# Smart Pong Demo Status

- Current target: FRDM-MCXN947 3D-look Smart Pong on LCD-PAR-S035
- Workspace: `mcuxsdk_ws/` (created by `./tools/setup_mcuxsdk_ws.sh`)

## Last Run
- Date: 2026-02-25
- Result: ok (build + flash)
- Binary: `mcuxsdk_ws/build/edgeai_smart_pong_demo_cm33_core0.bin`
- Flash: `west flash -d mcuxsdk_ws/build -r linkserver`
- Notes (persistence): match reset now explicitly reloads the learned persistence snapshot when `PERSIST` is enabled.
- Notes (settings UI): added `SPEED++` toggle row and moved `NEW GAME` to the next row.
- Notes (speed progression): when `SPEED++` is enabled, each side hitting `11, 22, 33, ...` raises serve-speed target by `5%` (compounding), clamped by runtime limits.
- Notes (flash persistence): `PERSIST ON` now restores AI learning profiles from onboard flash (`fsl_flash` ROM API) after reboot/power cycle.
- Notes (flash write policy): profile snapshot is synced to flash on match reset/new game to limit flash wear; `PERSIST OFF` clears stored snapshot.
- Notes (SPEED++ tuning): milestone boost updated to `+5%` per side-specific multiple-of-11 score event (`11, 22, 33, ...`).
- Notes (settings label render): added `+` support to the 5x7 font so `SPEED++` displays correctly (previously rendered as `SPEED`).
- Failsafe: `failsafe/edgeai_smart_pong_demo_cm33_core0_20260211_1309_final_release_score999_golden.elf`
- Restore point: current build is the active Golden + Failsafe snapshot.
- Notes (SKILL setting): learn-mode selector now supports `2AI`, `AI/ALGO`, and `ALGO/AI` so EdgeAI can run on either side.
- Notes (docs refresh): updated README and project description to match current settings, SKILL modes, SPEED++, and side-independent persistence behavior.
- Notes (SKILL balance): ALGO side remains CPU-only while mixed-mode EdgeAI now blends NPU output with analytic intercept for stronger stability and competitiveness.
- Notes (verification run): rebuilt and reflashed after SKILL-balance tuning; ready for fresh AI-vs-ALGO score validation on hardware.
- Notes (mixed-mode tune): reduced EdgeAI mixed-mode handicap by using ALGO-like target update cadence plus adaptive NPU confidence gating (fallback to analytic predictor on high disagreement).
