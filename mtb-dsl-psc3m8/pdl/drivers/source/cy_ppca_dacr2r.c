/***************************************************************************//**
* \file cy_ppca_dacr2r.c
* \version 1.0
*
* \brief
* Provides API implementation of the PPCA DAC R2R driver.
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

#include "cy_ppca_dacr2r.h"
#include "cy_ppca_aref.h"

#if defined(__cplusplus)
extern "C" {
#endif
#if defined (LOAD_PPCA_TRIMS)
static void Cy_PPCA_DACR2R_Set_Trims(ATOPSS_DAC_TYPE *base, uint8_t group);
#endif /* defined (LOAD_PPCA_TRIMS) */
/******************************************************************************
* Function Name: Cy_PPCA_DAC_Init
***************************************************************************//**
*
* Initializes and enables the DAC
*
* \param base The pointer to the DACR2R instance address.
*
******************************************************************************/
void Cy_PPCA_DAC_Init(ATOPSS_DAC_TYPE *base, cy_stc_ppca_dacr2r_config_t const *config )
{
    /* Input parameters verification */
    CY_ASSERT(NULL != base);
    CY_ASSERT(NULL != config);

    PPCA_ATOP_DAC_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_R2RDAC_CNFG, config->dacr2r_cnfg)                        |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_DAC_OFFSET_DIS, config->offset_correction_disable)      |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_DAC_GAIN_DIS, config->gain_correction_disable)          |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_BUF_OFFSET_DIS, config->buf_offset_correction_disable)  |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_EN_VREF_TO_BUF, config->vref_to_buf_enable)             |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_EN_DAC_O_TO_BUF, config->dac_out_to_buf_enable);

    PPCA_ATOP_DAC_CTL(base) |=  _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CTL_DAC_EN, 0U)                    |
                                _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CTL_DAC_BUFF_EN, config->dac_buf_enable);

#if defined (LOAD_PPCA_TRIMS)

    Cy_PPCA_DACR2R_Set_Trims(base, PPCA_GET_DACR2R_GROUP_NUMBER(base));

#endif /* defined (LOAD_PPCA_TRIMS) */
}


#if defined (LOAD_PPCA_TRIMS)
/******************************************************************************
* Function Name: Cy_PPCA_DACR2R_Set_Trims
***************************************************************************//**
*
* Initialize trim values for DACR2R
*
* \param base The pointer to the DACR2R instance address.
*
******************************************************************************/

static void Cy_PPCA_DACR2R_Set_Trims(ATOPSS_DAC_TYPE *base, uint8_t group)
{
    uint32_t offset = 0U;
    if(CY_EXTERNALLY_SUPPLIED_VREF == Cy_PPCA_AREF_Get_VREF_Source(PPCA_ATOPSS_ADC_GRP0_AREF))
    {
        offset = SFLASH_EXTERNAL_VREF_DAC_OFFSET;
    }
    switch(group)
    {
        case 0:
        {
            PPCA_ATOP_DAC_OFFSET_CNFG1(base) =  SFLASH_GRP0_DAC_OFFSET_CNFG1(offset);
            PPCA_ATOP_DAC_OFFSET_CNFG2(base) =  SFLASH_GRP0_DAC_OFFSET_CNFG2(offset);
            PPCA_ATOP_DAC_OFFSET_CNFG3(base) =  SFLASH_GRP0_DAC_OFFSET_CNFG3(offset);
            PPCA_ATOP_DAC_OFFSET_CNFG4(base) =  SFLASH_GRP0_DAC_OFFSET_CNFG4(offset);
            PPCA_ATOP_DAC_OFFSET_CNFG5(base) =  SFLASH_GRP0_DAC_OFFSET_CNFG5(offset);
            PPCA_ATOP_DAC_GAIN_CNFG1(base)   =  SFLASH_GRP0_DAC_GAIN_CNFG1(offset);
            PPCA_ATOP_DAC_GAIN_CNFG2(base)   =  SFLASH_GRP0_DAC_GAIN_CNFG2(offset);
            PPCA_ATOP_DAC_GAIN_CNFG3(base)   =  SFLASH_GRP0_DAC_GAIN_CNFG3(offset);
            PPCA_ATOP_DAC_GAIN_CNFG4(base)   =  SFLASH_GRP0_DAC_GAIN_CNFG4(offset);
            PPCA_ATOP_DAC_GAIN_CNFG5(base)   =  SFLASH_GRP0_DAC_GAIN_CNFG5(offset);
            PPCA_ATOP_BUFFER_OFFSET_1(base)  =  SFLASH_GRP0_BUFFER_OFFSET_1(offset);
            PPCA_ATOP_BUFFER_OFFSET_2(base)  =  SFLASH_GRP0_BUFFER_OFFSET_2(offset);
        }
        break;
        case 1:
        {
            PPCA_ATOP_DAC_OFFSET_CNFG1(base) =  SFLASH_GRP1_DAC_OFFSET_CNFG1(offset);
            PPCA_ATOP_DAC_OFFSET_CNFG2(base) =  SFLASH_GRP1_DAC_OFFSET_CNFG2(offset);
            PPCA_ATOP_DAC_OFFSET_CNFG3(base) =  SFLASH_GRP1_DAC_OFFSET_CNFG3(offset);
            PPCA_ATOP_DAC_OFFSET_CNFG4(base) =  SFLASH_GRP1_DAC_OFFSET_CNFG4(offset);
            PPCA_ATOP_DAC_OFFSET_CNFG5(base) =  SFLASH_GRP1_DAC_OFFSET_CNFG5(offset);
            PPCA_ATOP_DAC_GAIN_CNFG1(base)   =  SFLASH_GRP1_DAC_GAIN_CNFG1(offset);
            PPCA_ATOP_DAC_GAIN_CNFG2(base)   =  SFLASH_GRP1_DAC_GAIN_CNFG2(offset);
            PPCA_ATOP_DAC_GAIN_CNFG3(base)   =  SFLASH_GRP1_DAC_GAIN_CNFG3(offset);
            PPCA_ATOP_DAC_GAIN_CNFG4(base)   =  SFLASH_GRP1_DAC_GAIN_CNFG4(offset);
            PPCA_ATOP_DAC_GAIN_CNFG5(base)   =  SFLASH_GRP1_DAC_GAIN_CNFG5(offset);
            PPCA_ATOP_BUFFER_OFFSET_1(base)  =  SFLASH_GRP1_BUFFER_OFFSET_1(offset);
            PPCA_ATOP_BUFFER_OFFSET_2(base)  =  SFLASH_GRP1_BUFFER_OFFSET_2(offset);
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
