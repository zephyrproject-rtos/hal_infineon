/**************************************************************************//**
* \file cy_ble_stack_pvt.h
* \version 3.60
*
* \brief
*  Contains the function prototypes and constants for the HAL section.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2017-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef CY_BLE_CY_BLE_STACK_PVT_H
#define CY_BLE_CY_BLE_STACK_PVT_H

#include "cy_ble_stack.h"
#include "cy_sysclk.h"
#include "cy_syspm.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/***************************************
* Data Types
***************************************/
/**
 * Structure containing the parameters required for IPC message from controller to Host 
 */
typedef struct 
{
    /** ID of the message client*/
    uint8_t     clientID;
    /** Type of message */
    uint8_t     pktType;
    /** Message Interrupt Rel. Mask */
    uint16_t    intrRelMask;
    /** Pointer to Data in message */
    uint32_t    pktDataPointer;
    /** Meta Data of the message */
    uint16_t    pktMetaData;

}cy_stc_ble_ipc_ctrl_msg;


/***************************************
*   Function Prototypes
***************************************/

cy_en_ble_api_result_t Cy_BLE_ControllerIpcHalSendEnqueue(cy_stc_ble_ipc_ctrl_msg* msg);
void Cy_BLE_LlIsrExitLowPowerMode(void);

    
/***************************************
*     Stack manager prototypes
***************************************/

/* External definitions for BLE Stack ISR handler */
extern bool Cy_BLE_HAL_BlessInterruptHandler(void);

/* To be used only for HCI_MODE and in Debug mode
* where the logger serial port is enabled
*/
extern void Cy_BLE_HAL_UartTxCompltHandler(void);

/* To be used only for HCI_MODE */
extern void Cy_BLE_HAL_UartRxDataHandler(uint8_t byte);

/* To be used only for Host MODE */
extern void Cy_BLE_HAL_HciTransportHandler(char_t packet, uint16_t packet_len);

/* To be used only for Host UART/Soft HCI Mode */
extern void Cy_BLE_HAL_SoftControllerProcessEventsWrapper(void);
extern void Cy_BLE_HAL_ControllerEnablePrivacyFeatureWrapper(void);
extern void Cy_BLE_HAL_ControllerEnableDleFeatureWrapper(void);
extern void Cy_BLE_HAL_ControllerEnablePhyUpdateFeaturWrapper(void);
extern cy_en_ble_api_result_t Cy_BLE_HAL_ControllerSetFeatureConfigWrapper(const cy_stc_ble_stack_config_param_t *configParam,uint16_t *featureHeapReq);
extern cy_en_ble_lp_mode_t Cy_BLE_HAL_ControllerEnterLPMWrapper(cy_en_ble_lp_mode_t pwrMode);
extern cy_en_ble_api_result_t Cy_BLE_HAL_ControllerValidateInputParamsWrapper(const cy_stc_ble_stack_init_info_t *initParam);
extern cy_en_ble_api_result_t Cy_BLE_HAL_ControllerGetHeapMemoryWrapper(uint16_t *memorySize);
extern cy_en_ble_lp_mode_t Cy_BLE_HAL_ControllerExitLPMWrapper(void);
extern cy_en_ble_api_result_t Cy_BLE_HAL_ControllerInitWrapper(cy_stc_ble_stack_init_info_t *initParam);
extern void Cy_BLE_HAL_Pilo_InitCalibrationWrapper(void);
extern void Cy_BLE_HAL_Pilo_TriggerCalibrationWrapper(void);
extern cy_en_ble_api_result_t Cy_BLE_HAL_ControllerGetInternalHeapReqWrapper(uint16_t *memorySize);
extern cy_en_ble_api_result_t Cy_BLE_HAL_StackMgr_BleSSInitWrapper(uint8 persistRadioCal);
extern cy_en_ble_api_result_t Cy_BLE_HAL_ControllerResetWrapper(void);
extern void Cy_BLE_HAL_StackMgr_BleSSShutdownWrapper(void);
extern void Cy_BLE_HAL_Pilo_ShutdownCalibrationWrapper(void);
extern cy_stc_ble_stack_config_param_t* Cy_BLE_HAL_StackGetConfigPtrWrapper(void);
extern void * Cy_BLE_HAL_llf_task_start_routineWrapper(void * args);
extern void Cy_BLE_HAL_BT_timer_process_signalsWrapper(void *arg);


/***************************************
*     Macros
***************************************/
#define CY_BLE_INTR_TX_SUCCESS       0x00u
#define CY_BLE_INTR_TX_DONE          0x00u
#define CY_BLE_INTR_TX_OVERFLOW      0x01u

#define CY_BLE_INTR_RX_SUCCESS       0x00u
#define CY_BLE_INTR_RX_NOT_EMPTY     0x00u
#define CY_BLE_INTR_RX_OVERFLOW      0x01u
#define CY_BLE_INTR_RX_FRAME_ERROR   0x02u
#define CY_BLE_INTR_RX_PARITY_ERROR  0x04u


/* Align buffer size value to 4 */
#define CY_BLE_STACK_ALIGN_TO_4(x)      ((((x) & 3u) == 0u) ?    \
                                        (x) :                    \
                                        (((x) - ((x) & 3u)) + 4u))
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CY_BLE_CY_BLE_STACK_PVT_H  */

/* [] END OF FILE */
