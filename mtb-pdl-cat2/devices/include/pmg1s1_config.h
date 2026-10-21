/***************************************************************************//**
* \file pmg1s1_config.h
*
* \brief
* PMG1S1 device configuration header
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

#ifndef _PMG1S1_CONFIG_H_
#define _PMG1S1_CONFIG_H_

/* Clock Connections */
typedef enum
{
    PCLK_SCB0_CLOCK                 = 0x0000u,  /* scb[0].clock */
    PCLK_SCB1_CLOCK                 = 0x0001u,  /* scb[1].clock */
    PCLK_SCB2_CLOCK                 = 0x0002u,  /* scb[2].clock */
    PCLK_SCB3_CLOCK                 = 0x0003u,  /* scb[3].clock */
    PCLK_TCPWM_CLOCKS0              = 0x0004u,  /* tcpwm.clocks[0] */
    PCLK_TCPWM_CLOCKS1              = 0x0005u,  /* tcpwm.clocks[1] */
    PCLK_USBPD0_CLOCK_RX            = 0x0006u,  /* usbpd[0].clock_rx */
    PCLK_USBPD0_CLOCK_TX            = 0x0007u,  /* usbpd[0].clock_tx */
    PCLK_USBPD0_CLOCK_SAR           = 0x0008u,  /* usbpd[0].clock_sar */
    PCLK_USBPD0_CLOCK_SWAP          = 0x0009u,  /* usbpd[0].clock_swap */
    PCLK_USBPD0_CLOCK_FILTER1       = 0x000Au,  /* usbpd[0].clock_filter1 */
    PCLK_USBPD0_CLOCK_FILTER2       = 0x000Bu,  /* usbpd[0].clock_filter2 */
    PCLK_USBPD0_CLOCK_REFGEN        = 0x000Cu,  /* usbpd[0].clock_refgen */
    PCLK_USBPD0_CLOCK_BCH_DET       = 0x000Du,  /* usbpd[0].clock_bch_det */
    PCLK_USBPD0_CLOCK_ISNK          = 0x000Eu   /* usbpd[0].clock_isnk */
} en_clk_dst_t;

/* Include IP definitions */
#include "ip/cyip_sflash_256.h"
#include "ip/cyip_peri.h"
#include "ip/cyip_hsiom.h"
#include "ip/cyip_srsslt.h"
#include "ip/cyip_gpio.h"
#include "ip/cyip_scb_v2.h"
#include "ip/cyip_tcpwm_v2.h"
#include "ip/cyip_crypto_v2.h"
#include "ip/cyip_cpuss_v3.h"
#include "ip/cyip_dmac_v3.h"
#include "ip/cyip_spcif_v3.h"

/* Parameter Defines */
/* CPUSS version (2 or 3) */
#define CPUSS_CPUSS_VER                 3u
/* CM0 present or CM0+ present (1=CM0, 0=CM0+) */
#define CPUSS_CM0_PRESENT               1u
/* CM0+ Memory protection unit present/not (0=not present, 8=present). */
#define CPUSS_CM0_MPU                   0u
/* MTB SRAM size in kilo bytes (0, 1, 2, or 4). Must be '0' for CM0, Non zero
   value only for CM0+. */
#define CPUSS_MTB_SRAM_SIZE             0u
/* CM0+ Micro Trace Buffer (MTB) Present or not (Must be '0' for CM0) */
#define CPUSS_MTB_PRESENT               0u
/* Maximum speed that system will run at (0=48MHz, 1=16MHz) */
#define CPUSS_MAX_16_MHZ                0u
/* System RAM parition 0, size in kilobytes */
#define CPUSS_SRAM_SIZE                 12u
/* System RAM parition 1, size in kilobytes */
#define CPUSS_SRAM1_SIZE                0u
/* Boot ROM size in kilobytes */
#define CPUSS_ROM_SIZE                  16u
/* Product has ROM available for system usage (1) or not (0) */
#define CPUSS_SYSTEM_ROM                1u
/* Boot ROM available (1) or all classified as System Rom (0) */
#define CPUSS_ROMC_BOOT_ROM_PRESENT     1u
/* Boot ROM partition size */
#define CPUSS_BOOT_ROM_SIZE             8u
/* Number of external slave ports on System Interconnect */
#define CPUSS_SL_NR                     1u
/* Flash memory present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_FLASHC_PRESENT            1u
/* Flash size in kilobytes */
#define CPUSS_FLASH_SIZE                128u
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
#define CPUSS_INT_NR                    18u
/* Number of wakeup interrupt controller lines (always includes NMI, RXEV, so
   min=2) */
#define CPUSS_CM0_WICLINES              15u
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
#define CPUSS_BIST_FULL                 0u
/* Number of external SRAMs connected to the CPUSS BIST controller */
#define CPUSS_BIST_EXT_SRAM_NR          8u
/* Number of SRAMs connected to the CPUSS BIST controller (BIST_EXT_SRAM_NR+4) */
#define CPUSS_BIST_SRAM_NR              12u
/* CoreSight Part Identification Number */
#define CPUSS_JEPID                     52u
/* CoreSight Part Identification Number */
#define CPUSS_JEPCONTINUATION           0u
/* CoreSight Part Identification Number */
#define CPUSS_PARTNUMBER                186u
/* External Master Present */
#define CPUSS_EXT_MS_PRESENT            0u
/* RAM controller 1 present (0=No, 1=Yes) */
#define CPUSS_RAMC1_PRESENT             0u
/* Enforce Secure Access restrictions (0=No, 1=Yes) */
#define CPUSS_SECURE_ACCESS             1u
/* SWD MultiDrop Present */
#define CPUSS_SWD_MULTIDROP             0u
/* Enable SROM DMA Access */
#define CPUSS_SROM_ACCESS_PRESENT       0u
/* Select Cell VT type. Drives the type of standard cell to be used in MXTK.
   Depends on the product */
#define CPUSS_CELL_VT_TYPE              0u
/* MTB SRAM Base adress - Value should be computed from Memory Map */
#define CPUSS_CM0PMTB_MTB_SRAMBASE      0u
/* DW/DMA Controller present (0=No, 1=Yes) */
#define CPUSS_CPUMEMSS_DMAC_PRESENT     0u
/* Number of DMA Channels */
#define CPUSS_DMAC_CH_NR                0u
/* Width in bits of a DMA channel number (derived from CH_NR as
   roundup(log2(CH_NR))) */
#define CPUSS_DMAC_CH_ADDR_WIDTH        0u
/* Product uses SRSS-Lite (1) or SRSSv2 (0) - used to determine NVL parameters */
#define CPUSS_SPCIF_SRSSLT              1u
/* Use 2X?? Option for FLASH to allow parallel code execution and programming of
   FLASH */
#define CPUSS_SPCIF_FLASH_PARALLEL_PGM_EN 0u
/* Flash type is FMLT or S8FS */
#define CPUSS_SPCIF_FMLT_OR_S8FS        1u
/* Product uses FLASH-Lite (1) or regular FLASH (0) */
#define CPUSS_SPCIF_FMLT                0u
/* Using regular flash (=1-FMLT) */
#define CPUSS_SPCIF_FM                  0u
/* Total Flash size in multiples of 256 bytes (0=1x256, 1=2x256, ...) */
#define CPUSS_SPCIF_FLASH_SIZE          511u
/* The Flash read word width in bits (32, 64 or 128) */
#define CPUSS_SPCIF_FLASH_READ_WIDTH    64u
/* Total Supervisory Flash size in multiples of 256 bytes (0=1x256, 1=2x256, ...) */
#define CPUSS_SPCIF_SFLASH_SIZE         7u
/* Flash program/erase page size (0=64, 1=128 or 3=256 bytes) */
#define CPUSS_SPCIF_FLASH_PAGE_SIZE     3u
/* Number of Flash macros used in the device (0, 1 or 2) */
#define CPUSS_SPCIF_FLASH_MACROS        1u
/* Number of Flash macros minus 1 */
#define CPUSS_SPCIF_FLASH_MACROS_MINUS1 0u
/* Flash macro #1 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_1       0u
/* Flash macro #2 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_2       0u
/* Flash macro #3 (the second) present (0=No, 1=Yes) */
#define CPUSS_SPCIF_FLASH_MACRO_3       0u
/* SPCIF Timer clock is synchronous (1) or asynchronous (0) to clk_sys */
#define CPUSS_SPCIF_SYNCHRONOUS         1u
/* NVLatches present (0=No, 1=Yes) */
#define CPUSS_SPCIF_NVLATCH             0u
/* NVLatches size in bytes (default=8) */
#define CPUSS_SPCIF_NVLATCH_SIZE        8u
/* HOBTO-M ULL65 SRAM/SROM required */
#define CPUSS_SPCIF_ULL65               0u
/* Flash memory present or not (1=Flash present, 0=Flash not present) */
#define CPUSS_SPCIF_FLASHC_PRESENT      1u
/* Flash type (0=FM, 1=FMLT, 2=FS, 3=FSLT) */
#define CPUSS_SPCIF_FLASH_TYPE          3u
/* AES cipher support (0 = no support, 1 = support */
#define CRYPTO_AES                      0u
/* Pseudo random number generation support (0 = no support, 1 = support) */
#define CRYPTO_PR                       0u
/* True random number generation support (0 = no support, 1 = support) */
#define CRYPTO_TR                       1u
/* SHA hash support (0 = no support, 1 = support) */
#define CRYPTO_SHA                      0u
/* Cyclic Redundancy Check support (0 = no support, 1 = support) */
#define CRYPTO_CRC                      0u
/* Source Pointer 0 */
#define CRYPTO_SRC_CTL0_PRESENT         0u
/* Source Pointer 1 */
#define CRYPTO_SRC_CTL1_PRESENT         0u
/* Destination Pointer 0 */
#define CRYPTO_DST_CTL0_PRESENT         0u
/* Destination Pointer 1 */
#define CRYPTO_DST_CTL1_PRESENT         0u
/* Number of 32-bit words in the memory buffer (from the set [64, 128, 256, 512],
   to allow for a 256 B, 512 B, 1 kB, and 2 kB memory buffer) */
#define CRYPTO_MEM_SIZE                 64u
/* Memory address width in bytes */
#define CRYPTO_MEM_B_ADDR_WIDTH         16u
/* Memory address width in words */
#define CRYPTO_MEM_W_ADDR_WIDTH         16u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define CRYPTO_SPARE_EN                 1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define CRYPTO_SPARE_STDLIB_CFG         2u
/* IOSS PHASE */
#define IOSS_IOSS_PHASE                 4u
/* Route REFGEN vinref & voutref to AMUX bus when set */
#define IOSS_SIO_REF_HOOKUP             0u
/* Use 1.8V signaling on XRES (Xres4 cell only) */
#define IOSS_USE_1P8V_SIGNALING_XRES4   0u
/* Number of ports in device */
#define IOSS_GPIO_GPIO_PORT_NR          6u
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
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO7 0u
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
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_IO7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_IO7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_OVT 1u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_IO7 0u
/* Control register to improve IO testing */
#define IOSS_GPIO_IO_TEST_CTL           1u
/* Is there a pump in IOSS ? (same as GLOBAL.HAS_PUMP_IN_IOSS) */
#define IOSS_HSIOM_PUMP                 0u
/* Number of AMUX splitter cells */
#define IOSS_HSIOM_AMUX_SPLIT_NR        0u
/* Number of HSIOM ports in device (same as GPIO.GPIO_PRT_NR) */
#define IOSS_HSIOM_HSIOM_PORT_NR        6u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR1_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR4_HSIOM_PRT_IO7 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO2 0u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO3 0u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR5_HSIOM_PRT_IO7 0u
/* Number of PRGIO instances (in 8b ports) */
#define IOSS_PRGIO_PRGIO_NR             0u
/* Number of programmable clocks (outputs) */
#define PERI_PCLK_CLOCK_NR              15u
/* Number of 8.0 dividers */
#define PERI_PCLK_DIV_8_NR              6u
/* Number of 16.0 dividers */
#define PERI_PCLK_DIV_16_NR             4u
/* Number of 16.5 (fractional) dividers */
#define PERI_PCLK_DIV_16_5_NR           4u
/* Number of 24.5 (fractional) dividers */
#define PERI_PCLK_DIV_24_5_NR           0u
/* Divider number width: max(1,roundup(log2(max(DIV_*_NR))) */
#define PERI_PCLK_DIV_ADDR_WIDTH        3u
/* Trigger module present (0=No, 1=Yes) */
#define PERI_TR                         0u
/* Number of trigger groups */
#define PERI_TR_GROUP_NR                0u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB0_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB0_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB0_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB0_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB0_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB0_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB0_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB0_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB0_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB0_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB0_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB0_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB0_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB0_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB0_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB0_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB0_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB0_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB0_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB0_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB0_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB0_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB0_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB0_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB0_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB0_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB0_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB0_SPARE_STDLIB_CFG           2u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB1_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB1_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB1_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB1_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB1_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB1_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB1_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB1_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB1_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB1_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB1_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB1_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB1_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB1_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB1_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB1_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB1_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB1_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB1_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB1_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB1_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB1_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB1_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB1_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB1_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB1_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB1_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB1_SPARE_STDLIB_CFG           2u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB2_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB2_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB2_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB2_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB2_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB2_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB2_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB2_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB2_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB2_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB2_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB2_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB2_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB2_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB2_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB2_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB2_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB2_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB2_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB2_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB2_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB2_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB2_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB2_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB2_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB2_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB2_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB2_SPARE_STDLIB_CFG           2u
/* Externally Clocked capable? (0=No,1=Yes) */
#define SCB3_EC                         1u
/* I2C Glitch filters present (0=No, 1=Yes) */
#define SCB3_GLITCH                     1u
/* I2C capable? (0=No,1=Yes) */
#define SCB3_I2C                        1u
/* I2C Externally Clocked capable? (0=No,1=Yes) */
#define SCB3_I2C_EC                     1u
/* I2C Master capable? (0=No, 1=Yes) */
#define SCB3_I2C_M                      1u
/* I2C Slave capable? (0=No, 1=Yes) */
#define SCB3_I2C_S                      1u
/* I2C Master and Slave capable? (0=No, 1=Yes) */
#define SCB3_I2C_M_S                    1u
/* I2C Slave with EC? (0=No, 1=Yes) */
#define SCB3_I2C_S_EC                   1u
/* SPI capable? (0=No,1=Yes) */
#define SCB3_SPI                        1u
/* SPI Externally Clocked capable? (0=No,1=Yes) */
#define SCB3_SPI_EC                     1u
/* SPI Master capable? (0=No, 1=Yes) */
#define SCB3_SPI_M                      1u
/* SPI Slave capable? (0=No, 1=Yes) */
#define SCB3_SPI_S                      1u
/* SPI Slave with EC? (0=No, 1=Yes) */
#define SCB3_SPI_S_EC                   1u
/* UART capable? (0=No,1=Yes) */
#define SCB3_UART                       1u
/* UART Flow control? (0=No, 1=Yes) */
#define SCB3_UART_FLOW                  1u
/* Number of bits to represent a FIFO address */
#define SCB3_FF_DATA_NR_LOG2            4u
/* Number of bits to represent #bytes in FIFO */
#define SCB3_FF_DATA_NR_LOG2_PLUS1      5u
/* Number of words in EZ memory */
#define SCB3_EZ_DATA_NR                 32u
/* Number of bits to represent #bytes in EZ memory */
#define SCB3_EZ_DATA_NR_LOG2            5u
/* Command/response mode capable? (0=No, 1=Yes) */
#define SCB3_CMD_RESP                   1u
/* EZ mode capable? (0=No, 1=Yes) */
#define SCB3_EZ                         1u
/* Is at least one of EZ or CMD_RESP set to 1? (0=No,1=Yes) */
#define SCB3_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (0 = N0, 1= Yes) */
#define SCB3_I2C_S_EZ                   1u
/* SPI slave with EZ mode (0 = N0, 1= Yes) */
#define SCB3_SPI_S_EZ                   1u
/* Support I2C Fast+ 1MBit/Sec speed (0=No, 1=Yes) */
#define SCB3_i2C_FAST_PLUS              1u
/* Set to 1 to add enhancement to tolerate SPI SELECT glitch in SPI slave EC EZ
   and CMDRESP mode (0=No Enhancement) */
#define SCB3_M0S8SCB_VER2_SPI_ENHANCEMENT 1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define SCB3_SPARE_EN                   1u
/* Spare Technology choice 1=scs8ls, 2=scs8hd,3=scs8hv(invalid), others reserved */
#define SCB3_SPARE_STDLIB_CFG           2u
/* Does this product have the 2 byte address encoding for 8B CalPairs ? */
#define SFLASH_CALPAIRS_HAVE_2B_ADDRESS 1u
/* Is this TSG4 ? */
#define SFLASH_IS_TSG4                  0u
/* Is this TSG5-M ? */
#define SFLASH_IS_TSG5M                 0u
/* Is this TSG5-L ? */
#define SFLASH_IS_TSG5L                 0u
/* Does this product have standard SWD placement control ? */
#define SFLASH_STD_SWD                  1u
/* Flash Macro 0 has extra rows */
#define SFLASH_FLASH_M0_XTRA_ROWS       1u
/* Does this product include BLEDMA256_REVC ? */
#define SFLASH_HAS_BLEDMA256_REVC       0u
/* Does this product include CSD (m0s8csd) ? */
#define SFLASH_HAS_CSDV2                0u
/* Does this product include CSD (m0s8csdv2) ? (w/ 2nd CSD) */
#define SFLASH_HAS_CSDV2_2              0u
/* Does this product include CSD (m0s8csd) ? */
#define SFLASH_HAS_CSD                  0u
/* Does this product include SAR (m0s8sar) ? */
#define SFLASH_HAS_SAR                  0u
/* Does the product include BLE (m0s8bless)? */
#define SFLASH_HAS_BLE                  0u
/* Is the Product BLE128 */
#define SFLASH_IS_BLE128                0u
/* Is the device PSoC4AL with Copper? */
#define SFLASH_IS_PSOC4AL_CU            0u
/* Does the product include Atlas PLL (s8atlasana) */
#define SFLASH_HAS_ATLAS_PLL            0u
/* Does this product use SRSSv2 ? */
#define SFLASH_SRSSV2                   0u
/* Does this product use SRSS-Lite ? */
#define SFLASH_SRSSLT                   1u
/* Does this product use 2 FLASH macros or more ? */
#define SFLASH_HAS_2FM                  0u
/* Does this product use 3 FLASH macros or more ? */
#define SFLASH_HAS_3FM                  0u
/* Does this product use 4 FLASH macros or more ? */
#define SFLASH_HAS_4FM                  0u
/* Does this product have 2 CSDs and based on SRSSv2? */
#define SFLASH_CSD2_AND_SRSSV2          0u
/* Remap CSD2 INIT Value out of 8B area */
#define SFLASH_MOVE_CSD2_INIT_VALUE     0u
/* Does this product include PACSS (m0s8pacss) ? */
#define SFLASH_HAS_PACSS                0u
/* SRSSLT will use the NOESD version when set to 1 */
#define SRSSLT_SRSSLT_NOESD             0u
/* Number of bits from WDT_MATCH that are ignore in comparison */
#define SRSSLT_WDT_MATCH_MASK           0u
/* Connect vddio bus to pad_vddd (0) or pad_vccq_or_vddio (1) */
#define SRSSLT_HAS_VDDIO_PAD            1u
/* Number of counters per IP (1..8) */
#define TCPWM_CNT_NR                    2u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define TCPWM_SPARE_EN                  2u
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
#define USBPD_CCG6_EN                   1u
/* USBPD Number of Instances (0=1 instance, 1= 2 instances) */
#define USBPD_AGNOSTIC_phase2_INSTANCE_NUM 0u
/* Spare cell Library selection 1=LS,2=HD,3=HV */
#define USBPD_AGNOSTIC_phase2_SPARE_STDLIB_CFG 2u
/* Spare Cell Enable */
#define USBPD_AGNOSTIC_phase2_SPARE_EN  1u
/* SRAM_EN (1:Yes, 0:No) */
#define USBPD_AGNOSTIC_phase2_SRAM_EN   1u
/* 0: Use TX_HEADER register for GoodCRC Expected Header 1: Use
   RX_EXPECT_GOODCRC_MSG.EXPECTED_HEADER register for GoodCRC Expected Header */
#define USBPD_AGNOSTIC_phase2_NOT_USE_TX_HEADER 1u
/* 0: Use RX_ORDER_SET_CTRL register for TX_SOP Order Set 1: Use TX_SOP_ORDER_SET
   register for TX_SOP Order Set */
#define USBPD_AGNOSTIC_phase2_NOT_USE_RX_ORDER_SET 1u
/* Hardware handles the TX Specification Revsion field */
#define USBPD_AGNOSTIC_phase2_SPEC_REV_EN 0u
/* Hardware handles the TX mesageID field */
#define USBPD_AGNOSTIC_phase2_MSG_ID_EN 0u
/* Keep specific register bits or use their default to reduce gate count */
#define USBPD_AGNOSTIC_phase2_KEEP_REG_BIT 1u
/* High speed filter enabled */
#define USBPD_AGNOSTIC_phase2_HS_CLK_FILT_EN 1u
/* Extended data message function enabled */
#define USBPD_AGNOSTIC_phase2_EXT_DATA_MSG_EN 1u
/* RPRD function enabled */
#define USBPD_AGNOSTIC_phase2_RPRD_EN   1u
/* Swap function enabled */
#define USBPD_AGNOSTIC_phase2_SWAP_EN   1u
/* HPD function enabled */
#define USBPD_AGNOSTIC_phase2_HPD_EN    1u
/* Fault GPIO logic enabled */
#define USBPD_AGNOSTIC_phase2_FAULT_GPIO_EN 0u
/* Extra Fault GPIO logic enabled */
#define USBPD_AGNOSTIC_phase2_FAULT_GPIO_EN_EXTR 1u
/* CC1 Interrupt enabled */
#define USBPD_AGNOSTIC_phase2_CC1_INTR_EN 1u
/* CC2 Interrupt enabled */
#define USBPD_AGNOSTIC_phase2_CC2_INTR_EN 1u
/* VCMP UP Interrupt enabled */
#define USBPD_AGNOSTIC_phase2_VCMP_UP_INTR_EN 1u
/* VCMP DN Interrupt enabled */
#define USBPD_AGNOSTIC_phase2_VCMP_DN_INTR_EN 1u
/* VCMP LA Interrupt enabled */
#define USBPD_AGNOSTIC_phase2_VCMP_LA_INTR_EN 1u
/* GPIO DDFT enabled */
#define USBPD_AGNOSTIC_phase2_GPIO_DDFT_EN 1u
/* GPIO INTR DDFT enabled */
#define USBPD_AGNOSTIC_phase2_GPIO_INTR_DDFT_EN 1u
/* NCELL DDFT enabled */
#define USBPD_AGNOSTIC_phase2_NCELL_DDFT_EN 1u
/* act isolate enabled */
#define USBPD_AGNOSTIC_phase2_ACT_ISOLATE_EN 1u
/* TCPWM DDFT enabled */
#define USBPD_AGNOSTIC_phase2_TCPWM_DDFT_EN 1u
/* TCPWM Trigger enabled */
#define USBPD_AGNOSTIC_phase2_TCPWM_TRIGGER_EN 1u
/* Interrupt SET function enabled */
#define USBPD_AGNOSTIC_phase2_INTR_SET_EN 1u
/* Interrupt MASKED function enabled */
#define USBPD_AGNOSTIC_phase2_INTR_MASKED_EN 1u
/* Bypass function enable */
#define USBPD_AGNOSTIC_phase2_BYPASS_MODE_EN 1u
/* Enable the following registers: RX_SOP_GOOD_CRC_EN_CTRL, */
#define USBPD_AGNOSTIC_phase2_RX_SOP_CTRL_EN 0u
/* Enabling the HPD RX input selection */
#define USBPD_AGNOSTIC_phase2_HPD_IN_MUX_EN 1u
/* Number of comparator hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_COMP_NUM  6u
/* Number of comparator with trim hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_COMP_TR_NUM 0u
/* Number of USBPD AMUX hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_USB_AMUX_NUM 0u
/* Number of USBPD AMUX NHV hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_USB_AMUX_NHV_NUM 5u
/* Number of USBPD AMUX DENFET hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_USB_AMUX_DENFET_NUM 1u
/* Total number of CLK_FILTER Filter */
#define USBPD_AGNOSTIC_phase2_CLK_FILTER_FILT_NUM 2u
/* Total number of CLK_FILTER 1-bit CFG bits */
#define USBPD_AGNOSTIC_phase2_CLK_FILTER_LOG1 2u
/* Total number of CLK_FILTER 12-bit Lower CFG bits */
#define USBPD_AGNOSTIC_phase2_CLK_FILTER_FILT_NUM_LOG1_12 2u
/* Total number of CLK_FILTER 12-bit Upper CFG bits */
#define USBPD_AGNOSTIC_phase2_CLK_FILTER_FILT_NUM_LOG2_12 0u
/* Total number of CLK_LF Filter */
#define USBPD_AGNOSTIC_phase2_CLK_LF_FILT_NUM 2u
/* Number of RDIV_SHV Hard IP cell */
#define USBPD_AGNOSTIC_phase2_RDIV_NUM  0u
/* Total number of RDIV ADFT CTRL bits */
#define USBPD_AGNOSTIC_phase2_RDIV_NUM_LOG3 0u
/* Number of RDIV_R_SHV Hard IP cell */
#define USBPD_AGNOSTIC_phase2_RDIV_R_NUM 1u
/* Number of VBUS IEC hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_VBUS_IEC_NUM 0u
/* Number of s8usbpd_det_shv_top hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_DET_SHV_NUM 0u
/* Total number of Det SHV Filter enable bits */
#define USBPD_AGNOSTIC_phase2_DET_SHV_NUM_LOG1 0u
/* Total number of Det SHV Filter CFG bits */
#define USBPD_AGNOSTIC_phase2_DET_SHV_NUM_LOG2 0u
/* Total number of Det SHV Filter Select bits */
#define USBPD_AGNOSTIC_phase2_DET_SHV_NUM_LOG3 0u
/* Number of s8usbpd_shvreg_top Regulator hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_SHVREG_NUM 0u
/* Total number of SHV Filter CFG bits */
#define USBPD_AGNOSTIC_phase2_SHVREG_NUM_LOG1 0u
/* Total number of SHV Filter CFG bits */
#define USBPD_AGNOSTIC_phase2_SHVREG_NUM_LOG2 0u
/* Total number of SHV Filter Select bits */
#define USBPD_AGNOSTIC_phase2_SHVREG_NUM_LOG3 0u
/* Number of Error Amplifier hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_EA_NUM    0u
/* Number of LSCSA hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_LSCSA_NUM 0u
/* Number of RefGen hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_REFGEN_NUM 1u
/* The P-Gate Drivers are internal */
#define USBPD_AGNOSTIC_phase2_INTR_PGDO_EN 1u
/* Number of PGDO hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_PGDO_NUM  1u
/* Number of Internal/External P-Gate Driver with Pull-Up is instantiated */
#define USBPD_AGNOSTIC_phase2_PGDO_PU_NUM 1u
/* Number of Internal/External P-Gate Driver with Pull-Up is instantiated extra
   Register */
#define USBPD_AGNOSTIC_phase2_PGDO_PU_NUM_EXTR 1u
/* s8usbpd_pgdo_pd_isnk_top is instantiated (0=No, 1=Yes) */
#define USBPD_AGNOSTIC_phase2_PGDO_PD_ISNK_EN 1u
/* Enable higher resolution of the Value for PGDO PD ISNK (0=No, 1=Yes) */
#define USBPD_AGNOSTIC_phase2_PGDO_ISNK_H_RES_EN 1u
/* Number of HBM CLamp hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_HBM_CLAMP_NUM 1u
/* Number of Ground pads for Discharge hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_DISCHG_GND_NUM 1u
/* Number of Discharge hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_DISCHG_NUM 1u
/* Number of Discharge hard IP + Protection Logic is instantiated */
#define USBPD_AGNOSTIC_phase2_DISCHG_PROT_NUM 0u
/* Number of s8usbpd_vconn_sw_shv_small_top */
#define USBPD_AGNOSTIC_phase2_SMALL_VCONN_NUM 0u
/* Total number of Small Vconn two-bit CFG bits */
#define USBPD_AGNOSTIC_phase2_SMALL_VCONN_NUM_LOG2 0u
/* Total number of Small Vconn three-bit CFG bits */
#define USBPD_AGNOSTIC_phase2_SMALL_VCONN_NUM_LOG3 0u
/* Enable one s8usbpd_vconn_sw_2vconn_shv_top */
#define USBPD_AGNOSTIC_phase2_TWO_VCONN_EN 0u
/* Enable one s8usbpd_vconn_sw_1vconn_shv_top */
#define USBPD_AGNOSTIC_phase2_ONE_VCONN_EN 0u
/* VCONN_SW_EN OR VCONN_TERM_EN */
#define USBPD_AGNOSTIC_phase2_VCONN_EN  0u
/* VCONN 20V enabled */
#define USBPD_AGNOSTIC_phase2_VCONN20_EN 1u
/* Enable one s8usbpd 300ma_sw_top */
#define USBPD_AGNOSTIC_phase2_FET_300_EN 0u
/* V5V is enabled */
#define USBPD_AGNOSTIC_phase2_V5V_EN    1u
/* Enable s8usbpd_cc_shvt_top */
#define USBPD_AGNOSTIC_phase2_CC_SHVT_EN 1u
/* Enable s8usbpd_cc_shvt_cabl_top */
#define USBPD_AGNOSTIC_phase2_CC_SHVT_CABLE_EN 0u
/* Use the Scan port of s8usbpd_cc_shvt_cabl_top */
#define USBPD_AGNOSTIC_phase2_USE_CC_SHVT_CABLE_SCAN_PORT 0u
/* s8usbpd current/voltage reference capable (0=No, 1=Yes) */
#define USBPD_AGNOSTIC_phase2_DPSLP_REF_EN 1u
/* s8usbpd pump capable (0=No, 1=Yes) */
#define USBPD_AGNOSTIC_phase2_CPUMP_EN  0u
/* Number of s8usbpd2 5vpump The V5PUMP_NUM indiates the total s8usbpd2 5vpump
   regardless of the V5PUMP_EN value */
#define USBPD_AGNOSTIC_phase2_V5PUMP_NUM 3u
/* Instantiate s8usbpd2 5vpump for Hard IP CC top (0=No, 1=Yes) */
#define USBPD_AGNOSTIC_phase2_V5PUMP_EN 1u
/* Number of ADC hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_ADC_NUM   1u
/* Number of s8usbpd_chgdet_afc_top */
#define USBPD_AGNOSTIC_phase2_BCH_DET_NUM 1u
/* Total number of Battery Charger Filter CFG bits */
#define USBPD_AGNOSTIC_phase2_BCH_DET_NUM_LOG2 2u
/* Total number of Battery Charger Filter select bits */
#define USBPD_AGNOSTIC_phase2_BCH_DET_NUM_LOG3 3u
/* IECs is used for charger detects hard IP [1]: For First Charger [2]: For Second
   Charger [3]: For Third Charger [4]: For Forth Charger */
#define USBPD_AGNOSTIC_phase2_CHGDET_IEC_EN 0u
/* Number of s8usbpd_chgdet_top */
#define USBPD_AGNOSTIC_phase2_CHGDET_NUM 0u
/* Total number of Charger 1-bit CFG bits */
#define USBPD_AGNOSTIC_phase2_CHGDET_NUM_LOG1 0u
/* Total number of Charger two-bit CFG bits */
#define USBPD_AGNOSTIC_phase2_CHGDET_NUM_LOG2 0u
/* Total number of Charger three-bit CFG bits */
#define USBPD_AGNOSTIC_phase2_CHGDET_NUM_LOG3 0u
/* The N-Gate Drivers are internal */
#define USBPD_AGNOSTIC_phase2_INTR_NGDO_EN 0u
/* Number of NGate Driver hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_NGDO_NUM  0u
/* Instantiate s8usbpd_sbu_sw_top */
#define USBPD_AGNOSTIC_phase2_SBU_SW_TOP_EN 0u
/* IECs is used for SBU ports hard IP [1]: For SBU switch#1 (1/2) [2]: For SBU
   switch#2 (3/4) [3]: For SBU switch#3 (5/6) [4]: For SBU switch#4 (7/8) */
#define USBPD_AGNOSTIC_phase2_SBU_IEC_EN 0u
/* Number of SBU Switch is instantiated */
#define USBPD_AGNOSTIC_phase2_SBU_NUM   0u
/* Number of SBU Switch is instantiated */
#define USBPD_AGNOSTIC_phase2_SBU20_NUM 1u
/* Total number of SBU20 two-bit CFG bits */
#define USBPD_AGNOSTIC_phase2_SBU20_NUM_LOG2 2u
/* Number of DPDM Switch is instantiated */
#define USBPD_AGNOSTIC_phase2_DPDM_NUM  1u
/* CCG6 DPDM Enabled */
#define USBPD_AGNOSTIC_phase2_DPDM_CCG6_EN 1u
/* Number of CSA hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_CSA_NUM   0u
/* Total number of s8_esd_res250only cell for each of pad_inp/pad_inn of
   s8usbpdv2_csa_top */
#define USBPD_AGNOSTIC_phase2_CSA_ESD_NUM 0u
/* Total number of CSA2,3,4 Filter CFG bits */
#define USBPD_AGNOSTIC_phase2_CSA_NUM_LOG1 0u
/* Total number of CSA2,3,4 Filter CFG bits */
#define USBPD_AGNOSTIC_phase2_CSA_NUM_LOG2 0u
/* Total number of CSA2,3,4 Filter select bits */
#define USBPD_AGNOSTIC_phase2_CSA_NUM_LOG3 0u
/* One CSA SCP hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_CSA_SCP_EN 1u
/* One CSA RCP hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_CSA_RCP_EN 1u
/* CSA SCP or CSA RCP hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_CSA_SCP_RCP_EN 1u
/* VSYS Enabled */
#define USBPD_AGNOSTIC_phase2_VSYS_EN   1u
/* Number of s8usbpd_20vreg_top Regulator hard IP is instantiated */
#define USBPD_AGNOSTIC_phase2_VREG20_NUM 1u
/* Total number of VREG20 2,3,4 Filter CFG bits */
#define USBPD_AGNOSTIC_phase2_VREG20_NUM_LOG1 1u
/* Total number of VREG20 2,3,4 Filter CFG bits */
#define USBPD_AGNOSTIC_phase2_VREG20_NUM_LOG2 2u
/* Total number of VREG20 2,3,4 Filter select bits */
#define USBPD_AGNOSTIC_phase2_VREG20_NUM_LOG3 3u
/* First regulator instatiated */
#define USBPD_AGNOSTIC_phase2_REGULATOR1_EN 0u
/* Second regulator instatiated */
#define USBPD_AGNOSTIC_phase2_REGULATOR2_EN 0u
/* Third regulator instatiated */
#define USBPD_AGNOSTIC_phase2_REGULATOR3_EN 0u
/* Forth regulator instatiated */
#define USBPD_AGNOSTIC_phase2_REGULATOR4_EN 0u
/* First 20V regulator instatiated */
#define USBPD_AGNOSTIC_phase2_REGULATOR20_1_EN 1u
/* Second 20V regulator instatiated */
#define USBPD_AGNOSTIC_phase2_REGULATOR20_2_EN 0u
/* Third 20V regulator instatiated */
#define USBPD_AGNOSTIC_phase2_REGULATOR20_3_EN 0u
/* Forth 20V regulator instatiated */
#define USBPD_AGNOSTIC_phase2_REGULATOR20_4_EN 0u
/* Regulator control is enabled */
#define USBPD_AGNOSTIC_phase2_REG_CONTROL_EN 1u
/* CSA hard IP VBUS number: 2:0 For CSA1 VBUS Number 5:3 For CSA2 VBUS Number 8:6
   For CSA3 VBUS Number 11:9 For CSA4 VBUS Number i.e:
   {CSA4[3:0],CSA3[3:0],CSA2[2:0],CSA1[2:0]} */
#define USBPD_AGNOSTIC_phase2_CSA_VBUS_NUM 0u
/* NGDO hard IP VBUS number: 2:0 For NGDO1 VBUS Number 5:3 For NGDO2 VBUS Number
   8:6 For NGDO3 VBUS Number 11:9 For NGDO4 VBUS Number i.e:
   {NGDO4[3:0],NGDO3[3:0],NGDO2[2:0],NGDO1[2:0]} */
#define USBPD_AGNOSTIC_phase2_NGDO_VBUS_NUM 0u
/* VREG hard IP VBUS number: 2:0 For VREG1 VBUS Number 5:3 For VREG2 VBUS Number
   8:6 For VREG3 VBUS Number 11:9 For VREG4 VBUS Number i.e:
   {VREG4[3:0],VREG3[3:0],VREG2[2:0],VREG1[2:0]} */
#define USBPD_AGNOSTIC_phase2_VREG20_VBUS_NUM 0u
/* SHVREG hard IP VBUS number: 2:0 For SHVREG1 VBUS Number 5:3 For SHVREG2 VBUS
   Number 8:6 For SHVREG3 VBUS Number 11:9 For SHVREG4 VBUS Number i.e:
   {SHVREG4[3:0],SHVREG3[3:0],SHVREG2[2:0],SHVREG1[2:0]} */
#define USBPD_AGNOSTIC_phase2_SHVREG_VBUS_NUM 0u
/* EA hard IP VBUS number: 2:0 For EA1 VBUS Number 5:3 For EA2 VBUS Number 8:6 For
   EA3 VBUS Number 11:9 For EA4 VBUS Number i.e:
   {EA4[3:0],EA3[3:0],EA2[2:0],EA1[2:0]} */
#define USBPD_AGNOSTIC_phase2_EA_VBUS_NUM 0u
/* VBUS_IEC hard IP VBUS number: 2:0 For VBUS_IEC1 VBUS Number 5:3 For VBUS_IEC2
   VBUS Number 8:6 For VBUS_IEC3 VBUS Number 11:9 For VBUS_IEC4 VBUS Number
   14:12 For VBUS_IEC5 VBUS Number 17:15 For VBUS_IEC6 VBUS Number 20:18 For
   VBUS_IEC7 VBUS Number 23:21 For VBUS_IEC8 VBUS Number i.e:
   {VBUS_IEC8[3:0],VBUS_IEC7[3:0],VBUS_IEC6[3:0],VBUS_IEC5[3:0],VBUS_IEC4[3:0],VBUS_IEC3[3:0],VBUS_IEC2[2:0],VBUS_IEC1[2:0]} */
#define USBPD_AGNOSTIC_phase2_VBUS_IEC_VBUS_NUM 0u
/* DISCHARGE hard IP VBUS number: 2:0 For DISCHG1 VBUS Number 5:3 For DISCHG2 VBUS
   Number 8:6 For DISCHG3 VBUS Number 11:9 For DISCHG4 VBUS Number i.e:
   {DISCHG4[3:0],DISCHG3[3:0],DISCHG2[2:0],DISCHG1[2:0]} */
#define USBPD_AGNOSTIC_phase2_DISCHG_VBUS_NUM 0u
/* CLAMP hard IP VBUS number: 2:0 For CLAMP1 VBUS Number 5:3 For CLAMP2 VBUS
   Number 8:6 For CLAMP3 VBUS Number 11:9 For CLAMP4 VBUS Number i.e:
   {CLAMP4[3:0],CLAMP3[3:0],CLAMP2[2:0],CLAMP1[2:0]} */
#define USBPD_AGNOSTIC_phase2_CLAMP_VBUS_NUM 0u
/* PGDO hard IP VBUS number: 2:0 For PGDO1 VBUS Number 5:3 For PGDO2 VBUS Number
   8:6 For PGDO3 VBUS Number 11:9 For PGDO4 VBUS Number 14:12 For PGDO5 VBUS
   Number 17:15 For PGDO6 VBUS Number 20:18 For PGDO7 VBUS Number 23:21 For
   PGDO8 VBUS Number i.e:
   {PGDO8[3:0],PGDO7[3:0],PGDO6[3:0],PGDO5[3:0],PGDO4[3:0],PGDO3[3:0],PGDO2[2:0],PGDO1[2:0]} */
#define USBPD_AGNOSTIC_phase2_PGDO_PU_VBUS_NUM 0u
/* PGDO hard IP VBUS number: 2:0 For PGDO1 VBUS Number 5:3 For PGDO2 VBUS Number
   8:6 For PGDO3 VBUS Number 11:9 For PGDO4 VBUS Number 14:12 For PGDO5 VBUS
   Number 17:15 For PGDO6 VBUS Number 20:18 For PGDO7 VBUS Number 23:21 For
   PGDO8 VBUS Number i.e:
   {PGDO8[3:0],PGDO7[3:0],PGDO6[3:0],PGDO5[3:0],PGDO4[3:0],PGDO3[3:0],PGDO2[2:0],PGDO1[2:0]} */
#define USBPD_AGNOSTIC_phase2_PGDO_VBUS_NUM 0u
/* RDIV_SHV hard IP VBUS number: 2:0 For RDIV_SHV1 VBUS Number 5:3 For RDIV_SHV2
   VBUS Number 8:6 For RDIV_SHV3 VBUS Number 11:9 For RDIV_SHV4 VBUS Number
   14:12 For RDIV_SHV5 VBUS Number 17:15 For RDIV_SHV6 VBUS Number 20:18 For
   RDIV_SHV7 VBUS Number 23:21 For RDIV_SHV8 VBUS Number i.e:
   {RDIV_SHV8[3:0],RDIV_SHV7[3:0],RDIV_SHV6[3:0],RDIV_SHV5[3:0],RDIV_SHV4[3:0],RDIV_SHV3[3:0],RDIV_SHV2[2:0],RDIV_SHV1[2:0]} */
#define USBPD_AGNOSTIC_phase2_RDIV_VBUS_NUM 0u
/* RDIV_R_SHV hard IP VBUS number: 2:0 For RDIV_R_SHV1 VBUS Number 5:3 For
   RDIV_R_SHV2 VBUS Number 8:6 For RDIV_R_SHV3 VBUS Number 11:9 For RDIV_R_SHV4
   VBUS Number 14:12 For RDIV_R_SHV5 VBUS Number 17:15 For RDIV_R_SHV6 VBUS
   Number 20:18 For RDIV_R_SHV7 VBUS Number 23:21 For RDIV_R_SHV8 VBUS Number
   i.e:
   {RDIV_R_SHV8[3:0],RDIV_R_SHV7[3:0],RDIV_R_SHV6[3:0],RDIV_R_SHV5[3:0],RDIV_R_SHV4[3:0],RDIV_R_SHV3[3:0],RDIV_R_SHV2[2:0],RDIV_R_SHV1[2:0]} */
#define USBPD_AGNOSTIC_phase2_RDIV_R_VBUS_NUM 0u
/* DET_SHV hard IP VBUS number: 2:0 For DET_SHV1 VBUS Number 5:3 For DET_SHV2 VBUS
   Number 8:6 For DET_SHV3 VBUS Number 11:9 For DET_SHV4 VBUS Number 14:12 For
   DET_SHV5 VBUS Number 17:15 For DET_SHV6 VBUS Number 20:18 For DET_SHV7 VBUS
   Number 23:21 For DET_SHV8 VBUS Number i.e:
   {DET_SHV8[3:0],DET_SHV7[3:0],DET_SHV6[3:0],DET_SHV5[3:0],DET_SHV4[3:0],DET_SHV3[3:0],DET_SHV2[2:0],DET_SHV1[2:0]} */
#define USBPD_AGNOSTIC_phase2_DET_SHV_VBUS_NUM 0u
/* Number of RefGen hard IP is instantiated */
#define USBPD_CCG5_TRIMS_REFGEN_NUM     0u
/* VCONN 20V enabled? */
#define USBPD_CCG5_TRIMS_VCONN20_EN     0u
/* s8usbpd current/voltage reference capable (0=No, 1=Yes) */
#define USBPD_CCG5_TRIMS_DPSLP_REF_EN   0u
/* VSYS Enabled */
#define USBPD_CCG5_TRIMS_VSYS_EN        0u
/* Number of RefGen hard IP is instantiated */
#define USBPD_CCG6_TRIMS_REFGEN_NUM     1u
/* VCONN 20V enabled */
#define USBPD_CCG6_TRIMS_VCONN20_EN     1u
/* s8usbpd current/voltage reference capable (0=No, 1=Yes) */
#define USBPD_CCG6_TRIMS_DPSLP_REF_EN   1u
/* VSYS Enabled */
#define USBPD_CCG6_TRIMS_VSYS_EN        1u
/* Number of words in EZ memory */
#define SCB_EZ_DATA_NR                  32u

#endif /* _PMG1S1_CONFIG_H_ */


/* [] END OF FILE */
