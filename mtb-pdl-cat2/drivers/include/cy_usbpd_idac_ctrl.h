/***************************************************************************//**
* \file cy_usbpd_idac_ctrl.h
* \version 2.110
*
* Provides API declarations of the USBPD IDAC Control driver.
*
********************************************************************************
* \copyright
* (c) (2021-2025), Cypress Semiconductor Corporation (an Infineon company) or
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
#ifndef _CY_USBPD_IDAC_CTRL_H_
#define _CY_USBPD_IDAC_CTRL_H_

#include "cy_usbpd_common.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

/**
* \addtogroup group_usbpd_idac_ctrl
* \{
* USBPD IDAC Control driver.
*
* \defgroup group_usbpd_idac_ctrl_macros Macro
* \defgroup group_usbpd_idac_ctrl_functions Functions
*/

/**
* \addtogroup group_usbpd_idac_ctrl_macros
* \{
*/

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    

/** Error amplifier current reference gain trim location for PDAC. */
#define EA_IREF_GAIN_PDAC(port) (*(volatile uint8_t *)((0x0ffff46cu) + \
    (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
/** Error amplifier current reference gain trim location for NDAC. */
#define EA_IREF_GAIN_NDAC(port) (*(volatile uint8_t *)((0x0ffff46du) + \
    (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
/** Fixed Gain settings */
#define CC_GAIN_80                              (80u)
/** Fixed Gain settings */
#define CC_GAIN_80_AV1_VALUE                    (4u)
/** Fixed Gain settings */
#define CC_GAIN_60                              (60u)
/** Fixed Gain settings */
#define CC_GAIN_60_AV1_VALUE                    (2u)

#else /* CCGx */

/** Error amplifier current reference gain trim location for PDAC. */
#define EA_IREF_GAIN_PDAC       (*(volatile uint8_t *)(0x0ffff2a4u))
/** Error amplifier current reference gain trim location for NDAC. */
#define EA_IREF_GAIN_NDAC       (*(volatile uint8_t *)(0x0ffff2a5u))
#endif /* CCGx */

/** \} group_usbpd_idac_ctrl_macros */


/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_usbpd_idac_ctrl_functions
* \{
*/

void Cy_USBPD_Calc_Cabl_Gain(cy_stc_usbpd_context_t *context, uint32_t cur, uint8_t *gain_sel);

void Cy_USBPD_CSA_Calc_Ref(cy_stc_usbpd_context_t *context, uint32_t cur_10mA, uint8_t gain, uint32_t *vref_sel, bool vin_rsense);

void Cy_USBPD_PFC_StopComp(cy_stc_usbpd_context_t *context);

void Cy_USBPD_SR_StopComp(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_PFC_SetComp(cy_stc_usbpd_context_t *context, uint32_t cur,
        cy_usbpd_vbus_filter_edge_detect_cfg_t edge, cy_pd_cmp_cbk_t cbk);

bool Cy_USBPD_SR_SetComp(cy_stc_usbpd_context_t *context, uint32_t cur,
        cy_usbpd_vbus_filter_edge_detect_cfg_t edge, cy_pd_cmp_cbk_t cbk);

uint16_t Cy_USBPD_Hal_MeasureCur(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Hal_Disable_CV(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Hal_Enable_CV(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Hal_Set_Fb_Dac(cy_stc_usbpd_context_t *context, int16_t dac_value);

int16_t Cy_USBPD_Hal_Get_Fb_Dac(cy_stc_usbpd_context_t *context);

uint8_t Cy_USBPD_Get_Silicon_Rev(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_CF_GetStatus(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_PFC_CompSample(cy_stc_usbpd_context_t *context, uint32_t cur);

void Cy_USBPD_LSCSA_Calc_Cfg(cy_stc_usbpd_context_t *context, uint32_t cur_10mA, uint8_t *gain_sel, uint32_t *vref_sel);

cy_en_usbpd_status_t Cy_USBPD_LSCSA_Config(cy_stc_usbpd_context_t *context, cy_en_usbpd_vbus_lscsa_app_config_t lscsa_app, uint32_t gain_sel_value);

void Cy_USBPD_CF_Mon_Enable(cy_stc_usbpd_context_t *context, bool reset_state, cy_vbus_cf_cbk_t cbk);

void Cy_USBPD_CF_Mon_Disable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_CF_Enable(cy_stc_usbpd_context_t *context, uint32_t cur);

void Cy_USBPD_CF_Disable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_PFC_Intr1Handler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_SR_Intr1Handler(cy_stc_usbpd_context_t *context);

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S)) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)

void Cy_USBPD_Vbus_Slow_DischargeOnProcess(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_Slow_DischargeOffProcess(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_Slow_DischargeCbk(uint16_t id, void *callbackContext);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S)) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

void Cy_USBPD_VBTR_Start(cy_stc_usbpd_context_t *context);

void Cy_USBPD_VBTR_Config(cy_stc_usbpd_context_t *context, int16_t dac_cur, int16_t dac_req, cy_cb_adc_events_t vbtr_cb);

bool Cy_USBPD_VBTR_IsIdle(cy_stc_usbpd_context_t *context);

void Cy_USBPD_VBTR_SetIdac(cy_stc_usbpd_context_t *context, int16_t dac_req, cy_cb_adc_events_t vbtr_cb);

void Cy_USBPD_VBTR_Abort(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_IBTR_IsIdle(cy_stc_usbpd_context_t *context);

void Cy_USBPD_IBTR_Set(cy_stc_usbpd_context_t *context, uint16_t refgen_req, cy_cb_adc_events_t ibtr_cb);

void Cy_USBPD_IBTR_Abort(cy_stc_usbpd_context_t *context);

/** \} group_usbpd_idac_ctrl_functions */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_IDAC_CTRL_H_ */

/** \} group_usbpd_idac_ctrl */

/* [] END OF FILE */
