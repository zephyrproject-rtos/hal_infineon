/***************************************************************************//**
* \file cy_lpcomp.h
* \version 1.0.1
*
* This file provides constants and parameter values for the low-power
* comparator.
*
********************************************************************************
* \copyright
* (c) (2016-2021), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
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

/**
* \addtogroup group_lpcomp
* \{
* Provides access to the low-power comparators implemented using the fixed-function
* low-power comparator block.
*
* The functions and other declarations used in this driver are in cy_lpcomp.h.
* You can include cy_pdl.h to get access to all the functions and declarations in
* the PDL.
*
* These comparators can perform fast analog signal comparison of
* external analog signals in all system power modes. The low-power comparator
* output can be inspected by the CPU, used as an interrupt/wakeup source to the
* CPU when in Low-power mode (Sleep or Deep Sleep) or fed to DSI as
* an asynchronous or synchronous signal (level or pulse).
*
* \section group_lpcomp_section_Configuration_Considerations Configuration Considerations
* To set up a comparator, configure the inputs, output, mode, interrupts, and
* other configuration parameters.
*
* 1) Configure the inputs and the output using the GPIO API. The high-impedance
*    Analog drive mode is for the inputs and Strong drive mode is for the output.
*
*    a. Connecting inputs using dedicated pins:
*       \snippet lpcomp_snippet.c LPCOMP_SNIPPET_CONFIG_PINS_DIRECT
*    b. Connecting low-power comparator's inputs using AMUXBUS:
*       \snippet lpcomp_snippet.c LPCOMP_SNIPPET_CONFIG_PINS_AMUXBUS
*
*   \note The pins assignment is for the PSOC 4100S Plus (CY8CKIT-149). The pin
*   numbers may differ, please refer to the device documentation for the more
*   details.
*
* 2) Initialize and enable the driver:
* \snippet lpcomp_snippet.c LPCOMP_SNIPPET_EXT_CONFIG_INIT
* \snippet lpcomp_snippet.c LPCOMP_SNIPPET_CONFIG_INIT
*
* 3) Configure the interrupt requests if the interrupt event
* triggering is needed. Additionally, enable the global interrupts and
* initialize the referenced interrupt by setting the priority and the interrupt
* vector using the \ref group_sysint driver API:
* \snippet lpcomp_snippet.c LPCOMP_SNIPPET_EXT_CONFIG_ISR
* \snippet lpcomp_snippet.c LPCOMP_SNIPPET_CONFIG_ISR
*
* 4) The comparator output can be monitored using the Cy_LPComp_GetCompare()
* function, using the comparator interrupt (if the interrupt is enabled)
* or using GPIO pin (if routed directly through the HSIOM).
*
* \note The interrupt is not cleared automatically - it is the user's
* responsibility. The interrupt is cleared by writing "1" in the
* corresponding interrupt-register bit-position. The preferred way to clear
* interrupt sources is using the Cy_LPComp_ClearInterrupt() function.
*
* \note Individual comparator interrupt outputs are ORed together
* as a single asynchronous interrupt source before they are sent out and
* used to wake up the system in Low-power mode.
*
* \section group_lpcomp_lp Low Power Support
* The driver provides the callback functions to facilitate the Low-power mode
* transition. The callback \ref Cy_LPComp_DeepSleepCallback must be called
* during the execution of \ref Cy_SysPm_CpuEnterDeepSleep.
*
* To trigger the callback execution, the callback must be registered before
* calling the mode transition function. Refer to \ref group_syspm driver for
* more information about low-power mode transitions.
*
* \section group_lpcomp_more_information More Information
*
* Refer to the appropriate device technical reference manual (TRM) for
* a detailed description of the registers.
*
* \section group_lpcomp_Changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0.1</td>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_lpcomp_macros Macros
* \defgroup group_lpcomp_functions Functions
*   \{
*       \defgroup group_lpcomp_functions_syspm_callback Low Power Callback
*   \}
* \defgroup group_lpcomp_data_structures Data Structures
* \defgroup group_lpcomp_enums Enumerated Types
*/

#ifndef CY_LPCOMP_PDL_H
#define CY_LPCOMP_PDL_H

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/

#include "cy_device.h"

#if defined (CY_IP_M0S8LPCOMP)

#include <stdbool.h>
#include <stddef.h>
#include "cy_syslib.h"
#include "cy_syspm.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
* \addtogroup group_lpcomp_macros
* \{
*/

/** Driver major version */
#define CY_LPCOMP_DRV_VERSION_MAJOR       1

/** Driver minor version */
#define CY_LPCOMP_DRV_VERSION_MINOR       0

/******************************************************************************
* API Constants
******************************************************************************/

/**< LPCOMP PDL ID */
#define CY_LPCOMP_ID                                CY_PDL_DRV_ID(0x23U)

/** The number of the channels */
#define CY_LPCOMP_MAX_CHANNEL_NUM                   (2U)

/** The comparator 0 interrupt mask */
#define CY_LPCOMP_CHANNEL0_INTR                     (LPCOMP_INTR_COMP1_Msk)

/** The comparator 1 interrupt mask */
#define CY_LPCOMP_CHANNEL1_INTR                     (LPCOMP_INTR_COMP2_Msk)


/** \cond INTERNAL_MACROS */
/*******************************************************************************
* Registers Constants
*******************************************************************************/

/* Internal constants for Cy_LPComp_ZeroCal() & Cy_LPComp_LoadTrim() */
#define CY_LPCOMP_TRIMB_SHIFT                   (8U)

#define CY_LPCOMP_TRIMA_SIGNBIT                 (4U)
#define CY_LPCOMP_TRIMB_SIGNBIT                 (4U)

#define CY_LPCOMP_TRIMA_MAX_VALUE               (15U)
#define CY_LPCOMP_TRIMB_MAX_VALUE               (7U)

#define CY_LPCOMP_TRIM2_COMP1_TRIMB_Msk         (0x17UL)
#define CY_LPCOMP_TRIM4_COMP2_TRIMB_Msk         (0x17UL)

#define CY_LPCOMP_CMP1_OUTPUT_CONFIG_Pos        LPCOMP_CONFIG_DSI_BYPASS1_Pos
#define CY_LPCOMP_CMP2_OUTPUT_CONFIG_Pos        LPCOMP_CONFIG_DSI_BYPASS2_Pos

#define CY_LPCOMP_CMP1_OUTPUT_CONFIG_Msk        (LPCOMP_CONFIG_DSI_BYPASS1_Msk | \
                                                 LPCOMP_CONFIG_DSI_LEVEL1_Msk)

#define CY_LPCOMP_CMP2_OUTPUT_CONFIG_Msk        (LPCOMP_CONFIG_DSI_BYPASS2_Msk | \
                                                 LPCOMP_CONFIG_DSI_LEVEL2_Msk)


/** \endcond */
/** \} group_lpcomp_macros */

/**
* \addtogroup group_lpcomp_enums
* \{
*/

/******************************************************************************
 * Enumerations
 *****************************************************************************/
/** The LPCOMP output modes. */
typedef enum
{
    CY_LPCOMP_OUT_PULSE  = 0U,  /**< The DSI output with the pulse option, no bypass. */
    CY_LPCOMP_OUT_DIRECT = 1U,  /**< The bypass mode, the direct output of a comparator. */
    CY_LPCOMP_OUT_SYNC   = 2U   /**< The DSI output with the level option, it is similar
                                  to the bypass mode but it is 1 cycle slower than the bypass. */
} cy_en_lpcomp_out_t;

/** The hysteresis mode. */
typedef enum
{
    CY_LPCOMP_HYST_ENABLE  = 0U,  /**< Enables the 10 mV hysteresis level. */
    CY_LPCOMP_HYST_DISABLE = 1U   /**< Disables the 10 mV hysteresis level. */
} cy_en_lpcomp_hyst_t;

/** The channel number. */
typedef enum
{
    CY_LPCOMP_CHANNEL_0  = 0x1U,  /**< The comparator 0. */
    CY_LPCOMP_CHANNEL_1  = 0x2U   /**< The comparator 1. */
} cy_en_lpcomp_channel_t;

/** Interrupt mode. */
typedef enum
{
    CY_LPCOMP_INTR_DISABLE = 0U,  /**< The interrupt disabled, no interrupt will be detected. */
    CY_LPCOMP_INTR_RISING  = 1U,  /**< The interrupt on the rising edge. */
    CY_LPCOMP_INTR_FALLING = 2U,  /**< The interrupt on the falling edge. */
    CY_LPCOMP_INTR_BOTH    = 3U   /**< The interrupt on both rising and falling edges. */
} cy_en_lpcomp_int_t;

/** The power-mode selection. */
typedef enum
{
    CY_LPCOMP_MODE_SLOW     = 0U,  /**< Slow operating mode (uses less power). */
    CY_LPCOMP_MODE_FAST     = 1U,  /**< Fast operating mode (uses more power). */
    CY_LPCOMP_MODE_ULP      = 2U   /**< Ultra-low-power operating mode (uses lowest possible power). */
} cy_en_lpcomp_pwr_t;

/** LPCOMP error code. */
typedef enum
{
    CY_LPCOMP_SUCCESS = 0x00U,                                            /**< Successful. */
    CY_LPCOMP_BAD_PARAM = CY_LPCOMP_ID | CY_PDL_STATUS_ERROR | 0x01U,     /**< One or more invalid parameters. */
} cy_en_lpcomp_status_t;

/** \} group_lpcomp_enums */

/**
* \addtogroup group_lpcomp_data_structures
* \{
*/

/******************************************************************************
 * Structures
 *****************************************************************************/

/** The LPCOMP configuration structure. */
typedef struct {
    cy_en_lpcomp_out_t  outputMode;  /**< \ref cy_en_lpcomp_out_t. */
    cy_en_lpcomp_hyst_t hysteresis;  /**< Enables or disables the hysteresis */
    cy_en_lpcomp_pwr_t power;        /**< Sets the power mode */
    cy_en_lpcomp_int_t intType;      /**< Sets the interrupt mode */
} cy_stc_lpcomp_config_t;

/** The LPCOMP context structure */
typedef struct {
    cy_en_lpcomp_int_t intType[CY_LPCOMP_MAX_CHANNEL_NUM];   /**< The interrupt type \ref cy_en_lpcomp_int_t. */
} cy_stc_lpcomp_context_t;

/** \} group_lpcomp_data_structures */

/** \cond INTERNAL_MACROS */

/******************************************************************************
 * Macros
 *****************************************************************************/
#define CY_LPCOMP_IS_CHANNEL_VALID(channel)      (((channel) == CY_LPCOMP_CHANNEL_0) || \
                                                  ((channel) == CY_LPCOMP_CHANNEL_1))
#define CY_LPCOMP_IS_OUT_MODE_VALID(mode)        (((mode) == CY_LPCOMP_OUT_PULSE) || \
                                                  ((mode) == CY_LPCOMP_OUT_DIRECT) || \
                                                  ((mode) == CY_LPCOMP_OUT_SYNC))
#define CY_LPCOMP_IS_HYSTERESIS_VALID(hyst)      (((hyst) == CY_LPCOMP_HYST_ENABLE) || \
                                                  ((hyst) == CY_LPCOMP_HYST_DISABLE))
#define CY_LPCOMP_IS_INTR_MODE_VALID(intr)       (((intr) == CY_LPCOMP_INTR_DISABLE) || \
                                                  ((intr) == CY_LPCOMP_INTR_RISING) || \
                                                  ((intr) == CY_LPCOMP_INTR_FALLING) || \
                                                  ((intr) == CY_LPCOMP_INTR_BOTH))
#define CY_LPCOMP_IS_POWER_VALID(power)          (((power) == CY_LPCOMP_MODE_SLOW) || \
                                                  ((power) == CY_LPCOMP_MODE_FAST) || \
                                                  ((power) == CY_LPCOMP_MODE_ULP))
#define CY_LPCOMP_IS_INTR_VALID(intr)             (0UL == ((intr) & ~(LPCOMP_INTR_COMP1_Msk | LPCOMP_INTR_COMP2_Msk)))

/** \endcond */

/**
* \addtogroup group_lpcomp_functions
* \{
*/

/******************************************************************************
* Functions
*******************************************************************************/

cy_en_lpcomp_status_t Cy_LPComp_Init(LPCOMP_Type *base, cy_en_lpcomp_channel_t channel, const cy_stc_lpcomp_config_t *config, cy_stc_lpcomp_context_t *context);
void Cy_LPComp_Enable(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_stc_lpcomp_context_t *context);
void Cy_LPComp_Disable(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_stc_lpcomp_context_t *context);
__STATIC_INLINE uint32_t Cy_LPComp_GetCompare(LPCOMP_Type const * base, cy_en_lpcomp_channel_t channel);
void Cy_LPComp_SetPower(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_en_lpcomp_pwr_t power);
void Cy_LPComp_SetHysteresis(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_en_lpcomp_hyst_t hysteresis);
void Cy_LPComp_SetOutputMode(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_en_lpcomp_out_t outType);
void Cy_LPComp_SetInterruptTriggerMode(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_en_lpcomp_int_t intType, cy_stc_lpcomp_context_t *context);
uint32_t Cy_LPComp_ZeroCal(LPCOMP_Type const * base, cy_en_lpcomp_channel_t channel);
void Cy_LPComp_LoadTrim(LPCOMP_Type const * base, cy_en_lpcomp_channel_t channel, uint32_t trimVal);
__STATIC_INLINE uint32_t Cy_LPComp_GetInterruptStatus(LPCOMP_Type const * base);
__STATIC_INLINE void Cy_LPComp_ClearInterrupt(LPCOMP_Type* base, uint32_t interrupt);
__STATIC_INLINE void Cy_LPComp_SetInterrupt(LPCOMP_Type* base, uint32_t interrupt);
__STATIC_INLINE uint32_t Cy_LPComp_GetInterruptMask(LPCOMP_Type const * base);
__STATIC_INLINE void Cy_LPComp_SetInterruptMask(LPCOMP_Type* base, uint32_t interrupt);
__STATIC_INLINE uint32_t Cy_LPComp_GetInterruptStatusMasked(LPCOMP_Type const * base);
/** \addtogroup group_lpcomp_functions_syspm_callback
* The driver supports SysPm callback for Deep Sleep transition.
* \{
*/
cy_en_syspm_status_t Cy_LPComp_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);
/** \} */


/*******************************************************************************
* Function Name: Cy_LPComp_GetCompare
****************************************************************************//**
*
* Returns a non-zero value when the voltage connected to the
* positive input is greater than the negative input voltage.
*
* \param *base
* The LPComp register structure-pointer.
*
* \param channel
* The LPComp channel index.
*
* \return LPComp compare result.
* The value is a non-zero value when the voltage connected to the positive input
* is greater than the negative input voltage.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_LPComp_GetCompare(LPCOMP_Type const * base, cy_en_lpcomp_channel_t channel)
{
    uint32_t result;

    CY_ASSERT_L3(CY_LPCOMP_IS_CHANNEL_VALID(channel));

    if (CY_LPCOMP_CHANNEL_0 == channel)
    {
        result = _FLD2VAL(LPCOMP_CONFIG_OUT1, LPCOMP_CONFIG(base));
    }
    else
    {
        result = _FLD2VAL(LPCOMP_CONFIG_OUT2, LPCOMP_CONFIG(base));
    }

    return (result);
}


/*******************************************************************************
* Function Name: Cy_LPComp_SetInterruptMask
****************************************************************************//**
*
* Configures which bits of the interrupt request register trigger an interrupt
* event.
*
* \param *base
* The LPCOMP register structure-pointer.
*
* \param interrupt
* Interrupt mask: \ref CY_LPCOMP_CHANNEL0_INTR and \ref CY_LPCOMP_CHANNEL1_INTR.
*
*******************************************************************************/
__STATIC_INLINE void Cy_LPComp_SetInterruptMask(LPCOMP_Type* base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_LPCOMP_IS_INTR_VALID(interrupt));

    LPCOMP_INTR_MASK(base) = interrupt & (LPCOMP_INTR_COMP1_Msk | LPCOMP_INTR_COMP2_Msk);
}


/*******************************************************************************
* Function Name: Cy_LPComp_GetInterruptMask
****************************************************************************//**
*
*  Returns an interrupt mask.
*
* \param *base
* The LPCOMP register structure-pointer.
*
* \return
* Interrupt mask: \ref CY_LPCOMP_CHANNEL0_INTR and \ref CY_LPCOMP_CHANNEL1_INTR.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_LPComp_GetInterruptMask(LPCOMP_Type const * base)
{
    return LPCOMP_INTR_MASK(base);
}


/*******************************************************************************
* Function Name: Cy_LPComp_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns an interrupt request register masked by an interrupt mask.
* Returns the result of the bitwise AND operation between the corresponding
* interrupt request and mask bits.
*
* \param *base
* The LPCOMP register structure-pointer.
*
* \return Interrupt mask: \ref CY_LPCOMP_CHANNEL0_INTR and \ref CY_LPCOMP_CHANNEL1_INTR.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_LPComp_GetInterruptStatusMasked(LPCOMP_Type const * base)
{
    return LPCOMP_INTR_MASKED(base);
}


/*******************************************************************************
* Function Name: Cy_LPComp_GetInterruptStatus
****************************************************************************//**
*
* Returns the status of 2 different LPCOMP interrupt requests.
*
* \param *base
* The LPCOMP register structure-pointer.
*
* \return
* Interrupt mask: \ref CY_LPCOMP_CHANNEL0_INTR and \ref CY_LPCOMP_CHANNEL1_INTR.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_LPComp_GetInterruptStatus(LPCOMP_Type const * base)
{
    return LPCOMP_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_LPComp_ClearInterrupt
****************************************************************************//**
*
*  Clears LPCOMP interrupts by setting each bit.
*
* \param *base
* The LPCOMP register structure-pointer.
*
* \param interrupt status: \ref CY_LPCOMP_CHANNEL0_INTR and \ref CY_LPCOMP_CHANNEL1_INTR.
*
*******************************************************************************/
__STATIC_INLINE void Cy_LPComp_ClearInterrupt(LPCOMP_Type* base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_LPCOMP_IS_INTR_VALID(interrupt));

    LPCOMP_INTR(base) = (interrupt & (LPCOMP_INTR_COMP1_Msk | LPCOMP_INTR_COMP2_Msk));
    (void) LPCOMP_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_LPComp_SetInterrupt
****************************************************************************//**
*
* Sets a software interrupt request.
* Used for a combined interrupt signal from the global
* signal reference. Also, can be used from either component instance
* to trigger either or both software interrupts. It sets the INTR_SET interrupt
* mask.
*
* \param *base
* The LPCOMP register structure-pointer.
*
* \param interrupt
* Interrupt status: \ref CY_LPCOMP_CHANNEL0_INTR and \ref CY_LPCOMP_CHANNEL1_INTR.
*
*******************************************************************************/
__STATIC_INLINE void Cy_LPComp_SetInterrupt(LPCOMP_Type* base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_LPCOMP_IS_INTR_VALID(interrupt));

    LPCOMP_INTR_SET(base) = (interrupt & (LPCOMP_INTR_COMP1_Msk | LPCOMP_INTR_COMP2_Msk));
}


/** \} group_lpcomp_functions */

#ifdef __cplusplus
}
#endif

#endif /* CY_IP_M0S8LPCOMP */

#endif /* CY_LPCOMP_PDL_H */

/** \} group_lpcomp */

/* [] END OF FILE */
