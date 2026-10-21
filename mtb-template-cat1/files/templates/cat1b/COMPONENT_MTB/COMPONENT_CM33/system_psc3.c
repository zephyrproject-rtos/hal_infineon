/***************************************************************************//**
* \file system_psc3.c
* \version 1.0
*
* The device system-source file.
*
********************************************************************************
* \copyright
* Copyright (c) (2020-2022), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"

#if defined (CY_DEVICE_PSC3)

#include <stdbool.h>
#include "system_cat1b.h"
#include "cy_syslib.h"
#include "cy_wdt.h"
#include "cy_sysclk.h"
#include "cy_syspm.h"

/*******************************************************************************
* SystemCoreClockUpdate()
*******************************************************************************/

/** Default HFClk frequency in Hz */
#define CY_CLK_HFCLK0_FREQ_HZ_DEFAULT       (48000000UL)

/** Default PeriClk frequency in Hz */
#define CY_CLK_PERICLK_FREQ_HZ_DEFAULT      (48000000UL)

/** Default system core frequency in Hz */
#define CY_CLK_SYSTEM_FREQ_HZ_DEFAULT       (48000000UL)

/** Holds the CLK_HF0 system core clock. */
uint32_t SystemCoreClock = CY_CLK_SYSTEM_FREQ_HZ_DEFAULT;

/** Holds the HFClk0 clock frequency. Updated by \ref SystemCoreClockUpdate(). */
uint32_t cy_Hfclk0FreqHz  = CY_CLK_HFCLK0_FREQ_HZ_DEFAULT;

/** Holds the PeriClk clock frequency. Updated by \ref SystemCoreClockUpdate(). */
uint32_t cy_PeriClkFreqHz = CY_CLK_PERICLK_FREQ_HZ_DEFAULT;

/** Holds the AHB frequency. Updated by \ref SystemCoreClockUpdate(). */
uint32_t cy_AhbFreqHz = CY_CLK_SYSTEM_FREQ_HZ_DEFAULT;

/*******************************************************************************
* SystemCoreClockUpdate (void)
*******************************************************************************/

/* Do not use these definitions directly in your application */
#define CY_DELAY_MS_OVERFLOW_THRESHOLD  (0x8000u)
#define CY_DELAY_1K_THRESHOLD           (1000u)
#define CY_DELAY_1K_MINUS_1_THRESHOLD   (CY_DELAY_1K_THRESHOLD - 1u)
#define CY_DELAY_1M_THRESHOLD           (1000000u)
#define CY_DELAY_1M_MINUS_1_THRESHOLD   (CY_DELAY_1M_THRESHOLD - 1u)
uint32_t cy_delayFreqHz   = CY_CLK_SYSTEM_FREQ_HZ_DEFAULT;

uint32_t cy_delayFreqKhz  = (CY_CLK_SYSTEM_FREQ_HZ_DEFAULT + CY_DELAY_1K_MINUS_1_THRESHOLD) /
                            CY_DELAY_1K_THRESHOLD;

uint8_t cy_delayFreqMhz  = (uint8_t)((CY_CLK_SYSTEM_FREQ_HZ_DEFAULT + CY_DELAY_1M_MINUS_1_THRESHOLD) /
                            CY_DELAY_1M_THRESHOLD);

/* Reset values for each PERI group */
#define CY_PERI_GR1_SL_CTL 0x0F
#define CY_PERI_GR2_SL_CTL 0x03
#define CY_PERI_GR3_SL_CTL 0x3F
#define CY_PERI_GR4_SL_CTL 0x03
#define CY_PERI_GR5_SL_CTL 0x01

void SystemInit_Enable_Clocks(void)
{
    /** Enable HF2 */
    (void)Cy_SysClk_ClkHfSetSource(2U, CY_SYSCLK_CLKHF_IN_CLKPATH0);    /* Suppress a compiler warning about unused return value */
    (void)Cy_SysClk_ClkHfSetDivider(2U, CY_SYSCLK_CLKHF_NO_DIVIDE); /* Suppress a compiler warning about unused return value */
    (void)Cy_SysClk_ClkHfEnable(2U);         /* Suppress a compiler warning about unused return value */

    /** Enable HF3 */
    (void)Cy_SysClk_ClkHfSetSource(3U, CY_SYSCLK_CLKHF_IN_CLKPATH0);    /* Suppress a compiler warning about unused return value */
    (void)Cy_SysClk_ClkHfSetDivider(3U, CY_SYSCLK_CLKHF_NO_DIVIDE); /* Suppress a compiler warning about unused return value */
    (void)Cy_SysClk_ClkHfEnable(3U);         /* Suppress a compiler warning about unused return value */

    /** Enable HF4 */
    (void)Cy_SysClk_ClkHfSetSource(4U, CY_SYSCLK_CLKHF_IN_CLKPATH0);    /* Suppress a compiler warning about unused return value */
    (void)Cy_SysClk_ClkHfSetDivider(4U, CY_SYSCLK_CLKHF_NO_DIVIDE); /* Suppress a compiler warning about unused return value */
    (void)Cy_SysClk_ClkHfEnable(4U);         /* Suppress a compiler warning about unused return value */

}


void SystemInit_Enable_Peri(void)
{
    /* Release reset for all groups IP except group 0 */
    if(Cy_SysClk_PeriGroupGetSlaveCtl(1, CY_SYSCLK_PERI_GROUP_SL_CTL) != CY_PERI_GR1_SL_CTL)
    {
        (void)Cy_SysClk_PeriGroupSetSlaveCtl(1, CY_SYSCLK_PERI_GROUP_SL_CTL2, 0x0U); /* typecast void to suppress a compiler warning about unused return value */
        (void)Cy_SysClk_PeriGroupSetSlaveCtl(1, CY_SYSCLK_PERI_GROUP_SL_CTL, 0xFFFFFFFFU); /* typecast void to suppress a compiler warning about unused return value */
    }

    if(Cy_SysClk_PeriGroupGetSlaveCtl(2, CY_SYSCLK_PERI_GROUP_SL_CTL) != CY_PERI_GR2_SL_CTL)
    {
        (void)Cy_SysClk_PeriGroupSetSlaveCtl(2, CY_SYSCLK_PERI_GROUP_SL_CTL2, 0x0U); /* typecast void to suppress a compiler warning about unused return value */
        (void)Cy_SysClk_PeriGroupSetSlaveCtl(2, CY_SYSCLK_PERI_GROUP_SL_CTL, 0xFFFFFFFFU); /* typecast void to suppress a compiler warning about unused return value */
    }


    if(Cy_SysClk_PeriGroupGetSlaveCtl(3, CY_SYSCLK_PERI_GROUP_SL_CTL) != CY_PERI_GR3_SL_CTL)
    {
        (void)Cy_SysClk_PeriGroupSetSlaveCtl(3, CY_SYSCLK_PERI_GROUP_SL_CTL2, 0x0U); /* typecast void to suppress a compiler warning about unused return value */
        (void)Cy_SysClk_PeriGroupSetSlaveCtl(3, CY_SYSCLK_PERI_GROUP_SL_CTL, 0xFFFFFFFFU); /* typecast void to suppress a compiler warning about unused return value */
    }

    if(Cy_SysClk_PeriGroupGetSlaveCtl(4, CY_SYSCLK_PERI_GROUP_SL_CTL) != CY_PERI_GR4_SL_CTL)
    {
        (void)Cy_SysClk_PeriGroupSetSlaveCtl(4, CY_SYSCLK_PERI_GROUP_SL_CTL2, 0x0U); /* typecast void to suppress a compiler warning about unused return value */
        (void)Cy_SysClk_PeriGroupSetSlaveCtl(4, CY_SYSCLK_PERI_GROUP_SL_CTL, 0xFFFFFFFFU); /* typecast void to suppress a compiler warning about unused return value */
    }

    if(Cy_SysClk_PeriGroupGetSlaveCtl(5, CY_SYSCLK_PERI_GROUP_SL_CTL) != CY_PERI_GR5_SL_CTL)
    {
        (void)Cy_SysClk_PeriGroupSetSlaveCtl(5, CY_SYSCLK_PERI_GROUP_SL_CTL2, 0x0U); /* typecast void to suppress a compiler warning about unused return value */
        (void)Cy_SysClk_PeriGroupSetSlaveCtl(5, CY_SYSCLK_PERI_GROUP_SL_CTL, 0xFFFFFFFFU); /* typecast void to suppress a compiler warning about unused return value */
    }
}


CY_SECTION_RAMFUNC_BEGIN
/*******************************************************************************
* Function Name: SystemInit_Warmboot_CAT1B_CM33
****************************************************************************//**
*
* Prepares the system to work after warmboot:
* - Initializes Vector Table
* - Enables all the IP's through Slave Control Registers
* - Unfreezes the IO's
*
*******************************************************************************/
void SystemInit_Warmboot_CAT1B_CM33(void)
{
    #if defined(CY_PDL_TZ_ENABLED)
    SCB->VTOR = (uint32_t)__s_vector_table_rw;
    #else
    SCB->VTOR = (uint32_t)__ns_vector_table_rw;
    #endif
    (void)Cy_SysClk_PeriGroupSetSlaveCtl(1, CY_SYSCLK_PERI_GROUP_SL_CTL2, 0x0U);
    (void)Cy_SysClk_PeriGroupSetSlaveCtl(2, CY_SYSCLK_PERI_GROUP_SL_CTL2, 0x0U);
    (void)Cy_SysClk_PeriGroupSetSlaveCtl(3, CY_SYSCLK_PERI_GROUP_SL_CTL2, 0x0U);
    (void)Cy_SysClk_PeriGroupSetSlaveCtl(4, CY_SYSCLK_PERI_GROUP_SL_CTL2, 0x0U);
    (void)Cy_SysClk_PeriGroupSetSlaveCtl(5, CY_SYSCLK_PERI_GROUP_SL_CTL2, 0x0U);

    (void)Cy_SysClk_PeriGroupSetSlaveCtl(1, CY_SYSCLK_PERI_GROUP_SL_CTL, 0xFFFFFFFFU);
    (void)Cy_SysClk_PeriGroupSetSlaveCtl(2, CY_SYSCLK_PERI_GROUP_SL_CTL, 0xFFFFFFFFU);
    (void)Cy_SysClk_PeriGroupSetSlaveCtl(3, CY_SYSCLK_PERI_GROUP_SL_CTL, 0xFFFFFFFFU);
    (void)Cy_SysClk_PeriGroupSetSlaveCtl(4, CY_SYSCLK_PERI_GROUP_SL_CTL, 0xFFFFFFFFU);
    (void)Cy_SysClk_PeriGroupSetSlaveCtl(5, CY_SYSCLK_PERI_GROUP_SL_CTL, 0xFFFFFFFFU);

    if (Cy_SysPm_DeepSleepIoIsFrozen())
    {
        Cy_SysPm_DeepSleepIoUnfreeze();
    }

    cy_WakeupFromWarmBootStatus = true;
}
CY_SECTION_RAMFUNC_END

#define CY_NVIC_REG_COUNT 3U
#define CY_NVIC_IPR_REG_COUNT 69U

uint32_t nvicStoreRestore[CY_NVIC_REG_COUNT];
uint32_t nvicIPRStoreRestore[CY_NVIC_IPR_REG_COUNT];
uint32_t scbSHPR3StoreRestore;
#define SCB_SHPR3_REG     ( *( ( volatile uint32_t * ) 0xe000ed20 ) )

/*******************************************************************************
* Function Name: System_Store_NVIC_Reg
****************************************************************************//**
*
* Stores the NVIC register before Deepsleep RAM:
*
*******************************************************************************/
CY_SECTION_RAMFUNC_BEGIN
void System_Store_NVIC_Reg(void)
{
    for (uint32_t idx = 0; idx < CY_NVIC_REG_COUNT; idx++)
    {
        nvicStoreRestore[idx] = NVIC->ISER[idx];
    }

    for (uint32_t idx = 0; idx < CY_NVIC_IPR_REG_COUNT; idx++)
    {
        nvicIPRStoreRestore[idx] = NVIC->IPR[idx];
    }

    scbSHPR3StoreRestore = SCB_SHPR3_REG;
}
CY_SECTION_RAMFUNC_END


/*******************************************************************************
* Function Name: System_Restore_NVIC_Reg
****************************************************************************//**
*
* Restores the NVIC register After Deepsleep RAM Wakeup i.e. Warmboot:
*
*******************************************************************************/
CY_SECTION_RAMFUNC_BEGIN
void System_Restore_NVIC_Reg(void)
{
    for (uint32_t idx = 0; idx < CY_NVIC_REG_COUNT; idx++)
    {
        NVIC->ISER[idx] = nvicStoreRestore[idx];
    }

    for (uint32_t idx = 0; idx < CY_NVIC_IPR_REG_COUNT; idx++)
    {
        NVIC->IPR[idx] = nvicIPRStoreRestore[idx];
    }

    SCB_SHPR3_REG = scbSHPR3StoreRestore;
}
CY_SECTION_RAMFUNC_END

void SystemInit(void)
{
#if !defined(CY_NOT_ENABLE_IP_IN_STARTUP)
#ifdef CY_PDL_TZ_ENABLED
    SystemInit_Enable_Clocks();
    SystemInit_Enable_Peri();
#endif /* CY_PDL_TZ_ENABLED */
#endif /* CY_NOT_ENABLE_IP_IN_STARTUP */

    (void)Cy_SystemInit(); /* typecast void to suppress a compiler warning about unused return value */

    SystemCoreClockUpdate();
}

/*******************************************************************************
* Function Name: Cy_SystemInit
****************************************************************************//**
*
* The function is called during device startup.
*
*******************************************************************************/
__WEAK void Cy_SystemInit(void)
{
     /* Empty weak function.
     */
     __NOP(); /* No operation */
}

/*******************************************************************************
* Function Name: SystemCoreClockUpdate
****************************************************************************//**
*
* The function is called during device startup.
*
*******************************************************************************/
void SystemCoreClockUpdate (void)
{
    uint32_t pathFreqHz;
    uint32_t clkHfPath;

    /* Get frequency for the high-frequency clock # 0 */
    clkHfPath = CY_SYSCLK_CLK_CORE_HF_PATH_NUM;

    pathFreqHz = Cy_SysClk_ClkHfGetFrequency(clkHfPath);

    SystemCoreClock = pathFreqHz;

    cy_Hfclk0FreqHz = SystemCoreClock;

    /* Get frequency for the high-frequency clock # 2 , which is used for PERI PCLK*/
    clkHfPath = CY_SYSCLK_CLK_PERI_HF_PATH_NUM;

    pathFreqHz = Cy_SysClk_ClkHfGetFrequency(clkHfPath);

    cy_PeriClkFreqHz = pathFreqHz;

    /* Sets clock frequency for Delay API */
    cy_delayFreqHz = SystemCoreClock;
    cy_delayFreqMhz = (uint8_t)((cy_delayFreqHz + CY_DELAY_1M_MINUS_1_THRESHOLD) / CY_DELAY_1M_THRESHOLD);
    cy_delayFreqKhz = (cy_delayFreqHz + CY_DELAY_1K_MINUS_1_THRESHOLD) / CY_DELAY_1K_THRESHOLD;

    /* Get the frequency of AHB source, CLK HF0 is the source for AHB*/
    cy_AhbFreqHz = Cy_SysClk_ClkHfGetFrequency(0UL);
}

#endif /* defined (CY_DEVICE_PSC3) */
/* [] END OF FILE */

