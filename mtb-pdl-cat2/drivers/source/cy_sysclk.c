/***************************************************************************//**
* \file cy_sysclk.c
* \version 3.50
*
* Provides an API implementation of the sysclk driver.
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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
*******************************************************************************/


#include "cy_sysclk.h"
#include "cy_syslib.h"
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>


/* ========================================================================== */
/* =========================    EXTCLK SECTION    =========================== */
/* ========================================================================== */

/** \cond INTERNAL */
static uint32_t extClkFreq = 0UL; /* Internal storage for external clock frequency user setting */

#define CY_SYSCLK_EXTCLK_MIN_FREQ (0UL)  /* 0 MHz */
#define CY_SYSCLK_EXTCLK_MAX_FREQ (48000000UL) /* 48 MHz */
/** \endcond */

/**
* \addtogroup group_sysclk_ext_clk_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_ExtClkSetFrequency
****************************************************************************//**
*
* Sets the signal frequency of the External Clock Source (EXTCLK) into the
* internal storage to be used in \ref Cy_SysClk_ClkHfGetFrequency.
*
* \param freq The frequency of the External Clock Source.
* Valid range is 0...48000000 (0...48 MHz).
* Zero means the external clock signal is not applied.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ExtClkSetFrequency
*
*******************************************************************************/
void Cy_SysClk_ExtClkSetFrequency(uint32_t freq)
{
    if (freq <= CY_SYSCLK_EXTCLK_MAX_FREQ)
    {
        extClkFreq = freq;
    }
}


/*******************************************************************************
* Function Name: Cy_SysClk_ExtClkGetFrequency
****************************************************************************//**
*
* Returns the frequency of the External Clock Source (EXTCLK) from the
* internal storage.
*
* \return The frequency of the External Clock Source.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ExtClkSetFrequency
*
*******************************************************************************/
uint32_t Cy_SysClk_ExtClkGetFrequency(void)
{
    return (extClkFreq);
}
/** \} group_sysclk_ext_clk_funcs */


/* ========================================================================== */
/* =========================    EXTREF SECTION    =========================== */
/* ========================================================================== */
#if (defined(CY_IP_M0S8EXCO) && (CY_IP_M0S8EXCO == 1u))
#if (CY_IP_M0S8EXCO_VERSION == 2U) || defined(CY_DOXYGEN)
/** \cond INTERNAL */
static uint32_t extRefFreq = 0UL; /* Internal storage for external PLL reference frequency user setting */

#define CY_SYSCLK_EXTREF_MIN_FREQ (1000000UL)  /* 1 MHz */
#define CY_SYSCLK_EXTREF_MAX_FREQ (48000000UL) /* 48 MHz */
/** \endcond */
/**
* \addtogroup group_sysclk_ext_ref_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_ExtRefSetFrequency
****************************************************************************//**
*
* Sets the signal frequency of the External PLL Reference Clock Source (EXTREF)
* into the internal storage to be used in \ref Cy_SysClk_PllGetFrequency.
*
* \param freq The frequency of the External PLL Reference Source.
* Valid range is 1000000...48000000 (1...48 MHz) and also 0.
* Zero means the external clock signal is not applied.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ExtRefSetFrequency
*
*******************************************************************************/
void Cy_SysClk_ExtRefSetFrequency(uint32_t freq)
{
    if (((CY_SYSCLK_EXTREF_MIN_FREQ <= freq) && (freq <= CY_SYSCLK_EXTREF_MAX_FREQ)) || (0UL == freq))
    {
        extRefFreq = freq;
    }
}


/*******************************************************************************
* Function Name: Cy_SysClk_ExtRefGetFrequency
****************************************************************************//**
*
* Returns the frequency of the External PLL Reference Source (EXT_REF) from the
* internal storage.
*
* \return The frequency of the External PLL Reference Source.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ExtRefSetFrequency
*
*******************************************************************************/
uint32_t Cy_SysClk_ExtRefGetFrequency(void)
{
    return (extRefFreq);
}
/** \} group_sysclk_ext_ref_funcs */
#endif /* CY_IP_M0S8EXCO_VERSION == 2U */
#endif /* CY_IP_M0S8EXCO */

/* ========================================================================== */
/* ===========================    IMO SECTION    ============================ */
/* ========================================================================== */


#if defined (CY_IP_M0S8SRSSHV)
#define CY_SYSCLK_IS_FREQ_VALID(freq)  ((CY_SYSCLK_IMO_24MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_28MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_32MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_36MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_40MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_44MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_48MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_49_152MHZ == (freq)))
#elif defined (CY_IP_S8SRSSLT)
#define CY_SYSCLK_IS_FREQ_VALID(freq)  ((CY_SYSCLK_IMO_24MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_28MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_32MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_36MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_40MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_44MHZ == (freq)) || \
                                        (CY_SYSCLK_IMO_48MHZ == (freq)))
#endif /* (CY_IP_M0S8SRSSHV) */

#define CY_SYSCLK_FREQ_SCALER           (1000000UL)
#define CY_SYSCLK_MILLI_SCALER          (1000UL)
#define CY_SYSCLK_MICRO_SCALER          (1000000UL)


/*******************************************************************************
* Function Name: Cy_SysClk_ImoSetFrequency
****************************************************************************//**
*
* Sets the IMO desired frequency.
*
* \note There is a \ref Cy_SysClk_ImoLock feature to improve an IMO precision.
*
* \param freq - the desired IMO frequency, \ref cy_en_sysclk_imo_freq_t.
*
* \note Call \ref SystemCoreClockUpdate after this function calling
* if it affects the SYSCLK frequency.
*
* \note Call \ref Cy_SysLib_SetWaitStates before calling this function if
* SYSCLK frequency is increasing.
*
* \note Call \ref Cy_SysLib_SetWaitStates after calling this function if
* SYSCLK frequency is decreasing.
*
* \return Error / status code \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - the frequency is set as requested \n
* \ref CY_SYSCLK_BAD_PARAM - Invalid parameter \n
* \ref CY_SYSCLK_INVALID_STATE - IMO is not enabled
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ImoSetFrequency(cy_en_sysclk_imo_freq_t freq)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    if (Cy_SysClk_ImoIsEnabled())
    {
        if (CY_SYSCLK_IS_FREQ_VALID(freq))
        {
            if ((uint32_t) freq != Cy_SysClk_ImoGetFrequency())
            {
                /* Convert the frequency value in Hz into the SFLASH.IMO_TRIM register index */
                uint32_t locFreq = ((uint32_t)freq - (uint32_t)CY_SYSCLK_IMO_24MHZ) / CY_SYSCLK_FREQ_SCALER;
                uint32_t intStat = Cy_SysLib_EnterCriticalSection();
            #if defined(CY_IP_M0S8WCO)
                /* Unlock if locked */
                cy_en_sysclk_imo_lock_t lock = Cy_SysClk_ImoGetLockStatus();

                if (CY_SYSCLK_IMO_LOCK_NONE != lock)
                {
                    (void) Cy_SysClk_ImoLock(CY_SYSCLK_IMO_LOCK_NONE);
                }
            #endif /* (CY_IP_M0S8WCO) */

            #if defined(CY_IP_M0S8SRSSHV)
                /*
                 *  For SRSSHV, the IMO frequency TRIM step is in multiples of 4MHZ
                 */
                locFreq >>= 2UL;
                if (CY_SYSCLK_IMO_49_152MHZ == freq)
                {
                    /* for 49.152Mhz we have to address trim index next to 48 Mhz
                     * so we have to increment calculated index.
                     */
                    locFreq += 1UL;
                }

                Cy_SysClk_UnlockProtReg();

                /* Set IMO to 24 MHz */
                SRSS_CLK_IMO_SELECT = 0UL;

                /* Apply coarse trim */
                SRSS_CLK_IMO_TRIM1 = SFLASH_IMO_TRIM_LT(locFreq);

                /* Apply TC trim */
                SRSS_CLK_IMO_TRIM2 = SFLASH_IMO_TCTRIM_LT(locFreq);

                /* Apply step size trim */
                SRSS_CLK_IMO_TRIM3 = SFLASH_IMO_STEPSIZE_LT(locFreq);

                Cy_SysClk_LockProtReg();

                /*
                 * For SRSSHV, the IMO TRIM frequency is in multiples of 4
                 * So shifting by 4 here to avoid the divide by 4 done for other platforms.
                 */
                if (CY_SYSCLK_IMO_49_152MHZ == freq)
                {
                    /* for 49.152Mhz we have to address trim index next to 48 Mhz
                     * but set 48Mhz frequency.
                     * so we have to decrement calculated index back.
                     */
                    locFreq -= 1UL;
                }
                locFreq <<= 2UL;

            #elif defined(CY_IP_S8SRSSLT)
                /* Set IMO to 24 MHz */
                SRSS_CLK_IMO_SELECT = 0UL;

                /* Apply coarse trim */
                SRSS_CLK_IMO_TRIM1 = SFLASH_IMO_TRIM_LT(locFreq);

                /* Zero out fine trim */
                SRSS_CLK_IMO_TRIM2 = 0UL;

                /* Apply TC trim */
                SRSS_CLK_IMO_TRIM3 = SFLASH_IMO_TCTRIM_LT(locFreq);

            #endif /* defined(CY_IP_M0S8SRSSHV) */

                /* Convert the SFLASH.IMO_TRIM register index into the frequency bitfield value */
                locFreq >>= 2UL;

                Cy_SysLib_DelayCycles(50UL);

                if (0UL != locFreq)
                {
#if defined (CY_IP_M0S8SRSSHV)
                    Cy_SysClk_UnlockProtReg();
#endif /* defined (CY_IP_M0S8SRSSHV) */
                    /* Select nearby intermediate frequency */
                    CY_REG32_CLR_SET(SRSS_CLK_IMO_SELECT, SRSS_CLK_IMO_SELECT_FREQ, locFreq - 1UL);
                    Cy_SysLib_DelayCycles(50UL);

                    /* Make small step to final frequency */
                    CY_REG32_CLR_SET(SRSS_CLK_IMO_SELECT, SRSS_CLK_IMO_SELECT_FREQ, locFreq);
#if defined (CY_IP_M0S8SRSSHV)
                    /* clear history for second order trim */
                    iterationNum = 0UL;
                    errorIntegralHz = 0;
                    Cy_SysClk_LockProtReg();
#endif /* defined (CY_IP_M0S8SRSSHV) */
                }

            #if defined(CY_IP_M0S8WCO)
                /* Restore locking */
                if (CY_SYSCLK_IMO_LOCK_NONE != lock)
                {
                    (void) Cy_SysClk_ImoLock(lock);
                }
            #endif /* (CY_IP_M0S8WCO) */

                Cy_SysLib_ExitCriticalSection(intStat);
            }

            retVal = CY_SYSCLK_SUCCESS;
        }
    }
    else
    {
        retVal = CY_SYSCLK_INVALID_STATE;
    }

    return(retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_ImoGetFrequency
****************************************************************************//**
*
* Returns the IMO nominal frequency.
*
* \return the frequency value in Hz.
*
*******************************************************************************/
uint32_t Cy_SysClk_ImoGetFrequency(void)
{
    return (Cy_SysClk_ImoIsEnabled() ?
        (((_FLD2VAL(SRSS_CLK_IMO_SELECT_FREQ, SRSS_CLK_IMO_SELECT) << 2UL) *
          CY_SYSCLK_FREQ_SCALER) + (uint32_t)CY_SYSCLK_IMO_24MHZ) : 0UL);
}

#if defined(CY_IP_M0S8WCO)
/*******************************************************************************
* Function Name: Cy_SysClk_ImoGetLockStatus
****************************************************************************//**
*
* Returns IMO lock status.
*
* \return IMO lock state \ref cy_en_sysclk_imo_lock_t.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
*******************************************************************************/
cy_en_sysclk_imo_lock_t Cy_SysClk_ImoGetLockStatus(void)
{
    cy_en_sysclk_imo_lock_t retVal = CY_SYSCLK_IMO_LOCK_NONE;

    if (_FLD2BOOL(WCO_CONFIG_DPLL_ENABLE, WCO_CONFIG))
    {
        retVal = CY_SYSCLK_IMO_LOCK_WCO;
    }

    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_ImoLock
****************************************************************************//**
*
* Locks/unlocks IMO.
*
* \param lock - the desired IMO lock state, \ref cy_en_sysclk_imo_lock_t
*
* \return Error / status code \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - the lock state is set as requested \n
* \ref CY_SYSCLK_BAD_PARAM - Invalid parameter \n
* \ref CY_SYSCLK_INVALID_STATE - Invalid state (IMO or WCO is not enabled, etc.)
*
* \note Not applicable for PSOC4 HVMS/PA.
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ImoLock(cy_en_sysclk_imo_lock_t lock)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    if ((CY_SYSCLK_IMO_LOCK_NONE == lock) ||
        (CY_SYSCLK_IMO_LOCK_WCO  == lock))
    {
        if (!Cy_SysClk_ImoIsEnabled())
        {
            retVal = CY_SYSCLK_INVALID_STATE;
        }
        else if (lock == Cy_SysClk_ImoGetLockStatus())
        {
            /* Do nothing, the lock is already as requested */
            retVal = CY_SYSCLK_SUCCESS;
        }
        else if ((CY_SYSCLK_IMO_LOCK_NONE == lock))
        {
            WCO_CONFIG &= ~WCO_CONFIG_DPLL_ENABLE_Msk;

#if defined (CY_IP_M0S8SRSSHV)
#error "Device not supported."
#endif /* defined (CY_IP_M0S8SRSSHV) */

            /* Convert the IMO_SELECT_FREQ value into the SFLASH.IMO_TRIM register index */
            SRSS_CLK_IMO_TRIM1 = SFLASH_IMO_TRIM_LT((_FLD2VAL(SRSS_CLK_IMO_SELECT_FREQ, SRSS_CLK_IMO_SELECT) << 2UL));

            retVal = CY_SYSCLK_SUCCESS;
        }
        else if ((CY_SYSCLK_IMO_LOCK_WCO == lock))
        {
            if(!Cy_SysClk_WcoIsEnabled())
            {
                retVal = CY_SYSCLK_INVALID_STATE;
            }
            else
            {
                uint32_t lfLimit = 0UL;
                uint32_t flashCtlReg = 0UL;
                uint32_t dpllMult = 0UL;

#if defined (CY_IP_M0S8SRSSHV)
                /* Avoid lock register's potential race condition. */
                uint32_t intrState = Cy_SysLib_EnterCriticalSection();
                Cy_SysClk_UnlockProtReg();
#endif /* defined (CY_IP_M0S8SRSSHV) */
                /* Set oscillator interface control port to WCO */
                SRSS_CLK_IMO_TRIM1 = 0UL;
#if defined (CY_IP_M0S8SRSSHV)
                Cy_SysClk_LockProtReg();
                Cy_SysLib_ExitCriticalSection(intrState);
#endif /* defined (CY_IP_M0S8SRSSHV) */

                /* Set multiplier to determine IMO frequency in multiples of the WCO frequency */
                dpllMult = CY_SYSLIB_DIV_ROUND(Cy_SysClk_ImoGetFrequency(), CY_SYSCLK_WCO_FREQ) - 1UL;

                /* Config DPLL */
                WCO_DPLL = (_VAL2FLD(WCO_DPLL_DPLL_MULT,     dpllMult) |
                            _VAL2FLD(WCO_DPLL_DPLL_LF_IGAIN, CY_SYSCLK_WCO_DPLL_LF_IGAIN) |
                            _VAL2FLD(WCO_DPLL_DPLL_LF_PGAIN, CY_SYSCLK_WCO_DPLL_LF_PGAIN) |
                            _VAL2FLD(WCO_DPLL_DPLL_LF_LIMIT, 0UL));

                flashCtlReg = CPUSS_FLASH_CTL;
                Cy_SysLib_SetWaitStates(48UL);

                /* Enable DPLL operation */
                WCO_CONFIG |= WCO_CONFIG_DPLL_ENABLE_Msk;

                while (lfLimit <= CY_SYSCLK_WCO_CONFIG_DPLL_LF_LIMIT_MAX)
                {
                    Cy_SysLib_Delay(CY_SYSCLK_WCO_DPLL_TIMEOUT_MS);
                    lfLimit += CY_SYSCLK_WCO_CONFIG_DPLL_LF_LIMIT_STEP;
                    WCO_DPLL = _CLR_SET_FLD32U(WCO_DPLL, WCO_DPLL_DPLL_LF_LIMIT, lfLimit);
                }

                Cy_SysLib_Delay(CY_SYSCLK_WCO_DPLL_TIMEOUT_MS);
                WCO_DPLL = _CLR_SET_FLD32U(WCO_DPLL, WCO_DPLL_DPLL_LF_LIMIT, CY_SYSCLK_WCO_CONFIG_DPLL_LF_LIMIT_MAX);

                CPUSS_FLASH_CTL = flashCtlReg;

                retVal = CY_SYSCLK_SUCCESS;
            }
        }
        else
        {
            /* Do nothing, all the cases are addressed */
        }
    }

    return(retVal);
}
#endif /* (CY_IP_M0S8WCO) */

#if defined (SFLASH_HAS_DYNAMIC_IMO)

/** \cond */
#define CY_SYSCLK_IMO_TRIM2_SIZE            (0x03uL)
#define CY_SYSCLK_IMO_TRIM1_MSK             (0xFFuL)
#define CY_SYSCLK_IMO_TRIM2_MSK             (0x07uL)
#define CY_SYSCLK_IMO_TRIM_MAX_VALUE        (0x07FF)
#define CY_SYSCLK_IMO_TRIM_SCALING          (100)
/** \endcond */


/*******************************************************************************
* Function Name: Cy_SysClk_ImoTempTrim
****************************************************************************//**
*
* Trims the IMO based on tens of degree Celsius.
* For example, 12.3C must pass in as 123.
* Supported only on specific PSOC 4 with additional calibration data in SFLASH.
*
* \param tenthDegreeC - The die temperature in tens of degrees Celsius.
*
*******************************************************************************/
void Cy_SysClk_ImoTempTrim(int16_t tenthDegreeC)
{
    uint32_t imoSel = SRSSLT->CLK_IMO_SELECT;
    int32_t tempStart, tempEnd;
    uint32_t trimStart, trimEnd;
    int32_t trimTarget;

    if (tenthDegreeC < CY_SAR_TEMP_RC_TENTH_DEGREE)
    {
        /* Less than Cold till Room-Cold point */
        tempStart = CY_SAR_TEMP_C_TENTH_DEGREE;
        tempEnd = CY_SAR_TEMP_RC_TENTH_DEGREE;
        trimStart = (uint32_t)CY_SFLASH_IMO_CAL_TRIM->CY_SYSCLK_IMO_TRIM_COLD[imoSel] +
                (uint32_t)CY_SFLASH_IMO_CAL_TRIM->CY_SYSCLK_IMO_TRIM_OFFSET_COLD[imoSel];
        trimEnd = (uint32_t)CY_SFLASH_IMO_CAL_TRIM->CY_SYSCLK_IMO_TRIM_ROOM_COLD[imoSel];
    }
    else if (tenthDegreeC < CY_SAR_TEMP_R_TENTH_DEGREE)
    {
        /* From Room-Cold point till Room point */
        tempStart = CY_SAR_TEMP_RC_TENTH_DEGREE;
        tempEnd = CY_SAR_TEMP_R_TENTH_DEGREE;
        trimStart = (uint32_t)CY_SFLASH_IMO_CAL_TRIM->CY_SYSCLK_IMO_TRIM_ROOM_COLD[imoSel];
        trimEnd = (uint32_t)CY_SFLASH_IMO_CAL_TRIM->CY_SYSCLK_IMO_TRIM_ROOM[imoSel];
    }
    else if (tenthDegreeC < CY_SAR_TEMP_RH_TENTH_DEGREE)
    {
        /* From Room point till Room-Hot point */
        tempStart = CY_SAR_TEMP_R_TENTH_DEGREE;
        tempEnd = CY_SAR_TEMP_RH_TENTH_DEGREE;
        trimStart = (uint32_t)CY_SFLASH_IMO_CAL_TRIM->CY_SYSCLK_IMO_TRIM_ROOM[imoSel];
        trimEnd = (uint32_t)CY_SFLASH_IMO_CAL_TRIM->CY_SYSCLK_IMO_TRIM_ROOM_HOT[imoSel];
    }
    else
    {
        /* From Room-Hot point till above Hot point */
        tempStart = CY_SAR_TEMP_RH_TENTH_DEGREE;
        tempEnd = CY_SAR_TEMP_H_TENTH_DEGREE;
        trimStart = (uint32_t)CY_SFLASH_IMO_CAL_TRIM->CY_SYSCLK_IMO_TRIM_ROOM_HOT[imoSel];
        trimEnd = (uint32_t)CY_SFLASH_IMO_CAL_TRIM->CY_SYSCLK_IMO_TRIM_HOT[imoSel] +
                (uint32_t)CY_SFLASH_IMO_CAL_TRIM->CY_SYSCLK_IMO_TRIM_OFFSET_HOT[imoSel];
    }
    /* Scales trim values to operate in concatenation TRIM1 | TRIM2 */
    trimStart <<= CY_SYSCLK_IMO_TRIM2_SIZE;
    trimEnd <<= CY_SYSCLK_IMO_TRIM2_SIZE;
    /* Calculates percentage in the desired temperature region */
    trimTarget = (((int32_t)tenthDegreeC - tempStart) * CY_SYSCLK_IMO_TRIM_SCALING) / (tempEnd - tempStart);
    trimTarget *= (int32_t)trimEnd - (int32_t)trimStart;
    /* Calculates trim value with rounding */
    trimTarget = ((trimTarget + (CY_SYSCLK_IMO_TRIM_SCALING / 2)) / CY_SYSCLK_IMO_TRIM_SCALING) + ((int32_t)trimStart);
    /* Avoids overflow */
    if (0 > trimTarget)
    {
        trimTarget = 0;
    }
    if (CY_SYSCLK_IMO_TRIM_MAX_VALUE < trimTarget)
    {
        trimTarget = CY_SYSCLK_IMO_TRIM_MAX_VALUE;
    }
    /* Stores calculated trim value into target registers */
    SRSSLT->CLK_IMO_TRIM1 = ((uint32_t)trimTarget >> CY_SYSCLK_IMO_TRIM2_SIZE) & CY_SYSCLK_IMO_TRIM1_MSK;
    SRSSLT->CLK_IMO_TRIM2 = ((uint32_t)trimTarget) & CY_SYSCLK_IMO_TRIM2_MSK;
}
#endif


/* ========================================================================== */
/* ===========================    ILO SECTION    ============================ */
/* ========================================================================== */

/** \cond */
/* These variables act as locks to prevent collisions between ILO measurement and entry into
   Deep Sleep mode. See Cy_SysClk_DeepSleep(). */
static bool iloMeasurment = false;
static bool preventIloMeasurment = false;

#define SRSS_CLK_DFT_SELECT_DFT_SEL_NC  (0UL) /* DFT_SEL not connected (output is 0) */
#define SRSS_CLK_DFT_SELECT_DFT_SEL_ILO (1UL) /* DFT_SEL ILO output */

#define SRSS_CLK_DFT_SELECT_DFT_CHCK_MSK (SRSS_CLK_DFT_SELECT_DFT_SEL0_Msk | \
                                            SRSS_CLK_DFT_SELECT_DFT_SEL1_Msk)
#define SRSS_CLK_DFT_SELECT_DFT_CHCK_VAL (_VAL2FLD(SRSS_CLK_DFT_SELECT_DFT_SEL0, \
                                                     SRSS_CLK_DFT_SELECT_DFT_SEL_NC) | \
                                            _VAL2FLD(SRSS_CLK_DFT_SELECT_DFT_SEL1, \
                                                     SRSS_CLK_DFT_SELECT_DFT_SEL_ILO))

#define SRSS_TST_DDFT_CTRL_DFT_SEL_CLK0   (8UL)
#define SRSS_TST_DDFT_CTRL_DFT_SEL_CLK1   (9UL)

#define SRSS_TST_DDFT_CTRL_DFT_SEL_Pos    (SRSS_TST_DDFT_CTRL_DFT_SEL0_Pos)
#define SRSS_TST_DDFT_CTRL_DFT_SEL_Msk    (SRSS_TST_DDFT_CTRL_DFT_SEL0_Msk | SRSS_TST_DDFT_CTRL_DFT_SEL1_Msk)


/** \endcond */


/******************************************************************************
* Function Name: Cy_SysClk_IloStartMeasurement
***************************************************************************//**
*
* \brief
* Prepares the DFT hardware to perform the ILO accuracy measurement.
*
* This function is non-blocking and needs to be called before using the
* \ref Cy_SysClk_IloCompensate() function.
*
* This function configures measurement counters to be sourced:
* - by SysClk (Counter 1) for non PSOC4 HV devices
* - by IMO (Counter 1) for PSOC4 HV devices
*
* and ILO (Counter 2).
*
* \note for PSOC4 HV devices Calib mechanism used for compensation \ref group_sysclk_calclk_funcs
* \note for non PSOC4 HV devices SysClk should be clocked by IMO, otherwise
* Cy_SysClk_IloCompensate() function can give incorrect results.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_WDT_ISR
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_WDT_CFG
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_ILO_COMPENSATE
*
******************************************************************************/
void Cy_SysClk_IloStartMeasurement(void)
{

    if (!preventIloMeasurment)
    {
        iloMeasurment = true;
#if defined(CY_IP_S8SRSSLT)
        /* Configure measurement counters to source by SysClk (Counter 1) and ILO (Counter 2)*/
        CY_REG32_CLR_SET(SRSS_CLK_DFT_SELECT,
                         SRSS_CLK_DFT_SELECT_DFT_SEL1,
                         SRSS_CLK_DFT_SELECT_DFT_SEL_ILO);

        CY_REG32_CLR_SET(SRSS_TST_DDFT_CTRL,
                         SRSS_TST_DDFT_CTRL_DFT_SEL,
               (_VAL2FLD(SRSS_TST_DDFT_CTRL_DFT_SEL0,
                         SRSS_TST_DDFT_CTRL_DFT_SEL_CLK0) |
                _VAL2FLD(SRSS_TST_DDFT_CTRL_DFT_SEL1,
                         SRSS_TST_DDFT_CTRL_DFT_SEL_CLK1)));
#elif defined (CY_IP_M0S8SRSSHV)
        /* Cy_SysClk_ImoGetFrequency = frequency in Hz
         * Cy_SysClk_ImoGetFrequency ticks - will take 1 sec
         * Cy_SysClk_ImoGetFrequency/1000 ticks - will take ~1msec
         */
        (void)Cy_SysClk_CalibStart(CY_SYSCLK_MEAS_CLK_IMO,
                                   (uint16_t)(Cy_SysClk_ImoGetFrequency()/CY_SYSCLK_MILLI_SCALER),
                                   CY_SYSCLK_MEAS_CLK_ILO);
#endif /* defined(CY_IP_S8SRSSLT) */
    }
}


/******************************************************************************
* Function Name: Cy_SysClk_IloStopMeasurement
***************************************************************************//**
* \brief
* Cleans the DFT hardware registers, returning it to the default state.
*
* Calling this function immediately stops the the ILO frequency measurement.
* Call this function before placing the device to deepsleep, if
* \ref Cy_SysClk_IloStartMeasurement() API was called before.
*
* \note This function is not allowed to call immediately
*       after the \ref Cy_SysClk_IloStartMeasurement.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_WDT_ISR
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_WDT_CFG
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_ILO_COMPENSATE
*
******************************************************************************/
void Cy_SysClk_IloStopMeasurement(void)
{
    if (!preventIloMeasurment)
    {
        iloMeasurment = false;
#if defined(CY_IP_S8SRSSLT)
        /* Set default configurations in 11...8 DFT register bits to zero */
        SRSS_CLK_DFT_SELECT &= ~SRSS_CLK_DFT_SELECT_DFT_SEL1_Msk;
        SRSS_TST_DDFT_CTRL &= SRSS_TST_DDFT_CTRL_DFT_SEL_Msk;
#elif defined(CY_IP_M0S8SRSSHV)
        /* by default
         * no clocks set,
         * no dividers for both clock sources,
         * positive edge of the clock selected for dividers
         */
        SRSS_CLK_DFT_SELECT = 0UL;
#endif /* defined(CY_IP_S8SRSSLT) */
    }
}


#define MAX_DELAY_US                     (0x1E8480UL) /* 2s */
#define MIN_DELAY_US                     (0x64UL)     /* 100 us */
#define COEF_PHUNDRED                    (0x64UL)   /* 100 */
#define ILO_PERIOD_PPH                   (0x09C4UL) /* 2500 */
#define SYS_CLK_DIVIDER                  (0x0AUL) /* 10 */
#define ILO_FREQ_2MSB                    (0x28UL) /* 40 */
#define ILO_FREQ_3LSB                    (0x3E8UL) /* 1000 */
#define ILO_DESIRED_FREQ_HZ              (40000UL) /* 40kHz */

/**********************************************************************************
* Cy_SysClk_IloCompensate() - value to walk over oversampling in calculations with
* srsslite. The oversample can be obtained when ilo frequency in equal 80 KHz and
* desired clocks are 80 000 clocks.
**********************************************************************************/

/******************************************************************************
* Function Name: Cy_SysClk_IloCompensate
***************************************************************************//**
*
* \brief Measures the current ILO accuracy.
*
* Basing on the measured frequency the required number of ILO cycles for a
* given delay (in microseconds) is obtained. The desired delay that needs to
* be compensated is passed through the desiredDelay parameter. The compensated
* cycle count is returned through the compesatedCycles pointer.
* The compensated ILO cycles can then be used to define the WDT period value,
* effectively compensating for the ILO inaccuracy and allowing a more
* accurate WDT interrupt generation.
* This function starts timers, and if they are already running, their status
* is checked. If the timer has reached 0, then it is considered that it has
* already measured and calculated, how many cycles are
* needed for DesiredDelay and returns "success".
* The Cy_SysClk_IloCompensate function execution time is always ~ 1ms.
*
* \ref Cy_SysClk_IloStartMeasurement() function should be called prior to calling this function.
*
* \note SysClk should be clocked by IMO, otherwise the
* Cy_SysClk_IloCompensate() function can give incorrect results.
*
* \note If the System clock frequency is changed in runtime, the
* \ref SystemCoreClockUpdate() should be called before
* calling a next Cy_SysClk_IloCompensate().
*
* \note For a correct WDT or DeepSleep Timers functioning with ILO compensating
* the \ref Cy_SysClk_IloCompensate() should be called before WDT or DeepSleep Timers
* enabling.
*
* \warning Do not enter Deep Sleep mode until the function returns CY_SYSCLK_SUCCESS.
*
* \param desiredDelay Required delay in microseconds.
*                     Valid range is 100 ... 2 000 000 us.
*
* \note The desiredDelay range 100..2000000 is mathematically possible, but:\n
* Physically, the longest WDT period is 65536 * ILO clock period,\n
* which is nominally 25us, so the real maximum desiredDelay is 1.63s @40kHz ILO.\n
* The 100us is about a four ILO clocks, so such a small desiredDelay may be imprecise (~25% of error or even more).\n
* Therefore, the range 1ms..1s (1000...1000000) is recommended as practically applicable.
*
* \param *compensatedCycles The pointer to the variable in which the required
* number of ILO cycles for the given delay will be returned.
*
* \details The value returned in *compensatedCycles pointer is not valid until the
* function returns CY_SYSCLK_SUCCESS.
*
* \return The status \ref cy_en_sysclk_status_t
* - \ref CY_SYSCLK_SUCCESS - The compensation process is complete and the
* compensated cycles value is returned in the compensatedCycles pointer.
* - \ref CY_SYSCLK_BAD_PARAM - One or more invalid parameters
* - \ref CY_SYSCLK_STARTED - Indicates measurement is in progress. It is
* strongly recommended to do not make pauses between API calling. The
* function should be called repeatedly until the API returns CY_SYSCLK_SUCCESS.
* - \ref CY_SYSCLK_INVALID_STATE - Indicates that measurement not started.
* The user should call \ref Cy_SysClk_IloStartMeasurement() API before calling
* this function.
* \note for PSOC4 HV used Calib mechanism used for compensation \ref group_sysclk_calclk_funcs
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_WDT_ISR
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_WDT_CFG
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_ILO_COMPENSATE
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_IloCompensate(uint32_t desiredDelay , uint32_t * compensatedCycles)
{
#if defined(CY_IP_S8SRSSLT)
    uint32_t iloCompensatedCycles;
    uint32_t desiredDelayInCounts;
    static bool compRunStat = false; /* compensation running status */
#endif /* defined(CY_IP_S8SRSSLT) */
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;

    if ((MIN_DELAY_US > desiredDelay) ||
        (MAX_DELAY_US < desiredDelay) ||
        (NULL == compensatedCycles))
    {
        retVal = CY_SYSCLK_BAD_PARAM;
        return (retVal);
    }
#if defined(CY_IP_S8SRSSLT)
    /* Check if CySysStartMeasurement was called before */
    bool ddftClkSel = (SRSS_TST_DDFT_CTRL == (_VAL2FLD(SRSS_TST_DDFT_CTRL_DFT_SEL0,
                                           SRSS_TST_DDFT_CTRL_DFT_SEL_CLK0) |
                                  _VAL2FLD(SRSS_TST_DDFT_CTRL_DFT_SEL1,
                                           SRSS_TST_DDFT_CTRL_DFT_SEL_CLK1)));
    bool ddftCheck = (SRSS_CLK_DFT_SELECT_DFT_CHCK_VAL == (SRSS_CLK_DFT_SELECT & SRSS_CLK_DFT_SELECT_DFT_CHCK_MSK));
    /* Check if CySysStartMeasurement was called before */
    if (ddftClkSel && ddftCheck)
    {
        if(compRunStat)
        {
            /* Wait until counter 1 stopped counting and after it calculate compensated cycles */
            if(0UL != (SRSSLT_TST_TRIM_CNTR1 & SRSSLT_TST_TRIM_CNTR1_COUNTER_DONE_Msk))
            {
                if (0UL != SRSSLT_TST_TRIM_CNTR2)
                {
                    /* Calculate required number of ILO cycles for given delay */
                    desiredDelayInCounts = CY_SYSLIB_DIV_ROUND(desiredDelay * COEF_PHUNDRED, ILO_PERIOD_PPH);

                    if ((SRSSLT_TST_TRIM_CNTR2 * desiredDelayInCounts) > (0xFFFFFFFFu >> SYS_CLK_DIVIDER))
                    {
                        iloCompensatedCycles = (((SRSSLT_TST_TRIM_CNTR2 * SystemCoreClock) /
                            (SystemCoreClock >> SYS_CLK_DIVIDER)) / ILO_FREQ_2MSB) * (desiredDelayInCounts / ILO_FREQ_3LSB);
                    }
                    else
                    {
                        iloCompensatedCycles = (((SRSSLT_TST_TRIM_CNTR2 * SystemCoreClock) /
                            (SystemCoreClock >> SYS_CLK_DIVIDER)) * desiredDelayInCounts) / ILO_DESIRED_FREQ_HZ;
                    }

                    *compensatedCycles = iloCompensatedCycles;
                    compRunStat = false;
                    retVal = CY_SYSCLK_SUCCESS;
                }
            }
            else
            {
                retVal = CY_SYSCLK_STARTED;
            }
        }
        else
        {
            /* Reload CNTR 1 count value for next measurement cycle*/
            SRSSLT_TST_TRIM_CNTR1 = (SystemCoreClock >> SYS_CLK_DIVIDER);
            compRunStat = true;
            retVal = CY_SYSCLK_STARTED;
        }
    }
#elif defined(CY_IP_M0S8SRSSHV)
    if(0UL != SRSS_CLK_DFT_SELECT)
    {
        /* Cy_SysClk_CalibGetFreq returns calibrated ILO frequency using
         * Cy_SysClk_ImoGetFrequency()/1000UL ticks of IMO as reference
         */
        /* Wait until calibration is done */
        while(!Cy_SysClk_CalibDone())
        {
        }
        uint64_t ILOFrequency = Cy_SysClk_CalibGetFreq(true,(uint16_t)(Cy_SysClk_ImoGetFrequency()/CY_SYSCLK_MILLI_SCALER));
        *compensatedCycles = (uint32_t)CY_SYSLIB_DIV_ROUND((ILOFrequency * desiredDelay), CY_SYSCLK_MICRO_SCALER);
        retVal = CY_SYSCLK_SUCCESS;
    }
#endif /* defined(CY_IP_S8SRSSLT) */
    else
    {
        /* Do nothing, return CY_SYSCLK_INVALID_STATE */
    }

    return (retVal);
}

#if (defined(CY_IP_M0S8EXCO) && (CY_IP_M0S8EXCO == 1u)) || defined(CY_DOXYGEN)
/* ========================================================================== */
/* ===========================    ECO SECTION    ============================ */
/* ========================================================================== */

#define CY_SYSCLK_ECO_CONFIG_CLK_EN_TIMEOUT_US (10U)


/** \cond *********************************************************************
* Function Name: cy_sqrt
* Calculates square root.
* input is 32-bit wide.
* result is 16-bit wide.
*******************************************************************************/
static uint32_t cy_sqrt(uint32_t x);
static uint32_t cy_sqrt(uint32_t x)
{
    uint32_t i;
    uint32_t res = 0UL;
    uint32_t add = 0x8000UL;

    for(i = 0UL; i < 16UL; i++)
    {
        uint32_t tmp = res | add;

        if (x >= (tmp * tmp))
        {
            res = tmp;
        }

        add >>= 1U;
    }

    return (res);
}

static uint32_t ecoFreq = 0UL; /* Internal storage for ECO frequency user setting */

#define CY_SYSCLK_ECO_FREQ_MIN (4000000UL)  /* 4 MHz */
#define CY_SYSCLK_ECO_FREQ_MAX (33330000UL) /* 33.33 MHz */
#define CY_SYSCLK_ECO_CLD_MAX  (100UL)      /* 100 pF */
#define CY_SYSCLK_ECO_ESR_MAX  (1000UL)     /* 1000 Ohm */
#define CY_SYSCLK_ECO_DRV_MAX  (2000UL)     /* 2 mW */

#define CY_SYSCLK_ECO_IS_FREQ_VALID(freq) ((CY_SYSCLK_ECO_FREQ_MIN <= (freq)) && ((freq) <= CY_SYSCLK_ECO_FREQ_MAX))
#define CY_SYSCLK_ECO_IS_CLD_VALID(cld)   ((0UL < (cld)) && ((cld) <= CY_SYSCLK_ECO_CLD_MAX))
#define CY_SYSCLK_ECO_IS_ESR_VALID(esr)   ((0UL < (esr)) && ((esr) <= CY_SYSCLK_ECO_ESR_MAX))
#define CY_SYSCLK_ECO_IS_DRV_VALID(drv)   ((0UL < (drv)) && ((drv) <= CY_SYSCLK_ECO_DRV_MAX))
/** \endcond */


/**
* \addtogroup group_sysclk_eco_funcs
* \{
*/

/*******************************************************************************
* Function Name: Cy_SysClk_EcoConfigure
****************************************************************************//**
*
* Configures the external crystal oscillator (ECO) trim bits based on crystal
* characteristics. This function should be called only when the ECO is disabled.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \param freq Operating frequency of the crystal in Hz.
* Valid range: 4000000...33330000 (4..33.33 MHz).
*
* \param cLoad Crystal load capacitance in pF.
* Valid range: 1...100.
*
* \param esr Effective series resistance of the crystal in ohms.
* Valid range: 1...1000.
*
* \param driveLevel Crystal drive level in uW.
* Valid range: 1...2000.
*
* \return Error / status code \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - ECO configuration completed successfully \n
* \ref CY_SYSCLK_BAD_PARAM - One or more invalid parameters \n
* \ref CY_SYSCLK_INVALID_STATE - ECO already enabled
*
* \note
* The following calculations are implemented in integer 32-bitwise math:
*
* \verbatim
*   freqKhz = freq / 1000
*   maxAmpl = sqrt(drivelevel / 2 / esr) / 3.14 / freqKhz / cLoad
*   ampSect = INT(5 * 4 * 3.14^2 * freqKhz^2 * cLoad^2 * 4 * esr / 1000000000 / 1000000 / 4.5)
*
*   As a result of the above calculations, maxAmpl must be >= 0.5, and the
*   number of amplifier sections must be <= 3, otherwise this function returns with
*   a parameter error.
*
*   atrim = maxAmpl < 0.6 ? 0 :
*           maxAmpl < 0.7 ? 1 :
*           maxAmpl < 0.8 ? 2 :
*           maxAmpl < 0.9 ? 3 :
*           maxAmpl < 1.025 ? 4 :
*           maxAmpl < 1.150 ? 5 :
*           maxAmpl < 1.275 ? 6 : 7

*   wdtrim = maxAmpl < 1.2 ? INT(5 * maxAmpl) - 2 : 3

*   gtrim = ampSect > 1 ? ampSect : ampSect == 1 ? 0 : 1

*   rtrim = freqKhz > 30000 ? 0 :
*           freqMHz > 24000 ? 1 :
*           freqMHz > 17000 ? 2 : 3
*
*   ftrim = rtrim
*
* \endverbatim
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_EcoConfigure
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_EcoConfigure(uint32_t freq, uint32_t cLoad, uint32_t esr, uint32_t driveLevel)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    if (Cy_SysClk_EcoIsEnabled())
    {
        retVal = CY_SYSCLK_INVALID_STATE;
    }
    else if ((CY_SYSCLK_ECO_IS_FREQ_VALID(freq)) &&
             (CY_SYSCLK_ECO_IS_CLD_VALID(cLoad)) &&
             (CY_SYSCLK_ECO_IS_ESR_VALID(esr))   &&
             (CY_SYSCLK_ECO_IS_DRV_VALID(driveLevel)))
    {
        uint32_t freqKhz = CY_SYSLIB_DIV_ROUND(freq, 1000UL);

        /* calculate intermediate values */
        uint32_t maxAmpl = CY_SYSLIB_DIV_ROUND((159155UL * /* 5 * 100000 / PI */
                   cy_sqrt(CY_SYSLIB_DIV_ROUND(2000000UL * driveLevel, esr))), /* scaled by 2 */
                                               (freqKhz * cLoad)); /* The result is scaled by 10^3 */

        /* (4.5 * 10^9) / (5 * 4 * 4 * PI^2) = 5699316,5798814996437182198055472.. -> 56993, scaled by 100 */
        uint32_t ampSect = (CY_SYSLIB_DIV_ROUND(cLoad * cLoad *
                            CY_SYSLIB_DIV_ROUND(freqKhz * freqKhz, 56993UL), 1000UL) * esr) / 1000000UL;

        if ((maxAmpl >= 500UL) && (ampSect <= 3UL)) /* Error if input parameters cause erroneous intermediate values */
        {
            uint32_t wdtrim = (maxAmpl < 1200UL) ? (5UL * maxAmpl / 1000UL) - 2UL : 3UL;

            uint32_t atrim = (maxAmpl < 600UL)  ? 0UL :
                            ((maxAmpl < 700UL)  ? 1UL :
                            ((maxAmpl < 800UL)  ? 2UL :
                            ((maxAmpl < 900UL)  ? 3UL :
                            ((maxAmpl < 1025UL) ? 4UL :
                            ((maxAmpl < 1150UL) ? 5UL :
                            ((maxAmpl < 1275UL) ? 6UL : 7UL))))));

            uint32_t ftrim = ((freq > 30000000UL) ? 0UL :
                              ((freq > 24000000UL) ? 1UL :
                               ((freq > 17000000UL) ? 2UL : 3UL)));

            uint32_t gtrim = (ampSect > 1UL) ? ampSect :
                            ((ampSect == 1UL) ? 0UL : 1UL);

            EXCO_ECO_CONFIG = (maxAmpl < 2000UL) ? EXCO_ECO_CONFIG_AGC_EN_Msk : 0x0UL;

            EXCO_ECO_TRIM0 = _VAL2FLD(EXCO_ECO_TRIM0_WDTRIM, wdtrim) |
                             _VAL2FLD(EXCO_ECO_TRIM0_ATRIM, atrim);

            EXCO_ECO_TRIM1 = _VAL2FLD(EXCO_ECO_TRIM1_FTRIM, ftrim) |
                             _VAL2FLD(EXCO_ECO_TRIM1_RTRIM, ftrim) | /* rtrim = ftrim */
                             _VAL2FLD(EXCO_ECO_TRIM1_GTRIM, gtrim);

            ecoFreq = freq; /* Store the ECO frequency */

            retVal = CY_SYSCLK_SUCCESS;
        }
    }
    else
    {
        /* return CY_SYSCLK_BAD_PARAM */
    }

    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_EcoEnable
****************************************************************************//**
*
* Enables the external crystal oscillator (ECO). This function should be called
* after \ref Cy_SysClk_EcoConfigure.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \param timeoutUs Amount of time in microseconds to wait for the ECO to stabilize.
* To avoid waiting for stabilization, set this parameter to 0.
*
* \return Error / status code \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - ECO is enabled \n
* \ref CY_SYSCLK_TIMEOUT - ECO timed out and did not stabilized \n
* \ref CY_SYSCLK_INVALID_STATE - ECO is not configured using \ref Cy_SysClk_EcoConfigure.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_EcoConfigure
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_EcoEnable(uint32_t timeoutUs)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;

    /* Invalid state error if ECO is not configured */
    if (0UL != ecoFreq)
    {
        bool zeroTimeout = (0UL == timeoutUs);

        if (!Cy_SysClk_EcoIsEnabled())
        {
            EXCO_ECO_CONFIG |= EXCO_ECO_CONFIG_ENABLE_Msk;
            Cy_SysLib_DelayUs(CY_SYSCLK_ECO_CONFIG_CLK_EN_TIMEOUT_US);
            EXCO_ECO_CONFIG |= EXCO_ECO_CONFIG_CLK_EN_Msk;
        }

        /* Wait for CY_SYSCLK_ECOSTAT_STABLE */
        while ((CY_SYSCLK_ECO_STABLE != Cy_SysClk_EcoGetStatus()) && (0UL != timeoutUs))
        {
            timeoutUs--;
            Cy_SysLib_DelayUs(1U);
        }

        if (zeroTimeout || (0UL != timeoutUs))
        {
            retVal = CY_SYSCLK_SUCCESS;
        }
        else
        {
            retVal = CY_SYSCLK_TIMEOUT;
            Cy_SysClk_EcoDisable();
        }
    }

    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_EcoGetFrequency
****************************************************************************//**
*
* Returns the frequency of the external crystal oscillator (ECO).
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \return The frequency of the ECO.
*
* \note If the ECO is not enabled or stable - a zero is returned.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_EcoConfigure
*
*******************************************************************************/
uint32_t Cy_SysClk_EcoGetFrequency(void)
{
    return ((Cy_SysClk_EcoIsEnabled() && (CY_SYSCLK_ECO_STABLE == Cy_SysClk_EcoGetStatus())) ? ecoFreq : 0UL);
}
/** \} group_sysclk_eco_funcs */


#if (defined(EXCO_PLL_PRESENT) && (EXCO_PLL_PRESENT == 1u)) || defined(CY_DOXYGEN)
/* ========================================================================== */
/* ===========================    PLL SECTION    ============================ */
/* ========================================================================== */

#if (defined (EXCO_PLL_REF_IN_EN) && (EXCO_PLL_REF_IN_EN == 1u)) || defined(CY_DOXYGEN)

#if (CY_IP_M0S8EXCO_VERSION == 1U)
#define  CY_SYSCLK_PLL_IS_SRC_VALID(src) (((src) == CY_SYSCLK_PLL_SRC_ECO) || \
                                          ((src) == CY_SYSCLK_PLL_SRC_IMO))
#else /* (CY_IP_M0S8EXCO_VERSION == 2U) */
#define  CY_SYSCLK_PLL_IS_SRC_VALID(src) (((src) == CY_SYSCLK_PLL_SRC_ECO)    || \
                                          ((src) == CY_SYSCLK_PLL_SRC_EXTREF) || \
                                          ((src) == CY_SYSCLK_PLL_SRC_IMO))
#endif /* (CY_IP_M0S8EXCO_VERSION == 1U) */

#define CY_SYSCLK_EXCO_PGM_CLK_SEQ_GEN (8UL)


/*******************************************************************************
* Function Name: Cy_SysClk_EcoSeqGen
********************************************************************************
*
* Generates the ECO clock sequence for EXCO MUX switching if ECO is disabled.
*
*******************************************************************************/
static void Cy_SysClk_EcoSeqGen(void)
{
    if (0UL == Cy_SysClk_EcoGetFrequency()) /* If ECO is not working */
    {
        /* Generate clock sequence to change clock source in CY_SYS_ECO_CLK_SELECT_REG */
        EXCO_EXCO_PGM_CLK |= EXCO_EXCO_PGM_CLK_ENABLE_Msk;

        for(uint32_t i = 0UL; i < CY_SYSCLK_EXCO_PGM_CLK_SEQ_GEN; i++)
        {
            EXCO_EXCO_PGM_CLK |= EXCO_EXCO_PGM_CLK_CLK_ECO_Msk;
            EXCO_EXCO_PGM_CLK &= ~EXCO_EXCO_PGM_CLK_CLK_ECO_Msk;
        }

        EXCO_EXCO_PGM_CLK &= ~EXCO_EXCO_PGM_CLK_ENABLE_Msk;
    }
}

/**
* \addtogroup group_sysclk_pll_funcs
* \{
*/

/*******************************************************************************
* Function Name: Cy_SysClk_PllSetSource
****************************************************************************//**
*
* Selects the PLL reference clock of the selected HFCLK.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
*
* \param source \ref cy_en_sysclk_pll_src_t
*
* \return  Error / status code \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - the PLL reference clock source is selected \n
* \ref CY_SYSCLK_INVALID_STATE - the PLL reference clock source is not enabled \n
* \ref CY_SYSCLK_BAD_PARAM - some input parameter is invalid
*
* \note Call \ref SystemCoreClockUpdate after this function calling if
* SYSCLK frequency is affected.
*
* \note Call \ref Cy_SysLib_SetWaitStates before this function calling if
* SYSCLK frequency is increasing.
*
* \note Call \ref Cy_SysLib_SetWaitStates after this function calling if
* SYSCLK frequency is decreasing.
*
* \note In case of switching to the \ref CY_SYSCLK_PLL_SRC_EXTREF the
* EXTREF frequency should be specified using \ref Cy_SysClk_ExtRefSetFrequency.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_PLL_SRC_SW
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PllSetSource(uint32_t pllNum, cy_en_sysclk_pll_src_t source)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    if ((0UL == pllNum) && CY_SYSCLK_PLL_IS_SRC_VALID(source))
    {
        if (((CY_SYSCLK_PLL_SRC_ECO == source) && (0UL != Cy_SysClk_EcoGetFrequency())) ||
#if (CY_IP_M0S8EXCO_VERSION == 2U)
            ((CY_SYSCLK_PLL_SRC_EXTREF == source) && (0UL != Cy_SysClk_ExtRefGetFrequency())) ||
#endif /* (CY_IP_M0S8EXCO_VERSION == 2U) */
            ((CY_SYSCLK_PLL_SRC_IMO == source) && Cy_SysClk_ImoIsEnabled()))
        {
            CY_REG32_CLR_SET(EXCO_CLK_SELECT, EXCO_CLK_SELECT_REF_SEL, source);
            Cy_SysClk_EcoSeqGen();
            retVal = CY_SYSCLK_SUCCESS;
        }
        else
        {
            retVal = CY_SYSCLK_INVALID_STATE;
        }
    }

    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PllBypass
****************************************************************************//**
*
* Sets PLL bypass mode.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
*
* \param mode the bypass mode \ref cy_en_sysclk_pll_bypass_t.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the HFCLK frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the PLL is the source of HFCLK and the HFCLK frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the PLL is the source of HFCLK and the HFCLK frequency is decreasing.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c snippet_Cy_SysClk_EcoPllHfClk
*
*******************************************************************************/
void Cy_SysClk_PllBypass(uint32_t pllNum, cy_en_sysclk_pll_bypass_t mode)
{
    CY_ASSERT_L1(0UL == pllNum);
    if (0UL == pllNum)
    {
        CY_REG32_CLR_SET(EXCO_PLL_CONFIG, EXCO_PLL_CONFIG_BYPASS_SEL, mode);
        Cy_SysClk_EcoSeqGen();
    }
}
/** \} group_sysclk_pll_funcs */
#endif /* (EXCO_PLL_REF_IN_EN == 1u) */


/* PLL REFERENCE_DIV bitfield allowable range */
#define PLL_MIN_REF_DIV      (0x00UL)
#define PLL_MAX_REF_DIV      (0x3FUL)

/* PLL FEEDBACK_DIV bitfield allowable range selection */
#define PLL_MIN_FB_DIV   (8UL)
#define PLL_MAX_FB_DIV   (255UL)

/* PLL OUTPUT_DIV bitfield allowable range */
#define PLL_MIN_OUT_DIV  (0UL)
#define PLL_MAX_OUT_DIV  (3UL)

/* Internal PLL frequencies ranges */
#define PLL_MIN_FVCO     (22500000UL)
#define PLL_THR_FVCO     (67000000UL) /* Threshold for ICP setting */
#define PLL_MAX_FVCO     (104000000UL)
#define PLL_MIN_FPFD     (1000000UL)
#define PLL_MAX_FPFD     (3000000UL)

/* PLL input and output frequency limits */
#define PLL_MIN_IN_FREQ  (1000000UL)
#define PLL_MAX_IN_FREQ  (48000000UL)
#define PLL_MIN_OUT_FREQ (PLL_MIN_FVCO / (1UL << PLL_MAX_OUT_DIV))
#define PLL_MAX_OUT_FREQ ((PLL_MAX_FVCO > CY_SYSCLK_HF_CLK_MAX_FREQ) ? CY_SYSCLK_HF_CLK_MAX_FREQ : PLL_MAX_FVCO)

#define PLL_ICP_SEL_LT67MHZ (2U) /* For FVCO frequency <= 67 MHz */
#define PLL_ICP_SEL_GT67MHZ (3U) /* For FVCO frequency > 67 MHz */

/**
* \addtogroup group_sysclk_pll_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_PllConfigure
****************************************************************************//**
*
* Configures a given PLL.
* The configuration formula used is: \n
*   Fout = Fin * P / (Q + 1) / (1 << OUT) \n
*   where: \n
*     Fout is the real PLL output frequency \n
*     Fin is the frequency of the input clock source \n
*     P is the feedback divider. Its value is in bitfield FEEDBACK_DIV. \n
*     Q is the reference divider. Its value is in bitfield REFERENCE_DIV. \n
*     OUT is the output divider. Its value is in bitfield OUTPUT_DIV.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
*
* \param config The pointer to a configuration structure \ref cy_stc_sysclk_pll_config_t
*
* \return  Error / status code \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - PLL successfully configured \n
* \ref CY_SYSCLK_INVALID_STATE - PLL not configured because it is already enabled \n
* \ref CY_SYSCLK_BAD_PARAM - One or more invalid parameters.
*
* \note
* In case of returning CY_SYSCLK_BAD_PARAM the function does not write anything into
* the configuration register, so either the previous correct configuration or
* the default configuration remains in the register.
*
* \note
* Call this function after changing the PLL input frequency, for example if
* \ref Cy_SysClk_ImoSetFrequency() or \ref Cy_SysClk_PllSetSource() is called.
*
* \note
* Do not call this function when the PLL is enabled. If it is called, then this function
* returns immediately with an error return value and no register updates.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the HFCLK frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the PLL is the source of HFCLK and the PLL frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the PLL is the source of HFCLK and the PLL frequency is decreasing.
*
* \note
* Due to the integer nature of the P, Q and OUT dividers,
* the real PLL output frequency could slightly differ from the desired value
* (specified by the \ref cy_stc_sysclk_pll_config_t::outputFreq).
* So please check the real PLL output frequency using \ref Cy_SysClk_PllGetFrequency.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PllConfigure
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PllConfigure(uint32_t pllNum, const cy_stc_sysclk_pll_config_t *config)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint32_t inputFreq = 0U;

    if (0UL == config->inputFreq)
    {
        if (CY_SYSCLK_PLL_SRC_ECO == Cy_SysClk_PllGetSource(pllNum))
        {
            inputFreq = Cy_SysClk_EcoGetFrequency();
        }
    #if (CY_IP_M0S8EXCO_VERSION == 2U)
        else if (CY_SYSCLK_PLL_SRC_EXTREF == Cy_SysClk_PllGetSource(pllNum))
        {
            inputFreq = Cy_SysClk_ExtRefGetFrequency();
        }
    #endif /* (CY_IP_M0S8EXCO_VERSION == 2U) */
        else /* IMO */
        {
            inputFreq = Cy_SysClk_ImoGetFrequency();
        }

        if (0UL == inputFreq)
        {
            retVal = CY_SYSCLK_INVALID_STATE;
        }
    }
    else
    {
        inputFreq = config->inputFreq;
    }

    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 14.3', 4, \
    'The CY_SYSCLK_HF_CLK_MAX_FREQ is device-specific, and so PLL_MAX_OUT_FREQ expression may be invariant.');
    if ((PLL_MIN_IN_FREQ <= inputFreq)  && (inputFreq <= PLL_MAX_IN_FREQ) &&
        (PLL_MIN_OUT_FREQ <= config->outputFreq) && (config->outputFreq <= PLL_MAX_OUT_FREQ))
    {
        cy_stc_sysclk_pll_manual_config_t manualConfig = {0U, 0U, 0U, 0U};

        /* for each possible value of OUTPUT_DIV and REFERENCE_DIV (Q), try
           to find a value for FEEDBACK_DIV (P) that gives an output frequency
           as close as possible to the desired output frequency. */
        uint32_t q, fpfd;
        uint32_t foutBest = 0UL; /* to ensure at least one pass through the for loops below */

        /* REFERENCE_DIV (Q) selection */
        for (q = PLL_MIN_REF_DIV; q <= PLL_MAX_REF_DIV; q++)
        {
            fpfd = CY_SYSLIB_DIV_ROUND(inputFreq, 1UL + q);

            if ((PLL_MIN_FPFD <= fpfd) && (fpfd <= PLL_MAX_FPFD))
            {
                uint32_t p, fvco;

                /* FEEDBACK_DIV (P) selection */
                for (p = PLL_MIN_FB_DIV; p <= PLL_MAX_FB_DIV; p++)
                {
                    /* Calculate the intermediate Fvco, and make sure that it's in range */
                    fvco = fpfd * p;

                    if ((PLL_MIN_FVCO <= fvco) && (fvco <= PLL_MAX_FVCO))
                    {
                        uint32_t out;

                        /* OUTPUT_DIV selection */
                        for (out = PLL_MIN_OUT_DIV; out <= PLL_MAX_OUT_DIV; out++)
                        {
                            /* Calculate what output frequency will actually be produced.
                               If it's closer to the target than what we have so far, then save it. */
                            uint32_t fout = CY_SYSLIB_DIV_ROUND(fvco, 1UL << out);

                            if (((uint32_t)abs((int32_t)fout - (int32_t)(config->outputFreq)) <
                                 (uint32_t)abs((int32_t)foutBest - (int32_t)(config->outputFreq))) &&
                                                       (fout <= PLL_MAX_OUT_FREQ))
                            {
                                CY_MISRA_BLOCK_END('MISRA C-2012 Rule 14.3');

                                foutBest = fout;
                                manualConfig.feedbackDiv  = (uint8_t)p;
                                manualConfig.referenceDiv = (uint8_t)q;
                                manualConfig.outputDiv    = (uint8_t)out;
                                manualConfig.icp          = (uint8_t)((PLL_THR_FVCO < fvco) ? PLL_ICP_SEL_GT67MHZ : PLL_ICP_SEL_LT67MHZ);
                            }

                            if (foutBest == (config->outputFreq))
                            {
                                break;
                            }
                        }
                    }

                    if (foutBest == (config->outputFreq))
                    {
                        break;
                    }
                }
            }

            if (foutBest == (config->outputFreq))
            {
                break;
            }
        } /* exit loops if foutBest equals outputFreq */

        /* configure PLL based on calculated values */
        retVal = Cy_SysClk_PllManualConfigure(pllNum, &manualConfig);
    } /* if no error */

    return (retVal);
}

/** \cond INTERNAL */
#define EXCO_PLL_CFG_Pos (EXCO_PLL_CONFIG_FEEDBACK_DIV_Pos)
#define EXCO_PLL_CFG_Msk (EXCO_PLL_CONFIG_FEEDBACK_DIV_Msk  | \
                          EXCO_PLL_CONFIG_REFERENCE_DIV_Msk | \
                          EXCO_PLL_CONFIG_OUTPUT_DIV_Msk    | \
                          EXCO_PLL_CONFIG_ICP_SEL_Msk)

#define CY_SYSCLK_IS_ICP_VALID(icp)  ((CY_SYSCLK_IS_PLL_ICP_LT67MHZ == (icp)) || \
                                      (CY_SYSCLK_IS_PLL_ICP_GT67MHZ == (icp)))
/** \endcond */

/*******************************************************************************
* Function Name: Cy_SysClk_PllManualConfigure
****************************************************************************//**
*
* Manually configures a PLL based on user inputs.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
*
* \param config \ref cy_stc_sysclk_pll_manual_config_t
*
* \return  Error / status code \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - PLL successfully configured \n
* \ref CY_SYSCLK_INVALID_STATE - PLL not configured because it is already enabled \n
* \ref CY_SYSCLK_BAD_PARAM - One or more invalid parameters.
*
* \note
* In case of returning CY_SYSCLK_BAD_PARAM the function does not write anything into
* the configuration register, so either the previous correct configuration or
* the default configuration remains in the register.
*
* \note
* Call this function after changing the PLL input frequency, for example if
* \ref Cy_SysClk_ImoSetFrequency() or \ref Cy_SysClk_PllSetSource() is called.
*
* \note
* Do not call this function when the PLL is enabled. If it is called, then this function
* returns immediately with an error return value and no register updates.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the HFCLK frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the PLL is the source of HFCLK and the PLL frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the PLL is the source of HFCLK and the PLL frequency is decreasing.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PllManualConfigure
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PllManualConfigure(uint32_t pllNum, const cy_stc_sysclk_pll_manual_config_t *config)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    /* check for errors */
    if ((0UL == pllNum) &&
        (CY_SYSCLK_IS_ICP_VALID(config->icp)) &&
        (PLL_MAX_OUT_DIV >= (uint32_t)config->outputDiv) &&
        (PLL_MAX_REF_DIV >= (uint32_t)config->referenceDiv) &&
        (PLL_MIN_FB_DIV  <= (uint32_t)config->feedbackDiv))
    {
        if (Cy_SysClk_PllIsEnabled(pllNum))
        {
            retVal = CY_SYSCLK_INVALID_STATE;
        }
        else /* no errors */
        {
            uint32_t locPllCfg = _VAL2FLD(EXCO_PLL_CONFIG_FEEDBACK_DIV,  config->feedbackDiv)  |
                                 _VAL2FLD(EXCO_PLL_CONFIG_REFERENCE_DIV, config->referenceDiv) |
                                 _VAL2FLD(EXCO_PLL_CONFIG_OUTPUT_DIV,    config->outputDiv)    |
                                 _VAL2FLD(EXCO_PLL_CONFIG_ICP_SEL,       config->icp);

            CY_REG32_CLR_SET(EXCO_PLL_CONFIG, EXCO_PLL_CFG, locPllCfg); /* To preserve BYPASS_SEL bits */

            retVal = CY_SYSCLK_SUCCESS;
        }
    }

    return (retVal);
}

/*******************************************************************************
* Function Name: Cy_SysClk_PllGetConfiguration
****************************************************************************//**
*
* Reports configuration settings for a PLL.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
*
* \param config \ref cy_stc_sysclk_pll_manual_config_t
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PllManualConfigure
*
*******************************************************************************/
void Cy_SysClk_PllGetConfiguration(uint32_t pllNum, cy_stc_sysclk_pll_manual_config_t * config)
{
    CY_ASSERT_L1(0UL == pllNum);
    CY_ASSERT_L1(NULL != config);

    if ((0UL == pllNum) && (NULL != config))
    {
        uint32_t locReg = EXCO_PLL_CONFIG;
        config->feedbackDiv  = (uint8_t)_FLD2VAL(EXCO_PLL_CONFIG_FEEDBACK_DIV,  locReg);
        config->referenceDiv = (uint8_t)_FLD2VAL(EXCO_PLL_CONFIG_REFERENCE_DIV, locReg);
        config->outputDiv    = (uint8_t)_FLD2VAL(EXCO_PLL_CONFIG_OUTPUT_DIV,    locReg);
        config->icp          = (uint8_t)_FLD2VAL(EXCO_PLL_CONFIG_ICP_SEL,       locReg);
    }
}

/*******************************************************************************
* Function Name: Cy_SysClk_PllEnable
****************************************************************************//**
*
* Enables the PLL. The PLL should be configured before calling this function.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
*
* \param timeoutUs amount of time in microseconds to wait for the PLL to lock.
* If the lock doesn't occur, PLL is stopped. To avoid waiting for lock, set this to 0
* and manually check for lock using \ref Cy_SysClk_PllIsLocked.
*
* \return Error / status code \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - PLL successfully enabled \n
* \ref CY_SYSCLK_TIMEOUT - Timeout waiting for PLL lock \n
* \ref CY_SYSCLK_BAD_PARAM - invalid clock path number
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the HFCLK frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the PLL is the source of HFCLK and the HFCLK frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the PLL is the source of HFCLK and the HFCLK frequency is decreasing.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PllConfigure
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PllEnable(uint32_t pllNum, uint32_t timeoutUs)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    if (0UL == pllNum)
    {
        bool zeroTimeout = (0UL == timeoutUs);

        /* Isolate PLL outputs */
        EXCO_PLL_CONFIG &= ~EXCO_PLL_CONFIG_ISOLATE_N_Msk;

        /* first set the PLL enable bit */
        EXCO_PLL_CONFIG |= EXCO_PLL_CONFIG_ENABLE_Msk;

        Cy_SysLib_DelayUs(5U);

        /* De-isolate PLL after PLL enabled */
        EXCO_PLL_CONFIG |= EXCO_PLL_CONFIG_ISOLATE_N_Msk;

        /* now do the timeout wait for PLL_STATUS, bit LOCKED */
        while ((!Cy_SysClk_PllIsLocked(pllNum)) && (0UL != timeoutUs))
        {
            timeoutUs--;
            Cy_SysLib_DelayUs(1U);
        }

        if (zeroTimeout || (0UL != timeoutUs))
        {
            retVal = CY_SYSCLK_SUCCESS;
        }
        else
        {
            retVal = CY_SYSCLK_TIMEOUT;
            Cy_SysClk_PllDisable(pllNum);
        }
    }
    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PllGetFrequency
****************************************************************************//**
*
* Reports the output frequency of the specified PLL.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
*
* \return The frequency, in Hz.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PllManualConfigure
*
*******************************************************************************/
uint32_t Cy_SysClk_PllGetFrequency(uint32_t pllNum)
{
    uint32_t freq;
#if (defined (EXCO_PLL_REF_IN_EN) && (EXCO_PLL_REF_IN_EN == 1u))
    if (CY_SYSCLK_PLL_SRC_IMO == Cy_SysClk_PllGetSource(pllNum))
    {
        freq = Cy_SysClk_ImoGetFrequency();
    }
#if (CY_IP_M0S8EXCO_VERSION == 2U)
    else if (CY_SYSCLK_PLL_SRC_EXTREF == Cy_SysClk_PllGetSource(pllNum))
    {
        freq = Cy_SysClk_ExtRefGetFrequency();
    }
#endif /* (CY_IP_M0S8EXCO_VERSION == 2U) */
    else /* CY_SYSCLK_PLL_SRC_ECO */
    {
        freq = Cy_SysClk_EcoGetFrequency();
    }
#else
        freq = Cy_SysClk_EcoGetFrequency();
#endif /* (defined (EXCO_PLL_REF_IN_EN) && (EXCO_PLL_REF_IN_EN == 1u)) */

    if (!Cy_SysClk_PllIsEnabled(pllNum))
    {
        freq = 0UL; /* The frequency is unknown */
    }
    else
    {
        /* Get the Pll parameters */
        cy_stc_sysclk_pll_manual_config_t config;
        Cy_SysClk_PllGetConfiguration(pllNum, &config);

        /* Calculate Pll output frequency */
        freq = freq / 2UL; /* scaling to do not overflow 32 bits */
        freq = freq * config.feedbackDiv;
        freq = CY_SYSLIB_DIV_ROUND(freq, (1UL + config.referenceDiv) * (1UL << config.outputDiv));
        freq = freq * 2UL; /* de-scaling */
    }

    return (freq);
}


/** \} group_sysclk_pll_funcs */
#endif /* EXCO_PLL_PRESENT */
#endif  /* CY_IP_M0S8EXCO */

#if (defined(CY_IP_M0S8EXCO) && (CY_IP_M0S8EXCO == 1u))
typedef enum
{
    CY_SYSCLK_EXCO_OUT_INVALID = 0U, /* If ECO is not enabled/stabilized and PLL is not enabled/locked. */
#if (defined(EXCO_PLL_PRESENT) && (EXCO_PLL_PRESENT == 1u))
    CY_SYSCLK_EXCO_OUT_PLL     = 1U, /* If PLL is enabled/locked and bypass is AUTO or PLL */
#endif /* EXCO_PLL_PRESENT */
    CY_SYSCLK_EXCO_OUT_ECO     = 2U, /* If ECO is enabled/stabilized and bypass is ECO or (AUTO and PLL is disabled or unlocked). */
} cy_en_sysclk_exco_status_t;


/*******************************************************************************
* Function Name: Cy_SysClk_ExcoGetStatus
********************************************************************************
*
* Returns the source of the EXCO output clock.
*
* Returns cy_en_sysclk_exco_status_t
*
*******************************************************************************/
static cy_en_sysclk_exco_status_t Cy_SysClk_ExcoGetStatus(void)
{
    cy_en_sysclk_exco_status_t excoStatus = CY_SYSCLK_EXCO_OUT_INVALID;
    cy_en_sysclk_pll_bypass_t bypassState = Cy_SysClk_PllGetBypassState(0UL);

#if (defined(EXCO_PLL_PRESENT) && (EXCO_PLL_PRESENT == 1u))
    if (CY_SYSCLK_PLL_BYP_AUTO == bypassState)
    {
        if (Cy_SysClk_PllIsEnabled(0UL) && Cy_SysClk_PllIsLocked(0UL))
        {
            excoStatus = CY_SYSCLK_EXCO_OUT_PLL;
        }
        else
        {
            if (0UL != Cy_SysClk_EcoGetFrequency())
            {
                excoStatus = CY_SYSCLK_EXCO_OUT_ECO;
            }
        }
    }
    else if (CY_SYSCLK_PLL_BYP_PLL == bypassState)
    {
        if (Cy_SysClk_PllIsEnabled(0UL) && Cy_SysClk_PllIsLocked(0UL))
        {
            excoStatus = CY_SYSCLK_EXCO_OUT_PLL;
        }
    }
    else
#endif /* EXCO_PLL_PRESENT */
    {
        if (0UL != Cy_SysClk_EcoGetFrequency())
        {
            excoStatus = CY_SYSCLK_EXCO_OUT_ECO;
        }
    }
    return excoStatus;
}


/*******************************************************************************
* Function Name: Cy_SysClk_ExcoGetFrequency
********************************************************************************
*
* Returns the frequency of the EXCO output clock.
*
* Returns the frequency, in Hz.
*
*******************************************************************************/
static uint32_t Cy_SysClk_ExcoGetFrequency(void)
{
    uint32_t freq = 0UL;
#if (defined(EXCO_PLL_PRESENT) && (EXCO_PLL_PRESENT == 1u))
    cy_en_sysclk_exco_status_t excoStatus = Cy_SysClk_ExcoGetStatus();

    if (excoStatus == CY_SYSCLK_EXCO_OUT_PLL)
    {
       freq = Cy_SysClk_PllGetFrequency(0UL);
    }
    else
#endif /* EXCO_PLL_PRESENT */
    {
        freq = Cy_SysClk_EcoGetFrequency();
    }
    return (freq);
}
#endif /* CY_IP_M0S8EXCO */

/* ========================================================================== */
/* =========================    HFCLK SECTION    ========================= */
/* ========================================================================== */

/** \cond */
#if (defined(CY_IP_M0S8EXCO) && (CY_IP_M0S8EXCO == 1u))
#if (defined(EXCO_PLL_PRESENT) && (EXCO_PLL_PRESENT == 1u))
    #define  CY_SYSCLK_IS_SOURCE_VALID(src) (((src) == CY_SYSCLK_CLKHF_IN_IMO)    || \
                                             ((src) == CY_SYSCLK_CLKHF_IN_EXTCLK) || \
                                             ((src) == CY_SYSCLK_CLKHF_IN_EXCO)   || \
                                             ((src) == CY_SYSCLK_CLKHF_IN_ECO)    || \
                                             ((src) == CY_SYSCLK_CLKHF_IN_PLL))
#else
    #define  CY_SYSCLK_IS_SOURCE_VALID(src) (((src) == CY_SYSCLK_CLKHF_IN_IMO)    || \
                                             ((src) == CY_SYSCLK_CLKHF_IN_EXTCLK) || \
                                             ((src) == CY_SYSCLK_CLKHF_IN_EXCO)   || \
                                             ((src) == CY_SYSCLK_CLKHF_IN_ECO))
#endif /* EXCO_PLL_PRESENT */
#elif (defined (CY_IP_M0S8SRSSHV))
    #define  CY_SYSCLK_IS_SOURCE_VALID(src) (((src) == CY_SYSCLK_CLKHF_IN_IMO)    || \
                                             ((src) == CY_SYSCLK_CLKHF_IN_EXTCLK) || \
                                             ((src) == CY_SYSCLK_CLKHF_IN_HPOSC))
#else
    #define  CY_SYSCLK_IS_SOURCE_VALID(src) (((src) == CY_SYSCLK_CLKHF_IN_IMO)    || \
                                             ((src) == CY_SYSCLK_CLKHF_IN_EXTCLK))
#endif /* CY_IP_M0S8EXCO */

/** \endcond */

/**
* \addtogroup group_sysclk_clk_hf_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfSetSource
****************************************************************************//**
*
* Selects the source of the HFCLK.
*
* \param source \ref cy_en_sysclk_clkhf_src_t
*
* \return  Error / status code \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - the source is successfully set; \n
* \ref CY_SYSCLK_INVALID_STATE - the selected clock source is not enabled or does not working; \n
* \ref CY_SYSCLK_BAD_PARAM - the source parameter is invalid.
*
* \note Call \ref SystemCoreClockUpdate after this function calling if
* SYSCLK frequency is affected.
*
* \note Call \ref Cy_SysLib_SetWaitStates before this function calling if
* SYSCLK frequency is increasing.
*
* \note Call \ref Cy_SysLib_SetWaitStates after this function calling if
* SYSCLK frequency is decreasing.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c snippet_Cy_SysClk_EcoPllHfClk
* \snippet sysclk/snippet/sysclk_snippet.c snippet_Cy_SysClk_ClkHfSetSource_HPOSC
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkHfSetSource(cy_en_sysclk_clkhf_src_t source)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;

    if (CY_SYSCLK_IS_SOURCE_VALID(source))
    {
        cy_en_sysclk_clkhf_src_t prevSrc = Cy_SysClk_ClkHfGetSource();

        if (source != prevSrc)
        {
            if ((CY_SYSCLK_CLKHF_IN_IMO == source) && (Cy_SysClk_ImoIsEnabled()))
            {
                retVal = CY_SYSCLK_SUCCESS;
            }
            else if ((CY_SYSCLK_CLKHF_IN_EXTCLK == source) && (0UL != Cy_SysClk_ExtClkGetFrequency()))
            {
                retVal = CY_SYSCLK_SUCCESS;
            }
            #if (defined(CY_IP_M0S8EXCO) && (CY_IP_M0S8EXCO == 1u))
            else if ((CY_SYSCLK_CLKHF_IN_EXCO == source) && (CY_SYSCLK_EXCO_OUT_INVALID != Cy_SysClk_ExcoGetStatus()))
            {
                Cy_SysClk_EcoSeqGen();
                retVal = CY_SYSCLK_SUCCESS;
            }
            /* BWC section start, for HAL 2.0.0 only */
            else if ((CY_SYSCLK_CLKHF_IN_ECO == source) && (0UL != Cy_SysClk_EcoGetFrequency()))
            {
                Cy_SysClk_PllBypass(0UL, CY_SYSCLK_PLL_BYP_ECO);
                source = CY_SYSCLK_CLKHF_IN_EXCO;
                retVal = CY_SYSCLK_SUCCESS;
            }
            #if (defined(EXCO_PLL_PRESENT) && (EXCO_PLL_PRESENT == 1u))
            else if ((CY_SYSCLK_CLKHF_IN_PLL == source) && Cy_SysClk_PllIsEnabled(0UL) && Cy_SysClk_PllIsLocked(0UL))
            {
                if (0UL != Cy_SysClk_EcoGetFrequency())
                {
                    Cy_SysClk_PllBypass(0UL, CY_SYSCLK_PLL_BYP_AUTO);
                }
                else
                {
                    Cy_SysClk_PllBypass(0UL, CY_SYSCLK_PLL_BYP_PLL);
                }
                source = CY_SYSCLK_CLKHF_IN_EXCO;
                retVal = CY_SYSCLK_SUCCESS;
            }
            #endif /* EXCO_PLL_PRESENT */
            /* BWC section end */
            #endif /* CY_IP_M0S8EXCO */
            #if defined (CY_IP_M0S8SRSSHV)
            else if ((CY_SYSCLK_CLKHF_IN_HPOSC == source) && (Cy_SysClk_HposcIsEnabled()))
            {
                retVal = CY_SYSCLK_SUCCESS;
            }
            #endif /* CY_IP_M0S8SRSSHV */
            else
            {
                /* do nothing */
            }

            if (retVal == CY_SYSCLK_SUCCESS)
            {
            #if defined (CY_IP_M0S8SRSSHV)
                /* Avoid lock register's potential race condition. */
                uint32_t intrState = Cy_SysLib_EnterCriticalSection();
                Cy_SysClk_UnlockProtReg();
            #endif /* defined (CY_IP_M0S8SRSSHV) */
                CY_REG32_CLR_SET(SRSS_CLK_SELECT, SRSS_CLK_SELECT_HFCLK_SEL, source);
            #if defined (CY_IP_M0S8SRSSHV)
                Cy_SysClk_LockProtReg();
                Cy_SysLib_ExitCriticalSection(intrState);
            #endif /* defined (CY_IP_M0S8SRSSHV) */
            }
        }
        else
        {
            retVal = CY_SYSCLK_SUCCESS;
        }
    }
    else
    {
        retVal = CY_SYSCLK_BAD_PARAM;
    }

    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfGetSource
****************************************************************************//**
*
* Reports the source of the HFCLK.
*
* \return \ref cy_en_sysclk_clkhf_src_t : \n
* \ref CY_SYSCLK_CLKHF_IN_IMO - IMO - Internal R/C Oscillator. \n
* \ref CY_SYSCLK_CLKHF_IN_EXTCLK - EXTCLK - External Clock Pin. \n
* \ref CY_SYSCLK_CLKHF_IN_EXCO - EXCO block output, ECO or PLL, use \ref Cy_SysClk_PllBypass to select between them.
* \ref CY_SYSCLK_CLKHF_IN_HPOSC - High Precision Oscillator. \n
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_EcoDisable
*
*******************************************************************************/
cy_en_sysclk_clkhf_src_t Cy_SysClk_ClkHfGetSource(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8', 'The field values match the enumeration.');
    return ((cy_en_sysclk_clkhf_src_t)_FLD2VAL(SRSS_CLK_SELECT_HFCLK_SEL, SRSS_CLK_SELECT));
}


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfGetFrequency
****************************************************************************//**
*
* Reports the frequency of the HFCLK
*
* \return The frequency, in Hz.
*
* \note
* The reported value may be zero, which indicates the frequency is unknown.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkHfSetDivider
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkHfGetFrequency(void)
{
    uint32_t freq = 0UL;    /* HFCLK source clock frequency, in Hz, 0 = unknown frequency */
    /* Convert the cy_en_clkhf_dividers_t value into the natural number of divider */
    uint32_t div = (uint32_t) (1UL << (uint32_t)Cy_SysClk_ClkHfGetDivider());
    cy_en_sysclk_clkhf_src_t source = Cy_SysClk_ClkHfGetSource(); /* source input for HFCLK */

    /* get the frequency of the source, i.e., the path mux input */
    switch(source)
    {
        case CY_SYSCLK_CLKHF_IN_IMO:
            freq = Cy_SysClk_ImoGetFrequency();
            break;

        case CY_SYSCLK_CLKHF_IN_EXTCLK:
            freq = Cy_SysClk_ExtClkGetFrequency();
            break;

    #if (defined(CY_IP_M0S8EXCO) && (CY_IP_M0S8EXCO == 1u))
        case CY_SYSCLK_CLKHF_IN_EXCO:
            freq = Cy_SysClk_ExcoGetFrequency();
            break;
    #endif /* CY_IP_M0S8EXCO */
    #if defined (CY_IP_M0S8SRSSHV)
        case CY_SYSCLK_CLKHF_IN_HPOSC:
            freq = CY_SYSCLK_HPOSC_FREQ;
            break;
    #endif /* CY_IP_M0S8SRSSHV */

        default: /* Unsupported clock source, return 0 */
            break;
    }

    /* Divide the path input frequency down and return the result */
    return (CY_SYSLIB_DIV_ROUND(freq, div));
}

/** \} group_sysclk_clk_hf_funcs */


#if defined (CY_IP_M0S8SRSSHV)
/* ========================================================================== */
/* ==========================    LFCLK SECTION    =========================== */
/* ========================================================================== */

/** \cond */

/* The LFCLK clock source switching needs (3 + 1) cycles. */
#define CY_SYSCLK_LFCLK_SRC_SWITCH_CYCLES (4UL)
#define CY_SYSCLK_LFCLK_SRC_SWITCH_DELAY_BY_FREQ(freq) \
    (CY_SYSCLK_LFCLK_SRC_SWITCH_CYCLES * 1000000UL / (freq))

/** \endcond */

/**
* \addtogroup group_sysclk_clk_lf_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_ClkLfSetSource
****************************************************************************//**
*
* Selects the source of the LFCLK.
*
* \param source \ref cy_en_sysclk_clklf_src_t
*
* \return  Error / status code \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - the source is successfully set; \n
* \ref CY_SYSCLK_INVALID_STATE - the selected clock source is not enabled or does not working; \n
* \ref CY_SYSCLK_BAD_PARAM - the source parameter is invalid.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked before set source of the LFCLK.
* Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \note  It takes about (3 + 1) LF clock cycles of the new selected clock to switch away
* from the old clock to the new clock. Do not disable the original clock during this time.
*
* \note  If a clock source is disabled while selected, then the clock merely stops to all sources that receive it.
* In such a scenario, the disabled clock must be re-enabled, prior to switching FROM this clock source.
*
* \note This function is not re-entrant.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkLfSetSource
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkLfSetSource(cy_en_sysclk_clklf_src_t source)
{
    CY_ASSERT_L2(false == Cy_WDT_Locked());

    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;
    do
    {
        cy_en_sysclk_clklf_src_t prevSrc = Cy_SysClk_ClkLfGetSource();
        /* No switching needed */
        if (source == prevSrc)
        {
            break;
        }

        uint32_t srcFreq = 0;
        if (CY_SYSCLK_CLKLF_IN_PILO == source)
        {
            /* Handle situation when target source not enabled. */
            if (!Cy_SysClk_PiloIsEnabled())
            {
                retVal = CY_SYSCLK_INVALID_STATE;
                break;
            }

            srcFreq = CY_SYSCLK_PILO_FREQ;
        }
        else if (CY_SYSCLK_CLKLF_IN_ILO == source)
        {
            /* Handle situation when target source not enabled. */
            if(!Cy_SysClk_IloIsEnabled())
            {
                retVal = CY_SYSCLK_INVALID_STATE;
                break;
            }

            srcFreq = CY_SYSCLK_ILO_FREQ;
        }
        else
        {
            retVal = CY_SYSCLK_BAD_PARAM;
            break;
        }

        /* It takes about (3 + 1) low frequency clock cycles to switch away from the old source to the new source.
           Microsecond delay calculation which equal (3 + 1) ILO or PILO cycles by the target source frequency. */
        uint16_t delay = (uint16_t)CY_SYSCLK_LFCLK_SRC_SWITCH_DELAY_BY_FREQ(srcFreq);
        /* Avoid lock register's potential race condition. */
        uint32_t intrState = Cy_SysLib_EnterCriticalSection();
        Cy_SysClk_UnlockProtReg();
        CY_REG32_CLR_SET(SRSS_CLK_SELECT, SRSSHV_CLK_SELECT_LFCLK_SEL, source);
        Cy_SysClk_LockProtReg();
        Cy_SysLib_ExitCriticalSection(intrState);

        /* Wait for low frequency clock switching. */
        Cy_SysLib_DelayUs(delay);
    } while(false);

    return (retVal);
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkLfGetFrequency
****************************************************************************//**
*
* Reports the frequency of the LFCLK.
*
* \return The frequency is in Hz units and equals 0 in case of an unknown frequency.
*
* \note The reported value may be zero, which indicates the frequency is unknown.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkLfGetFrequency
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkLfGetFrequency(void)
{
    uint32_t freq = 0UL; /* frequency in Hz, 0 = an unknown frequency */

    cy_en_sysclk_clklf_src_t source = Cy_SysClk_ClkLfGetSource();
    /* Get the frequency of the source  */
    switch(source)
    {
    case CY_SYSCLK_CLKLF_IN_PILO:
        freq = Cy_SysClk_PiloIsEnabled() ? CY_SYSCLK_PILO_FREQ : 0UL;
        break;

    case CY_SYSCLK_CLKLF_IN_ILO:
        freq = Cy_SysClk_IloIsEnabled() ? CY_SYSCLK_ILO_FREQ : 0UL;
        break;

    default:
        /* Don't know the frequency, leave freq = 0UL */
        break;
    }

    return (freq);
}
/** \} group_sysclk_clk_lf_funcs */


/* ========================================================================== */
/* ====================    CLOCK CALIBRATION SECTION    ===================== */
/* ========================================================================== */
__STATIC_INLINE uint32_t Cy_SysClk_CalibGetFrequency(cy_en_meas_clks_t clock)
{
    uint32_t frequency;
    /* get actual frequency of the clock source */
    switch (clock)
    {
    case CY_SYSCLK_MEAS_CLK_ILO:
        frequency = CY_SYSCLK_ILO_FREQ;
        break;
    case CY_SYSCLK_MEAS_CLK_IMO:
        frequency = Cy_SysClk_ImoGetFrequency();
        break;
    case CY_SYSCLK_MEAS_CLK_SYSCLK:
        frequency = Cy_SysClk_ClkSysGetFrequency();
        break;
    case CY_SYSCLK_MEAS_CLK_HPOSC:
        frequency = CY_SYSCLK_HPOSC_FREQ;
        break;
    case CY_SYSCLK_MEAS_CLK_PILO:
        frequency = CY_SYSCLK_PILO_FREQ;
        break;
    default:
        frequency = 0UL;
        break;
    }
    return (frequency);
}
/**
* \addtogroup group_sysclk_calclk_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_CalibStart
****************************************************************************//**
*
* Assigns clocks to the clock measurement counters, and starts counting. The counters
* let you measure a clock frequency using another clock as a reference. There are two
* counters.
*
* - One counter (counter1), which is clocked by clock1, is loaded with an initial
*   value and counts down to zero.
* - The second counter (counter2), which is clocked by clock2, counts up until
*   the first counter reaches zero.
*
* Either clock1 or clock2 can be a reference clock; the other clock becomes the
* measured clock. The reference clock frequency is always known. \n
* After calling this function, call \ref Cy_SysClk_CalibDone()
* to determine when counting is done; that is, counter1 has counted down to zero.
* Then call \ref Cy_SysClk_CalibGetFreq() to calculate the frequency
* of the measured clock.
*
* \param clock1 The clock for counter1
*
* \param count1 The initial value for counter1, from which counter1 counts down to zero.
*
* \param clock2 The clock for counter2
*
* \return Error / status code: \n
* CY_SYSCLK_INVALID_STATE if already doing a measurement \n
* CY_SYSCLK_BAD_PARAM if invalid clock input parameter. Source have zero frequency. Or overflow expected \n
* else CY_SYSCLK_SUCCESS
*
* \note The counters are both 16-bit, so the maximum value of count1 is 0xFFFF.
* If clock2 frequency is greater than clock1, make sure that count1 is low enough
* that counter2 does not overflow before counter1 reaches zero.
* \note The time to complete a measurement is count1 / clock1 frequency.
* \note The clocks for both counters must have a nonzero frequency, or
* \ref Cy_SysClk_CalibGetFreq() incorrectly reports the result of the
* previous  measurement.
* \note Both clock1 and clock2 clocks must be running or the measurement will not complete.
* \note Due to internal clock synchronization count1 should be at least 5 times the 1/frequency2.
* \note Do not enter a device low power mode (Sleep, Deep Sleep) while doing a measurement;
* the measured clock frequency may not be accurate.
* \note The calibration counters are available only in Active/Sleep modes.
* Counter values are not retained and will be in default state after wakeup from deepsleep.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_CalibStart
*
*******************************************************************************/


cy_en_sysclk_status_t Cy_SysClk_CalibStart(cy_en_meas_clks_t clock1, uint16_t count1, cy_en_meas_clks_t clock2)
{
    uint32_t frequency1 = 0UL;
    uint32_t frequency2 = 0UL;
    /* if calibration is not done yet */
    if (!Cy_SysClk_CalibDone())
    {
        /* Calibration is in progress. Unable to start new calibration. Emergency exit */
        return CY_SYSCLK_INVALID_STATE;
    }
    /* clock sources number higher then PILO is not allowed for calibration */
    if ((clock1 > CY_SYSCLK_MEAS_CLK_PILO) || (clock2 > CY_SYSCLK_MEAS_CLK_PILO))
    {
        /* emergency exit, no reasons to continue */
        return CY_SYSCLK_BAD_PARAM;
    }
    /* disabled source can not be used for calibration */
    if ((clock1 == CY_SYSCLK_MEAS_CLK_NC) || (clock2 == CY_SYSCLK_MEAS_CLK_NC))
    {
        /* emergency exit, no reasons to continue */
        return CY_SYSCLK_BAD_PARAM;
    }
    frequency1 = Cy_SysClk_CalibGetFrequency(clock1);
    frequency2 = Cy_SysClk_CalibGetFrequency(clock2);
    /* if any of frequencies is zero, then no reason to continue calibration */
    if ((0UL == frequency1) || (0UL == frequency2))
    {
        /* emergency exit, no reasons to continue */
        return CY_SYSCLK_BAD_PARAM;
    }
    if (1UL >= count1)
    {
        /* CAL_COUNTER1 should always be > 1 */
        return CY_SYSCLK_BAD_PARAM;
    }
    /* if frequency of the counter2 bigger then frequency of the counter1, check potential overflow */
    if (frequency2 > frequency1)
    {
        /* counter1 and counter2 are 16 bits wide */
        if((uint64_t)UINT16_MAX < ((uint64_t)frequency2/(uint64_t)frequency1)*count1)
        {
            /* Overflow. Emergency exit, no reasons to continue */
            return CY_SYSCLK_BAD_PARAM;
        }
    }
    else
    {
        /* Due to internal clock synchronization CAL_COUNTER1 should be at least 5 times the 1/frequency2. */
        if (count1 < (uint16_t)((5ULL*(uint64_t)frequency1)/frequency2))
        {
            return CY_SYSCLK_BAD_PARAM;
        }
    }
    /* by default
     * no clocks set,
     * no dividers for both clock sources,
     * positive edge of the clock selected for dividers
     */
    SRSS_CLK_DFT_SELECT = 0UL;
    /* set clocks */
    SRSS_CLK_DFT_SELECT = _VAL2FLD(SRSS_CLK_DFT_SELECT_DFT_SEL0,clock1) | _VAL2FLD(SRSS_CLK_DFT_SELECT_DFT_SEL1,clock2);
    /* Start the clock calibration */
    SRSS_CLK_CAL_CNT1 = _VAL2FLD(SRSSHV_CLK_CAL_CNT1_CAL_COUNTER1,count1);
    return CY_SYSCLK_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_SysClk_CalibGetFreq
****************************************************************************//**
*
* Calculates the frequency of the indicated measured clock (clock1 or clock2).
* - If clock1 is the measured clock, its frequency is: clock1 frequency = (count1 / count2) * clock2 frequency
* - If clock2 is the measured clock, its frequency is: clock2 frequency = (count2 / count1) * clock1 frequency
*
* Call this function only after counting is done; see \ref Cy_SysClk_CalibDone().
*
* \param measuredClock False (0) if the measured clock is clock1; true (1)
* if the measured clock is clock2.
*
* \param count1 The initial value for counter1, from which counter1 counts down to zero.
* See \ref Cy_SysClk_CalibStart()
*
* \return The frequency of the measured clock, in Hz.
* \warning The function returns zero, if during measurement device was in the
* Deep Sleep or partially blocking flash operation occurred. It means that
* current measurement is not valid and you should call the
* Cy_SysClk_CalibStart() function once again.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_CalibGetFreq
*
*******************************************************************************/
uint32_t Cy_SysClk_CalibGetFreq(bool measuredClock, uint16_t count1)
{
    cy_en_meas_clks_t clock1;
    cy_en_meas_clks_t clock2;
    /* reference frequency can be clock1 or clock2 depends of measuredClock */
    uint32_t freqReference;
    /* calculated frequency value based on the reference clock*/
    uint32_t freqMeasured;
    /* up counter value */
    uint16_t count2;
    /* temp variable to cast according the MISRA requirements */
    uint32_t clock;

    if (!Cy_SysClk_CalibDone() || 0U == count1)
    {
        /* calibration is not done yet.
         * unable to have count1 equal zero
         */
        freqMeasured = 0UL;
    }
    else
    {
        clock = _FLD2VAL(SRSS_CLK_DFT_SELECT_DFT_SEL0,SRSS_CLK_DFT_SELECT);
        clock1 = (cy_en_meas_clks_t)clock;
        clock = _FLD2VAL(SRSS_CLK_DFT_SELECT_DFT_SEL1,SRSS_CLK_DFT_SELECT);
        clock2 = (cy_en_meas_clks_t)clock;
        count2 = (uint16_t)_FLD2VAL(SRSSHV_CLK_CAL_CNT2_CAL_COUNTER2,SRSS_CLK_CAL_CNT2);
        if (measuredClock)
        {
            freqReference = Cy_SysClk_CalibGetFrequency(clock1);
            if (0UL == freqReference)
            {
                /* reference clock is zero, unable to do calculations */
                freqMeasured = 0UL;
            }
            else
            {
                freqMeasured = (uint32_t)((count2 * (uint64_t)freqReference)/count1);
            }
        }
        else
        {
            freqReference = Cy_SysClk_CalibGetFrequency(clock2);
            if (0UL == freqReference)
            {
                /* reference clock is zero, unable to do calculations */
                freqMeasured = 0UL;
            }
            else
            {
                freqMeasured = (uint32_t)((count1 * (uint64_t)freqReference)/count2);
            }
        }
    }
    return freqMeasured;
}


/*******************************************************************************
* Function Name: Cy_SysClk_CalibDone
****************************************************************************//**
*
* Checks if clock measurement counting is done, that is, counter1 has counted down
* to zero. Call \ref Cy_SysClk_CalibStart() before calling this function.
*
* \return Status of calibration counters: \n
* true = done \n
* false = in progress
*
*******************************************************************************/
bool Cy_SysClk_CalibDone(void)
{
    return _FLD2BOOL(SRSSHV_CLK_CAL_CNT1_CAL_COUNTER_DONE,SRSS_CLK_CAL_CNT1);
}
/** \} group_sysclk_calclk_funcs */


/* ========================================================================== */
/* ==========================    TRIM SECTION    ============================ */
/* ========================================================================== */

/** \cond INTERNAL */
#define CY_SYSCLK_IMOTRIM_MIN           (0U)          /* Maximum value of the IMO clock trim setting */
#define CY_SYSCLK_IMOTRIM_MAX           (0x000007FFU) /* Maximum value of the IMO clock trim setting */
#define CY_SYSCLK_IMOTRIM1_OFFSET_SHIFT (3U)          /* Shift value of the CLK_IMO_TRIM1 register OFFSET bit */
#define CY_SYSCLK_IMO_COARSE_TRIM_STEP  (160000UL)    /* Coarse IMO TRIM Step size */
#define CY_SYSCLK_IMO_FINE_TRIM_STEP    (20000UL)     /* Fine IMO TRIM Step size */
#define CY_SYSCLK_CALIB_IMO_GAIN1       (50)          /* Value of the gain 1 factor for IMO clock */
#define CY_SYSCLK_CALIB_IMO_GAIN2       (5)           /* Value of the gain 2 factor for IMO clock */

#define CY_SYSCLK_CALIB_PILO_GAIN1      (15000)       /* Value of the gain 1 factor for PILO clock */
#define CY_SYSCLK_CALIB_PILO_GAIN2      (1500)        /* Value of the gain 2 factor for PILO clock */
/** CY_SYSCLK_PILO_TRIM_STEP is the default PILO TRIM Step value */
#define CY_SYSCLK_PILO_TRIM_STEP        (50UL)         /* Default PILO TRIM Step size */
#define CY_SYSCLK_PILOCTL_TRCAP_DEFAULT (0x000000C0U) /* Default value of the PILO_CTL register TR_CAP bit */
#define CY_SYSCLK_PILOCTL_TRCAP_MIN     (0x00000080U) /* Minimum value of the PILO_CTL register TR_CAP bit */
#define CY_SYSCLK_PILOCTL_TRCAP_MAX     (0x000000FFU) /* Maximum value of the PILO_CTL register TR_CAP bit */

/* history for second order trim */
uint32_t iterationNum;
int32_t  errorIntegralHz;
/** \endcond */

/*****************************************************************************
* Local function ('static')
*****************************************************************************/

/*******************************************************************************
* Function Name: Cy_SysClk_ImoGetTrim
****************************************************************************//**
*
* Gets the IMO Trim Value.
*
* \return IMO Trim Value.
* \note LSB [2:0] bits  is hardware updated during USB osclock mode.
* The step size of 1 LSB on this field is nominally 20 kHz.
* [10:3] bits determined at manufacturing time for each FREQ setting.
* This field is hardware updated during USB osclock mode.
* The step size of 1 bit on this part is nominally 160 kHz.
*
*******************************************************************************/
static uint32_t Cy_SysClk_ImoGetTrim(void)
{
    uint32_t trim;

    trim = (uint32_t)_FLD2VAL(SRSS_CLK_IMO_TRIM1_OFFSET, SRSS_CLK_IMO_TRIM1) << CY_SYSCLK_IMOTRIM1_OFFSET_SHIFT;
    trim += (uint32_t)_FLD2VAL(SRSS_CLK_IMO_TRIM2_FSOFFSET, SRSS_CLK_IMO_TRIM2);

    return (trim);
}

/*******************************************************************************
* Function Name: Cy_SysClk_ImoSetTrim
****************************************************************************//**
*
* Set IMO Trim Value
*
* \param trimVal Trim value to be set for IMO.
* \note trimVal must contain 11 bits of trim value.
*
*******************************************************************************/
static void Cy_SysClk_ImoSetTrim(uint32_t trimVal)
{
    if (CY_SYSCLK_IMOTRIM_MAX < trimVal)
    {
        trimVal = CY_SYSCLK_IMOTRIM_MAX;
    }
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSS_CLK_IMO_TRIM1 = _VAL2FLD(SRSS_CLK_IMO_TRIM1_OFFSET, (trimVal >> CY_SYSCLK_IMOTRIM1_OFFSET_SHIFT));
    SRSS_CLK_IMO_TRIM2 = _CLR_SET_FLD32U(SRSS_CLK_IMO_TRIM2, SRSS_CLK_IMO_TRIM2_FSOFFSET, trimVal);
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}

/*******************************************************************************
* Function Name: Cy_SysClk_PiloGetTrim
****************************************************************************//**
*
* Gets the PILO Trim Value.
*
* \return PILO Trim Value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_PiloGetTrim(void)
{
    return ((uint32_t)_FLD2VAL(SRSS_PILO_CTL_TR_CAP, SRSS_PILO_CTL));
}

/*******************************************************************************
* Function Name: Cy_SysClk_PiloSetTrim
****************************************************************************//**
*
* Set PILO Trim Value
*
* \param trimVal Trim value to be set for PILO.
*
* \note TP_CAP - PILO user temperature fine trim.
* To meet the 1% accuracy target, the user need to trim PILO_CTL.TR_CAP to lock to HPOSC.
* The trim uses only the lower 7 bits. This register is updated with firmware for tracking.
*
*
*******************************************************************************/
static void Cy_SysClk_PiloSetTrim(uint32_t trimVal)
{
    /* Set trim value to minimum value if it is below that */
    if(CY_SYSCLK_PILOCTL_TRCAP_MIN > trimVal)
    {
        trimVal = CY_SYSCLK_PILOCTL_TRCAP_MIN;
    }
    /* Set trim value to maximum value if it exceeds */
    if(CY_SYSCLK_PILOCTL_TRCAP_MAX < trimVal)
    {
        trimVal = CY_SYSCLK_PILOCTL_TRCAP_MAX;
    }
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    /* All trim registers are protected */
    Cy_SysClk_UnlockProtReg();
    /* Set trim value to what it is if it is in range */
    SRSS_PILO_CTL = _CLR_SET_FLD32U(SRSS_PILO_CTL, SRSS_PILO_CTL_TR_CAP, trimVal);
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}
/*******************************************************************************
* Function Name: Cy_SysClk_CalculateNextTrim
****************************************************************************//**
*
* \brief
*  Calculates the next clock trim value with clock error value.
* \param clock clock for which needed be
* \param currFreq actual frequency of the clock
* \param formula type of formula to calculate next trim value
* \return
*  Value of next clock trim.
*
******************************************************************************/
static uint32_t Cy_SysClk_CalculateNextTrim (cy_en_meas_clks_t clock, uint32_t currFreq, cy_en_sysclk_calib_formula_t formula)
{
    uint32_t errorValueHz; /* absolute difference between real and expected frequencies */
    bool sign = false; /* sign of the errorValueHz */
    uint32_t deltaTrim = 0UL; /* delta that should be added to the current trim value for calibration */
    uint32_t nextTrim = 0UL; /* trim value which have to be applied to tune frequency */
    uint32_t currentTrim; /* temporary storage for current trim registers value */
    uint32_t freqTarget; /* needed frequency */
    uint32_t trimStep; /* Hz per bits trimming */
    /* for second order formula borrowed from AutoPDL */
    uint32_t clkGain1; /* proportional gain */
    uint32_t clkGain2; /* IIR filter gain */

    if (CY_SYSCLK_MEAS_CLK_IMO == clock)
    {
        freqTarget = Cy_SysClk_ImoGetFrequency();
        /*
         * since for IMO fine trim have 3 bits, 8 steps from 0 to 7
         * total weight of the fine trim 8*20 = 160
         * exactly fit the LSB weight of the coarse trim register,
         * so we can use smallest step to simplify calculations
         * of the overall trimming.
         */
        trimStep = CY_SYSCLK_IMO_FINE_TRIM_STEP;
        /* Get current trim value */
        currentTrim = Cy_SysClk_ImoGetTrim();
        /* init gains for second order formula */
        clkGain1 = CY_SYSCLK_CALIB_IMO_GAIN1;
        clkGain2 = CY_SYSCLK_CALIB_IMO_GAIN2;
    }
    else
    {
        freqTarget = CY_SYSCLK_PILO_FREQ;
        trimStep = CY_SYSCLK_PILO_TRIM_STEP;
        /* Get current trim value */
        currentTrim = Cy_SysClk_PiloGetTrim();
        /* init gains for second order formula */
        clkGain1 = CY_SYSCLK_CALIB_PILO_GAIN1;
        clkGain2 = CY_SYSCLK_CALIB_PILO_GAIN2;
    }
    /* calculate diff between current and expected frequencies */
    if(currFreq > freqTarget)
    {
        errorValueHz = currFreq - freqTarget;
        /* for first order calibration frequency difference less then trim step have no sense */
        if((CY_SYSCLK_CALIB_FIRST_ORDER == formula) && (errorValueHz < trimStep))
        {
            errorValueHz = 0UL;
        }
    }
    else if(currFreq < freqTarget)
    {
        errorValueHz = freqTarget - currFreq;
        if ((CY_SYSCLK_CALIB_FIRST_ORDER == formula) && (errorValueHz < trimStep))
        {
            errorValueHz = 0UL;
        }
        sign = true;
    }
    else
    {
        errorValueHz = 0UL;
    }

    /* for second order always calculate deltaTrim */
    if (CY_SYSCLK_CALIB_SECOND_ORDER == formula)
    {
        deltaTrim = errorValueHz * clkGain1;
        /* if accumulated freq error is positive - increase trim */
        if (0 < errorIntegralHz)
        {
            deltaTrim += (uint32_t)errorIntegralHz * clkGain2;
        }
        else
        {
            /* it's unable to get abs from INT_MIN so need to handle this case separately */
            if (INT_MIN == errorIntegralHz)
            {
                /* if accumulated error is negative - decrease trim till zero */
                if (deltaTrim > (uint32_t)INT_MAX * clkGain2)
                {
                    deltaTrim -= (uint32_t)INT_MAX * clkGain2;
                }
                else
                {
                    deltaTrim = 0U;
                }
            }
            else
            {
                /* if accumulated error is negative - decrease trim till zero */
                if (deltaTrim > (uint32_t)abs(errorIntegralHz) * clkGain2)
                {
                    deltaTrim -= (uint32_t)abs(errorIntegralHz) * clkGain2;
                }
                else
                {
                    deltaTrim = 0U;
                }
            }
        }
        deltaTrim /= CY_SYSCLK_MICRO_SCALER;

        /* Sum (integrate) previous frequency errors, ignoring one initial measurement */
        if(0U == iterationNum)
        {
            iterationNum = 1U;
        }
        else
        {
            errorIntegralHz += (sign? (0 - (int32_t)errorValueHz): (int32_t)errorValueHz);
        }
    }
    else
    {
        /* calculate the trim for first order*/
        deltaTrim = CY_SYSLIB_DIV_ROUND(errorValueHz, trimStep);
    }

    if(sign)
    {/* frequency is too low. Increase the trim value */
        nextTrim = currentTrim + deltaTrim;
    }
    else
    {/* frequency is too high. Decrease the trim value */
        nextTrim = currentTrim - deltaTrim;
        if ((int32_t)nextTrim < 0) /* limit underflow */
        {
            nextTrim = 0UL;
        }
    }
    return nextTrim;
}


/**
* \addtogroup group_sysclk_trim_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_ImoTrim
****************************************************************************//**
*
* Trims the IMO to be as close to requested frequency as possible.
*
* \param imoFreq current IMO frequency. Call \ref Cy_SysClk_CalibStart
* and other measurement functions to obtain the current frequency of the IMO.
*
* \param order type of the calibration \ref cy_en_sysclk_calib_formula_t
* which will be executed.
*
* \return Change in trim value - 0 if done; that is, no change in trim value.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ImoTrim
*
*******************************************************************************/
int32_t Cy_SysClk_ImoTrim(uint32_t imoFreq, cy_en_sysclk_calib_formula_t order)
{
    uint32_t nextTrim;
    uint32_t currentTrim;
    uint32_t freqTarget; /* needed frequency */

    freqTarget = Cy_SysClk_ImoGetFrequency();

    /* Get current trim value */
    currentTrim = Cy_SysClk_ImoGetTrim();

    if ((CY_SYSCLK_CALIB_SECOND_ORDER == order) || \
        (imoFreq > freqTarget ? (imoFreq - freqTarget) : (freqTarget - imoFreq)) > CY_SYSCLK_IMO_FINE_TRIM_STEP)
    {
        nextTrim = Cy_SysClk_CalculateNextTrim(CY_SYSCLK_MEAS_CLK_IMO, imoFreq, order);
    }
    else
    {
        nextTrim = currentTrim;
    }

    /* Update the trim value */
    Cy_SysClk_ImoSetTrim(nextTrim);

    return ((int32_t)nextTrim - (int32_t)currentTrim);
}

/*******************************************************************************
* Function Name: Cy_SysClk_PiloTrim
****************************************************************************//**
*
* Trims the PILO to be as close to 32,768 Hz as possible.
*
* \param piloFreq current PILO frequency. Call \ref Cy_SysClk_CalibStart
* and other measurement functions to obtain the current frequency of the PILO.
*
* \param order type of the calibration \ref cy_en_sysclk_calib_formula_t
* which will be executed
*
*
* \return Change in trim value; 0 if done, that is, no change in trim value.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PiloTrim
*
*******************************************************************************/
int32_t Cy_SysClk_PiloTrim(uint32_t piloFreq, cy_en_sysclk_calib_formula_t order)
{
    uint32_t nextTrim;
    uint32_t currentTrim;

    /* Get current trim value */
    currentTrim = Cy_SysClk_PiloGetTrim();
    if ((CY_SYSCLK_CALIB_SECOND_ORDER == order) || \
        (piloFreq > CY_SYSCLK_PILO_FREQ ? (piloFreq - CY_SYSCLK_PILO_FREQ) : (CY_SYSCLK_PILO_FREQ - piloFreq)) > CY_SYSCLK_PILO_TRIM_STEP)
    {
        nextTrim = Cy_SysClk_CalculateNextTrim(CY_SYSCLK_MEAS_CLK_PILO, piloFreq, order);
        /* Set trim value to minimum value if it is below that */
        if(CY_SYSCLK_PILOCTL_TRCAP_MIN > nextTrim)
        {
            nextTrim = CY_SYSCLK_PILOCTL_TRCAP_MIN;
        }
        /* Set trim value to maximum value if it exceeds */
        if(CY_SYSCLK_PILOCTL_TRCAP_MAX < nextTrim)
        {
            nextTrim = CY_SYSCLK_PILOCTL_TRCAP_MAX;
        }
    }
    else
    {
        nextTrim = currentTrim;
    }

    /* Update the trim value */
    Cy_SysClk_PiloSetTrim(nextTrim);

    return (int32_t)nextTrim - (int32_t)currentTrim;
}
/** \} group_sysclk_trim_funcs */
#endif /* CY_IP_M0S8SRSSHV */


/* ========================================================================== */
/* =====================    clk_peripherals SECTION    ====================== */
/* ========================================================================== */

/** \cond */
#if (0U != PERI_PCLK_DIV_8_NR)
#define IS_DIV_8_TYPE_NUM_VALID(typ, num)    (((typ) == CY_SYSCLK_DIV_8_BIT)    && ((num) < PERI_PCLK_DIV_8_NR))
#else
#define IS_DIV_8_TYPE_NUM_VALID(typ, num)    (0U != 0U)
#endif

#if (0U != PERI_PCLK_DIV_16_NR)
#define IS_DIV_16_TYPE_NUM_VALID(typ, num)   (((typ) == CY_SYSCLK_DIV_16_BIT)   && ((num) < PERI_PCLK_DIV_16_NR))
#else
#define IS_DIV_16_TYPE_NUM_VALID(typ, num)   (0U != 0U)
#endif

#if (0U != PERI_PCLK_DIV_16_5_NR)
#define IS_DIV_16_5_TYPE_NUM_VALID(typ, num) (((typ) == CY_SYSCLK_DIV_16_5_BIT) && ((num) < PERI_PCLK_DIV_16_5_NR))
#else
#define IS_DIV_16_5_TYPE_NUM_VALID(typ, num) (0U != 0U)
#endif

#if (0U != PERI_PCLK_DIV_24_5_NR)
#define IS_DIV_24_5_TYPE_NUM_VALID(typ, num) (((typ) == CY_SYSCLK_DIV_24_5_BIT) && ((num) < PERI_PCLK_DIV_24_5_NR))
#else
#define IS_DIV_24_5_TYPE_NUM_VALID(typ, num) (0U != 0U)
#endif

#define IS_DIV_INT_TYPE_NUM_VALID(typ, num)  (IS_DIV_8_TYPE_NUM_VALID((typ), (num)) || \
                                              IS_DIV_16_TYPE_NUM_VALID((typ), (num)))

#define IS_DIV_FRC_TYPE_NUM_VALID(typ, num)  (IS_DIV_16_5_TYPE_NUM_VALID((typ), (num)) || \
                                              IS_DIV_24_5_TYPE_NUM_VALID((typ), (num)))

#define IS_DIV_TYPE_NUM_VALID(typ, num)      (IS_DIV_INT_TYPE_NUM_VALID((typ), (num)) || \
                                              IS_DIV_FRC_TYPE_NUM_VALID((typ), (num)))

#define IS_DIV_PA_TYPE_NUM_VALID(typ, num)   (IS_DIV_TYPE_NUM_VALID((typ), (num)) || \
                                              (((typ) == CY_SYSCLK_DIV_24_5_BIT) && ((num) == 63UL)))
/** \endcond */

/**
* \addtogroup group_sysclk_clk_peripheral_funcs
* \{
*/


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphSetDivider
****************************************************************************//**
*
* Sets one of the programmable clock dividers. This is only used for integer
* dividers. Use \ref Cy_SysClk_PeriphSetFracDivider for setting factional dividers.
*
* \pre If the specified clock divider is already enabled - it should be disabled
* prior to use this function by \ref Cy_SysClk_PeriphDisableDivider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_sysclk_divider_types_t
*
* \param dividerNum the divider number.
*
* \param dividerValue divider value
* Causes integer division of (divider value + 1), or division by 1 to 256
* (8-bit divider) or 1 to 65536 (16-bit divider).
*
* \return \ref cy_en_sysclk_status_t
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PeriphSetDivider
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PeriphSetDivider(cy_en_sysclk_divider_types_t dividerType,
                                                                     uint32_t dividerNum,
                                                                     uint32_t dividerValue)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
#if (0UL != PERI_PCLK_DIV_8_NR)
    if (IS_DIV_8_TYPE_NUM_VALID(dividerType, dividerNum) &&
        (dividerValue <= (PERI_DIV_8_CTL_INT8_DIV_Msk >> PERI_DIV_8_CTL_INT8_DIV_Pos)))
    {
        CY_REG32_CLR_SET(PERI_DIV_8_CTL[dividerNum], PERI_DIV_8_CTL_INT8_DIV, dividerValue);
        retVal = CY_SYSCLK_SUCCESS;
    }
    else
#endif /* PERI_PCLK_DIV_8_NR */
#if (0UL != PERI_PCLK_DIV_16_NR)
    if (IS_DIV_16_TYPE_NUM_VALID(dividerType, dividerNum) &&
        (dividerValue <= (PERI_DIV_16_CTL_INT16_DIV_Msk >> PERI_DIV_16_CTL_INT16_DIV_Pos)))
    {
        CY_REG32_CLR_SET(PERI_DIV_16_CTL[dividerNum], PERI_DIV_16_CTL_INT16_DIV, dividerValue);
        retVal = CY_SYSCLK_SUCCESS;
    }
    else
#endif /* PERI_PCLK_DIV_16_NR */
    {
        /* return bad parameter */
    }
    return (retVal);
}

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetDivider
****************************************************************************//**
*
* Returns the integer divider value for the specified divider. One works for
* integer dividers. Use \ref Cy_SysClk_PeriphGetFracDivider to get the fractional
* divider value
*
* \param dividerType specifies which type of divider to use; \ref cy_en_sysclk_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \return The divider value.
* The integer division done is by (divider value + 1), or division by 1 to 256
* (8-bit divider) or 1 to 65536 (16-bit divider).
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PeriphSetDivider
*
*******************************************************************************/
uint32_t Cy_SysClk_PeriphGetDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum)
{
    uint32_t retVal = 0UL;

    CY_ASSERT_L1(IS_DIV_INT_TYPE_NUM_VALID(dividerType, dividerNum));

#if (0UL != PERI_PCLK_DIV_8_NR)
    if (IS_DIV_8_TYPE_NUM_VALID(dividerType, dividerNum))
    {
        retVal = _FLD2VAL(PERI_DIV_8_CTL_INT8_DIV, PERI_DIV_8_CTL[dividerNum]);
    }
    else
#endif /* PERI_PCLK_DIV_8_NR */
#if (0UL != PERI_PCLK_DIV_16_NR)
    if (IS_DIV_16_TYPE_NUM_VALID(dividerType, dividerNum))
    {
        retVal = _FLD2VAL(PERI_DIV_16_CTL_INT16_DIV, PERI_DIV_16_CTL[dividerNum]);
    }
    else
#endif /* PERI_PCLK_DIV_16_NR */
    {
        /* return zero divider */
    }
    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphSetFracDivider
****************************************************************************//**
*
* Sets one of the programmable clock dividers. This function should only be used
* for fractional clock dividers.
*
* \pre If the specified clock divider is already enabled - it should be disabled
* prior to use this function by \ref Cy_SysClk_PeriphDisableDivider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_sysclk_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \param dividerIntValue the integer divider value
* The source of the divider is peri_clk, which is a divided version of HFCLK.
* The divider value causes integer division of (divider value + 1), or division
* by 1 to 65536 (16-bit divider) or 1 to 16777216 (24-bit divider).
*
* \param dividerFracValue the fraction part of the divider
* The fractional divider can be 1-32, thus it divides the clock by 1/32 for each
* count. To divide the clock by 11/32nds set this value to 11.
*
* \return \ref cy_en_sysclk_status_t
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PeriphSetFracDivider
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PeriphSetFracDivider(cy_en_sysclk_divider_types_t dividerType,
                                                                         uint32_t dividerNum,
                                                                         uint32_t dividerIntValue,
                                                                         uint32_t dividerFracValue)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    CY_UNUSED_PARAMETER(dividerType);
    CY_UNUSED_PARAMETER(dividerNum);
    CY_UNUSED_PARAMETER(dividerIntValue);
    CY_UNUSED_PARAMETER(dividerFracValue);

#if (0UL != PERI_PCLK_DIV_16_5_NR)
    if (IS_DIV_16_5_TYPE_NUM_VALID(dividerType, dividerNum) &&
        (dividerIntValue <= (PERI_DIV_16_5_CTL_INT16_DIV_Msk >> PERI_DIV_16_5_CTL_INT16_DIV_Pos)) &&
        (dividerFracValue <= (PERI_DIV_16_5_CTL_FRAC5_DIV_Msk >> PERI_DIV_16_5_CTL_FRAC5_DIV_Pos)))
    {
        CY_REG32_CLR_SET(PERI_DIV_16_5_CTL[dividerNum], PERI_DIV_16_5_CTL_INT16_DIV, dividerIntValue);
        CY_REG32_CLR_SET(PERI_DIV_16_5_CTL[dividerNum], PERI_DIV_16_5_CTL_FRAC5_DIV, dividerFracValue);
        retVal = CY_SYSCLK_SUCCESS;
    }
    else
#endif /* PERI_PCLK_DIV_16_5_NR */
#if (0UL != PERI_PCLK_DIV_24_5_NR)
    if (IS_DIV_24_5_TYPE_NUM_VALID(dividerType, dividerNum) &&
        (dividerIntValue <= (PERI_DIV_24_5_CTL_INT24_DIV_Msk >> PERI_DIV_24_5_CTL_INT24_DIV_Pos)) &&
        (dividerFracValue <= (PERI_DIV_24_5_CTL_FRAC5_DIV_Msk >> PERI_DIV_24_5_CTL_FRAC5_DIV_Pos)))
    {
        CY_REG32_CLR_SET(PERI_DIV_24_5_CTL[dividerNum], PERI_DIV_24_5_CTL_INT24_DIV, dividerIntValue);
        CY_REG32_CLR_SET(PERI_DIV_24_5_CTL[dividerNum], PERI_DIV_24_5_CTL_FRAC5_DIV, dividerFracValue);
        retVal = CY_SYSCLK_SUCCESS;
    }
    else
#endif /* PERI_PCLK_DIV_24_5_NR */
    {
        /* return bad parameter */
    }
    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetFracDivider
****************************************************************************//**
*
* Reports the integer and fractional parts of the divider
*
* \param dividerType specifies which type of divider to use; \ref cy_en_sysclk_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \param *dividerIntValue pointer to return integer divider value
*
* \param *dividerFracValue pointer to return fractional divider value
*
* \return None. Loads pointed-to variables.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PeriphSetFracDivider
*
*******************************************************************************/
void Cy_SysClk_PeriphGetFracDivider(cy_en_sysclk_divider_types_t   dividerType,
                                                        uint32_t   dividerNum,
                                                        uint32_t * dividerIntValue,
                                                        uint32_t * dividerFracValue)
{
    CY_ASSERT_L1(IS_DIV_FRC_TYPE_NUM_VALID(dividerType, dividerNum));
    CY_ASSERT_L1(NULL != dividerIntValue);
    CY_ASSERT_L1(NULL != dividerFracValue);

    CY_UNUSED_PARAMETER(dividerType);
    CY_UNUSED_PARAMETER(dividerNum);

#if (0UL != PERI_PCLK_DIV_16_5_NR)
    if (IS_DIV_16_5_TYPE_NUM_VALID(dividerType, dividerNum))
    {
        *dividerIntValue  = _FLD2VAL(PERI_DIV_16_5_CTL_INT16_DIV, PERI_DIV_16_5_CTL[dividerNum]);
        *dividerFracValue = _FLD2VAL(PERI_DIV_16_5_CTL_FRAC5_DIV, PERI_DIV_16_5_CTL[dividerNum]);
    }
    else
#endif /* PERI_PCLK_DIV_16_5_NR */
#if (0UL != PERI_PCLK_DIV_24_5_NR)
    if (IS_DIV_24_5_TYPE_NUM_VALID(dividerType, dividerNum))
    {
        *dividerIntValue  = _FLD2VAL(PERI_DIV_24_5_CTL_INT24_DIV, PERI_DIV_24_5_CTL[dividerNum]);
        *dividerFracValue = _FLD2VAL(PERI_DIV_24_5_CTL_FRAC5_DIV, PERI_DIV_24_5_CTL[dividerNum]);
    }
    else
#endif /* PERI_PCLK_DIV_24_5_NR */
    {
        *dividerIntValue  = 0UL;
        *dividerFracValue = 0UL;
    }
}


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetFrequency
****************************************************************************//**
*
* Reports the frequency of the output of a given peripheral divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_sysclk_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \return The frequency, in Hz.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PeriphGetFrequency
*
*******************************************************************************/
uint32_t Cy_SysClk_PeriphGetFrequency(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum)
{
    uint32_t integer = 0UL;        /* Integer part of peripheral divider */
    uint32_t freq = Cy_SysClk_ClkHfGetFrequency(); /* Get HFCLK frequency */

    CY_ASSERT_L1(IS_DIV_TYPE_NUM_VALID(dividerType, dividerNum));

    /* get the divider value for clk_peri to the selected peripheral clock */
    switch(dividerType)
    {
    #if (0UL != PERI_PCLK_DIV_8_NR)
        case CY_SYSCLK_DIV_8_BIT:
    #endif /* PERI_PCLK_DIV_8_NR */
    #if (0UL != PERI_PCLK_DIV_16_NR)
        case CY_SYSCLK_DIV_16_BIT:
    #endif /* PERI_PCLK_DIV_16_NR */
    #if ((0UL != PERI_PCLK_DIV_8_NR) || (0UL != PERI_PCLK_DIV_16_NR))
            integer = 1UL + Cy_SysClk_PeriphGetDivider(dividerType, dividerNum);
            freq = CY_SYSLIB_DIV_ROUND(freq, integer);
            break;
    #endif /* PERI_PCLK_DIV_8_NR or PERI_PCLK_DIV_16_NR */
    #if (0UL != PERI_PCLK_DIV_16_5_NR)
        case CY_SYSCLK_DIV_16_5_BIT:
    #endif /* PERI_PCLK_DIV_16_5_NR */
    #if (0UL != PERI_PCLK_DIV_24_5_NR)
        case CY_SYSCLK_DIV_24_5_BIT:
    #endif /* PERI_PCLK_DIV_24_5_NR */
    #if ((0UL != PERI_PCLK_DIV_16_5_NR) || (0UL != PERI_PCLK_DIV_24_5_NR))
            {
                uint32_t locFrac;
                uint32_t locDiv;
                uint32_t locFreq = freq * 32UL;
                Cy_SysClk_PeriphGetFracDivider(dividerType, dividerNum, &integer, &locFrac);
                /* For fractional dividers, the divider is (int + 1) + frac/32 */
                locDiv = ((1UL + integer) * 32UL) + locFrac;
                freq = CY_SYSLIB_DIV_ROUND(locFreq, locDiv);
            }
            break;
    #endif /* CY_SYSCLK_DIV_16_5_BIT or CY_SYSCLK_DIV_24_5_BIT */

        default:
            /* Invalid divider type */
            break;
    }

    return (freq);
}


/** \cond internal */
/* Fractional part divider mask */
#define FRAC_MASK (PERI_DIV_16_5_CTL_FRAC5_DIV_Msk >> PERI_DIV_16_5_CTL_FRAC5_DIV_Pos)
/* shift value for the integer divider part */
#define INTG_SHIFT (5UL)
/** \endcond */
/*******************************************************************************
* Function Name: Cy_SysClk_PeriphSetFrequency
****************************************************************************//**
*
* Calculates the dividing factor for the desired frequency,
* applies it to the specified peripheral divider
* and reports the achieved frequency.
*
* \pre This function reuses \ref Cy_SysClk_PeriphSetDivider/\ref Cy_SysClk_PeriphSetFracDivider,
* so if the clock divider is already enabled - it should be disabled
* prior to use this function by \ref Cy_SysClk_PeriphDisableDivider.
*
* \param dividerType specifies which type of divider to use \ref cy_en_sysclk_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \param frequency specifies the desired frequency, in Hz.
*
* \return The achieved frequency, in Hz.
*
* \funcusage \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_PERI_SET_FREQ
*
*******************************************************************************/
uint32_t Cy_SysClk_PeriphSetFrequency(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum, uint32_t frequency)
{
    uint32_t resFreq = 0UL; /* The closest achieved frequency to the desired frequency */
    uint32_t refFreq = Cy_SysClk_ClkHfGetFrequency(); /* The reference HFCLK frequency */

    CY_ASSERT_L1(IS_DIV_TYPE_NUM_VALID(dividerType, dividerNum));
    CY_ASSERT_L1(0UL != frequency);
    CY_ASSERT_L1(refFreq >= frequency);

    if ((0UL != frequency) && (refFreq >= frequency))
    {
        uint32_t locDiv = 1UL; /* Initial divider value */

        /* Get the maximal divider value for clk_peri to the selected peripheral clock */
        switch(dividerType)
        {
        #if (0UL != PERI_PCLK_DIV_8_NR)
            case CY_SYSCLK_DIV_8_BIT:
                locDiv = 1UL + (PERI_DIV_8_CTL_INT8_DIV_Msk >> PERI_DIV_8_CTL_INT8_DIV_Pos); /* 256 */
                break;
        #endif /* PERI_PCLK_DIV_8_NR */
        #if (0UL != PERI_PCLK_DIV_16_NR)
            case CY_SYSCLK_DIV_16_BIT:
                locDiv = 1UL + (PERI_DIV_16_CTL_INT16_DIV_Msk >> PERI_DIV_16_CTL_INT16_DIV_Pos); /* 65536 */
                break;
        #endif /* PERI_PCLK_DIV_16_NR */
        #if (0UL != PERI_PCLK_DIV_16_5_NR)
            case CY_SYSCLK_DIV_16_5_BIT:
                locDiv = ((1UL + (PERI_DIV_16_5_CTL_INT16_DIV_Msk >> PERI_DIV_16_5_CTL_INT16_DIV_Pos)) << INTG_SHIFT) | FRAC_MASK; /* 65536 + 31/32 */
                refFreq <<= INTG_SHIFT;
                break;
        #endif /* PERI_PCLK_DIV_16_5_NR */
        #if (0UL != PERI_PCLK_DIV_24_5_NR)
            case CY_SYSCLK_DIV_24_5_BIT:
                locDiv = ((1UL + (PERI_DIV_24_5_CTL_INT24_DIV_Msk >> PERI_DIV_24_5_CTL_INT24_DIV_Pos)) << INTG_SHIFT) | FRAC_MASK; /* 16777216 + 31/32 */
                refFreq <<= INTG_SHIFT;
                break;
        #endif /* PERI_PCLK_DIV_24_5_NR */

            default:
                refFreq = 0UL; /* Indication that the divider type is not supported */
                break;
        }

        if (0UL != refFreq)
        {
            resFreq = CY_SYSLIB_DIV_ROUND(refFreq, frequency); /* Temporarily use the resFreq variable as the desired divider */

            if ((locDiv > resFreq) && (0UL != resFreq)) /* If the desired frequency is within the achievable range */
            {
                locDiv = resFreq;
            }

            /* Change the divider(s) */
        #if ((0UL != PERI_PCLK_DIV_8_NR) && (0UL != PERI_PCLK_DIV_16_NR) && (0UL != PERI_PCLK_DIV_24_5_NR) && (0UL != PERI_PCLK_DIV_16_5_NR))
            if ((CY_SYSCLK_DIV_8_BIT == dividerType) || (CY_SYSCLK_DIV_16_BIT == dividerType))
        #elif (0UL != PERI_PCLK_DIV_8_NR)
            if (CY_SYSCLK_DIV_8_BIT == dividerType)
        #elif (0UL != PERI_PCLK_DIV_16_NR)
            if (CY_SYSCLK_DIV_16_BIT == dividerType)
        #endif /* integer dividers clauses */
        #if ((0UL != PERI_PCLK_DIV_8_NR) || (0UL != PERI_PCLK_DIV_16_NR))
            {
                (void)Cy_SysClk_PeriphSetDivider(dividerType, dividerNum, locDiv - 1UL);
            }
        #endif /* Integer dividers support */
        #if (((0UL != PERI_PCLK_DIV_8_NR) || (0UL != PERI_PCLK_DIV_16_NR)) && ((0UL != PERI_PCLK_DIV_16_5_NR) || (0UL != PERI_PCLK_DIV_24_5_NR)))
            else
        #endif /* Combine dividers support */
        #if ((0UL != PERI_PCLK_DIV_16_5_NR) || (0UL != PERI_PCLK_DIV_24_5_NR))
            {
                (void)Cy_SysClk_PeriphSetFracDivider(dividerType, dividerNum, (locDiv >> INTG_SHIFT) - 1UL, FRAC_MASK & locDiv);
            }
        #endif /* Fractional dividers support */

            resFreq = CY_SYSLIB_DIV_ROUND(refFreq, locDiv); /* Calculate the achieved frequency */
        }
    }

    return (resFreq);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphAssignDivider
****************************************************************************//**
*
* Assigns a programmable divider to a selected IP block, such as a TCPWM or SCB.
*
* \param periphNum specifies the peripheral block \ref en_clk_dst_t.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_sysclk_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \return \ref cy_en_sysclk_status_t
*
* \funcusage \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_PERI_SET_FREQ
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PeriphAssignDivider(en_clk_dst_t periphNum, cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    if ((PERI_PCLK_CLOCK_NR > (uint32_t)periphNum) && IS_DIV_TYPE_NUM_VALID(dividerType, dividerNum))
    {
        PERI_PCLK_CTL[periphNum] = _VAL2FLD(PERI_PCLK_CTL_SEL_TYPE, dividerType) |
                                   _VAL2FLD(PERI_PCLK_CTL_SEL_DIV,  dividerNum);
        retVal = CY_SYSCLK_SUCCESS;
    }
    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphEnableDivider
****************************************************************************//**
*
* Enables the selected divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_sysclk_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \note This function also sets the phase alignment bits such that the enabled
* divider is aligned to clk_peri. See \ref Cy_SysClk_PeriphDisableDivider()
* for information on how to phase-align a divider after it is enabled.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PeriphEnableDivider
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PeriphEnableDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    if (IS_DIV_TYPE_NUM_VALID(dividerType, dividerNum))
    {
        /* specify the divider, make the reference = clk_peri, and enable the divider */
        PERI_DIV_CMD = PERI_DIV_CMD_ENABLE_Msk             |
                       PERI_DIV_CMD_PA_SEL_TYPE_Msk        |
                       PERI_DIV_CMD_PA_SEL_DIV_Msk         |
              _VAL2FLD(PERI_DIV_CMD_SEL_TYPE, dividerType) |
              _VAL2FLD(PERI_DIV_CMD_SEL_DIV,  dividerNum);
        (void)PERI_DIV_CMD; /* dummy read to handle buffered writes */
        retVal = CY_SYSCLK_SUCCESS;
    }

    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphDisableDivider
****************************************************************************//**
*
* Disables a selected divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_sysclk_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PeriphDisableDivider
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PeriphDisableDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    if (IS_DIV_TYPE_NUM_VALID(dividerType, dividerNum))
    {
        /* specify the divider and disable it */
        PERI_DIV_CMD = PERI_DIV_CMD_DISABLE_Msk            |
              _VAL2FLD(PERI_DIV_CMD_SEL_TYPE, dividerType) |
              _VAL2FLD(PERI_DIV_CMD_SEL_DIV,  dividerNum);
        retVal = CY_SYSCLK_SUCCESS;
    }

    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphDividerIsEnabled
****************************************************************************//**
*
* Reports the enabled/disabled state of the selected divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_sysclk_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
* \return The enabled/disabled state; \n
* false = disabled \n
* true = enabled
*
* \funcusage \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_PERI_SET_FREQ
*
*******************************************************************************/
bool Cy_SysClk_PeriphDividerIsEnabled(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum)
{
    bool retVal = false;

    CY_ASSERT_L1(IS_DIV_TYPE_NUM_VALID(dividerType, dividerNum));

    switch(dividerType)
    {
        #if (0UL != PERI_PCLK_DIV_8_NR)
            case CY_SYSCLK_DIV_8_BIT:
                retVal = _FLD2BOOL(PERI_DIV_8_CTL_EN, PERI_DIV_8_CTL[dividerNum]);
                break;
        #endif /* PERI_PCLK_DIV_8_NR */
        #if (0UL != PERI_PCLK_DIV_16_NR)
            case CY_SYSCLK_DIV_16_BIT:
                retVal = _FLD2BOOL(PERI_DIV_16_CTL_EN, PERI_DIV_16_CTL[dividerNum]);
                break;
        #endif /* PERI_PCLK_DIV_16_NR */
        #if (0UL != PERI_PCLK_DIV_16_5_NR)
            case CY_SYSCLK_DIV_16_5_BIT:
                retVal = _FLD2BOOL(PERI_DIV_16_5_CTL_EN, PERI_DIV_16_5_CTL[dividerNum]);
                break;
        #endif /* PERI_PCLK_DIV_16_5_NR */
        #if (0UL != PERI_PCLK_DIV_24_5_NR)
            case CY_SYSCLK_DIV_24_5_BIT:
                retVal = _FLD2BOOL(PERI_DIV_24_5_CTL_EN, PERI_DIV_24_5_CTL[dividerNum]);
                break;
        #endif /* PERI_PCLK_DIV_24_5_NR */
            default:
                /* Invalid divider type */
                break;
    }
    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphEnablePhaseAlignDivider
****************************************************************************//**
*
* First disables a selected divider (\ref Cy_SysClk_PeriphDisableDivider),
* then aligns that divider to another programmable divider, and enables the
* selected divider. The divider to align to must already be enabled in order
* to align a divider to it.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_sysclk_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
* \param dividerTypePA type of divider to phase-align to; \ref cy_en_sysclk_divider_types_t.
*
* \param dividerNumPA divider number of type specified to phase align to.
*
* \note
* To phase-align a divider to hfclk, set dividerTypePA to 3 and dividerNumPA
* to 63.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PeriphEnablePhaseAlignDivider
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PeriphEnablePhaseAlignDivider(cy_en_sysclk_divider_types_t dividerType,
                                                                                  uint32_t dividerNum,
                                                              cy_en_sysclk_divider_types_t dividerTypePA,
                                                                                  uint32_t dividerNumPA)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    if (IS_DIV_PA_TYPE_NUM_VALID(dividerTypePA, dividerNumPA))
    {
        /* First, disable the divider that is to be phase-aligned.
           The other two parameters are checked in that function;
           if they're not valid, the divider is not disabled. */
        retVal = Cy_SysClk_PeriphDisableDivider(dividerType, dividerNum);
        if (retVal == CY_SYSCLK_SUCCESS)
        {
            /* Then, specify the reference divider, and the divider, and enable the divider */
            PERI_DIV_CMD = PERI_DIV_CMD_ENABLE_Msk             |
                  _VAL2FLD(PERI_DIV_CMD_PA_SEL_TYPE, dividerTypePA) |
                  _VAL2FLD(PERI_DIV_CMD_PA_SEL_DIV,  dividerNumPA)  |
                  _VAL2FLD(PERI_DIV_CMD_SEL_TYPE, dividerType)      |
                  _VAL2FLD(PERI_DIV_CMD_SEL_DIV,  dividerNum);
        }
    }
    return (retVal);
}

/** \} group_sysclk_clk_peripheral_funcs */


/* ========================================================================== */
/* =========================    clk_pump SECTION    ========================= */
/* ========================================================================== */


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpSetSource
****************************************************************************//**
*
* Sets the source for the pump clock (clk_pump). The pump clock can be used for
* the analog pumps in the CTB block.
*
* \param source \ref cy_en_sysclk_clkpump_src_t
*
* \return  Error / status code \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - the source is successfully set \n
* \ref CY_SYSCLK_INVALID_STATE - the selected clock source is not enabled \n
* \ref CY_SYSCLK_BAD_PARAM - the source parameter is invalid.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkPumpSetSource
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkPumpSetSource(cy_en_sysclk_clkpump_src_t source)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;

    if (CY_SYSCLK_IS_PUMP_SRC_VALID(source))
    {
        if ((CY_SYSCLK_PUMP_IN_IMO == source) && (!Cy_SysClk_ImoIsEnabled()))
        {
            retVal = CY_SYSCLK_INVALID_STATE;
        }
        else
        {
        #if defined (CY_IP_M0S8SRSSHV)
            /* Avoid lock register's potential race condition. */
            uint32_t intrState = Cy_SysLib_EnterCriticalSection();
            Cy_SysClk_UnlockProtReg();
        #endif /* defined (CY_IP_M0S8SRSSHV) */
            CY_REG32_CLR_SET(SRSS_CLK_SELECT, SRSS_CLK_SELECT_PUMP_SEL, source);
        #if defined (CY_IP_M0S8SRSSHV)
            Cy_SysClk_LockProtReg();
            Cy_SysLib_ExitCriticalSection(intrState);
        #endif /* defined (CY_IP_M0S8SRSSHV) */
        }
    }
    else
    {
        retVal = CY_SYSCLK_BAD_PARAM;
    }

    return (retVal);
}


#if (defined(CY_IP_M0S8EXCO) && (CY_IP_M0S8EXCO == 1u))
#if (defined(EXCO_PLL_PRESENT) && (EXCO_PLL_PRESENT == 1u))
#if (CY_IP_M0S8EXCO_VERSION == 2U)
/*******************************************************************************
* Function Name: Cy_SysClk_CsvInit
****************************************************************************//**
*
* Initializes the clock supervision parameters.
*
* This API is available on devices with the CSV Feature (i.e. PSOC 4500S and 4100S Max).
* Refer to the Device Datasheet to check the CSV feature support.
*
* \param config A pointer to the structure of type \ref cy_stc_sysclk_csv_config_t
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_ISR
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_CFG
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_INT
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_TRG
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_EN
*
*******************************************************************************/
void Cy_SysClk_CsvInit(cy_stc_sysclk_csv_config_t * config)
{
    CY_ASSERT_L1(NULL != config);

    if (NULL != config)
    {
        EXCO_REF_CTL = _VAL2FLD(EXCO_REF_CTL_STARTUP,       config->startupDelay) |
                      _BOOL2FLD(EXCO_REF_CTL_CSV_INT_EN,    config->interruptEn)  |
                      _BOOL2FLD(EXCO_REF_CTL_CSV_TRIG_EN,   config->triggerEn)    |
                      _BOOL2FLD(EXCO_REF_CTL_CSV_CLK_SW_EN, config->clkSwitchEn);

        EXCO_MON_CTL = _VAL2FLD(EXCO_MON_CTL_PERIOD, config->period);

        EXCO_REF_LIMIT = _VAL2FLD(EXCO_REF_LIMIT_LOWER, config->lowerLimit) |
                         _VAL2FLD(EXCO_REF_LIMIT_UPPER, config->upperLimit);
    }
}


#endif /* CY_IP_M0S8EXCO_VERSION == 2U */
#endif /* EXCO_PLL_PRESENT */
#endif /* CY_IP_M0S8EXCO */

/* ========================================================================== */
/* ======================    POWER MANAGEMENT SECTION    ==================== */
/* ========================================================================== */

/** \cond INTERNAL */
/* Timeout in us for use in function Cy_SysClk_DeepSleepCallback() */
#define DEEP_SLEEP_ECO_TIMEOUT (10000UL) /* 10 ms for 4MHz crystals */
#define DEEP_SLEEP_PLL_TIMEOUT (250UL)   /* 250 us for PLL */
/** \endcond */

/*******************************************************************************
* Function Name: Cy_SysClk_DeepSleepCallback
****************************************************************************//**
*
* Callback function to be used when entering system Deep Sleep mode.
* This function is needed if PLL and/or ECO are enabled and
* used as a source for HFCLK.
*
* This function performs the following:
*
* 1. Before entering Deep Sleep, the clock configuration is saved in SRAM.
*    If the HFCLK is clocked by EXCO (PLL/ECO) - the HFCLK
*    source is changed to IMO (with it current frequency, also IMO is being
*    enabled in case it was disabled).
* 2. Upon wakeup from Deep Sleep, the function waits for ECO/PLL stabilization/locking,
*    then restores the clock chain configuration.
* 3. It performs unlocking IMO (in case if it was locked with WCO) before falling asleep
*    and correspondingly locks it after waking up (it it was locked before).
* 4. It interacts with the ILO calibrating API: the \ref Cy_SysClk_IloStartMeasurement
*    will not work after the CY_SYSPM_CHECK_READY, or falling asleep will be cancelled
*    in case of the ILO measurement is already in progress.
*
* The function prevents entry into Deep Sleep mode if the ILO measurement
* is currently performing; see \ref Cy_SysClk_IloStartMeasurement.
*
* This function can be called during execution of \ref Cy_SysPm_CpuEnterDeepSleep.
* To do so, register this function as a callback before calling
* \ref Cy_SysPm_CpuEnterDeepSleep - specify \ref CY_SYSPM_DEEPSLEEP as the callback
* type and call \ref Cy_SysPm_RegisterCallback.
*
* \note
* This function is recommended to be the last callback that is registered.
* Doing so minimizes the time spent on low power mode entry and exit. \n
* Also, after this callback execution before falling asleep
*  and before this callback execution after waking up the HFCLK speed may be not as usual
* (it is switched to IMO), so it may affect other peripherals. \n
* This function implements all four SysPm callback modes \ref cy_en_syspm_callback_mode_t.
* So the \ref cy_stc_syspm_callback_t::skipMode must be set to 0UL. \n
* You can use this callback implementation as an example to design custom low-power
* callbacks for certain user application.
*
* \note There is a non-zero possibility of the ECO/PLL startup timeout at wakeup,
* therefore there is a user callback feature to indicate that,
* see \ref Cy_SysClk_RegisterCallback and \ref group_sysclk_pm_events.
* In case of ECO/PLL timeout, the HFCLK is not restored to the state as it was before the
* Deep Sleep, so user should either try to reconfigure the HFCLK clocking chain
* or adapt other periphery to the new HFCLK frequency
* (reconfigure peripheral clock dividers to restore the communication speed, etc.).
*
* \param callbackParams
* structure with the syspm callback parameters,
* see \ref cy_stc_syspm_callback_params_t.
*
* \param mode
* Callback mode, see \ref cy_en_syspm_callback_mode_t
*
* \return Error / status code; see \ref cy_en_syspm_status_t.
* Pass if not doing an ILO measurement, otherwise - Fail.
*
* \funcusage \snippet sysclk/snippet/sysclk_snippet.c snippet_Cy_SysClk_DeepSleepCallback_prep
* \funcusage \snippet sysclk/snippet/sysclk_snippet.c snippet_Cy_SysClk_DeepSleepCallback_reg
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysClk_DeepSleepCallback(cy_stc_syspm_callback_params_t * callbackParams, cy_en_syspm_callback_mode_t mode)
{
#if defined (CY_IP_M0S8EXCO)
    static bool exco;
    static bool eco;
    static bool pll;
#endif /* CY_IP_M0S8EXCO */

#if defined (CY_IP_M0S8EXCO) || defined(CY_IP_M0S8WCO)
    static bool imo;
#endif /* (CY_IP_M0S8EXCO || CY_IP_M0S8WCO) */

#if defined(CY_IP_M0S8WCO)
    static cy_en_sysclk_imo_lock_t imoLock;
#endif /* (CY_IP_M0S8WCO) */

    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    CY_UNUSED_PARAMETER(callbackParams);

    switch (mode)
    {
        case CY_SYSPM_CHECK_READY:
            /* Don't allow entry into Deep Sleep mode if currently measuring a frequency */
            if (!iloMeasurment)
            {
                /* Indicating that we can go into Deep Sleep.
                 * Prevent starting a new clock measurement until
                 * after we've come back from Deep Sleep.
                 */
                preventIloMeasurment = true;
            }
            else
            {
                retVal = CY_SYSPM_FAIL;
            }
            break;

        case CY_SYSPM_CHECK_FAIL:
            /* Cancellation of going into Deep Sleep, therefore allow a new clock measurement */
            preventIloMeasurment = false;
            break;

        case CY_SYSPM_BEFORE_TRANSITION:
            {
            #if defined (CY_IP_M0S8EXCO) || defined(CY_IP_M0S8WCO)
                imo = Cy_SysClk_ImoIsEnabled();
            #endif /* (CY_IP_M0S8EXCO || CY_IP_M0S8WCO) */

            #if defined(CY_IP_M0S8WCO)
                if (imo)
                {
                    imoLock = Cy_SysClk_ImoGetLockStatus();
                    /* Cy_SysClk_ImoLock always returns CY_SYSCLK_SUCCESS
                     * with CY_SYSCLK_IMO_LOCK_NONE if IMO is enabled.
                     */
                    (void)Cy_SysClk_ImoLock(CY_SYSCLK_IMO_LOCK_NONE);
                }
            #endif /* (CY_IP_M0S8WCO) */

            #if defined (CY_IP_M0S8EXCO)
                exco = (CY_SYSCLK_CLKHF_IN_EXCO == Cy_SysClk_ClkHfGetSource());

                if (exco)
                {
                    if (!imo)
                    {
                        Cy_SysClk_ImoEnable();
                    }

                    Cy_SysLib_SetWaitStates((uint32_t)CY_SYSCLK_IMO_48MHZ / CY_SYSCLK_FREQ_SCALER);

                    (void)Cy_SysClk_ClkHfSetSource(CY_SYSCLK_CLKHF_IN_IMO);

                    pll = Cy_SysClk_PllIsEnabled(0UL);
                    eco = Cy_SysClk_EcoIsEnabled();
                }
            #endif /* CY_IP_M0S8EXCO */
            }
            break;

        case CY_SYSPM_AFTER_TRANSITION:
            {
            #if defined (CY_IP_M0S8EXCO)
                if (exco)
                {
                    uint32_t timeout = DEEP_SLEEP_ECO_TIMEOUT;
                    SystemCoreClockUpdate(); /* for proper Cy_SysLib_DelayUs working with IMO */

                    if (eco)
                    {
                        while ((CY_SYSCLK_ECO_STABLE != Cy_SysClk_EcoGetStatus()) && (0UL != timeout))
                        {
                            timeout--;
                            Cy_SysLib_DelayUs(1U);
                        }
                    }

                    if (0UL != timeout)
                    {
                        if (pll)
                        {
                            timeout = DEEP_SLEEP_PLL_TIMEOUT;

                            while ((!Cy_SysClk_PllIsLocked(0UL)) && (0UL != timeout))
                            {
                                timeout--;
                                Cy_SysLib_DelayUs(1U);
                            }
                        }

                        if (0UL != timeout)
                        {
                            (void)Cy_SysClk_ClkHfSetSource(CY_SYSCLK_CLKHF_IN_EXCO);

                            Cy_SysLib_SetWaitStates(Cy_SysClk_ClkSysGetFrequency()/1000000UL);
                            SystemCoreClockUpdate(); /* for proper Cy_SysLib_DelayUs working with restored HFCLK source */

                            if (!imo)
                            {
                                Cy_SysClk_ImoDisable();
                            }
                        }
                        else
                        {
                            /* Call the callback (if registered) */
                            if ((NULL != callbackParams->context) &&
                                (NULL != ((cy_stc_sysclk_context_t*)(callbackParams->context))->callback))
                            {
                                ((cy_stc_sysclk_context_t*)(callbackParams->context))->callback(CY_SYSCLK_PLL_TIMEOUT_EVENT);
                            }
                        }
                    }
                    else
                    {
                        /* Call the callback (if registered) */
                        if ((NULL != callbackParams->context) &&
                            (NULL != ((cy_stc_sysclk_context_t*)(callbackParams->context))->callback))
                        {
                            ((cy_stc_sysclk_context_t*)(callbackParams->context))->callback(CY_SYSCLK_ECO_TIMEOUT_EVENT);
                        }
                    }
                }
            #endif /* CY_IP_M0S8EXCO */

            #if defined(CY_IP_M0S8WCO)
                if (imo)
                {
                    /* Cy_SysClk_ImoLock always returns CY_SYSCLK_SUCCESS
                     * if IMO and WCO are enabled.
                     */
                    (void)Cy_SysClk_ImoLock(imoLock);
                }
            #endif /* (CY_IP_M0S8WCO) */

                preventIloMeasurment = false; /* Allow clock measurement */
            }
            break;

        default: /* Unsupported mode */
            retVal = CY_SYSPM_FAIL;
            break;
    }

    return (retVal);
}


/* [] END OF FILE */
