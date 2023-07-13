#ifndef __BUTTON_H
#define __BUTTON_H

#include "bool.h"
#include "headfile.h"

#define BUTTON_0 !P70
#define BUTTON_1 !P71
#define BUTTON_2 !P72
#define BUTTON_3 !P73

// #define BUTTON_PUSH  0

typedef enum btn_enum {
    BTN_0,
    BTN_1,
    BTN_2,
    BTN_3,
} btn_enum;

bool btn_click(btn_enum button);

#endif // __BUTTON_H
