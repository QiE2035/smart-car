#if !defined(__BEEP_H)
#define __BEEP_H

#include "headfile.h"

#define BEEP     P67
#define BEEP_PIN P6_7

// void beep_init();

#define beep_init() \
    gpio_mode(BEEP_PIN, GPO_PP)

#endif // __BEEP_H
