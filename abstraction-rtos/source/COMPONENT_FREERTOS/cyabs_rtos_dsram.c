/***********************************************************************************************//**
 * \file cyabs_freertos_dsram.c
 *
 * \brief
 * Provides implementations for functions required to enable deepsleep ram.
 *
 ***************************************************************************************************
 * \copyright
 * Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation
 *
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
 **************************************************************************************************/
#include <cmsis_compiler.h> // For __WEAK
#include "FreeRTOS.h"
#include "cyabs_rtos.h"
#include "cyabs_rtos_dsram.h"
#if defined(COMPONENT_CAT1B)
#include "cy_syslib.h"
#endif
#if defined(COMPONENT_CAT1E)
#include "system_cat1e.h"
#endif

void vPortSetupTimerInterrupt(void);
void Cy_SysPm_StoreDSContext_Wfi(void);

#if defined (COMPONENT_CAT1B) || defined (COMPONENT_CAT1E)
//--------------------------------------------------------------------------------------------------
// vStoreDSRAMContextWithWFI
//--------------------------------------------------------------------------------------------------
__WEAK void vStoreDSRAMContextWithWFI(void)
{
}


//--------------------------------------------------------------------------------------------------
// vRestoreDSRAMContext
//--------------------------------------------------------------------------------------------------
__WEAK void vRestoreDSRAMContext(void)
{
}


CY_RAMFUNC_BEGIN
//--------------------------------------------------------------------------------------------------
// Cy_SysPm_StoreDSContext_Wfi
// Cy_SysPm_StoreDSContext_Wfi is defined as a weak function in pdl.
// This implementation under abstraction rtos implements FreeRTOS
// specific context store required for deep sleep entry.
//--------------------------------------------------------------------------------------------------
void Cy_SysPm_StoreDSContext_Wfi(void)
{
    System_Store_NVIC_Reg();
    /* Clear the Warm Boot Entry status Flag */
    Cy_SysLib_ClearDSRAMWarmBootEntryStatus();
    vStoreDSRAMContextWithWFI();
    System_Restore_NVIC_Reg();
}


CY_RAMFUNC_END


//--------------------------------------------------------------------------------------------------
// cyabs_dsram_exit_dsram
//--------------------------------------------------------------------------------------------------
__WEAK void cyabs_rtos_exit_dsram(void)
{
    vPortSetupTimerInterrupt();

    vRestoreDSRAMContext();
}


#endif // if defined(COMPONENT_CAT1B)
