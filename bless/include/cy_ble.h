/***************************************************************************//**
* \file cy_ble.h
* \version 3.60
*
* \brief
*  Contains the prototypes and constants used in the PSoC 6 BLE Middleware.
*
********************************************************************************
* \copyright
* Copyright 2017-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#ifndef CY_BLE_H
#define CY_BLE_H


#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <cy_device_headers.h>

#include "cy_syslib.h"
#include "cy_sysint.h"
#include "cy_syspm.h"
#include "cy_scb_uart.h"

// #include "cy_ble_gatt.h"
// #include "cy_ble_gap.h"

#if defined(CY_IP_MXBLESS)


/***************************************
* BLE Stack includes
***************************************/

#include "cy_ble_stack.h"
// #include "cy_ble_stack_host_main.h"
// #include "cy_ble_stack_host_error.h"
// #include "cy_ble_stack_gap.h"
// #include "cy_ble_stack_gap_central.h"
// #include "cy_ble_stack_gap_peripheral.h"
// #include "cy_ble_stack_gatt_server.h"
// #include "cy_ble_stack_gatt_client.h"
// #include "cy_ble_stack_gatt_db.h"
// #include "cy_ble_stack_l2cap.h"

/* The C binding of definitions if building with the C++ compiler */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*******************************************************************************
* API Constants
*******************************************************************************/

/** Library major version */
#define CY_BLE_MW_VERSION_MAJOR              (3)

/** Library minor version */
#define CY_BLE_MW_VERSION_MINOR              (60)

#define CY_BLE_M0S8BLESS_VERSION             (4u)
#define CY_BLE_SEMA                          (3u)

/* Align the buffer size value to 4 */
#define CY_BLE_ALIGN_TO_4(x)                 ((((x) & 3u) == 0u) ? (x) : (((x) - ((x) & 3u)) + 4u))

#define CY_BLE_MTU_MIN_VALUE                 (23u)
#define CY_BLE_MTU_MIN_BUFF_NUM              (3u)

/* Package type constants */
#define CY_BLE_PACKAGE_TYPE_MASK             (0x00FFu)
#define CY_BLE_PACKAGE_PIN_NUM_MASK          (0xFF00u)
#define CY_BLE_PACKAGE_PIN_NUM_OFFSET        (8u)


/* Support Host side only on CM4 core */
#if !defined(CY_BLE_LIB_HOST_CORE)
    #if defined(COMPONENT_BLESS_HOST) || defined(COMPONENT_BLESS_HOST_IPC)
        #define CY_BLE_LIB_HOST_CORE                 (1)
    #else
        #define CY_BLE_LIB_HOST_CORE                 (0)
    #endif /* defined(COMPONENT_BLESS_HOST) || defined(COMPONENT_BLESS_HOST_IPC) */
#endif /* !defined(CY_BLE_LIB_HOST_CORE) */

/*
* These defines are obsolete and kept for backward compatibility only.
* They will be removed in the future versions.
*/
#define CY_BLE_MIDDLEWARE_VERSION_MAJOR      (CY_BLE_MW_VERSION_MAJOR)
#define CY_BLE_MIDDLEWARE_VERSION_MINOR      (CY_BLE_MW_VERSION_MINOR)


/*******************************************************************************
* Data Types
*******************************************************************************/

/**
 * \addtogroup group_ble_common_api_definitions
 * \{
 */
/** Interrupt callback feature */
typedef enum
{
    /** Interrupt callback feature is disabled */
    CY_BLE_INTR_CALLBACK_NONE                        = (0x00),

    /** Executed on every trigger of BLESS interrupt. */
    CY_BLE_INTR_CALLBACK_BLESS_STACK_ISR             = (0x01UL << 1u),

    /** Executed when the BLESS exits BLESS deep sleep mode and enters BLESS active mode.
     *  BLESS deep sleep exit can be triggered automatically by link layer hardware
     *  or by different BLE_PDL data transfer APIs that need BLESS to be active.
     */
    CY_BLE_INTR_CALLBACK_BLESS_INTR_STAT_DSM_EXITED  = (0x01UL << 2u),

    /** Executed when the BLESS connection engine in slave mode detects a BLE packet
     *  that matches its access address.
     */
    CY_BLE_INTR_CALLBACK_BLELL_CONN_EXT_INTR_EARLY   = (0x01UL << 3u),

    /** Executed when the BLESS connection engine receives a non-empty packet from
     *  the peer device.
     */
    CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CE_RX       = (0x01UL << 4u),

    /** Executed when the BLESS connection engine receives an ACK packet from the peer
     *  device for the previously transmitted packet.
     */
    CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CE_TX_ACK   = (0x01UL << 5u),

    /** Executed when the BLESS connection engine closes the connection event.
     *  This interrupt will be executed on every connection interval for a connection,
     *  irrespective of data tx/rx state.
     */
    CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CLOSE_CE    = (0x01UL << 6u),

    /** Executed when the BLESS enters deep sleep mode. User call to Cy_SysPm_DeepSleep API
     *  will trigger BLESS deep sleep entry sequence.
     */
    CY_BLE_INTR_CALLBACK_BLESS_INTR_STAT_DSM_ENTERED = (0x01UL << 7u),

    /** Executed when the BLESS scan engine receives an advertisement packet from the
     *  peer device
     */
    CY_BLE_INTR_CALLBACK_BLELL_SCAN_INTR_ADV_RX      =  (0x01UL << 8u),

    /** Executed when the BLESS scan engine receives a scan response packet from the peer
     *  device in response to a scan request from the scanner.
     */
    CY_BLE_INTR_CALLBACK_BLELL_SCAN_INTR_SCAN_RSP_RX = (0x01UL << 9u),

    /** Executed when the BLESS advertisement engine receives a connection request from
     *  the peer central device
     */
    CY_BLE_INTR_CALLBACK_BLELL_ADV_INTR_CONN_REQ_RX  = (0x01UL << 10UL),
} cy_en_ble_interrupt_callback_feature_t;
/** \} group_ble_common_api_definitions */

/**
 * \addtogroup group_ble_common_api_gap_definitions
 * \{
 */
/** The event callback function prototype to receive events from the PSoC 6 BLE Middleware */
typedef void (* cy_ble_callback_t) (uint32_t eventCode, void *eventParam);

/** Application Notify Callback */
typedef void (* cy_ble_app_notify_callback_t) (void);
/** \} */

typedef void (* cy_ble_intr_callback_t) (uint32_t interruptType);

/**
* Pointer to function initializes services.
*/
typedef void (* cy_fn_service_init_t)(void);

/** \cond IGNORE */
/* Interrupt notification feature structure */
typedef struct
{
    uint8_t  clientID;
    uint8_t  pktType;
    uint16_t intrRelMask;

    bool     configFlag;        /* Flag indicates that Controller receive
                                 * address of structure */
    uint32_t mask;              /* Mask of interrupts   */
    uint32_t data;              /* Detected interrupt type */

    uint8_t userIpcChan;        /* IPC channel. Used only in BLE dual CPU mode */
    uint8_t userIpcIntr;        /* IPC Interrupt structure. Used only in BLE dual CPU mode */
    uint8_t userIpcIntrPrior;   /* IPC Interrupt priority. Used only in BLE dual CPU mode */

} cy_stc_ble_intr_notify_t;
/** \endcond */

/** Structure to store bonding data */
typedef struct
{
    /** Bonding data storage */
    uint8_t *stackFlashPtr;     /** Pointer to bonding data storage in auxiliary flash */
    uint32_t stackFlashSize;    /** Buffer size in auxiliary flash */

    /** CCCD data storage */
    uint8_t *cccdFlashPtr;      /** Pointer to CCCD values storage in auxiliary flash */
    uint8_t *cccdRamPtr;        /** Pointer to CCCD values storage in RAM */
    uint8_t  cccdCount;         /** Number of CCCD */

} cy_stc_ble_flash_storage_t;

/** BLE Configuration parameters structure */
typedef struct
{
    /** Silicon Device Address Enabled */
    bool                      siliconDeviceAddressEn;

    /** Using external buffer for Prepare Write Request */
    bool                      gattPrepareWriteExtBuffEn;

    /** The parameter to enable the configuration of the
     *  L2CAP logical channels */
    bool                      l2capEn;

    /** BLESS Power reflecting power level values supported
     *  by BLESS radio (for advertising channel) */
    cy_en_ble_bless_pwr_lvl_t txPowerLevelAdv;

    /** BLESS power reflecting power level values supported
     *  by BLESS radio (for connection channel) */
    cy_en_ble_bless_pwr_lvl_t txPowerLevelConn;

#if CY_BLE_LIB_HOST_CORE
    /** IO capability */
    cy_en_ble_gap_iocap_t     securityIoCapability;
#endif

    /** L2CAP MTU Size */
    uint16_t                  l2capMtuSize;

    /** L2CAP MPS Size */
    uint16_t                  l2capMps;

    /** The number of L2CAP Logical channels  */
    uint16_t                  l2capChanCount;

    /** Number of L2CAP PSMs */
    uint16_t                  l2capPsmCount;

    /** Size of prepare write queue buffer */
    uint16_t                  gattPrepareWriteQueueSize;

    /** Length of attribute value */
    uint16_t                  totalAttrValueLength;

    /** The GATT Maximum attribute length */
    uint16_t                  gattAttrMaxLen;

    /** Index count for GATT DB */
    uint16_t                  gattDbIndexCount;

    /** The MTU Size */
    uint16_t                  mtuSize;

    /** The GAP Role */
    uint8_t                   gapRole;

    /** The number of GAP Peripheral configurations */
    uint8_t                   gappConfCount;

    /** The number of GAP Central configurations */
    uint8_t                   gapcConfCount;

    /** The GATT Role */
    uint8_t                   gattRole;

    /** The number of BLE connections (client) */
    uint8_t                   maxClientCount;

    /** The Bonding Requirement */
    uint8_t                   isBondingReq;
} cy_stc_ble_params_t;

#if CY_BLE_LIB_HOST_CORE

/** BLE internal context structure */
typedef struct
{
    /** Structure with information about registered service callbacks */
    cy_stc_ble_event_handler_t  *eventHandlerPool;

    /** Discovery information structure  */
    cy_stc_ble_discovery_t      *discovery;

    /** Service data received with read by group type response during discovery process */
    cy_stc_ble_disc_srvc_info_t *serverInfo;

    /** Total Count of client services that will be discovered */
    uint32_t                     discServiCount;

} cy_stc_ble_context_t;

#endif

/** BLE Stack parameters */
typedef struct
{
    /** Tx 5dbm mode enable */
    bool                           tx5dbmModeEn;

    /**  Configuration parameter for Radio PA calibration */
    cy_stc_ble_mxd_pa_cal_param_t *paCalConfig;

    /** The feature set mask used to control usage of
     *  specified feature in the BLE stack */
    uint16_t                       featureMask;

    /** Max Tx payload size */
    uint16_t                       dleMaxTxCapability;

    /** Max Rx payload size */
    uint16_t                       dleMaxRxCapability;

    /** Memory heap pointer size */
    uint16_t                       totalHeapSz;

    /** Memory heap pointer */
    uint8_t                       *memoryHeapPtr;

    /** Controller memory heap size (uses only in dual CPU mode) */
    uint16_t                       controllerTotalHeapSz;

    /** Controller memory heap pointer (uses only in dual CPU mode) */
    uint8_t                       *controllerMemoryHeapPtr;

    /** Configuration for the L2CAP buffer for data transmission */
    uint8_t                        l2capBufferPerConn;

    /** The maximum number of devices that can be added to the resolve list */
    uint8_t                        maxResolvableDevListSize;

    /** The maximum number of devices that can be added to the white list */
    uint8_t                        maxBondedDevListSize;

    /** The maximum number of bonded devices to be supported by this device */
    uint8_t                        maxWhiteListSize;

    /** Maximum number of BLE connections */
    uint8_t                        maxConnCount;

    /** Package type */
    uint16_t                       packageType;

    /** Package type */
} cy_stc_ble_stack_params_t;


/** BLE HW Configuration structure */
typedef struct
{
    /** BLESS interrupt configuration */
    const cy_stc_sysint_t          *blessIsrConfig;

    /** HCI mode */
    /** UART interrupt configuration */
    const cy_stc_sysint_t          *uartIsrConfig;

    /** UART driver configuration */
    const cy_stc_scb_uart_config_t *uartConfig;

    /** UART driver hardware instance */
    CySCB_Type                     *uartHw;
} cy_stc_ble_hw_config_t;


/** BLE Configuration structure */
typedef struct
{

#if CY_BLE_LIB_HOST_CORE
    /** Pointer to advertising information structure */
    cy_stc_ble_gapp_disc_mode_info_t *discoveryModeInfo;

    /** Pointer to advertising configuration structure */
    cy_stc_ble_gapp_adv_params_t     *gappAdvParams;

    /** Pointer to Discovery information collected by client structure */
    cy_stc_ble_gapc_disc_info_t      *discoveryInfo;

    /** Pointer to scan configuration structure */
    cy_stc_ble_gapc_scan_params_t    *gapcScanParams;

    /** Pointer to structure to store bonding data */
    const cy_stc_ble_flash_storage_t *flashStorage;

    /** Pointer to cy_ble_attValuesCCCD */
    uint8_t                          *attValuesCCCD;

    /** Pointer to GATT database structure used in the GAP server */
    const cy_stc_ble_gatts_db_t      *gattDB;

    /** Pointer to Authentication Parameters Information structure */
    cy_stc_ble_gap_auth_info_t       *authInfo;

    /** Bluetooth Device Address */
    cy_stc_ble_gap_bd_addr_t         *deviceAddress;

    /** Services initialize function */
    cy_fn_service_init_t             ServiceInitFunc;

    /** Pointer to BLE Configuration Parameters structure */
    const cy_stc_ble_params_t        *params;

    /** Internal usage context */
    cy_stc_ble_context_t             *context;

#endif /* CY_BLE_LIB_HOST_CORE */

    /** BLE Stack configuration */
    cy_stc_ble_stack_params_t        *stackParam;

    /** BLE HW configuration */
    cy_stc_ble_hw_config_t           *hw;

}cy_stc_ble_config_t;


/*******************************************************************************
* Function Prototypes
*******************************************************************************/

/**
 * \addtogroup group_ble_common_api_functions
 * \{
 */
/* Host  API */
void Cy_BLE_RegisterEventCallback(cy_ble_callback_t callbackFunc);

/** \cond IGNORE */
/* Low Power mode API */
void Cy_BLE_EnableSystemLowPowerMode(void);
void Cy_BLE_EnableHostLowPowerMode(void);
void Cy_BLE_EnableControllerLowPowerMode(void);
/** \endcond */

/* BLE application Host callback feature API */
cy_en_ble_api_result_t Cy_BLE_RegisterAppHostCallback(cy_ble_app_notify_callback_t CallBack);
void Cy_BLE_UnRegisterAppHostCallback(void);

/* Interrupt functions */
void Cy_BLE_BlessIsrHandler(void);
/** \} group_ble_common_api_functions */


/* Host  API */
cy_en_ble_api_result_t Cy_BLE_InitHost(const cy_stc_ble_config_t *config);
cy_en_ble_api_result_t Cy_BLE_EnableHost(void);
cy_en_ble_api_result_t Cy_BLE_DisableHost(void);

/* Controller  API */
cy_en_ble_api_result_t Cy_BLE_InitController(const cy_stc_ble_config_t *config);
cy_en_ble_api_result_t Cy_BLE_EnableController(void);
cy_en_ble_api_result_t Cy_BLE_EnableHCIModeController(void);
cy_en_ble_api_result_t Cy_BLE_EnableControllerFromHost(void);/** \endcond */

/**
 * \addtogroup group_ble_common_Intr_feature_api_functions
 * \{
 */
/* BLE interrupt notifications feature API */
cy_en_ble_api_result_t Cy_BLE_RegisterInterruptCallback(uint32_t intrMask,
                                                        cy_ble_intr_callback_t CallBack);
cy_en_ble_api_result_t Cy_BLE_UnRegisterInterruptCallback(void);

cy_en_ble_api_result_t Cy_BLE_ConfigureIpcForInterruptCallback(uint32_t ipcChan, uint32_t ipcIntr,
                                                               uint32_t ipcIntrPrior);

/* Interrupt functions for interrupt notifications feature */
void Cy_BLE_IntrNotifyIsrHandler(void);
/** \} */


/*******************************************************************************
* Private Function Prototypes
*******************************************************************************/

void Cy_BLE_EventHandlerWrapper(cy_en_ble_event_t event, void *evParam);


/*******************************************************************************
* External Data references
*******************************************************************************/

/* BLE application callback */
extern cy_ble_callback_t Cy_BLE_ApplCallback;

/* Global structure to initialize Cy_BLE_Init */
extern const cy_stc_ble_config_t *cy_ble_configPtr;
extern cy_stc_ble_intr_notify_t intrNotify;

/* BLE application IPC notification handler */
extern cy_ble_app_notify_callback_t Cy_BLE_HostRegisteredCallback;


/*******************************************************************************
* Function Name: Cy_BLE_ConfigureExtPA
****************************************************************************//**
*
*  This function controls the external Power Amplifier and Low Noise Amplifier
*  outputs.
*
* \param controlValue Enables and controls polarity of the outputs.
*   To control external PA and LNA, the following mask defines are used:
*
*   - BLE_BLESS_EXT_PA_LNA_CTRL_ENABLE_EXT_PA_LNA_Msk - When set to 1, enables
*       the external PA & LNA and BLESS power profile for energy profiler
*   - BLE_BLESS_EXT_PA_LNA_CTRL_CHIP_EN_POL_Msk - Controls the polarity of the
*       chip-enable control signal:
*       * 0 - HIGH enable, LOW disable
*       * 1 - LOW enable, HIGH disable, Incorrect power profile
*   - BLE_BLESS_EXT_PA_LNA_CTRL_PA_CTRL_POL_Msk - Controls the polarity of the PA
*       control signal:
*       * 0 - HIGH enable, LOW disable
*       * 1 - LOW enable, HIGH disable, Incorrect power profile
*   - BLE_BLESS_EXT_PA_LNA_CTRL_LNA_CTRL_POL_Msk - Controls the polarity of the LNA
*       control signal:
*       * 0 - HIGH enable, LOW disable
*       * 1 - LOW enable, HIGH disable, Incorrect power profile
*   - BLE_BLESS_EXT_PA_LNA_CTRL_OUT_EN_DRIVE_VAL_Msk  - Configures the drive value
*       on the output enables of PA, LNA and CHI_EN signals
*       * 0 - drive 0 on the output enable signals
*       * 1 - drive 1 on the output enable signals
*
*******************************************************************************/
__STATIC_INLINE void Cy_BLE_ConfigureExtPA(uint32_t controlValue)
{
    BLE->BLESS.EXT_PA_LNA_CTRL = controlValue;
}



#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CY_IP_MXBLESS */
#endif /* CY_BLE_H */

/* [] END OF FILE */
