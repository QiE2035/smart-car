#ifndef __PID_H
#define __PID_H

#include "headfile.h"

typedef struct pid_t {
    float kp, ki, kd;
    int32 p, i, d;
} pid_t;

extern pid_t pid_motor_l,
    pid_motor_r,
    pid_motor_bias;

// int pid(pid_t *pid_param);

void pid_motor(int target_l, int target_r);

#endif // __PID_H
