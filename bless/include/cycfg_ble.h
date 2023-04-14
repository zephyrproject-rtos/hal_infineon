/**************************************************************************
 * Copyright 2022 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-Licence-Identifier: Apache-2.0
 ***************************************************************************/

#if !defined(CYCFG_BLE_H)
#define CYCFG_BLE_H

#define CY_BLE_CFG_TOOL_VERSION (250)

#include "cy_syslib.h"

#define CYBSP_BLE_ENABLED      1U
#define CY_BLE_CORE_CORTEX_M4  4U
#define CY_BLE_CORE_CORTEX_M0P 0U
#define CY_BLE_CORE_DUAL       255U
#ifndef CY_BLE_CORE
#define CY_BLE_CORE 4U
#endif
#define CY_BLE_IRQ bless_interrupt_IRQn

#if defined(COMPONENT_BLESS_CONTROLLER)

#include "cy_ble_event_handler.h"
#include "cy_ble_defines.h"

#define CY_BLE_MW_VERSION_REQUIRED (300)

#if !defined(CY_BLE_MW_VERSION)
#if (CY_BLE_MW_VERSION_MAJOR == 3)
#define CY_BLE_MW_VERSION (300)
#elif (CY_BLE_MW_VERSION_MAJOR == 2)
#define CY_BLE_MW_VERSION (200)
#elif (CY_BLE_MW_VERSION_MAJOR == 1)
#define CY_BLE_MW_VERSION (100)
#else
#define CY_BLE_MW_VERSION (100)
#endif
#endif

#if (CY_BLE_MW_VERSION_REQUIRED > CY_BLE_MW_VERSION)
#error The Bluetooth Configurator requires a newer version of the PSoC 6 BLESS Middleware. Update the PSoC 6 BLESS Middleware in your project.
#endif

#ifdef CONFIG_BT_MAX_CONN
#define CY_BLE_CONN_COUNT (CONFIG_BT_MAX_CONN)
#else
#define CY_BLE_CONN_COUNT (1)
#endif

#define CY_BLE_CONFIG_TX_POWER_CALIBRATION_ENABLE (0x01u)
#define CY_BLE_CONFIG_ENABLE_PHY_UPDATE		  (0x01u)

#include "cy_ble_cfg_common.h"

extern const cy_stc_ble_config_t cy_ble_config;

#endif

#endif
