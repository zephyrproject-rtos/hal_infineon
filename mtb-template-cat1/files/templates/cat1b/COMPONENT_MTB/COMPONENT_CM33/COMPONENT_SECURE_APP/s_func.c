#include <stdio.h>
#include <arm_cmse.h>
#include "cy_systick.h"

int __attribute__((cmse_nonsecure_entry)) entry1(int x) {
    __asm volatile("bkpt #99");
    //printf("Secure: %s\n",__FUNCTION__);
    x++;
    return x;
}

void __attribute__((cmse_nonsecure_entry)) secure_systick_entry(bool enable) {
    if(enable)
    {
        Cy_NsSysTick_Enable();
    }
    else
    {
        Cy_NsSysTick_Disable();
    }
}
