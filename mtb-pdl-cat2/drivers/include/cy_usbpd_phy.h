/***************************************************************************//**
* \file cy_usbpd_phy.h
* \version 2.110
*
* Provides API declarations of the USBPD transceiver driver.
*
********************************************************************************
* \copyright
* (c) (2022 - 2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _CY_USBPD_PHY_H_
#define _CY_USBPD_PHY_H_

#include "cy_usbpd_common.h"

/**
* \addtogroup group_usbpd_phy
* \{
* USBPD Phy transceiver driver.
*
* \defgroup group_usbpd_phy_functions Functions
*/

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_usbpd_phy_functions
* \{
*/

cy_en_usbpd_status_t Cy_USBPD_Phy_Init(cy_stc_usbpd_context_t *context, cy_cb_usbpd_phy_handle_events_t phyCbk);

void Cy_USBPD_Phy_RefreshRoles(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Phy_LoadMsg(cy_stc_usbpd_context_t *context, cy_en_pd_sop_t sop, uint8_t retries,
        uint8_t dobjCount, uint32_t header, bool unchunked, uint32_t* buf);
        
void Cy_USBPD_Phy_Reset_RxTx_SM(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Phy_SendMsg(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Phy_SendBIST_Cm2(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Phy_AbortBIST_Cm2(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Phy_AbortTxMsg(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Phy_SendReset(cy_stc_usbpd_context_t *context, cy_en_pd_sop_t sop);

void Cy_USBPD_Intr0RxTxHandler(cy_stc_usbpd_context_t *context);
cy_stc_pd_packet_extd_t *Cy_USBPD_Phy_GetRxPacket(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Intr0Handler(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Phy_IsBusy(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Phy_EnRx(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Phy_DisRx (cy_stc_usbpd_context_t *context, uint8_t hardResetEn);

void Cy_USBPD_Phy_EnUnchunkedTx (cy_stc_usbpd_context_t *context);

void Cy_USBPD_Phy_DisUnchunkedTx (cy_stc_usbpd_context_t *context);

void Cy_USBPD_Phy_DisRxTx(cy_stc_usbpd_context_t *context);

/** \} group_usbpd_phy_functions */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_PHY_H_ */

/** \} group_usbpd_phy */

/* [] END OF FILE */
