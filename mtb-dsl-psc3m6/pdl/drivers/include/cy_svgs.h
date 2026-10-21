/***************************************************************************//**
* \file cy_svgs.h
* \version 1.0
*
* \brief
* Provides an API declaration of the SVGS driver
*
********************************************************************************
* \copyright
* (c) 2025-2026, Infineon Technologies AG or an affiliate of
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

/**
* \addtogroup group_svgs
* \{
* The SVGS driver provides an API to access the Supply Voltage Glitch Sensor (SVGS).
* The glitch sensor is configured in privileged code and is read-only for non-privileged
* applications.
*
* The functions and other declarations used in this driver are in cy_svgs.h.
* You can include cy_pdl.h to get access to all functions and declarations in the PDL.
*
* \section group_svgs_features Features
*
* The primary use case for this block is to detect attempted glitch attacks.
* It provides voltage supervision, supply glitch detection, and over voltage detection.
*
* The glitch sensor contains five comparators supporting the following functionality.
*
* * Under Voltage Comparison (UVC) - VCCD Undershoot monitor functionality with configurable threshold.
* * Over Voltage Comparison (OVC) - VCCD Overshoot monitor functionality with configurable threshold.
* * Under Voltage (Filtered) Comparison (UVFC) - VCCD Undershoot monitor functionality with configurable threshold, with filtered VCCD signal.
* * Noise Voltage Comparison (NVC) - VCCD Noise monitor functionality with configurable threshold.
*
* - VDDQ Undershoot monitor functionality is also supported (below brown out threshold).
* - Comparator outputs are latched in retention domain, generated inside, and guaranteed to be
*   retained up to 2us in case of absence of VDDQ. i.e. it is immune to VDDQ noise up to 2us.
* - Event output and event status are observable in read only registers and can be used to
*   initiate countermeasure or reset the system in case of an attack event.
*
* \section group_svgs_trip_point Trip-point configuration
*
* PSC3-P8 devices have the following threshold configurations.
* * Threshold of UVC functionality in steps of 6.2mV. 0b000000 = 760.00mV; 0b111111 = 1150mV
* * Threshold of OVC in steps of 25mV. 0b00 = 1250mV; 0'b11 = 1325mV
* * Threshold of UVFC in steps of 6.2mV. 0b000000 = 760.00mV; 0b111111 = 1150mV
* *  Threshold of NVC in steps of 10mV. 0b0000 = 30mV; 0'b1111 = 180mV
*
* Non-PSC3-P8 devices have the following threshold configuration.
* * Threshold of UVC functionality in steps of 4mV. 0b000000 = 600mV; 0b111111 = 852mV
* * Threshold of OVC functionality in steps of 20mV. 0b00 = 990mV; 0b11 = 1050mV
* * Threshold of UVFC functionality in steps of 4mV. 0b000000 = 600mV; 0b111111 = 852mV
* * Threshold of NVC functionality in steps of 10mV. 0b0000 = 30mV; 0b1111 = 180mV
*
* \section group_svgs_more_information More Information
*
* Refer to the technical reference manual (TRM) and the device datasheet.
*
* \section group_svgs_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_svgs_macros Macros
* \defgroup group_svgs_functions Functions
* \{
*   \defgroup group_svgs_functions_general    General Functions
*   \defgroup group_svgs_functions_interrupt  Interrupt Functions
* \}
* \defgroup group_svgs_data_structures Data Structures
* \defgroup group_svgs_enums Enumerated Types
*/

#if !defined(CY_SVGS_H)
#define CY_SVGS_H

#include "cy_device.h"

#if defined (CY_IP_MXS40SVGS) || defined (CY_IP_MXS22SVGS)

#include <stddef.h>
#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_svgs_macros
* \{
*/

/** Driver major version */
#define CY_SVGS_DRV_VERSION_MAJOR       1

/** Driver minor version */
#define CY_SVGS_DRV_VERSION_MINOR       0

/** SVGS driver ID */
#define CY_SVGS_ID CY_PDL_DRV_ID(CY_PDL_RSLT_MODULE_SVGS)

/** \} group_svgs_macros */


/***************************************
*       Enumerations
***************************************/
/**
* \addtogroup group_svgs_enums
* \{
*/

/** Time constant for Under Voltage (Filtered) Comparison (UVFC) */
typedef enum
{
    CY_SVGS_UVFC_TC_20NS        = 0x00U, /**< 20 ns */
    CY_SVGS_UVFC_TC_24_4NS      = 0x01U, /**< 24.4 ns */
    CY_SVGS_UVFC_TC_29_8NS      = 0x02U, /**< 29.8 ns */
    CY_SVGS_UVFC_TC_36_4NS      = 0x03U, /**< 36.4 ns */
    CY_SVGS_UVFC_TC_44_4NS      = 0x04U, /**< 44.4 ns */
    CY_SVGS_UVFC_TC_54_3NS      = 0x05U, /**< 54.3 ns */
    CY_SVGS_UVFC_TC_66_2NS      = 0x06U, /**< 66.2 ns */
    CY_SVGS_UVFC_TC_81NS        = 0x07U, /**< 81 ns */
    CY_SVGS_UVFC_TC_98_8NS      = 0x08U, /**< 98.8 ns */
    CY_SVGS_UVFC_TC_147_3NS     = 0x0AU, /**< 147.3 ns */
    CY_SVGS_UVFC_TC_179_9NS     = 0x0BU, /**< 179.9 ns */
    CY_SVGS_UVFC_TC_219_7NS     = 0x0CU, /**< 219.7 ns */
    CY_SVGS_UVFC_TC_268_3NS     = 0x0DU, /**< 268.3 ns */
    CY_SVGS_UVFC_TC_327_5NS     = 0x0EU, /**< 327.5 ns */
    CY_SVGS_UVFC_TC_400NS       = 0x0FU, /**< 400 ns */
} cy_en_svgs_uvfc_tc_t;

/** \} group_svgs_enums */


/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_svgs_data_structures
* \{
*/

/** This structure is to hold comparator function configuration */
typedef struct
{
    bool enable;  /**<  1 = enabled; 0 = disabled */
    bool fullPower;   /**<  1 = full power; 0 = half power */
    bool mask;    /**<  1 = glitch event masked; 0 = not masked */
} cy_stc_svgs_cmp_func_t;

/** This structure is to hold comparator configuration */
typedef struct
{
    cy_stc_svgs_cmp_func_t  uvcCfg;   /**<  Under Voltage Comparison (UVC) configuration */
    cy_stc_svgs_cmp_func_t  ovcCfg;   /**<  Over Voltage Comparison (OVC) configuration */
    cy_stc_svgs_cmp_func_t  uvfcCfg;  /**<  Under Voltage (Filtered) Comparison (UVFC) configuration */
    cy_stc_svgs_cmp_func_t  nvcCfg;   /**<  Noise Voltage Comparison (NVC) configuration */
    cy_en_svgs_uvfc_tc_t    uvfcTc;   /**<  Time constant of UVFC (logarithmically equidistant) */
} cy_stc_svgs_cmp_cfg_t;

/** This structure is to hold comparator trip-point configuration */
typedef struct
{
    uint32_t uvcTrip;  /**<  Threshold of UVC. Refer to \ref group_svgs_trip_point for valid range */
    uint32_t ovcTrip;  /**<  Threshold of OVC. Refer to \ref group_svgs_trip_point for valid range */
    uint32_t uvfcTrip; /**<  Threshold of UVFC. Refer to \ref group_svgs_trip_point for valid range */
    uint32_t nvcTrip;  /**<  Threshold of NVC. Refer to \ref group_svgs_trip_point for valid range */
} cy_stc_svgs_cmp_trip_t;

/** This structure is to hold trim values */
typedef struct
{
    uint32_t vregTrim;   /**<  Regulator output voltage trim */
    uint32_t ibiasTrim;  /**<  Bias current output trim */
} cy_stc_svgs_trim_t;


/** \} group_svgs_data_structures */

/***************************************
*        Constants
***************************************/

/** \cond INTERNAL */
#define CY_SVGS_ENABLE          (0x1UL)
#define CY_SVGS_DISABLE         (0x5UL)
/** \endcond */


/***************************************
*        Function Constants
***************************************/

/**
* \addtogroup group_svgs_macros
* \{
*/

/**
* \defgroup group_svgs_status SVGS statuses
* \{
* Constants used in SVGS status
*/
#define CY_SVGS_STATUS_UVC_CAPTURED  (SVGS_SVGS_MAIN_SVGS_STATUS_UVC_CAPTURED_Msk) /**< UVC occurred since last reset */
#define CY_SVGS_STATUS_OVC_CAPTURED  (SVGS_SVGS_MAIN_SVGS_STATUS_OVC_CAPTURED_Msk) /**< OVC occurred since last reset */
#define CY_SVGS_STATUS_UVFC_CAPTURED (SVGS_SVGS_MAIN_SVGS_STATUS_UVFC_CAPTURED_Msk) /**< UVFC occurred since last reset */
#define CY_SVGS_STATUS_NVC_CAPTURED  (SVGS_SVGS_MAIN_SVGS_STATUS_NVC_CAPTURED_Msk) /**< NVC occurred since last reset */
#define CY_SVGS_STATUS_HVC_CAPTURED  (SVGS_SVGS_MAIN_SVGS_STATUS_HVC_CAPTURED_Msk) /**< HVC occurred since last reset */
#define CY_SVGS_STATUS_EN_SEQ_ACTIVE (SVGS_SVGS_MAIN_SVGS_STATUS_EN_SEQ_ACTIVE_Msk) /**< HW enable sequence is active */
#define CY_SVGS_STATUS_SVGS_ENABLED  (SVGS_SVGS_MAIN_SVGS_STATUS_SVGS_ENABLED_Msk) /**< Enable sequence complete */
/** \} */

/**
* \defgroup group_svgs_interrupt Interrupt sources
* \{
* Constants used in interrupt sources
*/
#define CY_SVGS_INTR_UVC_GLITCH      (SVGS_SVGS_MAIN_SVGS_INTR_UVC_GLITCH_Msk) /**< UVC glitch detected */
#define CY_SVGS_INTR_OVC_GLITCH      (SVGS_SVGS_MAIN_SVGS_INTR_OVC_GLITCH_Msk) /**< OVC glitch detected  */
#define CY_SVGS_INTR_UVFC_GLITCH     (SVGS_SVGS_MAIN_SVGS_INTR_UVFC_GLITCH_Msk) /**< UVFC glitch detected  */
#define CY_SVGS_INTR_NVC_GLITCH      (SVGS_SVGS_MAIN_SVGS_INTR_NVC_GLITCH_Msk) /**< NVC glitch detected  */
#define CY_SVGS_INTR_HVC_GLITCH      (SVGS_SVGS_MAIN_SVGS_INTR_HVC_GLITCH_Msk) /**< HVC glitch detected  */
/** \} */

/** \} group_svgs_macros */

/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_svgs_functions
* \{
*/

/**
* \addtogroup group_svgs_functions_general
* \{
*/
__STATIC_INLINE void Cy_SVGS_Enable (SVGS_Type *base);
__STATIC_INLINE void Cy_SVGS_Disable (SVGS_Type *base);
__STATIC_INLINE uint32_t Cy_SVGS_GetStatus (const SVGS_Type *base);
void Cy_SVGS_GetCmpCfg (const SVGS_Type *base, cy_stc_svgs_cmp_cfg_t *cfg);
void Cy_SVGS_GetCmpTrip (const SVGS_Type *base, cy_stc_svgs_cmp_trip_t *trip);
void Cy_SVGS_GetTrim (const SVGS_Type *base, cy_stc_svgs_trim_t *trim);
/** \} group_svgs_functions_general */

/**
* \addtogroup group_svgs_functions_interrupt
* \{
*/
__STATIC_INLINE uint32_t Cy_SVGS_GetInterruptStatus(const SVGS_Type *base);
__STATIC_INLINE void Cy_SVGS_ClearInterrupt(SVGS_Type *base, uint32_t interrupt);
__STATIC_INLINE void Cy_SVGS_SetInterruptMask(SVGS_Type *base, uint32_t interrupt);
__STATIC_INLINE uint32_t Cy_SVGS_GetInterruptMask(const SVGS_Type *base);
__STATIC_INLINE uint32_t Cy_SVGS_GetInterruptStatusMasked(const SVGS_Type *base);
__STATIC_INLINE void Cy_SVGS_SetInterrupt(SVGS_Type *base, uint32_t interrupt);
/** \} group_svgs_functions_interrupt */

/**
* \addtogroup group_svgs_functions_general
* \{
*/

/*******************************************************************************
* Function Name: Cy_SVGS_Enable
****************************************************************************//**
*
* Enables the glitch sensor.
*
* \note The glitch sensor is enabled/disabled at boot in the OEM_POLICY.
*
* \param base
* Pointer to structure describing registers
*
*******************************************************************************/
__STATIC_INLINE void Cy_SVGS_Enable (SVGS_Type *base)
{
    CY_REG32_CLR_SET(base->SVGS_MAIN.SVGS_CTL, SVGS_SVGS_MAIN_SVGS_CTL_ENABLE, CY_SVGS_ENABLE);
}

/*******************************************************************************
* Function Name: Cy_SVGS_Disable
****************************************************************************//**
*
* Disables the glitch sensor.
*
* \param base
* Pointer to structure describing registers
*
*******************************************************************************/
__STATIC_INLINE void Cy_SVGS_Disable (SVGS_Type *base)
{
    CY_REG32_CLR_SET(base->SVGS_MAIN.SVGS_CTL, SVGS_SVGS_MAIN_SVGS_CTL_ENABLE, CY_SVGS_DISABLE);
}

/*******************************************************************************
* Function Name: Cy_SVGS_GetStatus
****************************************************************************//**
*
* Reads the glitch event status.
*
* \param base
* Pointer to structure describing registers
*
* \return
* SVGS status. Options are detailed in \ref group_svgs_status macros
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SVGS_GetStatus (const SVGS_Type *base)
{
    return base->SVGS_MAIN.SVGS_STATUS;
}

/** \} group_svgs_functions_general */

/**
* \addtogroup group_svgs_functions_interrupt
* \{
*/

/*******************************************************************************
* Function Name: Cy_SVGS_GetInterruptStatus
****************************************************************************//**
*
* Returns the SVGS interrupt status.
*
* \param base
* Pointer to structure describing registers
*
* \return
* The status of SVGS interrupt. Options are detailed in \ref group_svgs_interrupt macros
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SVGS_GetInterruptStatus(const SVGS_Type *base)
{
    return base->SVGS_MAIN.SVGS_INTR;
}

/*******************************************************************************
* Function Name: Cy_SVGS_ClearInterrupt
****************************************************************************//**
*
* Clears the SVGS interrupt status.
*
* \note The SVGS block must be reset (disabled and enabled) to clear the interrupt.
* Otherwise the event status remains set and the interrupt will continue to trigger.
*
* \param base
* Pointer to structure describing registers
*
* \param interrupt
* The interrupt value. Options are detailed in \ref group_svgs_interrupt macros
*
*******************************************************************************/
__STATIC_INLINE void Cy_SVGS_ClearInterrupt(SVGS_Type *base, uint32_t interrupt)
{
    base->SVGS_MAIN.SVGS_INTR = interrupt;
    /* This dummy reading is necessary here. It provides a guarantee that the
    interrupt is cleared at returning from this function. */
    (void) base->SVGS_MAIN.SVGS_INTR;
}

/*******************************************************************************
* Function Name: Cy_SVGS_SetInterruptMask
****************************************************************************//**
*
* Sets the SVGS interrupt mask.
*
* \param base
* Pointer to structure describing registers
*
* \param interrupt
* The interrupt mask value. Options are detailed in \ref group_svgs_interrupt macros
*
*******************************************************************************/
__STATIC_INLINE void Cy_SVGS_SetInterruptMask(SVGS_Type *base, uint32_t interrupt)
{
    base->SVGS_MAIN.SVGS_INTR_MASK = interrupt;
}

/*******************************************************************************
* Function Name: Cy_SVGS_GetInterruptMask
****************************************************************************//**
*
* Gets the SVGS interrupt mask.
*
* \param base
* Pointer to structure describing registers
*
* \return
* The interrupt mask value. Options are detailed in \ref group_svgs_interrupt macros
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SVGS_GetInterruptMask(const SVGS_Type *base)
{
    return base->SVGS_MAIN.SVGS_INTR_MASK;
}

/*******************************************************************************
* Function Name: Cy_SVGS_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the logical AND of the corresponding INTR and INTR_MASK fields
* in a single-load operation for the SVGS interrupt.
*
* \param base
* Pointer to structure describing registers
*
* \return
* The interrupt status masked with configured mask value.
* Options are detailed in \ref group_svgs_interrupt macros
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SVGS_GetInterruptStatusMasked(const SVGS_Type *base)
{
    return base->SVGS_MAIN.SVGS_INTR_MASKED;
}

/*******************************************************************************
* Function Name: Cy_SVGS_SetInterrupt
****************************************************************************//**
*
* Sets the SVGS interrupt directly through CPU register write.
*
* \param base
* Pointer to structure describing registers
*
* \param interrupt
* The interrupt value. Options are detailed in \ref group_svgs_interrupt macros
*
*******************************************************************************/
__STATIC_INLINE void Cy_SVGS_SetInterrupt(SVGS_Type *base, uint32_t interrupt)
{
    base->SVGS_MAIN.SVGS_INTR_SET = interrupt;
}

/** \} group_svgs_functions_interrupt */

/** \} group_svgs_functions */

#if defined(__cplusplus)
}
#endif

#endif /* #if defined (CY_IP_MXS40SVGS) || defined (CY_IP_MXS22SVGS) */

#endif /* CY_SVGS_H */

/** \} group_svgs */

/* [] END OF FILE */
