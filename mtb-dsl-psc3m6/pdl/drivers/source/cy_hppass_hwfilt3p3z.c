/***************************************************************************//**
* \file cy_hppass_hwfilt3p3z.c
* \version 1.0
*
* \brief
* Provides API implementation of the HPPASS HW Filter 3P3Z driver.
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG, or an affiliate of Infineon
* Technologies AG.
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

#if defined (CY_IP_MXS40MCPASS) && (CY_IP_MXS40MCPASS_VERSION >= 3u)

#include "cy_hppass_hwfilt3p3z.h"

#if defined(__cplusplus)
extern "C" {
#endif

void Cy_HPPASS_HWFILT3P3Z_InitFilterConfig(uint8_t filtIdx, cy_stc_hppass_hwfilt3p3z_config_t const *config)
{
    /* Input parameters verification */
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(config));
    CY_ASSERT_L2(filtIdx < CY_HPPASS_HWFILT3P3Z_NUM_INSTANCE);

    HPPASS_HWFILT3P3Z_CNFG(HPPASS_BASE, filtIdx) = _VAL2FLD(HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_SRC_SEL, config->srcSel) |
                                                    _BOOL2FLD(HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_EN_TRIG0, config->enTrig0) |
                                                    _BOOL2FLD(HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_EN_TRIG1, config->enTrig1);
    HPPASS_HWFILT3P3Z_CX0(HPPASS_BASE, filtIdx) = config->cx0;
    HPPASS_HWFILT3P3Z_CX1(HPPASS_BASE, filtIdx) = config->cx1;
    HPPASS_HWFILT3P3Z_CX2(HPPASS_BASE, filtIdx) = config->cx2;
    HPPASS_HWFILT3P3Z_CX3(HPPASS_BASE, filtIdx) = config->cx3;
    HPPASS_HWFILT3P3Z_CY1(HPPASS_BASE, filtIdx) = config->cy1;
    HPPASS_HWFILT3P3Z_CY2(HPPASS_BASE, filtIdx) = config->cy2;
    HPPASS_HWFILT3P3Z_CY3(HPPASS_BASE, filtIdx) = config->cy3;
    HPPASS_HWFILT3P3Z_OFFSET(HPPASS_BASE, filtIdx) = config->dataOutOffset;
    HPPASS_HWFILT3P3Z_LIMMAX(HPPASS_BASE, filtIdx) = config->limMax;
    HPPASS_HWFILT3P3Z_LIMMIN(HPPASS_BASE, filtIdx) = config->limMin;
    HPPASS_HWFILT3P3Z_SCALECX(HPPASS_BASE, filtIdx) = (uint32_t)(config->scaleCX);
    HPPASS_HWFILT3P3Z_SCALECY(HPPASS_BASE, filtIdx) = (uint32_t)(config->scaleCY);
    HPPASS_HWFILT3P3Z_GIN(HPPASS_BASE, filtIdx) = config->gIn;
    HPPASS_HWFILT3P3Z_GOUT(HPPASS_BASE, filtIdx) = config->gOut;
    HPPASS_HWFILT3P3Z_AWMAX(HPPASS_BASE, filtIdx) = config->awMax;
    HPPASS_HWFILT3P3Z_AWMIN(HPPASS_BASE, filtIdx) = config->awMin;
    HPPASS_HWFILT3P3Z_AWGAIN(HPPASS_BASE, filtIdx) = config->awGain;

    /* HWFILT3P3Z_IND_CTRL only exists for instances 0..2 */
    if (filtIdx < 3U)
    {
        CY_REG32_CLR_SET(HPPASS_SAR_HWFILT3P3Z_IND_CTRL(HPPASS_BASE, filtIdx),
                         HPPASS_SAR_CFG_HWFILT3P3Z_IND_CTRL_CHANNEL_SEL,
                         config->channelSel);
    }
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40MCPASS && CY_IP_MXS40MCPASS_VERSION >= 3u */

/* [] END OF FILE */
