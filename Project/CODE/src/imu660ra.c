#include "imu660ra.h"

float acc_x = 0, acc_y = 0, acc_z = 0,
      gyro_x = 0, gyro_y = 0, gyro_z = 0;

void imu660ra_update()
{
    imu660ra_get_acc();
    imu660ra_get_gyro();

    acc_x = imu660ra_acc_transition(imu660ra_acc_x);
    acc_y = imu660ra_acc_transition(imu660ra_acc_y);
    acc_z = imu660ra_acc_transition(imu660ra_acc_z);

    gyro_x = imu660ra_gyro_transition(imu660ra_gyro_x);
    gyro_y = imu660ra_gyro_transition(imu660ra_gyro_y);
    gyro_z = imu660ra_gyro_transition(imu660ra_gyro_z);
}