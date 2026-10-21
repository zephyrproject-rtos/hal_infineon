/***************************************************************************//**
* \file cy_ble_defines.h
* \version 3.60
*
* \brief
*  This file contains common defines for the BLE.
*
********************************************************************************
* \copyright
* Copyright 2017-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef CY_BLE_DEFINES_H
#define CY_BLE_DEFINES_H

/** 
 * Definitions for CY_BLE_MODE
 */
#define CY_BLE_PROFILE                  (0U)  /* Complete BLE Protocol mode enables both BLE Host and Controller. */
#define CY_BLE_HCI                      (1U)  /* BLE Controller Only (HCI over UART) mode which enables the use of the
                                               * device as a BLE controller. */
    
/** 
 * Definitions for CY_BLE_STACK_MODE
 */    
#define CY_BLE_STACK_MODE_SINGLE_SOC    (3U)  /* Host and Controller with a software interface. */
#define CY_BLE_STACK_MODE_DUAL_IPC      (2U)  /* Host and Controller with an IPC interface. */
    
/** 
 * Definitions (masks) for CY_BLE_GAP_ROLE 
 */     
#define CY_BLE_GAP_HCI                  (0x00U) /* Used when the BLE operates in HCI mode. */
#define CY_BLE_GAP_PERIPHERAL           (0x01U) /* The device operates as peripheral. */
#define CY_BLE_GAP_CENTRAL              (0x02U) /* The device operates as central. */
#define CY_BLE_GAP_BROADCASTER          (0x04U) /* The device operates as a broadcaster. */
#define CY_BLE_GAP_OBSERVER             (0x08U) /* The device operates as an observer. */

/** 
 * Definitions (masks) for CY_BLE_GATT_ROLE 
 */         
#define CY_BLE_GATT_SERVER              (0x01U) /* Server */
#define CY_BLE_GATT_CLIENT              (0x02U) /* Client */
#define CY_BLE_GATT_BOTH                (CY_BLE_GATT_SERVER | CY_BLE_GATT_CLIENT)
        
/** 
 * Definitions for Cortex cores
 */    
#define CY_BLE_CORE_CORTEX_M4           4U
#define CY_BLE_CORE_CORTEX_M0P          0U
#define CY_BLE_CORE_DUAL                255U

/** 
 * Definitions for CY_BLE_BONDING_REQUIREMENT
 */        
#define CY_BLE_BONDING_YES              (0x01U)
#define CY_BLE_BONDING_NO               (0x00U)

/** 
 * Definitions for CY_BLE_SHARING_MODE
 */ 
#define CY_BLE_SHARING_NONE             (0U)  /* The OTA feature is disabled. */
#define CY_BLE_SHARING_EXPORT           (1U)  /* Stack and Profiles */
#define CY_BLE_SHARING_IMPORT           (2U)  /* Profile only. */
    


#endif /* !defined(CY_BLE_DEFINES_H)*/

/* [] END OF FILE */
