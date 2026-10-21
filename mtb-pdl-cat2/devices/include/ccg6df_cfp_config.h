/***************************************************************************//**
* \file ccg6df_cfp_config.h
*
* \brief
* CCG6DF_CFP device configuration header
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

#ifndef _CCG6DF_CFP_CONFIG_H_
#define _CCG6DF_CFP_CONFIG_H_

/* Clock Connections */
typedef enum
{
    PCLK_SCB0_CLOCK                 = 0x0000u,  /* scb[0].clock */
    PCLK_SCB1_CLOCK                 = 0x0001u,  /* scb[1].clock */
    PCLK_SCB2_CLOCK                 = 0x0002u,  /* scb[2].clock */
    PCLK_TCPWM_CLOCKS0              = 0x0003u,  /* tcpwm.clocks[0] */
    PCLK_TCPWM_CLOCKS1              = 0x0004u,  /* tcpwm.clocks[1] */
    PCLK_USBPD0_CLOCK_RX            = 0x0005u,  /* usbpd[0].clock_rx */
    PCLK_USBPD0_CLOCK_TX            = 0x0006u,  /* usbpd[0].clock_tx */
    PCLK_USBPD0_CLOCK_SAR           = 0x0007u,  /* usbpd[0].clock_sar */
    PCLK_USBPD0_CLOCK_SWAP          = 0x0008u,  /* usbpd[0].clock_swap */
    PCLK_USBPD0_CLOCK_FILTER1       = 0x0009u,  /* usbpd[0].clock_filter1 */
    PCLK_USBPD0_CLOCK_FILTER2       = 0x000Au,  /* usbpd[0].clock_filter2 */
    PCLK_USBPD0_CLOCK_REFGEN        = 0x000Bu,  /* usbpd[0].clock_refgen */
    PCLK_USBPD1_CLOCK_RX            = 0x000Cu,  /* usbpd[1].clock_rx */
    PCLK_USBPD1_CLOCK_TX            = 0x000Du,  /* usbpd[1].clock_tx */
    PCLK_USBPD1_CLOCK_SAR           = 0x000Eu,  /* usbpd[1].clock_sar */
    PCLK_USBPD1_CLOCK_SWAP          = 0x000Fu,  /* usbpd[1].clock_swap */
    PCLK_USBPD1_CLOCK_FILTER1       = 0x0010u,  /* usbpd[1].clock_filter1 */
    PCLK_USBPD1_CLOCK_FILTER2       = 0x0011u,  /* usbpd[1].clock_filter2 */
    PCLK_USBPD0_CLOCK_FRS_EN_SEQ    = 0x0012u,  /* usbpd[0].clock_frs_en_seq */
    PCLK_USBPD1_CLOCK_FRS_EN_SEQ    = 0x0013u   /* usbpd[1].clock_frs_en_seq */
} en_clk_dst_t;

/* Trigger Group */
/* This section contains the enums related to the Trigger multiplexer (TrigMux) driver.
* Refer to the Cypress Peripheral Driver Library Documentation, section Trigger multiplexer (TrigMux) -> Enumerated Types for details.
*/
/* Trigger Group Inputs */
/* Trigger Input Group 0 - DMA Request Assignments */
typedef enum
{
    TRIG0_IN_CPUSS_ZERO             = 0x00000000u, /* cpuss.zero */
    TRIG0_IN_TCPWM_TR_OVERFLOW0     = 0x00000001u, /* tcpwm.tr_overflow[0] */
    TRIG0_IN_TCPWM_TR_OVERFLOW1     = 0x00000002u, /* tcpwm.tr_overflow[1] */
    TRIG0_IN_TCPWM_TR_COMPARE_MATCH0 = 0x00000003u, /* tcpwm.tr_compare_match[0] */
    TRIG0_IN_TCPWM_TR_COMPARE_MATCH1 = 0x00000004u, /* tcpwm.tr_compare_match[1] */
    TRIG0_IN_TCPWM_TR_UNDERFLOW0    = 0x00000005u, /* tcpwm.tr_underflow[0] */
    TRIG0_IN_TCPWM_TR_UNDERFLOW1    = 0x00000006u, /* tcpwm.tr_underflow[1] */
    TRIG0_IN_SCB0_TR_TX_REQ         = 0x00000007u, /* scb[0].tr_tx_req */
    TRIG0_IN_SCB0_TR_RX_REQ         = 0x00000008u, /* scb[0].tr_rx_req */
    TRIG0_IN_SCB1_TR_TX_REQ         = 0x00000009u, /* scb[1].tr_tx_req */
    TRIG0_IN_SCB1_TR_RX_REQ         = 0x0000000Au, /* scb[1].tr_rx_req */
    TRIG0_IN_SCB2_TR_TX_REQ         = 0x0000000Bu, /* scb[2].tr_tx_req */
    TRIG0_IN_SCB2_TR_RX_REQ         = 0x0000000Cu, /* scb[2].tr_rx_req */
    TRIG0_IN_CPUSS_DMAC_TR_OUT0     = 0x0000000Du, /* cpuss.dmac_tr_out[0] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT1     = 0x0000000Eu, /* cpuss.dmac_tr_out[1] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT2     = 0x0000000Fu, /* cpuss.dmac_tr_out[2] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT3     = 0x00000010u, /* cpuss.dmac_tr_out[3] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT4     = 0x00000011u, /* cpuss.dmac_tr_out[4] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT5     = 0x00000012u, /* cpuss.dmac_tr_out[5] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT6     = 0x00000013u, /* cpuss.dmac_tr_out[6] */
    TRIG0_IN_CPUSS_DMAC_TR_OUT7     = 0x00000014u /* cpuss.dmac_tr_out[7] */
} en_trig_input_grp0_t;

/* Trigger Group Outputs */
/* Trigger Output Group 0 - DMA Request Assignments */
typedef enum
{
    TRIG0_OUT_CPUSS_DMAC_TR_IN0     = 0x40000000u, /* cpuss.dmac_tr_in[0] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN1     = 0x40000001u, /* cpuss.dmac_tr_in[1] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN2     = 0x40000002u, /* cpuss.dmac_tr_in[2] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN3     = 0x40000003u, /* cpuss.dmac_tr_in[3] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN4     = 0x40000004u, /* cpuss.dmac_tr_in[4] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN5     = 0x40000005u, /* cpuss.dmac_tr_in[5] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN6     = 0x40000006u, /* cpuss.dmac_tr_in[6] */
    TRIG0_OUT_CPUSS_DMAC_TR_IN7     = 0x40000007u /* cpuss.dmac_tr_in[7] */
} en_trig_output_grp0_t;

/* Include IP definitions */
#include "ip/cyip_sflash_256.h"
#include "ip/cyip_peri.h"
#include "ip/cyip_hsiom_v2.h"
#include "ip/cyip_srsslt.h"
#include "ip/cyip_gpio_v2.h"
#include "ip/cyip_scb_v2.h"
#include "ip/cyip_tcpwm_v2.h"
#include "ip/cyip_cryptolite.h"
#include "ip/cyip_cpuss_v6.h"
#include "ip/cyip_dmac_v6.h"
#include "ip/cyip_spcif_v6.h"
#include "ip/cyip_fpu_v6.h"

/* Parameter Defines */
/* CPUSS version (2 or 3) */
#define CPUSS_CPUSS_VER                 3u
/* CM0 present or CM0+ present (1=CM0, 0=CM0+) */
#define CPUSS_CM0_PRESENT               0u
/* CM0+ Memory protection unit present/not (0=not present, 8=present). */
#define CPUSS_CM0_MPU                   8u
/* MTB SRAM size in kilo bytes (0, 1, 2, or 4). Must be '0' for CM0, Non zero
   value only for CM0+. */
#define CPUSS_MTB_SRAM_SIZE             0u
/* CM0+ Micro Trace Buffer (MTB) Present or not (Must be '0' for CM0) */
#define CPUSS_MTB_PRESENT               0u
/* Maximum speed that system will run at (0=48MHz, 1=16MHz) */
#define CPUSS_MAX_16_MHZ                0u
/* System RAM parition 0, size in kilobytes */
#define CPUSS_SRAM_SIZE                 16u
/* System RAM parition 1, size in kilobytes */
#define CPUSS_SRAM1_SIZE                0u
/* Boot ROM size in kilobytes */
#define CPUSS_ROM_SIZE                  96u
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
#define CPUSS_INT_NR                    20u
/* Number of wakeup interrupt controller lines (always includes NMI, RXEV, so
   min=2) */
#define CPUSS_CM0_WICLINES              14u
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
#define CPUSS_DMAC_PRESENT              1u
/* Product is a multi-master system (same as CPUMEMSS.DMAC_PRESENT) */
#define CPUSS_MULTI_MASTER              1u
/* PTM interface present (0=No, 1=Yes) */
#define CPUSS_PTM_PRESENT               0u
/* Width of the PTM interface in bits ([2,32]) */
#define CPUSS_PTM_NR                    0u
/* Implement full (8-step) RAM BIST (1) or simple (1-step) RAM BIST (0) */
#define CPUSS_BIST_FULL                 0u
/* Number of external SRAMs connected to the CPUSS BIST controller */
#define CPUSS_BIST_EXT_SRAM_NR          11u
/* Number of SRAMs connected to the CPUSS BIST controller (BIST_EXT_SRAM_NR+4) */
#define CPUSS_BIST_SRAM_NR              15u
/* CoreSight Part Identification Number */
#define CPUSS_JEPID                     52u
/* CoreSight Part Identification Number */
#define CPUSS_JEPCONTINUATION           0u
/* CoreSight Part Identification Number */
#define CPUSS_PARTNUMBER                206u
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
/* External Master M1 Present (Note either DMA_PRESENT or EXT_MS_PRESENT must also
   be set) */
#define CPUSS_EXT_MS1_PRESENT           1u
/* MTB SRAM Base adress - Value should be computed from Memory Map */
#define CPUSS_CM0PMTB_MTB_SRAMBASE      0u
/* DW/DMA Controller present (0=No, 1=Yes) */
#define CPUSS_CPUMEMSS_DMAC_PRESENT     1u
/* FPU present - design time configurable */
#define CPUSS_CPUMEMSS_FPU_PRESENT      1u
/* Number of DMA Channels */
#define CPUSS_DMAC_CH_NR                8u
/* Width in bits of a DMA channel number (derived from CH_NR as
   roundup(log2(CH_NR))) */
#define CPUSS_DMAC_CH_ADDR_WIDTH        3u
/* FPU present - design time configurable */
#define CPUSS_FPU_FPU_PRESENT           1u
/* FPU present and design time configurable number of FPU blocks */
#define CPUSS_FPU_NUM_FPU_BLK           6u
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
/* IP MMIO registers base address in the system address space (32-bit Byte address
   at a 64 kB multiple). The IP MMIO registers occupy a 64 kB memory region in
   the system address space. */
#define CRYPTOLITE_ADDR_BASE            0x400C0000u
/* ECC present or not ('0': no, '1': yes). */
#define CRYPTOLITE_ECC_PRESENT          0u
/* True random number generation component support ('0': no, '1': yes). */
#define CRYPTOLITE_TRNG_PRESENT         1u
/* Vector unit component support ('0': no, '1': yes). */
#define CRYPTOLITE_VU_PRESENT           1u
/* SHA-256 hash component support ('0': no, '1': yes). */
#define CRYPTOLITE_SHA_PRESENT          0u
/* AES-128 block cipher component support ('0': no, '1': yes). */
#define CRYPTOLITE_AES_PRESENT          1u
/* Support for OR'ed interrupt ('0': no, '1': yes). */
#define CRYPTOLITE_INTR_ORED            1u
/* SHA-384 hash component support ('0': no, '1': yes). */
#define CRYPTOLITE_SHA384_PRESENT       1u
/* SHA-512 hash component support ('0': no, '1': yes). */
#define CRYPTOLITE_SHA512_PRESENT       1u
/* SHA function present or not ('0': None of the SHA functions are present, '1':
   Any of the SHA function is present i.e., SHA_PRESENT, SHA384_PRESENT or
   SHA512_PRESENT) */
#define CRYPTOLITE_SHA_ANY_PRESENT      1u
/* IOSS PHASE */
#define IOSS_IOSS_PHASE                 5u
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
/* Indicates port is a GPIO port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO_DVC 0u
/* GPIO_DVC, I2C_DVC GPIO_OVT Hyst Trim Register */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO_I2C_DVC_OVT 0u
/* GPIO_DVC, GPIO_OVT Slew Ctrl Register (No I2C) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO_DVC_OVT 0u
/* Indicates port is a I2C port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_I2C_DVC 0u
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
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_OVT 1u
/* Indicates port is a GPIO port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_DVC 0u
/* GPIO_DVC, I2C_DVC GPIO_OVT Hyst Trim Register */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_I2C_DVC_OVT 1u
/* GPIO_DVC, GPIO_OVT Slew Ctrl Register (No I2C) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO_DVC_OVT 1u
/* Indicates port is a I2C port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_I2C_DVC 0u
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
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_DVC 0u
/* GPIO_DVC, I2C_DVC GPIO_OVT Hyst Trim Register */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_I2C_DVC_OVT 0u
/* GPIO_DVC, GPIO_OVT Slew Ctrl Register (No I2C) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_DVC_OVT 0u
/* Indicates port is a I2C port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_I2C_DVC 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO4 1u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_DVC 0u
/* GPIO_DVC, I2C_DVC GPIO_OVT Hyst Trim Register */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_I2C_DVC_OVT 0u
/* GPIO_DVC, GPIO_OVT Slew Ctrl Register (No I2C) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_DVC_OVT 0u
/* Indicates port is a I2C port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_I2C_DVC 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO_V1P2 0u
/* Indicates port is an AUX port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_AUX 0u
/* Indicates that pin #0 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO4 0u
/* Indicates that pin #5 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO5 0u
/* Indicates that pin #6 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO6 0u
/* Indicates that pin #7 exists for this port */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_IO7 0u
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_DVC 0u
/* GPIO_DVC, I2C_DVC GPIO_OVT Hyst Trim Register */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_I2C_DVC_OVT 0u
/* GPIO_DVC, GPIO_OVT Slew Ctrl Register (No I2C) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_DVC_OVT 0u
/* Indicates port is a I2C port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_I2C_DVC 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO_V1P2 0u
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
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_FILTER_EN7 0u
/* Indicates port is present in the device */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_PRESENT 1u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port with OVT */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_OVT 0u
/* Indicates port is a GPIO port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_DVC 0u
/* GPIO_DVC, I2C_DVC GPIO_OVT Hyst Trim Register */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_I2C_DVC_OVT 0u
/* GPIO_DVC, GPIO_OVT Slew Ctrl Register (No I2C) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_DVC_OVT 0u
/* Indicates port is a I2C port with DVC */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_I2C_DVC 0u
/* Indicates port is a GPIO port with OVT reference generator */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_OVT_VREFGEN 0u
/* Indicates port is a GPIO port with 1.2V I/O */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO_V1P2 0u
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
/* Indicates that pin #0 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN0 0u
/* Indicates that pin #1 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN1 0u
/* Indicates that pin #2 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN2 0u
/* Indicates that pin #3 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN3 0u
/* Indicates that pin #4 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN4 0u
/* Indicates that pin #5 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN5 0u
/* Indicates that pin #6 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN6 0u
/* Indicates that pin #7 filter is present */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_FILTER_EN7 0u
/* Control register to improve IO testing */
#define IOSS_GPIO_IO_TEST_CTL           1u
/* GPIO_V1P2 cells used ? */
#define IOSS_GPIO_IO_GPIOV1P2           0u
/* GPIO_I2C_DVC Trim Register */
#define IOSS_GPIO_GPIO_I2C_DVC          0u
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
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR0_HSIOM_PRT_IO4 1u
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
/* Indicates that pin #0 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO0 1u
/* Indicates that pin #1 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO1 1u
/* Indicates that pin #2 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO2 1u
/* Indicates that pin #3 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO3 1u
/* Indicates that pin #4 exists for this port */
#define IOSS_HSIOM_HSIOM_PORT_NR2_HSIOM_PRT_IO4 1u
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
#define IOSS_HSIOM_HSIOM_PORT_NR3_HSIOM_PRT_IO3 1u
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
#define PERI_PCLK_CLOCK_NR              20u
/* Number of 8.0 dividers */
#define PERI_PCLK_DIV_8_NR              8u
/* Number of 16.0 dividers */
#define PERI_PCLK_DIV_16_NR             4u
/* Number of 16.5 (fractional) dividers */
#define PERI_PCLK_DIV_16_5_NR           4u
/* Number of 24.5 (fractional) dividers */
#define PERI_PCLK_DIV_24_5_NR           0u
/* Divider number width: max(1,roundup(log2(max(DIV_*_NR))) */
#define PERI_PCLK_DIV_ADDR_WIDTH        3u
/* Trigger module present (0=No, 1=Yes) */
#define PERI_TR                         1u
/* Number of trigger groups */
#define PERI_TR_GROUP_NR                1u
/* Number of input triggers */
#define PERI_TR_GROUP_NR_TR_GROUP_TR_IN_NR 21u
/* Number of output triggers */
#define PERI_TR_GROUP_NR_TR_GROUP_TR_OUT_NR 8u
/* Input trigger number width: roundup(log2(TR_IN_NR)) */
#define PERI_TR_GROUP_NR_TR_GROUP_TR_IN_ADDR_WIDTH 5u
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
/* CCG6DF_CFP_EN */
#define USBPD0_AGNOSTIC_ver3_CCG6DF_CFP_EN 1u
/* SRAM_EN (1:Yes, 0:No) */
#define USBPD0_AGNOSTIC_ver3_SRAM_EN    1u
/* USBPD Number of Instances (0=1 instance, 1= 2 instances) */
#define USBPD0_AGNOSTIC_ver3_INSTANCE_NUM 0u
/* Spare cell Library selection 1=LS,2=HD,3=HV */
#define USBPD0_AGNOSTIC_ver3_SPARE_STDLIB_CFG 2u
/* Spare Cell Enable */
#define USBPD0_AGNOSTIC_ver3_SPARE_EN   1u
/* USBPD function enable */
#define USBPD0_AGNOSTIC_ver3_PD_EN      1u
/* LF counter enable */
#define USBPD0_AGNOSTIC_ver3_LF_CNTR_EN 1u
/* 0: Use TX_HEADER register for GoodCRC Expected Header 1: Use
   RX_EXPECT_GOODCRC_MSG.EXPECTED_HEADER register for GoodCRC Expected Header */
#define USBPD0_AGNOSTIC_ver3_NOT_USE_TX_HEADER 1u
/* 0: Use RX_ORDER_SET_CTRL register for TX_SOP Order Set 1: Use TX_SOP_ORDER_SET
   register for TX_SOP Order Set */
#define USBPD0_AGNOSTIC_ver3_NOT_USE_RX_ORDER_SET 1u
/* Hardware handles the TX Specification Revsion field */
#define USBPD0_AGNOSTIC_ver3_SPEC_REV_EN 0u
/* Hardware handles the TX mesageID field */
#define USBPD0_AGNOSTIC_ver3_MSG_ID_EN  0u
/* Keep specific register bits or use their default to reduce gate count */
#define USBPD0_AGNOSTIC_ver3_KEEP_REG_BIT 1u
/* High speed filter enabled */
#define USBPD0_AGNOSTIC_ver3_HS_CLK_FILT_EN 1u
/* Extended data message function enabled */
#define USBPD0_AGNOSTIC_ver3_EXT_DATA_MSG_EN 1u
/* RPRD function enabled */
#define USBPD0_AGNOSTIC_ver3_RPRD_EN    1u
/* Swap function enabled */
#define USBPD0_AGNOSTIC_ver3_SWAP_EN    1u
/* HPD function enabled */
#define USBPD0_AGNOSTIC_ver3_HPD_EN     1u
/* Extra Fault GPIO logic enabled */
#define USBPD0_AGNOSTIC_ver3_FAULT_GPIO_EN_EXTR 1u
/* TCPWM Trigger enabled */
#define USBPD0_AGNOSTIC_ver3_TCPWM_TRIGGER_EN 1u
/* Interrupt SET function enabled */
#define USBPD0_AGNOSTIC_ver3_INTR_SET_EN 1u
/* Interrupt MASKED function enabled */
#define USBPD0_AGNOSTIC_ver3_INTR_MASKED_EN 1u
/* Bypass function enable */
#define USBPD0_AGNOSTIC_ver3_BYPASS_MODE_EN 1u
/* Enable the following registers: RX_SOP_GOOD_CRC_EN_CTRL, */
#define USBPD0_AGNOSTIC_ver3_RX_SOP_CTRL_EN 0u
/* Enabling the HPD RX input selection */
#define USBPD0_AGNOSTIC_ver3_HPD_IN_MUX_EN 1u
/* Number of ADC hard IP is instantiated */
#define USBPD0_AGNOSTIC_ver3_ADC_NUM    1u
/* VSYS Enabled */
#define USBPD0_AGNOSTIC_ver3_VSYS_EN    1u
/* USBPD Number of Instances (0=1 instance, 1= 2 instances) */
#define USBPD0_HIP_ver3_INSTANCE_NUM    0u
/* USBPD function enable */
#define USBPD0_HIP_ver3_PD_EN           1u
/* High speed filter enabled */
#define USBPD0_HIP_ver3_HS_CLK_FILT_EN  1u
/* RPRD function enabled */
#define USBPD0_HIP_ver3_RPRD_EN         1u
/* Number of comparator hard IP is instantiated */
#define USBPD0_HIP_ver3_COMP_NUM        3u
/* Number of USBPD AMUX NHV hard IP is instantiated */
#define USBPD0_HIP_ver3_USB_AMUX_NHV_NUM 9u
/* Number of USBPD AMUX DENFET hard IP is instantiated */
#define USBPD0_HIP_ver3_USB_AMUX_DENFET_NUM 1u
/* Total number of CLK_FILTER Filter */
#define USBPD0_HIP_ver3_CLK_FILTER_FILT_NUM 4u
/* Total number of CLK_FILTER 1-bit CFG bits */
#define USBPD0_HIP_ver3_CLK_FILTER_LOG1 4u
/* Total number of CLK_FILTER 12-bit Lower CFG bits */
#define USBPD0_HIP_ver3_CLK_FILTER_FILT_NUM_LOG1_12 4u
/* Total number of CLK_FILTER 12-bit Upper CFG bits */
#define USBPD0_HIP_ver3_CLK_FILTER_FILT_NUM_LOG2_12 0u
/* Total number of CLK_LF Filter */
#define USBPD0_HIP_ver3_CLK_LF_FILT_NUM 1u
/* VSYS Enabled */
#define USBPD0_HIP_ver3_VSYS_EN         1u
/* Switch_ctrl_0 */
#define USBPD0_HIP_ver3_SWITCH_00_FAULT_CNT 2u
/* Switch_ctrl_1 */
#define USBPD0_HIP_ver3_SWITCH_01_FAULT_CNT 2u
/* Switch_ctrl_2 */
#define USBPD0_HIP_ver3_SWITCH_02_FAULT_CNT 2u
/* Switch_ctrl_3 */
#define USBPD0_HIP_ver3_SWITCH_03_FAULT_CNT 6u
/* Switch_ctrl_4 */
#define USBPD0_HIP_ver3_SWITCH_04_FAULT_CNT 6u
/* Switch_ctrl_5 */
#define USBPD0_HIP_ver3_SWITCH_05_FAULT_CNT 4u
/* Switch_ctrl_6 */
#define USBPD0_HIP_ver3_SWITCH_06_FAULT_CNT 6u
/* Switch_ctrl_7 */
#define USBPD0_HIP_ver3_SWITCH_07_FAULT_CNT 6u
/* Switch_ctrl_8 */
#define USBPD0_HIP_ver3_SWITCH_08_FAULT_CNT 6u
/* Switch_ctrl_9 */
#define USBPD0_HIP_ver3_SWITCH_09_FAULT_CNT 6u
/* Switch_ctrl_10 */
#define USBPD0_HIP_ver3_SWITCH_10_FAULT_CNT 2u
/* Switch_ctrl_11 */
#define USBPD0_HIP_ver3_SWITCH_11_FAULT_CNT 2u
/* Instance_num */
#define USBPD0_HIP_ver3_INSTANCE_NUM_ZERO 1u
/* CCG6DF_CFP_EN */
#define USBPD1_AGNOSTIC_ver3_CCG6DF_CFP_EN 1u
/* SRAM_EN (1:Yes, 0:No) */
#define USBPD1_AGNOSTIC_ver3_SRAM_EN    1u
/* USBPD Number of Instances (0=1 instance, 1= 2 instances) */
#define USBPD1_AGNOSTIC_ver3_INSTANCE_NUM 1u
/* Spare cell Library selection 1=LS,2=HD,3=HV */
#define USBPD1_AGNOSTIC_ver3_SPARE_STDLIB_CFG 2u
/* Spare Cell Enable */
#define USBPD1_AGNOSTIC_ver3_SPARE_EN   1u
/* USBPD function enable */
#define USBPD1_AGNOSTIC_ver3_PD_EN      1u
/* LF counter enable */
#define USBPD1_AGNOSTIC_ver3_LF_CNTR_EN 1u
/* 0: Use TX_HEADER register for GoodCRC Expected Header 1: Use
   RX_EXPECT_GOODCRC_MSG.EXPECTED_HEADER register for GoodCRC Expected Header */
#define USBPD1_AGNOSTIC_ver3_NOT_USE_TX_HEADER 1u
/* 0: Use RX_ORDER_SET_CTRL register for TX_SOP Order Set 1: Use TX_SOP_ORDER_SET
   register for TX_SOP Order Set */
#define USBPD1_AGNOSTIC_ver3_NOT_USE_RX_ORDER_SET 1u
/* Hardware handles the TX Specification Revsion field */
#define USBPD1_AGNOSTIC_ver3_SPEC_REV_EN 0u
/* Hardware handles the TX mesageID field */
#define USBPD1_AGNOSTIC_ver3_MSG_ID_EN  0u
/* Keep specific register bits or use their default to reduce gate count */
#define USBPD1_AGNOSTIC_ver3_KEEP_REG_BIT 1u
/* High speed filter enabled */
#define USBPD1_AGNOSTIC_ver3_HS_CLK_FILT_EN 1u
/* Extended data message function enabled */
#define USBPD1_AGNOSTIC_ver3_EXT_DATA_MSG_EN 1u
/* RPRD function enabled */
#define USBPD1_AGNOSTIC_ver3_RPRD_EN    1u
/* Swap function enabled */
#define USBPD1_AGNOSTIC_ver3_SWAP_EN    1u
/* HPD function enabled */
#define USBPD1_AGNOSTIC_ver3_HPD_EN     1u
/* Extra Fault GPIO logic enabled */
#define USBPD1_AGNOSTIC_ver3_FAULT_GPIO_EN_EXTR 1u
/* TCPWM Trigger enabled */
#define USBPD1_AGNOSTIC_ver3_TCPWM_TRIGGER_EN 1u
/* Interrupt SET function enabled */
#define USBPD1_AGNOSTIC_ver3_INTR_SET_EN 1u
/* Interrupt MASKED function enabled */
#define USBPD1_AGNOSTIC_ver3_INTR_MASKED_EN 1u
/* Bypass function enable */
#define USBPD1_AGNOSTIC_ver3_BYPASS_MODE_EN 1u
/* Enable the following registers: RX_SOP_GOOD_CRC_EN_CTRL, */
#define USBPD1_AGNOSTIC_ver3_RX_SOP_CTRL_EN 0u
/* Enabling the HPD RX input selection */
#define USBPD1_AGNOSTIC_ver3_HPD_IN_MUX_EN 1u
/* Number of ADC hard IP is instantiated */
#define USBPD1_AGNOSTIC_ver3_ADC_NUM    1u
/* VSYS Enabled */
#define USBPD1_AGNOSTIC_ver3_VSYS_EN    0u
/* USBPD Number of Instances (0=1 instance, 1= 2 instances) */
#define USBPD1_HIP_ver3_INSTANCE_NUM    1u
/* USBPD function enable */
#define USBPD1_HIP_ver3_PD_EN           1u
/* High speed filter enabled */
#define USBPD1_HIP_ver3_HS_CLK_FILT_EN  1u
/* RPRD function enabled */
#define USBPD1_HIP_ver3_RPRD_EN         1u
/* Number of comparator hard IP is instantiated */
#define USBPD1_HIP_ver3_COMP_NUM        2u
/* Number of USBPD AMUX NHV hard IP is instantiated */
#define USBPD1_HIP_ver3_USB_AMUX_NHV_NUM 8u
/* Number of USBPD AMUX DENFET hard IP is instantiated */
#define USBPD1_HIP_ver3_USB_AMUX_DENFET_NUM 1u
/* Total number of CLK_FILTER Filter */
#define USBPD1_HIP_ver3_CLK_FILTER_FILT_NUM 3u
/* Total number of CLK_FILTER 1-bit CFG bits */
#define USBPD1_HIP_ver3_CLK_FILTER_LOG1 3u
/* Total number of CLK_FILTER 12-bit Lower CFG bits */
#define USBPD1_HIP_ver3_CLK_FILTER_FILT_NUM_LOG1_12 3u
/* Total number of CLK_FILTER 12-bit Upper CFG bits */
#define USBPD1_HIP_ver3_CLK_FILTER_FILT_NUM_LOG2_12 0u
/* Total number of CLK_LF Filter */
#define USBPD1_HIP_ver3_CLK_LF_FILT_NUM 0u
/* VSYS Enabled */
#define USBPD1_HIP_ver3_VSYS_EN         0u
/* Switch_ctrl_0 */
#define USBPD1_HIP_ver3_SWITCH_00_FAULT_CNT 2u
/* Switch_ctrl_1 */
#define USBPD1_HIP_ver3_SWITCH_01_FAULT_CNT 2u
/* Switch_ctrl_2 */
#define USBPD1_HIP_ver3_SWITCH_02_FAULT_CNT 2u
/* Switch_ctrl_3 */
#define USBPD1_HIP_ver3_SWITCH_03_FAULT_CNT 6u
/* Switch_ctrl_4 */
#define USBPD1_HIP_ver3_SWITCH_04_FAULT_CNT 6u
/* Switch_ctrl_5 */
#define USBPD1_HIP_ver3_SWITCH_05_FAULT_CNT 4u
/* Switch_ctrl_6 */
#define USBPD1_HIP_ver3_SWITCH_06_FAULT_CNT 6u
/* Switch_ctrl_7 */
#define USBPD1_HIP_ver3_SWITCH_07_FAULT_CNT 6u
/* Switch_ctrl_8 */
#define USBPD1_HIP_ver3_SWITCH_08_FAULT_CNT 6u
/* Switch_ctrl_9 */
#define USBPD1_HIP_ver3_SWITCH_09_FAULT_CNT 6u
/* Switch_ctrl_10 */
#define USBPD1_HIP_ver3_SWITCH_10_FAULT_CNT 2u
/* Switch_ctrl_11 */
#define USBPD1_HIP_ver3_SWITCH_11_FAULT_CNT 2u
/* Instance_num */
#define USBPD1_HIP_ver3_INSTANCE_NUM_ZERO 0u
/* Number of words in EZ memory */
#define SCB_EZ_DATA_NR                  32u

#endif /* _CCG6DF_CFP_CONFIG_H_ */


/* [] END OF FILE */
