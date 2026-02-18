/***************************************************************************//**
* PSC3_P8 device GPIO header for PG-E-LQFP100L package
*
********************************************************************************
* \copyright
* (c) (2016-2026), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _GPIO_PSC3_P8_PG_E_LQFP100L_H_
#define _GPIO_PSC3_P8_PG_E_LQFP100L_H_

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
    CY_GPIO_PACKAGE_VQFN,
};

#define CY_GPIO_PACKAGE_TYPE            CY_GPIO_PACKAGE_LQFP
#define CY_GPIO_PIN_COUNT               100u

/* AMUXBUS Segments */
enum
{
    AMUXBUS_CHIP,
    AMUXBUS_FLASH,
    AMUXBUS_LPCOMP,
    AMUXBUS_SRSS,
    AMUXBUS_SVGS,
    AMUXBUS_TEST,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_0                = 0x0000u,  /* Left = AMUXBUS_CHIP; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_1                = 0x0001u,  /* Left = AMUXBUS_SRSS; Right = AMUXBUS_CHIP */
    AMUX_SPLIT_CTL_2                = 0x0002u,  /* Left = AMUXBUS_LPCOMP; Right = AMUXBUS_CHIP */
    AMUX_SPLIT_CTL_3                = 0x0003u,  /* Left = AMUXBUS_FLASH; Right = AMUXBUS_CHIP */
    AMUX_SPLIT_CTL_4                = 0x0004u   /* Left = AMUXBUS_SVGS; Right = AMUXBUS_CHIP */
} cy_en_amux_split_t;

/* Port List */
/* PORT 0 (GPIO) */
#define P0_0_PORT                       GPIO_PRT0
#define P0_0_PIN                        0u
#define P0_0_NUM                        0u
#define P0_1_PORT                       GPIO_PRT0
#define P0_1_PIN                        1u
#define P0_1_NUM                        1u

/* PORT 1 (GPIO) */
#define P1_0_PORT                       GPIO_PRT1
#define P1_0_PIN                        0u
#define P1_0_NUM                        0u
#define P1_1_PORT                       GPIO_PRT1
#define P1_1_PIN                        1u
#define P1_1_NUM                        1u
#define P1_2_PORT                       GPIO_PRT1
#define P1_2_PIN                        2u
#define P1_2_NUM                        2u
#define P1_3_PORT                       GPIO_PRT1
#define P1_3_PIN                        3u
#define P1_3_NUM                        3u
#define P1_4_PORT                       GPIO_PRT1
#define P1_4_PIN                        4u
#define P1_4_NUM                        4u
#define P1_5_PORT                       GPIO_PRT1
#define P1_5_PIN                        5u
#define P1_5_NUM                        5u
#define P1_6_PORT                       GPIO_PRT1
#define P1_6_PIN                        6u
#define P1_6_NUM                        6u
#define P1_7_PORT                       GPIO_PRT1
#define P1_7_PIN                        7u
#define P1_7_NUM                        7u

/* PORT 2 (GPIO_OVT) */
#define P2_0_PORT                       GPIO_PRT2
#define P2_0_PIN                        0u
#define P2_0_NUM                        0u
#define P2_1_PORT                       GPIO_PRT2
#define P2_1_PIN                        1u
#define P2_1_NUM                        1u
#define P2_2_PORT                       GPIO_PRT2
#define P2_2_PIN                        2u
#define P2_2_NUM                        2u
#define P2_3_PORT                       GPIO_PRT2
#define P2_3_PIN                        3u
#define P2_3_NUM                        3u
#define P2_4_PORT                       GPIO_PRT2
#define P2_4_PIN                        4u
#define P2_4_NUM                        4u
#define P2_5_PORT                       GPIO_PRT2
#define P2_5_PIN                        5u
#define P2_5_NUM                        5u

/* PORT 3 (GPIO) */
#define P3_0_PORT                       GPIO_PRT3
#define P3_0_PIN                        0u
#define P3_0_NUM                        0u
#define P3_1_PORT                       GPIO_PRT3
#define P3_1_PIN                        1u
#define P3_1_NUM                        1u
#define P3_2_PORT                       GPIO_PRT3
#define P3_2_PIN                        2u
#define P3_2_NUM                        2u
#define P3_3_PORT                       GPIO_PRT3
#define P3_3_PIN                        3u
#define P3_3_NUM                        3u
#define P3_4_PORT                       GPIO_PRT3
#define P3_4_PIN                        4u
#define P3_4_NUM                        4u
#define P3_5_PORT                       GPIO_PRT3
#define P3_5_PIN                        5u
#define P3_5_NUM                        5u
#define P3_6_PORT                       GPIO_PRT3
#define P3_6_PIN                        6u
#define P3_6_NUM                        6u
#define P3_7_PORT                       GPIO_PRT3
#define P3_7_PIN                        7u
#define P3_7_NUM                        7u

/* PORT 4 (GPIO) */
#define P4_0_PORT                       GPIO_PRT4
#define P4_0_PIN                        0u
#define P4_0_NUM                        0u
#define P4_1_PORT                       GPIO_PRT4
#define P4_1_PIN                        1u
#define P4_1_NUM                        1u
#define P4_2_PORT                       GPIO_PRT4
#define P4_2_PIN                        2u
#define P4_2_NUM                        2u
#define P4_3_PORT                       GPIO_PRT4
#define P4_3_PIN                        3u
#define P4_3_NUM                        3u
#define P4_4_PORT                       GPIO_PRT4
#define P4_4_PIN                        4u
#define P4_4_NUM                        4u
#define P4_5_PORT                       GPIO_PRT4
#define P4_5_PIN                        5u
#define P4_5_NUM                        5u
#define P4_6_PORT                       GPIO_PRT4
#define P4_6_PIN                        6u
#define P4_6_NUM                        6u
#define P4_7_PORT                       GPIO_PRT4
#define P4_7_PIN                        7u
#define P4_7_NUM                        7u

/* PORT 5 (GPIO) */
#define P5_0_PORT                       GPIO_PRT5
#define P5_0_PIN                        0u
#define P5_0_NUM                        0u
#define P5_1_PORT                       GPIO_PRT5
#define P5_1_PIN                        1u
#define P5_1_NUM                        1u
#define P5_2_PORT                       GPIO_PRT5
#define P5_2_PIN                        2u
#define P5_2_NUM                        2u
#define P5_3_PORT                       GPIO_PRT5
#define P5_3_PIN                        3u
#define P5_3_NUM                        3u

/* PORT 6 (GPIO) */
#define P6_0_PORT                       GPIO_PRT6
#define P6_0_PIN                        0u
#define P6_0_NUM                        0u
#define P6_1_PORT                       GPIO_PRT6
#define P6_1_PIN                        1u
#define P6_1_NUM                        1u
#define P6_2_PORT                       GPIO_PRT6
#define P6_2_PIN                        2u
#define P6_2_NUM                        2u
#define P6_3_PORT                       GPIO_PRT6
#define P6_3_PIN                        3u
#define P6_3_NUM                        3u
#define P6_4_PORT                       GPIO_PRT6
#define P6_4_PIN                        4u
#define P6_4_NUM                        4u
#define P6_5_PORT                       GPIO_PRT6
#define P6_5_PIN                        5u
#define P6_5_NUM                        5u

/* PORT 7 (GPIO) */
#define P7_0_PORT                       GPIO_PRT7
#define P7_0_PIN                        0u
#define P7_0_NUM                        0u
#define P7_1_PORT                       GPIO_PRT7
#define P7_1_PIN                        1u
#define P7_1_NUM                        1u
#define P7_2_PORT                       GPIO_PRT7
#define P7_2_PIN                        2u
#define P7_2_NUM                        2u
#define P7_3_PORT                       GPIO_PRT7
#define P7_3_PIN                        3u
#define P7_3_NUM                        3u
#define P7_4_PORT                       GPIO_PRT7
#define P7_4_PIN                        4u
#define P7_4_NUM                        4u
#define P7_5_PORT                       GPIO_PRT7
#define P7_5_PIN                        5u
#define P7_5_NUM                        5u
#define P7_6_PORT                       GPIO_PRT7
#define P7_6_PIN                        6u
#define P7_6_NUM                        6u
#define P7_7_PORT                       GPIO_PRT7
#define P7_7_PIN                        7u
#define P7_7_NUM                        7u

/* PORT 8 (GPIO) */
#define P8_0_PORT                       GPIO_PRT8
#define P8_0_PIN                        0u
#define P8_0_NUM                        0u
#define P8_1_PORT                       GPIO_PRT8
#define P8_1_PIN                        1u
#define P8_1_NUM                        1u
#define P8_2_PORT                       GPIO_PRT8
#define P8_2_PIN                        2u
#define P8_2_NUM                        2u
#define P8_3_PORT                       GPIO_PRT8
#define P8_3_PIN                        3u
#define P8_3_NUM                        3u
#define P8_4_PORT                       GPIO_PRT8
#define P8_4_PIN                        4u
#define P8_4_NUM                        4u
#define P8_5_PORT                       GPIO_PRT8
#define P8_5_PIN                        5u
#define P8_5_NUM                        5u

/* PORT 9 (GPIO) */
#define P9_0_PORT                       GPIO_PRT9
#define P9_0_PIN                        0u
#define P9_0_NUM                        0u
#define P9_1_PORT                       GPIO_PRT9
#define P9_1_PIN                        1u
#define P9_1_NUM                        1u
#define P9_2_PORT                       GPIO_PRT9
#define P9_2_PIN                        2u
#define P9_2_NUM                        2u
#define P9_3_PORT                       GPIO_PRT9
#define P9_3_PIN                        3u
#define P9_3_NUM                        3u

/* Analog Connections */
#define IOSS_ADFT0_NET0_PORT            8u
#define IOSS_ADFT0_NET0_PIN             4u
#define IOSS_ADFT1_NET0_PORT            8u
#define IOSS_ADFT1_NET0_PIN             5u
#define LPCOMP_INN_COMP0_PORT           6u
#define LPCOMP_INN_COMP0_PIN            4u
#define LPCOMP_INN_COMP1_PORT           6u
#define LPCOMP_INN_COMP1_PIN            2u
#define LPCOMP_INP_COMP0_PORT           6u
#define LPCOMP_INP_COMP0_PIN            5u
#define LPCOMP_INP_COMP1_PORT           6u
#define LPCOMP_INP_COMP1_PIN            3u
#define PPCA_AI10_AI_PORT               7u
#define PPCA_AI10_AI_PIN                1u
#define PPCA_AI11_AI_PORT               7u
#define PPCA_AI11_AI_PIN                2u
#define PPCA_AI12_AI_PORT               7u
#define PPCA_AI12_AI_PIN                3u
#define PPCA_AI13_AI_PORT               7u
#define PPCA_AI13_AI_PIN                4u
#define PPCA_AI14_AI_PORT               7u
#define PPCA_AI14_AI_PIN                5u
#define PPCA_AI15_AI_PORT               7u
#define PPCA_AI15_AI_PIN                6u
#define PPCA_AI2_AI_PORT                6u
#define PPCA_AI2_AI_PIN                 5u
#define PPCA_AI3_AI_PORT                6u
#define PPCA_AI3_AI_PIN                 4u
#define PPCA_AI4_AI_PORT                6u
#define PPCA_AI4_AI_PIN                 3u
#define PPCA_AI5_AI_PORT                6u
#define PPCA_AI5_AI_PIN                 2u
#define PPCA_AI6_AI_PORT                6u
#define PPCA_AI6_AI_PIN                 1u
#define PPCA_AI7_AI_PORT                6u
#define PPCA_AI7_AI_PIN                 0u
#define PPCA_AI8_AI_PORT                5u
#define PPCA_AI8_AI_PIN                 3u
#define PPCA_AI9_AI_PORT                7u
#define PPCA_AI9_AI_PIN                 0u
#define SRSS_ECO_IN_PORT                1u
#define SRSS_ECO_IN_PIN                 0u
#define SRSS_ECO_OUT_PORT               1u
#define SRSS_ECO_OUT_PIN                1u
#define SRSS_VEXT_REF_REG_PORT          2u
#define SRSS_VEXT_REF_REG_PIN           0u
#define SRSS_WCO_IN_PORT                0u
#define SRSS_WCO_IN_PIN                 1u
#define SRSS_WCO_OUT_PORT               0u
#define SRSS_WCO_OUT_PIN                0u
#define SVGS_SVGS_TEST_VCCD_FEED_PORT   8u
#define SVGS_SVGS_TEST_VCCD_FEED_PIN    3u

/* HSIOM Connections */
typedef enum
{
    /* Generic HSIOM connections */
    HSIOM_SEL_GPIO                  =  0,       /* GPIO controls 'out' */
    HSIOM_SEL_GPIO_DSI              =  1,       /* GPIO controls 'out', DSI controls 'output enable' */
    HSIOM_SEL_DSI_DSI               =  2,       /* DSI controls 'out' and 'output enable' */
    HSIOM_SEL_DSI_GPIO              =  3,       /* DSI controls 'out', GPIO controls 'output enable' */
    HSIOM_SEL_AMUXA                 =  4,       /* Analog mux bus A */
    HSIOM_SEL_AMUXB                 =  5,       /* Analog mux bus B */
    HSIOM_SEL_AMUXA_DSI             =  6,       /* Analog mux bus A, DSI control */
    HSIOM_SEL_AMUXB_DSI             =  7,       /* Analog mux bus B, DSI control */
    HSIOM_SEL_ACT_0                 =  8,       /* Active functionality 0 */
    HSIOM_SEL_ACT_1                 =  9,       /* Active functionality 1 */
    HSIOM_SEL_ACT_2                 = 10,       /* Active functionality 2 */
    HSIOM_SEL_ACT_3                 = 11,       /* Active functionality 3 */
    HSIOM_SEL_DS_0                  = 12,       /* DeepSleep functionality 0 */
    HSIOM_SEL_DS_1                  = 13,       /* DeepSleep functionality 1 */
    HSIOM_SEL_DS_2                  = 14,       /* DeepSleep functionality 2 */
    HSIOM_SEL_DS_3                  = 15,       /* DeepSleep functionality 3 */
    HSIOM_SEL_ACT_4                 = 16,       /* Active functionality 4 */
    HSIOM_SEL_ACT_5                 = 17,       /* Active functionality 5 */
    HSIOM_SEL_ACT_6                 = 18,       /* Active functionality 6 */
    HSIOM_SEL_ACT_7                 = 19,       /* Active functionality 7 */
    HSIOM_SEL_ACT_8                 = 20,       /* Active functionality 8 */
    HSIOM_SEL_ACT_9                 = 21,       /* Active functionality 9 */
    HSIOM_SEL_ACT_10                = 22,       /* Active functionality 10 */
    HSIOM_SEL_ACT_11                = 23,       /* Active functionality 11 */
    HSIOM_SEL_ACT_12                = 24,       /* Active functionality 12 */
    HSIOM_SEL_ACT_13                = 25,       /* Active functionality 13 */
    HSIOM_SEL_ACT_14                = 26,       /* Active functionality 14 */
    HSIOM_SEL_ACT_15                = 27,       /* Active functionality 15 */
    HSIOM_SEL_DS_4                  = 28,       /* DeepSleep functionality 4 */
    HSIOM_SEL_DS_5                  = 29,       /* DeepSleep functionality 5 */
    HSIOM_SEL_DS_6                  = 30,       /* DeepSleep functionality 6 */
    HSIOM_SEL_DS_7                  = 31,       /* DeepSleep functionality 7 */

    /* P0.0 */
    P0_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_0_PPCA_PPSSIO54              =  8,       /* Digital Active - ppca.ppssio[54]:0 */
    P0_0_PERI_TR_IO_INPUT0          = 25,       /* Digital Active - peri.tr_io_input[0]:0 */
    P0_0_PERI_TR_IO_OUTPUT0         = 26,       /* Digital Active - peri.tr_io_output[0]:0 */
    P0_0_PERI_TR_IO_OUTPUT60        = 27,       /* Digital Active - peri.tr_io_output[60]:0 */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_1_PPCA_PPSSIO55              =  8,       /* Digital Active - ppca.ppssio[55]:0 */
    P0_1_PERI_TR_IO_INPUT1          = 25,       /* Digital Active - peri.tr_io_input[1]:0 */
    P0_1_PERI_TR_IO_OUTPUT1         = 26,       /* Digital Active - peri.tr_io_output[1]:0 */
    P0_1_PERI_TR_IO_OUTPUT61        = 27,       /* Digital Active - peri.tr_io_output[61]:0 */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_0_PPCA_PPSSIO56              =  8,       /* Digital Active - ppca.ppssio[56]:0 */
    P1_0_PERI_TR_IO_INPUT2          = 25,       /* Digital Active - peri.tr_io_input[2]:0 */
    P1_0_PERI_TR_IO_OUTPUT2         = 26,       /* Digital Active - peri.tr_io_output[2]:0 */
    P1_0_PERI_TR_IO_OUTPUT62        = 27,       /* Digital Active - peri.tr_io_output[62]:0 */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_1_PPCA_PPSSIO57              =  8,       /* Digital Active - ppca.ppssio[57]:0 */
    P1_1_PERI_TR_IO_INPUT3          = 25,       /* Digital Active - peri.tr_io_input[3]:0 */
    P1_1_PERI_TR_IO_OUTPUT3         = 26,       /* Digital Active - peri.tr_io_output[3]:0 */
    P1_1_PERI_TR_IO_OUTPUT63        = 27,       /* Digital Active - peri.tr_io_output[63]:0 */

    /* P1.2 */
    P1_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_2_PPCA_PPSSIO58              =  8,       /* Digital Active - ppca.ppssio[58]:0 */
    P1_2_TCPWM0_LINE0               = 22,       /* Digital Active - tcpwm[0].line[0]:0 */
    P1_2_PERI_TR_IO_INPUT4          = 25,       /* Digital Active - peri.tr_io_input[4]:0 */
    P1_2_PERI_TR_IO_OUTPUT4         = 26,       /* Digital Active - peri.tr_io_output[4]:0 */
    P1_2_PERI_TR_IO_OUTPUT64        = 27,       /* Digital Active - peri.tr_io_output[64]:0 */
    P1_2_DEBUG600_CLK_SWJ_SWCLK_TCLK = 29,      /* Digital Deep Sleep - debug600.clk_swj_swclk_tclk */

    /* P1.3 */
    P1_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_3_PPCA_PPSSIO59              =  8,       /* Digital Active - ppca.ppssio[59]:0 */
    P1_3_TCPWM0_LINE_COMPL0         = 22,       /* Digital Active - tcpwm[0].line_compl[0]:0 */
    P1_3_PERI_TR_IO_INPUT5          = 25,       /* Digital Active - peri.tr_io_input[5]:0 */
    P1_3_PERI_TR_IO_OUTPUT5         = 26,       /* Digital Active - peri.tr_io_output[5]:0 */
    P1_3_PERI_TR_IO_OUTPUT65        = 27,       /* Digital Active - peri.tr_io_output[65]:0 */
    P1_3_DEBUG600_SWJ_SWDIO_TMS     = 29,       /* Digital Deep Sleep - debug600.swj_swdio_tms */

    /* P1.4 */
    P1_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_4_PPCA_PPSSIO10              =  8,       /* Digital Active - ppca.ppssio[10]:0 */
    P1_4_PERI_TR_IO_INPUT6          = 25,       /* Digital Active - peri.tr_io_input[6]:0 */
    P1_4_PERI_TR_IO_OUTPUT6         = 26,       /* Digital Active - peri.tr_io_output[6]:0 */
    P1_4_PERI_TR_IO_OUTPUT66        = 27,       /* Digital Active - peri.tr_io_output[66]:0 */

    /* P1.5 */
    P1_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_5_PPCA_PPSSIO11              =  8,       /* Digital Active - ppca.ppssio[11]:0 */
    P1_5_PERI_TR_IO_INPUT7          = 25,       /* Digital Active - peri.tr_io_input[7]:0 */
    P1_5_PERI_TR_IO_OUTPUT7         = 26,       /* Digital Active - peri.tr_io_output[7]:0 */
    P1_5_PERI_TR_IO_OUTPUT67        = 27,       /* Digital Active - peri.tr_io_output[67]:0 */

    /* P1.6 */
    P1_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_6_PPCA_PPSSIO12              =  8,       /* Digital Active - ppca.ppssio[12]:0 */
    P1_6_PERI_TR_IO_INPUT8          = 25,       /* Digital Active - peri.tr_io_input[8]:0 */
    P1_6_PERI_TR_IO_OUTPUT8         = 26,       /* Digital Active - peri.tr_io_output[8]:0 */
    P1_6_PERI_TR_IO_OUTPUT68        = 27,       /* Digital Active - peri.tr_io_output[68]:0 */

    /* P1.7 */
    P1_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_7_PPCA_PPSSIO13              =  8,       /* Digital Active - ppca.ppssio[13]:0 */
    P1_7_PERI_TR_IO_INPUT9          = 25,       /* Digital Active - peri.tr_io_input[9]:0 */
    P1_7_PERI_TR_IO_OUTPUT9         = 26,       /* Digital Active - peri.tr_io_output[9]:0 */
    P1_7_PERI_TR_IO_OUTPUT69        = 27,       /* Digital Active - peri.tr_io_output[69]:0 */

    /* P2.0 */
    P2_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_0_PPCA_PPSSIO48              =  8,       /* Digital Active - ppca.ppssio[48]:0 */
    P2_0_SCB6_SPI_MOSI              = 18,       /* Digital Active - scb[6].spi_mosi:0 */
    P2_0_SCB6_UART_TX               = 19,       /* Digital Active - scb[6].uart_tx:0 */
    P2_0_SCB6_I2C_SDA               = 21,       /* Digital Active - scb[6].i2c_sda:0 */
    P2_0_PERI_TR_IO_INPUT10         = 25,       /* Digital Active - peri.tr_io_input[10]:0 */
    P2_0_PERI_TR_IO_OUTPUT10        = 26,       /* Digital Active - peri.tr_io_output[10]:0 */
    P2_0_PERI_TR_IO_OUTPUT70        = 27,       /* Digital Active - peri.tr_io_output[70]:0 */

    /* P2.1 */
    P2_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_1_PPCA_PPSSIO49              =  8,       /* Digital Active - ppca.ppssio[49]:0 */
    P2_1_SCB6_SPI_CLK               = 18,       /* Digital Active - scb[6].spi_clk:0 */
    P2_1_SCB6_UART_RX               = 19,       /* Digital Active - scb[6].uart_rx:0 */
    P2_1_SCB6_I2C_SCL               = 21,       /* Digital Active - scb[6].i2c_scl:0 */
    P2_1_PERI_TR_IO_INPUT11         = 25,       /* Digital Active - peri.tr_io_input[11]:0 */
    P2_1_PERI_TR_IO_OUTPUT11        = 26,       /* Digital Active - peri.tr_io_output[11]:0 */
    P2_1_PERI_TR_IO_OUTPUT71        = 27,       /* Digital Active - peri.tr_io_output[71]:0 */
    P2_1_DEBUG600_SWJ_SWDOE_TDI     = 29,       /* Digital Deep Sleep - debug600.swj_swdoe_tdi */
    P2_1_IOSS_DDFT_PIN0             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[0]:0 */

    /* P2.2 */
    P2_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_2_PPCA_PPSSIO50              =  8,       /* Digital Active - ppca.ppssio[50]:0 */
    P2_2_SRSS_CAL_WAVE              = 12,       /* Digital Deep Sleep - srss.cal_wave */
    P2_2_SCB6_SPI_MISO              = 18,       /* Digital Active - scb[6].spi_miso:0 */
    P2_2_SCB6_UART_RTS              = 19,       /* Digital Active - scb[6].uart_rts:0 */
    P2_2_SCB6_I2C_SCL_DO            = 21,       /* Digital Active - scb[6].i2c_scl_do:0 */
    P2_2_PERI_TR_IO_INPUT12         = 25,       /* Digital Active - peri.tr_io_input[12]:0 */
    P2_2_PERI_TR_IO_OUTPUT12        = 26,       /* Digital Active - peri.tr_io_output[12]:0 */
    P2_2_PERI_TR_IO_OUTPUT72        = 27,       /* Digital Active - peri.tr_io_output[72]:0 */
    P2_2_DEBUG600_RST_SWJ_TRSTN     = 29,       /* Digital Deep Sleep - debug600.rst_swj_trstn */

    /* P2.3 */
    P2_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_3_PPCA_PPSSIO51              =  8,       /* Digital Active - ppca.ppssio[51]:0 */
    P2_3_CANFD0_TTCAN_RX0           = 11,       /* Digital Active - canfd[0].ttcan_rx[0]:0 */
    P2_3_SCB0_SPI_CLK               = 13,       /* Digital Deep Sleep - scb[0].spi_clk:0 */
    P2_3_SCB0_UART_RX               = 14,       /* Digital Deep Sleep - scb[0].uart_rx:0 */
    P2_3_SCB0_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */
    P2_3_PERI_TR_IO_INPUT13         = 25,       /* Digital Active - peri.tr_io_input[13]:0 */
    P2_3_PERI_TR_IO_OUTPUT13        = 26,       /* Digital Active - peri.tr_io_output[13]:0 */
    P2_3_PERI_TR_IO_OUTPUT73        = 27,       /* Digital Active - peri.tr_io_output[73]:0 */
    P2_3_DEBUG600_SWJ_SWO_TDO       = 29,       /* Digital Deep Sleep - debug600.swj_swo_tdo */

    /* P2.4 */
    P2_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_4_PPCA_PPSSIO52              =  8,       /* Digital Active - ppca.ppssio[52]:0 */
    P2_4_CANFD0_TTCAN_TX0           = 11,       /* Digital Active - canfd[0].ttcan_tx[0]:0 */
    P2_4_SCB0_SPI_MOSI              = 13,       /* Digital Deep Sleep - scb[0].spi_mosi:0 */
    P2_4_SCB0_UART_TX               = 14,       /* Digital Deep Sleep - scb[0].uart_tx:0 */
    P2_4_SCB0_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */
    P2_4_TCPWM0_LINE1               = 22,       /* Digital Active - tcpwm[0].line[1]:0 */
    P2_4_PERI_TR_IO_INPUT14         = 25,       /* Digital Active - peri.tr_io_input[14]:0 */
    P2_4_PERI_TR_IO_OUTPUT14        = 26,       /* Digital Active - peri.tr_io_output[14]:0 */
    P2_4_PERI_TR_IO_OUTPUT74        = 27,       /* Digital Active - peri.tr_io_output[74]:0 */

    /* P2.5 */
    P2_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_5_PPCA_PPSSIO53              =  8,       /* Digital Active - ppca.ppssio[53]:0 */
    P2_5_SCB0_SPI_MISO              = 13,       /* Digital Deep Sleep - scb[0].spi_miso:0 */
    P2_5_SCB0_UART_RTS              = 14,       /* Digital Deep Sleep - scb[0].uart_rts:0 */
    P2_5_SCB0_I2C_SCL_DO            = 15,       /* Digital Deep Sleep - scb[0].i2c_scl_do:0 */
    P2_5_TCPWM0_LINE_COMPL1         = 22,       /* Digital Active - tcpwm[0].line_compl[1]:0 */
    P2_5_PERI_TR_IO_INPUT15         = 25,       /* Digital Active - peri.tr_io_input[15]:0 */
    P2_5_PERI_TR_IO_OUTPUT15        = 26,       /* Digital Active - peri.tr_io_output[15]:0 */
    P2_5_PERI_TR_IO_OUTPUT75        = 27,       /* Digital Active - peri.tr_io_output[75]:0 */

    /* P3.0 */
    P3_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_0_PPCA_PPSSIO31              =  8,       /* Digital Active - ppca.ppssio[31]:0 */
    P3_0_CANFD0_TTCAN_TX0           = 11,       /* Digital Active - canfd[0].ttcan_tx[0]:1 */
    P3_0_SCB2_SPI_SELECT1           = 16,       /* Digital Active - scb[2].spi_select1:0 */
    P3_0_SCB6_SPI_SELECT0           = 18,       /* Digital Active - scb[6].spi_select0:0 */
    P3_0_SCB6_UART_CTS              = 19,       /* Digital Active - scb[6].uart_cts:0 */
    P3_0_SCB6_I2C_SDA_DO            = 21,       /* Digital Active - scb[6].i2c_sda_do:0 */
    P3_0_PERI_TR_IO_INPUT16         = 25,       /* Digital Active - peri.tr_io_input[16]:0 */
    P3_0_PERI_TR_IO_OUTPUT16        = 26,       /* Digital Active - peri.tr_io_output[16]:0 */
    P3_0_PERI_TR_IO_OUTPUT76        = 27,       /* Digital Active - peri.tr_io_output[76]:0 */

    /* P3.1 */
    P3_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_1_PPCA_PPSSIO30              =  8,       /* Digital Active - ppca.ppssio[30]:0 */
    P3_1_CANFD0_TTCAN_RX0           = 11,       /* Digital Active - canfd[0].ttcan_rx[0]:1 */
    P3_1_SCB2_SPI_SELECT0           = 16,       /* Digital Active - scb[2].spi_select0:0 */
    P3_1_SCB6_SPI_SELECT1           = 18,       /* Digital Active - scb[6].spi_select1:0 */
    P3_1_SCB2_UART_CTS              = 19,       /* Digital Active - scb[2].uart_cts:0 */
    P3_1_SCB2_I2C_SDA_DO            = 21,       /* Digital Active - scb[2].i2c_sda_do:0 */
    P3_1_PERI_TR_IO_INPUT17         = 25,       /* Digital Active - peri.tr_io_input[17]:0 */
    P3_1_PERI_TR_IO_OUTPUT17        = 26,       /* Digital Active - peri.tr_io_output[17]:0 */
    P3_1_PERI_TR_IO_OUTPUT77        = 27,       /* Digital Active - peri.tr_io_output[77]:0 */

    /* P3.2 */
    P3_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_2_PPCA_PPSSIO40              =  8,       /* Digital Active - ppca.ppssio[40]:0 */
    P3_2_SCB2_SPI_MISO              = 16,       /* Digital Active - scb[2].spi_miso:0 */
    P3_2_SCB6_SPI_SELECT2           = 18,       /* Digital Active - scb[6].spi_select2:0 */
    P3_2_SCB2_UART_RTS              = 19,       /* Digital Active - scb[2].uart_rts:0 */
    P3_2_SCB2_I2C_SCL_DO            = 21,       /* Digital Active - scb[2].i2c_scl_do:0 */
    P3_2_PERI_TR_IO_INPUT18         = 25,       /* Digital Active - peri.tr_io_input[18]:0 */
    P3_2_PERI_TR_IO_OUTPUT18        = 26,       /* Digital Active - peri.tr_io_output[18]:0 */
    P3_2_PERI_TR_IO_OUTPUT78        = 27,       /* Digital Active - peri.tr_io_output[78]:0 */

    /* P3.3 */
    P3_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_3_PPCA_PPSSIO41              =  8,       /* Digital Active - ppca.ppssio[41]:0 */
    P3_3_SCB2_SPI_MOSI              = 16,       /* Digital Active - scb[2].spi_mosi:0 */
    P3_3_SCB2_UART_TX               = 19,       /* Digital Active - scb[2].uart_tx:0 */
    P3_3_SCB2_I2C_SDA               = 21,       /* Digital Active - scb[2].i2c_sda:0 */
    P3_3_TCPWM0_LINE256             = 22,       /* Digital Active - tcpwm[0].line[256]:0 */
    P3_3_PERI_TR_IO_INPUT19         = 25,       /* Digital Active - peri.tr_io_input[19]:0 */
    P3_3_PERI_TR_IO_OUTPUT19        = 26,       /* Digital Active - peri.tr_io_output[19]:0 */
    P3_3_PERI_TR_IO_OUTPUT79        = 27,       /* Digital Active - peri.tr_io_output[79]:0 */

    /* P3.4 */
    P3_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_4_PPCA_PPSSIO42              =  8,       /* Digital Active - ppca.ppssio[42]:0 */
    P3_4_SCB2_SPI_CLK               = 16,       /* Digital Active - scb[2].spi_clk:0 */
    P3_4_SCB2_UART_RX               = 19,       /* Digital Active - scb[2].uart_rx:0 */
    P3_4_SCB2_I2C_SCL               = 21,       /* Digital Active - scb[2].i2c_scl:0 */
    P3_4_TCPWM0_LINE_COMPL256       = 22,       /* Digital Active - tcpwm[0].line_compl[256]:0 */
    P3_4_PERI_TR_IO_INPUT20         = 25,       /* Digital Active - peri.tr_io_input[20]:0 */
    P3_4_PERI_TR_IO_OUTPUT20        = 26,       /* Digital Active - peri.tr_io_output[20]:0 */
    P3_4_PERI_TR_IO_OUTPUT80        = 27,       /* Digital Active - peri.tr_io_output[80]:0 */

    /* P3.5 */
    P3_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_5_PPCA_PPSSIO43              =  8,       /* Digital Active - ppca.ppssio[43]:0 */
    P3_5_SCB4_SPI_CLK               = 17,       /* Digital Active - scb[4].spi_clk:0 */
    P3_5_SCB4_UART_RX               = 20,       /* Digital Active - scb[4].uart_rx:0 */
    P3_5_SCB4_I2C_SCL               = 21,       /* Digital Active - scb[4].i2c_scl:0 */
    P3_5_TCPWM0_LINE257             = 22,       /* Digital Active - tcpwm[0].line[257]:0 */
    P3_5_PERI_TR_IO_INPUT21         = 25,       /* Digital Active - peri.tr_io_input[21]:0 */
    P3_5_PERI_TR_IO_OUTPUT21        = 26,       /* Digital Active - peri.tr_io_output[21]:0 */
    P3_5_PERI_TR_IO_OUTPUT81        = 27,       /* Digital Active - peri.tr_io_output[81]:0 */

    /* P3.6 */
    P3_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_6_PPCA_PPSSIO44              =  8,       /* Digital Active - ppca.ppssio[44]:0 */
    P3_6_SCB4_SPI_MOSI              = 17,       /* Digital Active - scb[4].spi_mosi:0 */
    P3_6_SCB4_UART_TX               = 20,       /* Digital Active - scb[4].uart_tx:0 */
    P3_6_SCB4_I2C_SDA               = 21,       /* Digital Active - scb[4].i2c_sda:0 */
    P3_6_TCPWM0_LINE_COMPL257       = 22,       /* Digital Active - tcpwm[0].line_compl[257]:0 */
    P3_6_PERI_TR_IO_INPUT22         = 25,       /* Digital Active - peri.tr_io_input[22]:0 */
    P3_6_PERI_TR_IO_OUTPUT22        = 26,       /* Digital Active - peri.tr_io_output[22]:0 */
    P3_6_PERI_TR_IO_OUTPUT82        = 27,       /* Digital Active - peri.tr_io_output[82]:0 */

    /* P3.7 */
    P3_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_7_PPCA_PPSSIO45              =  8,       /* Digital Active - ppca.ppssio[45]:0 */
    P3_7_SCB2_SPI_SELECT2           = 16,       /* Digital Active - scb[2].spi_select2:0 */
    P3_7_SCB4_SPI_SELECT2           = 17,       /* Digital Active - scb[4].spi_select2:0 */
    P3_7_PERI_TR_IO_INPUT23         = 25,       /* Digital Active - peri.tr_io_input[23]:0 */
    P3_7_PERI_TR_IO_OUTPUT23        = 26,       /* Digital Active - peri.tr_io_output[23]:0 */
    P3_7_PERI_TR_IO_OUTPUT83        = 27,       /* Digital Active - peri.tr_io_output[83]:0 */

    /* P4.0 */
    P4_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_0_PPCA_PPSSIO23              =  8,       /* Digital Active - ppca.ppssio[23]:0 */
    P4_0_SCB0_SPI_SELECT2           = 13,       /* Digital Deep Sleep - scb[0].spi_select2:0 */
    P4_0_SCB4_SPI_MISO              = 17,       /* Digital Active - scb[4].spi_miso:0 */
    P4_0_SCB6_SPI_SELECT0           = 18,       /* Digital Active - scb[6].spi_select0:1 */
    P4_0_SCB6_UART_CTS              = 19,       /* Digital Active - scb[6].uart_cts:1 */
    P4_0_SCB4_UART_RTS              = 20,       /* Digital Active - scb[4].uart_rts:0 */
    P4_0_SCB6_I2C_SDA_DO            = 21,       /* Digital Active - scb[6].i2c_sda_do:1 */
    P4_0_SCB4_I2C_SCL_DO            = 22,       /* Digital Active - scb[4].i2c_scl_do:0 */
    P4_0_PERI_TR_IO_INPUT24         = 25,       /* Digital Active - peri.tr_io_input[24]:0 */
    P4_0_PERI_TR_IO_OUTPUT24        = 26,       /* Digital Active - peri.tr_io_output[24]:0 */
    P4_0_PERI_TR_IO_OUTPUT84        = 27,       /* Digital Active - peri.tr_io_output[84]:0 */

    /* P4.1 */
    P4_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_1_PPCA_PPSSIO22              =  8,       /* Digital Active - ppca.ppssio[22]:0 */
    P4_1_SCB0_SPI_SELECT1           = 13,       /* Digital Deep Sleep - scb[0].spi_select1:0 */
    P4_1_SCB6_SPI_SELECT1           = 18,       /* Digital Active - scb[6].spi_select1:1 */
    P4_1_PERI_TR_IO_INPUT25         = 25,       /* Digital Active - peri.tr_io_input[25]:0 */
    P4_1_PERI_TR_IO_OUTPUT25        = 26,       /* Digital Active - peri.tr_io_output[25]:0 */
    P4_1_PERI_TR_IO_OUTPUT85        = 27,       /* Digital Active - peri.tr_io_output[85]:0 */

    /* P4.2 */
    P4_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_2_PPCA_PPSSIO21              =  8,       /* Digital Active - ppca.ppssio[21]:0 */
    P4_2_SCB0_SPI_SELECT0           = 13,       /* Digital Deep Sleep - scb[0].spi_select0:0 */
    P4_2_SCB0_UART_CTS              = 14,       /* Digital Deep Sleep - scb[0].uart_cts:0 */
    P4_2_SCB0_I2C_SDA_DO            = 15,       /* Digital Deep Sleep - scb[0].i2c_sda_do:0 */
    P4_2_SCB6_SPI_SELECT2           = 18,       /* Digital Active - scb[6].spi_select2:1 */
    P4_2_PERI_TR_IO_INPUT26         = 25,       /* Digital Active - peri.tr_io_input[26]:0 */
    P4_2_PERI_TR_IO_OUTPUT26        = 26,       /* Digital Active - peri.tr_io_output[26]:0 */
    P4_2_PERI_TR_IO_OUTPUT86        = 27,       /* Digital Active - peri.tr_io_output[86]:0 */

    /* P4.3 */
    P4_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_3_PPCA_PPSSIO20              =  8,       /* Digital Active - ppca.ppssio[20]:0 */
    P4_3_SCB1_SPI_MISO              = 16,       /* Digital Active - scb[1].spi_miso:0 */
    P4_3_SCB4_SPI_SELECT0           = 17,       /* Digital Active - scb[4].spi_select0:0 */
    P4_3_SCB1_UART_RTS              = 19,       /* Digital Active - scb[1].uart_rts:0 */
    P4_3_SCB4_UART_CTS              = 20,       /* Digital Active - scb[4].uart_cts:0 */
    P4_3_SCB1_I2C_SCL_DO            = 21,       /* Digital Active - scb[1].i2c_scl_do:0 */
    P4_3_SCB4_I2C_SDA_DO            = 22,       /* Digital Active - scb[4].i2c_sda_do:0 */
    P4_3_PERI_TR_IO_INPUT27         = 25,       /* Digital Active - peri.tr_io_input[27]:0 */
    P4_3_PERI_TR_IO_OUTPUT27        = 26,       /* Digital Active - peri.tr_io_output[27]:0 */
    P4_3_PERI_TR_IO_OUTPUT87        = 27,       /* Digital Active - peri.tr_io_output[87]:0 */

    /* P4.4 */
    P4_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_4_PPCA_PPSSIO24              =  8,       /* Digital Active - ppca.ppssio[24]:0 */
    P4_4_PERI_TR_IO_INPUT28         = 25,       /* Digital Active - peri.tr_io_input[28]:0 */
    P4_4_PERI_TR_IO_OUTPUT28        = 26,       /* Digital Active - peri.tr_io_output[28]:0 */
    P4_4_PERI_TR_IO_OUTPUT88        = 27,       /* Digital Active - peri.tr_io_output[88]:0 */

    /* P4.5 */
    P4_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_5_PPCA_PPSSIO25              =  8,       /* Digital Active - ppca.ppssio[25]:0 */
    P4_5_SCB1_SPI_SELECT2           = 16,       /* Digital Active - scb[1].spi_select2:0 */
    P4_5_PERI_TR_IO_INPUT29         = 25,       /* Digital Active - peri.tr_io_input[29]:0 */
    P4_5_PERI_TR_IO_OUTPUT29        = 26,       /* Digital Active - peri.tr_io_output[29]:0 */
    P4_5_PERI_TR_IO_OUTPUT89        = 27,       /* Digital Active - peri.tr_io_output[89]:0 */

    /* P4.6 */
    P4_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_6_PPCA_PPSSIO26              =  8,       /* Digital Active - ppca.ppssio[26]:0 */
    P4_6_SCB1_SPI_SELECT1           = 16,       /* Digital Active - scb[1].spi_select1:0 */
    P4_6_PERI_TR_IO_INPUT30         = 25,       /* Digital Active - peri.tr_io_input[30]:0 */
    P4_6_PERI_TR_IO_OUTPUT30        = 26,       /* Digital Active - peri.tr_io_output[30]:0 */
    P4_6_PERI_TR_IO_OUTPUT90        = 27,       /* Digital Active - peri.tr_io_output[90]:0 */

    /* P4.7 */
    P4_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_7_PPCA_PPSSIO27              =  8,       /* Digital Active - ppca.ppssio[27]:0 */
    P4_7_SCB1_SPI_SELECT0           = 16,       /* Digital Active - scb[1].spi_select0:0 */
    P4_7_SCB1_UART_CTS              = 19,       /* Digital Active - scb[1].uart_cts:0 */
    P4_7_SCB1_I2C_SDA_DO            = 21,       /* Digital Active - scb[1].i2c_sda_do:0 */
    P4_7_PERI_TR_IO_INPUT31         = 25,       /* Digital Active - peri.tr_io_input[31]:0 */
    P4_7_PERI_TR_IO_OUTPUT31        = 26,       /* Digital Active - peri.tr_io_output[31]:0 */
    P4_7_PERI_TR_IO_OUTPUT91        = 27,       /* Digital Active - peri.tr_io_output[91]:0 */

    /* P5.0 */
    P5_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_0_PPCA_PPSSIO28              =  8,       /* Digital Active - ppca.ppssio[28]:0 */
    P5_0_SCB1_SPI_MOSI              = 16,       /* Digital Active - scb[1].spi_mosi:0 */
    P5_0_SCB4_SPI_SELECT1           = 17,       /* Digital Active - scb[4].spi_select1:0 */
    P5_0_SCB1_UART_TX               = 19,       /* Digital Active - scb[1].uart_tx:0 */
    P5_0_SCB1_I2C_SDA               = 21,       /* Digital Active - scb[1].i2c_sda:0 */
    P5_0_PERI_TR_IO_INPUT32         = 25,       /* Digital Active - peri.tr_io_input[32]:0 */
    P5_0_PERI_TR_IO_OUTPUT32        = 26,       /* Digital Active - peri.tr_io_output[32]:0 */
    P5_0_PERI_TR_IO_OUTPUT92        = 27,       /* Digital Active - peri.tr_io_output[92]:0 */

    /* P5.1 */
    P5_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_1_PPCA_PPSSIO29              =  8,       /* Digital Active - ppca.ppssio[29]:0 */
    P5_1_SCB1_SPI_CLK               = 16,       /* Digital Active - scb[1].spi_clk:0 */
    P5_1_SCB1_UART_RX               = 19,       /* Digital Active - scb[1].uart_rx:0 */
    P5_1_SCB1_I2C_SCL               = 21,       /* Digital Active - scb[1].i2c_scl:0 */
    P5_1_PERI_TR_IO_INPUT33         = 25,       /* Digital Active - peri.tr_io_input[33]:0 */
    P5_1_PERI_TR_IO_OUTPUT33        = 26,       /* Digital Active - peri.tr_io_output[33]:0 */
    P5_1_PERI_TR_IO_OUTPUT93        = 27,       /* Digital Active - peri.tr_io_output[93]:0 */

    /* P5.2 */
    P5_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_2_PPCA_PPSSIO14              =  8,       /* Digital Active - ppca.ppssio[14]:0 */
    P5_2_PERI_TR_IO_INPUT34         = 25,       /* Digital Active - peri.tr_io_input[34]:0 */
    P5_2_PERI_TR_IO_OUTPUT34        = 26,       /* Digital Active - peri.tr_io_output[34]:0 */
    P5_2_PERI_TR_IO_OUTPUT94        = 27,       /* Digital Active - peri.tr_io_output[94]:0 */

    /* P5.3 */
    P5_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_3_PPCA_PPSSIO15              =  8,       /* Digital Active - ppca.ppssio[15]:0 */
    P5_3_PERI_TR_IO_INPUT35         = 25,       /* Digital Active - peri.tr_io_input[35]:0 */
    P5_3_PERI_TR_IO_OUTPUT35        = 26,       /* Digital Active - peri.tr_io_output[35]:0 */
    P5_3_PERI_TR_IO_OUTPUT95        = 27,       /* Digital Active - peri.tr_io_output[95]:0 */

    /* P6.0 */
    P6_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_0_PPCA_PPSSIO16              =  8,       /* Digital Active - ppca.ppssio[16]:0 */
    P6_0_PERI_TR_IO_INPUT36         = 25,       /* Digital Active - peri.tr_io_input[36]:0 */
    P6_0_PERI_TR_IO_OUTPUT36        = 26,       /* Digital Active - peri.tr_io_output[36]:0 */
    P6_0_PERI_TR_IO_OUTPUT96        = 27,       /* Digital Active - peri.tr_io_output[96]:0 */

    /* P6.1 */
    P6_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_1_PPCA_PPSSIO17              =  8,       /* Digital Active - ppca.ppssio[17]:0 */
    P6_1_PERI_TR_IO_INPUT37         = 25,       /* Digital Active - peri.tr_io_input[37]:0 */
    P6_1_PERI_TR_IO_OUTPUT37        = 26,       /* Digital Active - peri.tr_io_output[37]:0 */
    P6_1_PERI_TR_IO_OUTPUT97        = 27,       /* Digital Active - peri.tr_io_output[97]:0 */

    /* P6.2 */
    P6_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_2_PPCA_PPSSIO18              =  8,       /* Digital Active - ppca.ppssio[18]:0 */
    P6_2_SCB4_SPI_SELECT0           = 17,       /* Digital Active - scb[4].spi_select0:1 */
    P6_2_SCB4_UART_CTS              = 20,       /* Digital Active - scb[4].uart_cts:1 */
    P6_2_SCB4_I2C_SDA_DO            = 22,       /* Digital Active - scb[4].i2c_sda_do:1 */
    P6_2_PERI_TR_IO_INPUT38         = 25,       /* Digital Active - peri.tr_io_input[38]:0 */
    P6_2_PERI_TR_IO_OUTPUT38        = 26,       /* Digital Active - peri.tr_io_output[38]:0 */
    P6_2_PERI_TR_IO_OUTPUT98        = 27,       /* Digital Active - peri.tr_io_output[98]:0 */

    /* P6.3 */
    P6_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_3_PPCA_PPSSIO19              =  8,       /* Digital Active - ppca.ppssio[19]:0 */
    P6_3_SCB4_SPI_MISO              = 17,       /* Digital Active - scb[4].spi_miso:1 */
    P6_3_SCB4_UART_RTS              = 20,       /* Digital Active - scb[4].uart_rts:1 */
    P6_3_SCB4_I2C_SCL_DO            = 22,       /* Digital Active - scb[4].i2c_scl_do:1 */
    P6_3_PERI_TR_IO_INPUT39         = 25,       /* Digital Active - peri.tr_io_input[39]:0 */
    P6_3_PERI_TR_IO_OUTPUT39        = 26,       /* Digital Active - peri.tr_io_output[39]:0 */
    P6_3_PERI_TR_IO_OUTPUT99        = 27,       /* Digital Active - peri.tr_io_output[99]:0 */

    /* P6.4 */
    P6_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_4_PPCA_PPSSIO46              =  8,       /* Digital Active - ppca.ppssio[46]:0 */
    P6_4_SCB4_SPI_MOSI              = 17,       /* Digital Active - scb[4].spi_mosi:1 */
    P6_4_SCB4_UART_TX               = 20,       /* Digital Active - scb[4].uart_tx:1 */
    P6_4_SCB4_I2C_SDA               = 21,       /* Digital Active - scb[4].i2c_sda:1 */
    P6_4_PERI_TR_IO_INPUT40         = 25,       /* Digital Active - peri.tr_io_input[40]:0 */
    P6_4_PERI_TR_IO_OUTPUT40        = 26,       /* Digital Active - peri.tr_io_output[40]:0 */
    P6_4_PERI_TR_IO_OUTPUT100       = 27,       /* Digital Active - peri.tr_io_output[100]:0 */

    /* P6.5 */
    P6_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_5_PPCA_PPSSIO47              =  8,       /* Digital Active - ppca.ppssio[47]:0 */
    P6_5_SCB4_SPI_CLK               = 17,       /* Digital Active - scb[4].spi_clk:1 */
    P6_5_SCB4_UART_RX               = 20,       /* Digital Active - scb[4].uart_rx:1 */
    P6_5_SCB4_I2C_SCL               = 21,       /* Digital Active - scb[4].i2c_scl:1 */
    P6_5_CPUSS_FAULT0               = 22,       /* Digital Active - cpuss.fault[0]:1 */
    P6_5_PERI_TR_IO_INPUT41         = 25,       /* Digital Active - peri.tr_io_input[41]:0 */
    P6_5_PERI_TR_IO_OUTPUT41        = 26,       /* Digital Active - peri.tr_io_output[41]:0 */
    P6_5_PERI_TR_IO_OUTPUT101       = 27,       /* Digital Active - peri.tr_io_output[101]:0 */

    /* P7.0 */
    P7_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_0_PPCA_PPSSIO32              =  8,       /* Digital Active - ppca.ppssio[32]:0 */
    P7_0_CANFD0_TTCAN_RX1           = 11,       /* Digital Active - canfd[0].ttcan_rx[1]:0 */
    P7_0_SCB5_SPI_CLK               = 18,       /* Digital Active - scb[5].spi_clk:0 */
    P7_0_SCB5_UART_RX               = 20,       /* Digital Active - scb[5].uart_rx:0 */
    P7_0_SCB5_I2C_SCL               = 21,       /* Digital Active - scb[5].i2c_scl:0 */
    P7_0_DEBUG600_TRACE_CLOCK       = 22,       /* Digital Active - debug600.trace_clock:1 */
    P7_0_PERI_TR_IO_INPUT42         = 25,       /* Digital Active - peri.tr_io_input[42]:0 */
    P7_0_PERI_TR_IO_OUTPUT42        = 26,       /* Digital Active - peri.tr_io_output[42]:0 */
    P7_0_PERI_TR_IO_OUTPUT102       = 27,       /* Digital Active - peri.tr_io_output[102]:0 */

    /* P7.1 */
    P7_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_1_PPCA_PPSSIO33              =  8,       /* Digital Active - ppca.ppssio[33]:0 */
    P7_1_CANFD0_TTCAN_TX1           = 11,       /* Digital Active - canfd[0].ttcan_tx[1]:0 */
    P7_1_SCB5_SPI_MOSI              = 18,       /* Digital Active - scb[5].spi_mosi:0 */
    P7_1_SCB5_UART_TX               = 20,       /* Digital Active - scb[5].uart_tx:0 */
    P7_1_SCB5_I2C_SDA               = 21,       /* Digital Active - scb[5].i2c_sda:0 */
    P7_1_DEBUG600_TRACE_DATA0       = 22,       /* Digital Active - debug600.trace_data[0]:1 */
    P7_1_PERI_TR_IO_INPUT43         = 25,       /* Digital Active - peri.tr_io_input[43]:0 */
    P7_1_PERI_TR_IO_OUTPUT43        = 26,       /* Digital Active - peri.tr_io_output[43]:0 */
    P7_1_PERI_TR_IO_OUTPUT103       = 27,       /* Digital Active - peri.tr_io_output[103]:0 */

    /* P7.2 */
    P7_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_2_PPCA_PPSSIO34              =  8,       /* Digital Active - ppca.ppssio[34]:0 */
    P7_2_SCB5_SPI_MISO              = 18,       /* Digital Active - scb[5].spi_miso:0 */
    P7_2_SCB5_UART_RTS              = 20,       /* Digital Active - scb[5].uart_rts:0 */
    P7_2_SCB5_I2C_SCL_DO            = 21,       /* Digital Active - scb[5].i2c_scl_do:0 */
    P7_2_DEBUG600_TRACE_DATA1       = 22,       /* Digital Active - debug600.trace_data[1]:1 */
    P7_2_SRSS_EXT_CLK               = 23,       /* Digital Active - srss.ext_clk:1 */
    P7_2_PERI_TR_IO_INPUT44         = 25,       /* Digital Active - peri.tr_io_input[44]:0 */
    P7_2_PERI_TR_IO_OUTPUT44        = 26,       /* Digital Active - peri.tr_io_output[44]:0 */
    P7_2_PERI_TR_IO_OUTPUT104       = 27,       /* Digital Active - peri.tr_io_output[104]:0 */

    /* P7.3 */
    P7_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_3_PPCA_PPSSIO35              =  8,       /* Digital Active - ppca.ppssio[35]:0 */
    P7_3_SCB5_SPI_SELECT0           = 18,       /* Digital Active - scb[5].spi_select0:0 */
    P7_3_SCB5_UART_CTS              = 20,       /* Digital Active - scb[5].uart_cts:0 */
    P7_3_SCB5_I2C_SDA_DO            = 21,       /* Digital Active - scb[5].i2c_sda_do:0 */
    P7_3_DEBUG600_TRACE_DATA2       = 22,       /* Digital Active - debug600.trace_data[2]:1 */
    P7_3_PERI_TR_IO_INPUT45         = 25,       /* Digital Active - peri.tr_io_input[45]:0 */
    P7_3_PERI_TR_IO_OUTPUT45        = 26,       /* Digital Active - peri.tr_io_output[45]:0 */
    P7_3_PERI_TR_IO_OUTPUT105       = 27,       /* Digital Active - peri.tr_io_output[105]:0 */

    /* P7.4 */
    P7_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_4_PPCA_PPSSIO36              =  8,       /* Digital Active - ppca.ppssio[36]:0 */
    P7_4_CANFD0_TTCAN_TX1           = 11,       /* Digital Active - canfd[0].ttcan_tx[1]:1 */
    P7_4_SCB5_SPI_SELECT1           = 18,       /* Digital Active - scb[5].spi_select1:0 */
    P7_4_DEBUG600_TRACE_DATA3       = 22,       /* Digital Active - debug600.trace_data[3]:1 */
    P7_4_PERI_TR_IO_INPUT46         = 25,       /* Digital Active - peri.tr_io_input[46]:0 */
    P7_4_PERI_TR_IO_OUTPUT46        = 26,       /* Digital Active - peri.tr_io_output[46]:0 */
    P7_4_PERI_TR_IO_OUTPUT106       = 27,       /* Digital Active - peri.tr_io_output[106]:0 */

    /* P7.5 */
    P7_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_5_PPCA_PPSSIO37              =  8,       /* Digital Active - ppca.ppssio[37]:0 */
    P7_5_CANFD0_TTCAN_RX1           = 11,       /* Digital Active - canfd[0].ttcan_rx[1]:1 */
    P7_5_SCB5_SPI_SELECT2           = 18,       /* Digital Active - scb[5].spi_select2:0 */
    P7_5_PERI_TR_IO_INPUT47         = 25,       /* Digital Active - peri.tr_io_input[47]:0 */
    P7_5_PERI_TR_IO_OUTPUT47        = 26,       /* Digital Active - peri.tr_io_output[47]:0 */
    P7_5_PERI_TR_IO_OUTPUT107       = 27,       /* Digital Active - peri.tr_io_output[107]:0 */

    /* P7.6 */
    P7_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_6_PPCA_PPSSIO38              =  8,       /* Digital Active - ppca.ppssio[38]:0 */
    P7_6_PERI_TR_IO_INPUT48         = 25,       /* Digital Active - peri.tr_io_input[48]:0 */
    P7_6_PERI_TR_IO_OUTPUT48        = 26,       /* Digital Active - peri.tr_io_output[48]:0 */
    P7_6_PERI_TR_IO_OUTPUT108       = 27,       /* Digital Active - peri.tr_io_output[108]:0 */

    /* P7.7 */
    P7_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_7_PPCA_PPSSIO39              =  8,       /* Digital Active - ppca.ppssio[39]:0 */
    P7_7_PERI_TR_IO_INPUT49         = 25,       /* Digital Active - peri.tr_io_input[49]:0 */
    P7_7_PERI_TR_IO_OUTPUT49        = 26,       /* Digital Active - peri.tr_io_output[49]:0 */
    P7_7_PERI_TR_IO_OUTPUT109       = 27,       /* Digital Active - peri.tr_io_output[109]:0 */

    /* P8.0 */
    P8_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_0_PPCA_PPSSIO0               =  8,       /* Digital Active - ppca.ppssio[0]:0 */
    P8_0_SCB3_SPI_CLK               = 16,       /* Digital Active - scb[3].spi_clk:0 */
    P8_0_SCB5_SPI_SELECT0           = 18,       /* Digital Active - scb[5].spi_select0:1 */
    P8_0_SCB3_UART_RX               = 19,       /* Digital Active - scb[3].uart_rx:0 */
    P8_0_SCB3_I2C_SCL               = 21,       /* Digital Active - scb[3].i2c_scl:0 */
    P8_0_DEBUG600_TRACE_DATA3       = 22,       /* Digital Active - debug600.trace_data[3]:0 */
    P8_0_CPUSS_CLK_FM_PUMP          = 23,       /* Digital Active - cpuss.clk_fm_pump */
    P8_0_PERI_TR_IO_INPUT50         = 25,       /* Digital Active - peri.tr_io_input[50]:0 */
    P8_0_PERI_TR_IO_OUTPUT50        = 26,       /* Digital Active - peri.tr_io_output[50]:0 */
    P8_0_PERI_TR_IO_OUTPUT110       = 27,       /* Digital Active - peri.tr_io_output[110]:0 */
    P8_0_IOSS_DDFT_PIN0             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[0]:1 */

    /* P8.1 */
    P8_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_1_PPCA_PPSSIO1               =  8,       /* Digital Active - ppca.ppssio[1]:0 */
    P8_1_SCB3_SPI_MOSI              = 16,       /* Digital Active - scb[3].spi_mosi:0 */
    P8_1_SCB5_SPI_SELECT1           = 18,       /* Digital Active - scb[5].spi_select1:1 */
    P8_1_SCB3_UART_TX               = 19,       /* Digital Active - scb[3].uart_tx:0 */
    P8_1_SCB3_I2C_SDA               = 21,       /* Digital Active - scb[3].i2c_sda:0 */
    P8_1_DEBUG600_TRACE_DATA2       = 22,       /* Digital Active - debug600.trace_data[2]:0 */
    P8_1_PERI_TR_IO_INPUT51         = 25,       /* Digital Active - peri.tr_io_input[51]:0 */
    P8_1_PERI_TR_IO_OUTPUT51        = 26,       /* Digital Active - peri.tr_io_output[51]:0 */
    P8_1_PERI_TR_IO_OUTPUT111       = 27,       /* Digital Active - peri.tr_io_output[111]:0 */
    P8_1_IOSS_DDFT_PIN1             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[1]:1 */

    /* P8.2 */
    P8_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_2_PPCA_PPSSIO2               =  8,       /* Digital Active - ppca.ppssio[2]:0 */
    P8_2_SCB3_SPI_MISO              = 16,       /* Digital Active - scb[3].spi_miso:0 */
    P8_2_SCB5_SPI_SELECT2           = 18,       /* Digital Active - scb[5].spi_select2:1 */
    P8_2_SCB3_UART_RTS              = 19,       /* Digital Active - scb[3].uart_rts:0 */
    P8_2_SCB3_I2C_SCL_DO            = 21,       /* Digital Active - scb[3].i2c_scl_do:0 */
    P8_2_DEBUG600_TRACE_DATA1       = 22,       /* Digital Active - debug600.trace_data[1]:0 */
    P8_2_PERI_TR_IO_INPUT52         = 25,       /* Digital Active - peri.tr_io_input[52]:0 */
    P8_2_PERI_TR_IO_OUTPUT52        = 26,       /* Digital Active - peri.tr_io_output[52]:0 */
    P8_2_PERI_TR_IO_OUTPUT112       = 27,       /* Digital Active - peri.tr_io_output[112]:0 */

    /* P8.3 */
    P8_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_3_PPCA_PPSSIO3               =  8,       /* Digital Active - ppca.ppssio[3]:0 */
    P8_3_SCB3_SPI_SELECT0           = 16,       /* Digital Active - scb[3].spi_select0:0 */
    P8_3_SCB3_UART_CTS              = 19,       /* Digital Active - scb[3].uart_cts:0 */
    P8_3_SCB3_I2C_SDA_DO            = 21,       /* Digital Active - scb[3].i2c_sda_do:0 */
    P8_3_DEBUG600_TRACE_DATA0       = 22,       /* Digital Active - debug600.trace_data[0]:0 */
    P8_3_SRSS_EXT_CLK               = 23,       /* Digital Active - srss.ext_clk:0 */
    P8_3_SRSS_DDFT_CLK_DIRECT       = 24,       /* Digital Active - srss.ddft_clk_direct */
    P8_3_PERI_TR_IO_INPUT53         = 25,       /* Digital Active - peri.tr_io_input[53]:0 */
    P8_3_PERI_TR_IO_OUTPUT53        = 26,       /* Digital Active - peri.tr_io_output[53]:0 */
    P8_3_PERI_TR_IO_OUTPUT113       = 27,       /* Digital Active - peri.tr_io_output[113]:0 */
    P8_3_IOSS_DDFT_PIN1             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[1]:0 */

    /* P8.4 */
    P8_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_4_PPCA_PPSSIO4               =  8,       /* Digital Active - ppca.ppssio[4]:0 */
    P8_4_SCB3_SPI_SELECT1           = 16,       /* Digital Active - scb[3].spi_select1:0 */
    P8_4_DEBUG600_TRACE_CLOCK       = 22,       /* Digital Active - debug600.trace_clock:0 */
    P8_4_PERI_TR_IO_INPUT54         = 25,       /* Digital Active - peri.tr_io_input[54]:0 */
    P8_4_PERI_TR_IO_OUTPUT54        = 26,       /* Digital Active - peri.tr_io_output[54]:0 */
    P8_4_PERI_TR_IO_OUTPUT114       = 27,       /* Digital Active - peri.tr_io_output[114]:0 */

    /* P8.5 */
    P8_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_5_PPCA_PPSSIO5               =  8,       /* Digital Active - ppca.ppssio[5]:0 */
    P8_5_SCB3_SPI_SELECT2           = 16,       /* Digital Active - scb[3].spi_select2:0 */
    P8_5_CPUSS_FAULT0               = 22,       /* Digital Active - cpuss.fault[0]:0 */
    P8_5_PERI_TR_IO_INPUT55         = 25,       /* Digital Active - peri.tr_io_input[55]:0 */
    P8_5_PERI_TR_IO_OUTPUT55        = 26,       /* Digital Active - peri.tr_io_output[55]:0 */
    P8_5_PERI_TR_IO_OUTPUT115       = 27,       /* Digital Active - peri.tr_io_output[115]:0 */

    /* P9.0 */
    P9_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_0_PPCA_PPSSIO6               =  8,       /* Digital Active - ppca.ppssio[6]:0 */
    P9_0_PERI_TR_IO_INPUT56         = 25,       /* Digital Active - peri.tr_io_input[56]:0 */
    P9_0_PERI_TR_IO_OUTPUT56        = 26,       /* Digital Active - peri.tr_io_output[56]:0 */
    P9_0_PERI_TR_IO_OUTPUT116       = 27,       /* Digital Active - peri.tr_io_output[116]:0 */

    /* P9.1 */
    P9_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_1_PPCA_PPSSIO7               =  8,       /* Digital Active - ppca.ppssio[7]:0 */
    P9_1_PERI_TR_IO_INPUT57         = 25,       /* Digital Active - peri.tr_io_input[57]:0 */
    P9_1_PERI_TR_IO_OUTPUT57        = 26,       /* Digital Active - peri.tr_io_output[57]:0 */
    P9_1_PERI_TR_IO_OUTPUT117       = 27,       /* Digital Active - peri.tr_io_output[117]:0 */

    /* P9.2 */
    P9_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_2_PPCA_PPSSIO8               =  8,       /* Digital Active - ppca.ppssio[8]:0 */
    P9_2_PERI_TR_IO_INPUT58         = 25,       /* Digital Active - peri.tr_io_input[58]:0 */
    P9_2_PERI_TR_IO_OUTPUT58        = 26,       /* Digital Active - peri.tr_io_output[58]:0 */
    P9_2_PERI_TR_IO_OUTPUT118       = 27,       /* Digital Active - peri.tr_io_output[118]:0 */

    /* P9.3 */
    P9_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_3_PPCA_PPSSIO9               =  8,       /* Digital Active - ppca.ppssio[9]:0 */
    P9_3_PERI_TR_IO_INPUT59         = 25,       /* Digital Active - peri.tr_io_input[59]:0 */
    P9_3_PERI_TR_IO_OUTPUT59        = 26,       /* Digital Active - peri.tr_io_output[59]:0 */
    P9_3_PERI_TR_IO_OUTPUT119       = 27        /* Digital Active - peri.tr_io_output[119]:0 */
} en_hsiom_sel_t;

#endif /* _GPIO_PSC3_P8_PG_E_LQFP100L_H_ */


/* [] END OF FILE */
