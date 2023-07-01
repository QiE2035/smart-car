#ifndef __MOTOR_H
#define __MOTOR_H

#include "headfile.h"

#define MOTOR_L        P6_6
#define MOTOR_R        P6_2

#define MOTOR_DIR_L    P66
#define MOTOR_DIR_R    P62

#define MOTOR_FORWARD  1
#define MOTOR_REVERSE  (1 - MOTOR_FORWARD)

#define MOTOR_PWM_L    PWMA_CH3P_P64
#define MOTOR_PWM_R    PWMA_CH1P_P60
#define MOTOR_PWM_MAX  3000

#define MOTOR_PWM_FREQ 17000

// TODO: 拆分为单独的模块
#define min(a, b) ((a) < (b) ? (a) : (b))

void motor_init();
// void motor_left();
// void motor_run();
void motor_pwm(int pwm_l, int pwm_r);

#endif // __MOTOR_H