/***************************************************************************//**
* \file cy_usbpd_common.h
* \version 2.110
*
* Provides Common Header File of the USBPD driver.
*
********************************************************************************
* \copyright
* (c) (2021-2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _CY_USBPD_COMMON_H_
#define _CY_USBPD_COMMON_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_flash.h"
#include "cy_syslib.h"
#include "cy_syspm.h"
#include "cy_usbpd_defines.h"
#include "cy_usbpd_regs.h"

/**
* \addtogroup group_usbpd_common
* \{
* USBPD driver common data structures.
*
* \defgroup group_usbpd_common_macros Macros
* \defgroup group_usbpd_common_enums Enumerated Types
* \defgroup group_usbpd_common_data_structures Data Structures
*/

/**
* \addtogroup group_usbpd_common_macros
* \{
*/

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

/**  Get the maximum from among two numbers. */
#define CY_USBPD_GET_MAX(a,b)    (((a) > (b)) ? (a) : (b))

/**  Get the minimum from among two numbers. */
#define CY_USBPD_GET_MIN(a,b)    (((a) > (b)) ? (b) : (a))

/** Integer division - round up to next integer. */
#define CY_USBPD_DIV_ROUND_UP(x, y) (((x) + ((y) - 1)) / (y))

/** Integer division - round to nearest integer. */
#define CY_USBPD_DIV_ROUND_NEAREST(x, y) (((x) + ((y) / 2u)) / (y))

/** Combine two bytes to create one 16-bit WORD. */
#define CY_USBPD_MAKE_WORD(hi,lo)                        (((uint16_t)(hi) << 8) | ((uint16_t)(lo)))

/**
 * @brief Combine four bytes to create one 32-bit DWORD.
 */
#define CY_USBPD_MAKE_DWORD(b3,b2,b1,b0)                         \
    (((uint32_t)(b3) << 24) | ((uint32_t)(b2) << 16) |  \
     ((uint32_t)(b1) << 8) | ((uint32_t)(b0)))

/** Combine two WORDs to create one DWORD. */
#define CY_USBPD_MAKE_DWORD_FROM_WORD(hi,lo)             (((uint32_t)(hi) << 16) | ((uint32_t)(lo)))

/** Retrieve the MSB from a WORD. */
#define CY_USBPD_WORD_GET_MSB(w)         ((uint8_t)((w) >> 8))

/** Retrieve the LSB from a WORD. */
#define CY_USBPD_WORD_GET_LSB(w)         ((uint8_t)((w) & 0xFF))

/** Retrieve the Upper nibble from a BYTE. */
#define CY_USBPD_BYTE_GET_UPPER_NIBBLE(w)         ((uint8_t)(((w) >> 4) & 0xF))

/** Retrieve the Lower nibble from a BYTE. */
#define CY_USBPD_BYTE_GET_LOWER_NIBBLE(w)         ((uint8_t)((w) & 0xF))

/** Retrieve the LSB from a DWORD. */
#define CY_USBPD_DWORD_GET_BYTE0(dw)     ((uint8_t)((dw) & 0xFFUL))

/** Retrieve the bits 15-8 from a DWORD. */
#define CY_USBPD_DWORD_GET_BYTE1(dw)     ((uint8_t)(((dw) >> 8) & 0xFFUL))

/** Retrieve the bits 23-16 from a DWORD. */
#define CY_USBPD_DWORD_GET_BYTE2(dw)     ((uint8_t)(((dw) >> 16) & 0xFFUL))

/** Retrieve the MSB from a DWORD. */
#define CY_USBPD_DWORD_GET_BYTE3(dw)     ((uint8_t)(((dw) >> 24) & 0xFFUL))

#if (CY_FLASH_SIZEOF_ROW == 64U)
/** Flash row shift number. */
#define CCG_FLASH_ROW_SHIFT_NUM          (6u)
#elif (CY_FLASH_SIZEOF_ROW == 128U)
/** Flash row shift number. */
#define CCG_FLASH_ROW_SHIFT_NUM          (7u)
/** Flash row shift number. */
#elif (CY_FLASH_SIZEOF_ROW == 256U)
/** Flash row shift number. */
#define CCG_FLASH_ROW_SHIFT_NUM          (8u)
#endif /* CY_FLASH_SIZEOF_ROW */

/**
 * @brief Macro to combine 4 bytes in reverse order to make a 32-bit integer.
 * @param b Input array of bytes to be combined.
 * @param i Index into the input byte array.
 */
#define CY_USBPD_REV_BYTE_ORDER(b,i)                    \
          ( (uint32_t) (b)[(i)    ] << 24 )             \
        | ( (uint32_t) (b)[(i) + 1] << 16 )             \
        | ( (uint32_t) (b)[(i) + 2] <<  8 )             \
        | ( (uint32_t) (b)[(i) + 3]       );            \

/** Update a single field in a register. It first clears the field and then updates the data. */
#define CY_USBPD_REG_FIELD_UPDATE(reg,field,value)               \
    ((reg) = (((reg) & ~(field##_MASK)) | ((value) << (field##_POS))))
    
/** Update a single field in a register. It first clears the field and then updates the data. */
#define CY_USBPD_REG_FIELD_UPDATE_MTB(reg,field,value)               \
    ((reg) = (((reg) & ~(field##_Msk)) | ((value) << (field##_Pos))))

/** Retrieve a specific field from a register. */
#define CY_USBPD_REG_FIELD_GET(reg,field)                        \
    (((reg) & field##_MASK) >> field##_POS)

/** Default RSENSE value is 5mOhm. */
#define LSCSA_DEF_RSENSE_P0        (50u)

/** Default RSENSE value is 5mOhm. */
#define LSCSA_DEF_RSENSE_P1        (50u)

/** @cond DOXYGEN_HIDE */
/* Gain settings */
#define LSCSA_AV_SEL_150                        (0x1Cu)
#define LSCSA_AV_SEL_125                        (0x18u)
#define LSCSA_AV_SEL_35                         (0x03u)

/*
 * The maximum gain * Vsense value which can be accurately sampled. Above this,
 * the gain has to be lowered. The ideal value for low current is 125 and for
 * high current, it is 35. This threshold (in mV) is used to switch between the
 * gain.
 */
#define LSCSA_GAIN_MAX_VALUE                    (1850u)

/** @endcond */

#if PDL_VBAT_GND_SCP_ENABLE
/** Battery to ground short circuit protection mode */
#define VBAT_GND_SCP_MODE_INT_AUTOCTRL (2u)
#endif /* PDL_VBAT_GND_SCP_ENABLE */

/** VSafe5V margin for Fast Role Swap. */
#define CY_PD_VSAFE_5V_FRS_SWAP_RX_MARGIN         (10)

/** \} group_usbpd_common_macros */

/** Forward declaration for USBPD-IP context structure */
struct cy_stc_usbpd_context_t_;

/*******************************************************************************
*                            Enumerated Types
*******************************************************************************/

/**
* \addtogroup group_usbpd_common_enums
* \{
*/

/** Enum to hold SBU connection state. There is an internal switch to route SBU1/SBU2 signals
 * to AUX_P/AUX_N, LSTX/LSRX, or Isolate. Only applicable to PMG1S1, PMG1S2 and PMG1S3. */
typedef enum
{
    CY_USBPD_SBU_NOT_CONNECTED,                  /**< SBU pin is isolated. */
    CY_USBPD_SBU_CONNECT_AUX1,                   /**< Connect SBU pin to AUX_P. */
    CY_USBPD_SBU_CONNECT_AUX2,                   /**< Connect SBU pin to AUX_N. */
    CY_USBPD_SBU_CONNECT_LSTX,                   /**< Connect SBU pin to LSTX. */
    CY_USBPD_SBU_CONNECT_LSRX,                   /**< Connect SBU pin to LSRX. */
    CY_USBPD_SBU_CONNECT_DBG1,                   /**< Connect SBU pin to DEBUG1. */
    CY_USBPD_SBU_CONNECT_DBG2,                   /**< Connect SBU pin to DEBUG2. */
    CY_USBPD_SBU_MAX_STATE                       /**< Invalid value: not supported. */
} cy_en_usbpd_sbu_switch_state_t;

/** List of possible settings for the DP/DM MUX. Only applicable to PMG1S1. */
typedef enum
{
    CY_USBPD_DPDM_MUX_CONN_NONE         = 0x00,          /**< No connections enabled through the DPDM Mux. */
    CY_USBPD_DPDM_MUX_CONN_USB_TOP      = 0x11,          /**< Connect D+/D- to D+/D- on the top side of the connector. */
    CY_USBPD_DPDM_MUX_CONN_UART_TOP     = 0x22,          /**< Connect UART TX/RX to D+/D- on the top side of the connector. */
    CY_USBPD_DPDM_MUX_CONN_USB_BOT      = 0x44,          /**< Connect D+/D- to D+/D- on the bottom side of the connector. */
    CY_USBPD_DPDM_MUX_CONN_UART_BOT     = 0x88,          /**< Connect UART TX/RX to D+/D- on the bottom side of the connector. */
    CY_USBPD_DPDM_MUX_CONN_USB_TOP_UART = 0x99,          /**< Connect D+/D- to top and UART TX/RX to bottom side. */
    CY_USBPD_DPDM_MUX_CONN_USB_BOT_UART = 0x66           /**< Connect D+/D- to bottom and UART TX/RX to top side. */
} cy_en_usbpd_dpdm_mux_cfg_t;

/**
 * Enum to hold resistor configuration for AUX1 and AUX2. Values assigned
 * are the bit position of corresponding configuration in sbu_ctrl register.
 * Only applicable to PMG1S2 and PMG1S3.
 */
typedef enum
{
    CY_USBPD_AUX_NO_RESISTOR = 0,                        /**< No resistor. */
    CY_USBPD_AUX_1_1MEG_PU_RESISTOR = 9,                 /**< AUX1 1M0hm Pullup resistor. */
    CY_USBPD_AUX_1_100K_PD_RESISTOR = 10,                /**< AUX1 100KOhm Pulldown resistor. */
    CY_USBPD_AUX_1_470K_PD_RESISTOR = 11,                /**< AUX1 470KOhm Pulldown resistor. */
    CY_USBPD_AUX_2_100K_PU_RESISTOR = 12,                /**< AUX2 100KOhm Pullup resistor. */
    CY_USBPD_AUX_2_4P7MEG_PD_RESISTOR = 13,              /**< AUX2 4.7M0hm Pulldown resistor. */
    CY_USBPD_AUX_2_1MEG_PD_RESISTOR = 14,                /**< AUX2 1M0hm Pulldown resistor. */
    CY_USBPD_AUX_MAX_RESISTOR_CONFIG                     /**< Not supported. */
} cy_en_usbpd_aux_resistor_config_t;

/** List of HPD events detected by USBPD block. The UNPLUG, PLUG and IRQ events
 * are used in the case of a DisplayPort Sink implementation, and the
 * COMMAND_DONE event is used in the case of a DP Source implementation.
 */
typedef enum
{
    CY_USBPD_HPD_EVENT_NONE = 0,         /**< No event. */
    CY_USBPD_HPD_EVENT_UNPLUG,           /**< DP Unplug event. */
    CY_USBPD_HPD_EVENT_PLUG,             /**< DP Plug event. */
    CY_USBPD_HPD_EVENT_IRQ,              /**< DP IRQ event. */
    CY_USBPD_HPD_COMMAND_DONE,           /**< Requested HPD command is complete. */
    CY_USBPD_HPD_INPUT_CHANGE            /**< HPD IO raw status change. */
} cy_en_usbpd_hpd_events_t;

/** ADC block IDs. Refer to the device datasheet and TRM for more details. */
typedef enum 
{
    CY_USBPD_ADC_ID_0,                        /**< ADC-0 in the PD block. Supported by all devices. */
    CY_USBPD_ADC_ID_1,                        /**< ADC-1 in the PD block. */
    CY_USBPD_ADC_ID_OVUV,                     /**< Dedicated ADC for Over-Voltage/Under-Voltage detection. Only
                                                   available on PMG1S2. */
    CY_USBPD_ADC_NUM_ADC                      /**< Maximum number of ADCs in the PD block. */
} cy_en_usbpd_adc_id_t;

/** Types of PD ADC input sources. Refer to the device datasheet and TRM for
 * more details.
 */
typedef enum 
{
    CY_USBPD_ADC_INPUT_AMUX_A,                /**< AMUX_A bus. */
    CY_USBPD_ADC_INPUT_AMUX_B,                /**< AMUX_B bus. */
    CY_USBPD_ADC_INPUT_BANDGAP,               /**< BANDGAP input. */
    CY_USBPD_ADC_INPUT_BJT,                   /**< BJT. */
    CY_USBPD_ADC_NUM_INPUT                    /**< Number of ADC inputs available. */
} cy_en_usbpd_adc_input_t;

/** PD comparator interrupt configuration enumeration.
 * Note: These are the settings for INTR_1_CFG ADC output.
 */
typedef enum
{
    CY_USBPD_ADC_INT_DISABLED,                /**< Comparator interrupt disabled. */
    CY_USBPD_ADC_INT_FALLING,                 /**< Comparator interrupt on falling edge. */
    CY_USBPD_ADC_INT_RISING,                  /**< Comparator interrupt on rising edge. */
    CY_USBPD_ADC_INT_BOTH                     /**< Comparator interrupt on either edge. */
} cy_en_usbpd_adc_int_t;

/** ADC block reference voltage selection. */
typedef enum PD_ADC_VREF_T
{
    CY_USBPD_ADC_VREF_PROG = 0,               /**< Programmable reference voltage from the RefGen block. */
    CY_USBPD_ADC_VREF_VDDD,                   /**< VDDD supply used as ADC reference voltage. */
    CY_USBPD_ADC_VREF_MAX                     /**< MAX ADC reference voltage. Keep at the last of the enum. */
} cy_en_usbpd_adc_vref_t;

/** Timer Callback type selection */
typedef enum
{
    CY_USBPD_PD_OCP_DEBOUNCE_TIMER,
    /**< 000: Timer used for FW debounce of VBus OCP. */

    CY_USBPD_PD_VCONN_OCP_DEBOUNCE_TIMER,
    /**< 001: Timer used for FW debounce of VConn OCP. */

    CY_USBPD_APP_BC_GENERIC_TIMER1,
    /**< 002: Generic timer #1 used by the BC state machine. */

    CY_USBPD_APP_BC_GENERIC_TIMER2,
    /**< 003: Generic timer #2 used by the BC state machine. */

    CY_USBPD_VBUS_DISCHARGE_SCHEDULE_TIMER,
    /**< 004: Timer for VBUS SLow Discharge */

    CY_USBPD_APP_HAL_VREG_TIMER,
    /**< 005: Timer that can be used for Vreg fault handling. */

    CY_USBPD_APP_HAL_GENERIC_TIMER,
    /**< 006: Timer that can be used for generic HAL functions. */

    CY_USBPD_APP_REGULATOR_STARTUP_MONITOR_TIMER,             
    /**< 007: Timer ID reserved for regulator startup monitoring. */

    CY_USBPD_PDS_ACF_SMOOTH_RAMP_TIMER,
    /**< 008: Timer ID reserved for ACF smooth start during power on , and voltage transition */

    CY_USBPD_PDS_LTRAN_TIMER,
    /**< 009: Timer ID reserved for LTRAN load L2H handling */

    CY_USBPD_PDS_PASC_DEEPSLEEP_TIMER,
    /**< 00A: Timer ID reserved for Deepsleep timer */
    CY_USBPD_PDS_CC_DBN_SAFE_VALLEY_TIMER,
    /**< 00B: Timer ID reserved for CC safe valley debouncing */

} cy_en_usbpd_timer_id_t;

/** \} group_usbpd_common_enums */

/**
* \addtogroup group_usbpd_common_enums
* \{
*/

/** List of dedicated comparators supported by the PD block on various devices.
 * The actual comparators supported vary across device families. See comments
 * associated with each comparator ID for list of devices that support this
 * comparator.
 */
typedef enum
{
    CY_USBPD_VBUS_LSCSA_OCP_CONFIG,                           /**< OCP comparator gain control. Only available on PMG1S0.*/
    CY_USBPD_VBUS_LSCSA_EA_CONFIG,                            /**< EA comparator gain control. Only available on PMG1S0. */
    CY_USBPD_VBUS_LSCSA_PFC_OFF_CONFIG,                       /**< PFC OFF comparator gain control. Only available on PMG1S0. */
    CY_USBPD_VBUS_LSCSA_PFC_ON_CONFIG,                        /**< PFC ON comparator gain control. Only available on PMG1S0. */
    CY_USBPD_VBUS_LSCSA_SR_OFF_CONFIG,                        /**< SR OFF comparator gain control. Only available on PMG1S0. */
    CY_USBPD_VBUS_LSCSA_SR_ON_CONFIG,                         /**< SR ON comparator gain control. Only available on PMG1S0. */
    CY_USBPD_VBUS_LSCSA_MAX_CONFIG_VALUE                      /**< End of comparator list. */
} cy_en_usbpd_vbus_lscsa_app_config_t;

/** List of dedicated comparators supported by the PD block on various devices.
 * The actual comparators supported vary across device families. See comments
 * associated with each comparator ID for list of devices that support this
 * comparator.
 */
typedef enum
{
    CY_USBPD_VBUS_COMP_ID_UV                    = 0,    /**< UV comparator. */
    CY_USBPD_VBUS_COMP_ID_OV                    = 1,    /**< OV comparator. */

#if defined(CY_DEVICE_CCG3PA)
    CY_USBPD_VBUS_COMP_ID_VBUS_C_MON            = 2,    /**< VBUS_C_MON comparator. Only available on PMG1S0. */
    CY_USBPD_VBUS_COMP_ID_VBUS_DISCHARGE        = 3,    /**< Discharge comparator. Only available on PMG1S0. */
    CY_USBPD_VBUS_COMP_ID_LSCSA_SCP             = 4,    /**< SCP comparator. Only available on PMG1S0. */
    CY_USBPD_VBUS_COMP_ID_LSCSA_OCP             = 5,    /**< OCP comparator. Only available on PMG1S0. */
#elif defined (CY_DEVICE_PMG1S3)
    CY_USBPD_VBUS_COMP_ID_VSYS_DET              = 2,    /**< VSYS detection comparator*/
    CY_USBPD_VBUS_COMP_ID_P0_SBU1               = 3,    /**< Port-0 SBU1 Comparator. Only available on PMG1S3. */
    CY_USBPD_VBUS_COMP_ID_P0_SBU2               = 4,    /**< Port-0 SBU2 Comparator. Only available on PMG1S3. */
#elif defined (CY_DEVICE_CCG6DF_CFP)
    CY_USBPD_VBUS_COMP_ID_VSYS_DET              = 2,    /**< VSYS detection comparator*/
#elif (defined (CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    CY_USBPD_VBUS_COMP_ID_VSYS_DET              = 2,    /**< VSYS detection comparator*/
    CY_USBPD_VBUS_COMP_ID_VBUS_DISCHARGE        = 3,    /**< Discharge comparator. */
    CY_USBPD_VBUS_COMP_ID_LSCSA_SCP             = 4,    /**< SCP comparator. */
    CY_USBPD_VBUS_COMP_ID_DP_DETACH             = 4,    /**< D+ voltage comparator. */
    CY_USBPD_VBUS_COMP_ID_DM_DETACH             = 5,    /**< D- voltage comparator. */
    CY_USBPD_VBUS_COMP_ID_LSCSA_PFC             = 2,    /**< CBL_1, PFC comparator. */
    CY_USBPD_VBUS_COMP_ID_LSCSA_SR              = 4,    /**< CBL_0, SR comparator. */
    CY_USBPD_VBUS_COMP_ID_VSRC_NEW_M            = 5,    /**< VSRC_NEW comparator. */
    CY_USBPD_VBUS_COMP_ID_VSRC_NEW_P            = 6,    /**< VSRC_NEW comparator. */
#else
    CY_USBPD_VBUS_COMP_ID_VBUS_MON              = 2,    /**< VBUS_MON comparator. Only available on PMG1S1. */
    CY_USBPD_VBUS_COMP_ID_VSYS_DET              = 3,    /**< VSYS detection. Only available on PMG1S1. */
    CY_USBPD_VBUS_COMP_ID_DP_DETACH             = 4,    /**< D+ voltage comparator. Only available on PMG1S1. */
    CY_USBPD_VBUS_COMP_ID_DM_DETACH             = 5,    /**< D- voltage comparator. Only available on PMG1S1. */
#endif /* CY_DEVICE_CCG3PA */
#if defined(CY_DEVICE_CCG3PA)
    CY_USBPD_VBUS_COMP_ID_LSCSA_PFC             = 6,    /**< PFC comparator. Only available on PMG1S0. */
    CY_USBPD_VBUS_COMP_ID_VSRC_NEW_P            = 7,    /**< VSRC_NEW comparator. Only available on PMG1S0. */
    CY_USBPD_VBUS_COMP_ID_VSRC_NEW_M            = 8,    /**< VSRC_NEW comparator. Only available on PMG1S0. */
#endif /* CY_DEVICE_CCG3PA */
    COMP_ID_MAX                                 = 9     /**< End of comparator list. */

} cy_en_usbpd_comp_id_t;

/** The outputs of the comparators listed in comp_id_t and comp_tr_id_t can be passed through a
 * filter for debouncing. As with the comparators, the filters supported vary across device families.
 * This enumeration lists various filters supported and the comments indicate the devices that support
 * them.
 */
typedef enum
{
    CY_USBPD_VBUS_FILTER_ID_UV        = 0,              /**< UV comparator filter. */
    CY_USBPD_VBUS_FILTER_ID_OV        = 1,              /**< OV comparator filter. */

#if (defined(CY_DEVICE_CCG3PA))
    CY_USBPD_VBUS_FILTER_ID_DISCH_EN  = 2,              /**< Discharge enable filter for PMG1S0. */
    CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP = 3,              /**< SCP filter for PMG1S0. */
    CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP = 4,              /**< OCP filter for PMG1S0. */
    CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC = 5,              /**< PFC filter for PMG1S0. Can run based on HF or LF clock. */
    CY_USBPD_VBUS_FILTER_ID_LSCSA_SR  = 6,              /**< SR filter for PMG1S0. Can run based on HF or LF clock. */
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    CY_USBPD_VBUS_FILTER_ID_DISCH_EN  = 2,              /**< Discharge enable filter for PMG1S0. */
    CY_USBPD_VBUS_FILTER_ID_LSCSA_SR  = 3,              /**< CBL_0, SR filter for CCG7D. Can run based on HF or LF clock. */
    CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC = 4,              /**< CBL_1, PFC filter for CCG7D. Can run based on HF or LF clock. */
    CY_USBPD_VBUS_FILTER_ID_VSRC_NEW_P = 5,             /**< VSRC_NEW_P filter for CCG7D. Can run based on LF clock. */
    CY_USBPD_VBUS_FILTER_ID_VSRC_NEW_M = 6,             /**< VSRC_NEW_M filter for CCG7D. Can run based on LF clock. */
    CY_USBPD_VBUS_FILTER_ID_CSA_SCP = 10,               /**< Virtual number for SCP as it is to be configured differently. */
    CY_USBPD_VBUS_FILTER_ID_CSA_OCP = 11,               /**< Virtual number for OCP as it is to be configured differently. */
    CY_USBPD_VBUS_FILTER_ID_PDS_SCP = 12,               /**< Virtual number for VBAT_GND SCP as it is to be configured differently. */
    CY_USBPD_VBUS_FILTER_ID_VIN_UVP = 13,               /**< Virtual number for VIN UVP as it is to be configured differently. */
    CY_USBPD_VBUS_FILTER_ID_VIN_OVP = 14,               /**< Virtual number for VIN OVP as it is to be configured differently. */
    CY_USBPD_VBUS_FILTER_ID_ILIM_DET = 15,              /**< Virtual number for ILIM DET as it is to be configured differently. */
    CY_USBPD_VBUS_FILTER_ID_VREG_INRUSH_DET = 16,       /**< Virtual number for VREG INRUSH DET as it is to be configured differently. */
    CY_USBPD_VBUS_FILTER_ID_BROWN_OUT_DET = 17,         /**< Virtual number for VDDD brown out as it is to be configured differently. */
#else
    CY_USBPD_VBUS_FILTER_ID_HSCSA_SCP = 2,              /**< SCP filter for PMG1S1. */
    CY_USBPD_VBUS_FILTER_ID_HSCSA_OCP = 3,              /**< OCP filter for PMG1S1. */
    CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP = 4,              /**< RCP filter for PMG1S1. */
#endif /* defined(CY_DEVICE_CCG3PA) */

    CY_USBPD_VBUS_FILTER_ID_MAX                         /**< Number of supported filters. */
} cy_en_usbpd_vbus_filter_id_t;

/** List of edge triggered interrupt based on the filter output. */
typedef enum
{
    CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_DIS,           /**< Interrupt disabled. */
    CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_EN,            /**< Negative edge detection interrupt. */
    CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS,            /**< Positive edge detection interrupt. */
    CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_EN,             /**< Both edge detection interrupt. */
    CY_USBPD_VBUS_FILTER_CFG_MAX                        /**< Invalid interrupt configuration. */
} cy_usbpd_vbus_filter_edge_detect_cfg_t;

/** PMG1 OVP modes enumeration. */
typedef enum
{
    CY_USBPD_VBUS_OVP_MODE_ADC,                  /**< OVP detection using PMG1 internal ADC. */
    CY_USBPD_VBUS_OVP_MODE_UVOV,                 /**< OVP detection using the UVOV block on PMG1. FET control
                                                      is done by firmware. */
    CY_USBPD_VBUS_OVP_MODE_UVOV_AUTOCTRL         /**< OVP detection and FET control using the OVOV block on PMG1. */
} cy_en_usbpd_vbus_ovp_mode_t;

/** PMG1 UVP modes enumeration. */
typedef enum
{
    VBUS_UVP_MODE_ADC,                          /**< UVP detection using PMG1 internal ADC. */
    VBUS_UVP_MODE_INT_COMP,                     /**< UVP detection using the UVOV block on PMG1. FET control is
                                                     done by firmware. */
    VBUS_UVP_MODE_INT_COMP_AUTOCTRL             /**< UVP detection and FET control using the UVOV block on PMG1. */
} cy_en_usbpd_vbus_uvp_mode_t;

/**
 * @typedef cy_en_usbpd_supply_t
 * @brief List of power supplies input to and monitored by the PMG1 device.
 * This does not include the VBus supply which is monitored by all PMG1 devices as required by
 * the Type-C and USB-PD specifications.
 */
typedef enum
{
    CY_USBPD_SUPPLY_VSYS = 0x00,                /**< Vsys supply input which powers the device. */
    CY_USBPD_SUPPLY_V5V  = 0x01                 /**< V5V input used to derive the VConn supply from.
                                                     Not supported on PMG1S0. */
} cy_en_usbpd_supply_t;

/** PD PHY state events */
typedef enum
{
    CY_USBPD_PHY_EVT_TX_MSG_COLLISION,        /**< Bus busy at message transmission. */
    CY_USBPD_PHY_EVT_TX_MSG_PHY_IDLE,         /**< Bus idle, ready for message transmission. */
    CY_USBPD_PHY_EVT_TX_MSG_FAILED,           /**< Message transmission was not successful. */
    CY_USBPD_PHY_EVT_TX_MSG_SUCCESS,          /**< Message transmission was successful. */
    CY_USBPD_PHY_EVT_TX_RST_COLLISION,        /**< Bus busy just before reset transmission. */
    CY_USBPD_PHY_EVT_TX_RST_SUCCESS,          /**< Reset transmission was successful. */
    CY_USBPD_PHY_EVT_RX_MSG,                  /**< Message received. */
    CY_USBPD_PHY_EVT_RX_MSG_CMPLT,            /**< Message received and GoodCRC sent aka collision type 3. */
    CY_USBPD_PHY_EVT_RX_RST,                  /**< Reset was received. */
    CY_USBPD_PHY_EVT_FRS_SIG_RCVD,            /**< FRS signal was received. */
    CY_USBPD_PHY_EVT_FRS_SIG_SENT,            /**< FRS signal was transmitted. */
    CY_USBPD_PHY_EVT_CRC_ERROR                /**< Message received with CRC error. */
} cy_en_usbpd_phy_events_t;

/** USBPD Driver Events */
typedef enum {
    CY_USBPD_EVT_FRS_SIGNAL_RCVD = 0,         /**< FRS Signal Was received. */
    CY_USBPD_EVT_FRS_SIGNAL_SENT,             /**< FRS Signal was sent. */
    CY_USBPD_EVT_FRS_VBUS_LESS_5_DONE         /**< FRS VBUS is less than vSafe5V. */
} cy_en_usbpd_events_t;

/** USBPD status codes */
typedef enum cy_en_usbpd_status
{
    CY_USBPD_STAT_NO_RESPONSE = -2,          /**< Special status code indicating
                                             no response. */
    CY_USBPD_STAT_SUCCESS = 0,               /**< Success status. */
    CY_USBPD_STAT_FLASH_DATA_AVAILABLE,      /**< Special status code indicating flash data
                                             availability. */
    CY_USBPD_STAT_BAD_PARAM,                 /**< Bad input parameter. */
    CY_USBPD_STAT_INVALID_COMMAND = 3,       /**< Operation failed due to invalid command. */
    CY_USBPD_STAT_FLASH_UPDATE_FAILED = 5,   /**< Flash write operation failed. */
    CY_USBPD_STAT_INVALID_FW,                /**< Special status code indicating invalid firmware */
    CY_USBPD_STAT_INVALID_ARGUMENT,          /**< Operation failed due to invalid arguments. */
    CY_USBPD_STAT_NOT_SUPPORTED,             /**< Feature not supported. */
    CY_USBPD_STAT_INVALID_SIGNATURE,         /**< Invalid signature parameter identified. */
    CY_USBPD_STAT_TRANS_FAILURE,             /**< Transaction failure status. */
    CY_USBPD_STAT_CMD_FAILURE,               /**< Command failure status */
    CY_USBPD_STAT_FAILURE,                   /**< Generic failure status. */
    CY_USBPD_STAT_READ_DATA,                 /**< Special status code indicating read data
                                             availability. */
    CY_USBPD_STAT_NOT_READY,                 /**< Operation failed due to device/stack not ready. */
    CY_USBPD_STAT_BUSY,                      /**< Operation failed due to device/stack busy status. */
    CY_USBPD_STAT_TIMEOUT,                   /**< Operation timed out. */
    CY_USBPD_STAT_INVALID_PORT               /**< Invalid port number. */
} cy_en_usbpd_status_t;

/** \} group_usbpd_common_enums */

/** \} group_usbpd_common */

/**
* \addtogroup group_usbpd_legacy_enums
* \{
*/

/** List of charger detect block events sent by the HAL to the
 * state machine.
 */
typedef enum
{
    CY_USBPD_BC_PHY_EVT_COMP1_TRIG = 0,          /**< Comp1 triggered */
    CY_USBPD_BC_PHY_EVT_COMP2_TRIG               /**< Comp2 triggered */
} cy_en_usbpd_bch_phy_evt_t;

/** Charger block source (DP/DM) termination options. */
typedef enum
{
    CHGB_SRC_TERM_APPLE_1A = 0,         /**< Apple 1A termination */
    CHGB_SRC_TERM_APPLE_2_1A,           /**< Apple 2.1A termination */
    CHGB_SRC_TERM_APPLE_2_4A,           /**< Apple 2.4A termination */
    CHGB_SRC_TERM_APPLE_3A,             /**< Apple 3.0A termination */ 
    CHGB_SRC_TERM_QC,                   /**< Quick Charge termination */
    CHGB_SRC_TERM_AFC,                  /**< AFC termination */
    CHGB_SRC_TERM_DCP,                  /**< DCP termination */
    CHGB_SRC_TERM_CDP,                  /**< CDP termination */
    CHGB_SRC_TERM_SDP                   /**< SDP termination */
} cy_en_usbpd_bch_src_term_t;

/** Charger block sink termination options. */
typedef enum
{
    CHGB_SINK_TERM_SPD = 0,             /**< Standard port detect */
    CHGB_SINK_TERM_PCD,                 /**< Primary charger detect. */
    CHGB_SINK_TERM_SCD,                 /**< Secondary charger detect. */
    CHGB_SINK_TERM_AFC,                 /**< AFC detect */
    CHGB_SINK_TERM_APPLE,               /**< Apple detect */
    CHGB_SINK_TERM_QC_5V,               /**< QC 5V detect */
    CHGB_SINK_TERM_QC_9V,               /**< QC 9V detect */
    CHGB_SINK_TERM_QC_12V,              /**< QC 12V detect */
    CHGB_SINK_TERM_QC_20V              /**< QC 20V detect */
} cy_en_usbpd_bch_snk_term_t;


/**  Signals that can be connected to the positive input of the charger detect 
 * block comparators.
 */
typedef enum
{
    CHGB_COMP_P_DM = 0,                 /**< DM input */
    CHGB_COMP_P_VREF,                   /**< VREF input. Reference voltage level selected separately. */
    CHGB_COMP_P_DP,                     /**< DP input */
    CHGB_COMP_P_GND                     /**< GND input */
}cy_en_usbpd_bch_comp_pinput_t;

/** Signals that can be connected to the negative input of the charger detect
 * block comparators.
 */
typedef enum
{
    CHGB_COMP_N_DM = 0,                 /**< DM input */
    CHGB_COMP_N_VREF,                   /**< VREF input. Reference voltage level selected separately. */
    CHGB_COMP_N_DP,                     /**< DP input */
    CHGB_COMP_N_GND                     /**< GND input */
} cy_en_usbpd_bch_comp_ninput_t;

/** List of reference voltage levels available from the charger detect block.
 */
typedef enum
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    CHGB_VREF_0_325V = 0,               /**< 0.325 V */
    CHGB_VREF_0_425V = 0,               /**< 0.425 V. Use of 0.325 with offset of 100 mV */
    CHGB_VREF_0_7V,                     /**< 0.7 V */
    CHGB_VREF_0_85V,                    /**< 0.85 V */
    CHGB_VREF_1_4V,                     /**< 1.4 V */
    CHGB_VREF_1_7V,                     /**< 1.7 V */
    CHGB_VREF_2V,                       /**< 2.0 V */
    CHGB_VREF_2_2V,                     /**< 2.2 V */
    CHGB_VREF_2_9V                      /**< 2.9 V */
#elif (defined(CY_DEVICE_CCG3))
    CHGB_VREF_0_325V = 0,               /**< 0.325 V */
    CHGB_VREF_0_6V,                     /**< 0.6 V */
    CHGB_VREF_0_85V,                    /**< 0.85 V */
    CHGB_VREF_1_4V,                     /**< 1.4 V */
    CHGB_VREF_GND,                      /**< GND */
    CHGB_VREF_2V,                       /**< 2.0 V */
    CHGB_VREF_2_2V,                     /**< 2.2 V */
    CHGB_VREF_2_9V                      /**< 2.9 V */
#else
    CHGB_VREF_INVALID = 0               /**< Not supported. */
#endif /* CY_DEVICE */
} cy_en_usbpd_bch_vref_t;

/** Interrupt generation options for the charger detect block comparators.
 */
typedef enum
{
    CHGB_COMP_NO_INTR = 0,              /**< Interrupt disabled */
    CHGB_COMP_EDGE_FALLING,             /**< Interrupt on falling edge. */
    CHGB_COMP_EDGE_RISING,              /**< Interrupt on rising edge. */
    CHGB_COMP_EDGE_BOTH                 /**< Interrupt on either  edge. */
} cy_en_usbpd_bch_comp_edge_t;

/**
 * VBAT_GND Short circuit detection levels.
 */
typedef enum
{
    PD_VBAT_GND_SCP_6A = 0,               /**< 6A is current limit */
    PD_VBAT_GND_SCP_10A                   /**< 10A is current limit */
} cy_en_usbpd_vbat_gnd_scp_level_t;

/** List of ADFT inputs from SBU. */
typedef enum
{
#if (defined(CY_DEVICE_PMG1S3))
    CY_USBPD_SBU_ADFT_AUX1_SBU1 = 0,               /**< Connect SBU1 to ADFT0 and AUXP to ADFT1 */
    CY_USBPD_SBU_ADFT_AUX2_SBU2,                   /**< Connect SBU2 to ADFT0 and AUXN to ADFT1 */
    CY_USBPD_SBU_ADFT_AUX2_SBU1,                   /**< Connect SBU1 to ADFT0 and AUXN to ADFT1 */
    CY_USBPD_SBU_ADFT_AUX1_SBU2                    /**< Connect SBU2 to ADFT0 and AUXP to ADFT1 */
#elif (defined(CY_DEVICE_CCG3))
    CY_USBPD_SBU_ADFT_HIGHZ = 0,                   /**< ADFT0/1 is High-Z */
    CY_USBPD_SBU_ADFT_SBU1,                        /**< Connect SBU1 to ADFT0/1 */
    CY_USBPD_SBU_ADFT_SBU2,                        /**< Connect SBU2 to ADFT0/1 */
    CY_USBPD_SBU_ADFT_AUX1,                        /**< Connect AUXP to ADFT0/1 */
    CY_USBPD_SBU_ADFT_AUX2                         /**< Connect AUXN to ADFT0/1 */
#elif (defined(CY_DEVICE_CCG6))
    CY_USBPD_SBU_ADFT_HIGHZ_HIGHZ = 0,             /**< ADFT0 and ADFT1 are High-Z */
    CY_USBPD_SBU_ADFT_GND_GND,                     /**< Connect ADFT0 and ADFT1 to GND */
    CY_USBPD_SBU_ADFT_GND_SBU1_INT,                /**< Connect sbu1_int to ADFT0 and ADFT1 to GND */
    CY_USBPD_SBU_ADFT_ISNK_OVP_SBU2_INT,           /**< Connect sbu2_int to ADFT0 and isnk_ovp to ADFT1 */
    CY_USBPD_SBU_ADFT_HIGHZ_SBU2,                  /**< Connect sbu2 to ADFT0, ADFT1 is High-Z */
    CY_USBPD_SBU_ADFT_GND_OVP_DETECT_SBU1 = 6,     /**< Connect ovp_detect_sbu1 to ADFT0 and ADFT1 to GND */
    CY_USBPD_SBU_ADFT_GND_OVP_DETECT_SBU2,         /**< Connect ovp_detect_sbu2 to ADFT0 and ADFT1 to GND */
    CY_USBPD_SBU_ADFT_SBU1_ISNK1_LSRX,             /**< Connect lstx to ADFT0 and sbu1_isnk1 to ADFT1 */
    CY_USBPD_SBU_ADFT_HIGHZ_SBU1_ISNK2,            /**< Connect sbu1_isnk2 to ADFT0, ADFT1 is High-Z */
    CY_USBPD_SBU_ADFT_SBU2_ISNK2_SBU2_ISNK1,       /**< Connect sbu2_isnk1 to ADFT0 and sbu2_isnk2 to ADFT1 */
    CY_USBPD_SBU_ADFT_AUX2_GND = 12,               /**< Connect ADFT0 to GND and AUXN to ADFT1 */
    CY_USBPD_SBU_ADFT_LSTX_AUX1,                   /**< Connect lstx to ADFT0 and AUXP to ADFT1 */
    CY_USBPD_SBU_ADFT_GND_SBU1                     /**< Connect sbu1 to ADFT0 and ADFT1 to GND */
#elif defined(CY_DEVICE_CCG6DF_CFP)
    CY_USBPD_SBU_ADFT_SBU1_INT = 0,                /**< Connect sbu1_int to ADFT0/1 */
    CY_USBPD_SBU_ADFT_SBU2_INT,                    /**< Connect sbu2_int to ADFT0/1 */
    CY_USBPD_SBU_ADFT_SBU1,                        /**< Connect sbu1 (clipped) to ADFT0/1 */
    CY_USBPD_SBU_ADFT_SBU2                         /**< Connect sbu2 (clipped) to ADFT0/1 */
#else
    CY_USBPD_SBU_ADFT_INVALID = 0                  /**< Not supported */
#endif
} cy_en_usbpd_sbu_adft_input_t;

/** \} group_usbpd_legacy_enums */

/**
* \addtogroup group_usbpd_common
* \{
* */

/*******************************************************************************
*                              Type Definitions
*******************************************************************************/

/**
* \addtogroup group_usbpd_common_data_structures
* \{
*/

/**
 * Callback function used to provide notification about input supply changes.
 *
 * @param context Pointer to the context structure.
 * @param supply_id ID of the supply on which change is detected.
 * @param present Whether the identified supply is now present (true) or absent (false).
 */
typedef void (*cy_usbpd_supply_change_cbk_t)(void *context, cy_en_usbpd_supply_t supply_id, bool present);

/**
 * Notifies the PD stack about the occurrences of
 * \ref cy_en_usbpd_phy_events_t events.
 */
typedef void(*cy_cb_usbpd_phy_handle_events_t)(void *context, cy_en_usbpd_phy_events_t event);

/** Provides notification on VBUS load change */
typedef void (*cy_cb_usbpd_vbus_load_chg_t)(void *context);

/** VBus OVP/OCP/SCP/RCP protection callback function. */
typedef bool (*cy_cb_vbus_fault_t)(void *context, bool compOut);

/** ADC Events callback function. */
typedef void (*cy_cb_adc_events_t)(void *context, bool compOut);

/** SBU level detected callback function. */
typedef void (*cy_cb_sbu_level_detect_t)(void *context, bool sbu1Detect, bool sbu2Detect);

/** HPD event callback function. 
 * This function is used by the HAL layer to notify the DisplayPort
 * alternate mode layer about HPD related events that are detected.
 */
typedef void (*cy_cb_usbpd_hpd_events_t)(void *context, 
                                         cy_en_usbpd_hpd_events_t event);

/** Charger Detect PHY callback prototype. This function will be used to notify
 * the stack about PHY events.
 *
 * \param context
 * USBPD PDL Context pointer.
 *
 * \param event 
 * Type of BC PHY event.
 */
typedef void(*cy_cb_bc_phy_events_t)(void *context, uint32_t event);


/** USBPD Driver events callback.
 *
 * \param context
 * USBPD PDL Context pointer.
 *
 * \param event 
 * \ref cy_en_usbpd_events_t
 *
 * \param evtParam
 * Data associated with the event
 *
 * \return uint8_t
 * Returns the status of the event handling in the callback.
 *
 */
typedef uint8_t (*cy_usbpd_evt_cbk_t) (
        void *context,
        cy_en_usbpd_events_t event,
        void *evtParam);

/** Type C Driver events callback.
 *
 * \param context
 * Caller Context pointer.
 *
 * \param event 
 * \ref cy_en_pd_typec_events_t
 *
 * \return
 * None
 *
 */
typedef void (*cy_usbpd_typec_evt_cbk_t) (
        void *context,
        cy_en_pd_typec_events_t event);

/**
 * @brief Vbus current change callback prototype
 * This is the function prototype for the Vbus current change callback.
 * Callback can be registered with the cable compensation through
 * 'cable_comp_enable' function and the callback handler will be called on every
 * comparator interrupt for the changing Vbus current level.
 * @param port Port index.
 * @param vbus_cur Latest Vbus current in 10mA units
 * @return None
 */
typedef void (*cy_cable_comp_vbus_cur_cbk)(void *context, uint16_t vbus_cur);

/**
 * @typedef cy_pd_cmp_cbk_t
 * @brief Comparator interrupt callback function.
 *
 * @param port PD port on which the event occurred.
 * @param state State of the comparator.
 */
typedef void (*cy_pd_cmp_cbk_t)(void *context, bool state);

/**
 * @typedef cy_timer_cbk_t
 * @brief Timer callback function.
 *
 * This callback function is invoked on timer expiry and
 * should be treated as interrupt.
 */
typedef void (*cy_timer_cbk_t)(uint16_t id, void *callbackContext);

/**
 * @typedef cy_timer_start_t
 * @brief Timer Start callback function.
 *
 * This callback function is invoked for timer start from driver.
 */
typedef bool (*cy_timer_start_t)(struct cy_stc_usbpd_context_t_ *context, void *callbackContext, 
        uint16_t id, uint16_t period, cy_timer_cbk_t cbk);

/**
 * @typedef cy_timer_stop_t
 * @brief Timer Stop callback function.
 *
 * This callback function is invoked for timer stop from driver.
 */
typedef void (*cy_timer_stop_t)(struct cy_stc_usbpd_context_t_ *context, cy_en_usbpd_timer_id_t id);

/**
 * @typedef cy_timer_is_running_t
 * @brief Timer callback function.
 *
 * This callback function is invoked to check if software timer is running from driver.
 */
typedef bool (*cy_timer_is_running_t)(struct cy_stc_usbpd_context_t_ *context, cy_en_usbpd_timer_id_t id);

/**
 * @typedef cy_timer_get_multiplier_t
 * @brief Timer callback function.
 *
 * This callback function is invoked to get timer multiplier count.
 */
typedef uint16_t (*cy_timer_get_multiplier_t)(struct cy_stc_usbpd_context_t_ *context);

/**
 * @typedef cy_slow_discharge_t
 * @brief vbus_slow_discharge_cbk.
 *
 * This callback function is invoked to call vbus_slow_discharge_cbk from driver.
 */
typedef void (*cy_slow_discharge_t)(void *pdStackContext);

/**
 * VBUS current foldback callback function.
 *
 * \param pdStackContext
 * Caller context pointer.
 *
 * \param cf_state
 * Current foldback state.
 *
 * \return
 * None
 */
typedef void (*cy_vbus_cf_cbk_t)(void *pdStackContext, bool cf_state);

#if (((defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) && defined(CCG_CDP_EN)) && BATTERY_CHARGING_ENABLE)

/** Structure holding CDP state machine variables. */
typedef struct cdp_sm_vars
{
    bool     isActive;                 /**< Whether the state machine is active. */
    bool     vdmsrcOn;                 /**< Whether the VDM_SRC supply has been turned ON. */
    uint8_t  vdmsrcLvCnt;              /**< Number of times the VDM_SRC output has been detected as low. */
} cdp_sm_vars;

#endif /* (((defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) && CCG_CDP_EN) && BATTERY_CHARGING_ENABLE) */

/** Config structure for VBUS OVP parameters */
typedef struct
{
    /** Whether to enable/disable VBUS OVP Feature
     *  1 - Enable
     *  0 - Disable */
    uint8_t enable;

    /** Vbus OVP Mode Selection 
     *  0 - OVP using ADC comparator 
     *  1 - OVP using dedicated comparator, Firmware detects trips and turns
     *      off FETS 
     *  2 - OVP using dedicated comparator, Hardware detects trips and turns
     *      off FETS */
    uint8_t mode;

    /** Current threshold percentage (0-100) above the contract current to
     * trigger fault. */
    uint8_t threshold;

    /** Fault event debounce period in ms (0-255) */
    uint8_t debounce;

    /** Number of times to retry recovery from fault(0-255) */
    uint8_t retryCount;

} cy_stc_fault_vbus_ovp_cfg_t;

/** Config structure for VBUS UVP parameters */
typedef struct
{
    /** Whether to enable/disable VBUS UVP Feature
     *  1 - Enable
     *  0 - Disable */
    uint8_t enable;
    
    /** Vbus UVP Mode Selection 
     *  0 - UVP using ADC comparator 
     *  1 - UVP using dedicated comparator, Firmware detects trips and turns
     *      off FETS 
     *  2 - UVP using dedicated comparator, Hardware detects trips and turns
     *      off FETS */
    uint8_t mode;

    /** Current threshold percentage (0-100) above the contract current to
     * trigger fault. */
    uint8_t threshold;

    /** Fault event debounce period in ms (0-255) */
    uint8_t debounce;

    /** Number of times to retry recovery from fault(0-255) */
    uint8_t retryCount;

} cy_stc_fault_vbus_uvp_cfg_t;

/** Structure for legacy charging state machine */
typedef struct
{
    /** Whether the state machine is active. */
    bool     is_active;            
    
    /** Whether the VDM_SRC supply has been turned ON. */
    bool     vdmsrc_on;           
    
    /** Number of times the VDM_SRC output has been detected as low. */
    uint8_t  vdmsrc_lv_cnt;       

} cy_stc_usbpd_legacy_charging_state_t;

/** Config structure for VBUS OCP parameters */
typedef struct
{
    /** Whether to enable/disable VBUS OCP Feature
     *  1 - Enable
     *  0 - Disable */
    uint8_t enable;

    /** Vbus OCP Mode Selection 
     *  0 - OCP using external hardware
     *  1 - Internal OCP with neither software debounce nor automatic FET
     *      control
     *  2 - Internal OCP with automatic FET control by hardware when an OCP
     *      event is detected
     *  3 - Internal OCP with software debounce using delay in milliseconds
     *      specified by the user */
    uint8_t mode;

    /** Current threshold percentage (0-100) above the contract current to
     * trigger fault. */
    uint8_t threshold;

    /** Fault event debounce period in ms (0-255) */
    uint8_t debounce;

    /** Number of times to retry recovery from fault(0-255) */
    uint8_t retryCount;

    /** Sense Resistor impedance in milli-Ohm units */
    uint8_t senseRes;

    /** Current sense tuning resistor impedance in 100 Ohm units */
    uint8_t csRes;

} cy_stc_fault_vbus_ocp_cfg_t;

/** Config structure for VBAT OCP parameters */
typedef struct
{
    /** Vbat OCP Mode Selection
     *  0 - OCP using external hardware
     *  1 - Internal OCP with neither software debounce nor automatic FET
     *      control
     *  2 - Internal OCP with automatic FET control by hardware when an OCP
     *      event is detected
     *  3 - Internal OCP with software debounce using delay in milliseconds
     *      specified by the user */
    uint8_t mode;

    /** Current threshold percentage (0-100) above the contract current to
     * trigger fault. */
    uint8_t threshold;

    /** Fault event debounce period in ms (0-255) */
    uint8_t debounce;

} cy_stc_fault_vbat_ocp_cfg_t;

/** Config structure for VCONN OCP parameters */
typedef struct
{
    /** Whether to enable/disable VConn OCP Feature
     *  1 - Enable
     *  0 - Disable */
    uint8_t enable;

    /** Current threshold percentage (0-100) above the contract current to
     * trigger fault. */
    uint8_t threshold;

    /** Fault event debounce period in ms (0-255) */
    uint8_t debounce;

    /** Number of times to retry recovery from fault(0-255) */
    uint8_t retryCount;

} cy_stc_fault_vconn_ocp_cfg_t;

/** Config structure for VBUS SCP parameters */
typedef struct
{
    /** Whether to enable/disable VBUS SCP Feature
     *  1 - Enable
     *  0 - Disable */
    uint8_t enable;

    /** Sense Resistor impedance in milli-Ohm units */
    uint8_t senseRes;

    /** Current threshold percentage (0-100) above the contract current to
     * trigger fault. */
    uint8_t threshold;

    /** Fault event debounce period in us (0-255) */
    uint8_t debounce;

    /** Number of times to retry recovery from fault(0-255) */
    uint8_t retryCount;

    /** SCP mode. */
    uint8_t mode;

} cy_stc_fault_vbus_scp_cfg_t;

/** Config structure for VIN UVP / OVP parameters */
typedef struct
{
    /** VIN UVP protection mode. */
    uint8_t mode;
} cy_stc_fault_vin_uvp_ovp_cfg_t;

/** Config structure for VBUS RCP parameters */
typedef struct
{
    /** Whether to enable/disable VBUS RCP Feature
     *  1 - Enable
     *  0 - Disable */
    uint8_t enable;

    /** Number of times to retry recovery from fault(0-255) */
    uint8_t retryCount;

} cy_stc_fault_vbus_rcp_cfg_t;

/** Config structure for CC OVP parameters */
typedef struct
{
    /** Whether to enable/disable CC OVP Feature
     *  1 - Enable
     *  0 - Disable */
    uint8_t enable;

    /** Number of times to retry recovery from fault(0-255) */
    uint8_t retryCount;

} cy_stc_fault_cc_ovp_cfg_t;

/** Config structure for SBU OVP parameters */
typedef struct
{
    /** Whether to enable/disable SBU OVP Feature
     *  1 - Enable
     *  0 - Disable */
    uint8_t enable;

    /** Number of times to retry recovery from fault(0-255) */
    uint8_t retryCount;

} cy_stc_fault_sbu_ovp_cfg_t;

/**
 * @brief Struct to hold the port legacy charging parameters.
 */
#if CY_USE_CONFIG_TABLE
typedef struct
{
    uint8_t srcSel;            /**< Legacy charging source selection bit mask:
                                 *   Bit 0 --> BC 1.2 support
                                 *   Bit 1 --> Apple charger
                                 *   Bit 2 --> Quick charge
                                 *   Bit 3 --> AFC charger
                                 *   Bit 4 --> QC 4.0 (TypeC PD 3.0 only)
                                 *  Other bits reserved
                                 *  BC 1.2 bit is required to support QC (2.0/3.0) and AFC.
                                 *  For CCG5/CCG5C projects:
                                 *  Only Bit 0 is valid as the device supports only BC1.2 (DCP) in power states other than S0. In S0 state, device supports only BC1.2 CDP.

                                 *  For CCG6 projects:
                                 *  Only Bit 0 and Bit 1 are valid as the device supports only BC1.2 (DCP) or  Apple in power states other than S0. In S0 state, device supports only BC1.2 CDP.
                                 *  Note that both modes cannot be supported simultaneously due to device limitations. If both bits are set, Apple mode is given preference.

                                 *  For CCG3PA/CCG3PA2 projects :
                                 *  When Apple charger is enabled along with BC 1.2, the Apple charger brick ID should be 2.4A (2). Also, in case of CCG3PA, this require firmware update and hardware changes.

                                 *  Bit 4 is valid regardless of the legacy mode of operation.

                                 *  Legacy can operation in the following modes:
                                 *  1. Disabled. Bit 0-3 should be zero.
                                 *  2. BC 1.2: Bit 0 must be set.
                                 *  Bit 1-3 can be set or cleared based on requirement. But if Bit 1 is set, it requires external hardware support. Refer to CCGx Power SDK User Guide for more details.
                                 *  3. Apple: Bit 1 should be set and Bits 0, 2, 3 must be zero.
                                 */
    uint8_t snkSel;            /**< Legacy charging sink selection bit mask:
                                 *   Bit 0 --> BC 1.2
                                 *   Bit 1 --> Apple brick
                                 *   Bit 2 --> Quick charge
                                 *   Other bits reserved
                                 */
    uint8_t enable;            /**< Reserved for future use */
    uint8_t appleSrcId;       /**< Apple charger brick ID to be used as source:
                                 *   Bit 0 --> 1 A
                                 *   Bit 1 --> 2.1 A
                                 *   Bit 2 --> 2.4 A
                                 *   Bit 3 --> 3 A
                                 */
    uint8_t qcSrcType;        /**< Quick charge source type:
                                 *   Bit 0 --> QC 2.0 Class-A
                                 *   Bit 1 --> QC 2.0 Class-B
                                 *   Bit 2 --> QC 3.0 Class-A
                                 *   Bit 3 --> QC 3.0 Class-B
                                 */
    uint8_t reserved_1[2];    /**< Reserved for future use */
    uint8_t afcSrcCapCnt;     /**< Number of AFC source voltage-current capabilities supported. */
    uint8_t afcSrcCaps[16];   /**< AFC source voltage-current capabilities list. */
} cy_stc_legacy_charging_cfg_t;
#else
typedef struct
{
    uint8_t enable;           /**< Whether to enable/disable legacy charging Feature
                                 *  1 - Enable
                                 *  0 - Disable */
    uint8_t srcSel;           /**< Legacy charging source selection bit mask:
                                 *   Bit 0 --> BC 1.2 support
                                 *   Bit 1 --> Apple charger
                                 *   Bit 2 --> Quick charge
                                 *   Bit 3 --> AFC charger
                                 *   Other bits reserved
                                 */
    uint8_t snkSel;           /**< Legacy charging sink selection bit mask:
                                 *   Bit 0 --> BC 1.2
                                 *   Bit 1 --> Apple brick
                                 *   Other bits reserved
                                 */
    uint8_t appleSrcId;       /**< Apple charger brick ID to be used as source:
                                 *   Bit 0 --> 1 A
                                 *   Bit 1 --> 2.1 A
                                 *   Bit 2 --> 2.4 A
                                 */
    uint8_t qcSrcType;        /**< Quick charge source type:
                                 *   Bit 0 --> QC 2.0 Class-A
                                 *   Bit 1 --> QC 2.0 Class-B
                                 *   Bit 2 --> QC 3.0 Class-A
                                 *   Bit 3 --> QC 3.0 Class-B
                                 */
    uint8_t afcSrcCapCnt;     /**< Number of AFC source voltage-current capabilities supported. */
    uint8_t afcSrcCaps[16];   /**< AFC source voltage-current capabilities list. */
} cy_stc_legacy_charging_cfg_t;
#endif /* CY_USE_CONFIG_TABLE */

/** Config structure for Cable Compensation*/
typedef struct
{
    /** Whether to enable/disable cable compensation Feature
     *  1 - Enable
     *  0 - Disable */
    bool enable;

    /** Whether comparator interrupt received or not. */
    volatile bool start;

    /** The latest cable compensation Vbus current. */
    volatile uint16_t cableCompCur;

    /** The current cable compensation voltage drop. */
    uint16_t cableCompDrop;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint8_t vbusCblGain;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
} cy_stc_cable_comp_cfg_t;

/** Config structure for VBUS SLOW DISCHARGE*/
typedef struct
{
    /** Placeholder for VBUS discharge strength for DISCHG_SHV_CTRL[0]*/
    uint8_t vbus_discharge_ds0;

    /** Placeholder for VBUS discharge strength for DISCHG_SHV_CTRL[1]*/
    uint8_t vbus_discharge_ds1;

    /** Flag determines if VBUS discharge ON request is ongoing */
    uint8_t vbus_is_slow_dischargeOn;

    /** Flag determines if VBUS discharge OFF request is ongoing */
    uint8_t vbus_is_slow_dischargeOff;

} cy_stc_slow_discharge_cfg_t;

/** Structure for trim variables*/
typedef struct
{
/** \cond DOXYGEN_HIDE */
    uint32_t lszcd_trim;
    uint32_t hsrcp_trim;
/** \endcond */

    /** Variables are created to use dynamic CC/CF gain setting at 3A switchover. 
    For 3A application, using fixed gain of 80 across 1A to 3A.
    For 5A application, using fixed gain of 60 across 1A to 5A.  */
   
/** \cond DOXYGEN_HIDE */
    uint8_t cc_trim_1a;
    uint8_t cc_trim_2a;
    uint8_t cc_trim_3a;
    uint8_t cc_trim_3a_g2;
    uint8_t cc_trim_4a_g2;
    uint8_t cc_trim_5a_g2;
#if PMG1B1_USB_CHARGER
    uint8_t cc_trim_1a_100;
    uint8_t cc_trim_2a_100;
    uint8_t cc_trim_1a_110;
    uint8_t cc_trim_2a_110;
#endif /* PMG1B1_USB_CHARGER */
/** \endcond */

/** 20CSA current sense offset in 10uV with gain = 1. This offset shall be treated as 20CSA trim.
    This trim has to be subtracted while sampling 20CSA output.
   And added, while setting reference to 20CSA trigger. */
   
    uint16_t offset_20csa;
    
} cy_stc_trims_cfg_t;

/**
 * @brief Struct to hold the sensor throttling settings.
 */
typedef struct
{
    uint8_t sensor_ctrl;       /**< Bit 7: 0 -> Disabled, 1 -> Enabled; Bit 6-0: I2C address */
    uint8_t sensor_oc1;        /**< Maximum sensor temperature for the system to function in OC1 (100%) power rating. */
    uint8_t sensor_oc2;        /**< Maximum sensor temperature for the system to function in OC2 (50%) power rating.
                                *   To skip this power level, load with the 0x00.
                                *   To terminate at this level, load with 0xFF.
                                */
    uint8_t sensor_oc3;        /**< Maximum sensor temperature for the system to function in OC3 (15W) power rating.
                                *   To skip this power level, load with the 0x00.
                                *   To terminate at this level, load with 0xFF.
                                *   Beyond this threshold, the port shall be shutoff.
                                */

} sensor_data_t;

/**
 * @brief Struct to hold the power parameters settings.
 */
typedef struct
{
    uint8_t fb_type;                            /**< Type of power feedback:
                                                 *   Bit 0 --> No feedback
                                                 *   Bit 1 --> PWM
                                                 *   Bit 2 --> Direct feedback
                                                 *   Bit 3 --> Opto-isolator based feedback
                                                 */
    uint8_t reserved;                           /**< Reserved area for future expansion. */
    uint16_t vbus_min_volt;                     /**< VBus minimum voltage in mV */
    uint16_t vbus_max_volt;                     /**< VBus maximum voltage in mV */
    uint16_t vbus_dflt_volt;                    /**< Default VBus supply voltage when feedback control is tri-stated. */
    uint16_t cable_resistance;                  /**< Cable resistance in mOhm */
    uint16_t vbus_offset_volt;                  /**< VBus offset voltage in addition to contracted voltage in mV */
    uint8_t current_sense_res;                  /**< Available to adjust CSA accuracy on board. Unit of 0.1mOhm min_value = 10  max_value = 100*/
    uint8_t src_gate_drv_str;                   /**< Vbus source gate drive strength.
                                                 *   0 -> Slow
                                                 *   1 -> Normal
                                                 *   2 -> Fast*/
    uint16_t vbtr_up_step_width;                /**< Vbtr Upward transition step width in 1us units. For single slope
                                                 *   design, this shall be used for full voltage range. For dual slope
                                                 *   design this shall be used only for transitions above 5v. */
    uint16_t vbtr_down_step_width;              /**< Vbtr Downward transition step width in 1us units For single slope
                                                 *   design, this shall be used for full voltage range. For dual slope
                                                 *   design this shall be used only for transitions above 5v. */
    uint8_t prim_sec_turns_ratio;               /**< Primary to secondary turns ratio rounded to nearest decimal. min_value = 4 max_value = 10 */
    uint8_t sr_enable;                          /**< Enable/Disable the SR controller */
    uint8_t sr_rise_time;                       /**< SR gate driver rise time configuration.
                                                 *   0 -> Slow
                                                 *   1 -> Normal
                                                 *   2 -> Fast */
    uint8_t sr_fall_time;                       /**< SR gate driver fall time configuration
                                                 *   0 -> Slow
                                                 *   1 -> Normal
                                                 *   2 -> Fast */
    uint8_t sr_async_thresh;                    /**< Secondary width below which GDRV will be gated. Units in number of PASC Clock cycles. */
    uint8_t sr_supply_doubler;                  /**< Enable/Disable the doubler for gate drive function */
    uint8_t reserved_1;                         /**< Reserved for future use */
    uint8_t buck_boost_operating_mode;          /**< Indicates mode of Buck-Boost regulation. */
    uint8_t pwm_mode;                           /**< Indicates operational mode of power adapter secondary controller */
    uint8_t pwm_min_freq;                       /**< Minimum allowed switching frequency in QR/QR+FF mode in KHz */
    uint8_t pwm_max_freq;                       /**< Maximum allowed switching frequency in QR/QR+FF mode in KHz */
    uint8_t pwm_fix_freq;                       /**< PWM switching frequency in FF mode in KHz */
    uint8_t max_pwm_duty_cycle;                 /**< Maximum allowed PWM pulse duty cycle */
    uint8_t min_pwm_duty_cycle;                 /**< Minimum allowed PWM pulse duty cycle */
    uint8_t pwm_gate_pull_up_drv_strnth_LS1;    /**< adjust gate pull-up drive strength */
    uint8_t pwm_gate_pull_up_drv_strnth_LS2;    /**< adjust gate pull-up drive strength */
    uint8_t pwm_gate_pull_up_drv_strnth_HS1;    /**< adjust gate pull-up drive strength */
    uint8_t pwm_gate_pull_up_drv_strnth_HS2;    /**< adjust gate pull-up drive strength */
    uint8_t pwm_dithering_type;                 /**< enable / disable the dithering frequency configuration and pwm_dithering_type  */
    uint8_t pwm_dithering_freq_range;           /**< % of frequency dithering based on the set switching frequency */
    uint8_t power_inductor_value;               /**< Inductance L required for slope_comp_control calculation */
    uint8_t peak_current_sense_resistor;        /**< Ri required for slope_comp_control calculation */
    uint8_t phase_angle_control;                /**< phase angle between ports in degrees */
    uint8_t peak_current_limit;                 /**< Set the Current limit to shutdown the converter so that inductor shall not saturate */
    uint8_t max_pwm_duty_cycle_high_line;       /**< Maximum allowed PWM pulse duty cycle for high line condition */
    uint8_t reserved_2;                         /**< Reserved for future use */
    uint16_t vbtr_up_step_width_below_5v;       /**< Vbtr Upward transition step width in 1us units for dual slope
                                                 *   design when VBUS is below 5V */
    uint16_t vbtr_down_step_width_below_5V;     /**< Vbtr Downward transition step width in 1us units for dual slope
                                                 *   design when VBUS is below 5V */
    uint16_t pwm_max_freq_ex;                   /**< Maximum allowed switching frequency in QR/QR+FF mode in KHz, extended
                                                 *   for more than 254kHz operation. */
    uint8_t pwm_gate_pull_down_drv_strnth_LS1;  /**< adjust gate pull-down drive strength */
    uint8_t pwm_gate_pull_down_drv_strnth_LS2;  /**< adjust gate pull-down drive strength */
    uint8_t pwm_gate_pull_down_drv_strnth_HS1;  /**< adjust gate pull-down drive strength */
    uint8_t pwm_gate_pull_down_drv_strnth_HS2;  /**< adjust gate pull-down drive strength */
    uint8_t bbclk_freq;                         /**< Buck boost controller clock frequency in units of MHz */
    uint8_t pwm_fix_freq_dith;                  /**< Center PWM switching frequency when dithering is enabled */
    uint8_t pwm_dith_spread_cycles;             /**< Number of BBCLK cycles of spread required to achieve
                                                 * configured range of frequency spread */
    uint8_t reserved_3[1];                      /**< Reserved for future use */
    uint16_t bb_output_volt;                    /**< Default buck-boost controller output voltage in mV */
} cy_stc_buck_boost_cfg_t;

/**
 * @brief Struct to hold the automotive charger settings.
 */
typedef struct
{
    uint8_t reserved;                 /**< Reserved for ROM issue. */
    bool policy_manager_enable;      /**< Source policy manager.
                                      * Source policy manager Enable/Disable
                                      *  0 -> Disable
                                      * 1 ->Enable */
    uint8_t sys_power;                /**< VBUS total system power in Watts. Fractional input in 0.5 Watts increment is acceptable provided the difference between this value and port maximum power is in the range of 7.5 Watts - 9.5 Watts. */
    uint8_t port_power;               /**< VBUS per port maximum power in Watts */
    uint8_t configurable_power_OC2;   /**< Maximum Port's Budget OC2 Level either in % or Value  */
    uint8_t configurable_power_OC3;   /**< Maximum Port's Budget OC3 Level either in % or Value  */
    bool pps_enable;                  /**< PPS Enable/Disable
                                        * 0 -> Disable
                                        * 1 ->Enable */
    bool unconstrained_power_enable;   /**< Unconstrained Power Enable/Disable
                                        * 0 -> Disable
                                        *  1 ->Enable*/
    uint8_t vin_throttling_ctrl;  /**< Battery voltage throttling control */
    uint8_t vin_oc1;              /**< Minimum input voltage in 100mV units required for the system to supply OC1 (100%) power rating */
    uint8_t vin_oc2;              /**< Minimum input voltage in 100mV units required for the system to supply OC2 (50%) power rating.
                                   *   To skip this power level, load with the 0xFF.
                                   *   To terminate at this level, load with 0.
                                   */
    uint8_t vin_oc3;              /**< Minimum input voltage in 100mV units required for the system to supply OC3 (15W) power rating. To skip this power level, load with the 0xFF. To terminate at this level, load with 0.
                                   *   Beyond this threshold, the port shall be shutoff.
                                   */
    sensor_data_t sensor_data[4]; /**< Temperature throttling information for sensors */
    uint8_t vin_fault_max_safe_voltage; /**< VIN maximum safe voltage */
    uint8_t pdo_all_voltage_rail; /**< Enable/Disable all PDO voltage rail availability in SRC_CAP,
                                   * instead of spec recommended PDO source voltages for the
                                   * given port power (PDP).
                                   * PDO list customization option.
                                   */
    uint16_t max_current;         /**<  Maximum current that can be sourced in steps of 10 mA units.
                                   * All PDOs generated through Automotive policy/features are
                                   * capped with this maximum current limit.
                                   * PDO list customization option.
                                   */
    bool fractional_system_power; /**< Gets set if valid fractional total system power is selected.
                                      * 0->Selected Total System Power is an integer
                                      * 1->Selected Total System Power is a fraction. Actual selected system power is 0.5 Watts more than the integer value present in ""sys_pwr"" field.
                                      * This field is not visible in EZ-PD Config utility GUI and is updated internally by the tool as required.
                                      */
    uint8_t reserved_1[3];           /**< Reserved bytes */

} cy_stc_auto_cfg_settings_t;

/** Config structure for USBPD IP configuration */
typedef struct
{
    /** Pointer for VBUS OVP config structure */
    const cy_stc_fault_vbus_ovp_cfg_t *vbusOvpConfig;

    /** Pointer for VBUS UVP config structure */
    const cy_stc_fault_vbus_uvp_cfg_t *vbusUvpConfig;

    /** Pointer for VBUS OCP config structure */
    const cy_stc_fault_vbus_ocp_cfg_t *vbusOcpConfig;

    /** Pointer for VCONN OCP config structure */
    const cy_stc_fault_vconn_ocp_cfg_t *vconnOcpConfig;

    /** Pointer for VBUS SCP config structure */
    const cy_stc_fault_vbus_scp_cfg_t *vbusScpConfig;

    /** Pointer for VBUS RCP config structure */
    const cy_stc_fault_vbus_rcp_cfg_t *vbusRcpConfig;

    /** Pointer for CC OVP config structure */
    const cy_stc_fault_cc_ovp_cfg_t *ccOvpConfig;

    /** Pointer for SBU OVP config structure */
    const cy_stc_fault_sbu_ovp_cfg_t *sbuOvpConfig;

    /** Legacy Charging Configuration. */
    const cy_stc_legacy_charging_cfg_t *legacyChargingConfig;

    /** Buck-Boost Configuration. */
    cy_stc_buck_boost_cfg_t *buckBoostConfig;

    /** Auto SDK Configuration. */
    cy_stc_auto_cfg_settings_t *autoConfig;

    /** Input under voltage protection configuration */
    cy_stc_fault_vin_uvp_ovp_cfg_t vinUvpConfig;

    /** Input over voltage protection configuration */
    cy_stc_fault_vin_uvp_ovp_cfg_t vinOvpConfig;

    /** Pointer for VBAT OCP config structure */
    const cy_stc_fault_vbat_ocp_cfg_t *vbatOcpConfig;

} cy_stc_usbpd_config_t;

/** Context structure for USBPD-IP */
typedef struct cy_stc_usbpd_context_t_
{
    /** USBPD port Index. **/
    uint8_t port;
    
    /** USBPD register base address **/
    PPDSS_REGS_T base;
    
    /** USBPD TRIMS register base address **/
    void *trimsBase;
    
    /** PD phy callback. */
    cy_cb_usbpd_phy_handle_events_t pdPhyCbk;

    /** Supply Change callback. */
    cy_usbpd_supply_change_cbk_t supplyChangeCbk;

    /** The received PD packet. */
    cy_stc_pd_packet_extd_t rxPkt;

    /** The tx data pointer. */
    uint32_t* txDatPtr;

    /** ADC block Vref. */
    volatile bool adcRefVddd[CY_USBPD_ADC_NUM_ADC];
    
    /** ADC block Vref. */
    volatile uint16_t adcVdddMv[CY_USBPD_ADC_NUM_ADC];
    
    /** VBUS Monitor divider. */
    uint8_t vbusMonDiv;
    
    /** ADC input index. */
    cy_en_usbpd_adc_input_t vbusDetachAdcInp;
    
    /** ADC ID index. */
    cy_en_usbpd_adc_id_t vbusDetachAdcId;

    /** ADC callback. */
    cy_cb_adc_events_t adcCb[CY_USBPD_ADC_NUM_ADC];

    /** SBU level detect callback */
    cy_cb_sbu_level_detect_t sbuDetectCb;

    /** The tx data count. */
    uint8_t txDobjCount;

    /** The tx data pointer. */
    uint8_t volatile txObjSent;

    /** Holds current transmission is unchunked or not */
    uint8_t volatile txUnchunked;

    /** Holds retry count. */
    int8_t volatile retryCnt;

    /**
     * Flag to indicate a message has been transmitted and we're waiting for
     * GoodCRC.
     */
    uint8_t volatile txDone;

    /**
     * Flag to indicate currently received message is unchunked extended message
     */
    bool volatile rxUnchunked;

    /**
     * Length of currently being received extended unchunked messages in 32 bits units
     */
    uint8_t volatile rxUnchunkLen;

    /**
     * Count in 32 bits units of no of words read from rx memory for extended unchunked
     * message.
     */
    uint8_t volatile rxUnchunkCount;

    /**
     * Read memory location where the HAL should read the next portion of data from.
     */
    uint8_t volatile rxReadLocation;

    /** HPD transmit enable. */
    bool hpdTransmitEnable;

    /** HPD receive enable. */
    bool hpdReceiveEnable; 

    /** HPD event callback. */
    cy_cb_usbpd_hpd_events_t hpdCbk;

   /**
    * This flag keeps track of HPD Connection status. It is used in HPD CHANGE wakeup
    * interrupt.
    */
    bool hpdState;

    /** BC phy callback. */
    cy_cb_bc_phy_events_t bcPhyCbk;

    /** CDP State Variable */ 
    cy_stc_usbpd_legacy_charging_state_t cdp_state;

    /** QC3.0 net pulse count (+ve = D+ pulse, -ve = D- pulse).*/
    int volatile bcQcPulseCount;

    /** AFC TX buffer */
    uint8_t bcAfcTxBuf[16];

    /** AFC RX buffer */
    uint8_t bcAfcRxBuf[16];

    /** AFC RX buffer index */
    uint8_t bcAfcRxIdx;

    /** AFC TX buffer index */
    uint8_t bcAfcTxIdx;

    /** AFC TX buffer size */
    uint8_t bcAfcTxSize;

    /** PFET ON-OFF state */
    bool vbusPfetOn;
    
    /** CFET ON-OFF State */
    bool vbusCfetOn;
    
    /** VBUS RSENSE value */
    uint8_t vbusCsaRsense;
    
    /** Flag to indicate current foldback is active */
    uint32_t cfCur;

    /** Auto toggle enable from stack. */
    uint8_t volatile autoToggleEn;

    /** Auto toggle active state. */
    uint8_t volatile autoToggleAct;

    /** Type-C state machine re-enable pending. */
    uint8_t volatile typecStartPending;

    /** OVP fault pending on CC line. */
    uint8_t volatile ccOvpPending;
    
    /** DP/DM MUX config per port */ 
    cy_en_usbpd_dpdm_mux_cfg_t curDpdmCfg; 
    
    /** SBU Switch 1 State per port */ 
    cy_en_usbpd_sbu_switch_state_t sbu1State;

    /** SBU Switch 2 State per port */ 
    cy_en_usbpd_sbu_switch_state_t sbu2State;

    /** Aux 1 Resistor State */
    cy_en_usbpd_aux_resistor_config_t aux1Config; 

    /** Aux 2 Resistor State */
    cy_en_usbpd_aux_resistor_config_t aux2Config; 
    
    /** Callback function for VCONN OCP fault */
    cy_cb_vbus_fault_t vconnOcpCbk;
    
    /** Callback function for VBUS OVP fault */
    cy_cb_vbus_fault_t vbusOvpCbk;
    
    /** Callback function for VBUS UVP fault */
    cy_cb_vbus_fault_t vbusUvpCbk;
    
    /** Callback function for VBUS OCP fault */
    cy_cb_vbus_fault_t vbusOcpCbk;

#if defined(CY_DEVICE_SERIES_PMG1B1)
    /** Callback function for VBAT OVP fault */
    cy_cb_vbus_fault_t vbatOvpCbk;

    /** Callback function for VBAT UVP fault */
    cy_cb_vbus_fault_t vbatUvpCbk;

    /** Callback function for VBAT OCP fault */
    cy_cb_vbus_fault_t vbatOcpCbk;
#endif /* defined(CY_DEVICE_SERIES_PMG1B1) */

    /** Callback function for CC/SBU OVP fault */
    cy_cb_vbus_fault_t ccSbuOvpCbk;

    /** Callback function for VBUS RCP fault */
    cy_cb_vbus_fault_t vbusRcpCbk;

    /** Callback function for VBUS SCP fault */
    cy_cb_vbus_fault_t vbusScpCbk;

    /** Callback function for USBPD driver events */
    cy_usbpd_evt_cbk_t usbpdEventsCbk;

    /** Callback function for Type C driver events */
    cy_usbpd_typec_evt_cbk_t typecEventsCbk;

    /** Pointer to the PDSTACK Context. */
    void *pdStackContext;

    /** Pointer to the usbpd config structure. */
    cy_stc_usbpd_config_t *usbpdConfig;

    /** Pointer to the DPM status structure. */
    cy_cb_pd_dpm_get_config_t dpmGetConfig;

    /** The Vbus current change callback handler, refer to 'cy_cable_comp_vbus_cur_cbk'. */
    cy_cable_comp_vbus_cur_cbk cableCompVbusCurCbk;

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    
    /** Callback function for SR Comparator */
    cy_pd_cmp_cbk_t srCmpCbk;
    
    /** Callback function for PFC Comparator */
    cy_pd_cmp_cbk_t pfcCmpCbk;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    /** Cable compensation structure */
    cy_stc_cable_comp_cfg_t cableStat;

    /** VBUS slow discharge structure */
    cy_stc_slow_discharge_cfg_t vbusSlowDischarge;

    /** Callback function for fault timer start */
    cy_timer_start_t timerStartcbk;

    /** Callback function for fault timer stop */
    cy_timer_stop_t  timerStopcbk;

    /** Callback function for fault timer is running */
    cy_timer_is_running_t timerIsRunningcbk;

    /** Callback function for get timer multiplier */
    cy_timer_get_multiplier_t timerGetMultipliercbk;

    /** Callback function for vbus slow discharge */
    cy_slow_discharge_t vbusSlowDischargecbk;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /** Structure to use use dynamic CC/CF gain setting at 3A switchover */
    cy_stc_trims_cfg_t trimsConfig;
    
    /** Peak Current Resistance */
    uint8_t peak_current_sense_resistor;
#endif /*(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    /** Callback function for vbus current foldback */
    cy_vbus_cf_cbk_t cfCbk;

    /** Flag that indicates VBUS voltage transition is in idle state. */
    volatile bool vbtrIdle;

    /** Callback function for VBUS voltage transition. */
    cy_cb_adc_events_t vbtrCbk;

    /** Flag that indicates VBUS current transition is in idle state. */
    volatile bool ibtrIdle;

    /** Callback function for VBUS current transition. */
    cy_cb_adc_events_t ibtrCbk;

    /** GPIO port base for VBAT-GND SCP. */
    GPIO_PRT_Type *vbatGndFetPort;

    /** GPIO pin number for VBAT-GND SCP. */
    uint32_t vbatGndFetPin;

    /** Flag that indicates the enable/disable status for VBAT-GND SCP */
    bool vbatGndScpEnStatus;

    /** Flag that indicates the VBAT-GND SCP mode */
    uint8_t vbatGndScpMode;

    /** Flag that indicates gate driver type for VBAT-GND SCP FET */
    bool vbatGndScpPgdoType;

    /** Callback function for VBAT-GND SCP */
    cy_cb_adc_events_t vbatGndScpCb;

    /** Inductor current limit fault enable/disable flag */
    bool bbIlimDetEnStatus;

    /** VDDD regulator brown out fault detect enable/disable flag */
    volatile bool brownOutDetEnStatus;

    /** VDDD regulator current inrush fault detect enable/disable flag */
    volatile bool vregInrushDetEnStatus;

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))

    /** Variables used to backup the Ref Gen clock divider values before entering into sleep */
    uint32_t refgenClkDividerValue;
    
      /** Variables used to backup the clock select values before entering into sleep */
    uint32_t clkSelectValue;
    
    /** Variables used to backup the Filter1 clock divider values before entering into sleep */
    uint32_t filt1ClkDividerValue;
    
#if (defined(CCG_CDP_EN) && BATTERY_CHARGING_ENABLE)
    
    /** Structure to hold CDP State Machine related information */
    cdp_sm_vars cdpState;
    
#endif /* (defined(CCG_CDP_EN) && BATTERY_CHARGING_ENABLE) */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    
    /** VBUS_IN_DISCHARGE Enable */
    bool vbusInDischargeEn;
    
    /** VBus SCP software Limit */
    uint16_t vbusScpLimit;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    /** VBus OCP software debounce in ms. */
    uint8_t ocpSwDbMs;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)) */

    /** VBTR module source transition pending status */
    volatile bool vbtrSrcPending;

    /** VBTR module sink transition pending status */
    volatile bool vbtrSnkPending;

    /** Buck boost soft start voltage ramp OVP callback function. OVP is detected using
     * UVP comparator. */
    cy_cb_vbus_fault_t bbOvpCbk;

    /** Current foldback enable status */
    bool cfEnStatus;

    /** Input under voltage protection enable status */
    bool vinUvpIsEnabled;

    /** Callback function to be executed on input under voltage event */
    cy_cb_adc_events_t vinUvpCbk;

    /** Input over voltage protection enable status */
    bool vinOvpIsEnabled;

    /** Callback function to be executed on input over voltage event */
    cy_cb_adc_events_t vinOvpCbk;

    /** Callback function for VCONN SCP fault */
    cy_cb_vbus_fault_t vconnScpCbk;
    
    /** Pointer to configuration table */
    const void *cfg_table;

    /** Callback function for PDS SCP comparator */
    cy_cb_adc_events_t pdsScpCbk;

    /** Callback function for CC Up comparator */
    cy_cb_adc_events_t ccUpCbk;

    /** Callback function for CC Down comparator */
    cy_cb_adc_events_t ccDnCbk;

    /** Callback function for iLim comparator */
    cy_cb_adc_events_t bbIlimCbk;

    /** Callback function for Internal regulator (VREG) inrush detection */
    cy_cb_adc_events_t vregInrushCbk;

    /** Callback function for Brown Out Detection (BOD) detection */
    cy_cb_adc_events_t bodCbk;

    /** Buck-boost regulation enable status */
    bool bbEnableStatus;

    /** Buck-boost regulation enable sequence complete status */
    bool bbEnableDoneStatus;
    
    /** Variable to keep soft start pwm duty */
    uint16_t bbSsPwmDuty;
    
#if (CCG_PD_DUALPORT_ENABLE || PMG1_PD_DUALPORT_ENABLE)

    /** Variable to for number of active ports */
    uint32_t pdssActivePorts;
#endif /* (CCG_PD_DUALPORT_ENABLE || PMG1_PD_DUALPORT_ENABLE) */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /** Deep sleep entry register backup. */
    uint32_t vregActive40;
    
    /** Deep sleep entry register backup. */
    uint32_t vconn20CtrlActive;
    
    /** Deep sleep entry register backup. */
    uint32_t pump5vCtrlActive;
#if PDL_VBAT_GND_SCP_ENABLE
    /** VBAT-GND SCP uses VBUS SCP reference (SEL4) in deep sleep */
    uint8_t bat2gndVrefActive;
#else /* !PDL_VBAT_GND_SCP_ENABLE */
    /** VBAT-GND SCP uses VBUS SCP reference (SEL4) in deep sleep */
    uint32_t bbBat2gndProtCnfgActive;
#endif /* !PDL_VBAT_GND_SCP_ENABLE */
#if defined(CY_DEVICE_CCG7D) 
    /** Variables used to backup the BB Soft divider values before entering into sleep */
    uint32_t bbSoftClkDividerValue;
#endif /* defined(CY_DEVICE_CCG7D)  */
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */
    /** Enable polling for VSYS status change */
    uint8_t pollForVsys;

    /** USBPD context pointer for all ports. */
    struct cy_stc_usbpd_context_t_ *altPortUsbPdCtx[NO_OF_TYPEC_PORTS];

    /** Callback function for BB Vout RCP fault */
    cy_cb_vbus_fault_t voutRcpCbk;

    /** Array to store CC registers before updating */
    uint32_t ccRegisters[6];
} cy_stc_usbpd_context_t;


/** \} group_usbpd_common_data_structures */


/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/
/** \cond INTERNAL*/
__STATIC_INLINE uint32_t Cy_USBPD_MmioRegUpdateField(uint32_t origval, uint32_t fld, uint32_t mask, uint8_t pos);

__STATIC_INLINE void Cy_USBPD_MemCopyWord(uint32_t* dest, const uint32_t* source, uint32_t size);

/*******************************************************************************
*                     In-line Function Implementation
*******************************************************************************/

/*******************************************************************************
* Function Name: Cy_USBPD_MmioRegUpdateField
****************************************************************************//**
*
* Updates a register field with a new value.
*
* \param origval
* The current value of the register.
*
* \param fld
* The register field value to be updated.
*
* \param mask
* Register field mask.
*
* \param pos
* The register field position to be updated.
*
* \return uint32_t
* Returns the new value of the register
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_USBPD_MmioRegUpdateField(uint32_t origval, uint32_t fld, uint32_t mask, uint8_t pos)
{
    return ((origval & ~mask) | (fld << pos));
}

/*******************************************************************************
* Function Name: Cy_USBPD_MemCopyWord
****************************************************************************//**
*
* Copies a 32-bit word from source address to destination address
*
* \param dest
* The destination address pointer.
*
* \param source
* The source address pointer.
*
* \param size
* Number of 32-bit words to be copied.
*
*******************************************************************************/
__STATIC_INLINE void Cy_USBPD_MemCopyWord(uint32_t* dest, const uint32_t* source, uint32_t size)
{
    uint32_t i;
    for(i = 0 ; i < size; i++)
    {
        dest[i] = source[i];
    }
}

/** \endcond */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_COMMON_H_ */

/** \} group_usbpd_common */

/* [] End of File */
