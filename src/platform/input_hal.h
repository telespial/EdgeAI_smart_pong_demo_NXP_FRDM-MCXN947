#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "accel_proc.h"
#include "fxls8974cf.h"
#include "platform/touch_hal.h"

typedef struct
{
    bool p1_active;
    float p1_y;
    float p1_z;

    bool p2_active;
    float p2_y;
    float p2_z;

    bool mode_toggle;

    /* Primary touch (screen normalized). */
    bool touch_active;
    bool touch_pressed;
    float touch_x;
    float touch_y;
} platform_input_t;

typedef struct
{
    bool accel_ok;
    fxls8974_dev_t accel;
    accel_proc_t accel_proc;
    uint32_t accel_fail;

    bool prev_touch_active;
} input_hal_t;

bool input_hal_init(input_hal_t *s);
void input_hal_poll(input_hal_t *s, platform_input_t *out);
