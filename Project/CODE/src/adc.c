#include "adc.h"

int adc_datas[8];

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
    int i = 0;
    while (++i < ADC_COUNT) {
        adc_init(adcs[i], ADC_SYSclk_DIV_2);
    }
}

float adc_k[ADC_K_COUNT] = {1.0, 2.5, 0, 150};

int adc_bias = 0;

// 更新差比和
static void adc_update_bias()
{
    int bias = adc_k[0] * (ADC_L1 - ADC_R1) +
               adc_k[1] * (ADC_L2 - ADC_R2) +
               adc_k[2] * (ADC_L3 - ADC_R3),
        and = adc_k[0] * (ADC_L1 + ADC_R1) +
              adc_k[1] * (ADC_L2 + ADC_R2) +
              adc_k[2] * (ADC_L3 + ADC_R3);

    adc_bias = bias * adc_k[3] / and;
}

static uint16 adc_filter(ADCN_enum adc)
{
    uint16 adc_records[ADC_REC_COUNT], i, j, tmp;

    for (i = 0; ++i < ADC_REC_COUNT;) {
        adc_records[i] = adc_once(adc, ADC_12BIT);
    }

    for (i = 0; ++i < ADC_REC_COUNT;) {
        for (j = 0; ++j < i;) {
            if (adc_records[j] < adc_records[j + 1]) {
                tmp = adc_records[j];
                adc_records[j] = adc_records[j + 1];
                adc_records[j + 1] = tmp;
            }
        }
    }

    tmp = 0;
    for (i = 1; i < ADC_REC_COUNT - 2; i++) {
        tmp += adc_records[i];
    }

    return tmp / (ADC_REC_COUNT - 2);
}

// int adc_mins[ADC_COUNT] = {0, 77, 50, 35, 20, 0, 130, 0};
// int adc_mins[ADC_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0};

#define max(a, b) ((a) > (b) ? (a) : (b))

void adc_update()
{
    int i = 0, tmp = 0;
    while (++i < ADC_COUNT) {
        /* tmp = adc_filter(adcs[i]) - adc_mins[i];
        tmp = max(tmp, 0);
        adc_datas[i] =
            tmp / (ADC_MAX - adc_mins[i]) * ADC_NORMAL; */
        
        // TODO: ADC 归一化
        adc_datas[i] = adc_filter(adcs[i]) / ADC_MAX * ADC_NORMAL;
        // adc_datas[i] = adc_filter(adcs[i]);
    }
    adc_update_bias();
}

#undef max