/***************************************************************************//**
* \file cy_ppca_dcsg.c
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

#include "cy_ppca_dcsg.h"
#include "cy_ppca_aref.h"

#if defined(__cplusplus)
extern "C" {
#endif
#if defined (LOAD_PPCA_TRIMS)
static void Cy_PPCA_DCSG_Set_Trims(ATOPSS_DCSG_TYPE *base, uint8_t group, uint32_t trim_number);
#endif /* defined (LOAD_PPCA_TRIMS) */
/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Init
***************************************************************************//**
*
* Initializes and enables the DCSG
*
* \param base The pointer to the DCSG instance address.
*
* \param config The pointer to the config structure.
*
******************************************************************************/
void Cy_PPCA_DCSG_Init(ATOPSS_DCSG_TYPE *base, cy_stc_ppca_dcsg_config_t const *config)
{
    /* Input parameters verification */
    CY_ASSERT(NULL != base);
    CY_ASSERT(NULL != config);
    CY_ASSERT(CY_PPCA_DCSG_IS_THRESHOLD_VALID(config->threshold));

    PPCA_ATOP_DCSG_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_SEL_SRC, config->src_type)                         |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_SEL_CH_SRC, config->src_ch)                        |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_TYPE_CH_SRC, config->src_ch_type)                  |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_INIT_SETTING, config->blanking_period)             |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_DCSG_DAC_RATE, config->dac_clk_blk_rate)           |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_BYPASS_REFRESH, config->bypass_refresh)       |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_DEFINED_VALUE_SETUP, config->use_user_value)  |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_DEFINED_VALUE, config->user_value)            |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_HYST, config->hyst_value)                          |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_DEB, config->debounce_rate)                        |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_CFG_REFRESH_RATE, config->refresh_rate);

    PPCA_ATOP_DCSG_TH(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_TH_TH, config->threshold);

#if defined (LOAD_PPCA_TRIMS)

    Cy_PPCA_DCSG_Set_Trims(base, config->groupNumber, SFLASH_DCSG_TRIMS_NUMBER);

#endif /* defined (LOAD_PPCA_TRIMS) */
}

#if defined (LOAD_PPCA_TRIMS)
/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Set_Trims
***************************************************************************//**
*
* Initialize trim values for DCSG
*
* \param base The pointer to the DCSG instance address.
*
* \param group Group number of the DCSG instance.
*
* \param trim_number trim_number to be used.
*
* \note There are total 6 different trims for DCSG Group0 and 3 different trims for DCSG Group1
*
******************************************************************************/

static void Cy_PPCA_DCSG_Set_Trims(ATOPSS_DCSG_TYPE *base, uint8_t group, uint32_t trim_number)
{
    uint32_t offset = 0UL;
    if(CY_EXTERNALLY_SUPPLIED_VREF == Cy_PPCA_AREF_Get_VREF_Source(PPCA_ATOPSS_ADC_GRP0_AREF))
    {
        if((group == 0u) && (trim_number <= 2u))
        {
            offset = (uint32_t)(trim_number * SFLASH_DCSG_TRIM_OFFSET) + SFLASH_EXTERNAL_VREF_OFFSET;
        }
        else
        {
            offset = (uint32_t)(trim_number * SFLASH_DCSG_TRIM_OFFSET) + SFLASH_EXTERNAL_VREF_DAC_OFFSET;
        }
    }
    else
    {
        offset = (uint32_t)(trim_number * SFLASH_DCSG_TRIM_OFFSET);
    }
    switch(group)
    {
        case 0:
        {
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 1, \
'Intentional pointer type conversion to access TEST_OFFSET registers')
            CY_SET_REG32(((uint32_t)base + (uint32_t)PPCA_ATOP_DCSG_TEST_OFFSET), SFLASH_GRP0_DCSG_TEST_VREF_TRIM(offset));
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')
            PPCA_ATOP_DCSG_DIFF_CALOFFSET(base)  = SFLASH_GRP0_DCSG_DIFF_CALOFFSET(offset);
            PPCA_ATOP_DCSG_SE_CALOFFSET(base)    = SFLASH_GRP0_DCSG_SE_CALOFFSET(offset);
            PPCA_ATOP_DCSG_DIFF_CALGAIN_1(base)  = SFLASH_GRP0_DCSG_DIFF_CALGAIN_1(offset);
            PPCA_ATOP_DCSG_DIFF_CALGAIN_2(base)  = SFLASH_GRP0_DCSG_DIFF_CALGAIN_2(offset);
            PPCA_ATOP_DCSG_SE_CALGAIN(base)      = SFLASH_GRP0_DCSG_SE_CALGAIN(offset);
        }
        break;
        case 1:
        {
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 1, \
'Intentional pointer type conversion to access TEST_OFFSET registers')
            CY_SET_REG32(((uint32_t)base + (uint32_t)PPCA_ATOP_DCSG_TEST_OFFSET), SFLASH_GRP1_DCSG_TEST_VREF_TRIM(offset));
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')
            PPCA_ATOP_DCSG_DIFF_CALOFFSET(base)  = SFLASH_GRP1_DCSG_DIFF_CALOFFSET(offset);
            PPCA_ATOP_DCSG_SE_CALOFFSET(base)    = SFLASH_GRP1_DCSG_SE_CALOFFSET(offset);
            PPCA_ATOP_DCSG_DIFF_CALGAIN_1(base)  = SFLASH_GRP1_DCSG_DIFF_CALGAIN_1(offset);
            PPCA_ATOP_DCSG_DIFF_CALGAIN_2(base)  = SFLASH_GRP1_DCSG_DIFF_CALGAIN_2(offset);
            PPCA_ATOP_DCSG_SE_CALGAIN(base)      = SFLASH_GRP1_DCSG_SE_CALGAIN(offset);
        }
        break;
        default :
        {
            /* nothing to do */
        }
        break;
    }
}
#endif /* defined (LOAD_PPCA_TRIMS) */
#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40PPSS */

/* [] END OF FILE */
