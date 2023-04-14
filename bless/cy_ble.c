/***************************************************************************//**
* \file cy_ble.c
* \version 3.60
*
* \brief
*  This file contains the source code for the API of the PSoC 6 BLE Middleware.
*
********************************************************************************
* \copyright
* Copyright 2017-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <stdint.h>
#include "cy_ble_event_handler.h"
#include "cy_ble_hal_pvt.h"
#include "cy_ble.h"

#include "cy_ble_stack_pvt.h"

#if defined(CY_IP_MXBLESS)

#ifdef CY_BLE_WARNING_NO_SELECTED_BLESS_COMPONENTS
#warning The BLE Stack components are not defined in Makefile. Use COMPONENTS variable in Makefile   \
         to select BLE Stack component. The following COMPONENTS define patricular BLE Stack modes:  \
          'COMPONENTS+=BLESS_HOST_IPC CM0_BLESS'    - to operate in dual CPU mode,                   \
          'COMPONENTS+=BLESS_CONTROLLER BLESS_HOST' - to operate in single CPU mode,                 \
          'COMPONENTS+=BLESS_CONTROLLER'            - to operate in controller only (HCI) mode.      \
/* For more details refer to the following documentation:
 * https://cypresssemiconductorco.github.io/bless/ble_api_reference_manual/html/page_ble_section_configuration_considerations.html#group_ble_section_conf_cons_prebuild  */
#endif /* ifdef WARNING_NO_SELECTED_BLESS_COMPONENT */

/*******************************************************************************
* Private Function Prototypes
*******************************************************************************/

static void Cy_BLE_RegisterPmCallbacksSingle(void);
static void Cy_BLE_RegisterPmCallbacksDual(void);

static void Cy_BLE_UnregisterHostPmCallbacksSingle(void);
static void Cy_BLE_UnregisterHostPmCallbacksDual(void);

static cy_en_syspm_status_t Cy_BLE_DeepSleepCallbackSingleCore(cy_stc_syspm_callback_params_t *callbackParams,
        cy_en_syspm_callback_mode_t mode);
static cy_en_syspm_status_t Cy_BLE_DeepSleepCallbackDualCore(cy_stc_syspm_callback_params_t *callbackParams,
        cy_en_syspm_callback_mode_t mode);
static cy_en_syspm_status_t Cy_BLE_SleepCallbackDualCore(cy_stc_syspm_callback_params_t *callbackParams,
        cy_en_syspm_callback_mode_t mode);


/*******************************************************************************
* Global Variables
*******************************************************************************/

/** An application layer event callback function to receive
 *  service events from the PSoC 6 BLE Middleware. */
cy_ble_callback_t Cy_BLE_ApplCallback = NULL;

/** Pointer to the global BLE configuration structures */
__WEAK const cy_stc_ble_config_t *cy_ble_configPtr = NULL;

/** Pointers to SysPm callback function */
void (*Cy_BLE_RegisterPmCallbacksPtr)(void)   = NULL;
void (*Cy_BLE_UnregisterPmCallbacksPtr)(void) = NULL;

/* Structure with the SysPm callback parameters for BLESS deep sleep */
static cy_stc_syspm_callback_params_t bleDeepSleepCallbackParams =
{
   /* base           */  NULL,
   /* context        */  NULL
};

static cy_stc_syspm_callback_t bleDeepSleepCallback =
{
   /* callback       */  NULL,
   /* type           */  CY_SYSPM_DEEPSLEEP,
   /* skipMode       */  CY_SYSPM_SKIP_BEFORE_TRANSITION | CY_SYSPM_SKIP_CHECK_FAIL,

   /* callbackParams */  &bleDeepSleepCallbackParams,
   /* prevItm        */  NULL,
   /* nextItm        */  NULL,
   /* order          */  CY_BLE_LPM_SYSPM_CB_ORDER
};

/* Structure with the SysPm callback parameters for BLE sleep */
static cy_stc_syspm_callback_params_t bleSleepCallbackParams =
{
   /* base           */  NULL,
   /* context        */  NULL
};

static cy_stc_syspm_callback_t bleSleepCallback =
{
   /* callback       */  &Cy_BLE_SleepCallbackDualCore,
   /* type           */  CY_SYSPM_SLEEP,
   /* skipMode       */  CY_SYSPM_SKIP_BEFORE_TRANSITION | CY_SYSPM_SKIP_CHECK_FAIL,

   /* callbackParams */  &bleSleepCallbackParams,
   /* prevItm        */  NULL,
   /* nextItm        */  NULL,
   /* order          */  CY_BLE_LPM_SYSPM_CB_ORDER
};


/******************************************************************************
* Function Name: Cy_BLE_InitHost
***************************************************************************//**
*
*  Initializes the PSoC 6 BLE Middleware (Host part).
*
*  \param config: The configuration structure for the PSoC 6 BLE Middleware.
*
*  \return
*  \ref cy_en_ble_api_result_t : Return value indicates whether the function succeeded or
*   failed. The following are possible error codes.
*
*   Error codes                     | Description
*   ------------                    | -----------
*   CY_BLE_SUCCESS                  | The function completed successfully.
*   CY_BLE_ERROR_INVALID_PARAMETER  | On specifying NULL as the input parameter.
*
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_InitHost(const cy_stc_ble_config_t *config)
{
    cy_en_ble_api_result_t apiResult = CY_BLE_SUCCESS;

#if CY_BLE_LIB_HOST_CORE
    if((config == NULL) || (Cy_BLE_ApplCallback == NULL))
    {
        apiResult = CY_BLE_ERROR_INVALID_PARAMETER;
    }
    else
    {
        uint32_t idx;

        /* Register a pointer to the configuration structure */
        cy_ble_configPtr = config;
        Cy_BLE_HAL_SetConfigStructure(cy_ble_configPtr);

        /* Initializes cy_ble_connHandle */
        for(idx = 0u; idx < CY_BLE_MAX_SUPPORTED_CONN_COUNT; idx++)
        {
           cy_ble_connHandle[idx].bdHandle = CY_BLE_INVALID_CONN_HANDLE_VALUE;
           cy_ble_connHandle[idx].attId    = CY_BLE_INVALID_CONN_HANDLE_VALUE;
        }

        /* Initializes client structures */
        if((cy_ble_configPtr->params->gattRole & CY_BLE_GATT_CLIENT) != 0u)
        {
            for(idx = 0u; idx < cy_ble_configPtr->params->maxClientCount; idx++)
            {
                uint32 servCnt = cy_ble_configPtr->context->discServiCount;
                (void)memset(&cy_ble_configPtr->context->serverInfo[idx * servCnt], 0, 
                                                           (sizeof(cy_stc_ble_disc_srvc_info_t) * servCnt));
                (void)memset(&cy_ble_configPtr->context->discovery[idx], 0, sizeof(cy_stc_ble_discovery_t));                
                
                /* Update cy_ble_discovery[].connIndex with init values (CY_BLE_INVALID_CONN_HANDLE_VALUE) */
                cy_ble_configPtr->context->discovery[idx].connIndex = CY_BLE_INVALID_CONN_HANDLE_VALUE;
            }
        }

        if(cy_ble_configPtr->ServiceInitFunc != NULL)
        {
            cy_ble_configPtr->ServiceInitFunc();
        }

        cy_ble_pendingFlashWrite = 0u;
        cy_ble_eventHandlerFlag = 0u;
        (void)memset(cy_ble_peerBonding, (int8_t)CY_BLE_GAP_BONDING_NONE, sizeof(cy_ble_peerBonding));

    }
#else
    /* Suppress unused variable warning */
    (void) config;
#endif /* CY_BLE_LIB_HOST_CORE */
    return(apiResult);
}


/******************************************************************************
* Function Name: Cy_BLE_EnableHost
***************************************************************************//**
*
*  This function initializes the BLE Stack, which consists of the BLE Stack
*  Manager, BLE Controller, and BLE Host modules. It takes care of initializing
*  the Profile layer, schedulers, Timer, and other platform-related resources
*  required for the PSoC 6 BLE Middleware.
*
*  Note that this function does not reset the BLE Stack.
*
*  Calling this function results in generation of a #CY_BLE_EVT_STACK_ON event
*  on successful initialization of the BLE Stack.
*
*  In the BLE dual CPU mode, this function should be called on Host cores.
*
*  The BLE Stack enables the BLE ECO clock automatically with the default
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
*  time before calling the Cy_BLE_EnableHost() function.
*
*  NOTE: BLE requires a call to Cy_IPC_SystemSemaInit() and Cy_IPC_SystemPipeInit()
*    functions before use.
*    This function is called in the SystemInit() function for proper flash write
*    and erase operations. If the default startup file is not used, or the function
*    SystemInit() is not called in your project, call the following functions:
*    -# Cy_IPC_SystemSemaInit()
*    -# Cy_IPC_SystemPipeInit()
*
*  return
*  \ref cy_en_ble_api_result_t : Return value indicates whether the function succeeded
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
*    <tr>
*      <td>CY_BLE_ERROR_INVALID_STATE</td>
*      <td>The PSoC 6 BLE Middleware was not initialized.</td>
*    </tr>
*  </table>
*
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_EnableHost(void)
{
    cy_en_ble_api_result_t apiResult = CY_BLE_ERROR_INVALID_STATE;

#if CY_BLE_LIB_HOST_CORE
    if (cy_ble_configPtr != NULL)
    {
        /* Set of buffers to be allocated by the BLE Stack for BLE Stack operation */
        /* Array dataBuff [totalDataBufferPools] shall provide the information to the BLE Stack based
         *  on the below table:
         *
         *  Index |                        bufferSize                       | noOfBuffer
         *  ----- | --------------------------------------------------------| ---------------
         *    0   | (GATT MTU + CY_BLE_MEM_EXT_SZ + CY_BLE_L2CAP_HDR_SZ)    | 3
         *    1   | ((CY_BLE_L2CAP_PSM_SIZE + CY_BLE_MEM_EXT_SZ) *          | No of PSM supported
         *        |    No of PSM supported)                                 |
         *        |                                                         |
         *    2   | ((CY_BLE_L2CAP_CBFC_CHANNEL_SIZE + CY_BLE_MEM_EXT_SZ) * | 2 * No of L2cap
         *        |    No of L2CAP logical channels)                        | logical channels
         *        |                                                         |
         *    3   | (L2CAP MTU + CY_BLE_MEM_EXT_SZ + CY_BLE_L2CAP_HDR_SZ)   | 2 * No of L2cap
         *        |                                                         | logical channels
         */

        /* Data Buffer information for ATT/GATT Configured MTU Size */
        uint16_t dataBuffIdx0 = CY_BLE_ALIGN_TO_4(cy_ble_configPtr->params->mtuSize +
                                                   CY_BLE_MEM_EXT_SZ + CY_BLE_L2CAP_HDR_SZ);

        /* Data Buffer information forL2CAP configuration for number of PSM Channels */
        uint16_t dataBuffIdx1 = CY_BLE_ALIGN_TO_4(cy_ble_configPtr->params->l2capPsmCount *
                                                  (CY_BLE_L2CAP_PSM_SIZE + CY_BLE_MEM_EXT_SZ));

        /* Data Buffer information for L2CAP configuration for number of CBFC Channels */
        uint16_t dataBuffIdx2 = CY_BLE_ALIGN_TO_4(cy_ble_configPtr->params->l2capChanCount *
                                                  (CY_BLE_L2CAP_CBFC_CHANNEL_SIZE + CY_BLE_MEM_EXT_SZ));
        
        /* Data Buffer information for L2CAP configured MTU Size */
        uint16_t dataBuffIdx3 = CY_BLE_ALIGN_TO_4(cy_ble_configPtr->params->l2capMtuSize +
                                                   CY_BLE_MEM_EXT_SZ + CY_BLE_L2CAP_HDR_SZ);

    #if defined(CY_BLE_STACK_APP_POOL_5_SZ)
        /* Data Buffer information for GATT DB maximum entry Size */
        uint16_t dbInxCount   = cy_ble_configPtr->params->gattDbIndexCount;
        uint16_t dataBuffIdx4 = CY_BLE_ALIGN_TO_4((dbInxCount / 8u) +  CY_BLE_MEM_EXT_SZ +
                                                  (((dbInxCount % 8u) != 0u) ? 1u : 0u )) ;
    #endif /* defined(CY_BLE_STACK_APP_POOL_5_SZ) */

        /* If mtu > 23 stack queue depth (stack queue depth per connection - 1) * maxBleConnection */
        uint16_t mtuBuffCount = (cy_ble_configPtr->stackParam->maxConnCount *
                                  ((cy_ble_configPtr->params->mtuSize > CY_BLE_MTU_MIN_VALUE) ?
                                    ((uint16_t)cy_ble_configPtr->stackParam->l2capBufferPerConn - 1u) :
                                     CY_BLE_MTU_MIN_BUFF_NUM));

        cy_stc_ble_stk_app_data_buff_t stackDataBuff[CY_BLE_STACK_APP_MIN_POOL] =
        {
            { dataBuffIdx0, mtuBuffCount                                   },
            { dataBuffIdx1, cy_ble_configPtr->params->l2capPsmCount        },
            { dataBuffIdx2, 2u * cy_ble_configPtr->params->l2capChanCount  },
            { dataBuffIdx3, 2u * cy_ble_configPtr->params->l2capChanCount  },
        #if defined(CY_BLE_STACK_APP_POOL_5_SZ)
            { dataBuffIdx4, 1u                                             },
        #endif /* defined(CY_BLE_STACK_APP_POOL_5_SZ) */    
        };

        cy_stc_ble_stack_init_info_t stackInitParam;
        (void)memset(&stackInitParam, 0, sizeof(cy_stc_ble_stack_init_info_t));

        /* Application Callback Function */
        stackInitParam.CyBleAppCbFunc = (cy_ble_app_ev_cb_t)&Cy_BLE_EventHandler;

        /* Initialize BLE stack buffers needed for BLE Stack operation */
        stackInitParam.memParam.dataBuff = stackDataBuff;

        /* Total data buffer pools */
        stackInitParam.memParam.totalDataBufferPools = CY_BLE_STACK_APP_MIN_POOL;

        /* Flash storage */
        if(cy_ble_configPtr->flashStorage->stackFlashPtr != NULL)
        {
            stackInitParam.memParam.bleStackFlashPointer = cy_ble_configPtr->flashStorage->stackFlashPtr;
            stackInitParam.memParam.bleStackFlashSize = cy_ble_configPtr->flashStorage->stackFlashSize;
        }

        /* Configure l2cap queue */
        stackInitParam.stackConfig.l2capConfig.l2capBufferPerConn = cy_ble_configPtr->stackParam->l2capBufferPerConn;

        /* BLE Stack memory heap size */
        stackInitParam.memParam.totalHeapSz = cy_ble_configPtr->stackParam->totalHeapSz;

        /* Configure DLE */
        stackInitParam.stackConfig.dleConfig.dleMaxTxCapability = cy_ble_configPtr->stackParam->dleMaxTxCapability;
        stackInitParam.stackConfig.dleConfig.dleMaxRxCapability = cy_ble_configPtr->stackParam->dleMaxRxCapability;

        stackInitParam.stackConfig.dleConfig.dleNumTxBuffer = CY_BLE_LL_DEFAULT_NUM_ACL_TX_PACKETS;
        stackInitParam.stackConfig.dleConfig.dleNumRxBuffer = CY_BLE_LL_DEFAULT_NUM_ACL_RX_PACKETS;

        /* Configure BLE Stack features */
        stackInitParam.stackConfig.featureMask =
                cy_ble_configPtr->stackParam->featureMask;

        /* Configure maximum connection support */
        stackInitParam.stackConfig.maxBleConnections =
                cy_ble_configPtr->stackParam->maxConnCount;

        /* Configure bonded device list */
        stackInitParam.stackConfig.bondListConfig.bondListSize =
                cy_ble_configPtr->stackParam->maxBondedDevListSize;

        /* Configure white list */
        stackInitParam.stackConfig.whiteListConfig.whiteListSize =
                cy_ble_configPtr->stackParam->maxWhiteListSize;

        /* Configure LL Privacy */
        stackInitParam.stackConfig.privacyConfig.resolvingListSize =
                cy_ble_configPtr->stackParam->maxResolvableDevListSize;

        /* Register SysPm callback for BLESS deep sleep support */
        if (Cy_BLE_RegisterPmCallbacksPtr != NULL)
        {
            Cy_BLE_RegisterPmCallbacksPtr();
        }

        /* Configure BLE features */
        /* Enable DLE code in the stack */
        if((cy_ble_configPtr->stackParam->featureMask & CY_BLE_DLE_FEATURE_MASK) != 0u)
        {
            Cy_BLE_EnableDleFeature();
        }

        /* Enable LL Privacy code in the stack */
        if((cy_ble_configPtr->stackParam->featureMask & CY_BLE_PRIVACY_1_2_FEATURE_MASK) != 0u)
        {
            Cy_BLE_EnablePrivacyFeature();
        }

        /* Enable PHY Update code in the stack */
        if((cy_ble_configPtr->stackParam->featureMask & CY_BLE_PHY_UPDATE_FEATURE_MASK) != 0u)
        {
            Cy_BLE_EnablePhyUpdateFeature();
        }
        apiResult = Cy_BLE_StackSetFeatureConfig(&stackInitParam.stackConfig);


        if(apiResult == CY_BLE_SUCCESS)
        {
            /* Set pointer to memory RAM buffer */
            stackInitParam.memParam.memoryHeapPtr = cy_ble_configPtr->stackParam->memoryHeapPtr;

            /* Configure parameter for Radio PA calibration */
            if(cy_ble_configPtr->stackParam->paCalConfig != NULL)
            {
                stackInitParam.stackConfig.paCalConfig = *cy_ble_configPtr->stackParam->paCalConfig;
            }

            /* Initialize the BLE Stack */
            apiResult = Cy_BLE_StackInit(&stackInitParam);
        }

        if(apiResult == CY_BLE_SUCCESS)
        {
            /* Initializes internal states */
            Cy_BLE_SetState(CY_BLE_STATE_INITIALIZING);

            if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_BROADCASTER)) != 0u)
            {
                Cy_BLE_SetAdvertisementState(CY_BLE_ADV_STATE_STOPPED);
            }

            if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_OBSERVER | CY_BLE_GAP_CENTRAL)) != 0u)
            {
                Cy_BLE_SetScanState(CY_BLE_SCAN_STATE_STOPPED);
            }
        }
    }
#endif /* CY_BLE_LIB_HOST_CORE */

    return(apiResult);
}


/******************************************************************************
* Function Name: Cy_BLE_DisableHost
***************************************************************************//**
*
*  This function stops any ongoing operation in the BLE Stack and forces the
*  BLE Stack to shut down.
*
*  Calling this function results in generation of a
*  #CY_BLE_EVT_STACK_SHUTDOWN_COMPLETE event on a successful stack shut-down.

*
* \return
* \ref cy_en_ble_api_result_t : Return value indicates whether the function succeeded or
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
cy_en_ble_api_result_t Cy_BLE_DisableHost(void)
{
    cy_en_ble_api_result_t apiResult = CY_BLE_SUCCESS;

    #if CY_BLE_LIB_HOST_CORE
        /* Stops all ongoing activities */
        apiResult = Cy_BLE_StackShutdown();
    #endif /* CY_BLE_LIB_HOST_CORE */

    return(apiResult);
}


/******************************************************************************
* Function Name: Cy_BLE_RegisterEventCallback
***************************************************************************//**
*
*  Registers a callback function to receive events from the PSoC 6 BLE Middleware.
*
*  \param callbackFunc: An application layer event callback function to receive
*  events from the PSoC 6 BLE Middleware. The definition of \ref cy_ble_callback_t
*  is:<br>
*  typedef void (* cy_ble_callback_t) (uint32_t eventCode, void *eventParam),
*  where:
*       * eventCode:  Indicates the event that triggered this callback
*         (e.g. #CY_BLE_EVT_STACK_ON).
*       * eventParam: Contains the parameters corresponding to the
*         current event.
*
******************************************************************************/
void Cy_BLE_RegisterEventCallback(cy_ble_callback_t callbackFunc)
{
    /* Store an application callback function */
    Cy_BLE_ApplCallback = callbackFunc;
}


/*******************************************************************************
* Function Name: Cy_BLE_RegisterInterruptCallback
****************************************************************************//**
*
*  This function registers a callback to expose BLE interrupt notifications to an
*  application that indicates a different link layer and radio state transition
*  to the user from the BLESS interrupt context. This callback is triggered at
*  the beginning of a received BLESS interrupt (based on the registered
*  interrupt mask).
*
*  An application can use an interrupt callback to know when:
*  * the RF activity is about to begin/end;
*  * the BLE device changes its state from advertising to connected;
*  * BLESS transits between BLESS active and BLESS low-power modes.
*
*  These BLESS real-time states can be used to synchronize
*  an application with the BLESS or prevent radio interference with other
*  peripherals, etc.
*
*  BLE dual CPU mode requires an additional configuration IPC channel and IPC Interrupt
*  structure to send notifications from the controller core to Host core.
*  Refer to Cy_BLE_ConfigureIpcForInterruptCallback() for details.
*
*  \note
*  The user must call Cy_BLE_IntrNotifyIsrHandler() inside the user-defined BLESS 
*  interrupt service routine (ISR)
*
*  \param intrMask
*  All interrupts masks are specified in the #cy_en_ble_interrupt_callback_feature_t
*  enumeration.
*
*  \param CallBack
*  The pointer to an application notify callback.
*
*  \return
*  \ref cy_en_ble_api_result_t : The return value indicates whether the function succeeded or
*  failed. The possible error codes:
*
*    Errors codes                   | Description
*    ------------                   | -----------
*    CY_BLE_SUCCESS                 | The callback is registered successfully.
*    CY_BLE_ERROR_INVALID_PARAMETER | Validation of the input parameters failed.
*
*******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_RegisterInterruptCallback(uint32_t intrMask, cy_ble_intr_callback_t CallBack)
{
    cy_en_ble_api_result_t apiResult = CY_BLE_SUCCESS;

    if(CallBack != NULL)
    {
        /* Store the application callback and interrupt mask */
        Cy_BLE_InterruptCallback = CallBack;
        intrNotify.mask = intrMask;

        /* Store pointer to intrNotify configuration  */
        intrNotifyPtr = &intrNotify;
    }
    else
    {
        apiResult = CY_BLE_ERROR_INVALID_PARAMETER;
    }
    return apiResult;
}


/*******************************************************************************
* Function Name: Cy_BLE_ConfigureIpcForInterruptCallback
****************************************************************************//**
*
*  This function configures IPC channel for BLE interrupt notifications feature,
*  when BLE is operating in BLE dual CPU mode.
*
*  This function must be called only on the Host CPU core.
*
*  \param ipcChan: IPC channel. Valid range: 9..15
*  \param ipcIntr: IPC Interrupt structure. Valid range: 9..15
*  \param ipcIntrPrior: IPC Interrupt priority. Valid range: 0..7
*
*  \return
*  \ref cy_en_ble_api_result_t : The return value indicates whether the function succeeded or
*  failed. The possible error codes:
*
*    Errors codes                   | Description
*    ------------                   | -----------
*    CY_BLE_SUCCESS                 | The callback is registered successfully.
*    CY_BLE_ERROR_INVALID_PARAMETER | Validation of the input parameters failed.
*    CY_BLE_ERROR_INVALID_OPERATION | The IPC channel is busy (BLE dual CPU mode only).
*
*******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_ConfigureIpcForInterruptCallback(uint32_t ipcChan, uint32_t ipcIntr, uint32_t ipcIntrPrior)
{
    /* Set up the IPC for BLE dual CPU mode */

    cy_en_ble_api_result_t apiResult = CY_BLE_SUCCESS;

    /* IPC channel 0...8 is reserved by system */
    if( (ipcChan >= 9u) && (ipcChan <= 15u) && (ipcIntr >= 9u) && (ipcIntr <= 15u) &&
        (ipcIntrPrior <= 7u) )
    {
        cy_en_ipc_pipe_status_t ipcStatus;
        cy_stc_sysint_t intrConfig;
        uint32_t rTimeout = 2000u; /* us */

        /* Initialize the interrupt controller for CM4 and IPC Interrupt */
        intrConfig.intrPriority = ipcIntrPrior;
        intrConfig.intrSrc  =(IRQn_Type) CY_IPC_INTR_NUM_TO_VECT((int32_t)ipcIntr);

        (void)Cy_SysInt_Init(&intrConfig, &Cy_BLE_HAL_IntrNotifyIpcHandler);
        NVIC_EnableIRQ(intrConfig.intrSrc);

        /* Store IPC channel information in Interrupt Notify structure */
        intrNotify.userIpcChan = (uint8_t) ipcChan;
        intrNotify.userIpcIntr = (uint8_t) ipcIntr;
        intrNotify.userIpcIntrPrior = (uint8_t) ipcIntrPrior;

        /* Do not bring up an IPC release interrupt here; only set up a notify interrupt */
        Cy_IPC_Drv_SetInterruptMask(Cy_IPC_Drv_GetIntrBaseAddr(ipcIntr),
                                    CY_IPC_NO_NOTIFICATION, (1uL << ipcChan));

        /*
         * Send the address of the intrNotify structure to the controller core via CyPipe
         * The IPC Pipe can be busy. If so, try sending a message after 2 ms.
         */
        do
        {
            ipcStatus = Cy_IPC_Pipe_SendMessage(CY_BLE_IPC_CONTROLLER_ADDR, CY_BLE_IPC_HOST_ADDR,
                                                (void *)&intrNotify, NULL);
            Cy_SysLib_DelayUs(1u);
            rTimeout--;

        }while((ipcStatus != CY_IPC_PIPE_SUCCESS) && (rTimeout != 0u));

        if(ipcStatus != CY_IPC_PIPE_SUCCESS)
        {
            apiResult = CY_BLE_ERROR_INVALID_OPERATION;
        }
    }
    else
    {
        apiResult = CY_BLE_ERROR_INVALID_PARAMETER;
    }

    return(apiResult);
}


/*******************************************************************************
* Function Name: Cy_BLE_UnRegisterInterruptCallback
****************************************************************************//**
*
*  This function un-registers the callback that exposed BLE interrupt
*  notifications to the application.
*
*  \return
*  \ref cy_en_ble_api_result_t : Return value indicates whether the function succeeded
*   or failed. The following are possible error codes.
*
*   Errors codes                   | Description
*   ------------                   | -----------
*   CY_BLE_SUCCESS                 | The callback registered successfully.
*   CY_BLE_ERROR_INVALID_OPERATION | The IPC channel is busy (BLE dual CPU mode only).
*
*******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_UnRegisterInterruptCallback(void)
{
    cy_en_ble_api_result_t apiResult;

        /* Clean interrupt mask */
        apiResult = Cy_BLE_RegisterInterruptCallback((uint32_t)CY_BLE_INTR_CALLBACK_NONE,
                                                     Cy_BLE_InterruptCallback);
        if(apiResult == CY_BLE_SUCCESS)
        {
            /* Clean callback pointer */
            Cy_BLE_InterruptCallback = NULL;
        }
 
    return(apiResult);
}


/*******************************************************************************
* Function Name: Cy_BLE_RegisterAppHostCallback
****************************************************************************//**
*
*  This function registers an application Host callback (BLE RTOS hook).
*  The user can trigger an RTOS BLE task if the application Host callback was
*  called.
*
*  Theory of operation:
*  The PSoC 6 BLE Middleware triggers this callback when the BLE Stack controller needs
*  to process pending Stack events (by calling Cy_BLE_ProcessEvents()). This
*  callback executes from within an ISR and must be very short.
*
*  \note The application Host callback is called from the context of a high-
*  priority ISR. Some RTOS (e.g. FreeRTOS) have restrictions on calling the RTOS
*  functions from a high-priority ISR. The user application is responsible for
*  integration of the BLE RTOS hook and RTOS functions and must ensure that RTOS
*  allows calling RTOS API from BLE interrupt context.
*  If direct call is forbidden, one of the possible solutions is to trig a
*  low-priority interrupt from the application Host callback and then call the
*  RTOS functions from a low-priority interrupt. For detail, refer to specific
*  RTOS documentation.
*
*  \param CallBack
*  The pointer to the application Host callback.
*
*  \return
*   Error Codes                        | Description
*   ------------                       | -----------
*    CY_BLE_SUCCESS                    | The callback registered successfully.
*    CY_BLE_ERROR_INVALID_PARAMETER    | On specifying NULL as the input parameter.
*
*******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_RegisterAppHostCallback(cy_ble_app_notify_callback_t CallBack)
{
    cy_en_ble_api_result_t apiResult = CY_BLE_SUCCESS;

    if(CallBack != NULL)
    {
        Cy_BLE_HostRegisteredCallback = CallBack;
    }
    else
    {
        apiResult = CY_BLE_ERROR_INVALID_PARAMETER;
    }
    return apiResult;
}


/*******************************************************************************
* Function Name: Cy_BLE_UnRegisterAppHostCallback
****************************************************************************//**
*
* This function un-registers an application Host callback (BLE RTOS hook).
*
*******************************************************************************/
void Cy_BLE_UnRegisterAppHostCallback(void)
{
    Cy_BLE_HostRegisteredCallback = NULL;
}



/*******************************************************************************
 *
 *  BLE LPM (Low Power mode)
 *
*******************************************************************************/

/******************************************************************************
* Function Name: Cy_BLE_EnableSystemLowPowerMode
***************************************************************************//**
*
*  This function enables BLE low power mode (register BLE SysPm callback)
*
*  This function must be used only in BLE single CPU mode.
*
******************************************************************************/
void Cy_BLE_EnableSystemLowPowerMode(void)
{
    /* Register BLE SysPm callback for CPU deep sleep */
    Cy_BLE_RegisterPmCallbacksSingle();

    Cy_BLE_RegisterPmCallbacksPtr = &Cy_BLE_RegisterPmCallbacksSingle;
    Cy_BLE_UnregisterPmCallbacksPtr = &Cy_BLE_UnregisterHostPmCallbacksSingle;
}


/******************************************************************************
* Function Name: Cy_BLE_EnableHostLowPowerMode
***************************************************************************//**
*
*  This function enables BLE Low Power mode (register BLE SysPm callbacks)
*
*  This function must be used only in BLE dual CPU mode and called on the CPU core
*  where the BLE Host is running.
*
******************************************************************************/
void Cy_BLE_EnableHostLowPowerMode(void)
{
    /* Register BLE SysPm callback for CPU deep sleep/sleep */
    Cy_BLE_RegisterPmCallbacksDual();

    Cy_BLE_RegisterPmCallbacksPtr = &Cy_BLE_RegisterPmCallbacksDual;
    Cy_BLE_UnregisterPmCallbacksPtr = &Cy_BLE_UnregisterHostPmCallbacksDual;
}


/******************************************************************************
* Function Name: Cy_BLE_RegisterPmCallbacksSingle
***************************************************************************//**
*
*  Register BLE SysPm callback for CPU deep sleep
*
*  This function is designated for internal usage.
*
******************************************************************************/
static void Cy_BLE_RegisterPmCallbacksSingle(void)
{
    /* Register BLE SysPm callback for CPU deep sleep support */
    bleDeepSleepCallback.callback = &Cy_BLE_DeepSleepCallbackSingleCore;
    (void)Cy_SysPm_RegisterCallback(&bleDeepSleepCallback);
}


/******************************************************************************
* Function Name: Cy_BLE_RegisterPmCallbacksDual
***************************************************************************//**
*
*  Register BLE SysPm callback for CPU deep sleep/CPU sleep
*
*  This function is designated for internal usage.
*
******************************************************************************/
static void Cy_BLE_RegisterPmCallbacksDual(void)
{
    /* Register BLE SysPm callback for CPU deep sleep support */
    bleDeepSleepCallback.callback = &Cy_BLE_DeepSleepCallbackDualCore;
    (void)Cy_SysPm_RegisterCallback(&bleDeepSleepCallback);

    /* Register BLE SysPm callback for CPU sleep support, need only in 
     * BLE dual CPU mode for the Host core */
    (void)Cy_SysPm_RegisterCallback(&bleSleepCallback);
}


/******************************************************************************
* Function Name: Cy_BLE_UnregisterHostPmCallbacksSingle
***************************************************************************//**
*
*  Unregister BLE SysPm callback for CPU deep sleep for Host core.
*
*  This function is designated for internal usage.
*
******************************************************************************/
static void Cy_BLE_UnregisterHostPmCallbacksSingle(void)
{
    /* Unregister BLE SysPm callback for CPU deep sleep support */
    (void)Cy_SysPm_UnregisterCallback(&bleDeepSleepCallback);
}


/******************************************************************************
* Function Name: Cy_BLE_UnregisterHostPmCallbacksDual
***************************************************************************//**
*
*  Unregister BLE SysPm callback for CPU deep sleep/CPU sleep for Host core.
*
*  This function is designated for internal usage.
*
******************************************************************************/
static void Cy_BLE_UnregisterHostPmCallbacksDual(void)
{
    /* Unregister BLE callback for CPU deep sleep support */
    (void)Cy_SysPm_UnregisterCallback(&bleDeepSleepCallback);

    /* Unregister sleep mode callback only in BLE dual CPU mode for the Host core */
    /* Unregister BLE callback for CPU sleep support */
    (void)Cy_SysPm_UnregisterCallback(&bleSleepCallback);
}


/*******************************************************************************
* Function Name: Cy_BLE_DeepSleepCallbackSingleCore
****************************************************************************//**
*
*  This function requests the BLE Stack to put Bluetooth Low Energy Sub-System
*  (BLESS) to deep sleep mode for BLE single CPU mode.
*
*  It is registered to the system power mode by Cy_SysPm_RegisterCallback()
*  function with CY_SYSPM_DEEPSLEEP type. After registration, it is called by
*  Cy_SysPm_DeepSleep() function prior entering the core into the CPU deep sleep
*  power mode.
*
*  When it is called with the enMode parameter set to CY_SYSPM_CHECK_READY,
*  this function enters BLESS to CY_BLE_BLESS_DEEPSLEEP mode. It also checks the
*  BLE Subsystem's current operational mode. When the
*  Cy_BLE_StackGetBleSsState() function returns CY_BLE_BLESS_STATE_ECO_ON or
*  CY_BLE_BLESS_STATE_DEEPSLEEP state, this function returns CY_SYSPM_PASS and
*  allows putting the core into the CPU deep sleep power mode.
*  At all other times, the function tries to send the core into CPU sleep mode.
*
*  This function is available only when BLE Low Power mode is enabled (called
*  Cy_BLE_EnableLPM).
*
*  \param
*  callbackParams  Pointer to the structure with the syspm callback parameters.
*
*  \param
*  mode            The associated syspm callback mode. See description of the
*                  cy_en_syspm_callback_mode_t type.
*
*  \return
*  * CY_SYSPM_SUCCESS  - Entered and exited from BLESS deep sleep.
*  * CY_SYSPM_FAIL     - BLESS deep sleep not entered.
*
*******************************************************************************/
static cy_en_syspm_status_t Cy_BLE_DeepSleepCallbackSingleCore(cy_stc_syspm_callback_params_t *callbackParams,
                                                        cy_en_syspm_callback_mode_t mode)
{
    /* Suppress unused variable warning */
    (void) callbackParams;
    (void) mode;

#if defined(COMPONENT_BLESS_HOST)    
    cy_en_syspm_status_t retVal;
    static uint32_t interruptState = 0u;
    cy_en_ble_bless_state_t blessState;
    
    /* Local variable to store the status of BLESS Hardware block */
    cy_en_ble_lp_mode_t sleepMode;

    switch(mode)
    {
        case (CY_SYSPM_CHECK_READY):
            if(Cy_BLE_GetState() == CY_BLE_STATE_INITIALIZING)
            {
                retVal = CY_SYSPM_FAIL;
            }
            else if(Cy_IPC_Sema_Status(CY_BLE_SEMA) == CY_IPC_SEMA_STATUS_LOCKED)
            {
                /* System do not enter CPU deep sleep if BLE Host start write operation */
                retVal = CY_SYSPM_FAIL;
            }
            else if (Cy_BLE_HAL_IsEcoCpuClockSrc() == 1u)
            {
                /* System never enters CPU deep sleep if BLE ECO is CPU source */
                retVal = CY_SYSPM_FAIL;
            }
            else
            {
                cy_en_ble_api_result_t retIsControllerActive;

                /* Put BLESS into deep sleep and check the return status */
                sleepMode = Cy_BLE_StackEnterLPM(CY_BLE_BLESS_DEEPSLEEP);

                /* Disable global interrupt to prevent changes from any other interrupt ISR */
                interruptState = Cy_SysLib_EnterCriticalSection();

                /* Check the Status of BLESS */
                blessState = Cy_BLE_StackGetBleSsState();

                if(blessState == CY_BLE_BLESS_STATE_STOPPED)
                {
                    retVal = CY_SYSPM_SUCCESS;
                }
                else if(sleepMode == CY_BLE_BLESS_DEEPSLEEP)
                {
                    retIsControllerActive = Cy_BLE_MappingIsControllerActive(CY_BLE_CONTROLLER_SLEEP_MODE_DEEPSLEEP);

                    if(((blessState == CY_BLE_BLESS_STATE_ECO_ON) || (blessState == CY_BLE_BLESS_STATE_DEEPSLEEP))
                        && (retIsControllerActive == CY_BLE_SUCCESS))
                    {
                        /* Enter device CPU deep sleep */
                        retVal = CY_SYSPM_SUCCESS;
                    }
                    else
                    {
                        /* The BLESS hardware block cannot go to CPU deep sleep; try CPU sleep mode */
                        retVal = CY_SYSPM_FAIL;
                    }
                }
                else
                {
                    retIsControllerActive = Cy_BLE_MappingIsControllerActive(CY_BLE_CONTROLLER_SLEEP_MODE_SLEEP);

                    if((blessState != CY_BLE_BLESS_STATE_EVENT_CLOSE) &&
                       (retIsControllerActive == CY_BLE_SUCCESS))
                    {
                        /* If the BLESS hardware block cannot go to CPU deep sleep and BLE event has not
                         * closed yet, then place CPU to sleep */
                        (void)Cy_SysPm_CpuEnterSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
                    }
                    retVal = CY_SYSPM_FAIL;
                }
                if(retVal == CY_SYSPM_FAIL)
                {
                    /* Enable interrupts after failing check */
                    Cy_SysLib_ExitCriticalSection(interruptState);
                }
            }
            break;

        /* Enable interrupts after wakeup */
        case (CY_SYSPM_AFTER_TRANSITION):
            Cy_SysLib_ExitCriticalSection(interruptState);
            retVal = CY_SYSPM_SUCCESS;
            break;

        default:
            retVal = CY_SYSPM_FAIL;
            break;
    }

    return(retVal);
#else
    return(CY_SYSPM_SUCCESS);
#endif /*defined(COMPONENT_BLESS_HOST) */    
}


/*******************************************************************************
* Function Name: Cy_BLE_DeepSleepCallbackDualCore
****************************************************************************//**
*
*  This function requests the BLE Stack to put Bluetooth Low Energy Sub-System
*  (BLESS) to CPU deep sleep mode for BLE dual CPU mode (Host).
*
*  It is registered to the system power mode by Cy_SysPm_RegisterCallback()
*  function with CY_SYSPM_DEEPSLEEP type. After registration it is called by
*  Cy_SysPm_DeepSleep() function prior sending the core into the CPU deep sleep
*  power mode.
*
*  When it is called with the enMode parameter set to CY_SYSPM_CHECK_READY,
*  the function enters BLESS to CY_BLE_BLESS_DEEPSLEEP mode. It also checks the
*  BLE Subsystem's current operational mode. When the
*  Cy_BLE_StackGetBleSsState() function returns CY_BLE_BLESS_STATE_ECO_ON or
*  CY_BLE_BLESS_STATE_DEEPSLEEP state, this function returns CY_SYSPM_PASS and
*  allows putting the core into the CPU deep sleep power mode.
*  At all other times, the function tries to send the core into sleep mode.
*
*  This function is available only when BLE Low Power mode is enabled (called
*  Cy_BLE_EnableLPM).
*
*  \param
*  callbackParams  Pointer to the structure with the syspm callback parameters.
*
*  \param
*  mode            The associated syspm callback mode. See description of the
*                  cy_en_syspm_callback_mode_t type.
*
*  \return
*  * CY_SYSPM_SUCCESS  - Entered and exited from BLESS deep sleep.
*  * CY_SYSPM_FAIL     - BLESS deep sleep not entered.
*
*******************************************************************************/
static cy_en_syspm_status_t Cy_BLE_DeepSleepCallbackDualCore(cy_stc_syspm_callback_params_t *callbackParams,
                                                             cy_en_syspm_callback_mode_t mode)
{
    /* Suppress unused variable warning */
    (void) callbackParams;
    (void) mode;
    
#if defined(COMPONENT_BLESS_HOST_IPC)    
    cy_en_syspm_status_t retVal;
    static uint32_t interruptState = 0u;
    cy_en_ble_bless_state_t blessState;

    /* Local variable to store the status of BLESS Hardware block */
    cy_en_ble_lp_mode_t sleepMode;

    switch(mode)
    {
        case (CY_SYSPM_CHECK_READY):
            if(Cy_BLE_GetState() == CY_BLE_STATE_INITIALIZING)
            {
                retVal = CY_SYSPM_FAIL;
            }
            else if(Cy_IPC_Sema_Status(CY_BLE_SEMA) == CY_IPC_SEMA_STATUS_LOCKED)
            {
                /* System do not enter CPU deep sleep if BLE Host start write operation */
                retVal = CY_SYSPM_FAIL;
            }
            else
            {
                /* Disable global interrupt to prevent changes from any other interrupt ISR */
                interruptState = Cy_SysLib_EnterCriticalSection();

                /* Put BLESS into deep sleep and check the return status */
                sleepMode = Cy_BLE_StackEnterLPM(CY_BLE_BLESS_DEEPSLEEP);

                /* Check the Status of BLESS */
                blessState = Cy_BLE_StackGetBleSsState();

                if(sleepMode == CY_BLE_BLESS_DEEPSLEEP)
                {

                    if((blessState == CY_BLE_BLESS_STATE_ECO_ON) || (blessState == CY_BLE_BLESS_STATE_DEEPSLEEP))

                    {
                        /* Enter device deep sleep */
                        retVal = CY_SYSPM_SUCCESS;
                    }
                    else
                    {
                        /* The BLESS hardware block cannot go to CPU deep sleep; try CPU sleep mode */
                        retVal = CY_SYSPM_FAIL;
                    }
                }
                else
                {
                    retVal = CY_SYSPM_FAIL;
                }
                if(retVal == CY_SYSPM_FAIL)
                {
                    /* Enable interrupts after failing check */
                    Cy_SysLib_ExitCriticalSection(interruptState);
                }
            }
            break;

        /* Enable interrupts after wakeup */
        case (CY_SYSPM_AFTER_TRANSITION):
            Cy_SysLib_ExitCriticalSection(interruptState);
            retVal = CY_SYSPM_SUCCESS;
            break;

        default:
            retVal = CY_SYSPM_FAIL;
            break;
    }

    return(retVal);
#else
    return(CY_SYSPM_SUCCESS);
#endif /*defined(COMPONENT_BLESS_HOST_IPC) */

}


/*******************************************************************************
* Function Name: Cy_BLE_SleepCallbackDualCore
****************************************************************************//**
*
*  This function requests the BLE Stack to put the Host to CPU sleep mode.
*
*  It is registered to the system power mode by Cy_SysPm_RegisterCallback()
*  function with CY_SYSPM_SLEEP type. After registration, it is called by
*  Cy_SysPm_Sleep() function prior to sending the core into the CPU sleep
*  power mode.
*
*  This function is available only when BLE Low Power mode is enabled (called
*  Cy_BLE_EnableLPM).
*
*  \param
*  callbackParams  Pointer to the structure with the syspm callback parameters.
*
*  \param
*  mode            The associated syspm callback mode. See description of the
*                  cy_en_syspm_callback_mode_t type.
*
*  \return
*  * CY_SYSPM_SUCCESS  - Entered and exited from CPU sleep.
*  * CY_SYSPM_FAIL     - CPU sleep not entered.
*
*******************************************************************************/
static cy_en_syspm_status_t Cy_BLE_SleepCallbackDualCore(cy_stc_syspm_callback_params_t *callbackParams,
                                                         cy_en_syspm_callback_mode_t mode)
{
    /* Suppress unused variable warning */
    (void) callbackParams;
    (void) mode;

#if defined(COMPONENT_BLESS_HOST_IPC) 
    cy_en_syspm_status_t retVal;
    static uint32_t interruptState = 0u;
    
    /* Local variable to store the status of BLESS Hardware block */
    cy_en_ble_lp_mode_t sleepMode;
    
    switch(mode)
    {
        case (CY_SYSPM_CHECK_READY):
            if(Cy_BLE_GetState() == CY_BLE_STATE_INITIALIZING)
            {
                retVal = CY_SYSPM_FAIL;
            }
            else
            {
                /* Disable global interrupt to prevent changes from any other interrupt ISR */
                interruptState = Cy_SysLib_EnterCriticalSection();

                /* Put BLESS into deep sleep and check the return status */
                sleepMode = Cy_BLE_StackEnterLPM(CY_BLE_BLESS_DEEPSLEEP);

                /* Check whether the Host is ready for CPU sleep mode */
                if(sleepMode != CY_BLE_BLESS_DEEPSLEEP)
                {
                    retVal = CY_SYSPM_FAIL;
                    /* Enable interrupts after failing check */
                    Cy_SysLib_ExitCriticalSection(interruptState);
                }
                else
                {
                    retVal = CY_SYSPM_SUCCESS;
                }
            }
            break;

        /* Enable interrupts after wakeup */
        case (CY_SYSPM_AFTER_TRANSITION):
            Cy_SysLib_ExitCriticalSection(interruptState);
            retVal = CY_SYSPM_SUCCESS;
            break;

        case (CY_SYSPM_CHECK_FAIL):
            Cy_SysLib_ExitCriticalSection(interruptState);
            retVal = CY_SYSPM_FAIL;
            break;

        default:
            retVal = CY_SYSPM_FAIL;
            break;
    }
    return(retVal);
#else
    return(CY_SYSPM_SUCCESS);
#endif /*defined(COMPONENT_BLESS_HOST_IPC) */
}

#endif /* CY_IP_MXBLESS */

/* [] END OF FILE */
