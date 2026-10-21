/***************************************************************************//**
* \file cyip_cpuss_v6.h
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

#ifndef _CYIP_CPUSS_V6_H_
#define _CYIP_CPUSS_V6_H_

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
  __IOM uint32_t PROTECTION;                    /*!< 0x0000000C Protection control register */
  __IOM uint32_t PRIV_ROM;                      /*!< 0x00000010 ROM privilege register */
  __IOM uint32_t PRIV_RAM;                      /*!< 0x00000014 RAM privilege register */
  __IOM uint32_t PRIV_FLASH;                    /*!< 0x00000018 Flash privilege register */
  __IOM uint32_t WOUNDING;                      /*!< 0x0000001C Wounding register */
  __IOM uint32_t INT_SEL;                       /*!< 0x00000020 Interrupt multiplexer select register */
  __IOM uint32_t INT_MODE;                      /*!< 0x00000024 DSI interrupt pulse mode register */
  __IOM uint32_t NMI_MODE;                      /*!< 0x00000028 DSI NMI pulse mode register */
   __IM uint32_t RESERVED;
  __IOM uint32_t FLASH_CTL;                     /*!< 0x00000030 FLASH control register */
  __IOM uint32_t ROM_CTL;                       /*!< 0x00000034 ROM control register */
  __IOM uint32_t RAM_CTL;                       /*!< 0x00000038 RAM control register */
  __IOM uint32_t DMAC_CTL;                      /*!< 0x0000003C DMA controller register */
   __IM uint32_t RESERVED1[24];
  __IOM uint32_t PRIV_RAM1;                     /*!< 0x000000A0 RAM 1 privilege register */
  __IOM uint32_t RAM1_CTL;                      /*!< 0x000000A4 RAM 1 control register */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t MTB_CTL;                       /*!< 0x000000B0 MTB control register */
   __IM uint32_t RESERVED3[19];
  __IOM uint32_t SL_CTL[24];                    /*!< 0x00000100 Slave control register */
   __IM uint32_t RESERVED4[168];
  __IOM uint32_t EXT_MS_CTL;                    /*!< 0x00000400 External master control register */
} CPUSS_Type;                                   /*!< Size = 1028 (0x404) */


/* CPUSS.CONFIG */
#define CPUSS_CONFIG_VECT_IN_RAM_Pos            0UL
#define CPUSS_CONFIG_VECT_IN_RAM_Msk            0x1UL
/* CPUSS.SYSREQ */
#define CPUSS_SYSREQ_SYSCALL_COMMAND_Pos        0UL
#define CPUSS_SYSREQ_SYSCALL_COMMAND_Msk        0xFFFFUL
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
/* CPUSS.PROTECTION */
#define CPUSS_PROTECTION_PROTECTION_MODE_Pos    0UL
#define CPUSS_PROTECTION_PROTECTION_MODE_Msk    0xFUL
#define CPUSS_PROTECTION_FLASH_LOCK_Pos         30UL
#define CPUSS_PROTECTION_FLASH_LOCK_Msk         0x40000000UL
#define CPUSS_PROTECTION_PROTECTION_LOCK_Pos    31UL
#define CPUSS_PROTECTION_PROTECTION_LOCK_Msk    0x80000000UL
/* CPUSS.PRIV_ROM */
#define CPUSS_PRIV_ROM_BROM_PROT_LIMIT_Pos      0UL
#define CPUSS_PRIV_ROM_BROM_PROT_LIMIT_Msk      0xFFUL
#define CPUSS_PRIV_ROM_SROM_PROT_LIMIT_Pos      16UL
#define CPUSS_PRIV_ROM_SROM_PROT_LIMIT_Msk      0x3FF0000UL
/* CPUSS.PRIV_RAM */
#define CPUSS_PRIV_RAM_RAM_PROT_LIMIT_Pos       0UL
#define CPUSS_PRIV_RAM_RAM_PROT_LIMIT_Msk       0x1FFUL
/* CPUSS.PRIV_FLASH */
#define CPUSS_PRIV_FLASH_FLASH_PROT_LIMIT_Pos   0UL
#define CPUSS_PRIV_FLASH_FLASH_PROT_LIMIT_Msk   0xFFFUL
/* CPUSS.WOUNDING */
#define CPUSS_WOUNDING_RAM_WOUND_Pos            16UL
#define CPUSS_WOUNDING_RAM_WOUND_Msk            0x70000UL
#define CPUSS_WOUNDING_FLASH_WOUND_Pos          20UL
#define CPUSS_WOUNDING_FLASH_WOUND_Msk          0x700000UL
#define CPUSS_WOUNDING_RAM1_WOUND_Pos           24UL
#define CPUSS_WOUNDING_RAM1_WOUND_Msk           0x7000000UL
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
#define CPUSS_FLASH_CTL_FLASH_WS_Msk            0x3UL
#define CPUSS_FLASH_CTL_PREF_EN_Pos             4UL
#define CPUSS_FLASH_CTL_PREF_EN_Msk             0x10UL
#define CPUSS_FLASH_CTL_FLASH_INVALIDATE_Pos    8UL
#define CPUSS_FLASH_CTL_FLASH_INVALIDATE_Msk    0x100UL
#define CPUSS_FLASH_CTL_ARB_Pos                 16UL
#define CPUSS_FLASH_CTL_ARB_Msk                 0x30000UL
/* CPUSS.ROM_CTL */
#define CPUSS_ROM_CTL_ROM_WS_Pos                0UL
#define CPUSS_ROM_CTL_ROM_WS_Msk                0x1UL
#define CPUSS_ROM_CTL_ARB_Pos                   16UL
#define CPUSS_ROM_CTL_ARB_Msk                   0x30000UL
/* CPUSS.RAM_CTL */
#define CPUSS_RAM_CTL_ARB_Pos                   16UL
#define CPUSS_RAM_CTL_ARB_Msk                   0x30000UL
/* CPUSS.DMAC_CTL */
#define CPUSS_DMAC_CTL_ARB_Pos                  16UL
#define CPUSS_DMAC_CTL_ARB_Msk                  0x30000UL
/* CPUSS.PRIV_RAM1 */
#define CPUSS_PRIV_RAM1_RAM_PROT_LIMIT_Pos      0UL
#define CPUSS_PRIV_RAM1_RAM_PROT_LIMIT_Msk      0x1FFUL
/* CPUSS.RAM1_CTL */
#define CPUSS_RAM1_CTL_ARB_Pos                  16UL
#define CPUSS_RAM1_CTL_ARB_Msk                  0x30000UL
/* CPUSS.MTB_CTL */
#define CPUSS_MTB_CTL_CPU_HALT_TSTOP_EN_Pos     0UL
#define CPUSS_MTB_CTL_CPU_HALT_TSTOP_EN_Msk     0x1UL
/* CPUSS.SL_CTL */
#define CPUSS_SL_CTL_ARB_Pos                    16UL
#define CPUSS_SL_CTL_ARB_Msk                    0x30000UL
/* CPUSS.EXT_MS_CTL */
#define CPUSS_EXT_MS_CTL_ARB_Pos                16UL
#define CPUSS_EXT_MS_CTL_ARB_Msk                0x30000UL


#endif /* _CYIP_CPUSS_V6_H_ */


/* [] END OF FILE */
