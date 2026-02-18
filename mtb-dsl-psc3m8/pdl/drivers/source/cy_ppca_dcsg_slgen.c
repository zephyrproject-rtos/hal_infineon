/***************************************************************************//**
* \file cy_ppca_dcsg_slgen.c
* \version 1.0
*
* \brief
* Provides API implementation of the PPCA DCSG SLGEN driver.
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

#include "cy_ppca_dcsg_slgen.h"

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Init
***************************************************************************//**
*
* Initializes and enables the DCSG SLGEN
*
* \param base The pointer to the DCSG instance address.
*
* \param config The pointer to the config structure.
*
******************************************************************************/
void Cy_PPCA_DCSG_SLGEN_Init(ATOPSS_SLGEN_TYPE *base, cy_stc_ppca_dcsg_slgen_config_t const *config)
{
    /* Input parameters verification */
    CY_ASSERT(NULL != base);
    CY_ASSERT(NULL != config);

    PPCA_ATOP_DCSG_SLGEN_CTL(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_TRIGGER_UNMASK, config->trigger_unmask)   |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SIN_CLK_BLANK, config->single_clk_glitch)      |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SLGEN_EN, 1U);
    PPCA_ATOP_DCSG_SLGEN_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_SEL_SLGEN_SRC, config->slgen_src)        |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_EN_SHADOW_TRANSFER, config->shadow_transfer)   |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_AUTO_RESET, config->auto_reset)                |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_SLGEN_MAP, config->slgen_map);

    PPCA_ATOP_DCSG_SLGEN_INIT(base) =        _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_F, config->slgen_init_frac_value)             |
                                             _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_I, config->slgen_init_value);
    PPCA_ATOP_DCSG_SLGEN_TARGET(base) =      _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_F, config->slgen_target_frac_value)         |
                                             _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_I, config->slgen_target_value);    
    PPCA_ATOP_DCSG_SLGEN_INIT_BUF(base) =    _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_BUF_F, config->slgen_init_buf_frac_value)     |
                                             _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_BUF_I, config->slgen_init_buf_value);    
    PPCA_ATOP_DCSG_SLGEN_TARGET_BUF(base) =  _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_BUF_F, config->slgen_target_buf_frac_value) |
                                             _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_BUF_I, config->slgen_target_buf_value);
    PPCA_ATOP_DCSG_SLGEN_STEP(base) =        _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_STEP_F, config->slgen_step_frac_value)             |
                                             _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_STEP_I, config->slgen_step_value);

}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40PPSS */

/* [] END OF FILE */
