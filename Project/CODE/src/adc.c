#include "adc.h"

uint16 adc_data[8];

ADCN_enum adcs[ADC_COUNT] = {
    ADC_P00,
    ADC_P01,
    ADC_P05,
    ADC_P06,
    ADC_P17,
    ADC_P16,
    ADC_P14,
    ADC_P13};

void adc_init_all()
{

    /*     adc_init(ADC_0, ADC_SYSclk_DIV_2);
        adc_init(ADC_1, ADC_SYSclk_DIV_2);
        adc_init(ADC_2, ADC_SYSclk_DIV_2);
        adc_init(ADC_3, ADC_SYSclk_DIV_2);
        adc_init(ADC_4, ADC_SYSclk_DIV_2);
        adc_init(ADC_5, ADC_SYSclk_DIV_2);
        adc_init(ADC_6, ADC_SYSclk_DIV_2);
        adc_init(ADC_7, ADC_SYSclk_DIV_2); */
    int i = 0;
    while (++i < ADC_COUNT) {
        adc_init(adcs[i], ADC_SYSclk_DIV_2);
    }
}

void adc_update()
{
    /*     adc_data[0] = adc_once(ADC_0, ADC_12BIT);
        adc_data[1] = adc_once(ADC_1, ADC_12BIT);
        adc_data[2] = adc_once(ADC_2, ADC_12BIT);
        adc_data[3] = adc_once(ADC_3, ADC_12BIT);
        adc_data[4] = adc_once(ADC_4, ADC_12BIT);
        adc_data[5] = adc_once(ADC_5, ADC_12BIT);
        adc_data[6] = adc_once(ADC_6, ADC_12BIT);
        adc_data[7] = adc_once(ADC_7, ADC_12BIT); */
    int i = 0;
    while (++i < ADC_COUNT) {
        adc_data[i] = adc_once(adcs[i], ADC_12BIT);
    }
}