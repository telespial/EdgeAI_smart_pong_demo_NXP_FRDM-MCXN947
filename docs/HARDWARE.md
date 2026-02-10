# Hardware (FRDM-MCXN947)

Target:
- Board: FRDM-MCXN947
- Probe: MCU-Link (CMSIS-DAP), probe index `#1` in LinkServer
- LCD: LCD-PAR-S035 (ST7796S, 480x320, FlexIO 8080), attached to J8
- Debug USB: J17

Input options (platform HAL):
- Touch panel: GT911 (LPI2C2 / FLEXCOMM2, INT on PIO4_6)
  - I2C pins: PIO4_0 (FC2_P0, SDA), PIO4_1 (FC2_P1, SCL)
  - Reset pin is shared with the LCD reset line on the shield
- Accel 4 Click (FXLS8974CF) on mikroBUS:
  - I2C via FLEXCOMM3
  - Address: `0x18` or `0x19` (ADDR SEL)
  - `WHO_AM_I`: `0x86`
