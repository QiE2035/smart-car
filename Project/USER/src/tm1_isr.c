#include "headfile.h"

#include "button.h"
// #include "bool.h"
#include "encoder.h"
// #include "motor.h"
#include "adc.h"
#include "hall.h"
#include "pid.h"
#include "tof.h"
// #include "state.h"

bool btn_3_click = false;

#define RUN_DISTANCE 40960

enum state_enum {
    STATE_STOP,
    STATE_OUT,
    // STATE_TURN,
    STATE_RUN,
    STATE_BARRIER,
    STATE_IN,
} state = STATE_STOP;

/* enum barrier_enum {
    BARRIER_START_R,
    BARRIER_START_L,
    BARRIER_RUN,
    BARRIER_END_L,
    BARRIER_END_R,
} barrier = BARRIER_START_R; */

// uint8 count = 0;

/* static */ void car_barrier()
{
    if (encoder_int_check(0, 0)) {
        // 右转
        pid_motor(200, 0);
    } else if (encoder_int_check(0, 0)) {
        // 左转
        pid_motor(0, 200);
    } else if (encoder_int_check(0, 0)) {
        // 直行
        pid_motor(2, 200);
    } else if (encoder_int_check(0, 0)) {
        // 左转
        pid_motor(0, 200);
    } else if (encoder_int_check(0, 0)) {
        // 右转
        pid_motor(200, 0);
    } else if (encoder_int_check(0, 0)) {
        // 绕障完成，切回正常运行
        state = STATE_RUN;
    }
}

// int adc_bias_res = 0;
int count = 0;

void tm1_isr_callback()
{
    encoder_update();
    // tof_update();
    adc_update();

    if (btn_3_click) {
        if (encoder_int_check(RUN_DISTANCE, RUN_DISTANCE)) {
            btn_3_click = false;
            encoder_int_clear();
            count = 0;
        }
        if (count++ >= 100) {
            pid_motor(200 - adc_bias, 200 + adc_bias);
            // pid_motor(200 /* - adc_bias */, 200 /* + adc_bias */);
        }
    } else {
        pid_motor(0, 0);
    }

    /* switch (state) {
        case STATE_STOP:
            pid_motor(0, 0);
            break;
        case STATE_RUN:
            car_run();
            break;
    } */
}