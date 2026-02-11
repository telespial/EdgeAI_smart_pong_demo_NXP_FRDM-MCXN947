# Smart Pong Demo Status

- Current target: FRDM-MCXN947 3D-look Smart Pong on LCD-PAR-S035
- Workspace: `mcuxsdk_ws/` (created by `./tools/setup_mcuxsdk_ws.sh`)

## Last Run
- Date: 2026-02-11
- Result: ok (build + flash)
- Binary: `mcuxsdk_ws/build/edgeai_smart_pong_demo_cm33_core0.bin`
- Flash: `west flash -d mcuxsdk_ws/build -r linkserver`
- Notes (runtime): `CONFIG_EDGEAI_USE_NPU=y`, TFLM + eIQ Neutron path active with CPU fallback.
- Notes (NPU telemetry): runtime overlay shows NPU invoke rate, fallback rate, last inference latency, and moving-average latency.
- Notes (NPU predictor): direct `(y,z,t)` intercept decode path is active with analytic stabilization blend.
- Notes (P0 win loop): post-win restart delay now uses real elapsed time (no FPS stretch) and is tuned shorter.
- Notes (confetti): confetti progression now uses real elapsed time and reaches farther before P0 auto-restart.
- Notes (mode default): startup mode is `P0`.
- Notes (touch): paddle control uses left/right edge strips; no visual touch-guide overlays.
- Failsafe: `failsafe/edgeai_smart_pong_demo_cm33_core0_20260211_0821_p0_restart_confetti_tuned_golden.elf`
- Restore point: current build is the active Golden + Failsafe snapshot.
