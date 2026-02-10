#include "game/render.h"

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "edgeai_config.h"

#include "platform/display_hal.h"
#include "text5x7.h"

#include "game/ui_layout.h"

static uint16_t s_tile[EDGEAI_TILE_MAX_W * EDGEAI_TILE_MAX_H];

static inline float clampf(float v, float lo, float hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static inline float clamp01f(float v)
{
    return clampf(v, 0.0f, 1.0f);
}

static inline uint8_t clamp_u8(int32_t v)
{
    if (v < 0) return 0u;
    if (v > 255) return 255u;
    return (uint8_t)v;
}

static void render_project(const render_state_t *rs, float x, float y, float z, int32_t *sx, int32_t *sy, float *out_scale)
{
    float scale = 1.0f / (1.0f + z * rs->persp);
    if (out_scale) *out_scale = scale;

    float dx = (x - 0.5f) * (float)rs->world_scale_x;
    float dy = (y - 0.5f) * (float)rs->world_scale_y;

    int32_t px = rs->cx + (int32_t)(dx * scale);
    int32_t py = rs->cy + (int32_t)(dy * scale);
    if (sx) *sx = px;
    if (sy) *sy = py;
}

static void render_compute_box(render_state_t *rs)
{
    /* Near (z=0) corners: (0,0), (1,0), (1,1), (0,1) */
    render_project(rs, 0.0f, 0.0f, 0.0f, &rs->near_corners[0].x, &rs->near_corners[0].y, NULL);
    render_project(rs, 1.0f, 0.0f, 0.0f, &rs->near_corners[1].x, &rs->near_corners[1].y, NULL);
    render_project(rs, 1.0f, 1.0f, 0.0f, &rs->near_corners[2].x, &rs->near_corners[2].y, NULL);
    render_project(rs, 0.0f, 1.0f, 0.0f, &rs->near_corners[3].x, &rs->near_corners[3].y, NULL);

    /* Far (z=1) corners. */
    render_project(rs, 0.0f, 0.0f, 1.0f, &rs->far_corners[0].x, &rs->far_corners[0].y, NULL);
    render_project(rs, 1.0f, 0.0f, 1.0f, &rs->far_corners[1].x, &rs->far_corners[1].y, NULL);
    render_project(rs, 1.0f, 1.0f, 1.0f, &rs->far_corners[2].x, &rs->far_corners[2].y, NULL);
    render_project(rs, 0.0f, 1.0f, 1.0f, &rs->far_corners[3].x, &rs->far_corners[3].y, NULL);
}

void render_init(render_state_t *rs)
{
    if (!rs) return;

    rs->cx = EDGEAI_LCD_W / 2;
    rs->cy = EDGEAI_LCD_H / 2;
    rs->world_scale_x = 430;
    rs->world_scale_y = 280;
    rs->persp = 1.20f;

    render_compute_box(rs);
}

static void render_draw_center_dashes(uint16_t *dst, uint32_t w, uint32_t h, int32_t x0, int32_t y0, const render_state_t *rs)
{
    (void)rs;
    const uint16_t c_dash = sw_pack_rgb565_u8(200, 201, 204);

    const float x = 0.5f;
    const float y = 1.0f;
    const float dash_len = 0.05f;
    const float gap_len = 0.05f;

    float z = 0.05f;
    for (int i = 0; i < 14; i++)
    {
        float z0 = z;
        float z1 = z + dash_len;
        if (z1 > 0.98f) z1 = 0.98f;

        int32_t ax = 0, ay = 0, bx = 0, by = 0;
        render_project(rs, x, y, z0, &ax, &ay, NULL);
        render_project(rs, x, y, z1, &bx, &by, NULL);

        sw_render_line(dst, w, h, x0, y0, ax, ay, bx, by, c_dash);
        sw_render_line(dst, w, h, x0, y0, ax + 1, ay, bx + 1, by, c_dash);

        z = z1 + gap_len;
        if (z > 0.98f) break;
    }
}

static void render_bg_tile(uint16_t *dst, uint32_t w, uint32_t h, int32_t x0, int32_t y0, const render_state_t *rs)
{
    const uint16_t c_bg = sw_pack_rgb565_u8(14, 15, 16);
    const uint16_t c_wall_dark = sw_pack_rgb565_u8(17, 18, 21);
    const uint16_t c_wall_mid = sw_pack_rgb565_u8(27, 29, 32);
    const uint16_t c_wall_side = sw_pack_rgb565_u8(21, 22, 25);

    sw_render_clear(dst, w, h, c_bg);

    /* Back wall. */
    sw_render_fill_quad(dst, w, h, x0, y0,
                        rs->far_corners[0], rs->far_corners[1], rs->far_corners[2], rs->far_corners[3],
                        c_wall_dark);

    /* Ceiling. */
    sw_render_fill_quad(dst, w, h, x0, y0,
                        rs->near_corners[0], rs->near_corners[1], rs->far_corners[1], rs->far_corners[0],
                        c_wall_dark);

    /* Side walls. */
    sw_render_fill_quad(dst, w, h, x0, y0,
                        rs->near_corners[0], rs->near_corners[3], rs->far_corners[3], rs->far_corners[0],
                        c_wall_side);
    sw_render_fill_quad(dst, w, h, x0, y0,
                        rs->near_corners[1], rs->near_corners[2], rs->far_corners[2], rs->far_corners[1],
                        c_wall_side);

    /* Floor. */
    sw_render_fill_quad(dst, w, h, x0, y0,
                        rs->near_corners[3], rs->near_corners[2], rs->far_corners[2], rs->far_corners[3],
                        c_wall_mid);

    render_draw_center_dashes(dst, w, h, x0, y0, rs);

    /* Near frame outline. */
    const uint16_t c_frame = sw_pack_rgb565_u8(10, 10, 12);
    sw_render_line(dst, w, h, x0, y0, rs->near_corners[0].x, rs->near_corners[0].y, rs->near_corners[1].x, rs->near_corners[1].y, c_frame);
    sw_render_line(dst, w, h, x0, y0, rs->near_corners[1].x, rs->near_corners[1].y, rs->near_corners[2].x, rs->near_corners[2].y, c_frame);
    sw_render_line(dst, w, h, x0, y0, rs->near_corners[2].x, rs->near_corners[2].y, rs->near_corners[3].x, rs->near_corners[3].y, c_frame);
    sw_render_line(dst, w, h, x0, y0, rs->near_corners[3].x, rs->near_corners[3].y, rs->near_corners[0].x, rs->near_corners[0].y, c_frame);
}

static void render_draw_paddle(uint16_t *dst, uint32_t w, uint32_t h, int32_t x0, int32_t y0,
                               const render_state_t *rs, const pong_paddle_t *p)
{
    const uint16_t c_shadow = sw_pack_rgb565_u8(8, 8, 10);
    const uint16_t c_pad = sw_pack_rgb565_u8(214, 215, 217);

    float hy = p->size_y * 0.5f;
    float hz = p->size_z * 0.5f;

    float y0n = p->y - hy;
    float y1n = p->y + hy;
    float z0n = p->z - hz;
    float z1n = p->z + hz;

    sw_point_t q[4];
    render_project(rs, p->x_plane, y0n, z0n, &q[0].x, &q[0].y, NULL);
    render_project(rs, p->x_plane, y1n, z0n, &q[1].x, &q[1].y, NULL);
    render_project(rs, p->x_plane, y1n, z1n, &q[2].x, &q[2].y, NULL);
    render_project(rs, p->x_plane, y0n, z1n, &q[3].x, &q[3].y, NULL);

    /* Drop shadow. */
    sw_point_t qs[4] = {q[0], q[1], q[2], q[3]};
    for (int i = 0; i < 4; i++)
    {
        qs[i].x += 2;
        qs[i].y += 2;
    }
    sw_render_fill_quad(dst, w, h, x0, y0, qs[0], qs[1], qs[2], qs[3], c_shadow);
    sw_render_fill_quad(dst, w, h, x0, y0, q[0], q[1], q[2], q[3], c_pad);
}

static void render_draw_ball(uint16_t *dst, uint32_t w, uint32_t h, int32_t x0, int32_t y0,
                             const render_state_t *rs, const pong_ball_t *b)
{
    const uint16_t c_shadow0 = sw_pack_rgb565_u8(10, 10, 12);
    const uint16_t c_shadow1 = sw_pack_rgb565_u8(16, 16, 18);

    /* Ball color ramp (speed): red -> green. */
    float v2 = (b->vx * b->vx) + (b->vy * b->vy) + (b->vz * b->vz);
    const float vmin = 0.90f;
    const float vmax = 4.00f;
    float t = clamp01f((v2 - (vmin * vmin)) / ((vmax * vmax) - (vmin * vmin)));
    float hue = t * 120.0f;

    /* HSV (S=1,V=0.92) for h in [0,120]. */
    float v = 0.92f;
    float rf = 0.0f, gf = 0.0f, bf = 0.0f;
    if (hue < 60.0f)
    {
        rf = v;
        gf = v * (hue * (1.0f / 60.0f));
        bf = 0.0f;
    }
    else
    {
        rf = v * ((120.0f - hue) * (1.0f / 60.0f));
        gf = v;
        bf = 0.0f;
    }

    uint8_t r = clamp_u8((int32_t)(rf * 255.0f + 0.5f));
    uint8_t g = clamp_u8((int32_t)(gf * 255.0f + 0.5f));
    uint8_t b8 = clamp_u8((int32_t)(bf * 255.0f + 0.5f));

    const uint16_t c_ball = sw_pack_rgb565_u8(r, g, b8);
    const uint16_t c_hi = sw_pack_rgb565_u8(
        clamp_u8((int32_t)r + 40),
        clamp_u8((int32_t)g + 40),
        clamp_u8((int32_t)b8 + 40));

    int32_t sx = 0, sy = 0;
    float s = 1.0f;
    render_project(rs, b->x, b->y, b->z, &sx, &sy, &s);

    int32_t r_px = (int32_t)(b->r * (float)rs->world_scale_y * s);
    if (r_px < 2) r_px = 2;
    if (r_px > 40) r_px = 40;

    int32_t fx = 0, fy = 0;
    render_project(rs, b->x, 1.0f, b->z, &fx, &fy, NULL);
    int32_t sh_r = r_px + (r_px / 2);
    sw_render_filled_circle(dst, w, h, x0, y0, fx, fy, sh_r, c_shadow1);
    sw_render_filled_circle(dst, w, h, x0, y0, fx + 1, fy + 1, sh_r - 2, c_shadow0);

    sw_render_filled_circle(dst, w, h, x0, y0, sx, sy, r_px, c_ball);
    sw_render_filled_circle(dst, w, h, x0, y0, sx - (r_px / 3), sy - (r_px / 3), r_px / 3, c_hi);
}

static void render_digit7seg(uint16_t *dst, uint32_t w, uint32_t h, int32_t tile_x0, int32_t tile_y0,
                             int32_t x, int32_t y, int32_t seg_len, int32_t t, int digit, uint16_t c)
{
    static const uint8_t masks[10] = {
        0x3Fu, /* 0 */
        0x06u, /* 1 */
        0x5Bu, /* 2 */
        0x4Fu, /* 3 */
        0x66u, /* 4 */
        0x6Du, /* 5 */
        0x7Du, /* 6 */
        0x07u, /* 7 */
        0x7Fu, /* 8 */
        0x6Fu, /* 9 */
    };
    if (digit < 0 || digit > 9) return;
    uint8_t m = masks[digit];

    int32_t w_d = seg_len + 2 * t;
    int32_t h_d = 2 * seg_len + 3 * t;

    int32_t x0 = x - (w_d / 2);
    int32_t y0 = y - (h_d / 2);

    /* a */
    if (m & (1u << 0)) sw_render_fill_rect(dst, w, h, tile_x0, tile_y0, x0 + t, y0, x0 + t + seg_len - 1, y0 + t - 1, c);
    /* b */
    if (m & (1u << 1)) sw_render_fill_rect(dst, w, h, tile_x0, tile_y0, x0 + t + seg_len, y0 + t, x0 + t + seg_len + t - 1, y0 + t + seg_len - 1, c);
    /* c */
    if (m & (1u << 2)) sw_render_fill_rect(dst, w, h, tile_x0, tile_y0, x0 + t + seg_len, y0 + 2 * t + seg_len, x0 + t + seg_len + t - 1, y0 + 2 * t + 2 * seg_len - 1, c);
    /* d */
    if (m & (1u << 3)) sw_render_fill_rect(dst, w, h, tile_x0, tile_y0, x0 + t, y0 + 2 * seg_len + 2 * t, x0 + t + seg_len - 1, y0 + 2 * seg_len + 3 * t - 1, c);
    /* e */
    if (m & (1u << 4)) sw_render_fill_rect(dst, w, h, tile_x0, tile_y0, x0, y0 + 2 * t + seg_len, x0 + t - 1, y0 + 2 * t + 2 * seg_len - 1, c);
    /* f */
    if (m & (1u << 5)) sw_render_fill_rect(dst, w, h, tile_x0, tile_y0, x0, y0 + t, x0 + t - 1, y0 + t + seg_len - 1, c);
    /* g */
    if (m & (1u << 6)) sw_render_fill_rect(dst, w, h, tile_x0, tile_y0, x0 + t, y0 + seg_len + t, x0 + t + seg_len - 1, y0 + seg_len + 2 * t - 1, c);
}

static void render_scores(uint16_t *dst, uint32_t w, uint32_t h, int32_t x0, int32_t y0,
                          const render_state_t *rs, const pong_game_t *g)
{
    const uint16_t c_shadow = sw_pack_rgb565_u8(6, 6, 8);
    const uint16_t c_digit = sw_pack_rgb565_u8(214, 215, 217);

    float s_far = 1.0f / (1.0f + 1.0f * rs->persp);
    int32_t seg_len = (int32_t)(58.0f * s_far);
    int32_t t = (int32_t)(10.0f * s_far);
    if (seg_len < 14) seg_len = 14;
    if (t < 3) t = 3;

    int32_t lx = 0, ly = 0, rx = 0, ry = 0;
    render_project(rs, 0.25f, 0.16f, 1.0f, &lx, &ly, NULL);
    render_project(rs, 0.75f, 0.16f, 1.0f, &rx, &ry, NULL);

    int dl = (int)(g->score.left % 10u);
    int dr = (int)(g->score.right % 10u);

    render_digit7seg(dst, w, h, x0, y0, lx + 2, ly + 2, seg_len, t, dl, c_shadow);
    render_digit7seg(dst, w, h, x0, y0, rx + 2, ry + 2, seg_len, t, dr, c_shadow);
    render_digit7seg(dst, w, h, x0, y0, lx, ly, seg_len, t, dl, c_digit);
    render_digit7seg(dst, w, h, x0, y0, rx, ry, seg_len, t, dr, c_digit);
}

static void render_fill_round_rect(uint16_t *dst, uint32_t w, uint32_t h, int32_t tile_x0, int32_t tile_y0,
                                   int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t r, uint16_t c)
{
    if (x1 < x0 || y1 < y0) return;
    if (r < 0) r = 0;

    int32_t cy = (y0 + y1) / 2;
    int32_t rr = r;
    int32_t xl = x0 + rr;
    int32_t xr = x1 - rr;
    if (xl > xr) xl = xr = (x0 + x1) / 2;

    sw_render_fill_rect(dst, w, h, tile_x0, tile_y0, xl, y0, xr, y1, c);
    if (rr > 0)
    {
        sw_render_filled_circle(dst, w, h, tile_x0, tile_y0, xl, cy, rr, c);
        sw_render_filled_circle(dst, w, h, tile_x0, tile_y0, xr, cy, rr, c);
    }
}

static void render_ui(uint16_t *dst, uint32_t w, uint32_t h, int32_t tile_x0, int32_t tile_y0,
                      const pong_game_t *g)
{
    if (!g) return;

    const uint16_t c_pill_bg = sw_pack_rgb565_u8(g->menu_open ? 34 : 24, g->menu_open ? 35 : 25, g->menu_open ? 39 : 29);
    const uint16_t c_pill_border = sw_pack_rgb565_u8(62, 64, 68);
    const uint16_t c_text = sw_pack_rgb565_u8(214, 215, 217);
    const uint16_t c_text_dim = sw_pack_rgb565_u8(150, 152, 156);

    const int32_t pill_x0 = EDGEAI_UI_PILL_X;
    const int32_t pill_y0 = EDGEAI_UI_PILL_Y;
    const int32_t pill_x1 = pill_x0 + EDGEAI_UI_PILL_W - 1;
    const int32_t pill_y1 = pill_y0 + EDGEAI_UI_PILL_H - 1;
    const int32_t pill_r = EDGEAI_UI_PILL_H / 2;

    render_fill_round_rect(dst, w, h, tile_x0, tile_y0, pill_x0, pill_y0, pill_x1, pill_y1, pill_r, c_pill_bg);
    /* Border. */
    render_fill_round_rect(dst, w, h, tile_x0, tile_y0, pill_x0, pill_y0, pill_x1, pill_y0 + 1, 0, c_pill_border);
    render_fill_round_rect(dst, w, h, tile_x0, tile_y0, pill_x0, pill_y1 - 1, pill_x1, pill_y1, 0, c_pill_border);

    /* Icon: three short horizontal bars. */
    int32_t ix = pill_x0 + 10;
    int32_t iy = pill_y0 + 6;
    for (int i = 0; i < 3; i++)
    {
        sw_render_fill_rect(dst, w, h, tile_x0, tile_y0, ix, iy + i * 5, ix + 12, iy + i * 5 + 1, c_text_dim);
    }

    /* Label: P{0,1,2} D{1,2,3} */
    char players = (g->mode == kGameModeZeroPlayer) ? '0' : (g->mode == kGameModeSinglePlayer) ? '1' : '2';
    char diff = (g->difficulty < 1) ? '1' : (g->difficulty > 3) ? '3' : (char)('0' + g->difficulty);
    char s[8] = {'P', players, ' ', 'D', diff, 0};

    const int32_t scale = 2;
    int32_t tx = pill_x0 + 30;
    int32_t ty = pill_y0 + (EDGEAI_UI_PILL_H - 7 * scale) / 2;
    edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, tx, ty, scale, s, c_text);

    if (!g->menu_open) return;

    const uint16_t c_panel = sw_pack_rgb565_u8(18, 19, 22);
    const uint16_t c_panel_border = sw_pack_rgb565_u8(52, 54, 58);
    const uint16_t c_opt = sw_pack_rgb565_u8(26, 27, 31);
    const uint16_t c_opt_sel = sw_pack_rgb565_u8(214, 215, 217);
    const uint16_t c_opt_text = sw_pack_rgb565_u8(214, 215, 217);
    const uint16_t c_opt_text_sel = sw_pack_rgb565_u8(10, 10, 12);

    const int32_t panel_x0 = EDGEAI_UI_PANEL_X;
    const int32_t panel_y0 = EDGEAI_UI_PANEL_Y;
    const int32_t panel_x1 = panel_x0 + EDGEAI_UI_PANEL_W - 1;
    const int32_t panel_y1 = panel_y0 + EDGEAI_UI_PANEL_H - 1;

    render_fill_round_rect(dst, w, h, tile_x0, tile_y0, panel_x0, panel_y0, panel_x1, panel_y1, 10, c_panel);
    sw_render_line(dst, w, h, tile_x0, tile_y0, panel_x0, panel_y0, panel_x1, panel_y0, c_panel_border);
    sw_render_line(dst, w, h, tile_x0, tile_y0, panel_x0, panel_y1, panel_x1, panel_y1, c_panel_border);
    sw_render_line(dst, w, h, tile_x0, tile_y0, panel_x0, panel_y0, panel_x0, panel_y1, c_panel_border);
    sw_render_line(dst, w, h, tile_x0, tile_y0, panel_x1, panel_y0, panel_x1, panel_y1, c_panel_border);

    const int32_t label_scale = 2;
    const int32_t label_yoff = (EDGEAI_UI_ROW_H - 7 * label_scale) / 2;
    const int32_t opt_yoff = (EDGEAI_UI_ROW_H - EDGEAI_UI_OPT_H) / 2;
    const int32_t new_yoff = (EDGEAI_UI_ROW_H - EDGEAI_UI_NEW_H) / 2;

    /* Row labels. */
    edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, EDGEAI_UI_LABEL_X, EDGEAI_UI_ROW0_Y + label_yoff, label_scale, "P", c_opt_text);
    edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, EDGEAI_UI_LABEL_X, EDGEAI_UI_ROW1_Y + label_yoff, label_scale, "D", c_opt_text);
    edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, EDGEAI_UI_LABEL_X, EDGEAI_UI_ROW2_Y + label_yoff, label_scale, "N", c_opt_text);

    /* Players: 0/1/2 */
    for (int i = 0; i < 3; i++)
    {
        int32_t bx0 = EDGEAI_UI_OPT_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
        int32_t by0 = EDGEAI_UI_ROW0_Y + opt_yoff;
        int32_t bx1 = bx0 + EDGEAI_UI_OPT_W - 1;
        int32_t by1 = by0 + EDGEAI_UI_OPT_H - 1;

        bool sel = (g->mode == (i == 0 ? kGameModeZeroPlayer : i == 1 ? kGameModeSinglePlayer : kGameModeTwoPlayer));
        render_fill_round_rect(dst, w, h, tile_x0, tile_y0, bx0, by0, bx1, by1, EDGEAI_UI_OPT_H / 2, sel ? c_opt_sel : c_opt);

        char t[2] = {(char)('0' + i), 0};
        int32_t tw = edgeai_text5x7_width(label_scale, t);
        int32_t tx0 = bx0 + (EDGEAI_UI_OPT_W - tw) / 2;
        int32_t ty0 = by0 + (EDGEAI_UI_OPT_H - 7 * label_scale) / 2;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, tx0, ty0, label_scale, t, sel ? c_opt_text_sel : c_opt_text);
    }

    /* Difficulty: 1/2/3 */
    for (int i = 0; i < 3; i++)
    {
        int32_t bx0 = EDGEAI_UI_OPT_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
        int32_t by0 = EDGEAI_UI_ROW1_Y + opt_yoff;
        int32_t bx1 = bx0 + EDGEAI_UI_OPT_W - 1;
        int32_t by1 = by0 + EDGEAI_UI_OPT_H - 1;

        uint8_t d = (uint8_t)(i + 1);
        bool sel = (g->difficulty == d);
        render_fill_round_rect(dst, w, h, tile_x0, tile_y0, bx0, by0, bx1, by1, EDGEAI_UI_OPT_H / 2, sel ? c_opt_sel : c_opt);

        char t[2] = {(char)('0' + (i + 1)), 0};
        int32_t tw = edgeai_text5x7_width(label_scale, t);
        int32_t tx0 = bx0 + (EDGEAI_UI_OPT_W - tw) / 2;
        int32_t ty0 = by0 + (EDGEAI_UI_OPT_H - 7 * label_scale) / 2;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, tx0, ty0, label_scale, t, sel ? c_opt_text_sel : c_opt_text);
    }

    /* New game. */
    {
        int32_t bx0 = EDGEAI_UI_NEW_X;
        int32_t by0 = EDGEAI_UI_ROW2_Y + new_yoff;
        int32_t bx1 = bx0 + EDGEAI_UI_NEW_W - 1;
        int32_t by1 = by0 + EDGEAI_UI_NEW_H - 1;

        render_fill_round_rect(dst, w, h, tile_x0, tile_y0, bx0, by0, bx1, by1, EDGEAI_UI_NEW_H / 2, c_opt);
        const int32_t tscale = 2;
        const char *t = "0:0";
        int32_t tw = edgeai_text5x7_width(tscale, t);
        int32_t tx0 = bx0 + (EDGEAI_UI_NEW_W - tw) / 2;
        int32_t ty0 = by0 + (EDGEAI_UI_NEW_H - 7 * tscale) / 2;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, tx0, ty0, tscale, t, c_opt_text);
    }
}

void render_draw_frame(render_state_t *rs, const pong_game_t *g)
{
    if (!rs || !g) return;

    for (int32_t y0 = 0; y0 < EDGEAI_LCD_H; y0 += EDGEAI_TILE_MAX_H)
    {
        int32_t y1 = y0 + EDGEAI_TILE_MAX_H - 1;
        if (y1 >= EDGEAI_LCD_H) y1 = EDGEAI_LCD_H - 1;
        int32_t h = y1 - y0 + 1;

        for (int32_t x0 = 0; x0 < EDGEAI_LCD_W; x0 += EDGEAI_TILE_MAX_W)
        {
            int32_t x1 = x0 + EDGEAI_TILE_MAX_W - 1;
            if (x1 >= EDGEAI_LCD_W) x1 = EDGEAI_LCD_W - 1;
            int32_t w = x1 - x0 + 1;

            render_bg_tile(s_tile, (uint32_t)w, (uint32_t)h, x0, y0, rs);

            render_scores(s_tile, (uint32_t)w, (uint32_t)h, x0, y0, rs, g);

            /* Simple painter's algorithm by depth (z): far -> near. */
            struct draw_obj
            {
                float z;
                uint8_t kind; /* 0=paddle_l, 1=paddle_r, 2=ball */
            } objs[3] = {
                {g->paddle_l.z, 0u},
                {g->paddle_r.z, 1u},
                {g->ball.z, 2u},
            };

            for (int i = 0; i < 2; i++)
            {
                for (int j = i + 1; j < 3; j++)
                {
                    if (objs[j].z > objs[i].z)
                    {
                        struct draw_obj tmp = objs[i];
                        objs[i] = objs[j];
                        objs[j] = tmp;
                    }
                }
            }

            for (int i = 0; i < 3; i++)
            {
                switch (objs[i].kind)
                {
                    case 0u:
                        render_draw_paddle(s_tile, (uint32_t)w, (uint32_t)h, x0, y0, rs, &g->paddle_l);
                        break;
                    case 1u:
                        render_draw_paddle(s_tile, (uint32_t)w, (uint32_t)h, x0, y0, rs, &g->paddle_r);
                        break;
                    default:
                        render_draw_ball(s_tile, (uint32_t)w, (uint32_t)h, x0, y0, rs, &g->ball);
                        break;
                }
            }

            render_ui(s_tile, (uint32_t)w, (uint32_t)h, x0, y0, g);

            display_hal_blit_rect(x0, y0, x1, y1, s_tile);
        }
    }
}
