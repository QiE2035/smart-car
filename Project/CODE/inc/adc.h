#ifndef __ADC_H
#define __ADC_H

#include "headfile.h"

#define ADC_COUNT     8
#define ADC_K_COUNT   4
#define ADC_REC_COUNT 10

extern uint16 adc_datas[ADC_COUNT];
extern int adc_k[ADC_K_COUNT];

#define ADC_L1 adc_datas[7]
#define ADC_L2 adc_datas[6]
#define ADC_L3 adc_datas[5]

#define ADC_R2 adc_datas[1]
#define ADC_R1 adc_datas[2]
#define ADC_R3 adc_datas[0]

#define ADC_MF adc_datas[3]
#define ADC_MB adc_datas[4]

#define ADC_MAX    3000.0
#define ADC_NORMAL 100

extern int adc_bias;

void adc_init_all();
void adc_update();
// int adc_bias();

#endif // __ADC_H
