/***************************************************************************//**
* \file cy_ppca_cnfg.c
* \version 1.0
*
* \brief
* Provides API implementation of the PPCA CNFG driver.
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

#if (defined (CY_IP_MXS40PPSS) && !defined (COMPONENT_PPCA_DEVICE))

#include "cy_ppca_cnfg.h"

#if defined(__cplusplus)
extern "C" {
#endif

void Cy_PPCA_CNFG_Init(PPCA_CNFG_Type *base, cy_stc_ppca_cnfg_config_t const *config)
{

    /* Input parameters verification */
    CY_ASSERT_L1(CY_IS_PARAM_VALID(base));
    CY_ASSERT_L1(CY_IS_PARAM_VALID(config));

    PPCA_CNFG_CTRL(base) |= _BOOL2FLD(PPCA_CNFG_CTRL_PPCA_EN_DEEPSLEEPRSTN, config->dpslpRetentionEnable) |
                                 _BOOL2FLD(PPCA_CNFG_CTRL_PPCA_CLK_SH_DWN_EN, config->clkShutDown) |
                                 _BOOL2FLD(PPCA_CNFG_CTRL_REMAP_MEM, config->remapEnable) |
                                 _BOOL2FLD(PPCA_CNFG_CTRL_CPU0_HRESP_ERROR_ENABLE, config->cpu0HRESPError) |
                                 _BOOL2FLD(PPCA_CNFG_CTRL_CPU1_HRESP_ERROR_ENABLE, config->cpu1HRESPError);

    PPCA_CNFG_CNFG_CPU_CTRL((PPCA_CNFG_CNFG_Type*) &base->CNFG) |= _BOOL2FLD(PPCA_CNFG_CNFG_CPU_CTRL_CPU0_ENABLE, config->cpu0Enable) |
                                                                             _BOOL2FLD(PPCA_CNFG_CNFG_CPU_CTRL_CPU1_ENABLE, config->cpu1Enable);

    PPCA_CNFG_CNFG_CNFG0((PPCA_CNFG_CNFG_Type*) &base->CNFG) |= _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_PWM_SS0, config->ctrl_cnfg->pwmSS0) |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_PWM_SS1, config->ctrl_cnfg->pwmSS1) |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_PWM_SS2, config->ctrl_cnfg->pwmSS2) |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_PWM_SS3, config->ctrl_cnfg->pwmSS3) |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_HWFILT3P3Z_SS0, config->ctrl_cnfg->HWFILT3P3Z_SS0) |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_HWFILT3P3Z_SS1, config->ctrl_cnfg->HWFILT3P3Z_SS1) |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_ADC_MIRROR, config->ctrl_cnfg->ADCMirror) |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_CLB, config->ctrl_cnfg->CLB) |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_CORDIC_0, config->ctrl_cnfg->cordic0)     |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_CORDIC_1, config->ctrl_cnfg->cordic1)     |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_ADCGRP_0, config->ctrl_cnfg->adcGroup0)   |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_ADCGRP_1, config->ctrl_cnfg->adcGroup1)   |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_ADCGRP_2, config->ctrl_cnfg->adcGroup2)   |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_ADCGRP_3, config->ctrl_cnfg->adcGroup3)   |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_DCSGGRP_0, config->ctrl_cnfg->dcsgGroup0) |
                                                                          _BOOL2FLD(PPCA_CNFG_CNFG_CNFG0_DCSGGRP_1, config->ctrl_cnfg->dcsgGroup1);
    
    PPCA_CNFG_CNFG_CNFG1((PPCA_CNFG_CNFG_Type*) &base->CNFG) = config->puty1ResAlloc;
    
    PPCA_CNFG_CNFG_CNFG2((PPCA_CNFG_CNFG_Type*) &base->CNFG) = config->puty2ResAlloc;
    
    PPCA_CNFG_CNFG_PPCAOUT_SEL((PPCA_CNFG_CNFG_Type*) &base->CNFG) = _VAL2FLD(PPCA_CNFG_CNFG_PPCAOUT_SEL_PPCAOUT_SEL_SRC, (uint32_t) config->ppcaout_cnfg->outputSelSrc) |
                                                                               _BOOL2FLD(PPCA_CNFG_CNFG_PPCAOUT_SEL_PPCAOUT_SEL_EN, config->ppcaout_cnfg->enableOutputSel);


}


#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40PPSS */

/* [] END OF FILE */
