/***************************************************************************//**
* \file cy_hppass_sar.c
* \version 1.20
*
* \brief
* Provides the public functions for the SAR subsystem of the High Power Peripheral Analog Sub-System.
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
#include "cy_hppass_sar.h"

#ifdef CY_IP_MXS40MCPASS

#define CY_HPPASS_SUPPRESS_AC_RUN_CHECK
#define CY_HPPASS_SUPPRESS_ADC_BUSY_CHECK

/* De-Init defines */
#define CY_HPPASS_SAR_DEINIT                (0UL)           /* De-init value for most SAR registers */
#define CY_HPPASS_SAR_RESULT_DEINIT         (0xCFFFFFFFUL)  /* De-init value for Result registers */
#define CY_HPPASS_SAR_GROUP_HOLD_CNT_DEINIT (29UL)          /* De-init value for Group Hold Cnt register */
#define CY_HPPASS_SAR_AROUTE_FW_CTRL_DEINIT (0xFFFFUL)      /* De-init value for AROUT FW Ctrl register */
#define CY_HPPASS_SAR_SAMPLE_TIME_DEINIT    (31UL)          /* De-init value for Sample Time register */

#define CY_HPPASS_SAMP_GAIN_WIDTH           (2U)                /* The sampler gain width */
#define CY_HPPASS_SAR_MAX                   (4096U)             /* The ADC resolution*/
#define CY_HPPASS_DIFGAIN(DIF)              ((DIF) ? 2U : 1U)   /* The mode dependent gain value */

#if ((CY_IP_MXS40MCPASS_VERSION == 1u) && (CY_IP_MXS40MCPASS_VERSION_MINOR == 0u))
/* The HPPASS_SAR_CALOFFST mirror */
static uint32_t calOffsetMirror[4] = {0UL, 0UL, 0UL, 0UL};
#endif
static const uint8_t cy_hppass_sampgain_table[] = {1U, 3U, 6U, 12U};    /* The look up table to define sampler gain value based on its index */


/** \cond Macros for conditions used by CY_ASSERT calls */
#define CY_HPPASS_MUXMODE_VALID(muxMode)            ((CY_HPPASS_SAR_MUX_SEQ == (muxMode)) || \
                                                     (CY_HPPASS_SAR_MUX_FW  == (muxMode)) || \
                                                     (CY_HPPASS_SAR_MUX_AC  == (muxMode)))

#define CY_HPPASS_SARVREF_VALID(vref)               ((CY_HPPASS_SAR_VREF_VDDA == (vref)) || \
                                                     (CY_HPPASS_SAR_VREF_EXT  == (vref)))

#define CY_HPPASS_DIRSAMP_VALUE_VALID(dirSampEnMsk) (0U == ((dirSampEnMsk) & ((uint16_t) ~(CY_HPPASS_SAR_DIRECT_SAMP_0 | \
                                                                                           CY_HPPASS_SAR_DIRECT_SAMP_1 | \
                                                                                           CY_HPPASS_SAR_DIRECT_SAMP_2 | \
                                                                                           CY_HPPASS_SAR_DIRECT_SAMP_3 | \
                                                                                           CY_HPPASS_SAR_DIRECT_SAMP_4 | \
                                                                                           CY_HPPASS_SAR_DIRECT_SAMP_5 | \
                                                                                           CY_HPPASS_SAR_DIRECT_SAMP_6 | \
                                                                                           CY_HPPASS_SAR_DIRECT_SAMP_7 | \
                                                                                           CY_HPPASS_SAR_DIRECT_SAMP_8 | \
                                                                                           CY_HPPASS_SAR_DIRECT_SAMP_9 | \
                                                                                           CY_HPPASS_SAR_DIRECT_SAMP_10 | \
                                                                                           CY_HPPASS_SAR_DIRECT_SAMP_11))))

#define CY_HPPASS_MUXSAMP_VALUE_VALID(muxSampEnMsk) (0U == ((muxSampEnMsk) & ((uint8_t) ~(CY_HPPASS_SAR_MUXED_SAMP_0 | \
                                                                                          CY_HPPASS_SAR_MUXED_SAMP_1 | \
                                                                                          CY_HPPASS_SAR_MUXED_SAMP_2 | \
                                                                                          CY_HPPASS_SAR_MUXED_SAMP_3))))

#define CY_HPPASS_SAR_SAMPLE_TIME_VALID(sampTime)   ((0U < (sampTime)) && (1024U >= (sampTime)))
/** \endcond */


cy_en_hppass_status_t Cy_HPPASS_SAR_Init(const cy_stc_hppass_sar_t * sarCfg)
{
    cy_en_hppass_status_t result = CY_HPPASS_SUCCESS;

    if (NULL == sarCfg)
    {
        result = CY_HPPASS_SAR_BAD_PARAM;
    }
    else if (Cy_HPPASS_AC_IsRunning())
    {
        result = CY_HPPASS_AC_INVALID_STATE;
    }
    else if (Cy_HPPASS_SAR_IsBusy())
    {
        result = CY_HPPASS_SAR_INVALID_STATE;
    }
    else
    {
        /* Copy SAR ADC calibration default values from SFLASH */
        HPPASS_SAR_CALOFFST(HPPASS_BASE, 0U) = SFLASH_SAR_CALOFFST_0_25C;
        HPPASS_SAR_CALOFFST(HPPASS_BASE, 1U) = SFLASH_SAR_CALOFFST_1_25C;
        HPPASS_SAR_CALOFFST(HPPASS_BASE, 2U) = SFLASH_SAR_CALOFFST_2_25C;
        HPPASS_SAR_CALOFFST(HPPASS_BASE, 3U) = SFLASH_SAR_CALOFFST_3_25C;
        HPPASS_SAR_CALGAINC(HPPASS_BASE) = SFLASH_SAR_CALGAINC;
        HPPASS_SAR_CALGAINF(HPPASS_BASE) = SFLASH_SAR_CALGAINF;

#if ((CY_IP_MXS40MCPASS_VERSION == 1u) && (CY_IP_MXS40MCPASS_VERSION_MINOR == 0u))
        calOffsetMirror[0] = HPPASS_SAR_CALOFFST(HPPASS_BASE, 0U);
        calOffsetMirror[1] = HPPASS_SAR_CALOFFST(HPPASS_BASE, 1U);
        calOffsetMirror[2] = HPPASS_SAR_CALOFFST(HPPASS_BASE, 2U);
        calOffsetMirror[3] = HPPASS_SAR_CALOFFST(HPPASS_BASE, 3U);
#endif

        bool error = false;
        uint32_t dirSampGain = 0UL;
        uint32_t muxSampGain = 0UL;

        CY_ASSERT_L3(CY_HPPASS_MUXMODE_VALID(sarCfg->muxMode[0U]));
        CY_ASSERT_L3(CY_HPPASS_MUXMODE_VALID(sarCfg->muxMode[1U]));
        CY_ASSERT_L3(CY_HPPASS_MUXMODE_VALID(sarCfg->muxMode[2U]));
        CY_ASSERT_L3(CY_HPPASS_MUXMODE_VALID(sarCfg->muxMode[3U]));

        uint32_t muxModeVal = _VAL2FLD(HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX0_CTRL, sarCfg->muxMode[0U]) |
                              _VAL2FLD(HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX1_CTRL, sarCfg->muxMode[1U]) |
                              _VAL2FLD(HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX2_CTRL, sarCfg->muxMode[2U]) |
                              _VAL2FLD(HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX3_CTRL, sarCfg->muxMode[3U]);

        uint32_t muxMode_Pos = HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX0_CTRL_Pos;
        uint32_t muxMode_Msk = HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX0_CTRL_Msk |
                               HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX1_CTRL_Msk |
                               HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX2_CTRL_Msk |
                               HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX3_CTRL_Msk;

        CY_REG32_CLR_SET(HPPASS_SAR_AROUTE_CTRL_MODE(HPPASS_BASE), muxMode, muxModeVal);

        CY_REG32_CLR_SET(HPPASS_SAR_AROUTE_CTRL_MODE(HPPASS_BASE), HPPASS_SAR_CFG_AROUTE_CTRL_MODE_AROUTE_ENABLED,
                                                                   CY_HPPASS_BOOL_TO_UINT(sarCfg->aroute));
        CY_ASSERT_L3(CY_HPPASS_SARVREF_VALID(sarCfg->vref));

        HPPASS_SAR_CTRL(HPPASS_BASE) = _VAL2FLD(HPPASS_SAR_CFG_CTRL_VREF_SEL, sarCfg->vref) |
                                       _VAL2FLD(HPPASS_SAR_CFG_CTRL_LOW_SUPPLY_MODE, CY_HPPASS_BOOL_TO_UINT(sarCfg->lowSupply)) |
                                       _VAL2FLD(HPPASS_SAR_CFG_CTRL_STARTUP_CAL_OFFSET_EN, CY_HPPASS_BOOL_TO_UINT(sarCfg->offsetCal)) |
                                       _VAL2FLD(HPPASS_SAR_CFG_CTRL_STARTUP_CAL_LINEARITY_EN, CY_HPPASS_BOOL_TO_UINT(sarCfg->linearCal)) |
                                       _VAL2FLD(HPPASS_SAR_CFG_CTRL_STARTUP_CAL_GAIN_EN, CY_HPPASS_BOOL_TO_UINT(sarCfg->gainCal)) |
                                       _VAL2FLD(HPPASS_SAR_CFG_CTRL_CHAN_ID_EN, CY_HPPASS_BOOL_TO_UINT(sarCfg->chanId));

        for (uint8_t i = 0U; i < CY_HPPASS_SAR_DIR_SAMP_NUM; i++)
        {
            dirSampGain |= (uint32_t)sarCfg->dirSampGain[i] << (i * CY_HPPASS_SAMP_GAIN_WIDTH);
        }

        for (uint8_t i = 0U; i < CY_HPPASS_SAR_MUX_SAMP_NUM; i++)
        {
            muxSampGain |= (uint32_t)sarCfg->muxSampGain[i] << (i * CY_HPPASS_SAMP_GAIN_WIDTH);
        }

        HPPASS_SAR_SAMP_GAIN(HPPASS_BASE) = dirSampGain | (muxSampGain << (CY_HPPASS_SAR_DIR_SAMP_NUM * CY_HPPASS_SAMP_GAIN_WIDTH));

        CY_ASSERT_L2(CY_HPPASS_DIRSAMP_VALUE_VALID(sarCfg->dirSampEnMsk));
        CY_ASSERT_L2(CY_HPPASS_MUXSAMP_VALUE_VALID(sarCfg->muxSampEnMsk));

        HPPASS_SAR_SAMP_EN(HPPASS_BASE) = _VAL2FLD(HPPASS_SAR_CFG_SAMP_EN_DIRECT_SAMP_EN, sarCfg->dirSampEnMsk) |
                                          _VAL2FLD(HPPASS_SAR_CFG_SAMP_EN_MUXED_SAMP_EN, sarCfg->muxSampEnMsk);

        Cy_HPPASS_SAR_SetHoldViolationCnt(sarCfg->holdCount);

        for (uint8_t i = 0U; i < CY_HPPASS_SAR_SAMP_TIME_NUM; i++)
        {
            CY_ASSERT_L2(CY_HPPASS_SAR_SAMPLE_TIME_VALID(sarCfg->sampTime[i]));

            HPPASS_SAR_SAMPLE_TIME(HPPASS_BASE, i) = _VAL2FLD(HPPASS_SAR_CFG_SAMPLE_TIME_SAMPLE_TIME, (uint32_t)sarCfg->sampTime[i] - 1UL);
        }

        /* Channel result mask register is set by default. It needs to be cleared and set only required channels. */
        HPPASS_SAR_RESULT_MASK(HPPASS_BASE) = 0UL;

        for (uint8_t i = 0U; i < CY_HPPASS_SAR_CHAN_NUM; i++)
        {
            if (NULL != sarCfg->chan[i])
            {
                if (CY_HPPASS_SUCCESS != Cy_HPPASS_SAR_ChannelConfig(i, sarCfg->chan[i]))
                {
                    error = true;
                }
            }
        }

        for (uint8_t i = 0U; i < CY_HPPASS_SAR_GRP_NUM; i++)
        {
            if (NULL != sarCfg->grp[i])
            {
                if (CY_HPPASS_SUCCESS != Cy_HPPASS_SAR_GroupConfig(i, sarCfg->grp[i]))
                {
                    error = true;
                }
            }
        }

        for (uint8_t i = 0U; i < CY_HPPASS_SAR_LIMIT_NUM; i++)
        {
            if (NULL != sarCfg->limit[i])
            {
                if (CY_HPPASS_SUCCESS != Cy_HPPASS_SAR_Limit_Config(i, sarCfg->limit[i]))
                {
                    error = true;
                }
            }
        }

        for (uint8_t i = 0U; i < CY_HPPASS_FIR_NUM; i++)
        {
            if (NULL != sarCfg->fir[i])
            {
                if (CY_HPPASS_SUCCESS != Cy_HPPASS_SAR_FirConfig(i, sarCfg->fir[i]))
                {
                    error = true;
                }
            }
        }

        if (NULL != sarCfg->fifo)
        {
            if (CY_HPPASS_SUCCESS != Cy_HPPASS_FIFO_Config(sarCfg->fifo))
            {
                error = true;
            }
        }

        if (error)
        {
            result = CY_HPPASS_SAR_BAD_PARAM;
        }
    }

    return result;
}


void Cy_HPPASS_SAR_DeInit(void)
{
    HPPASS_SAR_CTRL(HPPASS_BASE) = CY_HPPASS_SAR_DEINIT;
    HPPASS_SAR_AROUTE_CTRL_MODE(HPPASS_BASE) = HPPASS_SAR_CFG_AROUTE_CTRL_MODE_TEMPSENSE_ENABLED_Msk |
                                               HPPASS_SAR_CFG_AROUTE_CTRL_MODE_AROUTE_ENABLED_Msk;
    HPPASS_SAR_SAMP_GAIN(HPPASS_BASE) = CY_HPPASS_SAR_DEINIT;
    HPPASS_SAR_SAMP_EN(HPPASS_BASE) = CY_HPPASS_SAR_DEINIT;
    HPPASS_SAR_GROUP_HOLD_CNT(HPPASS_BASE) = CY_HPPASS_SAR_GROUP_HOLD_CNT_DEINIT;

    HPPASS_SAR_RESULT_MASK(HPPASS_BASE) = CY_HPPASS_SAR_RESULT_DEINIT;
    HPPASS_SAR_RESULT_STATUS(HPPASS_BASE) = CY_HPPASS_SAR_RESULT_DEINIT;
    HPPASS_SAR_LIMIT_STATUS(HPPASS_BASE) = CY_HPPASS_SAR_CHAN_MSK;
    HPPASS_SAR_RESULT_OVERFLOW(HPPASS_BASE) = CY_HPPASS_INTR_SAR_RESULT;
    HPPASS_SAR_GROUP_TR_COLLISION(HPPASS_BASE) = HPPASS_SAR_CFG_ENTRY_TR_COLLISION_ENTRY_COL_Msk;
    HPPASS_SAR_GROUP_HOLD_VIOLATION(HPPASS_BASE) = HPPASS_SAR_CFG_ENTRY_HOLD_VIOLATION_HOLD_VIOL_Msk;
    HPPASS_SAR_RESULT_INTR(HPPASS_BASE) = CY_HPPASS_INTR_SAR_RESULT;
    HPPASS_SAR_RESULT_INTR_SET(HPPASS_BASE) = CY_HPPASS_SAR_DEINIT;
    HPPASS_SAR_RESULT_INTR_MASK(HPPASS_BASE) = CY_HPPASS_SAR_DEINIT;
    HPPASS_SAR_LIMIT_INTR(HPPASS_BASE) = CY_HPPASS_INTR_SAR_LIMIT;
    HPPASS_SAR_LIMIT_INTR_SET(HPPASS_BASE) = CY_HPPASS_SAR_DEINIT;
    HPPASS_SAR_LIMIT_INTR_MASK(HPPASS_BASE) = CY_HPPASS_SAR_DEINIT;
    HPPASS_SAR_AROUTE_FW_CTRL_CLR(HPPASS_BASE) = CY_HPPASS_SAR_AROUTE_FW_CTRL_DEINIT;
    HPPASS_SAR_TEMPSENSE_CTRL(HPPASS_BASE) = CY_HPPASS_SAR_DEINIT;
    HPPASS_MMIO_FIFO_CFG(HPPASS_BASE) = CY_HPPASS_SAR_DEINIT;

    for (uint8_t i = 0U; i < CY_HPPASS_SAR_GRP_NUM; i++)
    {
        HPPASS_SAR_SEQ_GROUP(HPPASS_BASE, i) = CY_HPPASS_SAR_DEINIT;
    }

    for (uint8_t i = 0U; i < CY_HPPASS_SAR_SAMP_TIME_NUM; i++)
    {
        HPPASS_SAR_SAMPLE_TIME(HPPASS_BASE, i) = CY_HPPASS_SAR_SAMPLE_TIME_DEINIT;
    }

    for (uint8_t i = 0U; i < CY_HPPASS_FIR_NUM; i++)
    {
        HPPASS_SAR_FIR_CFG(HPPASS_BASE, i) = HPPASS_SAR_CFG_FIR_CFG_WAIT_TAP_INIT_Msk;
    }

    for (uint8_t i = 0U; i < CY_HPPASS_SAR_CHAN_NUM; i++)
    {
        HPPASS_SAR_CHAN_CFG(HPPASS_BASE, i) = CY_HPPASS_SAR_DEINIT;
    }

    for (uint8_t i = 0U; i < CY_HPPASS_SAR_LIMIT_NUM; i++)
    {
        HPPASS_SAR_LIMIT_CFG(HPPASS_BASE, i) = CY_HPPASS_SAR_DEINIT;
        HPPASS_SAR_LIMIT_LOW(HPPASS_BASE, i) = CY_HPPASS_SAR_DEINIT;
        HPPASS_SAR_LIMIT_HIGH(HPPASS_BASE, i) = CY_HPPASS_SAR_DEINIT;
    }

    for (uint8_t i = 0U; i < CY_HPPASS_FIR_TAP_NUM; i++)
    {
        HPPASS_SAR_FIR_COEFS(HPPASS_BASE, 0UL, i) = CY_HPPASS_SAR_DEINIT;
        HPPASS_SAR_FIR_COEFS(HPPASS_BASE, 1UL, i) = CY_HPPASS_SAR_DEINIT;
    }

    for (uint8_t i = 0U; i < CY_HPPASS_FIFO_NUM; i++)
    {
        HPPASS_MMIO_FIFO_LEVEL(HPPASS_BASE, i) = CY_HPPASS_SAR_DEINIT;
    }
}


uint8_t Cy_HPPASS_FIFO_ReadAll(uint8_t fifoIdx, int16_t * data, uint8_t * chanIdxs)
{
    uint8_t retVal = 0U;

    if (NULL != data)
    {
        retVal = Cy_HPPASS_FIFO_GetSampleCount(fifoIdx);

        for (uint8_t i = 0U; i < retVal; i++)
        {
            data[i] = Cy_HPPASS_FIFO_Read(fifoIdx, chanIdxs);

            if (NULL != chanIdxs)
            {
                chanIdxs++; /* Pointer arithmetic */
            }
        }
    }

    return (retVal);
}


static uint32_t Cy_HPPASS_SAR_Offset_Calc(float temp, float ref, uint32_t caloffsetN40, uint32_t caloffset125)
{
    uint32_t offsetN40 = _FLD2VAL(HPPASS_SARADC_CALOFFST_OFFSET_4N_0, caloffsetN40);
    uint32_t offset125 = _FLD2VAL(HPPASS_SARADC_CALOFFST_OFFSET_4N_0, caloffset125);
    float offsetFloat = ref * ((float)offsetN40 + ((float)offset125 - (float)offsetN40) * temp);
    uint32_t offset = _VAL2FLD(HPPASS_SARADC_CALOFFST_OFFSET_4N_0, offsetFloat);

    offsetN40 = _FLD2VAL(HPPASS_SARADC_CALOFFST_OFFSET_4N_1, caloffsetN40);
    offset125 = _FLD2VAL(HPPASS_SARADC_CALOFFST_OFFSET_4N_1, caloffset125);
    offsetFloat = ref * ((float)offsetN40 + ((float)offset125 - (float)offsetN40) * temp);
    offset |= _VAL2FLD(HPPASS_SARADC_CALOFFST_OFFSET_4N_1, offsetFloat);

    offsetN40 = _FLD2VAL(HPPASS_SARADC_CALOFFST_OFFSET_4N_2, caloffsetN40);
    offset125 = _FLD2VAL(HPPASS_SARADC_CALOFFST_OFFSET_4N_2, caloffset125);
    offsetFloat = ref * ((float)offsetN40 + ((float)offset125 - (float)offsetN40) * temp);
    offset |= _VAL2FLD(HPPASS_SARADC_CALOFFST_OFFSET_4N_2, offsetFloat);

    offsetN40 = _FLD2VAL(HPPASS_SARADC_CALOFFST_OFFSET_4N_3, caloffsetN40);
    offset125 = _FLD2VAL(HPPASS_SARADC_CALOFFST_OFFSET_4N_3, caloffset125);
    offsetFloat = ref * ((float)offsetN40 + ((float)offset125 - (float)offsetN40) * temp);
    offset |= _VAL2FLD(HPPASS_SARADC_CALOFFST_OFFSET_4N_3, offsetFloat);

    return offset;
}


void Cy_HPPASS_SAR_TempAdjust(int16_t temp, uint16_t vRef)
{
    CY_ASSERT_L2(CY_HPPASS_SAR_TEMP_VALID(temp));
    CY_ASSERT_L2(CY_HPPASS_SAR_VREF_VALID(vRef));

    float refLoc = ((float)SFLASH_SAR_CALREFPT / 65536.0f) / ((float)vRef / 1000.0f);
    float tempLoc = ((float)temp + 40.0f) / 165.0f;

    HPPASS_SAR_CALOFFST(HPPASS_BASE, 0UL) = Cy_HPPASS_SAR_Offset_Calc(tempLoc, refLoc,
                                            SFLASH_SAR_CALOFFST_0_N40C, SFLASH_SAR_CALOFFST_0_125C);
    HPPASS_SAR_CALOFFST(HPPASS_BASE, 1UL) = Cy_HPPASS_SAR_Offset_Calc(tempLoc, refLoc,
                                            SFLASH_SAR_CALOFFST_1_N40C, SFLASH_SAR_CALOFFST_1_125C);
    HPPASS_SAR_CALOFFST(HPPASS_BASE, 2UL) = Cy_HPPASS_SAR_Offset_Calc(tempLoc, refLoc,
                                            SFLASH_SAR_CALOFFST_2_N40C, SFLASH_SAR_CALOFFST_2_125C);
    HPPASS_SAR_CALOFFST(HPPASS_BASE, 3UL) = Cy_HPPASS_SAR_Offset_Calc(tempLoc, refLoc,
                                            SFLASH_SAR_CALOFFST_3_N40C, SFLASH_SAR_CALOFFST_3_125C);

#if ((CY_IP_MXS40MCPASS_VERSION == 1u) && (CY_IP_MXS40MCPASS_VERSION_MINOR == 0u))
    calOffsetMirror[0] = HPPASS_SAR_CALOFFST(HPPASS_BASE, 0U);
    calOffsetMirror[1] = HPPASS_SAR_CALOFFST(HPPASS_BASE, 1U);
    calOffsetMirror[2] = HPPASS_SAR_CALOFFST(HPPASS_BASE, 2U);
    calOffsetMirror[3] = HPPASS_SAR_CALOFFST(HPPASS_BASE, 3U);
#endif
}

#if ((CY_IP_MXS40MCPASS_VERSION == 1u) && (CY_IP_MXS40MCPASS_VERSION_MINOR == 0u))

#define CY_HPPASS_SAR_GROUP_SAMPLER_EN_Pos (HPPASS_SAR_SEQ_ENTRY_DIRECT_SAMPLER_EN_Pos)
#define CY_HPPASS_SAR_GROUP_SAMPLER_EN_Msk (HPPASS_SAR_SEQ_ENTRY_DIRECT_SAMPLER_EN_Msk | HPPASS_SAR_SEQ_ENTRY_MUXED_SAMPLER_EN_Msk)
#define CY_HPPASS_SAR_SAMP_NUM             (CY_HPPASS_SAR_DIR_SAMP_NUM + CY_HPPASS_SAR_MUX_SAMP_NUM)
#define CY_HPPASS_SAR_CALOFFST_REG_NUM     (4U)
#define CY_HPPASS_SAR_CALOFFST_FLD_NUM     (CY_HPPASS_SAR_SAMP_NUM / CY_HPPASS_SAR_CALOFFST_REG_NUM)
#define CY_HPPASS_SAR_CALOFFST_SIGN_Msk    (0x40U)
#define CY_HPPASS_SAR_CALOFFST_FLD_Msk     (0x7FUL)
#define CY_HPPASS_SAR_CALOFFST_FLD_Pos     (8UL)
#define CY_HPPASS_SAR_CALOFFST_N128        (0xFF80U)

/* The compensation factor table */
CY_ALIGN(32)
static float32_t const cy_sar_samp_comp_tbl[CY_HPPASS_SAR_SAMP_NUM] =
{
    1.3f, 1.2f, 1.1f, 1.0f, 0.8f, 0.8f, 0.8f, 0.9f, 1.3f, 1.4f, 1.3f, 1.3f, 1.0f, 1.0f, 1.0f, 1.0f
};

void Cy_HPPASS_SAR_CrossTalkAdjust (uint8_t groupMsk)
{
    uint16_t sampMsk = 0U;
    uint16_t sampNum = 0U;

    {
        uint8_t i = 0U;
        while (0U != groupMsk)
        {
            if(0U != (groupMsk & 1U))
            {
                sampMsk |= (uint16_t)_FLD2VAL(CY_HPPASS_SAR_GROUP_SAMPLER_EN, HPPASS_SAR_SEQ_GROUP(HPPASS_BASE, i));
            }
            groupMsk >>= 1U;
            i++;
        }
    }

    CY_ASSERT_L2(0U != sampMsk);
    {
        uint16_t mask = sampMsk;
        while (0U != mask)
        {
            sampNum += (uint16_t)(mask & 1U);
            mask >>= 1U;
        }
    }

    if(4U < sampNum)
    {
        for (uint8_t i = 0U; i < CY_HPPASS_SAR_CALOFFST_REG_NUM; i++)
        {
            /* Read existing offset value found during runtime calibration */
            uint32_t caloffstReg = calOffsetMirror[i];

            for (uint8_t j = 0U; j < CY_HPPASS_SAR_CALOFFST_FLD_NUM; j++)
            {
                uint16_t sampCtr = (uint16_t)i * CY_HPPASS_SAR_CALOFFST_FLD_NUM + (uint16_t)j;
                bool isSamplerEnabled = (0U != ((sampMsk >> sampCtr) & 1U));
                if (isSamplerEnabled)
                {
                    uint32_t bitfieldOffset = (uint32_t)j * CY_HPPASS_SAR_CALOFFST_FLD_Pos;

                    /* Calculate the needed additional offset compensation based on number of aggressor channels */
                    uint16_t    caloffstVal   = (uint16_t)((caloffstReg >> bitfieldOffset) & CY_HPPASS_SAR_CALOFFST_FLD_Msk);
                    uint16_t    caloffstSign  = CY_HPPASS_SAR_CALOFFST_N128 ^ caloffstVal;
                    int32_t     caloffst      = (0U == (caloffstVal & CY_HPPASS_SAR_CALOFFST_SIGN_Msk)) ? (int32_t)caloffstVal : (int32_t)(int16_t)caloffstSign;
                    float32_t   compVal       = cy_sar_samp_comp_tbl[sampCtr] * ((float32_t)(int16_t)sampNum - 1.0f) + 0.5f; /* Round Half Up rounding strategy */
                    int32_t     caloffstNew   = caloffst + (int32_t)compVal;

                    /* Write the updated offset calibration value into the corresponding bitfield */
                    /* After this step, all results received on the sampler are Cross Talk - compensated for the particular amount of aggressors */
                    caloffstReg &= ~(CY_HPPASS_SAR_CALOFFST_FLD_Msk << bitfieldOffset);
                    caloffstReg |= ((uint32_t)caloffstNew & CY_HPPASS_SAR_CALOFFST_FLD_Msk) << bitfieldOffset;
                }
            }
            HPPASS_SAR_CALOFFST(HPPASS_BASE, i) = caloffstReg;
        }
    }
}
#endif


typedef struct
{
    uint8_t   idx;
    uint32_t  gain;
    int32_t   offset;
    uint16_t  avg;
    bool      sign;
    bool      diff;
} chan_config_t;

static void getChanConfig(chan_config_t* cfg)
{
    #define MUX_SAMP_WIDTH  (4U)
    #define SAMPGAIN_MASK   (3UL)
    uint8_t  sampIdx = (CY_HPPASS_SAR_DIR_SAMP_NUM > (uint16_t)cfg->idx) ? cfg->idx : (((cfg->idx - CY_HPPASS_SAR_DIR_SAMP_NUM) / MUX_SAMP_WIDTH) + CY_HPPASS_SAR_DIR_SAMP_NUM);
    uint32_t sampGain_Pos = CY_HPPASS_SAMP_GAIN_WIDTH * (uint32_t)sampIdx;
    uint32_t sampGain_Msk = SAMPGAIN_MASK << sampGain_Pos;

    cfg->avg  = (uint16_t)_FLD2VAL(HPPASS_SAR_CFG_CHAN_CFG_AVG_SEL, HPPASS_SAR_CHAN_CFG(HPPASS_BASE, cfg->idx));
    cfg->sign = _FLD2BOOL(HPPASS_SAR_CFG_CHAN_CFG_SIGNED,          HPPASS_SAR_CHAN_CFG(HPPASS_BASE, cfg->idx));
    cfg->diff = _FLD2BOOL(HPPASS_SAR_CFG_CHAN_CFG_DIFFERENTIAL_EN, HPPASS_SAR_CHAN_CFG(HPPASS_BASE, cfg->idx));

    cfg->gain = cy_hppass_sampgain_table[_FLD2VAL(sampGain, HPPASS_SAR_SAMP_GAIN(HPPASS))];

    /* Calculate the offset for the SAR ADC channel */
    if (!cfg->sign && cfg->diff)
    {
        cfg->offset = -0x800L; /* avg is not used with diff */
    }
    else if (cfg->sign && !cfg->diff)
    {
        cfg->offset = 0x800L * (int32_t)(uint16_t)(1UL << cfg->avg);
    }
    else
    {
        cfg->offset = 0;
    }
}


float32_t Cy_HPPASS_SAR_CountsTo_Volts(uint8_t chanIdx, uint16_t vRef, int16_t chanCounts)
{
    float32_t volts = 0.0f;

    if (CY_HPPASS_SAR_CHAN_NUM_VALID(chanIdx) && CY_HPPASS_SAR_VREF_VALID(vRef))
    {
        chan_config_t cfg;

        cfg.idx = chanIdx;
        getChanConfig(&cfg);

        /* Calculate the SAR ADC result in V */
        if (!cfg.sign && !cfg.diff)
        {
            volts = (((float32_t)(uint16_t)chanCounts + (float32_t)cfg.offset) * (float32_t)vRef * 1E-3F) /
                    ((float32_t)CY_HPPASS_SAR_MAX * (float32_t)(uint16_t)(cfg.gain << cfg.avg));
        }
        else /* sign OR diff */
        {
            volts = (((float32_t)chanCounts + (float32_t)cfg.offset) * (float32_t)vRef * (float32_t)CY_HPPASS_DIFGAIN(cfg.diff) * 1E-3F) /
                    ((float32_t)CY_HPPASS_SAR_MAX * (float32_t)(uint16_t)(cfg.gain << cfg.avg));
        }
    }
    else
    {
        CY_ASSERT_L1(false); /* The chanIdx or vRef parameter is invalid */
    }

    return volts;
}

#define CY_HPPASS_DIV_ROUND(a, b) (((a) < 0) ? (((a) - ((b) / 2)) / (b)) : (((a) + ((b) / 2)) / (b)))

int16_t Cy_HPPASS_SAR_CountsTo_mVolts(uint8_t chanIdx, uint16_t vRef, int16_t chanCounts)
{
    int16_t mVolts = 0;

    if (CY_HPPASS_SAR_CHAN_NUM_VALID(chanIdx) && CY_HPPASS_SAR_VREF_VALID(vRef))
    {
        int32_t   num     = 0L;
        int32_t   denom   = 1L;
        chan_config_t cfg;

        cfg.idx = chanIdx;
        getChanConfig(&cfg);

        /* Calculate the SAR ADC result in mV */
        if (!cfg.sign && !cfg.diff)
        {
            num = (((int32_t)(uint16_t)chanCounts + cfg.offset) * (int32_t)vRef);
        }
        else /* sign OR diff */
        {
            num = (((int32_t)chanCounts + cfg.offset) * (int32_t)vRef * (int32_t)CY_HPPASS_DIFGAIN(cfg.diff));
        }

        denom = ((int32_t)CY_HPPASS_SAR_MAX * (int32_t)(uint16_t)(cfg.gain << cfg.avg));

        mVolts = (int16_t)CY_HPPASS_DIV_ROUND(num, denom);
    }
    else
    {
        CY_ASSERT_L1(false); /* The chanIdx or vRef parameter is invalid */
    }

    return mVolts;
}


int32_t Cy_HPPASS_SAR_CountsTo_uVolts(uint8_t chanIdx, uint16_t vRef, int16_t chanCounts)
{
    int32_t uVolts = 0L;

    if (CY_HPPASS_SAR_CHAN_NUM_VALID(chanIdx) && CY_HPPASS_SAR_VREF_VALID(vRef))
    {
        chan_config_t cfg;

        cfg.idx = chanIdx;
        getChanConfig(&cfg);

        /* Calculate the SAR ADC result in uV */
        if (!cfg.sign && !cfg.diff)
        {
            uVolts = (int32_t)((((int64_t)(uint16_t)chanCounts + cfg.offset) * (int32_t)vRef * 1000L) /
                     ((int32_t)CY_HPPASS_SAR_MAX * (int32_t)(uint16_t)(cfg.gain << cfg.avg)));
        }
        else /* sign OR diff */
        {
            uVolts = (int32_t)((((int64_t)chanCounts + cfg.offset) * (int32_t)vRef * 1000L * (int32_t)CY_HPPASS_DIFGAIN(cfg.diff)) /
                     ((int32_t)CY_HPPASS_SAR_MAX * (int32_t)(uint16_t)(cfg.gain << cfg.avg)));
        }
    }
    else
    {
        CY_ASSERT_L1(false); /* The chanIdx or vRef parameter is invalid */
    }

    return uVolts;
}

#endif /* CY_IP_MXS40MCPASS */

/* [] END OF FILE */
