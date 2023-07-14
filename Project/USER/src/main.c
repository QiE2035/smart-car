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
#include "imu660ra.h"
#include "motor.h"
#include "pid.h"
#include "switch.h"
#include "tof.h"

/*
 * 系统频率，可查看board.h中的 FOSC 宏定义修改。
 * board.h文件中FOSC的值设置为0,则程序自动设置系统频率为33.1776MHZ
 * 在board_init中,已经将P54引脚设置为复位
 * 如果需要使用P54引脚,可以在board.c文件中的board_init()函数中删除SET_P54_RESRT即可
 */

// #define ADC_K_IDX 1

void btn_fun()
{
    if (btn_click(BTN_3)) {
        delay_ms(3000);
        car_state = CAR_OUT;
    }

    /* if (btn_click(BTN_1)) {
        if (SWITCH_CHECK(0, 0, 0, 0)) {
            pid_motor_adc.kp += 1;
        } else if (SWITCH_CHECK(0, 0, 0, 1)) {
            pid_motor_adc.ki += 1;
        } else if (SWITCH_CHECK(0, 0, 1, 1)) {
            pid_motor_adc.kd += 1;
        }
    } else if (btn_click(BTN_2)) {
        if (SWITCH_CHECK(0, 0, 0, 0)) {
            pid_motor_adc.kp -= 1;
        } else if (SWITCH_CHECK(0, 0, 0, 1)) {
            pid_motor_adc.ki -= 1;
        } else if (SWITCH_CHECK(0, 0, 1, 1)) {
            pid_motor_adc.kd -= 1;
        }
    } */

    if (btn_click(BTN_0)) {
        encoder_int_clear();
    }
}

extern int barrier_stage;
extern int count;

void main()
{
    board_init(); // 初始化寄存器,勿删除此句代码。

    // ips114_init();
    // ips114_clear(WHITE);

    tof_init();
    motor_init();
    encoder_init();
    adc_init_all();
    while (imu660ra_init()) {
        printf("imu660ra_init faild!\n");
    };

    pit_timer_ms(TIM_1, 10);

    while (1) {

        /* printf("%d, %d, %d, %d, %d, %d, %d\n",
               ADC_L1, ADC_R1, // ADC_L3,
               ADC_L2, ADC_R2, // ADC_R3,
               ADC_MF, ADC_MB, adc_bias); */

        btn_fun();

        /* ips114_showint32(0, 1, encoder_int_l, 10);
        ips114_showint32(0, 2, encoder_int_r, 10);

        if (tof_finish) {
            ips114_showuint16(0, 3, tof_up);
            tof_reset();
        } */

        /*  printf("%d, %f, %f, %f, %d\n",
                adc_bias, pid_motor_adc.kp,
                pid_motor_adc.ki, pid_motor_adc.kd,
                pid_pwm_adc); */

        // printf("%f, %d\n",
        //        imu660ra_yaw, barrier_stage);

        /* printf("%d, %d, %d, %d, %d, %d\n",
               encoder_l, encoder_r,
               encoder_int_l, encoder_int_r,
               barrier_stage, count); */

        delay_ms(10);
    }
}