#include "switch.h"

uint8 switch_data()
{
    uint8 dat = 0;

    dat += SWITCH_1;
    dat = dat << 1;

    dat += SWITCH_2;

    return dat;
}