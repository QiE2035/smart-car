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

#define ADC_L1 adc_data[4]
#define ADC_L2 adc_data[5]
#define ADC_L3 adc_data[6]

#define ADC_R1 adc_data[1]
#define ADC_R2 adc_data[2]
#define ADC_R3 adc_data[3]

#define ADC_MF adc_data[0]
#define ADC_MB adc_data[7]

#define ADC_K_COUNT 3

extern int adc_k[ADC_K_COUNT];

void adc_init_all();
void adc_update();
int adc_bias_and();

#endif // __ADC_H
