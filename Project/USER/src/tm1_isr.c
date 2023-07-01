#include "headfile.h"

#include "encoder.h"
#include "pid.h"
#include "motor.h"
#include "button.h"
#include "beep.h"

bool button_3_click = false;

uint8 count = 0;

void tm1_isr_callback()
{
    encoder_update();

    if (button_is_click(button_3)) {
        button_3_click = !button_3_click;
    }

    if (button_3_click) {
        pid_motor(0, 100);
    } else {
        pid_motor(0, 0);
    }

    if (count++ % 100 == 0) {
        ips114_showint16(0, 0, encoder_l);
        ips114_showint16(0, 1, encoder_r);
        ips114_showint16(0, 2, (encoder_l - encoder_r));
    }
}