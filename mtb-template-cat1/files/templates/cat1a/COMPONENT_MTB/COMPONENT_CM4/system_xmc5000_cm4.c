/***************************************************************************//**
* \file system_xmc5000_cm4.c
* \version 2.120
*
* The device system-source file.
*
********************************************************************************
* \copyright
* Copyright 2016-2025 Infineon Technologies AG, or an affiliate of Infineon Technologies AG.
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

#include <stdbool.h>
#include "system_psoc6.h"
#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_syslib.h"
#include "cy_sysclk.h"
#include "cy_wdt.h"

#if defined(CY_DEVICE_XMC5000)

/*******************************************************************************
* SystemCoreClockUpdate()
*******************************************************************************/

/** Default HFClk frequency in Hz */
#define CY_CLK_HFCLK0_FREQ_HZ_DEFAULT       (8000000UL)

/** Default PeriClk frequency in Hz */
#define CY_CLK_PERICLK_FREQ_HZ_DEFAULT      (8000000UL)

/** Default system core frequency in Hz */
#define CY_CLK_SYSTEM_FREQ_HZ_DEFAULT       (8000000UL)

/* SCB->CPACR */
#define SCB_CPACR_CP10_CP11_ENABLE      (0xFUL << 20u)

/** Holds the CLK_SLOW(Cortex-M0+) or CLK_FAST0(Cortex-M4_0) system core clock */
CY_NOINIT uint32_t SystemCoreClock ;

/** Holds the HFClk0 clock frequency. Updated by \ref SystemCoreClockUpdate(). */
CY_NOINIT uint32_t cy_Hfclk0FreqHz ;

/** Holds the PeriClk clock frequency. Updated by \ref SystemCoreClockUpdate(). */
CY_NOINIT uint32_t cy_PeriClkFreqHz ;

/** Holds the AHB frequency. Updated by \ref SystemCoreClockUpdate(). */
CY_NOINIT uint32_t cy_AhbFreqHz ;

/*******************************************************************************
* SystemCoreClockUpdate (void)
*******************************************************************************/

/* Do not use these definitions directly in your application */
#define CY_DELAY_MS_OVERFLOW_THRESHOLD  (0x8000u)
#define CY_DELAY_1K_THRESHOLD           (1000u)
#define CY_DELAY_1K_MINUS_1_THRESHOLD   (CY_DELAY_1K_THRESHOLD - 1u)
#define CY_DELAY_1M_THRESHOLD           (1000000u)
#define CY_DELAY_1M_MINUS_1_THRESHOLD   (CY_DELAY_1M_THRESHOLD - 1u)

CY_NOINIT uint32_t cy_delayFreqKhz ;

CY_NOINIT uint8_t cy_delayFreqMhz ;

/* Interrupt Logic */

void Cy_DefaultUserHandler(void);

#define DEFAULT_HANDLER_NAME                            Cy_DefaultUserHandler

CY_NOINIT cy_israddress Cy_SystemIrqUserTable[CPUSS_SYSTEM_INT_NR] ;

CY_NOINIT cy_israddress * Cy_SysInt_SystemIrqUserTableRamPointer ;

void CM4_CpuIntr_Handler(uint8_t intrNum);

/*******************************************************************************
* Function Name: Cy_DefaultUserHandler
****************************************************************************//**
*
*The Handler is called when the CPU attempts to call IRQ that has not been mapped to user functions.
*
*
*******************************************************************************/
void Cy_DefaultUserHandler(void)
{
    // This IRQ occurred because CPU attempted to call IRQ that has not been mapped to user function
    while(1);
}

/*******************************************************************************
* Function Name: NvicMux0_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt0 occurs.
*
*******************************************************************************/
void NvicMux0_IRQHandler(void)
{
    CM4_CpuIntr_Handler(0);
}

/*******************************************************************************
* Function Name: NvicMux1_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt0 occurs.
*
*******************************************************************************/
void NvicMux1_IRQHandler(void)
{
    CM4_CpuIntr_Handler(1);
}

/*******************************************************************************
* Function Name: NvicMux2_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt2 occurs.
*
*******************************************************************************/
void NvicMux2_IRQHandler(void)
{
    CM4_CpuIntr_Handler(2);
}

/*******************************************************************************
* Function Name: NvicMux3_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt3 occurs.
*
*******************************************************************************/
void NvicMux3_IRQHandler(void)
{
    CM4_CpuIntr_Handler(3);
}

/*******************************************************************************
* Function Name: NvicMux4_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt4 occurs.
*
*******************************************************************************/
void NvicMux4_IRQHandler(void)
{
    CM4_CpuIntr_Handler(4);
}

/*******************************************************************************
* Function Name: NvicMux5_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt5 occurs.
*
*******************************************************************************/
void NvicMux5_IRQHandler(void)
{
    CM4_CpuIntr_Handler(5);
}

/*******************************************************************************
* Function Name: NvicMux6_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt6 occurs.
*
*******************************************************************************/
void NvicMux6_IRQHandler(void)
{
    CM4_CpuIntr_Handler(6);
}

/*******************************************************************************
* Function Name: NvicMux7_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt7 occurs.
*
*******************************************************************************/
void NvicMux7_IRQHandler(void)
{
    CM4_CpuIntr_Handler(7);
}

/*******************************************************************************
* Function Name: CM4_CpuIntr_Handler
****************************************************************************//**
*
* The Inline handler for CPU interrupt.
* The system interrupt mapped to CPU interrupt will be fetched and executed
*
*******************************************************************************/
void CM4_CpuIntr_Handler(uint8_t intrNum)
{
    uint32_t system_int_idx;
    cy_israddress handler;

    if((_FLD2VAL(CPUSS_V2_CM4_INT0_STATUS_SYSTEM_INT_VALID, CPUSS_CM4_INT_STATUS[intrNum])))
    {
        system_int_idx = _FLD2VAL(CPUSS_V2_CM4_INT0_STATUS_SYSTEM_INT_IDX, CPUSS_CM4_INT_STATUS[intrNum]);
        handler = Cy_SystemIrqUserTable[system_int_idx];
        handler(); // jump to system interrupt handler
    }
    NVIC_ClearPendingIRQ((IRQn_Type)intrNum);
}

/*******************************************************************************
* Function Name: SystemIrqInit
****************************************************************************//**
*
* The function is called during device startup.
*
*******************************************************************************/
void SystemIrqInit(void)
{
    for (int i=0; i<(int)CPUSS_SYSTEM_INT_NR; i++)
    {
        Cy_SystemIrqUserTable[i] = DEFAULT_HANDLER_NAME;
    }

    Cy_SysInt_SystemIrqUserTableRamPointer = Cy_SystemIrqUserTable;
}

/*******************************************************************************
* Function Name: SystemInit
****************************************************************************//**
* \cond
* Initializes the system:
* - Unlocks and disables WDT.
* - Calls the Cy_SystemInit() function.
* - Calls \ref SystemCoreClockUpdate().
* \endcond
*******************************************************************************/
void SystemInit(void)
{
    Cy_PDL_Init(CY_DEVICE_CFG);

    Cy_SystemInit();
    SystemCoreClockUpdate();

    SystemIrqInit();
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
     /* Empty weak function. The actual implementation to be in the user application
      * as strong function.
     */
}

/*******************************************************************************
* Function Name: SystemCoreClockUpdate
****************************************************************************//**
*
* Gets core clock frequency and updates \ref SystemCoreClock, \ref
* cy_Hfclk0FreqHz, and \ref cy_PeriClkFreqHz.
*
* Updates global variables used by the \ref Cy_SysLib_Delay(), \ref
* Cy_SysLib_DelayUs(), and \ref Cy_SysLib_DelayCycles().
*
*******************************************************************************/
void SystemCoreClockUpdate (void)
{
    /* Get frequency for the high-frequency clock # 0 */
    /* This is part of the clock tree for the CM0+; do not use for CM4 clock calculations. */
    cy_Hfclk0FreqHz = Cy_SysClk_ClkHfGetFrequency(CY_SYSCLK_CLK_CORE_HF_PATH_NUM);

    /* The CM4 core's clock source is the fast clock. */
    SystemCoreClock = Cy_SysClk_ClkFastGetFrequency();

    /* Get frequency for the high-frequency clock # 2 , which is used for PERI PCLK*/
    cy_PeriClkFreqHz = Cy_SysClk_ClkHfGetFrequency(CY_SYSCLK_CLK_PERI_HF_PATH_NUM);

    /* Sets clock frequency for Delay API */
    cy_delayFreqMhz = (uint32_t)((SystemCoreClock + CY_DELAY_1M_MINUS_1_THRESHOLD) / CY_DELAY_1M_THRESHOLD);
    cy_delayFreqKhz = (SystemCoreClock + CY_DELAY_1K_MINUS_1_THRESHOLD) / CY_DELAY_1K_THRESHOLD;

    /* Get the frequency of AHB source, CLK HF0 is the source for AHB*/
    cy_AhbFreqHz = Cy_SysClk_ClkHfGetFrequency(0UL);
}

/*******************************************************************************
* Function Name: Cy_SystemInitFpuEnable
****************************************************************************//**
*
* Enables the FPU if it is used. The function is called from the startup file.
*
*******************************************************************************/
void Cy_SystemInitFpuEnable(void)
{
    #if defined (__FPU_USED) && (__FPU_USED == 1U)
        uint32_t  interruptState;
        interruptState = __get_PRIMASK();
        __disable_irq();
        SCB->CPACR |= SCB_CPACR_CP10_CP11_ENABLE;
        __DSB();
        __ISB();
        __set_PRIMASK(interruptState);
    #endif /* (__FPU_USED) && (__FPU_USED == 1U) */
}

#endif /* defined(CY_DEVICE_XMC5000) */

/* [] END OF FILE */
