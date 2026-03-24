# Project State

Last updated: 2026-03-24

## Current Status
- Target board: `FRDM-MCXN947`
- Demo: 3D-look Smart Pong with optional EdgeAI assist layer
- Working workspace: `mcuxsdk_ws/`
- Most recent validated binary:
  - `mcuxsdk_ws/mcuxsdk_ws/build_speedup_20260324/edgeai_smart_pong_demo_cm33_core0.bin`

## Last Verified Change
- Date: 2026-03-24
- Result: build/flash PASS
- Summary:
  - Visual style retuned to better match the Infineon Smart Pong look.
  - EdgeAI fairness separation updated so non-AI/manual behavior is unaffected when EdgeAI is off.
  - Ball pacing update: faster startup serves (+14%) and progressive late-game speed-up once either side reaches 6+ points.
  - Release marker: promoted as Golden + Failsafe restore point.

## Active Restore Point
- Pointer file: `docs/failsafe.md`
- Artifact folder: `failsafe/`
- Active artifact:
  - `failsafe/edgeai_smart_pong_demo_cm33_core0_20260324_065426_style_edgeai_fairness_speedup_golden.elf`
- Flash command:
  - `FAILSAFE_CONFIRM="$(sed -n '1p' docs/failsafe.md)" ./tools/flash_failsafe.sh`

## Default Build / Flash
- Build:
  - `./tools/build_frdmmcxn947.sh`
- Flash:
  - `./tools/flash_frdmmcxn947.sh`

## Notes
- Keep release documentation synchronized in:
  - `STATUS.md`
  - `docs/PROJECT_STATE.md`
  - `docs/failsafe.md`
