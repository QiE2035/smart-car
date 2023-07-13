#include "motor.h"

void motor_init()
{
    // DisableGlobalIRQ();
    gpio_mode(MOTOR_L, GPO_PP);
    gpio_mode(MOTOR_R, GPO_PP);

    pwm_init(MOTOR_PWM_L, MOTOR_PWM_FREQ, 0);
    pwm_init(MOTOR_PWM_R, MOTOR_PWM_FREQ, 0);
    // EnableGlobalIRQ();
}

// void motor_left()
// {
//     MOTOR_DIR_L = MOTOR_FORWARD;
//     MOTOR_DIR_R = MOTOR_REVERSE;
// }

// void motor_run()
// {
//     MOTOR_DIR_L = MOTOR_FORWARD;
//     MOTOR_DIR_R = MOTOR_FORWARD;
// }

void motor_pwm(int pwm_l, int pwm_r)
{
    if (pwm_l < 0) {
        pwm_l = -pwm_l;

        MOTOR_DIR_L = MOTOR_REVERSE;
    } else {
        MOTOR_DIR_L = MOTOR_FORWARD;
    }
    pwm_l = min(pwm_l, MOTOR_PWM_MAX);
    pwm_duty(MOTOR_PWM_L, pwm_l);

    if (pwm_r < 0) {
        pwm_r = -pwm_r;

        MOTOR_DIR_R = MOTOR_REVERSE;
    } else {
        MOTOR_DIR_R = MOTOR_FORWARD;
    }
    pwm_r = min(pwm_r, MOTOR_PWM_MAX);
    pwm_duty(MOTOR_PWM_R, pwm_r);
}