/***************************************************************************//**
* \file cy_ble_controller.c
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
#include "cy_ble_event_handler.h"
#include "cy_ble_hal_pvt.h"
#include "cy_ble.h"

#include "cy_ble_stack_pvt.h"

#if defined(CY_IP_MXBLESS)

/*******************************************************************************
* Private Function Prototypes
*******************************************************************************/

static cy_en_syspm_status_t 
    Cy_BLE_ControllerDeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams,
                                       cy_en_syspm_callback_mode_t mode);


/*******************************************************************************
* Global Variables
*******************************************************************************/

/** Pointer to the global BLE configuration structures */
static const cy_stc_ble_config_t *cy_ble_controllerConfigPtr = NULL;


/*******************************************************************************
* Internal Defines
*******************************************************************************/

#define CY_BLE_SEND_IPC_MESSAGE_TIMEOUT                 (2000u)
#define CY_BLE_WAIT_CONTR_START_TIMEOUT                 (2000u)


/******************************************************************************
* Function Name: Cy_BLE_InitController
***************************************************************************//**
*
*  Initializes the PSoC 6 BLE Middleware (controller part).
*
*  This function must used only in HCI or BLE dual CPU mode and called on CPU core,
*  where BLE controller is running.
*
*  \param config: The configuration structure for the PSoC 6 BLE Middleware.
*
*  \return
*  \ref cy_en_ble_api_result_t : Return value indicates whether the function succeeded or
*  failed. The following are possible error codes.
*
*   Error codes                     | Description
*   ------------                    | -----------
*   CY_BLE_SUCCESS                  | The function completed successfully.
*   CY_BLE_ERROR_INVALID_PARAMETER  | On specifying NULL as the input parameter.
*
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_InitController(const cy_stc_ble_config_t *config)
{
    cy_en_ble_api_result_t apiResult = CY_BLE_ERROR_INVALID_PARAMETER;

    if(config != NULL)
    {
        /* Register a pointer to the BLE controller configuration structure */
        cy_ble_controllerConfigPtr = config;
        Cy_BLE_HAL_SetConfigStructure(cy_ble_controllerConfigPtr);
        apiResult = CY_BLE_SUCCESS;
    }

    return(apiResult);
}


/******************************************************************************
* Function Name: Cy_BLE_EnableController
***************************************************************************//**
*
*  This function enables the BLE Stack controller.
*
*  This function must used only in BLE dual CPU mode and called on CPU core,
*  where BLE controller is running.
*
*  \return
*  \ref cy_en_ble_api_result_t : Return value indicates whether the function succeeded
*       or failed. The following are possible error codes.
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
*      <td>The PSoC 6 BLE Middleware was not initialized</td>
*    </tr>
*  </table>
*
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_EnableController(void)
{
    cy_en_ble_api_result_t apiResult = CY_BLE_ERROR_INVALID_STATE;

#if defined(COMPONENT_BLESS_CONTROLLER_IPC)
    if (cy_ble_controllerConfigPtr != NULL)
    {
        cy_stc_ble_stack_init_info_t stackInitParam;
       (void) memset(&stackInitParam, 0, sizeof(cy_stc_ble_stack_init_info_t));

        /* BLE Stack memory heap size */
        stackInitParam.memParam.totalHeapSz =
                cy_ble_controllerConfigPtr->stackParam->controllerTotalHeapSz;
        
        /* Configure DLE */
        stackInitParam.stackConfig.dleConfig.dleMaxTxCapability =
                cy_ble_controllerConfigPtr->stackParam->dleMaxTxCapability;
        stackInitParam.stackConfig.dleConfig.dleMaxRxCapability =
                cy_ble_controllerConfigPtr->stackParam->dleMaxRxCapability;

        stackInitParam.stackConfig.dleConfig.dleNumTxBuffer = CY_BLE_LL_DEFAULT_NUM_ACL_TX_PACKETS;
        stackInitParam.stackConfig.dleConfig.dleNumRxBuffer = CY_BLE_LL_DEFAULT_NUM_ACL_RX_PACKETS;

        /* Configure BLE Stack features */
        stackInitParam.stackConfig.featureMask =
                cy_ble_controllerConfigPtr->stackParam->featureMask;

        /* Configure maximum connection support */
        stackInitParam.stackConfig.maxBleConnections =
                cy_ble_controllerConfigPtr->stackParam->maxConnCount;

        /* Configure bonded device list */
        stackInitParam.stackConfig.bondListConfig.bondListSize =
                cy_ble_controllerConfigPtr->stackParam->maxBondedDevListSize;

        /* Configure white list */
        stackInitParam.stackConfig.whiteListConfig.whiteListSize =
                cy_ble_controllerConfigPtr->stackParam->maxWhiteListSize;

        /* Configure LL Privacy */
        stackInitParam.stackConfig.privacyConfig.resolvingListSize =
                cy_ble_controllerConfigPtr->stackParam->maxResolvableDevListSize;

        /* Configure BLE features */
        /* Enable DLE code in the stack */
        if((cy_ble_controllerConfigPtr->stackParam->featureMask & CY_BLE_DLE_FEATURE_MASK) != 0u)
        {
            Cy_BLE_EnableDleFeature();
        }

        /* Enable LL Privacy code in the stack */
        if((cy_ble_controllerConfigPtr->stackParam->featureMask & CY_BLE_PRIVACY_1_2_FEATURE_MASK) != 0u)
        {
            Cy_BLE_EnablePrivacyFeature(); 
        }

        /* Enable PHY Update code in the stack */
        if((cy_ble_controllerConfigPtr->stackParam->featureMask & CY_BLE_PHY_UPDATE_FEATURE_MASK) != 0u)
        {
            Cy_BLE_EnablePhyUpdateFeature();        
        }

        apiResult = Cy_BLE_StackSetFeatureConfig(&stackInitParam.stackConfig);


        if(apiResult == CY_BLE_SUCCESS)
        {
            /* Set pointer to memory RAM buffer */
            stackInitParam.memParam.memoryHeapPtr = cy_ble_controllerConfigPtr->stackParam->controllerMemoryHeapPtr;

            /* Configure parameter for Radio PA calibration */
            if(cy_ble_controllerConfigPtr->stackParam->paCalConfig != NULL)
            {
                stackInitParam.stackConfig.paCalConfig = *cy_ble_controllerConfigPtr->stackParam->paCalConfig;
            }

            /* Initialize the BLE Stack */
            apiResult = Cy_BLE_StackInit(&stackInitParam);
        }
    }
#endif /* defined(COMPONENT_BLESS_CONTROLLER_IPC) */
    return(apiResult);
}


/******************************************************************************
* Function Name: Cy_BLE_EnableHCIModeController
***************************************************************************//**
*
*  This function enables the BLE Stack controller in HCI only mode.
*
*  This function must used only in HCI mode and called on CPU core,
*  where BLE controller is running.
*
*  \return
*  \ref cy_en_ble_api_result_t : Return value indicates whether the function succeeded
*       or failed. The following are possible error codes.
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
*      <td>The PSoC 6 BLE Middleware was not initialized</td>
*    </tr>
*  </table>
*
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_EnableHCIModeController(void)
{
    cy_en_ble_api_result_t apiResult = CY_BLE_ERROR_INVALID_STATE;

#if defined(COMPONENT_BLESS_CONTROLLER)
    if (cy_ble_controllerConfigPtr != NULL)
    {
        cy_stc_ble_stack_init_info_t stackInitParam;
       (void) memset(&stackInitParam, 0, sizeof(cy_stc_ble_stack_init_info_t));

        /* BLE Stack memory heap size */
        stackInitParam.memParam.totalHeapSz =
                cy_ble_controllerConfigPtr->stackParam->totalHeapSz;

        /* Configure DLE */
        stackInitParam.stackConfig.dleConfig.dleMaxTxCapability =
                cy_ble_controllerConfigPtr->stackParam->dleMaxTxCapability;
        stackInitParam.stackConfig.dleConfig.dleMaxRxCapability =
                cy_ble_controllerConfigPtr->stackParam->dleMaxRxCapability;

        stackInitParam.stackConfig.dleConfig.dleNumTxBuffer = CY_BLE_LL_DEFAULT_NUM_ACL_TX_PACKETS;
        stackInitParam.stackConfig.dleConfig.dleNumRxBuffer = CY_BLE_LL_DEFAULT_NUM_ACL_RX_PACKETS;

        /* Configure BLE Stack features */
        stackInitParam.stackConfig.featureMask =
                cy_ble_controllerConfigPtr->stackParam->featureMask;

        /* Configure maximum connection support */
        stackInitParam.stackConfig.maxBleConnections =
                cy_ble_controllerConfigPtr->stackParam->maxConnCount;

        /* Configure bonded device list */
        stackInitParam.stackConfig.bondListConfig.bondListSize =
                cy_ble_controllerConfigPtr->stackParam->maxBondedDevListSize;

        /* Configure white list */
        stackInitParam.stackConfig.whiteListConfig.whiteListSize =
                cy_ble_controllerConfigPtr->stackParam->maxWhiteListSize;

        /* Configure LL Privacy */
        stackInitParam.stackConfig.privacyConfig.resolvingListSize =
                cy_ble_controllerConfigPtr->stackParam->maxResolvableDevListSize;

        /* Configure BLE features */
        /* Enable DLE code in the stack */
        if((cy_ble_controllerConfigPtr->stackParam->featureMask & CY_BLE_DLE_FEATURE_MASK) != 0u)
        {
            Cy_BLE_ControllerEnableDleFeature();
        }

        /* Enable LL Privacy code in the stack */
        if((cy_ble_controllerConfigPtr->stackParam->featureMask & CY_BLE_PRIVACY_1_2_FEATURE_MASK) != 0u)
        {
            Cy_BLE_ControllerEnablePrivacyFeature();
        }

        /* Enable PHY Update code in the stack */
        if((cy_ble_controllerConfigPtr->stackParam->featureMask & CY_BLE_PHY_UPDATE_FEATURE_MASK) != 0u)
        {
            Cy_BLE_ControllerEnablePhyUpdateFeature();
        }

        apiResult = Cy_BLE_ControllerStackSetFeatureConfig(&stackInitParam.stackConfig);
        
        /* Application Callback Function */
        stackInitParam.CyBleAppCbFunc = (cy_ble_app_ev_cb_t)&Cy_BLE_EventHandlerWrapper;

        if(apiResult == CY_BLE_SUCCESS)
        {
            /* Set pointer to memory RAM buffer */
            stackInitParam.memParam.memoryHeapPtr = cy_ble_controllerConfigPtr->stackParam->memoryHeapPtr;

            /* Configure parameter for Radio PA calibration */
            if(cy_ble_controllerConfigPtr->stackParam->paCalConfig != NULL)
            {
                stackInitParam.stackConfig.paCalConfig = *cy_ble_controllerConfigPtr->stackParam->paCalConfig;
            }

            /* Initialize the BLE Stack */
            apiResult = Cy_BLE_ControllerStackInit(&stackInitParam);
        }
    }
#endif /* defined(COMPONENT_BLESS_CONTROLLER) */
    return(apiResult);
}


/******************************************************************************
* Function Name: Cy_BLE_EnableControllerFromHost
***************************************************************************//**
*
*  This function sends an IPC message to enable the BLE Stack controller and
*  waits until the controller starts.
*
*  \return
*  \ref cy_en_ble_api_result_t : Return value indicates whether the function succeeded
*       or failed. The following are possible error codes.
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
*      <td>The PSoC 6 BLE Middleware was not initialized</td>
*    </tr>
*    <tr>
*      <td>CY_BLE_ERROR_INVALID_OPERATION</td>
*      <td>The timeout to enable the BLE controller (a problem with the IPC
*            communication, or other BLE controller's CPU core problem)</td>
*    </tr>
*  </table>
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_EnableControllerFromHost(void)
{
    /** IPC mesage structure for enable controller */
    static volatile cy_stc_ble_ipc_msg_t controllerMsg =
    {
        /* clientID          */  CY_BLE_CYPIPE_MSG_CMD_ID,
        /* pktType           */  CY_BLE_CYPIPE_ENABLE_CONTR_CMD,
        /* intrRelMask       */  0x00u,
        /* controllerStarted */  false,
        /* data              */  0x00u,
        /* dataLen           */  0x00u 
    };

    cy_en_ipc_pipe_status_t ipcStatus;
    uint32_t rTimeout = CY_BLE_SEND_IPC_MESSAGE_TIMEOUT;

    /* Check if controller is started  */
    if ( !controllerMsg.controllerStarted )
    { 
        /* Store pointer to stack param structure */
        controllerMsg.data = (uint32_t) cy_ble_configPtr->stackParam;

        /* Send the address of the intrNotify structure to the controller core via CyPipe
         * The IPC Pipe can be busy. If so, try sending a message again. */
        do
        {
            ipcStatus = Cy_IPC_Pipe_SendMessage(CY_BLE_IPC_CONTROLLER_ADDR, CY_BLE_IPC_HOST_ADDR,
                                                (void *)&controllerMsg, NULL);
            Cy_SysLib_DelayUs(1u);
            rTimeout--;

        }while((ipcStatus != CY_IPC_PIPE_SUCCESS) && (rTimeout != 0u));

        /* Wait until controller starts */
        rTimeout = CY_BLE_WAIT_CONTR_START_TIMEOUT;
        do
        {
            Cy_SysLib_Delay(1u);
            rTimeout--;
        } while ((!controllerMsg.controllerStarted) && (rTimeout != 0u));
    }

    return ((rTimeout == 0u) ? CY_BLE_ERROR_INVALID_OPERATION :
                        (cy_en_ble_api_result_t) controllerMsg.data);
}


/*******************************************************************************
 *  BLE LPM (low power mode)
*******************************************************************************/

/******************************************************************************
* Function Name: Cy_BLE_EnableControllerLowPowerMode
***************************************************************************//**
*
*  This function enables BLE low power mode for Controller
*
*  Register BLE callback for deep sleep / sleep
*
*  This function must used only in BLE dual CPU mode and called on CPU core,
*  where BLE controller is running.
*
******************************************************************************/
void Cy_BLE_EnableControllerLowPowerMode(void)
{

    /* Structure with the SysPm callback parameters for BLESS deep sleep */
    static cy_stc_syspm_callback_params_t bleDeepSleepCallbackParams =
    {
       /* base           */  NULL,
       /* context        */  NULL
    };

    static cy_stc_syspm_callback_t bleDeepSleepCallback =
    {
       /* callback       */  &Cy_BLE_ControllerDeepSleepCallback,
       /* type           */  CY_SYSPM_DEEPSLEEP,
       /* skipMode       */  CY_SYSPM_SKIP_BEFORE_TRANSITION | CY_SYSPM_SKIP_CHECK_FAIL,

       /* callbackParams */  &bleDeepSleepCallbackParams,
       /* prevItm        */  NULL,
       /* nextItm        */  NULL,
       /* order          */  CY_BLE_LPM_SYSPM_CB_ORDER
    };

    /* Register BLE callback for BLESS deep sleep support */
    (void)Cy_SysPm_RegisterCallback(&bleDeepSleepCallback);
}


/*******************************************************************************
* Function Name: Cy_BLE_ControllerDeepSleepCallback
****************************************************************************//**
*
*  This function requests the BLE Stack to put Bluetooth Low Energy Sub-System
*  (BLESS) to deep sleep mode.
*
*  It is registered to the system power mode by Cy_SysPm_RegisterCallback()
*  function with CY_SYSPM_DEEPSLEEP type. After registration it is called by
*  Cy_SysPm_DeepSleep() function prior entering the core into the CPU deep sleep
*  power mode.
*
*  When it is called with the enMode parameter set to CY_SYSPM_CHECK_READY,
*  function enters BLESS to CY_BLE_BLESS_DEEPSLEEP mode. It also checks the
*  BLE Subsystem's current operational mode. When the
*  Cy_BLE_StackGetBleSsState() function returns CY_BLE_BLESS_STATE_ECO_ON or
*  CY_BLE_BLESS_STATE_DEEPSLEEP state, this function returns CY_SYSPM_PASS and
*  allows to put the core into the deep-sleep power mode.
*  At all other times, the function tries to enter core into sleep mode.
*
*  This function is available only when BLE low power mode is enabled (called
*  Cy_BLE_EnableLowPowerMode() function).
*
*  \param
*  callbackParams  Pointer to the structure with the syspm callback parameters.
*
*  \param
*  mode            The associated syspm callback mode. See description of the
*                  cy_en_syspm_callback_mode_t type.
*
*  \return
*  * CY_SYSPM_SUCCESS  - Entered and exited from CPU deep sleep
*  * CY_SYSPM_FAIL     - CPU deep sleep not entered.
*
*******************************************************************************/
static cy_en_syspm_status_t Cy_BLE_ControllerDeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams,
                                                               cy_en_syspm_callback_mode_t mode)
{
    cy_en_syspm_status_t retVal;
    static uint32_t interruptState = 0u;
    cy_en_ble_bless_state_t blessState;

    /* Local variable to store the status of BLESS Hardware block */
    cy_en_ble_lp_mode_t sleepMode;

    /* Suppress unused variable warning */
    (void) callbackParams;
    
    switch(mode)
    {
        case (CY_SYSPM_CHECK_READY):
            if(Cy_IPC_Sema_Status(CY_BLE_SEMA) == CY_IPC_SEMA_STATUS_LOCKED)
            {
                /* System do not enter deep sleep if BLE Host start write operation */
                retVal = CY_SYSPM_FAIL;
            }
            else if (Cy_BLE_HAL_IsEcoCpuClockSrc() == 1u)
            {
                /* System never enters deep sleep if BLE ECO is CPU source */
                retVal = CY_SYSPM_FAIL;
            }
            else
            {
                cy_en_ble_api_result_t retIsControllerActive;

                /* Put BLESS into deep sleep and check the return status */
                sleepMode = Cy_BLE_MappingStackEnterLPM(CY_BLE_BLESS_DEEPSLEEP);

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
                        /* Enter device deep sleep */
                        retVal = CY_SYSPM_SUCCESS;
                    }
                    else
                    {
                        /* The BLESS hardware block cannot go to deep sleep, try sleep mode */
                        retVal = CY_SYSPM_FAIL;
                    }
                }
                else
                {
                    retIsControllerActive = Cy_BLE_MappingIsControllerActive(CY_BLE_CONTROLLER_SLEEP_MODE_SLEEP);
                    if((blessState != CY_BLE_BLESS_STATE_EVENT_CLOSE) && (retIsControllerActive == CY_BLE_SUCCESS))
                    {
                        /* If the BLESS hardware block cannot go to deep sleep and BLE event has not
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
}


/*******************************************************************************
 *  Internal
*******************************************************************************/

/******************************************************************************
* Function Name: Cy_BLE_EventHandlerWrapper
***************************************************************************//**
*
*  This event handler is used in HCI Soft mode, and dirrect calls registered by 
*  application Cy_BLE_ApplCallback callback.
*
******************************************************************************/
void Cy_BLE_EventHandlerWrapper(cy_en_ble_event_t event, void *evParam)
{
    /* Call Cy_BLE_ApplCallback */  
    Cy_BLE_ApplCallback((uint32_t)event, evParam);
}


#endif /* CY_IP_MXBLESS */


/* [] END OF FILE */
