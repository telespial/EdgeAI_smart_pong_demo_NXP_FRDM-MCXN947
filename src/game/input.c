#include "game/input.h"

static inline float clampf(float v, float lo, float hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static float input_touch_max_speed(const pong_game_t *g)
{
    uint8_t d = g ? g->difficulty : 2;
    if (d < 1) d = 1;
    if (d > 3) d = 3;
    switch (d)
    {
        case 1: return 2.1f;
        case 2: return 2.4f;
        default: return 2.8f;
    }
}

static void input_move_paddle(pong_paddle_t *p, float dt, float max_speed, float alpha)
{
    if (!p) return;

    float prev_y = p->y;
    float prev_z = p->z;

    float max_step = max_speed * dt;

    float dy = p->target_y - p->y;
    float dz = p->target_z - p->z;
    dy = clampf(dy, -max_step, max_step);
    dz = clampf(dz, -max_step, max_step);

    /* Light smoothing for touch/tilt jitter. */
    p->y += dy * alpha;
    p->z += dz * alpha;

    float hy = p->size_y * 0.5f;
    float hz = p->size_z * 0.5f;
    p->y = clampf(p->y, hy, 1.0f - hy);
    p->z = clampf(p->z, hz, 1.0f - hz);

    p->vy = (p->y - prev_y) / dt;
    p->vz = (p->z - prev_z) / dt;
}

void input_apply(pong_game_t *g, const platform_input_t *in, float dt)
{
    if (!g) return;

    float max_speed = 1.30f;
    float alpha = 0.55f;
    if (in && in->touch_active)
    {
        max_speed = input_touch_max_speed(g);
        alpha = 0.85f;
    }

    if (g->mode != kGameModeZeroPlayer)
    {
        if (in && in->p1_active)
        {
            g->paddle_l.target_y = clampf(in->p1_y, 0.0f, 1.0f);
            g->paddle_l.target_z = clampf(in->p1_z, 0.0f, 1.0f);
        }
        else
        {
            g->paddle_l.target_y = 0.5f;
            g->paddle_l.target_z = 0.5f;
        }
        input_move_paddle(&g->paddle_l, dt, max_speed, alpha);
    }

    if (g->mode == kGameModeTwoPlayer && in && in->p2_active)
    {
        g->paddle_r.target_y = clampf(in->p2_y, 0.0f, 1.0f);
        g->paddle_r.target_z = clampf(in->p2_z, 0.0f, 1.0f);
        input_move_paddle(&g->paddle_r, dt, max_speed, alpha);
    }
    else if (g->mode == kGameModeTwoPlayer)
    {
        /* No input: keep position, clear velocity to avoid stale paddle influence. */
        g->paddle_r.vy = 0.0f;
        g->paddle_r.vz = 0.0f;
    }
}
