cmake_minimum_required(VERSION 3.22.0)

include(${SdkRootDirPath}/cmake/extension/mcux.cmake)

project(edgeai_smart_pong_demo LANGUAGES C CXX ASM PROJECT_BOARD_PORT_PATH ${board_root}/${board}/demo_apps/edgeai_smart_pong_demo)

include(${SdkRootDirPath}/CMakeLists.txt)

if(DEFINED ENV{EDGEAI_SMART_PONG_DEMO_ROOT})
    set(EDGEAI_ROOT "$ENV{EDGEAI_SMART_PONG_DEMO_ROOT}")
else()
    # Default layout: this repo contains ./mcuxsdk_ws and the workspace contains mcuxsdk/.
    # SdkRootDirPath points at <repo>/mcuxsdk_ws/mcuxsdk, so ../.. is the repo root.
    get_filename_component(EDGEAI_ROOT "${SdkRootDirPath}/../.." ABSOLUTE)
endif()

mcux_add_source(
    BASE_PATH ${EDGEAI_ROOT}
    SOURCES src/edgeai_smart_pong_demo.c
            src/accel_proc.c
            src/fxls8974cf.c
            src/par_lcd_s035.c
            src/text5x7.c
            src/sw_render.c
            src/platform/display_hal.c
            src/platform/input_hal.c
            src/platform/time_hal.c
            src/platform/touch_hal_stub.c
            src/platform/npu_hal_stub.c
            src/game/ai.c
            src/game/game.c
            src/game/input.c
            src/game/modes.c
            src/game/physics.c
            src/game/render.c
)

mcux_add_include(
    BASE_PATH ${EDGEAI_ROOT}
    INCLUDES src
)

# Touch controller (GT911) for LCD-PAR-S035 touch panel.
mcux_add_source(
    BASE_PATH ${SdkRootDirPath}
    SOURCES components/touch/gt911/fsl_gt911.c
)

mcux_add_include(
    BASE_PATH ${SdkRootDirPath}
    INCLUDES components/touch/gt911
)

# Default linker script stack is 0x800 (2 KB), which is enough for the render loop
# but not for TFLM/Neutron init/invoke when NPU inference is enabled (STKOF/HardFault).
if(DEFINED EDGEAI_ENABLE_NPU_INFERENCE AND EDGEAI_ENABLE_NPU_INFERENCE)
  mcux_add_linker_symbol(SYMBOLS "__stack_size__=0x2000")
endif()

include(${SdkRootDirPath}/${board_root}/${board}/demo_apps/edgeai_smart_pong_demo/reconfig.cmake OPTIONAL)

mcux_convert_binary(BINARY ${APPLICATION_BINARY_DIR}/${MCUX_SDK_PROJECT_NAME}.bin)
