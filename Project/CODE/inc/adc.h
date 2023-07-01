#ifndef __ADC_H
#define __ADC_H

#include "headfile.h"

#define ADC_0 ADC_P00
#define ADC_1 ADC_P01
#define ADC_2 ADC_P05
#define ADC_3 ADC_P06

extern uint16 adc_data[3];

void adc_init_all();
void adc_update();

#endif // __ADC_H
