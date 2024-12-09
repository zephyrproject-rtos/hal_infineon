/***************************************************************************//**
* \file gpio_fx3g2_169_bga.h
*
* \brief
* FX3G2 device GPIO header for 169-BGA package
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

#ifndef _GPIO_FX3G2_169_BGA_H_
#define _GPIO_FX3G2_169_BGA_H_

/* Package type */
enum
{
    CY_GPIO_PACKAGE_QFN,
    CY_GPIO_PACKAGE_BGA,
    CY_GPIO_PACKAGE_LGA,
    CY_GPIO_PACKAGE_CSP,
    CY_GPIO_PACKAGE_WLCSP,
    CY_GPIO_PACKAGE_LQFP,
    CY_GPIO_PACKAGE_TQFP,
    CY_GPIO_PACKAGE_TEQFP,
    CY_GPIO_PACKAGE_SMT,
};

#define CY_GPIO_PACKAGE_TYPE            CY_GPIO_PACKAGE_BGA
#define CY_GPIO_PIN_COUNT               169u

/* AMUXBUS Segments */
enum
{
    AMUXBUS_FLASH,
    AMUXBUS_LVDS,
    AMUXBUS_MAIN,
    AMUXBUS_SRSS_AMUXBUSA_ADFT_VDDD,
    AMUXBUS_SRSS_AMUXBUSB_ADFT_VDDD,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_1                = 0x0001u,  /* Left = AMUXBUS_MAIN; Right = AMUXBUS_LVDS */
    AMUX_SPLIT_CTL_2                = 0x0002u   /* Left = AMUXBUS_FLASH; Right = AMUXBUS_MAIN */
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
#define P1_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_1_PORT                       GPIO_PRT1
#define P1_1_PIN                        1u
#define P1_1_NUM                        1u
#define P1_1_AMUXSEGMENT                AMUXBUS_MAIN

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

/* PORT 5 (GPIO) */
#define P5_0_PORT                       GPIO_PRT5
#define P5_0_PIN                        0u
#define P5_0_NUM                        0u
#define P5_1_PORT                       GPIO_PRT5
#define P5_1_PIN                        1u
#define P5_1_NUM                        1u

/* PORT 6 (GPIO) */
#define P6_0_PORT                       GPIO_PRT6
#define P6_0_PIN                        0u
#define P6_0_NUM                        0u
#define P6_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_1_PORT                       GPIO_PRT6
#define P6_1_PIN                        1u
#define P6_1_NUM                        1u
#define P6_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_2_PORT                       GPIO_PRT6
#define P6_2_PIN                        2u
#define P6_2_NUM                        2u
#define P6_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_3_PORT                       GPIO_PRT6
#define P6_3_PIN                        3u
#define P6_3_NUM                        3u
#define P6_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_4_PORT                       GPIO_PRT6
#define P6_4_PIN                        4u
#define P6_4_NUM                        4u
#define P6_4_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 7 (GPIO) */
#define P7_0_PORT                       GPIO_PRT7
#define P7_0_PIN                        0u
#define P7_0_NUM                        0u
#define P7_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_1_PORT                       GPIO_PRT7
#define P7_1_PIN                        1u
#define P7_1_NUM                        1u
#define P7_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_2_PORT                       GPIO_PRT7
#define P7_2_PIN                        2u
#define P7_2_NUM                        2u
#define P7_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_3_PORT                       GPIO_PRT7
#define P7_3_PIN                        3u
#define P7_3_NUM                        3u
#define P7_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_4_PORT                       GPIO_PRT7
#define P7_4_PIN                        4u
#define P7_4_NUM                        4u
#define P7_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_5_PORT                       GPIO_PRT7
#define P7_5_PIN                        5u
#define P7_5_NUM                        5u
#define P7_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_6_PORT                       GPIO_PRT7
#define P7_6_PIN                        6u
#define P7_6_NUM                        6u
#define P7_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_7_PORT                       GPIO_PRT7
#define P7_7_PIN                        7u
#define P7_7_NUM                        7u
#define P7_7_AMUXSEGMENT                AMUXBUS_MAIN

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
#define P8_6_PORT                       GPIO_PRT8
#define P8_6_PIN                        6u
#define P8_6_NUM                        6u
#define P8_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_7_PORT                       GPIO_PRT8
#define P8_7_PIN                        7u
#define P8_7_NUM                        7u
#define P8_7_AMUXSEGMENT                AMUXBUS_MAIN

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
#define P9_4_PORT                       GPIO_PRT9
#define P9_4_PIN                        4u
#define P9_4_NUM                        4u
#define P9_5_PORT                       GPIO_PRT9
#define P9_5_PIN                        5u
#define P9_5_NUM                        5u
#define P9_6_PORT                       GPIO_PRT9
#define P9_6_PIN                        6u
#define P9_6_NUM                        6u
#define P9_7_PORT                       GPIO_PRT9
#define P9_7_PIN                        7u
#define P9_7_NUM                        7u

/* PORT 10 (GPIO_OVT) */
#define P10_0_PORT                      GPIO_PRT10
#define P10_0_PIN                       0u
#define P10_0_NUM                       0u
#define P10_1_PORT                      GPIO_PRT10
#define P10_1_PIN                       1u
#define P10_1_NUM                       1u

/* PORT 11 (GPIO) */
#define P11_0_PORT                      GPIO_PRT11
#define P11_0_PIN                       0u
#define P11_0_NUM                       0u
#define P11_1_PORT                      GPIO_PRT11
#define P11_1_PIN                       1u
#define P11_1_NUM                       1u
#define P11_2_PORT                      GPIO_PRT11
#define P11_2_PIN                       2u
#define P11_2_NUM                       2u
#define P11_3_PORT                      GPIO_PRT11
#define P11_3_PIN                       3u
#define P11_3_NUM                       3u
#define P11_4_PORT                      GPIO_PRT11
#define P11_4_PIN                       4u
#define P11_4_NUM                       4u
#define P11_5_PORT                      GPIO_PRT11
#define P11_5_PIN                       5u
#define P11_5_NUM                       5u

/* PORT 12 (AUX) */
#define USBDM_PORT                      GPIO_PRT12
#define USBDM_PIN                       0u
#define USBDM_NUM                       0u
#define P12_0_PORT                      GPIO_PRT12
#define P12_0_PIN                       0u
#define P12_0_NUM                       0u
#define USBDP_PORT                      GPIO_PRT12
#define USBDP_PIN                       1u
#define USBDP_NUM                       1u
#define P12_1_PORT                      GPIO_PRT12
#define P12_1_PIN                       1u
#define P12_1_NUM                       1u

/* PORT 13 (GPIO) */
#define P13_0_PORT                      GPIO_PRT13
#define P13_0_PIN                       0u
#define P13_0_NUM                       0u
#define P13_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P13_1_PORT                      GPIO_PRT13
#define P13_1_PIN                       1u
#define P13_1_NUM                       1u
#define P13_1_AMUXSEGMENT               AMUXBUS_MAIN

/* Analog Connections */
#define LVDS2USB32SS_ADC_A_IN0_PORT     1u
#define LVDS2USB32SS_ADC_A_IN0_PIN      0u
#define LVDS2USB32SS_ADC_A_IN1_PORT     1u
#define LVDS2USB32SS_ADC_A_IN1_PIN      1u
#define SRSS_ADFT_PIN0_PORT             13u
#define SRSS_ADFT_PIN0_PIN              0u
#define SRSS_ADFT_PIN1_PORT             13u
#define SRSS_ADFT_PIN1_PIN              1u
#define SRSS_ECO_IN_PORT                5u
#define SRSS_ECO_IN_PIN                 0u
#define SRSS_ECO_OUT_PORT               5u
#define SRSS_ECO_OUT_PIN                1u

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
    P0_0_AMUXA                      =  4,       /* Analog mux bus A */
    P0_0_AMUXB                      =  5,       /* Analog mux bus B */
    P0_0_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P0_0_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P0_0_SCB2_UART_RX               = 18,       /* Digital Active - scb[2].uart_rx:0 */
    P0_0_SCB2_I2C_SDA               = 19,       /* Digital Active - scb[2].i2c_sda:0 */
    P0_0_LVDS2USB32SS_LNK1_L3_ENTRY_GPIO_I = 28, /* Digital Deep Sleep - lvds2usb32ss.lnk1_l3_entry_gpio_i:3 */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_1_AMUXA                      =  4,       /* Analog mux bus A */
    P0_1_AMUXB                      =  5,       /* Analog mux bus B */
    P0_1_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P0_1_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P0_1_SCB2_UART_TX               = 18,       /* Digital Active - scb[2].uart_tx:0 */
    P0_1_SCB2_I2C_SCL               = 19,       /* Digital Active - scb[2].i2c_scl:0 */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_0_AMUXA                      =  4,       /* Analog mux bus A */
    P1_0_AMUXB                      =  5,       /* Analog mux bus B */
    P1_0_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P1_0_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P1_0_TCPWM0_LINE3               =  8,       /* Digital Active - tcpwm[0].line[3] */
    P1_0_TDM_TDM_RX_FSYNC           = 16,       /* Digital Active - tdm.tdm_rx_fsync:1 */
    P1_0_SCB4_UART_RTS              = 18,       /* Digital Active - scb[4].uart_rts:0 */
    P1_0_SCB4_SPI_MOSI              = 20,       /* Digital Active - scb[4].spi_mosi:0 */
    P1_0_USBHSDEV_GPIO_DDFT0        = 23,       /* Digital Active - usbhsdev.gpio_ddft0 */
    P1_0_SRSS_DDFT_PIN_IN0          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[0]:2 */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_1_AMUXA                      =  4,       /* Analog mux bus A */
    P1_1_AMUXB                      =  5,       /* Analog mux bus B */
    P1_1_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P1_1_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P1_1_TCPWM0_LINE_COMPL3         =  8,       /* Digital Active - tcpwm[0].line_compl[3] */
    P1_1_TDM_TDM_RX_MCK             = 16,       /* Digital Active - tdm.tdm_rx_mck:1 */
    P1_1_SCB4_UART_CTS              = 18,       /* Digital Active - scb[4].uart_cts:0 */
    P1_1_SCB4_SPI_MISO              = 20,       /* Digital Active - scb[4].spi_miso:0 */
    P1_1_USBHSDEV_GPIO_DDFT1        = 23,       /* Digital Active - usbhsdev.gpio_ddft1 */
    P1_1_SRSS_DDFT_PIN_IN1          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[1]:2 */

    /* P4.0 */
    P4_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_0_AMUXA                      =  4,       /* Analog mux bus A */
    P4_0_AMUXB                      =  5,       /* Analog mux bus B */
    P4_0_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P4_0_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P4_0_SCB3_UART_RTS              = 18,       /* Digital Active - scb[3].uart_rts:0 */
    P4_0_PERI_TR_IO_INPUT0          = 24,       /* Digital Active - peri.tr_io_input[0]:0 */
    P4_0_PERI_TR_IO_OUTPUT0         = 25,       /* Digital Active - peri.tr_io_output[0]:0 */
    P4_0_CPUSS_TRACE_DATA3          = 27,       /* Digital Active - cpuss.trace_data[3]:0 */

    /* P4.1 */
    P4_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_1_AMUXA                      =  4,       /* Analog mux bus A */
    P4_1_AMUXB                      =  5,       /* Analog mux bus B */
    P4_1_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P4_1_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P4_1_PDM0_PDM_CLK0              = 17,       /* Digital Active - pdm[0].pdm_clk[0]:0 */
    P4_1_SCB3_UART_RX               = 18,       /* Digital Active - scb[3].uart_rx:1 */
    P4_1_SCB3_I2C_SDA               = 19,       /* Digital Active - scb[3].i2c_sda:1 */
    P4_1_PERI_TR_IO_INPUT1          = 24,       /* Digital Active - peri.tr_io_input[1]:0 */
    P4_1_PERI_TR_IO_OUTPUT1         = 25,       /* Digital Active - peri.tr_io_output[1]:0 */
    P4_1_CPUSS_TRACE_DATA2          = 27,       /* Digital Active - cpuss.trace_data[2]:0 */

    /* P4.2 */
    P4_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_2_AMUXA                      =  4,       /* Analog mux bus A */
    P4_2_AMUXB                      =  5,       /* Analog mux bus B */
    P4_2_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P4_2_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P4_2_PDM0_PDM_DATA0             = 17,       /* Digital Active - pdm[0].pdm_data[0]:0 */
    P4_2_SCB3_UART_TX               = 18,       /* Digital Active - scb[3].uart_tx:1 */
    P4_2_SCB3_I2C_SCL               = 19,       /* Digital Active - scb[3].i2c_scl:1 */
    P4_2_PERI_TR_IO_INPUT2          = 24,       /* Digital Active - peri.tr_io_input[2]:0 */
    P4_2_CPUSS_FAULT_OUT0           = 25,       /* Digital Active - cpuss.fault_out[0]:0 */
    P4_2_CPUSS_TRACE_DATA1          = 27,       /* Digital Active - cpuss.trace_data[1]:0 */

    /* P4.3 */
    P4_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_3_AMUXA                      =  4,       /* Analog mux bus A */
    P4_3_AMUXB                      =  5,       /* Analog mux bus B */
    P4_3_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P4_3_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P4_3_SCB5_UART_RX               = 18,       /* Digital Active - scb[5].uart_rx:0 */
    P4_3_SCB5_I2C_SCL               = 19,       /* Digital Active - scb[5].i2c_scl:0 */
    P4_3_SCB5_SPI_CLK               = 20,       /* Digital Active - scb[5].spi_clk */
    P4_3_PERI_TR_IO_INPUT3          = 24,       /* Digital Active - peri.tr_io_input[3]:0 */
    P4_3_CPUSS_FAULT_OUT1           = 25,       /* Digital Active - cpuss.fault_out[1]:0 */
    P4_3_CPUSS_TRACE_DATA0          = 27,       /* Digital Active - cpuss.trace_data[0]:0 */
    P4_3_SRSS_DDFT_PIN_IN0          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[0]:1 */

    /* P4.4 */
    P4_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_4_AMUXA                      =  4,       /* Analog mux bus A */
    P4_4_AMUXB                      =  5,       /* Analog mux bus B */
    P4_4_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P4_4_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P4_4_SCB5_UART_TX               = 18,       /* Digital Active - scb[5].uart_tx:0 */
    P4_4_SCB5_I2C_SDA               = 19,       /* Digital Active - scb[5].i2c_sda:0 */
    P4_4_SCB5_SPI_SELECT0           = 20,       /* Digital Active - scb[5].spi_select0 */
    P4_4_CPUSS_CLK_FM_PUMP          = 21,       /* Digital Active - cpuss.clk_fm_pump */
    P4_4_CANFD0_TTCAN_RX            = 22,       /* Digital Active - canfd[0].ttcan_rx:1 */
    P4_4_CPUSS_TRACE_CLOCK          = 26,       /* Digital Active - cpuss.trace_clock:0 */
    P4_4_LVDS2USB32SS_LNK0_L3_ENTRY_GPIO_I = 28, /* Digital Deep Sleep - lvds2usb32ss.lnk0_l3_entry_gpio_i:3 */
    P4_4_SRSS_DDFT_PIN_IN1          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[1]:1 */

    /* P5.0 */
    P5_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_0_AMUXA                      =  4,       /* Analog mux bus A */
    P5_0_AMUXB                      =  5,       /* Analog mux bus B */
    P5_0_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P5_0_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P5_0_SRSS_EXT_CLK               = 16,       /* Digital Active - srss.ext_clk:0 */

    /* P5.1 */
    P5_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_1_AMUXA                      =  4,       /* Analog mux bus A */
    P5_1_AMUXB                      =  5,       /* Analog mux bus B */
    P5_1_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P5_1_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P5_1_SRSS_EXT_CLK               = 16,       /* Digital Active - srss.ext_clk:1 */
    P5_1_USBHSDEV_TEST_PLL_REFCLK_I = 18,       /* Digital Active - usbhsdev.test_pll_refclk_i */

    /* P6.0 */
    P6_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_0_AMUXA                      =  4,       /* Analog mux bus A */
    P6_0_AMUXB                      =  5,       /* Analog mux bus B */
    P6_0_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P6_0_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P6_0_SMIF_SPI_CLK               = 17,       /* Digital Active - smif.spi_clk */
    P6_0_SCB6_UART_RX               = 18,       /* Digital Active - scb[6].uart_rx:1 */
    P6_0_SCB6_I2C_SCL               = 19,       /* Digital Active - scb[6].i2c_scl:1 */
    P6_0_SCB3_SPI_CLK               = 20,       /* Digital Active - scb[3].spi_clk */
    P6_0_PERI_TR_IO_INPUT5          = 24,       /* Digital Active - peri.tr_io_input[5]:0 */
    P6_0_PERI_TR_IO_OUTPUT0         = 25,       /* Digital Active - peri.tr_io_output[0]:1 */
    P6_0_CPUSS_TRACE_DATA3          = 27,       /* Digital Active - cpuss.trace_data[3]:4 */

    /* P6.1 */
    P6_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_1_AMUXA                      =  4,       /* Analog mux bus A */
    P6_1_AMUXB                      =  5,       /* Analog mux bus B */
    P6_1_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P6_1_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P6_1_SMIF_SPI_SELECT0           = 17,       /* Digital Active - smif.spi_select0 */
    P6_1_SCB6_UART_TX               = 18,       /* Digital Active - scb[6].uart_tx:1 */
    P6_1_SCB6_I2C_SDA               = 19,       /* Digital Active - scb[6].i2c_sda:1 */
    P6_1_SCB3_SPI_SELECT0           = 20,       /* Digital Active - scb[3].spi_select0 */
    P6_1_PERI_TR_IO_INPUT8          = 24,       /* Digital Active - peri.tr_io_input[8]:0 */
    P6_1_PERI_TR_IO_OUTPUT1         = 25,       /* Digital Active - peri.tr_io_output[1]:1 */
    P6_1_CPUSS_TRACE_DATA2          = 27,       /* Digital Active - cpuss.trace_data[2]:4 */

    /* P6.2 */
    P6_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_2_AMUXA                      =  4,       /* Analog mux bus A */
    P6_2_AMUXB                      =  5,       /* Analog mux bus B */
    P6_2_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P6_2_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P6_2_SMIF_SPI_SELECT1           = 17,       /* Digital Active - smif.spi_select1 */
    P6_2_SCB3_SPI_MOSI              = 20,       /* Digital Active - scb[3].spi_mosi */
    P6_2_CPUSS_FAULT_OUT0           = 25,       /* Digital Active - cpuss.fault_out[0]:1 */
    P6_2_CPUSS_TRACE_DATA1          = 27,       /* Digital Active - cpuss.trace_data[1]:4 */

    /* P6.3 */
    P6_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_3_AMUXA                      =  4,       /* Analog mux bus A */
    P6_3_AMUXB                      =  5,       /* Analog mux bus B */
    P6_3_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P6_3_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P6_3_SMIF_SPI_SELECT2           = 17,       /* Digital Active - smif.spi_select2 */
    P6_3_SCB3_SPI_MISO              = 20,       /* Digital Active - scb[3].spi_miso */
    P6_3_LVDS2USB32SS_LVDS_USEC_PULSE_O = 23,   /* Digital Active - lvds2usb32ss.lvds_usec_pulse_o:2 */
    P6_3_CPUSS_FAULT_OUT1           = 25,       /* Digital Active - cpuss.fault_out[1]:1 */
    P6_3_CPUSS_TRACE_DATA0          = 27,       /* Digital Active - cpuss.trace_data[0]:4 */

    /* P6.4 */
    P6_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_4_SMIF_SPI_SELECT3           = 17,       /* Digital Active - smif.spi_select3 */
    P6_4_CPUSS_TRACE_CLOCK          = 26,       /* Digital Active - cpuss.trace_clock:4 */

    /* P7.0 */
    P7_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_0_SCB0_I2C_SCL               = 13,       /* Digital Deep Sleep - scb[0].i2c_scl:1 */
    P7_0_SMIF_SPI_DATA0             = 17,       /* Digital Active - smif.spi_data0 */
    P7_0_SCB0_UART_RX               = 18,       /* Digital Active - scb[0].uart_rx:1 */
    P7_0_SCB2_SPI_CLK               = 20,       /* Digital Active - scb[2].spi_clk */

    /* P7.1 */
    P7_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_1_AMUXA                      =  4,       /* Analog mux bus A */
    P7_1_AMUXB                      =  5,       /* Analog mux bus B */
    P7_1_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P7_1_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P7_1_SCB0_I2C_SDA               = 13,       /* Digital Deep Sleep - scb[0].i2c_sda:1 */
    P7_1_SMIF_SPI_DATA1             = 17,       /* Digital Active - smif.spi_data1 */
    P7_1_SCB0_UART_TX               = 18,       /* Digital Active - scb[0].uart_tx:1 */
    P7_1_SCB2_SPI_SELECT0           = 20,       /* Digital Active - scb[2].spi_select0 */
    P7_1_PERI_TR_IO_INPUT9          = 24,       /* Digital Active - peri.tr_io_input[9]:0 */
    P7_1_PERI_TR_IO_OUTPUT0         = 25,       /* Digital Active - peri.tr_io_output[0]:2 */

    /* P7.2 */
    P7_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_2_AMUXA                      =  4,       /* Analog mux bus A */
    P7_2_AMUXB                      =  5,       /* Analog mux bus B */
    P7_2_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P7_2_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P7_2_SMIF_SPI_DATA2             = 17,       /* Digital Active - smif.spi_data2 */
    P7_2_SCB0_UART_CTS              = 18,       /* Digital Active - scb[0].uart_cts:0 */
    P7_2_SCB2_SPI_MOSI              = 20,       /* Digital Active - scb[2].spi_mosi */
    P7_2_PERI_TR_IO_INPUT6          = 24,       /* Digital Active - peri.tr_io_input[6]:0 */
    P7_2_PERI_TR_IO_OUTPUT1         = 25,       /* Digital Active - peri.tr_io_output[1]:2 */

    /* P7.3 */
    P7_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_3_AMUXA                      =  4,       /* Analog mux bus A */
    P7_3_AMUXB                      =  5,       /* Analog mux bus B */
    P7_3_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P7_3_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P7_3_SMIF_SPI_DATA3             = 17,       /* Digital Active - smif.spi_data3 */
    P7_3_SCB3_UART_CTS              = 18,       /* Digital Active - scb[3].uart_cts:0 */
    P7_3_SCB0_UART_RTS              = 19,       /* Digital Active - scb[0].uart_rts:0 */
    P7_3_SCB2_SPI_MISO              = 20,       /* Digital Active - scb[2].spi_miso */
    P7_3_PERI_TR_IO_INPUT7          = 24,       /* Digital Active - peri.tr_io_input[7]:0 */
    P7_3_CPUSS_FAULT_OUT0           = 25,       /* Digital Active - cpuss.fault_out[0]:2 */

    /* P7.4 */
    P7_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_4_AMUXA                      =  4,       /* Analog mux bus A */
    P7_4_AMUXB                      =  5,       /* Analog mux bus B */
    P7_4_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P7_4_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P7_4_SMIF_SPI_DATA4             = 17,       /* Digital Active - smif.spi_data4 */
    P7_4_SCB2_UART_CTS              = 18,       /* Digital Active - scb[2].uart_cts:0 */
    P7_4_PERI_TR_IO_INPUT10         = 24,       /* Digital Active - peri.tr_io_input[10]:0 */
    P7_4_CPUSS_FAULT_OUT1           = 25,       /* Digital Active - cpuss.fault_out[1]:2 */

    /* P7.5 */
    P7_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_5_AMUXA                      =  4,       /* Analog mux bus A */
    P7_5_AMUXB                      =  5,       /* Analog mux bus B */
    P7_5_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P7_5_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P7_5_SMIF_SPI_DATA5             = 17,       /* Digital Active - smif.spi_data5 */

    /* P7.6 */
    P7_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_6_AMUXA                      =  4,       /* Analog mux bus A */
    P7_6_AMUXB                      =  5,       /* Analog mux bus B */
    P7_6_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P7_6_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P7_6_SMIF_SPI_DATA6             = 17,       /* Digital Active - smif.spi_data6 */
    P7_6_SCB1_UART_RX               = 18,       /* Digital Active - scb[1].uart_rx:1 */
    P7_6_SCB1_I2C_SDA               = 19,       /* Digital Active - scb[1].i2c_sda:1 */

    /* P7.7 */
    P7_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_7_AMUXA                      =  4,       /* Analog mux bus A */
    P7_7_AMUXB                      =  5,       /* Analog mux bus B */
    P7_7_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P7_7_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P7_7_SMIF_SPI_DATA7             = 17,       /* Digital Active - smif.spi_data7 */
    P7_7_SCB1_UART_TX               = 18,       /* Digital Active - scb[1].uart_tx:1 */
    P7_7_SCB1_I2C_SCL               = 19,       /* Digital Active - scb[1].i2c_scl:1 */

    /* P8.0 */
    P8_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_0_AMUXA                      =  4,       /* Analog mux bus A */
    P8_0_AMUXB                      =  5,       /* Analog mux bus B */
    P8_0_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P8_0_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P8_0_TCPWM0_LINE0               =  8,       /* Digital Active - tcpwm[0].line[0] */
    P8_0_TDM_TDM_TX_SCK             = 16,       /* Digital Active - tdm.tdm_tx_sck:1 */
    P8_0_PDM0_PDM_CLK0              = 17,       /* Digital Active - pdm[0].pdm_clk[0]:1 */
    P8_0_SCB1_UART_RX               = 18,       /* Digital Active - scb[1].uart_rx:0 */
    P8_0_SCB1_I2C_SDA               = 19,       /* Digital Active - scb[1].i2c_sda:0 */
    P8_0_SCB1_SPI_MISO              = 20,       /* Digital Active - scb[1].spi_miso:0 */
    P8_0_PERI_TR_IO_INPUT11         = 24,       /* Digital Active - peri.tr_io_input[11]:0 */
    P8_0_PERI_TR_IO_OUTPUT0         = 25,       /* Digital Active - peri.tr_io_output[0]:3 */
    P8_0_CPUSS_TRACE_DATA3          = 27,       /* Digital Active - cpuss.trace_data[3]:1 */

    /* P8.1 */
    P8_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_1_AMUXA                      =  4,       /* Analog mux bus A */
    P8_1_AMUXB                      =  5,       /* Analog mux bus B */
    P8_1_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P8_1_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P8_1_TCPWM0_LINE_COMPL0         =  8,       /* Digital Active - tcpwm[0].line_compl[0] */
    P8_1_TDM_TDM_RX_SCK             = 16,       /* Digital Active - tdm.tdm_rx_sck:1 */
    P8_1_PDM0_PDM_DATA0             = 17,       /* Digital Active - pdm[0].pdm_data[0]:1 */
    P8_1_SCB1_UART_TX               = 18,       /* Digital Active - scb[1].uart_tx:0 */
    P8_1_SCB1_I2C_SCL               = 19,       /* Digital Active - scb[1].i2c_scl:0 */
    P8_1_SCB1_SPI_CLK               = 20,       /* Digital Active - scb[1].spi_clk:0 */
    P8_1_PERI_TR_IO_INPUT12         = 24,       /* Digital Active - peri.tr_io_input[12]:0 */
    P8_1_PERI_TR_IO_OUTPUT1         = 25,       /* Digital Active - peri.tr_io_output[1]:3 */
    P8_1_CPUSS_TRACE_DATA2          = 27,       /* Digital Active - cpuss.trace_data[2]:1 */

    /* P8.2 */
    P8_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_2_AMUXA                      =  4,       /* Analog mux bus A */
    P8_2_AMUXB                      =  5,       /* Analog mux bus B */
    P8_2_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P8_2_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P8_2_TCPWM0_LINE1               =  8,       /* Digital Active - tcpwm[0].line[1] */
    P8_2_TDM_TDM_TX_FSYNC           = 16,       /* Digital Active - tdm.tdm_tx_fsync:1 */
    P8_2_PDM0_PDM_CLK1              = 17,       /* Digital Active - pdm[0].pdm_clk[1]:1 */
    P8_2_SCB1_UART_RTS              = 18,       /* Digital Active - scb[1].uart_rts:0 */
    P8_2_SCB1_SPI_MOSI              = 20,       /* Digital Active - scb[1].spi_mosi:0 */
    P8_2_PERI_TR_IO_INPUT13         = 24,       /* Digital Active - peri.tr_io_input[13]:0 */
    P8_2_CPUSS_FAULT_OUT0           = 25,       /* Digital Active - cpuss.fault_out[0]:3 */
    P8_2_CPUSS_TRACE_DATA1          = 27,       /* Digital Active - cpuss.trace_data[1]:1 */
    P8_2_LVDS2USB32SS_LNK0_L3_ENTRY_GPIO_I = 28, /* Digital Deep Sleep - lvds2usb32ss.lnk0_l3_entry_gpio_i:2 */

    /* P8.3 */
    P8_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_3_AMUXA                      =  4,       /* Analog mux bus A */
    P8_3_AMUXB                      =  5,       /* Analog mux bus B */
    P8_3_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P8_3_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P8_3_TCPWM0_LINE_COMPL1         =  8,       /* Digital Active - tcpwm[0].line_compl[1] */
    P8_3_TDM_TDM_TX_MCK             = 16,       /* Digital Active - tdm.tdm_tx_mck:1 */
    P8_3_PDM0_PDM_DATA1             = 17,       /* Digital Active - pdm[0].pdm_data[1]:1 */
    P8_3_SCB1_UART_CTS              = 18,       /* Digital Active - scb[1].uart_cts:0 */
    P8_3_SCB1_SPI_SELECT0           = 20,       /* Digital Active - scb[1].spi_select0:0 */
    P8_3_PERI_TR_IO_INPUT14         = 24,       /* Digital Active - peri.tr_io_input[14]:0 */
    P8_3_CPUSS_FAULT_OUT1           = 25,       /* Digital Active - cpuss.fault_out[1]:3 */
    P8_3_CPUSS_TRACE_DATA0          = 27,       /* Digital Active - cpuss.trace_data[0]:1 */
    P8_3_LVDS2USB32SS_LNK1_L3_ENTRY_GPIO_I = 28, /* Digital Deep Sleep - lvds2usb32ss.lnk1_l3_entry_gpio_i:2 */

    /* P8.4 */
    P8_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_4_AMUXA                      =  4,       /* Analog mux bus A */
    P8_4_AMUXB                      =  5,       /* Analog mux bus B */
    P8_4_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P8_4_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P8_4_TCPWM0_LINE2               =  8,       /* Digital Active - tcpwm[0].line[2] */
    P8_4_TDM_TDM_RX_SD              = 16,       /* Digital Active - tdm.tdm_rx_sd:1 */
    P8_4_PDM0_PDM_CLK1              = 17,       /* Digital Active - pdm[0].pdm_clk[1]:0 */
    P8_4_SCB4_UART_RX               = 18,       /* Digital Active - scb[4].uart_rx:0 */
    P8_4_SCB4_I2C_SCL               = 19,       /* Digital Active - scb[4].i2c_scl:0 */
    P8_4_SCB4_SPI_CLK               = 20,       /* Digital Active - scb[4].spi_clk:0 */
    P8_4_CANFD0_TTCAN_RX            = 22,       /* Digital Active - canfd[0].ttcan_rx:0 */
    P8_4_PERI_TR_IO_INPUT25         = 24,       /* Digital Active - peri.tr_io_input[25]:0 */
    P8_4_CPUSS_TRACE_CLOCK          = 26,       /* Digital Active - cpuss.trace_clock:1 */

    /* P8.5 */
    P8_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_5_AMUXA                      =  4,       /* Analog mux bus A */
    P8_5_AMUXB                      =  5,       /* Analog mux bus B */
    P8_5_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P8_5_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P8_5_TCPWM0_LINE_COMPL2         =  8,       /* Digital Active - tcpwm[0].line_compl[2] */
    P8_5_TDM_TDM_TX_SD              = 16,       /* Digital Active - tdm.tdm_tx_sd:1 */
    P8_5_PDM0_PDM_DATA1             = 17,       /* Digital Active - pdm[0].pdm_data[1]:0 */
    P8_5_SCB4_UART_TX               = 18,       /* Digital Active - scb[4].uart_tx:0 */
    P8_5_SCB4_I2C_SDA               = 19,       /* Digital Active - scb[4].i2c_sda:0 */
    P8_5_SCB4_SPI_SELECT0           = 20,       /* Digital Active - scb[4].spi_select0:0 */
    P8_5_CANFD0_TTCAN_TX            = 22,       /* Digital Active - canfd[0].ttcan_tx:0 */

    /* P8.6 */
    P8_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_6_AMUXA                      =  4,       /* Analog mux bus A */
    P8_6_AMUXB                      =  5,       /* Analog mux bus B */
    P8_6_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P8_6_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P8_6_SCB3_UART_RX               = 18,       /* Digital Active - scb[3].uart_rx:0 */
    P8_6_SCB3_I2C_SDA               = 19,       /* Digital Active - scb[3].i2c_sda:0 */

    /* P8.7 */
    P8_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_7_AMUXA                      =  4,       /* Analog mux bus A */
    P8_7_AMUXB                      =  5,       /* Analog mux bus B */
    P8_7_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P8_7_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P8_7_SCB3_UART_TX               = 18,       /* Digital Active - scb[3].uart_tx:0 */
    P8_7_SCB3_I2C_SCL               = 19,       /* Digital Active - scb[3].i2c_scl:0 */

    /* P9.0 */
    P9_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_0_AMUXA                      =  4,       /* Analog mux bus A */
    P9_0_AMUXB                      =  5,       /* Analog mux bus B */
    P9_0_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P9_0_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P9_0_TCPWM0_LINE4               =  8,       /* Digital Active - tcpwm[0].line[4] */
    P9_0_TDM_TDM_TX_SCK             = 16,       /* Digital Active - tdm.tdm_tx_sck:0 */
    P9_0_PDM0_PDM_CLK0              = 17,       /* Digital Active - pdm[0].pdm_clk[0]:2 */
    P9_0_SCB6_UART_RX               = 18,       /* Digital Active - scb[6].uart_rx:0 */
    P9_0_SCB6_I2C_SCL               = 19,       /* Digital Active - scb[6].i2c_scl:0 */
    P9_0_SCB6_SPI_CLK               = 20,       /* Digital Active - scb[6].spi_clk:0 */
    P9_0_PERI_TR_IO_INPUT15         = 24,       /* Digital Active - peri.tr_io_input[15]:0 */
    P9_0_PERI_TR_IO_OUTPUT0         = 25,       /* Digital Active - peri.tr_io_output[0]:4 */
    P9_0_CPUSS_TRACE_DATA3          = 27,       /* Digital Active - cpuss.trace_data[3]:2 */
    P9_0_LVDS2USB32SS_LNK0_L3_ENTRY_GPIO_I = 28, /* Digital Deep Sleep - lvds2usb32ss.lnk0_l3_entry_gpio_i:1 */

    /* P9.1 */
    P9_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_1_AMUXA                      =  4,       /* Analog mux bus A */
    P9_1_AMUXB                      =  5,       /* Analog mux bus B */
    P9_1_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P9_1_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P9_1_TCPWM0_LINE_COMPL4         =  8,       /* Digital Active - tcpwm[0].line_compl[4] */
    P9_1_TDM_TDM_RX_SCK             = 16,       /* Digital Active - tdm.tdm_rx_sck:0 */
    P9_1_PDM0_PDM_DATA0             = 17,       /* Digital Active - pdm[0].pdm_data[0]:2 */
    P9_1_SCB6_UART_TX               = 18,       /* Digital Active - scb[6].uart_tx:0 */
    P9_1_SCB6_I2C_SDA               = 19,       /* Digital Active - scb[6].i2c_sda:0 */
    P9_1_SCB6_SPI_MOSI              = 20,       /* Digital Active - scb[6].spi_mosi:0 */
    P9_1_PERI_TR_IO_INPUT16         = 24,       /* Digital Active - peri.tr_io_input[16]:0 */
    P9_1_PERI_TR_IO_OUTPUT1         = 25,       /* Digital Active - peri.tr_io_output[1]:4 */
    P9_1_CPUSS_TRACE_DATA2          = 27,       /* Digital Active - cpuss.trace_data[2]:2 */
    P9_1_LVDS2USB32SS_LNK1_L3_ENTRY_GPIO_I = 28, /* Digital Deep Sleep - lvds2usb32ss.lnk1_l3_entry_gpio_i:1 */

    /* P9.2 */
    P9_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_2_AMUXA                      =  4,       /* Analog mux bus A */
    P9_2_AMUXB                      =  5,       /* Analog mux bus B */
    P9_2_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P9_2_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P9_2_TCPWM0_LINE5               =  8,       /* Digital Active - tcpwm[0].line[5] */
    P9_2_TDM_TDM_TX_FSYNC           = 16,       /* Digital Active - tdm.tdm_tx_fsync:0 */
    P9_2_PDM0_PDM_CLK1              = 17,       /* Digital Active - pdm[0].pdm_clk[1]:2 */
    P9_2_SCB6_UART_RTS              = 18,       /* Digital Active - scb[6].uart_rts:0 */
    P9_2_SCB6_SPI_MISO              = 20,       /* Digital Active - scb[6].spi_miso:0 */
    P9_2_LVDS2USB32SS_USB32_GPIO_DDFT_O0 = 23,  /* Digital Active - lvds2usb32ss.usb32_gpio_ddft_o[0] */
    P9_2_PERI_TR_IO_INPUT17         = 24,       /* Digital Active - peri.tr_io_input[17]:0 */
    P9_2_CPUSS_FAULT_OUT0           = 25,       /* Digital Active - cpuss.fault_out[0]:4 */
    P9_2_CPUSS_TRACE_DATA1          = 27,       /* Digital Active - cpuss.trace_data[1]:2 */

    /* P9.3 */
    P9_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_3_AMUXA                      =  4,       /* Analog mux bus A */
    P9_3_AMUXB                      =  5,       /* Analog mux bus B */
    P9_3_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P9_3_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P9_3_TCPWM0_LINE_COMPL5         =  8,       /* Digital Active - tcpwm[0].line_compl[5] */
    P9_3_TDM_TDM_TX_MCK             = 16,       /* Digital Active - tdm.tdm_tx_mck:0 */
    P9_3_PDM0_PDM_DATA1             = 17,       /* Digital Active - pdm[0].pdm_data[1]:2 */
    P9_3_SCB6_UART_CTS              = 18,       /* Digital Active - scb[6].uart_cts:0 */
    P9_3_SCB6_SPI_SELECT0           = 20,       /* Digital Active - scb[6].spi_select0:0 */
    P9_3_LVDS2USB32SS_USB32_GPIO_DDFT_O1 = 23,  /* Digital Active - lvds2usb32ss.usb32_gpio_ddft_o[1] */
    P9_3_CPUSS_FAULT_OUT1           = 25,       /* Digital Active - cpuss.fault_out[1]:4 */
    P9_3_CPUSS_TRACE_CLOCK          = 26,       /* Digital Active - cpuss.trace_clock:2 */

    /* P9.4 */
    P9_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_4_AMUXA                      =  4,       /* Analog mux bus A */
    P9_4_AMUXB                      =  5,       /* Analog mux bus B */
    P9_4_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P9_4_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P9_4_TCPWM0_LINE6               =  8,       /* Digital Active - tcpwm[0].line[6] */
    P9_4_TDM_TDM_RX_SD              = 16,       /* Digital Active - tdm.tdm_rx_sd:0 */
    P9_4_SCB6_SPI_SELECT1           = 20,       /* Digital Active - scb[6].spi_select1:0 */
    P9_4_LVDS2USB32SS_LVDS_GPIO_DDFT_O0 = 23,   /* Digital Active - lvds2usb32ss.lvds_gpio_ddft_o[0] */
    P9_4_PERI_TR_IO_INPUT18         = 24,       /* Digital Active - peri.tr_io_input[18]:0 */
    P9_4_CPUSS_TRACE_DATA0          = 27,       /* Digital Active - cpuss.trace_data[0]:2 */

    /* P9.5 */
    P9_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_5_AMUXA                      =  4,       /* Analog mux bus A */
    P9_5_AMUXB                      =  5,       /* Analog mux bus B */
    P9_5_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P9_5_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P9_5_TCPWM0_LINE_COMPL6         =  8,       /* Digital Active - tcpwm[0].line_compl[6] */
    P9_5_TDM_TDM_TX_SD              = 16,       /* Digital Active - tdm.tdm_tx_sd:0 */
    P9_5_SCB2_UART_RTS              = 18,       /* Digital Active - scb[2].uart_rts:0 */
    P9_5_SCB6_SPI_SELECT2           = 20,       /* Digital Active - scb[6].spi_select2:0 */
    P9_5_CANFD0_TTCAN_RX            = 22,       /* Digital Active - canfd[0].ttcan_rx:2 */
    P9_5_LVDS2USB32SS_LVDS_GPIO_DDFT_O1 = 23,   /* Digital Active - lvds2usb32ss.lvds_gpio_ddft_o[1] */
    P9_5_PERI_TR_IO_INPUT19         = 24,       /* Digital Active - peri.tr_io_input[19]:0 */

    /* P9.6 */
    P9_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_6_AMUXA                      =  4,       /* Analog mux bus A */
    P9_6_AMUXB                      =  5,       /* Analog mux bus B */
    P9_6_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P9_6_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P9_6_TCPWM0_LINE7               =  8,       /* Digital Active - tcpwm[0].line[7] */
    P9_6_TDM_TDM_RX_FSYNC           = 16,       /* Digital Active - tdm.tdm_rx_fsync:0 */
    P9_6_SCB2_UART_RX               = 18,       /* Digital Active - scb[2].uart_rx:1 */
    P9_6_SCB2_I2C_SDA               = 19,       /* Digital Active - scb[2].i2c_sda:1 */
    P9_6_SCB6_SPI_SELECT3           = 20,       /* Digital Active - scb[6].spi_select3:0 */
    P9_6_CANFD0_TTCAN_TX            = 22,       /* Digital Active - canfd[0].ttcan_tx:2 */

    /* P9.7 */
    P9_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_7_AMUXA                      =  4,       /* Analog mux bus A */
    P9_7_AMUXB                      =  5,       /* Analog mux bus B */
    P9_7_AMUXA_DSI                  =  6,       /* Analog mux bus A, DSI control */
    P9_7_AMUXB_DSI                  =  7,       /* Analog mux bus B, DSI control */
    P9_7_TCPWM0_LINE_COMPL7         =  8,       /* Digital Active - tcpwm[0].line_compl[7] */
    P9_7_TDM_TDM_RX_MCK             = 16,       /* Digital Active - tdm.tdm_rx_mck:0 */
    P9_7_SCB2_UART_TX               = 18,       /* Digital Active - scb[2].uart_tx:1 */
    P9_7_SCB2_I2C_SCL               = 19,       /* Digital Active - scb[2].i2c_scl:1 */

    /* P10.0 */
    P10_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_0_AMUXA                     =  4,       /* Analog mux bus A */
    P10_0_AMUXB                     =  5,       /* Analog mux bus B */
    P10_0_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    P10_0_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */
    P10_0_SCB0_I2C_SCL              = 13,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */
    P10_0_SCB0_UART_RX              = 18,       /* Digital Active - scb[0].uart_rx:0 */
    P10_0_PERI_TR_IO_INPUT20        = 24,       /* Digital Active - peri.tr_io_input[20]:0 */
    P10_0_PERI_TR_IO_OUTPUT0        = 25,       /* Digital Active - peri.tr_io_output[0]:5 */
    P10_0_CPUSS_TRACE_DATA3         = 27,       /* Digital Active - cpuss.trace_data[3]:3 */

    /* P10.1 */
    P10_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_1_AMUXA                     =  4,       /* Analog mux bus A */
    P10_1_AMUXB                     =  5,       /* Analog mux bus B */
    P10_1_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    P10_1_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */
    P10_1_SCB0_I2C_SDA              = 13,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */
    P10_1_SCB0_UART_TX              = 18,       /* Digital Active - scb[0].uart_tx:0 */
    P10_1_LVDS2USB32SS_LVDS_USEC_PULSE_O = 23,  /* Digital Active - lvds2usb32ss.lvds_usec_pulse_o:1 */
    P10_1_PERI_TR_IO_INPUT21        = 24,       /* Digital Active - peri.tr_io_input[21]:0 */
    P10_1_PERI_TR_IO_OUTPUT1        = 25,       /* Digital Active - peri.tr_io_output[1]:5 */
    P10_1_CPUSS_TRACE_DATA2         = 27,       /* Digital Active - cpuss.trace_data[2]:3 */

    /* P11.0 */
    P11_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_0_AMUXA                     =  4,       /* Analog mux bus A */
    P11_0_AMUXB                     =  5,       /* Analog mux bus B */
    P11_0_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    P11_0_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */
    P11_0_PDM0_PDM_CLK0             = 17,       /* Digital Active - pdm[0].pdm_clk[0]:3 */
    P11_0_SCB4_UART_TX              = 18,       /* Digital Active - scb[4].uart_tx:1 */
    P11_0_SCB4_I2C_SCL              = 19,       /* Digital Active - scb[4].i2c_scl:1 */
    P11_0_SCB4_SPI_CLK              = 20,       /* Digital Active - scb[4].spi_clk:1 */
    P11_0_PERI_TR_IO_INPUT23        = 24,       /* Digital Active - peri.tr_io_input[23]:0 */
    P11_0_PERI_TR_IO_OUTPUT0        = 25,       /* Digital Active - peri.tr_io_output[0]:6 */
    P11_0_CPUSS_TRACE_DATA1         = 27,       /* Digital Active - cpuss.trace_data[1]:3 */
    P11_0_LVDS2USB32SS_LNK0_L3_ENTRY_GPIO_I = 28, /* Digital Deep Sleep - lvds2usb32ss.lnk0_l3_entry_gpio_i:0 */
    P11_0_CPUSS_SWJ_SWO_TDO         = 29,       /* Digital Deep Sleep - cpuss.swj_swo_tdo */
    P11_0_SRSS_DDFT_PIN_IN0         = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[0]:0 */

    /* P11.1 */
    P11_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_1_AMUXA                     =  4,       /* Analog mux bus A */
    P11_1_AMUXB                     =  5,       /* Analog mux bus B */
    P11_1_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    P11_1_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */
    P11_1_PDM0_PDM_DATA0            = 17,       /* Digital Active - pdm[0].pdm_data[0]:3 */
    P11_1_SCB4_UART_RX              = 18,       /* Digital Active - scb[4].uart_rx:1 */
    P11_1_SCB4_I2C_SDA              = 19,       /* Digital Active - scb[4].i2c_sda:1 */
    P11_1_SCB4_SPI_SELECT0          = 20,       /* Digital Active - scb[4].spi_select0:1 */
    P11_1_PERI_TR_IO_INPUT24        = 24,       /* Digital Active - peri.tr_io_input[24]:0 */
    P11_1_PERI_TR_IO_OUTPUT1        = 25,       /* Digital Active - peri.tr_io_output[1]:6 */
    P11_1_CPUSS_TRACE_DATA0         = 27,       /* Digital Active - cpuss.trace_data[0]:3 */
    P11_1_LVDS2USB32SS_LNK1_L3_ENTRY_GPIO_I = 28, /* Digital Deep Sleep - lvds2usb32ss.lnk1_l3_entry_gpio_i:0 */
    P11_1_CPUSS_SWJ_SWDOE_TDI       = 29,       /* Digital Deep Sleep - cpuss.swj_swdoe_tdi */
    P11_1_SRSS_DDFT_PIN_IN1         = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[1]:0 */

    /* P11.2 */
    P11_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_2_AMUXA                     =  4,       /* Analog mux bus A */
    P11_2_AMUXB                     =  5,       /* Analog mux bus B */
    P11_2_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    P11_2_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */
    P11_2_PDM0_PDM_CLK1             = 17,       /* Digital Active - pdm[0].pdm_clk[1]:3 */
    P11_2_SCB4_UART_RTS             = 18,       /* Digital Active - scb[4].uart_rts:1 */
    P11_2_SCB4_SPI_MOSI             = 20,       /* Digital Active - scb[4].spi_mosi:1 */
    P11_2_LVDS2USB32SS_LVDS_USEC_PULSE_O = 23,  /* Digital Active - lvds2usb32ss.lvds_usec_pulse_o:0 */
    P11_2_CPUSS_FAULT_OUT0          = 25,       /* Digital Active - cpuss.fault_out[0]:5 */
    P11_2_CPUSS_SWJ_SWDIO_TMS       = 29,       /* Digital Deep Sleep - cpuss.swj_swdio_tms */

    /* P11.3 */
    P11_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_3_AMUXA                     =  4,       /* Analog mux bus A */
    P11_3_AMUXB                     =  5,       /* Analog mux bus B */
    P11_3_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    P11_3_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */
    P11_3_PDM0_PDM_DATA1            = 17,       /* Digital Active - pdm[0].pdm_data[1]:3 */
    P11_3_SCB4_UART_CTS             = 18,       /* Digital Active - scb[4].uart_cts:1 */
    P11_3_SCB4_SPI_MISO             = 20,       /* Digital Active - scb[4].spi_miso:1 */
    P11_3_CPUSS_FAULT_OUT1          = 25,       /* Digital Active - cpuss.fault_out[1]:5 */
    P11_3_CPUSS_SWJ_SWCLK_TCLK      = 29,       /* Digital Deep Sleep - cpuss.swj_swclk_tclk */

    /* P11.4 */
    P11_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_4_AMUXA                     =  4,       /* Analog mux bus A */
    P11_4_AMUXB                     =  5,       /* Analog mux bus B */
    P11_4_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    P11_4_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */
    P11_4_SCB5_UART_RX              = 18,       /* Digital Active - scb[5].uart_rx:1 */
    P11_4_SCB5_I2C_SCL              = 19,       /* Digital Active - scb[5].i2c_scl:1 */
    P11_4_CANFD0_TTCAN_RX           = 22,       /* Digital Active - canfd[0].ttcan_rx:3 */
    P11_4_CPUSS_SWJ_TRSTN           = 29,       /* Digital Deep Sleep - cpuss.swj_trstn */

    /* P11.5 */
    P11_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_5_AMUXA                     =  4,       /* Analog mux bus A */
    P11_5_AMUXB                     =  5,       /* Analog mux bus B */
    P11_5_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    P11_5_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */
    P11_5_SCB5_UART_TX              = 18,       /* Digital Active - scb[5].uart_tx:1 */
    P11_5_SCB5_I2C_SDA              = 19,       /* Digital Active - scb[5].i2c_sda:1 */
    P11_5_CANFD0_TTCAN_TX           = 22,       /* Digital Active - canfd[0].ttcan_tx:3 */
    P11_5_PERI_TR_IO_INPUT22        = 24,       /* Digital Active - peri.tr_io_input[22]:0 */
    P11_5_CPUSS_TRACE_CLOCK         = 26,       /* Digital Active - cpuss.trace_clock:3 */

    /* USBDM */
    USBDM_AMUXA                     =  4,       /* Analog mux bus A */
    USBDM_AMUXB                     =  5,       /* Analog mux bus B */
    USBDM_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    USBDM_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */

    /* USBDP */
    USBDP_AMUXA                     =  4,       /* Analog mux bus A */
    USBDP_AMUXB                     =  5,       /* Analog mux bus B */
    USBDP_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    USBDP_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */

    /* P13.0 */
    P13_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_0_AMUXA                     =  4,       /* Analog mux bus A */
    P13_0_AMUXB                     =  5,       /* Analog mux bus B */
    P13_0_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    P13_0_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */
    P13_0_SCB5_UART_RTS             = 18,       /* Digital Active - scb[5].uart_rts:0 */
    P13_0_SCB5_SPI_MOSI             = 20,       /* Digital Active - scb[5].spi_mosi */
    P13_0_CANFD0_TTCAN_TX           = 22,       /* Digital Active - canfd[0].ttcan_tx:1 */

    /* P13.1 */
    P13_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_1_AMUXA                     =  4,       /* Analog mux bus A */
    P13_1_AMUXB                     =  5,       /* Analog mux bus B */
    P13_1_AMUXA_DSI                 =  6,       /* Analog mux bus A, DSI control */
    P13_1_AMUXB_DSI                 =  7,       /* Analog mux bus B, DSI control */
    P13_1_SCB5_UART_CTS             = 18,       /* Digital Active - scb[5].uart_cts:0 */
    P13_1_SCB5_SPI_MISO             = 20        /* Digital Active - scb[5].spi_miso */
} en_hsiom_sel_t;

#endif /* _GPIO_FX3G2_169_BGA_H_ */


/* [] END OF FILE */
