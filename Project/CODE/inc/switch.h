#ifndef __SWITCH_H
#define __SWITCH_H

// #include "bool.h"
#include "headfile.h"

/* #define SWITCH_1 !P75
#define SWITCH_2 !P76
#define SWITCH_3 !P50
#define SWITCH_4 !P51 */

// uint8 switch_data();

/* bool switch_check(int swich_1,
                  int swich_2,
                  int swich_3,
                  int swich_4); */

#define SWITCH_CHECK(swich_1, swich_2, swich_3, swich_4) \
    (!P75 == (swich_1) && !P76 == (swich_2) &&           \
     !P50 == (swich_3) && !P51 == (swich_4))

#endif // __SWITCH_H
