#include "headfile.h"

#include "adc.h"
#include "button.h"
#include "encoder.h"
#include "hall.h"
#include "imu660ra.h"
#include "pid.h"
#include "tof.h"

car_enum car_state = CAR_STOP;

#define SPEED 200

uint16 count = 0, barrier_stage = 0;

#define car_stop()   pid_motor(0, 0)
#define turn_left()  pid_motor(0, SPEED)
#define turn_right() pid_motor(SPEED, 0)
#define normal_run() pid_motor(SPEED, SPEED)

bool barrier_next = true;

#define BARRIER_CASE_ENC(case_data, operation, case_encoder) \
    case case_data:                                          \
        if (encoder_int_check(case_encoder, case_encoder)) { \
            operation();                                     \
        } else {                                             \
            barrier_next = true;                             \
        }                                                    \
        break

#define BARRIER_CASE_YAW(case_data, operation, yaw_target) \
    case case_data:                                        \
        if (imu660ra_yaw yaw_target) {                     \
            operation();                                   \
        } else {                                           \
            barrier_next = true;                           \
        }                                                  \
        break

#define BARRIER_TURN 30

#define BARRIER_IO 1024
#define BARRIER_GO 1024

static void car_barrier()
{
    // 每次状态切换等待 1s
    if (barrier_next) {
        car_stop();
        if (count++ > 100) {
            count = 0;
            imu660ra_yaw = 0;
            encoder_int_clear();
            barrier_stage++;
            barrier_next = false;
        }
    } else {
        switch (barrier_stage) {
            BARRIER_CASE_YAW(1, turn_right, < BARRIER_TURN); // 右转，面向赛道外
            BARRIER_CASE_ENC(2, normal_run, BARRIER_IO);     // 直行，出赛道
            BARRIER_CASE_YAW(3, turn_left, > -BARRIER_TURN); // 左转，摆正
            BARRIER_CASE_ENC(4, normal_run, BARRIER_GO);     // 直行，走过障碍
            BARRIER_CASE_YAW(5, turn_left, > -BARRIER_TURN); // 左转，面向赛道
            BARRIER_CASE_ENC(6, normal_run, BARRIER_IO);     // 直行，进入赛道
            BARRIER_CASE_YAW(7, turn_right, < BARRIER_TURN); // 右转，摆正
            case 8:
                // 绕障完成，切回正常运行
                encoder_int_clear();
                barrier_stage = 0;
                barrier_next = true;
                imu660ra_yaw = 0;
                car_state = CAR_STOP; // TODO: CAR_RUN
                break;
        }
    }
}

#undef BARRIER_CASE

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

    // 冲出赛道和霍尔停车
    if (!has_adc || HALL) {
        car_state = CAR_STOP;
    } else if (tof_finish && tof_up <= 500) {
        pid_adc = false;
        car_state = CAR_BARRIER;
        barrier_stage = 0;
        barrier_next = true;
        tof_finish = 0;
    }

    // 延迟 1s 后摆正
    if (count > 100) {
        pid_adc = true;
        // 延迟 3s 后启动
        if (count > 300) {
            normal_run();
        } else {
            count++;
            car_stop();
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
    imu660ra_update();

    switch (car_state) {
        case CAR_STOP:
            pid_adc = false;
            // encoder_int_clear();
            count = 0;
            car_stop();
            break;
        case CAR_RUN:
            car_run();
            break;
        case CAR_BARRIER:
            car_barrier();
            break;
    }
}