#include "pid.h"

#include "adc.h"
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

#define PID_NEW(KP, KI, KD)       \
    {                             \
        (KP), (KI), (KD), 0, 0, 0 \
    }

pid_t pid_motor_l = PID_NEW(10, 0.5, -5),
      pid_motor_r = PID_NEW(10, 0.5, -5),
      pid_motor_adc = PID_NEW(80, 20, 50);

#undef PID_NEW

int pid_pwm_l = 0, pid_pwm_r = 0, pid_pwm_adc = 0;
bool pid_adc_enable = false;

// TODO: 拆分为单独的模块
void pid_motor(int target_l, int target_r)
{
    pid_pwm_adc = 0;
    if (pid_adc_enable) {
        pid_pwm_adc = pid(&pid_motor_adc, 0, adc_bias);
    }

    pid_pwm_l = pid(&pid_motor_l, target_l, encoder_l) + pid_pwm_adc;
    pid_pwm_r = pid(&pid_motor_r, target_r, encoder_r) - pid_pwm_adc;

    motor_pwm(pid_pwm_l, pid_pwm_r);
}