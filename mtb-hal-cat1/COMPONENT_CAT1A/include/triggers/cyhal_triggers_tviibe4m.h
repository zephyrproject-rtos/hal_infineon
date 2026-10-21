/***************************************************************************//**
* \file cyhal_triggers_tviibe4m.h
*
* \brief
* TVIIBE4M family HAL triggers header
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

#ifndef _CYHAL_TRIGGERS_TVIIBE4M_H_
#define _CYHAL_TRIGGERS_TVIIBE4M_H_

/**
 * \addtogroup group_hal_impl_triggers_tviibe4m TVIIBE4M
 * \ingroup group_hal_impl_triggers
 * \{
 * Trigger connections for tviibe4m
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
    _CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ3 = 4, //!< canfd[0].tr_dbg_dma_req[3]
    _CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ0 = 5, //!< canfd[1].tr_dbg_dma_req[0]
    _CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ1 = 6, //!< canfd[1].tr_dbg_dma_req[1]
    _CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ2 = 7, //!< canfd[1].tr_dbg_dma_req[2]
    _CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ3 = 8, //!< canfd[1].tr_dbg_dma_req[3]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO00 = 9, //!< canfd[0].tr_fifo0[0]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO01 = 10, //!< canfd[0].tr_fifo0[1]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO02 = 11, //!< canfd[0].tr_fifo0[2]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO03 = 12, //!< canfd[0].tr_fifo0[3]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO00 = 13, //!< canfd[1].tr_fifo0[0]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO01 = 14, //!< canfd[1].tr_fifo0[1]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO02 = 15, //!< canfd[1].tr_fifo0[2]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO03 = 16, //!< canfd[1].tr_fifo0[3]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO10 = 17, //!< canfd[0].tr_fifo1[0]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO11 = 18, //!< canfd[0].tr_fifo1[1]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO12 = 19, //!< canfd[0].tr_fifo1[2]
    _CYHAL_TRIGGER_CANFD0_TR_FIFO13 = 20, //!< canfd[0].tr_fifo1[3]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO10 = 21, //!< canfd[1].tr_fifo1[0]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO11 = 22, //!< canfd[1].tr_fifo1[1]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO12 = 23, //!< canfd[1].tr_fifo1[2]
    _CYHAL_TRIGGER_CANFD1_TR_FIFO13 = 24, //!< canfd[1].tr_fifo1[3]
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT0 = 25, //!< canfd[0].tr_tmp_rtp_out[0]
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT1 = 26, //!< canfd[0].tr_tmp_rtp_out[1]
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT2 = 27, //!< canfd[0].tr_tmp_rtp_out[2]
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT3 = 28, //!< canfd[0].tr_tmp_rtp_out[3]
    _CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT0 = 29, //!< canfd[1].tr_tmp_rtp_out[0]
    _CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT1 = 30, //!< canfd[1].tr_tmp_rtp_out[1]
    _CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT2 = 31, //!< canfd[1].tr_tmp_rtp_out[2]
    _CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT3 = 32, //!< canfd[1].tr_tmp_rtp_out[3]
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT0 = 33, //!< cpuss.cti_tr_out[0]
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT1 = 34, //!< cpuss.cti_tr_out[1]
    _CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT0 = 35, //!< cpuss.dmac_tr_out[0]
    _CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT1 = 36, //!< cpuss.dmac_tr_out[1]
    _CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT2 = 37, //!< cpuss.dmac_tr_out[2]
    _CYHAL_TRIGGER_CPUSS_DMAC_TR_OUT3 = 38, //!< cpuss.dmac_tr_out[3]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT0 = 39, //!< cpuss.dw0_tr_out[0]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT1 = 40, //!< cpuss.dw0_tr_out[1]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT2 = 41, //!< cpuss.dw0_tr_out[2]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT3 = 42, //!< cpuss.dw0_tr_out[3]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT4 = 43, //!< cpuss.dw0_tr_out[4]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT5 = 44, //!< cpuss.dw0_tr_out[5]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT6 = 45, //!< cpuss.dw0_tr_out[6]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT7 = 46, //!< cpuss.dw0_tr_out[7]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT8 = 47, //!< cpuss.dw0_tr_out[8]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT9 = 48, //!< cpuss.dw0_tr_out[9]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT10 = 49, //!< cpuss.dw0_tr_out[10]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT11 = 50, //!< cpuss.dw0_tr_out[11]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT12 = 51, //!< cpuss.dw0_tr_out[12]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT13 = 52, //!< cpuss.dw0_tr_out[13]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT14 = 53, //!< cpuss.dw0_tr_out[14]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT15 = 54, //!< cpuss.dw0_tr_out[15]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT16 = 55, //!< cpuss.dw0_tr_out[16]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT17 = 56, //!< cpuss.dw0_tr_out[17]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT18 = 57, //!< cpuss.dw0_tr_out[18]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT19 = 58, //!< cpuss.dw0_tr_out[19]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT20 = 59, //!< cpuss.dw0_tr_out[20]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT21 = 60, //!< cpuss.dw0_tr_out[21]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT22 = 61, //!< cpuss.dw0_tr_out[22]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT23 = 62, //!< cpuss.dw0_tr_out[23]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT24 = 63, //!< cpuss.dw0_tr_out[24]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT25 = 64, //!< cpuss.dw0_tr_out[25]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT26 = 65, //!< cpuss.dw0_tr_out[26]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT27 = 66, //!< cpuss.dw0_tr_out[27]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT28 = 67, //!< cpuss.dw0_tr_out[28]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT29 = 68, //!< cpuss.dw0_tr_out[29]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT30 = 69, //!< cpuss.dw0_tr_out[30]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT31 = 70, //!< cpuss.dw0_tr_out[31]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT32 = 71, //!< cpuss.dw0_tr_out[32]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT33 = 72, //!< cpuss.dw0_tr_out[33]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT34 = 73, //!< cpuss.dw0_tr_out[34]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT35 = 74, //!< cpuss.dw0_tr_out[35]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT36 = 75, //!< cpuss.dw0_tr_out[36]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT37 = 76, //!< cpuss.dw0_tr_out[37]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT38 = 77, //!< cpuss.dw0_tr_out[38]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT39 = 78, //!< cpuss.dw0_tr_out[39]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT40 = 79, //!< cpuss.dw0_tr_out[40]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT41 = 80, //!< cpuss.dw0_tr_out[41]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT42 = 81, //!< cpuss.dw0_tr_out[42]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT43 = 82, //!< cpuss.dw0_tr_out[43]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT44 = 83, //!< cpuss.dw0_tr_out[44]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT45 = 84, //!< cpuss.dw0_tr_out[45]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT46 = 85, //!< cpuss.dw0_tr_out[46]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT47 = 86, //!< cpuss.dw0_tr_out[47]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT48 = 87, //!< cpuss.dw0_tr_out[48]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT49 = 88, //!< cpuss.dw0_tr_out[49]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT50 = 89, //!< cpuss.dw0_tr_out[50]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT51 = 90, //!< cpuss.dw0_tr_out[51]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT52 = 91, //!< cpuss.dw0_tr_out[52]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT53 = 92, //!< cpuss.dw0_tr_out[53]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT54 = 93, //!< cpuss.dw0_tr_out[54]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT55 = 94, //!< cpuss.dw0_tr_out[55]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT56 = 95, //!< cpuss.dw0_tr_out[56]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT57 = 96, //!< cpuss.dw0_tr_out[57]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT58 = 97, //!< cpuss.dw0_tr_out[58]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT59 = 98, //!< cpuss.dw0_tr_out[59]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT60 = 99, //!< cpuss.dw0_tr_out[60]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT61 = 100, //!< cpuss.dw0_tr_out[61]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT62 = 101, //!< cpuss.dw0_tr_out[62]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT63 = 102, //!< cpuss.dw0_tr_out[63]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT64 = 103, //!< cpuss.dw0_tr_out[64]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT65 = 104, //!< cpuss.dw0_tr_out[65]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT66 = 105, //!< cpuss.dw0_tr_out[66]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT67 = 106, //!< cpuss.dw0_tr_out[67]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT68 = 107, //!< cpuss.dw0_tr_out[68]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT69 = 108, //!< cpuss.dw0_tr_out[69]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT70 = 109, //!< cpuss.dw0_tr_out[70]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT71 = 110, //!< cpuss.dw0_tr_out[71]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT72 = 111, //!< cpuss.dw0_tr_out[72]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT73 = 112, //!< cpuss.dw0_tr_out[73]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT74 = 113, //!< cpuss.dw0_tr_out[74]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT75 = 114, //!< cpuss.dw0_tr_out[75]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT76 = 115, //!< cpuss.dw0_tr_out[76]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT77 = 116, //!< cpuss.dw0_tr_out[77]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT78 = 117, //!< cpuss.dw0_tr_out[78]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT79 = 118, //!< cpuss.dw0_tr_out[79]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT80 = 119, //!< cpuss.dw0_tr_out[80]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT81 = 120, //!< cpuss.dw0_tr_out[81]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT82 = 121, //!< cpuss.dw0_tr_out[82]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT83 = 122, //!< cpuss.dw0_tr_out[83]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT84 = 123, //!< cpuss.dw0_tr_out[84]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT85 = 124, //!< cpuss.dw0_tr_out[85]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT86 = 125, //!< cpuss.dw0_tr_out[86]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT87 = 126, //!< cpuss.dw0_tr_out[87]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT88 = 127, //!< cpuss.dw0_tr_out[88]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT89 = 128, //!< cpuss.dw0_tr_out[89]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT90 = 129, //!< cpuss.dw0_tr_out[90]
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT91 = 130, //!< cpuss.dw0_tr_out[91]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT0 = 131, //!< cpuss.dw1_tr_out[0]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT1 = 132, //!< cpuss.dw1_tr_out[1]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT2 = 133, //!< cpuss.dw1_tr_out[2]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT3 = 134, //!< cpuss.dw1_tr_out[3]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT4 = 135, //!< cpuss.dw1_tr_out[4]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT5 = 136, //!< cpuss.dw1_tr_out[5]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT6 = 137, //!< cpuss.dw1_tr_out[6]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT7 = 138, //!< cpuss.dw1_tr_out[7]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT8 = 139, //!< cpuss.dw1_tr_out[8]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT9 = 140, //!< cpuss.dw1_tr_out[9]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT10 = 141, //!< cpuss.dw1_tr_out[10]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT11 = 142, //!< cpuss.dw1_tr_out[11]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT12 = 143, //!< cpuss.dw1_tr_out[12]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT13 = 144, //!< cpuss.dw1_tr_out[13]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT14 = 145, //!< cpuss.dw1_tr_out[14]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT15 = 146, //!< cpuss.dw1_tr_out[15]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT16 = 147, //!< cpuss.dw1_tr_out[16]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT17 = 148, //!< cpuss.dw1_tr_out[17]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT18 = 149, //!< cpuss.dw1_tr_out[18]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT19 = 150, //!< cpuss.dw1_tr_out[19]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT20 = 151, //!< cpuss.dw1_tr_out[20]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT21 = 152, //!< cpuss.dw1_tr_out[21]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT22 = 153, //!< cpuss.dw1_tr_out[22]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT23 = 154, //!< cpuss.dw1_tr_out[23]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT24 = 155, //!< cpuss.dw1_tr_out[24]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT25 = 156, //!< cpuss.dw1_tr_out[25]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT26 = 157, //!< cpuss.dw1_tr_out[26]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT27 = 158, //!< cpuss.dw1_tr_out[27]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT28 = 159, //!< cpuss.dw1_tr_out[28]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT29 = 160, //!< cpuss.dw1_tr_out[29]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT30 = 161, //!< cpuss.dw1_tr_out[30]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT31 = 162, //!< cpuss.dw1_tr_out[31]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT32 = 163, //!< cpuss.dw1_tr_out[32]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT33 = 164, //!< cpuss.dw1_tr_out[33]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT34 = 165, //!< cpuss.dw1_tr_out[34]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT35 = 166, //!< cpuss.dw1_tr_out[35]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT36 = 167, //!< cpuss.dw1_tr_out[36]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT37 = 168, //!< cpuss.dw1_tr_out[37]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT38 = 169, //!< cpuss.dw1_tr_out[38]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT39 = 170, //!< cpuss.dw1_tr_out[39]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT40 = 171, //!< cpuss.dw1_tr_out[40]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT41 = 172, //!< cpuss.dw1_tr_out[41]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT42 = 173, //!< cpuss.dw1_tr_out[42]
    _CYHAL_TRIGGER_CPUSS_DW1_TR_OUT43 = 174, //!< cpuss.dw1_tr_out[43]
    _CYHAL_TRIGGER_CPUSS_TR_FAULT0 = 175, //!< cpuss.tr_fault[0]
    _CYHAL_TRIGGER_CPUSS_TR_FAULT1 = 176, //!< cpuss.tr_fault[1]
    _CYHAL_TRIGGER_CPUSS_TR_FAULT2 = 177, //!< cpuss.tr_fault[2]
    _CYHAL_TRIGGER_CPUSS_TR_FAULT3 = 178, //!< cpuss.tr_fault[3]
    _CYHAL_TRIGGER_CXPI0_TR_RX_REQ0 = 179, //!< cxpi[0].tr_rx_req[0]
    _CYHAL_TRIGGER_CXPI0_TR_RX_REQ1 = 180, //!< cxpi[0].tr_rx_req[1]
    _CYHAL_TRIGGER_CXPI0_TR_RX_REQ2 = 181, //!< cxpi[0].tr_rx_req[2]
    _CYHAL_TRIGGER_CXPI0_TR_RX_REQ3 = 182, //!< cxpi[0].tr_rx_req[3]
    _CYHAL_TRIGGER_CXPI0_TR_TX_REQ0 = 183, //!< cxpi[0].tr_tx_req[0]
    _CYHAL_TRIGGER_CXPI0_TR_TX_REQ1 = 184, //!< cxpi[0].tr_tx_req[1]
    _CYHAL_TRIGGER_CXPI0_TR_TX_REQ2 = 185, //!< cxpi[0].tr_tx_req[2]
    _CYHAL_TRIGGER_CXPI0_TR_TX_REQ3 = 186, //!< cxpi[0].tr_tx_req[3]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT0 = 187, //!< evtgen[0].tr_out[0]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT1 = 188, //!< evtgen[0].tr_out[1]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT2 = 189, //!< evtgen[0].tr_out[2]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT3 = 190, //!< evtgen[0].tr_out[3]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT4 = 191, //!< evtgen[0].tr_out[4]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT5 = 192, //!< evtgen[0].tr_out[5]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT6 = 193, //!< evtgen[0].tr_out[6]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT7 = 194, //!< evtgen[0].tr_out[7]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT8 = 195, //!< evtgen[0].tr_out[8]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT9 = 196, //!< evtgen[0].tr_out[9]
    _CYHAL_TRIGGER_EVTGEN0_TR_OUT10 = 197, //!< evtgen[0].tr_out[10]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE0 = 198, //!< pass[0].tr_sar_ch_done[0]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE1 = 199, //!< pass[0].tr_sar_ch_done[1]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE2 = 200, //!< pass[0].tr_sar_ch_done[2]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE3 = 201, //!< pass[0].tr_sar_ch_done[3]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE4 = 202, //!< pass[0].tr_sar_ch_done[4]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE5 = 203, //!< pass[0].tr_sar_ch_done[5]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE6 = 204, //!< pass[0].tr_sar_ch_done[6]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE7 = 205, //!< pass[0].tr_sar_ch_done[7]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE8 = 206, //!< pass[0].tr_sar_ch_done[8]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE9 = 207, //!< pass[0].tr_sar_ch_done[9]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE10 = 208, //!< pass[0].tr_sar_ch_done[10]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE11 = 209, //!< pass[0].tr_sar_ch_done[11]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE12 = 210, //!< pass[0].tr_sar_ch_done[12]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE13 = 211, //!< pass[0].tr_sar_ch_done[13]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE14 = 212, //!< pass[0].tr_sar_ch_done[14]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE15 = 213, //!< pass[0].tr_sar_ch_done[15]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE16 = 214, //!< pass[0].tr_sar_ch_done[16]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE17 = 215, //!< pass[0].tr_sar_ch_done[17]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE18 = 216, //!< pass[0].tr_sar_ch_done[18]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE19 = 217, //!< pass[0].tr_sar_ch_done[19]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE20 = 218, //!< pass[0].tr_sar_ch_done[20]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE21 = 219, //!< pass[0].tr_sar_ch_done[21]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE22 = 220, //!< pass[0].tr_sar_ch_done[22]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE23 = 221, //!< pass[0].tr_sar_ch_done[23]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE32 = 222, //!< pass[0].tr_sar_ch_done[32]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE33 = 223, //!< pass[0].tr_sar_ch_done[33]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE34 = 224, //!< pass[0].tr_sar_ch_done[34]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE35 = 225, //!< pass[0].tr_sar_ch_done[35]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE36 = 226, //!< pass[0].tr_sar_ch_done[36]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE37 = 227, //!< pass[0].tr_sar_ch_done[37]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE38 = 228, //!< pass[0].tr_sar_ch_done[38]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE39 = 229, //!< pass[0].tr_sar_ch_done[39]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE40 = 230, //!< pass[0].tr_sar_ch_done[40]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE41 = 231, //!< pass[0].tr_sar_ch_done[41]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE42 = 232, //!< pass[0].tr_sar_ch_done[42]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE43 = 233, //!< pass[0].tr_sar_ch_done[43]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE44 = 234, //!< pass[0].tr_sar_ch_done[44]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE45 = 235, //!< pass[0].tr_sar_ch_done[45]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE46 = 236, //!< pass[0].tr_sar_ch_done[46]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE47 = 237, //!< pass[0].tr_sar_ch_done[47]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE48 = 238, //!< pass[0].tr_sar_ch_done[48]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE49 = 239, //!< pass[0].tr_sar_ch_done[49]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE50 = 240, //!< pass[0].tr_sar_ch_done[50]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE51 = 241, //!< pass[0].tr_sar_ch_done[51]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE52 = 242, //!< pass[0].tr_sar_ch_done[52]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE53 = 243, //!< pass[0].tr_sar_ch_done[53]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE54 = 244, //!< pass[0].tr_sar_ch_done[54]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE55 = 245, //!< pass[0].tr_sar_ch_done[55]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE56 = 246, //!< pass[0].tr_sar_ch_done[56]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE57 = 247, //!< pass[0].tr_sar_ch_done[57]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE58 = 248, //!< pass[0].tr_sar_ch_done[58]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE59 = 249, //!< pass[0].tr_sar_ch_done[59]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE60 = 250, //!< pass[0].tr_sar_ch_done[60]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE61 = 251, //!< pass[0].tr_sar_ch_done[61]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE62 = 252, //!< pass[0].tr_sar_ch_done[62]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE63 = 253, //!< pass[0].tr_sar_ch_done[63]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE64 = 254, //!< pass[0].tr_sar_ch_done[64]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE65 = 255, //!< pass[0].tr_sar_ch_done[65]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE66 = 256, //!< pass[0].tr_sar_ch_done[66]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE67 = 257, //!< pass[0].tr_sar_ch_done[67]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE68 = 258, //!< pass[0].tr_sar_ch_done[68]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE69 = 259, //!< pass[0].tr_sar_ch_done[69]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE70 = 260, //!< pass[0].tr_sar_ch_done[70]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_DONE71 = 261, //!< pass[0].tr_sar_ch_done[71]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO0 = 262, //!< pass[0].tr_sar_ch_rangevio[0]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO1 = 263, //!< pass[0].tr_sar_ch_rangevio[1]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO2 = 264, //!< pass[0].tr_sar_ch_rangevio[2]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO3 = 265, //!< pass[0].tr_sar_ch_rangevio[3]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO4 = 266, //!< pass[0].tr_sar_ch_rangevio[4]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO5 = 267, //!< pass[0].tr_sar_ch_rangevio[5]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO6 = 268, //!< pass[0].tr_sar_ch_rangevio[6]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO7 = 269, //!< pass[0].tr_sar_ch_rangevio[7]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO8 = 270, //!< pass[0].tr_sar_ch_rangevio[8]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO9 = 271, //!< pass[0].tr_sar_ch_rangevio[9]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO10 = 272, //!< pass[0].tr_sar_ch_rangevio[10]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO11 = 273, //!< pass[0].tr_sar_ch_rangevio[11]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO12 = 274, //!< pass[0].tr_sar_ch_rangevio[12]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO13 = 275, //!< pass[0].tr_sar_ch_rangevio[13]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO14 = 276, //!< pass[0].tr_sar_ch_rangevio[14]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO15 = 277, //!< pass[0].tr_sar_ch_rangevio[15]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO16 = 278, //!< pass[0].tr_sar_ch_rangevio[16]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO17 = 279, //!< pass[0].tr_sar_ch_rangevio[17]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO18 = 280, //!< pass[0].tr_sar_ch_rangevio[18]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO19 = 281, //!< pass[0].tr_sar_ch_rangevio[19]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO20 = 282, //!< pass[0].tr_sar_ch_rangevio[20]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO21 = 283, //!< pass[0].tr_sar_ch_rangevio[21]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO22 = 284, //!< pass[0].tr_sar_ch_rangevio[22]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO23 = 285, //!< pass[0].tr_sar_ch_rangevio[23]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO32 = 286, //!< pass[0].tr_sar_ch_rangevio[32]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO33 = 287, //!< pass[0].tr_sar_ch_rangevio[33]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO34 = 288, //!< pass[0].tr_sar_ch_rangevio[34]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO35 = 289, //!< pass[0].tr_sar_ch_rangevio[35]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO36 = 290, //!< pass[0].tr_sar_ch_rangevio[36]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO37 = 291, //!< pass[0].tr_sar_ch_rangevio[37]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO38 = 292, //!< pass[0].tr_sar_ch_rangevio[38]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO39 = 293, //!< pass[0].tr_sar_ch_rangevio[39]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO40 = 294, //!< pass[0].tr_sar_ch_rangevio[40]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO41 = 295, //!< pass[0].tr_sar_ch_rangevio[41]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO42 = 296, //!< pass[0].tr_sar_ch_rangevio[42]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO43 = 297, //!< pass[0].tr_sar_ch_rangevio[43]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO44 = 298, //!< pass[0].tr_sar_ch_rangevio[44]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO45 = 299, //!< pass[0].tr_sar_ch_rangevio[45]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO46 = 300, //!< pass[0].tr_sar_ch_rangevio[46]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO47 = 301, //!< pass[0].tr_sar_ch_rangevio[47]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO48 = 302, //!< pass[0].tr_sar_ch_rangevio[48]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO49 = 303, //!< pass[0].tr_sar_ch_rangevio[49]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO50 = 304, //!< pass[0].tr_sar_ch_rangevio[50]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO51 = 305, //!< pass[0].tr_sar_ch_rangevio[51]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO52 = 306, //!< pass[0].tr_sar_ch_rangevio[52]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO53 = 307, //!< pass[0].tr_sar_ch_rangevio[53]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO54 = 308, //!< pass[0].tr_sar_ch_rangevio[54]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO55 = 309, //!< pass[0].tr_sar_ch_rangevio[55]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO56 = 310, //!< pass[0].tr_sar_ch_rangevio[56]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO57 = 311, //!< pass[0].tr_sar_ch_rangevio[57]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO58 = 312, //!< pass[0].tr_sar_ch_rangevio[58]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO59 = 313, //!< pass[0].tr_sar_ch_rangevio[59]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO60 = 314, //!< pass[0].tr_sar_ch_rangevio[60]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO61 = 315, //!< pass[0].tr_sar_ch_rangevio[61]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO62 = 316, //!< pass[0].tr_sar_ch_rangevio[62]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO63 = 317, //!< pass[0].tr_sar_ch_rangevio[63]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO64 = 318, //!< pass[0].tr_sar_ch_rangevio[64]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO65 = 319, //!< pass[0].tr_sar_ch_rangevio[65]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO66 = 320, //!< pass[0].tr_sar_ch_rangevio[66]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO67 = 321, //!< pass[0].tr_sar_ch_rangevio[67]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO68 = 322, //!< pass[0].tr_sar_ch_rangevio[68]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO69 = 323, //!< pass[0].tr_sar_ch_rangevio[69]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO70 = 324, //!< pass[0].tr_sar_ch_rangevio[70]
    _CYHAL_TRIGGER_PASS0_TR_SAR_CH_RANGEVIO71 = 325, //!< pass[0].tr_sar_ch_rangevio[71]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT0 = 326, //!< pass[0].tr_sar_gen_out[0]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT1 = 327, //!< pass[0].tr_sar_gen_out[1]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT2 = 328, //!< pass[0].tr_sar_gen_out[2]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT3 = 329, //!< pass[0].tr_sar_gen_out[3]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT4 = 330, //!< pass[0].tr_sar_gen_out[4]
    _CYHAL_TRIGGER_PASS0_TR_SAR_GEN_OUT5 = 331, //!< pass[0].tr_sar_gen_out[5]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT0 = 332, //!< peri.tr_io_input[0]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT1 = 333, //!< peri.tr_io_input[1]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT2 = 334, //!< peri.tr_io_input[2]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT3 = 335, //!< peri.tr_io_input[3]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT4 = 336, //!< peri.tr_io_input[4]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT5 = 337, //!< peri.tr_io_input[5]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT6 = 338, //!< peri.tr_io_input[6]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT7 = 339, //!< peri.tr_io_input[7]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT8 = 340, //!< peri.tr_io_input[8]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT9 = 341, //!< peri.tr_io_input[9]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT10 = 342, //!< peri.tr_io_input[10]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT11 = 343, //!< peri.tr_io_input[11]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT12 = 344, //!< peri.tr_io_input[12]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT13 = 345, //!< peri.tr_io_input[13]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT14 = 346, //!< peri.tr_io_input[14]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT15 = 347, //!< peri.tr_io_input[15]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT16 = 348, //!< peri.tr_io_input[16]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT17 = 349, //!< peri.tr_io_input[17]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT18 = 350, //!< peri.tr_io_input[18]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT19 = 351, //!< peri.tr_io_input[19]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT20 = 352, //!< peri.tr_io_input[20]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT21 = 353, //!< peri.tr_io_input[21]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT22 = 354, //!< peri.tr_io_input[22]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT23 = 355, //!< peri.tr_io_input[23]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT24 = 356, //!< peri.tr_io_input[24]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT25 = 357, //!< peri.tr_io_input[25]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT26 = 358, //!< peri.tr_io_input[26]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT27 = 359, //!< peri.tr_io_input[27]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT28 = 360, //!< peri.tr_io_input[28]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT29 = 361, //!< peri.tr_io_input[29]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT30 = 362, //!< peri.tr_io_input[30]
    _CYHAL_TRIGGER_PERI_TR_IO_INPUT31 = 363, //!< peri.tr_io_input[31]
    _CYHAL_TRIGGER_SCB0_TR_I2C_SCL_FILTERED = 364, //!< scb[0].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB1_TR_I2C_SCL_FILTERED = 365, //!< scb[1].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB2_TR_I2C_SCL_FILTERED = 366, //!< scb[2].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB3_TR_I2C_SCL_FILTERED = 367, //!< scb[3].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB4_TR_I2C_SCL_FILTERED = 368, //!< scb[4].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB5_TR_I2C_SCL_FILTERED = 369, //!< scb[5].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB6_TR_I2C_SCL_FILTERED = 370, //!< scb[6].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB7_TR_I2C_SCL_FILTERED = 371, //!< scb[7].tr_i2c_scl_filtered
    _CYHAL_TRIGGER_SCB0_TR_RX_REQ = 372, //!< scb[0].tr_rx_req
    _CYHAL_TRIGGER_SCB1_TR_RX_REQ = 373, //!< scb[1].tr_rx_req
    _CYHAL_TRIGGER_SCB2_TR_RX_REQ = 374, //!< scb[2].tr_rx_req
    _CYHAL_TRIGGER_SCB3_TR_RX_REQ = 375, //!< scb[3].tr_rx_req
    _CYHAL_TRIGGER_SCB4_TR_RX_REQ = 376, //!< scb[4].tr_rx_req
    _CYHAL_TRIGGER_SCB5_TR_RX_REQ = 377, //!< scb[5].tr_rx_req
    _CYHAL_TRIGGER_SCB6_TR_RX_REQ = 378, //!< scb[6].tr_rx_req
    _CYHAL_TRIGGER_SCB7_TR_RX_REQ = 379, //!< scb[7].tr_rx_req
    _CYHAL_TRIGGER_SCB0_TR_TX_REQ = 380, //!< scb[0].tr_tx_req
    _CYHAL_TRIGGER_SCB1_TR_TX_REQ = 381, //!< scb[1].tr_tx_req
    _CYHAL_TRIGGER_SCB2_TR_TX_REQ = 382, //!< scb[2].tr_tx_req
    _CYHAL_TRIGGER_SCB3_TR_TX_REQ = 383, //!< scb[3].tr_tx_req
    _CYHAL_TRIGGER_SCB4_TR_TX_REQ = 384, //!< scb[4].tr_tx_req
    _CYHAL_TRIGGER_SCB5_TR_TX_REQ = 385, //!< scb[5].tr_tx_req
    _CYHAL_TRIGGER_SCB6_TR_TX_REQ = 386, //!< scb[6].tr_tx_req
    _CYHAL_TRIGGER_SCB7_TR_TX_REQ = 387, //!< scb[7].tr_tx_req
    _CYHAL_TRIGGER_TCPWM0_TR_OUT00 = 388, //!< tcpwm[0].tr_out0[0]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT01 = 389, //!< tcpwm[0].tr_out0[1]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT02 = 390, //!< tcpwm[0].tr_out0[2]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT03 = 391, //!< tcpwm[0].tr_out0[3]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT04 = 392, //!< tcpwm[0].tr_out0[4]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT05 = 393, //!< tcpwm[0].tr_out0[5]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT06 = 394, //!< tcpwm[0].tr_out0[6]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT07 = 395, //!< tcpwm[0].tr_out0[7]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT08 = 396, //!< tcpwm[0].tr_out0[8]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT09 = 397, //!< tcpwm[0].tr_out0[9]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT010 = 398, //!< tcpwm[0].tr_out0[10]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT011 = 399, //!< tcpwm[0].tr_out0[11]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT012 = 400, //!< tcpwm[0].tr_out0[12]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT013 = 401, //!< tcpwm[0].tr_out0[13]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT014 = 402, //!< tcpwm[0].tr_out0[14]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT015 = 403, //!< tcpwm[0].tr_out0[15]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT016 = 404, //!< tcpwm[0].tr_out0[16]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT017 = 405, //!< tcpwm[0].tr_out0[17]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT018 = 406, //!< tcpwm[0].tr_out0[18]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT019 = 407, //!< tcpwm[0].tr_out0[19]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT020 = 408, //!< tcpwm[0].tr_out0[20]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT021 = 409, //!< tcpwm[0].tr_out0[21]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT022 = 410, //!< tcpwm[0].tr_out0[22]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT023 = 411, //!< tcpwm[0].tr_out0[23]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT024 = 412, //!< tcpwm[0].tr_out0[24]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT025 = 413, //!< tcpwm[0].tr_out0[25]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT026 = 414, //!< tcpwm[0].tr_out0[26]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT027 = 415, //!< tcpwm[0].tr_out0[27]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT028 = 416, //!< tcpwm[0].tr_out0[28]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT029 = 417, //!< tcpwm[0].tr_out0[29]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT030 = 418, //!< tcpwm[0].tr_out0[30]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT031 = 419, //!< tcpwm[0].tr_out0[31]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT032 = 420, //!< tcpwm[0].tr_out0[32]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT033 = 421, //!< tcpwm[0].tr_out0[33]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT034 = 422, //!< tcpwm[0].tr_out0[34]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT035 = 423, //!< tcpwm[0].tr_out0[35]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT036 = 424, //!< tcpwm[0].tr_out0[36]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT037 = 425, //!< tcpwm[0].tr_out0[37]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT038 = 426, //!< tcpwm[0].tr_out0[38]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT039 = 427, //!< tcpwm[0].tr_out0[39]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT040 = 428, //!< tcpwm[0].tr_out0[40]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT041 = 429, //!< tcpwm[0].tr_out0[41]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT042 = 430, //!< tcpwm[0].tr_out0[42]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT043 = 431, //!< tcpwm[0].tr_out0[43]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT044 = 432, //!< tcpwm[0].tr_out0[44]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT045 = 433, //!< tcpwm[0].tr_out0[45]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT046 = 434, //!< tcpwm[0].tr_out0[46]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT047 = 435, //!< tcpwm[0].tr_out0[47]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT048 = 436, //!< tcpwm[0].tr_out0[48]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT049 = 437, //!< tcpwm[0].tr_out0[49]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT050 = 438, //!< tcpwm[0].tr_out0[50]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT051 = 439, //!< tcpwm[0].tr_out0[51]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT052 = 440, //!< tcpwm[0].tr_out0[52]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT053 = 441, //!< tcpwm[0].tr_out0[53]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT054 = 442, //!< tcpwm[0].tr_out0[54]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT055 = 443, //!< tcpwm[0].tr_out0[55]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT056 = 444, //!< tcpwm[0].tr_out0[56]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT057 = 445, //!< tcpwm[0].tr_out0[57]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT058 = 446, //!< tcpwm[0].tr_out0[58]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT059 = 447, //!< tcpwm[0].tr_out0[59]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT060 = 448, //!< tcpwm[0].tr_out0[60]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT061 = 449, //!< tcpwm[0].tr_out0[61]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT062 = 450, //!< tcpwm[0].tr_out0[62]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0256 = 451, //!< tcpwm[0].tr_out0[256]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0257 = 452, //!< tcpwm[0].tr_out0[257]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0258 = 453, //!< tcpwm[0].tr_out0[258]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0259 = 454, //!< tcpwm[0].tr_out0[259]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0260 = 455, //!< tcpwm[0].tr_out0[260]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0261 = 456, //!< tcpwm[0].tr_out0[261]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0262 = 457, //!< tcpwm[0].tr_out0[262]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0263 = 458, //!< tcpwm[0].tr_out0[263]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0264 = 459, //!< tcpwm[0].tr_out0[264]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0265 = 460, //!< tcpwm[0].tr_out0[265]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0266 = 461, //!< tcpwm[0].tr_out0[266]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0267 = 462, //!< tcpwm[0].tr_out0[267]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0512 = 463, //!< tcpwm[0].tr_out0[512]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0513 = 464, //!< tcpwm[0].tr_out0[513]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0514 = 465, //!< tcpwm[0].tr_out0[514]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0515 = 466, //!< tcpwm[0].tr_out0[515]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0516 = 467, //!< tcpwm[0].tr_out0[516]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0517 = 468, //!< tcpwm[0].tr_out0[517]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0518 = 469, //!< tcpwm[0].tr_out0[518]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0519 = 470, //!< tcpwm[0].tr_out0[519]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT10 = 471, //!< tcpwm[0].tr_out1[0]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT11 = 472, //!< tcpwm[0].tr_out1[1]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT12 = 473, //!< tcpwm[0].tr_out1[2]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT13 = 474, //!< tcpwm[0].tr_out1[3]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT14 = 475, //!< tcpwm[0].tr_out1[4]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT15 = 476, //!< tcpwm[0].tr_out1[5]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT16 = 477, //!< tcpwm[0].tr_out1[6]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT17 = 478, //!< tcpwm[0].tr_out1[7]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT18 = 479, //!< tcpwm[0].tr_out1[8]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT19 = 480, //!< tcpwm[0].tr_out1[9]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT110 = 481, //!< tcpwm[0].tr_out1[10]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT111 = 482, //!< tcpwm[0].tr_out1[11]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT112 = 483, //!< tcpwm[0].tr_out1[12]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT113 = 484, //!< tcpwm[0].tr_out1[13]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT114 = 485, //!< tcpwm[0].tr_out1[14]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT115 = 486, //!< tcpwm[0].tr_out1[15]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT116 = 487, //!< tcpwm[0].tr_out1[16]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT117 = 488, //!< tcpwm[0].tr_out1[17]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT118 = 489, //!< tcpwm[0].tr_out1[18]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT119 = 490, //!< tcpwm[0].tr_out1[19]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT120 = 491, //!< tcpwm[0].tr_out1[20]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT121 = 492, //!< tcpwm[0].tr_out1[21]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT122 = 493, //!< tcpwm[0].tr_out1[22]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT123 = 494, //!< tcpwm[0].tr_out1[23]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT124 = 495, //!< tcpwm[0].tr_out1[24]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT125 = 496, //!< tcpwm[0].tr_out1[25]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT126 = 497, //!< tcpwm[0].tr_out1[26]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT127 = 498, //!< tcpwm[0].tr_out1[27]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT128 = 499, //!< tcpwm[0].tr_out1[28]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT129 = 500, //!< tcpwm[0].tr_out1[29]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT130 = 501, //!< tcpwm[0].tr_out1[30]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT131 = 502, //!< tcpwm[0].tr_out1[31]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT132 = 503, //!< tcpwm[0].tr_out1[32]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT133 = 504, //!< tcpwm[0].tr_out1[33]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT134 = 505, //!< tcpwm[0].tr_out1[34]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT135 = 506, //!< tcpwm[0].tr_out1[35]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT136 = 507, //!< tcpwm[0].tr_out1[36]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT137 = 508, //!< tcpwm[0].tr_out1[37]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT138 = 509, //!< tcpwm[0].tr_out1[38]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT139 = 510, //!< tcpwm[0].tr_out1[39]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT140 = 511, //!< tcpwm[0].tr_out1[40]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT141 = 512, //!< tcpwm[0].tr_out1[41]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT142 = 513, //!< tcpwm[0].tr_out1[42]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT143 = 514, //!< tcpwm[0].tr_out1[43]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT144 = 515, //!< tcpwm[0].tr_out1[44]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT145 = 516, //!< tcpwm[0].tr_out1[45]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT146 = 517, //!< tcpwm[0].tr_out1[46]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT147 = 518, //!< tcpwm[0].tr_out1[47]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT148 = 519, //!< tcpwm[0].tr_out1[48]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT149 = 520, //!< tcpwm[0].tr_out1[49]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT150 = 521, //!< tcpwm[0].tr_out1[50]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT151 = 522, //!< tcpwm[0].tr_out1[51]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT152 = 523, //!< tcpwm[0].tr_out1[52]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT153 = 524, //!< tcpwm[0].tr_out1[53]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT154 = 525, //!< tcpwm[0].tr_out1[54]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT155 = 526, //!< tcpwm[0].tr_out1[55]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT156 = 527, //!< tcpwm[0].tr_out1[56]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT157 = 528, //!< tcpwm[0].tr_out1[57]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT158 = 529, //!< tcpwm[0].tr_out1[58]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT159 = 530, //!< tcpwm[0].tr_out1[59]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT160 = 531, //!< tcpwm[0].tr_out1[60]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT161 = 532, //!< tcpwm[0].tr_out1[61]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT162 = 533, //!< tcpwm[0].tr_out1[62]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1256 = 534, //!< tcpwm[0].tr_out1[256]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1257 = 535, //!< tcpwm[0].tr_out1[257]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1258 = 536, //!< tcpwm[0].tr_out1[258]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1259 = 537, //!< tcpwm[0].tr_out1[259]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1260 = 538, //!< tcpwm[0].tr_out1[260]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1261 = 539, //!< tcpwm[0].tr_out1[261]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1262 = 540, //!< tcpwm[0].tr_out1[262]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1263 = 541, //!< tcpwm[0].tr_out1[263]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1264 = 542, //!< tcpwm[0].tr_out1[264]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1265 = 543, //!< tcpwm[0].tr_out1[265]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1266 = 544, //!< tcpwm[0].tr_out1[266]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1267 = 545, //!< tcpwm[0].tr_out1[267]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1512 = 546, //!< tcpwm[0].tr_out1[512]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1513 = 547, //!< tcpwm[0].tr_out1[513]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1514 = 548, //!< tcpwm[0].tr_out1[514]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1515 = 549, //!< tcpwm[0].tr_out1[515]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1516 = 550, //!< tcpwm[0].tr_out1[516]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1517 = 551, //!< tcpwm[0].tr_out1[517]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1518 = 552, //!< tcpwm[0].tr_out1[518]
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1519 = 553, //!< tcpwm[0].tr_out1[519]
    _CYHAL_TRIGGER_TR_GROUP9_OUTPUT0 = 554, //!< tr_group[9].output[0]
    _CYHAL_TRIGGER_TR_GROUP9_OUTPUT1 = 555, //!< tr_group[9].output[1]
    _CYHAL_TRIGGER_TR_GROUP9_OUTPUT2 = 556, //!< tr_group[9].output[2]
    _CYHAL_TRIGGER_TR_GROUP9_OUTPUT3 = 557, //!< tr_group[9].output[3]
    _CYHAL_TRIGGER_TR_GROUP9_OUTPUT4 = 558, //!< tr_group[9].output[4]
    _CYHAL_TRIGGER_TR_GROUP10_OUTPUT0 = 559, //!< tr_group[10].output[0]
    _CYHAL_TRIGGER_TR_GROUP10_OUTPUT1 = 560, //!< tr_group[10].output[1]
    _CYHAL_TRIGGER_TR_GROUP10_OUTPUT2 = 561, //!< tr_group[10].output[2]
    _CYHAL_TRIGGER_TR_GROUP10_OUTPUT3 = 562, //!< tr_group[10].output[3]
    _CYHAL_TRIGGER_TR_GROUP10_OUTPUT4 = 563, //!< tr_group[10].output[4]
} _cyhal_trigger_source_tviibe4m_t;

/** Typedef for internal device family specific trigger source to generic trigger source */
typedef _cyhal_trigger_source_tviibe4m_t cyhal_internal_source_t;

/** @brief Get a public source signal type (cyhal_trigger_source_tviibe4m_t) given an internal source signal and signal type */
#define _CYHAL_TRIGGER_CREATE_SOURCE(src, type)    ((src) << 1 | (type))
/** @brief Get an internal source signal (_cyhal_trigger_source_tviibe4m_t) given a public source signal. */
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
    CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ3, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_dbg_dma_req[3]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ0, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_dbg_dma_req[0]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ1, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_dbg_dma_req[1]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ2, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_dbg_dma_req[2]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_REQ3, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_dbg_dma_req[3]
    CYHAL_TRIGGER_CANFD0_TR_FIFO00 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO00, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo0[0]
    CYHAL_TRIGGER_CANFD0_TR_FIFO01 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO01, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo0[1]
    CYHAL_TRIGGER_CANFD0_TR_FIFO02 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO02, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo0[2]
    CYHAL_TRIGGER_CANFD0_TR_FIFO03 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO03, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo0[3]
    CYHAL_TRIGGER_CANFD1_TR_FIFO00 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO00, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo0[0]
    CYHAL_TRIGGER_CANFD1_TR_FIFO01 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO01, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo0[1]
    CYHAL_TRIGGER_CANFD1_TR_FIFO02 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO02, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo0[2]
    CYHAL_TRIGGER_CANFD1_TR_FIFO03 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO03, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo0[3]
    CYHAL_TRIGGER_CANFD0_TR_FIFO10 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO10, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo1[0]
    CYHAL_TRIGGER_CANFD0_TR_FIFO11 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO11, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo1[1]
    CYHAL_TRIGGER_CANFD0_TR_FIFO12 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO12, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo1[2]
    CYHAL_TRIGGER_CANFD0_TR_FIFO13 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_FIFO13, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[0].tr_fifo1[3]
    CYHAL_TRIGGER_CANFD1_TR_FIFO10 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO10, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo1[0]
    CYHAL_TRIGGER_CANFD1_TR_FIFO11 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO11, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo1[1]
    CYHAL_TRIGGER_CANFD1_TR_FIFO12 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO12, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo1[2]
    CYHAL_TRIGGER_CANFD1_TR_FIFO13 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_FIFO13, CYHAL_SIGNAL_TYPE_LEVEL), //!< canfd[1].tr_fifo1[3]
    CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[0].tr_tmp_rtp_out[0]
    CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[0].tr_tmp_rtp_out[1]
    CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[0].tr_tmp_rtp_out[2]
    CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT3, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[0].tr_tmp_rtp_out[3]
    CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT0, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[1].tr_tmp_rtp_out[0]
    CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT1, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[1].tr_tmp_rtp_out[1]
    CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT2, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[1].tr_tmp_rtp_out[2]
    CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CANFD1_TR_TMP_RTP_OUT3, CYHAL_SIGNAL_TYPE_EDGE), //!< canfd[1].tr_tmp_rtp_out[3]
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
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT89 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT89, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[89]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT90 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT90, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[90]
    CYHAL_TRIGGER_CPUSS_DW0_TR_OUT91 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW0_TR_OUT91, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw0_tr_out[91]
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
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT33 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT33, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[33]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT34 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT34, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[34]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT35 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT35, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[35]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT36 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT36, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[36]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT37 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT37, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[37]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT38 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT38, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[38]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT39 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT39, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[39]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT40 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT40, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[40]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT41 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT41, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[41]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT42 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT42, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[42]
    CYHAL_TRIGGER_CPUSS_DW1_TR_OUT43 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_DW1_TR_OUT43, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.dw1_tr_out[43]
    CYHAL_TRIGGER_CPUSS_TR_FAULT0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_TR_FAULT0, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.tr_fault[0]
    CYHAL_TRIGGER_CPUSS_TR_FAULT1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_TR_FAULT1, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.tr_fault[1]
    CYHAL_TRIGGER_CPUSS_TR_FAULT2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_TR_FAULT2, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.tr_fault[2]
    CYHAL_TRIGGER_CPUSS_TR_FAULT3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CPUSS_TR_FAULT3, CYHAL_SIGNAL_TYPE_EDGE), //!< cpuss.tr_fault[3]
    CYHAL_TRIGGER_CXPI0_TR_RX_REQ0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CXPI0_TR_RX_REQ0, CYHAL_SIGNAL_TYPE_LEVEL), //!< cxpi[0].tr_rx_req[0]
    CYHAL_TRIGGER_CXPI0_TR_RX_REQ1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CXPI0_TR_RX_REQ1, CYHAL_SIGNAL_TYPE_LEVEL), //!< cxpi[0].tr_rx_req[1]
    CYHAL_TRIGGER_CXPI0_TR_RX_REQ2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CXPI0_TR_RX_REQ2, CYHAL_SIGNAL_TYPE_LEVEL), //!< cxpi[0].tr_rx_req[2]
    CYHAL_TRIGGER_CXPI0_TR_RX_REQ3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CXPI0_TR_RX_REQ3, CYHAL_SIGNAL_TYPE_LEVEL), //!< cxpi[0].tr_rx_req[3]
    CYHAL_TRIGGER_CXPI0_TR_TX_REQ0 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CXPI0_TR_TX_REQ0, CYHAL_SIGNAL_TYPE_LEVEL), //!< cxpi[0].tr_tx_req[0]
    CYHAL_TRIGGER_CXPI0_TR_TX_REQ1 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CXPI0_TR_TX_REQ1, CYHAL_SIGNAL_TYPE_LEVEL), //!< cxpi[0].tr_tx_req[1]
    CYHAL_TRIGGER_CXPI0_TR_TX_REQ2 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CXPI0_TR_TX_REQ2, CYHAL_SIGNAL_TYPE_LEVEL), //!< cxpi[0].tr_tx_req[2]
    CYHAL_TRIGGER_CXPI0_TR_TX_REQ3 = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_CXPI0_TR_TX_REQ3, CYHAL_SIGNAL_TYPE_LEVEL), //!< cxpi[0].tr_tx_req[3]
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
    CYHAL_TRIGGER_TCPWM0_TR_OUT0516_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0516, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[516]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0516_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0516, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[516]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0517_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0517, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[517]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0517_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0517, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[517]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0518_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0518, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[518]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0518_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0518, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[518]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0519_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0519, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out0[519]
    CYHAL_TRIGGER_TCPWM0_TR_OUT0519_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT0519, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out0[519]
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
    CYHAL_TRIGGER_TCPWM0_TR_OUT1516_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1516, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[516]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1516_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1516, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[516]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1517_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1517, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[517]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1517_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1517, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[517]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1518_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1518, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[518]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1518_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1518, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[518]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1519_EDGE = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1519, CYHAL_SIGNAL_TYPE_EDGE), //!< tcpwm[0].tr_out1[519]
    CYHAL_TRIGGER_TCPWM0_TR_OUT1519_LEVEL = _CYHAL_TRIGGER_CREATE_SOURCE(_CYHAL_TRIGGER_TCPWM0_TR_OUT1519, CYHAL_SIGNAL_TYPE_LEVEL), //!< tcpwm[0].tr_out1[519]
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
} cyhal_trigger_source_tviibe4m_t;

/** Typedef from device family specific trigger source to generic trigger source */
typedef cyhal_trigger_source_tviibe4m_t cyhal_source_t;

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
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0516 (CYHAL_TRIGGER_TCPWM0_TR_OUT0516_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0517 (CYHAL_TRIGGER_TCPWM0_TR_OUT0517_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0518 (CYHAL_TRIGGER_TCPWM0_TR_OUT0518_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT0519 (CYHAL_TRIGGER_TCPWM0_TR_OUT0519_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
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
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1516 (CYHAL_TRIGGER_TCPWM0_TR_OUT1516_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1517 (CYHAL_TRIGGER_TCPWM0_TR_OUT1517_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1518 (CYHAL_TRIGGER_TCPWM0_TR_OUT1518_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
#define CYHAL_TRIGGER_TCPWM0_TR_OUT1519 (CYHAL_TRIGGER_TCPWM0_TR_OUT1519_LEVEL) //!< Legacy define. Instead, use the explicit _LEVEL or _EDGE version.
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
    CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_ACK3 = 3, //!< CAN DW0 triggers (from DW back to CAN) - canfd[0].tr_dbg_dma_ack[3]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_ACK0 = 4, //!< CAN DW1 triggers (from DW back to CAN) - canfd[1].tr_dbg_dma_ack[0]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_ACK1 = 5, //!< CAN DW1 triggers (from DW back to CAN) - canfd[1].tr_dbg_dma_ack[1]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_ACK2 = 6, //!< CAN DW1 triggers (from DW back to CAN) - canfd[1].tr_dbg_dma_ack[2]
    CYHAL_TRIGGER_CANFD1_TR_DBG_DMA_ACK3 = 7, //!< CAN DW1 triggers (from DW back to CAN) - canfd[1].tr_dbg_dma_ack[3]
    CYHAL_TRIGGER_CANFD0_TR_EVT_SWT_IN0 = 8, //!< CAN TT Sync - canfd[0].tr_evt_swt_in[0]
    CYHAL_TRIGGER_CANFD0_TR_EVT_SWT_IN1 = 9, //!< CAN TT Sync - canfd[0].tr_evt_swt_in[1]
    CYHAL_TRIGGER_CANFD0_TR_EVT_SWT_IN2 = 10, //!< CAN TT Sync - canfd[0].tr_evt_swt_in[2]
    CYHAL_TRIGGER_CANFD0_TR_EVT_SWT_IN3 = 11, //!< CAN TT Sync - canfd[0].tr_evt_swt_in[3]
    CYHAL_TRIGGER_CANFD1_TR_EVT_SWT_IN0 = 12, //!< CAN TT Sync - canfd[1].tr_evt_swt_in[0]
    CYHAL_TRIGGER_CANFD1_TR_EVT_SWT_IN1 = 13, //!< CAN TT Sync - canfd[1].tr_evt_swt_in[1]
    CYHAL_TRIGGER_CANFD1_TR_EVT_SWT_IN2 = 14, //!< CAN TT Sync - canfd[1].tr_evt_swt_in[2]
    CYHAL_TRIGGER_CANFD1_TR_EVT_SWT_IN3 = 15, //!< CAN TT Sync - canfd[1].tr_evt_swt_in[3]
    CYHAL_TRIGGER_CPUSS_CTI_TR_IN0 = 16, //!< Debug Multiplexer - cpuss.cti_tr_in[0]
    CYHAL_TRIGGER_CPUSS_CTI_TR_IN1 = 17, //!< Debug Multiplexer - cpuss.cti_tr_in[1]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_IN0 = 18, //!< M-DMA trigger multiplexer - cpuss.dmac_tr_in[0]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_IN1 = 19, //!< M-DMA trigger multiplexer - cpuss.dmac_tr_in[1]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_IN2 = 20, //!< M-DMA trigger multiplexer - cpuss.dmac_tr_in[2]
    CYHAL_TRIGGER_CPUSS_DMAC_TR_IN3 = 21, //!< M-DMA trigger multiplexer - cpuss.dmac_tr_in[3]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN0 = 22, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[0]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN1 = 23, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[1]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN2 = 24, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[2]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN3 = 25, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[3]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN4 = 26, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[4]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN5 = 27, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[5]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN6 = 28, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[6]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN7 = 29, //!< P-DMA0 trigger multiplexer - cpuss.dw0_tr_in[7]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN8 = 30, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[8]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN9 = 31, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[9]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN10 = 32, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[10]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN11 = 33, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[11]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN12 = 34, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[12]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN13 = 35, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[13]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN14 = 36, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[14]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN15 = 37, //!< TCPWM to P-DMA0 trigger mux - cpuss.dw0_tr_in[15]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN16 = 38, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[16]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN17 = 39, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[17]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN18 = 40, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[18]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN19 = 41, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[19]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN20 = 42, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[20]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN21 = 43, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[21]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN22 = 44, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[22]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN23 = 45, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[23]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN24 = 46, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[24]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN25 = 47, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[25]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN26 = 48, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[26]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN27 = 49, //!< CAN DW0 Triggers - cpuss.dw0_tr_in[27]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN28 = 50, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[28]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN29 = 51, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[29]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN30 = 52, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[30]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN31 = 53, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[31]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN32 = 54, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[32]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN33 = 55, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[33]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN34 = 56, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[34]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN35 = 57, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[35]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN36 = 58, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[36]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN37 = 59, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[37]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN38 = 60, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[38]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN39 = 61, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[39]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN40 = 62, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[40]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN41 = 63, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[41]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN42 = 64, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[42]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN43 = 65, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[43]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN44 = 66, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[44]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN45 = 67, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[45]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN46 = 68, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[46]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN47 = 69, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[47]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN48 = 70, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[48]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN49 = 71, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[49]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN50 = 72, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[50]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN51 = 73, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[51]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN52 = 74, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[52]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN53 = 75, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[53]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN54 = 76, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[54]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN55 = 77, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[55]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN56 = 78, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[56]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN57 = 79, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[57]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN58 = 80, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[58]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN59 = 81, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[59]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN60 = 82, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[60]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN61 = 83, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[61]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN62 = 84, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[62]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN63 = 85, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[63]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN64 = 86, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[64]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN65 = 87, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[65]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN66 = 88, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[66]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN67 = 89, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[67]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN68 = 90, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[68]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN69 = 91, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[69]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN70 = 92, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[70]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN71 = 93, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[71]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN72 = 94, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[72]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN73 = 95, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[73]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN74 = 96, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[74]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN75 = 97, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[75]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN76 = 98, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[76]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN77 = 99, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[77]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN78 = 100, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[78]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN79 = 101, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[79]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN80 = 102, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[80]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN81 = 103, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[81]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN82 = 104, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[82]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN83 = 105, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[83]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN84 = 106, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[84]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN85 = 107, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[85]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN86 = 108, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[86]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN87 = 109, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[87]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN88 = 110, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[88]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN89 = 111, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[89]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN90 = 112, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[90]
    CYHAL_TRIGGER_CPUSS_DW0_TR_IN91 = 113, //!< PASS to DW0 direct connect - cpuss.dw0_tr_in[91]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN0 = 114, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[0]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN1 = 115, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[1]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN2 = 116, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[2]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN3 = 117, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[3]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN4 = 118, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[4]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN5 = 119, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[5]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN6 = 120, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[6]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN7 = 121, //!< P-DMA1 trigger multiplexer - cpuss.dw1_tr_in[7]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN8 = 122, //!< SCB DW Triggers - cpuss.dw1_tr_in[8]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN9 = 123, //!< SCB DW Triggers - cpuss.dw1_tr_in[9]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN10 = 124, //!< SCB DW Triggers - cpuss.dw1_tr_in[10]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN11 = 125, //!< SCB DW Triggers - cpuss.dw1_tr_in[11]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN12 = 126, //!< SCB DW Triggers - cpuss.dw1_tr_in[12]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN13 = 127, //!< SCB DW Triggers - cpuss.dw1_tr_in[13]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN14 = 128, //!< SCB DW Triggers - cpuss.dw1_tr_in[14]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN15 = 129, //!< SCB DW Triggers - cpuss.dw1_tr_in[15]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN16 = 130, //!< SCB DW Triggers - cpuss.dw1_tr_in[16]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN17 = 131, //!< SCB DW Triggers - cpuss.dw1_tr_in[17]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN18 = 132, //!< SCB DW Triggers - cpuss.dw1_tr_in[18]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN19 = 133, //!< SCB DW Triggers - cpuss.dw1_tr_in[19]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN20 = 134, //!< SCB DW Triggers - cpuss.dw1_tr_in[20]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN21 = 135, //!< SCB DW Triggers - cpuss.dw1_tr_in[21]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN22 = 136, //!< SCB DW Triggers - cpuss.dw1_tr_in[22]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN23 = 137, //!< SCB DW Triggers - cpuss.dw1_tr_in[23]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN24 = 138, //!< CAN DW1 triggers - cpuss.dw1_tr_in[24]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN25 = 139, //!< CAN DW1 triggers - cpuss.dw1_tr_in[25]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN26 = 140, //!< CAN DW1 triggers - cpuss.dw1_tr_in[26]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN27 = 141, //!< CAN DW1 triggers - cpuss.dw1_tr_in[27]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN28 = 142, //!< CAN DW1 triggers - cpuss.dw1_tr_in[28]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN29 = 143, //!< CAN DW1 triggers - cpuss.dw1_tr_in[29]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN30 = 144, //!< CAN DW1 triggers - cpuss.dw1_tr_in[30]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN31 = 145, //!< CAN DW1 triggers - cpuss.dw1_tr_in[31]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN32 = 146, //!< CAN DW1 triggers - cpuss.dw1_tr_in[32]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN33 = 147, //!< CAN DW1 triggers - cpuss.dw1_tr_in[33]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN34 = 148, //!< CAN DW1 triggers - cpuss.dw1_tr_in[34]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN35 = 149, //!< CAN DW1 triggers - cpuss.dw1_tr_in[35]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN36 = 150, //!< CXPI DW Triggers - cpuss.dw1_tr_in[36]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN37 = 151, //!< CXPI DW Triggers - cpuss.dw1_tr_in[37]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN38 = 152, //!< CXPI DW Triggers - cpuss.dw1_tr_in[38]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN39 = 153, //!< CXPI DW Triggers - cpuss.dw1_tr_in[39]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN40 = 154, //!< CXPI DW Triggers - cpuss.dw1_tr_in[40]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN41 = 155, //!< CXPI DW Triggers - cpuss.dw1_tr_in[41]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN42 = 156, //!< CXPI DW Triggers - cpuss.dw1_tr_in[42]
    CYHAL_TRIGGER_CPUSS_DW1_TR_IN43 = 157, //!< CXPI DW Triggers - cpuss.dw1_tr_in[43]
    CYHAL_TRIGGER_CXPI0_TR_CMD_TX_HEADER0 = 158, //!< EVTGEN CXPI triggers - cxpi[0].tr_cmd_tx_header[0]
    CYHAL_TRIGGER_CXPI0_TR_CMD_TX_HEADER1 = 159, //!< EVTGEN CXPI triggers - cxpi[0].tr_cmd_tx_header[1]
    CYHAL_TRIGGER_CXPI0_TR_CMD_TX_HEADER2 = 160, //!< EVTGEN CXPI triggers - cxpi[0].tr_cmd_tx_header[2]
    CYHAL_TRIGGER_CXPI0_TR_CMD_TX_HEADER3 = 161, //!< EVTGEN CXPI triggers - cxpi[0].tr_cmd_tx_header[3]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER0 = 162, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[0]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER1 = 163, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[1]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER2 = 164, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[2]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER3 = 165, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[3]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER4 = 166, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[4]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER5 = 167, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[5]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER6 = 168, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[6]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER7 = 169, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[7]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER8 = 170, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[8]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER9 = 171, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[9]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER10 = 172, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[10]
    CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER11 = 173, //!< TCPWM to LIN - lin[0].tr_cmd_tx_header[11]
    CYHAL_TRIGGER_PASS0_TR_DEBUG_FREEZE = 174, //!< Debug Multiplexer - pass[0].tr_debug_freeze
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN0 = 175, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[0]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN1 = 176, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[1]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN2 = 177, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[2]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN3 = 178, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[3]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN4 = 179, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[4]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN5 = 180, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[5]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN6 = 181, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[6]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN7 = 182, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[7]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN8 = 183, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[8]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN9 = 184, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[9]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN10 = 185, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[10]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN11 = 186, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[11]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN12 = 187, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[12]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN13 = 188, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[13]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN14 = 189, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[14]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN15 = 190, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[15]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN16 = 191, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[16]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN17 = 192, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[17]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN18 = 193, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[18]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN19 = 194, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[19]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN20 = 195, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[20]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN21 = 196, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[21]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN22 = 197, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[22]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN23 = 198, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[23]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN32 = 199, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[32]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN33 = 200, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[33]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN34 = 201, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[34]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN35 = 202, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[35]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN36 = 203, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[36]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN37 = 204, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[37]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN38 = 205, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[38]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN39 = 206, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[39]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN40 = 207, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[40]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN41 = 208, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[41]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN42 = 209, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[42]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN43 = 210, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[43]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN44 = 211, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[44]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN45 = 212, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[45]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN46 = 213, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[46]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN47 = 214, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[47]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN48 = 215, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[48]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN49 = 216, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[49]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN50 = 217, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[50]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN51 = 218, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[51]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN52 = 219, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[52]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN53 = 220, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[53]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN54 = 221, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[54]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN55 = 222, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[55]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN56 = 223, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[56]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN57 = 224, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[57]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN58 = 225, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[58]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN59 = 226, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[59]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN60 = 227, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[60]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN61 = 228, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[61]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN62 = 229, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[62]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN63 = 230, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[63]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN64 = 231, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[64]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN65 = 232, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[65]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN66 = 233, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[66]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN67 = 234, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[67]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN68 = 235, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[68]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN69 = 236, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[69]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN70 = 237, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[70]
    CYHAL_TRIGGER_PASS0_TR_SAR_CH_IN71 = 238, //!< PWM Group 0 to PASS direct connect - pass[0].tr_sar_ch_in[71]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN0 = 239, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[0]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN1 = 240, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[1]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN2 = 241, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[2]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN3 = 242, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[3]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN4 = 243, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[4]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN5 = 244, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[5]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN6 = 245, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[6]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN7 = 246, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[7]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN8 = 247, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[8]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN9 = 248, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[9]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN10 = 249, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[10]
    CYHAL_TRIGGER_PASS0_TR_SAR_GEN_IN11 = 250, //!< PASS trigger multiplexer - pass[0].tr_sar_gen_in[11]
    CYHAL_TRIGGER_PERI_TR_DBG_FREEZE = 251, //!< Debug Multiplexer - peri.tr_dbg_freeze
    CYHAL_TRIGGER_PERI_TR_IO_OUTPUT0 = 252, //!< Debug Multiplexer - peri.tr_io_output[0]
    CYHAL_TRIGGER_PERI_TR_IO_OUTPUT1 = 253, //!< Debug Multiplexer - peri.tr_io_output[1]
    CYHAL_TRIGGER_SRSS_TR_DEBUG_FREEZE_MCWDT0 = 254, //!< Debug Multiplexer - srss.tr_debug_freeze_mcwdt[0]
    CYHAL_TRIGGER_SRSS_TR_DEBUG_FREEZE_MCWDT1 = 255, //!< Debug Multiplexer - srss.tr_debug_freeze_mcwdt[1]
    CYHAL_TRIGGER_SRSS_TR_DEBUG_FREEZE_WDT = 256, //!< Debug Multiplexer - srss.tr_debug_freeze_wdt
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN0 = 257, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[0]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN1 = 258, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[1]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN2 = 259, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[2]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN3 = 260, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[3]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN4 = 261, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[4]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN5 = 262, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[5]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN6 = 263, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[6]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN7 = 264, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[7]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN8 = 265, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[8]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN9 = 266, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[9]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN10 = 267, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[10]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN11 = 268, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[11]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN12 = 269, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[12]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN13 = 270, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[13]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN14 = 271, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[14]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN15 = 272, //!< TCPWM loopback mux - tcpwm[0].tr_all_cnt_in[15]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN16 = 273, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[16]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN17 = 274, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[17]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN18 = 275, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[18]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN19 = 276, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[19]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN20 = 277, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[20]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN21 = 278, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[21]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN22 = 279, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[22]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN23 = 280, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[23]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN24 = 281, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[24]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN25 = 282, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[25]
    CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN26 = 283, //!< TCPWM Trigger Multiplexer - tcpwm[0].tr_all_cnt_in[26]
    CYHAL_TRIGGER_TCPWM0_TR_DEBUG_FREEZE = 284, //!< Debug Multiplexer - tcpwm[0].tr_debug_freeze
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN2 = 285, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[2]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN5 = 286, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[5]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN8 = 287, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[8]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN11 = 288, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[11]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN14 = 289, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[14]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN17 = 290, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[17]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN20 = 291, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[20]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN23 = 292, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[23]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN26 = 293, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[26]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN29 = 294, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[29]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN32 = 295, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[32]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN35 = 296, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[35]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN38 = 297, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[38]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN41 = 298, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[41]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN44 = 299, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[44]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN47 = 300, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[47]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN50 = 301, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[50]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN53 = 302, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[53]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN56 = 303, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[56]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN59 = 304, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[59]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN62 = 305, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[62]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN65 = 306, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[65]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN68 = 307, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[68]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN71 = 308, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[71]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN74 = 309, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[74]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN77 = 310, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[77]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN80 = 311, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[80]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN83 = 312, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[83]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN86 = 313, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[86]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN89 = 314, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[89]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN92 = 315, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[92]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN95 = 316, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[95]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN98 = 317, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[98]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN101 = 318, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[101]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN104 = 319, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[104]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN107 = 320, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[107]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN110 = 321, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[110]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN113 = 322, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[113]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN116 = 323, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[116]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN119 = 324, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[119]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN122 = 325, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[122]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN125 = 326, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[125]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN128 = 327, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[128]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN131 = 328, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[131]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN134 = 329, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[134]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN137 = 330, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[137]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN140 = 331, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[140]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN143 = 332, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[143]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN146 = 333, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[146]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN149 = 334, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[149]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN152 = 335, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[152]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN155 = 336, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[155]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN770 = 337, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[770]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN773 = 338, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[773]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN776 = 339, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[776]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN779 = 340, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[779]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN782 = 341, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[782]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN785 = 342, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[785]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN788 = 343, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[788]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN791 = 344, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[791]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN794 = 345, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[794]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN797 = 346, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[797]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN800 = 347, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[800]
    CYHAL_TRIGGER_TCPWM0_TR_ONE_CNT_IN803 = 348, //!< PASS to PWM direct connect - tcpwm[0].tr_one_cnt_in[803]
    CYHAL_TRIGGER_TR_GROUP8_INPUT1 = 349, //!< Debug Reduction #1 - tr_group[8].input[1]
    CYHAL_TRIGGER_TR_GROUP8_INPUT2 = 350, //!< Debug Reduction #1 - tr_group[8].input[2]
    CYHAL_TRIGGER_TR_GROUP8_INPUT3 = 351, //!< Debug Reduction #1 - tr_group[8].input[3]
    CYHAL_TRIGGER_TR_GROUP8_INPUT4 = 352, //!< Debug Reduction #1 - tr_group[8].input[4]
    CYHAL_TRIGGER_TR_GROUP8_INPUT5 = 353, //!< Debug Reduction #1 - tr_group[8].input[5]
    CYHAL_TRIGGER_TR_GROUP8_INPUT6 = 354, //!< Debug Reduction #2 - tr_group[8].input[6]
    CYHAL_TRIGGER_TR_GROUP8_INPUT7 = 355, //!< Debug Reduction #2 - tr_group[8].input[7]
    CYHAL_TRIGGER_TR_GROUP8_INPUT8 = 356, //!< Debug Reduction #2 - tr_group[8].input[8]
    CYHAL_TRIGGER_TR_GROUP8_INPUT9 = 357, //!< Debug Reduction #2 - tr_group[8].input[9]
    CYHAL_TRIGGER_TR_GROUP8_INPUT10 = 358, //!< Debug Reduction #2 - tr_group[8].input[10]
} cyhal_trigger_dest_tviibe4m_t;

/** Typedef from device family specific trigger dest to generic trigger dest */
typedef cyhal_trigger_dest_tviibe4m_t cyhal_dest_t;

/** \cond INTERNAL */
/** Table of number of inputs to each mux. */
extern const uint16_t cyhal_sources_per_mux[22];

/** Table indicating whether mux is 1to1. */
extern const bool cyhal_is_mux_1to1[22];

/** Table pointing to each mux source table. The index of each source in the table is its mux input index. */
extern const _cyhal_trigger_source_tviibe4m_t* cyhal_mux_to_sources [22];

/** Maps each cyhal_destination_t to a mux index.
 * If bit 8 of the mux index is set, this denotes that the trigger is a
 * one to one trigger.
 */
extern const uint8_t cyhal_dest_to_mux[359];

/* Maps each cyhal_destination_t to a specific output in its mux */
extern const uint8_t cyhal_mux_dest_index[359];
/** \endcond */

#if defined(__cplusplus)
}
#endif /* __cplusplus */
/** \} group_hal_impl_triggers_tviibe4m */
#endif /* _CYHAL_TRIGGERS_TVIIBE4M_H_ */


/* [] END OF FILE */
