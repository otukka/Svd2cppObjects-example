# Introduction

This example project utilizes the [Svd2cppObjects](https://github.com/otukka/Svd2cppObjects) library. This example is targeted for [Nucleo F207ZG](https://www.st.com/en/evaluation-tools/nucleo-f207zg.html) board. This example should be easy to convert to other STM32 Cortex-M targets.

Code is mostly written in C++ including startup functionality, which is usually handled in STM32 example project with assembly code. 

In this example, there are a few peripherals used:
* RCC (Clocks HSE, PLL, etc) 
* GPIOs (Heartbeat led)
* USART3 (prints to the virtual COM port in Nucleo board)
* TIM6 (timer, delay function)

All this is achieved with a custom C++ embedded driver. Extension to this should be easy to implement.

# Dependencies

## Linker Script

Acquire a suitable linker script file and place it in the project root directory, renaming it to `STM32F207ZG.ld`. Suitable file can be found [here](https://github.com/STMicroelectronics/STM32CubeF2/blob/master/Projects/NUCLEO-F207ZG/Examples/GPIO/GPIO_IOToggle/SW4STM32/STM32F207ZG_NUCLEO_144/STM32F207ZGTx_FLASH.ld). This file is copyrighted, so it is not included in this project.

## SVD File

Download the SDV file from [st.com](https://www.st.com/en/microcontrollers-microprocessors/stm32f2x7.html#cad-resources) and place it suitable location, then modify cmake command argument `SVD_FILE`. This file is copyrighted, so it is not included in this project.


## Compiler
Download ARM GCC compiler and modify toolchain or overwrite parameters in build step. 
### Example

```bash
curl https://developer.arm.com/-/media/Files/downloads/gnu/13.2.rel1/binrel/arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz
sudo tar -xvf arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz -C /opt/toolchains/
```

Add the following arguments to cmake command if you don't want to modify toolchain 
* TOOLCHAIN_ROOT
* TOOLCHAIN_PREFIX

### Example
```bash
-DTOOLCHAIN_ROOT=/opt/toolchains/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi
-DTOOLCHAIN_PREFIX=arm-none-eabi
```

# Build

```bash 
git clone --recurse-submodules git@github.com:otukka/Svd2cppObjects-example.git
mkdir build
cd build
cmake \
-DCMAKE_BUILD_TYPE=Debug \
-DCMAKE_TOOLCHAIN_FILE=cmake/STM32F2xxToolchain.cmake \
-DSVD_FILE=../SVDs/STM32F217.svd \
..
make
```

# Run
This project includes a .vscode folder with the correct setup to run this program. It uses the following dependencies:
* OpenOCD
* [Cortex Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)

Make corrections to the json-files according to your setup. 
