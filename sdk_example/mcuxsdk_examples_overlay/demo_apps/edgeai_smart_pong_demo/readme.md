# EdgeAI Smart Pong Demo (FRDM-MCXN947)

3D-look Pong demo with:
- 1P vs AI (baseline CPU prediction)
- 2P local (touch split or alternate inputs, via platform HAL)

Hardware assumptions:
- FRDM-MCXN947 + LCD-PAR-S035 (ST7796S, 480x320)
- Input: touch panel or Accel 4 Click (FXLS8974CF) depending on configuration

Code lives in this repo:
- `src/`
- `docs/`

This example's CMake pulls sources from this repo so development stays in one place.
