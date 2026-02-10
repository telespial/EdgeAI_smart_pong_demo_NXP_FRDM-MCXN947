#include <stdbool.h>
#include <stdint.h>

#include "edgeai_config.h"

#include "game/game.h"
#include "game/render.h"
#include "platform/display_hal.h"
#include "platform/input_hal.h"
#include "platform/time_hal.h"
#include "sw_render.h"
#include "text5x7.h"

#include "app.h"
#include "fsl_debug_console.h"

static void draw_boot_title(void)
{
    const int32_t scale = 8;
    const char *title = "PONG";
    int32_t w = edgeai_text5x7_width(scale, title);
    int32_t x = (EDGEAI_LCD_W - w) / 2;
    int32_t y = (EDGEAI_LCD_H / 2) - (7 * scale);

    const uint16_t shadow = sw_pack_rgb565_u8(10, 10, 12);
    const uint16_t face = sw_pack_rgb565_u8(214, 215, 217);

    edgeai_text5x7_draw_scaled(x + 4, y + 4, scale, title, shadow);
    edgeai_text5x7_draw_scaled(x, y, scale, title, face);
}

int main(void)
{
    BOARD_InitHardware();
    time_hal_init();

    if (!display_hal_init())
    {
        for (;;) {}
    }

    display_hal_fill(0x0000u);
    draw_boot_title();

    PRINTF("PONG: boot %s %s\r\n", __DATE__, __TIME__);

    input_hal_t input;
    (void)input_hal_init(&input);

    pong_game_t game;
    game_init(&game);

    render_state_t render;
    render_init(&render);

    const uint32_t frame_us = 1000000u / (uint32_t)EDGEAI_FIXED_FPS;
    const float dt = 1.0f / (float)EDGEAI_FIXED_FPS;

    for (;;)
    {
        uint32_t start = time_hal_cycles();

        platform_input_t in;
        input_hal_poll(&input, &in);

        game_step(&game, &in, dt);
        render_draw_frame(&render, &game);

        uint32_t elapsed_us = time_hal_elapsed_us(start);
        if (elapsed_us < frame_us)
        {
            time_hal_delay_us(frame_us - elapsed_us);
        }
    }
}
