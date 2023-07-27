#include <stdio.h>
#include <arm_cmse.h>
#include "cy_pdl.h"
#include "partition_ARMCM33.h"
#include "cy_syspm_pdcm.h"
#include "partition_boy2.h"

/* memory addresses for cm33 */
#define CM33_SP_STORE               SRAM0_NS_LOAD_ADDR          //0x3407ffe0
#define CM33_RESET_HANDLER_STORE    (SRAM0_NS_LOAD_ADDR + 4)    //0x3407ffe4

/* Entry point for second secure image */
typedef void (*funcptr_void) (void) __attribute__((cmse_nonsecure_call));

void SystemInitStage2(void);
//void config_ppc(void);

__WEAK void SecureWeakFunc(void)
{
     /* Empty weak function.
     */
}

void test_stub_handler (void) {
    static int a;
    a++;
}


int main(void)
{
    funcptr_void NonSecure_ResetHandler;
    uint32_t ns_stack;


//    TZ_SAU_Setup();

    __enable_irq();

    // Enable below piece of code to test APIs to be called from ROT

    //config_ppc();

    SecureWeakFunc();

    ns_stack = (uint32_t)(*((uint32_t*)CM33_SP_STORE));
    NonSecure_ResetHandler = (funcptr_void)(*((uint32_t*)CM33_RESET_HANDLER_STORE));
    __TZ_set_MSP_NS(ns_stack);

    /* Start non-secure application */
    NonSecure_ResetHandler();

    /* Non-secure software does not return, this code is not executed */
    while(true)
    {
    }
}

/*void config_ppc(void)
{

}*/



