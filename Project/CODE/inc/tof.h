#ifndef __TOF_H
#define __TOF_H

#include "headfile.h"

#include "bool.h"

#define tof_down dl1a_distance_mm
#define tof_up   dl1a_2_distance_mm

#define tof_finish (dl1a_2_finsh_flag /* && dl1a_finsh_flag */)

void tof_init();
void tof_update();

#endif // __TOF_H
