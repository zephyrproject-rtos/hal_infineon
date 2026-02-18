/***************************************************************************//**
* \file cy_ppca_adc_filter.h
* \version 1.0
*
* The header file of the PPCA ADC Filter driver.
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


#if !defined(CY_PPCA_ADC_FILTER_H)
#define CY_PPCA_ADC_FILTER_H

#include "cy_device.h"

#if defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN)

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_ppca_adc_filter
* The ADC Filter driver provides an interface to the digital filter chain
* attached to each ADC group within the ATOPSS. Each ADC group has 2 filter
* instances (AFLT) that can be individually configured to post-process the
* raw ADC conversion results in hardware.
*
* \section group_ppca_adc_filter_overview Overview
*
* The filter chain processes the ADC output through the following stages
* (each stage can be individually bypassed):
*
* <b>Filter Pipeline:</b>
* \code
*   ADC_DATA -> MEDIAN -> LINTP -> LP -> CIC3 -> AVG
*                 |
*                 +---> MIN/MAX detection
* \endcode
*
* - <b>Median Filter:</b> Removes impulse noise from the ADC output stream.
*   Can serve as the source for MIN/MAX detection.
* - <b>Linear Interpolation Filter (LINTP/LIF):</b> Up-samples the ADC data
*   between conversion events. The M-factor sets the interpolation ratio
*   (2, 4, 8, 16, 32, 64, 128, or 256). Supports both interpolation and
*   extrapolation modes.
* - <b>Low-Pass Filter (LP):</b> First-order IIR low-pass filter with
*   configurable bandwidth.
* - <b>CIC3 Filter:</b> Cascaded Integrator-Comb filter of 3rd order with
*   configurable decimation factor, offset, and scaling. Supports both
*   internal (post-LPF) and external data sources with programmable clock
*   divider. Includes an optional digital comparator with upper/lower bound
*   thresholds.
* - <b>Averaging Filter (AVG):</b> Accumulates samples over a configurable
*   window. Supports linear (K=1) or squared (K=2) accumulation and
*   fixed or dynamic sample windows.
* - <b>MIN/MAX Detection:</b> Tracks minimum and maximum values in the ADC
*   data stream within a configurable search window (open, 16, 64, or
*   256 sample points). Reading the MIN/MAX register restarts the search.
*
* \{
*/

/**
* \defgroup group_ppca_adc_filter_macros                Macros
* \defgroup group_ppca_adc_filter_functions             Functions
* \defgroup group_ppca_adc_filter_data_structures Data Structures
* \} */

/**
* \addtogroup group_ppca_adc_filter_macros
* \{
*/
/** ADC Filter Type */
#define ATOPSS_ADCFLT_TYPE PPCA_ATOPSS_ADC_GRP_AFLT_Type

/** \} group_ppca_adc_filter_macros */

/**
* \addtogroup group_ppca_adc_filter_data_structures
* \{
*/

/** To define the maximum number of clock cycle between two SoC for the ADC Conversion. */
typedef enum
{
    CY_LIF_MFACTOR_SET_TO_2       = 0UL,        /**<Linear Interpolation Filter M-Factor set to 2.  */
    CY_LIF_MFACTOR_SET_TO_4       = 1UL,        /**<Linear Interpolation Filter M-Factor set to 4.  */
    CY_LIF_MFACTOR_SET_TO_8       = 2UL,        /**<Linear Interpolation Filter M-Factor set to 8.  */
    CY_LIF_MFACTOR_SET_TO_16      = 3UL,        /**<Linear Interpolation Filter M-Factor set to 16. */
    CY_LIF_MFACTOR_SET_TO_32      = 4UL,        /**<Linear Interpolation Filter M-Factor set to 32. */
    CY_LIF_MFACTOR_SET_TO_64      = 5UL,        /**<Linear Interpolation Filter M-Factor set to 64. */
    CY_LIF_MFACTOR_SET_TO_128     = 6UL,        /**<Linear Interpolation Filter M-Factor set to 128.*/
    CY_LIF_MFACTOR_SET_TO_256     = 7UL,        /**<Linear Interpolation Filter M-Factor set to 256.*/
} cy_en_lif_m_factor_t;

/** CIC filter Clock Divider for external source sampling. */
typedef enum
{
    CY_CIC_PPCACLK_DIV_BY_4       = 0UL,        /**<CIC Filter Clock Divider for external source sampling PPCA_CLK/4.   */
    CY_CIC_PPCACLK_DIV_BY_8       = 1UL,        /**<CIC Filter Clock Divider for external source sampling PPCA_CLK/8.   */
    CY_CIC_PPCACLK_DIV_BY_16      = 2UL,        /**<CIC Filter Clock Divider for external source sampling PPCA_CLK/16.  */
    CY_CIC_PPCACLK_DIV_BY_32      = 3UL,        /**<CIC Filter Clock Divider for external source sampling PPCA_CLK/32.  */
    CY_CIC_PPCACLK_DIV_BY_64      = 4UL,        /**<CIC Filter Clock Divider for external source sampling PPCA_CLK/64.  */
    CY_CIC_PPCACLK_DIV_BY_128     = 5UL,        /**<CIC Filter Clock Divider for external source sampling PPCA_CLK/128. */
    CY_CIC_PPCACLK_DIV_BY_256     = 6UL,        /**<CIC Filter Clock Divider for external source sampling PPCA_CLK/256. */
    CY_CIC_PPCACLK_DIV_BY_512     = 7UL,        /**<CIC Filter Clock Divider for external source sampling PPCA_CLK/512. */
} cy_en_cic_clck_div_t;

/** Min Max Filter Sample Search Window Configuration. */
typedef enum
{
    CY_SAMPLE_SEARCH_WINDOW_OPEN            = 0UL,        /**<Min/Max Filter sample search window Open.         */
    CY_SAMPLE_SEARCH_WINDOW_16_POINTS       = 1UL,        /**<Min/Max Filter sample search window 16 points .   */
    CY_SAMPLE_SEARCH_WINDOW_64_POINTS       = 2UL,        /**<Min/Max Filter sample search window 64 points .   */
    CY_SAMPLE_SEARCH_WINDOW_256_POINTS      = 3UL,        /**<Min/Max Filter sample search window 256 points .  */
} cy_en_min_max_search_window_t;


/** PPCA ADC Filter configuration structure */
typedef struct cy_stc_ppca_adc_filter_config
{
    bool              median_filter_enable;                          /**< Enable/Disable Median Filter. */
    bool              linear_filter_enable;                          /**< Enable/Disable Linear Interpolation Filter. */
    bool              average_filter_enable;                         /**< Enable/Disable Configurable Average Filter. */
    bool              cic_filter_enable;                             /**< Enable/Disable  Cascade Integrator 3rd order Comb Filter. */
    bool              lpf_filter_enable;                             /**< Enable/Disable  Low Pass Filter. */
    bool              median_filter_bypass;                          /**< Bypass Median Filter. */
    bool              linear_filter_bypass;                          /**< Bypass Linear Interpolation Filter. */
    bool              average_filter_bypass;                         /**< Bypass Configurable Average Filter. */
    bool              cic_filter_bypass;                             /**< Bypass Cascade Integrator 3rd order Comb Filter. */
    bool              lpf_filter_bypass;                             /**< Bypass Low Pass Filter. */
    bool              unsign_path_enable;                            /**< Enable/Disable unsigned path to Filter module. This should be enabled only for testing purpose. By default it should be signed path always. */
    bool              min_max_detection_enable;                      /**< Enable/Disable MIN/MAX Detection. */
    uint8_t           src_ch;                                        /**< Configure source ADC channel for Filter Module. For ADC0, the noof channels is 16. For ADC1-3, the noof channels is 4. */
    cy_en_lif_m_factor_t lif_m_factor;                               /**< is the maximum number of clock cycle between two SoC for the ADC Conversion. */
    bool              lif_intp_extp_sel;                             /**< interpolator or extrapolator computation. */
    uint8_t           lpf_bandwidth;                                 /**< Low Pass Filter bandwidth. */
    bool              cic_src_type;                                  /**< CIC filter Source type. false : Internal. true : External. */
    cy_en_cic_clck_div_t  cic_clck_div;                              /**< CIC filter Clock Divider for external source sampling. */
    uint16_t          cic_decimation_factor;                         /**< Decimation Factor. */
    uint16_t          cic_decimation_offset;                         /**< CIC Decimation offset. */
    uint8_t           cic_decimation_scale;                          /**< CIC Scaling. */
    bool              cic_digital_comparator_enable;                 /**< CIC Digital Comparator Enable. */
    uint16_t          cic_UB_threshold;                              /**< CIC Filter Upper Bound Threshold. */
    uint16_t          cic_LB_threshold;                              /**< CIC Filter Lower Bound Threshold. */
    uint16_t          avg_no_of_samples;                             /**< AVG Filter Number of accumulated samples. */
    bool              avg_linear_or_squared;                         /**< AVG Filter Select Linear or Squared sample: 0 = Linear (K=1), 1 = Squared (K=2). */
    bool              avg_fix_or_dynamic_sample;                     /**< AVG Filter Select Fix or Dynamic sample window:: 0 = Fix(uses \ref avg_no_of_samples) , 1 = Dynamic. */
    bool              min_max_source;                                /**< Source to MIN/MAX filter. 0 = ADC Input 1= Median Filter. */
    cy_en_min_max_search_window_t   min_max_sample_search;           /**< Configure Min/Max sample search window. Search will restart upon reading ADC_MIN_MAX values. */
    bool              src_adc;                                       /**< Select source of the ADC data for Filter Module: 0 = Internal 1 = External (from other ADC_GRP). */
}cy_stc_ppca_adc_filter_config_t;

/** \} group_ppca_adc_filter_data_structures */


/**
* \addtogroup group_ppca_adc_filter_functions
* \{
*/

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_Init
***************************************************************************//**
*
* Initializes and enables the ADC Filter module. Configures the digital filter
* chain (Median, Linear Interpolation, Low-Pass, CIC3, Averaging), MIN/MAX
* detection, bypass settings, and CIC digital comparator thresholds.
*
* \param base The pointer to the ADC filter instance address.
*
* \param config The pointer to the filter config structure
* \ref cy_stc_ppca_adc_filter_config_t.
*
* \snippet ppca/snippet/ppca_snippet.c SNIPPET_PPCA_ADC_FILTER_INIT
*
******************************************************************************/
void Cy_PPCA_ADC_Filter_Init(ATOPSS_ADCFLT_TYPE *base, cy_stc_ppca_adc_filter_config_t const *config);

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_DeInit
***************************************************************************//**
*
* De-Initializes and disables the ADC Filter
*
* \param base The pointer to the ADC filter instance address.
*
******************************************************************************/
void Cy_PPCA_ADC_Filter_DeInit(ATOPSS_ADCFLT_TYPE *base);

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_Median_Output
***************************************************************************//**
*
* Output from the Median Filter
*
* \param base The pointer to the ADC filter instance address.
*
* \return returns Output from the Median Filter.
*
******************************************************************************/
__STATIC_INLINE uint16_t Cy_PPCA_ADC_Filter_Median_Output(ATOPSS_ADCFLT_TYPE *base)
{
    return (uint16_t)PPCA_ATOP_AFLT_MED_DOUT(base);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_LPF_Output
***************************************************************************//**
*
* Output from the Low Pass Filter
*
* \param base The pointer to the ADC filter instance address.
*
* \return returns Output from the LPF Filter.
*
******************************************************************************/
__STATIC_INLINE uint16_t Cy_PPCA_ADC_Filter_LPF_Output(ATOPSS_ADCFLT_TYPE *base)
{
    return (uint16_t)PPCA_ATOP_AFLT_LPF_DOUT(base);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_CIC_Output
***************************************************************************//**
*
* Output from the CIC Filter
*
* \param base The pointer to the ADC filter instance address.
*
* \return returns Output from the CIC Filter.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_Filter_CIC_Output(ATOPSS_ADCFLT_TYPE *base)
{
    return (uint32_t)PPCA_ATOP_AFLT_CICF_DOUT(base);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_AVG_Output
***************************************************************************//**
*
* Output from the AVG Filter
*
* \param base The pointer to the ADC filter instance address.
*
* \return returns Output from the AVG Filter.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_Filter_AVG_Output(ATOPSS_ADCFLT_TYPE *base)
{
    return (uint32_t)PPCA_ATOP_AFLT_AVGF_DOUT(base);
}

/******************************************************************************
* Function Name: Cy_PPCA_Get_ADC_Filter_LIF_M_TriggerPoint
***************************************************************************//**
*
* Returns the Trigger point for LIF filter. Range is from 0 to 255.
*
* \param base The pointer to the ADC filter instance address.
*
* \return returns the Trigger point for LIF filter.
*
******************************************************************************/
__STATIC_INLINE uint8_t Cy_PPCA_Get_ADC_Filter_LIF_M_TriggerPoint(ATOPSS_ADCFLT_TYPE *base)
{
    return (uint8_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_AFLT_LIF_CNFG_M_TRIGGER_POINT, PPCA_ATOP_AFLT_LIF_CNFG(base));
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_LIF_Output
***************************************************************************//**
*
* Output from the Linear Interpolator Filter
*
* \param base The pointer to the ADC filter instance address.
*
* \return returns Output from the Linear Interpolator Filter.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_Filter_LIF_Output(ATOPSS_ADCFLT_TYPE *base)
{
    return (uint32_t)PPCA_ATOP_AFLT_LIF_DOUT(base);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_AVG_Get_Samples_Used
***************************************************************************//**
*
* Returns the number of accumulated samples used for average from the latest trigger
*
* \param base The pointer to the ADC filter instance address.
*
* \return returns number of accumulated samples.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_Filter_AVG_Get_Samples_Used(ATOPSS_ADCFLT_TYPE *base)
{
    return (uint32_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CTL_ACCM_SAMPLE_RPT, PPCA_ATOP_AFLT_AVGF_CTL(base));
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_Trigger_Start
***************************************************************************//**
*
* Trigger to Start the filter. This will reset the accumulated sample from the latest trigger
*
* \param base The pointer to the ADC filter instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_AVG_Filter_Trigger_Start(ATOPSS_ADCFLT_TYPE *base)
{
    PPCA_ATOP_AFLT_AVGF_CTL(base) |= PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CTL_SOF_TRIGGER_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_MINMAX_Get_MIN_Value
***************************************************************************//**
*
* Returns the Min ADC data input stream value in the defined MIN/MAX window
*
* \param base The pointer to the ADC filter instance address.
*
* \return returns Min value.
*
******************************************************************************/
__STATIC_INLINE uint16_t Cy_PPCA_ADC_Filter_MINMAX_Get_MIN_Value(ATOPSS_ADCFLT_TYPE *base)
{
    return (uint16_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_AFLT_ADC_MIN_MAX_MIN_MIRROR, PPCA_ATOP_AFLT_ADC_MIN_MAX(base));
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_MINMAX_Get_MAX_Value
***************************************************************************//**
*
* Returns the Max ADC data input stream value in the defined MIN/MAX window
*
* \param base The pointer to the ADC filter instance address.
*
* \return returns Max value.
*
******************************************************************************/
__STATIC_INLINE uint16_t Cy_PPCA_ADC_Filter_MINMAX_Get_MAX_Value(ATOPSS_ADCFLT_TYPE *base)
{
    return (uint16_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_AFLT_ADC_MIN_MAX_MAX_MIRROR, PPCA_ATOP_AFLT_ADC_MIN_MAX(base));
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_AVGFilter_Bypass
***************************************************************************//**
*
* Bypass AVG Filter
*
* \param base The pointer to the ADC filter instance address.
*
* \param bypass Bypass Average filter or not.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Filter_AVGFilter_Bypass(ATOPSS_ADCFLT_TYPE *base, bool bypass)
{
    if(bypass)
    {
        PPCA_ATOP_AFLT_CNFG(base) |= PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_AVG_Msk;
    }
    else
    {
        PPCA_ATOP_AFLT_CNFG(base) &= (uint32_t) ~(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_AVG_Msk);
    }
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_MedianFilter_Bypass
***************************************************************************//**
*
* Bypass Median Filter
*
* \param base The pointer to the ADC filter instance address.
*
* \param bypass Bypass Median filter or not.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Filter_MedianFilter_Bypass(ATOPSS_ADCFLT_TYPE *base, bool bypass)
{
    if(bypass)
    {
        PPCA_ATOP_AFLT_CNFG(base) |= PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_MEDIAN_Msk;
    }
    else
    {
        PPCA_ATOP_AFLT_CNFG(base) &= (uint32_t) ~(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_MEDIAN_Msk);
    }
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_LIFFilter_Bypass
***************************************************************************//**
*
* Bypass LIF Filter
*
* \param base The pointer to the ADC filter instance address.
*
* \param bypass Bypass LIF filter or not.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Filter_LIFFilter_Bypass(ATOPSS_ADCFLT_TYPE *base, bool bypass)
{
    if(bypass)
    {
        PPCA_ATOP_AFLT_CNFG(base) |= PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_LIF_Msk;
    }
    else
    {
        PPCA_ATOP_AFLT_CNFG(base) &= (uint32_t) ~(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_LIF_Msk);
    }
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_LPFFilter_Bypass
***************************************************************************//**
*
* Bypass LPF Filter
*
* \param base The pointer to the ADC filter instance address.
*
* \param bypass Bypass LPF filter or not.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Filter_LPFFilter_Bypass(ATOPSS_ADCFLT_TYPE *base, bool bypass)
{
    if(bypass)
    {
        PPCA_ATOP_AFLT_CNFG(base) |= PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_LPF_Msk;
    }
    else
    {
        PPCA_ATOP_AFLT_CNFG(base) &= (uint32_t) ~(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_LPF_Msk);
    }
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Filter_CICFilter_Bypass
***************************************************************************//**
*
* Bypass CIC Filter
*
* \param base The pointer to the ADC filter instance address.
*
* \param bypass Bypass CIC filter or not.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Filter_CICFilter_Bypass(ATOPSS_ADCFLT_TYPE *base, bool bypass)
{
    if(bypass)
    {
        PPCA_ATOP_AFLT_CNFG(base) |= PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_CIC_Msk;
    }
    else
    {
        PPCA_ATOP_AFLT_CNFG(base) &= (uint32_t) ~(PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_CIC_Msk);
    }
}

/** \} group_ppca_adc_filter_functions */



#if defined(__cplusplus)
}
#endif
#endif /*defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN) */

#endif /* CY_PPCA_ADC_FILTER_H */

