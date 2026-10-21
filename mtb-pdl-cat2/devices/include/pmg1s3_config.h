/***************************************************************************//**
* \file pmg1s3_config.h
*
* \brief
* PMG1S3 device configuration header
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

#ifndef _PMG1S3_CONFIG_H_
#define _PMG1S3_CONFIG_H_

/* Clock Connections */
typedef enum
{
    PCLK_SCB0_CLOCK                 = 0x0000u,  /* scb[0].clock */
    PCLK_SCB1_CLOCK                 = 0x0001u,  /* scb[1].clock */
    PCLK_SCB2_CLOCK                 = 0x0002u,  /* scb[2].clock */
    PCLK_SCB3_CLOCK                 = 0x0003u,  /* scb[3].clock */
    PCLK_SCB4_CLOCK                 = 0x0004u,  /* scb[4].clock */
    PCLK_SCB5_CLOCK                 = 0x0005u,  /* scb[5].clock */
    PCLK_SCB6_CLOCK                 = 0x0006u,  /* scb[6].clock */
    PCLK_SCB7_CLOCK                 = 0x0007u,  /* scb[7].clock */
    PCLK_TCPWM_CLOCKS0              = 0x0008u,  /* tcpwm.clocks[0] */
    PCLK_TCPWM_CLOCKS1              = 0x0009u,  /* tcpwm.clocks[1] */
    PCLK_TCPWM_CLOCKS2              = 0x000Au,  /* tcpwm.clocks[2] */
    PCLK_TCPWM_CLOCKS3              = 0x000Bu,  /* tcpwm.clocks[3] */
    PCLK_TCPWM_CLOCKS4              = 0x000Cu,  /* tcpwm.clocks[4] */
    PCLK_TCPWM_CLOCKS5              = 0x000Du,  /* tcpwm.clocks[5] */
    PCLK_TCPWM_CLOCKS6              = 0x000Eu,  /* tcpwm.clocks[6] */
    PCLK_TCPWM_CLOCKS7              = 0x000Fu,  /* tcpwm.clocks[7] */
    PCLK_CSD_CLOCK                  = 0x0010u,  /* csd.clock */
    PCLK_PASS0_CLOCK_SAR            = 0x0011u,  /* pass[0].clock_sar */
    PCLK_USBPD0_CLOCK_RX            = 0x0012u,  /* usbpd[0].clock_rx */
    PCLK_USBPD0_CLOCK_TX            = 0x0013u,  /* usbpd[0].clock_tx */
    PCLK_USBPD0_CLOCK_SAR           = 0x0014u,  /* usbpd[0].clock_sar */
    PCLK_USBPD0_CLOCK_SWAP          = 0x0015u,  /* usbpd[0].clock_swap */
    PCLK_USBPD0_CLOCK_FILTER1       = 0x0016u,  /* usbpd[0].clock_filter1 */
    PCLK_USBPD0_CLOCK_FILTER2       = 0x0017u,  /* usbpd[0].clock_filter2 */
    PCLK_USBPD0_CLOCK_REFGEN        = 0x0018u,  /* usbpd[0].clock_refgen */
    PCLK_USBPD0_CLOCK_BCH_DET       = 0x0019u,  /* usbpd[0].clock_bch_det */
    PCLK_USBPD1_CLOCK_RX            = 0x001Au,  /* usbpd[1].clock_rx */
    PCLK_USBPD1_CLOCK_TX            = 0x001Bu,  /* usbpd[1].clock_tx */
    PCLK_USBPD1_CLOCK_SAR           = 0x001Cu,  /* usbpd[1].clock_sar */
    PCLK_USBPD1_CLOCK_SWAP          = 0x001Du,  /* usbpd[1].clock_swap */
    PCLK_USBPD1_CLOCK_FILTER1       = 0x001Eu,  /* usbpd[1].clock_filter1 */
    PCLK_USBPD1_CLOCK_FILTER2       = 0x001Fu   /* usbpd[1].clock_filter2 */
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
    TRIG0_IN_SCB5_TR_TX_REQ         = 0x00000023u, /* scb[5].tr_tx_req */
    TRIG0_IN_SCB5_TR_RX_REQ         = 0x00000024u, /* scb[5].tr_rx_req */
    TRIG0_IN_SCB6_TR_TX_REQ         = 0x00000025u, /* scb[6].tr_tx_req */
    TRIG0_IN_SCB6_TR_RX_REQ         = 0x00000026u, /* scb[6].tr_rx_req */
    TRIG0_IN_SCB7_TR_TX_REQ         = 0x00000027u, /* scb[7].tr_tx_req */
    TRIG0_IN_SCB7_TR_RX_REQ         = 0x00000028u, /* scb[7].tr_rx_req */
    TRIG0_IN_CPUSS_DMAC_TR_OUT0     = 0x00000029u, /* cpuss.dmac_tr_out[0] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT1     = 0x0000002Au, /* cpuss.dmac_tr_out[1] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT2     = 0x0000002Bu, /* cpuss.dmac_tr_out[2] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT3     = 0x0000002Cu, /* cpuss.dmac_tr_out[3] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT4     = 0x0000002Du, /* cpuss.dmac_tr_out[4] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT5     = 0x0000002Eu, /* cpuss.dmac_tr_out[5] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT6     = 0x0000002Fu, /* cpuss.dmac_tr_out[6] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT7     = 0x00000030u, /* cpuss.dmac_tr_out[7] */
    TRIG0_IN_PASS0_DSI_SAR_SAMPLE_DONE = 0x00000031u, /* pass[0].dsi_sar_sample_done */
    TRIG0_IN_PASS0_TR_SAR_OUT       = 0x00000032u, /* pass[0].tr_sar_out */
    TRIG0_IN_PASS0_DSI_CTB_CMP0     = 0x00000033u, /* pass[0].dsi_ctb_cmp0 */
    TRIG0_IN_PASS0_DSI_CTB_CMP1     = 0x00000034u, /* pass[0].dsi_ctb_cmp1 */
    TRIG0_IN_LPCOMP_COMP_OUT0       = 0x00000035u, /* lpcomp.comp_out[0] */
    TRIG0_IN_LPCOMP_COMP_OUT1       = 0x00000036u /* lpcomp.comp_out[1] */
} en_trig_input_grp0_t;

/* Trigger Input Group 1 - DMA Request Assignments, channels 8-15 */
typedef enum
{
    TRIG1_IN_CPUSS_ZERO             = 0x00000100u, /* cpuss.zero */
    TRIG1_IN_USB_DMA_REQ0           = 0x00000101u, /* usb.dma_req[0] */
    TRIG1_IN_USB_DMA_REQ1           = 0x00000102u, /* usb.dma_req[1] */
    TRIG1_IN_USB_DMA_REQ2           = 0x00000103u, /* usb.dma_req[2] */
    TRIG1_IN_USB_DMA_REQ3           = 0x00000104u, /* usb.dma_req[3] */
    TRIG1_IN_USB_DMA_REQ4           = 0x00000105u, /* usb.dma_req[4] */
    TRIG1_IN_USB_DMA_REQ5           = 0x00000106u, /* usb.dma_req[5] */
    TRIG1_IN_USB_DMA_REQ6           = 0x00000107u, /* usb.dma_req[6] */
    TRIG1_IN_USB_DMA_REQ7           = 0x00000108u, /* usb.dma_req[7] */
    TRIG1_IN_CPUSS_DMAC_TR_OUT8     = 0x00000109u, /* cpuss.dmac_tr_out[8] */
    TRIG1_IN_CPUSS_DMAC_TR_OUT9     = 0x0000010Au, /* cpuss.dmac_tr_out[9] */
    TRIG1_IN_CPUSS_DMAC_TR_OUT10    = 0x0000010Bu, /* cpuss.dmac_tr_out[10] */
    TRIG1_IN_CPUSS_DMAC_TR_OUT11    = 0x0000010Cu, /* cpuss.dmac_tr_out[11] */
    TRIG1_IN_CPUSS_DMAC_TR_OUT12    = 0x0000010Du, /* cpuss.dmac_tr_out[12] */
    TRIG1_IN_CPUSS_DMAC_TR_OUT13    = 0x0000010Eu, /* cpuss.dmac_tr_out[13] */
    TRIG1_IN_CPUSS_DMAC_TR_OUT14    = 0x0000010Fu, /* cpuss.dmac_tr_out[14] */
    TRIG1_IN_CPUSS_DMAC_TR_OUT15    = 0x00000110u /* cpuss.dmac_tr_out[15] */
} en_trig_input_grp1_t;

/* Trigger Input Group 2 - USB Trigger Burst End assignment */
typedef enum
{
    TRIG2_IN_CPUSS_ZERO             = 0x00000200u, /* cpuss.zero */
    TRIG2_IN_CPUSS_DMAC_TR_OUT8     = 0x00000201u, /* cpuss.dmac_tr_out[8] */
    TRIG2_IN_CPUSS_DMAC_TR_OUT9     = 0x00000202u, /* cpuss.dmac_tr_out[9] */
    TRIG2_IN_CPUSS_DMAC_TR_OUT10    = 0x00000203u, /* cpuss.dmac_tr_out[10] */
    TRIG2_IN_CPUSS_DMAC_TR_OUT11    = 0x00000204u, /* cpuss.dmac_tr_out[11] */
    TRIG2_IN_CPUSS_DMAC_TR_OUT12    = 0x00000205u, /* cpuss.dmac_tr_out[12] */
    TRIG2_IN_CPUSS_DMAC_TR_OUT13    = 0x00000206u, /* cpuss.dmac_tr_out[13] */
    TRIG2_IN_CPUSS_DMAC_TR_OUT14    = 0x00000207u, /* cpuss.dmac_tr_out[14] */
    TRIG2_IN_CPUSS_DMAC_TR_OUT15    = 0x00000208u /* cpuss.dmac_tr_out[15] */
} en_trig_input_grp2_t;

/* Trigger Input Group 3 - Trigger sources for TCPWM */
typedef enum
{
    TRIG3_IN_CPUSS_ZERO             = 0x00000300u, /* cpuss.zero */
    TRIG3_IN_TCPWM_TR_OVERFLOW0     = 0x00000301u, /* tcpwm.tr_overflow[0] */
    TRIG3_IN_TCPWM_TR_OVERFLOW1     = 0x00000302u, /* tcpwm.tr_overflow[1] */
    TRIG3_IN_TCPWM_TR_OVERFLOW2     = 0x00000303u, /* tcpwm.tr_overflow[2] */
    TRIG3_IN_TCPWM_TR_OVERFLOW3     = 0x00000304u, /* tcpwm.tr_overflow[3] */
    TRIG3_IN_TCPWM_TR_OVERFLOW4     = 0x00000305u, /* tcpwm.tr_overflow[4] */
    TRIG3_IN_TCPWM_TR_OVERFLOW5     = 0x00000306u, /* tcpwm.tr_overflow[5] */
    TRIG3_IN_TCPWM_TR_OVERFLOW6     = 0x00000307u, /* tcpwm.tr_overflow[6] */
    TRIG3_IN_TCPWM_TR_OVERFLOW7     = 0x00000308u, /* tcpwm.tr_overflow[7] */
    TRIG3_IN_TCPWM_TR_COMPARE_MATCH0 = 0x00000309u, /* tcpwm.tr_compare_match[0] */
    TRIG3_IN_TCPWM_TR_COMPARE_MATCH1 = 0x0000030Au, /* tcpwm.tr_compare_match[1] */
    TRIG3_IN_TCPWM_TR_COMPARE_MATCH2 = 0x0000030Bu, /* tcpwm.tr_compare_match[2] */
    TRIG3_IN_TCPWM_TR_COMPARE_MATCH3 = 0x0000030Cu, /* tcpwm.tr_compare_match[3] */
    TRIG3_IN_TCPWM_TR_COMPARE_MATCH4 = 0x0000030Du, /* tcpwm.tr_compare_match[4] */
    TRIG3_IN_TCPWM_TR_COMPARE_MATCH5 = 0x0000030Eu, /* tcpwm.tr_compare_match[5] */
    TRIG3_IN_TCPWM_TR_COMPARE_MATCH6 = 0x0000030Fu, /* tcpwm.tr_compare_match[6] */
    TRIG3_IN_TCPWM_TR_COMPARE_MATCH7 = 0x00000310u, /* tcpwm.tr_compare_match[7] */
    TRIG3_IN_TCPWM_TR_UNDERFLOW0    = 0x00000311u, /* tcpwm.tr_underflow[0] */
    TRIG3_IN_TCPWM_TR_UNDERFLOW1    = 0x00000312u, /* tcpwm.tr_underflow[1] */
    TRIG3_IN_TCPWM_TR_UNDERFLOW2    = 0x00000313u, /* tcpwm.tr_underflow[2] */
    TRIG3_IN_TCPWM_TR_UNDERFLOW3    = 0x00000314u, /* tcpwm.tr_underflow[3] */
    TRIG3_IN_TCPWM_TR_UNDERFLOW4    = 0x00000315u, /* tcpwm.tr_underflow[4] */
    TRIG3_IN_TCPWM_TR_UNDERFLOW5    = 0x00000316u, /* tcpwm.tr_underflow[5] */
    TRIG3_IN_TCPWM_TR_UNDERFLOW6    = 0x00000317u, /* tcpwm.tr_underflow[6] */
    TRIG3_IN_TCPWM_TR_UNDERFLOW7    = 0x00000318u, /* tcpwm.tr_underflow[7] */
    TRIG3_IN_PASS0_DSI_SAR_SAMPLE_DONE = 0x00000319u, /* pass[0].dsi_sar_sample_done */
    TRIG3_IN_PASS0_TR_SAR_OUT       = 0x0000031Au, /* pass[0].tr_sar_out */
    TRIG3_IN_PASS0_DSI_CTB_CMP0     = 0x0000031Bu, /* pass[0].dsi_ctb_cmp0 */
    TRIG3_IN_PASS0_DSI_CTB_CMP1     = 0x0000031Cu, /* pass[0].dsi_ctb_cmp1 */
    TRIG3_IN_LPCOMP_COMP_OUT0       = 0x0000031Du, /* lpcomp.comp_out[0] */
    TRIG3_IN_LPCOMP_COMP_OUT1       = 0x0000031Eu, /* lpcomp.comp_out[1] */
    TRIG3_IN_USBPD0_TR_OUT_0        = 0x0000031Fu, /* usbpd[0].tr_out_0 */
    TRIG3_IN_USBPD0_TR_OUT_1        = 0x00000320u, /* usbpd[0].tr_out_1 */
    TRIG3_IN_USBPD0_TR_OUT_2        = 0x00000321u, /* usbpd[0].tr_out_2 */
    TRIG3_IN_USBPD0_TR_OUT_3        = 0x00000322u, /* usbpd[0].tr_out_3 */
    TRIG3_IN_USBPD0_TR_OUT_4        = 0x00000323u, /* usbpd[0].tr_out_4 */
    TRIG3_IN_USBPD0_TR_OUT_5        = 0x00000324u, /* usbpd[0].tr_out_5 */
    TRIG3_IN_USBPD0_TR_OUT_6        = 0x00000325u, /* usbpd[0].tr_out_6 */
    TRIG3_IN_USBPD1_TR_OUT_0        = 0x00000326u, /* usbpd[1].tr_out_0 */
    TRIG3_IN_USBPD1_TR_OUT_1        = 0x00000327u, /* usbpd[1].tr_out_1 */
    TRIG3_IN_USBPD1_TR_OUT_2        = 0x00000328u, /* usbpd[1].tr_out_2 */
    TRIG3_IN_USBPD1_TR_OUT_3        = 0x00000329u, /* usbpd[1].tr_out_3 */
    TRIG3_IN_USBPD1_TR_OUT_4        = 0x0000032Au, /* usbpd[1].tr_out_4 */
    TRIG3_IN_USBPD1_TR_OUT_5        = 0x0000032Bu, /* usbpd[1].tr_out_5 */
    TRIG3_IN_USBPD1_TR_OUT_6        = 0x0000032Cu /* usbpd[1].tr_out_6 */
} en_trig_input_grp3_t;

/* Trigger Input Group 4 - Trigger sources for PASS */
typedef enum
{
    TRIG4_IN_CPUSS_ZERO             = 0x00000400u, /* cpuss.zero */
    TRIG4_IN_TCPWM_TR_OVERFLOW0     = 0x00000401u, /* tcpwm.tr_overflow[0] */
    TRIG4_IN_TCPWM_TR_OVERFLOW1     = 0x00000402u, /* tcpwm.tr_overflow[1] */
    TRIG4_IN_TCPWM_TR_OVERFLOW2     = 0x00000403u, /* tcpwm.tr_overflow[2] */
    TRIG4_IN_TCPWM_TR_OVERFLOW3     = 0x00000404u, /* tcpwm.tr_overflow[3] */
    TRIG4_IN_TCPWM_TR_OVERFLOW4     = 0x00000405u, /* tcpwm.tr_overflow[4] */
    TRIG4_IN_TCPWM_TR_OVERFLOW5     = 0x00000406u, /* tcpwm.tr_overflow[5] */
    TRIG4_IN_TCPWM_TR_OVERFLOW6     = 0x00000407u, /* tcpwm.tr_overflow[6] */
    TRIG4_IN_TCPWM_TR_OVERFLOW7     = 0x00000408u, /* tcpwm.tr_overflow[7] */
    TRIG4_IN_TCPWM_TR_COMPARE_MATCH0 = 0x00000409u, /* tcpwm.tr_compare_match[0] */
    TRIG4_IN_TCPWM_TR_COMPARE_MATCH1 = 0x0000040Au, /* tcpwm.tr_compare_match[1] */
    TRIG4_IN_TCPWM_TR_COMPARE_MATCH2 = 0x0000040Bu, /* tcpwm.tr_compare_match[2] */
    TRIG4_IN_TCPWM_TR_COMPARE_MATCH3 = 0x0000040Cu, /* tcpwm.tr_compare_match[3] */
    TRIG4_IN_TCPWM_TR_COMPARE_MATCH4 = 0x0000040Du, /* tcpwm.tr_compare_match[4] */
    TRIG4_IN_TCPWM_TR_COMPARE_MATCH5 = 0x0000040Eu, /* tcpwm.tr_compare_match[5] */
    TRIG4_IN_TCPWM_TR_COMPARE_MATCH6 = 0x0000040Fu, /* tcpwm.tr_compare_match[6] */
    TRIG4_IN_TCPWM_TR_COMPARE_MATCH7 = 0x00000410u, /* tcpwm.tr_compare_match[7] */
    TRIG4_IN_TCPWM_TR_UNDERFLOW0    = 0x00000411u, /* tcpwm.tr_underflow[0] */
    TRIG4_IN_TCPWM_TR_UNDERFLOW1    = 0x00000412u, /* tcpwm.tr_underflow[1] */
    TRIG4_IN_TCPWM_TR_UNDERFLOW2    = 0x00000413u, /* tcpwm.tr_underflow[2] */
    TRIG4_IN_TCPWM_TR_UNDERFLOW3    = 0x00000414u, /* tcpwm.tr_underflow[3] */
    TRIG4_IN_TCPWM_TR_UNDERFLOW4    = 0x00000415u, /* tcpwm.tr_underflow[4] */
    TRIG4_IN_TCPWM_TR_UNDERFLOW5    = 0x00000416u, /* tcpwm.tr_underflow[5] */
    TRIG4_IN_TCPWM_TR_UNDERFLOW6    = 0x00000417u, /* tcpwm.tr_underflow[6] */
    TRIG4_IN_TCPWM_TR_UNDERFLOW7    = 0x00000418u, /* tcpwm.tr_underflow[7] */
    TRIG4_IN_TCPWM_LINE0            = 0x00000419u, /* tcpwm.line[0] */
    TRIG4_IN_TCPWM_LINE1            = 0x0000041Au, /* tcpwm.line[1] */
    TRIG4_IN_TCPWM_LINE2            = 0x0000041Bu, /* tcpwm.line[2] */
    TRIG4_IN_TCPWM_LINE3            = 0x0000041Cu, /* tcpwm.line[3] */
    TRIG4_IN_TCPWM_LINE4            = 0x0000041Du, /* tcpwm.line[4] */
    TRIG4_IN_TCPWM_LINE5            = 0x0000041Eu, /* tcpwm.line[5] */
    TRIG4_IN_TCPWM_LINE6            = 0x0000041Fu, /* tcpwm.line[6] */
    TRIG4_IN_TCPWM_LINE7            = 0x00000420u, /* tcpwm.line[7] */
    TRIG4_IN_PASS0_DSI_SAR_SAMPLE_DONE = 0x00000421u, /* pass[0].dsi_sar_sample_done */
    TRIG4_IN_PASS0_TR_SAR_OUT       = 0x00000422u, /* pass[0].tr_sar_out */
    TRIG4_IN_PASS0_DSI_CTB_CMP0     = 0x00000423u, /* pass[0].dsi_ctb_cmp0 */
    TRIG4_IN_PASS0_DSI_CTB_CMP1     = 0x00000424u, /* pass[0].dsi_ctb_cmp1 */
    TRIG4_IN_LPCOMP_COMP_OUT0       = 0x00000425u, /* lpcomp.comp_out[0] */
    TRIG4_IN_LPCOMP_COMP_OUT1       = 0x00000426u /* lpcomp.comp_out[1] */
} en_trig_input_grp4_t;

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
    TRIG0_OUT_CPUSS_DMAC_TR_IN7     = 0x40000007u /* cpuss.dmac_tr_in[7] */
} en_trig_output_grp0_t;

/* Trigger Output Group 1 - DMA Request Assignments, channels 8-15 */
typedef enum
{
    TRIG1_OUT_CPUSS_DMAC_TR_IN8     = 0x40000100u, /* cpuss.dmac_tr_in[8] */
    TRIG1_OUT_CPUSS_DMAC_TR_IN9     = 0x40000101u, /* cpuss.dmac_tr_in[9] */
    TRIG1_OUT_CPUSS_DMAC_TR_IN10    = 0x40000102u, /* cpuss.dmac_tr_in[10] */
    TRIG1_OUT_CPUSS_DMAC_TR_IN11    = 0x40000103u, /* cpuss.dmac_tr_in[11] */
    TRIG1_OUT_CPUSS_DMAC_TR_IN12    = 0x40000104u, /* cpuss.dmac_tr_in[12] */
    TRIG1_OUT_CPUSS_DMAC_TR_IN13    = 0x40000105u, /* cpuss.dmac_tr_in[13] */
    TRIG1_OUT_CPUSS_DMAC_TR_IN14    = 0x40000106u, /* cpuss.dmac_tr_in[14] */
    TRIG1_OUT_CPUSS_DMAC_TR_IN15    = 0x40000107u /* cpuss.dmac_tr_in[15] */
} en_trig_output_grp1_t;

/* Trigger Output Group 2 - USB Trigger Burst End assignment */
typedef enum
{
    TRIG2_OUT_USB_DMA_BURSTEND0     = 0x40000200u, /* usb.dma_burstend[0] */
    TRIG2_OUT_USB_DMA_BURSTEND1     = 0x40000201u, /* usb.dma_burstend[1] */
    TRIG2_OUT_USB_DMA_BURSTEND2     = 0x40000202u, /* usb.dma_burstend[2] */
    TRIG2_OUT_USB_DMA_BURSTEND3     = 0x40000203u, /* usb.dma_burstend[3] */
    TRIG2_OUT_USB_DMA_BURSTEND4     = 0x40000204u, /* usb.dma_burstend[4] */
    TRIG2_OUT_USB_DMA_BURSTEND5     = 0x40000205u, /* usb.dma_burstend[5] */
    TRIG2_OUT_USB_DMA_BURSTEND6     = 0x40000206u, /* usb.dma_burstend[6] */
    TRIG2_OUT_USB_DMA_BURSTEND7     = 0x40000207u /* usb.dma_burstend[7] */
} en_trig_output_grp2_t;

/* Trigger Output Group 3 - Trigger sources for TCPWM */
typedef enum
{
    TRIG3_OUT_TCPWM_TR_IN8          = 0x40000300u, /* tcpwm.tr_in[8] */
    TRIG3_OUT_TCPWM_TR_IN9          = 0x40000301u, /* tcpwm.tr_in[9] */
    TRIG3_OUT_TCPWM_TR_IN10         = 0x40000302u, /* tcpwm.tr_in[10] */
    TRIG3_OUT_TCPWM_TR_IN11         = 0x40000303u, /* tcpwm.tr_in[11] */
    TRIG3_OUT_TCPWM_TR_IN12         = 0x40000304u, /* tcpwm.tr_in[12] */
    TRIG3_OUT_TCPWM_TR_IN13         = 0x40000305u /* tcpwm.tr_in[13] */
} en_trig_output_grp3_t;

/* Trigger Output Group 4 - Trigger sources for PASS */
typedef enum
{
    TRIG4_OUT_PASS0_TR_SAR_IN       = 0x40000400u /* pass[0].tr_sar_in */
} en_trig_output_grp4_t;

/* Include IP definitions */
#include "ip/cyip_sflash_256.h"
#include "ip/cyip_peri.h"
#include "ip/cyip_hsiom.h"
#include "ip/cyip_srsslt.h"
#include "ip/cyip_gpio.h"
#include "ip/cyip_cpuss_v5.h"
#include "ip/cyip_dmac_v5.h"
#include "ip/cyip_spcif_v5.h"
#include "ip/cyip_tcpwm_v2.h"
#include "ip/cyip_scb_v2.h"
#include "ip/cyip_csd_v2.h"
#include "ip/cyip_lpcomp_v2.h"
#include "ip/cyip_usbfs_v2.h"
#include "ip/cyip_cryptolite.h"
#include "ip/cyip_ctbm_v2.h"
#include "ip/cyip_sar_v2.h"
#include "ip/cyip_pass_v2.h"

/* Parameter Defines */
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
#define CPUSS_ROM_SIZE                  96u
/* Product has ROM available for system usage (1) or not (0) */
#define CPUSS_SYSTEM_ROM                1u
/* Boot ROM available (1) or all classified as System Rom (0) */
#define CPUSS_ROMC_BOOT_ROM_PRESENT     1u
/* Boot ROM partition size */
#define CPUSS_BOOT_ROM_SIZE             8u
/* Number of external slave ports on System Interconnect */
#define CPUSS_SL_NR                     3u
/* Flash memory present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_FLASHC_PRESENT            1u
/* Flash size in kilobytes */
#define CPUSS_FLASH_SIZE                256u
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
#define CPUSS_BIST_FULL                 0u
/* Number of external SRAMs connected to the CPUSS BIST controller */
#define CPUSS_BIST_EXT_SRAM_NR          11u
/* Number of SRAMs connected to the CPUSS BIST controller (BIST_EXT_SRAM_NR+4) */
#define CPUSS_BIST_SRAM_NR              15u
/* CoreSight Part Identification Number */
#define CPUSS_JEPID                     52u
/* CoreSight Part Identification Number */
#define CPUSS_JEPCONTINUATION           0u
/* CoreSight Part Identification Number */
#define CPUSS_PARTNUMBER                197u
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
#define CPUSS_CELL_VT_TYPE              0u
/* External Master M1 Present (Note either DMA_PRESENT or EXT_MS_PRESENT must also
   be set) */
#define CPUSS_EXT_MS1_PRESENT           1u
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
/* Flash type is FMLT or S8FS */
#define CPUSS_SPCIF_FMLT_OR_S8FS        1u
/* Product uses FLASH-Lite (1) or regular FLASH (0) */
#define CPUSS_SPCIF_FMLT                0u
/* Using regular flash (=1-FMLT) */
#define CPUSS_SPCIF_FM                  0u
/* Total Flash size in multiples of 256 bytes (0=1x256, 1=2x256, ...) */
#define CPUSS_SPCIF_FLASH_SIZE          1023u
/* The Flash read word width in bits (32, 64 or 128) */
#define CPUSS_SPCIF_FLASH_READ_WIDTH    64u
/* Total Supervisory Flash size in multiples of 256 bytes (0=1x256, 1=2x256, ...) */
#define CPUSS_SPCIF_SFLASH_SIZE         15u
/* Flash program/erase page size (0=64, 1=128 or 3=256 bytes) */
#define CPUSS_SPCIF_FLASH_PAGE_SIZE     3u
/* Number of Flash macros used in the device (0, 1 or 2) */
#define CPUSS_SPCIF_FLASH_MACROS        2u
/* Number of Flash macros minus 1 */
#define CPUSS_SPCIF_FLASH_MACROS_MINUS1 1u
/* Flash macro #1 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_1       1u
/* Flash macro #2 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_2       0u
/* Flash macro #3 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_3       0u
/* SPCIF Timer clock is synchronous (1) or asynchronous (0) to clk_sys */
#define CPUSS_SPCIF_SYNCHRONOUS         1u
/* NVLatches present (0=No, 1=Yes) */
#define CPUSS_SPCIF_NVLATCH             0u
/* NVLatches size in bytes (default=8) */
#define CPUSS_SPCIF_NVLATCH_SIZE        8u
/* HOBTO-M ULL65 SRAM/SROM required */
#define CPUSS_SPCIF_ULL65               0u
/* Flash memory present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_SPCIF_FLASHC_PRESENT      1u
/* Flash type (0=FM, 1=FMLT, 2=FS, 3=FSLT) */
#define CPUSS_SPCIF_FLASH_TYPE          3u
/* IP MMIO registers base address in the system address space (32-bit Byte address
   at a 64 kB multiple). The IP MMIO registers occupy a 64 kB memory region in
   the system address space. */
#define CRYPTOLITE_ADDR_BASE            0x402D0000u
/* ECC present or not ('0': no, '1': yes). */
#define CRYPTOLITE_ECC_PRESENT          0u
/* True random number generation component support ('0': no, '1': yes). */
#define CRYPTOLITE_TRNG_PRESENT         1u
/* Vector unit component support ('0': no, '1': yes). */
#define CRYPTOLITE_VU_PRESENT           1u
/* SHA-256 hash component support ('0': no, '1': yes). */
#define CRYPTOLITE_SHA_PRESENT          1u
/* AES-128 block cipher component support ('0': no, '1': yes). */
#define CRYPTOLITE_AES_PRESENT          1u
/* Support for OR'ed interrupt ('0': no, '1': yes). */
#define CRYPTOLITE_INTR_ORED            1u
/* Use 9.6uA current Reference for IDACs. */
#define CSD_REF9P6UA_EN                 1u
/* Spare Enable 0=no spare, 1=max, 2=min */
#define CSD_SPARE_EN                    1u
/* Std Lib Config 1=scs8ls, 2=scs8hd, 3=scs8hv(invalid), others=reserved */
#define CSD_SPARE_STDLIB_CFG            2u
/* IOSS PHASE */
#define IOSS_IOSS_PHASE                 5u
/* Route REFGEN vinref & voutref to AMUX bus when set */
#define IOSS_SIO_REF_HOOKUP             0u
/* Use 1.8V signaling on XRES (Xres4 cell only) */
#define IOSS_USE_1P8V_SIGNALING_XRES4   0u
/* Number of ports in device */
#define IOSS_GPIO_GPIO_PORT_NR          9u
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
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
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
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
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
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
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
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_OVT 1u
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
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
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
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
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
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
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
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO 0u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_AUX 1u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_FILTER_EN7 0u
/* Control register to improve IO testing */
#define IOSS_GPIO_IO_TEST_CTL           1u
/* GPIO_V1P2 cells used ? */
#define IOSS_GPIO_IO_GPIOV1P2           0u
/* Is there a pump in IOSS ? (same as GLOBAL.HAS_PUMP_IN_IOSS) */
#define IOSS_HSIOM_PUMP                 0u
/* Number of AMUX splitter cells */
#define IOSS_HSIOM_AMUX_SPLIT_NR        3u
/* Number of HSIOM ports in device (same as GPIO.GPIO_PRT_NR) */
#define IOSS_HSIOM_HSIOM_PORT_NR        9u
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
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO7 0u
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
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO7 0u
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
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR6_HSIOM_PRT_IO5 0u
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
#define IOSS_HSIOM_HSIOM_PORT_NR7_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR8_HSIOM_PRT_IO7 0u
/* Number of PRGIO instances (in 8b ports) */
#define IOSS_PRGIO_PRGIO_NR             0u
/* Spare Enable 0=no spare, 1=max, 2=min */
#define LPCOMP_SPARE_EN                 0u
/* Std Lib Config 1=scs8ls, 2=scs8hd, 3=scs8hv(invalid), others=reserved */
#define LPCOMP_SPARE_STDLIB_CFG         2u
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
#define PERI_PCLK_CLOCK_NR              32u
/* Number of 8.0 dividers */
#define PERI_PCLK_DIV_8_NR              12u
/* Number of 16.0 dividers */
#define PERI_PCLK_DIV_16_NR             4u
/* Number of 16.5 (fractional) dividers */
#define PERI_PCLK_DIV_16_5_NR           5u
/* Number of 24.5 (fractional) dividers */
#define PERI_PCLK_DIV_24_5_NR           0u
/* Divider number width: max(1,roundup(log2(max(DIV_*_NR))) */
#define PERI_PCLK_DIV_ADDR_WIDTH        4u
/* Trigger module present (0=No, 1=Yes) */
#define PERI_TR                         1u
/* Number of trigger groups */
#define PERI_TR_GROUP_NR                5u
/* Number of input triggers */
#define PERI_TR_GROUP_NR0_TR_GROUP_TR_IN_NR 55u
/* Number of output triggers */
#define PERI_TR_GROUP_NR0_TR_GROUP_TR_OUT_NR 8u
/* Input trigger number width: roundup(log2(TR_IN_NR)) */
#define PERI_TR_GROUP_NR0_TR_GROUP_TR_IN_ADDR_WIDTH 6u
/* Number of input triggers */
#define PERI_TR_GROUP_NR1_TR_GROUP_TR_IN_NR 17u
/* Number of output triggers */
#define PERI_TR_GROUP_NR1_TR_GROUP_TR_OUT_NR 8u
/* Input trigger number width: roundup(log2(TR_IN_NR)) */
#define PERI_TR_GROUP_NR1_TR_GROUP_TR_IN_ADDR_WIDTH 5u
/* Number of input triggers */
#define PERI_TR_GROUP_NR2_TR_GROUP_TR_IN_NR 9u
/* Number of output triggers */
#define PERI_TR_GROUP_NR2_TR_GROUP_TR_OUT_NR 8u
/* Input trigger number width: roundup(log2(TR_IN_NR)) */
#define PERI_TR_GROUP_NR2_TR_GROUP_TR_IN_ADDR_WIDTH 4u
/* Number of input triggers */
#define PERI_TR_GROUP_NR3_TR_GROUP_TR_IN_NR 45u
/* Number of output triggers */
#define PERI_TR_GROUP_NR3_TR_GROUP_TR_OUT_NR 6u
/* Input trigger number width: roundup(log2(TR_IN_NR)) */
#define PERI_TR_GROUP_NR3_TR_GROUP_TR_IN_ADDR_WIDTH 6u
/* Number of input triggers */
#define PERI_TR_GROUP_NR4_TR_GROUP_TR_IN_NR 39u
/* Number of output triggers */
#define PERI_TR_GROUP_NR4_TR_GROUP_TR_OUT_NR 1u
/* Input trigger number width: roundup(log2(TR_IN_NR)) */
#define PERI_TR_GROUP_NR4_TR_GROUP_TR_IN_ADDR_WIDTH 6u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB0_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB0_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB0_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB0_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB0_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB0_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB0_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB0_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB0_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB0_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB0_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB0_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB0_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB0_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB0_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB0_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB0_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB0_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB0_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB0_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB0_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB0_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB0_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB0_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB0_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB0_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB0_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB0_SPARE_STDLIB_CFG           2u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB1_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB1_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB1_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB1_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB1_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB1_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB1_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB1_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB1_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB1_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB1_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB1_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB1_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB1_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB1_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB1_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB1_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB1_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB1_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB1_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB1_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB1_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB1_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB1_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB1_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB1_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB1_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB1_SPARE_STDLIB_CFG           2u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB2_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB2_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB2_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB2_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB2_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB2_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB2_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB2_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB2_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB2_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB2_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB2_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB2_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB2_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB2_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB2_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB2_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB2_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB2_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB2_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB2_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB2_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB2_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB2_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB2_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB2_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB2_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB2_SPARE_STDLIB_CFG           2u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB3_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB3_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB3_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB3_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB3_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB3_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB3_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB3_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB3_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB3_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB3_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB3_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB3_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB3_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB3_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB3_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB3_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB3_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB3_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB3_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB3_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB3_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB3_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB3_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB3_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB3_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB3_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB3_SPARE_STDLIB_CFG           2u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB4_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB4_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB4_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB4_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB4_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB4_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB4_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB4_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB4_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB4_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB4_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB4_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB4_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB4_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB4_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB4_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB4_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB4_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB4_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB4_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB4_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB4_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB4_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB4_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB4_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB4_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB4_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB4_SPARE_STDLIB_CFG           2u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB5_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB5_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB5_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB5_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB5_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB5_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB5_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB5_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB5_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB5_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB5_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB5_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB5_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB5_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB5_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB5_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB5_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB5_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB5_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB5_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB5_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB5_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB5_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB5_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB5_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB5_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB5_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB5_SPARE_STDLIB_CFG           2u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB6_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB6_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB6_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB6_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB6_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB6_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB6_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB6_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB6_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB6_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB6_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB6_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB6_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB6_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB6_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB6_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB6_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB6_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB6_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB6_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB6_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB6_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB6_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB6_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB6_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB6_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB6_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB6_SPARE_STDLIB_CFG           2u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB7_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB7_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB7_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB7_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB7_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB7_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB7_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB7_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB7_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB7_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB7_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB7_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB7_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB7_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB7_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB7_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB7_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB7_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB7_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB7_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB7_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB7_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB7_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB7_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB7_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB7_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB7_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB7_SPARE_STDLIB_CFG           2u
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
/* Does this product include BLEDMA256_REVC ? */
#define SFLASH_HAS_BLEDMA256_REVC       0u
/* Does this product include CSD (m0s8csd) ? */
#define SFLASH_HAS_CSDV2                1u
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
/* Is the device PSoC4AL with Copper? */
#define SFLASH_IS_PSOC4AL_CU            0u
/* Does the product include Atlas PLL (s8atlasana) */
#define SFLASH_HAS_ATLAS_PLL            0u
/* Does this product use SRSSv2 ? */
#define SFLASH_SRSSV2                   0u
/* Does this product use SRSS-Lite ? */
#define SFLASH_SRSSLT                   1u
/* Does this product use 2 FLASH macros or more ? */
#define SFLASH_HAS_2FM                  1u
/* Does this product use 3 FLASH macros or more ? */
#define SFLASH_HAS_3FM                  0u
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
#define SRSSLT_HAS_VDDIO_PAD            1u
/* Number of counters per IP (1..8) */
#define TCPWM_CNT_NR                    8u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define TCPWM_SPARE_EN                  2u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define TCPWM_SPARE_STDLIB_CFG          2u
/* Battery Charging Detection present (1) or not (0) */
#define USBDEVv2_USB_USB_CHGDET         0u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define USBDEVv2_USB_SPARE_EN           2u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define USBDEVv2_USB_SPARE_STDLIB_CFG   2u
/* Product uses SRSS-Lite (1) or SRSSv2 (0) - used to connect SRAM
   powerdown/retain */
#define USBDEVv2_USB_SRSSLT             1u
/* VBUS power pad cell present (1) or not (0) */
#define USBDEVv2_USB_VBUS_PAD_EN        0u
/* s8usbfsm0s8_top iec cell (1) or s8usbfsm0s8_top cell (0) */
#define USBDEVv2_USB_IEC_EN             1u
/* VBUS Leaker cell present (1) or not (0) */
#define USBDEVv2_USB_BLEEDER_EN         0u
/* Enable CCG3PA related trim registers */
#define USBPD0_CCG3PA_EN                0u
/* Enable CCG5 related trim registers */
#define USBPD0_CCG5_EN                  0u
/* Enable CCG3PA2 related trim registers */
#define USBPD0_CCG3PA2_EN               0u
/* Enable CMG1 related trim registers */
#define USBPD0_CMG1_EN                  0u
/* Enable CCG6 related trim registers */
#define USBPD0_CCG6_EN                  0u
/* Enable CCG2B related trim registers */
#define USBPD0_CCG2B_EN                 0u
/* Enable PAG1S_EN related trim registers */
#define USBPD0_PAG1S_EN                 0u
/* Enable ACG1F_EN related trim registers */
#define USBPD0_ACG1F_EN                 0u
/* Enable CCG6DF_EN related trim registers */
#define USBPD0_CCG6DF_EN                0u
/* Enable CCG7D_EN related trim registers */
#define USBPD0_CCG7D_EN                 0u
/* Enable PMG1S3_EN related trim registers */
#define USBPD0_PMG1S3_EN                1u
/* Enable CCG6 related trim registers */
#define USBPD0_AGNOSTIC_phase8_CCG6_EN  0u
/* Enable ACG1F_EN related trim registers */
#define USBPD0_AGNOSTIC_phase8_ACG1F_EN 0u
/* Enable CCG6DF_EN related trim registers */
#define USBPD0_AGNOSTIC_phase8_CCG6DF_EN 0u
/* ACG1F or CCG6DF enable */
#define USBPD0_AGNOSTIC_phase8_ACG1F_CCG6DF_EN 1u
/* PASC or CCG6DF enable */
#define USBPD0_AGNOSTIC_phase8_PASC_CCG6DF_EN 0u
/* SRAM_EN (1:Yes, 0:No) */
#define USBPD0_AGNOSTIC_phase8_SRAM_EN  1u
/* USBPD Number of Instances (0=1 instance, 1= 2 instances) */
#define USBPD0_AGNOSTIC_phase8_INSTANCE_NUM 0u
/* Spare cell Library selection 1=LS,2=HD,3=HV */
#define USBPD0_AGNOSTIC_phase8_SPARE_STDLIB_CFG 2u
/* Spare Cell Enable */
#define USBPD0_AGNOSTIC_phase8_SPARE_EN 1u
/* USBPD function enable */
#define USBPD0_AGNOSTIC_phase8_PD_EN    1u
/* LF counter enable */
#define USBPD0_AGNOSTIC_phase8_LF_CNTR_EN 1u
/* Number of USBPD AMUX NHVN hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_USB_AMUX_NHVN_NUM 0u
/* Enable function/related registers of PAG1S/next-gen products */
#define USBPD0_AGNOSTIC_phase8_PASC_EN  0u
/* Enable VBUS transition control logic */
#define USBPD0_AGNOSTIC_phase8_VBTR_EN  0u
/* 0: Use TX_HEADER register for GoodCRC Expected Header 1: Use
   RX_EXPECT_GOODCRC_MSG.EXPECTED_HEADER register for GoodCRC Expected Header */
#define USBPD0_AGNOSTIC_phase8_NOT_USE_TX_HEADER 1u
/* 0: Use RX_ORDER_SET_CTRL register for TX_SOP Order Set 1: Use TX_SOP_ORDER_SET
   register for TX_SOP Order Set */
#define USBPD0_AGNOSTIC_phase8_NOT_USE_RX_ORDER_SET 1u
/* Hardware handles the TX Specification Revsion field */
#define USBPD0_AGNOSTIC_phase8_SPEC_REV_EN 0u
/* Hardware handles the TX mesageID field */
#define USBPD0_AGNOSTIC_phase8_MSG_ID_EN 0u
/* Keep specific register bits or use their default to reduce gate count */
#define USBPD0_AGNOSTIC_phase8_KEEP_REG_BIT 1u
/* High speed filter enabled */
#define USBPD0_AGNOSTIC_phase8_HS_CLK_FILT_EN 1u
/* Extended data message function enabled */
#define USBPD0_AGNOSTIC_phase8_EXT_DATA_MSG_EN 1u
/* RPRD function enabled */
#define USBPD0_AGNOSTIC_phase8_RPRD_EN  1u
/* Swap function enabled */
#define USBPD0_AGNOSTIC_phase8_SWAP_EN  1u
/* HPD function enabled */
#define USBPD0_AGNOSTIC_phase8_HPD_EN   1u
/* Fault GPIO logic enabled */
#define USBPD0_AGNOSTIC_phase8_FAULT_GPIO_EN 0u
/* Extra Fault GPIO logic enabled */
#define USBPD0_AGNOSTIC_phase8_FAULT_GPIO_EN_EXTR 1u
/* CC1 Interrupt enabled */
#define USBPD0_AGNOSTIC_phase8_CC1_INTR_EN 1u
/* CC2 Interrupt enabled */
#define USBPD0_AGNOSTIC_phase8_CC2_INTR_EN 1u
/* VCMP UP Interrupt enabled */
#define USBPD0_AGNOSTIC_phase8_VCMP_UP_INTR_EN 1u
/* VCMP DN Interrupt enabled */
#define USBPD0_AGNOSTIC_phase8_VCMP_DN_INTR_EN 1u
/* VCMP LA Interrupt enabled */
#define USBPD0_AGNOSTIC_phase8_VCMP_LA_INTR_EN 1u
/* GPIO DDFT enabled */
#define USBPD0_AGNOSTIC_phase8_GPIO_DDFT_EN 1u
/* GPIO INTR DDFT enabled */
#define USBPD0_AGNOSTIC_phase8_GPIO_INTR_DDFT_EN 1u
/* NCELL DDFT enabled */
#define USBPD0_AGNOSTIC_phase8_NCELL_DDFT_EN 1u
/* TCPWM Trigger enabled */
#define USBPD0_AGNOSTIC_phase8_TCPWM_TRIGGER_EN 1u
/* Interrupt SET function enabled */
#define USBPD0_AGNOSTIC_phase8_INTR_SET_EN 1u
/* Interrupt MASKED function enabled */
#define USBPD0_AGNOSTIC_phase8_INTR_MASKED_EN 1u
/* Bypass function enable */
#define USBPD0_AGNOSTIC_phase8_BYPASS_MODE_EN 1u
/* Enable the following registers: RX_SOP_GOOD_CRC_EN_CTRL, */
#define USBPD0_AGNOSTIC_phase8_RX_SOP_CTRL_EN 0u
/* Enabling the HPD RX input selection */
#define USBPD0_AGNOSTIC_phase8_HPD_IN_MUX_EN 1u
/* Number of comparator hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_COMP_NUM 5u
/* Number of comparator with trim hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_COMP_TR_NUM 0u
/* Number of USBPD AMUX hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_USB_AMUX_NUM 0u
/* Number of USBPD AMUX NHV hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_USB_AMUX_NHV_NUM 6u
/* Number of USBPD AMUX DENFET hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_USB_AMUX_DENFET_NUM 1u
/* Total number of CLK_FILTER Filter */
#define USBPD0_AGNOSTIC_phase8_CLK_FILTER_FILT_NUM 3u
/* Total number of CLK_FILTER 1-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_CLK_FILTER_LOG1 3u
/* Total number of CLK_FILTER 12-bit Lower CFG bits */
#define USBPD0_AGNOSTIC_phase8_CLK_FILTER_FILT_NUM_LOG1_12 3u
/* Total number of CLK_FILTER 12-bit Upper CFG bits */
#define USBPD0_AGNOSTIC_phase8_CLK_FILTER_FILT_NUM_LOG2_12 0u
/* Total number of CLK_LF Filter */
#define USBPD0_AGNOSTIC_phase8_CLK_LF_FILT_NUM 3u
/* Number of RDIV_SHV Hard IP cell */
#define USBPD0_AGNOSTIC_phase8_RDIV_NUM 0u
/* Total number of RDIV ADFT CTRL bits */
#define USBPD0_AGNOSTIC_phase8_RDIV_NUM_LOG3 0u
/* Number of s8usbpd_det_shv_top hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_DET_SHV_NUM 0u
/* Total number of Det SHV 1-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_DET_SHV_NUM_LOG1 0u
/* Total number of Det SHV two-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_DET_SHV_NUM_LOG2 0u
/* Total number of Det SHV three-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_DET_SHV_NUM_LOG3 0u
/* Number of s8usbpd_shvreg_top Regulator hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_SHVREG_NUM 0u
/* Total number of SHV 1-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_SHVREG_NUM_LOG1 0u
/* Total number of SHV two-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_SHVREG_NUM_LOG2 0u
/* Total number of SHV three-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_SHVREG_NUM_LOG3 0u
/* Number of Error Amplifier hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_EA_NUM   0u
/* Number of LSCSA hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_LSCSA_NUM 0u
/* Number of RefGen hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_REFGEN_NUM 1u
/* Number of Internal/External P-Gate Driver is instantiated */
#define USBPD0_AGNOSTIC_phase8_PGDO_NUM 0u
/* Number of Internal/External P-Gate Driver with Pull-Up is instantiated */
#define USBPD0_AGNOSTIC_phase8_PGDO_PU_NUM 0u
/* Number of Internal/External P-Gate Driver with Pull-Up is instantiated extra
   Register */
#define USBPD0_AGNOSTIC_phase8_PGDO_PU_NUM_EXTR 0u
/* s8usbpd_pgdo_pd_isnk_top is instantiated (0=No, 1=Yes) */
#define USBPD0_AGNOSTIC_phase8_PGDO_PD_ISNK_EN 0u
/* Enable higher resolution of the Value for PGDO PD ISNK (0=No, 1=Yes) */
#define USBPD0_AGNOSTIC_phase8_PGDO_ISNK_H_RES_EN 0u
/* Number of Discharge hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_DISCHG_NUM 1u
/* Number of Discharge hard IP + Protection Logic is instantiated */
#define USBPD0_AGNOSTIC_phase8_DISCHG_PROT_NUM 0u
/* Number of s8usbpd_vconn_sw_shv_small_top */
#define USBPD0_AGNOSTIC_phase8_SMALL_VCONN_NUM 0u
/* Total number of Small Vconn two-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_SMALL_VCONN_NUM_LOG2 0u
/* Total number of Small Vconn three-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_SMALL_VCONN_NUM_LOG3 0u
/* Enable two s8usbpd_vconn_sw_1vconn_shv_top */
#define USBPD0_AGNOSTIC_phase8_TWO_VCONN_EN 0u
/* ONE_VCONN_EN OR TWO_VCONN_EN */
#define USBPD0_AGNOSTIC_phase8_VCONN_EN 0u
/* VCONN 20V enabled? */
#define USBPD0_AGNOSTIC_phase8_VCONN20_EN 1u
/* Enable one s8usbpd 300ma_sw_top */
#define USBPD0_AGNOSTIC_phase8_FET_300_EN 0u
/* V5V is enabled */
#define USBPD0_AGNOSTIC_phase8_V5V_EN   1u
/* Enable s8usbpd_cc_shvt_top */
#define USBPD0_AGNOSTIC_phase8_CC_SHVT_EN 1u
/* Enable s8usbpd_cc_shvt_cabl_top */
#define USBPD0_AGNOSTIC_phase8_CC_SHVT_CABLE_EN 0u
/* Enable s8usbpd_cc_ufp_nord_top */
#define USBPD0_AGNOSTIC_phase8_CC_UFP_NORD_EN 0u
/* Enable s8usbpd_cc_dfp_notxrx_top */
#define USBPD0_AGNOSTIC_phase8_CC_DFP_NOTXRX_EN 0u
/* s8usbpd current/voltage reference capable (0=No, 1=Yes) */
#define USBPD0_AGNOSTIC_phase8_DPSLP_REF_EN 1u
/* s8usbpd pump capable (0=No, 1=Yes) */
#define USBPD0_AGNOSTIC_phase8_CPUMP_EN 0u
/* Number of s8usbpd2 5vpump The V5PUMP_NUM indiates the total s8usbpd2 5vpump
   regardless of the V5PUMP_EN value */
#define USBPD0_AGNOSTIC_phase8_V5PUMP_NUM 2u
/* Number of ADC hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_ADC_NUM  1u
/* Number of s8usbpd_chgdet_afc_top/s8pds_chgdet_afc_top */
#define USBPD0_AGNOSTIC_phase8_BCH_DET_NUM 1u
/* Total number of Battery Charger two-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_BCH_DET_NUM_LOG2 2u
/* Total number of Battery Charger three-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_BCH_DET_NUM_LOG3 3u
/* Number of s8usbpd_chgdet_top */
#define USBPD0_AGNOSTIC_phase8_CHGDET_NUM 0u
/* Total number of Charger 1-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_CHGDET_NUM_LOG1 0u
/* Total number of Charger two-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_CHGDET_NUM_LOG2 0u
/* Total number of Charger three-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_CHGDET_NUM_LOG3 0u
/* Number of Internal/External N-Gate Driver is instantiated */
#define USBPD0_AGNOSTIC_phase8_NGDO_NUM 0u
/* Number of SBU Switch is instantiated */
#define USBPD0_AGNOSTIC_phase8_SBU_NUM  1u
/* Number of SBU Switches instantiated */
#define USBPD0_AGNOSTIC_phase8_SBU20_NUM 0u
/* Total number of SBU20 two-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_SBU20_NUM_LOG2 0u
/* Number of DPDM Switches instantiated */
#define USBPD0_AGNOSTIC_phase8_DPDM_NUM 0u
/* CCG6 or CCG6DF DPDM Enabled */
#define USBPD0_AGNOSTIC_phase8_DPDM_CCG6_EN 0u
/* Number of CSA hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_CSA_NUM  0u
/* Total number of CSA one-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_CSA_NUM_LOG1 0u
/* Total number of CSA two-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_CSA_NUM_LOG2 0u
/* Total number of CSA three-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_CSA_NUM_LOG3 0u
/* One CSA SCP hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_CSA_SCP_EN 1u
/* One CSA RCP hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_CSA_RCP_EN 1u
/* CSA SCP or CSA RCP hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_CSA_SCP_RCP_EN 1u
/* VSYS Enabled (s8usbpd_vddd_sw_top is instantiated) */
#define USBPD0_AGNOSTIC_phase8_VSYS_EN  1u
/* Number of s8usbpd_20vreg_top Regulator hard IP is instantiated */
#define USBPD0_AGNOSTIC_phase8_VREG20_NUM 1u
/* Total number of VREG20 one-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_VREG20_NUM_LOG1 1u
/* Total number of VREG20 two-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_VREG20_NUM_LOG2 2u
/* Total number of VREG20 three-bit CFG bits */
#define USBPD0_AGNOSTIC_phase8_VREG20_NUM_LOG3 3u
/* First SHV regulator instatiated */
#define USBPD0_AGNOSTIC_phase8_REGULATOR1_EN 0u
/* Second SHV regulator instatiated */
#define USBPD0_AGNOSTIC_phase8_REGULATOR2_EN 0u
/* Third SHV regulator instatiated */
#define USBPD0_AGNOSTIC_phase8_REGULATOR3_EN 0u
/* Forth SHV regulator instatiated */
#define USBPD0_AGNOSTIC_phase8_REGULATOR4_EN 0u
/* First 20V regulator instatiated */
#define USBPD0_AGNOSTIC_phase8_REGULATOR20_1_EN 1u
/* Second 20V regulator instatiated */
#define USBPD0_AGNOSTIC_phase8_REGULATOR20_2_EN 0u
/* Third 20V regulator instatiated */
#define USBPD0_AGNOSTIC_phase8_REGULATOR20_3_EN 0u
/* Forth 20V regulator instatiated */
#define USBPD0_AGNOSTIC_phase8_REGULATOR20_4_EN 0u
/* Regulator control is enabled (s8usbpd_reg_control_top is intantiated) */
#define USBPD0_AGNOSTIC_phase8_REG_CONTROL_EN 1u
/* Enable CCG7D_EN related registers */
#define USBPD0_AGNOSTIC_phase8_CCG7D_EN 0u
/* Enable CCG7D_EN related registers for Instance 0 only */
#define USBPD0_AGNOSTIC_phase8_CCG7D_EN_INST_ZERO 0u
/* Enable Battery to Ground protection */
#define USBPD0_AGNOSTIC_phase8_BAT2GND_EN 0u
/* Enable function/related registers of PD Buck Boost Controller/next-gen products */
#define USBPD0_AGNOSTIC_phase8_PDBBC_EN 0u
/* Enable IBUS transition contol logic */
#define USBPD0_AGNOSTIC_phase8_IBTR_EN  0u
/* PASC or CCG7D Enable */
#define USBPD0_AGNOSTIC_phase8_PASC_CCG7D_EN 0u
/* PASC or CCG6DF or CCG7D Enable */
#define USBPD0_AGNOSTIC_phase8_PASC_CCG6DF_CCG7D_EN 0u
/* CCG6 or CCG7D Enable */
#define USBPD0_AGNOSTIC_phase8_CCG6_CCG7D_EN 0u
/* Enable PMG1S3_EN related registers */
#define USBPD0_AGNOSTIC_phase8_PMG1S3_EN 1u
/* Enable CCG6DF or PMG1S3 related registers */
#define USBPD0_AGNOSTIC_phase8_CCG6DF_PMG1S3_EN 1u
/* Enable Digital Flip Mux */
#define USBPD0_AGNOSTIC_phase8_FMX_EN   1u
/* Enable PMG1S3_EN related registers */
#define USBPD0_AGNOSTIC_phase8_ACG1F_PMG1S3_EN 1u
/* Enable RAMBIST Muxing Logic */
#define USBPD0_AGNOSTIC_phase8_RBM_EN   1u
/* Enable Scan Bypass Logic */
#define USBPD0_AGNOSTIC_phase8_SCBYP_EN 1u
/* Number of New SBU Mux (s8usbpdv2_pmg1s3 _sbu_sw_top) and related Registers */
#define USBPD0_AGNOSTIC_phase8_SBU_NEW_NUM 2u
/* Enable CCG3PA related trim registers */
#define USBPD1_CCG3PA_EN                0u
/* Enable CCG5 related trim registers */
#define USBPD1_CCG5_EN                  0u
/* Enable CCG3PA2 related trim registers */
#define USBPD1_CCG3PA2_EN               0u
/* Enable CMG1 related trim registers */
#define USBPD1_CMG1_EN                  0u
/* Enable CCG6 related trim registers */
#define USBPD1_CCG6_EN                  0u
/* Enable CCG2B related trim registers */
#define USBPD1_CCG2B_EN                 0u
/* Enable PAG1S_EN related trim registers */
#define USBPD1_PAG1S_EN                 0u
/* Enable ACG1F_EN related trim registers */
#define USBPD1_ACG1F_EN                 0u
/* Enable CCG6DF_EN related trim registers */
#define USBPD1_CCG6DF_EN                0u
/* Enable CCG7D_EN related trim registers */
#define USBPD1_CCG7D_EN                 0u
/* Enable PMG1S3_EN related trim registers */
#define USBPD1_PMG1S3_EN                1u
/* Enable CCG6 related trim registers */
#define USBPD1_AGNOSTIC_phase8_CCG6_EN  0u
/* Enable ACG1F_EN related trim registers */
#define USBPD1_AGNOSTIC_phase8_ACG1F_EN 0u
/* Enable CCG6DF_EN related trim registers */
#define USBPD1_AGNOSTIC_phase8_CCG6DF_EN 0u
/* ACG1F or CCG6DF enable */
#define USBPD1_AGNOSTIC_phase8_ACG1F_CCG6DF_EN 1u
/* PASC or CCG6DF enable */
#define USBPD1_AGNOSTIC_phase8_PASC_CCG6DF_EN 0u
/* SRAM_EN (1:Yes, 0:No) */
#define USBPD1_AGNOSTIC_phase8_SRAM_EN  1u
/* USBPD Number of Instances (0=1 instance, 1= 2 instances) */
#define USBPD1_AGNOSTIC_phase8_INSTANCE_NUM 1u
/* Spare cell Library selection 1=LS,2=HD,3=HV */
#define USBPD1_AGNOSTIC_phase8_SPARE_STDLIB_CFG 2u
/* Spare Cell Enable */
#define USBPD1_AGNOSTIC_phase8_SPARE_EN 1u
/* USBPD function enable */
#define USBPD1_AGNOSTIC_phase8_PD_EN    1u
/* LF counter enable */
#define USBPD1_AGNOSTIC_phase8_LF_CNTR_EN 1u
/* Number of USBPD AMUX NHVN hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_USB_AMUX_NHVN_NUM 0u
/* Enable function/related registers of PAG1S/next-gen products */
#define USBPD1_AGNOSTIC_phase8_PASC_EN  0u
/* Enable VBUS transition control logic */
#define USBPD1_AGNOSTIC_phase8_VBTR_EN  0u
/* 0: Use TX_HEADER register for GoodCRC Expected Header 1: Use
   RX_EXPECT_GOODCRC_MSG.EXPECTED_HEADER register for GoodCRC Expected Header */
#define USBPD1_AGNOSTIC_phase8_NOT_USE_TX_HEADER 1u
/* 0: Use RX_ORDER_SET_CTRL register for TX_SOP Order Set 1: Use TX_SOP_ORDER_SET
   register for TX_SOP Order Set */
#define USBPD1_AGNOSTIC_phase8_NOT_USE_RX_ORDER_SET 1u
/* Hardware handles the TX Specification Revsion field */
#define USBPD1_AGNOSTIC_phase8_SPEC_REV_EN 0u
/* Hardware handles the TX mesageID field */
#define USBPD1_AGNOSTIC_phase8_MSG_ID_EN 0u
/* Keep specific register bits or use their default to reduce gate count */
#define USBPD1_AGNOSTIC_phase8_KEEP_REG_BIT 1u
/* High speed filter enabled */
#define USBPD1_AGNOSTIC_phase8_HS_CLK_FILT_EN 1u
/* Extended data message function enabled */
#define USBPD1_AGNOSTIC_phase8_EXT_DATA_MSG_EN 1u
/* RPRD function enabled */
#define USBPD1_AGNOSTIC_phase8_RPRD_EN  1u
/* Swap function enabled */
#define USBPD1_AGNOSTIC_phase8_SWAP_EN  1u
/* HPD function enabled */
#define USBPD1_AGNOSTIC_phase8_HPD_EN   1u
/* Fault GPIO logic enabled */
#define USBPD1_AGNOSTIC_phase8_FAULT_GPIO_EN 0u
/* Extra Fault GPIO logic enabled */
#define USBPD1_AGNOSTIC_phase8_FAULT_GPIO_EN_EXTR 1u
/* CC1 Interrupt enabled */
#define USBPD1_AGNOSTIC_phase8_CC1_INTR_EN 1u
/* CC2 Interrupt enabled */
#define USBPD1_AGNOSTIC_phase8_CC2_INTR_EN 1u
/* VCMP UP Interrupt enabled */
#define USBPD1_AGNOSTIC_phase8_VCMP_UP_INTR_EN 1u
/* VCMP DN Interrupt enabled */
#define USBPD1_AGNOSTIC_phase8_VCMP_DN_INTR_EN 1u
/* VCMP LA Interrupt enabled */
#define USBPD1_AGNOSTIC_phase8_VCMP_LA_INTR_EN 1u
/* GPIO DDFT enabled */
#define USBPD1_AGNOSTIC_phase8_GPIO_DDFT_EN 1u
/* GPIO INTR DDFT enabled */
#define USBPD1_AGNOSTIC_phase8_GPIO_INTR_DDFT_EN 1u
/* NCELL DDFT enabled */
#define USBPD1_AGNOSTIC_phase8_NCELL_DDFT_EN 1u
/* TCPWM Trigger enabled */
#define USBPD1_AGNOSTIC_phase8_TCPWM_TRIGGER_EN 1u
/* Interrupt SET function enabled */
#define USBPD1_AGNOSTIC_phase8_INTR_SET_EN 1u
/* Interrupt MASKED function enabled */
#define USBPD1_AGNOSTIC_phase8_INTR_MASKED_EN 1u
/* Bypass function enable */
#define USBPD1_AGNOSTIC_phase8_BYPASS_MODE_EN 1u
/* Enable the following registers: RX_SOP_GOOD_CRC_EN_CTRL, */
#define USBPD1_AGNOSTIC_phase8_RX_SOP_CTRL_EN 0u
/* Enabling the HPD RX input selection */
#define USBPD1_AGNOSTIC_phase8_HPD_IN_MUX_EN 1u
/* Number of comparator hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_COMP_NUM 4u
/* Number of comparator with trim hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_COMP_TR_NUM 0u
/* Number of USBPD AMUX hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_USB_AMUX_NUM 0u
/* Number of USBPD AMUX NHV hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_USB_AMUX_NHV_NUM 5u
/* Number of USBPD AMUX DENFET hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_USB_AMUX_DENFET_NUM 1u
/* Total number of CLK_FILTER Filter */
#define USBPD1_AGNOSTIC_phase8_CLK_FILTER_FILT_NUM 2u
/* Total number of CLK_FILTER 1-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_CLK_FILTER_LOG1 2u
/* Total number of CLK_FILTER 12-bit Lower CFG bits */
#define USBPD1_AGNOSTIC_phase8_CLK_FILTER_FILT_NUM_LOG1_12 2u
/* Total number of CLK_FILTER 12-bit Upper CFG bits */
#define USBPD1_AGNOSTIC_phase8_CLK_FILTER_FILT_NUM_LOG2_12 0u
/* Total number of CLK_LF Filter */
#define USBPD1_AGNOSTIC_phase8_CLK_LF_FILT_NUM 2u
/* Number of RDIV_SHV Hard IP cell */
#define USBPD1_AGNOSTIC_phase8_RDIV_NUM 0u
/* Total number of RDIV ADFT CTRL bits */
#define USBPD1_AGNOSTIC_phase8_RDIV_NUM_LOG3 0u
/* Number of s8usbpd_det_shv_top hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_DET_SHV_NUM 0u
/* Total number of Det SHV 1-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_DET_SHV_NUM_LOG1 0u
/* Total number of Det SHV two-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_DET_SHV_NUM_LOG2 0u
/* Total number of Det SHV three-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_DET_SHV_NUM_LOG3 0u
/* Number of s8usbpd_shvreg_top Regulator hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_SHVREG_NUM 0u
/* Total number of SHV 1-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_SHVREG_NUM_LOG1 0u
/* Total number of SHV two-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_SHVREG_NUM_LOG2 0u
/* Total number of SHV three-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_SHVREG_NUM_LOG3 0u
/* Number of Error Amplifier hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_EA_NUM   0u
/* Number of LSCSA hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_LSCSA_NUM 0u
/* Number of RefGen hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_REFGEN_NUM 1u
/* Number of Internal/External P-Gate Driver is instantiated */
#define USBPD1_AGNOSTIC_phase8_PGDO_NUM 0u
/* Number of Internal/External P-Gate Driver with Pull-Up is instantiated */
#define USBPD1_AGNOSTIC_phase8_PGDO_PU_NUM 0u
/* Number of Internal/External P-Gate Driver with Pull-Up is instantiated extra
   Register */
#define USBPD1_AGNOSTIC_phase8_PGDO_PU_NUM_EXTR 0u
/* s8usbpd_pgdo_pd_isnk_top is instantiated (0=No, 1=Yes) */
#define USBPD1_AGNOSTIC_phase8_PGDO_PD_ISNK_EN 0u
/* Enable higher resolution of the Value for PGDO PD ISNK (0=No, 1=Yes) */
#define USBPD1_AGNOSTIC_phase8_PGDO_ISNK_H_RES_EN 0u
/* Number of Discharge hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_DISCHG_NUM 1u
/* Number of Discharge hard IP + Protection Logic is instantiated */
#define USBPD1_AGNOSTIC_phase8_DISCHG_PROT_NUM 0u
/* Number of s8usbpd_vconn_sw_shv_small_top */
#define USBPD1_AGNOSTIC_phase8_SMALL_VCONN_NUM 0u
/* Total number of Small Vconn two-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_SMALL_VCONN_NUM_LOG2 0u
/* Total number of Small Vconn three-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_SMALL_VCONN_NUM_LOG3 0u
/* Enable two s8usbpd_vconn_sw_1vconn_shv_top */
#define USBPD1_AGNOSTIC_phase8_TWO_VCONN_EN 0u
/* ONE_VCONN_EN OR TWO_VCONN_EN */
#define USBPD1_AGNOSTIC_phase8_VCONN_EN 0u
/* VCONN 20V enabled? */
#define USBPD1_AGNOSTIC_phase8_VCONN20_EN 1u
/* Enable one s8usbpd 300ma_sw_top */
#define USBPD1_AGNOSTIC_phase8_FET_300_EN 0u
/* V5V is enabled */
#define USBPD1_AGNOSTIC_phase8_V5V_EN   1u
/* Enable s8usbpd_cc_shvt_top */
#define USBPD1_AGNOSTIC_phase8_CC_SHVT_EN 1u
/* Enable s8usbpd_cc_shvt_cabl_top */
#define USBPD1_AGNOSTIC_phase8_CC_SHVT_CABLE_EN 0u
/* Enable s8usbpd_cc_ufp_nord_top */
#define USBPD1_AGNOSTIC_phase8_CC_UFP_NORD_EN 0u
/* Enable s8usbpd_cc_dfp_notxrx_top */
#define USBPD1_AGNOSTIC_phase8_CC_DFP_NOTXRX_EN 0u
/* s8usbpd current/voltage reference capable (0=No, 1=Yes) */
#define USBPD1_AGNOSTIC_phase8_DPSLP_REF_EN 0u
/* s8usbpd pump capable (0=No, 1=Yes) */
#define USBPD1_AGNOSTIC_phase8_CPUMP_EN 0u
/* Number of s8usbpd2 5vpump The V5PUMP_NUM indiates the total s8usbpd2 5vpump
   regardless of the V5PUMP_EN value */
#define USBPD1_AGNOSTIC_phase8_V5PUMP_NUM 2u
/* Number of ADC hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_ADC_NUM  1u
/* Number of s8usbpd_chgdet_afc_top/s8pds_chgdet_afc_top */
#define USBPD1_AGNOSTIC_phase8_BCH_DET_NUM 0u
/* Total number of Battery Charger two-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_BCH_DET_NUM_LOG2 0u
/* Total number of Battery Charger three-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_BCH_DET_NUM_LOG3 0u
/* Number of s8usbpd_chgdet_top */
#define USBPD1_AGNOSTIC_phase8_CHGDET_NUM 0u
/* Total number of Charger 1-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_CHGDET_NUM_LOG1 0u
/* Total number of Charger two-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_CHGDET_NUM_LOG2 0u
/* Total number of Charger three-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_CHGDET_NUM_LOG3 0u
/* Number of Internal/External N-Gate Driver is instantiated */
#define USBPD1_AGNOSTIC_phase8_NGDO_NUM 0u
/* Number of SBU Switch is instantiated */
#define USBPD1_AGNOSTIC_phase8_SBU_NUM  1u
/* Number of SBU Switches instantiated */
#define USBPD1_AGNOSTIC_phase8_SBU20_NUM 0u
/* Total number of SBU20 two-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_SBU20_NUM_LOG2 0u
/* Number of DPDM Switches instantiated */
#define USBPD1_AGNOSTIC_phase8_DPDM_NUM 0u
/* CCG6 or CCG6DF DPDM Enabled */
#define USBPD1_AGNOSTIC_phase8_DPDM_CCG6_EN 0u
/* Number of CSA hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_CSA_NUM  0u
/* Total number of CSA one-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_CSA_NUM_LOG1 0u
/* Total number of CSA two-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_CSA_NUM_LOG2 0u
/* Total number of CSA three-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_CSA_NUM_LOG3 0u
/* One CSA SCP hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_CSA_SCP_EN 1u
/* One CSA RCP hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_CSA_RCP_EN 1u
/* CSA SCP or CSA RCP hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_CSA_SCP_RCP_EN 1u
/* VSYS Enabled (s8usbpd_vddd_sw_top is instantiated) */
#define USBPD1_AGNOSTIC_phase8_VSYS_EN  0u
/* Number of s8usbpd_20vreg_top Regulator hard IP is instantiated */
#define USBPD1_AGNOSTIC_phase8_VREG20_NUM 1u
/* Total number of VREG20 one-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_VREG20_NUM_LOG1 1u
/* Total number of VREG20 two-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_VREG20_NUM_LOG2 2u
/* Total number of VREG20 three-bit CFG bits */
#define USBPD1_AGNOSTIC_phase8_VREG20_NUM_LOG3 3u
/* First SHV regulator instatiated */
#define USBPD1_AGNOSTIC_phase8_REGULATOR1_EN 0u
/* Second SHV regulator instatiated */
#define USBPD1_AGNOSTIC_phase8_REGULATOR2_EN 0u
/* Third SHV regulator instatiated */
#define USBPD1_AGNOSTIC_phase8_REGULATOR3_EN 0u
/* Forth SHV regulator instatiated */
#define USBPD1_AGNOSTIC_phase8_REGULATOR4_EN 0u
/* First 20V regulator instatiated */
#define USBPD1_AGNOSTIC_phase8_REGULATOR20_1_EN 1u
/* Second 20V regulator instatiated */
#define USBPD1_AGNOSTIC_phase8_REGULATOR20_2_EN 0u
/* Third 20V regulator instatiated */
#define USBPD1_AGNOSTIC_phase8_REGULATOR20_3_EN 0u
/* Forth 20V regulator instatiated */
#define USBPD1_AGNOSTIC_phase8_REGULATOR20_4_EN 0u
/* Regulator control is enabled (s8usbpd_reg_control_top is intantiated) */
#define USBPD1_AGNOSTIC_phase8_REG_CONTROL_EN 0u
/* Enable CCG7D_EN related registers */
#define USBPD1_AGNOSTIC_phase8_CCG7D_EN 0u
/* Enable CCG7D_EN related registers for Instance 0 only */
#define USBPD1_AGNOSTIC_phase8_CCG7D_EN_INST_ZERO 0u
/* Enable Battery to Ground protection */
#define USBPD1_AGNOSTIC_phase8_BAT2GND_EN 0u
/* Enable function/related registers of PD Buck Boost Controller/next-gen products */
#define USBPD1_AGNOSTIC_phase8_PDBBC_EN 0u
/* Enable IBUS transition contol logic */
#define USBPD1_AGNOSTIC_phase8_IBTR_EN  0u
/* PASC or CCG7D Enable */
#define USBPD1_AGNOSTIC_phase8_PASC_CCG7D_EN 0u
/* PASC or CCG6DF or CCG7D Enable */
#define USBPD1_AGNOSTIC_phase8_PASC_CCG6DF_CCG7D_EN 0u
/* CCG6 or CCG7D Enable */
#define USBPD1_AGNOSTIC_phase8_CCG6_CCG7D_EN 0u
/* Enable PMG1S3_EN related registers */
#define USBPD1_AGNOSTIC_phase8_PMG1S3_EN 1u
/* Enable CCG6DF or PMG1S3 related registers */
#define USBPD1_AGNOSTIC_phase8_CCG6DF_PMG1S3_EN 1u
/* Enable Digital Flip Mux */
#define USBPD1_AGNOSTIC_phase8_FMX_EN   1u
/* Enable PMG1S3_EN related registers */
#define USBPD1_AGNOSTIC_phase8_ACG1F_PMG1S3_EN 1u
/* Enable RAMBIST Muxing Logic */
#define USBPD1_AGNOSTIC_phase8_RBM_EN   1u
/* Enable Scan Bypass Logic */
#define USBPD1_AGNOSTIC_phase8_SCBYP_EN 1u
/* Number of New SBU Mux (s8usbpdv2_pmg1s3 _sbu_sw_top) and related Registers */
#define USBPD1_AGNOSTIC_phase8_SBU_NEW_NUM 2u
/* Number of words in EZ memory */
#define SCB_EZ_DATA_NR                  32u

#endif /* _PMG1S3_CONFIG_H_ */


/* [] END OF FILE */
