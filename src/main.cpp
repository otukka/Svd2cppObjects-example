

#include "main.hpp"

#include "STM32F217.hpp"
#include "debug.hpp"
#include "system.hpp"

namespace
{

    using namespace Svd2cppObjects;
    using namespace Svd2cppObjects::STM32F217;

    void led_init()
    {
        // Initialize the RCC (Reset and Clock Control) peripheral using PeripheralFactory
        auto RCC = PeripheralFactory::instance()->createRCC();

        // Enable GPIOG clock in AHB1ENR register of RCC
        RCC->AHB1ENR->GPIOGEN->set(1);

        // Create GPIO_G peripheral using PeripheralFactory
        auto GPIO_G = PeripheralFactory::instance()->createGPIOG();

        // Configure GPIOG pin 6 for output mode
        GPIO_G->MODER->MODER6->set(1);

        // Configure GPIOG pin 6 as push-pull output
        GPIO_G->OTYPER->OT6->set(0);

        // Set GPIOG pin 6 to medium speed
        GPIO_G->OSPEEDR->OSPEEDR6->set(2);

        // Enable pull-up configuration for GPIOG pin 6
        GPIO_G->PUPDR->PUPDR6->set(1);
    }

    void led_toggle()
    {
        // Create GPIOG peripheral using PeripheralFactory
        auto GPIOG = PeripheralFactory::instance()->createGPIOG();

        // Check if GPIOG pin 6 output data register bit is set
        if (GPIOG->ODR->ODR6->get())
        {
            // Clear GPIOG pin 6 using bit reset in BSRR register
            GPIOG->BSRR->BR6->set();
        }
        else
        {
            // Set GPIOG pin 6 using bit set in BSRR register
            GPIOG->BSRR->BS6->set();
        }
    }
}

PeripheralFactory* PeripheralFactory::instance_ = nullptr;

int main(void)
{

    systemClockConfig();

    led_init();

    debugSerialInit();

    const char* message = "Hello world!\r\n";

    for (;;)
    {
        serialPrint(message);
        led_toggle();
        delay(LOOP_DELAY_MS);
    }

    return 0;
}
