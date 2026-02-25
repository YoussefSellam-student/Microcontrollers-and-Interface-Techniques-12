#include <stdio.h>
#include "driver/gpio.h"
#include "myGPIO.h"

void myGPIO_LED_Setup(int pin)
{
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_INPUT_OUTPUT);
}

void myGPIO_LED_On(int pin)
{
    gpio_set_level(pin, 1);
}

void myGPIO_LED_Off(int pin)
{
    gpio_set_level(pin, 0);
}

void myGPIO_LED_Toggle(int pin)
{
    if (gpio_get_level(pin))
    {
        gpio_set_level(pin, 0);
    }
    else
    {
        gpio_set_level(pin, 1);
    }
}