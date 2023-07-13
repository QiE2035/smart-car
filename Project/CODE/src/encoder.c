#include "encoder.h"

void encoder_init()
{
    ctimer_count_init(ENCODER_L);
    ctimer_count_init(ENCODER_R);
}

int encoder_l = 0, encoder_r = 0,
    encoder_int_l = 0, encoder_int_r = 0;

void encoder_update()
{
    encoder_l = ctimer_count_read(ENCODER_L);
    if (ENCODER_DIR_L != 1) {
        encoder_l *= -1;
    }
    ctimer_count_clean(ENCODER_L);
    encoder_int_l += encoder_l;

    encoder_r = ctimer_count_read(ENCODER_R);
    if (ENCODER_DIR_R == 1) {
        encoder_r *= -1;
    }
    ctimer_count_clean(ENCODER_R);
    encoder_int_r += encoder_r;
}
