#ifndef __PID_H
#define __PID_H

#include "headfile.h"
#include "bool.h"

#define PID_I_LIMIT 10240

typedef struct pid_t {
    float kp, ki, kd;
    int p, i, d;
} pid_t;

extern pid_t pid_motor_l,
    pid_motor_r,
    pid_motor_adc;

extern int pid_pwm_l, pid_pwm_r , pid_pwm_adc;
extern bool pid_adc;

void pid_motor(int target_l, int target_r);
// void pid_adc();

#endif // __PID_H
