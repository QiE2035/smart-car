#ifndef __PID_H
#define __PID_H

#include "headfile.h"

#define PID_I_LIMIT 10240

typedef struct pid_t {
    float kp, ki, kd;
    int p, i, d;
} pid_t;

extern pid_t pid_motor_l,
    pid_motor_r,
    pid_motor_bias;

extern int pid_pwm_l, pid_pwm_r;

// int pid(pid_t *pid_param);

void pid_motor(int target_l, int target_r);

#endif // __PID_H
