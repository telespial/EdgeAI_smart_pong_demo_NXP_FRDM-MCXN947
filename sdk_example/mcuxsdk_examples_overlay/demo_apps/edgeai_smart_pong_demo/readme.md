# Smart Pong Demo (FRDM-MCXN947)

3D-look Pong demo with:
- 0P / 1P / 2P modes
- 0P accel ball nudge (FXLS8974CF tilt perturbation)
- NPU-enabled AI path (TFLM + eIQ Neutron) with CPU fallback
- In-game settings include players, difficulty, AI on/off, and new game
- 1P vs AI and 2P local (touch split or alternate inputs via platform HAL)

Hardware assumptions:
- FRDM-MCXN947 + LCD-PAR-S035 (ST7796S, 480x320)
- Input: touch panel or Accel 4 Click (FXLS8974CF) depending on configuration

Code lives in this repo:
- `src/`
- `docs/`

This example's CMake pulls sources from this repo so development stays in one place.
