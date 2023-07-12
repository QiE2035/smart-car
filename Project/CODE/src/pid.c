#include "pid.h"

#include "encoder.h"
#include "motor.h"

static int pid_i_limit(int input)
{
    if (input > 0) {
        if (input > PID_I_LIMIT) {
            return PID_I_LIMIT;
        }
        return input;
    } else {
        if (input < -PID_I_LIMIT) {
            return -PID_I_LIMIT;
        }
        return input;
    }
}

static int pid(pid_t *pid_data, int target, int current)
{
    int p = target - current;

    if ((target <= 0 && pid_data->i > 0) ||
        (target >= 0 && pid_data->i < 0)) {
        pid_data->i = 0;
    }

    pid_data->i += p;
    pid_data->d = p - pid_data->p;
    pid_data->p = p;

    pid_data->i = pid_i_limit(pid_data->i);

    return pid_data->kp * pid_data->p +
           pid_data->ki * pid_data->i +
           pid_data->kd * pid_data->d;
}

pid_t pid_motor_l    = {10, 0.5, -5, 0, 0, 0},
      pid_motor_r    = {10, 0.5, -5, 0, 0, 0},
      pid_motor_bias = {0, 0, 0, 0, 0, 0};

int pwm_l = 0, pwm_r = 0;

// TODO: 拆分为单独的模块
void pid_motor(int target_l, int target_r)
{
    int bias = pid(&pid_motor_bias,
                   (target_l - target_r),
                   (encoder_l - encoder_r));

    pwm_l = pid(&pid_motor_l, target_l /* + bias */, encoder_l);
    pwm_r = pid(&pid_motor_r, target_r /* - bias */, encoder_r);

    motor_pwm(pwm_l, pwm_r);
}