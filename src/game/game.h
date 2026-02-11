#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "game/modes.h"
#include "platform/input_hal.h"
#include "platform/npu_hal.h"

typedef struct
{
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
    float r;
} pong_ball_t;

typedef struct
{
    float x_plane;
    float y;
    float z;
    float vy;
    float vz;
    float size_y;
    float size_z;
    float target_y;
    float target_z;
} pong_paddle_t;

typedef struct
{
    uint16_t left;
    uint16_t right;
} pong_score_t;

typedef struct
{
    game_mode_t mode;
    uint8_t difficulty; /* 1..3 */
    bool ai_enabled;
    bool menu_open;
    bool help_open;
    bool ui_block_touch;
    bool match_over;
    bool winner_left;
    bool end_prompt_dismissed;
    bool countdown_active;

    pong_ball_t ball;
    pong_paddle_t paddle_l;
    pong_paddle_t paddle_r;
    pong_score_t score;

    uint32_t rng;
    uint32_t frame;
    uint32_t match_over_frame;
    uint32_t countdown_frames_left;

    float last_hit_dy;
    float last_hit_dz;

    float serve_vx;
    float serve_vy;
    float serve_vz;

    /* Latest accel sample (for UI/debug + optional game effects). */
    bool accel_active;
    float accel_ax;
    float accel_ay;

    npu_hal_t npu;
} pong_game_t;

void game_init(pong_game_t *g);
void game_reset(pong_game_t *g);
void game_step(pong_game_t *g, const platform_input_t *in, float dt);
