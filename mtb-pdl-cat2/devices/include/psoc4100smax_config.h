/***************************************************************************//**
* \file psoc4100smax_config.h
*
* \brief
* PSOC4100Smax device configuration header
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

#ifndef _PSOC4100SMAX_CONFIG_H_
#define _PSOC4100SMAX_CONFIG_H_

/* Clock Connections */
typedef enum
{
    PCLK_SCB0_CLOCK                 = 0x0000u,  /* scb[0].clock */
    PCLK_SCB1_CLOCK                 = 0x0001u,  /* scb[1].clock */
    PCLK_SCB2_CLOCK                 = 0x0002u,  /* scb[2].clock */
    PCLK_SCB3_CLOCK                 = 0x0003u,  /* scb[3].clock */
    PCLK_SCB4_CLOCK                 = 0x0004u,  /* scb[4].clock */
    PCLK_MSC0_CLOCK_MSC             = 0x0005u,  /* msc[0].clock_msc */
    PCLK_TCPWM_CLOCKS0              = 0x0006u,  /* tcpwm.clocks[0] */
    PCLK_TCPWM_CLOCKS1              = 0x0007u,  /* tcpwm.clocks[1] */
    PCLK_TCPWM_CLOCKS2              = 0x0008u,  /* tcpwm.clocks[2] */
    PCLK_TCPWM_CLOCKS3              = 0x0009u,  /* tcpwm.clocks[3] */
    PCLK_TCPWM_CLOCKS4              = 0x000Au,  /* tcpwm.clocks[4] */
    PCLK_TCPWM_CLOCKS5              = 0x000Bu,  /* tcpwm.clocks[5] */
    PCLK_TCPWM_CLOCKS6              = 0x000Cu,  /* tcpwm.clocks[6] */
    PCLK_TCPWM_CLOCKS7              = 0x000Du,  /* tcpwm.clocks[7] */
    PCLK_PRGIO_CLOCK_PRGIO_1        = 0x000Eu,  /* prgio.clock_prgio_1 */
    PCLK_PRGIO_CLOCK_PRGIO_2        = 0x000Fu,  /* prgio.clock_prgio_2 */
    PCLK_PRGIO_CLOCK_PRGIO_3        = 0x0010u,  /* prgio.clock_prgio_3 */
    PCLK_LCD_CLOCK                  = 0x0011u,  /* lcd.clock */
    PCLK_PASS0_CLOCK_SAR            = 0x0012u,  /* pass[0].clock_sar */
    PCLK_MSC1_CLOCK_MSC             = 0x0013u,  /* msc[1].clock_msc */
    PCLK_CANFD_CLOCK_CAN0           = 0x0014u,  /* canfd.clock_can[0] */
    PCLK_MSC0_CLOCK_SYNC            = 0x0015u,  /* msc[0].clock_sync */
    PCLK_MSC1_CLOCK_SYNC            = 0x0016u,  /* msc[1].clock_sync */
    PCLK_AUDIOSS_CLOCK_POS_I2S_EN   = 0x0017u   /* audioss.clock_pos_i2s_en */
} en_clk_dst_t;

/* Trigger Group */
/* This section contains the enums related to the Trigger multiplexer (TrigMux) driver.
* Refer to the Cypress Peripheral Driver Library Documentation, section Trigger multiplexer (TrigMux) -> Enumerated Types for details.
*/
/* Trigger Group Inputs */
/* Trigger Input Group 0 - DMA Request Assignments */
typedef enum
{
    TRIG0_IN_CPUSS_ZERO             = 0x00000000u, /* cpuss.zero */
    TRIG0_IN_TCPWM_TR_OVERFLOW0     = 0x00000001u, /* tcpwm.tr_overflow[0] */
    TRIG0_IN_TCPWM_TR_OVERFLOW1     = 0x00000002u, /* tcpwm.tr_overflow[1] */
    TRIG0_IN_TCPWM_TR_OVERFLOW2     = 0x00000003u, /* tcpwm.tr_overflow[2] */
    TRIG0_IN_TCPWM_TR_OVERFLOW3     = 0x00000004u, /* tcpwm.tr_overflow[3] */
    TRIG0_IN_TCPWM_TR_OVERFLOW4     = 0x00000005u, /* tcpwm.tr_overflow[4] */
    TRIG0_IN_TCPWM_TR_OVERFLOW5     = 0x00000006u, /* tcpwm.tr_overflow[5] */
    TRIG0_IN_TCPWM_TR_OVERFLOW6     = 0x00000007u, /* tcpwm.tr_overflow[6] */
    TRIG0_IN_TCPWM_TR_OVERFLOW7     = 0x00000008u, /* tcpwm.tr_overflow[7] */
    TRIG0_IN_TCPWM_TR_COMPARE_MATCH0 = 0x00000009u, /* tcpwm.tr_compare_match[0] */
    TRIG0_IN_TCPWM_TR_COMPARE_MATCH1 = 0x0000000Au, /* tcpwm.tr_compare_match[1] */
    TRIG0_IN_TCPWM_TR_COMPARE_MATCH2 = 0x0000000Bu, /* tcpwm.tr_compare_match[2] */
    TRIG0_IN_TCPWM_TR_COMPARE_MATCH3 = 0x0000000Cu, /* tcpwm.tr_compare_match[3] */
    TRIG0_IN_TCPWM_TR_COMPARE_MATCH4 = 0x0000000Du, /* tcpwm.tr_compare_match[4] */
    TRIG0_IN_TCPWM_TR_COMPARE_MATCH5 = 0x0000000Eu, /* tcpwm.tr_compare_match[5] */
    TRIG0_IN_TCPWM_TR_COMPARE_MATCH6 = 0x0000000Fu, /* tcpwm.tr_compare_match[6] */
    TRIG0_IN_TCPWM_TR_COMPARE_MATCH7 = 0x00000010u, /* tcpwm.tr_compare_match[7] */
    TRIG0_IN_TCPWM_TR_UNDERFLOW0    = 0x00000011u, /* tcpwm.tr_underflow[0] */
    TRIG0_IN_TCPWM_TR_UNDERFLOW1    = 0x00000012u, /* tcpwm.tr_underflow[1] */
    TRIG0_IN_TCPWM_TR_UNDERFLOW2    = 0x00000013u, /* tcpwm.tr_underflow[2] */
    TRIG0_IN_TCPWM_TR_UNDERFLOW3    = 0x00000014u, /* tcpwm.tr_underflow[3] */
    TRIG0_IN_TCPWM_TR_UNDERFLOW4    = 0x00000015u, /* tcpwm.tr_underflow[4] */
    TRIG0_IN_TCPWM_TR_UNDERFLOW5    = 0x00000016u, /* tcpwm.tr_underflow[5] */
    TRIG0_IN_TCPWM_TR_UNDERFLOW6    = 0x00000017u, /* tcpwm.tr_underflow[6] */
    TRIG0_IN_TCPWM_TR_UNDERFLOW7    = 0x00000018u, /* tcpwm.tr_underflow[7] */
    TRIG0_IN_SCB0_TR_TX_REQ         = 0x00000019u, /* scb[0].tr_tx_req */
    TRIG0_IN_SCB0_TR_RX_REQ         = 0x0000001Au, /* scb[0].tr_rx_req */
    TRIG0_IN_SCB1_TR_TX_REQ         = 0x0000001Bu, /* scb[1].tr_tx_req */
    TRIG0_IN_SCB1_TR_RX_REQ         = 0x0000001Cu, /* scb[1].tr_rx_req */
    TRIG0_IN_SCB2_TR_TX_REQ         = 0x0000001Du, /* scb[2].tr_tx_req */
    TRIG0_IN_SCB2_TR_RX_REQ         = 0x0000001Eu, /* scb[2].tr_rx_req */
    TRIG0_IN_SCB3_TR_TX_REQ         = 0x0000001Fu, /* scb[3].tr_tx_req */
    TRIG0_IN_SCB3_TR_RX_REQ         = 0x00000020u, /* scb[3].tr_rx_req */
    TRIG0_IN_SCB4_TR_TX_REQ         = 0x00000021u, /* scb[4].tr_tx_req */
    TRIG0_IN_SCB4_TR_RX_REQ         = 0x00000022u, /* scb[4].tr_rx_req */
    TRIG0_IN_EXCO_TRIGGER           = 0x00000023u, /* exco.trigger */
    TRIG0_IN_CPUSS_DMAC_TR_OUT0     = 0x00000024u, /* cpuss.dmac_tr_out[0] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT1     = 0x00000025u, /* cpuss.dmac_tr_out[1] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT2     = 0x00000026u, /* cpuss.dmac_tr_out[2] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT3     = 0x00000027u, /* cpuss.dmac_tr_out[3] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT4     = 0x00000028u, /* cpuss.dmac_tr_out[4] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT5     = 0x00000029u, /* cpuss.dmac_tr_out[5] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT6     = 0x0000002Au, /* cpuss.dmac_tr_out[6] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT7     = 0x0000002Bu, /* cpuss.dmac_tr_out[7] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT8     = 0x0000002Cu, /* cpuss.dmac_tr_out[8] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT9     = 0x0000002Du, /* cpuss.dmac_tr_out[9] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT10    = 0x0000002Eu, /* cpuss.dmac_tr_out[10] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT11    = 0x0000002Fu, /* cpuss.dmac_tr_out[11] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT12    = 0x00000030u, /* cpuss.dmac_tr_out[12] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT13    = 0x00000031u, /* cpuss.dmac_tr_out[13] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT14    = 0x00000032u, /* cpuss.dmac_tr_out[14] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT15    = 0x00000033u, /* cpuss.dmac_tr_out[15] */
    TRIG0_IN_PASS0_DSI_SAR_SAMPLE_DONE = 0x00000034u, /* pass[0].dsi_sar_sample_done */
    TRIG0_IN_PASS0_TR_SAR_OUT       = 0x00000035u, /* pass[0].tr_sar_out */
    TRIG0_IN_MSC0_TR_WR_REQ_OUT     = 0x00000036u, /* msc[0].tr_wr_req_out */
    TRIG0_IN_MSC0_TR_RD_REQ_OUT     = 0x00000037u, /* msc[0].tr_rd_req_out */
    TRIG0_IN_MSC1_TR_WR_REQ_OUT     = 0x00000038u, /* msc[1].tr_wr_req_out */
    TRIG0_IN_MSC1_TR_RD_REQ_OUT     = 0x00000039u, /* msc[1].tr_rd_req_out */
    TRIG0_IN_PASS0_DSI_CTB_CMP0     = 0x0000003Au, /* pass[0].dsi_ctb_cmp0 */
    TRIG0_IN_PASS0_DSI_CTB_CMP1     = 0x0000003Bu, /* pass[0].dsi_ctb_cmp1 */
    TRIG0_IN_LPCOMP_COMP_OUT0       = 0x0000003Cu, /* lpcomp.comp_out[0] */
    TRIG0_IN_LPCOMP_COMP_OUT1       = 0x0000003Du, /* lpcomp.comp_out[1] */
    TRIG0_IN_CANFD_TR_FIFO00        = 0x0000003Eu, /* canfd.tr_fifo0[0] */
    TRIG0_IN_CANFD_TR_FIFO10        = 0x0000003Fu, /* canfd.tr_fifo1[0] */
    TRIG0_IN_CANFD_TR_TMP_RTP_OUT0  = 0x00000040u, /* canfd.tr_tmp_rtp_out[0] */
    TRIG0_IN_CANFD_TR_DBG_DMA_REQ0  = 0x00000041u /* canfd.tr_dbg_dma_req[0] */
} en_trig_input_grp0_t;

/* Trigger Input Group 1 - Trigger sources for TCPWM */
typedef enum
{
    TRIG1_IN_CPUSS_ZERO             = 0x00000100u, /* cpuss.zero */
    TRIG1_IN_TCPWM_TR_OVERFLOW0     = 0x00000101u, /* tcpwm.tr_overflow[0] */
    TRIG1_IN_TCPWM_TR_OVERFLOW1     = 0x00000102u, /* tcpwm.tr_overflow[1] */
    TRIG1_IN_TCPWM_TR_OVERFLOW2     = 0x00000103u, /* tcpwm.tr_overflow[2] */
    TRIG1_IN_TCPWM_TR_OVERFLOW3     = 0x00000104u, /* tcpwm.tr_overflow[3] */
    TRIG1_IN_TCPWM_TR_OVERFLOW4     = 0x00000105u, /* tcpwm.tr_overflow[4] */
    TRIG1_IN_TCPWM_TR_OVERFLOW5     = 0x00000106u, /* tcpwm.tr_overflow[5] */
    TRIG1_IN_TCPWM_TR_OVERFLOW6     = 0x00000107u, /* tcpwm.tr_overflow[6] */
    TRIG1_IN_TCPWM_TR_OVERFLOW7     = 0x00000108u, /* tcpwm.tr_overflow[7] */
    TRIG1_IN_TCPWM_TR_COMPARE_MATCH0 = 0x00000109u, /* tcpwm.tr_compare_match[0] */
    TRIG1_IN_TCPWM_TR_COMPARE_MATCH1 = 0x0000010Au, /* tcpwm.tr_compare_match[1] */
    TRIG1_IN_TCPWM_TR_COMPARE_MATCH2 = 0x0000010Bu, /* tcpwm.tr_compare_match[2] */
    TRIG1_IN_TCPWM_TR_COMPARE_MATCH3 = 0x0000010Cu, /* tcpwm.tr_compare_match[3] */
    TRIG1_IN_TCPWM_TR_COMPARE_MATCH4 = 0x0000010Du, /* tcpwm.tr_compare_match[4] */
    TRIG1_IN_TCPWM_TR_COMPARE_MATCH5 = 0x0000010Eu, /* tcpwm.tr_compare_match[5] */
    TRIG1_IN_TCPWM_TR_COMPARE_MATCH6 = 0x0000010Fu, /* tcpwm.tr_compare_match[6] */
    TRIG1_IN_TCPWM_TR_COMPARE_MATCH7 = 0x00000110u, /* tcpwm.tr_compare_match[7] */
    TRIG1_IN_TCPWM_TR_UNDERFLOW0    = 0x00000111u, /* tcpwm.tr_underflow[0] */
    TRIG1_IN_TCPWM_TR_UNDERFLOW1    = 0x00000112u, /* tcpwm.tr_underflow[1] */
    TRIG1_IN_TCPWM_TR_UNDERFLOW2    = 0x00000113u, /* tcpwm.tr_underflow[2] */
    TRIG1_IN_TCPWM_TR_UNDERFLOW3    = 0x00000114u, /* tcpwm.tr_underflow[3] */
    TRIG1_IN_TCPWM_TR_UNDERFLOW4    = 0x00000115u, /* tcpwm.tr_underflow[4] */
    TRIG1_IN_TCPWM_TR_UNDERFLOW5    = 0x00000116u, /* tcpwm.tr_underflow[5] */
    TRIG1_IN_TCPWM_TR_UNDERFLOW6    = 0x00000117u, /* tcpwm.tr_underflow[6] */
    TRIG1_IN_TCPWM_TR_UNDERFLOW7    = 0x00000118u, /* tcpwm.tr_underflow[7] */
    TRIG1_IN_PASS0_DSI_SAR_SAMPLE_DONE = 0x00000119u, /* pass[0].dsi_sar_sample_done */
    TRIG1_IN_PASS0_TR_SAR_OUT       = 0x0000011Au, /* pass[0].tr_sar_out */
    TRIG1_IN_PASS0_DSI_CTB_CMP0     = 0x0000011Bu, /* pass[0].dsi_ctb_cmp0 */
    TRIG1_IN_PASS0_DSI_CTB_CMP1     = 0x0000011Cu, /* pass[0].dsi_ctb_cmp1 */
    TRIG1_IN_LPCOMP_COMP_OUT0       = 0x0000011Du, /* lpcomp.comp_out[0] */
    TRIG1_IN_LPCOMP_COMP_OUT1       = 0x0000011Eu, /* lpcomp.comp_out[1] */
    TRIG1_IN_EXCO_TRIGGER           = 0x0000011Fu, /* exco.trigger */
    TRIG1_IN_SCB0_TR_I2C_SCL_FILTERED = 0x00000120u, /* scb[0].tr_i2c_scl_filtered */
    TRIG1_IN_SCB1_TR_I2C_SCL_FILTERED = 0x00000121u, /* scb[1].tr_i2c_scl_filtered */
    TRIG1_IN_SCB2_TR_I2C_SCL_FILTERED = 0x00000122u, /* scb[2].tr_i2c_scl_filtered */
    TRIG1_IN_SCB3_TR_I2C_SCL_FILTERED = 0x00000123u, /* scb[3].tr_i2c_scl_filtered */
    TRIG1_IN_SCB4_TR_I2C_SCL_FILTERED = 0x00000124u /* scb[4].tr_i2c_scl_filtered */
} en_trig_input_grp1_t;

/* Trigger Input Group 2 - Trigger sources for PASS */
typedef enum
{
    TRIG2_IN_CPUSS_ZERO             = 0x00000200u, /* cpuss.zero */
    TRIG2_IN_TCPWM_TR_OVERFLOW0     = 0x00000201u, /* tcpwm.tr_overflow[0] */
    TRIG2_IN_TCPWM_TR_OVERFLOW1     = 0x00000202u, /* tcpwm.tr_overflow[1] */
    TRIG2_IN_TCPWM_TR_OVERFLOW2     = 0x00000203u, /* tcpwm.tr_overflow[2] */
    TRIG2_IN_TCPWM_TR_OVERFLOW3     = 0x00000204u, /* tcpwm.tr_overflow[3] */
    TRIG2_IN_TCPWM_TR_OVERFLOW4     = 0x00000205u, /* tcpwm.tr_overflow[4] */
    TRIG2_IN_TCPWM_TR_OVERFLOW5     = 0x00000206u, /* tcpwm.tr_overflow[5] */
    TRIG2_IN_TCPWM_TR_OVERFLOW6     = 0x00000207u, /* tcpwm.tr_overflow[6] */
    TRIG2_IN_TCPWM_TR_OVERFLOW7     = 0x00000208u, /* tcpwm.tr_overflow[7] */
    TRIG2_IN_TCPWM_TR_COMPARE_MATCH0 = 0x00000209u, /* tcpwm.tr_compare_match[0] */
    TRIG2_IN_TCPWM_TR_COMPARE_MATCH1 = 0x0000020Au, /* tcpwm.tr_compare_match[1] */
    TRIG2_IN_TCPWM_TR_COMPARE_MATCH2 = 0x0000020Bu, /* tcpwm.tr_compare_match[2] */
    TRIG2_IN_TCPWM_TR_COMPARE_MATCH3 = 0x0000020Cu, /* tcpwm.tr_compare_match[3] */
    TRIG2_IN_TCPWM_TR_COMPARE_MATCH4 = 0x0000020Du, /* tcpwm.tr_compare_match[4] */
    TRIG2_IN_TCPWM_TR_COMPARE_MATCH5 = 0x0000020Eu, /* tcpwm.tr_compare_match[5] */
    TRIG2_IN_TCPWM_TR_COMPARE_MATCH6 = 0x0000020Fu, /* tcpwm.tr_compare_match[6] */
    TRIG2_IN_TCPWM_TR_COMPARE_MATCH7 = 0x00000210u, /* tcpwm.tr_compare_match[7] */
    TRIG2_IN_TCPWM_TR_UNDERFLOW0    = 0x00000211u, /* tcpwm.tr_underflow[0] */
    TRIG2_IN_TCPWM_TR_UNDERFLOW1    = 0x00000212u, /* tcpwm.tr_underflow[1] */
    TRIG2_IN_TCPWM_TR_UNDERFLOW2    = 0x00000213u, /* tcpwm.tr_underflow[2] */
    TRIG2_IN_TCPWM_TR_UNDERFLOW3    = 0x00000214u, /* tcpwm.tr_underflow[3] */
    TRIG2_IN_TCPWM_TR_UNDERFLOW4    = 0x00000215u, /* tcpwm.tr_underflow[4] */
    TRIG2_IN_TCPWM_TR_UNDERFLOW5    = 0x00000216u, /* tcpwm.tr_underflow[5] */
    TRIG2_IN_TCPWM_TR_UNDERFLOW6    = 0x00000217u, /* tcpwm.tr_underflow[6] */
    TRIG2_IN_TCPWM_TR_UNDERFLOW7    = 0x00000218u, /* tcpwm.tr_underflow[7] */
    TRIG2_IN_TCPWM_LINE0            = 0x00000219u, /* tcpwm.line[0] */
    TRIG2_IN_TCPWM_LINE1            = 0x0000021Au, /* tcpwm.line[1] */
    TRIG2_IN_TCPWM_LINE2            = 0x0000021Bu, /* tcpwm.line[2] */
    TRIG2_IN_TCPWM_LINE3            = 0x0000021Cu, /* tcpwm.line[3] */
    TRIG2_IN_TCPWM_LINE4            = 0x0000021Du, /* tcpwm.line[4] */
    TRIG2_IN_TCPWM_LINE5            = 0x0000021Eu, /* tcpwm.line[5] */
    TRIG2_IN_TCPWM_LINE6            = 0x0000021Fu, /* tcpwm.line[6] */
    TRIG2_IN_TCPWM_LINE7            = 0x00000220u, /* tcpwm.line[7] */
    TRIG2_IN_PASS0_DSI_SAR_SAMPLE_DONE = 0x00000221u, /* pass[0].dsi_sar_sample_done */
    TRIG2_IN_PASS0_TR_SAR_OUT       = 0x00000222u, /* pass[0].tr_sar_out */
    TRIG2_IN_PASS0_DSI_CTB_CMP0     = 0x00000223u, /* pass[0].dsi_ctb_cmp0 */
    TRIG2_IN_PASS0_DSI_CTB_CMP1     = 0x00000224u, /* pass[0].dsi_ctb_cmp1 */
    TRIG2_IN_LPCOMP_COMP_OUT0       = 0x00000225u, /* lpcomp.comp_out[0] */
    TRIG2_IN_LPCOMP_COMP_OUT1       = 0x00000226u /* lpcomp.comp_out[1] */
} en_trig_input_grp2_t;

/* Trigger Input Group 3 - Trigger sources for CSD */
typedef enum
{
    TRIG3_IN_CPUSS_ZERO             = 0x00000300u, /* cpuss.zero */
    TRIG3_IN_CPUSS_DMAC_TR_OUT0     = 0x00000301u, /* cpuss.dmac_tr_out[0] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT1     = 0x00000302u, /* cpuss.dmac_tr_out[1] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT2     = 0x00000303u, /* cpuss.dmac_tr_out[2] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT3     = 0x00000304u, /* cpuss.dmac_tr_out[3] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT4     = 0x00000305u, /* cpuss.dmac_tr_out[4] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT5     = 0x00000306u, /* cpuss.dmac_tr_out[5] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT6     = 0x00000307u, /* cpuss.dmac_tr_out[6] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT7     = 0x00000308u, /* cpuss.dmac_tr_out[7] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT8     = 0x00000309u, /* cpuss.dmac_tr_out[8] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT9     = 0x0000030Au, /* cpuss.dmac_tr_out[9] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT10    = 0x0000030Bu, /* cpuss.dmac_tr_out[10] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT11    = 0x0000030Cu, /* cpuss.dmac_tr_out[11] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT12    = 0x0000030Du, /* cpuss.dmac_tr_out[12] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT13    = 0x0000030Eu, /* cpuss.dmac_tr_out[13] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT14    = 0x0000030Fu, /* cpuss.dmac_tr_out[14] */
    TRIG3_IN_CPUSS_DMAC_TR_OUT15    = 0x00000310u /* cpuss.dmac_tr_out[15] */
} en_trig_input_grp3_t;

/* Trigger Group Outputs */
/* Trigger Output Group 0 - DMA Request Assignments */
typedef enum
{
    TRIG0_OUT_CPUSS_DMAC_TR_IN0     = 0x40000000u, /* cpuss.dmac_tr_in[0] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN1     = 0x40000001u, /* cpuss.dmac_tr_in[1] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN2     = 0x40000002u, /* cpuss.dmac_tr_in[2] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN3     = 0x40000003u, /* cpuss.dmac_tr_in[3] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN4     = 0x40000004u, /* cpuss.dmac_tr_in[4] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN5     = 0x40000005u, /* cpuss.dmac_tr_in[5] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN6     = 0x40000006u, /* cpuss.dmac_tr_in[6] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN7     = 0x40000007u, /* cpuss.dmac_tr_in[7] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN8     = 0x40000008u, /* cpuss.dmac_tr_in[8] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN9     = 0x40000009u, /* cpuss.dmac_tr_in[9] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN10    = 0x4000000Au, /* cpuss.dmac_tr_in[10] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN11    = 0x4000000Bu, /* cpuss.dmac_tr_in[11] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN12    = 0x4000000Cu, /* cpuss.dmac_tr_in[12] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN13    = 0x4000000Du, /* cpuss.dmac_tr_in[13] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN14    = 0x4000000Eu, /* cpuss.dmac_tr_in[14] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN15    = 0x4000000Fu, /* cpuss.dmac_tr_in[15] */
    TRIG0_OUT_CANFD_TR_EVT_SWT_IN0  = 0x40000010u, /* canfd.tr_evt_swt_in[0] */
    TRIG0_OUT_CANFD_TR_DBG_DMA_ACK0 = 0x40000011u /* canfd.tr_dbg_dma_ack[0] */
} en_trig_output_grp0_t;

/* Trigger Output Group 1 - Trigger sources for TCPWM */
typedef enum
{
    TRIG1_OUT_TCPWM_TR_IN7          = 0x40000100u, /* tcpwm.tr_in[7] */
    TRIG1_OUT_TCPWM_TR_IN8          = 0x40000101u, /* tcpwm.tr_in[8] */
    TRIG1_OUT_TCPWM_TR_IN9          = 0x40000102u, /* tcpwm.tr_in[9] */
    TRIG1_OUT_TCPWM_TR_IN10         = 0x40000103u, /* tcpwm.tr_in[10] */
    TRIG1_OUT_TCPWM_TR_IN11         = 0x40000104u, /* tcpwm.tr_in[11] */
    TRIG1_OUT_TCPWM_TR_IN12         = 0x40000105u, /* tcpwm.tr_in[12] */
    TRIG1_OUT_TCPWM_TR_IN13         = 0x40000106u /* tcpwm.tr_in[13] */
} en_trig_output_grp1_t;

/* Trigger Output Group 2 - Trigger sources for PASS */
typedef enum
{
    TRIG2_OUT_PASS0_TR_SAR_IN       = 0x40000200u /* pass[0].tr_sar_in */
} en_trig_output_grp2_t;

/* Trigger Output Group 3 - Trigger sources for CSD */
typedef enum
{
    TRIG3_OUT_MSC0_TR_WR_REQ_IN     = 0x40000300u, /* msc[0].tr_wr_req_in */
    TRIG3_OUT_MSC0_TR_RD_REQ_IN     = 0x40000301u, /* msc[0].tr_rd_req_in */
    TRIG3_OUT_MSC1_TR_WR_REQ_IN     = 0x40000302u, /* msc[1].tr_wr_req_in */
    TRIG3_OUT_MSC1_TR_RD_REQ_IN     = 0x40000303u /* msc[1].tr_rd_req_in */
} en_trig_output_grp3_t;

/* Include IP definitions */
#include "ip/cyip_sflash_256.h"
#include "ip/cyip_peri.h"
#include "ip/cyip_hsiom.h"
#include "ip/cyip_srsslt.h"
#include "ip/cyip_gpio.h"
#include "ip/cyip_prgio.h"
#include "ip/cyip_cpuss_v3.h"
#include "ip/cyip_dmac_v3.h"
#include "ip/cyip_spcif_v3.h"
#include "ip/cyip_tcpwm_v2.h"
#include "ip/cyip_lcd_v2.h"
#include "ip/cyip_wco.h"
#include "ip/cyip_scb_v3.h"
#include "ip/cyip_msc.h"
#include "ip/cyip_lpcomp_v2.h"
#include "ip/cyip_crypto_v2.h"
#include "ip/cyip_exco_v2.h"
#include "ip/cyip_ctbm_v2.h"
#include "ip/cyip_sar_v2.h"
#include "ip/cyip_pass_v2.h"
#include "ip/cyip_canfd_v2.h"
#include "ip/cyip_i2s_v2.h"

/* Parameter Defines */
/* I2S capable? (0=No,1=Yes) */
#define AUDIOSS_I2S_I2S                 1u
/* I2S instantiates both RX and TX. 0=TX Only 1=RX Plus TX present */
#define AUDIOSS_I2S_I2S_RX_TX           0u
/* PDM capable? (0=No,1=Yes) */
#define AUDIOSS_PDM_PDM                 0u
/* Number of TTCAN instances */
#define CANFD_CAN_NR                    1u
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
/* CPUSS version (2 or 3) */
#define CPUSS_CPUSS_VER                 3u
/* CM0 present or CM0+ present (1=CM0, 0=CM0+) */
#define CPUSS_CM0_PRESENT               0u
/* CM0+ Memory protection unit present/not (0=not present, 8=present). */
#define CPUSS_CM0_MPU                   8u
/* MTB SRAM size in kilo bytes (0, 1, 2, or 4). Must be '0' for CM0, Non zero
   value only for CM0+. */
#define CPUSS_MTB_SRAM_SIZE             0u
/* CM0+ Micro Trace Buffer (MTB) Present or not (Must be '0' for CM0) */
#define CPUSS_MTB_PRESENT               0u
/* Maximum speed that system will run at (0=48MHz, 1=16MHz) */
#define CPUSS_MAX_16_MHZ                0u
/* System RAM parition 0, size in kilobytes */
#define CPUSS_SRAM_SIZE                 32u
/* System RAM parition 1, size in kilobytes */
#define CPUSS_SRAM1_SIZE                0u
/* Boot ROM size in kilobytes */
#define CPUSS_ROM_SIZE                  8u
/* Product has ROM available for system usage (1) or not (0) */
#define CPUSS_SYSTEM_ROM                0u
/* Boot ROM partition size */
#define CPUSS_BOOT_ROM_SIZE             8u
/* Boot ROM available (1) or all classified as System Rom (0) */
#define CPUSS_ROMC_BOOT_ROM_PRESENT     1u
/* Number of external slave ports on System Interconnect */
#define CPUSS_SL_NR                     4u
/* Flash memory present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_FLASHC_PRESENT            1u
/* Flash size in kilobytes */
#define CPUSS_FLASH_SIZE                384u
/* Debug support (0=No, 1=Yes) */
#define CPUSS_CM0_DBG                   1u
/* Number of break-point comparators ([0,4]) */
#define CPUSS_CM0_BKPT                  4u
/* Number of watch-point comparators ([0,2]) */
#define CPUSS_CM0_WPT                   2u
/* Serial multiplier (1) or parallel multiplier (0) */
#define CPUSS_CM0_SMUL                  0u
/* Clock Source clk_lf implemented in SysTick Counter. When 0, not implemented,
   1=implemented */
#define CPUSS_CM0_SYST_CLKSOURCE_LF     1u
/* Number of interrupt request inputs to CM0 ([8,32]) - called CM0_NUMIRQ in
   design */
#define CPUSS_INT_NR                    32u
/* Number of wakeup interrupt controller lines (always includes NMI, RXEV, so
   min=2) */
#define CPUSS_CM0_WICLINES              16u
/* Indicates whether DSI/FixedFunction interrupt multiplexer is present (0=No,
   1=Yes) */
#define CPUSS_INT_DSI                   0u
/* Implement DSI interrupt sync and pulse generation (1) or not (0) */
#define CPUSS_INT_DSI_SYNC              0u
/* Wounding supported (1) or not supported (0) - must be 1 currently */
#define CPUSS_WOUNDING                  1u
/* Protection modes supported (1) or not supported (0) - must be 1 currently */
#define CPUSS_PROTECTION                1u
/* DW/DMA Controller present (0=No, 1=Yes) */
#define CPUSS_DMAC_PRESENT              1u
/* Product is a multi-master system (same as CPUMEMSS.DMAC_PRESENT) */
#define CPUSS_MULTI_MASTER              1u
/* PTM interface present (0=No, 1=Yes) */
#define CPUSS_PTM_PRESENT               0u
/* Width of the PTM interface in bits ([2,32]) */
#define CPUSS_PTM_NR                    0u
/* Implement full (8-step) RAM BIST (1) or simple (1-step) RAM BIST (0) */
#define CPUSS_BIST_FULL                 1u
/* Number of external SRAMs connected to the CPUSS BIST controller */
#define CPUSS_BIST_EXT_SRAM_NR          8u
/* Number of SRAMs connected to the CPUSS BIST controller (BIST_EXT_SRAM_NR+4) */
#define CPUSS_BIST_SRAM_NR              12u
/* CoreSight Part Identification Number */
#define CPUSS_JEPID                     52u
/* CoreSight Part Identification Number */
#define CPUSS_JEPCONTINUATION           0u
/* CoreSight Part Identification Number */
#define CPUSS_PARTNUMBER                190u
/* External Master Present */
#define CPUSS_EXT_MS_PRESENT            0u
/* RAM controller 1 present (0=No, 1=Yes) */
#define CPUSS_RAMC1_PRESENT             0u
/* Enforce Secure Access restrictions (0=No, 1=Yes) */
#define CPUSS_SECURE_ACCESS             1u
/* SWD MultiDrop Present */
#define CPUSS_SWD_MULTIDROP             0u
/* Enable SROM DMA Access */
#define CPUSS_SROM_ACCESS_PRESENT       0u
/* Select Cell VT type. Drives the type of standard cell to be used in MXTK.
   Depends on the product */
#define CPUSS_CELL_VT_TYPE              1u
/* MTB SRAM Base adress - Value should be computed from Memory Map */
#define CPUSS_CM0PMTB_MTB_SRAMBASE      0u
/* DW/DMA Controller present (0=No, 1=Yes) */
#define CPUSS_CPUMEMSS_DMAC_PRESENT     1u
/* Number of DMA Channels */
#define CPUSS_DMAC_CH_NR                16u
/* Width in bits of a DMA channel number (derived from CH_NR as
   roundup(log2(CH_NR))) */
#define CPUSS_DMAC_CH_ADDR_WIDTH        4u
/* Product uses SRSS-Lite (1) or SRSSv2 (0) - used to determine NVL parameters */
#define CPUSS_SPCIF_SRSSLT              1u
/* Use 2X?? Option for FLASH to allow parallel code execution and programming of
   FLASH */
#define CPUSS_SPCIF_FLASH_PARALLEL_PGM_EN 1u
/* Flash memory present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_SPCIF_FLASHC_PRESENT      1u
/* HOBTO-M ULL65 SRAM/SROM required */
#define CPUSS_SPCIF_ULL65               0u
/* Flash type is FMLT or S8FS */
#define CPUSS_SPCIF_FMLT_OR_S8FS        1u
/* Product uses FLASH-Lite (1) or regular FLASH (0) */
#define CPUSS_SPCIF_FMLT                0u
/* Using regular flash (=1-FMLT) */
#define CPUSS_SPCIF_FM                  0u
/* Total Flash size in multiples of 256 bytes (0=1x256, 1=2x256, ...) */
#define CPUSS_SPCIF_FLASH_SIZE          1535u
/* The Flash read word width in bits (32, 64 or 128) */
#define CPUSS_SPCIF_FLASH_READ_WIDTH    64u
/* Total Supervisory Flash size in multiples of 256 bytes (0=1x256, 1=2x256, ...) */
#define CPUSS_SPCIF_SFLASH_SIZE         23u
/* Flash program/erase page size (0=64, 1=128 or 3=256 bytes) */
#define CPUSS_SPCIF_FLASH_PAGE_SIZE     3u
/* Number of Flash macros used in the device (0, 1 or 2) */
#define CPUSS_SPCIF_FLASH_MACROS        3u
/* Number of Flash macros minus 1 */
#define CPUSS_SPCIF_FLASH_MACROS_MINUS1 2u
/* Flash macro #1 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_1       1u
/* Flash macro #2 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_2       1u
/* Flash macro #3 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_3       0u
/* SPCIF Timer clock is synchronous (1) or asynchronous (0) to clk_sys */
#define CPUSS_SPCIF_SYNCHRONOUS         1u
/* NVLatches present (0=No, 1=Yes) */
#define CPUSS_SPCIF_NVLATCH             0u
/* NVLatches size in bytes (default=8) */
#define CPUSS_SPCIF_NVLATCH_SIZE        8u
/* Flash type (0=FM, 1=FMLT, 2=FS, 3=FSLT) */
#define CPUSS_SPCIF_FLASH_TYPE          3u
/* AES cipher support (0 = no support, 1 = support */
#define CRYPTO_AES                      1u
/* Pseudo random number generation support (0 = no support, 1 = support) */
#define CRYPTO_PR                       1u
/* True random number generation support (0 = no support, 1 = support) */
#define CRYPTO_TR                       1u
/* SHA hash support (0 = no support, 1 = support) */
#define CRYPTO_SHA                      1u
/* Cyclic Redundancy Check support (0 = no support, 1 = support) */
#define CRYPTO_CRC                      1u
/* Source Pointer 0 */
#define CRYPTO_SRC_CTL0_PRESENT         1u
/* Source Pointer 1 */
#define CRYPTO_SRC_CTL1_PRESENT         1u
/* Destination Pointer 0 */
#define CRYPTO_DST_CTL0_PRESENT         1u
/* Destination Pointer 1 */
#define CRYPTO_DST_CTL1_PRESENT         1u
/* Number of 32-bit words in the memory buffer (from the set [64, 128, 256, 512],
   to allow for a 256 B, 512 B, 1 kB, and 2 kB memory buffer) */
#define CRYPTO_MEM_SIZE                 128u
/* Memory address width in bytes */
#define CRYPTO_MEM_B_ADDR_WIDTH         16u
/* Memory address width in words */
#define CRYPTO_MEM_W_ADDR_WIDTH         16u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define CRYPTO_SPARE_EN                 1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define CRYPTO_SPARE_STDLIB_CFG         2u
/* Enable instantiate of PLL within IP */
#define EXCO_PLL_PRESENT                1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define EXCO_SPARE_EN                   1u
/* Enable use of alternate PLL Reference source (0=disable, 1=enable) Note: Not
   valid unless PLL_PRESENT==1. */
#define EXCO_PLL_REF_IN_EN              1u
/* IOSS Phase */
#define IOSS_IOSS_PHASE                 5u
/* Route REFGEN vinref & voutref to AMUX bus when set */
#define IOSS_SIO_REF_HOOKUP             0u
/* Use 1.8V signaling on XRES (Xres4 cell only) */
#define IOSS_USE_1P8V_SIGNALING_XRES4   0u
/* Number of ports in device */
#define IOSS_GPIO_GPIO_PORT_NR          13u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO7 1u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO7 1u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO7 1u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO7 1u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO7 1u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO7 1u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_IO7 1u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_FILTER_EN7 0u
/* Control register to improve IO testing */
#define IOSS_GPIO_IO_TEST_CTL           1u
/* GPIO_V1P2 cells used ? */
#define IOSS_GPIO_IO_GPIOV1P2           0u
/* Is there a pump in IOSS ? (same as GLOBAL.HAS_PUMP_IN_IOSS) */
#define IOSS_HSIOM_PUMP                 1u
/* Number of AMUX splitter cells */
#define IOSS_HSIOM_AMUX_SPLIT_NR        3u
/* Number of HSIOM ports in device (same as GPIO.GPIO_PRT_NR) */
#define IOSS_HSIOM_HSIOM_PORT_NR        13u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO7 1u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO7 1u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO7 1u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO7 1u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO7 1u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO7 1u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR7_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR7_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR7_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR7_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR7_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR7_HSIOM_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR7_HSIOM_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR7_HSIOM_PRT_IO7 1u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR9_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR9_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR9_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR9_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR9_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR9_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR9_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR9_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR10_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR10_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR10_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR10_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR10_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR10_HSIOM_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR10_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR10_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR11_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR11_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR11_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR11_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR11_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR11_HSIOM_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR11_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR11_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR12_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR12_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR12_HSIOM_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR12_HSIOM_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR12_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR12_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR12_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR12_HSIOM_PRT_IO7 0u
/* Number of PRGIO instances (in 8b ports) */
#define IOSS_PRGIO_PRGIO_NR             3u
/* Max number of LCD commons supported */
#define LCD_COM_NR                      8u
/* Max number of LCD pins (total) supported */
#define LCD_PIN_NR                      64u
/* Number of ports supoprting up to 4 COMs */
#define LCD_NUMPORTS                    8u
/* Number of ports supporting up to 8 COMs */
#define LCD_NUMPORTS8                   8u
/* Number of ports supporting up to 16 COMs */
#define LCD_NUMPORTS16                  0u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define LCD_SPARE_EN                    0u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define LCD_SPARE_STDLIB_CFG            2u
/* Spare Enable 0=no spare, 1=max, 2=min */
#define LPCOMP_SPARE_EN                 0u
/* Std Lib Config 1=scs8ls, 2=scs8hd, 3=scs8hv(invalid), others=reserved */
#define LPCOMP_SPARE_STDLIB_CFG         2u
/* Depth of sample result FIFO for a single sensor. Actual hardware FIFO depth is
   CONFIG_NR*SAMPLE_NR in cases where CONFIG_NR > 0. */
#define MSC0_SAMPLE_NR                  1u
/* Autonomous scan sensor configuration storage quantity. Default is 0 (this
   implies no RAM storage and MMIO configuration capability only). Supported
   values: [0,8,16,32,64,128,256] */
#define MSC0_CONFIG_NR                  0u
/* Number of predefined GPIO pads supported by the analog control switch matrix
   for high-performance capacitive sensing. */
#define MSC0_SENSE_PAD_NR               16u
/* Number of on-chip MSCv3 channels */
#define MSC0_CH_NR                      2u
/* Number of sensing modes supported autonomously. */
#define MSC0_SENSE_MODE_NR              3u
/* LP-AoC present/absent */
#define MSC0_LP_AOC_PRESENT             0u
/* Nano power present/absent. */
#define MSC0_NP_PRESENT                 0u
/* 0=ULL65, 1=MXS40-ULP, 2=MXS40E, 3=M0S8, 4=MXS40-HD, 5=F45, 6=MXS40v2, 7=T28HPM,
   8=T28HPL, 9=T28HPC */
#define MSC0_PLATFORM_VARIANT           3u
/* SRAM vendor ({0=Cypress, 1=Synopsys, 2=ARM, 3=Broadcom,4=TSMC}) */
#define MSC0_RAM_VEND                   0u
/* Spare cell enable. ({0=no spare, 1=max, 2=min}) */
#define MSC0_SPARE_EN                   1u
/* Depth of sample result FIFO for a single sensor. Actual hardware FIFO depth is
   CONFIG_NR*SAMPLE_NR in cases where CONFIG_NR > 0. */
#define MSC1_SAMPLE_NR                  1u
/* Autonomous scan sensor configuration storage quantity. Default is 0 (this
   implies no RAM storage and MMIO configuration capability only). Supported
   values: [0,8,16,32,64,128,256] */
#define MSC1_CONFIG_NR                  0u
/* Number of predefined GPIO pads supported by the analog control switch matrix
   for high-performance capacitive sensing. */
#define MSC1_SENSE_PAD_NR               16u
/* Number of on-chip MSCv3 channels */
#define MSC1_CH_NR                      2u
/* Number of sensing modes supported autonomously. */
#define MSC1_SENSE_MODE_NR              3u
/* LP-AoC present/absent */
#define MSC1_LP_AOC_PRESENT             0u
/* Nano power present/absent. */
#define MSC1_NP_PRESENT                 0u
/* 0=ULL65, 1=MXS40-ULP, 2=MXS40E, 3=M0S8, 4=MXS40-HD, 5=F45, 6=MXS40v2, 7=T28HPM,
   8=T28HPL, 9=T28HPC */
#define MSC1_PLATFORM_VARIANT           3u
/* SRAM vendor ({0=Cypress, 1=Synopsys, 2=ARM, 3=Broadcom,4=TSMC}) */
#define MSC1_RAM_VEND                   0u
/* Spare cell enable. ({0=no spare, 1=max, 2=min}) */
#define MSC1_SPARE_EN                   1u
/* Number of CTBms in the Subsystem */
#define PASS0_NR_CTBS                   1u
/* Switch between SRSSv2 and SRSSLITE */
#define PASS0_SRSSLITE_PRESENT          1u
/* CTB0 Exists */
#define PASS0_CTB0_EXISTS               1u
/* CTB1 Exists */
#define PASS0_CTB1_EXISTS               0u
/* CTB2 Exists */
#define PASS0_CTB2_EXISTS               0u
/* CTB3 Exists */
#define PASS0_CTB3_EXISTS               0u
/* Number of slices (slice 0 = SAR) */
#define PASS0_SAR_NR_SLICES             2u
/* Number of SAR channels */
#define PASS0_SAR_SAR_CHANNELS          16u
/* Averaging logic present in SAR */
#define PASS0_SAR_SAR_AVERAGE           1u
/* Range detect logic present in SAR */
#define PASS0_SAR_SAR_RANGEDET          1u
/* Number of programmable clocks (outputs) */
#define PERI_PCLK_CLOCK_NR              24u
/* Number of 8.0 dividers */
#define PERI_PCLK_DIV_8_NR              0u
/* Number of 16.0 dividers */
#define PERI_PCLK_DIV_16_NR             15u
/* Number of 16.5 (fractional) dividers */
#define PERI_PCLK_DIV_16_5_NR           5u
/* Number of 24.5 (fractional) dividers */
#define PERI_PCLK_DIV_24_5_NR           1u
/* Divider number width: roundup(log2(max(DIV_*_NR)) */
#define PERI_PCLK_DIV_ADDR_WIDTH        4u
/* Trigger module present (0=No, 1=Yes) */
#define PERI_TR                         1u
/* Number of trigger groups */
#define PERI_TR_GROUP_NR                4u
/* Number of input triggers */
#define PERI_TR_GROUP_NR0_TR_GROUP_TR_IN_NR 66u
/* Number of output triggers */
#define PERI_TR_GROUP_NR0_TR_GROUP_TR_OUT_NR 18u
/* Input trigger number width: roundup(log2(TR_IN_NR)) */
#define PERI_TR_GROUP_NR0_TR_GROUP_TR_IN_ADDR_WIDTH 7u
/* Number of input triggers */
#define PERI_TR_GROUP_NR1_TR_GROUP_TR_IN_NR 37u
/* Number of output triggers */
#define PERI_TR_GROUP_NR1_TR_GROUP_TR_OUT_NR 7u
/* Input trigger number width: roundup(log2(TR_IN_NR)) */
#define PERI_TR_GROUP_NR1_TR_GROUP_TR_IN_ADDR_WIDTH 6u
/* Number of input triggers */
#define PERI_TR_GROUP_NR2_TR_GROUP_TR_IN_NR 39u
/* Number of output triggers */
#define PERI_TR_GROUP_NR2_TR_GROUP_TR_OUT_NR 1u
/* Input trigger number width: roundup(log2(TR_IN_NR)) */
#define PERI_TR_GROUP_NR2_TR_GROUP_TR_IN_ADDR_WIDTH 6u
/* Number of input triggers */
#define PERI_TR_GROUP_NR3_TR_GROUP_TR_IN_NR 17u
/* Number of output triggers */
#define PERI_TR_GROUP_NR3_TR_GROUP_TR_OUT_NR 4u
/* Input trigger number width: roundup(log2(TR_IN_NR)) */
#define PERI_TR_GROUP_NR3_TR_GROUP_TR_IN_ADDR_WIDTH 5u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB0_DEEPSLEEP                  1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB0_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB0_I2C_S                      1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB0_I2C_S_EC                   1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB0_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB0_I2C_HS                     1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB0_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB0_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB0_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB0_I2C_M_HS                   1u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB0_I2C_S_HS                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB0_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB0_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB0_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB0_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB0_SPI_EC                     1u
/* Externally clocked support? (I2C_S_EC | SPI_S_EC) */
#define SCB0_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB0_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB0_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB0_EZ_DATA_NR                 32u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB0_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB0_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB0_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB0_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB0_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB0_MASTER_WIDTH               2u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB0_CHIP_TOP_DDFT_USED         0u
/* Number of used spi_select signals (max 4) */
#define SCB0_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB0_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB1_DEEPSLEEP                  1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB1_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB1_I2C_S                      1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB1_I2C_S_EC                   1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB1_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB1_I2C_HS                     0u
/* I2C support? (I2C_M | I2C_S) */
#define SCB1_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB1_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB1_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB1_I2C_M_HS                   1u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB1_I2C_S_HS                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB1_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB1_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB1_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB1_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB1_SPI_EC                     1u
/* Externally clocked support? (I2C_S_EC | SPI_S_EC) */
#define SCB1_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB1_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB1_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB1_EZ_DATA_NR                 32u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB1_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB1_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB1_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB1_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB1_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB1_MASTER_WIDTH               2u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB1_CHIP_TOP_DDFT_USED         0u
/* Number of used spi_select signals (max 4) */
#define SCB1_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB1_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB2_DEEPSLEEP                  1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB2_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB2_I2C_S                      1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB2_I2C_S_EC                   1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB2_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB2_I2C_HS                     0u
/* I2C support? (I2C_M | I2C_S) */
#define SCB2_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB2_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB2_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB2_I2C_M_HS                   1u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB2_I2C_S_HS                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB2_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB2_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB2_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB2_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB2_SPI_EC                     1u
/* Externally clocked support? (I2C_S_EC | SPI_S_EC) */
#define SCB2_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB2_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB2_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB2_EZ_DATA_NR                 32u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB2_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB2_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB2_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB2_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB2_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB2_MASTER_WIDTH               2u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB2_CHIP_TOP_DDFT_USED         0u
/* Number of used spi_select signals (max 4) */
#define SCB2_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB2_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB3_DEEPSLEEP                  1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB3_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB3_I2C_S                      1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB3_I2C_S_EC                   1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB3_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB3_I2C_HS                     0u
/* I2C support? (I2C_M | I2C_S) */
#define SCB3_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB3_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB3_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB3_I2C_M_HS                   1u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB3_I2C_S_HS                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB3_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB3_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB3_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB3_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB3_SPI_EC                     1u
/* Externally clocked support? (I2C_S_EC | SPI_S_EC) */
#define SCB3_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB3_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB3_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB3_EZ_DATA_NR                 32u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB3_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB3_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB3_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB3_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB3_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB3_MASTER_WIDTH               2u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB3_CHIP_TOP_DDFT_USED         0u
/* Number of used spi_select signals (max 4) */
#define SCB3_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB3_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB4_DEEPSLEEP                  1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB4_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB4_I2C_S                      1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB4_I2C_S_EC                   1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB4_I2C_GLITCH                 1u
/* Support I2C Hs-mode (3.4Mbps) ('0': no, '1': yes) */
#define SCB4_I2C_HS                     0u
/* I2C support? (I2C_M | I2C_S) */
#define SCB4_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB4_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB4_I2C_M_S                    1u
/* I2C master and slave support? (I2C_M & I2C_HS) */
#define SCB4_I2C_M_HS                   1u
/* I2C master and slave support? (I2C_S & I2C_HS) */
#define SCB4_I2C_S_HS                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB4_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB4_SPI_S                      1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB4_SPI_S_EC                   1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB4_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB4_SPI_EC                     1u
/* Externally clocked support? (I2C_S_EC | SPI_S_EC) */
#define SCB4_EC                         1u
/* UART support? ('0': no, '1': yes) */
#define SCB4_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB4_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB4_EZ_DATA_NR                 32u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB4_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB4_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB4_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB4_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB4_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB4_MASTER_WIDTH               2u
/* ddft_in[1:0] and ddft_out[1:0] are used (not used on M0S8 platform) */
#define SCB4_CHIP_TOP_DDFT_USED         0u
/* Number of used spi_select signals (max 4) */
#define SCB4_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB4_CHIP_TOP_I2C_FAST_PLUS     1u
/* Does this product have the 2 byte address encoding for 8B CalPairs ? */
#define SFLASH_CALPAIRS_HAVE_2B_ADDRESS 1u
/* Is this TSG4 ? */
#define SFLASH_IS_TSG4                  0u
/* Is this TSG5-M ? */
#define SFLASH_IS_TSG5M                 0u
/* Is this TSG5-L ? */
#define SFLASH_IS_TSG5L                 0u
/* Does this product have standard SWD placement control ? */
#define SFLASH_STD_SWD                  1u
/* Flash Macro 0 has extra rows */
#define SFLASH_FLASH_M0_XTRA_ROWS       1u
/* Does this product include BLE DMA256 RevC? */
#define SFLASH_HAS_BLEDMA256_REVC       0u
/* Does this product include CSDV2 (m0s8csdv2) ? */
#define SFLASH_HAS_CSDV2                0u
/* Does this product include CSD (m0s8csdv2) ? (w/ 2nd CSD) */
#define SFLASH_HAS_CSDV2_2              0u
/* Does this product include CSD (m0s8csd) ? */
#define SFLASH_HAS_CSD                  0u
/* Does this product include SAR (m0s8sar) ? */
#define SFLASH_HAS_SAR                  1u
/* Does the product include BLE (m0s8bless)? */
#define SFLASH_HAS_BLE                  0u
/* Is the Product BLE128 */
#define SFLASH_IS_BLE128                0u
/* Is the Device PSoC4AL with Copper? */
#define SFLASH_IS_PSOC4AL_CU            0u
/* Does the product include Atlas PLL (s8atlasana) */
#define SFLASH_HAS_ATLAS_PLL            0u
/* Does this product use SRSSv2 ? */
#define SFLASH_SRSSV2                   0u
/* Does this product use SRSS-Lite ? */
#define SFLASH_SRSSLT                   1u
/* Does this product use 2 FLASH macros or more ? */
#define SFLASH_HAS_2FM                  0u
/* Does this product use 3 FLASH macros or more ? */
#define SFLASH_HAS_3FM                  1u
/* Does this product use 4 FLASH macros or more ? */
#define SFLASH_HAS_4FM                  0u
/* Does this product have 2 CSDs and based on SRSSv2? */
#define SFLASH_CSD2_AND_SRSSV2          0u
/* Remap CSD2 INIT Value out of 8B area */
#define SFLASH_MOVE_CSD2_INIT_VALUE     0u
/* Does this product include PACSS (m0s8pacss) ? */
#define SFLASH_HAS_PACSS                0u
/* SRSSLT will use the NOESD version when set to 1 */
#define SRSSLT_SRSSLT_NOESD             0u
/* Number of bits from WDT_MATCH that are ignore in comparison */
#define SRSSLT_WDT_MATCH_MASK           0u
/* Connect vddio bus to pad_vddd (0) or pad_vccq_or_vddio (1) */
#define SRSSLT_HAS_VDDIO_PAD            0u
/* Number of counters per IP (1..8) */
#define TCPWM_CNT_NR                    8u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define TCPWM_SPARE_EN                  0u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define TCPWM_SPARE_STDLIB_CFG          2u
/* WDT enable (0= no WDT, 1=WDT present) */
#define WCO_WDT_EN                      1u
/* Spare Enable 0=no spare, 1=max, 2=min */
#define WCO_SPARE_EN                    0u
/* Std Lib Config 1=scs8ls, 2=scs8hd, 3=scs8hv(invalid), others=reserved */
#define WCO_SPARE_STDLIB_CFG            2u
/* Number of words in EZ memory */
#define SCB_EZ_DATA_NR                  32u

#endif /* _PSOC4100SMAX_CONFIG_H_ */


/* [] END OF FILE */
