#include <stdio.h>
#include "myGPIO.h"
#include "myADC.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_adc/adc_oneshot.h"

#define CHANNEL ADC_CHANNEL_7
#define ADC_UNIT 1

void app_main(void)
{
    myADC_setup(CHANNEL);
    while (1)
    {
        vTaskDelay(10);
        int adc_value = myADC_getValue(CHANNEL);
        printf("ADC Value: %d\n", adc_value);
    }
    
}
