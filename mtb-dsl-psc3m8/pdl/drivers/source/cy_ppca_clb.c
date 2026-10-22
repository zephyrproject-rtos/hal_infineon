/***************************************************************************//**
* \file cy_ppca_clb.c
* \version 1.0
*
* \brief
* Provides API implementation of the PPCA CLB driver.
*
********************************************************************************
* \copyright
* (c) 2023-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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

#if defined (CY_IP_MXS40PPSS)

#include "cy_ppca_clb.h"

#if defined(__cplusplus)
extern "C" {
#endif

void Cy_PPCA_CLB_InitConfig_DICO(PPCA_CLB_DICO_Type *base, cy_stc_ppca_clb_dico_config_t const *config)
{
    /* Input parameters verification */
    CY_ASSERT_L1(CY_IS_PARAM_VALID(base));
    CY_ASSERT_L1(CY_IS_PARAM_VALID(config));

    PPCA_CLB_DICO_CTRL(base) |= _BOOL2FLD(PPCA_CLB_DICO_CTRL_EN_PH1, config->enablePhase1) |
                                _BOOL2FLD(PPCA_CLB_DICO_CTRL_EN_PH2, config->enablePhase2) |
                                _BOOL2FLD(PPCA_CLB_DICO_CTRL_EN_PH3, config->enablePhase3) |
                                _BOOL2FLD(PPCA_CLB_DICO_CTRL_PE_EN, config->enablePhaseEnabler);
    
    PPCA_CLB_DICO_CNFG(base) |= _VAL2FLD(PPCA_CLB_DICO_CNFG_SEL_VAC, config->vac) |
                                _VAL2FLD(PPCA_CLB_DICO_CNFG_SEL_VBUS, config->vbus) |
                                _VAL2FLD(PPCA_CLB_DICO_CNFG_SEL_IL1, config->il1) |
                                _VAL2FLD(PPCA_CLB_DICO_CNFG_SEL_IL2, config->il2) |
                                _VAL2FLD(PPCA_CLB_DICO_CNFG_SEL_IL3, config->il3) |
                                _VAL2FLD(PPCA_CLB_DICO_CNFG_NUM_OF_MEAS_PERIOD, config->numPeriod) |
                                _VAL2FLD(PPCA_CLB_DICO_CNFG_PWM_DEADTIME, config->pwmDeadTime) |
                                _BOOL2FLD(PPCA_CLB_DICO_CNFG_PE_SKIP_SLOPE, config->skipslopeCal) |
                                _BOOL2FLD(PPCA_CLB_DICO_CNFG_PE_IDLE1_RECAL_SLOPE, config->recalSlope) |
                                _VAL2FLD(PPCA_CLB_DICO_CNFG_MONITOR_SEL, config->monitorSignalSel) |
                                _BOOL2FLD(PPCA_CLB_DICO_CNFG_ONLY_CORR_CHARG, config->onlyCorrCharg);

    PPCA_CLB_DICO_SAFE(base) = _VAL2FLD(PPCA_CLB_DICO_SAFE_STATE,config->safeState) |
                               _VAL2FLD(PPCA_CLB_DICO_SAFE_MAX_ON_TIME, config->pwmMaxOnTime) |
                               _VAL2FLD(PPCA_CLB_DICO_SAFE_MIN_ON_TIME, config->pwmMinOnTime);

    PPCA_CLB_DICO_IMAXL(base) = config->imaxl;
    PPCA_CLB_DICO_IMINL(base) = config->iminl;
    PPCA_CLB_DICO_PE_TPHD_1(base) = config->peTPHD1;
    PPCA_CLB_DICO_PE_TPHD_2(base) = config->peTPHD2;
    PPCA_CLB_DICO_PS_TH(base) = config->psThld;
}


void Cy_PPCA_CLB_MACO_InitConfig(PPCA_CLB_MACO_Type *base, cy_stc_ppca_clb_maco_config_t const *config)
{
    uint8_t count;

    /* Input parameters verification */
    CY_ASSERT_L1(CY_IS_PARAM_VALID(base));
    CY_ASSERT_L1(CY_IS_PARAM_VALID(config));

    PPCA_CLB_MACO_CTRL(base) |=  _BOOL2FLD(PPCA_CLB_MACO_CTRL_WAIT_FOR_TRIGGER, config->startMode) |
                                 _BOOL2FLD(PPCA_CLB_MACO_CTRL_MUXSEL_IN_SRC_SEL, config->muxselInSrcSel) |
                                 _BOOL2FLD(PPCA_CLB_MACO_CTRL_MUXSEL_OUT_SYNC_BYPASS, config->muxselOutSyncBypass) |
                                 _BOOL2FLD(PPCA_CLB_MACO_CTRL_EN_AUTO_TRANSITION, config->transitionMode) |
                                 _BOOL2FLD(PPCA_CLB_MACO_CTRL_MACO_FUNC, config->macoFunc) |
                                 _VAL2FLD(PPCA_CLB_MACO_CTRL_MONITOR_SEL, config->monitorSel);
    
    PPCA_CLB_MACO_EVENT(base) = (PPCA_CLB_MACO_EVENT(base) & ~(PPCA_CLB_MACO_EVENT_SEL_NXT_SECT_Msk)) |
                                (_VAL2FLD(PPCA_CLB_MACO_EVENT_SEL_NXT_SECT, config->selNxtSec));


    PPCA_CLB_MACO_SECT0_ROW(base) = _VAL2FLD(PPCA_CLB_MACO_SECT0_ROW_TRAN_ROW, config->patternConfig[0].tranRow) |
                                    _VAL2FLD(PPCA_CLB_MACO_SECT0_ROW_ALL_ROW, config->patternConfig[0].allRow);

    PPCA_CLB_MACO_SECT1_ROW(base) = _VAL2FLD(PPCA_CLB_MACO_SECT1_ROW_TRAN_ROW, config->patternConfig[1].tranRow) |
                                    _VAL2FLD(PPCA_CLB_MACO_SECT1_ROW_ALL_ROW, config->patternConfig[1].allRow);

    PPCA_CLB_MACO_SECT2_ROW(base) = _VAL2FLD(PPCA_CLB_MACO_SECT2_ROW_TRAN_ROW, config->patternConfig[2].tranRow) |
                                    _VAL2FLD(PPCA_CLB_MACO_SECT2_ROW_ALL_ROW, config->patternConfig[2].allRow);

    PPCA_CLB_MACO_SECT0_SAFE(base) = config->patternConfig[0].safeState;
    PPCA_CLB_MACO_SECT1_SAFE(base) = config->patternConfig[1].safeState;
    PPCA_CLB_MACO_SECT2_SAFE(base) = config->patternConfig[2].safeState;

    for(count = 0; count < 20U; count++)
    {
        PPCA_CLB_MACO_SECT0_PATTERN(base, count) = _VAL2FLD(PPCA_CLB_MACO_SECT0_PATTERN_DRV, config->patternConfig[0].driverSignal[count]) |
                                                   _VAL2FLD(PPCA_CLB_MACO_SECT0_PATTERN_DLY, config->patternConfig[0].holdTime[count]);
    }
    
    for(count = 0; count < 20U; count++)
    {
        PPCA_CLB_MACO_SECT1_PATTERN(base, count) = _VAL2FLD(PPCA_CLB_MACO_SECT1_PATTERN_DRV, config->patternConfig[1].driverSignal[count]) |
                                                   _VAL2FLD(PPCA_CLB_MACO_SECT1_PATTERN_DLY, config->patternConfig[1].holdTime[count]);
    }
    
    for(count = 0; count < 20U; count++)
    {
        PPCA_CLB_MACO_SECT2_PATTERN(base, count) = _VAL2FLD(PPCA_CLB_MACO_SECT2_PATTERN_DRV, config->patternConfig[2].driverSignal[count]) |
                                                   _VAL2FLD(PPCA_CLB_MACO_SECT2_PATTERN_DLY, config->patternConfig[2].holdTime[count]);
    }

}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40PPSS */

/* [] END OF FILE */
