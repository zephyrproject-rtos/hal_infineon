/***************************************************************************//**
* \file cy_ble_common.c
* \version 3.60
*
* \brief
*  This file contains the source code for the API of the BLE PSoC 6 BLE Middleware.
*
********************************************************************************
* \copyright
* Copyright 2017-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if defined(COMPONENT_BLESS_HOST_IPC) || \
    defined(COMPONENT_BLESS_CONTROLLER) || defined(COMPONENT_BLESS_HOST)
#include "cycfg_ble.h"
#endif /* defined(COMPONENT_BLESS_CONTROLLER_IPC) || defined(COMPONENT_BLESS_HOST_IPC) ... */

#include "cy_ble_cfg_common.h"
#include "cy_ble_hal_pvt.h"

#if defined(CY_IP_MXBLESS) 


/******************************************************************************
* Function Name: Cy_BLE_Init
***************************************************************************//**
*
*  Initializes the PSoC 6 BLE Middleware.
*
*  \param config: The configuration structure for the PSoC 6 BLE Middleware.
*
*  \return
*  \ref cy_en_ble_api_result_t : Return value indicates if the function succeeded or
*   failed. The following are possible error codes.
*
*   Error codes                     | Description
*   ------------                    | -----------
*   CY_BLE_SUCCESS                  | The function completed successfully.
*   CY_BLE_ERROR_INVALID_PARAMETER  | On specifying NULL as the input parameter.
*
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_Init(const cy_stc_ble_config_t *config)
{
    cy_en_ble_api_result_t apiResult;

    #if (CY_BLE_STACK_IPC_CONTR_CORE) || (CY_BLE_MODE_HCI)

        /* Initializes the controller portion of the BLE (dual CPU mode) */
        apiResult = Cy_BLE_InitController(config);

    #else
    
        /* Initializes the host portion of the BLE (dual CPU mode) or full
         * (controller/host) in single CPU */
        apiResult = Cy_BLE_InitHost(config);

    #endif /* end stack mode condition */


    return(apiResult);
}


/******************************************************************************
* Function Name: Cy_BLE_Enable
***************************************************************************//**
*
*  Initializes and enable the BLE Stack.
*
*  Calling this function results in generation of a #CY_BLE_EVT_STACK_ON event
*  on successful initialization of the BLE Stack.
*
*  BLE Stack enables the BLE ECO clock automatically with the default
*  parameters:
*     Parameter            | Value
*     -------------------- | -----------
*     ECO Frequency        | CY_BLE_DEFAULT_ECO_FREQ
*     Divider              | CY_BLE_DEFAULT_ECO_DIV
*     Startup time         | CY_BLE_DEFAULT_OSC_STARTUP_DELAY_LF
*     Load cap             | CY_BLE_DEFAULT_CAP_TRIM_VALUE
*
*  If there is a need to start the BLE with non-default ECO parameters,
*  call the Cy_BLE_EcoConfigure() function with the custom configuration each
*  time before calling the Cy_BLE_Enable() function.
*
*  This function initializes the BLE Stack which consists of the BLE Stack
*  Manager, BLE Controller, and BLE Host modules. It takes care of initializing
*  the Profile layer, schedulers, Timer and other platform-related resources
*  required for the PSoC 6 BLE Middleware. It also registers the callback function
*  for BLE events that will be registered in the BLE stack.
*
*  Note that this function does not reset the BLE Stack.
*
*  For the HCI-Mode of operation, this function will not initialize the BLE Host
*  module.
*
*  Calling this function results in generation of a #CY_BLE_EVT_STACK_ON event
*  on successful initialization of the BLE Stack.
*
*  In the dual CPU mode, this function should be called on both cores in the
*  following sequence:
*   - call this function on CM0+ core to initialize the Controller.
*   - start CM4 core by calling Cy_SysEnableCM4() function.
*   - call this function on CM4 core to initialize the Host and Profiles.
*
*  NOTE: BLE requires a call to Cy_IPC_Sema_Init(), Cy_IPC_Pipe_Config(),
*    Cy_IPC_Pipe_Init() functions before use.
*    These functions are called in the SystemInit() function for proper flash write
*    and erase operations. If the default startup file is not used, or the function
*    SystemInit() is not called in your project, call the following functions:
*    -# Cy_IPC_Sema_Init()
*    -# Cy_IPC_Pipe_Config()
*    -# Cy_IPC_Pipe_Init()
*
* \return
* \ref cy_en_ble_api_result_t : Return value indicates if the function succeeded
*      or failed. The following are possible error codes.
*
*  <table>
*    <tr>
*      <th>Error codes</th>
*      <th>Description</th>
*    </tr>
*    <tr>
*      <td>CY_BLE_SUCCESS</td>
*      <td>On successful operation.</td>
*    </tr>
*    <tr>
*      <td>CY_BLE_ERROR_REPEATED_ATTEMPTS</td>
*      <td>On invoking this function more than once without calling
*          Cy_BLE_Disable() function between calls to this function.</td>
*    </tr>
*    <tr>
*      <td>CY_BLE_ERROR_MEMORY_ALLOCATION_FAILED</td>
*      <td>There is insufficient memory available.</td>
*    </tr>
*  </table>
*
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_Enable(void)
{
    cy_en_ble_api_result_t apiResult ;

#if (CY_BLE_STACK_IPC_CONTR_CORE)
    /* Registers IPC pipe callback. The PSoC 6 BLE Middleware when it
     * operates in BLE dual CPU mode. */
    apiResult = Cy_BLE_HAL_RegisterCommonPipeCallback();
    
#elif (CY_BLE_STACK_IPC_HOST_CORE)
    /* Enable BLE ECO clock with default configuration */
    apiResult = Cy_BLE_HAL_EnableDefaultEco();
    
    /* Enable BLE controller portion of BLE over IPC */
    if (apiResult == CY_BLE_SUCCESS)
    {
        apiResult = Cy_BLE_EnableControllerFromHost();
    }

    /* Enable BLE host portion of BLE over IPC */
    if (apiResult == CY_BLE_SUCCESS)
    {
        apiResult = Cy_BLE_EnableHost();
    }
    
#elif (CY_BLE_MODE_HCI)
    /* Start the Controller portion of the BLE (HCI mode) */
    apiResult = Cy_BLE_EnableHCIModeController();    

#else
    /* Enable BLE host portion of the BLE (single CPU mode) */
    apiResult = Cy_BLE_EnableHost();

#endif /* end stack mode condition */

    return(apiResult);
}


/******************************************************************************
* Function Name: Cy_BLE_Disable
***************************************************************************//**
*
*  This function stops any ongoing operation in the BLE Stack and forces the
*  BLE Stack to shut down.
*
*  Calling this function results in generation of a
*  #CY_BLE_EVT_STACK_SHUTDOWN_COMPLETE event on a successful stack shutdown.
*
*  For HCI mode:
*  This is a blocking function and no event is generated.
*  Only #CY_BLE_SUCCESS will be returned and other error codes are not applicable.
*  UART interface will be stopped and UART data will not be processed by stack
*  until Cy_BLE_Enable() is invoked.
*
* \return
* \ref cy_en_ble_api_result_t : Return value indicates if the function succeeded or
*  failed. The following are possible error codes.
*
*  <table>
*    <tr>
*      <th>Error codes</th>
*      <th>Description</th>
*    </tr>
*    <tr>
*      <td>CY_BLE_SUCCESS</td>
*      <td>On successful operation.</td>
*    </tr>
*    <tr>
*      <td>CY_BLE_ERROR_INVALID_OPERATION</td>
*      <td>On calling Cy_BLE_Disable before calling Cy_BLE_Enable()
*          or on Controller core.</td>
*    </tr>
*  </table>
*
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_Disable(void)
{
    cy_en_ble_api_result_t apiResult;

    #if (CY_BLE_STACK_IPC_CONTR_CORE) || (CY_BLE_MODE_HCI)

        /* To stop Controller (in dual CPU mode) call Cy_BLE_Disable()
         * function on Host core */
        apiResult = CY_BLE_SUCCESS;

    #else

        /* Stops all ongoing activities */
        apiResult = Cy_BLE_StackShutdown();

    #endif     /* CY_BLE_STACK_IPC_CONTR_CORE */

    return(apiResult);
}


/******************************************************************************
* Function Name: Cy_BLE_EnableLowPowerMode
***************************************************************************//**
*
*  This function enables BLE low power mode
*
******************************************************************************/
void Cy_BLE_EnableLowPowerMode(void)
{
    #if CY_BLE_STACK_IPC_HOST_CORE

        /* Enable LPM in BLE dual CPU mode (host) */
        Cy_BLE_EnableHostLowPowerMode();

    #elif CY_BLE_STACK_IPC_CONTR_CORE

        /* Enable LPM in BLE dual CPU mode (controller) */
        Cy_BLE_EnableControllerLowPowerMode();

    #else

        /* Enable LPM in BLE single CPU mode */
        Cy_BLE_EnableSystemLowPowerMode();

    #endif /* end stack mode condition */
}


/******************************************************************************
* Function Name: Cy_BLE_ServiceInit
***************************************************************************//**
*
*  Initializes all included services.
*
******************************************************************************/
void Cy_BLE_ServiceInit(void)
{
#if (CY_BLE_MODE_PROFILE)
    /* Init GAP/GATT server service */
    #if (CY_BLE_GATT_ROLE_SERVER)
    (void)Cy_BLE_GATTS_Init(&cy_ble_gattsConfig);
    (void)Cy_BLE_GAPS_Init(&cy_ble_gapsConfig);
    #endif /* (CY_BLE_GATT_ROLE_SERVER) */

    /* Init GAP/GATT client service */
    #if (CY_BLE_GATT_ROLE_CLIENT)
    (void)Cy_BLE_GATTC_Init(&cy_ble_gattcConfig);
    (void)Cy_BLE_GAPC_Init(&cy_ble_gapcConfig);
    #endif /* (CY_BLE_GATT_ROLE_SERVER) */

    /* Init ANCS service */
    #ifdef CY_BLE_ANCS_SERVER
    (void)Cy_BLE_ANCSS_Init(&cy_ble_ancssConfig);
    #endif /* CY_BLE_ANCS_SERVER */

    #ifdef CY_BLE_ANCS_CLIENT
    (void)Cy_BLE_ANCSC_Init(&cy_ble_ancscConfig);
    #endif /* CY_BLE_ANCS_CLIENT */

    /* Init ANS service */
    #ifdef CY_BLE_ANS_SERVER
    (void)Cy_BLE_ANSS_Init(&cy_ble_anssConfig);
    #endif /* CY_BLE_ANS_SERVER */

    #ifdef CY_BLE_ANS_CLIENT
    (void)Cy_BLE_ANSC_Init(&cy_ble_anscConfig);
    #endif /* CY_BLE_ANS_CLIENT */

    /* Init AIOS service */
    #ifdef CY_BLE_AIOS_SERVER
    (void)Cy_BLE_AIOSS_Init(&cy_ble_aiossConfig);
    #endif /* CY_BLE_AIOS_SERVER */

    #ifdef CY_BLE_AIOS_CLIENT
    (void)Cy_BLE_AIOSC_Init(&cy_ble_aioscConfig);
    #endif /* CY_BLE_AIOS_CLIENT */

    /* Init BAS service */
    #ifdef CY_BLE_BAS_SERVER
    (void)Cy_BLE_BASS_Init(&cy_ble_bassConfig);
    #endif /* CY_BLE_BAS_SERVER */

    #ifdef CY_BLE_BAS_CLIENT
    (void)Cy_BLE_BASC_Init(&cy_ble_bascConfig);
    #endif /* CY_BLE_BAS_CLIENT */

    /* Init BLS service */
    #ifdef CY_BLE_BLS_SERVER
    (void)Cy_BLE_BLSS_Init(&cy_ble_blssConfig);
    #endif /* CY_BLE_BLS_SERVER */

    #ifdef CY_BLE_BLS_CLIENT
    (void)Cy_BLE_BLSC_Init(&cy_ble_blscConfig);
    #endif /* CY_BLE_BLS_CLIENT */

    /* Init BCS service */
    #ifdef CY_BLE_BCS_SERVER
    (void)Cy_BLE_BCSS_Init(&cy_ble_bcssConfig);
    #endif /* CY_BLE_BLS_SERVER */

    #ifdef CY_BLE_BCS_CLIENT
    (void)Cy_BLE_BCSC_Init(&cy_ble_bcscConfig);
    #endif /* CY_BLE_BCS_CLIENT */

    /* Init BMS service */
    #ifdef CY_BLE_BMS_SERVER
    (void)Cy_BLE_BMSS_Init(&cy_ble_bmssConfig);
    #endif /* CY_BLE_BMS_SERVER */

    #ifdef CY_BLE_BMS_CLIENT
    (void)Cy_BLE_BMSC_Init(&cy_ble_bmscConfig);
    #endif /* CY_BLE_BMS_CLIENT */

     /* Init BTS service */
    #ifdef CY_BLE_BTS_SERVER
    (void)Cy_BLE_BTSS_Init(&cy_ble_btssConfig);
    #endif /* CY_BLE_BTS_SERVER */

    /* Init CGMS service */
    #ifdef CY_BLE_CGMS_SERVER
    (void)Cy_BLE_CGMSS_Init(&cy_ble_cgmssConfig);
    #endif /* CY_BLE_CGMS_SERVER */

    #ifdef CY_BLE_CGMS_CLIENT
    (void)Cy_BLE_CGMSC_Init(&cy_ble_cgmscConfig);
    #endif /* CY_BLE_CGMS_CLIENT */

    /* Init CPS service */
    #ifdef CY_BLE_CPS_SERVER
    (void)Cy_BLE_CPSS_Init(&cy_ble_cpssConfig);
    #endif /* CY_BLE_CPS_SERVER */

    #ifdef CY_BLE_CPS_CLIENT
    (void)Cy_BLE_CPSC_Init(&cy_ble_cpscConfig);
    #endif /* CY_BLE_CPS_CLIENT */

    /* Init CSCS service */
    #ifdef CY_BLE_CSCS_SERVER
    (void)Cy_BLE_CSCSS_Init(&cy_ble_cscssConfig);
    #endif /* CY_BLE_CSCS_SERVER */

    #ifdef CY_BLE_CSCS_CLIENT
    (void)Cy_BLE_CSCSC_Init(&cy_ble_cscscConfig);
    #endif /* CY_BLE_CSCS_CLIENT */

    /* Init CTS service */
    #ifdef CY_BLE_CTS_SERVER
    (void)Cy_BLE_CTSS_Init(&cy_ble_ctssConfig);
    #endif /* CY_BLE_CTS_SERVER */

    #ifdef CY_BLE_CTS_CLIENT
    (void)Cy_BLE_CTSC_Init(&cy_ble_ctscConfig);
    #endif /* CY_BLE_CTS_CLIENT */

    /* Init CUSTOM service */
    #ifdef CY_BLE_CUSTOM_SERVER
    (void)Cy_BLE_CUSTOMS_Init(&cy_ble_customsConfig);
    #endif /* CY_BLE_CUSTOM_SERVER */

    #ifdef CY_BLE_CUSTOM_CLIENT
    (void)Cy_BLE_CUSTOMC_Init(&cy_ble_customcConfig);
    #endif /* CY_BLE_CUSTOM_CLIENT */

    /* Init DIS service */
    #ifdef CY_BLE_DIS_SERVER
    (void)Cy_BLE_DISS_Init(&cy_ble_dissConfig);
    #endif /* CY_BLE_DIS_SERVER */

    #ifdef CY_BLE_DIS_CLIENT
    (void)Cy_BLE_DISC_Init(&cy_ble_discConfig);
    #endif /* CY_BLE_DIS_CLIENT */

    /* Init ESS service */
    #ifdef CY_BLE_ESS_SERVER
    (void)Cy_BLE_ESSS_Init(&cy_ble_esssConfig);
    #endif /* CY_BLE_ESS_SERVER */

    #ifdef CY_BLE_ESS_CLIENT
    (void)Cy_BLE_ESSC_Init(&cy_ble_esscConfig);
    #endif /* CY_BLE_ESS_CLIENT */

    /* Init GLS service */
    #ifdef CY_BLE_GLS_SERVER
    (void)Cy_BLE_GLSS_Init(&cy_ble_glssConfig);
    #endif /* CY_BLE_GLS_SERVER */

    #ifdef CY_BLE_GLS_CLIENT
    (void)Cy_BLE_GLSC_Init(&cy_ble_glscConfig);
    #endif /* CY_BLE_GLS_CLIENT */

    /* Init HID service */
    #ifdef CY_BLE_HIDS_SERVER
    (void)Cy_BLE_HIDSS_Init(&cy_ble_hidssConfig);
    #endif /* CY_BLE_HIDS_SERVER */

    #ifdef CY_BLE_HIDS_CLIENT
    (void)Cy_BLE_HIDSC_Init(&cy_ble_hidscConfig);
    #endif /* CY_BLE_HIDS_CLIENT */

    /* Init HPS service */
    #ifdef CY_BLE_HPS_SERVER
    (void)Cy_BLE_HPSS_Init(&cy_ble_hpssConfig);
    #endif /* CY_BLE_HPS_SERVER */

    #ifdef CY_BLE_HPS_CLIENT
    (void)Cy_BLE_HPSC_Init(&cy_ble_hpscConfig);
    #endif /* CY_BLE_HPS_CLIENT */

    /* Init HRS service */
    #ifdef CY_BLE_HRS_SERVER
    (void)Cy_BLE_HRSS_Init(&cy_ble_hrssConfig);
    #endif /* CY_BLE_HRS_SERVER */

    #ifdef CY_BLE_HRS_CLIENT
    (void)Cy_BLE_HRSC_Init(&cy_ble_hrscConfig);
    #endif /* CY_BLE_HRS_CLIENT */

    /* Init HTS service */
    #ifdef CY_BLE_HTS_SERVER
    (void)Cy_BLE_HTSS_Init(&cy_ble_htssConfig);
    #endif /* CY_BLE_HTS_SERVER */

    #ifdef CY_BLE_HTS_CLIENT
    (void)Cy_BLE_HTSC_Init(&cy_ble_htscConfig);
    #endif /* CY_BLE_HTS_CLIENT */

    /* Init IAS service */
    #ifdef CY_BLE_IAS_SERVER
    (void)Cy_BLE_IASS_Init(&cy_ble_iassConfig);
    #endif /* CY_BLE_IAS_SERVER */

    #ifdef CY_BLE_IAS_CLIENT
    (void)Cy_BLE_IASC_Init(&cy_ble_iascConfig);
    #endif /* CY_BLE_IAS_CLIENT */

    /* Init IPS service */
    #ifdef CY_BLE_IPS_SERVER
    (void)Cy_BLE_IPSS_Init(&cy_ble_ipssConfig);
    #endif /* CY_BLE_IPS_SERVER */

    #ifdef CY_BLE_IPS_CLIENT
    (void)Cy_BLE_IPSC_Init(&cy_ble_ipscConfig);
    #endif /* CY_BLE_IPS_CLIENT */

    /* Init LLS service */
    #ifdef CY_BLE_LLS_SERVER
    (void)Cy_BLE_LLSS_Init(&cy_ble_llssConfig);
    #endif /* CY_BLE_LLS_SERVER */

    #ifdef CY_BLE_LLS_CLIENT
    (void)Cy_BLE_LLSC_Init(&cy_ble_llscConfig);
    #endif /* CY_BLE_LLS_CLIENT */

    /* Init LNS service */
    #ifdef CY_BLE_LNS_SERVER
    (void)Cy_BLE_LNSS_Init(&cy_ble_lnssConfig);
    #endif /* CY_BLE_LNS_SERVER */

    #ifdef CY_BLE_LNS_CLIENT
    (void)Cy_BLE_LNSC_Init(&cy_ble_lnscConfig);
    #endif /* CY_BLE_LNS_CLIENT */

    /* Init NDCS service */
    #ifdef CY_BLE_NDCS_SERVER
    (void)Cy_BLE_NDCSS_Init(&cy_ble_ndcssConfig);
    #endif /* CY_BLE_NDCS_SERVER */

    #ifdef CY_BLE_NDCS_CLIENT
    (void)Cy_BLE_NDCSC_Init(&cy_ble_ndcscConfig);
    #endif /* CY_BLE_NDCS_CLIENT */

    /* Init PASS service */
    #ifdef CY_BLE_PASS_SERVER
    (void)Cy_BLE_PASSS_Init(&cy_ble_passsConfig);
    #endif /* CY_BLE_PASS_SERVER */

    #ifdef CY_BLE_PASS_CLIENT
    (void)Cy_BLE_PASSC_Init(&cy_ble_passcConfig);
    #endif /* CY_BLE_PASS_CLIENT */

    /* Init PLXS service */
    #ifdef CY_BLE_PLXS_SERVER
    (void)Cy_BLE_PLXSS_Init(&cy_ble_plxssConfig);
    #endif /* CY_BLE_PLXS_SERVER */

    #ifdef CY_BLE_PLXS_CLIENT
    (void)Cy_BLE_PLXSC_Init(&cy_ble_plxscConfig);
    #endif /* CY_BLE_PLXS_CLIENT */

    /* Init RSCS service */
    #ifdef CY_BLE_RSCS_SERVER
    (void)Cy_BLE_RSCSS_Init(&cy_ble_rscssConfig);
    #endif /* CY_BLE_RSCS_SERVER */

    #ifdef CY_BLE_RSCS_CLIENT
    (void)Cy_BLE_RSCSC_Init(&cy_ble_rscscConfig);
    #endif /* CY_BLE_RSCS_CLIENT */

    /* Init RTUS service */
    #ifdef CY_BLE_RTUS_SERVER
    (void)Cy_BLE_RTUSS_Init(&cy_ble_rtussConfig);
    #endif /* CY_BLE_RTUS_SERVER */

    #ifdef CY_BLE_RTUS_CLIENT
    (void)Cy_BLE_RTUSC_Init(&cy_ble_rtuscConfig);
    #endif /* CY_BLE_RTUS_CLIENT */

    /* Init SCPS service */
    #ifdef CY_BLE_SCPS_SERVER
    (void)Cy_BLE_SCPSS_Init(&cy_ble_scpssConfig);
    #endif /* CY_BLE_SCPS_SERVER */

    #ifdef CY_BLE_SCPS_CLIENT
    (void)Cy_BLE_SCPSC_Init(&cy_ble_scpscConfig);
    #endif /* CY_BLE_SCPS_CLIENT */

    /* Init TPS service */
    #ifdef CY_BLE_TPS_SERVER
    (void)Cy_BLE_TPSS_Init(&cy_ble_tpssConfig);
    #endif /* CY_BLE_TPS_SERVER */

    #ifdef CY_BLE_TPS_CLIENT
    (void)Cy_BLE_TPSC_Init(&cy_ble_tpscConfig);
    #endif /* CY_BLE_TPS_CLIENT */

     /* Init UDS service */
    #ifdef CY_BLE_UDS_SERVER
    (void)Cy_BLE_UDSS_Init(&cy_ble_udssConfig);
    #endif /* CY_BLE_UDS_SERVER */

    #ifdef CY_BLE_UDS_CLIENT
    (void)Cy_BLE_UDSC_Init(&cy_ble_udscConfig);
    #endif /* CY_BLE_UDS_CLIENT */

    /* Init WPTS service */
    #ifdef CY_BLE_WPTS_SERVER
    (void)Cy_BLE_WPTSS_Init(&cy_ble_wptssConfig);
    #endif /* CY_BLE_WPTS_SERVER */

    #ifdef CY_BLE_WPTS_CLIENT
    (void)Cy_BLE_WPTSC_Init(&cy_ble_wptscConfig);
    #endif /* CY_BLE_WPTS_CLIENT */

    /* Init WSS service */
    #ifdef CY_BLE_WSS_SERVER
    (void)Cy_BLE_WSSS_Init(&cy_ble_wsssConfig);
    #endif /* CY_BLE_WSS_SERVER */

    #ifdef CY_BLE_WSS_CLIENT
    (void)Cy_BLE_WSSC_Init(&cy_ble_wsscConfig);
    #endif /* CY_BLE_WSS_CLIENT */

    #ifdef CY_BLE_IPSS_CLIENT
    {
        uint32_t idx;
        for(idx = 0u; idx < CY_BLE_GATTC_COUNT; idx++)
        {
            cy_ble_serverInfo[idx][CY_BLE_SRVI_IPSS].uuid = CY_BLE_UUID_INTERNET_PROTOCOL_SUPPORT_SERVICE;
        }
    }
    #endif     /* CY_BLE_IPSS_CLIENT */
#endif /* (CY_BLE_MODE_PROFILE) */
}



/******************************************************************************
* Mapping Functions for stack size optimization  (internal usage only)
***************************************************************************//**/

void Cy_BLE_HAL_EccHeapInit(uint8_t *heapMem, uint8_t numOfConn)
{
    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        Cy_BLE_HAL_MappingEccHeapInit(heapMem, numOfConn);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */

    /* Suppress unused variable warning */
    (void) heapMem;
    (void) numOfConn;
}

void Cy_BLE_HAL_EccHeapDeInit(void)
{
    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        Cy_BLE_HAL_MappingEccHeapDeInit();
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

uint16_t Cy_BLE_HAL_EccGetFeatureHeapReq(uint8_t numOfConn)
{
    /* Suppress unused variable warning */
    (void) numOfConn;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingEccGetFeatureHeapReq(numOfConn));
    #else
        return(0u);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_EccGenerateSecurityKeypair(uint8_t p_publicKey[],
                                                             uint8_t p_privateKey[],
                                                             uint8_t randomData[])
{
    /* Suppress unused variable warning */
    (void) p_publicKey;
    (void) p_privateKey;
    (void) randomData;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingEccGenerateSecurityKeypair(p_publicKey, p_privateKey, randomData));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_EccGenerateDHKey(const uint8_t p_publicKey[],
                                                   const uint8_t p_privateKey[],
                                                   uint8_t p_secret[], uint8_t ci)
{
    /* Suppress unused variable warning */
    (void) p_publicKey;
    (void) p_privateKey;
    (void) p_secret;
    (void) ci;
    
    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingEccGenerateDHKey(p_publicKey, p_privateKey, p_secret, ci));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_EccValidPublicKey(const uint8_t p_publicKey[])
{
    /* Suppress unused variable warning */
    (void) p_publicKey;
    
    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingEccValidPublicKey(p_publicKey));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingLocalPublicKeyHandler(void *param)
{
    /* Suppress unused variable warning */
    (void) param;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingPairingLocalPublicKeyHandler(param));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingRemoteKeyHandler(void *param)
{
    /* Suppress unused variable warning */
    (void) param;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingPairingRemoteKeyHandler(param));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingDhkeyHandler(void *param)
{
    /* Suppress unused variable warning */
    (void) param;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingPairingDhkeyHandler(param));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingDhkeyCheckHandler(void *param)
{
    /* Suppress unused variable warning */
    (void) param;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingPairingDhkeyCheckHandler(param));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingKeypressNotificationHandler(void *param)
{
    /* Suppress unused variable warning */
    (void) param;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingPairingKeypressNotificationHandler(param));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingRandHandler(void *param)
{
    /* Suppress unused variable warning */
    (void) param;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingPairingRandHandler(param));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingConfirmHandler(void *param)
{
    /* Suppress unused variable warning */
    (void) param;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingPairingConfirmHandler(param));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingLrConfirmingHandler(void *param)
{
    /* Suppress unused variable warning */
    (void) param;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingPairingLrConfirmingHandler(param));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingScTbxDhkeyGenerateComplete(void *param)
{
    /* Suppress unused variable warning */
    (void) param;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        Cy_BLE_HAL_MappingTbxDhkeyGenerateComplete(param);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */

    return(CY_BLE_SUCCESS);
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingScTbxLocalPubkeyGenerateComplete(void *param)
{
    /* Suppress unused variable warning */
    (void) param;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        Cy_BLE_HAL_MappingTbxLocalPubkeyGenerateComplete(param);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */

    return(CY_BLE_SUCCESS);
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingScTbxGenerateLocalP256PublicKey(uint8_t param)
{
    /* Suppress unused variable warning */
    (void) param;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingTbxGenerateLocalP256PublicKey(param));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_PairingScTbxGenerateDHkey(void  *param1, void  *param2, uint8_t param3)
{
    /* Suppress unused variable warning */
    (void) param1;
    (void) param2;
    (void) param3;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingTbxGenerateDHkey(param1, param2, param3));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

void Cy_BLE_HAL_SmpScCmacComplete(uint8_t param)
{
    /* Suppress unused variable warning */
    (void) param;
    
    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        Cy_BLE_HAL_MappingSmpScCmacComplete(param);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

cy_en_ble_api_result_t Cy_BLE_HAL_SeSmpScUserPasskeyHandler(void *param1,
                                                            void *param2)
{
    /* Suppress unused variable warning */
    (void) param1;
    (void) param2;

    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        return(Cy_BLE_HAL_MappingSeSmpScUserPasskeyHandler(param1, param2));
    #else
        return(CY_BLE_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

void Cy_BLE_HAL_EccPointMult(uint8_t param)
{
    /* Suppress unused variable warning */
    (void) param;
    
    #if (CY_BLE_SECURE_CONN_FEATURE_ENABLED)
        Cy_BLE_HAL_MappingEccPointMult(param);
    #endif /* CY_BLE_SECURE_CONN_FEATURE_ENABLED */
}

/* Controller stack functions */
cy_en_ble_api_result_t Cy_BLE_MappingIsControllerActive(cy_en_ble_controller_sleep_mode_t checkForMode)
{
    /* Suppress unused variable warning */
    (void) checkForMode;
    
    #if CY_BLE_STACK_CONTR_CORE
        return(Cy_BLE_IsControllerActive(checkForMode));
    #else
        return(CY_BLE_SUCCESS);
    #endif /* CY_BLE_STACK_CONTR_CORE */

}
 
bool Cy_BLE_HAL_MappingBlessInterruptHandler(void)
{
    #if CY_BLE_STACK_CONTR_CORE
        return(Cy_BLE_HAL_BlessInterruptHandler());
    #else
        return(false);
    #endif /* CY_BLE_STACK_CONTR_CORE */
}
 
void Cy_BLE_MappingLlIsrExitLowPowerMode(void)
{
    #if (CY_BLE_STACK_CONTR_CORE)
        Cy_BLE_LlIsrExitLowPowerMode();
    #endif /* CY_BLE_STACK_CONTR_CORE */
}

void Cy_BLE_HAL_MappingUartRxDataHandler(uint8_t byte)
{
    /* Suppress unused variable warning */
    (void) byte;
    
    #if ((CY_BLE_STACK_CONTR_CORE) && (CY_BLE_MODE_HCI) && (CY_BLE_MODE_HCI_LEGACY))
        Cy_BLE_HAL_UartRxDataHandler(byte);
    #endif /* CY_BLE_STACK_CONTR_CORE */
}

void Cy_BLE_HAL_MappingUartTxCompltHandler(void)
{
    #if ((CY_BLE_STACK_CONTR_CORE) && (CY_BLE_MODE_HCI) && (CY_BLE_MODE_HCI_LEGACY))
        Cy_BLE_HAL_UartTxCompltHandler();
    #endif /* CY_BLE_STACK_CONTR_CORE */
}

void Cy_BLE_HAL_MappingSoftHciHostReceiveControllerPkt(cy_stc_ble_hci_tx_packet_info_t *hciPkt)
{
    /* Suppress unused variable warning */
    (void) hciPkt;

    #if (CY_BLE_MODE_PROFILE) && (CY_BLE_STACK_MODE_SOC)
        Cy_BLE_HAL_SoftHciHostReceiveControllerPkt(hciPkt);
    #endif /* (CY_BLE_MODE_PROFILE) && (CY_BLE_STACK_MODE_SOC) */
}

cy_en_ble_api_result_t Cy_BLE_HAL_MappingSoftHciControllerReceiveHostPkt(cy_stc_ble_hci_tx_packet_info_t *hciPkt)
{
    /* Suppress unused variable warning */
    (void) hciPkt;
    
    #if (CY_BLE_MODE_PROFILE) && (CY_BLE_STACK_MODE_SOC)
        return(Cy_BLE_HAL_SoftHciControllerReceiveHostPkt(hciPkt));
    #else
        return(CY_BLE_SUCCESS);    
    #endif /* (CY_BLE_MODE_PROFILE) && (CY_BLE_STACK_MODE_IPC) */
}

cy_en_ble_lp_mode_t Cy_BLE_MappingStackEnterLPM(cy_en_ble_lp_mode_t pwrMode)
{
    /* Suppress unused variable warning */
    (void) pwrMode;
    
    #if ( (CY_BLE_STACK_IPC_CONTR_CORE) || (CY_BLE_MODE_PROFILE) ||\
          ((CY_BLE_STACK_CONTR_CORE) && (CY_BLE_MODE_HCI) && (CY_BLE_MODE_HCI_LEGACY)) )
        return(Cy_BLE_StackEnterLPM(pwrMode));
    #elif ((CY_BLE_STACK_CONTR_CORE) && (CY_BLE_MODE_HCI) )
        return(Cy_BLE_ControllerEnterLPM(pwrMode));    
    #endif /* (CY_BLE_MODE_PROFILE) && (CY_BLE_STACK_MODE_IPC) */
}


#endif /* defined(CY_IP_MXBLESS) */

/* [] END OF FILE */
