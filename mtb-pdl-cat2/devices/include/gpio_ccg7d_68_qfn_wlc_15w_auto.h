/***************************************************************************//**
* \file gpio_ccg7d_68_qfn_wlc_15w_auto.h
*
* \brief
* CCG7D device GPIO header for 68-QFN_WLC_15W_Auto package
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

#ifndef _GPIO_CCG7D_68_QFN_WLC_15W_AUTO_H_
#define _GPIO_CCG7D_68_QFN_WLC_15W_AUTO_H_

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
#define CY_GPIO_PIN_COUNT               68u

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

/* PORT 1 (GPIO) */
#define P1_0_PORT                       GPIO_PRT1
#define P1_0_PIN                        0u
#define P1_0_NUM                        0u
#define P1_0_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P1_1_PORT                       GPIO_PRT1
#define P1_1_PIN                        1u
#define P1_1_NUM                        1u
#define P1_1_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P1_2_PORT                       GPIO_PRT1
#define P1_2_PIN                        2u
#define P1_2_NUM                        2u
#define P1_2_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P1_3_PORT                       GPIO_PRT1
#define P1_3_PIN                        3u
#define P1_3_NUM                        3u
#define P1_3_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P1_4_PORT                       GPIO_PRT1
#define P1_4_PIN                        4u
#define P1_4_NUM                        4u
#define P1_4_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P1_5_PORT                       GPIO_PRT1
#define P1_5_PIN                        5u
#define P1_5_NUM                        5u
#define P1_5_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P1_6_PORT                       GPIO_PRT1
#define P1_6_PIN                        6u
#define P1_6_NUM                        6u
#define P1_6_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* PORT 2 (GPIO_OVT) */
#define P2_0_PORT                       GPIO_PRT2
#define P2_0_PIN                        0u
#define P2_0_NUM                        0u
#define P2_0_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P2_1_PORT                       GPIO_PRT2
#define P2_1_PIN                        1u
#define P2_1_NUM                        1u
#define P2_1_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* PORT 3 (GPIO) */
#define P3_0_PORT                       GPIO_PRT3
#define P3_0_PIN                        0u
#define P3_0_NUM                        0u
#define P3_0_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P3_1_PORT                       GPIO_PRT3
#define P3_1_PIN                        1u
#define P3_1_NUM                        1u
#define P3_1_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P3_2_PORT                       GPIO_PRT3
#define P3_2_PIN                        2u
#define P3_2_NUM                        2u
#define P3_2_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P3_3_PORT                       GPIO_PRT3
#define P3_3_PIN                        3u
#define P3_3_NUM                        3u
#define P3_3_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P3_4_PORT                       GPIO_PRT3
#define P3_4_PIN                        4u
#define P3_4_NUM                        4u
#define P3_4_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* Analog Connections */
#define USBPD0_PAD_BAT2GND_PULLDN_PORT  0u
#define USBPD0_PAD_BAT2GND_PULLDN_PIN   2u
#define USBPD0_PAD_LSCSA_INP0_PORT      0u
#define USBPD0_PAD_LSCSA_INP0_PIN       1u
#define USBPD0_PAD_LSCSA_VGND0_PORT     0u
#define USBPD0_PAD_LSCSA_VGND0_PIN      0u
#define USBPD0_USBPHY_DM_BCH_DET0_PORT  1u
#define USBPD0_USBPHY_DM_BCH_DET0_PIN   1u
#define USBPD0_USBPHY_DP_BCH_DET0_PORT  1u
#define USBPD0_USBPHY_DP_BCH_DET0_PIN   0u
#define USBPD1_PAD_BAT2GND_PULLDN_PORT  1u
#define USBPD1_PAD_BAT2GND_PULLDN_PIN   4u
#define USBPD1_PAD_LSCSA_INP0_PORT      1u
#define USBPD1_PAD_LSCSA_INP0_PIN       5u
#define USBPD1_PAD_LSCSA_VGND0_PORT     1u
#define USBPD1_PAD_LSCSA_VGND0_PIN      6u
#define USBPD1_USBPHY_DM_BCH_DET0_PORT  1u
#define USBPD1_USBPHY_DM_BCH_DET0_PIN   2u
#define USBPD1_USBPHY_DP_BCH_DET0_PORT  1u
#define USBPD1_USBPHY_DP_BCH_DET0_PIN   3u

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
    P0_0_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1]:0 */
    P0_0_TCPWM_TR_COMPARE_MATCH1    =  9,       /* Digital Active - tcpwm.tr_compare_match[1]:0 */
    P0_0_SCB1_UART_CTS              = 10,       /* Digital Active - scb[1].uart_cts:0 */
    P0_0_TCPWM_TR_OVERFLOW1         = 11,       /* Digital Active - tcpwm.tr_overflow[1]:0 */
    P0_0_USBPD0_HPD                 = 13,       /* Digital Deep Sleep - usbpd[0].hpd:1 */
    P0_0_SCB1_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[1].spi_select0:0 */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_1_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:0 */
    P0_1_TCPWM_TR_COMPARE_MATCH0    =  9,       /* Digital Active - tcpwm.tr_compare_match[0]:0 */
    P0_1_SCB2_UART_RTS              = 10,       /* Digital Active - scb[2].uart_rts:0 */
    P0_1_TCPWM_TR_OVERFLOW0         = 11,       /* Digital Active - tcpwm.tr_overflow[0]:0 */
    P0_1_USBPD0_GPIO_DDFT0          = 12,       /* Digital Deep Sleep - usbpd[0].gpio_ddft0 */
    P0_1_USBPD1_HPD                 = 13,       /* Digital Deep Sleep - usbpd[1].hpd:1 */
    P0_1_SCB2_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[2].spi_miso:0 */
    P0_1_USBPD1_AFC_TX_DATA_EN      = 15,       /* Digital Deep Sleep - usbpd[1].afc_tx_data_en */

    /* P0.2 */
    P0_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_2_SRSS_EXT_CLK               =  8,       /* Digital Active - srss.ext_clk:0 */
    P0_2_USBPD1_EXT_SET_BUCK        =  9,       /* Digital Active - usbpd[1].ext_set_buck */
    P0_2_SCB2_UART_CTS              = 10,       /* Digital Active - scb[2].uart_cts:0 */
    P0_2_USBPD0_EXT_SET_BUCK        = 11,       /* Digital Active - usbpd[0].ext_set_buck */
    P0_2_USBPD0_FAULT_GPIO0         = 12,       /* Digital Deep Sleep - usbpd[0].fault_gpio0 */
    P0_2_USBPD0_ADC_CMP_OUT_GPIO0   = 13,       /* Digital Deep Sleep - usbpd[0].adc_cmp_out_gpio[0] */
    P0_2_SCB2_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[2].spi_mosi:0 */
    P0_2_USBPD1_AFC_TX_DATA0        = 15,       /* Digital Deep Sleep - usbpd[1].afc_tx_data[0] */

    /* P0.3 */
    P0_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_3_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:2 */
    P0_3_USBPD1_EXT_SET_BOOST       =  9,       /* Digital Active - usbpd[1].ext_set_boost */
    P0_3_SCB2_UART_RX               = 10,       /* Digital Active - scb[2].uart_rx:0 */
    P0_3_USBPD0_EXT_SET_BOOST       = 11,       /* Digital Active - usbpd[0].ext_set_boost */
    P0_3_USBPD0_GPIO_DDFT1          = 12,       /* Digital Deep Sleep - usbpd[0].gpio_ddft1 */
    P0_3_USBPD0_ADC_CMP_OUT_GPIO1   = 13,       /* Digital Deep Sleep - usbpd[0].adc_cmp_out_gpio[1] */
    P0_3_SCB2_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[2].spi_clk:0 */
    P0_3_SCB2_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[2].i2c_scl:0 */

    /* P0.4 */
    P0_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_4_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1]:2 */
    P0_4_USBPD1_EXT_RST_SW1         =  9,       /* Digital Active - usbpd[1].ext_rst_sw1 */
    P0_4_SCB2_UART_TX               = 10,       /* Digital Active - scb[2].uart_tx:0 */
    P0_4_USBPD0_EXT_RST_SW1         = 11,       /* Digital Active - usbpd[0].ext_rst_sw1 */
    P0_4_USBPD1_GPIO_DDFT1          = 12,       /* Digital Deep Sleep - usbpd[1].gpio_ddft1 */
    P0_4_USBPD1_ADC_CMP_OUT_GPIO0   = 13,       /* Digital Deep Sleep - usbpd[1].adc_cmp_out_gpio[0] */
    P0_4_SCB2_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[2].spi_select0:0 */
    P0_4_SCB2_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[2].i2c_sda:0 */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_0_TCPWM_LINE2                =  8,       /* Digital Active - tcpwm.line[2]:2 */
    P1_0_USBPD1_EXT_HSRCP           =  9,       /* Digital Active - usbpd[1].ext_hsrcp */
    P1_0_SCB0_UART_CTS              = 10,       /* Digital Active - scb[0].uart_cts:0 */
    P1_0_USBPD0_EXT_HSRCP           = 11,       /* Digital Active - usbpd[0].ext_hsrcp */
    P1_0_USBPD0_EXT_HS1             = 13,       /* Digital Deep Sleep - usbpd[0].ext_hs1 */
    P1_0_SCB0_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[0].spi_mosi:0 */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_1_TCPWM_LINE3                =  8,       /* Digital Active - tcpwm.line[3]:2 */
    P1_1_USBPD1_EXT_PWM_OUT         =  9,       /* Digital Active - usbpd[1].ext_pwm_out */
    P1_1_SCB0_UART_RTS              = 10,       /* Digital Active - scb[0].uart_rts:0 */
    P1_1_USBPD0_EXT_PWM_OUT         = 11,       /* Digital Active - usbpd[0].ext_pwm_out */
    P1_1_USBPD0_EXT_LS1             = 13,       /* Digital Deep Sleep - usbpd[0].ext_ls1 */
    P1_1_SCB0_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[0].spi_select0:0 */

    /* P1.2 */
    P1_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_2_USBPD0_SWAPT_IN            = 12,       /* Digital Deep Sleep - usbpd[0].swapt_in */
    P1_2_USBPD0_EXT_HS2             = 13,       /* Digital Deep Sleep - usbpd[0].ext_hs2 */
    P1_2_USBPD1_FAULT_GPIO1         = 14,       /* Digital Deep Sleep - usbpd[1].fault_gpio1 */

    /* P1.3 */
    P1_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_3_USBPD1_SWAPT_IN            = 12,       /* Digital Deep Sleep - usbpd[1].swapt_in */
    P1_3_USBPD0_EXT_LS2             = 13,       /* Digital Deep Sleep - usbpd[0].ext_ls2 */
    P1_3_USBPD0_FAULT_GPIO1         = 14,       /* Digital Deep Sleep - usbpd[0].fault_gpio1 */

    /* P1.4 */
    P1_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_4_TCPWM_LINE2                =  8,       /* Digital Active - tcpwm.line[2]:0 */
    P1_4_USBPD1_EXT_LSZCD           =  9,       /* Digital Active - usbpd[1].ext_lszcd */
    P1_4_SCB1_UART_TX               = 10,       /* Digital Active - scb[1].uart_tx:0 */
    P1_4_USBPD0_EXT_LSZCD           = 11,       /* Digital Active - usbpd[0].ext_lszcd */
    P1_4_USBPD1_FAULT_GPIO0         = 12,       /* Digital Deep Sleep - usbpd[1].fault_gpio0 */
    P1_4_SCB1_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[1].spi_mosi:0 */
    P1_4_SCB1_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[1].i2c_sda:0 */

    /* P1.5 */
    P1_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_5_TCPWM_LINE3                =  8,       /* Digital Active - tcpwm.line[3]:0 */
    P1_5_TCPWM_TR_COMPARE_MATCH3    =  9,       /* Digital Active - tcpwm.tr_compare_match[3]:0 */
    P1_5_SCB1_UART_RX               = 10,       /* Digital Active - scb[1].uart_rx:0 */
    P1_5_TCPWM_TR_OVERFLOW3         = 11,       /* Digital Active - tcpwm.tr_overflow[3]:0 */
    P1_5_USBPD1_GPIO_DDFT0          = 12,       /* Digital Deep Sleep - usbpd[1].gpio_ddft0 */
    P1_5_USBPD0_HPD                 = 13,       /* Digital Deep Sleep - usbpd[0].hpd:0 */
    P1_5_SCB1_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[1].spi_clk:0 */
    P1_5_SCB1_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[1].i2c_scl:0 */

    /* P1.6 */
    P1_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_6_TCPWM_TR_COMPARE_MATCH2    =  9,       /* Digital Active - tcpwm.tr_compare_match[2]:0 */
    P1_6_SCB1_UART_RTS              = 10,       /* Digital Active - scb[1].uart_rts:0 */
    P1_6_TCPWM_TR_OVERFLOW2         = 11,       /* Digital Active - tcpwm.tr_overflow[2]:0 */
    P1_6_USBPD1_HPD                 = 13,       /* Digital Deep Sleep - usbpd[1].hpd:0 */
    P1_6_SCB1_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[1].spi_miso:0 */

    /* P2.0 */
    P2_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_0_USBPD1_EXT_SCAP_RST        =  9,       /* Digital Active - usbpd[1].ext_scap_rst */
    P2_0_SCB0_UART_TX               = 10,       /* Digital Active - scb[0].uart_tx:0 */
    P2_0_USBPD0_EXT_SCAP_RST        = 11,       /* Digital Active - usbpd[0].ext_scap_rst */
    P2_0_USBPD1_TX_DATA_EN          = 12,       /* Digital Deep Sleep - usbpd[1].tx_data_en */
    P2_0_USBPD0_AFC_TX_DATA_EN      = 13,       /* Digital Deep Sleep - usbpd[0].afc_tx_data_en */
    P2_0_SCB0_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[0].spi_miso:0 */
    P2_0_SCB0_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */

    /* P2.1 */
    P2_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_1_USBPD1_EXT_SCOMP_OUT_EN    =  9,       /* Digital Active - usbpd[1].ext_scomp_out_en */
    P2_1_SCB0_UART_RX               = 10,       /* Digital Active - scb[0].uart_rx:0 */
    P2_1_USBPD0_EXT_SCOMP_OUT_EN    = 11,       /* Digital Active - usbpd[0].ext_scomp_out_en */
    P2_1_USBPD1_TX_DATA             = 12,       /* Digital Deep Sleep - usbpd[1].tx_data */
    P2_1_USBPD0_AFC_TX_DATA0        = 13,       /* Digital Deep Sleep - usbpd[0].afc_tx_data[0] */
    P2_1_SCB0_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[0].spi_clk:0 */
    P2_1_SCB0_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */

    /* P3.0 */
    P3_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_0_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:1 */
    P3_0_TCPWM_TR_COMPARE_MATCH0    =  9,       /* Digital Active - tcpwm.tr_compare_match[0]:1 */
    P3_0_SCB3_UART_TX               = 10,       /* Digital Active - scb[3].uart_tx:0 */
    P3_0_TCPWM_TR_OVERFLOW0         = 11,       /* Digital Active - tcpwm.tr_overflow[0]:1 */
    P3_0_CPUSS_SWD_DATA             = 12,       /* Digital Deep Sleep - cpuss.swd_data:0 */
    P3_0_USBPD1_EXT_HS1             = 13,       /* Digital Deep Sleep - usbpd[1].ext_hs1 */
    P3_0_SCB3_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[3].spi_miso:0 */
    P3_0_SCB3_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[3].i2c_sda:0 */

    /* P3.1 */
    P3_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_1_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1]:1 */
    P3_1_TCPWM_TR_COMPARE_MATCH1    =  9,       /* Digital Active - tcpwm.tr_compare_match[1]:1 */
    P3_1_SCB3_UART_RX               = 10,       /* Digital Active - scb[3].uart_rx:0 */
    P3_1_TCPWM_TR_OVERFLOW1         = 11,       /* Digital Active - tcpwm.tr_overflow[1]:1 */
    P3_1_CPUSS_SWD_CLK              = 12,       /* Digital Deep Sleep - cpuss.swd_clk:0 */
    P3_1_USBPD1_EXT_LS1             = 13,       /* Digital Deep Sleep - usbpd[1].ext_ls1 */
    P3_1_SCB3_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[3].spi_clk:0 */
    P3_1_SCB3_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[3].i2c_scl:0 */

    /* P3.2 */
    P3_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_2_TCPWM_LINE2                =  8,       /* Digital Active - tcpwm.line[2]:1 */
    P3_2_TCPWM_TR_COMPARE_MATCH2    =  9,       /* Digital Active - tcpwm.tr_compare_match[2]:1 */
    P3_2_SCB3_UART_CTS              = 10,       /* Digital Active - scb[3].uart_cts:0 */
    P3_2_TCPWM_TR_OVERFLOW2         = 11,       /* Digital Active - tcpwm.tr_overflow[2]:1 */
    P3_2_USBPD0_TX_DATA_EN          = 12,       /* Digital Deep Sleep - usbpd[0].tx_data_en */
    P3_2_USBPD1_EXT_HS2             = 13,       /* Digital Deep Sleep - usbpd[1].ext_hs2 */
    P3_2_SCB3_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[3].spi_mosi:0 */

    /* P3.3 */
    P3_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_3_TCPWM_LINE3                =  8,       /* Digital Active - tcpwm.line[3]:1 */
    P3_3_TCPWM_TR_COMPARE_MATCH3    =  9,       /* Digital Active - tcpwm.tr_compare_match[3]:1 */
    P3_3_SCB3_UART_RTS              = 10,       /* Digital Active - scb[3].uart_rts:0 */
    P3_3_TCPWM_TR_OVERFLOW3         = 11,       /* Digital Active - tcpwm.tr_overflow[3]:1 */
    P3_3_USBPD0_TX_DATA             = 12,       /* Digital Deep Sleep - usbpd[0].tx_data */
    P3_3_USBPD1_EXT_LS2             = 13,       /* Digital Deep Sleep - usbpd[1].ext_ls2 */
    P3_3_SCB3_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[3].spi_select0:0 */

    /* P3.4 */
    P3_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_4_SRSS_EXT_CLK               =  8        /* Digital Active - srss.ext_clk:1 */
} en_hsiom_sel_t;

#endif /* _GPIO_CCG7D_68_QFN_WLC_15W_AUTO_H_ */


/* [] END OF FILE */
