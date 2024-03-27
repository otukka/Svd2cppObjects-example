
#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "STM32F217.hpp"

using namespace Svd2cppObjects;
using namespace Svd2cppObjects::STM32F217;

extern "C" void SystemInit();

void systemClockConfig();

void delay(uint32_t microseconds);

void enableMCO2();

#endif /* SYSTEM_HPP_ */
