#ifndef __IMU660RA_H
#define __IMU660RA_H

#include "headfile.h"

/* extern float acc_x, acc_y, acc_z,
    gyro_x, gyro_y, gyro_z; */

extern float imu660ra_yaw;

#define TIMER_TIME 10

void imu660ra_update();
// float imu660ra_yaw();

#endif // __IMU660RA_H
