# Ubuntu 20.04 default
cmake_minimum_required(VERSION 3.16.3)

project(Svd2cppObjects-example VERSION 1.0.0 LANGUAGES ASM C CXX)

# Generate of compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_TARGET ${CMAKE_PROJECT_NAME}.elf)

add_subdirectory(Svd2cppObjects)

add_executable(${BUILD_TARGET})

target_include_directories(
    ${BUILD_TARGET}
    PRIVATE
    inc
)

target_sources(
    ${BUILD_TARGET}
    PRIVATE
    src/main.cpp
    src/system.cpp
    src/stm32f2xx_it.cpp
    src/debug.cpp
    PUBLIC
    src/dummys.cpp
)

target_link_libraries(
    ${BUILD_TARGET}
    PRIVATE
    m
    Svd2cppObjects
)

target_compile_options(
    ${BUILD_TARGET}
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -ffunction-sections
    -fdata-sections
)

target_link_options(
    ${BUILD_TARGET}
    PRIVATE
    -T
    "${CMAKE_CURRENT_LIST_DIR}/STM32F207ZG.ld"
    PUBLIC
    LINKER:-Map=mapfile
)

add_compile_definitions(SYSTEM_BIT_WIDTH=SYSTEM_32_BIT)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --save-temps")
set (CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} --save-temps")

add_custom_command(TARGET
    ${BUILD_TARGET}
    POST_BUILD
    COMMAND
    ${CMAKE_BIN_SIZE} -A -x ${BUILD_TARGET} COMMENT "\nSection sizes:\n"
)



add_custom_command(TARGET ${BUILD_TARGET} POST_BUILD COMMAND ${CMAKE_OBJDUMP} -dSCl ${BUILD_TARGET} > ${BUILD_TARGET}.s)
add_custom_command(TARGET ${BUILD_TARGET} POST_BUILD COMMAND ${CMAKE_READELF} -aWC ${BUILD_TARGET} > ${BUILD_TARGET}.txt)
