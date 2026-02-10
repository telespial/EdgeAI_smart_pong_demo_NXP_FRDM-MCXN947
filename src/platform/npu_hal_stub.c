#include "platform/npu_hal.h"

bool npu_hal_init(npu_hal_t *s)
{
    if (!s) return false;
    s->init_ok = false;
    return true;
}

bool npu_hal_predict(npu_hal_t *s, const float features[16], npu_pred_t *out)
{
    (void)features;
    if (!s || !out) return false;
    if (!s->init_ok) return false;
    return false;
}

