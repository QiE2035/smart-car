#include "button.h"

#define BUTTON_CASE(num)           \
    case BTN_##num:                \
        if (BUTTON_##num) {        \
            delay_ms(20);          \
            while (BUTTON_##num) { \
                result = true;     \
            }                      \
        }                          \
        break

bool btn_click(btn_enum button)
{
    bool result = false;

    switch (button) {
        BUTTON_CASE(0);
        BUTTON_CASE(1);
        BUTTON_CASE(2);
        BUTTON_CASE(3);
    }

    return result;
}

#undef BUTTON_CASE
