/***************************************************************************//**
* \file cy_ble_event_handler.c
* \version 3.60
*
* \brief
*  This file contains the source code for the event Handler State Machine
*  of the PSoC 6 BLE Middleware.
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

#if defined(CY_IP_MXBLESS)

/*******************************************************************************
* Global Variables
*******************************************************************************/

/* Indicates if event is processed by registered services */
volatile uint8_t cy_ble_eventHandlerFlag;

/* Busy status. Updated from CY_BLE_EVT_STACK_BUSY_STATUS event */
// volatile uint8_t cy_ble_busyStatus[CY_BLE_MAX_SUPPORTED_CONN_COUNT];

/* The pointers to the callback functions */
cy_ble_app_ev_cb_t Cy_BLE_ServerEventHandlerCallback = NULL;
cy_ble_app_ev_cb_t Cy_BLE_ClientEventHandlerCallback = NULL;

/* Pointer to the BLE device address in SROM */
cy_stc_ble_bd_addr_t *cy_ble_sflashDeviceAddress = (cy_stc_ble_bd_addr_t *) SFLASH_BLE_DEVICE_ADDRESS;


#if CY_BLE_LIB_HOST_CORE

/*******************************************************************************
* Private Function Prototypes
*******************************************************************************/

/* event Handler functions */
static void Cy_BLE_TimeOutEventHandler(const cy_stc_ble_timeout_param_t *eventParam);
static void Cy_BLE_SendWriteResponse(const cy_stc_ble_gatts_write_cmd_req_param_t *eventParam,
                                     cy_en_ble_gatt_err_code_t gattErr);

static void Cy_BLE_ReadByGroupEventHandler(cy_stc_ble_gattc_read_by_grp_rsp_param_t *eventParam);
static void Cy_BLE_ReadByTypeEventHandler(cy_stc_ble_gattc_read_by_type_rsp_param_t *eventParam);
static void Cy_BLE_FindInfoEventHandler(cy_stc_ble_gattc_find_info_rsp_param_t *eventParam);
static void Cy_BLE_NextCharDiscovery(cy_stc_ble_conn_handle_t connHandle, uint8_t incrementIndex);
static void Cy_BLE_NextCharDscrDiscovery(cy_stc_ble_conn_handle_t connHandle, uint8_t incrementIndex);
static void Cy_BLE_LongProcedureEndEventHandler(cy_stc_ble_conn_handle_t connHandle);
static void Cy_BLE_ErrorResponseEventHandler(const cy_stc_ble_gatt_err_param_t *eventParam);
static void Cy_BLE_GAPC_DiscoverCharacteristicsEventHandler(cy_stc_ble_disc_char_info_t *discCharInfo);


/******************************************************************************
* Function Name: Cy_BLE_RegisterServiceEventHandler
***************************************************************************//**
*
*  Registration service event Handler
*
*  \param  eventHandlerFunc: The pointer to the callback procedure.
*
*  \return
*  \ref cy_en_ble_api_result_t : Return value indicates whether the function succeeded or
*  failed. The following are possible error codes.
*
*   Error Codes                           | Description
*   ------------                          | -----------
*   CY_BLE_SUCCESS                        | The function completed successfully.
*   CY_BLE_ERROR_INVALID_PARAMETER        | On specifying NULL as input parameter.
*   CY_BLE_ERROR_MEMORY_ALLOCATION_FAILED | Buffer overflow in the registration callback.
*
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_RegisterServiceEventHandler(cy_ble_event_handle_t eventHandlerFunc)
{
    cy_en_ble_api_result_t apiResult = CY_BLE_SUCCESS;
    bool existFlag = false;

    if(eventHandlerFunc == NULL)
    {
        apiResult = CY_BLE_ERROR_INVALID_PARAMETER;
    }
    else
    {
        /* Check whether eventHandlerFunc has been already registered */
        uint32_t idx;
        for(idx = 0u; (idx < cy_ble_configPtr->context->eventHandlerPool->count) && (existFlag == false); idx++)
        {
            if(cy_ble_configPtr->context->eventHandlerPool->serviceEventHandler[idx] == eventHandlerFunc)
            {
                existFlag = true;
            }
        }
    }

    /* Register eventHandlerFunc callback */
    if((apiResult == CY_BLE_SUCCESS) && (existFlag == false))
    {
        if(cy_ble_configPtr->context->eventHandlerPool->count <
               cy_ble_configPtr->context->eventHandlerPool->maxServCount)
        {
            cy_ble_configPtr->context->eventHandlerPool->
                     serviceEventHandler[cy_ble_configPtr->context->eventHandlerPool->count] = eventHandlerFunc;
            cy_ble_configPtr->context->eventHandlerPool->count += 1u;
        }
        else
        {
            apiResult = CY_BLE_ERROR_MEMORY_ALLOCATION_FAILED;
        }
    }

    return(apiResult);
}


/******************************************************************************
* Function Name: Cy_BLE_InvokeServiceEventHandler
***************************************************************************//**
*
*  Invoke registered service event handlers.
*
*  \param eventCode:   The event code.
*  \param eventParam:  The event parameters.
*
*  \return
*   A return value of type cy_en_ble_gatt_err_code_t.
*
******************************************************************************/
cy_en_ble_gatt_err_code_t Cy_BLE_InvokeServiceEventHandler(uint32_t eventCode,
                                                           void *eventParam)
{
    uint32_t idx;
    cy_en_ble_gatt_err_code_t gattErr = CY_BLE_GATT_ERR_NONE;

    for(idx = 0u; ( (idx < cy_ble_configPtr->context->eventHandlerPool->count) &&
                    ((cy_ble_eventHandlerFlag & CY_BLE_CALLBACK) != 0u) ) ; idx++)
    {
        gattErr = cy_ble_configPtr->context->eventHandlerPool->
                                    serviceEventHandler[idx](eventCode, eventParam);
    }

    return(gattErr);
}


/******************************************************************************
* Function Name: Cy_BLE_SendWriteResponse
***************************************************************************//**
*
*  Sends the Write Response to Write Request when event was handled by service.
*
*  \param eventParam - The event parameter.
*  \param gattErr - The error code.
*
******************************************************************************/
static void Cy_BLE_SendWriteResponse(const cy_stc_ble_gatts_write_cmd_req_param_t *eventParam,
                                     cy_en_ble_gatt_err_code_t gattErr)
{
    cy_stc_ble_gatt_err_param_t err_param;
    err_param.errInfo.opCode     = CY_BLE_GATT_WRITE_REQ;
    err_param.errInfo.attrHandle = eventParam->handleValPair.attrHandle;
    err_param.connHandle         = eventParam->connHandle;

    /* Send response when event was handled by the service */
    if((cy_ble_eventHandlerFlag & CY_BLE_CALLBACK) == 0u)
    {
        if(gattErr != CY_BLE_GATT_ERR_NONE)
        {
            /* Send an Error Response */
            err_param.errInfo.errorCode  = gattErr;
            (void)Cy_BLE_GATTS_ErrorRsp(&err_param);
        }
        else
        {
            /* Send an Write Response */
            (void)Cy_BLE_GATTS_WriteRsp(eventParam->connHandle);
        }
    }
}


/******************************************************************************
* Function Name: Cy_BLE_TimeOutEventHandler
***************************************************************************//**
*
*  Handles a #CY_BLE_EVT_TIMEOUT event from the BLE Stack.
*
*  \param eventParam: The pointer to a structure of type cy_stc_ble_timeout_param_t.
*
******************************************************************************/
static void Cy_BLE_TimeOutEventHandler(const cy_stc_ble_timeout_param_t *eventParam)
{
    if((eventParam->reasonCode == CY_BLE_GATT_RSP_TO) &&
       ((cy_ble_configPtr->params->gattRole & CY_BLE_GATT_CLIENT) != 0u) )
    {
        uint32_t discIdx = Cy_BLE_GetDiscoveryIdx(eventParam->CY_BLE_HANDLE.connHandle);

        if((discIdx < cy_ble_configPtr->params->maxClientCount) &&
           (cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag != 0u))
        {
            switch(Cy_BLE_GetConnectionState(eventParam->CY_BLE_HANDLE.connHandle))
            {
                case CY_BLE_CONN_STATE_CLIENT_SRVC_DISCOVERING:
                    Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_SRVC_DISCOVERY_FAILED,
                                        (cy_stc_ble_conn_handle_t*)&eventParam->CY_BLE_HANDLE.connHandle);
                    break;

                case CY_BLE_CONN_STATE_CLIENT_INCL_DISCOVERING:
                    Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_INCL_DISCOVERY_FAILED,
                                        (cy_stc_ble_conn_handle_t*)&eventParam->CY_BLE_HANDLE.connHandle);
                    break;

                case CY_BLE_CONN_STATE_CLIENT_CHAR_DISCOVERING:
                    Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_CHAR_DISCOVERY_FAILED,
                                        (cy_stc_ble_conn_handle_t*)&eventParam->CY_BLE_HANDLE.connHandle);
                    break;

                case CY_BLE_CONN_STATE_CLIENT_DESCR_DISCOVERING:
                    Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_DESCR_DISCOVERY_FAILED,
                                        (cy_stc_ble_conn_handle_t*)&eventParam->CY_BLE_HANDLE.connHandle);
                    break;

                default:        /* Other states should not be set in Auto discovery mode */
                    break;
            }
            cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag = 0u;
            Cy_BLE_SetConnectionState(eventParam->CY_BLE_HANDLE.connHandle, CY_BLE_CONN_STATE_CONNECTED);
        }
    }

    if((cy_ble_configPtr->params->gapRole & CY_BLE_GAP_CENTRAL) != 0u)
    {
        /* Connection procedure timeout */
        if((eventParam->reasonCode == CY_BLE_GENERIC_APP_TO) &&
           (cy_ble_connectingTimeout.timerHandle == eventParam->timerHandle) &&
           (Cy_BLE_GetState() == CY_BLE_STATE_CONNECTING))
        {
            (void)Cy_BLE_GAPC_CancelDeviceConnection();
        }
    }
}


/******************************************************************************
* Function Name: Cy_BLE_IsDeviceAddressValid
***************************************************************************//**
*
*  This function verifies that the device address is valid (not equal zero)
*
*  \param deviceAddress: The pointer to the BD address of
*                        type #cy_stc_ble_bd_addr_t.
*
*  \return
*   A non-zero value when a device address is valid
*
******************************************************************************/
uint8_t Cy_BLE_IsDeviceAddressValid(const cy_stc_ble_bd_addr_t *deviceAddress)
{
    uint8_t addressValid = 0u;
    uint32_t i;

    if(deviceAddress->type == CY_BLE_GAP_ADDR_TYPE_PUBLIC)
    {
        for(i = 0u; i < CY_BLE_GAP_BD_ADDR_SIZE; i++)
        {
            if(deviceAddress->bdAddr[i] != 0u)
            {
                addressValid = 1u;
                break;
            }
        }
    }

    return(addressValid);
}


/******************************************************************************
* Function Name: Cy_BLE_EventHandler
***************************************************************************//**
*
*  Handles events from the BLE Stack.
*
*  \param event:   The event code.
*  \param evParam: The event parameters.
*
******************************************************************************/
void Cy_BLE_EventHandler(cy_en_ble_event_t event, void *evParam)
{
    /* Internal status of commands execution */
    static volatile uint32_t cy_ble_cmdStatus;

    cy_ble_eventHandlerFlag |= CY_BLE_CALLBACK;

    /* Common Profile event handling */
    switch(event)
    {
        /**********************************************************
         * General events
         ************************************************************/

        case CY_BLE_EVT_HCI_PKT_RCVD:
        {
            cy_stc_ble_hci_tx_packet_info_t *HciPktParams = (cy_stc_ble_hci_tx_packet_info_t*)evParam;
            Cy_BLE_HAL_MappingSoftHciHostReceiveControllerPkt(HciPktParams);

            /* Clear the CY_BLE_CALLBACK flag not to provide a handled event to the application */
            cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
        }
        break;

        case CY_BLE_EVT_STACK_ON:

            /* Initializes internal state variables */
            cy_ble_scanningIntervalType = CY_BLE_SCANNING_FAST;
            cy_ble_advertisingIntervalType = CY_BLE_ADVERTISING_FAST;
            (void)memset((uint8_t*)&cy_ble_busyStatus, 0, sizeof(cy_ble_busyStatus));
            (void)memset(&cy_ble_connState, 0, sizeof(cy_ble_connState));
            cy_ble_cmdStatus = 0u;

            /* Set a device address  */
            if(Cy_BLE_IsDeviceAddressValid(cy_ble_sflashDeviceAddress) != 0u)
            {
                (void)Cy_BLE_GAP_SetBdAddress(cy_ble_sflashDeviceAddress);

                if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_BROADCASTER)) != 0u)
                {
                    Cy_BLE_ChangeAdDeviceAddress(cy_ble_sflashDeviceAddress, 0u);
                    Cy_BLE_ChangeAdDeviceAddress(cy_ble_sflashDeviceAddress, 1u);
                }
            }
            else
            {
                if(cy_ble_configPtr->params->siliconDeviceAddressEn)
                {
                    uint32_t bdAddrLoc;
                    bdAddrLoc = ((uint32_t)SFLASH_DIE_X & (uint32_t)CY_BLE_SFLASH_DIE_X_MASK) |
                                ((uint32_t)(((uint32_t)SFLASH_DIE_Y) & ((uint32_t)CY_BLE_SFLASH_DIE_Y_MASK)) <<
                                    CY_BLE_SFLASH_DIE_X_BITS) |
                                ((uint32_t)(((uint32_t)SFLASH_DIE_WAFER) & ((uint32_t)CY_BLE_SFLASH_DIE_WAFER_MASK)) <<
                                    CY_BLE_SFLASH_DIE_XY_BITS) |
                                ((uint32_t)(((uint32_t)SFLASH_DIE_LOT(0)) & ((uint32_t)CY_BLE_SFLASH_DIE_LOT_MASK)) <<
                                    CY_BLE_SFLASH_DIE_XYWAFER_BITS);

                    cy_ble_configPtr->deviceAddress->bdAddr[0] = (uint8_t)bdAddrLoc;
                    cy_ble_configPtr->deviceAddress->bdAddr[1] = (uint8_t)(bdAddrLoc >> 8u);
                    cy_ble_configPtr->deviceAddress->bdAddr[2] = (uint8_t)(bdAddrLoc >> 16u);
                }
                (void)Cy_BLE_GAP_SetBdAddress(cy_ble_configPtr->deviceAddress);

                if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_BROADCASTER)) != 0u)
                {
                    Cy_BLE_ChangeAdDeviceAddress(cy_ble_configPtr->deviceAddress, 0u);
                    Cy_BLE_ChangeAdDeviceAddress(cy_ble_configPtr->deviceAddress, 1u);
                }
            }

            /* Set the device IO Capability  */
            (void)Cy_BLE_GAP_SetIoCap((cy_en_ble_gap_iocap_t*)&cy_ble_configPtr->params->securityIoCapability);

            /* Enable all 4.1 events and configured 4.2 events */
            {
                uint8_t leMask[CY_BLE_LE_MASK_LENGTH] = {CY_LO8(CY_BLE_LE_MASK),
                                                         CY_HI8(CY_BLE_LE_MASK), 0u, 0u, 0u, 0u, 0u, 0u };
                (void)Cy_BLE_SetLeEventMask(leMask);
            }

            /* Update BLE state  */
            Cy_BLE_SetState(CY_BLE_STATE_ON);
        break;

        case CY_BLE_EVT_SOFT_RESET_COMPLETE:
        case CY_BLE_EVT_STACK_SHUTDOWN_COMPLETE:

            /* Update BLE / Adv. / Scan states  */
            Cy_BLE_SetState(CY_BLE_STATE_STOPPED);

            if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_BROADCASTER)) != 0u)
            {
                Cy_BLE_SetAdvertisementState(CY_BLE_ADV_STATE_STOPPED);
            }

            if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_CENTRAL | CY_BLE_GAP_OBSERVER)) != 0u)
            {
                Cy_BLE_SetScanState(CY_BLE_SCAN_STATE_STOPPED);
            }

            /* Clean pair status */
            if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_CENTRAL)) != 0u)
            {
                (void)memset((uint8_t*)cy_ble_pairStatus, 0, sizeof(cy_ble_pairStatus));
            }

            #if defined(COMPONENT_BLESS_HOST_IPC)
            /* Adding a delay of 10ms to ensure that the controller is completely
             * shut-down before generating the event to the application.
             * Refer to CY_BLE_EVT_STACK_SHUTDOWN_COMPLETE event documentation. */
            Cy_SysLib_Delay(10u);
            #endif /* defined(COMPONENT_BLESS_HOST_IPC) */

            if ( event == CY_BLE_EVT_STACK_SHUTDOWN_COMPLETE)
            {
                /* Unregister BLE SysPm callback for deep sleep/sleep */
                if (Cy_BLE_UnregisterPmCallbacksPtr != NULL)
                {
                    Cy_BLE_UnregisterPmCallbacksPtr();
                }
            }
        break;

        case CY_BLE_EVT_LE_SET_EVENT_MASK_COMPLETE:
            if((cy_ble_cmdStatus & CY_BLE_STATUS_SET_TX_PWR_LVL) == 0u)
            {
                cy_stc_ble_tx_pwr_lvl_info_t bleSsPowerLevel;

                /* Set the Tx Power Level for advertising channel */
                bleSsPowerLevel.blePwrLevel = cy_ble_configPtr->params->txPowerLevelAdv;
                bleSsPowerLevel.pwrConfigParam.bleSsChId = CY_BLE_LL_ADV_CH_TYPE;
                bleSsPowerLevel.pwrConfigParam.bdHandle = 0x0u;
                (void)Cy_BLE_SetTxPowerLevel(&bleSsPowerLevel);

                /* Set the Tx Power Level for connection channel */
                bleSsPowerLevel.blePwrLevel = cy_ble_configPtr->params->txPowerLevelConn;
                bleSsPowerLevel.pwrConfigParam.bleSsChId = CY_BLE_LL_CONN_CH_TYPE;
                bleSsPowerLevel.pwrConfigParam.bdHandle = 0xFFu; /* Set the tx power level value for all connection handles.*/
                (void)Cy_BLE_SetTxPowerLevel(&bleSsPowerLevel);

                /* Set flag that executed Cy_BLE_SetTxPowerLevel during BLE start-up  */
                cy_ble_cmdStatus |= CY_BLE_STATUS_SET_TX_PWR_LVL;
            }
        break;

        case CY_BLE_EVT_TIMEOUT:
            /* Internal Timeout Handling */
            Cy_BLE_TimeOutEventHandler((cy_stc_ble_timeout_param_t*)evParam);

            if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_CENTRAL)) != 0u)
            {
                (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            }
        break;

        case CY_BLE_EVT_STACK_BUSY_STATUS:
            if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_CENTRAL)) != 0u)
            {
                cy_ble_busyStatus[Cy_BLE_GetConnHandleByBdHandle(((cy_stc_ble_l2cap_state_info_t*)evParam)->bdHandle).attId] =
                   ((cy_stc_ble_l2cap_state_info_t*)evParam)->flowState;
            }
        break;

        case CY_BLE_EVT_MEMORY_REQUEST:
        {
            cy_stc_ble_memory_request_t *memReq = (cy_stc_ble_memory_request_t*)evParam;

            if( (!cy_ble_configPtr->params->gattPrepareWriteExtBuffEn) &&
                (memReq->request == CY_BLE_PREPARED_WRITE_REQUEST) )
            {
                /* Stack requests to provide memory to process a remote request */
                if(memReq->allocFree == CY_BLE_ALLOC_MEMORY)
                {
                    static cy_stc_ble_prepare_write_request_memory_t gPrepWriteReqMem;

                    /* Prepare write buffer locates at the end of memoryHeap */
                    uint16_t bufferAddr = cy_ble_configPtr->stackParam->totalHeapSz;

                    /* Configure and return a statically allocated buffer at the end of the cy_ble_stackMemoryRam buffer */
                    gPrepWriteReqMem.prepareWriteQueueSize = cy_ble_configPtr->params->gattPrepareWriteQueueSize;
                    gPrepWriteReqMem.totalAttrValueLength  = cy_ble_configPtr->params->totalAttrValueLength;
                    gPrepWriteReqMem.queueBuffer           = &cy_ble_configPtr->stackParam->memoryHeapPtr[bufferAddr];
                    memReq->configMemory = &gPrepWriteReqMem;
                }

                /* Clear the CY_BLE_CALLBACK flag not to provide a handled event to the application */
                cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
            }
        }
        break;

        /**********************************************************
         * GAP events
         ************************************************************/

        case CY_BLE_EVT_GAP_AUTH_COMPLETE:
            if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_CENTRAL)) != 0u)
            {
                cy_stc_ble_conn_handle_t connectedHandle;
                connectedHandle = Cy_BLE_GetConnHandleByBdHandle(((cy_stc_ble_gap_auth_info_t*)evParam)->bdHandle);

                if(cy_ble_configPtr->params->isBondingReq == CY_BLE_BONDING_YES)
                {
                    cy_ble_peerBonding[connectedHandle.attId] = ((cy_stc_ble_gap_auth_info_t*)evParam)->bonding;
                }

                if(((cy_stc_ble_gap_auth_info_t *)evParam)->authErr == CY_BLE_GAP_AUTH_ERROR_NONE)
                {
                    cy_ble_pairStatus[connectedHandle.attId] = true;
                }
            }
        break;

        case CY_BLE_EVT_GAP_CONNECTION_UPDATE_COMPLETE:
            if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_CENTRAL)) != 0u)
            {
                (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            }
        break;

        case CY_BLE_EVT_GAP_ENHANCE_CONN_COMPLETE:
        case CY_BLE_EVT_GAP_DEVICE_CONNECTED:
            {
                uint8_t cmdStatus;
                uint8_t deviceDdHandle = 0u;
                uint8_t deviceRole = 0u;

                if((cy_ble_configPtr->stackParam->featureMask & CY_BLE_PRIVACY_1_2_FEATURE_MASK) != 0u)
                {
                    cmdStatus = ((cy_stc_ble_gap_enhance_conn_complete_param_t *) evParam)->status;
                    if(cmdStatus == CY_BLE_HCI_SUCCESS)
                    {
                        deviceDdHandle = ((cy_stc_ble_gap_enhance_conn_complete_param_t *) evParam)->bdHandle;
                        deviceRole = ((cy_stc_ble_gap_enhance_conn_complete_param_t *) evParam)->role;
                    }
                }
                else
                {
                    cmdStatus = ((cy_stc_ble_gap_connected_param_t *) evParam)->status;
                    if(cmdStatus == CY_BLE_HCI_SUCCESS)
                    {
                        deviceDdHandle = ((cy_stc_ble_gap_connected_param_t *) evParam)->bdHandle;
                        deviceRole = ((cy_stc_ble_gap_connected_param_t *) evParam)->role;
                    }
                }

                if(cmdStatus == CY_BLE_HCI_SUCCESS)
                {
                    /* Advertising is automatically stopped if a Slave is connected,
                       so update the adv state to CY_BLE_ADV_STATE_STOPPED  */
                    if( ((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_CENTRAL)) != 0u) &&
                        (deviceRole == CY_BLE_GAP_LL_ROLE_SLAVE) )
                    {
                        Cy_BLE_SetAdvertisementState(CY_BLE_ADV_STATE_STOPPED);
                    }

                    /* Stop Timer in central mode (if timer was started) */
                    if(((cy_ble_configPtr->params->gapRole & CY_BLE_GAP_CENTRAL) != 0u) &&
                        (cy_ble_connectingTimeout.timeout != 0u))
                    {
                        (void)Cy_BLE_StopTimer(&cy_ble_connectingTimeout);
                    }

                    /* Store information about role of device connected (Master/Slave)*/
                    if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_BROADCASTER)) != 0u)
                    {
                        cy_stc_ble_conn_handle_t tconnHandle = Cy_BLE_GetConnHandleByBdHandle(deviceDdHandle);
                        if( tconnHandle.attId != CY_BLE_INVALID_CONN_HANDLE_VALUE)
                        {
                            cy_ble_devConnRole[tconnHandle.attId] = deviceRole;
                        }
                    }
                }
                Cy_BLE_SetState(CY_BLE_STATE_ON);
            }
        break;

        case CY_BLE_EVT_GAP_DEVICE_DISCONNECTED:
            Cy_BLE_SetState(CY_BLE_STATE_ON);
        break;

        case CY_BLE_EVT_GAPP_ADVERTISEMENT_START_STOP:
            if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_BROADCASTER | CY_BLE_GAP_PERIPHERAL)) ==
                    (CY_BLE_GAP_BROADCASTER | CY_BLE_GAP_PERIPHERAL))
            {
                (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            }

            if((cy_ble_eventHandlerFlag & CY_BLE_CALLBACK) != 0u)
            {
                /* After Cy_BLE_GAPP_StartAdvertisement, the first event indicates that advertising has started */
                if(Cy_BLE_GetAdvertisementState() == CY_BLE_ADV_STATE_ADV_INITIATED)
                {
                    Cy_BLE_SetAdvertisementState(CY_BLE_ADV_STATE_ADVERTISING);
                }
                /* When the application initiated a stop advertisement */
                else if(Cy_BLE_GetAdvertisementState() == CY_BLE_ADV_STATE_STOP_INITIATED)
                {
                    Cy_BLE_SetAdvertisementState(CY_BLE_ADV_STATE_STOPPED);
                }
                /* The following event indicates that advertising has been stopped */
                else if(Cy_BLE_GetAdvertisementState() == CY_BLE_ADV_STATE_ADVERTISING)
                {
                    Cy_BLE_SetAdvertisementState(CY_BLE_ADV_STATE_STOPPED);

                    /* Enable slow advertising, if need */
                    if((cy_ble_configPtr->gappAdvParams[cy_ble_advIndex].slowAdvEnable != 0u) &&
                       (cy_ble_configPtr->gappAdvParams[cy_ble_advIndex].fastAdvTimeOut != 0u) &&
                       (cy_ble_advertisingIntervalType == CY_BLE_ADVERTISING_FAST))
                    {
                        if(Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_SLOW, cy_ble_advIndex) == CY_BLE_SUCCESS)
                        {
                            Cy_BLE_SetAdvertisementState(CY_BLE_ADV_STATE_ADV_INITIATED);
                        }
                    }
                }
                else
                {
                    /* Empty else */
                }
            }
        break;

        case CY_BLE_EVT_GAPC_SCAN_START_STOP:
            if((cy_ble_configPtr->params->gattRole & CY_BLE_GATT_CLIENT) != 0u)
            {
                (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            }

            if((cy_ble_eventHandlerFlag & CY_BLE_CALLBACK) != 0u)
            {
                /* After Cy_BLE_GAPC_StartScan, the first event indicates that scanning has been started */
                if(Cy_BLE_GetScanState() == CY_BLE_SCAN_STATE_SCAN_INITIATED)
                {
                    Cy_BLE_SetScanState(CY_BLE_SCAN_STATE_SCANNING);
                }
                /* When the application initiated stop scanning */
                else if(Cy_BLE_GetScanState() == CY_BLE_SCAN_STATE_STOP_INITIATED)
                {
                    Cy_BLE_SetScanState(CY_BLE_SCAN_STATE_STOPPED);
                }
                /* The following event indicates that scanning has been stopped by BLE Stack */
                else if(Cy_BLE_GetScanState() == CY_BLE_SCAN_STATE_SCANNING)
                {
                    Cy_BLE_SetScanState(CY_BLE_SCAN_STATE_STOPPED);
                    if((cy_ble_configPtr->gapcScanParams[cy_ble_scanIndex].slowScanEnabled != 0u) &&
                       (cy_ble_configPtr->gapcScanParams[cy_ble_scanIndex].fastScanTimeOut != 0u) &&
                       (cy_ble_scanningIntervalType == CY_BLE_SCANNING_FAST))
                    {
                        if(Cy_BLE_GAPC_StartScan(CY_BLE_SCANNING_SLOW, cy_ble_scanIndex) == CY_BLE_SUCCESS)
                        {
                            Cy_BLE_SetScanState(CY_BLE_SCAN_STATE_SCAN_INITIATED);
                        }
                    }
                }
                else
                {
                    /* Empty else */
                }
            }
        break;


        /**********************************************************
         * L2AP events
         ************************************************************/
        case CY_BLE_EVT_L2CAP_CONN_PARAM_UPDATE_RSP:
            if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_CENTRAL)) != 0u)
            {
                (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            }
         break;


        /**********************************************************
         * GATT events
         ************************************************************/
        case CY_BLE_EVT_GATT_CONNECT_IND:
            {
                cy_stc_ble_conn_handle_t *locConnHandle = (cy_stc_ble_conn_handle_t*)evParam;

                /* If connected to the same device which is already discovered */
                if( ((cy_ble_configPtr->params->gattRole & CY_BLE_GATT_CLIENT) != 0u) &&
                    (Cy_BLE_GetConnectionState(*locConnHandle) == CY_BLE_CONN_STATE_CLIENT_DISCONNECTED_DISCOVERED) &&
                    (locConnHandle->bdHandle == cy_ble_connHandle[locConnHandle->attId].bdHandle))
                {   /* Set a discovered state */
                    Cy_BLE_SetConnectionState(*(cy_stc_ble_conn_handle_t*)evParam, CY_BLE_CONN_STATE_CLIENT_DISCOVERED);
                }
                else    /* Connected to a new device */
                {
                    /* Clear the discovery index for the client role */
                    if( (cy_ble_configPtr->params->gattRole & CY_BLE_GATT_CLIENT) != 0u)
                    {
                        (void)Cy_BLE_GATTC_RemoveConnHandle(*(cy_stc_ble_conn_handle_t*)evParam);
                    }
                    Cy_BLE_SetConnectionState(*locConnHandle, CY_BLE_CONN_STATE_CONNECTED);
                    cy_ble_connHandle[locConnHandle->attId] = *locConnHandle;
                }
                cy_ble_busyStatus[locConnHandle->attId] = CY_BLE_STACK_STATE_FREE;

                if( ((cy_ble_configPtr->params->gattRole & CY_BLE_GATT_SERVER) != 0u) &&
                    (cy_ble_configPtr->params->isBondingReq == CY_BLE_BONDING_YES) &&
                    (cy_ble_configPtr->flashStorage->cccdCount != 0u) )
                {
                    /* Initialize the CCCD values in the RAM when bonding is enabled */
                    uint32_t cccdBlockSize = cy_ble_configPtr->flashStorage->cccdCount + CY_BLE_CCCD_CRC_BYTE;
                    uint32_t cccdBlockOffsetRam = locConnHandle->attId * cccdBlockSize;
                    uint32_t cccdBlockCrcOffset = cccdBlockSize - CY_BLE_CCCD_CRC_BYTE;
                    uint8_t calcCrc;

                    (void)memcpy(&cy_ble_configPtr->flashStorage->cccdRamPtr[cccdBlockOffsetRam],
                                 &cy_ble_configPtr->flashStorage->cccdFlashPtr[locConnHandle->bdHandle * cccdBlockSize],
                                 cccdBlockSize);

                    /* Check CRC for CCCD data */
                    calcCrc = Cy_BLE_HAL_CalcCRC8(&cy_ble_configPtr->flashStorage->cccdRamPtr[cccdBlockOffsetRam],
                                                  cy_ble_configPtr->flashStorage->cccdCount);

                    if(cy_ble_configPtr->flashStorage->cccdRamPtr[cccdBlockOffsetRam  + cccdBlockCrcOffset] != calcCrc)
                    {

                        /* Inform that the CRC for CCCD is wrong */
                        Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTS_EVT_CCCD_CORRUPT, NULL);

                        /* Clean the CCCD buffer in the RAM */
                        (void)memset(&cy_ble_configPtr->flashStorage->cccdRamPtr[locConnHandle->attId * cccdBlockSize],
                                      0, cccdBlockSize);
                    }
                }
                (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            }
        break;

        case CY_BLE_EVT_GATT_DISCONNECT_IND:
            {
                cy_stc_ble_conn_handle_t *locConnHandle = (cy_stc_ble_conn_handle_t*)evParam;

                if( ((cy_ble_configPtr->params->gattRole & CY_BLE_GATT_CLIENT) != 0u) &&
                    (Cy_BLE_GetConnectionState(*locConnHandle) == CY_BLE_CONN_STATE_CLIENT_DISCOVERED) &&
                    (cy_ble_configPtr->params->isBondingReq == CY_BLE_BONDING_YES) )
                {
                    Cy_BLE_SetConnectionState(*(cy_stc_ble_conn_handle_t*)evParam,
                                              CY_BLE_CONN_STATE_CLIENT_DISCONNECTED_DISCOVERED);
                }
                else
                {
                    Cy_BLE_SetConnectionState(*(cy_stc_ble_conn_handle_t*)evParam, CY_BLE_CONN_STATE_DISCONNECTED);

                    if((cy_ble_configPtr->params->gattRole & CY_BLE_GATT_CLIENT) != 0u)
                    {
                        (void)Cy_BLE_GATTC_RemoveConnHandle(*(cy_stc_ble_conn_handle_t*)evParam);
                    }
                }

                if((cy_ble_configPtr->params->gapRole & (CY_BLE_GAP_PERIPHERAL | CY_BLE_GAP_CENTRAL )) != 0u)
                {
                    cy_ble_pairStatus[(*(cy_stc_ble_conn_handle_t *)evParam).attId] = false;
                }
                (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            }
        break;

        case CY_BLE_EVT_GATTS_XCNHG_MTU_REQ:
        {
            cy_stc_ble_gatt_xchg_mtu_param_t mtuParam;
            mtuParam.connHandle = ((cy_stc_ble_gatt_xchg_mtu_param_t*)evParam)->connHandle;
            mtuParam.mtu = cy_ble_configPtr->params->mtuSize ;

            (void)Cy_BLE_GATTS_ExchangeMtuRsp(&mtuParam);
        }
        break;

        case CY_BLE_EVT_GAPC_SCAN_PROGRESS_RESULT:
            (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
        break;

        case CY_BLE_EVT_PENDING_FLASH_WRITE:
            cy_ble_pendingFlashWrite |= CY_BLE_PENDING_STACK_FLASH_WRITE_BIT;
        break;

        default:
            break;
    }

    /* Handling GATT server events */
    if(((cy_ble_eventHandlerFlag & CY_BLE_CALLBACK) != 0u) && (Cy_BLE_ServerEventHandlerCallback != NULL))
    {
        Cy_BLE_ServerEventHandlerCallback(event, evParam);
    }

    /* Handling GATT client events */
    if(((cy_ble_eventHandlerFlag & CY_BLE_CALLBACK) != 0u) && (Cy_BLE_ClientEventHandlerCallback != NULL))
    {
        Cy_BLE_ClientEventHandlerCallback(event, evParam);
    }

    /* Call Cy_BLE_ApplCallback if event was not processed */
    if((cy_ble_eventHandlerFlag & (CY_BLE_CALLBACK | CY_BLE_ENABLE_ALL_EVENTS)) != 0u)
    {
        cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
        Cy_BLE_ApplCallback((uint32_t)event, evParam);
    }
}


/******************************************************************************
* Function Name: Cy_BLE_ServerEventHandler
***************************************************************************//**
*
*  Handles server events from the BLE Stack.
*
*  \param event:   The event code.
*  \param evParam: The event parameters.
*
******************************************************************************/
void Cy_BLE_ServerEventHandler(cy_en_ble_event_t event, void *evParam)
{
    /* Common Profile event handling */
    switch(event)
    {
        case CY_BLE_EVT_GATTS_WRITE_REQ:
        {
            cy_en_ble_gatt_err_code_t gattErr;
            cy_ble_gatt_db_attr_handle_t attrHandle;

            /* Process GATT service */
            gattErr = Cy_BLE_GATTS_WriteEventHandler((cy_stc_ble_gatts_write_cmd_req_param_t*)evParam);

            /* Process all registered service */
            if(gattErr == CY_BLE_GATT_ERR_NONE)
            {
                gattErr = Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            }
            Cy_BLE_SendWriteResponse((cy_stc_ble_gatts_write_cmd_req_param_t*)evParam, gattErr);

            /* Call Cy_BLE_ApplCallback if event was not processed */
            if((cy_ble_eventHandlerFlag & (CY_BLE_CALLBACK | CY_BLE_ENABLE_ALL_EVENTS)) != 0u)
            {
                Cy_BLE_ApplCallback((uint32_t)event, evParam);
            }

            /* Send Error response if unknown attr handle */
            attrHandle = ((cy_stc_ble_gatts_write_cmd_req_param_t*)evParam)->handleValPair.attrHandle;
            if( ((cy_ble_eventHandlerFlag & CY_BLE_CALLBACK) != 0u) &&
                ((attrHandle > cy_ble_configPtr->params->gattDbIndexCount) || (attrHandle == 0u)))
            {
                /* Processing unknown attr handle (send an Error Response) */
                cy_stc_ble_gatt_err_param_t err_param;
                err_param.errInfo.opCode     = CY_BLE_GATT_WRITE_REQ;
                err_param.errInfo.attrHandle = ((cy_stc_ble_gatts_write_cmd_req_param_t*)evParam)->handleValPair.attrHandle;
                err_param.connHandle         = ((cy_stc_ble_gatts_write_cmd_req_param_t*)evParam)->connHandle;
                err_param.errInfo.errorCode  = CY_BLE_GATT_ERR_INVALID_HANDLE;

                (void)Cy_BLE_GATTS_ErrorRsp(&err_param);
            }

            /* Indicate that request was handled */
            cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
        }
        break;

        case CY_BLE_EVT_GATTS_WRITE_CMD_REQ:
        case CY_BLE_EVT_GATTS_PREP_WRITE_REQ:
        case CY_BLE_EVT_GATTS_EXEC_WRITE_REQ:
        case CY_BLE_EVT_GATTS_HANDLE_VALUE_CNF:
            (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            break;

        case CY_BLE_EVT_GATTS_READ_CHAR_VAL_ACCESS_REQ:
            if(cy_ble_configPtr->flashStorage->cccdCount != 0u)
            {
                (void)Cy_BLE_GATTS_ReadAttributeValueCCCDReqHandler((cy_stc_ble_gatts_char_val_read_req_t*)evParam);
            }
            (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            break;

        default:
            break;
    }
}


/******************************************************************************
* Function Name: Cy_BLE_ClientEventHandler
***************************************************************************//**
*
*  Handles client events from the BLE Stack.
*
*  \param event:   The event code.
*  \param evParam: The event parameters.
*
******************************************************************************/
void Cy_BLE_ClientEventHandler(cy_en_ble_event_t event, void *evParam)
{
    /* Common Profile event handling */
    switch(event)
    {
        case CY_BLE_EVT_GATTC_READ_BY_GROUP_TYPE_RSP:
            Cy_BLE_ReadByGroupEventHandler((cy_stc_ble_gattc_read_by_grp_rsp_param_t*)evParam);
            break;

        case CY_BLE_EVT_GATTC_READ_BY_TYPE_RSP:
            Cy_BLE_ReadByTypeEventHandler((cy_stc_ble_gattc_read_by_type_rsp_param_t*)evParam);
            break;

        case CY_BLE_EVT_GATTC_READ_BLOB_RSP:
            (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            break;

        case CY_BLE_EVT_GATTC_LONG_PROCEDURE_END:
            Cy_BLE_LongProcedureEndEventHandler(((cy_stc_ble_gattc_long_procedure_end_param_t*)evParam)->connHandle);
            break;

        case CY_BLE_EVT_GATTC_FIND_INFO_RSP:
            Cy_BLE_FindInfoEventHandler((cy_stc_ble_gattc_find_info_rsp_param_t*)evParam);
            break;

        case CY_BLE_EVT_GATTC_ERROR_RSP:
            Cy_BLE_ErrorResponseEventHandler((cy_stc_ble_gatt_err_param_t*)evParam);
            (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            break;

        case CY_BLE_EVT_GATTC_HANDLE_VALUE_IND:
            Cy_BLE_GATTC_IndicationEventHandler((cy_stc_ble_gattc_handle_value_ind_param_t*)evParam);
            (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);

            /* Respond with a Handle Value Confirmation when request handled */
            if((cy_ble_eventHandlerFlag & CY_BLE_CALLBACK) == 0u)
            {
                cy_stc_ble_gattc_confirmation_req_t confirmationParam;
                confirmationParam.connHandle = ((cy_stc_ble_gattc_handle_value_ind_param_t*)evParam)->connHandle;

                (void)Cy_BLE_GATTC_Confirmation(&confirmationParam);
            }
            break;

        case CY_BLE_EVT_GATTC_HANDLE_VALUE_NTF:
        case CY_BLE_EVT_GATTC_READ_RSP:
        case CY_BLE_EVT_GATTC_READ_MULTI_RSP:
        case CY_BLE_EVT_GATTC_WRITE_RSP:
        case CY_BLE_EVT_GATTC_EXEC_WRITE_RSP:
            (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)event, (void*)evParam);
            break;

        case CY_BLE_EVT_GATTC_STOP_CMD_COMPLETE:
            {
                cy_stc_ble_conn_handle_t locConnHandle = *(cy_stc_ble_conn_handle_t *)evParam;
                uint32_t discIdx = Cy_BLE_GetDiscoveryIdx(locConnHandle);

                if( (Cy_BLE_GetConnectionState(locConnHandle) == CY_BLE_CONN_STATE_CLIENT_INCL_DISCOVERING) &&
                    (discIdx < cy_ble_configPtr->params->maxClientCount) &&
                    (cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag != 0u) )
                {
                    cy_stc_ble_gattc_read_req_t readReqParam;
                    /* Fill Read Request parameters */
                    readReqParam.attrHandle =
                        cy_ble_configPtr->context->discovery[discIdx].inclInfo.inclHandleRange.startHandle;
                    readReqParam.connHandle = locConnHandle;

                    /* Get the included service UUID when the included service uses a 128-bit
                     * UUID, a Read Request is used. The Attribute Handle for the Read Request is
                     * the Attribute Handle of the included service.
                     */

                    if(Cy_BLE_GATTC_ReadCharacteristicValue(&readReqParam) != CY_BLE_SUCCESS)
                    {
                        Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_INCL_DISCOVERY_FAILED, &locConnHandle);
                        cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag = 0u;
                    }

                    cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
                }
            }
            break;

        default:
            break;
    }
}


/******************************************************************************
* Function Name: Cy_BLE_ReadByGroupEventHandler
***************************************************************************//**
*
*  Handles a Read By Group Response event during an automatic server discovery
*  process.
*
*  \param eventParam: The event parameters for a Read By Group Response.
*
******************************************************************************/
static void Cy_BLE_ReadByGroupEventHandler(cy_stc_ble_gattc_read_by_grp_rsp_param_t *eventParam)
{
    uint32_t discIdx = Cy_BLE_GetDiscoveryIdx(eventParam->connHandle);

    if( (Cy_BLE_GetConnectionState(eventParam->connHandle) == CY_BLE_CONN_STATE_CLIENT_SRVC_DISCOVERING) &&
        (discIdx < cy_ble_configPtr->params->maxClientCount) &&
        (cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag != 0u) )
    {
        uint16_t locDataLength = eventParam->attrData.length;
        uint16_t attrLength;

        if((locDataLength == CY_BLE_DISC_SRVC_INFO_LEN) || (locDataLength == CY_BLE_DISC_SRVC_INFO_128_LEN))
        {
            cy_stc_ble_disc_srv_info_t locDiscServInfo = { .connHandle = eventParam->connHandle };
            uint32_t fFlag;
            uint32_t j;
            uint32_t i;

            attrLength = eventParam->attrData.attrLen;

            for(i = 0u; i < attrLength; i += locDataLength)
            {
                cy_ble_eventHandlerFlag |= CY_BLE_CALLBACK;

                locDiscServInfo.srvcInfo = (cy_stc_ble_disc_srvc128_info_t*)(eventParam->attrData.attrValue + i);
                fFlag = 0u;


                if((locDiscServInfo.srvcInfo->range.startHandle >=
                    cy_ble_configPtr->context->discovery[discIdx].gattcDiscoveryRange.startHandle) &&
                   (locDiscServInfo.srvcInfo->range.startHandle <=
                    cy_ble_configPtr->context->discovery[discIdx].gattcDiscoveryRange.endHandle))
                {
                    /* Received a 16-bit service UUID */
                    if(locDataLength == CY_BLE_DISC_SRVC_INFO_LEN)
                    {
                        uint32_t discServiNum = cy_ble_configPtr->context->discServiCount;

                        locDiscServInfo.uuidFormat = CY_BLE_GATT_16_BIT_UUID_FORMAT;
                        for(j = 0u; (j < discServiNum) && (fFlag == 0u); j++)
                        {
                            locDiscServInfo.uuidFormat = CY_BLE_GATT_16_BIT_UUID_FORMAT;
                            if(cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + j].uuid ==
                                locDiscServInfo.srvcInfo->uuid.uuid16)
                            {
                                if(cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + j].range.startHandle ==
                                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE)
                                {
                                    cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + j].range =
                                      locDiscServInfo.srvcInfo->range;
                                    fFlag = 1u;
                                }
                                else    /* Duplication of service */
                                {
                                    /* For multiple service support next service has the same UUID */
                                    if((j >= (discServiNum - 1u)) ||
                                       (cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + j + 1u].uuid !=
                                          locDiscServInfo.srvcInfo->uuid.uuid16))
                                    {
                                        Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_SRVC_DUPLICATION, &locDiscServInfo);
                                        fFlag = 1u;
                                    }
                                }
                            }
                        }
                    }
                    else  /* Received a 128-bit service UUID */
                    {
                        locDiscServInfo.uuidFormat = CY_BLE_GATT_128_BIT_UUID_FORMAT;

                        /* Loop thru all registered services and invoke CY_BLE_EVT_GATTC_DISC_CHAR event */
                        (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)CY_BLE_EVT_GATTC_DISC_SERVICE,
                                                               (void*)&locDiscServInfo);
                    }
                }

                /* Generate event CY_BLE_EVT_GATTC_DISC_SKIPPED_SERVICE, if the incoming service was not processed */
                if((fFlag == 0u) && ((cy_ble_eventHandlerFlag & CY_BLE_CALLBACK) != 0u))
                {
                    /* Inform application that we discovered the service which is not defined in GATT database */
                    Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_DISC_SKIPPED_SERVICE, &locDiscServInfo);
                }

            }
            cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
        }
        else
        {
            Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_SRVC_DISCOVERY_FAILED, &eventParam->connHandle);
        }
    }
}


/******************************************************************************
* Function Name: Cy_BLE_NextInclDiscovery
***************************************************************************//**
*
*  Looks for the included services in the current service (pointed by
*   cy_ble_disCount). If the current service handle range is invalid (any of start
*   or end handle is invalid), then increments the cy_ble_disCount and check
*   the next service range and does so until a valid range is caught or the end of
*   the service set is reached.
*
*  \param connHandle:     The connection handle.
*  \param incrementIndex: A non-zero value indicates that the service index should be
*                         incremented.
*
******************************************************************************/
void Cy_BLE_NextInclDiscovery(cy_stc_ble_conn_handle_t connHandle,
                              uint8_t incrementIndex)
{
    uint32_t locServCount;
    uint32_t discIdx = Cy_BLE_GetDiscoveryIdx(connHandle);
    uint32_t discServiNum = cy_ble_configPtr->context->discServiCount;

    if(incrementIndex != CY_BLE_DISCOVERY_INIT)
    {
        cy_ble_configPtr->context->discovery[discIdx].servCount++;
    }
    else
    {
        cy_ble_configPtr->context->discovery[discIdx].servCount = 0u;
        cy_ble_configPtr->context->discovery[discIdx].inclInfo.inclDefHandle = 0u;
    }

    locServCount = cy_ble_configPtr->context->discovery[discIdx].servCount;

    /* Skip not existing services and services out of the discovery range */
    while( (cy_ble_configPtr->context->discovery[discIdx].servCount < discServiNum) &&
           ((cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + locServCount].range.startHandle <
             cy_ble_configPtr->context->discovery[discIdx].gattcDiscoveryRange.startHandle) ||
            (cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + locServCount].range.startHandle >
             cy_ble_configPtr->context->discovery[discIdx].gattcDiscoveryRange.endHandle)) )
    {
        cy_ble_configPtr->context->discovery[discIdx].servCount++;
        locServCount = cy_ble_configPtr->context->discovery[discIdx].servCount;
    }

    if(cy_ble_configPtr->context->discovery[discIdx].servCount < discServiNum)
    {
        cy_stc_ble_gattc_read_by_type_req_t requestParam;

        /* Fill Read by type request parameters */
        requestParam.range = cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + locServCount].range;
        requestParam.connHandle = connHandle;

        if(Cy_BLE_GATTC_FindIncludedServices(&requestParam) != CY_BLE_SUCCESS)
        {
            Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_INCL_DISCOVERY_FAILED, &connHandle);
            cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag = 0u;
        }
    }
    else /* An included service discovery procedure is done, start a characteristic discovery procedure */
    {
        if((cy_ble_eventHandlerFlag & CY_BLE_ENABLE_ALL_EVENTS) != 0u)
        {
            Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_INCL_DISCOVERY_COMPLETE, &connHandle);
        }
        Cy_BLE_SetConnectionState(connHandle, CY_BLE_CONN_STATE_CLIENT_CHAR_DISCOVERING);
        Cy_BLE_NextCharDiscovery(connHandle, CY_BLE_DISCOVERY_INIT);
    }
}


/******************************************************************************
* Function Name: Cy_BLE_GAPC_DiscoverCharacteristicsEventHandler
***************************************************************************//**
*
*  This function is called on receiving a #CY_BLE_EVT_GATTC_READ_BY_TYPE_RSP
*  event. Based on the service UUID, an appropriate data structure is populated
*  using the data received as part of the callback.
*
*  \param discCharInfo:  The pointer to the characteristic information structure.
*
******************************************************************************/
static void Cy_BLE_GAPC_DiscoverCharacteristicsEventHandler(cy_stc_ble_disc_char_info_t *discCharInfo)
{
    uint32_t discIdx = Cy_BLE_GetDiscoveryIdx(discCharInfo->connHandle);

    if((discCharInfo->uuidFormat == CY_BLE_GATT_16_BIT_UUID_FORMAT) &&
       (cy_ble_configPtr->context->discovery[discIdx].servCount == cy_ble_gapcConfigPtr->serviceDiscIdx))
    {
        switch(discCharInfo->uuid.uuid16)
        {
            case CY_BLE_UUID_CHAR_DEVICE_NAME:
                CY_BLE_GapcCheckCharHandle(cy_ble_gapcConfigPtr->attrInfo[discIdx].deviceNameCharHandle,
                                            discCharInfo);
                break;

            case CY_BLE_UUID_CHAR_APPEARANCE:
                CY_BLE_GapcCheckCharHandle(cy_ble_gapcConfigPtr->attrInfo[discIdx].appearanceCharHandle,
                                            discCharInfo);
                break;

            case CY_BLE_UUID_CHAR_PERIPH_PRIVCY_FLAG:
                CY_BLE_GapcCheckCharHandle(cy_ble_gapcConfigPtr->attrInfo[discIdx].periphPrivacyCharHandle,
                                            discCharInfo);
                break;

            case CY_BLE_UUID_CHAR_RECONNECTION_ADDR:
                CY_BLE_GapcCheckCharHandle(cy_ble_gapcConfigPtr->attrInfo[discIdx].reconnAddrCharHandle,
                                            discCharInfo);
                break;

            case CY_BLE_UUID_CHAR_PRFRRD_CNXN_PARAM:
                CY_BLE_GapcCheckCharHandle(cy_ble_gapcConfigPtr->attrInfo[discIdx].prefConnParamCharHandle,
                                            discCharInfo);
                break;

            case CY_BLE_UUID_CHAR_CENTRAL_ADDRESS_RESOLUTION:
                CY_BLE_GapcCheckCharHandle(cy_ble_gapcConfigPtr->attrInfo[discIdx].centralAddrResolutionCharHandle,
                                            discCharInfo);
                break;

            case CY_BLE_UUID_CHAR_RESOLVABLE_PRIVATE_ADDR_ONLY:
                CY_BLE_GapcCheckCharHandle(cy_ble_gapcConfigPtr->attrInfo[discIdx].resolvablePrivateAddressOnly, discCharInfo);
                break;

            default:
                break;
        }

        /* Indicate that request was handled */
        cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
    }
}


/******************************************************************************
* Function Name: Cy_BLE_ReadByTypeEventHandler
***************************************************************************//**
*
*  Handles a Read By Type Response event during an automatic server discovery
*  process.
*
*  \param eventParam: The event parameters for a Read By Type Response.
*
******************************************************************************/
static void Cy_BLE_ReadByTypeEventHandler(cy_stc_ble_gattc_read_by_type_rsp_param_t *eventParam)
{
    uint32_t discIdx = Cy_BLE_GetDiscoveryIdx(eventParam->connHandle);
    uint32_t i;
    uint32_t j;

    if((discIdx < cy_ble_configPtr->params->maxClientCount) &&
       (cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag != 0u))
    {
        /* Count of service information pieces in this mtu */
        uint32_t locDataLength = (uint32_t)eventParam->attrData.length;
        uint32_t attrLength = (uint32_t)eventParam->attrData.attrLen;
        uint8_t *attrVal = eventParam->attrData.attrValue;

        if(Cy_BLE_GetConnectionState(eventParam->connHandle) == CY_BLE_CONN_STATE_CLIENT_CHAR_DISCOVERING)
        {
            cy_stc_ble_disc_char_info_t locDiscCharInfo;

            locDiscCharInfo.connHandle = eventParam->connHandle;

            for(i = 0u; i < attrLength; i += locDataLength)
            {
                cy_ble_eventHandlerFlag |= CY_BLE_CALLBACK;

                /* Get Handle for characteristic declaration */
                locDiscCharInfo.charDeclHandle = Cy_BLE_Get16ByPtr(attrVal);
                attrVal += sizeof(locDiscCharInfo.charDeclHandle);

                /* Get Properties for value */
                locDiscCharInfo.properties = *attrVal;
                attrVal += sizeof(locDiscCharInfo.properties);

                /* Get Handle to server database attribute value entry */
                locDiscCharInfo.valueHandle = Cy_BLE_Get16ByPtr(attrVal);
                attrVal += sizeof(locDiscCharInfo.valueHandle);

                /* Get Characteristic UUID (128/16 bit) */
                if(locDataLength == CY_BLE_DISC_CHAR_INFO_128_LEN)
                {
                    locDiscCharInfo.uuidFormat = CY_BLE_GATT_128_BIT_UUID_FORMAT;
                    (void)memcpy(&locDiscCharInfo.uuid.uuid128, attrVal, CY_BLE_GATT_128_BIT_UUID_SIZE);
                    attrVal += CY_BLE_GATT_128_BIT_UUID_SIZE;
                }
                else if(locDataLength == CY_BLE_DISC_CHAR_INFO_LEN)
                {
                    locDiscCharInfo.uuidFormat = CY_BLE_GATT_16_BIT_UUID_FORMAT;
                    locDiscCharInfo.uuid.uuid16 = Cy_BLE_Get16ByPtr(attrVal);
                    attrVal += CY_BLE_GATT_16_BIT_UUID_SIZE;
                }
                else
                {
                    /* Unsupported data length value */
                }

                if((locDataLength == CY_BLE_DISC_CHAR_INFO_128_LEN) || (locDataLength == CY_BLE_DISC_CHAR_INFO_LEN))
                {
                    /* Process common services: GAP and GATT */
                    Cy_BLE_GAPC_DiscoverCharacteristicsEventHandler(&locDiscCharInfo);
                    Cy_BLE_GATTC_DiscoverCharacteristicsEventHandler(&locDiscCharInfo);

                    /* Loop thru all registered services and invoke CY_BLE_EVT_GATTC_DISC_CHAR event */
                    (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)CY_BLE_EVT_GATTC_DISC_CHAR, (void*)&locDiscCharInfo);
                }
            }
            /* The sub-procedure is complete when an Error Response is received and the
             *  Error Code is set to the Attribute Not Found; or the Read By Type Response has an
             *  Attribute Handle equal to the Ending Handle of the request - in this case
             *  a CY_BLE_EVT_GATTC_LONG_PROCEDURE_END event is generated by the BLE Stack. */
            cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
        }
        else if(Cy_BLE_GetConnectionState(eventParam->connHandle) == CY_BLE_CONN_STATE_CLIENT_INCL_DISCOVERING)
        {
            bool exitFlag = false;
            cy_stc_ble_disc_incl_info_t locDiscInclInfo;
            locDiscInclInfo.connHandle = eventParam->connHandle;

            for(i = 0u; (i < attrLength) && (exitFlag == false); i += locDataLength)
            {
                cy_ble_eventHandlerFlag |= CY_BLE_CALLBACK;

                locDiscInclInfo.inclDefHandle = Cy_BLE_Get16ByPtr(attrVal);
                attrVal += sizeof(locDiscInclInfo.inclDefHandle);

                locDiscInclInfo.inclHandleRange.startHandle = Cy_BLE_Get16ByPtr(attrVal);
                attrVal += sizeof(locDiscInclInfo.inclHandleRange.startHandle);

                locDiscInclInfo.inclHandleRange.endHandle = Cy_BLE_Get16ByPtr(attrVal);
                attrVal += sizeof(locDiscInclInfo.inclHandleRange.endHandle);

                if(locDataLength == CY_BLE_DISC_INCL_INFO_128_LEN)
                {
                    cy_stc_ble_gattc_stop_cmd_param_t stopCmdParam;

                    stopCmdParam.connHandle = eventParam->connHandle;
                    locDiscInclInfo.uuidFormat = CY_BLE_GATT_128_BIT_UUID_FORMAT;

                    /* Stop ongoing GATT operation */
                    (void)Cy_BLE_GATTC_StopCmd(&stopCmdParam);

                    /* Save handle to support a read response from device */
                    cy_ble_configPtr->context->discovery[discIdx].inclInfo = locDiscInclInfo;

                    exitFlag = true;
                }
                else if(locDataLength == CY_BLE_DISC_INCL_INFO_LEN)
                {
                    uint32_t discServiNum = cy_ble_configPtr->context->discServiCount;
                    locDiscInclInfo.uuidFormat = CY_BLE_GATT_16_BIT_UUID_FORMAT;
                    locDiscInclInfo.uuid.uuid16 = Cy_BLE_Get16ByPtr(attrVal);
                    attrVal += CY_BLE_GATT_16_BIT_UUID_SIZE;

                    /* Store the range of the included service in the list of services for discovery */
                    for(j = 0u; j < discServiNum; j++)
                    {
                        if( (cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + j].uuid ==
                                locDiscInclInfo.uuid.uuid16) &&
                            (cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + j].range.startHandle ==
                                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE))
                            {
                                cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + j].range =
                                    locDiscInclInfo.inclHandleRange;
                                break;
                            }
                    }
                }
                else
                {
                    /* Unsupported data length value */
                }

                /* Loop thru all registered services and invoke CY_BLE_EVT_GATTC_DISC_INCL event */
                (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)CY_BLE_EVT_GATTC_DISC_INCL, (void*)&locDiscInclInfo);
            }
            cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
        }
        else
        {
            /* Unhandled state value */
        }
    }
}


/******************************************************************************
* Function Name: Cy_BLE_NextCharDiscovery
***************************************************************************//**
*
*  Looks for a characteristic handle range for the current service (pointed by
*   cy_ble_disCount). If the current range is invalid (any of start or end
*   handles is invalid), then increments the cy_ble_disCount and check
*   the next service range and does so until a valid range is caught or the end
*   of the service set is reached.
*
*  \param connHandle:     The connection handle.
*  \param incrementIndex: A non-zero value indicates that the characteristic index
*                         should be incremented.
*
******************************************************************************/
static void Cy_BLE_NextCharDiscovery(cy_stc_ble_conn_handle_t connHandle,
                              uint8_t incrementIndex)
{
    uint32_t locServCount;
    uint32_t discIdx = Cy_BLE_GetDiscoveryIdx(connHandle);
    uint32_t discServiNum = cy_ble_configPtr->context->discServiCount;

    if(incrementIndex != CY_BLE_DISCOVERY_INIT)
    {
        cy_ble_configPtr->context->discovery[discIdx].servCount++;
    }
    else
    {
        cy_ble_configPtr->context->discovery[discIdx].servCount = 0u;
    }

    locServCount = cy_ble_configPtr->context->discovery[discIdx].servCount;

    /* Skip not existing services and services out of the discovery range */
    while((cy_ble_configPtr->context->discovery[discIdx].servCount < discServiNum) &&
          ((cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + locServCount].range.startHandle <
            cy_ble_configPtr->context->discovery[discIdx].gattcDiscoveryRange.startHandle) ||
           (cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + locServCount].range.startHandle >
            cy_ble_configPtr->context->discovery[discIdx].gattcDiscoveryRange.endHandle)))
    {
        ++cy_ble_configPtr->context->discovery[discIdx].servCount;
        locServCount = cy_ble_configPtr->context->discovery[discIdx].servCount;
    }

    if(cy_ble_configPtr->context->discovery[discIdx].servCount < discServiNum)
    {
        cy_stc_ble_gattc_read_by_type_req_t reqParam =
        {
            .connHandle = connHandle,
            .range      = cy_ble_configPtr->context->serverInfo[(discIdx * discServiNum) + locServCount].range
        };

        if(Cy_BLE_GATTC_DiscoverCharacteristics(&reqParam) != CY_BLE_SUCCESS)
        {
            Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_CHAR_DISCOVERY_FAILED, &connHandle);
            cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag = 0u;
        }
    }
    else /* A Characteristic discovery procedure is done, start a descriptor discovery procedure */
    {
        if((cy_ble_eventHandlerFlag & CY_BLE_ENABLE_ALL_EVENTS) != 0u)
        {
            Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_CHAR_DISCOVERY_COMPLETE, &connHandle);
        }
        Cy_BLE_SetConnectionState(connHandle, CY_BLE_CONN_STATE_CLIENT_DESCR_DISCOVERING);
        Cy_BLE_NextCharDscrDiscovery(connHandle, CY_BLE_DISCOVERY_INIT);
    }
}


/******************************************************************************
* Function Name: Cy_BLE_FindInfoEventHandler
***************************************************************************//**
*
*  Handles a Find Info Response event during an automatic server discovery
*  process.
*
*  \param eventParam:  The event parameters for a Find Info Response.
*
******************************************************************************/
static void Cy_BLE_FindInfoEventHandler(cy_stc_ble_gattc_find_info_rsp_param_t *eventParam)
{
    uint32_t discIdx = Cy_BLE_GetDiscoveryIdx(eventParam->connHandle);

    /* Discovery descriptor information */
    cy_stc_ble_disc_descr_info_t locDiscDescrInfo;

    locDiscDescrInfo.descrHandle = CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE;

    if((Cy_BLE_GetConnectionState(eventParam->connHandle) == CY_BLE_CONN_STATE_CLIENT_DESCR_DISCOVERING) &&
       (discIdx < cy_ble_configPtr->params->maxClientCount) &&
       (cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag != 0u))
    {
        uint32_t attrLength = eventParam->handleValueList.byteCount;    /* Number of elements on list in bytes */
        uint32_t locDataLength;
        uint32_t i;
        uint8_t *attrVal;

        locDiscDescrInfo.uuidFormat = eventParam->uuidFormat;
        locDiscDescrInfo.connHandle = eventParam->connHandle;

        if(locDiscDescrInfo.uuidFormat == CY_BLE_GATT_16_BIT_UUID_FORMAT)
        {
            locDataLength = CY_BLE_DB_ATTR_HANDLE_LEN + CY_BLE_GATT_16_BIT_UUID_SIZE;
        }
        else
        {
            locDataLength = CY_BLE_DB_ATTR_HANDLE_LEN + CY_BLE_GATT_128_BIT_UUID_SIZE;
        }
        attrVal = eventParam->handleValueList.list;

        for(i = 0u; i < attrLength; i += locDataLength)
        {
            cy_ble_eventHandlerFlag |= CY_BLE_CALLBACK;

            locDiscDescrInfo.descrHandle = Cy_BLE_Get16ByPtr(attrVal);
            attrVal += CY_BLE_DB_ATTR_HANDLE_LEN;


            if(locDiscDescrInfo.uuidFormat == CY_BLE_GATT_128_BIT_UUID_FORMAT)
            {
                (void)memcpy(&locDiscDescrInfo.uuid.uuid128, attrVal, CY_BLE_GATT_128_BIT_UUID_SIZE);
                attrVal += CY_BLE_GATT_128_BIT_UUID_SIZE;
            }
            else
            {
                locDiscDescrInfo.uuid.uuid16 = Cy_BLE_Get16ByPtr(attrVal);
                attrVal += CY_BLE_GATT_16_BIT_UUID_SIZE;
            }

            /* Process common services: GATT */
            Cy_BLE_GATTC_DiscoverCharDescriptorsEventHandler(&locDiscDescrInfo);

            /* Loop thru all registered services and invoke CY_BLE_EVT_GATTC_DISC_CHAR event */
            (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)CY_BLE_EVT_GATTC_DISC_DESCR, (void*)&locDiscDescrInfo);
        }

        /* The sub-procedure is complete when an Error Response is received and the
         * Error Code is set to the Attribute Not Found or the Find Information Response has
         * an Attribute Handle that is equal to the Ending Handle of the request in this
         * case a CY_BLE_EVT_GATTC_LONG_PROCEDURE_END event is generated by the BLE Stack. */

        cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
    }
}


/******************************************************************************
* Function Name: Cy_BLE_NextCharDscrDiscovery
***************************************************************************//**
*
*  Looks for a handle range for the current descriptor (pointed by
*   cy_ble_discovery[discIdx].servCount). If the current range is invalid (any of start or end
*   handles is invalid), then increments the cy_ble_discovery[discIdx].servCount and check
*   the next descriptor range and does so until a valid range is caught or the
*   end of the descriptor set is reached.
*
*  \param connHandle:     The connection handle.
*  \param incrementIndex: A non-zero value indicates that the characteristic index should be
*                         incremented.
*
******************************************************************************/
static void Cy_BLE_NextCharDscrDiscovery(cy_stc_ble_conn_handle_t connHandle,
                                  uint8_t incrementIndex)
{
    uint32_t discIdx = Cy_BLE_GetDiscoveryIdx(connHandle);
    cy_stc_ble_disc_range_info_t charRangeInfo = { .connHandle = connHandle, .srviIncIdx = incrementIndex };

    do
    {
        cy_ble_eventHandlerFlag |= CY_BLE_CALLBACK;
        charRangeInfo.range.startHandle = CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE;
        charRangeInfo.range.endHandle = CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE;

        if(incrementIndex == CY_BLE_DISCOVERY_INIT)
        {
            cy_ble_configPtr->context->discovery[discIdx].servCount = 0u;
            cy_ble_configPtr->context->discovery[discIdx].charCount = 0u;
            incrementIndex = CY_BLE_DISCOVERY_CONTINUE;

        }

        /* Get a possible range of the common service: GATT */
        Cy_BLE_GATTC_GetCharRange(&charRangeInfo);

        /* Loop thru all registered services and get a possible range of the characteristic descriptor */
        (void)Cy_BLE_InvokeServiceEventHandler((uint32_t)CY_BLE_EVT_GATTC_DISC_DESCR_GET_RANGE, (void*)&charRangeInfo);

        if((charRangeInfo.range.startHandle == CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE) ||
           (charRangeInfo.range.endHandle == CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE))
        {
            cy_ble_configPtr->context->discovery[discIdx].servCount++;
            cy_ble_configPtr->context->discovery[discIdx].charCount = 0u;
            charRangeInfo.srviIncIdx = CY_BLE_DISCOVERY_INIT;
        }
        else
        {
            charRangeInfo.srviIncIdx = CY_BLE_DISCOVERY_CONTINUE;
        }

        /* Skip not existing characteristics and characteristics out of discovery range */
    }
    while( ((charRangeInfo.range.startHandle <= cy_ble_configPtr->context->discovery[discIdx].gattcDiscoveryRange.startHandle) ||
            (charRangeInfo.range.startHandle > cy_ble_configPtr->context->discovery[discIdx].gattcDiscoveryRange.endHandle) ||
            (charRangeInfo.range.endHandle < cy_ble_configPtr->context->discovery[discIdx].gattcDiscoveryRange.startHandle) ||
           (charRangeInfo.range.startHandle > charRangeInfo.range.endHandle)) &&
           (cy_ble_configPtr->context->discovery[discIdx].servCount < cy_ble_configPtr->context->discServiCount) );

    if(cy_ble_configPtr->context->discovery[discIdx].servCount < cy_ble_configPtr->context->discServiCount)
    {
        cy_stc_ble_gattc_find_info_req_t reqParam;

        /* Fill Error Response parameters */
        reqParam.connHandle = connHandle;
        reqParam.range      = charRangeInfo.range;

        if(Cy_BLE_GATTC_DiscoverCharacteristicDescriptors(&reqParam) != CY_BLE_SUCCESS)
        {
            Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_DESCR_DISCOVERY_FAILED, &connHandle);
            cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag = 0u;
        }
    }
    else /* Discovery done */
    {
        Cy_BLE_SetConnectionState(connHandle, CY_BLE_CONN_STATE_CLIENT_DISCOVERED);
        Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_DISCOVERY_COMPLETE, &connHandle);
        cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag = 0u;
    }
}


/******************************************************************************
* Function Name: Cy_BLE_LongProcedureEndEventHandler
***************************************************************************//**
*
*  Handles a Long Procedure End event during an automatic server discovery
*  process.
*
*  \param connHandle:  The connection handle.
*
******************************************************************************/
static void Cy_BLE_LongProcedureEndEventHandler(cy_stc_ble_conn_handle_t connHandle)
{
    uint32_t discIdx = Cy_BLE_GetDiscoveryIdx(connHandle);

    if((discIdx < cy_ble_configPtr->params->maxClientCount) &&
       (cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag != 0u))
    {
        cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;

        switch(Cy_BLE_GetConnectionState(connHandle))
        {
            case CY_BLE_CONN_STATE_CLIENT_SRVC_DISCOVERING:
                if((cy_ble_eventHandlerFlag & CY_BLE_ENABLE_ALL_EVENTS) != 0u)
                {
                    Cy_BLE_ApplCallback((uint32_t)CY_BLE_EVT_GATTC_SRVC_DISCOVERY_COMPLETE, &connHandle);
                }
                Cy_BLE_SetConnectionState(connHandle, CY_BLE_CONN_STATE_CLIENT_INCL_DISCOVERING);
                Cy_BLE_NextInclDiscovery(connHandle, CY_BLE_DISCOVERY_INIT);
                /* Do not propagate this event to the application level during an automatic discovery procedure */
                cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
                break;

            case CY_BLE_CONN_STATE_CLIENT_INCL_DISCOVERING:
                Cy_BLE_NextInclDiscovery(connHandle, CY_BLE_DISCOVERY_CONTINUE);
                cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
                break;

            case CY_BLE_CONN_STATE_CLIENT_CHAR_DISCOVERING:
                Cy_BLE_NextCharDiscovery(connHandle, CY_BLE_DISCOVERY_CONTINUE);
                cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
                break;

            case CY_BLE_CONN_STATE_CLIENT_DESCR_DISCOVERING:
                Cy_BLE_NextCharDscrDiscovery(connHandle, CY_BLE_DISCOVERY_CONTINUE);
                cy_ble_eventHandlerFlag &= (uint8_t) ~CY_BLE_CALLBACK;
                break;

            default:
                break;
        }
    }
}


/******************************************************************************
* Function Name: Cy_BLE_ErrorResponseEventHandler
***************************************************************************//**
*
*  Handles an Error Response event during an automatic server discovery
*  process.
*
*  \param eventParam:  The event parameters for an Error Response.
*
******************************************************************************/
static void Cy_BLE_ErrorResponseEventHandler(const cy_stc_ble_gatt_err_param_t *eventParam)
{
    uint32_t discIdx = Cy_BLE_GetDiscoveryIdx(eventParam->connHandle);

    if( (discIdx < cy_ble_configPtr->params->maxClientCount) &&
        (cy_ble_configPtr->context->discovery[discIdx].autoDiscoveryFlag != 0u) &&
        (eventParam->errInfo.errorCode == CY_BLE_GATT_ERR_ATTRIBUTE_NOT_FOUND) )
    {
        Cy_BLE_LongProcedureEndEventHandler(eventParam->connHandle);
    }
}

#endif /* CY_BLE_LIB_HOST_CORE */
#endif /* CY_IP_MXBLESS */


/* [] END OF FILE */
