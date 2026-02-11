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
- Notes (rules/win flow): match ends at 11 points; winner score is larger and flashing green, loser score is smaller solid red; confetti animation then `NEW GAME? YES/NO` popup.
- Notes (serve): serve direction now resets toward the side that just conceded.
- Notes (serve UX): `3,2,1` countdown is shown at new game start only; per-point serves resume immediately.
- Notes (countdown timing): countdown uses hardware elapsed time (`1.0s` each for `3`, `2`, `1`) so timing stays correct under frame drops.
- Notes (render pacing): tile layout switched to full-height strips to reduce horizontal split artifacts at high ball speed.
- Failsafe: failsafe/edgeai_smart_pong_demo_cm33_core0_20260211_0707_countdown_realtime_golden.elf
- Restore point: current realtime-countdown build is now the active Golden + Failsafe snapshot.
