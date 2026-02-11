#include "game/ai.h"

#include <string.h>

#include "platform/time_hal.h"

static inline float clampf(float v, float lo, float hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static inline uint16_t clampu16(uint32_t v, uint16_t hi)
{
    if (v > (uint32_t)hi) return hi;
    return (uint16_t)v;
}

static inline float absf(float v)
{
    return (v < 0.0f) ? -v : v;
}

static inline uint32_t xorshift32(uint32_t x)
{
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

static float rand_f01(pong_game_t *g)
{
    g->rng = xorshift32(g->rng ? g->rng : 1u);
    uint32_t u = (g->rng >> 8) & 0x00FFFFFFu;
    return (float)u * (1.0f / 16777215.0f);
}

static float rand_f(pong_game_t *g, float lo, float hi)
{
    return lo + (hi - lo) * rand_f01(g);
}

static void ai_sim_wall(float *p, float *v, float r)
{
    if (!p || !v) return;
    if ((*p - r) < 0.0f)
    {
        *p = r;
        *v = absf(*v);
    }
    if ((*p + r) > 1.0f)
    {
        *p = 1.0f - r;
        *v = -absf(*v);
    }
}

static void ai_predict_right(const pong_game_t *g, float dt, float *out_y, float *out_z, float *out_t)
{
    if (!out_y || !out_z || !out_t)
        return;

    *out_y = 0.5f;
    *out_z = 0.5f;
    *out_t = 0.0f;
    if (!g) return;

    if (g->ball.vx <= 0.0f)
    {
        *out_y = 0.5f;
        *out_z = 0.5f;
        *out_t = 0.0f;
        return;
    }

    float x = g->ball.x;
    float y = g->ball.y;
    float z = g->ball.z;
    float vx = g->ball.vx;
    float vy = g->ball.vy;
    float vz = g->ball.vz;
    float r = g->ball.r;

    const float x_hit = g->paddle_r.x_plane - r;
    const int max_steps = 240; /* ~4s at 60 Hz */

    for (int i = 0; i < max_steps; i++)
    {
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        ai_sim_wall(&y, &vy, r);
        ai_sim_wall(&z, &vz, r);
        if (x >= x_hit)
        {
            *out_y = clampf(y, 0.0f, 1.0f);
            *out_z = clampf(z, 0.0f, 1.0f);
            *out_t = (float)(i + 1) * dt;
            return;
        }
    }
}

static void ai_predict_left(const pong_game_t *g, float dt, float *out_y, float *out_z, float *out_t)
{
    if (!out_y || !out_z || !out_t)
        return;

    *out_y = 0.5f;
    *out_z = 0.5f;
    *out_t = 0.0f;
    if (!g) return;

    if (g->ball.vx >= 0.0f)
    {
        *out_y = 0.5f;
        *out_z = 0.5f;
        *out_t = 0.0f;
        return;
    }

    float x = g->ball.x;
    float y = g->ball.y;
    float z = g->ball.z;
    float vx = g->ball.vx;
    float vy = g->ball.vy;
    float vz = g->ball.vz;
    float r = g->ball.r;

    const float x_hit = g->paddle_l.x_plane + r;
    const int max_steps = 240; /* ~4s at 60 Hz */

    for (int i = 0; i < max_steps; i++)
    {
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        ai_sim_wall(&y, &vy, r);
        ai_sim_wall(&z, &vz, r);
        if (x <= x_hit)
        {
            *out_y = clampf(y, 0.0f, 1.0f);
            *out_z = clampf(z, 0.0f, 1.0f);
            *out_t = (float)(i + 1) * dt;
            return;
        }
    }
}

void ai_init(pong_game_t *g)
{
    if (!g) return;
    (void)npu_hal_init(&g->npu);
}

static void ai_build_features(const pong_game_t *g, float f[16])
{
    if (!g || !f) return;
    memset(f, 0, 16 * sizeof(f[0]));

    f[0] = g->ball.x;
    f[1] = g->ball.y;
    f[2] = g->ball.z;
    f[3] = g->ball.vx;
    f[4] = g->ball.vy;
    f[5] = g->ball.vz;

    f[6] = g->paddle_l.y;
    f[7] = g->paddle_l.z;
    f[8] = g->paddle_l.vy;
    f[9] = g->paddle_l.vz;

    f[10] = g->paddle_r.y;
    f[11] = g->paddle_r.z;

    int32_t sd = (int32_t)g->score.left - (int32_t)g->score.right;
    if (sd > 20) sd = 20;
    if (sd < -20) sd = -20;
    f[12] = (float)sd * (1.0f / 20.0f);

    f[13] = g->last_hit_dy;
    f[14] = g->last_hit_dz;
    f[15] = 1.0f;
}

static void ai_mirror_features_x(const float in[16], float out[16])
{
    if (!in || !out) return;

    /* Keep the NPU feature view always predicting the right paddle plane:
     * - mirror x and vx
     * - swap left/right paddle features
     * - flip score diff sign (left-right -> right-left)
     */
    memcpy(out, in, 16 * sizeof(out[0]));

    out[0] = 1.0f - in[0];   /* ball.x */
    out[3] = -in[3];         /* ball.vx */

    /* left paddle (6..9) <-> right paddle (10..11) */
    out[6] = in[10]; /* opp y */
    out[7] = in[11]; /* opp z */
    out[8] = 0.0f;
    out[9] = 0.0f;

    out[10] = in[6]; /* self y */
    out[11] = in[7]; /* self z */

    out[12] = -in[12];
}

static uint32_t ai_update_div(const pong_game_t *g, bool use_npu)
{
    uint8_t d = g ? g->difficulty : 2;
    if (d < 1) d = 1;
    if (d > 3) d = 3;

    if (!use_npu)
    {
        switch (d)
        {
            case 1: return 6u;
            case 2: return 4u;
            default: return 2u;
        }
    }

    /* NPU invoke cadence is intentionally slower to protect frame pacing. */
    switch (d)
    {
        case 1: return 12u;
        case 2: return 8u;
        default: return 6u;
    }
}

static float ai_noise(const pong_game_t *g)
{
    uint8_t d = g ? g->difficulty : 2;
    if (d < 1) d = 1;
    if (d > 3) d = 3;
    switch (d)
    {
        case 1: return 0.055f;
        case 2: return 0.025f;
        default: return 0.012f;
    }
}

static float ai_max_speed(const pong_game_t *g)
{
    uint8_t d = g ? g->difficulty : 2;
    if (d < 1) d = 1;
    if (d > 3) d = 3;
    switch (d)
    {
        case 1: return 0.95f;
        case 2: return 1.15f;
        default: return 1.35f;
    }
}

static void ai_update_telemetry_window(pong_game_t *g)
{
    if (!g) return;

    if (g->ai_telemetry_start_cycles == 0u)
    {
        g->ai_telemetry_start_cycles = time_hal_cycles();
        return;
    }

    uint32_t elapsed_us = time_hal_elapsed_us(g->ai_telemetry_start_cycles);
    if (elapsed_us < 1000000u) return;

    uint32_t npu_hz = 0u;
    uint32_t fb_hz = 0u;

    if (elapsed_us > 0u)
    {
        npu_hz = (uint32_t)(((uint64_t)g->ai_npu_attempts_window * 1000000ull) / (uint64_t)elapsed_us);
        fb_hz = (uint32_t)(((uint64_t)g->ai_fallback_window * 1000000ull) / (uint64_t)elapsed_us);
    }

    g->ai_npu_rate_hz = clampu16(npu_hz, 999u);
    g->ai_fallback_rate_hz = clampu16(fb_hz, 999u);
    g->ai_npu_attempts_window = 0u;
    g->ai_fallback_window = 0u;
    g->ai_telemetry_start_cycles = time_hal_cycles();
}

static void ai_step_one(pong_game_t *g, float dt, pong_paddle_t *p, bool right_side)
{
    if (!g || !p) return;

    bool ball_toward = right_side ? (g->ball.vx > 0.0f) : (g->ball.vx < 0.0f);
    bool use_npu = g->ai_enabled && ball_toward;

    /* Refresh AI target at a lower rate for difficulty and lower CPU. */
    uint32_t div = ai_update_div(g, use_npu);
    if (div == 0u) div = 1u;
    if ((g->frame % div) == 0u)
    {
        float y_hit = 0.5f;
        float z_hit = 0.5f;
        float t_hit = 0.0f;

        if (ball_toward)
        {
            bool used_npu = false;

            if (use_npu)
            {
                float feat[16];
                float feat2[16];
                ai_build_features(g, feat);

                const float *use_feat = feat;
                if (!right_side)
                {
                    ai_mirror_features_x(feat, feat2);
                    use_feat = feat2;
                }

                g->ai_npu_attempts_window++;
                npu_pred_t pred;
                used_npu = npu_hal_predict(&g->npu, use_feat, &pred);
                if (used_npu)
                {
                    y_hit = pred.y_hit;
                    z_hit = pred.z_hit;
                    t_hit = pred.t_hit;
                }
                else
                {
                    g->ai_fallback_window++;
                }
            }

            if (!used_npu)
            {
                if (right_side)
                {
                    ai_predict_right(g, dt, &y_hit, &z_hit, &t_hit);
                }
                else
                {
                    ai_predict_left(g, dt, &y_hit, &z_hit, &t_hit);
                }
            }

            /* Add small noise to avoid perfect play. */
            float noise = ai_noise(g);
            y_hit += rand_f(g, -noise, noise);
            z_hit += rand_f(g, -noise, noise);
        }

        (void)t_hit;

        p->target_y = clampf(y_hit, 0.0f, 1.0f);
        p->target_z = clampf(z_hit, 0.0f, 1.0f);
    }

    /* Speed-limited movement. */
    float prev_y = p->y;
    float prev_z = p->z;

    float max_speed = ai_max_speed(g);
    float max_step = max_speed * dt;

    float dy = p->target_y - p->y;
    float dz = p->target_z - p->z;
    dy = clampf(dy, -max_step, max_step);
    dz = clampf(dz, -max_step, max_step);
    p->y += dy;
    p->z += dz;

    /* Clamp inside arena. */
    float hy = p->size_y * 0.5f;
    float hz = p->size_z * 0.5f;
    p->y = clampf(p->y, hy, 1.0f - hy);
    p->z = clampf(p->z, hz, 1.0f - hz);

    p->vy = (p->y - prev_y) / dt;
    p->vz = (p->z - prev_z) / dt;
}

void ai_step(pong_game_t *g, float dt, bool ai_left, bool ai_right)
{
    if (!g) return;

    if (ai_left)
    {
        ai_step_one(g, dt, &g->paddle_l, false);
    }
    if (ai_right)
    {
        ai_step_one(g, dt, &g->paddle_r, true);
    }

    ai_update_telemetry_window(g);
}
