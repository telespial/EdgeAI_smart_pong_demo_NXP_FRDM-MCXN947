#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    bool init_ok;
} npu_hal_t;

typedef struct
{
    float y_hit;
    float z_hit;
    float t_hit;
} npu_pred_t;

bool npu_hal_init(npu_hal_t *s);
bool npu_hal_predict(npu_hal_t *s, const float features[16], npu_pred_t *out);

