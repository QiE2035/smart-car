#include "tof.h"

uint16 tof_distance()
{
    dl1a_get_distance();
    while (!dl1a_finsh_flag) {}
    dl1a_finsh_flag = 0;
    return dl1a_distance_mm;
}