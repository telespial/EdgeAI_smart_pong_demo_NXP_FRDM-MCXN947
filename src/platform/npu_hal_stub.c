#include "platform/npu_hal.h"

#if defined(CONFIG_EDGEAI_USE_NPU) && (CONFIG_EDGEAI_USE_NPU)
bool npu_hal_tflm_neutron_init(npu_hal_t *s);
bool npu_hal_tflm_neutron_predict(npu_hal_t *s, const float features[16], npu_pred_t *out);
#endif

bool npu_hal_init(npu_hal_t *s)
{
    if (!s) return false;
    s->init_ok = false;

#if defined(CONFIG_EDGEAI_USE_NPU) && (CONFIG_EDGEAI_USE_NPU)
    return npu_hal_tflm_neutron_init(s);
#else
    return true;
#endif
}

bool npu_hal_predict(npu_hal_t *s, const float features[16], npu_pred_t *out)
{
    if (!s || !out) return false;
    if (!s->init_ok) return false;
#if defined(CONFIG_EDGEAI_USE_NPU) && (CONFIG_EDGEAI_USE_NPU)
    return npu_hal_tflm_neutron_predict(s, features, out);
#else
    (void)features;
    return false;
#endif
}
