/***************************************************************************//**
* \file gpio_pag2s_32_qfn_1.h
*
* \brief
* PAG2S device GPIO header for 32-QFN_1 package
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _GPIO_PAG2S_32_QFN_1_H_
#define _GPIO_PAG2S_32_QFN_1_H_

/* Package type */
enum
{
    CY_GPIO_PACKAGE_QFN,
    CY_GPIO_PACKAGE_BGA,
    CY_GPIO_PACKAGE_CSP,
    CY_GPIO_PACKAGE_WLCSP,
    CY_GPIO_PACKAGE_LQFP,
    CY_GPIO_PACKAGE_TQFP,
    CY_GPIO_PACKAGE_SMT,
    CY_GPIO_PACKAGE_DFN,
    CY_GPIO_PACKAGE_SOIC,
    CY_GPIO_PACKAGE_SSOP,
    CY_GPIO_PACKAGE_LGA,
};

#define CY_GPIO_PACKAGE_TYPE            CY_GPIO_PACKAGE_QFN
#define CY_GPIO_PIN_COUNT               32u

/* AMUXBUS Segments */
enum
{
    AMUXBUS_AMUXBUS_A,
    AMUXBUS_AMUXBUS_B,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_NONE             = 0x0000u   /* Device doesn't have AMux bus splitter cells */
} cy_en_amux_split_t;

/* Port List */
/* PORT 0 (GPIO) */
#define P0_0_PORT                       GPIO_PRT0
#define P0_0_PIN                        0u
#define P0_0_NUM                        0u
#define P0_0_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P0_1_PORT                       GPIO_PRT0
#define P0_1_PIN                        1u
#define P0_1_NUM                        1u
#define P0_1_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P0_2_PORT                       GPIO_PRT0
#define P0_2_PIN                        2u
#define P0_2_NUM                        2u
#define P0_2_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P0_3_PORT                       GPIO_PRT0
#define P0_3_PIN                        3u
#define P0_3_NUM                        3u
#define P0_3_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P0_4_PORT                       GPIO_PRT0
#define P0_4_PIN                        4u
#define P0_4_NUM                        4u
#define P0_4_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P0_5_PORT                       GPIO_PRT0
#define P0_5_PIN                        5u
#define P0_5_NUM                        5u
#define P0_5_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P0_6_PORT                       GPIO_PRT0
#define P0_6_PIN                        6u
#define P0_6_NUM                        6u
#define P0_6_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P0_7_PORT                       GPIO_PRT0
#define P0_7_PIN                        7u
#define P0_7_NUM                        7u
#define P0_7_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* PORT 1 (GPIO) */
#define P1_0_PORT                       GPIO_PRT1
#define P1_0_PIN                        0u
#define P1_0_NUM                        0u
#define P1_0_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P1_1_PORT                       GPIO_PRT1
#define P1_1_PIN                        1u
#define P1_1_NUM                        1u
#define P1_1_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* Analog Connections */
#define USBPD0_PAD_CC_COMPN_EA_PORT     1u
#define USBPD0_PAD_CC_COMPN_EA_PIN      0u
#define USBPD0_PAD_ESD_CC_BUFOUT_PORT   1u
#define USBPD0_PAD_ESD_CC_BUFOUT_PIN    1u
#define USBPD0_USBPHY_DM_BCH_DET0_PORT  0u
#define USBPD0_USBPHY_DM_BCH_DET0_PIN   2u
#define USBPD0_USBPHY_DP_BCH_DET0_PORT  0u
#define USBPD0_USBPHY_DP_BCH_DET0_PIN   3u

/* HSIOM Connections */
typedef enum
{
    /* Generic HSIOM connections */
    HSIOM_SEL_GPIO                  =  0,       /* SW controlled GPIO. */
    HSIOM_SEL_GPIO_DSI              =  1,       /* SW controlled 'out', DSI controlled 'oe_n'. */
    HSIOM_SEL_DSI_DSI               =  2,       /* DSI controlled 'out' and 'oe_n'. */
    HSIOM_SEL_DSI_GPIO              =  3,       /* DSI controlled 'out', SW controlled 'oe_n'. */
    HSIOM_SEL_CSD_SENSE             =  4,       /* CSD sense connection (analog mode) */
    HSIOM_SEL_CSD_SHIELD            =  5,       /* CSD shield connection (analog mode) */
    HSIOM_SEL_AMUXA                 =  6,       /* AMUXBUS A connection. */
    HSIOM_SEL_AMUXB                 =  7,       /* AMUXBUS B connection. */
    HSIOM_SEL_ACT_0                 =  8,       /* Chip specific Active source 0 connection. */
    HSIOM_SEL_ACT_1                 =  9,       /* Chip specific Active source 1 connection. */
    HSIOM_SEL_ACT_2                 = 10,       /* Chip specific Active source 2 connection. */
    HSIOM_SEL_ACT_3                 = 11,       /* Chip specific Active source 3 connection. */
    HSIOM_SEL_LCD_COM               = 12,       /* LCD common connection. */
    HSIOM_SEL_LCD_SEG               = 13,       /* LCD segment connection. */
    HSIOM_SEL_DS_0                  = 12,       /* Chip specific DeepSleep source 0 connection. */
    HSIOM_SEL_DS_1                  = 13,       /* Chip specific DeepSleep source 1 connection. */
    HSIOM_SEL_DS_2                  = 14,       /* Chip specific DeepSleep source 2 connection. */
    HSIOM_SEL_DS_3                  = 15,       /* Chip specific DeepSleep source 3 connection. */

    /* P0.0 */
    P0_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_0_TCPWM_TR_IN0               =  8,       /* Digital Active - tcpwm.tr_in[0]:1 */
    P0_0_USBPD0_EXT_FEEDFWD_SW_EN   = 11,       /* Digital Active - usbpd[0].ext_feedfwd_sw_en:1 */
    P0_0_USBPD0_EXT_NSN_OUT         = 13,       /* Digital Deep Sleep - usbpd[0].ext_nsn_out:1 */
    P0_0_USBPD0_EXT_PEAKDET_OUT     = 14,       /* Digital Deep Sleep - usbpd[0].ext_peakdet_out:1 */
    P0_0_USBPD0_AFC_TX_DATA_EN      = 15,       /* Digital Deep Sleep - usbpd[0].afc_tx_data_en:1 */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_1_USBPD0_EXT_PWM_OUT         = 10,       /* Digital Active - usbpd[0].ext_pwm_out:1 */
    P0_1_USBPD0_EXT_ACF_IN          = 11,       /* Digital Active - usbpd[0].ext_acf_in */
    P0_1_USBPD0_EXT_FF_INTEG_RESETB_IN = 13,    /* Digital Deep Sleep - usbpd[0].ext_ff_integ_resetb_in:1 */
    P0_1_USBPD0_EXT_ZCD_OUT         = 14,       /* Digital Deep Sleep - usbpd[0].ext_zcd_out:1 */
    P0_1_USBPD0_AFC_TX_DATA0        = 15,       /* Digital Deep Sleep - usbpd[0].afc_tx_data[0]:1 */

    /* P0.2 */
    P0_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_2_USBPD0_EXT_FEEDFWD_SW_EN   = 11,       /* Digital Active - usbpd[0].ext_feedfwd_sw_en:0 */
    P0_2_CPUSS_SWD_DATA             = 12,       /* Digital Deep Sleep - cpuss.swd_data:0 */
    P0_2_USBPD0_EXT_NSN_OUT         = 13,       /* Digital Deep Sleep - usbpd[0].ext_nsn_out:0 */
    P0_2_USBPD0_EXT_PEAKDET_OUT     = 14,       /* Digital Deep Sleep - usbpd[0].ext_peakdet_out:0 */
    P0_2_USBPD0_AFC_TX_DATA_EN      = 15,       /* Digital Deep Sleep - usbpd[0].afc_tx_data_en:0 */

    /* P0.3 */
    P0_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_3_USBPD0_EXT_PWM_OUT         = 10,       /* Digital Active - usbpd[0].ext_pwm_out:0 */
    P0_3_USBPD0_EXT_ACF_WEAKP_IN    = 11,       /* Digital Active - usbpd[0].ext_acf_weakp_in */
    P0_3_CPUSS_SWD_CLK              = 12,       /* Digital Deep Sleep - cpuss.swd_clk:0 */
    P0_3_USBPD0_EXT_ZCD_OUT         = 14,       /* Digital Deep Sleep - usbpd[0].ext_zcd_out:0 */
    P0_3_USBPD0_AFC_TX_DATA0        = 15,       /* Digital Deep Sleep - usbpd[0].afc_tx_data[0]:0 */

    /* P0.4 */
    P0_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_4_USBPD0_DISCHG_EN0          = 12,       /* Digital Deep Sleep - usbpd[0].dischg_en[0] */
    P0_4_USBPD0_EXT_FF_INTEG_RESETB_IN = 13,    /* Digital Deep Sleep - usbpd[0].ext_ff_integ_resetb_in:0 */

    /* P0.5 */
    P0_5_GPIO                       =  0,       /* SW controlled GPIO. */

    /* P0.6 */
    P0_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_6_TCPWM_TR_IN0               =  8,       /* Digital Active - tcpwm.tr_in[0]:0 */
    P0_6_TCPWM_LINE0                =  9,       /* Digital Active - tcpwm.line[0]:0 */
    P0_6_TCPWM_TR_OVERFLOW0         = 10,       /* Digital Active - tcpwm.tr_overflow[0]:0 */
    P0_6_TCPWM_TR_COMPARE_MATCH0    = 11,       /* Digital Active - tcpwm.tr_compare_match[0]:0 */
    P0_6_USBPD0_EXT_PTDRV_IN        = 13,       /* Digital Deep Sleep - usbpd[0].ext_ptdrv_in:0 */
    P0_6_USBPD0_ADC_CMP_OUT_GPIO0   = 14,       /* Digital Deep Sleep - usbpd[0].adc_cmp_out_gpio[0]:0 */
    P0_6_USBPD0_EXT_GDRV_IN         = 15,       /* Digital Deep Sleep - usbpd[0].ext_gdrv_in:0 */

    /* P0.7 */
    P0_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_7_USBPD0_EXT_PTDRV_IN        = 13,       /* Digital Deep Sleep - usbpd[0].ext_ptdrv_in:1 */
    P0_7_USBPD0_ADC_CMP_OUT_GPIO0   = 14,       /* Digital Deep Sleep - usbpd[0].adc_cmp_out_gpio[0]:1 */
    P0_7_USBPD0_EXT_GDRV_IN         = 15,       /* Digital Deep Sleep - usbpd[0].ext_gdrv_in:1 */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_0_SRSS_EXT_CLK               =  8,       /* Digital Active - srss.ext_clk */
    P1_0_TCPWM_LINE0                =  9,       /* Digital Active - tcpwm.line[0]:1 */
    P1_0_TCPWM_TR_OVERFLOW0         = 10,       /* Digital Active - tcpwm.tr_overflow[0]:1 */
    P1_0_TCPWM_TR_COMPARE_MATCH0    = 11,       /* Digital Active - tcpwm.tr_compare_match[0]:1 */
    P1_0_USBPD0_GPIO_DDFT1          = 13,       /* Digital Deep Sleep - usbpd[0].gpio_ddft1 */
    P1_0_USBPD0_FAULT_GPIO1         = 14,       /* Digital Deep Sleep - usbpd[0].fault_gpio1 */
    P1_0_USBPD0_TX_DATA             = 15,       /* Digital Deep Sleep - usbpd[0].tx_data */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_1_TCPWM_TR_IN0               =  8,       /* Digital Active - tcpwm.tr_in[0]:2 */
    P1_1_TCPWM_LINE0                =  9,       /* Digital Active - tcpwm.line[0]:2 */
    P1_1_TCPWM_TR_OVERFLOW0         = 10,       /* Digital Active - tcpwm.tr_overflow[0]:2 */
    P1_1_TCPWM_TR_COMPARE_MATCH0    = 11,       /* Digital Active - tcpwm.tr_compare_match[0]:2 */
    P1_1_USBPD0_GPIO_DDFT0          = 13,       /* Digital Deep Sleep - usbpd[0].gpio_ddft0 */
    P1_1_USBPD0_FAULT_GPIO0         = 14,       /* Digital Deep Sleep - usbpd[0].fault_gpio0 */
    P1_1_USBPD0_TX_DATA_EN          = 15        /* Digital Deep Sleep - usbpd[0].tx_data_en */
} en_hsiom_sel_t;

#endif /* _GPIO_PAG2S_32_QFN_1_H_ */


/* [] END OF FILE */
