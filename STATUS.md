# Smart Pong Demo Status

- Current target: FRDM-MCXN947 3D-look Pong on LCD-PAR-S035
- Workspace: `mcuxsdk_ws/` (created by `./tools/setup_mcuxsdk_ws.sh`)

## Last Run
- Date: 2026-02-11
- Result: ok (build + flash)
- Binary: mcuxsdk_ws/build/edgeai_smart_pong_demo_cm33_core0.bin
- Flash: west flash -d mcuxsdk_ws/build -r linkserver
- Notes: `CONFIG_EDGEAI_USE_NPU=y`, TFLM + eIQ Neutron path active. Model section `.model` mapped into `m_flash1` and flashed; stack raised to `0x8000`.
- Notes (UI/AI): boot title now "SMART PONG"; settings include `AI ON/OFF` (NPU-assisted path toggle); AI invoke cadence reduced to improve frame pacing.
- Failsafe: failsafe/edgeai_smart_pong_demo_cm33_core0_20260210_2044_npu_stable_golden.elf
- Restore point: current build is now the active Golden + Failsafe snapshot.
