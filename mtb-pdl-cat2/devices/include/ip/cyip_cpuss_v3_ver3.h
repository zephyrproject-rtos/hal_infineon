/***************************************************************************//**
* \file cyip_cpuss_v3_ver3.h
*
* \brief
* CPUSS IP definitions
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef _CYIP_CPUSS_V3_VER3_H_
#define _CYIP_CPUSS_V3_VER3_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    CPUSS
*******************************************************************************/

#define CPUSS_SECTION_SIZE                      0x00001000UL

/**
  * \brief CPU Subsystem (CPUSS)
  */
typedef struct {
  __IOM uint32_t CONFIG;                        /*!< 0x00000000 Configuration register */
  __IOM uint32_t SYSREQ;                        /*!< 0x00000004 SYSCALL control register */
  __IOM uint32_t SYSARG;                        /*!< 0x00000008 SYSARG control register */
   __IM uint32_t RESERVED[5];
  __IOM uint32_t INT_SEL;                       /*!< 0x00000020 Interrupt multiplexer select register */
  __IOM uint32_t INT_MODE;                      /*!< 0x00000024 DSI interrupt pulse mode register */
  __IOM uint32_t NMI_MODE;                      /*!< 0x00000028 DSI NMI pulse mode register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t FLASH_CTL;                     /*!< 0x00000030 FLASH control register */
  __IOM uint32_t ROM_CTL;                       /*!< 0x00000034 ROM control register */
  __IOM uint32_t RAM_CTL;                       /*!< 0x00000038 RAM control register */
  __IOM uint32_t DMAC_CTL;                      /*!< 0x0000003C DMA controller register */
   __IM uint32_t RESERVED2[25];
  __IOM uint32_t RAM1_CTL;                      /*!< 0x000000A4 RAM 1 control register */
  __IOM uint32_t FLASHC1_CTL;                   /*!< 0x000000A8 FLASH Control1  control register */
  __IOM uint32_t FAULT_CTL;                     /*!< 0x000000AC Fault Control Register */
  __IOM uint32_t MTB_CTL;                       /*!< 0x000000B0 MTB control register */
   __IM uint32_t RESERVED3[4];
   __IM uint32_t DAP_CTL;                       /*!< 0x000000C4 SWD DP Instance ID */
   __IM uint32_t RESERVED4[2];
   __IM uint32_t RAM_STATUS;                    /*!< 0x000000D0 RAM Controller 0 Status */
   __IM uint32_t RAM1_STATUS;                   /*!< 0x000000D4 RAM Controller 1 Status */
   __IM uint32_t RESERVED5[2];
  __IOM uint32_t BOOT_RESULT_0;                 /*!< 0x000000E0 Boot Result Register 0 */
  __IOM uint32_t BOOT_RESULT_1;                 /*!< 0x000000E4 Boot Result Register 1 */
   __IM uint32_t RESERVED6[6];
  __IOM uint32_t SL_CTL[24];                    /*!< 0x00000100 Slave control register */
   __IM uint32_t RESERVED7[40];
  __IOM uint32_t RAM_ECC_STATUS0;               /*!< 0x00000200 RAM ECC Status 0 */
   __IM uint32_t RAM_ECC_STATUS1;               /*!< 0x00000204 RAM ECC Status 1 */
  __IOM uint32_t RAM1_ECC_STATUS0;              /*!< 0x00000208 RAM1 ECC Status 0 */
   __IM uint32_t RAM1_ECC_STATUS1;              /*!< 0x0000020C RAM1 ECC Status 1 */
  __IOM uint32_t ECC_TEST;                      /*!< 0x00000210 ECC Test */
   __IM uint32_t RESERVED8[59];
  __IOM uint32_t INTR;                          /*!< 0x00000300 Interrupt register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000304 Interrupt set register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000308 Interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000030C Interrupt masked register */
   __IM uint32_t RESERVED9[60];
  __IOM uint32_t EXT_MS_CTL;                    /*!< 0x00000400 External master control register */
   __IM uint32_t RESERVED10[63];
  __IOM uint32_t FLASHC_BERR_STATUS;            /*!< 0x00000500 Flash Bus Error Status */
  __IOM uint32_t FLASHC1_BERR_STATUS;           /*!< 0x00000504 Flash 1 Bus Error Status */
  __IOM uint32_t FLASHC_ECC_CTL;                /*!< 0x00000508 Flash ECC Control */
  __IOM uint32_t FLASHC1_ECC_CTL;               /*!< 0x0000050C Flash 1 ECC Control */
} CPUSS_Type;                                   /*!< Size = 1296 (0x510) */


/* CPUSS.CONFIG */
#define CPUSS_CONFIG_VECT_IN_RAM_Pos            0UL
#define CPUSS_CONFIG_VECT_IN_RAM_Msk            0x1UL
/* CPUSS.SYSREQ */
#define CPUSS_SYSREQ_SYSCALL_COMMAND_Pos        0UL
#define CPUSS_SYSREQ_SYSCALL_COMMAND_Msk        0xFFFFUL
#define CPUSS_SYSREQ_EXTERNAL_SYS_REQ_Pos       26UL
#define CPUSS_SYSREQ_EXTERNAL_SYS_REQ_Msk       0x4000000UL
#define CPUSS_SYSREQ_DIS_RESET_VECT_REL_Pos     27UL
#define CPUSS_SYSREQ_DIS_RESET_VECT_REL_Msk     0x8000000UL
#define CPUSS_SYSREQ_PRIVILEGED_Pos             28UL
#define CPUSS_SYSREQ_PRIVILEGED_Msk             0x10000000UL
#define CPUSS_SYSREQ_ROM_ACCESS_EN_Pos          29UL
#define CPUSS_SYSREQ_ROM_ACCESS_EN_Msk          0x20000000UL
#define CPUSS_SYSREQ_HMASTER_0_Pos              30UL
#define CPUSS_SYSREQ_HMASTER_0_Msk              0x40000000UL
#define CPUSS_SYSREQ_SYSCALL_REQ_Pos            31UL
#define CPUSS_SYSREQ_SYSCALL_REQ_Msk            0x80000000UL
/* CPUSS.SYSARG */
#define CPUSS_SYSARG_SYSCALL_ARG_Pos            0UL
#define CPUSS_SYSARG_SYSCALL_ARG_Msk            0xFFFFFFFFUL
/* CPUSS.INT_SEL */
#define CPUSS_INT_SEL_DSI_Pos                   0UL
#define CPUSS_INT_SEL_DSI_Msk                   0xFFFFFFFFUL
/* CPUSS.INT_MODE */
#define CPUSS_INT_MODE_DSI_INT_PULSE_Pos        0UL
#define CPUSS_INT_MODE_DSI_INT_PULSE_Msk        0xFFFFFFFFUL
/* CPUSS.NMI_MODE */
#define CPUSS_NMI_MODE_DSI_NMI_PULSE_Pos        0UL
#define CPUSS_NMI_MODE_DSI_NMI_PULSE_Msk        0x1UL
/* CPUSS.FLASH_CTL */
#define CPUSS_FLASH_CTL_FLASH_WS_Pos            0UL
#define CPUSS_FLASH_CTL_FLASH_WS_Msk            0xFUL
#define CPUSS_FLASH_CTL_PREF_EN_Pos             4UL
#define CPUSS_FLASH_CTL_PREF_EN_Msk             0x10UL
#define CPUSS_FLASH_CTL_FLASH_INVALIDATE_Pos    8UL
#define CPUSS_FLASH_CTL_FLASH_INVALIDATE_Msk    0x100UL
#define CPUSS_FLASH_CTL_ARB_Pos                 16UL
#define CPUSS_FLASH_CTL_ARB_Msk                 0x30000UL
#define CPUSS_FLASH_CTL_FLASH_ECC_INJ_EN_Pos    20UL
#define CPUSS_FLASH_CTL_FLASH_ECC_INJ_EN_Msk    0x100000UL
#define CPUSS_FLASH_CTL_FLASH_ERR_SILENT_Pos    21UL
#define CPUSS_FLASH_CTL_FLASH_ERR_SILENT_Msk    0x200000UL
/* CPUSS.ROM_CTL */
#define CPUSS_ROM_CTL_ROM_WS_Pos                0UL
#define CPUSS_ROM_CTL_ROM_WS_Msk                0x1UL
#define CPUSS_ROM_CTL_ARB_Pos                   16UL
#define CPUSS_ROM_CTL_ARB_Msk                   0x30000UL
/* CPUSS.RAM_CTL */
#define CPUSS_RAM_CTL_ECC_ENABLE_Pos            0UL
#define CPUSS_RAM_CTL_ECC_ENABLE_Msk            0x1UL
#define CPUSS_RAM_CTL_ECC_AUTO_CORRECT_Pos      2UL
#define CPUSS_RAM_CTL_ECC_AUTO_CORRECT_Msk      0x4UL
#define CPUSS_RAM_CTL_ECC_INJ_EN_Pos            4UL
#define CPUSS_RAM_CTL_ECC_INJ_EN_Msk            0x10UL
#define CPUSS_RAM_CTL_ECC_BIST_SWITCH_Pos       6UL
#define CPUSS_RAM_CTL_ECC_BIST_SWITCH_Msk       0x40UL
#define CPUSS_RAM_CTL_ARB_Pos                   16UL
#define CPUSS_RAM_CTL_ARB_Msk                   0x30000UL
/* CPUSS.DMAC_CTL */
#define CPUSS_DMAC_CTL_ARB_Pos                  16UL
#define CPUSS_DMAC_CTL_ARB_Msk                  0x30000UL
/* CPUSS.RAM1_CTL */
#define CPUSS_RAM1_CTL_ECC_ENABLE_Pos           0UL
#define CPUSS_RAM1_CTL_ECC_ENABLE_Msk           0x1UL
#define CPUSS_RAM1_CTL_ECC_AUTO_CORRECT_Pos     2UL
#define CPUSS_RAM1_CTL_ECC_AUTO_CORRECT_Msk     0x4UL
#define CPUSS_RAM1_CTL_ECC_INJ_EN_Pos           4UL
#define CPUSS_RAM1_CTL_ECC_INJ_EN_Msk           0x10UL
#define CPUSS_RAM1_CTL_ECC_BIST_SWITCH_Pos      6UL
#define CPUSS_RAM1_CTL_ECC_BIST_SWITCH_Msk      0x40UL
#define CPUSS_RAM1_CTL_ARB_Pos                  16UL
#define CPUSS_RAM1_CTL_ARB_Msk                  0x30000UL
/* CPUSS.FLASHC1_CTL */
#define CPUSS_FLASHC1_CTL_FLASH_WS_Pos          0UL
#define CPUSS_FLASHC1_CTL_FLASH_WS_Msk          0xFUL
#define CPUSS_FLASHC1_CTL_PREF_EN_Pos           4UL
#define CPUSS_FLASHC1_CTL_PREF_EN_Msk           0x10UL
#define CPUSS_FLASHC1_CTL_FLASH_INVALIDATE_Pos  8UL
#define CPUSS_FLASHC1_CTL_FLASH_INVALIDATE_Msk  0x100UL
#define CPUSS_FLASHC1_CTL_ARB_Pos               16UL
#define CPUSS_FLASHC1_CTL_ARB_Msk               0x30000UL
#define CPUSS_FLASHC1_CTL_FLASH_ECC_INJ_EN_Pos  20UL
#define CPUSS_FLASHC1_CTL_FLASH_ECC_INJ_EN_Msk  0x100000UL
#define CPUSS_FLASHC1_CTL_FLASH_ERR_SILENT_Pos  21UL
#define CPUSS_FLASHC1_CTL_FLASH_ERR_SILENT_Msk  0x200000UL
/* CPUSS.FAULT_CTL */
#define CPUSS_FAULT_CTL_ARB_Pos                 16UL
#define CPUSS_FAULT_CTL_ARB_Msk                 0x30000UL
/* CPUSS.MTB_CTL */
#define CPUSS_MTB_CTL_CPU_HALT_TSTOP_EN_Pos     0UL
#define CPUSS_MTB_CTL_CPU_HALT_TSTOP_EN_Msk     0x1UL
/* CPUSS.DAP_CTL */
#define CPUSS_DAP_CTL_INSTANCE_ID_Pos           0UL
#define CPUSS_DAP_CTL_INSTANCE_ID_Msk           0xFUL
/* CPUSS.RAM_STATUS */
#define CPUSS_RAM_STATUS_WB_EMPTY_Pos           0UL
#define CPUSS_RAM_STATUS_WB_EMPTY_Msk           0x1UL
/* CPUSS.RAM1_STATUS */
#define CPUSS_RAM1_STATUS_WB_EMPTY_Pos          0UL
#define CPUSS_RAM1_STATUS_WB_EMPTY_Msk          0x1UL
/* CPUSS.BOOT_RESULT_0 */
#define CPUSS_BOOT_RESULT_0_BOOT_RESULT_Pos     0UL
#define CPUSS_BOOT_RESULT_0_BOOT_RESULT_Msk     0xFFFFFFFFUL
/* CPUSS.BOOT_RESULT_1 */
#define CPUSS_BOOT_RESULT_1_BOOT_RESULT_Pos     0UL
#define CPUSS_BOOT_RESULT_1_BOOT_RESULT_Msk     0xFFFFFFFFUL
/* CPUSS.SL_CTL */
#define CPUSS_SL_CTL_ARB_Pos                    16UL
#define CPUSS_SL_CTL_ARB_Msk                    0x30000UL
/* CPUSS.RAM_ECC_STATUS0 */
#define CPUSS_RAM_ECC_STATUS0_ECC_CAPTURE_ADDR_31_2_Pos 0UL
#define CPUSS_RAM_ECC_STATUS0_ECC_CAPTURE_ADDR_31_2_Msk 0x3FFFFFFFUL
#define CPUSS_RAM_ECC_STATUS0_ECC_CAPTURE_ADDR_SYNDROME_VALID_Pos 31UL
#define CPUSS_RAM_ECC_STATUS0_ECC_CAPTURE_ADDR_SYNDROME_VALID_Msk 0x80000000UL
/* CPUSS.RAM_ECC_STATUS1 */
#define CPUSS_RAM_ECC_STATUS1_ECC_CAPTURE_SYNDROME_Pos 0UL
#define CPUSS_RAM_ECC_STATUS1_ECC_CAPTURE_SYNDROME_Msk 0x7FUL
/* CPUSS.RAM1_ECC_STATUS0 */
#define CPUSS_RAM1_ECC_STATUS0_ECC_CAPTURE_ADDR_31_2_Pos 0UL
#define CPUSS_RAM1_ECC_STATUS0_ECC_CAPTURE_ADDR_31_2_Msk 0x3FFFFFFFUL
#define CPUSS_RAM1_ECC_STATUS0_ECC_CAPTURE_ADDR_SYNDROME_VALID_Pos 31UL
#define CPUSS_RAM1_ECC_STATUS0_ECC_CAPTURE_ADDR_SYNDROME_VALID_Msk 0x80000000UL
/* CPUSS.RAM1_ECC_STATUS1 */
#define CPUSS_RAM1_ECC_STATUS1_ECC_CAPTURE_SYNDROME_Pos 0UL
#define CPUSS_RAM1_ECC_STATUS1_ECC_CAPTURE_SYNDROME_Msk 0x7FUL
/* CPUSS.ECC_TEST */
#define CPUSS_ECC_TEST_WORD_ADDR_Pos            0UL
#define CPUSS_ECC_TEST_WORD_ADDR_Msk            0x1FFFFFFUL
#define CPUSS_ECC_TEST_SYND_DATA_Pos            25UL
#define CPUSS_ECC_TEST_SYND_DATA_Msk            0xFE000000UL
/* CPUSS.INTR */
#define CPUSS_INTR_SRAM0_C_ERROR_Pos            0UL
#define CPUSS_INTR_SRAM0_C_ERROR_Msk            0x1UL
#define CPUSS_INTR_SRAM0_NC_ERROR_Pos           1UL
#define CPUSS_INTR_SRAM0_NC_ERROR_Msk           0x2UL
#define CPUSS_INTR_SRAM1_C_ERROR_Pos            2UL
#define CPUSS_INTR_SRAM1_C_ERROR_Msk            0x4UL
#define CPUSS_INTR_SRAM1_NC_ERROR_Pos           3UL
#define CPUSS_INTR_SRAM1_NC_ERROR_Msk           0x8UL
/* CPUSS.INTR_SET */
#define CPUSS_INTR_SET_SRAM0_C_ERROR_Pos        0UL
#define CPUSS_INTR_SET_SRAM0_C_ERROR_Msk        0x1UL
#define CPUSS_INTR_SET_SRAM0_NC_ERROR_Pos       1UL
#define CPUSS_INTR_SET_SRAM0_NC_ERROR_Msk       0x2UL
#define CPUSS_INTR_SET_SRAM1_C_ERROR_Pos        2UL
#define CPUSS_INTR_SET_SRAM1_C_ERROR_Msk        0x4UL
#define CPUSS_INTR_SET_SRAM1_NC_ERROR_Pos       3UL
#define CPUSS_INTR_SET_SRAM1_NC_ERROR_Msk       0x8UL
/* CPUSS.INTR_MASK */
#define CPUSS_INTR_MASK_SRAM0_C_ERROR_Pos       0UL
#define CPUSS_INTR_MASK_SRAM0_C_ERROR_Msk       0x1UL
#define CPUSS_INTR_MASK_SRAM0_NC_ERROR_Pos      1UL
#define CPUSS_INTR_MASK_SRAM0_NC_ERROR_Msk      0x2UL
#define CPUSS_INTR_MASK_SRAM1_C_ERROR_Pos       2UL
#define CPUSS_INTR_MASK_SRAM1_C_ERROR_Msk       0x4UL
#define CPUSS_INTR_MASK_SRAM1_NC_ERROR_Pos      3UL
#define CPUSS_INTR_MASK_SRAM1_NC_ERROR_Msk      0x8UL
/* CPUSS.INTR_MASKED */
#define CPUSS_INTR_MASKED_SRAM0_C_ERROR_Pos     0UL
#define CPUSS_INTR_MASKED_SRAM0_C_ERROR_Msk     0x1UL
#define CPUSS_INTR_MASKED_SRAM0_NC_ERROR_Pos    1UL
#define CPUSS_INTR_MASKED_SRAM0_NC_ERROR_Msk    0x2UL
#define CPUSS_INTR_MASKED_SRAM1_C_ERROR_Pos     2UL
#define CPUSS_INTR_MASKED_SRAM1_C_ERROR_Msk     0x4UL
#define CPUSS_INTR_MASKED_SRAM1_NC_ERROR_Pos    3UL
#define CPUSS_INTR_MASKED_SRAM1_NC_ERROR_Msk    0x8UL
/* CPUSS.EXT_MS_CTL */
#define CPUSS_EXT_MS_CTL_ARB_Pos                16UL
#define CPUSS_EXT_MS_CTL_ARB_Msk                0x30000UL
/* CPUSS.FLASHC_BERR_STATUS */
#define CPUSS_FLASHC_BERR_STATUS_INTERNAL_ERROR_Pos 0UL
#define CPUSS_FLASHC_BERR_STATUS_INTERNAL_ERROR_Msk 0x1UL
#define CPUSS_FLASHC_BERR_STATUS_FLASH_UNCORRECTABLE_Pos 1UL
#define CPUSS_FLASHC_BERR_STATUS_FLASH_UNCORRECTABLE_Msk 0x2UL
#define CPUSS_FLASHC_BERR_STATUS_FLASH_MEMORY_HOLE_Pos 2UL
#define CPUSS_FLASHC_BERR_STATUS_FLASH_MEMORY_HOLE_Msk 0x4UL
#define CPUSS_FLASHC_BERR_STATUS_FLASH_PROT_VIO_Pos 3UL
#define CPUSS_FLASHC_BERR_STATUS_FLASH_PROT_VIO_Msk 0x8UL
/* CPUSS.FLASHC1_BERR_STATUS */
#define CPUSS_FLASHC1_BERR_STATUS_INTERNAL_ERROR_Pos 0UL
#define CPUSS_FLASHC1_BERR_STATUS_INTERNAL_ERROR_Msk 0x1UL
#define CPUSS_FLASHC1_BERR_STATUS_FLASH_UNCORRECTABLE_Pos 1UL
#define CPUSS_FLASHC1_BERR_STATUS_FLASH_UNCORRECTABLE_Msk 0x2UL
#define CPUSS_FLASHC1_BERR_STATUS_FLASH_MEMORY_HOLE_Pos 2UL
#define CPUSS_FLASHC1_BERR_STATUS_FLASH_MEMORY_HOLE_Msk 0x4UL
#define CPUSS_FLASHC1_BERR_STATUS_FLASH_PROT_VIO_Pos 3UL
#define CPUSS_FLASHC1_BERR_STATUS_FLASH_PROT_VIO_Msk 0x8UL
/* CPUSS.FLASHC_ECC_CTL */
#define CPUSS_FLASHC_ECC_CTL_FLASH_WORD_ADDR_Pos 0UL
#define CPUSS_FLASHC_ECC_CTL_FLASH_WORD_ADDR_Msk 0xFFFFFFUL
#define CPUSS_FLASHC_ECC_CTL_PARITY_Pos         24UL
#define CPUSS_FLASHC_ECC_CTL_PARITY_Msk         0xFF000000UL
/* CPUSS.FLASHC1_ECC_CTL */
#define CPUSS_FLASHC1_ECC_CTL_FLASH_WORD_ADDR_Pos 0UL
#define CPUSS_FLASHC1_ECC_CTL_FLASH_WORD_ADDR_Msk 0xFFFFFFUL
#define CPUSS_FLASHC1_ECC_CTL_PARITY_Pos        24UL
#define CPUSS_FLASHC1_ECC_CTL_PARITY_Msk        0xFF000000UL


#endif /* _CYIP_CPUSS_V3_VER3_H_ */


/* [] END OF FILE */
