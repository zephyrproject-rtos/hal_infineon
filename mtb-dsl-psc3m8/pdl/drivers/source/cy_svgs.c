/***************************************************************************//**
* \file cy_svgs.c
* \version 1.0
*
* \brief
* Provides an API definition of the SVGS driver
*
********************************************************************************
* \copyright
* (c) 2025-2026, Infineon Technologies AG or an affiliate of
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

#include "cy_device.h"

#if defined (CY_IP_MXS40SVGS) || defined (CY_IP_MXS22SVGS)

#include "cy_svgs.h"

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
* Function Name: Cy_SVGS_GetCmpCfg
****************************************************************************//**
*
* Reads the SVGS comparator configuration (read-only).
*
* \param base
* Pointer to structure describing registers
*
* \param cfg
* Pointer to structure used to populate the configuration data
*
*******************************************************************************/
void Cy_SVGS_GetCmpCfg (const SVGS_Type *base, cy_stc_svgs_cmp_cfg_t *cfg)
{
    CY_ASSERT_L1(NULL != cfg);
    uint32_t cmp_cfg_reg = base->SVGS_MAIN.SVGS_CMP_CFG_RO;

    cfg->uvcCfg.enable = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_UVC_EN, cmp_cfg_reg);
    cfg->uvcCfg.fullPower = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_UVC_PWR, cmp_cfg_reg);
    cfg->uvcCfg.mask = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_UVC_MASK, cmp_cfg_reg);

    cfg->ovcCfg.enable = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_OVC_EN, cmp_cfg_reg);
    cfg->ovcCfg.fullPower = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_OVC_PWR, cmp_cfg_reg);
    cfg->ovcCfg.mask = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_OVC_MASK, cmp_cfg_reg);

    cfg->uvfcCfg.enable = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_UVFC_EN, cmp_cfg_reg);
    cfg->uvfcCfg.fullPower = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_UVFC_PWR, cmp_cfg_reg);
    cfg->uvfcCfg.mask = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_UVFC_MASK, cmp_cfg_reg);

    cfg->nvcCfg.enable = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_NVC_EN, cmp_cfg_reg);
    cfg->nvcCfg.fullPower = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_NVC_PWR, cmp_cfg_reg);
    cfg->nvcCfg.mask = _FLD2BOOL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_NVC_MASK, cmp_cfg_reg);

    uint32_t uvfcTc = _FLD2VAL(SVGS_SVGS_MAIN_SVGS_CMP_CFG_RO_SVGS_UVFC_TC, cmp_cfg_reg);
    cfg->uvfcTc = (cy_en_svgs_uvfc_tc_t)(uvfcTc);
}

/*******************************************************************************
* Function Name: Cy_SVGS_GetCmpTrip
****************************************************************************//**
*
* Reads the SVGS comparator trip-point configuration (read-only).
*
* \param base
* Pointer to structure describing registers
*
* \param trip
* Pointer to structure used to populate the trip-point data
*
*******************************************************************************/
void Cy_SVGS_GetCmpTrip (const SVGS_Type *base, cy_stc_svgs_cmp_trip_t *trip)
{
    CY_ASSERT_L1(NULL != trip);
    uint32_t cmp_trip_reg = base->SVGS_MAIN.SVGS_CMP_TRIP_RO;
    trip->uvcTrip = _FLD2VAL(SVGS_SVGS_MAIN_SVGS_CMP_TRIP_RO_SVGS_UVC_TRIP, cmp_trip_reg);
    trip->ovcTrip = _FLD2VAL(SVGS_SVGS_MAIN_SVGS_CMP_TRIP_RO_SVGS_OVC_TRIP, cmp_trip_reg);
    trip->uvfcTrip = _FLD2VAL(SVGS_SVGS_MAIN_SVGS_CMP_TRIP_RO_SVGS_UVFC_TRIP, cmp_trip_reg);
    trip->nvcTrip = _FLD2VAL(SVGS_SVGS_MAIN_SVGS_CMP_TRIP_RO_SVGS_NVC_TRIP, cmp_trip_reg);
}

/*******************************************************************************
* Function Name: Cy_SVGS_GetTrim
****************************************************************************//**
*
* Reads the SVGS trim values
*
* \param base
* Pointer to structure describing registers
*
* \param trim
* Pointer to structure used to populate the trim data
*
*******************************************************************************/
void Cy_SVGS_GetTrim (const SVGS_Type *base, cy_stc_svgs_trim_t *trim)
{
    CY_ASSERT_L1(NULL != trim);
    uint32_t trim_reg = base->SVGS_MAIN.SVGS_TRIM_RO;
    trim->vregTrim = _FLD2VAL(SVGS_SVGS_MAIN_SVGS_TRIM_RO_SVGS_VREG_TRIM, trim_reg);
    trim->ibiasTrim = _FLD2VAL(SVGS_SVGS_MAIN_SVGS_TRIM_RO_SVGS_IBIAS_TRIM, trim_reg);
}

#if defined(__cplusplus)
}
#endif

#endif /* #if defined (CY_IP_MXS40SVGS) || defined (CY_IP_MXS22SVGS) */

/* [] END OF FILE */
