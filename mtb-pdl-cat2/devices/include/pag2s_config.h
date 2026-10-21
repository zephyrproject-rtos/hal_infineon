/***************************************************************************//**
* \file pag2s_config.h
*
* \brief
* PAG2S device configuration header
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

#ifndef _PAG2S_CONFIG_H_
#define _PAG2S_CONFIG_H_

/* Clock Connections */
typedef enum
{
    PCLK_TCPWM_CLOCKS0              = 0x0000u,  /* tcpwm.clocks[0] */
    PCLK_USBPD0_CLOCK_RX            = 0x0001u,  /* usbpd[0].clock_rx */
    PCLK_USBPD0_CLOCK_TX            = 0x0002u,  /* usbpd[0].clock_tx */
    PCLK_USBPD0_CLOCK_SAR           = 0x0003u,  /* usbpd[0].clock_sar */
    PCLK_USBPD0_CLOCK_FILTER1       = 0x0004u,  /* usbpd[0].clock_filter1 */
    PCLK_USBPD0_CLOCK_FILTER2       = 0x0005u,  /* usbpd[0].clock_filter2 */
    PCLK_USBPD0_CLOCK_REFGEN        = 0x0006u,  /* usbpd[0].clock_refgen */
    PCLK_USBPD0_CLOCK_BCH_DET       = 0x0007u,  /* usbpd[0].clock_bch_det */
    PCLK_USBPD0_CLOCK_PASC          = 0x0008u,  /* usbpd[0].clock_pasc */
    PCLK_USBPD0_CLOCK_GDRV          = 0x0009u,  /* usbpd[0].clock_gdrv */
    PCLK_USBPD0_CLOCK_VBTR          = 0x000Au,  /* usbpd[0].clock_vbtr */
    PCLK_USBPD0_CLOCK_IBTR          = 0x000Bu,  /* usbpd[0].clock_ibtr */
    PCLK_USBPD0_CLOCK_PASC_LP       = 0x000Cu   /* usbpd[0].clock_pasc_lp */
} en_clk_dst_t;

/* Fault connections */
typedef enum
{
    CPUSS_FAULT_RAMC_C_ECC          = 0x0000u,
    CPUSS_FAULT_RAMC_NC_ECC         = 0x0001u,
    CPUSS_FAULT_FLASHC_C_ECC        = 0x0004u,
    CPUSS_FAULT_FLASHC_NC_ECC       = 0x0005u,
    CPUSS_FAULT_FLASHC_BUS_ERR      = 0x0006u,
    SRSS_FAULT_CRWDT                = 0x000Au
} en_sysfault_source_t;

/* Include IP definitions */
#include "ip/cyip_sflash_128X4.h"
#include "ip/cyip_peri.h"
#include "ip/cyip_hsiom.h"
#include "ip/cyip_srsshv.h"
#include "ip/cyip_gpio.h"
#include "ip/cyip_tcpwm_v2.h"
#include "ip/cyip_cpuss_v3_ver3.h"
#include "ip/cyip_dmac_v3_ver3.h"
#include "ip/cyip_spcif_v3_ver3.h"
#include "ip/cyip_spcif1_v3_ver3.h"
#include "ip/cyip_fault_v3.h"

/* Parameter Defines */
/* CPUSS version (2 or 3) */
#define CPUSS_CPUSS_VER                 3u
/* CM0 present or CM0+ present (1=CM0, 0=CM0+) */
#define CPUSS_CM0_PRESENT               0u
/* CM0+ Memory protection unit present/not (0=not present, 8=present). */
#define CPUSS_CM0_MPU                   8u
/* CM0+ Micro Trace Buffer (MTB) Present or not (Must be '0' for CM0) */
#define CPUSS_MTB_PRESENT               0u
/* MTB SRAM size in kilo bytes (0, 1, 2, or 4). Must be '0' for CM0, Non zero
   value only for CM0+. */
#define CPUSS_MTB_SRAM_SIZE             0u
/* Maximum speed that system will run at (0=48MHz, 1=16MHz) */
#define CPUSS_MAX_16_MHZ                0u
/* System RAM parition 0, size in kilobytes */
#define CPUSS_SRAM_SIZE                 8u
/* System RAM parition 1, size in kilobytes */
#define CPUSS_SRAM1_SIZE                0u
/* Total ROM size in kilobytes */
#define CPUSS_ROM_SIZE                  64u
/* Product has ROM available for system usage (1) or not (0) */
#define CPUSS_SYSTEM_ROM                1u
/* Boot ROM partition size in kilobytes in multiple of 2^n (2,4,8,16,32,64) */
#define CPUSS_BOOT_ROM_SIZE             16u
/* Boot ROM available (1) or all classified as System Rom (0) */
#define CPUSS_ROMC_BOOT_ROM_PRESENT     1u
/* Number of external slave ports on System Interconnect */
#define CPUSS_SL_NR                     1u
/* Define Erased Value of Flash Controller 0 */
#define CPUSS_FLASHC_ERASE_STATE        0u
/* Define Erased Value of Flash Controller 1 */
#define CPUSS_FLASHC_1_ERASE_STATE      0u
/* Flash size in kilobytes */
#define CPUSS_FLASH_SIZE                64u
/* Flash memory present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_FLASHC_PRESENT            1u
/* FLASH has ECC and fault system */
#define CPUSS_FLASHC_PRESENT_WITH_ECC   1u
/* Flash size in kilobytes for 2nd Flash Controller */
#define CPUSS_FLASHC1_SIZE              16u
/* Flash memory Controller 1 present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_FLASHC1_PRESENT           0u
/* FLASH has ECC and fault system */
#define CPUSS_FLASHC1_PRESENT_WITH_ECC  0u
/* Debug support (0=No, 1=Yes) */
#define CPUSS_CM0_DBG                   1u
/* Number of break-point comparators ([0,4]) */
#define CPUSS_CM0_BKPT                  4u
/* Number of watch-point comparators ([0,2]) */
#define CPUSS_CM0_WPT                   2u
/* Serial multiplier (1) or parallel multiplier (0) */
#define CPUSS_CM0_SMUL                  0u
/* Clock Source clk_lf implemented in SysTick Counter. When 0, not implemented,
   1=implemented */
#define CPUSS_CM0_SYST_CLKSOURCE_LF     1u
/* Number of interrupt request inputs to CM0 ([8,32]) - called CM0_NUMIRQ in
   design */
#define CPUSS_INT_NR                    11u
/* Number of wakeup interrupt controller lines (always includes NMI, RXEV, so
   min=2) */
#define CPUSS_CM0_WICLINES              8u
/* Indicates whether DSI/FixedFunction interrupt multiplexer is present (0=No,
   1=Yes) */
#define CPUSS_INT_DSI                   0u
/* Implement DSI interrupt sync and pulse generation (1) or not (0) */
#define CPUSS_INT_DSI_SYNC              0u
/* Wounding supported (1) or not supported (0) - must be 1 currently */
#define CPUSS_WOUNDING                  1u
/* Protection modes supported (1) or not supported (0) - must be 1 currently */
#define CPUSS_PROTECTION                1u
/* DW/DMA Controller present (0=No, 1=Yes) */
#define CPUSS_DMAC_PRESENT              0u
/* Product is a multi-master system (same as CPUMEMSS.DMAC_PRESENT) */
#define CPUSS_MULTI_MASTER              0u
/* PTM interface present (0=No, 1=Yes) */
#define CPUSS_PTM_PRESENT               0u
/* Width of the PTM interface in bits ([2,32]) */
#define CPUSS_PTM_NR                    0u
/* Implement full (8-step) RAM BIST (1) or simple (1-step) RAM BIST (0) */
#define CPUSS_BIST_FULL                 1u
/* Number of external SRAMs connected to the CPUSS BIST controller (0 to 12) */
#define CPUSS_BIST_EXT_SRAM_NR          6u
/* Number of SRAMs connected to the CPUSS BIST controller (BIST_EXT_SRAM_NR+4) */
#define CPUSS_BIST_SRAM_NR              10u
/* CoreSight Part Identification Number */
#define CPUSS_JEPID                     52u
/* CoreSight Part Identification Number */
#define CPUSS_JEPCONTINUATION           0u
/* CoreSight Part Identification Number */
#define CPUSS_PARTNUMBER                203u
/* External Master Present */
#define CPUSS_EXT_MS_PRESENT            0u
/* External Master M1 Present (Note either DMA_PRESENT or EXT_MS_PRESENT must also
   be set) */
#define CPUSS_EXT_MS1_PRESENT           0u
/* RAM controller 1 present (0=No, 1=Yes) */
#define CPUSS_RAMC1_PRESENT             0u
/* Enforce Secure Access restrictions (0=No, 1=Yes) */
#define CPUSS_SECURE_ACCESS             1u
/* SWD MultiDrop Present */
#define CPUSS_SWD_MULTIDROP             0u
/* Enable SROM DMA Access */
#define CPUSS_SROM_ACCESS_PRESENT       0u
/* Enable ECC for RAMC (SRAM Controller 0) */
#define CPUSS_RAMC_ECC_PRESENT          1u
/* Is the Address included in ECC calculation, impacts timing (SRAM Controller 0) */
#define CPUSS_RAMC_ECC_ADDR_PRESENT     1u
/* Enable ECC for RAMC1 (SRAM Controller 1) */
#define CPUSS_RAMC1_ECC_PRESENT         0u
/* Is the Address included in ECC calculation, impacts timing (SRAM Controller 0) */
#define CPUSS_RAMC1_ECC_ADDR_PRESENT    0u
/* Vector Table Relocation ROM Offset (In KB. Supported Values are 4/8/16/32 KB) */
#define CPUSS_VECT_TABLE_ROM_OFFSET     4u
/* Fault logging system present */
#define CPUSS_FAULT_PRESENT             1u
/* Fault start address in MMIO address space */
#define CPUSS_FAULT_ADDR                0x00030000u
/* Mask for Fault MMIO */
#define CPUSS_FAULT_MASK                1139u
/* Enables Fault Report by Fault structure for SRAM/Flash (0=Use Interrupts, 1=Use
   Fault signaling) */
#define CPUSS_ECC_REPORT_BY_FAULT       1u
/* Inverse value of ECC_REPORT_BY_FAULT */
#define CPUSS_ECC_REPORT_BY_INTR        0u
/* 0=ULL65, 1=MXS40-ULP, 2=MXS40E, 3=M0S8, 4=MXS40Sv2 -HD, 5=F45, 6=MXS40Sv2, ,
   7=t28hpm, 8=t28hpl, 9=t28hpc */
#define CPUSS_PLATFORM_VARIANT          3u
/* 0=CYP (Cypress), 1=SNPS (Synopsys), 2=ARM,3=Broadcom, 4=TSMC */
#define CPUSS_RAM_VEND                  0u
/* Select Cell VT type. Drives the type of standard cell to be used in MXTK. (0 =
   scs8hd, 1 = scs8hdll, 2 = scs8hv) */
#define CPUSS_CELL_VT_TYPE              0u
/* ECC enabled for all FLASH */
#define CPUSS_CHIP_TOP_FLASH_ECC        1u
/* Flash block size (per macro). */
#define CPUSS_CHIP_TOP_FLASH_BLOCK_SIZE 64u
/* Flash ECC enabled with no fault system */
#define CPUSS_CHIP_TOP_FLASHC_ECC_INT   0u
/* Flash block size (per macro). */
#define CPUSS_CHIP_TOP_FLASHC1_BLOCK_SIZE 16u
/* Flash ECC enabled with no fault system, controller 1 */
#define CPUSS_CHIP_TOP_FLASHC1_ECC_INT  0u
/* Enable ECC for RAMC with no fault system (SRAM Controller 0) */
#define CPUSS_CHIP_TOP_RAMC_ECC_INT     0u
/* Enable ECC for RAMC1 with no fault system (SRAM Controller 1) */
#define CPUSS_CHIP_TOP_RAMC1_ECC_INT    0u
/* MTB SRAM Base adress - Value should be computed from Memory Map */
#define CPUSS_CM0PMTB_MTB_SRAMBASE      0u
/* Flash memory present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_CPUMEMSS_FLASHC_PRESENT   1u
/* Flash memory Controller 1 present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_CPUMEMSS_FLASHC1_PRESENT  0u
/* DW/DMA Controller present (0=No, 1=Yes) */
#define CPUSS_CPUMEMSS_DMAC_PRESENT     0u
/* Fault logging system present */
#define CPUSS_CPUMEMSS_FAULT_PRESENT    1u
/* Number of DMA Channels (8, 16, or 32) */
#define CPUSS_DMAC_CH_NR                0u
/* Width in bits of a DMA channel number (derived from CH_NR as
   roundup(log2(CH_NR))) */
#define CPUSS_DMAC_CH_ADDR_WIDTH        0u
/* Number of fault structures. Legal range [1, 4] */
#define CPUSS_FAULT_FAULT_NR            2u
/* Flash memory present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_SPCIF_FLASHC_PRESENT      1u
/* Flash memory present with no ECC */
#define CPUSS_SPCIF_FLASHC_PRESENT_NO_ECC 0u
/* FLASH has ECC and fault system */
#define CPUSS_SPCIF_FLASHC_PRESENT_WITH_ECC 1u
/* Enables Fault Report by Fault structure for SRAM/Flash (0=Use Interrupts, 1=Use
   Fault signaling) */
#define CPUSS_SPCIF_ECC_REPORT_BY_FAULT 1u
/* Flash type (0=FM, 1=FMLT, 2=FS, 3=FSLT) */
#define CPUSS_SPCIF_FLASH_TYPE          3u
/* Use 2X?? Option for FLASH to allow parallel code execution and programming of
   FLASH */
#define CPUSS_SPCIF_FLASH_PARALLEL_PGM_EN 0u
/* HOBTO-M ULL65 SRAM/SROM required */
#define CPUSS_SPCIF_ULL65               0u
/* Product uses FLASH-Lite (1) or regular FLASH (0) */
#define CPUSS_SPCIF_FMLT                0u
/* Flash type being used (0=Lite, 1=Regular) */
#define CPUSS_SPCIF_FM                  0u
/* Flash type is FMLT or S8FS */
#define CPUSS_SPCIF_FMLT_OR_S8FS        1u
/* S8FS_ver2 */
#define CPUSS_SPCIF_FLASH_S8FS_VER2     1u
/* Not S8FS_ver2 */
#define CPUSS_SPCIF_FLASH_NOT_S8FS_VER2 0u
/* Total Flash size in multiples of 256 bytes */
#define CPUSS_SPCIF_FLASH_SIZE          255u
/* The Flash read word width in bits (32, 64 or 128) */
#define CPUSS_SPCIF_FLASH_READ_WIDTH    64u
/* Total Supervisory Flash size in multiples of 256 bytes (0=1x256, 1=2x256, ...) */
#define CPUSS_SPCIF_SFLASH_SIZE         3u
/* Flash program/erase page size (64, 128 or 256 bytes) */
#define CPUSS_SPCIF_FLASH_PAGE_SIZE     128u
/* Number of Flash macros used in the device (1, 2, 3 or 4) */
#define CPUSS_SPCIF_FLASH_MACROS        1u
/* Number of Flash macros minus 1 */
#define CPUSS_SPCIF_FLASH_MACROS_MINUS1 0u
/* Flash macro #1 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_1       0u
/* Flash macro #2 (the third) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_2       0u
/* Flash macro #3 (the fourth) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_3       0u
/* S8FS_ver2 & Flash Macro 1 */
#define CPUSS_SPCIF_FLASH_S8FS_VER2_M1  0u
/* S8FS_ver2 & Flash Macro 2 */
#define CPUSS_SPCIF_FLASH_S8FS_VER2_M2  0u
/* S8FS_ver2 & Flash Macro 3 */
#define CPUSS_SPCIF_FLASH_S8FS_VER2_M3  0u
/* Not S8FS_ver2 & Flash Macro 1 */
#define CPUSS_SPCIF_FLASH_NOT_S8FS_VER2_M1 0u
/* Not S8FS_ver2 & Flash Macro 2 */
#define CPUSS_SPCIF_FLASH_NOT_S8FS_VER2_M2 0u
/* Not S8FS_ver2 & Flash Macro 3 */
#define CPUSS_SPCIF_FLASH_NOT_S8FS_VER2_M3 0u
/* SPCIF Timer clock is synchronous (1) or asynchronous (0) to clk_sys */
#define CPUSS_SPCIF_SYNCHRONOUS         1u
/* Product uses SRSS-Lite (1) or SRSSv2 (0) - used to determine NVL parameters */
#define CPUSS_SPCIF_SRSSLT              1u
/* NVLatches present (0=No, 1=Yes) */
#define CPUSS_SPCIF_NVLATCH             0u
/* NVLatches size in bytes (default=8) */
#define CPUSS_SPCIF_NVLATCH_SIZE        8u
/* Inverse value of ECC_REPORT_BY_FAULT */
#define CPUSS_SPCIF_ECC_REPORT_BY_INTR  0u
/* Flash memory present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_SPCIF1_FLASHC_PRESENT     0u
/* Flash memory present with no ECC */
#define CPUSS_SPCIF1_FLASHC_PRESENT_NO_ECC 0u
/* FLASH has ECC and fault system */
#define CPUSS_SPCIF1_FLASHC_PRESENT_WITH_ECC 0u
/* Enables Fault Report by Fault structure for SRAM/Flash (0=Use Interrupts, 1=Use
   Fault signaling) */
#define CPUSS_SPCIF1_ECC_REPORT_BY_FAULT 1u
/* Flash type (0=FM, 1=FMLT, 2=FS, 3=FSLT) */
#define CPUSS_SPCIF1_FLASH_TYPE         3u
/* Use 2X?? Option for FLASH to allow parallel code execution and programming of
   FLASH */
#define CPUSS_SPCIF1_FLASH_PARALLEL_PGM_EN 0u
/* HOBTO-M ULL65 SRAM/SROM required */
#define CPUSS_SPCIF1_ULL65              0u
/* Product uses FLASH-Lite (1) or regular FLASH (0) */
#define CPUSS_SPCIF1_FMLT               0u
/* Flash type being used (0=Lite, 1=Regular) */
#define CPUSS_SPCIF1_FM                 0u
/* Flash type is FMLT or S8FS */
#define CPUSS_SPCIF1_FMLT_OR_S8FS       1u
/* S8FS_ver2 */
#define CPUSS_SPCIF1_FLASH_S8FS_VER2    1u
/* Not S8FS_ver2 */
#define CPUSS_SPCIF1_FLASH_NOT_S8FS_VER2 0u
/* Total Flash size in multiples of 256 bytes */
#define CPUSS_SPCIF1_FLASH_SIZE         63u
/* The Flash read word width in bits (32, 64 or 128) */
#define CPUSS_SPCIF1_FLASH_READ_WIDTH   64u
/* Total Supervisory Flash size in multiples of 256 bytes */
#define CPUSS_SPCIF1_SFLASH_SIZE        3u
/* Flash program/erase page size (64, 128 or 256 bytes) */
#define CPUSS_SPCIF1_FLASH_PAGE_SIZE    128u
/* Number of Flash macros used in the device (1, 2, 3 or 4) */
#define CPUSS_SPCIF1_FLASH_MACROS       1u
/* Number of Flash macros minus 1 */
#define CPUSS_SPCIF1_FLASH_MACROS_MINUS1 0u
/* Flash macro #1 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF1_FLASH_MACRO_1      0u
/* Flash macro #2 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF1_FLASH_MACRO_2      0u
/* Flash macro #3 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF1_FLASH_MACRO_3      0u
/* S8FS_ver2 & Flash Macro 1 */
#define CPUSS_SPCIF1_FLASH_S8FS_VER2_M1 0u
/* S8FS_ver2 & Flash Macro 2 */
#define CPUSS_SPCIF1_FLASH_S8FS_VER2_M2 0u
/* S8FS_ver2 & Flash Macro 3 */
#define CPUSS_SPCIF1_FLASH_S8FS_VER2_M3 0u
/* Not S8FS_ver2 & Flash Macro 1 */
#define CPUSS_SPCIF1_FLASH_NOT_S8FS_VER2_M1 0u
/* Not S8FS_ver2 & Flash Macro 2 */
#define CPUSS_SPCIF1_FLASH_NOT_S8FS_VER2_M2 0u
/* Not S8FS_ver2 & Flash Macro 3 */
#define CPUSS_SPCIF1_FLASH_NOT_S8FS_VER2_M3 0u
/* SPCIF Timer clock is synchronous (1) or asynchronous (0) to clk_sys */
#define CPUSS_SPCIF1_SYNCHRONOUS        1u
/* NVLatches present (0=No, 1=Yes) */
#define CPUSS_SPCIF1_NVLATCH            0u
/* NVLatches size in bytes (default=8) */
#define CPUSS_SPCIF1_NVLATCH_SIZE       8u
/* Inverse value of ECC_REPORT_BY_FAULT */
#define CPUSS_SPCIF1_ECC_REPORT_BY_INTR 0u
/* IOSS Phase */
#define IOSS_IOSS_PHASE                 5u
/* Route REFGEN vinref & voutref to AMUX bus when set */
#define IOSS_SIO_REF_HOOKUP             0u
/* Use 1.8V signaling on XRES (Xres4 cell only) */
#define IOSS_USE_1P8V_SIGNALING_XRES4   0u
/* Number of ports in device */
#define IOSS_GPIO_GPIO_PORT_NR          2u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO7 1u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present ( Add 50ns Glitch Filter in datapath) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN7 0u
/* Control register to improve IO testing */
#define IOSS_GPIO_IO_TEST_CTL           1u
/* GPIO_V1P2 cells used ? */
#define IOSS_GPIO_IO_GPIOV1P2           0u
/* Is there a pump in IOSS ? (same as GLOBAL.HAS_PUMP_IN_IOSS) */
#define IOSS_HSIOM_PUMP                 0u
/* Number of AMUX splitter cells */
#define IOSS_HSIOM_AMUX_SPLIT_NR        0u
/* Number of HSIOM ports in device (same as GPIO.GPIO_PRT_NR) */
#define IOSS_HSIOM_HSIOM_PORT_NR        2u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO5 1u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO6 1u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO7 1u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO7 0u
/* Number of PRGIO instances (in 8b ports) */
#define IOSS_PRGIO_PRGIO_NR             0u
/* Number of programmable clocks (outputs) */
#define PERI_PCLK_CLOCK_NR              13u
/* Number of 8.0 dividers */
#define PERI_PCLK_DIV_8_NR              6u
/* Number of 16.0 dividers */
#define PERI_PCLK_DIV_16_NR             7u
/* Number of 16.5 (fractional) dividers */
#define PERI_PCLK_DIV_16_5_NR           0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PCLK_DIV_24_5_NR           0u
/* Divider number width: roundup(log2(max(DIV_*_NR)) */
#define PERI_PCLK_DIV_ADDR_WIDTH        3u
/* Trigger module present (0=No, 1=Yes) */
#define PERI_TR                         0u
/* Number of trigger groups */
#define PERI_TR_GROUP_NR                0u
/* Is this product using automotive SFLASH layout ? */
#define SFLASH_AUTO_SFLASH              1u
/* Does this product have standard SWD placement control ? */
#define SFLASH_STD_SWD                  1u
/* Does this product use SRSS-HV ? */
#define SFLASH_SRSSHV                   1u
/* Does this product have PACSS? */
#define SFLASH_HAS_PACSS                0u
/* Does this product include PACSS + OCD (m0s8pacss + s8panatk) ? */
#define SFLASH_HAS_OCD                  0u
/* Does this product include SAR (m0s8sar) ? */
#define SFLASH_HAS_SAR                  0u
/* SRSSHV will use the NOESD version when set to 1 */
#define SRSSHV_SRSSHV_NOESD             0u
/* Number of bits from WDT_MATCH that are ignore in comparison */
#define SRSSHV_WDT_MATCH_MASK           0u
/* Connect vddio bus to pad_vddd (0) or pad_vccq_or_vddio (1) */
#define SRSSHV_HAS_VDDIO_PAD            1u
/* Enable ASIL-B Support - Add PILO/HPOSC, etc. {0=No, 1=Yes} */
#define SRSSHV_ENABLE_ASILB_SUPPORT     1u
/* CRWDT Enable (0=Not Present, 1=Present) */
#define SRSSHV_CRWDT_PRESENT            0u
/* HPOSC Enable (0=Not Present, 1=Present) */
#define SRSSHV_HPOSC_PRESENT            0u
/* PILO Enable (0=Not Present, 1=Present) */
#define SRSSHV_PILO_PRESENT             0u
/* Number of counters per IP (1..8) */
#define TCPWM_CNT_NR                    1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define TCPWM_SPARE_EN                  0u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define TCPWM_SPARE_STDLIB_CFG          2u
/* Enable CCG3PA related trim registers */
#define USBPD_CCG3PA_EN                 0u
/* Enable CCG5 related trim registers */
#define USBPD_CCG5_EN                   0u
/* Enable CCG3PA2 related trim registers */
#define USBPD_CCG3PA2_EN                0u
/* Enable CMG1 related trim registers */
#define USBPD_CMG1_EN                   0u
/* Enable CCG6 related trim registers */
#define USBPD_CCG6_EN                   0u
/* Enable CCG2B related trim registers */
#define USBPD_CCG2B_EN                  0u
/* Enable PAG1S_EN related trim registers */
#define USBPD_PAG1S_EN                  0u
/* Enable ACG1F_EN related trim registers */
#define USBPD_ACG1F_EN                  0u
/* Enable CCG6DF_EN related trim registers */
#define USBPD_CCG6DF_EN                 0u
/* Enable CCG7D_EN related trim registers */
#define USBPD_CCG7D_EN                  0u
/* Enable PMG1S3_EN related trim registers */
#define USBPD_PMG1S3_EN                 0u
/* Enable CCG7S_EN related trim registers */
#define USBPD_CCG7S_EN                  0u
/* Enable PAG2S_EN related trim registers */
#define USBPD_PAG2S_EN                  1u
/* Enable CMG2 related trim registers */
#define USBPD_CMG2_EN                   0u
/* Enable CCG6 related trim registers */
#define USBPD_AGNOSTIC_phase10_CCG6_EN  0u
/* Enable ACG1F_EN related trim registers */
#define USBPD_AGNOSTIC_phase10_ACG1F_EN 0u
/* Enable CCG6DF_EN related trim registers */
#define USBPD_AGNOSTIC_phase10_CCG6DF_EN 0u
/* ACG1F or CCG6DF enable */
#define USBPD_AGNOSTIC_phase10_ACG1F_CCG6DF_EN 0u
/* PASC or CCG6DF enable */
#define USBPD_AGNOSTIC_phase10_PASC_CCG6DF_EN 0u
/* SRAM_EN (1:Yes, 0:No) */
#define USBPD_AGNOSTIC_phase10_SRAM_EN  1u
/* USBPD Number of Instances (0=1 instance, 1= 2 instances) */
#define USBPD_AGNOSTIC_phase10_INSTANCE_NUM 0u
/* Spare cell Library selection 1=LS,2=HD,3=HV */
#define USBPD_AGNOSTIC_phase10_SPARE_STDLIB_CFG 2u
/* Spare Cell Enable */
#define USBPD_AGNOSTIC_phase10_SPARE_EN 1u
/* USBPD function enable */
#define USBPD_AGNOSTIC_phase10_PD_EN    1u
/* LF counter enable */
#define USBPD_AGNOSTIC_phase10_LF_CNTR_EN 1u
/* Number of USBPD AMUX NHVN hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_USB_AMUX_NHVN_NUM 13u
/* Enable function/related registers of PAG1S/next-gen products */
#define USBPD_AGNOSTIC_phase10_PASC_EN  0u
/* Enable VBUS transition control logic */
#define USBPD_AGNOSTIC_phase10_VBTR_EN  1u
/* 0: Use TX_HEADER register for GoodCRC Expected Header 1: Use
   RX_EXPECT_GOODCRC_MSG.EXPECTED_HEADER register for GoodCRC Expected Header */
#define USBPD_AGNOSTIC_phase10_NOT_USE_TX_HEADER 1u
/* 0: Use RX_ORDER_SET_CTRL register for TX_SOP Order Set 1: Use TX_SOP_ORDER_SET
   register for TX_SOP Order Set */
#define USBPD_AGNOSTIC_phase10_NOT_USE_RX_ORDER_SET 1u
/* Hardware handles the TX Specification Revsion field */
#define USBPD_AGNOSTIC_phase10_SPEC_REV_EN 0u
/* Hardware handles the TX mesageID field */
#define USBPD_AGNOSTIC_phase10_MSG_ID_EN 0u
/* Keep specific register bits or use their default to reduce gate count */
#define USBPD_AGNOSTIC_phase10_KEEP_REG_BIT 1u
/* High speed filter enabled */
#define USBPD_AGNOSTIC_phase10_HS_CLK_FILT_EN 1u
/* Extended data message function enabled */
#define USBPD_AGNOSTIC_phase10_EXT_DATA_MSG_EN 1u
/* RPRD function enabled */
#define USBPD_AGNOSTIC_phase10_RPRD_EN  1u
/* Swap function enabled */
#define USBPD_AGNOSTIC_phase10_SWAP_EN  0u
/* HPD function enabled */
#define USBPD_AGNOSTIC_phase10_HPD_EN   0u
/* Fault GPIO logic enabled */
#define USBPD_AGNOSTIC_phase10_FAULT_GPIO_EN 0u
/* Extra Fault GPIO logic enabled */
#define USBPD_AGNOSTIC_phase10_FAULT_GPIO_EN_EXTR 1u
/* CC1 Interrupt enabled */
#define USBPD_AGNOSTIC_phase10_CC1_INTR_EN 1u
/* CC2 Interrupt enabled */
#define USBPD_AGNOSTIC_phase10_CC2_INTR_EN 1u
/* VCMP UP Interrupt enabled */
#define USBPD_AGNOSTIC_phase10_VCMP_UP_INTR_EN 1u
/* VCMP DN Interrupt enabled */
#define USBPD_AGNOSTIC_phase10_VCMP_DN_INTR_EN 1u
/* VCMP LA Interrupt enabled */
#define USBPD_AGNOSTIC_phase10_VCMP_LA_INTR_EN 1u
/* GPIO DDFT enabled */
#define USBPD_AGNOSTIC_phase10_GPIO_DDFT_EN 1u
/* GPIO INTR DDFT enabled */
#define USBPD_AGNOSTIC_phase10_GPIO_INTR_DDFT_EN 1u
/* NCELL DDFT enabled */
#define USBPD_AGNOSTIC_phase10_NCELL_DDFT_EN 1u
/* TCPWM Trigger enabled */
#define USBPD_AGNOSTIC_phase10_TCPWM_TRIGGER_EN 1u
/* Interrupt SET function enabled */
#define USBPD_AGNOSTIC_phase10_INTR_SET_EN 1u
/* Interrupt MASKED function enabled */
#define USBPD_AGNOSTIC_phase10_INTR_MASKED_EN 1u
/* Bypass function enable */
#define USBPD_AGNOSTIC_phase10_BYPASS_MODE_EN 1u
/* Enable the following registers: RX_SOP_GOOD_CRC_EN_CTRL, */
#define USBPD_AGNOSTIC_phase10_RX_SOP_CTRL_EN 0u
/* Enabling the HPD RX input selection */
#define USBPD_AGNOSTIC_phase10_HPD_IN_MUX_EN 1u
/* Number of comparator hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_COMP_NUM 7u
/* Number of comparator with trim hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_COMP_TR_NUM 0u
/* Number of USBPD AMUX hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_USB_AMUX_NUM 21u
/* Number of USBPD AMUX NHV hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_USB_AMUX_NHV_NUM 0u
/* Number of USBPD AMUX DENFET hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_USB_AMUX_DENFET_NUM 0u
/* Total number of CLK_FILTER Filter */
#define USBPD_AGNOSTIC_phase10_CLK_FILTER_FILT_NUM 5u
/* Total number of CLK_FILTER 1-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_CLK_FILTER_LOG1 5u
/* Total number of CLK_FILTER 12-bit Lower CFG bits */
#define USBPD_AGNOSTIC_phase10_CLK_FILTER_FILT_NUM_LOG1_12 5u
/* Total number of CLK_FILTER 12-bit Upper CFG bits */
#define USBPD_AGNOSTIC_phase10_CLK_FILTER_FILT_NUM_LOG2_12 0u
/* Total number of CLK_LF Filter */
#define USBPD_AGNOSTIC_phase10_CLK_LF_FILT_NUM 2u
/* Number of RDIV_SHV Hard IP cell */
#define USBPD_AGNOSTIC_phase10_RDIV_NUM 0u
/* Total number of RDIV ADFT CTRL bits */
#define USBPD_AGNOSTIC_phase10_RDIV_NUM_LOG3 0u
/* Number of s8usbpd_det_shv_top hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_DET_SHV_NUM 0u
/* Total number of Det SHV 1-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_DET_SHV_NUM_LOG1 0u
/* Total number of Det SHV two-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_DET_SHV_NUM_LOG2 0u
/* Total number of Det SHV three-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_DET_SHV_NUM_LOG3 0u
/* Number of s8usbpd_shvreg_top Regulator hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_SHVREG_NUM 0u
/* Total number of SHV 1-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_SHVREG_NUM_LOG1 0u
/* Total number of SHV two-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_SHVREG_NUM_LOG2 0u
/* Total number of SHV three-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_SHVREG_NUM_LOG3 0u
/* Number of Error Amplifier hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_EA_NUM   0u
/* Number of LSCSA hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_LSCSA_NUM 0u
/* Number of RefGen hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_REFGEN_NUM 1u
/* Number of Internal/External P-Gate Driver is instantiated */
#define USBPD_AGNOSTIC_phase10_PGDO_NUM 0u
/* Number of Internal/External P-Gate Driver with Pull-Up is instantiated */
#define USBPD_AGNOSTIC_phase10_PGDO_PU_NUM 0u
/* Number of Internal/External P-Gate Driver with Pull-Up is instantiated extra
   Register */
#define USBPD_AGNOSTIC_phase10_PGDO_PU_NUM_EXTR 0u
/* s8usbpd_pgdo_pd_isnk_top is instantiated (0=No, 1=Yes) */
#define USBPD_AGNOSTIC_phase10_PGDO_PD_ISNK_EN 0u
/* Enable higher resolution of the Value for PGDO PD ISNK (0=No, 1=Yes) */
#define USBPD_AGNOSTIC_phase10_PGDO_ISNK_H_RES_EN 0u
/* Number of Discharge hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_DISCHG_NUM 2u
/* Number of Discharge hard IP + Protection Logic is instantiated */
#define USBPD_AGNOSTIC_phase10_DISCHG_PROT_NUM 2u
/* Number of s8usbpd_vconn_sw_shv_small_top */
#define USBPD_AGNOSTIC_phase10_SMALL_VCONN_NUM 0u
/* Total number of Small Vconn two-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_SMALL_VCONN_NUM_LOG2 0u
/* Total number of Small Vconn three-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_SMALL_VCONN_NUM_LOG3 0u
/* Enable two s8usbpd_vconn_sw_1vconn_shv_top */
#define USBPD_AGNOSTIC_phase10_TWO_VCONN_EN 0u
/* ONE_VCONN_EN OR TWO_VCONN_EN */
#define USBPD_AGNOSTIC_phase10_VCONN_EN 0u
/* VCONN 20V enabled? */
#define USBPD_AGNOSTIC_phase10_VCONN20_EN 0u
/* Enable one s8usbpd 300ma_sw_top */
#define USBPD_AGNOSTIC_phase10_FET_300_EN 0u
/* V5V is enabled */
#define USBPD_AGNOSTIC_phase10_V5V_EN   0u
/* Enable s8usbpd_cc_shvt_top */
#define USBPD_AGNOSTIC_phase10_CC_SHVT_EN 1u
/* Enable s8usbpd_cc_shvt_cabl_top */
#define USBPD_AGNOSTIC_phase10_CC_SHVT_CABLE_EN 0u
/* Enable s8usbpd_cc_ufp_nord_top */
#define USBPD_AGNOSTIC_phase10_CC_UFP_NORD_EN 0u
/* Enable s8usbpd_cc_dfp_notxrx_top */
#define USBPD_AGNOSTIC_phase10_CC_DFP_NOTXRX_EN 0u
/* s8usbpd current/voltage reference capable (0=No, 1=Yes) */
#define USBPD_AGNOSTIC_phase10_DPSLP_REF_EN 1u
/* s8usbpd pump capable (0=No, 1=Yes) */
#define USBPD_AGNOSTIC_phase10_CPUMP_EN 0u
/* Number of s8usbpd2 5vpump The V5PUMP_NUM indiates the total s8usbpd2 5vpump
   regardless of the V5PUMP_EN value */
#define USBPD_AGNOSTIC_phase10_V5PUMP_NUM 1u
/* Number of ADC hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_ADC_NUM  1u
/* Number of s8usbpd_chgdet_afc_top/s8pds_chgdet_afc_top */
#define USBPD_AGNOSTIC_phase10_BCH_DET_NUM 1u
/* Total number of Battery Charger two-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_BCH_DET_NUM_LOG2 2u
/* Total number of Battery Charger three-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_BCH_DET_NUM_LOG3 3u
/* Number of s8usbpd_chgdet_top */
#define USBPD_AGNOSTIC_phase10_CHGDET_NUM 0u
/* Total number of Charger 1-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_CHGDET_NUM_LOG1 0u
/* Total number of Charger two-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_CHGDET_NUM_LOG2 0u
/* Total number of Charger three-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_CHGDET_NUM_LOG3 0u
/* Number of Internal/External N-Gate Driver is instantiated */
#define USBPD_AGNOSTIC_phase10_NGDO_NUM 0u
/* Number of SBU Switch is instantiated */
#define USBPD_AGNOSTIC_phase10_SBU_NUM  0u
/* Number of SBU Switches instantiated */
#define USBPD_AGNOSTIC_phase10_SBU20_NUM 0u
/* Total number of SBU20 two-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_SBU20_NUM_LOG2 0u
/* Number of DPDM Switches instantiated */
#define USBPD_AGNOSTIC_phase10_DPDM_NUM 0u
/* CCG6 or CCG6DF DPDM Enabled */
#define USBPD_AGNOSTIC_phase10_DPDM_CCG6_EN 0u
/* Number of CSA hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_CSA_NUM  0u
/* Total number of CSA one-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_CSA_NUM_LOG1 0u
/* Total number of CSA two-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_CSA_NUM_LOG2 0u
/* Total number of CSA three-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_CSA_NUM_LOG3 0u
/* One CSA SCP hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_CSA_SCP_EN 0u
/* One CSA RCP hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_CSA_RCP_EN 0u
/* CSA SCP or CSA RCP hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_CSA_SCP_RCP_EN 0u
/* VSYS Enabled */
#define USBPD_AGNOSTIC_phase10_VSYS_EN  0u
/* Number of s8usbpd_20vreg_top Regulator hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_VREG20_NUM 0u
/* Total number of VREG20 one-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_VREG20_NUM_LOG1 0u
/* Total number of VREG20 two-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_VREG20_NUM_LOG2 0u
/* Total number of VREG20 three-bit CFG bits */
#define USBPD_AGNOSTIC_phase10_VREG20_NUM_LOG3 0u
/* First SHV regulator instatiated */
#define USBPD_AGNOSTIC_phase10_REGULATOR1_EN 0u
/* Second SHV regulator instatiated */
#define USBPD_AGNOSTIC_phase10_REGULATOR2_EN 0u
/* Third SHV regulator instatiated */
#define USBPD_AGNOSTIC_phase10_REGULATOR3_EN 0u
/* Forth SHV regulator instatiated */
#define USBPD_AGNOSTIC_phase10_REGULATOR4_EN 0u
/* First 20V regulator instatiated */
#define USBPD_AGNOSTIC_phase10_REGULATOR20_1_EN 0u
/* Second 20V regulator instatiated */
#define USBPD_AGNOSTIC_phase10_REGULATOR20_2_EN 0u
/* Third 20V regulator instatiated */
#define USBPD_AGNOSTIC_phase10_REGULATOR20_3_EN 0u
/* Forth 20V regulator instatiated */
#define USBPD_AGNOSTIC_phase10_REGULATOR20_4_EN 0u
/* Regulator control is enabled */
#define USBPD_AGNOSTIC_phase10_REG_CONTROL_EN 0u
/* Enable CCG7D_EN related registers */
#define USBPD_AGNOSTIC_phase10_CCG7D_EN 0u
/* Enable CCG7D_EN related registers for Instance 0 only */
#define USBPD_AGNOSTIC_phase10_CCG7D_EN_INST_ZERO 0u
/* Enable Battery to Ground protection */
#define USBPD_AGNOSTIC_phase10_BAT2GND_EN 0u
/* Enable function/related registers of PD Buck Boost Controller/next-gen products */
#define USBPD_AGNOSTIC_phase10_PDBBC_EN 0u
/* Enable IBUS transition contol logic */
#define USBPD_AGNOSTIC_phase10_IBTR_EN  1u
/* PASC or CCG7D Enable */
#define USBPD_AGNOSTIC_phase10_PASC_CCG7D_EN 0u
/* PASC or CCG6DF or CCG7D Enable */
#define USBPD_AGNOSTIC_phase10_PASC_CCG6DF_CCG7D_EN 0u
/* CCG6 or CCG7D Enable */
#define USBPD_AGNOSTIC_phase10_CCG6_CCG7D_EN 0u
/* Enable PMG1S3_EN related registers */
#define USBPD_AGNOSTIC_phase10_PMG1S3_EN 0u
/* Enable CCG6DF or PMG1S3 related registers */
#define USBPD_AGNOSTIC_phase10_CCG6DF_PMG1S3_EN 0u
/* Enable Digital Flip Mux */
#define USBPD_AGNOSTIC_phase10_FMX_EN   0u
/* Enable PMG1S3_EN related registers */
#define USBPD_AGNOSTIC_phase10_ACG1F_PMG1S3_EN 0u
/* Enable RAMBIST Muxing Logic */
#define USBPD_AGNOSTIC_phase10_RBM_EN   0u
/* Enable Scan Bypass Logic */
#define USBPD_AGNOSTIC_phase10_SCBYP_EN 0u
/* Number of New SBU Mux (s8usbpdv2_pmg1s3 _sbu_sw_top) and related Registers */
#define USBPD_AGNOSTIC_phase10_SBU_NEW_NUM 0u
/* Enable CCG7S_EN related trim registers */
#define USBPD_AGNOSTIC_phase10_CCG7D_CCG7S_EN 0u
/* Enable CCG7S_EN related registers */
#define USBPD_AGNOSTIC_phase10_CCG7S_EN 0u
/* Enable extended controls for 40VREGLD */
#define USBPD_AGNOSTIC_phase10_BB40VREGLD_EN 0u
/* Enable controls for BB_CC_SHVT */
#define USBPD_AGNOSTIC_phase10_BB_CC_SHVT_EN 0u
/* Enable controls for ASYNC PWM edge control */
#define USBPD_AGNOSTIC_phase10_BB_ASYNC_NEW_EN 0u
/* Enable EA's HS Switch on VBUS */
#define USBPD_AGNOSTIC_phase10_HSSW_EN  0u
/* Enable implementation of S8PDBB_DPSLP_REF. Requires DPSLP_REF_EN to be 1 */
#define USBPD_AGNOSTIC_phase10_BB_DPSLP_REF 1u
/* Enable PAG2S_EN related registers */
#define USBPD_AGNOSTIC_phase10_PAG2S_EN 1u
/* Enable PASC2_EN related registers */
#define USBPD_AGNOSTIC_phase10_PASC2_EN 1u
/* PASC or PASC2 Enable */
#define USBPD_AGNOSTIC_phase10_PASC_PASC2_EN 1u
/* PASC or CCG7D Enable */
#define USBPD_AGNOSTIC_phase10_PASC_PASC2_CCG7D_EN 1u
/* Number of S8PDSV2 RDIV_R_SHV Hard IP cell */
#define USBPD_AGNOSTIC_phase10_RDIV_R_CLIP_NUM 2u
/* Enable controls for CC_40SHVT */
#define USBPD_AGNOSTIC_phase10_CC_40SHVT_EN 1u
/* Enable controls for 40DISCHG_SHV */
#define USBPD_AGNOSTIC_phase10_DISCHG40_EN 1u
/* Enable controls for 30NGDO */
#define USBPD_AGNOSTIC_phase10_NGDO30_EN 1u
/* Enable controls for V2_LSCSA */
#define USBPD_AGNOSTIC_phase10_V2_LSCSA_EN 1u
/* Enable PTDRV_EN related registers */
#define USBPD_AGNOSTIC_phase10_PTDRV_EN 1u
/* Enable controls for V2_SRGDRV */
#define USBPD_AGNOSTIC_phase10_V2_SRGDRV 1u
/* Enable controls for V2_SRSENSE */
#define USBPD_AGNOSTIC_phase10_V2_SRSENSE 1u
/* VCONN 40V enabled? */
#define USBPD_AGNOSTIC_phase10_VCONN40_EN 1u
/* Enable controls for V2_PWM */
#define USBPD_AGNOSTIC_phase10_V2_PWM   1u
/* Enable controls for V2_CHGDET */
#define USBPD_AGNOSTIC_phase10_V2_CHGDET 1u
/* Enable controls for V2_40VREG */
#define USBPD_AGNOSTIC_phase10_V2_40VREG 1u
/* Enable controls for V2_EA */
#define USBPD_AGNOSTIC_phase10_V2_PDS_EA 1u
/* Switch controls for VCONN20 & VCONN40 */
#define USBPD_AGNOSTIC_phase10_VCONN20_VCONN40_EN 1u
/* Enable controls for V2_BG ref */
#define USBPD_AGNOSTIC_phase10_V2_BG_REF 1u
/* Enable controls for VBTR EPR */
#define USBPD_AGNOSTIC_phase10_EPR_EN   1u
/* Enable CCG7D_EN related registers for Instance 0 only and PASC2 */
#define USBPD_AGNOSTIC_phase10_CCG7D_EN_INST_ZERO_PASC2 1u
/* Enable CCG7S_EN & PAG2S related trim registers */
#define USBPD_AGNOSTIC_phase10_CCG7D_CCG7S_PASC2_EN 1u
/* One CSA SCP hard IP or V2_LSCSA is instantiated */
#define USBPD_AGNOSTIC_phase10_CSA_SCP_V2_LSCSA_EN 1u
/* CSA SCP or CSA RCP or V2_LSCSA hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_CSA_SCP_RCP_V2_LSCSA_EN 1u
/* Round Robin ADC logic and Hard IPs are instantiated */
#define USBPD_AGNOSTIC_phase10_RNDRBN_ADC_EN 1u
/* Number of USBPD HIP parameters to be measured including Die temparature. Valid
   if RNDRBN_ADC_EN is 1 */
#define USBPD_AGNOSTIC_phase10_USB_R_CHAN_NUM 4u
/* Number of USBPD Round Robin AMUX hard IP is instantiated. It will be 2 less
   than USB_R_CHAN_NUM due to Die temparature and last parameter not needing
   AMUX. Valid if RNDRBN_ADC_EN is 1 */
#define USBPD_AGNOSTIC_phase10_USB_R_AMUX_NUM 2u
/* Enable Over Temparature Protection logic */
#define USBPD_AGNOSTIC_phase10_EN_OTP   1u
/* Number of RC filters */
#define USBPD_AGNOSTIC_phase10_RC_FILT_NUM 2u
/* Enable DISCHG LOW_R for VBUS */
#define USBPD_AGNOSTIC_phase10_DISCHG_LOW_R_VBUS 1u
/* Enable CMG2 related registers */
#define USBPD_AGNOSTIC_phase10_CMG2_EN  0u
/* CSA hard IP VBUS number: 2:0 For CSA1 VBUS Number 5:3 For CSA2 VBUS Number 8:6
   For CSA3 VBUS Number 11:9 For CSA4 VBUS Number i.e:
   {CSA4[3:0],CSA3[3:0],CSA2[2:0],CSA1[2:0]} */
#define USBPD_AGNOSTIC_phase10_CSA_VBUS_NUM 0u
/* NGDO hard IP VBUS number: 2:0 For NGDO1 VBUS Number 5:3 For NGDO2 VBUS Number
   8:6 For NGDO3 VBUS Number 11:9 For NGDO4 VBUS Number i.e:
   {NGDO4[3:0],NGDO3[3:0],NGDO2[2:0],NGDO1[2:0]} */
#define USBPD_AGNOSTIC_phase10_NGDO_VBUS_NUM 0u
/* VREG hard IP VBUS number: 2:0 For VREG1 VBUS Number 5:3 For VREG2 VBUS Number
   8:6 For VREG3 VBUS Number 11:9 For VREG4 VBUS Number i.e:
   {VREG4[3:0],VREG3[3:0],VREG2[2:0],VREG1[2:0]} */
#define USBPD_AGNOSTIC_phase10_VREG20_VBUS_NUM 0u
/* SHVREG hard IP VBUS number: 2:0 For SHVREG1 VBUS Number 5:3 For SHVREG2 VBUS
   Number 8:6 For SHVREG3 VBUS Number 11:9 For SHVREG4 VBUS Number i.e:
   {SHVREG4[3:0],SHVREG3[3:0],SHVREG2[2:0],SHVREG1[2:0]} */
#define USBPD_AGNOSTIC_phase10_SHVREG_VBUS_NUM 0u
/* EA hard IP VBUS number: 2:0 For EA1 VBUS Number 5:3 For EA2 VBUS Number 8:6 For
   EA3 VBUS Number 11:9 For EA4 VBUS Number i.e:
   {EA4[3:0],EA3[3:0],EA2[2:0],EA1[2:0]} */
#define USBPD_AGNOSTIC_phase10_EA_VBUS_NUM 0u
/* VBUS_IEC hard IP VBUS number: 2:0 For VBUS_IEC1 VBUS Number 5:3 For VBUS_IEC2
   VBUS Number 8:6 For VBUS_IEC3 VBUS Number 11:9 For VBUS_IEC4 VBUS Number
   14:12 For VBUS_IEC5 VBUS Number 17:15 For VBUS_IEC6 VBUS Number 20:18 For
   VBUS_IEC7 VBUS Number 23:21 For VBUS_IEC8 VBUS Number i.e:
   {VBUS_IEC8[3:0],VBUS_IEC7[3:0],VBUS_IEC6[3:0],VBUS_IEC5[3:0],VBUS_IEC4[3:0],VBUS_IEC3[3:0],VBUS_IEC2[2:0],VBUS_IEC1[2:0]} */
#define USBPD_AGNOSTIC_phase10_VBUS_IEC_VBUS_NUM 0u
/* DISCHARGE hard IP VBUS number: 2:0 For DISCHG1 VBUS Number 5:3 For DISCHG2 VBUS
   Number 8:6 For DISCHG3 VBUS Number 11:9 For DISCHG4 VBUS Number i.e:
   {DISCHG4[3:0],DISCHG3[3:0],DISCHG2[2:0],DISCHG1[2:0]} */
#define USBPD_AGNOSTIC_phase10_DISCHG_VBUS_NUM 0u
/* CLAMP hard IP VBUS number: 2:0 For CLAMP1 VBUS Number 5:3 For CLAMP2 VBUS
   Number 8:6 For CLAMP3 VBUS Number 11:9 For CLAMP4 VBUS Number i.e:
   {CLAMP4[3:0],CLAMP3[3:0],CLAMP2[2:0],CLAMP1[2:0]} */
#define USBPD_AGNOSTIC_phase10_CLAMP_VBUS_NUM 0u
/* PGDO Pull-up hard IP VBUS number: 2:0 For PGDO_PU1 VBUS Number 5:3 For PGDO_PU2
   VBUS Number 8:6 For PGDO_PU3 VBUS Number 11:9 For PGDO_PU4 VBUS Number 14:12
   For PGDO_PU5 VBUS Number 17:15 For PGDO_PU6 VBUS Number 20:18 For PGDO_PU7
   VBUS Number 23:21 For PGDO_PU8 VBUS Number i.e:
   {PGDO_PU8[3:0],PGDO_PU7[3:0],PGDO_PU6[3:0],PGDO_PU5[3:0],PGDO_PU4[3:0],PGDO_PU3[3:0],PGDO_PU2[2:0],PGDO_PU1[2:0]} */
#define USBPD_AGNOSTIC_phase10_PGDO_PU_VBUS_NUM 0u
/* PGDO hard IP VBUS number: 2:0 For PGDO1 VBUS Number 5:3 For PGDO2 VBUS Number
   8:6 For PGDO3 VBUS Number 11:9 For PGDO4 VBUS Number 14:12 For PGDO5 VBUS
   Number 17:15 For PGDO6 VBUS Number 20:18 For PGDO7 VBUS Number 23:21 For
   PGDO8 VBUS Number i.e:
   {PGDO8[3:0],PGDO7[3:0],PGDO6[3:0],PGDO5[3:0],PGDO4[3:0],PGDO3[3:0],PGDO2[2:0],PGDO1[2:0]} */
#define USBPD_AGNOSTIC_phase10_PGDO_VBUS_NUM 0u
/* RDIV_SHV hard IP VBUS number: 2:0 For RDIV_SHV1 VBUS Number 5:3 For RDIV_SHV2
   VBUS Number 8:6 For RDIV_SHV3 VBUS Number 11:9 For RDIV_SHV4 VBUS Number
   14:12 For RDIV_SHV5 VBUS Number 17:15 For RDIV_SHV6 VBUS Number 20:18 For
   RDIV_SHV7 VBUS Number 23:21 For RDIV_SHV8 VBUS Number i.e:
   {RDIV_SHV8[3:0],RDIV_SHV7[3:0],RDIV_SHV6[3:0],RDIV_SHV5[3:0],RDIV_SHV4[3:0],RDIV_SHV3[3:0],RDIV_SHV2[2:0],RDIV_SHV1[2:0]} */
#define USBPD_AGNOSTIC_phase10_RDIV_VBUS_NUM 0u
/* RDIV_R_SHV hard IP VBUS number: 2:0 For RDIV_R_SHV1 VBUS Number 5:3 For
   RDIV_R_SHV2 VBUS Number 8:6 For RDIV_R_SHV3 VBUS Number 11:9 For RDIV_R_SHV4
   VBUS Number 14:12 For RDIV_R_SHV5 VBUS Number 17:15 For RDIV_R_SHV6 VBUS
   Number 20:18 For RDIV_R_SHV7 VBUS Number 23:21 For RDIV_R_SHV8 VBUS Number
   i.e:
   {RDIV_R_SHV8[3:0],RDIV_R_SHV7[3:0],RDIV_R_SHV6[3:0],RDIV_R_SHV5[3:0],RDIV_R_SHV4[3:0],RDIV_R_SHV3[3:0],RDIV_R_SHV2[2:0],RDIV_R_SHV1[2:0]} */
#define USBPD_AGNOSTIC_phase10_RDIV_R_VBUS_NUM 0u
/* DET_SHV hard IP VBUS number: 2:0 For DET_SHV1 VBUS Number 5:3 For DET_SHV2 VBUS
   Number 8:6 For DET_SHV3 VBUS Number 11:9 For DET_SHV4 VBUS Number 14:12 For
   DET_SHV5 VBUS Number 17:15 For DET_SHV6 VBUS Number 20:18 For DET_SHV7 VBUS
   Number 23:21 For DET_SHV8 VBUS Number i.e:
   {DET_SHV8[3:0],DET_SHV7[3:0],DET_SHV6[3:0],DET_SHV5[3:0],DET_SHV4[3:0],DET_SHV3[3:0],DET_SHV2[2:0],DET_SHV1[2:0]} */
#define USBPD_AGNOSTIC_phase10_DET_SHV_VBUS_NUM 0u
/* act isolate enabled */
#define USBPD_AGNOSTIC_phase10_ACT_ISOLATE_EN 0u
/* TCPWM DDFT enabled */
#define USBPD_AGNOSTIC_phase10_TCPWM_DDFT_EN 0u
/* Number of RDIV_R_SHV Hard IP cell */
#define USBPD_AGNOSTIC_phase10_RDIV_R_NUM 0u
/* Number of VBUS IEC hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_VBUS_IEC_NUM 0u
/* The P-Gate Drivers are internal */
#define USBPD_AGNOSTIC_phase10_INTR_PGDO_EN 0u
/* Number of HBM CLamp hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_HBM_CLAMP_NUM 0u
/* Number of Ground pads for Discharge hard IP is instantiated */
#define USBPD_AGNOSTIC_phase10_DISCHG_GND_NUM 0u
/* Enable one s8usbpd_vconn_sw_1vconn_shv_top */
#define USBPD_AGNOSTIC_phase10_ONE_VCONN_EN 0u
/* Use the Scan port of s8usbpd_cc_shvt_cabl_top */
#define USBPD_AGNOSTIC_phase10_USE_CC_SHVT_CABLE_SCAN_PORT 0u
/* s8usbpd2 5vpump capable (0=no, 1=yes) */
#define USBPD_AGNOSTIC_phase10_V5PUMP_EN 0u
/* IECs is used for charger detects hard IP [1]: For First Charger [2]: For Second
   Charger [3]: For Third Charger [4]: For Forth Charger */
#define USBPD_AGNOSTIC_phase10_CHGDET_IEC_EN 0u
/* The N-Gate Drivers are internal */
#define USBPD_AGNOSTIC_phase10_INTR_NGDO_EN 0u
/* Instantiate s8usbpd_sbu_sw_top */
#define USBPD_AGNOSTIC_phase10_SBU_SW_TOP_EN 0u
/* IECs is used for SBU ports hard IP [1]: For SBU switch#1 (1/2) [2]: For SBU
   switch#2 (3/4) [3]: For SBU switch#3 (5/6) [4]: For SBU switch#4 (7/8) */
#define USBPD_AGNOSTIC_phase10_SBU_IEC_EN 0u
/* Total number of s8_esd_res250only cell for each of pad_inp/pad_inn of
   s8usbpdv2_csa_top */
#define USBPD_AGNOSTIC_phase10_CSA_ESD_NUM 0u

#endif /* _PAG2S_CONFIG_H_ */


/* [] END OF FILE */
