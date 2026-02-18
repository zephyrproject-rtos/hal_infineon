/***************************************************************************//**
* \file cy_ppca_dcmp.h
* \version 1.0
*
* The header file of the PPCA DCMP driver.
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


#if !defined(CY_PPCA_DCMP_H)
#define CY_PPCA_DCMP_H

#include "cy_device.h"

#if defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN)

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_ppca_dcmp
* The DCMP (Digital Comparator) driver provides an interface to the 12 digital
* comparator modules within the ATOPSS ADC_GRP_IF blocks. Each DCMP is
* connected to one of the converted ADC data channels and generates an event
* (DCMP_OUT) when the input (or elaborated input) crosses a programmed
* threshold.
*
* \section group_ppca_dcmp_overview Overview
*
* The ATOPSS contains 12 DCMP instances distributed across four ADC groups:
* - <b>ADC_GRP_0:</b> 4 DCMP modules (DCMP_00 .. DCMP_03)
* - <b>ADC_GRP_1:</b> 2 DCMP modules (DCMP_10 .. DCMP_11)
* - <b>ADC_GRP_2:</b> 2 DCMP modules (DCMP_20 .. DCMP_21)
* - <b>ADC_GRP_3:</b> 4 DCMP modules (DCMP_30 .. DCMP_33)
*
* The source ADC channel for each DCMP is selected through the configuration
* register (DCMP_CNFG.SEL_SRC_CH). The 12-bit threshold (DCMP_TH) can be
* signed or unsigned, matching the ADC channel data format.
*
* <b>Comparison Modes (DCMP_CNFG.MODE):</b>
* - <b>Mode 0 — Immediate:</b> A(n) > TH. Comparison occurs as soon as data
*   is ready. Invertible via INV_DCMP_EV_CNFG.
* - <b>Mode 1 — Integration (Accumulate):</b> Accumulates +1 for each
*   A(n) > TH and -1 otherwise, capped at [0, 255]. Result compared
*   against TH_ACC. Requires a trigger to start/reset.
* - <b>Mode 2 — Increment:</b> Accumulates +1 for each A(n) > TH, +0
*   otherwise, capped at 255. Result compared against TH_ACC.
*   Requires a trigger to start/reset.
* - <b>Mode 3 — Averaged:</b> ROUND(1/N * Sigma A(n)) > TH. Averages over
*   a window of 4, 16, 64, or 256 samples, then compares against TH.
*   Requires a trigger to start.
*
* <b>Trigger Behavior:</b>
* In Modes 1-3, DCMP_TRIGGER.DCMP_TRIG or the external DCMP_TRIG[] signal
* resets the accumulated computation and starts the comparison window.
* DCMP_OUT events are routed to the EPU trigger bus.
*
* \note DCMP_CNFG registers must not be changed while the DCMP is enabled.
* Disable the DCMP first, modify the configuration, then re-enable to
* prevent unexpected behavior.
*
* \{
*/

/**
* \defgroup group_ppca_dcmp_macros                Macros
* \defgroup group_ppca_dcmp_functions             Functions
* \defgroup group_ppca_dcmp_data_structures Data Structures
* \} */

/**
* \addtogroup group_ppca_dcmp_macros
* \{
*/
/** Macros */
#define ATOPSS_DCMP_TYPE PPCA_ATOPSS_ADC_GRP_DCMP_Type

/** \} group_ppca_dcmp_macros */

/**
* \addtogroup group_ppca_dcmp_data_structures
* \{
*/

/** comparison method */
typedef enum
{
    CY_DCMP_MODE_IMMEDIATE_COMPARISON                 = 0UL,        /**<DCMP comparison method set to Immediate: A(n) > TH  */
    CY_DCMP_MODE_INTEGRATION_OF_IMMEDIATE_COMPARISON  = 1UL,        /**<DCMP comparison method set to Integration of Immediate: Sigma ((A(n) > TH) - (A(n) <= TH)) > TH_ACC  */
    CY_DCMP_MODE_ACCUMULATE_OF_IMMEDIATE_COMPARISON   = 2UL,        /**<DCMP comparison method set to accumulation of Immediate: Sigma (A(n) > TH) > TH_ACC  */
    CY_DCMP_MODE_AVERAGED_COMPARISON                  = 3UL,        /**<DCMP comparison method set to Average: 1/N Sigma A(n) > TH   */
} cy_en_dcmp_comparison_mode_t;

/** DCMP Average Sampling Window */
typedef enum
{
    CY_DCMP_AVG_SAMPLING_WINDOW_4POINTS    = 0UL,        /**<DCMP Average Sampling Window is 4 Points  */
    CY_DCMP_AVG_SAMPLING_WINDOW_16POINTS   = 1UL,        /**<DCMP Average Sampling Window is 16 Points  */
    CY_DCMP_AVG_SAMPLING_WINDOW_64POINTS   = 2UL,        /**<DCMP Average Sampling Window is 64 Points  */
    CY_DCMP_AVG_SAMPLING_WINDOW_256POINTS  = 3UL,        /**<DCMP Average Sampling Window is 256 Points  */
} cy_en_dcmp_avg_sampling_window_t;

/** PPCA DCMP configuration structure */
typedef struct cy_stc_ppca_dcmp_config
{
    cy_en_dcmp_comparison_mode_t               comparison_mode;          /**< Comparison mode */
    cy_en_dcmp_avg_sampling_window_t           avg_sampling_window;      /**< DCMP Average Sampling Window */
    uint8_t                                    src_ch;                   /**< Source Channel to DCMP */
    bool                                       inv_dcmp_ev;              /**< If set The immediate comparison result of mode 0 will be inverted. */
    uint16_t                                   dcmp_threshold;           /**< 12 bit Digital Comparator Threshold value. Can be signed or unsigned depending on the ADC Channel Signed and Unsigned */
    uint8_t                                    dcmp_acc_threshold;       /**< 8 bit Digital Comparator accumulate Threshold value. DCMP result will be 1 if the Comparator result is greater than dcmp_acc_threshold.*/
}cy_stc_ppca_dcmp_config_t;

/** \} group_ppca_dcmp_data_structures */


/**
* \addtogroup group_ppca_dcmp_functions
* \{
*/

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
* \snippet ppca/snippet/ppca_snippet.c SNIPPET_PPCA_DCMP_INIT
*
******************************************************************************/
void Cy_PPCA_DCMP_Init(ATOPSS_DCMP_TYPE *base, cy_stc_ppca_dcmp_config_t const *config);

/******************************************************************************
* Function Name: Cy_PPCA_DCMP_Enable
***************************************************************************//**
*
* Enables the DCMP
*
* \param base The pointer to the DCMP instance address.
*
* \snippet ppca/snippet/ppca_snippet.c SNIPPET_PPCA_DCMP_ENABLE_DISABLE
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCMP_Enable(ATOPSS_DCMP_TYPE *base)
{
    PPCA_ATOP_DCMP_CTL(base) |= PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CTL_DCMP_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_DCMP_Disable
***************************************************************************//**
*
* Disables the DCMP
*
* \param base The pointer to the DCMP instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCMP_Disable(ATOPSS_DCMP_TYPE *base)
{
    PPCA_ATOP_DCMP_CTL(base) &= (uint32_t) ~PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CTL_DCMP_EN_Msk;
}


/******************************************************************************
* Function Name: Cy_PPCA_DCMP_Get_Status
***************************************************************************//**
*
* Report status of the current digital comparison
*
* \param base The pointer to the DCMP instance address.
*
* \return returns DCMP Status. 0: input less or equal to threshold. 1: input above threshold
*
******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_DCMP_Get_Status(ATOPSS_DCMP_TYPE *base)
{
    return (bool)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CTL_DCMP_EV, PPCA_ATOP_DCMP_CTL(base));
}


/******************************************************************************
* Function Name: Cy_PPCA_DCMP_Set_Threshold
***************************************************************************//**
*
* Sets 12 bit Digital Comparator Threshold value. Can be signed or unsigned depending on the ADC Channel Signed and Unsigned 
*
* \param base The pointer to the DCMP instance address.
*
* \param threshold 12 bit Digital Comparator Threshold value..
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCMP_Set_Threshold(ATOPSS_DCMP_TYPE *base, uint16_t threshold)
{
    PPCA_ATOP_DCMP_TH(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_TH_DCMP_TH, threshold);
}

/******************************************************************************
* Function Name: Cy_PPCA_DCMP_is_Threshold_Negative
***************************************************************************//**
*
* 12 bit Digital Comparator Threshold value can be signed or unsigned depending on the ADC Channel Signed and Unsigned.
* When DCMP threshold data is negative for sign, the 20 bits data returned will be all 1's.
*
* \param base The pointer to the DCMP instance address.
*
* \return returns When DCMP threshold data is negative for sign, the 20 bits data returned will be all 1's, else 0's
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_DCMP_is_Threshold_Negative(ATOPSS_DCMP_TYPE *base)
{
    return (uint32_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_TH_SIGN_EXTENDED_DCMP_TH, PPCA_ATOP_DCMP_TH(base));
}

/******************************************************************************
* Function Name: Cy_PPCA_DCMP_Trigger
***************************************************************************//**
*
* Triggers DCMP Comparison, when comparison mode is not CY_DCMP_MODE_IMMEDIATE_COMPARISON
* This trigger also resets current computed value.
*
* \param base The pointer to the DCMP instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCMP_Trigger(ATOPSS_DCMP_TYPE *base)
{
    PPCA_ATOP_DCMP_TRIGGER(base) = PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_TRIGGER_DCMP_TRIG_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_DCMP_Get_Source_Channel
***************************************************************************//**
*
* Returns the ADC channel number currently feeding this DCMP instance, as
* configured via cy_stc_ppca_dcmp_config_t.src_ch at Cy_PPCA_DCMP_Init().
* Useful when the source channel assignment is not otherwise known to the
* calling code (e.g. generic test/verification routines).
*
* \param base The pointer to the DCMP instance address.
*
* \return the ADC source channel number connected to this DCMP.
*
******************************************************************************/
__STATIC_INLINE uint8_t Cy_PPCA_DCMP_Get_Source_Channel(ATOPSS_DCMP_TYPE *base)
{
    return (uint8_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_SEL_SRC_CH, PPCA_ATOP_DCMP_CNFG(base));
}


/** \} group_ppca_dcmp_functions */



#if defined(__cplusplus)
}
#endif
#endif /*defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN) */

#endif /* CY_PPCA_DCMP_H */

