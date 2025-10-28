/***************************************************************************//**
* \file cy_sar.c
* \version 2.70
*
* Provides the functions for the API for the SAR driver.
*
********************************************************************************
* \copyright
* (c) (2020-2025), Cypress Semiconductor Corporation (an Infineon company) or
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
#include "cy_sar.h"

#ifdef CY_IP_M0S8PASS4A_SAR

#if defined(__cplusplus)
extern "C" {
#endif

/** \cond INTERNAL */
#define CY_SAR_DEINIT                   (0UL)             /**< De-init value for most SAR registers */
#define CY_SAR_SAMPLE_TIME_DEINIT       ((3UL << SAR_SAMPLE_TIME01_SAMPLE_TIME0_Pos) | (3UL << SAR_SAMPLE_TIME01_SAMPLE_TIME1_Pos))  /**< De-init value for the SAMPLE_TIME* registers */
#define CY_SAR_SAMPLE_CTRL_DEINIT       (SAR_SAMPLE_CTRL_DIFFERENTIAL_SIGNED_Msk | SAR_SAMPLE_CTRL_DSI_SYNC_TRIGGER_Msk)  /**< De-init value for the SAMPLE_CTRL register */
#define CY_SAR_CLEAR_ALL_SWITCHES       (0x3FFFFFFFUL)    /**< Value to clear all SARMUX switches */

/* Mask value of MUX_SWITCH2 */
#if defined (CY_PASS0_SAR_EXPMUX_PRESENT) && (1U == CY_PASS0_SAR_EXPMUX_PRESENT)
    #define CY_SAR_MUX_SWITCH2_MASK (0xFFFFFFFFU)
#else
    #define CY_SAR_MUX_SWITCH2_MASK (0xFFFF0000U)
#endif /* (1U == CY_PASS0_SAR_EXPMUX_PRESENT) */
#define CY_SAR_DEINIT_SQ_CTRL           (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P0_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P1_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P2_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P3_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P4_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P5_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P6_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P7_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_VSSA_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_TEMP_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_AMUXBUSA_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_AMUXBUSB_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_SARBUS0_Msk \
                                        | SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_SARBUS1_Msk)

#define CY_SAR_2US_DELAY                (2U)              /**< Delay used in Enable API function to avoid SAR deadlock */
#define CY_SAR_10V_COUNTS               (10.0F)           /**< Value of 10 in volts */
#define CY_SAR_10MV_COUNTS              (10000UL)         /**< Value of 10 in millivolts */
#define CY_SAR_10UV_COUNTS              (10000000UL)      /**< Value of 10 in microvolts */
#define CY_SAR_RANGE_LIMIT_MAX          (0xFFFFUL)        /**< Maximum value for the low and high range interrupt threshold values */
#define CY_SAR_CAP_TRIM_MAX             (0x3FUL)          /**< Maximum value for CAP_TRIM */
#define CY_SAR_CAP_TRIM_MIN             (0x00UL)          /**< Maximum value for CAP_TRIM */
#define CY_SAR_CAP_TRIM                 (0x0BUL)          /**< Correct cap trim value */

/* Macros for conditions used in CY_ASSERT calls */
#define CY_SAR_CHAN_NUM(chan)           ((chan) < CY_SAR_NUM_CHANNELS)
#define CY_SAR_RIGHT_ALIGN              (!_FLD2BOOL(SAR_SAMPLE_CTRL_LEFT_ALIGN, SAR_SAMPLE_CTRL(base)))
#define IS_SAR_MASK_VALID(sarMask)      (0UL == ((sarMask) & ((uint32_t) ~CY_SAR_MASK)))
#define CY_SAR_INJMASK(mask)            (0UL == ((mask) & ~(CY_SAR_INJ_CHAN_MASK | CY_SAR_CHANNELS_MASK)))
#define CY_SAR_TRIGGER(mode)            (((mode) == CY_SAR_TRIGGER_MODE_FW_ONLY) || \
                                         ((mode) == CY_SAR_TRIGGER_MODE_FW_AND_HWEDGE) || \
                                         ((mode) == CY_SAR_TRIGGER_MODE_FW_AND_HWLEVEL))
#define CY_SAR_RETURN(mode)             (((mode) == CY_SAR_RETURN_STATUS) || \
                                         ((mode) == CY_SAR_WAIT_FOR_RESULT) || \
                                         ((mode) == CY_SAR_RETURN_STATUS_INJ) || \
                                         ((mode) == CY_SAR_WAIT_FOR_RESULT_INJ))
#define CY_SAR_STARTCONVERT(mode)       (((mode) == CY_SAR_START_CONVERT_SINGLE_SHOT) || ((mode) == CY_SAR_START_CONVERT_CONTINUOUS))
#define CY_SAR_RANGE_LIMIT(limit)       ((limit) <= CY_SAR_RANGE_LIMIT_MAX)
#define CY_SAR_SWITCHMASK(mask)         ((mask) <= CY_SAR_CLEAR_ALL_SWITCHES)
#define CY_SAR_SQMASK(mask)             (((mask) & (~CY_SAR_DEINIT_SQ_CTRL)) == 0UL)
#define CY_SAR_VREF(vref)               ((CY_SAR_VREF_SEL_BGR        == (vref)) || \
                                         (CY_SAR_VREF_SEL_EXT        == (vref)) || \
                                         (CY_SAR_VREF_SEL_VDDA_DIV_2 == (vref)) || \
                                         (CY_SAR_VREF_SEL_VDDA       == (vref)))
#define CY_SAR_NEG_SEL(nsel)            ((CY_SAR_NEG_SEL_VSSA_KELVIN == (nsel)) || \
                                         (CY_SAR_NEG_SEL_ART_VSSA    == (nsel)) || \
                                         (CY_SAR_NEG_SEL_P1          == (nsel)) || \
                                         (CY_SAR_NEG_SEL_P3          == (nsel)) || \
                                         (CY_SAR_NEG_SEL_P5          == (nsel)) || \
                                         (CY_SAR_NEG_SEL_P7          == (nsel)) || \
                                         (CY_SAR_NEG_SEL_ACORE       == (nsel)) || \
                                         (CY_SAR_NEG_SEL_VREF        == (nsel)))
#define CY_SAR_NEG_REF(nref)            ((CY_SAR_NEGVREF_FW_ONLY     == (nref)) || \
                                         (CY_SAR_NEGVREF_HW          == (nref)))
#define CY_SAR_PWR(pwr)                 ((CY_SAR_NORMAL_PWR          == (pwr)) || \
                                         (CY_SAR_HALF_PWR            == (pwr)) || \
                                         (CY_SAR_MORE_PWR            == (pwr)) || \
                                         (CY_SAR_QUARTER_PWR         == (pwr)))
#define CY_SAR_SUB_RES(sres)            ((CY_SAR_SUB_RESOLUTION_8B   == (sres)) || \
                                         (CY_SAR_SUB_RESOLUTION_10B  == (sres)))
#define CY_SAR_AVG(avg)                 ((CY_SAR_AVG_CNT_2           == (avg)) || \
                                         (CY_SAR_AVG_CNT_4           == (avg)) || \
                                         (CY_SAR_AVG_CNT_8           == (avg)) || \
                                         (CY_SAR_AVG_CNT_16          == (avg)) || \
                                         (CY_SAR_AVG_CNT_32          == (avg)) || \
                                         (CY_SAR_AVG_CNT_64          == (avg)) || \
                                         (CY_SAR_AVG_CNT_128         == (avg)) || \
                                         (CY_SAR_AVG_CNT_256         == (avg)))
#define CY_SAR_MIN_SAMPLE_TIME          (2UL)
#define CY_SAR_SAMPLE_TIME(sTime)       ((CY_SAR_MIN_SAMPLE_TIME <= (sTime)) && ((sTime) <= SAR_SAMPLE_TIME01_SAMPLE_TIME0_Msk))

#if defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)
#define CY_SAR_DIAG(addr)               ((CY_SAR_ADDR_DIAG_GND         == (addr)) || \
                                         (CY_SAR_ADDR_DIAG_SRSS_BGR    == (addr)) || \
                                         (CY_SAR_ADDR_DIAG_VBAT_DIV_24 == (addr)) || \
                                         (CY_SAR_ADDR_DIAG_VCC_DIV_2   == (addr)) || \
                                         (CY_SAR_ADDR_DIAG_VDD_DIV_6   == (addr)))
#else
#define CY_SAR_DIAG(addr)               (0u)
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */

#if defined (CY_PASS0_SAR_EXPMUX_PRESENT) && (1U == CY_PASS0_SAR_EXPMUX_PRESENT)
#define CY_SAR_EXP_ADDR(addr)           ((CY_SAR_ADDR_EXPMUX_0         == (addr)) || \
                                         (CY_SAR_ADDR_EXPMUX_1         == (addr)) || \
                                         (CY_SAR_ADDR_EXPMUX_2         == (addr)) || \
                                         (CY_SAR_ADDR_EXPMUX_3         == (addr)) || \
                                         (CY_SAR_ADDR_EXPMUX_4         == (addr)) || \
                                         (CY_SAR_ADDR_EXPMUX_5         == (addr)) || \
                                         (CY_SAR_ADDR_EXPMUX_6         == (addr)) || \
                                         (CY_SAR_ADDR_EXPMUX_7         == (addr)))

#define CY_SAR_EXP_NEG_ADDR(addr)       ((CY_SAR_NEG_ADDR_EXPMUX_0     == (addr)) || \
                                          CY_SAR_NEG_ADDR_EXPMUX_1     == (addr)) || \
                                          CY_SAR_NEG_ADDR_EXPMUX_2     == (addr)) || \
                                          CY_SAR_NEG_ADDR_EXPMUX_3     == (addr)) || \
                                          CY_SAR_NEG_ADDR_EXPMUX_4     == (addr)) || \
                                          CY_SAR_NEG_ADDR_EXPMUX_5     == (addr)) || \
                                          CY_SAR_NEG_ADDR_EXPMUX_6     == (addr)) || \
                                          CY_SAR_NEG_ADDR_EXPMUX_7     == (addr)))
#else
#define CY_SAR_EXP_ADDR(addr)           (0u)
#define CY_SAR_EXP_NEG_ADDR(addr)       (0u)
#endif /* 1U == CY_PASS0_SAR_EXPMUX_PRESENT */

#if defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)
#define CY_SAR_DIAG(addr)               ((CY_SAR_ADDR_DIAG_GND         == (addr)) || \
                                         (CY_SAR_ADDR_DIAG_SRSS_BGR    == (addr)) || \
                                         (CY_SAR_ADDR_DIAG_VBAT_DIV_24 == (addr)) || \
                                         (CY_SAR_ADDR_DIAG_VCC_DIV_2   == (addr)) || \
                                         (CY_SAR_ADDR_DIAG_VDD_DIV_6   == (addr)))

#define CY_SAR_NEG_DIAG(addr)           ((CY_SAR_NEG_ADDR_DIAG_VSSA        == (addr)) || \
                                         (CY_SAR_NEG_ADDR_DIAG_VSSD        == (addr)) || \
                                         (CY_SAR_NEG_ADDR_SARMUX_AMUXBUS_A == (addr)) || \
                                         (CY_SAR_NEG_ADDR_SARMUX_AMUXBUS_B == (addr)))

#define CY_SAR_NEG_ADDR(addr)           ((CY_SAR_NEG_ADDR_SARMUX_0     == (addr)) || \
                                         (CY_SAR_NEG_ADDR_SARMUX_1     == (addr)) || \
                                         (CY_SAR_NEG_ADDR_SARMUX_2     == (addr)) || \
                                         (CY_SAR_NEG_ADDR_SARMUX_3     == (addr)) || \
                                         (CY_SAR_NEG_ADDR_SARMUX_4     == (addr)) || \
                                         (CY_SAR_NEG_ADDR_SARMUX_5     == (addr)) || \
                                         (CY_SAR_NEG_ADDR_SARMUX_6     == (addr)) || \
                                         (CY_SAR_NEG_ADDR_SARMUX_7     == (addr)))
#else
#define CY_SAR_DIAG(addr)               (0u)
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */
#define CY_SAR_ADDR(addr)               ((CY_SAR_ADDR_SARMUX_0         == (addr)) || \
                                         (CY_SAR_ADDR_SARMUX_1         == (addr)) || \
                                         (CY_SAR_ADDR_SARMUX_2         == (addr)) || \
                                         (CY_SAR_ADDR_SARMUX_3         == (addr)) || \
                                         (CY_SAR_ADDR_SARMUX_4         == (addr)) || \
                                         (CY_SAR_ADDR_SARMUX_5         == (addr)) || \
                                         (CY_SAR_ADDR_SARMUX_6         == (addr)) || \
                                         (CY_SAR_ADDR_SARMUX_7         == (addr)) || \
                                         (CY_SAR_ADDR_CTB0_OA0         == (addr)) || \
                                         (CY_SAR_ADDR_CTB0_OA1         == (addr)) || \
                                         (CY_SAR_ADDR_CTB1_OA0         == (addr)) || \
                                         (CY_SAR_ADDR_CTB1_OA1         == (addr)) || \
                                         (CY_SAR_ADDR_CTB2_OA0         == (addr)) || \
                                         (CY_SAR_ADDR_CTB2_OA1         == (addr)) || \
                                         (CY_SAR_ADDR_CTB3_OA0         == (addr)) || \
                                         (CY_SAR_ADDR_CTB3_OA1         == (addr)) || \
                                         (CY_SAR_ADDR_SARMUX_DIE_TEMP  == (addr)) || \
                                         (CY_SAR_ADDR_SARMUX_AMUXBUS_A == (addr)) || \
                                         (CY_SAR_ADDR_SARMUX_AMUXBUS_B == (addr)))
#define CY_SAR_RESOLUTION(res)          ((CY_SAR_MAX_RES  == (res)) || \
                                         (CY_SAR_SUB_RES  == (res)))

#define CY_SAR_SAMPLE_TIMER_CNT         (4UL)
#define CY_SAR_SAMPLE_TIMER(sTimer)     ((CY_SAR_SAMPLE_TIME_0 == (sTimer)) || \
                                         (CY_SAR_SAMPLE_TIME_1 == (sTimer)) || \
                                         (CY_SAR_SAMPLE_TIME_2 == (sTimer)) || \
                                         (CY_SAR_SAMPLE_TIME_3 == (sTimer)))

#define SAR_SAMPLE_CTRL_DSI_TRIGGER_MODE_Pos (SAR_SAMPLE_CTRL_DSI_TRIGGER_EN_Pos)
#define SAR_SAMPLE_CTRL_DSI_TRIGGER_MODE_Msk (SAR_SAMPLE_CTRL_DSI_TRIGGER_EN_Msk | SAR_SAMPLE_CTRL_DSI_TRIGGER_LEVEL_Msk)

#if defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4 <= CY_IP_M0S8PASS4A_SAR_VERSION)
    #define SAR_CHAN_CONFIG_ADDR_Pos  (SAR_CHAN_CONFIG_POS_PIN_ADDR_Pos)
    #define SAR_CHAN_CONFIG_ADDR_Msk  (SAR_CHAN_CONFIG_POS_PIN_ADDR_Msk | SAR_CHAN_CONFIG_POS_PORT_ADDR_Msk)
    #define SAR_CHAN_CONFIG_NEG_ADDR_Pos  (SAR_CHAN_CONFIG_NEG_PIN_ADDR_Pos)
    #define SAR_CHAN_CONFIG_NEG_ADDR_Msk  (SAR_CHAN_CONFIG_NEG_PIN_ADDR_Msk | SAR_CHAN_CONFIG_NEG_PORT_ADDR_Msk)
#else
    #define SAR_CHAN_CONFIG_ADDR_Pos  (SAR_CHAN_CONFIG_PIN_ADDR_Pos)
    #define SAR_CHAN_CONFIG_ADDR_Msk  (SAR_CHAN_CONFIG_PIN_ADDR_Msk | SAR_CHAN_CONFIG_PORT_ADDR_Msk)
#endif /* (4 <= CY_IP_M0S8PASS4A_SAR_VERSION) */

/* firmware control of expmux and diagmux */
#if defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)
#if defined (CY_PASS0_SAR_EXPMUX_PRESENT) && (1U == CY_PASS0_SAR_EXPMUX_PRESENT)
#define CY_EXP_VPLUS(addr)               ((CY_SAR_EXPMUX_FW_P0_VPLUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P1_VPLUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P2_VPLUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P3_VPLUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P4_VPLUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P5_VPLUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P6_VPLUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P7_VPLUS == (addr)))
#define CY_EXP_VMINUS(addr)              ((CY_SAR_EXPMUX_FW_P0_VMINUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P1_VMINUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P2_VMINUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P3_VMINUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P4_VMINUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P5_VMINUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P6_VMINUS == (addr)) || \
                                          (CY_SAR_EXPMUX_FW_P7_VMINUS == (addr)))
#else
#define CY_EXP_VPLUS(addr)               (0u)
#define CY_EXP_VMINUS(addr)              (0u)
#endif /* (1U == CY_PASS0_SAR_EXPMUX_PRESENT) */
#define CY_DIAG_VPLUS(addr)              ((CY_SAR_DIAGMUX_FW_VD0_VPLUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_VD1_VPLUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_VD2_VPLUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_VD3_VPLUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_VD4_VPLUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_VD5_VPLUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_VD6_VPLUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_VD7_VPLUS == (addr)))
#define CY_DIAG_VMINUS(addr)             ((CY_SAR_DIAGMUX_FW_VG0_VMINUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_VG1_VMINUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_VG2_VMINUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_VG3_VMINUS == (addr)))
#define CY_BROKEN_WIRE(addr)             ((CY_SAR_DIAGMUX_FW_CSRC_VPLUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_CSINK_VPLUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_CSRC_VMINUS == (addr)) || \
                                          (CY_SAR_DIAGMUX_FW_CSINK_VMINUS == (addr)))
#else
#define CY_EXP_VPLUS(addr)               (0u)
#define CY_EXP_VMINUS(addr)              (0u)
#define CY_DIAG_VPLUS(addr)              (0u)
#define CY_DIAG_VMINUS(addr)             (0u)
#define CY_BROKEN_WIRE(addr)             (0u)
#endif /* (4U <= CY_IP_M0S8PASS4A_SAR_VERSION) */

/* hardware control of expmux and diagmux */
#if defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)
#if defined (CY_PASS0_SAR_EXPMUX_PRESENT) && (1U == CY_PASS0_SAR_EXPMUX_PRESENT)
#define CY_HW_EXPMUX(addr)               ((CY_SAR_EXPMUX_HW_CTRL_P0 == (addr)) || \
                                          (CY_SAR_EXPMUX_HW_CTRL_P1 == (addr)) || \
                                          (CY_SAR_EXPMUX_HW_CTRL_P2 == (addr)) || \
                                          (CY_SAR_EXPMUX_HW_CTRL_P3 == (addr)) || \
                                          (CY_SAR_EXPMUX_HW_CTRL_P4 == (addr)) || \
                                          (CY_SAR_EXPMUX_HW_CTRL_P5 == (addr)) || \
                                          (CY_SAR_EXPMUX_HW_CTRL_P6 == (addr)) || \
                                          (CY_SAR_EXPMUX_HW_CTRL_P7 == (addr)))
#else
#define CY_HW_EXPMUX(addr)               (0u)
#endif /* (1U == CY_PASS0_SAR_EXPMUX_PRESENT) */
#define CY_HW_DIAGMUX(addr)              ((CY_SAR_DIAGMUX_HW_CTRL_V0 == (addr)) || \
                                          (CY_SAR_DIAGMUX_HW_CTRL_V1 == (addr)) || \
                                          (CY_SAR_DIAGMUX_HW_CTRL_V2 == (addr)) || \
                                          (CY_SAR_DIAGMUX_HW_CTRL_V3 == (addr)) || \
                                          (CY_SAR_DIAGMUX_HW_CTRL_V4 == (addr)) || \
                                          (CY_SAR_DIAGMUX_HW_CTRL_V5 == (addr)) || \
                                          (CY_SAR_DIAGMUX_HW_CTRL_V6 == (addr)) || \
                                          (CY_SAR_DIAGMUX_HW_CTRL_V7 == (addr)))
#define CY_HW_BROKEN_WIRE(addr)          ((CY_SAR_HW_CTRL_CSRC_VPLUS == (addr)) || \
                                         (CY_SAR_HW_CTRL_CSRC_VMINUS == (addr)) || \
                                         (CY_SAR_HW_CTRL_CSINK_VPLUS == (addr)) || \
                                         (CY_SAR_HW_CTRL_CSINK_VMINUS == (addr)))
#else
#define CY_HW_DIAGMUX(addr)               (0u)
#define CY_HW_BROKEN_WIRE(addr)           (0u)
#endif /* (4U <= CY_IP_M0S8PASS4A_SAR_VERSION) */

#define CY_SAR_BACKUP_ENABLED  (1UL)
#define CY_SAR_BACKUP_STARTED  (2UL)

static uint32_t Cy_SAR_backup[CY_IP_M0S8PASS4A_SAR_INSTANCES];
/** \endcond */

/* This array is used to calibrate the offset for each channel.
* At initialization, channels that are single-ended, signed, and with Vneg = Vref
* have an offset of -(2^12)/2 = -2048. All other channels have an offset of 0.
* The offset can be overridden using Cy_SAR_SetChannelOffset.
* The channel offsets are used by the Cy_SAR_CountsTo_Volts, Cy_SAR_CountsTo_mVolts, and
* Cy_SAR_CountsTo_uVolts functions to convert counts to voltage.
*/
static int16_t Cy_SAR_offset[CY_SAR_NUM_CHANNELS][CY_IP_M0S8PASS4A_SAR_INSTANCES];

/* This array is used to calibrate the gain for each channel.
* It is set at initialization and the value depends on the SARADC resolution
* and voltage reference, 10*(2^12)/(2*Vref).
* The gain can be overridden using Cy_SAR_SetChannelGain.
* The channel gains are used by the Cy_SAR_CountsTo_Volts, Cy_SAR_CountsTo_mVolts and
* Cy_SAR_CountsTo_uVolts functions to convert counts to voltage.
*/
static int32_t Cy_SAR_countsPer10Volt[CY_SAR_NUM_CHANNELS][CY_IP_M0S8PASS4A_SAR_INSTANCES];

static void Cy_SAR_WaitWhileBusy(SAR_Type * base);

static void Cy_SAR_WaitWhileBusy(SAR_Type * base)
{
    while (Cy_SAR_GetBusyStatus(base))
    {
        /* Wait for SAR to go idle */
    }
}

static bool Cy_SAR_IsBaseAddrValid(const SAR_Type * base)
{
    bool status;

    status = (SAR0 == base);

    #if defined(SAR1)
        status = status || (SAR1 == base);
    #endif

    return status;
}


/*******************************************************************************
* Function Name: Cy_SAR_Init
****************************************************************************//**
*
* Initialize all SAR configuration registers.
* If routing is to be configured, all switches will be cleared before
* being initialized.
*
* \note If interleaved averaging mode is used, the Differential Result Format
*       should be the same as the Single-Ended Result Format. Otherwise, this
*       function will return CY_SAR_BAD_PARAM.
*
* \param base
* Pointer to structure describing SAR instance registers
*
* \param config
* Pointer to structure containing configuration data. See \ref cy_stc_sar_config_t
* and guidance in the \ref group_sar_initialization section.
*
* \return
* - \ref CY_SAR_SUCCESS : initialization complete successfully
* - \ref CY_SAR_BAD_PARAM : input pointers are null or some configuration
                            setting is invalid, initialization incomplete.
*
* \funcusage \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_INIT
*
*******************************************************************************/
cy_en_sar_status_t Cy_SAR_Init(SAR_Type * base, const cy_stc_sar_config_t * config)
{
    cy_en_sar_status_t result = CY_SAR_BAD_PARAM;

    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(NULL != config);

    if (Cy_SAR_IsBaseAddrValid(base) && (NULL != config))
    {
        uint8_t chan;
        int32_t defaultGain;
        uint32_t satIntrMsk = 0UL;   /* Saturation interrupt mask */
        uint32_t rangeIntrMsk = 0UL; /* Range interrupt mask */

        CY_ASSERT_L3(CY_SAR_VREF(config->vrefSel));
        CY_ASSERT_L3(CY_SAR_NEG_SEL(config->negSel));
        CY_ASSERT_L3(CY_SAR_NEG_REF(config->negVref));
        CY_ASSERT_L3(CY_SAR_PWR(config->power));
        CY_ASSERT_L3(CY_SAR_SUB_RES(config->subResolution));
        CY_ASSERT_L3(CY_SAR_AVG(config->avgCnt));
        CY_ASSERT_L3(CY_SAR_TRIGGER(config->trigMode));
        CY_ASSERT_L2(CY_SAR_SAMPLE_TIME(config->sampleTime0));
        CY_ASSERT_L2(CY_SAR_SAMPLE_TIME(config->sampleTime1));
        CY_ASSERT_L2(CY_SAR_SAMPLE_TIME(config->sampleTime2));
        CY_ASSERT_L2(CY_SAR_SAMPLE_TIME(config->sampleTime3));
        CY_ASSERT_L2(CY_SAR_RANGE_LIMIT(config->rangeThresLow));
        CY_ASSERT_L2(CY_SAR_RANGE_LIMIT(config->rangeThresHigh));
        CY_ASSERT_L3(CY_SAR_RANGE_COND(config->rangeCond));
        CY_ASSERT_L2(CY_SAR_INJMASK(config->chanEn));

    #if defined(SAR_CTRL_DSI_SYNC_CONFIG_Msk) && defined(SAR_CTRL_DSI_MODE_Msk)
        SAR_CTRL(base) &= SAR_CTRL_DSI_SYNC_CONFIG_Msk | SAR_CTRL_DSI_MODE_Msk; /* preserve the DSI_SYNC_CONFIG and DSI_MODE fields (and BTW disable the block)  */
    #endif /*defined(SAR_CTRL_DSI_SYNC_CONFIG_Msk) && defined(SAR_CTRL_DSI_MODE_Msk)*/
        SAR_CTRL(base) |= _VAL2FLD(SAR_CTRL_VREF_SEL, config->vrefSel) |
                         _BOOL2FLD(SAR_CTRL_VREF_BYP_CAP_EN, config->vrefBypCapEn) |
                          _VAL2FLD(SAR_CTRL_NEG_SEL, config->negSel) |
                          _VAL2FLD(SAR_CTRL_SAR_HW_CTRL_NEGVREF, config->negVref) |
                         _BOOL2FLD(SAR_CTRL_BOOSTPUMP_EN, config->boostPump) |
                          _VAL2FLD(SAR_CTRL_ICONT_LV, config->power) |
                         _BOOL2FLD(SAR_CTRL_DEEPSLEEP_ON, config->sarMuxDsEn) |
                         _BOOL2FLD(SAR_CTRL_SWITCH_DISABLE, config->switchDisable);

        SAR_SAMPLE_CTRL(base) &= SAR_SAMPLE_CTRL_DSI_SYNC_TRIGGER_Msk; /* preserve the DSI_SYNC_TRIGGER field  */
        SAR_SAMPLE_CTRL(base) |= _VAL2FLD(SAR_SAMPLE_CTRL_SUB_RESOLUTION, config->subResolution) |
                                _BOOL2FLD(SAR_SAMPLE_CTRL_LEFT_ALIGN, config->leftAlign) |
                                _BOOL2FLD(SAR_SAMPLE_CTRL_SINGLE_ENDED_SIGNED, config->singleEndedSigned) |
                                _BOOL2FLD(SAR_SAMPLE_CTRL_DIFFERENTIAL_SIGNED, config->differentialSigned) |
                                 _VAL2FLD(SAR_SAMPLE_CTRL_AVG_CNT, config->avgCnt) |
                                _BOOL2FLD(SAR_SAMPLE_CTRL_AVG_SHIFT, config->avgShift) |
                                 _VAL2FLD(SAR_SAMPLE_CTRL_DSI_TRIGGER_MODE, config->trigMode) |
                                _BOOL2FLD(SAR_SAMPLE_CTRL_EOS_DSI_OUT_EN, config->eosEn);

        SAR_SAMPLE_TIME01(base) = _VAL2FLD(SAR_SAMPLE_TIME01_SAMPLE_TIME0, config->sampleTime0) |
                                  _VAL2FLD(SAR_SAMPLE_TIME01_SAMPLE_TIME1, config->sampleTime1);
        SAR_SAMPLE_TIME23(base) = _VAL2FLD(SAR_SAMPLE_TIME23_SAMPLE_TIME2, config->sampleTime2) |
                                  _VAL2FLD(SAR_SAMPLE_TIME23_SAMPLE_TIME3, config->sampleTime3);
        SAR_RANGE_THRES(base) = _VAL2FLD(SAR_RANGE_THRES_RANGE_LOW, config->rangeThresLow) |
                                _VAL2FLD(SAR_RANGE_THRES_RANGE_HIGH, config->rangeThresHigh);
        SAR_RANGE_COND(base) = _VAL2FLD(SAR_RANGE_COND_RANGE_COND, config->rangeCond);

        /* Calculate the default gain for all the channels in counts per 10 volts with rounding */
        defaultGain = (int32_t)(uint16_t)CY_SYSLIB_DIV_ROUND(CY_SAR_WRK_MAX_12BIT * CY_SAR_10MV_COUNTS / 2UL, config->vrefMvValue);

        SAR_CHAN_EN(base) = _VAL2FLD(SAR_CHAN_EN_CHAN_EN, config->chanEn);

        for (chan = 0u; chan < CY_SAR_NUM_CHANNELS; chan++)
        {
            const cy_stc_sar_channel_config_t * locChanCfg = config->channelConfig[chan];

            if (NULL != locChanCfg)
            {
                CY_ASSERT_L3(CY_SAR_ADDR(locChanCfg->addr) || CY_SAR_DIAG(locChanCfg->addr) || CY_SAR_EXP_ADDR(locChanCfg->addr));
#if defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)
                if (locChanCfg->negAddrEn)
                {
                    CY_ASSERT_L3(CY_SAR_NEG_ADDR(locChanCfg->neg_addr) || \
                                 CY_SAR_NEG_DIAG(locChanCfg->neg_addr) || \
                                 CY_SAR_EXP_NEG_ADDR(locChanCfg->neg_addr));
                }
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */
                CY_ASSERT_L3(CY_SAR_RESOLUTION(locChanCfg->resolution));
                CY_ASSERT_L2(CY_SAR_SAMPLE_TIMER(locChanCfg->sampleTimeSel));

                if (chan < CY_SAR_INJ_CHANNEL)
                {
                    SAR_CHAN_CONFIG(base, chan) = _VAL2FLD(SAR_CHAN_CONFIG_ADDR, locChanCfg->addr) |
                                                 _BOOL2FLD(SAR_CHAN_CONFIG_DIFFERENTIAL_EN, locChanCfg->differential) |
                                                  _VAL2FLD(SAR_CHAN_CONFIG_RESOLUTION, locChanCfg->resolution) |
                                                 _BOOL2FLD(SAR_CHAN_CONFIG_AVG_EN, locChanCfg->avgEn) |
#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION))
                                                 _VAL2FLD(SAR_CHAN_CONFIG_SAMPLE_TIME_SEL, locChanCfg->sampleTimeSel) |
                                                 _VAL2FLD(SAR_CHAN_CONFIG_NEG_ADDR, locChanCfg->neg_addr) |
                                                 _BOOL2FLD(SAR_CHAN_CONFIG_NEG_ADDR_EN, locChanCfg->negAddrEn) |
                                                 _BOOL2FLD(SAR_CHAN_CONFIG_DIAG_VPLUS_SOURCE, locChanCfg->diagVplusSource) |
                                                 _BOOL2FLD(SAR_CHAN_CONFIG_DIAG_VPLUS_SINK, locChanCfg->diagVplusSink) |
                                                 _BOOL2FLD(SAR_CHAN_CONFIG_DIAG_VMINUS_SOURCE, locChanCfg->diagVminusSoure) |
                                                 _BOOL2FLD(SAR_CHAN_CONFIG_DIAG_VMINUS_SINK, locChanCfg->diagVminusSink);
#else
                                                  _VAL2FLD(SAR_CHAN_CONFIG_SAMPLE_TIME_SEL, locChanCfg->sampleTimeSel);
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */
                }
                else
                {
                    SAR_INJ_CHAN_CONFIG(base) = _VAL2FLD(SAR_CHAN_CONFIG_ADDR, locChanCfg->addr) |
                                               _BOOL2FLD(SAR_INJ_CHAN_CONFIG_INJ_DIFFERENTIAL_EN, locChanCfg->differential) |
                                                _VAL2FLD(SAR_INJ_CHAN_CONFIG_INJ_RESOLUTION, locChanCfg->resolution) |
                                               _BOOL2FLD(SAR_INJ_CHAN_CONFIG_INJ_AVG_EN, locChanCfg->avgEn) |
#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION))
                                                 _VAL2FLD(SAR_INJ_CHAN_CONFIG_INJ_SAMPLE_TIME_SEL, locChanCfg->sampleTimeSel) |
                                                 _VAL2FLD(SAR_CHAN_CONFIG_NEG_ADDR, locChanCfg->neg_addr) |
                                                 _BOOL2FLD(SAR_INJ_CHAN_CONFIG_INJ_NEG_ADDR_EN, locChanCfg->negAddrEn) |
                                                 _BOOL2FLD(SAR_INJ_CHAN_CONFIG_INJ_DIAG_VPLUS_SOURCE, locChanCfg->diagVplusSource) |
                                                 _BOOL2FLD(SAR_INJ_CHAN_CONFIG_INJ_DIAG_VPLUS_SINK, locChanCfg->diagVplusSink) |
                                                 _BOOL2FLD(SAR_INJ_CHAN_CONFIG_INJ_DIAG_VMINUS_SOURCE, locChanCfg->diagVminusSoure) |
                                                 _BOOL2FLD(SAR_INJ_CHAN_CONFIG_INJ_DIAG_VMINUS_SINK, locChanCfg->diagVminusSink);
#else
                                                  _VAL2FLD(SAR_INJ_CHAN_CONFIG_INJ_SAMPLE_TIME_SEL, locChanCfg->sampleTimeSel);
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */
                }

                /* For signed single ended channels with NEG_SEL set to VREF,
                 * set the offset to minus half scale to convert results to unsigned format
                 */
                if (!(locChanCfg->differential) && (CY_SAR_NEG_SEL_VREF == config->negSel) && (config->singleEndedSigned))
                {
                    Cy_SAR_offset[chan][CY_SAR_INSTANCE(base)] = (int16_t)CY_SAR_WRK_MAX_12BIT / -2;
                }
                else
                {
                    Cy_SAR_offset[chan][CY_SAR_INSTANCE(base)] = 0;
                }

                Cy_SAR_countsPer10Volt[chan][CY_SAR_INSTANCE(base)] = defaultGain;

                if (chan < CY_SAR_SEQ_NUM_CHANNELS) /* All except the injection channel */
                {
                    if (locChanCfg->rangeIntrEn)
                    {
                        rangeIntrMsk |= 1UL << chan;
                    }

                    if (locChanCfg->satIntrEn)
                    {
                        satIntrMsk |= 1UL << chan;
                    }
                }
                else
                {
                    uint32_t intrMsk = (locChanCfg->rangeIntrEn ? CY_SAR_INTR_INJ_RANGE : 0UL) |
                                       (locChanCfg->satIntrEn ? CY_SAR_INTR_INJ_SATURATE : 0UL);
                    Cy_SAR_ClearInterrupt(base, intrMsk);
                    Cy_SAR_SetInterruptMask(base, intrMsk);
                }
            }
        }

        Cy_SAR_ClearSatInterrupt(base, satIntrMsk);
        Cy_SAR_SetSatInterruptMask(base, satIntrMsk);
        Cy_SAR_ClearRangeInterrupt(base, rangeIntrMsk);
        Cy_SAR_SetRangeInterruptMask(base, rangeIntrMsk);

        /* Set routing related registers if enabled */
        if (NULL != config->routingConfig)
        {
            CY_ASSERT_L2(CY_SAR_SWITCHMASK(config->routingConfig->muxSwitch));
            CY_ASSERT_L2(CY_SAR_SQMASK(config->routingConfig->muxSwitchHwCtrl));

            /* Clear out all the switches so that only the desired switches in the config structure are set. */
            SAR_MUX_SWITCH_CLEAR0(base) = CY_SAR_CLEAR_ALL_SWITCHES;

            SAR_MUX_SWITCH0(base) = config->routingConfig->muxSwitch;
            SAR_MUX_SWITCH_HW_CTRL(base) = config->routingConfig->muxSwitchHwCtrl;
#if defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4u <= CY_IP_M0S8PASS4A_SAR_VERSION)
            SAR_MUX_SWITCH_CLEAR2(base) = CY_SAR_MUX_SWITCH2_MASK;

            SAR_MUX_SWITCH2(base) = config->routingConfig->muxSwitch2;
            SAR_MUX_SWITCH_HW_CTRL2(base) = config->routingConfig->muxSwitchHwCtrl2;
#endif /* 4u <= CY_IP_M0S8PASS4A_SAR_VERSION */
        }

        /* Set the Cap trim if it was trimmed out of range from sflash */
        if ((CY_SAR_CAP_TRIM_MAX == SAR_ANA_TRIM(base)) || (CY_SAR_CAP_TRIM_MIN == SAR_ANA_TRIM(base)))
        {
            SAR_ANA_TRIM(base) = CY_SAR_CAP_TRIM;
        }

        SAR_PUMP_CTRL(base) = (config->boostPump) ? SAR_PUMP_CTRL_ENABLED_Msk : CY_SAR_DEINIT;

        base->DFT_CTRL |= SAR_DFT_CTRL_DCEN_Msk; /* DRIVERS-7100, DRIVERS-21118, DRIVERS-21596 */

        result = CY_SAR_SUCCESS;
    }

    return result;
}


/*******************************************************************************
* Function Name: Cy_SAR_DeInit
****************************************************************************//**
*
* Reset SAR registers back to power on reset defaults.
*
* \if Cy_SAR_offset and Cy_SAR_countsPer10Volt arrays are NOT reset. \endif
*
* \param base
* Pointer to structure describing registers
*
* \param deInitRouting
* If true, all SARMUX switches are opened and switch control registers are reset
* to zero. If false, switch registers are untouched.
*
* \return
* - \ref CY_SAR_SUCCESS : de-initialization complete
* - \ref CY_SAR_BAD_PARAM : input pointers are null, de-initialization incomplete
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_DEINIT
*
*******************************************************************************/
cy_en_sar_status_t Cy_SAR_DeInit(SAR_Type * base, bool deInitRouting)
{
    cy_en_sar_status_t result = CY_SAR_BAD_PARAM;

    CY_ASSERT_L1(NULL != base);

    if (NULL != base)
    {
        uint8_t chan;

        SAR_CTRL(base) = CY_SAR_DEINIT;
        SAR_SAMPLE_CTRL(base) = CY_SAR_SAMPLE_CTRL_DEINIT;
        SAR_SAMPLE_TIME01(base) = CY_SAR_SAMPLE_TIME_DEINIT;
        SAR_SAMPLE_TIME23(base) = CY_SAR_SAMPLE_TIME_DEINIT;
        SAR_RANGE_THRES(base) = CY_SAR_DEINIT;
        SAR_RANGE_COND(base) = CY_SAR_DEINIT;
        SAR_CHAN_EN(base) = CY_SAR_DEINIT;
        for (chan = 0u; chan < CY_SAR_SEQ_NUM_CHANNELS; chan++)
        {
            SAR_CHAN_CONFIG(base, chan) = CY_SAR_DEINIT;
        }
        SAR_INJ_CHAN_CONFIG(base) = CY_SAR_DEINIT;
        SAR_INTR_MASK(base) = CY_SAR_DEINIT;
        SAR_SATURATE_INTR_MASK(base) = CY_SAR_DEINIT;
        SAR_RANGE_INTR_MASK(base) = CY_SAR_DEINIT;
        if (true == deInitRouting)
        {
            SAR_MUX_SWITCH_CLEAR0(base) = CY_SAR_CLEAR_ALL_SWITCHES;
            SAR_MUX_SWITCH_HW_CTRL(base) = CY_SAR_DEINIT;
#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION))
            SAR_MUX_SWITCH_CLEAR2(base) = CY_SAR_MUX_SWITCH2_MASK;
            SAR_MUX_SWITCH_HW_CTRL2(base) = CY_SAR_DEINIT;
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */
        }
        SAR_PUMP_CTRL(base) = CY_SAR_DEINIT;

        result = CY_SAR_SUCCESS;
    }

    return result;
}


/*******************************************************************************
* Function Name: Cy_SAR_Enable
****************************************************************************//**
*
* Power up the SAR ADC subsystem block. The hardware is ready to use
* after 2 us, which is included in this function.
*
* \param base
* Pointer to structure describing registers
*
* \return None
*
*******************************************************************************/
void Cy_SAR_Enable(SAR_Type * base)
{
    if (!_FLD2BOOL(SAR_CTRL_ENABLED, SAR_CTRL(base)))
    {
        SAR_CTRL(base) |= SAR_CTRL_ENABLED_Msk;

        /* The block is ready to use 2 us after the enable signal is set high. */
        Cy_SysLib_DelayUs(CY_SAR_2US_DELAY);
    }
}


/*******************************************************************************
* Function Name: Cy_SAR_Disable
****************************************************************************//**
*
* Turn off the hardware block.
*
* \param base
* Pointer to structure describing registers
*
* \return None
*
*******************************************************************************/
void Cy_SAR_Disable(SAR_Type * base)
{
    if (_FLD2BOOL(SAR_CTRL_ENABLED, SAR_CTRL(base)))
    {
        Cy_SAR_WaitWhileBusy(base); /* Wait for SAR to stop conversions before disable */

        SAR_CTRL(base) &= ~SAR_CTRL_ENABLED_Msk;
    }
}


/*******************************************************************************
* Function Name: Cy_SAR_DeepSleep
****************************************************************************//**
*
* This is the preferred routine to prepare the hardware for Deep Sleep.
*
* It will call \ref Cy_SAR_StopConvert to disable continuous conversions
* and wait for SAR conversions to stop before entering Deep Sleep.
* If the SARMUX is not configured for Deep Sleep operation, the entire SAR hardware
* block will be turned off.
*
* \param base
* Pointer to structure describing registers
*
* \return None
*
* \funcusage
*
* This function is used in the \ref Cy_SAR_DeepSleepCallback. There is no
* need to call this function directly.
*
*******************************************************************************/
void Cy_SAR_DeepSleep(SAR_Type * base)
{
    uint32_t ctrlReg = SAR_CTRL(base);

    if (Cy_SAR_IsBaseAddrValid(base) && (0UL != (ctrlReg & SAR_CTRL_ENABLED_Msk)))
    {
        Cy_SAR_backup[CY_SAR_INSTANCE(base)] = CY_SAR_BACKUP_ENABLED |
                                               ((0UL != (SAR_SAMPLE_CTRL(base) & SAR_SAMPLE_CTRL_CONTINUOUS_Msk)) ? CY_SAR_BACKUP_STARTED : 0UL) |
                                               (base->DFT_CTRL & SAR_DFT_CTRL_DCEN_Msk);
        Cy_SAR_StopConvert(base);

        Cy_SAR_WaitWhileBusy(base); /* Wait for SAR to stop conversions before entering low power */

        /* Turn off the entire hardware block only if the SARMUX is not
         * enabled for Deep Sleep operation. */
        if (SAR_CTRL_DEEPSLEEP_ON_Msk != (ctrlReg & SAR_CTRL_DEEPSLEEP_ON_Msk))
        {
            Cy_SAR_Disable(base);
        }
    }

    SAR_CTRL(base) = ctrlReg;
}


/*******************************************************************************
* Function Name: Cy_SAR_Wakeup
****************************************************************************//**
*
* This is the preferred routine to restore the hardware to the state after calling
* \ref Cy_SAR_DeepSleep. Restoring the hardware involves re-enabling the hardware,
* the reference buffer, and continuous scanning if it was previously
* enabled before entering sleep.
*
* \param base
* Pointer to structure describing registers
*
* \sideeffect
* Calling this function without previously calling \ref Cy_SAR_DeepSleep can lead to
* unpredictable results.
*
* \return None
*
* \funcusage
*
* This function is used in the \ref Cy_SAR_DeepSleepCallback. There is no
* need to call this function directly.
*
*******************************************************************************/
void Cy_SAR_Wakeup(SAR_Type * base)
{
    if (Cy_SAR_IsBaseAddrValid(base))
    {
        uint32_t locBackup = Cy_SAR_backup[CY_SAR_INSTANCE(base)];

        if (0UL != (CY_SAR_BACKUP_ENABLED & locBackup))
        {
            Cy_SAR_Enable(base);

            base->DFT_CTRL |= locBackup & SAR_DFT_CTRL_DCEN_Msk;

            if (0UL != (CY_SAR_BACKUP_STARTED & locBackup))
            {
                Cy_SAR_StartConvert(base, CY_SAR_START_CONVERT_CONTINUOUS);
            }
        }

        Cy_SAR_backup[CY_SAR_INSTANCE(base)] = 0UL;
    }
}


/*******************************************************************************
* Function Name: Cy_SAR_StartConvert
****************************************************************************//**
*
* Start a single scan (one shot) of all enabled channels or start scanning
* continuously. When in continuous mode, all firmware and hardware triggers
* are ignored. To stop continuous scanning, call \ref Cy_SAR_StopConvert.
*
* \param base
* Pointer to structure describing registers
*
* \param startSelect
* A value of the enum \ref cy_en_sar_start_convert_sel_t
*
* \return None
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_START_CONVERT
*
*******************************************************************************/
void Cy_SAR_StartConvert(SAR_Type * base, cy_en_sar_start_convert_sel_t startSelect)
{
    CY_ASSERT_L3(CY_SAR_STARTCONVERT(startSelect));

    switch(startSelect)
    {
    case CY_SAR_START_CONVERT_CONTINUOUS:
        SAR_SAMPLE_CTRL(base) |= SAR_SAMPLE_CTRL_CONTINUOUS_Msk;
        break;
    case CY_SAR_START_CONVERT_SINGLE_SHOT:
        SAR_START_CTRL(base) = SAR_START_CTRL_FW_TRIGGER_Msk;
        break;
    default:
        /* do nothing */
        break;
    }
}


/*******************************************************************************
* Function Name: Cy_SAR_StopConvert
****************************************************************************//**
*
* Stop continuous scanning of enabled channels.
* If a conversion is currently executing, that conversion will complete,
* but no further conversions will occur until the next call to
* \ref Cy_SAR_StartConvert or the next hardware trigger, if enabled.
*
* \param base
* Pointer to structure describing registers
*
* \return None
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_STOP_CONVERT
*
*******************************************************************************/
void Cy_SAR_StopConvert(SAR_Type * base)
{
    if (0UL != (SAR_SAMPLE_CTRL_CONTINUOUS_Msk & SAR_SAMPLE_CTRL(base)))
    {
        SAR_SAMPLE_CTRL(base) &= ~SAR_SAMPLE_CTRL_CONTINUOUS_Msk;
    }
}


#define CY_SAR_TRIGGER_MODE_Msk (SAR_SAMPLE_CTRL_DSI_TRIGGER_EN_Msk | SAR_SAMPLE_CTRL_DSI_TRIGGER_LEVEL_Msk)
#define CY_SAR_TRIGGER_MODE_Pos (SAR_SAMPLE_CTRL_DSI_TRIGGER_EN_Pos)

/*******************************************************************************
* Function Name: Cy_SAR_SetConvertMode
****************************************************************************//**
*
* Set the mode in which conversions are triggered. This function does
* not start any conversions; it only configures the mode for subsequent conversions.
*
* There are three modes:
*   - firmware only; hardware triggering is disabled
*   - firmware and edge sensitive hardware triggering
*   - firmware and level sensitive hardware triggering
*
* Note that firmware triggering is always enabled.
*
* \param base
* Pointer to structure describing registers
*
* \param mode
* A value of the enum \ref cy_en_sar_sample_ctrl_trigger_mode_t
*
* \funcusage \snippet sar_snippet.c SAR_SNIPPET_SET_CONVERT_MODE
*
*******************************************************************************/
void Cy_SAR_SetConvertMode(SAR_Type * base, cy_en_sar_sample_ctrl_trigger_mode_t mode)
{
    CY_ASSERT_L3(CY_SAR_TRIGGER(mode));

    CY_REG32_CLR_SET(SAR_SAMPLE_CTRL(base), CY_SAR_TRIGGER_MODE, mode);
}


/*******************************************************************************
* Function Name: Cy_SAR_IsEndConversion
****************************************************************************//**
*
* Immediately return the status of the conversion or does not return (blocking)
* until the conversion completes, depending on the retMode parameter.
* In blocking mode, there is a time out of about 10 seconds for a CPU speed of
* 48 MHz.
*
* \param base
* Pointer to structure describing registers
*
* \param retMode
* A value of the enum \ref cy_en_sar_return_mode_t
*
* \return
* - \ref CY_SAR_SUCCESS : the last conversion is complete
* - \ref CY_SAR_CONVERSION_NOT_COMPLETE : the conversion has not completed
* - \ref CY_SAR_TIMEOUT : the watchdog timer has expired in blocking mode
*
* \sideeffect
* This function reads the end of conversion status and clears it after.
*
* \note
* \ref CY_SAR_WAIT_FOR_RESULT and \ref CY_SAR_WAIT_FOR_RESULT_INJ return modes are not recommended,
* especially in RTOS applications, as the timeout is generated by the CPU waiting for a few seconds.
* It is recommended to handle the timeout in the user firmware.
*
* \funcusage \snippet sar/snippet/sar_snippet.c SAR_SNIPPET_POLLING
*
*******************************************************************************/
cy_en_sar_status_t Cy_SAR_IsEndConversion(SAR_Type * base, cy_en_sar_return_mode_t retMode)
{
    CY_ASSERT_L3(CY_SAR_RETURN(retMode));

    cy_en_sar_status_t result;

    uint32_t wdt = 0x2355555UL; /* Watchdog timer for blocking while loop */
    uint32_t mask = ((CY_SAR_RETURN_STATUS_INJ == retMode) || (CY_SAR_WAIT_FOR_RESULT_INJ == retMode)) ? CY_SAR_INTR_INJ_EOC : CY_SAR_INTR_EOS;
    uint32_t intr = mask & Cy_SAR_GetInterruptStatus(base);

    if ((CY_SAR_WAIT_FOR_RESULT == retMode) || (CY_SAR_WAIT_FOR_RESULT_INJ == retMode))
    {
        while ((0UL == intr) && (0UL != wdt))
        {
            intr = mask & Cy_SAR_GetInterruptStatus(base);
            wdt--;
        }
    }

    /* Clear the EOS bit */
    if (mask == intr)
    {
        result = CY_SAR_SUCCESS;
        Cy_SAR_ClearInterrupt(base, mask);
    }
    else if (0UL == wdt)
    {
        result = CY_SAR_TIMEOUT;
    }
    else
    {
        result = CY_SAR_CONVERSION_NOT_COMPLETE;
    }

    return result;
}

/*******************************************************************************
* Function Name: Cy_SAR_GetBusyStatus
****************************************************************************//**
*
* Get SAR conversion status.
*
* \param base
* Pointer to structure describing registers
*
* \return
*  TRUE : SAR conversion is busy.
*  FALSE: SAR conversion is not busy.
*
*******************************************************************************/
bool Cy_SAR_GetBusyStatus(const SAR_Type * base)
{
    return (_FLD2BOOL(SAR_STATUS_BUSY, SAR_STATUS(base)));
}

/*******************************************************************************
* Function Name: Cy_SAR_IsChannelSigned
****************************************************************************//**
*
* Return true if channel result is configured for signed format, else false.
* The formats for single-ended and differential channels are independent.
* This function will first check whether the channel is single-ended or differential.
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel to check, between 0 and \ref CY_SAR_INJ_CHANNEL
*
* \return
* If channel number is invalid, false is returned
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_IS_CHANNEL_SIGNED
*
*******************************************************************************/
bool Cy_SAR_IsChannelSigned(const SAR_Type * base, uint32_t chan)
{
    CY_ASSERT_L2(CY_SAR_CHAN_NUM(chan));

    bool isSigned = false;

    if (chan < CY_SAR_NUM_CHANNELS)
    {
        /* Sign bits are stored separately for differential and single ended channels. */
        if (true == Cy_SAR_IsChannelDifferential(base, chan))
        { /* Differential channel */
            if (SAR_SAMPLE_CTRL_DIFFERENTIAL_SIGNED_Msk == (SAR_SAMPLE_CTRL(base) & SAR_SAMPLE_CTRL_DIFFERENTIAL_SIGNED_Msk))
            {
                isSigned = true;
            }
        }
        else
        { /* Single ended channel */
            if (SAR_SAMPLE_CTRL_SINGLE_ENDED_SIGNED_Msk == (SAR_SAMPLE_CTRL(base) & SAR_SAMPLE_CTRL_SINGLE_ENDED_SIGNED_Msk))
            {
                isSigned = true;
            }
        }
    }

    return isSigned;
}


/*******************************************************************************
* Function Name: Cy_SAR_IsChannelSingleEnded
****************************************************************************//**
*
* Return true if channel is single ended, else false
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel to check, between 0 and \ref CY_SAR_INJ_CHANNEL
*
* \return
* If channel number is invalid, false is returned
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_IS_CHANNEL_SE
*
*******************************************************************************/
bool Cy_SAR_IsChannelSingleEnded(const SAR_Type * base, uint32_t chan)
{
    CY_ASSERT_L2(CY_SAR_CHAN_NUM(chan));

    bool isSingleEnded = false;

    if (chan < CY_SAR_SEQ_NUM_CHANNELS)
    {
#if defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)
        /* if SAR_CHAN_CONFIG_DIFFERENTIAL_EN or SAR_CHAN_CONFIG_NEG_ADDR_EN is TRUE,
           then it's not SingleEnded measure */
        isSingleEnded = !(_FLD2BOOL(SAR_CHAN_CONFIG_DIFFERENTIAL_EN, SAR_CHAN_CONFIG(base, chan)) || \
                         _FLD2BOOL(SAR_CHAN_CONFIG_NEG_ADDR_EN, SAR_CHAN_CONFIG(base, chan)));
#else
        isSingleEnded = !_FLD2BOOL(SAR_CHAN_CONFIG_DIFFERENTIAL_EN, SAR_CHAN_CONFIG(base, chan));
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */
    }
    else if (CY_SAR_INJ_CHANNEL == chan)
    {
#if defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)
        /* if SAR_INJ_CHAN_CONFIG_INJ_DIFFERENTIAL_EN or SAR_INJ_CHAN_CONFIG_INJ_NEG_ADDR_EN is TRUE,
           then it's not SingleEnded injection measure */
        isSingleEnded = !(_FLD2BOOL(SAR_INJ_CHAN_CONFIG_INJ_DIFFERENTIAL_EN, SAR_INJ_CHAN_CONFIG(base)) || \
                          _FLD2BOOL(SAR_INJ_CHAN_CONFIG_INJ_NEG_ADDR_EN, SAR_INJ_CHAN_CONFIG(base)));
#else
        isSingleEnded = !_FLD2BOOL(SAR_INJ_CHAN_CONFIG_INJ_DIFFERENTIAL_EN, SAR_INJ_CHAN_CONFIG(base));
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */
    }
    else
    {
        /* Return false */
    }

    return isSingleEnded;
}


/*******************************************************************************
* Function Name: Cy_SAR_GetResult16
****************************************************************************//**
*
* Return the data available in the channel result data register as a signed
* 16-bit integer.
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel to read the result from, between 0 and \ref CY_SAR_INJ_CHANNEL
*
* \return
* Data is returned as a signed 16-bit integer.
* If channel number is invalid, 0 is returned.
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_GET_RESULT16
*
*******************************************************************************/
int16_t Cy_SAR_GetResult16(const SAR_Type * base, uint32_t chan)
{
    return (int16_t) Cy_SAR_GetResult32(base, chan);
}


/*******************************************************************************
* Function Name: Cy_SAR_GetResult32
****************************************************************************//**
*
* Return the data available in the channel result data register as a signed
* 32-bit integer.
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel to read the result from, between 0 and \ref CY_SAR_INJ_CHANNEL
*
* \return
* Data is returned as a signed 32-bit integer.
* If channel number is invalid, 0 is returned.
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_GET_RESULT32
*
*******************************************************************************/
int32_t Cy_SAR_GetResult32(const SAR_Type * base, uint32_t chan)
{
    CY_ASSERT_L2(CY_SAR_CHAN_NUM(chan));

    uint32_t adcResult = 0UL;

    if (chan < CY_SAR_SEQ_NUM_CHANNELS)
    {
        adcResult = _FLD2VAL(SAR_CHAN_RESULT_RESULT, SAR_CHAN_RESULT(base, chan));
    }
    else if (CY_SAR_INJ_CHANNEL == chan)
    {
        adcResult = _FLD2VAL(SAR_INJ_RESULT_INJ_RESULT, SAR_INJ_RESULT(base));
    }
    else
    {
        /* Return zero */
    }

    return (int32_t) adcResult;
}


/*******************************************************************************
* Function Name: Cy_SAR_SetLowLimit
****************************************************************************//**
*
* Set the low threshold for range detection. The values are interpreted
* as signed or unsigned according to the channel configuration. Range
* detection is done on the value stored in the result register. That is, after
* averaging, shifting sign extension, and left/right alignment.
*
* \param base
* Pointer to structure describing registers
*
* \param lowLimit
* The low threshold for range detection
*
* \return None
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_SET_LOWHIGH_LIMIT
*
*******************************************************************************/
void Cy_SAR_SetLowLimit(SAR_Type * base, uint32_t lowLimit)
{
    CY_ASSERT_L2(CY_SAR_RANGE_LIMIT(lowLimit));

    CY_REG32_CLR_SET(SAR_RANGE_THRES(base), SAR_RANGE_THRES_RANGE_LOW, lowLimit);
}


/*******************************************************************************
* Function Name: Cy_SAR_SetHighLimit
****************************************************************************//**
*
* Set the high threshold for range detection. The values are interpreted
* as signed or unsigned according to the channel configuration. Range
* detection is done on the value stored in the result register. That is, after
* averaging, shifting sign extension, and left/right alignment.
*
* \param base
* Pointer to structure describing registers
*
* \param highLimit
* The high threshold for range detection
*
* \return None
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_SET_LOWHIGH_LIMIT
*
*******************************************************************************/
void Cy_SAR_SetHighLimit(SAR_Type * base, uint32_t highLimit)
{
    CY_ASSERT_L2(CY_SAR_RANGE_LIMIT(highLimit));

    CY_REG32_CLR_SET(SAR_RANGE_THRES(base), SAR_RANGE_THRES_RANGE_HIGH, highLimit);
}


/*******************************************************************************
* Function Name: Cy_SAR_SetVref
****************************************************************************//**
*
* Sets the Vref of the SAR ADC during runtime.
* If Vref = BGR or VDDA/2, API enables the Vref buffer, otherwise, disable the Vref buffer.
* When using this API, the user must:
* *   Stop the ADC before running this function.
* *   Configure the correct gain of channels using Cy_SAR_SetChannelGain for raw count conversations APIs to work properly while using a different Vref.
* *   Allow sufficient time for Vref to settle change when using a bypass cap or the Vref buffer.
*
* \param base
* The pointer to the structure, which describes registers.
*
* \param  vrefSel
* The enumerated type of possible Vref settings \ref cy_en_sar_ctrl_vref_sel_t.
*
*******************************************************************************/
void Cy_SAR_SetVref(SAR_Type *base, cy_en_sar_ctrl_vref_sel_t vrefSel)
{
    CY_ASSERT_L2(CY_SAR_VREF(vrefSel));

    CY_REG32_CLR_SET(SAR_CTRL(base), SAR_CTRL_VREF_SEL, vrefSel);
}


/*******************************************************************************
* Function Name: Cy_SAR_SetChannelOffset
****************************************************************************//**
*
* Store the channel offset for the voltage conversion functions.
*
* Offset is applied to counts before unit scaling and gain.
* See \ref Cy_SAR_CountsTo_Volts for more about this formula.
*
* To change channel 0's offset based on a known positive offset of V_offset_mV, use:
*
*     Cy_SAR_SetChannelOffset(base, chan, -1 * V_offset_mV * (1UL << Resolution) / (2 * V_ref_mV));
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel number, between 0 and \ref CY_SAR_INJ_CHANNEL.
*
* \param offsetCount
* The count value measured when the inputs are shorted or
* connected to the same input voltage.
*
* \return
* - \ref CY_SAR_SUCCESS : offset was set successfully
* - \ref CY_SAR_BAD_PARAM : channel number is equal to or greater than \ref CY_SAR_NUM_CHANNELS
*
*******************************************************************************/
cy_en_sar_status_t Cy_SAR_SetChannelOffset(const SAR_Type * base, uint32_t chan, int16_t offsetCount)
{
    CY_ASSERT_L2(CY_SAR_CHAN_NUM(chan));

    cy_en_sar_status_t result = CY_SAR_BAD_PARAM;

    if (Cy_SAR_IsBaseAddrValid(base) && (chan < CY_SAR_NUM_CHANNELS))
    {
        Cy_SAR_offset[chan][CY_SAR_INSTANCE(base)] = offsetCount;
        result = CY_SAR_SUCCESS;
    }

    return result;
}


/*******************************************************************************
* Function Name: Cy_SAR_SetChannelGain
****************************************************************************//**
*
* Store the gain value for the voltage conversion functions.
* The gain is configured at initialization in \ref Cy_SAR_Init
* based on the SARADC resolution and voltage reference.
*
* Gain is applied after offset and unit scaling.
* See \ref Cy_SAR_CountsTo_Volts for more about this formula.
*
* To change channel 0's gain based on a known V_ref_mV, use:
*
*     Cy_SAR_SetChannelGain(SAR0, 0UL, 10000 * (1UL << Resolution) / (2 * V_ref_mV));
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel number, between 0 and \ref CY_SAR_INJ_CHANNEL.
*
* \param adcGain
* The gain in counts per 10 volt.
*
* \return
* - \ref CY_SAR_SUCCESS : gain was set successfully
* - \ref CY_SAR_BAD_PARAM : channel number is equal to or greater than \ref CY_SAR_NUM_CHANNELS
*
*******************************************************************************/
cy_en_sar_status_t Cy_SAR_SetChannelGain(const SAR_Type * base, uint32_t chan, int32_t adcGain)
{
    CY_ASSERT_L2(CY_SAR_CHAN_NUM(chan));

    cy_en_sar_status_t result = CY_SAR_BAD_PARAM;

    if (Cy_SAR_IsBaseAddrValid(base) && (chan < CY_SAR_NUM_CHANNELS))
    {
        Cy_SAR_countsPer10Volt[chan][CY_SAR_INSTANCE(base)] = adcGain;
        result = CY_SAR_SUCCESS;
    }

    return result;
}


/*******************************************************************************
* Function Name: Cy_SAR_RawCounts2Counts
****************************************************************************//**
*
* Convert the channel result to a consistent result after accounting for
* averaging and subtracting the offset.
* The equation used is:
*
*     Counts = (RawCounts/AvgDivider - Offset)
*
* where,
* - RawCounts: Raw counts from SAR 16-bit CHAN_RESULT register
* - AvgDivider: divider based on averaging mode (\ref cy_stc_sar_config_t::avgShift) and number of samples averaged
*   (\ref cy_stc_sar_config_t::avgCnt)
*   - \ref cy_stc_sar_config_t::avgShift is false : AvgDivider is the number of samples averaged or 16, whichever is smaller
*   - \ref cy_stc_sar_config_t::avgShift is true  : AvgDivider is 1
* - Offset: Value stored by the \ref Cy_SAR_SetChannelOffset function.
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel number, between 0 and \ref CY_SAR_INJ_CHANNEL
*
* \param adcCounts
* Conversion result from \ref Cy_SAR_GetResult16
*
* \return
* adcCounts after averaging and offset adjustments.
* If channel number is invalid, adcCounts is returned unmodified.
*
* \funcusage
*
* This function is used by \ref Cy_SAR_CountsTo_Volts, \ref Cy_SAR_CountsTo_mVolts,
* and \ref Cy_SAR_CountsTo_uVolts. Calling this function directly is usually
* not needed.
*
*******************************************************************************/
int16_t Cy_SAR_RawCounts2Counts(const SAR_Type * base, uint32_t chan, int16_t adcCounts)
{
    int16_t retVal = adcCounts;

    /* Sub-resolution multiplier: 4 for 10 bit and 16 for 8 bit */
    int16_t subResMul = ((uint32_t)CY_SAR_SUB_RESOLUTION_10B == _FLD2VAL(SAR_SAMPLE_CTRL_SUB_RESOLUTION, SAR_SAMPLE_CTRL(base))) ? 4 : 16;

    CY_ASSERT_L2(CY_SAR_CHAN_NUM(chan));

    if (Cy_SAR_IsBaseAddrValid(base) && (chan < CY_SAR_NUM_CHANNELS))
    {
        /* Divide the adcCount when accumulate averaging mode selected */
        if (!_FLD2BOOL(SAR_SAMPLE_CTRL_AVG_SHIFT, SAR_SAMPLE_CTRL(base)))
        {
            /* If channel uses averaging */
            if (((chan < CY_SAR_SEQ_NUM_CHANNELS) && _FLD2BOOL(SAR_CHAN_CONFIG_AVG_EN,         SAR_CHAN_CONFIG(base, chan))) ||
                ((chan == CY_SAR_INJ_CHANNEL)     && _FLD2BOOL(SAR_INJ_CHAN_CONFIG_INJ_AVG_EN, SAR_INJ_CHAN_CONFIG(base))))
            {
                /* Divide by 2^(AVG_CNT + 1) */
                uint32_t averageAdcSamplesDiv = 1UL << (_FLD2VAL(SAR_SAMPLE_CTRL_AVG_CNT, SAR_SAMPLE_CTRL(base)) + 1UL);

                /* Divider limit is 16 */
                if (averageAdcSamplesDiv > 16UL)
                {
                    averageAdcSamplesDiv = 16UL;
                }

                /* If unsigned format, prevent sign extension */
                if (false == Cy_SAR_IsChannelSigned(base, chan))
                {
                    retVal = (int16_t)(uint32_t)((uint16_t) retVal / averageAdcSamplesDiv);
                }
                else
                {
                    retVal /= (int16_t) averageAdcSamplesDiv;
                }
            }
        }

        /* Subtract ADC offset */
        retVal -= Cy_SAR_offset[chan][CY_SAR_INSTANCE(base)];

        /* If sub-resolution is used */
        if (CY_SAR_SEQ_NUM_CHANNELS > chan)
        {
            if (_FLD2BOOL(SAR_CHAN_CONFIG_RESOLUTION, SAR_CHAN_CONFIG(base, chan)))
            {
                retVal *= subResMul;
            }
        }
        else /* injection channel */
        {
            if (_FLD2BOOL(SAR_INJ_CHAN_CONFIG_INJ_RESOLUTION, SAR_INJ_CHAN_CONFIG(base)))
            {
                retVal *= subResMul;
            }
        }
    }

    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SAR_CountsTo_Volts
****************************************************************************//**
*
* Convert the ADC output to Volts as a float32. For example, if the ADC
* measured 0.534 volts, the return value would be 0.534.
* The calculation of voltage depends on the channel offset, gain and other parameters.
* The equation used is:
*
*     V = (RawCounts/AvgDivider - Offset)*TEN_VOLT/Gain
*
* where,
* - RawCounts: Raw counts from SAR 16-bit CHAN_RESULT register
* - AvgDivider: divider based on averaging mode (\ref cy_stc_sar_config_t::avgShift) and number of samples averaged
*   (\ref cy_en_sar_sample_ctrl_avg_cnt_t)
*   - \ref cy_stc_sar_config_t::avgShift is false : AvgDivider is the number of samples averaged or 16, whichever is smaller
*   - \ref cy_stc_sar_config_t::avgShift is true  : AvgDivider is 1
* - Offset: Value stored by the \ref Cy_SAR_SetChannelOffset function.
* - TEN_VOLT: 10 V constant since the gain is in counts per 10 volts.
* - Gain: Value stored by the \ref Cy_SAR_SetChannelGain function.
*
* \note
* This function is only valid when result alignment is right aligned.
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel number, between 0 and \ref CY_SAR_INJ_CHANNEL
*
* \param adcCounts
* Conversion result from \ref Cy_SAR_GetResult16
*
* \return
* Result in Volts.
* - If channel number is invalid, 0 is returned.
* - If channel is left aligned, 0 is returned.
*
* \funcusage \snippet sar_snippet.c SNIPPET_SAR_COUNTSTO_VOLTS
*
*******************************************************************************/
float32_t Cy_SAR_CountsTo_Volts(const SAR_Type * base, uint32_t chan, int16_t adcCounts)
{
    CY_ASSERT_L2(CY_SAR_CHAN_NUM(chan));

    float32_t result_Volts = 0.0f;

    if (Cy_SAR_IsBaseAddrValid(base) && (chan < CY_SAR_NUM_CHANNELS))
    {
        if (CY_SAR_RIGHT_ALIGN)
        {
            result_Volts = (float32_t)Cy_SAR_RawCounts2Counts(base, chan, adcCounts) * CY_SAR_10V_COUNTS;
            result_Volts /= (float32_t)Cy_SAR_countsPer10Volt[chan][CY_SAR_INSTANCE(base)];
        }
    }

    return result_Volts;
}


/*******************************************************************************
* Function Name: Cy_SAR_CountsTo_mVolts
****************************************************************************//**
*
* Convert the ADC output to millivolts as an int16. For example, if the ADC
* measured 0.534 volts, the return value would be 534.
* The calculation of voltage depends on the channel offset, gain and other parameters.
* The equation used is:
*
*     V = (RawCounts/AvgDivider - Offset)*TEN_VOLT/Gain
*     mV = V * 1000
*
* where,
* - RawCounts: Raw counts from SAR 16-bit CHAN_RESULT register
* - AvgDivider: divider based on averaging mode (\ref cy_stc_sar_config_t::avgShift) and number of samples averaged
*   (\ref cy_en_sar_sample_ctrl_avg_cnt_t)
*   - \ref cy_stc_sar_config_t::avgShift is false : AvgDivider is the number of samples averaged or 16, whichever is smaller
*   - \ref cy_stc_sar_config_t::avgShift is true  : AvgDivider is 1
* - Offset: Value stored by the \ref Cy_SAR_SetChannelOffset function.
* - TEN_VOLT: 10 V constant since the gain is in counts per 10 volts.
* - Gain: Value stored by the \ref Cy_SAR_SetChannelGain function.
*
* \note
* This function is only valid when result alignment is right aligned.
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel number, between 0 and \ref CY_SAR_INJ_CHANNEL
*
* \param adcCounts
* Conversion result from \ref Cy_SAR_GetResult16
*
* \return
* Result in millivolts.
* - If channel number is invalid, 0 is returned.
* - If channel is left aligned, 0 is returned.
*
* \funcusage \snippet sar_snippet.c SNIPPET_SAR_COUNTSTO_MVOLTS
*
*******************************************************************************/
int16_t Cy_SAR_CountsTo_mVolts(const SAR_Type * base, uint32_t chan, int16_t adcCounts)
{
    CY_ASSERT_L2(CY_SAR_CHAN_NUM(chan));

    int32_t result_mVolts = 0;

    if (Cy_SAR_IsBaseAddrValid(base) && (chan < CY_SAR_NUM_CHANNELS))
    {
        if (CY_SAR_RIGHT_ALIGN)
        {
            int32_t locCounts = (int32_t)Cy_SAR_RawCounts2Counts(base, chan, adcCounts);

            result_mVolts = (locCounts * (int32_t)CY_SAR_10MV_COUNTS);
            if (locCounts > 0)
            {
                result_mVolts += Cy_SAR_countsPer10Volt[chan][CY_SAR_INSTANCE(base)] / 2;
            }
            else
            {
                result_mVolts -= Cy_SAR_countsPer10Volt[chan][CY_SAR_INSTANCE(base)] / 2;
            }
            result_mVolts /= Cy_SAR_countsPer10Volt[chan][CY_SAR_INSTANCE(base)];
        }
    }

    return (int16_t) result_mVolts;
}


/*******************************************************************************
* Function Name: Cy_SAR_CountsTo_uVolts
****************************************************************************//**
*
* Convert the ADC output to microvolts as a int32. For example, if the ADC
* measured 0.534 volts, the return value would be 534000.
* The calculation of voltage depends on the channel offset, gain and other parameters.
* The equation used is:
*
*     V = (RawCounts / AvgDivider - Offset) * (TEN_VOLT / 10) / (Gain / 10)
*     uV = V * 1000000
*
* where,
* - RawCounts: Raw counts from SAR 16-bit CHAN_RESULT register
* - AvgDivider: divider based on averaging mode (\ref cy_stc_sar_config_t::avgShift) and number of samples averaged
*   (\ref cy_en_sar_sample_ctrl_avg_cnt_t)
*   - \ref cy_stc_sar_config_t::avgShift is false : AvgDivider is the number of samples averaged or 16, whichever is smaller
*   - \ref cy_stc_sar_config_t::avgShift is true  : AvgDivider is 1
* - Offset: Value stored by the \ref Cy_SAR_SetChannelOffset function.
* - TEN_VOLT: 10 V constant since the gain is in counts per 10 volts.
* - Gain: Value stored by the \ref Cy_SAR_SetChannelGain function.
* - TEN_VOLT and Gain are divided by 10 to avoid extremely flash consuming 64-bit math.
*
* \note
* This function is only valid when result alignment is right aligned.
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel number, between 0 and \ref CY_SAR_INJ_CHANNEL
*
* \param adcCounts
* Conversion result from \ref Cy_SAR_GetResult16
*
* \return
* Result in microvolts.
* - If channel number is invalid, 0 is returned.
* - If channel is left aligned, 0 is returned.
*
* \funcusage \snippet sar_snippet.c SNIPPET_SAR_COUNTSTO_UVOLTS
*
*******************************************************************************/
int32_t Cy_SAR_CountsTo_uVolts(const SAR_Type * base, uint32_t chan, int16_t adcCounts)
{
    CY_ASSERT_L2(CY_SAR_CHAN_NUM(chan));

    int32_t result_uVolts = 0;

    if (Cy_SAR_IsBaseAddrValid(base) && (chan < CY_SAR_NUM_CHANNELS))
    {
        if (CY_SAR_RIGHT_ALIGN)
        {
            /* Scale coefficients by 10 to do not overflow 32-bit math */
            result_uVolts = (int32_t)Cy_SAR_RawCounts2Counts(base, chan, adcCounts) * ((int32_t)CY_SAR_10UV_COUNTS / 10L);
            result_uVolts /= Cy_SAR_countsPer10Volt[chan][CY_SAR_INSTANCE(base)] / 10L;
        }
    }

    return (result_uVolts);
}


/*     DieTemp     */

#define CY_TEMP_MULT              (0x400L)    /* 2^10 - the SFLASH.SAR_TEMP_OFFSET multiplier */
#define CY_TEMP_DIV               (0x10000L)  /* 1 in Q16.16 format */
#define CY_TEMP_HALF              (0x8000L)   /* 0.5 in Q16.16 format */

#ifndef CY_TEMP_VREF
#define CY_TEMP_VREF              (1200L)     /* DieTemp reference voltage */
#endif/*CY_TEMP_VREF*/

#ifndef CY_TEMP_SCALE_MULT
#define CY_TEMP_SCALE_MULT        (0x8L)      /* Scale adjustment multiplier (effectively 0.5 << 4) 0.5 in Q28.4 format */
#endif/*CY_TEMP_SCALE_MULT*/

#ifndef CY_TEMP_SCALE_DIV
#define CY_TEMP_SCALE_DIV         (0x10L)     /* Scale adjustment divider (effectively 1 << 4) 1 in Q28.4 format */
#endif/*CY_TEMP_SCALE_DIV*/

#ifndef CY_TEMP_CENT
#define CY_TEMP_CENT              (0xF0000L)  /* Dual slope correction center value 15 degrees Celsius in Q16.16 format */
#endif/*CY_TEMP_CENT*/

#ifndef CY_TEMP_HIGH
#define CY_TEMP_HIGH              (0x640000L) /* 100 degrees Celsius in Q16.16 format */
#endif/*CY_TEMP_HIGH*/

#ifndef CY_TEMP_LOW
#define CY_TEMP_LOW               (0x280000L) /* 40 degrees Celsius in Q16.16 format */
#endif/*CY_TEMP_LOW*/

/*******************************************************************************
* Function Name: Cy_SAR_CountsTo_degreeC
****************************************************************************//**
*
* Converts the ADC output to degrees Celsius.
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel number, between 0 and \ref CY_SAR_INJ_CHANNEL
*
* \param adcCounts
* Conversion result from \ref Cy_SAR_GetResult16
*
* \note In case of ADC Vref doesn't match the DieTemp sensor Vref this function
*       automatically corrects the adcCounts to match the DieTemp Vref.
*
* \return The die temperature in degrees Celsius.
*         If any of base or chan parameters is valid, 0 is returned.
*
* \funcusage \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_TEMP
* Also please refer the \ref group_sar_sarmux_dietemp
*
*******************************************************************************/
int16_t Cy_SAR_CountsTo_degreeC(const SAR_Type * base, uint32_t chan, int16_t adcCounts)
{
    CY_ASSERT_L2(CY_SAR_CHAN_NUM(chan));

    int16_t retVal = 0;

    if (Cy_SAR_IsBaseAddrValid(base) && (chan < CY_SAR_NUM_CHANNELS))
    {
        /* Calculate the Vref back from the defaultGain */
        int32_t temp = (int32_t)(uint16_t)CY_SYSLIB_DIV_ROUND(CY_SAR_WRK_MAX_12BIT * CY_SAR_10MV_COUNTS / 2UL, (uint32_t)Cy_SAR_countsPer10Volt[chan][CY_SAR_INSTANCE(base)]);

        /* Correct the ADC counts depending on the ADC Vref */
        if (CY_TEMP_VREF != temp)
        {
            temp *= (int32_t)adcCounts;
            temp /= CY_TEMP_VREF;
        }
        else
        {
            temp = (int32_t)adcCounts;
        }

        /* Calculate tInitial in Q16.16 */
        temp = ((int16_t)SFLASH->SAR_TEMP_MULTIPLIER * temp) +
               ((int16_t)SFLASH->SAR_TEMP_OFFSET * CY_TEMP_MULT);

        if(temp >= CY_TEMP_CENT)
        {
            /* Shift (tHigh - tInitial) by 4 bits to prevent scale-adjustment from overflowing. */
            /* Then divide by the integer bits of (tHigh - tCent) to end up with a Q16.16 tAdjust */
            temp += (CY_TEMP_SCALE_MULT * ((CY_TEMP_HIGH - temp) / CY_TEMP_SCALE_DIV)) /
                   ((CY_TEMP_HIGH - CY_TEMP_CENT) / CY_TEMP_DIV);
        }
        else
        {
            /* Shift (tLow + tInitial) by 4 bits to prevent scale-adjustment from overflowing. */
            /* Then divide by the integer bits of (tLow + tCent) to end up with a Q16.16 tAdjust */
            temp += (CY_TEMP_SCALE_MULT * ((CY_TEMP_LOW + temp) / CY_TEMP_SCALE_DIV)) /
                   ((CY_TEMP_LOW + CY_TEMP_CENT) / CY_TEMP_DIV);
        }

        retVal = (int16_t)((temp + CY_TEMP_HALF) / CY_TEMP_DIV);
    }

    /* Add tInitial + tAdjust + 0.5 to round to nearest int. Shift off frac bits, and return. */
    return (retVal);
}

#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4u <= CY_IP_M0S8PASS4A_SAR_VERSION)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SAR_SetDiagSwitch
****************************************************************************//**
*
*  Firmware control for EXPMUX and DIAGMUX switches to connect analog signals to the SAR
*
* \param base
* Pointer to structure describing registers
*
* \param mask
*  MUX_SWITCH2 mask value
* The mask to open or close switches.
* Select one or more values from the \ref group_sar_diag_exp_mux_switch
* and "OR" them together.
*
* \param setSwitch
*  Mode (false: Clear mask pattern, true:Set mask pattern)
*
* \return
*  None
*
* \note Applicable to PSOC4 HVMS/PA only.
*
*******************************************************************************/
void Cy_SAR_SetDiagSwitch(const SAR_Type * base, uint32_t mask, bool setSwitch)
{
    CY_ASSERT_L2(CY_EXP_VPLUS(mask) || \
                 CY_EXP_VMINUS(mask) || \
                 CY_DIAG_VPLUS(mask) || \
                 CY_DIAG_VMINUS(mask) || \
                 CY_BROKEN_WIRE(mask));

    if(setSwitch)
    {
        SAR_MUX_SWITCH2(base) = mask;
    }
    else
    {
        SAR_MUX_SWITCH_CLEAR2(base) = mask;
    }
}

/*******************************************************************************
* Function Name: Cy_SAR_GetDiagSwitch
****************************************************************************//**
*
*  Get control state for EXPMUX and DIAGMUX switches
*
* \param base
* Pointer to structure describing registers
*
* \return
* Mask which represent DiagSwitches
* return 0 if no valid switch2 present
*
* \note Applicable to PSOC4 HVMS/PA only.
*
*******************************************************************************/
uint32_t Cy_SAR_GetDiagSwitch(const SAR_Type * base)
{
    return SAR_MUX_SWITCH2(base);
}

/*******************************************************************************
* Function Name: Cy_SAR_SetDiagHwCtrl
****************************************************************************//**
*
*  Set MUX_SWITCH_HW_CTRL2 register value.
*
* \param base
* Pointer to structure describing registers
*
* \param mask
* The mask of the MUX_SWITCH_HW_CTRL2 switches to allow SARSEQ control.
* Select one or more values from the \ref group_sar_diag_exp_mux_switch
* and "OR" them together.
*
* \return
*  None
*
* \note Applicable to PSOC4 HVMS/PA only.
*
******************************************************************************/
void Cy_SAR_SetDiagHwCtrl(volatile SAR_Type * base, uint32_t mask)
{
    CY_ASSERT_L2(CY_HW_EXPMUX(mask)  || \
                 CY_HW_DIAGMUX(mask) || \
                 CY_HW_BROKEN_WIRE(mask));

    SAR_MUX_SWITCH_HW_CTRL2(base) = mask;
}

/*******************************************************************************
* Function Name: Cy_SAR_GetDiagHwCtrl
****************************************************************************//**
*
*  Get MUX_SWITCH_HW_CTRL2 register value.
*
* \param base
* Pointer to structure describing registers
*
* \return
* The mask which represents MUX_SWITCH_HW_CTRL2 Switches.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
*******************************************************************************/
uint32_t Cy_SAR_GetDiagHwCtrl(const SAR_Type * base)
{
    return SAR_MUX_SWITCH_HW_CTRL2(base);
}
#endif /* (CY_IP_M0S8PASS4A_SAR_VERSION >= 4u) */


#if defined (SFLASH_HAS_DYNAMIC_IMO)
/*******************************************************************************
* Function Name: Cy_SAR_CountsTo_tenthDegreeC
****************************************************************************//**
*
* Converts the ADC output to tens of degrees Celsius.
* For example, converts 12.3C to 123.
* This is used for converting data from the dietemp sensor.
*
* \param base
* The pointer to the structure, which describes registers.
*
* \param chan
* The channel number, between 0 and \ref CY_SAR_INJ_CHANNEL
*
* \param adcCounts
* Conversion result from \ref Cy_SAR_GetResult16
*
\note If ADC Vref does not match the DieTemp sensor Vref, this function
*       automatically adjusts adcCounts to match DieTemp Vref.
*
* \return The die temperature in tens of degrees Celsius.
*         If any base or channel parameter is invalid, 0 is returned.
*
* \funcusage \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_TEMP
* Also please refer the \ref group_sar_sarmux_dietemp
*
*******************************************************************************/
int16_t Cy_SAR_CountsTo_tenthDegreeC(const SAR_Type *base, uint32_t chan, int16_t adcCounts)
{
    CY_ASSERT_L2(CY_SAR_CHAN_NUM(chan));

    int32_t retVal = 0;
    int32_t t0, t1;
    int32_t c0, c1;
    int32_t temp;
    if (Cy_SAR_IsBaseAddrValid(base) && (chan < CY_SAR_NUM_CHANNELS))
    {
        /* Calculate the Vref back from defaultGain */
        temp = (int32_t)(uint16_t)CY_SYSLIB_DIV_ROUND(CY_SAR_WRK_MAX_12BIT * CY_SAR_10MV_COUNTS / 2UL, (uint32_t)Cy_SAR_countsPer10Volt[chan][CY_SAR_INSTANCE(base)]);

        /* Correct the ADC counts depending on the ADC Vref */
        if (CY_TEMP_VREF != temp)
        {
            temp *= (int32_t)adcCounts;
            temp /= CY_TEMP_VREF;
        }
        else
        {
            temp = (int32_t)adcCounts;
        }

        /* Get interpolation points */
        if (temp > (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_RC_COUNTS)
        {
            t0 = CY_SAR_TEMP_C_TENTH_DEGREE;
            t1 = CY_SAR_TEMP_RC_TENTH_DEGREE;
            c0 = (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_C_COUNTS;
            c1 = (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_RC_COUNTS;
        }
        else if((temp <= (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_RC_COUNTS) &&
                (temp > (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_R_COUNTS))
        {
            t0 = CY_SAR_TEMP_RC_TENTH_DEGREE;
            t1 = CY_SAR_TEMP_R_TENTH_DEGREE;
            c0 = (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_RC_COUNTS;
            c1 = (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_R_COUNTS;
        }
        else if((temp <= (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_R_COUNTS) &&
                (temp > (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_RH_COUNTS))
        {
            t0 = CY_SAR_TEMP_R_TENTH_DEGREE;
            t1 = CY_SAR_TEMP_RH_TENTH_DEGREE;
            c0 = (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_R_COUNTS;
            c1 = (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_RH_COUNTS;
        }
        else
        {
            t0 = CY_SAR_TEMP_RH_TENTH_DEGREE;
            t1 = CY_SAR_TEMP_H_TENTH_DEGREE;
            c0 = (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_RH_COUNTS;
            c1 = (int32_t)CY_SFLASH_IMO_CAL_TEMP->CY_SAR_TEMP_H_COUNTS;
        }

        retVal = (t0 - t1);
        retVal *= (temp - c0);
        temp = (c0 - c1);
        if (0 == temp)
        {
            retVal = 0;
        }
        else
        {
            retVal /= temp;
            retVal += t0;
        }
    }

    return (int16_t)retVal;
}
#endif


/*******************************************************************************
* Function Name: Cy_SAR_SetAnalogSwitch
****************************************************************************//**
*
* Provide firmware control of the SARMUX switches for firmware sequencing.
* Each call to this function can open or close a set of switches.
* Previously configured switches are untouched.
*
* If the SARSEQ is enabled, there is no need to use this function.
*
* \param base
* Pointer to structure describing registers
*
* \param switchMask
* The mask of the switches to either open or close.
* Select one or more values from the \ref group_sar_mux_switch
* and "OR" them together.
*
* \param state
* Open or close the desired switches:
*  - true - open switch
*  - false - close switch.
*
* \note
* This is an advanced function used for the low-level hardware control of the switches.
* This function is not required for a typical SAR sequencer-based application.
*
* \funcusage \snippet sar_snippet.c SAR_SNIPPET_SET_ANALOG_SWITCH
*
*******************************************************************************/
void Cy_SAR_SetAnalogSwitch(SAR_Type * base, uint32_t switchMask, bool state)
{
    CY_ASSERT_L2(CY_SAR_SWITCHMASK(switchMask));

    if (state)
    {
        SAR_MUX_SWITCH0(base) = switchMask;
    }
    else
    {
        SAR_MUX_SWITCH_CLEAR0(base) = switchMask;
    }
}


/*******************************************************************************
* Function Name: Cy_SAR_GetAnalogSwitch
****************************************************************************//**
*
* Return the state (open or close) of SARMUX switches.
*
* \param base
* Pointer to structure describing registers
*
* \return
* Each bit corresponds to a single switch, where a bit value of 0 is open
* and 1 is closed.
* Compare this value to the switch masks in \ref group_sar_mux_switch.
*
* \note
* This is an advanced function used for the low-level hardware control of the switches.
* This function is not required for a typical SAR sequencer-based application.
*
*******************************************************************************/
uint32_t Cy_SAR_GetAnalogSwitch(const SAR_Type * base)
{
    return SAR_MUX_SWITCH0(base);
}


/*******************************************************************************
* Function Name: Cy_SAR_SetSwitchSarSeqCtrl
****************************************************************************//**
*
* Enable or disable SARSEQ control of one or more switches.
* Previously configured switches are untouched.
*
* \param base
* Pointer to structure describing registers
*
* \param switchMask
* The mask of the switches.
* Select one or more values from the cy_en_sar_mux_switch_sq_ctrl_t enum
* and "OR" them together.
*
* \param ctrl
* true - enable, false - disable SARSEQ control.
*
* \note
* This is an advanced function used for the low-level hardware control of the switches.
* This function is not required for a typical SAR sequencer-based application.
*
* \funcusage \snippet sar_snippet.c SAR_SNIPPET_SET_SWITCH_SAR_SEQ_CTRL
*
*******************************************************************************/
void Cy_SAR_SetSwitchSarSeqCtrl(SAR_Type * base, uint32_t switchMask, bool ctrl)
{
    CY_ASSERT_L2(CY_SAR_SQMASK(switchMask));

    if (ctrl)
    {
        SAR_MUX_SWITCH_HW_CTRL(base) |= switchMask;
    }
    else
    {
        SAR_MUX_SWITCH_HW_CTRL(base) &= ~switchMask;
    }
}


/*******************************************************************************
* Function Name: Cy_SAR_DeepSleepCallback
****************************************************************************//**
*
* Callback to prepare the SAR before entering Deep Sleep
* and to re-enable the SAR after exiting Deep Sleep.
*
* \param callbackParams
* Pointer to structure of type \ref cy_stc_syspm_callback_params_t
*
* \param mode
* Callback mode, see \ref cy_en_syspm_callback_mode_t
*
* \return
* See \ref cy_en_syspm_status_t
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_DEEPSLEEP_CALLBACK
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SAR_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode)
{
    if (CY_SYSPM_BEFORE_TRANSITION == mode)
    { /* Actions that should be done before entering the Deep Sleep mode */
        Cy_SAR_DeepSleep((SAR_Type *)callbackParams->base);
    }
    else if (CY_SYSPM_AFTER_TRANSITION == mode)
    { /* Actions that should be done after exiting the Deep Sleep mode */
        Cy_SAR_Wakeup((SAR_Type *)callbackParams->base);
    }
    else
    { /* Does nothing in other modes */
    }

    return (CY_SYSPM_SUCCESS);
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8PASS4A_SAR */

/* [] END OF FILE */
