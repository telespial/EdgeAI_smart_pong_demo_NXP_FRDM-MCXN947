#include "game/game.h"

#include <string.h>

#include "game/ai.h"
#include "game/input.h"
#include "game/modes.h"
#include "game/physics.h"
#include "game/ui_layout.h"

static inline int32_t clampi(int32_t v, int32_t lo, int32_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

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

static inline bool hit_rect(int32_t x, int32_t y, int32_t rx, int32_t ry, int32_t rw, int32_t rh)
{
    return (x >= rx) && (x < (rx + rw)) && (y >= ry) && (y < (ry + rh));
}

static float game_deadzone(float v, float dz)
{
    if (dz <= 0.0f) return v;
    if (dz >= 1.0f) return 0.0f;
    return (absf(v) < dz) ? 0.0f : v;
}

static void game_apply_accel_ball_nudge(pong_game_t *g, const platform_input_t *in, float dt)
{
    if (!g || !in) return;
    if (dt <= 0.0f) return;
    if (g->mode != kGameModeZeroPlayer) return;
    if (!in->accel_active) return;

    /* Tilt affects ball vertical (y) and horizontal (z) to allow outcome nudging in AI vs AI mode. */
    float ax = clampf(in->accel_ax, -1.0f, 1.0f);
    float ay = clampf(in->accel_ay, -1.0f, 1.0f);

    /* Input is already deadzoned/softened in accel_proc; avoid a second deadzone here. */
    const float dz = 0.0f;
    ax = game_deadzone(ax, dz);
    ay = game_deadzone(ay, dz);

    /* High gain on purpose: P0 is a "mess with the outcome" mode. */
    const float k = 14.0f;
    g->ball.vz += ax * k * dt;
    g->ball.vy += ay * k * dt;

    const float vlim = 6.0f;
    g->ball.vy = clampf(g->ball.vy, -vlim, vlim);
    g->ball.vz = clampf(g->ball.vz, -vlim, vlim);
}

static void ui_handle_press(pong_game_t *g, float touch_x, float touch_y)
{
    if (!g) return;

    int32_t px = (int32_t)(touch_x * (float)(EDGEAI_LCD_W - 1) + 0.5f);
    int32_t py = (int32_t)(touch_y * (float)(EDGEAI_LCD_H - 1) + 0.5f);
    px = clampi(px, 0, EDGEAI_LCD_W - 1);
    py = clampi(py, 0, EDGEAI_LCD_H - 1);

    const int32_t pill_x = EDGEAI_UI_PILL_X;
    const int32_t pill_y = EDGEAI_UI_PILL_Y;
    const int32_t pill_w = EDGEAI_UI_PILL_W;
    const int32_t pill_h = EDGEAI_UI_PILL_H;

    const int32_t help_x = EDGEAI_UI_HELP_BTN_X;
    const int32_t help_y = EDGEAI_UI_HELP_BTN_Y;
    const int32_t help_w = EDGEAI_UI_HELP_BTN_W;
    const int32_t help_h = EDGEAI_UI_HELP_BTN_H;

    if (hit_rect(px, py, help_x, help_y, help_w, help_h))
    {
        g->help_open = !g->help_open;
        if (g->help_open) g->menu_open = false;
        return;
    }

    if (hit_rect(px, py, pill_x, pill_y, pill_w, pill_h))
    {
        g->menu_open = !g->menu_open;
        if (g->menu_open) g->help_open = false;
        return;
    }

    if (g->help_open)
    {
        const int32_t panel_x = EDGEAI_UI_HELP_PANEL_X;
        const int32_t panel_y = EDGEAI_UI_HELP_PANEL_Y;
        const int32_t panel_w = EDGEAI_UI_HELP_PANEL_W;
        const int32_t panel_h = EDGEAI_UI_HELP_PANEL_H;

        if (!hit_rect(px, py, panel_x, panel_y, panel_w, panel_h))
        {
            g->help_open = false;
            g->ui_block_touch = true;
        }
        return;
    }

    if (!g->menu_open) return;

    const int32_t panel_x = EDGEAI_UI_PANEL_X;
    const int32_t panel_y = EDGEAI_UI_PANEL_Y;
    const int32_t panel_w = EDGEAI_UI_PANEL_W;
    const int32_t panel_h = EDGEAI_UI_PANEL_H;

    if (!hit_rect(px, py, panel_x, panel_y, panel_w, panel_h))
    {
        g->menu_open = false;
        g->ui_block_touch = true;
        return;
    }

    const int32_t opt_y0 = (EDGEAI_UI_ROW_H - EDGEAI_UI_OPT_H) / 2;
    const int32_t new_y0 = (EDGEAI_UI_ROW_H - EDGEAI_UI_NEW_H) / 2;

    /* Players: 0, 1, 2 */
    for (int32_t i = 0; i < 3; i++)
    {
        int32_t bx = EDGEAI_UI_OPT_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
        int32_t by = EDGEAI_UI_ROW0_Y + opt_y0;
        if (hit_rect(px, py, bx, by, EDGEAI_UI_OPT_W, EDGEAI_UI_OPT_H))
        {
            game_mode_t new_mode = (i == 0) ? kGameModeZeroPlayer : (i == 1) ? kGameModeSinglePlayer : kGameModeTwoPlayer;
            if (g->mode != new_mode)
            {
                g->mode = new_mode;
                game_reset(g);
            }
            return;
        }
    }

    /* Difficulty: 1, 2, 3 */
    for (int32_t i = 0; i < 3; i++)
    {
        int32_t bx = EDGEAI_UI_OPT_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
        int32_t by = EDGEAI_UI_ROW1_Y + opt_y0;
        if (hit_rect(px, py, bx, by, EDGEAI_UI_OPT_W, EDGEAI_UI_OPT_H))
        {
            uint8_t new_diff = (uint8_t)(i + 1);
            if (new_diff < 1) new_diff = 1;
            if (new_diff > 3) new_diff = 3;
            if (g->difficulty != new_diff)
            {
                g->difficulty = new_diff;
                game_reset(g);
            }
            return;
        }
    }

    /* AI: ON, OFF */
    for (int32_t i = 0; i < 2; i++)
    {
        int32_t bx = EDGEAI_UI_OPT2_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
        int32_t by = EDGEAI_UI_ROW2_Y + opt_y0;
        if (hit_rect(px, py, bx, by, EDGEAI_UI_OPT_W, EDGEAI_UI_OPT_H))
        {
            bool new_ai_enabled = (i == 0);
            if (g->ai_enabled != new_ai_enabled)
            {
                g->ai_enabled = new_ai_enabled;
            }
            return;
        }
    }

    /* New game. */
    {
        int32_t bx = EDGEAI_UI_NEW_X;
        int32_t by = EDGEAI_UI_ROW3_Y + new_y0;
        if (hit_rect(px, py, bx, by, EDGEAI_UI_NEW_W, EDGEAI_UI_NEW_H))
        {
            game_reset(g);
            g->menu_open = false;
            return;
        }
    }
}

void game_init(pong_game_t *g)
{
    if (!g) return;
    memset(g, 0, sizeof(*g));

    g->mode = kGameModeSinglePlayer;
    g->difficulty = 2;
    g->ai_enabled = true;
    g->menu_open = false;
    g->help_open = false;
    g->ui_block_touch = false;

    g->rng = 1u;
    g->frame = 0;

    g->paddle_l.x_plane = 0.06f;
    g->paddle_r.x_plane = 0.94f;

    g->paddle_l.size_y = 0.26f;
    g->paddle_l.size_z = 0.28f;
    g->paddle_r.size_y = 0.26f;
    g->paddle_r.size_z = 0.28f;

    g->paddle_l.y = 0.5f;
    g->paddle_l.z = 0.5f;
    g->paddle_r.y = 0.5f;
    g->paddle_r.z = 0.5f;

    g->paddle_l.target_y = g->paddle_l.y;
    g->paddle_l.target_z = g->paddle_l.z;
    g->paddle_r.target_y = g->paddle_r.y;
    g->paddle_r.target_z = g->paddle_r.z;

    g->last_hit_dy = 0.0f;
    g->last_hit_dz = 0.0f;

    g->accel_active = false;
    g->accel_ax = 0.0f;
    g->accel_ay = 0.0f;

    ai_init(g);
    game_reset(g);
}

void game_reset(pong_game_t *g)
{
    if (!g) return;

    g->score.left = 0;
    g->score.right = 0;

    g->paddle_l.y = 0.5f;
    g->paddle_l.z = 0.5f;
    g->paddle_r.y = 0.5f;
    g->paddle_r.z = 0.5f;

    g->paddle_l.vy = 0.0f;
    g->paddle_l.vz = 0.0f;
    g->paddle_r.vy = 0.0f;
    g->paddle_r.vz = 0.0f;

    g->paddle_l.target_y = g->paddle_l.y;
    g->paddle_l.target_z = g->paddle_l.z;
    g->paddle_r.target_y = g->paddle_r.y;
    g->paddle_r.target_z = g->paddle_r.z;

    g->last_hit_dy = 0.0f;
    g->last_hit_dz = 0.0f;

    physics_reset_ball(g, +1);
}

void game_step(pong_game_t *g, const platform_input_t *in, float dt)
{
    if (!g) return;

    /* Keep latest accel values in game state for UI/debug even when not used for control. */
    g->accel_active = (in && in->accel_active);
    g->accel_ax = in ? in->accel_ax : 0.0f;
    g->accel_ay = in ? in->accel_ay : 0.0f;

    if (in && in->touch_pressed)
    {
        ui_handle_press(g, in->touch_x, in->touch_y);
    }

    if (g->ui_block_touch)
    {
        if (in && in->touch_active)
        {
            return;
        }
        g->ui_block_touch = false;
    }

    if (g->menu_open || g->help_open)
    {
        /* Pause simulation while an overlay UI panel is open. */
        return;
    }

    if (in && in->mode_toggle)
    {
        g->mode = modes_next(g->mode);
        game_reset(g);
    }

    input_apply(g, in, dt);

    bool manual_r = (g->mode == kGameModeTwoPlayer) && in && in->p2_active;
    bool ai_left = (g->mode == kGameModeZeroPlayer);
    bool ai_right = (g->mode == kGameModeSinglePlayer) || (g->mode == kGameModeZeroPlayer);
    if (g->mode == kGameModeTwoPlayer || manual_r) ai_right = false;
    ai_step(g, dt, ai_left, ai_right);

    physics_step(g, dt);

    /* Apply after physics so paddle hits do not overwrite the external nudge. */
    game_apply_accel_ball_nudge(g, in, dt);
    g->frame++;
}
