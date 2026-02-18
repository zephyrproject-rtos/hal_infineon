/***************************************************************************//**
* \file cy_ppca_adc_filter.c
* \version 1.0
*
* \brief
* Provides API implementation of the PPCA ADC Filter driver.
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

#include "cy_ppca_adc_filter.h"

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_Init
***************************************************************************//**
*
* Initializes and enables the ADC Filter
*
* \param base The pointer to the ADC filter instance address.
*
* \param config The pointer to the config structure.
*
******************************************************************************/
void Cy_PPCA_ADC_Filter_Init(ATOPSS_ADCFLT_TYPE *base, cy_stc_ppca_adc_filter_config_t const *config)
{
    /* Input parameters verification */
    CY_ASSERT(NULL != base);
    CY_ASSERT(NULL != config);

    PPCA_ATOP_AFLT_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_SRC_CH, config->src_ch)                              |
                                _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_MIN_MAX_SAMPLE_SEARCH, config->min_max_sample_search)    |
                                _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SOURCE_MIN_MAX_SAMPLE_SEARCH, config->min_max_source)   |
                                _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_MEDIAN, config->median_filter_bypass)               |
                                _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_LIF, config->linear_filter_bypass)                  |
                                _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_AVG, config->average_filter_bypass)                 |
                                _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_CIC, config->cic_filter_bypass)                     |
                                _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_LPF, config->lpf_filter_bypass)                     |
                                _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_SRC_ADC_FILT, config->src_adc);
                                
    PPCA_ATOP_AFLT_LPF_ALFA(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_LPF_ALFA_BW, config->lpf_bandwidth);
    
    PPCA_ATOP_AFLT_CICF_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CLK_DIV, config->cic_clck_div)                      |
                                     _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_DEC, config->cic_decimation_factor)            |
                                     _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_DEC_OFFSET, config->cic_decimation_offset)     |
                                     _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_DEC_SCALE, config->cic_decimation_scale)       |
                                     _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_SEL_SRC, config->cic_src_type)                     |
                                     _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_CMP_EN, config->cic_digital_comparator_enable);
                                     
    PPCA_ATOP_AFLT_CICF_UB_TH(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_CICF_UB_TH_CICF_UB_TH, config->cic_UB_threshold);
    PPCA_ATOP_AFLT_CICF_LB_TH(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_CICF_LB_TH_CICF_LB_TH, config->cic_LB_threshold);
    
    PPCA_ATOP_AFLT_AVGF_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CNFG_M, config->avg_no_of_samples)                       |
                                     _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CNFG_K, config->avg_linear_or_squared)                  |
                                     _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CNFG_SEL_W_TYPE, config->avg_fix_or_dynamic_sample);
   
    PPCA_ATOP_AFLT_LIF_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_LIF_CNFG_M_FACTOR, config->lif_m_factor)                       |
                                    _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_LIF_CNFG_INTP_EXTP_SEL, config->lif_intp_extp_sel);

    PPCA_ATOP_AFLT_CTL(base) =    _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_UNSIGN_PATH_EN, config->unsign_path_enable)            |
                                  _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_MIN_MAX_DET_EN, config->min_max_detection_enable)      |
                                  _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_MED_EN, config->median_filter_enable)                  |
                                  _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_LIF_EN, config->linear_filter_enable)                  |
                                  _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_AVG_EN, config->average_filter_enable)                 |
                                  _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_CIC_EN, config->cic_filter_enable)                     |
                                  _BOOL2FLD(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_LPF_EN, config->lpf_filter_enable);

}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_DeInit
***************************************************************************//**
*
* De-Initializes and disables the ADC Filter
*
* \param base The pointer to the ADC filter instance address.
*
******************************************************************************/
void Cy_PPCA_ADC_Filter_DeInit(ATOPSS_ADCFLT_TYPE *base)
{
    PPCA_ATOP_AFLT_CTL(base)         = 0U;
    PPCA_ATOP_AFLT_LIF_CNFG(base)    = 0U;
    PPCA_ATOP_AFLT_AVGF_CNFG(base)   = 0U;
    PPCA_ATOP_AFLT_CICF_UB_TH(base)  = 0U;
    PPCA_ATOP_AFLT_CICF_LB_TH(base)  = 0U;
    PPCA_ATOP_AFLT_CICF_CNFG(base)   = 0U;
    PPCA_ATOP_AFLT_LPF_ALFA(base)    = 0U;
    PPCA_ATOP_AFLT_CNFG(base)        = 0U;
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40PPSS */

/* [] END OF FILE */
