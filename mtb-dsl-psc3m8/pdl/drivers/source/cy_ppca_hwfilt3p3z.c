/***************************************************************************//**
* \file cy_ppca_hwfilt3p3z.c
* \version 1.0
*
* \brief
* Provides API implementation of the PPCA HW Filter 3P3Z driver.
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

#include "cy_ppca_hwfilt3p3z.h"

#if defined(__cplusplus)
extern "C" {
#endif

void Cy_PPCA_HWFILT3P3Z_InitFilterConfig(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base, cy_stc_ppca_hwfilt3p3z_config_t const *config)
{
    /* Input parameters verification */
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(base));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(config));

    /* Configure data source for DATA_IN1 and processing trigger selection */
    PPCA_HWFILT3P3Z_SS_CNFG(base) = _VAL2FLD(PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_SRC_SEL, config->srcSel) |
                                    _BOOL2FLD(PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG0, config->enTrig0) |
                                    _BOOL2FLD(PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG1, config->enTrig1);
    /* Program 3P3Z filter coefficients: B0-B3 (numerator/zeros) and A1-A3 (denominator/poles) */
    PPCA_HWFILT3P3Z_SS_CX0(base) = config->cx0;
    PPCA_HWFILT3P3Z_SS_CX1(base) = config->cx1;
    PPCA_HWFILT3P3Z_SS_CX2(base) = config->cx2;
    PPCA_HWFILT3P3Z_SS_CX3(base) = config->cx3;
    PPCA_HWFILT3P3Z_SS_CY1(base) = config->cy1;
    PPCA_HWFILT3P3Z_SS_CY2(base) = config->cy2;
    PPCA_HWFILT3P3Z_SS_CY3(base) = config->cy3;
    /* Configure output offset, saturation limits, scale factors and gains */
    PPCA_HWFILT3P3Z_SS_OFFSET(base) = config->dataOutOffset;
    PPCA_HWFILT3P3Z_SS_LIMMAX(base) = config->limMax;
    PPCA_HWFILT3P3Z_SS_LIMMIN(base) = config->limMin;
    PPCA_HWFILT3P3Z_SS_SCALECX(base) = (uint32_t)(config->scaleCX);
    PPCA_HWFILT3P3Z_SS_SCALECY(base) = (uint32_t)(config->scaleCY);
    PPCA_HWFILT3P3Z_SS_GIN(base) = config->gIn;
    PPCA_HWFILT3P3Z_SS_GOUT(base) = config->gOut;
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40PPSS */

/* [] END OF FILE */
