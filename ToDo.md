# ToDo: Smart Pong (FRDM-MCXN947)

Reference material:
- `docs/project_description.md`
- `docs/pong_3D.png`

## Current Snapshot
- [x] Build/flash flow is reproducible in-project (`tools/setup_mcuxsdk_ws.sh`, `tools/build_frdmmcxn947.sh`, `tools/flash_frdmmcxn947.sh`).
- [x] Golden restore point and failsafe restore point are aligned via `docs/failsafe.md`.
- [x] Last known-good status is tracked in `STATUS.md`.

## Gameplay + Rendering
- [x] 3D-look arena rendering aligned to style target (walls, floor, center dash, depth cues).
- [x] 0P / 1P / 2P play modes with in-game settings pill (players, difficulty, AI on/off, new game).
- [x] Touch controls support split-screen two-player mapping.
- [x] Ball speed scaling distributed across difficulty levels.
- [x] Ball color hue shifts from red toward green as speed increases.
- [x] Help overlay (`?`) is integrated in top menu flow with usage/rules text and credits.
- [x] Win condition at 11 points with end-of-match celebration and `NEW GAME? YES/NO` prompt.

## Physics + Control
- [x] Fixed timestep game loop.
- [x] Paddle-ball collision and depth handling improved for left/right parity.
- [x] Single-player and two-player paddle behavior tuned to avoid recentring on finger release.
- [x] Accelerometer tilt perturbation path active for 0P mode (X/Y influence).

## AI/NPU
- [x] CPU baseline predictor path implemented.
- [x] NPU runtime integration enabled (`CONFIG_EDGEAI_USE_NPU=y`).
- [x] TFLM + eIQ Neutron execution path verified through debug trace.
- [x] Model section placement fixed (`.model` mapped to `m_flash1`) and flashed.
- [x] NPU path has CPU fallback behavior.

## Remaining Backlog
- [ ] Replace placeholder NeutronGraph model with Pong-specific trained model that directly predicts intercept outputs.
- [ ] Add AI telemetry overlay toggle (NPU invoke rate, fallback count, frame-time budget).
- [ ] Define and validate win condition/end-game UX.
- [ ] Add automated gameplay regression scenarios for collision edge cases.
- [ ] Document model training/export pipeline in a dedicated `docs/AI_MODEL.md`.
