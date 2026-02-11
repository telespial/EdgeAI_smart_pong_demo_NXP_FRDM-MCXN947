# EdgeAI Smart Pong Demo (FRDM-MCXN947)

3D-look Pong demo for FRDM-MCXN947 + LCD-PAR-S035.

Features:
- 0P / 1P / 2P: AI vs AI, 1P vs AI, 2P local
- 0P accel ball nudge (Accel 4 Click, FXLS8974CF): tilt perturbs ball vy/vz to influence AI vs AI outcomes
- NPU-backed AI path (TFLM + eIQ Neutron) enabled via `CONFIG_EDGEAI_USE_NPU`
- Touch control (GT911, multi-touch):
  - 1 touch drives player 1
  - 2 touches split screen: left half drives player 1, right half drives player 2
- Settings UI (top pill):
  - Players: 0 / 1 / 2
  - Difficulty: 1 / 2 / 3
  - New game (score reset)
- Fixed-timestep physics (60 Hz default)
- Difficulty presets tune AI behavior, paddle speed, and ball speed
- NPU path can be disabled by clearing `CONFIG_EDGEAI_USE_NPU`

Key folders:
- `sdk_example/`: MCUX SDK example wrapper (built via `west`)
- `src/`: firmware sources (platform + game)
- `docs/`: bring-up and build notes
- `tools/`: bootstrap/build/flash scripts

## Quickstart (Ubuntu)
1. Bootstrap user-local tools (no sudo): `./tools/bootstrap_ubuntu_user.sh`
2. Create/update local MCUX west workspace: `./tools/setup_mcuxsdk_ws.sh`
3. Build: `./tools/build_frdmmcxn947.sh debug`
4. Flash (requires NXP LinkServer installed): `./tools/flash_frdmmcxn947.sh`
5. Install repo guardrails (optional): `./tools/install_git_hooks.sh`

## Docs Entry Point
- `docs/START_HERE.md`

## Restore Points
- Active Golden/Failsafe pointer: `docs/failsafe.md`
- Failsafe flash command:
  - `FAILSAFE_CONFIRM="$(sed -n '1p' docs/failsafe.md)" ./tools/flash_failsafe.sh`

## Text Style Guardrails
Comments and docs are required to avoid conversational phrasing and direct reader references.
- Rules: `docs/STYLE_RULES.md`
- Lint: `./tools/lint_text_style.sh`
