/***************************************************************************//**
* PSC3M6 device configuration header
*
********************************************************************************
* \copyright
* (c) 2016-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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

#ifndef _PSC3M6_CONFIG_H_
#define _PSC3M6_CONFIG_H_

/* Clock Connections */
typedef enum
{
    PCLK_DEBUG600_CLOCK_TRACE_IN    = 0x0000u,  /* debug600.clock_trace_in */
    PCLK_TCPWM0_CLOCK_COUNTER_EN0   = 0x0001u,  /* tcpwm[0].clock_counter_en[0] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN1   = 0x0002u,  /* tcpwm[0].clock_counter_en[1] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN2   = 0x0003u,  /* tcpwm[0].clock_counter_en[2] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN3   = 0x0004u,  /* tcpwm[0].clock_counter_en[3] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN4   = 0x0005u,  /* tcpwm[0].clock_counter_en[4] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN5   = 0x0006u,  /* tcpwm[0].clock_counter_en[5] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN6   = 0x0007u,  /* tcpwm[0].clock_counter_en[6] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN7   = 0x0008u,  /* tcpwm[0].clock_counter_en[7] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN256 = 0x0009u,  /* tcpwm[0].clock_counter_en[256] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN257 = 0x000Au,  /* tcpwm[0].clock_counter_en[257] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN258 = 0x000Bu,  /* tcpwm[0].clock_counter_en[258] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN259 = 0x000Cu,  /* tcpwm[0].clock_counter_en[259] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN260 = 0x000Du,  /* tcpwm[0].clock_counter_en[260] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN261 = 0x000Eu,  /* tcpwm[0].clock_counter_en[261] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN262 = 0x000Fu,  /* tcpwm[0].clock_counter_en[262] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN263 = 0x0010u,  /* tcpwm[0].clock_counter_en[263] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN512 = 0x0011u,  /* tcpwm[0].clock_counter_en[512] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN513 = 0x0012u,  /* tcpwm[0].clock_counter_en[513] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN514 = 0x0013u,  /* tcpwm[0].clock_counter_en[514] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN515 = 0x0014u,  /* tcpwm[0].clock_counter_en[515] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN516 = 0x0015u,  /* tcpwm[0].clock_counter_en[516] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN517 = 0x0016u,  /* tcpwm[0].clock_counter_en[517] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN518 = 0x0017u,  /* tcpwm[0].clock_counter_en[518] */
    PCLK_TCPWM0_CLOCK_COUNTER_EN519 = 0x0018u,  /* tcpwm[0].clock_counter_en[519] */
    PCLK_TCPWM0_CLOCK_MOTIF_EN32    = 0x0019u,  /* tcpwm[0].clock_motif_en[32] */
    PCLK_TCPWM0_CLOCK_MOTIF_EN64    = 0x001Au,  /* tcpwm[0].clock_motif_en[64] */
    PCLK_PASS_CLOCK_CSG             = 0x001Bu,  /* pass.clock_csg */
    PCLK_IOSS_CLOCK_SMARTIO_PCLK_POS_EN0 = 0x0100u, /* ioss.clock_smartio_pclk_pos_en[0] */
    PCLK_IOSS_CLOCK_SMARTIO_PCLK_POS_EN1 = 0x0101u, /* ioss.clock_smartio_pclk_pos_en[1] */
    PCLK_IOSS_CLOCK_SMARTIO_PCLK_POS_EN2 = 0x0102u, /* ioss.clock_smartio_pclk_pos_en[2] */
    PCLK_IOSS_CLOCK_SMARTIO_PCLK_POS_EN3 = 0x0103u, /* ioss.clock_smartio_pclk_pos_en[3] */
    PCLK_IOSS_CLOCK_SMARTIO_PCLK_POS_EN5 = 0x0104u, /* ioss.clock_smartio_pclk_pos_en[5] */
    PCLK_IOSS_CLOCK_SMARTIO_PCLK_POS_EN6 = 0x0105u, /* ioss.clock_smartio_pclk_pos_en[6] */
    PCLK_IOSS_CLOCK_SMARTIO_PCLK_POS_EN9 = 0x0106u, /* ioss.clock_smartio_pclk_pos_en[9] */
    PCLK_CRYPTOLITE_CLK_HF          = 0x0200u,  /* cryptolite.clk_hf */
    PCLK_IOSS_CLK_HF                = 0x0300u,  /* ioss.clk_hf */
    PCLK_SCB0_CLOCK_SCB_EN          = 0x0400u,  /* scb[0].clock_scb_en */
    PCLK_SCB0_CLOCK_TGS_EN          = 0x0401u,  /* scb[0].clock_tgs_en */
    PCLK_SCB1_CLOCK_SCB_EN          = 0x0402u,  /* scb[1].clock_scb_en */
    PCLK_SCB1_CLOCK_TGS_EN          = 0x0403u,  /* scb[1].clock_tgs_en */
    PCLK_SCB2_CLOCK_SCB_EN          = 0x0404u,  /* scb[2].clock_scb_en */
    PCLK_SCB2_CLOCK_TGS_EN          = 0x0405u,  /* scb[2].clock_tgs_en */
    PCLK_SCB3_CLOCK_SCB_EN          = 0x0406u,  /* scb[3].clock_scb_en */
    PCLK_SCB3_CLOCK_TGS_EN          = 0x0407u,  /* scb[3].clock_tgs_en */
    PCLK_SCB4_CLOCK_SCB_EN          = 0x0408u,  /* scb[4].clock_scb_en */
    PCLK_SCB4_CLOCK_TGS_EN          = 0x0409u,  /* scb[4].clock_tgs_en */
    PCLK_CANFD0_CLOCK_CAN_EN0       = 0x040Au,  /* canfd[0].clock_can_en[0] */
    PCLK_CANFD0_CLOCK_CAN_EN1       = 0x040Bu,  /* canfd[0].clock_can_en[1] */
    PCLK_SCB5_CLOCK_SCB_EN          = 0x0600u,  /* scb[5].clock_scb_en */
    PCLK_SCB5_CLOCK_TGS_EN          = 0x0601u,  /* scb[5].clock_tgs_en */
    PCLK_I3C0_CLOCK_I3C_EN          = 0x0602u,  /* i3c[0].clock_i3c_en */
    PCLK_USB0_CLOCK_DEV_BRS         = 0x0603u,  /* usb[0].clock_dev_brs */
    PCLK_I3C0_CLK_IF                = 0x0700u,  /* i3c[0].clk_if */
    PCLK_USB0_CLK_USB_DEV           = 0x0800u,  /* usb[0].clk_usb_dev */
    PCLK_USB0_CLK_USB_HOST          = 0x0900u   /* usb[0].clk_usb_host */
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
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT0_2 = 0x00000007u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT0_3 = 0x00000008u, /* tcpwm[0].tr_out0[3] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT0_4 = 0x00000009u, /* tcpwm[0].tr_out0[4] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT0_5 = 0x0000000Au, /* tcpwm[0].tr_out0[5] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT0_6 = 0x0000000Bu, /* tcpwm[0].tr_out0[6] */
    TRIG_IN_MUX_0_TCPWM0_GRP0_OUT0_7 = 0x0000000Cu, /* tcpwm[0].tr_out0[7] */
    TRIG_IN_MUX_0_TCPWM0_GRP1_OUT0_0 = 0x0000000Du, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_0_TCPWM0_GRP1_OUT0_1 = 0x0000000Eu, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_0_TCPWM0_GRP1_OUT0_2 = 0x0000000Fu, /* tcpwm[0].tr_out0[258] */
    TRIG_IN_MUX_0_TCPWM0_GRP1_OUT0_3 = 0x00000010u, /* tcpwm[0].tr_out0[259] */
    TRIG_IN_MUX_0_TCPWM0_GRP1_OUT0_4 = 0x00000011u, /* tcpwm[0].tr_out0[260] */
    TRIG_IN_MUX_0_TCPWM0_GRP1_OUT0_5 = 0x00000012u, /* tcpwm[0].tr_out0[261] */
    TRIG_IN_MUX_0_TCPWM0_GRP1_OUT0_6 = 0x00000013u, /* tcpwm[0].tr_out0[262] */
    TRIG_IN_MUX_0_TCPWM0_GRP1_OUT0_7 = 0x00000014u, /* tcpwm[0].tr_out0[263] */
    TRIG_IN_MUX_0_TCPWM0_GRP2_OUT0_0 = 0x00000015u, /* tcpwm[0].tr_out0[512] */
    TRIG_IN_MUX_0_TCPWM0_GRP2_OUT0_1 = 0x00000016u, /* tcpwm[0].tr_out0[513] */
    TRIG_IN_MUX_0_TCPWM0_GRP2_OUT0_2 = 0x00000017u, /* tcpwm[0].tr_out0[514] */
    TRIG_IN_MUX_0_TCPWM0_GRP2_OUT0_3 = 0x00000018u, /* tcpwm[0].tr_out0[515] */
    TRIG_IN_MUX_0_TCPWM0_GRP2_OUT0_4 = 0x00000019u, /* tcpwm[0].tr_out0[516] */
    TRIG_IN_MUX_0_TCPWM0_GRP2_OUT0_5 = 0x0000001Au, /* tcpwm[0].tr_out0[517] */
    TRIG_IN_MUX_0_TCPWM0_GRP2_OUT0_6 = 0x0000001Bu, /* tcpwm[0].tr_out0[518] */
    TRIG_IN_MUX_0_TCPWM0_GRP2_OUT0_7 = 0x0000001Cu, /* tcpwm[0].tr_out0[519] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT0     = 0x0000001Du, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT1     = 0x0000001Eu, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT2     = 0x0000001Fu, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT3     = 0x00000020u, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT4     = 0x00000021u, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT5     = 0x00000022u, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT6     = 0x00000023u, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT7     = 0x00000024u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT8     = 0x00000025u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT9     = 0x00000026u, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT10    = 0x00000027u, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT11    = 0x00000028u, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT12    = 0x00000029u, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT13    = 0x0000002Au, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT14    = 0x0000002Bu, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT15    = 0x0000002Cu, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT16    = 0x0000002Du, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT17    = 0x0000002Eu, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT18    = 0x0000002Fu, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT19    = 0x00000030u, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT20    = 0x00000031u, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT21    = 0x00000032u, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT22    = 0x00000033u, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT23    = 0x00000034u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT24    = 0x00000035u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT25    = 0x00000036u, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT26    = 0x00000037u, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT27    = 0x00000038u, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT28    = 0x00000039u, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT29    = 0x0000003Au, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT30    = 0x0000003Bu, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT31    = 0x0000003Cu, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT32    = 0x0000003Du, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT33    = 0x0000003Eu, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT34    = 0x0000003Fu, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT35    = 0x00000040u, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT36    = 0x00000041u, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT37    = 0x00000042u, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT38    = 0x00000043u, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT39    = 0x00000044u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT40    = 0x00000045u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT41    = 0x00000046u, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT42    = 0x00000047u, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT43    = 0x00000048u, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT44    = 0x00000049u, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT45    = 0x0000004Au, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT46    = 0x0000004Bu, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT47    = 0x0000004Cu, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT48    = 0x0000004Du, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT49    = 0x0000004Eu, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT50    = 0x0000004Fu, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT51    = 0x00000050u, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT52    = 0x00000051u, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT53    = 0x00000052u, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT54    = 0x00000053u, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT55    = 0x00000054u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT56    = 0x00000055u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT57    = 0x00000056u, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT58    = 0x00000057u, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT59    = 0x00000058u, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT60    = 0x00000059u, /* ioss.peri_tr_io_input_in[60] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT61    = 0x0000005Au, /* ioss.peri_tr_io_input_in[61] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT62    = 0x0000005Bu, /* ioss.peri_tr_io_input_in[62] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT63    = 0x0000005Cu, /* ioss.peri_tr_io_input_in[63] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT64    = 0x0000005Du, /* ioss.peri_tr_io_input_in[64] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT65    = 0x0000005Eu, /* ioss.peri_tr_io_input_in[65] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT66    = 0x0000005Fu, /* ioss.peri_tr_io_input_in[66] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT67    = 0x00000060u, /* ioss.peri_tr_io_input_in[67] */
    TRIG_IN_MUX_0_SCB_I2C_SCL0      = 0x00000061u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX0           = 0x00000062u, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX0           = 0x00000063u, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD00  = 0x00000064u, /* scb[0].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP00    = 0x00000065u, /* scb[0].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED00   = 0x00000066u, /* scb[0].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_SCB_I2C_SCL1      = 0x00000067u, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX1           = 0x00000068u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX1           = 0x00000069u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD10  = 0x0000006Au, /* scb[1].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP10    = 0x0000006Bu, /* scb[1].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED10   = 0x0000006Cu, /* scb[1].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_SCB_I2C_SCL2      = 0x0000006Du, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX2           = 0x0000006Eu, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX2           = 0x0000006Fu, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD20  = 0x00000070u, /* scb[2].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP20    = 0x00000071u, /* scb[2].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED20   = 0x00000072u, /* scb[2].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_SCB_I2C_SCL3      = 0x00000073u, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX3           = 0x00000074u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX3           = 0x00000075u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD30  = 0x00000076u, /* scb[3].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP30    = 0x00000077u, /* scb[3].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED30   = 0x00000078u, /* scb[3].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_SCB_I2C_SCL4      = 0x00000079u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX4           = 0x0000007Au, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX4           = 0x0000007Bu, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD40  = 0x0000007Cu, /* scb[4].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP40    = 0x0000007Du, /* scb[4].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED40   = 0x0000007Eu, /* scb[4].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_SCB_I2C_SCL5      = 0x0000007Fu, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_0_SCB_TX5           = 0x00000080u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_0_SCB_RX5           = 0x00000081u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_0_SCB_TGS_RELOAD50  = 0x00000082u, /* scb[5].tr_tgs_reload[0] */
    TRIG_IN_MUX_0_SCB_TGS_STOP50    = 0x00000083u, /* scb[5].tr_tgs_stop[0] */
    TRIG_IN_MUX_0_SCB_TGS_GATED50   = 0x00000084u, /* scb[5].tr_tgs_gated[0] */
    TRIG_IN_MUX_0_CTI_TR_OUT0       = 0x00000085u, /* debug600.cti_tr_out[0] */
    TRIG_IN_MUX_0_CTI_TR_OUT1       = 0x00000086u, /* debug600.cti_tr_out[1] */
    TRIG_IN_MUX_0_MXCORDIC_DONE     = 0x00000087u, /* cordic[0].tr_done_mxcordic */
    TRIG_IN_MUX_0_CANFD_TT_TR_OUT0  = 0x00000088u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_0_CANFD_TT_TR_OUT1  = 0x00000089u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_0_CAN_DBG0          = 0x0000008Au, /* canfd[0].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_0_CAN_DBG1          = 0x0000008Bu, /* canfd[0].tr_dbg_dma_req[1] */
    TRIG_IN_MUX_0_CAN_FIFO0_CH0     = 0x0000008Cu, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_MUX_0_CAN_FIFO0_CH1     = 0x0000008Du, /* canfd[0].tr_fifo0[1] */
    TRIG_IN_MUX_0_CAN_FIFO1_CH0     = 0x0000008Eu, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_MUX_0_CAN_FIFO1_CH1     = 0x0000008Fu, /* canfd[0].tr_fifo1[1] */
    TRIG_IN_MUX_0_LPCOMP_DSI_COMP0  = 0x00000090u, /* lpcomp.dsi_comp0 */
    TRIG_IN_MUX_0_LPCOMP_DSI_COMP1  = 0x00000091u, /* lpcomp.dsi_comp1 */
    TRIG_IN_MUX_0_CPUSS_TR_FAULT0   = 0x00000092u, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_0_TRNG_BITSTREAM    = 0x00000093u, /* cryptolite.tr_trng_bitstream */
    TRIG_IN_MUX_0_PASS_FIFO0        = 0x00000094u, /* pass.tr_fifo_level_out[0] */
    TRIG_IN_MUX_0_PASS_FIFO1        = 0x00000095u, /* pass.tr_fifo_level_out[1] */
    TRIG_IN_MUX_0_PASS_FIFO2        = 0x00000096u, /* pass.tr_fifo_level_out[2] */
    TRIG_IN_MUX_0_PASS_FIFO3        = 0x00000097u, /* pass.tr_fifo_level_out[3] */
    TRIG_IN_MUX_0_PASS_PULSE0       = 0x00000098u, /* pass.tr_pulse_out[0] */
    TRIG_IN_MUX_0_PASS_PULSE1       = 0x00000099u, /* pass.tr_pulse_out[1] */
    TRIG_IN_MUX_0_PASS_PULSE2       = 0x0000009Au, /* pass.tr_pulse_out[2] */
    TRIG_IN_MUX_0_PASS_PULSE3       = 0x0000009Bu, /* pass.tr_pulse_out[3] */
    TRIG_IN_MUX_0_PASS_PULSE4       = 0x0000009Cu, /* pass.tr_pulse_out[4] */
    TRIG_IN_MUX_0_PASS_PULSE5       = 0x0000009Du, /* pass.tr_pulse_out[5] */
    TRIG_IN_MUX_0_PASS_PULSE6       = 0x0000009Eu, /* pass.tr_pulse_out[6] */
    TRIG_IN_MUX_0_PASS_PULSE7       = 0x0000009Fu, /* pass.tr_pulse_out[7] */
    TRIG_IN_MUX_0_PASS_PULSE8       = 0x000000A0u, /* pass.tr_pulse_out[8] */
    TRIG_IN_MUX_0_PASS_PULSE9       = 0x000000A1u, /* pass.tr_pulse_out[9] */
    TRIG_IN_MUX_0_PASS_PULSE10      = 0x000000A2u, /* pass.tr_pulse_out[10] */
    TRIG_IN_MUX_0_PASS_PULSE11      = 0x000000A3u, /* pass.tr_pulse_out[11] */
    TRIG_IN_MUX_0_PASS_PULSE12      = 0x000000A4u, /* pass.tr_pulse_out[12] */
    TRIG_IN_MUX_0_PASS_PULSE13      = 0x000000A5u, /* pass.tr_pulse_out[13] */
    TRIG_IN_MUX_0_PASS_PULSE14      = 0x000000A6u, /* pass.tr_pulse_out[14] */
    TRIG_IN_MUX_0_PASS_PULSE15      = 0x000000A7u, /* pass.tr_pulse_out[15] */
    TRIG_IN_MUX_0_PASS_LEVEL0       = 0x000000A8u, /* pass.tr_level_out[0] */
    TRIG_IN_MUX_0_PASS_LEVEL1       = 0x000000A9u, /* pass.tr_level_out[1] */
    TRIG_IN_MUX_0_PASS_LEVEL2       = 0x000000AAu, /* pass.tr_level_out[2] */
    TRIG_IN_MUX_0_PASS_LEVEL3       = 0x000000ABu, /* pass.tr_level_out[3] */
    TRIG_IN_MUX_0_PASS_LEVEL4       = 0x000000ACu, /* pass.tr_level_out[4] */
    TRIG_IN_MUX_0_PASS_LEVEL5       = 0x000000ADu, /* pass.tr_level_out[5] */
    TRIG_IN_MUX_0_PASS_LEVEL6       = 0x000000AEu, /* pass.tr_level_out[6] */
    TRIG_IN_MUX_0_PASS_LEVEL7       = 0x000000AFu, /* pass.tr_level_out[7] */
    TRIG_IN_MUX_0_PASS_LEVEL8       = 0x000000B0u, /* pass.tr_level_out[8] */
    TRIG_IN_MUX_0_PASS_LEVEL9       = 0x000000B1u, /* pass.tr_level_out[9] */
    TRIG_IN_MUX_0_PASS_LEVEL10      = 0x000000B2u, /* pass.tr_level_out[10] */
    TRIG_IN_MUX_0_PASS_LEVEL11      = 0x000000B3u, /* pass.tr_level_out[11] */
    TRIG_IN_MUX_0_PASS_LEVEL12      = 0x000000B4u, /* pass.tr_level_out[12] */
    TRIG_IN_MUX_0_PASS_LEVEL13      = 0x000000B5u, /* pass.tr_level_out[13] */
    TRIG_IN_MUX_0_PASS_LEVEL14      = 0x000000B6u, /* pass.tr_level_out[14] */
    TRIG_IN_MUX_0_PASS_LEVEL15      = 0x000000B7u, /* pass.tr_level_out[15] */
    TRIG_IN_MUX_0_I3C_TX0           = 0x000000B8u, /* i3c[0].tr_tx_req */
    TRIG_IN_MUX_0_I3C_RX0           = 0x000000B9u, /* i3c[0].tr_rx_req */
    TRIG_IN_MUX_0_USB_DMA_REQ0      = 0x000000BAu, /* usb[0].usb_dma_req[0] */
    TRIG_IN_MUX_0_USB_DMA_REQ1      = 0x000000BBu, /* usb[0].usb_dma_req[1] */
    TRIG_IN_MUX_0_USB_DMA_REQ2      = 0x000000BCu, /* usb[0].usb_dma_req[2] */
    TRIG_IN_MUX_0_USB_DMA_REQ3      = 0x000000BDu, /* usb[0].usb_dma_req[3] */
    TRIG_IN_MUX_0_USB_DMA_REQ4      = 0x000000BEu, /* usb[0].usb_dma_req[4] */
    TRIG_IN_MUX_0_USB_DMA_REQ5      = 0x000000BFu, /* usb[0].usb_dma_req[5] */
    TRIG_IN_MUX_0_USB_DMA_REQ6      = 0x000000C0u, /* usb[0].usb_dma_req[6] */
    TRIG_IN_MUX_0_USB_DMA_REQ7      = 0x000000C1u /* usb[0].usb_dma_req[7] */
} en_trig_input_pdma0_tr_t;

/* Trigger Input Group 1 - P-DMA1 Request Assignments */
typedef enum
{
    TRIG_IN_MUX_1_PDMA1_TR_OUT0     = 0x00000101u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT1     = 0x00000102u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT2     = 0x00000103u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT3     = 0x00000104u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_0 = 0x00000105u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_1 = 0x00000106u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_2 = 0x00000107u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_3 = 0x00000108u, /* tcpwm[0].tr_out0[3] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_4 = 0x00000109u, /* tcpwm[0].tr_out0[4] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_5 = 0x0000010Au, /* tcpwm[0].tr_out0[5] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_6 = 0x0000010Bu, /* tcpwm[0].tr_out0[6] */
    TRIG_IN_MUX_1_TCPWM0_GRP0_OUT0_7 = 0x0000010Cu, /* tcpwm[0].tr_out0[7] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_OUT0_0 = 0x0000010Du, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_OUT0_1 = 0x0000010Eu, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_OUT0_2 = 0x0000010Fu, /* tcpwm[0].tr_out0[258] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_OUT0_3 = 0x00000110u, /* tcpwm[0].tr_out0[259] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_OUT0_4 = 0x00000111u, /* tcpwm[0].tr_out0[260] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_OUT0_5 = 0x00000112u, /* tcpwm[0].tr_out0[261] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_OUT0_6 = 0x00000113u, /* tcpwm[0].tr_out0[262] */
    TRIG_IN_MUX_1_TCPWM0_GRP1_OUT0_7 = 0x00000114u, /* tcpwm[0].tr_out0[263] */
    TRIG_IN_MUX_1_TCPWM0_GRP2_OUT0_0 = 0x00000115u, /* tcpwm[0].tr_out0[512] */
    TRIG_IN_MUX_1_TCPWM0_GRP2_OUT0_1 = 0x00000116u, /* tcpwm[0].tr_out0[513] */
    TRIG_IN_MUX_1_TCPWM0_GRP2_OUT0_2 = 0x00000117u, /* tcpwm[0].tr_out0[514] */
    TRIG_IN_MUX_1_TCPWM0_GRP2_OUT0_3 = 0x00000118u, /* tcpwm[0].tr_out0[515] */
    TRIG_IN_MUX_1_TCPWM0_GRP2_OUT0_4 = 0x00000119u, /* tcpwm[0].tr_out0[516] */
    TRIG_IN_MUX_1_TCPWM0_GRP2_OUT0_5 = 0x0000011Au, /* tcpwm[0].tr_out0[517] */
    TRIG_IN_MUX_1_TCPWM0_GRP2_OUT0_6 = 0x0000011Bu, /* tcpwm[0].tr_out0[518] */
    TRIG_IN_MUX_1_TCPWM0_GRP2_OUT0_7 = 0x0000011Cu, /* tcpwm[0].tr_out0[519] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT0     = 0x0000011Du, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT1     = 0x0000011Eu, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT2     = 0x0000011Fu, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT3     = 0x00000120u, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT4     = 0x00000121u, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT5     = 0x00000122u, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT6     = 0x00000123u, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT7     = 0x00000124u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT8     = 0x00000125u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT9     = 0x00000126u, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT10    = 0x00000127u, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT11    = 0x00000128u, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT12    = 0x00000129u, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT13    = 0x0000012Au, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT14    = 0x0000012Bu, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT15    = 0x0000012Cu, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT16    = 0x0000012Du, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT17    = 0x0000012Eu, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT18    = 0x0000012Fu, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT19    = 0x00000130u, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT20    = 0x00000131u, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT21    = 0x00000132u, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT22    = 0x00000133u, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT23    = 0x00000134u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT24    = 0x00000135u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT25    = 0x00000136u, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT26    = 0x00000137u, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT27    = 0x00000138u, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT28    = 0x00000139u, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT29    = 0x0000013Au, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT30    = 0x0000013Bu, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT31    = 0x0000013Cu, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT32    = 0x0000013Du, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT33    = 0x0000013Eu, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT34    = 0x0000013Fu, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT35    = 0x00000140u, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT36    = 0x00000141u, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT37    = 0x00000142u, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT38    = 0x00000143u, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT39    = 0x00000144u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT40    = 0x00000145u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT41    = 0x00000146u, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT42    = 0x00000147u, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT43    = 0x00000148u, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT44    = 0x00000149u, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT45    = 0x0000014Au, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT46    = 0x0000014Bu, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT47    = 0x0000014Cu, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT48    = 0x0000014Du, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT49    = 0x0000014Eu, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT50    = 0x0000014Fu, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT51    = 0x00000150u, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT52    = 0x00000151u, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT53    = 0x00000152u, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT54    = 0x00000153u, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT55    = 0x00000154u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT56    = 0x00000155u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT57    = 0x00000156u, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT58    = 0x00000157u, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT59    = 0x00000158u, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT60    = 0x00000159u, /* ioss.peri_tr_io_input_in[60] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT61    = 0x0000015Au, /* ioss.peri_tr_io_input_in[61] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT62    = 0x0000015Bu, /* ioss.peri_tr_io_input_in[62] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT63    = 0x0000015Cu, /* ioss.peri_tr_io_input_in[63] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT64    = 0x0000015Du, /* ioss.peri_tr_io_input_in[64] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT65    = 0x0000015Eu, /* ioss.peri_tr_io_input_in[65] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT66    = 0x0000015Fu, /* ioss.peri_tr_io_input_in[66] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT67    = 0x00000160u, /* ioss.peri_tr_io_input_in[67] */
    TRIG_IN_MUX_1_SCB_I2C_SCL0      = 0x00000161u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX0           = 0x00000162u, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX0           = 0x00000163u, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD00  = 0x00000164u, /* scb[0].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP00    = 0x00000165u, /* scb[0].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED00   = 0x00000166u, /* scb[0].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_SCB_I2C_SCL1      = 0x00000167u, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX1           = 0x00000168u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX1           = 0x00000169u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD10  = 0x0000016Au, /* scb[1].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP10    = 0x0000016Bu, /* scb[1].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED10   = 0x0000016Cu, /* scb[1].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_SCB_I2C_SCL2      = 0x0000016Du, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX2           = 0x0000016Eu, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX2           = 0x0000016Fu, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD20  = 0x00000170u, /* scb[2].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP20    = 0x00000171u, /* scb[2].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED20   = 0x00000172u, /* scb[2].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_SCB_I2C_SCL3      = 0x00000173u, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX3           = 0x00000174u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX3           = 0x00000175u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD30  = 0x00000176u, /* scb[3].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP30    = 0x00000177u, /* scb[3].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED30   = 0x00000178u, /* scb[3].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_SCB_I2C_SCL4      = 0x00000179u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX4           = 0x0000017Au, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX4           = 0x0000017Bu, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD40  = 0x0000017Cu, /* scb[4].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP40    = 0x0000017Du, /* scb[4].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED40   = 0x0000017Eu, /* scb[4].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_SCB_I2C_SCL5      = 0x0000017Fu, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_1_SCB_TX5           = 0x00000180u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_1_SCB_RX5           = 0x00000181u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_1_SCB_TGS_RELOAD50  = 0x00000182u, /* scb[5].tr_tgs_reload[0] */
    TRIG_IN_MUX_1_SCB_TGS_STOP50    = 0x00000183u, /* scb[5].tr_tgs_stop[0] */
    TRIG_IN_MUX_1_SCB_TGS_GATED50   = 0x00000184u, /* scb[5].tr_tgs_gated[0] */
    TRIG_IN_MUX_1_CTI_TR_OUT0       = 0x00000185u, /* debug600.cti_tr_out[0] */
    TRIG_IN_MUX_1_CTI_TR_OUT1       = 0x00000186u, /* debug600.cti_tr_out[1] */
    TRIG_IN_MUX_1_MXCORDIC_DONE     = 0x00000187u, /* cordic[0].tr_done_mxcordic */
    TRIG_IN_MUX_1_CANFD_TT_TR_OUT0  = 0x00000188u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_1_CANFD_TT_TR_OUT1  = 0x00000189u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_1_CAN_DBG0          = 0x0000018Au, /* canfd[0].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_1_CAN_DBG1          = 0x0000018Bu, /* canfd[0].tr_dbg_dma_req[1] */
    TRIG_IN_MUX_1_CAN_FIFO0_CH0     = 0x0000018Cu, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_MUX_1_CAN_FIFO0_CH1     = 0x0000018Du, /* canfd[0].tr_fifo0[1] */
    TRIG_IN_MUX_1_CAN_FIFO1_CH0     = 0x0000018Eu, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_MUX_1_CAN_FIFO1_CH1     = 0x0000018Fu, /* canfd[0].tr_fifo1[1] */
    TRIG_IN_MUX_1_LPCOMP_DSI_COMP0  = 0x00000190u, /* lpcomp.dsi_comp0 */
    TRIG_IN_MUX_1_LPCOMP_DSI_COMP1  = 0x00000191u, /* lpcomp.dsi_comp1 */
    TRIG_IN_MUX_1_CPUSS_TR_FAULT0   = 0x00000192u, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_1_TRNG_BITSTREAM    = 0x00000193u, /* cryptolite.tr_trng_bitstream */
    TRIG_IN_MUX_1_PASS_FIFO0        = 0x00000194u, /* pass.tr_fifo_level_out[0] */
    TRIG_IN_MUX_1_PASS_FIFO1        = 0x00000195u, /* pass.tr_fifo_level_out[1] */
    TRIG_IN_MUX_1_PASS_FIFO2        = 0x00000196u, /* pass.tr_fifo_level_out[2] */
    TRIG_IN_MUX_1_PASS_FIFO3        = 0x00000197u, /* pass.tr_fifo_level_out[3] */
    TRIG_IN_MUX_1_PASS_PULSE0       = 0x00000198u, /* pass.tr_pulse_out[0] */
    TRIG_IN_MUX_1_PASS_PULSE1       = 0x00000199u, /* pass.tr_pulse_out[1] */
    TRIG_IN_MUX_1_PASS_PULSE2       = 0x0000019Au, /* pass.tr_pulse_out[2] */
    TRIG_IN_MUX_1_PASS_PULSE3       = 0x0000019Bu, /* pass.tr_pulse_out[3] */
    TRIG_IN_MUX_1_PASS_PULSE4       = 0x0000019Cu, /* pass.tr_pulse_out[4] */
    TRIG_IN_MUX_1_PASS_PULSE5       = 0x0000019Du, /* pass.tr_pulse_out[5] */
    TRIG_IN_MUX_1_PASS_PULSE6       = 0x0000019Eu, /* pass.tr_pulse_out[6] */
    TRIG_IN_MUX_1_PASS_PULSE7       = 0x0000019Fu, /* pass.tr_pulse_out[7] */
    TRIG_IN_MUX_1_PASS_PULSE8       = 0x000001A0u, /* pass.tr_pulse_out[8] */
    TRIG_IN_MUX_1_PASS_PULSE9       = 0x000001A1u, /* pass.tr_pulse_out[9] */
    TRIG_IN_MUX_1_PASS_PULSE10      = 0x000001A2u, /* pass.tr_pulse_out[10] */
    TRIG_IN_MUX_1_PASS_PULSE11      = 0x000001A3u, /* pass.tr_pulse_out[11] */
    TRIG_IN_MUX_1_PASS_PULSE12      = 0x000001A4u, /* pass.tr_pulse_out[12] */
    TRIG_IN_MUX_1_PASS_PULSE13      = 0x000001A5u, /* pass.tr_pulse_out[13] */
    TRIG_IN_MUX_1_PASS_PULSE14      = 0x000001A6u, /* pass.tr_pulse_out[14] */
    TRIG_IN_MUX_1_PASS_PULSE15      = 0x000001A7u, /* pass.tr_pulse_out[15] */
    TRIG_IN_MUX_1_PASS_LEVEL0       = 0x000001A8u, /* pass.tr_level_out[0] */
    TRIG_IN_MUX_1_PASS_LEVEL1       = 0x000001A9u, /* pass.tr_level_out[1] */
    TRIG_IN_MUX_1_PASS_LEVEL2       = 0x000001AAu, /* pass.tr_level_out[2] */
    TRIG_IN_MUX_1_PASS_LEVEL3       = 0x000001ABu, /* pass.tr_level_out[3] */
    TRIG_IN_MUX_1_PASS_LEVEL4       = 0x000001ACu, /* pass.tr_level_out[4] */
    TRIG_IN_MUX_1_PASS_LEVEL5       = 0x000001ADu, /* pass.tr_level_out[5] */
    TRIG_IN_MUX_1_PASS_LEVEL6       = 0x000001AEu, /* pass.tr_level_out[6] */
    TRIG_IN_MUX_1_PASS_LEVEL7       = 0x000001AFu, /* pass.tr_level_out[7] */
    TRIG_IN_MUX_1_PASS_LEVEL8       = 0x000001B0u, /* pass.tr_level_out[8] */
    TRIG_IN_MUX_1_PASS_LEVEL9       = 0x000001B1u, /* pass.tr_level_out[9] */
    TRIG_IN_MUX_1_PASS_LEVEL10      = 0x000001B2u, /* pass.tr_level_out[10] */
    TRIG_IN_MUX_1_PASS_LEVEL11      = 0x000001B3u, /* pass.tr_level_out[11] */
    TRIG_IN_MUX_1_PASS_LEVEL12      = 0x000001B4u, /* pass.tr_level_out[12] */
    TRIG_IN_MUX_1_PASS_LEVEL13      = 0x000001B5u, /* pass.tr_level_out[13] */
    TRIG_IN_MUX_1_PASS_LEVEL14      = 0x000001B6u, /* pass.tr_level_out[14] */
    TRIG_IN_MUX_1_PASS_LEVEL15      = 0x000001B7u, /* pass.tr_level_out[15] */
    TRIG_IN_MUX_1_I3C_TX0           = 0x000001B8u, /* i3c[0].tr_tx_req */
    TRIG_IN_MUX_1_I3C_RX0           = 0x000001B9u, /* i3c[0].tr_rx_req */
    TRIG_IN_MUX_1_USB_DMA_REQ0      = 0x000001BAu, /* usb[0].usb_dma_req[0] */
    TRIG_IN_MUX_1_USB_DMA_REQ1      = 0x000001BBu, /* usb[0].usb_dma_req[1] */
    TRIG_IN_MUX_1_USB_DMA_REQ2      = 0x000001BCu, /* usb[0].usb_dma_req[2] */
    TRIG_IN_MUX_1_USB_DMA_REQ3      = 0x000001BDu, /* usb[0].usb_dma_req[3] */
    TRIG_IN_MUX_1_USB_DMA_REQ4      = 0x000001BEu, /* usb[0].usb_dma_req[4] */
    TRIG_IN_MUX_1_USB_DMA_REQ5      = 0x000001BFu, /* usb[0].usb_dma_req[5] */
    TRIG_IN_MUX_1_USB_DMA_REQ6      = 0x000001C0u, /* usb[0].usb_dma_req[6] */
    TRIG_IN_MUX_1_USB_DMA_REQ7      = 0x000001C1u /* usb[0].usb_dma_req[7] */
} en_trig_input_pdma1_tr_t;

/* Trigger Input Group 2 - HSIOM0 trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_2_PDMA0_TR_OUT0     = 0x00000201u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT1     = 0x00000202u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT2     = 0x00000203u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT3     = 0x00000204u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT4     = 0x00000205u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT5     = 0x00000206u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT6     = 0x00000207u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT7     = 0x00000208u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT8     = 0x00000209u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT9     = 0x0000020Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT10    = 0x0000020Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT11    = 0x0000020Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT12    = 0x0000020Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT13    = 0x0000020Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT14    = 0x0000020Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT15    = 0x00000210u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT0     = 0x00000211u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT1     = 0x00000212u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT2     = 0x00000213u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT3     = 0x00000214u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT4     = 0x00000215u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT5     = 0x00000216u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT6     = 0x00000217u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT7     = 0x00000218u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT8     = 0x00000219u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT9     = 0x0000021Au, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT10    = 0x0000021Bu, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT11    = 0x0000021Cu, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT12    = 0x0000021Du, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT13    = 0x0000021Eu, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT14    = 0x0000021Fu, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT15    = 0x00000220u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_OUT1_0 = 0x00000221u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_OUT1_1 = 0x00000222u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_OUT1_2 = 0x00000223u, /* tcpwm[0].tr_out1[2] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_OUT1_3 = 0x00000224u, /* tcpwm[0].tr_out1[3] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_OUT1_4 = 0x00000225u, /* tcpwm[0].tr_out1[4] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_OUT1_5 = 0x00000226u, /* tcpwm[0].tr_out1[5] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_OUT1_6 = 0x00000227u, /* tcpwm[0].tr_out1[6] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_OUT1_7 = 0x00000228u, /* tcpwm[0].tr_out1[7] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_OUT1_0 = 0x00000229u, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_OUT1_1 = 0x0000022Au, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_OUT1_2 = 0x0000022Bu, /* tcpwm[0].tr_out1[258] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_OUT1_3 = 0x0000022Cu, /* tcpwm[0].tr_out1[259] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_OUT1_4 = 0x0000022Du, /* tcpwm[0].tr_out1[260] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_OUT1_5 = 0x0000022Eu, /* tcpwm[0].tr_out1[261] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_OUT1_6 = 0x0000022Fu, /* tcpwm[0].tr_out1[262] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_OUT1_7 = 0x00000230u, /* tcpwm[0].tr_out1[263] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_OUT1_0 = 0x00000231u, /* tcpwm[0].tr_out1[512] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_OUT1_1 = 0x00000232u, /* tcpwm[0].tr_out1[513] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_OUT1_2 = 0x00000233u, /* tcpwm[0].tr_out1[514] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_OUT1_3 = 0x00000234u, /* tcpwm[0].tr_out1[515] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_OUT1_4 = 0x00000235u, /* tcpwm[0].tr_out1[516] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_OUT1_5 = 0x00000236u, /* tcpwm[0].tr_out1[517] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_OUT1_6 = 0x00000237u, /* tcpwm[0].tr_out1[518] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_OUT1_7 = 0x00000238u, /* tcpwm[0].tr_out1[519] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP1_TR_OUT0 = 0x00000239u, /* tcpwm[0].tr_motif_out[256] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP1_TR_OUT1 = 0x0000023Au, /* tcpwm[0].tr_motif_out[257] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP1_TR_OUT2 = 0x0000023Bu, /* tcpwm[0].tr_motif_out[258] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP1_TR_OUT3 = 0x0000023Cu, /* tcpwm[0].tr_motif_out[259] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP1_TR_OUT4 = 0x0000023Du, /* tcpwm[0].tr_motif_out[260] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP1_TR_OUT5 = 0x0000023Eu, /* tcpwm[0].tr_motif_out[261] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP1_TR_OUT6 = 0x0000023Fu, /* tcpwm[0].tr_motif_out[262] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP1_TR_OUT7 = 0x00000240u, /* tcpwm[0].tr_motif_out[263] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP2_TR_OUT0 = 0x00000241u, /* tcpwm[0].tr_motif_out[512] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP2_TR_OUT1 = 0x00000242u, /* tcpwm[0].tr_motif_out[513] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP2_TR_OUT2 = 0x00000243u, /* tcpwm[0].tr_motif_out[514] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP2_TR_OUT3 = 0x00000244u, /* tcpwm[0].tr_motif_out[515] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP2_TR_OUT4 = 0x00000245u, /* tcpwm[0].tr_motif_out[516] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP2_TR_OUT5 = 0x00000246u, /* tcpwm[0].tr_motif_out[517] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP2_TR_OUT6 = 0x00000247u, /* tcpwm[0].tr_motif_out[518] */
    TRIG_IN_MUX_2_TCPWM0_MOTIF_GRP2_TR_OUT7 = 0x00000248u, /* tcpwm[0].tr_motif_out[519] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_0 = 0x00000249u, /* tcpwm[0].tr_line[0] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_1 = 0x0000024Au, /* tcpwm[0].tr_line[1] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_2 = 0x0000024Bu, /* tcpwm[0].tr_line[2] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_3 = 0x0000024Cu, /* tcpwm[0].tr_line[3] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_4 = 0x0000024Du, /* tcpwm[0].tr_line[4] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_5 = 0x0000024Eu, /* tcpwm[0].tr_line[5] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_6 = 0x0000024Fu, /* tcpwm[0].tr_line[6] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_7 = 0x00000250u, /* tcpwm[0].tr_line[7] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_COMPL_0 = 0x00000251u, /* tcpwm[0].tr_line_compl[0] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_COMPL_1 = 0x00000252u, /* tcpwm[0].tr_line_compl[1] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_COMPL_2 = 0x00000253u, /* tcpwm[0].tr_line_compl[2] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_COMPL_3 = 0x00000254u, /* tcpwm[0].tr_line_compl[3] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_COMPL_4 = 0x00000255u, /* tcpwm[0].tr_line_compl[4] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_COMPL_5 = 0x00000256u, /* tcpwm[0].tr_line_compl[5] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_COMPL_6 = 0x00000257u, /* tcpwm[0].tr_line_compl[6] */
    TRIG_IN_MUX_2_TCPWM0_GRP0_LINE_COMPL_7 = 0x00000258u, /* tcpwm[0].tr_line_compl[7] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_256 = 0x00000259u, /* tcpwm[0].tr_line[256] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_257 = 0x0000025Au, /* tcpwm[0].tr_line[257] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_258 = 0x0000025Bu, /* tcpwm[0].tr_line[258] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_259 = 0x0000025Cu, /* tcpwm[0].tr_line[259] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_260 = 0x0000025Du, /* tcpwm[0].tr_line[260] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_261 = 0x0000025Eu, /* tcpwm[0].tr_line[261] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_262 = 0x0000025Fu, /* tcpwm[0].tr_line[262] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_263 = 0x00000260u, /* tcpwm[0].tr_line[263] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_256 = 0x00000261u, /* tcpwm[0].tr_line_compl[256] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_257 = 0x00000262u, /* tcpwm[0].tr_line_compl[257] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_258 = 0x00000263u, /* tcpwm[0].tr_line_compl[258] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_259 = 0x00000264u, /* tcpwm[0].tr_line_compl[259] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_260 = 0x00000265u, /* tcpwm[0].tr_line_compl[260] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_261 = 0x00000266u, /* tcpwm[0].tr_line_compl[261] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_262 = 0x00000267u, /* tcpwm[0].tr_line_compl[262] */
    TRIG_IN_MUX_2_TCPWM0_GRP1_LINE_COMPL_263 = 0x00000268u, /* tcpwm[0].tr_line_compl[263] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_512 = 0x00000269u, /* tcpwm[0].tr_line[512] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_513 = 0x0000026Au, /* tcpwm[0].tr_line[513] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_514 = 0x0000026Bu, /* tcpwm[0].tr_line[514] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_515 = 0x0000026Cu, /* tcpwm[0].tr_line[515] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_516 = 0x0000026Du, /* tcpwm[0].tr_line[516] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_517 = 0x0000026Eu, /* tcpwm[0].tr_line[517] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_518 = 0x0000026Fu, /* tcpwm[0].tr_line[518] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_519 = 0x00000270u, /* tcpwm[0].tr_line[519] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_COMPL_512 = 0x00000271u, /* tcpwm[0].tr_line_compl[512] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_COMPL_513 = 0x00000272u, /* tcpwm[0].tr_line_compl[513] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_COMPL_514 = 0x00000273u, /* tcpwm[0].tr_line_compl[514] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_COMPL_515 = 0x00000274u, /* tcpwm[0].tr_line_compl[515] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_COMPL_516 = 0x00000275u, /* tcpwm[0].tr_line_compl[516] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_COMPL_517 = 0x00000276u, /* tcpwm[0].tr_line_compl[517] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_COMPL_518 = 0x00000277u, /* tcpwm[0].tr_line_compl[518] */
    TRIG_IN_MUX_2_TCPWM0_GRP2_LINE_COMPL_519 = 0x00000278u, /* tcpwm[0].tr_line_compl[519] */
    TRIG_IN_MUX_2_SCB_I2C_SCL0      = 0x00000279u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_SCB_TX0           = 0x0000027Au, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_2_SCB_RX0           = 0x0000027Bu, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_2_SCB_TGS_RELOAD00  = 0x0000027Cu, /* scb[0].tr_tgs_reload[0] */
    TRIG_IN_MUX_2_SCB_TGS_STOP00    = 0x0000027Du, /* scb[0].tr_tgs_stop[0] */
    TRIG_IN_MUX_2_SCB_TGS_GATED00   = 0x0000027Eu, /* scb[0].tr_tgs_gated[0] */
    TRIG_IN_MUX_2_SCB_I2C_SCL1      = 0x0000027Fu, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_SCB_TX1           = 0x00000280u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_2_SCB_RX1           = 0x00000281u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_2_SCB_TGS_RELOAD10  = 0x00000282u, /* scb[1].tr_tgs_reload[0] */
    TRIG_IN_MUX_2_SCB_TGS_STOP10    = 0x00000283u, /* scb[1].tr_tgs_stop[0] */
    TRIG_IN_MUX_2_SCB_TGS_GATED10   = 0x00000284u, /* scb[1].tr_tgs_gated[0] */
    TRIG_IN_MUX_2_SCB_I2C_SCL2      = 0x00000285u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_SCB_TX2           = 0x00000286u, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_2_SCB_RX2           = 0x00000287u, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_2_SCB_TGS_RELOAD20  = 0x00000288u, /* scb[2].tr_tgs_reload[0] */
    TRIG_IN_MUX_2_SCB_TGS_STOP20    = 0x00000289u, /* scb[2].tr_tgs_stop[0] */
    TRIG_IN_MUX_2_SCB_TGS_GATED20   = 0x0000028Au, /* scb[2].tr_tgs_gated[0] */
    TRIG_IN_MUX_2_SCB_I2C_SCL3      = 0x0000028Bu, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_SCB_TX3           = 0x0000028Cu, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_2_SCB_RX3           = 0x0000028Du, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_2_SCB_TGS_RELOAD30  = 0x0000028Eu, /* scb[3].tr_tgs_reload[0] */
    TRIG_IN_MUX_2_SCB_TGS_STOP30    = 0x0000028Fu, /* scb[3].tr_tgs_stop[0] */
    TRIG_IN_MUX_2_SCB_TGS_GATED30   = 0x00000290u, /* scb[3].tr_tgs_gated[0] */
    TRIG_IN_MUX_2_SCB_I2C_SCL4      = 0x00000291u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_SCB_TX4           = 0x00000292u, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_2_SCB_RX4           = 0x00000293u, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_2_SCB_TGS_RELOAD40  = 0x00000294u, /* scb[4].tr_tgs_reload[0] */
    TRIG_IN_MUX_2_SCB_TGS_STOP40    = 0x00000295u, /* scb[4].tr_tgs_stop[0] */
    TRIG_IN_MUX_2_SCB_TGS_GATED40   = 0x00000296u, /* scb[4].tr_tgs_gated[0] */
    TRIG_IN_MUX_2_SCB_I2C_SCL5      = 0x00000297u, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_SCB_TX5           = 0x00000298u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_2_SCB_RX5           = 0x00000299u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_2_SCB_TGS_RELOAD50  = 0x0000029Au, /* scb[5].tr_tgs_reload[0] */
    TRIG_IN_MUX_2_SCB_TGS_STOP50    = 0x0000029Bu, /* scb[5].tr_tgs_stop[0] */
    TRIG_IN_MUX_2_SCB_TGS_GATED50   = 0x0000029Cu, /* scb[5].tr_tgs_gated[0] */
    TRIG_IN_MUX_2_CTI_TR_OUT0       = 0x0000029Du, /* debug600.cti_tr_out[0] */
    TRIG_IN_MUX_2_CTI_TR_OUT1       = 0x0000029Eu, /* debug600.cti_tr_out[1] */
    TRIG_IN_MUX_2_MXCORDIC_DONE     = 0x0000029Fu, /* cordic[0].tr_done_mxcordic */
    TRIG_IN_MUX_2_CANFD_TT_TR_OUT0  = 0x000002A0u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_2_CANFD_TT_TR_OUT1  = 0x000002A1u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_2_LPCOMP_DSI_COMP0  = 0x000002A2u, /* lpcomp.dsi_comp0 */
    TRIG_IN_MUX_2_LPCOMP_DSI_COMP1  = 0x000002A3u, /* lpcomp.dsi_comp1 */
    TRIG_IN_MUX_2_CPUSS_TR_FAULT0   = 0x000002A4u, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_2_TRNG_BITSTREAM    = 0x000002A5u, /* cryptolite.tr_trng_bitstream */
    TRIG_IN_MUX_2_PASS_FIFO0        = 0x000002A6u, /* pass.tr_fifo_level_out[0] */
    TRIG_IN_MUX_2_PASS_FIFO1        = 0x000002A7u, /* pass.tr_fifo_level_out[1] */
    TRIG_IN_MUX_2_PASS_FIFO2        = 0x000002A8u, /* pass.tr_fifo_level_out[2] */
    TRIG_IN_MUX_2_PASS_FIFO3        = 0x000002A9u, /* pass.tr_fifo_level_out[3] */
    TRIG_IN_MUX_2_PASS_PULSE0       = 0x000002AAu, /* pass.tr_pulse_out[0] */
    TRIG_IN_MUX_2_PASS_PULSE1       = 0x000002ABu, /* pass.tr_pulse_out[1] */
    TRIG_IN_MUX_2_PASS_PULSE2       = 0x000002ACu, /* pass.tr_pulse_out[2] */
    TRIG_IN_MUX_2_PASS_PULSE3       = 0x000002ADu, /* pass.tr_pulse_out[3] */
    TRIG_IN_MUX_2_PASS_PULSE4       = 0x000002AEu, /* pass.tr_pulse_out[4] */
    TRIG_IN_MUX_2_PASS_PULSE5       = 0x000002AFu, /* pass.tr_pulse_out[5] */
    TRIG_IN_MUX_2_PASS_PULSE6       = 0x000002B0u, /* pass.tr_pulse_out[6] */
    TRIG_IN_MUX_2_PASS_PULSE7       = 0x000002B1u, /* pass.tr_pulse_out[7] */
    TRIG_IN_MUX_2_PASS_PULSE8       = 0x000002B2u, /* pass.tr_pulse_out[8] */
    TRIG_IN_MUX_2_PASS_PULSE9       = 0x000002B3u, /* pass.tr_pulse_out[9] */
    TRIG_IN_MUX_2_PASS_PULSE10      = 0x000002B4u, /* pass.tr_pulse_out[10] */
    TRIG_IN_MUX_2_PASS_PULSE11      = 0x000002B5u, /* pass.tr_pulse_out[11] */
    TRIG_IN_MUX_2_PASS_PULSE12      = 0x000002B6u, /* pass.tr_pulse_out[12] */
    TRIG_IN_MUX_2_PASS_PULSE13      = 0x000002B7u, /* pass.tr_pulse_out[13] */
    TRIG_IN_MUX_2_PASS_PULSE14      = 0x000002B8u, /* pass.tr_pulse_out[14] */
    TRIG_IN_MUX_2_PASS_PULSE15      = 0x000002B9u, /* pass.tr_pulse_out[15] */
    TRIG_IN_MUX_2_PASS_LEVEL0       = 0x000002BAu, /* pass.tr_level_out[0] */
    TRIG_IN_MUX_2_PASS_LEVEL1       = 0x000002BBu, /* pass.tr_level_out[1] */
    TRIG_IN_MUX_2_PASS_LEVEL2       = 0x000002BCu, /* pass.tr_level_out[2] */
    TRIG_IN_MUX_2_PASS_LEVEL3       = 0x000002BDu, /* pass.tr_level_out[3] */
    TRIG_IN_MUX_2_PASS_LEVEL4       = 0x000002BEu, /* pass.tr_level_out[4] */
    TRIG_IN_MUX_2_PASS_LEVEL5       = 0x000002BFu, /* pass.tr_level_out[5] */
    TRIG_IN_MUX_2_PASS_LEVEL6       = 0x000002C0u, /* pass.tr_level_out[6] */
    TRIG_IN_MUX_2_PASS_LEVEL7       = 0x000002C1u, /* pass.tr_level_out[7] */
    TRIG_IN_MUX_2_PASS_LEVEL8       = 0x000002C2u, /* pass.tr_level_out[8] */
    TRIG_IN_MUX_2_PASS_LEVEL9       = 0x000002C3u, /* pass.tr_level_out[9] */
    TRIG_IN_MUX_2_PASS_LEVEL10      = 0x000002C4u, /* pass.tr_level_out[10] */
    TRIG_IN_MUX_2_PASS_LEVEL11      = 0x000002C5u, /* pass.tr_level_out[11] */
    TRIG_IN_MUX_2_PASS_LEVEL12      = 0x000002C6u, /* pass.tr_level_out[12] */
    TRIG_IN_MUX_2_PASS_LEVEL13      = 0x000002C7u, /* pass.tr_level_out[13] */
    TRIG_IN_MUX_2_PASS_LEVEL14      = 0x000002C8u, /* pass.tr_level_out[14] */
    TRIG_IN_MUX_2_PASS_LEVEL15      = 0x000002C9u, /* pass.tr_level_out[15] */
    TRIG_IN_MUX_2_I3C_TX0           = 0x000002CAu, /* i3c[0].tr_tx_req */
    TRIG_IN_MUX_2_I3C_RX0           = 0x000002CBu /* i3c[0].tr_rx_req */
} en_trig_input_hsiom0_t;

/* Trigger Input Group 3 - HSIOMLOOP tigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_3_HSIOM_TR_OUT0     = 0x00000301u, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT1     = 0x00000302u, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT2     = 0x00000303u, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT3     = 0x00000304u, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT4     = 0x00000305u, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT5     = 0x00000306u, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT6     = 0x00000307u, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT7     = 0x00000308u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT8     = 0x00000309u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT9     = 0x0000030Au, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT10    = 0x0000030Bu, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT11    = 0x0000030Cu, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT12    = 0x0000030Du, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT13    = 0x0000030Eu, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT14    = 0x0000030Fu, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT15    = 0x00000310u, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT16    = 0x00000311u, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT17    = 0x00000312u, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT18    = 0x00000313u, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT19    = 0x00000314u, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT20    = 0x00000315u, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT21    = 0x00000316u, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT22    = 0x00000317u, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT23    = 0x00000318u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT24    = 0x00000319u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT25    = 0x0000031Au, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT26    = 0x0000031Bu, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT27    = 0x0000031Cu, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT28    = 0x0000031Du, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT29    = 0x0000031Eu, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT30    = 0x0000031Fu, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT31    = 0x00000320u, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT32    = 0x00000321u, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT33    = 0x00000322u, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT34    = 0x00000323u, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT35    = 0x00000324u, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT36    = 0x00000325u, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT37    = 0x00000326u, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT38    = 0x00000327u, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT39    = 0x00000328u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT40    = 0x00000329u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT41    = 0x0000032Au, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT42    = 0x0000032Bu, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT43    = 0x0000032Cu, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT44    = 0x0000032Du, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT45    = 0x0000032Eu, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT46    = 0x0000032Fu, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT47    = 0x00000330u, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT48    = 0x00000331u, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT49    = 0x00000332u, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT50    = 0x00000333u, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT51    = 0x00000334u, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT52    = 0x00000335u, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT53    = 0x00000336u, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT54    = 0x00000337u, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT55    = 0x00000338u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT56    = 0x00000339u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT57    = 0x0000033Au, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT58    = 0x0000033Bu, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT59    = 0x0000033Cu, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT60    = 0x0000033Du, /* ioss.peri_tr_io_input_in[60] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT61    = 0x0000033Eu, /* ioss.peri_tr_io_input_in[61] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT62    = 0x0000033Fu, /* ioss.peri_tr_io_input_in[62] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT63    = 0x00000340u, /* ioss.peri_tr_io_input_in[63] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT64    = 0x00000341u, /* ioss.peri_tr_io_input_in[64] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT65    = 0x00000342u, /* ioss.peri_tr_io_input_in[65] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT66    = 0x00000343u, /* ioss.peri_tr_io_input_in[66] */
    TRIG_IN_MUX_3_HSIOM_TR_OUT67    = 0x00000344u /* ioss.peri_tr_io_input_in[67] */
} en_trig_input_hsiomloop_t;

/* Trigger Input Group 4 - HSIOM1 trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_4_TCPWM0_GRP0_LINE0 = 0x00000401u, /* tcpwm[0].tr_line[0] */
    TRIG_IN_MUX_4_TCPWM0_GRP0_LINE1 = 0x00000402u, /* tcpwm[0].tr_line[1] */
    TRIG_IN_MUX_4_TCPWM0_GRP0_LINE2 = 0x00000403u, /* tcpwm[0].tr_line[2] */
    TRIG_IN_MUX_4_TCPWM0_GRP0_LINE3 = 0x00000404u, /* tcpwm[0].tr_line[3] */
    TRIG_IN_MUX_4_TCPWM0_GRP0_LINE_COMPL0 = 0x00000405u, /* tcpwm[0].tr_line_compl[0] */
    TRIG_IN_MUX_4_TCPWM0_GRP0_LINE_COMPL1 = 0x00000406u, /* tcpwm[0].tr_line_compl[1] */
    TRIG_IN_MUX_4_TCPWM0_GRP0_LINE_COMPL2 = 0x00000407u, /* tcpwm[0].tr_line_compl[2] */
    TRIG_IN_MUX_4_TCPWM0_GRP0_LINE_COMPL3 = 0x00000408u /* tcpwm[0].tr_line_compl[3] */
} en_trig_input_hsiom1_t;

/* Trigger Input Group 5 - HSIOM2 trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_5_TCPWM0_GRP1_LINE0 = 0x00000501u, /* tcpwm[0].tr_line[256] */
    TRIG_IN_MUX_5_TCPWM0_GRP1_LINE1 = 0x00000502u, /* tcpwm[0].tr_line[257] */
    TRIG_IN_MUX_5_TCPWM0_GRP1_LINE2 = 0x00000503u, /* tcpwm[0].tr_line[258] */
    TRIG_IN_MUX_5_TCPWM0_GRP1_LINE3 = 0x00000504u, /* tcpwm[0].tr_line[259] */
    TRIG_IN_MUX_5_TCPWM0_GRP1_LINE_COMPL0 = 0x00000505u, /* tcpwm[0].tr_line_compl[256] */
    TRIG_IN_MUX_5_TCPWM0_GRP1_LINE_COMPL1 = 0x00000506u, /* tcpwm[0].tr_line_compl[257] */
    TRIG_IN_MUX_5_TCPWM0_GRP1_LINE_COMPL2 = 0x00000507u, /* tcpwm[0].tr_line_compl[258] */
    TRIG_IN_MUX_5_TCPWM0_GRP1_LINE_COMPL3 = 0x00000508u /* tcpwm[0].tr_line_compl[259] */
} en_trig_input_hsiom2_t;

/* Trigger Input Group 6 - HSIOM3 trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_6_TCPWM0_GRP2_LINE0 = 0x00000601u, /* tcpwm[0].tr_line[512] */
    TRIG_IN_MUX_6_TCPWM0_GRP2_LINE1 = 0x00000602u, /* tcpwm[0].tr_line[513] */
    TRIG_IN_MUX_6_TCPWM0_GRP2_LINE2 = 0x00000603u, /* tcpwm[0].tr_line[514] */
    TRIG_IN_MUX_6_TCPWM0_GRP2_LINE3 = 0x00000604u, /* tcpwm[0].tr_line[515] */
    TRIG_IN_MUX_6_TCPWM0_GRP2_LINE_COMPL0 = 0x00000605u, /* tcpwm[0].tr_line_compl[512] */
    TRIG_IN_MUX_6_TCPWM0_GRP2_LINE_COMPL1 = 0x00000606u, /* tcpwm[0].tr_line_compl[513] */
    TRIG_IN_MUX_6_TCPWM0_GRP2_LINE_COMPL2 = 0x00000607u, /* tcpwm[0].tr_line_compl[514] */
    TRIG_IN_MUX_6_TCPWM0_GRP2_LINE_COMPL3 = 0x00000608u /* tcpwm[0].tr_line_compl[515] */
} en_trig_input_hsiom3_t;

/* Trigger Input Group 7 - CPUSS Debug  multiplexer */
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
    TRIG_IN_MUX_7_PDMA1_TR_OUT0     = 0x00000711u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT1     = 0x00000712u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT2     = 0x00000713u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT3     = 0x00000714u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT4     = 0x00000715u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT5     = 0x00000716u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT6     = 0x00000717u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT7     = 0x00000718u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT8     = 0x00000719u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT9     = 0x0000071Au, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT10    = 0x0000071Bu, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT11    = 0x0000071Cu, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT12    = 0x0000071Du, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT13    = 0x0000071Eu, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT14    = 0x0000071Fu, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT15    = 0x00000720u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_0 = 0x00000721u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_1 = 0x00000722u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_2 = 0x00000723u, /* tcpwm[0].tr_out1[2] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_3 = 0x00000724u, /* tcpwm[0].tr_out1[3] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_4 = 0x00000725u, /* tcpwm[0].tr_out1[4] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_5 = 0x00000726u, /* tcpwm[0].tr_out1[5] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_6 = 0x00000727u, /* tcpwm[0].tr_out1[6] */
    TRIG_IN_MUX_7_TCPWM0_GRP0_OUT1_7 = 0x00000728u, /* tcpwm[0].tr_out1[7] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_OUT1_0 = 0x00000729u, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_OUT1_1 = 0x0000072Au, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_OUT1_2 = 0x0000072Bu, /* tcpwm[0].tr_out1[258] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_OUT1_3 = 0x0000072Cu, /* tcpwm[0].tr_out1[259] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_OUT1_4 = 0x0000072Du, /* tcpwm[0].tr_out1[260] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_OUT1_5 = 0x0000072Eu, /* tcpwm[0].tr_out1[261] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_OUT1_6 = 0x0000072Fu, /* tcpwm[0].tr_out1[262] */
    TRIG_IN_MUX_7_TCPWM0_GRP1_OUT1_7 = 0x00000730u, /* tcpwm[0].tr_out1[263] */
    TRIG_IN_MUX_7_TCPWM0_GRP2_OUT1_0 = 0x00000731u, /* tcpwm[0].tr_out1[512] */
    TRIG_IN_MUX_7_TCPWM0_GRP2_OUT1_1 = 0x00000732u, /* tcpwm[0].tr_out1[513] */
    TRIG_IN_MUX_7_TCPWM0_GRP2_OUT1_2 = 0x00000733u, /* tcpwm[0].tr_out1[514] */
    TRIG_IN_MUX_7_TCPWM0_GRP2_OUT1_3 = 0x00000734u, /* tcpwm[0].tr_out1[515] */
    TRIG_IN_MUX_7_TCPWM0_GRP2_OUT1_4 = 0x00000735u, /* tcpwm[0].tr_out1[516] */
    TRIG_IN_MUX_7_TCPWM0_GRP2_OUT1_5 = 0x00000736u, /* tcpwm[0].tr_out1[517] */
    TRIG_IN_MUX_7_TCPWM0_GRP2_OUT1_6 = 0x00000737u, /* tcpwm[0].tr_out1[518] */
    TRIG_IN_MUX_7_TCPWM0_GRP2_OUT1_7 = 0x00000738u, /* tcpwm[0].tr_out1[519] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP1_TR_OUT0 = 0x00000739u, /* tcpwm[0].tr_motif_out[256] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP1_TR_OUT1 = 0x0000073Au, /* tcpwm[0].tr_motif_out[257] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP1_TR_OUT2 = 0x0000073Bu, /* tcpwm[0].tr_motif_out[258] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP1_TR_OUT3 = 0x0000073Cu, /* tcpwm[0].tr_motif_out[259] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP1_TR_OUT4 = 0x0000073Du, /* tcpwm[0].tr_motif_out[260] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP1_TR_OUT5 = 0x0000073Eu, /* tcpwm[0].tr_motif_out[261] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP1_TR_OUT6 = 0x0000073Fu, /* tcpwm[0].tr_motif_out[262] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP1_TR_OUT7 = 0x00000740u, /* tcpwm[0].tr_motif_out[263] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP2_TR_OUT0 = 0x00000741u, /* tcpwm[0].tr_motif_out[512] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP2_TR_OUT1 = 0x00000742u, /* tcpwm[0].tr_motif_out[513] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP2_TR_OUT2 = 0x00000743u, /* tcpwm[0].tr_motif_out[514] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP2_TR_OUT3 = 0x00000744u, /* tcpwm[0].tr_motif_out[515] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP2_TR_OUT4 = 0x00000745u, /* tcpwm[0].tr_motif_out[516] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP2_TR_OUT5 = 0x00000746u, /* tcpwm[0].tr_motif_out[517] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP2_TR_OUT6 = 0x00000747u, /* tcpwm[0].tr_motif_out[518] */
    TRIG_IN_MUX_7_TCPWM0_MOTIF_GRP2_TR_OUT7 = 0x00000748u, /* tcpwm[0].tr_motif_out[519] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT0     = 0x00000749u, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT1     = 0x0000074Au, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT2     = 0x0000074Bu, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT3     = 0x0000074Cu, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT4     = 0x0000074Du, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT5     = 0x0000074Eu, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT6     = 0x0000074Fu, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT7     = 0x00000750u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT8     = 0x00000751u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT9     = 0x00000752u, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT10    = 0x00000753u, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT11    = 0x00000754u, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT12    = 0x00000755u, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT13    = 0x00000756u, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT14    = 0x00000757u, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT15    = 0x00000758u, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT16    = 0x00000759u, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT17    = 0x0000075Au, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT18    = 0x0000075Bu, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT19    = 0x0000075Cu, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT20    = 0x0000075Du, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT21    = 0x0000075Eu, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT22    = 0x0000075Fu, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT23    = 0x00000760u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT24    = 0x00000761u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT25    = 0x00000762u, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT26    = 0x00000763u, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT27    = 0x00000764u, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT28    = 0x00000765u, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT29    = 0x00000766u, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT30    = 0x00000767u, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT31    = 0x00000768u, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT32    = 0x00000769u, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT33    = 0x0000076Au, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT34    = 0x0000076Bu, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT35    = 0x0000076Cu, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT36    = 0x0000076Du, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT37    = 0x0000076Eu, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT38    = 0x0000076Fu, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT39    = 0x00000770u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT40    = 0x00000771u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT41    = 0x00000772u, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT42    = 0x00000773u, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT43    = 0x00000774u, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT44    = 0x00000775u, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT45    = 0x00000776u, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT46    = 0x00000777u, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT47    = 0x00000778u, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT48    = 0x00000779u, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT49    = 0x0000077Au, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT50    = 0x0000077Bu, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT51    = 0x0000077Cu, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT52    = 0x0000077Du, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT53    = 0x0000077Eu, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT54    = 0x0000077Fu, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT55    = 0x00000780u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT56    = 0x00000781u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT57    = 0x00000782u, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT58    = 0x00000783u, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT59    = 0x00000784u, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT60    = 0x00000785u, /* ioss.peri_tr_io_input_in[60] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT61    = 0x00000786u, /* ioss.peri_tr_io_input_in[61] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT62    = 0x00000787u, /* ioss.peri_tr_io_input_in[62] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT63    = 0x00000788u, /* ioss.peri_tr_io_input_in[63] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT64    = 0x00000789u, /* ioss.peri_tr_io_input_in[64] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT65    = 0x0000078Au, /* ioss.peri_tr_io_input_in[65] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT66    = 0x0000078Bu, /* ioss.peri_tr_io_input_in[66] */
    TRIG_IN_MUX_7_HSIOM_TR_OUT67    = 0x0000078Cu, /* ioss.peri_tr_io_input_in[67] */
    TRIG_IN_MUX_7_SCB_I2C_SCL0      = 0x0000078Du, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX0           = 0x0000078Eu, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX0           = 0x0000078Fu, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_7_SCB_TGS_RELOAD00  = 0x00000790u, /* scb[0].tr_tgs_reload[0] */
    TRIG_IN_MUX_7_SCB_TGS_STOP00    = 0x00000791u, /* scb[0].tr_tgs_stop[0] */
    TRIG_IN_MUX_7_SCB_TGS_GATED00   = 0x00000792u, /* scb[0].tr_tgs_gated[0] */
    TRIG_IN_MUX_7_SCB_I2C_SCL1      = 0x00000793u, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX1           = 0x00000794u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX1           = 0x00000795u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_7_SCB_I2C_SCL2      = 0x00000796u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX2           = 0x00000797u, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX2           = 0x00000798u, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_7_SCB_I2C_SCL3      = 0x00000799u, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX3           = 0x0000079Au, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX3           = 0x0000079Bu, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_7_SCB_I2C_SCL4      = 0x0000079Cu, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX4           = 0x0000079Du, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX4           = 0x0000079Eu, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_7_SCB_I2C_SCL5      = 0x0000079Fu, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_7_SCB_TX5           = 0x000007A0u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_7_SCB_RX5           = 0x000007A1u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_7_SCB_TGS_RELOAD50  = 0x000007A2u, /* scb[5].tr_tgs_reload[0] */
    TRIG_IN_MUX_7_SCB_TGS_STOP50    = 0x000007A3u, /* scb[5].tr_tgs_stop[0] */
    TRIG_IN_MUX_7_SCB_TGS_GATED50   = 0x000007A4u, /* scb[5].tr_tgs_gated[0] */
    TRIG_IN_MUX_7_CTI_TR_OUT0       = 0x000007A5u, /* debug600.cti_tr_out[0] */
    TRIG_IN_MUX_7_CTI_TR_OUT1       = 0x000007A6u, /* debug600.cti_tr_out[1] */
    TRIG_IN_MUX_7_MXCORDIC_DONE     = 0x000007A7u, /* cordic[0].tr_done_mxcordic */
    TRIG_IN_MUX_7_CANFD_TT_TR_OUT0  = 0x000007A8u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_7_CANFD_TT_TR_OUT1  = 0x000007A9u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_7_LPCOMP_DSI_COMP0  = 0x000007AAu, /* lpcomp.dsi_comp0 */
    TRIG_IN_MUX_7_LPCOMP_DSI_COMP1  = 0x000007ABu, /* lpcomp.dsi_comp1 */
    TRIG_IN_MUX_7_CPUSS_TR_FAULT0   = 0x000007ACu, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_7_PASS_FIFO0        = 0x000007ADu, /* pass.tr_fifo_level_out[0] */
    TRIG_IN_MUX_7_PASS_FIFO1        = 0x000007AEu, /* pass.tr_fifo_level_out[1] */
    TRIG_IN_MUX_7_PASS_FIFO2        = 0x000007AFu, /* pass.tr_fifo_level_out[2] */
    TRIG_IN_MUX_7_PASS_FIFO3        = 0x000007B0u, /* pass.tr_fifo_level_out[3] */
    TRIG_IN_MUX_7_PASS_PULSE0       = 0x000007B1u, /* pass.tr_pulse_out[0] */
    TRIG_IN_MUX_7_PASS_PULSE1       = 0x000007B2u, /* pass.tr_pulse_out[1] */
    TRIG_IN_MUX_7_PASS_PULSE2       = 0x000007B3u, /* pass.tr_pulse_out[2] */
    TRIG_IN_MUX_7_PASS_PULSE3       = 0x000007B4u, /* pass.tr_pulse_out[3] */
    TRIG_IN_MUX_7_PASS_PULSE4       = 0x000007B5u, /* pass.tr_pulse_out[4] */
    TRIG_IN_MUX_7_PASS_PULSE5       = 0x000007B6u, /* pass.tr_pulse_out[5] */
    TRIG_IN_MUX_7_PASS_PULSE6       = 0x000007B7u, /* pass.tr_pulse_out[6] */
    TRIG_IN_MUX_7_PASS_PULSE7       = 0x000007B8u, /* pass.tr_pulse_out[7] */
    TRIG_IN_MUX_7_PASS_PULSE8       = 0x000007B9u, /* pass.tr_pulse_out[8] */
    TRIG_IN_MUX_7_PASS_PULSE9       = 0x000007BAu, /* pass.tr_pulse_out[9] */
    TRIG_IN_MUX_7_PASS_PULSE10      = 0x000007BBu, /* pass.tr_pulse_out[10] */
    TRIG_IN_MUX_7_PASS_PULSE11      = 0x000007BCu, /* pass.tr_pulse_out[11] */
    TRIG_IN_MUX_7_PASS_PULSE12      = 0x000007BDu, /* pass.tr_pulse_out[12] */
    TRIG_IN_MUX_7_PASS_PULSE13      = 0x000007BEu, /* pass.tr_pulse_out[13] */
    TRIG_IN_MUX_7_PASS_PULSE14      = 0x000007BFu, /* pass.tr_pulse_out[14] */
    TRIG_IN_MUX_7_PASS_PULSE15      = 0x000007C0u, /* pass.tr_pulse_out[15] */
    TRIG_IN_MUX_7_PASS_LEVEL0       = 0x000007C1u, /* pass.tr_level_out[0] */
    TRIG_IN_MUX_7_PASS_LEVEL1       = 0x000007C2u, /* pass.tr_level_out[1] */
    TRIG_IN_MUX_7_PASS_LEVEL2       = 0x000007C3u, /* pass.tr_level_out[2] */
    TRIG_IN_MUX_7_PASS_LEVEL3       = 0x000007C4u, /* pass.tr_level_out[3] */
    TRIG_IN_MUX_7_PASS_LEVEL4       = 0x000007C5u, /* pass.tr_level_out[4] */
    TRIG_IN_MUX_7_PASS_LEVEL5       = 0x000007C6u, /* pass.tr_level_out[5] */
    TRIG_IN_MUX_7_PASS_LEVEL6       = 0x000007C7u, /* pass.tr_level_out[6] */
    TRIG_IN_MUX_7_PASS_LEVEL7       = 0x000007C8u, /* pass.tr_level_out[7] */
    TRIG_IN_MUX_7_PASS_LEVEL8       = 0x000007C9u, /* pass.tr_level_out[8] */
    TRIG_IN_MUX_7_PASS_LEVEL9       = 0x000007CAu, /* pass.tr_level_out[9] */
    TRIG_IN_MUX_7_PASS_LEVEL10      = 0x000007CBu, /* pass.tr_level_out[10] */
    TRIG_IN_MUX_7_PASS_LEVEL11      = 0x000007CCu, /* pass.tr_level_out[11] */
    TRIG_IN_MUX_7_PASS_LEVEL12      = 0x000007CDu, /* pass.tr_level_out[12] */
    TRIG_IN_MUX_7_PASS_LEVEL13      = 0x000007CEu, /* pass.tr_level_out[13] */
    TRIG_IN_MUX_7_PASS_LEVEL14      = 0x000007CFu, /* pass.tr_level_out[14] */
    TRIG_IN_MUX_7_PASS_LEVEL15      = 0x000007D0u, /* pass.tr_level_out[15] */
    TRIG_IN_MUX_7_I3C_TX0           = 0x000007D1u, /* i3c[0].tr_tx_req */
    TRIG_IN_MUX_7_I3C_RX0           = 0x000007D2u, /* i3c[0].tr_rx_req */
    TRIG_IN_MUX_7_USB_DMA_REQ0      = 0x000007D3u, /* usb[0].usb_dma_req[0] */
    TRIG_IN_MUX_7_USB_DMA_REQ1      = 0x000007D4u, /* usb[0].usb_dma_req[1] */
    TRIG_IN_MUX_7_USB_DMA_REQ2      = 0x000007D5u, /* usb[0].usb_dma_req[2] */
    TRIG_IN_MUX_7_USB_DMA_REQ3      = 0x000007D6u, /* usb[0].usb_dma_req[3] */
    TRIG_IN_MUX_7_USB_DMA_REQ4      = 0x000007D7u, /* usb[0].usb_dma_req[4] */
    TRIG_IN_MUX_7_USB_DMA_REQ5      = 0x000007D8u, /* usb[0].usb_dma_req[5] */
    TRIG_IN_MUX_7_USB_DMA_REQ6      = 0x000007D9u, /* usb[0].usb_dma_req[6] */
    TRIG_IN_MUX_7_USB_DMA_REQ7      = 0x000007DAu /* usb[0].usb_dma_req[7] */
} en_trig_input_cpuss_cti_t;

/* Trigger Input Group 8 - CAN TT Synchronization triggers */
typedef enum
{
    TRIG_IN_MUX_8_CAN_TT_TR_OUT0    = 0x00000801u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_8_CAN_TT_TR_OUT1    = 0x00000802u /* canfd[0].tr_tmp_rtp_out[1] */
} en_trig_input_cantt_t;

/* Trigger Input Group 9 - PERI Freeze trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_9_CPUSS_TR_FAULT0   = 0x00000901u, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_9_CTI_TR_OUT0       = 0x00000902u, /* debug600.cti_tr_out[0] */
    TRIG_IN_MUX_9_CTI_TR_OUT1       = 0x00000903u /* debug600.cti_tr_out[1] */
} en_trig_input_peri_freeze_t;

/* Trigger Input Group 10 - TCPWM0 trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_10_LPCOMP_DSI_COMP0 = 0x00000A01u, /* lpcomp.dsi_comp0 */
    TRIG_IN_MUX_10_LPCOMP_DSI_COMP1 = 0x00000A02u, /* lpcomp.dsi_comp1 */
    TRIG_IN_MUX_10_PASS_FIFO0       = 0x00000A03u, /* pass.tr_fifo_level_out[0] */
    TRIG_IN_MUX_10_PASS_FIFO1       = 0x00000A04u, /* pass.tr_fifo_level_out[1] */
    TRIG_IN_MUX_10_PASS_FIFO2       = 0x00000A05u, /* pass.tr_fifo_level_out[2] */
    TRIG_IN_MUX_10_PASS_FIFO3       = 0x00000A06u, /* pass.tr_fifo_level_out[3] */
    TRIG_IN_MUX_10_PASS_PULSE0      = 0x00000A07u, /* pass.tr_pulse_out[0] */
    TRIG_IN_MUX_10_PASS_PULSE1      = 0x00000A08u, /* pass.tr_pulse_out[1] */
    TRIG_IN_MUX_10_PASS_PULSE2      = 0x00000A09u, /* pass.tr_pulse_out[2] */
    TRIG_IN_MUX_10_PASS_PULSE3      = 0x00000A0Au, /* pass.tr_pulse_out[3] */
    TRIG_IN_MUX_10_PASS_PULSE4      = 0x00000A0Bu, /* pass.tr_pulse_out[4] */
    TRIG_IN_MUX_10_PASS_PULSE5      = 0x00000A0Cu, /* pass.tr_pulse_out[5] */
    TRIG_IN_MUX_10_PASS_PULSE6      = 0x00000A0Du, /* pass.tr_pulse_out[6] */
    TRIG_IN_MUX_10_PASS_PULSE7      = 0x00000A0Eu, /* pass.tr_pulse_out[7] */
    TRIG_IN_MUX_10_PASS_PULSE8      = 0x00000A0Fu, /* pass.tr_pulse_out[8] */
    TRIG_IN_MUX_10_PASS_PULSE9      = 0x00000A10u, /* pass.tr_pulse_out[9] */
    TRIG_IN_MUX_10_PASS_PULSE10     = 0x00000A11u, /* pass.tr_pulse_out[10] */
    TRIG_IN_MUX_10_PASS_PULSE11     = 0x00000A12u, /* pass.tr_pulse_out[11] */
    TRIG_IN_MUX_10_PASS_PULSE12     = 0x00000A13u, /* pass.tr_pulse_out[12] */
    TRIG_IN_MUX_10_PASS_PULSE13     = 0x00000A14u, /* pass.tr_pulse_out[13] */
    TRIG_IN_MUX_10_PASS_PULSE14     = 0x00000A15u, /* pass.tr_pulse_out[14] */
    TRIG_IN_MUX_10_PASS_PULSE15     = 0x00000A16u, /* pass.tr_pulse_out[15] */
    TRIG_IN_MUX_10_PASS_LEVEL0      = 0x00000A17u, /* pass.tr_level_out[0] */
    TRIG_IN_MUX_10_PASS_LEVEL1      = 0x00000A18u, /* pass.tr_level_out[1] */
    TRIG_IN_MUX_10_PASS_LEVEL2      = 0x00000A19u, /* pass.tr_level_out[2] */
    TRIG_IN_MUX_10_PASS_LEVEL3      = 0x00000A1Au, /* pass.tr_level_out[3] */
    TRIG_IN_MUX_10_PASS_LEVEL4      = 0x00000A1Bu, /* pass.tr_level_out[4] */
    TRIG_IN_MUX_10_PASS_LEVEL5      = 0x00000A1Cu, /* pass.tr_level_out[5] */
    TRIG_IN_MUX_10_PASS_LEVEL6      = 0x00000A1Du, /* pass.tr_level_out[6] */
    TRIG_IN_MUX_10_PASS_LEVEL7      = 0x00000A1Eu, /* pass.tr_level_out[7] */
    TRIG_IN_MUX_10_PASS_LEVEL8      = 0x00000A1Fu, /* pass.tr_level_out[8] */
    TRIG_IN_MUX_10_PASS_LEVEL9      = 0x00000A20u, /* pass.tr_level_out[9] */
    TRIG_IN_MUX_10_PASS_LEVEL10     = 0x00000A21u, /* pass.tr_level_out[10] */
    TRIG_IN_MUX_10_PASS_LEVEL11     = 0x00000A22u, /* pass.tr_level_out[11] */
    TRIG_IN_MUX_10_PASS_LEVEL12     = 0x00000A23u, /* pass.tr_level_out[12] */
    TRIG_IN_MUX_10_PASS_LEVEL13     = 0x00000A24u, /* pass.tr_level_out[13] */
    TRIG_IN_MUX_10_PASS_LEVEL14     = 0x00000A25u, /* pass.tr_level_out[14] */
    TRIG_IN_MUX_10_PASS_LEVEL15     = 0x00000A26u, /* pass.tr_level_out[15] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT0    = 0x00000A27u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT1    = 0x00000A28u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT2    = 0x00000A29u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT3    = 0x00000A2Au, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT4    = 0x00000A2Bu, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT5    = 0x00000A2Cu, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT6    = 0x00000A2Du, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT7    = 0x00000A2Eu, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT8    = 0x00000A2Fu, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT9    = 0x00000A30u, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT10   = 0x00000A31u, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT11   = 0x00000A32u, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT12   = 0x00000A33u, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT13   = 0x00000A34u, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT14   = 0x00000A35u, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT15   = 0x00000A36u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT0    = 0x00000A37u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT1    = 0x00000A38u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT2    = 0x00000A39u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT3    = 0x00000A3Au, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT4    = 0x00000A3Bu, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT5    = 0x00000A3Cu, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT6    = 0x00000A3Du, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT7    = 0x00000A3Eu, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT8    = 0x00000A3Fu, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT9    = 0x00000A40u, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT10   = 0x00000A41u, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT11   = 0x00000A42u, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT12   = 0x00000A43u, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT13   = 0x00000A44u, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT14   = 0x00000A45u, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_10_PDMA1_TR_OUT15   = 0x00000A46u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_10_TCPWM0_GRP0_OUT1_0 = 0x00000A47u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_10_TCPWM0_GRP0_OUT1_1 = 0x00000A48u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_10_TCPWM0_GRP0_OUT1_2 = 0x00000A49u, /* tcpwm[0].tr_out1[2] */
    TRIG_IN_MUX_10_TCPWM0_GRP0_OUT1_3 = 0x00000A4Au, /* tcpwm[0].tr_out1[3] */
    TRIG_IN_MUX_10_TCPWM0_GRP0_OUT1_4 = 0x00000A4Bu, /* tcpwm[0].tr_out1[4] */
    TRIG_IN_MUX_10_TCPWM0_GRP0_OUT1_5 = 0x00000A4Cu, /* tcpwm[0].tr_out1[5] */
    TRIG_IN_MUX_10_TCPWM0_GRP0_OUT1_6 = 0x00000A4Du, /* tcpwm[0].tr_out1[6] */
    TRIG_IN_MUX_10_TCPWM0_GRP0_OUT1_7 = 0x00000A4Eu, /* tcpwm[0].tr_out1[7] */
    TRIG_IN_MUX_10_TCPWM0_GRP1_OUT1_0 = 0x00000A4Fu, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_10_TCPWM0_GRP1_OUT1_1 = 0x00000A50u, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_10_TCPWM0_GRP1_OUT1_2 = 0x00000A51u, /* tcpwm[0].tr_out1[258] */
    TRIG_IN_MUX_10_TCPWM0_GRP1_OUT1_3 = 0x00000A52u, /* tcpwm[0].tr_out1[259] */
    TRIG_IN_MUX_10_TCPWM0_GRP1_OUT1_4 = 0x00000A53u, /* tcpwm[0].tr_out1[260] */
    TRIG_IN_MUX_10_TCPWM0_GRP1_OUT1_5 = 0x00000A54u, /* tcpwm[0].tr_out1[261] */
    TRIG_IN_MUX_10_TCPWM0_GRP1_OUT1_6 = 0x00000A55u, /* tcpwm[0].tr_out1[262] */
    TRIG_IN_MUX_10_TCPWM0_GRP1_OUT1_7 = 0x00000A56u, /* tcpwm[0].tr_out1[263] */
    TRIG_IN_MUX_10_TCPWM0_GRP2_OUT1_0 = 0x00000A57u, /* tcpwm[0].tr_out1[512] */
    TRIG_IN_MUX_10_TCPWM0_GRP2_OUT1_1 = 0x00000A58u, /* tcpwm[0].tr_out1[513] */
    TRIG_IN_MUX_10_TCPWM0_GRP2_OUT1_2 = 0x00000A59u, /* tcpwm[0].tr_out1[514] */
    TRIG_IN_MUX_10_TCPWM0_GRP2_OUT1_3 = 0x00000A5Au, /* tcpwm[0].tr_out1[515] */
    TRIG_IN_MUX_10_TCPWM0_GRP2_OUT1_4 = 0x00000A5Bu, /* tcpwm[0].tr_out1[516] */
    TRIG_IN_MUX_10_TCPWM0_GRP2_OUT1_5 = 0x00000A5Cu, /* tcpwm[0].tr_out1[517] */
    TRIG_IN_MUX_10_TCPWM0_GRP2_OUT1_6 = 0x00000A5Du, /* tcpwm[0].tr_out1[518] */
    TRIG_IN_MUX_10_TCPWM0_GRP2_OUT1_7 = 0x00000A5Eu, /* tcpwm[0].tr_out1[519] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP1_TR_OUT0 = 0x00000A5Fu, /* tcpwm[0].tr_motif_out[256] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP1_TR_OUT1 = 0x00000A60u, /* tcpwm[0].tr_motif_out[257] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP1_TR_OUT2 = 0x00000A61u, /* tcpwm[0].tr_motif_out[258] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP1_TR_OUT3 = 0x00000A62u, /* tcpwm[0].tr_motif_out[259] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP1_TR_OUT4 = 0x00000A63u, /* tcpwm[0].tr_motif_out[260] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP1_TR_OUT5 = 0x00000A64u, /* tcpwm[0].tr_motif_out[261] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP1_TR_OUT6 = 0x00000A65u, /* tcpwm[0].tr_motif_out[262] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP1_TR_OUT7 = 0x00000A66u, /* tcpwm[0].tr_motif_out[263] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP2_TR_OUT0 = 0x00000A67u, /* tcpwm[0].tr_motif_out[512] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP2_TR_OUT1 = 0x00000A68u, /* tcpwm[0].tr_motif_out[513] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP2_TR_OUT2 = 0x00000A69u, /* tcpwm[0].tr_motif_out[514] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP2_TR_OUT3 = 0x00000A6Au, /* tcpwm[0].tr_motif_out[515] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP2_TR_OUT4 = 0x00000A6Bu, /* tcpwm[0].tr_motif_out[516] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP2_TR_OUT5 = 0x00000A6Cu, /* tcpwm[0].tr_motif_out[517] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP2_TR_OUT6 = 0x00000A6Du, /* tcpwm[0].tr_motif_out[518] */
    TRIG_IN_MUX_10_TCPWM0_MOTIF_GRP2_TR_OUT7 = 0x00000A6Eu, /* tcpwm[0].tr_motif_out[519] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT0    = 0x00000A6Fu, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT1    = 0x00000A70u, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT2    = 0x00000A71u, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT3    = 0x00000A72u, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT4    = 0x00000A73u, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT5    = 0x00000A74u, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT6    = 0x00000A75u, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT7    = 0x00000A76u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT8    = 0x00000A77u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT9    = 0x00000A78u, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT10   = 0x00000A79u, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT11   = 0x00000A7Au, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT12   = 0x00000A7Bu, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT13   = 0x00000A7Cu, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT14   = 0x00000A7Du, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT15   = 0x00000A7Eu, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT16   = 0x00000A7Fu, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT17   = 0x00000A80u, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT18   = 0x00000A81u, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT19   = 0x00000A82u, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT20   = 0x00000A83u, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT21   = 0x00000A84u, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT22   = 0x00000A85u, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT23   = 0x00000A86u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT24   = 0x00000A87u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT25   = 0x00000A88u, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT26   = 0x00000A89u, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT27   = 0x00000A8Au, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT28   = 0x00000A8Bu, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT29   = 0x00000A8Cu, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT30   = 0x00000A8Du, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT31   = 0x00000A8Eu, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT32   = 0x00000A8Fu, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT33   = 0x00000A90u, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT34   = 0x00000A91u, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT35   = 0x00000A92u, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT36   = 0x00000A93u, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT37   = 0x00000A94u, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT38   = 0x00000A95u, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT39   = 0x00000A96u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT40   = 0x00000A97u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT41   = 0x00000A98u, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT42   = 0x00000A99u, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT43   = 0x00000A9Au, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT44   = 0x00000A9Bu, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT45   = 0x00000A9Cu, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT46   = 0x00000A9Du, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT47   = 0x00000A9Eu, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT48   = 0x00000A9Fu, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT49   = 0x00000AA0u, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT50   = 0x00000AA1u, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT51   = 0x00000AA2u, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT52   = 0x00000AA3u, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT53   = 0x00000AA4u, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT54   = 0x00000AA5u, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT55   = 0x00000AA6u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT56   = 0x00000AA7u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT57   = 0x00000AA8u, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT58   = 0x00000AA9u, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT59   = 0x00000AAAu, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT60   = 0x00000AABu, /* ioss.peri_tr_io_input_in[60] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT61   = 0x00000AACu, /* ioss.peri_tr_io_input_in[61] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT62   = 0x00000AADu, /* ioss.peri_tr_io_input_in[62] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT63   = 0x00000AAEu, /* ioss.peri_tr_io_input_in[63] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT64   = 0x00000AAFu, /* ioss.peri_tr_io_input_in[64] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT65   = 0x00000AB0u, /* ioss.peri_tr_io_input_in[65] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT66   = 0x00000AB1u, /* ioss.peri_tr_io_input_in[66] */
    TRIG_IN_MUX_10_HSIOM_TR_OUT67   = 0x00000AB2u, /* ioss.peri_tr_io_input_in[67] */
    TRIG_IN_MUX_10_SCB_I2C_SCL0     = 0x00000AB3u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_TX0          = 0x00000AB4u, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_10_SCB_RX0          = 0x00000AB5u, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_10_SCB_TGS_RELOAD00 = 0x00000AB6u, /* scb[0].tr_tgs_reload[0] */
    TRIG_IN_MUX_10_SCB_TGS_STOP00   = 0x00000AB7u, /* scb[0].tr_tgs_stop[0] */
    TRIG_IN_MUX_10_SCB_TGS_GATED00  = 0x00000AB8u, /* scb[0].tr_tgs_gated[0] */
    TRIG_IN_MUX_10_SCB_I2C_SCL1     = 0x00000AB9u, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_TX1          = 0x00000ABAu, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_10_SCB_RX1          = 0x00000ABBu, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_10_SCB_I2C_SCL2     = 0x00000ABCu, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_TX2          = 0x00000ABDu, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_10_SCB_RX2          = 0x00000ABEu, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_10_SCB_I2C_SCL3     = 0x00000ABFu, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_TX3          = 0x00000AC0u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_10_SCB_RX3          = 0x00000AC1u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_10_SCB_I2C_SCL4     = 0x00000AC2u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_TX4          = 0x00000AC3u, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_10_SCB_RX4          = 0x00000AC4u, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_10_SCB_I2C_SCL5     = 0x00000AC5u, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_TX5          = 0x00000AC6u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_10_SCB_RX5          = 0x00000AC7u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_10_SCB_TGS_RELOAD50 = 0x00000AC8u, /* scb[5].tr_tgs_reload[0] */
    TRIG_IN_MUX_10_SCB_TGS_STOP50   = 0x00000AC9u, /* scb[5].tr_tgs_stop[0] */
    TRIG_IN_MUX_10_SCB_TGS_GATED50  = 0x00000ACAu, /* scb[5].tr_tgs_gated[0] */
    TRIG_IN_MUX_10_CANFD_TT_TR_OUT0 = 0x00000ACBu, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_10_CANFD_TT_TR_OUT1 = 0x00000ACCu, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_10_CPUSS_TR_FAULT0  = 0x00000ACDu, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_10_I3C_TX0          = 0x00000ACEu, /* i3c[0].tr_tx_req */
    TRIG_IN_MUX_10_I3C_RX0          = 0x00000ACFu /* i3c[0].tr_rx_req */
} en_trig_input_tcpwm0_t;

/* Trigger Input Group 11 - TCPWM1 trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_11_TCPWM0_GRP0_OUT0_0 = 0x00000B01u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_11_TCPWM0_GRP0_OUT0_1 = 0x00000B02u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_11_TCPWM0_GRP0_OUT0_2 = 0x00000B03u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_11_TCPWM0_GRP0_OUT0_3 = 0x00000B04u, /* tcpwm[0].tr_out0[3] */
    TRIG_IN_MUX_11_TCPWM0_GRP0_OUT0_4 = 0x00000B05u, /* tcpwm[0].tr_out0[4] */
    TRIG_IN_MUX_11_TCPWM0_GRP0_OUT0_5 = 0x00000B06u, /* tcpwm[0].tr_out0[5] */
    TRIG_IN_MUX_11_TCPWM0_GRP0_OUT0_6 = 0x00000B07u, /* tcpwm[0].tr_out0[6] */
    TRIG_IN_MUX_11_TCPWM0_GRP0_OUT0_7 = 0x00000B08u, /* tcpwm[0].tr_out0[7] */
    TRIG_IN_MUX_11_TCPWM0_GRP1_OUT0_0 = 0x00000B09u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_11_TCPWM0_GRP1_OUT0_1 = 0x00000B0Au, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_11_TCPWM0_GRP1_OUT0_2 = 0x00000B0Bu, /* tcpwm[0].tr_out0[258] */
    TRIG_IN_MUX_11_TCPWM0_GRP1_OUT0_3 = 0x00000B0Cu, /* tcpwm[0].tr_out0[259] */
    TRIG_IN_MUX_11_TCPWM0_GRP1_OUT0_4 = 0x00000B0Du, /* tcpwm[0].tr_out0[260] */
    TRIG_IN_MUX_11_TCPWM0_GRP1_OUT0_5 = 0x00000B0Eu, /* tcpwm[0].tr_out0[261] */
    TRIG_IN_MUX_11_TCPWM0_GRP1_OUT0_6 = 0x00000B0Fu, /* tcpwm[0].tr_out0[262] */
    TRIG_IN_MUX_11_TCPWM0_GRP1_OUT0_7 = 0x00000B10u, /* tcpwm[0].tr_out0[263] */
    TRIG_IN_MUX_11_TCPWM0_GRP2_OUT0_0 = 0x00000B11u, /* tcpwm[0].tr_out0[512] */
    TRIG_IN_MUX_11_TCPWM0_GRP2_OUT0_1 = 0x00000B12u, /* tcpwm[0].tr_out0[513] */
    TRIG_IN_MUX_11_TCPWM0_GRP2_OUT0_2 = 0x00000B13u, /* tcpwm[0].tr_out0[514] */
    TRIG_IN_MUX_11_TCPWM0_GRP2_OUT0_3 = 0x00000B14u, /* tcpwm[0].tr_out0[515] */
    TRIG_IN_MUX_11_TCPWM0_GRP2_OUT0_4 = 0x00000B15u, /* tcpwm[0].tr_out0[516] */
    TRIG_IN_MUX_11_TCPWM0_GRP2_OUT0_5 = 0x00000B16u, /* tcpwm[0].tr_out0[517] */
    TRIG_IN_MUX_11_TCPWM0_GRP2_OUT0_6 = 0x00000B17u, /* tcpwm[0].tr_out0[518] */
    TRIG_IN_MUX_11_TCPWM0_GRP2_OUT0_7 = 0x00000B18u /* tcpwm[0].tr_out0[519] */
} en_trig_input_tcpwm1_t;

/* Trigger Input Group 12 - TCPWM MOTIF trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT0_0 = 0x00000C01u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT1_0 = 0x00000C02u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT0_1 = 0x00000C03u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT1_1 = 0x00000C04u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT0_2 = 0x00000C05u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT1_2 = 0x00000C06u, /* tcpwm[0].tr_out1[2] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT0_3 = 0x00000C07u, /* tcpwm[0].tr_out0[3] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT1_3 = 0x00000C08u, /* tcpwm[0].tr_out1[3] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT0_4 = 0x00000C09u, /* tcpwm[0].tr_out0[4] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT1_4 = 0x00000C0Au, /* tcpwm[0].tr_out1[4] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT0_5 = 0x00000C0Bu, /* tcpwm[0].tr_out0[5] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT1_5 = 0x00000C0Cu, /* tcpwm[0].tr_out1[5] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT0_6 = 0x00000C0Du, /* tcpwm[0].tr_out0[6] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT1_6 = 0x00000C0Eu, /* tcpwm[0].tr_out1[6] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT0_7 = 0x00000C0Fu, /* tcpwm[0].tr_out0[7] */
    TRIG_IN_MUX_12_TCPWM0_GRP0_OUT1_7 = 0x00000C10u, /* tcpwm[0].tr_out1[7] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_0 = 0x00000C11u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT1_0 = 0x00000C12u, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_1 = 0x00000C13u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT1_1 = 0x00000C14u, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_2 = 0x00000C15u, /* tcpwm[0].tr_out0[258] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT1_2 = 0x00000C16u, /* tcpwm[0].tr_out1[258] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_3 = 0x00000C17u, /* tcpwm[0].tr_out0[259] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT1_3 = 0x00000C18u, /* tcpwm[0].tr_out1[259] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_4 = 0x00000C19u, /* tcpwm[0].tr_out0[260] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT1_4 = 0x00000C1Au, /* tcpwm[0].tr_out1[260] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_5 = 0x00000C1Bu, /* tcpwm[0].tr_out0[261] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT1_5 = 0x00000C1Cu, /* tcpwm[0].tr_out1[261] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_6 = 0x00000C1Du, /* tcpwm[0].tr_out0[262] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT1_6 = 0x00000C1Eu, /* tcpwm[0].tr_out1[262] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT0_7 = 0x00000C1Fu, /* tcpwm[0].tr_out0[263] */
    TRIG_IN_MUX_12_TCPWM0_GRP1_OUT1_7 = 0x00000C20u, /* tcpwm[0].tr_out1[263] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT0_0 = 0x00000C21u, /* tcpwm[0].tr_out0[512] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT1_0 = 0x00000C22u, /* tcpwm[0].tr_out1[512] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT0_1 = 0x00000C23u, /* tcpwm[0].tr_out0[513] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT1_1 = 0x00000C24u, /* tcpwm[0].tr_out1[513] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT0_2 = 0x00000C25u, /* tcpwm[0].tr_out0[514] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT1_2 = 0x00000C26u, /* tcpwm[0].tr_out1[514] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT0_3 = 0x00000C27u, /* tcpwm[0].tr_out0[515] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT1_3 = 0x00000C28u, /* tcpwm[0].tr_out1[515] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT0_4 = 0x00000C29u, /* tcpwm[0].tr_out0[516] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT1_4 = 0x00000C2Au, /* tcpwm[0].tr_out1[516] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT0_5 = 0x00000C2Bu, /* tcpwm[0].tr_out0[517] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT1_5 = 0x00000C2Cu, /* tcpwm[0].tr_out1[517] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT0_6 = 0x00000C2Du, /* tcpwm[0].tr_out0[518] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT1_6 = 0x00000C2Eu, /* tcpwm[0].tr_out1[518] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT0_7 = 0x00000C2Fu, /* tcpwm[0].tr_out0[519] */
    TRIG_IN_MUX_12_TCPWM0_GRP2_OUT1_7 = 0x00000C30u, /* tcpwm[0].tr_out1[519] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT0    = 0x00000C31u, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT1    = 0x00000C32u, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT2    = 0x00000C33u, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT3    = 0x00000C34u, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT4    = 0x00000C35u, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT5    = 0x00000C36u, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT6    = 0x00000C37u, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT7    = 0x00000C38u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT8    = 0x00000C39u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT9    = 0x00000C3Au, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT10   = 0x00000C3Bu, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT11   = 0x00000C3Cu, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT12   = 0x00000C3Du, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT13   = 0x00000C3Eu, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT14   = 0x00000C3Fu, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT15   = 0x00000C40u, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT16   = 0x00000C41u, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT17   = 0x00000C42u, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT18   = 0x00000C43u, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT19   = 0x00000C44u, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT20   = 0x00000C45u, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT21   = 0x00000C46u, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT22   = 0x00000C47u, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT23   = 0x00000C48u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT24   = 0x00000C49u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT25   = 0x00000C4Au, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT26   = 0x00000C4Bu, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT27   = 0x00000C4Cu, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT28   = 0x00000C4Du, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT29   = 0x00000C4Eu, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT30   = 0x00000C4Fu, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT31   = 0x00000C50u, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT32   = 0x00000C51u, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT33   = 0x00000C52u, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT34   = 0x00000C53u, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT35   = 0x00000C54u, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT36   = 0x00000C55u, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT37   = 0x00000C56u, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT38   = 0x00000C57u, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT39   = 0x00000C58u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT40   = 0x00000C59u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT41   = 0x00000C5Au, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT42   = 0x00000C5Bu, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT43   = 0x00000C5Cu, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT44   = 0x00000C5Du, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT45   = 0x00000C5Eu, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT46   = 0x00000C5Fu, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT47   = 0x00000C60u, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT48   = 0x00000C61u, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT49   = 0x00000C62u, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT50   = 0x00000C63u, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT51   = 0x00000C64u, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT52   = 0x00000C65u, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT53   = 0x00000C66u, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT54   = 0x00000C67u, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT55   = 0x00000C68u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT56   = 0x00000C69u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT57   = 0x00000C6Au, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT58   = 0x00000C6Bu, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT59   = 0x00000C6Cu, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT60   = 0x00000C6Du, /* ioss.peri_tr_io_input_in[60] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT61   = 0x00000C6Eu, /* ioss.peri_tr_io_input_in[61] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT62   = 0x00000C6Fu, /* ioss.peri_tr_io_input_in[62] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT63   = 0x00000C70u, /* ioss.peri_tr_io_input_in[63] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT64   = 0x00000C71u, /* ioss.peri_tr_io_input_in[64] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT65   = 0x00000C72u, /* ioss.peri_tr_io_input_in[65] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT66   = 0x00000C73u, /* ioss.peri_tr_io_input_in[66] */
    TRIG_IN_MUX_12_HSIOM_TR_OUT67   = 0x00000C74u, /* ioss.peri_tr_io_input_in[67] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL0   = 0x00000C75u, /* pass.tr_level_out[0] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL1   = 0x00000C76u, /* pass.tr_level_out[1] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL2   = 0x00000C77u, /* pass.tr_level_out[2] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL3   = 0x00000C78u, /* pass.tr_level_out[3] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL4   = 0x00000C79u, /* pass.tr_level_out[4] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL5   = 0x00000C7Au, /* pass.tr_level_out[5] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL6   = 0x00000C7Bu, /* pass.tr_level_out[6] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL7   = 0x00000C7Cu, /* pass.tr_level_out[7] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL8   = 0x00000C7Du, /* pass.tr_level_out[8] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL9   = 0x00000C7Eu, /* pass.tr_level_out[9] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL10  = 0x00000C7Fu, /* pass.tr_level_out[10] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL11  = 0x00000C80u, /* pass.tr_level_out[11] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL12  = 0x00000C81u, /* pass.tr_level_out[12] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL13  = 0x00000C82u, /* pass.tr_level_out[13] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL14  = 0x00000C83u, /* pass.tr_level_out[14] */
    TRIG_IN_MUX_12_PASS_TR_LEVEL15  = 0x00000C84u /* pass.tr_level_out[15] */
} en_trig_input_tcpwm_motif_t;

/* Trigger Input Group 13 - MCPASS trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_13_TCPWM0_GRP0_OUT1_0 = 0x00000D01u, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_13_TCPWM0_GRP0_OUT1_1 = 0x00000D02u, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_13_TCPWM0_GRP0_OUT1_2 = 0x00000D03u, /* tcpwm[0].tr_out1[2] */
    TRIG_IN_MUX_13_TCPWM0_GRP0_OUT1_3 = 0x00000D04u, /* tcpwm[0].tr_out1[3] */
    TRIG_IN_MUX_13_TCPWM0_GRP0_OUT1_4 = 0x00000D05u, /* tcpwm[0].tr_out1[4] */
    TRIG_IN_MUX_13_TCPWM0_GRP0_OUT1_5 = 0x00000D06u, /* tcpwm[0].tr_out1[5] */
    TRIG_IN_MUX_13_TCPWM0_GRP0_OUT1_6 = 0x00000D07u, /* tcpwm[0].tr_out1[6] */
    TRIG_IN_MUX_13_TCPWM0_GRP0_OUT1_7 = 0x00000D08u, /* tcpwm[0].tr_out1[7] */
    TRIG_IN_MUX_13_TCPWM0_GRP1_OUT1_0 = 0x00000D09u, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_13_TCPWM0_GRP1_OUT1_1 = 0x00000D0Au, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_13_TCPWM0_GRP1_OUT1_2 = 0x00000D0Bu, /* tcpwm[0].tr_out1[258] */
    TRIG_IN_MUX_13_TCPWM0_GRP1_OUT1_3 = 0x00000D0Cu, /* tcpwm[0].tr_out1[259] */
    TRIG_IN_MUX_13_TCPWM0_GRP1_OUT1_4 = 0x00000D0Du, /* tcpwm[0].tr_out1[260] */
    TRIG_IN_MUX_13_TCPWM0_GRP1_OUT1_5 = 0x00000D0Eu, /* tcpwm[0].tr_out1[261] */
    TRIG_IN_MUX_13_TCPWM0_GRP1_OUT1_6 = 0x00000D0Fu, /* tcpwm[0].tr_out1[262] */
    TRIG_IN_MUX_13_TCPWM0_GRP1_OUT1_7 = 0x00000D10u, /* tcpwm[0].tr_out1[263] */
    TRIG_IN_MUX_13_TCPWM0_GRP2_OUT1_0 = 0x00000D11u, /* tcpwm[0].tr_out1[512] */
    TRIG_IN_MUX_13_TCPWM0_GRP2_OUT1_1 = 0x00000D12u, /* tcpwm[0].tr_out1[513] */
    TRIG_IN_MUX_13_TCPWM0_GRP2_OUT1_2 = 0x00000D13u, /* tcpwm[0].tr_out1[514] */
    TRIG_IN_MUX_13_TCPWM0_GRP2_OUT1_3 = 0x00000D14u, /* tcpwm[0].tr_out1[515] */
    TRIG_IN_MUX_13_TCPWM0_GRP2_OUT1_4 = 0x00000D15u, /* tcpwm[0].tr_out1[516] */
    TRIG_IN_MUX_13_TCPWM0_GRP2_OUT1_5 = 0x00000D16u, /* tcpwm[0].tr_out1[517] */
    TRIG_IN_MUX_13_TCPWM0_GRP2_OUT1_6 = 0x00000D17u, /* tcpwm[0].tr_out1[518] */
    TRIG_IN_MUX_13_TCPWM0_GRP2_OUT1_7 = 0x00000D18u, /* tcpwm[0].tr_out1[519] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP1_TR_OUT0 = 0x00000D19u, /* tcpwm[0].tr_motif_out[256] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP1_TR_OUT1 = 0x00000D1Au, /* tcpwm[0].tr_motif_out[257] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP1_TR_OUT2 = 0x00000D1Bu, /* tcpwm[0].tr_motif_out[258] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP1_TR_OUT3 = 0x00000D1Cu, /* tcpwm[0].tr_motif_out[259] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP1_TR_OUT4 = 0x00000D1Du, /* tcpwm[0].tr_motif_out[260] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP1_TR_OUT5 = 0x00000D1Eu, /* tcpwm[0].tr_motif_out[261] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP1_TR_OUT6 = 0x00000D1Fu, /* tcpwm[0].tr_motif_out[262] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP1_TR_OUT7 = 0x00000D20u, /* tcpwm[0].tr_motif_out[263] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP2_TR_OUT0 = 0x00000D21u, /* tcpwm[0].tr_motif_out[512] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP2_TR_OUT1 = 0x00000D22u, /* tcpwm[0].tr_motif_out[513] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP2_TR_OUT2 = 0x00000D23u, /* tcpwm[0].tr_motif_out[514] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP2_TR_OUT3 = 0x00000D24u, /* tcpwm[0].tr_motif_out[515] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP2_TR_OUT4 = 0x00000D25u, /* tcpwm[0].tr_motif_out[516] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP2_TR_OUT5 = 0x00000D26u, /* tcpwm[0].tr_motif_out[517] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP2_TR_OUT6 = 0x00000D27u, /* tcpwm[0].tr_motif_out[518] */
    TRIG_IN_MUX_13_TCPWM0_MOTIF_GRP2_TR_OUT7 = 0x00000D28u, /* tcpwm[0].tr_motif_out[519] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT0    = 0x00000D29u, /* ioss.peri_tr_io_input_in[0] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT1    = 0x00000D2Au, /* ioss.peri_tr_io_input_in[1] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT2    = 0x00000D2Bu, /* ioss.peri_tr_io_input_in[2] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT3    = 0x00000D2Cu, /* ioss.peri_tr_io_input_in[3] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT4    = 0x00000D2Du, /* ioss.peri_tr_io_input_in[4] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT5    = 0x00000D2Eu, /* ioss.peri_tr_io_input_in[5] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT6    = 0x00000D2Fu, /* ioss.peri_tr_io_input_in[6] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT7    = 0x00000D30u, /* ioss.peri_tr_io_input_in[7] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT8    = 0x00000D31u, /* ioss.peri_tr_io_input_in[8] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT9    = 0x00000D32u, /* ioss.peri_tr_io_input_in[9] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT10   = 0x00000D33u, /* ioss.peri_tr_io_input_in[10] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT11   = 0x00000D34u, /* ioss.peri_tr_io_input_in[11] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT12   = 0x00000D35u, /* ioss.peri_tr_io_input_in[12] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT13   = 0x00000D36u, /* ioss.peri_tr_io_input_in[13] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT14   = 0x00000D37u, /* ioss.peri_tr_io_input_in[14] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT15   = 0x00000D38u, /* ioss.peri_tr_io_input_in[15] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT16   = 0x00000D39u, /* ioss.peri_tr_io_input_in[16] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT17   = 0x00000D3Au, /* ioss.peri_tr_io_input_in[17] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT18   = 0x00000D3Bu, /* ioss.peri_tr_io_input_in[18] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT19   = 0x00000D3Cu, /* ioss.peri_tr_io_input_in[19] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT20   = 0x00000D3Du, /* ioss.peri_tr_io_input_in[20] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT21   = 0x00000D3Eu, /* ioss.peri_tr_io_input_in[21] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT22   = 0x00000D3Fu, /* ioss.peri_tr_io_input_in[22] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT23   = 0x00000D40u, /* ioss.peri_tr_io_input_in[23] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT24   = 0x00000D41u, /* ioss.peri_tr_io_input_in[24] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT25   = 0x00000D42u, /* ioss.peri_tr_io_input_in[25] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT26   = 0x00000D43u, /* ioss.peri_tr_io_input_in[26] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT27   = 0x00000D44u, /* ioss.peri_tr_io_input_in[27] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT28   = 0x00000D45u, /* ioss.peri_tr_io_input_in[28] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT29   = 0x00000D46u, /* ioss.peri_tr_io_input_in[29] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT30   = 0x00000D47u, /* ioss.peri_tr_io_input_in[30] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT31   = 0x00000D48u, /* ioss.peri_tr_io_input_in[31] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT32   = 0x00000D49u, /* ioss.peri_tr_io_input_in[32] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT33   = 0x00000D4Au, /* ioss.peri_tr_io_input_in[33] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT34   = 0x00000D4Bu, /* ioss.peri_tr_io_input_in[34] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT35   = 0x00000D4Cu, /* ioss.peri_tr_io_input_in[35] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT36   = 0x00000D4Du, /* ioss.peri_tr_io_input_in[36] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT37   = 0x00000D4Eu, /* ioss.peri_tr_io_input_in[37] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT38   = 0x00000D4Fu, /* ioss.peri_tr_io_input_in[38] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT39   = 0x00000D50u, /* ioss.peri_tr_io_input_in[39] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT40   = 0x00000D51u, /* ioss.peri_tr_io_input_in[40] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT41   = 0x00000D52u, /* ioss.peri_tr_io_input_in[41] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT42   = 0x00000D53u, /* ioss.peri_tr_io_input_in[42] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT43   = 0x00000D54u, /* ioss.peri_tr_io_input_in[43] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT44   = 0x00000D55u, /* ioss.peri_tr_io_input_in[44] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT45   = 0x00000D56u, /* ioss.peri_tr_io_input_in[45] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT46   = 0x00000D57u, /* ioss.peri_tr_io_input_in[46] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT47   = 0x00000D58u, /* ioss.peri_tr_io_input_in[47] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT48   = 0x00000D59u, /* ioss.peri_tr_io_input_in[48] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT49   = 0x00000D5Au, /* ioss.peri_tr_io_input_in[49] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT50   = 0x00000D5Bu, /* ioss.peri_tr_io_input_in[50] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT51   = 0x00000D5Cu, /* ioss.peri_tr_io_input_in[51] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT52   = 0x00000D5Du, /* ioss.peri_tr_io_input_in[52] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT53   = 0x00000D5Eu, /* ioss.peri_tr_io_input_in[53] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT54   = 0x00000D5Fu, /* ioss.peri_tr_io_input_in[54] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT55   = 0x00000D60u, /* ioss.peri_tr_io_input_in[55] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT56   = 0x00000D61u, /* ioss.peri_tr_io_input_in[56] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT57   = 0x00000D62u, /* ioss.peri_tr_io_input_in[57] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT58   = 0x00000D63u, /* ioss.peri_tr_io_input_in[58] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT59   = 0x00000D64u, /* ioss.peri_tr_io_input_in[59] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT60   = 0x00000D65u, /* ioss.peri_tr_io_input_in[60] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT61   = 0x00000D66u, /* ioss.peri_tr_io_input_in[61] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT62   = 0x00000D67u, /* ioss.peri_tr_io_input_in[62] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT63   = 0x00000D68u, /* ioss.peri_tr_io_input_in[63] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT64   = 0x00000D69u, /* ioss.peri_tr_io_input_in[64] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT65   = 0x00000D6Au, /* ioss.peri_tr_io_input_in[65] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT66   = 0x00000D6Bu, /* ioss.peri_tr_io_input_in[66] */
    TRIG_IN_MUX_13_HSIOM_TR_OUT67   = 0x00000D6Cu /* ioss.peri_tr_io_input_in[67] */
} en_trig_input_mcpass_t;

/* Trigger Input Group 14 - USBFS trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_14_PDMA0_TR_OUT0    = 0x00000E01u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT1    = 0x00000E02u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT2    = 0x00000E03u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT3    = 0x00000E04u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT4    = 0x00000E05u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT5    = 0x00000E06u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT6    = 0x00000E07u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT7    = 0x00000E08u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT8    = 0x00000E09u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT9    = 0x00000E0Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT10   = 0x00000E0Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT11   = 0x00000E0Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT12   = 0x00000E0Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT13   = 0x00000E0Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT14   = 0x00000E0Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_14_PDMA0_TR_OUT15   = 0x00000E10u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT0    = 0x00000E11u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT1    = 0x00000E12u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT2    = 0x00000E13u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT3    = 0x00000E14u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT4    = 0x00000E15u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT5    = 0x00000E16u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT6    = 0x00000E17u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT7    = 0x00000E18u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT8    = 0x00000E19u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT9    = 0x00000E1Au, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT10   = 0x00000E1Bu, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT11   = 0x00000E1Cu, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT12   = 0x00000E1Du, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT13   = 0x00000E1Eu, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT14   = 0x00000E1Fu, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_14_PDMA1_TR_OUT15   = 0x00000E20u /* cpuss.dw1_tr_out[15] */
} en_trig_input_usbfs_t;

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

/* Trigger Output Group 1 - P-DMA1 Request Assignments */
typedef enum
{
    TRIG_OUT_MUX_1_PDMA1_TR_IN0     = 0x40000100u, /* cpuss.dw1_tr_in[0] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN1     = 0x40000101u, /* cpuss.dw1_tr_in[1] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN2     = 0x40000102u, /* cpuss.dw1_tr_in[2] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN3     = 0x40000103u, /* cpuss.dw1_tr_in[3] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN4     = 0x40000104u, /* cpuss.dw1_tr_in[4] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN5     = 0x40000105u, /* cpuss.dw1_tr_in[5] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN6     = 0x40000106u, /* cpuss.dw1_tr_in[6] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN7     = 0x40000107u, /* cpuss.dw1_tr_in[7] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN8     = 0x40000108u, /* cpuss.dw1_tr_in[8] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN9     = 0x40000109u, /* cpuss.dw1_tr_in[9] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN10    = 0x4000010Au, /* cpuss.dw1_tr_in[10] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN11    = 0x4000010Bu, /* cpuss.dw1_tr_in[11] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN12    = 0x4000010Cu, /* cpuss.dw1_tr_in[12] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN13    = 0x4000010Du, /* cpuss.dw1_tr_in[13] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN14    = 0x4000010Eu, /* cpuss.dw1_tr_in[14] */
    TRIG_OUT_MUX_1_PDMA1_TR_IN15    = 0x4000010Fu /* cpuss.dw1_tr_in[15] */
} en_trig_output_pdma1_tr_t;

/* Trigger Output Group 2 - HSIOM0 trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT0 = 0x40000200u, /* ioss.peri_tr_io_output_out[0] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT1 = 0x40000201u, /* ioss.peri_tr_io_output_out[1] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT2 = 0x40000202u, /* ioss.peri_tr_io_output_out[2] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT3 = 0x40000203u, /* ioss.peri_tr_io_output_out[3] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT4 = 0x40000204u, /* ioss.peri_tr_io_output_out[4] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT5 = 0x40000205u, /* ioss.peri_tr_io_output_out[5] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT6 = 0x40000206u, /* ioss.peri_tr_io_output_out[6] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT7 = 0x40000207u, /* ioss.peri_tr_io_output_out[7] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT8 = 0x40000208u, /* ioss.peri_tr_io_output_out[8] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT9 = 0x40000209u, /* ioss.peri_tr_io_output_out[9] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT10 = 0x4000020Au, /* ioss.peri_tr_io_output_out[10] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT11 = 0x4000020Bu, /* ioss.peri_tr_io_output_out[11] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT12 = 0x4000020Cu, /* ioss.peri_tr_io_output_out[12] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT13 = 0x4000020Du, /* ioss.peri_tr_io_output_out[13] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT14 = 0x4000020Eu, /* ioss.peri_tr_io_output_out[14] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT15 = 0x4000020Fu, /* ioss.peri_tr_io_output_out[15] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT16 = 0x40000210u, /* ioss.peri_tr_io_output_out[16] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT17 = 0x40000211u, /* ioss.peri_tr_io_output_out[17] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT18 = 0x40000212u, /* ioss.peri_tr_io_output_out[18] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT19 = 0x40000213u, /* ioss.peri_tr_io_output_out[19] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT20 = 0x40000214u, /* ioss.peri_tr_io_output_out[20] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT21 = 0x40000215u, /* ioss.peri_tr_io_output_out[21] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT22 = 0x40000216u, /* ioss.peri_tr_io_output_out[22] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT23 = 0x40000217u, /* ioss.peri_tr_io_output_out[23] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT24 = 0x40000218u, /* ioss.peri_tr_io_output_out[24] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT25 = 0x40000219u, /* ioss.peri_tr_io_output_out[25] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT26 = 0x4000021Au, /* ioss.peri_tr_io_output_out[26] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT27 = 0x4000021Bu, /* ioss.peri_tr_io_output_out[27] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT28 = 0x4000021Cu, /* ioss.peri_tr_io_output_out[28] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT29 = 0x4000021Du, /* ioss.peri_tr_io_output_out[29] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT30 = 0x4000021Eu, /* ioss.peri_tr_io_output_out[30] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT31 = 0x4000021Fu, /* ioss.peri_tr_io_output_out[31] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT32 = 0x40000220u, /* ioss.peri_tr_io_output_out[32] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT33 = 0x40000221u, /* ioss.peri_tr_io_output_out[33] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT34 = 0x40000222u, /* ioss.peri_tr_io_output_out[34] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT35 = 0x40000223u, /* ioss.peri_tr_io_output_out[35] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT36 = 0x40000224u, /* ioss.peri_tr_io_output_out[36] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT37 = 0x40000225u, /* ioss.peri_tr_io_output_out[37] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT38 = 0x40000226u, /* ioss.peri_tr_io_output_out[38] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT39 = 0x40000227u, /* ioss.peri_tr_io_output_out[39] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT40 = 0x40000228u, /* ioss.peri_tr_io_output_out[40] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT41 = 0x40000229u, /* ioss.peri_tr_io_output_out[41] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT42 = 0x4000022Au, /* ioss.peri_tr_io_output_out[42] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT43 = 0x4000022Bu, /* ioss.peri_tr_io_output_out[43] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT44 = 0x4000022Cu, /* ioss.peri_tr_io_output_out[44] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT45 = 0x4000022Du, /* ioss.peri_tr_io_output_out[45] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT46 = 0x4000022Eu, /* ioss.peri_tr_io_output_out[46] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT47 = 0x4000022Fu, /* ioss.peri_tr_io_output_out[47] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT48 = 0x40000230u, /* ioss.peri_tr_io_output_out[48] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT49 = 0x40000231u, /* ioss.peri_tr_io_output_out[49] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT50 = 0x40000232u, /* ioss.peri_tr_io_output_out[50] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT51 = 0x40000233u, /* ioss.peri_tr_io_output_out[51] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT52 = 0x40000234u, /* ioss.peri_tr_io_output_out[52] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT53 = 0x40000235u, /* ioss.peri_tr_io_output_out[53] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT54 = 0x40000236u, /* ioss.peri_tr_io_output_out[54] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT55 = 0x40000237u, /* ioss.peri_tr_io_output_out[55] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT56 = 0x40000238u, /* ioss.peri_tr_io_output_out[56] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT57 = 0x40000239u, /* ioss.peri_tr_io_output_out[57] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT58 = 0x4000023Au, /* ioss.peri_tr_io_output_out[58] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT59 = 0x4000023Bu, /* ioss.peri_tr_io_output_out[59] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT60 = 0x4000023Cu, /* ioss.peri_tr_io_output_out[60] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT61 = 0x4000023Du, /* ioss.peri_tr_io_output_out[61] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT62 = 0x4000023Eu, /* ioss.peri_tr_io_output_out[62] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT63 = 0x4000023Fu, /* ioss.peri_tr_io_output_out[63] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT64 = 0x40000240u, /* ioss.peri_tr_io_output_out[64] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT65 = 0x40000241u, /* ioss.peri_tr_io_output_out[65] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT66 = 0x40000242u, /* ioss.peri_tr_io_output_out[66] */
    TRIG_OUT_MUX_2_HSIOM_TR_IO_OUTPUT67 = 0x40000243u /* ioss.peri_tr_io_output_out[67] */
} en_trig_output_hsiom0_t;

/* Trigger Output Group 3 - HSIOMLOOP tigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT68 = 0x40000300u, /* ioss.peri_tr_io_output_out[68] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT69 = 0x40000301u, /* ioss.peri_tr_io_output_out[69] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT70 = 0x40000302u, /* ioss.peri_tr_io_output_out[70] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT71 = 0x40000303u, /* ioss.peri_tr_io_output_out[71] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT72 = 0x40000304u, /* ioss.peri_tr_io_output_out[72] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT73 = 0x40000305u, /* ioss.peri_tr_io_output_out[73] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT74 = 0x40000306u, /* ioss.peri_tr_io_output_out[74] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT75 = 0x40000307u, /* ioss.peri_tr_io_output_out[75] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT76 = 0x40000308u, /* ioss.peri_tr_io_output_out[76] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT77 = 0x40000309u, /* ioss.peri_tr_io_output_out[77] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT78 = 0x4000030Au, /* ioss.peri_tr_io_output_out[78] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT79 = 0x4000030Bu, /* ioss.peri_tr_io_output_out[79] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT80 = 0x4000030Cu, /* ioss.peri_tr_io_output_out[80] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT81 = 0x4000030Du, /* ioss.peri_tr_io_output_out[81] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT82 = 0x4000030Eu, /* ioss.peri_tr_io_output_out[82] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT83 = 0x4000030Fu, /* ioss.peri_tr_io_output_out[83] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT84 = 0x40000310u, /* ioss.peri_tr_io_output_out[84] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT85 = 0x40000311u, /* ioss.peri_tr_io_output_out[85] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT86 = 0x40000312u, /* ioss.peri_tr_io_output_out[86] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT87 = 0x40000313u, /* ioss.peri_tr_io_output_out[87] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT88 = 0x40000314u, /* ioss.peri_tr_io_output_out[88] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT89 = 0x40000315u, /* ioss.peri_tr_io_output_out[89] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT90 = 0x40000316u, /* ioss.peri_tr_io_output_out[90] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT91 = 0x40000317u, /* ioss.peri_tr_io_output_out[91] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT92 = 0x40000318u, /* ioss.peri_tr_io_output_out[92] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT93 = 0x40000319u, /* ioss.peri_tr_io_output_out[93] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT94 = 0x4000031Au, /* ioss.peri_tr_io_output_out[94] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT95 = 0x4000031Bu, /* ioss.peri_tr_io_output_out[95] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT96 = 0x4000031Cu, /* ioss.peri_tr_io_output_out[96] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT97 = 0x4000031Du, /* ioss.peri_tr_io_output_out[97] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT98 = 0x4000031Eu, /* ioss.peri_tr_io_output_out[98] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT99 = 0x4000031Fu, /* ioss.peri_tr_io_output_out[99] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT100 = 0x40000320u, /* ioss.peri_tr_io_output_out[100] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT101 = 0x40000321u, /* ioss.peri_tr_io_output_out[101] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT102 = 0x40000322u, /* ioss.peri_tr_io_output_out[102] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT103 = 0x40000323u, /* ioss.peri_tr_io_output_out[103] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT104 = 0x40000324u, /* ioss.peri_tr_io_output_out[104] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT105 = 0x40000325u, /* ioss.peri_tr_io_output_out[105] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT106 = 0x40000326u, /* ioss.peri_tr_io_output_out[106] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT107 = 0x40000327u, /* ioss.peri_tr_io_output_out[107] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT108 = 0x40000328u, /* ioss.peri_tr_io_output_out[108] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT109 = 0x40000329u, /* ioss.peri_tr_io_output_out[109] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT110 = 0x4000032Au, /* ioss.peri_tr_io_output_out[110] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT111 = 0x4000032Bu, /* ioss.peri_tr_io_output_out[111] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT112 = 0x4000032Cu, /* ioss.peri_tr_io_output_out[112] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT113 = 0x4000032Du, /* ioss.peri_tr_io_output_out[113] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT114 = 0x4000032Eu, /* ioss.peri_tr_io_output_out[114] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT115 = 0x4000032Fu, /* ioss.peri_tr_io_output_out[115] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT116 = 0x40000330u, /* ioss.peri_tr_io_output_out[116] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT117 = 0x40000331u, /* ioss.peri_tr_io_output_out[117] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT118 = 0x40000332u, /* ioss.peri_tr_io_output_out[118] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT119 = 0x40000333u, /* ioss.peri_tr_io_output_out[119] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT120 = 0x40000334u, /* ioss.peri_tr_io_output_out[120] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT121 = 0x40000335u, /* ioss.peri_tr_io_output_out[121] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT122 = 0x40000336u, /* ioss.peri_tr_io_output_out[122] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT123 = 0x40000337u, /* ioss.peri_tr_io_output_out[123] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT124 = 0x40000338u, /* ioss.peri_tr_io_output_out[124] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT125 = 0x40000339u, /* ioss.peri_tr_io_output_out[125] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT126 = 0x4000033Au, /* ioss.peri_tr_io_output_out[126] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT127 = 0x4000033Bu, /* ioss.peri_tr_io_output_out[127] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT128 = 0x4000033Cu, /* ioss.peri_tr_io_output_out[128] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT129 = 0x4000033Du, /* ioss.peri_tr_io_output_out[129] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT130 = 0x4000033Eu, /* ioss.peri_tr_io_output_out[130] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT131 = 0x4000033Fu, /* ioss.peri_tr_io_output_out[131] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT132 = 0x40000340u, /* ioss.peri_tr_io_output_out[132] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT133 = 0x40000341u, /* ioss.peri_tr_io_output_out[133] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT134 = 0x40000342u, /* ioss.peri_tr_io_output_out[134] */
    TRIG_OUT_MUX_3_HSIOM_TR_IO_OUTPUT135 = 0x40000343u /* ioss.peri_tr_io_output_out[135] */
} en_trig_output_hsiomloop_t;

/* Trigger Output Group 4 - HSIOM1 trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_4_HSIOM_TR_IO_OUTPUT136 = 0x40000400u, /* ioss.peri_tr_io_output_out[136] */
    TRIG_OUT_MUX_4_HSIOM_TR_IO_OUTPUT137 = 0x40000401u, /* ioss.peri_tr_io_output_out[137] */
    TRIG_OUT_MUX_4_HSIOM_TR_IO_OUTPUT138 = 0x40000402u, /* ioss.peri_tr_io_output_out[138] */
    TRIG_OUT_MUX_4_HSIOM_TR_IO_OUTPUT139 = 0x40000403u, /* ioss.peri_tr_io_output_out[139] */
    TRIG_OUT_MUX_4_HSIOM_TR_IO_OUTPUT140 = 0x40000404u, /* ioss.peri_tr_io_output_out[140] */
    TRIG_OUT_MUX_4_HSIOM_TR_IO_OUTPUT141 = 0x40000405u, /* ioss.peri_tr_io_output_out[141] */
    TRIG_OUT_MUX_4_HSIOM_TR_IO_OUTPUT142 = 0x40000406u, /* ioss.peri_tr_io_output_out[142] */
    TRIG_OUT_MUX_4_HSIOM_TR_IO_OUTPUT143 = 0x40000407u /* ioss.peri_tr_io_output_out[143] */
} en_trig_output_hsiom1_t;

/* Trigger Output Group 5 - HSIOM2 trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_5_HSIOM_TR_IO_OUTPUT144 = 0x40000500u, /* ioss.peri_tr_io_output_out[144] */
    TRIG_OUT_MUX_5_HSIOM_TR_IO_OUTPUT145 = 0x40000501u, /* ioss.peri_tr_io_output_out[145] */
    TRIG_OUT_MUX_5_HSIOM_TR_IO_OUTPUT146 = 0x40000502u, /* ioss.peri_tr_io_output_out[146] */
    TRIG_OUT_MUX_5_HSIOM_TR_IO_OUTPUT147 = 0x40000503u, /* ioss.peri_tr_io_output_out[147] */
    TRIG_OUT_MUX_5_HSIOM_TR_IO_OUTPUT148 = 0x40000504u, /* ioss.peri_tr_io_output_out[148] */
    TRIG_OUT_MUX_5_HSIOM_TR_IO_OUTPUT149 = 0x40000505u, /* ioss.peri_tr_io_output_out[149] */
    TRIG_OUT_MUX_5_HSIOM_TR_IO_OUTPUT150 = 0x40000506u, /* ioss.peri_tr_io_output_out[150] */
    TRIG_OUT_MUX_5_HSIOM_TR_IO_OUTPUT151 = 0x40000507u /* ioss.peri_tr_io_output_out[151] */
} en_trig_output_hsiom2_t;

/* Trigger Output Group 6 - HSIOM3 trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_6_HSIOM_TR_IO_OUTPUT152 = 0x40000600u, /* ioss.peri_tr_io_output_out[152] */
    TRIG_OUT_MUX_6_HSIOM_TR_IO_OUTPUT153 = 0x40000601u, /* ioss.peri_tr_io_output_out[153] */
    TRIG_OUT_MUX_6_HSIOM_TR_IO_OUTPUT154 = 0x40000602u, /* ioss.peri_tr_io_output_out[154] */
    TRIG_OUT_MUX_6_HSIOM_TR_IO_OUTPUT155 = 0x40000603u, /* ioss.peri_tr_io_output_out[155] */
    TRIG_OUT_MUX_6_HSIOM_TR_IO_OUTPUT156 = 0x40000604u, /* ioss.peri_tr_io_output_out[156] */
    TRIG_OUT_MUX_6_HSIOM_TR_IO_OUTPUT157 = 0x40000605u, /* ioss.peri_tr_io_output_out[157] */
    TRIG_OUT_MUX_6_HSIOM_TR_IO_OUTPUT158 = 0x40000606u, /* ioss.peri_tr_io_output_out[158] */
    TRIG_OUT_MUX_6_HSIOM_TR_IO_OUTPUT159 = 0x40000607u /* ioss.peri_tr_io_output_out[159] */
} en_trig_output_hsiom3_t;

/* Trigger Output Group 7 - CPUSS Debug  multiplexer */
typedef enum
{
    TRIG_OUT_MUX_7_CPUSS_CTI_TR_IN0 = 0x40000700u, /* debug600.cti_tr_in[0] */
    TRIG_OUT_MUX_7_CPUSS_CTI_TR_IN1 = 0x40000701u /* debug600.cti_tr_in[1] */
} en_trig_output_cpuss_cti_t;

/* Trigger Output Group 8 - CAN TT Synchronization triggers */
typedef enum
{
    TRIG_OUT_MUX_8_CAN_TT_TR_IN0    = 0x40000800u, /* canfd[0].tr_evt_swt_in[0] */
    TRIG_OUT_MUX_8_CAN_TT_TR_IN1    = 0x40000801u /* canfd[0].tr_evt_swt_in[1] */
} en_trig_output_cantt_t;

/* Trigger Output Group 9 - PERI Freeze trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_9_PERI_DEBUG_FREEZE_TR_IN = 0x40000900u, /* peri.tr_dbg_freeze */
    TRIG_OUT_MUX_9_TCPWM_DEBUG_FREEZE_TR_IN = 0x40000901u /* tcpwm[0].tr_debug_freeze */
} en_trig_output_peri_freeze_t;

/* Trigger Output Group 10 - TCPWM0 trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_10_TCPWM0_TR_IN0   = 0x40000A00u, /* tcpwm[0].tr_all_cnt_in[0] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN1   = 0x40000A01u, /* tcpwm[0].tr_all_cnt_in[1] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN2   = 0x40000A02u, /* tcpwm[0].tr_all_cnt_in[2] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN3   = 0x40000A03u, /* tcpwm[0].tr_all_cnt_in[3] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN4   = 0x40000A04u, /* tcpwm[0].tr_all_cnt_in[4] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN5   = 0x40000A05u, /* tcpwm[0].tr_all_cnt_in[5] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN6   = 0x40000A06u, /* tcpwm[0].tr_all_cnt_in[6] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN7   = 0x40000A07u, /* tcpwm[0].tr_all_cnt_in[7] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN8   = 0x40000A08u, /* tcpwm[0].tr_all_cnt_in[8] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN9   = 0x40000A09u, /* tcpwm[0].tr_all_cnt_in[9] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN10  = 0x40000A0Au, /* tcpwm[0].tr_all_cnt_in[10] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN11  = 0x40000A0Bu, /* tcpwm[0].tr_all_cnt_in[11] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN12  = 0x40000A0Cu, /* tcpwm[0].tr_all_cnt_in[12] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN13  = 0x40000A0Du, /* tcpwm[0].tr_all_cnt_in[13] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN14  = 0x40000A0Eu, /* tcpwm[0].tr_all_cnt_in[14] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN15  = 0x40000A0Fu, /* tcpwm[0].tr_all_cnt_in[15] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN16  = 0x40000A10u, /* tcpwm[0].tr_all_cnt_in[16] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN17  = 0x40000A11u, /* tcpwm[0].tr_all_cnt_in[17] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN18  = 0x40000A12u, /* tcpwm[0].tr_all_cnt_in[18] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN19  = 0x40000A13u, /* tcpwm[0].tr_all_cnt_in[19] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN20  = 0x40000A14u, /* tcpwm[0].tr_all_cnt_in[20] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN21  = 0x40000A15u, /* tcpwm[0].tr_all_cnt_in[21] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN22  = 0x40000A16u, /* tcpwm[0].tr_all_cnt_in[22] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN23  = 0x40000A17u, /* tcpwm[0].tr_all_cnt_in[23] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN24  = 0x40000A18u, /* tcpwm[0].tr_all_cnt_in[24] */
    TRIG_OUT_MUX_10_TCPWM0_TR_IN25  = 0x40000A19u, /* tcpwm[0].tr_all_cnt_in[25] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT0_TR2_IN = 0x40000A1Au, /* tcpwm[0].tr_one_cnt_in[0] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT1_TR2_IN = 0x40000A1Bu, /* tcpwm[0].tr_one_cnt_in[3] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT2_TR2_IN = 0x40000A1Cu, /* tcpwm[0].tr_one_cnt_in[6] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT3_TR2_IN = 0x40000A1Du, /* tcpwm[0].tr_one_cnt_in[9] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT4_TR2_IN = 0x40000A1Eu, /* tcpwm[0].tr_one_cnt_in[12] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT5_TR2_IN = 0x40000A1Fu, /* tcpwm[0].tr_one_cnt_in[15] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT6_TR2_IN = 0x40000A20u, /* tcpwm[0].tr_one_cnt_in[18] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT7_TR2_IN = 0x40000A21u, /* tcpwm[0].tr_one_cnt_in[21] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT0_TR2_IN = 0x40000A22u, /* tcpwm[0].tr_one_cnt_in[768] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT1_TR2_IN = 0x40000A23u, /* tcpwm[0].tr_one_cnt_in[771] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT2_TR2_IN = 0x40000A24u, /* tcpwm[0].tr_one_cnt_in[774] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT3_TR2_IN = 0x40000A25u, /* tcpwm[0].tr_one_cnt_in[777] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT4_TR2_IN = 0x40000A26u, /* tcpwm[0].tr_one_cnt_in[780] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT5_TR2_IN = 0x40000A27u, /* tcpwm[0].tr_one_cnt_in[783] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT6_TR2_IN = 0x40000A28u, /* tcpwm[0].tr_one_cnt_in[786] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT7_TR2_IN = 0x40000A29u, /* tcpwm[0].tr_one_cnt_in[789] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT0_TR2_IN = 0x40000A2Au, /* tcpwm[0].tr_one_cnt_in[1536] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT1_TR2_IN = 0x40000A2Bu, /* tcpwm[0].tr_one_cnt_in[1539] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT2_TR2_IN = 0x40000A2Cu, /* tcpwm[0].tr_one_cnt_in[1542] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT3_TR2_IN = 0x40000A2Du, /* tcpwm[0].tr_one_cnt_in[1545] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT4_TR2_IN = 0x40000A2Eu, /* tcpwm[0].tr_one_cnt_in[1548] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT5_TR2_IN = 0x40000A2Fu, /* tcpwm[0].tr_one_cnt_in[1551] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT6_TR2_IN = 0x40000A30u, /* tcpwm[0].tr_one_cnt_in[1554] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT7_TR2_IN = 0x40000A31u, /* tcpwm[0].tr_one_cnt_in[1557] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT0_TR3_IN = 0x40000A32u, /* tcpwm[0].tr_one_cnt_in[1] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT1_TR3_IN = 0x40000A33u, /* tcpwm[0].tr_one_cnt_in[4] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT2_TR3_IN = 0x40000A34u, /* tcpwm[0].tr_one_cnt_in[7] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT3_TR3_IN = 0x40000A35u, /* tcpwm[0].tr_one_cnt_in[10] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT4_TR3_IN = 0x40000A36u, /* tcpwm[0].tr_one_cnt_in[13] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT5_TR3_IN = 0x40000A37u, /* tcpwm[0].tr_one_cnt_in[16] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT6_TR3_IN = 0x40000A38u, /* tcpwm[0].tr_one_cnt_in[19] */
    TRIG_OUT_MUX_10_TCPWM0_GRP0_CNT7_TR3_IN = 0x40000A39u, /* tcpwm[0].tr_one_cnt_in[22] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT0_TR3_IN = 0x40000A3Au, /* tcpwm[0].tr_one_cnt_in[769] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT1_TR3_IN = 0x40000A3Bu, /* tcpwm[0].tr_one_cnt_in[772] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT2_TR3_IN = 0x40000A3Cu, /* tcpwm[0].tr_one_cnt_in[775] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT3_TR3_IN = 0x40000A3Du, /* tcpwm[0].tr_one_cnt_in[778] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT4_TR3_IN = 0x40000A3Eu, /* tcpwm[0].tr_one_cnt_in[781] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT5_TR3_IN = 0x40000A3Fu, /* tcpwm[0].tr_one_cnt_in[784] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT6_TR3_IN = 0x40000A40u, /* tcpwm[0].tr_one_cnt_in[787] */
    TRIG_OUT_MUX_10_TCPWM0_GRP1_CNT7_TR3_IN = 0x40000A41u, /* tcpwm[0].tr_one_cnt_in[790] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT0_TR3_IN = 0x40000A42u, /* tcpwm[0].tr_one_cnt_in[1537] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT1_TR3_IN = 0x40000A43u, /* tcpwm[0].tr_one_cnt_in[1540] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT2_TR3_IN = 0x40000A44u, /* tcpwm[0].tr_one_cnt_in[1543] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT3_TR3_IN = 0x40000A45u, /* tcpwm[0].tr_one_cnt_in[1546] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT4_TR3_IN = 0x40000A46u, /* tcpwm[0].tr_one_cnt_in[1549] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT5_TR3_IN = 0x40000A47u, /* tcpwm[0].tr_one_cnt_in[1552] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT6_TR3_IN = 0x40000A48u, /* tcpwm[0].tr_one_cnt_in[1555] */
    TRIG_OUT_MUX_10_TCPWM0_GRP2_CNT7_TR3_IN = 0x40000A49u /* tcpwm[0].tr_one_cnt_in[1558] */
} en_trig_output_tcpwm0_t;

/* Trigger Output Group 11 - TCPWM1 trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_11_TCPWM0_GRP0_CNT0_TR4_IN = 0x40000B00u, /* tcpwm[0].tr_one_cnt_in[2] */
    TRIG_OUT_MUX_11_TCPWM0_GRP0_CNT1_TR4_IN = 0x40000B01u, /* tcpwm[0].tr_one_cnt_in[5] */
    TRIG_OUT_MUX_11_TCPWM0_GRP0_CNT2_TR4_IN = 0x40000B02u, /* tcpwm[0].tr_one_cnt_in[8] */
    TRIG_OUT_MUX_11_TCPWM0_GRP0_CNT3_TR4_IN = 0x40000B03u, /* tcpwm[0].tr_one_cnt_in[11] */
    TRIG_OUT_MUX_11_TCPWM0_GRP0_CNT4_TR4_IN = 0x40000B04u, /* tcpwm[0].tr_one_cnt_in[14] */
    TRIG_OUT_MUX_11_TCPWM0_GRP0_CNT5_TR4_IN = 0x40000B05u, /* tcpwm[0].tr_one_cnt_in[17] */
    TRIG_OUT_MUX_11_TCPWM0_GRP0_CNT6_TR4_IN = 0x40000B06u, /* tcpwm[0].tr_one_cnt_in[20] */
    TRIG_OUT_MUX_11_TCPWM0_GRP0_CNT7_TR4_IN = 0x40000B07u, /* tcpwm[0].tr_one_cnt_in[23] */
    TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT0_TR4_IN = 0x40000B08u, /* tcpwm[0].tr_one_cnt_in[770] */
    TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT1_TR4_IN = 0x40000B09u, /* tcpwm[0].tr_one_cnt_in[773] */
    TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT2_TR4_IN = 0x40000B0Au, /* tcpwm[0].tr_one_cnt_in[776] */
    TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT3_TR4_IN = 0x40000B0Bu, /* tcpwm[0].tr_one_cnt_in[779] */
    TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT4_TR4_IN = 0x40000B0Cu, /* tcpwm[0].tr_one_cnt_in[782] */
    TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT5_TR4_IN = 0x40000B0Du, /* tcpwm[0].tr_one_cnt_in[785] */
    TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT6_TR4_IN = 0x40000B0Eu, /* tcpwm[0].tr_one_cnt_in[788] */
    TRIG_OUT_MUX_11_TCPWM0_GRP1_CNT7_TR4_IN = 0x40000B0Fu, /* tcpwm[0].tr_one_cnt_in[791] */
    TRIG_OUT_MUX_11_TCPWM0_GRP2_CNT0_TR4_IN = 0x40000B10u, /* tcpwm[0].tr_one_cnt_in[1538] */
    TRIG_OUT_MUX_11_TCPWM0_GRP2_CNT1_TR4_IN = 0x40000B11u, /* tcpwm[0].tr_one_cnt_in[1541] */
    TRIG_OUT_MUX_11_TCPWM0_GRP2_CNT2_TR4_IN = 0x40000B12u, /* tcpwm[0].tr_one_cnt_in[1544] */
    TRIG_OUT_MUX_11_TCPWM0_GRP2_CNT3_TR4_IN = 0x40000B13u, /* tcpwm[0].tr_one_cnt_in[1547] */
    TRIG_OUT_MUX_11_TCPWM0_GRP2_CNT4_TR4_IN = 0x40000B14u, /* tcpwm[0].tr_one_cnt_in[1550] */
    TRIG_OUT_MUX_11_TCPWM0_GRP2_CNT5_TR4_IN = 0x40000B15u, /* tcpwm[0].tr_one_cnt_in[1553] */
    TRIG_OUT_MUX_11_TCPWM0_GRP2_CNT6_TR4_IN = 0x40000B16u, /* tcpwm[0].tr_one_cnt_in[1556] */
    TRIG_OUT_MUX_11_TCPWM0_GRP2_CNT7_TR4_IN = 0x40000B17u /* tcpwm[0].tr_one_cnt_in[1559] */
} en_trig_output_tcpwm1_t;

/* Trigger Output Group 12 - TCPWM MOTIF trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP1_TR_IN0 = 0x40000C00u, /* tcpwm[0].tr_motif_in[256] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP1_TR_IN1 = 0x40000C01u, /* tcpwm[0].tr_motif_in[257] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP1_TR_IN2 = 0x40000C02u, /* tcpwm[0].tr_motif_in[258] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP1_TR_IN3 = 0x40000C03u, /* tcpwm[0].tr_motif_in[259] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP1_TR_IN4 = 0x40000C04u, /* tcpwm[0].tr_motif_in[260] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP1_TR_IN5 = 0x40000C05u, /* tcpwm[0].tr_motif_in[261] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP1_TR_IN6 = 0x40000C06u, /* tcpwm[0].tr_motif_in[262] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP1_TR_IN7 = 0x40000C07u, /* tcpwm[0].tr_motif_in[263] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP2_TR_IN0 = 0x40000C08u, /* tcpwm[0].tr_motif_in[512] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP2_TR_IN1 = 0x40000C09u, /* tcpwm[0].tr_motif_in[513] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP2_TR_IN2 = 0x40000C0Au, /* tcpwm[0].tr_motif_in[514] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP2_TR_IN3 = 0x40000C0Bu, /* tcpwm[0].tr_motif_in[515] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP2_TR_IN4 = 0x40000C0Cu, /* tcpwm[0].tr_motif_in[516] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP2_TR_IN5 = 0x40000C0Du, /* tcpwm[0].tr_motif_in[517] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP2_TR_IN6 = 0x40000C0Eu, /* tcpwm[0].tr_motif_in[518] */
    TRIG_OUT_MUX_12_TCPWM0_MOTIF_GRP2_TR_IN7 = 0x40000C0Fu /* tcpwm[0].tr_motif_in[519] */
} en_trig_output_tcpwm_motif_t;

/* Trigger Output Group 13 - MCPASS trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_13_PASS_TR_A_IN0   = 0x40000D00u, /* pass.tr_a_in[0] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN1   = 0x40000D01u, /* pass.tr_a_in[1] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN2   = 0x40000D02u, /* pass.tr_a_in[2] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN3   = 0x40000D03u, /* pass.tr_a_in[3] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN4   = 0x40000D04u, /* pass.tr_a_in[4] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN5   = 0x40000D05u, /* pass.tr_a_in[5] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN6   = 0x40000D06u, /* pass.tr_a_in[6] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN7   = 0x40000D07u, /* pass.tr_a_in[7] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN8   = 0x40000D08u, /* pass.tr_a_in[8] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN9   = 0x40000D09u, /* pass.tr_a_in[9] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN10  = 0x40000D0Au, /* pass.tr_a_in[10] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN11  = 0x40000D0Bu, /* pass.tr_a_in[11] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN12  = 0x40000D0Cu, /* pass.tr_a_in[12] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN13  = 0x40000D0Du, /* pass.tr_a_in[13] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN14  = 0x40000D0Eu, /* pass.tr_a_in[14] */
    TRIG_OUT_MUX_13_PASS_TR_A_IN15  = 0x40000D0Fu, /* pass.tr_a_in[15] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN0   = 0x40000D10u, /* pass.tr_b_in[0] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN1   = 0x40000D11u, /* pass.tr_b_in[1] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN2   = 0x40000D12u, /* pass.tr_b_in[2] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN3   = 0x40000D13u, /* pass.tr_b_in[3] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN4   = 0x40000D14u, /* pass.tr_b_in[4] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN5   = 0x40000D15u, /* pass.tr_b_in[5] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN6   = 0x40000D16u, /* pass.tr_b_in[6] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN7   = 0x40000D17u, /* pass.tr_b_in[7] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN8   = 0x40000D18u, /* pass.tr_b_in[8] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN9   = 0x40000D19u, /* pass.tr_b_in[9] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN10  = 0x40000D1Au, /* pass.tr_b_in[10] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN11  = 0x40000D1Bu, /* pass.tr_b_in[11] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN12  = 0x40000D1Cu, /* pass.tr_b_in[12] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN13  = 0x40000D1Du, /* pass.tr_b_in[13] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN14  = 0x40000D1Eu, /* pass.tr_b_in[14] */
    TRIG_OUT_MUX_13_PASS_TR_B_IN15  = 0x40000D1Fu /* pass.tr_b_in[15] */
} en_trig_output_mcpass_t;

/* Trigger Output Group 14 - USBFS trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_14_USB_DMA_BURSTEND0 = 0x40000E00u, /* usb[0].usb_dma_burstend[0] */
    TRIG_OUT_MUX_14_USB_DMA_BURSTEND1 = 0x40000E01u, /* usb[0].usb_dma_burstend[1] */
    TRIG_OUT_MUX_14_USB_DMA_BURSTEND2 = 0x40000E02u, /* usb[0].usb_dma_burstend[2] */
    TRIG_OUT_MUX_14_USB_DMA_BURSTEND3 = 0x40000E03u, /* usb[0].usb_dma_burstend[3] */
    TRIG_OUT_MUX_14_USB_DMA_BURSTEND4 = 0x40000E04u, /* usb[0].usb_dma_burstend[4] */
    TRIG_OUT_MUX_14_USB_DMA_BURSTEND5 = 0x40000E05u, /* usb[0].usb_dma_burstend[5] */
    TRIG_OUT_MUX_14_USB_DMA_BURSTEND6 = 0x40000E06u, /* usb[0].usb_dma_burstend[6] */
    TRIG_OUT_MUX_14_USB_DMA_BURSTEND7 = 0x40000E07u /* usb[0].usb_dma_burstend[7] */
} en_trig_output_usbfs_t;

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
/* CORDIC Trigger Types */
#define TRIGGER_TYPE_CORDIC_TR_DONE_MXCORDIC    TRIGGER_TYPE_LEVEL
/* CPUSS Trigger Types */
#define TRIGGER_TYPE_CPUSS_DW0_TR_IN__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DW0_TR_IN__EDGE      TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW0_TR_OUT           TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW1_TR_IN__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DW1_TR_IN__EDGE      TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW1_TR_OUT           TRIGGER_TYPE_EDGE
/* CRYPTOLITE Trigger Types */
#define TRIGGER_TYPE_CRYPTOLITE_TR_TRNG_BITSTREAM TRIGGER_TYPE_LEVEL
/* I3C Trigger Types */
#define TRIGGER_TYPE_I3C_TR_RX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_I3C_TR_TX_REQ              TRIGGER_TYPE_LEVEL
/* LPCOMP Trigger Types */
#define TRIGGER_TYPE_LPCOMP_DSI_COMP0           TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_LPCOMP_DSI_COMP1           TRIGGER_TYPE_LEVEL
/* PASS Trigger Types */
#define TRIGGER_TYPE_PASS_TR_A_IN__LEVEL        TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_A_IN__EDGE         TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PASS_TR_B_IN__LEVEL        TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_B_IN__EDGE         TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PASS_TR_FIFO_LEVEL_OUT     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_LEVEL_OUT          TRIGGER_TYPE_LEVEL
/* PERI Trigger Types */
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__LEVEL    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__EDGE     TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__LEVEL   TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__EDGE    TRIGGER_TYPE_EDGE
/* SCB Trigger Types */
#define TRIGGER_TYPE_SCB_TR_I2C_SCL_FILTERED    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_RX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_TGS_GATED           TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_TGS_RELOAD          TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_TGS_STOP            TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_TX_REQ              TRIGGER_TYPE_LEVEL
/* TCPWM Trigger Types */
#define TRIGGER_TYPE_TCPWM_TR_DEBUG_FREEZE      TRIGGER_TYPE_LEVEL
/* USB Trigger Types */
#define TRIGGER_TYPE_USB_USB_DMA_BURSTEND       TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_USB_USB_DMA_REQ            TRIGGER_TYPE_EDGE

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
    SVGS_FAULT                      = 0x0021u,
    MXAES_FAULT                     = 0x0022u,
    CY_SYSFAULT_NO_FAULT            = 0x0023u
} en_sysfault_source_t;

/* Include IP definitions */
#include "ip/cyip_sflash_psc3m6.h"
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
#include "ip/cyip_mxcordic_1_1_v1_1.h"
#include "ip/cyip_debug600_v1_2.h"
#include "ip/cyip_svgs.h"
#include "ip/cyip_mxaes_v2_2.h"
#include "ip/cyip_mxwound_v1_1.h"
#include "ip/cyip_hsiom_v1_3.h"
#include "ip/cyip_gpio_v1_3.h"
#include "ip/cyip_smartio_v1_3.h"
#include "ip/cyip_lpcomp_v2_1.h"
#include "ip/cyip_efuse_v3_1.h"
#include "ip/cyip_canfd_v3.h"
#include "ip/cyip_scb_v4_5.h"
#include "ip/cyip_tcpwm_v1_2.h"
#include "ip/cyip_hppass_v3.h"
#include "ip/cyip_i3c.h"
#include "ip/cyip_usbfs.h"
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
#define CPUSS_DW1_PRESENT               1u
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
#define CPUSS_IPC_NR                    4u
/* Number of IPC interrupt structures. Legal range [1, 16] */
#define CPUSS_IPC_IRQ_NR                2u
/* Number of protection contexts supported. Legal range [3, 4, 6, 8] (CDT-336698) */
#define CPUSS_PC_NR                     8u
/* CM33_0 PC monitor present or not */
#define CPUSS_CM33_0_PC_MON_PRESENT     1u
/* IRQ expander present ('0': no, '1': yes) */
#define CPUSS_SYSTEM_IRQ_PRESENT        0u
/* Number of system interrupt inputs to CPUSS */
#define CPUSS_SYSTEM_INT_NR             167u
/* Number of DeepSleep system interrupt inputs to CPUSS */
#define CPUSS_SYSTEM_DPSLP_INT_NR       38u
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
#define CPUSS_EXP_MS_PRESENT            0u
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
#define CPUSS_FAMILYID                  292u
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
/* SHA-256 hash component support ('0': no, '1': yes). */
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
#define DEBUG600_FAMILYID               292u
/* Compiled cells vendor: 1:SNPS, 2:ARM, 3:BRCM */
#define DEBUG600_RAM_VEND               1u
/* PLATFORM VARIANT for ITCM SRAM (To determine ITCM SRAM memory type) */
#define DEBUG600_PLATFORM_VARIANT       6u
/* VT type of instantiated tech cells through mxtk. */
#define DEBUG600_CELL_VT_TYPE           0u
/* ECOREV Value to the Coresight components */
#define DEBUG600_REVAND                 0u
/* CM55_0 present or not. */
#define DEBUG600_CM55_0_PRESENT         0u
/* CM55_1 present or not. */
#define DEBUG600_CM55_1_PRESENT         0u
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
#define DFT_NUM_FASTCLK                 1u
/* Number of select signals to control each FASTCLK multiplexer. Not expected to
   be more than 2 */
#define DFT_NUM_FASTCLK_SEL             1u
/* Number of MBIST controllers with corresponding mbist(pg)_done and mbist(pg)_go
   signals. Value defined by CIC during Pass 1. */
#define DFT_MBIST_C_NUM                 5u
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
#define DFT_MBIST0_C_NUM                5u
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
#define DW0_CH_NR                       16u
/* DataWire SRAM ECC present or not ('0': no, '1': yes) */
#define DW0_ECC_PRESENT                 0u
/* DataWire SRAM address ECC present or not ('0': no, '1': yes) */
#define DW0_ECC_ADDR_PRESENT            0u
#define DW0_CH_NR_WIDTH                 1u
#define DW0_CH_STRUCT_ECC_PRESENT       0u
/* Number of DataWire channels ([1, 512]) */
#define DW1_CH_NR                       16u
/* DataWire SRAM ECC present or not ('0': no, '1': yes) */
#define DW1_ECC_PRESENT                 0u
/* DataWire SRAM address ECC present or not ('0': no, '1': yes) */
#define DW1_ECC_ADDR_PRESENT            0u
#define DW1_CH_NR_WIDTH                 1u
#define DW1_CH_STRUCT_ECC_PRESENT       0u
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
#define IOSS_GPIO_GPIO_PORT_NR_0_31     14u
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
#define IOSS_GPIO_GPIO_PORT_NR          14u
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
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_RES_CFG 0u
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
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_RES_CFG 0u
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
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO5 0u
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
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_RES_CFG 0u
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
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_RES_CFG 0u
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
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DRIVEMODE_EXT 1u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_RES_WIDTH 4u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_RES_CFG 1u
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
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DRIVEMODE_WIDTH 4u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DRIVEMODE_EXT 1u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_RES_WIDTH 4u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_RES_CFG 1u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO3 1u
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
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_RES_CFG 0u
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
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_RES_CFG 0u
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
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_RES_CFG 0u
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
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DRIVE_EXT 1u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_GPIO 0u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DRIVE_EXT 1u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DRIVE_EXT 1u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SIO 0u
/* Indicates port is an HSIO port */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_HSIO 0u
/* Indicates port is a GPIO_SMC */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_GPIO_SMC 0u
/* Indicates port is a HSIO_ENH */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_HSIO_ENH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_AUTOLVL 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension trims */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DRIVE_EXT 1u
/* Width of CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DRIVEMODE_WIDTH 0u
/* Indicates port supports CFG_OUT/DRIVEMODE_EXT bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DRIVEMODE_EXT 0u
/* Width of CFG_RES Bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_RES_WIDTH 0u
/* Inidcates port support RES_CFG bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_RES_CFG 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLEW_WIDTH 1u
/* Indicates drive bit width */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DRIVE_WIDTH 3u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO7 0u
/* Power Switch exists */
#define IOSS_GPIO_PWRSW                 0u
/* Indicates if Secure access is enabled */
#define IOSS_GPIO_SECEXT                1u
/* Number of AMUX splitter cells */
#define IOSS_HSIOM_AMUX_SPLIT_NR        6u
/* Number of HSIOM ports in device (same as GPIO.GPIO_PRT_NR) */
#define IOSS_HSIOM_HSIOM_PORT_NR        14u
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
#define IOSS_HSIOM_HSIOM_SEC_PORT_NR    14u
/* Indicates if Secure access is enabled */
#define IOSS_HSIOM_SECEXT               1u
/* Security extension present ('0': no, '1': yes) */
#define IOSS_HSIOM_SECURE_PRT_SECEXT    1u
/* Mask of SMARTIO instances presence */
#define IOSS_SMARTIO_SMARTIO_MASK       623u
/* Page size in # of 32-bit words (1: 4 bytes, 2: 8 bytes, ... */
#define IPC_PA_SIZE                     1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define IPC_MASTER_WIDTH                6u
#define IPC_IPC_NR                      4u
#define IPC_IPC_IRQ_NR                  2u
/* IKS_KWORD_NB (Number of 32-bit key words in IKS. 0:MXAES does not support
   internal key storage. 1-96:Number of key words available in IKS. IKS_KWORD_NB
   has to be set to a multiple of 4.) */
#define MXAES_IKS_KWORD_NB              0u
/* EXTERNAL_ACCESS_MANAGEMENT (0: HAUSER value is evaluated for access rights
   management of MXAES, 1: HAUSER[0] is forced to 0 by MXAES peripheral(i.e.
   MXAES is in BOS access mode)). Note that a MXAES design with
   EXTERNAL_ACCESS_MANAGEMENT=0 and where HAUSER[0]=1, NRNGA_INTEGRATION shall
   be set to 1 because PC0/BOS seeding is not possible. */
#define MXAES_EXTERNAL_ACCESS_MANAGEMENT 1u
/* USE_POWER_ON_DOMAIN(0: no, 1: yes) 0: ALM_MON and SEED_* SFRs NonRetention 1:
   ALM_MON and SEED_* SFRs DeepSleep Note: This parameter is only verified for
   value 0. */
#define MXAES_Unmasked_inter_range_2_2_USE_POWER_ON_DOMAIN 0u
/* NRNGA_INTEGRATION (0: no, 1: yes) 0: 4-times SW seeding required 1: NRNGA
   seeding source available */
#define MXAES_Unmasked_user_range_2_2_NRNGA_INTEGRATION 1u
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
#define MXCM33_SYSTEM_INT_NR            167u
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
#define PERI_GROUP_PRESENT4_PERI_GROUP_CLOCK_PRESENT 0u
/* Default value for SL_CTL register value on POR. Group-0 it is 32'hFFFF_FFFF
   Group-1 to Group-15 it is 32'h000_0000 */
#define PERI_GROUP_PRESENT4_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_CLOCK_PRESENT 1u
/* Default value for SL_CTL register value on POR. Group-0 it is 32'hFFFF_FFFF
   Group-1 to Group-15 it is 32'h000_0000 */
#define PERI_GROUP_PRESENT5_PERI_GROUP_SL_CTL_DEFAULT 0u
/* Clock group divider default value (This is not used in RTL yet, for SW usage) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_GROUP_CLOCK_CTL_DIV_DEFAULT 0u
/* Number of asynchronous PCLK groups */
#define PERI_PCLK_GROUP_NR              10u
/* Timeout functionality present ('0': no, '1': yes) */
#define PERI_TIMEOUT_PRESENT            1u
/* AHB ERROR response reporting present ('0': no, '1':yes) */
#define PERI_AHB_ERROR_PRESENT          1u
/* Trigger module present ('0': no, '1': yes) */
#define PERI_TR                         1u
/* Number of trigger groups */
#define PERI_TR_GROUP_NR                15u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR0_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR1_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR2_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR3_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR4_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR5_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR6_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR7_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR8_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR9_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR10_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR11_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR12_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR13_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR14_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Divider number width: max(1,roundup(log2(max(DIV_*_NR))) */
#define PERI_GR_DIV_ADDR_WIDTH          4u
/* Number of asynchronous PCLK groups */
#define PERI_PERI_PCLK_PCLK_GROUP_NR    10u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_8_VECT 12u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_VECT 6u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_5_VECT 2u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_24_5_VECT 1u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_CLOCK_VECT 28u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_8_VECT 1u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_CLOCK_VECT 7u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR2_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR3_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_8_VECT 4u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_VECT 1u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_16_5_VECT 3u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_DIV_24_5_VECT 1u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_CLOCK_VECT 12u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR4_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR5_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_8_VECT 1u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_16_5_VECT 3u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR6_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR6_GR_CLOCK_VECT 4u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR6_GR_PCLK_DIV_PRESENT 1u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR7_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR7_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR7_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR8_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR8_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR8_GR_PCLK_DIV_PRESENT 0u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_8_VECT 0u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_16_VECT 0u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR9_GR_DIV_24_5_VECT 0u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR9_GR_CLOCK_VECT 0u
/* If Direct Clocks PCLK DIVIDER would be zero, other wise 1 */
#define PERI_PERI_PCLK_PCLK_GROUP_NR9_GR_PCLK_DIV_PRESENT 0u
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
#define PERI_PPC_PPC_NR92_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR93_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR94_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR95_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR96_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR97_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR98_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR99_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR100_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR101_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR102_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR103_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR104_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR105_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR106_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR107_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR108_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR109_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR110_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR111_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR112_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR113_SECURITY_AWARE 1u
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
#define PERI_PPC_PPC_NR129_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR130_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR131_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR132_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR133_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR134_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR135_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR136_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR137_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR138_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR139_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR140_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR141_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR142_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR143_SECURITY_AWARE 0u
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
#define PERI_PPC_PPC_NR174_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR175_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR176_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR177_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR178_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR179_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR180_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR181_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR182_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR183_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR184_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR185_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR186_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR187_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR188_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR189_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR190_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR191_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR192_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR193_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR194_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR195_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR196_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR197_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR198_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR199_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR200_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR201_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR202_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR203_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR204_SECURITY_AWARE 1u
/* Security Aware */
#define PERI_PPC_PPC_NR205_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR206_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR207_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR208_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR209_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR210_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR211_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR212_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR213_SECURITY_AWARE 0u
/* Security Aware */
#define PERI_PPC_PPC_NR214_SECURITY_AWARE 0u
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
/* SPI SSEL lines usage. This parameter is used in RTL and can only be 4, 8, or
   16. This paramter should be equal or greater than CHIP_TOP SPI_SEL_NR
   parameter. */
#define SCB0_SPI_SEL_NR                 4u
/* Number of used spi_select signals (max 16). Only used for connectivity check.
   No HW impact. This number however should match the SPI_SEL_NR being used in
   the RTL */
#define SCB0_CHIP_TOP_SPI_SEL_NR        4u
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
/* SPI SSEL lines usage. This parameter is used in RTL and can only be 4, 8, or
   16. This paramter should be equal or greater than CHIP_TOP SPI_SEL_NR
   parameter. */
#define SCB1_SPI_SEL_NR                 8u
/* Number of used spi_select signals (max 16). Only used for connectivity check.
   No HW impact. This number however should match the SPI_SEL_NR being used in
   the RTL */
#define SCB1_CHIP_TOP_SPI_SEL_NR        8u
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
/* SPI SSEL lines usage. This parameter is used in RTL and can only be 4, 8, or
   16. This paramter should be equal or greater than CHIP_TOP SPI_SEL_NR
   parameter. */
#define SCB2_SPI_SEL_NR                 4u
/* Number of used spi_select signals (max 16). Only used for connectivity check.
   No HW impact. This number however should match the SPI_SEL_NR being used in
   the RTL */
#define SCB2_CHIP_TOP_SPI_SEL_NR        4u
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
/* SPI SSEL lines usage. This parameter is used in RTL and can only be 4, 8, or
   16. This paramter should be equal or greater than CHIP_TOP SPI_SEL_NR
   parameter. */
#define SCB3_SPI_SEL_NR                 8u
/* Number of used spi_select signals (max 16). Only used for connectivity check.
   No HW impact. This number however should match the SPI_SEL_NR being used in
   the RTL */
#define SCB3_CHIP_TOP_SPI_SEL_NR        8u
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
/* SPI SSEL lines usage. This parameter is used in RTL and can only be 4, 8, or
   16. This paramter should be equal or greater than CHIP_TOP SPI_SEL_NR
   parameter. */
#define SCB4_SPI_SEL_NR                 4u
/* Number of used spi_select signals (max 16). Only used for connectivity check.
   No HW impact. This number however should match the SPI_SEL_NR being used in
   the RTL */
#define SCB4_CHIP_TOP_SPI_SEL_NR        4u
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
/* SPI SSEL lines usage. This parameter is used in RTL and can only be 4, 8, or
   16. This paramter should be equal or greater than CHIP_TOP SPI_SEL_NR
   parameter. */
#define SCB5_SPI_SEL_NR                 8u
/* Number of used spi_select signals (max 16). Only used for connectivity check.
   No HW impact. This number however should match the SPI_SEL_NR being used in
   the RTL */
#define SCB5_CHIP_TOP_SPI_SEL_NR        8u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB5_CHIP_TOP_I2C_FAST_PLUS     1u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB5_CHIP_TOP_DDFT_USED         4u
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
#define SRSS_NUM_ACTREG_PWRMOD          2u
/* Number of shorting switches between vccd and vccact. Must be > 0. */
#define SRSS_NUM_ACTIVE_SWITCH          2u
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
#define SRSS_NUM_DPLL250                1u
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
#define SRSS_MASK_DEBUG_CLK             1u
/* Total number of PLLs present. */
#define SRSS_NUM_TOTAL_PLL              1u
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
#define SRSS_PDCM_PD_PRESENT            15u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT0_PDCM_PD_DEFAULT_ON 14u
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
#define SRSS_PDCM_PD_PRESENT4_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT5_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT5_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT6_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT6_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT7_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT7_PDCM_PD_CONFIG_ON 0u
/* Mask of PDCM PD_FORCE_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_FORCE_ON[k%16]. For a non-configurable sense bit, a high
   value for bit k indicates whether PD<k/16> is always kept on when PD<k%16> is
   on. For configurable sense bits, this indicates the reset value of the
   configuration register. */
#define SRSS_PDCM_PD_PRESENT8_PDCM_PD_DEFAULT_ON 0u
/* Mask of PDCM PD_CONFIG_ON bits. Each bit k maps to
   PD_SPT[k/16].PD_CONFIG_ON[k%16]. A high value for bit k indicates whether
   PD<k/16> can be configured on when PD<k%16> is on. */
#define SRSS_PDCM_PD_PRESENT8_PDCM_PD_CONFIG_ON 0u
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
#define TCPWM_TR_ALL_CNT_NR             26u
/* Number of TCPWM counter groups (1..8) */
#define TCPWM_GRP_NR                    3u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR0_CNT_GRP_CNT_WIDTH 32u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR0_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR0_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1) */
#define TCPWM_GRP_NR0_CNT_GRP_SMC_PRESENT 1u
/* Dithering Function is present (0,1) */
#define TCPWM_GRP_NR0_CNT_GRP_DITHERING_PRESENT 0u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define TCPWM_GRP_NR0_CNT_TR_ONE_GF_NR  1u
/* Quadrature feature inside counter are present (0, 1) */
#define TCPWM_GRP_NR0_CNT_QUAD_PRESENT  0u
/* PWM_PR feature inside counter is present (0, 1) */
#define TCPWM_GRP_NR0_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define TCPWM_GRP_NR0_CNT_SR_PRESENT    0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define TCPWM_GRP_NR0_CNT_GRP_DATA_IN_CC_PRESENT 1u
/* HRPWM feature extension is available for counter group(0,1) */
#define TCPWM_GRP_NR0_CNT_GRP_HRPWM_PRESENT 1u
/* Number of micro ticks bits supported in HRPWM feature (2,3,4,5,6,7,8) */
#define TCPWM_GRP_NR0_CNT_GRP_HRPWM_WIDTH 6u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR0_GRP_GRP_CNT_NR    8u
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
#define TCPWM_GRP_NR1_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR1_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1) */
#define TCPWM_GRP_NR1_CNT_GRP_SMC_PRESENT 1u
/* Dithering Function is present (0,1) */
#define TCPWM_GRP_NR1_CNT_GRP_DITHERING_PRESENT 1u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define TCPWM_GRP_NR1_CNT_TR_ONE_GF_NR  1u
/* Quadrature feature inside counter are present (0, 1) */
#define TCPWM_GRP_NR1_CNT_QUAD_PRESENT  1u
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
#define TCPWM_GRP_NR1_GRP_GRP_CNT_NR    8u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define TCPWM_GRP_NR1_MOTIF_GRP_GRP_MOTIF_NR 1u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define TCPWM_GRP_NR1_MOTIF_GRP_GRP_MOTIF_TR_NR 8u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define TCPWM_GRP_NR1_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 2u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR2_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR2_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR2_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1) */
#define TCPWM_GRP_NR2_CNT_GRP_SMC_PRESENT 1u
/* Dithering Function is present (0,1) */
#define TCPWM_GRP_NR2_CNT_GRP_DITHERING_PRESENT 1u
/* Number of glitch filters only routed to input triggers per counter which is
   only routed to one counter(0..8) */
#define TCPWM_GRP_NR2_CNT_TR_ONE_GF_NR  1u
/* Quadrature feature inside counter are present (0, 1) */
#define TCPWM_GRP_NR2_CNT_QUAD_PRESENT  1u
/* PWM_PR feature inside counter is present (0, 1) */
#define TCPWM_GRP_NR2_CNT_PWM_PR_PRESENT 0u
/* SR feature inside counter is present (0, 1) */
#define TCPWM_GRP_NR2_CNT_SR_PRESENT    0u
/* Parallel data path for CC0 and CC1 register present (0,1) */
#define TCPWM_GRP_NR2_CNT_GRP_DATA_IN_CC_PRESENT 0u
/* HRPWM feature extension is available for counter group(0,1) */
#define TCPWM_GRP_NR2_CNT_GRP_HRPWM_PRESENT 0u
/* Number of micro ticks bits supported in HRPWM feature (2,3,4,5,6,7,8) */
#define TCPWM_GRP_NR2_CNT_GRP_HRPWM_WIDTH 0u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR2_GRP_GRP_CNT_NR    8u
/* Number of TCPWM MOTIF instances units per counter group (0..32) */
#define TCPWM_GRP_NR2_MOTIF_GRP_GRP_MOTIF_NR 1u
/* Number of TCPWM MOTIF inputs/outputs triggers per MOTIF being instantized on
   Product Level. */
#define TCPWM_GRP_NR2_MOTIF_GRP_GRP_MOTIF_TR_NR 8u
/* Number of TCPWM MOTIF interrupt triggers per MOTIF being instantized on Product
   Level. */
#define TCPWM_GRP_NR2_MOTIF_GRP_GRP_MOTIF_INT_TR_NR 2u
/* Number of input triggers per counter only routed to one counter (0..8) */
#define TCPWM_CNT_TR_ONE_CNT_NR         3u
/* Number of glitch filters routed to input triggers that are routed to all
   counters (0..254), NR_TR_ONE_CNT+NR_TR_ALL CNT <= 254 */
#define TCPWM_TR_ALL_GF_TR_ALL_GF_NR    26u
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
/* MMIO0.MXCORDIC */
#define CY_MMIO_MXCORDIC_GROUP_NR       0u
#define CY_MMIO_MXCORDIC_SLAVE_NR       8u
/* MMIO0.DEBUG600 */
#define CY_MMIO_DEBUG600_GROUP_NR       0u
#define CY_MMIO_DEBUG600_SLAVE_NR       9u
/* MMIO0.SVGS */
#define CY_MMIO_SVGS_GROUP_NR           0u
#define CY_MMIO_SVGS_SLAVE_NR           10u
/* MMIO0.MXAES */
#define CY_MMIO_MXAES_GROUP_NR          0u
#define CY_MMIO_MXAES_SLAVE_NR          11u
/* MMIO0.MXWOUND */
#define CY_MMIO_MXWOUND_GROUP_NR        0u
#define CY_MMIO_MXWOUND_SLAVE_NR        12u
/* MMIO1.HSIOM */
#define CY_MMIO_HSIOM_GROUP_NR          1u
#define CY_MMIO_HSIOM_SLAVE_NR          0u
/* MMIO1.GPIO */
#define CY_MMIO_GPIO_GROUP_NR           1u
#define CY_MMIO_GPIO_SLAVE_NR           1u
/* MMIO1.SMARTIO */
#define CY_MMIO_SMARTIO_GROUP_NR        1u
#define CY_MMIO_SMARTIO_SLAVE_NR        2u
/* MMIO1.LPCOMP */
#define CY_MMIO_LPCOMP_GROUP_NR         1u
#define CY_MMIO_LPCOMP_SLAVE_NR         3u
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
/* MMIO4.TCPWM0 */
#define CY_MMIO_TCPWM0_GROUP_NR         4u
#define CY_MMIO_TCPWM0_SLAVE_NR         0u
/* MMIO4.PASS */
#define CY_MMIO_PASS_GROUP_NR           4u
#define CY_MMIO_PASS_SLAVE_NR           1u
/* MMIO5.SCB5 */
#define CY_MMIO_SCB5_GROUP_NR           5u
#define CY_MMIO_SCB5_SLAVE_NR           0u
/* MMIO5.I3C0 */
#define CY_MMIO_I3C0_GROUP_NR           5u
#define CY_MMIO_I3C0_SLAVE_NR           1u
/* MMIO5.USBFS0 */
#define CY_MMIO_USBFS0_GROUP_NR         5u
#define CY_MMIO_USBFS0_SLAVE_NR         2u

/* Protection regions */
typedef enum
{
    PROT_START                      =   0,
    PROT_PERI0_MAIN                 =   0,      /* Address 0x42000000, size 0x00004000 */
    PROT_PERI0_GR0_GROUP            =   1,      /* Address 0x42004010, size 0x00000008 */
    PROT_PERI0_GR1_GROUP            =   2,      /* Address 0x42004040, size 0x00000020 */
    PROT_PERI0_GR2_GROUP            =   3,      /* Address 0x42004080, size 0x00000020 */
    PROT_PERI0_GR3_GROUP            =   4,      /* Address 0x420040c0, size 0x00000020 */
    PROT_PERI0_GR4_GROUP            =   5,      /* Address 0x42004110, size 0x00000008 */
    PROT_PERI0_GR5_GROUP            =   6,      /* Address 0x42004140, size 0x00000020 */
    PROT_PERI0_GR0_BOOT             =   7,      /* Address 0x42004020, size 0x00000004 */
    PROT_PERI0_GR1_BOOT             =   8,      /* Address 0x42004060, size 0x00000004 */
    PROT_PERI0_GR2_BOOT             =   9,      /* Address 0x420040a0, size 0x00000004 */
    PROT_PERI0_GR3_BOOT             =  10,      /* Address 0x420040e0, size 0x00000004 */
    PROT_PERI0_GR4_BOOT             =  11,      /* Address 0x42004120, size 0x00000004 */
    PROT_PERI0_GR5_BOOT             =  12,      /* Address 0x42004160, size 0x00000004 */
    PROT_PERI0_TR                   =  13,      /* Address 0x42008000, size 0x00008000 */
    PROT_PPC0_PPC_PPC_SECURE        =  14,      /* Address 0x42020000, size 0x00004000 */
    PROT_PPC0_PPC_PPC_NONSECURE     =  15,      /* Address 0x42024000, size 0x00004000 */
    PROT_PERI_PCLK0_MAIN            =  16,      /* Address 0x42040000, size 0x00020000 */
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
    PROT_DW1_DW                     =  55,      /* Address 0x42190000, size 0x00000080 */
    PROT_DW0_DW_CRC                 =  56,      /* Address 0x42180100, size 0x00000080 */
    PROT_DW1_DW_CRC                 =  57,      /* Address 0x42190100, size 0x00000080 */
    PROT_DW0_CH_STRUCT0_CH          =  58,      /* Address 0x42188000, size 0x00000040 */
    PROT_DW0_CH_STRUCT1_CH          =  59,      /* Address 0x42188040, size 0x00000040 */
    PROT_DW0_CH_STRUCT2_CH          =  60,      /* Address 0x42188080, size 0x00000040 */
    PROT_DW0_CH_STRUCT3_CH          =  61,      /* Address 0x421880c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT4_CH          =  62,      /* Address 0x42188100, size 0x00000040 */
    PROT_DW0_CH_STRUCT5_CH          =  63,      /* Address 0x42188140, size 0x00000040 */
    PROT_DW0_CH_STRUCT6_CH          =  64,      /* Address 0x42188180, size 0x00000040 */
    PROT_DW0_CH_STRUCT7_CH          =  65,      /* Address 0x421881c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT8_CH          =  66,      /* Address 0x42188200, size 0x00000040 */
    PROT_DW0_CH_STRUCT9_CH          =  67,      /* Address 0x42188240, size 0x00000040 */
    PROT_DW0_CH_STRUCT10_CH         =  68,      /* Address 0x42188280, size 0x00000040 */
    PROT_DW0_CH_STRUCT11_CH         =  69,      /* Address 0x421882c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT12_CH         =  70,      /* Address 0x42188300, size 0x00000040 */
    PROT_DW0_CH_STRUCT13_CH         =  71,      /* Address 0x42188340, size 0x00000040 */
    PROT_DW0_CH_STRUCT14_CH         =  72,      /* Address 0x42188380, size 0x00000040 */
    PROT_DW0_CH_STRUCT15_CH         =  73,      /* Address 0x421883c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT0_CH          =  74,      /* Address 0x42198000, size 0x00000040 */
    PROT_DW1_CH_STRUCT1_CH          =  75,      /* Address 0x42198040, size 0x00000040 */
    PROT_DW1_CH_STRUCT2_CH          =  76,      /* Address 0x42198080, size 0x00000040 */
    PROT_DW1_CH_STRUCT3_CH          =  77,      /* Address 0x421980c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT4_CH          =  78,      /* Address 0x42198100, size 0x00000040 */
    PROT_DW1_CH_STRUCT5_CH          =  79,      /* Address 0x42198140, size 0x00000040 */
    PROT_DW1_CH_STRUCT6_CH          =  80,      /* Address 0x42198180, size 0x00000040 */
    PROT_DW1_CH_STRUCT7_CH          =  81,      /* Address 0x421981c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT8_CH          =  82,      /* Address 0x42198200, size 0x00000040 */
    PROT_DW1_CH_STRUCT9_CH          =  83,      /* Address 0x42198240, size 0x00000040 */
    PROT_DW1_CH_STRUCT10_CH         =  84,      /* Address 0x42198280, size 0x00000040 */
    PROT_DW1_CH_STRUCT11_CH         =  85,      /* Address 0x421982c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT12_CH         =  86,      /* Address 0x42198300, size 0x00000040 */
    PROT_DW1_CH_STRUCT13_CH         =  87,      /* Address 0x42198340, size 0x00000040 */
    PROT_DW1_CH_STRUCT14_CH         =  88,      /* Address 0x42198380, size 0x00000040 */
    PROT_DW1_CH_STRUCT15_CH         =  89,      /* Address 0x421983c0, size 0x00000040 */
    PROT_CPUSS_ALL_PC               =  90,      /* Address 0x421c0000, size 0x00000080 */
    PROT_CPUSS_DDFT                 =  91,      /* Address 0x421c0080, size 0x00000004 */
    PROT_CPUSS_CM33_S               =  92,      /* Address 0x421c0100, size 0x00000004 */
    PROT_CPUSS_CM33_NS              =  93,      /* Address 0x421c0120, size 0x00000004 */
    PROT_CPUSS_MSC_INT              =  94,      /* Address 0x421c0200, size 0x00000010 */
    PROT_CPUSS_AP                   =  95,      /* Address 0x421c1000, size 0x00000004 */
    PROT_CPUSS_BOOT                 =  96,      /* Address 0x421c2000, size 0x00000008 */
    PROT_MS0_MAIN                   =  97,      /* Address 0x421c4000, size 0x00000004 */
    PROT_MS4_MAIN                   =  98,      /* Address 0x421c4040, size 0x00000004 */
    PROT_MS5_MAIN                   =  99,      /* Address 0x421c4050, size 0x00000004 */
    PROT_MS7_MAIN                   = 100,      /* Address 0x421c4070, size 0x00000004 */
    PROT_MS31_MAIN                  = 101,      /* Address 0x421c41f0, size 0x00000004 */
    PROT_MS_PC0_PRIV                = 102,      /* Address 0x421c5000, size 0x00000004 */
    PROT_MS_PC31_PRIV               = 103,      /* Address 0x421c51f0, size 0x00000004 */
    PROT_MS_PC0_PRIV_MIR            = 104,      /* Address 0x421c5004, size 0x00000004 */
    PROT_MS_PC31_PRIV_MIR           = 105,      /* Address 0x421c51f4, size 0x00000004 */
    PROT_MSC_ACG                    = 106,      /* Address 0x421c6000, size 0x00000040 */
    PROT_CPUSS_SL_CTL_GROUP         = 107,      /* Address 0x421c8000, size 0x00000008 */
    PROT_IPC_STRUCT0_IPC            = 108,      /* Address 0x421d0000, size 0x00000020 */
    PROT_IPC_STRUCT1_IPC            = 109,      /* Address 0x421d0020, size 0x00000020 */
    PROT_IPC_STRUCT2_IPC            = 110,      /* Address 0x421d0040, size 0x00000020 */
    PROT_IPC_STRUCT3_IPC            = 111,      /* Address 0x421d0060, size 0x00000020 */
    PROT_IPC_INTR_STRUCT0_INTR      = 112,      /* Address 0x421d1000, size 0x00000010 */
    PROT_IPC_INTR_STRUCT1_INTR      = 113,      /* Address 0x421d1020, size 0x00000010 */
    PROT_FAULT_STRUCT0_MAIN         = 114,      /* Address 0x421e0000, size 0x00000100 */
    PROT_SRSS_GENERAL               = 115,      /* Address 0x42200000, size 0x00000400 */
    PROT_SRSS_GENERAL2              = 116,      /* Address 0x42200400, size 0x00000040 */
    PROT_SRSS_HIB_DATA              = 117,      /* Address 0x422008a0, size 0x00000010 */
    PROT_SRSS_MAIN                  = 118,      /* Address 0x42201000, size 0x00001000 */
    PROT_SRSS_SECURE                = 119,      /* Address 0x42202000, size 0x00002000 */
    PROT_RAM_TRIM_SRSS_SRAM         = 120,      /* Address 0x42204000, size 0x00000008 */
    PROT_SRSS_DPLL                  = 121,      /* Address 0x42204200, size 0x00000020 */
    PROT_SRSS_WDT                   = 122,      /* Address 0x4220c000, size 0x00000010 */
    PROT_MAIN                       = 123,      /* Address 0x4220d000, size 0x00000040 */
    PROT_PWRMODE_PWRMODE            = 124,      /* Address 0x42210000, size 0x00004000 */
    PROT_BACKUP_BACKUP              = 125,      /* Address 0x42220000, size 0x00000100 */
    PROT_BACKUP_B_BREG0             = 126,      /* Address 0x42221000, size 0x00000010 */
    PROT_BACKUP_B_BREG1             = 127,      /* Address 0x42221010, size 0x00000010 */
    PROT_BACKUP_B_BREG2             = 128,      /* Address 0x42221020, size 0x00000020 */
    PROT_BACKUP_B_BREG3             = 129,      /* Address 0x42221080, size 0x00000040 */
    PROT_BACKUP_BACKUP_SECURE       = 130,      /* Address 0x4222ff00, size 0x00000004 */
    PROT_CRYPTOLITE_MAIN            = 131,      /* Address 0x42230000, size 0x00000100 */
    PROT_CRYPTOLITE_TRNG            = 132,      /* Address 0x42230100, size 0x00000100 */
    PROT_MXCORDIC_1_1               = 133,      /* Address 0x42240000, size 0x00010000 */
    PROT_DEBUG600_DEBUG600          = 134,      /* Address 0x42250000, size 0x00000004 */
    PROT_SVGS_SVGS_MAIN             = 135,      /* Address 0x42260000, size 0x00000040 */
    PROT_SVGS_SVGS_AUX              = 136,      /* Address 0x42260040, size 0x00000040 */
    PROT_MXAES_MAIN1                = 137,      /* Address 0x42270000, size 0x00000800 */
    PROT_MXAES_BOOT1                = 138,      /* Address 0x42270800, size 0x00000800 */
    PROT_MXAES_MAIN2                = 139,      /* Address 0x42271000, size 0x00000800 */
    PROT_MXAES_BOOT2                = 140,      /* Address 0x42271800, size 0x00000800 */
    PROT_MXWOUND_MAIN               = 141,      /* Address 0x42280000, size 0x00000004 */
    PROT_MXWOUND_MXWOUND_PROP0_PROP = 142,      /* Address 0x42280100, size 0x00000004 */
    PROT_MXWOUND_MXWOUND_PROP1_PROP = 143,      /* Address 0x42280140, size 0x00000004 */
    PROT_HSIOM_PRT0_PRT             = 144,      /* Address 0x42400000, size 0x00000008 */
    PROT_HSIOM_PRT1_PRT             = 145,      /* Address 0x42400010, size 0x00000008 */
    PROT_HSIOM_PRT2_PRT             = 146,      /* Address 0x42400020, size 0x00000008 */
    PROT_HSIOM_PRT3_PRT             = 147,      /* Address 0x42400030, size 0x00000008 */
    PROT_HSIOM_PRT4_PRT             = 148,      /* Address 0x42400040, size 0x00000008 */
    PROT_HSIOM_PRT5_PRT             = 149,      /* Address 0x42400050, size 0x00000008 */
    PROT_HSIOM_PRT6_PRT             = 150,      /* Address 0x42400060, size 0x00000008 */
    PROT_HSIOM_PRT7_PRT             = 151,      /* Address 0x42400070, size 0x00000008 */
    PROT_HSIOM_PRT8_PRT             = 152,      /* Address 0x42400080, size 0x00000008 */
    PROT_HSIOM_PRT9_PRT             = 153,      /* Address 0x42400090, size 0x00000008 */
    PROT_HSIOM_PRT10_PRT            = 154,      /* Address 0x424000a0, size 0x00000008 */
    PROT_HSIOM_PRT11_PRT            = 155,      /* Address 0x424000b0, size 0x00000008 */
    PROT_HSIOM_PRT12_PRT            = 156,      /* Address 0x424000c0, size 0x00000008 */
    PROT_HSIOM_PRT13_PRT            = 157,      /* Address 0x424000d0, size 0x00000008 */
    PROT_HSIOM_SECURE_PRT0_SECURE_PRT = 158,    /* Address 0x42401000, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT1_SECURE_PRT = 159,    /* Address 0x42401010, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT2_SECURE_PRT = 160,    /* Address 0x42401020, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT3_SECURE_PRT = 161,    /* Address 0x42401030, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT4_SECURE_PRT = 162,    /* Address 0x42401040, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT5_SECURE_PRT = 163,    /* Address 0x42401050, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT6_SECURE_PRT = 164,    /* Address 0x42401060, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT7_SECURE_PRT = 165,    /* Address 0x42401070, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT8_SECURE_PRT = 166,    /* Address 0x42401080, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT9_SECURE_PRT = 167,    /* Address 0x42401090, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT10_SECURE_PRT = 168,   /* Address 0x424010a0, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT11_SECURE_PRT = 169,   /* Address 0x424010b0, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT12_SECURE_PRT = 170,   /* Address 0x424010c0, size 0x00000004 */
    PROT_HSIOM_SECURE_PRT13_SECURE_PRT = 171,   /* Address 0x424010d0, size 0x00000004 */
    PROT_HSIOM_AMUX                 = 172,      /* Address 0x42402000, size 0x00000020 */
    PROT_HSIOM_MON                  = 173,      /* Address 0x42402200, size 0x00000010 */
    PROT_GPIO_PRT0_PRT              = 174,      /* Address 0x42410000, size 0x00000040 */
    PROT_GPIO_PRT1_PRT              = 175,      /* Address 0x42410080, size 0x00000040 */
    PROT_GPIO_PRT2_PRT              = 176,      /* Address 0x42410100, size 0x00000040 */
    PROT_GPIO_PRT3_PRT              = 177,      /* Address 0x42410180, size 0x00000040 */
    PROT_GPIO_PRT4_PRT              = 178,      /* Address 0x42410200, size 0x00000040 */
    PROT_GPIO_PRT5_PRT              = 179,      /* Address 0x42410280, size 0x00000040 */
    PROT_GPIO_PRT6_PRT              = 180,      /* Address 0x42410300, size 0x00000040 */
    PROT_GPIO_PRT7_PRT              = 181,      /* Address 0x42410380, size 0x00000040 */
    PROT_GPIO_PRT8_PRT              = 182,      /* Address 0x42410400, size 0x00000040 */
    PROT_GPIO_PRT9_PRT              = 183,      /* Address 0x42410480, size 0x00000040 */
    PROT_GPIO_PRT10_PRT             = 184,      /* Address 0x42410500, size 0x00000040 */
    PROT_GPIO_PRT11_PRT             = 185,      /* Address 0x42410580, size 0x00000040 */
    PROT_GPIO_PRT12_PRT             = 186,      /* Address 0x42410600, size 0x00000040 */
    PROT_GPIO_PRT13_PRT             = 187,      /* Address 0x42410680, size 0x00000040 */
    PROT_GPIO_PRT0_CFG              = 188,      /* Address 0x42410040, size 0x00000040 */
    PROT_GPIO_PRT1_CFG              = 189,      /* Address 0x424100c0, size 0x00000040 */
    PROT_GPIO_PRT2_CFG              = 190,      /* Address 0x42410140, size 0x00000040 */
    PROT_GPIO_PRT3_CFG              = 191,      /* Address 0x424101c0, size 0x00000040 */
    PROT_GPIO_PRT4_CFG              = 192,      /* Address 0x42410240, size 0x00000040 */
    PROT_GPIO_PRT5_CFG              = 193,      /* Address 0x424102c0, size 0x00000040 */
    PROT_GPIO_PRT6_CFG              = 194,      /* Address 0x42410340, size 0x00000040 */
    PROT_GPIO_PRT7_CFG              = 195,      /* Address 0x424103c0, size 0x00000040 */
    PROT_GPIO_PRT8_CFG              = 196,      /* Address 0x42410440, size 0x00000040 */
    PROT_GPIO_PRT9_CFG              = 197,      /* Address 0x424104c0, size 0x00000040 */
    PROT_GPIO_PRT10_CFG             = 198,      /* Address 0x42410540, size 0x00000040 */
    PROT_GPIO_PRT11_CFG             = 199,      /* Address 0x424105c0, size 0x00000040 */
    PROT_GPIO_PRT12_CFG             = 200,      /* Address 0x42410640, size 0x00000040 */
    PROT_GPIO_PRT13_CFG             = 201,      /* Address 0x424106c0, size 0x00000040 */
    PROT_GPIO_SEC_GPIO              = 202,      /* Address 0x42417000, size 0x00000004 */
    PROT_GPIO_GPIO                  = 203,      /* Address 0x42418000, size 0x00000040 */
    PROT_GPIO_TEST                  = 204,      /* Address 0x42419000, size 0x00000008 */
    PROT_SMARTIO_PRT0_PRT           = 205,      /* Address 0x42420000, size 0x00000100 */
    PROT_SMARTIO_PRT1_PRT           = 206,      /* Address 0x42420100, size 0x00000100 */
    PROT_SMARTIO_PRT2_PRT           = 207,      /* Address 0x42420200, size 0x00000100 */
    PROT_SMARTIO_PRT3_PRT           = 208,      /* Address 0x42420300, size 0x00000100 */
    PROT_SMARTIO_PRT5_PRT           = 209,      /* Address 0x42420500, size 0x00000100 */
    PROT_SMARTIO_PRT6_PRT           = 210,      /* Address 0x42420600, size 0x00000100 */
    PROT_SMARTIO_PRT9_PRT           = 211,      /* Address 0x42420900, size 0x00000100 */
    PROT_LPCOMP                     = 212,      /* Address 0x42430000, size 0x00010000 */
    PROT_DFT                        = 213,      /* Address 0x42600000, size 0x00001000 */
    PROT_EFUSE_CTL1                 = 214,      /* Address 0x42610000, size 0x00000004 */
    PROT_EFUSE_CTL2                 = 215,      /* Address 0x42610100, size 0x00000080 */
    PROT_EFUSE_CTL3                 = 216,      /* Address 0x42610180, size 0x00000004 */
    PROT_EFUSE_DATA_BOOT1           = 217,      /* Address 0x42610800, size 0x00000080 */
    PROT_CANFD0_CH0_CH              = 218,      /* Address 0x42800000, size 0x00000200 */
    PROT_CANFD0_CH1_CH              = 219,      /* Address 0x42800200, size 0x00000200 */
    PROT_CANFD0_MAIN                = 220,      /* Address 0x42801000, size 0x00000040 */
    PROT_CANFD0_BUF                 = 221,      /* Address 0x42810000, size 0x00010000 */
    PROT_SCB0                       = 222,      /* Address 0x42820000, size 0x00010000 */
    PROT_SCB1                       = 223,      /* Address 0x42840000, size 0x00010000 */
    PROT_SCB2                       = 224,      /* Address 0x42850000, size 0x00010000 */
    PROT_SCB3                       = 225,      /* Address 0x42860000, size 0x00010000 */
    PROT_SCB4                       = 226,      /* Address 0x42870000, size 0x00010000 */
    PROT_SCB5                       = 227,      /* Address 0x42c00000, size 0x00010000 */
    PROT_TCPWM0_GRP0_CNT0_CNT       = 228,      /* Address 0x42a00000, size 0x00000100 */
    PROT_TCPWM0_GRP0_CNT1_CNT       = 229,      /* Address 0x42a00100, size 0x00000100 */
    PROT_TCPWM0_GRP0_CNT2_CNT       = 230,      /* Address 0x42a00200, size 0x00000100 */
    PROT_TCPWM0_GRP0_CNT3_CNT       = 231,      /* Address 0x42a00300, size 0x00000100 */
    PROT_TCPWM0_GRP0_CNT4_CNT       = 232,      /* Address 0x42a00400, size 0x00000100 */
    PROT_TCPWM0_GRP0_CNT5_CNT       = 233,      /* Address 0x42a00500, size 0x00000100 */
    PROT_TCPWM0_GRP0_CNT6_CNT       = 234,      /* Address 0x42a00600, size 0x00000100 */
    PROT_TCPWM0_GRP0_CNT7_CNT       = 235,      /* Address 0x42a00700, size 0x00000100 */
    PROT_TCPWM0_GRP1_CNT0_CNT       = 236,      /* Address 0x42a10000, size 0x00000100 */
    PROT_TCPWM0_GRP1_CNT1_CNT       = 237,      /* Address 0x42a10100, size 0x00000100 */
    PROT_TCPWM0_GRP1_CNT2_CNT       = 238,      /* Address 0x42a10200, size 0x00000100 */
    PROT_TCPWM0_GRP1_CNT3_CNT       = 239,      /* Address 0x42a10300, size 0x00000100 */
    PROT_TCPWM0_GRP1_CNT4_CNT       = 240,      /* Address 0x42a10400, size 0x00000100 */
    PROT_TCPWM0_GRP1_CNT5_CNT       = 241,      /* Address 0x42a10500, size 0x00000100 */
    PROT_TCPWM0_GRP1_CNT6_CNT       = 242,      /* Address 0x42a10600, size 0x00000100 */
    PROT_TCPWM0_GRP1_CNT7_CNT       = 243,      /* Address 0x42a10700, size 0x00000100 */
    PROT_TCPWM0_GRP2_CNT0_CNT       = 244,      /* Address 0x42a20000, size 0x00000100 */
    PROT_TCPWM0_GRP2_CNT1_CNT       = 245,      /* Address 0x42a20100, size 0x00000100 */
    PROT_TCPWM0_GRP2_CNT2_CNT       = 246,      /* Address 0x42a20200, size 0x00000100 */
    PROT_TCPWM0_GRP2_CNT3_CNT       = 247,      /* Address 0x42a20300, size 0x00000100 */
    PROT_TCPWM0_GRP2_CNT4_CNT       = 248,      /* Address 0x42a20400, size 0x00000100 */
    PROT_TCPWM0_GRP2_CNT5_CNT       = 249,      /* Address 0x42a20500, size 0x00000100 */
    PROT_TCPWM0_GRP2_CNT6_CNT       = 250,      /* Address 0x42a20600, size 0x00000100 */
    PROT_TCPWM0_GRP2_CNT7_CNT       = 251,      /* Address 0x42a20700, size 0x00000100 */
    PROT_TCPWM0_TR_ALL_GF_TR_ALL_GF = 252,      /* Address 0x42a80000, size 0x00000080 */
    PROT_TCPWM0_TR_ALL_SYNC_BYPASS_TR_ALL_SYN_BYPASS = 253, /* Address 0x42a90000, size 0x00000004 */
    PROT_TCPWM0_MOTIF_GRP1_MOTIF0_MOTIF = 254,  /* Address 0x42aa4000, size 0x00000200 */
    PROT_TCPWM0_MOTIF_GRP2_MOTIF0_MOTIF = 255,  /* Address 0x42aa8000, size 0x00000200 */
    PROT_MCPASS_AFE                 = 256,      /* Address 0x42b60000, size 0x00010000 */
    PROT_MCPASS_SARADC              = 257,      /* Address 0x42b70000, size 0x00010000 */
    PROT_MCPASS_SAR                 = 258,      /* Address 0x42b80000, size 0x00010000 */
    PROT_MCPASS_DAC_BUFFER          = 259,      /* Address 0x42b90000, size 0x00010000 */
    PROT_MCPASS_HWFILT3P3Z          = 260,      /* Address 0x42ba0000, size 0x00001000 */
    PROT_MCPASS_CSG                 = 261,      /* Address 0x42bb0000, size 0x00010000 */
    PROT_MCPASS_ACTRLR              = 262,      /* Address 0x42bd0000, size 0x00010000 */
    PROT_MCPASS_INFRA               = 263,      /* Address 0x42be0000, size 0x00010000 */
    PROT_MCPASS_MMIO                = 264,      /* Address 0x42bf0000, size 0x00010000 */
    PROT_I3C0                       = 265,      /* Address 0x42c10000, size 0x00010000 */
    PROT_USBFS0                     = 266,      /* Address 0x42c20000, size 0x00010000 */
    PROT_END                        = 266
} cy_en_prot_region_t;

#endif /* _PSC3M6_CONFIG_H_ */


/* [] END OF FILE */
