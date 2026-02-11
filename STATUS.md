# Smart Pong Demo Status

- Current target: FRDM-MCXN947 3D-look Smart Pong on LCD-PAR-S035
- Workspace: `mcuxsdk_ws/` (created by `./tools/setup_mcuxsdk_ws.sh`)

## Last Run
- Date: 2026-02-11
- Result: ok (build + flash)
- Binary: `mcuxsdk_ws/build/edgeai_smart_pong_demo_cm33_core0.bin`
- Flash: `west flash -d mcuxsdk_ws/build -r linkserver`
- Notes (runtime): `CONFIG_EDGEAI_USE_NPU=y`, TFLM + eIQ Neutron path active with CPU fallback.
- Notes (AI tuning): AI update cadence tightened, noise reduced, paddle response increased.
- Notes (NPU path): direct NPU intercept path uses confidence-gated analytic blending.
- Notes (telemetry): bottom overlay format updated to clearer rate/latency fields.
- Notes (AI lag pass): NPU inference cadence now adapts to measured average inference latency to protect render pacing.
- Notes (telemetry refresh): NPU/fallback rates are sampled over rolling windows and invoke count is shown so values visibly change.
- Notes (UI): `NEW GAME?` popup moved to lower-third placement.
- Notes (P0 win loop): post-win restart delay uses real elapsed time; confetti progression is real-time and tuned.
- Notes (mode default): startup mode is `P0`.
- Notes (touch): paddle control uses left/right edge strips; no visual touch-guide overlays.
- Failsafe: `failsafe/edgeai_smart_pong_demo_cm33_core0_20260211_1309_final_release_score999_golden.elf`
- Restore point: current build is the active Golden + Failsafe snapshot.
