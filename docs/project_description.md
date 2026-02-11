# Project Description: Smart Pong (FRDM-MCXN947)

Goal:
- Implement a 3D-look Pong game on FRDM-MCXN947 with LCD-PAR-S035.

Targets:
- 0P / 1P / 2P: AI vs AI, 1P vs AI, 2P local
- In-game settings UI (players 0/1/2, difficulty 1/2/3, AI on/off, new game)
- Touch-first control (GT911 multi-touch) with alternate inputs supported via platform HAL
- Clean separation between platform bring-up, game logic, and rendering

Visual target:
- Match `docs/pong_3D.png`: monochrome box arena, perspective depth cue, center dashed line, segmented digits, soft ball shadow.

Inspiration:
- Pong is a 1972 sports video game developed and published by Atari, Inc. for arcades. It was created by Allan Alcorn as a training exercise assigned to him by Atari co-founder Nolan Bushnell.

## 3D-Look Rendering Model (MCU-Friendly)
This demo does not require a full 3D engine. It uses:
- 3D game state (x, y, z)
- Cheap perspective projection into 2D
- Simple lighting cues (flat shades, gradients, shadow blob)

## World Model (Normalized Coordinates)
Use normalized coordinates to keep physics independent of screen resolution:
- x: 0 (left paddle plane) -> 1 (right paddle plane)
- y: 0 (top) -> 1 (bottom)
- z: 0 (near) -> 1 (far)

Ball:
- `pos = (x, y, z)`
- `vel = (vx, vy, vz)`
- `radius = r` (normalized)

Paddles (left/right):
- Plane: `x = constant`
- Center: `(y, z)`
- Size: `(size_y, size_z)`

## Physics (Deterministic, Fixed Timestep)
Loop:
- Fixed timestep at 60 FPS default (30 FPS optional).

Wall collisions:
- Bounce on y bounds and z bounds with radius-aware clamping.

Paddle collisions:
- Detect intersection at x plane while ball moves toward a paddle.
- Check overlap in (y, z) with radius padding.
- On hit:
  - Invert `vx`
  - Apply "english" based on hit offset in y/z
  - Add paddle velocity influence to `vy` and `vz`

Scoring:
- Score when ball passes beyond x bounds.
- First side to 11 points wins the match.
- Reset serve from center with slight randomness toward the side that just conceded.
- Apply a pre-serve `3,2,1` countdown on new game start only.

## Projection
Perspective projection:
- `scale = 1 / (1 + z * persp)`
- `sx = cx + (x - 0.5) * world_scale_x * scale`
- `sy = cy + (y - 0.5) * world_scale_y * scale`

Depth cues:
- Ball and paddle sizes scale with depth.
- Ball shadow blob is drawn on the floor plane (y = 1), scaled by depth.

## Input
Touch mapping (when available):
- Touch y -> paddle y
- Touch x -> paddle z
- Apply smoothing and speed limits in the controller layer.
- Y is remapped to full paddle range below the reserved UI bar.
- Z uses full-region mapping by default; an optional edge-strip remap supports non-occluding control.
- Single-touch (1P): opposite-side edge-strip remap is supported to keep the finger off the left paddle region.

UI interaction:
- Reserve a top bar region for the settings pill.
- Ignore paddle-driving touches inside the reserved UI region.

Two-player:
- Split-touch mapping: left half controls left paddle, right half controls right paddle.
- Each side supports full-range z mapping; optional edge strips remap z to full range near screen edges.
- Single-touch drives the touched side; multi-touch supports simultaneous independent control.

Accel (optional):
- Accel 4 Click (FXLS8974CF) tilt is available as a non-touch input path.
- 0P mode: tilt nudges ball `vy`/`vz` to perturb AI vs AI outcomes.

## AI
Baseline CPU AI:
- Predict intercept at the right paddle plane by forward simulation with wall bounces.
- Apply reaction delay, noise, and speed limits for difficulty presets.

NPU predictor path:
- Model predicts `(y_hit, z_hit, t_hit)` from a compact feature vector.
- Feature vector (16 values):
  - Ball: x,y,z,vx,vy,vz (6)
  - Player paddle: py,pz,dpy,dpz (4)
  - AI paddle: ay,az (2)
  - Score diff (1)
  - Last hit offsets: lastDy,lastDz (2)
  - Bias (1)
- Runtime uses NPU-first prediction with CPU predictor fallback.

Current implementation notes:
- NPU runtime uses TFLM + eIQ Neutron (`CONFIG_EDGEAI_USE_NPU=y`).
- Embedded model is a NeutronGraph placeholder blob in `src/npu/model_ds_cnn_s_npu_data.h`.
- Current NPU output contributes deterministic perturbation terms; final `(y_hit, z_hit, t_hit)` is solved by an analytic intercept path.
- Planned upgrade path: replace placeholder with Pong-specific predictor model that emits direct intercept outputs.

## Repo Architecture
- `src/platform/`: display, input, time, touch, NPU hooks
- `src/game/`: game loop, physics, input mapping, AI, modes, rendering
- `tools/`: bootstrap, setup, build, flash scripts
- `docs/`: hardware, build/flash, style rules, spec
