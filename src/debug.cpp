
#include <stdio.h>
#include <string.h>

#include "STM32F217.hpp"
#include "debug.hpp"

namespace
{
    using namespace Svd2cppObjects;
    using namespace Svd2cppObjects::STM32F217;
    static char m_buffer[DEBUG_BUFFER_LEN];
}

void debugSerialInit(void)
{
    // Create RCC peripheral instance
    auto RCC = PeripheralFactory::instance()->createRCC();

    // Enable USART3 clock
    RCC->APB1ENR->USART3EN->set();

    // Enable GPIO Port D clock
    RCC->AHB1ENR->GPIODEN->set();

    // Create GPIO Port D peripheral instance
    auto GPIOD = PeripheralFactory::instance()->createGPIOD();

    // Configure Pin 8 for USART3 TX
    GPIOD->MODER->MODER8 = 0b10;      // Alternate function mode
    GPIOD->OSPEEDR->OSPEEDR8 = 0b10;  // High speed
    GPIOD->PUPDR->PUPDR8 = 0b01;      // Pull-up
    GPIOD->AFRH->AFRH8 = 0b111;       // Alternate function AF7 (USART3 TX)

    // Configure Pin 9 for USART3 RX
    GPIOD->MODER->MODER9 = 0b10;      // Alternate function mode
    GPIOD->OSPEEDR->OSPEEDR9 = 0b10;  // High speed
    GPIOD->PUPDR->PUPDR9 = 0b01;      // Pull-up
    GPIOD->AFRH->AFRH9 = 0b111;       // Alternate function AF7 (USART3 RX)

    // Create USART3 peripheral instance
    auto USART3 = PeripheralFactory::instance()->createUSART3();

    // Configure USART3 baud rate
    USART3->BRR->DIV_Mantissa = 32;
    USART3->BRR->DIV_Fraction = 9;

    USART3->CR1->UE = 1;     // Enable USART3
    USART3->CR1->OVER8 = 0;  // Oversampling by 16
    USART3->CR1->M = 0;      // 8 data bits
    USART3->CR1->PCE = 0;    // Disable parity control

    USART3->CR2->CPHA = 0;  // Clock phase set to 0
    USART3->CR2->CPOL = 0;  // Clock polarity set to 0
}
void serialPrint(const char* a_format, ...)
{
    int ret = 0;
    memset(&m_buffer[0], '\0', DEBUG_BUFFER_LEN);

    va_list args;
    va_start(args, a_format);
    ret = vsnprintf(&m_buffer[0], DEBUG_BUFFER_LEN, a_format, args);

    if (ret > 0)
    {
        auto USART3 = PeripheralFactory::instance()->createUSART3();

        size_t index = 0;

        USART3->CR1->RE = 1;
        USART3->CR1->TE = 1;
        while (m_buffer[index] != '\0')
        {

            USART3->DR = static_cast<REG_ADDR>(m_buffer[index]);
            index++;

            while (USART3->SR->TXE == 0)
            {
            }
        }

        while (USART3->SR->TC != 1)
        {
        }
        USART3->CR1->TE = 0;
        USART3->CR1->RE = 0;
    }
    va_end(args);
}
