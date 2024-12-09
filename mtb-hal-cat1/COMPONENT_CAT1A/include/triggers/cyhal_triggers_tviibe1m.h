/***************************************************************************//**
* \file cyhal_triggers_tviibe1m.h
*
* \brief
* TVIIBE1M family HAL triggers header
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

#ifndef _CYHAL_TRIGGERS_TVIIBE1M_H_
#define _CYHAL_TRIGGERS_TVIIBE1M_H_

/**
 * \addtogroup group_hal_impl_triggers_tviibe1m TVIIBE1M
 * \ingroup group_hal_impl_triggers
 * \{
 * Trigger connections for tviibe1m
 */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/** \cond INTERNAL */
/** @brief Name of each input trigger. */
typedef enum
{
    _CYHAL_TRIGGER_CPUSS_ZERO = 0, //!< cpuss.zero
    _CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ0 = 1, //!< canfd[0].tr_dbg_dma_req[0]
    _CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ1 = 2, //!< canfd[0].tr_dbg_dma_req[1]
    _CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ2 = 3, //!< canfd[0].tr_dbg_dma_req[2]
    _CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ0 = 4, //!< canfd[1].tr_dbg_dma_req[0]
    _CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ1 = 5, //!< canfd[1].tr_dbg_dma_req[1]
    _CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ2 = 6, //!< canfd[1].tr_dbg_dma_req[2]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO00 = 7, //!< canfd[0].tr_fifo0[0]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO01 = 8, //!< canfd[0].tr_fifo0[1]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO02 = 9, //!< canfd[0].tr_fifo0[2]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO00 = 10, //!< canfd[1].tr_fifo0[0]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO01 = 11, //!< canfd[1].tr_fifo0[1]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO02 = 12, //!< canfd[1].tr_fifo0[2]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO10 = 13, //!< canfd[0].tr_fifo1[0]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO11 = 14, //!< canfd[0].tr_fifo1[1]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO12 = 15, //!< canfd[0].tr_fifo1[2]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO10 = 16, //!< canfd[1].tr_fifo1[0]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO11 = 17, //!< canfd[1].tr_fifo1[1]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO12 = 18, //!< canfd[1].tr_fifo1[2]
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT0 = 19, //!< canfd[0].tr_tmp_rtp_out[0]
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT1 = 20, //!< canfd[0].tr_tmp_rtp_out[1]
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT2 = 21, //!< canfd[0].tr_tmp_rtp_out[2]
    _CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT0 = 22, //!< canfd[1].tr_tmp_rtp_out[0]
    _CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT1 = 23, //!< canfd[1].tr_tmp_rtp_out[1]
    _CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT2 = 24, //!< canfd[1].tr_tmp_rtp_out[2]
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT0 = 25, //!< cpuss.cti_tr_out[0]
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT1 = 26, //!< cpuss.cti_tr_out[1]
    _CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT0 = 27, //!< cpuss.dmac_tr_out[0]
    _CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT1 = 28, //!< cpuss.dmac_tr_out[1]
    _CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT2 = 29, //!< cpuss.dmac_tr_out[2]
    _CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT3 = 30, //!< cpuss.dmac_tr_out[3]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT0 = 31, //!< cpuss.dw0_tr_out[0]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT1 = 32, //!< cpuss.dw0_tr_out[1]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT2 = 33, //!< cpuss.dw0_tr_out[2]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT3 = 34, //!< cpuss.dw0_tr_out[3]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT4 = 35, //!< cpuss.dw0_tr_out[4]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT5 = 36, //!< cpuss.dw0_tr_out[5]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT6 = 37, //!< cpuss.dw0_tr_out[6]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT7 = 38, //!< cpuss.dw0_tr_out[7]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT8 = 39, //!< cpuss.dw0_tr_out[8]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT9 = 40, //!< cpuss.dw0_tr_out[9]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT10 = 41, //!< cpuss.dw0_tr_out[10]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT11 = 42, //!< cpuss.dw0_tr_out[11]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT12 = 43, //!< cpuss.dw0_tr_out[12]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT13 = 44, //!< cpuss.dw0_tr_out[13]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT14 = 45, //!< cpuss.dw0_tr_out[14]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT15 = 46, //!< cpuss.dw0_tr_out[15]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT16 = 47, //!< cpuss.dw0_tr_out[16]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT17 = 48, //!< cpuss.dw0_tr_out[17]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT18 = 49, //!< cpuss.dw0_tr_out[18]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT19 = 50, //!< cpuss.dw0_tr_out[19]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT20 = 51, //!< cpuss.dw0_tr_out[20]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT21 = 52, //!< cpuss.dw0_tr_out[21]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT22 = 53, //!< cpuss.dw0_tr_out[22]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT23 = 54, //!< cpuss.dw0_tr_out[23]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT24 = 55, //!< cpuss.dw0_tr_out[24]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT25 = 56, //!< cpuss.dw0_tr_out[25]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT26 = 57, //!< cpuss.dw0_tr_out[26]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT27 = 58, //!< cpuss.dw0_tr_out[27]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT28 = 59, //!< cpuss.dw0_tr_out[28]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT29 = 60, //!< cpuss.dw0_tr_out[29]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT30 = 61, //!< cpuss.dw0_tr_out[30]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT31 = 62, //!< cpuss.dw0_tr_out[31]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT32 = 63, //!< cpuss.dw0_tr_out[32]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT33 = 64, //!< cpuss.dw0_tr_out[33]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT34 = 65, //!< cpuss.dw0_tr_out[34]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT35 = 66, //!< cpuss.dw0_tr_out[35]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT36 = 67, //!< cpuss.dw0_tr_out[36]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT37 = 68, //!< cpuss.dw0_tr_out[37]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT38 = 69, //!< cpuss.dw0_tr_out[38]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT39 = 70, //!< cpuss.dw0_tr_out[39]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT40 = 71, //!< cpuss.dw0_tr_out[40]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT41 = 72, //!< cpuss.dw0_tr_out[41]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT42 = 73, //!< cpuss.dw0_tr_out[42]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT43 = 74, //!< cpuss.dw0_tr_out[43]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT44 = 75, //!< cpuss.dw0_tr_out[44]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT45 = 76, //!< cpuss.dw0_tr_out[45]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT46 = 77, //!< cpuss.dw0_tr_out[46]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT47 = 78, //!< cpuss.dw0_tr_out[47]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT48 = 79, //!< cpuss.dw0_tr_out[48]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT49 = 80, //!< cpuss.dw0_tr_out[49]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT50 = 81, //!< cpuss.dw0_tr_out[50]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT51 = 82, //!< cpuss.dw0_tr_out[51]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT52 = 83, //!< cpuss.dw0_tr_out[52]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT53 = 84, //!< cpuss.dw0_tr_out[53]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT54 = 85, //!< cpuss.dw0_tr_out[54]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT55 = 86, //!< cpuss.dw0_tr_out[55]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT56 = 87, //!< cpuss.dw0_tr_out[56]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT57 = 88, //!< cpuss.dw0_tr_out[57]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT58 = 89, //!< cpuss.dw0_tr_out[58]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT59 = 90, //!< cpuss.dw0_tr_out[59]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT60 = 91, //!< cpuss.dw0_tr_out[60]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT61 = 92, //!< cpuss.dw0_tr_out[61]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT62 = 93, //!< cpuss.dw0_tr_out[62]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT63 = 94, //!< cpuss.dw0_tr_out[63]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT64 = 95, //!< cpuss.dw0_tr_out[64]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT65 = 96, //!< cpuss.dw0_tr_out[65]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT66 = 97, //!< cpuss.dw0_tr_out[66]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT67 = 98, //!< cpuss.dw0_tr_out[67]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT68 = 99, //!< cpuss.dw0_tr_out[68]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT69 = 100, //!< cpuss.dw0_tr_out[69]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT70 = 101, //!< cpuss.dw0_tr_out[70]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT71 = 102, //!< cpuss.dw0_tr_out[71]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT72 = 103, //!< cpuss.dw0_tr_out[72]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT73 = 104, //!< cpuss.dw0_tr_out[73]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT74 = 105, //!< cpuss.dw0_tr_out[74]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT75 = 106, //!< cpuss.dw0_tr_out[75]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT76 = 107, //!< cpuss.dw0_tr_out[76]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT77 = 108, //!< cpuss.dw0_tr_out[77]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT78 = 109, //!< cpuss.dw0_tr_out[78]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT79 = 110, //!< cpuss.dw0_tr_out[79]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT80 = 111, //!< cpuss.dw0_tr_out[80]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT81 = 112, //!< cpuss.dw0_tr_out[81]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT82 = 113, //!< cpuss.dw0_tr_out[82]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT83 = 114, //!< cpuss.dw0_tr_out[83]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT84 = 115, //!< cpuss.dw0_tr_out[84]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT85 = 116, //!< cpuss.dw0_tr_out[85]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT86 = 117, //!< cpuss.dw0_tr_out[86]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT87 = 118, //!< cpuss.dw0_tr_out[87]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT88 = 119, //!< cpuss.dw0_tr_out[88]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT0 = 120, //!< cpuss.dw1_tr_out[0]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT1 = 121, //!< cpuss.dw1_tr_out[1]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT2 = 122, //!< cpuss.dw1_tr_out[2]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT3 = 123, //!< cpuss.dw1_tr_out[3]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT4 = 124, //!< cpuss.dw1_tr_out[4]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT5 = 125, //!< cpuss.dw1_tr_out[5]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT6 = 126, //!< cpuss.dw1_tr_out[6]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT7 = 127, //!< cpuss.dw1_tr_out[7]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT8 = 128, //!< cpuss.dw1_tr_out[8]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT9 = 129, //!< cpuss.dw1_tr_out[9]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT10 = 130, //!< cpuss.dw1_tr_out[10]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT11 = 131, //!< cpuss.dw1_tr_out[11]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT12 = 132, //!< cpuss.dw1_tr_out[12]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT13 = 133, //!< cpuss.dw1_tr_out[13]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT14 = 134, //!< cpuss.dw1_tr_out[14]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT15 = 135, //!< cpuss.dw1_tr_out[15]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT16 = 136, //!< cpuss.dw1_tr_out[16]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT17 = 137, //!< cpuss.dw1_tr_out[17]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT18 = 138, //!< cpuss.dw1_tr_out[18]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT19 = 139, //!< cpuss.dw1_tr_out[19]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT20 = 140, //!< cpuss.dw1_tr_out[20]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT21 = 141, //!< cpuss.dw1_tr_out[21]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT22 = 142, //!< cpuss.dw1_tr_out[22]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT23 = 143, //!< cpuss.dw1_tr_out[23]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT24 = 144, //!< cpuss.dw1_tr_out[24]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT25 = 145, //!< cpuss.dw1_tr_out[25]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT26 = 146, //!< cpuss.dw1_tr_out[26]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT27 = 147, //!< cpuss.dw1_tr_out[27]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT28 = 148, //!< cpuss.dw1_tr_out[28]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT29 = 149, //!< cpuss.dw1_tr_out[29]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT30 = 150, //!< cpuss.dw1_tr_out[30]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT31 = 151, //!< cpuss.dw1_tr_out[31]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT32 = 152, //!< cpuss.dw1_tr_out[32]
    _CYHAL_TRIGGER_CPUSS_TR_FAULT0 = 153, //!< cpuss.tr_fault[0]
    _CYHAL_TRIGGER_CPUSS_TR_FAULT1 = 154, //!< cpuss.tr_fault[1]
    _CYHAL_TRIGGER_CPUSS_TR_FAULT2 = 155, //!< cpuss.tr_fault[2]
    _CYHAL_TRIGGER_CPUSS_TR_FAULT3 = 156, //!< cpuss.tr_fault[3]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT0 = 157, //!< evtgen[0].tr_out[0]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT1 = 158, //!< evtgen[0].tr_out[1]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT2 = 159, //!< evtgen[0].tr_out[2]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT3 = 160, //!< evtgen[0].tr_out[3]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT4 = 161, //!< evtgen[0].tr_out[4]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT5 = 162, //!< evtgen[0].tr_out[5]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT6 = 163, //!< evtgen[0].tr_out[6]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT7 = 164, //!< evtgen[0].tr_out[7]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT8 = 165, //!< evtgen[0].tr_out[8]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT9 = 166, //!< evtgen[0].tr_out[9]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT10 = 167, //!< evtgen[0].tr_out[10]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE0 = 168, //!< pass[0].tr_sar_ch_done[0]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE1 = 169, //!< pass[0].tr_sar_ch_done[1]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE2 = 170, //!< pass[0].tr_sar_ch_done[2]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE3 = 171, //!< pass[0].tr_sar_ch_done[3]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE4 = 172, //!< pass[0].tr_sar_ch_done[4]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE5 = 173, //!< pass[0].tr_sar_ch_done[5]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE6 = 174, //!< pass[0].tr_sar_ch_done[6]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE7 = 175, //!< pass[0].tr_sar_ch_done[7]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE8 = 176, //!< pass[0].tr_sar_ch_done[8]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE9 = 177, //!< pass[0].tr_sar_ch_done[9]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE10 = 178, //!< pass[0].tr_sar_ch_done[10]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE11 = 179, //!< pass[0].tr_sar_ch_done[11]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE12 = 180, //!< pass[0].tr_sar_ch_done[12]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE13 = 181, //!< pass[0].tr_sar_ch_done[13]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE14 = 182, //!< pass[0].tr_sar_ch_done[14]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE15 = 183, //!< pass[0].tr_sar_ch_done[15]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE16 = 184, //!< pass[0].tr_sar_ch_done[16]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE17 = 185, //!< pass[0].tr_sar_ch_done[17]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE18 = 186, //!< pass[0].tr_sar_ch_done[18]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE19 = 187, //!< pass[0].tr_sar_ch_done[19]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE20 = 188, //!< pass[0].tr_sar_ch_done[20]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE21 = 189, //!< pass[0].tr_sar_ch_done[21]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE22 = 190, //!< pass[0].tr_sar_ch_done[22]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE23 = 191, //!< pass[0].tr_sar_ch_done[23]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE32 = 192, //!< pass[0].tr_sar_ch_done[32]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE33 = 193, //!< pass[0].tr_sar_ch_done[33]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE34 = 194, //!< pass[0].tr_sar_ch_done[34]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE35 = 195, //!< pass[0].tr_sar_ch_done[35]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE36 = 196, //!< pass[0].tr_sar_ch_done[36]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE37 = 197, //!< pass[0].tr_sar_ch_done[37]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE38 = 198, //!< pass[0].tr_sar_ch_done[38]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE39 = 199, //!< pass[0].tr_sar_ch_done[39]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE40 = 200, //!< pass[0].tr_sar_ch_done[40]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE41 = 201, //!< pass[0].tr_sar_ch_done[41]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE42 = 202, //!< pass[0].tr_sar_ch_done[42]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE43 = 203, //!< pass[0].tr_sar_ch_done[43]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE44 = 204, //!< pass[0].tr_sar_ch_done[44]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE45 = 205, //!< pass[0].tr_sar_ch_done[45]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE46 = 206, //!< pass[0].tr_sar_ch_done[46]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE47 = 207, //!< pass[0].tr_sar_ch_done[47]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE48 = 208, //!< pass[0].tr_sar_ch_done[48]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE49 = 209, //!< pass[0].tr_sar_ch_done[49]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE50 = 210, //!< pass[0].tr_sar_ch_done[50]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE51 = 211, //!< pass[0].tr_sar_ch_done[51]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE52 = 212, //!< pass[0].tr_sar_ch_done[52]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE53 = 213, //!< pass[0].tr_sar_ch_done[53]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE54 = 214, //!< pass[0].tr_sar_ch_done[54]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE55 = 215, //!< pass[0].tr_sar_ch_done[55]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE56 = 216, //!< pass[0].tr_sar_ch_done[56]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE57 = 217, //!< pass[0].tr_sar_ch_done[57]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE58 = 218, //!< pass[0].tr_sar_ch_done[58]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE59 = 219, //!< pass[0].tr_sar_ch_done[59]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE60 = 220, //!< pass[0].tr_sar_ch_done[60]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE61 = 221, //!< pass[0].tr_sar_ch_done[61]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE62 = 222, //!< pass[0].tr_sar_ch_done[62]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE63 = 223, //!< pass[0].tr_sar_ch_done[63]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE64 = 224, //!< pass[0].tr_sar_ch_done[64]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE65 = 225, //!< pass[0].tr_sar_ch_done[65]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE66 = 226, //!< pass[0].tr_sar_ch_done[66]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE67 = 227, //!< pass[0].tr_sar_ch_done[67]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE68 = 228, //!< pass[0].tr_sar_ch_done[68]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE69 = 229, //!< pass[0].tr_sar_ch_done[69]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE70 = 230, //!< pass[0].tr_sar_ch_done[70]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE71 = 231, //!< pass[0].tr_sar_ch_done[71]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO0 = 232, //!< pass[0].tr_sar_ch_rangevio[0]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO1 = 233, //!< pass[0].tr_sar_ch_rangevio[1]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO2 = 234, //!< pass[0].tr_sar_ch_rangevio[2]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO3 = 235, //!< pass[0].tr_sar_ch_rangevio[3]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO4 = 236, //!< pass[0].tr_sar_ch_rangevio[4]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO5 = 237, //!< pass[0].tr_sar_ch_rangevio[5]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO6 = 238, //!< pass[0].tr_sar_ch_rangevio[6]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO7 = 239, //!< pass[0].tr_sar_ch_rangevio[7]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO8 = 240, //!< pass[0].tr_sar_ch_rangevio[8]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO9 = 241, //!< pass[0].tr_sar_ch_rangevio[9]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO10 = 242, //!< pass[0].tr_sar_ch_rangevio[10]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO11 = 243, //!< pass[0].tr_sar_ch_rangevio[11]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO12 = 244, //!< pass[0].tr_sar_ch_rangevio[12]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO13 = 245, //!< pass[0].tr_sar_ch_rangevio[13]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO14 = 246, //!< pass[0].tr_sar_ch_rangevio[14]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO15 = 247, //!< pass[0].tr_sar_ch_rangevio[15]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO16 = 248, //!< pass[0].tr_sar_ch_rangevio[16]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO17 = 249, //!< pass[0].tr_sar_ch_rangevio[17]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO18 = 250, //!< pass[0].tr_sar_ch_rangevio[18]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO19 = 251, //!< pass[0].tr_sar_ch_rangevio[19]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO20 = 252, //!< pass[0].tr_sar_ch_rangevio[20]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO21 = 253, //!< pass[0].tr_sar_ch_rangevio[21]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO22 = 254, //!< pass[0].tr_sar_ch_rangevio[22]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO23 = 255, //!< pass[0].tr_sar_ch_rangevio[23]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO32 = 256, //!< pass[0].tr_sar_ch_rangevio[32]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO33 = 257, //!< pass[0].tr_sar_ch_rangevio[33]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO34 = 258, //!< pass[0].tr_sar_ch_rangevio[34]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO35 = 259, //!< pass[0].tr_sar_ch_rangevio[35]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO36 = 260, //!< pass[0].tr_sar_ch_rangevio[36]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO37 = 261, //!< pass[0].tr_sar_ch_rangevio[37]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO38 = 262, //!< pass[0].tr_sar_ch_rangevio[38]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO39 = 263, //!< pass[0].tr_sar_ch_rangevio[39]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO40 = 264, //!< pass[0].tr_sar_ch_rangevio[40]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO41 = 265, //!< pass[0].tr_sar_ch_rangevio[41]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO42 = 266, //!< pass[0].tr_sar_ch_rangevio[42]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO43 = 267, //!< pass[0].tr_sar_ch_rangevio[43]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO44 = 268, //!< pass[0].tr_sar_ch_rangevio[44]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO45 = 269, //!< pass[0].tr_sar_ch_rangevio[45]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO46 = 270, //!< pass[0].tr_sar_ch_rangevio[46]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO47 = 271, //!< pass[0].tr_sar_ch_rangevio[47]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO48 = 272, //!< pass[0].tr_sar_ch_rangevio[48]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO49 = 273, //!< pass[0].tr_sar_ch_rangevio[49]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO50 = 274, //!< pass[0].tr_sar_ch_rangevio[50]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO51 = 275, //!< pass[0].tr_sar_ch_rangevio[51]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO52 = 276, //!< pass[0].tr_sar_ch_rangevio[52]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO53 = 277, //!< pass[0].tr_sar_ch_rangevio[53]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO54 = 278, //!< pass[0].tr_sar_ch_rangevio[54]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO55 = 279, //!< pass[0].tr_sar_ch_rangevio[55]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO56 = 280, //!< pass[0].tr_sar_ch_rangevio[56]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO57 = 281, //!< pass[0].tr_sar_ch_rangevio[57]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO58 = 282, //!< pass[0].tr_sar_ch_rangevio[58]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO59 = 283, //!< pass[0].tr_sar_ch_rangevio[59]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO60 = 284, //!< pass[0].tr_sar_ch_rangevio[60]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO61 = 285, //!< pass[0].tr_sar_ch_rangevio[61]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO62 = 286, //!< pass[0].tr_sar_ch_rangevio[62]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO63 = 287, //!< pass[0].tr_sar_ch_rangevio[63]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO64 = 288, //!< pass[0].tr_sar_ch_rangevio[64]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO65 = 289, //!< pass[0].tr_sar_ch_rangevio[65]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO66 = 290, //!< pass[0].tr_sar_ch_rangevio[66]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO67 = 291, //!< pass[0].tr_sar_ch_rangevio[67]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO68 = 292, //!< pass[0].tr_sar_ch_rangevio[68]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO69 = 293, //!< pass[0].tr_sar_ch_rangevio[69]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO70 = 294, //!< pass[0].tr_sar_ch_rangevio[70]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO71 = 295, //!< pass[0].tr_sar_ch_rangevio[71]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT0 = 296, //!< pass[0].tr_sar_gen_out[0]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT1 = 297, //!< pass[0].tr_sar_gen_out[1]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT2 = 298, //!< pass[0].tr_sar_gen_out[2]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT3 = 299, //!< pass[0].tr_sar_gen_out[3]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT4 = 300, //!< pass[0].tr_sar_gen_out[4]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT5 = 301, //!< pass[0].tr_sar_gen_out[5]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT0 = 302, //!< peri.tr_io_input[0]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT1 = 303, //!< peri.tr_io_input[1]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT2 = 304, //!< peri.tr_io_input[2]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT3 = 305, //!< peri.tr_io_input[3]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT4 = 306, //!< peri.tr_io_input[4]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT5 = 307, //!< peri.tr_io_input[5]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT6 = 308, //!< peri.tr_io_input[6]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT7 = 309, //!< peri.tr_io_input[7]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT8 = 310, //!< peri.tr_io_input[8]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT9 = 311, //!< peri.tr_io_input[9]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT10 = 312, //!< peri.tr_io_input[10]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT11 = 313, //!< peri.tr_io_input[11]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT12 = 314, //!< peri.tr_io_input[12]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT13 = 315, //!< peri.tr_io_input[13]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT14 = 316, //!< peri.tr_io_input[14]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT15 = 317, //!< peri.tr_io_input[15]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT16 = 318, //!< peri.tr_io_input[16]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT17 = 319, //!< peri.tr_io_input[17]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT18 = 320, //!< peri.tr_io_input[18]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT19 = 321, //!< peri.tr_io_input[19]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT20 = 322, //!< peri.tr_io_input[20]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT21 = 323, //!< peri.tr_io_input[21]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT22 = 324, //!< peri.tr_io_input[22]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT23 = 325, //!< peri.tr_io_input[23]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT24 = 326, //!< peri.tr_io_input[24]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT25 = 327, //!< peri.tr_io_input[25]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT26 = 328, //!< peri.tr_io_input[26]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT27 = 329, //!< peri.tr_io_input[27]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT28 = 330, //!< peri.tr_io_input[28]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT29 = 331, //!< peri.tr_io_input[29]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT30 = 332, //!< peri.tr_io_input[30]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT31 = 333, //!< peri.tr_io_input[31]
    _CYHAL_TRIGGER_SCB0_TR_I2C_SCL_FILTERED = 334, //!< scb[0].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB1_TR_I2C_SCL_FILTERED = 335, //!< scb[1].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB2_TR_I2C_SCL_FILTERED = 336, //!< scb[2].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB3_TR_I2C_SCL_FILTERED = 337, //!< scb[3].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB4_TR_I2C_SCL_FILTERED = 338, //!< scb[4].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB5_TR_I2C_SCL_FILTERED = 339, //!< scb[5].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB6_TR_I2C_SCL_FILTERED = 340, //!< scb[6].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB7_TR_I2C_SCL_FILTERED = 341, //!< scb[7].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB0_TR_RX_REQ = 342, //!< scb[0].tr_rx_req
    _CYHAL_TRIGGER_SCB1_TR_RX_REQ = 343, //!< scb[1].tr_rx_req
    _CYHAL_TRIGGER_SCB2_TR_RX_REQ = 344, //!< scb[2].tr_rx_req
    _CYHAL_TRIGGER_SCB3_TR_RX_REQ = 345, //!< scb[3].tr_rx_req
    _CYHAL_TRIGGER_SCB4_TR_RX_REQ = 346, //!< scb[4].tr_rx_req
    _CYHAL_TRIGGER_SCB5_TR_RX_REQ = 347, //!< scb[5].tr_rx_req
    _CYHAL_TRIGGER_SCB6_TR_RX_REQ = 348, //!< scb[6].tr_rx_req
    _CYHAL_TRIGGER_SCB7_TR_RX_REQ = 349, //!< scb[7].tr_rx_req
    _CYHAL_TRIGGER_SCB0_TR_TX_REQ = 350, //!< scb[0].tr_tx_req
    _CYHAL_TRIGGER_SCB1_TR_TX_REQ = 351, //!< scb[1].tr_tx_req
    _CYHAL_TRIGGER_SCB2_TR_TX_REQ = 352, //!< scb[2].tr_tx_req
    _CYHAL_TRIGGER_SCB3_TR_TX_REQ = 353, //!< scb[3].tr_tx_req
    _CYHAL_TRIGGER_SCB4_TR_TX_REQ = 354, //!< scb[4].tr_tx_req
    _CYHAL_TRIGGER_SCB5_TR_TX_REQ = 355, //!< scb[5].tr_tx_req
    _CYHAL_TRIGGER_SCB6_TR_TX_REQ = 356, //!< scb[6].tr_tx_req
    _CYHAL_TRIGGER_SCB7_TR_TX_REQ = 357, //!< scb[7].tr_tx_req
    _CYHAL_TRIGGER_TCPWM0_TR_OUT00 = 358, //!< tcpwm[0].tr_out0[0]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT01 = 359, //!< tcpwm[0].tr_out0[1]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT02 = 360, //!< tcpwm[0].tr_out0[2]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT03 = 361, //!< tcpwm[0].tr_out0[3]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT04 = 362, //!< tcpwm[0].tr_out0[4]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT05 = 363, //!< tcpwm[0].tr_out0[5]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT06 = 364, //!< tcpwm[0].tr_out0[6]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT07 = 365, //!< tcpwm[0].tr_out0[7]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT08 = 366, //!< tcpwm[0].tr_out0[8]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT09 = 367, //!< tcpwm[0].tr_out0[9]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT010 = 368, //!< tcpwm[0].tr_out0[10]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT011 = 369, //!< tcpwm[0].tr_out0[11]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT012 = 370, //!< tcpwm[0].tr_out0[12]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT013 = 371, //!< tcpwm[0].tr_out0[13]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT014 = 372, //!< tcpwm[0].tr_out0[14]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT015 = 373, //!< tcpwm[0].tr_out0[15]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT016 = 374, //!< tcpwm[0].tr_out0[16]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT017 = 375, //!< tcpwm[0].tr_out0[17]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT018 = 376, //!< tcpwm[0].tr_out0[18]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT019 = 377, //!< tcpwm[0].tr_out0[19]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT020 = 378, //!< tcpwm[0].tr_out0[20]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT021 = 379, //!< tcpwm[0].tr_out0[21]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT022 = 380, //!< tcpwm[0].tr_out0[22]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT023 = 381, //!< tcpwm[0].tr_out0[23]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT024 = 382, //!< tcpwm[0].tr_out0[24]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT025 = 383, //!< tcpwm[0].tr_out0[25]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT026 = 384, //!< tcpwm[0].tr_out0[26]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT027 = 385, //!< tcpwm[0].tr_out0[27]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT028 = 386, //!< tcpwm[0].tr_out0[28]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT029 = 387, //!< tcpwm[0].tr_out0[29]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT030 = 388, //!< tcpwm[0].tr_out0[30]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT031 = 389, //!< tcpwm[0].tr_out0[31]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT032 = 390, //!< tcpwm[0].tr_out0[32]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT033 = 391, //!< tcpwm[0].tr_out0[33]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT034 = 392, //!< tcpwm[0].tr_out0[34]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT035 = 393, //!< tcpwm[0].tr_out0[35]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT036 = 394, //!< tcpwm[0].tr_out0[36]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT037 = 395, //!< tcpwm[0].tr_out0[37]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT038 = 396, //!< tcpwm[0].tr_out0[38]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT039 = 397, //!< tcpwm[0].tr_out0[39]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT040 = 398, //!< tcpwm[0].tr_out0[40]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT041 = 399, //!< tcpwm[0].tr_out0[41]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT042 = 400, //!< tcpwm[0].tr_out0[42]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT043 = 401, //!< tcpwm[0].tr_out0[43]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT044 = 402, //!< tcpwm[0].tr_out0[44]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT045 = 403, //!< tcpwm[0].tr_out0[45]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT046 = 404, //!< tcpwm[0].tr_out0[46]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT047 = 405, //!< tcpwm[0].tr_out0[47]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT048 = 406, //!< tcpwm[0].tr_out0[48]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT049 = 407, //!< tcpwm[0].tr_out0[49]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT050 = 408, //!< tcpwm[0].tr_out0[50]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT051 = 409, //!< tcpwm[0].tr_out0[51]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT052 = 410, //!< tcpwm[0].tr_out0[52]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT053 = 411, //!< tcpwm[0].tr_out0[53]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT054 = 412, //!< tcpwm[0].tr_out0[54]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT055 = 413, //!< tcpwm[0].tr_out0[55]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT056 = 414, //!< tcpwm[0].tr_out0[56]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT057 = 415, //!< tcpwm[0].tr_out0[57]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT058 = 416, //!< tcpwm[0].tr_out0[58]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT059 = 417, //!< tcpwm[0].tr_out0[59]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT060 = 418, //!< tcpwm[0].tr_out0[60]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT061 = 419, //!< tcpwm[0].tr_out0[61]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT062 = 420, //!< tcpwm[0].tr_out0[62]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0256 = 421, //!< tcpwm[0].tr_out0[256]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0257 = 422, //!< tcpwm[0].tr_out0[257]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0258 = 423, //!< tcpwm[0].tr_out0[258]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0259 = 424, //!< tcpwm[0].tr_out0[259]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0260 = 425, //!< tcpwm[0].tr_out0[260]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0261 = 426, //!< tcpwm[0].tr_out0[261]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0262 = 427, //!< tcpwm[0].tr_out0[262]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0263 = 428, //!< tcpwm[0].tr_out0[263]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0264 = 429, //!< tcpwm[0].tr_out0[264]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0265 = 430, //!< tcpwm[0].tr_out0[265]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0266 = 431, //!< tcpwm[0].tr_out0[266]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0267 = 432, //!< tcpwm[0].tr_out0[267]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0512 = 433, //!< tcpwm[0].tr_out0[512]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0513 = 434, //!< tcpwm[0].tr_out0[513]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0514 = 435, //!< tcpwm[0].tr_out0[514]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0515 = 436, //!< tcpwm[0].tr_out0[515]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT10 = 437, //!< tcpwm[0].tr_out1[0]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT11 = 438, //!< tcpwm[0].tr_out1[1]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT12 = 439, //!< tcpwm[0].tr_out1[2]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT13 = 440, //!< tcpwm[0].tr_out1[3]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT14 = 441, //!< tcpwm[0].tr_out1[4]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT15 = 442, //!< tcpwm[0].tr_out1[5]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT16 = 443, //!< tcpwm[0].tr_out1[6]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT17 = 444, //!< tcpwm[0].tr_out1[7]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT18 = 445, //!< tcpwm[0].tr_out1[8]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT19 = 446, //!< tcpwm[0].tr_out1[9]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT110 = 447, //!< tcpwm[0].tr_out1[10]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT111 = 448, //!< tcpwm[0].tr_out1[11]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT112 = 449, //!< tcpwm[0].tr_out1[12]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT113 = 450, //!< tcpwm[0].tr_out1[13]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT114 = 451, //!< tcpwm[0].tr_out1[14]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT115 = 452, //!< tcpwm[0].tr_out1[15]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT116 = 453, //!< tcpwm[0].tr_out1[16]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT117 = 454, //!< tcpwm[0].tr_out1[17]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT118 = 455, //!< tcpwm[0].tr_out1[18]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT119 = 456, //!< tcpwm[0].tr_out1[19]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT120 = 457, //!< tcpwm[0].tr_out1[20]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT121 = 458, //!< tcpwm[0].tr_out1[21]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT122 = 459, //!< tcpwm[0].tr_out1[22]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT123 = 460, //!< tcpwm[0].tr_out1[23]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT124 = 461, //!< tcpwm[0].tr_out1[24]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT125 = 462, //!< tcpwm[0].tr_out1[25]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT126 = 463, //!< tcpwm[0].tr_out1[26]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT127 = 464, //!< tcpwm[0].tr_out1[27]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT128 = 465, //!< tcpwm[0].tr_out1[28]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT129 = 466, //!< tcpwm[0].tr_out1[29]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT130 = 467, //!< tcpwm[0].tr_out1[30]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT131 = 468, //!< tcpwm[0].tr_out1[31]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT132 = 469, //!< tcpwm[0].tr_out1[32]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT133 = 470, //!< tcpwm[0].tr_out1[33]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT134 = 471, //!< tcpwm[0].tr_out1[34]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT135 = 472, //!< tcpwm[0].tr_out1[35]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT136 = 473, //!< tcpwm[0].tr_out1[36]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT137 = 474, //!< tcpwm[0].tr_out1[37]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT138 = 475, //!< tcpwm[0].tr_out1[38]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT139 = 476, //!< tcpwm[0].tr_out1[39]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT140 = 477, //!< tcpwm[0].tr_out1[40]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT141 = 478, //!< tcpwm[0].tr_out1[41]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT142 = 479, //!< tcpwm[0].tr_out1[42]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT143 = 480, //!< tcpwm[0].tr_out1[43]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT144 = 481, //!< tcpwm[0].tr_out1[44]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT145 = 482, //!< tcpwm[0].tr_out1[45]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT146 = 483, //!< tcpwm[0].tr_out1[46]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT147 = 484, //!< tcpwm[0].tr_out1[47]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT148 = 485, //!< tcpwm[0].tr_out1[48]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT149 = 486, //!< tcpwm[0].tr_out1[49]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT150 = 487, //!< tcpwm[0].tr_out1[50]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT151 = 488, //!< tcpwm[0].tr_out1[51]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT152 = 489, //!< tcpwm[0].tr_out1[52]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT153 = 490, //!< tcpwm[0].tr_out1[53]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT154 = 491, //!< tcpwm[0].tr_out1[54]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT155 = 492, //!< tcpwm[0].tr_out1[55]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT156 = 493, //!< tcpwm[0].tr_out1[56]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT157 = 494, //!< tcpwm[0].tr_out1[57]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT158 = 495, //!< tcpwm[0].tr_out1[58]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT159 = 496, //!< tcpwm[0].tr_out1[59]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT160 = 497, //!< tcpwm[0].tr_out1[60]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT161 = 498, //!< tcpwm[0].tr_out1[61]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT162 = 499, //!< tcpwm[0].tr_out1[62]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1256 = 500, //!< tcpwm[0].tr_out1[256]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1257 = 501, //!< tcpwm[0].tr_out1[257]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1258 = 502, //!< tcpwm[0].tr_out1[258]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1259 = 503, //!< tcpwm[0].tr_out1[259]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1260 = 504, //!< tcpwm[0].tr_out1[260]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1261 = 505, //!< tcpwm[0].tr_out1[261]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1262 = 506, //!< tcpwm[0].tr_out1[262]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1263 = 507, //!< tcpwm[0].tr_out1[263]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1264 = 508, //!< tcpwm[0].tr_out1[264]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1265 = 509, //!< tcpwm[0].tr_out1[265]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1266 = 510, //!< tcpwm[0].tr_out1[266]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1267 = 511, //!< tcpwm[0].tr_out1[267]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1512 = 512, //!< tcpwm[0].tr_out1[512]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1513 = 513, //!< tcpwm[0].tr_out1[513]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1514 = 514, //!< tcpwm[0].tr_out1[514]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1515 = 515, //!< tcpwm[0].tr_out1[515]
    _CYHAL_TRIGGER_TR_GROUP9_OUTPUT0 = 516, //!< tr_group[9].output[0]
    _CYHAL_TRIGGER_TR_GROUP9_OUTPUT1 = 517, //!< tr_group[9].output[1]
    _CYHAL_TRIGGER_TR_GROUP9_OUTPUT2 = 518, //!< tr_group[9].output[2]
    _CYHAL_TRIGGER_TR_GROUP9_OUTPUT3 = 519, //!< tr_group[9].output[3]
    _CYHAL_TRIGGER_TR_GROUP9_OUTPUT4 = 520, //!< tr_group[9].output[4]
    _CYHAL_TRIGGER_TR_GROUP10_OUTPUT0 = 521, //!< tr_group[10].output[0]
    _CYHAL_TRIGGER_TR_GROUP10_OUTPUT1 = 522, //!< tr_group[10].output[1]
    _CYHAL_TRIGGER_TR_GROUP10_OUTPUT2 = 523, //!< tr_group[10].output[2]
    _CYHAL_TRIGGER_TR_GROUP10_OUTPUT3 = 524, //!< tr_group[10].output[3]
    _CYHAL_TRIGGER_TR_GROUP10_OUTPUT4 = 525, //!< tr_group[10].output[4]
} _cyhal_trigger_source_tviibe1m_t;

/** Typedef for internal device family specific trigger source to generic trigger source */
typedef _cyhal_trigger_source_tviibe1m_t cyhal_internal_source_t;

/** @brief Get a public source signal type (cyhal_trigger_source_tviibe1m_t) given an internal source signal and signal type */
#define _CYHAL_TRIGGER_CREATE_SOURCE(src, type)    ((src) << 1 | (type))
/** @brief Get an internal source signal (_cyhal_trigger_source_tviibe1m_t) given a public source signal. */
#define _CYHAL_TRIGGER_GET_SOURCE_SIGNAL(src)      ((cyhal_internal_source_t)((src) >> 1))
/** @brief Get the signal type (cyhal_signal_type_t) given a public source signal. */
#define _CYHAL_TRIGGER_GET_SOURCE_TYPE(src)        ((cyhal_signal_type_t)((src) & 1))
/** \endcond */

/** @brief Name of each input trigger. */
typedef enum
{
    CYHAL_TRIGGER_CPUSS_ZERO_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_ZERO, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.zero
    CYHAL_TRIGGER_CPUSS_ZERO_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_ZERO, CYHAL_SIGNAL_TYPE_LEVEL), //!< cpuss.zero
    CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ0, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_dbg_dma_req[0]
    CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ1, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_dbg_dma_req[1]
    CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ2, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_dbg_dma_req[2]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ0, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_dbg_dma_req[0]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ1, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_dbg_dma_req[1]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ2, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_dbg_dma_req[2]
    CYHAL_TRIGGER_CANFD0_TR_FIFO00 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO00, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo0[0]
    CYHAL_TRIGGER_CANFD0_TR_FIFO01 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO01, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo0[1]
    CYHAL_TRIGGER_CANFD0_TR_FIFO02 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO02, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo0[2]
    CYHAL_TRIGGER_CANFD1_TR_FIFO00 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO00, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo0[0]
    CYHAL_TRIGGER_CANFD1_TR_FIFO01 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO01, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo0[1]
    CYHAL_TRIGGER_CANFD1_TR_FIFO02 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO02, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo0[2]
    CYHAL_TRIGGER_CANFD0_TR_FIFO10 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO10, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo1[0]
    CYHAL_TRIGGER_CANFD0_TR_FIFO11 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO11, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo1[1]
    CYHAL_TRIGGER_CANFD0_TR_FIFO12 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO12, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo1[2]
    CYHAL_TRIGGER_CANFD1_TR_FIFO10 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO10, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo1[0]
    CYHAL_TRIGGER_CANFD1_TR_FIFO11 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO11, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo1[1]
    CYHAL_TRIGGER_CANFD1_TR_FIFO12 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO12, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo1[2]
    CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[0].tr_tmp_rtp_out[0]
    CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[0].tr_tmp_rtp_out[1]
    CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[0].tr_tmp_rtp_out[2]
    CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[1].tr_tmp_rtp_out[0]
    CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[1].tr_tmp_rtp_out[1]
    CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[1].tr_tmp_rtp_out[2]
    CYHAL_TRIGGER_CPUSS_CTI_TR_OUT0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_CTI_TR_OUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.cti_tr_out[0]
    CYHAL_TRIGGER_CPUSS_CTI_TR_OUT1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_CTI_TR_OUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.cti_tr_out[1]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dmac_tr_out[0]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dmac_tr_out[1]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dmac_tr_out[2]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT3, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dmac_tr_out[3]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[0]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[1]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[2]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT3, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[3]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT4 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT4, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[4]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT5 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT5, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[5]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT6 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT6, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[6]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT7 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT7, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[7]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT8 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT8, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[8]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT9 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT9, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[9]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT10 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT10, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[10]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT11 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT11, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[11]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT12 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT12, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[12]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT13 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT13, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[13]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT14 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT14, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[14]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT15 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT15, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[15]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT16 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT16, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[16]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT17 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT17, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[17]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT18 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT18, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[18]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT19 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT19, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[19]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT20 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT20, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[20]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT21 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT21, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[21]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT22 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT22, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[22]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT23 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT23, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[23]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT24 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT24, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[24]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT25 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT25, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[25]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT26 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT26, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[26]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT27 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT27, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[27]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT28 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT28, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[28]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT29 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT29, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[29]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT30 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT30, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[30]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT31 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT31, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[31]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT32 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT32, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[32]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT33 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT33, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[33]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT34 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT34, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[34]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT35 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT35, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[35]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT36 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT36, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[36]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT37 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT37, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[37]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT38 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT38, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[38]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT39 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT39, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[39]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT40 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT40, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[40]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT41 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT41, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[41]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT42 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT42, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[42]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT43 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT43, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[43]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT44 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT44, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[44]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT45 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT45, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[45]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT46 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT46, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[46]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT47 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT47, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[47]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT48 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT48, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[48]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT49 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT49, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[49]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT50 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT50, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[50]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT51 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT51, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[51]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT52 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT52, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[52]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT53 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT53, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[53]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT54 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT54, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[54]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT55 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT55, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[55]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT56 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT56, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[56]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT57 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT57, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[57]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT58 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT58, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[58]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT59 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT59, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[59]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT60 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT60, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[60]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT61 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT61, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[61]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT62 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT62, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[62]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT63 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT63, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[63]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT64 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT64, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[64]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT65 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT65, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[65]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT66 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT66, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[66]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT67 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT67, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[67]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT68 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT68, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[68]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT69 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT69, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[69]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT70 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT70, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[70]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT71 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT71, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[71]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT72 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT72, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[72]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT73 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT73, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[73]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT74 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT74, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[74]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT75 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT75, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[75]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT76 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT76, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[76]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT77 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT77, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[77]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT78 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT78, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[78]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT79 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT79, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[79]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT80 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT80, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[80]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT81 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT81, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[81]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT82 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT82, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[82]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT83 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT83, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[83]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT84 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT84, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[84]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT85 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT85, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[85]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT86 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT86, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[86]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT87 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT87, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[87]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT88 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT88, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[88]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[0]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[1]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[2]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT3, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[3]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT4 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT4, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[4]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT5 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT5, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[5]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT6 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT6, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[6]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT7 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT7, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[7]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT8 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT8, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[8]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT9 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT9, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[9]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT10 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT10, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[10]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT11 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT11, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[11]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT12 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT12, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[12]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT13 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT13, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[13]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT14 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT14, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[14]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT15 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT15, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[15]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT16 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT16, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[16]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT17 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT17, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[17]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT18 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT18, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[18]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT19 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT19, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[19]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT20 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT20, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[20]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT21 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT21, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[21]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT22 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT22, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[22]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT23 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT23, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[23]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT24 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT24, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[24]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT25 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT25, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[25]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT26 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT26, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[26]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT27 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT27, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[27]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT28 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT28, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[28]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT29 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT29, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[29]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT30 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT30, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[30]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT31 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT31, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[31]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT32 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT32, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[32]
    CYHAL_TRIGGER_CPUSS_TR_FAULT0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_TR_FAULT0, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.tr_fault[0]
    CYHAL_TRIGGER_CPUSS_TR_FAULT1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_TR_FAULT1, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.tr_fault[1]
    CYHAL_TRIGGER_CPUSS_TR_FAULT2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_TR_FAULT2, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.tr_fault[2]
    CYHAL_TRIGGER_CPUSS_TR_FAULT3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_TR_FAULT3, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.tr_fault[3]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT0_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< evtgen[0].tr_out[0]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT0_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT0, CYHAL_SIGNAL_TYPE_LEVEL), //!< evtgen[0].tr_out[0]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT1_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< evtgen[0].tr_out[1]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT1_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT1, CYHAL_SIGNAL_TYPE_LEVEL), //!< evtgen[0].tr_out[1]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT2_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< evtgen[0].tr_out[2]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT2_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT2, CYHAL_SIGNAL_TYPE_LEVEL), //!< evtgen[0].tr_out[2]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT3_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT3, CYHAL_SIGNAL_TYPE_EDGE), //!< evtgen[0].tr_out[3]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT3_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT3, CYHAL_SIGNAL_TYPE_LEVEL), //!< evtgen[0].tr_out[3]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT4_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT4, CYHAL_SIGNAL_TYPE_EDGE), //!< evtgen[0].tr_out[4]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT4_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT4, CYHAL_SIGNAL_TYPE_LEVEL), //!< evtgen[0].tr_out[4]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT5_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT5, CYHAL_SIGNAL_TYPE_EDGE), //!< evtgen[0].tr_out[5]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT5_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT5, CYHAL_SIGNAL_TYPE_LEVEL), //!< evtgen[0].tr_out[5]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT6_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT6, CYHAL_SIGNAL_TYPE_EDGE), //!< evtgen[0].tr_out[6]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT6_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT6, CYHAL_SIGNAL_TYPE_LEVEL), //!< evtgen[0].tr_out[6]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT7_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT7, CYHAL_SIGNAL_TYPE_EDGE), //!< evtgen[0].tr_out[7]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT7_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT7, CYHAL_SIGNAL_TYPE_LEVEL), //!< evtgen[0].tr_out[7]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT8_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT8, CYHAL_SIGNAL_TYPE_EDGE), //!< evtgen[0].tr_out[8]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT8_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT8, CYHAL_SIGNAL_TYPE_LEVEL), //!< evtgen[0].tr_out[8]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT9_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT9, CYHAL_SIGNAL_TYPE_EDGE), //!< evtgen[0].tr_out[9]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT9_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT9, CYHAL_SIGNAL_TYPE_LEVEL), //!< evtgen[0].tr_out[9]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT10_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT10, CYHAL_SIGNAL_TYPE_EDGE), //!< evtgen[0].tr_out[10]
    CYHAL_TRIGGER_EVTGEN0_TR_OUT10_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_EVTGEN0_TR_OUT10, CYHAL_SIGNAL_TYPE_LEVEL), //!< evtgen[0].tr_out[10]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE0_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE0, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[0]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE0_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE0, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[0]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE1_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE1, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[1]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE1_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE1, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[1]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE2_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE2, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[2]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE2_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE2, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[2]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE3_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE3, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[3]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE3_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE3, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[3]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE4_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE4, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[4]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE4_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE4, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[4]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE5_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE5, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[5]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE5_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE5, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[5]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE6_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE6, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[6]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE6_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE6, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[6]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE7_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE7, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[7]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE7_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE7, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[7]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE8_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE8, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[8]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE8_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE8, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[8]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE9_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE9, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[9]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE9_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE9, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[9]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE10_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE10, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[10]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE10_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE10, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[10]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE11_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE11, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[11]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE11_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE11, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[11]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE12_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE12, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[12]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE12_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE12, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[12]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE13_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE13, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[13]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE13_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE13, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[13]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE14_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE14, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[14]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE14_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE14, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[14]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE15_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE15, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[15]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE15_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE15, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[15]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE16_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE16, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[16]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE16_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE16, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[16]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE17_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE17, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[17]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE17_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE17, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[17]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE18_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE18, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[18]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE18_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE18, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[18]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE19_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE19, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[19]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE19_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE19, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[19]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE20_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE20, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[20]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE20_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE20, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[20]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE21_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE21, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[21]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE21_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE21, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[21]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE22_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE22, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[22]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE22_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE22, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[22]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE23_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE23, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[23]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE23_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE23, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[23]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE32_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE32, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[32]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE32_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE32, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[32]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE33_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE33, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[33]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE33_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE33, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[33]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE34_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE34, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[34]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE34_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE34, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[34]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE35_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE35, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[35]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE35_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE35, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[35]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE36_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE36, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[36]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE36_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE36, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[36]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE37_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE37, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[37]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE37_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE37, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[37]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE38_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE38, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[38]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE38_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE38, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[38]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE39_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE39, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[39]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE39_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE39, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[39]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE40_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE40, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[40]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE40_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE40, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[40]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE41_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE41, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[41]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE41_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE41, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[41]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE42_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE42, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[42]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE42_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE42, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[42]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE43_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE43, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[43]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE43_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE43, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[43]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE44_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE44, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[44]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE44_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE44, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[44]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE45_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE45, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[45]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE45_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE45, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[45]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE46_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE46, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[46]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE46_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE46, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[46]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE47_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE47, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[47]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE47_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE47, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[47]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE48_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE48, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[48]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE48_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE48, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[48]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE49_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE49, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[49]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE49_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE49, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[49]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE50_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE50, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[50]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE50_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE50, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[50]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE51_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE51, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[51]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE51_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE51, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[51]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE52_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE52, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[52]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE52_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE52, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[52]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE53_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE53, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[53]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE53_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE53, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[53]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE54_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE54, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[54]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE54_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE54, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[54]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE55_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE55, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[55]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE55_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE55, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[55]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE56_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE56, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[56]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE56_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE56, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[56]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE57_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE57, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[57]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE57_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE57, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[57]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE58_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE58, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[58]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE58_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE58, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[58]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE59_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE59, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[59]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE59_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE59, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[59]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE60_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE60, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[60]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE60_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE60, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[60]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE61_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE61, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[61]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE61_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE61, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[61]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE62_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE62, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[62]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE62_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE62, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[62]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE63_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE63, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[63]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE63_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE63, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[63]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE64_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE64, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[64]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE64_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE64, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[64]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE65_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE65, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[65]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE65_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE65, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[65]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE66_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE66, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[66]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE66_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE66, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[66]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE67_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE67, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[67]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE67_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE67, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[67]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE68_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE68, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[68]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE68_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE68, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[68]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE69_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE69, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[69]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE69_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE69, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[69]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE70_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE70, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[70]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE70_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE70, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[70]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE71_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE71, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_done[71]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE71_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE71, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_ch_done[71]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO0, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[0]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO1, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[1]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO2, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[2]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO3, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[3]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO4 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO4, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[4]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO5 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO5, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[5]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO6 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO6, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[6]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO7 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO7, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[7]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO8 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO8, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[8]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO9 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO9, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[9]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO10 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO10, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[10]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO11 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO11, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[11]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO12 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO12, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[12]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO13 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO13, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[13]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO14 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO14, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[14]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO15 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO15, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[15]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO16 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO16, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[16]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO17 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO17, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[17]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO18 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO18, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[18]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO19 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO19, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[19]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO20 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO20, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[20]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO21 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO21, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[21]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO22 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO22, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[22]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO23 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO23, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[23]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO32 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO32, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[32]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO33 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO33, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[33]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO34 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO34, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[34]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO35 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO35, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[35]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO36 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO36, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[36]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO37 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO37, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[37]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO38 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO38, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[38]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO39 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO39, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[39]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO40 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO40, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[40]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO41 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO41, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[41]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO42 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO42, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[42]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO43 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO43, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[43]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO44 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO44, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[44]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO45 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO45, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[45]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO46 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO46, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[46]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO47 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO47, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[47]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO48 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO48, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[48]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO49 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO49, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[49]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO50 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO50, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[50]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO51 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO51, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[51]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO52 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO52, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[52]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO53 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO53, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[53]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO54 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO54, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[54]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO55 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO55, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[55]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO56 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO56, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[56]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO57 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO57, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[57]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO58 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO58, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[58]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO59 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO59, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[59]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO60 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO60, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[60]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO61 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO61, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[61]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO62 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO62, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[62]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO63 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO63, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[63]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO64 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO64, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[64]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO65 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO65, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[65]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO66 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO66, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[66]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO67 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO67, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[67]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO68 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO68, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[68]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO69 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO69, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[69]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO70 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO70, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[70]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO71 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO71, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_ch_rangevio[71]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT0_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_gen_out[0]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT0_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT0, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_gen_out[0]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT1_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_gen_out[1]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT1_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT1, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_gen_out[1]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT2_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_gen_out[2]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT2_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT2, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_gen_out[2]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT3_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT3, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_gen_out[3]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT3_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT3, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_gen_out[3]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT4_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT4, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_gen_out[4]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT4_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT4, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_gen_out[4]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT5_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT5, CYHAL_SIGNAL_TYPE_EDGE), //!< pass[0].tr_sar_gen_out[5]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT5_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT5, CYHAL_SIGNAL_TYPE_LEVEL), //!< pass[0].tr_sar_gen_out[5]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT0_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[0]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT0_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT0, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[0]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT1_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[1]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT1_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT1, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[1]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT2_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[2]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT2_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT2, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[2]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT3_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT3, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[3]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT3_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT3, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[3]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT4_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT4, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[4]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT4_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT4, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[4]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT5_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT5, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[5]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT5_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT5, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[5]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT6_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT6, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[6]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT6_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT6, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[6]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT7_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT7, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[7]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT7_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT7, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[7]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT8_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT8, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[8]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT8_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT8, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[8]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT9_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT9, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[9]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT9_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT9, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[9]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT10_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT10, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[10]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT10_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT10, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[10]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT11_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT11, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[11]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT11_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT11, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[11]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT12_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT12, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[12]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT12_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT12, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[12]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT13_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT13, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[13]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT13_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT13, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[13]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT14_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT14, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[14]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT14_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT14, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[14]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT15_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT15, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[15]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT15_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT15, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[15]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT16_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT16, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[16]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT16_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT16, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[16]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT17_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT17, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[17]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT17_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT17, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[17]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT18_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT18, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[18]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT18_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT18, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[18]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT19_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT19, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[19]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT19_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT19, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[19]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT20_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT20, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[20]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT20_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT20, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[20]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT21_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT21, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[21]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT21_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT21, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[21]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT22_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT22, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[22]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT22_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT22, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[22]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT23_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT23, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[23]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT23_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT23, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[23]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT24_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT24, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[24]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT24_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT24, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[24]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT25_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT25, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[25]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT25_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT25, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[25]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT26_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT26, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[26]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT26_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT26, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[26]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT27_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT27, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[27]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT27_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT27, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[27]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT28_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT28, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[28]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT28_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT28, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[28]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT29_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT29, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[29]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT29_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT29, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[29]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT30_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT30, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[30]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT30_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT30, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[30]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT31_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT31, CYHAL_SIGNAL_TYPE_EDGE), //!< peri.tr_io_input[31]
    CYHAL_TRIGGER_PERI_TR_IO_INPUT31_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_PERI_TR_IO_INPUT31, CYHAL_SIGNAL_TYPE_LEVEL), //!< peri.tr_io_input[31]
    CYHAL_TRIGGER_SCB0_TR_I2C_SCL_FILTERED = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB0_TR_I2C_SCL_FILTERED, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[0].tr_i2c_scl_filtered
    CYHAL_TRIGGER_SCB1_TR_I2C_SCL_FILTERED = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB1_TR_I2C_SCL_FILTERED, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[1].tr_i2c_scl_filtered
    CYHAL_TRIGGER_SCB2_TR_I2C_SCL_FILTERED = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB2_TR_I2C_SCL_FILTERED, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[2].tr_i2c_scl_filtered
    CYHAL_TRIGGER_SCB3_TR_I2C_SCL_FILTERED = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB3_TR_I2C_SCL_FILTERED, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[3].tr_i2c_scl_filtered
    CYHAL_TRIGGER_SCB4_TR_I2C_SCL_FILTERED = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB4_TR_I2C_SCL_FILTERED, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[4].tr_i2c_scl_filtered
    CYHAL_TRIGGER_SCB5_TR_I2C_SCL_FILTERED = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB5_TR_I2C_SCL_FILTERED, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[5].tr_i2c_scl_filtered
    CYHAL_TRIGGER_SCB6_TR_I2C_SCL_FILTERED = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB6_TR_I2C_SCL_FILTERED, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[6].tr_i2c_scl_filtered
    CYHAL_TRIGGER_SCB7_TR_I2C_SCL_FILTERED = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB7_TR_I2C_SCL_FILTERED, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[7].tr_i2c_scl_filtered
    CYHAL_TRIGGER_SCB0_TR_RX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB0_TR_RX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[0].tr_rx_req
    CYHAL_TRIGGER_SCB1_TR_RX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB1_TR_RX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[1].tr_rx_req
    CYHAL_TRIGGER_SCB2_TR_RX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB2_TR_RX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[2].tr_rx_req
    CYHAL_TRIGGER_SCB3_TR_RX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB3_TR_RX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[3].tr_rx_req
    CYHAL_TRIGGER_SCB4_TR_RX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB4_TR_RX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[4].tr_rx_req
    CYHAL_TRIGGER_SCB5_TR_RX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB5_TR_RX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[5].tr_rx_req
    CYHAL_TRIGGER_SCB6_TR_RX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB6_TR_RX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[6].tr_rx_req
    CYHAL_TRIGGER_SCB7_TR_RX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB7_TR_RX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[7].tr_rx_req
    CYHAL_TRIGGER_SCB0_TR_TX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB0_TR_TX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[0].tr_tx_req
    CYHAL_TRIGGER_SCB1_TR_TX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB1_TR_TX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[1].tr_tx_req
    CYHAL_TRIGGER_SCB2_TR_TX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB2_TR_TX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[2].tr_tx_req
    CYHAL_TRIGGER_SCB3_TR_TX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB3_TR_TX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[3].tr_tx_req
    CYHAL_TRIGGER_SCB4_TR_TX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB4_TR_TX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[4].tr_tx_req
    CYHAL_TRIGGER_SCB5_TR_TX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB5_TR_TX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[5].tr_tx_req
    CYHAL_TRIGGER_SCB6_TR_TX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB6_TR_TX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[6].tr_tx_req
    CYHAL_TRIGGER_SCB7_TR_TX_REQ = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_SCB7_TR_TX_REQ, CYHAL_SIGNAL_TYPE_LEVEL), //!< scb[7].tr_tx_req
    CYHAL_TRIGGER_TCPWM0_TR_OUT00_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT00, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[0]
    CYHAL_TRIGGER_TCPWM0_TR_OUT00_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT00, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[0]
    CYHAL_TRIGGER_TCPWM0_TR_OUT01_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT01, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[1]
    CYHAL_TRIGGER_TCPWM0_TR_OUT01_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT01, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[1]
    CYHAL_TRIGGER_TCPWM0_TR_OUT02_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT02, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[2]
    CYHAL_TRIGGER_TCPWM0_TR_OUT02_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT02, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[2]
    CYHAL_TRIGGER_TCPWM0_TR_OUT03_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT03, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[3]
    CYHAL_TRIGGER_TCPWM0_TR_OUT03_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT03, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[3]
    CYHAL_TRIGGER_TCPWM0_TR_OUT04_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT04, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[4]
    CYHAL_TRIGGER_TCPWM0_TR_OUT04_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT04, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[4]
    CYHAL_TRIGGER_TCPWM0_TR_OUT05_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT05, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[5]
    CYHAL_TRIGGER_TCPWM0_TR_OUT05_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT05, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[5]
    CYHAL_TRIGGER_TCPWM0_TR_OUT06_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT06, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[6]
    CYHAL_TRIGGER_TCPWM0_TR_OUT06_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT06, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[6]
    CYHAL_TRIGGER_TCPWM0_TR_OUT07_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT07, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[7]
    CYHAL_TRIGGER_TCPWM0_TR_OUT07_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT07, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[7]
    CYHAL_TRIGGER_TCPWM0_TR_OUT08_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT08, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[8]
    CYHAL_TRIGGER_TCPWM0_TR_OUT08_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT08, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[8]
    CYHAL_TRIGGER_TCPWM0_TR_OUT09_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT09, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[9]
    CYHAL_TRIGGER_TCPWM0_TR_OUT09_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT09, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[9]
    CYHAL_TRIGGER_TCPWM0_TR_OUT010_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT010, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[10]
    CYHAL_TRIGGER_TCPWM0_TR_OUT010_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT010, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[10]
    CYHAL_TRIGGER_TCPWM0_TR_OUT011_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT011, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[11]
    CYHAL_TRIGGER_TCPWM0_TR_OUT011_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT011, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[11]
    CYHAL_TRIGGER_TCPWM0_TR_OUT012_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT012, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[12]
    CYHAL_TRIGGER_TCPWM0_TR_OUT012_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT012, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[12]
    CYHAL_TRIGGER_TCPWM0_TR_OUT013_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT013, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[13]
    CYHAL_TRIGGER_TCPWM0_TR_OUT013_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT013, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[13]
    CYHAL_TRIGGER_TCPWM0_TR_OUT014_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT014, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[14]
    CYHAL_TRIGGER_TCPWM0_TR_OUT014_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT014, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[14]
    CYHAL_TRIGGER_TCPWM0_TR_OUT015_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT015, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[15]
    CYHAL_TRIGGER_TCPWM0_TR_OUT015_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT015, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[15]
    CYHAL_TRIGGER_TCPWM0_TR_OUT016_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT016, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[16]
    CYHAL_TRIGGER_TCPWM0_TR_OUT016_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT016, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[16]
    CYHAL_TRIGGER_TCPWM0_TR_OUT017_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT017, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[17]
    CYHAL_TRIGGER_TCPWM0_TR_OUT017_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT017, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[17]
    CYHAL_TRIGGER_TCPWM0_TR_OUT018_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT018, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[18]
    CYHAL_TRIGGER_TCPWM0_TR_OUT018_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT018, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[18]
    CYHAL_TRIGGER_TCPWM0_TR_OUT019_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT019, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[19]
    CYHAL_TRIGGER_TCPWM0_TR_OUT019_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT019, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[19]
    CYHAL_TRIGGER_TCPWM0_TR_OUT020_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT020, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[20]
    CYHAL_TRIGGER_TCPWM0_TR_OUT020_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT020, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[20]
    CYHAL_TRIGGER_TCPWM0_TR_OUT021_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT021, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[21]
    CYHAL_TRIGGER_TCPWM0_TR_OUT021_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT021, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[21]
    CYHAL_TRIGGER_TCPWM0_TR_OUT022_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT022, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[22]
    CYHAL_TRIGGER_TCPWM0_TR_OUT022_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT022, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[22]
    CYHAL_TRIGGER_TCPWM0_TR_OUT023_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT023, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[23]
    CYHAL_TRIGGER_TCPWM0_TR_OUT023_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT023, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[23]
    CYHAL_TRIGGER_TCPWM0_TR_OUT024_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT024, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[24]
    CYHAL_TRIGGER_TCPWM0_TR_OUT024_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT024, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[24]
    CYHAL_TRIGGER_TCPWM0_TR_OUT025_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT025, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[25]
    CYHAL_TRIGGER_TCPWM0_TR_OUT025_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT025, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[25]
    CYHAL_TRIGGER_TCPWM0_TR_OUT026_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT026, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[26]
    CYHAL_TRIGGER_TCPWM0_TR_OUT026_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT026, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[26]
    CYHAL_TRIGGER_TCPWM0_TR_OUT027_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT027, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[27]
    CYHAL_TRIGGER_TCPWM0_TR_OUT027_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT027, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[27]
    CYHAL_TRIGGER_TCPWM0_TR_OUT028_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT028, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[28]
    CYHAL_TRIGGER_TCPWM0_TR_OUT028_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT028, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[28]
    CYHAL_TRIGGER_TCPWM0_TR_OUT029_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT029, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[29]
    CYHAL_TRIGGER_TCPWM0_TR_OUT029_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT029, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[29]
    CYHAL_TRIGGER_TCPWM0_TR_OUT030_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT030, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[30]
    CYHAL_TRIGGER_TCPWM0_TR_OUT030_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT030, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[30]
    CYHAL_TRIGGER_TCPWM0_TR_OUT031_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT031, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[31]
    CYHAL_TRIGGER_TCPWM0_TR_OUT031_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT031, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[31]
    CYHAL_TRIGGER_TCPWM0_TR_OUT032_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT032, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[32]
    CYHAL_TRIGGER_TCPWM0_TR_OUT032_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT032, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[32]
    CYHAL_TRIGGER_TCPWM0_TR_OUT033_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT033, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[33]
    CYHAL_TRIGGER_TCPWM0_TR_OUT033_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT033, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[33]
    CYHAL_TRIGGER_TCPWM0_TR_OUT034_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT034, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[34]
    CYHAL_TRIGGER_TCPWM0_TR_OUT034_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT034, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[34]
    CYHAL_TRIGGER_TCPWM0_TR_OUT035_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT035, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[35]
    CYHAL_TRIGGER_TCPWM0_TR_OUT035_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT035, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[35]
    CYHAL_TRIGGER_TCPWM0_TR_OUT036_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT036, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[36]
    CYHAL_TRIGGER_TCPWM0_TR_OUT036_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT036, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[36]
    CYHAL_TRIGGER_TCPWM0_TR_OUT037_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT037, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[37]
    CYHAL_TRIGGER_TCPWM0_TR_OUT037_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT037, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[37]
    CYHAL_TRIGGER_TCPWM0_TR_OUT038_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT038, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[38]
    CYHAL_TRIGGER_TCPWM0_TR_OUT038_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT038, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[38]
    CYHAL_TRIGGER_TCPWM0_TR_OUT039_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT039, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[39]
    CYHAL_TRIGGER_TCPWM0_TR_OUT039_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT039, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[39]
    CYHAL_TRIGGER_TCPWM0_TR_OUT040_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT040, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[40]
    CYHAL_TRIGGER_TCPWM0_TR_OUT040_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT040, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[40]
    CYHAL_TRIGGER_TCPWM0_TR_OUT041_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT041, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[41]
    CYHAL_TRIGGER_TCPWM0_TR_OUT041_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT041, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[41]
    CYHAL_TRIGGER_TCPWM0_TR_OUT042_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT042, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[42]
    CYHAL_TRIGGER_TCPWM0_TR_OUT042_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT042, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[42]
    CYHAL_TRIGGER_TCPWM0_TR_OUT043_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT043, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[43]
    CYHAL_TRIGGER_TCPWM0_TR_OUT043_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT043, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[43]
    CYHAL_TRIGGER_TCPWM0_TR_OUT044_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT044, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[44]
    CYHAL_TRIGGER_TCPWM0_TR_OUT044_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT044, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[44]
    CYHAL_TRIGGER_TCPWM0_TR_OUT045_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT045, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[45]
    CYHAL_TRIGGER_TCPWM0_TR_OUT045_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT045, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[45]
    CYHAL_TRIGGER_TCPWM0_TR_OUT046_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT046, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[46]
    CYHAL_TRIGGER_TCPWM0_TR_OUT046_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT046, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[46]
    CYHAL_TRIGGER_TCPWM0_TR_OUT047_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT047, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[47]
    CYHAL_TRIGGER_TCPWM0_TR_OUT047_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT047, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[47]
    CYHAL_TRIGGER_TCPWM0_TR_OUT048_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT048, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[48]
    CYHAL_TRIGGER_TCPWM0_TR_OUT048_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT048, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[48]
    CYHAL_TRIGGER_TCPWM0_TR_OUT049_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT049, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[49]
    CYHAL_TRIGGER_TCPWM0_TR_OUT049_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT049, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[49]
    CYHAL_TRIGGER_TCPWM0_TR_OUT050_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT050, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[50]
    CYHAL_TRIGGER_TCPWM0_TR_OUT050_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT050, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[50]
    CYHAL_TRIGGER_TCPWM0_TR_OUT051_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT051, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[51]
    CYHAL_TRIGGER_TCPWM0_TR_OUT051_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT051, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[51]
    CYHAL_TRIGGER_TCPWM0_TR_OUT052_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT052, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[52]
    CYHAL_TRIGGER_TCPWM0_TR_OUT052_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT052, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[52]
    CYHAL_TRIGGER_TCPWM0_TR_OUT053_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT053, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[53]
    CYHAL_TRIGGER_TCPWM0_TR_OUT053_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT053, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[53]
    CYHAL_TRIGGER_TCPWM0_TR_OUT054_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT054, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[54]
    CYHAL_TRIGGER_TCPWM0_TR_OUT054_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT054, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[54]
    CYHAL_TRIGGER_TCPWM0_TR_OUT055_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT055, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[55]
    CYHAL_TRIGGER_TCPWM0_TR_OUT055_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT055, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[55]
    CYHAL_TRIGGER_TCPWM0_TR_OUT056_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT056, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[56]
    CYHAL_TRIGGER_TCPWM0_TR_OUT056_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT056, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[56]
    CYHAL_TRIGGER_TCPWM0_TR_OUT057_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT057, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[57]
    CYHAL_TRIGGER_TCPWM0_TR_OUT057_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT057, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[57]
    CYHAL_TRIGGER_TCPWM0_TR_OUT058_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT058, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[58]
    CYHAL_TRIGGER_TCPWM0_TR_OUT058_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT058, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[58]
    CYHAL_TRIGGER_TCPWM0_TR_OUT059_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT059, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[59]
    CYHAL_TRIGGER_TCPWM0_TR_OUT059_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT059, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[59]
    CYHAL_TRIGGER_TCPWM0_TR_OUT060_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT060, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[60]
    CYHAL_TRIGGER_TCPWM0_TR_OUT060_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT060, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[60]
    CYHAL_TRIGGER_TCPWM0_TR_OUT061_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT061, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[61]
    CYHAL_TRIGGER_TCPWM0_TR_OUT061_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT061, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[61]
    CYHAL_TRIGGER_TCPWM0_TR_OUT062_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT062, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[62]
    CYHAL_TRIGGER_TCPWM0_TR_OUT062_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT062, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[62]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0256_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0256, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[256]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0256_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0256, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[256]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0257_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0257, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[257]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0257_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0257, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[257]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0258_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0258, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[258]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0258_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0258, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[258]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0259_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0259, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[259]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0259_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0259, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[259]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0260_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0260, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[260]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0260_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0260, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[260]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0261_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0261, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[261]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0261_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0261, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[261]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0262_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0262, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[262]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0262_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0262, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[262]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0263_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0263, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[263]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0263_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0263, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[263]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0264_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0264, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[264]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0264_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0264, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[264]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0265_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0265, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[265]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0265_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0265, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[265]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0266_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0266, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[266]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0266_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0266, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[266]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0267_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0267, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[267]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0267_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0267, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[267]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0512_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0512, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[512]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0512_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0512, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[512]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0513_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0513, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[513]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0513_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0513, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[513]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0514_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0514, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[514]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0514_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0514, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[514]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0515_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0515, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[515]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0515_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0515, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[515]
    CYHAL_TRIGGER_TCPWM0_TR_OUT10_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT10, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[0]
    CYHAL_TRIGGER_TCPWM0_TR_OUT10_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT10, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[0]
    CYHAL_TRIGGER_TCPWM0_TR_OUT11_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT11, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[1]
    CYHAL_TRIGGER_TCPWM0_TR_OUT11_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT11, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[1]
    CYHAL_TRIGGER_TCPWM0_TR_OUT12_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT12, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[2]
    CYHAL_TRIGGER_TCPWM0_TR_OUT12_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT12, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[2]
    CYHAL_TRIGGER_TCPWM0_TR_OUT13_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT13, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[3]
    CYHAL_TRIGGER_TCPWM0_TR_OUT13_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT13, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[3]
    CYHAL_TRIGGER_TCPWM0_TR_OUT14_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT14, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[4]
    CYHAL_TRIGGER_TCPWM0_TR_OUT14_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT14, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[4]
    CYHAL_TRIGGER_TCPWM0_TR_OUT15_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT15, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[5]
    CYHAL_TRIGGER_TCPWM0_TR_OUT15_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT15, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[5]
    CYHAL_TRIGGER_TCPWM0_TR_OUT16_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT16, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[6]
    CYHAL_TRIGGER_TCPWM0_TR_OUT16_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT16, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[6]
    CYHAL_TRIGGER_TCPWM0_TR_OUT17_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT17, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[7]
    CYHAL_TRIGGER_TCPWM0_TR_OUT17_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT17, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[7]
    CYHAL_TRIGGER_TCPWM0_TR_OUT18_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT18, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[8]
    CYHAL_TRIGGER_TCPWM0_TR_OUT18_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT18, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[8]
    CYHAL_TRIGGER_TCPWM0_TR_OUT19_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT19, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[9]
    CYHAL_TRIGGER_TCPWM0_TR_OUT19_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT19, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[9]
    CYHAL_TRIGGER_TCPWM0_TR_OUT110_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT110, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[10]
    CYHAL_TRIGGER_TCPWM0_TR_OUT110_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT110, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[10]
    CYHAL_TRIGGER_TCPWM0_TR_OUT111_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT111, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[11]
    CYHAL_TRIGGER_TCPWM0_TR_OUT111_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT111, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[11]
    CYHAL_TRIGGER_TCPWM0_TR_OUT112_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT112, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[12]
    CYHAL_TRIGGER_TCPWM0_TR_OUT112_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT112, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[12]
    CYHAL_TRIGGER_TCPWM0_TR_OUT113_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT113, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[13]
    CYHAL_TRIGGER_TCPWM0_TR_OUT113_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT113, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[13]
    CYHAL_TRIGGER_TCPWM0_TR_OUT114_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT114, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[14]
    CYHAL_TRIGGER_TCPWM0_TR_OUT114_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT114, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[14]
    CYHAL_TRIGGER_TCPWM0_TR_OUT115_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT115, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[15]
    CYHAL_TRIGGER_TCPWM0_TR_OUT115_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT115, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[15]
    CYHAL_TRIGGER_TCPWM0_TR_OUT116_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT116, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[16]
    CYHAL_TRIGGER_TCPWM0_TR_OUT116_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT116, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[16]
    CYHAL_TRIGGER_TCPWM0_TR_OUT117_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT117, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[17]
    CYHAL_TRIGGER_TCPWM0_TR_OUT117_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT117, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[17]
    CYHAL_TRIGGER_TCPWM0_TR_OUT118_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT118, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[18]
    CYHAL_TRIGGER_TCPWM0_TR_OUT118_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT118, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[18]
    CYHAL_TRIGGER_TCPWM0_TR_OUT119_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT119, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[19]
    CYHAL_TRIGGER_TCPWM0_TR_OUT119_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT119, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[19]
    CYHAL_TRIGGER_TCPWM0_TR_OUT120_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT120, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[20]
    CYHAL_TRIGGER_TCPWM0_TR_OUT120_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT120, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[20]
    CYHAL_TRIGGER_TCPWM0_TR_OUT121_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT121, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[21]
    CYHAL_TRIGGER_TCPWM0_TR_OUT121_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT121, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[21]
    CYHAL_TRIGGER_TCPWM0_TR_OUT122_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT122, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[22]
    CYHAL_TRIGGER_TCPWM0_TR_OUT122_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT122, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[22]
    CYHAL_TRIGGER_TCPWM0_TR_OUT123_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT123, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[23]
    CYHAL_TRIGGER_TCPWM0_TR_OUT123_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT123, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[23]
    CYHAL_TRIGGER_TCPWM0_TR_OUT124_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT124, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[24]
    CYHAL_TRIGGER_TCPWM0_TR_OUT124_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT124, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[24]
    CYHAL_TRIGGER_TCPWM0_TR_OUT125_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT125, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[25]
    CYHAL_TRIGGER_TCPWM0_TR_OUT125_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT125, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[25]
    CYHAL_TRIGGER_TCPWM0_TR_OUT126_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT126, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[26]
    CYHAL_TRIGGER_TCPWM0_TR_OUT126_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT126, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[26]
    CYHAL_TRIGGER_TCPWM0_TR_OUT127_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT127, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[27]
    CYHAL_TRIGGER_TCPWM0_TR_OUT127_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT127, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[27]
    CYHAL_TRIGGER_TCPWM0_TR_OUT128_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT128, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[28]
    CYHAL_TRIGGER_TCPWM0_TR_OUT128_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT128, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[28]
    CYHAL_TRIGGER_TCPWM0_TR_OUT129_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT129, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[29]
    CYHAL_TRIGGER_TCPWM0_TR_OUT129_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT129, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[29]
    CYHAL_TRIGGER_TCPWM0_TR_OUT130_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT130, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[30]
    CYHAL_TRIGGER_TCPWM0_TR_OUT130_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT130, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[30]
    CYHAL_TRIGGER_TCPWM0_TR_OUT131_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT131, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[31]
    CYHAL_TRIGGER_TCPWM0_TR_OUT131_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT131, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[31]
    CYHAL_TRIGGER_TCPWM0_TR_OUT132_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT132, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[32]
    CYHAL_TRIGGER_TCPWM0_TR_OUT132_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT132, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[32]
    CYHAL_TRIGGER_TCPWM0_TR_OUT133_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT133, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[33]
    CYHAL_TRIGGER_TCPWM0_TR_OUT133_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT133, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[33]
    CYHAL_TRIGGER_TCPWM0_TR_OUT134_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT134, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[34]
    CYHAL_TRIGGER_TCPWM0_TR_OUT134_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT134, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[34]
    CYHAL_TRIGGER_TCPWM0_TR_OUT135_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT135, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[35]
    CYHAL_TRIGGER_TCPWM0_TR_OUT135_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT135, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[35]
    CYHAL_TRIGGER_TCPWM0_TR_OUT136_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT136, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[36]
    CYHAL_TRIGGER_TCPWM0_TR_OUT136_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT136, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[36]
    CYHAL_TRIGGER_TCPWM0_TR_OUT137_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT137, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[37]
    CYHAL_TRIGGER_TCPWM0_TR_OUT137_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT137, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[37]
    CYHAL_TRIGGER_TCPWM0_TR_OUT138_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT138, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[38]
    CYHAL_TRIGGER_TCPWM0_TR_OUT138_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT138, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[38]
    CYHAL_TRIGGER_TCPWM0_TR_OUT139_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT139, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[39]
    CYHAL_TRIGGER_TCPWM0_TR_OUT139_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT139, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[39]
    CYHAL_TRIGGER_TCPWM0_TR_OUT140_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT140, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[40]
    CYHAL_TRIGGER_TCPWM0_TR_OUT140_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT140, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[40]
    CYHAL_TRIGGER_TCPWM0_TR_OUT141_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT141, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[41]
    CYHAL_TRIGGER_TCPWM0_TR_OUT141_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT141, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[41]
    CYHAL_TRIGGER_TCPWM0_TR_OUT142_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT142, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[42]
    CYHAL_TRIGGER_TCPWM0_TR_OUT142_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT142, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[42]
    CYHAL_TRIGGER_TCPWM0_TR_OUT143_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT143, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[43]
    CYHAL_TRIGGER_TCPWM0_TR_OUT143_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT143, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[43]
    CYHAL_TRIGGER_TCPWM0_TR_OUT144_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT144, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[44]
    CYHAL_TRIGGER_TCPWM0_TR_OUT144_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT144, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[44]
    CYHAL_TRIGGER_TCPWM0_TR_OUT145_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT145, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[45]
    CYHAL_TRIGGER_TCPWM0_TR_OUT145_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT145, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[45]
    CYHAL_TRIGGER_TCPWM0_TR_OUT146_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT146, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[46]
    CYHAL_TRIGGER_TCPWM0_TR_OUT146_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT146, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[46]
    CYHAL_TRIGGER_TCPWM0_TR_OUT147_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT147, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[47]
    CYHAL_TRIGGER_TCPWM0_TR_OUT147_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT147, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[47]
    CYHAL_TRIGGER_TCPWM0_TR_OUT148_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT148, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[48]
    CYHAL_TRIGGER_TCPWM0_TR_OUT148_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT148, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[48]
    CYHAL_TRIGGER_TCPWM0_TR_OUT149_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT149, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[49]
    CYHAL_TRIGGER_TCPWM0_TR_OUT149_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT149, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[49]
    CYHAL_TRIGGER_TCPWM0_TR_OUT150_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT150, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[50]
    CYHAL_TRIGGER_TCPWM0_TR_OUT150_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT150, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[50]
    CYHAL_TRIGGER_TCPWM0_TR_OUT151_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT151, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[51]
    CYHAL_TRIGGER_TCPWM0_TR_OUT151_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT151, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[51]
    CYHAL_TRIGGER_TCPWM0_TR_OUT152_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT152, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[52]
    CYHAL_TRIGGER_TCPWM0_TR_OUT152_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT152, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[52]
    CYHAL_TRIGGER_TCPWM0_TR_OUT153_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT153, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[53]
    CYHAL_TRIGGER_TCPWM0_TR_OUT153_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT153, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[53]
    CYHAL_TRIGGER_TCPWM0_TR_OUT154_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT154, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[54]
    CYHAL_TRIGGER_TCPWM0_TR_OUT154_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT154, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[54]
    CYHAL_TRIGGER_TCPWM0_TR_OUT155_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT155, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[55]
    CYHAL_TRIGGER_TCPWM0_TR_OUT155_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT155, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[55]
    CYHAL_TRIGGER_TCPWM0_TR_OUT156_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT156, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[56]
    CYHAL_TRIGGER_TCPWM0_TR_OUT156_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT156, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[56]
    CYHAL_TRIGGER_TCPWM0_TR_OUT157_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT157, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[57]
    CYHAL_TRIGGER_TCPWM0_TR_OUT157_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT157, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[57]
    CYHAL_TRIGGER_TCPWM0_TR_OUT158_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT158, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[58]
    CYHAL_TRIGGER_TCPWM0_TR_OUT158_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT158, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[58]
    CYHAL_TRIGGER_TCPWM0_TR_OUT159_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT159, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[59]
    CYHAL_TRIGGER_TCPWM0_TR_OUT159_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT159, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[59]
    CYHAL_TRIGGER_TCPWM0_TR_OUT160_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT160, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[60]
    CYHAL_TRIGGER_TCPWM0_TR_OUT160_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT160, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[60]
    CYHAL_TRIGGER_TCPWM0_TR_OUT161_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT161, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[61]
    CYHAL_TRIGGER_TCPWM0_TR_OUT161_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT161, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[61]
    CYHAL_TRIGGER_TCPWM0_TR_OUT162_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT162, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[62]
    CYHAL_TRIGGER_TCPWM0_TR_OUT162_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT162, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[62]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1256_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1256, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[256]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1256_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1256, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[256]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1257_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1257, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[257]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1257_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1257, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[257]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1258_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1258, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[258]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1258_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1258, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[258]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1259_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1259, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[259]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1259_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1259, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[259]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1260_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1260, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[260]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1260_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1260, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[260]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1261_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1261, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[261]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1261_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1261, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[261]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1262_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1262, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[262]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1262_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1262, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[262]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1263_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1263, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[263]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1263_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1263, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[263]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1264_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1264, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[264]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1264_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1264, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[264]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1265_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1265, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[265]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1265_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1265, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[265]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1266_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1266, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[266]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1266_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1266, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[266]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1267_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1267, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[267]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1267_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1267, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[267]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1512_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1512, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[512]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1512_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1512, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[512]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1513_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1513, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[513]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1513_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1513, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[513]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1514_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1514, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[514]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1514_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1514, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[514]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1515_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1515, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[515]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1515_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1515, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[515]
    CYHAL_TRIGGER_TR_GROUP9_OUTPUT0_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP9_OUTPUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< tr_group[9].output[0]
    CYHAL_TRIGGER_TR_GROUP9_OUTPUT0_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP9_OUTPUT0, CYHAL_SIGNAL_TYPE_LEVEL), //!< tr_group[9].output[0]
    CYHAL_TRIGGER_TR_GROUP9_OUTPUT1_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP9_OUTPUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< tr_group[9].output[1]
    CYHAL_TRIGGER_TR_GROUP9_OUTPUT1_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP9_OUTPUT1, CYHAL_SIGNAL_TYPE_LEVEL), //!< tr_group[9].output[1]
    CYHAL_TRIGGER_TR_GROUP9_OUTPUT2_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP9_OUTPUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< tr_group[9].output[2]
    CYHAL_TRIGGER_TR_GROUP9_OUTPUT2_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP9_OUTPUT2, CYHAL_SIGNAL_TYPE_LEVEL), //!< tr_group[9].output[2]
    CYHAL_TRIGGER_TR_GROUP9_OUTPUT3_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP9_OUTPUT3, CYHAL_SIGNAL_TYPE_EDGE), //!< tr_group[9].output[3]
    CYHAL_TRIGGER_TR_GROUP9_OUTPUT3_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP9_OUTPUT3, CYHAL_SIGNAL_TYPE_LEVEL), //!< tr_group[9].output[3]
    CYHAL_TRIGGER_TR_GROUP9_OUTPUT4_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP9_OUTPUT4, CYHAL_SIGNAL_TYPE_EDGE), //!< tr_group[9].output[4]
    CYHAL_TRIGGER_TR_GROUP9_OUTPUT4_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP9_OUTPUT4, CYHAL_SIGNAL_TYPE_LEVEL), //!< tr_group[9].output[4]
    CYHAL_TRIGGER_TR_GROUP10_OUTPUT0_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP10_OUTPUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< tr_group[10].output[0]
    CYHAL_TRIGGER_TR_GROUP10_OUTPUT0_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP10_OUTPUT0, CYHAL_SIGNAL_TYPE_LEVEL), //!< tr_group[10].output[0]
    CYHAL_TRIGGER_TR_GROUP10_OUTPUT1_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP10_OUTPUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< tr_group[10].output[1]
    CYHAL_TRIGGER_TR_GROUP10_OUTPUT1_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP10_OUTPUT1, CYHAL_SIGNAL_TYPE_LEVEL), //!< tr_group[10].output[1]
    CYHAL_TRIGGER_TR_GROUP10_OUTPUT2_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP10_OUTPUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< tr_group[10].output[2]
    CYHAL_TRIGGER_TR_GROUP10_OUTPUT2_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP10_OUTPUT2, CYHAL_SIGNAL_TYPE_LEVEL), //!< tr_group[10].output[2]
    CYHAL_TRIGGER_TR_GROUP10_OUTPUT3_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP10_OUTPUT3, CYHAL_SIGNAL_TYPE_EDGE), //!< tr_group[10].output[3]
    CYHAL_TRIGGER_TR_GROUP10_OUTPUT3_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP10_OUTPUT3, CYHAL_SIGNAL_TYPE_LEVEL), //!< tr_group[10].output[3]
    CYHAL_TRIGGER_TR_GROUP10_OUTPUT4_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP10_OUTPUT4, CYHAL_SIGNAL_TYPE_EDGE), //!< tr_group[10].output[4]
    CYHAL_TRIGGER_TR_GROUP10_OUTPUT4_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TR_GROUP10_OUTPUT4, CYHAL_SIGNAL_TYPE_LEVEL), //!< tr_group[10].output[4]
} cyhal_trigger_source_tviibe1m_t;

/** Typedef from device family specific trigger source to generic trigger source */
typedef cyhal_trigger_source_tviibe1m_t cyhal_source_t;

/** Deprecated defines for signals that can be either level or edge. */
#define CYHAL_TRIGGER_CPUSS_ZERO (CYHAL_TRIGGER_CPUSS_ZERO_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_EVTGEN0_TR_OUT0 (CYHAL_TRIGGER_EVTGEN0_TR_OUT0_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_EVTGEN0_TR_OUT1 (CYHAL_TRIGGER_EVTGEN0_TR_OUT1_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_EVTGEN0_TR_OUT2 (CYHAL_TRIGGER_EVTGEN0_TR_OUT2_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_EVTGEN0_TR_OUT3 (CYHAL_TRIGGER_EVTGEN0_TR_OUT3_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_EVTGEN0_TR_OUT4 (CYHAL_TRIGGER_EVTGEN0_TR_OUT4_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_EVTGEN0_TR_OUT5 (CYHAL_TRIGGER_EVTGEN0_TR_OUT5_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_EVTGEN0_TR_OUT6 (CYHAL_TRIGGER_EVTGEN0_TR_OUT6_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_EVTGEN0_TR_OUT7 (CYHAL_TRIGGER_EVTGEN0_TR_OUT7_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_EVTGEN0_TR_OUT8 (CYHAL_TRIGGER_EVTGEN0_TR_OUT8_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_EVTGEN0_TR_OUT9 (CYHAL_TRIGGER_EVTGEN0_TR_OUT9_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_EVTGEN0_TR_OUT10 (CYHAL_TRIGGER_EVTGEN0_TR_OUT10_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE0 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE0_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE1 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE1_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE2 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE2_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE3 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE3_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE4 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE4_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE5 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE5_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE6 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE6_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE7 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE7_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE8 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE8_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE9 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE9_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE10 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE10_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE11 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE11_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE12 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE12_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE13 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE13_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE14 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE14_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE15 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE15_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE16 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE16_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE17 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE17_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE18 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE18_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE19 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE19_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE20 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE20_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE21 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE21_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE22 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE22_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE23 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE23_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE32 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE32_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE33 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE33_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE34 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE34_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE35 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE35_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE36 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE36_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE37 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE37_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE38 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE38_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE39 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE39_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE40 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE40_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE41 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE41_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE42 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE42_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE43 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE43_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE44 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE44_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE45 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE45_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE46 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE46_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE47 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE47_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE48 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE48_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE49 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE49_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE50 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE50_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE51 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE51_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE52 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE52_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE53 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE53_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE54 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE54_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE55 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE55_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE56 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE56_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE57 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE57_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE58 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE58_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE59 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE59_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE60 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE60_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE61 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE61_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE62 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE62_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE63 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE63_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE64 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE64_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE65 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE65_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE66 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE66_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE67 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE67_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE68 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE68_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE69 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE69_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE70 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE70_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE71 (CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE71_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT0 (CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT0_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT1 (CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT1_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT2 (CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT2_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT3 (CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT3_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT4 (CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT4_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT5 (CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT5_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT0 (CYHAL_TRIGGER_PERI_TR_IO_INPUT0_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT1 (CYHAL_TRIGGER_PERI_TR_IO_INPUT1_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT2 (CYHAL_TRIGGER_PERI_TR_IO_INPUT2_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT3 (CYHAL_TRIGGER_PERI_TR_IO_INPUT3_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT4 (CYHAL_TRIGGER_PERI_TR_IO_INPUT4_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT5 (CYHAL_TRIGGER_PERI_TR_IO_INPUT5_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT6 (CYHAL_TRIGGER_PERI_TR_IO_INPUT6_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT7 (CYHAL_TRIGGER_PERI_TR_IO_INPUT7_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT8 (CYHAL_TRIGGER_PERI_TR_IO_INPUT8_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT9 (CYHAL_TRIGGER_PERI_TR_IO_INPUT9_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT10 (CYHAL_TRIGGER_PERI_TR_IO_INPUT10_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT11 (CYHAL_TRIGGER_PERI_TR_IO_INPUT11_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT12 (CYHAL_TRIGGER_PERI_TR_IO_INPUT12_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT13 (CYHAL_TRIGGER_PERI_TR_IO_INPUT13_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT14 (CYHAL_TRIGGER_PERI_TR_IO_INPUT14_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT15 (CYHAL_TRIGGER_PERI_TR_IO_INPUT15_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT16 (CYHAL_TRIGGER_PERI_TR_IO_INPUT16_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT17 (CYHAL_TRIGGER_PERI_TR_IO_INPUT17_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT18 (CYHAL_TRIGGER_PERI_TR_IO_INPUT18_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT19 (CYHAL_TRIGGER_PERI_TR_IO_INPUT19_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT20 (CYHAL_TRIGGER_PERI_TR_IO_INPUT20_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT21 (CYHAL_TRIGGER_PERI_TR_IO_INPUT21_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT22 (CYHAL_TRIGGER_PERI_TR_IO_INPUT22_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT23 (CYHAL_TRIGGER_PERI_TR_IO_INPUT23_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT24 (CYHAL_TRIGGER_PERI_TR_IO_INPUT24_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT25 (CYHAL_TRIGGER_PERI_TR_IO_INPUT25_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT26 (CYHAL_TRIGGER_PERI_TR_IO_INPUT26_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT27 (CYHAL_TRIGGER_PERI_TR_IO_INPUT27_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT28 (CYHAL_TRIGGER_PERI_TR_IO_INPUT28_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT29 (CYHAL_TRIGGER_PERI_TR_IO_INPUT29_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT30 (CYHAL_TRIGGER_PERI_TR_IO_INPUT30_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_PERI_TR_IO_INPUT31 (CYHAL_TRIGGER_PERI_TR_IO_INPUT31_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT00 (CYHAL_TRIGGER_TCPWM0_TR_OUT00_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT01 (CYHAL_TRIGGER_TCPWM0_TR_OUT01_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT02 (CYHAL_TRIGGER_TCPWM0_TR_OUT02_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT03 (CYHAL_TRIGGER_TCPWM0_TR_OUT03_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT04 (CYHAL_TRIGGER_TCPWM0_TR_OUT04_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT05 (CYHAL_TRIGGER_TCPWM0_TR_OUT05_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT06 (CYHAL_TRIGGER_TCPWM0_TR_OUT06_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT07 (CYHAL_TRIGGER_TCPWM0_TR_OUT07_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT08 (CYHAL_TRIGGER_TCPWM0_TR_OUT08_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT09 (CYHAL_TRIGGER_TCPWM0_TR_OUT09_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT010 (CYHAL_TRIGGER_TCPWM0_TR_OUT010_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT011 (CYHAL_TRIGGER_TCPWM0_TR_OUT011_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT012 (CYHAL_TRIGGER_TCPWM0_TR_OUT012_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT013 (CYHAL_TRIGGER_TCPWM0_TR_OUT013_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT014 (CYHAL_TRIGGER_TCPWM0_TR_OUT014_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT015 (CYHAL_TRIGGER_TCPWM0_TR_OUT015_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT016 (CYHAL_TRIGGER_TCPWM0_TR_OUT016_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT017 (CYHAL_TRIGGER_TCPWM0_TR_OUT017_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT018 (CYHAL_TRIGGER_TCPWM0_TR_OUT018_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT019 (CYHAL_TRIGGER_TCPWM0_TR_OUT019_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT020 (CYHAL_TRIGGER_TCPWM0_TR_OUT020_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT021 (CYHAL_TRIGGER_TCPWM0_TR_OUT021_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT022 (CYHAL_TRIGGER_TCPWM0_TR_OUT022_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT023 (CYHAL_TRIGGER_TCPWM0_TR_OUT023_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT024 (CYHAL_TRIGGER_TCPWM0_TR_OUT024_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT025 (CYHAL_TRIGGER_TCPWM0_TR_OUT025_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT026 (CYHAL_TRIGGER_TCPWM0_TR_OUT026_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT027 (CYHAL_TRIGGER_TCPWM0_TR_OUT027_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT028 (CYHAL_TRIGGER_TCPWM0_TR_OUT028_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT029 (CYHAL_TRIGGER_TCPWM0_TR_OUT029_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT030 (CYHAL_TRIGGER_TCPWM0_TR_OUT030_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT031 (CYHAL_TRIGGER_TCPWM0_TR_OUT031_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT032 (CYHAL_TRIGGER_TCPWM0_TR_OUT032_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT033 (CYHAL_TRIGGER_TCPWM0_TR_OUT033_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT034 (CYHAL_TRIGGER_TCPWM0_TR_OUT034_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT035 (CYHAL_TRIGGER_TCPWM0_TR_OUT035_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT036 (CYHAL_TRIGGER_TCPWM0_TR_OUT036_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT037 (CYHAL_TRIGGER_TCPWM0_TR_OUT037_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT038 (CYHAL_TRIGGER_TCPWM0_TR_OUT038_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT039 (CYHAL_TRIGGER_TCPWM0_TR_OUT039_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT040 (CYHAL_TRIGGER_TCPWM0_TR_OUT040_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT041 (CYHAL_TRIGGER_TCPWM0_TR_OUT041_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT042 (CYHAL_TRIGGER_TCPWM0_TR_OUT042_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT043 (CYHAL_TRIGGER_TCPWM0_TR_OUT043_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT044 (CYHAL_TRIGGER_TCPWM0_TR_OUT044_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT045 (CYHAL_TRIGGER_TCPWM0_TR_OUT045_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT046 (CYHAL_TRIGGER_TCPWM0_TR_OUT046_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT047 (CYHAL_TRIGGER_TCPWM0_TR_OUT047_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT048 (CYHAL_TRIGGER_TCPWM0_TR_OUT048_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT049 (CYHAL_TRIGGER_TCPWM0_TR_OUT049_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT050 (CYHAL_TRIGGER_TCPWM0_TR_OUT050_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT051 (CYHAL_TRIGGER_TCPWM0_TR_OUT051_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT052 (CYHAL_TRIGGER_TCPWM0_TR_OUT052_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT053 (CYHAL_TRIGGER_TCPWM0_TR_OUT053_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT054 (CYHAL_TRIGGER_TCPWM0_TR_OUT054_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT055 (CYHAL_TRIGGER_TCPWM0_TR_OUT055_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT056 (CYHAL_TRIGGER_TCPWM0_TR_OUT056_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT057 (CYHAL_TRIGGER_TCPWM0_TR_OUT057_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT058 (CYHAL_TRIGGER_TCPWM0_TR_OUT058_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT059 (CYHAL_TRIGGER_TCPWM0_TR_OUT059_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT060 (CYHAL_TRIGGER_TCPWM0_TR_OUT060_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT061 (CYHAL_TRIGGER_TCPWM0_TR_OUT061_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT062 (CYHAL_TRIGGER_TCPWM0_TR_OUT062_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0256 (CYHAL_TRIGGER_TCPWM0_TR_OUT0256_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0257 (CYHAL_TRIGGER_TCPWM0_TR_OUT0257_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0258 (CYHAL_TRIGGER_TCPWM0_TR_OUT0258_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0259 (CYHAL_TRIGGER_TCPWM0_TR_OUT0259_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0260 (CYHAL_TRIGGER_TCPWM0_TR_OUT0260_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0261 (CYHAL_TRIGGER_TCPWM0_TR_OUT0261_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0262 (CYHAL_TRIGGER_TCPWM0_TR_OUT0262_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0263 (CYHAL_TRIGGER_TCPWM0_TR_OUT0263_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0264 (CYHAL_TRIGGER_TCPWM0_TR_OUT0264_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0265 (CYHAL_TRIGGER_TCPWM0_TR_OUT0265_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0266 (CYHAL_TRIGGER_TCPWM0_TR_OUT0266_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0267 (CYHAL_TRIGGER_TCPWM0_TR_OUT0267_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0512 (CYHAL_TRIGGER_TCPWM0_TR_OUT0512_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0513 (CYHAL_TRIGGER_TCPWM0_TR_OUT0513_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0514 (CYHAL_TRIGGER_TCPWM0_TR_OUT0514_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0515 (CYHAL_TRIGGER_TCPWM0_TR_OUT0515_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT10 (CYHAL_TRIGGER_TCPWM0_TR_OUT10_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT11 (CYHAL_TRIGGER_TCPWM0_TR_OUT11_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT12 (CYHAL_TRIGGER_TCPWM0_TR_OUT12_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT13 (CYHAL_TRIGGER_TCPWM0_TR_OUT13_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT14 (CYHAL_TRIGGER_TCPWM0_TR_OUT14_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT15 (CYHAL_TRIGGER_TCPWM0_TR_OUT15_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT16 (CYHAL_TRIGGER_TCPWM0_TR_OUT16_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT17 (CYHAL_TRIGGER_TCPWM0_TR_OUT17_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT18 (CYHAL_TRIGGER_TCPWM0_TR_OUT18_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT19 (CYHAL_TRIGGER_TCPWM0_TR_OUT19_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT110 (CYHAL_TRIGGER_TCPWM0_TR_OUT110_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT111 (CYHAL_TRIGGER_TCPWM0_TR_OUT111_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT112 (CYHAL_TRIGGER_TCPWM0_TR_OUT112_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT113 (CYHAL_TRIGGER_TCPWM0_TR_OUT113_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT114 (CYHAL_TRIGGER_TCPWM0_TR_OUT114_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT115 (CYHAL_TRIGGER_TCPWM0_TR_OUT115_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT116 (CYHAL_TRIGGER_TCPWM0_TR_OUT116_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT117 (CYHAL_TRIGGER_TCPWM0_TR_OUT117_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT118 (CYHAL_TRIGGER_TCPWM0_TR_OUT118_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT119 (CYHAL_TRIGGER_TCPWM0_TR_OUT119_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT120 (CYHAL_TRIGGER_TCPWM0_TR_OUT120_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT121 (CYHAL_TRIGGER_TCPWM0_TR_OUT121_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT122 (CYHAL_TRIGGER_TCPWM0_TR_OUT122_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT123 (CYHAL_TRIGGER_TCPWM0_TR_OUT123_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT124 (CYHAL_TRIGGER_TCPWM0_TR_OUT124_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT125 (CYHAL_TRIGGER_TCPWM0_TR_OUT125_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT126 (CYHAL_TRIGGER_TCPWM0_TR_OUT126_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT127 (CYHAL_TRIGGER_TCPWM0_TR_OUT127_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT128 (CYHAL_TRIGGER_TCPWM0_TR_OUT128_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT129 (CYHAL_TRIGGER_TCPWM0_TR_OUT129_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT130 (CYHAL_TRIGGER_TCPWM0_TR_OUT130_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT131 (CYHAL_TRIGGER_TCPWM0_TR_OUT131_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT132 (CYHAL_TRIGGER_TCPWM0_TR_OUT132_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT133 (CYHAL_TRIGGER_TCPWM0_TR_OUT133_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT134 (CYHAL_TRIGGER_TCPWM0_TR_OUT134_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT135 (CYHAL_TRIGGER_TCPWM0_TR_OUT135_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT136 (CYHAL_TRIGGER_TCPWM0_TR_OUT136_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT137 (CYHAL_TRIGGER_TCPWM0_TR_OUT137_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT138 (CYHAL_TRIGGER_TCPWM0_TR_OUT138_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT139 (CYHAL_TRIGGER_TCPWM0_TR_OUT139_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT140 (CYHAL_TRIGGER_TCPWM0_TR_OUT140_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT141 (CYHAL_TRIGGER_TCPWM0_TR_OUT141_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT142 (CYHAL_TRIGGER_TCPWM0_TR_OUT142_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT143 (CYHAL_TRIGGER_TCPWM0_TR_OUT143_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT144 (CYHAL_TRIGGER_TCPWM0_TR_OUT144_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT145 (CYHAL_TRIGGER_TCPWM0_TR_OUT145_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT146 (CYHAL_TRIGGER_TCPWM0_TR_OUT146_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT147 (CYHAL_TRIGGER_TCPWM0_TR_OUT147_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT148 (CYHAL_TRIGGER_TCPWM0_TR_OUT148_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT149 (CYHAL_TRIGGER_TCPWM0_TR_OUT149_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT150 (CYHAL_TRIGGER_TCPWM0_TR_OUT150_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT151 (CYHAL_TRIGGER_TCPWM0_TR_OUT151_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT152 (CYHAL_TRIGGER_TCPWM0_TR_OUT152_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT153 (CYHAL_TRIGGER_TCPWM0_TR_OUT153_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT154 (CYHAL_TRIGGER_TCPWM0_TR_OUT154_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT155 (CYHAL_TRIGGER_TCPWM0_TR_OUT155_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT156 (CYHAL_TRIGGER_TCPWM0_TR_OUT156_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT157 (CYHAL_TRIGGER_TCPWM0_TR_OUT157_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT158 (CYHAL_TRIGGER_TCPWM0_TR_OUT158_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT159 (CYHAL_TRIGGER_TCPWM0_TR_OUT159_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT160 (CYHAL_TRIGGER_TCPWM0_TR_OUT160_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT161 (CYHAL_TRIGGER_TCPWM0_TR_OUT161_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT162 (CYHAL_TRIGGER_TCPWM0_TR_OUT162_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1256 (CYHAL_TRIGGER_TCPWM0_TR_OUT1256_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1257 (CYHAL_TRIGGER_TCPWM0_TR_OUT1257_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1258 (CYHAL_TRIGGER_TCPWM0_TR_OUT1258_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1259 (CYHAL_TRIGGER_TCPWM0_TR_OUT1259_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1260 (CYHAL_TRIGGER_TCPWM0_TR_OUT1260_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1261 (CYHAL_TRIGGER_TCPWM0_TR_OUT1261_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1262 (CYHAL_TRIGGER_TCPWM0_TR_OUT1262_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1263 (CYHAL_TRIGGER_TCPWM0_TR_OUT1263_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1264 (CYHAL_TRIGGER_TCPWM0_TR_OUT1264_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1265 (CYHAL_TRIGGER_TCPWM0_TR_OUT1265_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1266 (CYHAL_TRIGGER_TCPWM0_TR_OUT1266_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1267 (CYHAL_TRIGGER_TCPWM0_TR_OUT1267_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1512 (CYHAL_TRIGGER_TCPWM0_TR_OUT1512_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1513 (CYHAL_TRIGGER_TCPWM0_TR_OUT1513_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1514 (CYHAL_TRIGGER_TCPWM0_TR_OUT1514_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1515 (CYHAL_TRIGGER_TCPWM0_TR_OUT1515_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TR_GROUP9_OUTPUT0 (CYHAL_TRIGGER_TR_GROUP9_OUTPUT0_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TR_GROUP9_OUTPUT1 (CYHAL_TRIGGER_TR_GROUP9_OUTPUT1_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TR_GROUP9_OUTPUT2 (CYHAL_TRIGGER_TR_GROUP9_OUTPUT2_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TR_GROUP9_OUTPUT3 (CYHAL_TRIGGER_TR_GROUP9_OUTPUT3_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TR_GROUP9_OUTPUT4 (CYHAL_TRIGGER_TR_GROUP9_OUTPUT4_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TR_GROUP10_OUTPUT0 (CYHAL_TRIGGER_TR_GROUP10_OUTPUT0_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TR_GROUP10_OUTPUT1 (CYHAL_TRIGGER_TR_GROUP10_OUTPUT1_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TR_GROUP10_OUTPUT2 (CYHAL_TRIGGER_TR_GROUP10_OUTPUT2_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TR_GROUP10_OUTPUT3 (CYHAL_TRIGGER_TR_GROUP10_OUTPUT3_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TR_GROUP10_OUTPUT4 (CYHAL_TRIGGER_TR_GROUP10_OUTPUT4_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.

/** @brief Name of each output trigger. */
typedef enum
{
    CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_ACK0 = 0, //!< CAN DW0 triggers (from DW back to CAN) - canfd[0].tr_dbg_dma_ack[0]
    CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_ACK1 = 1, //!< CAN DW0 triggers (from DW back to CAN) - canfd[0].tr_dbg_dma_ack[1]
    CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_ACK2 = 2, //!< CAN DW0 triggers (from DW back to CAN) - canfd[0].tr_dbg_dma_ack[2]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_ACK0 = 3, //!< CAN DW1 triggers (from DW back to CAN) - canfd[1].tr_dbg_dma_ack[0]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_ACK1 = 4, //!< CAN DW1 triggers (from DW back to CAN) - canfd[1].tr_dbg_dma_ack[1]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_ACK2 = 5, //!< CAN DW1 triggers (from DW back to CAN) - canfd[1].tr_dbg_dma_ack[2]
    CYHAL_TRIGGER_CANFD0_TR_EVT_SWT_IN0 = 6, //!< CAN TT Sync - canfd[0].tr_evt_swt_in[0]
    CYHAL_TRIGGER_CANFD0_TR_EVT_SWT_IN1 = 7, //!< CAN TT Sync - canfd[0].tr_evt_swt_in[1]
    CYHAL_TRIGGER_CANFD0_TR_EVT_SWT_IN2 = 8, //!< CAN TT Sync - canfd[0].tr_evt_swt_in[2]
    CYHAL_TRIGGER_CANFD1_TR_EVT_SWT_IN0 = 9, //!< CAN TT Sync - canfd[1].tr_evt_swt_in[0]
    CYHAL_TRIGGER_CANFD1_TR_EVT_SWT_IN1 = 10, //!< CAN TT Sync - canfd[1].tr_evt_swt_in[1]
    CYHAL_TRIGGER_CANFD1_TR_EVT_SWT_IN2 = 11, //!< CAN TT Sync - canfd[1].tr_evt_swt_in[2]
    CYHAL_TRIGGER_CPUSS_CTI_TR_IN0 = 12, //!< Debug Multiplexer - cpuss.cti_tr_in[0]
    CYHAL_TRIGGER_CPUSS_CTI_TR_IN1 = 13, //!< Debug Multiplexer - cpuss.cti_tr_in[1]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_IN0 = 14, //!< M-DMA trigger multiplexer - cpuss.dmac_tr_in[0]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_IN1 = 15, //!< M-DMA trigger multiplexer - cpuss.dmac_tr_in[1]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_IN2 = 16, //!< M-DMA trigger multiplexer - cpuss.dmac_tr_in[2]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_IN3 = 17, //!< M-DMA trigger multiplexer - cpuss.dmac_tr_in[3]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN0 = 18, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[0]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN1 = 19, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[1]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN2 = 20, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[2]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN3 = 21, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[3]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN4 = 22, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[4]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN5 = 23, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[5]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN6 = 24, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[6]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN7 = 25, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[7]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN8 = 26, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[8]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN9 = 27, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[9]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN10 = 28, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[10]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN11 = 29, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[11]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN12 = 30, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[12]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN13 = 31, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[13]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN14 = 32, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[14]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN15 = 33, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[15]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN16 = 34, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[16]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN17 = 35, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[17]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN18 = 36, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[18]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN19 = 37, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[19]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN20 = 38, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[20]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN21 = 39, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[21]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN22 = 40, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[22]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN23 = 41, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[23]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN24 = 42, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[24]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN25 = 43, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[25]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN26 = 44, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[26]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN27 = 45, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[27]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN28 = 46, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[28]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN29 = 47, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[29]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN30 = 48, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[30]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN31 = 49, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[31]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN32 = 50, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[32]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN33 = 51, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[33]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN34 = 52, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[34]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN35 = 53, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[35]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN36 = 54, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[36]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN37 = 55, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[37]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN38 = 56, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[38]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN39 = 57, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[39]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN40 = 58, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[40]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN41 = 59, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[41]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN42 = 60, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[42]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN43 = 61, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[43]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN44 = 62, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[44]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN45 = 63, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[45]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN46 = 64, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[46]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN47 = 65, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[47]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN48 = 66, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[48]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN49 = 67, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[49]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN50 = 68, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[50]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN51 = 69, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[51]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN52 = 70, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[52]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN53 = 71, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[53]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN54 = 72, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[54]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN55 = 73, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[55]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN56 = 74, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[56]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN57 = 75, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[57]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN58 = 76, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[58]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN59 = 77, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[59]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN60 = 78, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[60]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN61 = 79, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[61]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN62 = 80, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[62]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN63 = 81, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[63]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN64 = 82, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[64]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN65 = 83, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[65]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN66 = 84, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[66]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN67 = 85, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[67]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN68 = 86, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[68]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN69 = 87, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[69]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN70 = 88, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[70]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN71 = 89, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[71]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN72 = 90, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[72]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN73 = 91, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[73]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN74 = 92, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[74]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN75 = 93, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[75]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN76 = 94, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[76]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN77 = 95, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[77]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN78 = 96, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[78]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN79 = 97, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[79]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN80 = 98, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[80]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN81 = 99, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[81]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN82 = 100, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[82]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN83 = 101, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[83]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN84 = 102, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[84]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN85 = 103, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[85]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN86 = 104, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[86]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN87 = 105, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[87]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN88 = 106, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[88]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN0 = 107, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[0]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN1 = 108, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[1]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN2 = 109, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[2]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN3 = 110, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[3]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN4 = 111, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[4]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN5 = 112, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[5]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN6 = 113, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[6]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN7 = 114, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[7]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN8 = 115, //!< SCB DW Triggers - cpuss.dw1_tr_in[8]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN9 = 116, //!< SCB DW Triggers - cpuss.dw1_tr_in[9]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN10 = 117, //!< SCB DW Triggers - cpuss.dw1_tr_in[10]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN11 = 118, //!< SCB DW Triggers - cpuss.dw1_tr_in[11]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN12 = 119, //!< SCB DW Triggers - cpuss.dw1_tr_in[12]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN13 = 120, //!< SCB DW Triggers - cpuss.dw1_tr_in[13]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN14 = 121, //!< SCB DW Triggers - cpuss.dw1_tr_in[14]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN15 = 122, //!< SCB DW Triggers - cpuss.dw1_tr_in[15]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN16 = 123, //!< SCB DW Triggers - cpuss.dw1_tr_in[16]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN17 = 124, //!< SCB DW Triggers - cpuss.dw1_tr_in[17]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN18 = 125, //!< SCB DW Triggers - cpuss.dw1_tr_in[18]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN19 = 126, //!< SCB DW Triggers - cpuss.dw1_tr_in[19]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN20 = 127, //!< SCB DW Triggers - cpuss.dw1_tr_in[20]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN21 = 128, //!< SCB DW Triggers - cpuss.dw1_tr_in[21]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN22 = 129, //!< SCB DW Triggers - cpuss.dw1_tr_in[22]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN23 = 130, //!< SCB DW Triggers - cpuss.dw1_tr_in[23]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN24 = 131, //!< CAN DW1 triggers - cpuss.dw1_tr_in[24]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN25 = 132, //!< CAN DW1 triggers - cpuss.dw1_tr_in[25]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN26 = 133, //!< CAN DW1 triggers - cpuss.dw1_tr_in[26]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN27 = 134, //!< CAN DW1 triggers - cpuss.dw1_tr_in[27]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN28 = 135, //!< CAN DW1 triggers - cpuss.dw1_tr_in[28]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN29 = 136, //!< CAN DW1 triggers - cpuss.dw1_tr_in[29]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN30 = 137, //!< CAN DW1 triggers - cpuss.dw1_tr_in[30]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN31 = 138, //!< CAN DW1 triggers - cpuss.dw1_tr_in[31]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN32 = 139, //!< CAN DW1 triggers - cpuss.dw1_tr_in[32]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER0 = 140, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[0]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER1 = 141, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[1]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER2 = 142, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[2]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER3 = 143, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[3]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER4 = 144, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[4]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER5 = 145, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[5]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER6 = 146, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[6]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER7 = 147, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[7]
    CYHAL_TRIGGER_PASS0_TR_DEBUG_FREEZE = 148, //!< Debug Multiplexer - pass[0].tr_debug_freeze
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN0 = 149, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[0]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN1 = 150, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[1]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN2 = 151, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[2]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN3 = 152, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[3]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN4 = 153, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[4]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN5 = 154, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[5]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN6 = 155, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[6]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN7 = 156, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[7]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN8 = 157, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[8]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN9 = 158, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[9]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN10 = 159, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[10]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN11 = 160, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[11]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN12 = 161, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[12]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN13 = 162, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[13]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN14 = 163, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[14]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN15 = 164, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[15]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN16 = 165, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[16]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN17 = 166, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[17]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN18 = 167, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[18]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN19 = 168, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[19]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN20 = 169, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[20]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN21 = 170, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[21]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN22 = 171, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[22]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN23 = 172, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[23]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN32 = 173, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[32]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN33 = 174, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[33]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN34 = 175, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[34]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN35 = 176, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[35]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN36 = 177, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[36]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN37 = 178, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[37]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN38 = 179, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[38]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN39 = 180, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[39]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN40 = 181, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[40]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN41 = 182, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[41]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN42 = 183, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[42]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN43 = 184, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[43]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN44 = 185, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[44]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN45 = 186, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[45]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN46 = 187, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[46]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN47 = 188, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[47]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN48 = 189, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[48]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN49 = 190, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[49]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN50 = 191, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[50]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN51 = 192, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[51]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN52 = 193, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[52]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN53 = 194, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[53]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN54 = 195, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[54]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN55 = 196, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[55]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN56 = 197, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[56]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN57 = 198, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[57]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN58 = 199, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[58]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN59 = 200, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[59]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN60 = 201, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[60]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN61 = 202, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[61]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN62 = 203, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[62]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN63 = 204, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[63]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN64 = 205, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[64]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN65 = 206, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[65]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN66 = 207, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[66]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN67 = 208, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[67]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN68 = 209, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[68]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN69 = 210, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[69]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN70 = 211, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[70]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN71 = 212, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[71]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN0 = 213, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[0]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN1 = 214, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[1]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN2 = 215, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[2]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN3 = 216, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[3]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN4 = 217, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[4]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN5 = 218, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[5]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN6 = 219, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[6]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN7 = 220, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[7]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN8 = 221, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[8]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN9 = 222, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[9]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN10 = 223, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[10]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN11 = 224, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[11]
    CYHAL_TRIGGER_PERI_TR_DBG_FREEZE = 225, //!< Debug Multiplexer - peri.tr_dbg_freeze
    CYHAL_TRIGGER_PERI_TR_IO_OUTPUT0 = 226, //!< Debug Multiplexer - peri.tr_io_output[0]
    CYHAL_TRIGGER_PERI_TR_IO_OUTPUT1 = 227, //!< Debug Multiplexer - peri.tr_io_output[1]
    CYHAL_TRIGGER_SRSS_TR_DEBUG_FREEZE_MCWDT0 = 228, //!< Debug Multiplexer - srss.tr_debug_freeze_mcwdt[0]
    CYHAL_TRIGGER_SRSS_TR_DEBUG_FREEZE_MCWDT1 = 229, //!< Debug Multiplexer - srss.tr_debug_freeze_mcwdt[1]
    CYHAL_TRIGGER_SRSS_TR_DEBUG_FREEZE_WDT = 230, //!< Debug Multiplexer - srss.tr_debug_freeze_wdt
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN0 = 231, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[0]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN1 = 232, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[1]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN2 = 233, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[2]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN3 = 234, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[3]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN4 = 235, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[4]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN5 = 236, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[5]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN6 = 237, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[6]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN7 = 238, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[7]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN8 = 239, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[8]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN9 = 240, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[9]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN10 = 241, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[10]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN11 = 242, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[11]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN12 = 243, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[12]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN13 = 244, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[13]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN14 = 245, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[14]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN15 = 246, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[15]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN16 = 247, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[16]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN17 = 248, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[17]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN18 = 249, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[18]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN19 = 250, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[19]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN20 = 251, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[20]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN21 = 252, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[21]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN22 = 253, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[22]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN23 = 254, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[23]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN24 = 255, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[24]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN25 = 256, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[25]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN26 = 257, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[26]
    CYHAL_TRIGGER_TCPWM0_TR_DEBUG_FREEZE = 258, //!< Debug Multiplexer - tcpwm[0].tr_debug_freeze
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN2 = 259, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[2]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN5 = 260, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[5]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN8 = 261, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[8]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN11 = 262, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[11]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN14 = 263, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[14]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN17 = 264, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[17]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN20 = 265, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[20]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN23 = 266, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[23]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN26 = 267, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[26]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN29 = 268, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[29]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN32 = 269, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[32]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN35 = 270, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[35]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN38 = 271, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[38]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN41 = 272, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[41]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN44 = 273, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[44]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN47 = 274, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[47]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN50 = 275, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[50]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN53 = 276, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[53]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN56 = 277, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[56]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN59 = 278, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[59]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN62 = 279, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[62]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN65 = 280, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[65]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN68 = 281, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[68]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN71 = 282, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[71]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN74 = 283, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[74]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN77 = 284, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[77]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN80 = 285, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[80]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN83 = 286, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[83]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN86 = 287, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[86]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN89 = 288, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[89]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN92 = 289, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[92]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN95 = 290, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[95]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN98 = 291, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[98]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN101 = 292, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[101]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN104 = 293, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[104]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN107 = 294, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[107]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN110 = 295, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[110]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN113 = 296, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[113]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN116 = 297, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[116]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN119 = 298, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[119]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN122 = 299, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[122]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN125 = 300, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[125]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN128 = 301, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[128]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN131 = 302, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[131]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN134 = 303, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[134]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN137 = 304, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[137]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN140 = 305, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[140]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN143 = 306, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[143]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN146 = 307, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[146]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN149 = 308, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[149]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN152 = 309, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[152]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN155 = 310, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[155]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN770 = 311, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[770]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN773 = 312, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[773]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN776 = 313, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[776]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN779 = 314, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[779]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN782 = 315, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[782]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN785 = 316, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[785]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN788 = 317, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[788]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN791 = 318, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[791]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN794 = 319, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[794]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN797 = 320, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[797]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN800 = 321, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[800]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN803 = 322, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[803]
    CYHAL_TRIGGER_TR_GROUP8_INPUT1 = 323, //!< Debug Reduction #1 - tr_group[8].input[1]
    CYHAL_TRIGGER_TR_GROUP8_INPUT2 = 324, //!< Debug Reduction #1 - tr_group[8].input[2]
    CYHAL_TRIGGER_TR_GROUP8_INPUT3 = 325, //!< Debug Reduction #1 - tr_group[8].input[3]
    CYHAL_TRIGGER_TR_GROUP8_INPUT4 = 326, //!< Debug Reduction #1 - tr_group[8].input[4]
    CYHAL_TRIGGER_TR_GROUP8_INPUT5 = 327, //!< Debug Reduction #1 - tr_group[8].input[5]
    CYHAL_TRIGGER_TR_GROUP8_INPUT6 = 328, //!< Debug Reduction #2 - tr_group[8].input[6]
    CYHAL_TRIGGER_TR_GROUP8_INPUT7 = 329, //!< Debug Reduction #2 - tr_group[8].input[7]
    CYHAL_TRIGGER_TR_GROUP8_INPUT8 = 330, //!< Debug Reduction #2 - tr_group[8].input[8]
    CYHAL_TRIGGER_TR_GROUP8_INPUT9 = 331, //!< Debug Reduction #2 - tr_group[8].input[9]
    CYHAL_TRIGGER_TR_GROUP8_INPUT10 = 332, //!< Debug Reduction #2 - tr_group[8].input[10]
} cyhal_trigger_dest_tviibe1m_t;

/** Typedef from device family specific trigger dest to generic trigger dest */
typedef cyhal_trigger_dest_tviibe1m_t cyhal_dest_t;

/** \cond INTERNAL */
/** Table of number of inputs to each mux. */
extern const uint16_t cyhal_sources_per_mux[20];

/** Table indicating whether mux is 1to1. */
extern const bool cyhal_is_mux_1to1[20];

/** Table pointing to each mux source table. The index of each source in the table is its mux input index. */
extern const _cyhal_trigger_source_tviibe1m_t* cyhal_mux_to_sources [20];

/** Maps each cyhal_destination_t to a mux index.
 * If bit 8 of the mux index is set, this denotes that the trigger is a
 * one to one trigger.
 */
extern const uint8_t cyhal_dest_to_mux[333];

/* Maps each cyhal_destination_t to a specific output in its mux */
extern const uint8_t cyhal_mux_dest_index[333];
/** \endcond */

#if defined(__cplusplus)
}
#endif /* __cplusplus */
/** \} group_hal_impl_triggers_tviibe1m */
#endif /* _CYHAL_TRIGGERS_TVIIBE1M_H_ */


/* [] END OF FILE */
