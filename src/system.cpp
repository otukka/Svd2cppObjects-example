#include "system.hpp"

void SystemInit(void)
{
    auto RCC = PeripheralFactory::instance()->createRCC();
    auto SCB = PeripheralFactory::instance()->createSCB();

    // Set HSION bit
    RCC->CR->HSION->set(1);

    // Reset CFGR register
    RCC->CFGR.reset();

    // Reset HSEON, CSSON and PLLON bits
    RCC->CR->HSEON.clear();
    RCC->CR->CSSON.clear();
    RCC->CR->PLLON.clear();

    // Reset PLLCFGR register
    RCC->PLLCFGR.reset();

    // Reset HSEBYP bit
    RCC->CR->HSEBYP.clear();

    // Disable all interrupts
    RCC->CIR.reset();

    // Reset all peripheral enable registers
    RCC->AHB1ENR.reset();
    RCC->AHB2ENR.reset();
    RCC->AHB3ENR.reset();
    RCC->APB1ENR.reset();
    RCC->APB2ENR.reset();

    // Configure the vector table offset
    SCB->VTOR->TBLOFF->set(0x400000);
}

void systemClockConfig()
{
    auto RCC = PeripheralFactory::instance()->createRCC();

    RCC->CR->HSEON->clear();
    RCC->CR->HSEBYP->clear();
    RCC->CR->HSEON->set();

    // HSE = 1, HSI = 0
    RCC->PLLCFGR->PLLSRC->set(1);

    // P = 2
    RCC->PLLCFGR->PLLP1->set(0);
    RCC->PLLCFGR->PLLP0->set(0);

    // N = 240
    RCC->PLLCFGR->PLLN8->set(0);
    RCC->PLLCFGR->PLLN7->set(1);
    RCC->PLLCFGR->PLLN6->set(1);
    RCC->PLLCFGR->PLLN5->set(1);
    RCC->PLLCFGR->PLLN4->set(1);
    RCC->PLLCFGR->PLLN3->set(0);
    RCC->PLLCFGR->PLLN2->set(0);
    RCC->PLLCFGR->PLLN1->set(0);
    RCC->PLLCFGR->PLLN0->set(0);

    // PLL M = 8
    RCC->PLLCFGR->PLLM5->set(0);
    RCC->PLLCFGR->PLLM4->set(0);
    RCC->PLLCFGR->PLLM3->set(1);
    RCC->PLLCFGR->PLLM2->set(0);
    RCC->PLLCFGR->PLLM1->set(0);
    RCC->PLLCFGR->PLLM0->set(0);

    // ABH = 120 MHz = SYSCLK
    RCC->CFGR->HPRE3->set(0);
    RCC->CFGR->HPRE2->set(0);
    RCC->CFGR->HPRE1->set(0);
    RCC->CFGR->HPRE0->set(0);

    // APB2 = 30 MHz
    RCC->CFGR->PPRE12->set(1);
    RCC->CFGR->PPRE11->set(0);
    RCC->CFGR->PPRE10->set(0);

    // APB1 = 60 MHz
    RCC->CFGR->PPRE22->set(1);
    RCC->CFGR->PPRE21->set(0);
    RCC->CFGR->PPRE20->set(0);

    // Activate PLL
    RCC->CR->PLLON->set(1);

    // Modify flash latency
    auto FLASH = PeripheralFactory::instance()->createFLASH();
    FLASH->ACR->LATENCY = 3;

    while (!(RCC->CR->PLLRDY->get() && RCC->CR->HSERDY->get()))
    {
    }

    // Set SYSCLK source to PLL
    RCC->CFGR->SW1->set(1);
    RCC->CFGR->SW0->set(0);

    // Disable HSI
    RCC->CR->HSION.clear();
}

// This is super simple delay function. Note the limits
void delay(uint32_t microseconds)
{
    auto RCC = PeripheralFactory::instance()->createRCC();
    auto TIM6 = PeripheralFactory::instance()->createTIM6();

    // Enable TIM6 clock
    RCC->APB1ENR->TIM6EN->set();

    // Set prescaler value to have 1ms tick
    TIM6->PSC->PSC->set(60 * 1000 * 1000 / 1000 - 1);

    // Compute Auto-Reload Value to get desired delay
    TIM6->ARR->ARR->set(microseconds);

    // Disable Auto-Reload Preload
    TIM6->CR1->ARPE = 0;

    // Counter stops counting at the next update event (clearing the CEN bit).
    TIM6->CR1->OPM = 1;

    // Clear update event flag
    TIM6->SR->UIF.clear();

    // Enable counter
    TIM6->CR1->CEN->set();

    // Wait until the update event occurs (delay time)
    while (TIM6->SR->UIF->get() == 0)
        ;

    // Clear update event flag
    TIM6->SR->UIF.clear();

    // Disable TIM6 clock
    RCC->APB1ENR->TIM6EN->set();
}
