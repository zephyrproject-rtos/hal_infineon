#include <stdio.h>
#include <arm_cmse.h>
#include "cy_pdl.h"
#include "partition_ARMCM33.h"
#include "partition_psc3.h"
#include "cy_mpc.h"
#include "cy_ppc.h"
#include "cy_ms_ctl.h"


/* memory addresses for cm33 */
#define CM33_SP_STORE               NS_BOOT_START //GET_ALIAS_ADDRESS(SRAM0_NS_CBUS_CODE_START) //0x3400_8000
#define CM33_RESET_HANDLER_STORE    (NS_BOOT_START + 4)//(GET_ALIAS_ADDRESS(SRAM0_NS_CBUS_CODE_START) + 4)   //0x3400_8004


/* Entry point for second secure image */
typedef void (*funcptr_void) (void) __attribute__((cmse_nonsecure_call));

void SystemInitStage2(void);
void config_mpc(void);
void config_ppc(void);
void config_ppc_secure_flash(void);
void config_ppc_nonsecure_flash(void);
cy_en_ms_ctl_status_t config_set_cm33_ns_pc(void);
extern void ipc_cm33_s_isr(void);
extern int config_ipc(void);

cy_stc_ppc_init_t ppcInit;
cy_stc_ppc_attribute_t ppcAttribute;
cy_stc_ppc_pc_mask_t pcMaskConfig;


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

#ifndef NORMAL_PROVISIONED_LCS
    /* configure MPC */
    config_mpc();
#endif

    TZ_SAU_Setup();

    config_ipc();

    __enable_irq();

    // Enable below piece of code to test APIs to be called from ROT

    SecureWeakFunc();

    ns_stack = (uint32_t)(*((uint32_t*)CM33_SP_STORE));
    NonSecure_ResetHandler = (funcptr_void)(*((uint32_t*)CM33_RESET_HANDLER_STORE));
    __TZ_set_MSP_NS(ns_stack);

    /* Configure PPC for CM33 non-secure access */
    config_ppc();

#ifndef NORMAL_PROVISIONED_LCS
    config_set_cm33_ns_pc();
#else
    Cy_Ms_Ctl_SetSavedPC(CPUSS_MS_ID_CM33_0, CM33_NS_PC_VALUE);
    Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_NS_PC_VALUE);
#endif

    /* Start non-secure application */
    NonSecure_ResetHandler();

    /* Non-secure software does not return, this code is not executed */
    while(true)
    {
    }
}


void config_mpc(void)
{
    cy_stc_mpc_rot_cfg_t rotConfig;
    cy_en_mpc_status_t mpcStatus;

    rotConfig.regionSize = CY_MPC_SIZE_2KB;
    rotConfig.secure = CY_MPC_NON_SECURE;
    rotConfig.access = CY_MPC_ACCESS_RW;
    rotConfig.pc = CY_MPC_PC_0;

    /** SRAM0 configurations */
    rotConfig.addrOffset = SRAM0_NS_OFFSET;
    rotConfig.size = SRAM0_NS_SIZE;
    mpcStatus = Cy_Mpc_ConfigRotMpcStruct((MPC_Type*)RAMC0_MPC0, &rotConfig);
    if (mpcStatus != CY_MPC_SUCCESS) {
        while(1);
    }

    rotConfig.pc = CY_MPC_PC_1;
    mpcStatus = Cy_Mpc_ConfigRotMpcStruct((MPC_Type*)RAMC0_MPC0, &rotConfig);
    if (mpcStatus != CY_MPC_SUCCESS) {
        while(1);
    }

    /** shared memory configurations */
    rotConfig.pc = CY_MPC_PC_1;
    rotConfig.addrOffset = SRAM0_SHM_OFFSET;
    rotConfig.size = SRAM0_SHM_SIZE;
    mpcStatus = Cy_Mpc_ConfigRotMpcStruct((MPC_Type*)RAMC0_MPC0, &rotConfig);
    if (mpcStatus != CY_MPC_SUCCESS) {
        while(1);
    }

    /** Internal flash config */
    rotConfig.regionSize = CY_MPC_SIZE_2KB;
    rotConfig.secure = CY_MPC_NON_SECURE;
    rotConfig.access = CY_MPC_ACCESS_RW;
    rotConfig.pc = CY_MPC_PC_0;
    rotConfig.addrOffset = FLASH_NS_OFFSET;
    rotConfig.size = FLASH_NS_SIZE;

    mpcStatus = Cy_Mpc_ConfigRotMpcStruct((MPC_Type*)FLASHC_MPC0, &rotConfig);
    if (mpcStatus != CY_MPC_SUCCESS) {
        while(1);
    }

    rotConfig.pc = CY_MPC_PC_1;
    mpcStatus = Cy_Mpc_ConfigRotMpcStruct((MPC_Type*)FLASHC_MPC0, &rotConfig);
    if (mpcStatus != CY_MPC_SUCCESS) {
        while(1);
    }
}

void config_ppc_secure_flash(void)
{
    PPC_Type* ppcPtr;
    cy_en_ppc_status_t ppcStatus;

    /* Configure PPC0 for CM33 access */
    ppcPtr = PPC;

    ppcAttribute.secAttribute = CY_PPC_SECURE;
    ppcAttribute.secPrivAttribute = CY_PPC_SEC_NONPRIV;
    ppcAttribute.nsPrivAttribute = CY_PPC_NON_SEC_NONPRIV;

    //17 - 17 This is required for boot rom to access flash in secure mode.
    ppcAttribute.startRegion = PROT_CPUSS;
    ppcAttribute.endRegion = PROT_CPUSS;
    ppcStatus = Cy_Ppc_ConfigAttrib(ppcPtr, &ppcAttribute);
    if (ppcStatus != CY_PPC_SUCCESS) {
        while(true){
        }
    }
}

void config_ppc_nonsecure_flash(void)
{
    PPC_Type* ppcPtr;
    cy_en_ppc_status_t ppcStatus;

    /* Configure PPC0 for CM33 access */
    ppcPtr = PPC;

    ppcAttribute.secAttribute = CY_PPC_NON_SECURE;
    ppcAttribute.secPrivAttribute = CY_PPC_SEC_NONPRIV;
    ppcAttribute.nsPrivAttribute = CY_PPC_NON_SEC_NONPRIV;

    //17 - 17 This is required for boot rom to access flash in secure mode.
    ppcAttribute.startRegion = PROT_CPUSS;
    ppcAttribute.endRegion = PROT_CPUSS;
    ppcStatus = Cy_Ppc_ConfigAttrib(ppcPtr, &ppcAttribute);
    if (ppcStatus != CY_PPC_SUCCESS) {
        while(true){
        }
    }
}

void config_ppc(void)
{
    PPC_Type* ppcPtr;
    cy_en_ppc_status_t ppcStatus;

    /* Configure PPC0 for CM33 access */
    ppcPtr = PPC;

    // Initialize PPC
    ppcInit.respConfig = CY_PPC_BUS_ERR;
    ppcStatus = Cy_Ppc_InitPpc(ppcPtr, &ppcInit);
    if (ppcStatus != CY_PPC_SUCCESS) {
        while(true){
        }
    }

    ppcAttribute.secAttribute = CY_PPC_NON_SECURE;
    ppcAttribute.secPrivAttribute = CY_PPC_SEC_NONPRIV;
    ppcAttribute.nsPrivAttribute = CY_PPC_NON_SEC_NONPRIV;

    // Need to enable following  regions
    //10,
    //39 -149
    //0,7

    //0x00000010u
    ppcAttribute.startRegion = PROT_PERI_PCLK0_MAIN;
    ppcAttribute.endRegion = PROT_PERI_PCLK0_MAIN;
    ppcStatus = Cy_Ppc_ConfigAttrib(ppcPtr, &ppcAttribute);
    if (ppcStatus != CY_PPC_SUCCESS) {
        while(true){
        }
    }

    //17 - 20
    ppcAttribute.startRegion = PROT_CPUSS;
    ppcAttribute.endRegion = PROT_RAMC0_RAM_PWR;
    ppcStatus = Cy_Ppc_ConfigAttrib(ppcPtr, &ppcAttribute);
    if (ppcStatus != CY_PPC_SUCCESS) {
        while(true){
        }
    }

    //39 - 39
    ppcAttribute.startRegion = PROT_MXCM33_CM33;
    ppcAttribute.endRegion = PROT_MXCM33_CM33;
    ppcStatus = Cy_Ppc_ConfigAttrib(ppcPtr, &ppcAttribute);
    if (ppcStatus != CY_PPC_SUCCESS) {
        while(true){
        }
    }

    //43 - 86
    ppcAttribute.startRegion = PROT_MXCM33_CM33_INT;
    ppcAttribute.endRegion = PROT_CPUSS_BOOT;
    ppcStatus = Cy_Ppc_ConfigAttrib(ppcPtr, &ppcAttribute);
    if (ppcStatus != CY_PPC_SUCCESS) {
        while(true){
        }
    }

    //97 - 215
    ppcAttribute.startRegion = PROT_CPUSS_SL_CTL_GROUP;
    ppcAttribute.endRegion = PROT_MCPASS;
    ppcStatus = Cy_Ppc_ConfigAttrib(ppcPtr, &ppcAttribute);
    if (ppcStatus != CY_PPC_SUCCESS) {
        while(1);
    }

    //0 - 6
    ppcAttribute.startRegion = PROT_PERI0_MAIN;
    ppcAttribute.endRegion = PROT_PERI0_GR5_GROUP;
    ppcStatus = Cy_Ppc_ConfigAttrib(ppcPtr, &ppcAttribute);
    if (ppcStatus != CY_PPC_SUCCESS) {
        while(true){
        }
    }

    //13 - 13
    ppcAttribute.startRegion = PROT_PERI0_TR;
    ppcAttribute.endRegion = PROT_PERI0_TR;
    ppcStatus = Cy_Ppc_ConfigAttrib(ppcPtr, &ppcAttribute);
    if (ppcStatus != CY_PPC_SUCCESS) {
        while(true){
        }
    }


    // Set PC Mask
    pcMaskConfig.startRegion = PROT_PERI0_MAIN;
    pcMaskConfig.endRegion = PROT_MCPASS;
    pcMaskConfig.pcMask = 0xFFFFFFFF;
    ppcStatus = Cy_Ppc_SetPcMask(ppcPtr, &pcMaskConfig);
    if (ppcStatus != CY_PPC_SUCCESS) {
        while(1);
    }
}

cy_en_ms_ctl_status_t config_set_cm33_ns_pc(void)
{
    cy_en_ms_ctl_status_t mscStatus;
    uint32_t activePC;

    mscStatus = Cy_Ms_Ctl_SetPcHandler(CM33_S_PC_VALUE, ipc_cm33_s_isr);
    if (mscStatus == CY_MS_CTL_SUCCESS)
    {
        mscStatus = Cy_Ms_Ctl_ConfigBusMaster(CPUSS_MS_ID_CM33_0, true, true, ((1u<<CM33_NS_PC_VALUE)|(1u<<CM33_S_PC_VALUE)));
        if (mscStatus == CY_MS_CTL_SUCCESS)
        {
            Cy_Ms_Ctl_SetSavedPC(CPUSS_MS_ID_CM33_0, CM33_NS_PC_VALUE);
            mscStatus = Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_NS_PC_VALUE);
            if (mscStatus == CY_MS_CTL_SUCCESS)
            {
                activePC =  Cy_Ms_Ctl_GetActivePC(CPUSS_MS_ID_CM33_0);
                if (activePC != CM33_NS_PC_VALUE)
                {
                    mscStatus = CY_MS_CTL_FAILURE;
                }
            }   /* set active pc */
        }   /* config bus master */
    }

    return mscStatus;
}


