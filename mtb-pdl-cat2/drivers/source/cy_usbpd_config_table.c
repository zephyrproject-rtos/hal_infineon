/***************************************************************************//**
* \file cy_usbpd_config_table.c
* \version 2.110
*
* This file specifies helper functions to retrieve Configuration table data
* present in flash for various supported devices.
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

#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_usbpd_common.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

#include "cy_usbpd_defines.h"
#include "cy_usbpd_config_table.h"

#if CY_USE_CONFIG_TABLE

const auto_config_t * get_auto_config(cy_stc_usbpd_context_t *context)
{
    /* QAC suppression 0310, 3305: The correct pointer alignment is ensured by the placement
     * of this table as per the linker script. */
    return (const auto_config_t *)context->cfg_table; /* PRQA S 0310, 3305 */
}

const wireless_config_t * get_wireless_config(cy_stc_usbpd_context_t *context)
{
    /* QAC suppression 0310, 3305: The correct pointer alignment is ensured by the placement
     * of this table as per the linker script. */
    return (const wireless_config_t *)context->cfg_table; /* PRQA S 0310, 3305 */
}

const host_config_t * get_host_config(cy_stc_usbpd_context_t *context)
{
    /* QAC suppression 0310, 3305: The correct pointer alignment is ensured by the placement
     * of this table as per the linker script. */
    return (const host_config_t *)context->cfg_table; /* PRQA S 0310, 3305 */
}

const dock_config_t * get_dock_config(cy_stc_usbpd_context_t *context)
{
    /* QAC suppression 0310, 3305: The correct pointer alignment is ensured by the placement
     * of this table as per the linker script. */
    return (const dock_config_t *)context->cfg_table; /* PRQA S 0310, 3305 */
}

const pd_port_config_t * get_pd_port_config(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    return ((const pd_port_config_t *)((uint32_t)(const uint8_t *)(get_wireless_config (context)) +
            get_wireless_config(context)->port_0_config_offset));  /* PRQA S 0310, 3305 */
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    if(context->port==0u)
    {
    /* QAC suppression 0310, 3305: The correct pointer alignment is ensured by the placement
     * of this table as per the linker script. */
    return ((const pd_port_config_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                get_auto_config(context)->port_0_config_offset));  /* PRQA S 0310, 3305 */
    }
    else
    {
    return ((const pd_port_config_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                get_auto_config(context)->port_1_config_offset));
    }
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
#if (CY_CONFIG_TABLE_TYPE == CY_CONFIG_TABLE_HOST)
    if(context->port==0u)
    {
        /* QAC suppression 0310, 3305: The correct pointer alignment is ensured by the placement
         * of this table as per the linker script. */
        return ((const pd_port_config_t *)((uint32_t)(const uint8_t *)(get_host_config (context)) +
                    get_host_config(context)->port_0_config_offset));  /* PRQA S 0310, 3305 */
    }
    else
    {
        return ((const pd_port_config_t *)((uint32_t)(const uint8_t *)(get_host_config (context)) +
                    get_host_config(context)->port_1_config_offset));
    }
#elif (CY_CONFIG_TABLE_TYPE == CY_CONFIG_TABLE_DOCK)
    if(context->port==0u)
    {
        /* QAC suppression 0310, 3305: The correct pointer alignment is ensured by the placement
         * of this table as per the linker script. */
        return ((const pd_port_config_t *)((uint32_t)(const uint8_t *)(get_dock_config (context)) +
                get_dock_config(context)->port_0_config_offset));  /* PRQA S 0310, 3305 */
    }
    else
    {
        return ((const pd_port_config_t *)((uint32_t)(const uint8_t *)(get_dock_config (context)) +
                get_dock_config(context)->port_1_config_offset));
    }
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif /* (CY_CONFIG_TABLE_TYPE == CY_CONFIG_TABLE_DOCK) */
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif 
}

#if(defined(CY_DEVICE_SERIES_WLC1))

const cy_wireless_port_config * get_wireless_port_config(const void *cfgPtr)
{
    return ((const cy_wireless_port_config *)((uint32_t)(const uint8_t *)(cfgPtr) +
            ((const wireless_config_t *)(cfgPtr))->wireless_config_offset));  /* PRQA S 0310, 3305 */
}

const cy_stc_qi_main_cfg_t * get_wireless_main_config(const void *cfgPtr)
{
    return ((const cy_stc_qi_main_cfg_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
            get_wireless_port_config(cfgPtr)->qiMainTableOffset));  /* PRQA S 0310, 3305 */
}

const cy_stc_qi_coil_cfg_t * get_wireless_coil_config(const void *cfgPtr, uint8_t coilNum)
{
    if(coilNum == 0u)
    {
        return ((const cy_stc_qi_coil_cfg_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
        get_wireless_port_config(cfgPtr)->qiCoil0TableOffset));  /* PRQA S 0310, 3305 */
    }
    else if(coilNum == 1u)
    {
        return ((const cy_stc_qi_coil_cfg_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
        get_wireless_port_config(cfgPtr)->qiCoil1TableOffset));  /* PRQA S 0310, 3305 */
    }
    else if(coilNum == 2u)
    {
        return ((const cy_stc_qi_coil_cfg_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
        get_wireless_port_config(cfgPtr)->qiCoil2TableOffset));  /* PRQA S 0310, 3305 */
    }
    else if(coilNum == 3u)
    {
        return ((const cy_stc_qi_coil_cfg_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
        get_wireless_port_config(cfgPtr)->qiCoil3TableOffset));  /* PRQA S 0310, 3305 */
    }
    else
    {
        /*Return COIL 0 Parameters if no number is sent */
        return ((const cy_stc_qi_coil_cfg_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
        get_wireless_port_config(cfgPtr)->qiCoil0TableOffset));  /* PRQA S 0310, 3305 */
    }
}

const pwr_params_t * get_wireless_regulation_config(const void *cfgPtr, uint8_t coilNum)
{
    if(coilNum == 0u)
    {
        return ((const pwr_params_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
        (get_wireless_coil_config(cfgPtr, coilNum)->vbridgeRegTableoffset)));  /* PRQA S 0310, 3305 */
    }
    else
    {
        return ((const pwr_params_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
        (get_wireless_coil_config(cfgPtr, coilNum)->vbridgeRegTableoffset)));  /* PRQA S 0310, 3305 */
    }
}

const pwr_params_t * get_wireless_invbridge_config(const void *cfgPtr, uint8_t coilNum)
{
    if(coilNum == 0u)
    {
        return ((const pwr_params_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
        (get_wireless_coil_config(cfgPtr, coilNum)->invBridgeTableoffset)));  /* PRQA S 0310, 3305 */
    }
    else
    {
        return ((const pwr_params_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
        (get_wireless_coil_config(cfgPtr, coilNum)->invBridgeTableoffset)));  /* PRQA S 0310, 3305 */
    }
}

const cy_stc_fod_cfg_t * get_wireless_fod_config(const void *cfgPtr, uint8_t coilNum)
{
    if(coilNum == 0u)
    {
        return ((const cy_stc_fod_cfg_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
        (get_wireless_coil_config(cfgPtr, coilNum)->fodTableOffset)));  /* PRQA S 0310, 3305 */
    }
    else
    {
        return ((const cy_stc_fod_cfg_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
        (get_wireless_coil_config(cfgPtr, coilNum)->fodTableOffset)));  /* PRQA S 0310, 3305 */
    }
}

const cy_stc_vin_cfg_t * get_wireless_vin_config(const void *cfgPtr)
{
    return ((const cy_stc_vin_cfg_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
    (get_wireless_port_config(cfgPtr)->vinConfigTableOffset)));  /* PRQA S 0310, 3305 */
}

const cy_stc_fault_protect_cfg_t * get_wireless_fault_config(const void *cfgPtr)
{
    return ((const cy_stc_fault_protect_cfg_t *)((uint32_t)(const uint8_t *)((const wireless_config_t *)(cfgPtr)) +
    (get_wireless_port_config(cfgPtr)->faultProtectTableOffset)));  /* PRQA S 0310, 3305 */
}

#endif /* (defined(CY_DEVICE_SERIES_WLC1)) */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
auto_cfg_settings_t* pd_get_ptr_auto_cfg_tbl(cy_stc_usbpd_context_t *context)
{
    /* Update the Automotive charger settings from the configuration table*/
    return ((auto_cfg_settings_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
            get_auto_config(context)->auto_config_offset));
}
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)- || defined(CY_DEVICE_CCG3PA)) */
ovp_settings_t* pd_get_ptr_ovp_tbl(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    /* Update the OVP settings from the configuration table. */
    return ((ovp_settings_t *)(uint32_t)((const uint8_t *)(get_wireless_config (context)) +
                get_pd_port_config(context)->port_n_ovp_table_offset));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    /* Update the OVP settings from the configuration table. */
    return ((ovp_settings_t *)(uint32_t)((const uint8_t *)(get_auto_config (context)) +
                get_pd_port_config(context)->port_n_ovp_table_offset));
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Update the OVP settings from the configuration table. */
    return ((ovp_settings_t *)(uint32_t)((const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->port_n_ovp_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif
}

#if (BATTERY_CHARGING_ENABLE) || (QC_PPS_ENABLE)
cy_stc_legacy_charging_cfg_t* pd_get_ptr_chg_cfg_tbl(cy_stc_usbpd_context_t *context)
{
#if CCG_TYPE_A_PORT_ENABLE
    if (port == TYPE_A_PORT_ID)
    {
        /* Return parameters for TYPE-A port. */
        return pd_get_ptr_type_a_chg_cfg_tbl (0);
    }
#endif /* CCG_TYPE_A_PORT_ENABLE */
#if(defined(CY_DEVICE_SERIES_WLC1))
    return context->usbpdConfig->legacyChargingConfig;
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    /* Update the legacy charging parameters from the configuration table */
    return ((cy_stc_legacy_charging_cfg_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
            get_pd_port_config(context)->port_n_bch_table_offset));
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Update the legacy charging parameters from the configuration table */
    return ((cy_stc_legacy_charging_cfg_t *)((uint32_t)(const uint8_t *)context->cfg_table +
            get_pd_port_config(context)->port_n_bch_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif 
}
#endif /* (BATTERY_CHARGING_ENABLE) || (QC_PPS_ENABLE) */

rcp_settings_t* pd_get_ptr_rcp_tbl(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    return ((rcp_settings_t *)((uint32_t)(const uint8_t *)(get_wireless_config (context)) +
            get_pd_port_config(context)->port_n_rcp_table_offset));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    /* Update the VBus OCP settings from the configuration table */
    return ((rcp_settings_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                get_pd_port_config(context)->port_n_rcp_table_offset));
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Update the VBus OCP settings from the configuration table */
    return ((rcp_settings_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->port_n_rcp_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif 
}
ocp_settings_t* pd_get_ptr_ocp_tbl(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    /** Cast into  ocp_settings_t as a Workaround*/
    return ((ocp_settings_t *)(((cy_stc_usbpd_context_t *)context)->usbpdConfig->vbusOcpConfig));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    /* Update the VBus OCP settings from the configuration table */
    return ((ocp_settings_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                get_pd_port_config(context)->port_n_ocp_table_offset));
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Update the VBus OCP settings from the configuration table */
    return ((ocp_settings_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->port_n_ocp_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif 
}

scp_settings_t* pd_get_ptr_scp_tbl(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    /** Cast into  scp_settings_t as a Workaround*/
    return ((scp_settings_t *)(((cy_stc_usbpd_context_t *)context)->usbpdConfig->vbusScpConfig));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    /* Update the VBus SCP settings from the configuration table */
    return ((scp_settings_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                get_pd_port_config(context)->port_n_scp_table_offset));
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Update the VBus SCP settings from the configuration table */
    return ((scp_settings_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->port_n_scp_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif     
}

vconn_ocp_settings_t* pd_get_ptr_vconn_ocp_tbl(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    return ((vconn_ocp_settings_t *)((uint32_t)(const uint8_t *)(get_wireless_config (context)) +
            get_pd_port_config(context)->port_n_vconn_ocp_table_offset));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    /* Update the Vcon OCP settings from the configuration table */
    return ((vconn_ocp_settings_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                get_pd_port_config(context)->port_n_vconn_ocp_table_offset));
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Update the Vcon OCP settings from the configuration table */
    return ((vconn_ocp_settings_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->port_n_vconn_ocp_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif 
}

otp_settings_t* pd_get_ptr_otp_tbl(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    return ((otp_settings_t *)((uint32_t)(const uint8_t *)(get_wireless_config (context)) +
            get_pd_port_config(context)->port_n_otp_table_offset));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    /* Update the OTP settings from the configuration table */
    return ((otp_settings_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                get_pd_port_config(context)->port_n_otp_table_offset));
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Update the OTP settings from the configuration table */
    return ((otp_settings_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->port_n_otp_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif 
}

uvp_settings_t* pd_get_ptr_uvp_tbl(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    /** Cast into  uvp_settings_t as a Workaround*/
    return ((uvp_settings_t *)(((cy_stc_usbpd_context_t *)context)->usbpdConfig->vbusUvpConfig));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    /* Update the VBus UVP settings from the configuration table */
    return ((uvp_settings_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                get_pd_port_config(context)->port_n_uvp_table_offset));
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Update the VBus UVP settings from the configuration table */
    return ((uvp_settings_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->port_n_uvp_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif 
}

const cy_stc_pdstack_port_cfg_t* pd_get_ptr_pdstack_tbl(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    return ((const cy_stc_pdstack_port_cfg_t *)((uint32_t)(const uint8_t *)(get_wireless_config (context)) +
                get_pd_port_config(context)->port_n_pd_table_offset));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    return ((const cy_stc_pdstack_port_cfg_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                    get_pd_port_config(context)->port_n_pd_table_offset));
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    return ((const cy_stc_pdstack_port_cfg_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                    get_pd_port_config(context)->port_n_pd_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif 
}

pwr_params_t* pd_get_ptr_pwr_tbl(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    return ((pwr_params_t *)((uint32_t)(const uint8_t *)(get_wireless_regulation_config((context->cfg_table), 0))));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    /* Update the power parameters from the configuration table */
    return ((pwr_params_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                get_pd_port_config(context)->port_n_power_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif 
}

app_config_t* pd_get_ptr_app_tbl(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    return ((app_config_t *)((uint32_t)(const uint8_t *)(get_wireless_config (context)) +
            get_pd_port_config(context)->port_n_app_table_offset));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    /* Update the power parameters from the configuration table */
    return ((app_config_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                get_pd_port_config(context)->port_n_app_table_offset));
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Update the power parameters from the configuration table */
    return ((app_config_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->port_n_app_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif 
}

cy_stc_pdaltmode_cfg_settings_t* pd_get_ptr_base_alt_tbl(cy_stc_usbpd_context_t *context)
{
#if(defined(CY_DEVICE_SERIES_WLC1))
    return ((cy_stc_pdaltmode_cfg_settings_t *)((uint32_t)(const uint8_t *)(get_wireless_config (context)) +
            get_pd_port_config(context)->port_n_base_alt_mode_table_offset));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
    /* Update the Alt from the configuration table */
    return ((cy_stc_pdaltmode_cfg_settings_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
             get_pd_port_config(context)->port_n_base_alt_mode_table_offset));
#elif  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Update the Alt from the configuration table */
    return ((cy_stc_pdaltmode_cfg_settings_t *)((uint32_t)(const uint8_t *)context->cfg_table +
             get_pd_port_config(context)->port_n_base_alt_mode_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif 
}

cy_pd_pd_do_t* pd_get_ptr_disc_id(cy_stc_usbpd_context_t *context)
{
#if  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Return Disc ID pointer from base alt mode settings */
    return ((cy_pd_pd_do_t *)((uint32_t)(const uint8_t *)context->cfg_table +
            pd_get_ptr_base_alt_tbl(context)->disc_id_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif
}

cy_pd_pd_do_t* pd_get_ptr_disc_svid(cy_stc_usbpd_context_t *context)
{
#if  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Return Disc SVID pointer from base alt mode settings */
    return ((cy_pd_pd_do_t *)((uint32_t)(const uint8_t *)context->cfg_table +
            pd_get_ptr_base_alt_tbl(context)->disc_svid_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif
}

cy_pd_pd_do_t* pd_get_ptr_disc_mode(cy_stc_usbpd_context_t *context)
{
#if  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Return Disc MODE pointer from base alt mode settings */
    return ((cy_pd_pd_do_t *)((uint32_t)(const uint8_t *)context->cfg_table +
            pd_get_ptr_base_alt_tbl(context)->disc_mode_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif
}

cy_stc_pdaltmode_custom_alt_cfg_settings_t* pd_get_ptr_custom_alt_tbl(cy_stc_usbpd_context_t *context)
{
#if  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    return ((cy_stc_pdaltmode_custom_alt_cfg_settings_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->port_n_custom_alt_mode_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif
}

custom_host_cfg_settings_t* pd_get_ptr_custom_host_tbl(cy_stc_usbpd_context_t *context)
{
#if  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    return ((custom_host_cfg_settings_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->custom_host_config_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif
}

tbthost_cfg_settings_t* pd_get_ptr_tbt_host_tbl(cy_stc_usbpd_context_t *context)
{
#if  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    return ((tbthost_cfg_settings_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->port_n_tbt_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif
}

cy_stc_pdaltmode_dp_cfg_settings_t* pd_get_ptr_dp_config_tbl(cy_stc_usbpd_context_t *context)
{
#if  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    return ((cy_stc_pdaltmode_dp_cfg_settings_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                get_pd_port_config(context)->port_n_dp_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif
}

intel_soc_cfg_settings_t* pd_get_ptr_intel_soc_config_tbl(cy_stc_usbpd_context_t *context)
{
#if  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    return ((intel_soc_cfg_settings_t *)((uint32_t)(const uint8_t *)(get_host_config (context)) +
                get_pd_port_config(context)->port_n_soc_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif
}

amd_cfg_settings_t* pd_get_ptr_amd_config_tbl(cy_stc_usbpd_context_t *context)
{
#if  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    return ((amd_cfg_settings_t *)((uint32_t)(const uint8_t *)(get_host_config (context)) +
                get_pd_port_config(context)->amd_config_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif
}

mtk_cfg_settings_t* pd_get_ptr_mtk_config_tbl(cy_stc_usbpd_context_t *context)
{
#if  (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    return ((mtk_cfg_settings_t *)((uint32_t)(const uint8_t *)(get_host_config (context)) +
                get_pd_port_config(context)->mtk_config_table_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif
}
cy_stc_bb_settings_t* pd_get_ptr_bb_tbl(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG7D))
    /* Update the Alt from the configuration table */
    return ((cy_stc_bb_settings_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
            get_auto_config(context)->bb_offset));
#elif (defined(CY_DEVICE_PMG1S3))
    /* Update the Alt from the configuration table */
    return ((cy_stc_bb_settings_t *)((uint32_t)(const uint8_t *)(get_dock_config (context)) +
            get_dock_config(context)->bb_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif /* (defined(CY_DEVICE_CCG7D)) */
}


#if (defined(CY_DEVICE_CCG7D))
cy_stc_pdaltmode_dp_cfg_settings_t* pd_get_ptr_dp_tbl(cy_stc_usbpd_context_t *context)
{
    return ((cy_stc_pdaltmode_dp_cfg_settings_t *)((uint32_t)(const uint8_t *)(get_auto_config (context)) +
                    get_pd_port_config(context)->port_n_dp_table_offset));
}
#endif /* defined(CY_DEVICE_CCG7D) */

host_config_param_t* pd_get_ptr_host_config_param_tbl(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
#if (CY_CONFIG_TABLE_TYPE == CY_CONFIG_TABLE_HOST)
    return ((host_config_param_t *)((uint32_t)(const uint8_t *)context->cfg_table +
                    get_host_config(context)->host_config_offset));
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif /* (CY_CONFIG_TABLE_TYPE == CY_CONFIG_TABLE_HOST) */
#else
    CY_UNUSED_PARAMETER(context);
    return NULL;
#endif /* (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */
}

#endif /* CY_USE_CONFIG_TABLE */
#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */
