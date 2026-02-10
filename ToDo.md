# ToDo: EdgeAI Smart Pong (FRDM-MCXN947)

Reference material:
- `docs/project_description.md` (feature/architecture requirements)
- `docs/pong_3D.png` (visual style target)

## Definition Of Done
- [x] Builds with a reproducible command path (clean workspace -> build -> flash).
- [x] Runs on FRDM-MCXN947 and renders a "3D Pong" arena consistent with `docs/pong_3D.png`.
- [x] Supports 0P / 1P / 2P modes.
- [x] Uses fixed-timestep physics (60 FPS) with deterministic behavior.
- [x] AI supports baseline CPU prediction.
- [ ] Optional NPU-backed predictor path is available (runtime integration).
- [x] Includes minimal docs for bring-up, build, and flashing (project-local only).

## Visual Style Checklist (Match `docs/pong_3D.png`)
- [ ] Monochrome palette: 2-3 dark grays for arena; light gray paddles/ball; soft shadows.
- [ ] Box arena: back wall rectangle, side walls trapezoids, floor trapezoid (perspective).
- [ ] Center dashed line: vertical, evenly spaced dashes.
- [ ] Score digits: blocky, segmented look; placed near top left/right.
- [ ] Ball depth cue: size scales with depth; add a floor shadow blob that scales with depth.
- [ ] Lighting cue: subtle gradients on walls/floor; avoid high-frequency textures.

Suggested palette (tune per display gamma):
- Background: #0E0F10
- Arena mid:  #1B1D20
- Arena dark: #111215
- Paddles:    #D6D7D9
- Ball:       #E2E3E6
- Line/dash:  #C8C9CC

## Milestone 0: Build/Flash Plumbing (Project-Local)
- [x] Confirm build target and align overlay/app paths to Smart Pong (`edgeai_smart_pong_demo`).
- [x] Document canonical commands:
  - [x] `./tools/bootstrap_ubuntu_user.sh` (tooling bootstrap)
  - [x] `./tools/setup_mcuxsdk_ws.sh` (west workspace setup)
  - [x] `./tools/build_frdmmcxn947.sh [debug|release]` (build)
  - [x] `./tools/flash_frdmmcxn947.sh` (flash)
- [x] Add a minimal `docs/BUILD_FLASH.md` focused on this project repo (no external/private references).
- [x] Add a minimal `STATUS.md` with last-known-good build settings and binary location.

## Milestone 1: 2D Pong Baseline (Fast, Verifiable)
- [x] Game state:
  - [x] `Ball`, `Paddle`, `GameState` structs (normalized 0..1 coordinates).
  - [x] Fixed timestep loop (60 Hz).
- [x] Physics:
  - [x] Ball-wall collisions (y bounds).
  - [x] Paddle collisions (x plane + y overlap).
  - [x] Scoring + serve reset (small randomness).
- [x] Input:
  - [x] Touch -> normalized coordinates.
  - [x] Left paddle follows touch (y,z) with smoothing.
- [x] AI (CPU baseline):
  - [x] Right paddle follows predicted intercept with speed limits.
- [x] Rendering:
  - [x] Software-tile renderer primitives: rects, circles, lines.
  - [x] Simple UI: paddles, ball, score digits.
- [ ] Debug:
  - [ ] Optional overlay: FPS, dt, ball/paddle state.

## Milestone 2: Add Z Axis + 3D Illusion Rendering
- [x] Expand world model:
  - [x] Add `z` position/velocity and z bounds.
  - [x] Paddle has `centerY/centerZ` and `sizeY/sizeZ`.
- [x] Physics:
  - [x] Ball-wall collisions (z bounds).
  - [x] Paddle collisions in (y,z) with radius overlap.
  - [x] "English" on hits (dy,dz) + paddle-velocity influence.
- [x] Input mapping:
  - [x] Map touch Y -> paddle Y.
  - [x] Map touch X -> paddle Z.
  - [x] Apply smoothing and rate limits.
- [x] Projection:
  - [x] Perspective scale factor `scale = 1 / (1 + z * persp)`.
  - [x] Apply depth scaling to ball radius and paddle size.
- [x] Arena rendering:
  - [x] Back wall rectangle.
  - [x] Side wall trapezoids.
  - [x] Floor trapezoid + subtle gradient.
  - [x] Center dashed line.
  - [x] Ball floor shadow blob scaled by depth.

## Milestone 3: Two-Player Local
- [x] Mode selection: 0P / 1P / 2P.
- [x] 2P option A: split touch
  - [x] Left half controls left paddle.
  - [x] Right half controls right paddle.
  - [x] Multi-touch support detection; single-touch falls back to player 1 only.
- [x] UI:
  - [x] Settings pill menu (players, difficulty, new game).
  - [ ] Win condition (first to N points).

## Milestone 4: NPU "Smart AI" (Predictive)
- [ ] Baseline CPU predictor (gold standard):
  - [ ] Simulate forward until `x == paddleXRight` to get predicted (y,z).
  - [ ] Add reaction delay + noise + speed/accel limits for difficulty.
- [ ] Feature vector spec (target: 16 values):
  - [ ] ball: x,y,z,vx,vy,vz (6)
  - [ ] player paddle: py,pz,dpy,dpz (4)
  - [ ] AI paddle: ay,az (2)
  - [ ] score diff (1)
  - [ ] last hit offsets: lastDy,lastDz (2)
  - [ ] bias (1)
- [ ] Labels spec:
  - [ ] y_hit, z_hit, t_hit (normalized time)
- [ ] Offline training pipeline (host):
  - [ ] Generate synthetic samples by randomizing ball/paddle states.
  - [ ] Use CPU predictor/sim as label generator.
  - [ ] Train tiny MLP: 16 -> 32 -> 32 -> 3, ReLU.
  - [ ] Quantize to int8; export TFLite (or NPU-native blob as required).
- [ ] Runtime integration:
  - [ ] Add NPU HAL hooks: model load + invoke.
  - [ ] Run inference every N frames (2-4).
  - [ ] Convert outputs to AI target; apply constraints (speed/accel, reaction, noise).
- [ ] Verification:
  - [ ] Compare NPU predictor vs baseline on-device (max error thresholds, timing).

## Milestone 5: Polish + Performance
- [ ] Visual polish:
  - [ ] Paddle glow/bloom (simple, optional).
  - [ ] Improved shadows (ball + paddle contact cues).
  - [ ] Subtle vignette (optional).
- [ ] Audio:
  - [ ] Beep on hit and score (optional).
- [ ] Performance:
  - [ ] Double buffering.
  - [ ] Minimize per-frame draw calls (rects/circles/lines only).
  - [ ] DMA/accelerator usage for fills/blits when available.
  - [ ] Ensure inference budget stays below frame time (especially at 60 FPS).

## Architecture Targets (From `docs/project_description.md`)
- [ ] `platform/` HALs: display, touch, time, NPU.
- [ ] `game/` modules: game loop, physics, render, input, AI, modes.
- [ ] `assets/`: score digits font, gradient helpers, model blob.

## Open Decisions (Resolve Before Implementation)
- [x] Rendering path: raw framebuffer + tiled single-blit renderer (PAR-LCD-S035, RGB565).
- [x] Touch driver: GT911 touch controller (LPI2C2 + INT).
- [x] Player 2 input hardware availability: split-touch mapping implemented (HAL-dependent).
- [ ] NPU backend choice and model format requirements (predictor model integration pending; stub HAL present).
