

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

if (NOT DEFINED TOOLCHAIN_ROOT)
  set(TOOLCHAIN_ROOT "/opt/toolchains/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi")
endif()

if (NOT DEFINED TOOLCHAIN_PREFIX)
  set(TOOLCHAIN_PREFIX "arm-none-eabi")
endif()

set(TOOLCHAIN_BINARIES ${TOOLCHAIN_ROOT}/bin)


set(CMAKE_SYSROOT ${TOOLCHAIN_ROOT}/${TOOLCHAIN_PREFIX})

set(CMAKE_C_COMPILER ${TOOLCHAIN_BINARIES}/${TOOLCHAIN_PREFIX}-gcc)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_BINARIES}/${TOOLCHAIN_PREFIX}-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_BINARIES}/${TOOLCHAIN_PREFIX}-g++)
set(CMAKE_BIN_SIZE ${TOOLCHAIN_BINARIES}/${TOOLCHAIN_PREFIX}-size)
set(CMAKE_READELF ${TOOLCHAIN_BINARIES}/${TOOLCHAIN_PREFIX}-readelf)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-m3 -march=armv7-m -mthumb -mfpu=vfp -msoft-float --save-temps" CACHE STRING "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-m3 -march=armv7-m -mthumb -mfpu=vfp -msoft-float --save-temps" CACHE STRING "")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --specs=nosys.specs -Wl,--gc-sections -Wl,--print-memory-usage" CACHE STRING "")
