/***************************************************************************//**
* \file fx3g2_config.h
*
* \brief
* FX3G2 device configuration header
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

#ifndef _FX3G2_CONFIG_H_
#define _FX3G2_CONFIG_H_

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
    PCLK_TCPWM0_CLOCKS0             = 0x0007u,  /* tcpwm[0].clocks[0] */
    PCLK_TCPWM0_CLOCKS1             = 0x0008u,  /* tcpwm[0].clocks[1] */
    PCLK_TCPWM0_CLOCKS2             = 0x0009u,  /* tcpwm[0].clocks[2] */
    PCLK_TCPWM0_CLOCKS3             = 0x000Au,  /* tcpwm[0].clocks[3] */
    PCLK_TCPWM0_CLOCKS4             = 0x000Bu,  /* tcpwm[0].clocks[4] */
    PCLK_TCPWM0_CLOCKS5             = 0x000Cu,  /* tcpwm[0].clocks[5] */
    PCLK_TCPWM0_CLOCKS6             = 0x000Du,  /* tcpwm[0].clocks[6] */
    PCLK_TCPWM0_CLOCKS7             = 0x000Eu,  /* tcpwm[0].clocks[7] */
    PCLK_CPUSS_CLOCK_TRACE_IN       = 0x000Fu,  /* cpuss.clock_trace_in */
    PCLK_USB_CLOCK_DEV_BRS          = 0x0010u,  /* usb.clock_dev_brs */
    PCLK_CANFD0_CLOCK_CAN0          = 0x0011u,  /* canfd[0].clock_can[0] */
    PCLK_LVDS2USB32SS_CLOCK_SAR     = 0x0012u   /* lvds2usb32ss.clock_sar */
} en_clk_dst_t;

/* Trigger Group */
/* This section contains the enums related to the Trigger multiplexer (TrigMux) driver.
* Refer to the Cypress Peripheral Driver Library Documentation, section Trigger multiplexer (TrigMux) -> Enumerated Types for details.
*/
/* Trigger Group Inputs */
/* Trigger Input Group 0 - PDMA0 Request Assignments */
typedef enum
{
    TRIG_IN_MUX_0_PDMA0_TR_OUT0     = 0x00000001u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT1     = 0x00000002u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT2     = 0x00000003u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT3     = 0x00000004u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT4     = 0x00000005u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT5     = 0x00000006u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT6     = 0x00000007u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT7     = 0x00000008u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT8     = 0x00000009u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT9     = 0x0000000Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT10    = 0x0000000Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT11    = 0x0000000Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT12    = 0x0000000Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT13    = 0x0000000Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT14    = 0x0000000Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT15    = 0x00000010u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT0     = 0x00000011u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT1     = 0x00000012u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT2     = 0x00000013u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT3     = 0x00000014u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT4     = 0x00000015u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT5     = 0x00000016u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT6     = 0x00000017u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT7     = 0x00000018u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT8     = 0x00000019u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT9     = 0x0000001Au, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT10    = 0x0000001Bu, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT11    = 0x0000001Cu, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT12    = 0x0000001Du, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT13    = 0x0000001Eu, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT14    = 0x0000001Fu, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT15    = 0x00000020u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_0_MDMA_TR_OUT0      = 0x00000021u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_0_MDMA_TR_OUT1      = 0x00000022u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_0_MDMA_TR_OUT2      = 0x00000023u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_0_MDMA_TR_OUT3      = 0x00000024u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_0_MDMA_TR_OUT4      = 0x00000025u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_0_MDMA_TR_OUT5      = 0x00000026u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_0_USB_DMA_REQ0      = 0x00000027u, /* usb.dma_req[0] */
    TRIG_IN_MUX_0_USB_DMA_REQ1      = 0x00000028u, /* usb.dma_req[1] */
    TRIG_IN_MUX_0_USB_DMA_REQ2      = 0x00000029u, /* usb.dma_req[2] */
    TRIG_IN_MUX_0_USB_DMA_REQ3      = 0x0000002Au, /* usb.dma_req[3] */
    TRIG_IN_MUX_0_USB_DMA_REQ4      = 0x0000002Bu, /* usb.dma_req[4] */
    TRIG_IN_MUX_0_USB_DMA_REQ5      = 0x0000002Cu, /* usb.dma_req[5] */
    TRIG_IN_MUX_0_USB_DMA_REQ6      = 0x0000002Du, /* usb.dma_req[6] */
    TRIG_IN_MUX_0_USB_DMA_REQ7      = 0x0000002Eu, /* usb.dma_req[7] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT0     = 0x0000002Fu, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT1     = 0x00000030u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT2     = 0x00000031u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT3     = 0x00000032u, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT4     = 0x00000033u, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT5     = 0x00000034u, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT6     = 0x00000035u, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT7     = 0x00000036u, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT8     = 0x00000037u, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT9     = 0x00000038u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT10    = 0x00000039u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT11    = 0x0000003Au, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT12    = 0x0000003Bu, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT13    = 0x0000003Cu, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT14    = 0x0000003Du, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT15    = 0x0000003Eu, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT16    = 0x0000003Fu, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT17    = 0x00000040u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT18    = 0x00000041u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT19    = 0x00000042u, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT20    = 0x00000043u, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT21    = 0x00000044u, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT22    = 0x00000045u, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_0_HSIOM_TR_OUT23    = 0x00000046u, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_0_TCPWM_TR_OVERFLOW0 = 0x00000049u, /* tcpwm[0].tr_overflow[0] */
    TRIG_IN_MUX_0_TCPWM_TR_COMPARE_MATCH0 = 0x0000004Au, /* tcpwm[0].tr_compare_match[0] */
    TRIG_IN_MUX_0_TCPWM_TR_UNDERFLOW0 = 0x0000004Bu, /* tcpwm[0].tr_underflow[0] */
    TRIG_IN_MUX_0_TCPWM_TR_OVERFLOW1 = 0x0000004Cu, /* tcpwm[0].tr_overflow[1] */
    TRIG_IN_MUX_0_TCPWM_TR_COMPARE_MATCH1 = 0x0000004Du, /* tcpwm[0].tr_compare_match[1] */
    TRIG_IN_MUX_0_TCPWM_TR_UNDERFLOW1 = 0x0000004Eu, /* tcpwm[0].tr_underflow[1] */
    TRIG_IN_MUX_0_TCPWM_TR_OVERFLOW2 = 0x0000004Fu, /* tcpwm[0].tr_overflow[2] */
    TRIG_IN_MUX_0_TCPWM_TR_COMPARE_MATCH2 = 0x00000050u, /* tcpwm[0].tr_compare_match[2] */
    TRIG_IN_MUX_0_TCPWM_TR_UNDERFLOW2 = 0x00000051u, /* tcpwm[0].tr_underflow[2] */
    TRIG_IN_MUX_0_TCPWM_TR_OVERFLOW3 = 0x00000052u, /* tcpwm[0].tr_overflow[3] */
    TRIG_IN_MUX_0_TCPWM_TR_COMPARE_MATCH3 = 0x00000053u, /* tcpwm[0].tr_compare_match[3] */
    TRIG_IN_MUX_0_TCPWM_TR_UNDERFLOW3 = 0x00000054u, /* tcpwm[0].tr_underflow[3] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT0  = 0x00000055u, /* usbhsdev.u2d_tr_out[0] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT1  = 0x00000056u, /* usbhsdev.u2d_tr_out[1] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT2  = 0x00000057u, /* usbhsdev.u2d_tr_out[2] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT3  = 0x00000058u, /* usbhsdev.u2d_tr_out[3] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT4  = 0x00000059u, /* usbhsdev.u2d_tr_out[4] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT5  = 0x0000005Au, /* usbhsdev.u2d_tr_out[5] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT6  = 0x0000005Bu, /* usbhsdev.u2d_tr_out[6] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT7  = 0x0000005Cu, /* usbhsdev.u2d_tr_out[7] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT8  = 0x0000005Du, /* usbhsdev.u2d_tr_out[8] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT9  = 0x0000005Eu, /* usbhsdev.u2d_tr_out[9] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT10 = 0x0000005Fu, /* usbhsdev.u2d_tr_out[10] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT11 = 0x00000060u, /* usbhsdev.u2d_tr_out[11] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT12 = 0x00000061u, /* usbhsdev.u2d_tr_out[12] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT13 = 0x00000062u, /* usbhsdev.u2d_tr_out[13] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT14 = 0x00000063u, /* usbhsdev.u2d_tr_out[14] */
    TRIG_IN_MUX_0_USBHSDEV_TR_OUT15 = 0x00000064u, /* usbhsdev.u2d_tr_out[15] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT0 = 0x00000065u, /* lvds2usb32ss.hbwss_otrig_o[0] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT1 = 0x00000066u, /* lvds2usb32ss.hbwss_otrig_o[1] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT2 = 0x00000067u, /* lvds2usb32ss.hbwss_otrig_o[2] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT3 = 0x00000068u, /* lvds2usb32ss.hbwss_otrig_o[3] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT4 = 0x00000069u, /* lvds2usb32ss.hbwss_otrig_o[4] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT5 = 0x0000006Au, /* lvds2usb32ss.hbwss_otrig_o[5] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT6 = 0x0000006Bu, /* lvds2usb32ss.hbwss_otrig_o[6] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT7 = 0x0000006Cu, /* lvds2usb32ss.hbwss_otrig_o[7] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT8 = 0x0000006Du, /* lvds2usb32ss.hbwss_otrig_o[8] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT9 = 0x0000006Eu, /* lvds2usb32ss.hbwss_otrig_o[9] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT10 = 0x0000006Fu, /* lvds2usb32ss.hbwss_otrig_o[10] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT11 = 0x00000070u, /* lvds2usb32ss.hbwss_otrig_o[11] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT12 = 0x00000071u, /* lvds2usb32ss.hbwss_otrig_o[12] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT13 = 0x00000072u, /* lvds2usb32ss.hbwss_otrig_o[13] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT14 = 0x00000073u, /* lvds2usb32ss.hbwss_otrig_o[14] */
    TRIG_IN_MUX_0_LVDS2USB32SS_TR_OUT15 = 0x00000074u, /* lvds2usb32ss.hbwss_otrig_o[15] */
    TRIG_IN_MUX_0_CAN_DBG_DMA       = 0x00000075u, /* canfd[0].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_0_LVDS2USB32SS_FRM_CNTR_VLD = 0x00000076u /* lvds2usb32ss.usb32_frm_cntr_vld_o */
} en_trig_input_pdma0_tr_t;

/* Trigger Input Group 1 - PDMA1 Request Assignments */
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
    TRIG_IN_MUX_1_PDMA1_TR_OUT0     = 0x00000111u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT1     = 0x00000112u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT2     = 0x00000113u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT3     = 0x00000114u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT4     = 0x00000115u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT5     = 0x00000116u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT6     = 0x00000117u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT7     = 0x00000118u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT8     = 0x00000119u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT9     = 0x0000011Au, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT10    = 0x0000011Bu, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT11    = 0x0000011Cu, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT12    = 0x0000011Du, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT13    = 0x0000011Eu, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT14    = 0x0000011Fu, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_1_PDMA1_TR_OUT15    = 0x00000120u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_1_MDMA_TR_OUT0      = 0x00000121u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_1_MDMA_TR_OUT1      = 0x00000122u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_1_MDMA_TR_OUT2      = 0x00000123u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_1_MDMA_TR_OUT3      = 0x00000124u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_1_MDMA_TR_OUT4      = 0x00000125u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_1_MDMA_TR_OUT5      = 0x00000126u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_1_USB_DMA_REQ0      = 0x00000127u, /* usb.dma_req[0] */
    TRIG_IN_MUX_1_USB_DMA_REQ1      = 0x00000128u, /* usb.dma_req[1] */
    TRIG_IN_MUX_1_USB_DMA_REQ2      = 0x00000129u, /* usb.dma_req[2] */
    TRIG_IN_MUX_1_USB_DMA_REQ3      = 0x0000012Au, /* usb.dma_req[3] */
    TRIG_IN_MUX_1_USB_DMA_REQ4      = 0x0000012Bu, /* usb.dma_req[4] */
    TRIG_IN_MUX_1_USB_DMA_REQ5      = 0x0000012Cu, /* usb.dma_req[5] */
    TRIG_IN_MUX_1_USB_DMA_REQ6      = 0x0000012Du, /* usb.dma_req[6] */
    TRIG_IN_MUX_1_USB_DMA_REQ7      = 0x0000012Eu, /* usb.dma_req[7] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT0     = 0x0000012Fu, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT1     = 0x00000130u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT2     = 0x00000131u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT3     = 0x00000132u, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT4     = 0x00000133u, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT5     = 0x00000134u, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT6     = 0x00000135u, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT7     = 0x00000136u, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT8     = 0x00000137u, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT9     = 0x00000138u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT10    = 0x00000139u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT11    = 0x0000013Au, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT12    = 0x0000013Bu, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT13    = 0x0000013Cu, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT14    = 0x0000013Du, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT15    = 0x0000013Eu, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT16    = 0x0000013Fu, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT17    = 0x00000140u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT18    = 0x00000141u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT19    = 0x00000142u, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT20    = 0x00000143u, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT21    = 0x00000144u, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT22    = 0x00000145u, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_1_HSIOM_TR_OUT23    = 0x00000146u, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_1_TCPWM_TR_OVERFLOW4 = 0x00000147u, /* tcpwm[0].tr_overflow[4] */
    TRIG_IN_MUX_1_TCPWM_TR_COMPARE_MATCH4 = 0x00000148u, /* tcpwm[0].tr_compare_match[4] */
    TRIG_IN_MUX_1_TCPWM_TR_UNDERFLOW4 = 0x00000149u, /* tcpwm[0].tr_underflow[4] */
    TRIG_IN_MUX_1_TCPWM_TR_OVERFLOW5 = 0x0000014Au, /* tcpwm[0].tr_overflow[5] */
    TRIG_IN_MUX_1_TCPWM_TR_COMPARE_MATCH5 = 0x0000014Bu, /* tcpwm[0].tr_compare_match[5] */
    TRIG_IN_MUX_1_TCPWM_TR_UNDERFLOW5 = 0x0000014Cu, /* tcpwm[0].tr_underflow[5] */
    TRIG_IN_MUX_1_TCPWM_TR_OVERFLOW6 = 0x0000014Du, /* tcpwm[0].tr_overflow[6] */
    TRIG_IN_MUX_1_TCPWM_TR_COMPARE_MATCH6 = 0x0000014Eu, /* tcpwm[0].tr_compare_match[6] */
    TRIG_IN_MUX_1_TCPWM_TR_UNDERFLOW6 = 0x0000014Fu, /* tcpwm[0].tr_underflow[6] */
    TRIG_IN_MUX_1_TCPWM_TR_OVERFLOW7 = 0x00000150u, /* tcpwm[0].tr_overflow[7] */
    TRIG_IN_MUX_1_TCPWM_TR_COMPARE_MATCH7 = 0x00000151u, /* tcpwm[0].tr_compare_match[7] */
    TRIG_IN_MUX_1_TCPWM_TR_UNDERFLOW7 = 0x00000152u, /* tcpwm[0].tr_underflow[7] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT16 = 0x00000153u, /* usbhsdev.u2d_tr_out[16] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT17 = 0x00000154u, /* usbhsdev.u2d_tr_out[17] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT18 = 0x00000155u, /* usbhsdev.u2d_tr_out[18] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT19 = 0x00000156u, /* usbhsdev.u2d_tr_out[19] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT20 = 0x00000157u, /* usbhsdev.u2d_tr_out[20] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT21 = 0x00000158u, /* usbhsdev.u2d_tr_out[21] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT22 = 0x00000159u, /* usbhsdev.u2d_tr_out[22] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT23 = 0x0000015Au, /* usbhsdev.u2d_tr_out[23] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT24 = 0x0000015Bu, /* usbhsdev.u2d_tr_out[24] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT25 = 0x0000015Cu, /* usbhsdev.u2d_tr_out[25] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT26 = 0x0000015Du, /* usbhsdev.u2d_tr_out[26] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT27 = 0x0000015Eu, /* usbhsdev.u2d_tr_out[27] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT28 = 0x0000015Fu, /* usbhsdev.u2d_tr_out[28] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT29 = 0x00000160u, /* usbhsdev.u2d_tr_out[29] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT30 = 0x00000161u, /* usbhsdev.u2d_tr_out[30] */
    TRIG_IN_MUX_1_USBHSDEV_TR_OUT31 = 0x00000162u, /* usbhsdev.u2d_tr_out[31] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT0 = 0x00000163u, /* lvds2usb32ss.hbwss_otrig_o[0] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT1 = 0x00000164u, /* lvds2usb32ss.hbwss_otrig_o[1] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT2 = 0x00000165u, /* lvds2usb32ss.hbwss_otrig_o[2] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT3 = 0x00000166u, /* lvds2usb32ss.hbwss_otrig_o[3] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT4 = 0x00000167u, /* lvds2usb32ss.hbwss_otrig_o[4] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT5 = 0x00000168u, /* lvds2usb32ss.hbwss_otrig_o[5] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT6 = 0x00000169u, /* lvds2usb32ss.hbwss_otrig_o[6] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT7 = 0x0000016Au, /* lvds2usb32ss.hbwss_otrig_o[7] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT8 = 0x0000016Bu, /* lvds2usb32ss.hbwss_otrig_o[8] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT9 = 0x0000016Cu, /* lvds2usb32ss.hbwss_otrig_o[9] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT10 = 0x0000016Du, /* lvds2usb32ss.hbwss_otrig_o[10] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT11 = 0x0000016Eu, /* lvds2usb32ss.hbwss_otrig_o[11] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT12 = 0x0000016Fu, /* lvds2usb32ss.hbwss_otrig_o[12] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT13 = 0x00000170u, /* lvds2usb32ss.hbwss_otrig_o[13] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT14 = 0x00000171u, /* lvds2usb32ss.hbwss_otrig_o[14] */
    TRIG_IN_MUX_1_LVDS2USB32SS_TR_OUT15 = 0x00000172u, /* lvds2usb32ss.hbwss_otrig_o[15] */
    TRIG_IN_MUX_1_LVDS2USB32SS_FRM_CNTR_VLD = 0x00000173u /* lvds2usb32ss.usb32_frm_cntr_vld_o */
} en_trig_input_pdma1_tr_t;

/* Trigger Input Group 2 - TCPWM0 trigger multiplexer */
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
    TRIG_IN_MUX_2_PDMA0_TR_OUT16    = 0x00000211u, /* cpuss.dw0_tr_out[16] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT17    = 0x00000212u, /* cpuss.dw0_tr_out[17] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT18    = 0x00000213u, /* cpuss.dw0_tr_out[18] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT19    = 0x00000214u, /* cpuss.dw0_tr_out[19] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT20    = 0x00000215u, /* cpuss.dw0_tr_out[20] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT21    = 0x00000216u, /* cpuss.dw0_tr_out[21] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT22    = 0x00000217u, /* cpuss.dw0_tr_out[22] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT23    = 0x00000218u, /* cpuss.dw0_tr_out[23] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT0     = 0x00000219u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT1     = 0x0000021Au, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT2     = 0x0000021Bu, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT3     = 0x0000021Cu, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT4     = 0x0000021Du, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT5     = 0x0000021Eu, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT6     = 0x0000021Fu, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT7     = 0x00000220u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT8     = 0x00000221u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT9     = 0x00000222u, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT10    = 0x00000223u, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT11    = 0x00000224u, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT12    = 0x00000225u, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT13    = 0x00000226u, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT14    = 0x00000227u, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT15    = 0x00000228u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT16    = 0x00000229u, /* cpuss.dw1_tr_out[16] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT17    = 0x0000022Au, /* cpuss.dw1_tr_out[17] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT18    = 0x0000022Bu, /* cpuss.dw1_tr_out[18] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT19    = 0x0000022Cu, /* cpuss.dw1_tr_out[19] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT20    = 0x0000022Du, /* cpuss.dw1_tr_out[20] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT21    = 0x0000022Eu, /* cpuss.dw1_tr_out[21] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT22    = 0x0000022Fu, /* cpuss.dw1_tr_out[22] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT23    = 0x00000230u, /* cpuss.dw1_tr_out[23] */
    TRIG_IN_MUX_2_MDMA_TR_OUT0      = 0x00000231u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_2_MDMA_TR_OUT1      = 0x00000232u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_2_MDMA_TR_OUT2      = 0x00000233u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_2_MDMA_TR_OUT3      = 0x00000234u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_2_MDMA_TR_OUT4      = 0x00000235u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_2_MDMA_TR_OUT5      = 0x00000236u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_2_USB_DMA_REQ0      = 0x00000237u, /* usb.dma_req[0] */
    TRIG_IN_MUX_2_USB_DMA_REQ1      = 0x00000238u, /* usb.dma_req[1] */
    TRIG_IN_MUX_2_USB_DMA_REQ2      = 0x00000239u, /* usb.dma_req[2] */
    TRIG_IN_MUX_2_USB_DMA_REQ3      = 0x0000023Au, /* usb.dma_req[3] */
    TRIG_IN_MUX_2_USB_DMA_REQ4      = 0x0000023Bu, /* usb.dma_req[4] */
    TRIG_IN_MUX_2_USB_DMA_REQ5      = 0x0000023Cu, /* usb.dma_req[5] */
    TRIG_IN_MUX_2_USB_DMA_REQ6      = 0x0000023Du, /* usb.dma_req[6] */
    TRIG_IN_MUX_2_USB_DMA_REQ7      = 0x0000023Eu, /* usb.dma_req[7] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT0     = 0x0000023Fu, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT1     = 0x00000240u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT2     = 0x00000241u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT3     = 0x00000242u, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT4     = 0x00000243u, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT5     = 0x00000244u, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT6     = 0x00000245u, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT7     = 0x00000246u, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT8     = 0x00000247u, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT9     = 0x00000248u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT10    = 0x00000249u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT11    = 0x0000024Au, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT12    = 0x0000024Bu, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT13    = 0x0000024Cu, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT14    = 0x0000024Du, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT15    = 0x0000024Eu, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT16    = 0x0000024Fu, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT17    = 0x00000250u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT18    = 0x00000251u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT19    = 0x00000252u, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT20    = 0x00000253u, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT21    = 0x00000254u, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT22    = 0x00000255u, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_2_HSIOM_TR_OUT23    = 0x00000256u, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT0  = 0x00000259u, /* usbhsdev.u2d_tr_out[0] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT1  = 0x0000025Au, /* usbhsdev.u2d_tr_out[1] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT2  = 0x0000025Bu, /* usbhsdev.u2d_tr_out[2] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT3  = 0x0000025Cu, /* usbhsdev.u2d_tr_out[3] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT4  = 0x0000025Du, /* usbhsdev.u2d_tr_out[4] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT5  = 0x0000025Eu, /* usbhsdev.u2d_tr_out[5] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT6  = 0x0000025Fu, /* usbhsdev.u2d_tr_out[6] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT7  = 0x00000260u, /* usbhsdev.u2d_tr_out[7] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT8  = 0x00000261u, /* usbhsdev.u2d_tr_out[8] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT9  = 0x00000262u, /* usbhsdev.u2d_tr_out[9] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT10 = 0x00000263u, /* usbhsdev.u2d_tr_out[10] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT11 = 0x00000264u, /* usbhsdev.u2d_tr_out[11] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT12 = 0x00000265u, /* usbhsdev.u2d_tr_out[12] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT13 = 0x00000266u, /* usbhsdev.u2d_tr_out[13] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT14 = 0x00000267u, /* usbhsdev.u2d_tr_out[14] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT15 = 0x00000268u, /* usbhsdev.u2d_tr_out[15] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT16 = 0x00000269u, /* usbhsdev.u2d_tr_out[16] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT17 = 0x0000026Au, /* usbhsdev.u2d_tr_out[17] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT18 = 0x0000026Bu, /* usbhsdev.u2d_tr_out[18] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT19 = 0x0000026Cu, /* usbhsdev.u2d_tr_out[19] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT20 = 0x0000026Du, /* usbhsdev.u2d_tr_out[20] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT21 = 0x0000026Eu, /* usbhsdev.u2d_tr_out[21] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT22 = 0x0000026Fu, /* usbhsdev.u2d_tr_out[22] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT23 = 0x00000270u, /* usbhsdev.u2d_tr_out[23] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT24 = 0x00000271u, /* usbhsdev.u2d_tr_out[24] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT25 = 0x00000272u, /* usbhsdev.u2d_tr_out[25] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT26 = 0x00000273u, /* usbhsdev.u2d_tr_out[26] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT27 = 0x00000274u, /* usbhsdev.u2d_tr_out[27] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT28 = 0x00000275u, /* usbhsdev.u2d_tr_out[28] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT29 = 0x00000276u, /* usbhsdev.u2d_tr_out[29] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT30 = 0x00000277u, /* usbhsdev.u2d_tr_out[30] */
    TRIG_IN_MUX_2_USBHSDEV_TR_OUT31 = 0x00000278u, /* usbhsdev.u2d_tr_out[31] */
    TRIG_IN_MUX_2_SMIF_TX_REQ       = 0x00000279u, /* smif.tr_tx_req */
    TRIG_IN_MUX_2_SMIF_RX_REQ       = 0x0000027Au, /* smif.tr_rx_req */
    TRIG_IN_MUX_2_PDM_RX_REQ0       = 0x0000027Bu, /* pdm[0].tr_rx_req[0] */
    TRIG_IN_MUX_2_PDM_RX_REQ1       = 0x0000027Cu, /* pdm[0].tr_rx_req[1] */
    TRIG_IN_MUX_2_TDM_TX_REQ        = 0x0000027Du, /* tdm[0].tr_tx_req */
    TRIG_IN_MUX_2_TDM_RX_REQ        = 0x0000027Eu, /* tdm[0].tr_rx_req */
    TRIG_IN_MUX_2_SCB0_TX_REQ       = 0x0000027Fu, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_2_SCB0_RX_REQ       = 0x00000280u, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_2_SCB0_SCL_FILTERED = 0x00000281u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_SCB1_TX_REQ       = 0x00000282u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_2_SCB1_RX_REQ       = 0x00000283u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_2_SCB1_SCL_FILTERED = 0x00000284u, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_SCB2_TX_REQ       = 0x00000285u, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_2_SCB2_RX_REQ       = 0x00000286u, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_2_SCB2_SCL_FILTERED = 0x00000287u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_SCB3_TX_REQ       = 0x00000288u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_2_SCB3_RX_REQ       = 0x00000289u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_2_SCB3_SCL_FILTERED = 0x0000028Au, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_CAN_FIFO0         = 0x0000028Bu, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_MUX_2_CAN_FIFO1         = 0x0000028Cu, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_MUX_2_CTI_TR_OUT0       = 0x0000028Du, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_2_CTI_TR_OUT1       = 0x0000028Eu, /* cpuss.cti_tr_out[1] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT0 = 0x0000028Fu, /* lvds2usb32ss.hbwss_otrig_o[0] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT1 = 0x00000290u, /* lvds2usb32ss.hbwss_otrig_o[1] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT2 = 0x00000291u, /* lvds2usb32ss.hbwss_otrig_o[2] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT3 = 0x00000292u, /* lvds2usb32ss.hbwss_otrig_o[3] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT4 = 0x00000293u, /* lvds2usb32ss.hbwss_otrig_o[4] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT5 = 0x00000294u, /* lvds2usb32ss.hbwss_otrig_o[5] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT6 = 0x00000295u, /* lvds2usb32ss.hbwss_otrig_o[6] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT7 = 0x00000296u, /* lvds2usb32ss.hbwss_otrig_o[7] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT8 = 0x00000297u, /* lvds2usb32ss.hbwss_otrig_o[8] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT9 = 0x00000298u, /* lvds2usb32ss.hbwss_otrig_o[9] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT10 = 0x00000299u, /* lvds2usb32ss.hbwss_otrig_o[10] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT11 = 0x0000029Au, /* lvds2usb32ss.hbwss_otrig_o[11] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT12 = 0x0000029Bu, /* lvds2usb32ss.hbwss_otrig_o[12] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT13 = 0x0000029Cu, /* lvds2usb32ss.hbwss_otrig_o[13] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT14 = 0x0000029Du, /* lvds2usb32ss.hbwss_otrig_o[14] */
    TRIG_IN_MUX_2_LVDS2USB32SS_TR_OUT15 = 0x0000029Eu, /* lvds2usb32ss.hbwss_otrig_o[15] */
    TRIG_IN_MUX_2_SCB4_TX_REQ       = 0x000002AFu, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_2_SCB4_RX_REQ       = 0x000002B0u, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_2_SCB4_SCL_FILTERED = 0x000002B1u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_SCB5_TX_REQ       = 0x000002B2u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_2_SCB5_RX_REQ       = 0x000002B3u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_2_SCB5_SCL_FILTERED = 0x000002B4u, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_SCB6_TX_REQ       = 0x000002B5u, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_2_SCB6_RX_REQ       = 0x000002B6u, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_2_SCB6_SCL_FILTERED = 0x000002B7u, /* scb[6].tr_i2c_scl_filtered */
    TRIG_IN_MUX_2_LVDS2USB32SS_FRM_CNTR_VLD = 0x000002B8u /* lvds2usb32ss.usb32_frm_cntr_vld_o */
} en_trig_input_tcpwm0_t;

/* Trigger Input Group 3 - IO trigger multiplexer */
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
    TRIG_IN_MUX_3_PDMA1_TR_OUT0     = 0x00000311u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT1     = 0x00000312u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT2     = 0x00000313u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT3     = 0x00000314u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT4     = 0x00000315u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT5     = 0x00000316u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT6     = 0x00000317u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT7     = 0x00000318u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT8     = 0x00000319u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT9     = 0x0000031Au, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT10    = 0x0000031Bu, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT11    = 0x0000031Cu, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT12    = 0x0000031Du, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT13    = 0x0000031Eu, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT14    = 0x0000031Fu, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_3_PDMA1_TR_OUT15    = 0x00000320u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_3_MDMA_TR_OUT0      = 0x00000321u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_3_MDMA_TR_OUT1      = 0x00000322u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_3_MDMA_TR_OUT2      = 0x00000323u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_3_MDMA_TR_OUT3      = 0x00000324u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_3_MDMA_TR_OUT4      = 0x00000325u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_3_MDMA_TR_OUT5      = 0x00000326u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_3_USB_DMA_REQ0      = 0x00000327u, /* usb.dma_req[0] */
    TRIG_IN_MUX_3_USB_DMA_REQ1      = 0x00000328u, /* usb.dma_req[1] */
    TRIG_IN_MUX_3_USB_DMA_REQ2      = 0x00000329u, /* usb.dma_req[2] */
    TRIG_IN_MUX_3_USB_DMA_REQ3      = 0x0000032Au, /* usb.dma_req[3] */
    TRIG_IN_MUX_3_USB_DMA_REQ4      = 0x0000032Bu, /* usb.dma_req[4] */
    TRIG_IN_MUX_3_USB_DMA_REQ5      = 0x0000032Cu, /* usb.dma_req[5] */
    TRIG_IN_MUX_3_USB_DMA_REQ6      = 0x0000032Du, /* usb.dma_req[6] */
    TRIG_IN_MUX_3_USB_DMA_REQ7      = 0x0000032Eu, /* usb.dma_req[7] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT0  = 0x00000331u, /* usbhsdev.u2d_tr_out[0] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT1  = 0x00000332u, /* usbhsdev.u2d_tr_out[1] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT2  = 0x00000333u, /* usbhsdev.u2d_tr_out[2] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT3  = 0x00000334u, /* usbhsdev.u2d_tr_out[3] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT4  = 0x00000335u, /* usbhsdev.u2d_tr_out[4] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT5  = 0x00000336u, /* usbhsdev.u2d_tr_out[5] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT6  = 0x00000337u, /* usbhsdev.u2d_tr_out[6] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT7  = 0x00000338u, /* usbhsdev.u2d_tr_out[7] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT8  = 0x00000339u, /* usbhsdev.u2d_tr_out[8] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT9  = 0x0000033Au, /* usbhsdev.u2d_tr_out[9] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT10 = 0x0000033Bu, /* usbhsdev.u2d_tr_out[10] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT11 = 0x0000033Cu, /* usbhsdev.u2d_tr_out[11] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT12 = 0x0000033Du, /* usbhsdev.u2d_tr_out[12] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT13 = 0x0000033Eu, /* usbhsdev.u2d_tr_out[13] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT14 = 0x0000033Fu, /* usbhsdev.u2d_tr_out[14] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT15 = 0x00000340u, /* usbhsdev.u2d_tr_out[15] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT16 = 0x00000341u, /* usbhsdev.u2d_tr_out[16] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT17 = 0x00000342u, /* usbhsdev.u2d_tr_out[17] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT18 = 0x00000343u, /* usbhsdev.u2d_tr_out[18] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT19 = 0x00000344u, /* usbhsdev.u2d_tr_out[19] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT20 = 0x00000345u, /* usbhsdev.u2d_tr_out[20] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT21 = 0x00000346u, /* usbhsdev.u2d_tr_out[21] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT22 = 0x00000347u, /* usbhsdev.u2d_tr_out[22] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT23 = 0x00000348u, /* usbhsdev.u2d_tr_out[23] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT24 = 0x00000349u, /* usbhsdev.u2d_tr_out[24] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT25 = 0x0000034Au, /* usbhsdev.u2d_tr_out[25] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT26 = 0x0000034Bu, /* usbhsdev.u2d_tr_out[26] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT27 = 0x0000034Cu, /* usbhsdev.u2d_tr_out[27] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT28 = 0x0000034Du, /* usbhsdev.u2d_tr_out[28] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT29 = 0x0000034Eu, /* usbhsdev.u2d_tr_out[29] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT30 = 0x0000034Fu, /* usbhsdev.u2d_tr_out[30] */
    TRIG_IN_MUX_3_USBHSDEV_TR_OUT31 = 0x00000350u, /* usbhsdev.u2d_tr_out[31] */
    TRIG_IN_MUX_3_SMIF_TX_REQ       = 0x00000351u, /* smif.tr_tx_req */
    TRIG_IN_MUX_3_SMIF_RX_REQ       = 0x00000352u, /* smif.tr_rx_req */
    TRIG_IN_MUX_3_PDM_RX_REQ0       = 0x00000353u, /* pdm[0].tr_rx_req[0] */
    TRIG_IN_MUX_3_PDM_RX_REQ1       = 0x00000354u, /* pdm[0].tr_rx_req[1] */
    TRIG_IN_MUX_3_TDM_TX_REQ        = 0x00000355u, /* tdm[0].tr_tx_req */
    TRIG_IN_MUX_3_TDM_RX_REQ        = 0x00000356u, /* tdm[0].tr_rx_req */
    TRIG_IN_MUX_3_SCB0_TX_REQ       = 0x00000357u, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_3_SCB0_RX_REQ       = 0x00000358u, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_3_SCB0_SCL_FILTERED = 0x00000359u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB1_TX_REQ       = 0x0000035Au, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_3_SCB1_RX_REQ       = 0x0000035Bu, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_3_SCB1_SCL_FILTERED = 0x0000035Cu, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB2_TX_REQ       = 0x0000035Du, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_3_SCB2_RX_REQ       = 0x0000035Eu, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_3_SCB2_SCL_FILTERED = 0x0000035Fu, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB3_TX_REQ       = 0x00000360u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_3_SCB3_RX_REQ       = 0x00000361u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_3_SCB3_SCL_FILTERED = 0x00000362u, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_CAN_FIFO0         = 0x00000363u, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_MUX_3_CAN_FIFO1         = 0x00000364u, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_MUX_3_CTI_TR_OUT0       = 0x00000365u, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_3_CTI_TR_OUT1       = 0x00000366u, /* cpuss.cti_tr_out[1] */
    TRIG_IN_MUX_3_TCPWM_TR_OVERFLOW0 = 0x00000367u, /* tcpwm[0].tr_overflow[0] */
    TRIG_IN_MUX_3_TCPWM_TR_COMPARE_MATCH0 = 0x00000368u, /* tcpwm[0].tr_compare_match[0] */
    TRIG_IN_MUX_3_TCPWM_TR_UNDERFLOW0 = 0x00000369u, /* tcpwm[0].tr_underflow[0] */
    TRIG_IN_MUX_3_TCPWM_TR_OVERFLOW1 = 0x0000036Au, /* tcpwm[0].tr_overflow[1] */
    TRIG_IN_MUX_3_TCPWM_TR_COMPARE_MATCH1 = 0x0000036Bu, /* tcpwm[0].tr_compare_match[1] */
    TRIG_IN_MUX_3_TCPWM_TR_UNDERFLOW1 = 0x0000036Cu, /* tcpwm[0].tr_underflow[1] */
    TRIG_IN_MUX_3_TCPWM_TR_OVERFLOW2 = 0x0000036Du, /* tcpwm[0].tr_overflow[2] */
    TRIG_IN_MUX_3_TCPWM_TR_COMPARE_MATCH2 = 0x0000036Eu, /* tcpwm[0].tr_compare_match[2] */
    TRIG_IN_MUX_3_TCPWM_TR_UNDERFLOW2 = 0x0000036Fu, /* tcpwm[0].tr_underflow[2] */
    TRIG_IN_MUX_3_TCPWM_TR_OVERFLOW3 = 0x00000370u, /* tcpwm[0].tr_overflow[3] */
    TRIG_IN_MUX_3_TCPWM_TR_COMPARE_MATCH3 = 0x00000371u, /* tcpwm[0].tr_compare_match[3] */
    TRIG_IN_MUX_3_TCPWM_TR_UNDERFLOW3 = 0x00000372u, /* tcpwm[0].tr_underflow[3] */
    TRIG_IN_MUX_3_TCPWM_TR_OVERFLOW4 = 0x00000373u, /* tcpwm[0].tr_overflow[4] */
    TRIG_IN_MUX_3_TCPWM_TR_COMPARE_MATCH4 = 0x00000374u, /* tcpwm[0].tr_compare_match[4] */
    TRIG_IN_MUX_3_TCPWM_TR_UNDERFLOW4 = 0x00000375u, /* tcpwm[0].tr_underflow[4] */
    TRIG_IN_MUX_3_TCPWM_TR_OVERFLOW5 = 0x00000376u, /* tcpwm[0].tr_overflow[5] */
    TRIG_IN_MUX_3_TCPWM_TR_COMPARE_MATCH5 = 0x00000377u, /* tcpwm[0].tr_compare_match[5] */
    TRIG_IN_MUX_3_TCPWM_TR_UNDERFLOW5 = 0x00000378u, /* tcpwm[0].tr_underflow[5] */
    TRIG_IN_MUX_3_TCPWM_TR_OVERFLOW6 = 0x00000379u, /* tcpwm[0].tr_overflow[6] */
    TRIG_IN_MUX_3_TCPWM_TR_COMPARE_MATCH6 = 0x0000037Au, /* tcpwm[0].tr_compare_match[6] */
    TRIG_IN_MUX_3_TCPWM_TR_UNDERFLOW6 = 0x0000037Bu, /* tcpwm[0].tr_underflow[6] */
    TRIG_IN_MUX_3_TCPWM_TR_OVERFLOW7 = 0x0000037Cu, /* tcpwm[0].tr_overflow[7] */
    TRIG_IN_MUX_3_TCPWM_TR_COMPARE_MATCH7 = 0x0000037Du, /* tcpwm[0].tr_compare_match[7] */
    TRIG_IN_MUX_3_TCPWM_TR_UNDERFLOW7 = 0x0000037Eu, /* tcpwm[0].tr_underflow[7] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT0 = 0x0000037Fu, /* lvds2usb32ss.hbwss_otrig_o[0] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT1 = 0x00000380u, /* lvds2usb32ss.hbwss_otrig_o[1] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT2 = 0x00000381u, /* lvds2usb32ss.hbwss_otrig_o[2] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT3 = 0x00000382u, /* lvds2usb32ss.hbwss_otrig_o[3] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT4 = 0x00000383u, /* lvds2usb32ss.hbwss_otrig_o[4] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT5 = 0x00000384u, /* lvds2usb32ss.hbwss_otrig_o[5] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT6 = 0x00000385u, /* lvds2usb32ss.hbwss_otrig_o[6] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT7 = 0x00000386u, /* lvds2usb32ss.hbwss_otrig_o[7] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT8 = 0x00000387u, /* lvds2usb32ss.hbwss_otrig_o[8] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT9 = 0x00000388u, /* lvds2usb32ss.hbwss_otrig_o[9] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT10 = 0x00000389u, /* lvds2usb32ss.hbwss_otrig_o[10] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT11 = 0x0000038Au, /* lvds2usb32ss.hbwss_otrig_o[11] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT12 = 0x0000038Bu, /* lvds2usb32ss.hbwss_otrig_o[12] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT13 = 0x0000038Cu, /* lvds2usb32ss.hbwss_otrig_o[13] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT14 = 0x0000038Du, /* lvds2usb32ss.hbwss_otrig_o[14] */
    TRIG_IN_MUX_3_LVDS2USB32SS_TR_OUT15 = 0x0000038Eu, /* lvds2usb32ss.hbwss_otrig_o[15] */
    TRIG_IN_MUX_3_SCB4_TX_REQ       = 0x0000039Fu, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_3_SCB4_RX_REQ       = 0x000003A0u, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_3_SCB4_SCL_FILTERED = 0x000003A1u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB5_TX_REQ       = 0x000003A2u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_3_SCB5_RX_REQ       = 0x000003A3u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_3_SCB5_SCL_FILTERED = 0x000003A4u, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_3_SCB6_TX_REQ       = 0x000003A5u, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_3_SCB6_RX_REQ       = 0x000003A6u, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_3_SCB6_SCL_FILTERED = 0x000003A7u /* scb[6].tr_i2c_scl_filtered */
} en_trig_input_ioss_t;

/* Trigger Input Group 4 - IO trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_4_PDMA0_TR_OUT0     = 0x00000401u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT1     = 0x00000402u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT2     = 0x00000403u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT3     = 0x00000404u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT4     = 0x00000405u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT5     = 0x00000406u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT6     = 0x00000407u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT7     = 0x00000408u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT8     = 0x00000409u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT9     = 0x0000040Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT10    = 0x0000040Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT11    = 0x0000040Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT12    = 0x0000040Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT13    = 0x0000040Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT14    = 0x0000040Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT15    = 0x00000410u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT16    = 0x00000411u, /* cpuss.dw0_tr_out[16] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT17    = 0x00000412u, /* cpuss.dw0_tr_out[17] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT18    = 0x00000413u, /* cpuss.dw0_tr_out[18] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT19    = 0x00000414u, /* cpuss.dw0_tr_out[19] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT20    = 0x00000415u, /* cpuss.dw0_tr_out[20] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT21    = 0x00000416u, /* cpuss.dw0_tr_out[21] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT22    = 0x00000417u, /* cpuss.dw0_tr_out[22] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT23    = 0x00000418u, /* cpuss.dw0_tr_out[23] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT0     = 0x00000419u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT1     = 0x0000041Au, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT2     = 0x0000041Bu, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT3     = 0x0000041Cu, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT4     = 0x0000041Du, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT5     = 0x0000041Eu, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT6     = 0x0000041Fu, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT7     = 0x00000420u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT8     = 0x00000421u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT9     = 0x00000422u, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT10    = 0x00000423u, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT11    = 0x00000424u, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT12    = 0x00000425u, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT13    = 0x00000426u, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT14    = 0x00000427u, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT15    = 0x00000428u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT16    = 0x00000429u, /* cpuss.dw1_tr_out[16] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT17    = 0x0000042Au, /* cpuss.dw1_tr_out[17] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT18    = 0x0000042Bu, /* cpuss.dw1_tr_out[18] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT19    = 0x0000042Cu, /* cpuss.dw1_tr_out[19] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT20    = 0x0000042Du, /* cpuss.dw1_tr_out[20] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT21    = 0x0000042Eu, /* cpuss.dw1_tr_out[21] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT22    = 0x0000042Fu, /* cpuss.dw1_tr_out[22] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT23    = 0x00000430u, /* cpuss.dw1_tr_out[23] */
    TRIG_IN_MUX_4_MDMA_TR_OUT0      = 0x00000431u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_4_MDMA_TR_OUT1      = 0x00000432u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_4_MDMA_TR_OUT2      = 0x00000433u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_4_MDMA_TR_OUT3      = 0x00000434u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_4_MDMA_TR_OUT4      = 0x00000435u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_4_MDMA_TR_OUT5      = 0x00000436u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_4_USB_DMA_REQ0      = 0x00000437u, /* usb.dma_req[0] */
    TRIG_IN_MUX_4_USB_DMA_REQ1      = 0x00000438u, /* usb.dma_req[1] */
    TRIG_IN_MUX_4_USB_DMA_REQ2      = 0x00000439u, /* usb.dma_req[2] */
    TRIG_IN_MUX_4_USB_DMA_REQ3      = 0x0000043Au, /* usb.dma_req[3] */
    TRIG_IN_MUX_4_USB_DMA_REQ4      = 0x0000043Bu, /* usb.dma_req[4] */
    TRIG_IN_MUX_4_USB_DMA_REQ5      = 0x0000043Cu, /* usb.dma_req[5] */
    TRIG_IN_MUX_4_USB_DMA_REQ6      = 0x0000043Du, /* usb.dma_req[6] */
    TRIG_IN_MUX_4_USB_DMA_REQ7      = 0x0000043Eu, /* usb.dma_req[7] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT0     = 0x0000043Fu, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT1     = 0x00000440u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT2     = 0x00000441u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT3     = 0x00000442u, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT4     = 0x00000443u, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT5     = 0x00000444u, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT6     = 0x00000445u, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT7     = 0x00000446u, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT8     = 0x00000447u, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT9     = 0x00000448u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT10    = 0x00000449u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT11    = 0x0000044Au, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT12    = 0x0000044Bu, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT13    = 0x0000044Cu, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT14    = 0x0000044Du, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT15    = 0x0000044Eu, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT16    = 0x0000044Fu, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT17    = 0x00000450u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT18    = 0x00000451u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT19    = 0x00000452u, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT20    = 0x00000453u, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT21    = 0x00000454u, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT22    = 0x00000455u, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_4_HSIOM_TR_OUT23    = 0x00000456u, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT0  = 0x00000459u, /* usbhsdev.u2d_tr_out[0] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT1  = 0x0000045Au, /* usbhsdev.u2d_tr_out[1] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT2  = 0x0000045Bu, /* usbhsdev.u2d_tr_out[2] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT3  = 0x0000045Cu, /* usbhsdev.u2d_tr_out[3] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT4  = 0x0000045Du, /* usbhsdev.u2d_tr_out[4] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT5  = 0x0000045Eu, /* usbhsdev.u2d_tr_out[5] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT6  = 0x0000045Fu, /* usbhsdev.u2d_tr_out[6] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT7  = 0x00000460u, /* usbhsdev.u2d_tr_out[7] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT8  = 0x00000461u, /* usbhsdev.u2d_tr_out[8] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT9  = 0x00000462u, /* usbhsdev.u2d_tr_out[9] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT10 = 0x00000463u, /* usbhsdev.u2d_tr_out[10] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT11 = 0x00000464u, /* usbhsdev.u2d_tr_out[11] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT12 = 0x00000465u, /* usbhsdev.u2d_tr_out[12] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT13 = 0x00000466u, /* usbhsdev.u2d_tr_out[13] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT14 = 0x00000467u, /* usbhsdev.u2d_tr_out[14] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT15 = 0x00000468u, /* usbhsdev.u2d_tr_out[15] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT16 = 0x00000469u, /* usbhsdev.u2d_tr_out[16] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT17 = 0x0000046Au, /* usbhsdev.u2d_tr_out[17] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT18 = 0x0000046Bu, /* usbhsdev.u2d_tr_out[18] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT19 = 0x0000046Cu, /* usbhsdev.u2d_tr_out[19] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT20 = 0x0000046Du, /* usbhsdev.u2d_tr_out[20] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT21 = 0x0000046Eu, /* usbhsdev.u2d_tr_out[21] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT22 = 0x0000046Fu, /* usbhsdev.u2d_tr_out[22] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT23 = 0x00000470u, /* usbhsdev.u2d_tr_out[23] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT24 = 0x00000471u, /* usbhsdev.u2d_tr_out[24] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT25 = 0x00000472u, /* usbhsdev.u2d_tr_out[25] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT26 = 0x00000473u, /* usbhsdev.u2d_tr_out[26] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT27 = 0x00000474u, /* usbhsdev.u2d_tr_out[27] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT28 = 0x00000475u, /* usbhsdev.u2d_tr_out[28] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT29 = 0x00000476u, /* usbhsdev.u2d_tr_out[29] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT30 = 0x00000477u, /* usbhsdev.u2d_tr_out[30] */
    TRIG_IN_MUX_4_USBHSDEV_TR_OUT31 = 0x00000478u, /* usbhsdev.u2d_tr_out[31] */
    TRIG_IN_MUX_4_SMIF_TX_REQ       = 0x00000479u, /* smif.tr_tx_req */
    TRIG_IN_MUX_4_SMIF_RX_REQ       = 0x0000047Au, /* smif.tr_rx_req */
    TRIG_IN_MUX_4_PDM_RX_REQ0       = 0x0000047Bu, /* pdm[0].tr_rx_req[0] */
    TRIG_IN_MUX_4_PDM_RX_REQ1       = 0x0000047Cu, /* pdm[0].tr_rx_req[1] */
    TRIG_IN_MUX_4_TDM_TX_REQ        = 0x0000047Du, /* tdm[0].tr_tx_req */
    TRIG_IN_MUX_4_TDM_RX_REQ        = 0x0000047Eu, /* tdm[0].tr_rx_req */
    TRIG_IN_MUX_4_SCB0_TX_REQ       = 0x0000047Fu, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_4_SCB0_RX_REQ       = 0x00000480u, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_4_SCB0_SCL_FILTERED = 0x00000481u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_4_SCB1_TX_REQ       = 0x00000482u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_4_SCB1_RX_REQ       = 0x00000483u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_4_SCB1_SCL_FILTERED = 0x00000484u, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_4_SCB2_TX_REQ       = 0x00000485u, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_4_SCB2_RX_REQ       = 0x00000486u, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_4_SCB2_SCL_FILTERED = 0x00000487u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_4_SCB3_TX_REQ       = 0x00000488u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_4_SCB3_RX_REQ       = 0x00000489u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_4_SCB3_SCL_FILTERED = 0x0000048Au, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_4_CAN_FIFO0         = 0x0000048Bu, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_MUX_4_CAN_FIFO1         = 0x0000048Cu, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_MUX_4_CAN_DBG_DMA       = 0x0000048Du, /* canfd[0].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_4_TCPWM_TR_OVERFLOW0 = 0x0000048Eu, /* tcpwm[0].tr_overflow[0] */
    TRIG_IN_MUX_4_TCPWM_TR_COMPARE_MATCH0 = 0x0000048Fu, /* tcpwm[0].tr_compare_match[0] */
    TRIG_IN_MUX_4_TCPWM_TR_UNDERFLOW0 = 0x00000490u, /* tcpwm[0].tr_underflow[0] */
    TRIG_IN_MUX_4_TCPWM_TR_OVERFLOW1 = 0x00000491u, /* tcpwm[0].tr_overflow[1] */
    TRIG_IN_MUX_4_TCPWM_TR_COMPARE_MATCH1 = 0x00000492u, /* tcpwm[0].tr_compare_match[1] */
    TRIG_IN_MUX_4_TCPWM_TR_UNDERFLOW1 = 0x00000493u, /* tcpwm[0].tr_underflow[1] */
    TRIG_IN_MUX_4_TCPWM_TR_OVERFLOW2 = 0x00000494u, /* tcpwm[0].tr_overflow[2] */
    TRIG_IN_MUX_4_TCPWM_TR_COMPARE_MATCH2 = 0x00000495u, /* tcpwm[0].tr_compare_match[2] */
    TRIG_IN_MUX_4_TCPWM_TR_UNDERFLOW2 = 0x00000496u, /* tcpwm[0].tr_underflow[2] */
    TRIG_IN_MUX_4_TCPWM_TR_OVERFLOW3 = 0x00000497u, /* tcpwm[0].tr_overflow[3] */
    TRIG_IN_MUX_4_TCPWM_TR_COMPARE_MATCH3 = 0x00000498u, /* tcpwm[0].tr_compare_match[3] */
    TRIG_IN_MUX_4_TCPWM_TR_UNDERFLOW3 = 0x00000499u, /* tcpwm[0].tr_underflow[3] */
    TRIG_IN_MUX_4_TCPWM_TR_OVERFLOW4 = 0x0000049Au, /* tcpwm[0].tr_overflow[4] */
    TRIG_IN_MUX_4_TCPWM_TR_COMPARE_MATCH4 = 0x0000049Bu, /* tcpwm[0].tr_compare_match[4] */
    TRIG_IN_MUX_4_TCPWM_TR_UNDERFLOW4 = 0x0000049Cu, /* tcpwm[0].tr_underflow[4] */
    TRIG_IN_MUX_4_TCPWM_TR_OVERFLOW5 = 0x0000049Du, /* tcpwm[0].tr_overflow[5] */
    TRIG_IN_MUX_4_TCPWM_TR_COMPARE_MATCH5 = 0x0000049Eu, /* tcpwm[0].tr_compare_match[5] */
    TRIG_IN_MUX_4_TCPWM_TR_UNDERFLOW5 = 0x0000049Fu, /* tcpwm[0].tr_underflow[5] */
    TRIG_IN_MUX_4_TCPWM_TR_OVERFLOW6 = 0x000004A0u, /* tcpwm[0].tr_overflow[6] */
    TRIG_IN_MUX_4_TCPWM_TR_COMPARE_MATCH6 = 0x000004A1u, /* tcpwm[0].tr_compare_match[6] */
    TRIG_IN_MUX_4_TCPWM_TR_UNDERFLOW6 = 0x000004A2u, /* tcpwm[0].tr_underflow[6] */
    TRIG_IN_MUX_4_TCPWM_TR_OVERFLOW7 = 0x000004A3u, /* tcpwm[0].tr_overflow[7] */
    TRIG_IN_MUX_4_TCPWM_TR_COMPARE_MATCH7 = 0x000004A4u, /* tcpwm[0].tr_compare_match[7] */
    TRIG_IN_MUX_4_TCPWM_TR_UNDERFLOW7 = 0x000004A5u, /* tcpwm[0].tr_underflow[7] */
    TRIG_IN_MUX_4_CAN_TT_TR_OUT0    = 0x000004A6u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT0 = 0x000004A7u, /* lvds2usb32ss.hbwss_otrig_o[0] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT1 = 0x000004A8u, /* lvds2usb32ss.hbwss_otrig_o[1] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT2 = 0x000004A9u, /* lvds2usb32ss.hbwss_otrig_o[2] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT3 = 0x000004AAu, /* lvds2usb32ss.hbwss_otrig_o[3] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT4 = 0x000004ABu, /* lvds2usb32ss.hbwss_otrig_o[4] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT5 = 0x000004ACu, /* lvds2usb32ss.hbwss_otrig_o[5] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT6 = 0x000004ADu, /* lvds2usb32ss.hbwss_otrig_o[6] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT7 = 0x000004AEu, /* lvds2usb32ss.hbwss_otrig_o[7] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT8 = 0x000004AFu, /* lvds2usb32ss.hbwss_otrig_o[8] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT9 = 0x000004B0u, /* lvds2usb32ss.hbwss_otrig_o[9] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT10 = 0x000004B1u, /* lvds2usb32ss.hbwss_otrig_o[10] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT11 = 0x000004B2u, /* lvds2usb32ss.hbwss_otrig_o[11] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT12 = 0x000004B3u, /* lvds2usb32ss.hbwss_otrig_o[12] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT13 = 0x000004B4u, /* lvds2usb32ss.hbwss_otrig_o[13] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT14 = 0x000004B5u, /* lvds2usb32ss.hbwss_otrig_o[14] */
    TRIG_IN_MUX_4_LVDS2USB32SS_TR_OUT15 = 0x000004B6u, /* lvds2usb32ss.hbwss_otrig_o[15] */
    TRIG_IN_MUX_4_SCB4_TX_REQ       = 0x000004C7u, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_4_SCB4_RX_REQ       = 0x000004C8u, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_4_SCB4_SCL_FILTERED = 0x000004C9u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_4_SCB5_TX_REQ       = 0x000004CAu, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_4_SCB5_RX_REQ       = 0x000004CBu, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_4_SCB5_SCL_FILTERED = 0x000004CCu, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_4_SCB6_TX_REQ       = 0x000004CDu, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_4_SCB6_RX_REQ       = 0x000004CEu, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_4_SCB6_SCL_FILTERED = 0x000004CFu /* scb[6].tr_i2c_scl_filtered */
} en_trig_input_cpuss_cti_t;

/* Trigger Input Group 5 - MDMA trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_5_PDMA0_TR_OUT0     = 0x00000501u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT1     = 0x00000502u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT2     = 0x00000503u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT3     = 0x00000504u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT4     = 0x00000505u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT5     = 0x00000506u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT6     = 0x00000507u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT7     = 0x00000508u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT8     = 0x00000509u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT9     = 0x0000050Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT10    = 0x0000050Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT11    = 0x0000050Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT12    = 0x0000050Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT13    = 0x0000050Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT14    = 0x0000050Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT15    = 0x00000510u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT16    = 0x00000511u, /* cpuss.dw0_tr_out[16] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT17    = 0x00000512u, /* cpuss.dw0_tr_out[17] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT18    = 0x00000513u, /* cpuss.dw0_tr_out[18] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT19    = 0x00000514u, /* cpuss.dw0_tr_out[19] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT20    = 0x00000515u, /* cpuss.dw0_tr_out[20] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT21    = 0x00000516u, /* cpuss.dw0_tr_out[21] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT22    = 0x00000517u, /* cpuss.dw0_tr_out[22] */
    TRIG_IN_MUX_5_PDMA0_TR_OUT23    = 0x00000518u, /* cpuss.dw0_tr_out[23] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT0     = 0x00000519u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT1     = 0x0000051Au, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT2     = 0x0000051Bu, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT3     = 0x0000051Cu, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT4     = 0x0000051Du, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT5     = 0x0000051Eu, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT6     = 0x0000051Fu, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT7     = 0x00000520u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT8     = 0x00000521u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT9     = 0x00000522u, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT10    = 0x00000523u, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT11    = 0x00000524u, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT12    = 0x00000525u, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT13    = 0x00000526u, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT14    = 0x00000527u, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT15    = 0x00000528u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT16    = 0x00000529u, /* cpuss.dw1_tr_out[16] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT17    = 0x0000052Au, /* cpuss.dw1_tr_out[17] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT18    = 0x0000052Bu, /* cpuss.dw1_tr_out[18] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT19    = 0x0000052Cu, /* cpuss.dw1_tr_out[19] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT20    = 0x0000052Du, /* cpuss.dw1_tr_out[20] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT21    = 0x0000052Eu, /* cpuss.dw1_tr_out[21] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT22    = 0x0000052Fu, /* cpuss.dw1_tr_out[22] */
    TRIG_IN_MUX_5_PDMA1_TR_OUT23    = 0x00000530u, /* cpuss.dw1_tr_out[23] */
    TRIG_IN_MUX_5_MDMA_TR_OUT0      = 0x00000531u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_5_MDMA_TR_OUT1      = 0x00000532u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_5_MDMA_TR_OUT2      = 0x00000533u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_5_MDMA_TR_OUT3      = 0x00000534u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_5_MDMA_TR_OUT4      = 0x00000535u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_5_MDMA_TR_OUT5      = 0x00000536u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_5_USB_DMA_REQ0      = 0x00000537u, /* usb.dma_req[0] */
    TRIG_IN_MUX_5_USB_DMA_REQ1      = 0x00000538u, /* usb.dma_req[1] */
    TRIG_IN_MUX_5_USB_DMA_REQ2      = 0x00000539u, /* usb.dma_req[2] */
    TRIG_IN_MUX_5_USB_DMA_REQ3      = 0x0000053Au, /* usb.dma_req[3] */
    TRIG_IN_MUX_5_USB_DMA_REQ4      = 0x0000053Bu, /* usb.dma_req[4] */
    TRIG_IN_MUX_5_USB_DMA_REQ5      = 0x0000053Cu, /* usb.dma_req[5] */
    TRIG_IN_MUX_5_USB_DMA_REQ6      = 0x0000053Du, /* usb.dma_req[6] */
    TRIG_IN_MUX_5_USB_DMA_REQ7      = 0x0000053Eu, /* usb.dma_req[7] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT0     = 0x0000053Fu, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT1     = 0x00000540u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT2     = 0x00000541u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT3     = 0x00000542u, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT4     = 0x00000543u, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT5     = 0x00000544u, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT6     = 0x00000545u, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT7     = 0x00000546u, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT8     = 0x00000547u, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT9     = 0x00000548u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT10    = 0x00000549u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT11    = 0x0000054Au, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT12    = 0x0000054Bu, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT13    = 0x0000054Cu, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT14    = 0x0000054Du, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT15    = 0x0000054Eu, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT16    = 0x0000054Fu, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT17    = 0x00000550u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT18    = 0x00000551u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT19    = 0x00000552u, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT20    = 0x00000553u, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT21    = 0x00000554u, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT22    = 0x00000555u, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_5_HSIOM_TR_OUT23    = 0x00000556u, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT0  = 0x00000557u, /* usbhsdev.u2d_tr_out[0] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT1  = 0x00000558u, /* usbhsdev.u2d_tr_out[1] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT2  = 0x00000559u, /* usbhsdev.u2d_tr_out[2] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT3  = 0x0000055Au, /* usbhsdev.u2d_tr_out[3] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT4  = 0x0000055Bu, /* usbhsdev.u2d_tr_out[4] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT5  = 0x0000055Cu, /* usbhsdev.u2d_tr_out[5] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT6  = 0x0000055Du, /* usbhsdev.u2d_tr_out[6] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT7  = 0x0000055Eu, /* usbhsdev.u2d_tr_out[7] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT8  = 0x0000055Fu, /* usbhsdev.u2d_tr_out[8] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT9  = 0x00000560u, /* usbhsdev.u2d_tr_out[9] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT10 = 0x00000561u, /* usbhsdev.u2d_tr_out[10] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT11 = 0x00000562u, /* usbhsdev.u2d_tr_out[11] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT12 = 0x00000563u, /* usbhsdev.u2d_tr_out[12] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT13 = 0x00000564u, /* usbhsdev.u2d_tr_out[13] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT14 = 0x00000565u, /* usbhsdev.u2d_tr_out[14] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT15 = 0x00000566u, /* usbhsdev.u2d_tr_out[15] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT16 = 0x00000567u, /* usbhsdev.u2d_tr_out[16] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT17 = 0x00000568u, /* usbhsdev.u2d_tr_out[17] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT18 = 0x00000569u, /* usbhsdev.u2d_tr_out[18] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT19 = 0x0000056Au, /* usbhsdev.u2d_tr_out[19] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT20 = 0x0000056Bu, /* usbhsdev.u2d_tr_out[20] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT21 = 0x0000056Cu, /* usbhsdev.u2d_tr_out[21] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT22 = 0x0000056Du, /* usbhsdev.u2d_tr_out[22] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT23 = 0x0000056Eu, /* usbhsdev.u2d_tr_out[23] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT24 = 0x0000056Fu, /* usbhsdev.u2d_tr_out[24] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT25 = 0x00000570u, /* usbhsdev.u2d_tr_out[25] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT26 = 0x00000571u, /* usbhsdev.u2d_tr_out[26] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT27 = 0x00000572u, /* usbhsdev.u2d_tr_out[27] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT28 = 0x00000573u, /* usbhsdev.u2d_tr_out[28] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT29 = 0x00000574u, /* usbhsdev.u2d_tr_out[29] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT30 = 0x00000575u, /* usbhsdev.u2d_tr_out[30] */
    TRIG_IN_MUX_5_USBHSDEV_TR_OUT31 = 0x00000576u, /* usbhsdev.u2d_tr_out[31] */
    TRIG_IN_MUX_5_SMIF_TX_REQ       = 0x00000577u, /* smif.tr_tx_req */
    TRIG_IN_MUX_5_SMIF_RX_REQ       = 0x00000578u, /* smif.tr_rx_req */
    TRIG_IN_MUX_5_PDM_RX_REQ0       = 0x00000579u, /* pdm[0].tr_rx_req[0] */
    TRIG_IN_MUX_5_PDM_RX_REQ1       = 0x0000057Au, /* pdm[0].tr_rx_req[1] */
    TRIG_IN_MUX_5_TDM_TX_REQ        = 0x0000057Bu, /* tdm[0].tr_tx_req */
    TRIG_IN_MUX_5_TDM_RX_REQ        = 0x0000057Cu, /* tdm[0].tr_rx_req */
    TRIG_IN_MUX_5_SCB0_TX_REQ       = 0x0000057Du, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_5_SCB0_RX_REQ       = 0x0000057Eu, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_5_SCB0_SCL_FILTERED = 0x0000057Fu, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB1_TX_REQ       = 0x00000580u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_5_SCB1_RX_REQ       = 0x00000581u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_5_SCB1_SCL_FILTERED = 0x00000582u, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB2_TX_REQ       = 0x00000583u, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_5_SCB2_RX_REQ       = 0x00000584u, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_5_SCB2_SCL_FILTERED = 0x00000585u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB3_TX_REQ       = 0x00000586u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_5_SCB3_RX_REQ       = 0x00000587u, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_5_SCB3_SCL_FILTERED = 0x00000588u, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_TCPWM_TR_OVERFLOW0 = 0x00000589u, /* tcpwm[0].tr_overflow[0] */
    TRIG_IN_MUX_5_TCPWM_TR_COMPARE_MATCH0 = 0x0000058Au, /* tcpwm[0].tr_compare_match[0] */
    TRIG_IN_MUX_5_TCPWM_TR_UNDERFLOW0 = 0x0000058Bu, /* tcpwm[0].tr_underflow[0] */
    TRIG_IN_MUX_5_TCPWM_TR_OVERFLOW1 = 0x0000058Cu, /* tcpwm[0].tr_overflow[1] */
    TRIG_IN_MUX_5_TCPWM_TR_COMPARE_MATCH1 = 0x0000058Du, /* tcpwm[0].tr_compare_match[1] */
    TRIG_IN_MUX_5_TCPWM_TR_UNDERFLOW1 = 0x0000058Eu, /* tcpwm[0].tr_underflow[1] */
    TRIG_IN_MUX_5_TCPWM_TR_OVERFLOW2 = 0x0000058Fu, /* tcpwm[0].tr_overflow[2] */
    TRIG_IN_MUX_5_TCPWM_TR_COMPARE_MATCH2 = 0x00000590u, /* tcpwm[0].tr_compare_match[2] */
    TRIG_IN_MUX_5_TCPWM_TR_UNDERFLOW2 = 0x00000591u, /* tcpwm[0].tr_underflow[2] */
    TRIG_IN_MUX_5_TCPWM_TR_OVERFLOW3 = 0x00000592u, /* tcpwm[0].tr_overflow[3] */
    TRIG_IN_MUX_5_TCPWM_TR_COMPARE_MATCH3 = 0x00000593u, /* tcpwm[0].tr_compare_match[3] */
    TRIG_IN_MUX_5_TCPWM_TR_UNDERFLOW3 = 0x00000594u, /* tcpwm[0].tr_underflow[3] */
    TRIG_IN_MUX_5_TCPWM_TR_OVERFLOW4 = 0x00000595u, /* tcpwm[0].tr_overflow[4] */
    TRIG_IN_MUX_5_TCPWM_TR_COMPARE_MATCH4 = 0x00000596u, /* tcpwm[0].tr_compare_match[4] */
    TRIG_IN_MUX_5_TCPWM_TR_UNDERFLOW4 = 0x00000597u, /* tcpwm[0].tr_underflow[4] */
    TRIG_IN_MUX_5_TCPWM_TR_OVERFLOW5 = 0x00000598u, /* tcpwm[0].tr_overflow[5] */
    TRIG_IN_MUX_5_TCPWM_TR_COMPARE_MATCH5 = 0x00000599u, /* tcpwm[0].tr_compare_match[5] */
    TRIG_IN_MUX_5_TCPWM_TR_UNDERFLOW5 = 0x0000059Au, /* tcpwm[0].tr_underflow[5] */
    TRIG_IN_MUX_5_TCPWM_TR_OVERFLOW6 = 0x0000059Bu, /* tcpwm[0].tr_overflow[6] */
    TRIG_IN_MUX_5_TCPWM_TR_COMPARE_MATCH6 = 0x0000059Cu, /* tcpwm[0].tr_compare_match[6] */
    TRIG_IN_MUX_5_TCPWM_TR_UNDERFLOW6 = 0x0000059Du, /* tcpwm[0].tr_underflow[6] */
    TRIG_IN_MUX_5_TCPWM_TR_OVERFLOW7 = 0x0000059Eu, /* tcpwm[0].tr_overflow[7] */
    TRIG_IN_MUX_5_TCPWM_TR_COMPARE_MATCH7 = 0x0000059Fu, /* tcpwm[0].tr_compare_match[7] */
    TRIG_IN_MUX_5_TCPWM_TR_UNDERFLOW7 = 0x000005A0u, /* tcpwm[0].tr_underflow[7] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT0 = 0x000005A1u, /* lvds2usb32ss.hbwss_otrig_o[0] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT1 = 0x000005A2u, /* lvds2usb32ss.hbwss_otrig_o[1] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT2 = 0x000005A3u, /* lvds2usb32ss.hbwss_otrig_o[2] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT3 = 0x000005A4u, /* lvds2usb32ss.hbwss_otrig_o[3] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT4 = 0x000005A5u, /* lvds2usb32ss.hbwss_otrig_o[4] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT5 = 0x000005A6u, /* lvds2usb32ss.hbwss_otrig_o[5] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT6 = 0x000005A7u, /* lvds2usb32ss.hbwss_otrig_o[6] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT7 = 0x000005A8u, /* lvds2usb32ss.hbwss_otrig_o[7] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT8 = 0x000005A9u, /* lvds2usb32ss.hbwss_otrig_o[8] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT9 = 0x000005AAu, /* lvds2usb32ss.hbwss_otrig_o[9] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT10 = 0x000005ABu, /* lvds2usb32ss.hbwss_otrig_o[10] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT11 = 0x000005ACu, /* lvds2usb32ss.hbwss_otrig_o[11] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT12 = 0x000005ADu, /* lvds2usb32ss.hbwss_otrig_o[12] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT13 = 0x000005AEu, /* lvds2usb32ss.hbwss_otrig_o[13] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT14 = 0x000005AFu, /* lvds2usb32ss.hbwss_otrig_o[14] */
    TRIG_IN_MUX_5_LVDS2USB32SS_TR_OUT15 = 0x000005B0u, /* lvds2usb32ss.hbwss_otrig_o[15] */
    TRIG_IN_MUX_5_SCB4_TX_REQ       = 0x000005C1u, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_5_SCB4_RX_REQ       = 0x000005C2u, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_5_SCB4_SCL_FILTERED = 0x000005C3u, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB5_TX_REQ       = 0x000005C4u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_5_SCB5_RX_REQ       = 0x000005C5u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_5_SCB5_SCL_FILTERED = 0x000005C6u, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_SCB6_TX_REQ       = 0x000005C7u, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_5_SCB6_RX_REQ       = 0x000005C8u, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_5_SCB6_SCL_FILTERED = 0x000005C9u, /* scb[6].tr_i2c_scl_filtered */
    TRIG_IN_MUX_5_LVDS2USB32SS_FRM_CNTR_VLD = 0x000005CAu /* lvds2usb32ss.usb32_frm_cntr_vld_o */
} en_trig_input_mdma_t;

/* Trigger Input Group 6 - PERI Freeze trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_6_CTI_TR_OUT0       = 0x00000601u, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_6_CTI_TR_OUT1       = 0x00000602u /* cpuss.cti_tr_out[1] */
} en_trig_input_peri_freeze_t;

/* Trigger Input Group 7 - usb DMA Trigger multiplexer */
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
    TRIG_IN_MUX_7_PDMA0_TR_OUT16    = 0x00000711u, /* cpuss.dw0_tr_out[16] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT17    = 0x00000712u, /* cpuss.dw0_tr_out[17] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT18    = 0x00000713u, /* cpuss.dw0_tr_out[18] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT19    = 0x00000714u, /* cpuss.dw0_tr_out[19] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT20    = 0x00000715u, /* cpuss.dw0_tr_out[20] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT21    = 0x00000716u, /* cpuss.dw0_tr_out[21] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT22    = 0x00000717u, /* cpuss.dw0_tr_out[22] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT23    = 0x00000718u, /* cpuss.dw0_tr_out[23] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT0     = 0x00000719u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT1     = 0x0000071Au, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT2     = 0x0000071Bu, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT3     = 0x0000071Cu, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT4     = 0x0000071Du, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT5     = 0x0000071Eu, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT6     = 0x0000071Fu, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT7     = 0x00000720u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT8     = 0x00000721u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT9     = 0x00000722u, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT10    = 0x00000723u, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT11    = 0x00000724u, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT12    = 0x00000725u, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT13    = 0x00000726u, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT14    = 0x00000727u, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT15    = 0x00000728u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT16    = 0x00000729u, /* cpuss.dw1_tr_out[16] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT17    = 0x0000072Au, /* cpuss.dw1_tr_out[17] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT18    = 0x0000072Bu, /* cpuss.dw1_tr_out[18] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT19    = 0x0000072Cu, /* cpuss.dw1_tr_out[19] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT20    = 0x0000072Du, /* cpuss.dw1_tr_out[20] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT21    = 0x0000072Eu, /* cpuss.dw1_tr_out[21] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT22    = 0x0000072Fu, /* cpuss.dw1_tr_out[22] */
    TRIG_IN_MUX_7_PDMA1_TR_OUT23    = 0x00000730u, /* cpuss.dw1_tr_out[23] */
    TRIG_IN_MUX_7_MDMA_TR_OUT0      = 0x00000731u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_7_MDMA_TR_OUT1      = 0x00000732u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_7_MDMA_TR_OUT2      = 0x00000733u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_7_MDMA_TR_OUT3      = 0x00000734u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_7_MDMA_TR_OUT4      = 0x00000735u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_7_MDMA_TR_OUT5      = 0x00000736u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_7_CTI_TR_OUT0       = 0x00000737u, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_7_CTI_TR_OUT1       = 0x00000738u /* cpuss.cti_tr_out[1] */
} en_trig_input_usb_tr_in_t;

/* Trigger Input Group 8 - USBHSDEV DMA Trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_8_PDMA0_TR_OUT0     = 0x00000801u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT1     = 0x00000802u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT2     = 0x00000803u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT3     = 0x00000804u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT4     = 0x00000805u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT5     = 0x00000806u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT6     = 0x00000807u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT7     = 0x00000808u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT8     = 0x00000809u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT9     = 0x0000080Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT10    = 0x0000080Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT11    = 0x0000080Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT12    = 0x0000080Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT13    = 0x0000080Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT14    = 0x0000080Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT15    = 0x00000810u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT16    = 0x00000811u, /* cpuss.dw0_tr_out[16] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT17    = 0x00000812u, /* cpuss.dw0_tr_out[17] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT18    = 0x00000813u, /* cpuss.dw0_tr_out[18] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT19    = 0x00000814u, /* cpuss.dw0_tr_out[19] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT20    = 0x00000815u, /* cpuss.dw0_tr_out[20] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT21    = 0x00000816u, /* cpuss.dw0_tr_out[21] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT22    = 0x00000817u, /* cpuss.dw0_tr_out[22] */
    TRIG_IN_MUX_8_PDMA0_TR_OUT23    = 0x00000818u, /* cpuss.dw0_tr_out[23] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT0     = 0x00000819u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT1     = 0x0000081Au, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT2     = 0x0000081Bu, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT3     = 0x0000081Cu, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT4     = 0x0000081Du, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT5     = 0x0000081Eu, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT6     = 0x0000081Fu, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT7     = 0x00000820u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT8     = 0x00000821u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT9     = 0x00000822u, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT10    = 0x00000823u, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT11    = 0x00000824u, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT12    = 0x00000825u, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT13    = 0x00000826u, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT14    = 0x00000827u, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT15    = 0x00000828u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT16    = 0x00000829u, /* cpuss.dw1_tr_out[16] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT17    = 0x0000082Au, /* cpuss.dw1_tr_out[17] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT18    = 0x0000082Bu, /* cpuss.dw1_tr_out[18] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT19    = 0x0000082Cu, /* cpuss.dw1_tr_out[19] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT20    = 0x0000082Du, /* cpuss.dw1_tr_out[20] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT21    = 0x0000082Eu, /* cpuss.dw1_tr_out[21] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT22    = 0x0000082Fu, /* cpuss.dw1_tr_out[22] */
    TRIG_IN_MUX_8_PDMA1_TR_OUT23    = 0x00000830u, /* cpuss.dw1_tr_out[23] */
    TRIG_IN_MUX_8_MDMA_TR_OUT0      = 0x00000831u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_8_MDMA_TR_OUT1      = 0x00000832u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_8_MDMA_TR_OUT2      = 0x00000833u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_8_MDMA_TR_OUT3      = 0x00000834u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_8_MDMA_TR_OUT4      = 0x00000835u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_8_MDMA_TR_OUT5      = 0x00000836u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT0     = 0x00000837u, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT1     = 0x00000838u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT2     = 0x00000839u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT3     = 0x0000083Au, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT4     = 0x0000083Bu, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT5     = 0x0000083Cu, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT6     = 0x0000083Du, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT7     = 0x0000083Eu, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT8     = 0x0000083Fu, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT9     = 0x00000840u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT10    = 0x00000841u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT11    = 0x00000842u, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT12    = 0x00000843u, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT13    = 0x00000844u, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT14    = 0x00000845u, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT15    = 0x00000846u, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT16    = 0x00000847u, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT17    = 0x00000848u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT18    = 0x00000849u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT19    = 0x0000084Au, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT20    = 0x0000084Bu, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT21    = 0x0000084Cu, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT22    = 0x0000084Du, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_8_HSIOM_TR_OUT23    = 0x0000084Eu, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_8_TCPWM_TR_OVERFLOW0 = 0x0000084Fu, /* tcpwm[0].tr_overflow[0] */
    TRIG_IN_MUX_8_TCPWM_TR_COMPARE_MATCH0 = 0x00000850u, /* tcpwm[0].tr_compare_match[0] */
    TRIG_IN_MUX_8_TCPWM_TR_UNDERFLOW0 = 0x00000851u, /* tcpwm[0].tr_underflow[0] */
    TRIG_IN_MUX_8_TCPWM_TR_OVERFLOW1 = 0x00000852u, /* tcpwm[0].tr_overflow[1] */
    TRIG_IN_MUX_8_TCPWM_TR_COMPARE_MATCH1 = 0x00000853u, /* tcpwm[0].tr_compare_match[1] */
    TRIG_IN_MUX_8_TCPWM_TR_UNDERFLOW1 = 0x00000854u, /* tcpwm[0].tr_underflow[1] */
    TRIG_IN_MUX_8_TCPWM_TR_OVERFLOW2 = 0x00000855u, /* tcpwm[0].tr_overflow[2] */
    TRIG_IN_MUX_8_TCPWM_TR_COMPARE_MATCH2 = 0x00000856u, /* tcpwm[0].tr_compare_match[2] */
    TRIG_IN_MUX_8_TCPWM_TR_UNDERFLOW2 = 0x00000857u, /* tcpwm[0].tr_underflow[2] */
    TRIG_IN_MUX_8_TCPWM_TR_OVERFLOW3 = 0x00000858u, /* tcpwm[0].tr_overflow[3] */
    TRIG_IN_MUX_8_TCPWM_TR_COMPARE_MATCH3 = 0x00000859u, /* tcpwm[0].tr_compare_match[3] */
    TRIG_IN_MUX_8_TCPWM_TR_UNDERFLOW3 = 0x0000085Au, /* tcpwm[0].tr_underflow[3] */
    TRIG_IN_MUX_8_TCPWM_TR_OVERFLOW4 = 0x0000085Bu, /* tcpwm[0].tr_overflow[4] */
    TRIG_IN_MUX_8_TCPWM_TR_COMPARE_MATCH4 = 0x0000085Cu, /* tcpwm[0].tr_compare_match[4] */
    TRIG_IN_MUX_8_TCPWM_TR_UNDERFLOW4 = 0x0000085Du, /* tcpwm[0].tr_underflow[4] */
    TRIG_IN_MUX_8_TCPWM_TR_OVERFLOW5 = 0x0000085Eu, /* tcpwm[0].tr_overflow[5] */
    TRIG_IN_MUX_8_TCPWM_TR_COMPARE_MATCH5 = 0x0000085Fu, /* tcpwm[0].tr_compare_match[5] */
    TRIG_IN_MUX_8_TCPWM_TR_UNDERFLOW5 = 0x00000860u, /* tcpwm[0].tr_underflow[5] */
    TRIG_IN_MUX_8_TCPWM_TR_OVERFLOW6 = 0x00000861u, /* tcpwm[0].tr_overflow[6] */
    TRIG_IN_MUX_8_TCPWM_TR_COMPARE_MATCH6 = 0x00000862u, /* tcpwm[0].tr_compare_match[6] */
    TRIG_IN_MUX_8_TCPWM_TR_UNDERFLOW6 = 0x00000863u, /* tcpwm[0].tr_underflow[6] */
    TRIG_IN_MUX_8_TCPWM_TR_OVERFLOW7 = 0x00000864u, /* tcpwm[0].tr_overflow[7] */
    TRIG_IN_MUX_8_TCPWM_TR_COMPARE_MATCH7 = 0x00000865u, /* tcpwm[0].tr_compare_match[7] */
    TRIG_IN_MUX_8_TCPWM_TR_UNDERFLOW7 = 0x00000866u, /* tcpwm[0].tr_underflow[7] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT0  = 0x00000867u, /* usbhsdev.u2d_tr_out[0] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT1  = 0x00000868u, /* usbhsdev.u2d_tr_out[1] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT2  = 0x00000869u, /* usbhsdev.u2d_tr_out[2] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT3  = 0x0000086Au, /* usbhsdev.u2d_tr_out[3] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT4  = 0x0000086Bu, /* usbhsdev.u2d_tr_out[4] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT5  = 0x0000086Cu, /* usbhsdev.u2d_tr_out[5] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT6  = 0x0000086Du, /* usbhsdev.u2d_tr_out[6] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT7  = 0x0000086Eu, /* usbhsdev.u2d_tr_out[7] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT8  = 0x0000086Fu, /* usbhsdev.u2d_tr_out[8] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT9  = 0x00000870u, /* usbhsdev.u2d_tr_out[9] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT10 = 0x00000871u, /* usbhsdev.u2d_tr_out[10] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT11 = 0x00000872u, /* usbhsdev.u2d_tr_out[11] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT12 = 0x00000873u, /* usbhsdev.u2d_tr_out[12] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT13 = 0x00000874u, /* usbhsdev.u2d_tr_out[13] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT14 = 0x00000875u, /* usbhsdev.u2d_tr_out[14] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT15 = 0x00000876u, /* usbhsdev.u2d_tr_out[15] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT16 = 0x00000877u, /* usbhsdev.u2d_tr_out[16] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT17 = 0x00000878u, /* usbhsdev.u2d_tr_out[17] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT18 = 0x00000879u, /* usbhsdev.u2d_tr_out[18] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT19 = 0x0000087Au, /* usbhsdev.u2d_tr_out[19] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT20 = 0x0000087Bu, /* usbhsdev.u2d_tr_out[20] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT21 = 0x0000087Cu, /* usbhsdev.u2d_tr_out[21] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT22 = 0x0000087Du, /* usbhsdev.u2d_tr_out[22] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT23 = 0x0000087Eu, /* usbhsdev.u2d_tr_out[23] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT24 = 0x0000087Fu, /* usbhsdev.u2d_tr_out[24] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT25 = 0x00000880u, /* usbhsdev.u2d_tr_out[25] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT26 = 0x00000881u, /* usbhsdev.u2d_tr_out[26] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT27 = 0x00000882u, /* usbhsdev.u2d_tr_out[27] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT28 = 0x00000883u, /* usbhsdev.u2d_tr_out[28] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT29 = 0x00000884u, /* usbhsdev.u2d_tr_out[29] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT30 = 0x00000885u, /* usbhsdev.u2d_tr_out[30] */
    TRIG_IN_MUX_8_USBHSDEV_TR_OUT31 = 0x00000886u, /* usbhsdev.u2d_tr_out[31] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT0 = 0x00000887u, /* lvds2usb32ss.hbwss_otrig_o[0] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT1 = 0x00000888u, /* lvds2usb32ss.hbwss_otrig_o[1] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT2 = 0x00000889u, /* lvds2usb32ss.hbwss_otrig_o[2] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT3 = 0x0000088Au, /* lvds2usb32ss.hbwss_otrig_o[3] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT4 = 0x0000088Bu, /* lvds2usb32ss.hbwss_otrig_o[4] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT5 = 0x0000088Cu, /* lvds2usb32ss.hbwss_otrig_o[5] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT6 = 0x0000088Du, /* lvds2usb32ss.hbwss_otrig_o[6] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT7 = 0x0000088Eu, /* lvds2usb32ss.hbwss_otrig_o[7] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT8 = 0x0000088Fu, /* lvds2usb32ss.hbwss_otrig_o[8] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT9 = 0x00000890u, /* lvds2usb32ss.hbwss_otrig_o[9] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT10 = 0x00000891u, /* lvds2usb32ss.hbwss_otrig_o[10] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT11 = 0x00000892u, /* lvds2usb32ss.hbwss_otrig_o[11] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT12 = 0x00000893u, /* lvds2usb32ss.hbwss_otrig_o[12] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT13 = 0x00000894u, /* lvds2usb32ss.hbwss_otrig_o[13] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT14 = 0x00000895u, /* lvds2usb32ss.hbwss_otrig_o[14] */
    TRIG_IN_MUX_8_LVDS2USB32SS_TR_OUT15 = 0x00000896u /* lvds2usb32ss.hbwss_otrig_o[15] */
} en_trig_input_usbhsdev_tr_in_t;

/* Trigger Input Group 9 - LVDS2USB32SS DMA Trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_9_PDMA0_TR_OUT0     = 0x00000901u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT1     = 0x00000902u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT2     = 0x00000903u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT3     = 0x00000904u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT4     = 0x00000905u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT5     = 0x00000906u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT6     = 0x00000907u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT7     = 0x00000908u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT8     = 0x00000909u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT9     = 0x0000090Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT10    = 0x0000090Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT11    = 0x0000090Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT12    = 0x0000090Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT13    = 0x0000090Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT14    = 0x0000090Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT15    = 0x00000910u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT16    = 0x00000911u, /* cpuss.dw0_tr_out[16] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT17    = 0x00000912u, /* cpuss.dw0_tr_out[17] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT18    = 0x00000913u, /* cpuss.dw0_tr_out[18] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT19    = 0x00000914u, /* cpuss.dw0_tr_out[19] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT20    = 0x00000915u, /* cpuss.dw0_tr_out[20] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT21    = 0x00000916u, /* cpuss.dw0_tr_out[21] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT22    = 0x00000917u, /* cpuss.dw0_tr_out[22] */
    TRIG_IN_MUX_9_PDMA0_TR_OUT23    = 0x00000918u, /* cpuss.dw0_tr_out[23] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT0     = 0x00000919u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT1     = 0x0000091Au, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT2     = 0x0000091Bu, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT3     = 0x0000091Cu, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT4     = 0x0000091Du, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT5     = 0x0000091Eu, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT6     = 0x0000091Fu, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT7     = 0x00000920u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT8     = 0x00000921u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT9     = 0x00000922u, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT10    = 0x00000923u, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT11    = 0x00000924u, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT12    = 0x00000925u, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT13    = 0x00000926u, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT14    = 0x00000927u, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT15    = 0x00000928u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT16    = 0x00000929u, /* cpuss.dw1_tr_out[16] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT17    = 0x0000092Au, /* cpuss.dw1_tr_out[17] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT18    = 0x0000092Bu, /* cpuss.dw1_tr_out[18] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT19    = 0x0000092Cu, /* cpuss.dw1_tr_out[19] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT20    = 0x0000092Du, /* cpuss.dw1_tr_out[20] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT21    = 0x0000092Eu, /* cpuss.dw1_tr_out[21] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT22    = 0x0000092Fu, /* cpuss.dw1_tr_out[22] */
    TRIG_IN_MUX_9_PDMA1_TR_OUT23    = 0x00000930u, /* cpuss.dw1_tr_out[23] */
    TRIG_IN_MUX_9_MDMA_TR_OUT0      = 0x00000931u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_9_MDMA_TR_OUT1      = 0x00000932u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_9_MDMA_TR_OUT2      = 0x00000933u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_9_MDMA_TR_OUT3      = 0x00000934u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_9_MDMA_TR_OUT4      = 0x00000935u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_9_MDMA_TR_OUT5      = 0x00000936u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT0     = 0x00000937u, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT1     = 0x00000938u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT2     = 0x00000939u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT3     = 0x0000093Au, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT4     = 0x0000093Bu, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT5     = 0x0000093Cu, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT6     = 0x0000093Du, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT7     = 0x0000093Eu, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT8     = 0x0000093Fu, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT9     = 0x00000940u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT10    = 0x00000941u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT11    = 0x00000942u, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT12    = 0x00000943u, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT13    = 0x00000944u, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT14    = 0x00000945u, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT15    = 0x00000946u, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT16    = 0x00000947u, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT17    = 0x00000948u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT18    = 0x00000949u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT19    = 0x0000094Au, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT20    = 0x0000094Bu, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT21    = 0x0000094Cu, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT22    = 0x0000094Du, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_9_HSIOM_TR_OUT23    = 0x0000094Eu, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_9_TCPWM_TR_OVERFLOW0 = 0x0000094Fu, /* tcpwm[0].tr_overflow[0] */
    TRIG_IN_MUX_9_TCPWM_TR_COMPARE_MATCH0 = 0x00000950u, /* tcpwm[0].tr_compare_match[0] */
    TRIG_IN_MUX_9_TCPWM_TR_UNDERFLOW0 = 0x00000951u, /* tcpwm[0].tr_underflow[0] */
    TRIG_IN_MUX_9_TCPWM_TR_OVERFLOW1 = 0x00000952u, /* tcpwm[0].tr_overflow[1] */
    TRIG_IN_MUX_9_TCPWM_TR_COMPARE_MATCH1 = 0x00000953u, /* tcpwm[0].tr_compare_match[1] */
    TRIG_IN_MUX_9_TCPWM_TR_UNDERFLOW1 = 0x00000954u, /* tcpwm[0].tr_underflow[1] */
    TRIG_IN_MUX_9_TCPWM_TR_OVERFLOW2 = 0x00000955u, /* tcpwm[0].tr_overflow[2] */
    TRIG_IN_MUX_9_TCPWM_TR_COMPARE_MATCH2 = 0x00000956u, /* tcpwm[0].tr_compare_match[2] */
    TRIG_IN_MUX_9_TCPWM_TR_UNDERFLOW2 = 0x00000957u, /* tcpwm[0].tr_underflow[2] */
    TRIG_IN_MUX_9_TCPWM_TR_OVERFLOW3 = 0x00000958u, /* tcpwm[0].tr_overflow[3] */
    TRIG_IN_MUX_9_TCPWM_TR_COMPARE_MATCH3 = 0x00000959u, /* tcpwm[0].tr_compare_match[3] */
    TRIG_IN_MUX_9_TCPWM_TR_UNDERFLOW3 = 0x0000095Au, /* tcpwm[0].tr_underflow[3] */
    TRIG_IN_MUX_9_TCPWM_TR_OVERFLOW4 = 0x0000095Bu, /* tcpwm[0].tr_overflow[4] */
    TRIG_IN_MUX_9_TCPWM_TR_COMPARE_MATCH4 = 0x0000095Cu, /* tcpwm[0].tr_compare_match[4] */
    TRIG_IN_MUX_9_TCPWM_TR_UNDERFLOW4 = 0x0000095Du, /* tcpwm[0].tr_underflow[4] */
    TRIG_IN_MUX_9_TCPWM_TR_OVERFLOW5 = 0x0000095Eu, /* tcpwm[0].tr_overflow[5] */
    TRIG_IN_MUX_9_TCPWM_TR_COMPARE_MATCH5 = 0x0000095Fu, /* tcpwm[0].tr_compare_match[5] */
    TRIG_IN_MUX_9_TCPWM_TR_UNDERFLOW5 = 0x00000960u, /* tcpwm[0].tr_underflow[5] */
    TRIG_IN_MUX_9_TCPWM_TR_OVERFLOW6 = 0x00000961u, /* tcpwm[0].tr_overflow[6] */
    TRIG_IN_MUX_9_TCPWM_TR_COMPARE_MATCH6 = 0x00000962u, /* tcpwm[0].tr_compare_match[6] */
    TRIG_IN_MUX_9_TCPWM_TR_UNDERFLOW6 = 0x00000963u, /* tcpwm[0].tr_underflow[6] */
    TRIG_IN_MUX_9_TCPWM_TR_OVERFLOW7 = 0x00000964u, /* tcpwm[0].tr_overflow[7] */
    TRIG_IN_MUX_9_TCPWM_TR_COMPARE_MATCH7 = 0x00000965u, /* tcpwm[0].tr_compare_match[7] */
    TRIG_IN_MUX_9_TCPWM_TR_UNDERFLOW7 = 0x00000966u, /* tcpwm[0].tr_underflow[7] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT0  = 0x00000967u, /* usbhsdev.u2d_tr_out[0] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT1  = 0x00000968u, /* usbhsdev.u2d_tr_out[1] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT2  = 0x00000969u, /* usbhsdev.u2d_tr_out[2] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT3  = 0x0000096Au, /* usbhsdev.u2d_tr_out[3] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT4  = 0x0000096Bu, /* usbhsdev.u2d_tr_out[4] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT5  = 0x0000096Cu, /* usbhsdev.u2d_tr_out[5] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT6  = 0x0000096Du, /* usbhsdev.u2d_tr_out[6] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT7  = 0x0000096Eu, /* usbhsdev.u2d_tr_out[7] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT8  = 0x0000096Fu, /* usbhsdev.u2d_tr_out[8] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT9  = 0x00000970u, /* usbhsdev.u2d_tr_out[9] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT10 = 0x00000971u, /* usbhsdev.u2d_tr_out[10] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT11 = 0x00000972u, /* usbhsdev.u2d_tr_out[11] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT12 = 0x00000973u, /* usbhsdev.u2d_tr_out[12] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT13 = 0x00000974u, /* usbhsdev.u2d_tr_out[13] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT14 = 0x00000975u, /* usbhsdev.u2d_tr_out[14] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT15 = 0x00000976u, /* usbhsdev.u2d_tr_out[15] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT16 = 0x00000977u, /* usbhsdev.u2d_tr_out[16] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT17 = 0x00000978u, /* usbhsdev.u2d_tr_out[17] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT18 = 0x00000979u, /* usbhsdev.u2d_tr_out[18] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT19 = 0x0000097Au, /* usbhsdev.u2d_tr_out[19] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT20 = 0x0000097Bu, /* usbhsdev.u2d_tr_out[20] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT21 = 0x0000097Cu, /* usbhsdev.u2d_tr_out[21] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT22 = 0x0000097Du, /* usbhsdev.u2d_tr_out[22] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT23 = 0x0000097Eu, /* usbhsdev.u2d_tr_out[23] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT24 = 0x0000097Fu, /* usbhsdev.u2d_tr_out[24] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT25 = 0x00000980u, /* usbhsdev.u2d_tr_out[25] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT26 = 0x00000981u, /* usbhsdev.u2d_tr_out[26] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT27 = 0x00000982u, /* usbhsdev.u2d_tr_out[27] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT28 = 0x00000983u, /* usbhsdev.u2d_tr_out[28] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT29 = 0x00000984u, /* usbhsdev.u2d_tr_out[29] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT30 = 0x00000985u, /* usbhsdev.u2d_tr_out[30] */
    TRIG_IN_MUX_9_USBHSDEV_TR_OUT31 = 0x00000986u, /* usbhsdev.u2d_tr_out[31] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT0 = 0x00000987u, /* lvds2usb32ss.hbwss_otrig_o[0] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT1 = 0x00000988u, /* lvds2usb32ss.hbwss_otrig_o[1] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT2 = 0x00000989u, /* lvds2usb32ss.hbwss_otrig_o[2] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT3 = 0x0000098Au, /* lvds2usb32ss.hbwss_otrig_o[3] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT4 = 0x0000098Bu, /* lvds2usb32ss.hbwss_otrig_o[4] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT5 = 0x0000098Cu, /* lvds2usb32ss.hbwss_otrig_o[5] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT6 = 0x0000098Du, /* lvds2usb32ss.hbwss_otrig_o[6] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT7 = 0x0000098Eu, /* lvds2usb32ss.hbwss_otrig_o[7] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT8 = 0x0000098Fu, /* lvds2usb32ss.hbwss_otrig_o[8] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT9 = 0x00000990u, /* lvds2usb32ss.hbwss_otrig_o[9] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT10 = 0x00000991u, /* lvds2usb32ss.hbwss_otrig_o[10] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT11 = 0x00000992u, /* lvds2usb32ss.hbwss_otrig_o[11] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT12 = 0x00000993u, /* lvds2usb32ss.hbwss_otrig_o[12] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT13 = 0x00000994u, /* lvds2usb32ss.hbwss_otrig_o[13] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT14 = 0x00000995u, /* lvds2usb32ss.hbwss_otrig_o[14] */
    TRIG_IN_MUX_9_LVDS2USB32SS_TR_OUT15 = 0x00000996u /* lvds2usb32ss.hbwss_otrig_o[15] */
} en_trig_input_lvds2usb32ss_tr_in_t;

/* Trigger Input Group 10 - CAN TT Synchronization triggers */
typedef enum
{
    TRIG_IN_MUX_10_CAN_TT_TR_OUT0   = 0x00000A00u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT0    = 0x00000A01u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT1    = 0x00000A02u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT2    = 0x00000A03u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT3    = 0x00000A04u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT4    = 0x00000A05u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT5    = 0x00000A06u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT6    = 0x00000A07u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT7    = 0x00000A08u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT8    = 0x00000A09u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT9    = 0x00000A0Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT10   = 0x00000A0Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT11   = 0x00000A0Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT12   = 0x00000A0Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT13   = 0x00000A0Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT14   = 0x00000A0Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT15   = 0x00000A10u /* cpuss.dw0_tr_out[15] */
} en_trig_input_cantt_t;

/* Trigger Input Group 11 - TCPWM and PDM trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_11_TCPWM_TR_OVERFLOW0 = 0x00000B00u, /* tcpwm[0].tr_overflow[0] */
    TRIG_IN_MUX_11_TCPWM_TR_COMPARE_MATCH0 = 0x00000B01u, /* tcpwm[0].tr_compare_match[0] */
    TRIG_IN_MUX_11_TCPWM_TR_UNDERFLOW0 = 0x00000B02u, /* tcpwm[0].tr_underflow[0] */
    TRIG_IN_MUX_11_TCPWM_TR_OVERFLOW1 = 0x00000B03u, /* tcpwm[0].tr_overflow[1] */
    TRIG_IN_MUX_11_TCPWM_TR_COMPARE_MATCH1 = 0x00000B04u, /* tcpwm[0].tr_compare_match[1] */
    TRIG_IN_MUX_11_TCPWM_TR_UNDERFLOW1 = 0x00000B05u, /* tcpwm[0].tr_underflow[1] */
    TRIG_IN_MUX_11_TCPWM_TR_OVERFLOW2 = 0x00000B06u, /* tcpwm[0].tr_overflow[2] */
    TRIG_IN_MUX_11_TCPWM_TR_COMPARE_MATCH2 = 0x00000B07u, /* tcpwm[0].tr_compare_match[2] */
    TRIG_IN_MUX_11_TCPWM_TR_UNDERFLOW2 = 0x00000B08u, /* tcpwm[0].tr_underflow[2] */
    TRIG_IN_MUX_11_TCPWM_TR_OVERFLOW3 = 0x00000B09u, /* tcpwm[0].tr_overflow[3] */
    TRIG_IN_MUX_11_TCPWM_TR_COMPARE_MATCH3 = 0x00000B0Au, /* tcpwm[0].tr_compare_match[3] */
    TRIG_IN_MUX_11_TCPWM_TR_UNDERFLOW3 = 0x00000B0Bu, /* tcpwm[0].tr_underflow[3] */
    TRIG_IN_MUX_11_TCPWM_TR_OVERFLOW4 = 0x00000B0Cu, /* tcpwm[0].tr_overflow[4] */
    TRIG_IN_MUX_11_TCPWM_TR_COMPARE_MATCH4 = 0x00000B0Du, /* tcpwm[0].tr_compare_match[4] */
    TRIG_IN_MUX_11_TCPWM_TR_UNDERFLOW4 = 0x00000B0Eu, /* tcpwm[0].tr_underflow[4] */
    TRIG_IN_MUX_11_TCPWM_TR_OVERFLOW5 = 0x00000B0Fu, /* tcpwm[0].tr_overflow[5] */
    TRIG_IN_MUX_11_TCPWM_TR_COMPARE_MATCH5 = 0x00000B10u, /* tcpwm[0].tr_compare_match[5] */
    TRIG_IN_MUX_11_TCPWM_TR_UNDERFLOW5 = 0x00000B11u, /* tcpwm[0].tr_underflow[5] */
    TRIG_IN_MUX_11_TCPWM_TR_OVERFLOW6 = 0x00000B12u, /* tcpwm[0].tr_overflow[6] */
    TRIG_IN_MUX_11_TCPWM_TR_COMPARE_MATCH6 = 0x00000B13u, /* tcpwm[0].tr_compare_match[6] */
    TRIG_IN_MUX_11_TCPWM_TR_UNDERFLOW6 = 0x00000B14u, /* tcpwm[0].tr_underflow[6] */
    TRIG_IN_MUX_11_TCPWM_TR_OVERFLOW7 = 0x00000B15u, /* tcpwm[0].tr_overflow[7] */
    TRIG_IN_MUX_11_TCPWM_TR_COMPARE_MATCH7 = 0x00000B16u, /* tcpwm[0].tr_compare_match[7] */
    TRIG_IN_MUX_11_TCPWM_TR_UNDERFLOW7 = 0x00000B17u, /* tcpwm[0].tr_underflow[7] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT0    = 0x00000B18u, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT1    = 0x00000B19u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT2    = 0x00000B1Au, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT3    = 0x00000B1Bu, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT4    = 0x00000B1Cu, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT5    = 0x00000B1Du, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT6    = 0x00000B1Eu, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT7    = 0x00000B1Fu, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT8    = 0x00000B20u, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT9    = 0x00000B21u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT10   = 0x00000B22u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT11   = 0x00000B23u, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT12   = 0x00000B24u, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT13   = 0x00000B25u, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT14   = 0x00000B26u, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT15   = 0x00000B27u, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT16   = 0x00000B28u, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT17   = 0x00000B29u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT18   = 0x00000B2Au, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT19   = 0x00000B2Bu, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT20   = 0x00000B2Cu, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT21   = 0x00000B2Du, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT22   = 0x00000B2Eu, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_11_HSIOM_TR_OUT23   = 0x00000B2Fu /* peri.tr_io_input[23] */
} en_trig_input_tcpwm_pdm_t;

/* Trigger Input Group 12 - PDM TDM Freeze trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_12_CTI_TR_OUT0      = 0x00000C00u, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_12_CTI_TR_OUT1      = 0x00000C01u /* cpuss.cti_tr_out[1] */
} en_trig_input_pdm_tdm_freeze_t;

/* Trigger Group Outputs */
/* Trigger Output Group 0 - PDMA0 Request Assignments */
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

/* Trigger Output Group 1 - PDMA1 Request Assignments */
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

/* Trigger Output Group 2 - TCPWM0 trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_2_TCPWM_TR_IN0     = 0x40000200u, /* tcpwm[0].tr_in[0] */
    TRIG_OUT_MUX_2_TCPWM_TR_IN1     = 0x40000201u, /* tcpwm[0].tr_in[1] */
    TRIG_OUT_MUX_2_TCPWM_TR_IN2     = 0x40000202u, /* tcpwm[0].tr_in[2] */
    TRIG_OUT_MUX_2_TCPWM_TR_IN3     = 0x40000203u, /* tcpwm[0].tr_in[3] */
    TRIG_OUT_MUX_2_TCPWM_TR_IN4     = 0x40000204u, /* tcpwm[0].tr_in[4] */
    TRIG_OUT_MUX_2_TCPWM_TR_IN5     = 0x40000205u, /* tcpwm[0].tr_in[5] */
    TRIG_OUT_MUX_2_TCPWM_TR_IN6     = 0x40000206u, /* tcpwm[0].tr_in[6] */
    TRIG_OUT_MUX_2_TCPWM_TR_IN7     = 0x40000207u /* tcpwm[0].tr_in[7] */
} en_trig_output_tcpwm0_t;

/* Trigger Output Group 3 - IO trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_3_PERI_IO_OUT0     = 0x40000300u, /* peri.tr_io_output[0] */
    TRIG_OUT_MUX_3_PERI_IO_OUT1     = 0x40000301u /* peri.tr_io_output[1] */
} en_trig_output_ioss_t;

/* Trigger Output Group 4 - IO trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_4_CPUSS_CTI_TR_IN0 = 0x40000400u, /* cpuss.cti_tr_in[0] */
    TRIG_OUT_MUX_4_CPUSS_CTI_TR_IN1 = 0x40000401u /* cpuss.cti_tr_in[1] */
} en_trig_output_cpuss_cti_t;

/* Trigger Output Group 5 - MDMA trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_5_MDMA_TR_IN0      = 0x40000500u, /* cpuss.dmac_tr_in[0] */
    TRIG_OUT_MUX_5_MDMA_TR_IN1      = 0x40000501u, /* cpuss.dmac_tr_in[1] */
    TRIG_OUT_MUX_5_MDMA_TR_IN2      = 0x40000502u, /* cpuss.dmac_tr_in[2] */
    TRIG_OUT_MUX_5_MDMA_TR_IN3      = 0x40000503u, /* cpuss.dmac_tr_in[3] */
    TRIG_OUT_MUX_5_MDMA_TR_IN4      = 0x40000504u, /* cpuss.dmac_tr_in[4] */
    TRIG_OUT_MUX_5_MDMA_TR_IN5      = 0x40000505u /* cpuss.dmac_tr_in[5] */
} en_trig_output_mdma_t;

/* Trigger Output Group 6 - PERI Freeze trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_6_PERI_DEBUG_FREEZE_TR_IN = 0x40000600u /* peri.tr_dbg_freeze */
} en_trig_output_peri_freeze_t;

/* Trigger Output Group 7 - usb DMA Trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_7_USB_DMA_BURSTEND0 = 0x40000700u, /* usb.dma_burstend[0] */
    TRIG_OUT_MUX_7_USB_DMA_BURSTEND1 = 0x40000701u, /* usb.dma_burstend[1] */
    TRIG_OUT_MUX_7_USB_DMA_BURSTEND2 = 0x40000702u, /* usb.dma_burstend[2] */
    TRIG_OUT_MUX_7_USB_DMA_BURSTEND3 = 0x40000703u, /* usb.dma_burstend[3] */
    TRIG_OUT_MUX_7_USB_DMA_BURSTEND4 = 0x40000704u, /* usb.dma_burstend[4] */
    TRIG_OUT_MUX_7_USB_DMA_BURSTEND5 = 0x40000705u, /* usb.dma_burstend[5] */
    TRIG_OUT_MUX_7_USB_DMA_BURSTEND6 = 0x40000706u, /* usb.dma_burstend[6] */
    TRIG_OUT_MUX_7_USB_DMA_BURSTEND7 = 0x40000707u /* usb.dma_burstend[7] */
} en_trig_output_usb_tr_in_t;

/* Trigger Output Group 8 - USBHSDEV DMA Trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN0  = 0x40000800u, /* usbhsdev.u2d_tr_in[0] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN1  = 0x40000801u, /* usbhsdev.u2d_tr_in[1] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN2  = 0x40000802u, /* usbhsdev.u2d_tr_in[2] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN3  = 0x40000803u, /* usbhsdev.u2d_tr_in[3] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN4  = 0x40000804u, /* usbhsdev.u2d_tr_in[4] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN5  = 0x40000805u, /* usbhsdev.u2d_tr_in[5] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN6  = 0x40000806u, /* usbhsdev.u2d_tr_in[6] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN7  = 0x40000807u, /* usbhsdev.u2d_tr_in[7] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN8  = 0x40000808u, /* usbhsdev.u2d_tr_in[8] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN9  = 0x40000809u, /* usbhsdev.u2d_tr_in[9] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN10 = 0x4000080Au, /* usbhsdev.u2d_tr_in[10] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN11 = 0x4000080Bu, /* usbhsdev.u2d_tr_in[11] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN12 = 0x4000080Cu, /* usbhsdev.u2d_tr_in[12] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN13 = 0x4000080Du, /* usbhsdev.u2d_tr_in[13] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN14 = 0x4000080Eu, /* usbhsdev.u2d_tr_in[14] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN15 = 0x4000080Fu, /* usbhsdev.u2d_tr_in[15] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN16 = 0x40000810u, /* usbhsdev.u2d_tr_in[16] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN17 = 0x40000811u, /* usbhsdev.u2d_tr_in[17] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN18 = 0x40000812u, /* usbhsdev.u2d_tr_in[18] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN19 = 0x40000813u, /* usbhsdev.u2d_tr_in[19] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN20 = 0x40000814u, /* usbhsdev.u2d_tr_in[20] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN21 = 0x40000815u, /* usbhsdev.u2d_tr_in[21] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN22 = 0x40000816u, /* usbhsdev.u2d_tr_in[22] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN23 = 0x40000817u, /* usbhsdev.u2d_tr_in[23] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN24 = 0x40000818u, /* usbhsdev.u2d_tr_in[24] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN25 = 0x40000819u, /* usbhsdev.u2d_tr_in[25] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN26 = 0x4000081Au, /* usbhsdev.u2d_tr_in[26] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN27 = 0x4000081Bu, /* usbhsdev.u2d_tr_in[27] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN28 = 0x4000081Cu, /* usbhsdev.u2d_tr_in[28] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN29 = 0x4000081Du, /* usbhsdev.u2d_tr_in[29] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN30 = 0x4000081Eu, /* usbhsdev.u2d_tr_in[30] */
    TRIG_OUT_MUX_8_USBHSDEV_TR_IN31 = 0x4000081Fu /* usbhsdev.u2d_tr_in[31] */
} en_trig_output_usbhsdev_tr_in_t;

/* Trigger Output Group 9 - LVDS2USB32SS DMA Trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN0 = 0x40000900u, /* lvds2usb32ss.hbwss_itrig_i[0] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN1 = 0x40000901u, /* lvds2usb32ss.hbwss_itrig_i[1] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN2 = 0x40000902u, /* lvds2usb32ss.hbwss_itrig_i[2] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN3 = 0x40000903u, /* lvds2usb32ss.hbwss_itrig_i[3] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN4 = 0x40000904u, /* lvds2usb32ss.hbwss_itrig_i[4] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN5 = 0x40000905u, /* lvds2usb32ss.hbwss_itrig_i[5] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN6 = 0x40000906u, /* lvds2usb32ss.hbwss_itrig_i[6] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN7 = 0x40000907u, /* lvds2usb32ss.hbwss_itrig_i[7] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN8 = 0x40000908u, /* lvds2usb32ss.hbwss_itrig_i[8] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN9 = 0x40000909u, /* lvds2usb32ss.hbwss_itrig_i[9] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN10 = 0x4000090Au, /* lvds2usb32ss.hbwss_itrig_i[10] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN11 = 0x4000090Bu, /* lvds2usb32ss.hbwss_itrig_i[11] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN12 = 0x4000090Cu, /* lvds2usb32ss.hbwss_itrig_i[12] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN13 = 0x4000090Du, /* lvds2usb32ss.hbwss_itrig_i[13] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN14 = 0x4000090Eu, /* lvds2usb32ss.hbwss_itrig_i[14] */
    TRIG_OUT_MUX_9_LVDSUSB32SS_TR_IN15 = 0x4000090Fu /* lvds2usb32ss.hbwss_itrig_i[15] */
} en_trig_output_lvds2usb32ss_tr_in_t;

/* Trigger Output Group 10 - CAN TT Synchronization triggers */
typedef enum
{
    TRIG_OUT_MUX_10_CAN_TT_TR_IN0   = 0x40000A00u, /* canfd[0].tr_evt_swt_in[0] */
    TRIG_OUT_MUX_10_CAN_TT_DBG_IN0  = 0x40000A01u /* canfd[0].tr_dbg_dma_ack[0] */
} en_trig_output_cantt_t;

/* Trigger Output Group 11 - TCPWM and PDM trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_11_PDM_TR_ACTIVATE0 = 0x40000B00u, /* pdm[0].tr_activate[0] */
    TRIG_OUT_MUX_11_PDM_TR_ACTIVATE1 = 0x40000B01u /* pdm[0].tr_activate[1] */
} en_trig_output_tcpwm_pdm_t;

/* Trigger Output Group 12 - PDM TDM Freeze trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_12_TDM_DEBUG_FREEZE_TR_IN = 0x40000C00u, /* tdm[0].tr_dbg_freeze */
    TRIG_OUT_MUX_12_PDM_DEBUG_FREEZE_TR_IN = 0x40000C01u /* pdm[0].tr_dbg_freeze */
} en_trig_output_pdm_tdm_freeze_t;

/* Trigger Output Group 0 - SCB PDMA0 Triggers (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_0_SCB0_TX_TO_PDMA0_TR_IN16 = 0x40001000u, /* From scb[0].tr_tx_req to cpuss.dw0_tr_in[16] */
    TRIG_OUT_1TO1_0_SCB0_RX_TO_PDMA0_TR_IN17 = 0x40001001u, /* From scb[0].tr_rx_req to cpuss.dw0_tr_in[17] */
    TRIG_OUT_1TO1_0_SCB1_TX_TO_PDMA0_TR_IN18 = 0x40001002u, /* From scb[1].tr_tx_req to cpuss.dw0_tr_in[18] */
    TRIG_OUT_1TO1_0_SCB1_RX_TO_PDMA0_TR_IN19 = 0x40001003u /* From scb[1].tr_rx_req to cpuss.dw0_tr_in[19] */
} en_trig_output_1to1_scb_pdma0_tr_t;

/* Trigger Output Group 1 - SCB PDMA1 Triggers (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_1_SCB0_TX_TO_PDMA1_TR_IN16 = 0x40001100u, /* From scb[2].tr_tx_req to cpuss.dw1_tr_in[16] */
    TRIG_OUT_1TO1_1_SCB0_RX_TO_PDMA1_TR_IN17 = 0x40001101u, /* From scb[2].tr_rx_req to cpuss.dw1_tr_in[17] */
    TRIG_OUT_1TO1_1_SCB0_TX_TO_PDMA1_TR_IN18 = 0x40001102u, /* From scb[3].tr_tx_req to cpuss.dw1_tr_in[18] */
    TRIG_OUT_1TO1_1_SCB0_RX_TO_PDMA1_TR_IN19 = 0x40001103u /* From scb[3].tr_rx_req to cpuss.dw1_tr_in[19] */
} en_trig_output_1to1_scb_pdma1_tr_t;

/* Trigger Output Group 2 -  (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_2_SMIF_TX_TO_PDMA0_TR_IN20 = 0x40001200u, /* From smif.tr_tx_req to cpuss.dw0_tr_in[20] */
    TRIG_OUT_1TO1_2_SMIF_RX_TO_PDMA0_TR_IN21 = 0x40001201u /* From smif.tr_rx_req to cpuss.dw0_tr_in[21] */
} en_trig_output_1to1_smif_to_pdma0_t;

/* Trigger Output Group 3 - USB PDMA0 Triggers (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_3_PDM_RX0_TO_PDMA1_TR_IN20 = 0x40001300u, /* From pdm[0].tr_rx_req[0] to cpuss.dw1_tr_in[20] */
    TRIG_OUT_1TO1_3_PDM_RX1_TO_PDMA1_TR_IN21 = 0x40001301u /* From pdm[0].tr_rx_req[1] to cpuss.dw1_tr_in[21] */
} en_trig_output_1to1_pdm_pdma1_tr_t;

/* Trigger Output Group 4 - TDM PDMA1 Triggers (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_4_TDM_TX_TO_PDMA1_TR_IN22 = 0x40001400u, /* From tdm[0].tr_tx_req to cpuss.dw1_tr_in[22] */
    TRIG_OUT_1TO1_4_TDM_TX_TO_PDMA1_TR_IN23 = 0x40001401u /* From tdm[0].tr_rx_req to cpuss.dw1_tr_in[23] */
} en_trig_output_1to1_tdm_pdma1_tr_t;

/* Trigger Output Group 5 - CAN DW triggers (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_5_CAN_FIFO0_TO_PDMA0_TR_IN22 = 0x40001500u, /* From canfd[0].tr_fifo0[0] to cpuss.dw0_tr_in[22] */
    TRIG_OUT_1TO1_5_CAN_FIFO1_TO_PDMA0_TR_IN23 = 0x40001501u /* From canfd[0].tr_fifo1[0] to cpuss.dw0_tr_in[23] */
} en_trig_output_1to1_can_dw_tr_t;

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
#define TRIGGER_TYPE_CPUSS_CTI_TR_IN            TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_CTI_TR_OUT           TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DMAC_TR_IN__LEVEL    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DMAC_TR_IN__EDGE     TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DMAC_TR_OUT          TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW0_TR_IN__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DW0_TR_IN__EDGE      TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW0_TR_OUT           TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW1_TR_IN__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DW1_TR_IN__EDGE      TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW1_TR_OUT           TRIGGER_TYPE_EDGE
/* LVDS2USB32SS Trigger Types */
#define TRIGGER_TYPE_LVDS2USB32SS_HBWSS_ITRIG_I TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_LVDS2USB32SS_HBWSS_OTRIG_O TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_LVDS2USB32SS_USB32_FRM_CNTR_VLD_O TRIGGER_TYPE_LEVEL
/* PDM Trigger Types */
#define TRIGGER_TYPE_PDM_TR_ACTIVATE            TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PDM_TR_DBG_FREEZE          TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PDM_TR_RX_REQ              TRIGGER_TYPE_LEVEL
/* PERI Trigger Types */
#define TRIGGER_TYPE_PERI_TR_DBG_FREEZE         TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__LEVEL    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__EDGE     TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__LEVEL   TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__EDGE    TRIGGER_TYPE_EDGE
/* SCB Trigger Types */
#define TRIGGER_TYPE_SCB_TR_I2C_SCL_FILTERED    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_RX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_TX_REQ              TRIGGER_TYPE_LEVEL
/* SMIF Trigger Types */
#define TRIGGER_TYPE_SMIF_TR_RX_REQ             TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SMIF_TR_TX_REQ             TRIGGER_TYPE_LEVEL
/* TCPWM Trigger Types */
#define TRIGGER_TYPE_TCPWM_LINE                 TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_TCPWM_LINE_COMPL           TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_TCPWM_TR_COMPARE_MATCH     TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_TCPWM_TR_IN__LEVEL         TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_TCPWM_TR_IN__EDGE          TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_TCPWM_TR_OVERFLOW          TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_TCPWM_TR_UNDERFLOW         TRIGGER_TYPE_EDGE
/* TDM Trigger Types */
#define TRIGGER_TYPE_TDM_TR_DBG_FREEZE          TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_TDM_TR_RX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_TDM_TR_TX_REQ              TRIGGER_TYPE_LEVEL
/* USB Trigger Types */
#define TRIGGER_TYPE_USB_DMA_BURSTEND           TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_USB_DMA_REQ                TRIGGER_TYPE_EDGE
/* USBHSDEV Trigger Types */
#define TRIGGER_TYPE_USBHSDEV_U2D_TR_IN         TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_USBHSDEV_U2D_TR_OUT        TRIGGER_TYPE_LEVEL

/* Fault connections */
typedef enum
{
    CPUSS_MPU_VIO_0                 = 0x0000u,
    CPUSS_MPU_VIO_1                 = 0x0001u,
    CPUSS_MPU_VIO_2                 = 0x0002u,
    CPUSS_MPU_VIO_3                 = 0x0003u,
    CPUSS_MPU_VIO_4                 = 0x0004u,
    CPUSS_MPU_VIO_14                = 0x000Eu,
    CPUSS_MPU_VIO_15                = 0x000Fu,
    CPUSS_MPU_VIO_16                = 0x0010u,
    CPUSS_MPU_VIO_17                = 0x0011u,
    CPUSS_MPU_VIO_18                = 0x0012u,
    PERI_MS_VIO_0                   = 0x001Cu,
    PERI_MS_VIO_1                   = 0x001Du,
    PERI_MS_VIO_2                   = 0x001Eu,
    PERI_MS_VIO_3                   = 0x001Fu,
    PERI_GROUP_VIO_0                = 0x0020u,
    PERI_GROUP_VIO_1                = 0x0021u,
    PERI_GROUP_VIO_2                = 0x0022u,
    PERI_GROUP_VIO_3                = 0x0023u,
    PERI_GROUP_VIO_4                = 0x0024u,
    PERI_GROUP_VIO_5                = 0x0025u,
    PERI_GROUP_VIO_6                = 0x0026u,
    CPUSS_FLASHC_MAIN_BUS_ERR       = 0x0030u
} en_sysfault_source_t;

/* Bus masters */
typedef enum
{
    CPUSS_MS_ID_CM0                 =  0,
    CPUSS_MS_ID_CRYPTO              =  1,
    CPUSS_MS_ID_DW0                 =  2,
    CPUSS_MS_ID_DW1                 =  3,
    CPUSS_MS_ID_DMAC                =  4,
    CPUSS_MS_ID_SLOW0               =  5,
    CPUSS_MS_ID_SLOW1               =  6,
    CPUSS_MS_ID_CM4                 = 14,
    CPUSS_MS_ID_TC                  = 15
} en_prot_master_t;

/* Pointer to device configuration structure */
#define CY_DEVICE_CFG                   (&cy_deviceIpBlockCfgFX3G2)

/* Include IP definitions */
#include "ip/cyip_sflash_fx3g2.h"
#include "ip/cyip_peri_v2.h"
#include "ip/cyip_peri_ms_v2.h"
#include "ip/cyip_crypto_v2.h"
#include "ip/cyip_cpuss_v2.h"
#include "ip/cyip_fault_v2.h"
#include "ip/cyip_ipc_v2.h"
#include "ip/cyip_prot_v2.h"
#include "ip/cyip_flashc_v2.h"
#include "ip/cyip_srss.h"
#include "ip/cyip_dw_v2.h"
#include "ip/cyip_dmac_v2.h"
#include "ip/cyip_efuse.h"
#include "ip/cyip_efuse_data_fx3g2.h"
#include "ip/cyip_hsiom_v5.h"
#include "ip/cyip_gpio_v5.h"
#include "ip/cyip_mxpdm.h"
#include "ip/cyip_tcpwm.h"
#include "ip/cyip_smif.h"
#include "ip/cyip_usbfs.h"
#include "ip/cyip_mxs40usbhsdev.h"
#include "ip/cyip_scb.h"
#include "ip/cyip_canfd.h"
#include "ip/cyip_tdm_v2.h"
#include "ip/cyip_main_reg.h"
#include "ip/cyip_usb32dev.h"
#include "ip/cyip_lvdsss.h"
#include "ip/cyip_backup.h"

/* IP type definitions */
typedef SFLASH_V1_Type SFLASH_Type;
typedef PERI_GR_V2_Type PERI_GR_Type;
typedef PERI_TR_GR_V2_Type PERI_TR_GR_Type;
typedef PERI_TR_1TO1_GR_V2_Type PERI_TR_1TO1_GR_Type;
typedef PERI_V2_Type PERI_Type;
typedef PERI_MS_PPU_PR_V2_Type PERI_MS_PPU_PR_Type;
typedef PERI_MS_PPU_FX_V2_Type PERI_MS_PPU_FX_Type;
typedef PERI_MS_V2_Type PERI_MS_Type;
typedef CRYPTO_V2_Type CRYPTO_Type;
typedef CPUSS_V2_Type CPUSS_Type;
typedef FAULT_STRUCT_V2_Type FAULT_STRUCT_Type;
typedef FAULT_V2_Type FAULT_Type;
typedef IPC_STRUCT_V2_Type IPC_STRUCT_Type;
typedef IPC_INTR_STRUCT_V2_Type IPC_INTR_STRUCT_Type;
typedef IPC_V2_Type IPC_Type;
typedef PROT_SMPU_SMPU_STRUCT_V2_Type PROT_SMPU_SMPU_STRUCT_Type;
typedef PROT_SMPU_V2_Type PROT_SMPU_Type;
typedef PROT_MPU_MPU_STRUCT_V2_Type PROT_MPU_MPU_STRUCT_Type;
typedef PROT_MPU_V2_Type PROT_MPU_Type;
typedef PROT_V2_Type PROT_Type;
typedef FLASHC_FM_CTL_V2_Type FLASHC_FM_CTL_Type;
typedef FLASHC_V2_Type FLASHC_Type;
typedef MCWDT_STRUCT_V1_Type MCWDT_STRUCT_Type;
typedef SRSS_V1_Type SRSS_Type;
typedef DW_CH_STRUCT_V2_Type DW_CH_STRUCT_Type;
typedef DW_V2_Type DW_Type;
typedef DMAC_CH_V2_Type DMAC_CH_Type;
typedef DMAC_V2_Type DMAC_Type;
typedef EFUSE_V1_Type EFUSE_Type;
typedef HSIOM_PRT_V5_Type HSIOM_PRT_Type;
typedef HSIOM_V5_Type HSIOM_Type;
typedef GPIO_PRT_V5_Type GPIO_PRT_Type;
typedef GPIO_V5_Type GPIO_Type;
typedef PDM_CH_V1_Type PDM_CH_Type;
typedef PDM_V1_Type PDM_Type;
typedef TCPWM_CNT_V1_Type TCPWM_CNT_Type;
typedef TCPWM_V1_Type TCPWM_Type;
typedef SMIF_DEVICE_V1_Type SMIF_DEVICE_Type;
typedef SMIF_V1_Type SMIF_Type;
typedef USBFS_USBDEV_V1_Type USBFS_USBDEV_Type;
typedef USBFS_USBLPM_V1_Type USBFS_USBLPM_Type;
typedef USBFS_USBHOST_V1_Type USBFS_USBHOST_Type;
typedef USBFS_V1_Type USBFS_Type;
typedef USBHSDEV_V1_Type USBHSDEV_Type;
typedef USBHSPHY_V1_Type USBHSPHY_Type;
typedef MXS40USBHSDEV_V1_Type MXS40USBHSDEV_Type;
typedef CySCB_V1_Type CySCB_Type;
typedef CANFD_CH_M_TTCAN_V1_Type CANFD_CH_M_TTCAN_Type;
typedef CANFD_CH_V1_Type CANFD_CH_Type;
typedef CANFD_V1_Type CANFD_Type;
typedef BACKUP_V1_Type BACKUP_Type;
typedef TDM_TDM_STRUCT_TDM_TX_STRUCT_V2_Type TDM_TDM_STRUCT_TDM_TX_STRUCT_Type;
typedef TDM_TDM_STRUCT_TDM_RX_STRUCT_V2_Type TDM_TDM_STRUCT_TDM_RX_STRUCT_Type;
typedef TDM_TDM_STRUCT_V2_Type TDM_TDM_STRUCT_Type;
typedef TDM_V2_Type TDM_Type;
typedef MAIN_REG_TR_GR_V1_Type MAIN_REG_TR_GR_Type;
typedef MAIN_REG_TR_ASSIST_GR_V1_Type MAIN_REG_TR_ASSIST_GR_Type;
typedef MAIN_REG_V1_Type MAIN_REG_Type;
typedef USB32DEV_MAIN_V1_Type USB32DEV_MAIN_Type;
typedef USB32DEV_EPM_V1_Type USB32DEV_EPM_Type;
typedef USB32DEV_LNK_V1_Type USB32DEV_LNK_Type;
typedef USB32DEV_PROT_V1_Type USB32DEV_PROT_Type;
typedef USB32DEV_PHYSS_USB40PHY_TOP_V1_Type USB32DEV_PHYSS_USB40PHY_TOP_Type;
typedef USB32DEV_PHYSS_USB40PHY_RX_V1_Type USB32DEV_PHYSS_USB40PHY_RX_Type;
typedef USB32DEV_PHYSS_USB40PHY_PLL_SYS_V1_Type USB32DEV_PHYSS_USB40PHY_PLL_SYS_Type;
typedef USB32DEV_PHYSS_USB40PHY_V1_Type USB32DEV_PHYSS_USB40PHY_Type;
typedef USB32DEV_PHYSS_V1_Type USB32DEV_PHYSS_Type;
typedef USB32DEV_ADAPTER_DMA_SCK_V1_Type USB32DEV_ADAPTER_DMA_SCK_Type;
typedef USB32DEV_ADAPTER_DMA_SCK_GBL_V1_Type USB32DEV_ADAPTER_DMA_SCK_GBL_Type;
typedef USB32DEV_ADAPTER_DMA_V1_Type USB32DEV_ADAPTER_DMA_Type;
typedef USB32DEV_V1_Type USB32DEV_Type;
typedef LVDSSS_LVDS_LVDS_LOW_PWR_INTR_V1_Type LVDSSS_LVDS_LVDS_LOW_PWR_INTR_Type;
typedef LVDSSS_LVDS_THREAD_V1_Type LVDSSS_LVDS_THREAD_Type;
typedef LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_V1_Type LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type;
typedef LVDSSS_LVDS_GPIF_LEFT_V1_Type LVDSSS_LVDS_GPIF_LEFT_Type;
typedef LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_V1_Type LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type;
typedef LVDSSS_LVDS_GPIF_RIGHT_V1_Type LVDSSS_LVDS_GPIF_RIGHT_Type;
typedef LVDSSS_LVDS_GPIF_V1_Type LVDSSS_LVDS_GPIF_Type;
typedef LVDSSS_LVDS_AFE_V1_Type LVDSSS_LVDS_AFE_Type;
typedef LVDSSS_LVDS_ADAPTER_DMA_SCK_V1_Type LVDSSS_LVDS_ADAPTER_DMA_SCK_Type;
typedef LVDSSS_LVDS_ADAPTER_DMA_SCK_GBL_V1_Type LVDSSS_LVDS_ADAPTER_DMA_SCK_GBL_Type;
typedef LVDSSS_LVDS_ADAPTER_DMA_V1_Type LVDSSS_LVDS_ADAPTER_DMA_Type;
typedef LVDSSS_LVDS_V1_Type LVDSSS_LVDS_Type;
typedef LVDSSS_V1_Type LVDSSS_Type;

/* Parameter Defines */
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
/* UDB present or not ('0': no, '1': yes) */
#define CPUSS_UDB_PRESENT               0u
/* MBIST MMIO for Synopsys MBIST ('0': no, '1': yes). Set this to '1' only for the
   chips which doesn't use mxdft. */
#define CPUSS_MBIST_MMIO_PRESENT        1u
/* System RAM 0 size in kilobytes */
#define CPUSS_SRAM0_SIZE                128u
/* Number of macros used to implement System RAM 0. Example: 8 if 256 KB System
   SRAM0 is implemented with 8 32KB macros. */
#define CPUSS_RAMC0_MACRO_NR            4u
/* System RAM 1 present or not (0=No, 1=Yes) */
#define CPUSS_RAMC1_PRESENT             0u
/* System RAM 1 size in kilobytes */
#define CPUSS_SRAM1_SIZE                1u
/* Number of macros used to implement System RAM 1. Example: 8 if 256 KB System
   RAM 1 is implemented with 8 32KB macros. */
#define CPUSS_RAMC1_MACRO_NR            1u
/* System RAM 2 present or not (0=No, 1=Yes) */
#define CPUSS_RAMC2_PRESENT             0u
/* System RAM 2 size in kilobytes */
#define CPUSS_SRAM2_SIZE                1u
/* Number of macros used to implement System RAM 2. Example: 8 if 256 KB System
   RAM 2 is implemented with 8 32KB macros. */
#define CPUSS_RAMC2_MACRO_NR            1u
/* System SRAM(s) ECC present or not ('0': no, '1': yes) */
#define CPUSS_RAMC_ECC_PRESENT          0u
/* System SRAM(s) address ECC present or not ('0': no, '1': yes) */
#define CPUSS_RAMC_ECC_ADDR_PRESENT     0u
/* ECC present in either system RAM or interrupt handler (RAMC_ECC_PRESENT) */
#define CPUSS_ECC_PRESENT               0u
/* DataWire SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_PRESENT            0u
/* DataWire SRAMs address ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_ADDR_PRESENT       0u
/* System ROM size in KB */
#define CPUSS_ROM_SIZE                  128u
/* Number of macros used to implement system ROM. Example: 4 if 512 KB system ROM
   is implemented with 4 128KB macros. */
#define CPUSS_ROMC_MACRO_NR             2u
/* Flash memory present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_PRESENT            1u
/* Flash memory type ('0' : SONOS, '1': ECT) */
#define CPUSS_FLASHC_ECT                0u
/* Flash main region size in KB */
#define CPUSS_FLASH_SIZE                512u
/* Flash work region size in KB (EEPROM emulation, data) */
#define CPUSS_WFLASH_SIZE               32u
/* Flash supervisory region size in KB */
#define CPUSS_SFLASH_SIZE               32u
/* Flash data output word size (in Bytes) */
#define CPUSS_FLASHC_MAIN_DATA_WIDTH    16u
/* SONOS Flash RWW present or not ('0': no, '1': yes) When RWW is '0', No special
   sectors present in Flash. Part of main sector 0 is allowcated for Supervisory
   Flash, and no Work Flash present. */
#define CPUSS_FLASHC_SONOS_RWW          1u
/* SONOS Flash, number of main sectors. */
#define CPUSS_FLASHC_SONOS_MAIN_SECTORS 2u
/* SONOS Flash, number of rows per main sector. */
#define CPUSS_FLASHC_SONOS_MAIN_ROWS    512u
/* SONOS Flash, number of words per row of main sector. */
#define CPUSS_FLASHC_SONOS_MAIN_WORDS   128u
/* SONOS Flash, number of special sectors. */
#define CPUSS_FLASHC_SONOS_SPL_SECTORS  2u
/* SONOS Flash, number of rows per special sector. */
#define CPUSS_FLASHC_SONOS_SPL_ROWS     64u
/* Flash memory ECC present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_FLASH_ECC_PRESENT  0u
/* Flash cache SRAM(s) ECC present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_RAM_ECC_PRESENT    0u
/* Number of external slaves directly connected to slow AHB-Lite infrastructure.
   Maximum nubmer of slave supported is 4. Width of this parameter is 4-bits.
   1-bit mask for each slave indicating present or not. Example: 4'b0011 - slave
   0 and slave 1 are present. Note: The SLOW_SLx_ADDR and SLOW_SLx_MASK
   parameters (for the slaves present) should be derived from the Memory Map. */
#define CPUSS_SLOW_SL_PRESENT           7u
/* Number of external slaves directly connected to fast AHB-Lite infrastructure.
   Maximum nubmer of slave supported is 4. Width of this parameter is 4-bits.
   1-bit mask for each slave indicating present or not. Example: 4'b0011 - slave
   0 and slave 1 are present. Note: The FAST_SLx_ADDR and FAST_SLx_MASK
   parameters (for the slaves present) should be derived from the Memory Map. */
#define CPUSS_FAST_SL_PRESENT           3u
/* Number of external masters driving the slow AHB-Lite infrastructure. Maximum
   number of masters supported is 2. Width of this parameter is 2-bits. 1-bit
   mask for each master indicating present or not. Example: 2'b01 - master 0 is
   present. */
#define CPUSS_SLOW_MS_PRESENT           0u
/* System interrupt functionality present or not ('0': no; '1': yes). Not used for
   CM0+ PCU, which always uses system interrupt functionality. */
#define CPUSS_SYSTEM_IRQ_PRESENT        0u
/* Number of total interrupt request inputs to CPUSS */
#define CPUSS_SYSTEM_INT_NR             142u
/* Number of DeepSleep wakeup interrupt inputs to CPUSS */
#define CPUSS_SYSTEM_DPSLP_INT_NR       46u
/* CM4 CPU present or not ('0': no, '1': yes) */
#define CPUSS_CM4_PRESENT               1u
/* Width of the CM4 interrupt priority bits. Legal range [3,8] Example: 3 = 8
   levels of priority 8 = 256 levels of priority */
#define CPUSS_CM4_LVL_WIDTH             3u
/* CM4 Floating point unit present or not (0=No, 1=Yes) */
#define CPUSS_CM4_FPU_PRESENT           1u
/* Debug level. Legal range [0,3] (0= No support, 1= Minimum: CM0/4 both 2
   breakpoints +1 watchpoint, 2= Full debug: CM0/4 have 4/6 breakpoints, 2/4
   watchpoints and 0/2 literal compare, 3= Full debug + data matching) */
#define CPUSS_DEBUG_LVL                 3u
/* Trace level. Legal range [0,2] (0= No tracing, 1= ITM + TPIU + SWO, 2= ITM +
   ETM + TPIU + SWO) Note: CM4 HTM is not supported. Hence vaule 3 for trace
   level is not supported in CPUSS. */
#define CPUSS_TRACE_LVL                 2u
/* Embedded Trace Buffer present or not (0=No, 1=Yes) */
#define CPUSS_ETB_PRESENT               0u
/* CM0+ MTB SRAM buffer size in kilobytes. Legal vaules 4, 8 or 16 */
#define CPUSS_MTB_SRAM_SIZE             4u
/* CM4 ETB SRAM buffer size in kilobytes. Legal vaules 4, 8 or 16 */
#define CPUSS_ETB_SRAM_SIZE             8u
/* PTM interface present (0=No, 1=Yes) */
#define CPUSS_PTM_PRESENT               0u
/* Width of the PTM interface in bits ([2,32]) */
#define CPUSS_PTM_WIDTH                 1u
/* Width of the TPIU interface in bits ([1,4]) */
#define CPUSS_TPIU_WIDTH                4u
/* CoreSight Part Identification Number */
#define CPUSS_JEPID                     52u
/* CoreSight Part Identification Number */
#define CPUSS_JEPCONTINUATION           0u
/* CoreSight Part Identification Number */
#define CPUSS_FAMILYID                  284u
/* ROM trim register width (for ARM 3, for Synopsys 5) */
#define CPUSS_ROM_TRIM_WIDTH            5u
/* ROM trim register default (for both ARM and Synopsys 0x0000_0012) */
#define CPUSS_ROM_TRIM_DEFAULT          18u
/* RAM trim register width (for ARM 8, for Synopsys 15) */
#define CPUSS_RAM_TRIM_WIDTH            15u
/* RAM trim register default (for ARM 0x0000_0062 and for Synopsys 0x0000_6012) */
#define CPUSS_RAM_TRIM_DEFAULT          0x00006012u
/* Cryptography IP present or not (0=No, 1=Yes) */
#define CPUSS_CRYPTO_PRESENT            1u
/* DataWire and DMAC SW trigger per channel present or not ('0': no, '1': yes) */
#define CPUSS_SW_TR_PRESENT             0u
/* DataWire 0 present or not (0=No, 1=Yes) */
#define CPUSS_DW0_PRESENT               1u
/* Number of DataWire 0 channels (8, 16 or 32) */
#define CPUSS_DW0_CH_NR                 24u
/* DataWire 1 present or not (0=No, 1=Yes) */
#define CPUSS_DW1_PRESENT               1u
/* Number of DataWire 1 channels (8, 16 or 32) */
#define CPUSS_DW1_CH_NR                 24u
/* DMA controller present or not ('0': no, '1': yes) */
#define CPUSS_DMAC_PRESENT              1u
/* Number of DMA controller channels ([1, 8]) */
#define CPUSS_DMAC_CH_NR                6u
/* DMAC SW trigger per channel present or not ('0': no, '1': yes) */
#define CPUSS_CH_SW_TR_PRESENT          0u
/* Copy value from Globals */
#define CPUSS_CHIP_TOP_PROFILER_PRESENT 0u
/* ETAS Calibration support pin out present (automotive only) */
#define CPUSS_CHIP_TOP_CAL_SUP_NZ_PRESENT 0u
/* TRACE_LVL>0 */
#define CPUSS_CHIP_TOP_TRACE_PRESENT    1u
/* DataWire SW trigger per channel present or not ('0': no, '1': yes) */
#define CPUSS_CH_STRUCT_SW_TR_PRESENT   0u
/* Number of DataWire controllers present (max 2) (same as DW.NR above) */
#define CPUSS_CPUSS_DW_DW_NR            2u
/* Number of channels in each DataWire controller */
#define CPUSS_CPUSS_DW_DW_NR0_DW_CH_NR  24u
/* Width of a channel number in bits */
#define CPUSS_CPUSS_DW_DW_NR0_DW_CH_NR_WIDTH 5u
/* Number of channels in each DataWire controller */
#define CPUSS_CPUSS_DW_DW_NR1_DW_CH_NR  24u
/* Width of a channel number in bits */
#define CPUSS_CPUSS_DW_DW_NR1_DW_CH_NR_WIDTH 5u
/* Cryptography SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_CRYPTO_ECC_PRESENT        0u
/* Cryptography SRAMs address ECC present or not ('0': no, '1': yes) */
#define CPUSS_CRYPTO_ECC_ADDR_PRESENT   0u
/* AES cipher support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_AES                1u
/* (Tripple) DES cipher support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_DES                1u
/* Chacha support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_CHACHA             1u
/* Pseudo random number generation support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_PR                 1u
/* SHA1 hash support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_SHA1               1u
/* SHA2 hash support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_SHA2               1u
/* SHA3 hash support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_SHA3               1u
/* Cyclic Redundancy Check support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_CRC                1u
/* True random number generation support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_TR                 1u
/* Vector unit support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_VU                 1u
/* Galios/Counter Mode (GCM) support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_GCM                1u
/* Number of 32-bit words in the IP internal memory buffer (from the set [64, 128,
   256, 512, 1024, 2048, 4096], to allow for a 256 B, 512 B, 1 kB, 2 kB, 4 kB, 8
   kB and 16 kB memory buffer) */
#define CPUSS_CRYPTO_BUFF_SIZE          2048u
/* Number of DMA controller channels ([1, 8]) */
#define CPUSS_DMAC_CH_NR                6u
/* Number of DataWire controllers present (max 2) */
#define CPUSS_DW_NR                     2u
/* DataWire SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_PRESENT            0u
/* Number of fault structures. Legal range [1, 4] */
#define CPUSS_FAULT_FAULT_NR            2u
/* Number of Flash BIST_DATA registers */
#define CPUSS_FLASHC_FLASHC_BIST_DATA_NR 4u
/* Page size in # of 32-bit words (1: 4 bytes, 2: 8 bytes, ... */
#define CPUSS_FLASHC_PA_SIZE            128u
/* SONOS Flash is used or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_FLASHC_IS_SONOS    1u
/* eCT Flash is used or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_FLASHC_IS_ECT      0u
/* CM4 CPU present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_CM4_PRESENT        1u
/* Number of IPC structures. Legal range [1, 16] */
#define CPUSS_IPC_IPC_NR                16u
/* Number of IPC interrupt structures. Legal range [1, 16] */
#define CPUSS_IPC_IPC_IRQ_NR            16u
/* Master 0 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS0_PC_NR_MINUS1 7u
/* Master 1 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS1_PC_NR_MINUS1 0u
/* Master 2 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS2_PC_NR_MINUS1 0u
/* Master 3 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS3_PC_NR_MINUS1 0u
/* Master 4 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS4_PC_NR_MINUS1 0u
/* Master 5 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS5_PC_NR_MINUS1 0u
/* Master 6 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS6_PC_NR_MINUS1 0u
/* Master 7 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS7_PC_NR_MINUS1 0u
/* Master 8 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS8_PC_NR_MINUS1 0u
/* Master 9 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS9_PC_NR_MINUS1 0u
/* Master 10 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS10_PC_NR_MINUS1 0u
/* Master 11 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS11_PC_NR_MINUS1 0u
/* Master 12 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS12_PC_NR_MINUS1 0u
/* Master 13 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS13_PC_NR_MINUS1 0u
/* Master 14 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS14_PC_NR_MINUS1 7u
/* Master 15 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS15_PC_NR_MINUS1 7u
/* Number of SMPU protection structures */
#define CPUSS_PROT_SMPU_STRUCT_NR       16u
/* Number of protection contexts supported minus 1. Legal range [1,16] */
#define CPUSS_SMPU_STRUCT_PC_NR_MINUS1  7u
/* Number of instantiated eFUSE macros (256 bit macros). Legal range [1, 16] */
#define EFUSE_EFUSE_NR                  4u
/* Number of GPIO ports in range 0..31 */
#define IOSS_GPIO_GPIO_PORT_NR_0_31     14u
/* Number of GPIO ports in range 32..63 */
#define IOSS_GPIO_GPIO_PORT_NR_32_63    0u
/* Number of GPIO ports in range 64..95 */
#define IOSS_GPIO_GPIO_PORT_NR_64_95    0u
/* Number of GPIO ports in range 96..127 */
#define IOSS_GPIO_GPIO_PORT_NR_96_127   0u
/* Number of ports in device */
#define IOSS_GPIO_GPIO_PORT_NR          14u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SIO 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLEW_WIDTH 3u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_AUTOLVL 1u
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
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLEW_WIDTH 3u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO1 1u
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
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO 0u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SIO 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLEW_EXT 0u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLEW_WIDTH 0u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_AUTOLVL 0u
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
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO 0u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SIO 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLEW_EXT 0u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLEW_WIDTH 0u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_AUTOLVL 0u
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
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLEW_WIDTH 3u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_AUTOLVL 1u
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
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLEW_WIDTH 3u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_AUTOLVL 1u
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
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLEW_EXT 0u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLEW_WIDTH 0u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_AUTOLVL 0u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO4 1u
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
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLEW_EXT 0u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLEW_WIDTH 0u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_AUTOLVL 0u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO4 1u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO5 1u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO6 1u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO7 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SIO 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLEW_WIDTH 3u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_AUTOLVL 1u
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
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLEW_WIDTH 3u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_AUTOLVL 1u
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
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLEW_WIDTH 3u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO1 1u
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
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SIO 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLEW_WIDTH 3u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_AUTOLVL 1u
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
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_GPIO 0u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SIO 0u
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLEW_EXT 0u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLEW_WIDTH 0u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_AUTOLVL 0u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO1 1u
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
/* Indicates port supports drive select trims */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DS_CTRL 0u
/* Indicates port supports slew extension bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLEW_EXT 1u
/* Indicates port supports drive select extension bits */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DRIVE_EXT 0u
/* Indicates slew bit width */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLEW_WIDTH 3u
/* Indicates drive sel bit width */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_DRIVE_WIDTH 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO1 1u
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
/* Level Detector present */
#define IOSS_GPIO_LVL_DET_PRESENT       0u
/* Number of AMUX splitter cells */
#define IOSS_HSIOM_AMUX_SPLIT_NR        3u
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
/* Indicates the presence of alternate JTAG interface */
#define IOSS_HSIOM_ALTJTAG_PRESENT      0u
/* Mask of SMARTIO instances presence */
#define IOSS_SMARTIO_SMARTIO_MASK       0u
/* Base address for USBHSDEV SLOW SLAV access */
#define MXS40USBHSDEV_CHIP_TOP_USBHSDEV_ADDR 0x30000000u
/* Mask for USBHSDEV SLOW SLAV access */
#define MXS40USBHSDEV_CHIP_TOP_USBHSDEV_MASK 0xFF000000u
/* Number of endpoints in Ingress path of EPM (16=Max) */
#define MXS40USBHSDEV_USBHSDEV_IGRS_NUM_EP 16u
/* Number of endpoints in Egress path of EPM (16=Max) */
#define MXS40USBHSDEV_USBHSDEV_EGRS_NUM_EP 16u
/* Allows direct map of EPM SRAMs on MMIO (0=None, 1=Supported) */
#define MXS40USBHSDEV_USBHSDEV_MMIO_EPM_SUPPORT 1u
/* Instantiates PLL and dreive clk60 output */
#define MXS40USBHSDEV_USBHSPHY_PLL_EN   1u
/* Instantiates USB as as PHY when enabled. When not enabled, eUSB PHY will be
   instantiated. */
#define MXS40USBHSDEV_USBHSPHY_USB_EN   1u
/* Instantiates VREFGEN module */
#define MXS40USBHSDEV_USBHSPHY_VREFGEN_EN 1u
/* Instantiates IREFGEN module */
#define MXS40USBHSDEV_USBHSPHY_IREFGEN_EN 1u
/* Instantiates 2p5 regulator module */
#define MXS40USBHSDEV_USBHSPHY_REG_2P5_EN 1u
/* Instantiates 1p1 regulator module */
#define MXS40USBHSDEV_USBHSPHY_REG_1P1_EN 1u
/* Instantiates SW_1P2 regulator module */
#define MXS40USBHSDEV_USBHSPHY_REG_SW_1P2_EN 0u
/* Number of PDM structures ({2, 4, 6, 8}]). */
#define PDM_NR                          2u
/* The number of protection contexts ([2, 16]). */
#define PERI_PC_NR                      8u
/* Master interface presence mask (4 bits) */
#define PERI_MS_PRESENT                 15u
/* Protection structures SRAM ECC present or not ('0': no, '1': yes) */
#define PERI_ECC_PRESENT                0u
/* Protection structures SRAM address ECC present or not ('0': no, '1': yes) */
#define PERI_ECC_ADDR_PRESENT           0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL3_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL4_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL6_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL8_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL9_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL10_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL12_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL3_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL3_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL4_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL5_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL6_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL8_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL10_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL4_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL8_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL12_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present (0:No, 1:Yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Number of programmable clocks (outputs) */
#define PERI_CLOCK_NR                   19u
/* Number of 8.0 dividers */
#define PERI_DIV_8_NR                   8u
/* Number of 16.0 dividers */
#define PERI_DIV_16_NR                  8u
/* Number of 16.5 (fractional) dividers */
#define PERI_DIV_16_5_NR                2u
/* Number of 24.5 (fractional) dividers */
#define PERI_DIV_24_5_NR                1u
/* Divider number width: max(1,roundup(log2(max(DIV_*_NR))) */
#define PERI_DIV_ADDR_WIDTH             3u
/* Timeout functionality present ('0': no, '1': yes) */
#define PERI_TIMEOUT_PRESENT            1u
/* Trigger module present (0=No, 1=Yes) */
#define PERI_TR                         1u
/* Number of trigger groups */
#define PERI_TR_GROUP_NR                13u
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
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR8_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR9_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR10_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR11_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR12_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR0_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR1_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR2_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR3_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR4_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Trigger 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR5_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define PERI_MASTER_WIDTH               8u
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
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB0_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB0_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB0_I2C_S_EC                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB0_SPI_M                      0u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB0_SPI_S                      0u
/* SPI support? (SPI_M | SPI_S) */
#define SCB0_SPI                        0u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB0_SPI_EC                     0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB0_SPI_S_EC                   0u
/* UART support? ('0': no, '1': yes) */
#define SCB0_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB0_SPI_UART                   0u
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
#define SCB0_SPI_S_EZ                   0u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB0_I2C_FAST_PLUS              1u
/* Number of used spi_select signals (max 4) */
#define SCB0_CHIP_TOP_SPI_SEL_NR        0u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB1_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB1_EC                         0u
/* I2C master support? ('0': no, '1': yes) */
#define SCB1_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB1_I2C_S                      1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB1_I2C                        1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB1_I2C_GLITCH                 1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB1_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB1_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB1_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB1_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB1_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB1_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB1_SPI_EC                     0u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB1_SPI_S_EC                   0u
/* UART support? ('0': no, '1': yes) */
#define SCB1_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB1_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB1_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB1_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB1_EZ                         0u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB1_EZ_CMD_RESP                0u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB1_I2C_S_EZ                   0u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB1_SPI_S_EZ                   0u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB1_I2C_FAST_PLUS              1u
/* Number of used spi_select signals (max 4) */
#define SCB1_CHIP_TOP_SPI_SEL_NR        1u
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
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB2_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB2_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB2_I2C_S_EC                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB2_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB2_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB2_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB2_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB2_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB2_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB2_SPI_UART                   0u
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
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB2_I2C_FAST_PLUS              1u
/* Number of used spi_select signals (max 4) */
#define SCB2_CHIP_TOP_SPI_SEL_NR        1u
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
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB3_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB3_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB3_I2C_S_EC                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB3_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB3_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB3_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB3_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB3_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB3_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB3_SPI_UART                   0u
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
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB3_I2C_FAST_PLUS              1u
/* Number of used spi_select signals (max 4) */
#define SCB3_CHIP_TOP_SPI_SEL_NR        1u
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
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB4_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB4_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB4_I2C_S_EC                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB4_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB4_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB4_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB4_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB4_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB4_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB4_SPI_UART                   0u
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
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB4_I2C_FAST_PLUS              1u
/* Number of used spi_select signals (max 4) */
#define SCB4_CHIP_TOP_SPI_SEL_NR        1u
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
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB5_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB5_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB5_I2C_S_EC                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB5_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB5_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB5_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB5_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB5_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB5_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB5_SPI_UART                   0u
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
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB5_I2C_FAST_PLUS              1u
/* Number of used spi_select signals (max 4) */
#define SCB5_CHIP_TOP_SPI_SEL_NR        1u
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
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB6_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB6_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB6_I2C_S_EC                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB6_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB6_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB6_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB6_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB6_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB6_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB6_SPI_UART                   0u
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
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB6_I2C_FAST_PLUS              1u
/* Number of used spi_select signals (max 4) */
#define SCB6_CHIP_TOP_SPI_SEL_NR        4u
/* SONOS Flash is used or not ('0': no, '1': yes) */
#define SFLASH_FLASHC_IS_SONOS          1u
/* CPUSS_WOUNDING_PRESENT or not ('0': no, '1': yes) */
#define SFLASH_CPUSS_WOUNDING_PRESENT   0u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]) */
#define SMIF_MASTER_WIDTH               8u
/* Base address of the SMIF XIP memory region. This address must be a multiple of
   the SMIF XIP memory capacity. This address must be a multiple of 64 KB. This
   address must be in the [0x0000:0000, 0x1fff:ffff] memory region. The XIP
   memory region should NOT overlap with other memory regions. */
#define SMIF_SMIF_XIP_ADDR              0x18000000u
/* Capacity of the SMIF XIP memory region. The more significant bits of this
   parameter must be '1' and the lesser significant bits of this paramter must
   be '0'. E.g., 0xfff0:0000 specifies a 1 MB memory region. Legal values are
   {0xffff:0000, 0xfffe:0000, 0xfffc:0000, 0xfff8:0000, 0xfff0:0000,
   0xffe0:0000, ..., 0xe000:0000}. */
#define SMIF_SMIF_XIP_MASK              0xFC000000u
/* Cryptography (AES) support ('0' = no support, '1' = support) */
#define SMIF_CRYPTO                     1u
/* Number of external devices supported ([1,4]) */
#define SMIF_DEVICE_NR                  4u
/* External device write support. This is a 4-bit field. Each external device has
   a dedicated bit. E.g., if bit 2 is '1', external device 2 has write support. */
#define SMIF_DEVICE_WR_EN               15u
/* Chip top connect all 8 data pins (0= connect 4 data pins, 1= connect 8 data
   pins) */
#define SMIF_CHIP_TOP_DATA8_PRESENT     1u
/* Number of used spi_select signals (max 4) */
#define SMIF_CHIP_TOP_SPI_SEL_NR        4u
/* Number of regulator modules instantiated within SRSS, start with estimate,
   update after CMR feedback */
#define SRSS_NUM_ACTREG_PWRMOD          4u
/* Number of shorting switches between vccd and vccact (target dynamic voltage
   drop < 10mV) */
#define SRSS_NUM_ACTIVE_SWITCH          6u
/* ULP linear regulator system is present */
#define SRSS_ULPLINREG_PRESENT          1u
/* HT linear regulator system is present */
#define SRSS_HTLINREG_PRESENT           0u
/* Low-current buck regulator present. Can be derived from S40S_SISOBUCKLC_PRESENT
   or SIMOBUCK_PRESENT. */
#define SRSS_BUCKCTL_PRESENT            0u
/* Low-current SISO buck core regulator is present. Only compatible with ULP
   linear regulator system (ULPLINREG_PRESENT==1). */
#define SRSS_S40S_SISOBUCKLC_PRESENT    0u
/* SIMO buck core regulator is present. Only compatible with ULP linear regulator
   system (ULPLINREG_PRESENT==1). */
#define SRSS_SIMOBUCK_PRESENT           0u
/* Precision ILO (PILO) is present */
#define SRSS_PILO_PRESENT               0u
/* External Crystal Oscillator is present (high frequency) */
#define SRSS_ECO_PRESENT                1u
/* System Buck-Boost is present */
#define SRSS_SYSBB_PRESENT              0u
/* Number of clock paths. Must be > 0 */
#define SRSS_NUM_CLKPATH                5u
/* Number of PLLs present. Must be <= NUM_CLKPATH */
#define SRSS_NUM_PLL                    2u
/* Number of HFCLK roots present. Must be > 0 */
#define SRSS_NUM_HFROOT                 6u
/* Number of PWR_HIB_DATA registers, should not be needed if BACKUP_PRESENT */
#define SRSS_NUM_HIBDATA                1u
/* Backup domain is present (includes RTC and WCO) */
#define SRSS_BACKUP_PRESENT             0u
/* Mask of HFCLK root clock supervisors (CSV). For each clock root i, bit[i] of
   mask indicates presence of a CSV. */
#define SRSS_MASK_HFCSV                 0u
/* Clock supervisor is present on WCO. Must be 0 if BACKUP_PRESENT==0. */
#define SRSS_WCOCSV_PRESENT             0u
/* Number of software watchdog timers. */
#define SRSS_NUM_MCWDT                  2u
/* Number of DSI inputs into clock muxes. This is used for logic optimization. */
#define SRSS_NUM_DSI                    0u
/* Alternate high-frequency clock is present. This is used for logic optimization. */
#define SRSS_ALTHF_PRESENT              1u
/* Alternate low-frequency clock is present. This is used for logic optimization. */
#define SRSS_ALTLF_PRESENT              0u
/* Use the hardened clkactfllmux block */
#define SRSS_USE_HARD_CLKACTFLLMUX      1u
/* Number of clock paths, including direct paths in hardened clkactfllmux block
   (Must be >= NUM_CLKPATH) */
#define SRSS_HARD_CLKPATH               6u
/* Number of clock paths with muxes in hardened clkactfllmux block (Must be >=
   NUM_PLL+1) */
#define SRSS_HARD_CLKPATHMUX            6u
/* Number of HFCLKS present in hardened clkactfllmux block (Must be >= NUM_HFROOT) */
#define SRSS_HARD_HFROOT                6u
/* ECO mux is present in hardened clkactfllmux block (Must be >= ECO_PRESENT) */
#define SRSS_HARD_ECOMUX_PRESENT        1u
/* ALTHF mux is present in hardened clkactfllmux block (Must be >= ALTHF_PRESENT) */
#define SRSS_HARD_ALTHFMUX_PRESENT      1u
/* SRSS version is at least SRSS_VER1P3. Set to 1 for new products. Set to 0 for
   PSoC6ABLE2, PSoC6A2M. */
#define SRSS_SRSS_VER1P3                1u
/* Backup memory is present (only used when BACKUP_PRESENT==1) */
#define SRSS_BACKUP_BMEM_PRESENT        0u
/* Number of Backup registers to include (each is 32b). Only used when
   BACKUP_PRESENT==1. */
#define SRSS_BACKUP_NUM_BREG            16u
/* Number of counters per IP (1..32) */
#define TCPWM_CNT_NR                    8u
/* Counter width (in number of bits) */
#define TCPWM_CNT_CNT_WIDTH             32u
/* Number of AHB-Lite "hmaster[]" bits ([4, 8]). */
#define TDM_MASTER_WIDTH                8u
/* Number of TDM structures ({1, 2, 3, 4}]). */
#define TDM_NR                          1u
/* Number of channels per TDM structure. */
#define TDM_NR_CH_NR                    2u
/* Number of channels per TDM structure. */
#define TDM_NR_TDM_RX_STRUCT_CH_NR      2u
/* Number of channels per TDM structure. */
#define TDM_NR_TDM_TX_STRUCT_CH_NR      2u
/* Spare Enable 0=no spare, 1=max, 2=min */
#define TDM_SPARE_EN                    1u
/* 0=ULL65, 1=MXS40-ULP, 2=MXS40E, 3=M0S8, 4=MXS40-HD, 5=F45, 6=MXS40v2, 7=T28HPM,
   8=T28HPL, 9=T28HPC */
#define TDM_PLATFORM_VARIANT            1u
/* SRAM vendor ({0=Cypress, 1=Synopsys, 2=ARM, 3=BRCM}) */
#define TDM_RAM_VEND                    1u
/* Use mxsramwrap IP */
#define TDM_MXSRAMWRAP_EN               1u
/* Number of connected clocks at the IP's top level ([1, 4]). */
#define TDM_CHIP_TOP_CLK_NR             1u
/* Replay functionality for transmitter. This functionality adds significant
   silicon area. */
#define TDM_TDM_TX_STRUCT_REPLAY_PRESENT 0u

/* MMIO Targets Defines */
/* MMIO1.CRYPTO */
#define CY_MMIO_CRYPTO_GROUP_NR         1u
#define CY_MMIO_CRYPTO_SLAVE_NR         0u
/* MMIO2.CPUSS */
#define CY_MMIO_CPUSS_GROUP_NR          2u
#define CY_MMIO_CPUSS_SLAVE_NR          0u
/* MMIO2.FAULT */
#define CY_MMIO_FAULT_GROUP_NR          2u
#define CY_MMIO_FAULT_SLAVE_NR          1u
/* MMIO2.IPC */
#define CY_MMIO_IPC_GROUP_NR            2u
#define CY_MMIO_IPC_SLAVE_NR            2u
/* MMIO2.PROT */
#define CY_MMIO_PROT_GROUP_NR           2u
#define CY_MMIO_PROT_SLAVE_NR           3u
/* MMIO2.FLASHC */
#define CY_MMIO_FLASHC_GROUP_NR         2u
#define CY_MMIO_FLASHC_SLAVE_NR         4u
/* MMIO2.SRSS */
#define CY_MMIO_SRSS_GROUP_NR           2u
#define CY_MMIO_SRSS_SLAVE_NR           6u
/* MMIO2.DW */
#define CY_MMIO_DW_GROUP_NR             2u
#define CY_MMIO_DW_SLAVE_NR             8u
/* MMIO2.DMAC */
#define CY_MMIO_DMAC_GROUP_NR           2u
#define CY_MMIO_DMAC_SLAVE_NR           10u
/* MMIO2.EFUSE */
#define CY_MMIO_EFUSE_GROUP_NR          2u
#define CY_MMIO_EFUSE_SLAVE_NR          12u
/* MMIO3.HSIOM */
#define CY_MMIO_HSIOM_GROUP_NR          3u
#define CY_MMIO_HSIOM_SLAVE_NR          0u
/* MMIO3.GPIO */
#define CY_MMIO_GPIO_GROUP_NR           3u
#define CY_MMIO_GPIO_SLAVE_NR           1u
/* MMIO3.PDM0 */
#define CY_MMIO_PDM0_GROUP_NR           3u
#define CY_MMIO_PDM0_SLAVE_NR           2u
/* MMIO4.TCPWM0 */
#define CY_MMIO_TCPWM0_GROUP_NR         4u
#define CY_MMIO_TCPWM0_SLAVE_NR         0u
/* MMIO4.SMIF0 */
#define CY_MMIO_SMIF0_GROUP_NR          4u
#define CY_MMIO_SMIF0_SLAVE_NR          1u
/* MMIO4.USBFS0 */
#define CY_MMIO_USBFS0_GROUP_NR         4u
#define CY_MMIO_USBFS0_SLAVE_NR         2u
/* MMIO4.USBHSDEV */
#define CY_MMIO_USBHSDEV_GROUP_NR       4u
#define CY_MMIO_USBHSDEV_SLAVE_NR       3u
/* MMIO5.SCB0 */
#define CY_MMIO_SCB0_GROUP_NR           5u
#define CY_MMIO_SCB0_SLAVE_NR           0u
/* MMIO5.SCB1 */
#define CY_MMIO_SCB1_GROUP_NR           5u
#define CY_MMIO_SCB1_SLAVE_NR           1u
/* MMIO5.SCB2 */
#define CY_MMIO_SCB2_GROUP_NR           5u
#define CY_MMIO_SCB2_SLAVE_NR           2u
/* MMIO5.SCB3 */
#define CY_MMIO_SCB3_GROUP_NR           5u
#define CY_MMIO_SCB3_SLAVE_NR           3u
/* MMIO5.SCB4 */
#define CY_MMIO_SCB4_GROUP_NR           5u
#define CY_MMIO_SCB4_SLAVE_NR           4u
/* MMIO5.SCB5 */
#define CY_MMIO_SCB5_GROUP_NR           5u
#define CY_MMIO_SCB5_SLAVE_NR           5u
/* MMIO5.SCB6 */
#define CY_MMIO_SCB6_GROUP_NR           5u
#define CY_MMIO_SCB6_SLAVE_NR           6u
/* MMIO5.CANFD0 */
#define CY_MMIO_CANFD0_GROUP_NR         5u
#define CY_MMIO_CANFD0_SLAVE_NR         8u
/* MMIO5.TDM0 */
#define CY_MMIO_TDM0_GROUP_NR           5u
#define CY_MMIO_TDM0_SLAVE_NR           10u
/* MMIO6.MAIN_REG */
#define CY_MMIO_MAIN_REG_GROUP_NR       6u
#define CY_MMIO_MAIN_REG_SLAVE_NR       4u
/* MMIO6.USB32DEV */
#define CY_MMIO_USB32DEV_GROUP_NR       6u
#define CY_MMIO_USB32DEV_SLAVE_NR       8u
/* MMIO6.LVDSSS */
#define CY_MMIO_LVDSSS_GROUP_NR         6u
#define CY_MMIO_LVDSSS_SLAVE_NR         12u

/* Backward compatibility definitions */
#define CPUSS_IRQ_NR                    CPUSS_SYSTEM_INT_NR
#define CPUSS_DPSLP_IRQ_NR              CPUSS_SYSTEM_DPSLP_INT_NR

/*******************************************************************************
*                                    BACKUP
*******************************************************************************/
#define BACKUP_BASE                     0x40270000UL
#define BACKUP                          ((BACKUP_Type*) BACKUP_BASE)                            /* 0x40270000 */

/* Protection regions */
typedef enum
{
    PROT_PERI_MAIN                  =   0,      /* Address 0x40000000, size 0x00002000 */
    PROT_PERI_GR0_GROUP             =   1,      /* Address 0x40004010, size 0x00000004 */
    PROT_PERI_GR1_GROUP             =   2,      /* Address 0x40004030, size 0x00000004 */
    PROT_PERI_GR2_GROUP             =   3,      /* Address 0x40004050, size 0x00000004 */
    PROT_PERI_GR3_GROUP             =   4,      /* Address 0x40004060, size 0x00000020 */
    PROT_PERI_GR4_GROUP             =   5,      /* Address 0x40004080, size 0x00000020 */
    PROT_PERI_GR5_GROUP             =   6,      /* Address 0x400040a0, size 0x00000020 */
    PROT_PERI_GR6_GROUP             =   7,      /* Address 0x400040c0, size 0x00000020 */
    PROT_PERI_TR                    =   8,      /* Address 0x40008000, size 0x00008000 */
    PROT_CRYPTO_MAIN                =   9,      /* Address 0x40100000, size 0x00000400 */
    PROT_CRYPTO_CRYPTO              =  10,      /* Address 0x40101000, size 0x00000800 */
    PROT_CRYPTO_BOOT                =  11,      /* Address 0x40102000, size 0x00000100 */
    PROT_CRYPTO_KEY0                =  12,      /* Address 0x40102100, size 0x00000004 */
    PROT_CRYPTO_KEY1                =  13,      /* Address 0x40102120, size 0x00000004 */
    PROT_CRYPTO_BUF                 =  14,      /* Address 0x40108000, size 0x00002000 */
    PROT_CPUSS_CM4                  =  15,      /* Address 0x40200000, size 0x00000400 */
    PROT_CPUSS_CM0                  =  16,      /* Address 0x40201000, size 0x00001000 */
    PROT_CPUSS_BOOT                 =  17,      /* Address 0x40202000, size 0x00000200 */
    PROT_CPUSS_CM0_INT              =  18,      /* Address 0x40208000, size 0x00000400 */
    PROT_CPUSS_CM4_INT              =  19,      /* Address 0x4020a000, size 0x00000400 */
    PROT_IPC_STRUCT0_IPC            =  20,      /* Address 0x40220000, size 0x00000020 */
    PROT_IPC_STRUCT1_IPC            =  21,      /* Address 0x40220020, size 0x00000020 */
    PROT_IPC_STRUCT2_IPC            =  22,      /* Address 0x40220040, size 0x00000020 */
    PROT_IPC_STRUCT3_IPC            =  23,      /* Address 0x40220060, size 0x00000020 */
    PROT_IPC_STRUCT4_IPC            =  24,      /* Address 0x40220080, size 0x00000020 */
    PROT_IPC_STRUCT5_IPC            =  25,      /* Address 0x402200a0, size 0x00000020 */
    PROT_IPC_STRUCT6_IPC            =  26,      /* Address 0x402200c0, size 0x00000020 */
    PROT_IPC_STRUCT7_IPC            =  27,      /* Address 0x402200e0, size 0x00000020 */
    PROT_IPC_STRUCT8_IPC            =  28,      /* Address 0x40220100, size 0x00000020 */
    PROT_IPC_STRUCT9_IPC            =  29,      /* Address 0x40220120, size 0x00000020 */
    PROT_IPC_STRUCT10_IPC           =  30,      /* Address 0x40220140, size 0x00000020 */
    PROT_IPC_STRUCT11_IPC           =  31,      /* Address 0x40220160, size 0x00000020 */
    PROT_IPC_STRUCT12_IPC           =  32,      /* Address 0x40220180, size 0x00000020 */
    PROT_IPC_STRUCT13_IPC           =  33,      /* Address 0x402201a0, size 0x00000020 */
    PROT_IPC_STRUCT14_IPC           =  34,      /* Address 0x402201c0, size 0x00000020 */
    PROT_IPC_STRUCT15_IPC           =  35,      /* Address 0x402201e0, size 0x00000020 */
    PROT_IPC_INTR_STRUCT0_INTR      =  36,      /* Address 0x40221000, size 0x00000010 */
    PROT_IPC_INTR_STRUCT1_INTR      =  37,      /* Address 0x40221020, size 0x00000010 */
    PROT_IPC_INTR_STRUCT2_INTR      =  38,      /* Address 0x40221040, size 0x00000010 */
    PROT_IPC_INTR_STRUCT3_INTR      =  39,      /* Address 0x40221060, size 0x00000010 */
    PROT_IPC_INTR_STRUCT4_INTR      =  40,      /* Address 0x40221080, size 0x00000010 */
    PROT_IPC_INTR_STRUCT5_INTR      =  41,      /* Address 0x402210a0, size 0x00000010 */
    PROT_IPC_INTR_STRUCT6_INTR      =  42,      /* Address 0x402210c0, size 0x00000010 */
    PROT_IPC_INTR_STRUCT7_INTR      =  43,      /* Address 0x402210e0, size 0x00000010 */
    PROT_IPC_INTR_STRUCT8_INTR      =  44,      /* Address 0x40221100, size 0x00000010 */
    PROT_IPC_INTR_STRUCT9_INTR      =  45,      /* Address 0x40221120, size 0x00000010 */
    PROT_IPC_INTR_STRUCT10_INTR     =  46,      /* Address 0x40221140, size 0x00000010 */
    PROT_IPC_INTR_STRUCT11_INTR     =  47,      /* Address 0x40221160, size 0x00000010 */
    PROT_IPC_INTR_STRUCT12_INTR     =  48,      /* Address 0x40221180, size 0x00000010 */
    PROT_IPC_INTR_STRUCT13_INTR     =  49,      /* Address 0x402211a0, size 0x00000010 */
    PROT_IPC_INTR_STRUCT14_INTR     =  50,      /* Address 0x402211c0, size 0x00000010 */
    PROT_IPC_INTR_STRUCT15_INTR     =  51,      /* Address 0x402211e0, size 0x00000010 */
    PROT_PROT_SMPU_MAIN             =  52,      /* Address 0x40230000, size 0x00000040 */
    PROT_PROT_MPU0_MAIN             =  53,      /* Address 0x40234000, size 0x00000004 */
    PROT_PROT_MPU14_MAIN            =  54,      /* Address 0x40237800, size 0x00000004 */
    PROT_PROT_MPU15_MAIN            =  55,      /* Address 0x40237c00, size 0x00000400 */
    PROT_FLASHC_MAIN                =  56,      /* Address 0x40240000, size 0x00000008 */
    PROT_FLASHC_CMD                 =  57,      /* Address 0x40240008, size 0x00000004 */
    PROT_FLASHC_DFT                 =  58,      /* Address 0x40240200, size 0x00000100 */
    PROT_FLASHC_CM0                 =  59,      /* Address 0x40240400, size 0x00000080 */
    PROT_FLASHC_CM4                 =  60,      /* Address 0x40240480, size 0x00000080 */
    PROT_FLASHC_CRYPTO              =  61,      /* Address 0x40240500, size 0x00000004 */
    PROT_FLASHC_DW0                 =  62,      /* Address 0x40240580, size 0x00000004 */
    PROT_FLASHC_DW1                 =  63,      /* Address 0x40240600, size 0x00000004 */
    PROT_FLASHC_DMAC                =  64,      /* Address 0x40240680, size 0x00000004 */
    PROT_FLASHC_FM                  =  65,      /* Address 0x4024f000, size 0x00001000 */
    PROT_SRSS_MAIN1                 =  66,      /* Address 0x40260000, size 0x00000100 */
    PROT_SRSS_MAIN2                 =  67,      /* Address 0x40260100, size 0x00000010 */
    PROT_WDT                        =  68,      /* Address 0x40260180, size 0x00000010 */
    PROT_MAIN                       =  69,      /* Address 0x40260200, size 0x00000080 */
    PROT_SRSS_MAIN3                 =  70,      /* Address 0x40260300, size 0x00000100 */
    PROT_SRSS_MAIN4                 =  71,      /* Address 0x40260400, size 0x00000400 */
    PROT_SRSS_MAIN5                 =  72,      /* Address 0x40260800, size 0x00000008 */
    PROT_SRSS_MAIN6                 =  73,      /* Address 0x40267000, size 0x00001000 */
    PROT_SRSS_MAIN7                 =  74,      /* Address 0x4026ff00, size 0x00000080 */
    PROT_DW0_DW                     =  75,      /* Address 0x40280000, size 0x00000080 */
    PROT_DW1_DW                     =  76,      /* Address 0x40290000, size 0x00000080 */
    PROT_DW0_DW_CRC                 =  77,      /* Address 0x40280100, size 0x00000080 */
    PROT_DW1_DW_CRC                 =  78,      /* Address 0x40290100, size 0x00000080 */
    PROT_DW0_CH_STRUCT0_CH          =  79,      /* Address 0x40288000, size 0x00000040 */
    PROT_DW0_CH_STRUCT1_CH          =  80,      /* Address 0x40288040, size 0x00000040 */
    PROT_DW0_CH_STRUCT2_CH          =  81,      /* Address 0x40288080, size 0x00000040 */
    PROT_DW0_CH_STRUCT3_CH          =  82,      /* Address 0x402880c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT4_CH          =  83,      /* Address 0x40288100, size 0x00000040 */
    PROT_DW0_CH_STRUCT5_CH          =  84,      /* Address 0x40288140, size 0x00000040 */
    PROT_DW0_CH_STRUCT6_CH          =  85,      /* Address 0x40288180, size 0x00000040 */
    PROT_DW0_CH_STRUCT7_CH          =  86,      /* Address 0x402881c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT8_CH          =  87,      /* Address 0x40288200, size 0x00000040 */
    PROT_DW0_CH_STRUCT9_CH          =  88,      /* Address 0x40288240, size 0x00000040 */
    PROT_DW0_CH_STRUCT10_CH         =  89,      /* Address 0x40288280, size 0x00000040 */
    PROT_DW0_CH_STRUCT11_CH         =  90,      /* Address 0x402882c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT12_CH         =  91,      /* Address 0x40288300, size 0x00000040 */
    PROT_DW0_CH_STRUCT13_CH         =  92,      /* Address 0x40288340, size 0x00000040 */
    PROT_DW0_CH_STRUCT14_CH         =  93,      /* Address 0x40288380, size 0x00000040 */
    PROT_DW0_CH_STRUCT15_CH         =  94,      /* Address 0x402883c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT16_CH         =  95,      /* Address 0x40288400, size 0x00000040 */
    PROT_DW0_CH_STRUCT17_CH         =  96,      /* Address 0x40288440, size 0x00000040 */
    PROT_DW0_CH_STRUCT18_CH         =  97,      /* Address 0x40288480, size 0x00000040 */
    PROT_DW0_CH_STRUCT19_CH         =  98,      /* Address 0x402884c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT20_CH         =  99,      /* Address 0x40288500, size 0x00000040 */
    PROT_DW0_CH_STRUCT21_CH         = 100,      /* Address 0x40288540, size 0x00000040 */
    PROT_DW0_CH_STRUCT22_CH         = 101,      /* Address 0x40288580, size 0x00000040 */
    PROT_DW0_CH_STRUCT23_CH         = 102,      /* Address 0x402885c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT24_CH         = 103,      /* Address 0x40288600, size 0x00000040 */
    PROT_DW0_CH_STRUCT25_CH         = 104,      /* Address 0x40288640, size 0x00000040 */
    PROT_DW0_CH_STRUCT26_CH         = 105,      /* Address 0x40288680, size 0x00000040 */
    PROT_DW0_CH_STRUCT27_CH         = 106,      /* Address 0x402886c0, size 0x00000040 */
    PROT_DW0_CH_STRUCT28_CH         = 107,      /* Address 0x40288700, size 0x00000040 */
    PROT_DW0_CH_STRUCT29_CH         = 108,      /* Address 0x40288740, size 0x00000040 */
    PROT_DW0_CH_STRUCT30_CH         = 109,      /* Address 0x40288780, size 0x00000040 */
    PROT_DW0_CH_STRUCT31_CH         = 110,      /* Address 0x402887c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT0_CH          = 111,      /* Address 0x40298000, size 0x00000040 */
    PROT_DW1_CH_STRUCT1_CH          = 112,      /* Address 0x40298040, size 0x00000040 */
    PROT_DW1_CH_STRUCT2_CH          = 113,      /* Address 0x40298080, size 0x00000040 */
    PROT_DW1_CH_STRUCT3_CH          = 114,      /* Address 0x402980c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT4_CH          = 115,      /* Address 0x40298100, size 0x00000040 */
    PROT_DW1_CH_STRUCT5_CH          = 116,      /* Address 0x40298140, size 0x00000040 */
    PROT_DW1_CH_STRUCT6_CH          = 117,      /* Address 0x40298180, size 0x00000040 */
    PROT_DW1_CH_STRUCT7_CH          = 118,      /* Address 0x402981c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT8_CH          = 119,      /* Address 0x40298200, size 0x00000040 */
    PROT_DW1_CH_STRUCT9_CH          = 120,      /* Address 0x40298240, size 0x00000040 */
    PROT_DW1_CH_STRUCT10_CH         = 121,      /* Address 0x40298280, size 0x00000040 */
    PROT_DW1_CH_STRUCT11_CH         = 122,      /* Address 0x402982c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT12_CH         = 123,      /* Address 0x40298300, size 0x00000040 */
    PROT_DW1_CH_STRUCT13_CH         = 124,      /* Address 0x40298340, size 0x00000040 */
    PROT_DW1_CH_STRUCT14_CH         = 125,      /* Address 0x40298380, size 0x00000040 */
    PROT_DW1_CH_STRUCT15_CH         = 126,      /* Address 0x402983c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT16_CH         = 127,      /* Address 0x40298400, size 0x00000040 */
    PROT_DW1_CH_STRUCT17_CH         = 128,      /* Address 0x40298440, size 0x00000040 */
    PROT_DW1_CH_STRUCT18_CH         = 129,      /* Address 0x40298480, size 0x00000040 */
    PROT_DW1_CH_STRUCT19_CH         = 130,      /* Address 0x402984c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT20_CH         = 131,      /* Address 0x40298500, size 0x00000040 */
    PROT_DW1_CH_STRUCT21_CH         = 132,      /* Address 0x40298540, size 0x00000040 */
    PROT_DW1_CH_STRUCT22_CH         = 133,      /* Address 0x40298580, size 0x00000040 */
    PROT_DW1_CH_STRUCT23_CH         = 134,      /* Address 0x402985c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT24_CH         = 135,      /* Address 0x40298600, size 0x00000040 */
    PROT_DW1_CH_STRUCT25_CH         = 136,      /* Address 0x40298640, size 0x00000040 */
    PROT_DW1_CH_STRUCT26_CH         = 137,      /* Address 0x40298680, size 0x00000040 */
    PROT_DW1_CH_STRUCT27_CH         = 138,      /* Address 0x402986c0, size 0x00000040 */
    PROT_DW1_CH_STRUCT28_CH         = 139,      /* Address 0x40298700, size 0x00000040 */
    PROT_DW1_CH_STRUCT29_CH         = 140,      /* Address 0x40298740, size 0x00000040 */
    PROT_DW1_CH_STRUCT30_CH         = 141,      /* Address 0x40298780, size 0x00000040 */
    PROT_DW1_CH_STRUCT31_CH         = 142,      /* Address 0x402987c0, size 0x00000040 */
    PROT_DMAC_TOP                   = 143,      /* Address 0x402a0000, size 0x00000010 */
    PROT_DMAC_CH0_CH                = 144,      /* Address 0x402a1000, size 0x00000100 */
    PROT_DMAC_CH1_CH                = 145,      /* Address 0x402a1100, size 0x00000100 */
    PROT_DMAC_CH2_CH                = 146,      /* Address 0x402a1200, size 0x00000100 */
    PROT_DMAC_CH3_CH                = 147,      /* Address 0x402a1300, size 0x00000100 */
    PROT_DMAC_CH4_CH                = 148,      /* Address 0x402a1400, size 0x00000100 */
    PROT_DMAC_CH5_CH                = 149,      /* Address 0x402a1500, size 0x00000100 */
    PROT_EFUSE_CTL                  = 150,      /* Address 0x402c0000, size 0x00000080 */
    PROT_EFUSE_DATA                 = 151,      /* Address 0x402c0800, size 0x00000200 */
    PROT_HSIOM_PRT0_PRT             = 152,      /* Address 0x40300000, size 0x00000008 */
    PROT_HSIOM_PRT1_PRT             = 153,      /* Address 0x40300010, size 0x00000008 */
    PROT_HSIOM_PRT2_PRT             = 154,      /* Address 0x40300020, size 0x00000008 */
    PROT_HSIOM_PRT3_PRT             = 155,      /* Address 0x40300030, size 0x00000008 */
    PROT_HSIOM_PRT4_PRT             = 156,      /* Address 0x40300040, size 0x00000008 */
    PROT_HSIOM_PRT5_PRT             = 157,      /* Address 0x40300050, size 0x00000008 */
    PROT_HSIOM_PRT6_PRT             = 158,      /* Address 0x40300060, size 0x00000008 */
    PROT_HSIOM_PRT7_PRT             = 159,      /* Address 0x40300070, size 0x00000008 */
    PROT_HSIOM_PRT8_PRT             = 160,      /* Address 0x40300080, size 0x00000008 */
    PROT_HSIOM_PRT9_PRT             = 161,      /* Address 0x40300090, size 0x00000008 */
    PROT_HSIOM_PRT10_PRT            = 162,      /* Address 0x403000a0, size 0x00000008 */
    PROT_HSIOM_PRT11_PRT            = 163,      /* Address 0x403000b0, size 0x00000008 */
    PROT_HSIOM_PRT12_PRT            = 164,      /* Address 0x403000c0, size 0x00000008 */
    PROT_HSIOM_PRT13_PRT            = 165,      /* Address 0x403000d0, size 0x00000008 */
    PROT_HSIOM_AMUX                 = 166,      /* Address 0x40302000, size 0x00000010 */
    PROT_HSIOM_MON                  = 167,      /* Address 0x40302200, size 0x00000010 */
    PROT_GPIO_PRT0_PRT              = 168,      /* Address 0x40310000, size 0x00000040 */
    PROT_GPIO_PRT1_PRT              = 169,      /* Address 0x40310080, size 0x00000040 */
    PROT_GPIO_PRT2_PRT              = 170,      /* Address 0x40310100, size 0x00000040 */
    PROT_GPIO_PRT3_PRT              = 171,      /* Address 0x40310180, size 0x00000040 */
    PROT_GPIO_PRT4_PRT              = 172,      /* Address 0x40310200, size 0x00000040 */
    PROT_GPIO_PRT5_PRT              = 173,      /* Address 0x40310280, size 0x00000040 */
    PROT_GPIO_PRT6_PRT              = 174,      /* Address 0x40310300, size 0x00000040 */
    PROT_GPIO_PRT7_PRT              = 175,      /* Address 0x40310380, size 0x00000040 */
    PROT_GPIO_PRT8_PRT              = 176,      /* Address 0x40310400, size 0x00000040 */
    PROT_GPIO_PRT9_PRT              = 177,      /* Address 0x40310480, size 0x00000040 */
    PROT_GPIO_PRT10_PRT             = 178,      /* Address 0x40310500, size 0x00000040 */
    PROT_GPIO_PRT11_PRT             = 179,      /* Address 0x40310580, size 0x00000040 */
    PROT_GPIO_PRT12_PRT             = 180,      /* Address 0x40310600, size 0x00000040 */
    PROT_GPIO_PRT13_PRT             = 181,      /* Address 0x40310680, size 0x00000040 */
    PROT_GPIO_PRT0_CFG              = 182,      /* Address 0x40310040, size 0x00000040 */
    PROT_GPIO_PRT1_CFG              = 183,      /* Address 0x403100c0, size 0x00000040 */
    PROT_GPIO_PRT2_CFG              = 184,      /* Address 0x40310140, size 0x00000008 */
    PROT_GPIO_PRT3_CFG              = 185,      /* Address 0x403101c0, size 0x00000008 */
    PROT_GPIO_PRT4_CFG              = 186,      /* Address 0x40310240, size 0x00000040 */
    PROT_GPIO_PRT5_CFG              = 187,      /* Address 0x403102c0, size 0x00000040 */
    PROT_GPIO_PRT6_CFG              = 188,      /* Address 0x40310340, size 0x00000010 */
    PROT_GPIO_PRT7_CFG              = 189,      /* Address 0x403103c0, size 0x00000010 */
    PROT_GPIO_PRT8_CFG              = 190,      /* Address 0x40310440, size 0x00000040 */
    PROT_GPIO_PRT9_CFG              = 191,      /* Address 0x403104c0, size 0x00000040 */
    PROT_GPIO_PRT10_CFG             = 192,      /* Address 0x40310540, size 0x00000040 */
    PROT_GPIO_PRT11_CFG             = 193,      /* Address 0x403105c0, size 0x00000040 */
    PROT_GPIO_PRT12_CFG             = 194,      /* Address 0x40310640, size 0x00000008 */
    PROT_GPIO_PRT13_CFG             = 195,      /* Address 0x403106c0, size 0x00000040 */
    PROT_GPIO_GPIO                  = 196,      /* Address 0x40314000, size 0x00000040 */
    PROT_GPIO_TEST                  = 197,      /* Address 0x40315000, size 0x00000008 */
    PROT_PDM0_MAIN                  = 198,      /* Address 0x40320000, size 0x00000200 */
    PROT_PDM0_CH0_RX                = 199,      /* Address 0x40328000, size 0x00000100 */
    PROT_PDM0_CH1_RX                = 200,      /* Address 0x40328100, size 0x00000100 */
    PROT_TCPWM0                     = 201,      /* Address 0x40400000, size 0x00010000 */
    PROT_SMIF0                      = 202,      /* Address 0x40410000, size 0x00010000 */
    PROT_USBFS0                     = 203,      /* Address 0x40420000, size 0x00010000 */
    PROT_MXS40USBHSDEV              = 204,      /* Address 0x40430000, size 0x00010000 */
    PROT_SCB0                       = 205,      /* Address 0x40500000, size 0x00010000 */
    PROT_SCB1                       = 206,      /* Address 0x40510000, size 0x00010000 */
    PROT_SCB2                       = 207,      /* Address 0x40520000, size 0x00010000 */
    PROT_SCB3                       = 208,      /* Address 0x40530000, size 0x00010000 */
    PROT_SCB4                       = 209,      /* Address 0x40540000, size 0x00010000 */
    PROT_SCB5                       = 210,      /* Address 0x40550000, size 0x00010000 */
    PROT_SCB6                       = 211,      /* Address 0x40560000, size 0x00010000 */
    PROT_CANFD0_CH0_CH              = 212,      /* Address 0x40580000, size 0x00000200 */
    PROT_CANFD0_MAIN                = 213,      /* Address 0x40581000, size 0x00000040 */
    PROT_CANFD0_BUF                 = 214,      /* Address 0x40590000, size 0x00010000 */
    PROT_TDM0_TDM_STRUCT0_TDM_TX_STRUCT_TX = 215, /* Address 0x405a8000, size 0x00000100 */
    PROT_TDM0_TDM_STRUCT0_TDM_RX_STRUCT_RX = 216, /* Address 0x405a8100, size 0x00000100 */
    PROT_MAIN_REG                   = 217,      /* Address 0x40640000, size 0x00001000 */
    PROT_USB32DEV                   = 218,      /* Address 0x40680000, size 0x00040000 */
    PROT_LVDSSS                     = 219       /* Address 0x406c0000, size 0x00040000 */
} cy_en_prot_region_t;

#endif /* _FX3G2_CONFIG_H_ */


/* [] END OF FILE */
