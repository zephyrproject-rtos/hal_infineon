/*
 * (c) 2025 Infineon Technologies AG, or an affiliate of Infineon Technologies AG.
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CYCFG_QSPI_MEMSLOT_H
#define CYCFG_QSPI_MEMSLOT_H
#include "cy_smif_memslot.h"

#define CY_SMIF_CFG_TOOL_VERSION (440)

/* Supported QSPI Driver version */
#define CY_SMIF_DRV_VERSION_REQUIRED (100)

#if !defined(CY_SMIF_DRV_VERSION)
#define CY_SMIF_DRV_VERSION (100)
#endif

/* Check the used Driver version */
#if (CY_SMIF_DRV_VERSION_REQUIRED > CY_SMIF_DRV_VERSION)
#error The QSPI Configurator requires a newer version of the PDL. Update the PDL in your project.
#endif

typedef cy_stc_smif_mem_config_t cy_serial_flash_mem_config_t;
typedef cy_stc_smif_block_config_t cy_serial_flash_block_config_t;

#define CY_SMIF_DEVICE_NUM0 1

#define CY_SMIF_DEVICE_NUM1 0

#define smifBlockConfig smif0BlockConfig
#define smifMemConfigs  smif0MemConfigs

extern cy_stc_smif_mem_config_t *smif0MemConfigs[CY_SMIF_DEVICE_NUM0];

extern cy_stc_smif_block_config_t smif0BlockConfig;

extern cy_stc_smif_block_config_t smif1BlockConfig;

#endif /*CYCFG_QSPI_MEMSLOT_H*/
