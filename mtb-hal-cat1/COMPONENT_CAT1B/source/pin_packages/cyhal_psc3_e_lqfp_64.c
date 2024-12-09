/***************************************************************************//**
* \file cyhal_psc3_e_lqfp_64.c
*
* \brief
* PSC3 device GPIO HAL header for E-LQFP-64 package
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

#include "cy_device_headers.h"
#include "cyhal_hw_types.h"

#if defined(_GPIO_PSC3_E_LQFP_64_H_)
#include "pin_packages/cyhal_psc3_e_lqfp_64.h"

/* Pin connections */
/* Connections for: canfd_ttcan_rx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_canfd_ttcan_rx[4] = {
    {0u, 1u, P5_2, P5_2_CANFD0_TTCAN_RX1},
    {0u, 1u, P6_2, P6_2_CANFD0_TTCAN_RX1},
    {0u, 0u, P8_2, P8_2_CANFD0_TTCAN_RX0},
    {0u, 0u, P9_2, P9_2_CANFD0_TTCAN_RX0},
};

/* Connections for: canfd_ttcan_tx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_canfd_ttcan_tx[4] = {
    {0u, 1u, P5_3, P5_3_CANFD0_TTCAN_TX1},
    {0u, 1u, P6_3, P6_3_CANFD0_TTCAN_TX1},
    {0u, 0u, P8_3, P8_3_CANFD0_TTCAN_TX0},
    {0u, 0u, P9_3, P9_3_CANFD0_TTCAN_TX0},
};

/* Connections for: cpuss_clk_fm_pump */
const cyhal_resource_pin_mapping_t cyhal_pin_map_cpuss_clk_fm_pump[1] = {
    {0u, 0u, P9_3, P9_3_CPUSS_CLK_FM_PUMP},
};

/* Connections for: cpuss_fault */
const cyhal_resource_pin_mapping_t cyhal_pin_map_cpuss_fault[2] = {
    {0u, 0u, P6_3, P6_3_CPUSS_FAULT0},
    {0u, 0u, P9_3, P9_3_CPUSS_FAULT0},
};

/* Connections for: debug600_clk_swj_swclk_tclk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_debug600_clk_swj_swclk_tclk[1] = {
    {0u, 0u, P1_2, P1_2_DEBUG600_CLK_SWJ_SWCLK_TCLK},
};

/* Connections for: debug600_rst_swj_trstn */
const cyhal_resource_pin_mapping_t cyhal_pin_map_debug600_rst_swj_trstn[1] = {
    {0u, 0u, P8_0, P8_0_DEBUG600_RST_SWJ_TRSTN},
};

/* Connections for: debug600_swj_swdio_tms */
const cyhal_resource_pin_mapping_t cyhal_pin_map_debug600_swj_swdio_tms[1] = {
    {0u, 0u, P1_3, P1_3_DEBUG600_SWJ_SWDIO_TMS},
};

/* Connections for: debug600_swj_swdoe_tdi */
const cyhal_resource_pin_mapping_t cyhal_pin_map_debug600_swj_swdoe_tdi[1] = {
    {0u, 0u, P2_0, P2_0_DEBUG600_SWJ_SWDOE_TDI},
};

/* Connections for: debug600_swj_swo_tdo */
const cyhal_resource_pin_mapping_t cyhal_pin_map_debug600_swj_swo_tdo[1] = {
    {0u, 0u, P2_1, P2_1_DEBUG600_SWJ_SWO_TDO},
};

/* Connections for: debug600_trace_clock */
const cyhal_resource_pin_mapping_t cyhal_pin_map_debug600_trace_clock[2] = {
    {0u, 0u, P7_4, P7_4_DEBUG600_TRACE_CLOCK},
    {0u, 0u, P9_2, P9_2_DEBUG600_TRACE_CLOCK},
};

/* Connections for: debug600_trace_data */
const cyhal_resource_pin_mapping_t cyhal_pin_map_debug600_trace_data[8] = {
    {0u, 0u, P7_0, P7_0_DEBUG600_TRACE_DATA0},
    {0u, 1u, P7_1, P7_1_DEBUG600_TRACE_DATA1},
    {0u, 2u, P7_2, P7_2_DEBUG600_TRACE_DATA2},
    {0u, 3u, P7_3, P7_3_DEBUG600_TRACE_DATA3},
    {0u, 0u, P8_0, P8_0_DEBUG600_TRACE_DATA0},
    {0u, 1u, P8_1, P8_1_DEBUG600_TRACE_DATA1},
    {0u, 2u, P8_2, P8_2_DEBUG600_TRACE_DATA2},
    {0u, 3u, P8_3, P8_3_DEBUG600_TRACE_DATA3},
};

/* Connections for: lpcomp_inn_comp */
const cyhal_resource_pin_mapping_t cyhal_pin_map_lpcomp_inn_comp[2] = {
    {0u, 0u, P8_1, HSIOM_SEL_GPIO},
    {0u, 1u, P8_3, HSIOM_SEL_GPIO},
};

/* Connections for: lpcomp_inp_comp */
const cyhal_resource_pin_mapping_t cyhal_pin_map_lpcomp_inp_comp[2] = {
    {0u, 0u, P8_0, HSIOM_SEL_GPIO},
    {0u, 1u, P8_2, HSIOM_SEL_GPIO},
};

/* Connections for: pass_an_a_pad_aio */
const cyhal_resource_pin_mapping_t cyhal_pin_map_pass_an_a_pad_aio[8] = {
    {0u, 0u, AN_A0, HSIOM_SEL_GPIO},
    {0u, 1u, AN_A1, HSIOM_SEL_GPIO},
    {0u, 2u, AN_A2, HSIOM_SEL_GPIO},
    {0u, 3u, AN_A3, HSIOM_SEL_GPIO},
    {0u, 4u, AN_A4, HSIOM_SEL_GPIO},
    {0u, 5u, AN_A5, HSIOM_SEL_GPIO},
    {0u, 6u, AN_A6, HSIOM_SEL_GPIO},
    {0u, 7u, AN_A7, HSIOM_SEL_GPIO},
};

/* Connections for: pass_an_b_pad_aio */
const cyhal_resource_pin_mapping_t cyhal_pin_map_pass_an_b_pad_aio[8] = {
    {0u, 8u, AN_B0, HSIOM_SEL_GPIO},
    {0u, 9u, AN_B1, HSIOM_SEL_GPIO},
    {0u, 10u, AN_B2, HSIOM_SEL_GPIO},
    {0u, 11u, AN_B3, HSIOM_SEL_GPIO},
    {0u, 12u, AN_B4, HSIOM_SEL_GPIO},
    {0u, 13u, AN_B5, HSIOM_SEL_GPIO},
    {0u, 14u, AN_B6, HSIOM_SEL_GPIO},
    {0u, 15u, AN_B7, HSIOM_SEL_GPIO},
};

/* Connections for: pass_gpio_00_aio */
const cyhal_resource_pin_mapping_t cyhal_pin_map_pass_gpio_00_aio[1] = {
    {0u, 0u, P8_0, HSIOM_SEL_GPIO},
};

/* Connections for: pass_gpio_01_aio */
const cyhal_resource_pin_mapping_t cyhal_pin_map_pass_gpio_01_aio[1] = {
    {0u, 0u, P8_2, HSIOM_SEL_GPIO},
};

/* Connections for: pass_mcpass_dclk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_pass_mcpass_dclk[2] = {
    {0u, 0u, P7_4, P7_4_PASS_MCPASS_DCLK},
    {0u, 0u, P9_2, P9_2_PASS_MCPASS_DCLK},
};

/* Connections for: pass_mcpass_dout */
const cyhal_resource_pin_mapping_t cyhal_pin_map_pass_mcpass_dout[8] = {
    {0u, 0u, P7_0, P7_0_PASS_MCPASS_DOUT0},
    {0u, 1u, P7_1, P7_1_PASS_MCPASS_DOUT1},
    {0u, 2u, P7_2, P7_2_PASS_MCPASS_DOUT2},
    {0u, 3u, P7_3, P7_3_PASS_MCPASS_DOUT3},
    {0u, 0u, P8_0, P8_0_PASS_MCPASS_DOUT0},
    {0u, 1u, P8_1, P8_1_PASS_MCPASS_DOUT1},
    {0u, 2u, P8_2, P8_2_PASS_MCPASS_DOUT2},
    {0u, 3u, P8_3, P8_3_PASS_MCPASS_DOUT3},
};

/* Connections for: peri_tr_io_input */
/* The actual channel_num has no value to how the connection works. However, the HAL driver needs
   to know the index of the input or output trigger line. Store that in the channel_num field
   instead. */
const cyhal_resource_pin_mapping_t cyhal_pin_map_peri_tr_io_input[39] = {
    {0u, 0u, P0_0, P0_0_PERI_TR_IO_INPUT0},
    {0u, 1u, P0_1, P0_1_PERI_TR_IO_INPUT1},
    {0u, 2u, P1_0, P1_0_PERI_TR_IO_INPUT2},
    {0u, 3u, P1_1, P1_1_PERI_TR_IO_INPUT3},
    {0u, 4u, P1_2, P1_2_PERI_TR_IO_INPUT4},
    {0u, 5u, P1_3, P1_3_PERI_TR_IO_INPUT5},
    {0u, 6u, P2_0, P2_0_PERI_TR_IO_INPUT6},
    {0u, 7u, P2_1, P2_1_PERI_TR_IO_INPUT7},
    {0u, 8u, P2_2, P2_2_PERI_TR_IO_INPUT8},
    {0u, 9u, P2_3, P2_3_PERI_TR_IO_INPUT9},
    {0u, 14u, P4_0, P4_0_PERI_TR_IO_INPUT14},
    {0u, 15u, P4_1, P4_1_PERI_TR_IO_INPUT15},
    {0u, 16u, P4_2, P4_2_PERI_TR_IO_INPUT16},
    {0u, 17u, P4_3, P4_3_PERI_TR_IO_INPUT17},
    {0u, 18u, P4_4, P4_4_PERI_TR_IO_INPUT18},
    {0u, 19u, P4_5, P4_5_PERI_TR_IO_INPUT19},
    {0u, 20u, P4_6, P4_6_PERI_TR_IO_INPUT20},
    {0u, 21u, P4_7, P4_7_PERI_TR_IO_INPUT21},
    {0u, 22u, P5_0, P5_0_PERI_TR_IO_INPUT22},
    {0u, 23u, P5_1, P5_1_PERI_TR_IO_INPUT23},
    {0u, 24u, P5_2, P5_2_PERI_TR_IO_INPUT24},
    {0u, 25u, P5_3, P5_3_PERI_TR_IO_INPUT25},
    {0u, 26u, P6_0, P6_0_PERI_TR_IO_INPUT26},
    {0u, 27u, P6_1, P6_1_PERI_TR_IO_INPUT27},
    {0u, 28u, P6_2, P6_2_PERI_TR_IO_INPUT28},
    {0u, 29u, P6_3, P6_3_PERI_TR_IO_INPUT29},
    {0u, 30u, P7_0, P7_0_PERI_TR_IO_INPUT30},
    {0u, 31u, P7_1, P7_1_PERI_TR_IO_INPUT31},
    {0u, 32u, P7_2, P7_2_PERI_TR_IO_INPUT32},
    {0u, 33u, P7_3, P7_3_PERI_TR_IO_INPUT33},
    {0u, 34u, P7_4, P7_4_PERI_TR_IO_INPUT34},
    {0u, 38u, P8_0, P8_0_PERI_TR_IO_INPUT38},
    {0u, 39u, P8_1, P8_1_PERI_TR_IO_INPUT39},
    {0u, 40u, P8_2, P8_2_PERI_TR_IO_INPUT40},
    {0u, 41u, P8_3, P8_3_PERI_TR_IO_INPUT41},
    {0u, 44u, P9_0, P9_0_PERI_TR_IO_INPUT44},
    {0u, 45u, P9_1, P9_1_PERI_TR_IO_INPUT45},
    {0u, 46u, P9_2, P9_2_PERI_TR_IO_INPUT46},
    {0u, 47u, P9_3, P9_3_PERI_TR_IO_INPUT47},
};

/* Connections for: peri_tr_io_output */
/* The actual channel_num has no value to how the connection works. However, the HAL driver needs
   to know the index of the input or output trigger line. Store that in the channel_num field
   instead. */
const cyhal_resource_pin_mapping_t cyhal_pin_map_peri_tr_io_output[80] = {
    {0u, 0u, P0_0, P0_0_PERI_TR_IO_OUTPUT0},
    {0u, 1u, P0_1, P0_1_PERI_TR_IO_OUTPUT1},
    {0u, 2u, P1_0, P1_0_PERI_TR_IO_OUTPUT2},
    {0u, 58u, P1_0, P1_0_PERI_TR_IO_OUTPUT58},
    {0u, 70u, P1_0, P1_0_PERI_TR_IO_OUTPUT70},
    {0u, 3u, P1_1, P1_1_PERI_TR_IO_OUTPUT3},
    {0u, 59u, P1_1, P1_1_PERI_TR_IO_OUTPUT59},
    {0u, 71u, P1_1, P1_1_PERI_TR_IO_OUTPUT71},
    {0u, 4u, P1_2, P1_2_PERI_TR_IO_OUTPUT4},
    {0u, 60u, P1_2, P1_2_PERI_TR_IO_OUTPUT60},
    {0u, 72u, P1_2, P1_2_PERI_TR_IO_OUTPUT72},
    {0u, 5u, P1_3, P1_3_PERI_TR_IO_OUTPUT5},
    {0u, 61u, P1_3, P1_3_PERI_TR_IO_OUTPUT61},
    {0u, 73u, P1_3, P1_3_PERI_TR_IO_OUTPUT73},
    {0u, 6u, P2_0, P2_0_PERI_TR_IO_OUTPUT6},
    {0u, 58u, P2_0, P2_0_PERI_TR_IO_OUTPUT58},
    {0u, 7u, P2_1, P2_1_PERI_TR_IO_OUTPUT7},
    {0u, 59u, P2_1, P2_1_PERI_TR_IO_OUTPUT59},
    {0u, 8u, P2_2, P2_2_PERI_TR_IO_OUTPUT8},
    {0u, 60u, P2_2, P2_2_PERI_TR_IO_OUTPUT60},
    {0u, 9u, P2_3, P2_3_PERI_TR_IO_OUTPUT9},
    {0u, 61u, P2_3, P2_3_PERI_TR_IO_OUTPUT61},
    {0u, 14u, P4_0, P4_0_PERI_TR_IO_OUTPUT14},
    {0u, 50u, P4_0, P4_0_PERI_TR_IO_OUTPUT50},
    {0u, 15u, P4_1, P4_1_PERI_TR_IO_OUTPUT15},
    {0u, 51u, P4_1, P4_1_PERI_TR_IO_OUTPUT51},
    {0u, 16u, P4_2, P4_2_PERI_TR_IO_OUTPUT16},
    {0u, 52u, P4_2, P4_2_PERI_TR_IO_OUTPUT52},
    {0u, 17u, P4_3, P4_3_PERI_TR_IO_OUTPUT17},
    {0u, 53u, P4_3, P4_3_PERI_TR_IO_OUTPUT53},
    {0u, 18u, P4_4, P4_4_PERI_TR_IO_OUTPUT18},
    {0u, 54u, P4_4, P4_4_PERI_TR_IO_OUTPUT54},
    {0u, 19u, P4_5, P4_5_PERI_TR_IO_OUTPUT19},
    {0u, 55u, P4_5, P4_5_PERI_TR_IO_OUTPUT55},
    {0u, 20u, P4_6, P4_6_PERI_TR_IO_OUTPUT20},
    {0u, 56u, P4_6, P4_6_PERI_TR_IO_OUTPUT56},
    {0u, 21u, P4_7, P4_7_PERI_TR_IO_OUTPUT21},
    {0u, 57u, P4_7, P4_7_PERI_TR_IO_OUTPUT57},
    {0u, 22u, P5_0, P5_0_PERI_TR_IO_OUTPUT22},
    {0u, 62u, P5_0, P5_0_PERI_TR_IO_OUTPUT62},
    {0u, 23u, P5_1, P5_1_PERI_TR_IO_OUTPUT23},
    {0u, 63u, P5_1, P5_1_PERI_TR_IO_OUTPUT63},
    {0u, 24u, P5_2, P5_2_PERI_TR_IO_OUTPUT24},
    {0u, 64u, P5_2, P5_2_PERI_TR_IO_OUTPUT64},
    {0u, 25u, P5_3, P5_3_PERI_TR_IO_OUTPUT25},
    {0u, 65u, P5_3, P5_3_PERI_TR_IO_OUTPUT65},
    {0u, 26u, P6_0, P6_0_PERI_TR_IO_OUTPUT26},
    {0u, 66u, P6_0, P6_0_PERI_TR_IO_OUTPUT66},
    {0u, 27u, P6_1, P6_1_PERI_TR_IO_OUTPUT27},
    {0u, 67u, P6_1, P6_1_PERI_TR_IO_OUTPUT67},
    {0u, 28u, P6_2, P6_2_PERI_TR_IO_OUTPUT28},
    {0u, 68u, P6_2, P6_2_PERI_TR_IO_OUTPUT68},
    {0u, 29u, P6_3, P6_3_PERI_TR_IO_OUTPUT29},
    {0u, 69u, P6_3, P6_3_PERI_TR_IO_OUTPUT69},
    {0u, 30u, P7_0, P7_0_PERI_TR_IO_OUTPUT30},
    {0u, 50u, P7_0, P7_0_PERI_TR_IO_OUTPUT50},
    {0u, 70u, P7_0, P7_0_PERI_TR_IO_OUTPUT70},
    {0u, 31u, P7_1, P7_1_PERI_TR_IO_OUTPUT31},
    {0u, 51u, P7_1, P7_1_PERI_TR_IO_OUTPUT51},
    {0u, 71u, P7_1, P7_1_PERI_TR_IO_OUTPUT71},
    {0u, 32u, P7_2, P7_2_PERI_TR_IO_OUTPUT32},
    {0u, 52u, P7_2, P7_2_PERI_TR_IO_OUTPUT52},
    {0u, 72u, P7_2, P7_2_PERI_TR_IO_OUTPUT72},
    {0u, 33u, P7_3, P7_3_PERI_TR_IO_OUTPUT33},
    {0u, 53u, P7_3, P7_3_PERI_TR_IO_OUTPUT53},
    {0u, 73u, P7_3, P7_3_PERI_TR_IO_OUTPUT73},
    {0u, 34u, P7_4, P7_4_PERI_TR_IO_OUTPUT34},
    {0u, 54u, P7_4, P7_4_PERI_TR_IO_OUTPUT54},
    {0u, 38u, P8_0, P8_0_PERI_TR_IO_OUTPUT38},
    {0u, 62u, P8_0, P8_0_PERI_TR_IO_OUTPUT62},
    {0u, 39u, P8_1, P8_1_PERI_TR_IO_OUTPUT39},
    {0u, 63u, P8_1, P8_1_PERI_TR_IO_OUTPUT63},
    {0u, 40u, P8_2, P8_2_PERI_TR_IO_OUTPUT40},
    {0u, 64u, P8_2, P8_2_PERI_TR_IO_OUTPUT64},
    {0u, 41u, P8_3, P8_3_PERI_TR_IO_OUTPUT41},
    {0u, 65u, P8_3, P8_3_PERI_TR_IO_OUTPUT65},
    {0u, 44u, P9_0, P9_0_PERI_TR_IO_OUTPUT44},
    {0u, 45u, P9_1, P9_1_PERI_TR_IO_OUTPUT45},
    {0u, 46u, P9_2, P9_2_PERI_TR_IO_OUTPUT46},
    {0u, 47u, P9_3, P9_3_PERI_TR_IO_OUTPUT47},
};

/* Connections for: scb_i2c_scl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_i2c_scl[8] = {
    {1u, 0u, P1_3, P1_3_SCB1_I2C_SCL},
    {1u, 0u, P2_1, P2_1_SCB1_I2C_SCL},
    {4u, 0u, P4_2, P4_2_SCB4_I2C_SCL},
    {3u, 0u, P5_1, P5_1_SCB3_I2C_SCL},
    {3u, 0u, P6_1, P6_1_SCB3_I2C_SCL},
    {2u, 0u, P7_0, P7_0_SCB2_I2C_SCL},
    {5u, 0u, P8_1, P8_1_SCB5_I2C_SCL},
    {0u, 0u, P9_0, P9_0_SCB0_I2C_SCL},
};

/* Connections for: scb_i2c_sda */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_i2c_sda[8] = {
    {1u, 0u, P1_2, P1_2_SCB1_I2C_SDA},
    {1u, 0u, P2_2, P2_2_SCB1_I2C_SDA},
    {4u, 0u, P4_1, P4_1_SCB4_I2C_SDA},
    {3u, 0u, P5_0, P5_0_SCB3_I2C_SDA},
    {3u, 0u, P6_0, P6_0_SCB3_I2C_SDA},
    {2u, 0u, P7_1, P7_1_SCB2_I2C_SDA},
    {5u, 0u, P8_3, P8_3_SCB5_I2C_SDA},
    {0u, 0u, P9_2, P9_2_SCB0_I2C_SDA},
};

/* Connections for: scb_spi_m_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_clk[8] = {
    {1u, 0u, P1_1, P1_1_SCB1_SPI_CLK},
    {1u, 0u, P2_1, P2_1_SCB1_SPI_CLK},
    {4u, 0u, P4_2, P4_2_SCB4_SPI_CLK},
    {3u, 0u, P5_2, P5_2_SCB3_SPI_CLK},
    {3u, 0u, P6_2, P6_2_SCB3_SPI_CLK},
    {2u, 0u, P7_0, P7_0_SCB2_SPI_CLK},
    {5u, 0u, P8_3, P8_3_SCB5_SPI_CLK},
    {0u, 0u, P9_0, P9_0_SCB0_SPI_CLK},
};

/* Connections for: scb_spi_m_miso */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_miso[8] = {
    {1u, 0u, P1_3, P1_3_SCB1_SPI_MISO},
    {1u, 0u, P2_3, P2_3_SCB1_SPI_MISO},
    {4u, 0u, P4_1, P4_1_SCB4_SPI_MISO},
    {3u, 0u, P5_1, P5_1_SCB3_SPI_MISO},
    {3u, 0u, P6_1, P6_1_SCB3_SPI_MISO},
    {2u, 0u, P7_2, P7_2_SCB2_SPI_MISO},
    {5u, 0u, P8_2, P8_2_SCB5_SPI_MISO},
    {0u, 0u, P9_3, P9_3_SCB0_SPI_MISO},
};

/* Connections for: scb_spi_m_mosi */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_mosi[8] = {
    {1u, 0u, P1_2, P1_2_SCB1_SPI_MOSI},
    {1u, 0u, P2_2, P2_2_SCB1_SPI_MOSI},
    {4u, 0u, P4_0, P4_0_SCB4_SPI_MOSI},
    {3u, 0u, P5_0, P5_0_SCB3_SPI_MOSI},
    {3u, 0u, P6_0, P6_0_SCB3_SPI_MOSI},
    {2u, 0u, P7_1, P7_1_SCB2_SPI_MOSI},
    {5u, 0u, P8_1, P8_1_SCB5_SPI_MOSI},
    {0u, 0u, P9_2, P9_2_SCB0_SPI_MOSI},
};

/* Connections for: scb_spi_m_select0 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select0[8] = {
    {1u, 0u, P1_0, P1_0_SCB1_SPI_SELECT0},
    {1u, 0u, P2_0, P2_0_SCB1_SPI_SELECT0},
    {4u, 0u, P4_3, P4_3_SCB4_SPI_SELECT0},
    {3u, 0u, P5_3, P5_3_SCB3_SPI_SELECT0},
    {3u, 0u, P6_3, P6_3_SCB3_SPI_SELECT0},
    {2u, 0u, P7_3, P7_3_SCB2_SPI_SELECT0},
    {5u, 0u, P8_0, P8_0_SCB5_SPI_SELECT0},
    {0u, 0u, P9_1, P9_1_SCB0_SPI_SELECT0},
};

/* Connections for: scb_spi_m_select1 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select1[1] = {
    {2u, 0u, P7_4, P7_4_SCB2_SPI_SELECT1},
};

/* Connections for: scb_spi_m_select2 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select2[1] = {
    {0u, 0u, NC, HSIOM_SEL_GPIO},
};

/* Connections for: scb_spi_s_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_clk[8] = {
    {1u, 0u, P1_1, P1_1_SCB1_SPI_CLK},
    {1u, 0u, P2_1, P2_1_SCB1_SPI_CLK},
    {4u, 0u, P4_2, P4_2_SCB4_SPI_CLK},
    {3u, 0u, P5_2, P5_2_SCB3_SPI_CLK},
    {3u, 0u, P6_2, P6_2_SCB3_SPI_CLK},
    {2u, 0u, P7_0, P7_0_SCB2_SPI_CLK},
    {5u, 0u, P8_3, P8_3_SCB5_SPI_CLK},
    {0u, 0u, P9_0, P9_0_SCB0_SPI_CLK},
};

/* Connections for: scb_spi_s_miso */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_miso[8] = {
    {1u, 0u, P1_3, P1_3_SCB1_SPI_MISO},
    {1u, 0u, P2_3, P2_3_SCB1_SPI_MISO},
    {4u, 0u, P4_1, P4_1_SCB4_SPI_MISO},
    {3u, 0u, P5_1, P5_1_SCB3_SPI_MISO},
    {3u, 0u, P6_1, P6_1_SCB3_SPI_MISO},
    {2u, 0u, P7_2, P7_2_SCB2_SPI_MISO},
    {5u, 0u, P8_2, P8_2_SCB5_SPI_MISO},
    {0u, 0u, P9_3, P9_3_SCB0_SPI_MISO},
};

/* Connections for: scb_spi_s_mosi */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_mosi[8] = {
    {1u, 0u, P1_2, P1_2_SCB1_SPI_MOSI},
    {1u, 0u, P2_2, P2_2_SCB1_SPI_MOSI},
    {4u, 0u, P4_0, P4_0_SCB4_SPI_MOSI},
    {3u, 0u, P5_0, P5_0_SCB3_SPI_MOSI},
    {3u, 0u, P6_0, P6_0_SCB3_SPI_MOSI},
    {2u, 0u, P7_1, P7_1_SCB2_SPI_MOSI},
    {5u, 0u, P8_1, P8_1_SCB5_SPI_MOSI},
    {0u, 0u, P9_2, P9_2_SCB0_SPI_MOSI},
};

/* Connections for: scb_spi_s_select0 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select0[8] = {
    {1u, 0u, P1_0, P1_0_SCB1_SPI_SELECT0},
    {1u, 0u, P2_0, P2_0_SCB1_SPI_SELECT0},
    {4u, 0u, P4_3, P4_3_SCB4_SPI_SELECT0},
    {3u, 0u, P5_3, P5_3_SCB3_SPI_SELECT0},
    {3u, 0u, P6_3, P6_3_SCB3_SPI_SELECT0},
    {2u, 0u, P7_3, P7_3_SCB2_SPI_SELECT0},
    {5u, 0u, P8_0, P8_0_SCB5_SPI_SELECT0},
    {0u, 0u, P9_1, P9_1_SCB0_SPI_SELECT0},
};

/* Connections for: scb_spi_s_select1 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select1[1] = {
    {2u, 0u, P7_4, P7_4_SCB2_SPI_SELECT1},
};

/* Connections for: scb_spi_s_select2 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select2[1] = {
    {0u, 0u, NC, HSIOM_SEL_GPIO},
};

/* Connections for: scb_uart_cts */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_cts[8] = {
    {1u, 0u, P1_0, P1_0_SCB1_UART_CTS},
    {1u, 0u, P2_0, P2_0_SCB1_UART_CTS},
    {4u, 0u, P4_0, P4_0_SCB4_UART_CTS},
    {3u, 0u, P5_0, P5_0_SCB3_UART_CTS},
    {3u, 0u, P6_0, P6_0_SCB3_UART_CTS},
    {2u, 0u, P7_0, P7_0_SCB2_UART_CTS},
    {5u, 0u, P8_0, P8_0_SCB5_UART_CTS},
    {0u, 0u, P9_0, P9_0_SCB0_UART_CTS},
};

/* Connections for: scb_uart_rts */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_rts[8] = {
    {1u, 0u, P1_1, P1_1_SCB1_UART_RTS},
    {1u, 0u, P2_1, P2_1_SCB1_UART_RTS},
    {4u, 0u, P4_1, P4_1_SCB4_UART_RTS},
    {3u, 0u, P5_1, P5_1_SCB3_UART_RTS},
    {3u, 0u, P6_1, P6_1_SCB3_UART_RTS},
    {2u, 0u, P7_3, P7_3_SCB2_UART_RTS},
    {5u, 0u, P8_2, P8_2_SCB5_UART_RTS},
    {0u, 0u, P9_1, P9_1_SCB0_UART_RTS},
};

/* Connections for: scb_uart_rx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_rx[8] = {
    {1u, 0u, P1_2, P1_2_SCB1_UART_RX},
    {1u, 0u, P2_2, P2_2_SCB1_UART_RX},
    {4u, 0u, P4_2, P4_2_SCB4_UART_RX},
    {3u, 0u, P5_2, P5_2_SCB3_UART_RX},
    {3u, 0u, P6_2, P6_2_SCB3_UART_RX},
    {2u, 0u, P7_2, P7_2_SCB2_UART_RX},
    {5u, 0u, P8_1, P8_1_SCB5_UART_RX},
    {0u, 0u, P9_2, P9_2_SCB0_UART_RX},
};

/* Connections for: scb_uart_tx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_tx[8] = {
    {1u, 0u, P1_3, P1_3_SCB1_UART_TX},
    {1u, 0u, P2_3, P2_3_SCB1_UART_TX},
    {4u, 0u, P4_3, P4_3_SCB4_UART_TX},
    {3u, 0u, P5_3, P5_3_SCB3_UART_TX},
    {3u, 0u, P6_3, P6_3_SCB3_UART_TX},
    {2u, 0u, P7_1, P7_1_SCB2_UART_TX},
    {5u, 0u, P8_3, P8_3_SCB5_UART_TX},
    {0u, 0u, P9_3, P9_3_SCB0_UART_TX},
};

/* Connections for: tcpwm_line */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tcpwm_line[14] = {
    {2u, 6u, P2_0, P2_0_TCPWM0_LINE518},
    {2u, 7u, P2_2, P2_2_TCPWM0_LINE519},
    {1u, 4u, P4_0, P4_0_TCPWM0_LINE260},
    {1u, 5u, P4_2, P4_2_TCPWM0_LINE261},
    {1u, 6u, P4_4, P4_4_TCPWM0_LINE262},
    {1u, 7u, P4_6, P4_6_TCPWM0_LINE263},
    {1u, 4u, P6_0, P6_0_TCPWM0_LINE260},
    {1u, 5u, P6_2, P6_2_TCPWM0_LINE261},
    {1u, 6u, P7_0, P7_0_TCPWM0_LINE262},
    {1u, 7u, P7_2, P7_2_TCPWM0_LINE263},
    {2u, 4u, P8_0, P8_0_TCPWM0_LINE516},
    {2u, 5u, P8_2, P8_2_TCPWM0_LINE517},
    {2u, 6u, P9_0, P9_0_TCPWM0_LINE518},
    {2u, 7u, P9_2, P9_2_TCPWM0_LINE519},
};

/* Connections for: tcpwm_line_compl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tcpwm_line_compl[14] = {
    {2u, 6u, P2_1, P2_1_TCPWM0_LINE_COMPL518},
    {2u, 7u, P2_3, P2_3_TCPWM0_LINE_COMPL519},
    {1u, 4u, P4_1, P4_1_TCPWM0_LINE_COMPL260},
    {1u, 5u, P4_3, P4_3_TCPWM0_LINE_COMPL261},
    {1u, 6u, P4_5, P4_5_TCPWM0_LINE_COMPL262},
    {1u, 7u, P4_7, P4_7_TCPWM0_LINE_COMPL263},
    {1u, 4u, P6_1, P6_1_TCPWM0_LINE_COMPL260},
    {1u, 5u, P6_3, P6_3_TCPWM0_LINE_COMPL261},
    {1u, 6u, P7_1, P7_1_TCPWM0_LINE_COMPL262},
    {1u, 7u, P7_3, P7_3_TCPWM0_LINE_COMPL263},
    {2u, 4u, P8_1, P8_1_TCPWM0_LINE_COMPL516},
    {2u, 5u, P8_3, P8_3_TCPWM0_LINE_COMPL517},
    {2u, 6u, P9_1, P9_1_TCPWM0_LINE_COMPL518},
    {2u, 7u, P9_3, P9_3_TCPWM0_LINE_COMPL519},
};

#endif
