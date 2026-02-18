/***************************************************************************//**
* \file cy_ppca_dcmp.c
* \version 1.0
*
* \brief
* Provides API implementation of the PPCA DCSG driver.
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG or an affiliate of
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

#include "cy_ppca_dcmp.h"

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
* Function Name: Cy_PPCA_DCMP_Init
***************************************************************************//**
*
* Initializes and enables the DCMP
*
* \param base The pointer to the DCMP instance address.
*
* \param config The pointer to the config structure.
*
******************************************************************************/
void Cy_PPCA_DCMP_Init(ATOPSS_DCMP_TYPE *base, cy_stc_ppca_dcmp_config_t const *config)
{
    /* Input parameters verification */
    CY_ASSERT(NULL != base);
    CY_ASSERT(NULL != config);

    PPCA_ATOP_DCMP_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_MODE, config->comparison_mode)                |
                                _VAL2FLD(PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_SAMPLE, config->avg_sampling_window)           |
                                _VAL2FLD(PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_SEL_SRC_CH, config->src_ch)                    |
                                _VAL2FLD(PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_INV_DCMP_EV_CNFG, config->inv_dcmp_ev);

    PPCA_ATOP_DCMP_TH(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_TH_DCMP_TH, config->dcmp_threshold);
    PPCA_ATOP_DCMP_ACC_TH(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_ACC_TH_DCMP_ACC_TH, config->dcmp_acc_threshold);

}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40PPSS */

/* [] END OF FILE */
