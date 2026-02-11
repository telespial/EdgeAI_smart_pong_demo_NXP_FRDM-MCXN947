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

static void render_draw_floor_grid(uint16_t *dst, uint32_t w, uint32_t h, int32_t x0, int32_t y0, const render_state_t *rs)
{
    const uint16_t c_grid = sw_pack_rgb565_u8(24, 25, 28);

    const float y = 1.0f;

    /* Depth cross-lines. */
    static const float z_lines[] = {0.12f, 0.24f, 0.36f, 0.48f, 0.60f, 0.72f, 0.84f, 0.96f};
    for (size_t i = 0; i < (sizeof(z_lines) / sizeof(z_lines[0])); i++)
    {
        float z = z_lines[i];
        int32_t ax = 0, ay = 0, bx = 0, by = 0;
        render_project(rs, 0.0f, y, z, &ax, &ay, NULL);
        render_project(rs, 1.0f, y, z, &bx, &by, NULL);
        sw_render_line(dst, w, h, x0, y0, ax, ay, bx, by, c_grid);
    }

    /* Perspective rails. */
    static const float x_lines[] = {0.25f, 0.75f};
    for (size_t i = 0; i < (sizeof(x_lines) / sizeof(x_lines[0])); i++)
    {
        float x = x_lines[i];
        int32_t ax = 0, ay = 0, bx = 0, by = 0;
        render_project(rs, x, y, 0.05f, &ax, &ay, NULL);
        render_project(rs, x, y, 0.98f, &bx, &by, NULL);
        sw_render_line(dst, w, h, x0, y0, ax, ay, bx, by, c_grid);
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

    render_draw_floor_grid(dst, w, h, x0, y0, rs);
    render_draw_center_dashes(dst, w, h, x0, y0, rs);

    /* Box edges: increase wall readability while keeping the monochrome style. */
    const uint16_t c_box_edge = sw_pack_rgb565_u8(18, 19, 22);
    const uint16_t c_box_far = sw_pack_rgb565_u8(26, 27, 31);

    /* Far frame outline. */
    sw_render_line(dst, w, h, x0, y0, rs->far_corners[0].x, rs->far_corners[0].y, rs->far_corners[1].x, rs->far_corners[1].y, c_box_far);
    sw_render_line(dst, w, h, x0, y0, rs->far_corners[1].x, rs->far_corners[1].y, rs->far_corners[2].x, rs->far_corners[2].y, c_box_far);
    sw_render_line(dst, w, h, x0, y0, rs->far_corners[2].x, rs->far_corners[2].y, rs->far_corners[3].x, rs->far_corners[3].y, c_box_far);
    sw_render_line(dst, w, h, x0, y0, rs->far_corners[3].x, rs->far_corners[3].y, rs->far_corners[0].x, rs->far_corners[0].y, c_box_far);

    /* Connecting edges from near to far. */
    sw_render_line(dst, w, h, x0, y0, rs->near_corners[0].x, rs->near_corners[0].y, rs->far_corners[0].x, rs->far_corners[0].y, c_box_edge);
    sw_render_line(dst, w, h, x0, y0, rs->near_corners[1].x, rs->near_corners[1].y, rs->far_corners[1].x, rs->far_corners[1].y, c_box_edge);
    sw_render_line(dst, w, h, x0, y0, rs->near_corners[2].x, rs->near_corners[2].y, rs->far_corners[2].x, rs->far_corners[2].y, c_box_edge);
    sw_render_line(dst, w, h, x0, y0, rs->near_corners[3].x, rs->near_corners[3].y, rs->far_corners[3].x, rs->far_corners[3].y, c_box_edge);

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
    const uint16_t c_edge_near = sw_pack_rgb565_u8(246, 247, 249);
    const uint16_t c_edge_far = sw_pack_rgb565_u8(156, 157, 160);
    const uint16_t c_edge_side = sw_pack_rgb565_u8(206, 207, 209);

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

    /* Depth edges: make z extent readable at a glance. */
    sw_render_line(dst, w, h, x0, y0, q[0].x, q[0].y, q[1].x, q[1].y, c_edge_near);
    sw_render_line(dst, w, h, x0, y0, q[0].x + 1, q[0].y, q[1].x + 1, q[1].y, c_edge_near);
    sw_render_line(dst, w, h, x0, y0, q[3].x, q[3].y, q[2].x, q[2].y, c_edge_far);
    sw_render_line(dst, w, h, x0, y0, q[0].x, q[0].y, q[3].x, q[3].y, c_edge_side);
    sw_render_line(dst, w, h, x0, y0, q[1].x, q[1].y, q[2].x, q[2].y, c_edge_side);
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

    /* Use x scale so the visible radius matches paddle-plane collision distance in screen space. */
    int32_t r_px = (int32_t)(b->r * (float)rs->world_scale_x * s);
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

    /* Help icon: right-aligned inside the pill. */
    {
        const uint16_t c_help_bg = sw_pack_rgb565_u8(g->help_open ? 36 : 20, g->help_open ? 37 : 21, g->help_open ? 41 : 25);

        const int32_t hx0 = EDGEAI_UI_HELP_BTN_X;
        const int32_t hy0 = EDGEAI_UI_HELP_BTN_Y;
        const int32_t hx1 = hx0 + EDGEAI_UI_HELP_BTN_W - 1;
        const int32_t hy1 = hy0 + EDGEAI_UI_HELP_BTN_H - 1;

        /* Segment background + divider. */
        render_fill_round_rect(dst, w, h, tile_x0, tile_y0, hx0, hy0, hx1, hy1, EDGEAI_UI_PILL_H / 2, c_help_bg);
        sw_render_line(dst, w, h, tile_x0, tile_y0, hx0, hy0 + 3, hx0, hy1 - 3, c_pill_border);

        const int32_t qscale = 2;
        const char *q = "?";
        int32_t qw = edgeai_text5x7_width(qscale, q);
        int32_t qx = hx0 + (EDGEAI_UI_HELP_BTN_W - qw) / 2;
        int32_t qy = hy0 + (EDGEAI_UI_HELP_BTN_H - 7 * qscale) / 2;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, qx, qy, qscale, q, c_text);
    }

    /* Tilt indicator (P0): shows accel vector used to nudge the ball.
     * Helps confirm the accelerometer is alive without needing a serial console.
     */
    if (g->mode == kGameModeZeroPlayer)
    {
        const int32_t bx0 = 12;
        const int32_t by0 = pill_y0;
        const int32_t bw = 28;
        const int32_t bh = EDGEAI_UI_PILL_H;
        const int32_t bx1 = bx0 + bw - 1;
        const int32_t by1 = by0 + bh - 1;

        const uint16_t c_ind_bg = sw_pack_rgb565_u8(20, 21, 24);
        const uint16_t c_ind_border = sw_pack_rgb565_u8(52, 54, 58);
        const uint16_t c_ind_dot = sw_pack_rgb565_u8(214, 215, 217);
        const uint16_t c_ind_dim = sw_pack_rgb565_u8(120, 122, 126);

        render_fill_round_rect(dst, w, h, tile_x0, tile_y0, bx0, by0, bx1, by1, bh / 2, c_ind_bg);
        sw_render_line(dst, w, h, tile_x0, tile_y0, bx0, by0, bx1, by0, c_ind_border);
        sw_render_line(dst, w, h, tile_x0, tile_y0, bx0, by1, bx1, by1, c_ind_border);

        int32_t cx = bx0 + bw / 2;
        int32_t cy = by0 + bh / 2;
        int32_t r = 2;

        if (g->accel_active)
        {
            float ax = clampf(g->accel_ax, -1.0f, 1.0f);
            float ay = clampf(g->accel_ay, -1.0f, 1.0f);

            int32_t max_dx = (bw / 2) - 6;
            int32_t max_dy = (bh / 2) - 6;
            if (max_dx < 0) max_dx = 0;
            if (max_dy < 0) max_dy = 0;

            int32_t dx = (int32_t)(ax * (float)max_dx);
            int32_t dy = (int32_t)(ay * (float)max_dy);
            sw_render_filled_circle(dst, w, h, tile_x0, tile_y0, cx + dx, cy + dy, r, c_ind_dot);
        }
        else
        {
            /* No accel present: draw a subtle X. */
            sw_render_line(dst, w, h, tile_x0, tile_y0, bx0 + 6, by0 + 6, bx1 - 6, by1 - 6, c_ind_dim);
            sw_render_line(dst, w, h, tile_x0, tile_y0, bx1 - 6, by0 + 6, bx0 + 6, by1 - 6, c_ind_dim);
        }
    }

    if (!g->menu_open && !g->help_open) return;

    if (g->menu_open)
    {
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
        return;
    }

    /* Help panel. */
    {
        const uint16_t c_panel = sw_pack_rgb565_u8(18, 19, 22);
        const uint16_t c_panel_border = sw_pack_rgb565_u8(52, 54, 58);
        const uint16_t c_body = sw_pack_rgb565_u8(214, 215, 217);
        const uint16_t c_dim = sw_pack_rgb565_u8(150, 152, 156);

        const int32_t panel_x0 = EDGEAI_UI_HELP_PANEL_X;
        const int32_t panel_y0 = EDGEAI_UI_HELP_PANEL_Y;
        const int32_t panel_x1 = panel_x0 + EDGEAI_UI_HELP_PANEL_W - 1;
        const int32_t panel_y1 = panel_y0 + EDGEAI_UI_HELP_PANEL_H - 1;

        render_fill_round_rect(dst, w, h, tile_x0, tile_y0, panel_x0, panel_y0, panel_x1, panel_y1, 12, c_panel);
        sw_render_line(dst, w, h, tile_x0, tile_y0, panel_x0, panel_y0, panel_x1, panel_y0, c_panel_border);
        sw_render_line(dst, w, h, tile_x0, tile_y0, panel_x0, panel_y1, panel_x1, panel_y1, c_panel_border);
        sw_render_line(dst, w, h, tile_x0, tile_y0, panel_x0, panel_y0, panel_x0, panel_y1, c_panel_border);
        sw_render_line(dst, w, h, tile_x0, tile_y0, panel_x1, panel_y0, panel_x1, panel_y1, c_panel_border);

        const int32_t xpad = 14;
        const int32_t ypad = 10;
        int32_t x = panel_x0 + xpad;
        int32_t y = panel_y0 + ypad;

        const int32_t s1 = 1;
        const int32_t lh = 9;

        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, 2, "GAME RULES", c_body);
        y += 16;

        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "HIT BALL WITH PADDLE", c_body);
        y += lh;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "SCORE WHEN BALL PASSES PADDLE", c_body);
        y += lh;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "BALL BOUNCES OFF WALLS", c_body);
        y += lh;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "BALL SPEEDS UP ON HITS", c_body);
        y += lh;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "BALL COLOR SHOWS SPEED", c_body);
        y += lh;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "DIFFICULTY CHANGES SPEED AND AI", c_body);
        y += lh + 4;

        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, 2, "CONTROLS", c_dim);
        y += 16;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "TOUCH Y UP DOWN", c_body);
        y += lh;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "TOUCH X DEPTH", c_body);
        y += lh;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "P0 AI VS AI", c_body);
        y += lh;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "P1 ONE TOUCH", c_body);
        y += lh;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "P2 TWO TOUCHES L R", c_body);
        y += lh + 4;

        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, 2, "INSPIRED BY", c_dim);
        y += 16;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "PONG 1972 ATARI INC", c_body);
        y += lh;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "ORIGINAL VERSION: ALLAN ALCORN", c_body);
        y += lh;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "CONCEIVED BY: NOLAN BUSHNELL", c_body);

        int32_t credit_y = panel_y1 - ypad - 7 * s1;
        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, credit_y, s1, "THIS VERSION: RICHARD HABERKERN", c_dim);
    }
}

typedef struct
{
    float z0; /* near */
    float z1; /* far */
    float zc; /* center */
} render_depth_range_t;

static bool render_depth_behind(const render_depth_range_t r[3], int a, int b, float eps)
{
    return r && (r[a].z0 >= (r[b].z1 + eps));
}

static bool render_depth_overlap(const render_depth_range_t r[3], int a, int b)
{
    return r && (r[a].z0 <= r[b].z1) && (r[a].z1 >= r[b].z0);
}

static uint8_t render_depth_order3(const pong_game_t *g, uint8_t out_order[3])
{
    if (!out_order) return 0u;
    if (!g)
    {
        out_order[0] = 0u;
        out_order[1] = 1u;
        out_order[2] = 2u;
        return 3u;
    }

    float lhz = g->paddle_l.size_z * 0.5f;
    float rhz = g->paddle_r.size_z * 0.5f;

    render_depth_range_t r[3] = {
        {g->paddle_l.z - lhz, g->paddle_l.z + lhz, g->paddle_l.z},
        {g->paddle_r.z - rhz, g->paddle_r.z + rhz, g->paddle_r.z},
        {g->ball.z - g->ball.r, g->ball.z + g->ball.r, g->ball.z},
    };

    const float eps = 1e-4f;

    static const uint8_t perms[6][3] = {
        {0u, 1u, 2u},
        {0u, 2u, 1u},
        {1u, 0u, 2u},
        {1u, 2u, 0u},
        {2u, 0u, 1u},
        {2u, 1u, 0u},
    };

    int best_i = 0;
    int best_score = 0x7FFFFFFF;

    for (int pi = 0; pi < 6; pi++)
    {
        const uint8_t *p = perms[pi];

        int pos[3] = {0, 0, 0};
        pos[p[0]] = 0;
        pos[p[1]] = 1;
        pos[p[2]] = 2;

        int score = 0;

        /* Hard constraints: if A is fully behind B, A must be drawn first. */
        for (int a = 0; a < 3; a++)
        {
            for (int b = a + 1; b < 3; b++)
            {
                if (render_depth_behind(r, a, b, eps) && (pos[a] > pos[b])) score += 1000;
                if (render_depth_behind(r, b, a, eps) && (pos[b] > pos[a])) score += 1000;
            }
        }

        /* Soft preference: if z ranges overlap, draw the ball on top (last) for readability. */
        if (render_depth_overlap(r, 2, 0) && (pos[2] < pos[0])) score += 1;
        if (render_depth_overlap(r, 2, 1) && (pos[2] < pos[1])) score += 1;

        /* Tie-breaker: prefer far->near by center z when possible. */
        for (int a = 0; a < 3; a++)
        {
            for (int b = a + 1; b < 3; b++)
            {
                if ((r[a].zc > r[b].zc) && (pos[a] > pos[b])) score += 1;
                if ((r[b].zc > r[a].zc) && (pos[b] > pos[a])) score += 1;
            }
        }

        if (score < best_score)
        {
            best_score = score;
            best_i = pi;
        }
    }

    out_order[0] = perms[best_i][0];
    out_order[1] = perms[best_i][1];
    out_order[2] = perms[best_i][2];
    return 3u;
}

void render_draw_frame(render_state_t *rs, const pong_game_t *g)
{
    if (!rs || !g) return;

    uint8_t draw_order[3] = {0u, 1u, 2u};
    (void)render_depth_order3(g, draw_order);

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

            /* Painter's algorithm by depth (z): far -> near, with simple z-range handling. */
            for (int i = 0; i < 3; i++)
            {
                switch (draw_order[i])
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
