#include "button.h"

#define BUTTON_CASE(button_enum, BUTTON_PIN) \
    case button_enum:                        \
        if (BUTTON_PIN) {                    \
            delay_ms(20);                    \
            while (BUTTON_PIN) {             \
                result = true;               \
            }                                \
        }                                    \
        break

bool button_click(button_enum button)
{
    bool result = false;

    switch (button) {
        BUTTON_CASE(button_0, BUTTON_0);
        BUTTON_CASE(button_1, BUTTON_1);
        BUTTON_CASE(button_2, BUTTON_2);
        BUTTON_CASE(button_3, BUTTON_3);
    }

    return result;
}

#undef BUTTON_CASE
