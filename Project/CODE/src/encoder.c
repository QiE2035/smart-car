#include "encoder.h"

void encoder_init()
{
    ctimer_count_init(ENCODER_L);
    ctimer_count_init(ENCODER_R);
}

/* int encoder_read(encoder_t encoder)
{
    int encoder_data = 0;

    encoder_data = ctimer_count_read(encoder);
    // TO_DO: 左右判定优化
    if ((encoder == ENCODER_L && ENCODER_L_DIR != 1) ||
        (encoder == ENCODER_R && ENCODER_R_DIR == 1)) {
        encoder_data *= -1;
    }
    ctimer_count_clean(encoder);

    return encoder_data;
} */

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
