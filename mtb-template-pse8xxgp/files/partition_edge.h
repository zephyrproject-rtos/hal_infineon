/***************************************************************************//**
* \file partition_edge.h
* \version 1.0.0
*
* Partition file contains memory addresses
*
* The main purpose of the partition file is to describe how the sections in the
* linker files should be mapped into the output file, and to control the memory
* layout of the output file.
*
********************************************************************************
* \copyright
* Copyright (c) (2020-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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

#define SERAM_START_ADDR            0x30000000 /* sec addr */
#define SERAM_SIZE                  0x00010000 /* 64K */
#define SERAM_CODE_START            SERAM_START_ADDR
#define SERAM_CODE_SIZE             0x00008400
#define SERAM_DATA_START            (SERAM_CODE_START + SERAM_CODE_SIZE)
#define SERAM_DATA_SIZE             (SERAM_SIZE - SERAM_CODE_SIZE)

#define ITCM_NS_START               0x00000000
#define TCM_S_START                 0x10000000
#define ITCM_SIZE                   0x00040000

#define DTCM_NS_START               0x20000000
#define DTCM_S_START                0x30000000
#define DTCM_SIZE                   0x00040000

#define RRAM_NS_START               0x22000000
#define RRAM_S_START                0x32000000
#define RRAM_SIZE                   0x02000000

#define RRAM_NS_SAHB_START          RRAM_NS_START
#define RRAM_S_SAHB_START           RRAM_S_START

#define RRAM_NS_CBUS_START          0x02000000
#define RRAM_S_CBUS_START           0x12000000

#define SRAM0_NS_SAHB_START         0x24000000
#define SRAM0_S_SAHB_START          0x34000000
#define SRAM0_NS_CBUS_START         0x04000000
#define SRAM0_S_CBUS_START          0x14000000
#define SRAM0_SIZE                  0x00080000
#define SRAM0_SHARED_SIZE           0x00002000
#define SRAM0_NS_SAHB_SHARED_START  (SRAM0_NS_SAHB_START + SRAM0_SIZE - SRAM0_SHARED_SIZE)
#define SRAM0_S_SAHB_SHARED_START   (SRAM0_S_SAHB_START + SRAM0_SIZE - SRAM0_SHARED_SIZE)
#define SRAM0_NS_CBUS_SHARED_START  (SRAM0_NS_CBUS_START + SRAM0_SIZE - SRAM0_SHARED_SIZE)
#define SRAM0_S_CBUS_SHARED_START   (SRAM0_S_CBUS_START + SRAM0_SIZE - SRAM0_SHARED_SIZE)

#define SRAM1_NS_SAHB_START         0x24080000
#define SRAM1_S_SAHB_START          0x34080000
#define SRAM1_NS_CBUS_START         0x04080000
#define SRAM1_S_CBUS_START          0x14080000
#define SRAM1_SIZE                  0x00080000
#define SRAM1_SHARED_SIZE           0x00002000
#define SRAM1_NS_SAHB_SHARED_START  (SRAM1_NS_SAHB_START + SRAM1_SIZE - SRAM1_SHARED_SIZE)
#define SRAM1_S_SAHB_SHARED_START   (SRAM1_S_SAHB_START + SRAM1_SIZE - SRAM1_SHARED_SIZE)
#define SRAM1_NS_CBUS_SHARED_START  (SRAM1_NS_CBUS_START + SRAM1_SIZE - SRAM1_SHARED_SIZE)
#define SRAM1_S_CBUS_SHARED_START   (SRAM1_S_CBUS_START + SRAM1_SIZE - SRAM1_SHARED_SIZE)

#define NS_LOAD_ADDR_SIZE           0x00000020
#define SRAM0_NS_LOAD_ADDR          (SRAM0_S_SAHB_START + SRAM0_SIZE - SRAM0_SHARED_SIZE - NS_LOAD_ADDR_SIZE)

#define SOCMEMSRAM_CM55NS_IMAGE_OFFSET   0x00000000
#ifndef APP_SOCMEMSRAM_CM55NS_APP_SIZE
#define APP_SOCMEMSRAM_CM55NS_APP_SIZE 0x00080000
#endif
#ifndef APP_SOCMEMSRAM_GPUBUF_SIZE
#define APP_SOCMEMSRAM_GPUBUF_SIZE 0x00080000
#endif
#ifndef APP_SOCMEMSRAM_SHARED_SIZE
#define APP_SOCMEMSRAM_SHARED_SIZE 0x00100000
#endif

#define SOCMEM_NS_RAM_SAHB_START    0x26000000
#define SOCMEM_S_RAM_SAHB_START     0x36000000
#define SOCMEM_NS_RAM_CBUS_START    0x06000000
#define SOCMEM_S_RAM_CBUS_START     0x16000000
#define SOCMEM_RAM_SIZE             0x00500000
#define SOCMEM_SHARED_MEM_SIZE      APP_SOCMEMSRAM_SHARED_SIZE
#define SOCMEM_SHARED_OFFSET        SOCMEMSRAM_CM55NS_IMAGE_OFFSET + APP_SOCMEMSRAM_CM55NS_APP_SIZE + APP_SOCMEMSRAM_GPUBUF_SIZE
#define SOCMEM_NS_SAHB_SHARED_START (SOCMEM_NS_RAM_SAHB_START + SOCMEM_SHARED_OFFSET)


#define SOCMEM_GPUBUF_OFFSET        SOCMEMSRAM_CM55NS_IMAGE_OFFSET + APP_SOCMEMSRAM_CM55NS_APP_SIZE
#define SOCMEM_GPUBUF_SIZE          APP_SOCMEMSRAM_GPUBUF_SIZE
#define SOCMEM_GPUBUF_START         (SOCMEM_NS_RAM_SAHB_START + SOCMEM_GPUBUF_OFFSET)

#define FLASH_NS_SAHB_START         0x60000000
#define FLASH_S_SAHB_START          0x70000000
#define FLASH_NS_CBUS_START         0x08000000
#define FLASH_S_CBUS_START          0x18000000
#define FLASH_SIZE                  0x04000000

#define MMIO_NS_M33SYS_START        0x42000000
#define MMIO_S_M33SYS_START         0x52000000
#define MMIO_M33SYS_SIZE            0x02000000

#define MMIO_NS_M55APP_START        0x44000000
#define MMIO_S_M55APP_START         0x54000000
#define MMIO_M55APP_SIZE            0x01000000

#define SRAM1_NS_SIZE               (SRAM1_SIZE - SRAM1_SHARED_SIZE)  /** 504K */
#define SRAM1_SHM_OFFSET            (SRAM1_NS_SIZE)

#define RRAM_CM33S_APP_OFFSET       0x0002A400

#define RRAM_SEC_APP_START          (RRAM_S_START + RRAM_CM33S_APP_OFFSET)

#if defined (RRAM_BOOT)
#define RRAM_CM33S_APP_SIZE         (31*1024) /* 23KB */
#else
#define RRAM_CM33S_APP_SIZE         (51*1024) /* 50KB */
#endif

#define RRAM_NVM_MAIN_NS_CODE_OFFSET  (RRAM_CM33S_APP_OFFSET + RRAM_CM33S_APP_SIZE) /* Make sure this address is always multiple of 4KB since RRAM MPC Block can be configured at 4K granularity */

#if defined (RRAM_BOOT)
#define RRAM_NVM_MAIN_NS_CODE_SIZE    (40*1024) /* 40KB */
#else
#define RRAM_NVM_MAIN_NS_CODE_SIZE    (0) /* 0KB */
#endif

#define RRAM_NVM_MAIN_NS_CODE_START   (RRAM_NS_SAHB_START + RRAM_NVM_MAIN_NS_CODE_OFFSET)

#define RRAM_NVM_MAIN_NS_M55CODE_OFFSET  (RRAM_NVM_MAIN_NS_CODE_OFFSET + RRAM_NVM_MAIN_NS_CODE_SIZE)

#if defined (RRAM_BOOT)
#define RRAM_NVM_MAIN_NS_M55CODE_SIZE (40*1024) /* 40KB */
#else
#define RRAM_NVM_MAIN_NS_M55CODE_SIZE (0) /* 0KB */
#endif

#define RRAM_NVM_MAIN_NS_M55CODE_START   (RRAM_NS_CBUS_START + RRAM_NVM_MAIN_NS_M55CODE_OFFSET)

#define RRAM_NVM_MAIN_NS_DATA_OFFSET  (RRAM_NVM_MAIN_NS_M55CODE_OFFSET + RRAM_NVM_MAIN_NS_M55CODE_SIZE)

#if defined (RRAM_BOOT)
#define RRAM_NVM_MAIN_NS_DATA_SIZE    (8*1024) /* 8KB */
#else
#define RRAM_NVM_MAIN_NS_DATA_SIZE    (16*1024) /* 16KB */
#endif

//#define RRAM_NVM_MAIN_NS_SIZE       (RRAM_NVM_MAIN_NS_CODE_SIZE + RRAM_NVM_MAIN_NS_M55CODE_SIZE + RRAM_NVM_MAIN_NS_DATA_SIZE) /** 60KB+20KB */
#define RRAM_NVM_MAIN_NS_SIZE       (40*1024) /* 40KB */
#define RRAM_NVM_MAIN_NS_OFFSET     (RRAM_NVM_MAIN_NS_CODE_OFFSET)


#define RRAM_NVM_PROTECTED_OFFSET   (CPUSS_RRAMC_MAIN_N*8*1024) /** 256K offset */
#define RRAM_NVM_PROTECTED_NS_SIZE  (CPUSS_RRAMC_PROTECTED_X*4*1024) /** 128K */
#define RRAM_NVM_DATA_NS_START      (RRAM_NS_SAHB_START + 0x00003C000)
