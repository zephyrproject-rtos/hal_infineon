/***************************************************************************//**
* \file cy_ppca_dcsg.h
* \version 1.0
*
* The header file of the PPCA DCSG driver.
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


#if !defined(CY_PPCA_DCSG_H)
#define CY_PPCA_DCSG_H

#include "cy_device.h"
#include "cy_syslib.h"

#if defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN)

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_ppca_dcsg
* The DCSG (Digital Comparator and Slope Generator) driver provides an
* interface to the analog comparator slices within the ATOPSS. Each DCSG slice
* implements a programmable-threshold analog comparator with built-in
* hysteresis, debounce, and blanking support.
*
* \section group_ppca_dcsg_overview Overview
*
* The ATOPSS contains 9 DCSG slices organized into two groups:
* - <b>DCSG_GRP_0:</b> 6 comparator slices
* - <b>DCSG_GRP_1:</b> 3 comparator slices
*
* Each DCSG slice compares an analog input against a 12-bit programmable
* threshold and produces a digital comparator output (CMP_FLAG). The input
* can be external (from analog pads) or internal (from DAC R2R output).
*
* <b>Input Modes:</b>
* - Differential Extended Range (+/-3.3 V)
* - Differential Full Range (0 V to 3.3 V)
* - Differential Reduced Range (+/-200 mV)
* - Single-Ended P vs GND or N vs GND
* - A vs B mode (with hysteresis and debounce)
*
* <b>Key Features:</b>
* - 12-bit threshold (1 LSB approx. 1.6 mV in A_VS_B mode)
* - Programmable hysteresis: 0, +/-1, +/-2, +/-4, +/-8, +/-16, +/-32, +/-64 LSB
* - Debounce filter: transition must be stable for 2-8 clock cycles
* - Blanking period: suppresses output glitches after comparison init
* - Configurable refresh rate (5 to 50 us based on 200 MHz clock)
* - Interleave blanking support using an alternate DCSG slice
*
* Each DCSG group also contains a Slope Generator (\ref group_ppca_dcsg_slgen)
* and a DAC R2R (\ref group_ppca_dacr2r) instance.
*
* \note Initialization (Cy_PPCA_DCSG_Init) must be called from the Main core
* so that trim registers are configured correctly.
*
* \{
*/

/**
* \defgroup group_ppca_dcsg_macros                Macros
* \defgroup group_ppca_dcsg_functions             Functions
* \defgroup group_ppca_dcsg_data_structures Data Structures
* \} */

/**
* \addtogroup group_ppca_dcsg_macros
* \{
*/
/** Macros */
#define ATOPSS_DCSG_TYPE PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type

/** Parameter check macro for threshold value */
#define CY_PPCA_DCSG_IS_THRESHOLD_VALID(threshold) ((threshold) <= 0xFFFU)

/** \} group_ppca_dcsg_macros */

/**
* \addtogroup group_ppca_dcsg_data_structures
* \{
*/

/** To configure the DCSG DAC update rate. */
typedef enum
{
    CY_DCSG_DAC_RATE_4CLK_0BLANK_CYCLES       = 0UL,        /**<4 Clock Cycle, 0 tblank clk cycle (This is only for slope gen only). */
    CY_DCSG_DAC_RATE_4CLK_2BLANK_CYCLES       = 1UL,        /**<4 Clock Cycle, 2 tblank clk cycle (This is only for slope gen only). */
    CY_DCSG_DAC_RATE_4CLK_3BLANK_CYCLES       = 2UL,        /**<4 Clock Cycle, 3 tblank clk cycle (This is only for slope gen only). */
    CY_DCSG_DAC_RATE_6CLK_4BLANK_CYCLES       = 3UL,        /**<6 Clock Cycle, 4 tblank clk cycle.   */
    CY_DCSG_DAC_RATE_8CLK_6BLANK_CYCLES       = 4UL,        /**<8 Clock Cycle, 6 tblank clk cycle.   */
    CY_DCSG_DAC_RATE_10CLK_8BLANK_CYCLES      = 5UL,        /**<10 Clock Cycle, 8 tblank clk cycle.  */
    CY_DCSG_DAC_RATE_12CLK_10BLANK_CYCLES     = 6UL,        /**<12 Clock Cycle, 10 tblank clk cycle. */
    CY_DCSG_DAC_RATE_20CLK_18BLANK_CYCLES     = 7UL,        /**<20 Clock Cycle, 18 tblank clk cycle. */
} cy_en_dcsg_dac_rate_t;

/** To configure the DCSG Refresh rate. Formula used to calculate refresh rate is  1/DCSG_CLK*Clk counter value  */
typedef enum
{
    CY_DCSG_REFRESH_RATE_10000_CYCLES    = 0UL,        /**<10000 Clk counter -> 50.0usec based on 200MHz Clock. */
    CY_DCSG_REFRESH_RATE_7500_CYCLES     = 1UL,        /**<7500 Clk counter -> 37.5usec based on 200MHz Clock.  */
    CY_DCSG_REFRESH_RATE_5000_CYCLES     = 2UL,        /**<5000 Clk counter -> 25.0usec based on 200MHz Clock.  */
    CY_DCSG_REFRESH_RATE_3500_CYCLES     = 3UL,        /**<3500 Clk counter -> 17.5usec based on 200MHz Clock.  */
    CY_DCSG_REFRESH_RATE_2500_CYCLES     = 4UL,        /**<2500 Clk counter -> 12.5usec based on 200MHz Clock.  */
    CY_DCSG_REFRESH_RATE_1750_CYCLES     = 5UL,        /**<1750 Clk counter -> 8.75usec based on 200MHz Clock.  */
    CY_DCSG_REFRESH_RATE_1250_CYCLES     = 6UL,        /**<1250 Clk counter -> 6.25usec based on 200MHz Clock.  */
    CY_DCSG_REFRESH_RATE_1000_CYCLES     = 7UL,        /**<1000 Clk counter -> 5.00usec based on 200MHz Clock.  */
} cy_en_dcsg_refresh_rate_t;

/** To configure the DCSG Hysteresis setup for A_VS_B Mode. 1 LSB is equivalent to 1.6mV.
    Hysteresis is a phenomenon that occurs when the output of a system depends on both its current and past inputs.  */
typedef enum
{
    CY_DCSG_HYSTERESIS_IS_DISABLED    = 0UL,        /**< Hysteresis feature is disabled.      */
    CY_DCSG_HYSTERESIS_IS_1_LSB       = 1UL,        /**< +/- 1 LSB hysteresis is introduced.  */
    CY_DCSG_HYSTERESIS_IS_2_LSB       = 2UL,        /**< +/- 2 LSB hysteresis is introduced.  */
    CY_DCSG_HYSTERESIS_IS_4_LSB       = 3UL,        /**< +/- 4 LSB hysteresis is introduced.  */
    CY_DCSG_HYSTERESIS_IS_8_LSB       = 4UL,        /**< +/- 8 LSB hysteresis is introduced.  */
    CY_DCSG_HYSTERESIS_IS_16_LSB      = 5UL,        /**< +/- 16 LSB hysteresis is introduced. */
    CY_DCSG_HYSTERESIS_IS_32_LSB      = 6UL,        /**< +/- 32 LSB hysteresis is introduced. */
    CY_DCSG_HYSTERESIS_IS_64_LSB      = 7UL,        /**< +/- 64 LSB hysteresis is introduced. */
} cy_en_dcsg_hyst_value_t;

/** To configure the DCSG Debounce feature for HYST operation (Only for A_VS_B Mode Hysteresis )    */
typedef enum
{
    CY_DCSG_DEBOUNCE_RATE_DISABLED     = 0UL,        /**<Debounce feature is disabled. */
    CY_DCSG_DEBOUNCE_RATE_2_CYCLES     = 1UL,        /**<Transition must be valid for 2 clock cycle.  */
    CY_DCSG_DEBOUNCE_RATE_3_CYCLES     = 2UL,        /**<Transition must be valid for 3 clock cycle.  */
    CY_DCSG_DEBOUNCE_RATE_4_CYCLES     = 3UL,        /**<Transition must be valid for 4 clock cycle.  */
    CY_DCSG_DEBOUNCE_RATE_5_CYCLES     = 4UL,        /**<Transition must be valid for 5 clock cycle.  */
    CY_DCSG_DEBOUNCE_RATE_6_CYCLES     = 5UL,        /**<Transition must be valid for 6 clock cycle.  */
    CY_DCSG_DEBOUNCE_RATE_7_CYCLES     = 6UL,        /**<Transition must be valid for 7 clock cycle.  */
    CY_DCSG_DEBOUNCE_RATE_8_CYCLES     = 7UL,        /**<Transition must be valid for 8 clock cycle.  */
} cy_en_dcsg_debounce_rate_t;

/** DCSG Blanking Period Setting. */
typedef enum
{
    CY_DCSG_BLANKING_PERIOD_8       = 0UL,        /**<Blanking period is 8 after init. It will be 98 if the source is internal.  */
    CY_DCSG_BLANKING_PERIOD_10_1    = 1UL,        /**<Blanking period is 10 after init. It will be 98 if the source is internal. */
    CY_DCSG_BLANKING_PERIOD_10_2    = 2UL,        /**<Blanking period is 10 after init. It will be 98 if the source is internal. */
    CY_DCSG_BLANKING_PERIOD_12      = 3UL,        /**<Blanking period is 12 after init. It will be 98 if the source is internal. */

} cy_en_dcsg_blanking_period_t;

/** Analog Comparator channel source type */
typedef enum
{
    CY_DCSG_CH_SRC_TYPE_CH_DIFF_ER    = 0UL,        /**<Differential Mode Extended Range support +/-3.3V. Other than 5, this will be selected  */
    CY_DCSG_CH_SRC_TYPE_CH_DIFF_FR    = 1UL,        /**<Differential Mode Full Range support 0-3.3V  */
    CY_DCSG_CH_SRC_TYPE_CH_SINGLE_P   = 2UL,        /**<Single-Ended Mode P Vs GND (Use together with SEL_CH_SRC)  */
    CY_DCSG_CH_SRC_TYPE_CH_SINGLE_N   = 3UL,        /**<Single-Ended Mode N Vs GND (User together with SEL_CH_SRC) */
    CY_DCSG_CH_SRC_TYPE_CH_DIFF_RR    = 4UL,        /**<Differential Mode Reduced Range support +/-200mV */
    CY_DCSG_CH_SRC_TYPE_CH_A_VS_B     = 5UL,        /**<A vs B Mode */

} cy_en_dcsg_ch_src_type_t;


/** PPCA DCSG configuration structure */
typedef struct cy_stc_ppca_dcsg_config
{
    bool              src_type;                                 /**< if enabled, source to DCSG is from DAC R2R(internal). If disabled, source to DCSG is from analog input pad(external). */
    uint8_t           src_ch;                                   /**< Select Analog Input Channel Source. Valid range 0 to 11. */
    cy_en_dcsg_ch_src_type_t        src_ch_type;                /**< Analog Comparator channel source type. */
    cy_en_dcsg_blanking_period_t    blanking_period;            /**< DCSG Blanking Period Setting.          */
    cy_en_dcsg_dac_rate_t           dac_clk_blk_rate;           /**< configures the DCSG DAC update rate.   */
    cy_en_dcsg_refresh_rate_t       refresh_rate;               /**< configures the DCSG refresh rate.      */
    bool                            bypass_refresh;             /**< Bypass DCSG refresh.                   */
    bool                            use_user_value;             /**< To use User Defined Value during Refresh. 0: CMP_Flag from comparator output. 1: CMP_Flag from User defined value.  */
    bool                            user_value;                 /**< User defined value. used as CMP_FLAG when bypass_refresh and use_user_value are set to true.                        */
    cy_en_dcsg_hyst_value_t         hyst_value;                 /**< configures the DCSG Hysteresis setup for A_VS_B Mode. 1 LSB is equivalent to 1.6mV.                                 */
    cy_en_dcsg_debounce_rate_t      debounce_rate;              /**< configures the DCSG Debounce feature for HYST operation (Only for A_VS_B Mode Hysteresis )                          */
    uint16_t                        threshold;                  /**< 12 bit DCSG Threshold Value.           */
    uint8_t                         groupNumber;                /**< Group Number in which the DCSG is placed. This is required to apply trims for the DCSG group.                       */
}cy_stc_ppca_dcsg_config_t;

/** \} group_ppca_dcsg_data_structures */


/**
* \addtogroup group_ppca_dcsg_functions
* \{
*/

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Init
***************************************************************************//**
*
* Initializes and enables the DCSG analog comparator slice. Configures the
* input source (internal DAC or external pad), channel mode, threshold,
* hysteresis, debounce, blanking period, DAC update rate, and refresh rate.
* Also loads trim values from the SFLASH region.
*
* \param base The pointer to the DCSG instance address.
*
* \param config The pointer to the DCSG config structure \ref cy_stc_ppca_dcsg_config_t.
*
* \note Must be called from the Main core so that trim registers are
* configured correctly. Trim values are not loaded if called from PPCA cores.
*
* \snippet ppca/snippet/ppca_snippet.c SNIPPET_PPCA_DCSG_INIT
******************************************************************************/
#if defined (COMPONENT_PPCA_DEVICE) && !defined (__ICCARM__)
void Cy_PPCA_DCSG_Init(ATOPSS_DCSG_TYPE *base, cy_stc_ppca_dcsg_config_t const *config)__attribute__((warning("Initialization of PPCA peripherals like AREF, ADC, DAC and DCSG to be done on Main core. Trim values are not configured if called on PPCA cores.")));
#else
void Cy_PPCA_DCSG_Init(ATOPSS_DCSG_TYPE *base, cy_stc_ppca_dcsg_config_t const *config);
#endif

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Enable
***************************************************************************//**
*
* Enables the DCSG module
*
* \param base The pointer to the DCSG instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_Enable(ATOPSS_DCSG_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_CTL(base) |= PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CTL_DCSG_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Disable
***************************************************************************//**
*
* Disables the DCSG module
*
* \param base The pointer to the DCSG instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_Disable(ATOPSS_DCSG_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_CTL(base) &= (uint32_t) ~PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CTL_DCSG_EN_Msk;
}


/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Blank_Enable
***************************************************************************//**
*
* Enables the DCSG Blank feature
* DCSG requires a refresh interval at every 50usec, and the refresh duration is around 50nsec.
* DCSG is unable to monitor the analog input pad during this refresh duration.
* User can enable this for interleave blanking support.
* When enabled an alternate DCSG will be used as the DCSG for the interleave operation.
*
* \note DCSG interleave blanking feature will not be applicable to DCSG when SLGEN is enabled.
*
* \param base The pointer to the DCSG instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_Blank_Enable(PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK_Type *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_BLANK_CTL(base) |= PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK_DCSG_BLANK_CTL_DCSG_BLANK_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Blank_Disable
***************************************************************************//**
*
* Disables the DCSG blank feature
*
* \param base The pointer to the DCSG instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_Blank_Disable(PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK_Type *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_BLANK_CTL(base) &= (uint32_t) ~PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK_DCSG_BLANK_CTL_DCSG_BLANK_EN_Msk;
}


/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Get_Input_Signal_Status
***************************************************************************//**
*
* Returns if the input signal from comparator is greater than the threshold or not 
*
* \param base The pointer to the DCSG instance address.
*
* \return returns false if the input signal from comparator is less then the threshold, else returns true.
*
******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_DCSG_Get_Input_Signal_Status(ATOPSS_DCSG_TYPE *base)
{
    return (bool)_FLD2VAL(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CTL_CMP_FLAG, PPCA_ATOP_DCSG_CTL(base));
}


/******************************************************************************
* Function Name: Cy_PPCA_Is_DCSG_Busy
***************************************************************************//**
*
* Returns the busy status of the DCSG
*
* \param base The pointer to the DCSG instance address.
*
* \return returns if DCSG is busy or not. True: Busy, False: Not Busy
*
******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_Is_DCSG_Busy(ATOPSS_DCSG_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    return (bool)_FLD2VAL(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CTL_DCSG_BUSY, PPCA_ATOP_DCSG_CTL(base));    
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Set_Threshold
***************************************************************************//**
*
* Set's DCSG 12 bit Threshold value
*
* \param base The pointer to the DCSG instance address.
*
* \param threshold Threshold Value. User shall ensure that DCSG is not BUSY while setting this value.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_Set_Threshold(ATOPSS_DCSG_TYPE *base, uint16_t threshold)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L2(CY_PPCA_DCSG_IS_THRESHOLD_VALID(threshold));
    PPCA_ATOP_DCSG_TH(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_TH_TH, threshold);
}


/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Refresh_Bypass_Enable
***************************************************************************//**
*
* Bypass DCSG refresh.
*
* \param base The pointer to the DCSG instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_Refresh_Bypass_Enable(ATOPSS_DCSG_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_CNFG(base) |= PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_BYPASS_REFRESH_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Refresh_Disable
***************************************************************************//**
*
* Disables the Bypass DCSG refresh.
*
* \param base The pointer to the DCSG instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_Refresh_Bypass_Disable(ATOPSS_DCSG_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_CNFG(base) &= (uint32_t) ~PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_BYPASS_REFRESH_Msk;
}


/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Use_UserValue_During_Refresh
***************************************************************************//**
*
* To use user Defined Value during Refresh.
*
* \param base The pointer to the DCSG instance address.
*
* \param user_value user defined value during refresh.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_Use_UserValue_During_Refresh(ATOPSS_DCSG_TYPE *base, bool user_value)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_CNFG(base) &= (uint32_t) ~PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_DEFINED_VALUE_Msk;
    PPCA_ATOP_DCSG_CNFG(base) |= _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_DEFINED_VALUE_SETUP, 1U)  |
                                 _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_DEFINED_VALUE, user_value);
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Use_Comparator_Output_During_Refresh
***************************************************************************//**
*
* To use comparator output during Refresh.
*
* \param base The pointer to the DCSG instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_Use_Comparator_Output_During_Refresh(ATOPSS_DCSG_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_CNFG(base) &= (uint32_t) ~PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_DEFINED_VALUE_SETUP_Msk;
    PPCA_ATOP_DCSG_CNFG(base) &= (uint32_t) ~PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_DEFINED_VALUE_Msk;
}



/** \} group_ppca_dcsg_functions */



#if defined(__cplusplus)
}
#endif
#endif /*defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN) */

#endif /* CY_PPCA_DCSG_H */

