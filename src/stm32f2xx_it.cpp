#include "stm32f2xx_it.hpp"

void Reset_Handler()
{
    unsigned int *src, *dst;

    // Set stack pointer
    asm volatile("ldr sp, =_estack");

    // Copy the data segment initializers from flash to SRAM
    src = &_sidata;
    dst = &_sdata;
    while (dst < &_edata)
        *(dst++) = *(src++);

    // Zero fill the bss segment
    dst = &_sbss;
    while (dst < &_ebss)
        *(dst++) = 0;

    // Call the clock system initialization function
    SystemInit();

    // Call static constructors
    __libc_init_array();

    // Call the application's entry point
    main();

    // Branch with link register (return)
    asm volatile("bx lr");
}

void HardFault_Handler(void)
{

    while (1)
    {
    }
}

void MemManage_Handler(void)
{
    while (1)
    {
    }
}

void UsageFault_Handler(void)
{
    while (1)
    {
    }
}

void BusFault_Handler(void)
{
    while (1)
    {
    }
}

void NMI_Handler(void) {}
void PendSV_Handler(void) {}
void SVC_Handler(void) {}
void SysTick_Handler(void) {}

void DebugMon_Handler(void) {}

void WWDG_IRQHandler(void) {}
void PVD_IRQHandler(void) {}
void TAMP_STAMP_IRQHandler(void) {}
void RTC_WKUP_IRQHandler(void) {}
void FLASH_IRQHandler(void) {}
void RCC_IRQHandler(void) {}
void EXTI0_IRQHandler(void) {}
void EXTI1_IRQHandler(void) {}
void EXTI2_IRQHandler(void) {}
void EXTI3_IRQHandler(void) {}
void EXTI4_IRQHandler(void) {}
void DMA1_Stream0_IRQHandler(void) {}
void DMA1_Stream1_IRQHandler(void) {}
void DMA1_Stream2_IRQHandler(void) {}
void DMA1_Stream3_IRQHandler(void) {}
void DMA1_Stream4_IRQHandler(void) {}
void DMA1_Stream5_IRQHandler(void) {}
void DMA1_Stream6_IRQHandler(void) {}
void ADC_IRQHandler(void) {}
void CAN1_TX_IRQHandler(void) {}
void CAN1_RX0_IRQHandler(void) {}
void CAN1_RX1_IRQHandler(void) {}
void CAN1_SCE_IRQHandler(void) {}
void EXTI9_5_IRQHandler(void) {}
void TIM1_BRK_TIM9_IRQHandler(void) {}
void TIM1_UP_TIM10_IRQHandler(void) {}
void TIM1_TRG_COM_TIM11_IRQHandler(void) {}
void TIM1_CC_IRQHandler(void) {}
void TIM2_IRQHandler(void) {}
void TIM3_IRQHandler(void) {}
void TIM4_IRQHandler(void) {}
void I2C1_EV_IRQHandler(void) {}
void I2C1_ER_IRQHandler(void) {}
void I2C2_EV_IRQHandler(void) {}
void I2C2_ER_IRQHandler(void) {}
void SPI1_IRQHandler(void) {}
void SPI2_IRQHandler(void) {}
void USART1_IRQHandler(void) {}
void USART2_IRQHandler(void) {}
void USART3_IRQHandler(void) {}
void EXTI15_10_IRQHandler(void) {}
void RTC_Alarm_IRQHandler(void) {}
void OTG_FS_WKUP_IRQHandler(void) {}
void TIM8_BRK_TIM12_IRQHandler(void) {}
void TIM8_UP_TIM13_IRQHandler(void) {}
void TIM8_TRG_COM_TIM14_IRQHandler(void) {}
void TIM8_CC_IRQHandler(void) {}
void DMA1_Stream7_IRQHandler(void) {}
void FSMC_IRQHandler(void) {}
void SDIO_IRQHandler(void) {}
void TIM5_IRQHandler(void) {}
void SPI3_IRQHandler(void) {}
void UART4_IRQHandler(void) {}
void UART5_IRQHandler(void) {}
void TIM6_DAC_IRQHandler(void) {}
void TIM7_IRQHandler(void) {}
void DMA2_Stream0_IRQHandler(void) {}
void DMA2_Stream1_IRQHandler(void) {}
void DMA2_Stream2_IRQHandler(void) {}
void DMA2_Stream3_IRQHandler(void) {}
void DMA2_Stream4_IRQHandler(void) {}
void ETH_IRQHandler(void) {}
void ETH_WKUP_IRQHandler(void) {}
void CAN2_TX_IRQHandler(void) {}
void CAN2_RX0_IRQHandler(void) {}
void CAN2_RX1_IRQHandler(void) {}
void CAN2_SCE_IRQHandler(void) {}
void OTG_FS_IRQHandler(void) {}
void DMA2_Stream5_IRQHandler(void) {}
void DMA2_Stream6_IRQHandler(void) {}
void DMA2_Stream7_IRQHandler(void) {}
void USART6_IRQHandler(void) {}
void I2C3_EV_IRQHandler(void) {}
void I2C3_ER_IRQHandler(void) {}
void OTG_HS_EP1_OUT_IRQHandler(void) {}
void OTG_HS_EP1_IN_IRQHandler(void) {}
void OTG_HS_WKUP_IRQHandler(void) {}
void OTG_HS_IRQHandler(void) {}
void DCMI_IRQHandler(void) {}
void HASH_RNG_IRQHandler(void) {}

const std::array<uintptr_t, 97> vector_table __attribute__((section(".isr_vector"))) = {

    INIT_SP,
    reinterpret_cast<uintptr_t>(&Reset_Handler),
    reinterpret_cast<uintptr_t>(&NMI_Handler),
    reinterpret_cast<uintptr_t>(&HardFault_Handler),
    reinterpret_cast<uintptr_t>(&MemManage_Handler),
    reinterpret_cast<uintptr_t>(&BusFault_Handler),
    reinterpret_cast<uintptr_t>(&UsageFault_Handler),
    0,
    0,
    0,
    0,
    reinterpret_cast<uintptr_t>(&SVC_Handler),
    0,
    0,
    reinterpret_cast<uintptr_t>(&PendSV_Handler),
    reinterpret_cast<uintptr_t>(&SysTick_Handler),
    reinterpret_cast<uintptr_t>(&TIM3_IRQHandler),
    reinterpret_cast<uintptr_t>(&WWDG_IRQHandler),
    reinterpret_cast<uintptr_t>(&PVD_IRQHandler),
    reinterpret_cast<uintptr_t>(&TAMP_STAMP_IRQHandler),
    reinterpret_cast<uintptr_t>(&RTC_WKUP_IRQHandler),
    reinterpret_cast<uintptr_t>(&FLASH_IRQHandler),
    reinterpret_cast<uintptr_t>(&RCC_IRQHandler),
    reinterpret_cast<uintptr_t>(&EXTI0_IRQHandler),
    reinterpret_cast<uintptr_t>(&EXTI1_IRQHandler),
    reinterpret_cast<uintptr_t>(&EXTI2_IRQHandler),
    reinterpret_cast<uintptr_t>(&EXTI3_IRQHandler),
    reinterpret_cast<uintptr_t>(&EXTI4_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA1_Stream0_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA1_Stream1_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA1_Stream2_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA1_Stream3_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA1_Stream4_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA1_Stream5_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA1_Stream6_IRQHandler),
    reinterpret_cast<uintptr_t>(&ADC_IRQHandler),
    reinterpret_cast<uintptr_t>(&CAN1_TX_IRQHandler),
    reinterpret_cast<uintptr_t>(&CAN1_RX0_IRQHandler),
    reinterpret_cast<uintptr_t>(&CAN1_RX1_IRQHandler),
    reinterpret_cast<uintptr_t>(&CAN1_SCE_IRQHandler),
    reinterpret_cast<uintptr_t>(&EXTI9_5_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM1_BRK_TIM9_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM1_UP_TIM10_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM1_TRG_COM_TIM11_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM1_CC_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM2_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM3_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM4_IRQHandler),
    reinterpret_cast<uintptr_t>(&I2C1_EV_IRQHandler),
    reinterpret_cast<uintptr_t>(&I2C1_ER_IRQHandler),
    reinterpret_cast<uintptr_t>(&I2C2_EV_IRQHandler),
    reinterpret_cast<uintptr_t>(&I2C2_ER_IRQHandler),
    reinterpret_cast<uintptr_t>(&SPI1_IRQHandler),
    reinterpret_cast<uintptr_t>(&SPI2_IRQHandler),
    reinterpret_cast<uintptr_t>(&USART1_IRQHandler),
    reinterpret_cast<uintptr_t>(&USART2_IRQHandler),
    reinterpret_cast<uintptr_t>(&USART3_IRQHandler),
    reinterpret_cast<uintptr_t>(&EXTI15_10_IRQHandler),
    reinterpret_cast<uintptr_t>(&RTC_Alarm_IRQHandler),
    reinterpret_cast<uintptr_t>(&OTG_FS_WKUP_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM8_BRK_TIM12_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM8_UP_TIM13_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM8_TRG_COM_TIM14_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM8_CC_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA1_Stream7_IRQHandler),
    reinterpret_cast<uintptr_t>(&FSMC_IRQHandler),
    reinterpret_cast<uintptr_t>(&SDIO_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM5_IRQHandler),
    reinterpret_cast<uintptr_t>(&SPI3_IRQHandler),
    reinterpret_cast<uintptr_t>(&UART4_IRQHandler),
    reinterpret_cast<uintptr_t>(&UART5_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM6_DAC_IRQHandler),
    reinterpret_cast<uintptr_t>(&TIM7_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA2_Stream0_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA2_Stream1_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA2_Stream2_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA2_Stream3_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA2_Stream4_IRQHandler),
    reinterpret_cast<uintptr_t>(&ETH_IRQHandler),
    reinterpret_cast<uintptr_t>(&ETH_WKUP_IRQHandler),
    reinterpret_cast<uintptr_t>(&CAN2_TX_IRQHandler),
    reinterpret_cast<uintptr_t>(&CAN2_RX0_IRQHandler),
    reinterpret_cast<uintptr_t>(&CAN2_RX1_IRQHandler),
    reinterpret_cast<uintptr_t>(&CAN2_SCE_IRQHandler),
    reinterpret_cast<uintptr_t>(&OTG_FS_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA2_Stream5_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA2_Stream6_IRQHandler),
    reinterpret_cast<uintptr_t>(&DMA2_Stream7_IRQHandler),
    reinterpret_cast<uintptr_t>(&USART6_IRQHandler),
    reinterpret_cast<uintptr_t>(&I2C3_EV_IRQHandler),
    reinterpret_cast<uintptr_t>(&I2C3_ER_IRQHandler),
    reinterpret_cast<uintptr_t>(&OTG_HS_EP1_OUT_IRQHandler),
    reinterpret_cast<uintptr_t>(&OTG_HS_EP1_IN_IRQHandler),
    reinterpret_cast<uintptr_t>(&OTG_HS_WKUP_IRQHandler),
    reinterpret_cast<uintptr_t>(&OTG_HS_IRQHandler),
    reinterpret_cast<uintptr_t>(&DCMI_IRQHandler),
    reinterpret_cast<uintptr_t>(&HASH_RNG_IRQHandler),
};