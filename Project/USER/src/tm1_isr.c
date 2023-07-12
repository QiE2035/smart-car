#include "headfile.h"

#include "button.h"
// #include "bool.h"
#include "encoder.h"
// #include "motor.h"
#include "pid.h"
// #include "tof.h"
#include "adc.h"
// #include "state.h"

bool button_3_click = false;

#define RUN_DISTANCE 1024

// uint8 count = 0;

void tm1_isr_callback()
{
    encoder_update();
    // tof_update();
    // adc_update();
    

    // if (button_3_click) {
        /* if (encoder_l_int >= RUN_DISTANCE ||
            encoder_r_int >= RUN_DISTANCE) {
            button_3_click = false;
            encoder_clear_int();
        } */
        // motor_pwm(3000, 3000);
        // pid_motor(300, 300);
    // } else {
        // motor_pwm(0, 0);
        // if (pid_motor_l.i > 0) { pid_motor_l.i = 0; }
        // if (pid_motor_r.i > 0) { pid_motor_r.i = 0; }
        // pid_motor(0, 0);
    // }
}