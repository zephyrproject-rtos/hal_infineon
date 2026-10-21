/***************************************************************************//**
* \file gpio_pmg1s3_97_bga_cypm1322.h
*
* \brief
* PMG1S3 device GPIO header for 97-BGA-CYPM1322 package
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

#ifndef _GPIO_PMG1S3_97_BGA_CYPM1322_H_
#define _GPIO_PMG1S3_97_BGA_CYPM1322_H_

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

#define CY_GPIO_PACKAGE_TYPE            CY_GPIO_PACKAGE_BGA
#define CY_GPIO_PIN_COUNT               97u

/* AMUXBUS Segments */
enum
{
    AMUXBUS_CSD,
    AMUXBUS_GPIO,
    AMUXBUS_PASS,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_0                = 0x0000u,  /* Left = AMUXBUS_GPIO; Right = AMUXBUS_PASS */
    AMUX_SPLIT_CTL_1                = 0x0001u,  /* Left = AMUXBUS_CSD; Right = AMUXBUS_PASS */
    AMUX_SPLIT_CTL_2                = 0x0002u   /* Left = AMUXBUS_CSD; Right = AMUXBUS_GPIO */
} cy_en_amux_split_t;

/* Port List */
/* PORT 0 (GPIO) */
#define P0_0_PORT                       GPIO_PRT0
#define P0_0_PIN                        0u
#define P0_0_NUM                        0u
#define P0_0_AMUXSEGMENT                AMUXBUS_GPIO
#define P0_1_PORT                       GPIO_PRT0
#define P0_1_PIN                        1u
#define P0_1_NUM                        1u
#define P0_1_AMUXSEGMENT                AMUXBUS_GPIO
#define P0_2_PORT                       GPIO_PRT0
#define P0_2_PIN                        2u
#define P0_2_NUM                        2u
#define P0_2_AMUXSEGMENT                AMUXBUS_GPIO
#define P0_3_PORT                       GPIO_PRT0
#define P0_3_PIN                        3u
#define P0_3_NUM                        3u
#define P0_3_AMUXSEGMENT                AMUXBUS_GPIO
#define P0_4_PORT                       GPIO_PRT0
#define P0_4_PIN                        4u
#define P0_4_NUM                        4u
#define P0_4_AMUXSEGMENT                AMUXBUS_GPIO
#define P0_5_PORT                       GPIO_PRT0
#define P0_5_PIN                        5u
#define P0_5_NUM                        5u
#define P0_5_AMUXSEGMENT                AMUXBUS_GPIO
#define P0_6_PORT                       GPIO_PRT0
#define P0_6_PIN                        6u
#define P0_6_NUM                        6u
#define P0_6_AMUXSEGMENT                AMUXBUS_GPIO
#define P0_7_PORT                       GPIO_PRT0
#define P0_7_PIN                        7u
#define P0_7_NUM                        7u
#define P0_7_AMUXSEGMENT                AMUXBUS_GPIO

/* PORT 1 (GPIO) */
#define P1_0_PORT                       GPIO_PRT1
#define P1_0_PIN                        0u
#define P1_0_NUM                        0u
#define P1_0_AMUXSEGMENT                AMUXBUS_GPIO
#define P1_1_PORT                       GPIO_PRT1
#define P1_1_PIN                        1u
#define P1_1_NUM                        1u
#define P1_1_AMUXSEGMENT                AMUXBUS_GPIO
#define P1_2_PORT                       GPIO_PRT1
#define P1_2_PIN                        2u
#define P1_2_NUM                        2u
#define P1_2_AMUXSEGMENT                AMUXBUS_GPIO
#define P1_3_PORT                       GPIO_PRT1
#define P1_3_PIN                        3u
#define P1_3_NUM                        3u
#define P1_3_AMUXSEGMENT                AMUXBUS_GPIO
#define P1_4_PORT                       GPIO_PRT1
#define P1_4_PIN                        4u
#define P1_4_NUM                        4u
#define P1_4_AMUXSEGMENT                AMUXBUS_GPIO
#define P1_5_PORT                       GPIO_PRT1
#define P1_5_PIN                        5u
#define P1_5_NUM                        5u
#define P1_5_AMUXSEGMENT                AMUXBUS_GPIO
#define P1_6_PORT                       GPIO_PRT1
#define P1_6_PIN                        6u
#define P1_6_NUM                        6u
#define P1_6_AMUXSEGMENT                AMUXBUS_GPIO

/* PORT 2 (GPIO) */
#define P2_0_PORT                       GPIO_PRT2
#define P2_0_PIN                        0u
#define P2_0_NUM                        0u
#define P2_0_AMUXSEGMENT                AMUXBUS_PASS
#define P2_1_PORT                       GPIO_PRT2
#define P2_1_PIN                        1u
#define P2_1_NUM                        1u
#define P2_1_AMUXSEGMENT                AMUXBUS_PASS
#define P2_2_PORT                       GPIO_PRT2
#define P2_2_PIN                        2u
#define P2_2_NUM                        2u
#define P2_2_AMUXSEGMENT                AMUXBUS_PASS
#define P2_3_PORT                       GPIO_PRT2
#define P2_3_PIN                        3u
#define P2_3_NUM                        3u
#define P2_3_AMUXSEGMENT                AMUXBUS_PASS
#define P2_4_PORT                       GPIO_PRT2
#define P2_4_PIN                        4u
#define P2_4_NUM                        4u
#define P2_4_AMUXSEGMENT                AMUXBUS_PASS
#define P2_5_PORT                       GPIO_PRT2
#define P2_5_PIN                        5u
#define P2_5_NUM                        5u
#define P2_5_AMUXSEGMENT                AMUXBUS_PASS
#define P2_6_PORT                       GPIO_PRT2
#define P2_6_PIN                        6u
#define P2_6_NUM                        6u
#define P2_6_AMUXSEGMENT                AMUXBUS_PASS
#define P2_7_PORT                       GPIO_PRT2
#define P2_7_PIN                        7u
#define P2_7_NUM                        7u
#define P2_7_AMUXSEGMENT                AMUXBUS_PASS

/* PORT 3 (GPIO) */
#define P3_0_PORT                       GPIO_PRT3
#define P3_0_PIN                        0u
#define P3_0_NUM                        0u
#define P3_0_AMUXSEGMENT                AMUXBUS_CSD
#define P3_1_PORT                       GPIO_PRT3
#define P3_1_PIN                        1u
#define P3_1_NUM                        1u
#define P3_1_AMUXSEGMENT                AMUXBUS_CSD
#define P3_2_PORT                       GPIO_PRT3
#define P3_2_PIN                        2u
#define P3_2_NUM                        2u
#define P3_2_AMUXSEGMENT                AMUXBUS_CSD
#define P3_3_PORT                       GPIO_PRT3
#define P3_3_PIN                        3u
#define P3_3_NUM                        3u
#define P3_3_AMUXSEGMENT                AMUXBUS_CSD
#define P3_4_PORT                       GPIO_PRT3
#define P3_4_PIN                        4u
#define P3_4_NUM                        4u
#define P3_4_AMUXSEGMENT                AMUXBUS_CSD
#define P3_5_PORT                       GPIO_PRT3
#define P3_5_PIN                        5u
#define P3_5_NUM                        5u
#define P3_5_AMUXSEGMENT                AMUXBUS_CSD
#define P3_6_PORT                       GPIO_PRT3
#define P3_6_PIN                        6u
#define P3_6_NUM                        6u
#define P3_6_AMUXSEGMENT                AMUXBUS_CSD
#define P3_7_PORT                       GPIO_PRT3
#define P3_7_PIN                        7u
#define P3_7_NUM                        7u
#define P3_7_AMUXSEGMENT                AMUXBUS_CSD

/* PORT 4 (GPIO_OVT) */
#define P4_0_PORT                       GPIO_PRT4
#define P4_0_PIN                        0u
#define P4_0_NUM                        0u
#define P4_0_AMUXSEGMENT                AMUXBUS_GPIO
#define P4_1_PORT                       GPIO_PRT4
#define P4_1_PIN                        1u
#define P4_1_NUM                        1u
#define P4_1_AMUXSEGMENT                AMUXBUS_GPIO

/* PORT 5 (GPIO) */
#define P5_0_PORT                       GPIO_PRT5
#define P5_0_PIN                        0u
#define P5_0_NUM                        0u
#define P5_0_AMUXSEGMENT                AMUXBUS_CSD
#define P5_1_PORT                       GPIO_PRT5
#define P5_1_PIN                        1u
#define P5_1_NUM                        1u
#define P5_1_AMUXSEGMENT                AMUXBUS_CSD
#define P5_2_PORT                       GPIO_PRT5
#define P5_2_PIN                        2u
#define P5_2_NUM                        2u
#define P5_2_AMUXSEGMENT                AMUXBUS_CSD
#define P5_3_PORT                       GPIO_PRT5
#define P5_3_PIN                        3u
#define P5_3_NUM                        3u
#define P5_3_AMUXSEGMENT                AMUXBUS_CSD
#define P5_4_PORT                       GPIO_PRT5
#define P5_4_PIN                        4u
#define P5_4_NUM                        4u
#define P5_4_AMUXSEGMENT                AMUXBUS_CSD
#define P5_5_PORT                       GPIO_PRT5
#define P5_5_PIN                        5u
#define P5_5_NUM                        5u
#define P5_5_AMUXSEGMENT                AMUXBUS_GPIO

/* PORT 6 (GPIO) */
#define P6_0_PORT                       GPIO_PRT6
#define P6_0_PIN                        0u
#define P6_0_NUM                        0u
#define P6_0_AMUXSEGMENT                AMUXBUS_GPIO
#define P6_1_PORT                       GPIO_PRT6
#define P6_1_PIN                        1u
#define P6_1_NUM                        1u
#define P6_1_AMUXSEGMENT                AMUXBUS_GPIO
#define P6_2_PORT                       GPIO_PRT6
#define P6_2_PIN                        2u
#define P6_2_NUM                        2u
#define P6_2_AMUXSEGMENT                AMUXBUS_GPIO
#define P6_3_PORT                       GPIO_PRT6
#define P6_3_PIN                        3u
#define P6_3_NUM                        3u
#define P6_3_AMUXSEGMENT                AMUXBUS_GPIO

/* PORT 7 (GPIO) */
#define P7_0_PORT                       GPIO_PRT7
#define P7_0_PIN                        0u
#define P7_0_NUM                        0u
#define P7_0_AMUXSEGMENT                AMUXBUS_GPIO
#define P7_1_PORT                       GPIO_PRT7
#define P7_1_PIN                        1u
#define P7_1_NUM                        1u
#define P7_1_AMUXSEGMENT                AMUXBUS_GPIO
#define P7_2_PORT                       GPIO_PRT7
#define P7_2_PIN                        2u
#define P7_2_NUM                        2u
#define P7_2_AMUXSEGMENT                AMUXBUS_GPIO
#define P7_3_PORT                       GPIO_PRT7
#define P7_3_PIN                        3u
#define P7_3_NUM                        3u
#define P7_3_AMUXSEGMENT                AMUXBUS_GPIO
#define P7_4_PORT                       GPIO_PRT7
#define P7_4_PIN                        4u
#define P7_4_NUM                        4u
#define P7_4_AMUXSEGMENT                AMUXBUS_GPIO
#define P7_5_PORT                       GPIO_PRT7
#define P7_5_PIN                        5u
#define P7_5_NUM                        5u
#define P7_5_AMUXSEGMENT                AMUXBUS_GPIO
#define P7_6_PORT                       GPIO_PRT7
#define P7_6_PIN                        6u
#define P7_6_NUM                        6u
#define P7_6_AMUXSEGMENT                AMUXBUS_GPIO

/* PORT 8 (AUX) */
#define USBDP_PORT                      GPIO_PRT8
#define USBDP_PIN                       0u
#define USBDP_NUM                       0u
#define P8_0_PORT                       GPIO_PRT8
#define P8_0_PIN                        0u
#define P8_0_NUM                        0u
#define USBDM_PORT                      GPIO_PRT8
#define USBDM_PIN                       1u
#define USBDM_NUM                       1u
#define P8_1_PORT                       GPIO_PRT8
#define P8_1_PIN                        1u
#define P8_1_NUM                        1u
#define VSSIO_5_PORT                    GPIO_PRT8
#define VSSIO_5_PIN                     2u
#define VSSIO_5_NUM                     2u
#define P8_2_PORT                       GPIO_PRT8
#define P8_2_PIN                        2u
#define P8_2_NUM                        2u

/* Analog Connections */
#define CSD_CMODPADD_PORT               5u
#define CSD_CMODPADD_PIN                1u
#define CSD_CMODPADS_PORT               5u
#define CSD_CMODPADS_PIN                1u
#define CSD_CSH_TANKPADD_PORT           5u
#define CSD_CSH_TANKPADD_PIN            0u
#define CSD_CSH_TANKPADS_PORT           5u
#define CSD_CSH_TANKPADS_PIN            0u
#define CSD_CSHIELDPADS_PORT            5u
#define CSD_CSHIELDPADS_PIN             2u
#define CSD_VREF_EXT_PORT               5u
#define CSD_VREF_EXT_PIN                3u
#define CSD_VREF_EXT_HSCOMP_PORT        5u
#define CSD_VREF_EXT_HSCOMP_PIN         3u
#define LPCOMP_IN_N0_PORT               1u
#define LPCOMP_IN_N0_PIN                5u
#define LPCOMP_IN_N1_PORT               1u
#define LPCOMP_IN_N1_PIN                2u
#define LPCOMP_IN_P0_PORT               1u
#define LPCOMP_IN_P0_PIN                6u
#define LPCOMP_IN_P1_PORT               1u
#define LPCOMP_IN_P1_PIN                1u
#define PASS0_CTB0_OA0_OUT_10X_PORT     3u
#define PASS0_CTB0_OA0_OUT_10X_PIN      5u
#define PASS0_CTB0_OA1_OUT_10X_PORT     3u
#define PASS0_CTB0_OA1_OUT_10X_PIN      4u
#define PASS0_CTB0_PADS0_PORT           3u
#define PASS0_CTB0_PADS0_PIN            7u
#define PASS0_CTB0_PADS1_PORT           3u
#define PASS0_CTB0_PADS1_PIN            6u
#define PASS0_CTB0_PADS2_PORT           3u
#define PASS0_CTB0_PADS2_PIN            5u
#define PASS0_CTB0_PADS3_PORT           3u
#define PASS0_CTB0_PADS3_PIN            4u
#define PASS0_CTB0_PADS4_PORT           3u
#define PASS0_CTB0_PADS4_PIN            3u
#define PASS0_CTB0_PADS5_PORT           3u
#define PASS0_CTB0_PADS5_PIN            2u
#define PASS0_CTB0_PADS6_PORT           3u
#define PASS0_CTB0_PADS6_PIN            1u
#define PASS0_CTB0_PADS7_PORT           3u
#define PASS0_CTB0_PADS7_PIN            0u
#define PASS0_SAR_EXT_VREF0_PORT        3u
#define PASS0_SAR_EXT_VREF0_PIN         0u
#define PASS0_SAR_EXT_VREF1_PORT        3u
#define PASS0_SAR_EXT_VREF1_PIN         0u
#define PASS0_SARMUX_PADS0_PORT         2u
#define PASS0_SARMUX_PADS0_PIN          0u
#define PASS0_SARMUX_PADS1_PORT         2u
#define PASS0_SARMUX_PADS1_PIN          1u
#define PASS0_SARMUX_PADS2_PORT         2u
#define PASS0_SARMUX_PADS2_PIN          2u
#define PASS0_SARMUX_PADS3_PORT         2u
#define PASS0_SARMUX_PADS3_PIN          3u
#define PASS0_SARMUX_PADS4_PORT         2u
#define PASS0_SARMUX_PADS4_PIN          4u
#define PASS0_SARMUX_PADS5_PORT         2u
#define PASS0_SARMUX_PADS5_PIN          5u
#define PASS0_SARMUX_PADS6_PORT         2u
#define PASS0_SARMUX_PADS6_PIN          6u
#define PASS0_SARMUX_PADS7_PORT         2u
#define PASS0_SARMUX_PADS7_PIN          7u
#define USBPD0_LSRX_GPIO_NOESD_PORT     0u
#define USBPD0_LSRX_GPIO_NOESD_PIN      7u
#define USBPD0_LSTX_GPIO_NOESD_PORT     0u
#define USBPD0_LSTX_GPIO_NOESD_PIN      6u
#define USBPD0_PAD_USBPHY_DM_BCH_DET0_PORT 8u
#define USBPD0_PAD_USBPHY_DM_BCH_DET0_PIN 1u
#define USBPD0_PAD_USBPHY_DP_BCH_DET0_PORT 8u
#define USBPD0_PAD_USBPHY_DP_BCH_DET0_PIN 0u
#define USBPD0_SBU_NOESD0_PORT          6u
#define USBPD0_SBU_NOESD0_PIN           3u
#define USBPD0_SBU_NOESD1_PORT          6u
#define USBPD0_SBU_NOESD1_PIN           2u
#define USBPD1_LSRX_GPIO_NOESD_PORT     0u
#define USBPD1_LSRX_GPIO_NOESD_PIN      0u
#define USBPD1_LSTX_GPIO_NOESD_PORT     0u
#define USBPD1_LSTX_GPIO_NOESD_PIN      1u
#define USBPD1_SBU_NOESD0_PORT          6u
#define USBPD1_SBU_NOESD0_PIN           0u
#define USBPD1_SBU_NOESD1_PORT          6u
#define USBPD1_SBU_NOESD1_PIN           1u

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
    P0_0_CSD_SENSE                  =  4,       /* csd.sense:14 */
    P0_0_CSD_SHIELD                 =  5,       /* csd.shield:14 */
    P0_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_0_USBPD1_SBU_LSRX            = 12,       /* Digital Deep Sleep - usbpd[1].sbu_lsrx */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_1_CSD_SENSE                  =  4,       /* csd.sense:15 */
    P0_1_CSD_SHIELD                 =  5,       /* csd.shield:15 */
    P0_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_1_USBPD1_SBU_LSTX            = 12,       /* Digital Deep Sleep - usbpd[1].sbu_lstx */

    /* P0.2 */
    P0_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_2_CSD_SENSE                  =  4,       /* csd.sense:16 */
    P0_2_CSD_SHIELD                 =  5,       /* csd.shield:16 */
    P0_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_2_USBPD1_SBU_DBG1            = 12,       /* Digital Deep Sleep - usbpd[1].sbu_dbg1 */

    /* P0.3 */
    P0_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_3_CSD_SENSE                  =  4,       /* csd.sense:17 */
    P0_3_CSD_SHIELD                 =  5,       /* csd.shield:17 */
    P0_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_3_USBPD1_SBU_DBG2            = 12,       /* Digital Deep Sleep - usbpd[1].sbu_dbg2 */

    /* P0.4 */
    P0_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_4_CSD_SENSE                  =  4,       /* csd.sense:22 */
    P0_4_CSD_SHIELD                 =  5,       /* csd.shield:22 */
    P0_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_4_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1] */
    P0_4_TCPWM_TR_COMPARE_MATCH1    =  9,       /* Digital Active - tcpwm.tr_compare_match[1] */
    P0_4_TCPWM_TR_IN1               = 11,       /* Digital Active - tcpwm.tr_in[1] */
    P0_4_USBPD0_SBU_DBG2            = 12,       /* Digital Deep Sleep - usbpd[0].sbu_dbg2 */

    /* P0.5 */
    P0_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_5_CSD_SENSE                  =  4,       /* csd.sense:23 */
    P0_5_CSD_SHIELD                 =  5,       /* csd.shield:23 */
    P0_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_5_USBPD0_SBU_DBG1            = 12,       /* Digital Deep Sleep - usbpd[0].sbu_dbg1 */

    /* P0.6 */
    P0_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_6_CSD_SENSE                  =  4,       /* csd.sense:25 */
    P0_6_CSD_SHIELD                 =  5,       /* csd.shield:25 */
    P0_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_6_USBPD0_SBU_LSTX            = 12,       /* Digital Deep Sleep - usbpd[0].sbu_lstx */

    /* P0.7 */
    P0_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_7_CSD_SENSE                  =  4,       /* csd.sense:26 */
    P0_7_CSD_SHIELD                 =  5,       /* csd.shield:26 */
    P0_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_7_USBPD0_SBU_LSRX            = 12,       /* Digital Deep Sleep - usbpd[0].sbu_lsrx */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_0_CSD_SENSE                  =  4,       /* csd.sense:29 */
    P1_0_CSD_SHIELD                 =  5,       /* csd.shield:29 */
    P1_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_0_USBPD1_GPIO_DDFT1          = 13,       /* Digital Deep Sleep - usbpd[1].gpio_ddft1 */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_1_CSD_SENSE                  =  4,       /* csd.sense:27 */
    P1_1_CSD_SHIELD                 =  5,       /* csd.shield:27 */
    P1_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_1_PASS0_DSI_SAR_SAMPLE_DONE  =  9,       /* Digital Active - pass[0].dsi_sar_sample_done */
    P1_1_SCB3_UART_RX               = 10,       /* Digital Active - scb[3].uart_rx:0 */
    P1_1_CSD_COMP                   = 11,       /* Digital Active - csd.comp */
    P1_1_CPUSS_SWD_CLK              = 12,       /* Digital Deep Sleep - cpuss.swd_clk:0 */
    P1_1_USBPD0_TX_DATA             = 13,       /* Digital Deep Sleep - usbpd[0].tx_data */
    P1_1_SCB3_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[3].spi_clk:0 */
    P1_1_SCB3_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[3].i2c_scl:0 */

    /* P1.2 */
    P1_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_2_CSD_SENSE                  =  4,       /* csd.sense:28 */
    P1_2_CSD_SHIELD                 =  5,       /* csd.shield:28 */
    P1_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_2_PASS0_TR_SAR_OUT           =  9,       /* Digital Active - pass[0].tr_sar_out */
    P1_2_SCB3_UART_TX               = 10,       /* Digital Active - scb[3].uart_tx:0 */
    P1_2_CPUSS_SWD_DATA             = 12,       /* Digital Deep Sleep - cpuss.swd_data:0 */
    P1_2_USBPD0_GPIO_DDFT1          = 13,       /* Digital Deep Sleep - usbpd[0].gpio_ddft1 */
    P1_2_SCB3_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[3].spi_miso:0 */
    P1_2_SCB3_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[3].i2c_sda:0 */

    /* P1.3 */
    P1_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_3_CSD_SENSE                  =  4,       /* csd.sense:34 */
    P1_3_CSD_SHIELD                 =  5,       /* csd.shield:34 */
    P1_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_3_TCPWM_LINE4                =  8,       /* Digital Active - tcpwm.line[4] */
    P1_3_TCPWM_TR_COMPARE_MATCH4    =  9,       /* Digital Active - tcpwm.tr_compare_match[4] */
    P1_3_SCB3_UART_CTS              = 10,       /* Digital Active - scb[3].uart_cts:0 */
    P1_3_TCPWM_TR_IN4               = 11,       /* Digital Active - tcpwm.tr_in[4] */
    P1_3_USBPD0_ADC_CMP_OUT_GPIO0   = 13,       /* Digital Deep Sleep - usbpd[0].adc_cmp_out_gpio[0] */
    P1_3_SCB3_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[3].spi_mosi:0 */

    /* P1.4 */
    P1_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_4_CSD_SENSE                  =  4,       /* csd.sense:30 */
    P1_4_CSD_SHIELD                 =  5,       /* csd.shield:30 */
    P1_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_4_TCPWM_LINE5                =  8,       /* Digital Active - tcpwm.line[5] */
    P1_4_TCPWM_TR_COMPARE_MATCH5    =  9,       /* Digital Active - tcpwm.tr_compare_match[5] */
    P1_4_SCB3_UART_RTS              = 10,       /* Digital Active - scb[3].uart_rts:0 */
    P1_4_TCPWM_TR_IN5               = 11,       /* Digital Active - tcpwm.tr_in[5] */
    P1_4_USBPD0_HPD                 = 13,       /* Digital Deep Sleep - usbpd[0].hpd */
    P1_4_SCB3_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[3].spi_select0:0 */

    /* P1.5 */
    P1_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_5_CSD_SENSE                  =  4,       /* csd.sense:33 */
    P1_5_CSD_SHIELD                 =  5,       /* csd.shield:33 */
    P1_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_5_PASS0_DSI_SAR_DATA2        =  9,       /* Digital Active - pass[0].dsi_sar_data[2]:0 */
    P1_5_SCB1_UART_TX               = 10,       /* Digital Active - scb[1].uart_tx:0 */
    P1_5_USBPD0_FAULT_GPIO0         = 13,       /* Digital Deep Sleep - usbpd[0].fault_gpio0 */
    P1_5_SCB1_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[1].spi_miso:0 */
    P1_5_SCB1_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[1].i2c_sda:0 */

    /* P1.6 */
    P1_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_6_CSD_SENSE                  =  4,       /* csd.sense:35 */
    P1_6_CSD_SHIELD                 =  5,       /* csd.shield:35 */
    P1_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_6_SRSS_EXT_CLK               =  8,       /* Digital Active - srss.ext_clk:0 */
    P1_6_SCB1_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[1].spi_clk:0 */
    P1_6_SCB1_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[1].i2c_scl:0 */

    /* P2.0 */
    P2_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_0_CSD_SENSE                  =  4,       /* csd.sense:0 */
    P2_0_CSD_SHIELD                 =  5,       /* csd.shield:0 */
    P2_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_0_SCB5_UART_RTS              = 10,       /* Digital Active - scb[5].uart_rts:0 */
    P2_0_USBPD1_TX_DATA_EN          = 13,       /* Digital Deep Sleep - usbpd[1].tx_data_en */
    P2_0_SCB5_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[5].spi_select0:0 */

    /* P2.1 */
    P2_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_1_CSD_SENSE                  =  4,       /* csd.sense:1 */
    P2_1_CSD_SHIELD                 =  5,       /* csd.shield:1 */
    P2_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_1_TCPWM_LINE2                =  8,       /* Digital Active - tcpwm.line[2] */
    P2_1_TCPWM_TR_COMPARE_MATCH2    =  9,       /* Digital Active - tcpwm.tr_compare_match[2] */
    P2_1_SCB0_UART_RTS              = 10,       /* Digital Active - scb[0].uart_rts:0 */
    P2_1_TCPWM_TR_IN2               = 11,       /* Digital Active - tcpwm.tr_in[2] */
    P2_1_USBPD0_SWAPT_IN            = 13,       /* Digital Deep Sleep - usbpd[0].swapt_in */
    P2_1_SCB0_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[0].spi_select0:0 */

    /* P2.2 */
    P2_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_2_CSD_SENSE                  =  4,       /* csd.sense:2 */
    P2_2_CSD_SHIELD                 =  5,       /* csd.shield:2 */
    P2_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_2_SCB5_UART_TX               = 10,       /* Digital Active - scb[5].uart_tx:0 */
    P2_2_USBPD0_AFC_TX_DATA_EN      = 12,       /* Digital Deep Sleep - usbpd[0].afc_tx_data_en:1 */
    P2_2_SCB5_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[5].spi_miso:0 */
    P2_2_SCB5_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[5].i2c_sda:0 */

    /* P2.3 */
    P2_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_3_CSD_SENSE                  =  4,       /* csd.sense:3 */
    P2_3_CSD_SHIELD                 =  5,       /* csd.shield:3 */
    P2_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_3_SCB5_UART_RX               = 10,       /* Digital Active - scb[5].uart_rx:0 */
    P2_3_USBPD0_AFC_TX_DATA0        = 12,       /* Digital Deep Sleep - usbpd[0].afc_tx_data[0]:1 */
    P2_3_SCB5_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[5].spi_clk:0 */
    P2_3_SCB5_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[5].i2c_scl:0 */

    /* P2.4 */
    P2_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_4_CSD_SENSE                  =  4,       /* csd.sense:4 */
    P2_4_CSD_SHIELD                 =  5,       /* csd.shield:4 */
    P2_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_4_TCPWM_LINE3                =  8,       /* Digital Active - tcpwm.line[3] */
    P2_4_TCPWM_TR_COMPARE_MATCH3    =  9,       /* Digital Active - tcpwm.tr_compare_match[3] */
    P2_4_SCB0_UART_CTS              = 10,       /* Digital Active - scb[0].uart_cts:0 */
    P2_4_TCPWM_TR_IN3               = 11,       /* Digital Active - tcpwm.tr_in[3] */
    P2_4_USBPD0_AFC_TX_DATA_EN      = 12,       /* Digital Deep Sleep - usbpd[0].afc_tx_data_en:0 */
    P2_4_USBPD1_GPIO_DDFT0          = 13,       /* Digital Deep Sleep - usbpd[1].gpio_ddft0 */
    P2_4_SCB0_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[0].spi_miso:0 */

    /* P2.5 */
    P2_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_5_CSD_SENSE                  =  4,       /* csd.sense:5 */
    P2_5_CSD_SHIELD                 =  5,       /* csd.shield:5 */
    P2_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_5_SCB5_UART_CTS              = 10,       /* Digital Active - scb[5].uart_cts:0 */
    P2_5_USBPD1_DDFT1               = 13,       /* Digital Deep Sleep - usbpd[1].ddft1 */
    P2_5_SCB5_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[5].spi_mosi:0 */

    /* P2.6 */
    P2_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_6_CSD_SENSE                  =  4,       /* csd.sense:6 */
    P2_6_CSD_SHIELD                 =  5,       /* csd.shield:6 */
    P2_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_6_SCB1_UART_RTS              = 10,       /* Digital Active - scb[1].uart_rts:0 */
    P2_6_USBPD1_SWAPT_IN            = 13,       /* Digital Deep Sleep - usbpd[1].swapt_in */
    P2_6_SCB1_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[1].spi_mosi:0 */

    /* P2.7 */
    P2_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_7_CSD_SENSE                  =  4,       /* csd.sense:7 */
    P2_7_CSD_SHIELD                 =  5,       /* csd.shield:7 */
    P2_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_7_SCB1_UART_CTS              = 10,       /* Digital Active - scb[1].uart_cts:0 */
    P2_7_USBPD1_FAULT_GPIO0         = 13,       /* Digital Deep Sleep - usbpd[1].fault_gpio0 */
    P2_7_SCB1_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[1].spi_select0:0 */

    /* P3.0 */
    P3_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_0_CSD_SENSE                  =  4,       /* csd.sense:49 */
    P3_0_CSD_SHIELD                 =  5,       /* csd.shield:49 */
    P3_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_0_TCPWM_LINE6                =  8,       /* Digital Active - tcpwm.line[6] */
    P3_0_TCPWM_TR_COMPARE_MATCH6    =  9,       /* Digital Active - tcpwm.tr_compare_match[6] */
    P3_0_SCB4_UART_CTS              = 10,       /* Digital Active - scb[4].uart_cts:0 */
    P3_0_TCPWM_TR_IN6               = 11,       /* Digital Active - tcpwm.tr_in[6] */
    P3_0_USBPD0_AFC_TX_DATA0        = 12,       /* Digital Deep Sleep - usbpd[0].afc_tx_data[0]:0 */
    P3_0_USBPD0_GPIO_DDFT0          = 13,       /* Digital Deep Sleep - usbpd[0].gpio_ddft0 */
    P3_0_SCB4_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[4].spi_mosi:0 */

    /* P3.1 */
    P3_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_1_CSD_SENSE                  =  4,       /* csd.sense:48 */
    P3_1_CSD_SHIELD                 =  5,       /* csd.shield:48 */
    P3_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_1_PASS0_DSI_SAR_DATA11       =  9,       /* Digital Active - pass[0].dsi_sar_data[11]:0 */
    P3_1_USBPD1_SWAPT_OUT0          = 13,       /* Digital Deep Sleep - usbpd[1].swapt_out[0] */

    /* P3.2 */
    P3_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_2_CSD_SENSE                  =  4,       /* csd.sense:47 */
    P3_2_CSD_SHIELD                 =  5,       /* csd.shield:47 */
    P3_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_2_PASS0_DSI_SAR_DATA10       =  9,       /* Digital Active - pass[0].dsi_sar_data[10]:0 */
    P3_2_USBPD1_SWAPT_OUT1          = 13,       /* Digital Deep Sleep - usbpd[1].swapt_out[1] */

    /* P3.3 */
    P3_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_3_CSD_SENSE                  =  4,       /* csd.sense:46 */
    P3_3_CSD_SHIELD                 =  5,       /* csd.shield:46 */
    P3_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_3_TCPWM_LINE7                =  8,       /* Digital Active - tcpwm.line[7] */
    P3_3_TCPWM_TR_COMPARE_MATCH7    =  9,       /* Digital Active - tcpwm.tr_compare_match[7] */
    P3_3_SCB4_UART_RTS              = 10,       /* Digital Active - scb[4].uart_rts:0 */
    P3_3_TCPWM_TR_IN7               = 11,       /* Digital Active - tcpwm.tr_in[7] */
    P3_3_USB_VBUS_VALID             = 13,       /* Digital Deep Sleep - usb.vbus_valid */
    P3_3_SCB4_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[4].spi_select0:0 */

    /* P3.4 */
    P3_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_4_CSD_SENSE                  =  4,       /* csd.sense:45 */
    P3_4_CSD_SHIELD                 =  5,       /* csd.shield:45 */
    P3_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_4_PASS0_DSI_SAR_DATA9        =  9,       /* Digital Active - pass[0].dsi_sar_data[9]:0 */

    /* P3.5 */
    P3_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_5_CSD_SENSE                  =  4,       /* csd.sense:44 */
    P3_5_CSD_SHIELD                 =  5,       /* csd.shield:44 */
    P3_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_5_PASS0_DSI_SAR_DATA_VALID   =  9,       /* Digital Active - pass[0].dsi_sar_data_valid */
    P3_5_SCB4_UART_RX               = 10,       /* Digital Active - scb[4].uart_rx:0 */
    P3_5_SCB4_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[4].spi_clk:0 */
    P3_5_SCB4_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[4].i2c_scl:0 */

    /* P3.6 */
    P3_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_6_CSD_SENSE                  =  4,       /* csd.sense:43 */
    P3_6_CSD_SHIELD                 =  5,       /* csd.shield:43 */
    P3_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_6_PASS0_DSI_SAR_DATA7        =  9,       /* Digital Active - pass[0].dsi_sar_data[7]:0 */
    P3_6_SCB4_UART_TX               = 10,       /* Digital Active - scb[4].uart_tx:0 */
    P3_6_SCB4_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[4].spi_miso:0 */
    P3_6_SCB4_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[4].i2c_sda:0 */

    /* P3.7 */
    P3_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_7_CSD_SENSE                  =  4,       /* csd.sense:42 */
    P3_7_CSD_SHIELD                 =  5,       /* csd.shield:42 */
    P3_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_7_PASS0_DSI_SAR_DATA8        =  9,       /* Digital Active - pass[0].dsi_sar_data[8]:0 */

    /* P4.0 */
    P4_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_0_CSD_SENSE                  =  4,       /* csd.sense:31 */
    P4_0_CSD_SHIELD                 =  5,       /* csd.shield:31 */
    P4_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_0_PASS0_DSI_SAR_DATA3        =  9,       /* Digital Active - pass[0].dsi_sar_data[3]:0 */
    P4_0_SCB0_UART_RX               = 10,       /* Digital Active - scb[0].uart_rx:0 */
    P4_0_USBPD0_DDFT1               = 13,       /* Digital Deep Sleep - usbpd[0].ddft1 */
    P4_0_SCB0_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[0].spi_clk:0 */
    P4_0_SCB0_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */

    /* P4.1 */
    P4_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_1_CSD_SENSE                  =  4,       /* csd.sense:32 */
    P4_1_CSD_SHIELD                 =  5,       /* csd.shield:32 */
    P4_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_1_PASS0_DSI_SAR_DATA4        =  9,       /* Digital Active - pass[0].dsi_sar_data[4]:0 */
    P4_1_SCB0_UART_TX               = 10,       /* Digital Active - scb[0].uart_tx:0 */
    P4_1_USBPD0_DDFT0               = 13,       /* Digital Deep Sleep - usbpd[0].ddft0 */
    P4_1_SCB0_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[0].spi_mosi:0 */
    P4_1_SCB0_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */

    /* P5.0 */
    P5_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_0_CSD_SENSE                  =  4,       /* csd.sense:41 */
    P5_0_CSD_SHIELD                 =  5,       /* csd.shield:41 */
    P5_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_0_PASS0_DSI_SAR_DATA6        =  9,       /* Digital Active - pass[0].dsi_sar_data[6]:0 */
    P5_0_SCB2_UART_RX               = 10,       /* Digital Active - scb[2].uart_rx:0 */
    P5_0_USBPD0_FAULT_GPIO1         = 13,       /* Digital Deep Sleep - usbpd[0].fault_gpio1 */
    P5_0_SCB2_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[2].spi_clk:0 */
    P5_0_SCB2_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[2].i2c_scl:0 */

    /* P5.1 */
    P5_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_1_CSD_SENSE                  =  4,       /* csd.sense:40 */
    P5_1_CSD_SHIELD                 =  5,       /* csd.shield:40 */
    P5_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_1_PASS0_DSI_SAR_DATA5        =  9,       /* Digital Active - pass[0].dsi_sar_data[5]:0 */
    P5_1_SCB2_UART_TX               = 10,       /* Digital Active - scb[2].uart_tx:0 */
    P5_1_USBPD1_TX_DATA             = 13,       /* Digital Deep Sleep - usbpd[1].tx_data */
    P5_1_SCB2_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[2].spi_mosi:0 */
    P5_1_SCB2_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[2].i2c_sda:0 */

    /* P5.2 */
    P5_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_2_CSD_SENSE                  =  4,       /* csd.sense:39 */
    P5_2_CSD_SHIELD                 =  5,       /* csd.shield:39 */
    P5_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_2_PASS0_DSI_CTB_CMP0         =  9,       /* Digital Active - pass[0].dsi_ctb_cmp0 */
    P5_2_SCB2_UART_CTS              = 10,       /* Digital Active - scb[2].uart_cts:0 */
    P5_2_USBPD0_SWAPT_OUT0          = 13,       /* Digital Deep Sleep - usbpd[0].swapt_out[0] */
    P5_2_SCB2_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[2].spi_miso:0 */
    P5_2_LPCOMP_COMP1               = 15,       /* Digital Deep Sleep - lpcomp.comp[1]:0 */

    /* P5.3 */
    P5_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_3_CSD_SENSE                  =  4,       /* csd.sense:38 */
    P5_3_CSD_SHIELD                 =  5,       /* csd.shield:38 */
    P5_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_3_PASS0_DSI_CTB_CMP1         =  9,       /* Digital Active - pass[0].dsi_ctb_cmp1 */
    P5_3_SCB2_UART_RTS              = 10,       /* Digital Active - scb[2].uart_rts:0 */
    P5_3_USBPD0_SWAPT_OUT1          = 13,       /* Digital Deep Sleep - usbpd[0].swapt_out[1] */
    P5_3_SCB2_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[2].spi_select0:0 */
    P5_3_LPCOMP_COMP0               = 15,       /* Digital Deep Sleep - lpcomp.comp[0]:0 */

    /* P5.4 */
    P5_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_4_CSD_SENSE                  =  4,       /* csd.sense:37 */
    P5_4_CSD_SHIELD                 =  5,       /* csd.shield:37 */
    P5_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_4_AMUXB                      =  7,       /* AMUXBUS B connection. */

    /* P5.5 */
    P5_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_5_CSD_SENSE                  =  4,       /* csd.sense:36 */
    P5_5_CSD_SHIELD                 =  5,       /* csd.shield:36 */
    P5_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_5_USBPD0_TX_DATA_EN          = 13,       /* Digital Deep Sleep - usbpd[0].tx_data_en */

    /* P6.0 */
    P6_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P6_0_CSD_SENSE                  =  4,       /* csd.sense:18 */
    P6_0_CSD_SHIELD                 =  5,       /* csd.shield:18 */
    P6_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P6_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P6_0_SRSS_EXT_CLK               =  8,       /* Digital Active - srss.ext_clk:1 */
    P6_0_PASS0_DSI_SAR_DATA0        =  9,       /* Digital Active - pass[0].dsi_sar_data[0]:0 */
    P6_0_SCB6_UART_TX               = 10,       /* Digital Active - scb[6].uart_tx:0 */
    P6_0_USBPD1_SBU_IO1             = 12,       /* Digital Deep Sleep - usbpd[1].sbu_io1 */
    P6_0_SCB6_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[6].spi_miso:0 */
    P6_0_SCB6_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[6].i2c_sda:0 */

    /* P6.1 */
    P6_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P6_1_CSD_SENSE                  =  4,       /* csd.sense:19 */
    P6_1_CSD_SHIELD                 =  5,       /* csd.shield:19 */
    P6_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P6_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P6_1_PASS0_DSI_SAR_DATA1        =  9,       /* Digital Active - pass[0].dsi_sar_data[1]:0 */
    P6_1_SCB6_UART_RX               = 10,       /* Digital Active - scb[6].uart_rx:0 */
    P6_1_USBPD1_SBU_IO2             = 12,       /* Digital Deep Sleep - usbpd[1].sbu_io2 */
    P6_1_SCB6_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[6].spi_clk:0 */
    P6_1_SCB6_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[6].i2c_scl:0 */

    /* P6.2 */
    P6_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P6_2_CSD_SENSE                  =  4,       /* csd.sense:21 */
    P6_2_CSD_SHIELD                 =  5,       /* csd.shield:21 */
    P6_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P6_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P6_2_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0] */
    P6_2_TCPWM_TR_COMPARE_MATCH0    =  9,       /* Digital Active - tcpwm.tr_compare_match[0] */
    P6_2_SCB6_UART_RTS              = 10,       /* Digital Active - scb[6].uart_rts:0 */
    P6_2_TCPWM_TR_IN0               = 11,       /* Digital Active - tcpwm.tr_in[0] */
    P6_2_USBPD0_SBU_IO2             = 12,       /* Digital Deep Sleep - usbpd[0].sbu_io2 */
    P6_2_SCB6_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[6].spi_select0:0 */

    /* P6.3 */
    P6_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P6_3_CSD_SENSE                  =  4,       /* csd.sense:20 */
    P6_3_CSD_SHIELD                 =  5,       /* csd.shield:20 */
    P6_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P6_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P6_3_SCB6_UART_CTS              = 10,       /* Digital Active - scb[6].uart_cts:0 */
    P6_3_USBPD0_SBU_IO1             = 12,       /* Digital Deep Sleep - usbpd[0].sbu_io1 */
    P6_3_SCB6_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[6].spi_mosi:0 */

    /* P7.0 */
    P7_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_0_CSD_SENSE                  =  4,       /* csd.sense:12 */
    P7_0_CSD_SHIELD                 =  5,       /* csd.shield:12 */
    P7_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_0_SCB1_UART_RX               = 10,       /* Digital Active - scb[1].uart_rx:0 */
    P7_0_USBPD1_FAULT_GPIO1         = 13,       /* Digital Deep Sleep - usbpd[1].fault_gpio1 */

    /* P7.1 */
    P7_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_1_CSD_SENSE                  =  4,       /* csd.sense:24 */
    P7_1_CSD_SHIELD                 =  5,       /* csd.shield:24 */
    P7_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_1_USBPD1_HPD                 = 13,       /* Digital Deep Sleep - usbpd[1].hpd */

    /* P7.2 */
    P7_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_2_CSD_SENSE                  =  4,       /* csd.sense:13 */
    P7_2_CSD_SHIELD                 =  5,       /* csd.shield:13 */
    P7_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_2_AMUXB                      =  7,       /* AMUXBUS B connection. */

    /* P7.3 */
    P7_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_3_CSD_SENSE                  =  4,       /* csd.sense:8 */
    P7_3_CSD_SHIELD                 =  5,       /* csd.shield:8 */
    P7_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_3_SCB7_UART_TX               = 10,       /* Digital Active - scb[7].uart_tx:0 */
    P7_3_SCB7_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[7].spi_miso:0 */
    P7_3_SCB7_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[7].i2c_sda:0 */

    /* P7.4 */
    P7_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_4_CSD_SENSE                  =  4,       /* csd.sense:9 */
    P7_4_CSD_SHIELD                 =  5,       /* csd.shield:9 */
    P7_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_4_SCB7_UART_RX               = 10,       /* Digital Active - scb[7].uart_rx:0 */
    P7_4_SCB7_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[7].spi_clk:0 */
    P7_4_SCB7_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[7].i2c_scl:0 */

    /* P7.5 */
    P7_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_5_CSD_SENSE                  =  4,       /* csd.sense:10 */
    P7_5_CSD_SHIELD                 =  5,       /* csd.shield:10 */
    P7_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_5_SCB7_UART_CTS              = 10,       /* Digital Active - scb[7].uart_cts:0 */
    P7_5_USBPD1_DDFT0               = 13,       /* Digital Deep Sleep - usbpd[1].ddft0 */
    P7_5_SCB7_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[7].spi_mosi:0 */

    /* P7.6 */
    P7_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_6_CSD_SENSE                  =  4,       /* csd.sense:11 */
    P7_6_CSD_SHIELD                 =  5,       /* csd.shield:11 */
    P7_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_6_SCB7_UART_RTS              = 10,       /* Digital Active - scb[7].uart_rts:0 */
    P7_6_USBPD1_ADC_CMP_OUT_GPIO0   = 13,       /* Digital Deep Sleep - usbpd[1].adc_cmp_out_gpio[0] */
    P7_6_SCB7_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[7].spi_select0:0 */

    /* USBDP */
    USBDP_GPIO                      =  0,       /* SW controlled GPIO. */

    /* USBDM */
    USBDM_GPIO                      =  0        /* SW controlled GPIO. */
} en_hsiom_sel_t;

#endif /* _GPIO_PMG1S3_97_BGA_CYPM1322_H_ */


/* [] END OF FILE */
