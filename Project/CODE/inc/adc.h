#ifndef __ADC_H
#define __ADC_H

#include "headfile.h"


/* #define ADC_0 ADC_P00
#define ADC_1 ADC_P01
#define ADC_2 ADC_P05
#define ADC_3 ADC_P06
#define ADC_4 ADC_P17
#define ADC_5 ADC_P16
#define ADC_6 ADC_P14
#define ADC_7 ADC_P13 */

#define ADC_COUNT 8

extern uint16 adc_data[ADC_COUNT];

void adc_init_all();
void adc_update();

#endif // __ADC_H
