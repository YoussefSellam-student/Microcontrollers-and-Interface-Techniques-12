#include <stdio.h>
#include "myADC.h"
#include "esp_adc/adc_oneshot.h"

// --- DEFAULT CONFIGURATION STRUCTS FOR ADC DRIVER
// These structs will be used to initialize the ADC driver.
adc_oneshot_unit_handle_t adc_handle;
// This struct tells ESP-IDF how to initialize the ADC hardware unit.
adc_oneshot_unit_init_cfg_t adc_config = {
    .unit_id = ADC_UNIT_1,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
};
// This struct defines the per-channel ADC settings for the one-shot ADC driver.
adc_oneshot_chan_cfg_t default_channel_config = {
    .bitwidth = ADC_BITWIDTH_DEFAULT,
    .atten = ADC_ATTEN_DB_12,
};

// --- FUNCTION DEFINITIONS
void myADC_setup(int channel)
{
    adc_oneshot_new_unit(&adc_config, &adc_handle);
    adc_oneshot_config_channel(adc_handle, channel, &default_channel_config);
}

int myADC_getValue(int channel)
{
    int getal;
    adc_oneshot_read(adc_handle, channel, &getal);
    return getal;
}
