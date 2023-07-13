#include "headfile.h"

#include "adc.h"
#include "button.h"
#include "encoder.h"
#include "hall.h"
#include "pid.h"
#include "tof.h"

state_enum car_state = STATE_STOP;

#define SPEED 200

/* enum barrier_enum {
    BARRIER_START_R,
    BARRIER_START_L,
    BARRIER_RUN,
    BARRIER_END_L,
    BARRIER_END_R,
} barrier = BARRIER_START_R; */

int count = 0;

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
        car_state = STATE_RUN;
    }
}

static void car_run()
{
    int i = 0;
    bool has_adc = false;

    // 冲出赛道检测
    while (++i < ADC_COUNT) {
        if (adc_datas[i] >= 20) {
            has_adc = true;
            break;
        }
    }
    // 冲出赛道停车
    if (!has_adc) {
        car_state = STATE_STOP;
    } /* else if (tof_up <= 500) {
        car_state = STATE_BARRIER;
    } */

    // 延迟 1s 后摆正
    if (count >= 100) {
        pid_adc_enable = true;
        // 延迟 3s 后启动
        if (count >= 300) {
            pid_motor(SPEED, SPEED);
        } else {
            count++;
            pid_motor(0, 0);
        }
    } else {
        count++;
    }
}

void tm1_isr_callback()
{
    encoder_update();
    tof_update();
    adc_update();

    switch (car_state) {
        case STATE_STOP:
            pid_adc_enable = false;
            // encoder_int_clear();
            count = 0;
            pid_motor(0, 0);
            break;
        case STATE_RUN:
            car_run();
            break;
        case STATE_BARRIER:

            break;
    }
}