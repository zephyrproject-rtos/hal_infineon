/***************************************************************************//**
* \file cy_usbpd_defines.h
* \version 2.110
*
* Provides Common Header File of the USBPD specification related structures.
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
#ifndef _CY_USBPD_DEFINES_H_
#define _CY_USBPD_DEFINES_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "cy_device.h"
#include "cy_device_headers.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

/* Provide default values for feature selection macros where not already defined. */
#ifndef CY_PD_REV3_ENABLE
#define CY_PD_REV3_ENABLE               (1u)
#endif /* CY_PD_REV3_ENABLE */

#ifndef CY_PD_USB4_SUPPORT_ENABLE
#define CY_PD_USB4_SUPPORT_ENABLE       (0u)
#endif /* CY_PD_USB4_SUPPORT_ENABLE */

#ifndef CY_PD_FRS_RX_ENABLE
#define CY_PD_FRS_RX_ENABLE             (0u)
#endif /* CY_PD_FRS_RX_ENABLE */

#ifndef CY_PD_FRS_TX_ENABLE
#define CY_PD_FRS_TX_ENABLE             (0u)
#endif /* CY_PD_FRS_TX_ENABLE */

#ifndef CY_PD_SINK_ONLY
#ifdef CY_DEVICE_CCG3PA
#define CY_PD_SINK_ONLY                 (1u)
#else
#define CY_PD_SINK_ONLY                 (0u)
#endif /* CY_DEVICE_CCG3PA */
#endif /* CY_PD_SINK_ONLY */

#ifndef PMG1_FLIPPED_FET_CTRL
#define PMG1_FLIPPED_FET_CTRL           (0u)
#endif /* PMG1_FLIPPED_FET_CTRL */

#ifndef CCG_SRC_FET
#define CCG_SRC_FET                     (PMG1_FLIPPED_FET_CTRL == 0u)
#endif /* CCG_SRC_FET */

#ifndef CCG_SNK_FET
#define CCG_SNK_FET                     (PMG1_FLIPPED_FET_CTRL)
#endif /* CCG_SNK_FET  */

#ifndef SYS_DEEPSLEEP_ENABLE
#define SYS_DEEPSLEEP_ENABLE            (0u)
#endif /* SYS_DEEPSLEEP_ENABLE */

#ifndef VBUS_OVP_ENABLE
#define VBUS_OVP_ENABLE                 (0u)
#endif /* VBUS_OVP_ENABLE */

#if VBUS_OVP_ENABLE
#define PDL_VBUS_OVP_ENABLE             (1u)
#endif /* VBUS_OVP_ENABLE */

#ifndef PDL_VBUS_OVP_ENABLE
#define PDL_VBUS_OVP_ENABLE             (0u)
#endif /* PDL_VBUS_OVP_ENABLE */

#ifndef CY_PD_SOURCE_ONLY
#define CY_PD_SOURCE_ONLY               (0u)
#endif /* CY_PD_SOURCE_ONLY */

#ifndef CY_PD_VBUS_CF_EN
#define CY_PD_VBUS_CF_EN                (0u)
#endif /* CY_PD_VBUS_CF_EN */

#ifndef VBUS_ILIM_ENABLE
#define VBUS_ILIM_ENABLE                 (0u)
#endif /* VBUS_ILIM_ENABLE */

#if VBUS_ILIM_ENABLE
#define PDL_VBUS_ILIM_ENABLE             (1u)
#endif /* VBUS_ILIM_ENABLE */

#ifndef PDL_VBUS_ILIM_ENABLE
#define PDL_VBUS_ILIM_ENABLE             (0u)
#endif /* PDL_VBUS_ILIM_ENABLE */

#ifndef VBUS_UVP_ENABLE
#define VBUS_UVP_ENABLE                 (0u)
#endif /* VBUS_UVP_ENABLE */

#if (VBUS_UVP_ENABLE || VBUS_ILIM_ENABLE)
#define PDL_VBUS_UVP_ENABLE             (1u)
#endif /* (VBUS_UVP_ENABLE || VBUS_ILIM_ENABLE) */

#ifndef PDL_VBUS_UVP_ENABLE
#define PDL_VBUS_UVP_ENABLE             (0u)
#endif /* PDL_VBUS_UVP_ENABLE */

#ifndef PMG1_HPD_RX_ENABLE
#define PMG1_HPD_RX_ENABLE              (0u)
#endif /* PMG1_HPD_RX_ENABLE */

#ifndef PMG1B1_USB_CHARGER
#define PMG1B1_USB_CHARGER              (0u)
#endif /* PMG1B1_USB_CHARGER */

#ifndef QC_AFC_CHARGING_DISABLED
#define QC_AFC_CHARGING_DISABLED        (1u)
#endif /* QC_AFC_CHARGING_DISABLED */

#ifndef QC_SRC_AFC_CHARGING_DISABLED
#define QC_SRC_AFC_CHARGING_DISABLED    (1u)
#endif /* QC_SRC_AFC_CHARGING_DISABLED */

#ifndef BC_AFC_SINK_ERROR_INT_ENABLE
#define BC_AFC_SINK_ERROR_INT_ENABLE    (0u)
#endif /* BC_AFC_SINK_ERROR_INT_ENABLE */

#ifndef ENABLE_APPLE_BC12_SUPPORT
#define ENABLE_APPLE_BC12_SUPPORT       (0u)
#endif /* ENABLE_APPLE_BC12_SUPPORT */

#ifndef BC_SOURCE_ONLY
#define BC_SOURCE_ONLY                  (0u)
#endif /* BC_SOURCE_ONLY */

#ifndef CCG_TYPE_A_PORT_ENABLE
#define CCG_TYPE_A_PORT_ENABLE          (0u)
#endif /* CCG_TYPE_A_PORT_ENABLE */

#ifndef NO_OF_BC_PORTS
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_PMG1S3) || CCG_TYPE_A_PORT_ENABLE)
#define NO_OF_BC_PORTS                  (2u)
#else
#define NO_OF_BC_PORTS                  (1u)
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_PMG1S3)) */
#endif /* NO_OF_BC_PORTS */

#ifndef SOFT_START_ENABLE
#define SOFT_START_ENABLE               (0u)
#endif /* SOFT_START_ENABLE */

#ifndef VBUS_IN_DISCHARGE_EN
#define VBUS_IN_DISCHARGE_EN            (0u)
#endif /* VBUS_IN_DISCHARGE_EN */

#ifndef LSCSA_SKIP_125_GAIN
#define LSCSA_SKIP_125_GAIN             (0u)
#endif /* LSCSA_SKIP_125_GAIN */

#ifndef VBUS_CTRL_TYPE_P1
#define VBUS_CTRL_TYPE_P1               (0u)
#endif /* VBUS_CTRL_TYPE_P1 */

#ifndef VBUS_CTRL_PWM
#define VBUS_CTRL_PWM                   (1u)
#endif /* VBUS_CTRL_PWM */

#ifndef VBUS_CTRL_DIR_FB
#define VBUS_CTRL_DIR_FB                (2u)
#endif /* VBUS_CTRL_DIR_FB */

#ifndef VBUS_CTRL_OPTO_FB
#define VBUS_CTRL_OPTO_FB               (3u)
#endif /* VBUS_CTRL_OPTO_FB */

#ifndef VBUS_CTRL_BB
#define VBUS_CTRL_BB                    (4u)
#endif /* VBUS_CTRL_BB */

#ifndef VBUS_OCP_ENABLE
#define VBUS_OCP_ENABLE                 (0u)
#endif /* VBUS_OCP_ENABLE */

#if VBUS_OCP_ENABLE
#define PDL_VBUS_OCP_ENABLE             (1u)
#endif /* VBUS_OCP_ENABLE */

#ifndef PDL_VBUS_OCP_ENABLE
#define PDL_VBUS_OCP_ENABLE             (0u)
#endif /* PDL_VBUS_OCP_ENABLE */

#ifndef VBUS_SCP_ENABLE
#define VBUS_SCP_ENABLE                 (0u)
#endif /* VBUS_SCP_ENABLE */

#if VBUS_SCP_ENABLE
#define PDL_VBUS_SCP_ENABLE             (1u)
#endif /* VBUS_SCP_ENABLE */

#ifndef PDL_VBUS_SCP_ENABLE
#define PDL_VBUS_SCP_ENABLE             (0u)
#endif /* PDL_VBUS_SCP_ENABLE */

#ifndef VBUS_RCP_ENABLE
#define VBUS_RCP_ENABLE                 (0u)
#endif /* VBUS_RCP_ENABLE */

#if VBUS_RCP_ENABLE
#define PDL_VBUS_RCP_ENABLE             (1u)
#endif /* VBUS_RCP_ENABLE */

/* Enable CC OVP by default as the macro introduce newly. */
#ifndef CC_OVP_ENABLE
#define CC_OVP_ENABLE                 (1u)
#endif /* CC_OVP_ENABLE */

#if CC_OVP_ENABLE
#define PDL_CC_OVP_ENABLE             (1u)
#endif /* CC_OVP_ENABLE */

#ifndef PDL_CC_OVP_ENABLE
#define PDL_CC_OVP_ENABLE             (0u)
#endif /* PDL_CC_OVP_ENABLE */

/* Enable SBU OVP by default as the macro introduce newly. */
#ifndef SBU_OVP_ENABLE
#define SBU_OVP_ENABLE                 (1u)
#endif /* SBU_OVP_ENABLE */

#if SBU_OVP_ENABLE
#define PDL_SBU_OVP_ENABLE             (1u)
#endif /* SBU_OVP_ENABLE */

#ifndef PDL_SBU_OVP_ENABLE
#define PDL_SBU_OVP_ENABLE             (0u)
#endif /* PDL_SBU_OVP_ENABLE */

#ifndef PDL_VBUS_RCP_ENABLE
#define PDL_VBUS_RCP_ENABLE             (0u)
#endif /* PDL_VBUS_RCP_ENABLE */

#ifndef PMG1_V5V_CHANGE_DETECT
#define PMG1_V5V_CHANGE_DETECT          (0u)
#endif /* PMG1_V5V_CHANGE_DETECT */

#ifndef CY_PD_CRC_ERR_HANDLING_ENABLE
#define CY_PD_CRC_ERR_HANDLING_ENABLE   (1u)
#endif /* CY_PD_CRC_ERR_HANDLING_ENABLE */

#ifndef CY_PD_BIST_MODE_DISABLE
#define CY_PD_BIST_MODE_DISABLE         (0u)
#endif /* CY_PD_BIST_MODE_DISABLE */

#ifndef CY_HPD_ENABLE
#define CY_HPD_ENABLE                   (0u)
#endif /* CY_HPD_ENABLE */

#ifndef CY_PD_HW_DRP_TOGGLE_ENABLE
#define CY_PD_HW_DRP_TOGGLE_ENABLE      (0u)
#endif /* CY_PD_HW_DRP_TOGGLE_ENABLE */

#ifndef BATTERY_CHARGING_ENABLE
#define BATTERY_CHARGING_ENABLE         (0u)
#endif /* BATTERY_CHARGING_ENABLE */

#ifndef PSVP_FPGA_ENABLE
#ifdef CY_DEVICE_PMG1S3
#define PSVP_FPGA_ENABLE                (0u)
#else
#define PSVP_FPGA_ENABLE                (0u)
#endif /* CY_DEVICE_PMG1S3 */
#endif /* PSVP_FPGA_ENABLE */


#ifndef CY_PD_EPR_ENABLE
#define CY_PD_EPR_ENABLE                (0u)
#endif /* CY_PD_EPR_ENABLE */

#ifndef VBTR_ENABLE
#define VBTR_ENABLE                     (0u)
#endif /* VBTR_ENABLE */

#if VBTR_ENABLE
#define PDL_VBTR_ENABLE                 (1u)
#endif /* VBTR_ENABLE */

#ifndef PDL_VBTR_ENABLE
#define PDL_VBTR_ENABLE                 (0u)
#endif /* PDL_VBTR_ENABLE */

#ifndef IBTR_ENABLE
#define IBTR_ENABLE                     (0u)
#endif /* IBTR_ENABLE */

#if IBTR_ENABLE
#define PDL_IBTR_ENABLE                 (1u)
#endif /* IBTR_ENABLE */

#ifndef PDL_IBTR_ENABLE
#define PDL_IBTR_ENABLE                 (0u)
#endif /* PDL_IBTR_ENABLE */

#ifndef CCG_CF_HW_DET_ENABLE
#define CCG_CF_HW_DET_ENABLE            (0u)
#endif /* CCG_CF_HW_DET_ENABLE */

#ifndef BB_ILIM_DET_ENABLE
#define BB_ILIM_DET_ENABLE              (0u)
#endif /* BB_ILIM_DET_ENABLE */

#if BB_ILIM_DET_ENABLE
#define PDL_BB_ILIM_DET_ENABLE          (1u)
#endif /* BB_ILIM_DET_ENABLE */

#ifndef PDL_BB_ILIM_DET_ENABLE
#define PDL_BB_ILIM_DET_ENABLE          (0u)
#endif /* PDL_BB_ILIM_DET_ENABLE */

#ifndef VBAT_GND_SCP_ENABLE
#define VBAT_GND_SCP_ENABLE             (0u)
#endif /* VBAT_GND_SCP_ENABLE */

#if VBAT_GND_SCP_ENABLE
#define PDL_VBAT_GND_SCP_ENABLE         (1u)
#endif /* VBAT_GND_SCP_ENABLE */

#ifndef PDL_VBAT_GND_SCP_ENABLE
#define PDL_VBAT_GND_SCP_ENABLE         (0u)
#endif /* PDL_VBAT_GND_SCP_ENABLE */

#ifndef VREG_BROWN_OUT_DET_ENABLE
#define VREG_BROWN_OUT_DET_ENABLE       (0u)
#endif /* VREG_BROWN_OUT_DET_ENABLE */

#if VREG_BROWN_OUT_DET_ENABLE
#define PDL_VREG_BROWN_OUT_DET_ENABLE   (1u)
#endif /* VREG_BROWN_OUT_DET_ENABLE */

#ifndef PDL_VREG_BROWN_OUT_DET_ENABLE
#define PDL_VREG_BROWN_OUT_DET_ENABLE   (0u)
#endif /* PDL_VREG_BROWN_OUT_DET_ENABLE */

#ifndef VREG_INRUSH_DET_ENABLE
#define VREG_INRUSH_DET_ENABLE          (0u)
#endif /* VREG_INRUSH_DET_ENABLE */

#if VREG_INRUSH_DET_ENABLE
#define PDL_VREG_INRUSH_DET_ENABLE      (1u)
#endif /* VREG_INRUSH_DET_ENABLE */

#ifndef PDL_VREG_INRUSH_DET_ENABLE
#define PDL_VREG_INRUSH_DET_ENABLE      (0u)
#endif /* PDL_VREG_INRUSH_DET_ENABLE */

#ifndef PDL_VOUTBB_RCP_ENABLE
#define PDL_VOUTBB_RCP_ENABLE          (0u)
#endif /* PDL_VOUTBB_RCP_ENABLE */

#ifndef VBUS_CTRL_TRIM_ADJUST_ENABLE
#define VBUS_CTRL_TRIM_ADJUST_ENABLE    (0u)
#endif /* VBUS_CTRL_TRIM_ADJUST_ENABLE */

#ifndef APP_VBUS_SRC_FET_BYPASS_EN
#define APP_VBUS_SRC_FET_BYPASS_EN      (0u)
#endif /* APP_VBUS_SRC_FET_BYPASS_EN */

#ifndef CCG_TEMP_BASED_VOLTAGE_THROTTLING
#define CCG_TEMP_BASED_VOLTAGE_THROTTLING   (0u)
#endif /* CCG_TEMP_BASED_VOLTAGE_THROTTLING */

#ifndef OTP_ENABLE
#define OTP_ENABLE                      (0u)
#endif /* OTP_ENABLE */
#ifndef ADFT_DDFT_EN
#define ADFT_DDFT_EN                    (0u)
#endif /* ADFT_DDFT_EN */

#ifndef FG_PART
#define FG_PART                         (0u)
#endif /* FG_PART */

#ifndef CCG_SROM_CODE_ENABLE
#define CCG_SROM_CODE_ENABLE            (0u)
#endif /* CCG_SROM_CODE_ENABLE */

#ifndef GENERATE_SROM_CODE
#define GENERATE_SROM_CODE              (0u)
#endif /* GENERATE_SROM_CODE */

#if (defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_PMG1S3))
#if !CCG_SROM_CODE_ENABLE
#ifndef PDL_ATTRIBUTES
#define PDL_ATTRIBUTES
#endif /* PDL_ATTRIBUTES */
#ifndef ROM_CONSTANT
#define ROM_CONSTANT
#endif /* ROM_CONSTANT */
#endif /* !CCG_SROM_CODE_ENABLE */
#else
#ifndef PDL_ATTRIBUTES
#define PDL_ATTRIBUTES
#endif /* PDL_ATTRIBUTES */
#ifndef ROM_CONSTANT
#define ROM_CONSTANT
#endif /* ROM_CONSTANT */
#endif /* (defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_PMG1S3)) */

#if !CCG_SROM_CODE_ENABLE
#ifndef CALL_MAP
#define CALL_MAP(func)                (func)
#endif /* CALL_MAP */

#ifndef MODULE_DISABLE
#define MODULE_DISABLE                    (0u)
#endif /* MODULE_DISABLE */

#ifndef MODULE_IN_ROM
#define MODULE_IN_ROM                     (1u)
#endif /* MODULE_IN_ROM */

#ifndef MODULE_IN_FLASH
#define MODULE_IN_FLASH                 (2u)
#endif /* MODULE_IN_FLASH */
#endif /* !CCG_SROM_CODE_ENABLE */

/*
 * Enable / disable VBUS Slow Discharge Feature. When this feature is enabled,
 * the discharge drive strength shall be increased by steps every ms until the
 * selected top drive strength is achieved. Similarly, the drive strength is
 * decreased in steps while stopping the discharge.
 */
#ifndef VBUS_SLOW_DISCHARGE_EN
#define VBUS_SLOW_DISCHARGE_EN                  (0u)
#endif /* VBUS_SLOW_DISCHARGE_EN */

/*
 * Whether to leave the PD block ON even when the PD port is disabled. This
 * is required if features like ADC need to be used while the port is OFF.
 */
#ifndef CCG_PD_BLOCK_ALWAYS_ON
#define CCG_PD_BLOCK_ALWAYS_ON                  (0u)
#endif /* CCG_PD_BLOCK_ALWAYS_ON */

#ifndef CCG_PD_DUALPORT_ENABLE
#if defined(CY_DEVICE_CCG7D)
#define CCG_PD_DUALPORT_ENABLE                  (1u)
#else
#define CCG_PD_DUALPORT_ENABLE                  (0u)
#endif /* defined(CY_DEVICE_CCG7D) */
#endif /* CCG_PD_DUALPORT_ENABLE */

#ifndef CY_USBPD_CGND_SHIFT_ENABLE

#if defined(CY_DEVICE_CCG7S)
#define CY_USBPD_CGND_SHIFT_ENABLE              (1u)
#else /* !(defined(CY_DEVICE_CCG7S)) */
#define CY_USBPD_CGND_SHIFT_ENABLE              (0u)
#endif /* (defined(CY_DEVICE_CCG7S)) */

#endif /* CY_USBPD_CGND_SHIFT_ENABLE */

#ifndef BB_PWM_ASYNC_MODE_ENABLE

#if defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
#define BB_PWM_ASYNC_MODE_ENABLE (1u)
#else /* !(defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#define BB_PWM_ASYNC_MODE_ENABLE (0u)
#endif /* (defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

#endif /* BB_PWM_ASYNC_MODE_ENABLE */

#ifndef BB_MODE_PSM_ONLY
#define BB_MODE_PSM_ONLY                        (0u)
#endif /* BB_MODE_PSM_ONLY */

#ifndef VBTR_MULTI_SLOPE_ENABLE
#define VBTR_MULTI_SLOPE_ENABLE                 (0u)
#endif /* VBTR_MULTI_SLOPE_ENABLE */

#ifndef VIN_UVP_ENABLE
#define VIN_UVP_ENABLE                          (0u)
#endif /* VIN_UVP_ENABLE */

#if VIN_UVP_ENABLE
#define PDL_VIN_UVP_ENABLE                      (1u)
#endif /* VIN_UVP_ENABLE */

#ifndef PDL_VIN_UVP_ENABLE
#define PDL_VIN_UVP_ENABLE                      (0u)
#endif /* PDL_VIN_UVP_ENABLE */

#ifndef VIN_OVP_ENABLE
#define VIN_OVP_ENABLE                          (0u)
#endif /* VIN_OVP_ENABLE */

#if VIN_OVP_ENABLE
#define PDL_VIN_OVP_ENABLE                      (1u)
#endif /* VIN_OVP_ENABLE */

#ifndef PDL_VIN_OVP_ENABLE
#define PDL_VIN_OVP_ENABLE                      (0u)
#endif /* PDL_VIN_OVP_ENABLE */

#ifndef VCONN_OCP_ENABLE
#define VCONN_OCP_ENABLE                        (0u)
#endif /* VCONN_OCP_ENABLE */

#if VCONN_OCP_ENABLE
#define PDL_VCONN_OCP_ENABLE                    (1u)
#endif /* VCONN_OCP_ENABLE */

#ifndef PDL_VCONN_OCP_ENABLE
#define PDL_VCONN_OCP_ENABLE                    (0u)
#endif /* PDL_VCONN_OCP_ENABLE */

#ifndef VCONN_SCP_ENABLE
#define VCONN_SCP_ENABLE                        (0u)
#endif /* VCONN_SCP_ENABLE */

#if VCONN_SCP_ENABLE
#define PDL_VCONN_SCP_ENABLE                    (1u)
#endif /* VCONN_SCP_ENABLE */

#ifndef PDL_VCONN_SCP_ENABLE
#define PDL_VCONN_SCP_ENABLE                    (0u)
#endif /* PDL_VCONN_SCP_ENABLE */

#ifndef CCG_DYN_PFET_GATE_DRV_ENABLE
#define CCG_DYN_PFET_GATE_DRV_ENABLE            (0u)
#endif /* CCG_DYN_PFET_GATE_DRV_ENABLE */

#ifndef CCG_DYN_PFET_GATE_DRV_TYP
#define CCG_DYN_PFET_GATE_DRV_TYP               (30u)
#endif /* CCG_DYN_PFET_GATE_DRV_TYP */

#ifndef VBUS_DEFINE_SOLN_MAX_CURRENT_EN
/* Enables to set solution specific max OCP current threshold */
#define VBUS_DEFINE_SOLN_MAX_CURRENT_EN         (0u)
#endif /* VBUS_DEFINE_SOLN_MAX_CURRENT_EN */

#ifndef VBUS_MAX_CURRENT
#if VBUS_DEFINE_SOLN_MAX_CURRENT_EN
/*
 * Solution specific Maximum limit on the VBUS current (in 10mA units).
 * This overrides the default PD HAL behavior max OCP current threshold.
 */
#define VBUS_MAX_CURRENT                            (530u)
#endif /* VBUS_DEFINE_SOLN_MAX_CURRENT_EN */
#endif /* VBUS_MAX_CURRENT */

#ifndef QC_PPS_ENABLE
#define QC_PPS_ENABLE                               (0u)
#endif /* QC_PPS_ENABLE */

#ifndef CY_USE_CONFIG_TABLE
#define CY_USE_CONFIG_TABLE                         (0u)
#endif /* CY_USE_CONFIG_TABLE */


#ifndef CY_PD_EPR_AVS_ENABLE
#define CY_PD_EPR_AVS_ENABLE                        (0u)
#endif /* CY_PD_EPR_AVS_ENABLE */

#ifndef SBU_LEVEL_DETECT_EN
#define SBU_LEVEL_DETECT_EN                         (0u)
#endif /* SBU_LEVEL_DETECT_EN */

#ifndef TERM_AUX_LS_ENABLE
#define TERM_AUX_LS_ENABLE                          (0u)
#endif /* TERM_AUX_LS_ENABLE */

#if TERM_AUX_LS_ENABLE
#define PDL_TERM_AUX_LS_ENABLE                      (1u)
#endif /* TERM_AUX_LS_ENABLE */

#ifndef PDL_TERM_AUX_LS_ENABLE
#define PDL_TERM_AUX_LS_ENABLE                      (0u)
#endif /* PDL_TERM_AUX_LS_ENABLE */

#ifndef CY_USBPD_PDS_SSC_ENABLE
#define CY_USBPD_PDS_SSC_ENABLE                     (0u)
#endif /* CY_USBPD_PDS_SSC_ENABLE */

#ifndef PD_CTRL_INF_PRESENT
#define PD_CTRL_INF_PRESENT                         (0u)
#endif /* PD_CTRL_INF_PRESENT */

#ifndef HFCLK_CHANGE_OVER_SLEEP
#if SYS_DEEPSLEEP_ENABLE
#define HFCLK_CHANGE_OVER_SLEEP                     (1u)
#else
#define HFCLK_CHANGE_OVER_SLEEP                     (0u)
#endif /* SYS_DEEPSLEEP_ENABLE */
#endif /* HFCLK_CHANGE_OVER_SLEEP */

#ifndef SYSCLK_CHANGE_OVER_SLEEP
#define SYSCLK_CHANGE_OVER_SLEEP                    (0u)
#endif /* SYSCLK_CHANGE_OVER_SLEEP */

#ifndef CY_PD_USE_ADC_IN_DS
#define CY_PD_USE_ADC_IN_DS                         (0u)
#endif /* CY_PD_USE_ADC_IN_DS */

#ifndef CY_PD_EPR_36V_SUPP_EN
#define CY_PD_EPR_36V_SUPP_EN           (0u)
#endif /* CY_PD_EPR_36V_SUPP_EN */

#ifndef CCG_PASC_LP_ENABLE
#define CCG_PASC_LP_ENABLE                          (0u)
#endif /*CCG_PASC_LP_ENABLE*/

/*******************************************************************************
 * MACRO Definitions
 ******************************************************************************/
/**
* \addtogroup group_usbpd_common_macros
* \{
*/

/** USB-C port number 0. Supported on all PMG1/CCGx devices. */
#define TYPEC_PORT_0_IDX                (0u)

/** USB-C port number 1. Supported only on the Dual Port devices. */
#define TYPEC_PORT_1_IDX                (1u)

/** CYPD8229_52LQXI part and CYPD8229_52LQXIT part has the same silicon ID. */
#if ((defined(CYPM1321_97BZXIT)) || \
        (defined(CYPM1322_97BZXIT)) || \
        (defined(CYPD8225_97BZXIT)) || \
        (defined(CY_DEVICE_CCG7D)) || \
        (defined(CYPD6229_52LQXI)) || \
        (defined(CYPD6229_52LQXIT)) || \
        (defined(CYPD8229_52LQXIT)))

#ifndef NO_OF_TYPEC_PORTS
/** Two USB-C ports supported on CYPM1322-97BZXIT part. */
#define NO_OF_TYPEC_PORTS               (2u)
#endif /*NO_OF_TYPEC_PORTS*/

#ifndef PMG1_PD_DUALPORT_ENABLE
/** Two USB-C ports supported on CYPM1322-97BZXIT part/CYPD7291-68LDXS part. */
#define PMG1_PD_DUALPORT_ENABLE         (1u)
#endif /* PMG1_PD_DUALPORT_ENABLE */

#else

#ifndef NO_OF_TYPEC_PORTS
/** Single USB-C port supported. */
#define NO_OF_TYPEC_PORTS               (1u)
#endif /*NO_OF_TYPEC_PORTS*/

#ifndef PMG1_PD_DUALPORT_ENABLE
/** Single USB-C port supported. */
#define PMG1_PD_DUALPORT_ENABLE         (0u)
#endif /* PMG1_PD_DUALPORT_ENABLE */

#endif /* CY_DEVICE */

/********************************* PD macros **********************************/

/** Maximum extended message 32-bit words. Each word is 32 bit. */
#define CY_PD_MAX_EXTD_PKT_WORDS                  (65u)

/** Vbus voltage = 0.8 V */
#define CY_PD_VSAFE_0V                            (800u)

/** Vbus voltage = 3.6 V */
#define CY_PD_VSAFE_3_6V                          (3600u)

/** Vbus voltage = 5.0 V */
#define CY_PD_VSAFE_5V                            (5000u)

/** Vbus voltage = 9.0 V */
#define CY_PD_VSAFE_9V                            (9000u)

/** Vbus voltage = 12.0 V */
#define CY_PD_VSAFE_12V                           (12000u)

/** Vbus voltage = 13.0 V */
#define CY_PD_VSAFE_13V                           (13000u)

/** Vbus voltage = 15.0 V */
#define CY_PD_VSAFE_15V                           (15000u)

/** Vbus voltage = 19.0 V */
#define CY_PD_VSAFE_19V                           (19000u)

/** Vbus voltage = 20.0 V */
#define CY_PD_VSAFE_20V                           (20000u)

/** Vbus voltage = 21.0 V */
#define CY_PD_VSAFE_21V                           (21000u)

/** Vbus voltage = 27.0 V */
#define CY_PD_VSAFE_27V                           (27000u)

/** Vbus voltage = 28.0 V */
#define CY_PD_VSAFE_28V                           (28000u)

/** Vbus voltage = 36.0 V */
#define CY_PD_VSAFE_36V                           (36000u)

/** Vbus voltage = 48.0 V */
#define CY_PD_VSAFE_48V                           (48000u)

/** PDP 100 W */
#define CY_PD_EPR_MIN_WATT                        (100u)

/** PDP 140 W */
#define CY_PD_EPR_MAX_28V_WATT                    (140u)

/** PDP 180 W */
#define CY_PD_EPR_MAX_36V_WATT                    (180u)

/** PDP 240 W */
#define CY_PD_EPR_MAX_48V_WATT                    (240u)

/** Round Up */
#define ROUND_UP(x, y)      ( ( ( (x) + ((y) - 1) ) / y ) * y)

/** Round Down */
#define ROUND_DOWN(x, y)      ( ( (x)  / y ) * y)

/** Reference to CC_1 pin in the Type-C connector. */
#define CY_PD_CC_CHANNEL_1                        (0u)

/** Reference to CC_2 pin in the Type-C connector. */
#define CY_PD_CC_CHANNEL_2                        (1u)

/** @cond DOXYGEN_HIDE */
#define CY_PD_REV_POS                          (6u)        /* Position of PD revision field in message header. */

#define CY_PD_REV_V1_0                         (0UL)        /* PD revision 1.0: Not supported by PMG1. */
#define CY_PD_REV_V2_0                         (1UL)        /* PD revision 2.0: Default supported revision. */
#define CY_PD_REV_V3_0                         (2UL)        /* PD revision 3.0. */
#define CY_PD_REV_RESERVED                     (3UL)        /* Reserved/undefined revision. */

#define CY_PD_TX_SOP_GD_CRC_HDR_DFLT              ((CY_PD_REV_V2_0 << CY_PD_REV_POS) | 0x0001U)
#define CY_PD_TX_SOP_PRIME_DPRIME_GD_CRC_HDR_DFLT ((CY_PD_TX_SOP_GD_CRC_HDR_DFLT <<16u) |CY_PD_TX_SOP_GD_CRC_HDR_DFLT)

/* Message masks for control messages. */
#define CY_PD_CTRL_MSG_RSRVD_MASK                 (0x1UL << CY_PD_CTRL_MSG_RSRVD)
#define CY_PD_CTRL_MSG_GOOD_CRC_MASK              (0x1UL << CY_PD_CTRL_MSG_GOOD_CRC)
#define CY_PD_CTRL_MSG_GO_TO_MIN_MASK             (0x1UL << CY_PD_CTRL_MSG_GO_TO_MIN)
#define CY_PD_CTRL_MSG_ACCEPT_MASK                (0x1UL << CY_PD_CTRL_MSG_ACCEPT)
#define CY_PD_CTRL_MSG_REJECT_MASK                (0x1UL << CY_PD_CTRL_MSG_REJECT)
#define CY_PD_CTRL_MSG_PING_MASK                  (0x1UL << CY_PD_CTRL_MSG_PING)
#define CY_PD_CTRL_MSG_PS_RDY_MASK                (0x1UL << CY_PD_CTRL_MSG_PS_RDY)
#define CY_PD_CTRL_MSG_GET_SOURCE_CAP_MASK        (0x1UL << CY_PD_CTRL_MSG_GET_SOURCE_CAP)
#define CY_PD_CTRL_MSG_GET_SINK_CAP_MASK          (0x1UL << CY_PD_CTRL_MSG_GET_SINK_CAP)
#define CY_PD_CTRL_MSG_DR_SWAP_MASK               (0x1UL << CY_PD_CTRL_MSG_DR_SWAP)
#define CY_PD_CTRL_MSG_PR_SWAP_MASK               (0x1UL << CY_PD_CTRL_MSG_PR_SWAP)
#define CY_PD_CTRL_MSG_VCONN_SWAP_MASK            (0x1UL << CY_PD_CTRL_MSG_VCONN_SWAP)
#define CY_PD_CTRL_MSG_WAIT_MASK                  (0x1UL << CY_PD_CTRL_MSG_WAIT)
#define CY_PD_CTRL_MSG_SOFT_RESET_MASK            (0x1UL << CY_PD_CTRL_MSG_SOFT_RESET)
#define CY_PD_CTRL_MSG_NOT_SUPPORTED_MASK         (0x1UL << CY_PD_CTRL_MSG_NOT_SUPPORTED)
#define CY_PD_CTRL_MSG_GET_SRC_CAP_EXTD_MASK      (0x1UL << CY_PD_CTRL_MSG_GET_SRC_CAP_EXTD)
#define CY_PD_CTRL_MSG_GET_STATUS_MASK            (0x1UL << CY_PD_CTRL_MSG_GET_STATUS)
#define CY_PD_CTRL_MSG_FR_SWAP_MASK               (0x1UL << CY_PD_CTRL_MSG_FR_SWAP)
#define CY_PD_CTRL_MSG_DATA_RESET_MASK            (0x1UL << CY_PD_CTRL_MSG_DATA_RESET)
#define CY_PD_CTRL_MSG_GET_SNK_CAP_EXTD_MASK      (0x1UL << CY_PD_CTRL_MSG_GET_SNK_CAP_EXTD)
#define CY_PD_EXTD_MSG_PPS_STATUS_MASK            (0x1UL << CY_PDSTACK_EXTD_MSG_PPS_STATUS)
#define CY_PD_CTRL_MSG_DATA_RESET_COMPLETE_MASK   (0x1UL << CY_PD_CTRL_MSG_DATA_RESET_COMPLETE)
#define CY_PD_CTRL_MSG_GET_SOURCE_INFO_MASK       (0x1UL << CY_PD_CTRL_MSG_GET_SOURCE_INFO)
#define CY_PD_CTRL_MSG_GET_REVISION_MASK          (0x1UL << CY_PD_CTRL_MSG_GET_REVISION)

/** @endcond */

/** Macro to update DR and PR role in PD header. */
#define CY_PD_DR_PR_ROLE(dataRole,pwrRole)   (((pwrRole) << 8) | ((dataRole) << 5))

/** \} group_usbpd_common_macros */

/*******************************************************************************
*                            Enumerated Types
*******************************************************************************/

/**
* \addtogroup group_usbpd_common_enums
* \{
*/
/** Enum of the SOP (Start Of Frame) types. */
typedef enum
{
    CY_PD_SOP = 0,                            /**< SOP: Used for communication with port partner. */
    CY_PD_SOP_PRIME,                          /**< SOP': Cable marker communication. */
    CY_PD_SOP_DPRIME,                         /**< SOP'': Cable marker communication. */
    CY_PD_SOP_P_DEBUG,                        /**< SOP'_Debug */
    CY_PD_SOP_DP_DEBUG,                       /**< SOP''_Debug */
    CY_PD_HARD_RESET,                         /**< Hard Reset */
    CY_PD_CABLE_RESET,                        /**< Cable Reset */
    CY_PD_SOP_INVALID                         /**< Undefined ordered set. */
} cy_en_pd_sop_t;

/**
 * @typedef cy_en_pd_port_role_t
 * @brief Enum of the PD port roles.
 */
typedef enum
{
    CY_PD_PRT_ROLE_SINK = 0,                  /**< Power sink */
    CY_PD_PRT_ROLE_SOURCE,                    /**< Power source */
    CY_PD_PRT_DUAL                            /**< Dual Role Power device: can be source or sink. */
} cy_en_pd_port_role_t;

/**
 * @typedef cy_en_pd_port_type_t
 * @brief Enum of the PD port types.
 */
typedef enum
{
    CY_PD_PRT_TYPE_UFP = 0,                   /**< Upstream facing port. USB device or Alternate mode accessory. */
    CY_PD_PRT_TYPE_DFP,                       /**< Downstream facing port. USB host or Alternate mode controller. */
    CY_PD_PRT_TYPE_DRP                        /**< Dual Role data device: can be UFP or DFP. */
} cy_en_pd_port_type_t;

/**
 * @brief Enumeration of the PD spec revisions.
 */
typedef enum
{
    CY_PD_REV1 = 0,                        /**< USB-PD spec revision 1.0. Not supported. */
    CY_PD_REV2,                            /**< USB-PD spec revision 2.0. */
    CY_PD_REV3,                            /**< USB-PD spec revision 3.0. */
    CY_PD_REV_RSVD                         /**< Undefined USB-PD spec revision. */
} cy_en_pd_pd_rev_t;

/**
 *
 * @brief Enum of the attached device type.
 */
typedef enum
{
    CY_PD_DEV_SNK = 1,                        /**< Power sink device is attached. */
    CY_PD_DEV_SRC,                            /**< Power source device is attached. */
    CY_PD_DEV_DBG_ACC,                        /**< Debug accessory is attached. */
    CY_PD_DEV_RA_RA,                          /**< RA_RA is attached. */
    CY_PD_DEV_PWRD_ACC,                       /**< Powered accessory is attached. */
    CY_PD_DEV_VPD,                            /**< Vconn powered device is attached. */
    CY_PD_DEV_UNSUPORTED_ACC                  /**< Unsupported device type is attached. */
} cy_en_pd_devtype_t;

/**
 * @brief Enum of the control message types.
 */
typedef enum
{
    CY_PD_CTRL_MSG_RSRVD = 0UL,                /**< 0x00: Reserved message code. */
    CY_PD_CTRL_MSG_GOOD_CRC = 1UL,             /**< 0x01: GoodCRC message. */
    CY_PD_CTRL_MSG_GO_TO_MIN = 2UL,            /**< 0x02: GotoMin message. */
    CY_PD_CTRL_MSG_ACCEPT = 3UL,               /**< 0x03: Accept message. */
    CY_PD_CTRL_MSG_REJECT = 4UL,               /**< 0x04: Reject message. */
    CY_PD_CTRL_MSG_PING = 5UL,                 /**< 0x05: Ping message. */
    CY_PD_CTRL_MSG_PS_RDY = 6UL,               /**< 0x06: PS_RDY message. */
    CY_PD_CTRL_MSG_GET_SOURCE_CAP = 7UL,       /**< 0x07: Get_Source_Cap message. */
    CY_PD_CTRL_MSG_GET_SINK_CAP = 8UL,         /**< 0x08: Get_Sink_Cap message. */
    CY_PD_CTRL_MSG_DR_SWAP = 9UL,              /**< 0x09: DR_Swap message. */
    CY_PD_CTRL_MSG_PR_SWAP = 10UL,             /**< 0x0A: PR_Swap message. */
    CY_PD_CTRL_MSG_VCONN_SWAP = 11UL,          /**< 0x0B: VCONN_Swap message. */
    CY_PD_CTRL_MSG_WAIT = 12UL,                /**< 0x0C: Wait message. */
    CY_PD_CTRL_MSG_SOFT_RESET = 13UL,          /**< 0x0D: Soft_Reset message. */
    CY_PD_CTRL_MSG_DATA_RESET = 14UL,          /**< 0x0E: Data_Reset message. */
    CY_PD_CTRL_MSG_DATA_RESET_COMPLETE = 15UL, /**< 0x0F: Data_Reset_Complete message. */
    CY_PD_CTRL_MSG_NOT_SUPPORTED = 16UL,       /**< 0x10: Not_Supported message. */
    CY_PD_CTRL_MSG_GET_SRC_CAP_EXTD = 17UL,    /**< 0x11: Get_Source_Cap_Extended message. */
    CY_PD_CTRL_MSG_GET_STATUS = 18UL,          /**< 0x12: Get_Status message . */
    CY_PD_CTRL_MSG_FR_SWAP = 19UL,             /**< 0x13: FR_Swap message. */
    CY_PD_CTRL_MSG_GET_PPS_STATUS = 20UL,      /**< 0x14: Get_PPS_Status message. */
    CY_PD_CTRL_MSG_GET_COUNTRY_CODES = 21UL,   /**< 0x15: Get_Country_Codes message. */
    CY_PD_CTRL_MSG_GET_SNK_CAP_EXTD = 22UL,    /**< 0x16: Get_Sink_Cap_Extended message. */
    CY_PD_CTRL_MSG_GET_SOURCE_INFO = 23UL,     /**< 0x17: Get_Source_Info message. */
    CY_PD_CTRL_MSG_GET_REVISION = 24UL          /**< 0x18: Get_Revision message. */
} cy_en_pd_ctrl_msg_t;

/**
 * @brief Enum of the Rp status when Rp is asserted.
 */
typedef enum
{
    CY_PD_RP_RA = 0UL,                         /**< PMG1 has applied Rp. External Ra present.  */
    CY_PD_RP_RD = 1UL,                         /**< PMG1 has applied Rp. External Rd present.  */
    CY_PD_RP_OPEN = 2UL,                       /**< PMG1 has applied Rp. No external pulldown. */
} cy_en_pd_rp_cc_status_t;

/**
 * @brief Enum of the Rd status when Rd is asserted.
 */
typedef enum
{
    CY_PD_RD_RA = 0UL,                         /**< PMG1 has applied Rd. No external Rp. */
    CY_PD_RD_USB = 1UL,                        /**< PMG1 has applied Rd. Default Rp present. */
    CY_PD_RD_1_5A = 2UL,                       /**< PMG1 has applied Rd. 1.5A Rp present. */
    CY_PD_RD_3A = 3UL,                         /**< PMG1 has applied Rd. 3A Rp present. */
    CY_PD_RD_ERR = 4UL                         /**< PMG1 has applied Rd. Error state. */
} cy_en_pd_rd_cc_status_t;

/**
 * @brief Enum of the CC termination current levels.
 */
typedef enum
{
    CY_PD_RP_TERM_RP_CUR_DEF = 0UL,            /**< Use default Rp. */
    CY_PD_RP_TERM_RP_CUR_1_5A = 1UL,           /**< Use 1.5 A Rp. */
    CY_PD_RP_TERM_RP_CUR_3A = 2UL              /**< Use 3A Rp. */
} cy_en_pd_rp_term_t;


/** PD Type C Driver Events */
typedef enum {
    CY_PD_TYPEC_EVT_UNATTACHED_SRC = 0,  /**< Transition to Unattached.SRC state. */
    CY_PD_TYPEC_EVT_UNATTACHED_SNK,      /**< Transition to Unattached.SNK state. */
    CY_PD_TYPEC_EVT_STOP_FSM,            /**< Stop the Type C State machine. */
} cy_en_pd_typec_events_t;

/** Types of extended alert events. */
typedef enum
{
    CY_PD_EXTD_ALERT_TYPE_PWR_STATE_CHANGE = 1UL,  /**< Power state change (DFP only). */
    CY_PD_EXTD_ALERT_TYPE_PWR_BTN_PRESS = 2UL,     /**< Power button press (UFP only). */
    CY_PD_EXTD_ALERT_TYPE_PWR_BTN_RELEASE = 3UL,   /**< Power button release (UFP only). */
    CY_PD_EXTD_ALERT_TYPE_CTRLR_WAKE = 4UL,        /**< Controller initiated wake (UFP only). */
} cy_en_pd_extd_alert_type_t;

/** \} group_usbpd_common_enums */

/*******************************************************************************
*                              Type Definitions
*******************************************************************************/

/**
* \addtogroup group_usbpd_common_data_structures
* \{
*/

/** Union to hold the PD header defined by the USB-PD specification. Lower 16 bits hold the message
 * header and the upper 16 bits hold the extended message header (where applicable). */
typedef union
{
    uint32_t val;                               /**< Header expressed as a 32-bit word. */

    /** @brief PD message header broken down into component fields. Includes 2-byte extended message header. */
    struct PD_HDR
    {
        uint32_t msgType   : 5;                /**< Bits 04:00 - Message type. */
        uint32_t dataRole  : 1;                /**< Bit     05 - Data role. */
        uint32_t specRev   : 2;                /**< Bits 07:06 - Spec revision. */
        uint32_t pwrRole   : 1;                /**< Bit     08 - Power role. */
        uint32_t msgId     : 3;                /**< Bits 11:09 - Message ID. */
        uint32_t len       : 3;                /**< Bits 14:12 - Number of data objects. */
        uint32_t extd      : 1;                /**< Bit     15 - Extended message. */
        uint32_t dataSize  : 9;                /**< Bits 24:16 - Extended message size in bytes. */
        uint32_t rsvd1     : 1;                /**< Bit     25 - Reserved. */
        uint32_t request   : 1;                /**< Bit     26 - Chunk request. */
        uint32_t chunkNum  : 4;                /**< Bits 30:27 - Chunk number. */
        uint32_t chunked   : 1;                /**< Bit     31 - Chunked message. */
    } hdr;                                     /**< PD message header split into component fields. */
} cy_pd_pd_hdr_t;

/**
 * Union to hold a PD data object. All USB-PD data objects are 4-byte values which are interpreted
 * according to the message type, length and object position. This union represents all possible interpretations
 * of a USB-PD data object.
 */
typedef union
{
    uint32_t val;                                   /**< Data object interpreted as an unsigned integer value. */

    /** @brief Structure of a BIST data object. */
    struct BIST_DO
    {
        uint32_t rsvd1                      : 16;   /**< Reserved field. */
        uint32_t rsvd2                      : 12;   /**< Reserved field. */
        uint32_t mode                       : 4;    /**< BIST mode. */
    } bist_do;                                      /**< DO interpreted as a BIST data object. */

    /** @brief Structure representing a Fixed Supply PDO - Source. */
    struct FIXED_SRC
    {
        uint32_t maxCurrent               : 10;     /**< Maximum current in 100mA units. */
        uint32_t voltage                  : 10;     /**< Voltage in 50mV units. */
        uint32_t pkCurrent                : 2;      /**< Peak current. */
#if CY_PD_EPR_ENABLE
        uint32_t rsrvd                    : 1;      /**< Reserved field. */
        uint32_t eprModeCapable           : 1;      /**< EPR mode capable. */
#else
        uint32_t rsrvd                    : 2;      /**< Reserved field. */
#endif /* CY_PD_EPR_ENABLE */
        uint32_t unchunkSup               : 1;      /**< Unchunked extended messages supported. */
        uint32_t drSwap                   : 1;      /**< Data Role Swap supported. */
        uint32_t usbCommCap               : 1;      /**< USB communication capability. */
        uint32_t extPowered               : 1;      /**< Externally powered. */
        uint32_t usbSuspendSup            : 1;      /**< USB suspend supported. */
        uint32_t dualRolePower            : 1;      /**< Dual role power support. */
        uint32_t supplyType               : 2;      /**< Supply type - should be 'b00. */
    } fixed_src;                                    /**< DO interpreted as a Fixed Supply PDO - Source. */

    /** @brief Structure representing a Variable Supply PDO - Source. */
    struct VAR_SRC
    {
        uint32_t maxCurrent                : 10;   /**< Maximum current in 10mA units. */
        uint32_t minVoltage                : 10;   /**< Minimum voltage in 50mV units. */
        uint32_t maxVoltage                : 10;   /**< Maximum voltage in 50mV units. */
        uint32_t supplyType                : 2;    /**< Supply type - should be 'b10. */
    } var_src;                                      /**< DO interpreted as a Variable Supply PDO - Source. */

    /** @brief Structure representing a Battery Supply PDO - Source. */
    struct BAT_SRC
    {
        uint32_t maxPower                  : 10;   /**< Maximum power in 250mW units. */
        uint32_t minVoltage                : 10;   /**< Minimum voltage in 50mV units. */
        uint32_t maxVoltage                : 10;   /**< Maximum voltage in 50mV units. */
        uint32_t supplyType                : 2;    /**< Supply type - should be 'b01. */
    } bat_src;                                      /**< DO interpreted as a Battery Supply PDO - Source. */

    /** @brief Structure representing a generic source PDO. */
    struct SRC_GEN
    {
        uint32_t maxCurPower               : 10;   /**< Maximum current in 10 mA or power in 250 mW units. */
        uint32_t minVoltage                : 10;   /**< Minimum voltage in 50mV units. */
        uint32_t maxVoltage                : 10;   /**< Maximum voltage in 50mV units. */
        uint32_t supplyType                : 2;    /**< Supply type. */
    } src_gen;                                      /**< DO interpreted as a generic PDO - Source. */

    /** @brief Structure representing a Fixed Supply PDO - Sink. */
    struct FIXED_SNK
    {
        uint32_t opCurrent                  : 10;   /**< Operational current in 10mA units. */
        uint32_t voltage                    : 10;   /**< Voltage in 50mV units. */
        uint32_t rsrvd                      : 3;    /**< Reserved field. */
        uint32_t frSwap                     : 2;    /**< FR swap support. */
        uint32_t drSwap                     : 1;    /**< Data Role Swap supported. */
        uint32_t usbCommCap                 : 1;    /**< USB communication capability. */
        uint32_t extPowered                 : 1;    /**< Externally powered. */
        uint32_t highCap                    : 1;    /**< Higher capability possible. */
        uint32_t dualRolePower              : 1;    /**< Dual role power support. */
        uint32_t supplyType                 : 2;    /**< Supply type - should be 'b00. */
    } fixed_snk;                                    /**< DO interpreted as a Fixed Supply PDO - Sink. */

    /** @brief Structure representing a Variable Supply PDO - Sink. */
    struct VAR_SNK
    {
        uint32_t opCurrent                  : 10;   /**< Operational current in 10mA units. */
        uint32_t minVoltage                 : 10;   /**< Minimum voltage in 50mV units. */
        uint32_t maxVoltage                 : 10;   /**< Maximum voltage in 50mV units. */
        uint32_t supplyType                 : 2;    /**< Supply type - should be 'b10. */
    } var_snk;                                      /**< DO interpreted as a Variable Supply PDO - Sink. */

    /** @brief Structure representing a Battery Supply PDO - Sink. */
    struct BAT_SNK
    {
        uint32_t opPower                    : 10;   /**< Maximum power in 250mW units. */
        uint32_t minVoltage                 : 10;   /**< Minimum voltage in 50mV units. */
        uint32_t maxVoltage                 : 10;   /**< Maximum voltage in 50mV units. */
        uint32_t supplyType                 : 2;    /**< Supply type - should be 'b01. */
    } bat_snk;                                      /**< DO interpreted as a Battery Supply PDO - Sink. */

    /** @brief Structure representing a Fixed or Variable Request Data Object. */
    struct RDO_FIXED_VAR
    {
        uint32_t maxOpCurrent               : 10;   /**< Maximum operating current in 10mA units. */
        uint32_t opCurrent                  : 10;   /**< Operating current in 10mA units. */
#if CY_PD_EPR_ENABLE
        uint32_t rsrvd1                     : 2;    /**< Reserved field. */
        uint32_t eprModeCapable             : 1;    /**< EPR mode capable. */
#else
        uint32_t rsrvd1                     : 3;    /**< Reserved field. */
#endif /* CY_PD_EPR_ENABLE */
        uint32_t unchunkSup                 : 1;    /**< Unchunked extended messages supported. */
        uint32_t noUsbSuspend               : 1;    /**< No USB suspend. */
        uint32_t usbCommCap                 : 1;    /**< USB communication capability. */
        uint32_t capMismatch                : 1;    /**< Capability mismatch. */
        uint32_t giveBackFlag               : 1;    /**< GiveBack flag = 0. */
#if CY_PD_REV3_ENABLE
#if CY_PD_EPR_ENABLE
        uint32_t objPos                     : 3;    /**< Object position. */
        uint32_t eprPdo                     : 1;    /**< used in EPR_Request message for EPR objects. */
#else
        uint32_t objPos                     : 3;    /**< Object position. */
        uint32_t rsrvd2                     : 1;    /**< Reserved field. */
#endif /* CY_PD_EPR_ENABLE */
#else
        uint32_t objPos                     : 3;    /**< Object position. */
        uint32_t rsrvd2                     : 1;    /**< Reserved field. */
#endif /* CY_PD_REV3_ENABLE */
    } rdo_fix_var;                                  /**< DO interpreted as a fixed/variable request. */

    /** @brief Structure representing a Fixed or Variable Request Data Object with GiveBack. */
    struct RDO_FIXED_VAR_GIVEBACK
    {
        uint32_t minOpCurrent               : 10;   /**< Minimum operating current in 10mA units. */
        uint32_t opCurrent                  : 10;   /**< Operating current in 10mA units. */
        uint32_t rsrvd1                     : 3;    /**< Reserved field. */
        uint32_t unchunkSup                 : 1;    /**< Unchunked extended messages supported. */
        uint32_t noUsbSuspend               : 1;    /**< No USB suspend. */
        uint32_t usbCommCap                 : 1;    /**< USB communication capability. */
        uint32_t capMismatch                : 1;    /**< Capability mismatch. */
        uint32_t giveBackFlag               : 1;    /**< GiveBack flag = 1. */
#if CY_PD_REV3_ENABLE
        uint32_t objPos                     : 4;    /**< Object position. */
#else
        uint32_t objPos                     : 3;    /**< Object position. */
        uint32_t rsrvd2                     : 1;    /**< Reserved field. */
#endif /* CY_PD_REV3_ENABLE */
    } rdo_fix_var_gvb;                              /**< DO interpreted as a fixed/variable request with giveback. */

    /** @brief Structure representing a Battery Request Data Object. */
    struct RDO_BAT
    {
        uint32_t maxOpPower                 : 10;   /**< Maximum operating power in 250mW units. */
        uint32_t opPower                    : 10;   /**< Operating power in 250mW units. */
        uint32_t rsrvd1                     : 3;    /**< Reserved field. */
        uint32_t unchunkSup                 : 1;    /**< Unchunked extended messages supported. */
        uint32_t noUsbSuspend               : 1;    /**< No USB suspend. */
        uint32_t usbCommCap                 : 1;    /**< USB communication capability. */
        uint32_t capMismatch                : 1;    /**< Capability mismatch. */
        uint32_t giveBackFlag               : 1;    /**< GiveBack flag = 0. */
#if CY_PD_REV3_ENABLE
        uint32_t objPos                     : 4;    /**< Object position. */
#else        
        uint32_t objPos                     : 3;    /**< Object position. */
        uint32_t rsrvd2                     : 1;    /**< Reserved field. */
#endif /* CY_PD_REV3_ENABLE */
    } rdo_bat;                                      /**< DO interpreted as a Battery request. */

    /** @brief Structure representing a Battery Request Data Object with GiveBack. */
    struct RDO_BAT_GIVEBACK
    {
        uint32_t minOpPower                 : 10;   /**< Minimum operating power in 250mW units. */
        uint32_t opPower                    : 10;   /**< Operating power in 250mW units. */
        uint32_t rsrvd1                     : 3;    /**< Reserved field. */
        uint32_t unchunkSup                 : 1;    /**< Unchunked extended messages supported. */
        uint32_t noUsbSuspend               : 1;    /**< No USB suspend. */
        uint32_t usbCommCap                 : 1;    /**< USB communication capability. */
        uint32_t capMismatch                : 1;    /**< Capability mismatch. */
        uint32_t giveBackFlag               : 1;    /**< GiveBack flag = 1. */
#if CY_PD_REV3_ENABLE
        uint32_t objPos                     : 4;    /**< Object position. */
#else        
        uint32_t objPos                     : 3;    /**< Object position. */
        uint32_t rsrvd2                     : 1;    /**< Reserved field. */
#endif /* CY_PD_REV3_ENABLE */
    } rdo_bat_gvb;                                  /**< DO interpreted as a Battery request with giveback. */

    /** @brief Structure representing a generic Request Data Object. */
    struct RDO_GEN
    {
        uint32_t minMaxPowerCur             : 10;   /**< Min/Max power or current requirement. */
        uint32_t opPowerCur                 : 10;   /**< Operating power or current requirement. */
#if CY_PD_EPR_ENABLE
        uint32_t rsrvd1                     : 2;    /**< Reserved field. */
        uint32_t eprModeCapable             : 1;    /**< EPR mode capable. */
#else
        uint32_t rsrvd1                     : 3;    /**< Reserved field. */
#endif /* CY_PD_EPR_ENABLE */
        uint32_t unchunkSup                 : 1;    /**< Unchunked extended messages supported. */
        uint32_t noUsbSuspend               : 1;    /**< No USB suspend. */
        uint32_t usbCommCap                 : 1;    /**< USB communication capability. */
        uint32_t capMismatch                : 1;    /**< Capability mismatch. */
        uint32_t giveBackFlag               : 1;    /**< GiveBack supported flag = 0. */
#if CY_PD_REV3_ENABLE
        uint32_t objPos                     : 3;    /**< Object position. */
        uint32_t eprPdo                     : 1;    /**< used in EPR_Request message for EPR objects. */
#else
        uint32_t objPos                     : 3;    /**< Object position. */
        uint32_t rsrvd2                     : 1;    /**< Reserved field. */
#endif /* CY_PD_REV3_ENABLE */
    } rdo_gen;                                      /**< DO interpreted as a generic request message. */

    /** @brief Structure representing a Generic Request Data Object with GiveBack. */
    struct RDO_GEN_GVB
    {
        uint32_t maxPowerCur                : 10;   /**< Min/Max power or current requirement. */
        uint32_t opPowerCur                 : 10;   /**< Operating power or current requirement. */
        uint32_t rsrvd1                     : 3;    /**< Reserved field. */
        uint32_t unchunkSup                 : 1;    /**< Unchunked extended messages supported. */
        uint32_t noUsbSuspend               : 1;    /**< No USB suspend. */
        uint32_t usbCommCap                 : 1;    /**< USB communication capability. */
        uint32_t capMismatch                : 1;    /**< Capability mismatch. */
        uint32_t giveBackFlag               : 1;    /**< GiveBack supported flag = 1. */
#if CY_PD_REV3_ENABLE
        uint32_t objPos                     : 4;    /**< Object position. */
#else        
        uint32_t objPos                     : 3;    /**< Object position. */
        uint32_t rsrvd2                     : 1;    /**< Reserved field. */
#endif /* CY_PD_REV3_ENABLE */
    } rdo_gen_gvb;                                  /**< DO interpreted as a generic request with giveback. */

    /** @brief Structure representing a Structured VDM Header Data Object. */
    struct STD_VDM_HDR
    {
        uint32_t cmd                        : 5;    /**< VDM command id. */
        uint32_t rsvd1                      : 1;    /**< Reserved field. */
        uint32_t cmdType                    : 2;    /**< VDM command type. */
        uint32_t objPos                     : 3;    /**< Object position. */
        uint32_t stMinVer                   : 2;    /**< Structured VDM version (Minor). */
        uint32_t stVer                      : 2;    /**< Structured VDM version (Major). */
        uint32_t vdmType                    : 1;    /**< VDM type = Structured. */
        uint32_t svid                       : 16;   /**< SVID associated with VDM. */
    } std_vdm_hdr;                                  /**< DO interpreted as a Structured VDM header. */

    /** @brief Structure representing an Unstructured VDM header data object as defined by Infineon. */
    struct USTD_VDM_HDR
    {
        uint32_t cmd                        : 5;    /**< Command id. */
        uint32_t seqNum                     : 4;    /**< Sequence number. */
        uint32_t rsvd1                      : 2;    /**< Reserved field. */
        uint32_t cmdType                    : 2;    /**< Command type. */
        uint32_t vdmVer                     : 2;    /**< VDM version. */
        uint32_t vdmType                    : 1;    /**< VDM type = Unstructured. */
        uint32_t svid                       : 16;   /**< SVID associated with VDM. */
    } ustd_vdm_hdr;                                 /**< DO interpreted as a Infineon unstructured VDM header. */

    /** @brief Structure representing an Unstructured VDM header data object as defined by QC 5.0/4.0 spec. */
    struct USTD_QC_PPS_HDR
    {
        uint32_t cmd0                      : 8;    /**< Command code #0. */
        uint32_t cmd1                      : 7;    /**< Command code #1. */
        uint32_t vdmType                   : 1;    /**< VDM type = Unstructured. */
        uint32_t svid                      : 16;   /**< SVID associated with message. */
    } ustd_qc_pps_hdr;                             /**< DO interpreted as a QC 5.0/4.0 Unstructured VDM header. */

    /** @brief Structure representing an Unstructured VDM data object as defined by QC 5.0/4.0 spec. */
    struct QC_PPS_DATA_VDO
    {
        uint32_t data0                     : 8;    /**< Command data #0. */
        uint32_t data1                     : 8;    /**< Command data #1. */
        uint32_t data2                     : 8;    /**< Command data #2. */
        uint32_t data3                     : 8;    /**< Command data #3. */
    } qc_pps_data_vdo;                              /**< DO interpreted as a QC 5.0/4.0 Unstructured VDM data object. */

    /** @brief Structure representing a Standard ID_HEADER VDO. */
    struct STD_VDM_ID_HDR
    {
        uint32_t usbVid                     : 16;   /**< 16-bit vendor ID. */
#if CY_PD_REV3_ENABLE
        uint32_t rsvd1                      : 5;    /**< Reserved field. */
        uint32_t connType                   : 2;    /**< Connector type. */
        uint32_t prodTypeDfp                : 3;    /**< Product type as DFP. */
#else
        uint32_t rsvd1                      : 10;   /**< Reserved field. */
#endif /* CY_PD_REV3_ENABLE */
        uint32_t modSupport                 : 1;    /**< Whether alternate modes are supported. */
        uint32_t prodType                   : 3;    /**< Product type as UFP. */
        uint32_t usbDev                     : 1;    /**< USB device supported. */
        uint32_t usbHost                    : 1;    /**< USB host supported. */
    } std_id_hdr;                                   /**< DO interpreted as a Standard ID_HEADER VDO. */

    /** @brief Cert Stat VDO structure. */
    struct STD_CERT_VDO
    {
        uint32_t usbXid                     : 32;   /**< 32-bit XID value. */
    } std_cert_vdo;                                 /**< DO interpreted as a Cert Stat VDO. */

    /** @brief Product VDO structure. */
    struct STD_PROD_VDO
    {
        uint32_t bcdDev                     : 16;   /**< 16-bit bcdDevice value. */
        uint32_t usbPid                     : 16;   /**< 16-bit product ID. */
    } std_prod_vdo;                                 /**< DO interpreted as a Product VDO. */

    /** @brief Cable VDO structure as defined in USB-PD r2.0. */
    struct STD_CBL_VDO
    {
        uint32_t usbSsSup                   : 3;    /**< USB signalling supported by the cable. */
        uint32_t sopDp                      : 1;    /**< Whether SOP'' controller is present. */
        uint32_t vbusThruCbl                : 1;    /**< Whether cable allows VBus power through. */
        uint32_t vbusCur                    : 2;    /**< VBus current supported by the cable. */
        uint32_t ssrx2                      : 1;    /**< Whether SSRX2 has configurable direction. */
        uint32_t ssrx1                      : 1;    /**< Whether SSRX1 has configurable direction. */
        uint32_t sstx2                      : 1;    /**< Whether SSTX2 has configurable direction. */
        uint32_t sstx1                      : 1;    /**< Whether SSTX1 has configurable direction. */
        uint32_t cblTerm                    : 2;    /**< Cable termination and VConn power requirement. */
        uint32_t cblLatency                 : 4;    /**< Cable latency. */
        uint32_t typecPlug                  : 1;    /**< Whether cable has a plug: Should be 0. */
        uint32_t typecAbc                   : 2;    /**< Cable plug type. */
        uint32_t rsvd1                      : 4;    /**< Reserved field. */
        uint32_t cblFwVer                   : 4;    /**< Cable firmware version. */
        uint32_t cblHwVer                   : 4;    /**< Cable hardware version. */
    } std_cbl_vdo;                                  /**< DO interpreted as a PD 2.0 cable VDO. */

    /** @brief Passive cable VDO structure as defined by PD 3.0. */
    struct PAS_CBL_VDO
    {
        uint32_t usbSsSup                   : 3;    /**< USB signalling supported by the cable. */
        uint32_t rsvd1                      : 2;    /**< Reserved field. */
        uint32_t vbusCur                    : 2;    /**< VBus current supported by the cable. */
        uint32_t rsvd2                      : 2;    /**< Reserved field. */
        uint32_t maxVbusVolt                : 2;    /**< Max. VBus voltage supported. */
        uint32_t cblTerm                    : 2;    /**< Cable termination and VConn power requirement. */
        uint32_t cblLatency                 : 4;    /**< Cable latency. */
#if CY_PD_EPR_ENABLE
        uint32_t eprModeCapable             : 1;    /**< EPR mode capable. */
#else
        uint32_t typecPlug                  : 1;    /**< Reserved field. */
#endif /* CY_PD_EPR_ENABLE */
        uint32_t typecAbc                   : 2;    /**< Cable plug type. */
        uint32_t rsvd3                      : 1;    /**< Reserved field. */
        uint32_t vdoVersion                 : 3;    /**< VDO version. */
        uint32_t cblFwVer                   : 4;    /**< Cable firmware version. */
        uint32_t cblHwVer                   : 4;    /**< Cable hardware version. */
    } pas_cbl_vdo;                                  /**< DO interpreted as a PD 3.0 passive cable VDO. */

    /** @brief Active cable VDO structure as defined by PD 3.0. */
    struct ACT_CBL_VDO
    {
        uint32_t usbSsSup                   : 3;    /**< USB signalling supported by the cable. */
        uint32_t sopDp                      : 1;    /**< Whether SOP'' controller is present. */
        uint32_t vbusThruCbl                : 1;    /**< Whether cable conducts VBus through. */
        uint32_t vbusCur                    : 2;    /**< VBus current supported by the cable. */
        uint32_t rsvd1                      : 2;    /**< Reserved field. */
        uint32_t maxVbusVolt                : 2;    /**< Max. VBus voltage supported. */
        uint32_t cblTerm                    : 2;    /**< Cable termination and VConn power requirement. */
        uint32_t cblLatency                 : 4;    /**< Cable latency. */
        uint32_t typecPlug                  : 1;    /**< Reserved field. */
        uint32_t typecAbc                   : 2;    /**< Cable plug type. */
        uint32_t rsvd2                      : 1;    /**< Reserved field. */
        uint32_t vdoVersion                 : 3;    /**< VDO version. */
        uint32_t cblFwVer                   : 4;    /**< Cable firmware version. */
        uint32_t cblHwVer                   : 4;    /**< Cable hardware version. */
    } act_cbl_vdo;                                  /**< DO interpreted as a PD 3.0 active cable VDO. */

    /** @brief Active Cable VDO 1 structure as defined by PD 3.0, Version 1.6 */
    struct ACT_CBL_VDO_1
    {
        uint32_t usbSsSup                   : 3;    /**< USB signalling supported by the cable. */
        uint32_t sopDp                      : 1;    /**< Whether SOP'' controller is present. */
        uint32_t vbusThruCbl                : 1;    /**< Whether cable conducts VBus through. */
        uint32_t vbusCur                    : 2;    /**< VBus current supported by the cable. */
        uint32_t sbu_type                   : 1;    /**< Whether SBU connections are passive/active. */
        uint32_t sbu_supp                   : 1;    /**< Whether SBU connections are supported, 1=Not supported. */
        uint32_t maxVbusVolt                : 2;    /**< Max. VBus voltage supported. */
        uint32_t cblTerm                    : 2;    /**< Cable termination and VConn power requirement. */
        uint32_t cblLatency                 : 4;    /**< Cable latency. */
        uint32_t eprModeCapable             : 1;    /**< EPR mode capable. */
        uint32_t typecAbc                   : 2;    /**< Cable plug type. */
        uint32_t rsvd2                      : 1;    /**< Reserved field. */
        uint32_t vdoVersion                 : 3;    /**< VDO version. */
        uint32_t cblFwVer                   : 4;    /**< Cable firmware version. */
        uint32_t cblHwVer                   : 4;    /**< Cable hardware version. */
    } act_cbl_vdo1;                                 /**< DO interpreted as a PD 3.0 Active Cable VDO 1. */

    /** @brief Active Cable VDO 2 structure as defined by PD 3.0, Version 1.6 */
    struct ACT_CBL_VDO_2
    {
        uint32_t usbGen                     : 1;    /**< USB Generation. */
        uint32_t usb4AsymSupp               : 1;    /**< Whether cable supports USB4 asymmetric mode. */
        uint32_t optIsolated                : 1;    /**< Optically Isolated Active Cable. */
        uint32_t ssLanes                    : 1;    /**< Whether cable supports 1 or 2 USB 3.2 lanes. */
        uint32_t ssSupp                     : 1;    /**< Whether cable supports USB 3.2 signaling. */
        uint32_t usb2Supp                   : 1;    /**< Whether cable supports USB 2.0 data. */
        uint32_t usb2HubHops                : 2;    /**< Number of USB 2.0 hub hops contributed by the cable. */
        uint32_t usb4Supp                   : 1;    /**< Whether cable supports USB 4. */
        uint32_t activeEl                   : 1;    /**< Active element. */
        uint32_t phyConn                    : 1;    /**< Physical connection. */
        uint32_t u3U0Trans                  : 1;    /**< Type of USB U3 to U0 transition. */
        uint32_t u3Power                    : 3;    /**< USB 3.2 U3 power. */
        uint32_t rsvd1                      : 1;    /**< Reserved field. */
        uint32_t shutdownTemp               : 8;    /**< Shutdown temperature. */
        uint32_t maxOpTemp                  : 8;    /**< Maximum operating temperature. */
    } act_cbl_vdo2;                                 /**< DO interpreted as a PD 3.0 Active Cable VDO 2. */

    /** @brief AMA VDO structure as defined by PD 2.0. */
    struct STD_AMA_VDO
    {
        uint32_t usbSsSup                   : 3;    /**< USB signalling supported. */
        uint32_t vbusReq                    : 1;    /**< Whether device requires VBus. */
        uint32_t vconReq                    : 1;    /**< Whether device requires VConn. */
        uint32_t vconPwr                    : 3;    /**< VConn power required. */
        uint32_t ssrx2                      : 1;    /**< Whether SSRX2 has configurable direction. */
        uint32_t ssrx1                      : 1;    /**< Whether SSRX1 has configurable direction. */
        uint32_t sstx2                      : 1;    /**< Whether SSTX2 has configurable direction. */
        uint32_t sstx1                      : 1;    /**< Whether SSTX1 has configurable direction. */
        uint32_t rsvd1                      : 12;   /**< Reserved field. */
        uint32_t amaFwVer                   : 4;    /**< AMA firmware version. */
        uint32_t amaHwVer                   : 4;    /**< AMA hardware version. */
    } std_ama_vdo;                                  /**< DO interpreted as a PD 2.0 AMA VDO. */

    /** @brief AMA VDO structure as defined by PD 3.0. */
    struct STD_AMA_VDO_PD3
    {
        uint32_t usbSsSup                   : 3;    /**< USB signalling supported. */
        uint32_t vbusReq                    : 1;    /**< Whether device requires VBus. */
        uint32_t vconReq                    : 1;    /**< Whether device requires VConn. */
        uint32_t vconPwr                    : 3;    /**< VConn power required. */
        uint32_t rsvd1                      : 13;   /**< Reserved field. */
        uint32_t vdoVersion                 : 3;    /**< VDO version. */
        uint32_t amaFwVer                   : 4;    /**< AMA firmware version. */
        uint32_t amaHwVer                   : 4;    /**< AMA hardware version. */
    } std_ama_vdo_pd3;                              /**< DO interpreted as a PD 3.0 AMA VDO. */

    /** @brief Discover_SVID response structure. */
    struct CY_PD_STD_SVID_RESP_VDO
    {
        uint32_t svidN1                     : 16;   /**< SVID #1 */
        uint32_t svidN                      : 16;   /**< SVID #2 */
    } std_svid_res;                                 /**< DO interpreted as a DISCOVER_SVID response. */

    /** @brief DisplayPort Mode VDO as defined by VESA spec. */
    struct STD_DP_VDO
    {
        uint32_t portCap                    : 2;    /**< Port capability. */
        uint32_t signal                     : 4;    /**< Signalling supported. */
        uint32_t recep                      : 1;    /**< Whether Type-C connector is plug or receptacle. */
        uint32_t usb20                      : 1;    /**< USB 2.0 signalling required. */
        uint32_t dfpDPin                    : 8;    /**< DFP_D pin assignments supported. */
        uint32_t ufpDPin                    : 8;    /**< UFP_D pin assignments supported. */
        uint32_t rsvd                       : 6;    /**< Reserved field. */
        uint32_t dpAmVersion                : 2;    /**< DP alt mode version. */
    } std_dp_vdo;                                 /**< DO interpreted as a DisplayPort Mode response. */

    /** @brief DisplayPort Mode Cable VDO as defined by VESA spec. */
    struct DP_CBL_VDO
    {
        uint32_t rsvd1                      : 2;    /**< Reserved field. */
        uint32_t signal                     : 4;    /**< Signalling supported. */
        uint32_t rsvd2                      : 2;    /**< Reserved field. */
        uint32_t dfpDPin                    : 8;    /**< DFP_D pin assignments supported. */
        uint32_t ufpDPin                    : 8;    /**< UFP_D pin assignments supported. */
        uint32_t rsvd3                      : 2;    /**< Reserved field. */
        uint32_t uhbr13CblSupp              : 1;    /**< Cable UHBR13 Support. */
        uint32_t rsvd4                      : 1;    /**< Reserved field. */
        uint32_t actComp                    : 2;    /**< Cable active component. */
        uint32_t dpAmVersion                : 2;    /**< DP alt mode version. */
    } dp_cbl_vdo;                                  /**< DO interpreted as a DisplayPort Mode response. */

    /** @brief DisplayPort status update VDO as defined by VESA spec. */
    struct DP_STATUS_VDO
    {
        uint32_t dfpUfpConn                 : 2;    /**< Whether DFP_D/UFP_D is connected. */
        uint32_t pwrLow                     : 1;    /**< Low power mode. */
        uint32_t en                         : 1;    /**< DP functionality enabled. */
        uint32_t multFun                    : 1;    /**< Multi-function mode preferred. */
        uint32_t usbCfg                     : 1;    /**< Request switch to USB configuration. */
        uint32_t exit                       : 1;    /**< Exit DP mode request. */
        uint32_t hpdState                   : 1;    /**< Current HPD state. */
        uint32_t hpdIrq                     : 1;    /**< HPD IRQ status. */
        uint32_t noDpSuspend                : 1;    /**< Device has/not preference for entry into low power state. */
        uint32_t rsvd                       : 22;   /**< Reserved field. */
    } dp_stat_vdo;                                  /**< DO interpreted as a DisplayPort status update. */

    /** @brief DisplayPort configure VDO as defined by VESA spec. */
    struct DP_CONFIG_VDO
    {
        uint32_t selConf                    : 2;    /**< Select configuration. */
        uint32_t sign                       : 4;    /**< Signalling for DP protocol. */
        uint32_t rsvd1                      : 2;    /**< Reserved. */
        uint32_t dfpAsgmnt                  : 8;    /**< DFP_D pin assignment or DP2.1 assignment. */
        uint32_t ufpAsgmnt                  : 8;    /**< UFP_D pin assignment. */
        uint32_t rsvd2                      : 2;    /**< Reserved. */
        uint32_t uhbr13CblSupp              : 1;    /**< Cable UHBR13 Support. */
        uint32_t rsvd3                      : 1;    /**< Reserved. */
        uint32_t actComp                    : 2;    /**< Cable active component. */
        uint32_t dpAmVersion                : 2;    /**< DP alt mode version. */
    } dp_cfg_vdo;                               /**< DO interpreted as a DisplayPort Configure command. */

    /** @brief Programmable Power Supply Source PDO. */
    struct PPS_SRC
    {
        uint32_t maxCur                     : 7;    /**< Maximum current in 50 mA units. */
        uint32_t rsvd1                      : 1;    /**< Reserved field. */
        uint32_t minVolt                    : 8;    /**< Minimum voltage in 100 mV units. */
        uint32_t rsvd2                      : 1;    /**< Reserved field. */
        uint32_t maxVolt                    : 8;    /**< Maximum voltage in 100 mV units. */
        uint32_t rsvd3                      : 2;    /**< Reserved field. */
        uint32_t ppsPwrLimited              : 1;    /**< Whether PPS power has been limited. */
        uint32_t apdoType                   : 2;    /**< APDO type: Should be 0 for PPS. */
        uint32_t supplyType                 : 2;    /**< PDO type: Should be 3 for PPS APDO. */
    } pps_src;                                      /**< DO interpreted as a Programmable Power Supply - Source. */

    /** @brief Programmable Power Supply Sink PDO. */
    struct PPS_SNK
    {
        uint32_t opCur                      : 7;    /**< Operating current in 50 mA units. */
        uint32_t rsvd1                      : 1;    /**< Reserved field. */
        uint32_t minVolt                    : 8;    /**< Minimum voltage in 100 mV units. */
        uint32_t rsvd2                      : 1;    /**< Reserved field. */
        uint32_t maxVolt                    : 8;    /**< Maximum voltage in 100 mV units. */
        uint32_t rsvd3                      : 1;    /**< Reserved field. */
        uint32_t curFb                      : 1;    /**< Whether current foldback is required. */
        uint32_t rsvd4                      : 1;    /**< Reserved field. */
        uint32_t apdoType                   : 2;    /**< APDO type: Should be 0 for PPS. */
        uint32_t supplyType                 : 2;    /**< PDO type: Should be 3 for PPS APDO. */
    } pps_snk;                                      /**< DO interpreted as a Programmable Power Supply - Sink. */

    /** @brief Programmable Request Data Object. */
    struct RDO_PPS
    {
        uint32_t opCur                      : 7;    /**< Operating current in 50 mA units. */
        uint32_t rsvd1                      : 2;    /**< Reserved field. */
        uint32_t outVolt                    : 11;   /**< Requested output voltage in 20 mV units. */
        uint32_t rsvd2                      : 3;    /**< Reserved field. */
        uint32_t unchunkSup                 : 1;    /**< Whether unchunked extended messages are supported. */
        uint32_t noUsbSuspend               : 1;    /**< No USB suspend flag. */
        uint32_t usbCommCap                 : 1;    /**< Whether sink supports USB communication. */
        uint32_t capMismatch                : 1;    /**< Capability mismatch flag. */
        uint32_t rsvd3                      : 1;    /**< Reserved field. */
#if CY_PD_REV3_ENABLE
        uint32_t objPos                     : 4;    /**< Object position - index to source PDO. */
#else        
        uint32_t objPos                     : 3;    /**< Object position - index to source PDO. */
        uint32_t rsvd4                      : 1;    /**< Reserved field. */
#endif /* CY_PD_REV3_ENABLE */
    } rdo_pps;                                      /**< DO interpreted as a PPD Request. */

    /** @brief Programmable Power Supply Source PDO. */
    struct EPR_AVS_SRC
    {
        uint32_t pdp                        : 8;    /**< PDP in 1W increments. */
        uint32_t minVolt                    : 8;    /**< Minimum Voltage in 100mV increments */
        uint32_t rsvd1                      : 1;    /**< Reserved field. */
        uint32_t maxVolt                    : 9;    /**< Maximum voltage in 100 mV units. */
        uint32_t rsvd2                      : 2;    /**< Reserved field. */
        uint32_t apdoType                   : 2;    /**< APDO type: Should be 0x01 for EPR AVS */
        uint32_t supplyType                 : 2;    /**< PDO type: Should be 3 for APDO. */
    } epr_avs_src;                                  /**< DO interpreted as an EPR Adjustable Voltages Supply - Source. */

    /** @brief SPR AVS Source PDO. */
    struct SPR_AVS_SRC
    {
        uint32_t maxCur2                    : 10;   /**< Max current in 10mA units for 15-20 V range. */
        uint32_t maxCur1                    : 10;   /**< Max current in 10mA units for 9-15 V range. */
        uint32_t rsvd                       : 6;    /**< Reserved field. */
        uint32_t pkCurrent                  : 2;    /**< Peak Current in %. */
        uint32_t apdoType                   : 2;    /**< APDO type: Should be 0x02 for SPR AVS */
        uint32_t supplyType                 : 2;    /**< PDO type: Should be 0x03 for APDO. */
    } spr_avs_src;                                  /**< DO interpreted as an SPR Adjustable Voltages Supply - Source. */

    /** @brief Programmable Power Supply Sink PDO. */
    struct EPR_AVS_SNK
    {
        uint32_t pdp                        : 8;    /**< PDP in 1W increments. */
        uint32_t minVolt                    : 8;    /**< Minimum Voltage in 100mV increments */
        uint32_t rsvd1                      : 1;    /**< Reserved field. */
        uint32_t maxVolt                    : 9;    /**< Maximum voltage in 100 mV units. */
        uint32_t rsvd2                      : 2;    /**< Reserved field. */
        uint32_t apdoType                   : 2;    /**< APDO type: Should be 0x01 for EPR AVS */
        uint32_t supplyType                 : 2;    /**< PDO type: Should be 3 for APDO. */
    } epr_avs_snk;                                  /**< DO interpreted as a Adjustable Voltages Supply - Sink. */

    /** @brief Programmable Request Data Object. */
    struct RDO_EPR_AVS
    {
        uint32_t opCur                      : 7;    /**< Operating current in 50 mA units. */
        uint32_t rsvd1                      : 2;    /**< Reserved field. */
        uint32_t outVolt                    : 12;   /**< Output Voltage in 25mV units. The two least significant bit */
                                                    /**< Shall be zero making the effective step size 100 mV. */
        uint32_t rsvd2                      : 1;    /**< Reserved field. */
        uint32_t eprModeCapable             : 1;    /**< EPR mode capable. */
        uint32_t unchunkSup                 : 1;    /**< Whether unchunked extended messages are supported. */
        uint32_t noUsbSuspend               : 1;    /**< No USB suspend flag. */
        uint32_t usbCommCap                 : 1;    /**< Whether sink supports USB communication. */
        uint32_t capMismatch                : 1;    /**< Capability mismatch flag. */
        uint32_t rsvd3                      : 1;    /**< Reserved field. */
        uint32_t objPos                     : 4;    /**< Object position - index to source PDO. */
    } rdo_epr_avs;                                  /**< DO interpreted as a AVS Request. */

    /** @brief SPR AVS Request Data Object. */
    struct RDO_SPR_AVS
    {
        uint32_t opCur                      : 7;    /**< Operating current in 50 mA units. */
        uint32_t rsvd1                      : 2;    /**< Reserved field. */
        uint32_t outVolt                    : 12;   /**< Output Voltage in 25mV units. The two least significant bit */
                                                    /**< Shall be zero making the effective step size 100 mV. */
        uint32_t rsvd2                      : 1;    /**< Reserved field. */
        uint32_t eprModeCapable             : 1;    /**< EPR mode capable. */
        uint32_t unchunkSup                 : 1;    /**< Whether unchunked extended messages are supported. */
        uint32_t noUsbSuspend               : 1;    /**< No USB suspend flag. */
        uint32_t usbCommCap                 : 1;    /**< Whether sink supports USB communication. */
        uint32_t capMismatch                : 1;    /**< Capability mismatch flag. */
        uint32_t rsvd3                      : 1;    /**< Reserved field. */
        uint32_t objPos                     : 4;    /**< Object position - index to source PDO. */
    } rdo_spr_avs;                                  /**< DO interpreted as SPR AVS Request. */

    /** @brief PD 3.0 Alert Data Object. */
    struct ADO_ALERT
    {
        uint32_t extdAlertEvtType           :4;     /**< Extended alert event type. */
        uint32_t rsvd1                      :12;    /**< Reserved field. */
        uint32_t hotSwapBats                :4;     /**< Identifies hot-swappable batteries whose status has changed. */
        uint32_t fixedBats                  :4;     /**< Identifies fixed batteries whose status has changed. */
        uint32_t rsvd2                      :1;     /**< Reserved field. */
        uint32_t batStatusChange            :1;     /**< Battery status changed. */
        uint32_t ocp                        :1;     /**< Over-Current event status. */
        uint32_t otp                        :1;     /**< Over-Temperature event status. */
        uint32_t opCondChange               :1;     /**< Operating conditions changed. */
        uint32_t srcInputChange             :1;     /**< Power source input changed. */
        uint32_t ovp                        :1;     /**< Over-Voltage event status. */
        uint32_t extdAlert                  :1;     /**< Extended alert event status. */
    } ado_alert;                                    /**< DO interpreted as a PD 3.0 alert message. */

    /** @brief Thunderbolt UFP Discover Modes Response Data Object. */
    struct TBT_UFP_VDO
    {
        uint32_t intelMode                  : 16;   /**< Thunderbolt (Intel) modes identifier. */
        uint32_t adapter                    : 1;    /**< Legacy TBT Adapter or Device. */
        uint32_t rsvd0                      : 9;    /**< Reserved field. */
        uint32_t vproSupp                   : 1;    /**< Whether supports vPro mode. */
        uint32_t rsvd1                      : 5;    /**< Reserved field. */
    } tbt_ufp_vdo;                                  /**< Data Object interpreted as a Thunderbolt3 mode VDO. */

    /** @brief Thunderbolt Discover Modes Response Data Object. */
    struct TBT_VDO
    {
        uint32_t intelMode                  : 16;   /**< Thunderbolt (Intel) modes identifier. */
        uint32_t cblSpeed                   : 3;    /**< Data bandwidth supported by the Type-C cable. */
        uint32_t cblGen                     : 2;    /**< Thunderbolt cable generation. */
        uint32_t cblType                    : 1;    /**< Whether cable is non-optical or optical. */
        uint32_t b22RetimerCbl              : 1;    /**< Type of Type-C cable: Redriver or Retimer. */
        uint32_t linkTraining               : 1;    /**< Type of link training supported by active cable. */
        uint32_t adapter                    : 1;    /**< Legacy TBT Adapter or Device. */
        uint32_t cableActive                : 1;    /**< Whether cable reports active or passive in ID HDR in discover id response. */
        uint32_t vproDockHost               : 1;    /**< Whether the device supports VPRO feature. */
        uint32_t rsvd1                      : 3;    /**< Reserved field. */
        uint32_t rsvd2                      : 2;    /**< Reserved field. */
    } tbt_vdo;                                      /**< DO interpreted as a Thunderbolt Discovery response. */

    /** @brief Thunderbolt Discover Modes Response Data Object. */
    struct TBT_CBL_VDO
    {
        uint32_t intelMode                  : 16;   /**< Thunderbolt (Intel) modes identifier. */
        uint32_t cblSpeed                   : 3;    /**< Data bandwidth supported by the Type-C cable. */
        uint32_t cblGen                     : 2;    /**< Thunderbolt cable generation. */
        uint32_t cblType                    : 1;    /**< Whether cable is non-optical or optical. */
        uint32_t b22RetimerCbl              : 1;    /**< Type of Type-C cable: Redriver or Retimer. */
        uint32_t linkTraining               : 1;    /**< Type of link training supported by active cable. */
        uint32_t rsvd1                      : 8;    /**< Reserved field. */
    } tbt_cbl_vdo;                                  /**< DO interpreted as a Thunderbolt Discovery response. */

    /** @brief UFP VDO #1 */
    struct UFP_VDO_1
    {
        uint32_t usbSig                     : 3;    /**< USB signaling supported. */
        uint32_t altModes                   : 3;    /**< Alt. modes supported bit-map. */
#if CY_PD_REV3_ENABLE
        uint32_t rsvd0                      : 16;   /**< Reserved field. */
        uint32_t connType                   : 2;    /**< Connector type. */
#else
        uint32_t rsvd0                      : 18;   /**< Reserved field. */
#endif /* CY_PD_REV3_ENABLE */
        uint32_t devCap                     : 4;    /**< Device Capability. */
        uint32_t rsvd1                      : 1;    /**< Reserved field. */
        uint32_t vdoVersion                 : 3;    /**< VDO version field. */
    } ufp_vdo_1;                                    /**< DO interpreted as UFP VDO1 data object. */

    /** @brief DFP VDO */
    struct DFP_VDO
    {
        uint32_t portNum                    : 5;    /**< Unique port number to identify a specific port on a multi-port device. */
#if CY_PD_REV3_ENABLE
        uint32_t rsvd0                      : 17;   /**< Reserved field. */
        uint32_t connType                   : 2;    /**< Connector type. */
#else
        uint32_t rsvd0                      : 19;   /**< Reserved field. */
#endif /* CY_PD_REV3_ENABLE */
        uint32_t hostCap                    : 3;    /**< Host capability. */
        uint32_t rsvd1                      : 2;    /**< Reserved field. */
        uint32_t vdoVersion                 : 3;    /**< VDO version field. */
    } dfp_vdo;                                      /**< DO interpreted as UFP VDO1 data object. */

    /** @brief Enter USB Data Object. */
    struct ENTERUSB_VDO
    {
        uint32_t rsvd0                      : 13;   /**< Reserved field. */
        uint32_t hostPresent                : 1;    /**< Whether a host is connected. */
        uint32_t hostTbtSupp                : 1;    /**< Whether host supports Thunderbolt. */
        uint32_t hostDpSupp                 : 1;    /**< Whether host supports DisplayPort. */
        uint32_t hostPcieSupp               : 1;    /**< Whether host supports PCIe. */
        uint32_t cableCurrent               : 2;    /**< Current carrying capacity of the cable. */
        uint32_t cableType                  : 2;    /**< Type of cable. */
        uint32_t cableSpeed                 : 3;    /**< Data rate supported by the cable. */
        uint32_t rsvd1                      : 1;    /**< Reserved field. */
        uint32_t usb3Drd                    : 1;    /**< Whether the DFP is USB 3.2 DRD capable. */
        uint32_t usb4Drd                    : 1;    /**< Whether the DFP is USB4 DRD capable. */
        uint32_t rsvd2                      : 1;    /**< Reserved field. */
        uint32_t usbMode                    : 3;    /**< Mode of USB communication (2.0, 3.2 or 4.0) */
        uint32_t rsvd3                      : 1;    /**< Reserved field. */
    } enterusb_vdo;                                 /**< DO interpreted as an Enter USB Data Object. */

    /** @brief EPR Mode Data Object. */
    struct EPRMODE_DO
    {
        uint32_t rsvd                       : 16;   /**< Reserved field. */
        uint32_t data                       : 8;    /**< command parameter or failure cause. */
        uint32_t action                     : 8;    /**< Required action. */
    } eprmdo;                                       /**< DO interpreted as EPR Mode Data Object. */

    /** @cond DOXYGEN_HIDE */
    struct SLICE_VDO
    {
        uint32_t sliceMode                  : 16;
        uint32_t moduleType                 : 2;
        uint32_t rsvd                       : 14;
    } slice_vdo;

    struct SLICE_SUBHDR
    {
        uint32_t amAddr                    : 20;
        uint32_t vdoCnt                    : 3;
        uint32_t multiPart                 : 1;
        uint32_t dataCnt                   : 8;
    } slice_subhdr;
    
    /** @brief Different fields of source information*/
    struct SRC_INFO
    {
        uint32_t portRepPdp   : 8;                /**< Bits 07:00 - Reported Port PDP */
        uint32_t portPresPdp  : 8;                /**< Bits 15:8 - Present Port PDP */
        uint32_t portMaxPdp   : 8;                /**< Bits 23:16 - Maximum Port PDP. */
        uint32_t reserved     : 7;                /**< Bits 30: 24 - Reserved. */
        uint32_t portType     : 1;                /**< Bit     31 - Port Type. */
    } src_info;  
    /** @endcond */

} cy_pd_pd_do_t;

/** Structure to hold extended PD packets (messages). */
typedef struct
{
    cy_en_pd_sop_t      sop;                    /**< Packet type. */
    uint8_t             len;                    /**< Length of the message: Unused for unchunked extended messages. */
    uint8_t             msg;                    /**< Message code. */
    cy_en_pd_port_role_t  dataRole;             /**< Data role. */
    cy_pd_pd_hdr_t    hdr;                      /**< Message header, including extended header. */
    cy_pd_pd_do_t     dat[CY_PD_MAX_EXTD_PKT_WORDS];/**< Data associated with the message. */
} cy_stc_pd_packet_extd_t;

/** Union to hold CC status. */
typedef union cy_pd_cc_state
{
    uint16_t state;                     /**< Combined status of CC1 and CC2. */
    uint8_t  cc[2];                     /**< Individual status of CC1(cc[0]) and CC2(cc[1]). */
} cy_pd_cc_state_t;

/** Structure to hold port dpm status variables which are common to the driver and stack **/
typedef struct
{
    /** Type of device attached. */
    cy_en_pd_devtype_t attachedDev;

    /** Stores Type C events. */
    uint32_t volatile typecEvt;

    /** DPM enabled flag. */
    bool dpmEnabled;

    /** Port connected but not debounced yet. */
    bool volatile connect;

    /** Port attached indication. */
    bool volatile attach;

    /** PD contract exists indication. */
    bool volatile contractExist;

    /** DRP toggle is enabled. */
    bool toggle;

    /** VCONN logical status. */
    bool volatile vconnLogical;

    /** Cable discovery control knob. */
    bool cblDsc;

    /** EMCA cable present indication. */
    bool volatile emcaPresent;

    /** Skip CC scanning control knob. */
    bool volatile skipScan;

    /** Current port type: UFP or DFP. */
    cy_en_pd_port_type_t curPortType;

    /** Current spec rev for SOP messages. */
    cy_en_pd_pd_rev_t specRevSopLive;

    /** Fast role signal auto send enabled */
    bool frTxEnLive;

    /** Fast role signal detection enabled */
    bool frRxEnLive;

    /** Type C current level in sink role. */
    uint8_t volatile snkCurLevel;

    /** Old CC status. */
    cy_pd_cc_state_t ccOldStatus;

    /** Current Port role: Sink or Source. */
    cy_en_pd_port_role_t curPortRole;

    /** Current Type C current level in the source role. */
    uint8_t srcCurLevelLive;

    /** Current state of the CC1 and CC2 pins. */
    uint8_t ccStat[2];

    /** CC channel polarity (CC1=0, CC2=1) */
    uint8_t polarity;

    /** CC channel reverse polarity. */
    uint8_t revPol;

} cy_stc_pd_dpm_config_t;

/**
 * DPM configuration information retrieval callback. This callback is used by
 * the USBPD driver to get retrieve the dpm configuration required by the USBPD
 * driver.
 *
 * \param
 * None
 *
 * \return cy_stc_pd_dpm_config_t
 * Pointer to the DPM configuration information through \ref cy_stc_pd_dpm_config_t structure.
 *
 */
typedef cy_stc_pd_dpm_config_t * (*cy_cb_pd_dpm_get_config_t)(void);

/** \} group_usbpd_common_data_structures */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_DEFINES_H_ */

/* [] END OF FILE */
