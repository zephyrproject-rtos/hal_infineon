/***************************************************************************//**
* \file cy_hppass_csg.c
* \version 1.20
*
* \brief
* Provides the public functions for the CSG subsystem of the High Power Peripheral Analog Sub-System.
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
#include "cy_hppass_csg.h"

#define CY_HPPASS_CSG_DEINIT    (0UL) /**< De-init value for CSG registers */


#ifdef CY_IP_MXS40MCPASS


/* Macros for conditions used by CY_ASSERT calls */
#define CY_HPPASS_DACOUTPUT_VALID(dacOut)       ((CY_HPPASS_DAC_OUT_DISABLED == (dacOut)) || \
                                                 (CY_HPPASS_DAC_OUT_0        == (dacOut)) || \
                                                 (CY_HPPASS_DAC_OUT_1        == (dacOut)) || \
                                                 (CY_HPPASS_DAC_OUT_2        == (dacOut)) || \
                                                 (CY_HPPASS_DAC_OUT_3        == (dacOut)) || \
                                                 (CY_HPPASS_DAC_OUT_4        == (dacOut)))

#define CY_HPPASS_COMP_POS_VALID(pos)           ((CY_HPPASS_COMP_POS_A == (pos)) || \
                                                 (CY_HPPASS_COMP_POS_B == (pos)))

#define CY_HPPASS_COMP_NEG_VALID(neg)           ((CY_HPPASS_COMP_NEG_DAC == (neg)) || \
                                                 (CY_HPPASS_COMP_NEG_A   == (neg)) || \
                                                 (CY_HPPASS_COMP_NEG_B   == (neg)))

#define CY_HPPASS_COMP_BLANK_VALID(blank)       ((CY_HPPASS_COMP_BLANK_DISABLED == (blank)) || \
                                                 (CY_HPPASS_COMP_BLANK_TRIG_HI  == (blank)) || \
                                                 (CY_HPPASS_COMP_BLANK_TRIG_LO  == (blank)))

#define CY_HPPASS_COMP_TRIG_VALID(trig)         ((CY_HPPASS_COMP_TRIG_DISABLED == (trig)) || \
                                                 (CY_HPPASS_COMP_TRIG_0        == (trig)) || \
                                                 (CY_HPPASS_COMP_TRIG_1        == (trig)) || \
                                                 (CY_HPPASS_COMP_TRIG_2        == (trig)) || \
                                                 (CY_HPPASS_COMP_TRIG_3        == (trig)) || \
                                                 (CY_HPPASS_COMP_TRIG_4        == (trig)) || \
                                                 (CY_HPPASS_COMP_TRIG_5        == (trig)) || \
                                                 (CY_HPPASS_COMP_TRIG_6        == (trig)) || \
                                                 (CY_HPPASS_COMP_TRIG_7        == (trig)))

#define CY_HPPASS_COMP_EDGE_VALID(edge)         ((CY_HPPASS_COMP_EDGE_DISABLED == (edge)) || \
                                                 (CY_HPPASS_COMP_EDGE_RISING   == (edge)) || \
                                                 (CY_HPPASS_COMP_EDGE_FALLING  == (edge)) || \
                                                 (CY_HPPASS_COMP_EDGE_BOTH     == (edge)))

#define CY_HPPASS_DAC_START_VALID(start)        ((CY_HPPASS_DAC_START_DISABLED == (start)) || \
                                                 (CY_HPPASS_DAC_START_TRIG_0   == (start)) || \
                                                 (CY_HPPASS_DAC_START_TRIG_1   == (start)) || \
                                                 (CY_HPPASS_DAC_START_TRIG_2   == (start)) || \
                                                 (CY_HPPASS_DAC_START_TRIG_3   == (start)) || \
                                                 (CY_HPPASS_DAC_START_TRIG_4   == (start)) || \
                                                 (CY_HPPASS_DAC_START_TRIG_5   == (start)) || \
                                                 (CY_HPPASS_DAC_START_TRIG_6   == (start)) || \
                                                 (CY_HPPASS_DAC_START_TRIG_7   == (start)) || \
                                                 (CY_HPPASS_DAC_START_AC       == (start)))

#define CY_HPPASS_DAC_UPDATE_VALID(update)      ((CY_HPPASS_DAC_UPDATE_DISABLED     == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_TRIG_0       == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_TRIG_1       == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_TRIG_2       == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_TRIG_3       == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_TRIG_4       == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_TRIG_5       == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_TRIG_6       == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_TRIG_7       == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_AC           == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_PERIOD_TC    == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_COMP_LVL     == (update)) || \
                                                 (CY_HPPASS_DAC_UPDATE_COMP_LVL_INV == (update)))

#define CY_HPPASS_DAC_MODE_VALID(mode)          ((CY_HPPASS_DAC_MODE_BUFFERED      == (mode)) || \
                                                 (CY_HPPASS_DAC_MODE_HYSTERETIC    == (mode)) || \
                                                 (CY_HPPASS_DAC_MODE_SLOPE_RISING  == (mode)) || \
                                                 (CY_HPPASS_DAC_MODE_SLOPE_FALLING == (mode)) || \
                                                 (CY_HPPASS_DAC_MODE_SLOPE_TRIANG  == (mode)) || \
                                                 (CY_HPPASS_DAC_MODE_LUT_FORWARD   == (mode)) || \
                                                 (CY_HPPASS_DAC_MODE_LUT_REVERSE   == (mode)) || \
                                                 (CY_HPPASS_DAC_MODE_LUT_FWD_REV   == (mode)))

#define CY_HPPASS_DAC_DEGLITCH_VALID(deGlitch)  (7U >= (deGlitch))
#define CY_HPPASS_DACA_VALID(valBuffA)          (1023U >= (valBuffA))
#define CY_HPPASS_DACB_VALID(valBuffB)          (1023U >= (valBuffB))


cy_rslt_t Cy_HPPASS_CSG_Init(const cy_stc_hppass_csg_t * csgCfg)
{
    cy_rslt_t result = (cy_rslt_t)CY_HPPASS_SUCCESS;

    if (NULL == csgCfg)
    {
        result = (cy_rslt_t)CY_HPPASS_CSG_BAD_PARAM;
    }
    else if (Cy_HPPASS_AC_IsRunning())
    {
        result = (cy_rslt_t)CY_HPPASS_AC_INVALID_STATE;
    }
    else
    {
        CY_ASSERT_L3(CY_HPPASS_DACOUTPUT_VALID(csgCfg->dacOut));

        HPPASS_CSG_CTRL(HPPASS_BASE) = _VAL2FLD(HPPASS_CSG_CSG_CTRL_VDAC_OUT_SEL, csgCfg->dacOut);

        for (uint8_t i = 0U; i < CY_HPPASS_CSG_NUM; i++)
        {
            if (NULL != csgCfg->slice[i])
            {
                result |= (cy_rslt_t)Cy_HPPASS_CSG_SliceConfig(i, csgCfg->slice[i]);
            }
        }

        for (uint8_t i = 0U; i < CY_HPPASS_CSG_LUT_NUM; i++)
        {
            if ((NULL != csgCfg->lut[i]) && (NULL != csgCfg->lut[i]->waveform))
            {
                result |= (cy_rslt_t)Cy_HPPASS_CSG_LoadWaveform(i, 0U, csgCfg->lut[i]->sampleNum, csgCfg->lut[i]->waveform);
            }
        }
    }

    return result;
}


void Cy_HPPASS_CSG_DeInit(void)
{
    HPPASS_CSG_CTRL(HPPASS_BASE) = CY_HPPASS_CSG_DEINIT;

    for (uint8_t i = 0U; i < CY_HPPASS_CSG_NUM; i++)
    {
        HPPASS_CSG_SLICE_CMP_CFG(HPPASS_BASE, i) = CY_HPPASS_CSG_DEINIT;
        HPPASS_CSG_SLICE_DAC_CFG(HPPASS_BASE, i) = CY_HPPASS_CSG_DEINIT;
        HPPASS_CSG_SLICE_DAC_VAL_A(HPPASS_BASE, i) = CY_HPPASS_CSG_DEINIT;
        HPPASS_CSG_SLICE_DAC_VAL_B(HPPASS_BASE, i) = CY_HPPASS_CSG_DEINIT;
        HPPASS_CSG_SLICE_DAC_PERIOD(HPPASS_BASE, i) = CY_HPPASS_CSG_DEINIT;
    }
}


cy_en_hppass_status_t Cy_HPPASS_CSG_SliceConfig(uint8_t sliceIdx, const cy_stc_hppass_slice_t * slice)
{
    cy_en_hppass_status_t result = CY_HPPASS_SUCCESS;

    if ((NULL == slice) || (CY_HPPASS_CSG_NUM <= sliceIdx))
    {
        result = CY_HPPASS_CSG_BAD_PARAM;
    }
    else if (Cy_HPPASS_AC_IsRunning())
    {
        result = CY_HPPASS_AC_INVALID_STATE;
    }
    else if (Cy_HPPASS_DAC_IsBusy(sliceIdx))
    {
        result = CY_HPPASS_CSG_INVALID_STATE;
    }
    else
    {
        /* Configure Comparator */
        CY_ASSERT_L3(CY_HPPASS_COMP_POS_VALID(slice->comp.pos));
        CY_ASSERT_L3(CY_HPPASS_COMP_NEG_VALID(slice->comp.neg));
        CY_ASSERT_L3(CY_HPPASS_COMP_BLANK_VALID(slice->comp.blank));
        CY_ASSERT_L3(CY_HPPASS_COMP_TRIG_VALID(slice->comp.trig));
        CY_ASSERT_L3(CY_HPPASS_COMP_EDGE_VALID(slice->comp.edge));

        HPPASS_CSG_SLICE_CMP_CFG(HPPASS_BASE, sliceIdx) =
            _VAL2FLD(HPPASS_CSG_SLICE_CMP_CFG_CMP_POS_SEL, slice->comp.pos)       |
            _VAL2FLD(HPPASS_CSG_SLICE_CMP_CFG_CMP_NEG_SEL, slice->comp.neg)       |
            _VAL2FLD(HPPASS_CSG_SLICE_CMP_CFG_CMP_BLANK_MODE, slice->comp.blank)  |
            _VAL2FLD(HPPASS_CSG_SLICE_CMP_CFG_CMP_BLANK_TR_SEL, slice->comp.trig) |
            _VAL2FLD(HPPASS_CSG_SLICE_CMP_CFG_CMP_EDGE_MODE, slice->comp.edge)    |
            _VAL2FLD(HPPASS_CSG_SLICE_CMP_CFG_CMP_POLARITY, slice->comp.invert);

        /* Configure DAC */
        CY_ASSERT_L3(CY_HPPASS_DAC_START_VALID(slice->dac.start));
        CY_ASSERT_L3(CY_HPPASS_DAC_UPDATE_VALID(slice->dac.update));
        CY_ASSERT_L3(CY_HPPASS_DAC_MODE_VALID(slice->dac.mode));
        CY_ASSERT_L2(CY_HPPASS_DAC_DEGLITCH_VALID(slice->dac.deGlitch));

        HPPASS_CSG_SLICE_DAC_CFG(HPPASS_BASE, sliceIdx) =
            _VAL2FLD(HPPASS_CSG_SLICE_DAC_CFG_DAC_TR_START_SEL, slice->dac.start)      |
            _VAL2FLD(HPPASS_CSG_SLICE_DAC_CFG_DAC_TR_UPDATE_SEL, slice->dac.update)    |
            _VAL2FLD(HPPASS_CSG_SLICE_DAC_CFG_DAC_MODE, slice->dac.mode)               |
            _VAL2FLD(HPPASS_CSG_SLICE_DAC_CFG_DAC_CONT, slice->dac.continuous)         |
            _VAL2FLD(HPPASS_CSG_SLICE_DAC_CFG_DAC_SKIP_TR_EN, slice->dac.skipTrig)     |
            _VAL2FLD(HPPASS_CSG_SLICE_DAC_CFG_DAC_CASCADE_EN, slice->dac.cascade)      |
            _VAL2FLD(HPPASS_CSG_SLICE_DAC_CFG_DAC_PARAM_SYNC_EN, slice->dac.paramSync) |
            _VAL2FLD(HPPASS_CSG_SLICE_DAC_CFG_DAC_DEGLITCH, slice->dac.deGlitch);

        switch (slice->dac.mode)
        {
            case CY_HPPASS_DAC_MODE_BUFFERED:
                Cy_HPPASS_DAC_SetValue(sliceIdx, slice->dac.valBuffA);
                break;

            case CY_HPPASS_DAC_MODE_HYSTERETIC:
                Cy_HPPASS_DAC_SetHystereticValues(sliceIdx, slice->dac.valBuffA, slice->dac.valBuffB);
                break;

            case CY_HPPASS_DAC_MODE_SLOPE_RISING:
            case CY_HPPASS_DAC_MODE_SLOPE_FALLING:
            case CY_HPPASS_DAC_MODE_SLOPE_TRIANG:
                Cy_HPPASS_DAC_SetSlopeValues(sliceIdx, slice->dac.valBuffA, slice->dac.valBuffB, slice->dac.stepSize);
                break;

            case CY_HPPASS_DAC_MODE_LUT_FORWARD:
            case CY_HPPASS_DAC_MODE_LUT_REVERSE:
            case CY_HPPASS_DAC_MODE_LUT_FWD_REV:
                Cy_HPPASS_DAC_SetLutAddress(sliceIdx, (uint8_t)slice->dac.valBuffA, (uint8_t)slice->dac.valBuffB, slice->dac.stepSize);
                break;

            default:
                CY_ASSERT_L3(false); /* Invalid mode */
                break;
        }

        /* Set DAC period buffer */
        Cy_HPPASS_DAC_SetPeriod(sliceIdx, slice->dac.period);
    }

    return result;
}


cy_en_hppass_status_t Cy_HPPASS_CSG_LoadWaveform(uint8_t lutIdx, uint8_t dataIdx, uint8_t numSamples, const uint16_t * waveform)
{
    cy_en_hppass_status_t result = CY_HPPASS_SUCCESS;

    if ((CY_HPPASS_CSG_LUT_NUM <= lutIdx) ||
        (CY_HPPASS_CSG_LUT_SIZE < ((uint32_t)dataIdx + numSamples)) ||
        (0U == numSamples) ||
        (NULL == waveform))
    {
        result = CY_HPPASS_CSG_BAD_PARAM;
    }
    else
    {
        for(uint8_t i = 0U; i < numSamples; i++)
        {
            HPPASS_CSG_LUT_CFG(HPPASS_BASE, lutIdx, (dataIdx + i)) = (uint32_t)waveform[i]; /* Set waveform data to the CSG LUT register */
        }
    }
    return result;
}


#endif /* CY_IP_MXS40MCPASS */

/* [] END OF FILE */
