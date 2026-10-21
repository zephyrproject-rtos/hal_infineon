/***************************************************************************//**
* \file cy_usbpd_mux.h
* \version 2.110
*
* Provides API declarations of the USBPD MUX Control driver.
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

#ifndef _CY_USBPD_MUX_H_
#define _CY_USBPD_MUX_H_

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

#include <cy_usbpd_common.h>
#include <cy_usbpd_typec.h>

/**
* \addtogroup group_usbpd_mux
* \{
* USBPD MUX Control driver.
*
* \defgroup group_usbpd_mux_functions Functions
*/

/*******************************************************************************
*                            Enumerated Types
*******************************************************************************/

/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_usbpd_mux_functions
* \{
*/
#if defined(CY_DEVICE_CCG6DF_CFP)
cy_en_usbpd_status_t Cy_USBPD_Mux_FuncModeEnDis(cy_stc_usbpd_context_t *context, bool enable);

void Cy_USBPD_Mux_SetLsTxDir(cy_stc_usbpd_context_t *context, bool tx_mode);

cy_en_usbpd_status_t Cy_USBPD_Mux_LsTermConfigure(cy_stc_usbpd_context_t *context, bool lsTxTermEn, bool lsRxTermEn);
#endif /* CY_DEVICE_CCG6DF_CFP */

cy_en_usbpd_status_t Cy_USBPD_Mux_ConfigDpDm(cy_stc_usbpd_context_t *context, cy_en_usbpd_dpdm_mux_cfg_t conf);

cy_en_usbpd_status_t Cy_USBPD_Mux_SbuSwitchConfigure(cy_stc_usbpd_context_t *context,
                                                     cy_en_usbpd_sbu_switch_state_t sbu1State, 
                                                     cy_en_usbpd_sbu_switch_state_t sbu2State);
                                                      
cy_en_usbpd_status_t Cy_USBPD_Mux_AuxTermConfigure(cy_stc_usbpd_context_t *context,
                                   cy_en_usbpd_aux_resistor_config_t aux1Config,
                                   cy_en_usbpd_aux_resistor_config_t aux2Config);

cy_en_usbpd_status_t Cy_USBPD_Mux_SbuAdftEnable(cy_stc_usbpd_context_t *context,
                                   cy_en_usbpd_sbu_adft_input_t adftInput);

void Cy_USBPD_Mux_SbuAdftDisable(cy_stc_usbpd_context_t *context);

/** \} group_usbpd_mux_functions */

/** \} group_usbpd_mux */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_MUX_H_ */

/* [] END OF FILE */
