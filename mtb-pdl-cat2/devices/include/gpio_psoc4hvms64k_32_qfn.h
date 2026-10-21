/***************************************************************************//**
* \file gpio_psoc4hvms64k_32_qfn.h
*
* \brief
* PSOC4HVMS64K device GPIO header for 32-QFN package
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

#ifndef _GPIO_PSOC4HVMS64K_32_QFN_H_
#define _GPIO_PSOC4HVMS64K_32_QFN_H_

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
    AMUXBUS_MSC,
    AMUXBUS_SYS,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_0                = 0x0000u,  /* Left = AMUXBUS_MSC; Right = AMUXBUS_SYS */
    AMUX_SPLIT_CTL_1                = 0x0001u   /* Left = AMUXBUS_SYS; Right = AMUXBUS_MSC */
} cy_en_amux_split_t;

/* Port List */
/* PORT 0 (GPIO) */
#define P0_0_PORT                       GPIO_PRT0
#define P0_0_PIN                        0u
#define P0_0_NUM                        0u
#define P0_0_AMUXSEGMENT                AMUXBUS_SYS
#define P0_1_PORT                       GPIO_PRT0
#define P0_1_PIN                        1u
#define P0_1_NUM                        1u
#define P0_1_AMUXSEGMENT                AMUXBUS_SYS
#define P0_2_PORT                       GPIO_PRT0
#define P0_2_PIN                        2u
#define P0_2_NUM                        2u
#define P0_2_AMUXSEGMENT                AMUXBUS_SYS
#define P0_3_PORT                       GPIO_PRT0
#define P0_3_PIN                        3u
#define P0_3_NUM                        3u
#define P0_3_AMUXSEGMENT                AMUXBUS_SYS

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

/* PORT 3 (GPIO) */
#define P3_0_PORT                       GPIO_PRT3
#define P3_0_PIN                        0u
#define P3_0_NUM                        0u
#define P3_0_AMUXSEGMENT                AMUXBUS_MSC

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

/* PORT 5 (GPIO) */
#define P5_0_PORT                       GPIO_PRT5
#define P5_0_PIN                        0u
#define P5_0_NUM                        0u
#define P5_0_AMUXSEGMENT                AMUXBUS_MSC
#define P5_1_PORT                       GPIO_PRT5
#define P5_1_PIN                        1u
#define P5_1_NUM                        1u
#define P5_1_AMUXSEGMENT                AMUXBUS_MSC

/* PORT 7 (GPIO) */
#define P7_0_PORT                       GPIO_PRT7
#define P7_0_PIN                        0u
#define P7_0_NUM                        0u
#define P7_0_AMUXSEGMENT                AMUXBUS_MSC
#define P7_1_PORT                       GPIO_PRT7
#define P7_1_PIN                        1u
#define P7_1_NUM                        1u
#define P7_1_AMUXSEGMENT                AMUXBUS_MSC

/* Analog Connections */
#define LPCOMP0_IN_N0_PORT              1u
#define LPCOMP0_IN_N0_PIN               2u
#define LPCOMP0_IN_N1_PORT              1u
#define LPCOMP0_IN_N1_PIN               4u
#define LPCOMP0_IN_P0_PORT              1u
#define LPCOMP0_IN_P0_PIN               1u
#define LPCOMP0_IN_P1_PORT              1u
#define LPCOMP0_IN_P1_PIN               3u
#define LPCOMP1_IN_N0_PORT              0u
#define LPCOMP1_IN_N0_PIN               2u
#define LPCOMP1_IN_N1_PORT              0u
#define LPCOMP1_IN_N1_PIN               0u
#define LPCOMP1_IN_P0_PORT              0u
#define LPCOMP1_IN_P0_PIN               3u
#define LPCOMP1_IN_P1_PORT              0u
#define LPCOMP1_IN_P1_PIN               1u
#define MSC0_CMOD1PADD_PORT             4u
#define MSC0_CMOD1PADD_PIN              0u
#define MSC0_CMOD1PADS_PORT             4u
#define MSC0_CMOD1PADS_PIN              0u
#define MSC0_CMOD2PADD_PORT             4u
#define MSC0_CMOD2PADD_PIN              1u
#define MSC0_CMOD2PADS_PORT             4u
#define MSC0_CMOD2PADS_PIN              1u
#define MSC0_CMOD3PADD_PORT             4u
#define MSC0_CMOD3PADD_PIN              2u
#define MSC0_CMOD3PADS_PORT             4u
#define MSC0_CMOD3PADS_PIN              2u
#define MSC0_S_PAD10_PORT               1u
#define MSC0_S_PAD10_PIN                4u
#define MSC0_S_PAD11_PORT               1u
#define MSC0_S_PAD11_PIN                5u
#define MSC0_S_PAD14_PORT               3u
#define MSC0_S_PAD14_PIN                0u
#define MSC0_S_PAD5_PORT                7u
#define MSC0_S_PAD5_PIN                 0u
#define MSC0_S_PAD6_PORT                7u
#define MSC0_S_PAD6_PIN                 1u
#define MSC0_S_PAD7_PORT                1u
#define MSC0_S_PAD7_PIN                 1u
#define MSC0_S_PAD8_PORT                1u
#define MSC0_S_PAD8_PIN                 2u
#define MSC0_S_PAD9_PORT                1u
#define MSC0_S_PAD9_PIN                 3u
#define PASS0_SAR_EXT_VREF0_PORT        1u
#define PASS0_SAR_EXT_VREF0_PIN         0u
#define PASS0_SAR_EXT_VREF1_PORT        1u
#define PASS0_SAR_EXT_VREF1_PIN         0u
#define PASS0_SARMUX_PADS0_PORT         5u
#define PASS0_SARMUX_PADS0_PIN          0u
#define PASS0_SARMUX_PADS1_PORT         5u
#define PASS0_SARMUX_PADS1_PIN          1u
#define SRSS_ADFT_POR_PAD_HV_PORT       1u
#define SRSS_ADFT_POR_PAD_HV_PIN        0u

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
    P0_0_MSC0_SENSE                 =  4,       /* msc[0].sense:31 */
    P0_0_MSC0_SHIELD                =  5,       /* msc[0].shield:31 */
    P0_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_0_PERI_VIRT_IN_0             =  8,       /* Digital Active - peri.virt_in_0 */
    P0_0_LIN_LIN_TX0                =  9,       /* Digital Active - lin.lin_tx[0]:0 */
    P0_0_SCB0_UART_RX               = 10,       /* Digital Active - scb[0].uart_rx:0 */
    P0_0_TCPWM_LINE0                = 11,       /* Digital Active - tcpwm.line[0]:0 */
    P0_0_SCB0_SPI_CLK               = 12,       /* Digital Deep Sleep - scb[0].spi_clk:0 */
    P0_0_SCB0_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_1_MSC0_SENSE                 =  4,       /* msc[0].sense:30 */
    P0_1_MSC0_SHIELD                =  5,       /* msc[0].shield:30 */
    P0_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_1_SRSS_EXT_CLK               =  8,       /* Digital Active - srss.ext_clk */
    P0_1_LIN_LIN_RX0                =  9,       /* Digital Active - lin.lin_rx[0]:0 */
    P0_1_SCB0_UART_TX               = 10,       /* Digital Active - scb[0].uart_tx:0 */
    P0_1_TCPWM_LINE_COMPL0          = 11,       /* Digital Active - tcpwm.line_compl[0]:0 */
    P0_1_SCB0_SPI_MOSI              = 12,       /* Digital Deep Sleep - scb[0].spi_mosi:0 */
    P0_1_SCB0_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */

    /* P0.2 */
    P0_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_2_MSC0_SENSE                 =  4,       /* msc[0].sense:29 */
    P0_2_MSC0_SHIELD                =  5,       /* msc[0].shield:29 */
    P0_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_2_TCPWM_TR_IN3               =  8,       /* Digital Active - tcpwm.tr_in[3] */
    P0_2_LIN_LIN_EN0                =  9,       /* Digital Active - lin.lin_en[0]:0 */
    P0_2_SCB0_UART_RTS              = 10,       /* Digital Active - scb[0].uart_rts:0 */
    P0_2_TCPWM_LINE1                = 11,       /* Digital Active - tcpwm.line[1]:0 */
    P0_2_SCB0_SPI_MISO              = 12,       /* Digital Deep Sleep - scb[0].spi_miso:0 */
    P0_2_SCB0_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[0].i2c_scl:1 */

    /* P0.3 */
    P0_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_3_MSC0_SENSE                 =  4,       /* msc[0].sense:28 */
    P0_3_MSC0_SHIELD                =  5,       /* msc[0].shield:28 */
    P0_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_3_TCPWM_TR_IN2               =  8,       /* Digital Active - tcpwm.tr_in[2] */
    P0_3_SCB0_UART_CTS              = 10,       /* Digital Active - scb[0].uart_cts:0 */
    P0_3_TCPWM_LINE_COMPL1          = 11,       /* Digital Active - tcpwm.line_compl[1]:0 */
    P0_3_SCB0_SPI_SELECT0           = 12,       /* Digital Deep Sleep - scb[0].spi_select0 */
    P0_3_SCB0_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[0].i2c_sda:1 */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_0_MSC0_SENSE                 =  4,       /* msc[0].sense:10 */
    P1_0_MSC0_SHIELD                =  5,       /* msc[0].shield:10 */
    P1_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_0_CXPI_CXPI_EN0              =  8,       /* Digital Active - cxpi.cxpi_en[0]:1 */
    P1_0_HVSS_LIN_ALT_EN            =  9,       /* Digital Active - hvss.lin_alt_en */
    P1_0_SCB1_UART_CTS              = 10,       /* Digital Active - scb[1].uart_cts:1 */
    P1_0_TCPWM_LINE2                = 11,       /* Digital Active - tcpwm.line[2]:2 */
    P1_0_CPUSS_FAULT_OUT0           = 14,       /* Digital Deep Sleep - cpuss.fault_out[0] */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_1_MSC0_SENSE                 =  4,       /* msc[0].sense:11 */
    P1_1_MSC0_SHIELD                =  5,       /* msc[0].shield:11 */
    P1_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_1_MSC0_EXT_SYNC              =  8,       /* Digital Active - msc[0].ext_sync */
    P1_1_HVSS_LIN_ALT_TXD           =  9,       /* Digital Active - hvss.lin_alt_txd */
    P1_1_SCB1_UART_RTS              = 10,       /* Digital Active - scb[1].uart_rts:1 */
    P1_1_TCPWM_LINE_COMPL3          = 11,       /* Digital Active - tcpwm.line_compl[3]:2 */
    P1_1_SCB1_SPI_CLK               = 12,       /* Digital Deep Sleep - scb[1].spi_clk:0 */
    P1_1_CPUSS_FAULT_OUT1           = 14,       /* Digital Deep Sleep - cpuss.fault_out[1] */

    /* P1.2 */
    P1_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_2_MSC0_SENSE                 =  4,       /* msc[0].sense:12 */
    P1_2_MSC0_SHIELD                =  5,       /* msc[0].shield:12 */
    P1_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_2_MSC0_EXT_SYNC_CLK          =  8,       /* Digital Active - msc[0].ext_sync_clk */
    P1_2_HVSS_LIN_ALT_RXD           =  9,       /* Digital Active - hvss.lin_alt_rxd */
    P1_2_SCB1_UART_TX               = 10,       /* Digital Active - scb[1].uart_tx:0 */
    P1_2_TCPWM_LINE3                = 11,       /* Digital Active - tcpwm.line[3]:2 */
    P1_2_SCB1_SPI_SELECT1           = 12,       /* Digital Deep Sleep - scb[1].spi_select1 */
    P1_2_SCB1_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[1].i2c_sda:0 */

    /* P1.3 */
    P1_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_3_MSC0_SENSE                 =  4,       /* msc[0].sense:13 */
    P1_3_MSC0_SHIELD                =  5,       /* msc[0].shield:13 */
    P1_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_3_MSC0_EXT_FRM_START         =  8,       /* Digital Active - msc[0].ext_frm_start */
    P1_3_LIN_LIN_EN0                =  9,       /* Digital Active - lin.lin_en[0]:1 */
    P1_3_SCB1_UART_RX               = 10,       /* Digital Active - scb[1].uart_rx:0 */
    P1_3_TCPWM_LINE_COMPL3          = 11,       /* Digital Active - tcpwm.line_compl[3]:1 */
    P1_3_SCB1_SPI_SELECT0           = 12,       /* Digital Deep Sleep - scb[1].spi_select0 */
    P1_3_SCB1_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[1].i2c_scl:0 */

    /* P1.4 */
    P1_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_4_MSC0_SENSE                 =  4,       /* msc[0].sense:14 */
    P1_4_MSC0_SHIELD                =  5,       /* msc[0].shield:14 */
    P1_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_4_PERI_VIRT_IN_2             =  8,       /* Digital Active - peri.virt_in_2 */
    P1_4_SCB1_UART_CTS              = 10,       /* Digital Active - scb[1].uart_cts:0 */
    P1_4_TCPWM_LINE_COMPL4          = 11,       /* Digital Active - tcpwm.line_compl[4]:1 */
    P1_4_SCB0_SPI_MOSI              = 12,       /* Digital Deep Sleep - scb[0].spi_mosi:1 */
    P1_4_CPUSS_SWD_CLK              = 14,       /* Digital Deep Sleep - cpuss.swd_clk */

    /* P1.5 */
    P1_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_5_MSC0_SENSE                 =  4,       /* msc[0].sense:15 */
    P1_5_MSC0_SHIELD                =  5,       /* msc[0].shield:15 */
    P1_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_5_PERI_VIRT_IN_1             =  8,       /* Digital Active - peri.virt_in_1 */
    P1_5_SCB1_UART_RTS              = 10,       /* Digital Active - scb[1].uart_rts:0 */
    P1_5_TCPWM_LINE3                = 11,       /* Digital Active - tcpwm.line[3]:1 */
    P1_5_SCB0_SPI_CLK               = 12,       /* Digital Deep Sleep - scb[0].spi_clk:1 */
    P1_5_LPCOMP1_COMP0              = 13,       /* Digital Deep Sleep - lpcomp[1].comp[0]:1 */
    P1_5_CPUSS_SWD_DATA             = 14,       /* Digital Deep Sleep - cpuss.swd_data */
    P1_5_LPCOMP0_COMP0              = 15,       /* Digital Deep Sleep - lpcomp[0].comp[0]:1 */

    /* P3.0 */
    P3_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_0_MSC0_SENSE                 =  4,       /* msc[0].sense:18 */
    P3_0_MSC0_SHIELD                =  5,       /* msc[0].shield:18 */
    P3_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_0_MSC0_OBS_DATA0             =  8,       /* Digital Active - msc[0].obs_data[0] */
    P3_0_PASS0_DSI_SAR_DATA1        = 10,       /* Digital Active - pass[0].dsi_sar_data[1] */
    P3_0_TCPWM_LINE_COMPL4          = 11,       /* Digital Active - tcpwm.line_compl[4]:0 */
    P3_0_SCB0_SPI_MISO              = 12,       /* Digital Deep Sleep - scb[0].spi_miso:1 */
    P3_0_LPCOMP1_COMP1              = 13,       /* Digital Deep Sleep - lpcomp[1].comp[1]:1 */
    P3_0_LPCOMP0_COMP1              = 15,       /* Digital Deep Sleep - lpcomp[0].comp[1]:1 */

    /* P4.0 */
    P4_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_0_MSC0_SENSE                 =  4,       /* msc[0].sense:39 */
    P4_0_MSC0_SHIELD                =  5,       /* msc[0].shield:39 */
    P4_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_0_CXPI_CXPI_RX0              =  8,       /* Digital Active - cxpi.cxpi_rx[0]:0 */
    P4_0_SCB0_UART_RX               = 10,       /* Digital Active - scb[0].uart_rx:1 */
    P4_0_TCPWM_LINE4                = 11,       /* Digital Active - tcpwm.line[4]:2 */

    /* P4.1 */
    P4_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_1_MSC0_SENSE                 =  4,       /* msc[0].sense:38 */
    P4_1_MSC0_SHIELD                =  5,       /* msc[0].shield:38 */
    P4_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_1_CXPI_CXPI_TX0              =  8,       /* Digital Active - cxpi.cxpi_tx[0]:0 */
    P4_1_SCB0_UART_TX               = 10,       /* Digital Active - scb[0].uart_tx:1 */
    P4_1_TCPWM_LINE_COMPL4          = 11,       /* Digital Active - tcpwm.line_compl[4]:2 */

    /* P4.2 */
    P4_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_2_MSC0_SENSE                 =  4,       /* msc[0].sense:37 */
    P4_2_MSC0_SHIELD                =  5,       /* msc[0].shield:37 */
    P4_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_2_CXPI_CXPI_EN0              =  8,       /* Digital Active - cxpi.cxpi_en[0]:0 */
    P4_2_SCB0_UART_RTS              = 10,       /* Digital Active - scb[0].uart_rts:1 */
    P4_2_TCPWM_LINE0                = 11,       /* Digital Active - tcpwm.line[0]:1 */

    /* P5.0 */
    P5_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_0_MSC0_SENSE                 =  4,       /* msc[0].sense:2 */
    P5_0_MSC0_SHIELD                =  5,       /* msc[0].shield:2 */
    P5_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_0_CXPI_CXPI_TX0              =  8,       /* Digital Active - cxpi.cxpi_tx[0]:1 */
    P5_0_LIN_LIN_TX0                =  9,       /* Digital Active - lin.lin_tx[0]:1 */
    P5_0_SCB1_UART_TX               = 10,       /* Digital Active - scb[1].uart_tx:1 */
    P5_0_TCPWM_LINE_COMPL0          = 11,       /* Digital Active - tcpwm.line_compl[0]:2 */
    P5_0_SCB1_SPI_MISO              = 12,       /* Digital Deep Sleep - scb[1].spi_miso:0 */
    P5_0_LPCOMP1_COMP0              = 13,       /* Digital Deep Sleep - lpcomp[1].comp[0]:0 */
    P5_0_SCB1_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[1].i2c_sda:1 */
    P5_0_LPCOMP0_COMP0              = 15,       /* Digital Deep Sleep - lpcomp[0].comp[0]:0 */

    /* P5.1 */
    P5_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P5_1_MSC0_SENSE                 =  4,       /* msc[0].sense:3 */
    P5_1_MSC0_SHIELD                =  5,       /* msc[0].shield:3 */
    P5_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P5_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P5_1_CXPI_CXPI_RX0              =  8,       /* Digital Active - cxpi.cxpi_rx[0]:1 */
    P5_1_LIN_LIN_RX0                =  9,       /* Digital Active - lin.lin_rx[0]:1 */
    P5_1_SCB1_UART_RX               = 10,       /* Digital Active - scb[1].uart_rx:1 */
    P5_1_TCPWM_LINE0                = 11,       /* Digital Active - tcpwm.line[0]:2 */
    P5_1_SCB1_SPI_MOSI              = 12,       /* Digital Deep Sleep - scb[1].spi_mosi:0 */
    P5_1_LPCOMP1_COMP1              = 13,       /* Digital Deep Sleep - lpcomp[1].comp[1]:0 */
    P5_1_SCB1_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[1].i2c_scl:1 */
    P5_1_LPCOMP0_COMP1              = 15,       /* Digital Deep Sleep - lpcomp[0].comp[1]:0 */

    /* P7.0 */
    P7_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_0_MSC0_SENSE                 =  4,       /* msc[0].sense:0 */
    P7_0_MSC0_SHIELD                =  5,       /* msc[0].shield:0 */
    P7_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_0_AMUXB                      =  7,       /* AMUXBUS B connection. */

    /* P7.1 */
    P7_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P7_1_MSC0_SENSE                 =  4,       /* msc[0].sense:1 */
    P7_1_MSC0_SHIELD                =  5,       /* msc[0].shield:1 */
    P7_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P7_1_AMUXB                      =  7        /* AMUXBUS B connection. */
} en_hsiom_sel_t;

#endif /* _GPIO_PSOC4HVMS64K_32_QFN_H_ */


/* [] END OF FILE */
