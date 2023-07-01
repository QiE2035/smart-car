#ifndef __IMU660RA_H
#define __IMU660RA_H

#include "headfile.h"

extern float acc_x, acc_y, acc_z,
    gyro_x, gyro_y, gyro_z;

void imu660ra_update();

#endif // __IMU660RA_H
