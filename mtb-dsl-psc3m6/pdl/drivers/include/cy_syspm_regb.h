/***************************************************************************//**
* \file cy_syspm_regb.h
* \version 1.0
*
* This file provides header for Regulator Type B Support APIs.
*
********************************************************************************
* \copyright
* (c) 2016-2026, Infineon Technologies AG or an affiliate of
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
#if !defined (CY_SYSPM_REGB_H)
#define CY_SYSPM_REGB_H

#include "cy_device.h"

#if defined(CY_IP_MXS22SRSS) && defined(CY_IP_MXS22SRSS_VERSION) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1) && defined(CY_DEVICE_PSB3)

#ifdef __cplusplus
extern "C" {
#endif

/**
* \addtogroup group_syspm_regb
* \{
*
* Regulator Set B specific functions: Used in target products that need high current
* low noise rails and possibly multiple core voltage islands. A switching regulator/
* buck regulator generates an intermediate supply rail (vcci) with stepdown regulators
* that create voltage islands from it
*
* Various Sub-Systems within the device can request for operating mode and voltages
* of SR and CLDO. After aggregating the request from every Sub-system, final aggregated
* & target request is applied via PMU power control bus to SR and CLDO.
*
* \defgroup group_syspm_regb_enums                General Enumerated Types
* \defgroup group_syspm_regb_macros               Macros
* \defgroup group_syspm_regb_data_structures      Data Structures
* \defgroup group_syspm_regb_functions            Functions
* \} group_syspm_regb */

/**
* \addtogroup group_syspm_regb_enums
* \{
*/
/**
* This enumeration is used to specify the device sub-system
*/
typedef enum
{
    CY_SYSPM_DEVICE_MCU            = 0U,                           /**< MCU Sub-system */
    CY_SYSPM_DEVICE_BT             = 1U,                           /**< BT Sub-system */
    CY_SYSPM_DEVICE_SUB_SYSTEM_MAX = CY_SYSPM_DEVICE_BT            /**< Device Sub System Max Value */
}cy_en_syspm_device_sub_system_t;

/**
* This enumeration is used to select the output voltage for the
* Switching Regulator. Voltage could be adjusted from 0.55V to 1.18V
* in 10mv steps
*/
typedef enum
{
    CY_SYSPM_SR_VOLTAGE_0_55V = 0U,     /**< 0.55 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_56V = 1U,     /**< 0.56 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_57V = 2U,     /**< 0.57 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_58V = 3U,     /**< 0.58 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_59V = 4U,     /**< 0.59 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_60V = 5U,     /**< 0.60 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_61V = 6U,     /**< 0.61 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_62V = 7U,     /**< 0.62 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_63V = 8U,     /**< 0.63 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_64V = 9U,     /**< 0.64 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_65V = 10U,    /**< 0.65 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_66V = 11U,    /**< 0.66 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_67V = 12U,    /**< 0.67 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_68V = 13U,    /**< 0.68 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_69V = 14U,    /**< 0.69 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_70V = 15U,    /**< 0.70 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_71V = 16U,    /**< 0.71 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_72V = 17U,    /**< 0.72 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_73V = 18U,    /**< 0.73 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_74V = 19U,    /**< 0.74 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_75V = 20U,    /**< 0.75 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_76V = 21U,    /**< 0.76 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_77V = 22U,    /**< 0.77 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_78V = 23U,    /**< 0.78 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_79V = 24U,    /**< 0.79 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_80V = 25U,    /**< 0.80 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_81V = 26U,    /**< 0.81 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_82V = 27U,    /**< 0.82 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_83V = 28U,    /**< 0.83 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_84V = 29U,    /**< 0.84 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_85V = 30U,    /**< 0.85 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_86V = 31U,    /**< 0.86 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_87V = 32U,    /**< 0.87 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_88V = 33U,    /**< 0.88 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_89V = 34U,    /**< 0.89 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_90V = 35U,    /**< 0.90 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_91V = 36U,    /**< 0.91 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_92V = 37U,    /**< 0.92 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_93V = 38U,    /**< 0.93 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_94V = 39U,    /**< 0.94 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_95V = 40U,    /**< 0.95 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_96V = 41U,    /**< 0.96 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_97V = 42U,    /**< 0.97 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_98V = 43U,    /**< 0.98 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_0_99V = 44U,    /**< 0.99 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_00V = 45U,    /**< 1.00 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_01V = 46U,    /**< 1.01 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_02V = 47U,    /**< 1.02 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_03V = 48U,    /**< 1.03 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_04V = 49U,    /**< 1.04 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_05V = 50U,    /**< 1.05 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_06V = 51U,    /**< 1.06 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_07V = 52U,    /**< 1.07 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_08V = 53U,    /**< 1.08 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_09V = 54U,    /**< 1.09 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_10V = 55U,    /**< 1.10 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_11V = 56U,    /**< 1.11 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_12V = 57U,    /**< 1.12 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_13V = 58U,    /**< 1.13 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_14V = 59U,    /**< 1.14 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_15V = 60U,    /**< 1.15 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_16V = 61U,    /**< 1.16 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_17V = 62U,    /**< 1.17 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_1_18V = 63U,    /**< 1.18 V nominal voltage. */
    CY_SYSPM_SR_VOLTAGE_INVALID = 255U, /**< Invalid voltage. */
} cy_en_syspm_sr_voltage_t;

#if defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)
/**
* This enumeration is used to select the output voltage for the
* Core LDO.The Core LDO has a limited regulation range, from 0.70V to 1.01V
*/
typedef enum
{
    CY_SYSPM_CLDO_VOLTAGE_0_55V = 0U,     /**< 0.55 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_56V = 1U,     /**< 0.56 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_57V = 2U,     /**< 0.57 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_58V = 3U,     /**< 0.58 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_59V = 4U,     /**< 0.59 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_60V = 5U,     /**< 0.60 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_61V = 6U,     /**< 0.61 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_62V = 7U,     /**< 0.62 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_63V = 8U,     /**< 0.63 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_64V = 9U,     /**< 0.64 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_65V = 10U,    /**< 0.65 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_66V = 11U,    /**< 0.66 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_67V = 12U,    /**< 0.67 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_68V = 13U,    /**< 0.68 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_69V = 14U,    /**< 0.69 V nominal voltage, bypass only */
    CY_SYSPM_CLDO_VOLTAGE_0_70V = 15U,    /**< 0.70 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_71V = 16U,    /**< 0.71 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_72V = 17U,    /**< 0.72 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_73V = 18U,    /**< 0.73 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_74V = 19U,    /**< 0.74 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_75V = 20U,    /**< 0.75 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_76V = 21U,    /**< 0.76 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_77V = 22U,    /**< 0.77 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_78V = 23U,    /**< 0.78 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_79V = 24U,    /**< 0.79 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_80V = 25U,    /**< 0.80 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_81V = 26U,    /**< 0.81 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_82V = 27U,    /**< 0.82 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_83V = 28U,    /**< 0.83 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_84V = 29U,    /**< 0.84 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_85V = 30U,    /**< 0.85 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_86V = 31U,    /**< 0.86 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_87V = 32U,    /**< 0.87 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_88V = 33U,    /**< 0.88 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_89V = 34U,    /**< 0.89 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_90V = 35U,    /**< 0.90 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_91V = 36U,    /**< 0.91 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_92V = 37U,    /**< 0.92 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_93V = 38U,    /**< 0.93 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_94V = 39U,    /**< 0.94 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_95V = 40U,    /**< 0.95 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_96V = 41U,    /**< 0.96 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_97V = 42U,    /**< 0.97 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_98V = 43U,    /**< 0.98 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_0_99V = 44U,    /**< 0.99 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_1_00V = 45U,    /**< 1.00 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_1_01V = 46U,    /**< 1.01 V nominal voltage. */
    CY_SYSPM_CLDO_VOLTAGE_INVALID = 255U, /**< Invalid voltage. */
}cy_en_syspm_cldo_voltage_t;
#endif // defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)

/**
* This enumeration is used to select the output voltage for the
* High-Voltage LDO. HVLDO include the BTLDO and PALDO
*/
typedef enum
{
    CY_SYSPM_HVLDO_VOLTAGE_1_595V = 0U,    /**< 1.595 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_1_650V = 1U,    /**< 1.650 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_1_705V = 2U,    /**< 1.705 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_1_760V = 3U,    /**< 1.760 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_1_815V = 4U,    /**< 1.815 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_1_870V = 5U,    /**< 1.870 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_1_925V = 6U,    /**< 1.925 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_1_980V = 7U,    /**< 1.980 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_035V = 8U,    /**< 2.035 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_090V = 9U,    /**< 2.090 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_145V = 10U,   /**< 2.145 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_200V = 11U,   /**< 2.200 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_255V = 12U,   /**< 2.255 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_310V = 13U,   /**< 2.310 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_365V = 14U,   /**< 2.365 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_475V = 16U,   /**< 2.475 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_530V = 17U,   /**< 2.530 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_585V = 18U,   /**< 2.585 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_640V = 19U,   /**< 2.640 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_695V = 20U,   /**< 2.695 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_750V = 21U,   /**< 2.750 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_805V = 22U,   /**< 2.805 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_860V = 23U,   /**< 2.860 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_915V = 24U,   /**< 2.915 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_970V = 25U,   /**< 2.970 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_025V = 26U,   /**< 3.025 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_080V = 27U,   /**< 3.080 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_135V = 28U,   /**< 3.135 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_190V = 29U,   /**< 3.190 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_245V = 30U,   /**< 3.245 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_300V = 31U,   /**< 3.3 V nominal voltage. */
}cy_en_syspm_hvldo_voltage_t;


/**
* This enumeration is used to select the Switching Regulator index.
*/
typedef enum
{
    CY_SYSPM_SR_INDEX_DS        = 0U,   /**< Switching Regulator index DS */
    CY_SYSPM_SR_INDEX_ULP       = 1U,   /**< Switching Regulator index ULP */
    CY_SYSPM_SR_INDEX_MF        = 2U,   /**< Switching Regulator index MF */
    CY_SYSPM_SR_INDEX_LP        = 3U,   /**< Switching Regulator index LP */
    CY_SYSPM_SR_INDEX_BEACON_RX = 4U,   /**< Switching Regulator index Beacon RX */
    CY_SYSPM_SR_INDEX_RF_0      = 5U,   /**< Switching Regulator index RF 0 */
    CY_SYSPM_SR_INDEX_RF_1      = 6U,   /**< Switching Regulator index RF 1 */
    CY_SYSPM_SR_INDEX_RF_2      = 7U,   /**< Switching Regulator index RF 2 */
}cy_en_syspm_sr_index_t;

#if defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)
/**
* This enumeration is used to select the CLDO index.
*/
typedef enum{
    CY_SYSPM_CLDO_INDEX_DS        = 0U,   /**< CLDO index DS */
    CY_SYSPM_CLDO_INDEX_ULP       = 1U,   /**< CLDO index ULP */
    CY_SYSPM_CLDO_INDEX_MF        = 2U,   /**< CLDO index MF */
    CY_SYSPM_CLDO_INDEX_LP        = 3U,   /**< CLDO index LP */
}cy_en_syspm_cldo_index_t;
#endif //defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)

#if defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)
/**
* This enumeration is used to select the PALDO control signal.
*/
typedef enum
{
    CY_SYSPM_PALDO_WL_0      = 0U,      /**< PALDO WL0 */
    CY_SYSPM_PALDO_WL_1      = 1U,      /**< PALDO WL1 */
    CY_SYSPM_PALDO_WL_2      = 2U,      /**< PALDO WL2 */
    CY_SYSPM_PALDO_DEFAULT   = 3U,      /**< PALDO Default */
}cy_en_syspm_paldo_control_t;
#endif // defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)

#if defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)
/**
* This enumeration is used to select the BTLDO control signal.
*/
typedef enum
{
    CY_SYSPM_BTLDO_WL_0      = 0U,      /**< BTLDO WL0 */
    CY_SYSPM_BTLDO_WL_1      = 1U,      /**< BTLDO WL1 */
    CY_SYSPM_BTLDO_WL_2      = 2U,      /**< BTLDO WL2 */
    CY_SYSPM_BTLDO_BT_0      = 3U,      /**< BTLDO BT0 */
    CY_SYSPM_BTLDO_BT_1      = 4U,      /**< BTLDO BT1 */
    CY_SYSPM_BTLDO_BT_2      = 5U,      /**< BTLDO BT2 */
    CY_SYSPM_BTLDO_DEFAULT   = 6U,      /**< BTLDO Default */
}cy_en_syspm_btldo_control_t;
#endif // defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)

/**
 * BG chopping startup delay.
 */
typedef enum
{
    CY_SYSPM_BG_CHOP_DELAY_16US        = 0U,    /**< Delay 16us */
    CY_SYSPM_BG_CHOP_DELAY_32US        = 1U,    /**< Delay 32us */
    CY_SYSPM_BG_CHOP_DELAY_64US        = 2U,    /**< Delay 64us */
    CY_SYSPM_BG_CHOP_DELAY_128US       = 3U,    /**< Delay 128us */
}cy_en_syspm_bg_chop_delay_t;

/**
 * SR Frequency Control
 */
typedef enum
{
    CY_SYSPM_SR_FREQ_WL_A    = 0U,       /**< WLAN A-channel */
    CY_SYSPM_SR_FREQ_WL_B    = 1U,       /**< WLAN B-channel */
    CY_SYSPM_SR_FREQ_BT_A    = 2U,       /**< BT A-channel */
    CY_SYSPM_SR_FREQ_BT_B    = 3U,       /**< BT B-channel */
    CY_SYSPM_SR_FREQ_DEFAULT = 4U,       /**< Default */
}cy_en_syspm_sr_frequency_control_type_t;

/**
 * PFM comparator hysteresis adjustment.
 * Affects SR HP PFM operation only.  Higher settings result in faster SR frequency.
 */
typedef enum
{
    CY_SYSPM_SR_MAINCOMP_HYST_16_5 = 0u,    /*< 16.5mV */
    CY_SYSPM_SR_MAINCOMP_HYST_7_5  = 1u,    /*< 7.5mV */
    CY_SYSPM_SR_MAINCOMP_HYST_4_5  = 2u,    /*< 4.5mV */
    CY_SYSPM_SR_MAINCOMP_HYST_2_5  = 3u     /*< 2.5mV */
}cy_en_syspm_sr_maincomp_hyst_t;

/**
 * LPPFM comparator hysteresis adjustment.
 * Affects SR HP LPPFM operation only.  Higher settings result in faster SR frequency.
 */
typedef enum
{
    CY_SYSPM_SR_LPCOMP_HYST_21_6 = 0u,    /**< 21.6 mV */
    CY_SYSPM_SR_LPCOMP_HYST_15_8 = 1u,    /**< 15.8 mV */
    CY_SYSPM_SR_LPCOMP_HYST_10_6 = 2u,    /**< 10.6 mV */
    CY_SYSPM_SR_LPCOMP_HYST_5_2  = 3u     /**< 5.2 mV */
}cy_en_syspm_sr_lpcomp_hyst_t;

#if defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)
/**
* SR-to-CLDO dropout voltage (headroom) requirement.  When SR to CLDO voltage difference
* is below this amount the CLDO will enter Bypass.  10mV per step
*/
typedef enum
{
    CY_SYSPM_CLDO_BYP_THRESHOLD_0MV   = 0u,     /**< CLDO bypass threshold 0mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_10MV  = 1u,     /**< CLDO bypass threshold 10mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_20MV  = 2u,     /**< CLDO bypass threshold 20mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_30MV  = 3u,     /**< CLDO bypass threshold 30mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_40MV  = 4u,     /**< CLDO bypass threshold 40mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_50MV  = 5u,     /**< CLDO bypass threshold 50mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_60MV  = 6u,     /**< CLDO bypass threshold 60mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_70MV  = 7u,     /**< CLDO bypass threshold 70mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_80MV  = 8u,     /**< CLDO bypass threshold 80mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_90MV  = 9u,     /**< CLDO bypass threshold 90mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_100MV = 10u,    /**< CLDO bypass threshold 100mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_110MV = 11u,    /**< CLDO bypass threshold 110mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_120MV = 12u,    /**< CLDO bypass threshold 120mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_130MV = 13u,    /**< CLDO bypass threshold 130mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_140MV = 14u,    /**< CLDO bypass threshold 140mV */
    CY_SYSPM_CLDO_BYP_THRESHOLD_150MV = 15u,    /**< CLDO bypass threshold 150mV */
}cy_en_syspm_cldo_bypass_threshold_t;

/**
* CLDO bypass offset - This is used to offset SR voltage during CLDO bypass transitions
* in order to provide LDO headroom for regulation when bypass exit happens at high
* current load,  as follows:
*      - When SR is rising voltage transition and CLDO is going from Bypass to Regulation
*         the SR will first transition to CLDO target voltage+CLDO_BYP_OFFSET.
*       - Then bypass to regulation handover occurs
*       - Then SR ramps to final voltage
*  10mV per step
*/
typedef enum
{
    CY_SYSPM_CLDO_BYP_OFFSET_0MV   = 0u,    /**< CLDO bypass offset 0mV */
    CY_SYSPM_CLDO_BYP_OFFSET_10MV  = 1u,    /**< CLDO bypass offset 10mV */
    CY_SYSPM_CLDO_BYP_OFFSET_20MV  = 2u,    /**< CLDO bypass offset 20mV */
    CY_SYSPM_CLDO_BYP_OFFSET_30MV  = 3u,    /**< CLDO bypass offset 30mV */
    CY_SYSPM_CLDO_BYP_OFFSET_40MV  = 4u,    /**< CLDO bypass offset 40mV */
    CY_SYSPM_CLDO_BYP_OFFSET_50MV  = 5u,    /**< CLDO bypass offset 50mV */
    CY_SYSPM_CLDO_BYP_OFFSET_60MV  = 6u,    /**< CLDO bypass offset 60mV */
    CY_SYSPM_CLDO_BYP_OFFSET_70MV  = 7u,    /**< CLDO bypass offset 70mV */
    CY_SYSPM_CLDO_BYP_OFFSET_80MV  = 8u,    /**< CLDO bypass offset 80mV */
    CY_SYSPM_CLDO_BYP_OFFSET_90MV  = 9u,    /**< CLDO bypass offset 90mV */
    CY_SYSPM_CLDO_BYP_OFFSET_100MV = 10u,   /**< CLDO bypass offset 100mV */
    CY_SYSPM_CLDO_BYP_OFFSET_110MV = 11u,   /**< CLDO bypass offset 110mV */
    CY_SYSPM_CLDO_BYP_OFFSET_120MV = 12u,   /**< CLDO bypass offset 120mV */
    CY_SYSPM_CLDO_BYP_OFFSET_130MV = 13u,   /**< CLDO bypass offset 130mV */
    CY_SYSPM_CLDO_BYP_OFFSET_140MV = 14u,   /**< CLDO bypass offset 140mV */
    CY_SYSPM_CLDO_BYP_OFFSET_150MV = 15u,   /**< CLDO bypass offset 150mV */
}cy_en_syspm_cldo_bypass_offset_t;
#endif // defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)

/**
* Soft-start time adjust, time to adjust from 0V to 0.8V
*/
typedef enum
{
    CY_SYSPM_SR_SS_TIME_71US       = 0u,  /*< Soft-start time 71us */
    CY_SYSPM_SR_SS_TIME_143US      = 1u,  /*< Soft-start time 143us */
    CY_SYSPM_SR_SS_TIME_37US       = 2u,  /*< Soft-start time 37 us */
    CY_SYSPM_SR_SS_TIME_XXUS      =  3u,  /*< Soft-start time 37us */
}cy_en_syspm_sr_ss_adj_t;

/**
* Peak-current threshold in Switching Regulator LP regulation.
*/
typedef enum
{
    CY_SYSPM_SR_LP_IPEAK_100MA      = 0u,   /*< 100mA peak current threshold */
    CY_SYSPM_SR_LP_IPEAK_133MA      = 1u,   /*< 133mA peak current threshold */
    CY_SYSPM_SR_LP_IPEAK_166MA      = 2u,   /*< 166mA peak current threshold */
    CY_SYSPM_SR_LP_IPEAK_200MA      = 3u,   /*< 200mA peak current threshold */
}cy_en_syspm_sr_lp_ipeak_t;

/**
* Switching Regulator PWM rampgen amplitude.
*/
typedef enum
{
    CY_SYSPM_SR_PWM_RAMP_VOLT_0 = 0,    /*< 98mv @4MHz,  121mv @3.2MHz */
    CY_SYSPM_SR_PWM_RAMP_VOLT_1 = 1,    /*< 73mv @4MHz,  91mv @3.2MHz */
    CY_SYSPM_SR_PWM_RAMP_VOLT_2 = 2,    /*< 49mv @4MHz,  60mv @3.2MHz */
    CY_SYSPM_SR_PWM_RAMP_VOLT_3 = 3,    /*< 24mv @4MHz,  30mv @3.2MHz */
    CY_SYSPM_SR_PWM_RAMP_VOLT_4 = 4,    /*< 197mv @4MHz, 245mv @3.2MHz */
    CY_SYSPM_SR_PWM_RAMP_VOLT_5 = 5,    /*< 173mv @4MHz, 216mv @3.2MHz */
    CY_SYSPM_SR_PWM_RAMP_VOLT_6 = 6,    /*< 149mv @4MHz, 185mv @3.2MHz */
    CY_SYSPM_SR_PWM_RAMP_VOLT_7 = 7,    /*< 124mv @4MHz, 155mv @3.2MHz */
}cy_en_syspm_sr_pwm_rampgen_amplitude_t;

/**
* Adjust Switching Regulator integrator R1 value
*/
typedef enum
{
    CY_SYSPM_SR_R1_375K      = 0u,      /**< Integrator R1 value 375k */
    CY_SYSPM_SR_R1_500K      = 1u,      /**< Integrator R1 value 500k */
    CY_SYSPM_SR_R1_750K      = 2u,      /**< Integrator R1 value 750k */
    CY_SYSPM_SR_R1_1000K     = 3u,      /**< Integrator R1 value 1000k */
    CY_SYSPM_SR_R1_1250K     = 4u,      /**< Integrator R1 value 1250k */
    CY_SYSPM_SR_R1_1500K     = 5u,      /**< Integrator R1 value 1500k */
    CY_SYSPM_SR_R1_1750K     = 6u,      /**< Integrator R1 value 1750k */
    CY_SYSPM_SR_R1_2250K     = 7u,      /**< Integrator R1 value 2250k */
}cy_en_syspm_sr_r1_adj_t;

/**
* Adjust Switching Regulator integrator Hysteretic RC / Feedforward C2 adjust
*/
typedef enum
{
    CY_SYSPM_SR_C2_1PF      = 0u,      /**< Capacitor C2 value 1pF */
    CY_SYSPM_SR_C2_2PF      = 1u,      /**< Capacitor C2 value 2pF */
    CY_SYSPM_SR_C2_3PF      = 2u,      /**< Capacitor C2 value 3pF */
    CY_SYSPM_SR_C2_4PF      = 3u,      /**< Capacitor C2 value 4pF */
    CY_SYSPM_SR_C2_5PF      = 4u,      /**< Capacitor C2 value 5pF */
    CY_SYSPM_SR_C2_6PF      = 5u,      /**< Capacitor C2 value 6pF */
    CY_SYSPM_SR_C2_7PF      = 6u,      /**< Capacitor C2 value 7pF */
    CY_SYSPM_SR_C2_8PF      = 7u,      /**< Capacitor C2 value 8pF */
}cy_en_syspm_sr_c2_adj_t;

/**
 * Switching Regulator Zero Current Detect trim adjust
 */
typedef enum
{
    CY_SYSPM_SR_ZEROCURRENT_THRESHOLD_30MA      = 0u,      /**< Zero Current Threshold 30mA */
    CY_SYSPM_SR_ZEROCURRENT_THRESHOLD_40MA      = 1u,      /**< Zero Current Threshold 40mA */
    CY_SYSPM_SR_ZEROCURRENT_THRESHOLD_50MA      = 2u,      /**< Zero Current Threshold 50mA */
    CY_SYSPM_SR_ZEROCURRENT_THRESHOLD_60MA      = 3u,      /**< Zero Current Threshold 60mA */
}cy_en_syspm_sr_zero_current_threshold_t;

/**
 * Over Current Detect threshold adjust
 */
typedef enum
{
    CY_SYSPM_SR_OVERCURRENT_THRESHOLD_0_50A      = 0u,      /**< Overcurrent Threshold 0.50A */
    CY_SYSPM_SR_OVERCURRENT_THRESHOLD_0_75A      = 1u,      /**< Overcurrent Threshold 0.75A */
    CY_SYSPM_SR_OVERCURRENT_THRESHOLD_1_00A      = 2u,      /**< Overcurrent Threshold 1.00A */
    CY_SYSPM_SR_OVERCURRENT_THRESHOLD_1_25A      = 3u,      /**< Overcurrent Threshold 1.25A */
}cy_en_syspm_sr_overcurrent_threshold_t;

/**
 * Over Current Detect blanking time adjust
 */
typedef enum
{
    CY_SYSPM_SR_OVERCURRENT_BLANKTIME_14_2NS      = 0u,      /**< Blank Time 14.2ns */
    CY_SYSPM_SR_OVERCURRENT_BLANKTIME_12_1NS      = 1u,      /**< Blank Time 12.1ns */
    CY_SYSPM_SR_OVERCURRENT_BLANKTIME_18_1NS      = 2u,      /**< Blank Time 18.1ns */
    CY_SYSPM_SR_OVERCURRENT_BLANKTIME_16_0NS      = 3u,      /**< Blank Time 16.0ns */
}cy_en_syspm_sr_overcurrent_blanktime_t;

/**
* Low-Power (window) mode Vref High voltage offset.
* In SR LP mode, the low voltage is specified by the primary SR voltage setting, and high voltage is given by:
*   vref_high = vref_low + lp_vref_high_adj
* Internally limited to maximum SR voltage setting.
 */
typedef enum
{
    CY_SYSPM_SR_LP_VREF_HIGH_VOLT_OFFSET_PLUS_00MV      = 0u,      /**< Offset +00mV */
    CY_SYSPM_SR_LP_VREF_HIGH_VOLT_OFFSET_PLUS_10MV      = 1u,      /**< Offset +10mV */
    CY_SYSPM_SR_LP_VREF_HIGH_VOLT_OFFSET_PLUS_20MV      = 2u,      /**< Offset +20mV */
    CY_SYSPM_SR_LP_VREF_HIGH_VOLT_OFFSET_PLUS_30MV      = 3u,      /**< Offset +30mV */
    CY_SYSPM_SR_LP_VREF_HIGH_VOLT_OFFSET_PLUS_40MV      = 4u,      /**< Offset +40mV */
    CY_SYSPM_SR_LP_VREF_HIGH_VOLT_OFFSET_PLUS_50MV      = 5u,      /**< Offset +50mV */
    CY_SYSPM_SR_LP_VREF_HIGH_VOLT_OFFSET_PLUS_60MV      = 6u,      /**< Offset +60mV */
    CY_SYSPM_SR_LP_VREF_HIGH_VOLT_OFFSET_PLUS_70MV      = 7u,      /**< Offset +70mV */
}cy_en_syspm_sr_lp_vref_high_voltage_offset_t;

/**
 * Power stage stagger ON/OFF delay for all slices
 */
typedef enum
{
    CY_SYSPM_SR_STG_ON_OFF_DELAY_0NS      = 0u,      /**< Delay 0ns */
    CY_SYSPM_SR_STG_ON_OFF_DELAY_1NS      = 1u,      /**< Delay 1ns */
    CY_SYSPM_SR_STG_ON_OFF_DELAY_2NS      = 2u,      /**< Delay 2ns */
    CY_SYSPM_SR_STG_ON_OFF_DELAY_3NS      = 3u,      /**< Delay 3ns */
}cy_en_syspm_sr_stg_on_off_delay_t;

/**
 * Drive strength up/down adjust for all slices. Applicable for Pgate and Ngate
 */
typedef enum
{
    CY_SYSPM_SR_DRV_STR_3X      = 0u,      /**< Drive Strength 3x */
    CY_SYSPM_SR_DRV_STR_4X      = 1u,      /**< Drive Strength 4x */
    CY_SYSPM_SR_DRV_STR_1X      = 2u,      /**< Drive Strength 1x */
    CY_SYSPM_SR_DRV_STR_2X      = 3u,      /**< Drive Strength 2x */
}cy_en_syspm_sr_drive_strength_t;

/**
 * SR NOL Adjust Noff/Poff Delay
 */
typedef enum
{
    CY_SYSPM_SR_NOL_OFF_DELAY_0NS      = 0u,      /**< Delay 0ns */
    CY_SYSPM_SR_NOL_OFF_DELAY_1NS      = 1u,      /**< Delay 1ns */
    CY_SYSPM_SR_NOL_OFF_DELAY_2NS      = 2u,      /**< Delay 2ns */
    CY_SYSPM_SR_NOL_OFF_DELAY_3NS      = 3u,      /**< Delay 3ns */
    CY_SYSPM_SR_NOL_OFF_DELAY_4NS      = 4u,      /**< Delay 4ns */
    CY_SYSPM_SR_NOL_OFF_DELAY_5NS      = 5u,      /**< Delay 5ns */
    CY_SYSPM_SR_NOL_OFF_DELAY_6NS      = 6u,      /**< Delay 6ns */
    CY_SYSPM_SR_NOL_OFF_DELAY_7NS      = 7u,      /**< Delay 7ns */
}cy_en_syspm_sr_nol_off_delay_t;

/**
 * Switching Regulator Load Current Thresholds. 5mA per step
 */
typedef enum
{
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_0MA      =  0u,     /**< Load Current Threshold 0mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_5MA      =  1u,     /**< Load Current Threshold 5mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_10MA     =  2u,     /**< Load Current Threshold 10mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_15MA     =  3u,     /**< Load Current Threshold 15mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_20MA     =  4u,     /**< Load Current Threshold 20mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_25MA     =  5u,     /**< Load Current Threshold 25mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_30MA     =  6u,     /**< Load Current Threshold 30mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_35MA     =  7u,     /**< Load Current Threshold 35mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_40MA     =  8u,     /**< Load Current Threshold 40mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_45MA     =  9u,     /**< Load Current Threshold 45mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_50MA     =  10u,    /**< Load Current Threshold 50mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_55MA     =  11u,    /**< Load Current Threshold 55mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_60MA     =  12u,    /**< Load Current Threshold 60mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_65MA     =  13u,    /**< Load Current Threshold 65mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_70MA     =  14u,    /**< Load Current Threshold 70mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_75MA     =  15u,    /**< Load Current Threshold 75mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_80MA     =  16u,    /**< Load Current Threshold 80mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_85MA     =  17u,    /**< Load Current Threshold 85mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_90MA     =  18u,    /**< Load Current Threshold 90mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_95MA     =  19u,    /**< Load Current Threshold 95mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_100MA    =  20u,    /**< Load Current Threshold 100mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_105MA    =  21u,    /**< Load Current Threshold 105mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_110MA    =  22u,    /**< Load Current Threshold 110mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_115MA    =  23u,    /**< Load Current Threshold 115mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_120MA    =  24u,    /**< Load Current Threshold 120mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_125MA    =  25u,    /**< Load Current Threshold 125mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_130MA    =  26u,    /**< Load Current Threshold 130mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_135MA    =  27u,    /**< Load Current Threshold 135mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_140MA    =  28u,    /**< Load Current Threshold 140mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_145MA    =  29u,    /**< Load Current Threshold 145mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_150MA    =  30u,    /**< Load Current Threshold 150mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_155MA    =  31u,    /**< Load Current Threshold 155mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_160MA    =  32u,    /**< Load Current Threshold 160mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_165MA    =  33u,    /**< Load Current Threshold 165mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_170MA    =  34u,    /**< Load Current Threshold 170mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_175MA    =  35u,    /**< Load Current Threshold 175mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_180MA    =  36u,    /**< Load Current Threshold 180mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_185MA    =  37u,    /**< Load Current Threshold 185mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_190MA    =  38u,    /**< Load Current Threshold 190mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_195MA    =  39u,    /**< Load Current Threshold 195mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_200MA    =  40u,    /**< Load Current Threshold 200mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_205MA    =  41u,    /**< Load Current Threshold 205mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_210MA    =  42u,    /**< Load Current Threshold 210mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_215MA    =  43u,    /**< Load Current Threshold 215mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_220MA    =  44u,    /**< Load Current Threshold 220mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_225MA    =  45u,    /**< Load Current Threshold 225mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_230MA    =  46u,    /**< Load Current Threshold 230mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_235MA    =  47u,    /**< Load Current Threshold 235mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_240MA    =  48u,    /**< Load Current Threshold 240mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_245MA    =  49u,    /**< Load Current Threshold 245mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_250MA    =  50u,    /**< Load Current Threshold 250mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_255MA    =  51u,    /**< Load Current Threshold 255mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_260MA    =  52u,    /**< Load Current Threshold 260mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_265MA    =  53u,    /**< Load Current Threshold 265mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_270MA    =  54u,    /**< Load Current Threshold 270mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_275MA    =  55u,    /**< Load Current Threshold 275mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_280MA    =  56u,    /**< Load Current Threshold 280mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_285MA    =  57u,    /**< Load Current Threshold 285mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_290MA    =  58u,    /**< Load Current Threshold 290mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_295MA    =  59u,    /**< Load Current Threshold 295mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_300MA    =  60u,    /**< Load Current Threshold 300mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_305MA    =  61u,    /**< Load Current Threshold 305mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_310MA    =  62u,    /**< Load Current Threshold 310mA */
    CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_315MA    =  63u,    /**< Load Current Threshold 315mA */
}cy_en_syspm_sr_load_current_threshold_t;

/** Specifies the source (top-connection) for the divide-by-8 R-ladder. */
typedef enum
{
    CY_SYSPM_RLADDER_MUX_SELECT_VBAT      =  0u,     /**< VBAT Source */
    CY_SYSPM_RLADDER_MUX_SELECT_PALDO     =  1u,     /**< PALDO Source */
    CY_SYSPM_RLADDER_MUX_SELECT_BTLDO     =  2u,     /**< BTLDO Source */
}cy_en_syspm_rladder_mux_select_t;

/** SR mode.  This specifies SR primary mode and sub-mode.
*       Low-Power (LP) modes use Window-regulation.
*       High-Power (HP) modes use Hysteretic-regulation.
 */
typedef enum
{
    CY_SYSPM_SR_TARGET_LP_LOW_SIDE_ONLY         = 0u,    /**< LP, Low-side-only regulation */
    CY_SYSPM_SR_TARGET_LP_HIGH_LOW_REGULATION   = 1u,    /**< LP, High/Low regulation */
    CY_SYSPM_SR_TARGET_HP_LPPFM_ONLY            = 4u,    /**< HP, LPPFM-only */
    CY_SYSPM_SR_TARGET_HP_AUTO_PFM_PWM          = 5u,    /**< HP, Auto PFM/PWM */
    CY_SYSPM_SR_TARGET_HP_PFM_ONLY              = 6u,    /**< HP, PFM-only */
    CY_SYSPM_SR_TARGET_HP_PWM_ONLY              = 7u,    /**< HP, PWM-only */
}cy_en_syspm_sr_target_mode_t;

/** SR High-Power mode PWM/PFM output voltage trim table
 *
 * SR_PWM_PFM_TRIM_TABLE
 * sr_pwm_pfm_trim   SR Voltage
     0111           +3.0%
     0110           +2.6%
     0101           +2.2%
     0100           +1.7%
     0011           +1.3%
     0010           +0.9%
     0001           +0.4%
     0000           +0%
     1111           -0.4%
     1110           -0.9%
     1101           -1.3%
     1100           -1.7%
     1011           -2.2%
     1010           -2.6%
     1001           -3.0%
     1000           -3.4%
 */
typedef enum
{
    CY_SYSPM_SR_PWM_PFM_TRIM_0       = 0u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_1       = 1u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_2       = 2u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_3       = 3u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_4       = 4u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_5       = 5u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_6       = 6u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_7       = 7u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_8       = 8u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_9       = 9u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_10      = 10u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_11      = 11u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_12      = 12u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_13      = 13u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_14      = 14u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
    CY_SYSPM_SR_PWM_PFM_TRIM_15      = 15u, /**< Refer the SR_PWM_PFM_TRIM_TABLE */
}cy_en_syspm_sr_pwm_pfm_trim_t;

/** SR High-Power mode LPPFM output voltage trim table
 *
 * SR_LPPFM_TRIM_TABLE
 * sr_lppfm_trim     SR Voltage
     0111           +3.0%
     0110           +2.6%
     0101           +2.2%
     0100           +1.7%
     0011           +1.3%
     0010           +0.9%
     0001           +0.4
     0000           +0%
     1111           -0.4%
     1110           -0.9%
     1101           -1.3%
     1100           -1.7%
     1011           -2.2%
     1010           -2.6%
     1001           -3.0%
     1000           -3.4%
 */
typedef enum
{
    CY_SYSPM_SR_LPPFM_TRIM_0       = 0u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_1       = 1u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_2       = 2u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_3       = 3u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_4       = 4u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_5       = 5u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_6       = 6u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_7       = 7u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_8       = 8u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_9       = 9u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_10      = 10u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_11      = 11u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_12      = 12u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_13      = 13u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_14      = 14u, /**< Refer the SR_LPPFM_TRIM_TABLE */
    CY_SYSPM_SR_LPPFM_TRIM_15      = 15u, /**< Refer the SR_LPPFM_TRIM_TABLE */
}cy_en_syspm_sr_lppfm_trim_t;

/** SR Low-Power (window) mode output voltage trim.  This affects only low-side voltage threshold.
 *
 * SR_LP_TRIM_TABLE
 * sr_lp_trim  SR_Voltage  sr_lp_trim  SR Voltage
   01111     +3.34%        11111      -0.22%
   01110     +3.10%        11110      -0.43%
   01101     +2.88%        11101      -0.65%
   01100     +2.65%        11100      -0.85%
   01011     +2.42%        11011      -1.07%
   01010     +2.20%        11010      -1.28%
   01001     +1.98%        11001      -1.48%
   01000     +1.75%        11000      -1.70%
   00111     +1.53%        10111      -1.90%
   00110     +1.30%        10110      -2.12%
   00101     +1.08%        10101      -2.32%
   00100     +0.87%        10100      -2.52%
   00011     +0.65%        10011      -2.73%
   00010     +0.43%        10010      -2.93%
   00001     +0.22%        10001      -3.13%
   00000     +0mV          10000      -3.34%

*/
typedef enum
{
    CY_SYSPM_SR_LP_TRIM_0       = 0u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_1       = 1u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_2       = 2u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_3       = 3u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_4       = 4u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_5       = 5u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_6       = 6u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_7       = 7u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_8       = 8u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_9       = 9u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_10      = 10u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_11      = 11u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_12      = 12u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_13      = 13u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_14      = 14u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_15      = 15u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_16      = 16u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_17      = 17u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_18      = 18u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_19      = 19u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_20      = 20u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_21      = 21u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_22      = 22u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_23      = 23u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_24      = 24u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_25      = 25u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_26      = 26u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_27      = 27u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_28      = 28u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_29      = 29u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_30      = 30u, /**< Refer the SR_LP_TRIM_TABLE */
    CY_SYSPM_SR_LP_TRIM_31      = 31u, /**< Refer the SR_LP_TRIM_TABLE */
}cy_en_syspm_sr_lp_trim_t;

#if defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)
/** PALDO Configuration */
typedef enum{
    CY_SYSPM_PALDO_INRUSH_0     = 0, /*< 130mA PALDO inrush adjustment, PALDO 120us inrush delay */
    CY_SYSPM_PALDO_INRUSH_1     = 1, /*< 150mA PALDO inrush adjustment, PALDO 110us inrush delay */
    CY_SYSPM_PALDO_INRUSH_2     = 2, /*<  70mA PALDO inrush adjustment, PALDO 235us inrush delay */
    CY_SYSPM_PALDO_INRUSH_3     = 3, /*<  90mA PALDO inrush adjustment, PALDO 170us inrush delay */
}cy_en_syspm_paldo_inrush_t;
#endif // defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)

#if defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)
/** BTLDO Configuration */
typedef enum{
    CY_SYSPM_BTLDO_INRUSH_0     = 0, /*< 65mA PALDO inrush adjustment, PALDO 110us inrush delay */
    CY_SYSPM_BTLDO_INRUSH_1     = 1, /*< 75mA PALDO inrush adjustment, PALDO 100us inrush delay */
    CY_SYSPM_BTLDO_INRUSH_2     = 2, /*< 30mA PALDO inrush adjustment, PALDO 235us inrush delay */
    CY_SYSPM_BTLDO_INRUSH_3     = 3, /*< 45mA PALDO inrush adjustment, PALDO 160us inrush delay */
}cy_en_syspm_btldo_inrush_t;
#endif // defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)

/** \} group_syspm_regb_enums */

/**
* \addtogroup group_syspm_regb_macros
* \{
*/

/**
* \addtogroup group_syspm_regb_device_sub_system_mcu_profile_macros
* \{
*/
/**
* Defines used to specify the profiles within the MCU sub-system
*/
#define CY_SYSPM_DEVICE_MCU_ACTIVE_0_8V                 ((uint32_t)0U)                           /**< MCU Active 0.8V */
#define CY_SYSPM_DEVICE_MCU_ACTIVE_0_8V_XTAL            ((uint32_t)1U)                           /**< MCU Active 0.8V + XTAL */
#define CY_SYSPM_DEVICE_MCU_ACTIVE_0_9V_XTAL            ((uint32_t)2U)                           /**< MCU Active 0.9V + XTAL */
#define CY_SYSPM_DEVICE_MCU_PROFILE_MAX                 CY_SYSPM_DEVICE_MCU_ACTIVE_0_9V_XTAL     /**< MCU Profile Max Value */
/** \} group_syspm_regb_device_sub_system_mcu_profile_macros */

/**
* \addtogroup group_syspm_regb_device_sub_system_bt_profile_macros
* \{
*/
/**
* Defines used to specify the profiles within the BT sub-system
*/
#define CY_SYSPM_DEVICE_BT_DO           ((uint32_t)0U)                                          /**< BT DO */
#define CY_SYSPM_DEVICE_BT_TX_RX        ((uint32_t)1U)                                          /**< BT TX RX */
#define CY_SYSPM_DEVICE_BT_PROFILE_MAX  CY_SYSPM_DEVICE_BT_TX_RX                                /**< BT Profile Max Value */
/** \} group_syspm_regb_device_sub_system_bt_profile_macros */


/** Maximum allowed count for SR pulses during boost cycle in LP regulation */
#define CY_SYSPM_SR_LP_COUNT_LIMIT_MAX              (0x1FUL)

/**  Macro to validate the device sub-system */
#define CY_SYSPM_IS_DEVICE_SUB_SYSTEM_VALID(value)    ((value) <= CY_SYSPM_DEVICE_SUB_SYSTEM_MAX)

/**  Macro to validate MCU profiles in the device sub-system */
#define CY_SYSPM_IS_DEVICE_MCU_PROFILE_VALID(value)    ((value) <= CY_SYSPM_DEVICE_MCU_PROFILE_MAX)

/**  Macro to validate BT profiles in the device sub-system */
#define CY_SYSPM_IS_DEVICE_BT_PROFILE_VALID(value)    ((value) <= CY_SYSPM_DEVICE_BT_PROFILE_MAX)

/**  Macro to validate parameters in Cy_SysPm_PMUConfigure() */
#define CY_SYSPM_IS_PMU_BGCHOPDELAY_VALID(delay)    ((delay) <= CY_SYSPM_BG_CHOP_DELAY_128US)

/** Macro to validate parameters in Cy_SysPm_CLDOConfigure() */
#define CY_SYSPM_IS_CLDO_BYPASS_THRESHOLD_VALID(threshold)   ((threshold) <= CY_SYSPM_CLDO_BYP_THRESHOLD_150MV)

/** Macro to validate parameters in Cy_SysPm_CLDOConfigure() */
#define CY_SYSPM_IS_CLDO_BYPASS_OFFSET_VALID(offset)   ((offset) <= CY_SYSPM_CLDO_BYP_OFFSET_150MV)

/** Macro to validate parameters in Cy_SysPm_CLDOConfigure() */
#define CY_SYSPM_IS_CLDO_FALLING_BYPASS_THRESHOLD_VALID(threshold)   ((threshold) <= CY_SYSPM_SR_VOLTAGE_1_06V)

/** Macro to validate parameters in Cy_SysPm_PALDOConfigure() */
#define CY_SYSPM_IS_PALDO_INRUSH_VALID(config)   ((config) <= CY_SYSPM_PALDO_INRUSH_3)

/** Macro to validate parameters in Cy_SysPm_BTLDOConfigure() */
#define CY_SYSPM_IS_BTLDO_INRUSH_VALID(config)   ((config) <= CY_SYSPM_BTLDO_INRUSH_3)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_SS_ADJUST_VALID(time)   ((time) <= CY_SYSPM_SR_SS_TIME_XXUS)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_LP_IPEAK_VALID(threshold)   ((threshold) <= CY_SYSPM_SR_LP_IPEAK_200MA)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_PWM_RAMPGEN_AMPLITUDE_VALID(amplitude)   ((amplitude) <= CY_SYSPM_SR_PWM_RAMP_VOLT_7)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_R1_VALUE_VALID(r1Value)   ((r1Value) <= CY_SYSPM_SR_R1_2250K)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_C2_VALUE_VALID(c2Value)   ((c2Value) <= CY_SYSPM_SR_C2_8PF)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_ZCD_TRIM_VALID(threshold)   ((threshold) <= CY_SYSPM_SR_ZEROCURRENT_THRESHOLD_60MA)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_OCD_LIMIT_VALID(threshold)   ((threshold) <= CY_SYSPM_SR_OVERCURRENT_THRESHOLD_1_25A)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_OCD_BLANKTIME_VALID(time)   ((time) <= CY_SYSPM_SR_OVERCURRENT_BLANKTIME_16_0NS)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_LP_VREF_HIGH_VOLTAGE_OFFSET_VALID(offset)   ((offset) <= CY_SYSPM_SR_LP_VREF_HIGH_VOLT_OFFSET_PLUS_70MV)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_LP_COUNT_LIMIT_VALID(count)   ((count) <= CY_SYSPM_SR_LP_COUNT_LIMIT_MAX)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_STAGGER_ON_OFF_DELAY_VALID(delay)   ((delay) <= CY_SYSPM_SR_STG_ON_OFF_DELAY_3NS)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_GATE_DRIVE_STRENGTH_VALID(driveStrength)   ((driveStrength) <= CY_SYSPM_SR_DRV_STR_2X)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_NOL_OFF_DELAY_VALID(delay)   ((delay) <= CY_SYSPM_SR_NOL_OFF_DELAY_7NS)

/** Macro to validate parameters in Cy_SysPm_SRConfigure() */
#define CY_SYSPM_IS_SR_NOL_OFF_DELAY_VALID(delay)   ((delay) <= CY_SYSPM_SR_NOL_OFF_DELAY_7NS)

#if defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)
/** Macro to validate parameters in Cy_SysPm_CLDOSetVoltage() */
#define CY_SYSPM_IS_CLDO_INDEX_VALID(index)   ((index) <= CY_SYSPM_CLDO_INDEX_LP)

/** Macro to validate parameters in Cy_SysPm_CLDOSetVoltage() */
#define CY_SYSPM_IS_CLDO_VOLTAGE_VALID(voltage)   ((voltage) <= CY_SYSPM_CLDO_VOLTAGE_1_01V)
#endif // defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)

#if defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)
/** Macro to validate parameters in Cy_SysPm_PALDOSetVoltage() */
#define CY_SYSPM_IS_PALDO_CONTROL_VALID(control)   ((control) <= CY_SYSPM_PALDO_DEFAULT)
#endif //defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)

/** Macro to validate parameters in Cy_SysPm_PALDOSetVoltage() and Cy_SysPm_BTLDOSetVoltage() */
#define CY_SYSPM_IS_HVLDO_VOLTAGE_VALID(voltage)   ((voltage) <= CY_SYSPM_HVLDO_VOLTAGE_3_300V)

#if defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)
/** Macro to validate parameters in Cy_SysPm_BTLDOSetVoltage() */
#define CY_SYSPM_IS_BTLDO_CONTROL_VALID(control)   ((control) <= CY_SYSPM_BTLDO_DEFAULT)
#endif // defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)
/** Macro to validate parameters in Cy_SysPm_SRSetVoltage() */
#define CY_SYSPM_IS_SR_INDEX_VALID(index)   ((index) <= CY_SYSPM_SR_INDEX_RF_2)

/** Macro to validate parameters in Cy_SysPm_SRSetVoltage() */
#define CY_SYSPM_IS_SR_VOLTAGE_VALID(voltage)   ((voltage) <= CY_SYSPM_SR_VOLTAGE_1_06V)

/** Macro to validate parameters in Cy_SysPm_SRFrequencyControlConfigure() */
#define CY_SYSPM_IS_SR_FREQUENCY_CONTROL_VALID(control)   ((control) <= CY_SYSPM_SR_FREQ_DEFAULT)

/** Macro to validate parameters in Cy_SysPm_SRFrequencyControlConfigure() */
#define CY_SYSPM_IS_SR_MAINCOMP_HYST_VALID(hysteresis)   ((hysteresis) <= CY_SYSPM_SR_MAINCOMP_HYST_2_5)

/** Macro to validate parameters in Cy_SysPm_SRFrequencyControlConfigure() */
#define CY_SYSPM_IS_SR_LPCOMP_HYST_VALID(hysteresis)   ((hysteresis) <= CY_SYSPM_SR_LPCOMP_HYST_5_2)

/** Macro to validate parameters in Cy_SysPm_SRThresholdConfigure() */
#define CY_SYSPM_IS_SR_LOAD_CURRENT_THRESHOLD_VALID(threshold)   ((threshold) <= CY_SYSPM_SR_LOAD_CURRENT_THRESHOLD_315MA)

/** Macro to validate the SR Target Mode */
#define CY_SYSPM_IS_SR_TARGET_MODE_VALID(mode)          (((mode) == CY_SYSPM_SR_TARGET_LP_LOW_SIDE_ONLY) || \
                                                         ((mode) == CY_SYSPM_SR_TARGET_LP_HIGH_LOW_REGULATION)  || \
                                                         ((mode) == CY_SYSPM_SR_TARGET_HP_LPPFM_ONLY) || \
                                                         ((mode) == CY_SYSPM_SR_TARGET_HP_AUTO_PFM_PWM)  || \
                                                         ((mode) == CY_SYSPM_SR_TARGET_HP_PFM_ONLY)  || \
                                                         ((mode) == CY_SYSPM_SR_TARGET_HP_PWM_ONLY))

/** Macro to validate parameters in Cy_SysPm_PMUVoltageSenseControlConfigure() */
#define CY_SYSPM_IS_RLADDER_MUX_SELECT_VALID(value)   ((value) <= CY_SYSPM_RLADDER_MUX_SELECT_BTLDO)

/** Macro to validate parameters in Cy_SysPm_SRTrimConfigure() */
#define CY_SYSPM_IS_SR_PWM_PFM_TRIM_VALID(trim)   ((trim) <= CY_SYSPM_SR_PWM_PFM_TRIM_15)

/** Macro to validate parameters in Cy_SysPm_SRTrimConfigure() */
#define CY_SYSPM_IS_SR_LPPFM_TRIM_VALID(trim)   ((trim) <= CY_SYSPM_SR_LPPFM_TRIM_15)

/** Macro to validate parameters in Cy_SysPm_SRTrimConfigure() */
#define CY_SYSPM_IS_SR_LP_TRIM_VALID(trim)   ((trim) <= CY_SYSPM_SR_LP_TRIM_31)

/** \} group_syspm_regb_macros */

/**
* \addtogroup group_syspm_regb_data_structures
* \{
*/

/**
 * The structure that contains the PMU Configuration settings
 */
typedef struct
{
    uint8_t bgChopDelay; /**< BG chopping startup delay Select /ref cy_en_syspm_bg_chop_delay_t */
    bool    bgLpClkSel;  /**< BG low-power clock select
                                     true  - SR duty-cycle (window-mode only)
                                     false - Internal */
    bool    bgForceEnable;   /**< BG Force Enable :
                                     true  - Always-ON (HP=on, LP=on)
                                     false - Normal (HP=on, LP=duty-cycle) */

}cy_stc_syspm_pmu_params_t;

#if defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)
/**
 * The structure that contains the CLDO Configuration settings
 */
typedef struct
{
    bool     cldoEnable;            /**< CLDO enable */
    bool     cldoLeakSenseEnable;   /**< CLDO leak sense enable.  Leak sense is used to protect CLDO */
    uint8_t  cldoBypThreshold;      /**< SR-to-CLDO dropout voltage (headroom) requirement.  When SR to CLDO voltage
                                        difference is below this amount the CLDO will enter Bypass
                                        /ref cy_en_syspm_cldo_bypass_threshold_t */
    uint8_t  cldoBypOffset;         /**< CLDO bypass offset - This is used to offset SR voltage during CLDO bypass transitions
                                         in order to provide LDO headroom for regulation when bypass exit happens at high current
                                         load /ref cy_en_syspm_cldo_bypass_offset_t*/
    uint8_t  cldoFallBypThreshold;  /**< CLDO falling bypass threshold voltage - This is used to control max SR voltage that will occur
                                         when CLDO is changing from regulation to bypass.
                                            - When SR is falling voltage transition and CLDO is going from regulation to bypass,
                                              if SR is greater than this voltage it will first transition to this voltage.
                                            - Then regulation to bypass handover occurs
                                            - Then SR ramps to final voltage
                                        /ref cy_en_syspm_sr_voltage_t for the voltage settings */
}cy_stc_syspm_cldo_params_t;
#endif // defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)

#if defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)
/**
 * The structure that contains the PALDO Configuration settings
 */
typedef struct
{
    uint8_t    paldoInrushAdjust; /**< PALDO inrush adjustment. Timing is for 1uF load cap.
                                        /ref cy_en_syspm_paldo_inrush_t */
    uint8_t    paldoInrushDelay; /**<  PALDO inrush delay, 1us per step. This should be consistent
                                        with paldoInrushAdjust. /ref cy_en_syspm_paldo_inrush_t */
}cy_stc_syspm_paldo_params_t;
#endif // defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)
#if defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)
/**
 * The structure that contains the BTLDO Configuration settings
 */
typedef struct
{
    uint8_t   btldoInrushAdjust;    /**< BTLDO inrush adjustment. Timing is for 1uF load cap.
                                        /ref cy_en_syspm_btldo_inrush_t */
    uint8_t   btldoInrushDelay;    /**<  BTLDO inrush delay, 1us per step. This should be consistent
                                        with btldoInrushAdjust. /ref cy_en_syspm_btldo_inrush_t */
}cy_stc_syspm_btldo_params_t;
#endif // defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)

/**
 * The structure that contains the Switching Regulator Configuration settings
 */
typedef struct
{
    bool        srEnable;              /**< Switching Regulator enable. Controls if SR is enabled when PMU is enabled. */
    uint8_t     srSoftStartAdj;        /**< Soft-start time adjust. Time to adjust from 0 to 0.8V /ref cy_en_syspm_sr_ss_adj_t */
    uint8_t     srLPIpeak;             /**< Peak-current threshold in LP regulation. /ref cy_en_syspm_sr_lp_ipeak_t */
    uint8_t     srRampAdj;             /**< PWM rampgen amplitude. /ref cy_en_syspm_sr_pwm_rampgen_amplitude_t */
    bool        srDisCompLatch;        /**< Disable Main and LP comparator output latches (note: this disables minimum high/low timing)
                                                Setting  Comp Latch
                                                    0     Timing based on Noff/Poff
                                                    1     Disabled */
    bool        srMainCompRatio;       /**< Main comparator Gm ratio
                                                Setting   Ratio
                                                    0      1:4:1
                                                    1      1:2:1 */
    bool        srMainCompLpDis;       /**< Main comparator disable low-power operation in PFM
                                                Setting        Bias
                                                    0         PWM=HP, PFM=LP
                                                    1         PWM=HP, PFM=HP */
    uint8_t     srR1Adj;               /**< Adjust integrator R1 value. /ref cy_en_syspm_sr_r1_adj_t */
    uint8_t     srC2Adj;               /**< Hysteretic RC / Feedforward C2 adjust. /ref cy_en_syspm_sr_c2_adj_t */
    uint8_t     srZcdTrim;             /**< Zero Current Detect trim adjust. /ref cy_en_syspm_sr_zero_current_threshold_t */
    bool        srDisOcd;              /**< Disable over-current detect */
    uint8_t     srOcdLimit;            /**< Over Current Detect threshold adjust. /ref cy_en_syspm_sr_overcurrent_threshold_t */
    bool        srOcdCount;            /**< Over Current Detect fault count
                                                Setting   Count
                                                    0        8 counts
                                                    1        15 counts */
    uint8_t     srOcdBlank;            /**< Over Current Detect blanking time adjust. /ref cy_en_syspm_sr_overcurrent_blanktime_t */
    bool        srOcdResetMethod;      /**< Over Current Detect reset method.
                                                Setting   Method
                                                    0      175ns timer
                                                    1      Reset by ZeroI  */
    uint8_t     srLpVrefHighAdj;       /**< Low-Power (window) mode Vref High voltage offset./ref cy_en_syspm_sr_lp_vref_high_voltage_offset_t */
    uint8_t     srLpCntLimit;          /**< Minimum number of pulses during boost cycle in LP regulation.  Actual pulses will
                                            be determined by greater of: this number, or number of pulses required to clear
                                            Vlow comparator hysteresis. */
    uint8_t     srStaggerOnDelay;      /**< Power stage stagger ON delay for all slices. /ref cy_en_syspm_sr_stgon_delay_t */
    uint8_t     srStaggerOffDelay;     /**< Power stage stagger OFF delay for all slices. /ref cy_en_syspm_sr_stgoff_delay_t */
    uint8_t     srDriveStrnp;          /**< Ngate drive strength up adjust for all slices. /ref cy_en_syspm_sr_drive_strength_t */
    uint8_t     srDriveStrnn;          /**< Ngate drive strength down adjust for all slices. /ref cy_en_syspm_sr_drive_strength_t */
    uint8_t     srDriveStrpp;          /**< Pgate drive strength up adjust for all slices. /ref cy_en_syspm_sr_drive_strength_t */
    uint8_t     srDriveStrpn;          /**< Pgate drive strength down adjust for all slices. /ref cy_en_syspm_sr_drive_strength_t */
    uint8_t     srNOffDelay;           /**< Adjust NOL Noff delay. /ref cy_en_syspm_sr_nol_off_delay_t */
    uint8_t     srPOffDelay;           /**< Adjust NOL Poff delay. /ref cy_en_syspm_sr_nol_off_delay_t */
    bool        srVlxForceEn;          /**< VLX force enable */
    bool        srVlxForceSel;         /**< VLX force select
                                                Only applies when sr_vlx_force_en=1
                                                Setting    VLX State
                                                   0          Low
                                                   1          Hi-Z */
    bool        srFreqOverride;         /**< Set to force SRfreq to use CY_SYSPM_SR_FREQ_DEFAULT settings */
}cy_stc_syspm_sr_params_t;

/** Switching Regulator Frequency Control */
typedef struct
{
    bool        bgChopDisable;        /**< Disable bandgap 1MHz chopping mode in BG high-power operation */
    bool        oscFreqSelect;        /**< PWM oscillator frequency select.
                                                0: 4.0MHz
                                                1: 3.2MHz */
    bool        srFreqDiv2;           /**< Divide SR PWM frequency by 2.
                                                0: 3.2MHz/4.0MHz
                                                1: 1.6MHz/2.0MHz */
    uint8_t     srMainCompHysteresis; /**< PFM comparator hysteresis adjustment.  \ref cy_en_syspm_sr_maincomp_hyst_t*/
    uint8_t     srLpCompHysteresis;   /**< LPPFM comparator hysteresis adjustment.  \ref cy_en_syspm_sr_lpcomp_hyst_t*/
}cy_stc_syspm_sr_freq_params_t;

/** Switching Regulator Frequency Control Priority settings */
typedef struct
{
    bool        bgChopPriority;         /**< Priority for BG chop disable.
                                            Individually for WLAN/BT, if multiple SRfreq Pactive are asserted,
                                                the B-setting will override A-setting.
                                            If both BT and WLAN SRfreq Pactive are asserted, then this setting
                                                determines which is used, evaluated on a per-setting basis.
                                            If no Pactive are asserted then CY_SYSPM_SR_FREQ_DEFAULT settings are used
                                            Setting   Priority
                                                0      WL > BT
                                                1      BT > WL    */
    bool        osc4mFreqPriority;      /**< Priority for Osc4M Freq. Same method as bgChopPriority */
    bool        srFswDiv2Priority;      /**< Priority for SR Fsw Div2. Same method as bgChopPriority */
    bool        mainCompHystPriority;   /**< Priority for Maincomp Hyst. Same method as bgChopPriority */
    bool        lpCompHystPriority;     /**< Priority for LPcomp Hyst. Same method as bgChopPriority */
}cy_stc_syspm_sr_freq_priority_params_t;

/** Switching Regulator threshold settings */
typedef struct {
    uint8_t     currentThreshold2Slice;    /**< Load current threshold to use 2 slices./ref cy_en_syspm_sr_load_current_threshold_t */
    uint8_t     currentThreshold3Slice;    /**< Load current threshold to use 3 slices./ref cy_en_syspm_sr_load_current_threshold_t */
    uint8_t     currentThreshold4Slice;    /**< Load current threshold to use 4 slices./ref cy_en_syspm_sr_load_current_threshold_t */
    uint8_t     currentThreshold5Slice;    /**< Load current threshold to use 5 slices./ref cy_en_syspm_sr_load_current_threshold_t */
    uint8_t     srPokThreshold;            /**< Sets minimum SR voltage required to indicate Power-OK signal to miniPMU.
                                                Uses same voltage table as SR /ref cy_en_syspm_sr_voltage_t */
}cy_stc_syspm_sr_threshold_params_t;

/** PMU voltage sense control settings */
typedef struct
{
    uint8_t     rLadderMuxSelect;   /**< Sets the source (top-connection) for the divide-by-8 R-ladder.
                                         /ref cy_en_syspm_rladder_mux_select_t */
    bool        paldoOverride;      /**< Set to force PALDO to use PWR_PALDO_DEFAULT settings */
    bool        btldoOverride;      /**< Set to force BTLDO to use PWR_BTLDO_DEFAULT settings */
}cy_stc_syspm_pmu_voltage_sense_params_t;

/** PMU Sleep Target Settings */
typedef struct
{
    uint8_t     sleepCoreTargetIndex; /**< Sets the Core index for DeepSleep. /ref cy_en_syspm_cldo_index_t */
    uint8_t     sleepSrTargetIndex;   /**< Sets the SR index for DeepSleep. /ref cy_en_syspm_sr_index_t */
    uint8_t     sleepSrTargetLoad;    /**< Sets the SR load for DeepSleep. /ref cy_en_syspm_sr_load_current_threshold_t */
    uint8_t     sleepSrTargetMode;    /**< Sets the SR mode for DeepSleep /ref cy_en_syspm_sr_target_mode_t */
}cy_stc_syspm_pmu_sleep_target_params_t;

/** Switching Regulator Trim Settings */
typedef struct
{
    uint8_t     srPwmPfmTrim;   /**< SR High-Power mode PWM/PFM output voltage trim. /ref cy_en_syspm_sr_pwm_pfm_trim_t */
    uint8_t     srLPPfmTrim;    /**< SR High-Power mode LPPFM output voltage trim. /ref cy_en_syspm_sr_lppfm_trim_t */
    uint8_t     srLPTrim;       /**< SR Low-Power (window) mode output voltage trim. /ref cy_en_syspm_sr_lp_trim_t */
}cy_stc_syspm_sr_trim_params_t;

/** \} group_syspm_regb_data_structures */

/**
* \addtogroup group_syspm_regb_functions
* \{
*/
#if defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)
/*******************************************************************************
* Function Name: Cy_SysPm_CLDOSetTargetVoltageIndex
****************************************************************************//**
*
* Sets the CLDO target voltage index
*
* \param subSystem
* Device sub-system, \ref cy_en_syspm_device_sub_system_t.
*
* \param profile
* Profile within the sub-system.
* Specify the profile depending on the specified sub-system
* \ref group_syspm_regb_device_sub_system_mcu_profile_macros
* \ref group_syspm_regb_device_sub_system_wl_profile_macros
* \ref group_syspm_regb_device_sub_system_bt_profile_macros
* \ref group_syspm_regb_device_sub_system_xtaldig_profile_macros
*
* \param cldoIndex
* CLDO target voltage index to be set, \ref cy_en_syspm_cldo_index_t
*
*******************************************************************************/
void Cy_SysPm_CLDOSetTargetVoltageIndex(cy_en_syspm_device_sub_system_t subSystem, uint32_t profile, cy_en_syspm_cldo_index_t cldoIndex);
#endif // defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)

/*******************************************************************************
* Function Name: Cy_SysPm_SRSetTargetVoltageIndex
****************************************************************************//**
*
* Sets the SR target voltage index
*
* \param subSystem
* Device sub-system, \ref cy_en_syspm_device_sub_system_t.
*
* \param profile
* Profile within the sub-system.
* Specify the profile depending on the specified sub-system
* \ref group_syspm_regb_device_sub_system_mcu_profile_macros
* \ref group_syspm_regb_device_sub_system_wl_profile_macros
* \ref group_syspm_regb_device_sub_system_bt_profile_macros
* \ref group_syspm_regb_device_sub_system_xtaldig_profile_macros
*
* \param srIndex
* SR target voltage index to be set, \ref cy_en_syspm_sr_index_t
*
*******************************************************************************/
void Cy_SysPm_SRSetTargetVoltageIndex(cy_en_syspm_device_sub_system_t subSystem, uint32_t profile, cy_en_syspm_sr_index_t srIndex);

/*******************************************************************************
* Function Name: Cy_SysPm_SRSetTargetLoadCurrent
****************************************************************************//**
*
* Sets the SR target load current
*
* \param subSystem
* Device sub-system, \ref cy_en_syspm_device_sub_system_t.
*
* \param profile
* Profile within the sub-system.
* Specify the profile depending on the specified sub-system
* \ref group_syspm_regb_device_sub_system_mcu_profile_macros
* \ref group_syspm_regb_device_sub_system_wl_profile_macros
* \ref group_syspm_regb_device_sub_system_bt_profile_macros
* \ref group_syspm_regb_device_sub_system_xtaldig_profile_macros
*
* \param srLoadCurrent
* SR target load current to be set, \ref cy_en_syspm_sr_load_current_threshold_t
*
*******************************************************************************/
void Cy_SysPm_SRSetTargetLoadCurrent(cy_en_syspm_device_sub_system_t subSystem, uint32_t profile, cy_en_syspm_sr_load_current_threshold_t srLoadCurrent);

/*******************************************************************************
* Function Name: Cy_SysPm_SRSetTargetMode
****************************************************************************//**
*
* Sets the SR target mode
*
* \param subSystem
* Device sub-system, \ref cy_en_syspm_device_sub_system_t.
*
* \param profile
* Profile within the sub-system.
* Specify the profile depending on the specified sub-system
* \ref group_syspm_regb_device_sub_system_mcu_profile_macros
* \ref group_syspm_regb_device_sub_system_wl_profile_macros
* \ref group_syspm_regb_device_sub_system_bt_profile_macros
* \ref group_syspm_regb_device_sub_system_xtaldig_profile_macros
*
* \param srMode
* SR target mode to be set, \ref cy_en_syspm_sr_target_mode_t
*
*******************************************************************************/
void Cy_SysPm_SRSetTargetMode(cy_en_syspm_device_sub_system_t subSystem, uint32_t profile, cy_en_syspm_sr_target_mode_t srMode);

/*******************************************************************************
* Function Name: Cy_SysPm_PMUConfigure
****************************************************************************//**
*
* Configures the PMU
*
* \param pmuParam
* Structure containing the pmu config parameters, \ref cy_stc_syspm_pmu_params_t.
*
*******************************************************************************/
void Cy_SysPm_PMUConfigure( cy_stc_syspm_pmu_params_t *pmuParam);

#if defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)
/*******************************************************************************
* Function Name: Cy_SysPm_CLDOConfigure
****************************************************************************//**
*
* Configures the Core LDO
*
* \param cldoParam
* Structure containing the CLDO config parameters, \ref cy_stc_syspm_cldo_params_t.
*
*******************************************************************************/
void Cy_SysPm_CLDOConfigure( cy_stc_syspm_cldo_params_t *cldoParam);

/*******************************************************************************
* Function Name: Cy_SysPm_CLDOSetVoltage
****************************************************************************//**
*
* Sets the Core LDO output voltage for the specified index
*
* \param index
* Core LDO index, \ref cy_en_syspm_cldo_index_t
*
* \param voltage
* Core LDO voltage to be set \ref cy_en_syspm_cldo_voltage_t.
*
*******************************************************************************/
void Cy_SysPm_CLDOSetVoltage(cy_en_syspm_cldo_index_t index, cy_en_syspm_cldo_voltage_t voltage);

/*******************************************************************************
* Function Name: Cy_SysPm_CLDOGetVoltage
****************************************************************************//**
*
* Get CLDO Voltage
*
* \return
* Gets enum value of type \ref cy_en_syspm_cldo_voltage_t
* CY_SYSPM_SR_VOLTAGE_INVALID if CLDO in bypass mode.
*
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_cldo_voltage_t Cy_SysPm_CLDOGetVoltage(void)
{
    cy_en_syspm_cldo_voltage_t cldo_vout = CY_SYSPM_CLDO_VOLTAGE_INVALID;

    if (0 == _FLD2VAL(PMU_AUX_PWR_READ_CLDO_CLDO_BYPASS, SRSS_PWR_READ_CLDO) &&
        0 == _FLD2VAL(PMU_AUX_PWR_READ_CLDO_CLDO_BYPASS_NMOS, SRSS_PWR_READ_CLDO))
        {
            /* The value is only correct if CLDO is in regulation (not bypass)
			   and the lowest value is 0.70V, hence requires the adjustment */
            cldo_vout = (cy_en_syspm_cldo_voltage_t)
			(_FLD2VAL(PMU_AUX_PWR_READ_CLDO_CLDO_VOUT, SRSS_PWR_READ_CLDO) + CY_SYSPM_CLDO_VOLTAGE_0_70V);
        }
    return cldo_vout;
}
#endif // defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)

#if defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)
/*******************************************************************************
* Function Name: Cy_SysPm_PALDOConfigure
****************************************************************************//**
*
* Configures the PALDO
*
* \param paldoParam
* Structure containing the PALDO config parameters, \ref cy_stc_syspm_paldo_params_t
*
*******************************************************************************/
void Cy_SysPm_PALDOConfigure( cy_stc_syspm_paldo_params_t *paldoParam);

/*******************************************************************************
* Function Name: Cy_SysPm_PALDOSetVoltage
****************************************************************************//**
*
* Sets the PALDO output voltage for the specified PALDO Control
*
* \param control
* PALDO control, \ref cy_en_syspm_paldo_control_t
*
* \param voltage
* PALDO voltage to be set \ref cy_en_syspm_hvldo_voltage_t.
*
*******************************************************************************/
void Cy_SysPm_PALDOSetVoltage(cy_en_syspm_paldo_control_t control, cy_en_syspm_hvldo_voltage_t voltage);

/*******************************************************************************
* Function Name: Cy_SysPm_PALDOGetVoltage
****************************************************************************//**
*
* Get PALDO Voltage
*
* \return
* Gets enum value of type \ref cy_en_syspm_hvldo_voltage_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_hvldo_voltage_t Cy_SysPm_PALDOGetVoltage(void)
{
    return (cy_en_syspm_hvldo_voltage_t)(_FLD2VAL(PMU_AUX_PWR_READ_PALDO_PALDO_VOUT, SRSS_PWR_READ_PALDO));
}

/*******************************************************************************
* Function Name: Cy_SysPm_PALDOEnable
****************************************************************************//**
*
* Enables the PALDO
*
* \param enable
* true - enable, false - disable
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_PALDOEnable(bool enable)
{
    CY_REG32_CLR_SET(SRSS_PWR_PALDO_DEFAULT, PMU_MAIN_PWR_PALDO_DEFAULT_PALDO_EN, ((enable) ? 1UL : 0UL));
}
#endif // defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)

#if defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)
/*******************************************************************************
* Function Name: Cy_SysPm_BTLDOConfigure
****************************************************************************//**
*
* Configures the BTLDO
*
* \param btldoParam
* Structure containing the BTLDO config parameters, \ref cy_stc_syspm_btldo_params_t
*
*******************************************************************************/
void Cy_SysPm_BTLDOConfigure( cy_stc_syspm_btldo_params_t *btldoParam);

/*******************************************************************************
* Function Name: Cy_SysPm_BTLDOSetVoltage
****************************************************************************//**
*
* Sets the BTLDO output voltage for the specified BTLDO control
*
* \param control
* BTLDO control, \ref cy_en_syspm_btldo_control_t
*
* \param voltage
* BTLDO voltage to be set \ref cy_en_syspm_hvldo_voltage_t.
*
*******************************************************************************/
void Cy_SysPm_BTLDOSetVoltage(cy_en_syspm_btldo_control_t control, cy_en_syspm_hvldo_voltage_t voltage);


/*******************************************************************************
* Function Name: Cy_SysPm_BTLDOGetVoltage
****************************************************************************//**
*
* Get BTLDO Voltage
*
* \return
* Gets enum value of type \ref cy_en_syspm_hvldo_voltage_t*
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_hvldo_voltage_t Cy_SysPm_BTLDOGetVoltage(void)
{
    return (cy_en_syspm_hvldo_voltage_t)(_FLD2VAL(PMU_AUX_PWR_READ_BTLDO_BTLDO_VOUT, SRSS_PWR_READ_BTLDO));
}

/*******************************************************************************
* Function Name: Cy_SysPm_BTLDOEnable
****************************************************************************//**
*
* Enables the BTLDO
*
* \param enable
* true - enable, false - disable
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_BTLDOEnable(bool enable)
{
    CY_REG32_CLR_SET(SRSS_PWR_BTLDO_DEFAULT, PMU_MAIN_PWR_BTLDO_DEFAULT_BTLDO_EN, ((enable) ? 1UL : 0UL));
}
#endif // defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)

/*******************************************************************************
* Function Name: Cy_SysPm_SRConfigure
****************************************************************************//**
*
* Configures the Switching Regulator
*
* \param srParam
* Structure containing the SR config parameters, \ref cy_stc_syspm_sr_params_t
*
*******************************************************************************/
void Cy_SysPm_SRConfigure( cy_stc_syspm_sr_params_t *srParam);

/*******************************************************************************
* Function Name: Cy_SysPm_SRSetVoltage
****************************************************************************//**
*
* Sets the Switching Regulator output voltage
*
* \param index
* SR index, \ref cy_en_syspm_sr_index_t
*
* \param voltage
* SR voltage to be set \ref cy_en_syspm_sr_voltage_t
*
*******************************************************************************/
void Cy_SysPm_SRSetVoltage(cy_en_syspm_sr_index_t index, cy_en_syspm_sr_voltage_t voltage);


/*******************************************************************************
* Function Name: Cy_SysPm_SRGetVoltage
****************************************************************************//**
*
* Get Switching Regulator Voltage
*
* \return
* Gets enum value of type \ref cy_en_syspm_sr_voltage_t
* CY_SYSPM_SR_VOLTAGE_INVALID if SR voltage out of spec (max 1.06V).
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_sr_voltage_t Cy_SysPm_SRGetVoltage(void)
{
    cy_en_syspm_sr_voltage_t sr_voltage =
        (cy_en_syspm_sr_voltage_t)(_FLD2VAL(PMU_AUX_PWR_READ_SR_SR_VOUT, SRSS_PWR_READ_SR));
    return (sr_voltage > CY_SYSPM_SR_VOLTAGE_1_06V) ? CY_SYSPM_SR_VOLTAGE_INVALID : sr_voltage;
}

/*******************************************************************************
* Function Name: Cy_SysPm_SRFrequencyControlConfigure
****************************************************************************//**
*
* Configures the Switching Regulator Frequency Control
*
* \param type
* SR Frequency Control type, \ref cy_en_syspm_sr_frequency_control_type_t
*
* \param srFreqParam
* SR Frequency parameters to be set \ref cy_stc_syspm_sr_freq_params_t
*
*******************************************************************************/
void Cy_SysPm_SRFrequencyControlConfigure(cy_en_syspm_sr_frequency_control_type_t type, cy_stc_syspm_sr_freq_params_t *srFreqParam);

/*******************************************************************************
* Function Name: Cy_SysPm_SRFrequencyPriorityConfigure
****************************************************************************//**
*
* Configures the Switching Regulator Frequency Control Priority
*
* \param srFreqPriorityParam
* SR Frequency priority parameters to be set \ref cy_stc_syspm_sr_freq_priority_params_t
*
*******************************************************************************/
void Cy_SysPm_SRFrequencyPriorityConfigure(cy_stc_syspm_sr_freq_priority_params_t *srFreqPriorityParam);

/*******************************************************************************
* Function Name: Cy_SysPm_SRThresholdConfigure
****************************************************************************//**
*
* Configures the Switching Regulator Threshold
*
* \param srThresholdParam
* SR threshold parameters to be set \ref cy_stc_syspm_sr_threshold_params_t
*
*******************************************************************************/
void Cy_SysPm_SRThresholdConfigure(cy_stc_syspm_sr_threshold_params_t *srThresholdParam);

/*******************************************************************************
* Function Name: Cy_SysPm_PMUVoltageSenseControlConfigure
****************************************************************************//**
*
* Configures the Voltage Sense Control
*
* \param pmuVoltSenseParam
* Voltage sense parameters to be set \ref cy_stc_syspm_pmu_voltage_sense_params_t
*
*******************************************************************************/
void Cy_SysPm_PMUVoltageSenseControlConfigure(cy_stc_syspm_pmu_voltage_sense_params_t *pmuVoltSenseParam);

/*******************************************************************************
* Function Name: Cy_SysPm_SleepTargetConfigure
****************************************************************************//**
*
* Configures the Sleep Target Settings
*
* \param pmuSleepTargetParam
* Sleep Target parameters to be set \ref cy_stc_syspm_pmu_sleep_target_params_t
*
*******************************************************************************/
void Cy_SysPm_PMUSleepTargetConfigure(cy_stc_syspm_pmu_sleep_target_params_t *pmuSleepTargetParam);

/*******************************************************************************
* Function Name: Cy_SysPm_SRTrimConfigure
****************************************************************************//**
*
* Configures the Switching Regulator trim settings
*
* \param srTrimParam
* Switching Regulator trim parameters to be set \ref cy_stc_syspm_sr_trim_params_t
*
*******************************************************************************/
void Cy_SysPm_SRTrimConfigure(cy_stc_syspm_sr_trim_params_t *srTrimParam);

/** \} group_syspm_regb_functions */

#ifdef __cplusplus
}
#endif

#endif /* defined(CY_IP_MXS22SRSS) && defined(CY_IP_MXS22SRSS_VERSION) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1) */

#endif /* CY_SYSPM_REGB_H */

/** \} group_syspm_regb */


/* [] END OF FILE */
