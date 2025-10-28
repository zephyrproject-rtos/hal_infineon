/***************************************************************************//**
* \file gpio_psoc4100tp_48_qfn.h
*
* \brief
* PSOC4100Tp device GPIO header for 48-QFN package
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

#ifndef _GPIO_PSOC4100TP_48_QFN_H_
#define _GPIO_PSOC4100TP_48_QFN_H_

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
#define CY_GPIO_PIN_COUNT               48u

/* AMUXBUS Segments */
enum
{
    AMUXBUS_MSC,
    AMUXBUS_PASS,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_0                = 0x0000u,  /* Left = AMUXBUS_MSC; Right = AMUXBUS_PASS */
    AMUX_SPLIT_CTL_1                = 0x0001u   /* Left = AMUXBUS_PASS; Right = AMUXBUS_MSC */
} cy_en_amux_split_t;

/* Port List */
/* PORT 0 (GPIO) */
#define P0_0_PORT                       GPIO_PRT0
#define P0_0_PIN                        0u
#define P0_0_NUM                        0u
#define P0_0_AMUXSEGMENT                AMUXBUS_MSC
#define P0_1_PORT                       GPIO_PRT0
#define P0_1_PIN                        1u
#define P0_1_NUM                        1u
#define P0_1_AMUXSEGMENT                AMUXBUS_MSC
#define P0_2_PORT                       GPIO_PRT0
#define P0_2_PIN                        2u
#define P0_2_NUM                        2u
#define P0_2_AMUXSEGMENT                AMUXBUS_MSC
#define P0_3_PORT                       GPIO_PRT0
#define P0_3_PIN                        3u
#define P0_3_NUM                        3u
#define P0_3_AMUXSEGMENT                AMUXBUS_MSC
#define P0_4_PORT                       GPIO_PRT0
#define P0_4_PIN                        4u
#define P0_4_NUM                        4u
#define P0_4_AMUXSEGMENT                AMUXBUS_MSC
#define P0_5_PORT                       GPIO_PRT0
#define P0_5_PIN                        5u
#define P0_5_NUM                        5u
#define P0_5_AMUXSEGMENT                AMUXBUS_MSC
#define P0_6_PORT                       GPIO_PRT0
#define P0_6_PIN                        6u
#define P0_6_NUM                        6u
#define P0_6_AMUXSEGMENT                AMUXBUS_MSC
#define P0_7_PORT                       GPIO_PRT0
#define P0_7_PIN                        7u
#define P0_7_NUM                        7u
#define P0_7_AMUXSEGMENT                AMUXBUS_MSC

/* PORT 1 (GPIO) */
#define P1_0_PORT                       GPIO_PRT1
#define P1_0_PIN                        0u
#define P1_0_NUM                        0u
#define P1_0_AMUXSEGMENT                AMUXBUS_MSC
#define P1_1_PORT                       GPIO_PRT1
#define P1_1_PIN                        1u
#define P1_1_NUM                        1u
#define P1_1_AMUXSEGMENT                AMUXBUS_MSC
#define P1_2_PORT                       GPIO_PRT1
#define P1_2_PIN                        2u
#define P1_2_NUM                        2u
#define P1_2_AMUXSEGMENT                AMUXBUS_MSC
#define P1_3_PORT                       GPIO_PRT1
#define P1_3_PIN                        3u
#define P1_3_NUM                        3u
#define P1_3_AMUXSEGMENT                AMUXBUS_MSC
#define P1_4_PORT                       GPIO_PRT1
#define P1_4_PIN                        4u
#define P1_4_NUM                        4u
#define P1_4_AMUXSEGMENT                AMUXBUS_MSC
#define P1_5_PORT                       GPIO_PRT1
#define P1_5_PIN                        5u
#define P1_5_NUM                        5u
#define P1_5_AMUXSEGMENT                AMUXBUS_MSC
#define P1_6_PORT                       GPIO_PRT1
#define P1_6_PIN                        6u
#define P1_6_NUM                        6u
#define P1_6_AMUXSEGMENT                AMUXBUS_MSC
#define P1_7_PORT                       GPIO_PRT1
#define P1_7_PIN                        7u
#define P1_7_NUM                        7u
#define P1_7_AMUXSEGMENT                AMUXBUS_MSC

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
#define P3_1_PORT                       GPIO_PRT3
#define P3_1_PIN                        1u
#define P3_1_NUM                        1u
#define P3_1_AMUXSEGMENT                AMUXBUS_MSC
#define P3_2_PORT                       GPIO_PRT3
#define P3_2_PIN                        2u
#define P3_2_NUM                        2u
#define P3_2_AMUXSEGMENT                AMUXBUS_MSC
#define P3_3_PORT                       GPIO_PRT3
#define P3_3_PIN                        3u
#define P3_3_NUM                        3u
#define P3_3_AMUXSEGMENT                AMUXBUS_MSC

/* PORT 4 (GPIO) */
#define P4_0_PORT                       GPIO_PRT4
#define P4_0_PIN                        0u
#define P4_0_NUM                        0u
#define P4_0_AMUXSEGMENT                AMUXBUS_MSC
#define P4_1_PORT                       GPIO_PRT4
#define P4_1_PIN                        1u
#define P4_1_NUM                        1u
#define P4_1_AMUXSEGMENT                AMUXBUS_MSC
#define P4_2_PORT                       GPIO_PRT4
#define P4_2_PIN                        2u
#define P4_2_NUM                        2u
#define P4_2_AMUXSEGMENT                AMUXBUS_MSC
#define P4_3_PORT                       GPIO_PRT4
#define P4_3_PIN                        3u
#define P4_3_NUM                        3u
#define P4_3_AMUXSEGMENT                AMUXBUS_MSC
#define P4_4_PORT                       GPIO_PRT4
#define P4_4_PIN                        4u
#define P4_4_NUM                        4u
#define P4_4_AMUXSEGMENT                AMUXBUS_MSC
#define P4_5_PORT                       GPIO_PRT4
#define P4_5_PIN                        5u
#define P4_5_NUM                        5u
#define P4_5_AMUXSEGMENT                AMUXBUS_MSC
#define P4_6_PORT                       GPIO_PRT4
#define P4_6_PIN                        6u
#define P4_6_NUM                        6u
#define P4_6_AMUXSEGMENT                AMUXBUS_MSC

/* PORT 5 (GPIO) */
#define P5_1_PORT                       GPIO_PRT5
#define P5_1_PIN                        1u
#define P5_1_NUM                        1u
#define P5_1_AMUXSEGMENT                AMUXBUS_MSC
#define P5_2_PORT                       GPIO_PRT5
#define P5_2_PIN                        2u
#define P5_2_NUM                        2u
#define P5_2_AMUXSEGMENT                AMUXBUS_MSC
#define P5_3_PORT                       GPIO_PRT5
#define P5_3_PIN                        3u
#define P5_3_NUM                        3u
#define P5_3_AMUXSEGMENT                AMUXBUS_MSC
#define P5_4_PORT                       GPIO_PRT5
#define P5_4_PIN                        4u
#define P5_4_NUM                        4u
#define P5_4_AMUXSEGMENT                AMUXBUS_MSC

/* MSC List */
#define P0_0_MSCLP_MSC_GPIO_CTRL_SNS    0u
#define P0_1_MSCLP_MSC_GPIO_CTRL_SNS    1u
#define P0_2_MSCLP_MSC_GPIO_CTRL_SNS    2u
#define P0_3_MSCLP_MSC_GPIO_CTRL_SNS    3u
#define P0_4_MSCLP_MSC_GPIO_CTRL_SNS    4u
#define P0_5_MSCLP_MSC_GPIO_CTRL_SNS    5u
#define P0_6_MSCLP_MSC_GPIO_CTRL_SNS    6u
#define P0_7_MSCLP_MSC_GPIO_CTRL_SNS    7u
#define P1_0_MSCLP_MSC_GPIO_CTRL_CMOD   1u
#define P1_1_MSCLP_MSC_GPIO_CTRL_CMOD   2u
#define P1_2_MSCLP_MSC_GPIO_CTRL_SNS    8u
#define P1_3_MSCLP_MSC_GPIO_CTRL_SNS    9u
#define P1_4_MSCLP_MSC_GPIO_CTRL_SNS    10u
#define P1_5_MSCLP_MSC_GPIO_CTRL_SNS    11u
#define P1_6_MSCLP_MSC_GPIO_CTRL_SNS    12u
#define P1_7_MSCLP_MSC_GPIO_CTRL_SNS    13u
#define P2_0_MSCLP_MSC_GPIO_CTRL_SNS    14u
#define P2_1_MSCLP_MSC_GPIO_CTRL_SNS    15u
#define P2_2_MSCLP_MSC_GPIO_CTRL_SNS    16u
#define P2_3_MSCLP_MSC_GPIO_CTRL_SNS    17u
#define P2_4_MSCLP_MSC_GPIO_CTRL_SNS    18u
#define P2_5_MSCLP_MSC_GPIO_CTRL_SNS    19u
#define P2_6_MSCLP_MSC_GPIO_CTRL_SNS    20u
#define P2_7_MSCLP_MSC_GPIO_CTRL_SNS    21u
#define P3_1_MSCLP_MSC_GPIO_CTRL_SNS    22u
#define P3_2_MSCLP_MSC_GPIO_CTRL_SNS    23u
#define P3_3_MSCLP_MSC_GPIO_CTRL_SNS    24u
#define P4_0_MSCLP_MSC_GPIO_CTRL_SNS    25u
#define P4_1_MSCLP_MSC_GPIO_CTRL_SNS    26u
#define P4_2_MSCLP_MSC_GPIO_CTRL_SNS    27u
#define P4_3_MSCLP_MSC_GPIO_CTRL_SNS    28u
#define P4_4_MSCLP_MSC_GPIO_CTRL_SNS    29u
#define P4_5_MSCLP_MSC_GPIO_CTRL_SNS    30u
#define P4_6_MSCLP_MSC_GPIO_CTRL_SNS    31u

/* Analog Connections */
#define MSCLP_CMOD1PADD_CCOMP_PORT      1u
#define MSCLP_CMOD1PADD_CCOMP_PIN       0u
#define MSCLP_CMOD1PADD_CREF_PORT       1u
#define MSCLP_CMOD1PADD_CREF_PIN        0u
#define MSCLP_CMOD1PADS_PORT            1u
#define MSCLP_CMOD1PADS_PIN             0u
#define MSCLP_CMOD2PADD_CCOMP_PORT      1u
#define MSCLP_CMOD2PADD_CCOMP_PIN       1u
#define MSCLP_CMOD2PADD_CREF_PORT       1u
#define MSCLP_CMOD2PADD_CREF_PIN        1u
#define MSCLP_CMOD2PADS_PORT            1u
#define MSCLP_CMOD2PADS_PIN             1u
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
#define SRSS_ADFT_POR_PAD_HV_PIN        4u
#define WCO_WCO_IN_PORT                 0u
#define WCO_WCO_IN_PIN                  2u
#define WCO_WCO_OUT_PORT                0u
#define WCO_WCO_OUT_PIN                 3u

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
    P0_0_MSCLP_SENSE                =  4,       /* msclp.sense:0 */
    P0_0_MSCLP_SHIELD               =  5,       /* msclp.shield:0 */
    P0_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_0_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:0 */
    P0_0_SCB0_UART_RX               =  9,       /* Digital Active - scb[0].uart_rx:0 */
    P0_0_PASS0_DSI_SAR_DATA_VALID   = 10,       /* Digital Active - pass[0].dsi_sar_data_valid */
    P0_0_TCPWM_TR_IN0               = 11,       /* Digital Active - tcpwm.tr_in[0]:0 */
    P0_0_MSCLP_MSC_DDRV0            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[0] */
    P0_0_SCB0_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */
    P0_0_SCB0_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[0].spi_select0:0 */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_1_MSCLP_SENSE                =  4,       /* msclp.sense:1 */
    P0_1_MSCLP_SHIELD               =  5,       /* msclp.shield:1 */
    P0_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_1_TCPWM_LINE_COMPL0          =  8,       /* Digital Active - tcpwm.line_compl[0]:0 */
    P0_1_SCB0_UART_TX               =  9,       /* Digital Active - scb[0].uart_tx:0 */
    P0_1_PASS0_TR_SAR_OUT           = 10,       /* Digital Active - pass[0].tr_sar_out */
    P0_1_TCPWM_TR_IN1               = 11,       /* Digital Active - tcpwm.tr_in[1]:0 */
    P0_1_MSCLP_MSC_DDRV1            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[1] */
    P0_1_SCB0_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */
    P0_1_SCB0_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[0].spi_select1:0 */

    /* P0.2 */
    P0_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_2_MSCLP_SENSE                =  4,       /* msclp.sense:2 */
    P0_2_MSCLP_SHIELD               =  5,       /* msclp.shield:2 */
    P0_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_2_SCB0_UART_CTS              =  9,       /* Digital Active - scb[0].uart_cts:0 */
    P0_2_PASS0_DSI_SAR_SAMPLE_DONE  = 10,       /* Digital Active - pass[0].dsi_sar_sample_done */
    P0_2_MSCLP_MSC_DDRV2            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[2] */
    P0_2_SCB0_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[0].spi_select2:0 */

    /* P0.3 */
    P0_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_3_MSCLP_SENSE                =  4,       /* msclp.sense:3 */
    P0_3_MSCLP_SHIELD               =  5,       /* msclp.shield:3 */
    P0_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_3_SCB0_UART_RTS              =  9,       /* Digital Active - scb[0].uart_rts:0 */
    P0_3_PASS0_DSI_SAR_DATA0        = 10,       /* Digital Active - pass[0].dsi_sar_data[0] */
    P0_3_MSCLP_MSC_DDRV3            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[3] */
    P0_3_SCB0_SPI_SELECT3           = 15,       /* Digital Deep Sleep - scb[0].spi_select3:0 */

    /* P0.4 */
    P0_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_4_MSCLP_SENSE                =  4,       /* msclp.sense:4 */
    P0_4_MSCLP_SHIELD               =  5,       /* msclp.shield:4 */
    P0_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_4_SRSS_EXT_CLK               =  8,       /* Digital Active - srss.ext_clk */
    P0_4_PASS0_DSI_SAR_DATA1        = 10,       /* Digital Active - pass[0].dsi_sar_data[1] */
    P0_4_MSCLP_MSC_DDRV4            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[4] */
    P0_4_SCB0_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[0].spi_mosi:0 */

    /* P0.5 */
    P0_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_5_MSCLP_SENSE                =  4,       /* msclp.sense:5 */
    P0_5_MSCLP_SHIELD               =  5,       /* msclp.shield:5 */
    P0_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_5_MSCLP_MSC_DDRV5            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[5] */
    P0_5_SCB0_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[0].spi_miso:0 */

    /* P0.6 */
    P0_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_6_MSCLP_SENSE                =  4,       /* msclp.sense:6 */
    P0_6_MSCLP_SHIELD               =  5,       /* msclp.shield:6 */
    P0_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_6_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1]:0 */
    P0_6_MSCLP_MSC_DDRV6            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[6] */
    P0_6_SCB0_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[0].spi_clk:0 */

    /* P0.7 */
    P0_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_7_MSCLP_SENSE                =  4,       /* msclp.sense:7 */
    P0_7_MSCLP_SHIELD               =  5,       /* msclp.shield:7 */
    P0_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_7_TCPWM_LINE_COMPL1          =  8,       /* Digital Active - tcpwm.line_compl[1]:0 */
    P0_7_MSCLP_MSC_DDRV7            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[7] */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_0_MSCLP_SENSE                =  4,       /* msclp.sense:8 */
    P1_0_MSCLP_SHIELD               =  5,       /* msclp.shield:8 */
    P1_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_0_MSCLP_MSC_CMOD1_DDRV       = 12,       /* Digital Deep Sleep - msclp.msc_cmod1_ddrv */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_1_MSCLP_SENSE                =  4,       /* msclp.sense:9 */
    P1_1_MSCLP_SHIELD               =  5,       /* msclp.shield:9 */
    P1_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_1_MSCLP_MSC_CMOD2_DDRV       = 12,       /* Digital Deep Sleep - msclp.msc_cmod2_ddrv */

    /* P1.2 */
    P1_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_2_MSCLP_SENSE                =  4,       /* msclp.sense:10 */
    P1_2_MSCLP_SHIELD               =  5,       /* msclp.shield:10 */
    P1_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_2_MSCLP_MSC_DDRV8            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[8] */

    /* P1.3 */
    P1_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_3_MSCLP_SENSE                =  4,       /* msclp.sense:11 */
    P1_3_MSCLP_SHIELD               =  5,       /* msclp.shield:11 */
    P1_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_3_MSCLP_MSC_DDRV9            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[9] */
    P1_3_SCB1_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[1].spi_select0:0 */

    /* P1.4 */
    P1_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_4_MSCLP_SENSE                =  4,       /* msclp.sense:12 */
    P1_4_MSCLP_SHIELD               =  5,       /* msclp.shield:12 */
    P1_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_4_SCB1_UART_RX               =  9,       /* Digital Active - scb[1].uart_rx:0 */
    P1_4_PASS0_DSI_SAR_DATA2        = 10,       /* Digital Active - pass[0].dsi_sar_data[2]:0 */
    P1_4_TCPWM_TR_IN2               = 11,       /* Digital Active - tcpwm.tr_in[2]:0 */
    P1_4_MSCLP_MSC_DDRV10           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[10] */
    P1_4_SCB1_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[1].i2c_scl:0 */
    P1_4_SCB1_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[1].spi_select1:0 */

    /* P1.5 */
    P1_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_5_MSCLP_SENSE                =  4,       /* msclp.sense:13 */
    P1_5_MSCLP_SHIELD               =  5,       /* msclp.shield:13 */
    P1_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_5_SCB1_UART_TX               =  9,       /* Digital Active - scb[1].uart_tx:0 */
    P1_5_PASS0_DSI_SAR_DATA3        = 10,       /* Digital Active - pass[0].dsi_sar_data[3]:0 */
    P1_5_TCPWM_TR_IN3               = 11,       /* Digital Active - tcpwm.tr_in[3]:0 */
    P1_5_MSCLP_MSC_DDRV11           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[11] */
    P1_5_MSCLP_EXT_SYNC             = 13,       /* Digital Deep Sleep - msclp.ext_sync:0 */
    P1_5_SCB1_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[1].i2c_sda:0 */
    P1_5_SCB1_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[1].spi_mosi:0 */

    /* P1.6 */
    P1_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_6_MSCLP_SENSE                =  4,       /* msclp.sense:14 */
    P1_6_MSCLP_SHIELD               =  5,       /* msclp.shield:14 */
    P1_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_6_SCB1_UART_CTS              =  9,       /* Digital Active - scb[1].uart_cts:0 */
    P1_6_MSCLP_MSC_DDRV12           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[12] */
    P1_6_MSCLP_EXT_SYNC_CLK         = 13,       /* Digital Deep Sleep - msclp.ext_sync_clk:0 */
    P1_6_SCB1_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[1].spi_miso:0 */

    /* P1.7 */
    P1_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_7_MSCLP_SENSE                =  4,       /* msclp.sense:15 */
    P1_7_MSCLP_SHIELD               =  5,       /* msclp.shield:15 */
    P1_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_7_SCB1_UART_RTS              =  9,       /* Digital Active - scb[1].uart_rts:0 */
    P1_7_MSCLP_MSC_DDRV13           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[13] */
    P1_7_MSCLP_EXT_FRM_START        = 13,       /* Digital Deep Sleep - msclp.ext_frm_start:0 */
    P1_7_SCB1_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[1].spi_clk:0 */

    /* P2.0 */
    P2_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_0_MSCLP_SENSE                =  4,       /* msclp.sense:16 */
    P2_0_MSCLP_SHIELD               =  5,       /* msclp.shield:16 */
    P2_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_0_TCPWM_LINE2                =  8,       /* Digital Active - tcpwm.line[2]:0 */
    P2_0_SCB2_UART_RX               =  9,       /* Digital Active - scb[2].uart_rx:0 */
    P2_0_PASS0_DSI_SAR_DATA4        = 10,       /* Digital Active - pass[0].dsi_sar_data[4]:0 */
    P2_0_TCPWM_TR_IN4               = 11,       /* Digital Active - tcpwm.tr_in[4]:0 */
    P2_0_MSCLP_MSC_DDRV14           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[14] */
    P2_0_MSCLP_OBS_DATA3            = 13,       /* Digital Deep Sleep - msclp.obs_data[3] */
    P2_0_SCB0_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[0].i2c_scl:1 */
    P2_0_SCB0_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[0].spi_select0:1 */

    /* P2.1 */
    P2_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_1_MSCLP_SENSE                =  4,       /* msclp.sense:17 */
    P2_1_MSCLP_SHIELD               =  5,       /* msclp.shield:17 */
    P2_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_1_TCPWM_LINE_COMPL2          =  8,       /* Digital Active - tcpwm.line_compl[2]:0 */
    P2_1_SCB2_UART_TX               =  9,       /* Digital Active - scb[2].uart_tx:0 */
    P2_1_PASS0_DSI_SAR_DATA5        = 10,       /* Digital Active - pass[0].dsi_sar_data[5]:0 */
    P2_1_TCPWM_TR_IN5               = 11,       /* Digital Active - tcpwm.tr_in[5]:0 */
    P2_1_MSCLP_MSC_DDRV15           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[15] */
    P2_1_MSCLP_OBS_DATA2            = 13,       /* Digital Deep Sleep - msclp.obs_data[2] */
    P2_1_SCB0_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[0].i2c_sda:1 */
    P2_1_SCB0_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[0].spi_select1:1 */

    /* P2.2 */
    P2_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_2_MSCLP_SENSE                =  4,       /* msclp.sense:18 */
    P2_2_MSCLP_SHIELD               =  5,       /* msclp.shield:18 */
    P2_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_2_TCPWM_LINE3                =  8,       /* Digital Active - tcpwm.line[3]:0 */
    P2_2_SCB2_UART_CTS              =  9,       /* Digital Active - scb[2].uart_cts:0 */
    P2_2_MSCLP_MSC_DDRV16           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[16] */
    P2_2_MSCLP_OBS_DATA1            = 13,       /* Digital Deep Sleep - msclp.obs_data[1] */
    P2_2_SCB0_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[0].spi_select2:1 */

    /* P2.3 */
    P2_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_3_MSCLP_SENSE                =  4,       /* msclp.sense:19 */
    P2_3_MSCLP_SHIELD               =  5,       /* msclp.shield:19 */
    P2_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_3_TCPWM_LINE_COMPL3          =  8,       /* Digital Active - tcpwm.line_compl[3]:0 */
    P2_3_SCB2_UART_RTS              =  9,       /* Digital Active - scb[2].uart_rts:0 */
    P2_3_MSCLP_MSC_DDRV17           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[17] */
    P2_3_MSCLP_OBS_DATA0            = 13,       /* Digital Deep Sleep - msclp.obs_data[0] */
    P2_3_SCB0_SPI_SELECT3           = 15,       /* Digital Deep Sleep - scb[0].spi_select3:1 */

    /* P2.4 */
    P2_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_4_MSCLP_SENSE                =  4,       /* msclp.sense:20 */
    P2_4_MSCLP_SHIELD               =  5,       /* msclp.shield:20 */
    P2_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_4_TCPWM_LINE4                =  8,       /* Digital Active - tcpwm.line[4]:0 */
    P2_4_SCB3_UART_RX               =  9,       /* Digital Active - scb[3].uart_rx:1 */
    P2_4_PASS0_DSI_SAR_DATA6        = 10,       /* Digital Active - pass[0].dsi_sar_data[6]:0 */
    P2_4_MSCLP_MSC_DDRV18           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[18] */
    P2_4_MSCLP_EXT_SYNC             = 13,       /* Digital Deep Sleep - msclp.ext_sync:1 */
    P2_4_SCB0_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[0].spi_mosi:1 */

    /* P2.5 */
    P2_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_5_MSCLP_SENSE                =  4,       /* msclp.sense:21 */
    P2_5_MSCLP_SHIELD               =  5,       /* msclp.shield:21 */
    P2_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_5_TCPWM_LINE_COMPL4          =  8,       /* Digital Active - tcpwm.line_compl[4]:0 */
    P2_5_SCB3_UART_TX               =  9,       /* Digital Active - scb[3].uart_tx:1 */
    P2_5_PASS0_DSI_SAR_DATA7        = 10,       /* Digital Active - pass[0].dsi_sar_data[7]:0 */
    P2_5_TCPWM_TR_IN6               = 11,       /* Digital Active - tcpwm.tr_in[6]:0 */
    P2_5_MSCLP_MSC_DDRV19           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[19] */
    P2_5_MSCLP_EXT_SYNC_CLK         = 13,       /* Digital Deep Sleep - msclp.ext_sync_clk:1 */
    P2_5_SCB0_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[0].spi_miso:1 */

    /* P2.6 */
    P2_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_6_MSCLP_SENSE                =  4,       /* msclp.sense:22 */
    P2_6_MSCLP_SHIELD               =  5,       /* msclp.shield:22 */
    P2_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_6_TCPWM_LINE5                =  8,       /* Digital Active - tcpwm.line[5]:0 */
    P2_6_SCB3_UART_CTS              =  9,       /* Digital Active - scb[3].uart_cts:1 */
    P2_6_TCPWM_TR_IN0               = 11,       /* Digital Active - tcpwm.tr_in[0]:1 */
    P2_6_MSCLP_MSC_DDRV20           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[20] */
    P2_6_MSCLP_EXT_FRM_START        = 13,       /* Digital Deep Sleep - msclp.ext_frm_start:1 */
    P2_6_SCB0_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[0].spi_clk:1 */

    /* P2.7 */
    P2_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_7_MSCLP_SENSE                =  4,       /* msclp.sense:23 */
    P2_7_MSCLP_SHIELD               =  5,       /* msclp.shield:23 */
    P2_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_7_TCPWM_LINE_COMPL5          =  8,       /* Digital Active - tcpwm.line_compl[5]:0 */
    P2_7_SCB3_UART_RTS              =  9,       /* Digital Active - scb[3].uart_rts:1 */
    P2_7_MSCLP_MSC_DDRV21           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[21] */

    /* P3.1 */
    P3_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_1_MSCLP_SENSE                =  4,       /* msclp.sense:24 */
    P3_1_MSCLP_SHIELD               =  5,       /* msclp.shield:24 */
    P3_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_1_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:1 */
    P3_1_SCB3_UART_RTS              =  9,       /* Digital Active - scb[3].uart_rts:0 */
    P3_1_PASS0_DSI_SAR_DATA8        = 10,       /* Digital Active - pass[0].dsi_sar_data[8]:0 */
    P3_1_TCPWM_TR_IN1               = 11,       /* Digital Active - tcpwm.tr_in[1]:1 */
    P3_1_MSCLP_MSC_DDRV22           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[22] */
    P3_1_SCB0_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[0].spi_select1:2 */

    /* P3.2 */
    P3_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_2_MSCLP_SENSE                =  4,       /* msclp.sense:25 */
    P3_2_MSCLP_SHIELD               =  5,       /* msclp.shield:25 */
    P3_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_2_TCPWM_LINE_COMPL0          =  8,       /* Digital Active - tcpwm.line_compl[0]:1 */
    P3_2_SCB3_UART_RX               =  9,       /* Digital Active - scb[3].uart_rx:0 */
    P3_2_PASS0_DSI_SAR_DATA9        = 10,       /* Digital Active - pass[0].dsi_sar_data[9]:0 */
    P3_2_TCPWM_TR_IN2               = 11,       /* Digital Active - tcpwm.tr_in[2]:1 */
    P3_2_MSCLP_MSC_DDRV23           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[23] */
    P3_2_CPUSS_SWD_DATA             = 13,       /* Digital Deep Sleep - cpuss.swd_data:0 */
    P3_2_SCB0_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[0].i2c_sda:2 */
    P3_2_SCB0_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[0].spi_select2:2 */

    /* P3.3 */
    P3_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_3_MSCLP_SENSE                =  4,       /* msclp.sense:26 */
    P3_3_MSCLP_SHIELD               =  5,       /* msclp.shield:26 */
    P3_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_3_SCB3_UART_TX               =  9,       /* Digital Active - scb[3].uart_tx:0 */
    P3_3_MSCLP_MSC_DDRV24           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[24] */
    P3_3_CPUSS_SWD_CLK              = 13,       /* Digital Deep Sleep - cpuss.swd_clk:0 */
    P3_3_SCB0_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[0].i2c_scl:2 */
    P3_3_SCB0_SPI_SELECT3           = 15,       /* Digital Deep Sleep - scb[0].spi_select3:2 */

    /* P4.0 */
    P4_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_0_MSCLP_SENSE                =  4,       /* msclp.sense:27 */
    P4_0_MSCLP_SHIELD               =  5,       /* msclp.shield:27 */
    P4_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_0_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1]:1 */
    P4_0_SCB4_UART_RX               =  9,       /* Digital Active - scb[4].uart_rx:0 */
    P4_0_PASS0_DSI_SAR_DATA10       = 10,       /* Digital Active - pass[0].dsi_sar_data[10]:0 */
    P4_0_TCPWM_TR_IN3               = 11,       /* Digital Active - tcpwm.tr_in[3]:1 */
    P4_0_MSCLP_MSC_DDRV25           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[25] */
    P4_0_SCB1_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[1].i2c_scl:1 */
    P4_0_SCB1_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[1].spi_select0:1 */

    /* P4.1 */
    P4_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_1_MSCLP_SENSE                =  4,       /* msclp.sense:28 */
    P4_1_MSCLP_SHIELD               =  5,       /* msclp.shield:28 */
    P4_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_1_TCPWM_LINE_COMPL1          =  8,       /* Digital Active - tcpwm.line_compl[1]:1 */
    P4_1_SCB4_UART_TX               =  9,       /* Digital Active - scb[4].uart_tx:0 */
    P4_1_PASS0_DSI_SAR_DATA11       = 10,       /* Digital Active - pass[0].dsi_sar_data[11]:0 */
    P4_1_TCPWM_TR_IN4               = 11,       /* Digital Active - tcpwm.tr_in[4]:1 */
    P4_1_MSCLP_MSC_DDRV26           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[26] */
    P4_1_SCB1_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[1].i2c_sda:1 */
    P4_1_SCB1_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[1].spi_select1:1 */

    /* P4.2 */
    P4_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_2_MSCLP_SENSE                =  4,       /* msclp.sense:29 */
    P4_2_MSCLP_SHIELD               =  5,       /* msclp.shield:29 */
    P4_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_2_TCPWM_LINE2                =  8,       /* Digital Active - tcpwm.line[2]:1 */
    P4_2_SCB4_UART_CTS              =  9,       /* Digital Active - scb[4].uart_cts:0 */
    P4_2_MSCLP_MSC_DDRV27           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[27] */
    P4_2_SCB1_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[1].spi_select2:0 */

    /* P4.3 */
    P4_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_3_MSCLP_SENSE                =  4,       /* msclp.sense:30 */
    P4_3_MSCLP_SHIELD               =  5,       /* msclp.shield:30 */
    P4_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_3_TCPWM_LINE_COMPL2          =  8,       /* Digital Active - tcpwm.line_compl[2]:1 */
    P4_3_SCB4_UART_RTS              =  9,       /* Digital Active - scb[4].uart_rts:0 */
    P4_3_MSCLP_MSC_DDRV28           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[28] */
    P4_3_SCB1_SPI_SELECT3           = 15,       /* Digital Deep Sleep - scb[1].spi_select3:0 */

    /* P4.4 */
    P4_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_4_MSCLP_SENSE                =  4,       /* msclp.sense:31 */
    P4_4_MSCLP_SHIELD               =  5,       /* msclp.shield:31 */
    P4_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_4_TCPWM_LINE3                =  8,       /* Digital Active - tcpwm.line[3]:1 */
    P4_4_TCPWM_TR_IN5               = 11,       /* Digital Active - tcpwm.tr_in[5]:1 */
    P4_4_MSCLP_MSC_DDRV29           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[29] */
    P4_4_SCB1_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[1].spi_mosi:1 */

    /* P4.5 */
    P4_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_5_MSCLP_SENSE                =  4,       /* msclp.sense:32 */
    P4_5_MSCLP_SHIELD               =  5,       /* msclp.shield:32 */
    P4_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_5_TCPWM_LINE_COMPL3          =  8,       /* Digital Active - tcpwm.line_compl[3]:1 */
    P4_5_TCPWM_TR_IN6               = 11,       /* Digital Active - tcpwm.tr_in[6]:1 */
    P4_5_MSCLP_MSC_DDRV30           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[30] */
    P4_5_SCB1_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[1].spi_miso:1 */

    /* P4.6 */
    P4_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_6_MSCLP_SENSE                =  4,       /* msclp.sense:33 */
    P4_6_MSCLP_SHIELD               =  5,       /* msclp.shield:33 */
    P4_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_6_TCPWM_LINE4                =  8,       /* Digital Active - tcpwm.line[4]:1 */
    P4_6_MSCLP_MSC_DDRV31           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[31] */
    P4_6_SCB1_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[1].spi_clk:1 */

    /* P5.1 */
    P5_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_1_TCPWM_LINE5                =  8,       /* Digital Active - tcpwm.line[5]:1 */
    P5_1_SCB0_UART_RX               =  9,       /* Digital Active - scb[0].uart_rx:1 */
    P5_1_TCPWM_TR_IN0               = 11,       /* Digital Active - tcpwm.tr_in[0]:2 */
    P5_1_SCB1_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[1].i2c_scl:2 */
    P5_1_SCB1_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[1].spi_mosi:2 */

    /* P5.2 */
    P5_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_2_TCPWM_LINE_COMPL5          =  8,       /* Digital Active - tcpwm.line_compl[5]:1 */
    P5_2_SCB0_UART_TX               =  9,       /* Digital Active - scb[0].uart_tx:1 */
    P5_2_TCPWM_TR_IN1               = 11,       /* Digital Active - tcpwm.tr_in[1]:2 */
    P5_2_SCB1_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[1].i2c_sda:2 */
    P5_2_SCB1_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[1].spi_miso:2 */

    /* P5.3 */
    P5_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_3_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:2 */
    P5_3_SCB0_UART_CTS              =  9,       /* Digital Active - scb[0].uart_cts:1 */
    P5_3_TCPWM_TR_IN2               = 11,       /* Digital Active - tcpwm.tr_in[2]:2 */
    P5_3_SCB1_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[1].spi_clk:2 */

    /* P5.4 */
    P5_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_4_TCPWM_LINE_COMPL0          =  8,       /* Digital Active - tcpwm.line_compl[0]:2 */
    P5_4_SCB0_UART_RTS              =  9,       /* Digital Active - scb[0].uart_rts:1 */
    P5_4_TCPWM_TR_IN3               = 11,       /* Digital Active - tcpwm.tr_in[3]:2 */
    P5_4_SCB1_SPI_SELECT0           = 15        /* Digital Deep Sleep - scb[1].spi_select0:2 */
} en_hsiom_sel_t;

#endif /* _GPIO_PSOC4100TP_48_QFN_H_ */


/* [] END OF FILE */
