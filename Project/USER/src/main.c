/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ790875685)
 * @version    		查看doc内version文件 版本说明
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32G12K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-12-18
 ********************************************************************************************************************/

#include "headfile.h"

#include "adc.h"
#include "button.h"
#include "encoder.h"
#include "motor.h"
#include "pid.h"
#include "switch.h"
// #include "hall.h"
// #include "tof.h"

/*
 * 系统频率，可查看board.h中的 FOSC 宏定义修改。
 * board.h文件中FOSC的值设置为0,则程序自动设置系统频率为33.1776MHZ
 * 在board_init中,已经将P54引脚设置为复位
 * 如果需要使用P54引脚,可以在board.c文件中的board_init()函数中删除SET_P54_RESRT即可
 */

// uint8 main_count = 0;

extern bool btn_3_click;
// extern int adc_bias_res;

#define ADC_K_IDX 3

void main()
{
    board_init(); // 初始化寄存器,勿删除此句代码。

    // ips114_init();
    // ips114_clear(WHITE);

    motor_init();
    encoder_init();
    adc_init_all();

    pit_timer_ms(TIM_1, 10);

    while (1) {
        if (btn_click(BTN_3)) {
            btn_3_click = !btn_3_click;
        }

        printf("%d, %d, %d, %d, %d, %d, %d\n",
               ADC_L1, ADC_L2, // ADC_L3,
               ADC_R1, ADC_R2, // ADC_R3,
               ADC_MF, ADC_MB, adc_bias);

        if (btn_click(BTN_1)) {
            // if (SWITCH_CHECK(0, 0, 0, 0)) {
            adc_k[ADC_K_IDX] += 10;
            // }
        } else if (btn_click(BTN_2)) {
            adc_k[ADC_K_IDX] -= 10;
        }

        // printf("%d\n", adc_bias);
        delay_ms(10);
    }
}