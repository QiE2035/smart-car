#ifndef __BUTTON_H
#define __BUTTON_H

#include "headfile.h"

#define BUTTON_0 !P70
#define BUTTON_1 !P71
#define BUTTON_2 !P72
#define BUTTON_3 !P73

// #define BUTTON_PUSH  0

typedef enum button_enum {
    button_0,
    button_1,
    button_2,
    button_3,
} button_enum;

typedef enum bool {
    false,
    true
} bool;

bool button_is_click(button_enum button);

#endif // __BUTTON_H
