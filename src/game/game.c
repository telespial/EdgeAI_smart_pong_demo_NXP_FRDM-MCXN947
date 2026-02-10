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

static inline bool hit_rect(int32_t x, int32_t y, int32_t rx, int32_t ry, int32_t rw, int32_t rh)
{
    return (x >= rx) && (x < (rx + rw)) && (y >= ry) && (y < (ry + rh));
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

    if (hit_rect(px, py, pill_x, pill_y, pill_w, pill_h))
    {
        g->menu_open = !g->menu_open;
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

    /* New game. */
    {
        int32_t bx = EDGEAI_UI_NEW_X;
        int32_t by = EDGEAI_UI_ROW2_Y + new_y0;
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
    g->menu_open = false;

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

    if (in && in->touch_pressed)
    {
        ui_handle_press(g, in->touch_x, in->touch_y);
    }

    if (g->menu_open)
    {
        /* Pause simulation while the settings menu is open. */
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
    g->frame++;
}
