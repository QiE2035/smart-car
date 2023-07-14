#ifndef __ENCODER_H
#define __ENCODER_H

#include "headfile.h"

#define ENCODER_L CTIM0_P34
#define ENCODER_R CTIM3_P04

#define ENCODER_DIR_L P35
#define ENCODER_DIR_R P53

// 编码器分辨率
#define ENCODER_RES 1024

extern int encoder_l, encoder_r;
extern int32 encoder_int_l, encoder_int_r;

void encoder_init();
void encoder_update();

#define encoder_int_clear() \
    (encoder_int_l = encoder_int_r = 0)

#define encoder_arrive(target) \
    (encoder_int_l < target && encoder_int_r < target)

#endif // __ENCODER_H
