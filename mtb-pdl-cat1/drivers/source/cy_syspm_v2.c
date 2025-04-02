/***************************************************************************//**
* \file cy_syspm_v2.c
* \version 5.180
*
* This driver provides the source code for API power management.
*
********************************************************************************
* \copyright
* Copyright (c) (2016-2024), Cypress Semiconductor Corporation (an Infineon company) or
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
#include "cy_sysclk.h"

#if defined (CY_IP_MXS40SSRSS)

#include "cy_syspm.h"
#if  defined (CY_IP_MXS40SSRSS)
#include "cy_syspm_ppu.h"
#endif


/*******************************************************************************
*       Internal Functions
*******************************************************************************/
__WEAK void Cy_SysPm_Dsramoff_Entry(void);
static bool IsVoltageChangePossible(void);

#ifdef ENABLE_MEM_VOLTAGE_TRIMS
/* RAM and ROM Voltage TRIM functions */
static void SetMemoryVoltageTrims(cy_en_syspm_sdr_voltage_t voltage);
#endif /* ENABLE_MEM_VOLTAGE_TRIMS */

#if defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)
static void SetReadMarginTrimUlp(void);
static void SetReadMarginTrimLp(void);
static void SetReadMarginTrimMf(void);
static void SetReadMarginTrimOd(void);
static void SetWriteAssistTrimUlp(void);
static void SetWriteAssistTrimLp(void);
static void SetWriteAssistTrimMf(void);
static void SetWriteAssistTrimOd(void);
#endif

/*******************************************************************************
*       Internal Defines
*******************************************************************************/


#if defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)
/* The define for number of callback roots */
#define CALLBACK_ROOT_NR                (9U)

/* Define for transitional 1.0 V for the LDO regulator */
#define LDO_OUT_VOLTAGE_1_0V          (0x0CU)

/* Define for transitional 1.2 V for the LDO regulator */
#define LDO_OUT_VOLTAGE_1_2V          (0x1CU)

/* Define for transitional 1.1 V for the LDO regulator */
#define LDO_OUT_VOLTAGE_1_1V           (0x14U)

/* Define for an LDO stabilization delay to 1.0 V */
#define LDO_TO_1_0V_DELAY_US          (3U)

/* Define for an LDO regulator stabilization delay to 1.1 V */
#define LDO_TO_1_1V_DELAY_US          (3U)

/* Define for an LDO stabilization delay 1.2 V */
#define LDO_TO_1_2V_DELAY_US          (3U)

/* Mask for the RAM read assist bits */
#define SRSS_TRIM_RAM_CTL_RA_MASK                   ((uint32_t) 0x3U << 8U)

/* Wake up delay for LP mode */
#define SRSS_PWR_TRIM_WAKE_LP                   (0x50U)

/* Wake up delay for MF mode */
#define SRSS_PWR_TRIM_WAKE_MF                   (0x50U)

/* Wake up delay for OD mode*/
#define SRSS_PWR_TRIM_WAKE_OD                   (0x50U)

/* Mask for the RAM write check bits */
#define SRSS_TRIM_RAM_CTL_WC_MASK        (0x3UL << 10U)

#else
/* The define for number of callback roots */
#define CALLBACK_ROOT_NR                (7U)
#endif

/* The mask to unlock the Hibernate power mode */
#define HIBERNATE_UNLOCK_VAL                 ((uint32_t) 0x3Au << SRSS_PWR_HIBERNATE_UNLOCK_Pos)

/* The mask to set the Hibernate power mode */
#define SET_HIBERNATE_MODE                   ((HIBERNATE_UNLOCK_VAL |\
                                               SRSS_PWR_HIBERNATE_FREEZE_Msk |\
                                               SRSS_PWR_HIBERNATE_HIBERNATE_Msk))

/* The mask to retain the Hibernate power mode status */
#define HIBERNATE_RETAIN_STATUS_MASK         ((SRSS_PWR_HIBERNATE_TOKEN_Msk |\
                                               SRSS_PWR_HIBERNATE_MASK_HIBALARM_Msk |\
                                               SRSS_PWR_HIBERNATE_MASK_HIBWDT_Msk |\
                                               SRSS_PWR_HIBERNATE_POLARITY_HIBPIN_Msk |\
                                               SRSS_PWR_HIBERNATE_MASK_HIBPIN_Msk))

/** The mask for the Hibernate wakeup sources */
#define HIBERNATE_WAKEUP_MASK               ((SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC_Msk |\
                                              SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_CSV_BAK_Msk |\
                                              SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_RTC_Msk |\
                                              SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_WDT_Msk))

/** The define to update the token to indicate the transition into Hibernate */
#define HIBERNATE_TOKEN                    ((uint32_t) 0x1BU << SRSS_PWR_HIBERNATE_TOKEN_Pos)

/* The wait time for transition into the minimum regulator current mode
*/
#define SET_MIN_CURRENT_MODE_DELAY_US        (1U)

/* The wait delay time that occurs before the active reference is settled.
*  Intermediate delay is used in transition into the normal regulator current
*  mode
*/
#define ACT_REF_SETTLE_DELAY_US              (6U)

/* The wait delay time that occurs after the active reference is settled.
*  Final delay is used in transition into the normal regulator current mode
*/
#define SET_NORMAL_CURRENT_MODE_DELAY_US     (1U)

/* The internal define of the tries number in the
* Cy_SysPm_SystemSetMinRegulatorCurrent() function
*/
#define WAIT_DELAY_TRIES                (100U)

/* The internal define of the tries number in the
* Cy_SysPm_SystemSetMinRegulatorCurrent() function
*/
#define CY_SYSPM_CBUCK_BUSY_RETRY_COUNT         (100U)
#define CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_MS      (1U)

/* Define for ROM trim for 0.9V */
#define CPUSS_TRIM_ROM_VOLT_0_900         (0x00000012U)

/* Define for ROM trim for 1.0V */
#define CPUSS_TRIM_ROM_VOLT_1_000         (0x00000012U)

/* Define for ROM trim for 1.1V */
#define CPUSS_TRIM_ROM_VOLT_1_100         (0x00000013U)

/* Define for RAM trim for 0.9V */
#define CPUSS_TRIM_RAM_VOLT_0_900         (0x00006012U)

/* Define for RAM trim for 1.0V */
#define CPUSS_TRIM_RAM_VOLT_1_000         (0x00005012U)

/* Define for RAM trim for 1.1V */
#define CPUSS_TRIM_RAM_VOLT_1_100         (0x00004013U)

/* Mask for the RAM write check bits */
#define CPUSS_TRIM_RAM_CTL_WC_MASK        (0x3UL << 10U)

/* Define for transitional 0.95 V for the LDO regulator */
#define LDO_OUT_VOLTAGE_0_95V          (0x0BU)

/*******************************************************************************
*       Internal Variables
*******************************************************************************/
#if defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)
/* Array of the callback roots */
static cy_stc_syspm_callback_t* pmCallbackRoot[CALLBACK_ROOT_NR] = {(void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0};

/* The array of the pointers to failed callback */
static cy_stc_syspm_callback_t* failedCallback[CALLBACK_ROOT_NR] = {(void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0};
#else
/* Array of the callback roots */
static cy_stc_syspm_callback_t* pmCallbackRoot[CALLBACK_ROOT_NR] = {(void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0};

/* The array of the pointers to failed callback */
static cy_stc_syspm_callback_t* failedCallback[CALLBACK_ROOT_NR] = {(void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0};
#endif

void Cy_SysPm_Init(void)
{
    if(CY_SYSPM_WARM_BOOT_MODE != Cy_SysPm_GetBootMode())
    {
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_MAIN_BASE); /* Suppress a compiler warning about unused return value */
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_CPUSS_BASE); /* Suppress a compiler warning about unused return value */
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_SRAM_BASE); /* Suppress a compiler warning about unused return value */

        /* Set Default mode to DEEPSLEEP */
        (void)Cy_SysPm_SetDeepSleepMode(CY_SYSPM_MODE_DEEPSLEEP);
    }
}

cy_en_syspm_status_t Cy_SysPm_CpuEnterSleep(cy_en_syspm_waitfor_t waitFor)
{
    uint32_t interruptState;
    uint32_t cbSleepRootIdx = (uint32_t) CY_SYSPM_SLEEP;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    CY_ASSERT_L3(CY_SYSPM_IS_WAIT_FOR_VALID(waitFor));

    /* Call registered callback functions with CY_SYSPM_CHECK_READY parameter */
    if (pmCallbackRoot[cbSleepRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_CHECK_READY);
    }

    /* The CPU can switch into the Sleep power mode only when
    *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
    *  parameter return CY_SYSPM_SUCCESS.
    */
    if(retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_BEFORE_TRANSITION);
        }

        /* The CPU enters the Sleep power mode upon execution of WFI/WFE */
        SCB_SCR &= (uint32_t) ~SCB_SCR_SLEEPDEEP_Msk;
        __DSB();                   /* Ensure completion of memory access */

        if(waitFor != CY_SYSPM_WAIT_FOR_EVENT)
        {
            __WFI();
        }
        else
        {
            __WFE();
        }

        /* Clear SCB_SCR_SLEEPDEEP flag */
        SCB_SCR &= (uint32_t) ~SCB_SCR_SLEEPDEEP_Msk;

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        *  CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
        *  parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }
    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemLpActiveEnter(void)
{
    uint32_t interruptState;
    uint32_t cbSleepRootIdx = (uint32_t)CY_SYSPM_LPACTIVE_ENTER;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* Step-1: Wait until PWR_CTL.LPM_READY==1 to indicate low power circuits are ready. */
    if(!Cy_SysPm_IsLpmReady())
    {
        retVal = CY_SYSPM_FAIL;
    }
    else
    {
        /* Call registered callback functions with CY_SYSPM_CHECK_READY parameter */
        if (pmCallbackRoot[cbSleepRootIdx] != NULL)
        {
            retVal = Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbSleepRootIdx, CY_SYSPM_CHECK_READY);
        }

        if (retVal == CY_SYSPM_SUCCESS)
        {
            /* The CPU can switch into the LPACTIVE power mode only when
            *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
            *  parameter return CY_SYSPM_SUCCESS.
            */
            /* Call the registered callback functions with
            * CY_SYSPM_BEFORE_TRANSITION parameter
            */
            interruptState = Cy_SysLib_EnterCriticalSection();
            if (pmCallbackRoot[cbSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbSleepRootIdx, CY_SYSPM_BEFORE_TRANSITION); /* Suppress a compiler warning about unused return value */
            }

            //Enabling Low Power Profile
            /* Step-2: Clock for clk_hf0 is selected as IMO, which runs at 8MHz Nominal. */
            (void)Cy_SysClk_ClkHfDirectSel(0U, true);

            //Disable FLL if enabled
            if(Cy_SysClk_FllIsEnabled())
            {
                (void)Cy_SysClk_FllDisable(); /* Suppress a compiler warning about unused return value */
            }

            //Disable PLL if enabled
            #if (defined (SRSS_NUM_TOTAL_PLL) && (SRSS_NUM_TOTAL_PLL > 0UL))
            if(Cy_SysClk_PllIsEnabled(1U))
            {
                (void)Cy_SysClk_PllDisable(1U); /* Suppress a compiler warning about unused return value */
            }

            if(Cy_SysClk_PllIsEnabled(2U))
            {
                (void)Cy_SysClk_PllDisable(2U); /* Suppress a compiler warning about unused return value */
            }
            #endif

            /* Step-3: If reducing the regulator output voltage for RegSetA, perform the extra requester sequence.
             * Call API-Cy_SysPm_LdoExtraRequesterConfig before calling this if the voltage needs to be reduced
             */

            /* Step-4: If lowest power is required; perform the following writes to PWR_CTL2 */
            retVal = Cy_SysPm_SystemSetMinRegulatorCurrent();

            Cy_SysLib_ExitCriticalSection(interruptState);

            /* Call the registered callback functions with the
            *  CY_SYSPM_AFTER_TRANSITION parameter
            */
            if (pmCallbackRoot[cbSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbSleepRootIdx, CY_SYSPM_AFTER_TRANSITION); /* Suppress a compiler warning about unused return value */
            }
        }
        else
        {
            /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
            *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
            *  parameter
            */
            (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbSleepRootIdx, CY_SYSPM_CHECK_FAIL); /* Suppress a compiler warning about unused return value */
            retVal = CY_SYSPM_FAIL;
        }
    }
    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemLpActiveExit(void)
{
    uint32_t interruptState;
    uint32_t cbSleepRootIdx = (uint32_t)CY_SYSPM_LPACTIVE_EXIT;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* Call registered callback functions with CY_SYSPM_CHECK_READY parameter */
    if (pmCallbackRoot[cbSleepRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbSleepRootIdx, CY_SYSPM_CHECK_READY);
    }

    if (retVal == CY_SYSPM_SUCCESS)
    {
        /* The CPU can switch into the LPACTIVE power mode only when
        *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
        *  parameter return CY_SYSPM_SUCCESS.
        */
        /* Call the registered callback functions with
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbSleepRootIdx, CY_SYSPM_BEFORE_TRANSITION); /* Suppress a compiler warning about unused return value */
        }

        /* Step-1: Reverse the writes to PWR_CTL2 which are done in Cy_SysPm_SystemLpActiveEnter*/
        retVal = Cy_SysPm_SystemSetNormalRegulatorCurrent();

        /* Step-2: If increasing the regulator output voltage for RegSetB, perform the extra requester sequence.
         * Call API-Cy_SysPm_LdoExtraRequesterConfig before calling this if the voltage needs to be increased
         */

        /* Step-3: High Frequency clocks could be enabled */
        if (CY_SYSCLK_SUCCESS != Cy_SysClk_FllEnable(0UL))
        {
            retVal = CY_SYSPM_FAIL;
        }

        #if (defined (SRSS_NUM_TOTAL_PLL) && (SRSS_NUM_TOTAL_PLL > 0UL))
        if (CY_SYSCLK_SUCCESS != Cy_SysClk_PllEnable(1UL, 10000u))
        {
            retVal = CY_SYSPM_FAIL;
        }
        if (CY_SYSCLK_SUCCESS != Cy_SysClk_PllEnable(2UL, 10000u))
        {
            retVal = CY_SYSPM_FAIL;
        }
        #endif

        (void)Cy_SysClk_ClkHfDirectSel(0U, false);

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        *  CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbSleepRootIdx, CY_SYSPM_AFTER_TRANSITION); /* Suppress a compiler warning about unused return value */
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
        *  parameter
        */
        (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbSleepRootIdx, CY_SYSPM_CHECK_FAIL); /* Suppress a compiler warning about unused return value */
        retVal = CY_SYSPM_FAIL;
    }
    return retVal;
}

bool Cy_SysPm_IsSystemLpActiveEnabled(void)
{
    return (_FLD2BOOL(SRSS_PWR_CTL2_REFV_DIS, SRSS_PWR_CTL2)? true : false);
}

cy_en_syspm_status_t Cy_SysPm_SetDeepSleepMode(cy_en_syspm_deep_sleep_mode_t deepSleepMode)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_FAIL;

    switch(deepSleepMode)
    {
        case CY_SYSPM_MODE_DEEPSLEEP:
        {
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE, (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_CPUSS_BASE, (uint32_t)CY_SYSTEM_CPUSS_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM_BASE, (uint32_t)CY_SYSTEM_SRAM_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_MODE_DEEPSLEEP_RAM:
        {
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE, (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_CPUSS_BASE, (uint32_t)CY_SYSTEM_CPUSS_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM_BASE, (uint32_t)CY_SYSTEM_SRAM_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_MODE_DEEPSLEEP_OFF:
        {
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE, (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_CPUSS_BASE, (uint32_t)CY_SYSTEM_CPUSS_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM_BASE, (uint32_t)CY_SYSTEM_SRAM_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        default:
            retVal = CY_SYSPM_BAD_PARAM;
        break;
    }
    return retVal;
}

cy_en_syspm_deep_sleep_mode_t Cy_SysPm_GetDeepSleepMode(void)
{
    uint32_t mode;
    cy_en_syspm_deep_sleep_mode_t deepSleepMode;

    mode = (uint32_t)cy_pd_ppu_get_programmed_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE);

    switch(mode)
    {
        case CY_SYSTEM_DEEPSLEEP_PPU_MODES:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP;
        }
        break;

        case CY_SYSTEM_DEEPSLEEP_RAM_PPU_MODES:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_RAM;
        }
        break;

        case CY_SYSTEM_DEEPSLEEP_OFF_PPU_MODES:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_OFF;
        }
        break;

        default:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_NONE;
        }
        break;
    }

    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_deep_sleep_mode_t enum.');
    return ((cy_en_syspm_deep_sleep_mode_t)deepSleepMode);
}

cy_en_syspm_boot_mode_t Cy_SysPm_GetBootMode(void)
{
    uint32_t resCause, resCause2;
    cy_en_syspm_boot_mode_t deepSleepWakeMode = CY_SYSPM_POR_BOOT_MODE;

    resCause = SRSS_RES_CAUSE;
    resCause2 = SRSS_RES_CAUSE2;

    if((resCause == 0UL) || (resCause2 == 0UL))
    {
        switch(Cy_SysPm_GetDeepSleepMode())
        {
            case CY_SYSPM_MODE_DEEPSLEEP_RAM:
            {
                deepSleepWakeMode = CY_SYSPM_WARM_BOOT_MODE;
            }
            break;

            case CY_SYSPM_MODE_DEEPSLEEP_OFF:
            {
                deepSleepWakeMode = CY_SYSPM_COLD_BOOT_MODE;
            }
            break;

            default:
            {
                deepSleepWakeMode = CY_SYSPM_POR_BOOT_MODE;
            }
            break;
        }

    }

    return ((cy_en_syspm_boot_mode_t)deepSleepWakeMode);
}

/*Weak declaration allows for both RTOS and non-RTOS based
 * implementation to handle any context store before WFI
 * This PDL implements a weak handler for non-RTOS based deep sleep */
__WEAK void Cy_SysPm_StoreDSContext_Wfi(void)
{
    __WFI();
}

cy_en_syspm_status_t Cy_SysPm_CpuEnterDeepSleep(cy_en_syspm_waitfor_t waitFor)
{
    uint32_t interruptState;
    uint32_t cbDeepSleepRootIdx = (uint32_t) Cy_SysPm_GetDeepSleepMode();
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    CY_ASSERT_L3(CY_SYSPM_IS_WAIT_FOR_VALID(waitFor));
    CY_ASSERT_L3(CY_SYSPM_IS_DEEPSLEEP_MODE_VALID(cbDeepSleepRootIdx));

    //Check if LPM is ready
    if(!Cy_SysPm_IsLpmReady())
    {
        retVal = CY_SYSPM_FAIL;
    }
    else
    {
        /* Call the registered callback functions with the CY_SYSPM_CHECK_READY
        *  parameter
        */
        if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
        {
            retVal = Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_CHECK_READY);
        }

        /* The CPU can switch into the Deep Sleep power mode only when
        *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
        *  parameter return CY_SYSPM_SUCCESS
        */
        if (retVal == CY_SYSPM_SUCCESS)
        {
            /* Call the registered callback functions with the
            * CY_SYSPM_BEFORE_TRANSITION parameter
            */
            interruptState = Cy_SysLib_EnterCriticalSection();
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_BEFORE_TRANSITION);
            }

            /* Clear Reset reason before entering DS */
            Cy_SysLib_ClearResetReason();

            /* The CPU enters Deep Sleep mode upon execution of WFI/WFE
                * use Cy_SysPm_SetDeepSleepMode to set various deepsleep modes TBD*/
            SCB_SCR |= SCB_SCR_SLEEPDEEP_Msk;
            __DSB();                   /* Ensure completion of memory access */

        #if defined (__FPU_PRESENT) && (__FPU_PRESENT == 1U)
            /* Disable FPU for CM33 for DS-RAM/DS-OFF Entry to work.
             * FPU power domain is enabled by HW and SW should always disable it to
             * enter into DS_RAM/OFF modes.
             */
            if(((uint32_t)CY_SYSPM_MODE_DEEPSLEEP_RAM == cbDeepSleepRootIdx) || ((uint32_t)CY_SYSPM_MODE_DEEPSLEEP_OFF == cbDeepSleepRootIdx))
            {
                SCS_CPPWR |= (SCS_ENABLE_CPPWR_SU10_SU11);
                SCB_CPACR &= ~(SCB_ENABLE_CPACR_CP10_CP11);
                __DSB();                   /* Ensure completion of memory access */
            }
        #endif /* defined (__FPU_PRESENT) && (__FPU_PRESENT == 1U) */

            if(waitFor != CY_SYSPM_WAIT_FOR_EVENT)
            {
                if (cbDeepSleepRootIdx == (uint32_t)CY_SYSPM_MODE_DEEPSLEEP_RAM)
                {
                    Cy_SysPm_StoreDSContext_Wfi();
                }
                else
                {
                    __WFI();
                }
            }
            else
            {
                __WFE();
            }

        #if defined (__FPU_USED) && (__FPU_USED == 1U)

            /* Enable back FPU if it was used for CM33 in case of DS-RAM/DS-OFF.
             *
             * This is not required for DS-RAM/DS-OFF  because device should goes to reset after __WFI.
             * If requirements for entering into DS-RAM/DS-OFF were not met (for example, active debug session),
             * the device will operate as in normal deep sleep mode.
             * Because of that FPU is re-enabling.
             */
            if(((uint32_t)CY_SYSPM_MODE_DEEPSLEEP_RAM == cbDeepSleepRootIdx) || ((uint32_t)CY_SYSPM_MODE_DEEPSLEEP_OFF == cbDeepSleepRootIdx))
            {
                SCS_CPPWR &= ~(SCS_ENABLE_CPPWR_SU10_SU11);
                SCB->CPACR |= SCB_ENABLE_CPACR_CP10_CP11;
                __DSB();                   /* Ensure completion of memory access */
            }
        #endif /* defined (__FPU_USED) && (__FPU_USED == 1U) */

            /* Clear SCB_SCR_SLEEPDEEP flag */
            SCB_SCR &= (uint32_t) ~SCB_SCR_SLEEPDEEP_Msk;

            /* Call the registered callback functions with the CY_SYSPM_AFTER_DS_WFI_TRANSITION
            *  parameter
            */
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_AFTER_DS_WFI_TRANSITION);
            }

            Cy_SysLib_ExitCriticalSection(interruptState);
        }
        if (retVal == CY_SYSPM_SUCCESS)
        {
            /* Call the registered callback functions with the CY_SYSPM_AFTER_TRANSITION
            *  parameter
            */
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_AFTER_TRANSITION);
            }
        }
        else
        {
            /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
            *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
            *  parameter
            */
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_CHECK_FAIL);
            }
        }
    }
    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SetupDeepSleepRAM(cy_en_syspm_dsram_checks_t dsramCheck, uint32_t *dsramIntState)
{
    uint32_t cbDeepSleepRootIdx = (uint32_t) Cy_SysPm_GetDeepSleepMode();
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    CY_ASSERT_L3(CY_SYSPM_IS_DSRAM_CHECK_VALID(dsramCheck));
    CY_ASSERT_L3(CY_SYSPM_IS_DEEPSLEEP_MODE_VALID(cbDeepSleepRootIdx));

    //Check if LPM is ready
    if(!Cy_SysPm_IsLpmReady())
    {
        retVal = CY_SYSPM_FAIL;
    }
    else
    {
        if(dsramCheck == CY_SYSPM_PRE_DSRAM)
        {
            /* Clear the Warm Boot Entry status Flag */
            Cy_SysLib_ClearDSRAMWarmBootEntryStatus();

            /* Call the registered callback functions with the CY_SYSPM_CHECK_READY
            *  parameter
            */
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                retVal = Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_CHECK_READY);
            }

            /* The CPU can switch into the Deep Sleep power mode only when
            *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
            *  parameter return CY_SYSPM_SUCCESS
            */
            if (retVal == CY_SYSPM_SUCCESS)
            {
                /* Call the registered callback functions with the
                * CY_SYSPM_BEFORE_TRANSITION parameter
                */
                *dsramIntState = Cy_SysLib_EnterCriticalSection();

                if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
                {
                    (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_BEFORE_TRANSITION);
                }
                    /* The CPU enters Deep Sleep mode upon execution of WFI/WFE
                     * use Cy_SysPm_SetDeepSleepMode to set various deepsleep modes TBD*/
                    SCB_SCR |= SCB_SCR_SLEEPDEEP_Msk;
                    __DSB();                   /* Ensure completion of memory access */

            }
            else
            {
                /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
                *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
                *  parameter
                */
                if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
                {
                    (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_CHECK_FAIL);
                }
            }
        }
        else
        {
            /* Clear SCB_SCR_SLEEPDEEP flag */
            SCB_SCR &= (uint32_t) ~SCB_SCR_SLEEPDEEP_Msk;

            /* Call the registered callback functions with the CY_SYSPM_AFTER_DS_WFI_TRANSITION
            *  parameter
            */
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_AFTER_DS_WFI_TRANSITION);
            }

            Cy_SysLib_ExitCriticalSection(*dsramIntState);

            /* Call the registered callback functions with the CY_SYSPM_AFTER_TRANSITION
            *  parameter
            */
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_AFTER_TRANSITION);
            }
        }
    }
    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemEnterHibernate(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    uint32_t cbHibernateRootIdx = (uint32_t) CY_SYSPM_HIBERNATE;
    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbHibernateRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_HIBERNATE, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into Hibernate power mode only when
    *  all executed registered callback functions with CY_SYSPM_CHECK_READY
    *  parameter return CY_SYSPM_SUCCESS.
    */
    if(retVal == CY_SYSPM_SUCCESS)
    {
        /* Call registered callback functions with CY_SYSPM_BEFORE_TRANSITION
        *  parameter
        */
        (void) Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbHibernateRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_HIBERNATE, CY_SYSPM_BEFORE_TRANSITION);
        }

        /* Preserve the token that will be retained through a wakeup sequence.
         * This could be used by Cy_SysLib_GetResetReason() to differentiate
         * Wakeup from a general reset event.
         * Preserve the wakeup source(s) configuration.
         */
        SRSS_PWR_HIBERNATE = (SRSS_PWR_HIBERNATE  | HIBERNATE_TOKEN);

        /* Clear Previous Wakeup Reasons */
        Cy_SysPm_ClearHibernateWakeupCause();

        /* Disable overriding by the peripherals the next pin-freeze command */
        SRSS_PWR_HIBERNATE |= SET_HIBERNATE_MODE;

        /* The second write causes freezing of I/O cells to save the I/O-cell state */
        SRSS_PWR_HIBERNATE |= SET_HIBERNATE_MODE;

        /* Third write cause system to enter Hibernate */
        SRSS_PWR_HIBERNATE |= SET_HIBERNATE_MODE;

        /* Read register to make sure it is settled */
        (void) SRSS_PWR_HIBERNATE;

        /* Wait for transition */
        __WFI();

        /* The callback function calls with the CY_SYSPM_AFTER_TRANSITION
        * parameter in the Hibernate power mode are not applicable as system
        * wake-up was made on system reboot.
        */

        /* A wakeup from Hibernate is performed by toggling of the wakeup
        * pins, or WDT matches, or Backup domain alarm expires. This depends on
        * what item is configured in the Hibernate register. After a wakeup
        * event, a normal Boot procedure occurs.
        * There is no need to exit from the critical section.
        */
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter. The return value should be CY_SYSPM_SUCCESS.
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_HIBERNATE, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }
    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemSetMinRegulatorCurrent(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_CANCELED;

    /* Check if the power circuits are ready to enter into regulator minimum
    *  current mode
    */
    if (Cy_SysPm_IsLpmReady())
    {
        SRSS_PWR_CTL2 |= (SRSS_PWR_CTL2_LINREG_LPMODE_Msk |
                          SRSS_PWR_CTL2_PORBOD_LPMODE_Msk |
                          SRSS_PWR_CTL2_BGREF_LPMODE_Msk |
                          SRSS_PWR_CTL2_REFI_LPMODE_Msk);

        /* This wait time allows the circuits to remove their dependence on
        *  the Active mode circuits, such as active Reference
        */
        Cy_SysLib_DelayUs(SET_MIN_CURRENT_MODE_DELAY_US);

        /* Disable active reference */
        SRSS_PWR_CTL2 |= SRSS_PWR_CTL2_REFV_DIS_Msk;

        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemSetNormalRegulatorCurrent(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;

    uint32_t timeOut = WAIT_DELAY_TRIES;

    /* Configure the regulator normal current mode for the POR/BOD circuits
    *  and for the Voltage References
    */

    /* Bring Regulators Power Circuit out of LPMODE */
    SRSS_PWR_CTL2 &= (uint32_t)~(SRSS_PWR_CTL2_REFV_DIS_Msk      |
                                 SRSS_PWR_CTL2_LINREG_LPMODE_Msk |
                                 SRSS_PWR_CTL2_PORBOD_LPMODE_Msk |
                                 SRSS_PWR_CTL2_REFI_LPMODE_Msk);

    /* This wait time allows setting active Reference */
    Cy_SysLib_DelayUs(ACT_REF_SETTLE_DELAY_US);

    while ((0U == _FLD2VAL(SRSS_PWR_CTL2_REFV_OK, SRSS_PWR_CTL2)) && (0U != timeOut))
    {
        timeOut--;
    }

    if (0U != timeOut)
    {
        /* Disable the low-power for Bandgap reference circuit */
        SRSS_PWR_CTL2 &= (uint32_t) ~SRSS_PWR_CTL2_BGREF_LPMODE_Msk;

        /* Delay to finally set the normal current mode */
        Cy_SysLib_DelayUs(SET_NORMAL_CURRENT_MODE_DELAY_US);

        retVal= CY_SYSPM_SUCCESS;
    }

    return retVal;
}

bool Cy_SysPm_SystemIsMinRegulatorCurrentSet(void)
{
#if (defined (CY_IP_MXS40SSRSS) && (SRSS_S40S_REGSETB_PRESENT == 1UL))
    uint32_t regMask = Cy_SysPm_LdoIsEnabled() ? CY_SYSPM_PWR_CIRCUITS_LPMODE_ACTIVE_LDO_MASK : CY_SYSPM_PWR_CIRCUITS_LPMODE_ACTIVE_BUCK_MASK;

    return ((SRSS_PWR_CTL & regMask) == regMask);
#else
    return ((0U == _FLD2VAL(SRSS_PWR_CTL2_REFV_DIS, SRSS_PWR_CTL2)) ? false : true);
#endif
}

cy_en_syspm_status_t Cy_SysPm_LdoSetMode(cy_en_syspm_ldo_mode_t mode)
{
    CY_ASSERT_L3(CY_SYSPM_IS_LDO_MODE_VALID(mode));

    cy_en_syspm_status_t retVal = CY_SYSPM_CANCELED;

    switch (mode)
    {
        case CY_SYSPM_LDO_MODE_NORMAL:
        {
            retVal = Cy_SysPm_SystemSetNormalRegulatorCurrent();
        }
        break;

        case CY_SYSPM_LDO_MODE_MIN:
        {
            retVal = Cy_SysPm_SystemSetMinRegulatorCurrent();
        }
        break;

        case CY_SYSPM_LDO_MODE_DISABLED:
        {
            /* Disable the LDO, Deep Sleep and Retention regulators */
            SRSS_PWR_CTL2 |= (_VAL2FLD(SRSS_PWR_CTL2_DPSLP_REG_DIS, 1U) |
                             _VAL2FLD(SRSS_PWR_CTL2_RET_REG_DIS, 1U) |
                             _VAL2FLD(SRSS_PWR_CTL2_LINREG_DIS, 1U));

            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        default:
            retVal = CY_SYSPM_FAIL;
        break;
    }

    return retVal;
}

cy_en_syspm_ldo_mode_t Cy_SysPm_LdoGetMode(void)
{
    cy_en_syspm_ldo_mode_t retVal;

    if (!Cy_SysPm_LdoIsEnabled())
    {
        retVal = CY_SYSPM_LDO_MODE_DISABLED;
    }
    else if (Cy_SysPm_SystemIsMinRegulatorCurrentSet())
    {
        retVal = CY_SYSPM_LDO_MODE_MIN;
    }
    else
    {
        retVal = CY_SYSPM_LDO_MODE_NORMAL;
    }

    return retVal;
}

bool Cy_SysPm_LdoIsEnabled(void)
{
    return ((0U != _FLD2VAL(SRSS_PWR_CTL2_LINREG_DIS, SRSS_PWR_CTL2)) ? false : true);
}

#if defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)

cy_en_syspm_status_t Cy_SysPm_LdoSetVoltage(cy_en_syspm_ldo_voltage_t voltage)
{
    CY_ASSERT_L1(CY_SYSPM_IS_LDO_VOLTAGE_VALID(voltage));

    cy_en_syspm_status_t retVal = CY_SYSPM_INVALID_STATE;

    /* Voltage change is possible only when the specific device revision
    * support registers modification.
    */
    if (IsVoltageChangePossible())
    {
        uint32_t interruptState;
        uint32_t trimVoltage;
        cy_en_syspm_ldo_voltage_t currVoltage = Cy_SysPm_LdoGetVoltage();

        interruptState = Cy_SysLib_EnterCriticalSection();

        if (CY_SYSPM_LDO_VOLTAGE_0_9V == voltage)
        {
            SRSS_PWR_TRIM_WAKE_CTL = _FLD2VAL(SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_0P9V, SFLASH_PWR_TRIM_WAKE_CTL);

            trimVoltage =  SFLASH_LDO_0P9V_TRIM;

            /* Update read-write margin value for the ULP mode */
            SetReadMarginTrimUlp();
        }
        else if(CY_SYSPM_LDO_VOLTAGE_1_0V == voltage)
        {
            if (Cy_SysPm_SystemIsMinRegulatorCurrentSet())
            {
                SRSS_PWR_TRIM_WAKE_CTL = SRSS_PWR_TRIM_WAKE_MF;
            }
            else
            {
                SRSS_PWR_TRIM_WAKE_CTL = _FLD2VAL(SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_1P0V, SFLASH_PWR_TRIM_WAKE_CTL);
            }

            trimVoltage = SFLASH_LDO_1P0V_TRIM;

            /* A delay for the supply to stabilize at the new higher voltage */
            Cy_SysLib_DelayUs(LDO_TO_1_0V_DELAY_US);

            if(currVoltage > CY_SYSPM_LDO_VOLTAGE_1_0V)
            {
                /* Update read-write margin value for the MF mode */
                SetReadMarginTrimMf();
            }
            else
            {
                /* Update write assist value for the MF mode */
                SetWriteAssistTrimMf();
            }
        }
        else if(CY_SYSPM_LDO_VOLTAGE_1_1V == voltage)
        {
            if (Cy_SysPm_SystemIsMinRegulatorCurrentSet())
            {
                SRSS_PWR_TRIM_WAKE_CTL = SRSS_PWR_TRIM_WAKE_LP;
            }
            else
            {
                SRSS_PWR_TRIM_WAKE_CTL = _FLD2VAL(SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_1P1V, SFLASH_PWR_TRIM_WAKE_CTL);
            }

            trimVoltage = SFLASH_LDO_1P1V_TRIM;
            /* A delay for the supply to stabilize at the new higher voltage */
            Cy_SysLib_DelayUs(LDO_TO_1_1V_DELAY_US);

            if(currVoltage < CY_SYSPM_LDO_VOLTAGE_1_1V)
            {
                /* Update read-write margin value for the LP mode */
                SetReadMarginTrimLp();
            }
            else
            {
                /* Update write assist value for the LP mode */
                SetWriteAssistTrimLp();
            }
        }
        else
        {
            if (Cy_SysPm_SystemIsMinRegulatorCurrentSet())
            {
                SRSS_PWR_TRIM_WAKE_CTL = SRSS_PWR_TRIM_WAKE_OD;
            }
            else
            {
                SRSS_PWR_TRIM_WAKE_CTL = _FLD2VAL(SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_1P2V, SFLASH_PWR_TRIM_WAKE_CTL);
            }

            trimVoltage = SFLASH_LDO_1P2V_TRIM;

            /* A delay for the supply to stabilize at the new higher voltage */
            Cy_SysLib_DelayUs(LDO_TO_1_2V_DELAY_US);

            /* Update write assist value for the OD mode */
            SetWriteAssistTrimOd();
        }

        /* The system may continue operating while the voltage on Vccd
        *  discharges to the new voltage. The time it takes to reach the
        *  new voltage depends on the conditions, including the load current
        *  on Vccd and the external capacitor size.
        */
        SRSS_PWR_TRIM_PWRSYS_CTL =
        _CLR_SET_FLD32U((SRSS_PWR_TRIM_PWRSYS_CTL), SRSS_PWR_TRIM_PWRSYS_CTL_ACT_REG_TRIM, trimVoltage);

        if (CY_SYSPM_LDO_VOLTAGE_0_9V == voltage)
        {
            /* Update write assist value for the ULP mode */
            SetWriteAssistTrimUlp();
        }
        else if(CY_SYSPM_LDO_VOLTAGE_1_0V == voltage)
        {
            /* A delay for the supply to stabilize at the new intermediate voltage */
            Cy_SysLib_DelayUs(LDO_TO_1_0V_DELAY_US);

            if(currVoltage > CY_SYSPM_LDO_VOLTAGE_1_1V)
            {
                /* Update write assist value for the MF mode */
                SetWriteAssistTrimMf();
            }
            else
            {
                /* Update read-write margin value for the MF mode */
                SetReadMarginTrimMf();
            }
        }
        else if(CY_SYSPM_LDO_VOLTAGE_1_1V == voltage)
        {
            /* A delay for the supply to stabilize at the new intermediate voltage */
            Cy_SysLib_DelayUs(LDO_TO_1_1V_DELAY_US);
            if(currVoltage > CY_SYSPM_LDO_VOLTAGE_1_1V)
            {
                /* Update write assist value for the LP mode */
                SetWriteAssistTrimLp();
            }
            else
            {
                /* Update read-write margin value for the LP mode */
                SetReadMarginTrimLp();
            }
        }
        else
        {
            /* A delay for the supply to stabilize at the new intermediate voltage */
            Cy_SysLib_DelayUs(LDO_TO_1_2V_DELAY_US);

            /* Update read-write margin value for the OD mode */
            SetReadMarginTrimOd();
        }

        Cy_SysLib_ExitCriticalSection(interruptState);
        retVal = CY_SYSPM_SUCCESS;
    }
    return retVal;
}

cy_en_syspm_ldo_voltage_t Cy_SysPm_LdoGetVoltage(void)
{
    uint32_t curVoltage;

    curVoltage = _FLD2VAL(SRSS_PWR_TRIM_PWRSYS_CTL_ACT_REG_TRIM, SRSS_PWR_TRIM_PWRSYS_CTL);

    return ((curVoltage == (SFLASH_LDO_0P9V_TRIM)) ? CY_SYSPM_LDO_VOLTAGE_ULP :
            (curVoltage == (SFLASH_LDO_1P0V_TRIM)) ? CY_SYSPM_LDO_VOLTAGE_MF :
            (curVoltage == (SFLASH_LDO_1P2V_TRIM)) ? CY_SYSPM_LDO_VOLTAGE_OD :
                                                                                 CY_SYSPM_LDO_VOLTAGE_LP);

}
#endif

void Cy_SysPm_CpuSleepOnExit(bool enable)
{
    if(enable)
    {
        /* Enable sleep-on-exit feature */
        SCB_SCR |= SCB_SCR_SLEEPONEXIT_Msk;
    }
    else
    {
        /* Disable sleep-on-exit feature */
        SCB_SCR &= (uint32_t) ~(SCB_SCR_SLEEPONEXIT_Msk);
    }
}

void Cy_SysPm_SetHibernateWakeupSource(uint32_t wakeupSource)
{
    CY_ASSERT_L3(CY_SYSPM_IS_WAKE_UP_SOURCE_VALID(wakeupSource));

    uint32_t polarityMask = 0U;
    uint32_t wakeSrcMask = 0U;

    /* LPCOMP0 & LPCOMP1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_MASK;
    }

    /* PIN0 & PIN1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN1_MASK;
    }

    /* RTC */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_RTC_ALARM))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_RTC_MASK;
    }

    /* WDT */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_WDT))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_WDT_MASK;
    }

    /* Polarity Mask */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK;
    }

    SRSS_PWR_HIB_WAKE_CTL = (SRSS_PWR_HIB_WAKE_CTL | wakeSrcMask);
    SRSS_PWR_HIB_WAKE_CTL2 = (SRSS_PWR_HIB_WAKE_CTL2 | polarityMask);

    /* Read registers to make sure it is settled */
    (void) SRSS_PWR_HIB_WAKE_CTL;
    (void) SRSS_PWR_HIB_WAKE_CTL2;

}

void Cy_SysPm_ClearHibernateWakeupSource(uint32_t wakeupSource)
{
    CY_ASSERT_L3(CY_SYSPM_IS_WAKE_UP_SOURCE_VALID(wakeupSource));

    uint32_t polarityMask = 0U;
    uint32_t wakeSrcMask = 0U;

    /* LPCOMP0 & LPCOMP1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_MASK;
    }

    /* PIN0 & PIN1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN1_MASK;
    }

    /* RTC */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_RTC_ALARM))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_RTC_MASK;
    }

    /* WDT */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_WDT))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_WDT_MASK;
    }

    /* Polarity Mask */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK;
    }

    SRSS_PWR_HIB_WAKE_CTL = (SRSS_PWR_HIB_WAKE_CTL & (~wakeSrcMask));
    SRSS_PWR_HIB_WAKE_CTL2 = (SRSS_PWR_HIB_WAKE_CTL2 & (~polarityMask));

    /* Read registers to make sure it is settled */
    (void) SRSS_PWR_HIB_WAKE_CTL;
    (void) SRSS_PWR_HIB_WAKE_CTL2;
}

cy_en_syspm_hibernate_wakeup_source_t Cy_SysPm_GetHibernateWakeupCause(void)
{
    uint32_t wakeupCause;
    uint32_t wakeupCausePolarity;

    wakeupCause = SRSS_PWR_HIB_WAKE_CAUSE;

    wakeupCausePolarity = (wakeupCause & (uint32_t)(CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK |
                                          CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK |
                                          CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK    |
                                          CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK ));

    switch(wakeupCause)
    {
        case CY_SYSPM_HIB_WAKEUP_PIN0_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN0_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_PIN1_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN1_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_RTC_MASK:
        {
            wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_RTC_ALARM);
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_WDT_MASK:
        {
            wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_WDT);
        }
        break;

        default:
            CY_ASSERT_L2(false);
        break;
    }

    return (cy_en_syspm_hibernate_wakeup_source_t)wakeupCause;
}

void Cy_SysPm_ClearHibernateWakeupCause(void)
{
    uint32_t temp = SRSS_PWR_HIB_WAKE_CAUSE;
    SRSS_PWR_HIB_WAKE_CAUSE = temp;
}

cy_en_syspm_status_t Cy_SysPm_CoreBuckSetVoltage(cy_en_syspm_core_buck_voltage_t voltage)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(voltage));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL, SRSS_PWR_CBUCK_CTL_CBUCK_VSEL, voltage);

    /* Since voltage is changed , use it for the CBUCK setting decision */
    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL2, SRSS_PWR_CBUCK_CTL2_CBUCK_USE_SETTINGS, 1UL);

    return Cy_SysPm_CoreBuckStatus();
}

cy_en_syspm_core_buck_voltage_t Cy_SysPm_CoreBuckGetVoltage(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_voltage_t enum.');
    return (cy_en_syspm_core_buck_voltage_t)(_FLD2VAL(SRSS_PWR_CBUCK_CTL_CBUCK_VSEL, SRSS_PWR_CBUCK_CTL));
}

void Cy_SysPm_CoreBuckSetMode(cy_en_syspm_core_buck_mode_t mode)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_MODE_VALID(mode));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL, SRSS_PWR_CBUCK_CTL_CBUCK_MODE, mode);
}

cy_en_syspm_core_buck_mode_t Cy_SysPm_CoreBuckGetMode(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_mode_t enum.');
    return (cy_en_syspm_core_buck_mode_t)(_FLD2VAL(SRSS_PWR_CBUCK_CTL_CBUCK_MODE, SRSS_PWR_CBUCK_CTL));
}

void Cy_SysPm_CoreBuckSetInrushLimit(cy_en_syspm_core_inrush_limit_t inrushLimit)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_INRUSH_LIMIT_VALID(inrushLimit));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL3, SRSS_PWR_CBUCK_CTL3_CBUCK_INRUSH_SEL, inrushLimit);
}

cy_en_syspm_core_inrush_limit_t Cy_SysPm_CoreBuckGetInrushLimit(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_inrush_limit_t enum.');
    return (cy_en_syspm_core_inrush_limit_t)(_FLD2VAL(SRSS_PWR_CBUCK_CTL3_CBUCK_INRUSH_SEL, SRSS_PWR_CBUCK_CTL3));
}

cy_en_syspm_status_t Cy_SysPm_CoreBuckConfig(cy_stc_syspm_core_buck_params_t *config)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(config->voltageSel));
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_MODE_VALID(config->mode));
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_INRUSH_LIMIT_VALID(config->inRushLimitSel));

    SRSS_PWR_CBUCK_CTL = _VAL2FLD(SRSS_PWR_CBUCK_CTL_CBUCK_VSEL, config->voltageSel) |
                         _VAL2FLD(SRSS_PWR_CBUCK_CTL_CBUCK_MODE, config->mode);

    SRSS_PWR_CBUCK_CTL2 = _VAL2FLD(SRSS_PWR_CBUCK_CTL2_CBUCK_OVERRIDE, ((config->override) ? 1UL : 0UL)) |
                         _VAL2FLD(SRSS_PWR_CBUCK_CTL2_CBUCK_COPY_SETTINGS, ((config->copySettings) ? 1UL : 0UL)) |
                         _VAL2FLD(SRSS_PWR_CBUCK_CTL2_CBUCK_USE_SETTINGS, ((config->useSettings) ? 1UL : 0UL));

    SRSS_PWR_CBUCK_CTL3 = _VAL2FLD(SRSS_PWR_CBUCK_CTL3_CBUCK_INRUSH_SEL, config->inRushLimitSel);

    /* Check if the CBUCK transition is Successful */
    return Cy_SysPm_CoreBuckStatus();
}

cy_en_syspm_status_t Cy_SysPm_CoreBuckStatus(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;
    uint32_t syspmCbuckRetry = CY_SYSPM_CBUCK_BUSY_RETRY_COUNT;

    while((_FLD2VAL(SRSS_PWR_CBUCK_STATUS_PMU_DONE, SRSS_PWR_CBUCK_STATUS) == 0U) && (syspmCbuckRetry != 0U))
    {
        syspmCbuckRetry--;
        Cy_SysLib_Delay(CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_MS);
    }

    if(syspmCbuckRetry != 0UL)
    {
        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;
}

#ifdef ENABLE_MEM_VOLTAGE_TRIMS
void Cy_SysPm_SdrConfigure(cy_en_syspm_sdr_t sdr, cy_stc_syspm_sdr_params_t *config)
{
    CY_ASSERT_L2(CY_SYSPM_IS_SDR_NUM_VALID(sdr));
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(config->coreBuckVoltSel));
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_MODE_VALID(config->coreBuckMode));
    CY_ASSERT_L2(CY_SYSPM_IS_SDR_VOLTAGE_VALID(config->sdrVoltSel));

    CY_SYSPM_CORE_BUCK_PAUSE_ENABLE(1U);

    if(sdr == CY_SYSPM_SDR_0)
    {
        cy_en_syspm_sdr_voltage_t currSdr0Volt = Cy_SysPm_SdrGetVoltage(CY_SYSPM_SDR_0);

        CY_ASSERT_L2(CY_SYSPM_IS_SDR_VOLTAGE_VALID(config->sdr0DpSlpVoltSel));
        CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(config->coreBuckDpSlpVoltSel));
        CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_MODE_VALID(config->coreBuckDpSlpMode));

        /* High to Low voltage --> TRIM first , Set Voltage next */
        if(config->sdrVoltSel < ((uint8_t)currSdr0Volt))
        {
            if(IsVoltageChangePossible())
            {
                SetMemoryVoltageTrims((cy_en_syspm_sdr_voltage_t)config->sdrVoltSel);
            }

            SRSS_PWR_SDR0_CTL =  _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_VSEL, config->coreBuckVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_MODE, config->coreBuckMode) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_VSEL, config->sdrVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_DPSLP_VSEL, config->coreBuckDpSlpVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_DPSLP_MODE, config->coreBuckDpSlpMode) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_DPSLP_VSEL, config->sdr0DpSlpVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_ALLOW_BYPASS, ((config->sdr0Allowbypass) ? 1UL : 0UL));

        }
        else if(config->sdrVoltSel > ((uint8_t)currSdr0Volt))  /* Low to High voltage --> Set Voltage first , Trim next */
        {
            SRSS_PWR_SDR0_CTL =  _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_VSEL, config->coreBuckVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_MODE, config->coreBuckMode) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_VSEL, config->sdrVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_DPSLP_VSEL, config->coreBuckDpSlpVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_DPSLP_MODE, config->coreBuckDpSlpMode) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_DPSLP_VSEL, config->sdr0DpSlpVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_ALLOW_BYPASS, ((config->sdr0Allowbypass) ? 1UL : 0UL));

            if(IsVoltageChangePossible())
            {
                SetMemoryVoltageTrims((cy_en_syspm_sdr_voltage_t)config->sdrVoltSel);
            }
        }
        else
        {
            SRSS_PWR_SDR0_CTL =  _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_VSEL, config->coreBuckVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_MODE, config->coreBuckMode) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_VSEL, config->sdrVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_DPSLP_VSEL, config->coreBuckDpSlpVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_DPSLP_MODE, config->coreBuckDpSlpMode) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_DPSLP_VSEL, config->sdr0DpSlpVoltSel) |
                              _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_ALLOW_BYPASS, ((config->sdr0Allowbypass) ? 1UL : 0UL));
        }
    }
    else
    {
        SRSS_PWR_SDR1_CTL =  _VAL2FLD(SRSS_PWR_SDR1_CTL_SDR1_CBUCK_VSEL, config->coreBuckVoltSel) |
                             _VAL2FLD(SRSS_PWR_SDR1_CTL_SDR1_CBUCK_MODE, config->coreBuckMode) |
                             _VAL2FLD(SRSS_PWR_SDR1_CTL_SDR1_VSEL, config->sdrVoltSel) |
                             _VAL2FLD(SRSS_PWR_SDR1_CTL_SDR1_HW_SEL, ((config->sdr1HwControl) ? 1UL : 0UL)) |
                             _VAL2FLD(SRSS_PWR_SDR1_CTL_SDR1_ENABLE, ((config->sdr1Enable) ? 1UL : 0UL));
    }

    CY_SYSPM_CORE_BUCK_PAUSE_ENABLE(0U);
}

void Cy_SysPm_SdrSetVoltage(cy_en_syspm_sdr_t sdr, cy_en_syspm_sdr_voltage_t voltage)
{
    CY_ASSERT_L2(CY_SYSPM_IS_SDR_NUM_VALID(sdr));
    CY_ASSERT_L2(CY_SYSPM_IS_SDR_VOLTAGE_VALID(voltage));

    CY_SYSPM_CORE_BUCK_PAUSE_ENABLE(1U);

    if(sdr == CY_SYSPM_SDR_0)
    {
        cy_en_syspm_sdr_voltage_t currSdr0Volt = Cy_SysPm_SdrGetVoltage(CY_SYSPM_SDR_0);
        /* High to Low voltage --> Set TRIM's first , Set Voltage next */
        if(voltage < currSdr0Volt)
        {
            if(IsVoltageChangePossible())
            {
                SetMemoryVoltageTrims(voltage);
            }

            CY_REG32_CLR_SET(SRSS_PWR_SDR0_CTL, SRSS_PWR_SDR0_CTL_SDR0_VSEL, voltage);
        }
        /* Low to High voltage --> Set Voltage first , Set TRIM's next */
        else if (voltage > currSdr0Volt)
        {
            CY_REG32_CLR_SET(SRSS_PWR_SDR0_CTL, SRSS_PWR_SDR0_CTL_SDR0_VSEL, voltage);

            if(IsVoltageChangePossible())
            {
                SetMemoryVoltageTrims(voltage);
            }
        }
        else
        {
        }
    }
    else
    {
        CY_REG32_CLR_SET(SRSS_PWR_SDR1_CTL, SRSS_PWR_SDR1_CTL_SDR1_VSEL, voltage);
    }

    CY_SYSPM_CORE_BUCK_PAUSE_ENABLE(0U);
}
#endif /* ENABLE_MEM_VOLTAGE_TRIMS */

cy_en_syspm_sdr_voltage_t Cy_SysPm_SdrGetVoltage(cy_en_syspm_sdr_t sdr)
{
    CY_ASSERT_L2(CY_SYSPM_IS_SDR_NUM_VALID(sdr));

    if(sdr == CY_SYSPM_SDR_0)
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_sdr_voltage_t enum.');
        return (cy_en_syspm_sdr_voltage_t)(_FLD2VAL(SRSS_PWR_SDR0_CTL_SDR0_VSEL, SRSS_PWR_SDR0_CTL));
    }
    else
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_sdr_voltage_t enum.');
        return (cy_en_syspm_sdr_voltage_t)(_FLD2VAL(SRSS_PWR_SDR1_CTL_SDR1_VSEL, SRSS_PWR_SDR1_CTL));
    }
}

void Cy_SysPm_SdrEnable(cy_en_syspm_sdr_t sdr, bool enable)
{
    CY_ASSERT_L2(CY_SYSPM_IS_SDR_NUM_VALID(sdr));

    if(sdr == CY_SYSPM_SDR_1)
    {
        CY_REG32_CLR_SET(SRSS_PWR_SDR1_CTL, SRSS_PWR_SDR1_CTL_SDR1_ENABLE, ((enable) ? 1UL : 0UL));
    }
}

bool Cy_SysPm_IsSdrEnabled(cy_en_syspm_sdr_t sdr)
{
    CY_ASSERT_L2(CY_SYSPM_IS_SDR_NUM_VALID(sdr));
    if(sdr == CY_SYSPM_SDR_0)
    {
        return (_FLD2BOOL(SRSS_PWR_SDR0_CTL_SDR0_ALLOW_BYPASS, SRSS_PWR_SDR0_CTL)? false : true);
    }
    else
    {
        return (_FLD2BOOL(SRSS_PWR_SDR1_CTL_SDR1_ENABLE, SRSS_PWR_SDR1_CTL)? true : false);
    }
}

void Cy_SysPm_HvLdoConfigure(cy_stc_syspm_hvldo_params_t *config)
{
    CY_ASSERT_L2(CY_SYSPM_IS_HVLDO_VOLTAGE_VALID(config->voltageSel));

    SRSS_PWR_HVLDO0_CTL = _VAL2FLD(SRSS_PWR_HVLDO0_CTL_HVLDO0_VSEL, config->voltageSel) |
                          _VAL2FLD(SRSS_PWR_HVLDO0_CTL_HVLDO0_HW_SEL, ((config->hwSel) ? 1UL : 0UL)) |
                          _VAL2FLD(SRSS_PWR_HVLDO0_CTL_HVLDO0_ENABLE, ((config->hvldoEnable) ? 1UL : 0UL));
}

void Cy_SysPm_HvLdoEnable(bool enable)
{
    CY_REG32_CLR_SET(SRSS_PWR_HVLDO0_CTL, SRSS_PWR_HVLDO0_CTL_HVLDO0_ENABLE, ((enable) ? 1UL : 0UL));
}

bool Cy_SysPm_IsHvLdoEnabled(void)
{
    return (_FLD2BOOL(SRSS_PWR_HVLDO0_CTL_HVLDO0_ENABLE, SRSS_PWR_HVLDO0_CTL)? true : false);
}

void Cy_SysPm_HvLdoSetVoltage(cy_en_syspm_hvldo_voltage_t voltage)
{
    CY_ASSERT_L2(CY_SYSPM_IS_HVLDO_VOLTAGE_VALID(voltage));

    CY_REG32_CLR_SET(SRSS_PWR_HVLDO0_CTL, SRSS_PWR_HVLDO0_CTL_HVLDO0_VSEL, voltage);
}

cy_en_syspm_hvldo_voltage_t Cy_SysPm_HvLdoGetVoltage(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_hvldo_voltage_t enum.');
    return (cy_en_syspm_hvldo_voltage_t)(_FLD2VAL(SRSS_PWR_HVLDO0_CTL_HVLDO0_VSEL, SRSS_PWR_HVLDO0_CTL));
}


cy_en_syspm_status_t Cy_SysPm_LdoExtraRequesterConfig(cy_stc_syspm_extraReq_params_t *extraReqConfig)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_FAIL;

    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(extraReqConfig->coreBuckVoltSel));
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(extraReqConfig->sdr0Config->coreBuckVoltSel));
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_MODE_VALID(extraReqConfig->sdr0Config->coreBuckMode));
    CY_ASSERT_L2(CY_SYSPM_IS_SDR_VOLTAGE_VALID(extraReqConfig->sdr0Config->sdrVoltSel));
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(extraReqConfig->sdr1Config->coreBuckVoltSel));
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_MODE_VALID(extraReqConfig->sdr1Config->coreBuckMode));
    CY_ASSERT_L2(CY_SYSPM_IS_SDR_VOLTAGE_VALID(extraReqConfig->sdr1Config->sdrVoltSel));


    /* Extra Requester Sequence */

    /* 1. Prevent dynamic setting changes by writing PWR_CBUCK_CTL.CBUCK_PAUSE=1. */
    CY_SYSPM_CORE_BUCK_PAUSE_ENABLE(1U);

    /* 2. Enable PWR_CBUCK_CTL.CBUCK_COPY_SETTINGS */
    CY_SYSPM_CORE_BUCK_COPY_SETTINGS_ENABLE(1U);

    /* 3. If the intention is to request higher operational state
     * (eg. higher CBUCK target voltage or higher CBUCK mode), load  the
     * desired settings into the extra requester
     * (PWR_CBUCK_CTL.CBUCK_VSEL/MODE). Do not reduce any of the
     * settings, because the intention is that the eventual
     * composite CBUCK mode matches the extra requester
     */
    (void)Cy_SysPm_CoreBuckSetVoltage((cy_en_syspm_core_buck_voltage_t)extraReqConfig->coreBuckVoltSel);

    (void)Cy_SysPm_CoreBuckSetMode((cy_en_syspm_core_buck_mode_t)extraReqConfig->coreBuckMode);

    /* 4. Override the normal harmonization logic which internally selects the
     * scratch profile using PWR_CBUCK_CTL.CBUCK_OVERRIDE).
     */
    CY_SYSPM_CORE_BUCK_OVERRRIDE_ENABLE(1U);

    /* 5. Wait until the status register indicates the transition is completed.
     * See PWR_CBUCK_STATUS.PMU_DONE.
     */
    retVal = Cy_SysPm_CoreBuckStatus();

    if(retVal == CY_SYSPM_SUCCESS)
    {
        /* 6. Update the desired SDR requester.  This is safe to do, because it is
         * not the selected profile and there is no transition in progress, so it
         * will not have any effect on a CBUCK profile.
         */

        SRSS_PWR_SDR0_CTL =  _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_VSEL, extraReqConfig->sdr0Config->coreBuckVoltSel) |
                 _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_CBUCK_MODE, extraReqConfig->sdr0Config->coreBuckMode) |
                 _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_VSEL, extraReqConfig->sdr0Config->sdrVoltSel) |
                 _VAL2FLD(SRSS_PWR_SDR0_CTL_SDR0_ALLOW_BYPASS, ((extraReqConfig->sdr0Config->sdr0Allowbypass) ? 1UL : 0UL));

        SRSS_PWR_SDR1_CTL =  _VAL2FLD(SRSS_PWR_SDR1_CTL_SDR1_CBUCK_VSEL, extraReqConfig->sdr1Config->coreBuckVoltSel) |
                 _VAL2FLD(SRSS_PWR_SDR1_CTL_SDR1_CBUCK_MODE, extraReqConfig->sdr1Config->coreBuckMode) |
                 _VAL2FLD(SRSS_PWR_SDR1_CTL_SDR1_VSEL, extraReqConfig->sdr1Config->sdrVoltSel) |
                 _VAL2FLD(SRSS_PWR_SDR1_CTL_SDR1_HW_SEL, ((extraReqConfig->sdr1Config->sdr1HwControl) ? 1UL : 0UL)) |
                 _VAL2FLD(SRSS_PWR_SDR1_CTL_SDR1_ENABLE, ((extraReqConfig->sdr1Config->sdr1Enable) ? 1UL : 0UL));

    }

    /* 7. Remove overrides by clearing CBUCK_OVERRIDE and CBUCK_PAUSE */
    CY_SYSPM_CORE_BUCK_OVERRRIDE_ENABLE(0U);
    CY_SYSPM_CORE_BUCK_PAUSE_ENABLE(0U);

    /* 8. Wait until the status register indicates the transition is
     * completed. See PWR_CBUCK_STATUS.PMU_DONE.
     */
    retVal = Cy_SysPm_CoreBuckStatus();

    return retVal;
}


bool Cy_SysPm_RegisterCallback(cy_stc_syspm_callback_t* handler)
{
    bool retVal = false;

    /* Verify the input parameters. */
    if ((handler != NULL) && (handler->callbackParams != NULL) && (handler->callback != NULL))
    {
        uint32_t callbackRootIdx = (uint32_t) handler->type;

        /* If the callback list is not empty. */
        if (pmCallbackRoot[callbackRootIdx] != NULL)
        {
            cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[callbackRootIdx];
            cy_stc_syspm_callback_t* insertPos  = curCallback;

            /* Find the callback after which the new callback is to be
             * inserted. Ensure the given callback has not been registered.
             */
            while ((NULL != curCallback->nextItm) && (curCallback != handler))
            {
                curCallback = curCallback->nextItm;
                /* Callbacks with the same order value are stored in the order
                 * they are registered.
                 */
                if (curCallback->order <= handler->order)
                {
                    insertPos = curCallback;
                }
            }
            /* If the callback has not been registered. */
            if (curCallback != handler)
            {
                /* If the callback is to be inserted at the beginning of the list. */
                if ((insertPos->prevItm == NULL) && (handler->order < insertPos->order))
                {
                    handler->nextItm = insertPos;
                    handler->prevItm = NULL;
                    handler->nextItm->prevItm = handler;
                    pmCallbackRoot[callbackRootIdx] = handler;
                }
                else
                {
                    handler->nextItm = insertPos->nextItm;
                    handler->prevItm = insertPos;

                    /* If the callback is not inserted at the end of the list. */
                    if (handler->nextItm != NULL)
                    {
                        handler->nextItm->prevItm = handler;
                    }
                    insertPos->nextItm = handler;
                }
                retVal = true;
            }
        }
        else
        {
            /* The callback list is empty. */
            pmCallbackRoot[callbackRootIdx] = handler;
            handler->nextItm = NULL;
            handler->prevItm = NULL;
            retVal = true;
        }
    }
    return retVal;
}

bool Cy_SysPm_UnregisterCallback(cy_stc_syspm_callback_t const *handler)
{
    bool retVal = false;

    if (handler != NULL)
    {
        uint32_t callbackRootIdx = (uint32_t) handler->type;
        cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[callbackRootIdx];

        /* Search requested callback item in the linked list */
        while (curCallback != NULL)
        {
            /* Requested callback is found */
            if (curCallback == handler)
            {
                retVal = true;
                break;
            }

            /* Go to next callback item in the linked list */
            curCallback = curCallback->nextItm;
        }

        if (retVal)
        {
            /* Requested callback is first in the list */
            if (pmCallbackRoot[callbackRootIdx] == handler)
            {
                /* Check whether this the only callback registered */
                if (pmCallbackRoot[callbackRootIdx]->nextItm != NULL)
                {
                    pmCallbackRoot[callbackRootIdx] = pmCallbackRoot[callbackRootIdx]->nextItm;
                    pmCallbackRoot[callbackRootIdx]->prevItm = NULL;
                }
                else
                {
                    /* We had only one callback */
                    pmCallbackRoot[callbackRootIdx] = NULL;
                }
            }
            else
            {
                /* Update links of related to unregistered callback items */
                curCallback->prevItm->nextItm = curCallback->nextItm;

                if (curCallback->nextItm != NULL)
                {
                    curCallback->nextItm->prevItm = curCallback->prevItm;
                }
            }
        }
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_ExecuteCallback(cy_en_syspm_callback_type_t type, cy_en_syspm_callback_mode_t mode)
{
    CY_ASSERT_L3(CY_SYSPM_IS_CALLBACK_TYPE_VALID(type));
    CY_ASSERT_L3(CY_SYSPM_IS_CALLBACK_MODE_VALID(mode));

    static cy_stc_syspm_callback_t* lastExecutedCallback = NULL;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[(uint32_t) type];
    cy_stc_syspm_callback_params_t curParams;

    if ((mode == CY_SYSPM_BEFORE_TRANSITION) || (mode == CY_SYSPM_CHECK_READY))
    {
        /* Execute registered callbacks with order from first registered to the
        *  last registered. Stop executing if CY_SYSPM_FAIL was returned in
        *  CY_SYSPM_CHECK_READY mode
        */
        while ((curCallback != NULL) && ((retVal != CY_SYSPM_FAIL) || (mode != CY_SYSPM_CHECK_READY)))
        {
            /* The modes defined in the .skipMode element are not executed */
            if (0UL == ((uint32_t) mode & curCallback->skipMode))
            {
                /* Update elements for local callback parameter values */
                curParams.base = curCallback->callbackParams->base;
                curParams.context = curCallback->callbackParams->context;

                retVal = curCallback->callback(&curParams, mode);

                /* Update callback pointer with value of executed callback.
                * Such update is required to execute further callbacks in
                * backward order after exit from LP mode or to undo
                * configuration after callback returned fail: from last called
                * to first registered.
                */
                lastExecutedCallback = curCallback;
            }
            curCallback = curCallback->nextItm;
        }

        if (mode == CY_SYSPM_CHECK_READY)
        {
            /* Update the pointer to  the failed callback with the result of the callback execution.
            *  If the callback fails, the value of the pointer will be updated
            *  with the address of the callback which returned CY_SYSPM_FAIL, else,
            *  it will be updated with NULL.
            */
            if(retVal == CY_SYSPM_FAIL)
            {
                failedCallback[(uint32_t) type] = lastExecutedCallback;
            }
            else
            {
                failedCallback[(uint32_t) type] = NULL;
            }
        }
    }
    else
    {
        /* Execute registered callbacks with order from lastCallback or last
        * executed to the first registered callback. Such a flow is required if
        * a previous callback function returned CY_SYSPM_FAIL or a previous
        * callback mode was CY_SYSPM_BEFORE_TRANSITION. Such an order is
        * required to undo configurations in correct backward order.
        */
        if (mode != CY_SYSPM_CHECK_FAIL)
        {
            while (curCallback->nextItm != NULL)
            {
                curCallback = curCallback->nextItm;
            }
        }
        else
        {
            /* Skip last executed callback that returns CY_SYSPM_FAIL, as this
            *  callback already knows that it failed.
            */
            curCallback = lastExecutedCallback;

            if (curCallback != NULL)
            {
                curCallback = curCallback->prevItm;
            }
        }

        /* Execute callback functions with required type and mode */
        while (curCallback != NULL)
        {
            /* The modes defined in the .skipMode element are not executed */
            if (0UL == ((uint32_t) mode & curCallback->skipMode))
            {
                /* Update elements for local callback parameter values */
                curParams.base = curCallback->callbackParams->base;
                curParams.context = curCallback->callbackParams->context;

                retVal = curCallback->callback(&curParams, mode);
            }
            curCallback = curCallback->prevItm;
        }
    }

    return retVal;
}

cy_stc_syspm_callback_t* Cy_SysPm_GetFailedCallback(cy_en_syspm_callback_type_t type)
{
    return failedCallback[(uint32_t) type];
}

void Cy_SysPm_IoUnfreeze(void)
{
    uint32_t interruptState;
    interruptState = Cy_SysLib_EnterCriticalSection();

    /* Preserve the last reset reason and wakeup polarity. Then, unfreeze I/O:
     * write PWR_HIBERNATE.FREEZE=0, .UNLOCK=0x3A, .HIBERANTE=0
     */
    SRSS_PWR_HIBERNATE = (SRSS_PWR_HIBERNATE & HIBERNATE_RETAIN_STATUS_MASK) | HIBERNATE_UNLOCK_VAL;

    /* Lock the Hibernate mode:
    * write PWR_HIBERNATE.HIBERNATE=0, UNLOCK=0x00, HIBERANTE=0
    */
    SRSS_PWR_HIBERNATE &= HIBERNATE_RETAIN_STATUS_MASK;

    /* Read register to make sure it is settled */
    (void) SRSS_PWR_HIBERNATE;

    Cy_SysLib_ExitCriticalSection(interruptState);
}

bool Cy_SysPm_IoIsFrozen(void)
{
    return (0U != _FLD2VAL(SRSS_PWR_HIBERNATE_FREEZE, SRSS_PWR_HIBERNATE));
}

void Cy_SysPm_DeepSleepIoUnfreeze(void)
{
    uint32_t interruptState;
    interruptState = Cy_SysLib_EnterCriticalSection();

    /* Unfreeze IO's which are frozen during DEEPSLEEP-RAM/OFF
    * Entry
    */
    SRSS_PWR_CTL2 |= SRSS_PWR_CTL2_FREEZE_DPSLP_Msk;

    Cy_SysLib_ExitCriticalSection(interruptState);
}

bool Cy_SysPm_DeepSleepIoIsFrozen(void)
{
    return (0U != _FLD2VAL(SRSS_PWR_CTL2_FREEZE_DPSLP, SRSS_PWR_CTL2));
}


void Cy_SysPm_CpuSendWakeupEvent(void)
{
    __SEV();
}

bool Cy_SysPm_IsLpmReady(void)
{
    return (_FLD2BOOL(SRSS_PWR_CTL_LPM_READY, SRSS_PWR_CTL)? true : false);
}

void Cy_SysPm_BackupSetSupply(cy_en_syspm_vddbackup_control_t vddBackControl)
{
    CY_ASSERT_L3(CY_SYSPM_IS_VDDBACKUP_VALID(vddBackControl));

    BACKUP_CTL = _CLR_SET_FLD32U((BACKUP_CTL), BACKUP_CTL_VDDBAK_CTL, (uint32_t) vddBackControl);
}


cy_en_syspm_vddbackup_control_t Cy_SysPm_BackupGetSupply(void)
{
    uint32_t retVal;
    retVal = _FLD2VAL(BACKUP_CTL_VDDBAK_CTL, BACKUP_CTL);

    return ((cy_en_syspm_vddbackup_control_t) retVal);
}


void Cy_SysPm_BackupEnableVoltageMeasurement(void)
{
    BACKUP_CTL |= BACKUP_CTL_VBACKUP_MEAS_Msk;
}


void Cy_SysPm_BackupDisableVoltageMeasurement(void)
{
    BACKUP_CTL &= ((uint32_t) ~BACKUP_CTL_VBACKUP_MEAS_Msk);
}


void Cy_SysPm_BackupSuperCapCharge(cy_en_syspm_sc_charge_key_t key)
{
    CY_ASSERT_L3(CY_SYSPM_IS_SC_CHARGE_KEY_VALID(key));

    if(key == CY_SYSPM_SC_CHARGE_ENABLE)
    {
        BACKUP_CTL = _CLR_SET_FLD32U((BACKUP_CTL), BACKUP_CTL_EN_CHARGE_KEY, (uint32_t) CY_SYSPM_SC_CHARGE_ENABLE);
    }
    else
    {
        BACKUP_CTL &= ((uint32_t) ~BACKUP_CTL_EN_CHARGE_KEY_Msk);
    }
}

void Cy_SysPm_BackupWordStore(uint32_t wordIndex, uint32_t *wordSrcPointer, uint32_t wordSize)
{
    CY_ASSERT_L3(CY_SYSPM_IS_WORD_INDEX_VALID(wordIndex));
    CY_ASSERT_L3(CY_SYSPM_IS_WORD_SIZE_VALID(wordSize + wordIndex));

    while(wordSize != 0UL)
    {
        if(wordIndex < CY_SRSS_BACKUP_BREG1_START_POS)
        {
            BACKUP_BREG_SET0[wordIndex] = *wordSrcPointer;
        }
        else if(wordIndex < CY_SRSS_BACKUP_BREG2_START_POS)
        {
            BACKUP_BREG_SET1[wordIndex - CY_SRSS_BACKUP_BREG1_START_POS] = *wordSrcPointer;
        }
        else if(wordIndex < CY_SRSS_BACKUP_BREG3_START_POS)
        {
            BACKUP_BREG_SET2[wordIndex - CY_SRSS_BACKUP_BREG2_START_POS] = *wordSrcPointer;
        }
        else
        {
            BACKUP_BREG_SET3[wordIndex - CY_SRSS_BACKUP_BREG3_START_POS] = *wordSrcPointer;
        }

        wordIndex++;
        wordSrcPointer++;
        wordSize--;
    }
}

void Cy_SysPm_BackupWordReStore(uint32_t wordIndex, uint32_t *wordDstPointer, uint32_t wordSize)
{
    CY_ASSERT_L3(CY_SYSPM_IS_WORD_INDEX_VALID(wordIndex));
    CY_ASSERT_L3(CY_SYSPM_IS_WORD_SIZE_VALID(wordSize + wordIndex));

    while(wordSize != 0UL)
    {

        if(wordIndex < CY_SRSS_BACKUP_BREG1_START_POS)
        {
            *wordDstPointer = BACKUP_BREG_SET0[wordIndex];
        }
        else if(wordIndex < CY_SRSS_BACKUP_BREG2_START_POS)
        {
            *wordDstPointer = BACKUP_BREG_SET1[wordIndex - CY_SRSS_BACKUP_BREG1_START_POS];
        }
        else if(wordIndex < CY_SRSS_BACKUP_BREG3_START_POS)
        {
            *wordDstPointer = BACKUP_BREG_SET2[wordIndex - CY_SRSS_BACKUP_BREG2_START_POS];
        }
        else
        {
            *wordDstPointer = BACKUP_BREG_SET3[wordIndex - CY_SRSS_BACKUP_BREG3_START_POS];
        }

        wordIndex++;
        wordDstPointer++;
        wordSize--;
    }
}

/* This API is an inline version of Cy_SysPm_SetSRAMMacroPwrMode */
__STATIC_FORCEINLINE cy_en_syspm_status_t Cy_SysPm_SetSRAMMacroPwrModeInline(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode)
{
    CY_ASSERT_L3(sramNum == CY_SYSPM_SRAM0_MEMORY);
    CY_ASSERT_L3((sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_ON) || (sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_OFF));
    CY_ASSERT_L3(sramMacroNum < CY_CPUSS_RAMC0_MACRO_NR);

    CY_UNUSED_PARAM(sramNum);

    /* Unlock PWR MACRO Control */
    /* Clear bit 0(CLR0)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR0;
    /* Clear bit 1(CLR1)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR1;

    if(sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_ON)
    {
        /* Enable the Macro Number */
        MXSRAMC_PWR_MACRO_CTL &= ~(0x1UL << (uint32_t)sramMacroNum);
    }
    else
    {
        /* Disable the Macro Number */
        MXSRAMC_PWR_MACRO_CTL |= (0x1UL << (uint32_t)sramMacroNum);
    }
    /* Wait for the PWR_DONE status */
    while(!_FLD2BOOL(RAMC_STATUS_PWR_DONE, MXSRAMC_STATUS)){}

    /* Lock PWR MACRO Control(Set SET01) */
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_SET01;

    return CY_SYSPM_SUCCESS;
}

cy_en_syspm_status_t Cy_SysPm_SetSRAMMacroPwrMode(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode)
{
    return Cy_SysPm_SetSRAMMacroPwrModeInline(sramNum, sramMacroNum, sramPwrMode);
}

cy_en_syspm_sram_pwr_mode_t Cy_SysPm_GetSRAMMacroPwrMode(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum)
{
    cy_en_syspm_sram_pwr_mode_t value;

    CY_ASSERT_L3(sramNum == CY_SYSPM_SRAM0_MEMORY);
    CY_ASSERT_L3(sramMacroNum < CY_CPUSS_RAMC0_MACRO_NR);

    CY_UNUSED_PARAM(sramNum);

    /* Unlock PWR MACRO Control */
    /* Clear bit 0(CLR0)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR0;
    /* Clear bit 1(CLR1)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR1;

    value = ((MXSRAMC_PWR_MACRO_CTL & (0x1UL << (uint32_t)sramMacroNum)) != 0UL) ? CY_SYSPM_SRAM_PWR_MODE_OFF:CY_SYSPM_SRAM_PWR_MODE_ON;

    /* Lock PWR MACRO Control(Set SET01) */
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_SET01;

    return value;

}


cy_en_syspm_status_t Cy_SysPm_SetSRAMPwrMode(cy_en_syspm_sram_index_t sramNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode)
{
    CY_ASSERT_L3(sramNum == CY_SYSPM_SRAM0_MEMORY);
    CY_ASSERT_L3((sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_ON) || (sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_OFF));

    CY_UNUSED_PARAM(sramNum);

    (void)Cy_SysPm_SetSRAMMacroPwrMode(CY_SYSPM_SRAM0_MEMORY, (uint32_t)CY_SYSPM_SRAM0_MACRO_0, sramPwrMode);
    (void)Cy_SysPm_SetSRAMMacroPwrMode(CY_SYSPM_SRAM0_MEMORY, (uint32_t)CY_SYSPM_SRAM0_MACRO_1, sramPwrMode);

    return CY_SYSPM_SUCCESS;
}

/*This reset handler will be implemented as part of HCI ROM app*/
__WEAK void Cy_SysPm_Dsramoff_Entry(void)
{
    while(true) {}
}

cy_en_syspm_status_t Cy_SysPm_CpuEnterRAMOffDeepSleep(void)
{
    uint32_t interruptState;
    uint32_t cbDeepSleepRootIdx = (uint32_t) Cy_SysPm_GetDeepSleepMode();
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    CY_ASSERT_L3(CY_SYSPM_IS_DEEPSLEEP_MODE_VALID(cbDeepSleepRootIdx));

    //Check if LPM is ready
    if(!Cy_SysPm_IsLpmReady())
    {
        retVal = CY_SYSPM_FAIL;
    }
    else
    {
        //TBD Check if PDCM Dependencies are set properly

        /* Call the registered callback functions with the CY_SYSPM_CHECK_READY
        *  parameter
        */
        if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
        {
            retVal = Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_CHECK_READY);
        }

        /* The CPU can switch into the Deep Sleep power mode only when
        *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
        *  parameter return CY_SYSPM_SUCCESS
        */
        if (retVal == CY_SYSPM_SUCCESS)
        {
            /* Call the registered callback functions with the
            * CY_SYSPM_BEFORE_TRANSITION parameter
            */
            interruptState = Cy_SysLib_EnterCriticalSection();
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_BEFORE_TRANSITION);
            }
            /* The CPU enters Deep Sleep mode upon execution of WFI/WFE
             * use Cy_SysPm_SetDeepSleepMode to set various deepsleep modes TBD*/
            SCB_SCR |= SCB_SCR_SLEEPDEEP_Msk;
            __DSB();                   /* Ensure completion of memory access */

            /* Disable SRAM Macros to save power */
            (void)Cy_SysPm_SetSRAMMacroPwrModeInline(CY_SYSPM_SRAM0_MEMORY, (uint32_t)CY_SYSPM_SRAM0_MACRO_0, CY_SYSPM_SRAM_PWR_MODE_OFF);

            __WFI();

            /* Enable SRAM Macros as DEEPSLEEP_RAM might have failed if we reach this point */
            (void)Cy_SysPm_SetSRAMMacroPwrModeInline(CY_SYSPM_SRAM0_MEMORY, (uint32_t)CY_SYSPM_SRAM0_MACRO_0, CY_SYSPM_SRAM_PWR_MODE_ON);

            /* Clear SCB_SCR_SLEEPDEEP flag */
            SCB_SCR &= (uint32_t) ~SCB_SCR_SLEEPDEEP_Msk;

            /* Jump to HCI ROM app Reset handler */
            Cy_SysPm_Dsramoff_Entry();

            Cy_SysLib_ExitCriticalSection(interruptState);
        }
        else
        {
            /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
            *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
            *  parameter
            */
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_CHECK_FAIL);
            }
        }
    }
    return retVal;
}

void Cy_SysPm_TriggerSoftReset(void)
{
    SRSS_RES_SOFT_CTL = SRSS_RES_SOFT_CTL_TRIGGER_SOFT_Msk;
}

void Cy_SysPm_TriggerXRes(void)
{
    SRSS_RES_PXRES_CTL = SRSS_RES_PXRES_CTL_PXRES_TRIGGER_Msk;
}


#ifdef ENABLE_MEM_VOLTAGE_TRIMS
/*******************************************************************************
* Function Name: SetMemoryVoltageTrims
****************************************************************************//**
*
* This is the internal function that updates the trim values for the
* RAM and ROM. The trim update is done during transition of regulator voltage
* from higher to a lower one.
*
*******************************************************************************/
static void SetMemoryVoltageTrims(cy_en_syspm_sdr_voltage_t voltage)
{
    uint32_t ramVoltgeTrim = CPUSS_TRIM_RAM_CTL;
    uint32_t romVoltgeTrim = CPUSS_TRIM_ROM_CTL;

    CY_ASSERT_L3(CY_SYSPM_IS_SDR_TRIM_VOLTAGE_VALID(voltage));

    switch(voltage)
    {
        case CY_SYSPM_SDR_VOLTAGE_0_900V:
        {
            ramVoltgeTrim = CPUSS_TRIM_RAM_VOLT_0_900;
            romVoltgeTrim = CPUSS_TRIM_ROM_VOLT_0_900;
        }
        break;

        case CY_SYSPM_SDR_VOLTAGE_1_000V:
        {
            ramVoltgeTrim = CPUSS_TRIM_RAM_VOLT_1_000;
            romVoltgeTrim = CPUSS_TRIM_ROM_VOLT_1_000;
        }
        break;

        case CY_SYSPM_SDR_VOLTAGE_1_100V:
        {
            ramVoltgeTrim = CPUSS_TRIM_RAM_VOLT_1_100;
            romVoltgeTrim = CPUSS_TRIM_ROM_VOLT_1_100;
        }
        break;

        default:
        {
            CY_ASSERT_L2(false);
        }
        break;
    }

    CPUSS_TRIM_RAM_CTL = ramVoltgeTrim;
    CPUSS_TRIM_ROM_CTL = romVoltgeTrim;

}
#endif /* ENABLE_MEM_VOLTAGE_TRIMS */

#if defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)

/*******************************************************************************
* Function Name: SetReadMarginTrimUlp
****************************************************************************//**
*
* This is the internal function that updates the read-margin trim values for the
* RAM and ROM. The trim update is done during transition of regulator voltage
* from higher to a lower one.
*
*******************************************************************************/
static void SetReadMarginTrimUlp(void)
{
    SRSS_TRIM_RAM_CTL = (SFLASH_CPUSS_TRIM_RAM_CTL_HALF_ULP & ((uint32_t) ~SRSS_TRIM_RAM_CTL_RA_MASK)) |
                        (SRSS_TRIM_RAM_CTL & SRSS_TRIM_RAM_CTL_RA_MASK);

    SRSS_TRIM_ROM_CTL = SFLASH_CPUSS_TRIM_ROM_CTL_HALF_ULP;
}


/*******************************************************************************
* Function Name: SetReadMarginTrimLp
****************************************************************************//**
*
* The internal function that updates the read-margin trim values for the
* RAM and ROM. The trim update is done during transition of regulator voltage
* from a lower to a higher one.
*
*******************************************************************************/
static void SetReadMarginTrimLp(void)
{
    SRSS_TRIM_RAM_CTL = (SFLASH_CPUSS_TRIM_RAM_CTL_LP & ((uint32_t) ~SRSS_TRIM_RAM_CTL_RA_MASK)) |
                        (SRSS_TRIM_RAM_CTL & SRSS_TRIM_RAM_CTL_RA_MASK);

    SRSS_TRIM_ROM_CTL = SFLASH_CPUSS_TRIM_ROM_CTL_LP;

}


/*******************************************************************************
* Function Name: SetReadMarginTrimMf
****************************************************************************//**
*
* The internal function that updates the read-margin trim values for the
* RAM and ROM. The trim update is done during transition of regulator voltage
* from a lower to a higher one.
*
*******************************************************************************/
static void SetReadMarginTrimMf(void)
{
    SRSS_TRIM_RAM_CTL = (SFLASH_CPUSS_TRIM_RAM_CTL_MF & ((uint32_t) ~SRSS_TRIM_RAM_CTL_RA_MASK)) |
                        (SRSS_TRIM_RAM_CTL & SRSS_TRIM_RAM_CTL_RA_MASK);

    SRSS_TRIM_ROM_CTL = SFLASH_CPUSS_TRIM_ROM_CTL_MF;
}


/*******************************************************************************
* Function Name: SetReadMarginTrimOd
****************************************************************************//**
*
* The internal function that updates the read-margin trim values for the
* RAM and ROM. The trim update is done during transition of regulator voltage
* from a lower to a higher one.
*
*******************************************************************************/
static void SetReadMarginTrimOd(void)
{
    SRSS_TRIM_RAM_CTL = (SFLASH_CPUSS_TRIM_RAM_CTL_OD & ((uint32_t) ~SRSS_TRIM_RAM_CTL_RA_MASK)) |
                        (SRSS_TRIM_RAM_CTL & SRSS_TRIM_RAM_CTL_RA_MASK);

    SRSS_TRIM_ROM_CTL = SFLASH_CPUSS_TRIM_ROM_CTL_OD;
}


/*******************************************************************************
* Function Name: SetWriteAssistTrimUlp
****************************************************************************//**
*
* The internal function that updates the write assistant trim value for the
* RAM. The trim update is done during transition of regulator voltage
* from higher to a lower.
*
*******************************************************************************/
static void SetWriteAssistTrimUlp(void)
{
    SRSS_TRIM_RAM_CTL = (SFLASH_CPUSS_TRIM_RAM_CTL_ULP & ((uint32_t) ~SRSS_TRIM_RAM_CTL_RA_MASK)) |
                        (SRSS_TRIM_RAM_CTL & SRSS_TRIM_RAM_CTL_RA_MASK);
}


/*******************************************************************************
* Function Name: SetWriteAssistTrimLp
****************************************************************************//**
*
* The internal function that updates the write assistant trim value for the
* RAM. The trim update is done during transition of regulator voltage
* from lower to a higher one.
*
*******************************************************************************/
static void SetWriteAssistTrimLp(void)
{
    SRSS_TRIM_RAM_CTL = (SFLASH_CPUSS_TRIM_RAM_CTL_HALF_LP & ((uint32_t) ~SRSS_TRIM_RAM_CTL_RA_MASK)) |
                        (SRSS_TRIM_RAM_CTL & SRSS_TRIM_RAM_CTL_RA_MASK);

    SRSS_TRIM_ROM_CTL = SFLASH_CPUSS_TRIM_ROM_CTL_HALF_LP;
}


/*******************************************************************************
* Function Name: SetWriteAssistTrimMf
****************************************************************************//**
*
* The internal function that updates the write assistant trim value for the
* RAM. The trim update is done during transition of regulator voltage
* from lower to a higher one.
*
*******************************************************************************/
static void SetWriteAssistTrimMf(void)
{
    SRSS_TRIM_RAM_CTL = (SFLASH_CPUSS_TRIM_RAM_CTL_HALF_MF & ((uint32_t) ~SRSS_TRIM_RAM_CTL_RA_MASK)) |
                        (SRSS_TRIM_RAM_CTL & SRSS_TRIM_RAM_CTL_RA_MASK);

    SRSS_TRIM_ROM_CTL = SFLASH_CPUSS_TRIM_ROM_CTL_HALF_MF;
}


/*******************************************************************************
* Function Name: SetWriteAssistTrimOd
****************************************************************************//**
*
* The internal function that updates the write assistant trim value for the
* RAM. The trim update is done during transition of regulator voltage
* from lower to a higher one.
*
*******************************************************************************/
static void SetWriteAssistTrimOd(void)
{
    SRSS_TRIM_RAM_CTL = (SFLASH_CPUSS_TRIM_RAM_CTL_HALF_OD & ((uint32_t) ~SRSS_TRIM_RAM_CTL_RA_MASK)) |
                        (SRSS_TRIM_RAM_CTL & SRSS_TRIM_RAM_CTL_RA_MASK);

    SRSS_TRIM_ROM_CTL = SFLASH_CPUSS_TRIM_ROM_CTL_HALF_OD;
}
#endif

/*******************************************************************************
* Function Name: IsVoltageChangePossible
****************************************************************************//**
*
* The internal function that checks wherever it is possible to change the core
* voltage. Voltage change is possible only when the specific device revision
* support registers modification.
*
*******************************************************************************/
static bool IsVoltageChangePossible(void)
{

    bool retVal = false;
#if defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)

    uint32_t trimRamCheckVal = (SRSS_TRIM_RAM_CTL & SRSS_TRIM_RAM_CTL_WC_MASK);

    SRSS_TRIM_RAM_CTL &= ~SRSS_TRIM_RAM_CTL_WC_MASK;
    SRSS_TRIM_RAM_CTL |= ((~trimRamCheckVal) & SRSS_TRIM_RAM_CTL_WC_MASK);

    retVal = (trimRamCheckVal != (SRSS_TRIM_RAM_CTL & SRSS_TRIM_RAM_CTL_WC_MASK));

#elif (CY_SYSLIB_GET_SILICON_REV_ID != CY_SYSLIB_20829A0_SILICON_REV)
    {
        uint32_t trimRamCheckVal = (CPUSS_TRIM_RAM_CTL & CPUSS_TRIM_RAM_CTL_WC_MASK);

        CPUSS_TRIM_RAM_CTL &= ~CPUSS_TRIM_RAM_CTL_WC_MASK;
        CPUSS_TRIM_RAM_CTL |= ((~trimRamCheckVal) & CPUSS_TRIM_RAM_CTL_WC_MASK);

        retVal = (trimRamCheckVal != (CPUSS_TRIM_RAM_CTL & CPUSS_TRIM_RAM_CTL_WC_MASK));
    }
#endif

    return retVal;
}


#if (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))

uint32_t Cy_SysPm_ReadStatus(void)
{
    uint32_t pmStatus = 0UL;

    /* Check whether the device is in LP, MF, ULP, OD mode by reading
    *  the core voltage:
    *  - 0.9V (nominal) - System ULP mode
    *  - 1.0V (nominal) - System MF mode
    *  - 1.1V (nominal) - System LP mode
    *  - 1.2V (nominal) - System OD mode
    */

    /* Read current active regulator */
    if (Cy_SysPm_LdoIsEnabled())
    {
        /* Current active regulator is LDO */
        if (Cy_SysPm_LdoGetVoltage() == CY_SYSPM_LDO_VOLTAGE_LP)
        {
            pmStatus |= CY_SYSPM_STATUS_SYSTEM_LP;
        }
        else if (Cy_SysPm_LdoGetVoltage() == CY_SYSPM_LDO_VOLTAGE_ULP)
        {
            pmStatus |= CY_SYSPM_STATUS_SYSTEM_ULP;
        }
        else if (Cy_SysPm_LdoGetVoltage() == CY_SYSPM_LDO_VOLTAGE_MF)
        {
            pmStatus |= CY_SYSPM_STATUS_SYSTEM_MF;
        }
        else
        {
            pmStatus |= CY_SYSPM_STATUS_SYSTEM_OD;
        }
    }
    return pmStatus;
}


bool Cy_SysPm_IsSystemLp(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_SYSTEM_LP) != 0U);
}


bool Cy_SysPm_IsSystemUlp(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_SYSTEM_ULP) != 0U);
}


bool Cy_SysPm_IsSystemMf(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_SYSTEM_MF) != 0U);
}


bool Cy_SysPm_IsSystemOd(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_SYSTEM_OD) != 0U);
}


cy_en_syspm_status_t Cy_SysPm_SystemEnterLp(void)
{
    uint32_t interruptState;
    uint32_t cbLpRootIdx = (uint32_t) CY_SYSPM_LP;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbLpRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into LP only when
    * all executed registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS
    */
    if (retVal == CY_SYSPM_SUCCESS)
    {

        /* Call the registered callback functions with the
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbLpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_BEFORE_TRANSITION);
        }

        /* Read current active regulator and set LP voltage*/
        if (Cy_SysPm_LdoIsEnabled()) // Comment : Is this check req for PSOC C3
        {
            /* Current active regulator is LDO */
            if (Cy_SysPm_LdoGetVoltage() != CY_SYSPM_LDO_VOLTAGE_LP)
            {
                retVal = Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_LP);
            }
        }

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        * CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbLpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemEnterUlp(void)
{
    uint32_t interruptState;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    uint32_t cbUlpRootIdx = (uint32_t) CY_SYSPM_ULP;

    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbUlpRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into the ULP only when
    * all executed registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS
    */
    if (retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with the
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_BEFORE_TRANSITION);
        }

        /* Read current active regulator and set ULP voltage*/
        if (Cy_SysPm_LdoIsEnabled())
        {
            /* Current active regulator is LDO */
            if (Cy_SysPm_LdoGetVoltage() != CY_SYSPM_LDO_VOLTAGE_ULP)
            {
                retVal = Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_ULP);
            }
        }

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        * CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemEnterMf(void)
{
    uint32_t interruptState;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    uint32_t cbUlpRootIdx = (uint32_t) CY_SYSPM_MF;

    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbUlpRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_MF, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into the MF only when
    * all executed registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS
    */
    if (retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with the
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_MF, CY_SYSPM_BEFORE_TRANSITION);
        }

        /* Read current active regulator and set ULP voltage*/
        if (Cy_SysPm_LdoIsEnabled())
        {
            /* Current active regulator is LDO */
            if (Cy_SysPm_LdoGetVoltage() != CY_SYSPM_LDO_VOLTAGE_MF)
            {
                retVal = Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_MF);
            }
        }

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        * CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_MF, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_MF, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemEnterOd(void)
{
    uint32_t interruptState;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    uint32_t cbUlpRootIdx = (uint32_t) CY_SYSPM_OD;

    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbUlpRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_OD, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into the OD only when
    * all executed registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS
    */
    if (retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with the
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_OD, CY_SYSPM_BEFORE_TRANSITION);
        }

        /* Read current active regulator and set ULP voltage*/
        if (Cy_SysPm_LdoIsEnabled())
        {
            /* Current active regulator is LDO */
            if (Cy_SysPm_LdoGetVoltage() != CY_SYSPM_LDO_VOLTAGE_OD)
            {
                retVal = Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_OD);
            }
        }

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        * CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_OD, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_OD, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }

    return retVal;
}
#endif

#if ((defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2u)) || \
    ((defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2u)) && (defined (SRSS_BACKUP_VBCK_PRESENT) && (SRSS_BACKUP_VBCK_PRESENT == 1u)))) || \
    defined (CY_DOXYGEN)

void Cy_SysPm_PmicEnable(void)
{
    if (CY_SYSPM_PMIC_UNLOCK_KEY == _FLD2VAL(BACKUP_PMIC_CTL_UNLOCK, BACKUP_PMIC_CTL))
    {
        BACKUP_PMIC_CTL =
        _VAL2FLD(BACKUP_PMIC_CTL_UNLOCK, CY_SYSPM_PMIC_UNLOCK_KEY) |
        _VAL2FLD(BACKUP_PMIC_CTL_PMIC_EN_OUTEN, 1U) |
        _VAL2FLD(BACKUP_PMIC_CTL_PMIC_EN, 1U);
    }
}


void Cy_SysPm_PmicDisable(cy_en_syspm_pmic_wakeup_polarity_t polarity)
{
    CY_ASSERT_L3(CY_SYSPM_IS_POLARITY_VALID(polarity));

    if (CY_SYSPM_PMIC_UNLOCK_KEY == _FLD2VAL(BACKUP_PMIC_CTL_UNLOCK, BACKUP_PMIC_CTL))
    {
        BACKUP_PMIC_CTL =
        (_VAL2FLD(BACKUP_PMIC_CTL_UNLOCK, CY_SYSPM_PMIC_UNLOCK_KEY) |
         _CLR_SET_FLD32U(BACKUP_PMIC_CTL, BACKUP_PMIC_CTL_POLARITY, (uint32_t) polarity)) &
        ((uint32_t) ~ _VAL2FLD(BACKUP_PMIC_CTL_PMIC_EN, 1U));
    }
}


void Cy_SysPm_PmicAlwaysEnable(void)
{
    BACKUP_PMIC_CTL |= _VAL2FLD(BACKUP_PMIC_CTL_PMIC_ALWAYSEN, 1U);
}


void Cy_SysPm_PmicEnableOutput(void)
{
    if (CY_SYSPM_PMIC_UNLOCK_KEY == _FLD2VAL(BACKUP_PMIC_CTL_UNLOCK, BACKUP_PMIC_CTL))
    {
        BACKUP_PMIC_CTL |=
        _VAL2FLD(BACKUP_PMIC_CTL_UNLOCK, CY_SYSPM_PMIC_UNLOCK_KEY) | _VAL2FLD(BACKUP_PMIC_CTL_PMIC_EN_OUTEN, 1U);
    }
}


void Cy_SysPm_PmicDisableOutput(void)
{
    if (CY_SYSPM_PMIC_UNLOCK_KEY == _FLD2VAL(BACKUP_PMIC_CTL_UNLOCK, BACKUP_PMIC_CTL))
    {
        BACKUP_PMIC_CTL =
        (BACKUP_PMIC_CTL | _VAL2FLD(BACKUP_PMIC_CTL_UNLOCK, CY_SYSPM_PMIC_UNLOCK_KEY)) &
        ((uint32_t) ~ _VAL2FLD(BACKUP_PMIC_CTL_PMIC_EN_OUTEN, 1U));
    }
}


void Cy_SysPm_PmicLock(void)
{
    BACKUP_PMIC_CTL = _CLR_SET_FLD32U(BACKUP_PMIC_CTL, BACKUP_PMIC_CTL_UNLOCK, 0U);
}


void Cy_SysPm_PmicUnlock(void)
{
    BACKUP_PMIC_CTL = _CLR_SET_FLD32U(BACKUP_PMIC_CTL, BACKUP_PMIC_CTL_UNLOCK, CY_SYSPM_PMIC_UNLOCK_KEY);
}


bool Cy_SysPm_PmicIsEnabled(void)
{
    return (0U != _FLD2VAL(BACKUP_PMIC_CTL_PMIC_EN, BACKUP_PMIC_CTL));
}


bool Cy_SysPm_PmicIsOutputEnabled(void)
{
    return (0U != _FLD2VAL(BACKUP_PMIC_CTL_PMIC_EN_OUTEN, BACKUP_PMIC_CTL));
}


bool Cy_SysPm_PmicIsLocked(void)
{
    return ((_FLD2VAL(BACKUP_PMIC_CTL_UNLOCK, BACKUP_PMIC_CTL) == CY_SYSPM_PMIC_UNLOCK_KEY) ? false : true);
}
#endif  /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || ((CY_IP_MXS40SRSS_VERSION >= 2u) && (SRSS_BACKUP_VBCK_PRESENT)) */

#if (defined (CY_IP_MXS40SSRSS) && (SRSS_S40S_REGSETA_PRESENT == 1UL))

void Cy_SysPm_LinearRegDisable(void)
{
    SRSS_PWR_CTL2 |= SRSS_PWR_CTL2_LINREG_DIS_Msk;
}

void Cy_SysPm_LinearRegEnable(void)
{
    SRSS_PWR_CTL2 &= (uint32_t) ~SRSS_PWR_CTL2_LINREG_DIS_Msk;
}

bool Cy_SysPm_LinearRegGetStatus(void)
{
    return (_FLD2BOOL(SRSS_PWR_CTL2_LINREG_OK, SRSS_PWR_CTL2));
}

void Cy_SysPm_DeepSleepRegDisable(void)
{
    SRSS_PWR_CTL2 |= SRSS_PWR_CTL2_DPSLP_REG_DIS_Msk;
}

void Cy_SysPm_DeepSleepRegEnable(void)
{
    SRSS_PWR_CTL2 &= (uint32_t) ~SRSS_PWR_CTL2_DPSLP_REG_DIS_Msk;
}

bool Cy_SySPm_IsDeepSleepRegEnabled(void)
{
    return(0u == _FLD2VAL(SRSS_PWR_CTL2_DPSLP_REG_DIS, SRSS_PWR_CTL2));
}
#endif /* Linear Regulator */

#endif
/* [] END OF FILE */
