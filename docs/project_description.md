# Project Description: EdgeAI Smart Pong (FRDM-MCXN947)

Goal:
- Implement a 3D-look Pong game on FRDM-MCXN947 with LCD-PAR-S035.

Targets:
- 0P / 1P / 2P: AI vs AI, 1P vs AI, 2P local
- In-game settings UI (players 0/1/2, difficulty 1/2/3, new game)
- Touch-first control (GT911 multi-touch) with alternate inputs supported via platform HAL
- Clean separation between platform bring-up, game logic, and rendering

Visual target:
- Match `docs/pong_3D.png`: monochrome box arena, perspective depth cue, center dashed line, segmented digits, soft ball shadow.

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
- Reset serve with slight randomness.

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
- Z is controlled from an edge strip so the controlling finger does not occlude the paddle.
- Single-touch (1P): map control to the opposite-side edge strip to avoid blocking the left paddle.

UI interaction:
- Reserve a top bar region for the settings pill.
- Ignore paddle-driving touches inside the reserved UI region.

Two-player:
- Split-touch mapping: left half controls left paddle, right half controls right paddle.
- Each side uses an edge strip for z control to keep fingers off the arena interior.
- Multi-touch support is required for simultaneous independent control.

Accel fallback (optional):
- Accel 4 Click (FXLS8974CF) can drive paddle targets in y/z via tilt mapping.

## AI
Baseline CPU AI:
- Predict intercept at the right paddle plane by forward simulation with wall bounces.
- Apply reaction delay, noise, and speed limits for difficulty presets.

Optional NPU predictor (future work):
- Model predicts `(y_hit, z_hit, t_hit)` from a compact feature vector.
- Suggested features (16 values):
  - Ball: x,y,z,vx,vy,vz (6)
  - Player paddle: py,pz,dpy,dpz (4)
  - AI paddle: ay,az (2)
  - Score diff (1)
  - Last hit offsets: lastDy,lastDz (2)
  - Bias (1)

## Repo Architecture
- `src/platform/`: display, input, time, touch, NPU hooks
- `src/game/`: game loop, physics, input mapping, AI, modes, rendering
- `tools/`: bootstrap, setup, build, flash scripts
- `docs/`: hardware, build/flash, style rules, spec
