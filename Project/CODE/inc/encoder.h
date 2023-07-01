#ifndef __ENCODER_H
#define __ENCODER_H

#include "headfile.h"

#define ENCODER_L_DIR P35
#define ENCODER_R_DIR P53

#define ENCODER_L     CTIM0_P34
#define ENCODER_R     CTIM3_P04

// 编码器分辨率
#define ENCODER_RES 1024

// typedef CTIMN_enum encoder_t;

extern int encoder_l, encoder_r,
    encoder_l_int, encoder_r_int;

void encoder_init();
// #define encoder_init(encoder)
//     ctimer_count_init(encoder)
// int encoder_read(encoder_t encoder);
void encoder_update();

#define encoder_clear_int() \
    encoder_l_int = encoder_r_int = 0

#endif // __ENCODER_H
