#!/bin/bash

# rm -rf build

if [[ ! -e build ]]; then
    mkdir build
    cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=cmake/STM32F2xxToolchain.cmake -DSVD_FILE=../SVDs/STM32F217.svd -B build .
fi
