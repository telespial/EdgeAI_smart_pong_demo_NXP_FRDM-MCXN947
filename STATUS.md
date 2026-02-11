# Smart Pong Demo Status

- Current target: FRDM-MCXN947 3D-look Smart Pong on LCD-PAR-S035
- Workspace: `mcuxsdk_ws/` (created by `./tools/setup_mcuxsdk_ws.sh`)

## Last Run
- Date: 2026-02-11
- Result: ok (lint + build + flash)
- Binary: `mcuxsdk_ws/build/edgeai_smart_pong_demo_cm33_core0.bin`
- Flash: `west flash -d mcuxsdk_ws/build -r linkserver`
- Notes (runtime): `CONFIG_EDGEAI_USE_NPU=y`, TFLM + eIQ Neutron path active with CPU fallback.
- Notes (mode default): startup mode is `P0`.
- Notes (P0 flow): at 11 points, winner score styling + confetti are shown, then game auto-resets with no `NEW GAME?` prompt.
- Notes (P1/P2 flow): at 11 points, winner score styling + confetti are shown, then `NEW GAME? YES/NO` prompt appears.
- Notes (countdown): `3,2,1` uses real elapsed time (1 second each), shown only at new-game start; skipped in `P0`.
- Notes (touch): paddle control uses left/right edge strips; no visual touch-guide overlays.
- Notes (docs): README and project docs updated for final Smart Pong naming, hardware list, rules/settings, and AI/NPU details.
- Failsafe: `failsafe/edgeai_smart_pong_demo_cm33_core0_20260211_0745_p0_win11_autoloop_final_golden.elf`
- Restore point: current build is the active Golden + Failsafe snapshot.
