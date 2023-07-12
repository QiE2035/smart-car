#include "encoder.h"

void encoder_init()
{
    ctimer_count_init(ENCODER_L);
    ctimer_count_init(ENCODER_R);
}

int encoder_l = 0, encoder_r = 0,
    encoder_l_int = 0, encoder_r_int = 0;

void encoder_update()
{
    encoder_l = ctimer_count_read(ENCODER_L);
    if (ENCODER_L_DIR != 1) {
        encoder_l *= -1;
    }
    ctimer_count_clean(ENCODER_L);
    encoder_l_int += encoder_l;

    encoder_r = ctimer_count_read(ENCODER_R);
    if (ENCODER_R_DIR == 1) {
        encoder_r *= -1;
    }
    ctimer_count_clean(ENCODER_R);
    encoder_r_int += encoder_r;
}
