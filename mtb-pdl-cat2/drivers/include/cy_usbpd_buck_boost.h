/***************************************************************************//**
* \file cy_usbpd_buck_boost.h
* \version 2.110
*
* Provides API declarations of the USBPD Buck Boost Control driver.
*
********************************************************************************
* \copyright
* (c) (2022 - 2025), Cypress Semiconductor Corporation (an Infineon company) or
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
#ifndef _CY_USBPD_BUCK_BOOST_H_
#define _CY_USBPD_BUCK_BOOST_H_

#include "cy_usbpd_common.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

/**
* \addtogroup group_usbpd_buck_boost
* \{
* USBPD VBus Buck Boost driver.
*
* \defgroup group_usbpd_buck_boost_functions Functions
*
*/


#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)

/*
 * Fixed PWM frequency during buck-boost soft start.
 * Shall be configurable depending on hardware configuration
 * to reach soft start threshold during regulation enable.
 */
#define BB_SS_PWM_FREQ_KHZ                          (200u)

/*
 * Fixed PWM duty (in %) during soft start.
 * Shall be configurable depending on hardware configuration
 * to reach VSAFE_5V during buck-boost soft start.
 */
#define BB_SS_PWM_DUTY_PER                          (5u)

/*
 * Buck-boost high-side or top gates (HS1 and HS2) dead time
 * configuration.
 * Possible range is 5nS to 50nS. Configurable value must in multiples of
 * 5nS only.
 */
#ifdef CY_DEVICE_CCG7S
#define BB_GDRV_HS_DEAD_TIME_NS                     (10u)
/*
 * Buck-boost low-side or bottom gates (LS1 and LS2) dead time
 * configuration.
 * Possible range is 5nS to 50nS. Configurable value must in multiples of
 * 5nS only.
 */
#define BB_GDRV_LS_DEAD_TIME_NS                     (10u)
#else
#ifdef CY_DEVICE_CCG7D
#define BB_GDRV_HS_DEAD_TIME_NS                     (5u)
/*
 * Buck-boost low-side or bottom gates (LS1 and LS2) dead time
 * configuration.
 * Possible range is 5nS to 50nS. Configurable value must in multiples of
 * 5nS only.
 */
#define BB_GDRV_LS_DEAD_TIME_NS                     (5u)
#endif /* CY_DEVICE_CCG7D */
#endif /* CY_DEVICE_CCG7S */


/* 20CSA vout_cc bandwidth configuration. */
#define BBCTRL_20CSA_BW_CC_18_KHZ               ((uint32_t)0u)
#define BBCTRL_20CSA_BW_CC_45_KHZ               ((uint32_t)6u)

/* 
 * Non-configurable regulation settings. 
 * Below values must not be modified. 
 */

/* GM of CV amplifier in mS */
#define GM_CV_1P4_MS                            (22u)

/* GM of CC amplifier in mS */
#define GM_CC_0P2_MS                            (2u)

/* CC loop entry detection current in uA */
#define CC_FLAG_CUR_9P6_UA                      ((uint32_t)16u)

/* 20CSA input referred offset in mV negative (N * 0.43mV) */
#define CSA_INPUT_OFFSET_NEG_6P1_MV             (14u)

/* EA source current configuration in uA */
#define EA_PLOAD_20_UA                          ((uint32_t)3u)

/* CC amplifier GM boosting gain from sink */
#define GMBOOSTN_CC_NOBOOST                     ((uint32_t)0u)

/* CC amplifier GM boosting gain from source for 3A PDO */
#define GMBOOSTP_CC_2X_WITH_OFFSET              (12u)

/* CC amplifier GM boosting gain from source for 5A PDO */
#define GMBOOSTP_CC_3P5X                        (7u)

/* BST offset to change from 4V to 4.5V reference */
#define VBST_GDRVI_TRIM_OFFSET_0P5_V            (12u)

/* 40VREG reference selection for active mode 5V */
#define BB_40VREG_5V_VREF_750_MV                (2u)

/* 40VREG inrush detection limit set to maximum in mA. */
#define BB_40VREG_DET_LIM_500_MA                (3u)

/* Transient load detect sample and hold pulse width in BB clock cycles */
#define BBCTRL_TRANS_ILOAD_PW                   (10u)

/* Transient load detect sample and hold period in BB clock cycles */
#define BBCTRL_TRANS_ILOAD_PER                  (58u)

/* 20CSA vout_ocp bandwidth configuration in KHZ. */
#define BBCTRL_20CSA_BW_OCP_100_KHZ             ((uint32_t)0u)

/* Fixed Gain settings */
#define ILIM_DET_GAIN                           (10u)
#define OCP_GAIN_VALUE                          (40u)
#define SCP_GAIN_VALUE                          (20u)
#define CSA_GAIN_VALUE_LOW                      (40u)
#define CSA_GAIN_VALUE_HIGH                     (150u)

/* Maximum CC VREF value allowed*/
#define CC_VREF_VALUE_MAX                       (199u)

/* CCG7D VOUT_MON and VOUT_CBL gain options mask */
#define CSA_VOUT_MON_CBL_GAIN_OPTIONS_MASK      (3u)

/* CCG7D VOUT_MON and VOUT_CBL gain selection */
#define CSA_VOUT_MON_CBL_GAIN_OPTIONS_70_150    (0u)
#define CSA_VOUT_MON_CBL_GAIN_OPTIONS_40_150    (1u)
#define CSA_VOUT_MON_CBL_GAIN_OPTIONS_70_200    (2u)
#define CSA_VOUT_MON_CBL_GAIN_OPTIONS_40_200    (3u)

/* VBST comparator trim data */
#define VBST_GDRVI_TRIM(port) (*(volatile uint8_t *)((0x0ffff151u) + \
        (((uint32_t)(port)) * (0x32u))))
#define VBST_GDRVO_TRIM(port) (*(volatile uint8_t *)((0x0ffff14Fu) + \
        (((uint32_t)(port)) * (0x32u))))

/* PWM trip High to Low and Low to High trim data */
#define BB_PWM_TRIP_BB_1_LH_TRIM(port) (uint32_t)(*(volatile uint8_t *)((0x0ffff4ecu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define BB_PWM_TRIP_BB_2_HL_TRIM(port) (uint32_t)(*(volatile uint8_t *)((0x0ffff4edu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define BB_PWM_TRIP_BOOST_1_HL_TRIM(port) (uint32_t)(*(volatile uint8_t *)((0x0ffff4eeu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define BB_PWM_TRIP_BOOST_2_LH_TRIM(port) (uint32_t)(*(volatile uint8_t *)((0x0ffff4efu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* VBAT_GND SCP trims */
#define VBAT_GND_SCP_TRIM_6A_ROOM(port) (*(volatile uint8_t *)((0x0ffff480u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define VBAT_GND_SCP_TRIM_10A_ROOM(port) (*(volatile uint8_t *)((0x0ffff481u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* VCONN OCP trim */
#define VCONN_OCP_TRIM(port) (*(volatile uint8_t *)((0x0ffff13cu) + \
        (((uint32_t)(port)) * (0x32u))))

/* VCONN OCP offset on CC2 line in steps of 4.8mA */
#define VCONN_OCP_TRIM_CC2_OFFSET       (1u)

/* BB enable target voltage */
#if defined(CY_DEVICE_SERIES_WLC1)
#define BB_ENABLE_VOUT_VOLT                 (4000u)
#else /* !defined(CY_DEVICE_SERIES_WLC1) */
#define BB_ENABLE_VOUT_VOLT                 (5000u)
#endif /* defined(CY_DEVICE_SERIES_WLC1) */

/* BB overvoltage filter debounce time */
#define BB_BAT_OVP_DEBOUNCE                 (0x0Au)

/* CC loop trim settings */

/* Trims flag */
#define CC_TRIM_ROOM_FLAG(port) (*(volatile uint8_t *)((0x0ffff4C6u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* Older silicon. Gain = 70, GM_CC = 0.1mS */
#define CC_GAIN70_TRIM_1A(port) (*(volatile uint8_t *)((0x0ffff49Au) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN70_TRIM_2A(port) (*(volatile uint8_t *)((0x0ffff49Bu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN70_TRIM_3A(port) (*(volatile uint8_t *)((0x0ffff49Cu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN70_TRIM_4A(port) (*(volatile uint8_t *)((0x0ffff49Du) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN70_TRIM_5A(port) (*(volatile uint8_t *)((0x0ffff49Eu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* New silicon. Gain = 60, GM_CC = 0.2mS */
#define CC_GAIN60_GM0P2_TRIM_1A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4BEu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_2A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4BFu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_3A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4C0u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_4A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4C1u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_5A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4C2u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define CC_GAIN60_GM0P2_TRIM_1A_H(port) (*(volatile uint8_t *)((0x0ffff49Cu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_2A_H(port) (*(volatile uint8_t *)((0x0ffff49Du) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_3A_H(port) (*(volatile uint8_t *)((0x0ffff49Eu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_4A_H(port) (*(volatile uint8_t *)((0x0ffff49Fu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_5A_H(port) (*(volatile uint8_t *)((0x0ffff4A0u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define CC_GAIN60_GM0P2_TRIM_1A_C(port) (*(volatile uint8_t *)((0x0ffff4ADu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_2A_C(port) (*(volatile uint8_t *)((0x0ffff4AEu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_3A_C(port) (*(volatile uint8_t *)((0x0ffff4AFu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_4A_C(port) (*(volatile uint8_t *)((0x0ffff4B0u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P2_TRIM_5A_C(port) (*(volatile uint8_t *)((0x0ffff4B1u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* New silicon. Gain = 60, GM_CC = 0.6mS */
#define CC_GAIN60_GM0P6_TRIM_1A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4B6u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_2A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4B7u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_3A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4B8u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_4A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4B9u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_5A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4BAu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define CC_GAIN60_GM0P6_TRIM_1A_H(port) (*(volatile uint8_t *)((0x0ffff494u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_2A_H(port) (*(volatile uint8_t *)((0x0ffff495u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_3A_H(port) (*(volatile uint8_t *)((0x0ffff496u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_4A_H(port) (*(volatile uint8_t *)((0x0ffff497u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_5A_H(port) (*(volatile uint8_t *)((0x0ffff498u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define CC_GAIN60_GM0P6_TRIM_1A_C(port) (*(volatile uint8_t *)((0x0ffff4A5u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_2A_C(port) (*(volatile uint8_t *)((0x0ffff4A6u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_3A_C(port) (*(volatile uint8_t *)((0x0ffff4A7u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_4A_C(port) (*(volatile uint8_t *)((0x0ffff4A8u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN60_GM0P6_TRIM_5A_C(port) (*(volatile uint8_t *)((0x0ffff4A9u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* New silicon. Gain = 80, GM_CC = 0.2mS */
#define CC_GAIN80_GM0P2_TRIM_1A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4C3u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P2_TRIM_2A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4C4u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P2_TRIM_3A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4C5u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define CC_GAIN80_GM0P2_TRIM_1A_H(port) (*(volatile uint8_t *)((0x0ffff4A1u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P2_TRIM_2A_H(port) (*(volatile uint8_t *)((0x0ffff4A2u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P2_TRIM_3A_H(port) (*(volatile uint8_t *)((0x0ffff4A3u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define CC_GAIN80_GM0P2_TRIM_1A_C(port) (*(volatile uint8_t *)((0x0ffff4B2u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P2_TRIM_2A_C(port) (*(volatile uint8_t *)((0x0ffff4B3u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P2_TRIM_3A_C(port) (*(volatile uint8_t *)((0x0ffff4B4u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* New silicon. Gain = 80, GM_CC = 0.6mS */
#define CC_GAIN80_GM0P6_TRIM_1A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4BBu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P6_TRIM_2A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4BCu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P6_TRIM_3A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4BDu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define CC_GAIN80_GM0P6_TRIM_1A_H(port) (*(volatile uint8_t *)((0x0ffff499u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P6_TRIM_2A_H(port) (*(volatile uint8_t *)((0x0ffff49Au) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P6_TRIM_3A_H(port) (*(volatile uint8_t *)((0x0ffff49Bu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define CC_GAIN80_GM0P6_TRIM_1A_C(port) (*(volatile uint8_t *)((0x0ffff4AAu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P6_TRIM_2A_C(port) (*(volatile uint8_t *)((0x0ffff4ABu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN80_GM0P6_TRIM_3A_C(port) (*(volatile uint8_t *)((0x0ffff4ACu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define CC_GAIN40_GM0P6_TRIM_2A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4CCu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN40_GM0P6_TRIM_3A_ROOM(port) (*(volatile uint8_t *)((0x0ffff4CDu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#if PMG1B1_USB_CHARGER

/* PMG1B1 silicon. Gain = 100, GM_CC = 0.6mS.Hot. */
#define CC_GAIN100_GM0P6_TRIM_1A_H(port) (*(volatile uint8_t *)((0x0ffff5CCu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN100_GM0P6_TRIM_2A_H(port) (*(volatile uint8_t *)((0x0ffff5CDu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
/* New silicon. Gain = 110, GM_CC = 0.2mS */
#define CC_GAIN110_GM0P6_TRIM_1A_H(port) (*(volatile uint8_t *)((0x0ffff5CEu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN110_GM0P6_TRIM_2A_H(port) (*(volatile uint8_t *)((0x0ffff5CFu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* PMG1B1 silicon. Gain = 100, GM_CC = 0.2mS.Hot. */
#define CC_GAIN100_GM0P2_TRIM_1A_H(port) (*(volatile uint8_t *)((0x0ffff5D1u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN100_GM0P2_TRIM_2A_H(port) (*(volatile uint8_t *)((0x0ffff5D2u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
/* New silicon. Gain = 110, GM_CC = 0.2mS.Cold. */
#define CC_GAIN110_GM0P2_TRIM_1A_H(port) (*(volatile uint8_t *)((0x0ffff5D3u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN110_GM0P2_TRIM_2A_H(port) (*(volatile uint8_t *)((0x0ffff5D4u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* PMG1B1 silicon. Gain = 100, GM_CC = 0.6mS.Cold. */
#define CC_GAIN100_GM0P6_TRIM_1A_C(port) (*(volatile uint8_t *)((0x0ffff5D7u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN100_GM0P6_TRIM_2A_C(port) (*(volatile uint8_t *)((0x0ffff5D8u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
/* New silicon. Gain = 110, GM_CC = 0.2mS */
#define CC_GAIN110_GM0P6_TRIM_1A_C(port) (*(volatile uint8_t *)((0x0ffff5D9u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN110_GM0P6_TRIM_2A_C(port) (*(volatile uint8_t *)((0x0ffff5DAu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* PMG1B1 silicon. Gain = 100, GM_CC = 0.2mS.Cold. */
#define CC_GAIN100_GM0P2_TRIM_1A_C(port) (*(volatile uint8_t *)((0x0ffff5DCu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN100_GM0P2_TRIM_2A_C(port) (*(volatile uint8_t *)((0x0ffff5DDu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
/* New silicon. Gain = 110, GM_CC = 0.2mS.Cold. */
#define CC_GAIN110_GM0P2_TRIM_1A_C(port) (*(volatile uint8_t *)((0x0ffff5DEu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN110_GM0P2_TRIM_2A_C(port) (*(volatile uint8_t *)((0x0ffff5DFu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* PMG1B1 silicon. Gain = 100, GM_CC = 0.6mS */
#define CC_GAIN100_GM0P6_TRIM_1A_ROOM(port) (*(volatile uint8_t *)((0x0ffff5E2u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN100_GM0P6_TRIM_2A_ROOM(port) (*(volatile uint8_t *)((0x0ffff5E3u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
/* New silicon. Gain = 110, GM_CC = 0.2mS */
#define CC_GAIN110_GM0P6_TRIM_1A_ROOM(port) (*(volatile uint8_t *)((0x0ffff5E4u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN110_GM0P6_TRIM_2A_ROOM(port) (*(volatile uint8_t *)((0x0ffff5E5u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* PMG1B1 silicon. Gain = 100, GM_CC = 0.2mS */
#define CC_GAIN100_GM0P2_TRIM_1A_ROOM(port) (*(volatile uint8_t *)((0x0ffff5E7u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN100_GM0P2_TRIM_2A_ROOM(port) (*(volatile uint8_t *)((0x0ffff5E8u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
/* New silicon. Gain = 110, GM_CC = 0.2mS */
#define CC_GAIN110_GM0P2_TRIM_1A_ROOM(port) (*(volatile uint8_t *)((0x0ffff5E9u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define CC_GAIN110_GM0P2_TRIM_2A_ROOM(port) (*(volatile uint8_t *)((0x0ffff5EAu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#endif /* PMG1B1_USB_CHARGER */



#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)*/



/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_usbpd_buck_boost_functions
* \{
*/

/**
 * Enables the Buck-Boost regulation with soft start.
 * This function should be called to start the regulation with soft
 * start sequence. Cy_USBPD_BB_Init() must have been called prior to this function.
 *
 * \param context
 * USBPD PDSTACK Context pointer.
 */
void Cy_USBPD_BB_Enable(cy_stc_usbpd_context_t *context);

/**
 * Disables the Buck-Boost regulation.
 * This function resets buck-boost operation until Cy_USBPD_BB_Enable() is called.
 *
 * \param context
 * USBPD PDSTACK Context pointer.
 */
void Cy_USBPD_BB_Disable(cy_stc_usbpd_context_t *context);

/**
 * Buck-Boost regulation enable status.
 * This function returns the status of Buck-Boost regulation enable.
 *
 * \param context
 * USBPD PDSTACK Context pointer.
 *
 * \return bool
 * Buck-boost enable status.
 */
bool Cy_USBPD_BB_IsEnabled(cy_stc_usbpd_context_t *context);

/**
 * Buck-Boost regulation ready status.
 * This function returns the Buck-Boost regulation enable
 * sequence done and regulator ready status.
 *
 * \param context
 * USBPD PDSTACK Context pointer.
 *
 * \return bool
 * Buck-boost enable status.
 */
bool Cy_USBPD_BB_IsReady(cy_stc_usbpd_context_t *context);

/**
 * Initializes the Buck-Boost regulation.
 * This function should be called only during USBPD drivers initialization at power up.
 *
 * \param context
 * USBPD PDSTACK Context pointer.
 */
void Cy_USBPD_BB_Init(cy_stc_usbpd_context_t *context);

/**
 * Power Down the Buck-Boost block for power saving.
 * This function should be called only during Deep Sleep entry.
 *
 * \param context
 * USBPD PDSTACK Context pointer.
 */
void Cy_USBPD_BB_PowerDown(cy_stc_usbpd_context_t *context);

/**
 * Power Up the Buck-Boost block for active mode.
 *
 * This function should be called only during Deep Sleep exit.
 *
 * \param context
 * USBPD PDSTACK Context pointer.
 */
void Cy_USBPD_BB_PowerUp(cy_stc_usbpd_context_t *context);


/**
 * Enable Buck-Boost inductor current limit protection.
 *
 * \param context
 * USBPD Context pointer.
 */
void Cy_USBPD_Fault_BbIlimDetEn(cy_stc_usbpd_context_t *context);

/**
 * Disable Buck-Boost inductor current limit protection.
 *
 * \param context
 * USBPD Context pointer.
 */
void Cy_USBPD_Fault_BbIlimDetDis(cy_stc_usbpd_context_t *context);

/** \} group_usbpd_buck_boost_functions */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_BUCK_BOOST_H_ */

/** \} group_usbpd_buck_boost */

/* [] END OF FILE */
