/***************************************************************************//**
* \file gpio_pmg1s0_24_qfn_pmg1_s0.h
*
* \brief
* PMG1S0 device GPIO header for 24-QFN-PMG1-S0 package
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

#ifndef _GPIO_PMG1S0_24_QFN_PMG1_S0_H_
#define _GPIO_PMG1S0_24_QFN_PMG1_S0_H_

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
#define CY_GPIO_PIN_COUNT               24u

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
/* PORT 0 (GPIO_OVT) */
#define P0_0_PORT                       GPIO_PRT0
#define P0_0_PIN                        0u
#define P0_0_NUM                        0u
#define P0_0_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P0_1_PORT                       GPIO_PRT0
#define P0_1_PIN                        1u
#define P0_1_NUM                        1u
#define P0_1_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

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

/* PORT 2 (GPIO) */
#define P2_0_PORT                       GPIO_PRT2
#define P2_0_PIN                        0u
#define P2_0_NUM                        0u
#define P2_0_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P2_1_PORT                       GPIO_PRT2
#define P2_1_PIN                        1u
#define P2_1_NUM                        1u
#define P2_1_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P2_2_PORT                       GPIO_PRT2
#define P2_2_PIN                        2u
#define P2_2_NUM                        2u
#define P2_2_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P2_3_PORT                       GPIO_PRT2
#define P2_3_PIN                        3u
#define P2_3_NUM                        3u
#define P2_3_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* PORT 3 (GPIO) */
#define P3_0_PORT                       GPIO_PRT3
#define P3_0_PIN                        0u
#define P3_0_NUM                        0u
#define P3_0_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P3_1_PORT                       GPIO_PRT3
#define P3_1_PIN                        1u
#define P3_1_NUM                        1u
#define P3_1_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* Analog Connections */
#define USBPD0_SBU_IO0_PORT             2u
#define USBPD0_SBU_IO0_PIN              2u
#define USBPD0_SBU_IO1_PORT             2u
#define USBPD0_SBU_IO1_PIN              3u
#define USBPD0_USBPHY_DM_BCH_DET0_PORT  3u
#define USBPD0_USBPHY_DM_BCH_DET0_PIN   1u
#define USBPD0_USBPHY_DM_BCH_DET1_PORT  1u
#define USBPD0_USBPHY_DM_BCH_DET1_PIN   3u
#define USBPD0_USBPHY_DP_BCH_DET0_PORT  3u
#define USBPD0_USBPHY_DP_BCH_DET0_PIN   0u
#define USBPD0_USBPHY_DP_BCH_DET1_PORT  1u
#define USBPD0_USBPHY_DP_BCH_DET1_PIN   2u

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
    P0_0_TCPWM_TR_IN1               =  8,       /* Digital Active - tcpwm.tr_in[1] */
    P0_0_TCPWM_LINE0                =  9,       /* Digital Active - tcpwm.line[0]:0 */
    P0_0_TCPWM_TR_COMPARE_MATCH0    = 10,       /* Digital Active - tcpwm.tr_compare_match[0] */
    P0_0_SCB0_UART_CTS              = 11,       /* Digital Active - scb[0].uart_cts */
    P0_0_CPUSS_SWD_DATA             = 13,       /* Digital Deep Sleep - cpuss.swd_data:0 */
    P0_0_SCB1_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[1].spi_mosi */
    P0_0_SCB0_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[0].i2c_sda */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_1_TCPWM_TR_IN2               =  8,       /* Digital Active - tcpwm.tr_in[2] */
    P0_1_TCPWM_LINE1                =  9,       /* Digital Active - tcpwm.line[1]:0 */
    P0_1_TCPWM_TR_COMPARE_MATCH1    = 10,       /* Digital Active - tcpwm.tr_compare_match[1] */
    P0_1_SCB0_UART_RTS              = 11,       /* Digital Active - scb[0].uart_rts */
    P0_1_CPUSS_SWD_CLK              = 13,       /* Digital Deep Sleep - cpuss.swd_clk:0 */
    P0_1_SCB1_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[1].spi_miso */
    P0_1_SCB0_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[0].i2c_scl */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_0_TCPWM_LINE2                =  9,       /* Digital Active - tcpwm.line[2]:1 */
    P1_0_TCPWM_TR_OVERFLOW0         = 10,       /* Digital Active - tcpwm.tr_overflow[0] */
    P1_0_SCB1_UART_CTS              = 11,       /* Digital Active - scb[1].uart_cts */
    P1_0_USBPD0_ADC_CMP_OUT_GPIO1   = 12,       /* Digital Deep Sleep - usbpd[0].adc_cmp_out_gpio[1] */
    P1_0_USBPD0_FAULT_GPIO0         = 13,       /* Digital Deep Sleep - usbpd[0].fault_gpio0 */
    P1_0_SCB0_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[0].spi_select0 */
    P1_0_SCB1_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[1].i2c_sda:1 */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_1_TCPWM_TR_IN0               =  8,       /* Digital Active - tcpwm.tr_in[0] */
    P1_1_TCPWM_LINE3                =  9,       /* Digital Active - tcpwm.line[3]:1 */
    P1_1_TCPWM_TR_OVERFLOW1         = 10,       /* Digital Active - tcpwm.tr_overflow[1] */
    P1_1_SCB1_UART_RTS              = 11,       /* Digital Active - scb[1].uart_rts */
    P1_1_USBPD0_TX_DATA_EN          = 12,       /* Digital Deep Sleep - usbpd[0].tx_data_en */
    P1_1_USBPD0_FAULT_GPIO1         = 13,       /* Digital Deep Sleep - usbpd[0].fault_gpio1 */
    P1_1_SCB0_SPI_MISO              = 14,       /* Digital Deep Sleep - scb[0].spi_miso */
    P1_1_SCB1_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[1].i2c_scl:1 */

    /* P1.2 */
    P1_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_2_TCPWM_TR_OVERFLOW2         = 10,       /* Digital Active - tcpwm.tr_overflow[2] */
    P1_2_SCB1_UART_TX               = 11,       /* Digital Active - scb[1].uart_tx:1 */
    P1_2_USBPD0_ADC_CMP_OUT_GPIO0   = 12,       /* Digital Deep Sleep - usbpd[0].adc_cmp_out_gpio[0] */
    P1_2_USBPD0_HPD                 = 13,       /* Digital Deep Sleep - usbpd[0].hpd */
    P1_2_SCB0_SPI_MOSI              = 14,       /* Digital Deep Sleep - scb[0].spi_mosi */

    /* P1.3 */
    P1_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_3_TCPWM_TR_OVERFLOW3         = 10,       /* Digital Active - tcpwm.tr_overflow[3] */
    P1_3_SCB1_UART_RX               = 11,       /* Digital Active - scb[1].uart_rx:1 */
    P1_3_USBPD0_SWAPT_IN            = 12,       /* Digital Deep Sleep - usbpd[0].swapt_in */
    P1_3_USBPD0_GPIO_RX_FRS         = 13,       /* Digital Deep Sleep - usbpd[0].gpio_rx_frs */
    P1_3_SCB0_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[0].spi_clk */

    /* P2.0 */
    P2_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_0_TCPWM_TR_IN3               =  8,       /* Digital Active - tcpwm.tr_in[3] */
    P2_0_TCPWM_LINE2                =  9,       /* Digital Active - tcpwm.line[2]:0 */
    P2_0_TCPWM_TR_COMPARE_MATCH2    = 10,       /* Digital Active - tcpwm.tr_compare_match[2] */
    P2_0_SCB0_UART_TX               = 11,       /* Digital Active - scb[0].uart_tx:0 */
    P2_0_USBPD0_SWAPT_OUT0          = 12,       /* Digital Deep Sleep - usbpd[0].swapt_out[0] */
    P2_0_SCB1_SPI_SELECT0           = 14,       /* Digital Deep Sleep - scb[1].spi_select0 */

    /* P2.1 */
    P2_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_1_TCPWM_TR_IN4               =  8,       /* Digital Active - tcpwm.tr_in[4] */
    P2_1_TCPWM_LINE3                =  9,       /* Digital Active - tcpwm.line[3]:0 */
    P2_1_TCPWM_TR_COMPARE_MATCH3    = 10,       /* Digital Active - tcpwm.tr_compare_match[3] */
    P2_1_SCB0_UART_RX               = 11,       /* Digital Active - scb[0].uart_rx:0 */
    P2_1_USBPD0_SWAPT_OUT1          = 12,       /* Digital Deep Sleep - usbpd[0].swapt_out[1] */
    P2_1_SCB1_SPI_CLK               = 14,       /* Digital Deep Sleep - scb[1].spi_clk */

    /* P2.2 */
    P2_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_2_TCPWM_TR_IN5               =  8,       /* Digital Active - tcpwm.tr_in[5] */
    P2_2_TCPWM_LINE0                =  9,       /* Digital Active - tcpwm.line[0]:1 */
    P2_2_SCB0_UART_TX               = 11,       /* Digital Active - scb[0].uart_tx:1 */
    P2_2_USBPD0_GPIO_DDFT1          = 12,       /* Digital Deep Sleep - usbpd[0].gpio_ddft1 */
    P2_2_USBPD0_AFC_TX_DATA0        = 14,       /* Digital Deep Sleep - usbpd[0].afc_tx_data[0] */
    P2_2_SCB1_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[1].i2c_sda:0 */

    /* P2.3 */
    P2_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_3_TCPWM_TR_IN6               =  8,       /* Digital Active - tcpwm.tr_in[6] */
    P2_3_TCPWM_LINE1                =  9,       /* Digital Active - tcpwm.line[1]:1 */
    P2_3_SCB0_UART_RX               = 11,       /* Digital Active - scb[0].uart_rx:1 */
    P2_3_USBPD0_GPIO_DDFT0          = 12,       /* Digital Deep Sleep - usbpd[0].gpio_ddft0 */
    P2_3_USBPD0_AFC_TX_DATA1        = 14,       /* Digital Deep Sleep - usbpd[0].afc_tx_data[1] */
    P2_3_SCB1_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[1].i2c_scl:0 */

    /* P3.0 */
    P3_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_0_SRSS_EXT_CLK               =  9,       /* Digital Active - srss.ext_clk */
    P3_0_SCB1_UART_TX               = 11,       /* Digital Active - scb[1].uart_tx:0 */
    P3_0_USBPD0_TX_DATA             = 12,       /* Digital Deep Sleep - usbpd[0].tx_data */

    /* P3.1 */
    P3_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_1_SCB1_UART_RX               = 11,       /* Digital Active - scb[1].uart_rx:0 */
    P3_1_USBPD0_AFC_TX_DATA_EN      = 14        /* Digital Deep Sleep - usbpd[0].afc_tx_data_en */
} en_hsiom_sel_t;

#endif /* _GPIO_PMG1S0_24_QFN_PMG1_S0_H_ */


/* [] END OF FILE */
