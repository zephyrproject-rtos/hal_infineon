/***************************************************************************//**
* \file gpio_psoc4000t_16_qfn.h
*
* \brief
* PSOC4000T device GPIO header for 16-QFN package
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

#ifndef _GPIO_PSOC4000T_16_QFN_H_
#define _GPIO_PSOC4000T_16_QFN_H_

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
#define CY_GPIO_PIN_COUNT               16u

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
#define P0_4_PORT                       GPIO_PRT0
#define P0_4_PIN                        4u
#define P0_4_NUM                        4u
#define P0_4_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* PORT 2 (GPIO) */
#define P2_2_PORT                       GPIO_PRT2
#define P2_2_PIN                        2u
#define P2_2_NUM                        2u
#define P2_2_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P2_3_PORT                       GPIO_PRT2
#define P2_3_PIN                        3u
#define P2_3_NUM                        3u
#define P2_3_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P2_4_PORT                       GPIO_PRT2
#define P2_4_PIN                        4u
#define P2_4_NUM                        4u
#define P2_4_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P2_5_PORT                       GPIO_PRT2
#define P2_5_PIN                        5u
#define P2_5_NUM                        5u
#define P2_5_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* PORT 3 (GPIO) */
#define P3_2_PORT                       GPIO_PRT3
#define P3_2_PIN                        2u
#define P3_2_NUM                        2u
#define P3_2_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P3_3_PORT                       GPIO_PRT3
#define P3_3_PIN                        3u
#define P3_3_NUM                        3u
#define P3_3_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* PORT 4 (GPIO) */
#define P4_2_PORT                       GPIO_PRT4
#define P4_2_PIN                        2u
#define P4_2_NUM                        2u
#define P4_2_AMUXSEGMENT                AMUXBUS_AMUXBUS_A
#define P4_3_PORT                       GPIO_PRT4
#define P4_3_PIN                        3u
#define P4_3_NUM                        3u
#define P4_3_AMUXSEGMENT                AMUXBUS_AMUXBUS_A

/* MSC List */
#define P0_0_MSCLP_MSC_GPIO_CTRL_SNS    0u
#define P0_1_MSCLP_MSC_GPIO_CTRL_SNS    1u
#define P0_4_MSCLP_MSC_GPIO_CTRL_SNS    4u
#define P2_2_MSCLP_MSC_GPIO_CTRL_SNS    9u
#define P2_3_MSCLP_MSC_GPIO_CTRL_SNS    10u
#define P2_4_MSCLP_MSC_GPIO_CTRL_SNS    11u
#define P2_5_MSCLP_MSC_GPIO_CTRL_SNS    12u
#define P3_2_MSCLP_MSC_GPIO_CTRL_SNS    15u
#define P3_3_MSCLP_MSC_GPIO_CTRL_SNS    16u
#define P4_2_MSCLP_MSC_GPIO_CTRL_CMOD   1u
#define P4_3_MSCLP_MSC_GPIO_CTRL_CMOD   2u

/* Analog Connections */
#define MSCLP_CMOD1PADD_CCOMP_PORT      4u
#define MSCLP_CMOD1PADD_CCOMP_PIN       2u
#define MSCLP_CMOD1PADD_CREF_PORT       4u
#define MSCLP_CMOD1PADD_CREF_PIN        2u
#define MSCLP_CMOD1PADS_PORT            4u
#define MSCLP_CMOD1PADS_PIN             2u
#define MSCLP_CMOD2PADD_CCOMP_PORT      4u
#define MSCLP_CMOD2PADD_CCOMP_PIN       3u
#define MSCLP_CMOD2PADD_CREF_PORT       4u
#define MSCLP_CMOD2PADD_CREF_PIN        3u
#define MSCLP_CMOD2PADS_PORT            4u
#define MSCLP_CMOD2PADS_PIN             3u
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
    P0_0_MSCLP_SENSE                =  4,       /* msclp.sense:0 */
    P0_0_MSCLP_SHIELD               =  5,       /* msclp.shield:0 */
    P0_0_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_0_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_0_TCPWM_TR_IN0               = 11,       /* Digital Active - tcpwm.tr_in[0] */
    P0_0_MSCLP_MSC_DDRV0            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[0] */
    P0_0_MSCLP_EXT_SYNC             = 13,       /* Digital Deep Sleep - msclp.ext_sync:0 */
    P0_0_SCB0_SPI_SELECT1           = 15,       /* Digital Deep Sleep - scb[0].spi_select1:0 */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_1_MSCLP_SENSE                =  4,       /* msclp.sense:1 */
    P0_1_MSCLP_SHIELD               =  5,       /* msclp.shield:1 */
    P0_1_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_1_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_1_TCPWM_TR_IN1               = 11,       /* Digital Active - tcpwm.tr_in[1] */
    P0_1_MSCLP_MSC_DDRV1            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[1] */
    P0_1_MSCLP_EXT_SYNC_CLK         = 13,       /* Digital Deep Sleep - msclp.ext_sync_clk:0 */
    P0_1_SCB0_SPI_SELECT2           = 15,       /* Digital Deep Sleep - scb[0].spi_select2:0 */

    /* P0.4 */
    P0_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P0_4_MSCLP_SENSE                =  4,       /* msclp.sense:4 */
    P0_4_MSCLP_SHIELD               =  5,       /* msclp.shield:4 */
    P0_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P0_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P0_4_SRSS_EXT_CLK               =  8,       /* Digital Active - srss.ext_clk */
    P0_4_SCB0_UART_CTS              =  9,       /* Digital Active - scb[0].uart_cts:2 */
    P0_4_MSCLP_MSC_DDRV4            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[4] */
    P0_4_MSCLP_EXT_FRM_START        = 13,       /* Digital Deep Sleep - msclp.ext_frm_start:0 */
    P0_4_SCB0_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[0].spi_clk:0 */

    /* P2.2 */
    P2_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_2_MSCLP_SENSE                =  4,       /* msclp.sense:9 */
    P2_2_MSCLP_SHIELD               =  5,       /* msclp.shield:9 */
    P2_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_2_TCPWM_LINE0                =  8,       /* Digital Active - tcpwm.line[0]:1 */
    P2_2_SCB0_UART_RX               =  9,       /* Digital Active - scb[0].uart_rx:3 */
    P2_2_TCPWM_TR_IN4               = 11,       /* Digital Active - tcpwm.tr_in[4] */
    P2_2_MSCLP_MSC_DDRV9            = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[9] */
    P2_2_MSCLP_OBS_DATA1            = 13,       /* Digital Deep Sleep - msclp.obs_data[1] */
    P2_2_SCB1_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[1].i2c_scl:1 */
    P2_2_SCB0_SPI_MOSI              = 15,       /* Digital Deep Sleep - scb[0].spi_mosi:3 */

    /* P2.3 */
    P2_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_3_MSCLP_SENSE                =  4,       /* msclp.sense:10 */
    P2_3_MSCLP_SHIELD               =  5,       /* msclp.shield:10 */
    P2_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_3_TCPWM_LINE_COMPL0          =  8,       /* Digital Active - tcpwm.line_compl[0]:1 */
    P2_3_SCB0_UART_TX               =  9,       /* Digital Active - scb[0].uart_tx:3 */
    P2_3_TCPWM_TR_IN5               = 11,       /* Digital Active - tcpwm.tr_in[5] */
    P2_3_MSCLP_MSC_DDRV10           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[10] */
    P2_3_MSCLP_OBS_DATA0            = 13,       /* Digital Deep Sleep - msclp.obs_data[0] */
    P2_3_SCB1_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[1].i2c_sda:1 */
    P2_3_SCB0_SPI_MISO              = 15,       /* Digital Deep Sleep - scb[0].spi_miso:3 */

    /* P2.4 */
    P2_4_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_4_MSCLP_SENSE                =  4,       /* msclp.sense:11 */
    P2_4_MSCLP_SHIELD               =  5,       /* msclp.shield:11 */
    P2_4_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_4_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_4_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1]:1 */
    P2_4_SCB0_UART_CTS              =  9,       /* Digital Active - scb[0].uart_cts:3 */
    P2_4_MSCLP_MSC_DDRV11           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[11] */
    P2_4_MSCLP_EXT_SYNC             = 13,       /* Digital Deep Sleep - msclp.ext_sync:1 */
    P2_4_SCB0_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[0].spi_clk:3 */

    /* P2.5 */
    P2_5_GPIO                       =  0,       /* SW controlled GPIO. */
    P2_5_MSCLP_SENSE                =  4,       /* msclp.sense:12 */
    P2_5_MSCLP_SHIELD               =  5,       /* msclp.shield:12 */
    P2_5_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P2_5_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P2_5_TCPWM_LINE_COMPL1          =  8,       /* Digital Active - tcpwm.line_compl[1]:1 */
    P2_5_SCB0_UART_RTS              =  9,       /* Digital Active - scb[0].uart_rts:3 */
    P2_5_MSCLP_MSC_DDRV12           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[12] */
    P2_5_MSCLP_EXT_SYNC_CLK         = 13,       /* Digital Deep Sleep - msclp.ext_sync_clk:1 */
    P2_5_SCB0_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[0].spi_select0:3 */

    /* P3.2 */
    P3_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_2_MSCLP_SENSE                =  4,       /* msclp.sense:15 */
    P3_2_MSCLP_SHIELD               =  5,       /* msclp.shield:15 */
    P3_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_2_TCPWM_LINE1                =  8,       /* Digital Active - tcpwm.line[1]:0 */
    P3_2_SCB0_UART_CTS              =  9,       /* Digital Active - scb[0].uart_cts:1 */
    P3_2_MSCLP_MSC_DDRV15           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[15] */
    P3_2_CPUSS_SWD_DATA             = 13,       /* Digital Deep Sleep - cpuss.swd_data:0 */
    P3_2_SCB1_I2C_SDA               = 14,       /* Digital Deep Sleep - scb[1].i2c_sda:0 */
    P3_2_SCB0_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[0].spi_clk:1 */

    /* P3.3 */
    P3_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P3_3_MSCLP_SENSE                =  4,       /* msclp.sense:16 */
    P3_3_MSCLP_SHIELD               =  5,       /* msclp.shield:16 */
    P3_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P3_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P3_3_TCPWM_LINE_COMPL1          =  8,       /* Digital Active - tcpwm.line_compl[1]:0 */
    P3_3_SCB0_UART_RTS              =  9,       /* Digital Active - scb[0].uart_rts:1 */
    P3_3_MSCLP_MSC_DDRV16           = 12,       /* Digital Deep Sleep - msclp.msc_ddrv[16] */
    P3_3_CPUSS_SWD_CLK              = 13,       /* Digital Deep Sleep - cpuss.swd_clk:0 */
    P3_3_SCB1_I2C_SCL               = 14,       /* Digital Deep Sleep - scb[1].i2c_scl:0 */
    P3_3_SCB0_SPI_SELECT0           = 15,       /* Digital Deep Sleep - scb[0].spi_select0:1 */

    /* P4.2 */
    P4_2_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_2_MSCLP_SENSE                =  4,       /* msclp.sense:19 */
    P4_2_MSCLP_SHIELD               =  5,       /* msclp.shield:19 */
    P4_2_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_2_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_2_SCB0_UART_CTS              =  9,       /* Digital Active - scb[0].uart_cts:0 */
    P4_2_MSCLP_MSC_CMOD1_DDRV       = 12,       /* Digital Deep Sleep - msclp.msc_cmod1_ddrv */
    P4_2_SCB0_SPI_CLK               = 15,       /* Digital Deep Sleep - scb[0].spi_clk:2 */

    /* P4.3 */
    P4_3_GPIO                       =  0,       /* SW controlled GPIO. */
    P4_3_MSCLP_SENSE                =  4,       /* msclp.sense:20 */
    P4_3_MSCLP_SHIELD               =  5,       /* msclp.shield:20 */
    P4_3_AMUXA                      =  6,       /* AMUXBUS A connection. */
    P4_3_AMUXB                      =  7,       /* AMUXBUS B connection. */
    P4_3_SCB0_UART_RTS              =  9,       /* Digital Active - scb[0].uart_rts:0 */
    P4_3_MSCLP_MSC_CMOD2_DDRV       = 12,       /* Digital Deep Sleep - msclp.msc_cmod2_ddrv */
    P4_3_SCB0_SPI_SELECT0           = 15        /* Digital Deep Sleep - scb[0].spi_select0:2 */
} en_hsiom_sel_t;

#endif /* _GPIO_PSOC4000T_16_QFN_H_ */


/* [] END OF FILE */
