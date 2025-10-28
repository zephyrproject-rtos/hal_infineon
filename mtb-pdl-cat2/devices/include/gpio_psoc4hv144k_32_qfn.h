/***************************************************************************//**
* \file gpio_psoc4hv144k_32_qfn.h
*
* \brief
* PSOC4HV144K device GPIO header for 32-QFN package
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

#ifndef _GPIO_PSOC4HV144K_32_QFN_H_
#define _GPIO_PSOC4HV144K_32_QFN_H_

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
#define P0_6_0_PORT                     GPIO_PRT0
#define P0_6_0_PIN                      6u
#define P0_6_0_NUM                      6u
#define P0_6_0_AMUXSEGMENT              AMUXBUS_AMUXBUS_A
#define P0_6_PORT                       GPIO_PRT0
#define P0_6_PIN                        6u
#define P0_6_NUM                        6u
#define P0_6_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P0_7_0_PORT                     GPIO_PRT0
#define P0_7_0_PIN                      7u
#define P0_7_0_NUM                      7u
#define P0_7_0_AMUXSEGMENT              AMUXBUS_AMUXBUS_A
#define P0_7_PORT                       GPIO_PRT0
#define P0_7_PIN                        7u
#define P0_7_NUM                        7u
#define P0_7_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* PORT 1 (GPIO) */
#define P1_0_0_PORT                     GPIO_PRT1
#define P1_0_0_PIN                      0u
#define P1_0_0_NUM                      0u
#define P1_0_0_AMUXSEGMENT              AMUXBUS_AMUXBUS_A
#define P1_0_PORT                       GPIO_PRT1
#define P1_0_PIN                        0u
#define P1_0_NUM                        0u
#define P1_0_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P1_1_0_PORT                     GPIO_PRT1
#define P1_1_0_PIN                      1u
#define P1_1_0_NUM                      1u
#define P1_1_0_AMUXSEGMENT              AMUXBUS_AMUXBUS_A
#define P1_1_PORT                       GPIO_PRT1
#define P1_1_PIN                        1u
#define P1_1_NUM                        1u
#define P1_1_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P1_2_0_PORT                     GPIO_PRT1
#define P1_2_0_PIN                      2u
#define P1_2_0_NUM                      2u
#define P1_2_0_AMUXSEGMENT              AMUXBUS_AMUXBUS_A
#define P1_2_PORT                       GPIO_PRT1
#define P1_2_PIN                        2u
#define P1_2_NUM                        2u
#define P1_2_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* Analog Connections */
#define PACSS_ANALOGSHORT0_PORT         1u
#define PACSS_ANALOGSHORT0_PIN          0u
#define PACSS_ANALOGSHORT1_PORT         1u
#define PACSS_ANALOGSHORT1_PIN          1u
#define PACSS_ANALOGSHORT2_PORT         1u
#define PACSS_ANALOGSHORT2_PIN          2u
#define PACSS_ANALOGSHORT3_PORT         0u
#define PACSS_ANALOGSHORT3_PIN          7u
#define PACSS_ANALOGSHORT4_PORT         0u
#define PACSS_ANALOGSHORT4_PIN          6u
#define PACSS_MUX_PADS0_PORT            0u
#define PACSS_MUX_PADS0_PIN             0u
#define PACSS_MUX_PADS1_PORT            0u
#define PACSS_MUX_PADS1_PIN             1u
#define PACSS_MUX_PADS2_PORT            0u
#define PACSS_MUX_PADS2_PIN             2u
#define PACSS_MUX_PADS3_PORT            0u
#define PACSS_MUX_PADS3_PIN             3u
#define PACSS_MUX_PADS4_PORT            0u
#define PACSS_MUX_PADS4_PIN             4u
#define PACSS_MUX_PADS5_PORT            0u
#define PACSS_MUX_PADS5_PIN             5u
#define PACSS_MUX_PADS6_PORT            0u
#define PACSS_MUX_PADS6_PIN             6u
#define PACSS_MUX_PADS7_PORT            0u
#define PACSS_MUX_PADS7_PIN             7u
#define PACSS_VTEMP_PORT                1u
#define PACSS_VTEMP_PIN                 1u
#define PACSS_VTEMP_RET_PORT            1u
#define PACSS_VTEMP_RET_PIN             2u
#define PACSS_VTEMP_RET_K_PORT          1u
#define PACSS_VTEMP_RET_K_PIN           2u
#define PACSS_VTEMP_SUP_PORT            1u
#define PACSS_VTEMP_SUP_PIN             0u
#define SRSS_ADFT_POR_PAD_HV_PORT       0u
#define SRSS_ADFT_POR_PAD_HV_PIN        4u

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
    P0_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_0_TCPWM_TR_IN0               =  8,       /* Digital Active - tcpwm.tr_in[0] */
    P0_0_LIN_LIN_RX0                =  9,       /* Digital Active - lin.lin_rx[0]:0 */
    P0_0_SCB0_UART_RX               = 10,       /* Digital Active - scb[0].uart_rx:1 */
    P0_0_TCPWM_LINE0                = 11,       /* Digital Active - tcpwm.line[0]:0 */
    P0_0_SCB0_SPI_CLK               = 12,       /* Digital Deep Sleep - scb[0].spi_clk:0 */
    P0_0_SCB0_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[0].i2c_scl */
    P0_0_PACSS_DBG_IO0              = 15,       /* Digital Deep Sleep - pacss.dbg_io[0] */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_1_TCPWM_TR_IN1               =  8,       /* Digital Active - tcpwm.tr_in[1] */
    P0_1_LIN_LIN_TX0                =  9,       /* Digital Active - lin.lin_tx[0]:0 */
    P0_1_SCB0_UART_TX               = 10,       /* Digital Active - scb[0].uart_tx:1 */
    P0_1_TCPWM_LINE_COMPL0          = 11,       /* Digital Active - tcpwm.line_compl[0]:0 */
    P0_1_SCB0_SPI_MOSI              = 12,       /* Digital Deep Sleep - scb[0].spi_mosi:0 */
    P0_1_SCB0_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[0].i2c_sda */
    P0_1_PACSS_DBG_IO1              = 15,       /* Digital Deep Sleep - pacss.dbg_io[1] */

    /* P0.2 */
    P0_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_2_TCPWM_TR_IN2               =  8,       /* Digital Active - tcpwm.tr_in[2] */
    P0_2_LIN_LIN_EN0                =  9,       /* Digital Active - lin.lin_en[0]:0 */
    P0_2_TCPWM_LINE1                = 11,       /* Digital Active - tcpwm.line[1]:0 */
    P0_2_SCB0_SPI_MISO              = 12,       /* Digital Deep Sleep - scb[0].spi_miso:0 */
    P0_2_PACSS_DBG_IO2              = 15,       /* Digital Deep Sleep - pacss.dbg_io[2] */

    /* P0.3 */
    P0_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_3_TCPWM_TR_IN3               =  8,       /* Digital Active - tcpwm.tr_in[3] */
    P0_3_TCPWM_LINE_COMPL1          = 11,       /* Digital Active - tcpwm.line_compl[1]:0 */
    P0_3_SCB0_SPI_SELECT0           = 12,       /* Digital Deep Sleep - scb[0].spi_select0 */
    P0_3_PACSS_DBG_IO3              = 15,       /* Digital Deep Sleep - pacss.dbg_io[3] */

    /* P0.4 */
    P0_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_4_PERI_VIRT_IN_0             =  8,       /* Digital Active - peri.virt_in_0 */
    P0_4_TCPWM_LINE2                = 11,       /* Digital Active - tcpwm.line[2]:0 */
    P0_4_SCB0_SPI_SELECT1           = 12,       /* Digital Deep Sleep - scb[0].spi_select1 */
    P0_4_CPUSS_FAULT_OUT0           = 14,       /* Digital Deep Sleep - cpuss.fault_out[0] */
    P0_4_PACSS_DBG_IO4              = 15,       /* Digital Deep Sleep - pacss.dbg_io[4] */

    /* P0.5 */
    P0_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_5_SRSS_EXT_CLK               =  8,       /* Digital Active - srss.ext_clk */
    P0_5_TCPWM_LINE_COMPL2          = 11,       /* Digital Active - tcpwm.line_compl[2]:0 */
    P0_5_SCB0_SPI_SELECT2           = 12,       /* Digital Deep Sleep - scb[0].spi_select2 */
    P0_5_CPUSS_FAULT_OUT1           = 14,       /* Digital Deep Sleep - cpuss.fault_out[1] */
    P0_5_PACSS_DBG_IO5              = 15,       /* Digital Deep Sleep - pacss.dbg_io[5] */

    /* P0.6:0 */
    P0_6_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_6_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_6_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_6_PERI_VIRT_IN_1             =  8,       /* Digital Active - peri.virt_in_1 */
    P0_6_SCB0_SPI_SELECT3           = 12,       /* Digital Deep Sleep - scb[0].spi_select3 */
    P0_6_CPUSS_SWD_DATA             = 14,       /* Digital Deep Sleep - cpuss.swd_data */

    /* P0.7:0 */
    P0_7_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_7_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_7_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_7_PERI_VIRT_IN_2             =  8,       /* Digital Active - peri.virt_in_2 */
    P0_7_CPUSS_SWD_CLK              = 14,       /* Digital Deep Sleep - cpuss.swd_clk */

    /* P1.0:0 */
    P1_0_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_0_HVSS_LIN_ALT_RXD           =  9,       /* Digital Active - hvss.lin_alt_rxd */
    P1_0_TCPWM_LINE3                = 11,       /* Digital Active - tcpwm.line[3]:0 */

    /* P1.1:0 */
    P1_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_1_HVSS_LIN_ALT_TXD           =  9,       /* Digital Active - hvss.lin_alt_txd */

    /* P1.2:0 */
    P1_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P1_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P1_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P1_2_PERI_VIRT_IN_3             =  8,       /* Digital Active - peri.virt_in_3 */
    P1_2_HVSS_LIN_ALT_EN            =  9,       /* Digital Active - hvss.lin_alt_en */
    P1_2_TCPWM_LINE_COMPL3          = 11        /* Digital Active - tcpwm.line_compl[3]:0 */
} en_hsiom_sel_t;

#endif /* _GPIO_PSOC4HV144K_32_QFN_H_ */


/* [] END OF FILE */
