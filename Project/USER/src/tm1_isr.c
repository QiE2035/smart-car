#include "headfile.h"

#include "encoder.h"
#include "pid.h"
#include "motor.h"
#include "button.h"

bool button_3_click = false;

uint8 count = 0;

void tm1_isr_callback()
{
    encoder_update();

    if (button_3_click) {
        pid_motor(200, 200);
    } else {
        // motor_pwm(0, 0);
        // if (pid_motor_l.i > 0) { pid_motor_l.i = 0; }
        // if (pid_motor_r.i > 0) { pid_motor_r.i = 0; }
        pid_motor(0, 0);
    }
    // 中断里不要用屏幕, 会炸!!!
    /* if (count++ % 10 == 0) {
        ips114_showint16(0, 0, encoder_l);
        ips114_showint16(0, 1, encoder_r);
        ips114_showint16(0, 2, (encoder_l - encoder_r));
        ips114_showint16(0, 2, pid_motor_l.kp * 10);
        ips114_showint16(0, 3, pid_motor_l.ki);
        ips114_showint16(0, 4, pid_motor_l.kd);
    } */
}