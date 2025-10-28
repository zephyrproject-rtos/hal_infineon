/***************************************************************************//**
* \file gpio_psoc4100smax_100_tqfp.h
*
* \brief
* PSOC4100Smax device GPIO header for 100-TQFP package
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

#ifndef _GPIO_PSOC4100SMAX_100_TQFP_H_
#define _GPIO_PSOC4100SMAX_100_TQFP_H_

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

#define CY_GPIO_PACKAGE_TYPE            CY_GPIO_PACKAGE_TQFP
#define CY_GPIO_PIN_COUNT               100u

/* AMUXBUS Segments */
enum
{
    AMUXBUS_MSC0,
    AMUXBUS_MSC1,
    AMUXBUS_PASS,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_0                = 0x0000u,  /* Left = AMUXBUS_MSC1; Right = AMUXBUS_PASS */
    AMUX_SPLIT_CTL_1                = 0x0001u,  /* Left = AMUXBUS_PASS; Right = AMUXBUS_MSC0 */
    AMUX_SPLIT_CTL_2                = 0x0002u   /* Left = AMUXBUS_MSC0; Right = AMUXBUS_MSC1 */
} cy_en_amux_split_t;

/* Port List */
/* PORT 0 (GPIO) */
#define P0_0_PORT                       GPIO_PRT0
#define P0_0_PIN                        0u
#define P0_0_NUM                        0u
#define P0_0_AMUXSEGMENT                AMUXBUS_MSC1
#define P0_1_PORT                       GPIO_PRT0
#define P0_1_PIN                        1u
#define P0_1_NUM                        1u
#define P0_1_AMUXSEGMENT                AMUXBUS_MSC1
#define P0_2_PORT                       GPIO_PRT0
#define P0_2_PIN                        2u
#define P0_2_NUM                        2u
#define P0_2_AMUXSEGMENT                AMUXBUS_MSC1
#define P0_3_PORT                       GPIO_PRT0
#define P0_3_PIN                        3u
#define P0_3_NUM                        3u
#define P0_3_AMUXSEGMENT                AMUXBUS_MSC1
#define P0_4_PORT                       GPIO_PRT0
#define P0_4_PIN                        4u
#define P0_4_NUM                        4u
#define P0_4_AMUXSEGMENT                AMUXBUS_MSC1
#define P0_5_PORT                       GPIO_PRT0
#define P0_5_PIN                        5u
#define P0_5_NUM                        5u
#define P0_5_AMUXSEGMENT                AMUXBUS_MSC1
#define P0_6_PORT                       GPIO_PRT0
#define P0_6_PIN                        6u
#define P0_6_NUM                        6u
#define P0_6_AMUXSEGMENT                AMUXBUS_MSC1
#define P0_7_PORT                       GPIO_PRT0
#define P0_7_PIN                        7u
#define P0_7_NUM                        7u
#define P0_7_AMUXSEGMENT                AMUXBUS_MSC1

/* PORT 1 (GPIO) */
#define P1_0_PORT                       GPIO_PRT1
#define P1_0_PIN                        0u
#define P1_0_NUM                        0u
#define P1_0_AMUXSEGMENT                AMUXBUS_PASS
#define P1_1_PORT                       GPIO_PRT1
#define P1_1_PIN                        1u
#define P1_1_NUM                        1u
#define P1_1_AMUXSEGMENT                AMUXBUS_PASS
#define P1_2_PORT                       GPIO_PRT1
#define P1_2_PIN                        2u
#define P1_2_NUM                        2u
#define P1_2_AMUXSEGMENT                AMUXBUS_PASS
#define P1_3_PORT                       GPIO_PRT1
#define P1_3_PIN                        3u
#define P1_3_NUM                        3u
#define P1_3_AMUXSEGMENT                AMUXBUS_PASS
#define P1_4_PORT                       GPIO_PRT1
#define P1_4_PIN                        4u
#define P1_4_NUM                        4u
#define P1_4_AMUXSEGMENT                AMUXBUS_PASS
#define P1_5_PORT                       GPIO_PRT1
#define P1_5_PIN                        5u
#define P1_5_NUM                        5u
#define P1_5_AMUXSEGMENT                AMUXBUS_PASS
#define P1_6_PORT                       GPIO_PRT1
#define P1_6_PIN                        6u
#define P1_6_NUM                        6u
#define P1_6_AMUXSEGMENT                AMUXBUS_PASS
#define P1_7_PORT                       GPIO_PRT1
#define P1_7_PIN                        7u
#define P1_7_NUM                        7u
#define P1_7_AMUXSEGMENT                AMUXBUS_PASS

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
#define P3_0_AMUXSEGMENT                AMUXBUS_MSC0
#define P3_1_PORT                       GPIO_PRT3
#define P3_1_PIN                        1u
#define P3_1_NUM                        1u
#define P3_1_AMUXSEGMENT                AMUXBUS_MSC0
#define P3_2_PORT                       GPIO_PRT3
#define P3_2_PIN                        2u
#define P3_2_NUM                        2u
#define P3_2_AMUXSEGMENT                AMUXBUS_MSC0
#define P3_3_PORT                       GPIO_PRT3
#define P3_3_PIN                        3u
#define P3_3_NUM                        3u
#define P3_3_AMUXSEGMENT                AMUXBUS_MSC0
#define P3_4_PORT                       GPIO_PRT3
#define P3_4_PIN                        4u
#define P3_4_NUM                        4u
#define P3_4_AMUXSEGMENT                AMUXBUS_MSC0
#define P3_5_PORT                       GPIO_PRT3
#define P3_5_PIN                        5u
#define P3_5_NUM                        5u
#define P3_5_AMUXSEGMENT                AMUXBUS_MSC0
#define P3_6_PORT                       GPIO_PRT3
#define P3_6_PIN                        6u
#define P3_6_NUM                        6u
#define P3_6_AMUXSEGMENT                AMUXBUS_MSC0
#define P3_7_PORT                       GPIO_PRT3
#define P3_7_PIN                        7u
#define P3_7_NUM                        7u
#define P3_7_AMUXSEGMENT                AMUXBUS_MSC0

/* PORT 4 (GPIO) */
#define P4_0_PORT                       GPIO_PRT4
#define P4_0_PIN                        0u
#define P4_0_NUM                        0u
#define P4_0_AMUXSEGMENT                AMUXBUS_MSC0
#define P4_1_PORT                       GPIO_PRT4
#define P4_1_PIN                        1u
#define P4_1_NUM                        1u
#define P4_1_AMUXSEGMENT                AMUXBUS_MSC0
#define P4_2_PORT                       GPIO_PRT4
#define P4_2_PIN                        2u
#define P4_2_NUM                        2u
#define P4_2_AMUXSEGMENT                AMUXBUS_MSC0
#define P4_3_PORT                       GPIO_PRT4
#define P4_3_PIN                        3u
#define P4_3_NUM                        3u
#define P4_3_AMUXSEGMENT                AMUXBUS_MSC0
#define P4_4_PORT                       GPIO_PRT4
#define P4_4_PIN                        4u
#define P4_4_NUM                        4u
#define P4_4_AMUXSEGMENT                AMUXBUS_MSC0
#define P4_5_PORT                       GPIO_PRT4
#define P4_5_PIN                        5u
#define P4_5_NUM                        5u
#define P4_5_AMUXSEGMENT                AMUXBUS_MSC0
#define P4_6_PORT                       GPIO_PRT4
#define P4_6_PIN                        6u
#define P4_6_NUM                        6u
#define P4_6_AMUXSEGMENT                AMUXBUS_MSC0
#define P4_7_PORT                       GPIO_PRT4
#define P4_7_PIN                        7u
#define P4_7_NUM                        7u
#define P4_7_AMUXSEGMENT                AMUXBUS_MSC0

/* PORT 5 (GPIO) */
#define P5_0_PORT                       GPIO_PRT5
#define P5_0_PIN                        0u
#define P5_0_NUM                        0u
#define P5_0_AMUXSEGMENT                AMUXBUS_MSC1
#define P5_1_PORT                       GPIO_PRT5
#define P5_1_PIN                        1u
#define P5_1_NUM                        1u
#define P5_1_AMUXSEGMENT                AMUXBUS_MSC1
#define P5_2_PORT                       GPIO_PRT5
#define P5_2_PIN                        2u
#define P5_2_NUM                        2u
#define P5_2_AMUXSEGMENT                AMUXBUS_MSC1
#define P5_3_PORT                       GPIO_PRT5
#define P5_3_PIN                        3u
#define P5_3_NUM                        3u
#define P5_3_AMUXSEGMENT                AMUXBUS_MSC1
#define P5_4_PORT                       GPIO_PRT5
#define P5_4_PIN                        4u
#define P5_4_NUM                        4u
#define P5_4_AMUXSEGMENT                AMUXBUS_MSC1
#define P5_5_PORT                       GPIO_PRT5
#define P5_5_PIN                        5u
#define P5_5_NUM                        5u
#define P5_5_AMUXSEGMENT                AMUXBUS_MSC1
#define P5_6_PORT                       GPIO_PRT5
#define P5_6_PIN                        6u
#define P5_6_NUM                        6u
#define P5_6_AMUXSEGMENT                AMUXBUS_MSC1
#define P5_7_PORT                       GPIO_PRT5
#define P5_7_PIN                        7u
#define P5_7_NUM                        7u
#define P5_7_AMUXSEGMENT                AMUXBUS_MSC1

/* PORT 6 (GPIO) */
#define P6_0_PORT                       GPIO_PRT6
#define P6_0_PIN                        0u
#define P6_0_NUM                        0u
#define P6_0_AMUXSEGMENT                AMUXBUS_MSC0
#define P6_1_PORT                       GPIO_PRT6
#define P6_1_PIN                        1u
#define P6_1_NUM                        1u
#define P6_1_AMUXSEGMENT                AMUXBUS_MSC0
#define P6_2_PORT                       GPIO_PRT6
#define P6_2_PIN                        2u
#define P6_2_NUM                        2u
#define P6_2_AMUXSEGMENT                AMUXBUS_MSC0
#define P6_3_PORT                       GPIO_PRT6
#define P6_3_PIN                        3u
#define P6_3_NUM                        3u
#define P6_3_AMUXSEGMENT                AMUXBUS_MSC0
#define P6_4_PORT                       GPIO_PRT6
#define P6_4_PIN                        4u
#define P6_4_NUM                        4u
#define P6_4_AMUXSEGMENT                AMUXBUS_MSC0
#define P6_5_PORT                       GPIO_PRT6
#define P6_5_PIN                        5u
#define P6_5_NUM                        5u
#define P6_5_AMUXSEGMENT                AMUXBUS_MSC0

/* PORT 7 (GPIO) */
#define P7_0_PORT                       GPIO_PRT7
#define P7_0_PIN                        0u
#define P7_0_NUM                        0u
#define P7_0_AMUXSEGMENT                AMUXBUS_MSC1
#define P7_1_PORT                       GPIO_PRT7
#define P7_1_PIN                        1u
#define P7_1_NUM                        1u
#define P7_1_AMUXSEGMENT                AMUXBUS_MSC1
#define P7_2_PORT                       GPIO_PRT7
#define P7_2_PIN                        2u
#define P7_2_NUM                        2u
#define P7_2_AMUXSEGMENT                AMUXBUS_MSC1
#define P7_3_PORT                       GPIO_PRT7
#define P7_3_PIN                        3u
#define P7_3_NUM                        3u
#define P7_3_AMUXSEGMENT                AMUXBUS_MSC1
#define P7_4_PORT                       GPIO_PRT7
#define P7_4_PIN                        4u
#define P7_4_NUM                        4u
#define P7_4_AMUXSEGMENT                AMUXBUS_MSC1
#define P7_5_PORT                       GPIO_PRT7
#define P7_5_PIN                        5u
#define P7_5_NUM                        5u
#define P7_5_AMUXSEGMENT                AMUXBUS_MSC1
#define P7_6_PORT                       GPIO_PRT7
#define P7_6_PIN                        6u
#define P7_6_NUM                        6u
#define P7_6_AMUXSEGMENT                AMUXBUS_MSC1
#define P7_7_PORT                       GPIO_PRT7
#define P7_7_PIN                        7u
#define P7_7_NUM                        7u
#define P7_7_AMUXSEGMENT                AMUXBUS_MSC1

/* PORT 8 (GPIO) */
#define P8_0_PORT                       GPIO_PRT8
#define P8_0_PIN                        0u
#define P8_0_NUM                        0u
#define P8_0_AMUXSEGMENT                AMUXBUS_MSC1
#define P8_1_PORT                       GPIO_PRT8
#define P8_1_PIN                        1u
#define P8_1_NUM                        1u
#define P8_1_AMUXSEGMENT                AMUXBUS_MSC1
#define P8_2_PORT                       GPIO_PRT8
#define P8_2_PIN                        2u
#define P8_2_NUM                        2u
#define P8_2_AMUXSEGMENT                AMUXBUS_MSC1
#define P8_3_PORT                       GPIO_PRT8
#define P8_3_PIN                        3u
#define P8_3_NUM                        3u
#define P8_3_AMUXSEGMENT                AMUXBUS_MSC1

/* PORT 9 (GPIO) */
#define P9_0_PORT                       GPIO_PRT9
#define P9_0_PIN                        0u
#define P9_0_NUM                        0u
#define P9_0_AMUXSEGMENT                AMUXBUS_MSC1
#define P9_1_PORT                       GPIO_PRT9
#define P9_1_PIN                        1u
#define P9_1_NUM                        1u
#define P9_1_AMUXSEGMENT                AMUXBUS_MSC1
#define P9_2_PORT                       GPIO_PRT9
#define P9_2_PIN                        2u
#define P9_2_NUM                        2u
#define P9_2_AMUXSEGMENT                AMUXBUS_MSC1
#define P9_3_PORT                       GPIO_PRT9
#define P9_3_PIN                        3u
#define P9_3_NUM                        3u
#define P9_3_AMUXSEGMENT                AMUXBUS_MSC1

/* PORT 10 (GPIO) */
#define P10_0_PORT                      GPIO_PRT10
#define P10_0_PIN                       0u
#define P10_0_NUM                       0u
#define P10_0_AMUXSEGMENT               AMUXBUS_MSC0
#define P10_1_PORT                      GPIO_PRT10
#define P10_1_PIN                       1u
#define P10_1_NUM                       1u
#define P10_1_AMUXSEGMENT               AMUXBUS_MSC0
#define P10_2_PORT                      GPIO_PRT10
#define P10_2_PIN                       2u
#define P10_2_NUM                       2u
#define P10_2_AMUXSEGMENT               AMUXBUS_MSC0
#define P10_3_PORT                      GPIO_PRT10
#define P10_3_PIN                       3u
#define P10_3_NUM                       3u
#define P10_3_AMUXSEGMENT               AMUXBUS_MSC0
#define P10_4_PORT                      GPIO_PRT10
#define P10_4_PIN                       4u
#define P10_4_NUM                       4u
#define P10_4_AMUXSEGMENT               AMUXBUS_MSC0
#define P10_5_PORT                      GPIO_PRT10
#define P10_5_PIN                       5u
#define P10_5_NUM                       5u
#define P10_5_AMUXSEGMENT               AMUXBUS_MSC0

/* PORT 11 (GPIO) */
#define P11_0_PORT                      GPIO_PRT11
#define P11_0_PIN                       0u
#define P11_0_NUM                       0u
#define P11_0_AMUXSEGMENT               AMUXBUS_MSC0
#define P11_1_PORT                      GPIO_PRT11
#define P11_1_PIN                       1u
#define P11_1_NUM                       1u
#define P11_1_AMUXSEGMENT               AMUXBUS_MSC0
#define P11_2_PORT                      GPIO_PRT11
#define P11_2_PIN                       2u
#define P11_2_NUM                       2u
#define P11_2_AMUXSEGMENT               AMUXBUS_MSC0
#define P11_3_PORT                      GPIO_PRT11
#define P11_3_PIN                       3u
#define P11_3_NUM                       3u
#define P11_3_AMUXSEGMENT               AMUXBUS_MSC0
#define P11_4_PORT                      GPIO_PRT11
#define P11_4_PIN                       4u
#define P11_4_NUM                       4u
#define P11_4_AMUXSEGMENT               AMUXBUS_MSC0
#define P11_5_PORT                      GPIO_PRT11
#define P11_5_PIN                       5u
#define P11_5_NUM                       5u
#define P11_5_AMUXSEGMENT               AMUXBUS_MSC0

/* PORT 12 (GPIO) */
#define P12_0_PORT                      GPIO_PRT12
#define P12_0_PIN                       0u
#define P12_0_NUM                       0u
#define P12_0_AMUXSEGMENT               AMUXBUS_MSC0
#define P12_1_PORT                      GPIO_PRT12
#define P12_1_PIN                       1u
#define P12_1_NUM                       1u
#define P12_1_AMUXSEGMENT               AMUXBUS_MSC0

/* Analog Connections */
#define EXCO_ECO_IN_PORT                0u
#define EXCO_ECO_IN_PIN                 6u
#define EXCO_ECO_OUT_PORT               0u
#define EXCO_ECO_OUT_PIN                7u
#define LPCOMP_IN_N0_PORT               0u
#define LPCOMP_IN_N0_PIN                1u
#define LPCOMP_IN_N1_PORT               0u
#define LPCOMP_IN_N1_PIN                3u
#define LPCOMP_IN_P0_PORT               0u
#define LPCOMP_IN_P0_PIN                0u
#define LPCOMP_IN_P1_PORT               0u
#define LPCOMP_IN_P1_PIN                2u
#define MSC0_CMOD1PADD_PORT             4u
#define MSC0_CMOD1PADD_PIN              2u
#define MSC0_CMOD1PADS_PORT             4u
#define MSC0_CMOD1PADS_PIN              2u
#define MSC0_CMOD2PADD_PORT             4u
#define MSC0_CMOD2PADD_PIN              3u
#define MSC0_CMOD2PADS_PORT             4u
#define MSC0_CMOD2PADS_PIN              3u
#define MSC0_CMOD3PADD_PORT             4u
#define MSC0_CMOD3PADD_PIN              0u
#define MSC0_CMOD3PADS_PORT             4u
#define MSC0_CMOD3PADS_PIN              0u
#define MSC0_CMOD4PADD_PORT             4u
#define MSC0_CMOD4PADD_PIN              1u
#define MSC0_CMOD4PADS_PORT             4u
#define MSC0_CMOD4PADS_PIN              1u
#define MSC0_S_PAD0_PORT                6u
#define MSC0_S_PAD0_PIN                 5u
#define MSC0_S_PAD1_PORT                3u
#define MSC0_S_PAD1_PIN                 0u
#define MSC0_S_PAD10_PORT               11u
#define MSC0_S_PAD10_PIN                3u
#define MSC0_S_PAD11_PORT               11u
#define MSC0_S_PAD11_PIN                4u
#define MSC0_S_PAD12_PORT               4u
#define MSC0_S_PAD12_PIN                4u
#define MSC0_S_PAD13_PORT               4u
#define MSC0_S_PAD13_PIN                5u
#define MSC0_S_PAD14_PORT               4u
#define MSC0_S_PAD14_PIN                6u
#define MSC0_S_PAD15_PORT               4u
#define MSC0_S_PAD15_PIN                7u
#define MSC0_S_PAD2_PORT                3u
#define MSC0_S_PAD2_PIN                 1u
#define MSC0_S_PAD3_PORT                3u
#define MSC0_S_PAD3_PIN                 4u
#define MSC0_S_PAD4_PORT                3u
#define MSC0_S_PAD4_PIN                 5u
#define MSC0_S_PAD5_PORT                3u
#define MSC0_S_PAD5_PIN                 6u
#define MSC0_S_PAD6_PORT                3u
#define MSC0_S_PAD6_PIN                 7u
#define MSC0_S_PAD7_PORT                11u
#define MSC0_S_PAD7_PIN                 0u
#define MSC0_S_PAD8_PORT                11u
#define MSC0_S_PAD8_PIN                 1u
#define MSC0_S_PAD9_PORT                11u
#define MSC0_S_PAD9_PIN                 2u
#define MSC1_CMOD1PADD_PORT             5u
#define MSC1_CMOD1PADD_PIN              1u
#define MSC1_CMOD1PADS_PORT             5u
#define MSC1_CMOD1PADS_PIN              1u
#define MSC1_CMOD2PADD_PORT             5u
#define MSC1_CMOD2PADD_PIN              2u
#define MSC1_CMOD2PADS_PORT             5u
#define MSC1_CMOD2PADS_PIN              2u
#define MSC1_CMOD3PADD_PORT             7u
#define MSC1_CMOD3PADD_PIN              0u
#define MSC1_CMOD3PADS_PORT             7u
#define MSC1_CMOD3PADS_PIN              0u
#define MSC1_CMOD4PADD_PORT             7u
#define MSC1_CMOD4PADD_PIN              1u
#define MSC1_CMOD4PADS_PORT             7u
#define MSC1_CMOD4PADS_PIN              1u
#define MSC1_S_PAD0_PORT                5u
#define MSC1_S_PAD0_PIN                 6u
#define MSC1_S_PAD1_PORT                5u
#define MSC1_S_PAD1_PIN                 7u
#define MSC1_S_PAD10_PORT               9u
#define MSC1_S_PAD10_PIN                2u
#define MSC1_S_PAD11_PORT               9u
#define MSC1_S_PAD11_PIN                3u
#define MSC1_S_PAD12_PORT               5u
#define MSC1_S_PAD12_PIN                0u
#define MSC1_S_PAD13_PORT               5u
#define MSC1_S_PAD13_PIN                3u
#define MSC1_S_PAD14_PORT               5u
#define MSC1_S_PAD14_PIN                4u
#define MSC1_S_PAD15_PORT               5u
#define MSC1_S_PAD15_PIN                5u
#define MSC1_S_PAD2_PORT                7u
#define MSC1_S_PAD2_PIN                 6u
#define MSC1_S_PAD3_PORT                7u
#define MSC1_S_PAD3_PIN                 7u
#define MSC1_S_PAD4_PORT                0u
#define MSC1_S_PAD4_PIN                 0u
#define MSC1_S_PAD5_PORT                0u
#define MSC1_S_PAD5_PIN                 1u
#define MSC1_S_PAD6_PORT                0u
#define MSC1_S_PAD6_PIN                 2u
#define MSC1_S_PAD7_PORT                0u
#define MSC1_S_PAD7_PIN                 3u
#define MSC1_S_PAD8_PORT                9u
#define MSC1_S_PAD8_PIN                 0u
#define MSC1_S_PAD9_PORT                9u
#define MSC1_S_PAD9_PIN                 1u
#define PASS0_CTB0_OA0_OUT_10X_PORT     1u
#define PASS0_CTB0_OA0_OUT_10X_PIN      2u
#define PASS0_CTB0_OA1_OUT_10X_PORT     1u
#define PASS0_CTB0_OA1_OUT_10X_PIN      3u
#define PASS0_CTB0_PADS0_PORT           1u
#define PASS0_CTB0_PADS0_PIN            0u
#define PASS0_CTB0_PADS1_PORT           1u
#define PASS0_CTB0_PADS1_PIN            1u
#define PASS0_CTB0_PADS2_PORT           1u
#define PASS0_CTB0_PADS2_PIN            2u
#define PASS0_CTB0_PADS3_PORT           1u
#define PASS0_CTB0_PADS3_PIN            3u
#define PASS0_CTB0_PADS4_PORT           1u
#define PASS0_CTB0_PADS4_PIN            4u
#define PASS0_CTB0_PADS5_PORT           1u
#define PASS0_CTB0_PADS5_PIN            5u
#define PASS0_CTB0_PADS6_PORT           1u
#define PASS0_CTB0_PADS6_PIN            6u
#define PASS0_CTB0_PADS7_PORT           1u
#define PASS0_CTB0_PADS7_PIN            7u
#define PASS0_SAR_EXT_VREF0_PORT        1u
#define PASS0_SAR_EXT_VREF0_PIN         7u
#define PASS0_SAR_EXT_VREF1_PORT        1u
#define PASS0_SAR_EXT_VREF1_PIN         7u
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
#define SRSS_ADFT_POR_PAD_HV_PORT       0u
#define SRSS_ADFT_POR_PAD_HV_PIN        6u
#define WCO_WCO_IN_PORT                 0u
#define WCO_WCO_IN_PIN                  4u
#define WCO_WCO_OUT_PORT                0u
#define WCO_WCO_OUT_PIN                 5u

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
    P0_0_MSC1_SENSE                 =  4,       /* msc[1].sense:14 */
    P0_0_MSC1_SHIELD                =  5,       /* msc[1].shield:14 */
    P0_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_0_TCPWM_TR_IN0               =  9,       /* Digital Active - tcpwm.tr_in[0] */
    P0_0_PASS0_DSI_SAR_DATA_VALID   = 10,       /* Digital Active - pass[0].dsi_sar_data_valid */
    P0_0_SCB2_UART_CTS              = 11,       /* Digital Active - scb[2].uart_cts:0 */
    P0_0_LCD_COM0                   = 12,       /* Digital Deep Sleep - lcd.com[0] */
    P0_0_LCD_SEG0                   = 13,       /* Digital Deep Sleep - lcd.seg[0] */
    P0_0_SCB2_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[2].i2c_scl:0 */
    P0_0_SCB0_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[0].spi_select1:0 */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_1_MSC1_SENSE                 =  4,       /* msc[1].sense:15 */
    P0_1_MSC1_SHIELD                =  5,       /* msc[1].shield:15 */
    P0_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_1_TCPWM_TR_IN1               =  9,       /* Digital Active - tcpwm.tr_in[1] */
    P0_1_PASS0_TR_SAR_OUT           = 10,       /* Digital Active - pass[0].tr_sar_out */
    P0_1_SCB2_UART_RTS              = 11,       /* Digital Active - scb[2].uart_rts:0 */
    P0_1_LCD_COM1                   = 12,       /* Digital Deep Sleep - lcd.com[1] */
    P0_1_LCD_SEG1                   = 13,       /* Digital Deep Sleep - lcd.seg[1] */
    P0_1_SCB2_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[2].i2c_sda:0 */
    P0_1_SCB0_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[0].spi_select2:0 */

    /* P0.2 */
    P0_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_2_MSC1_SENSE                 =  4,       /* msc[1].sense:16 */
    P0_2_MSC1_SHIELD                =  5,       /* msc[1].shield:16 */
    P0_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_2_PASS0_DSI_SAR_SAMPLE_DONE  = 10,       /* Digital Active - pass[0].dsi_sar_sample_done */
    P0_2_CANFD_TTCAN_RX0            = 11,       /* Digital Active - canfd.ttcan_rx[0]:1 */
    P0_2_LCD_COM2                   = 12,       /* Digital Deep Sleep - lcd.com[2] */
    P0_2_LCD_SEG2                   = 13,       /* Digital Deep Sleep - lcd.seg[2] */
    P0_2_SCB0_SPI_SELECT3           = 15,       /* Digital Deep Sleep - scb[0].spi_select3:0 */

    /* P0.3 */
    P0_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_3_MSC1_SENSE                 =  4,       /* msc[1].sense:17 */
    P0_3_MSC1_SHIELD                =  5,       /* msc[1].shield:17 */
    P0_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_3_PASS0_DSI_SAR_DATA2        = 10,       /* Digital Active - pass[0].dsi_sar_data[2] */
    P0_3_CANFD_TTCAN_TX0            = 11,       /* Digital Active - canfd.ttcan_tx[0]:1 */
    P0_3_LCD_COM3                   = 12,       /* Digital Deep Sleep - lcd.com[3]:0 */
    P0_3_LCD_SEG3                   = 13,       /* Digital Deep Sleep - lcd.seg[3] */
    P0_3_SCB2_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[2].spi_select0:1 */

    /* P0.4 */
    P0_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_4_MSC1_SENSE                 =  4,       /* msc[1].sense:18 */
    P0_4_MSC1_SHIELD                =  5,       /* msc[1].shield:18 */
    P0_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_4_SCB1_UART_RX               =  9,       /* Digital Active - scb[1].uart_rx:0 */
    P0_4_PASS0_DSI_SAR_DATA0        = 10,       /* Digital Active - pass[0].dsi_sar_data[0] */
    P0_4_SCB2_UART_RX               = 11,       /* Digital Active - scb[2].uart_rx:0 */
    P0_4_LCD_COM4                   = 12,       /* Digital Deep Sleep - lcd.com[4] */
    P0_4_LCD_SEG4                   = 13,       /* Digital Deep Sleep - lcd.seg[4] */
    P0_4_SCB1_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[1].i2c_scl:0 */
    P0_4_SCB1_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[1].spi_mosi:1 */

    /* P0.5 */
    P0_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_5_MSC1_SENSE                 =  4,       /* msc[1].sense:19 */
    P0_5_MSC1_SHIELD                =  5,       /* msc[1].shield:19 */
    P0_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_5_SCB1_UART_TX               =  9,       /* Digital Active - scb[1].uart_tx:0 */
    P0_5_PASS0_DSI_SAR_DATA1        = 10,       /* Digital Active - pass[0].dsi_sar_data[1] */
    P0_5_SCB2_UART_TX               = 11,       /* Digital Active - scb[2].uart_tx:0 */
    P0_5_LCD_COM5                   = 12,       /* Digital Deep Sleep - lcd.com[5] */
    P0_5_LCD_SEG5                   = 13,       /* Digital Deep Sleep - lcd.seg[5] */
    P0_5_SCB1_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[1].i2c_sda:0 */
    P0_5_SCB1_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[1].spi_miso:1 */

    /* P0.6 */
    P0_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_6_MSC1_SENSE                 =  4,       /* msc[1].sense:20 */
    P0_6_MSC1_SHIELD                =  5,       /* msc[1].shield:20 */
    P0_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_6_SRSS_EXT_CLK               =  8,       /* Digital Active - srss.ext_clk */
    P0_6_SCB1_UART_CTS              =  9,       /* Digital Active - scb[1].uart_cts:0 */
    P0_6_EXCO_PLL_REF_IN            = 10,       /* Digital Active - exco.pll_ref_in */
    P0_6_SCB2_UART_TX               = 11,       /* Digital Active - scb[2].uart_tx:1 */
    P0_6_LCD_COM6                   = 12,       /* Digital Deep Sleep - lcd.com[6] */
    P0_6_LCD_SEG6                   = 13,       /* Digital Deep Sleep - lcd.seg[6] */
    P0_6_SCB1_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[1].spi_clk:1 */

    /* P0.7 */
    P0_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_7_MSC1_SENSE                 =  4,       /* msc[1].sense:21 */
    P0_7_MSC1_SHIELD                =  5,       /* msc[1].shield:21 */
    P0_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_7_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:3 */
    P0_7_SCB1_UART_RTS              =  9,       /* Digital Active - scb[1].uart_rts:0 */
    P0_7_LCD_COM7                   = 12,       /* Digital Deep Sleep - lcd.com[7] */
    P0_7_LCD_SEG7                   = 13,       /* Digital Deep Sleep - lcd.seg[7] */
    P0_7_SCB1_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[1].spi_select0:1 */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_0_MSC0_SENSE                 =  4,       /* msc[0].sense:0 */
    P1_0_MSC0_SHIELD                =  5,       /* msc[0].shield:0 */
    P1_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_0_TCPWM_LINE2                =  8,       /* Digital Active - tcpwm.line[2]:1 */
    P1_0_SCB0_UART_RX               =  9,       /* Digital Active - scb[0].uart_rx:1 */
    P1_0_LCD_COM8                   = 12,       /* Digital Deep Sleep - lcd.com[8] */
    P1_0_LCD_SEG8                   = 13,       /* Digital Deep Sleep - lcd.seg[8] */
    P1_0_SCB0_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */
    P1_0_SCB0_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[0].spi_mosi:1 */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_1_MSC0_SENSE                 =  4,       /* msc[0].sense:1 */
    P1_1_MSC0_SHIELD                =  5,       /* msc[0].shield:1 */
    P1_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_1_TCPWM_LINE_COMPL2          =  8,       /* Digital Active - tcpwm.line_compl[2]:1 */
    P1_1_SCB0_UART_TX               =  9,       /* Digital Active - scb[0].uart_tx:1 */
    P1_1_LCD_COM9                   = 12,       /* Digital Deep Sleep - lcd.com[9] */
    P1_1_LCD_SEG9                   = 13,       /* Digital Deep Sleep - lcd.seg[9] */
    P1_1_SCB0_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */
    P1_1_SCB0_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[0].spi_miso:1 */

    /* P1.2 */
    P1_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_2_MSC0_SENSE                 =  4,       /* msc[0].sense:2 */
    P1_2_MSC0_SHIELD                =  5,       /* msc[0].shield:2 */
    P1_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_2_TCPWM_LINE3                =  8,       /* Digital Active - tcpwm.line[3]:1 */
    P1_2_SCB0_UART_CTS              =  9,       /* Digital Active - scb[0].uart_cts:1 */
    P1_2_PASS0_DSI_SAR_DATA3        = 10,       /* Digital Active - pass[0].dsi_sar_data[3]:0 */
    P1_2_TCPWM_TR_IN2               = 11,       /* Digital Active - tcpwm.tr_in[2] */
    P1_2_LCD_COM10                  = 12,       /* Digital Deep Sleep - lcd.com[10] */
    P1_2_LCD_SEG10                  = 13,       /* Digital Deep Sleep - lcd.seg[10] */
    P1_2_SCB2_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[2].i2c_scl:2 */
    P1_2_SCB0_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[0].spi_clk:1 */

    /* P1.3 */
    P1_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_3_MSC0_SENSE                 =  4,       /* msc[0].sense:3 */
    P1_3_MSC0_SHIELD                =  5,       /* msc[0].shield:3 */
    P1_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_3_TCPWM_LINE_COMPL3          =  8,       /* Digital Active - tcpwm.line_compl[3]:1 */
    P1_3_SCB0_UART_RTS              =  9,       /* Digital Active - scb[0].uart_rts:1 */
    P1_3_PASS0_DSI_SAR_DATA4        = 10,       /* Digital Active - pass[0].dsi_sar_data[4]:0 */
    P1_3_TCPWM_TR_IN3               = 11,       /* Digital Active - tcpwm.tr_in[3] */
    P1_3_LCD_COM11                  = 12,       /* Digital Deep Sleep - lcd.com[11] */
    P1_3_LCD_SEG11                  = 13,       /* Digital Deep Sleep - lcd.seg[11] */
    P1_3_SCB2_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[2].i2c_sda:2 */
    P1_3_SCB0_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[0].spi_select0:1 */

    /* P1.4 */
    P1_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_4_MSC0_SENSE                 =  4,       /* msc[0].sense:4 */
    P1_4_MSC0_SHIELD                =  5,       /* msc[0].shield:4 */
    P1_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_4_TCPWM_LINE6                =  8,       /* Digital Active - tcpwm.line[6]:1 */
    P1_4_MSC1_OBS_DATA0             = 10,       /* Digital Active - msc[1].obs_data[0] */
    P1_4_LCD_COM12                  = 12,       /* Digital Deep Sleep - lcd.com[12] */
    P1_4_LCD_SEG12                  = 13,       /* Digital Deep Sleep - lcd.seg[12] */
    P1_4_SCB3_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[3].i2c_scl:0 */
    P1_4_SCB0_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[0].spi_select1:1 */

    /* P1.5 */
    P1_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_5_MSC0_SENSE                 =  4,       /* msc[0].sense:5 */
    P1_5_MSC0_SHIELD                =  5,       /* msc[0].shield:5 */
    P1_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_5_TCPWM_LINE_COMPL6          =  8,       /* Digital Active - tcpwm.line_compl[6]:1 */
    P1_5_MSC1_OBS_DATA1             = 10,       /* Digital Active - msc[1].obs_data[1] */
    P1_5_LCD_COM13                  = 12,       /* Digital Deep Sleep - lcd.com[13] */
    P1_5_LCD_SEG13                  = 13,       /* Digital Deep Sleep - lcd.seg[13] */
    P1_5_SCB3_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[3].i2c_sda:0 */
    P1_5_SCB0_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[0].spi_select2:1 */

    /* P1.6 */
    P1_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_6_MSC0_SENSE                 =  4,       /* msc[0].sense:6 */
    P1_6_MSC0_SHIELD                =  5,       /* msc[0].shield:6 */
    P1_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_6_TCPWM_LINE7                =  8,       /* Digital Active - tcpwm.line[7]:1 */
    P1_6_MSC1_OBS_DATA2             = 10,       /* Digital Active - msc[1].obs_data[2] */
    P1_6_LCD_COM14                  = 12,       /* Digital Deep Sleep - lcd.com[14] */
    P1_6_LCD_SEG14                  = 13,       /* Digital Deep Sleep - lcd.seg[14] */
    P1_6_SCB0_SPI_SELECT3           = 15,       /* Digital Deep Sleep - scb[0].spi_select3:1 */

    /* P1.7 */
    P1_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_7_MSC0_SENSE                 =  4,       /* msc[0].sense:7 */
    P1_7_MSC0_SHIELD                =  5,       /* msc[0].shield:7 */
    P1_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_7_TCPWM_LINE_COMPL7          =  8,       /* Digital Active - tcpwm.line_compl[7]:1 */
    P1_7_MSC1_OBS_DATA3             = 10,       /* Digital Active - msc[1].obs_data[3] */
    P1_7_LCD_COM15                  = 12,       /* Digital Deep Sleep - lcd.com[15] */
    P1_7_LCD_SEG15                  = 13,       /* Digital Deep Sleep - lcd.seg[15] */
    P1_7_SCB2_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[2].spi_clk:1 */

    /* P2.0 */
    P2_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_0_MSC0_SENSE                 =  4,       /* msc[0].sense:8 */
    P2_0_MSC0_SHIELD                =  5,       /* msc[0].shield:8 */
    P2_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_0_TCPWM_LINE4                =  8,       /* Digital Active - tcpwm.line[4]:0 */
    P2_0_TCPWM_TR_IN4               = 11,       /* Digital Active - tcpwm.tr_in[4] */
    P2_0_LCD_COM16                  = 12,       /* Digital Deep Sleep - lcd.com[16] */
    P2_0_LCD_SEG16                  = 13,       /* Digital Deep Sleep - lcd.seg[16] */
    P2_0_SCB1_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[1].i2c_scl:1 */
    P2_0_SCB1_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[1].spi_mosi:2 */

    /* P2.1 */
    P2_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_1_MSC0_SENSE                 =  4,       /* msc[0].sense:9 */
    P2_1_MSC0_SHIELD                =  5,       /* msc[0].shield:9 */
    P2_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_1_TCPWM_LINE_COMPL4          =  8,       /* Digital Active - tcpwm.line_compl[4]:0 */
    P2_1_TCPWM_TR_IN5               = 11,       /* Digital Active - tcpwm.tr_in[5] */
    P2_1_LCD_COM17                  = 12,       /* Digital Deep Sleep - lcd.com[17] */
    P2_1_LCD_SEG17                  = 13,       /* Digital Deep Sleep - lcd.seg[17] */
    P2_1_SCB1_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[1].i2c_sda:1 */
    P2_1_SCB1_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[1].spi_miso:2 */

    /* P2.2 */
    P2_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_2_MSC0_SENSE                 =  4,       /* msc[0].sense:10 */
    P2_2_MSC0_SHIELD                =  5,       /* msc[0].shield:10 */
    P2_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_2_TCPWM_LINE5                =  8,       /* Digital Active - tcpwm.line[5]:1 */
    P2_2_MSC0_OBS_DATA0             = 10,       /* Digital Active - msc[0].obs_data[0] */
    P2_2_LCD_COM18                  = 12,       /* Digital Deep Sleep - lcd.com[18] */
    P2_2_LCD_SEG18                  = 13,       /* Digital Deep Sleep - lcd.seg[18] */
    P2_2_SCB1_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[1].spi_clk:2 */

    /* P2.3 */
    P2_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_3_MSC0_SENSE                 =  4,       /* msc[0].sense:11 */
    P2_3_MSC0_SHIELD                =  5,       /* msc[0].shield:11 */
    P2_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_3_TCPWM_LINE_COMPL5          =  8,       /* Digital Active - tcpwm.line_compl[5]:1 */
    P2_3_MSC0_OBS_DATA1             = 10,       /* Digital Active - msc[0].obs_data[1] */
    P2_3_LCD_COM19                  = 12,       /* Digital Deep Sleep - lcd.com[19] */
    P2_3_LCD_SEG19                  = 13,       /* Digital Deep Sleep - lcd.seg[19] */
    P2_3_SCB1_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[1].spi_select0:2 */

    /* P2.4 */
    P2_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_4_MSC0_SENSE                 =  4,       /* msc[0].sense:12 */
    P2_4_MSC0_SHIELD                =  5,       /* msc[0].shield:12 */
    P2_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_4_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:1 */
    P2_4_SCB3_UART_RX               =  9,       /* Digital Active - scb[3].uart_rx:1 */
    P2_4_MSC0_OBS_DATA2             = 10,       /* Digital Active - msc[0].obs_data[2] */
    P2_4_AUDIOSS_TX_SCK             = 11,       /* Digital Active - audioss.tx_sck:1 */
    P2_4_AUDIOSS0_TX_SCK            = 11,       /* Digital Active - audioss[0].tx_sck:1:0 */
    P2_4_LCD_COM20                  = 12,       /* Digital Deep Sleep - lcd.com[20] */
    P2_4_LCD_SEG20                  = 13,       /* Digital Deep Sleep - lcd.seg[20] */
    P2_4_SCB1_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[1].spi_select1:1 */

    /* P2.5 */
    P2_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_5_MSC0_SENSE                 =  4,       /* msc[0].sense:13 */
    P2_5_MSC0_SHIELD                =  5,       /* msc[0].shield:13 */
    P2_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_5_TCPWM_LINE_COMPL0          =  8,       /* Digital Active - tcpwm.line_compl[0]:1 */
    P2_5_SCB3_UART_TX               =  9,       /* Digital Active - scb[3].uart_tx:1 */
    P2_5_MSC0_OBS_DATA3             = 10,       /* Digital Active - msc[0].obs_data[3] */
    P2_5_AUDIOSS_TX_WS              = 11,       /* Digital Active - audioss.tx_ws:1 */
    P2_5_AUDIOSS0_TX_WS             = 11,       /* Digital Active - audioss[0].tx_ws:1:0 */
    P2_5_LCD_COM21                  = 12,       /* Digital Deep Sleep - lcd.com[21] */
    P2_5_LCD_SEG21                  = 13,       /* Digital Deep Sleep - lcd.seg[21] */
    P2_5_SCB1_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[1].spi_select2:1 */

    /* P2.6 */
    P2_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_6_MSC0_SENSE                 =  4,       /* msc[0].sense:14 */
    P2_6_MSC0_SHIELD                =  5,       /* msc[0].shield:14 */
    P2_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_6_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1]:1 */
    P2_6_SCB3_UART_CTS              =  9,       /* Digital Active - scb[3].uart_cts:1 */
    P2_6_PASS0_DSI_SAR_DATA5        = 10,       /* Digital Active - pass[0].dsi_sar_data[5]:0 */
    P2_6_AUDIOSS_TX_SDO             = 11,       /* Digital Active - audioss.tx_sdo:1 */
    P2_6_AUDIOSS0_TX_SDO            = 11,       /* Digital Active - audioss[0].tx_sdo:1:0 */
    P2_6_LCD_COM22                  = 12,       /* Digital Deep Sleep - lcd.com[22] */
    P2_6_LCD_SEG22                  = 13,       /* Digital Deep Sleep - lcd.seg[22] */
    P2_6_SCB1_SPI_SELECT3           = 15,       /* Digital Deep Sleep - scb[1].spi_select3:1 */

    /* P2.7 */
    P2_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_7_MSC0_SENSE                 =  4,       /* msc[0].sense:15 */
    P2_7_MSC0_SHIELD                =  5,       /* msc[0].shield:15 */
    P2_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_7_TCPWM_LINE_COMPL1          =  8,       /* Digital Active - tcpwm.line_compl[1]:1 */
    P2_7_SCB3_UART_RTS              =  9,       /* Digital Active - scb[3].uart_rts:1 */
    P2_7_PASS0_DSI_SAR_DATA6        = 10,       /* Digital Active - pass[0].dsi_sar_data[6]:0 */
    P2_7_AUDIOSS_CLK_I2S_IF         = 11,       /* Digital Active - audioss.clk_i2s_if:1 */
    P2_7_AUDIOSS0_CLK_I2S_IF        = 11,       /* Digital Active - audioss[0].clk_i2s_if:1:0 */
    P2_7_LCD_COM23                  = 12,       /* Digital Deep Sleep - lcd.com[23] */
    P2_7_LCD_SEG23                  = 13,       /* Digital Deep Sleep - lcd.seg[23] */
    P2_7_LPCOMP_COMP0               = 14,       /* Digital Deep Sleep - lpcomp.comp[0]:0 */
    P2_7_SCB2_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[2].spi_mosi:1 */

    /* P3.0 */
    P3_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_0_MSC0_SENSE                 =  4,       /* msc[0].sense:30 */
    P3_0_MSC0_SHIELD                =  5,       /* msc[0].shield:30 */
    P3_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_0_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:0 */
    P3_0_SCB1_UART_RX               =  9,       /* Digital Active - scb[1].uart_rx:1 */
    P3_0_PASS0_DSI_SAR_DATA7        = 10,       /* Digital Active - pass[0].dsi_sar_data[7]:0 */
    P3_0_AUDIOSS_CLK_I2S_IF         = 11,       /* Digital Active - audioss.clk_i2s_if:0 */
    P3_0_AUDIOSS0_CLK_I2S_IF        = 11,       /* Digital Active - audioss[0].clk_i2s_if:0:0 */
    P3_0_LCD_COM24                  = 12,       /* Digital Deep Sleep - lcd.com[24] */
    P3_0_LCD_SEG24                  = 13,       /* Digital Deep Sleep - lcd.seg[24] */
    P3_0_SCB1_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[1].i2c_scl:2 */
    P3_0_SCB1_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[1].spi_mosi:0 */

    /* P3.1 */
    P3_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_1_MSC0_SENSE                 =  4,       /* msc[0].sense:31 */
    P3_1_MSC0_SHIELD                =  5,       /* msc[0].shield:31 */
    P3_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_1_TCPWM_LINE_COMPL0          =  8,       /* Digital Active - tcpwm.line_compl[0]:0 */
    P3_1_SCB1_UART_TX               =  9,       /* Digital Active - scb[1].uart_tx:1 */
    P3_1_PASS0_DSI_SAR_DATA8        = 10,       /* Digital Active - pass[0].dsi_sar_data[8]:0 */
    P3_1_LCD_COM25                  = 12,       /* Digital Deep Sleep - lcd.com[25] */
    P3_1_LCD_SEG25                  = 13,       /* Digital Deep Sleep - lcd.seg[25] */
    P3_1_SCB1_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[1].i2c_sda:2 */
    P3_1_SCB1_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[1].spi_miso:0 */

    /* P3.2 */
    P3_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_2_MSC0_SENSE                 =  4,       /* msc[0].sense:32 */
    P3_2_MSC0_SHIELD                =  5,       /* msc[0].shield:32 */
    P3_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_2_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1]:0 */
    P3_2_SCB1_UART_CTS              =  9,       /* Digital Active - scb[1].uart_cts:1 */
    P3_2_LCD_COM26                  = 12,       /* Digital Deep Sleep - lcd.com[26] */
    P3_2_LCD_SEG26                  = 13,       /* Digital Deep Sleep - lcd.seg[26] */
    P3_2_CPUSS_SWD_DATA             = 14,       /* Digital Deep Sleep - cpuss.swd_data:0 */
    P3_2_SCB1_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[1].spi_clk:0 */

    /* P3.3 */
    P3_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_3_MSC0_SENSE                 =  4,       /* msc[0].sense:33 */
    P3_3_MSC0_SHIELD                =  5,       /* msc[0].shield:33 */
    P3_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_3_TCPWM_LINE_COMPL1          =  8,       /* Digital Active - tcpwm.line_compl[1]:0 */
    P3_3_SCB1_UART_RTS              =  9,       /* Digital Active - scb[1].uart_rts:1 */
    P3_3_LCD_COM27                  = 12,       /* Digital Deep Sleep - lcd.com[27] */
    P3_3_LCD_SEG27                  = 13,       /* Digital Deep Sleep - lcd.seg[27] */
    P3_3_CPUSS_SWD_CLK              = 14,       /* Digital Deep Sleep - cpuss.swd_clk:0 */
    P3_3_SCB1_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[1].spi_select0:0 */

    /* P3.4 */
    P3_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_4_MSC0_SENSE                 =  4,       /* msc[0].sense:34 */
    P3_4_MSC0_SHIELD                =  5,       /* msc[0].shield:34 */
    P3_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_4_TCPWM_LINE2                =  8,       /* Digital Active - tcpwm.line[2]:0 */
    P3_4_TCPWM_TR_IN6               = 11,       /* Digital Active - tcpwm.tr_in[6] */
    P3_4_LCD_COM28                  = 12,       /* Digital Deep Sleep - lcd.com[28] */
    P3_4_LCD_SEG28                  = 13,       /* Digital Deep Sleep - lcd.seg[28] */
    P3_4_SCB1_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[1].spi_select1:0 */

    /* P3.5 */
    P3_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_5_MSC0_SENSE                 =  4,       /* msc[0].sense:35 */
    P3_5_MSC0_SHIELD                =  5,       /* msc[0].shield:35 */
    P3_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_5_TCPWM_LINE_COMPL2          =  8,       /* Digital Active - tcpwm.line_compl[2]:0 */
    P3_5_AUDIOSS_TX_SCK             = 11,       /* Digital Active - audioss.tx_sck:0 */
    P3_5_AUDIOSS0_TX_SCK            = 11,       /* Digital Active - audioss[0].tx_sck:0:0 */
    P3_5_LCD_COM29                  = 12,       /* Digital Deep Sleep - lcd.com[29] */
    P3_5_LCD_SEG29                  = 13,       /* Digital Deep Sleep - lcd.seg[29] */
    P3_5_SCB1_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[1].spi_select2:0 */

    /* P3.6 */
    P3_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_6_MSC0_SENSE                 =  4,       /* msc[0].sense:36 */
    P3_6_MSC0_SHIELD                =  5,       /* msc[0].shield:36 */
    P3_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_6_TCPWM_LINE3                =  8,       /* Digital Active - tcpwm.line[3]:0 */
    P3_6_PASS0_DSI_CTB_CMP0         = 10,       /* Digital Active - pass[0].dsi_ctb_cmp0 */
    P3_6_AUDIOSS_TX_SDO             = 11,       /* Digital Active - audioss.tx_sdo:0 */
    P3_6_AUDIOSS0_TX_SDO            = 11,       /* Digital Active - audioss[0].tx_sdo:0:0 */
    P3_6_LCD_COM30                  = 12,       /* Digital Deep Sleep - lcd.com[30] */
    P3_6_LCD_SEG30                  = 13,       /* Digital Deep Sleep - lcd.seg[30] */
    P3_6_SCB4_SPI_SELECT3           = 14,       /* Digital Deep Sleep - scb[4].spi_select3 */
    P3_6_SCB1_SPI_SELECT3           = 15,       /* Digital Deep Sleep - scb[1].spi_select3:0 */

    /* P3.7 */
    P3_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_7_MSC0_SENSE                 =  4,       /* msc[0].sense:37 */
    P3_7_MSC0_SHIELD                =  5,       /* msc[0].shield:37 */
    P3_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_7_TCPWM_LINE_COMPL3          =  8,       /* Digital Active - tcpwm.line_compl[3]:0 */
    P3_7_PASS0_DSI_CTB_CMP1         = 10,       /* Digital Active - pass[0].dsi_ctb_cmp1 */
    P3_7_AUDIOSS_TX_WS              = 11,       /* Digital Active - audioss.tx_ws:0 */
    P3_7_AUDIOSS0_TX_WS             = 11,       /* Digital Active - audioss[0].tx_ws:0:0 */
    P3_7_LCD_COM31                  = 12,       /* Digital Deep Sleep - lcd.com[31] */
    P3_7_LCD_SEG31                  = 13,       /* Digital Deep Sleep - lcd.seg[31] */
    P3_7_LPCOMP_COMP1               = 14,       /* Digital Deep Sleep - lpcomp.comp[1]:1 */
    P3_7_SCB2_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[2].spi_miso:1 */

    /* P4.0 */
    P4_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_0_MSC0_SENSE                 =  4,       /* msc[0].sense:44 */
    P4_0_MSC0_SHIELD                =  5,       /* msc[0].shield:44 */
    P4_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_0_SCB0_UART_RX               =  9,       /* Digital Active - scb[0].uart_rx:0 */
    P4_0_PASS0_DSI_SAR_DATA9        = 10,       /* Digital Active - pass[0].dsi_sar_data[9]:0 */
    P4_0_LCD_COM32                  = 12,       /* Digital Deep Sleep - lcd.com[32] */
    P4_0_LCD_SEG32                  = 13,       /* Digital Deep Sleep - lcd.seg[32] */
    P4_0_SCB0_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[0].i2c_scl:1 */
    P4_0_SCB0_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[0].spi_mosi:0 */

    /* P4.1 */
    P4_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_1_MSC0_SENSE                 =  4,       /* msc[0].sense:45 */
    P4_1_MSC0_SHIELD                =  5,       /* msc[0].shield:45 */
    P4_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_1_SCB0_UART_TX               =  9,       /* Digital Active - scb[0].uart_tx:0 */
    P4_1_LCD_COM33                  = 12,       /* Digital Deep Sleep - lcd.com[33] */
    P4_1_LCD_SEG33                  = 13,       /* Digital Deep Sleep - lcd.seg[33] */
    P4_1_SCB0_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[0].i2c_sda:1 */
    P4_1_SCB0_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[0].spi_miso:0 */

    /* P4.2 */
    P4_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_2_MSC0_SENSE                 =  4,       /* msc[0].sense:46 */
    P4_2_MSC0_SHIELD                =  5,       /* msc[0].shield:46 */
    P4_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_2_SCB0_UART_CTS              =  9,       /* Digital Active - scb[0].uart_cts:0 */
    P4_2_PASS0_DSI_SAR_DATA10       = 10,       /* Digital Active - pass[0].dsi_sar_data[10]:0 */
    P4_2_LCD_COM34                  = 12,       /* Digital Deep Sleep - lcd.com[34] */
    P4_2_LCD_SEG34                  = 13,       /* Digital Deep Sleep - lcd.seg[34] */
    P4_2_LPCOMP_COMP0               = 14,       /* Digital Deep Sleep - lpcomp.comp[0]:1 */
    P4_2_SCB0_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[0].spi_clk:0 */

    /* P4.3 */
    P4_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_3_MSC0_SENSE                 =  4,       /* msc[0].sense:47 */
    P4_3_MSC0_SHIELD                =  5,       /* msc[0].shield:47 */
    P4_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_3_SCB0_UART_RTS              =  9,       /* Digital Active - scb[0].uart_rts:0 */
    P4_3_PASS0_DSI_SAR_DATA11       = 10,       /* Digital Active - pass[0].dsi_sar_data[11]:0 */
    P4_3_LCD_COM35                  = 12,       /* Digital Deep Sleep - lcd.com[35] */
    P4_3_LCD_SEG35                  = 13,       /* Digital Deep Sleep - lcd.seg[35] */
    P4_3_LPCOMP_COMP1               = 14,       /* Digital Deep Sleep - lpcomp.comp[1]:2 */
    P4_3_SCB0_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[0].spi_select0:0 */

    /* P4.4 */
    P4_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_4_MSC0_SENSE                 =  4,       /* msc[0].sense:48 */
    P4_4_MSC0_SHIELD                =  5,       /* msc[0].shield:48 */
    P4_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_4_SCB4_UART_RX               =  9,       /* Digital Active - scb[4].uart_rx */
    P4_4_LCD_COM36                  = 12,       /* Digital Deep Sleep - lcd.com[36] */
    P4_4_LCD_SEG36                  = 13,       /* Digital Deep Sleep - lcd.seg[36] */
    P4_4_SCB4_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[4].spi_mosi */
    P4_4_SCB0_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[0].spi_select1:2 */

    /* P4.5 */
    P4_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_5_MSC0_SENSE                 =  4,       /* msc[0].sense:49 */
    P4_5_MSC0_SHIELD                =  5,       /* msc[0].shield:49 */
    P4_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_5_SCB4_UART_TX               =  9,       /* Digital Active - scb[4].uart_tx */
    P4_5_LCD_COM37                  = 12,       /* Digital Deep Sleep - lcd.com[37] */
    P4_5_LCD_SEG37                  = 13,       /* Digital Deep Sleep - lcd.seg[37] */
    P4_5_SCB4_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[4].spi_miso */
    P4_5_SCB0_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[0].spi_select2:2 */

    /* P4.6 */
    P4_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_6_MSC0_SENSE                 =  4,       /* msc[0].sense:50 */
    P4_6_MSC0_SHIELD                =  5,       /* msc[0].shield:50 */
    P4_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_6_TCPWM_LINE6                =  8,       /* Digital Active - tcpwm.line[6]:4 */
    P4_6_SCB4_UART_CTS              =  9,       /* Digital Active - scb[4].uart_cts */
    P4_6_LCD_COM38                  = 12,       /* Digital Deep Sleep - lcd.com[38] */
    P4_6_LCD_SEG38                  = 13,       /* Digital Deep Sleep - lcd.seg[38] */
    P4_6_SCB4_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[4].spi_clk */
    P4_6_SCB0_SPI_SELECT3           = 15,       /* Digital Deep Sleep - scb[0].spi_select3:2 */

    /* P4.7 */
    P4_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_7_MSC0_SENSE                 =  4,       /* msc[0].sense:51 */
    P4_7_MSC0_SHIELD                =  5,       /* msc[0].shield:51 */
    P4_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_7_TCPWM_LINE_COMPL6          =  8,       /* Digital Active - tcpwm.line_compl[6]:4 */
    P4_7_SCB4_UART_RTS              =  9,       /* Digital Active - scb[4].uart_rts */
    P4_7_LCD_COM39                  = 12,       /* Digital Deep Sleep - lcd.com[39] */
    P4_7_LCD_SEG39                  = 13,       /* Digital Deep Sleep - lcd.seg[39] */
    P4_7_SCB4_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[4].spi_select0 */
    P4_7_SCB3_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[3].spi_select2:1 */

    /* P5.0 */
    P5_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_0_MSC1_SENSE                 =  4,       /* msc[1].sense:30 */
    P5_0_MSC1_SHIELD                =  5,       /* msc[1].shield:30 */
    P5_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_0_TCPWM_LINE4                =  8,       /* Digital Active - tcpwm.line[4]:2 */
    P5_0_SCB2_UART_RX               = 11,       /* Digital Active - scb[2].uart_rx:1 */
    P5_0_LCD_COM40                  = 12,       /* Digital Deep Sleep - lcd.com[40] */
    P5_0_LCD_SEG40                  = 13,       /* Digital Deep Sleep - lcd.seg[40] */
    P5_0_SCB2_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[2].i2c_scl:1 */
    P5_0_SCB2_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[2].spi_mosi:0 */

    /* P5.1 */
    P5_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_1_MSC1_SENSE                 =  4,       /* msc[1].sense:31 */
    P5_1_MSC1_SHIELD                =  5,       /* msc[1].shield:31 */
    P5_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_1_TCPWM_LINE_COMPL4          =  8,       /* Digital Active - tcpwm.line_compl[4]:2 */
    P5_1_SCB2_UART_TX               = 11,       /* Digital Active - scb[2].uart_tx:2 */
    P5_1_LCD_COM41                  = 12,       /* Digital Deep Sleep - lcd.com[41] */
    P5_1_LCD_SEG41                  = 13,       /* Digital Deep Sleep - lcd.seg[41] */
    P5_1_SCB2_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[2].i2c_sda:1 */
    P5_1_SCB2_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[2].spi_miso:0 */

    /* P5.2 */
    P5_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_2_MSC1_SENSE                 =  4,       /* msc[1].sense:3 */
    P5_2_MSC1_SHIELD                =  5,       /* msc[1].shield:3 */
    P5_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_2_TCPWM_LINE5                =  8,       /* Digital Active - tcpwm.line[5]:2 */
    P5_2_SCB2_UART_CTS              = 11,       /* Digital Active - scb[2].uart_cts:1 */
    P5_2_LCD_COM42                  = 12,       /* Digital Deep Sleep - lcd.com[42] */
    P5_2_LCD_SEG42                  = 13,       /* Digital Deep Sleep - lcd.seg[42] */
    P5_2_LPCOMP_COMP0               = 14,       /* Digital Deep Sleep - lpcomp.comp[0]:2 */
    P5_2_SCB2_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[2].spi_clk:0 */

    /* P5.3 */
    P5_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_3_MSC1_SENSE                 =  4,       /* msc[1].sense:2 */
    P5_3_MSC1_SHIELD                =  5,       /* msc[1].shield:2 */
    P5_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_3_TCPWM_LINE_COMPL5          =  8,       /* Digital Active - tcpwm.line_compl[5]:2 */
    P5_3_SCB2_UART_RTS              = 11,       /* Digital Active - scb[2].uart_rts:1 */
    P5_3_LCD_COM43                  = 12,       /* Digital Deep Sleep - lcd.com[43] */
    P5_3_LCD_SEG43                  = 13,       /* Digital Deep Sleep - lcd.seg[43] */
    P5_3_LPCOMP_COMP1               = 14,       /* Digital Deep Sleep - lpcomp.comp[1]:0 */
    P5_3_SCB2_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[2].spi_select0:0 */

    /* P5.4 */
    P5_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_4_MSC1_SENSE                 =  4,       /* msc[1].sense:1 */
    P5_4_MSC1_SHIELD                =  5,       /* msc[1].shield:1 */
    P5_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_4_TCPWM_LINE6                =  8,       /* Digital Active - tcpwm.line[6]:2 */
    P5_4_LCD_COM44                  = 12,       /* Digital Deep Sleep - lcd.com[44] */
    P5_4_LCD_SEG44                  = 13,       /* Digital Deep Sleep - lcd.seg[44] */
    P5_4_SCB2_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[2].spi_select1:0 */

    /* P5.5 */
    P5_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_5_MSC1_SENSE                 =  4,       /* msc[1].sense:0 */
    P5_5_MSC1_SHIELD                =  5,       /* msc[1].shield:0 */
    P5_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_5_TCPWM_LINE_COMPL6          =  8,       /* Digital Active - tcpwm.line_compl[6]:2 */
    P5_5_LCD_COM45                  = 12,       /* Digital Deep Sleep - lcd.com[45] */
    P5_5_LCD_SEG45                  = 13,       /* Digital Deep Sleep - lcd.seg[45] */
    P5_5_SCB2_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[2].spi_select2:0 */

    /* P5.6 */
    P5_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_6_MSC1_SENSE                 =  4,       /* msc[1].sense:4 */
    P5_6_MSC1_SHIELD                =  5,       /* msc[1].shield:4 */
    P5_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_6_TCPWM_LINE7                =  8,       /* Digital Active - tcpwm.line[7]:0 */
    P5_6_LCD_COM46                  = 12,       /* Digital Deep Sleep - lcd.com[46] */
    P5_6_LCD_SEG46                  = 13,       /* Digital Deep Sleep - lcd.seg[46] */
    P5_6_SCB4_SPI_SELECT1           = 14,       /* Digital Deep Sleep - scb[4].spi_select1 */
    P5_6_SCB2_SPI_SELECT3           = 15,       /* Digital Deep Sleep - scb[2].spi_select3:0 */

    /* P5.7 */
    P5_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_7_MSC1_SENSE                 =  4,       /* msc[1].sense:5 */
    P5_7_MSC1_SHIELD                =  5,       /* msc[1].shield:5 */
    P5_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_7_TCPWM_LINE_COMPL7          =  8,       /* Digital Active - tcpwm.line_compl[7]:0 */
    P5_7_LCD_COM47                  = 12,       /* Digital Deep Sleep - lcd.com[47] */
    P5_7_LCD_SEG47                  = 13,       /* Digital Deep Sleep - lcd.seg[47] */
    P5_7_SCB4_SPI_SELECT2           = 14,       /* Digital Deep Sleep - scb[4].spi_select2 */
    P5_7_SCB3_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[3].spi_select1:1 */

    /* P6.0 */
    P6_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P6_0_MSC0_SENSE                 =  4,       /* msc[0].sense:22 */
    P6_0_MSC0_SHIELD                =  5,       /* msc[0].shield:22 */
    P6_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P6_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P6_0_TCPWM_LINE4                =  8,       /* Digital Active - tcpwm.line[4]:1 */
    P6_0_SCB3_UART_RX               =  9,       /* Digital Active - scb[3].uart_rx:0 */
    P6_0_MSC0_EXT_FRM_START         = 10,       /* Digital Active - msc[0].ext_frm_start:1 */
    P6_0_LCD_COM48                  = 12,       /* Digital Deep Sleep - lcd.com[48] */
    P6_0_LCD_SEG48                  = 13,       /* Digital Deep Sleep - lcd.seg[48] */
    P6_0_SCB3_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[3].i2c_scl:1 */
    P6_0_SCB3_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[3].spi_mosi:0 */

    /* P6.1 */
    P6_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P6_1_MSC0_SENSE                 =  4,       /* msc[0].sense:23 */
    P6_1_MSC0_SHIELD                =  5,       /* msc[0].shield:23 */
    P6_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P6_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P6_1_TCPWM_LINE_COMPL4          =  8,       /* Digital Active - tcpwm.line_compl[4]:1 */
    P6_1_SCB3_UART_TX               =  9,       /* Digital Active - scb[3].uart_tx:0 */
    P6_1_MSC0_EXT_SYNC_CLK          = 10,       /* Digital Active - msc[0].ext_sync_clk:1 */
    P6_1_CANFD_TTCAN_RX0            = 11,       /* Digital Active - canfd.ttcan_rx[0]:0 */
    P6_1_LCD_COM49                  = 12,       /* Digital Deep Sleep - lcd.com[49] */
    P6_1_LCD_SEG49                  = 13,       /* Digital Deep Sleep - lcd.seg[49] */
    P6_1_SCB3_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[3].i2c_sda:1 */
    P6_1_SCB3_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[3].spi_miso:0 */

    /* P6.2 */
    P6_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P6_2_MSC0_SENSE                 =  4,       /* msc[0].sense:24 */
    P6_2_MSC0_SHIELD                =  5,       /* msc[0].shield:24 */
    P6_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P6_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P6_2_TCPWM_LINE5                =  8,       /* Digital Active - tcpwm.line[5]:0 */
    P6_2_SCB3_UART_CTS              =  9,       /* Digital Active - scb[3].uart_cts:0 */
    P6_2_MSC0_EXT_SYNC              = 10,       /* Digital Active - msc[0].ext_sync:1 */
    P6_2_CANFD_TTCAN_TX0            = 11,       /* Digital Active - canfd.ttcan_tx[0]:0 */
    P6_2_LCD_COM50                  = 12,       /* Digital Deep Sleep - lcd.com[50] */
    P6_2_LCD_SEG50                  = 13,       /* Digital Deep Sleep - lcd.seg[50] */
    P6_2_SCB3_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[3].spi_clk:0 */

    /* P6.3 */
    P6_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P6_3_MSC0_SENSE                 =  4,       /* msc[0].sense:25 */
    P6_3_MSC0_SHIELD                =  5,       /* msc[0].shield:25 */
    P6_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P6_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P6_3_TCPWM_LINE_COMPL5          =  8,       /* Digital Active - tcpwm.line_compl[5]:0 */
    P6_3_SCB3_UART_RTS              =  9,       /* Digital Active - scb[3].uart_rts:0 */
    P6_3_LCD_COM51                  = 12,       /* Digital Deep Sleep - lcd.com[51] */
    P6_3_LCD_SEG51                  = 13,       /* Digital Deep Sleep - lcd.seg[51] */
    P6_3_SCB3_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[3].spi_select0:0 */

    /* P6.4 */
    P6_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P6_4_MSC0_SENSE                 =  4,       /* msc[0].sense:26 */
    P6_4_MSC0_SHIELD                =  5,       /* msc[0].shield:26 */
    P6_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P6_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P6_4_TCPWM_LINE6                =  8,       /* Digital Active - tcpwm.line[6]:0 */
    P6_4_LCD_COM52                  = 12,       /* Digital Deep Sleep - lcd.com[52] */
    P6_4_LCD_SEG52                  = 13,       /* Digital Deep Sleep - lcd.seg[52] */
    P6_4_SCB4_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[4].i2c_scl */
    P6_4_SCB3_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[3].spi_select1:0 */

    /* P6.5 */
    P6_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P6_5_MSC0_SENSE                 =  4,       /* msc[0].sense:29 */
    P6_5_MSC0_SHIELD                =  5,       /* msc[0].shield:29 */
    P6_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P6_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P6_5_TCPWM_LINE_COMPL6          =  8,       /* Digital Active - tcpwm.line_compl[6]:0 */
    P6_5_LCD_COM53                  = 12,       /* Digital Deep Sleep - lcd.com[53] */
    P6_5_LCD_SEG53                  = 13,       /* Digital Deep Sleep - lcd.seg[53] */
    P6_5_SCB4_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[4].i2c_sda */
    P6_5_SCB3_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[3].spi_select2:0 */

    /* P7.0 */
    P7_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_0_MSC1_SENSE                 =  4,       /* msc[1].sense:6 */
    P7_0_MSC1_SHIELD                =  5,       /* msc[1].shield:6 */
    P7_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_0_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:2 */
    P7_0_SCB3_UART_RX               =  9,       /* Digital Active - scb[3].uart_rx:2 */
    P7_0_LCD_COM54                  = 12,       /* Digital Deep Sleep - lcd.com[54]:0 */
    P7_0_LCD_SEG54                  = 13,       /* Digital Deep Sleep - lcd.seg[54] */
    P7_0_SCB3_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[3].i2c_scl:2 */
    P7_0_SCB3_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[3].spi_mosi:1 */

    /* P7.1 */
    P7_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_1_MSC1_SENSE                 =  4,       /* msc[1].sense:7 */
    P7_1_MSC1_SHIELD                =  5,       /* msc[1].shield:7 */
    P7_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_1_TCPWM_LINE_COMPL0          =  8,       /* Digital Active - tcpwm.line_compl[0]:2 */
    P7_1_SCB3_UART_TX               =  9,       /* Digital Active - scb[3].uart_tx:2 */
    P7_1_LCD_COM55                  = 12,       /* Digital Deep Sleep - lcd.com[55]:0 */
    P7_1_LCD_SEG55                  = 13,       /* Digital Deep Sleep - lcd.seg[55] */
    P7_1_SCB3_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[3].i2c_sda:2 */
    P7_1_SCB3_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[3].spi_miso:1 */

    /* P7.2 */
    P7_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_2_MSC1_SENSE                 =  4,       /* msc[1].sense:8 */
    P7_2_MSC1_SHIELD                =  5,       /* msc[1].shield:8 */
    P7_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_2_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1]:2 */
    P7_2_SCB3_UART_CTS              =  9,       /* Digital Active - scb[3].uart_cts:2 */
    P7_2_LCD_COM56                  = 12,       /* Digital Deep Sleep - lcd.com[56]:0 */
    P7_2_LCD_SEG56                  = 13,       /* Digital Deep Sleep - lcd.seg[56] */
    P7_2_SCB3_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[3].spi_clk:1 */

    /* P7.3 */
    P7_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_3_MSC1_SENSE                 =  4,       /* msc[1].sense:9 */
    P7_3_MSC1_SHIELD                =  5,       /* msc[1].shield:9 */
    P7_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_3_TCPWM_LINE_COMPL1          =  8,       /* Digital Active - tcpwm.line_compl[1]:2 */
    P7_3_SCB3_UART_RTS              =  9,       /* Digital Active - scb[3].uart_rts:2 */
    P7_3_AUDIOSS_CLK_I2S_IF         = 11,       /* Digital Active - audioss.clk_i2s_if:2 */
    P7_3_AUDIOSS0_CLK_I2S_IF        = 11,       /* Digital Active - audioss[0].clk_i2s_if:2:0 */
    P7_3_LCD_COM57                  = 12,       /* Digital Deep Sleep - lcd.com[57]:0 */
    P7_3_LCD_SEG57                  = 13,       /* Digital Deep Sleep - lcd.seg[57] */
    P7_3_SCB3_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[3].spi_select2:2 */

    /* P7.4 */
    P7_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_4_MSC1_SENSE                 =  4,       /* msc[1].sense:10 */
    P7_4_MSC1_SHIELD                =  5,       /* msc[1].shield:10 */
    P7_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_4_TCPWM_LINE2                =  8,       /* Digital Active - tcpwm.line[2]:2 */
    P7_4_AUDIOSS_TX_SCK             = 11,       /* Digital Active - audioss.tx_sck:2 */
    P7_4_AUDIOSS0_TX_SCK            = 11,       /* Digital Active - audioss[0].tx_sck:2:0 */
    P7_4_LCD_COM58                  = 12,       /* Digital Deep Sleep - lcd.com[58]:0 */
    P7_4_LCD_SEG58                  = 13,       /* Digital Deep Sleep - lcd.seg[58] */
    P7_4_SCB3_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[3].spi_select0:1 */

    /* P7.5 */
    P7_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_5_MSC1_SENSE                 =  4,       /* msc[1].sense:11 */
    P7_5_MSC1_SHIELD                =  5,       /* msc[1].shield:11 */
    P7_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_5_TCPWM_LINE_COMPL2          =  8,       /* Digital Active - tcpwm.line_compl[2]:2 */
    P7_5_AUDIOSS_TX_SDO             = 11,       /* Digital Active - audioss.tx_sdo:2 */
    P7_5_AUDIOSS0_TX_SDO            = 11,       /* Digital Active - audioss[0].tx_sdo:2:0 */
    P7_5_LCD_COM59                  = 12,       /* Digital Deep Sleep - lcd.com[59]:0 */
    P7_5_LCD_SEG59                  = 13,       /* Digital Deep Sleep - lcd.seg[59]:0 */
    P7_5_SCB3_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[3].spi_select1:2 */

    /* P7.6 */
    P7_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_6_MSC1_SENSE                 =  4,       /* msc[1].sense:12 */
    P7_6_MSC1_SHIELD                =  5,       /* msc[1].shield:12 */
    P7_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_6_TCPWM_LINE3                =  8,       /* Digital Active - tcpwm.line[3]:2 */
    P7_6_AUDIOSS_TX_WS              = 11,       /* Digital Active - audioss.tx_ws:2 */
    P7_6_AUDIOSS0_TX_WS             = 11,       /* Digital Active - audioss[0].tx_ws:2:0 */
    P7_6_LCD_COM60                  = 12,       /* Digital Deep Sleep - lcd.com[60]:0 */
    P7_6_LCD_SEG60                  = 13,       /* Digital Deep Sleep - lcd.seg[60]:0 */
    P7_6_SCB3_SPI_SELECT3           = 15,       /* Digital Deep Sleep - scb[3].spi_select3:1 */

    /* P7.7 */
    P7_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_7_MSC1_SENSE                 =  4,       /* msc[1].sense:13 */
    P7_7_MSC1_SHIELD                =  5,       /* msc[1].shield:13 */
    P7_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P7_7_TCPWM_LINE_COMPL3          =  8,       /* Digital Active - tcpwm.line_compl[3]:2 */
    P7_7_LCD_COM61                  = 12,       /* Digital Deep Sleep - lcd.com[61]:0 */
    P7_7_LCD_SEG61                  = 13,       /* Digital Deep Sleep - lcd.seg[61]:0 */

    /* P8.0 */
    P8_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P8_0_MSC1_SENSE                 =  4,       /* msc[1].sense:22 */
    P8_0_MSC1_SHIELD                =  5,       /* msc[1].shield:22 */
    P8_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P8_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P8_0_TCPWM_LINE4                =  8,       /* Digital Active - tcpwm.line[4]:4 */
    P8_0_SCB4_UART_RX               =  9,       /* Digital Active - scb[4].uart_rx:2 */
    P8_0_MSC1_EXT_SYNC              = 10,       /* Digital Active - msc[1].ext_sync:0 */
    P8_0_AUDIOSS_CLK_I2S_IF         = 11,       /* Digital Active - audioss.clk_i2s_if:3 */
    P8_0_AUDIOSS0_CLK_I2S_IF        = 11,       /* Digital Active - audioss[0].clk_i2s_if:3:0 */
    P8_0_LCD_COM0                   = 12,       /* Digital Deep Sleep - lcd.com[0]:1 */
    P8_0_LCD_SEG0                   = 13,       /* Digital Deep Sleep - lcd.seg[0]:1 */
    P8_0_SCB4_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[4].i2c_scl:1 */
    P8_0_SCB3_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[3].spi_mosi:2 */

    /* P8.1 */
    P8_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P8_1_MSC1_SENSE                 =  4,       /* msc[1].sense:23 */
    P8_1_MSC1_SHIELD                =  5,       /* msc[1].shield:23 */
    P8_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P8_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P8_1_TCPWM_LINE_COMPL4          =  8,       /* Digital Active - tcpwm.line_compl[4]:4 */
    P8_1_SCB4_UART_TX               =  9,       /* Digital Active - scb[4].uart_tx:2 */
    P8_1_MSC1_EXT_SYNC_CLK          = 10,       /* Digital Active - msc[1].ext_sync_clk:0 */
    P8_1_AUDIOSS_TX_SCK             = 11,       /* Digital Active - audioss.tx_sck:3 */
    P8_1_AUDIOSS0_TX_SCK            = 11,       /* Digital Active - audioss[0].tx_sck:3:0 */
    P8_1_LCD_COM1                   = 12,       /* Digital Deep Sleep - lcd.com[1]:1 */
    P8_1_LCD_SEG1                   = 13,       /* Digital Deep Sleep - lcd.seg[1]:1 */
    P8_1_SCB4_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[4].i2c_sda:1 */
    P8_1_SCB3_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[3].spi_miso:2 */

    /* P8.2 */
    P8_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P8_2_MSC1_SENSE                 =  4,       /* msc[1].sense:24 */
    P8_2_MSC1_SHIELD                =  5,       /* msc[1].shield:24 */
    P8_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P8_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P8_2_TCPWM_LINE5                =  8,       /* Digital Active - tcpwm.line[5]:4 */
    P8_2_SCB4_UART_CTS              =  9,       /* Digital Active - scb[4].uart_cts:2 */
    P8_2_MSC1_EXT_FRM_START         = 10,       /* Digital Active - msc[1].ext_frm_start:0 */
    P8_2_AUDIOSS_TX_WS              = 11,       /* Digital Active - audioss.tx_ws:3 */
    P8_2_AUDIOSS0_TX_WS             = 11,       /* Digital Active - audioss[0].tx_ws:3:0 */
    P8_2_LCD_COM2                   = 12,       /* Digital Deep Sleep - lcd.com[2]:1 */
    P8_2_LCD_SEG2                   = 13,       /* Digital Deep Sleep - lcd.seg[2]:1 */
    P8_2_LPCOMP_COMP0               = 14,       /* Digital Deep Sleep - lpcomp.comp[0]:3 */
    P8_2_SCB3_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[3].spi_clk:2 */

    /* P8.3 */
    P8_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P8_3_MSC1_SENSE                 =  4,       /* msc[1].sense:25 */
    P8_3_MSC1_SHIELD                =  5,       /* msc[1].shield:25 */
    P8_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P8_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P8_3_TCPWM_LINE_COMPL5          =  8,       /* Digital Active - tcpwm.line_compl[5]:4 */
    P8_3_SCB4_UART_RTS              =  9,       /* Digital Active - scb[4].uart_rts:2 */
    P8_3_AUDIOSS_TX_SDO             = 11,       /* Digital Active - audioss.tx_sdo:3 */
    P8_3_AUDIOSS0_TX_SDO            = 11,       /* Digital Active - audioss[0].tx_sdo:3:0 */
    P8_3_LCD_COM3                   = 12,       /* Digital Deep Sleep - lcd.com[3]:1 */
    P8_3_LCD_SEG3                   = 13,       /* Digital Deep Sleep - lcd.seg[3]:1 */
    P8_3_LPCOMP_COMP1               = 14,       /* Digital Deep Sleep - lpcomp.comp[1]:3 */
    P8_3_SCB3_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[3].spi_select0:2 */

    /* P9.0 */
    P9_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P9_0_MSC1_SENSE                 =  4,       /* msc[1].sense:26 */
    P9_0_MSC1_SHIELD                =  5,       /* msc[1].shield:26 */
    P9_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P9_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P9_0_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:4 */
    P9_0_SCB0_UART_RX               =  9,       /* Digital Active - scb[0].uart_rx:2 */
    P9_0_CANFD_TTCAN_RX0            = 11,       /* Digital Active - canfd.ttcan_rx[0]:2 */
    P9_0_LCD_COM8                   = 12,       /* Digital Deep Sleep - lcd.com[8]:1 */
    P9_0_LCD_SEG8                   = 13,       /* Digital Deep Sleep - lcd.seg[8]:1 */
    P9_0_SCB0_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[0].i2c_scl:2 */
    P9_0_SCB0_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[0].spi_mosi:2 */

    /* P9.1 */
    P9_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P9_1_MSC1_SENSE                 =  4,       /* msc[1].sense:27 */
    P9_1_MSC1_SHIELD                =  5,       /* msc[1].shield:27 */
    P9_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P9_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P9_1_TCPWM_LINE_COMPL0          =  8,       /* Digital Active - tcpwm.line_compl[0]:3 */
    P9_1_SCB0_UART_TX               =  9,       /* Digital Active - scb[0].uart_tx:2 */
    P9_1_CANFD_TTCAN_TX0            = 11,       /* Digital Active - canfd.ttcan_tx[0]:2 */
    P9_1_LCD_COM9                   = 12,       /* Digital Deep Sleep - lcd.com[9]:1 */
    P9_1_LCD_SEG9                   = 13,       /* Digital Deep Sleep - lcd.seg[9]:1 */
    P9_1_SCB0_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[0].i2c_sda:2 */
    P9_1_SCB0_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[0].spi_miso:2 */

    /* P9.2 */
    P9_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P9_2_MSC1_SENSE                 =  4,       /* msc[1].sense:28 */
    P9_2_MSC1_SHIELD                =  5,       /* msc[1].shield:28 */
    P9_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P9_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P9_2_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1]:3 */
    P9_2_SCB0_UART_CTS              =  9,       /* Digital Active - scb[0].uart_cts:2 */
    P9_2_LCD_COM10                  = 12,       /* Digital Deep Sleep - lcd.com[10]:1 */
    P9_2_LCD_SEG10                  = 13,       /* Digital Deep Sleep - lcd.seg[10]:1 */
    P9_2_SCB0_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[0].spi_clk:2 */

    /* P9.3 */
    P9_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P9_3_MSC1_SENSE                 =  4,       /* msc[1].sense:29 */
    P9_3_MSC1_SHIELD                =  5,       /* msc[1].shield:29 */
    P9_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P9_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P9_3_TCPWM_LINE_COMPL1          =  8,       /* Digital Active - tcpwm.line_compl[1]:3 */
    P9_3_SCB0_UART_RTS              =  9,       /* Digital Active - scb[0].uart_rts:2 */
    P9_3_LCD_COM11                  = 12,       /* Digital Deep Sleep - lcd.com[11]:1 */
    P9_3_LCD_SEG11                  = 13,       /* Digital Deep Sleep - lcd.seg[11]:1 */
    P9_3_SCB0_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[0].spi_select0:2 */

    /* P10.0 */
    P10_0_GPIO                      =  0,       /* SW controlled GPIO. */
    P10_0_MSC0_SENSE                =  4,       /* msc[0].sense:16 */
    P10_0_MSC0_SHIELD               =  5,       /* msc[0].shield:16 */
    P10_0_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P10_0_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P10_0_TCPWM_LINE7               =  8,       /* Digital Active - tcpwm.line[7]:3 */
    P10_0_MSC1_EXT_SYNC             = 10,       /* Digital Active - msc[1].ext_sync:1 */
    P10_0_SCB2_UART_RX              = 11,       /* Digital Active - scb[2].uart_rx:2 */
    P10_0_LCD_COM16                 = 12,       /* Digital Deep Sleep - lcd.com[16]:1 */
    P10_0_LCD_SEG16                 = 13,       /* Digital Deep Sleep - lcd.seg[16]:1 */
    P10_0_SCB2_I2C_SCL              = 14,       /* Digital Deep Sleep - scb[2].i2c_scl:3 */
    P10_0_SCB2_SPI_MOSI             = 15,       /* Digital Deep Sleep - scb[2].spi_mosi:2 */

    /* P10.1 */
    P10_1_GPIO                      =  0,       /* SW controlled GPIO. */
    P10_1_MSC0_SENSE                =  4,       /* msc[0].sense:17 */
    P10_1_MSC0_SHIELD               =  5,       /* msc[0].shield:17 */
    P10_1_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P10_1_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P10_1_TCPWM_LINE_COMPL7         =  8,       /* Digital Active - tcpwm.line_compl[7]:3 */
    P10_1_MSC1_EXT_SYNC_CLK         = 10,       /* Digital Active - msc[1].ext_sync_clk:1 */
    P10_1_SCB2_UART_TX              = 11,       /* Digital Active - scb[2].uart_tx:3 */
    P10_1_LCD_COM17                 = 12,       /* Digital Deep Sleep - lcd.com[17]:1 */
    P10_1_LCD_SEG17                 = 13,       /* Digital Deep Sleep - lcd.seg[17]:1 */
    P10_1_SCB2_I2C_SDA              = 14,       /* Digital Deep Sleep - scb[2].i2c_sda:3 */
    P10_1_SCB2_SPI_MISO             = 15,       /* Digital Deep Sleep - scb[2].spi_miso:2 */

    /* P10.2 */
    P10_2_GPIO                      =  0,       /* SW controlled GPIO. */
    P10_2_MSC0_SENSE                =  4,       /* msc[0].sense:18 */
    P10_2_MSC0_SHIELD               =  5,       /* msc[0].shield:18 */
    P10_2_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P10_2_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P10_2_TCPWM_LINE2               =  8,       /* Digital Active - tcpwm.line[2]:3 */
    P10_2_MSC1_EXT_FRM_START        = 10,       /* Digital Active - msc[1].ext_frm_start:1 */
    P10_2_SCB2_UART_CTS             = 11,       /* Digital Active - scb[2].uart_cts:2 */
    P10_2_LCD_COM18                 = 12,       /* Digital Deep Sleep - lcd.com[18]:1 */
    P10_2_LCD_SEG18                 = 13,       /* Digital Deep Sleep - lcd.seg[18]:1 */
    P10_2_SCB2_SPI_CLK              = 15,       /* Digital Deep Sleep - scb[2].spi_clk:2 */

    /* P10.3 */
    P10_3_GPIO                      =  0,       /* SW controlled GPIO. */
    P10_3_MSC0_SENSE                =  4,       /* msc[0].sense:19 */
    P10_3_MSC0_SHIELD               =  5,       /* msc[0].shield:19 */
    P10_3_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P10_3_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P10_3_TCPWM_LINE_COMPL2         =  8,       /* Digital Active - tcpwm.line_compl[2]:3 */
    P10_3_MSC0_EXT_SYNC             = 10,       /* Digital Active - msc[0].ext_sync:0 */
    P10_3_SCB2_UART_RTS             = 11,       /* Digital Active - scb[2].uart_rts:2 */
    P10_3_LCD_COM19                 = 12,       /* Digital Deep Sleep - lcd.com[19]:1 */
    P10_3_LCD_SEG19                 = 13,       /* Digital Deep Sleep - lcd.seg[19]:1 */
    P10_3_SCB2_SPI_SELECT0          = 15,       /* Digital Deep Sleep - scb[2].spi_select0:2 */

    /* P10.4 */
    P10_4_GPIO                      =  0,       /* SW controlled GPIO. */
    P10_4_MSC0_SENSE                =  4,       /* msc[0].sense:20 */
    P10_4_MSC0_SHIELD               =  5,       /* msc[0].shield:20 */
    P10_4_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P10_4_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P10_4_TCPWM_LINE3               =  8,       /* Digital Active - tcpwm.line[3]:3 */
    P10_4_MSC0_EXT_SYNC_CLK         = 10,       /* Digital Active - msc[0].ext_sync_clk:0 */
    P10_4_CANFD_TTCAN_RX0           = 11,       /* Digital Active - canfd.ttcan_rx[0]:3 */
    P10_4_LCD_COM20                 = 12,       /* Digital Deep Sleep - lcd.com[20]:1 */
    P10_4_LCD_SEG20                 = 13,       /* Digital Deep Sleep - lcd.seg[20]:1 */
    P10_4_SCB2_SPI_SELECT1          = 15,       /* Digital Deep Sleep - scb[2].spi_select1:1 */

    /* P10.5 */
    P10_5_GPIO                      =  0,       /* SW controlled GPIO. */
    P10_5_MSC0_SENSE                =  4,       /* msc[0].sense:21 */
    P10_5_MSC0_SHIELD               =  5,       /* msc[0].shield:21 */
    P10_5_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P10_5_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P10_5_TCPWM_LINE_COMPL3         =  8,       /* Digital Active - tcpwm.line_compl[3]:3 */
    P10_5_MSC0_EXT_FRM_START        = 10,       /* Digital Active - msc[0].ext_frm_start:0 */
    P10_5_CANFD_TTCAN_TX0           = 11,       /* Digital Active - canfd.ttcan_tx[0]:3 */
    P10_5_LCD_COM21                 = 12,       /* Digital Deep Sleep - lcd.com[21]:1 */
    P10_5_LCD_SEG21                 = 13,       /* Digital Deep Sleep - lcd.seg[21]:1 */
    P10_5_SCB2_SPI_SELECT2          = 15,       /* Digital Deep Sleep - scb[2].spi_select2:1 */

    /* P11.0 */
    P11_0_GPIO                      =  0,       /* SW controlled GPIO. */
    P11_0_MSC0_SENSE                =  4,       /* msc[0].sense:38 */
    P11_0_MSC0_SHIELD               =  5,       /* msc[0].shield:38 */
    P11_0_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P11_0_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P11_0_TCPWM_LINE4               =  8,       /* Digital Active - tcpwm.line[4]:3 */
    P11_0_SCB4_UART_RX              =  9,       /* Digital Active - scb[4].uart_rx:1 */
    P11_0_LCD_COM24                 = 12,       /* Digital Deep Sleep - lcd.com[24]:1 */
    P11_0_LCD_SEG24                 = 13,       /* Digital Deep Sleep - lcd.seg[24]:1 */
    P11_0_SCB4_SPI_MOSI             = 14,       /* Digital Deep Sleep - scb[4].spi_mosi:1 */
    P11_0_SCB1_SPI_MOSI             = 15,       /* Digital Deep Sleep - scb[1].spi_mosi:3 */

    /* P11.1 */
    P11_1_GPIO                      =  0,       /* SW controlled GPIO. */
    P11_1_MSC0_SENSE                =  4,       /* msc[0].sense:39 */
    P11_1_MSC0_SHIELD               =  5,       /* msc[0].shield:39 */
    P11_1_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P11_1_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P11_1_TCPWM_LINE_COMPL4         =  8,       /* Digital Active - tcpwm.line_compl[4]:3 */
    P11_1_SCB4_UART_TX              =  9,       /* Digital Active - scb[4].uart_tx:1 */
    P11_1_LCD_COM25                 = 12,       /* Digital Deep Sleep - lcd.com[25]:1 */
    P11_1_LCD_SEG25                 = 13,       /* Digital Deep Sleep - lcd.seg[25]:1 */
    P11_1_SCB4_SPI_MISO             = 14,       /* Digital Deep Sleep - scb[4].spi_miso:1 */
    P11_1_SCB1_SPI_MISO             = 15,       /* Digital Deep Sleep - scb[1].spi_miso:3 */

    /* P11.2 */
    P11_2_GPIO                      =  0,       /* SW controlled GPIO. */
    P11_2_MSC0_SENSE                =  4,       /* msc[0].sense:40 */
    P11_2_MSC0_SHIELD               =  5,       /* msc[0].shield:40 */
    P11_2_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P11_2_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P11_2_TCPWM_LINE5               =  8,       /* Digital Active - tcpwm.line[5]:3 */
    P11_2_SCB4_UART_CTS             =  9,       /* Digital Active - scb[4].uart_cts:1 */
    P11_2_LCD_COM26                 = 12,       /* Digital Deep Sleep - lcd.com[26]:1 */
    P11_2_LCD_SEG26                 = 13,       /* Digital Deep Sleep - lcd.seg[26]:1 */
    P11_2_SCB4_SPI_CLK              = 14,       /* Digital Deep Sleep - scb[4].spi_clk:1 */
    P11_2_SCB1_SPI_CLK              = 15,       /* Digital Deep Sleep - scb[1].spi_clk:3 */

    /* P11.3 */
    P11_3_GPIO                      =  0,       /* SW controlled GPIO. */
    P11_3_MSC0_SENSE                =  4,       /* msc[0].sense:41 */
    P11_3_MSC0_SHIELD               =  5,       /* msc[0].shield:41 */
    P11_3_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P11_3_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P11_3_TCPWM_LINE_COMPL5         =  8,       /* Digital Active - tcpwm.line_compl[5]:3 */
    P11_3_SCB4_UART_RTS             =  9,       /* Digital Active - scb[4].uart_rts:1 */
    P11_3_LCD_COM27                 = 12,       /* Digital Deep Sleep - lcd.com[27]:1 */
    P11_3_LCD_SEG27                 = 13,       /* Digital Deep Sleep - lcd.seg[27]:1 */
    P11_3_SCB4_SPI_SELECT0          = 14,       /* Digital Deep Sleep - scb[4].spi_select0:1 */
    P11_3_SCB1_SPI_SELECT0          = 15,       /* Digital Deep Sleep - scb[1].spi_select0:3 */

    /* P11.4 */
    P11_4_GPIO                      =  0,       /* SW controlled GPIO. */
    P11_4_MSC0_SENSE                =  4,       /* msc[0].sense:42 */
    P11_4_MSC0_SHIELD               =  5,       /* msc[0].shield:42 */
    P11_4_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P11_4_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P11_4_TCPWM_LINE6               =  8,       /* Digital Active - tcpwm.line[6]:3 */
    P11_4_LCD_COM28                 = 12,       /* Digital Deep Sleep - lcd.com[28]:1 */
    P11_4_LCD_SEG28                 = 13,       /* Digital Deep Sleep - lcd.seg[28]:1 */
    P11_4_SCB4_SPI_SELECT1          = 14,       /* Digital Deep Sleep - scb[4].spi_select1:1 */
    P11_4_SCB1_SPI_SELECT1          = 15,       /* Digital Deep Sleep - scb[1].spi_select1:2 */

    /* P11.5 */
    P11_5_GPIO                      =  0,       /* SW controlled GPIO. */
    P11_5_MSC0_SENSE                =  4,       /* msc[0].sense:43 */
    P11_5_MSC0_SHIELD               =  5,       /* msc[0].shield:43 */
    P11_5_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P11_5_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P11_5_TCPWM_LINE_COMPL6         =  8,       /* Digital Active - tcpwm.line_compl[6]:3 */
    P11_5_LCD_COM29                 = 12,       /* Digital Deep Sleep - lcd.com[29]:1 */
    P11_5_LCD_SEG29                 = 13,       /* Digital Deep Sleep - lcd.seg[29]:1 */
    P11_5_SCB4_SPI_SELECT2          = 14,       /* Digital Deep Sleep - scb[4].spi_select2:1 */
    P11_5_SCB1_SPI_SELECT2          = 15,       /* Digital Deep Sleep - scb[1].spi_select2:2 */

    /* P12.0 */
    P12_0_GPIO                      =  0,       /* SW controlled GPIO. */
    P12_0_MSC0_SENSE                =  4,       /* msc[0].sense:27 */
    P12_0_MSC0_SHIELD               =  5,       /* msc[0].shield:27 */
    P12_0_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P12_0_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P12_0_TCPWM_LINE7               =  8,       /* Digital Active - tcpwm.line[7]:2 */
    P12_0_LCD_COM62                 = 12,       /* Digital Deep Sleep - lcd.com[62]:0 */
    P12_0_LCD_SEG62                 = 13,       /* Digital Deep Sleep - lcd.seg[62]:0 */
    P12_0_SCB1_I2C_SCL              = 14,       /* Digital Deep Sleep - scb[1].i2c_scl:3 */
    P12_0_SCB3_SPI_SELECT3          = 15,       /* Digital Deep Sleep - scb[3].spi_select3:0 */

    /* P12.1 */
    P12_1_GPIO                      =  0,       /* SW controlled GPIO. */
    P12_1_MSC0_SENSE                =  4,       /* msc[0].sense:28 */
    P12_1_MSC0_SHIELD               =  5,       /* msc[0].shield:28 */
    P12_1_AMUXA                     =  6,       /* AMUXBUS A connection. */
    P12_1_AMUXB                     =  7,       /* AMUXBUS B connection. */
    P12_1_TCPWM_LINE_COMPL7         =  8,       /* Digital Active - tcpwm.line_compl[7]:2 */
    P12_1_LCD_COM63                 = 12,       /* Digital Deep Sleep - lcd.com[63]:0 */
    P12_1_LCD_SEG63                 = 13,       /* Digital Deep Sleep - lcd.seg[63]:0 */
    P12_1_SCB1_I2C_SDA              = 14        /* Digital Deep Sleep - scb[1].i2c_sda:3 */
} en_hsiom_sel_t;

#endif /* _GPIO_PSOC4100SMAX_100_TQFP_H_ */


/* [] END OF FILE */
