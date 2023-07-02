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

#include "button.h"
#include "encoder.h"
#include "motor.h"
#include "pid.h"
#include "switch.h"
/*
 * 系统频率，可查看board.h中的 FOSC 宏定义修改。
 * board.h文件中FOSC的值设置为0,则程序自动设置系统频率为33.1776MHZ
 * 在board_init中,已经将P54引脚设置为复位
 * 如果需要使用P54引脚,可以在board.c文件中的board_init()函数中删除SET_P54_RESRT即可
 */

uint8 main_count = 0;

extern bool button_3_click;

void main()
{
    board_init(); // 初始化寄存器,勿删除此句代码。

    ips114_init();
    ips114_clear(WHITE);

    // wireless_uart_init();

    motor_init();
    encoder_init();

    pit_timer_ms(TIM_1, 10);

    // 此处编写用户代码(例如：外设初始化代码等)

    // motor_pwm(1000, 1000);

    while (1) {
        printf("%d, %d, %d\n", encoder_l, encoder_r, (encoder_l - encoder_r));

        if (main_count++ % 10 == 0) {
            ips114_showint16(0, 0, encoder_l);
            ips114_showint16(0, 1, encoder_r);
            ips114_showint16(0, 2, (encoder_l - encoder_r));
            ips114_showint16(0, 3, pid_motor_bias.kp * 10);
            ips114_showint16(0, 4, pid_motor_bias.ki * 10);
            ips114_showint16(0, 5, pid_motor_bias.kd * 10);
        }

        if (button_is_click(button_2)) {
            switch (switch_data()) {
                case 0:
                    pid_motor_bias.kp += 0.1;
                    break;
                case 1:
                    pid_motor_bias.ki += 0.1;
                    break;
                case 3:
                    pid_motor_bias.kd += 0.1;
            }
        }
        if (button_is_click(button_1)) {
            switch (switch_data()) {
                case 0:
                    pid_motor_bias.kp -= 0.1;
                    break;
                case 1:
                    pid_motor_bias.ki -= 0.1;
                    break;
                case 3:
                    pid_motor_bias.kd -= 0.1;
            }
        }
        if (button_is_click(button_3)) {
            button_3_click = !button_3_click;
        }

        delay_ms(10);
    }
}