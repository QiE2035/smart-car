#include "tof.h"

// bool is_dl1a = false;

void tof_init()
{
    /* while (dl1a_init()) {
        printf("dl1a init faild!\n");
    } */
    while (dl1a_2_init()) {
        printf("dl1a_2 init faild!");
    }
}

void tof_update()
{
    // if (is_dl1a) {
    // dl1a_get_distance();
    // } else {
    dl1a_2_get_distance();
    // }
    // is_dl1a = !is_dl1a;
}