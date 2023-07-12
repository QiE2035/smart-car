#include "tof.h"
#include "bool.h"

bool is_dl1a_2 = false;

void tof_update()
{
    // while (!dl1a_finsh_flag /*  || !dl1a_2_finsh_flag */) {
    if (is_dl1a_2) {
        dl1a_get_distance();
    } else {
        dl1a_2_get_distance();
    }
    is_dl1a_2 = !is_dl1a_2;
    // dl1a_2_get_distance();
    // }
    // dl1a_finsh_flag /* = dl1a_2_finsh_flag */ = 0;
}