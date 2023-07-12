#include "switch.h"

/* uint8 switch_data()
{
    uint8 dat = 0;

    dat += SWITCH_1;
    dat = dat << 1;

    dat += SWITCH_2;

    return dat;
} */

bool switch_check(int swich_1,
                  int swich_2,
                  int swich_3,
                  int swich_4)
{
    return SWITCH_1 == swich_1 &&
           SWITCH_2 == swich_2 &&
           SWITCH_3 == swich_3 &&
           SWITCH_4 == swich_4;
}