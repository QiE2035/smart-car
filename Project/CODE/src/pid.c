#include "pid.h"

#include "encoder.h"
#include "motor.h"

int pid(pid_t *pid_data, int target, int current)
{
    int p = target - current;

    pid_data->i += p;
    pid_data->d = p - pid_data->p;
    pid_data->p = p;

    return pid_data->kp * pid_data->p +
           pid_data->ki * pid_data->i +
           pid_data->kd * pid_data->d;
}

pid_t pid_motor_l    = {0, 0, 0, 0, 0, 0},
      pid_motor_r    = {15, 0, 0, 0, 0, 0},
      pid_motor_bias = {0, 0, 0, 0, 0, 0};

// TODO: 拆分为单独的模块
void pid_motor(int target_l, int target_r)
{
    int bias = pid(&pid_motor_bias, (target_l - target_r), (encoder_l - encoder_r));

    target_l = pid(&pid_motor_l, target_l, encoder_l) + bias;
    target_r = pid(&pid_motor_r, target_r, encoder_r) - bias;

    motor_pwm(target_l, target_r);
}