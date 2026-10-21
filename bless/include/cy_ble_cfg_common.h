/***************************************************************************//**
* \file cy_ble_cfg_common.h
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

#if !defined(CY_BLE_CFG_COMMON_H)
#define CY_BLE_CFG_COMMON_H

#include "cy_syslib.h"
#include "cy_ble_defines.h"




/*******************************************************************************
* Set default configurations
*******************************************************************************/

#if defined(COMPONENT_BLESS_CONTROLLER_IPC) || defined(COMPONENT_BLESS_HOST_IPC)
    #define CY_BLE_CONFIG_MODE                 (CY_BLE_PROFILE)
    #define CY_BLE_CONFIG_STACK_MODE           (CY_BLE_STACK_MODE_DUAL_IPC)

#elif defined(COMPONENT_BLESS_CONTROLLER) && defined(COMPONENT_BLESS_HOST)
    #define CY_BLE_CONFIG_MODE                 (CY_BLE_PROFILE)
    #define CY_BLE_CONFIG_STACK_MODE           (CY_BLE_STACK_MODE_SINGLE_SOC)
    #define CY_BLE_CONFIG_HOST_CORE            (__CORTEX_M)

#elif defined(CY_BLE_STACK_LIB_SINGLE_SOC_CM0P)
    #define CY_BLE_CONFIG_MODE                 (CY_BLE_PROFILE)
    #define CY_BLE_CONFIG_STACK_MODE           (CY_BLE_STACK_MODE_SINGLE_SOC)
    #define CY_BLE_CONFIG_HOST_CORE            (CY_BLE_CORE_CORTEX_M0P)

#elif defined(COMPONENT_BLESS_CONTROLLER) && !defined(COMPONENT_BLESS_HOST)
    #define CY_BLE_CONFIG_MODE                 (CY_BLE_HCI)
    #define CY_BLE_CONFIG_STACK_MODE           (CY_BLE_STACK_MODE_SINGLE_SOC)
    
#else
    #define CY_BLE_CONFIG_MODE                 (CY_BLE_PROFILE)
    #define CY_BLE_CONFIG_STACK_MODE           (CY_BLE_STACK_MODE_SINGLE_SOC)
    #define CY_BLE_CONFIG_HOST_CORE            (CY_BLE_CORE_CORTEX_M4)
#endif


/*******************************************************************************
* Macros determines BLE cores and mode
*******************************************************************************/

/* The BLE operation mode */
#define CY_BLE_MODE                             (CY_BLE_CONFIG_MODE)

/* The BLE Stack core mode */
#define CY_BLE_STACK_MODE                       (CY_BLE_CONFIG_STACK_MODE)

/* Default host core in CM4 */
#if !defined(CY_BLE_CONFIG_HOST_CORE)
    #define CY_BLE_CONFIG_HOST_CORE             (CY_BLE_CORE_CORTEX_M4)
#endif /* (!CY_BLE_CORE_CORTEX_M4) */

/* BLE core definitions */
#define CY_BLE_HOST_CORE                        ((CY_BLE_CONFIG_HOST_CORE == CY_BLE_CORE_CORTEX_M4) ?         \
                                                    CY_CPU_CORTEX_M4 : CY_CPU_CORTEX_M0P)

#define CY_BLE_CONTR_CORE                       ((CY_BLE_STACK_MODE == CY_BLE_STACK_MODE_SINGLE_SOC) ? CY_BLE_HOST_CORE : \
                                                    ((CY_BLE_CONFIG_HOST_CORE == CY_BLE_CORE_CORTEX_M0P) ?    \
                                                        CY_CPU_CORTEX_M4 : CY_CPU_CORTEX_M0P))

/* BLE modes definitions */
#define CY_BLE_MODE_PROFILE                     ((CY_BLE_CONFIG_MODE == CY_BLE_PROFILE) && (CY_BLE_HOST_CORE))
#define CY_BLE_MODE_HCI                         (CY_BLE_CONFIG_MODE == CY_BLE_HCI)


/* Controller/host cores */
#define CY_BLE_STACK_CONTR_CORE                 ((CY_BLE_MODE_HCI) ||                                                           \
                                                 ((CY_BLE_MODE == CY_BLE_PROFILE) &&                                            \
                                                 ((CY_BLE_STACK_MODE == CY_BLE_STACK_MODE_SINGLE_SOC) && (CY_BLE_HOST_CORE)) || \
                                                 ((CY_BLE_STACK_MODE == CY_BLE_STACK_MODE_DUAL_IPC) && (CY_BLE_CONTR_CORE))))

#define CY_BLE_HOST_CONTR_CORE                  (CY_BLE_MODE_PROFILE || CY_BLE_STACK_CONTR_CORE)

#define CY_BLE_STACK_IPC_CONTR_CORE             ((CY_BLE_MODE == CY_BLE_PROFILE) &&                   \
                                                 (CY_BLE_STACK_MODE == CY_BLE_STACK_MODE_DUAL_IPC) && \
                                                 (CY_BLE_CONTR_CORE))

#define CY_BLE_STACK_IPC_HOST_CORE              ((CY_BLE_MODE == CY_BLE_PROFILE) &&                   \
                                                 (CY_BLE_STACK_MODE == CY_BLE_STACK_MODE_DUAL_IPC) && \
                                                 (CY_BLE_HOST_CORE))
/* Stack mode */
#define CY_BLE_STACK_MODE_IPC                   (CY_BLE_STACK_MODE == CY_BLE_STACK_MODE_DUAL_IPC)
#define CY_BLE_STACK_MODE_SOC                   (CY_BLE_STACK_MODE == CY_BLE_STACK_MODE_SINGLE_SOC)


/*******************************************************************************
* Macros
*******************************************************************************/

/* Sharing mode defines */
#define CY_BLE_SHARING_MODE_EXPORT              (CY_BLE_SHARING_MODE == CY_BLE_SHARING_EXPORT)
#define CY_BLE_SHARING_MODE_IMPORT              (CY_BLE_SHARING_MODE == CY_BLE_SHARING_IMPORT)

/* Align the buffer size value to 4 */
#define CY_BLE_ALIGN_TO_4(x)                    ((((x) & 3u) == 0u) ? (x) : (((x) - ((x) & 3u)) + 4u))

#define CY_BLE_GAPP_CONF_COUNT                  (CY_BLE_GAP_PERIPHERAL_COUNT + CY_BLE_GAP_BROADCASTER_COUNT)
#define CY_BLE_GAPC_CONF_COUNT                  (CY_BLE_GAP_CENTRAL_COUNT + CY_BLE_GAP_OBSERVER_COUNT)

/** The GAP Role defines */
#define CY_BLE_GAP_ROLE_PERIPHERAL              (0u != (CY_BLE_GAP_ROLE & CY_BLE_GAP_PERIPHERAL))
#define CY_BLE_GAP_ROLE_CENTRAL                 (0u != (CY_BLE_GAP_ROLE & CY_BLE_GAP_CENTRAL))
#define CY_BLE_GAP_ROLE_OBSERVER                (0u != (CY_BLE_GAP_ROLE & CY_BLE_GAP_OBSERVER))
#define CY_BLE_GAP_ROLE_BROADCASTER             (0u != (CY_BLE_GAP_ROLE & CY_BLE_GAP_BROADCASTER))


#if !defined(CY_BLE_CONN_COUNT)
    #define CY_BLE_CONN_COUNT                   (1u)
#endif /* (!CY_BLE_CONN_COUNT) */

/**
 * The parameter to enable configuration of the L2CAP logical channels
 */
#if !defined(CY_BLE_L2CAP_ENABLE)
    #define CY_BLE_L2CAP_ENABLE                 (0u)
#endif /* (!CY_BLE_L2CAP_ENABLE) */
#if(CY_BLE_L2CAP_ENABLE != 0u)

    /* L2CAP MTU Size */
    #define CY_BLE_L2CAP_MTU                    (CY_BLE_CONFIG_L2CAP_MTU)

    /** L2CAP MPS Size  */
    #if defined (CY_BLE_CONFIG_L2CAP_MPS)
        #define CY_BLE_L2CAP_MPS                (CY_BLE_CONFIG_L2CAP_MPS)
    #else
        #define CY_BLE_L2CAP_MPS                (23u)
    #endif /* defined (CY_BLE_CONFIG_L2CAP_MPS) */

    #define CY_BLE_L2CAP_MTU_MPS                (CY_BLE_L2CAP_MTU / CY_BLE_L2CAP_MPS)

    /* Number of L2CAP Logical channels */
    #define CY_BLE_L2CAP_LOGICAL_CHANNEL_COUNT  (CY_BLE_CONFIG_L2CAP_LOGICAL_CHANNEL_COUNT)

    /* Number of L2CAP PSMs */
    #define CY_BLE_L2CAP_PSM_COUNT              (CY_BLE_CONFIG_L2CAP_PSM_COUNT)

#else
    #define CY_BLE_L2CAP_MTU                    (0u)
    #define CY_BLE_L2CAP_MPS                    (0u)
    #define CY_BLE_L2CAP_MTU_MPS                (0u)
    #define CY_BLE_L2CAP_LOGICAL_CHANNEL_COUNT  (0u)
    #define CY_BLE_L2CAP_PSM_COUNT              (0u)
#endif  /* CY_BLE_L2CAP_ENABLE != 0u */

#if (CY_BLE_MODE == CY_BLE_PROFILE)

    /** LL Privacy 1.2 feature */
    #if !defined(CY_BLE_CONFIG_ENABLE_LL_PRIVACY)
        #define CY_BLE_ENABLE_LL_PRIVACY            (0u)
    #else
        #define CY_BLE_ENABLE_LL_PRIVACY            (CY_BLE_CONFIG_ENABLE_LL_PRIVACY)
    #endif /* !defined(CY_BLE_CONFIG_ENABLE_LL_PRIVACY) */

    /** The maximum number of peer devices whose addresses should be resolved by this device. */
    #if (CY_BLE_ENABLE_LL_PRIVACY != 0u)
        #define CY_BLE_MAX_RESOLVABLE_DEVICES       (CY_BLE_CONFIG_MAX_RESOLVABLE_DEVICES)
    #else
        #define CY_BLE_MAX_RESOLVABLE_DEVICES       (0u)
    #endif  /* (CY_BLE_ENABLE_LL_PRIVACY == 0u) */

    /** The maximum number of devices that can be added to the white list. */
    #if defined (CY_BLE_CONFIG_MAX_WHITE_LIST_SIZE)
        #define CY_BLE_MAX_WHITE_LIST_SIZE          (CY_BLE_CONFIG_MAX_WHITE_LIST_SIZE)
    #endif /* defined (CY_BLE_CONFIG_MAX_WHITE_LIST_SIZE) */

    /** The maximum number of bonded devices to be supported by this device.  */
    #if defined (CY_BLE_CONFIG_MAX_BONDED_DEVICES)
        #define CY_BLE_MAX_BONDED_DEVICES          (CY_BLE_CONFIG_MAX_BONDED_DEVICES)
    #endif /* defined (CY_BLE_CONFIG_MAX_BONDED_DEVICES) */
    
    /* The GAP security level */
    #if defined (CY_BLE_CONFIG_GAP_SECURITY_LEVEL)
        #define CY_BLE_GAP_SECURITY_LEVEL           (CY_BLE_CONFIG_GAP_SECURITY_LEVEL)
    #endif /* defined (CY_BLE_CONFIG_GAP_SECURITY_LEVEL) */

    /** Additional queue depth provided from the customizer  */
    #if defined (CY_BLE_CONFIG_ADD_Q_DEPTH_PER_CONN)
        #define CY_BLE_ADD_Q_DEPTH_PER_CONN         (CY_BLE_CONFIG_ADD_Q_DEPTH_PER_CONN)
    #else
        #define CY_BLE_ADD_Q_DEPTH_PER_CONN         (0u)
    #endif /* defined (CY_BLE_CONFIG_ADD_Q_DEPTH_PER_CONN) */

    /**
     * Minimum stack queue depth requirement per connection
     * The application can choose to give higher queue depth for better throughput.
     */
    #define CY_BLE_L2CAP_Q_DEPTH_PER_CONN           (CY_BLE_L2CAP_STACK_Q_DEPTH_PER_CONN + CY_BLE_ADD_Q_DEPTH_PER_CONN)
    #define CY_BLE_L2CAP_Q_HEAP                     (CY_BLE_ALIGN_TO_4(CY_BLE_L2CAP_Q_DEPTH_PER_CONN * \
                                                                    CY_BLE_L2CAP_QUEUE_ELEMENT_SIZE * CY_BLE_CONN_COUNT))

    /* If mtu > 23 stack queue depth =  (stack queue depth per connection - 1) * maxBleConnection */
    #define CY_BLE_GATT_MTU_BUFF_COUNT              (CY_BLE_CONN_COUNT * ((CY_BLE_GATT_MTU > CY_BLE_MTU_MIN_VALUE) ? \
                                                     (CY_BLE_L2CAP_Q_DEPTH_PER_CONN - 1u) : (CY_BLE_MTU_MIN_BUFF_NUM)) )

    #define CY_BLE_GATT_MTU_PLUS_L2CAP_MEM_EXT      (CY_BLE_ALIGN_TO_4(CY_BLE_GATT_MTU + CY_BLE_MEM_EXT_SZ + \
                                                                       CY_BLE_L2CAP_HDR_SZ))

    /* GATT Maximum attribute length */
    #define CY_BLE_GATT_MAX_ATTR_LEN                ((CY_BLE_GATT_DB_MAX_VALUE_LEN == 0u) ? (1u) : \
                                                     (CY_BLE_GATT_DB_MAX_VALUE_LEN))

    #define CY_BLE_GATT_MAX_ATTR_LEN_PLUS_L2CAP_MEM_EXT                                                               \
                                                    (CY_BLE_ALIGN_TO_4(CY_BLE_GATT_MAX_ATTR_LEN + CY_BLE_MEM_EXT_SZ + \
                                                                       CY_BLE_L2CAP_HDR_SZ))

    /* The header length for Prepare Write Request */
    #define CY_BLE_GATT_PREPARE_WRITE_HEADER_LEN    (5u)

    /* The header length for Write Request */
    #define CY_BLE_GATT_WRITE_HEADER_LEN            (3u)

    #define CY_BLE_GATT_PREPARE_LENGTH              ((CY_BLE_GATT_RELIABLE_CHAR_LENGTH > CY_BLE_GATT_MAX_ATTR_LEN) ? \
                                                      CY_BLE_GATT_RELIABLE_CHAR_LENGTH : CY_BLE_GATT_MAX_ATTR_LEN)

    /* The number of buffers required for Prepare Write Request based on assumption that the negotiated MTU
     *  size is equal to the CY_BLE_GATT_DEFAULT_MTU and all the Characteristics supporting a Reliable Write
     *  property must be written, in order, in a single operation.
     *  The buffer count is 0 when the maximum attribute size is less than the minimum MTU - 3.
     */
    #define CY_BLE_GATT_MAX_PREPARE_BUFF_COUNT                                                                         \
            (((CY_BLE_GATT_MAX_ATTR_LEN <= (CY_BLE_GATT_DEFAULT_MTU - CY_BLE_GATT_WRITE_HEADER_LEN)) &&                \
            (CY_BLE_GATT_RELIABLE_CHAR_COUNT == 0u)) ? 0u :                                                            \
            ((CY_BLE_GATT_PREPARE_LENGTH / (CY_BLE_GATT_DEFAULT_MTU - CY_BLE_GATT_PREPARE_WRITE_HEADER_LEN)) +         \
             (((CY_BLE_GATT_PREPARE_LENGTH % (CY_BLE_GATT_DEFAULT_MTU - CY_BLE_GATT_PREPARE_WRITE_HEADER_LEN)) > 0u) ? \
               1u : 0u)))

    #define CY_BLE_GATT_PREPARE_LENGTH_ALIGN        ((CY_BLE_GATT_MAX_PREPARE_BUFF_COUNT == 0u) ? 0u : \
                                                      CY_BLE_ALIGN_TO_4(CY_BLE_GATT_PREPARE_LENGTH))

    /* The parameter to enable the application to provide a dynamically allocated buffer for Prepare Write Request */
    #if defined (CY_BLE_CONFIG_GATT_ENABLE_EXTERNAL_PREP_WRITE_BUFF)
        #define CY_BLE_GATT_EN_EXT_PREP_WRITE_BUFF    \
                                                    (CY_BLE_CONFIG_GATT_ENABLE_EXTERNAL_PREP_WRITE_BUFF)
    #else
        #define CY_BLE_GATT_EN_EXT_PREP_WRITE_BUFF (0u)
    #endif /* defined (CY_BLE_CONFIG_GATT_ENABLE_EXTERNAL_PREP_WRITE_BUFF) */


    /* Buffer length for the data received during Prepare Write Requests
     * For dynamic memory allocation by the application level, set the EnableExternalPrepWriteBuff parameter
     * in the Expression view of the Advanced tab to true.
     */

    #define CY_BLE_GATT_PREPARE_WRITE_BUFF_LEN      ((CY_BLE_GATT_EN_EXT_PREP_WRITE_BUFF != 0u) ? 0u :  \
                                                     (CY_BLE_GATT_PREPARE_LENGTH_ALIGN +                         \
                                                     (CY_BLE_GATT_MAX_PREPARE_BUFF_COUNT *                       \
                                                      sizeof(cy_stc_ble_gatt_handle_value_offset_param_t))))


    /* L2CAP RAM buffer sizes */
    #define CY_BLE_L2CAP_MTU_PLUS_L2CAP_MEM_EXT     (CY_BLE_ALIGN_TO_4(CY_BLE_L2CAP_MTU + \
                                                                       CY_BLE_MEM_EXT_SZ + CY_BLE_L2CAP_HDR_SZ))
    #define CY_BLE_L2CAP_MPS_PLUS_L2CAP_MEM_EXT     (CY_BLE_ALIGN_TO_4(CY_BLE_L2CAP_MPS + CY_BLE_MEM_EXT_SZ + \
                                                                       CY_BLE_L2CAP_HDR_SZ))
    #define CY_BLE_L2CAP_PSM_PLUS_L2CAP_MEM_EXT     (CY_BLE_ALIGN_TO_4((CY_BLE_L2CAP_PSM_SIZE + CY_BLE_MEM_EXT_SZ) * \
                                                                     CY_BLE_L2CAP_PSM_COUNT))
    #define CY_BLE_L2CAP_CBFC_PLUS_L2CAP_MEM_EXT    (CY_BLE_ALIGN_TO_4((CY_BLE_L2CAP_CBFC_CHANNEL_SIZE + \
                                                                        CY_BLE_MEM_EXT_SZ) * CY_BLE_L2CAP_LOGICAL_CHANNEL_COUNT))
#else /* CY_BLE_MODE == CY_BLE_HCI */
    #define CY_BLE_MAX_BONDED_DEVICES               (CY_BLE_DEFAULT_BONDED_DEVICE_LIST_SZ)
    #define CY_BLE_MAX_RESOLVABLE_DEVICES           (CY_BLE_DEFAULT_RPA_LIST_SZ)
    #define CY_BLE_MAX_WHITE_LIST_SIZE              (CY_BLE_MAX_WHITELIST_LIST_SZ)
    #define CY_BLE_ENABLE_LL_PRIVACY                (1u)
    #define CY_BLE_GAP_SECURITY_LEVEL               (0x0u)
    #define CY_BLE_L2CAP_Q_DEPTH_PER_CONN           (0x0u)
    #define CY_BLE_GATT_PREPARE_WRITE_BUFF_LEN      (0x0u)
#endif /* CY_BLE_MODE_PROFILE */

/* LL max data length */
#define CY_BLE_LL_MAX_SUPPORTED_TX_PAYLOAD_SIZE     (251u)
#define CY_BLE_LL_MAX_SUPPORTED_RX_PAYLOAD_SIZE     (251u)
#define CY_BLE_LL_MIN_SUPPORTED_TX_PAYLOAD_SIZE     (27u)
#define CY_BLE_LL_MIN_SUPPORTED_RX_PAYLOAD_SIZE     (27u)
#define CY_BLE_LL_MAX_TX_TIME                       (0x0848u)

/* Use maximum payload size (LL max data length) */
#if (CY_BLE_MODE == CY_BLE_PROFILE)
    /** Max Tx payload size. */
    #if !defined(CY_BLE_CONFIG_LL_MAX_TX_PAYLOAD_SIZE)
        #define CY_BLE_CONFIG_LL_MAX_TX_PAYLOAD_SIZE     (0u)
    #endif /* (!CY_BLE_CONFIG_LL_MAX_TX_PAYLOAD_SIZE) */
    #define CY_BLE_LL_MAX_TX_PAYLOAD_SIZE           (CY_BLE_CONFIG_LL_MAX_TX_PAYLOAD_SIZE)

    /** Max Rx payload size. */
    #if !defined(CY_BLE_CONFIG_LL_MAX_RX_PAYLOAD_SIZE)
        #define CY_BLE_CONFIG_LL_MAX_RX_PAYLOAD_SIZE     (0u)
    #endif /* (!CY_BLE_CONFIG_LL_MAX_RX_PAYLOAD_SIZE) */
    #define CY_BLE_LL_MAX_RX_PAYLOAD_SIZE           (CY_BLE_CONFIG_LL_MAX_RX_PAYLOAD_SIZE)

#else /* Use maximum payload size for HCI mode */
    #define CY_BLE_LL_MAX_TX_PAYLOAD_SIZE           (CY_BLE_LL_MAX_SUPPORTED_TX_PAYLOAD_SIZE)
    #define CY_BLE_LL_MAX_RX_PAYLOAD_SIZE           (CY_BLE_LL_MAX_SUPPORTED_RX_PAYLOAD_SIZE)
#endif /* CY_BLE_MODE_PROFILE */

#define CY_BLE_LL_MAX_TX_PAYLOAD_BUFFER_SZ          CY_BLE_ALIGN_TO_4(CY_BLE_LL_MAX_TX_PAYLOAD_SIZE)
#define CY_BLE_LL_MAX_RX_PAYLOAD_BUFFER_SZ          CY_BLE_ALIGN_TO_4(CY_BLE_LL_MAX_RX_PAYLOAD_SIZE)

#if ((CY_BLE_LL_MAX_TX_PAYLOAD_SIZE > CY_BLE_LL_MIN_SUPPORTED_TX_PAYLOAD_SIZE) || \
     (CY_BLE_LL_MAX_RX_PAYLOAD_SIZE > CY_BLE_LL_MIN_SUPPORTED_RX_PAYLOAD_SIZE))
    #define CY_BLE_DLE_FEATURE                      (CY_BLE_DLE_FEATURE_MASK)
    #define CY_BLE_LL_DLE_HEAP_SZ                   (CY_BLE_LL_DLE_HEAP_REQ)
#else
    #define CY_BLE_DLE_FEATURE                      (0u)
    #define CY_BLE_LL_DLE_HEAP_SZ                   (0u)
#endif /* DLE enabled */

#if (CY_BLE_ENABLE_LL_PRIVACY > 0u)
    #define CY_BLE_LL_PRIVACY_FEATURE               (CY_BLE_PRIVACY_1_2_FEATURE_MASK)
    #define CY_BLE_LL_PRIVACY_HEAP_SZ               (CY_BLE_LL_PRIVACY_HEAP_REQ)
    #define CY_BLE_STORE_RESOLVING_LIST_FEATURE     (CY_BLE_PERSISTENT_STORE_RESOLVING_LIST)

    /* Resolving list memory computation */
    #define CY_BLE_STACK_RESOLVING_LIST_SIZE        ((CY_BLE_LL_PRIVACY_HEAP_SZ * CY_BLE_MAX_RESOLVABLE_DEVICES) + \
                                                      CY_BLE_LL_PRIVACY_RETENTION_HEAP_REQ)
#else
    #define CY_BLE_LL_PRIVACY_FEATURE               (0u)
    #define CY_BLE_LL_PRIVACY_HEAP_SZ               (0u)
    #define CY_BLE_STORE_RESOLVING_LIST_FEATURE     (0u)
    #define CY_BLE_STACK_RESOLVING_LIST_SIZE        (0u)
#endif /* CY_BLE_MAX_RESOLVABLE_DEVICES != 0u */

/** Secure Connection feature */
#if !defined(CY_BLE_GAP_SECURITY_LEVEL)
    #define CY_BLE_GAP_SECURITY_LEVEL               (0u)
#endif /* !defined(CY_BLE_GAP_SECURITY_LEVEL) */    
#if (CY_BLE_GAP_SECURITY_LEVEL == 0x03)
    #define CY_BLE_SECURE_CONN_FEATURE              (CY_BLE_SECURE_CONN_FEATURE_MASK)
    #define CY_BLE_RAM_SECURE_CONNECTIONS_SIZE      (CY_BLE_RAM_SIZE_SECURE_CONNECTIONS)
#else
    #define CY_BLE_SECURE_CONN_FEATURE              (0u)
    #define CY_BLE_RAM_SECURE_CONNECTIONS_SIZE      (0u)
#endif /* CY_BLE_GAP_SECURITY_LEVEL == 0x03 */

/** PHY update enable */
#if !defined (CY_BLE_CONFIG_ENABLE_PHY_UPDATE)
    #define CY_BLE_ENABLE_PHY_UPDATE                (0u)
#else
    #define CY_BLE_ENABLE_PHY_UPDATE                (CY_BLE_CONFIG_ENABLE_PHY_UPDATE)
#endif  /* defined(CY_BLE_CONFIG_ENABLE_PHY_UPDATE) */

#if ((CY_BLE_ENABLE_PHY_UPDATE != 0u) || (CY_BLE_MODE_HCI))
    #define CY_BLE_PHY_UPDATE_FEATURE               (CY_BLE_PHY_UPDATE_FEATURE_MASK)
#else
    #define CY_BLE_PHY_UPDATE_FEATURE               (0u)
#endif  /* (CY_BLE_ENABLE_PHY_UPDATE != 0u) || (CY_BLE_MODE_HCI) */

/** Tx 5dbm mode enable */
#if defined (CY_BLE_CONFIG_ENABLE_TX_5DBM)
    #define CY_BLE_ENABLE_TX_5DBM                   (1u)
#else
    #define CY_BLE_ENABLE_TX_5DBM                   (0u)
#endif /* defined (CY_BLE_CONFIG_ADD_Q_DEPTH_PER_CONN) */

/* Bonded device list auxiliary flash memory computation */
#if !defined (CY_BLE_BONDING_REQUIREMENT)
    #define CY_BLE_BONDING_REQUIREMENT              (CY_BLE_BONDING_NO)
#endif /* !defined (CY_BLE_BONDING_REQUIREMENT) */
#if ((CY_BLE_MODE_PROFILE) && (CY_BLE_BONDING_REQUIREMENT == CY_BLE_BONDING_YES))

    #define CY_BLE_STORE_BONDLIST_FEATURE           (CY_BLE_PERSISTENT_STORE_BONDLIST)

    /* Bonded device list auxiliary flash memory computation. Cypress ID #309591 */
    #define CY_BLE_STACK_BOND_FLASH_SIZE            ((CY_BLE_STACK_ONE_BONDED_DEVICE_SIZE * CY_BLE_MAX_BONDED_DEVICES) + \
                                                     (CY_BLE_STACK_ONE_DEVICE_Q_ENTITY_SIZE *                            \
                                                      (CY_BLE_MAX_CONNECTION_INSTANCES + CY_BLE_MAX_BONDED_DEVICES)))

    /* Bonded device list RAM memory computation */
    #define CY_BLE_STACK_BOND_RAM_SIZE              ((CY_BLE_STACK_ONE_BONDED_DEVICE_SIZE +    \
                                                      CY_BLE_STACK_ONE_DEVICE_Q_ENTITY_SIZE) * \
                                                     (CY_BLE_CONN_COUNT + CY_BLE_MAX_BONDED_DEVICES))
#else
    #define CY_BLE_STORE_BONDLIST_FEATURE           (0u)
    #define CY_BLE_STACK_BOND_FLASH_SIZE            (0u)
    #define CY_BLE_STACK_BOND_RAM_SIZE              (0u)
#endif  /* (CY_BLE_MODE_PROFILE) && (CY_BLE_BONDING_REQUIREMENT == CY_BLE_BONDING_YES) */

#define CY_BLE_STORE_WHITELIST_FEATURE              (CY_BLE_PERSISTENT_STORE_WHITELIST)

/* White list memory computation */
#define CY_BLE_STACK_WHITELIST_SIZE                 ((CY_BLE_LL_ONE_WHITELIST_HEAP_REQ * CY_BLE_MAX_WHITE_LIST_SIZE) + \
                                                      CY_BLE_LL_WHITELIST_RETENTION_HEAP_REQ)

#if defined(CY_BLE_CONFIG_TX_POWER_CALIBRATION_ENABLE) && (CY_BLE_CONFIG_TX_POWER_CALIBRATION_ENABLE != 0u)
    #define CY_BLE_TX_POWER_CALIBRATION_FEATURE     (CY_BLE_PERSISTENT_RADIO_CALIBRATION_MASK)
#else
    #define CY_BLE_TX_POWER_CALIBRATION_FEATURE     (0u)
#endif  /* CY_BLE_TX_POWER_CALIBRATION_ENABLE CALIBRATION != 0u */

/* BLE Features */
#define CY_BLE_DLE_FEATURE_ENABLED                  (CY_BLE_DLE_FEATURE != 0u)
#define CY_BLE_LL_PRIVACY_FEATURE_ENABLED           (CY_BLE_LL_PRIVACY_FEATURE != 0u)
#define CY_BLE_SECURE_CONN_FEATURE_ENABLED          (CY_BLE_SECURE_CONN_FEATURE != 0u)
#define CY_BLE_PHY_UPDATE_FEATURE_ENABLED           (CY_BLE_PHY_UPDATE_FEATURE != 0u)

#define CY_BLE_TX_POWER_CALIBRATION_FEATURE_ENABLED (CY_BLE_TX_POWER_CALIBRATION_FEATURE != 0u)
#define CY_BLE_INTR_NOTIFY_FEATURE_ENABLED          (CY_BLE_INTR_NOTIFY_FEATURE_ENABLE != 0u)


#define CY_BLE_LL_ACL_TX_HEAP_SZ                    (CY_BLE_LL_DEFAULT_NUM_ACL_TX_PACKETS *   \
                                                     (CY_BLE_LL_MAX_TX_PAYLOAD_BUFFER_SZ +    \
                                                      CY_BLE_LL_ACL_DATA_PACKET_OVERHEAD_SZ + \
                                                      CY_BLE_MEM_EXT_SZ))

#define CY_BLE_LL_ACL_RX_HEAP_SZ                    (CY_BLE_LL_DEFAULT_NUM_ACL_RX_PACKETS *   \
                                                     (CY_BLE_LL_MAX_RX_PAYLOAD_BUFFER_SZ +    \
                                                      CY_BLE_LL_ACL_DATA_PACKET_OVERHEAD_SZ + \
                                                      CY_BLE_MEM_EXT_SZ))


#define CY_BLE_LL_CONTROLLER_HEAP_REQ               ((CY_BLE_DLE_DEVICE_PARAM_SZ) +                     \
                                                     (CY_BLE_LL_DLE_HEAP_REQ * CY_BLE_CONN_COUNT) +     \
                                                     ((CY_BLE_CONTROLLER_CONN_SPECIFIC_HEAP_REQ +       \
                                                       CY_BLE_LL_ACL_TX_HEAP_SZ) * CY_BLE_CONN_COUNT) + \
                                                     CY_BLE_CONTROLLER_DEVICE_SPECIFIC_HEAP_REQ +       \
                                                     CY_BLE_LL_ACL_RX_HEAP_SZ +                         \
                                                     CY_BLE_STACK_RESOLVING_LIST_SIZE +                 \
                                                     CY_BLE_STACK_WHITELIST_SIZE)

/** CRC size for stack flash */
#define CY_BLE_STACK_FLASH_CRC_SIZE                 (2u)

/**
 * \addtogroup group_ble_common_api_macros
 * \{
 */
#if ((CY_BLE_MODE == CY_BLE_PROFILE) && (CY_BLE_HOST_CORE))

    /* Define controller heap for single CPU mode. For dual CPU mode it will defined as CY_BLE_STACK_CONTROLLER_RAM_SIZE */
    #if CY_BLE_STACK_MODE_SOC
        /** The size of RAM memory required for the Stack controller */
        #define CY_BLE_LL_CONTROLLER_HEAP_REQ_SOC   (CY_BLE_LL_CONTROLLER_HEAP_REQ)
    #else
        /** The size of RAM memory required for the Stack controller */
        #define CY_BLE_LL_CONTROLLER_HEAP_REQ_SOC   (0u)
    #endif /* CY_BLE_STACK_MODE_SOC */

    /** The size of RAM memory required for store attribute handle state (Enable/Disable) */
    #if defined(CY_BLE_STACK_APP_POOL_5_SZ)
        #define CY_BLE_GATT_DB_ATTR_BUFF_SIZE  (CY_BLE_ALIGN_TO_4( (CY_BLE_GATT_DB_INDEX_COUNT / 8u) + CY_BLE_MEM_EXT_SZ + \
                                                                   ((CY_BLE_GATT_DB_INDEX_COUNT % 8u) ? 1u : 0u) ))    
    #else
        #define CY_BLE_GATT_DB_ATTR_BUFF_SIZE   (0u)
    #endif /*(CY_BLE_STACK_APP_POOL_5_SZ) */

    /** The size of RAM memory required for the Stack host */
    #define CY_BLE_STACK_RAM_SIZE   (CY_BLE_ALIGN_TO_4(CY_BLE_DEFAULT_HOST_RAM_SIZE + CY_BLE_LL_CONTROLLER_HEAP_REQ_SOC +\
                                                    CY_BLE_RAM_SECURE_CONNECTIONS_SIZE + CY_BLE_L2CAP_Q_HEAP +          \
                                                    CY_BLE_STACK_BOND_RAM_SIZE +                                        \
                                                    (CY_BLE_GATT_MTU_PLUS_L2CAP_MEM_EXT * CY_BLE_GATT_MTU_BUFF_COUNT) + \
                                                    (CY_BLE_L2CAP_PSM_PLUS_L2CAP_MEM_EXT * CY_BLE_L2CAP_PSM_COUNT) +    \
                                                    (CY_BLE_L2CAP_CBFC_PLUS_L2CAP_MEM_EXT * 2u *                        \
                                                        CY_BLE_L2CAP_LOGICAL_CHANNEL_COUNT) +                           \
                                                    (CY_BLE_L2CAP_MTU_PLUS_L2CAP_MEM_EXT * 2u *                         \
                                                        CY_BLE_L2CAP_LOGICAL_CHANNEL_COUNT) +                           \
                                                    (CY_BLE_STACK_BUFFER_MGR_UTIL_RAM_SZ * CY_BLE_STACK_APP_MIN_POOL) + \
                                                    (CY_BLE_RAM_SIZE_HOST_SINGLE_CONN * CY_BLE_CONN_COUNT) +            \
                                                    CY_BLE_GATT_DB_ATTR_BUFF_SIZE +                                     \
                                                    (CY_BLE_GATT_PREPARE_WRITE_BUFF_LEN))) /* This buffer must always be the latest */
#else
    /** The size of RAM memory required for the Stack Controller */
    #define CY_BLE_STACK_RAM_SIZE                   (CY_BLE_LL_CONTROLLER_HEAP_REQ)
#endif /* CY_BLE_MODE == CY_BLE_PROFILE) && (CY_BLE_HOST_CORE) */



/** The size of RAM memory required for the Stack Controller */
#define CY_BLE_STACK_CONTROLLER_RAM_SIZE            (CY_BLE_LL_CONTROLLER_HEAP_REQ)

/** The size of flash memory required for the bonding data */
#define CY_BLE_STACK_FLASH_SIZE                     (CY_BLE_STACK_BOND_FLASH_SIZE + CY_BLE_STACK_RESOLVING_LIST_SIZE + \
                                                     CY_BLE_STACK_WHITELIST_SIZE + CY_BLE_STACK_FLASH_CRC_SIZE )

/** \} group_ble_common_api_macros */

#endif /* CY_BLE_CFG_COMMON_H */

/* [] END OF FILE */
