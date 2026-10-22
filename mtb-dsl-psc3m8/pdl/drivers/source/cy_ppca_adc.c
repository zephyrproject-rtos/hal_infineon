/***************************************************************************//**
* \file cy_ppca_adc.c
* \version 1.0
*
* \brief
* Provides API implementation of the PPCA ADC driver.
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

#include "cy_ppca_adc.h"
#include "cy_ppca_aref.h"

#if defined(__cplusplus)
extern "C" {
#endif
#if defined (LOAD_PPCA_TRIMS)
static void Cy_PPCA_ADC_Set_HardCoded_Trims(ATOPSS_ADC_TYPE *base, uint8_t group);
static void Cy_PPCA_AFE_Set_HardCoded_Trims(ATOPSS_AFE_TYPE *base, uint8_t group);
static void Cy_PPCA_ADC_Set_Trims(ATOPSS_ADC_TYPE *base, uint8_t group);
static void Cy_PPCA_AFE_Set_Trims(ATOPSS_AFE_TYPE *base, uint8_t group);
#endif /* defined (LOAD_PPCA_TRIMS) */

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Init
***************************************************************************//**
*
* Initializes and enables the ADC
*
* \param base The pointer to the ADC instance address.
*
* \param config The pointer to the config structure.
*
******************************************************************************/
void Cy_PPCA_ADC_Init(ATOPSS_ADC_TYPE *base, cy_stc_ppca_adc_config_t const *config)
{
    /* Input parameters verification */
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(NULL != config);

    PPCA_ATOP_ADC_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNFG_CHANNEL_EN, config->channels)      |
                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNFG_CHANNEL_TYPE, config->channel_type);
                                
    PPCA_ATOP_ADC_SIGN_UNSIGN_CNFG(base) = config->channel_data_type;
    
    PPCA_ATOP_ADC_AUX_SIGN_UNSIGN_CNFG(base) = config->aux_channel_data_type;
    
    PPCA_ATOP_ADC_AUX_ALT_SIGN_UNSIGN_CNFG(base) = config->alt_aux_channel_data_type;
    
    PPCA_ATOP_ADC_AUX_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ADC_AUX_SEL, config->aux_slot_config->aux_ch)                    |
                                   _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_SEL_SRC_N_GND, config->aux_slot_config->aux_ch_gnd)              |
                                   _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ALT_AUX_SEL_SRC, config->aux_slot_config->alt_aux_ch)            |
                                   _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ALT_AUX_SEL_SRC_GND, config->aux_slot_config->alt_aux_ch_gnd)    |
                                   _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_AUX_GND_GRP_2, config->aux_slot_config->aux_gnd_group2)              |
                                   _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ALT_AUX_GND_GRP_2, config->aux_slot_config->alt_aux_gnd_group2)      |
                                   _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ADC_AUX_GND_SEL, config->aux_slot_config->gnd_group)             |
                                   _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ADC_AUX_ALT_AUX_SEL, config->aux_slot_config->ch7_data_path);
    
    PPCA_ATOP_ADC_CNV_CNFG(base) = _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_GROUP_CH, config->adc_conv_config.group_channel)                           |
                                   _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_TRIGGER_MODE, config->adc_conv_config.trigger_mode)                         |
                                   _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_SRC_EOS, config->adc_conv_config.eos_src)                                  |
                                   _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_AUX_SLOT_SCAN_RATE, config->adc_conv_config.aux_slot_scan_rate)             |
                                   _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_EXT_SOURCE_SEL, config->adc_conv_config.ext_src);
    if(config->adc_conv_config.trigger_mode != CY_ADC_ARBITRARY_TRIGGER)
    {
        PPCA_ATOP_ADC_CNV_CNFG(base) |= _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_AUTO_TRIGGER_SAMPLE_TCLK, config->adc_conv_config.auto_trigger_sample_clck);
    }
    if(config->adc_conv_config.group_channel)
    {
        PPCA_ATOP_ADC_CNV_CNFG(base) |= _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_NUM_OF_SLOT, config->adc_conv_config.num_of_slot)                           |
                                        _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_NUM_OF_AUX_SLOT, config->adc_conv_config.num_of_aux_slot)                   |
                                        _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_NUM_OF_ALT_AUX_SLOT, config->adc_conv_config.num_of_alt_aux_slot);
    }

    PPCA_ATOP_ADC_CH_CNFG0(base) = (config->adc_conv_config.sequence_of_channel) & 0xFFFFUL;
                                   
    PPCA_ATOP_ADC_CH_CNFG1(base) = (config->adc_conv_config.sequence_of_channel >> 16U) & 0xFFFFUL;


    PPCA_ATOP_ADC_AUX_CH_CNFG0(base) = config->adc_conv_config.sequence_of_aux_channel;
    PPCA_ATOP_ADC_ALT_AUX_CH_CNFG(base) = config->adc_conv_config.sequence_of_alt_aux_channel;

    PPCA_ATOP_ADC_CTRL(base) =    _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_CALIB_GAIN_MODE, config->calib_gain_mode)      |
                                  _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_AUX_SLOT_SEL, config->aux_slot)         |
                                  _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ALT_AUX_SLOT_SEL, config->alt_aux_slot);

#if defined (LOAD_PPCA_TRIMS)
    if((uint32_t)SFLASH_SVN_ES100 <= (uint32_t)SFLASH_SVN_VALUE)
    {
        Cy_PPCA_ADC_Set_Trims(base, PPCA_GET_ADC_GROUP_NUMBER(base));
    }
    else
    {
        Cy_PPCA_ADC_Set_HardCoded_Trims(base, PPCA_GET_ADC_GROUP_NUMBER(base));
    }
#endif /* defined (LOAD_PPCA_TRIMS) */
}

/******************************************************************************
* Function Name: Cy_PPCA_AFE_Init
***************************************************************************//**
*
* Initializes AFE
*
* \param base The pointer to the AFE instance address.
*
* \param config The pointer to the config structure.
*
******************************************************************************/
void Cy_PPCA_AFE_Init(ATOPSS_AFE_TYPE *base, cy_stc_ppca_afe_config_t const *config )
{
    PPCA_ATOP_AFE_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CNFG_AFE_GAIN_SET, config->afe_gain)        |
                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CNFG_AFE_PWR_SET, config->afe_pwr)          |
                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CNFG_AFE_CLOCK_RATIO, config->afe_clk_ratio);
                               
    PPCA_ATOP_AFE_CTL(base)  = 0UL;

#if defined (LOAD_PPCA_TRIMS)
    if((uint32_t)SFLASH_SVN_ES100 <= (uint32_t)SFLASH_SVN_VALUE)
    {
        Cy_PPCA_AFE_Set_Trims(base, PPCA_GET_AFE_GROUP_NUMBER(base));
    }
    else
    {
        Cy_PPCA_AFE_Set_HardCoded_Trims(base, PPCA_GET_AFE_GROUP_NUMBER(base));
    }
#endif /* defined (LOAD_PPCA_TRIMS) */
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_DeInit
***************************************************************************//**
*
* De-Initializes and disables the ADC
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/
void Cy_PPCA_ADC_DeInit(ATOPSS_ADC_TYPE *base)
{
    PPCA_ATOP_ADC_CTRL(base) = 0U;
    PPCA_ATOP_ADC_ALT_AUX_CH_CNFG(base) = 0U;
    PPCA_ATOP_ADC_AUX_CH_CNFG1(base) = 0U;
    PPCA_ATOP_ADC_AUX_CH_CNFG0(base) = 0U;
    PPCA_ATOP_ADC_CH_CNFG0(base) = 0U;
    PPCA_ATOP_ADC_CH_CNFG1(base) = 0U;
    PPCA_ATOP_ADC_CH_CNFG2(base) = 0U;
    PPCA_ATOP_ADC_CH_CNFG3(base) = 0U;
    PPCA_ATOP_ADC_CNV_CNFG(base) = 0U;
    PPCA_ATOP_ADC_CNFG(base) = 0U;
    PPCA_ATOP_ADC_SIGN_UNSIGN_CNFG(base) = 0U;
    PPCA_ATOP_ADC_AUX_SIGN_UNSIGN_CNFG(base) = 0U;
    PPCA_ATOP_ADC_AUX_ALT_SIGN_UNSIGN_CNFG(base) = 0U;
    PPCA_ATOP_ADC_AUX_CNFG(base) = 0U;
}

/******************************************************************************
* Function Name: Cy_PPCA_AFE_DeInit
***************************************************************************//**
*
* De-Initializes and disables the AFE
*
* \param base The pointer to the AFE instance address.
*
******************************************************************************/
void Cy_PPCA_AFE_DeInit(ATOPSS_AFE_TYPE *base)
{
    PPCA_ATOP_AFE_CNFG(base) = 0U;
    PPCA_ATOP_AFE_CTL(base) = 0U;
}
#if defined (LOAD_PPCA_TRIMS)
/******************************************************************************
* Function Name: Cy_PPCA_ADC_Set_HardCoded_Trims
***************************************************************************//**
*
* Initialize trim values for ADC
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/

static void Cy_PPCA_ADC_Set_HardCoded_Trims(ATOPSS_ADC_TYPE *base, uint8_t group)
{
    uint32_t offset = 0;
    if(CY_EXTERNALLY_SUPPLIED_VREF == Cy_PPCA_AREF_Get_VREF_Source(PPCA_ATOPSS_ADC_GRP0_AREF))
    {
        offset = SFLASH_EXTERNAL_VREF_OFFSET;
    }
    switch(group)
    {
        case 0:
        {
            PPCA_ATOP_ADC_STARTUPCTRL(base)  = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_VTOICAL_TRIM, SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM(offset));
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 16, \
'Intentional pointer type conversion to access CALOFFSET registers')
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(0U)), SFLASH_GRP0_ADC_CALOFFSET(0, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(1U)), SFLASH_GRP0_ADC_CALOFFSET(1, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(2U)), SFLASH_GRP0_ADC_CALOFFSET(2, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(3U)), SFLASH_GRP0_ADC_CALOFFSET(3, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(4U)), SFLASH_GRP0_ADC_CALOFFSET(4, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(5U)), SFLASH_GRP0_ADC_CALOFFSET(5, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(6U)), SFLASH_GRP0_ADC_CALOFFSET(6, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(7U)), SFLASH_GRP0_ADC_CALOFFSET(7, offset));

            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(0U)), SFLASH_GRP0_ADC_CALGAIN_GAINX1(0, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(1U)), SFLASH_GRP0_ADC_CALGAIN_GAINX1(1, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(2U)), SFLASH_GRP0_ADC_CALGAIN_GAINX1(2, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(3U)), SFLASH_GRP0_ADC_CALGAIN_GAINX1(3, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(4U)), SFLASH_GRP0_ADC_CALGAIN_GAINX1(4, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(5U)), SFLASH_GRP0_ADC_CALGAIN_GAINX1(5, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(6U)), SFLASH_GRP0_ADC_CALGAIN_GAINX1(6, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(7U)), SFLASH_GRP0_ADC_CALGAIN_GAINX1(7, offset));
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')
        }
        break;
        case 1:
        {
            PPCA_ATOP_ADC_STARTUPCTRL(base)  = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_VTOICAL_TRIM, SFLASH_GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM(offset));
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 8, \
'Intentional pointer type conversion to access CALOFFSET registers')
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(0U)), SFLASH_GRP1_ADC_CALOFFSET(0, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(1U)), SFLASH_GRP1_ADC_CALOFFSET(1, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(2U)), SFLASH_GRP1_ADC_CALOFFSET(2, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(3U)), SFLASH_GRP1_ADC_CALOFFSET(3, offset));

            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(0U)), SFLASH_GRP1_ADC_CALGAIN_GAINX1(0, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(1U)), SFLASH_GRP1_ADC_CALGAIN_GAINX1(1, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(2U)), SFLASH_GRP1_ADC_CALGAIN_GAINX1(2, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(3U)), SFLASH_GRP1_ADC_CALGAIN_GAINX1(3, offset));
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')
        }
        break;
        case 2:
        {
            PPCA_ATOP_ADC_STARTUPCTRL(base)  = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_VTOICAL_TRIM, SFLASH_GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM(offset));
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 8, \
'Intentional pointer type conversion to access CALOFFSET registers')
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(0U)), SFLASH_GRP2_ADC_CALOFFSET(0, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(1U)), SFLASH_GRP2_ADC_CALOFFSET(1, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(2U)), SFLASH_GRP2_ADC_CALOFFSET(2, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(3U)), SFLASH_GRP2_ADC_CALOFFSET(3, offset));

            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(0U)), SFLASH_GRP2_ADC_CALGAIN_GAINX1(0, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(1U)), SFLASH_GRP2_ADC_CALGAIN_GAINX1(1, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(2U)), SFLASH_GRP2_ADC_CALGAIN_GAINX1(2, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(3U)), SFLASH_GRP2_ADC_CALGAIN_GAINX1(3, offset));
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')
        }
        break;
        case 3:
        {
            PPCA_ATOP_ADC_STARTUPCTRL(base)  = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_VTOICAL_TRIM, SFLASH_GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM(offset));
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 16, \
'Intentional pointer type conversion to access CALOFFSET registers')
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(0U)), SFLASH_GRP3_ADC_CALOFFSET(0, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(1U)), SFLASH_GRP3_ADC_CALOFFSET(1, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(2U)), SFLASH_GRP3_ADC_CALOFFSET(2, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(3U)), SFLASH_GRP3_ADC_CALOFFSET(3, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(4U)), SFLASH_GRP3_ADC_CALOFFSET(4, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(5U)), SFLASH_GRP3_ADC_CALOFFSET(5, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(6U)), SFLASH_GRP3_ADC_CALOFFSET(6, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALOFFSET_OFFSET(7U)), SFLASH_GRP3_ADC_CALOFFSET(7, offset));

            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(0U)), SFLASH_GRP3_ADC_CALGAIN_GAINX1(0, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(1U)), SFLASH_GRP3_ADC_CALGAIN_GAINX1(1, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(2U)), SFLASH_GRP3_ADC_CALGAIN_GAINX1(2, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(3U)), SFLASH_GRP3_ADC_CALGAIN_GAINX1(3, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(4U)), SFLASH_GRP3_ADC_CALGAIN_GAINX1(4, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(5U)), SFLASH_GRP3_ADC_CALGAIN_GAINX1(5, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(6U)), SFLASH_GRP3_ADC_CALGAIN_GAINX1(6, offset));
            CY_SET_REG32((base + PPCA_ATOP_ADC_CALGAIN_OFFSET(7U)), SFLASH_GRP3_ADC_CALGAIN_GAINX1(7, offset));
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')
        }
        break;
        default :
        {
            /* nothing to do */
        }
        break;

    }
}

/******************************************************************************
* Function Name: Cy_PPCA_AFE_Set_HardCoded_Trims
***************************************************************************//**
*
* Initialize trim values for AFE
*
* \param base The pointer to the AFE instance address.
*
******************************************************************************/
/* Hard coding the values for all AFE Gain. please remove the hardcoded values when this gets fixed in the production silicon */
static void Cy_PPCA_AFE_Set_HardCoded_Trims(ATOPSS_AFE_TYPE *base, uint8_t group)
{
    uint32_t offset = 0;
    if(CY_EXTERNALLY_SUPPLIED_VREF == Cy_PPCA_AREF_Get_VREF_Source(PPCA_ATOPSS_ADC_GRP0_AREF))
    {
        offset = SFLASH_EXTERNAL_VREF_OFFSET;
    }
    switch(group)
    {
        case 0:
        {
            PPCA_ATOP_AFE_CALGAINAFE_1(base)   = 0x04000400; //SFLASH_GRP0_AFE_CALGAIN_AFE_1(offset);
            PPCA_ATOP_AFE_CALGAINAFE_2(base)   = 0x04000400; //SFLASH_GRP0_AFE_CALGAIN_AFE_2(offset);
            PPCA_ATOP_AFE_CALGAINAFE_3(base)   = 0x04000400; //SFLASH_GRP0_AFE_CALGAIN_AFE_3(offset);
            PPCA_ATOP_AFE_CALGAINAFE_4(base)   = 0x04000400; //SFLASH_GRP0_AFE_CALGAIN_AFE_4(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_1(base) = SFLASH_GRP0_AFE_CALOFFSET_AFE_1(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_2(base) = SFLASH_GRP0_AFE_CALOFFSET_AFE_2(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_3(base) = SFLASH_GRP0_AFE_CALOFFSET_AFE_3(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_4(base) = SFLASH_GRP0_AFE_CALOFFSET_AFE_4(offset);
        }
        break;
        case 1:
        {
            PPCA_ATOP_AFE_CALGAINAFE_1(base)   = 0x04000400; //SFLASH_GRP1_AFE_CALGAIN_AFE_1(offset);
            PPCA_ATOP_AFE_CALGAINAFE_2(base)   = 0x04000400; //SFLASH_GRP1_AFE_CALGAIN_AFE_2(offset);
            PPCA_ATOP_AFE_CALGAINAFE_3(base)   = 0x04000400; //SFLASH_GRP1_AFE_CALGAIN_AFE_3(offset);
            PPCA_ATOP_AFE_CALGAINAFE_4(base)   = 0x04000400; //SFLASH_GRP1_AFE_CALGAIN_AFE_4(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_1(base) = SFLASH_GRP1_AFE_CALOFFSET_AFE_1(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_2(base) = SFLASH_GRP1_AFE_CALOFFSET_AFE_2(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_3(base) = SFLASH_GRP1_AFE_CALOFFSET_AFE_3(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_4(base) = SFLASH_GRP1_AFE_CALOFFSET_AFE_4(offset);
        }
        break;
        case 2:
        {
            PPCA_ATOP_AFE_CALGAINAFE_1(base)   = 0x04000400; //SFLASH_GRP2_AFE_CALGAIN_AFE_1(offset);
            PPCA_ATOP_AFE_CALGAINAFE_2(base)   = 0x04000400; //SFLASH_GRP2_AFE_CALGAIN_AFE_2(offset);
            PPCA_ATOP_AFE_CALGAINAFE_3(base)   = 0x04000400; //SFLASH_GRP2_AFE_CALGAIN_AFE_3(offset);
            PPCA_ATOP_AFE_CALGAINAFE_4(base)   = 0x04000400; //SFLASH_GRP2_AFE_CALGAIN_AFE_4(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_1(base) = SFLASH_GRP2_AFE_CALOFFSET_AFE_1(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_2(base) = SFLASH_GRP2_AFE_CALOFFSET_AFE_2(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_3(base) = SFLASH_GRP2_AFE_CALOFFSET_AFE_3(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_4(base) = SFLASH_GRP2_AFE_CALOFFSET_AFE_4(offset);
        }
        break;
        case 3:
        {
            PPCA_ATOP_AFE_CALGAINAFE_1(base)   = 0x04000400; //SFLASH_GRP3_AFE_CALGAIN_AFE_1(offset);
            PPCA_ATOP_AFE_CALGAINAFE_2(base)   = 0x04000400; //SFLASH_GRP3_AFE_CALGAIN_AFE_2(offset);
            PPCA_ATOP_AFE_CALGAINAFE_3(base)   = 0x04000400; //SFLASH_GRP3_AFE_CALGAIN_AFE_3(offset);
            PPCA_ATOP_AFE_CALGAINAFE_4(base)   = 0x04000400; //SFLASH_GRP3_AFE_CALGAIN_AFE_4(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_1(base) = SFLASH_GRP3_AFE_CALOFFSET_AFE_1(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_2(base) = SFLASH_GRP3_AFE_CALOFFSET_AFE_2(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_3(base) = SFLASH_GRP3_AFE_CALOFFSET_AFE_3(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_4(base) = SFLASH_GRP3_AFE_CALOFFSET_AFE_4(offset);
        }
        break;
        default :
        {
            /* nothing to do */
        }
        break;

    }
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Set_Trims
***************************************************************************//**
*
* Initialize trim values for ADC
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/
static void Cy_PPCA_ADC_Set_Trims(ATOPSS_ADC_TYPE *base, uint8_t group)
{
    uint32_t offset = 0;
    if(CY_EXTERNALLY_SUPPLIED_VREF == Cy_PPCA_AREF_Get_VREF_Source(PPCA_ATOPSS_ADC_GRP0_AREF))
    {
        offset = SFLASH_EXTERNAL_VREF_OFFSET;
    }
    switch(group)
    {
        case 0:
        {
            PPCA_ATOP_ADC_STARTUPCTRL(base) = SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM(offset);

            PPCA_ATOP_ADC_CALOFFSET(base, 0U) = SFLASH_GRP0_ADC_CALOFFSET(0, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 1U) = SFLASH_GRP0_ADC_CALOFFSET(1, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 2U) = SFLASH_GRP0_ADC_CALOFFSET(2, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 3U) = SFLASH_GRP0_ADC_CALOFFSET(3, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 4U) = SFLASH_GRP0_ADC_CALOFFSET(4, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 5U) = SFLASH_GRP0_ADC_CALOFFSET(5, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 6U) = SFLASH_GRP0_ADC_CALOFFSET(6, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 7U) = SFLASH_GRP0_ADC_CALOFFSET(7, offset);

            PPCA_ATOP_ADC_CALGAIN(base, 0U) = SFLASH_GRP0_ADC_CALGAIN_GAINX1(0, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 1U) = SFLASH_GRP0_ADC_CALGAIN_GAINX1(1, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 2U) = SFLASH_GRP0_ADC_CALGAIN_GAINX1(2, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 3U) = SFLASH_GRP0_ADC_CALGAIN_GAINX1(3, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 4U) = SFLASH_GRP0_ADC_CALGAIN_GAINX1(4, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 5U) = SFLASH_GRP0_ADC_CALGAIN_GAINX1(5, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 6U) = SFLASH_GRP0_ADC_CALGAIN_GAINX1(6, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 7U) = SFLASH_GRP0_ADC_CALGAIN_GAINX1(7, offset);
        }
        break;
        case 1:
        {
            PPCA_ATOP_ADC_STARTUPCTRL(base)  = SFLASH_GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM(offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 0U) = SFLASH_GRP1_ADC_CALOFFSET(0, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 1U) = SFLASH_GRP1_ADC_CALOFFSET(1, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 2U) = SFLASH_GRP1_ADC_CALOFFSET(2, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 3U) = SFLASH_GRP1_ADC_CALOFFSET(3, offset);

            PPCA_ATOP_ADC_CALGAIN(base, 0U) = SFLASH_GRP1_ADC_CALGAIN_GAINX1(0, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 1U) = SFLASH_GRP1_ADC_CALGAIN_GAINX1(1, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 2U) = SFLASH_GRP1_ADC_CALGAIN_GAINX1(2, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 3U) = SFLASH_GRP1_ADC_CALGAIN_GAINX1(3, offset);
        }
        break;
        case 2:
        {
            PPCA_ATOP_ADC_STARTUPCTRL(base)  = SFLASH_GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM(offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 0U) = SFLASH_GRP2_ADC_CALOFFSET(0, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 1U) = SFLASH_GRP2_ADC_CALOFFSET(1, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 2U) = SFLASH_GRP2_ADC_CALOFFSET(2, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 3U) = SFLASH_GRP2_ADC_CALOFFSET(3, offset);

            PPCA_ATOP_ADC_CALGAIN(base, 0U) = SFLASH_GRP2_ADC_CALGAIN_GAINX1(0, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 1U) = SFLASH_GRP2_ADC_CALGAIN_GAINX1(1, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 2U) = SFLASH_GRP2_ADC_CALGAIN_GAINX1(2, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 3U) = SFLASH_GRP2_ADC_CALGAIN_GAINX1(3, offset);
        }
        break;
        case 3:
        {
            PPCA_ATOP_ADC_STARTUPCTRL(base)  = SFLASH_GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM(offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 0U) = SFLASH_GRP3_ADC_CALOFFSET(0, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 1U) = SFLASH_GRP3_ADC_CALOFFSET(1, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 2U) = SFLASH_GRP3_ADC_CALOFFSET(2, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 3U) = SFLASH_GRP3_ADC_CALOFFSET(3, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 4U) = SFLASH_GRP3_ADC_CALOFFSET(4, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 5U) = SFLASH_GRP3_ADC_CALOFFSET(5, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 6U) = SFLASH_GRP3_ADC_CALOFFSET(6, offset);
            PPCA_ATOP_ADC_CALOFFSET(base, 7U) = SFLASH_GRP3_ADC_CALOFFSET(7, offset);

            PPCA_ATOP_ADC_CALGAIN(base, 0U) = SFLASH_GRP3_ADC_CALGAIN_GAINX1(0, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 1U) = SFLASH_GRP3_ADC_CALGAIN_GAINX1(1, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 2U) = SFLASH_GRP3_ADC_CALGAIN_GAINX1(2, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 3U) = SFLASH_GRP3_ADC_CALGAIN_GAINX1(3, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 4U) = SFLASH_GRP3_ADC_CALGAIN_GAINX1(4, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 5U) = SFLASH_GRP3_ADC_CALGAIN_GAINX1(5, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 6U) = SFLASH_GRP3_ADC_CALGAIN_GAINX1(6, offset);
            PPCA_ATOP_ADC_CALGAIN(base, 7U) = SFLASH_GRP3_ADC_CALGAIN_GAINX1(7, offset);
        }
        break;
        default :
        {
            /* nothing to do */
        }
        break;
    
    }
}

/******************************************************************************
* Function Name: Cy_PPCA_AFE_Set_Trims
***************************************************************************//**
*
* Initialize trim values for AFE
*
* \param base The pointer to the AFE instance address.
*
******************************************************************************/
static void Cy_PPCA_AFE_Set_Trims(ATOPSS_AFE_TYPE *base, uint8_t group)
{
    uint32_t offset = 0;
    if(CY_EXTERNALLY_SUPPLIED_VREF == Cy_PPCA_AREF_Get_VREF_Source(PPCA_ATOPSS_ADC_GRP0_AREF))
    {
        offset = SFLASH_EXTERNAL_VREF_OFFSET;
    }
    switch(group)
    {
        case 0:
        {
            PPCA_ATOP_AFE_CALGAINAFE_1(base)   = SFLASH_GRP0_AFE_CALGAIN_AFE_1(offset);
            PPCA_ATOP_AFE_CALGAINAFE_2(base)   = SFLASH_GRP0_AFE_CALGAIN_AFE_2(offset);
            PPCA_ATOP_AFE_CALGAINAFE_3(base)   = SFLASH_GRP0_AFE_CALGAIN_AFE_3(offset);
            PPCA_ATOP_AFE_CALGAINAFE_4(base)   = SFLASH_GRP0_AFE_CALGAIN_AFE_4(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_1(base) = SFLASH_GRP0_AFE_CALOFFSET_AFE_1(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_2(base) = SFLASH_GRP0_AFE_CALOFFSET_AFE_2(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_3(base) = SFLASH_GRP0_AFE_CALOFFSET_AFE_3(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_4(base) = SFLASH_GRP0_AFE_CALOFFSET_AFE_4(offset);
        }
        break;
        case 1:
        {
            PPCA_ATOP_AFE_CALGAINAFE_1(base)   = SFLASH_GRP1_AFE_CALGAIN_AFE_1(offset);
            PPCA_ATOP_AFE_CALGAINAFE_2(base)   = SFLASH_GRP1_AFE_CALGAIN_AFE_2(offset);
            PPCA_ATOP_AFE_CALGAINAFE_3(base)   = SFLASH_GRP1_AFE_CALGAIN_AFE_3(offset);
            PPCA_ATOP_AFE_CALGAINAFE_4(base)   = SFLASH_GRP1_AFE_CALGAIN_AFE_4(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_1(base) = SFLASH_GRP1_AFE_CALOFFSET_AFE_1(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_2(base) = SFLASH_GRP1_AFE_CALOFFSET_AFE_2(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_3(base) = SFLASH_GRP1_AFE_CALOFFSET_AFE_3(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_4(base) = SFLASH_GRP1_AFE_CALOFFSET_AFE_4(offset);
        }
        break;
        case 2:
        {
            PPCA_ATOP_AFE_CALGAINAFE_1(base)   = SFLASH_GRP2_AFE_CALGAIN_AFE_1(offset);
            PPCA_ATOP_AFE_CALGAINAFE_2(base)   = SFLASH_GRP2_AFE_CALGAIN_AFE_2(offset);
            PPCA_ATOP_AFE_CALGAINAFE_3(base)   = SFLASH_GRP2_AFE_CALGAIN_AFE_3(offset);
            PPCA_ATOP_AFE_CALGAINAFE_4(base)   = SFLASH_GRP2_AFE_CALGAIN_AFE_4(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_1(base) = SFLASH_GRP2_AFE_CALOFFSET_AFE_1(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_2(base) = SFLASH_GRP2_AFE_CALOFFSET_AFE_2(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_3(base) = SFLASH_GRP2_AFE_CALOFFSET_AFE_3(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_4(base) = SFLASH_GRP2_AFE_CALOFFSET_AFE_4(offset);
        }
        break;
        case 3:
        {
            PPCA_ATOP_AFE_CALGAINAFE_1(base)   = SFLASH_GRP3_AFE_CALGAIN_AFE_1(offset);
            PPCA_ATOP_AFE_CALGAINAFE_2(base)   = SFLASH_GRP3_AFE_CALGAIN_AFE_2(offset);
            PPCA_ATOP_AFE_CALGAINAFE_3(base)   = SFLASH_GRP3_AFE_CALGAIN_AFE_3(offset);
            PPCA_ATOP_AFE_CALGAINAFE_4(base)   = SFLASH_GRP3_AFE_CALGAIN_AFE_4(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_1(base) = SFLASH_GRP3_AFE_CALOFFSET_AFE_1(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_2(base) = SFLASH_GRP3_AFE_CALOFFSET_AFE_2(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_3(base) = SFLASH_GRP3_AFE_CALOFFSET_AFE_3(offset);
            PPCA_ATOP_AFE_CALOFFSETAFE_4(base) = SFLASH_GRP3_AFE_CALOFFSET_AFE_4(offset);
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
