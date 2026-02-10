#include "game/physics.h"

#include <stddef.h>

static inline float clampf(float v, float lo, float hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
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
    /* 24-bit mantissa fraction. */
    uint32_t u = (g->rng >> 8) & 0x00FFFFFFu;
    return (float)u * (1.0f / 16777215.0f);
}

static float rand_f(pong_game_t *g, float lo, float hi)
{
    return lo + (hi - lo) * rand_f01(g);
}

static int physics_substeps(const pong_game_t *g, float dt)
{
    if (!g) return 1;
    if (dt <= 0.0f) return 1;

    float vmax = absf(g->ball.vx);
    float avy = absf(g->ball.vy);
    float avz = absf(g->ball.vz);
    if (avy > vmax) vmax = avy;
    if (avz > vmax) vmax = avz;

    /* Keep per-substep motion small to avoid tunneling through paddles at higher speeds. */
    float limit = g->ball.r * 0.5f;
    if (limit < 0.001f) limit = 0.001f;

    float ratio = (vmax * dt) / limit;
    int n = (int)ratio;
    if ((float)n < ratio) n++;
    if (n < 1) n = 1;
    if (n > 8) n = 8;
    return n;
}

static float physics_ball_speed_scale(const pong_game_t *g)
{
    uint8_t d = g ? g->difficulty : 2;
    if (d < 1) d = 1;
    if (d > 3) d = 3;
    switch (d)
    {
        case 1: return 1.68f;
        case 2: return 1.82f;
        default: return 1.96f;
    }
}

static void physics_get_tuning(const pong_game_t *g, float *serve_speed, float *speed_up, float *vlim)
{
    uint8_t d = g ? g->difficulty : 2;
    if (d < 1) d = 1;
    if (d > 3) d = 3;

    if (serve_speed) *serve_speed = 1.00f;
    if (speed_up) *speed_up = 1.025f;
    if (vlim) *vlim = 2.30f;

    switch (d)
    {
        case 1:
            if (serve_speed) *serve_speed = 0.82f;
            if (speed_up) *speed_up = 1.018f;
            if (vlim) *vlim = 1.90f;
            break;
        case 2:
            if (serve_speed) *serve_speed = 1.02f;
            if (speed_up) *speed_up = 1.025f;
            if (vlim) *vlim = 2.30f;
            break;
        default:
            if (serve_speed) *serve_speed = 1.18f;
            if (speed_up) *speed_up = 1.035f;
            if (vlim) *vlim = 2.80f;
            break;
    }

    /* Scale overall ball speeds per difficulty preset. */
    float s = physics_ball_speed_scale(g);
    if (serve_speed) *serve_speed *= s;
    if (vlim) *vlim *= s;
}

void physics_reset_ball(pong_game_t *g, int serve_dir)
{
    if (!g) return;

    float dir = (serve_dir >= 0) ? 1.0f : -1.0f;

    g->ball.x = 0.5f;
    g->ball.y = rand_f(g, 0.30f, 0.70f);
    g->ball.z = rand_f(g, 0.20f, 0.80f);
    g->ball.r = 0.040f;

    float serve_speed = 1.0f;
    physics_get_tuning(g, &serve_speed, NULL, NULL);
    g->ball.vx = dir * serve_speed;
    g->ball.vy = rand_f(g, -0.28f, 0.28f);
    g->ball.vz = rand_f(g, -0.22f, 0.22f);
}

static void physics_wall_bounce(float *p, float *v, float r)
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

static void physics_paddle_hit(pong_game_t *g, pong_paddle_t *p, bool left_side)
{
    if (!g || !p) return;

    float dy = (g->ball.y - p->y) / (p->size_y * 0.5f);
    float dz = (g->ball.z - p->z) / (p->size_z * 0.5f);
    dy = clampf(dy, -1.0f, 1.0f);
    dz = clampf(dz, -1.0f, 1.0f);

    g->last_hit_dy = dy;
    g->last_hit_dz = dz;

    const float english = 0.55f;
    const float p_influence = 0.12f;

    g->ball.vy += dy * english;
    g->ball.vz += dz * english;
    g->ball.vy += p->vy * p_influence;
    g->ball.vz += p->vz * p_influence;

    float speed_up = 1.02f;
    float vlim = 1.6f;
    physics_get_tuning(g, NULL, &speed_up, &vlim);
    g->ball.vx = (left_side ? absf(g->ball.vx) : -absf(g->ball.vx)) * speed_up;

    /* Clamp speeds. */
    g->ball.vx = clampf(g->ball.vx, -vlim, vlim);
    g->ball.vy = clampf(g->ball.vy, -vlim, vlim);
    g->ball.vz = clampf(g->ball.vz, -vlim, vlim);

    /* Ensure x motion does not stall. */
    if (absf(g->ball.vx) < 0.24f)
    {
        g->ball.vx = (g->ball.vx < 0.0f) ? -0.24f : 0.24f;
    }
}

static bool physics_step_sub(pong_game_t *g, float dt)
{
    if (!g) return false;
    if (dt <= 0.0f) return false;

    g->ball.x += g->ball.vx * dt;
    g->ball.y += g->ball.vy * dt;
    g->ball.z += g->ball.vz * dt;

    /* Walls (y and z). */
    physics_wall_bounce(&g->ball.y, &g->ball.vy, g->ball.r);
    physics_wall_bounce(&g->ball.z, &g->ball.vz, g->ball.r);

    /* Paddle collisions. */
    if (g->ball.vx < 0.0f && (g->ball.x - g->ball.r) <= g->paddle_l.x_plane)
    {
        float hy = g->paddle_l.size_y * 0.5f;
        float hz = g->paddle_l.size_z * 0.5f;
        bool hit =
            (absf(g->ball.y - g->paddle_l.y) <= (hy + g->ball.r)) &&
            (absf(g->ball.z - g->paddle_l.z) <= (hz + g->ball.r));
        if (hit)
        {
            g->ball.x = g->paddle_l.x_plane + g->ball.r;
            physics_paddle_hit(g, &g->paddle_l, true);
        }
    }

    if (g->ball.vx > 0.0f && (g->ball.x + g->ball.r) >= g->paddle_r.x_plane)
    {
        float hy = g->paddle_r.size_y * 0.5f;
        float hz = g->paddle_r.size_z * 0.5f;
        bool hit =
            (absf(g->ball.y - g->paddle_r.y) <= (hy + g->ball.r)) &&
            (absf(g->ball.z - g->paddle_r.z) <= (hz + g->ball.r));
        if (hit)
        {
            g->ball.x = g->paddle_r.x_plane - g->ball.r;
            physics_paddle_hit(g, &g->paddle_r, false);
        }
    }

    /* Scoring. */
    const float margin = 0.10f;
    if (g->ball.x < -margin)
    {
        g->score.right++;
        physics_reset_ball(g, +1);
        return true;
    }
    else if (g->ball.x > 1.0f + margin)
    {
        g->score.left++;
        physics_reset_ball(g, -1);
        return true;
    }

    return false;
}

void physics_step(pong_game_t *g, float dt)
{
    if (!g) return;

    int n = physics_substeps(g, dt);
    float h = dt / (float)n;
    for (int i = 0; i < n; i++)
    {
        if (physics_step_sub(g, h))
        {
            return;
        }
    }
}
