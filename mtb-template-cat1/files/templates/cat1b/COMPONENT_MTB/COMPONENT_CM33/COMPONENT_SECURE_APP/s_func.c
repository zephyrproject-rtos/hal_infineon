#include <stdio.h>
#include <arm_cmse.h>
#include "cy_pdl.h"
#include "cy_systick.h"
#include "cy_flash.h"
#include "cy_ms_ctl.h"
#include "partition_ARMCM33.h"
#include "partition_psc3.h"

/* Note: To test PIPE user needs to define this macro TEST_PIPE in makefile */
//#define TEST_PIPE     /* Enables pipe test code for testing purpose */

extern void config_ppc_secure_flash(void);
extern void config_ppc_nonsecure_flash(void);
void send_ipc_secure_msg(void);
void send_pipe_secure_msg(void);

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

cy_en_flashdrv_status_t __attribute__((cmse_nonsecure_entry)) secure_Flash_Init(bool refresh_enable) {
    Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_S_PC_VALUE);
    __DSB();
    config_ppc_secure_flash();
    cy_en_flashdrv_status_t flashStatus = Cy_Flash_Init(refresh_enable);
    config_ppc_nonsecure_flash();
    Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_NS_PC_VALUE);
    __DSB();
    return flashStatus;
}

cy_en_flashdrv_status_t __attribute__((cmse_nonsecure_entry)) secure_Flash_Erase_Row(uint32_t rowAddr) {

    Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_S_PC_VALUE);
     __DSB();
    config_ppc_secure_flash();
    cy_en_flashdrv_status_t flashStatus = Cy_Flash_EraseRow(rowAddr);
    config_ppc_nonsecure_flash();
    Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_NS_PC_VALUE);
    __DSB();
    return flashStatus;
}

cy_en_flashdrv_status_t __attribute__((cmse_nonsecure_entry)) secure_Flash_Write_Row(uint32_t rowAddr, const uint32_t* data) {
    Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_S_PC_VALUE);
    __DSB();
    config_ppc_secure_flash();
    cy_en_flashdrv_status_t flashStatus = Cy_Flash_WriteRow(rowAddr, data);
    config_ppc_nonsecure_flash();
    Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_NS_PC_VALUE);
    __DSB();
    return flashStatus;
}

void __attribute__((cmse_nonsecure_entry)) secure_ipc_entry(void) {
    /* Changing the PC value to secure. */
    Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_S_PC_VALUE);

    #ifdef TEST_PIPE
    send_pipe_secure_msg();
    #else
    send_ipc_secure_msg();
    #endif

    /* Changing the PC value to non-secure. */
    Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_NS_PC_VALUE);
}
