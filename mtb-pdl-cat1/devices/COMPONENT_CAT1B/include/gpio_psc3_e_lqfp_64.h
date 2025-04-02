/***************************************************************************//**
* \file gpio_psc3_e_lqfp_64.h
*
* \brief
* PSC3 device GPIO header for E-LQFP-64 package
*
********************************************************************************
* \copyright
* (c) (2016-2024), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _GPIO_PSC3_E_LQFP_64_H_
#define _GPIO_PSC3_E_LQFP_64_H_

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
#define CY_GPIO_PIN_COUNT               64u

/* AMUXBUS Segments */
enum
{
    AMUXBUS_CHIP,
    AMUXBUS_FLASH,
    AMUXBUS_LPCOMP,
    AMUXBUS_SRSS,
    AMUXBUS_TEST,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_0                = 0x0000u,  /* Left = AMUXBUS_CHIP; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_1                = 0x0001u,  /* Left = AMUXBUS_SRSS; Right = AMUXBUS_CHIP */
    AMUX_SPLIT_CTL_2                = 0x0002u,  /* Left = AMUXBUS_LPCOMP; Right = AMUXBUS_CHIP */
    AMUX_SPLIT_CTL_3                = 0x0003u   /* Left = AMUXBUS_FLASH; Right = AMUXBUS_CHIP */
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

/* PORT 2 (GPIO) */
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
#define IOSS_ADFT0_NET0_PORT            9u
#define IOSS_ADFT0_NET0_PIN             2u
#define IOSS_ADFT1_NET0_PORT            9u
#define IOSS_ADFT1_NET0_PIN             3u
#define LPCOMP_INN_COMP0_PORT           8u
#define LPCOMP_INN_COMP0_PIN            1u
#define LPCOMP_INN_COMP1_PORT           8u
#define LPCOMP_INN_COMP1_PIN            3u
#define LPCOMP_INP_COMP0_PORT           8u
#define LPCOMP_INP_COMP0_PIN            0u
#define LPCOMP_INP_COMP1_PORT           8u
#define LPCOMP_INP_COMP1_PIN            2u
#define PASS_GPIO_00_AIO_PORT           8u
#define PASS_GPIO_00_AIO_PIN            0u
#define PASS_GPIO_01_AIO_PORT           8u
#define PASS_GPIO_01_AIO_PIN            2u
#define SRSS_ECO_IN_PORT                1u
#define SRSS_ECO_IN_PIN                 0u
#define SRSS_ECO_OUT_PORT               1u
#define SRSS_ECO_OUT_PIN                1u
#define SRSS_WCO_IN_PORT                0u
#define SRSS_WCO_IN_PIN                 1u
#define SRSS_WCO_OUT_PORT               0u
#define SRSS_WCO_OUT_PIN                0u

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
    P0_0_SRSS_EXT_CLK               = 20,       /* Digital Active - srss.ext_clk:0 */
    P0_0_SRSS_DDFT_CLK_DIRECT       = 24,       /* Digital Active - srss.ddft_clk_direct */
    P0_0_PERI_TR_IO_INPUT0          = 26,       /* Digital Active - peri.tr_io_input[0]:0 */
    P0_0_PERI_TR_IO_OUTPUT0         = 27,       /* Digital Active - peri.tr_io_output[0]:0 */
    P0_0_IOSS_DDFT_PIN1             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[1]:0 */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_1_PERI_TR_IO_INPUT1          = 26,       /* Digital Active - peri.tr_io_input[1]:0 */
    P0_1_PERI_TR_IO_OUTPUT1         = 27,       /* Digital Active - peri.tr_io_output[1]:0 */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_0_PERI_TR_IO_OUTPUT58        =  9,       /* Digital Active - peri.tr_io_output[58]:1 */
    P1_0_PERI_TR_IO_OUTPUT70        = 10,       /* Digital Active - peri.tr_io_output[70]:1 */
    P1_0_SCB1_UART_CTS              = 16,       /* Digital Active - scb[1].uart_cts:0 */
    P1_0_SCB1_SPI_SELECT0           = 18,       /* Digital Active - scb[1].spi_select0:0 */
    P1_0_PERI_TR_IO_INPUT2          = 26,       /* Digital Active - peri.tr_io_input[2]:0 */
    P1_0_PERI_TR_IO_OUTPUT2         = 27,       /* Digital Active - peri.tr_io_output[2]:0 */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_1_PERI_TR_IO_OUTPUT59        =  9,       /* Digital Active - peri.tr_io_output[59]:1 */
    P1_1_PERI_TR_IO_OUTPUT71        = 10,       /* Digital Active - peri.tr_io_output[71]:1 */
    P1_1_SCB1_UART_RTS              = 16,       /* Digital Active - scb[1].uart_rts:0 */
    P1_1_SCB1_SPI_CLK               = 18,       /* Digital Active - scb[1].spi_clk:0 */
    P1_1_PERI_TR_IO_INPUT3          = 26,       /* Digital Active - peri.tr_io_input[3]:0 */
    P1_1_PERI_TR_IO_OUTPUT3         = 27,       /* Digital Active - peri.tr_io_output[3]:0 */

    /* P1.2 */
    P1_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_2_PERI_TR_IO_OUTPUT60        =  9,       /* Digital Active - peri.tr_io_output[60]:1 */
    P1_2_PERI_TR_IO_OUTPUT72        = 10,       /* Digital Active - peri.tr_io_output[72]:1 */
    P1_2_SCB1_UART_RX               = 16,       /* Digital Active - scb[1].uart_rx:0 */
    P1_2_SCB1_SPI_MOSI              = 18,       /* Digital Active - scb[1].spi_mosi:0 */
    P1_2_SCB1_I2C_SDA               = 19,       /* Digital Active - scb[1].i2c_sda:0 */
    P1_2_PERI_TR_IO_INPUT4          = 26,       /* Digital Active - peri.tr_io_input[4]:0 */
    P1_2_PERI_TR_IO_OUTPUT4         = 27,       /* Digital Active - peri.tr_io_output[4]:0 */
    P1_2_DEBUG600_CLK_SWJ_SWCLK_TCLK = 29,      /* Digital Deep Sleep - debug600.clk_swj_swclk_tclk */

    /* P1.3 */
    P1_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_3_PERI_TR_IO_OUTPUT61        =  9,       /* Digital Active - peri.tr_io_output[61]:1 */
    P1_3_PERI_TR_IO_OUTPUT73        = 10,       /* Digital Active - peri.tr_io_output[73]:1 */
    P1_3_SCB1_UART_TX               = 16,       /* Digital Active - scb[1].uart_tx:0 */
    P1_3_SCB1_SPI_MISO              = 18,       /* Digital Active - scb[1].spi_miso:0 */
    P1_3_SCB1_I2C_SCL               = 19,       /* Digital Active - scb[1].i2c_scl:0 */
    P1_3_PERI_TR_IO_INPUT5          = 26,       /* Digital Active - peri.tr_io_input[5]:0 */
    P1_3_PERI_TR_IO_OUTPUT5         = 27,       /* Digital Active - peri.tr_io_output[5]:0 */
    P1_3_DEBUG600_SWJ_SWDIO_TMS     = 29,       /* Digital Deep Sleep - debug600.swj_swdio_tms */

    /* P2.0 */
    P2_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_0_PERI_TR_IO_OUTPUT58        =  9,       /* Digital Active - peri.tr_io_output[58]:0 */
    P2_0_TCPWM0_LINE518             = 10,       /* Digital Active - tcpwm[0].line[518]:1 */
    P2_0_SCB1_UART_CTS              = 16,       /* Digital Active - scb[1].uart_cts:1 */
    P2_0_SCB1_SPI_SELECT0           = 18,       /* Digital Active - scb[1].spi_select0:1 */
    P2_0_PERI_TR_IO_INPUT6          = 26,       /* Digital Active - peri.tr_io_input[6]:0 */
    P2_0_PERI_TR_IO_OUTPUT6         = 27,       /* Digital Active - peri.tr_io_output[6]:0 */
    P2_0_DEBUG600_SWJ_SWDOE_TDI     = 29,       /* Digital Deep Sleep - debug600.swj_swdoe_tdi */
    P2_0_IOSS_DDFT_PIN0             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[0]:0 */

    /* P2.1 */
    P2_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_1_PERI_TR_IO_OUTPUT59        =  9,       /* Digital Active - peri.tr_io_output[59]:0 */
    P2_1_TCPWM0_LINE_COMPL518       = 10,       /* Digital Active - tcpwm[0].line_compl[518]:1 */
    P2_1_SRSS_CAL_WAVE              = 12,       /* Digital Deep Sleep - srss.cal_wave */
    P2_1_SCB1_UART_RTS              = 16,       /* Digital Active - scb[1].uart_rts:1 */
    P2_1_SCB1_SPI_CLK               = 18,       /* Digital Active - scb[1].spi_clk:1 */
    P2_1_SCB1_I2C_SCL               = 19,       /* Digital Active - scb[1].i2c_scl:1 */
    P2_1_PERI_TR_IO_INPUT7          = 26,       /* Digital Active - peri.tr_io_input[7]:0 */
    P2_1_PERI_TR_IO_OUTPUT7         = 27,       /* Digital Active - peri.tr_io_output[7]:0 */
    P2_1_DEBUG600_SWJ_SWO_TDO       = 29,       /* Digital Deep Sleep - debug600.swj_swo_tdo */

    /* P2.2 */
    P2_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_2_PERI_TR_IO_OUTPUT60        =  9,       /* Digital Active - peri.tr_io_output[60]:0 */
    P2_2_TCPWM0_LINE519             = 10,       /* Digital Active - tcpwm[0].line[519]:1 */
    P2_2_SCB1_UART_RX               = 16,       /* Digital Active - scb[1].uart_rx:1 */
    P2_2_SCB1_SPI_MOSI              = 18,       /* Digital Active - scb[1].spi_mosi:1 */
    P2_2_SCB1_I2C_SDA               = 19,       /* Digital Active - scb[1].i2c_sda:1 */
    P2_2_SRSS_EXT_CLK               = 20,       /* Digital Active - srss.ext_clk:1 */
    P2_2_PERI_TR_IO_INPUT8          = 26,       /* Digital Active - peri.tr_io_input[8]:0 */
    P2_2_PERI_TR_IO_OUTPUT8         = 27,       /* Digital Active - peri.tr_io_output[8]:0 */

    /* P2.3 */
    P2_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_3_PERI_TR_IO_OUTPUT61        =  9,       /* Digital Active - peri.tr_io_output[61]:0 */
    P2_3_TCPWM0_LINE_COMPL519       = 10,       /* Digital Active - tcpwm[0].line_compl[519]:1 */
    P2_3_SCB1_UART_TX               = 16,       /* Digital Active - scb[1].uart_tx:1 */
    P2_3_SCB1_SPI_MISO              = 18,       /* Digital Active - scb[1].spi_miso:1 */
    P2_3_PERI_TR_IO_INPUT9          = 26,       /* Digital Active - peri.tr_io_input[9]:0 */
    P2_3_PERI_TR_IO_OUTPUT9         = 27,       /* Digital Active - peri.tr_io_output[9]:0 */

    /* P4.0 */
    P4_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_0_PERI_TR_IO_OUTPUT50        =  8,       /* Digital Active - peri.tr_io_output[50]:0 */
    P4_0_TCPWM0_LINE260             =  9,       /* Digital Active - tcpwm[0].line[260]:0 */
    P4_0_SCB4_UART_CTS              = 16,       /* Digital Active - scb[4].uart_cts:1 */
    P4_0_SCB4_SPI_MOSI              = 18,       /* Digital Active - scb[4].spi_mosi:1 */
    P4_0_PERI_TR_IO_INPUT14         = 26,       /* Digital Active - peri.tr_io_input[14]:0 */
    P4_0_PERI_TR_IO_OUTPUT14        = 27,       /* Digital Active - peri.tr_io_output[14]:0 */

    /* P4.1 */
    P4_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_1_PERI_TR_IO_OUTPUT51        =  8,       /* Digital Active - peri.tr_io_output[51]:0 */
    P4_1_TCPWM0_LINE_COMPL260       =  9,       /* Digital Active - tcpwm[0].line_compl[260]:0 */
    P4_1_SCB4_UART_RTS              = 16,       /* Digital Active - scb[4].uart_rts:1 */
    P4_1_SCB4_SPI_MISO              = 18,       /* Digital Active - scb[4].spi_miso:1 */
    P4_1_SCB4_I2C_SDA               = 19,       /* Digital Active - scb[4].i2c_sda:1 */
    P4_1_PERI_TR_IO_INPUT15         = 26,       /* Digital Active - peri.tr_io_input[15]:0 */
    P4_1_PERI_TR_IO_OUTPUT15        = 27,       /* Digital Active - peri.tr_io_output[15]:0 */

    /* P4.2 */
    P4_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_2_PERI_TR_IO_OUTPUT52        =  8,       /* Digital Active - peri.tr_io_output[52]:0 */
    P4_2_TCPWM0_LINE261             =  9,       /* Digital Active - tcpwm[0].line[261]:0 */
    P4_2_SCB4_UART_RX               = 16,       /* Digital Active - scb[4].uart_rx:1 */
    P4_2_SCB4_SPI_CLK               = 18,       /* Digital Active - scb[4].spi_clk:1 */
    P4_2_SCB4_I2C_SCL               = 19,       /* Digital Active - scb[4].i2c_scl:1 */
    P4_2_PERI_TR_IO_INPUT16         = 26,       /* Digital Active - peri.tr_io_input[16]:0 */
    P4_2_PERI_TR_IO_OUTPUT16        = 27,       /* Digital Active - peri.tr_io_output[16]:0 */

    /* P4.3 */
    P4_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_3_PERI_TR_IO_OUTPUT53        =  8,       /* Digital Active - peri.tr_io_output[53]:0 */
    P4_3_TCPWM0_LINE_COMPL261       =  9,       /* Digital Active - tcpwm[0].line_compl[261]:0 */
    P4_3_SCB4_UART_TX               = 16,       /* Digital Active - scb[4].uart_tx:1 */
    P4_3_SCB4_SPI_SELECT0           = 18,       /* Digital Active - scb[4].spi_select0:1 */
    P4_3_PERI_TR_IO_INPUT17         = 26,       /* Digital Active - peri.tr_io_input[17]:0 */
    P4_3_PERI_TR_IO_OUTPUT17        = 27,       /* Digital Active - peri.tr_io_output[17]:0 */

    /* P4.4 */
    P4_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_4_PERI_TR_IO_OUTPUT54        =  8,       /* Digital Active - peri.tr_io_output[54]:0 */
    P4_4_TCPWM0_LINE262             =  9,       /* Digital Active - tcpwm[0].line[262]:0 */
    P4_4_PERI_TR_IO_INPUT18         = 26,       /* Digital Active - peri.tr_io_input[18]:0 */
    P4_4_PERI_TR_IO_OUTPUT18        = 27,       /* Digital Active - peri.tr_io_output[18]:0 */

    /* P4.5 */
    P4_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_5_PERI_TR_IO_OUTPUT55        =  8,       /* Digital Active - peri.tr_io_output[55]:0 */
    P4_5_TCPWM0_LINE_COMPL262       =  9,       /* Digital Active - tcpwm[0].line_compl[262]:0 */
    P4_5_PERI_TR_IO_INPUT19         = 26,       /* Digital Active - peri.tr_io_input[19]:0 */
    P4_5_PERI_TR_IO_OUTPUT19        = 27,       /* Digital Active - peri.tr_io_output[19]:0 */

    /* P4.6 */
    P4_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_6_PERI_TR_IO_OUTPUT56        =  8,       /* Digital Active - peri.tr_io_output[56]:0 */
    P4_6_TCPWM0_LINE263             =  9,       /* Digital Active - tcpwm[0].line[263]:0 */
    P4_6_PERI_TR_IO_INPUT20         = 26,       /* Digital Active - peri.tr_io_input[20]:0 */
    P4_6_PERI_TR_IO_OUTPUT20        = 27,       /* Digital Active - peri.tr_io_output[20]:0 */

    /* P4.7 */
    P4_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_7_PERI_TR_IO_OUTPUT57        =  8,       /* Digital Active - peri.tr_io_output[57]:0 */
    P4_7_TCPWM0_LINE_COMPL263       =  9,       /* Digital Active - tcpwm[0].line_compl[263]:0 */
    P4_7_PERI_TR_IO_INPUT21         = 26,       /* Digital Active - peri.tr_io_input[21]:0 */
    P4_7_PERI_TR_IO_OUTPUT21        = 27,       /* Digital Active - peri.tr_io_output[21]:0 */

    /* P5.0 */
    P5_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_0_PERI_TR_IO_OUTPUT62        =  9,       /* Digital Active - peri.tr_io_output[62]:1 */
    P5_0_SCB3_UART_CTS              = 16,       /* Digital Active - scb[3].uart_cts:0 */
    P5_0_SCB3_SPI_MOSI              = 18,       /* Digital Active - scb[3].spi_mosi:0 */
    P5_0_SCB3_I2C_SDA               = 19,       /* Digital Active - scb[3].i2c_sda:0 */
    P5_0_PERI_TR_IO_INPUT22         = 26,       /* Digital Active - peri.tr_io_input[22]:0 */
    P5_0_PERI_TR_IO_OUTPUT22        = 27,       /* Digital Active - peri.tr_io_output[22]:0 */

    /* P5.1 */
    P5_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_1_PERI_TR_IO_OUTPUT63        =  9,       /* Digital Active - peri.tr_io_output[63]:1 */
    P5_1_SCB3_UART_RTS              = 16,       /* Digital Active - scb[3].uart_rts:0 */
    P5_1_SCB3_SPI_MISO              = 18,       /* Digital Active - scb[3].spi_miso:0 */
    P5_1_SCB3_I2C_SCL               = 19,       /* Digital Active - scb[3].i2c_scl:0 */
    P5_1_PERI_TR_IO_INPUT23         = 26,       /* Digital Active - peri.tr_io_input[23]:0 */
    P5_1_PERI_TR_IO_OUTPUT23        = 27,       /* Digital Active - peri.tr_io_output[23]:0 */

    /* P5.2 */
    P5_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_2_PERI_TR_IO_OUTPUT64        =  9,       /* Digital Active - peri.tr_io_output[64]:1 */
    P5_2_CANFD0_TTCAN_RX1           = 11,       /* Digital Active - canfd[0].ttcan_rx[1]:0 */
    P5_2_SCB3_UART_RX               = 16,       /* Digital Active - scb[3].uart_rx:0 */
    P5_2_SCB3_SPI_CLK               = 18,       /* Digital Active - scb[3].spi_clk:0 */
    P5_2_PERI_TR_IO_INPUT24         = 26,       /* Digital Active - peri.tr_io_input[24]:0 */
    P5_2_PERI_TR_IO_OUTPUT24        = 27,       /* Digital Active - peri.tr_io_output[24]:0 */

    /* P5.3 */
    P5_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_3_PERI_TR_IO_OUTPUT65        =  9,       /* Digital Active - peri.tr_io_output[65]:1 */
    P5_3_CANFD0_TTCAN_TX1           = 11,       /* Digital Active - canfd[0].ttcan_tx[1]:0 */
    P5_3_SCB3_UART_TX               = 16,       /* Digital Active - scb[3].uart_tx:0 */
    P5_3_SCB3_SPI_SELECT0           = 18,       /* Digital Active - scb[3].spi_select0:0 */
    P5_3_PERI_TR_IO_INPUT25         = 26,       /* Digital Active - peri.tr_io_input[25]:0 */
    P5_3_PERI_TR_IO_OUTPUT25        = 27,       /* Digital Active - peri.tr_io_output[25]:0 */

    /* P6.0 */
    P6_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_0_TCPWM0_LINE260             =  9,       /* Digital Active - tcpwm[0].line[260]:1 */
    P6_0_PERI_TR_IO_OUTPUT66        = 10,       /* Digital Active - peri.tr_io_output[66]:0 */
    P6_0_SCB3_UART_CTS              = 16,       /* Digital Active - scb[3].uart_cts:1 */
    P6_0_SCB3_SPI_MOSI              = 18,       /* Digital Active - scb[3].spi_mosi:1 */
    P6_0_SCB3_I2C_SDA               = 19,       /* Digital Active - scb[3].i2c_sda:1 */
    P6_0_PERI_TR_IO_INPUT26         = 26,       /* Digital Active - peri.tr_io_input[26]:0 */
    P6_0_PERI_TR_IO_OUTPUT26        = 27,       /* Digital Active - peri.tr_io_output[26]:0 */

    /* P6.1 */
    P6_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_1_TCPWM0_LINE_COMPL260       =  9,       /* Digital Active - tcpwm[0].line_compl[260]:1 */
    P6_1_PERI_TR_IO_OUTPUT67        = 10,       /* Digital Active - peri.tr_io_output[67]:0 */
    P6_1_SCB3_UART_RTS              = 16,       /* Digital Active - scb[3].uart_rts:1 */
    P6_1_SCB3_SPI_MISO              = 18,       /* Digital Active - scb[3].spi_miso:1 */
    P6_1_SCB3_I2C_SCL               = 19,       /* Digital Active - scb[3].i2c_scl:1 */
    P6_1_PERI_TR_IO_INPUT27         = 26,       /* Digital Active - peri.tr_io_input[27]:0 */
    P6_1_PERI_TR_IO_OUTPUT27        = 27,       /* Digital Active - peri.tr_io_output[27]:0 */

    /* P6.2 */
    P6_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_2_TCPWM0_LINE261             =  9,       /* Digital Active - tcpwm[0].line[261]:1 */
    P6_2_PERI_TR_IO_OUTPUT68        = 10,       /* Digital Active - peri.tr_io_output[68]:0 */
    P6_2_CANFD0_TTCAN_RX1           = 11,       /* Digital Active - canfd[0].ttcan_rx[1]:1 */
    P6_2_SCB3_UART_RX               = 16,       /* Digital Active - scb[3].uart_rx:1 */
    P6_2_SCB3_SPI_CLK               = 18,       /* Digital Active - scb[3].spi_clk:1 */
    P6_2_PERI_TR_IO_INPUT28         = 26,       /* Digital Active - peri.tr_io_input[28]:0 */
    P6_2_PERI_TR_IO_OUTPUT28        = 27,       /* Digital Active - peri.tr_io_output[28]:0 */

    /* P6.3 */
    P6_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_3_TCPWM0_LINE_COMPL261       =  9,       /* Digital Active - tcpwm[0].line_compl[261]:1 */
    P6_3_PERI_TR_IO_OUTPUT69        = 10,       /* Digital Active - peri.tr_io_output[69]:0 */
    P6_3_CANFD0_TTCAN_TX1           = 11,       /* Digital Active - canfd[0].ttcan_tx[1]:1 */
    P6_3_SCB3_UART_TX               = 16,       /* Digital Active - scb[3].uart_tx:1 */
    P6_3_SCB3_SPI_SELECT0           = 18,       /* Digital Active - scb[3].spi_select0:1 */
    P6_3_CPUSS_FAULT0               = 21,       /* Digital Active - cpuss.fault[0]:1 */
    P6_3_PERI_TR_IO_INPUT29         = 26,       /* Digital Active - peri.tr_io_input[29]:0 */
    P6_3_PERI_TR_IO_OUTPUT29        = 27,       /* Digital Active - peri.tr_io_output[29]:0 */

    /* P7.0 */
    P7_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_0_PERI_TR_IO_OUTPUT50        =  8,       /* Digital Active - peri.tr_io_output[50]:1 */
    P7_0_TCPWM0_LINE262             =  9,       /* Digital Active - tcpwm[0].line[262]:1 */
    P7_0_PERI_TR_IO_OUTPUT70        = 10,       /* Digital Active - peri.tr_io_output[70]:0 */
    P7_0_SCB2_UART_CTS              = 16,       /* Digital Active - scb[2].uart_cts:0 */
    P7_0_SCB2_SPI_CLK               = 17,       /* Digital Active - scb[2].spi_clk:0 */
    P7_0_SCB2_I2C_SCL               = 19,       /* Digital Active - scb[2].i2c_scl:0 */
    P7_0_DEBUG600_TRACE_DATA0       = 21,       /* Digital Active - debug600.trace_data[0]:0 */
    P7_0_PASS_MCPASS_DOUT0          = 24,       /* Digital Active - pass.mcpass_dout[0]:0 */
    P7_0_PERI_TR_IO_INPUT30         = 26,       /* Digital Active - peri.tr_io_input[30]:0 */
    P7_0_PERI_TR_IO_OUTPUT30        = 27,       /* Digital Active - peri.tr_io_output[30]:0 */

    /* P7.1 */
    P7_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_1_PERI_TR_IO_OUTPUT51        =  8,       /* Digital Active - peri.tr_io_output[51]:1 */
    P7_1_TCPWM0_LINE_COMPL262       =  9,       /* Digital Active - tcpwm[0].line_compl[262]:1 */
    P7_1_PERI_TR_IO_OUTPUT71        = 10,       /* Digital Active - peri.tr_io_output[71]:0 */
    P7_1_SCB2_UART_TX               = 16,       /* Digital Active - scb[2].uart_tx:0 */
    P7_1_SCB2_SPI_MOSI              = 17,       /* Digital Active - scb[2].spi_mosi:0 */
    P7_1_SCB2_I2C_SDA               = 19,       /* Digital Active - scb[2].i2c_sda:0 */
    P7_1_DEBUG600_TRACE_DATA1       = 21,       /* Digital Active - debug600.trace_data[1]:0 */
    P7_1_PASS_MCPASS_DOUT1          = 24,       /* Digital Active - pass.mcpass_dout[1]:0 */
    P7_1_PERI_TR_IO_INPUT31         = 26,       /* Digital Active - peri.tr_io_input[31]:0 */
    P7_1_PERI_TR_IO_OUTPUT31        = 27,       /* Digital Active - peri.tr_io_output[31]:0 */

    /* P7.2 */
    P7_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_2_PERI_TR_IO_OUTPUT52        =  8,       /* Digital Active - peri.tr_io_output[52]:1 */
    P7_2_TCPWM0_LINE263             =  9,       /* Digital Active - tcpwm[0].line[263]:1 */
    P7_2_PERI_TR_IO_OUTPUT72        = 10,       /* Digital Active - peri.tr_io_output[72]:0 */
    P7_2_SCB2_UART_RX               = 16,       /* Digital Active - scb[2].uart_rx:0 */
    P7_2_SCB2_SPI_MISO              = 17,       /* Digital Active - scb[2].spi_miso:0 */
    P7_2_DEBUG600_TRACE_DATA2       = 21,       /* Digital Active - debug600.trace_data[2]:0 */
    P7_2_PASS_MCPASS_DOUT2          = 24,       /* Digital Active - pass.mcpass_dout[2]:0 */
    P7_2_PERI_TR_IO_INPUT32         = 26,       /* Digital Active - peri.tr_io_input[32]:0 */
    P7_2_PERI_TR_IO_OUTPUT32        = 27,       /* Digital Active - peri.tr_io_output[32]:0 */

    /* P7.3 */
    P7_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_3_PERI_TR_IO_OUTPUT53        =  8,       /* Digital Active - peri.tr_io_output[53]:1 */
    P7_3_TCPWM0_LINE_COMPL263       =  9,       /* Digital Active - tcpwm[0].line_compl[263]:1 */
    P7_3_PERI_TR_IO_OUTPUT73        = 10,       /* Digital Active - peri.tr_io_output[73]:0 */
    P7_3_SCB2_UART_RTS              = 16,       /* Digital Active - scb[2].uart_rts:0 */
    P7_3_SCB2_SPI_SELECT0           = 17,       /* Digital Active - scb[2].spi_select0:0 */
    P7_3_DEBUG600_TRACE_DATA3       = 21,       /* Digital Active - debug600.trace_data[3]:0 */
    P7_3_PASS_MCPASS_DOUT3          = 24,       /* Digital Active - pass.mcpass_dout[3]:0 */
    P7_3_PERI_TR_IO_INPUT33         = 26,       /* Digital Active - peri.tr_io_input[33]:0 */
    P7_3_PERI_TR_IO_OUTPUT33        = 27,       /* Digital Active - peri.tr_io_output[33]:0 */

    /* P7.4 */
    P7_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_4_PERI_TR_IO_OUTPUT54        =  8,       /* Digital Active - peri.tr_io_output[54]:1 */
    P7_4_SCB2_SPI_SELECT1           = 17,       /* Digital Active - scb[2].spi_select1:0 */
    P7_4_DEBUG600_TRACE_CLOCK       = 21,       /* Digital Active - debug600.trace_clock:0 */
    P7_4_PASS_MCPASS_DCLK           = 24,       /* Digital Active - pass.mcpass_dclk:0 */
    P7_4_PERI_TR_IO_INPUT34         = 26,       /* Digital Active - peri.tr_io_input[34]:0 */
    P7_4_PERI_TR_IO_OUTPUT34        = 27,       /* Digital Active - peri.tr_io_output[34]:0 */

    /* P8.0 */
    P8_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_0_PERI_TR_IO_OUTPUT62        =  9,       /* Digital Active - peri.tr_io_output[62]:2 */
    P8_0_TCPWM0_LINE516             = 10,       /* Digital Active - tcpwm[0].line[516]:0 */
    P8_0_SCB5_UART_CTS              = 16,       /* Digital Active - scb[5].uart_cts:0 */
    P8_0_SCB5_SPI_SELECT0           = 17,       /* Digital Active - scb[5].spi_select0:0 */
    P8_0_DEBUG600_TRACE_DATA0       = 21,       /* Digital Active - debug600.trace_data[0]:1 */
    P8_0_PASS_MCPASS_DOUT0          = 24,       /* Digital Active - pass.mcpass_dout[0]:1 */
    P8_0_PERI_TR_IO_INPUT38         = 26,       /* Digital Active - peri.tr_io_input[38]:0 */
    P8_0_PERI_TR_IO_OUTPUT38        = 27,       /* Digital Active - peri.tr_io_output[38]:0 */
    P8_0_DEBUG600_RST_SWJ_TRSTN     = 29,       /* Digital Deep Sleep - debug600.rst_swj_trstn */

    /* P8.1 */
    P8_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_1_PERI_TR_IO_OUTPUT63        =  9,       /* Digital Active - peri.tr_io_output[63]:2 */
    P8_1_TCPWM0_LINE_COMPL516       = 10,       /* Digital Active - tcpwm[0].line_compl[516]:0 */
    P8_1_SCB5_UART_RX               = 16,       /* Digital Active - scb[5].uart_rx:0 */
    P8_1_SCB5_SPI_MOSI              = 17,       /* Digital Active - scb[5].spi_mosi:0 */
    P8_1_SCB5_I2C_SCL               = 19,       /* Digital Active - scb[5].i2c_scl:0 */
    P8_1_DEBUG600_TRACE_DATA1       = 21,       /* Digital Active - debug600.trace_data[1]:1 */
    P8_1_PASS_MCPASS_DOUT1          = 24,       /* Digital Active - pass.mcpass_dout[1]:1 */
    P8_1_PERI_TR_IO_INPUT39         = 26,       /* Digital Active - peri.tr_io_input[39]:0 */
    P8_1_PERI_TR_IO_OUTPUT39        = 27,       /* Digital Active - peri.tr_io_output[39]:0 */

    /* P8.2 */
    P8_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_2_PERI_TR_IO_OUTPUT64        =  9,       /* Digital Active - peri.tr_io_output[64]:2 */
    P8_2_TCPWM0_LINE517             = 10,       /* Digital Active - tcpwm[0].line[517]:0 */
    P8_2_CANFD0_TTCAN_RX0           = 11,       /* Digital Active - canfd[0].ttcan_rx[0]:0 */
    P8_2_SCB5_UART_RTS              = 16,       /* Digital Active - scb[5].uart_rts:0 */
    P8_2_SCB5_SPI_MISO              = 17,       /* Digital Active - scb[5].spi_miso:0 */
    P8_2_DEBUG600_TRACE_DATA2       = 21,       /* Digital Active - debug600.trace_data[2]:1 */
    P8_2_PASS_MCPASS_DOUT2          = 24,       /* Digital Active - pass.mcpass_dout[2]:1 */
    P8_2_PERI_TR_IO_INPUT40         = 26,       /* Digital Active - peri.tr_io_input[40]:0 */
    P8_2_PERI_TR_IO_OUTPUT40        = 27,       /* Digital Active - peri.tr_io_output[40]:0 */
    P8_2_IOSS_DDFT_PIN1             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[1]:1 */

    /* P8.3 */
    P8_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_3_PERI_TR_IO_OUTPUT65        =  9,       /* Digital Active - peri.tr_io_output[65]:2 */
    P8_3_TCPWM0_LINE_COMPL517       = 10,       /* Digital Active - tcpwm[0].line_compl[517]:0 */
    P8_3_CANFD0_TTCAN_TX0           = 11,       /* Digital Active - canfd[0].ttcan_tx[0]:0 */
    P8_3_SCB5_UART_TX               = 16,       /* Digital Active - scb[5].uart_tx:0 */
    P8_3_SCB5_SPI_CLK               = 17,       /* Digital Active - scb[5].spi_clk:0 */
    P8_3_SCB5_I2C_SDA               = 19,       /* Digital Active - scb[5].i2c_sda:0 */
    P8_3_DEBUG600_TRACE_DATA3       = 21,       /* Digital Active - debug600.trace_data[3]:1 */
    P8_3_PASS_MCPASS_DOUT3          = 24,       /* Digital Active - pass.mcpass_dout[3]:1 */
    P8_3_PERI_TR_IO_INPUT41         = 26,       /* Digital Active - peri.tr_io_input[41]:0 */
    P8_3_PERI_TR_IO_OUTPUT41        = 27,       /* Digital Active - peri.tr_io_output[41]:0 */
    P8_3_IOSS_DDFT_PIN0             = 31,       /* Digital Deep Sleep - ioss.ddft_pin[0]:1 */

    /* P9.0 */
    P9_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_0_TCPWM0_LINE518             = 10,       /* Digital Active - tcpwm[0].line[518]:0 */
    P9_0_SCB0_SPI_CLK               = 13,       /* Digital Deep Sleep - scb[0].spi_clk:0 */
    P9_0_SCB0_UART_CTS              = 14,       /* Digital Deep Sleep - scb[0].uart_cts:0 */
    P9_0_SCB0_I2C_SCL               = 15,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */
    P9_0_PERI_TR_IO_INPUT44         = 26,       /* Digital Active - peri.tr_io_input[44]:0 */
    P9_0_PERI_TR_IO_OUTPUT44        = 27,       /* Digital Active - peri.tr_io_output[44]:0 */

    /* P9.1 */
    P9_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_1_TCPWM0_LINE_COMPL518       = 10,       /* Digital Active - tcpwm[0].line_compl[518]:0 */
    P9_1_SCB0_SPI_SELECT0           = 13,       /* Digital Deep Sleep - scb[0].spi_select0:0 */
    P9_1_SCB0_UART_RTS              = 14,       /* Digital Deep Sleep - scb[0].uart_rts:0 */
    P9_1_PERI_TR_IO_INPUT45         = 26,       /* Digital Active - peri.tr_io_input[45]:0 */
    P9_1_PERI_TR_IO_OUTPUT45        = 27,       /* Digital Active - peri.tr_io_output[45]:0 */

    /* P9.2 */
    P9_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_2_TCPWM0_LINE519             = 10,       /* Digital Active - tcpwm[0].line[519]:0 */
    P9_2_CANFD0_TTCAN_RX0           = 11,       /* Digital Active - canfd[0].ttcan_rx[0]:1 */
    P9_2_SCB0_SPI_MOSI              = 13,       /* Digital Deep Sleep - scb[0].spi_mosi:0 */
    P9_2_SCB0_UART_RX               = 14,       /* Digital Deep Sleep - scb[0].uart_rx:0 */
    P9_2_SCB0_I2C_SDA               = 15,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */
    P9_2_DEBUG600_TRACE_CLOCK       = 21,       /* Digital Active - debug600.trace_clock:1 */
    P9_2_PASS_MCPASS_DCLK           = 24,       /* Digital Active - pass.mcpass_dclk:1 */
    P9_2_PERI_TR_IO_INPUT46         = 26,       /* Digital Active - peri.tr_io_input[46]:0 */
    P9_2_PERI_TR_IO_OUTPUT46        = 27,       /* Digital Active - peri.tr_io_output[46]:0 */

    /* P9.3 */
    P9_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_3_TCPWM0_LINE_COMPL519       = 10,       /* Digital Active - tcpwm[0].line_compl[519]:0 */
    P9_3_CANFD0_TTCAN_TX0           = 11,       /* Digital Active - canfd[0].ttcan_tx[0]:1 */
    P9_3_SCB0_SPI_MISO              = 13,       /* Digital Deep Sleep - scb[0].spi_miso:0 */
    P9_3_SCB0_UART_TX               = 14,       /* Digital Deep Sleep - scb[0].uart_tx:0 */
    P9_3_CPUSS_CLK_FM_PUMP          = 20,       /* Digital Active - cpuss.clk_fm_pump */
    P9_3_CPUSS_FAULT0               = 21,       /* Digital Active - cpuss.fault[0]:0 */
    P9_3_PERI_TR_IO_INPUT47         = 26,       /* Digital Active - peri.tr_io_input[47]:0 */
    P9_3_PERI_TR_IO_OUTPUT47        = 27        /* Digital Active - peri.tr_io_output[47]:0 */
} en_hsiom_sel_t;

#endif /* _GPIO_PSC3_E_LQFP_64_H_ */


/* [] END OF FILE */
