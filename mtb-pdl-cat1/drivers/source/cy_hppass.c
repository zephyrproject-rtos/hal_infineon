/***************************************************************************//**
* \file cy_hppass.c
* \version 1.20
*
* \brief
* Provides common public functions of the High Power Peripheral Analog Sub-System.
*
********************************************************************************
* \copyright
* Copyright (c) (2024), Cypress Semiconductor Corporation (an Infineon company) or
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
#include "cy_hppass.h"

#ifdef CY_IP_MXS40MCPASS

#define CY_HPPASS_SUPPRESS_AC_RUN_CHECK

#define CY_HPPASS_SAR_CAL_LIN_TABLE_SIZE (16U) /* The size of calibration values table to be loaded into CAL_LIN register */

/* Structure to save SAR calibration values during Deep Sleep */
static struct
{
    uint32_t caloffst_0;    /**< Calibration Offset #0 */
    uint32_t caloffst_1;    /**< Calibration Offset #1 */
    uint32_t caloffst_2;    /**< Calibration Offset #2 */
    uint32_t caloffst_3;    /**< Calibration Offset #3 */
    uint32_t calgainc;      /**< Coarse-grained Gain */
    uint32_t calgainf;      /**< Fine-grained Gain */
    uint32_t callin[CY_HPPASS_SAR_CAL_LIN_TABLE_SIZE]; /**< Linearity Calibration table */
} calVal;


static cy_en_hppass_status_t Cy_HPPASS_ApplyTrims(void)
{
    /* The max number of trim pair entries */
    #define CY_HPPASS_TRIMS_ENTRIES_NUM (7U)

    /* Trim data structure: address and value */
    typedef struct
    {
        volatile uint32_t * address;    /* Trim address */
        uint32_t value;                 /* Trim value */
    } cy_stc_hppass_trim_entry_t;

    /* SAR INFRA trim data structure*/
    typedef struct
    {
        uint32_t num_entries;           /* Number of trims entries */
        cy_stc_hppass_trim_entry_t entry[CY_HPPASS_TRIMS_ENTRIES_NUM]; /* Array of address-value pairs */
    } cy_stc_hppass_trims_t;

    cy_en_hppass_status_t result = CY_HPPASS_TRIM_ERROR;

    /* Copy AREF trimming values from SFLASH */
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional typecast to cy_stc_hppass_trims_t.');
    const cy_stc_hppass_trims_t * infraTrims = (cy_stc_hppass_trims_t*)SFLASH_SAR_INFRA_TRIM_TABLE;

    if (CY_HPPASS_TRIMS_ENTRIES_NUM == infraTrims->num_entries)
    {
        for (uint32_t i = 0UL; i < CY_HPPASS_TRIMS_ENTRIES_NUM; i++)
        {
            volatile uint32_t * trimAddr = infraTrims->entry[i].address;
            * trimAddr = infraTrims->entry[i].value;
        }

        for (uint8_t i = 0U; i < CY_HPPASS_SAR_CAL_LIN_TABLE_SIZE; i++)
        {
            HPPASS_SAR_CALLIN(HPPASS_BASE, i) = SFLASH_SAR_CAL_LIN_TABLE(i);
        }

        result = CY_HPPASS_SUCCESS;
    }

    return result;
}


cy_rslt_t Cy_HPPASS_Init(const cy_stc_hppass_cfg_t * cfg)
{
    cy_rslt_t result;

    HPPASS_AC_CTRL(HPPASS_BASE) = HPPASS_ACTRLR_CTRL_ENABLED_Msk;

    if (NULL == cfg)
    {
        result = (cy_rslt_t)CY_HPPASS_BAD_PARAM;
    }
    else if (Cy_HPPASS_AC_IsRunning() || Cy_HPPASS_AC_IsBlockReady())
    {
        result = (cy_rslt_t)CY_HPPASS_AC_INVALID_STATE;
    }
    else if (CY_HPPASS_SUCCESS != Cy_HPPASS_ApplyTrims())
    {
        result = (cy_rslt_t)CY_HPPASS_TRIM_ERROR;
    }
    else
    {
        CY_ASSERT_L2(CY_HPPASS_DIVSTCLK_VALID(cfg->ac.startupClkDiv));
        CY_ASSERT_L2(CY_HPPASS_ACGPIOOUTEN_VALID(cfg->ac.gpioOutEnMsk));

        HPPASS_INFRA_AREF_CTRL(HPPASS_BASE) = _VAL2FLD(HPPASS_INFRA_AREFV2_AREF_CTRL_IZTAT_SEL, 1UL)|
                                              _VAL2FLD(HPPASS_INFRA_AREFV2_AREF_CTRL_VREF_SEL, 1UL) |
                                              _VAL2FLD(HPPASS_INFRA_AREFV2_AREF_CTRL_ENABLED, 1UL)  |
                                              _VAL2FLD(HPPASS_INFRA_AREFV2_AREF_CTRL_AREF_BIAS_SCALE, 1UL);
        HPPASS_INFRA_CLOCK_STARTUP_DIV(HPPASS_BASE) = _VAL2FLD(HPPASS_INFRA_CLOCK_STARTUP_DIV_DIV_VAL, (uint32_t)cfg->ac.startupClkDiv - 1UL);
        HPPASS_AC_CFG(HPPASS_BASE) = _VAL2FLD(HPPASS_ACTRLR_CFG_DOUT_EN, cfg->ac.gpioOutEnMsk);

        result = (cy_rslt_t)Cy_HPPASS_AC_LoadStateTransitionTable(cfg->ac.sttEntriesNum, cfg->ac.stt);

        for (uint8_t i = 0U; i < CY_HPPASS_STARTUP_CFG_NUM; i++)
        {
            HPPASS_INFRA_STARTUP_CFG(HPPASS_BASE, i) = _VAL2FLD(HPPASS_INFRA_STARTUP_CFG_COUNT_VAL, cfg->ac.startup[i].count)           |
                                                       _VAL2FLD(HPPASS_INFRA_STARTUP_CFG_SAR_EN, cfg->ac.startup[i].sar)                |
                                                       _VAL2FLD(HPPASS_INFRA_STARTUP_CFG_CSG_CH_EN, cfg->ac.startup[i].csgChan)         |
                                                       _VAL2FLD(HPPASS_INFRA_STARTUP_CFG_CSG_PWR_EN_SLICE, cfg->ac.startup[i].csgSlice) |
                                                       _VAL2FLD(HPPASS_INFRA_STARTUP_CFG_CSG_READY, cfg->ac.startup[i].csgReady);
        }

        if (NULL != cfg->csg)
        {
            result |= (cy_rslt_t)Cy_HPPASS_CSG_Init(cfg->csg);
        }

        if (NULL != cfg->sar)
        {
            result |= (cy_rslt_t)Cy_HPPASS_SAR_Init(cfg->sar);
        }

        for (uint8_t i = 0U; i < CY_HPPASS_TRIG_NUM; i++)
        {
            result |= (cy_rslt_t)Cy_HPPASS_TriggerInConfig(i, &cfg->trigIn[i]);
            result |= (cy_rslt_t)Cy_HPPASS_TriggerOutPulseConfig(i, cfg->trigPulse[i]);
            result |= (cy_rslt_t)Cy_HPPASS_TriggerOutLevelConfig(i, &cfg->trigLevel[i]);
        }
    }

    return result;
}


void Cy_HPPASS_DeInit(void)
{
    /* Clear the enable bit */
    HPPASS_AC_CTRL(HPPASS_BASE) &= ~HPPASS_ACTRLR_CTRL_ENABLED_Msk;

    Cy_HPPASS_CSG_DeInit();
    Cy_HPPASS_SAR_DeInit();

    for (uint8_t i = 0U; i < CY_HPPASS_STARTUP_CFG_NUM; i++)
    {
        HPPASS_INFRA_STARTUP_CFG(HPPASS_BASE, i) = CY_HPPASS_DEINIT;
    }

    HPPASS_INFRA_AREF_CTRL(HPPASS_BASE) = CY_HPPASS_DEINIT;
    HPPASS_INFRA_CLOCK_STARTUP_DIV(HPPASS_BASE) = CY_HPPASS_CLK_STARTUP_DIV_DEINIT;
    HPPASS_AC_CFG(HPPASS_BASE) = CY_HPPASS_DEINIT;
    HPPASS_INFRA_TR_IN_SEL(HPPASS_BASE) = CY_HPPASS_DEINIT;
    HPPASS_INFRA_HW_TR_MODE(HPPASS_BASE) = CY_HPPASS_DEINIT;
    HPPASS_MMIO_TR_LEVEL_CFG(HPPASS_BASE) = CY_HPPASS_DEINIT;
    HPPASS_INFRA_FW_TR_LEVEL(HPPASS_BASE) = CY_HPPASS_DEINIT;
    HPPASS_INFRA_FW_TR_PULSE(HPPASS_BASE) = CY_HPPASS_DEINIT;
    HPPASS_MMIO_INTR(HPPASS_BASE) = CY_HPPASS_INTR;
    HPPASS_MMIO_INTR_MASK(HPPASS_BASE) = CY_HPPASS_DEINIT;

    for (uint8_t i = 0U; i < CY_HPPASS_TRIG_NUM; i++)
    {
        HPPASS_MMIO_TR_LEVEL_OUT(HPPASS_BASE, i) = CY_HPPASS_DEINIT;
        HPPASS_MMIO_TR_PULSE_OUT(HPPASS_BASE, i) = CY_HPPASS_DEINIT;
    }

    for (uint8_t i = 0U; i < CY_HPPASS_AC_STT_SIZE; i++)
    {
        HPPASS_AC_TT_CFG0(HPPASS_BASE, i) = CY_HPPASS_DEINIT;
        HPPASS_AC_TT_CFG1(HPPASS_BASE, i) = CY_HPPASS_DEINIT;
        HPPASS_AC_TT_CFG2(HPPASS_BASE, i) = CY_HPPASS_DEINIT;
        HPPASS_AC_TT_CFG3(HPPASS_BASE, i) = CY_HPPASS_DEINIT;
    }
}


cy_en_syspm_status_t Cy_HPPASS_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode)
{
    (void)callbackParams;

    cy_en_syspm_status_t ret = CY_SYSPM_SUCCESS;

    switch (mode)
    {
        case CY_SYSPM_CHECK_READY:
        {
            if (Cy_HPPASS_AC_IsRunning() || Cy_HPPASS_SAR_IsBusy())
            {
                ret = CY_SYSPM_FAIL;
            }
        }
        break;

        case CY_SYSPM_CHECK_FAIL:
        break;

        case CY_SYSPM_BEFORE_TRANSITION:
        {
            /* Save the SAR ADC calibration values */
            calVal.caloffst_0 = HPPASS_SAR_CALOFFST(HPPASS_BASE, 0U);
            calVal.caloffst_1 = HPPASS_SAR_CALOFFST(HPPASS_BASE, 1U);
            calVal.caloffst_2 = HPPASS_SAR_CALOFFST(HPPASS_BASE, 2U);
            calVal.caloffst_3 = HPPASS_SAR_CALOFFST(HPPASS_BASE, 3U);
            calVal.calgainc = HPPASS_SAR_CALGAINC(HPPASS_BASE);
            calVal.calgainf = HPPASS_SAR_CALGAINF(HPPASS_BASE);

            for (uint8_t i = 0U; i < CY_HPPASS_SAR_CAL_LIN_TABLE_SIZE; i++)
            {
                calVal.callin[i] = HPPASS_SAR_CALLIN(HPPASS_BASE, i);
            }
        }
        break;

        case CY_SYSPM_AFTER_TRANSITION:
        {
            /* Restore the SAR ADC calibration values */
            HPPASS_SAR_CALOFFST(HPPASS_BASE, 0U) = calVal.caloffst_0;
            HPPASS_SAR_CALOFFST(HPPASS_BASE, 1U) = calVal.caloffst_1;
            HPPASS_SAR_CALOFFST(HPPASS_BASE, 2U) = calVal.caloffst_2;
            HPPASS_SAR_CALOFFST(HPPASS_BASE, 3U) = calVal.caloffst_3;
            HPPASS_SAR_CALGAINC(HPPASS_BASE) = calVal.calgainc;
            HPPASS_SAR_CALGAINF(HPPASS_BASE) = calVal.calgainf;

            for (uint8_t i = 0U; i < CY_HPPASS_SAR_CAL_LIN_TABLE_SIZE; i++)
            {
                HPPASS_SAR_CALLIN(HPPASS_BASE, i) = calVal.callin[i];
            }
        }
        break;

        default:
        ret = CY_SYSPM_FAIL;
        break;
    }

    return ret;
}


cy_en_hppass_status_t Cy_HPPASS_SetFwTrigger(uint8_t mask)
{
    cy_en_hppass_status_t result = CY_HPPASS_SUCCESS;
    uint32_t trInSel = HPPASS_INFRA_TR_IN_SEL(HPPASS_BASE);
    uint8_t fwTrLevel = (uint8_t)0U;
    uint8_t fwTrPulse = (uint8_t)0U;

    for (uint8_t i = 0U; i < CY_HPPASS_TRIG_NUM; i++)
    {
        uint8_t locMask = 1U << i; /* Local trig bit mask */

        if (0U != (locMask & mask))
        {
            uint32_t trSel = (trInSel >> CY_HPPASS_TRIG_IN_BIT_POS(i)) & HPPASS_INFRA_TR_IN_SEL_TR0_SEL_Msk;

            if (((uint32_t)CY_HPPASS_TR_FW_PULSE != trSel) && ((uint32_t)CY_HPPASS_TR_FW_LEVEL != trSel))
            {
                result = CY_HPPASS_BAD_PARAM;
                break;
            }

            if ((uint32_t)CY_HPPASS_TR_FW_LEVEL == trSel)
            {
                fwTrLevel |= locMask;
            }
            else
            {
                fwTrPulse |= locMask;
            }
        }
    }

    if (CY_HPPASS_SUCCESS == result)
    {
        Cy_HPPASS_SetFwTriggerLevel(fwTrLevel);
        Cy_HPPASS_SetFwTriggerPulse(fwTrPulse);
    }

    return result;
}


cy_en_hppass_status_t Cy_HPPASS_ClearFwTrigger(uint8_t mask)
{
    cy_en_hppass_status_t result = CY_HPPASS_SUCCESS;
    uint32_t trInSel = HPPASS_INFRA_TR_IN_SEL(HPPASS_BASE);

    for (uint8_t i = 0U; i < CY_HPPASS_TRIG_NUM; i++)
    {
        if (0U != ((1U << i) & mask))
        {
            uint32_t trSel = (trInSel >> CY_HPPASS_TRIG_IN_BIT_POS(i)) & HPPASS_INFRA_TR_IN_SEL_TR0_SEL_Msk;

            if ((uint32_t)CY_HPPASS_TR_FW_LEVEL != trSel)
            {
                result = CY_HPPASS_BAD_PARAM;
                break;
            }
        }
    }

    if (CY_HPPASS_SUCCESS == result)
    {
        Cy_HPPASS_ClearFwTriggerLevel(mask);
    }

    return result;
}

#endif /* CY_IP_MXS40MCPASS */

/* [] END OF FILE */
