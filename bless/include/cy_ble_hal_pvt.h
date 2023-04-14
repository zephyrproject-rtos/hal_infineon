/***************************************************************************//**
* \file cy_ble_hal_pvt.h
* \version 3.60
*
* \brief
*  Contains the function prototypes and constants for the HAL section
*  of the PSoC 6 BLE Middleware.
*
********************************************************************************
* \copyright
* Copyright 2017-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef CY_BLE_HALL_PVT_H
#define CY_BLE_HALL_PVT_H

#include <stdlib.h>

#include "cy_device.h"
#include "cy_ble_stack_pvt.h"
#include "cy_ble.h"

/* system resources */
#include "cy_syspm.h"
#include "cy_flash.h"
#include "cy_ipc_pipe.h"
#include "cy_sysclk.h"
#include "cy_ipc_sema.h"
#include "cy_ble_clk.h"

#if defined(CY_IP_MXBLESS)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*******************************************************************************
*   HAL Constants
*******************************************************************************/

#define CY_BLE_HCI_COMMAND_SUCCEEDED                                    (0x00u)
#define CY_BLE_UNKNOWN_HCI_COMMAND_ERROR                                (0x01u)

#define CY_BLE_CYPIPE_MSG_COMPLETE_ID                                   (0u)
#define CY_BLE_CYPIPE_MSG_SEND_ID                                       (1u)
#define CY_BLE_CYPIPE_MSG_CMD_ID                                        (3u)

/* Common IPC commands (used by middleware) */
#define CY_BLE_CYPIPE_INTR_NOTIFY_CMD                                   (0xFFu)
#define CY_BLE_CYPIPE_ENABLE_CONTR_CMD                                  (0x01u)

/* Other */
#define CY_BLE_FLASH_OPR_TIMEOUT                                        (200u)

#define CY_BLE_IPC_CONTROLLER_ADDR                                      (CY_IPC_EP_CYPIPE_CM0_ADDR)
#define CY_BLE_IPC_HOST_ADDR                                            (CY_IPC_EP_CYPIPE_CM4_ADDR)

#define CY_BLE_SFLASH_BLE_RADIO_CALL_ADDRESS                            ((uint32_t)SFLASH_BLE_DEVICE_ADDRESS + sizeof(cy_stc_ble_bd_addr_t))

/* Flash blocking mode(define for mode in Cy_BLE_HAL_NvramWrite function ) */
#define CY_BLE_FLASH_BLOCKING_MODE                                      (1u)

/* Flash non blocking mode(define for mode in Cy_BLE_HAL_NvramWrite function )*/
#define CY_BLE_FLASH_NON_BLOCKING_MODE                                  (0u)

/* Constants for Voltage value calculation  */
#define CY_BLE_RADIO_VOLTAGE_MONITOR_SLOPE                              (174u)
#define CY_BLE_RADIO_VOLTAGE_MONITOR_SLOPE_MULTIPLIER                   (10u)
#define CY_BLE_RADIO_VOLTAGE_MONITOR_OFFSET                             (879u)

/* Constants for Temperature value calculation  */
#define CY_BLE_RADIO_TEMP_MONITOR_SLOPE                                 (10315)
#define CY_BLE_RADIO_TEMP_MONITOR_SLOPE_MULTIPLIER                      (10000)
#define CY_BLE_RADIO_TEMP_MONITOR_OFFSET                                (189)

/* Default BLE ECO settings */
#define CY_BLE_DEFAULT_OSC_STARTUP_DELAY_LF                             (25u)
#define CY_BLE_DEFAULT_CAP_TRIM_VALUE                                   (32u)
#define CY_BLE_DEFAULT_BLESS_ECO_FREQ                                   (CY_BLE_BLESS_ECO_FREQ_32MHZ)
#define CY_BLE_DEFAULT_SYS_ECO_CLK_DIV                                  (CY_BLE_SYS_ECO_CLK_DIV_4)
#define CY_BLE_DEFAULT_CY_BLE_ECO_VOLTAGE_REG                           (CY_BLE_ECO_VOLTAGE_REG_AUTO)

/* Package type */
#define CY_BLE_PACKAGE_QFN                                              (0u)
#define CY_BLE_PACKAGE_BGA                                              (1u)
#define CY_BLE_PACKAGE_CSP                                              (2u)

/* Package HW Block */
#define CY_BLE_PACKAGE_HW_BLOCK_USB                                     (0x01UL << 1u)

/* Constants for PILO */
/* Target frequency */
#define CY_BLE_PILO_TARGET_FREQ                                         (32768ul)

/* Nominal trim step size */
#define CY_BLE_PILO_TRIM_STEP                                           (5ul)

/* BLESS Syspm callback's order */
#if !defined(CY_BLE_LPM_SYSPM_CB_ORDER)
    #define CY_BLE_LPM_SYSPM_CB_ORDER                                   (254u)
#endif  /* !defined(CY_BLE_LPM_SYSPM_CB_ORDER) */



/*******************************************************************************
* Data Types
*******************************************************************************/

/** \cond IGNORE */
typedef struct
{
    uint8_t  clientID;
    uint8_t  pktType;
    uint16_t intrRelMask;
    bool     controllerStarted;
    uint32_t data;
    uint16_t dataLen;
} cy_stc_ble_ipc_msg_t;

typedef enum
{
    CY_BLE_IC_PACKAGE_TYPE_BGA_116 = 0ul,
    CY_BLE_IC_PACKAGE_TYPE_CSP_104,
    CY_BLE_IC_PACKAGE_TYPE_BGA_124,
    CY_BLE_IC_PACKAGE_TYPE_QFN_68,
}cy_en_ble_ic_package_type_t;
/** \endcond */



/*******************************************************************************
* Function Prototypes
*******************************************************************************/

void Cy_BLE_HAL_BlessStart(void);
cy_en_ble_api_result_t Cy_BLE_HAL_RegisterCommonPipeCallback(void);

void Cy_BLE_HAL_DelayUs(uint16_t delayVal);
void Cy_BLE_HAL_DelayMs(uint32_t delayVal);

void Cy_BLE_HAL_EnableBlessInterrupt(void);
void Cy_BLE_HAL_DisableBlessInterrupt(void);

uint32_t Cy_BLE_HAL_GetIpBlockVersion(void);
uint32_t Cy_BLE_HAL_GetIcPackageType(void);
uint64_t Cy_BLE_HAL_GetUniqueId(void);
uint16_t Cy_BLE_HAL_GetSiliconId(void);
bool Cy_BLE_HAL_IsDefinedTx5dbm(void);

uint32_t Cy_BLE_HAL_EnterCriticalSection(void);
void Cy_BLE_HAL_ExitCriticalSection(uint32_t interruptState);
cy_en_syspm_status_t Cy_BLE_HAL_SysPmSleep(cy_en_syspm_waitfor_t enWaitFor);
void Cy_BLE_HAL_SimoBuckSetVoltage2(cy_en_syspm_simo_buck_voltage2_t voltage);

/* Stack Interface to clock */
uint8_t Cy_BLE_HAL_IsEcoCpuClockSrc(void);
uint8_t Cy_BLE_HAL_IsWcoLfclkSrc(void);
uint32_t Cy_BLE_HAL_EcoGetFrequency(void);
int32_t Cy_BLE_HAL_ClkMeasurementCountersDone(void);
uint32_t Cy_BLE_HAL_ClkMeasurementCountersGetFreq(bool measuredClock, uint32_t refClkFreq);
uint32_t Cy_BLE_HAL_StartClkMeasurementCounters(cy_en_meas_clks_t clock1, uint32_t count1, cy_en_meas_clks_t clock2);
int32_t Cy_BLE_HAL_PiloTrim(uint32_t piloFreq);
cy_en_clklf_in_sources_t Cy_BLE_HAL_LfClkGetSource(void);
#if ((CY_SYSCLK_DRV_VERSION_MAJOR == 2) && (CY_SYSCLK_DRV_VERSION_MINOR <= 10)) || \
     (CY_SYSCLK_DRV_VERSION_MAJOR < 2)
void Cy_BLE_HAL_SetPiloTrimStep(uint32_t stepSize);
int32_t Cy_BLE_HAL_TryPiloTrim(uint32_t piloFreq, uint32_t targetFreq, uint32_t stepSize);
#endif /* (CY_SYSCLK_DRV_VERSION_MAJOR == 2) && (CY_SYSCLK_DRV_VERSION_MINOR <= 10) */
cy_en_ble_api_result_t Cy_BLE_HAL_EnableDefaultEco(void);

/* Stack Interface to flash */
cy_en_ble_api_result_t Cy_BLE_HAL_NvramWrite(const uint8_t buffer[], const uint8_t varFlash[],
                                             uint32_t length, uint32_t mode);
cy_en_ble_api_result_t Cy_BLE_HAL_StackNvramWrite(const uint8_t buffer[], const uint8_t varFlash[], uint32_t length);
bool Cy_BLE_HAL_NvramWriteIsBusy(void);

/* CRC APIs */
uint8_t Cy_BLE_HAL_CalcCRC8(uint8_t data[], uint32_t length);
uint8_t Cy_BLE_HAL_BlockCalcCRC8(uint8_t data[], uint32_t length, uint8_t crcSeed);

cy_en_ble_api_result_t Cy_BLE_HAL_RadioCalibrationRead(void *data, uint32_t length);
cy_en_ble_api_result_t Cy_BLE_HAL_RadioCalibrationWrite(const void *data, uint32_t length);

/* API for calculating absolute values for Temperature and Voltage monitor */
void Cy_BLE_HAL_RadioGetAbsVbat(const uint16_t *raw, uint16_t *vbat);
void Cy_BLE_HAL_RadioGetAbsTemp(const uint16_t *raw, int16_t *temp);

void Cy_BLE_HAL_SetConfigStructure(const cy_stc_ble_config_t *configPtr);


void Cy_BLE_HAL_MappingEccHeapInit(uint8_t *heapMem, uint8_t numOfConn);
void Cy_BLE_HAL_MappingEccHeapDeInit(void);
uint16_t Cy_BLE_HAL_MappingEccGetFeatureHeapReq(uint8_t numOfConn);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingEccGenerateSecurityKeypair(uint8_t p_publicKey[],
                                                                    uint8_t p_privateKey[],
                                                                    uint8_t random[]);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingEccGenerateDHKey(const uint8_t p_publicKey[],
                                                          const uint8_t p_privateKey[],
                                                          uint8_t p_secret[], uint8_t ci);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingEccValidPublicKey(const uint8_t p_publicKey[]);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingPairingLocalPublicKeyHandler(void *param);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingPairingRemoteKeyHandler(void *param);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingPairingDhkeyHandler(void *param);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingPairingDhkeyCheckHandler(void *param);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingPairingKeypressNotificationHandler(void *param);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingPairingRandHandler(void * param);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingPairingConfirmHandler(void *param);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingPairingLrConfirmingHandler(void *param);
void Cy_BLE_HAL_MappingTbxDhkeyGenerateComplete(void *param);
void Cy_BLE_HAL_MappingTbxLocalPubkeyGenerateComplete(void *param);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingTbxGenerateLocalP256PublicKey(uint8_t param);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingTbxGenerateDHkey(void  *param1, void  *param2, uint8_t param3);
void Cy_BLE_HAL_MappingSmpScCmacComplete(uint8_t param);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingSeSmpScUserPasskeyHandler(void *param, void *param2);
void Cy_BLE_HAL_MappingEccPointMult(uint8_t param);

void Cy_BLE_HAL_UART_Start(void);
void Cy_BLE_HAL_UART_Stop(void);
void Cy_BLE_HAL_UART_Transmit(uint8_t *dataBuf, uint8_t length);
void Cy_BLE_HAL_UART_Interrupt(void);
void Cy_BLE_HAL_UART_EnableInterrupt(void);
void Cy_BLE_HAL_UART_DisableInterrupt(void);

void Cy_BLE_HAL_EnableControllerIpcPipeInterrupt(void);
void Cy_BLE_HAL_DisableControllerIpcPipeInterrupt(void);
void Cy_BLE_HAL_EnableHostIpcPipeInterrupt(void);
void Cy_BLE_HAL_DisableHostIpcPipeInterrupt(void);

cy_en_ble_api_result_t Cy_BLE_MappingIsControllerActive(cy_en_ble_controller_sleep_mode_t checkForMode);
bool Cy_BLE_HAL_MappingBlessInterruptHandler(void);
void Cy_BLE_MappingLlIsrExitLowPowerMode(void);
void Cy_BLE_HAL_MappingUartRxDataHandler(uint8_t byte);
void Cy_BLE_HAL_MappingUartTxCompltHandler(void);
void Cy_BLE_HAL_MappingSoftHciHostReceiveControllerPkt(cy_stc_ble_hci_tx_packet_info_t *hciPkt);
cy_en_ble_api_result_t Cy_BLE_HAL_MappingSoftHciControllerReceiveHostPkt(cy_stc_ble_hci_tx_packet_info_t *hciPkt);
cy_en_ble_lp_mode_t Cy_BLE_MappingStackEnterLPM(cy_en_ble_lp_mode_t pwrMode);


cy_en_ipc_pipe_status_t Cy_BLE_IPC_ControllerRegisterClientCallbacks(cy_ipc_pipe_callback_ptr_t ctrlMsgRecvCallBack,
                                                                     cy_ipc_pipe_callback_ptr_t ctrlMsgFlushRecvCallBack);
cy_en_ipc_pipe_status_t Cy_BLE_IPC_SendMessageToHost(uint32_t *msg,
                                                     cy_ipc_pipe_relcallback_ptr_t controllerIpcRelCallBack,
                                                     cy_ipc_pipe_relcallback_ptr_t controllerPollCallBack);


cy_en_ipc_pipe_status_t Cy_BLE_IPC_HostRegisterClientCallbacks(cy_ipc_pipe_callback_ptr_t hostMsgRecvCallBack,
                                                               cy_ipc_pipe_callback_ptr_t hostMsgFlushRecvCallBack);
cy_en_ipc_pipe_status_t Cy_BLE_IPC_SendMessageToController(uint32_t *msg,
                                                           cy_ipc_pipe_relcallback_ptr_t hostIpcRelCallBack,
                                                           cy_ipc_pipe_relcallback_ptr_t hostPollCallBack);

void Cy_BLE_HAL_IntrNotifyIpcHandler(void);
extern cy_ble_intr_callback_t Cy_BLE_InterruptCallback;
extern cy_stc_ble_intr_notify_t *intrNotifyPtr;

/* APIs to support Soft HCI mode  */
cy_en_ble_api_result_t Cy_BLE_HAL_SoftHciHostWritePkt(cy_stc_ble_hci_tx_packet_info_t *hciPktParams);
void Cy_BLE_HAL_SoftHciHostReceiveControllerPkt(cy_stc_ble_hci_tx_packet_info_t *hciPkt);
cy_en_ble_api_result_t Cy_BLE_HAL_SoftHciControllerReceiveHostPkt(cy_stc_ble_hci_tx_packet_info_t *hciPkt);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CY_IP_MXBLESS */
#endif /* CY_BLE_HALL_PVT_H  */

/* [] END OF FILE */
