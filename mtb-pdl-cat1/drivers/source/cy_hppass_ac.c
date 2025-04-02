/***************************************************************************//**
* \file cy_hppass_ac.c
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
#include "cy_hppass_ac.h"

#ifdef CY_IP_MXS40MCPASS

#define CY_HPPASS_SUPPRESS_AC_RUN_CHECK

cy_en_hppass_status_t Cy_HPPASS_AC_GetState(cy_stc_hppass_state_t * state)
{
    cy_en_hppass_status_t result = CY_HPPASS_AC_BAD_PARAM;

    if (NULL != state)
    {
        /* The Autonomous Controller status and state */
        state->ac.running = Cy_HPPASS_AC_IsRunning();
        state->ac.stateIdx = (uint8_t) _FLD2VAL(HPPASS_ACTRLR_STATUS_CUR_STATE, HPPASS_AC_STATUS(HPPASS_BASE));

        /* The Timer/Counter[] state */
        for (uint8_t cntIdx = 0U; cntIdx < CY_HPPASS_TC_NUM; cntIdx++)
        {
            state->tc[cntIdx].stateIdx = (uint8_t) _FLD2VAL(HPPASS_ACTRLR_CNTR_STATUS_CUR_STATE, HPPASS_AC_CNTR_STATUS(HPPASS_BASE, cntIdx));
            state->tc[cntIdx].count = (uint16_t) _FLD2VAL(HPPASS_ACTRLR_CNTR_STATUS_CUR_CNT, HPPASS_AC_CNTR_STATUS(HPPASS_BASE, cntIdx));
            state->tc[cntIdx].busy = _FLD2BOOL(HPPASS_ACTRLR_CNTR_STATUS_BUSY, HPPASS_AC_CNTR_STATUS(HPPASS_BASE, cntIdx));
        }

        result = CY_HPPASS_SUCCESS;
    }

    return result;
}


cy_en_hppass_status_t Cy_HPPASS_AC_UpdateStateTransitionTable(uint8_t numEntries, const cy_stc_hppass_ac_stt_t * stateTransitionTable, uint8_t startState)
{
    cy_en_hppass_status_t result = CY_HPPASS_AC_BAD_PARAM;

    if ((NULL != stateTransitionTable)        &&
        (CY_HPPASS_AC_STT_SIZE >= numEntries) &&
        (CY_HPPASS_AC_STT_SIZE > startState)  &&
        (CY_HPPASS_AC_STT_SIZE >= (numEntries + startState)))
    {
        if (Cy_HPPASS_AC_IsRunning())
        {
            result = CY_HPPASS_AC_INVALID_STATE;
        }
        else
        {
            uint8_t startStateLoc = startState;

            for (uint8_t sttIdx = 0U; sttIdx < numEntries; sttIdx++)
            {
                uint32_t csgUnlockVal = 0UL;
                uint32_t csgCfg = 0UL;
                uint32_t sarAroute = 0UL;

                for (uint8_t csgIdx = 0U; csgIdx < CY_HPPASS_CSG_NUM; csgIdx++)
                {
                    uint32_t csgUnlock_Msk = HPPASS_ACTRLR_TTCFG_TT_CFG0_CSG_UNLOCK_Msk;
                    uint32_t csgUnlock_Pos = HPPASS_ACTRLR_TTCFG_TT_CFG0_CSG_UNLOCK_Pos + csgIdx;

                    uint32_t csgEn_Msk = HPPASS_ACTRLR_TTCFG_TT_CFG2_CSG_EN_Msk;
                    uint32_t csgEn_Pos = csgIdx;

                    uint32_t csgDacTrig_Msk = HPPASS_ACTRLR_TTCFG_TT_CFG2_CSG_DAC_TR_Msk;
                    uint32_t csgDacTrig_Pos = HPPASS_ACTRLR_TTCFG_TT_CFG2_CSG_DAC_TR_Pos + csgIdx;

                    csgUnlockVal |= _VAL2FLD(csgUnlock, stateTransitionTable[sttIdx].csgUnlock[csgIdx]);
                    csgCfg |= _VAL2FLD(csgEn, stateTransitionTable[sttIdx].csgEnable[csgIdx]) |
                         _VAL2FLD(csgDacTrig, stateTransitionTable[sttIdx].csgDacTrig[csgIdx]);
                }

                CY_ASSERT_L2(CY_HPPASS_GPIOOUT_VALID(stateTransitionTable[sttIdx].gpioOutMsk));

                HPPASS_AC_TT_CFG0(HPPASS_BASE, startStateLoc) = csgUnlockVal |
                    _VAL2FLD(HPPASS_ACTRLR_TTCFG_TT_CFG0_SAR_UNLOCK, stateTransitionTable[sttIdx].sarUnlock) |
                    _VAL2FLD(HPPASS_ACTRLR_TTCFG_TT_CFG0_DOUT_UNLOCK, CY_HPPASS_BOOL_TO_UINT(stateTransitionTable[sttIdx].gpioOutUnlock)) |
                    _VAL2FLD(HPPASS_ACTRLR_TTCFG_TT_CFG0_DOUT, stateTransitionTable[sttIdx].gpioOutMsk);

                CY_ASSERT_L2(CY_HPPASS_BRANCHSTATE_VALID(stateTransitionTable[sttIdx].branchStateIdx));
                CY_ASSERT_L3(CY_HPPASS_AC_CONDITION_VALID(stateTransitionTable[sttIdx].condition));
                CY_ASSERT_L3(CY_HPPASS_AC_ACTION_VALID(stateTransitionTable[sttIdx].action));

                HPPASS_AC_TT_CFG1(HPPASS_BASE, startStateLoc) =
                    _VAL2FLD(HPPASS_ACTRLR_TTCFG_TT_CFG1_BR_ADDR, stateTransitionTable[sttIdx].branchStateIdx) |
                    _VAL2FLD(HPPASS_ACTRLR_TTCFG_TT_CFG1_COND, stateTransitionTable[sttIdx].condition) |
                    _VAL2FLD(HPPASS_ACTRLR_TTCFG_TT_CFG1_ACTION, stateTransitionTable[sttIdx].action) |
                    _VAL2FLD(HPPASS_ACTRLR_TTCFG_TT_CFG1_INTR_SET, CY_HPPASS_BOOL_TO_UINT(stateTransitionTable[sttIdx].interrupt));

                if(CY_HPPASS_CONDITION_CNT_DONE == stateTransitionTable[sttIdx].condition)
                {
                    CY_ASSERT_L2(CY_HPPASS_AC_COUNT_VALID(stateTransitionTable[sttIdx].count));

                    HPPASS_AC_TT_CFG1(HPPASS_BASE, startStateLoc) |=
                      _VAL2FLD(HPPASS_ACTRLR_TTCFG_TT_CFG1_CNT, (uint32_t)stateTransitionTable[sttIdx].count - 1UL);
                }

                HPPASS_AC_TT_CFG2(HPPASS_BASE, startStateLoc) = csgCfg;

                for (uint8_t muxIdx = 0U; muxIdx < CY_HPPASS_SAR_MUX_NUM; muxIdx++)
                {
                    CY_ASSERT_L2(CY_HPPASS_MUXSELECT_VALID(stateTransitionTable[sttIdx].sarMux[muxIdx].chanIdx));

                    uint32_t sarArouteTrig_Msk = HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_AROUTE_TR_Msk;
                    uint32_t sarArouteTrig_Pos = HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_AROUTE_TR_Pos + muxIdx;

                    uint32_t sarArouteSel_Msk = HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_AROUTE_SEL_Msk;
                    uint32_t sarArouteSel_Pos = HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_AROUTE_SEL_Pos + muxIdx;

                    sarAroute |= _VAL2FLD(sarArouteTrig, stateTransitionTable[sttIdx].sarMux[muxIdx].unlock) |
                                 _VAL2FLD(sarArouteSel,  stateTransitionTable[sttIdx].sarMux[muxIdx].chanIdx);
                }

                HPPASS_AC_TT_CFG3(HPPASS_BASE, startStateLoc) = sarAroute                            |
                    _VAL2FLD(HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_TR, stateTransitionTable[sttIdx].sarGrpMsk) |
                    _VAL2FLD(HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_EN, stateTransitionTable[sttIdx].sarEnable);
                startStateLoc++;
                result = CY_HPPASS_SUCCESS;
            }
        }
    }

    return result;
}

cy_en_hppass_status_t Cy_HPPASS_AC_Start(uint8_t startState, uint16_t timeoutUs)
{
    cy_en_hppass_status_t result = CY_HPPASS_AC_BAD_PARAM;

    if (CY_HPPASS_AC_STT_SIZE > startState)
    {
        if (Cy_HPPASS_AC_IsRunning())
        {
            result = CY_HPPASS_AC_INVALID_STATE;
        }

        /* Check the VDDA voltage status */
        else if (!_FLD2BOOL(HPPASS_INFRA_VDDA_STATUS_VDDA_OK, HPPASS_INFRA_VDDA_STATUS(HPPASS_BASE)))
        {
            result = CY_HPPASS_VDDA_FAIL;
        }
        else
        {
            HPPASS_AC_CMD_STATE(HPPASS_BASE) = _VAL2FLD(HPPASS_ACTRLR_CMD_STATE_STATE, startState);
            HPPASS_AC_CMD_RUN(HPPASS_BASE) = HPPASS_ACTRLR_CMD_RUN_RUN_Msk;

            result = CY_HPPASS_SUCCESS;

            if (0U != timeoutUs)
            {
                while (!Cy_HPPASS_AC_IsBlockReady() && (0U != timeoutUs))
                {
                    timeoutUs--;
                    Cy_SysLib_DelayUs(1U);
                }

                if (0U == timeoutUs)
                {
                    result = CY_HPPASS_TIMEOUT;
                }
            }
        }
    }

    return result;
}

#endif /* CY_IP_MXS40MCPASS */

/* [] END OF FILE */
