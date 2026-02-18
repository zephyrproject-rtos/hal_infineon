/***************************************************************************//**
* \file cy_ppca_dcsg_slgen.h
* \version 1.0
*
* The header file of the PPCA DCSG_SLGEN driver.
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


#if !defined(CY_PPCA_DCSG_SLGEN_H)
#define CY_PPCA_DCSG_SLGEN_H

#include "cy_device.h"
#include "cy_syslib.h"

#if defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN)

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_ppca_dcsg_slgen
* The DCSG Slope Generator (SLGEN) driver provides an interface to the hardware
* ramp generator embedded in each DCSG group. The SLGEN produces a
* monotonically increasing or decreasing ramp waveform that drives the DCSG
* comparator threshold, enabling autonomous slope compensation and valley/peak
* current mode control without CPU intervention.
*
* \section group_ppca_dcsg_slgen_overview Overview
*
* Each DCSG group contains one SLGEN instance that can be mapped to any DCSG
* slice within that group. The SLGEN generates a ramp from an initial value
* to a target value with a configurable step size per DAC clock cycle.
*
* <b>Ramp Parameters (all 12-bit integer + 4-bit fractional):</b>
* - Initial value: starting point of the ramp
* - Target value: end point of the ramp
* - Step value: increment/decrement per DAC clock cycle
*
* <b>Key Features:</b>
* - Shadow transfer: Initial and target values have shadow buffer registers.
*   The active values update from the buffer on the next ramp trigger.
* - Auto-reset: Automatically reloads the initial value and restarts the ramp
*   when the target is reached.
* - Hardware trigger: The ramp starts on an external trigger event (from the
*   EPU trigger bus) when triggers are unmasked.
* - Match capture: Records the slope value at which the DCSG comparator
*   triggered, along with a valid flag indicating whether the match occurred
*   before or after the trigger event.
* - Debug freeze: Pauses ramp generation when a debug halt signal is active.
* - Single-clock glitch filter: Suppresses single-cycle blanking glitches.
*
* \{
*/

/**
* \defgroup group_ppca_dcsg_slgen_macros                Macros
* \defgroup group_ppca_dcsg_slgen_functions             Functions
* \defgroup group_ppca_dcsg_slgen_data_structures Data Structures
* \} */

/**
* \addtogroup group_ppca_dcsg_slgen_macros
* \{
*/
/** Macros */
#define ATOPSS_SLGEN_TYPE PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_Type

/** \} group_ppca_dcsg_slgen_macros */

/**
* \addtogroup group_ppca_dcsg_slgen_data_structures
* \{
*/

/** To map SL_GEN operation DCSG */
typedef enum
{
    CY_DCSG_SLGEN_MAP_0    = 0UL,        /**<SL_GEN is configured to DCSG_0  */
    CY_DCSG_SLGEN_MAP_1    = 1UL,        /**<SL_GEN is configured to DCSG_1  */
    CY_DCSG_SLGEN_MAP_2    = 2UL,        /**<SL_GEN is configured to DCSG_2  */
    CY_DCSG_SLGEN_MAP_3    = 3UL,        /**<SL_GEN is configured to DCSG_3  */
    CY_DCSG_SLGEN_MAP_4    = 4UL,        /**<SL_GEN is configured to DCSG_4  */
    CY_DCSG_SLGEN_MAP_5    = 5UL,        /**<SL_GEN is configured to DCSG_5  */

} cy_en_dcsg_slgen_map_t;


/** PPCA DCSG_SLGEN configuration structure */
typedef struct cy_stc_ppca_dcsg_slgen_config
{
    bool              trigger_unmask;                           /**< if enabled, triggers are unmasked. Upon detect of Trigger will start the SL operation. */
    bool              single_clk_glitch;                        /**< if enabled, single clock blank glitch filter is enabled. */
    bool              slgen_src;                                /**< if enabled, Select SLGEN RAMP as source, SLGEN_RAMP is control of the DAC threshold. If disabled CPU is in control of DCSG_TH: DAC threshold  */
    bool              shadow_transfer;                          /**< Enable/Disable Shadow Transfer Feature. */
    bool              auto_reset;                               /**< Enable/Disable Auto Reset Feature. Auto-Reset of Slope Generation threshold between initial and target value. */
    cy_en_dcsg_slgen_map_t slgen_map;                           /**< map SL_GEN operation DCSG. */
    uint16_t          slgen_init_value;                         /**< 12 bit Initial Integer Value. */
    uint8_t           slgen_init_frac_value;                    /**< 4 bit Initial Fractional Value. */
    uint16_t          slgen_init_buf_value;                     /**< shadow 12 bit Initial Integer Value. */
    uint8_t           slgen_init_buf_frac_value;                /**< shadow 4 bit Initial Fractional Value. */     
    uint16_t          slgen_target_value;                       /**< 12 bit Target Integer Value. */
    uint8_t           slgen_target_frac_value;                  /**< 4 bit Target Fractional Value. */
    uint16_t          slgen_target_buf_value;                   /**< shadow 12 bit Target Integer Value. */
    uint8_t           slgen_target_buf_frac_value;              /**< shadow 4 bit Target Fractional Value. */
    uint16_t          slgen_step_value;                         /**< 12 bit Step Integer Value. */
    uint8_t           slgen_step_frac_value;                    /**< 4 bit Step Fractional Value. */
}cy_stc_ppca_dcsg_slgen_config_t;

/** \} group_ppca_dcsg_slgen_data_structures */


/**
* \addtogroup group_ppca_dcsg_slgen_functions
* \{
*/

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Init
***************************************************************************//**
*
* Initializes and enables the DCSG Slope Generator. Configures the DCSG
* mapping, initial/target/step values (with shadow buffers), trigger
* unmasking, auto-reset, shadow transfer, and glitch filter settings.
*
* \param base The pointer to the DCSG SLGEN instance address.
*
* \param config The pointer to the SLGEN config structure \ref cy_stc_ppca_dcsg_slgen_config_t.
*
* \snippet ppca/snippet/ppca_snippet.c SNIPPET_PPCA_DCSG_SLGEN_INIT
*
******************************************************************************/
void Cy_PPCA_DCSG_SLGEN_Init(ATOPSS_SLGEN_TYPE *base, cy_stc_ppca_dcsg_slgen_config_t const *config);

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Enable
***************************************************************************//**
*
* Enables the DCSG_SLGEN
* User has to configure the initial and target values after enabling \ref cy_stc_ppca_dcsg_slgen_config_t
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_SLGEN_Enable(ATOPSS_SLGEN_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_SLGEN_CTL(base) |= PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SLGEN_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Disable
***************************************************************************//**
*
* Disables the DCSG_SLGEN. Resets the configured initial and target values.
* User has to configure the initial and target values after enabling \ref cy_stc_ppca_dcsg_slgen_config_t
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_SLGEN_Disable(ATOPSS_SLGEN_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_SLGEN_CTL(base) &= (uint32_t) ~PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SLGEN_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Set_Initial_Value
***************************************************************************//**
*
* Sets Slope Generator Initial Value.
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
* \param integer_value 12 bit Initial Integer Value
*
* \param fractional_value 4 bit Initial Fractional Value.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_SLGEN_Set_Initial_Value(ATOPSS_SLGEN_TYPE *base, uint16_t integer_value, uint8_t fractional_value)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_SLGEN_INIT(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_F, fractional_value)      |
                                      _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_I, integer_value);
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Set_Target_Value
***************************************************************************//**
*
* Sets Slope Generator Target Value.
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
* \param integer_value 12 bit Target Integer Value
*
* \param fractional_value 4 bit Target Fractional Value.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_SLGEN_Set_Target_Value(ATOPSS_SLGEN_TYPE *base, uint16_t integer_value, uint8_t fractional_value)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_SLGEN_TARGET(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_F, fractional_value)      |
                                        _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_I, integer_value);
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Set_Initial_Buf_Value
***************************************************************************//**
*
* Sets Slope Generator Shadow Initial Value.
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
* \param integer_value shadow 12 bit Target Integer Value
*
* \param fractional_value shadow 4 bit Target Fractional Value.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_SLGEN_Set_Initial_Buf_Value(ATOPSS_SLGEN_TYPE *base, uint16_t integer_value, uint8_t fractional_value)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_SLGEN_INIT_BUF(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_BUF_F, fractional_value)      |
                                          _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_BUF_I, integer_value);
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Set_Target_Buf_Value
***************************************************************************//**
*
* Sets Slope Generator Shadow Target Value.
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
* \param integer_value shadow 12 bit Target Integer Value
*
* \param fractional_value shadow 4 bit Target Fractional Value.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_SLGEN_Set_Target_Buf_Value(ATOPSS_SLGEN_TYPE *base, uint16_t integer_value, uint8_t fractional_value)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_SLGEN_TARGET_BUF(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_BUF_F, fractional_value)      |
                                            _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_BUF_I, integer_value);
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Set_Step_Value
***************************************************************************//**
*
* Sets Slope Generator Step Value.
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
* \param integer_value shadow 12 bit Step Integer Value
*
* \param fractional_value shadow 4 bit Step Fractional Value.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_SLGEN_Set_Step_Value(ATOPSS_SLGEN_TYPE *base, uint16_t integer_value, uint8_t fractional_value)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_SLGEN_STEP(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_STEP_F, fractional_value)      |
                                      _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_STEP_I, integer_value);
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Get_Debug_Status
***************************************************************************//**
*
* Returns whether SLGEN has enter into Debug state or not
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
* \return returns true if SLGEN enter debug state, else returns false.
*
******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_DCSG_SLGEN_Get_Debug_Status(ATOPSS_SLGEN_TYPE *base)
{
    return (bool)_FLD2VAL(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_DBG_STATUS, PPCA_ATOP_DCSG_SLGEN_CTL(base));        
}


/******************************************************************************
* Function Name: Cy_PPCA_DCSG_Is_SLGEN_Busy
***************************************************************************//**
*
* Returns the busy status of the DCSG_SLGEN
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
* \return returns if DCSG_SLGEN is busy or not. True: Busy, False: Not Busy
*
******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_DCSG_Is_SLGEN_Busy(ATOPSS_SLGEN_TYPE *base)
{
    return (bool)_FLD2VAL(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SLGEN_BUSY, PPCA_ATOP_DCSG_SLGEN_CTL(base));    
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Trigger_UnMask
***************************************************************************//**
*
* If Set to True Triggers are unmasked. Upon detect of Trigger will start the SL operation
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
* \param unmask Trigger mask/unmask.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_SLGEN_Trigger_UnMask(ATOPSS_SLGEN_TYPE *base, bool unmask)
{
    CY_ASSERT_L1(NULL != base);
    if(unmask)
    {
        PPCA_ATOP_DCSG_SLGEN_CTL(base) |= PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_TRIGGER_UNMASK_Msk;
    }
    else
    {
        PPCA_ATOP_DCSG_SLGEN_CTL(base) &= ~(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_TRIGGER_UNMASK_Msk);
    }
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Debug_Freeze_Enable
***************************************************************************//**
*
* The SLGEN freezes the progress of the slope generation when this is enabled and a debug signal is received on the ATOPSS. Resumes the operation when the debug signal is released
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
* \param debug_freeze enable/disable debug freeze.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DCSG_SLGEN_Debug_Freeze_Enable(ATOPSS_SLGEN_TYPE *base, bool debug_freeze)
{
    CY_ASSERT_L1(NULL != base);
    if(debug_freeze)
    {
        PPCA_ATOP_DCSG_SLGEN_CTL(base) |= PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_DBG_FREEZE_EN_Msk;
    }
    else
    {
        PPCA_ATOP_DCSG_SLGEN_CTL(base) &= ~(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_DBG_FREEZE_EN_Msk);
    }
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Get_Match_Value
***************************************************************************//**
*
* Returns the slope value at which the comparator triggered
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
* \param slope returns the 12 bit slope value at which the comparator triggered.
*
* \return returns 0: if reported value occurred before trigger. 1: If reported value occurred after trigger
*
******************************************************************************/
__STATIC_INLINE  bool Cy_PPCA_DCSG_SLGEN_Get_Match_Value(ATOPSS_SLGEN_TYPE *base, uint16_t *slope)
{
    *slope = (uint16_t)(_FLD2VAL(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_MATCH_TH_TRIG, PPCA_ATOP_DCSG_SLGEN_MATCH(base)));
    return (bool)_FLD2VAL(PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_MATCH_TH_TRIG_VALID, PPCA_ATOP_DCSG_SLGEN_MATCH(base));
}

/******************************************************************************
* Function Name: Cy_PPCA_DCSG_SLGEN_Trigger_Ramp_Generation
***************************************************************************//**
*
* Triggers Slope Generator Ramp Generation
* HW will clear this once ramp generation is complete
*
* \param base The pointer to the DCSG_SLGEN instance address.
*
******************************************************************************/
__STATIC_INLINE  void Cy_PPCA_DCSG_SLGEN_Trigger_Ramp_Generation(ATOPSS_SLGEN_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_DCSG_SLGEN_CTL(base) |= PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SLGEN_EN_TRIGGER_Msk;
}


/** \} group_ppca_dcsg_slgen_functions */



#if defined(__cplusplus)
}
#endif
#endif /*defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN) */

#endif /* CY_PPCA_DCSG_SLGEN_H */

