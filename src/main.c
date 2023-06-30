#include <stdint.h>
#include "stm32f4xx.h"

#define LED_PIN 0

void main(void)
{
    // enable GPIOB on the AHB
    RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOBEN_Pos);

    // Do two dummy reads after enabling the peripheral clock, as per the errata
    volatile uint32_t dummy;
    dummy = RCC->AHB1ENR;
    dummy = RCC->AHB1ENR;

    // Set the mode
    GPIOB->MODER |= (1 << GPIO_MODER_MODER0_Pos); 

    // Flash the LED
    while (1)
    {
        GPIOB->ODR ^= (1 << LED_PIN);
        for (uint32_t i = 0; i < 1000000; i++);
    }
}