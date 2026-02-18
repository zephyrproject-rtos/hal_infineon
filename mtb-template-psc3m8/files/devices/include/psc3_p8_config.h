/***************************************************************************//**
* PSC3_P8 device configuration header
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

#ifndef _PSC3_P8_CONFIG_H_
#define _PSC3_P8_CONFIG_H_

/* Clock Connections */
typedef enum
{
    PCLK_DEBUG600_CLOCK_TRACE_IN    = 0x0000u,  /* debug600.clock_trace_in */
    PCLK_CRYPTOLITE_CLK_HF          = 0x0100u,  /* cryptolite.clk_hf */
    PCLK_IOSS_CLK_HF                = 0x0200u,  /* ioss.clk_hf */
    PCLK_TCPWM0_CLOCK_COUNTER_EN0   = 0x0201u,  /* tcpwm[0].clock_counter_en[0] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN1   = 0x0202u,  /* tcpwm[0].clock_counter_en[1] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN256 = 0x0203u,  /* tcpwm[0].clock_counter_en[256] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN257 = 0x0204u,  /* tcpwm[0].clock_counter_en[257] */
    PCLK_SCB0_CLOCK_SCB_EN          = 0x0300u,  /* scb[0].clock_scb_en */
    PCLK_SCB0_CLOCK_TGS_EN          = 0x0301u,  /* scb[0].clock_tgs_en */
    PCLK_SCB1_CLOCK_SCB_EN          = 0x0302u,  /* scb[1].clock_scb_en */
    PCLK_SCB1_CLOCK_TGS_EN          = 0x0303u,  /* scb[1].clock_tgs_en */
    PCLK_SCB2_CLOCK_SCB_EN          = 0x0304u,  /* scb[2].clock_scb_en */
    PCLK_SCB2_CLOCK_TGS_EN          = 0x0305u,  /* scb[2].clock_tgs_en */
    PCLK_SCB3_CLOCK_SCB_EN          = 0x0306u,  /* scb[3].clock_scb_en */
    PCLK_SCB3_CLOCK_TGS_EN          = 0x0307u,  /* scb[3].clock_tgs_en */
    PCLK_SCB4_CLOCK_SCB_EN          = 0x0308u,  /* scb[4].clock_scb_en */
    PCLK_SCB4_CLOCK_TGS_EN          = 0x0309u,  /* scb[4].clock_tgs_en */
    PCLK_CANFD0_CLOCK_CAN_EN0       = 0x030Au,  /* canfd[0].clock_can_en[0] */
    PCLK_CANFD0_CLOCK_CAN_EN1       = 0x030Bu,  /* canfd[0].clock_can_en[1] */
    PCLK_SCB5_CLOCK_SCB_EN          = 0x0500u,  /* scb[5].clock_scb_en */
    PCLK_SCB5_CLOCK_TGS_EN          = 0x0501u,  /* scb[5].clock_tgs_en */
    PCLK_SCB6_CLOCK_SCB_EN          = 0x0502u,  /* scb[6].clock_scb_en */
    PCLK_SCB6_CLOCK_TGS_EN          = 0x0503u   /* scb[6].clock_tgs_en */
} en_clk_dst_t;

/* Trigger Group */
/* This section contains the enums related to the Trigger multiplexer (TrigMux) driver.
* Refer to the Cypress Peripheral Driver Library Documentation, section Trigger multiplexer (TrigMux) -> Enumerated Types for details.
*/
/* Trigger Group Inputs */
/* Trigger Input Group 0 - P-DMA0 Request Assignments */
typedef enum
{
    TRIG_IN_MUX_0_PDMA0_TR_OUT0     = 0x00000001u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT1     = 0x00000002u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT2     = 0x00000003u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT3     = 0x00000004u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT0_0 = 0x00000005u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT0_1 = 0x00000006u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT0_256 = 0x00000007u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT0_257 = 0x00000008u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT1_0 = 0x00000009u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT1_1 = 0x0000000Au, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT1_256 = 0x0000000Bu, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT1_257 = 0x0000000Cu, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT0     = 0x0000000Du, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT1     = 0x0000000Eu, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT2     = 0x0000000Fu, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT3     = 0x00000010u, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT4     = 0x00000011u, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT5     = 0x00000012u, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT6     = 0x00000013u, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT7     = 0x00000014u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT8     = 0x00000015u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT9     = 0x00000016u, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT10    = 0x00000017u, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT11    = 0x00000018u, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT12    = 0x00000019u, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT13    = 0x0000001Au, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT14    = 0x0000001Bu, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT15    = 0x0000001Cu, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT16    = 0x0000001Du, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT17    = 0x0000001Eu, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT18    = 0x0000001Fu, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT19    = 0x00000020u, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT20    = 0x00000021u, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT21    = 0x00000022u, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT22    = 0x00000023u, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT23    = 0x00000024u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT24    = 0x00000025u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT25    = 0x00000026u, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT26    = 0x00000027u, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT27    = 0x00000028u, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT28    = 0x00000029u, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT29    = 0x0000002Au, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT30    = 0x0000002Bu, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT31    = 0x0000002Cu, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT32    = 0x0000002Du, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT33    = 0x0000002Eu, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT34    = 0x0000002Fu, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT35    = 0x00000030u, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT36    = 0x00000031u, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT37    = 0x00000032u, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT38    = 0x00000033u, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT39    = 0x00000034u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT40    = 0x00000035u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT41    = 0x00000036u, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT42    = 0x00000037u, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT43    = 0x00000038u, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT44    = 0x00000039u, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT45    = 0x0000003Au, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT46    = 0x0000003Bu, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT47    = 0x0000003Cu, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT48    = 0x0000003Du, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT49    = 0x0000003Eu, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT50    = 0x0000003Fu, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT51    = 0x00000040u, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT52    = 0x00000041u, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT53    = 0x00000042u, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT54    = 0x00000043u, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT55    = 0x00000044u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT56    = 0x00000045u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT57    = 0x00000046u, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT58    = 0x00000047u, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT59    = 0x00000048u, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_0_SCB_I2C_SCL0      = 0x00000049u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX0           = 0x0000004Au, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX0           = 0x0000004Bu, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD00  = 0x0000004Cu, /* scb[0].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP00    = 0x0000004Du, /* scb[0].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED00   = 0x0000004Eu, /* scb[0].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_SCB_I2C_SCL1      = 0x0000004Fu, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX1           = 0x00000050u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX1           = 0x00000051u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD10  = 0x00000052u, /* scb[1].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP10    = 0x00000053u, /* scb[1].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED10   = 0x00000054u, /* scb[1].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_SCB_I2C_SCL2      = 0x00000055u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX2           = 0x00000056u, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX2           = 0x00000057u, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD20  = 0x00000058u, /* scb[2].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP20    = 0x00000059u, /* scb[2].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED20   = 0x0000005Au, /* scb[2].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_SCB_I2C_SCL3      = 0x0000005Bu, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX3           = 0x0000005Cu, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX3           = 0x0000005Du, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD30  = 0x0000005Eu, /* scb[3].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP30    = 0x0000005Fu, /* scb[3].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED30   = 0x00000060u, /* scb[3].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_SCB_I2C_SCL4      = 0x00000061u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX4           = 0x00000062u, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX4           = 0x00000063u, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD40  = 0x00000064u, /* scb[4].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP40    = 0x00000065u, /* scb[4].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED40   = 0x00000066u, /* scb[4].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_SCB_I2C_SCL5      = 0x00000067u, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX5           = 0x00000068u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX5           = 0x00000069u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD50  = 0x0000006Au, /* scb[5].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP50    = 0x0000006Bu, /* scb[5].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED50   = 0x0000006Cu, /* scb[5].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_SCB_I2C_SCL6      = 0x0000006Du, /* scb[6].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX6           = 0x0000006Eu, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX6           = 0x0000006Fu, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD60  = 0x00000070u, /* scb[6].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP60    = 0x00000071u, /* scb[6].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED60   = 0x00000072u, /* scb[6].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_CTI_TR_OUT0       = 0x00000073u, /* debug600.cti_tr_out[0] */
    TRIG_IN_MUX_0_CTI_TR_OUT1       = 0x00000074u, /* debug600.cti_tr_out[1] */
    TRIG_IN_MUX_0_CANFD_TT_TR_OUT0  = 0x00000075u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_0_CANFD_TT_TR_OUT1  = 0x00000076u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_0_CAN_DBG0          = 0x00000077u, /* canfd[0].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_0_CAN_DBG1          = 0x00000078u, /* canfd[0].tr_dbg_dma_req[1] */
    TRIG_IN_MUX_0_CAN_FIFO0_CH0     = 0x00000079u, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_MUX_0_CAN_FIFO0_CH1     = 0x0000007Au, /* canfd[0].tr_fifo0[1] */
    TRIG_IN_MUX_0_CAN_FIFO1_CH0     = 0x0000007Bu, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_MUX_0_CAN_FIFO1_CH1     = 0x0000007Cu, /* canfd[0].tr_fifo1[1] */
    TRIG_IN_MUX_0_LPCOMP_DSI_COMP0  = 0x0000007Du, /* lpcomp.dsi_comp0 */
    TRIG_IN_MUX_0_LPCOMP_DSI_COMP1  = 0x0000007Eu, /* lpcomp.dsi_comp1 */
    TRIG_IN_MUX_0_CPUSS_TR_FAULT0   = 0x0000007Fu, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_0_TRNG_BITSTREAM    = 0x00000080u, /* cryptolite.tr_trng_bitstream */
    TRIG_IN_MUX_0_PPCA_DMAREQ0      = 0x00000081u, /* ppca.dmareq_ppss[0] */
    TRIG_IN_MUX_0_PPCA_DMAREQ1      = 0x00000082u, /* ppca.dmareq_ppss[1] */
    TRIG_IN_MUX_0_PPCA_DMAREQ2      = 0x00000083u, /* ppca.dmareq_ppss[2] */
    TRIG_IN_MUX_0_PPCA_DMAREQ3      = 0x00000084u, /* ppca.dmareq_ppss[3] */
    TRIG_IN_MUX_0_PPCA_TR136        = 0x00000085u, /* ppca.tr_ppssout[136] */
    TRIG_IN_MUX_0_PPCA_TR137        = 0x00000086u, /* ppca.tr_ppssout[137] */
    TRIG_IN_MUX_0_PPCA_TR138        = 0x00000087u, /* ppca.tr_ppssout[138] */
    TRIG_IN_MUX_0_PPCA_TR139        = 0x00000088u, /* ppca.tr_ppssout[139] */
    TRIG_IN_MUX_0_PPCA_TR140        = 0x00000089u, /* ppca.tr_ppssout[140] */
    TRIG_IN_MUX_0_PPCA_TR141        = 0x0000008Au, /* ppca.tr_ppssout[141] */
    TRIG_IN_MUX_0_PPCA_TR142        = 0x0000008Bu, /* ppca.tr_ppssout[142] */
    TRIG_IN_MUX_0_PPCA_TR143        = 0x0000008Cu, /* ppca.tr_ppssout[143] */
    TRIG_IN_MUX_0_PPCA_TR144        = 0x0000008Du, /* ppca.tr_ppssout[144] */
    TRIG_IN_MUX_0_PPCA_TR145        = 0x0000008Eu, /* ppca.tr_ppssout[145] */
    TRIG_IN_MUX_0_PPCA_TR146        = 0x0000008Fu, /* ppca.tr_ppssout[146] */
    TRIG_IN_MUX_0_PPCA_TR147        = 0x00000090u, /* ppca.tr_ppssout[147] */
    TRIG_IN_MUX_0_PPCA_TR148        = 0x00000091u, /* ppca.tr_ppssout[148] */
    TRIG_IN_MUX_0_PPCA_TR149        = 0x00000092u, /* ppca.tr_ppssout[149] */
    TRIG_IN_MUX_0_PPCA_TR150        = 0x00000093u, /* ppca.tr_ppssout[150] */
    TRIG_IN_MUX_0_PPCA_TR151        = 0x00000094u, /* ppca.tr_ppssout[151] */
    TRIG_IN_MUX_0_PPCA_TR152        = 0x00000095u, /* ppca.tr_ppssout[152] */
    TRIG_IN_MUX_0_PPCA_TR153        = 0x00000096u, /* ppca.tr_ppssout[153] */
    TRIG_IN_MUX_0_PPCA_TR154        = 0x00000097u, /* ppca.tr_ppssout[154] */
    TRIG_IN_MUX_0_PPCA_TR155        = 0x00000098u, /* ppca.tr_ppssout[155] */
    TRIG_IN_MUX_0_PPCA_TR156        = 0x00000099u, /* ppca.tr_ppssout[156] */
    TRIG_IN_MUX_0_PPCA_TR157        = 0x0000009Au, /* ppca.tr_ppssout[157] */
    TRIG_IN_MUX_0_PPCA_TR158        = 0x0000009Bu, /* ppca.tr_ppssout[158] */
    TRIG_IN_MUX_0_PPCA_TR159        = 0x0000009Cu, /* ppca.tr_ppssout[159] */
    TRIG_IN_MUX_0_PPCA_TR160        = 0x0000009Du, /* ppca.tr_ppssout[160] */
    TRIG_IN_MUX_0_PPCA_TR161        = 0x0000009Eu, /* ppca.tr_ppssout[161] */
    TRIG_IN_MUX_0_PPCA_TR162        = 0x0000009Fu, /* ppca.tr_ppssout[162] */
    TRIG_IN_MUX_0_PPCA_TR163        = 0x000000A0u, /* ppca.tr_ppssout[163] */
    TRIG_IN_MUX_0_PPCA_TR164        = 0x000000A1u, /* ppca.tr_ppssout[164] */
    TRIG_IN_MUX_0_PPCA_TR165        = 0x000000A2u, /* ppca.tr_ppssout[165] */
    TRIG_IN_MUX_0_PPCA_TR166        = 0x000000A3u, /* ppca.tr_ppssout[166] */
    TRIG_IN_MUX_0_PPCA_TR167        = 0x000000A4u, /* ppca.tr_ppssout[167] */
    TRIG_IN_MUX_0_PPCA_TR168        = 0x000000A5u, /* ppca.tr_ppssout[168] */
    TRIG_IN_MUX_0_PPCA_TR169        = 0x000000A6u, /* ppca.tr_ppssout[169] */
    TRIG_IN_MUX_0_PPCA_TR170        = 0x000000A7u, /* ppca.tr_ppssout[170] */
    TRIG_IN_MUX_0_PPCA_TR171        = 0x000000A8u, /* ppca.tr_ppssout[171] */
    TRIG_IN_MUX_0_PPCA_TR172        = 0x000000A9u, /* ppca.tr_ppssout[172] */
    TRIG_IN_MUX_0_PPCA_TR173        = 0x000000AAu, /* ppca.tr_ppssout[173] */
    TRIG_IN_MUX_0_PPCA_TR174        = 0x000000ABu, /* ppca.tr_ppssout[174] */
    TRIG_IN_MUX_0_PPCA_TR175        = 0x000000ACu, /* ppca.tr_ppssout[175] */
    TRIG_IN_MUX_0_PPCA_TR176        = 0x000000ADu, /* ppca.tr_ppssout[176] */
    TRIG_IN_MUX_0_PPCA_TR177        = 0x000000AEu, /* ppca.tr_ppssout[177] */
    TRIG_IN_MUX_0_PPCA_TR178        = 0x000000AFu, /* ppca.tr_ppssout[178] */
    TRIG_IN_MUX_0_PPCA_TR179        = 0x000000B0u, /* ppca.tr_ppssout[179] */
    TRIG_IN_MUX_0_PPCA_TR180        = 0x000000B1u, /* ppca.tr_ppssout[180] */
    TRIG_IN_MUX_0_PPCA_TR181        = 0x000000B2u, /* ppca.tr_ppssout[181] */
    TRIG_IN_MUX_0_PPCA_TR182        = 0x000000B3u, /* ppca.tr_ppssout[182] */
    TRIG_IN_MUX_0_PPCA_TR183        = 0x000000B4u, /* ppca.tr_ppssout[183] */
    TRIG_IN_MUX_0_PPCA_TR184        = 0x000000B5u, /* ppca.tr_ppssout[184] */
    TRIG_IN_MUX_0_PPCA_TR185        = 0x000000B6u, /* ppca.tr_ppssout[185] */
    TRIG_IN_MUX_0_PPCA_TR186        = 0x000000B7u, /* ppca.tr_ppssout[186] */
    TRIG_IN_MUX_0_PPCA_TR193        = 0x000000B8u, /* ppca.tr_ppssout[193] */
    TRIG_IN_MUX_0_PPCA_TR194        = 0x000000B9u, /* ppca.tr_ppssout[194] */
    TRIG_IN_MUX_0_PPCA_TR195        = 0x000000BAu, /* ppca.tr_ppssout[195] */
    TRIG_IN_MUX_0_PPCA_TR196        = 0x000000BBu, /* ppca.tr_ppssout[196] */
    TRIG_IN_MUX_0_PPCA_TR197        = 0x000000BCu, /* ppca.tr_ppssout[197] */
    TRIG_IN_MUX_0_PPCA_TR198        = 0x000000BDu, /* ppca.tr_ppssout[198] */
    TRIG_IN_MUX_0_PPCA_TR199        = 0x000000BEu, /* ppca.tr_ppssout[199] */
    TRIG_IN_MUX_0_PPCA_TR200        = 0x000000BFu, /* ppca.tr_ppssout[200] */
    TRIG_IN_MUX_0_PPCA_TR202        = 0x000000C0u, /* ppca.tr_ppssout[202] */
    TRIG_IN_MUX_0_PPCA_TR203        = 0x000000C1u, /* ppca.tr_ppssout[203] */
    TRIG_IN_MUX_0_PPCA_TR204        = 0x000000C2u, /* ppca.tr_ppssout[204] */
    TRIG_IN_MUX_0_PPCA_TR205        = 0x000000C3u, /* ppca.tr_ppssout[205] */
    TRIG_IN_MUX_0_PPCA_TR206        = 0x000000C4u, /* ppca.tr_ppssout[206] */
    TRIG_IN_MUX_0_PPCA_TR207        = 0x000000C5u, /* ppca.tr_ppssout[207] */
    TRIG_IN_MUX_0_PPCA_TR208        = 0x000000C6u, /* ppca.tr_ppssout[208] */
    TRIG_IN_MUX_0_PPCA_TR209        = 0x000000C7u, /* ppca.tr_ppssout[209] */
    TRIG_IN_MUX_0_PPCA_TR210        = 0x000000C8u, /* ppca.tr_ppssout[210] */
    TRIG_IN_MUX_0_PPCA_TR211        = 0x000000C9u /* ppca.tr_ppssout[211] */
} en_trig_input_pdma0_tr_t;

/* Trigger Input Group 1 - HSIOM0 trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_1_PDMA0_TR_OUT0     = 0x00000101u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT1     = 0x00000102u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT2     = 0x00000103u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT3     = 0x00000104u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT4     = 0x00000105u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT5     = 0x00000106u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT6     = 0x00000107u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT7     = 0x00000108u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT8     = 0x00000109u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT9     = 0x0000010Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT10    = 0x0000010Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT11    = 0x0000010Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT12    = 0x0000010Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT13    = 0x0000010Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT14    = 0x0000010Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_1_PDMA0_TR_OUT15    = 0x00000110u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_0 = 0x00000111u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_1 = 0x00000112u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_256 = 0x00000113u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_257 = 0x00000114u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT1_0 = 0x00000115u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT1_1 = 0x00000116u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT1_256 = 0x00000117u, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT1_257 = 0x00000118u, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_LINE_0 = 0x00000119u, /* tcpwm[0].tr_line[0] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_LINE_1 = 0x0000011Au, /* tcpwm[0].tr_line[1] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_LINE_COMPL_0 = 0x0000011Bu, /* tcpwm[0].tr_line_compl[0] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_LINE_COMPL_1 = 0x0000011Cu, /* tcpwm[0].tr_line_compl[1] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_LINE_256 = 0x0000011Du, /* tcpwm[0].tr_line[256] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_LINE_257 = 0x0000011Eu, /* tcpwm[0].tr_line[257] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_LINE_COMPL_256 = 0x0000011Fu, /* tcpwm[0].tr_line_compl[256] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_LINE_COMPL_257 = 0x00000120u, /* tcpwm[0].tr_line_compl[257] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT0     = 0x00000121u, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT1     = 0x00000122u, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT2     = 0x00000123u, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT3     = 0x00000124u, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT4     = 0x00000125u, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT5     = 0x00000126u, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT6     = 0x00000127u, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT7     = 0x00000128u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT8     = 0x00000129u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT9     = 0x0000012Au, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT10    = 0x0000012Bu, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT11    = 0x0000012Cu, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT12    = 0x0000012Du, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT13    = 0x0000012Eu, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT14    = 0x0000012Fu, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT15    = 0x00000130u, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT16    = 0x00000131u, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT17    = 0x00000132u, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT18    = 0x00000133u, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT19    = 0x00000134u, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT20    = 0x00000135u, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT21    = 0x00000136u, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT22    = 0x00000137u, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT23    = 0x00000138u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT24    = 0x00000139u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT25    = 0x0000013Au, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT26    = 0x0000013Bu, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT27    = 0x0000013Cu, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT28    = 0x0000013Du, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT29    = 0x0000013Eu, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT30    = 0x0000013Fu, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT31    = 0x00000140u, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT32    = 0x00000141u, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT33    = 0x00000142u, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT34    = 0x00000143u, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT35    = 0x00000144u, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT36    = 0x00000145u, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT37    = 0x00000146u, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT38    = 0x00000147u, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT39    = 0x00000148u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT40    = 0x00000149u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT41    = 0x0000014Au, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT42    = 0x0000014Bu, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT43    = 0x0000014Cu, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT44    = 0x0000014Du, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT45    = 0x0000014Eu, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT46    = 0x0000014Fu, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT47    = 0x00000150u, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT48    = 0x00000151u, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT49    = 0x00000152u, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT50    = 0x00000153u, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT51    = 0x00000154u, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT52    = 0x00000155u, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT53    = 0x00000156u, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT54    = 0x00000157u, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT55    = 0x00000158u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT56    = 0x00000159u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT57    = 0x0000015Au, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT58    = 0x0000015Bu, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT59    = 0x0000015Cu, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_1_SCB_I2C_SCL0      = 0x0000015Du, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX0           = 0x0000015Eu, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX0           = 0x0000015Fu, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD00  = 0x00000160u, /* scb[0].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP00    = 0x00000161u, /* scb[0].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED00   = 0x00000162u, /* scb[0].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_SCB_I2C_SCL1      = 0x00000163u, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX1           = 0x00000164u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX1           = 0x00000165u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD10  = 0x00000166u, /* scb[1].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP10    = 0x00000167u, /* scb[1].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED10   = 0x00000168u, /* scb[1].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_SCB_I2C_SCL2      = 0x00000169u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX2           = 0x0000016Au, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX2           = 0x0000016Bu, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD20  = 0x0000016Cu, /* scb[2].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP20    = 0x0000016Du, /* scb[2].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED20   = 0x0000016Eu, /* scb[2].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_SCB_I2C_SCL3      = 0x0000016Fu, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX3           = 0x00000170u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX3           = 0x00000171u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD30  = 0x00000172u, /* scb[3].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP30    = 0x00000173u, /* scb[3].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED30   = 0x00000174u, /* scb[3].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_SCB_I2C_SCL4      = 0x00000175u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX4           = 0x00000176u, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX4           = 0x00000177u, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD40  = 0x00000178u, /* scb[4].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP40    = 0x00000179u, /* scb[4].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED40   = 0x0000017Au, /* scb[4].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_SCB_I2C_SCL5      = 0x0000017Bu, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX5           = 0x0000017Cu, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX5           = 0x0000017Du, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD50  = 0x0000017Eu, /* scb[5].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP50    = 0x0000017Fu, /* scb[5].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED50   = 0x00000180u, /* scb[5].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_SCB_I2C_SCL6      = 0x00000181u, /* scb[6].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX6           = 0x00000182u, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX6           = 0x00000183u, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD60  = 0x00000184u, /* scb[6].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP60    = 0x00000185u, /* scb[6].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED60   = 0x00000186u, /* scb[6].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_CTI_TR_OUT0       = 0x00000187u, /* debug600.cti_tr_out[0] */
    TRIG_IN_MUX_1_CTI_TR_OUT1       = 0x00000188u, /* debug600.cti_tr_out[1] */
    TRIG_IN_MUX_1_CANFD_TT_TR_OUT0  = 0x00000189u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_1_CANFD_TT_TR_OUT1  = 0x0000018Au, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_1_LPCOMP_DSI_COMP0  = 0x0000018Bu, /* lpcomp.dsi_comp0 */
    TRIG_IN_MUX_1_LPCOMP_DSI_COMP1  = 0x0000018Cu, /* lpcomp.dsi_comp1 */
    TRIG_IN_MUX_1_CPUSS_TR_FAULT0   = 0x0000018Du, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_1_TRNG_BITSTREAM    = 0x0000018Eu /* cryptolite.tr_trng_bitstream */
} en_trig_input_hsiom0_t;

/* Trigger Input Group 2 - HSIOM1 trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_2_PPCA_TR0          = 0x00000201u, /* ppca.tr_ppssout[0] */
    TRIG_IN_MUX_2_PPCA_TR1          = 0x00000202u, /* ppca.tr_ppssout[1] */
    TRIG_IN_MUX_2_PPCA_TR2          = 0x00000203u, /* ppca.tr_ppssout[2] */
    TRIG_IN_MUX_2_PPCA_TR3          = 0x00000204u, /* ppca.tr_ppssout[3] */
    TRIG_IN_MUX_2_PPCA_TR4          = 0x00000205u, /* ppca.tr_ppssout[4] */
    TRIG_IN_MUX_2_PPCA_TR5          = 0x00000206u, /* ppca.tr_ppssout[5] */
    TRIG_IN_MUX_2_PPCA_TR6          = 0x00000207u, /* ppca.tr_ppssout[6] */
    TRIG_IN_MUX_2_PPCA_TR7          = 0x00000208u, /* ppca.tr_ppssout[7] */
    TRIG_IN_MUX_2_PPCA_TR8          = 0x00000209u, /* ppca.tr_ppssout[8] */
    TRIG_IN_MUX_2_PPCA_TR9          = 0x0000020Au, /* ppca.tr_ppssout[9] */
    TRIG_IN_MUX_2_PPCA_TR10         = 0x0000020Bu, /* ppca.tr_ppssout[10] */
    TRIG_IN_MUX_2_PPCA_TR11         = 0x0000020Cu, /* ppca.tr_ppssout[11] */
    TRIG_IN_MUX_2_PPCA_TR12         = 0x0000020Du, /* ppca.tr_ppssout[12] */
    TRIG_IN_MUX_2_PPCA_TR13         = 0x0000020Eu, /* ppca.tr_ppssout[13] */
    TRIG_IN_MUX_2_PPCA_TR14         = 0x0000020Fu, /* ppca.tr_ppssout[14] */
    TRIG_IN_MUX_2_PPCA_TR15         = 0x00000210u, /* ppca.tr_ppssout[15] */
    TRIG_IN_MUX_2_PPCA_TR16         = 0x00000211u, /* ppca.tr_ppssout[16] */
    TRIG_IN_MUX_2_PPCA_TR17         = 0x00000212u, /* ppca.tr_ppssout[17] */
    TRIG_IN_MUX_2_PPCA_TR18         = 0x00000213u, /* ppca.tr_ppssout[18] */
    TRIG_IN_MUX_2_PPCA_TR19         = 0x00000214u, /* ppca.tr_ppssout[19] */
    TRIG_IN_MUX_2_PPCA_TR20         = 0x00000215u, /* ppca.tr_ppssout[20] */
    TRIG_IN_MUX_2_PPCA_TR21         = 0x00000216u, /* ppca.tr_ppssout[21] */
    TRIG_IN_MUX_2_PPCA_TR22         = 0x00000217u, /* ppca.tr_ppssout[22] */
    TRIG_IN_MUX_2_PPCA_TR23         = 0x00000218u, /* ppca.tr_ppssout[23] */
    TRIG_IN_MUX_2_PPCA_TR24         = 0x00000219u, /* ppca.tr_ppssout[24] */
    TRIG_IN_MUX_2_PPCA_TR25         = 0x0000021Au, /* ppca.tr_ppssout[25] */
    TRIG_IN_MUX_2_PPCA_TR26         = 0x0000021Bu, /* ppca.tr_ppssout[26] */
    TRIG_IN_MUX_2_PPCA_TR27         = 0x0000021Cu, /* ppca.tr_ppssout[27] */
    TRIG_IN_MUX_2_PPCA_TR28         = 0x0000021Du, /* ppca.tr_ppssout[28] */
    TRIG_IN_MUX_2_PPCA_TR29         = 0x0000021Eu, /* ppca.tr_ppssout[29] */
    TRIG_IN_MUX_2_PPCA_TR30         = 0x0000021Fu, /* ppca.tr_ppssout[30] */
    TRIG_IN_MUX_2_PPCA_TR31         = 0x00000220u, /* ppca.tr_ppssout[31] */
    TRIG_IN_MUX_2_PPCA_TR32         = 0x00000221u, /* ppca.tr_ppssout[32] */
    TRIG_IN_MUX_2_PPCA_TR33         = 0x00000222u, /* ppca.tr_ppssout[33] */
    TRIG_IN_MUX_2_PPCA_TR34         = 0x00000223u, /* ppca.tr_ppssout[34] */
    TRIG_IN_MUX_2_PPCA_TR35         = 0x00000224u, /* ppca.tr_ppssout[35] */
    TRIG_IN_MUX_2_PPCA_TR36         = 0x00000225u, /* ppca.tr_ppssout[36] */
    TRIG_IN_MUX_2_PPCA_TR37         = 0x00000226u, /* ppca.tr_ppssout[37] */
    TRIG_IN_MUX_2_PPCA_TR38         = 0x00000227u, /* ppca.tr_ppssout[38] */
    TRIG_IN_MUX_2_PPCA_TR39         = 0x00000228u, /* ppca.tr_ppssout[39] */
    TRIG_IN_MUX_2_PPCA_TR40         = 0x00000229u, /* ppca.tr_ppssout[40] */
    TRIG_IN_MUX_2_PPCA_TR41         = 0x0000022Au, /* ppca.tr_ppssout[41] */
    TRIG_IN_MUX_2_PPCA_TR42         = 0x0000022Bu, /* ppca.tr_ppssout[42] */
    TRIG_IN_MUX_2_PPCA_TR43         = 0x0000022Cu, /* ppca.tr_ppssout[43] */
    TRIG_IN_MUX_2_PPCA_TR44         = 0x0000022Du, /* ppca.tr_ppssout[44] */
    TRIG_IN_MUX_2_PPCA_TR45         = 0x0000022Eu, /* ppca.tr_ppssout[45] */
    TRIG_IN_MUX_2_PPCA_TR46         = 0x0000022Fu, /* ppca.tr_ppssout[46] */
    TRIG_IN_MUX_2_PPCA_TR47         = 0x00000230u, /* ppca.tr_ppssout[47] */
    TRIG_IN_MUX_2_PPCA_TR48         = 0x00000231u, /* ppca.tr_ppssout[48] */
    TRIG_IN_MUX_2_PPCA_TR49         = 0x00000232u, /* ppca.tr_ppssout[49] */
    TRIG_IN_MUX_2_PPCA_TR50         = 0x00000233u, /* ppca.tr_ppssout[50] */
    TRIG_IN_MUX_2_PPCA_TR51         = 0x00000234u, /* ppca.tr_ppssout[51] */
    TRIG_IN_MUX_2_PPCA_TR52         = 0x00000235u, /* ppca.tr_ppssout[52] */
    TRIG_IN_MUX_2_PPCA_TR53         = 0x00000236u, /* ppca.tr_ppssout[53] */
    TRIG_IN_MUX_2_PPCA_TR54         = 0x00000237u, /* ppca.tr_ppssout[54] */
    TRIG_IN_MUX_2_PPCA_TR55         = 0x00000238u, /* ppca.tr_ppssout[55] */
    TRIG_IN_MUX_2_PPCA_TR56         = 0x00000239u, /* ppca.tr_ppssout[56] */
    TRIG_IN_MUX_2_PPCA_TR57         = 0x0000023Au, /* ppca.tr_ppssout[57] */
    TRIG_IN_MUX_2_PPCA_TR58         = 0x0000023Bu, /* ppca.tr_ppssout[58] */
    TRIG_IN_MUX_2_PPCA_TR59         = 0x0000023Cu, /* ppca.tr_ppssout[59] */
    TRIG_IN_MUX_2_PPCA_TR60         = 0x0000023Du, /* ppca.tr_ppssout[60] */
    TRIG_IN_MUX_2_PPCA_TR61         = 0x0000023Eu, /* ppca.tr_ppssout[61] */
    TRIG_IN_MUX_2_PPCA_TR62         = 0x0000023Fu, /* ppca.tr_ppssout[62] */
    TRIG_IN_MUX_2_PPCA_TR63         = 0x00000240u, /* ppca.tr_ppssout[63] */
    TRIG_IN_MUX_2_PPCA_TR64         = 0x00000241u, /* ppca.tr_ppssout[64] */
    TRIG_IN_MUX_2_PPCA_TR65         = 0x00000242u, /* ppca.tr_ppssout[65] */
    TRIG_IN_MUX_2_PPCA_TR66         = 0x00000243u, /* ppca.tr_ppssout[66] */
    TRIG_IN_MUX_2_PPCA_TR67         = 0x00000244u, /* ppca.tr_ppssout[67] */
    TRIG_IN_MUX_2_PPCA_TR68         = 0x00000245u, /* ppca.tr_ppssout[68] */
    TRIG_IN_MUX_2_PPCA_TR69         = 0x00000246u, /* ppca.tr_ppssout[69] */
    TRIG_IN_MUX_2_PPCA_TR70         = 0x00000247u, /* ppca.tr_ppssout[70] */
    TRIG_IN_MUX_2_PPCA_TR71         = 0x00000248u, /* ppca.tr_ppssout[71] */
    TRIG_IN_MUX_2_PPCA_TR72         = 0x00000249u, /* ppca.tr_ppssout[72] */
    TRIG_IN_MUX_2_PPCA_TR73         = 0x0000024Au, /* ppca.tr_ppssout[73] */
    TRIG_IN_MUX_2_PPCA_TR74         = 0x0000024Bu, /* ppca.tr_ppssout[74] */
    TRIG_IN_MUX_2_PPCA_TR75         = 0x0000024Cu, /* ppca.tr_ppssout[75] */
    TRIG_IN_MUX_2_PPCA_TR76         = 0x0000024Du, /* ppca.tr_ppssout[76] */
    TRIG_IN_MUX_2_PPCA_TR77         = 0x0000024Eu, /* ppca.tr_ppssout[77] */
    TRIG_IN_MUX_2_PPCA_TR78         = 0x0000024Fu, /* ppca.tr_ppssout[78] */
    TRIG_IN_MUX_2_PPCA_TR79         = 0x00000250u, /* ppca.tr_ppssout[79] */
    TRIG_IN_MUX_2_PPCA_TR80         = 0x00000251u, /* ppca.tr_ppssout[80] */
    TRIG_IN_MUX_2_PPCA_TR81         = 0x00000252u, /* ppca.tr_ppssout[81] */
    TRIG_IN_MUX_2_PPCA_TR82         = 0x00000253u, /* ppca.tr_ppssout[82] */
    TRIG_IN_MUX_2_PPCA_TR83         = 0x00000254u, /* ppca.tr_ppssout[83] */
    TRIG_IN_MUX_2_PPCA_TR84         = 0x00000255u, /* ppca.tr_ppssout[84] */
    TRIG_IN_MUX_2_PPCA_TR85         = 0x00000256u, /* ppca.tr_ppssout[85] */
    TRIG_IN_MUX_2_PPCA_TR86         = 0x00000257u, /* ppca.tr_ppssout[86] */
    TRIG_IN_MUX_2_PPCA_TR87         = 0x00000258u, /* ppca.tr_ppssout[87] */
    TRIG_IN_MUX_2_PPCA_TR88         = 0x00000259u, /* ppca.tr_ppssout[88] */
    TRIG_IN_MUX_2_PPCA_TR89         = 0x0000025Au, /* ppca.tr_ppssout[89] */
    TRIG_IN_MUX_2_PPCA_TR90         = 0x0000025Bu, /* ppca.tr_ppssout[90] */
    TRIG_IN_MUX_2_PPCA_TR91         = 0x0000025Cu, /* ppca.tr_ppssout[91] */
    TRIG_IN_MUX_2_PPCA_TR92         = 0x0000025Du, /* ppca.tr_ppssout[92] */
    TRIG_IN_MUX_2_PPCA_TR93         = 0x0000025Eu, /* ppca.tr_ppssout[93] */
    TRIG_IN_MUX_2_PPCA_TR94         = 0x0000025Fu, /* ppca.tr_ppssout[94] */
    TRIG_IN_MUX_2_PPCA_TR95         = 0x00000260u, /* ppca.tr_ppssout[95] */
    TRIG_IN_MUX_2_PPCA_TR96         = 0x00000261u, /* ppca.tr_ppssout[96] */
    TRIG_IN_MUX_2_PPCA_TR97         = 0x00000262u, /* ppca.tr_ppssout[97] */
    TRIG_IN_MUX_2_PPCA_TR98         = 0x00000263u, /* ppca.tr_ppssout[98] */
    TRIG_IN_MUX_2_PPCA_TR99         = 0x00000264u, /* ppca.tr_ppssout[99] */
    TRIG_IN_MUX_2_PPCA_TR100        = 0x00000265u, /* ppca.tr_ppssout[100] */
    TRIG_IN_MUX_2_PPCA_TR101        = 0x00000266u, /* ppca.tr_ppssout[101] */
    TRIG_IN_MUX_2_PPCA_TR102        = 0x00000267u, /* ppca.tr_ppssout[102] */
    TRIG_IN_MUX_2_PPCA_TR103        = 0x00000268u, /* ppca.tr_ppssout[103] */
    TRIG_IN_MUX_2_PPCA_TR104        = 0x00000269u, /* ppca.tr_ppssout[104] */
    TRIG_IN_MUX_2_PPCA_TR105        = 0x0000026Au, /* ppca.tr_ppssout[105] */
    TRIG_IN_MUX_2_PPCA_TR106        = 0x0000026Bu, /* ppca.tr_ppssout[106] */
    TRIG_IN_MUX_2_PPCA_TR107        = 0x0000026Cu, /* ppca.tr_ppssout[107] */
    TRIG_IN_MUX_2_PPCA_TR108        = 0x0000026Du, /* ppca.tr_ppssout[108] */
    TRIG_IN_MUX_2_PPCA_TR109        = 0x0000026Eu, /* ppca.tr_ppssout[109] */
    TRIG_IN_MUX_2_PPCA_TR110        = 0x0000026Fu, /* ppca.tr_ppssout[110] */
    TRIG_IN_MUX_2_PPCA_TR111        = 0x00000270u, /* ppca.tr_ppssout[111] */
    TRIG_IN_MUX_2_PPCA_TR112        = 0x00000271u, /* ppca.tr_ppssout[112] */
    TRIG_IN_MUX_2_PPCA_TR113        = 0x00000272u, /* ppca.tr_ppssout[113] */
    TRIG_IN_MUX_2_PPCA_TR114        = 0x00000273u, /* ppca.tr_ppssout[114] */
    TRIG_IN_MUX_2_PPCA_TR115        = 0x00000274u, /* ppca.tr_ppssout[115] */
    TRIG_IN_MUX_2_PPCA_TR116        = 0x00000275u, /* ppca.tr_ppssout[116] */
    TRIG_IN_MUX_2_PPCA_TR117        = 0x00000276u, /* ppca.tr_ppssout[117] */
    TRIG_IN_MUX_2_PPCA_TR118        = 0x00000277u, /* ppca.tr_ppssout[118] */
    TRIG_IN_MUX_2_PPCA_TR119        = 0x00000278u, /* ppca.tr_ppssout[119] */
    TRIG_IN_MUX_2_PPCA_TR120        = 0x00000279u, /* ppca.tr_ppssout[120] */
    TRIG_IN_MUX_2_PPCA_TR121        = 0x0000027Au, /* ppca.tr_ppssout[121] */
    TRIG_IN_MUX_2_PPCA_TR122        = 0x0000027Bu, /* ppca.tr_ppssout[122] */
    TRIG_IN_MUX_2_PPCA_TR123        = 0x0000027Cu, /* ppca.tr_ppssout[123] */
    TRIG_IN_MUX_2_PPCA_TR124        = 0x0000027Du, /* ppca.tr_ppssout[124] */
    TRIG_IN_MUX_2_PPCA_TR125        = 0x0000027Eu, /* ppca.tr_ppssout[125] */
    TRIG_IN_MUX_2_PPCA_TR126        = 0x0000027Fu, /* ppca.tr_ppssout[126] */
    TRIG_IN_MUX_2_PPCA_TR127        = 0x00000280u, /* ppca.tr_ppssout[127] */
    TRIG_IN_MUX_2_PPCA_TR128        = 0x00000281u, /* ppca.tr_ppssout[128] */
    TRIG_IN_MUX_2_PPCA_TR129        = 0x00000282u, /* ppca.tr_ppssout[129] */
    TRIG_IN_MUX_2_PPCA_TR130        = 0x00000283u, /* ppca.tr_ppssout[130] */
    TRIG_IN_MUX_2_PPCA_TR131        = 0x00000284u, /* ppca.tr_ppssout[131] */
    TRIG_IN_MUX_2_PPCA_TR132        = 0x00000285u, /* ppca.tr_ppssout[132] */
    TRIG_IN_MUX_2_PPCA_TR133        = 0x00000286u, /* ppca.tr_ppssout[133] */
    TRIG_IN_MUX_2_PPCA_TR134        = 0x00000287u, /* ppca.tr_ppssout[134] */
    TRIG_IN_MUX_2_PPCA_TR135        = 0x00000288u, /* ppca.tr_ppssout[135] */
    TRIG_IN_MUX_2_PPCA_TR136        = 0x00000289u, /* ppca.tr_ppssout[136] */
    TRIG_IN_MUX_2_PPCA_TR137        = 0x0000028Au, /* ppca.tr_ppssout[137] */
    TRIG_IN_MUX_2_PPCA_TR138        = 0x0000028Bu, /* ppca.tr_ppssout[138] */
    TRIG_IN_MUX_2_PPCA_TR139        = 0x0000028Cu, /* ppca.tr_ppssout[139] */
    TRIG_IN_MUX_2_PPCA_TR140        = 0x0000028Du, /* ppca.tr_ppssout[140] */
    TRIG_IN_MUX_2_PPCA_TR141        = 0x0000028Eu, /* ppca.tr_ppssout[141] */
    TRIG_IN_MUX_2_PPCA_TR142        = 0x0000028Fu, /* ppca.tr_ppssout[142] */
    TRIG_IN_MUX_2_PPCA_TR143        = 0x00000290u, /* ppca.tr_ppssout[143] */
    TRIG_IN_MUX_2_PPCA_TR144        = 0x00000291u, /* ppca.tr_ppssout[144] */
    TRIG_IN_MUX_2_PPCA_TR145        = 0x00000292u, /* ppca.tr_ppssout[145] */
    TRIG_IN_MUX_2_PPCA_TR146        = 0x00000293u, /* ppca.tr_ppssout[146] */
    TRIG_IN_MUX_2_PPCA_TR147        = 0x00000294u, /* ppca.tr_ppssout[147] */
    TRIG_IN_MUX_2_PPCA_TR148        = 0x00000295u, /* ppca.tr_ppssout[148] */
    TRIG_IN_MUX_2_PPCA_TR149        = 0x00000296u, /* ppca.tr_ppssout[149] */
    TRIG_IN_MUX_2_PPCA_TR150        = 0x00000297u, /* ppca.tr_ppssout[150] */
    TRIG_IN_MUX_2_PPCA_TR151        = 0x00000298u, /* ppca.tr_ppssout[151] */
    TRIG_IN_MUX_2_PPCA_TR152        = 0x00000299u, /* ppca.tr_ppssout[152] */
    TRIG_IN_MUX_2_PPCA_TR153        = 0x0000029Au, /* ppca.tr_ppssout[153] */
    TRIG_IN_MUX_2_PPCA_TR154        = 0x0000029Bu, /* ppca.tr_ppssout[154] */
    TRIG_IN_MUX_2_PPCA_TR155        = 0x0000029Cu, /* ppca.tr_ppssout[155] */
    TRIG_IN_MUX_2_PPCA_TR156        = 0x0000029Du, /* ppca.tr_ppssout[156] */
    TRIG_IN_MUX_2_PPCA_TR157        = 0x0000029Eu, /* ppca.tr_ppssout[157] */
    TRIG_IN_MUX_2_PPCA_TR158        = 0x0000029Fu, /* ppca.tr_ppssout[158] */
    TRIG_IN_MUX_2_PPCA_TR159        = 0x000002A0u, /* ppca.tr_ppssout[159] */
    TRIG_IN_MUX_2_PPCA_TR160        = 0x000002A1u, /* ppca.tr_ppssout[160] */
    TRIG_IN_MUX_2_PPCA_TR161        = 0x000002A2u, /* ppca.tr_ppssout[161] */
    TRIG_IN_MUX_2_PPCA_TR162        = 0x000002A3u, /* ppca.tr_ppssout[162] */
    TRIG_IN_MUX_2_PPCA_TR163        = 0x000002A4u, /* ppca.tr_ppssout[163] */
    TRIG_IN_MUX_2_PPCA_TR164        = 0x000002A5u, /* ppca.tr_ppssout[164] */
    TRIG_IN_MUX_2_PPCA_TR165        = 0x000002A6u, /* ppca.tr_ppssout[165] */
    TRIG_IN_MUX_2_PPCA_TR166        = 0x000002A7u, /* ppca.tr_ppssout[166] */
    TRIG_IN_MUX_2_PPCA_TR167        = 0x000002A8u, /* ppca.tr_ppssout[167] */
    TRIG_IN_MUX_2_PPCA_TR168        = 0x000002A9u, /* ppca.tr_ppssout[168] */
    TRIG_IN_MUX_2_PPCA_TR169        = 0x000002AAu, /* ppca.tr_ppssout[169] */
    TRIG_IN_MUX_2_PPCA_TR170        = 0x000002ABu, /* ppca.tr_ppssout[170] */
    TRIG_IN_MUX_2_PPCA_TR171        = 0x000002ACu, /* ppca.tr_ppssout[171] */
    TRIG_IN_MUX_2_PPCA_TR172        = 0x000002ADu, /* ppca.tr_ppssout[172] */
    TRIG_IN_MUX_2_PPCA_TR173        = 0x000002AEu, /* ppca.tr_ppssout[173] */
    TRIG_IN_MUX_2_PPCA_TR174        = 0x000002AFu, /* ppca.tr_ppssout[174] */
    TRIG_IN_MUX_2_PPCA_TR175        = 0x000002B0u, /* ppca.tr_ppssout[175] */
    TRIG_IN_MUX_2_PPCA_TR176        = 0x000002B1u, /* ppca.tr_ppssout[176] */
    TRIG_IN_MUX_2_PPCA_TR177        = 0x000002B2u, /* ppca.tr_ppssout[177] */
    TRIG_IN_MUX_2_PPCA_TR178        = 0x000002B3u, /* ppca.tr_ppssout[178] */
    TRIG_IN_MUX_2_PPCA_TR179        = 0x000002B4u, /* ppca.tr_ppssout[179] */
    TRIG_IN_MUX_2_PPCA_TR180        = 0x000002B5u, /* ppca.tr_ppssout[180] */
    TRIG_IN_MUX_2_PPCA_TR181        = 0x000002B6u, /* ppca.tr_ppssout[181] */
    TRIG_IN_MUX_2_PPCA_TR182        = 0x000002B7u, /* ppca.tr_ppssout[182] */
    TRIG_IN_MUX_2_PPCA_TR183        = 0x000002B8u, /* ppca.tr_ppssout[183] */
    TRIG_IN_MUX_2_PPCA_TR184        = 0x000002B9u, /* ppca.tr_ppssout[184] */
    TRIG_IN_MUX_2_PPCA_TR185        = 0x000002BAu, /* ppca.tr_ppssout[185] */
    TRIG_IN_MUX_2_PPCA_TR186        = 0x000002BBu, /* ppca.tr_ppssout[186] */
    TRIG_IN_MUX_2_PPCA_TR187        = 0x000002BCu, /* ppca.tr_ppssout[187] */
    TRIG_IN_MUX_2_PPCA_TR188        = 0x000002BDu, /* ppca.tr_ppssout[188] */
    TRIG_IN_MUX_2_PPCA_TR189        = 0x000002BEu, /* ppca.tr_ppssout[189] */
    TRIG_IN_MUX_2_PPCA_TR190        = 0x000002BFu, /* ppca.tr_ppssout[190] */
    TRIG_IN_MUX_2_PPCA_TR191        = 0x000002C0u, /* ppca.tr_ppssout[191] */
    TRIG_IN_MUX_2_PPCA_TR192        = 0x000002C1u, /* ppca.tr_ppssout[192] */
    TRIG_IN_MUX_2_PPCA_TR193        = 0x000002C2u, /* ppca.tr_ppssout[193] */
    TRIG_IN_MUX_2_PPCA_TR194        = 0x000002C3u, /* ppca.tr_ppssout[194] */
    TRIG_IN_MUX_2_PPCA_TR195        = 0x000002C4u, /* ppca.tr_ppssout[195] */
    TRIG_IN_MUX_2_PPCA_TR196        = 0x000002C5u, /* ppca.tr_ppssout[196] */
    TRIG_IN_MUX_2_PPCA_TR197        = 0x000002C6u, /* ppca.tr_ppssout[197] */
    TRIG_IN_MUX_2_PPCA_TR198        = 0x000002C7u, /* ppca.tr_ppssout[198] */
    TRIG_IN_MUX_2_PPCA_TR199        = 0x000002C8u, /* ppca.tr_ppssout[199] */
    TRIG_IN_MUX_2_PPCA_TR200        = 0x000002C9u, /* ppca.tr_ppssout[200] */
    TRIG_IN_MUX_2_PPCA_TR201        = 0x000002CAu, /* ppca.tr_ppssout[201] */
    TRIG_IN_MUX_2_PPCA_TR202        = 0x000002CBu, /* ppca.tr_ppssout[202] */
    TRIG_IN_MUX_2_PPCA_TR203        = 0x000002CCu, /* ppca.tr_ppssout[203] */
    TRIG_IN_MUX_2_PPCA_TR204        = 0x000002CDu, /* ppca.tr_ppssout[204] */
    TRIG_IN_MUX_2_PPCA_TR205        = 0x000002CEu, /* ppca.tr_ppssout[205] */
    TRIG_IN_MUX_2_PPCA_TR206        = 0x000002CFu, /* ppca.tr_ppssout[206] */
    TRIG_IN_MUX_2_PPCA_TR207        = 0x000002D0u, /* ppca.tr_ppssout[207] */
    TRIG_IN_MUX_2_PPCA_TR208        = 0x000002D1u, /* ppca.tr_ppssout[208] */
    TRIG_IN_MUX_2_PPCA_TR209        = 0x000002D2u, /* ppca.tr_ppssout[209] */
    TRIG_IN_MUX_2_PPCA_TR210        = 0x000002D3u, /* ppca.tr_ppssout[210] */
    TRIG_IN_MUX_2_PPCA_TR211        = 0x000002D4u, /* ppca.tr_ppssout[211] */
    TRIG_IN_MUX_2_PPCA_TR212        = 0x000002D5u, /* ppca.tr_ppssout[212] */
    TRIG_IN_MUX_2_PPCA_TR213        = 0x000002D6u, /* ppca.tr_ppssout[213] */
    TRIG_IN_MUX_2_PPCA_TR214        = 0x000002D7u, /* ppca.tr_ppssout[214] */
    TRIG_IN_MUX_2_PPCA_TR215        = 0x000002D8u, /* ppca.tr_ppssout[215] */
    TRIG_IN_MUX_2_PPCA_TR216        = 0x000002D9u, /* ppca.tr_ppssout[216] */
    TRIG_IN_MUX_2_PPCA_TR217        = 0x000002DAu, /* ppca.tr_ppssout[217] */
    TRIG_IN_MUX_2_PPCA_TR218        = 0x000002DBu, /* ppca.tr_ppssout[218] */
    TRIG_IN_MUX_2_PPCA_TR219        = 0x000002DCu, /* ppca.tr_ppssout[219] */
    TRIG_IN_MUX_2_PPCA_TR220        = 0x000002DDu, /* ppca.tr_ppssout[220] */
    TRIG_IN_MUX_2_PPCA_TR221        = 0x000002DEu, /* ppca.tr_ppssout[221] */
    TRIG_IN_MUX_2_PPCA_TR222        = 0x000002DFu, /* ppca.tr_ppssout[222] */
    TRIG_IN_MUX_2_PPCA_TR223        = 0x000002E0u, /* ppca.tr_ppssout[223] */
    TRIG_IN_MUX_2_PPCA_TR224        = 0x000002E1u, /* ppca.tr_ppssout[224] */
    TRIG_IN_MUX_2_PPCA_TR225        = 0x000002E2u, /* ppca.tr_ppssout[225] */
    TRIG_IN_MUX_2_PPCA_TR226        = 0x000002E3u, /* ppca.tr_ppssout[226] */
    TRIG_IN_MUX_2_PPCA_TR227        = 0x000002E4u, /* ppca.tr_ppssout[227] */
    TRIG_IN_MUX_2_PPCA_TR228        = 0x000002E5u, /* ppca.tr_ppssout[228] */
    TRIG_IN_MUX_2_PPCA_TR229        = 0x000002E6u, /* ppca.tr_ppssout[229] */
    TRIG_IN_MUX_2_PPCA_TR230        = 0x000002E7u, /* ppca.tr_ppssout[230] */
    TRIG_IN_MUX_2_PPCA_TR231        = 0x000002E8u, /* ppca.tr_ppssout[231] */
    TRIG_IN_MUX_2_PPCA_TR232        = 0x000002E9u, /* ppca.tr_ppssout[232] */
    TRIG_IN_MUX_2_PPCA_TR233        = 0x000002EAu, /* ppca.tr_ppssout[233] */
    TRIG_IN_MUX_2_PPCA_TR234        = 0x000002EBu, /* ppca.tr_ppssout[234] */
    TRIG_IN_MUX_2_PPCA_TR235        = 0x000002ECu, /* ppca.tr_ppssout[235] */
    TRIG_IN_MUX_2_PPCA_TR236        = 0x000002EDu, /* ppca.tr_ppssout[236] */
    TRIG_IN_MUX_2_PPCA_TR237        = 0x000002EEu, /* ppca.tr_ppssout[237] */
    TRIG_IN_MUX_2_PPCA_TR238        = 0x000002EFu, /* ppca.tr_ppssout[238] */
    TRIG_IN_MUX_2_PPCA_TR239        = 0x000002F0u, /* ppca.tr_ppssout[239] */
    TRIG_IN_MUX_2_PPCA_TR240        = 0x000002F1u, /* ppca.tr_ppssout[240] */
    TRIG_IN_MUX_2_PPCA_TR241        = 0x000002F2u, /* ppca.tr_ppssout[241] */
    TRIG_IN_MUX_2_PPCA_TR242        = 0x000002F3u, /* ppca.tr_ppssout[242] */
    TRIG_IN_MUX_2_PPCA_TR243        = 0x000002F4u, /* ppca.tr_ppssout[243] */
    TRIG_IN_MUX_2_PPCA_TR244        = 0x000002F5u, /* ppca.tr_ppssout[244] */
    TRIG_IN_MUX_2_PPCA_TR245        = 0x000002F6u, /* ppca.tr_ppssout[245] */
    TRIG_IN_MUX_2_PPCA_TR246        = 0x000002F7u, /* ppca.tr_ppssout[246] */
    TRIG_IN_MUX_2_PPCA_TR247        = 0x000002F8u, /* ppca.tr_ppssout[247] */
    TRIG_IN_MUX_2_PPCA_TR248        = 0x000002F9u, /* ppca.tr_ppssout[248] */
    TRIG_IN_MUX_2_PPCA_TR249        = 0x000002FAu, /* ppca.tr_ppssout[249] */
    TRIG_IN_MUX_2_PPCA_TR250        = 0x000002FBu, /* ppca.tr_ppssout[250] */
    TRIG_IN_MUX_2_PPCA_TR251        = 0x000002FCu, /* ppca.tr_ppssout[251] */
    TRIG_IN_MUX_2_PPCA_TR252        = 0x000002FDu, /* ppca.tr_ppssout[252] */
    TRIG_IN_MUX_2_PPCA_TR253        = 0x000002FEu, /* ppca.tr_ppssout[253] */
    TRIG_IN_MUX_2_PPCA_TR254        = 0x000002FFu /* ppca.tr_ppssout[254] */
} en_trig_input_hsiom1_t;

/* Trigger Input Group 3 - CPUSS Debug  multiplexer */
typedef enum
{
    TRIG_IN_MUX_3_PDMA0_TR_OUT0     = 0x00000301u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT1     = 0x00000302u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT2     = 0x00000303u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT3     = 0x00000304u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT4     = 0x00000305u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT5     = 0x00000306u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT6     = 0x00000307u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT7     = 0x00000308u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT8     = 0x00000309u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT9     = 0x0000030Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT10    = 0x0000030Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT11    = 0x0000030Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT12    = 0x0000030Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT13    = 0x0000030Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT14    = 0x0000030Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_3_PDMA0_TR_OUT15    = 0x00000310u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_3_TCPWM0_GRP0_OUT0_0 = 0x00000311u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_3_TCPWM0_GRP0_OUT0_1 = 0x00000312u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_3_TCPWM0_GRP0_OUT0_256 = 0x00000313u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_3_TCPWM0_GRP0_OUT0_257 = 0x00000314u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_3_TCPWM0_GRP0_OUT1_0 = 0x00000315u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_3_TCPWM0_GRP0_OUT1_1 = 0x00000316u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_3_TCPWM0_GRP0_OUT1_256 = 0x00000317u, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_3_TCPWM0_GRP0_OUT1_257 = 0x00000318u, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT0     = 0x00000319u, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT1     = 0x0000031Au, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT2     = 0x0000031Bu, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT3     = 0x0000031Cu, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT4     = 0x0000031Du, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT5     = 0x0000031Eu, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT6     = 0x0000031Fu, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT7     = 0x00000320u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT8     = 0x00000321u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT9     = 0x00000322u, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT10    = 0x00000323u, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT11    = 0x00000324u, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT12    = 0x00000325u, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT13    = 0x00000326u, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT14    = 0x00000327u, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT15    = 0x00000328u, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT16    = 0x00000329u, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT17    = 0x0000032Au, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT18    = 0x0000032Bu, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT19    = 0x0000032Cu, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT20    = 0x0000032Du, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT21    = 0x0000032Eu, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT22    = 0x0000032Fu, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT23    = 0x00000330u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT24    = 0x00000331u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT25    = 0x00000332u, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT26    = 0x00000333u, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT27    = 0x00000334u, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT28    = 0x00000335u, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT29    = 0x00000336u, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT30    = 0x00000337u, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT31    = 0x00000338u, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT32    = 0x00000339u, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT33    = 0x0000033Au, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT34    = 0x0000033Bu, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT35    = 0x0000033Cu, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT36    = 0x0000033Du, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT37    = 0x0000033Eu, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT38    = 0x0000033Fu, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT39    = 0x00000340u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT40    = 0x00000341u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT41    = 0x00000342u, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT42    = 0x00000343u, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT43    = 0x00000344u, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT44    = 0x00000345u, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT45    = 0x00000346u, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT46    = 0x00000347u, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT47    = 0x00000348u, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT48    = 0x00000349u, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT49    = 0x0000034Au, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT50    = 0x0000034Bu, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT51    = 0x0000034Cu, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT52    = 0x0000034Du, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT53    = 0x0000034Eu, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT54    = 0x0000034Fu, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT55    = 0x00000350u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT56    = 0x00000351u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT57    = 0x00000352u, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT58    = 0x00000353u, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT59    = 0x00000354u, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_3_SCB_I2C_SCL0      = 0x00000355u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB_TX0           = 0x00000356u, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_3_SCB_RX0           = 0x00000357u, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_3_SCB_TGS_RELOAD00  = 0x00000358u, /* scb[0].tr_tgs_reload[0] */
    TRIG_IN_MUX_3_SCB_TGS_STOP00    = 0x00000359u, /* scb[0].tr_tgs_stop[0] */
    TRIG_IN_MUX_3_SCB_TGS_GATED00   = 0x0000035Au, /* scb[0].tr_tgs_gated[0] */
    TRIG_IN_MUX_3_SCB_I2C_SCL1      = 0x0000035Bu, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB_TX1           = 0x0000035Cu, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_3_SCB_RX1           = 0x0000035Du, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_3_SCB_TGS_RELOAD10  = 0x0000035Eu, /* scb[1].tr_tgs_reload[0] */
    TRIG_IN_MUX_3_SCB_TGS_STOP10    = 0x0000035Fu, /* scb[1].tr_tgs_stop[0] */
    TRIG_IN_MUX_3_SCB_TGS_GATED10   = 0x00000360u, /* scb[1].tr_tgs_gated[0] */
    TRIG_IN_MUX_3_SCB_I2C_SCL2      = 0x00000361u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB_TX2           = 0x00000362u, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_3_SCB_RX2           = 0x00000363u, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_3_SCB_TGS_RELOAD20  = 0x00000364u, /* scb[2].tr_tgs_reload[0] */
    TRIG_IN_MUX_3_SCB_TGS_STOP20    = 0x00000365u, /* scb[2].tr_tgs_stop[0] */
    TRIG_IN_MUX_3_SCB_TGS_GATED20   = 0x00000366u, /* scb[2].tr_tgs_gated[0] */
    TRIG_IN_MUX_3_SCB_I2C_SCL3      = 0x00000367u, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB_TX3           = 0x00000368u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_3_SCB_RX3           = 0x00000369u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_3_SCB_TGS_RELOAD30  = 0x0000036Au, /* scb[3].tr_tgs_reload[0] */
    TRIG_IN_MUX_3_SCB_TGS_STOP30    = 0x0000036Bu, /* scb[3].tr_tgs_stop[0] */
    TRIG_IN_MUX_3_SCB_TGS_GATED30   = 0x0000036Cu, /* scb[3].tr_tgs_gated[0] */
    TRIG_IN_MUX_3_SCB_I2C_SCL4      = 0x0000036Du, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB_TX4           = 0x0000036Eu, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_3_SCB_RX4           = 0x0000036Fu, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_3_SCB_TGS_RELOAD40  = 0x00000370u, /* scb[4].tr_tgs_reload[0] */
    TRIG_IN_MUX_3_SCB_TGS_STOP40    = 0x00000371u, /* scb[4].tr_tgs_stop[0] */
    TRIG_IN_MUX_3_SCB_TGS_GATED40   = 0x00000372u, /* scb[4].tr_tgs_gated[0] */
    TRIG_IN_MUX_3_SCB_I2C_SCL5      = 0x00000373u, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB_TX5           = 0x00000374u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_3_SCB_RX5           = 0x00000375u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_3_SCB_TGS_RELOAD50  = 0x00000376u, /* scb[5].tr_tgs_reload[0] */
    TRIG_IN_MUX_3_SCB_TGS_STOP50    = 0x00000377u, /* scb[5].tr_tgs_stop[0] */
    TRIG_IN_MUX_3_SCB_TGS_GATED50   = 0x00000378u, /* scb[5].tr_tgs_gated[0] */
    TRIG_IN_MUX_3_SCB_I2C_SCL6      = 0x00000379u, /* scb[6].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB_TX6           = 0x0000037Au, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_3_SCB_RX6           = 0x0000037Bu, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_3_SCB_TGS_RELOAD60  = 0x0000037Cu, /* scb[6].tr_tgs_reload[0] */
    TRIG_IN_MUX_3_SCB_TGS_STOP60    = 0x0000037Du, /* scb[6].tr_tgs_stop[0] */
    TRIG_IN_MUX_3_SCB_TGS_GATED60   = 0x0000037Eu, /* scb[6].tr_tgs_gated[0] */
    TRIG_IN_MUX_3_CTI_TR_OUT0       = 0x0000037Fu, /* debug600.cti_tr_out[0] */
    TRIG_IN_MUX_3_CTI_TR_OUT1       = 0x00000380u, /* debug600.cti_tr_out[1] */
    TRIG_IN_MUX_3_CANFD_TT_TR_OUT0  = 0x00000381u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_3_CANFD_TT_TR_OUT1  = 0x00000382u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_3_LPCOMP_DSI_COMP0  = 0x00000383u, /* lpcomp.dsi_comp0 */
    TRIG_IN_MUX_3_LPCOMP_DSI_COMP1  = 0x00000384u, /* lpcomp.dsi_comp1 */
    TRIG_IN_MUX_3_CPUSS_TR_FAULT0   = 0x00000385u, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_3_PPCA_TR52         = 0x00000386u, /* ppca.tr_ppssout[52] */
    TRIG_IN_MUX_3_PPCA_TR53         = 0x00000387u, /* ppca.tr_ppssout[53] */
    TRIG_IN_MUX_3_PPCA_TR54         = 0x00000388u, /* ppca.tr_ppssout[54] */
    TRIG_IN_MUX_3_PPCA_TR55         = 0x00000389u, /* ppca.tr_ppssout[55] */
    TRIG_IN_MUX_3_PPCA_TR56         = 0x0000038Au, /* ppca.tr_ppssout[56] */
    TRIG_IN_MUX_3_PPCA_TR57         = 0x0000038Bu, /* ppca.tr_ppssout[57] */
    TRIG_IN_MUX_3_PPCA_TR58         = 0x0000038Cu, /* ppca.tr_ppssout[58] */
    TRIG_IN_MUX_3_PPCA_TR59         = 0x0000038Du, /* ppca.tr_ppssout[59] */
    TRIG_IN_MUX_3_PPCA_TR60         = 0x0000038Eu, /* ppca.tr_ppssout[60] */
    TRIG_IN_MUX_3_PPCA_TR61         = 0x0000038Fu, /* ppca.tr_ppssout[61] */
    TRIG_IN_MUX_3_PPCA_TR62         = 0x00000390u, /* ppca.tr_ppssout[62] */
    TRIG_IN_MUX_3_PPCA_TR63         = 0x00000391u, /* ppca.tr_ppssout[63] */
    TRIG_IN_MUX_3_PPCA_TR76         = 0x00000392u, /* ppca.tr_ppssout[76] */
    TRIG_IN_MUX_3_PPCA_TR77         = 0x00000393u, /* ppca.tr_ppssout[77] */
    TRIG_IN_MUX_3_PPCA_TR78         = 0x00000394u, /* ppca.tr_ppssout[78] */
    TRIG_IN_MUX_3_PPCA_TR79         = 0x00000395u, /* ppca.tr_ppssout[79] */
    TRIG_IN_MUX_3_PPCA_TR80         = 0x00000396u, /* ppca.tr_ppssout[80] */
    TRIG_IN_MUX_3_PPCA_TR81         = 0x00000397u, /* ppca.tr_ppssout[81] */
    TRIG_IN_MUX_3_PPCA_TR82         = 0x00000398u, /* ppca.tr_ppssout[82] */
    TRIG_IN_MUX_3_PPCA_TR83         = 0x00000399u, /* ppca.tr_ppssout[83] */
    TRIG_IN_MUX_3_PPCA_TR84         = 0x0000039Au, /* ppca.tr_ppssout[84] */
    TRIG_IN_MUX_3_PPCA_TR85         = 0x0000039Bu, /* ppca.tr_ppssout[85] */
    TRIG_IN_MUX_3_PPCA_TR86         = 0x0000039Cu, /* ppca.tr_ppssout[86] */
    TRIG_IN_MUX_3_PPCA_TR87         = 0x0000039Du, /* ppca.tr_ppssout[87] */
    TRIG_IN_MUX_3_PPCA_TR88         = 0x0000039Eu, /* ppca.tr_ppssout[88] */
    TRIG_IN_MUX_3_PPCA_TR89         = 0x0000039Fu, /* ppca.tr_ppssout[89] */
    TRIG_IN_MUX_3_PPCA_TR90         = 0x000003A0u, /* ppca.tr_ppssout[90] */
    TRIG_IN_MUX_3_PPCA_TR91         = 0x000003A1u, /* ppca.tr_ppssout[91] */
    TRIG_IN_MUX_3_PPCA_TR100        = 0x000003A2u, /* ppca.tr_ppssout[100] */
    TRIG_IN_MUX_3_PPCA_TR101        = 0x000003A3u, /* ppca.tr_ppssout[101] */
    TRIG_IN_MUX_3_PPCA_TR102        = 0x000003A4u, /* ppca.tr_ppssout[102] */
    TRIG_IN_MUX_3_PPCA_TR103        = 0x000003A5u, /* ppca.tr_ppssout[103] */
    TRIG_IN_MUX_3_PPCA_TR104        = 0x000003A6u, /* ppca.tr_ppssout[104] */
    TRIG_IN_MUX_3_PPCA_TR105        = 0x000003A7u, /* ppca.tr_ppssout[105] */
    TRIG_IN_MUX_3_PPCA_TR106        = 0x000003A8u, /* ppca.tr_ppssout[106] */
    TRIG_IN_MUX_3_PPCA_TR107        = 0x000003A9u, /* ppca.tr_ppssout[107] */
    TRIG_IN_MUX_3_PPCA_TR108        = 0x000003AAu, /* ppca.tr_ppssout[108] */
    TRIG_IN_MUX_3_PPCA_TR109        = 0x000003ABu, /* ppca.tr_ppssout[109] */
    TRIG_IN_MUX_3_PPCA_TR110        = 0x000003ACu, /* ppca.tr_ppssout[110] */
    TRIG_IN_MUX_3_PPCA_TR111        = 0x000003ADu, /* ppca.tr_ppssout[111] */
    TRIG_IN_MUX_3_PPCA_TR116        = 0x000003AEu, /* ppca.tr_ppssout[116] */
    TRIG_IN_MUX_3_PPCA_TR117        = 0x000003AFu, /* ppca.tr_ppssout[117] */
    TRIG_IN_MUX_3_PPCA_TR136        = 0x000003B0u, /* ppca.tr_ppssout[136] */
    TRIG_IN_MUX_3_PPCA_TR137        = 0x000003B1u, /* ppca.tr_ppssout[137] */
    TRIG_IN_MUX_3_PPCA_TR138        = 0x000003B2u, /* ppca.tr_ppssout[138] */
    TRIG_IN_MUX_3_PPCA_TR139        = 0x000003B3u, /* ppca.tr_ppssout[139] */
    TRIG_IN_MUX_3_PPCA_TR140        = 0x000003B4u, /* ppca.tr_ppssout[140] */
    TRIG_IN_MUX_3_PPCA_TR141        = 0x000003B5u, /* ppca.tr_ppssout[141] */
    TRIG_IN_MUX_3_PPCA_TR142        = 0x000003B6u, /* ppca.tr_ppssout[142] */
    TRIG_IN_MUX_3_PPCA_TR143        = 0x000003B7u, /* ppca.tr_ppssout[143] */
    TRIG_IN_MUX_3_PPCA_TR144        = 0x000003B8u, /* ppca.tr_ppssout[144] */
    TRIG_IN_MUX_3_PPCA_TR145        = 0x000003B9u, /* ppca.tr_ppssout[145] */
    TRIG_IN_MUX_3_PPCA_TR146        = 0x000003BAu, /* ppca.tr_ppssout[146] */
    TRIG_IN_MUX_3_PPCA_TR147        = 0x000003BBu, /* ppca.tr_ppssout[147] */
    TRIG_IN_MUX_3_PPCA_TR148        = 0x000003BCu, /* ppca.tr_ppssout[148] */
    TRIG_IN_MUX_3_PPCA_TR149        = 0x000003BDu, /* ppca.tr_ppssout[149] */
    TRIG_IN_MUX_3_PPCA_TR150        = 0x000003BEu, /* ppca.tr_ppssout[150] */
    TRIG_IN_MUX_3_PPCA_TR151        = 0x000003BFu, /* ppca.tr_ppssout[151] */
    TRIG_IN_MUX_3_PPCA_TR152        = 0x000003C0u, /* ppca.tr_ppssout[152] */
    TRIG_IN_MUX_3_PPCA_TR153        = 0x000003C1u, /* ppca.tr_ppssout[153] */
    TRIG_IN_MUX_3_PPCA_TR154        = 0x000003C2u, /* ppca.tr_ppssout[154] */
    TRIG_IN_MUX_3_PPCA_TR155        = 0x000003C3u, /* ppca.tr_ppssout[155] */
    TRIG_IN_MUX_3_PPCA_TR156        = 0x000003C4u, /* ppca.tr_ppssout[156] */
    TRIG_IN_MUX_3_PPCA_TR157        = 0x000003C5u, /* ppca.tr_ppssout[157] */
    TRIG_IN_MUX_3_PPCA_TR158        = 0x000003C6u, /* ppca.tr_ppssout[158] */
    TRIG_IN_MUX_3_PPCA_TR159        = 0x000003C7u, /* ppca.tr_ppssout[159] */
    TRIG_IN_MUX_3_PPCA_TR160        = 0x000003C8u, /* ppca.tr_ppssout[160] */
    TRIG_IN_MUX_3_PPCA_TR161        = 0x000003C9u, /* ppca.tr_ppssout[161] */
    TRIG_IN_MUX_3_PPCA_TR162        = 0x000003CAu, /* ppca.tr_ppssout[162] */
    TRIG_IN_MUX_3_PPCA_TR163        = 0x000003CBu, /* ppca.tr_ppssout[163] */
    TRIG_IN_MUX_3_PPCA_TR164        = 0x000003CCu, /* ppca.tr_ppssout[164] */
    TRIG_IN_MUX_3_PPCA_TR165        = 0x000003CDu, /* ppca.tr_ppssout[165] */
    TRIG_IN_MUX_3_PPCA_TR166        = 0x000003CEu, /* ppca.tr_ppssout[166] */
    TRIG_IN_MUX_3_PPCA_TR167        = 0x000003CFu, /* ppca.tr_ppssout[167] */
    TRIG_IN_MUX_3_PPCA_TR168        = 0x000003D0u, /* ppca.tr_ppssout[168] */
    TRIG_IN_MUX_3_PPCA_TR169        = 0x000003D1u, /* ppca.tr_ppssout[169] */
    TRIG_IN_MUX_3_PPCA_TR170        = 0x000003D2u, /* ppca.tr_ppssout[170] */
    TRIG_IN_MUX_3_PPCA_TR171        = 0x000003D3u, /* ppca.tr_ppssout[171] */
    TRIG_IN_MUX_3_PPCA_TR172        = 0x000003D4u, /* ppca.tr_ppssout[172] */
    TRIG_IN_MUX_3_PPCA_TR173        = 0x000003D5u, /* ppca.tr_ppssout[173] */
    TRIG_IN_MUX_3_PPCA_TR174        = 0x000003D6u, /* ppca.tr_ppssout[174] */
    TRIG_IN_MUX_3_PPCA_TR175        = 0x000003D7u, /* ppca.tr_ppssout[175] */
    TRIG_IN_MUX_3_PPCA_TR176        = 0x000003D8u, /* ppca.tr_ppssout[176] */
    TRIG_IN_MUX_3_PPCA_TR177        = 0x000003D9u, /* ppca.tr_ppssout[177] */
    TRIG_IN_MUX_3_PPCA_TR178        = 0x000003DAu, /* ppca.tr_ppssout[178] */
    TRIG_IN_MUX_3_PPCA_TR179        = 0x000003DBu, /* ppca.tr_ppssout[179] */
    TRIG_IN_MUX_3_PPCA_TR180        = 0x000003DCu, /* ppca.tr_ppssout[180] */
    TRIG_IN_MUX_3_PPCA_TR181        = 0x000003DDu, /* ppca.tr_ppssout[181] */
    TRIG_IN_MUX_3_PPCA_TR182        = 0x000003DEu, /* ppca.tr_ppssout[182] */
    TRIG_IN_MUX_3_PPCA_TR183        = 0x000003DFu, /* ppca.tr_ppssout[183] */
    TRIG_IN_MUX_3_PPCA_TR184        = 0x000003E0u, /* ppca.tr_ppssout[184] */
    TRIG_IN_MUX_3_PPCA_TR185        = 0x000003E1u, /* ppca.tr_ppssout[185] */
    TRIG_IN_MUX_3_PPCA_TR186        = 0x000003E2u, /* ppca.tr_ppssout[186] */
    TRIG_IN_MUX_3_PPCA_TR193        = 0x000003E3u, /* ppca.tr_ppssout[193] */
    TRIG_IN_MUX_3_PPCA_TR194        = 0x000003E4u, /* ppca.tr_ppssout[194] */
    TRIG_IN_MUX_3_PPCA_TR195        = 0x000003E5u, /* ppca.tr_ppssout[195] */
    TRIG_IN_MUX_3_PPCA_TR196        = 0x000003E6u, /* ppca.tr_ppssout[196] */
    TRIG_IN_MUX_3_PPCA_TR197        = 0x000003E7u, /* ppca.tr_ppssout[197] */
    TRIG_IN_MUX_3_PPCA_TR198        = 0x000003E8u, /* ppca.tr_ppssout[198] */
    TRIG_IN_MUX_3_PPCA_TR199        = 0x000003E9u, /* ppca.tr_ppssout[199] */
    TRIG_IN_MUX_3_PPCA_TR200        = 0x000003EAu, /* ppca.tr_ppssout[200] */
    TRIG_IN_MUX_3_PPCA_TR212        = 0x000003EBu, /* ppca.tr_ppssout[212] */
    TRIG_IN_MUX_3_PPCA_TR213        = 0x000003ECu, /* ppca.tr_ppssout[213] */
    TRIG_IN_MUX_3_PPCA_TR214        = 0x000003EDu, /* ppca.tr_ppssout[214] */
    TRIG_IN_MUX_3_PPCA_TR215        = 0x000003EEu, /* ppca.tr_ppssout[215] */
    TRIG_IN_MUX_3_PPCA_TR216        = 0x000003EFu, /* ppca.tr_ppssout[216] */
    TRIG_IN_MUX_3_PPCA_TR217        = 0x000003F0u /* ppca.tr_ppssout[217] */
} en_trig_input_cpuss_cti_t;

/* Trigger Input Group 4 - CAN TT Synchronization triggers */
typedef enum
{
    TRIG_IN_MUX_4_CAN_TT_TR_OUT0    = 0x00000401u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_4_CAN_TT_TR_OUT1    = 0x00000402u /* canfd[0].tr_tmp_rtp_out[1] */
} en_trig_input_cantt_t;

/* Trigger Input Group 5 - PERI Freeze trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_5_CPUSS_TR_FAULT0   = 0x00000501u, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_5_CTI_TR_OUT0       = 0x00000502u, /* debug600.cti_tr_out[0] */
    TRIG_IN_MUX_5_CTI_TR_OUT1       = 0x00000503u /* debug600.cti_tr_out[1] */
} en_trig_input_peri_freeze_t;

/* Trigger Input Group 6 - TCPWM1 trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_6_PDMA0_TR_OUT0     = 0x00000601u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT1     = 0x00000602u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT2     = 0x00000603u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT3     = 0x00000604u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT4     = 0x00000605u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT5     = 0x00000606u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT6     = 0x00000607u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT7     = 0x00000608u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT8     = 0x00000609u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT9     = 0x0000060Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT10    = 0x0000060Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT11    = 0x0000060Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT12    = 0x0000060Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT13    = 0x0000060Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT14    = 0x0000060Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_6_PDMA0_TR_OUT15    = 0x00000610u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_6_TCPWM0_GRP0_OUT0_0 = 0x00000611u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_6_TCPWM0_GRP0_OUT0_1 = 0x00000612u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_6_TCPWM0_GRP0_OUT0_256 = 0x00000613u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_6_TCPWM0_GRP0_OUT0_257 = 0x00000614u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_6_TCPWM0_GRP0_OUT1_0 = 0x00000615u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_6_TCPWM0_GRP0_OUT1_1 = 0x00000616u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_6_TCPWM0_GRP0_OUT1_256 = 0x00000617u, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_6_TCPWM0_GRP0_OUT1_257 = 0x00000618u, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT0     = 0x00000619u, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT1     = 0x0000061Au, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT2     = 0x0000061Bu, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT3     = 0x0000061Cu, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT4     = 0x0000061Du, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT5     = 0x0000061Eu, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT6     = 0x0000061Fu, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT7     = 0x00000620u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT8     = 0x00000621u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT9     = 0x00000622u, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT10    = 0x00000623u, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT11    = 0x00000624u, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT12    = 0x00000625u, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT13    = 0x00000626u, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT14    = 0x00000627u, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT15    = 0x00000628u, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT16    = 0x00000629u, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT17    = 0x0000062Au, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT18    = 0x0000062Bu, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT19    = 0x0000062Cu, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT20    = 0x0000062Du, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT21    = 0x0000062Eu, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT22    = 0x0000062Fu, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT23    = 0x00000630u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT24    = 0x00000631u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT25    = 0x00000632u, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT26    = 0x00000633u, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT27    = 0x00000634u, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT28    = 0x00000635u, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT29    = 0x00000636u, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT30    = 0x00000637u, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT31    = 0x00000638u, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT32    = 0x00000639u, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT33    = 0x0000063Au, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT34    = 0x0000063Bu, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT35    = 0x0000063Cu, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT36    = 0x0000063Du, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT37    = 0x0000063Eu, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT38    = 0x0000063Fu, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT39    = 0x00000640u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT40    = 0x00000641u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT41    = 0x00000642u, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT42    = 0x00000643u, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT43    = 0x00000644u, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT44    = 0x00000645u, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT45    = 0x00000646u, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT46    = 0x00000647u, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT47    = 0x00000648u, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT48    = 0x00000649u, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT49    = 0x0000064Au, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT50    = 0x0000064Bu, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT51    = 0x0000064Cu, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT52    = 0x0000064Du, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT53    = 0x0000064Eu, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT54    = 0x0000064Fu, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT55    = 0x00000650u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT56    = 0x00000651u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT57    = 0x00000652u, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT58    = 0x00000653u, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_6_HSIOM_TR_OUT59    = 0x00000654u, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_6_SCB_I2C_SCL0      = 0x00000655u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX0           = 0x00000656u, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX0           = 0x00000657u, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_6_SCB_TGS_RELOAD00  = 0x00000658u, /* scb[0].tr_tgs_reload[0] */
    TRIG_IN_MUX_6_SCB_TGS_STOP00    = 0x00000659u, /* scb[0].tr_tgs_stop[0] */
    TRIG_IN_MUX_6_SCB_TGS_GATED00   = 0x0000065Au, /* scb[0].tr_tgs_gated[0] */
    TRIG_IN_MUX_6_SCB_I2C_SCL1      = 0x0000065Bu, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX1           = 0x0000065Cu, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX1           = 0x0000065Du, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_6_SCB_TGS_RELOAD10  = 0x0000065Eu, /* scb[1].tr_tgs_reload[0] */
    TRIG_IN_MUX_6_SCB_TGS_STOP10    = 0x0000065Fu, /* scb[1].tr_tgs_stop[0] */
    TRIG_IN_MUX_6_SCB_TGS_GATED10   = 0x00000660u, /* scb[1].tr_tgs_gated[0] */
    TRIG_IN_MUX_6_SCB_I2C_SCL2      = 0x00000661u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX2           = 0x00000662u, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX2           = 0x00000663u, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_6_SCB_TGS_RELOAD20  = 0x00000664u, /* scb[2].tr_tgs_reload[0] */
    TRIG_IN_MUX_6_SCB_TGS_STOP20    = 0x00000665u, /* scb[2].tr_tgs_stop[0] */
    TRIG_IN_MUX_6_SCB_TGS_GATED20   = 0x00000666u, /* scb[2].tr_tgs_gated[0] */
    TRIG_IN_MUX_6_SCB_I2C_SCL3      = 0x00000667u, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX3           = 0x00000668u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX3           = 0x00000669u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_6_SCB_TGS_RELOAD30  = 0x0000066Au, /* scb[3].tr_tgs_reload[0] */
    TRIG_IN_MUX_6_SCB_TGS_STOP30    = 0x0000066Bu, /* scb[3].tr_tgs_stop[0] */
    TRIG_IN_MUX_6_SCB_TGS_GATED30   = 0x0000066Cu, /* scb[3].tr_tgs_gated[0] */
    TRIG_IN_MUX_6_SCB_I2C_SCL4      = 0x0000066Du, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX4           = 0x0000066Eu, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX4           = 0x0000066Fu, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_6_SCB_TGS_RELOAD40  = 0x00000670u, /* scb[4].tr_tgs_reload[0] */
    TRIG_IN_MUX_6_SCB_TGS_STOP40    = 0x00000671u, /* scb[4].tr_tgs_stop[0] */
    TRIG_IN_MUX_6_SCB_TGS_GATED40   = 0x00000672u, /* scb[4].tr_tgs_gated[0] */
    TRIG_IN_MUX_6_SCB_I2C_SCL5      = 0x00000673u, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX5           = 0x00000674u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX5           = 0x00000675u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_6_SCB_TGS_RELOAD50  = 0x00000676u, /* scb[5].tr_tgs_reload[0] */
    TRIG_IN_MUX_6_SCB_TGS_STOP50    = 0x00000677u, /* scb[5].tr_tgs_stop[0] */
    TRIG_IN_MUX_6_SCB_TGS_GATED50   = 0x00000678u, /* scb[5].tr_tgs_gated[0] */
    TRIG_IN_MUX_6_SCB_I2C_SCL6      = 0x00000679u, /* scb[6].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX6           = 0x0000067Au, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX6           = 0x0000067Bu, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_6_SCB_TGS_RELOAD60  = 0x0000067Cu, /* scb[6].tr_tgs_reload[0] */
    TRIG_IN_MUX_6_SCB_TGS_STOP60    = 0x0000067Du, /* scb[6].tr_tgs_stop[0] */
    TRIG_IN_MUX_6_SCB_TGS_GATED60   = 0x0000067Eu, /* scb[6].tr_tgs_gated[0] */
    TRIG_IN_MUX_6_CANFD_TT_TR_OUT0  = 0x0000067Fu, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_6_CANFD_TT_TR_OUT1  = 0x00000680u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_6_CPUSS_TR_FAULT0   = 0x00000681u, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_6_PPCA_TR52         = 0x00000682u, /* ppca.tr_ppssout[52] */
    TRIG_IN_MUX_6_PPCA_TR53         = 0x00000683u, /* ppca.tr_ppssout[53] */
    TRIG_IN_MUX_6_PPCA_TR54         = 0x00000684u, /* ppca.tr_ppssout[54] */
    TRIG_IN_MUX_6_PPCA_TR55         = 0x00000685u, /* ppca.tr_ppssout[55] */
    TRIG_IN_MUX_6_PPCA_TR56         = 0x00000686u, /* ppca.tr_ppssout[56] */
    TRIG_IN_MUX_6_PPCA_TR57         = 0x00000687u, /* ppca.tr_ppssout[57] */
    TRIG_IN_MUX_6_PPCA_TR58         = 0x00000688u, /* ppca.tr_ppssout[58] */
    TRIG_IN_MUX_6_PPCA_TR59         = 0x00000689u, /* ppca.tr_ppssout[59] */
    TRIG_IN_MUX_6_PPCA_TR60         = 0x0000068Au, /* ppca.tr_ppssout[60] */
    TRIG_IN_MUX_6_PPCA_TR61         = 0x0000068Bu, /* ppca.tr_ppssout[61] */
    TRIG_IN_MUX_6_PPCA_TR62         = 0x0000068Cu, /* ppca.tr_ppssout[62] */
    TRIG_IN_MUX_6_PPCA_TR63         = 0x0000068Du, /* ppca.tr_ppssout[63] */
    TRIG_IN_MUX_6_PPCA_TR76         = 0x0000068Eu, /* ppca.tr_ppssout[76] */
    TRIG_IN_MUX_6_PPCA_TR77         = 0x0000068Fu, /* ppca.tr_ppssout[77] */
    TRIG_IN_MUX_6_PPCA_TR78         = 0x00000690u, /* ppca.tr_ppssout[78] */
    TRIG_IN_MUX_6_PPCA_TR79         = 0x00000691u, /* ppca.tr_ppssout[79] */
    TRIG_IN_MUX_6_PPCA_TR80         = 0x00000692u, /* ppca.tr_ppssout[80] */
    TRIG_IN_MUX_6_PPCA_TR81         = 0x00000693u, /* ppca.tr_ppssout[81] */
    TRIG_IN_MUX_6_PPCA_TR82         = 0x00000694u, /* ppca.tr_ppssout[82] */
    TRIG_IN_MUX_6_PPCA_TR83         = 0x00000695u, /* ppca.tr_ppssout[83] */
    TRIG_IN_MUX_6_PPCA_TR84         = 0x00000696u, /* ppca.tr_ppssout[84] */
    TRIG_IN_MUX_6_PPCA_TR85         = 0x00000697u, /* ppca.tr_ppssout[85] */
    TRIG_IN_MUX_6_PPCA_TR86         = 0x00000698u, /* ppca.tr_ppssout[86] */
    TRIG_IN_MUX_6_PPCA_TR87         = 0x00000699u, /* ppca.tr_ppssout[87] */
    TRIG_IN_MUX_6_PPCA_TR88         = 0x0000069Au, /* ppca.tr_ppssout[88] */
    TRIG_IN_MUX_6_PPCA_TR89         = 0x0000069Bu, /* ppca.tr_ppssout[89] */
    TRIG_IN_MUX_6_PPCA_TR90         = 0x0000069Cu, /* ppca.tr_ppssout[90] */
    TRIG_IN_MUX_6_PPCA_TR91         = 0x0000069Du, /* ppca.tr_ppssout[91] */
    TRIG_IN_MUX_6_PPCA_TR100        = 0x0000069Eu, /* ppca.tr_ppssout[100] */
    TRIG_IN_MUX_6_PPCA_TR101        = 0x0000069Fu, /* ppca.tr_ppssout[101] */
    TRIG_IN_MUX_6_PPCA_TR102        = 0x000006A0u, /* ppca.tr_ppssout[102] */
    TRIG_IN_MUX_6_PPCA_TR103        = 0x000006A1u, /* ppca.tr_ppssout[103] */
    TRIG_IN_MUX_6_PPCA_TR104        = 0x000006A2u, /* ppca.tr_ppssout[104] */
    TRIG_IN_MUX_6_PPCA_TR105        = 0x000006A3u, /* ppca.tr_ppssout[105] */
    TRIG_IN_MUX_6_PPCA_TR106        = 0x000006A4u, /* ppca.tr_ppssout[106] */
    TRIG_IN_MUX_6_PPCA_TR107        = 0x000006A5u, /* ppca.tr_ppssout[107] */
    TRIG_IN_MUX_6_PPCA_TR108        = 0x000006A6u, /* ppca.tr_ppssout[108] */
    TRIG_IN_MUX_6_PPCA_TR109        = 0x000006A7u, /* ppca.tr_ppssout[109] */
    TRIG_IN_MUX_6_PPCA_TR110        = 0x000006A8u, /* ppca.tr_ppssout[110] */
    TRIG_IN_MUX_6_PPCA_TR111        = 0x000006A9u, /* ppca.tr_ppssout[111] */
    TRIG_IN_MUX_6_PPCA_TR116        = 0x000006AAu, /* ppca.tr_ppssout[116] */
    TRIG_IN_MUX_6_PPCA_TR117        = 0x000006ABu, /* ppca.tr_ppssout[117] */
    TRIG_IN_MUX_6_PPCA_TR136        = 0x000006ACu, /* ppca.tr_ppssout[136] */
    TRIG_IN_MUX_6_PPCA_TR137        = 0x000006ADu, /* ppca.tr_ppssout[137] */
    TRIG_IN_MUX_6_PPCA_TR138        = 0x000006AEu, /* ppca.tr_ppssout[138] */
    TRIG_IN_MUX_6_PPCA_TR139        = 0x000006AFu, /* ppca.tr_ppssout[139] */
    TRIG_IN_MUX_6_PPCA_TR140        = 0x000006B0u, /* ppca.tr_ppssout[140] */
    TRIG_IN_MUX_6_PPCA_TR141        = 0x000006B1u, /* ppca.tr_ppssout[141] */
    TRIG_IN_MUX_6_PPCA_TR142        = 0x000006B2u, /* ppca.tr_ppssout[142] */
    TRIG_IN_MUX_6_PPCA_TR143        = 0x000006B3u, /* ppca.tr_ppssout[143] */
    TRIG_IN_MUX_6_PPCA_TR144        = 0x000006B4u, /* ppca.tr_ppssout[144] */
    TRIG_IN_MUX_6_PPCA_TR145        = 0x000006B5u, /* ppca.tr_ppssout[145] */
    TRIG_IN_MUX_6_PPCA_TR146        = 0x000006B6u, /* ppca.tr_ppssout[146] */
    TRIG_IN_MUX_6_PPCA_TR147        = 0x000006B7u, /* ppca.tr_ppssout[147] */
    TRIG_IN_MUX_6_PPCA_TR148        = 0x000006B8u, /* ppca.tr_ppssout[148] */
    TRIG_IN_MUX_6_PPCA_TR149        = 0x000006B9u, /* ppca.tr_ppssout[149] */
    TRIG_IN_MUX_6_PPCA_TR150        = 0x000006BAu, /* ppca.tr_ppssout[150] */
    TRIG_IN_MUX_6_PPCA_TR151        = 0x000006BBu, /* ppca.tr_ppssout[151] */
    TRIG_IN_MUX_6_PPCA_TR152        = 0x000006BCu, /* ppca.tr_ppssout[152] */
    TRIG_IN_MUX_6_PPCA_TR153        = 0x000006BDu, /* ppca.tr_ppssout[153] */
    TRIG_IN_MUX_6_PPCA_TR154        = 0x000006BEu, /* ppca.tr_ppssout[154] */
    TRIG_IN_MUX_6_PPCA_TR155        = 0x000006BFu, /* ppca.tr_ppssout[155] */
    TRIG_IN_MUX_6_PPCA_TR156        = 0x000006C0u, /* ppca.tr_ppssout[156] */
    TRIG_IN_MUX_6_PPCA_TR157        = 0x000006C1u, /* ppca.tr_ppssout[157] */
    TRIG_IN_MUX_6_PPCA_TR158        = 0x000006C2u, /* ppca.tr_ppssout[158] */
    TRIG_IN_MUX_6_PPCA_TR159        = 0x000006C3u, /* ppca.tr_ppssout[159] */
    TRIG_IN_MUX_6_PPCA_TR160        = 0x000006C4u, /* ppca.tr_ppssout[160] */
    TRIG_IN_MUX_6_PPCA_TR161        = 0x000006C5u, /* ppca.tr_ppssout[161] */
    TRIG_IN_MUX_6_PPCA_TR162        = 0x000006C6u, /* ppca.tr_ppssout[162] */
    TRIG_IN_MUX_6_PPCA_TR163        = 0x000006C7u, /* ppca.tr_ppssout[163] */
    TRIG_IN_MUX_6_PPCA_TR164        = 0x000006C8u, /* ppca.tr_ppssout[164] */
    TRIG_IN_MUX_6_PPCA_TR165        = 0x000006C9u, /* ppca.tr_ppssout[165] */
    TRIG_IN_MUX_6_PPCA_TR166        = 0x000006CAu, /* ppca.tr_ppssout[166] */
    TRIG_IN_MUX_6_PPCA_TR167        = 0x000006CBu, /* ppca.tr_ppssout[167] */
    TRIG_IN_MUX_6_PPCA_TR168        = 0x000006CCu, /* ppca.tr_ppssout[168] */
    TRIG_IN_MUX_6_PPCA_TR169        = 0x000006CDu, /* ppca.tr_ppssout[169] */
    TRIG_IN_MUX_6_PPCA_TR170        = 0x000006CEu, /* ppca.tr_ppssout[170] */
    TRIG_IN_MUX_6_PPCA_TR171        = 0x000006CFu, /* ppca.tr_ppssout[171] */
    TRIG_IN_MUX_6_PPCA_TR172        = 0x000006D0u, /* ppca.tr_ppssout[172] */
    TRIG_IN_MUX_6_PPCA_TR173        = 0x000006D1u, /* ppca.tr_ppssout[173] */
    TRIG_IN_MUX_6_PPCA_TR174        = 0x000006D2u, /* ppca.tr_ppssout[174] */
    TRIG_IN_MUX_6_PPCA_TR175        = 0x000006D3u, /* ppca.tr_ppssout[175] */
    TRIG_IN_MUX_6_PPCA_TR176        = 0x000006D4u, /* ppca.tr_ppssout[176] */
    TRIG_IN_MUX_6_PPCA_TR177        = 0x000006D5u, /* ppca.tr_ppssout[177] */
    TRIG_IN_MUX_6_PPCA_TR178        = 0x000006D6u, /* ppca.tr_ppssout[178] */
    TRIG_IN_MUX_6_PPCA_TR179        = 0x000006D7u, /* ppca.tr_ppssout[179] */
    TRIG_IN_MUX_6_PPCA_TR180        = 0x000006D8u, /* ppca.tr_ppssout[180] */
    TRIG_IN_MUX_6_PPCA_TR181        = 0x000006D9u, /* ppca.tr_ppssout[181] */
    TRIG_IN_MUX_6_PPCA_TR182        = 0x000006DAu, /* ppca.tr_ppssout[182] */
    TRIG_IN_MUX_6_PPCA_TR183        = 0x000006DBu, /* ppca.tr_ppssout[183] */
    TRIG_IN_MUX_6_PPCA_TR184        = 0x000006DCu, /* ppca.tr_ppssout[184] */
    TRIG_IN_MUX_6_PPCA_TR185        = 0x000006DDu, /* ppca.tr_ppssout[185] */
    TRIG_IN_MUX_6_PPCA_TR186        = 0x000006DEu, /* ppca.tr_ppssout[186] */
    TRIG_IN_MUX_6_PPCA_TR193        = 0x000006DFu, /* ppca.tr_ppssout[193] */
    TRIG_IN_MUX_6_PPCA_TR194        = 0x000006E0u, /* ppca.tr_ppssout[194] */
    TRIG_IN_MUX_6_PPCA_TR195        = 0x000006E1u, /* ppca.tr_ppssout[195] */
    TRIG_IN_MUX_6_PPCA_TR196        = 0x000006E2u, /* ppca.tr_ppssout[196] */
    TRIG_IN_MUX_6_PPCA_TR197        = 0x000006E3u, /* ppca.tr_ppssout[197] */
    TRIG_IN_MUX_6_PPCA_TR198        = 0x000006E4u, /* ppca.tr_ppssout[198] */
    TRIG_IN_MUX_6_PPCA_TR199        = 0x000006E5u, /* ppca.tr_ppssout[199] */
    TRIG_IN_MUX_6_PPCA_TR200        = 0x000006E6u /* ppca.tr_ppssout[200] */
} en_trig_input_tcpwm0_t;

/* Trigger Input Group 7 - PPSS trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_7_PDMA0_TR_OUT0     = 0x00000701u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT1     = 0x00000702u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT2     = 0x00000703u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT3     = 0x00000704u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT4     = 0x00000705u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT5     = 0x00000706u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT6     = 0x00000707u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT7     = 0x00000708u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT8     = 0x00000709u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT9     = 0x0000070Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT10    = 0x0000070Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT11    = 0x0000070Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT12    = 0x0000070Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT13    = 0x0000070Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT14    = 0x0000070Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT15    = 0x00000710u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT0_0 = 0x00000711u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT0_1 = 0x00000712u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT0_256 = 0x00000713u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT0_257 = 0x00000714u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_0 = 0x00000715u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_1 = 0x00000716u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_256 = 0x00000717u, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_257 = 0x00000718u, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_LINE_0 = 0x00000719u, /* tcpwm[0].tr_line[0] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_LINE_1 = 0x0000071Au, /* tcpwm[0].tr_line[1] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_LINE_COMPL_0 = 0x0000071Bu, /* tcpwm[0].tr_line_compl[0] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_LINE_COMPL_1 = 0x0000071Cu, /* tcpwm[0].tr_line_compl[1] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_LINE_256 = 0x0000071Du, /* tcpwm[0].tr_line[256] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_LINE_257 = 0x0000071Eu, /* tcpwm[0].tr_line[257] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_LINE_COMPL_256 = 0x0000071Fu, /* tcpwm[0].tr_line_compl[256] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_LINE_COMPL_257 = 0x00000720u, /* tcpwm[0].tr_line_compl[257] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT0     = 0x00000721u, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT1     = 0x00000722u, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT2     = 0x00000723u, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT3     = 0x00000724u, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT4     = 0x00000725u, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT5     = 0x00000726u, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT6     = 0x00000727u, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT7     = 0x00000728u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT8     = 0x00000729u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT9     = 0x0000072Au, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT10    = 0x0000072Bu, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT11    = 0x0000072Cu, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT12    = 0x0000072Du, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT13    = 0x0000072Eu, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT14    = 0x0000072Fu, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT15    = 0x00000730u, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT16    = 0x00000731u, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT17    = 0x00000732u, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT18    = 0x00000733u, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT19    = 0x00000734u, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT20    = 0x00000735u, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT21    = 0x00000736u, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT22    = 0x00000737u, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT23    = 0x00000738u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT24    = 0x00000739u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT25    = 0x0000073Au, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT26    = 0x0000073Bu, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT27    = 0x0000073Cu, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT28    = 0x0000073Du, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT29    = 0x0000073Eu, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT30    = 0x0000073Fu, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT31    = 0x00000740u, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT32    = 0x00000741u, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT33    = 0x00000742u, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT34    = 0x00000743u, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT35    = 0x00000744u, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT36    = 0x00000745u, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT37    = 0x00000746u, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT38    = 0x00000747u, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT39    = 0x00000748u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT40    = 0x00000749u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT41    = 0x0000074Au, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT42    = 0x0000074Bu, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT43    = 0x0000074Cu, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT44    = 0x0000074Du, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT45    = 0x0000074Eu, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT46    = 0x0000074Fu, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT47    = 0x00000750u, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT48    = 0x00000751u, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT49    = 0x00000752u, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT50    = 0x00000753u, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT51    = 0x00000754u, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT52    = 0x00000755u, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT53    = 0x00000756u, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT54    = 0x00000757u, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT55    = 0x00000758u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT56    = 0x00000759u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT57    = 0x0000075Au, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT58    = 0x0000075Bu, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT59    = 0x0000075Cu, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_7_SCB_I2C_SCL0      = 0x0000075Du, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX0           = 0x0000075Eu, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX0           = 0x0000075Fu, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_7_SCB_TGS_RELOAD00  = 0x00000760u, /* scb[0].tr_tgs_reload[0] */
    TRIG_IN_MUX_7_SCB_TGS_STOP00    = 0x00000761u, /* scb[0].tr_tgs_stop[0] */
    TRIG_IN_MUX_7_SCB_TGS_GATED00   = 0x00000762u, /* scb[0].tr_tgs_gated[0] */
    TRIG_IN_MUX_7_SCB_I2C_SCL1      = 0x00000763u, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX1           = 0x00000764u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX1           = 0x00000765u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_7_SCB_TGS_RELOAD10  = 0x00000766u, /* scb[1].tr_tgs_reload[0] */
    TRIG_IN_MUX_7_SCB_TGS_STOP10    = 0x00000767u, /* scb[1].tr_tgs_stop[0] */
    TRIG_IN_MUX_7_SCB_TGS_GATED10   = 0x00000768u, /* scb[1].tr_tgs_gated[0] */
    TRIG_IN_MUX_7_SCB_I2C_SCL2      = 0x00000769u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX2           = 0x0000076Au, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX2           = 0x0000076Bu, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_7_SCB_TGS_RELOAD20  = 0x0000076Cu, /* scb[2].tr_tgs_reload[0] */
    TRIG_IN_MUX_7_SCB_TGS_STOP20    = 0x0000076Du, /* scb[2].tr_tgs_stop[0] */
    TRIG_IN_MUX_7_SCB_TGS_GATED20   = 0x0000076Eu, /* scb[2].tr_tgs_gated[0] */
    TRIG_IN_MUX_7_SCB_I2C_SCL3      = 0x0000076Fu, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX3           = 0x00000770u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX3           = 0x00000771u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_7_SCB_TGS_RELOAD30  = 0x00000772u, /* scb[3].tr_tgs_reload[0] */
    TRIG_IN_MUX_7_SCB_TGS_STOP30    = 0x00000773u, /* scb[3].tr_tgs_stop[0] */
    TRIG_IN_MUX_7_SCB_TGS_GATED30   = 0x00000774u, /* scb[3].tr_tgs_gated[0] */
    TRIG_IN_MUX_7_SCB_I2C_SCL4      = 0x00000775u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX4           = 0x00000776u, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX4           = 0x00000777u, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_7_SCB_TGS_RELOAD40  = 0x00000778u, /* scb[4].tr_tgs_reload[0] */
    TRIG_IN_MUX_7_SCB_TGS_STOP40    = 0x00000779u, /* scb[4].tr_tgs_stop[0] */
    TRIG_IN_MUX_7_SCB_TGS_GATED40   = 0x0000077Au, /* scb[4].tr_tgs_gated[0] */
    TRIG_IN_MUX_7_SCB_I2C_SCL5      = 0x0000077Bu, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX5           = 0x0000077Cu, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX5           = 0x0000077Du, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_7_SCB_TGS_RELOAD50  = 0x0000077Eu, /* scb[5].tr_tgs_reload[0] */
    TRIG_IN_MUX_7_SCB_TGS_STOP50    = 0x0000077Fu, /* scb[5].tr_tgs_stop[0] */
    TRIG_IN_MUX_7_SCB_TGS_GATED50   = 0x00000780u, /* scb[5].tr_tgs_gated[0] */
    TRIG_IN_MUX_7_SCB_I2C_SCL6      = 0x00000781u, /* scb[6].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX6           = 0x00000782u, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX6           = 0x00000783u, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_7_SCB_TGS_RELOAD60  = 0x00000784u, /* scb[6].tr_tgs_reload[0] */
    TRIG_IN_MUX_7_SCB_TGS_STOP60    = 0x00000785u, /* scb[6].tr_tgs_stop[0] */
    TRIG_IN_MUX_7_SCB_TGS_GATED60   = 0x00000786u, /* scb[6].tr_tgs_gated[0] */
    TRIG_IN_MUX_7_CTI_TR_OUT0       = 0x00000787u, /* debug600.cti_tr_out[0] */
    TRIG_IN_MUX_7_CTI_TR_OUT1       = 0x00000788u, /* debug600.cti_tr_out[1] */
    TRIG_IN_MUX_7_CANFD_TT_TR_OUT0  = 0x00000789u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_7_CANFD_TT_TR_OUT1  = 0x0000078Au, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_7_LPCOMP_DSI_COMP0  = 0x0000078Bu, /* lpcomp.dsi_comp0 */
    TRIG_IN_MUX_7_LPCOMP_DSI_COMP1  = 0x0000078Cu, /* lpcomp.dsi_comp1 */
    TRIG_IN_MUX_7_CPUSS_TR_FAULT0   = 0x0000078Du, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_7_TRNG_BITSTREAM    = 0x0000078Eu /* cryptolite.tr_trng_bitstream */
} en_trig_input_ppca_t;

/* Trigger Group Outputs */
/* Trigger Output Group 0 - P-DMA0 Request Assignments */
typedef enum
{
    TRIG_OUT_MUX_0_PDMA0_TR_IN0     = 0x40000000u, /* cpuss.dw0_tr_in[0] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN1     = 0x40000001u, /* cpuss.dw0_tr_in[1] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN2     = 0x40000002u, /* cpuss.dw0_tr_in[2] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN3     = 0x40000003u, /* cpuss.dw0_tr_in[3] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN4     = 0x40000004u, /* cpuss.dw0_tr_in[4] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN5     = 0x40000005u, /* cpuss.dw0_tr_in[5] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN6     = 0x40000006u, /* cpuss.dw0_tr_in[6] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN7     = 0x40000007u, /* cpuss.dw0_tr_in[7] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN8     = 0x40000008u, /* cpuss.dw0_tr_in[8] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN9     = 0x40000009u, /* cpuss.dw0_tr_in[9] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN10    = 0x4000000Au, /* cpuss.dw0_tr_in[10] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN11    = 0x4000000Bu, /* cpuss.dw0_tr_in[11] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN12    = 0x4000000Cu, /* cpuss.dw0_tr_in[12] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN13    = 0x4000000Du, /* cpuss.dw0_tr_in[13] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN14    = 0x4000000Eu, /* cpuss.dw0_tr_in[14] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN15    = 0x4000000Fu /* cpuss.dw0_tr_in[15] */
} en_trig_output_pdma0_tr_t;

/* Trigger Output Group 1 - HSIOM0 trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT0 = 0x40000100u, /* ioss.peri_tr_io_output_out[0] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT1 = 0x40000101u, /* ioss.peri_tr_io_output_out[1] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT2 = 0x40000102u, /* ioss.peri_tr_io_output_out[2] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT3 = 0x40000103u, /* ioss.peri_tr_io_output_out[3] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT4 = 0x40000104u, /* ioss.peri_tr_io_output_out[4] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT5 = 0x40000105u, /* ioss.peri_tr_io_output_out[5] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT6 = 0x40000106u, /* ioss.peri_tr_io_output_out[6] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT7 = 0x40000107u, /* ioss.peri_tr_io_output_out[7] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT8 = 0x40000108u, /* ioss.peri_tr_io_output_out[8] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT9 = 0x40000109u, /* ioss.peri_tr_io_output_out[9] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT10 = 0x4000010Au, /* ioss.peri_tr_io_output_out[10] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT11 = 0x4000010Bu, /* ioss.peri_tr_io_output_out[11] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT12 = 0x4000010Cu, /* ioss.peri_tr_io_output_out[12] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT13 = 0x4000010Du, /* ioss.peri_tr_io_output_out[13] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT14 = 0x4000010Eu, /* ioss.peri_tr_io_output_out[14] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT15 = 0x4000010Fu, /* ioss.peri_tr_io_output_out[15] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT16 = 0x40000110u, /* ioss.peri_tr_io_output_out[16] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT17 = 0x40000111u, /* ioss.peri_tr_io_output_out[17] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT18 = 0x40000112u, /* ioss.peri_tr_io_output_out[18] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT19 = 0x40000113u, /* ioss.peri_tr_io_output_out[19] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT20 = 0x40000114u, /* ioss.peri_tr_io_output_out[20] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT21 = 0x40000115u, /* ioss.peri_tr_io_output_out[21] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT22 = 0x40000116u, /* ioss.peri_tr_io_output_out[22] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT23 = 0x40000117u, /* ioss.peri_tr_io_output_out[23] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT24 = 0x40000118u, /* ioss.peri_tr_io_output_out[24] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT25 = 0x40000119u, /* ioss.peri_tr_io_output_out[25] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT26 = 0x4000011Au, /* ioss.peri_tr_io_output_out[26] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT27 = 0x4000011Bu, /* ioss.peri_tr_io_output_out[27] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT28 = 0x4000011Cu, /* ioss.peri_tr_io_output_out[28] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT29 = 0x4000011Du, /* ioss.peri_tr_io_output_out[29] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT30 = 0x4000011Eu, /* ioss.peri_tr_io_output_out[30] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT31 = 0x4000011Fu, /* ioss.peri_tr_io_output_out[31] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT32 = 0x40000120u, /* ioss.peri_tr_io_output_out[32] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT33 = 0x40000121u, /* ioss.peri_tr_io_output_out[33] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT34 = 0x40000122u, /* ioss.peri_tr_io_output_out[34] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT35 = 0x40000123u, /* ioss.peri_tr_io_output_out[35] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT36 = 0x40000124u, /* ioss.peri_tr_io_output_out[36] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT37 = 0x40000125u, /* ioss.peri_tr_io_output_out[37] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT38 = 0x40000126u, /* ioss.peri_tr_io_output_out[38] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT39 = 0x40000127u, /* ioss.peri_tr_io_output_out[39] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT40 = 0x40000128u, /* ioss.peri_tr_io_output_out[40] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT41 = 0x40000129u, /* ioss.peri_tr_io_output_out[41] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT42 = 0x4000012Au, /* ioss.peri_tr_io_output_out[42] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT43 = 0x4000012Bu, /* ioss.peri_tr_io_output_out[43] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT44 = 0x4000012Cu, /* ioss.peri_tr_io_output_out[44] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT45 = 0x4000012Du, /* ioss.peri_tr_io_output_out[45] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT46 = 0x4000012Eu, /* ioss.peri_tr_io_output_out[46] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT47 = 0x4000012Fu, /* ioss.peri_tr_io_output_out[47] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT48 = 0x40000130u, /* ioss.peri_tr_io_output_out[48] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT49 = 0x40000131u, /* ioss.peri_tr_io_output_out[49] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT50 = 0x40000132u, /* ioss.peri_tr_io_output_out[50] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT51 = 0x40000133u, /* ioss.peri_tr_io_output_out[51] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT52 = 0x40000134u, /* ioss.peri_tr_io_output_out[52] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT53 = 0x40000135u, /* ioss.peri_tr_io_output_out[53] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT54 = 0x40000136u, /* ioss.peri_tr_io_output_out[54] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT55 = 0x40000137u, /* ioss.peri_tr_io_output_out[55] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT56 = 0x40000138u, /* ioss.peri_tr_io_output_out[56] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT57 = 0x40000139u, /* ioss.peri_tr_io_output_out[57] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT58 = 0x4000013Au, /* ioss.peri_tr_io_output_out[58] */
    TRIG_OUT_MUX_1_HSIOM_TR_IO_OUTPUT59 = 0x4000013Bu /* ioss.peri_tr_io_output_out[59] */
} en_trig_output_hsiom0_t;

/* Trigger Output Group 2 - HSIOM1 trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT60 = 0x40000200u, /* ioss.peri_tr_io_output_out[60] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT61 = 0x40000201u, /* ioss.peri_tr_io_output_out[61] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT62 = 0x40000202u, /* ioss.peri_tr_io_output_out[62] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT63 = 0x40000203u, /* ioss.peri_tr_io_output_out[63] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT64 = 0x40000204u, /* ioss.peri_tr_io_output_out[64] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT65 = 0x40000205u, /* ioss.peri_tr_io_output_out[65] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT66 = 0x40000206u, /* ioss.peri_tr_io_output_out[66] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT67 = 0x40000207u, /* ioss.peri_tr_io_output_out[67] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT68 = 0x40000208u, /* ioss.peri_tr_io_output_out[68] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT69 = 0x40000209u, /* ioss.peri_tr_io_output_out[69] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT70 = 0x4000020Au, /* ioss.peri_tr_io_output_out[70] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT71 = 0x4000020Bu, /* ioss.peri_tr_io_output_out[71] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT72 = 0x4000020Cu, /* ioss.peri_tr_io_output_out[72] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT73 = 0x4000020Du, /* ioss.peri_tr_io_output_out[73] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT74 = 0x4000020Eu, /* ioss.peri_tr_io_output_out[74] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT75 = 0x4000020Fu, /* ioss.peri_tr_io_output_out[75] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT76 = 0x40000210u, /* ioss.peri_tr_io_output_out[76] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT77 = 0x40000211u, /* ioss.peri_tr_io_output_out[77] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT78 = 0x40000212u, /* ioss.peri_tr_io_output_out[78] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT79 = 0x40000213u, /* ioss.peri_tr_io_output_out[79] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT80 = 0x40000214u, /* ioss.peri_tr_io_output_out[80] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT81 = 0x40000215u, /* ioss.peri_tr_io_output_out[81] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT82 = 0x40000216u, /* ioss.peri_tr_io_output_out[82] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT83 = 0x40000217u, /* ioss.peri_tr_io_output_out[83] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT84 = 0x40000218u, /* ioss.peri_tr_io_output_out[84] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT85 = 0x40000219u, /* ioss.peri_tr_io_output_out[85] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT86 = 0x4000021Au, /* ioss.peri_tr_io_output_out[86] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT87 = 0x4000021Bu, /* ioss.peri_tr_io_output_out[87] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT88 = 0x4000021Cu, /* ioss.peri_tr_io_output_out[88] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT89 = 0x4000021Du, /* ioss.peri_tr_io_output_out[89] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT90 = 0x4000021Eu, /* ioss.peri_tr_io_output_out[90] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT91 = 0x4000021Fu, /* ioss.peri_tr_io_output_out[91] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT92 = 0x40000220u, /* ioss.peri_tr_io_output_out[92] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT93 = 0x40000221u, /* ioss.peri_tr_io_output_out[93] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT94 = 0x40000222u, /* ioss.peri_tr_io_output_out[94] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT95 = 0x40000223u, /* ioss.peri_tr_io_output_out[95] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT96 = 0x40000224u, /* ioss.peri_tr_io_output_out[96] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT97 = 0x40000225u, /* ioss.peri_tr_io_output_out[97] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT98 = 0x40000226u, /* ioss.peri_tr_io_output_out[98] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT99 = 0x40000227u, /* ioss.peri_tr_io_output_out[99] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT100 = 0x40000228u, /* ioss.peri_tr_io_output_out[100] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT101 = 0x40000229u, /* ioss.peri_tr_io_output_out[101] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT102 = 0x4000022Au, /* ioss.peri_tr_io_output_out[102] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT103 = 0x4000022Bu, /* ioss.peri_tr_io_output_out[103] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT104 = 0x4000022Cu, /* ioss.peri_tr_io_output_out[104] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT105 = 0x4000022Du, /* ioss.peri_tr_io_output_out[105] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT106 = 0x4000022Eu, /* ioss.peri_tr_io_output_out[106] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT107 = 0x4000022Fu, /* ioss.peri_tr_io_output_out[107] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT108 = 0x40000230u, /* ioss.peri_tr_io_output_out[108] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT109 = 0x40000231u, /* ioss.peri_tr_io_output_out[109] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT110 = 0x40000232u, /* ioss.peri_tr_io_output_out[110] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT111 = 0x40000233u, /* ioss.peri_tr_io_output_out[111] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT112 = 0x40000234u, /* ioss.peri_tr_io_output_out[112] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT113 = 0x40000235u, /* ioss.peri_tr_io_output_out[113] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT114 = 0x40000236u, /* ioss.peri_tr_io_output_out[114] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT115 = 0x40000237u, /* ioss.peri_tr_io_output_out[115] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT116 = 0x40000238u, /* ioss.peri_tr_io_output_out[116] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT117 = 0x40000239u, /* ioss.peri_tr_io_output_out[117] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT118 = 0x4000023Au, /* ioss.peri_tr_io_output_out[118] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT119 = 0x4000023Bu /* ioss.peri_tr_io_output_out[119] */
} en_trig_output_hsiom1_t;

/* Trigger Output Group 3 - CPUSS Debug  multiplexer */
typedef enum
{
    TRIG_OUT_MUX_3_CPUSS_CTI_TR_IN0 = 0x40000300u, /* debug600.cti_tr_in[0] */
    TRIG_OUT_MUX_3_CPUSS_CTI_TR_IN1 = 0x40000301u /* debug600.cti_tr_in[1] */
} en_trig_output_cpuss_cti_t;

/* Trigger Output Group 4 - CAN TT Synchronization triggers */
typedef enum
{
    TRIG_OUT_MUX_4_CAN_TT_TR_IN0    = 0x40000400u, /* canfd[0].tr_evt_swt_in[0] */
    TRIG_OUT_MUX_4_CAN_TT_TR_IN1    = 0x40000401u /* canfd[0].tr_evt_swt_in[1] */
} en_trig_output_cantt_t;

/* Trigger Output Group 5 - PERI Freeze trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_5_PERI_DEBUG_FREEZE_TR_IN = 0x40000500u, /* peri.tr_dbg_freeze */
    TRIG_OUT_MUX_5_TCPWM_DEBUG_FREEZE_TR_IN = 0x40000501u, /* tcpwm[0].tr_debug_freeze */
    TRIG_OUT_MUX_5_PPCA_DEBUG_FREEZE_TR_IN = 0x40000502u /* ppca.tr_debug_freeze */
} en_trig_output_peri_freeze_t;

/* Trigger Output Group 6 - TCPWM1 trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_6_TCPWM0_TR_ALL_IN0 = 0x40000600u, /* tcpwm[0].tr_all_cnt_in[0] */
    TRIG_OUT_MUX_6_TCPWM0_TR_ALL_IN1 = 0x40000601u, /* tcpwm[0].tr_all_cnt_in[1] */
    TRIG_OUT_MUX_6_TCPWM0_TR_ALL_IN2 = 0x40000602u, /* tcpwm[0].tr_all_cnt_in[2] */
    TRIG_OUT_MUX_6_TCPWM0_TR_ALL_IN3 = 0x40000603u, /* tcpwm[0].tr_all_cnt_in[3] */
    TRIG_OUT_MUX_6_TCPWM0_TR_ALL_IN4 = 0x40000604u, /* tcpwm[0].tr_all_cnt_in[4] */
    TRIG_OUT_MUX_6_TCPWM0_TR_ALL_IN5 = 0x40000605u, /* tcpwm[0].tr_all_cnt_in[5] */
    TRIG_OUT_MUX_6_TCPWM0_TR_ONE_IN0 = 0x40000606u, /* tcpwm[0].tr_one_cnt_in[0] */
    TRIG_OUT_MUX_6_TCPWM0_TR_ONE_IN1 = 0x40000607u, /* tcpwm[0].tr_one_cnt_in[1] */
    TRIG_OUT_MUX_6_TCPWM0_TR_ONE_IN2 = 0x40000608u, /* tcpwm[0].tr_one_cnt_in[256] */
    TRIG_OUT_MUX_6_TCPWM0_TR_ONE_IN3 = 0x40000609u /* tcpwm[0].tr_one_cnt_in[257] */
} en_trig_output_tcpwm0_t;

/* Trigger Output Group 7 - PPSS trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_7_PPCA_TR_IN0      = 0x40000700u, /* ppca.tr_ppssin[0] */
    TRIG_OUT_MUX_7_PPCA_TR_IN1      = 0x40000701u, /* ppca.tr_ppssin[1] */
    TRIG_OUT_MUX_7_PPCA_TR_IN2      = 0x40000702u, /* ppca.tr_ppssin[2] */
    TRIG_OUT_MUX_7_PPCA_TR_IN3      = 0x40000703u, /* ppca.tr_ppssin[3] */
    TRIG_OUT_MUX_7_PPCA_TR_IN4      = 0x40000704u, /* ppca.tr_ppssin[4] */
    TRIG_OUT_MUX_7_PPCA_TR_IN5      = 0x40000705u, /* ppca.tr_ppssin[5] */
    TRIG_OUT_MUX_7_PPCA_TR_IN6      = 0x40000706u, /* ppca.tr_ppssin[6] */
    TRIG_OUT_MUX_7_PPCA_TR_IN7      = 0x40000707u, /* ppca.tr_ppssin[7] */
    TRIG_OUT_MUX_7_PPCA_TR_IN8      = 0x40000708u, /* ppca.tr_ppssin[8] */
    TRIG_OUT_MUX_7_PPCA_TR_IN9      = 0x40000709u, /* ppca.tr_ppssin[9] */
    TRIG_OUT_MUX_7_PPCA_TR_IN10     = 0x4000070Au, /* ppca.tr_ppssin[10] */
    TRIG_OUT_MUX_7_PPCA_TR_IN11     = 0x4000070Bu, /* ppca.tr_ppssin[11] */
    TRIG_OUT_MUX_7_PPCA_TR_IN12     = 0x4000070Cu, /* ppca.tr_ppssin[12] */
    TRIG_OUT_MUX_7_PPCA_TR_IN13     = 0x4000070Du, /* ppca.tr_ppssin[13] */
    TRIG_OUT_MUX_7_PPCA_TR_IN14     = 0x4000070Eu, /* ppca.tr_ppssin[14] */
    TRIG_OUT_MUX_7_PPCA_TR_IN15     = 0x4000070Fu, /* ppca.tr_ppssin[15] */
    TRIG_OUT_MUX_7_PPCA_TR_IN16     = 0x40000710u, /* ppca.tr_ppssin[16] */
    TRIG_OUT_MUX_7_PPCA_TR_IN17     = 0x40000711u, /* ppca.tr_ppssin[17] */
    TRIG_OUT_MUX_7_PPCA_TR_IN18     = 0x40000712u, /* ppca.tr_ppssin[18] */
    TRIG_OUT_MUX_7_PPCA_TR_IN19     = 0x40000713u, /* ppca.tr_ppssin[19] */
    TRIG_OUT_MUX_7_PPCA_TR_IN20     = 0x40000714u, /* ppca.tr_ppssin[20] */
    TRIG_OUT_MUX_7_PPCA_TR_IN21     = 0x40000715u, /* ppca.tr_ppssin[21] */
    TRIG_OUT_MUX_7_PPCA_TR_IN22     = 0x40000716u, /* ppca.tr_ppssin[22] */
    TRIG_OUT_MUX_7_PPCA_TR_IN23     = 0x40000717u, /* ppca.tr_ppssin[23] */
    TRIG_OUT_MUX_7_PPCA_TR_IN24     = 0x40000718u, /* ppca.tr_ppssin[24] */
    TRIG_OUT_MUX_7_PPCA_TR_IN25     = 0x40000719u, /* ppca.tr_ppssin[25] */
    TRIG_OUT_MUX_7_PPCA_TR_IN26     = 0x4000071Au, /* ppca.tr_ppssin[26] */
    TRIG_OUT_MUX_7_PPCA_TR_IN27     = 0x4000071Bu, /* ppca.tr_ppssin[27] */
    TRIG_OUT_MUX_7_PPCA_TR_IN28     = 0x4000071Cu, /* ppca.tr_ppssin[28] */
    TRIG_OUT_MUX_7_PPCA_TR_IN29     = 0x4000071Du, /* ppca.tr_ppssin[29] */
    TRIG_OUT_MUX_7_PPCA_TR_IN30     = 0x4000071Eu, /* ppca.tr_ppssin[30] */
    TRIG_OUT_MUX_7_PPCA_TR_IN31     = 0x4000071Fu, /* ppca.tr_ppssin[31] */
    TRIG_OUT_MUX_7_PPCA_TR_IN32     = 0x40000720u, /* ppca.tr_ppssin[32] */
    TRIG_OUT_MUX_7_PPCA_TR_IN33     = 0x40000721u, /* ppca.tr_ppssin[33] */
    TRIG_OUT_MUX_7_PPCA_TR_IN34     = 0x40000722u, /* ppca.tr_ppssin[34] */
    TRIG_OUT_MUX_7_PPCA_TR_IN35     = 0x40000723u, /* ppca.tr_ppssin[35] */
    TRIG_OUT_MUX_7_PPCA_TR_IN36     = 0x40000724u, /* ppca.tr_ppssin[36] */
    TRIG_OUT_MUX_7_PPCA_TR_IN37     = 0x40000725u, /* ppca.tr_ppssin[37] */
    TRIG_OUT_MUX_7_PPCA_TR_IN38     = 0x40000726u, /* ppca.tr_ppssin[38] */
    TRIG_OUT_MUX_7_PPCA_TR_IN39     = 0x40000727u, /* ppca.tr_ppssin[39] */
    TRIG_OUT_MUX_7_PPCA_TR_IN40     = 0x40000728u, /* ppca.tr_ppssin[40] */
    TRIG_OUT_MUX_7_PPCA_TR_IN41     = 0x40000729u, /* ppca.tr_ppssin[41] */
    TRIG_OUT_MUX_7_PPCA_TR_IN42     = 0x4000072Au, /* ppca.tr_ppssin[42] */
    TRIG_OUT_MUX_7_PPCA_TR_IN43     = 0x4000072Bu, /* ppca.tr_ppssin[43] */
    TRIG_OUT_MUX_7_PPCA_TR_IN44     = 0x4000072Cu, /* ppca.tr_ppssin[44] */
    TRIG_OUT_MUX_7_PPCA_TR_IN45     = 0x4000072Du, /* ppca.tr_ppssin[45] */
    TRIG_OUT_MUX_7_PPCA_TR_IN46     = 0x4000072Eu, /* ppca.tr_ppssin[46] */
    TRIG_OUT_MUX_7_PPCA_TR_IN47     = 0x4000072Fu, /* ppca.tr_ppssin[47] */
    TRIG_OUT_MUX_7_PPCA_TR_IN48     = 0x40000730u, /* ppca.tr_ppssin[48] */
    TRIG_OUT_MUX_7_PPCA_TR_IN49     = 0x40000731u, /* ppca.tr_ppssin[49] */
    TRIG_OUT_MUX_7_PPCA_TR_IN50     = 0x40000732u, /* ppca.tr_ppssin[50] */
    TRIG_OUT_MUX_7_PPCA_TR_IN51     = 0x40000733u, /* ppca.tr_ppssin[51] */
    TRIG_OUT_MUX_7_PPCA_TR_IN52     = 0x40000734u, /* ppca.tr_ppssin[52] */
    TRIG_OUT_MUX_7_PPCA_TR_IN53     = 0x40000735u, /* ppca.tr_ppssin[53] */
    TRIG_OUT_MUX_7_PPCA_TR_IN54     = 0x40000736u, /* ppca.tr_ppssin[54] */
    TRIG_OUT_MUX_7_PPCA_TR_IN55     = 0x40000737u, /* ppca.tr_ppssin[55] */
    TRIG_OUT_MUX_7_PPCA_TR_IN56     = 0x40000738u, /* ppca.tr_ppssin[56] */
    TRIG_OUT_MUX_7_PPCA_TR_IN57     = 0x40000739u, /* ppca.tr_ppssin[57] */
    TRIG_OUT_MUX_7_PPCA_TR_IN58     = 0x4000073Au, /* ppca.tr_ppssin[58] */
    TRIG_OUT_MUX_7_PPCA_TR_IN59     = 0x4000073Bu, /* ppca.tr_ppssin[59] */
    TRIG_OUT_MUX_7_PPCA_TR_IN60     = 0x4000073Cu, /* ppca.tr_ppssin[60] */
    TRIG_OUT_MUX_7_PPCA_TR_IN61     = 0x4000073Du, /* ppca.tr_ppssin[61] */
    TRIG_OUT_MUX_7_PPCA_TR_IN62     = 0x4000073Eu, /* ppca.tr_ppssin[62] */
    TRIG_OUT_MUX_7_PPCA_TR_IN63     = 0x4000073Fu /* ppca.tr_ppssin[63] */
} en_trig_output_ppca_t;

/* Trigger Output Group 0 - Acknowledge dma request triggers from DW0 to CAN (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_0_PDMA0_TR_OUT0_ACK_TO_CAN_0 = 0x40001000u, /* From cpuss.dw0_tr_out[6] to canfd[0].tr_dbg_dma_ack[0] */
    TRIG_OUT_1TO1_0_PDMA0_TR_OUT0_ACK_TO_CAN_1 = 0x40001001u /* From cpuss.dw0_tr_out[8] to canfd[0].tr_dbg_dma_ack[1] */
} en_trig_output_1to1_can0_dw_ack_t;

/* Level or edge detection setting for a trigger mux */
typedef enum
{
    /* The trigger is a simple level output */
    TRIGGER_TYPE_LEVEL = 0u,
    /* The trigger is synchronized to the consumer blocks clock
       and a two cycle pulse is generated on this clock */
    TRIGGER_TYPE_EDGE = 1u
} en_trig_type_t;

/* Trigger Type Defines */
/* CANFD Trigger Types */
#define TRIGGER_TYPE_CANFD_TR_DBG_DMA_ACK       TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CANFD_TR_DBG_DMA_REQ       TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_EVT_SWT_IN        TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CANFD_TR_FIFO0             TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_FIFO1             TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_TMP_RTP_OUT       TRIGGER_TYPE_EDGE
/* CPUSS Trigger Types */
#define TRIGGER_TYPE_CPUSS_DW0_TR_IN__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DW0_TR_IN__EDGE      TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW0_TR_OUT           TRIGGER_TYPE_EDGE
/* CRYPTOLITE Trigger Types */
#define TRIGGER_TYPE_CRYPTOLITE_TR_TRNG_BITSTREAM TRIGGER_TYPE_LEVEL
/* LPCOMP Trigger Types */
#define TRIGGER_TYPE_LPCOMP_DSI_COMP0           TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_LPCOMP_DSI_COMP1           TRIGGER_TYPE_LEVEL
/* PERI Trigger Types */
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__LEVEL    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__EDGE     TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__LEVEL   TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__EDGE    TRIGGER_TYPE_EDGE
/* PPCA Trigger Types */
#define TRIGGER_TYPE_PPCA_DMAREQ_PPSS           TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PPCA_TR_PPSSIN__LEVEL      TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PPCA_TR_PPSSIN__EDGE       TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PPCA_TR_PPSSOUT__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PPCA_TR_PPSSOUT__EDGE      TRIGGER_TYPE_EDGE
/* SCB Trigger Types */
#define TRIGGER_TYPE_SCB_TR_I2C_SCL_FILTERED    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_RX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_TGS_GATED           TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_TGS_RELOAD          TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_TGS_STOP            TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_TX_REQ              TRIGGER_TYPE_LEVEL
/* TCPWM Trigger Types */
#define TRIGGER_TYPE_TCPWM_TR_DEBUG_FREEZE      TRIGGER_TYPE_LEVEL

/* Fault connections */
typedef enum
{
    PERI_PERI_MS0_PPC_VIO           = 0x0000u,
    PERI_PERI_MS1_PPC_VIO           = 0x0001u,
    PERI_PERI_PPC_PC_MASK_VIO       = 0x0002u,
    PERI_PERI_GP1_TIMEOUT_VIO       = 0x0003u,
    PERI_PERI_GP2_TIMEOUT_VIO       = 0x0004u,
    PERI_PERI_GP3_TIMEOUT_VIO       = 0x0005u,
    PERI_PERI_GP4_TIMEOUT_VIO       = 0x0006u,
    PERI_PERI_GP5_TIMEOUT_VIO       = 0x0007u,
    PERI_PERI_GP0_AHB_VIO           = 0x0008u,
    PERI_PERI_GP1_AHB_VIO           = 0x0009u,
    PERI_PERI_GP2_AHB_VIO           = 0x000Au,
    PERI_PERI_GP3_AHB_VIO           = 0x000Bu,
    PERI_PERI_GP4_AHB_VIO           = 0x000Cu,
    PERI_PERI_GP5_AHB_VIO           = 0x000Du,
    CPUSS_RAMC0_MPC_FAULT_MMIO      = 0x000Eu,
    CPUSS_RAMC1_MPC_FAULT_MMIO      = 0x000Fu,
    CPUSS_EXP_MS_AHB_ERROR_MMIO     = 0x0010u,
    CPUSS_PROMC_MPC_FAULT_MMIO      = 0x0011u,
    CPUSS_RAMC0_C_ECC_MMIO          = 0x0012u,
    CPUSS_RAMC0_NC_ECC_MMIO         = 0x0013u,
    CPUSS_RAMC1_C_ECC_MMIO          = 0x0014u,
    CPUSS_RAMC1_NC_ECC_MMIO         = 0x0015u,
    CPUSS_FLASHC_MPC_FAULT          = 0x0016u,
    CPUSS_FLASHC_BUS_ACCESS_FAULT   = 0x0017u,
    CPUSS_FLASHC_MAIN_C_ECC_MMIO    = 0x0018u,
    CPUSS_FLASHC_MAIN_NC_ECC_MMIO   = 0x0019u,
    CPUSS_FLASHC_FM_CTL_FAULT       = 0x001Au,
    CPUSS_FLASHC_FM_R_Q_FAULT       = 0x001Bu,
    CPUSS_FLASHC_FLASH_CTL_FAULT    = 0x001Cu,
    CPUSS_FLASHC_ADDR_HOLE_FAULT    = 0x001Du,
    CPUSS_FLASHC_LOCK_FAULT         = 0x001Eu,
    SRSS_FAULT_CSV                  = 0x001Fu,
    SRSS_FAULT_SSV                  = 0x0020u,
    PPCA_PPSS_RAMC0_NC_ECC_MMIO     = 0x0021u,
    PPCA_PPSS_RAMC1_NC_ECC_MMIO     = 0x0022u,
    PPCA_PPSS_RAMC2_NC_ECC_MMIO     = 0x0023u,
    PPCA_PPSS_RAMC3_NC_ECC_MMIO     = 0x0024u,
    PPCA_PPSS_RAMC4_NC_ECC_MMIO     = 0x0025u,
    PPCA_PPSS_C0_HRESP_ERROR_MMIO   = 0x0026u,
    PPCA_PPSS_RAMC0_C_ECC_MMIO      = 0x0027u,
    PPCA_PPSS_RAMC1_C_ECC_MMIO      = 0x0028u,
    PPCA_PPSS_RAMC2_C_ECC_MMIO      = 0x0029u,
    PPCA_PPSS_RAMC3_C_ECC_MMIO      = 0x002Au,
    PPCA_PPSS_RAMC4_C_ECC_MMIO      = 0x002Bu,
    PPCA_PPSS_C1_HRESP_ERROR_MMIO   = 0x002Cu,
    SVGS_FAULT                      = 0x002Du,
    MXAES_FAULT                     = 0x002Eu,
    CY_SYSFAULT_NO_FAULT            = 0x002Fu
} en_sysfault_source_t;

/* Include IP definitions */
#include "ip/cyip_sflash_psc3_p8.h"
#include "ip/cyip_peri_v2.h"
#include "ip/cyip_ppc_v2.h"
#include "ip/cyip_peri_pclk_v2.h"
#include "ip/cyip_ramc_ppu_v2_1.h"
#include "ip/cyip_icache_v2_1.h"
#include "ip/cyip_cpuss_ppu_v2_1.h"
#include "ip/cyip_ramc_v2.h"
#include "ip/cyip_promc_v2.h"
#include "ip/cyip_flashc.h"
#include "ip/cyip_mxcm33_v2_1.h"
#include "ip/cyip_dw.h"
#include "ip/cyip_cpuss_v2_1.h"
#include "ip/cyip_ms_ctl_2_1_v2_1.h"
#include "ip/cyip_cpuss_sl_ctl_v2_1.h"
#include "ip/cyip_ipc.h"
#include "ip/cyip_fault.h"
#include "ip/cyip_srss_v1_3.h"
#include "ip/cyip_pwrmode_v1_3.h"
#include "ip/cyip_backup_v1_3.h"
#include "ip/cyip_cryptolite_v1_2.h"
#include "ip/cyip_mxwound.h"
#include "ip/cyip_debug600_v1_2.h"
#include "ip/cyip_svgs.h"
#include "ip/cyip_mxaes_v2.h"
#include "ip/cyip_hsiom.h"
#include "ip/cyip_gpio.h"
#include "ip/cyip_lpcomp_v2.h"
#include "ip/cyip_tcpwm_v1_1.h"
#include "ip/cyip_efuse_v3_1.h"
#include "ip/cyip_canfd_v3.h"
#include "ip/cyip_scb_v4_4.h"
#include "ip/cyip_ppca.h"
#include "ip/cyip_cm33.h"

/* Parameter Defines */
/* Number of TTCAN instances */
#define CANFD_CAN_NR                    2u
/* ECC logic present or not */
#define CANFD_ECC_PRESENT               0u
/* address included in ECC logic or not */
#define CANFD_ECC_ADDR_PRESENT          0u
/* Time Stamp counter present or not (required for instance 0, otherwise not
   allowed) */
#define CANFD_TS_PRESENT                1u
/* Message RAM size in KB */
#define CANFD_MRAM_SIZE                 4u
/* Message RAM address width */
#define CANFD_MRAM_ADDR_WIDTH           10u
/* System RAM 0 MPC protection block size in Bytes: 1<< (RAMC0_BLOCK_SIZE+5).
   Example: 7 = 4KB protection block size. */
#define CPUSS_RAMC0_BLOCK_SIZE          6u
/* Number of macros used to implement system RAM 0. Example: 8 if 256 KB system
   SRAM 0 is implemented with 8 32KB macros. */
#define CPUSS_RAMC0_MACRO_NR            1u
/* Number of power partitions in system RAM 0. Each power partition can be
   independently power controlled using a switch. Example: RAMC0_MACRO_NR = 16
   and RAMC0_PWR_GROUP_NR = 4 will create 4 power partitions with 4 macros in
   each power partition. */
#define CPUSS_RAMC0_PWR_GROUP_NR        1u
/* System RAM 1 present or not ('0': no, '1': yes) */
#define CPUSS_RAMC1_PRESENT             1u
/* System RAM 1 MPC protection block size in Bytes: 1<< (RAMC1_BLOCK_SIZE+5).
   Example: 7 = 4KB protection block size. */
#define CPUSS_RAMC1_BLOCK_SIZE          6u
/* Number of macros used to implement system RAM 1. */
#define CPUSS_RAMC1_MACRO_NR            1u
/* Number of power partitions in system RAM 1. Each power partition can be
   independently power controlled using a switch. Example: RAMC1_MACRO_NR = 16
   and RAMC1_PWR_GROUP_NR = 4 will create 4 power partitions with 4 macros in
   each power partition. */
#define CPUSS_RAMC1_PWR_GROUP_NR        1u
/* System RAM 2 present or not ('0': no, '1': yes) */
#define CPUSS_RAMC2_PRESENT             0u
/* System RAM 2 MPC protection block size in Bytes: 1<< (RAMC2_BLOCK_SIZE+5).
   Example: 7 = 4KB protection block size. */
#define CPUSS_RAMC2_BLOCK_SIZE          6u
/* Number of macros used to implement system RAM 2. */
#define CPUSS_RAMC2_MACRO_NR            1u
/* Number of power partitions in system RAM 2. Each power partition can be
   independently power controlled using a switch. Example: RAMC2_MACRO_NR = 16
   and RAMC2_PWR_GROUP_NR = 4 will create 4 power partitions with 4 macros in
   each power partition. */
#define CPUSS_RAMC2_PWR_GROUP_NR        1u
/* System SRAM(s) ECC present or not ('0': no, '1': yes) */
#define CPUSS_RAMC_ECC_PRESENT          1u
/* System SRAM(s) address ECC present or not ('0': no, '1': yes) */
#define CPUSS_RAMC_ECC_ADDR_PRESENT     0u
/* System Patchable ROM Controller Present or not ('0' : no, '1': yes) */
#define CPUSS_PROMC_PRESENT             1u
/* System Patchable ROM MPC protection block size in Bytes: 1<<
   (PROMC_BLOCK_SIZE+5). Example: 7 = 4KB protection block size. */
#define CPUSS_PROMC_BLOCK_SIZE          6u
/* Number of macros used to implement system patchable ROM. Example: 4 if 512 KB
   system patchable ROM is implemented with 4 128KB macros. ( Exception Player:
   8 * 64K ) */
#define CPUSS_PROMC_MACRO_NR            1u
/* Presence of the patch functionality. 0: ROM cannot be patched. 1: ROM can be
   patched. */
#define CPUSS_PROMC_PATCH_PRESENT       0u
/* Number of patchable locations (patch entries). Possible range [32,512] in
   powers of 2. (BRCM: 512 is only supported) These are implemented using SRAM.
   (SNPS: 32x128, 64x128, 128x128, 256x128, 512x128 are supported; BRCM: 4
   instances of 512x32 only supported) */
#define CPUSS_PROMC_PATCH_NR            64u
/* Patch size selection of a single structure. 0: 8 Bytes. 1: 16 Bytes. **) 2: 32
   Bytes. 3: 64 Bytes. **) The patch size should fit to the word size of the
   ROM. Thus only PATCH_SIZE=1 is supported for this ROM controller. */
#define CPUSS_PROMC_PATCH_SIZE          1u
/* Width of compared address bits. The LSB is determined by the PATCH_SIZE, for 16
   bytes this equals to bit [4]. The MSB is chosen to address the full size of
   the ROM in bytes. */
#define CPUSS_PROMC_MATCH_ADDR_SIZE     12u
/* Initial value of the first patchable address in the ROM. This address and the
   following higher addresses are patchable if the function is enabled. */
#define CPUSS_PROMC_SROM_BOUNDARY       0x00001000u
/* RRAM Controller Present or not ('0' : no, '1': yes) */
#define CPUSS_RRAMC_PRESENT             0u
/* RRAM NVM memory size in KB */
#define CPUSS_RRAMC_NVM_SIZE            512u
/* Size of RRAM Extra region */
#define CPUSS_RRAMC_EXTRA_REGION_SIZE   16u
/* RRAMC MPC protection block size in Bytes: 1<< (RRAMC_BLOCK_SIZE+5). Example: 7
   = 4KB protection block size. */
#define CPUSS_RRAMC_BLOCK_SIZE          7u
/* Main NVM region start address */
#define CPUSS_RRAMC_MAIN_START_ADDRESS  0x02000000u
/* Work NVM region start address */
#define CPUSS_RRAMC_WORK_START_ADDRESS  0x03000000u
/* Sflash NVM region start address */
#define CPUSS_RRAMC_SFLASH_START_ADDRESS 0x03600000u
/* Secure NVM region start address */
#define CPUSS_RRAMC_PROTECTED_START_ADDRESS 0x03C00000u
/* Main NVM region size in multiples of 8KB (8KB*N) */
#define CPUSS_RRAMC_MAIN_N              32u
/* Work NVM region size in multiples of 8KB (8KB*Z) */
#define CPUSS_RRAMC_WORK_Z              0u
/* Sflash NVM region size in multiples of 8KB (8KB*Y) */
#define CPUSS_RRAMC_SFLASH_Y            0u
/* Secure NVM region size in multiples of 8KB (8KB*X) */
#define CPUSS_RRAMC_PROTECTED_X         32u
/* Address of Session key for encoding/decoding Secure data */
#define CPUSS_RRAMC_SESSION_KEY_ADDRESS 0x40051000u
/* Default value of the 32-bit Session key */
#define CPUSS_RRAMC_SESSION_KEY_VALUE   0x16071971u
/* Bootrow Block Address [21:4] */
#define CPUSS_BOOTROW_BLOCK_ADDRESS     0x00008000u
/* Start address for "a defined space in RRAM Secure OTP region to be blocked when
   test_block_nvm is 1" */
#define CPUSS_RRAMC_BLOCK_START         16u
/* End address for "a defined space in RRAM Secure OTP region to be blocked when
   test_block_nvm is 1" */
#define CPUSS_RRAMC_BLOCK_END           507u
/* DataWire 0 present or not ('0': no, '1': yes) */
#define CPUSS_DW0_PRESENT               1u
/* Number of DataWire 0 channels ([1, 1024]) */
#define CPUSS_DW0_CH_NR                 16u
/* DataWire 1 present or not ('0': no, '1': yes) */
#define CPUSS_DW1_PRESENT               0u
/* Number of DataWire 1 channels ([1, 1024]) */
#define CPUSS_DW1_CH_NR                 16u
/* DataWire SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_PRESENT            0u
/* DataWire SRAMs address ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_ADDR_PRESENT       0u
/* DMA controller-0 present or not ('0': no, '1': yes) */
#define CPUSS_DMAC0_PRESENT             0u
/* Number of DMA controller-0 channels ([1, 8]) */
#define CPUSS_DMAC0_CH_NR               1u
/* DMA controller-1 present or not ('0': no, '1': yes) */
#define CPUSS_DMAC1_PRESENT             0u
/* Number of DMA controller-1 channels ([1, 8]) */
#define CPUSS_DMAC1_CH_NR               1u
/* Number of IPC structures. Legal range [1, 16] */
#define CPUSS_IPC_NR                    8u
/* Number of IPC interrupt structures. Legal range [1, 16] */
#define CPUSS_IPC_IRQ_NR                4u
/* Number of protection contexts supported. Legal range [3, 4, 6, 8] (CDT-336698) */
#define CPUSS_PC_NR                     8u
/* CM33_0 PC monitor present or not */
#define CPUSS_CM33_0_PC_MON_PRESENT     1u
/* IRQ expander present ('0': no, '1': yes) */
#define CPUSS_SYSTEM_IRQ_PRESENT        0u
/* Number of system interrupt inputs to CPUSS */
#define CPUSS_SYSTEM_INT_NR             143u
/* Number of DeepSleep system interrupt inputs to CPUSS */
#define CPUSS_SYSTEM_DPSLP_INT_NR       32u
/* SYSCPUSS Security extension present or not ('0': no, '1': yes) */
#define CPUSS_SYS_SECEXT_PRESENT        1u
/* Number of CPU interrupts used when SYSTEM_IRQ_PRESENT is '1'. Legal values 8,
   16. */
#define CPUSS_CM33_INT_NR               8u
/* Individual CPU interrupts to be disabled when SYSTEM_IRQ_PRESENT is '0'. 0: To
   enable respective interrupt-bit functionality; 1: To disable respective
   interrupt-bit functionality; Default value {480{1'b0}} to enable all 480
   interrupts of CM33; Example: {479{1'b0},1'b1} disables the interrupt IRQ[0]
   of CM33 and enables all other interrupts. This parameter is NOT applicable
   when SYSTEM_IRQ_PRESENT is '1'. */
#define CPUSS_CM33_IRQ_DISABLE          0u
/* CM33_0 Floating point unit present or not ('0': no, '1': yes) */
#define CPUSS_CM33_0_FPU_PRESENT        1u
/* CM33_0 DSP extension present or not ('0': no, '1': yes) */
#define CPUSS_CM33_0_DSP_PRESENT        1u
/* CM33_0 Security extension present or not ('0': no, '1': yes) */
#define CPUSS_CM33_0_SECEXT_PRESENT     1u
/* CM33_0 non-secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define CPUSS_CM33_0_MPU_NS_REGION_NR   8u
/* CM33_0 secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define CPUSS_CM33_0_MPU_S_REGION_NR    8u
/* CM33_0 SAU regions. Legal values [0, 4, 8] */
#define CPUSS_CM33_0_SAU_REGION_NR      8u
/* CM33_0 default WAIT value; 0: CM33_0 will start code execution after reset
   release; 1: CM33_0 will wait until SE or FW to clear this bit to start code
   execution after reset release. */
#define CPUSS_CM33_0_WAIT_DEFAULT       0u
/* Default value for CM33 Secure Vector table base address */
#define CPUSS_CM33_S_VECTOR_TABLE_DEFAULT 0x00210000u
/* Default value for CM33 Non-secure Vector table base address */
#define CPUSS_CM33_NS_VECTOR_TABLE_DEFAULT 0x00010000u
/* CM33_1 present or not. */
#define CPUSS_CM33_1_PRESENT            0u
/* CM33_1 Floating point unit present or not ('0': no, '1': yes) */
#define CPUSS_CM33_1_FPU_PRESENT        0u
/* CM33_1 DSP extension present or not ('0': no, '1': yes) */
#define CPUSS_CM33_1_DSP_PRESENT        0u
/* CM33_1 Security extension present or not ('0': no, '1': yes) */
#define CPUSS_CM33_1_SECEXT_PRESENT     0u
/* CM33_1 non-secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define CPUSS_CM33_1_MPU_NS_REGION_NR   16u
/* CM33_1 secure MPU regions. Legal values [0, 4, 8, 12, 16] */
#define CPUSS_CM33_1_MPU_S_REGION_NR    16u
/* CM33_1 SAU regions. Legal values [0, 4, 8] */
#define CPUSS_CM33_1_SAU_REGION_NR      8u
/* Cache RAM size in Kilo Bytes; Supported values are [8, 16, 32]. */
#define CPUSS_CACHE_SIZE                16u
/* Cache RAM ECC present or not ('0': no, '1': yes) */
#define CPUSS_CACHE_RAM_ECC_PRESENT     0u
/* Debug level. Legal range [0,2]. 0: Minumum debug (only BKPT instruction
   support) 1: Reduced debug set (2 watchpoints and 4 break points) 2: Full
   debug set (4 watchpoints and 8 breakpoints) */
#define CPUSS_DEBUG_LVL                 2u
/* Trace level. Legal range [0,2] 0: No trace support 1: ITM trace (ITM, TPIU, and
   SWO) 2: ITM and ETM trace (ITM, ETM, TPIU, and SWO) Note: No support for CM33
   MTB. ETB present or not is determined by separate ETB_PRESENT parameter. */
#define CPUSS_TRACE_LVL                 2u
/* PTM interface present (0=No, 1=Yes) */
#define CPUSS_PTM_PRESENT               0u
/* CPUSS external CODE master interface 0 present or not on CODE infrastructure.
   ('0': no, '1': yes). */
#define CPUSS_CODE_MS_0_PRESENT         0u
/* CPUSS external SYS master interface 0 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define CPUSS_SYS_MS_0_PRESENT          1u
/* CPUSS external SYS master interface 1 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define CPUSS_SYS_MS_1_PRESENT          0u
/* CPUSS external SYS master NVM interface 0 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define CPUSS_SYS_MS_0_NVM_PRESENT      0u
/* CPUSS external SYS master NVM interface 1 present or not on SYS infrastructure.
   ('0': no, '1': yes). */
#define CPUSS_SYS_MS_1_NVM_PRESENT      0u
/* Number of external AHB5 slave interfaces connected to SYSTEM infrastructure.
   Maximum number of slaves supported is 4. Width of this parameter is 4-bits.
   1-bit mask for each slave indicating present or not. Example: 4'b0001 - slave
   0 is present. */
#define CPUSS_SYS_SL_PRESENT            0u
/* Number of external EXPANSION masters driving the EXP AHB5 infrastructure.
   Maximum number of masters supported is 8. Width of this parameter is 8-bits.
   1-bit mask for each master indicating present or not. Example: 8'b0000_0101 -
   master 0 & master 2 are present. */
#define CPUSS_EXP_MS_PRESENT            1u
/* The timing de-coupled AHB brdige is present or not on the output of EXP
   infrastructure. ('0': no, '1':yes) */
#define CPUSS_EXP_BRIDGE_PRESENT        1u
/* Specifies the CODE interconnect arbitration type used for generating the RTL.
   0: ROUND; round insert an extra cycle each time the downstream port selects a
   new upstream port to service and must be used to avoid timing issues when
   target frequency is >=100MHz; 1: ROUND_NOLAT; round_nolat have no such
   latency and can be used when target frequency is <100MHz; Improves the
   performance by reducing latency; */
#define CPUSS_CODE_INFRA_ARB_TYPE       0u
/* Specifies the SYSTEM interconnect arbitration type used for generating the RTL.
   0: ROUND; round insert an extra cycle each time the downstream port selects a
   new upstream port to service and must be used to avoid timing issues when
   target frequency is >=100MHz; 1: ROUND_NOLAT; round_nolat have no such
   latency and can be used when target frequency is <100MHz; Improves the
   performance by reducing latency; */
#define CPUSS_SYSTEM_INFRA_ARB_TYPE     0u
/* Specifies the EXPANSION interconnect arbitration type used for generating the
   RTL. 0: ROUND; round insert an extra cycle each time the downstream port
   selects a new upstream port to service and must be used to avoid timing
   issues when target frequency is >=100MHz; 1: ROUND_NOLAT; round_nolat have no
   such latency and can be used when target frequency is <100MHz; Improves the
   performance by reducing latency; */
#define CPUSS_EXP_INFRA_ARB_TYPE        0u
/* CoreSight Part Identification Number */
#define CPUSS_JEPID                     65u
/* CoreSight Part Identification Number */
#define CPUSS_JEPCONTINUATION           0u
/* CoreSight Part Identification Number */
#define CPUSS_FAMILYID                  281u
/* ROM trim register width (for ARM 3, for Synopsys 5, for BRCM 6) */
#define CPUSS_ROM_TRIM_WIDTH            5u
/* ROM trim register default (for both ARM and Synopsys 0x0000_0002; for BRCM
   0x0000_0000) */
#define CPUSS_ROM_TRIM_DEFAULT          18u
/* Embedded Trace Buffer in mxdebug600 present or not ('0': no, '1': yes) */
#define CPUSS_ETB_PRESENT               0u
/* SRAM_TYPE for CM33-0 Cache SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_CM33_0_CACHE    0u
/* SRAM_TYPE for CM33-1 Cache SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_CM33_1_CACHE    0u
/* SRAM_TYPE for DW0 SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_DW0             0u
/* SRAM_TYPE for DW1 SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_DW1             0u
/* SRAM_TYPE for RAMC0 MPC SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC0_MPC       0u
/* SRAM_TYPE for RAMC1 MPC SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC1_MPC       0u
/* SRAM_TYPE for RAMC2 MPC SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC2_MPC       0u
/* SRAM_TYPE for RRAMC MPC SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RRAMC_MPC       0u
/* SRAM_TYPE for PROMC MPC SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_PROMC_MPC       0u
/* SRAM_TYPE for RAMC0 System SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC0           0u
/* SRAM_TYPE for RAMC1 System SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC1           0u
/* SRAM_TYPE for RAMC2 System SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_RAMC2           0u
/* SRAM_TYPE for PROMC Patch SRAM (To determine SRAM memory type) */
#define CPUSS_SRAM_TYPE_PROMC_PATCH     0u
/* Specifies the CM33-0 CACHE SRAM POWER SWITCH is present or not; 0: Not present;
   1: Present; */
#define CPUSS_CM33_0_CACHE_SWITCH_PRESENT 1u
/* Specifies the CM33-1 CACHE SRAM POWER SWITCH is present or not; 0: Not present;
   1: Present; */
#define CPUSS_CM33_1_CACHE_SWITCH_PRESENT 0u
/* Specifies the DW-0 SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_DW0_SWITCH_PRESENT        0u
/* Specifies the DW-1 SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_DW1_SWITCH_PRESENT        0u
/* Specifies the MPC SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_MPC_SWITCH_PRESENT        0u
/* Specifies the PROMC Patch-SRAM POWER SWITCH is present or not; 0: Not present;
   1: Present; */
#define CPUSS_PROMC_SWITCH_PRESENT      0u
/* Specifies the RAMC-0 SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_RAMC0_SRAM_SWITCH_PRESENT 1u
/* Specifies the RAMC-1 SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_RAMC1_SRAM_SWITCH_PRESENT 1u
/* Specifies the RAMC-2 SRAM POWER SWITCH is present or not; 0: Not present; 1:
   Present; */
#define CPUSS_RAMC2_SRAM_SWITCH_PRESENT 0u
/* External Crystal Oscillator is present (high frequency) */
#define CPUSS_ECO_PRESENT               1u
/* Number of Fault reporting structures; Legal range [1, 4] */
#define CPUSS_FAULT_NR                  1u
/* FlashC controller is present or not. 0: Not present 1: Present */
#define CPUSS_FLASHC_PRESENT            1u
/* ECC present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_ECC_PRESENT        1u
/* Start address of 33rd column */
#define CPUSS_FLASHC_COLUMN_33_START_ADDRESS 0x03A00000u
/* Main region start address */
#define CPUSS_FLASHC_MAIN_START_ADDRESS 0x02000000u
/* Work region start address */
#define CPUSS_FLASHC_WORK_START_ADDRESS 0x03000000u
/* SFLASH region start address */
#define CPUSS_FLASHC_SFLASH_START_ADDRESS 0x03400000u
/* Refresh rows start address */
#define CPUSS_FLASHC_REFRESH_ROW_START_ADDRESS 0x03800000u
/* FM MMIO start address */
#define CPUSS_FM_MMIO_START_ADDRESS     0x42152000u
/* mxs40flashc MMIO start address */
#define CPUSS_FLASHC_MMIO_START_ADDRESS 0x42150000u
/* mxs40flashc MPC MMIO start address */
#define CPUSS_FLASHC_MPC_START_ADDRESS  0x42151000u
/* Number of sectors in FM */
#define CPUSS_FLASHC_SECTOR_M           2u
/* Size of MAIN NVM in 8 KB blocks for each pair of sectors. */
#define CPUSS_FLASHC_MAIN_N             64u
/* Size of WORK NVM in 8 KB blocks for each pair of sectors. */
#define CPUSS_FLASHC_WORK_Z             0u
/* Size of SFLASH NVM in 8 KB blocks in Sector 1. */
#define CPUSS_FLASHC_SFLASH_Y           4u
/* Size of refresh rows for each sector. */
#define CPUSS_FLASHC_REFRESH_ROW        4u
/* SFLASH sector number */
#define CPUSS_FLASHC_SFLASH_SECNUM      1u
/* Number of rows per sector */
#define CPUSS_FLASHC_ROWS_PER_SECTOR    512u
/* CM330 HMASTER ID */
#define CPUSS_CM33_0_HMASTER_ID         0u
/* CM331 HMASTER ID */
#define CPUSS_CM33_1_HMASTER_ID         1u
/* System RAM 0 size in KB */
#define CPUSS_CHIP_TOP_RAMC0_SIZE       64u
/* System RAM 1 size in KB */
#define CPUSS_CHIP_TOP_RAMC1_SIZE       64u
/* System RAM 2 size in KB */
#define CPUSS_CHIP_TOP_RAMC2_SIZE       64u
/* System Patchable ROM size in KB */
#define CPUSS_CHIP_TOP_PROMC_SIZE       64u
/* See MMIO2 instantiation or not */
#define CPUSS_CHIP_TOP_PROFILER_PRESENT 0u
/* ETAS Calibration support pin out present (automotive only) */
#define CPUSS_CHIP_TOP_CAL_SUP_NZ_PRESENT 0u
/* TRACE_LVL>0 */
#define CPUSS_CHIP_TOP_TRACE_PRESENT    1u
/* Width of HPROT */
#define CPUSS_CHIP_TOP_HPROT_WIDTH      7u
/* Number of protection contexts supported. Legal range [2,16] */
#define CPUSS_MS_CTL_STRUCT_PC_NR       8u
/* MS_CTL_P (Privileged) default value */
#define CPUSS_MS_CTL_STRUCT_MS_CTL_P_DEFAULT 1u
/* MS_CTL_NS (Non-secure) default value */
#define CPUSS_MS_CTL_STRUCT_MS_CTL_NS_DEFAULT 0u
/* MS_CTL_PC_MASK default value */
#define CPUSS_MS_CTL_STRUCT_MS_CTL_PC_MASK_DEFAULT 0u
/* MS_CTL_PC (Protection Context) default value */
#define CPUSS_MS_PC_STRUCT_MS_CTL_PC_DEFAULT 0u
/* IP MMIO registers base address in the system address space (32-bit Byte address
   at a 64 kB multiple). The IP MMIO registers occupy a 64 kB memory region in
   the system address space. */
#define CRYPTOLITE_ADDR_BASE            0x40230000u
/* ECC present or not ('0': no, '1': yes). */
#define CRYPTOLITE_ECC_PRESENT          0u
/* True random number generation component support ('0': no, '1': yes). */
#define CRYPTOLITE_TRNG_PRESENT         1u
/* Vector unit component support ('0': no, '1': yes). */
#define CRYPTOLITE_VU_PRESENT           1u
/* SHA-256 hash component support ('0': no, '1': yes). Must be 1 for register
   generation only when any of SHA_PRESENT, SHA384_PRESENT or SHA512_PRESENT is
   selected for use. */
#define CRYPTOLITE_SHA_PRESENT          1u
/* SHA-384 hash component support ('0': no, '1': yes). */
#define CRYPTOLITE_SHA384_PRESENT       1u
/* SHA-512 hash component support ('0': no, '1': yes). */
#define CRYPTOLITE_SHA512_PRESENT       1u
/* Crypto v1.2 IP version support ('0': no, '1': yes). */
#define CRYPTOLITE_CRYPTO_1_2           1u
/* Support for any flavour of SHA function (SHA-256 or SHA-384 or SHA-512) ('0':
   no, '1': yes) */
#define CRYPTOLITE_SHA_ANY_PRESENT      1u
/* AES-128 block cipher component support ('0': no, '1': yes). */
#define CRYPTOLITE_AES_PRESENT          1u
/* Trace level. Legal range [0,2] 0: No trace support 1: ITM trace (ITM, TPIU, and
   SWO) 2: ITM and ETM trace (ITM, ETM, TPIU, and SWO) Note: No support for CM33
   MTB. ETB present or not is determined by separate ETB_PRESENT parameter. */
#define DEBUG600_TRACE_LVL              2u
/* Embedded Trace Buffer present or not ('0': no, '1': yes) */
#define DEBUG600_ETF_PRESENT            0u
/* Width of the TPIU interface in bits ([1,4]) */
#define DEBUG600_TPIU_WIDTH             4u
/* CoreSight Part Identification Number */
#define DEBUG600_JEPID                  65u
/* CoreSight Part Identification Number */
#define DEBUG600_JEPCONTINUATION        0u
/* CoreSight Part Identification Number */
#define DEBUG600_FAMILYID               281u
/* Compiled cells vendor: 1:SNPS, 2:ARM, 3:BRCM */
#define DEBUG600_RAM_VEND               1u
/* PLATFORM VARIANT for ITCM SRAM (To determine ITCM SRAM memory type) */
#define DEBUG600_PLATFORM_VARIANT       6u
/* VT type of instantiated tech cells through mxtk. */
#define DEBUG600_CELL_VT_TYPE           0u
/* ECOREV Value to the Coresight components */
#define DEBUG600_REVAND                 0u
/* CM55_0 present or not. */
#define DEBUG600_CM55_0_PRESENT         1u
/* CM55_1 present or not. */
#define DEBUG600_CM55_1_PRESENT         1u
/* CM33_1 present or not. */
#define DEBUG600_CM33_1_PRESENT         0u
/* Length of JTAG instruction register. Supported Values [4,8] */
#define DEBUG600_JTAG_IR_LENGTH         8u
/* Number of HFCLK roots present. Must be > 0. Must be same as set for SRSS */
#define DFT_NUM_HFROOT                  7u
/* Width of clk_occ_fast output bus (number of external OCCs) */
#define DFT_EXT_OCC                     0u
/* Number of PLLs usable as struct mode clock source (number of clk_occ_fast
   clocks). Not expected to be more than 4 */
#define DFT_NUM_FASTCLK                 2u
/* Number of select signals to control each FASTCLK multiplexer. Not expected to
   be more than 2 */
#define DFT_NUM_FASTCLK_SEL             1u
/* Number of MBIST controllers with corresponding mbist(pg)_done and mbist(pg)_go
   signals. Value defined by CIC during Pass 1. */
#define DFT_MBIST_C_NUM                 7u
/* Number of LBIST controllers. One LBIST controller on top level and one LBIST
   controller in each optional HDFT block */
#define DFT_LBIST_C_NUM                 1u
/* Number of MBISR chains. Separate chains are required for power domains that can
   be enabled independently */
#define DFT_MBISR_CH_NUM                1u
/* Defines if (Burn-In) Monitor function is present */
#define DFT_MONITOR_PRESENT             1u
/* Defines if Mentor BISR controller is present (controls generation of control
   and status register) */
#define DFT_MENTOR_BISR_PRESENT         1u
/* Defines if Direct MBIST Access function is present (controls generation of
   control and status registers) */
#define DFT_DIRECT_MBIST_ACCESS_PRESENT 0u
/* Defines if DIRECT_MBIST*SEL and DIRECT_MBIST*_RESULT registers are generated
   (only used for DIRECT_MBIST_ACCESS_PRESENT=1) */
#define DFT_DIRECT_MBIST_CTRL_ACCESS_PRESENT 0u
/* Controls generation of BIST_STEP_SEL_EN and BIST_STEP_SEL register fields
   within DIRECT_MBIST_CTL reg (only used for DIRECT_MBIST_ACCESS_PRESENT=1) */
#define DFT_DIRECT_MBIST_STEP_ACCESS_PRESENT 0u
/* Controls generation of BIST_MEM_SEL_EN and BIST_MEM_SEL register fields within
   DIRECT_MBIST_CTL reg (only used for DIRECT_MBIST_ACCESS_PRESENT=1) */
#define DFT_DIRECT_MBIST_MEM_ACCESS_PRESENT 0u
/* Number of HLBs with Direct MBIST Access function (only used for
   DIRECT_MBIST_ACCESS_PRESENT=1) */
#define DFT_DIRECT_MBIST_BAP_NUM        1u
/* Maximum value of MBIST controllers connected to single BAP (only used for
   DIRECT_MBIST_ACCESS_PRESENT=1) */
#define DFT_DIRECT_MBIST_CTRL_NUM       1u
/* local parameter: Number of MBIST controllers mapped to BISTMON_MBIST0_COMPLETED
   register */
#define DFT_MBIST0_C_NUM                7u
/* local parameter: Number of MBIST controllers mapped to BISTMON_MBIST1_COMPLETED
   register */
#define DFT_MBIST1_C_NUM                1u
/* local parameter: Number of MBIST controllers mapped to BISTMON_MBIST2_COMPLETED
   register */
#define DFT_MBIST2_C_NUM                1u
/* local parameter: Number of MBIST controllers mapped to BISTMON_MBIST3_COMPLETED
   register */
#define DFT_MBIST3_C_NUM                1u
/* local parameter: Number of MBIST controllers mapped to DIRECT_MBIST0_SEL and
   DIRECT_MBIST0_RESULT registers */
#define DFT_DIRECT_MBIST0_CTRL_NUM      1u
/* local parameter: Number of MBIST controllers mapped to DIRECT_MBIST1_SEL and
   DIRECT_MBIST1_RESULT registers */
#define DFT_DIRECT_MBIST1_CTRL_NUM      1u
/* local parameter: Number of MBIST controllers mapped to DIRECT_MBIST2_SEL and
   DIRECT_MBIST2_RESULT registers */
#define DFT_DIRECT_MBIST2_CTRL_NUM      1u
/* local parameter: Number of MBIST controllers mapped to DIRECT_MBIST3_SEL and
   DIRECT_MBIST3_RESULT registers */
#define DFT_DIRECT_MBIST3_CTRL_NUM      1u
/* Must be set to 1 when using this mxdft version in MXS40Sv2 devices */
#define DFT_PLATFORM_MXS40SV2           1u
/* Defines if VCCRET supply is generated in UPF. Must be set to 1 in MXS40S*
   technologies and to 0 in MXS40E */
#define DFT_VCCRET_PRESENT              1u
/* Defines if UPF is generated for S28 technology (1) or S40 technolgy (0) */
#define DFT_TECH_S28                    0u
/* Controls the polulation of the "accessed" monitor bits <IOBSC,0,MBIST,LBIST>.
   Default = 4'b1011 */
#define DFT_POP_ACC                     10u
/* Controls the polulation of the "started" monitor bits
   <0,FLASH_DBI,MBIST,LBIST>. Default = 4'b0111 */
#define DFT_POP_START                   2u
/* Controls the polulation of the "done" (completed) monitor bits
   <0,FLASH_DBI,MBIST,LBIST>. Default = 4'b0111 */
#define DFT_POP_DONE                    2u
/* Controls the polulation of the "failed" monitor bits <0,0,MBIST,LBIST>. Default
   = 4'b0011 */
#define DFT_POP_FAIL                    2u
/* Used for mxdft_tap: controls generation of logic for "TDR capture&update via
   MMIO" (default value is 1) */
#define DFT_CAP_UP_PRESENT              0u
/* Number of DataWire channels ([1, 512]) */
#define DW_CH_NR                        16u
/* DataWire SRAM ECC present or not ('0': no, '1': yes) */
#define DW_ECC_PRESENT                  0u
/* DataWire SRAM address ECC present or not ('0': no, '1': yes) */
#define DW_ECC_ADDR_PRESENT             0u
#define DW_CH_NR_WIDTH                  1u
#define DW_CH_STRUCT_ECC_PRESENT        0u
/* Number of instantiated eFUSE macros (256 bit macros). Legal range [4,8,12,16] */
#define EFUSE_EFUSE_NR                  4u
/* Enables limiting access to region defined by PROT_MASTER_START/END by
   PROT_MASTER */
#define EFUSE_BLOCK_NVM_CRYPTO          0u
/* Begining of region of EFUSE only accessible by master defined by PROT_MASTER. */
#define EFUSE_PROT_MASTER_START         4092u
/* End of region of EFUSE (last address) only accessible by master defined by
   PROT_MASTER. */
#define EFUSE_PROT_MASTER_END           4092u
/* The Master with permission to access the region defined by
   PROT_MASTER_START/PROT_MASTER_END */
#define EFUSE_PROT_MASTER               255u
#define FLASHC_MPC_PC_NR                8u
/* Cache SRAM ECC present or not ('0': no, '1': yes) */
#define ICACHE_ECC_PRESENT              0u
/* Security extension present ('0': no, '1': yes) */
#define IOSS_SECEXT                     1u
/* Number of GPIO ports in range 0..31 */
#define IOSS_GPIO_GPIO_PORT_NR_0_31     10u
/* Number of GPIO ports in range 32..63 */
#define IOSS_GPIO_GPIO_PORT_NR_32_63    0u
/* Number of GPIO ports in range 64..95 */
#define IOSS_GPIO_GPIO_PORT_NR_64_95    0u
/* Number of GPIO ports in range 96..127 */
#define IOSS_GPIO_GPIO_PORT_NR_96_127   0u
/* GPIO ports in range 0..31 */
#define IOSS_GPIO_GPIO_PORT_B_0_31      1u
/* GPIO ports in range 32..63 */
#define IOSS_GPIO_GPIO_PORT_B_32_63     0u
/* GPIO ports in range 64..95 */
#define IOSS_GPIO_GPIO_PORT_B_64_95     0u
/* GPIO ports in range 96..127 */
#define IOSS_GPIO_GPIO_PORT_B_96_127    0u
/* Secure GPIO ports in range 0..31 */
#define IOSS_GPIO_GPIO_PORT_SEC_B_0_31  1u
/* Secure GPIO ports in range 32..63 */
#define IOSS_GPIO_GPIO_PORT_SEC_B_32_63 0u
/* Secure GPIO ports in range 64..95 */
#define IOSS_GPIO_GPIO_PORT_SEC_B_64_95 0u
/* Secure GPIO ports in range 96..127 */
#define IOSS_GPIO_GPIO_PORT_SEC_B_96_127 0u
/* Number of ports in device */
#define IOSS_GPIO_GPIO_PORT_NR          10u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DRIVE_EXT 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DRIVE_EXT 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DRIVE_EXT 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DRIVE_EXT 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DRIVE_EXT 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DRIVE_EXT 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DRIVE_EXT 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DRIVE_EXT 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DRIVE_EXT 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DRIVE_EXT 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO7 0u
/* Power Switch exists */
#define IOSS_GPIO_PWRSW                 0u
/* Indicates if Secure access is enabled */
#define IOSS_GPIO_SECEXT                1u
/* Number of AMUX splitter cells */
#define IOSS_HSIOM_AMUX_SPLIT_NR        5u
/* Number of HSIOM ports in device (same as GPIO.GPIO_PRT_NR) */
#define IOSS_HSIOM_HSIOM_PORT_NR        10u
/* Number of PWR/GND MONITOR CELLs in the device */
#define IOSS_HSIOM_MONITOR_NR           0u
/* Number of PWR/GND MONITOR CELLs in range 0..31 */
#define IOSS_HSIOM_MONITOR_NR_0_31      0u
/* Number of PWR/GND MONITOR CELLs in range 32..63 */
#define IOSS_HSIOM_MONITOR_NR_32_63     0u
/* Number of PWR/GND MONITOR CELLs in range 64..95 */
#define IOSS_HSIOM_MONITOR_NR_64_95     0u
/* Number of PWR/GND MONITOR CELLs in range 96..127 */
#define IOSS_HSIOM_MONITOR_NR_96_127    0u
/* Number of HSIOM ports in device (same as GPIO.GPIO_PRT_NR) */
#define IOSS_HSIOM_HSIOM_SEC_PORT_NR    10u
/* Indicates if Secure access is enabled */
#define IOSS_HSIOM_SECEXT               1u
/* Security extension present ('0': no, '1': yes) */
#define IOSS_HSIOM_SECURE_PRT_SECEXT    1u
/* Mask of SMARTIO instances presence */
#define IOSS_SMARTIO_SMARTIO_MASK       0u
/* Page size in # of 32-bit words (1: 4 bytes, 2: 8 bytes, ... */
#define IPC_PA_SIZE                     1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define IPC_MASTER_WIDTH                6u
#define IPC_IPC_NR                      8u
#define IPC_IPC_IRQ_NR                  4u
/* USE_POWER_ON_DOMAIN(0: no, 1: yes) 0: ALM_MON and SEED_* SFRs NonRetention 1:
   ALM_MON and SEED_* SFRs DeepSleep Note: This parameter is only verified for
   value 0. */
#define MXAES_USE_POWER_ON_DOMAIN       0u
/* NRNGA_INTEGRATION (0: no, 1: yes) 0: 4-times SW seeding required 1: NRNGA
   seeding source available */
#define MXAES_Unmasked_user_range_NRNGA_INTEGRATION 1u
/* CM33[0] should be 0, CM33[1] should have 1 */
#define MXCM33_CPU_WAIT_DEFAULT         0u
/* Number of CPU interrupts used when SYSTEM_IRQ_PRESENT is '1'. Legal values 8,
   16. */
#define MXCM33_CM33_INT_NR              8u
/* IRQ expander present ('0': no, '1': yes) */
#define MXCM33_SYSTEM_IRQ_PRESENT       0u
/* CM33[0] should be 1, CM33[1] should have 0 */
#define MXCM33_PC_MON_PRESENT           1u
/* Number of system interrupt inputs to CPUSS */
#define MXCM33_SYSTEM_INT_NR            143u
/* TrustZone security extention present or not */
#define MXCM33_SECEXT                   1u
/* FPU extention present or not */
#define MXCM33_FPU_PRESENT              1u
/* DSP extention present or not */
#define MXCM33_DSP_PRESENT              1u
/* Default value for CM33 Secure Vector table base address */
#define MXCM33_CM33_S_VECTOR_TABLE_DEFAULT 0x00210000u
/* Default value for CM33 Non-secure Vector table base address */
#define MXCM33_CM33_NS_VECTOR_TABLE_DEFAULT 0x00010000u
/* Number of FAULT infrastructure channels ([1, 4]) */
#define MXFAULT_FAULT_NR                1u
/* AHB5 h*user width. */
#define PERI_USER_WIDTH                 4u
/* AHB5 hprot width */
#define PERI_HPROT_WIDTH                7u
/* Master interface presence mask (4 bits) */
#define PERI_MS_PRESENT                 3u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_CLOCK_PRESENT 0u
/* Default value for SL_CTL register value on POR. Group-0 it is 32'hFFFF_FFFF
   Group-1 to Group-15 it is 32'h000_0000 */
#define PERI_GROUP_PRESENT0_PERI_GROUP_SL_CTL_DEFAULT 0xFFFFFFFFu
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_CLOCK_PRESENT 1u
/* Default value for SL_CTL register value on POR. Group-0 it is 32'hFFFF_FFFF
   Group-1 to Group-15 it is 32'h000_0000 */
#define PERI_GROUP_PRESENT1_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_CLOCK_PRESENT 1u
/* Default value for SL_CTL register value on POR. Group-0 it is 32'hFFFF_FFFF
   Group-1 to Group-15 it is 32'h000_0000 */
#define PERI_GROUP_PRESENT2_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_CLOCK_PRESENT 1u
/* Default value for SL_CTL register value on POR. Group-0 it is 32'hFFFF_FFFF
   Group-1 to Group-15 it is 32'h000_0000 */
#define PERI_GROUP_PRESENT3_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_CLOCK_PRESENT 1u
/* Default value for SL_CTL register value on POR. Group-0 it is 32'hFFFF_FFFF
   Group-1 to Group-15 it is 32'h000_0000 */
#define PERI_GROUP_PRESENT4_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_CLOCK_PRESENT 0u
/* Default value for SL_CTL register value on POR. Group-0 it is 32'hFFFF_FFFF
   Group-1 to Group-15 it is 32'h000_0000 */
#define PERI_GROUP_PRESENT5_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Number of asynchronous PCLK groups */
#define PERI_PCLK_GROUP_NR              6u
/* Timeout functionality present ('0': no, '1': yes) */
#define PERI_TIMEOUT_PRESENT            1u
/* AHB ERROR response reporting present ('0': no, '1':yes) */
#define PERI_AHB_ERROR_PRESENT          1u
/* Trigger module present ('0': no, '1': yes) */
#define PERI_TR                         1u
/* Number of trigger groups */
#define PERI_TR_GROUP_NR                8u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR0_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR1_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR2_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR3_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR4_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR5_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR6_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR7_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Divider number width: max(1,roundup(log2(max(DIV_*_NR))) */
#define PERI_GR_DIV_ADDR_WIDTH          4u
/* Number of asynchronous PCLK groups */
#define PERI_PERI_PCLK_PCLK_GROUP_NR    6u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_24_5_VECT 1u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_CLOCK_VECT 1u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_8_VECT 1u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_VECT 4u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_CLOCK_VECT 5u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_8_VECT 1u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_VECT 2u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_5_VECT 4u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_24_5_VECT 1u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_CLOCK_VECT 12u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_VECT 1u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_5_VECT 2u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_CLOCK_VECT 4u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_PCLK_DIV_PRESENT 1u
/* Number of protection contexts supported. Legal range [3, 4, 6, 8] (CDT-336698) */
#define PERI_PPC_PC_NR                  8u
/* Security extension present ('0': no, '1': yes) */
#define PERI_PPC_SECEXT                 1u
/* Security Aware */
#define PERI_PPC_PPC_NR0_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR1_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR2_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR3_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR4_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR5_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR6_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR7_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR8_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR9_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR10_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR11_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR12_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR13_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR14_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR15_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR16_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR17_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR18_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR19_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR20_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR21_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR22_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR23_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR24_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR25_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR26_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR27_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR28_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR29_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR30_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR31_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR32_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR33_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR34_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR35_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR36_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR37_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR38_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR39_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR40_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR41_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR42_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR43_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR44_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR45_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR46_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR47_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR48_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR49_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR50_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR51_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR52_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR53_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR54_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR55_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR56_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR57_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR58_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR59_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR60_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR61_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR62_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR63_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR64_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR65_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR66_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR67_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR68_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR69_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR70_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR71_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR72_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR73_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR74_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR75_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR76_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR77_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR78_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR79_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR80_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR81_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR82_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR83_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR84_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR85_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR86_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR87_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR88_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR89_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR90_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR91_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR92_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR93_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR94_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR95_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR96_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR97_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR98_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR99_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR100_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR101_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR102_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR103_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR104_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR105_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR106_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR107_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR108_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR109_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR110_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR111_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR112_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR113_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR114_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR115_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR116_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR117_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR118_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR119_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR120_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR121_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR122_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR123_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR124_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR125_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR126_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR127_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR128_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR129_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR130_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR131_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR132_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR133_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR134_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR135_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR136_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR137_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR138_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR139_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR140_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR141_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR142_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR143_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR144_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR145_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR146_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR147_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR148_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR149_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR150_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR151_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR152_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR153_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR154_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR155_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR156_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR157_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR158_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR159_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR160_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR161_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR162_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR163_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR164_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR165_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR166_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR167_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR168_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR169_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR170_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR171_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR172_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR173_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR174_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR175_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR176_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR177_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR178_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR179_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR180_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR181_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR182_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR183_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR184_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR185_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR186_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR187_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR188_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR189_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR190_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR191_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR192_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR193_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR194_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR195_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR196_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR197_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR198_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR199_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR200_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR201_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR202_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR203_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR204_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR205_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR206_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR207_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR208_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR209_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR210_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR211_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR212_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR213_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR214_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR215_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR216_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR217_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR218_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR219_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR220_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR221_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR222_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR223_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR224_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR225_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR226_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR227_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR228_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR229_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR230_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR231_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR232_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR233_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR234_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR235_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR236_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR237_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR238_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR239_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR240_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR241_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR242_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR243_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR244_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR245_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR246_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR247_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR248_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR249_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR250_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR251_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR252_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR253_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR254_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR255_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR256_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR257_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR258_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR259_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR260_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR261_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR262_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR263_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR264_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR265_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR266_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR267_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR268_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR269_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR270_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR271_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR272_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR273_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR274_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR275_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR276_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR277_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR278_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR279_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR280_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR281_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR282_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR283_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR284_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR285_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR286_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR287_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR288_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR289_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR290_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR291_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR292_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR293_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR294_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR295_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR296_SECURITY_AWARE 0u
/* Number of input triggers per counter only routed to one counter (0..8) */
#define PPCA_TCPWM0_CNT_TR_ONE_CNT_NR   1u
/* Number of AHB5 "hmaster[]" bits ([1, 8]). */
#define PPCA_TCPWM0_TCPWM_MASTER_WIDTH  6u
/* Number of AHB5 "USER_WIDTH[]" bits([1,4]) */
#define PPCA_TCPWM0_TCPWM_USER_WIDTH    4u
/* Number of AHB5 "HPROT_WIDTH[] bits ([1,8]) */
#define PPCA_TCPWM0_TCPWM_HPROT_WIDTH   7u
/* Number of input triggers routed to all counters (0..254),
   TR_NR_ONE_CNT+TR_NR_ALL CNT <= 254 */
#define PPCA_TCPWM0_TCPWM_TR_ALL_CNT_NR 6u
/* Number of TCPWM counter groups (1..8) */
#define PPCA_TCPWM0_TCPWM_GRP_NR        3u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_GRP_CNT_WIDTH 32u
/* Second Capture / Compare Unit is present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_GRP_SMC_PRESENT 1u
/* Dithering Function is present (0,1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_GRP_DITHERING_PRESENT 0u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_TR_ONE_GF_NR 0u
/* Quadrature feature inside counter are present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_QUAD_PRESENT 0u
/* PWM_PR feature inside counter is present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_SR_PRESENT 0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_GRP_DATA_IN_CC_PRESENT 1u
/* HRPWM feature extension is available for counter group(0,1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_GRP_HRPWM_PRESENT 1u
/* HRPWM Fractional Resolution */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_CNT_GRP_HRPWM_WIDTH 6u
/* Number of counters per TCPWM group (1..256) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_GRP_GRP_CNT_NR 4u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_MOTIF_GRP_GRP_MOTIF_NR 0u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_MOTIF_GRP_GRP_MOTIF_TR_NR 0u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define PPCA_TCPWM0_TCPWM_GRP_NR0_TCPWM0_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 0u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_GRP_CNT_WIDTH 32u
/* Second Capture / Compare Unit is present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_GRP_SMC_PRESENT 1u
/* Dithering Function is present (0,1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_GRP_DITHERING_PRESENT 0u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_TR_ONE_GF_NR 0u
/* Quadrature feature inside counter are present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_QUAD_PRESENT 0u
/* PWM_PR feature inside counter is present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_SR_PRESENT 0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_GRP_DATA_IN_CC_PRESENT 0u
/* HRPWM feature extension is available for counter group(0,1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_GRP_HRPWM_PRESENT 1u
/* HRPWM Fractional Resolution */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_CNT_GRP_HRPWM_WIDTH 6u
/* Number of counters per TCPWM group (1..256) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_GRP_GRP_CNT_NR 4u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_MOTIF_GRP_GRP_MOTIF_NR 0u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_MOTIF_GRP_GRP_MOTIF_TR_NR 0u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define PPCA_TCPWM0_TCPWM_GRP_NR1_TCPWM0_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 0u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_GRP_SMC_PRESENT 1u
/* Dithering Function is present (0,1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_GRP_DITHERING_PRESENT 0u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_TR_ONE_GF_NR 0u
/* Quadrature feature inside counter are present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_QUAD_PRESENT 0u
/* PWM_PR feature inside counter is present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_SR_PRESENT 0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_GRP_DATA_IN_CC_PRESENT 0u
/* HRPWM feature extension is available for counter group(0,1) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_GRP_HRPWM_PRESENT 0u
/* HRPWM Fractional Resolution */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_CNT_GRP_HRPWM_WIDTH 0u
/* Number of counters per TCPWM group (1..256) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_GRP_GRP_CNT_NR 4u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_MOTIF_GRP_GRP_MOTIF_NR 1u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_MOTIF_GRP_GRP_MOTIF_TR_NR 0u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define PPCA_TCPWM0_TCPWM_GRP_NR2_TCPWM0_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 0u
/* Number of glitch filters routed to input triggers that are routed to all
   counters (0..254), TR_NR_ONE_CNT+TR_NR_ALL CNT <= 254 */
#define PPCA_TCPWM0_TR_ALL_GF_TR_ALL_GF_NR 0u
/* No of TR_ALL_SYNC_BYPASS register for group triggers. */
#define PPCA_TCPWM0_TR_ALL_SYNC_BYPASS_TR_ALL_SYNC_BYPASS_NR 1u
/* Number of input triggers per counter only routed to one counter (0..8) */
#define PPCA_TCPWM1_CNT_TR_ONE_CNT_NR   1u
/* Number of AHB5 "hmaster[]" bits ([1, 8]). */
#define PPCA_TCPWM1_TCPWM_MASTER_WIDTH  6u
/* Number of AHB5 "USER_WIDTH[]" bits([1,4]) */
#define PPCA_TCPWM1_TCPWM_USER_WIDTH    4u
/* Number of AHB5 "HPROT_WIDTH[] bits ([1,8]) */
#define PPCA_TCPWM1_TCPWM_HPROT_WIDTH   7u
/* Number of input triggers routed to all counters (0..254),
   TR_NR_ONE_CNT+TR_NR_ALL CNT <= 254 */
#define PPCA_TCPWM1_TCPWM_TR_ALL_CNT_NR 6u
/* Number of TCPWM counter groups (1..8) */
#define PPCA_TCPWM1_TCPWM_GRP_NR        3u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_GRP_CNT_WIDTH 32u
/* Second Capture / Compare Unit is present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_GRP_SMC_PRESENT 1u
/* Dithering Function is present (0,1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_GRP_DITHERING_PRESENT 0u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_TR_ONE_GF_NR 0u
/* Quadrature feature inside counter are present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_QUAD_PRESENT 0u
/* PWM_PR feature inside counter is present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_SR_PRESENT 0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_GRP_DATA_IN_CC_PRESENT 1u
/* HRPWM feature extension is available for counter group(0,1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_GRP_HRPWM_PRESENT 1u
/* HRPWM Fractional Resolution */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_CNT_GRP_HRPWM_WIDTH 6u
/* Number of counters per TCPWM group (1..256) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_GRP_GRP_CNT_NR 2u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_MOTIF_GRP_GRP_MOTIF_NR 0u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_MOTIF_GRP_GRP_MOTIF_TR_NR 0u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define PPCA_TCPWM1_TCPWM_GRP_NR0_TCPWM1_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 0u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_GRP_CNT_WIDTH 32u
/* Second Capture / Compare Unit is present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_GRP_SMC_PRESENT 1u
/* Dithering Function is present (0,1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_GRP_DITHERING_PRESENT 0u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_TR_ONE_GF_NR 0u
/* Quadrature feature inside counter are present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_QUAD_PRESENT 0u
/* PWM_PR feature inside counter is present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_SR_PRESENT 0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_GRP_DATA_IN_CC_PRESENT 0u
/* HRPWM feature extension is available for counter group(0,1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_GRP_HRPWM_PRESENT 1u
/* HRPWM Fractional Resolution */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_CNT_GRP_HRPWM_WIDTH 6u
/* Number of counters per TCPWM group (1..256) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_GRP_GRP_CNT_NR 2u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_MOTIF_GRP_GRP_MOTIF_NR 0u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_MOTIF_GRP_GRP_MOTIF_TR_NR 0u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define PPCA_TCPWM1_TCPWM_GRP_NR1_TCPWM1_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 0u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_GRP_SMC_PRESENT 1u
/* Dithering Function is present (0,1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_GRP_DITHERING_PRESENT 0u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_TR_ONE_GF_NR 0u
/* Quadrature feature inside counter are present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_QUAD_PRESENT 0u
/* PWM_PR feature inside counter is present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_SR_PRESENT 0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_GRP_DATA_IN_CC_PRESENT 0u
/* HRPWM feature extension is available for counter group(0,1) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_GRP_HRPWM_PRESENT 0u
/* HRPWM Fractional Resolution */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_CNT_GRP_HRPWM_WIDTH 0u
/* Number of counters per TCPWM group (1..256) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_GRP_GRP_CNT_NR 4u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_MOTIF_GRP_GRP_MOTIF_NR 1u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_MOTIF_GRP_GRP_MOTIF_TR_NR 0u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define PPCA_TCPWM1_TCPWM_GRP_NR2_TCPWM1_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 0u
/* Number of glitch filters routed to input triggers that are routed to all
   counters (0..254), TR_NR_ONE_CNT+TR_NR_ALL CNT <= 254 */
#define PPCA_TCPWM1_TR_ALL_GF_TR_ALL_GF_NR 0u
/* No of TR_ALL_SYNC_BYPASS register for group triggers. */
#define PPCA_TCPWM1_TR_ALL_SYNC_BYPASS_TR_ALL_SYNC_BYPASS_NR 1u
/* Number of input triggers per counter only routed to one counter (0..8) */
#define PPCA_TCPWM2_CNT_TR_ONE_CNT_NR   1u
/* Number of AHB5 "hmaster[]" bits ([1, 8]). */
#define PPCA_TCPWM2_TCPWM_MASTER_WIDTH  6u
/* Number of AHB5 "USER_WIDTH[]" bits([1,4]) */
#define PPCA_TCPWM2_TCPWM_USER_WIDTH    4u
/* Number of AHB5 "HPROT_WIDTH[] bits ([1,8]) */
#define PPCA_TCPWM2_TCPWM_HPROT_WIDTH   7u
/* Number of input triggers routed to all counters (0..254),
   TR_NR_ONE_CNT+TR_NR_ALL CNT <= 254 */
#define PPCA_TCPWM2_TCPWM_TR_ALL_CNT_NR 1u
/* Number of TCPWM counter groups (1..8) */
#define PPCA_TCPWM2_TCPWM_GRP_NR        1u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_GRP_SMC_PRESENT 1u
/* Dithering Function is present (0,1) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_GRP_DITHERING_PRESENT 0u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_TR_ONE_GF_NR 0u
/* Quadrature feature inside counter are present (0, 1) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_QUAD_PRESENT 0u
/* PWM_PR feature inside counter is present (0, 1) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_SR_PRESENT 0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_GRP_DATA_IN_CC_PRESENT 0u
/* HRPWM feature extension is available for counter group(0,1) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_GRP_HRPWM_PRESENT 0u
/* HRPWM Fractional Resolution */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_CNT_GRP_HRPWM_WIDTH 0u
/* Number of counters per TCPWM group (1..256) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_GRP_GRP_CNT_NR 4u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_MOTIF_GRP_GRP_MOTIF_NR 0u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_MOTIF_GRP_GRP_MOTIF_TR_NR 0u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define PPCA_TCPWM2_TCPWM_GRP_NR_TCPWM2_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 0u
/* Number of glitch filters routed to input triggers that are routed to all
   counters (0..254), TR_NR_ONE_CNT+TR_NR_ALL CNT <= 254 */
#define PPCA_TCPWM2_TR_ALL_GF_TR_ALL_GF_NR 0u
/* No of TR_ALL_SYNC_BYPASS register for group triggers. */
#define PPCA_TCPWM2_TR_ALL_SYNC_BYPASS_TR_ALL_SYNC_BYPASS_NR 1u
/* Number of input triggers per counter only routed to one counter (0..8) */
#define PPCA_TCPWM3_CNT_TR_ONE_CNT_NR   1u
/* Number of AHB5 "hmaster[]" bits ([1, 8]). */
#define PPCA_TCPWM3_TCPWM_MASTER_WIDTH  6u
/* Number of AHB5 "USER_WIDTH[]" bits([1,4]) */
#define PPCA_TCPWM3_TCPWM_USER_WIDTH    4u
/* Number of AHB5 "HPROT_WIDTH[] bits ([1,8]) */
#define PPCA_TCPWM3_TCPWM_HPROT_WIDTH   7u
/* Number of input triggers routed to all counters (0..254),
   TR_NR_ONE_CNT+TR_NR_ALL CNT <= 254 */
#define PPCA_TCPWM3_TCPWM_TR_ALL_CNT_NR 1u
/* Number of TCPWM counter groups (1..8) */
#define PPCA_TCPWM3_TCPWM_GRP_NR        1u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_GRP_SMC_PRESENT 1u
/* Dithering Function is present (0,1) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_GRP_DITHERING_PRESENT 0u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_TR_ONE_GF_NR 0u
/* Quadrature feature inside counter are present (0, 1) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_QUAD_PRESENT 0u
/* PWM_PR feature inside counter is present (0, 1) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_SR_PRESENT 0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_GRP_DATA_IN_CC_PRESENT 0u
/* HRPWM feature extension is available for counter group(0,1) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_GRP_HRPWM_PRESENT 0u
/* HRPWM Fractional Resolution */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_CNT_GRP_HRPWM_WIDTH 0u
/* Number of counters per TCPWM group (1..256) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_GRP_GRP_CNT_NR 2u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_MOTIF_GRP_GRP_MOTIF_NR 0u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_MOTIF_GRP_GRP_MOTIF_TR_NR 0u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define PPCA_TCPWM3_TCPWM_GRP_NR_TCPWM3_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 0u
/* Number of glitch filters routed to input triggers that are routed to all
   counters (0..254), TR_NR_ONE_CNT+TR_NR_ALL CNT <= 254 */
#define PPCA_TCPWM3_TR_ALL_GF_TR_ALL_GF_NR 0u
/* No of TR_ALL_SYNC_BYPASS register for group triggers. */
#define PPCA_TCPWM3_TR_ALL_SYNC_BYPASS_TR_ALL_SYNC_BYPASS_NR 1u
/* Number of System SRAM power partions */
#define RAMC0_PWR_GROUP_NR              1u
/* SRAM ECC present or not ('0': no, '1': yes) */
#define RAMC0_ECC_PRESENT               1u
#define RAMC0_MPC_MASTER_WIDTH          6u
#define RAMC0_MPC_PC_WIDTH              4u
#define RAMC0_MPC_PC_NR                 8u
#define RAMC0_MPC_BLK_IDX_MAX           0u
#define RAMC0_MPC_BLK_IDX_WIDTH         1u
#define RAMC0_MPC_EXT_PRESENT           0u
#define RAMC0_MPC_BLK_IDX_MAX_TIMES_FOUR_PLUS_THREE 3u
#define RAMC0_MPC_BLK_IDX_WIDTH_PLUS_TWO 3u
#define RAMC0_MPC_BLOCK_SIZE            6u
/* Number of System SRAM power partions */
#define RAMC1_PWR_GROUP_NR              1u
/* SRAM ECC present or not ('0': no, '1': yes) */
#define RAMC1_ECC_PRESENT               1u
#define RAMC1_MPC_MASTER_WIDTH          6u
#define RAMC1_MPC_PC_WIDTH              4u
#define RAMC1_MPC_PC_NR                 8u
#define RAMC1_MPC_BLK_IDX_MAX           0u
#define RAMC1_MPC_BLK_IDX_WIDTH         1u
#define RAMC1_MPC_EXT_PRESENT           0u
#define RAMC1_MPC_BLK_IDX_MAX_TIMES_FOUR_PLUS_THREE 3u
#define RAMC1_MPC_BLK_IDX_WIDTH_PLUS_TWO 3u
#define RAMC1_MPC_BLOCK_SIZE            6u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB0_DEEPSLEEP                  1u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB0_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB0_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB0_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB0_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB0_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB0_I2C_HS                     0u
/* Multiple slave address support enhancement from 1 to 2 ('0': no, '1': yes) */
#define SCB0_MSA_PRESENT                1u
/* Timeout generation support ('0': no, '1': yes) */
#define SCB0_TGS_PRESENT                1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB0_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB0_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB0_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB0_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB0_I2C_S_EC                   1u
/* I2C or I2C_S_EC support? (I2C | I2C_S_EC) */
#define SCB0_I2C_ALL                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB0_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB0_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB0_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB0_SPI_EC                     1u
/* SPI or SPI_S_EC support? (SPI | SPI_S_EC) */
#define SCB0_SPI_ALL                    1u
/* I2C or SPI or EC support? (I2C_ALL | SPI_ALL) */
#define SCB0_I2C_SPI_EC                 1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB0_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB0_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB0_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB0_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB0_CMD_RESP                   1u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB0_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB0_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB0_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB0_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB0_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB0_CHIP_TOP_SPI_SEL_NR        3u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB0_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB0_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB1_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB1_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB1_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB1_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB1_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB1_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB1_I2C_HS                     0u
/* Multiple slave address support enhancement from 1 to 2 ('0': no, '1': yes) */
#define SCB1_MSA_PRESENT                1u
/* Timeout generation support ('0': no, '1': yes) */
#define SCB1_TGS_PRESENT                1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB1_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB1_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB1_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB1_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB1_I2C_S_EC                   1u
/* I2C or I2C_S_EC support? (I2C | I2C_S_EC) */
#define SCB1_I2C_ALL                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB1_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB1_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB1_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB1_SPI_EC                     1u
/* SPI or SPI_S_EC support? (SPI | SPI_S_EC) */
#define SCB1_SPI_ALL                    1u
/* I2C or SPI or EC support? (I2C_ALL | SPI_ALL) */
#define SCB1_I2C_SPI_EC                 1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB1_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB1_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB1_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB1_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB1_CMD_RESP                   1u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB1_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB1_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB1_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB1_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB1_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB1_CHIP_TOP_SPI_SEL_NR        3u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB1_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB1_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB2_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB2_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB2_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB2_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB2_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB2_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB2_I2C_HS                     0u
/* Multiple slave address support enhancement from 1 to 2 ('0': no, '1': yes) */
#define SCB2_MSA_PRESENT                1u
/* Timeout generation support ('0': no, '1': yes) */
#define SCB2_TGS_PRESENT                1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB2_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB2_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB2_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB2_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB2_I2C_S_EC                   1u
/* I2C or I2C_S_EC support? (I2C | I2C_S_EC) */
#define SCB2_I2C_ALL                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB2_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB2_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB2_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB2_SPI_EC                     1u
/* SPI or SPI_S_EC support? (SPI | SPI_S_EC) */
#define SCB2_SPI_ALL                    1u
/* I2C or SPI or EC support? (I2C_ALL | SPI_ALL) */
#define SCB2_I2C_SPI_EC                 1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB2_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB2_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB2_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB2_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB2_CMD_RESP                   1u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB2_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB2_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB2_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB2_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB2_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB2_CHIP_TOP_SPI_SEL_NR        3u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB2_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB2_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB3_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB3_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB3_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB3_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB3_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB3_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB3_I2C_HS                     0u
/* Multiple slave address support enhancement from 1 to 2 ('0': no, '1': yes) */
#define SCB3_MSA_PRESENT                1u
/* Timeout generation support ('0': no, '1': yes) */
#define SCB3_TGS_PRESENT                1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB3_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB3_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB3_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB3_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB3_I2C_S_EC                   1u
/* I2C or I2C_S_EC support? (I2C | I2C_S_EC) */
#define SCB3_I2C_ALL                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB3_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB3_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB3_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB3_SPI_EC                     1u
/* SPI or SPI_S_EC support? (SPI | SPI_S_EC) */
#define SCB3_SPI_ALL                    1u
/* I2C or SPI or EC support? (I2C_ALL | SPI_ALL) */
#define SCB3_I2C_SPI_EC                 1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB3_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB3_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB3_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB3_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB3_CMD_RESP                   1u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB3_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB3_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB3_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB3_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB3_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB3_CHIP_TOP_SPI_SEL_NR        3u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB3_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB3_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB4_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB4_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB4_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB4_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB4_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB4_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB4_I2C_HS                     0u
/* Multiple slave address support enhancement from 1 to 2 ('0': no, '1': yes) */
#define SCB4_MSA_PRESENT                1u
/* Timeout generation support ('0': no, '1': yes) */
#define SCB4_TGS_PRESENT                1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB4_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB4_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB4_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB4_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB4_I2C_S_EC                   1u
/* I2C or I2C_S_EC support? (I2C | I2C_S_EC) */
#define SCB4_I2C_ALL                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB4_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB4_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB4_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB4_SPI_EC                     1u
/* SPI or SPI_S_EC support? (SPI | SPI_S_EC) */
#define SCB4_SPI_ALL                    1u
/* I2C or SPI or EC support? (I2C_ALL | SPI_ALL) */
#define SCB4_I2C_SPI_EC                 1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB4_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB4_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB4_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB4_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB4_CMD_RESP                   1u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB4_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB4_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB4_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB4_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB4_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB4_CHIP_TOP_SPI_SEL_NR        3u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB4_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB4_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB5_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB5_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB5_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB5_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB5_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB5_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB5_I2C_HS                     0u
/* Multiple slave address support enhancement from 1 to 2 ('0': no, '1': yes) */
#define SCB5_MSA_PRESENT                1u
/* Timeout generation support ('0': no, '1': yes) */
#define SCB5_TGS_PRESENT                1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB5_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB5_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB5_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB5_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB5_I2C_S_EC                   1u
/* I2C or I2C_S_EC support? (I2C | I2C_S_EC) */
#define SCB5_I2C_ALL                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB5_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB5_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB5_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB5_SPI_EC                     1u
/* SPI or SPI_S_EC support? (SPI | SPI_S_EC) */
#define SCB5_SPI_ALL                    1u
/* I2C or SPI or EC support? (I2C_ALL | SPI_ALL) */
#define SCB5_I2C_SPI_EC                 1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB5_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB5_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB5_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB5_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB5_CMD_RESP                   1u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB5_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB5_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB5_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB5_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB5_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB5_CHIP_TOP_SPI_SEL_NR        3u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB5_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB5_CHIP_TOP_DDFT_USED         4u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB6_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB6_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB6_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB6_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB6_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB6_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB6_I2C_HS                     0u
/* Multiple slave address support enhancement from 1 to 2 ('0': no, '1': yes) */
#define SCB6_MSA_PRESENT                1u
/* Timeout generation support ('0': no, '1': yes) */
#define SCB6_TGS_PRESENT                1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB6_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB6_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB6_I2C_M_HS                   0u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB6_I2C_S_HS                   0u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB6_I2C_S_EC                   1u
/* I2C or I2C_S_EC support? (I2C | I2C_S_EC) */
#define SCB6_I2C_ALL                    1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB6_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB6_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB6_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB6_SPI_EC                     1u
/* SPI or SPI_S_EC support? (SPI | SPI_S_EC) */
#define SCB6_SPI_ALL                    1u
/* I2C or SPI or EC support? (I2C_ALL | SPI_ALL) */
#define SCB6_I2C_SPI_EC                 1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB6_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB6_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB6_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB6_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB6_CMD_RESP                   1u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB6_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB6_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB6_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB6_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB6_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB6_CHIP_TOP_SPI_SEL_NR        3u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB6_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB6_CHIP_TOP_DDFT_USED         4u
/* SONOS Flash is used or not ('0': no, '1': yes) */
#define SFLASH_FLASHC_IS_SONOS          1u
/* RAM_VEND_PRESENT or not ('0': no, '1': yes) */
#define SFLASH_RAM_VEND_PRESENT         1u
/* CPUSS_WOUNDING_PRESENT or not ('0': no, '1': yes) */
#define SFLASH_CPUSS_WOUNDING_PRESENT   1u
/* WOUND_PRESENT or not ('0': no, '1': yes) */
#define SFLASH_WOUND_PRESENT            1u
/* S40S variant. Must be 1 when targeting S40S and 0 otherwise. */
#define SRSS_S40S_VARIANT               1u
/* S40E variant. Must be 1 when targeting S40E and 0 otherwise. */
#define SRSS_S40E_VARIANT               0u
/* Number of regulator modules instantiated within SRSS. Must be > 0. */
#define SRSS_NUM_ACTREG_PWRMOD          4u
/* Number of shorting switches between vccd and vccact. Must be > 0. */
#define SRSS_NUM_ACTIVE_SWITCH          4u
/* S40S variant. Number of shorting switches between vccd and vccdplsp for S40S
   REGSETB. Must be > 0. Has no affect when S40S_REGSETB_PRESENT=0 */
#define SRSS_NUM_DPSLP_SWITCH           5u
/* S40S Regulator Set A system is present */
#define SRSS_S40S_REGSETA_PRESENT       1u
/* S40E Regulator Set A system is present */
#define SRSS_S40E_REGSETA_PRESENT       0u
/* SIMO buck core regulator is present. Only compatible with S40S linear regulator
   system (S40S_REGSETA_PRESENT==1). */
#define SRSS_S40S_SIMOBUCK_PRESENT      0u
/* Precision ILO (PILO) is present */
#define SRSS_S40S_PILO_PRESENT          0u
/* External Crystal Oscillator is present (high frequency) */
#define SRSS_ECO_PRESENT                1u
/* Number of clock paths. Must be > 0. Recommend
   NUM_CLKPATH>=NUM_TOTAL_PLL+CSV_PRESENT+2. CSV and FLL requires special paths,
   and one extra is recommended for programming flexibility. */
#define SRSS_NUM_CLKPATH                7u
/* Number of 200MHz PLLs present. */
#define SRSS_NUM_PLL200M                0u
/* Number of 250MHz Digital PLLs present. */
#define SRSS_NUM_DPLL250                2u
/* Number of HFCLK roots present. Must be > 0. Recommend NUM_HFROOT=<# chipwide
   roots>+CSV_PRESENT. */
#define SRSS_NUM_HFROOT                 7u
/* Number of PWR_HIB_DATA registers. Min is zero. */
#define SRSS_NUM_HIBDATA                0u
/* Backup domain is present. See VBCK_PRESENT for whether it is supplied by vddd
   or by an independent vbackup supply. */
#define SRSS_BACKUP_PRESENT             1u
/* CSV present. User must add one NUM_CLKPATH and one NUM_HFROOT to monitor ILO0
   with CSV_HF_REF clock. */
#define SRSS_CSV_PRESENT                1u
/* Number of multi-counter watchdog timers (type A). Min is zero. If backward
   compatibility is not needed, it is recommended to use type B instead. */
#define SRSS_NUM_MCWDT                  1u
/* Number of DSI inputs into clock muxes. This is used for logic optimization.
   Must be > 0 */
#define SRSS_NUM_DSI                    0u
/* Alternate high-frequency clock is present. This is used for logic optimization. */
#define SRSS_ALTHF_PRESENT              0u
/* Alternate low-frequency clock is present. This is used for logic optimization. */
#define SRSS_ALTLF_PRESENT              0u
/* Use the hardened clkactfllmux block */
#define SRSS_USE_HARD_CLKACTFLLMUX      1u
/* Number of clock paths, including direct paths in hardened clkactfllmux block */
#define SRSS_HARD_CLKPATH               8u
/* Number of clock paths with muxes in hardened clkactfllmux block */
#define SRSS_HARD_CLKPATHMUX            8u
/* Number of HFCLKS present in hardened clkactfllmux block */
#define SRSS_HARD_HFROOT                8u
/* ECO mux is present in hardened clkactfllmux block */
#define SRSS_HARD_ECOMUX_PRESENT        1u
/* ALTHF mux is present in hardened clkactfllmux block */
#define SRSS_HARD_ALTHFMUX_PRESENT      1u
/* POR present. */
#define SRSS_POR_PRESENT                0u
/* Low-current buck regulator present. Can be derived from
   S40S_SISOBUCKLC_PRESENT, S40S_SISOBUCKMC_PRESENT or S40S_SIMOBUCK_PRESENT. */
#define SRSS_BUCKCTL_PRESENT            0u
/* Low-current SISO buck core regulator is present. Only compatible with S40S
   linear regulator system (S40S_REGSETA_PRESENT==1). */
#define SRSS_S40S_SISOBUCKLC_PRESENT    0u
/* S40E linear regulator system is present */
#define SRSS_S40E_REGHC_PRESENT         0u
/* LPECO mux is present in hardened clkactfllmux block */
#define SRSS_HARD_LPECOMUX_PRESENT      1u
/* Number of 400MHz PLLs present. */
#define SRSS_NUM_PLL400M                0u
/* Mask of DIRECT_MUX defaults. For each clock root i, if bit[i] is low the
   DIRECT_MUX defaults to IMO. If bit[0] is high, the DIRECT_MUX selects the
   output of ROOT_MUX. For backward compatibility, M33-only systems can have all
   mask bits high. In all cases, must have bit[0]==1 to start the chip. */
#define SRSS_MASK_DIRECTMUX_DEF         0x0000FFFFu
/* Mask of which HFCLK roots are enabled when the debugger requests power up
   (CDBGPWRUPREQ). For each clock root i, SRSS enables the clock in response to
   CDBGPWRUPREQ, if bit[i] of mask is high. SRSS automatically enables clk_hf0,
   regardless of setting of mask bit0. */
#define SRSS_MASK_DEBUG_CLK             9u
/* Total number of PLLs present. */
#define SRSS_NUM_TOTAL_PLL              2u
/* PMIC control of vccd is present (without REGHC). */
#define SRSS_S40E_PMIC_PRESENT          0u
/* Number of multi-counter watchdog timers (type B). Software incompatibility with
   type A. */
#define SRSS_NUM_MCWDT_B                0u
/* WDT type A is present (backward compatible version) */
#define SRSS_WDT_A_PRESENT              1u
/* WDT type B is present. Software incompatibility with type A. */
#define SRSS_WDT_B_PRESENT              0u
/* Medium-current SISO buck core regulator is present. Only compatible with S40S
   linear regulator system (S40S_REGSETA_PRESENT==1). */
#define SRSS_S40S_SISOBUCKMC_PRESENT    0u
/* Mask for whether a PD is present in the PDCM. The zeroth bit is the PD
   controlled by the main PPU and must always be set. */
#define SRSS_PDCM_PD_PRESENT            511u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT0_PDCM_PD_DEFAULT_ON 510u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT0_PDCM_PD_CONFIG_ON 1u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT1_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT1_PDCM_PD_CONFIG_ON 2u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT2_PDCM_PD_DEFAULT_ON 2u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT2_PDCM_PD_CONFIG_ON 6u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT3_PDCM_PD_DEFAULT_ON 2u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT3_PDCM_PD_CONFIG_ON 10u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT4_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT4_PDCM_PD_CONFIG_ON 16u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT5_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT5_PDCM_PD_CONFIG_ON 32u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT6_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT6_PDCM_PD_CONFIG_ON 64u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT7_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT7_PDCM_PD_CONFIG_ON 128u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT8_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT8_PDCM_PD_CONFIG_ON 256u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT9_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT9_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT10_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT10_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT11_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT11_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT12_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT12_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT13_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT13_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT14_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT14_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT15_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT15_PDCM_PD_CONFIG_ON 0u
/* FLL present */
#define SRSS_FLL_PRESENT                1u
/* S40S Regulator Set B system is present */
#define SRSS_S40S_REGSETB_PRESENT       0u
/* S40S Regulator Set B Nwell regulator is present */
#define SRSS_S40S_REGSETB_NW_PRESENT    0u
/* Number of additional HIBERNATE wakeup sources */
#define SRSS_NUM_HIB_WAKE               4u
/* CSV_BAK is present. Monitors clk_bak_hv using clk_ilo0_hv. */
#define SRSS_CSV_BAK_PRESENT            0u
/* HVLDO0 present */
#define SRSS_S40S_REGSETB_HVLDO0_PRESENT 0u
/* Width of the WDT (Type A) counter. For backward compatibility, the minimum
   allowed is 16b. */
#define SRSS_NUM_WDT_A_BITS             32u
/* This defines the default value of the SRAM trim register. */
#define SRSS_TRIM_DEFAULT               0x00004013u
/* This defines the default value of the ROM trim register. */
#define SRSS_TRIM_ROM_DEFAULT           19u
/* Separate power supply Vbackup is present (only used when BACKUP_PRESENT==1) */
#define SRSS_BACKUP_VBCK_PRESENT        1u
/* Alarm1 present in RTC */
#define SRSS_BACKUP_ALM1_PRESENT        1u
/* Alarm2 present in RTC */
#define SRSS_BACKUP_ALM2_PRESENT        1u
/* Backup memory is present (only used when BACKUP_PRESENT==1) */
#define SRSS_BACKUP_BMEM_PRESENT        0u
/* Number of Backup registers to include (each is 32b). Only used when
   BACKUP_PRESENT==1. Approximate size is 850squm per register. */
#define SRSS_BACKUP_NUM_BREG0           4u
/* Number of Backup registers to include (each is 32b). Only used when
   BACKUP_PRESENT==1. Approximate size is 850squm per register. */
#define SRSS_BACKUP_NUM_BREG1           4u
/* Number of Backup registers to include (each is 32b). Only used when
   BACKUP_PRESENT==1. Approximate size is 850squm per register. */
#define SRSS_BACKUP_NUM_BREG2           8u
/* Number of Backup registers to include (each is 32b). Only used when
   BACKUP_PRESENT==1. Approximate size is 850squm per register. */
#define SRSS_BACKUP_NUM_BREG3           16u
/* Low power external crystal oscillator (LPECO) is present. */
#define SRSS_BACKUP_S40E_LPECO_PRESENT  0u
/* CSV_BAK is present. Monitors clk_bak_hv using clk_ilo0_hv. */
#define SRSS_BACKUP_CSV_BAK_PRESENT     0u
/* S40S variant. Must be 1 when targeting S40S and 0 otherwise. */
#define SRSS_CLK_TRIM_PLL400M_S40S_VARIANT 1u
/* Mask of HFCLK root clock supervisors (CSV). For each clock root i, bit[i] of
   mask indicates presence of a CSV. */
#define SRSS_CSV_HF_MASK_HFCSV          127u
/* Number of AHB5 "hmaster[]" bits ([1, 8]). */
#define TCPWM_MASTER_WIDTH              6u
/* Number of AHB5 "USER_WIDTH[]" bits([1,4]. */
#define TCPWM_USER_WIDTH                4u
/* Number of AHB5 "HPROT_WIDTH[] bits ([1,8]) */
#define TCPWM_HPROT_WIDTH               7u
/* Number of input triggers routed to all counters (0..254),
   NR_TR_ONE_CNT+NR_TR_ALL CNT <= 254 */
#define TCPWM_TR_ALL_CNT_NR             6u
/* Number of TCPWM counter groups (1..8) */
#define TCPWM_GRP_NR                    2u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR0_CNT_GRP_CNT_WIDTH 32u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR0_CNT_GRP_CC1_PRESENT 0u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR0_CNT_GRP_AMC_PRESENT 0u
/* Stepper Motor Control features are present (0, 1) */
#define TCPWM_GRP_NR0_CNT_GRP_SMC_PRESENT 0u
/* Dithering Function is present (0,1) */
#define TCPWM_GRP_NR0_CNT_GRP_DITHERING_PRESENT 0u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define TCPWM_GRP_NR0_CNT_TR_ONE_GF_NR  0u
/* Quadrature feature inside counter are present (0, 1) */
#define TCPWM_GRP_NR0_CNT_QUAD_PRESENT  0u
/* PWM_PR feature inside counter is present (0, 1) */
#define TCPWM_GRP_NR0_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define TCPWM_GRP_NR0_CNT_SR_PRESENT    0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define TCPWM_GRP_NR0_CNT_GRP_DATA_IN_CC_PRESENT 0u
/* HRPWM feature extension is available for counter group(0,1) */
#define TCPWM_GRP_NR0_CNT_GRP_HRPWM_PRESENT 0u
/* Number of micro ticks bits supported in HRPWM feature (2,3,4,5,6,7,8) */
#define TCPWM_GRP_NR0_CNT_GRP_HRPWM_WIDTH 0u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR0_GRP_GRP_CNT_NR    2u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define TCPWM_GRP_NR0_MOTIF_GRP_GRP_MOTIF_NR 0u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define TCPWM_GRP_NR0_MOTIF_GRP_GRP_MOTIF_TR_NR 0u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define TCPWM_GRP_NR0_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 0u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR1_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR1_CNT_GRP_CC1_PRESENT 0u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR1_CNT_GRP_AMC_PRESENT 0u
/* Stepper Motor Control features are present (0, 1) */
#define TCPWM_GRP_NR1_CNT_GRP_SMC_PRESENT 0u
/* Dithering Function is present (0,1) */
#define TCPWM_GRP_NR1_CNT_GRP_DITHERING_PRESENT 0u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define TCPWM_GRP_NR1_CNT_TR_ONE_GF_NR  0u
/* Quadrature feature inside counter are present (0, 1) */
#define TCPWM_GRP_NR1_CNT_QUAD_PRESENT  0u
/* PWM_PR feature inside counter is present (0, 1) */
#define TCPWM_GRP_NR1_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define TCPWM_GRP_NR1_CNT_SR_PRESENT    0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define TCPWM_GRP_NR1_CNT_GRP_DATA_IN_CC_PRESENT 0u
/* HRPWM feature extension is available for counter group(0,1) */
#define TCPWM_GRP_NR1_CNT_GRP_HRPWM_PRESENT 0u
/* Number of micro ticks bits supported in HRPWM feature (2,3,4,5,6,7,8) */
#define TCPWM_GRP_NR1_CNT_GRP_HRPWM_WIDTH 0u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR1_GRP_GRP_CNT_NR    2u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define TCPWM_GRP_NR1_MOTIF_GRP_GRP_MOTIF_NR 0u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define TCPWM_GRP_NR1_MOTIF_GRP_GRP_MOTIF_TR_NR 0u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define TCPWM_GRP_NR1_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 0u
/* Number of input triggers per counter only routed to one counter (0..8) */
#define TCPWM_CNT_TR_ONE_CNT_NR         1u
/* Number of glitch filters routed to input triggers that are routed to all
   counters (0..254), NR_TR_ONE_CNT+NR_TR_ALL CNT <= 254 */
#define TCPWM_TR_ALL_GF_TR_ALL_GF_NR    0u
/* No of TR_ALL_SYNC_BYPASS register for group triggers. */
#define TCPWM_TR_ALL_SYNC_BYPASS_TR_ALL_SYNC_BYPASS_NR 1u

/* MMIO Targets Defines */
/* MMIO0.SRSS */
#define CY_MMIO_SRSS_GROUP_NR           0u
#define CY_MMIO_SRSS_SLAVE_NR           4u
/* MMIO0.PWRMODE */
#define CY_MMIO_PWRMODE_GROUP_NR        0u
#define CY_MMIO_PWRMODE_SLAVE_NR        5u
/* MMIO0.BACKUP */
#define CY_MMIO_BACKUP_GROUP_NR         0u
#define CY_MMIO_BACKUP_SLAVE_NR         6u
/* MMIO0.CRYPTOLITE */
#define CY_MMIO_CRYPTOLITE_GROUP_NR     0u
#define CY_MMIO_CRYPTOLITE_SLAVE_NR     7u
/* MMIO0.MXWOUND */
#define CY_MMIO_MXWOUND_GROUP_NR        0u
#define CY_MMIO_MXWOUND_SLAVE_NR        8u
/* MMIO0.DEBUG600 */
#define CY_MMIO_DEBUG600_GROUP_NR       0u
#define CY_MMIO_DEBUG600_SLAVE_NR       9u
/* MMIO0.SVGS */
#define CY_MMIO_SVGS_GROUP_NR           0u
#define CY_MMIO_SVGS_SLAVE_NR           10u
/* MMIO0.MXAES */
#define CY_MMIO_MXAES_GROUP_NR          0u
#define CY_MMIO_MXAES_SLAVE_NR          11u
/* MMIO1.HSIOM */
#define CY_MMIO_HSIOM_GROUP_NR          1u
#define CY_MMIO_HSIOM_SLAVE_NR          0u
/* MMIO1.GPIO */
#define CY_MMIO_GPIO_GROUP_NR           1u
#define CY_MMIO_GPIO_SLAVE_NR           1u
/* MMIO1.LPCOMP */
#define CY_MMIO_LPCOMP_GROUP_NR         1u
#define CY_MMIO_LPCOMP_SLAVE_NR         2u
/* MMIO1.TCPWM0 */
#define CY_MMIO_TCPWM0_GROUP_NR         1u
#define CY_MMIO_TCPWM0_SLAVE_NR         3u
/* MMIO2.DFT */
#define CY_MMIO_DFT_GROUP_NR            2u
#define CY_MMIO_DFT_SLAVE_NR            0u
/* MMIO2.EFUSE */
#define CY_MMIO_EFUSE_GROUP_NR          2u
#define CY_MMIO_EFUSE_SLAVE_NR          1u
/* MMIO3.CANFD0 */
#define CY_MMIO_CANFD0_GROUP_NR         3u
#define CY_MMIO_CANFD0_SLAVE_NR         0u
/* MMIO3.SCB0 */
#define CY_MMIO_SCB0_GROUP_NR           3u
#define CY_MMIO_SCB0_SLAVE_NR           1u
/* MMIO3.SCB1 */
#define CY_MMIO_SCB1_GROUP_NR           3u
#define CY_MMIO_SCB1_SLAVE_NR           2u
/* MMIO3.SCB2 */
#define CY_MMIO_SCB2_GROUP_NR           3u
#define CY_MMIO_SCB2_SLAVE_NR           3u
/* MMIO3.SCB3 */
#define CY_MMIO_SCB3_GROUP_NR           3u
#define CY_MMIO_SCB3_SLAVE_NR           4u
/* MMIO3.SCB4 */
#define CY_MMIO_SCB4_GROUP_NR           3u
#define CY_MMIO_SCB4_SLAVE_NR           5u
/* MMIO4.PPCA */
#define CY_MMIO_PPCA_GROUP_NR           4u
#define CY_MMIO_PPCA_SLAVE_NR           0u
/* MMIO5.SCB5 */
#define CY_MMIO_SCB5_GROUP_NR           5u
#define CY_MMIO_SCB5_SLAVE_NR           0u
/* MMIO5.SCB6 */
#define CY_MMIO_SCB6_GROUP_NR           5u
#define CY_MMIO_SCB6_SLAVE_NR           1u

/* Protection regions */
typedef enum
{
    PROT_START                      =   0,
    PROT_PERI0_MAIN                 =   0,      /* Address 0x42000000, size 0x00004000 */
    PROT_PERI0_GR0_GROUP            =   1,      /* Address 0x42004010, size 0x00000008 */
    PROT_PERI0_GR1_GROUP            =   2,      /* Address 0x42004040, size 0x00000020 */
    PROT_PERI0_GR2_GROUP            =   3,      /* Address 0x42004080, size 0x00000020 */
    PROT_PERI0_GR3_GROUP            =   4,      /* Address 0x420040c0, size 0x00000020 */
    PROT_PERI0_GR4_GROUP            =   5,      /* Address 0x42004100, size 0x00000020 */
    PROT_PERI0_GR5_GROUP            =   6,      /* Address 0x42004150, size 0x00000008 */
    PROT_PERI0_GR0_BOOT             =   7,      /* Address 0x42004020, size 0x00000004 */
    PROT_PERI0_GR1_BOOT             =   8,      /* Address 0x42004060, size 0x00000004 */
    PROT_PERI0_GR2_BOOT             =   9,      /* Address 0x420040a0, size 0x00000004 */
    PROT_PERI0_GR3_BOOT             =  10,      /* Address 0x420040e0, size 0x00000004 */
    PROT_PERI0_GR4_BOOT             =  11,      /* Address 0x42004120, size 0x00000004 */
    PROT_PERI0_GR5_BOOT             =  12,      /* Address 0x42004160, size 0x00000004 */
    PROT_PERI0_TR                   =  13,      /* Address 0x42008000, size 0x00008000 */
    PROT_PPC0_PPC_PPC_SECURE        =  14,      /* Address 0x42020000, size 0x00004000 */
    PROT_PPC0_PPC_PPC_NONSECURE     =  15,      /* Address 0x42024000, size 0x00004000 */
    PROT_PERI_PCLK0_MAIN            =  16,      /* Address 0x42040000, size 0x00010000 */
    PROT_CPUSS                      =  17,      /* Address 0x42100000, size 0x00010000 */
    PROT_RAMC0_CM33                 =  18,      /* Address 0x42110000, size 0x00000040 */
    PROT_RAMC1_CM33                 =  19,      /* Address 0x42120000, size 0x00000040 */
    PROT_RAMC0_BOOT                 =  20,      /* Address 0x42110100, size 0x00000008 */
    PROT_RAMC1_BOOT                 =  21,      /* Address 0x42120100, size 0x00000008 */
    PROT_RAMC0_RAM_PWR              =  22,      /* Address 0x42110200, size 0x00000100 */
    PROT_RAMC1_RAM_PWR              =  23,      /* Address 0x42120200, size 0x00000100 */
    PROT_RAMC0_MPC0_PPC_MPC_MAIN    =  24,      /* Address 0x42114000, size 0x00000004 */
    PROT_RAMC1_MPC0_PPC_MPC_MAIN    =  25,      /* Address 0x42124000, size 0x00000004 */
    PROT_RAMC0_MPC0_PPC_MPC_PC      =  26,      /* Address 0x42114100, size 0x00000020 */
    PROT_RAMC1_MPC0_PPC_MPC_PC      =  27,      /* Address 0x42124100, size 0x00000020 */
    PROT_RAMC0_MPC0_PPC_MPC_ROT     =  28,      /* Address 0x42114200, size 0x00000020 */
    PROT_RAMC1_MPC0_PPC_MPC_ROT     =  29,      /* Address 0x42124200, size 0x00000020 */
    PROT_PROMC_CM33                 =  30,      /* Address 0x42140000, size 0x00000004 */
    PROT_PROMC_MPC0_PPC_MPC_MAIN    =  31,      /* Address 0x42141000, size 0x00000004 */
    PROT_PROMC_MPC0_PPC_MPC_PC      =  32,      /* Address 0x42141100, size 0x00000020 */
    PROT_PROMC_MPC0_PPC_MPC_ROT     =  33,      /* Address 0x42141200, size 0x00000020 */
    PROT_FLASHC_BOOT                =  34,      /* Address 0x42150000, size 0x00000008 */
    PROT_FLASHC_BOOT1               =  35,      /* Address 0x42150100, size 0x00000020 */
    PROT_FLASHC_MAIN                =  36,      /* Address 0x42150200, size 0x00000010 */
    PROT_FLASHC_DFT                 =  37,      /* Address 0x42150400, size 0x00000080 */
    PROT_FLASHC_ECC                 =  38,      /* Address 0x42150800, size 0x00000010 */
    PROT_FLASHC_MPC0_PPC_MPC_MAIN   =  39,      /* Address 0x42151000, size 0x00000004 */
    PROT_FLASHC_MPC0_PPC_MPC_PC     =  40,      /* Address 0x42151100, size 0x00000020 */
    PROT_FLASHC_MPC0_PPC_MPC_ROT    =  41,      /* Address 0x42151200, size 0x00000020 */
    PROT_FLASHC_FM_CTL_FM_DFT       =  42,      /* Address 0x42152000, size 0x00000004 */
    PROT_FLASHC_FM_CTL_FM_BOOT      =  43,      /* Address 0x42152040, size 0x00000008 */
    PROT_FLASHC_FM_CTL_FM_MAIN      =  44,      /* Address 0x42152800, size 0x00000800 */
    PROT_MXCM33_CM33                =  45,      /* Address 0x42160000, size 0x00000100 */
    PROT_MXCM33_CM33_S              =  46,      /* Address 0x42161000, size 0x00000004 */
    PROT_MXCM33_CM33_NS             =  47,      /* Address 0x42161004, size 0x00000004 */
    PROT_MXCM33_BOOT_PC0            =  48,      /* Address 0x42162000, size 0x00000080 */
    PROT_MXCM33_BOOT_PC1            =  49,      /* Address 0x42162100, size 0x00000004 */
    PROT_MXCM33_BOOT_PC2            =  50,      /* Address 0x42162140, size 0x00000004 */
    PROT_MXCM33_BOOT_PC3            =  51,      /* Address 0x42162180, size 0x00000004 */
    PROT_MXCM33_BOOT                =  52,      /* Address 0x421621c0, size 0x00000004 */
    PROT_MXCM33_CM33_INT            =  53,      /* Address 0x42168000, size 0x00000400 */
    PROT_DW0_DW                     =  54,      /* Address 0x42180000, size 0x00000080 */
    PROT_DW0_DW_CRC                 =  55,      /* Address 0x42180100, size 0x00000080 */
    PROT_DW0_CH_STRUCT0_CH          =  56,      /* Address 0x42188000, size 0x00000040 */
    PROT_DW0_CH_STRUCT1_CH          =  57,      /* Address 0x42188040, size 0x00000040 */
    PROT_DW0_CH_STRUCT2_CH          =  58,      /* Address 0x42188080, size 0x00000040 */
    PROT_DW0_CH_STRUCT3_CH          =  59,      /* Address 0x421880c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT4_CH          =  60,      /* Address 0x42188100, size 0x00000040 */
    PROT_DW0_CH_STRUCT5_CH          =  61,      /* Address 0x42188140, size 0x00000040 */
    PROT_DW0_CH_STRUCT6_CH          =  62,      /* Address 0x42188180, size 0x00000040 */
    PROT_DW0_CH_STRUCT7_CH          =  63,      /* Address 0x421881c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT8_CH          =  64,      /* Address 0x42188200, size 0x00000040 */
    PROT_DW0_CH_STRUCT9_CH          =  65,      /* Address 0x42188240, size 0x00000040 */
    PROT_DW0_CH_STRUCT10_CH         =  66,      /* Address 0x42188280, size 0x00000040 */
    PROT_DW0_CH_STRUCT11_CH         =  67,      /* Address 0x421882c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT12_CH         =  68,      /* Address 0x42188300, size 0x00000040 */
    PROT_DW0_CH_STRUCT13_CH         =  69,      /* Address 0x42188340, size 0x00000040 */
    PROT_DW0_CH_STRUCT14_CH         =  70,      /* Address 0x42188380, size 0x00000040 */
    PROT_DW0_CH_STRUCT15_CH         =  71,      /* Address 0x421883c0, size 0x00000040 */
    PROT_CPUSS_ALL_PC               =  72,      /* Address 0x421c0000, size 0x00000080 */
    PROT_CPUSS_DDFT                 =  73,      /* Address 0x421c0080, size 0x00000004 */
    PROT_CPUSS_CM33_S               =  74,      /* Address 0x421c0100, size 0x00000004 */
    PROT_CPUSS_CM33_NS              =  75,      /* Address 0x421c0120, size 0x00000004 */
    PROT_CPUSS_MSC_INT              =  76,      /* Address 0x421c0200, size 0x00000010 */
    PROT_CPUSS_AP                   =  77,      /* Address 0x421c1000, size 0x00000004 */
    PROT_CPUSS_BOOT                 =  78,      /* Address 0x421c2000, size 0x00000008 */
    PROT_MS0_MAIN                   =  79,      /* Address 0x421c4000, size 0x00000004 */
    PROT_MS4_MAIN                   =  80,      /* Address 0x421c4040, size 0x00000004 */
    PROT_MS7_MAIN                   =  81,      /* Address 0x421c4070, size 0x00000004 */
    PROT_MS9_MAIN                   =  82,      /* Address 0x421c4090, size 0x00000004 */
    PROT_MS31_MAIN                  =  83,      /* Address 0x421c41f0, size 0x00000004 */
    PROT_MS_PC0_PRIV                =  84,      /* Address 0x421c5000, size 0x00000004 */
    PROT_MS_PC9_PRIV                =  85,      /* Address 0x421c5090, size 0x00000004 */
    PROT_MS_PC31_PRIV               =  86,      /* Address 0x421c51f0, size 0x00000004 */
    PROT_MS_PC0_PRIV_MIR            =  87,      /* Address 0x421c5004, size 0x00000004 */
    PROT_MS_PC9_PRIV_MIR            =  88,      /* Address 0x421c5094, size 0x00000004 */
    PROT_MS_PC31_PRIV_MIR           =  89,      /* Address 0x421c51f4, size 0x00000004 */
    PROT_MSC_ACG                    =  90,      /* Address 0x421c6000, size 0x00000040 */
    PROT_CPUSS_SL_CTL_GROUP         =  91,      /* Address 0x421c8000, size 0x00000008 */
    PROT_IPC_STRUCT0_IPC            =  92,      /* Address 0x421d0000, size 0x00000020 */
    PROT_IPC_STRUCT1_IPC            =  93,      /* Address 0x421d0020, size 0x00000020 */
    PROT_IPC_STRUCT2_IPC            =  94,      /* Address 0x421d0040, size 0x00000020 */
    PROT_IPC_STRUCT3_IPC            =  95,      /* Address 0x421d0060, size 0x00000020 */
    PROT_IPC_STRUCT4_IPC            =  96,      /* Address 0x421d0080, size 0x00000020 */
    PROT_IPC_STRUCT5_IPC            =  97,      /* Address 0x421d00a0, size 0x00000020 */
    PROT_IPC_STRUCT6_IPC            =  98,      /* Address 0x421d00c0, size 0x00000020 */
    PROT_IPC_STRUCT7_IPC            =  99,      /* Address 0x421d00e0, size 0x00000020 */
    PROT_IPC_INTR_STRUCT0_INTR      = 100,      /* Address 0x421d1000, size 0x00000010 */
    PROT_IPC_INTR_STRUCT1_INTR      = 101,      /* Address 0x421d1020, size 0x00000010 */
    PROT_IPC_INTR_STRUCT2_INTR      = 102,      /* Address 0x421d1040, size 0x00000010 */
    PROT_IPC_INTR_STRUCT3_INTR      = 103,      /* Address 0x421d1060, size 0x00000010 */
    PROT_FAULT_STRUCT0_MAIN         = 104,      /* Address 0x421e0000, size 0x00000100 */
    PROT_SRSS_GENERAL               = 105,      /* Address 0x42200000, size 0x00000400 */
    PROT_SRSS_GENERAL2              = 106,      /* Address 0x42200400, size 0x00000040 */
    PROT_SRSS_HIB_DATA              = 107,      /* Address 0x422008a0, size 0x00000010 */
    PROT_SRSS_MAIN                  = 108,      /* Address 0x42201000, size 0x00001000 */
    PROT_SRSS_SECURE                = 109,      /* Address 0x42202000, size 0x00002000 */
    PROT_RAM_TRIM_SRSS_SRAM         = 110,      /* Address 0x42204000, size 0x00000008 */
    PROT_SRSS_DPLL                  = 111,      /* Address 0x42204200, size 0x00000040 */
    PROT_SRSS_WDT                   = 112,      /* Address 0x4220c000, size 0x00000010 */
    PROT_MAIN                       = 113,      /* Address 0x4220d000, size 0x00000040 */
    PROT_PWRMODE_PWRMODE            = 114,      /* Address 0x42210000, size 0x00004000 */
    PROT_BACKUP_BACKUP              = 115,      /* Address 0x42220000, size 0x00000100 */
    PROT_BACKUP_B_BREG0             = 116,      /* Address 0x42221000, size 0x00000010 */
    PROT_BACKUP_B_BREG1             = 117,      /* Address 0x42221010, size 0x00000010 */
    PROT_BACKUP_B_BREG2             = 118,      /* Address 0x42221020, size 0x00000020 */
    PROT_BACKUP_B_BREG3             = 119,      /* Address 0x42221080, size 0x00000040 */
    PROT_BACKUP_BACKUP_SECURE       = 120,      /* Address 0x4222ff00, size 0x00000004 */
    PROT_CRYPTOLITE_MAIN            = 121,      /* Address 0x42230000, size 0x00000100 */
    PROT_CRYPTOLITE_TRNG            = 122,      /* Address 0x42230100, size 0x00000100 */
    PROT_MXWOUND_MAIN               = 123,      /* Address 0x42240000, size 0x00000004 */
    PROT_MXWOUND_MXWOUND_PROP0_PROP = 124,      /* Address 0x42240100, size 0x00000004 */
    PROT_DEBUG600_DEBUG600          = 125,      /* Address 0x42250000, size 0x00000004 */
    PROT_SVGS_SVGS_MAIN             = 126,      /* Address 0x42260000, size 0x00000040 */
    PROT_SVGS_SVGS_AUX              = 127,      /* Address 0x42260040, size 0x00000040 */
    PROT_MXAES                      = 128,      /* Address 0x42270000, size 0x00002000 */
    PROT_HSIOM_PRT0_PRT             = 129,      /* Address 0x42400000, size 0x00000008 */
    PROT_HSIOM_PRT1_PRT             = 130,      /* Address 0x42400010, size 0x00000008 */
    PROT_HSIOM_PRT2_PRT             = 131,      /* Address 0x42400020, size 0x00000008 */
    PROT_HSIOM_PRT3_PRT             = 132,      /* Address 0x42400030, size 0x00000008 */
    PROT_HSIOM_PRT4_PRT             = 133,      /* Address 0x42400040, size 0x00000008 */
    PROT_HSIOM_PRT5_PRT             = 134,      /* Address 0x42400050, size 0x00000008 */
    PROT_HSIOM_PRT6_PRT             = 135,      /* Address 0x42400060, size 0x00000008 */
    PROT_HSIOM_PRT7_PRT             = 136,      /* Address 0x42400070, size 0x00000008 */
    PROT_HSIOM_PRT8_PRT             = 137,      /* Address 0x42400080, size 0x00000008 */
    PROT_HSIOM_PRT9_PRT             = 138,      /* Address 0x42400090, size 0x00000008 */
    PROT_HSIOM_SECURE_PRT0_SECURE_PRT = 139,    /* Address 0x42401000, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT1_SECURE_PRT = 140,    /* Address 0x42401010, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT2_SECURE_PRT = 141,    /* Address 0x42401020, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT3_SECURE_PRT = 142,    /* Address 0x42401030, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT4_SECURE_PRT = 143,    /* Address 0x42401040, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT5_SECURE_PRT = 144,    /* Address 0x42401050, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT6_SECURE_PRT = 145,    /* Address 0x42401060, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT7_SECURE_PRT = 146,    /* Address 0x42401070, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT8_SECURE_PRT = 147,    /* Address 0x42401080, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT9_SECURE_PRT = 148,    /* Address 0x42401090, size 0x00000004 */
    PROT_HSIOM_AMUX                 = 149,      /* Address 0x42402000, size 0x00000020 */
    PROT_HSIOM_MON                  = 150,      /* Address 0x42402200, size 0x00000010 */
    PROT_GPIO_PRT0_PRT              = 151,      /* Address 0x42410000, size 0x00000040 */
    PROT_GPIO_PRT1_PRT              = 152,      /* Address 0x42410080, size 0x00000040 */
    PROT_GPIO_PRT2_PRT              = 153,      /* Address 0x42410100, size 0x00000040 */
    PROT_GPIO_PRT3_PRT              = 154,      /* Address 0x42410180, size 0x00000040 */
    PROT_GPIO_PRT4_PRT              = 155,      /* Address 0x42410200, size 0x00000040 */
    PROT_GPIO_PRT5_PRT              = 156,      /* Address 0x42410280, size 0x00000040 */
    PROT_GPIO_PRT6_PRT              = 157,      /* Address 0x42410300, size 0x00000040 */
    PROT_GPIO_PRT7_PRT              = 158,      /* Address 0x42410380, size 0x00000040 */
    PROT_GPIO_PRT8_PRT              = 159,      /* Address 0x42410400, size 0x00000040 */
    PROT_GPIO_PRT9_PRT              = 160,      /* Address 0x42410480, size 0x00000040 */
    PROT_GPIO_PRT0_CFG              = 161,      /* Address 0x42410040, size 0x00000040 */
    PROT_GPIO_PRT1_CFG              = 162,      /* Address 0x424100c0, size 0x00000040 */
    PROT_GPIO_PRT2_CFG              = 163,      /* Address 0x42410140, size 0x00000040 */
    PROT_GPIO_PRT3_CFG              = 164,      /* Address 0x424101c0, size 0x00000040 */
    PROT_GPIO_PRT4_CFG              = 165,      /* Address 0x42410240, size 0x00000040 */
    PROT_GPIO_PRT5_CFG              = 166,      /* Address 0x424102c0, size 0x00000040 */
    PROT_GPIO_PRT6_CFG              = 167,      /* Address 0x42410340, size 0x00000040 */
    PROT_GPIO_PRT7_CFG              = 168,      /* Address 0x424103c0, size 0x00000040 */
    PROT_GPIO_PRT8_CFG              = 169,      /* Address 0x42410440, size 0x00000040 */
    PROT_GPIO_PRT9_CFG              = 170,      /* Address 0x424104c0, size 0x00000040 */
    PROT_GPIO_SEC_GPIO              = 171,      /* Address 0x42417000, size 0x00000004 */
    PROT_GPIO_GPIO                  = 172,      /* Address 0x42418000, size 0x00000040 */
    PROT_GPIO_TEST                  = 173,      /* Address 0x42419000, size 0x00000008 */
    PROT_LPCOMP                     = 174,      /* Address 0x42430000, size 0x00010000 */
    PROT_TCPWM0_GRP0_CNT0_CNT       = 175,      /* Address 0x42500000, size 0x00000100 */
    PROT_TCPWM0_GRP0_CNT1_CNT       = 176,      /* Address 0x42500100, size 0x00000100 */
    PROT_TCPWM0_GRP1_CNT0_CNT       = 177,      /* Address 0x42510000, size 0x00000100 */
    PROT_TCPWM0_GRP1_CNT1_CNT       = 178,      /* Address 0x42510100, size 0x00000100 */
    PROT_TCPWM0_TR_ALL_SYNC_BYPASS_TR_ALL_SYN_BYPASS = 179, /* Address 0x42590000, size 0x00000004 */
    PROT_DFT                        = 180,      /* Address 0x42600000, size 0x00001000 */
    PROT_EFUSE_CTL1                 = 181,      /* Address 0x42610000, size 0x00000004 */
    PROT_EFUSE_CTL2                 = 182,      /* Address 0x42610100, size 0x00000080 */
    PROT_EFUSE_CTL3                 = 183,      /* Address 0x42610180, size 0x00000004 */
    PROT_EFUSE_DATA_BOOT1           = 184,      /* Address 0x42610800, size 0x00000080 */
    PROT_CANFD0_CH0_CH              = 185,      /* Address 0x42800000, size 0x00000200 */
    PROT_CANFD0_CH1_CH              = 186,      /* Address 0x42800200, size 0x00000200 */
    PROT_CANFD0_MAIN                = 187,      /* Address 0x42801000, size 0x00000040 */
    PROT_CANFD0_BUF                 = 188,      /* Address 0x42810000, size 0x00010000 */
    PROT_SCB0                       = 189,      /* Address 0x42820000, size 0x00010000 */
    PROT_SCB1                       = 190,      /* Address 0x42840000, size 0x00010000 */
    PROT_SCB2                       = 191,      /* Address 0x42850000, size 0x00010000 */
    PROT_SCB3                       = 192,      /* Address 0x42860000, size 0x00010000 */
    PROT_SCB4                       = 193,      /* Address 0x42870000, size 0x00010000 */
    PROT_SCB5                       = 194,      /* Address 0x43800000, size 0x00010000 */
    PROT_SCB6                       = 195,      /* Address 0x43810000, size 0x00010000 */
    PROT_PPCA_PPCA_CNFG_PPCACNFG    = 196,      /* Address 0x43000000, size 0x00000004 */
    PROT_PPCA_PPCA_CNFG_CNFG_CNFG   = 197,      /* Address 0x43000100, size 0x00000100 */
    PROT_PPCA_PPCA_CNFG_IMC         = 198,      /* Address 0x43000300, size 0x00000080 */
    PROT_PPCA_PPCA_CNFG_ADCM        = 199,      /* Address 0x43000400, size 0x00000100 */
    PROT_PPCA_PPCA_CNFG_DISPERI_BOOT = 200,     /* Address 0x43000800, size 0x00000004 */
    PROT_PPCA_EPU                   = 201,      /* Address 0x43004000, size 0x00001000 */
    PROT_PPCA_RAM0                  = 202,      /* Address 0x43010000, size 0x00010000 */
    PROT_PPCA_RAM1                  = 203,      /* Address 0x43020000, size 0x00010000 */
    PROT_PPCA_RAM2                  = 204,      /* Address 0x43030000, size 0x00010000 */
    PROT_PPCA_RAM3                  = 205,      /* Address 0x43040000, size 0x00010000 */
    PROT_PPCA_SHMEM                 = 206,      /* Address 0x43050000, size 0x00010000 */
    PROT_PPCA_PPCA_IPC_STRUCT0_IPC  = 207,      /* Address 0x43060000, size 0x00000020 */
    PROT_PPCA_PPCA_IPC_STRUCT1_IPC  = 208,      /* Address 0x43060020, size 0x00000020 */
    PROT_PPCA_PPCA_IPC_STRUCT2_IPC  = 209,      /* Address 0x43060040, size 0x00000020 */
    PROT_PPCA_PPCA_IPC_STRUCT3_IPC  = 210,      /* Address 0x43060060, size 0x00000020 */
    PROT_PPCA_PPCA_IPC_INTR_STRUCT0_INTR = 211, /* Address 0x43061000, size 0x00000010 */
    PROT_PPCA_PPCA_IPC_INTR_STRUCT1_INTR = 212, /* Address 0x43061020, size 0x00000010 */
    PROT_PPCA_PPCA_IPC_INTR_STRUCT2_INTR = 213, /* Address 0x43061040, size 0x00000010 */
    PROT_PPCA_PPCA_IPC_INTR_STRUCT3_INTR = 214, /* Address 0x43061060, size 0x00000010 */
    PROT_PPCA_CPUSS_CNFG_PPCA_MXCM330_CM33 = 215, /* Address 0x43080000, size 0x00000100 */
    PROT_PPCA_CPUSS_CNFG_PPCA_MXCM331_CM33 = 216, /* Address 0x43090000, size 0x00000100 */
    PROT_PPCA_CPUSS_CNFG_PPCA_MXCM330_CM33_NS = 217, /* Address 0x43081004, size 0x00000004 */
    PROT_PPCA_CPUSS_CNFG_PPCA_MXCM331_CM33_NS = 218, /* Address 0x43091004, size 0x00000004 */
    PROT_PPCA_CPUSS_CNFG_PPCA_MXCM330_BOOT = 219, /* Address 0x430821c0, size 0x00000004 */
    PROT_PPCA_CPUSS_CNFG_PPCA_MXCM331_BOOT = 220, /* Address 0x430921c0, size 0x00000004 */
    PROT_PPCA_CPUSS_CNFG_PPCA_MXCM330_CM33_INT = 221, /* Address 0x43088000, size 0x00000100 */
    PROT_PPCA_CPUSS_CNFG_PPCA_MXCM331_CM33_INT = 222, /* Address 0x43098000, size 0x00000100 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC0_CM33 = 223, /* Address 0x430a0000, size 0x00000040 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC1_CM33 = 224, /* Address 0x430b0000, size 0x00000040 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC2_CM33 = 225, /* Address 0x430c0000, size 0x00000040 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC3_CM33 = 226, /* Address 0x430d0000, size 0x00000040 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC4_CM33 = 227, /* Address 0x430e0000, size 0x00000040 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC0_BOOT = 228, /* Address 0x430a0100, size 0x00000008 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC1_BOOT = 229, /* Address 0x430b0100, size 0x00000008 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC2_BOOT = 230, /* Address 0x430c0100, size 0x00000008 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC3_BOOT = 231, /* Address 0x430d0100, size 0x00000008 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC4_BOOT = 232, /* Address 0x430e0100, size 0x00000008 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC0_RAM_PWR = 233, /* Address 0x430a0200, size 0x00000100 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC1_RAM_PWR = 234, /* Address 0x430b0200, size 0x00000100 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC2_RAM_PWR = 235, /* Address 0x430c0200, size 0x00000100 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC3_RAM_PWR = 236, /* Address 0x430d0200, size 0x00000100 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC4_RAM_PWR = 237, /* Address 0x430e0200, size 0x00000100 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC0_PPCA_MPC0_PPC_MPC_MAIN = 238, /* Address 0x430a4000, size 0x00000004 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC1_PPCA_MPC0_PPC_MPC_MAIN = 239, /* Address 0x430b4000, size 0x00000004 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC2_PPCA_MPC0_PPC_MPC_MAIN = 240, /* Address 0x430c4000, size 0x00000004 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC3_PPCA_MPC0_PPC_MPC_MAIN = 241, /* Address 0x430d4000, size 0x00000004 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC4_PPCA_MPC0_PPC_MPC_MAIN = 242, /* Address 0x430e4000, size 0x00000004 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC0_PPCA_MPC0_PPC_MPC_PC = 243, /* Address 0x430a4100, size 0x00000020 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC1_PPCA_MPC0_PPC_MPC_PC = 244, /* Address 0x430b4100, size 0x00000020 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC2_PPCA_MPC0_PPC_MPC_PC = 245, /* Address 0x430c4100, size 0x00000020 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC3_PPCA_MPC0_PPC_MPC_PC = 246, /* Address 0x430d4100, size 0x00000020 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC4_PPCA_MPC0_PPC_MPC_PC = 247, /* Address 0x430e4100, size 0x00000020 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC0_PPCA_MPC0_PPC_MPC_ROT = 248, /* Address 0x430a4200, size 0x00000020 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC1_PPCA_MPC0_PPC_MPC_ROT = 249, /* Address 0x430b4200, size 0x00000020 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC2_PPCA_MPC0_PPC_MPC_ROT = 250, /* Address 0x430c4200, size 0x00000020 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC3_PPCA_MPC0_PPC_MPC_ROT = 251, /* Address 0x430d4200, size 0x00000020 */
    PROT_PPCA_CPUSS_CNFG_PPCA_RAMC4_PPCA_MPC0_PPC_MPC_ROT = 252, /* Address 0x430e4200, size 0x00000020 */
    PROT_PPCA_CPUSS_CNFG_AP         = 253,      /* Address 0x430f0000, size 0x00000008 */
    PROT_PPCA_CPUSS_CNFG_RAMC_PPU0_PPU = 254,   /* Address 0x430f8000, size 0x00001000 */
    PROT_PPCA_CPUSS_CNFG_RAMC_PPU1_PPU = 255,   /* Address 0x430f9000, size 0x00001000 */
    PROT_PPCA_CPUSS_CNFG_RAMC_PPU2_PPU = 256,   /* Address 0x430fa000, size 0x00001000 */
    PROT_PPCA_CPUSS_CNFG_RAMC_PPU3_PPU = 257,   /* Address 0x430fb000, size 0x00001000 */
    PROT_PPCA_CPUSS_CNFG_RAMC_PPU4_PPU = 258,   /* Address 0x430fc000, size 0x00001000 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP0_TCPWM0_CNT0_CNT = 259, /* Address 0x43100000, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP0_TCPWM0_CNT1_CNT = 260, /* Address 0x43100100, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP0_TCPWM0_CNT2_CNT = 261, /* Address 0x43100200, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP0_TCPWM0_CNT3_CNT = 262, /* Address 0x43100300, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP1_TCPWM0_CNT0_CNT = 263, /* Address 0x43110000, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP1_TCPWM0_CNT1_CNT = 264, /* Address 0x43110100, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP1_TCPWM0_CNT2_CNT = 265, /* Address 0x43110200, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP1_TCPWM0_CNT3_CNT = 266, /* Address 0x43110300, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP2_TCPWM0_CNT0_CNT = 267, /* Address 0x43120000, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP2_TCPWM0_CNT1_CNT = 268, /* Address 0x43120100, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP2_TCPWM0_CNT2_CNT = 269, /* Address 0x43120200, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_GRP2_TCPWM0_CNT3_CNT = 270, /* Address 0x43120300, size 0x00000100 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_TR_ALL_SYNC_BYPASS_TR_ALL_SYN_BYPASS = 271, /* Address 0x43190000, size 0x00000004 */
    PROT_PPCA_TCPWM0_TCPWM_TCPWM0_MOTIF_GRP2_TCPWM0_MOTIF0_MOTIF = 272, /* Address 0x431a8000, size 0x00000200 */
    PROT_PPCA_TCPWM1_TCPWM_TCPWM1_GRP0_TCPWM1_CNT0_CNT = 273, /* Address 0x43200000, size 0x00000100 */
    PROT_PPCA_TCPWM1_TCPWM_TCPWM1_GRP0_TCPWM1_CNT1_CNT = 274, /* Address 0x43200100, size 0x00000100 */
    PROT_PPCA_TCPWM1_TCPWM_TCPWM1_GRP1_TCPWM1_CNT0_CNT = 275, /* Address 0x43210000, size 0x00000100 */
    PROT_PPCA_TCPWM1_TCPWM_TCPWM1_GRP1_TCPWM1_CNT1_CNT = 276, /* Address 0x43210100, size 0x00000100 */
    PROT_PPCA_TCPWM1_TCPWM_TCPWM1_GRP2_TCPWM1_CNT0_CNT = 277, /* Address 0x43220000, size 0x00000100 */
    PROT_PPCA_TCPWM1_TCPWM_TCPWM1_GRP2_TCPWM1_CNT1_CNT = 278, /* Address 0x43220100, size 0x00000100 */
    PROT_PPCA_TCPWM1_TCPWM_TCPWM1_GRP2_TCPWM1_CNT2_CNT = 279, /* Address 0x43220200, size 0x00000100 */
    PROT_PPCA_TCPWM1_TCPWM_TCPWM1_GRP2_TCPWM1_CNT3_CNT = 280, /* Address 0x43220300, size 0x00000100 */
    PROT_PPCA_TCPWM1_TCPWM_TCPWM1_TR_ALL_SYNC_BYPASS_TR_ALL_SYN_BYPASS = 281, /* Address 0x43290000, size 0x00000004 */
    PROT_PPCA_TCPWM1_TCPWM_TCPWM1_MOTIF_GRP2_TCPWM1_MOTIF0_MOTIF = 282, /* Address 0x432a8000, size 0x00000200 */
    PROT_PPCA_TCPWM2_TCPWM_TCPWM2_GRP0_TCPWM2_CNT0_CNT = 283, /* Address 0x43300000, size 0x00000100 */
    PROT_PPCA_TCPWM2_TCPWM_TCPWM2_GRP0_TCPWM2_CNT1_CNT = 284, /* Address 0x43300100, size 0x00000100 */
    PROT_PPCA_TCPWM2_TCPWM_TCPWM2_GRP0_TCPWM2_CNT2_CNT = 285, /* Address 0x43300200, size 0x00000100 */
    PROT_PPCA_TCPWM2_TCPWM_TCPWM2_GRP0_TCPWM2_CNT3_CNT = 286, /* Address 0x43300300, size 0x00000100 */
    PROT_PPCA_TCPWM2_TCPWM_TCPWM2_TR_ALL_SYNC_BYPASS_TR_ALL_SYN_BYPASS = 287, /* Address 0x43390000, size 0x00000004 */
    PROT_PPCA_TCPWM3_TCPWM_TCPWM3_GRP0_TCPWM3_CNT0_CNT = 288, /* Address 0x43400000, size 0x00000100 */
    PROT_PPCA_TCPWM3_TCPWM_TCPWM3_GRP0_TCPWM3_CNT1_CNT = 289, /* Address 0x43400100, size 0x00000100 */
    PROT_PPCA_TCPWM3_TCPWM_TCPWM3_TR_ALL_SYNC_BYPASS_TR_ALL_SYN_BYPASS = 290, /* Address 0x43490000, size 0x00000004 */
    PROT_PPCA_HWFILTSS0             = 291,      /* Address 0x43500000, size 0x00001000 */
    PROT_PPCA_HWFILTSS1             = 292,      /* Address 0x43510000, size 0x00001000 */
    PROT_PPCA_ADCM_ADCM             = 293,      /* Address 0x43520000, size 0x00000100 */
    PROT_PPCA_CLB_CLB               = 294,      /* Address 0x43530000, size 0x00008000 */
    PROT_PPCA_CORDIC                = 295,      /* Address 0x43540000, size 0x00020000 */
    PROT_PPCA_ATOPSS_ATOPSS         = 296,      /* Address 0x43580000, size 0x00010000 */
    PROT_END                        = 296
} cy_en_prot_region_t;

#endif /* _PSC3_P8_CONFIG_H_ */


/* [] END OF FILE */
