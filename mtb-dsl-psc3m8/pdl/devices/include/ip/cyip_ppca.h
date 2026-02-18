/***************************************************************************//**
* PPCA IP definitions
*
********************************************************************************
* \copyright
* (c) 2016-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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

#ifndef _CYIP_PPCA_H_
#define _CYIP_PPCA_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     PPCA
*******************************************************************************/

#define PPCA_CNFG_CNFG_SECTION_SIZE             0x00000100UL
#define PPCA_CNFG_S2IRQ_SECTION_SIZE            0x00000010UL
#define PPCA_CNFG_ADCM_SECTION_SIZE             0x00000100UL
#define PPCA_CNFG_DISPERI_SECTION_SIZE          0x00000400UL
#define PPCA_CNFG_SECTION_SIZE                  0x00001000UL
#define PPCA_EPU_EPU_IRQ_SECTION_SIZE           0x00000020UL
#define PPCA_EPU_EPU_SECTION_SIZE               0x00000800UL
#define PPCA_EPU_SECTION_SIZE                   0x00001000UL
#define PPCA_CPUSS_CNFG_MXCM33_SECTION_SIZE     0x00010000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_SECTION_SIZE   0x00001000UL
#define PPCA_CPUSS_CNFG_RAMC_SECTION_SIZE       0x00010000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_SECTION_SIZE   0x00001000UL
#define PPCA_CPUSS_CNFG_SECTION_SIZE            0x00080000UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_SECTION_SIZE 0x00000100UL
#define PPCA_HWFILT3P3Z_SS_0_SECTION_SIZE       0x00001000UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_SECTION_SIZE 0x00000100UL
#define PPCA_HWFILT3P3Z_SS_1_SECTION_SIZE       0x00001000UL
#define PPCA_ADCM_ADCM_SECTION_SIZE             0x00000100UL
#define PPCA_ADCM_SECTION_SIZE                  0x00001000UL
#define PPCA_CLB_DICO_SECTION_SIZE              0x00000100UL
#define PPCA_CLB_MACO_SECTION_SIZE              0x00000400UL
#define PPCA_CLB_SECTION_SIZE                   0x00008000UL
#define MXCORDIC_SECTION_SIZE                   0x00010000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_SECTION_SIZE 0x00000200UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_SECTION_SIZE 0x00000100UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_SECTION_SIZE  0x00000400UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_SECTION_SIZE   0x00000100UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_SECTION_SIZE   0x00000100UL
#define PPCA_ATOPSS_ADC_GRP_IDAC_SECTION_SIZE   0x00000100UL
#define PPCA_ATOPSS_ADC_GRP_AREF_SECTION_SIZE   0x00000100UL
#define PPCA_ATOPSS_ADC_GRP_GPI_SECTION_SIZE    0x00000100UL
#define PPCA_ATOPSS_ADC_GRP_SECTION_SIZE        0x00002000UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_SECTION_SIZE 0x00000100UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_SECTION_SIZE 0x00000100UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK_SECTION_SIZE 0x00000100UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SECTION_SIZE  0x00001000UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_SECTION_SIZE 0x00000100UL
#define PPCA_ATOPSS_DCSG_GRP_SECTION_SIZE       0x00002000UL
#define PPCA_ATOPSS_SECTION_SIZE                0x00010000UL
#define PPCA_SECTION_SIZE                       0x00800000UL

/**
  * \brief PPCA_CNFG_CNFG
  */
typedef struct {
  __IOM uint32_t CNFG0;                         /*!< 0x00000000  */
  __IOM uint32_t CNFG1;                         /*!< 0x00000004  */
  __IOM uint32_t CNFG2;                         /*!< 0x00000008  */
  __IOM uint32_t CNFG_TRACE_ATOP;               /*!< 0x0000000C  */
  __IOM uint32_t CPU_CTRL;                      /*!< 0x00000010  */
  __IOM uint32_t RST_CTRL;                      /*!< 0x00000014  */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t PPCAIN_SEL[16];                /*!< 0x00000020  */
   __IM uint32_t RESERVED1[8];
  __IOM uint32_t TR_PPCAIN_SEL[16];             /*!< 0x00000080  */
  __IOM uint32_t PPCAOUT_SEL;                   /*!< 0x000000C0  */
   __IM uint32_t RESERVED2[7];
  __IOM uint32_t DDFTOUT_SEL[2];                /*!< 0x000000E0  */
   __IM uint32_t RESERVED3[2];
  __IOM uint32_t CNFGEXTDBGCONN;                /*!< 0x000000F0  */
   __IM uint32_t PPCAIO_IN_MON;                 /*!< 0x000000F4  */
  __IOM uint32_t SCRATCH0;                      /*!< 0x000000F8  */
  __IOM uint32_t SCRATCH1;                      /*!< 0x000000FC  */
} PPCA_CNFG_CNFG_Type;                          /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_CNFG_S2IRQ
  */
typedef struct {
  __IOM uint32_t INTR;                          /*!< 0x00000000 Interrupt Request Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000004 Interrupt Set Request Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000008 Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000000C Interrupt Masked Register */
} PPCA_CNFG_S2IRQ_Type;                         /*!< Size = 16 (0x10) */

/**
  * \brief PPCA_CNFG_ADCM
  */
typedef struct {
   __IM uint32_t ADC_DATA[48];                  /*!< 0x00000000  */
   __IM uint32_t RESERVED[16];
} PPCA_CNFG_ADCM_Type;                          /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_CNFG_DISPERI
  */
typedef struct {
  __IOM uint32_t DISPERI;                       /*!< 0x00000000  */
   __IM uint32_t RESERVED[255];
} PPCA_CNFG_DISPERI_Type;                       /*!< Size = 1024 (0x400) */

/**
  * \brief PPCA_CNFG
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000  */
   __IM uint32_t RESERVED[63];
        PPCA_CNFG_CNFG_Type CNFG;               /*!< 0x00000100  */
   __IM uint32_t RESERVED1[64];
        PPCA_CNFG_S2IRQ_Type S2IRQ[7];          /*!< 0x00000300  */
   __IM uint32_t RESERVED2[36];
        PPCA_CNFG_ADCM_Type ADCM;               /*!< 0x00000400  */
   __IM uint32_t RESERVED3[192];
        PPCA_CNFG_DISPERI_Type DISPERI;         /*!< 0x00000800  */
   __IM uint32_t RESERVED4[256];
} PPCA_CNFG_Type;                               /*!< Size = 4096 (0x1000) */

/**
  * \brief PPCA_EPU_EPU_IRQ
  */
typedef struct {
  __IOM uint32_t INTR_SRCSEL;                   /*!< 0x00000000 Interrupt Source Selection Register */
   __IM uint32_t RESERVED[3];
  __IOM uint32_t INTR;                          /*!< 0x00000010 Interrupt Request Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000014 Interrupt Set Request Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000018 Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000001C Interrupt Masked Register */
} PPCA_EPU_EPU_IRQ_Type;                        /*!< Size = 32 (0x20) */

/**
  * \brief PPCA_EPU_EPU
  */
typedef struct {
  __IOM uint32_t PU_T1_CNFG[32];                /*!< 0x00000000  */
   __IM uint32_t RESERVED[32];
  __IOM uint32_t PU_T2_CNFG[16];                /*!< 0x00000100  */
   __IM uint32_t RESERVED1[48];
  __IOM uint32_t COMBO_CNFG[123];               /*!< 0x00000200  */
   __IM uint32_t RESERVED2[5];
  __IOM uint32_t COMBO_FB_CNFG[8];              /*!< 0x00000400  */
   __IM uint32_t RESERVED3[248];
} PPCA_EPU_EPU_Type;                            /*!< Size = 2048 (0x800) */

/**
  * \brief PPCA_EPU
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000  */
   __IM uint32_t RESERVED[63];
        PPCA_EPU_EPU_IRQ_Type EPU_IRQ[8];       /*!< 0x00000100  */
   __IM uint32_t RESERVED1[128];
        PPCA_EPU_EPU_Type EPU;                  /*!< 0x00000400  */
   __IM uint32_t RESERVED2[256];
} PPCA_EPU_Type;                                /*!< Size = 4096 (0x1000) */

/**
  * \brief MXCM33-0/1 (PPCA_CPUSS_CNFG_MXCM33)
  */
typedef struct {
  __IOM uint32_t CM33_CTL;                      /*!< 0x00000000 Control */
  __IOM uint32_t CM33_CMD;                      /*!< 0x00000004 Command */
   __IM uint32_t CM33_STATUS;                   /*!< 0x00000008 Status */
   __IM uint32_t RESERVED[13];
   __IM uint32_t CM33_INT_STATUS[16];           /*!< 0x00000040 CM33 interrupt status */
  __IOM uint32_t CM33_NMI_CTL[4];               /*!< 0x00000080 CM33 NMI control */
   __IM uint32_t RESERVED1[12];
  __IOM uint32_t CM33_EVENT_CTL;                /*!< 0x000000C0 CM33 event control */
   __IM uint32_t RESERVED2[975];
  __IOM uint32_t CM33_S_VECTOR_TABLE_BASE;      /*!< 0x00001000 CM33 secure vector table base */
  __IOM uint32_t CM33_NS_VECTOR_TABLE_BASE;     /*!< 0x00001004 CM33 non-secure vector table base */
   __IM uint32_t RESERVED3[1022];
  __IOM uint32_t CM33_PC_CTL;                   /*!< 0x00002000 CM33 protection context control */
   __IM uint32_t RESERVED4[15];
  __IOM uint32_t CM33_PC0_HANDLER;              /*!< 0x00002040 CM33 protection context 0 handler */
   __IM uint32_t RESERVED5[47];
  __IOM uint32_t CM33_PC1_HANDLER;              /*!< 0x00002100 CM33 protection context 1 handler */
   __IM uint32_t RESERVED6[15];
  __IOM uint32_t CM33_PC2_HANDLER;              /*!< 0x00002140 CM33 protection context 2 handler */
   __IM uint32_t RESERVED7[15];
  __IOM uint32_t CM33_PC3_HANDLER;              /*!< 0x00002180 CM33 protection context 3 handler */
   __IM uint32_t RESERVED8[6047];
  __IOM uint32_t CM33_SYSTEM_INT_CTL[1023];     /*!< 0x00008000 CM33 system interrupt control */
   __IM uint32_t RESERVED9[7169];
} PPCA_CPUSS_CNFG_MXCM33_Type;                  /*!< Size = 65536 (0x10000) */

/**
  * \brief MPC Memory Protection Controller registers (PPCA_CPUSS_CNFG_RAMC_MPC)
  */
typedef struct {
  __IOM uint32_t CFG;                           /*!< 0x00000000 Config register with error response, RegionID PPC_MPC_MAIN is
                                                                the security owner PC. The error response configuration is
                                                                located in CFG.RESPONSE, only one such configuration exists
                                                                applying to all protection contexts in the system. */
   __IM uint32_t RESERVED[63];
  __IOM uint32_t CTRL;                          /*!< 0x00000100 Control register with lock bit and auto-increment only
                                                                (Separate CTRL for each PC depends on access_pc) */
   __IM uint32_t BLK_MAX;                       /*!< 0x00000104 Max value of block-based index register */
   __IM uint32_t BLK_CFG;                       /*!< 0x00000108 Block size & initialization in progress */
  __IOM uint32_t BLK_IDX;                       /*!< 0x0000010C Index of 32-block group accessed through BLK_LUT (Separate IDX
                                                                for each PC depending on access_pc) */
  __IOM uint32_t BLK_LUT;                       /*!< 0x00000110 NS status for 32 blocks at BLK_IDX with PC=<access_pc> */
   __IM uint32_t RESERVED1[59];
  __IOM uint32_t ROT_CTRL;                      /*!< 0x00000200 Control register with lock bit and auto-increment only */
   __IM uint32_t RESERVED2;
   __IM uint32_t ROT_BLK_MAX;                   /*!< 0x00000208 Max value of block-based index register for ROT */
   __IM uint32_t ROT_BLK_CFG;                   /*!< 0x0000020C Same as BLK_CFG */
  __IOM uint32_t ROT_BLK_IDX;                   /*!< 0x00000210 Index of 8-block group accessed through ROT_BLK_LUT_* */
  __IOM uint32_t ROT_BLK_PC;                    /*!< 0x00000214 Protection context of 8-block group accesses through
                                                                ROT_BLK_LUT */
  __IOM uint32_t ROT_BLK_LUT;                   /*!< 0x00000218 (R,W,NS) bits for 8 blocks at ROT_BLK_IDX for PC=ROT_BKL_PC */
   __IM uint32_t RESERVED3[889];
} PPCA_CPUSS_CNFG_RAMC_MPC_Type;                /*!< Size = 4096 (0x1000) */

/**
  * \brief RAMC0/1/2 (PPCA_CPUSS_CNFG_RAMC)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control */
   __IM uint32_t RESERVED;
   __IM uint32_t STATUS;                        /*!< 0x00000008 Status */
   __IM uint32_t RESERVED1[5];
  __IOM uint32_t ECC_CTL;                       /*!< 0x00000020 ECC control */
   __IM uint32_t ECC_STATUS0;                   /*!< 0x00000024 ECC status 0 */
   __IM uint32_t ECC_STATUS1;                   /*!< 0x00000028 ECC status 1 */
   __IM uint32_t RESERVED2[54];
  __IOM uint32_t ECC_MATCH;                     /*!< 0x00000104 ECC match */
   __IM uint32_t RESERVED3[62];
  __IOM uint32_t PWR_MACRO_CTL;                 /*!< 0x00000200 SRAM power partition power control */
   __IM uint32_t RESERVED4[15];
  __IOM uint32_t PWR_MACRO_CTL_LOCK;            /*!< 0x00000240 SRAM power partition power control Lock */
   __IM uint32_t RESERVED5[15];
  __IOM uint32_t PWR_DELAY_CTL;                 /*!< 0x00000280 SRAM power switch power up & sequence delay */
   __IM uint32_t RESERVED6[3935];
        PPCA_CPUSS_CNFG_RAMC_MPC_Type MPC[1];   /*!< 0x00004000 MPC Memory Protection Controller registers */
   __IM uint32_t RESERVED7[11264];
} PPCA_CPUSS_CNFG_RAMC_Type;                    /*!< Size = 65536 (0x10000) */

/**
  * \brief Power Policy Unit Registers for System RAM (PPCA_CPUSS_CNFG_RAMC_PPU)
  */
typedef struct {
  __IOM uint32_t PWPR;                          /*!< 0x00000000 Power Policy Register */
  __IOM uint32_t PMER;                          /*!< 0x00000004 Power Mode Emulation Register */
   __IM uint32_t PWSR;                          /*!< 0x00000008 Power Status Register */
   __IM uint32_t RESERVED;
   __IM uint32_t DISR;                          /*!< 0x00000010 Device Interface Input Current Status Register */
   __IM uint32_t MISR;                          /*!< 0x00000014 Miscellaneous Input Current Status Register */
   __IM uint32_t STSR;                          /*!< 0x00000018 Stored Status Register */
  __IOM uint32_t UNLK;                          /*!< 0x0000001C Unlock register */
  __IOM uint32_t PWCR;                          /*!< 0x00000020 Power Configuration Register */
  __IOM uint32_t PTCR;                          /*!< 0x00000024 Power Mode Transition Configuration Register */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t IMR;                           /*!< 0x00000030 Interrupt Mask Register */
  __IOM uint32_t AIMR;                          /*!< 0x00000034 Additional Interrupt Mask Register */
  __IOM uint32_t ISR;                           /*!< 0x00000038 Interrupt Status Register */
  __IOM uint32_t AISR;                          /*!< 0x0000003C Additional Interrupt Status Register */
  __IOM uint32_t IESR;                          /*!< 0x00000040 Input Edge Sensitivity Register */
  __IOM uint32_t OPSR;                          /*!< 0x00000044 Operating Mode Active Edge Sensitivity Register */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t FUNRR;                         /*!< 0x00000050 Functional Retention RAM Configuration Register */
  __IOM uint32_t FULRR;                         /*!< 0x00000054 Full Retention RAM Configuration Register */
  __IOM uint32_t MEMRR;                         /*!< 0x00000058 Memory Retention RAM Configuration Register */
   __IM uint32_t RESERVED3[65];
  __IOM uint32_t EDTR0;                         /*!< 0x00000160 Power Mode Entry Delay Register 0 */
  __IOM uint32_t EDTR1;                         /*!< 0x00000164 Power Mode Entry Delay Register 1 */
   __IM uint32_t RESERVED4[2];
   __IM uint32_t DCDR0;                         /*!< 0x00000170 Device Control Delay Configuration Register 0 */
   __IM uint32_t DCDR1;                         /*!< 0x00000174 Device Control Delay Configuration Register 1 */
   __IM uint32_t RESERVED5[910];
   __IM uint32_t IDR0;                          /*!< 0x00000FB0 PPU Identification Register 0 */
   __IM uint32_t IDR1;                          /*!< 0x00000FB4 PPU Identification Register 1 */
   __IM uint32_t RESERVED6[4];
   __IM uint32_t IIDR;                          /*!< 0x00000FC8 Implementation Identification Register */
   __IM uint32_t AIDR;                          /*!< 0x00000FCC Architecture Identification Register */
   __IM uint32_t PID4;                          /*!< 0x00000FD0 Implementation Defined Identification Register (PID4) */
   __IM uint32_t RESERVED7[3];
   __IM uint32_t PID0;                          /*!< 0x00000FE0 Implementation Defined Identification Register (PID0) */
   __IM uint32_t PID1;                          /*!< 0x00000FE4 Implementation Defined Identification Register (PID1) */
   __IM uint32_t PID2;                          /*!< 0x00000FE8 Implementation Defined Identification Register (PID2) */
   __IM uint32_t PID3;                          /*!< 0x00000FEC Implementation Defined Identification Register (PID3) */
   __IM uint32_t ID0;                           /*!< 0x00000FF0 Implementation Defined Identification Register (ID0) */
   __IM uint32_t ID1;                           /*!< 0x00000FF4 Implementation Defined Identification Register (ID1) */
   __IM uint32_t ID2;                           /*!< 0x00000FF8 Implementation Defined Identification Register (ID2) */
   __IM uint32_t ID3;                           /*!< 0x00000FFC Implementation Defined Identification Register (ID3) */
} PPCA_CPUSS_CNFG_RAMC_PPU_Type;                /*!< Size = 4096 (0x1000) */

/**
  * \brief PPCA_CPUSS_CNFG
  */
typedef struct {
        PPCA_CPUSS_CNFG_MXCM33_Type PPCA_MXCM33[2]; /*!< 0x00000000 MXCM33-0/1 */
        PPCA_CPUSS_CNFG_RAMC_Type RAMC[5];      /*!< 0x00020000 RAMC0/1/2 */
  __IOM uint32_t AP_CTL;                        /*!< 0x00070000 Access port control */
  __IOM uint32_t MP_CTL;                        /*!< 0x00070004 Master Port Access control */
   __IM uint32_t RESERVED[8190];
        PPCA_CPUSS_CNFG_RAMC_PPU_Type RAMC_PPU[5]; /*!< 0x00078000 Power Policy Unit Registers for System RAM */
   __IM uint32_t RESERVED1[3072];
} PPCA_CPUSS_CNFG_Type;                         /*!< Size = 524288 (0x80000) */

/**
  * \brief PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000  */
  __IOM uint32_t DATA_IN0;                      /*!< 0x00000004  */
  __IOM uint32_t DATA_IN1;                      /*!< 0x00000008  */
  __IOM uint32_t CNFG;                          /*!< 0x0000000C  */
  __IOM uint32_t CX0;                           /*!< 0x00000010  */
  __IOM uint32_t CX1;                           /*!< 0x00000014  */
  __IOM uint32_t CX2;                           /*!< 0x00000018  */
  __IOM uint32_t CX3;                           /*!< 0x0000001C  */
   __IM uint32_t RESERVED;
  __IOM uint32_t CY1;                           /*!< 0x00000024  */
  __IOM uint32_t CY2;                           /*!< 0x00000028  */
  __IOM uint32_t CY3;                           /*!< 0x0000002C  */
   __IM uint32_t DATA_OUT;                      /*!< 0x00000030  */
  __IOM uint32_t OFFSET;                        /*!< 0x00000034  */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t LIMMAX;                        /*!< 0x00000040  */
  __IOM uint32_t LIMMIN;                        /*!< 0x00000044  */
   __IM uint32_t RESERVED2[6];
  __IOM uint32_t SCALECX;                       /*!< 0x00000060  */
  __IOM uint32_t SCALECY;                       /*!< 0x00000064  */
  __IOM uint32_t GIN;                           /*!< 0x00000068  */
  __IOM uint32_t GOUT;                          /*!< 0x0000006C  */
   __IM uint32_t RESERVED3[4];
   __IM uint32_t VERSION;                       /*!< 0x00000080  */
   __IM uint32_t RESERVED4[31];
} PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_Type;         /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_HWFILT3P3Z_SS_0
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000  */
   __IM uint32_t RESERVED[63];
        PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_Type HWFILT3P3Z[4]; /*!< 0x00000100  */
   __IM uint32_t RESERVED1[704];
} PPCA_HWFILT3P3Z_SS_0_Type;                    /*!< Size = 4096 (0x1000) */

/**
  * \brief PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000  */
  __IOM uint32_t DATA_IN0;                      /*!< 0x00000004  */
  __IOM uint32_t DATA_IN1;                      /*!< 0x00000008  */
  __IOM uint32_t CNFG;                          /*!< 0x0000000C  */
  __IOM uint32_t CX0;                           /*!< 0x00000010  */
  __IOM uint32_t CX1;                           /*!< 0x00000014  */
  __IOM uint32_t CX2;                           /*!< 0x00000018  */
  __IOM uint32_t CX3;                           /*!< 0x0000001C  */
   __IM uint32_t RESERVED;
  __IOM uint32_t CY1;                           /*!< 0x00000024  */
  __IOM uint32_t CY2;                           /*!< 0x00000028  */
  __IOM uint32_t CY3;                           /*!< 0x0000002C  */
   __IM uint32_t DATA_OUT;                      /*!< 0x00000030  */
  __IOM uint32_t OFFSET;                        /*!< 0x00000034  */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t LIMMAX;                        /*!< 0x00000040  */
  __IOM uint32_t LIMMIN;                        /*!< 0x00000044  */
   __IM uint32_t RESERVED2[6];
  __IOM uint32_t SCALECX;                       /*!< 0x00000060  */
  __IOM uint32_t SCALECY;                       /*!< 0x00000064  */
  __IOM uint32_t GIN;                           /*!< 0x00000068  */
  __IOM uint32_t GOUT;                          /*!< 0x0000006C  */
   __IM uint32_t RESERVED3[4];
   __IM uint32_t VERSION;                       /*!< 0x00000080  */
   __IM uint32_t RESERVED4[31];
} PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_Type;         /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_HWFILT3P3Z_SS_1
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000  */
   __IM uint32_t RESERVED[63];
        PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_Type HWFILT3P3Z[2]; /*!< 0x00000100  */
   __IM uint32_t RESERVED1[832];
} PPCA_HWFILT3P3Z_SS_1_Type;                    /*!< Size = 4096 (0x1000) */

/**
  * \brief PPCA_ADCM_ADCM
  */
typedef struct {
   __IM uint32_t ADC_DATA[48];                  /*!< 0x00000000  */
   __IM uint32_t RESERVED[16];
} PPCA_ADCM_ADCM_Type;                          /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_ADCM
  */
typedef struct {
        PPCA_ADCM_ADCM_Type ADCM;               /*!< 0x00000000  */
   __IM uint32_t RESERVED[960];
} PPCA_ADCM_Type;                               /*!< Size = 4096 (0x1000) */

/**
  * \brief PPCA_CLB_DICO
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000  */
  __IOM uint32_t CNFG;                          /*!< 0x00000004  */
  __IOM uint32_t EVENT;                         /*!< 0x00000008  */
  __IOM uint32_t SAFE;                          /*!< 0x0000000C  */
  __IOM uint32_t IMAXL;                         /*!< 0x00000010  */
  __IOM uint32_t IMINL;                         /*!< 0x00000014  */
  __IOM uint32_t VAC_POL;                       /*!< 0x00000018  */
  __IOM uint32_t OBS_CTRL;                      /*!< 0x0000001C  */
   __IM uint32_t PERIOD_MEAS[3];                /*!< 0x00000020  */
   __IM uint32_t RESERVED;
   __IM uint32_t IEST_IND_ACCU[3];              /*!< 0x00000030  */
   __IM uint32_t RESERVED1;
   __IM uint32_t IL_ACCU[3];                    /*!< 0x00000040  */
   __IM uint32_t RESERVED2;
  __IOM uint32_t IEST_CORR[3];                  /*!< 0x00000050  */
   __IM uint32_t RESERVED3;
   __IM uint32_t PE_IMINL;                      /*!< 0x00000060 IMINL for Up and Down Slope */
   __IM uint32_t PE_IMAXL;                      /*!< 0x00000064 IMAXL for Up and Down Slope */
   __IM uint32_t PE_UP_COUNT;                   /*!< 0x00000068 UP Count Register for Up and Down Slope */
   __IM uint32_t PE_DN_COUNT;                   /*!< 0x0000006C DOWN Count Register for Up and Down Slope */
  __IOM uint32_t PE_TPHD_1;                     /*!< 0x00000070 TPHD Value (PCO_1) Register for PE */
  __IOM uint32_t PE_TPHD_2;                     /*!< 0x00000074 TPHD Value (PCO_2) Register for PE */
   __IM uint32_t RESERVED4[2];
  __IOM uint32_t PS_TH;                         /*!< 0x00000080 Threshold Current multiplied by Inductance Register for PS */
   __IM uint32_t RESERVED5[3];
   __IM uint32_t PS_CC_INFO[2];                 /*!< 0x00000090 IMINL/IMAXL Correction Information Register for PS */
   __IM uint32_t RESERVED6[2];
  __IOM uint32_t PS_CC[2];                      /*!< 0x000000A0 Correction term of IMINL/IMAXL Register for PS */
   __IM uint32_t RESERVED7[2];
  __IOM uint32_t INTR;                          /*!< 0x000000B0 Interrupt Request Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x000000B4 Interrupt Set Request Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x000000B8 Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x000000BC Interrupt Masked Register */
   __IM uint32_t PCO_CORR_IEST[3];              /*!< 0x000000C0  */
   __IM uint32_t RESERVED8;
  __IOM uint32_t STAT;                          /*!< 0x000000D0  */
   __IM uint32_t RESERVED9[11];
} PPCA_CLB_DICO_Type;                           /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_CLB_MACO
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000  */
  __IOM uint32_t EVENT;                         /*!< 0x00000004  */
   __IM uint32_t RESERVED;
   __IM uint32_t STAT;                          /*!< 0x0000000C  */
   __IM uint32_t RESERVED1[4];
  __IOM uint32_t SECT0_ROW;                     /*!< 0x00000020  */
  __IOM uint32_t SECT1_ROW;                     /*!< 0x00000024  */
  __IOM uint32_t SECT2_ROW;                     /*!< 0x00000028  */
   __IM uint32_t RESERVED2;
  __IOM uint32_t INTR;                          /*!< 0x00000030 Interrupt Request Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000034 Interrupt Set Request Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000038 Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000003C Interrupt Masked Register */
   __IM uint32_t RESERVED3[48];
  __IOM uint32_t SECT0_PATTERN[20];             /*!< 0x00000100  */
   __IM uint32_t RESERVED4[43];
  __IOM uint32_t SECT0_SAFE;                    /*!< 0x000001FC  */
  __IOM uint32_t SECT1_PATTERN[20];             /*!< 0x00000200  */
   __IM uint32_t RESERVED5[43];
  __IOM uint32_t SECT1_SAFE;                    /*!< 0x000002FC  */
  __IOM uint32_t SECT2_PATTERN[20];             /*!< 0x00000300  */
   __IM uint32_t RESERVED6[43];
  __IOM uint32_t SECT2_SAFE;                    /*!< 0x000003FC  */
} PPCA_CLB_MACO_Type;                           /*!< Size = 1024 (0x400) */

/**
  * \brief PPCA_CLB
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000  */
   __IM uint32_t RESERVED[2047];
        PPCA_CLB_DICO_Type DICO;                /*!< 0x00002000  */
   __IM uint32_t RESERVED1[1984];
        PPCA_CLB_MACO_Type MACO;                /*!< 0x00004000  */
   __IM uint32_t RESERVED2[3840];
} PPCA_CLB_Type;                                /*!< Size = 32768 (0x8000) */

/**
  * \brief MXCORDIC
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000  */
   __IM uint32_t RESERVED;
   __IM uint32_t ID;                            /*!< 0x00000008 Module Identification Register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t INTR;                          /*!< 0x00000010 Interrupt Cause Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000014 Interrupt Set Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000018 Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000001C Interrupt Masked Register */
   __IM uint32_t RESERVED2[8];
  __IOM uint32_t KEEP;                          /*!< 0x00000040 CORDIC Keep Register */
  __IOM uint32_t CON;                           /*!< 0x00000044 CORDIC Control Register */
  __IOM uint32_t CORDX;                         /*!< 0x00000048 CORDIC X Data Register */
  __IOM uint32_t CORDY;                         /*!< 0x0000004C CORDIC Y Data Register */
  __IOM uint32_t CORDZ;                         /*!< 0x00000050 CORDIC Z Data Register */
   __IM uint32_t CORRX;                         /*!< 0x00000054 CORDIC X Result Register */
   __IM uint32_t CORRY;                         /*!< 0x00000058 CORDIC Y Result Register */
   __IM uint32_t CORRZ;                         /*!< 0x0000005C CORDIC Z Result Register */
   __IM uint32_t STAT;                          /*!< 0x00000060 CORDIC Status Register */
  __IOM uint32_t START_CMD;                     /*!< 0x00000064 CORDIC Start Command Register */
   __IM uint32_t RESERVED3[16358];
} MXCORDIC_Type;                                /*!< Size = 65536 (0x10000) */

/**
  * \brief PPCA_ATOPSS_ADC_GRP_SLICE_ADC
  */
typedef struct {
  __IOM uint32_t ADC_CTL;                       /*!< 0x00000000 ADC Control Register */
  __IOM uint32_t ADC_CNFG;                      /*!< 0x00000004 ADC Configuration Register */
  __IOM uint32_t ADC_AUX_ALT_AUX_CNFG;          /*!< 0x00000008 ADC Aux and ALT Aux Configuration Register */
   __IM uint32_t RESERVED;
  __IOM uint32_t ADC_CNV_CNFG;                  /*!< 0x00000010 ADC Conversion Configuration Register */
  __IOM uint32_t ADC_SAMPLING_MASK;             /*!< 0x00000014 ADC Sampling Mask register */
  __IOM uint32_t ADC_TRIGGER;                   /*!< 0x00000018 ADC Channel Trigger register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t ADC_CH_CNFG0;                  /*!< 0x00000020 ADC Channels group 0 to be converted Configurations registers */
  __IOM uint32_t ADC_CH_CNFG1;                  /*!< 0x00000024 ADC Channels group 1 to be converted Configurations registers */
  __IOM uint32_t ADC_CH_CNFG2;                  /*!< 0x00000028 ADC Channels group 2 to be converted Configurations registers */
  __IOM uint32_t ADC_CH_CNFG3;                  /*!< 0x0000002C ADC Channels group 3 to be converted Configurations registers */
  __IOM uint32_t ADC_AUX_CH_CNFG0;              /*!< 0x00000030 ADC Auxiliary Channels to be converted configuration registers */
  __IOM uint32_t ADC_AUX_CH_CNFG1;              /*!< 0x00000034 ADC Auxiliary Channels to be converted configuration registers */
  __IOM uint32_t ADC_ALT_AUX_CH_CNFG;           /*!< 0x00000038 ADC AUX Alternate Channel to be converted configuration
                                                                register */
   __IM uint32_t RESERVED2;
   __IM uint32_t ADC_DATA[16];                  /*!< 0x00000040 ADC Converted Data Channels */
   __IM uint32_t ADC_AUX_DATA[16];              /*!< 0x00000080 ADC Auxiliary Data Channels */
   __IM uint32_t ADC_ALT_AUX_DATA[8];           /*!< 0x000000C0 ADC Alternate Auxiliary Data Channels */
  __IOM uint32_t ADC_INTR;                      /*!< 0x000000E0 Interrupt request register */
  __IOM uint32_t ADC_INTR_SET;                  /*!< 0x000000E4 Interrupt set request register */
  __IOM uint32_t ADC_INTR_MASK;                 /*!< 0x000000E8 Interrupt mask register */
   __IM uint32_t ADC_INTR_MASKED;               /*!< 0x000000EC Interrupt masked request register */
  __IOM uint32_t ADC_SIGN_UNSIGN_CNFG;          /*!< 0x000000F0 ADC Channel Signed and Unsigned configuration Register */
  __IOM uint32_t AUX_SIGN_UNSIGN_CNFG;          /*!< 0x000000F4 AUX Channel Signed and Unsigned configuration Register */
  __IOM uint32_t AUX_ALT_SIGN_UNSIGN_CNFG;      /*!< 0x000000F8 AUX Alternate Channel Signed and Unsigned configuration
                                                                Register */
   __IM uint32_t RESERVED3;
  __IOM uint32_t ADC_STARTUPCTRL;               /*!< 0x00000100 SARADC STARTUP Control Register */
  __IOM uint32_t ADC_CALCTRL;                   /*!< 0x00000104 SARADC CALIBRATION Control Register */
   __IM uint32_t RESERVED4[6];
  __IOM uint32_t ADC_CALOFFSET[16];             /*!< 0x00000120 SARADC CAL offset per channel */
  __IOM uint32_t ADC_CALGAIN[16];               /*!< 0x00000160 SARADC GAIN CAL per channel */
   __IM uint32_t RESERVED5[3];
  __IOM uint32_t ADC_DFT_AUX_CNFG;              /*!< 0x000001AC ADC DFT DATA Test register */
   __IM uint32_t RESERVED6[20];
} PPCA_ATOPSS_ADC_GRP_SLICE_ADC_Type;           /*!< Size = 512 (0x200) */

/**
  * \brief PPCA_ATOPSS_ADC_GRP_SLICE_AFE
  */
typedef struct {
  __IOM uint32_t AFE_CTL;                       /*!< 0x00000000  */
  __IOM uint32_t AFE_CNFG;                      /*!< 0x00000004  */
  __IOM uint32_t AFE_CALGAINAFE_1;              /*!< 0x00000008  */
  __IOM uint32_t AFE_CALGAINAFE_2;              /*!< 0x0000000C  */
  __IOM uint32_t AFE_CALGAINAFE_3;              /*!< 0x00000010  */
  __IOM uint32_t AFE_CALGAINAFE_4;              /*!< 0x00000014  */
  __IOM uint32_t AFE_CALOFFSETAFE_1;            /*!< 0x00000018  */
  __IOM uint32_t AFE_CALOFFSETAFE_2;            /*!< 0x0000001C  */
  __IOM uint32_t AFE_CALOFFSETAFE_3;            /*!< 0x00000020  */
  __IOM uint32_t AFE_CALOFFSETAFE_4;            /*!< 0x00000024  */
   __IM uint32_t RESERVED[54];
} PPCA_ATOPSS_ADC_GRP_SLICE_AFE_Type;           /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_ATOPSS_ADC_GRP_SLICE
  */
typedef struct {
        PPCA_ATOPSS_ADC_GRP_SLICE_ADC_Type ADC; /*!< 0x00000000  */
        PPCA_ATOPSS_ADC_GRP_SLICE_AFE_Type AFE; /*!< 0x00000200  */
   __IM uint32_t RESERVED[64];
} PPCA_ATOPSS_ADC_GRP_SLICE_Type;               /*!< Size = 1024 (0x400) */

/**
  * \brief PPCA_ATOPSS_ADC_GRP_AFLT
  */
typedef struct {
  __IOM uint32_t AFLT_CTL;                      /*!< 0x00000000 Low Pass Filter Control Register */
  __IOM uint32_t AFLT_CNFG;                     /*!< 0x00000004 ADC Filter Module Configuration register */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t LPF_ALFA;                      /*!< 0x00000010 Low Pass Filter Bandwidth configuration Register */
   __IM uint32_t LPF_DOUT;                      /*!< 0x00000014 Low Pass Filter Data Output */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t CICF_CNFG;                     /*!< 0x00000020 CIC3 Configuration register */
   __IM uint32_t CICF_DOUT;                     /*!< 0x00000024 CIC3 Filter Data Output */
  __IOM uint32_t CICF_UB_TH;                    /*!< 0x00000028 CIC3 Upper bound threshold register */
  __IOM uint32_t CICF_LB_TH;                    /*!< 0x0000002C CIC3 Lower bound threshold register */
  __IOM uint32_t AVGF_CTL;                      /*!< 0x00000030 Average Filter CTL register */
  __IOM uint32_t AVGF_CNFG;                     /*!< 0x00000034 Average Filter Configuration Register (N,M,K) */
   __IM uint32_t AVGF_DOUT;                     /*!< 0x00000038 Average Filter Data Output */
   __IM uint32_t RESERVED2;
  __IOM uint32_t LIF_CNFG;                      /*!< 0x00000040 Linear Interpolator Filter Configuration register */
   __IM uint32_t LIF_DOUT;                      /*!< 0x00000044 Linear Interpolator Filter Data Output */
   __IM uint32_t RESERVED3[2];
  __IOM uint32_t MED_CNFG;                      /*!< 0x00000050 Median Filter Configuration register */
   __IM uint32_t MED_DOUT;                      /*!< 0x00000054 Median Filter Data Output */
   __IM uint32_t RESERVED4[2];
   __IM uint32_t ADC_MIN_MAX;                   /*!< 0x00000060 ADC Min Max detect value Register */
   __IM uint32_t RESERVED5[39];
} PPCA_ATOPSS_ADC_GRP_AFLT_Type;                /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_ATOPSS_ADC_GRP_DCMP
  */
typedef struct {
  __IOM uint32_t DCMP_CTL;                      /*!< 0x00000000  */
  __IOM uint32_t DCMP_CNFG;                     /*!< 0x00000004  */
  __IOM uint32_t DCMP_TRIGGER;                  /*!< 0x00000008  */
  __IOM uint32_t DCMP_TH;                       /*!< 0x0000000C  */
  __IOM uint32_t DCMP_ACC_TH;                   /*!< 0x00000010  */
   __IM uint32_t RESERVED[59];
} PPCA_ATOPSS_ADC_GRP_DCMP_Type;                /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_ATOPSS_ADC_GRP_IDAC
  */
typedef struct {
  __IOM uint32_t IDAC_CTL;                      /*!< 0x00000000  */
  __IOM uint32_t IDAC_CNFG;                     /*!< 0x00000004  */
   __IM uint32_t RESERVED[62];
} PPCA_ATOPSS_ADC_GRP_IDAC_Type;                /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_ATOPSS_ADC_GRP_AREF
  */
typedef struct {
  __IOM uint32_t AREF_CTL;                      /*!< 0x00000000 AREF control */
   __IM uint32_t RESERVED;
   __IM uint32_t VDDA_STATUS;                   /*!< 0x00000008 Analog Voltage Status */
  __IOM uint32_t AREF_ANA_CTL;                  /*!< 0x0000000C Analog Control */
  __IOM uint32_t VREF_TRIM0;                    /*!< 0x00000010 VREF Trim bits */
  __IOM uint32_t VREF_TRIM1;                    /*!< 0x00000014 VREF Trim bits */
  __IOM uint32_t VREF_TRIM2;                    /*!< 0x00000018 VREF Trim bits */
  __IOM uint32_t VREF_TRIM3;                    /*!< 0x0000001C VREF Trim bits */
  __IOM uint32_t IZTAT_TRIM0;                   /*!< 0x00000020 IZTAT Trim bits */
  __IOM uint32_t IZTAT_TRIM1;                   /*!< 0x00000024 IZTAT Trim bits */
  __IOM uint32_t IPTAT_TRIM0;                   /*!< 0x00000028 IPTAT Trim bits */
  __IOM uint32_t IPTAT_TRIM1;                   /*!< 0x0000002C 0 */
  __IOM uint32_t ICTAT_TRIM0;                   /*!< 0x00000030 ICTAT Trim bits */
   __IM uint32_t RESERVED1[51];
} PPCA_ATOPSS_ADC_GRP_AREF_Type;                /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_ATOPSS_ADC_GRP_GPI
  */
typedef struct {
  __IOM uint32_t GPI_CTL;                       /*!< 0x00000000  */
   __IM uint32_t RESERVED[63];
} PPCA_ATOPSS_ADC_GRP_GPI_Type;                 /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_ATOPSS_ADC_GRP
  */
typedef struct {
        PPCA_ATOPSS_ADC_GRP_SLICE_Type SLICE[2]; /*!< 0x00000000  */
   __IM uint32_t RESERVED[512];
        PPCA_ATOPSS_ADC_GRP_AFLT_Type AFLT[4];  /*!< 0x00001000  */
        PPCA_ATOPSS_ADC_GRP_DCMP_Type DCMP[4];  /*!< 0x00001400  */
        PPCA_ATOPSS_ADC_GRP_IDAC_Type IDAC;     /*!< 0x00001800  */
        PPCA_ATOPSS_ADC_GRP_AREF_Type AREF;     /*!< 0x00001900  */
        PPCA_ATOPSS_ADC_GRP_GPI_Type GPI;       /*!< 0x00001A00  */
   __IM uint32_t RESERVED1[320];
} PPCA_ATOPSS_ADC_GRP_Type;                     /*!< Size = 8192 (0x2000) */

/**
  * \brief DCSG Slice Module (PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE)
  */
typedef struct {
  __IOM uint32_t DCSG_CTL;                      /*!< 0x00000000 Analog Comparator Control Register */
  __IOM uint32_t DCSG_CNFG;                     /*!< 0x00000004 Analog Comparator Configuration Register */
  __IOM uint32_t DCSG_TH;                       /*!< 0x00000008 Analog Comparator Threshold configuration register */
   __IM uint32_t RESERVED;
  __IOM uint32_t DCSG_DIFF_CALOFFSET;           /*!< 0x00000010 Analog Comparator Differential Mode Calibration register */
  __IOM uint32_t DCSG_SE_CALOFFSET;             /*!< 0x00000014 Analog Comparator Single Ended Mode Calibration register */
  __IOM uint32_t DCSG_DIFF_CALGAIN_1;           /*!< 0x00000018 Analog Comparator Differential Mode Gain register */
  __IOM uint32_t DCSG_DIFF_CALGAIN_2;           /*!< 0x0000001C Analog Comparator Differential Mode Gain register */
  __IOM uint32_t DCSG_SE_CALGAIN;               /*!< 0x00000020 Analog Comparator Single Ended Mode Gain register */
   __IM uint32_t RESERVED1[55];
} PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type;         /*!< Size = 256 (0x100) */

/**
  * \brief DCSG Slice Module (PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN)
  */
typedef struct {
  __IOM uint32_t DCSG_SLGEN_CTL;                /*!< 0x00000000  */
  __IOM uint32_t DCSG_SLGEN_CNFG;               /*!< 0x00000004  */
  __IOM uint32_t DCSG_SLGEN_INIT;               /*!< 0x00000008  */
  __IOM uint32_t DCSG_SLGEN_TARGET;             /*!< 0x0000000C  */
  __IOM uint32_t DCSG_SLGEN_INIT_BUF;           /*!< 0x00000010  */
  __IOM uint32_t DCSG_SLGEN_TARGET_BUF;         /*!< 0x00000014  */
  __IOM uint32_t DCSG_SLGEN_STEP;               /*!< 0x00000018  */
   __IM uint32_t DCSG_SLGEN_MATCH;              /*!< 0x0000001C  */
   __IM uint32_t RESERVED[56];
} PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_Type;         /*!< Size = 256 (0x100) */

/**
  * \brief DCSG Slice Module (PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK)
  */
typedef struct {
  __IOM uint32_t DCSG_BLANK_CTL;                /*!< 0x00000000  */
   __IM uint32_t RESERVED[63];
} PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK_Type;         /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_ATOPSS_DCSG_GRP_DCSG
  */
typedef struct {
        PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type SLICE[6]; /*!< 0x00000000 DCSG Slice Module */
        PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_Type SLGEN[6]; /*!< 0x00000600 DCSG Slice Module */
        PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK_Type BLANK; /*!< 0x00000C00 DCSG Slice Module */
   __IM uint32_t RESERVED[192];
} PPCA_ATOPSS_DCSG_GRP_DCSG_Type;               /*!< Size = 4096 (0x1000) */

/**
  * \brief CSG Module (PPCA_ATOPSS_DCSG_GRP_DAC_R2R)
  */
typedef struct {
  __IOM uint32_t DAC_CTL;                       /*!< 0x00000000  */
  __IOM uint32_t DAC_CNFG;                      /*!< 0x00000004  */
  __IOM uint32_t DAC_DOUT;                      /*!< 0x00000008  */
  __IOM uint32_t DAC_OFFSET_CNFG1;              /*!< 0x0000000C DAC Offset CNFG1 register */
  __IOM uint32_t DAC_OFFSET_CNFG2;              /*!< 0x00000010 DAC Gain CNFG4 register */
  __IOM uint32_t DAC_OFFSET_CNFG3;              /*!< 0x00000014 0 */
  __IOM uint32_t DAC_OFFSET_CNFG4;              /*!< 0x00000018 0 */
  __IOM uint32_t DAC_OFFSET_CNFG5;              /*!< 0x0000001C 0 */
  __IOM uint32_t DAC_GAIN_CNFG1;                /*!< 0x00000020 DAC Gain CNFG1 register */
  __IOM uint32_t DAC_GAIN_CNFG2;                /*!< 0x00000024 DAC Gain CNFG2 register */
  __IOM uint32_t DAC_GAIN_CNFG3;                /*!< 0x00000028 DAC Gain CNFG3 register */
  __IOM uint32_t DAC_GAIN_CNFG4;                /*!< 0x0000002C DAC Gain CNFG4 register */
  __IOM uint32_t DAC_GAIN_CNFG5;                /*!< 0x00000030 DAC Gain CNFG5 register */
  __IOM uint32_t BUFFER_OFFSET_1;               /*!< 0x00000034 Buffer Offset 1 register */
  __IOM uint32_t BUFFER_OFFSET_2;               /*!< 0x00000038 Buffer Offset 2 register */
   __IM uint32_t RESERVED[49];
} PPCA_ATOPSS_DCSG_GRP_DAC_R2R_Type;            /*!< Size = 256 (0x100) */

/**
  * \brief PPCA_ATOPSS_DCSG_GRP
  */
typedef struct {
        PPCA_ATOPSS_DCSG_GRP_DCSG_Type DCSG;    /*!< 0x00000000  */
        PPCA_ATOPSS_DCSG_GRP_DAC_R2R_Type DAC_R2R; /*!< 0x00001000 CSG Module */
   __IM uint32_t RESERVED[960];
} PPCA_ATOPSS_DCSG_GRP_Type;                    /*!< Size = 8192 (0x2000) */

/**
  * \brief MXS40ATOPSS IP (PPCA_ATOPSS)
  */
typedef struct {
        PPCA_ATOPSS_ADC_GRP_Type ADC_GRP[4];    /*!< 0x00000000  */
        PPCA_ATOPSS_DCSG_GRP_Type DCSG_GRP[2];  /*!< 0x00008000  */
   __IM uint32_t RESERVED[4096];
} PPCA_ATOPSS_Type;                             /*!< Size = 65536 (0x10000) */

/**
  * \brief MXS40PPSS IP (PPCA)
  */
typedef struct {
        PPCA_CNFG_Type CNFG;                    /*!< 0x00000000  */
   __IM uint32_t RESERVED[3072];
        PPCA_EPU_Type EPU;                      /*!< 0x00004000  */
   __IM uint32_t RESERVED1[93184];
        IPC_Type PPCA_IPC;                      /*!< 0x00060000 IPC */
   __IM uint32_t RESERVED2[16384];
        PPCA_CPUSS_CNFG_Type CPUSS_CNFG;        /*!< 0x00080000  */
        TCPWM_Type TCPWM[4];                    /*!< 0x00100000 S40 Timer/Counter/PWM */
        PPCA_HWFILT3P3Z_SS_0_Type HWFILT3P3Z_SS_0; /*!< 0x00500000  */
   __IM uint32_t RESERVED3[15360];
        PPCA_HWFILT3P3Z_SS_1_Type HWFILT3P3Z_SS_1; /*!< 0x00510000  */
   __IM uint32_t RESERVED4[15360];
        PPCA_ADCM_Type ADCM;                    /*!< 0x00520000  */
   __IM uint32_t RESERVED5[15360];
        PPCA_CLB_Type CLB;                      /*!< 0x00530000  */
   __IM uint32_t RESERVED6[8192];
        MXCORDIC_Type MXCORDIC[2];              /*!< 0x00540000  */
   __IM uint32_t RESERVED7[32768];
        PPCA_ATOPSS_Type ATOPSS;                /*!< 0x00580000 MXS40ATOPSS IP */
} PPCA_Type;                                    /*!< Size = 5832704 (0x590000) */


/* PPCA_CNFG_CNFG.CNFG0 */
#define PPCA_CNFG_CNFG_CNFG0_PWM_SS0_Pos        0UL
#define PPCA_CNFG_CNFG_CNFG0_PWM_SS0_Msk        0x1UL
#define PPCA_CNFG_CNFG_CNFG0_PWM_SS1_Pos        1UL
#define PPCA_CNFG_CNFG_CNFG0_PWM_SS1_Msk        0x2UL
#define PPCA_CNFG_CNFG_CNFG0_PWM_SS2_Pos        2UL
#define PPCA_CNFG_CNFG_CNFG0_PWM_SS2_Msk        0x4UL
#define PPCA_CNFG_CNFG_CNFG0_PWM_SS3_Pos        3UL
#define PPCA_CNFG_CNFG_CNFG0_PWM_SS3_Msk        0x8UL
#define PPCA_CNFG_CNFG_CNFG0_HWFILT3P3Z_SS0_Pos 4UL
#define PPCA_CNFG_CNFG_CNFG0_HWFILT3P3Z_SS0_Msk 0x10UL
#define PPCA_CNFG_CNFG_CNFG0_HWFILT3P3Z_SS1_Pos 5UL
#define PPCA_CNFG_CNFG_CNFG0_HWFILT3P3Z_SS1_Msk 0x20UL
#define PPCA_CNFG_CNFG_CNFG0_ADC_MIRROR_Pos     6UL
#define PPCA_CNFG_CNFG_CNFG0_ADC_MIRROR_Msk     0x40UL
#define PPCA_CNFG_CNFG_CNFG0_CLB_Pos            7UL
#define PPCA_CNFG_CNFG_CNFG0_CLB_Msk            0x80UL
#define PPCA_CNFG_CNFG_CNFG0_CORDIC_0_Pos       8UL
#define PPCA_CNFG_CNFG_CNFG0_CORDIC_0_Msk       0x100UL
#define PPCA_CNFG_CNFG_CNFG0_CORDIC_1_Pos       9UL
#define PPCA_CNFG_CNFG_CNFG0_CORDIC_1_Msk       0x200UL
#define PPCA_CNFG_CNFG_CNFG0_ADCGRP_0_Pos       10UL
#define PPCA_CNFG_CNFG_CNFG0_ADCGRP_0_Msk       0x400UL
#define PPCA_CNFG_CNFG_CNFG0_ADCGRP_1_Pos       11UL
#define PPCA_CNFG_CNFG_CNFG0_ADCGRP_1_Msk       0x800UL
#define PPCA_CNFG_CNFG_CNFG0_ADCGRP_2_Pos       12UL
#define PPCA_CNFG_CNFG_CNFG0_ADCGRP_2_Msk       0x1000UL
#define PPCA_CNFG_CNFG_CNFG0_ADCGRP_3_Pos       13UL
#define PPCA_CNFG_CNFG_CNFG0_ADCGRP_3_Msk       0x2000UL
#define PPCA_CNFG_CNFG_CNFG0_DCSGGRP_0_Pos      14UL
#define PPCA_CNFG_CNFG_CNFG0_DCSGGRP_0_Msk      0x4000UL
#define PPCA_CNFG_CNFG_CNFG0_DCSGGRP_1_Pos      15UL
#define PPCA_CNFG_CNFG_CNFG0_DCSGGRP_1_Msk      0x8000UL
/* PPCA_CNFG_CNFG.CNFG1 */
#define PPCA_CNFG_CNFG_CNFG1_CNFG_PUTY1_Pos     0UL
#define PPCA_CNFG_CNFG_CNFG1_CNFG_PUTY1_Msk     0xFFFFFFFFUL
/* PPCA_CNFG_CNFG.CNFG2 */
#define PPCA_CNFG_CNFG_CNFG2_CNFG_PUTY2_Pos     0UL
#define PPCA_CNFG_CNFG_CNFG2_CNFG_PUTY2_Msk     0xFFFFUL
/* PPCA_CNFG_CNFG.CNFG_TRACE_ATOP */
#define PPCA_CNFG_CNFG_CNFG_TRACE_ATOP_SEL_ADC_GRP_Pos 0UL
#define PPCA_CNFG_CNFG_CNFG_TRACE_ATOP_SEL_ADC_GRP_Msk 0x3UL
#define PPCA_CNFG_CNFG_CNFG_TRACE_ATOP_EN_TRACE_ATOP_Pos 2UL
#define PPCA_CNFG_CNFG_CNFG_TRACE_ATOP_EN_TRACE_ATOP_Msk 0x4UL
#define PPCA_CNFG_CNFG_CNFG_TRACE_ATOP_SEL_MODE_Pos 3UL
#define PPCA_CNFG_CNFG_CNFG_TRACE_ATOP_SEL_MODE_Msk 0x8UL
#define PPCA_CNFG_CNFG_CNFG_TRACE_ATOP_POL_Pos  4UL
#define PPCA_CNFG_CNFG_CNFG_TRACE_ATOP_POL_Msk  0x10UL
/* PPCA_CNFG_CNFG.CPU_CTRL */
#define PPCA_CNFG_CNFG_CPU_CTRL_CPU0_ENABLE_Pos 0UL
#define PPCA_CNFG_CNFG_CPU_CTRL_CPU0_ENABLE_Msk 0x1UL
#define PPCA_CNFG_CNFG_CPU_CTRL_CPU1_ENABLE_Pos 1UL
#define PPCA_CNFG_CNFG_CPU_CTRL_CPU1_ENABLE_Msk 0x2UL
/* PPCA_CNFG_CNFG.RST_CTRL */
#define PPCA_CNFG_CNFG_RST_CTRL_CPU0_RST_Pos    0UL
#define PPCA_CNFG_CNFG_RST_CTRL_CPU0_RST_Msk    0x1UL
#define PPCA_CNFG_CNFG_RST_CTRL_CPU1_RST_Pos    1UL
#define PPCA_CNFG_CNFG_RST_CTRL_CPU1_RST_Msk    0x2UL
/* PPCA_CNFG_CNFG.PPCAIN_SEL */
#define PPCA_CNFG_CNFG_PPCAIN_SEL_PPCAIN_SEL_SRC_Pos 0UL
#define PPCA_CNFG_CNFG_PPCAIN_SEL_PPCAIN_SEL_SRC_Msk 0x3FUL
#define PPCA_CNFG_CNFG_PPCAIN_SEL_DS_SYNCSTAGE_PPCAIN_SEL_Pos 8UL
#define PPCA_CNFG_CNFG_PPCAIN_SEL_DS_SYNCSTAGE_PPCAIN_SEL_Msk 0x100UL
/* PPCA_CNFG_CNFG.TR_PPCAIN_SEL */
#define PPCA_CNFG_CNFG_TR_PPCAIN_SEL_TR_PPCAIN_SEL_SRC_Pos 0UL
#define PPCA_CNFG_CNFG_TR_PPCAIN_SEL_TR_PPCAIN_SEL_SRC_Msk 0x3FUL
#define PPCA_CNFG_CNFG_TR_PPCAIN_SEL_DS_SYNCSTAGE_TR_PPCAIN_SEL_Pos 8UL
#define PPCA_CNFG_CNFG_TR_PPCAIN_SEL_DS_SYNCSTAGE_TR_PPCAIN_SEL_Msk 0x100UL
/* PPCA_CNFG_CNFG.PPCAOUT_SEL */
#define PPCA_CNFG_CNFG_PPCAOUT_SEL_PPCAOUT_SEL_SRC_Pos 0UL
#define PPCA_CNFG_CNFG_PPCAOUT_SEL_PPCAOUT_SEL_SRC_Msk 0x1UL
#define PPCA_CNFG_CNFG_PPCAOUT_SEL_PPCAOUT_SEL_EN_Pos 1UL
#define PPCA_CNFG_CNFG_PPCAOUT_SEL_PPCAOUT_SEL_EN_Msk 0x2UL
/* PPCA_CNFG_CNFG.DDFTOUT_SEL */
#define PPCA_CNFG_CNFG_DDFTOUT_SEL_DDFTOUT_SEL_SRC_Pos 0UL
#define PPCA_CNFG_CNFG_DDFTOUT_SEL_DDFTOUT_SEL_SRC_Msk 0x1FFUL
/* PPCA_CNFG_CNFG.CNFGEXTDBGCONN */
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_PWM_SS0_Pos 0UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_PWM_SS0_Msk 0x1UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_PWM_SS1_Pos 1UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_PWM_SS1_Msk 0x2UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_PWM_SS2_Pos 2UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_PWM_SS2_Msk 0x4UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_PWM_SS3_Pos 3UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_PWM_SS3_Msk 0x8UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_CLB_Pos   7UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_CLB_Msk   0x80UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_ADCGRP_0_Pos 10UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_ADCGRP_0_Msk 0x400UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_ADCGRP_1_Pos 11UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_ADCGRP_1_Msk 0x800UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_ADCGRP_2_Pos 12UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_ADCGRP_2_Msk 0x1000UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_ADCGRP_3_Pos 13UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_ADCGRP_3_Msk 0x2000UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_DCSGGRP_0_Pos 14UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_DCSGGRP_0_Msk 0x4000UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_DCSGGRP_1_Pos 15UL
#define PPCA_CNFG_CNFG_CNFGEXTDBGCONN_DCSGGRP_1_Msk 0x8000UL
/* PPCA_CNFG_CNFG.PPCAIO_IN_MON */
#define PPCA_CNFG_CNFG_PPCAIO_IN_MON_PPCAIO_IN_MON_Pos 0UL
#define PPCA_CNFG_CNFG_PPCAIO_IN_MON_PPCAIO_IN_MON_Msk 0xFFFFUL
/* PPCA_CNFG_CNFG.SCRATCH0 */
#define PPCA_CNFG_CNFG_SCRATCH0_SCRATCH0_Pos    0UL
#define PPCA_CNFG_CNFG_SCRATCH0_SCRATCH0_Msk    0xFFFFFFFFUL
/* PPCA_CNFG_CNFG.SCRATCH1 */
#define PPCA_CNFG_CNFG_SCRATCH1_SCRATCH1_Pos    0UL
#define PPCA_CNFG_CNFG_SCRATCH1_SCRATCH1_Msk    0xFFFFFFFFUL


/* PPCA_CNFG_S2IRQ.INTR */
#define PPCA_CNFG_S2IRQ_INTR_INTR_Pos           0UL
#define PPCA_CNFG_S2IRQ_INTR_INTR_Msk           0x1UL
/* PPCA_CNFG_S2IRQ.INTR_SET */
#define PPCA_CNFG_S2IRQ_INTR_SET_INTR_SET_Pos   0UL
#define PPCA_CNFG_S2IRQ_INTR_SET_INTR_SET_Msk   0x1UL
/* PPCA_CNFG_S2IRQ.INTR_MASK */
#define PPCA_CNFG_S2IRQ_INTR_MASK_INTR_MASK_Pos 0UL
#define PPCA_CNFG_S2IRQ_INTR_MASK_INTR_MASK_Msk 0x1UL
/* PPCA_CNFG_S2IRQ.INTR_MASKED */
#define PPCA_CNFG_S2IRQ_INTR_MASKED_INTR_MASKED_Pos 0UL
#define PPCA_CNFG_S2IRQ_INTR_MASKED_INTR_MASKED_Msk 0x1UL


/* PPCA_CNFG_ADCM.ADC_DATA */
#define PPCA_CNFG_ADCM_ADC_DATA_ADC_DATA_Pos    0UL
#define PPCA_CNFG_ADCM_ADC_DATA_ADC_DATA_Msk    0xFFFFFFFFUL


/* PPCA_CNFG_DISPERI.DISPERI */
#define PPCA_CNFG_DISPERI_DISPERI_DS_CPU0_Pos   0UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_CPU0_Msk   0x1UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_CPU1_Pos   1UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_CPU1_Msk   0x2UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_ADCGRP0_Pos 2UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_ADCGRP0_Msk 0x4UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_ADCGRP1_Pos 3UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_ADCGRP1_Msk 0x8UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_ADCGRP2_Pos 4UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_ADCGRP2_Msk 0x10UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_ADCGRP3_Pos 5UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_ADCGRP3_Msk 0x20UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_DCSG_GRP0_Pos 6UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_DCSG_GRP0_Msk 0x40UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_DCSG_GRP1_Pos 7UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_DCSG_GRP1_Msk 0x80UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS0_Pos 8UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS0_Msk 0x100UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS0_MOTIF_Pos 9UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS0_MOTIF_Msk 0x200UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS0_HR_Pos 10UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS0_HR_Msk 0x400UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS1_Pos 11UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS1_Msk 0x800UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS1_MOTIF_Pos 12UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS1_MOTIF_Msk 0x1000UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS1_HR_Pos 13UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS1_HR_Msk 0x2000UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS2_Pos 14UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS2_Msk 0x4000UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS3_Pos 15UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_PWM_SS3_Msk 0x8000UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_HWFILT_SS0_Pos 16UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_HWFILT_SS0_Msk 0x10000UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_HWFILT_SS1_Pos 17UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_HWFILT_SS1_Msk 0x20000UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_CLB_Pos    18UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_CLB_Msk    0x40000UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_CORDIC0_Pos 19UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_CORDIC0_Msk 0x80000UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_CORDIC1_Pos 20UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_CORDIC1_Msk 0x100000UL
#define PPCA_CNFG_DISPERI_DISPERI_CNFG_CODE_MEM_Pos 21UL
#define PPCA_CNFG_DISPERI_DISPERI_CNFG_CODE_MEM_Msk 0x200000UL
#define PPCA_CNFG_DISPERI_DISPERI_CNFG_DATA_MEM_Pos 22UL
#define PPCA_CNFG_DISPERI_DISPERI_CNFG_DATA_MEM_Msk 0x400000UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_M2_M3_M4_MEM_Pos 23UL
#define PPCA_CNFG_DISPERI_DISPERI_DS_M2_M3_M4_MEM_Msk 0x800000UL


/* PPCA_CNFG.CTRL */
#define PPCA_CNFG_CTRL_REMAP_MEM_Pos            0UL
#define PPCA_CNFG_CTRL_REMAP_MEM_Msk            0x1UL
#define PPCA_CNFG_CTRL_PPCA_EN_ACTRSTN_Pos      4UL
#define PPCA_CNFG_CTRL_PPCA_EN_ACTRSTN_Msk      0x10UL
#define PPCA_CNFG_CTRL_PPCA_EN_DEEPSLEEPRSTN_Pos 5UL
#define PPCA_CNFG_CTRL_PPCA_EN_DEEPSLEEPRSTN_Msk 0x20UL
#define PPCA_CNFG_CTRL_PPCA_CLK_SH_DWN_EN_Pos   8UL
#define PPCA_CNFG_CTRL_PPCA_CLK_SH_DWN_EN_Msk   0x100UL
#define PPCA_CNFG_CTRL_VDDA_OK_Pos              16UL
#define PPCA_CNFG_CTRL_VDDA_OK_Msk              0x10000UL
#define PPCA_CNFG_CTRL_FAULT_STATUS_Pos         20UL
#define PPCA_CNFG_CTRL_FAULT_STATUS_Msk         0x100000UL
#define PPCA_CNFG_CTRL_CPU0_HRESP_ERROR_ENABLE_Pos 21UL
#define PPCA_CNFG_CTRL_CPU0_HRESP_ERROR_ENABLE_Msk 0x200000UL
#define PPCA_CNFG_CTRL_CPU1_HRESP_ERROR_ENABLE_Pos 22UL
#define PPCA_CNFG_CTRL_CPU1_HRESP_ERROR_ENABLE_Msk 0x400000UL
#define PPCA_CNFG_CTRL_DDFT_OUT_EN_Pos          28UL
#define PPCA_CNFG_CTRL_DDFT_OUT_EN_Msk          0x10000000UL
#define PPCA_CNFG_CTRL_DDFT_IN_EN_Pos           29UL
#define PPCA_CNFG_CTRL_DDFT_IN_EN_Msk           0x20000000UL
#define PPCA_CNFG_CTRL_PPCA_EN_Pos              31UL
#define PPCA_CNFG_CTRL_PPCA_EN_Msk              0x80000000UL


/* PPCA_EPU_EPU_IRQ.INTR_SRCSEL */
#define PPCA_EPU_EPU_IRQ_INTR_SRCSEL_EPU_IRQ_SRCSEL_Pos 0UL
#define PPCA_EPU_EPU_IRQ_INTR_SRCSEL_EPU_IRQ_SRCSEL_Msk 0x7FUL
#define PPCA_EPU_EPU_IRQ_INTR_SRCSEL_BYPASS_EPU_IRQ_Pos 31UL
#define PPCA_EPU_EPU_IRQ_INTR_SRCSEL_BYPASS_EPU_IRQ_Msk 0x80000000UL
/* PPCA_EPU_EPU_IRQ.INTR */
#define PPCA_EPU_EPU_IRQ_INTR_EPU_INTR_Pos      0UL
#define PPCA_EPU_EPU_IRQ_INTR_EPU_INTR_Msk      0x1UL
/* PPCA_EPU_EPU_IRQ.INTR_SET */
#define PPCA_EPU_EPU_IRQ_INTR_SET_EPU_INTR_SET_Pos 0UL
#define PPCA_EPU_EPU_IRQ_INTR_SET_EPU_INTR_SET_Msk 0x1UL
/* PPCA_EPU_EPU_IRQ.INTR_MASK */
#define PPCA_EPU_EPU_IRQ_INTR_MASK_EPU_INTR_MASK_Pos 0UL
#define PPCA_EPU_EPU_IRQ_INTR_MASK_EPU_INTR_MASK_Msk 0x1UL
/* PPCA_EPU_EPU_IRQ.INTR_MASKED */
#define PPCA_EPU_EPU_IRQ_INTR_MASKED_EPU_INTR_MASKED_Pos 0UL
#define PPCA_EPU_EPU_IRQ_INTR_MASKED_EPU_INTR_MASKED_Msk 0x1UL


/* PPCA_EPU_EPU.PU_T1_CNFG */
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_EN_Pos     0UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_EN_Msk     0x3UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_POL_Pos    2UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_POL_Msk    0x4UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_IN_SEL_Pos 3UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_IN_SEL_Msk 0x8UL
#define PPCA_EPU_EPU_PU_T1_CNFG_OPCODE_Pos      4UL
#define PPCA_EPU_EPU_PU_T1_CNFG_OPCODE_Msk      0x30UL
#define PPCA_EPU_EPU_PU_T1_CNFG_DATA_Pos        6UL
#define PPCA_EPU_EPU_PU_T1_CNFG_DATA_Msk        0x1FC0UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_ENQ_Pos    13UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_ENQ_Msk    0x2000UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SEL_CONSTANT_IN_Pos 14UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SEL_CONSTANT_IN_Msk 0x4000UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_CONSTANT_IN_Pos 15UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_CONSTANT_IN_Msk 0x8000UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SRC_SEL_Pos 16UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SRC_SEL_Msk 0xFF0000UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SRCQ_SEL_Pos 24UL
#define PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SRCQ_SEL_Msk 0xFF000000UL
/* PPCA_EPU_EPU.PU_T2_CNFG */
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_EN_Pos     0UL
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_EN_Msk     0x3UL
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_POL_Pos    2UL
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_POL_Msk    0x4UL
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_IN_SEL_Pos 3UL
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_IN_SEL_Msk 0x8UL
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SEL_CONSTANT_IN_Pos 4UL
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SEL_CONSTANT_IN_Msk 0x10UL
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_CONSTANT_IN_Pos 5UL
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_CONSTANT_IN_Msk 0x20UL
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SRC_SEL_Pos 6UL
#define PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SRC_SEL_Msk 0x3FC0UL
/* PPCA_EPU_EPU.COMBO_CNFG */
#define PPCA_EPU_EPU_COMBO_CNFG_BANK_SEL_Pos    0UL
#define PPCA_EPU_EPU_COMBO_CNFG_BANK_SEL_Msk    0x7UL
#define PPCA_EPU_EPU_COMBO_CNFG_PUT1_IN_EN_Pos  3UL
#define PPCA_EPU_EPU_COMBO_CNFG_PUT1_IN_EN_Msk  0x18UL
#define PPCA_EPU_EPU_COMBO_CNFG_PU_SRC_IN_Pos   5UL
#define PPCA_EPU_EPU_COMBO_CNFG_PU_SRC_IN_Msk   0x1E0UL
#define PPCA_EPU_EPU_COMBO_CNFG_PU_SRC_IN_EN_Pos 9UL
#define PPCA_EPU_EPU_COMBO_CNFG_PU_SRC_IN_EN_Msk 0x600UL
#define PPCA_EPU_EPU_COMBO_CNFG_PU_IN_QUALIFIER_Pos 11UL
#define PPCA_EPU_EPU_COMBO_CNFG_PU_IN_QUALIFIER_Msk 0x3800UL
#define PPCA_EPU_EPU_COMBO_CNFG_PU_IN_QUALIFIER_EN_Pos 14UL
#define PPCA_EPU_EPU_COMBO_CNFG_PU_IN_QUALIFIER_EN_Msk 0x4000UL
#define PPCA_EPU_EPU_COMBO_CNFG_COMBO_POL_Pos   15UL
#define PPCA_EPU_EPU_COMBO_CNFG_COMBO_POL_Msk   0x8000UL
/* PPCA_EPU_EPU.COMBO_FB_CNFG */
#define PPCA_EPU_EPU_COMBO_FB_CNFG_COMBO_SRC_IN_Pos 0UL
#define PPCA_EPU_EPU_COMBO_FB_CNFG_COMBO_SRC_IN_Msk 0x7FUL


/* PPCA_EPU.CTRL */
#define PPCA_EPU_CTRL_EN_EXCLUSIVE_ACCESS_Pos   0UL
#define PPCA_EPU_CTRL_EN_EXCLUSIVE_ACCESS_Msk   0x1UL
#define PPCA_EPU_CTRL_EPU_EN_Pos                31UL
#define PPCA_EPU_CTRL_EPU_EN_Msk                0x80000000UL


/* PPCA_CPUSS_CNFG_MXCM33.CM33_CTL */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_CPU_WAIT_Pos 4UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_CPU_WAIT_Msk 0x10UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_LOCKNSVTOR_Pos 8UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_LOCKNSVTOR_Msk 0x100UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_LOCKSVTAIRCR_Pos 9UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_LOCKSVTAIRCR_Msk 0x200UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_LOCKSMPU_Pos 10UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_LOCKSMPU_Msk 0x400UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_LOCKNSMPU_Pos 11UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_LOCKNSMPU_Msk 0x800UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_LOCKSAU_Pos 12UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_LOCKSAU_Msk 0x1000UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_IOC_MASK_Pos 24UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_IOC_MASK_Msk 0x1000000UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_DZC_MASK_Pos 25UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_DZC_MASK_Msk 0x2000000UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_OFC_MASK_Pos 26UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_OFC_MASK_Msk 0x4000000UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_UFC_MASK_Pos 27UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_UFC_MASK_Msk 0x8000000UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_IXC_MASK_Pos 28UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_IXC_MASK_Msk 0x10000000UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_IDC_MASK_Pos 31UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_IDC_MASK_Msk 0x80000000UL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_CMD */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CMD_ENABLED_Pos 1UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CMD_ENABLED_Msk 0x2UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CMD_VECTKEYSTAT_Pos 16UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_CMD_VECTKEYSTAT_Msk 0xFFFF0000UL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_STATUS */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_STATUS_SLEEPING_Pos 0UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_STATUS_SLEEPING_Msk 0x1UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_STATUS_SLEEPDEEP_Pos 1UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_STATUS_SLEEPDEEP_Msk 0x2UL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_INT_STATUS */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_INT_STATUS_SYSTEM_INT_IDX_Pos 0UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_INT_STATUS_SYSTEM_INT_IDX_Msk 0x3FFUL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_INT_STATUS_SYSTEM_INT_VALID_Pos 31UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_INT_STATUS_SYSTEM_INT_VALID_Msk 0x80000000UL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_NMI_CTL */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_NMI_CTL_SYSTEM_INT_IDX_Pos 0UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_NMI_CTL_SYSTEM_INT_IDX_Msk 0x3FFUL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_EVENT_CTL */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_EVENT_CTL_MASK_Pos 0UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_EVENT_CTL_MASK_Msk 0x1FUL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_S_VECTOR_TABLE_BASE */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_S_VECTOR_TABLE_BASE_ADDR25_Pos 7UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_S_VECTOR_TABLE_BASE_ADDR25_Msk 0xFFFFFF80UL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_NS_VECTOR_TABLE_BASE */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_NS_VECTOR_TABLE_BASE_ADDR25_Pos 7UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_NS_VECTOR_TABLE_BASE_ADDR25_Msk 0xFFFFFF80UL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_PC_CTL */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_PC_CTL_VALID_Pos 0UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_PC_CTL_VALID_Msk 0xFUL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_PC0_HANDLER */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_PC0_HANDLER_ADDR_Pos 0UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_PC0_HANDLER_ADDR_Msk 0xFFFFFFFFUL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_PC1_HANDLER */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_PC1_HANDLER_ADDR_Pos 0UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_PC1_HANDLER_ADDR_Msk 0xFFFFFFFFUL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_PC2_HANDLER */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_PC2_HANDLER_ADDR_Pos 0UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_PC2_HANDLER_ADDR_Msk 0xFFFFFFFFUL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_PC3_HANDLER */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_PC3_HANDLER_ADDR_Pos 0UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_PC3_HANDLER_ADDR_Msk 0xFFFFFFFFUL
/* PPCA_CPUSS_CNFG_MXCM33.CM33_SYSTEM_INT_CTL */
#define PPCA_CPUSS_CNFG_MXCM33_CM33_SYSTEM_INT_CTL_CPU_INT_IDX_Pos 0UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_SYSTEM_INT_CTL_CPU_INT_IDX_Msk 0xFUL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_SYSTEM_INT_CTL_CPU_INT_VALID_Pos 31UL
#define PPCA_CPUSS_CNFG_MXCM33_CM33_SYSTEM_INT_CTL_CPU_INT_VALID_Msk 0x80000000UL


/* PPCA_CPUSS_CNFG_RAMC_MPC.CFG */
#define PPCA_CPUSS_CNFG_RAMC_MPC_CFG_RESPONSE_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_CFG_RESPONSE_Msk 0x10UL
/* PPCA_CPUSS_CNFG_RAMC_MPC.CTRL */
#define PPCA_CPUSS_CNFG_RAMC_MPC_CTRL_AUTO_INC_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_CTRL_AUTO_INC_Msk 0x100UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_CTRL_LOCK_Pos  31UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_CTRL_LOCK_Msk  0x80000000UL
/* PPCA_CPUSS_CNFG_RAMC_MPC.BLK_MAX */
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_MAX_VALUE_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_MAX_VALUE_Msk 0xFFFFFFFFUL
/* PPCA_CPUSS_CNFG_RAMC_MPC.BLK_CFG */
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_CFG_BLOCK_SIZE_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_CFG_BLOCK_SIZE_Msk 0xFUL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* PPCA_CPUSS_CNFG_RAMC_MPC.BLK_IDX */
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_IDX_VALUE_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_IDX_VALUE_Msk 0xFFFFFFFFUL
/* PPCA_CPUSS_CNFG_RAMC_MPC.BLK_LUT */
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS0_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS0_Msk 0x1UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS1_Pos 1UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS1_Msk 0x2UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS2_Pos 2UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS2_Msk 0x4UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS3_Pos 3UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS3_Msk 0x8UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS4_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS4_Msk 0x10UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS5_Pos 5UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS5_Msk 0x20UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS6_Pos 6UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS6_Msk 0x40UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS7_Pos 7UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS7_Msk 0x80UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS8_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS8_Msk 0x100UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS9_Pos 9UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS9_Msk 0x200UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS10_Pos 10UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS10_Msk 0x400UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS11_Pos 11UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS11_Msk 0x800UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS12_Pos 12UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS12_Msk 0x1000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS13_Pos 13UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS13_Msk 0x2000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS14_Pos 14UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS14_Msk 0x4000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS15_Pos 15UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS15_Msk 0x8000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS16_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS16_Msk 0x10000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS17_Pos 17UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS17_Msk 0x20000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS18_Pos 18UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS18_Msk 0x40000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS19_Pos 19UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS19_Msk 0x80000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS20_Pos 20UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS20_Msk 0x100000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS21_Pos 21UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS21_Msk 0x200000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS22_Pos 22UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS22_Msk 0x400000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS23_Pos 23UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS23_Msk 0x800000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS24_Pos 24UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS24_Msk 0x1000000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS25_Pos 25UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS25_Msk 0x2000000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS26_Pos 26UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS26_Msk 0x4000000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS27_Pos 27UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS27_Msk 0x8000000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS28_Pos 28UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS28_Msk 0x10000000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS29_Pos 29UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS29_Msk 0x20000000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS30_Pos 30UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS30_Msk 0x40000000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS31_Pos 31UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_BLK_LUT_ATTR_NS31_Msk 0x80000000UL
/* PPCA_CPUSS_CNFG_RAMC_MPC.ROT_CTRL */
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_CTRL_AUTO_INC_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_CTRL_AUTO_INC_Msk 0x100UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_CTRL_LOCK_Pos 31UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_CTRL_LOCK_Msk 0x80000000UL
/* PPCA_CPUSS_CNFG_RAMC_MPC.ROT_BLK_MAX */
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_MAX_VALUE_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_MAX_VALUE_Msk 0xFFFFFFFFUL
/* PPCA_CPUSS_CNFG_RAMC_MPC.ROT_BLK_CFG */
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_CFG_BLOCK_SIZE_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_CFG_BLOCK_SIZE_Msk 0xFUL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* PPCA_CPUSS_CNFG_RAMC_MPC.ROT_BLK_IDX */
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_IDX_VALUE_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_IDX_VALUE_Msk 0xFFFFFFFFUL
/* PPCA_CPUSS_CNFG_RAMC_MPC.ROT_BLK_PC */
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_PC_PC_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_PC_PC_Msk 0xFUL
/* PPCA_CPUSS_CNFG_RAMC_MPC.ROT_BLK_LUT */
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR0_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR0_Msk 0x7UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR1_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR1_Msk 0x70UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR2_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR2_Msk 0x700UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR3_Pos 12UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR3_Msk 0x7000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR4_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR4_Msk 0x70000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR5_Pos 20UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR5_Msk 0x700000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR6_Pos 24UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR6_Msk 0x7000000UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR7_Pos 28UL
#define PPCA_CPUSS_CNFG_RAMC_MPC_ROT_BLK_LUT_ATTR7_Msk 0x70000000UL


/* PPCA_CPUSS_CNFG_RAMC.CTL */
#define PPCA_CPUSS_CNFG_RAMC_CTL_SRAM_WS_Pos    0UL
#define PPCA_CPUSS_CNFG_RAMC_CTL_SRAM_WS_Msk    0x3UL
#define PPCA_CPUSS_CNFG_RAMC_CTL_CLOCK_FORCE_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_CTL_CLOCK_FORCE_Msk 0x10000UL
/* PPCA_CPUSS_CNFG_RAMC.STATUS */
#define PPCA_CPUSS_CNFG_RAMC_STATUS_WB_EMPTY_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_STATUS_WB_EMPTY_Msk 0x1UL
#define PPCA_CPUSS_CNFG_RAMC_STATUS_PWR_DONE_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_STATUS_PWR_DONE_Msk 0x10UL
/* PPCA_CPUSS_CNFG_RAMC.ECC_CTL */
#define PPCA_CPUSS_CNFG_RAMC_ECC_CTL_EN_Pos     0UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_CTL_EN_Msk     0x1UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_CTL_AUTO_CORRECT_Pos 1UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_CTL_AUTO_CORRECT_Msk 0x2UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_CTL_INJ_EN_Pos 2UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_CTL_INJ_EN_Msk 0x4UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_CTL_CHECK_EN_Pos 3UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_CTL_CHECK_EN_Msk 0x8UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_CTL_PARITY_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_CTL_PARITY_Msk 0x7F0000UL
/* PPCA_CPUSS_CNFG_RAMC.ECC_STATUS0 */
#define PPCA_CPUSS_CNFG_RAMC_ECC_STATUS0_ADDR_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_STATUS0_ADDR_Msk 0xFFFFFFFFUL
/* PPCA_CPUSS_CNFG_RAMC.ECC_STATUS1 */
#define PPCA_CPUSS_CNFG_RAMC_ECC_STATUS1_SYNDROME_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_STATUS1_SYNDROME_Msk 0x7FUL
/* PPCA_CPUSS_CNFG_RAMC.ECC_MATCH */
#define PPCA_CPUSS_CNFG_RAMC_ECC_MATCH_WORD_ADDR_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_ECC_MATCH_WORD_ADDR_Msk 0x1FFFFFFUL
/* PPCA_CPUSS_CNFG_RAMC.PWR_MACRO_CTL */
#define PPCA_CPUSS_CNFG_RAMC_PWR_MACRO_CTL_OFF_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PWR_MACRO_CTL_OFF_Msk 0xFFFFFFFFUL
/* PPCA_CPUSS_CNFG_RAMC.PWR_MACRO_CTL_LOCK */
#define PPCA_CPUSS_CNFG_RAMC_PWR_MACRO_CTL_LOCK_PWR_MACRO_CTL_LOCK_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PWR_MACRO_CTL_LOCK_PWR_MACRO_CTL_LOCK_Msk 0x3UL
/* PPCA_CPUSS_CNFG_RAMC.PWR_DELAY_CTL */
#define PPCA_CPUSS_CNFG_RAMC_PWR_DELAY_CTL_UP_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PWR_DELAY_CTL_UP_Msk 0x3FFUL
#define PPCA_CPUSS_CNFG_RAMC_PWR_DELAY_CTL_SEQ0_DELAY_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_PWR_DELAY_CTL_SEQ0_DELAY_Msk 0xFF0000UL
#define PPCA_CPUSS_CNFG_RAMC_PWR_DELAY_CTL_SEQ1_DELAY_Pos 24UL
#define PPCA_CPUSS_CNFG_RAMC_PWR_DELAY_CTL_SEQ1_DELAY_Msk 0xFF000000UL


/* PPCA_CPUSS_CNFG_RAMC_PPU.PWPR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWPR_PWR_POLICY_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWPR_PWR_POLICY_Msk 0xFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWPR_PWR_DYN_EN_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWPR_PWR_DYN_EN_Msk 0x100UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWPR_LOCK_EN_Pos 12UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWPR_LOCK_EN_Msk 0x1000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWPR_OP_POLICY_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWPR_OP_POLICY_Msk 0xF0000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWPR_OP_DYN_EN_Pos 24UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWPR_OP_DYN_EN_Msk 0x1000000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.PMER */
#define PPCA_CPUSS_CNFG_RAMC_PPU_PMER_EMU_EN_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PMER_EMU_EN_Msk 0x1UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.PWSR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWSR_PWR_STATUS_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWSR_PWR_STATUS_Msk 0xFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWSR_PWR_DYN_STATUS_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWSR_PWR_DYN_STATUS_Msk 0x100UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWSR_LOCK_STATUS_Pos 12UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWSR_LOCK_STATUS_Msk 0x1000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWSR_OP_STATUS_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWSR_OP_STATUS_Msk 0xF0000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWSR_OP_DYN_STATUS_Pos 24UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWSR_OP_DYN_STATUS_Msk 0x1000000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.DISR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_DISR_PWR_DEVACTIVE_STATUS_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_DISR_PWR_DEVACTIVE_STATUS_Msk 0x7FFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_DISR_OP_DEVACTIVE_STATUS_Pos 24UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_DISR_OP_DEVACTIVE_STATUS_Msk 0xFF000000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.MISR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_MISR_PCSMPACCEPT_STATUS_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_MISR_PCSMPACCEPT_STATUS_Msk 0x1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_MISR_DEVACCEPT_STATUS_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_MISR_DEVACCEPT_STATUS_Msk 0xFF00UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_MISR_DEVDENY_STATUS_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_MISR_DEVDENY_STATUS_Msk 0xFF0000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.STSR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_STSR_STORED_DEVDENY_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_STSR_STORED_DEVDENY_Msk 0xFFUL
/* PPCA_CPUSS_CNFG_RAMC_PPU.UNLK */
#define PPCA_CPUSS_CNFG_RAMC_PPU_UNLK_UNLOCK_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_UNLK_UNLOCK_Msk 0x1UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.PWCR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWCR_DEVREQEN_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWCR_DEVREQEN_Msk 0xFFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWCR_PWR_DEVACTIVEEN_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWCR_PWR_DEVACTIVEEN_Msk 0x7FF00UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWCR_OP_DEVACTIVEEN_Pos 24UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PWCR_OP_DEVACTIVEEN_Msk 0xFF000000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.PTCR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_PTCR_WARM_RST_DEVREQEN_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PTCR_WARM_RST_DEVREQEN_Msk 0x1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PTCR_DBG_RECOV_PORST_EN_Pos 1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PTCR_DBG_RECOV_PORST_EN_Msk 0x2UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.IMR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_STA_POLICY_TRN_IRQ_MASK_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_STA_POLICY_TRN_IRQ_MASK_Msk 0x1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_STA_ACCEPT_IRQ_MASK_Pos 1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_STA_ACCEPT_IRQ_MASK_Msk 0x2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_STA_DENY_IRQ_MASK_Pos 2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_STA_DENY_IRQ_MASK_Msk 0x4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_EMU_ACCEPT_IRQ_MASK_Pos 3UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_EMU_ACCEPT_IRQ_MASK_Msk 0x8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_EMU_DENY_IRQ_MASK_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_EMU_DENY_IRQ_MASK_Msk 0x10UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_LOCKED_IRQ_MASK_Pos 5UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IMR_LOCKED_IRQ_MASK_Msk 0x20UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.AIMR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIMR_UNSPT_POLICY_IRQ_MASK_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIMR_UNSPT_POLICY_IRQ_MASK_Msk 0x1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIMR_DYN_ACCEPT_IRQ_MASK_Pos 1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIMR_DYN_ACCEPT_IRQ_MASK_Msk 0x2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIMR_DYN_DENY_IRQ_MASK_Pos 2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIMR_DYN_DENY_IRQ_MASK_Msk 0x4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIMR_STA_POLICY_PWR_IRQ_MASK_Pos 3UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIMR_STA_POLICY_PWR_IRQ_MASK_Msk 0x8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIMR_STA_POLICY_OP_IRQ_MASK_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIMR_STA_POLICY_OP_IRQ_MASK_Msk 0x10UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.ISR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_STA_POLICY_TRN_IRQ_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_STA_POLICY_TRN_IRQ_Msk 0x1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_STA_ACCEPT_IRQ_Pos 1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_STA_ACCEPT_IRQ_Msk 0x2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_STA_DENY_IRQ_Pos 2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_STA_DENY_IRQ_Msk 0x4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_EMU_ACCEPT_IRQ_Pos 3UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_EMU_ACCEPT_IRQ_Msk 0x8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_EMU_DENY_IRQ_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_EMU_DENY_IRQ_Msk 0x10UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_LOCKED_IRQ_Pos 5UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_LOCKED_IRQ_Msk 0x20UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_OTHER_IRQ_Pos 7UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_OTHER_IRQ_Msk 0x80UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_PWR_ACTIVE_EDGE_IRQ_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_PWR_ACTIVE_EDGE_IRQ_Msk 0x7FF00UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_OP_ACTIVE_EDGE_IRQ_Pos 24UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ISR_OP_ACTIVE_EDGE_IRQ_Msk 0xFF000000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.AISR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_AISR_UNSPT_POLICY_IRQ_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AISR_UNSPT_POLICY_IRQ_Msk 0x1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AISR_DYN_ACCEPT_IRQ_Pos 1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AISR_DYN_ACCEPT_IRQ_Msk 0x2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AISR_DYN_DENY_IRQ_Pos 2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AISR_DYN_DENY_IRQ_Msk 0x4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AISR_STA_POLICY_PWR_IRQ_Pos 3UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AISR_STA_POLICY_PWR_IRQ_Msk 0x8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AISR_STA_POLICY_OP_IRQ_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AISR_STA_POLICY_OP_IRQ_Msk 0x10UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.IESR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE00_EDGE_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE00_EDGE_Msk 0x3UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE01_EDGE_Pos 2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE01_EDGE_Msk 0xCUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE02_EDGE_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE02_EDGE_Msk 0x30UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE03_EDGE_Pos 6UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE03_EDGE_Msk 0xC0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE04_EDGE_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE04_EDGE_Msk 0x300UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE05_EDGE_Pos 10UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE05_EDGE_Msk 0xC00UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE06_EDGE_Pos 12UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE06_EDGE_Msk 0x3000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE07_EDGE_Pos 14UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE07_EDGE_Msk 0xC000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE08_EDGE_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE08_EDGE_Msk 0x30000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE09_EDGE_Pos 18UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE09_EDGE_Msk 0xC0000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE10_EDGE_Pos 20UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IESR_DEVACTIVE10_EDGE_Msk 0x300000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.OPSR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE16_EDGE_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE16_EDGE_Msk 0x3UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE17_EDGE_Pos 2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE17_EDGE_Msk 0xCUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE18_EDGE_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE18_EDGE_Msk 0x30UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE19_EDGE_Pos 6UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE19_EDGE_Msk 0xC0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE20_EDGE_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE20_EDGE_Msk 0x300UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE21_EDGE_Pos 10UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE21_EDGE_Msk 0xC00UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE22_EDGE_Pos 12UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE22_EDGE_Msk 0x3000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE23_EDGE_Pos 14UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_OPSR_DEVACTIVE23_EDGE_Msk 0xC000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.FUNRR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_FUNRR_FUNC_RET_RAM_CFG_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_FUNRR_FUNC_RET_RAM_CFG_Msk 0xFFUL
/* PPCA_CPUSS_CNFG_RAMC_PPU.FULRR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_FULRR_FULL_RET_RAM_CFG_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_FULRR_FULL_RET_RAM_CFG_Msk 0xFFUL
/* PPCA_CPUSS_CNFG_RAMC_PPU.MEMRR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_MEMRR_MEM_RET_RAM_CFG_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_MEMRR_MEM_RET_RAM_CFG_Msk 0xFFUL
/* PPCA_CPUSS_CNFG_RAMC_PPU.EDTR0 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR0_OFF_DEL_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR0_OFF_DEL_Msk 0xFFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR0_MEM_RET_DEL_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR0_MEM_RET_DEL_Msk 0xFF00UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR0_LOGIC_RET_DEL_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR0_LOGIC_RET_DEL_Msk 0xFF0000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR0_FULL_RET_DEL_Pos 24UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR0_FULL_RET_DEL_Msk 0xFF000000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.EDTR1 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR1_MEM_OFF_DEL_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR1_MEM_OFF_DEL_Msk 0xFFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR1_FUNC_RET_DEL_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_EDTR1_FUNC_RET_DEL_Msk 0xFF00UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.DCDR0 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_DCDR0_CLKEN_RST_DLY_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_DCDR0_CLKEN_RST_DLY_Msk 0xFFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_DCDR0_ISO_CLKEN_DLY_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_DCDR0_ISO_CLKEN_DLY_Msk 0xFF00UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_DCDR0_RST_HWSTAT_DLY_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_DCDR0_RST_HWSTAT_DLY_Msk 0xFF0000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.DCDR1 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_DCDR1_ISO_RST_DLY_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_DCDR1_ISO_RST_DLY_Msk 0xFFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_DCDR1_CLKEN_ISO_DLY_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_DCDR1_CLKEN_ISO_DLY_Msk 0xFF00UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.IDR0 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DEVCHAN_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DEVCHAN_Msk 0xFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_NUM_OPMODE_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_NUM_OPMODE_Msk 0xF0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_OFF_SPT_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_OFF_SPT_Msk 0x100UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_OFF_EMU_SPT_Pos 9UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_OFF_EMU_SPT_Msk 0x200UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_MEM_RET_SPT_Pos 10UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_MEM_RET_SPT_Msk 0x400UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_MEM_RET_EMU_SPT_Pos 11UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_MEM_RET_EMU_SPT_Msk 0x800UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_LGC_RET_SPT_Pos 12UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_LGC_RET_SPT_Msk 0x1000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_MEM_OFF_SPT_Pos 13UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_MEM_OFF_SPT_Msk 0x2000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_FULL_RET_SPT_Pos 14UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_FULL_RET_SPT_Msk 0x4000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_FUNC_RET_SPT_Pos 15UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_FUNC_RET_SPT_Msk 0x8000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_ON_SPT_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_ON_SPT_Msk 0x10000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_WRM_RST_SPT_Pos 17UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_WRM_RST_SPT_Msk 0x20000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_DBG_RECOV_SPT_Pos 18UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_STA_DBG_RECOV_SPT_Msk 0x40000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_OFF_SPT_Pos 20UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_OFF_SPT_Msk 0x100000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_OFF_EMU_SPT_Pos 21UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_OFF_EMU_SPT_Msk 0x200000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_MEM_RET_SPT_Pos 22UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_MEM_RET_SPT_Msk 0x400000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_MEM_RET_EMU_SPT_Pos 23UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_MEM_RET_EMU_SPT_Msk 0x800000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_LGC_RET_SPT_Pos 24UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_LGC_RET_SPT_Msk 0x1000000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_MEM_OFF_SPT_Pos 25UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_MEM_OFF_SPT_Msk 0x2000000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_FULL_RET_SPT_Pos 26UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_FULL_RET_SPT_Msk 0x4000000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_FUNC_RET_SPT_Pos 27UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_FUNC_RET_SPT_Msk 0x8000000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_ON_SPT_Pos 28UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_ON_SPT_Msk 0x10000000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_WRM_RST_SPT_Pos 29UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR0_DYN_WRM_RST_SPT_Msk 0x20000000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.IDR1 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_PWR_MODE_ENTRY_DEL_SPT_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_PWR_MODE_ENTRY_DEL_SPT_Msk 0x1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_SW_DEV_DEL_SPT_Pos 1UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_SW_DEV_DEL_SPT_Msk 0x2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_LOCK_SPT_Pos 2UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_LOCK_SPT_Msk 0x4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_MEM_RET_RAM_REG_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_MEM_RET_RAM_REG_Msk 0x10UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_FULL_RET_RAM_REG_Pos 5UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_FULL_RET_RAM_REG_Msk 0x20UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_FUNC_RET_RAM_REG_Pos 6UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_FUNC_RET_RAM_REG_Msk 0x40UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_STA_POLICY_PWR_IRQ_SPT_Pos 8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_STA_POLICY_PWR_IRQ_SPT_Msk 0x100UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_STA_POLICY_OP_IRQ_SPT_Pos 9UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_STA_POLICY_OP_IRQ_SPT_Msk 0x200UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_OP_ACTIVE_Pos 10UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_OP_ACTIVE_Msk 0x400UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_OFF_MEM_RET_TRANS_Pos 12UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IDR1_OFF_MEM_RET_TRANS_Msk 0x1000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.IIDR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_IIDR_IMPLEMENTER_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IIDR_IMPLEMENTER_Msk 0xFFFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IIDR_REVISION_Pos 12UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IIDR_REVISION_Msk 0xF000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IIDR_VARIANT_Pos 16UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IIDR_VARIANT_Msk 0xF0000UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IIDR_PRODUCT_ID_Pos 20UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_IIDR_PRODUCT_ID_Msk 0xFFF00000UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.AIDR */
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIDR_ARCH_REV_MINOR_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIDR_ARCH_REV_MINOR_Msk 0xFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIDR_ARCH_REV_MAJOR_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_AIDR_ARCH_REV_MAJOR_Msk 0xF0UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.PID4 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID4_IMPLEMENTER_11_8_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID4_IMPLEMENTER_11_8_Msk 0xFUL
/* PPCA_CPUSS_CNFG_RAMC_PPU.PID0 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID0_PRODUCT_ID_7_0_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID0_PRODUCT_ID_7_0_Msk 0xFFUL
/* PPCA_CPUSS_CNFG_RAMC_PPU.PID1 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID1_PRODUCT_ID_11_8_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID1_PRODUCT_ID_11_8_Msk 0xFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID1_IMPLEMENTER_3_0_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID1_IMPLEMENTER_3_0_Msk 0xF0UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.PID2 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID2_IMPLEMENTER_6_4_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID2_IMPLEMENTER_6_4_Msk 0x7UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID2_CONST_HIGH_Pos 3UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID2_CONST_HIGH_Msk 0x8UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID2_REV_CONST_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID2_REV_CONST_Msk 0xF0UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.PID3 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID3_PID3_REV_CONST_Pos 0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID3_PID3_REV_CONST_Msk 0xFUL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID3_PID3_REVISION_Pos 4UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_PID3_PID3_REVISION_Msk 0xF0UL
/* PPCA_CPUSS_CNFG_RAMC_PPU.ID0 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_ID0_ID0_Pos    0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ID0_ID0_Msk    0xFFUL
/* PPCA_CPUSS_CNFG_RAMC_PPU.ID1 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_ID1_ID1_Pos    0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ID1_ID1_Msk    0xFFUL
/* PPCA_CPUSS_CNFG_RAMC_PPU.ID2 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_ID2_ID2_Pos    0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ID2_ID2_Msk    0xFFUL
/* PPCA_CPUSS_CNFG_RAMC_PPU.ID3 */
#define PPCA_CPUSS_CNFG_RAMC_PPU_ID3_ID3_Pos    0UL
#define PPCA_CPUSS_CNFG_RAMC_PPU_ID3_ID3_Msk    0xFFUL


/* PPCA_CPUSS_CNFG.AP_CTL */
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_ENABLE_Pos 0UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_ENABLE_Msk 0x1UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_ENABLE_Pos 1UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_ENABLE_Msk 0x2UL
#define PPCA_CPUSS_CNFG_AP_CTL_SYS_ENABLE_Pos   2UL
#define PPCA_CPUSS_CNFG_AP_CTL_SYS_ENABLE_Msk   0x4UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_DBG_ENABLE_Pos 4UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_DBG_ENABLE_Msk 0x10UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_NID_ENABLE_Pos 5UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_NID_ENABLE_Msk 0x20UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_DBG_ENABLE_Pos 8UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_DBG_ENABLE_Msk 0x100UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_NID_ENABLE_Pos 9UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_NID_ENABLE_Msk 0x200UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_DISABLE_Pos 16UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_DISABLE_Msk 0x10000UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_DISABLE_Pos 17UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_DISABLE_Msk 0x20000UL
#define PPCA_CPUSS_CNFG_AP_CTL_SYS_DISABLE_Pos  18UL
#define PPCA_CPUSS_CNFG_AP_CTL_SYS_DISABLE_Msk  0x40000UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_DBG_DISABLE_Pos 20UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_DBG_DISABLE_Msk 0x100000UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_NID_DISABLE_Pos 21UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_0_NID_DISABLE_Msk 0x200000UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_DBG_DISABLE_Pos 24UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_DBG_DISABLE_Msk 0x1000000UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_NID_DISABLE_Pos 25UL
#define PPCA_CPUSS_CNFG_AP_CTL_CM33_1_NID_DISABLE_Msk 0x2000000UL
/* PPCA_CPUSS_CNFG.MP_CTL */
#define PPCA_CPUSS_CNFG_MP_CTL_PPCA_MS_TIMEOUT_ENABLE_Pos 0UL
#define PPCA_CPUSS_CNFG_MP_CTL_PPCA_MS_TIMEOUT_ENABLE_Msk 0x1UL


/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.CTRL */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CTRL_FILTER_EN_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CTRL_FILTER_EN_Msk 0x1UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CTRL_FILTER_BUSY_Pos 1UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CTRL_FILTER_BUSY_Msk 0x2UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.DATA_IN0 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_IN0_DIN0_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_IN0_DIN0_Msk 0xFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_IN0_SIGN_EXTEND_DIN0_Pos 16UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_IN0_SIGN_EXTEND_DIN0_Msk 0xFFFF0000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.DATA_IN1 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_IN1_DIN1_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_IN1_DIN1_Msk 0xFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_IN1_SIGN_EXTEND_DIN1_Pos 16UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_IN1_SIGN_EXTEND_DIN1_Msk 0xFFFF0000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.CNFG */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_SRC_SEL_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_SRC_SEL_Msk 0x1UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG0_Pos 1UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG0_Msk 0x2UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG1_Pos 2UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG1_Msk 0x4UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.CX0 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX0_CX0_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX0_CX0_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX0_SIGN_EXTEND_CX0_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX0_SIGN_EXTEND_CX0_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.CX1 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX1_CX1_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX1_CX1_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX1_SIGN_EXTEND_CX1_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX1_SIGN_EXTEND_CX1_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.CX2 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX2_CX2_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX2_CX2_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX2_SIGN_EXTEND_CX2_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX2_SIGN_EXTEND_CX2_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.CX3 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX3_CX3_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX3_CX3_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX3_SIGN_EXTEND_CX3_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CX3_SIGN_EXTEND_CX3_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.CY1 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY1_CY1_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY1_CY1_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY1_SIGN_EXTEND_CY1_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY1_SIGN_EXTEND_CY1_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.CY2 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY2_CY2_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY2_CY2_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY2_SIGN_EXTEND_CY2_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY2_SIGN_EXTEND_CY2_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.CY3 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY3_CY3_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY3_CY3_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY3_SIGN_EXTEND_CY3_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CY3_SIGN_EXTEND_CY3_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.DATA_OUT */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_OUT_DATA_OUT_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_OUT_DATA_OUT_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_OUT_SIGN_EXT_DATA_OUT_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_DATA_OUT_SIGN_EXT_DATA_OUT_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.OFFSET */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_OFFSET_DATA_OFFSET_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_OFFSET_DATA_OFFSET_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_OFFSET_SIGN_EXT_DATA_OFFSET_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_OFFSET_SIGN_EXT_DATA_OFFSET_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.LIMMAX */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_LIMMAX_LMAX_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_LIMMAX_LMAX_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_LIMMAX_SIGN_EXT_LMAX_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_LIMMAX_SIGN_EXT_LMAX_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.LIMMIN */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_LIMMIN_LMIN_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_LIMMIN_LMIN_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_LIMMIN_SIGN_EXT_LMIN_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_LIMMIN_SIGN_EXT_LMIN_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.SCALECX */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_SCALECX_SCALE_CX_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_SCALECX_SCALE_CX_Msk 0x7UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.SCALECY */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_SCALECY_SCALE_CY_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_SCALECY_SCALE_CY_Msk 0x7UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.GIN */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_GIN_G_IN_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_GIN_G_IN_Msk 0x3UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.GOUT */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_GOUT_G_OUT_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_GOUT_G_OUT_Msk 0x7UL
/* PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z.VERSION */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_VERSION_VERSION_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_VERSION_VERSION_Msk 0xFFFFFFFFUL


/* PPCA_HWFILT3P3Z_SS_0.CTRL */
#define PPCA_HWFILT3P3Z_SS_0_CTRL_HWFILT3P3Z_EN_Pos 31UL
#define PPCA_HWFILT3P3Z_SS_0_CTRL_HWFILT3P3Z_EN_Msk 0x80000000UL


/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.CTRL */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CTRL_FILTER_EN_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CTRL_FILTER_EN_Msk 0x1UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CTRL_FILTER_BUSY_Pos 1UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CTRL_FILTER_BUSY_Msk 0x2UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.DATA_IN0 */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_IN0_DIN0_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_IN0_DIN0_Msk 0xFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_IN0_SIGN_EXTEND_DIN0_Pos 16UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_IN0_SIGN_EXTEND_DIN0_Msk 0xFFFF0000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.DATA_IN1 */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_IN1_DIN1_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_IN1_DIN1_Msk 0xFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_IN1_SIGN_EXTEND_DIN1_Pos 16UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_IN1_SIGN_EXTEND_DIN1_Msk 0xFFFF0000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.CNFG */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CNFG_SRC_SEL_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CNFG_SRC_SEL_Msk 0x1UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CNFG_EN_TRIG0_Pos 1UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CNFG_EN_TRIG0_Msk 0x2UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CNFG_EN_TRIG1_Pos 2UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CNFG_EN_TRIG1_Msk 0x4UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.CX0 */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX0_CX0_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX0_CX0_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX0_SIGN_EXTEND_CX0_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX0_SIGN_EXTEND_CX0_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.CX1 */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX1_CX1_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX1_CX1_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX1_SIGN_EXTEND_CX1_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX1_SIGN_EXTEND_CX1_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.CX2 */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX2_CX2_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX2_CX2_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX2_SIGN_EXTEND_CX2_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX2_SIGN_EXTEND_CX2_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.CX3 */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX3_CX3_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX3_CX3_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX3_SIGN_EXTEND_CX3_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CX3_SIGN_EXTEND_CX3_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.CY1 */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY1_CY1_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY1_CY1_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY1_SIGN_EXTEND_CY1_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY1_SIGN_EXTEND_CY1_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.CY2 */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY2_CY2_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY2_CY2_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY2_SIGN_EXTEND_CY2_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY2_SIGN_EXTEND_CY2_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.CY3 */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY3_CY3_DATA_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY3_CY3_DATA_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY3_SIGN_EXTEND_CY3_DATA_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_CY3_SIGN_EXTEND_CY3_DATA_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.DATA_OUT */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_OUT_DATA_OUT_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_OUT_DATA_OUT_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_OUT_SIGN_EXT_DATA_OUT_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_DATA_OUT_SIGN_EXT_DATA_OUT_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.OFFSET */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_OFFSET_DATA_OFFSET_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_OFFSET_DATA_OFFSET_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_OFFSET_SIGN_EXT_DATA_OFFSET_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_OFFSET_SIGN_EXT_DATA_OFFSET_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.LIMMAX */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_LIMMAX_LMAX_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_LIMMAX_LMAX_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_LIMMAX_SIGN_EXT_LMAX_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_LIMMAX_SIGN_EXT_LMAX_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.LIMMIN */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_LIMMIN_LMIN_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_LIMMIN_LMIN_Msk 0xFFFFFFUL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_LIMMIN_SIGN_EXT_LMIN_Pos 24UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_LIMMIN_SIGN_EXT_LMIN_Msk 0xFF000000UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.SCALECX */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_SCALECX_SCALE_CX_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_SCALECX_SCALE_CX_Msk 0x7UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.SCALECY */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_SCALECY_SCALE_CY_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_SCALECY_SCALE_CY_Msk 0x7UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.GIN */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_GIN_G_IN_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_GIN_G_IN_Msk 0x3UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.GOUT */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_GOUT_G_OUT_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_GOUT_G_OUT_Msk 0x7UL
/* PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z.VERSION */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_VERSION_VERSION_Pos 0UL
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_VERSION_VERSION_Msk 0xFFFFFFFFUL


/* PPCA_HWFILT3P3Z_SS_1.CTRL */
#define PPCA_HWFILT3P3Z_SS_1_CTRL_HWFILT3P3Z_EN_Pos 31UL
#define PPCA_HWFILT3P3Z_SS_1_CTRL_HWFILT3P3Z_EN_Msk 0x80000000UL


/* PPCA_ADCM_ADCM.ADC_DATA */
#define PPCA_ADCM_ADCM_ADC_DATA_ADC_DATA_Pos    0UL
#define PPCA_ADCM_ADCM_ADC_DATA_ADC_DATA_Msk    0xFFFFFFFFUL


/* PPCA_CLB_DICO.CTRL */
#define PPCA_CLB_DICO_CTRL_EN_PH1_Pos           0UL
#define PPCA_CLB_DICO_CTRL_EN_PH1_Msk           0x1UL
#define PPCA_CLB_DICO_CTRL_EN_PH2_Pos           1UL
#define PPCA_CLB_DICO_CTRL_EN_PH2_Msk           0x2UL
#define PPCA_CLB_DICO_CTRL_EN_PH3_Pos           2UL
#define PPCA_CLB_DICO_CTRL_EN_PH3_Msk           0x4UL
#define PPCA_CLB_DICO_CTRL_PE_EN_Pos            4UL
#define PPCA_CLB_DICO_CTRL_PE_EN_Msk            0x10UL
#define PPCA_CLB_DICO_CTRL_USER_BITS_Pos        8UL
#define PPCA_CLB_DICO_CTRL_USER_BITS_Msk        0x3FF00UL
#define PPCA_CLB_DICO_CTRL_EN_Pos               31UL
#define PPCA_CLB_DICO_CTRL_EN_Msk               0x80000000UL
/* PPCA_CLB_DICO.CNFG */
#define PPCA_CLB_DICO_CNFG_SEL_VAC_Pos          0UL
#define PPCA_CLB_DICO_CNFG_SEL_VAC_Msk          0x7UL
#define PPCA_CLB_DICO_CNFG_SEL_VBUS_Pos         3UL
#define PPCA_CLB_DICO_CNFG_SEL_VBUS_Msk         0x38UL
#define PPCA_CLB_DICO_CNFG_SEL_IL1_Pos          6UL
#define PPCA_CLB_DICO_CNFG_SEL_IL1_Msk          0x1C0UL
#define PPCA_CLB_DICO_CNFG_SEL_IL2_Pos          9UL
#define PPCA_CLB_DICO_CNFG_SEL_IL2_Msk          0xE00UL
#define PPCA_CLB_DICO_CNFG_SEL_IL3_Pos          12UL
#define PPCA_CLB_DICO_CNFG_SEL_IL3_Msk          0x7000UL
#define PPCA_CLB_DICO_CNFG_NUM_OF_MEAS_PERIOD_Pos 15UL
#define PPCA_CLB_DICO_CNFG_NUM_OF_MEAS_PERIOD_Msk 0x18000UL
#define PPCA_CLB_DICO_CNFG_PWM_DEADTIME_Pos     17UL
#define PPCA_CLB_DICO_CNFG_PWM_DEADTIME_Msk     0xFE0000UL
#define PPCA_CLB_DICO_CNFG_PE_SKIP_SLOPE_Pos    24UL
#define PPCA_CLB_DICO_CNFG_PE_SKIP_SLOPE_Msk    0x1000000UL
#define PPCA_CLB_DICO_CNFG_PE_IDLE1_RECAL_SLOPE_Pos 25UL
#define PPCA_CLB_DICO_CNFG_PE_IDLE1_RECAL_SLOPE_Msk 0x2000000UL
#define PPCA_CLB_DICO_CNFG_MONITOR_SEL_Pos      26UL
#define PPCA_CLB_DICO_CNFG_MONITOR_SEL_Msk      0x1C000000UL
#define PPCA_CLB_DICO_CNFG_ONLY_CORR_CHARG_Pos  29UL
#define PPCA_CLB_DICO_CNFG_ONLY_CORR_CHARG_Msk  0x20000000UL
/* PPCA_CLB_DICO.EVENT */
#define PPCA_CLB_DICO_EVENT_KILL_EVENT_Pos      0UL
#define PPCA_CLB_DICO_EVENT_KILL_EVENT_Msk      0x1UL
#define PPCA_CLB_DICO_EVENT_KILL_EXIT_Pos       1UL
#define PPCA_CLB_DICO_EVENT_KILL_EXIT_Msk       0x2UL
/* PPCA_CLB_DICO.SAFE */
#define PPCA_CLB_DICO_SAFE_STATE_Pos            0UL
#define PPCA_CLB_DICO_SAFE_STATE_Msk            0x3FUL
#define PPCA_CLB_DICO_SAFE_MAX_ON_TIME_Pos      6UL
#define PPCA_CLB_DICO_SAFE_MAX_ON_TIME_Msk      0x3FFC0UL
#define PPCA_CLB_DICO_SAFE_MIN_ON_TIME_Pos      18UL
#define PPCA_CLB_DICO_SAFE_MIN_ON_TIME_Msk      0x3FFC0000UL
/* PPCA_CLB_DICO.IMAXL */
#define PPCA_CLB_DICO_IMAXL_IMAXL_Pos           0UL
#define PPCA_CLB_DICO_IMAXL_IMAXL_Msk           0xFFFFFFUL
#define PPCA_CLB_DICO_IMAXL_SIGN_EXTENDED_IMAXL_Pos 24UL
#define PPCA_CLB_DICO_IMAXL_SIGN_EXTENDED_IMAXL_Msk 0xFF000000UL
/* PPCA_CLB_DICO.IMINL */
#define PPCA_CLB_DICO_IMINL_IMINL_Pos           0UL
#define PPCA_CLB_DICO_IMINL_IMINL_Msk           0xFFFFFFUL
#define PPCA_CLB_DICO_IMINL_SIGN_EXTENDED_IMINL_Pos 24UL
#define PPCA_CLB_DICO_IMINL_SIGN_EXTENDED_IMINL_Msk 0xFF000000UL
/* PPCA_CLB_DICO.VAC_POL */
#define PPCA_CLB_DICO_VAC_POL_POL_Pos           0UL
#define PPCA_CLB_DICO_VAC_POL_POL_Msk           0x3UL
/* PPCA_CLB_DICO.OBS_CTRL */
#define PPCA_CLB_DICO_OBS_CTRL_FROZEN_INFO_PH1_Pos 0UL
#define PPCA_CLB_DICO_OBS_CTRL_FROZEN_INFO_PH1_Msk 0x1UL
#define PPCA_CLB_DICO_OBS_CTRL_FROZEN_INFO_PH2_Pos 1UL
#define PPCA_CLB_DICO_OBS_CTRL_FROZEN_INFO_PH2_Msk 0x2UL
#define PPCA_CLB_DICO_OBS_CTRL_FROZEN_INFO_PH3_Pos 2UL
#define PPCA_CLB_DICO_OBS_CTRL_FROZEN_INFO_PH3_Msk 0x4UL
/* PPCA_CLB_DICO.PERIOD_MEAS */
#define PPCA_CLB_DICO_PERIOD_MEAS_PERIOD_Pos    0UL
#define PPCA_CLB_DICO_PERIOD_MEAS_PERIOD_Msk    0xFFFUL
/* PPCA_CLB_DICO.IEST_IND_ACCU */
#define PPCA_CLB_DICO_IEST_IND_ACCU_IEST_IND_ACCU_Pos 0UL
#define PPCA_CLB_DICO_IEST_IND_ACCU_IEST_IND_ACCU_Msk 0xFFFFFFFFUL
/* PPCA_CLB_DICO.IL_ACCU */
#define PPCA_CLB_DICO_IL_ACCU_IL_ACCU_Pos       0UL
#define PPCA_CLB_DICO_IL_ACCU_IL_ACCU_Msk       0xFFFFFFFFUL
/* PPCA_CLB_DICO.IEST_CORR */
#define PPCA_CLB_DICO_IEST_CORR_IEST_CORR_Pos   0UL
#define PPCA_CLB_DICO_IEST_CORR_IEST_CORR_Msk   0xFFFUL
#define PPCA_CLB_DICO_IEST_CORR_SIGN_EXTENDED_IEST_CORR_Pos 12UL
#define PPCA_CLB_DICO_IEST_CORR_SIGN_EXTENDED_IEST_CORR_Msk 0xFFFFF000UL
/* PPCA_CLB_DICO.PE_IMINL */
#define PPCA_CLB_DICO_PE_IMINL_PE_IMINL_Pos     0UL
#define PPCA_CLB_DICO_PE_IMINL_PE_IMINL_Msk     0xFFFFFFFFUL
/* PPCA_CLB_DICO.PE_IMAXL */
#define PPCA_CLB_DICO_PE_IMAXL_PE_IMAXL_Pos     0UL
#define PPCA_CLB_DICO_PE_IMAXL_PE_IMAXL_Msk     0xFFFFFFFFUL
/* PPCA_CLB_DICO.PE_UP_COUNT */
#define PPCA_CLB_DICO_PE_UP_COUNT_UP_COUNT_Pos  0UL
#define PPCA_CLB_DICO_PE_UP_COUNT_UP_COUNT_Msk  0xFFFUL
/* PPCA_CLB_DICO.PE_DN_COUNT */
#define PPCA_CLB_DICO_PE_DN_COUNT_DOWN_COUNT_Pos 0UL
#define PPCA_CLB_DICO_PE_DN_COUNT_DOWN_COUNT_Msk 0xFFFUL
/* PPCA_CLB_DICO.PE_TPHD_1 */
#define PPCA_CLB_DICO_PE_TPHD_1_TPHD_1_Pos      0UL
#define PPCA_CLB_DICO_PE_TPHD_1_TPHD_1_Msk      0xFFFUL
#define PPCA_CLB_DICO_PE_TPHD_1_PENDING_1_Pos   12UL
#define PPCA_CLB_DICO_PE_TPHD_1_PENDING_1_Msk   0x1000UL
/* PPCA_CLB_DICO.PE_TPHD_2 */
#define PPCA_CLB_DICO_PE_TPHD_2_TPHD_2_Pos      0UL
#define PPCA_CLB_DICO_PE_TPHD_2_TPHD_2_Msk      0xFFFUL
#define PPCA_CLB_DICO_PE_TPHD_2_PENDING_2_Pos   12UL
#define PPCA_CLB_DICO_PE_TPHD_2_PENDING_2_Msk   0x1000UL
/* PPCA_CLB_DICO.PS_TH */
#define PPCA_CLB_DICO_PS_TH_PS_TH_Pos           0UL
#define PPCA_CLB_DICO_PS_TH_PS_TH_Msk           0xFFFFFFUL
#define PPCA_CLB_DICO_PS_TH_SIGN_EXTENDED_PS_TH_Pos 24UL
#define PPCA_CLB_DICO_PS_TH_SIGN_EXTENDED_PS_TH_Msk 0xFF000000UL
/* PPCA_CLB_DICO.PS_CC_INFO */
#define PPCA_CLB_DICO_PS_CC_INFO_UP_FLAG_Pos    0UL
#define PPCA_CLB_DICO_PS_CC_INFO_UP_FLAG_Msk    0x1UL
#define PPCA_CLB_DICO_PS_CC_INFO_PHASE_SHIFT_COUNT_Pos 1UL
#define PPCA_CLB_DICO_PS_CC_INFO_PHASE_SHIFT_COUNT_Msk 0x1FFEUL
#define PPCA_CLB_DICO_PS_CC_INFO_PERIOD_COUNT_Pos 13UL
#define PPCA_CLB_DICO_PS_CC_INFO_PERIOD_COUNT_Msk 0x1FFE000UL
/* PPCA_CLB_DICO.PS_CC */
#define PPCA_CLB_DICO_PS_CC_CC_PENDING_Pos      0UL
#define PPCA_CLB_DICO_PS_CC_CC_PENDING_Msk      0x1UL
#define PPCA_CLB_DICO_PS_CC_CORR_CURR_Pos       1UL
#define PPCA_CLB_DICO_PS_CC_CORR_CURR_Msk       0x1FFFFFEUL
#define PPCA_CLB_DICO_PS_CC_SIGN_EXTENDED_CORR_CURR_Pos 25UL
#define PPCA_CLB_DICO_PS_CC_SIGN_EXTENDED_CORR_CURR_Msk 0xFE000000UL
/* PPCA_CLB_DICO.INTR */
#define PPCA_CLB_DICO_INTR_DICO_INTR_Pos        0UL
#define PPCA_CLB_DICO_INTR_DICO_INTR_Msk        0xFFUL
/* PPCA_CLB_DICO.INTR_SET */
#define PPCA_CLB_DICO_INTR_SET_DICO_INTR_SET_Pos 0UL
#define PPCA_CLB_DICO_INTR_SET_DICO_INTR_SET_Msk 0xFFUL
/* PPCA_CLB_DICO.INTR_MASK */
#define PPCA_CLB_DICO_INTR_MASK_DICO_INTR_MASK_Pos 0UL
#define PPCA_CLB_DICO_INTR_MASK_DICO_INTR_MASK_Msk 0xFFUL
/* PPCA_CLB_DICO.INTR_MASKED */
#define PPCA_CLB_DICO_INTR_MASKED_DICO_INTR_MASKED_Pos 0UL
#define PPCA_CLB_DICO_INTR_MASKED_DICO_INTR_MASKED_Msk 0xFFUL
/* PPCA_CLB_DICO.PCO_CORR_IEST */
#define PPCA_CLB_DICO_PCO_CORR_IEST_CORR_IEST_Pos 0UL
#define PPCA_CLB_DICO_PCO_CORR_IEST_CORR_IEST_Msk 0xFFFFFFFFUL
/* PPCA_CLB_DICO.STAT */
#define PPCA_CLB_DICO_STAT_MAX_ON_REACHED_Pos   0UL
#define PPCA_CLB_DICO_STAT_MAX_ON_REACHED_Msk   0x1UL
#define PPCA_CLB_DICO_STAT_PCO0_ACTIVE_Pos      1UL
#define PPCA_CLB_DICO_STAT_PCO0_ACTIVE_Msk      0x2UL
#define PPCA_CLB_DICO_STAT_PCO1_ACTIVE_Pos      2UL
#define PPCA_CLB_DICO_STAT_PCO1_ACTIVE_Msk      0x4UL
#define PPCA_CLB_DICO_STAT_PCO2_ACTIVE_Pos      3UL
#define PPCA_CLB_DICO_STAT_PCO2_ACTIVE_Msk      0x8UL
#define PPCA_CLB_DICO_STAT_INCORR_SETTING_Pos   4UL
#define PPCA_CLB_DICO_STAT_INCORR_SETTING_Msk   0x10UL
#define PPCA_CLB_DICO_STAT_MASK_STATE_Pos       5UL
#define PPCA_CLB_DICO_STAT_MASK_STATE_Msk       0x20UL
#define PPCA_CLB_DICO_STAT_KILL_STATE_Pos       6UL
#define PPCA_CLB_DICO_STAT_KILL_STATE_Msk       0x40UL
#define PPCA_CLB_DICO_STAT_SAFE_STATE_Pos       7UL
#define PPCA_CLB_DICO_STAT_SAFE_STATE_Msk       0x80UL
#define PPCA_CLB_DICO_STAT_MIN_ON_NOT_REACHED_Pos 8UL
#define PPCA_CLB_DICO_STAT_MIN_ON_NOT_REACHED_Msk 0x100UL


/* PPCA_CLB_MACO.CTRL */
#define PPCA_CLB_MACO_CTRL_FW_MUXSEL_IN_Pos     0UL
#define PPCA_CLB_MACO_CTRL_FW_MUXSEL_IN_Msk     0x1UL
#define PPCA_CLB_MACO_CTRL_MUXSEL_IN_SRC_SEL_Pos 1UL
#define PPCA_CLB_MACO_CTRL_MUXSEL_IN_SRC_SEL_Msk 0x2UL
#define PPCA_CLB_MACO_CTRL_MUXSEL_OUT_SYNC_BYPASS_Pos 2UL
#define PPCA_CLB_MACO_CTRL_MUXSEL_OUT_SYNC_BYPASS_Msk 0x4UL
#define PPCA_CLB_MACO_CTRL_WAIT_FOR_TRIGGER_Pos 3UL
#define PPCA_CLB_MACO_CTRL_WAIT_FOR_TRIGGER_Msk 0x8UL
#define PPCA_CLB_MACO_CTRL_EN_AUTO_TRANSITION_Pos 4UL
#define PPCA_CLB_MACO_CTRL_EN_AUTO_TRANSITION_Msk 0x10UL
#define PPCA_CLB_MACO_CTRL_MACO_FUNC_Pos        5UL
#define PPCA_CLB_MACO_CTRL_MACO_FUNC_Msk        0x20UL
#define PPCA_CLB_MACO_CTRL_MONITOR_SEL_Pos      12UL
#define PPCA_CLB_MACO_CTRL_MONITOR_SEL_Msk      0x1000UL
#define PPCA_CLB_MACO_CTRL_EN_Pos               31UL
#define PPCA_CLB_MACO_CTRL_EN_Msk               0x80000000UL
/* PPCA_CLB_MACO.EVENT */
#define PPCA_CLB_MACO_EVENT_SEL_NXT_SECT_Pos    0UL
#define PPCA_CLB_MACO_EVENT_SEL_NXT_SECT_Msk    0x3UL
#define PPCA_CLB_MACO_EVENT_KILL_EVENT_Pos      2UL
#define PPCA_CLB_MACO_EVENT_KILL_EVENT_Msk      0x4UL
#define PPCA_CLB_MACO_EVENT_TRANS_EVENT_Pos     3UL
#define PPCA_CLB_MACO_EVENT_TRANS_EVENT_Msk     0x8UL
#define PPCA_CLB_MACO_EVENT_KILL_EXIT_Pos       4UL
#define PPCA_CLB_MACO_EVENT_KILL_EXIT_Msk       0x10UL
/* PPCA_CLB_MACO.STAT */
#define PPCA_CLB_MACO_STAT_LAST_SECT_Pos        0UL
#define PPCA_CLB_MACO_STAT_LAST_SECT_Msk        0x3UL
#define PPCA_CLB_MACO_STAT_SCAN_IN_PROGRESS_Pos 2UL
#define PPCA_CLB_MACO_STAT_SCAN_IN_PROGRESS_Msk 0x4UL
#define PPCA_CLB_MACO_STAT_MUXSEL_OUT_EXPO_Pos  3UL
#define PPCA_CLB_MACO_STAT_MUXSEL_OUT_EXPO_Msk  0x8UL
#define PPCA_CLB_MACO_STAT_CURR_SECT_Pos        4UL
#define PPCA_CLB_MACO_STAT_CURR_SECT_Msk        0x30UL
#define PPCA_CLB_MACO_STAT_NEXT_SECT_Pos        6UL
#define PPCA_CLB_MACO_STAT_NEXT_SECT_Msk        0xC0UL
#define PPCA_CLB_MACO_STAT_MASK_STATE_Pos       8UL
#define PPCA_CLB_MACO_STAT_MASK_STATE_Msk       0x100UL
#define PPCA_CLB_MACO_STAT_KILL_STATE_Pos       9UL
#define PPCA_CLB_MACO_STAT_KILL_STATE_Msk       0x200UL
#define PPCA_CLB_MACO_STAT_SAFE_STATE_Pos       10UL
#define PPCA_CLB_MACO_STAT_SAFE_STATE_Msk       0x400UL
/* PPCA_CLB_MACO.SECT0_ROW */
#define PPCA_CLB_MACO_SECT0_ROW_TRAN_ROW_Pos    0UL
#define PPCA_CLB_MACO_SECT0_ROW_TRAN_ROW_Msk    0x1FUL
#define PPCA_CLB_MACO_SECT0_ROW_ALL_ROW_Pos     5UL
#define PPCA_CLB_MACO_SECT0_ROW_ALL_ROW_Msk     0x3E0UL
/* PPCA_CLB_MACO.SECT1_ROW */
#define PPCA_CLB_MACO_SECT1_ROW_TRAN_ROW_Pos    0UL
#define PPCA_CLB_MACO_SECT1_ROW_TRAN_ROW_Msk    0x1FUL
#define PPCA_CLB_MACO_SECT1_ROW_ALL_ROW_Pos     5UL
#define PPCA_CLB_MACO_SECT1_ROW_ALL_ROW_Msk     0x3E0UL
/* PPCA_CLB_MACO.SECT2_ROW */
#define PPCA_CLB_MACO_SECT2_ROW_TRAN_ROW_Pos    0UL
#define PPCA_CLB_MACO_SECT2_ROW_TRAN_ROW_Msk    0x1FUL
#define PPCA_CLB_MACO_SECT2_ROW_ALL_ROW_Pos     5UL
#define PPCA_CLB_MACO_SECT2_ROW_ALL_ROW_Msk     0x3E0UL
/* PPCA_CLB_MACO.INTR */
#define PPCA_CLB_MACO_INTR_INTR_Pos             0UL
#define PPCA_CLB_MACO_INTR_INTR_Msk             0x1UL
/* PPCA_CLB_MACO.INTR_SET */
#define PPCA_CLB_MACO_INTR_SET_INTR_SET_Pos     0UL
#define PPCA_CLB_MACO_INTR_SET_INTR_SET_Msk     0x1UL
/* PPCA_CLB_MACO.INTR_MASK */
#define PPCA_CLB_MACO_INTR_MASK_INTR_MASK_Pos   0UL
#define PPCA_CLB_MACO_INTR_MASK_INTR_MASK_Msk   0x1UL
/* PPCA_CLB_MACO.INTR_MASKED */
#define PPCA_CLB_MACO_INTR_MASKED_INTR_MASKED_Pos 0UL
#define PPCA_CLB_MACO_INTR_MASKED_INTR_MASKED_Msk 0x1UL
/* PPCA_CLB_MACO.SECT0_PATTERN */
#define PPCA_CLB_MACO_SECT0_PATTERN_DRV_Pos     0UL
#define PPCA_CLB_MACO_SECT0_PATTERN_DRV_Msk     0xFFFFUL
#define PPCA_CLB_MACO_SECT0_PATTERN_DLY_Pos     16UL
#define PPCA_CLB_MACO_SECT0_PATTERN_DLY_Msk     0xFF0000UL
/* PPCA_CLB_MACO.SECT0_SAFE */
#define PPCA_CLB_MACO_SECT0_SAFE_DRV_Pos        0UL
#define PPCA_CLB_MACO_SECT0_SAFE_DRV_Msk        0xFFFFUL
/* PPCA_CLB_MACO.SECT1_PATTERN */
#define PPCA_CLB_MACO_SECT1_PATTERN_DRV_Pos     0UL
#define PPCA_CLB_MACO_SECT1_PATTERN_DRV_Msk     0xFFFFUL
#define PPCA_CLB_MACO_SECT1_PATTERN_DLY_Pos     16UL
#define PPCA_CLB_MACO_SECT1_PATTERN_DLY_Msk     0xFF0000UL
/* PPCA_CLB_MACO.SECT1_SAFE */
#define PPCA_CLB_MACO_SECT1_SAFE_DRV_Pos        0UL
#define PPCA_CLB_MACO_SECT1_SAFE_DRV_Msk        0xFFFFUL
/* PPCA_CLB_MACO.SECT2_PATTERN */
#define PPCA_CLB_MACO_SECT2_PATTERN_DRV_Pos     0UL
#define PPCA_CLB_MACO_SECT2_PATTERN_DRV_Msk     0xFFFFUL
#define PPCA_CLB_MACO_SECT2_PATTERN_DLY_Pos     16UL
#define PPCA_CLB_MACO_SECT2_PATTERN_DLY_Msk     0xFF0000UL
/* PPCA_CLB_MACO.SECT2_SAFE */
#define PPCA_CLB_MACO_SECT2_SAFE_DRV_Pos        0UL
#define PPCA_CLB_MACO_SECT2_SAFE_DRV_Msk        0xFFFFUL


/* PPCA_CLB.CTRL */
#define PPCA_CLB_CTRL_TRIG_IN_Pos               0UL
#define PPCA_CLB_CTRL_TRIG_IN_Msk               0x3FUL
#define PPCA_CLB_CTRL_MACO_SEL_Pos              8UL
#define PPCA_CLB_CTRL_MACO_SEL_Msk              0x100UL
#define PPCA_CLB_CTRL_DEBUG_FREEZE_EN_Pos       9UL
#define PPCA_CLB_CTRL_DEBUG_FREEZE_EN_Msk       0x200UL
#define PPCA_CLB_CTRL_EN_Pos                    31UL
#define PPCA_CLB_CTRL_EN_Msk                    0x80000000UL


/* MXCORDIC.CTL */
#define MXCORDIC_CTL_ENABLED_Pos                31UL
#define MXCORDIC_CTL_ENABLED_Msk                0x80000000UL
/* MXCORDIC.ID */
#define MXCORDIC_ID_MOD_REV_Pos                 0UL
#define MXCORDIC_ID_MOD_REV_Msk                 0xFFUL
#define MXCORDIC_ID_MOD_TYPE_Pos                8UL
#define MXCORDIC_ID_MOD_TYPE_Msk                0xFF00UL
#define MXCORDIC_ID_MOD_NUMBER_Pos              16UL
#define MXCORDIC_ID_MOD_NUMBER_Msk              0xFFFF0000UL
/* MXCORDIC.INTR */
#define MXCORDIC_INTR_CDEOC_Pos                 2UL
#define MXCORDIC_INTR_CDEOC_Msk                 0x4UL
#define MXCORDIC_INTR_CDERR_Pos                 3UL
#define MXCORDIC_INTR_CDERR_Msk                 0x8UL
/* MXCORDIC.INTR_SET */
#define MXCORDIC_INTR_SET_CDEOC_Pos             2UL
#define MXCORDIC_INTR_SET_CDEOC_Msk             0x4UL
#define MXCORDIC_INTR_SET_CDERR_Pos             3UL
#define MXCORDIC_INTR_SET_CDERR_Msk             0x8UL
/* MXCORDIC.INTR_MASK */
#define MXCORDIC_INTR_MASK_CDEOC_Pos            2UL
#define MXCORDIC_INTR_MASK_CDEOC_Msk            0x4UL
#define MXCORDIC_INTR_MASK_CDERR_Pos            3UL
#define MXCORDIC_INTR_MASK_CDERR_Msk            0x8UL
/* MXCORDIC.INTR_MASKED */
#define MXCORDIC_INTR_MASKED_CDEOC_Pos          2UL
#define MXCORDIC_INTR_MASKED_CDEOC_Msk          0x4UL
#define MXCORDIC_INTR_MASKED_CDERR_Pos          3UL
#define MXCORDIC_INTR_MASKED_CDERR_Msk          0x8UL
/* MXCORDIC.KEEP */
#define MXCORDIC_KEEP_KEEPX_Pos                 5UL
#define MXCORDIC_KEEP_KEEPX_Msk                 0x20UL
#define MXCORDIC_KEEP_KEEPY_Pos                 6UL
#define MXCORDIC_KEEP_KEEPY_Msk                 0x40UL
#define MXCORDIC_KEEP_KEEPZ_Pos                 7UL
#define MXCORDIC_KEEP_KEEPZ_Msk                 0x80UL
/* MXCORDIC.CON */
#define MXCORDIC_CON_MODE_Pos                   1UL
#define MXCORDIC_CON_MODE_Msk                   0x6UL
#define MXCORDIC_CON_ROTVEC_Pos                 3UL
#define MXCORDIC_CON_ROTVEC_Msk                 0x8UL
#define MXCORDIC_CON_ST_MODE_Pos                4UL
#define MXCORDIC_CON_ST_MODE_Msk                0x10UL
#define MXCORDIC_CON_X_USIGN_Pos                5UL
#define MXCORDIC_CON_X_USIGN_Msk                0x20UL
#define MXCORDIC_CON_MPS_Pos                    6UL
#define MXCORDIC_CON_MPS_Msk                    0xC0UL
#define MXCORDIC_CON_N_ITER_Pos                 8UL
#define MXCORDIC_CON_N_ITER_Msk                 0x700UL
/* MXCORDIC.CORDX */
#define MXCORDIC_CORDX_DATA_Pos                 8UL
#define MXCORDIC_CORDX_DATA_Msk                 0xFFFFFF00UL
/* MXCORDIC.CORDY */
#define MXCORDIC_CORDY_DATA_Pos                 8UL
#define MXCORDIC_CORDY_DATA_Msk                 0xFFFFFF00UL
/* MXCORDIC.CORDZ */
#define MXCORDIC_CORDZ_DATA_Pos                 8UL
#define MXCORDIC_CORDZ_DATA_Msk                 0xFFFFFF00UL
/* MXCORDIC.CORRX */
#define MXCORDIC_CORRX_RESULT_Pos               8UL
#define MXCORDIC_CORRX_RESULT_Msk               0xFFFFFF00UL
/* MXCORDIC.CORRY */
#define MXCORDIC_CORRY_RESULT_Pos               8UL
#define MXCORDIC_CORRY_RESULT_Msk               0xFFFFFF00UL
/* MXCORDIC.CORRZ */
#define MXCORDIC_CORRZ_RESULT_Pos               8UL
#define MXCORDIC_CORRZ_RESULT_Msk               0xFFFFFF00UL
/* MXCORDIC.STAT */
#define MXCORDIC_STAT_BSY_Pos                   0UL
#define MXCORDIC_STAT_BSY_Msk                   0x1UL
/* MXCORDIC.START_CMD */
#define MXCORDIC_START_CMD_ST_Pos               0UL
#define MXCORDIC_START_CMD_ST_Msk               0x1UL


/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_CTL */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_BUSY_Pos 1UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_BUSY_Msk 0x2UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_CALIB_GAIN_MODE_Pos 2UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_CALIB_GAIN_MODE_Msk 0x4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_AUX_SLOT_SEL_Pos 3UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_AUX_SLOT_SEL_Msk 0x8UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ALT_AUX_SLOT_SEL_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ALT_AUX_SLOT_SEL_Msk 0x10UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_TEST_DATA_SEL_Pos 28UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_TEST_DATA_SEL_Msk 0x10000000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_DBG_STATUS_Pos 29UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_DBG_STATUS_Msk 0x20000000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_DBG_FREEZE_EN_Pos 30UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_DBG_FREEZE_EN_Msk 0x40000000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_EN_Pos 31UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_EN_Msk 0x80000000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_CNFG */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNFG_CHANNEL_TYPE_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNFG_CHANNEL_TYPE_Msk 0xFFFFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNFG_CHANNEL_EN_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNFG_CHANNEL_EN_Msk 0xFFFF0000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_AUX_ALT_AUX_CNFG */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ADC_AUX_SEL_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ADC_AUX_SEL_Msk 0xFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_SEL_SRC_N_GND_Pos 8UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_SEL_SRC_N_GND_Msk 0xF00UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_AUX_GND_GRP_2_Pos 12UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_AUX_GND_GRP_2_Msk 0x3000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ALT_AUX_SEL_SRC_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ALT_AUX_SEL_SRC_Msk 0x70000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ALT_AUX_SEL_SRC_GND_Pos 24UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ALT_AUX_SEL_SRC_GND_Msk 0x7000000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ALT_AUX_GND_GRP_2_Pos 27UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ALT_AUX_GND_GRP_2_Msk 0x18000000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ADC_AUX_GND_SEL_Pos 29UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ADC_AUX_GND_SEL_Msk 0x20000000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ADC_AUX_ALT_AUX_SEL_Pos 30UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_ALT_AUX_CNFG_ADC_AUX_ALT_AUX_SEL_Msk 0xC0000000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_CNV_CNFG */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_GROUP_CH_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_GROUP_CH_Msk 0x1UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_TRIGGER_MODE_Pos 1UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_TRIGGER_MODE_Msk 0x6UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_AUTO_TRIGGER_SAMPLE_TCLK_Pos 3UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_AUTO_TRIGGER_SAMPLE_TCLK_Msk 0x1F8UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_NUM_OF_SLOT_Pos 9UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_NUM_OF_SLOT_Msk 0x3E00UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_SRC_EOS_Pos 14UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_SRC_EOS_Msk 0x4000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_NUM_OF_AUX_SLOT_Pos 15UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_NUM_OF_AUX_SLOT_Msk 0xF8000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_NUM_OF_ALT_AUX_SLOT_Pos 20UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_NUM_OF_ALT_AUX_SLOT_Msk 0xF00000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_AUX_SLOT_SCAN_RATE_Pos 24UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_AUX_SLOT_SCAN_RATE_Msk 0x1F000000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_EXT_SOURCE_SEL_Pos 29UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_EXT_SOURCE_SEL_Msk 0x20000000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_SAMPLING_MASK */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_SAMPLING_MASK_ADC_CH_SAMPLING_MASK_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_SAMPLING_MASK_ADC_CH_SAMPLING_MASK_Msk 0xFFFFUL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_TRIGGER */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_TRIGGER_ADC_TRIGGER_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_TRIGGER_ADC_TRIGGER_Msk 0xFFFFUL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_CH_CNFG0 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG0_CH1_TBC_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG0_CH1_TBC_Msk 0xFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG0_CH2_TBC_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG0_CH2_TBC_Msk 0xF0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG0_CH3_TBC_Pos 8UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG0_CH3_TBC_Msk 0xF00UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG0_CH4_TBC_Pos 12UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG0_CH4_TBC_Msk 0xF000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_CH_CNFG1 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG1_CH5_TBC_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG1_CH5_TBC_Msk 0xFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG1_CH6_TBC_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG1_CH6_TBC_Msk 0xF0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG1_CH7_TBC_Pos 8UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG1_CH7_TBC_Msk 0xF00UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG1_CH8_TBC_Pos 12UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG1_CH8_TBC_Msk 0xF000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_CH_CNFG2 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG2_CH9_TBC_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG2_CH9_TBC_Msk 0xFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG2_CH10_TBC_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG2_CH10_TBC_Msk 0xF0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG2_CH11_TBC_Pos 8UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG2_CH11_TBC_Msk 0xF00UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG2_CH12_TBC_Pos 12UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG2_CH12_TBC_Msk 0xF000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_CH_CNFG3 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG3_CH13_TBC_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG3_CH13_TBC_Msk 0xFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG3_CH14_TBC_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG3_CH14_TBC_Msk 0xF0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG3_CH15_TBC_Pos 8UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG3_CH15_TBC_Msk 0xF00UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG3_CH16_TBC_Pos 12UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CH_CNFG3_CH16_TBC_Msk 0xF000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_AUX_CH_CNFG0 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH1_TBC_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH1_TBC_Msk 0xFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH2_TBC_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH2_TBC_Msk 0xF0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH3_TBC_Pos 8UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH3_TBC_Msk 0xF00UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH4_TBC_Pos 12UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH4_TBC_Msk 0xF000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH5_TBC_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH5_TBC_Msk 0xF0000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH6_TBC_Pos 20UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH6_TBC_Msk 0xF00000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH7_TBC_Pos 24UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH7_TBC_Msk 0xF000000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH8_TBC_Pos 28UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG0_AUX_CH8_TBC_Msk 0xF0000000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_AUX_CH_CNFG1 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH9_TBC_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH9_TBC_Msk 0xFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH10_TBC_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH10_TBC_Msk 0xF0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH11_TBC_Pos 8UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH11_TBC_Msk 0xF00UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH12_TBC_Pos 12UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH12_TBC_Msk 0xF000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH13_TBC_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH13_TBC_Msk 0xF0000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH14_TBC_Pos 20UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH14_TBC_Msk 0xF00000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH15_TBC_Pos 24UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH15_TBC_Msk 0xF000000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH16_TBC_Pos 28UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_CH_CNFG1_AUX_CH16_TBC_Msk 0xF0000000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_ALT_AUX_CH_CNFG */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH1_TBC_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH1_TBC_Msk 0xFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH2_TBC_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH2_TBC_Msk 0xF0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH3_TBC_Pos 8UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH3_TBC_Msk 0xF00UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH4_TBC_Pos 12UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH4_TBC_Msk 0xF000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH5_TBC_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH5_TBC_Msk 0xF0000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH6_TBC_Pos 20UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH6_TBC_Msk 0xF00000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH7_TBC_Pos 24UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH7_TBC_Msk 0xF000000UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH8_TBC_Pos 28UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_CH_CNFG_ALT_AUX_CH8_TBC_Msk 0xF0000000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_DATA */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DATA_ADC_DATA_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DATA_ADC_DATA_Msk 0x1FFFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DATA_SIGN_EXTENDED_ADC_DATA_Pos 13UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DATA_SIGN_EXTENDED_ADC_DATA_Msk 0xFFFFE000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_AUX_DATA */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_DATA_ADC_AUX_DATA_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_DATA_ADC_AUX_DATA_Msk 0x1FFFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_DATA_SIGN_EXTENDED_ADC_AUX_DATA_Pos 13UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_DATA_SIGN_EXTENDED_ADC_AUX_DATA_Msk 0xFFFFE000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_ALT_AUX_DATA */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_DATA_ADC_ALT_AUX_DATA_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_DATA_ADC_ALT_AUX_DATA_Msk 0x1FFFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_DATA_SIGN_EXTENDED_ADC_ALT_AUX_DATA_Pos 13UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_ALT_AUX_DATA_SIGN_EXTENDED_ADC_ALT_AUX_DATA_Msk 0xFFFFE000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_INTR */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_INTR_TR_ERROR_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_INTR_TR_ERROR_Msk 0x1UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_INTR_SET */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_INTR_SET_TR_ERROR_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_INTR_SET_TR_ERROR_Msk 0x1UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_INTR_MASK */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_INTR_MASK_TR_ERROR_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_INTR_MASK_TR_ERROR_Msk 0x1UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_INTR_MASKED */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_INTR_MASKED_TR_ERROR_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_INTR_MASKED_TR_ERROR_Msk 0x1UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_SIGN_UNSIGN_CNFG */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_SIGN_UNSIGN_CNFG_ADC_SIGN_UNSIGN_BITS_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_SIGN_UNSIGN_CNFG_ADC_SIGN_UNSIGN_BITS_Msk 0xFFFFUL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.AUX_SIGN_UNSIGN_CNFG */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_AUX_SIGN_UNSIGN_CNFG_AUX_SIGN_UNSIGN_BITS_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_AUX_SIGN_UNSIGN_CNFG_AUX_SIGN_UNSIGN_BITS_Msk 0xFFFFUL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.AUX_ALT_SIGN_UNSIGN_CNFG */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_AUX_ALT_SIGN_UNSIGN_CNFG_AUX_ALT_SIGN_UNSIGN_BITS_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_AUX_ALT_SIGN_UNSIGN_CNFG_AUX_ALT_SIGN_UNSIGN_BITS_Msk 0xFFUL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_STARTUPCTRL */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_TIMCAL_ON_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_TIMCAL_ON_Msk 0x1UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_OFFCAL_ON_Pos 1UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_OFFCAL_ON_Msk 0x2UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_GAICAL_ON_Pos 2UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_GAICAL_ON_Msk 0x4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_VTOICAL_TRIM_Pos 24UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_STARTUPCTRL_VTOICAL_TRIM_Msk 0x1F000000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_CALCTRL */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALCTRL_BACKGND_CALIB_Pos 1UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALCTRL_BACKGND_CALIB_Msk 0x2UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALCTRL_USE_LATCH_TRIM_REG_Pos 2UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALCTRL_USE_LATCH_TRIM_REG_Msk 0x4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALCTRL_TIMING_AVG_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALCTRL_TIMING_AVG_Msk 0x30UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALCTRL_AVG_Pos 8UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALCTRL_AVG_Msk 0x300UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_CALOFFSET */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALOFFSET_OFFSET_SE_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALOFFSET_OFFSET_SE_Msk 0xFFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALOFFSET_OFFSET_DIFF_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALOFFSET_OFFSET_DIFF_Msk 0xFF0000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_CALGAIN */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALGAIN_GAINX1_SE_MODE_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALGAIN_GAINX1_SE_MODE_Msk 0x7FFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALGAIN_GAINX1_DIFF_MODE_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALGAIN_GAINX1_DIFF_MODE_Msk 0x7FF0000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_ADC.ADC_DFT_AUX_CNFG */
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_ADFT_EN_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_ADFT_EN_Msk 0x1UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_SEL_SRC_N_Pos 1UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_SEL_SRC_N_Msk 0xEUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_ADC_MUX_TO_PIN_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_ADC_MUX_TO_PIN_Msk 0x10UL


/* PPCA_ATOPSS_ADC_GRP_SLICE_AFE.AFE_CTL */
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CTL_AFE_EN_0_Pos 31UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CTL_AFE_EN_0_Msk 0x80000000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_AFE.AFE_CNFG */
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CNFG_AFE_GAIN_SET_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CNFG_AFE_GAIN_SET_Msk 0x7UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CNFG_AFE_PWR_SET_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CNFG_AFE_PWR_SET_Msk 0x70UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CNFG_AFE_CLOCK_RATIO_Pos 7UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CNFG_AFE_CLOCK_RATIO_Msk 0x180UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_AFE.AFE_CALGAINAFE_1 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_1_HFLG2_3_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_1_HFLG2_3_Msk 0x7FFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_1_HFLG2_6_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_1_HFLG2_6_Msk 0x7FF0000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_AFE.AFE_CALGAINAFE_2 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_2_HFLG3_3_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_2_HFLG3_3_Msk 0x7FFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_2_HFLG3_6_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_2_HFLG3_6_Msk 0x7FF0000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_AFE.AFE_CALGAINAFE_3 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_3_LFHG1_12_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_3_LFHG1_12_Msk 0x7FFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_3_LFHG1_24_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_3_LFHG1_24_Msk 0x7FF0000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_AFE.AFE_CALGAINAFE_4 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_4_HFLG1_3_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_4_HFLG1_3_Msk 0x7FFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_4_HFLG1_6_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALGAINAFE_4_HFLG1_6_Msk 0x7FF0000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_AFE.AFE_CALOFFSETAFE_1 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_1_HFLG2_3_OS_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_1_HFLG2_3_OS_Msk 0xFFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_1_HFLG2_6_OS_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_1_HFLG2_6_OS_Msk 0xFF0000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_AFE.AFE_CALOFFSETAFE_2 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_2_HFLG3_3_OS_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_2_HFLG3_3_OS_Msk 0xFFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_2_HFLG3_6_OS_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_2_HFLG3_6_OS_Msk 0xFF0000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_AFE.AFE_CALOFFSETAFE_3 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_3_LFHG1_12_OS_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_3_LFHG1_12_OS_Msk 0xFFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_3_LFHG1_24_OS_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_3_LFHG1_24_OS_Msk 0xFF0000UL
/* PPCA_ATOPSS_ADC_GRP_SLICE_AFE.AFE_CALOFFSETAFE_4 */
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_4_HFLG1_3_OS_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_4_HFLG1_3_OS_Msk 0xFFUL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_4_HFLG1_6_OS_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CALOFFSETAFE_4_HFLG1_6_OS_Msk 0xFF0000UL


/* PPCA_ATOPSS_ADC_GRP_AFLT.AFLT_CTL */
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_UNSIGN_PATH_EN_Pos 25UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_UNSIGN_PATH_EN_Msk 0x2000000UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_MIN_MAX_DET_EN_Pos 26UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_MIN_MAX_DET_EN_Msk 0x4000000UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_MED_EN_Pos 27UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_MED_EN_Msk 0x8000000UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_LIF_EN_Pos 28UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_LIF_EN_Msk 0x10000000UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_AVG_EN_Pos 29UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_AVG_EN_Msk 0x20000000UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_CIC_EN_Pos 30UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_CIC_EN_Msk 0x40000000UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_LPF_EN_Pos 31UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CTL_LPF_EN_Msk 0x80000000UL
/* PPCA_ATOPSS_ADC_GRP_AFLT.AFLT_CNFG */
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_MEDIAN_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_MEDIAN_Msk 0x1UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_LIF_Pos 1UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_LIF_Msk 0x2UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_LPF_Pos 2UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_LPF_Msk 0x4UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_CIC_Pos 3UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_CIC_Msk 0x8UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_AVG_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_AVG_Msk 0x10UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_SRC_CH_Pos 5UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_SRC_CH_Msk 0x1E0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_MIN_MAX_SAMPLE_SEARCH_Pos 9UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_MIN_MAX_SAMPLE_SEARCH_Msk 0x600UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SOURCE_MIN_MAX_SAMPLE_SEARCH_Pos 11UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SOURCE_MIN_MAX_SAMPLE_SEARCH_Msk 0x800UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_SRC_ADC_FILT_Pos 12UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AFLT_CNFG_SEL_SRC_ADC_FILT_Msk 0x1000UL
/* PPCA_ATOPSS_ADC_GRP_AFLT.LPF_ALFA */
#define PPCA_ATOPSS_ADC_GRP_AFLT_LPF_ALFA_BW_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_LPF_ALFA_BW_Msk 0xFFUL
/* PPCA_ATOPSS_ADC_GRP_AFLT.LPF_DOUT */
#define PPCA_ATOPSS_ADC_GRP_AFLT_LPF_DOUT_LPF_DOUT_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_LPF_DOUT_LPF_DOUT_Msk 0xFFFFUL
/* PPCA_ATOPSS_ADC_GRP_AFLT.CICF_CNFG */
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_SEL_SRC_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_SEL_SRC_Msk 0x1UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CLK_DIV_Pos 1UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CLK_DIV_Msk 0xEUL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_DEC_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_DEC_Msk 0x7FF0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_DEC_OFFSET_Pos 15UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_DEC_OFFSET_Msk 0x3FF8000UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_DEC_SCALE_Pos 26UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_DEC_SCALE_Msk 0x7C000000UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_CMP_EN_Pos 31UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_CNFG_CICF_CMP_EN_Msk 0x80000000UL
/* PPCA_ATOPSS_ADC_GRP_AFLT.CICF_DOUT */
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_DOUT_CICF_DOUT_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_DOUT_CICF_DOUT_Msk 0xFFFFFFFFUL
/* PPCA_ATOPSS_ADC_GRP_AFLT.CICF_UB_TH */
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_UB_TH_CICF_UB_TH_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_UB_TH_CICF_UB_TH_Msk 0xFFFF0000UL
/* PPCA_ATOPSS_ADC_GRP_AFLT.CICF_LB_TH */
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_LB_TH_CICF_LB_TH_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_CICF_LB_TH_CICF_LB_TH_Msk 0xFFFF0000UL
/* PPCA_ATOPSS_ADC_GRP_AFLT.AVGF_CTL */
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CTL_ACCM_SAMPLE_RPT_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CTL_ACCM_SAMPLE_RPT_Msk 0xFFFFFFUL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CTL_SOF_TRIGGER_Pos 31UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CTL_SOF_TRIGGER_Msk 0x80000000UL
/* PPCA_ATOPSS_ADC_GRP_AFLT.AVGF_CNFG */
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CNFG_M_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CNFG_M_Msk 0xFFFFUL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CNFG_K_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CNFG_K_Msk 0x10000UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CNFG_SEL_W_TYPE_Pos 17UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_CNFG_SEL_W_TYPE_Msk 0x20000UL
/* PPCA_ATOPSS_ADC_GRP_AFLT.AVGF_DOUT */
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_DOUT_AVGF_DOUT_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_AVGF_DOUT_AVGF_DOUT_Msk 0xFFFFFFFFUL
/* PPCA_ATOPSS_ADC_GRP_AFLT.LIF_CNFG */
#define PPCA_ATOPSS_ADC_GRP_AFLT_LIF_CNFG_M_FACTOR_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_LIF_CNFG_M_FACTOR_Msk 0x7UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_LIF_CNFG_M_TRIGGER_POINT_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_LIF_CNFG_M_TRIGGER_POINT_Msk 0xFF0000UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_LIF_CNFG_INTP_EXTP_SEL_Pos 31UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_LIF_CNFG_INTP_EXTP_SEL_Msk 0x80000000UL
/* PPCA_ATOPSS_ADC_GRP_AFLT.LIF_DOUT */
#define PPCA_ATOPSS_ADC_GRP_AFLT_LIF_DOUT_LIF_DOUT_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_LIF_DOUT_LIF_DOUT_Msk 0xFFFFUL
/* PPCA_ATOPSS_ADC_GRP_AFLT.MED_CNFG */
#define PPCA_ATOPSS_ADC_GRP_AFLT_MED_CNFG_CNFG_MED_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_MED_CNFG_CNFG_MED_Msk 0xFFFFUL
/* PPCA_ATOPSS_ADC_GRP_AFLT.MED_DOUT */
#define PPCA_ATOPSS_ADC_GRP_AFLT_MED_DOUT_MED_DOUT_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_MED_DOUT_MED_DOUT_Msk 0xFFFUL
/* PPCA_ATOPSS_ADC_GRP_AFLT.ADC_MIN_MAX */
#define PPCA_ATOPSS_ADC_GRP_AFLT_ADC_MIN_MAX_MIN_MIRROR_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_ADC_MIN_MAX_MIN_MIRROR_Msk 0xFFFUL
#define PPCA_ATOPSS_ADC_GRP_AFLT_ADC_MIN_MAX_MAX_MIRROR_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_AFLT_ADC_MIN_MAX_MAX_MIRROR_Msk 0xFFF0000UL


/* PPCA_ATOPSS_ADC_GRP_DCMP.DCMP_CTL */
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CTL_DCMP_EV_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CTL_DCMP_EV_Msk 0x1UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CTL_DCMP_EN_Pos 31UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CTL_DCMP_EN_Msk 0x80000000UL
/* PPCA_ATOPSS_ADC_GRP_DCMP.DCMP_CNFG */
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_MODE_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_MODE_Msk 0x3UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_SAMPLE_Pos 2UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_SAMPLE_Msk 0xCUL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_SEL_SRC_CH_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_SEL_SRC_CH_Msk 0xF0UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_INV_DCMP_EV_CNFG_Pos 8UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_CNFG_INV_DCMP_EV_CNFG_Msk 0x100UL
/* PPCA_ATOPSS_ADC_GRP_DCMP.DCMP_TRIGGER */
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_TRIGGER_DCMP_TRIG_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_TRIGGER_DCMP_TRIG_Msk 0x1UL
/* PPCA_ATOPSS_ADC_GRP_DCMP.DCMP_TH */
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_TH_DCMP_TH_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_TH_DCMP_TH_Msk 0xFFFUL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_TH_SIGN_EXTENDED_DCMP_TH_Pos 12UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_TH_SIGN_EXTENDED_DCMP_TH_Msk 0xFFFFF000UL
/* PPCA_ATOPSS_ADC_GRP_DCMP.DCMP_ACC_TH */
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_ACC_TH_DCMP_ACC_TH_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_DCMP_DCMP_ACC_TH_DCMP_ACC_TH_Msk 0xFFUL


/* PPCA_ATOPSS_ADC_GRP_IDAC.IDAC_CTL */
#define PPCA_ATOPSS_ADC_GRP_IDAC_IDAC_CTL_IDAC_EN_Pos 31UL
#define PPCA_ATOPSS_ADC_GRP_IDAC_IDAC_CTL_IDAC_EN_Msk 0x80000000UL
/* PPCA_ATOPSS_ADC_GRP_IDAC.IDAC_CNFG */
#define PPCA_ATOPSS_ADC_GRP_IDAC_IDAC_CNFG_MUX_SEL_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_IDAC_IDAC_CNFG_MUX_SEL_Msk 0xFUL


/* PPCA_ATOPSS_ADC_GRP_AREF.AREF_CTL */
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_AREF_MODE_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_AREF_MODE_Msk 0x1UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_AREF_BIAS_SCALE_Pos 2UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_AREF_BIAS_SCALE_Msk 0xCUL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_AREF_RMB_Pos 4UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_AREF_RMB_Msk 0x70UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_CTB_IPTAT_SCALE_Pos 7UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_CTB_IPTAT_SCALE_Msk 0x80UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_CTB_IPTAT_REDIRECT_Pos 8UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_CTB_IPTAT_REDIRECT_Msk 0xFF00UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_IZTAT_SEL_Pos 16UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_IZTAT_SEL_Msk 0x10000UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_VREF_SEL_Pos 20UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_VREF_SEL_Msk 0x300000UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_TSNS_CUR_ENABLED_Pos 30UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_TSNS_CUR_ENABLED_Msk 0x40000000UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_ENABLED_Pos 31UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_ENABLED_Msk 0x80000000UL
/* PPCA_ATOPSS_ADC_GRP_AREF.VDDA_STATUS */
#define PPCA_ATOPSS_ADC_GRP_AREF_VDDA_STATUS_VDDA_OK_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_VDDA_STATUS_VDDA_OK_Msk 0x1UL
/* PPCA_ATOPSS_ADC_GRP_AREF.AREF_ANA_CTL */
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_ANA_CTL_FORCE_POR_0_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_ANA_CTL_FORCE_POR_0_Msk 0x1UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_ANA_CTL_FORCE_POR_1_Pos 1UL
#define PPCA_ATOPSS_ADC_GRP_AREF_AREF_ANA_CTL_FORCE_POR_1_Msk 0x2UL
/* PPCA_ATOPSS_ADC_GRP_AREF.VREF_TRIM0 */
#define PPCA_ATOPSS_ADC_GRP_AREF_VREF_TRIM0_VREF_ABS_TRIM_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_VREF_TRIM0_VREF_ABS_TRIM_Msk 0xFFUL
/* PPCA_ATOPSS_ADC_GRP_AREF.VREF_TRIM1 */
#define PPCA_ATOPSS_ADC_GRP_AREF_VREF_TRIM1_VREF_TEMPCO_TRIM_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_VREF_TRIM1_VREF_TEMPCO_TRIM_Msk 0xFFUL
/* PPCA_ATOPSS_ADC_GRP_AREF.VREF_TRIM2 */
#define PPCA_ATOPSS_ADC_GRP_AREF_VREF_TRIM2_VREF_CURV_TRIM_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_VREF_TRIM2_VREF_CURV_TRIM_Msk 0xFFUL
/* PPCA_ATOPSS_ADC_GRP_AREF.VREF_TRIM3 */
#define PPCA_ATOPSS_ADC_GRP_AREF_VREF_TRIM3_VREF_ATTEN_TRIM_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_VREF_TRIM3_VREF_ATTEN_TRIM_Msk 0xFUL
/* PPCA_ATOPSS_ADC_GRP_AREF.IZTAT_TRIM0 */
#define PPCA_ATOPSS_ADC_GRP_AREF_IZTAT_TRIM0_IZTAT_ABS_TRIM_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_IZTAT_TRIM0_IZTAT_ABS_TRIM_Msk 0xFFUL
/* PPCA_ATOPSS_ADC_GRP_AREF.IZTAT_TRIM1 */
#define PPCA_ATOPSS_ADC_GRP_AREF_IZTAT_TRIM1_IZTAT_TC_TRIM_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_IZTAT_TRIM1_IZTAT_TC_TRIM_Msk 0xFFUL
/* PPCA_ATOPSS_ADC_GRP_AREF.IPTAT_TRIM0 */
#define PPCA_ATOPSS_ADC_GRP_AREF_IPTAT_TRIM0_IPTAT_CORE_TRIM_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_IPTAT_TRIM0_IPTAT_CORE_TRIM_Msk 0xFUL
/* PPCA_ATOPSS_ADC_GRP_AREF.IPTAT_TRIM1 */
#define PPCA_ATOPSS_ADC_GRP_AREF_IPTAT_TRIM1_IPTAT_CTBM_TRIM_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_IPTAT_TRIM1_IPTAT_CTBM_TRIM_Msk 0xFUL
/* PPCA_ATOPSS_ADC_GRP_AREF.ICTAT_TRIM0 */
#define PPCA_ATOPSS_ADC_GRP_AREF_ICTAT_TRIM0_ICTAT_TRIM_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_AREF_ICTAT_TRIM0_ICTAT_TRIM_Msk 0xFUL


/* PPCA_ATOPSS_ADC_GRP_GPI.GPI_CTL */
#define PPCA_ATOPSS_ADC_GRP_GPI_GPI_CTL_GPI_INPUT_AI0_Pos 0UL
#define PPCA_ATOPSS_ADC_GRP_GPI_GPI_CTL_GPI_INPUT_AI0_Msk 0x1UL
#define PPCA_ATOPSS_ADC_GRP_GPI_GPI_CTL_GPI_INPUT_AI1_Pos 1UL
#define PPCA_ATOPSS_ADC_GRP_GPI_GPI_CTL_GPI_INPUT_AI1_Msk 0x2UL
#define PPCA_ATOPSS_ADC_GRP_GPI_GPI_CTL_GPI_EN_AI1_Pos 30UL
#define PPCA_ATOPSS_ADC_GRP_GPI_GPI_CTL_GPI_EN_AI1_Msk 0x40000000UL
#define PPCA_ATOPSS_ADC_GRP_GPI_GPI_CTL_GPI_EN_AI0_Pos 31UL
#define PPCA_ATOPSS_ADC_GRP_GPI_GPI_CTL_GPI_EN_AI0_Msk 0x80000000UL


/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE.DCSG_CTL */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CTL_CMP_FLAG_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CTL_CMP_FLAG_Msk 0x1UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CTL_DCSG_BUSY_Pos 1UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CTL_DCSG_BUSY_Msk 0x2UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CTL_DCSG_EN_Pos 31UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CTL_DCSG_EN_Msk 0x80000000UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE.DCSG_CNFG */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_SEL_SRC_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_SEL_SRC_Msk 0x1UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_SEL_CH_SRC_Pos 1UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_SEL_CH_SRC_Msk 0x1EUL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_TYPE_CH_SRC_Pos 5UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_TYPE_CH_SRC_Msk 0xE0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_INIT_SETTING_Pos 11UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_INIT_SETTING_Msk 0x1800UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_DCSG_DAC_RATE_Pos 13UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_DCSG_DAC_RATE_Msk 0xE000UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_DEFINED_VALUE_SETUP_Pos 16UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_DEFINED_VALUE_SETUP_Msk 0x10000UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_DEFINED_VALUE_Pos 17UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_DEFINED_VALUE_Msk 0x20000UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_BYPASS_REFRESH_Pos 18UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_USER_BYPASS_REFRESH_Msk 0x40000UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_CFG_REFRESH_RATE_Pos 20UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_CFG_REFRESH_RATE_Msk 0x700000UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_HYST_Pos 23UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_HYST_Msk 0x3800000UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_DEB_Pos 26UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_CNFG_DEB_Msk 0x1C000000UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE.DCSG_TH */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_TH_TH_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_TH_TH_Msk 0xFFFUL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE.DCSG_DIFF_CALOFFSET */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_ER_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_ER_Msk 0x3FFUL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_FR_Pos 10UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_FR_Msk 0xFFC00UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_RR_Pos 20UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_RR_Msk 0x3FF00000UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE.DCSG_SE_CALOFFSET */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_SE_CALOFFSET_OFFSET_SE_SP_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_SE_CALOFFSET_OFFSET_SE_SP_Msk 0x3FFUL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_SE_CALOFFSET_OFFSET_SE_SN_Pos 10UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_SE_CALOFFSET_OFFSET_SE_SN_Msk 0xFFC00UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_SE_CALOFFSET_OFFSET_A_VS_B_Pos 20UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_SE_CALOFFSET_OFFSET_A_VS_B_Msk 0x3FF00000UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE.DCSG_DIFF_CALGAIN_1 */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_ER_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_ER_Msk 0x7FFUL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_FR_Pos 16UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_FR_Msk 0x7FF0000UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE.DCSG_DIFF_CALGAIN_2 */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALGAIN_2_GAIN_DIFF_RR_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_DIFF_CALGAIN_2_GAIN_DIFF_RR_Msk 0x7FFUL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE.DCSG_SE_CALGAIN */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_SE_CALGAIN_GAIN_SE_SP_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_SE_CALGAIN_GAIN_SE_SP_Msk 0x7FFUL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_SE_CALGAIN_GAIN_SE_SN_Pos 16UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_DCSG_SE_CALGAIN_GAIN_SE_SN_Msk 0x7FF0000UL


/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN.DCSG_SLGEN_CTL */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SLGEN_EN_TRIGGER_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SLGEN_EN_TRIGGER_Msk 0x1UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SLGEN_BUSY_Pos 1UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SLGEN_BUSY_Msk 0x2UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_TRIGGER_UNMASK_Pos 2UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_TRIGGER_UNMASK_Msk 0x4UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SIN_CLK_BLANK_Pos 28UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SIN_CLK_BLANK_Msk 0x10000000UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_DBG_STATUS_Pos 29UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_DBG_STATUS_Msk 0x20000000UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_DBG_FREEZE_EN_Pos 30UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_DBG_FREEZE_EN_Msk 0x40000000UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SLGEN_EN_Pos 31UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CTL_SLGEN_EN_Msk 0x80000000UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN.DCSG_SLGEN_CNFG */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_SEL_SLGEN_SRC_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_SEL_SLGEN_SRC_Msk 0x1UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_EN_SHADOW_TRANSFER_Pos 1UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_EN_SHADOW_TRANSFER_Msk 0x2UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_AUTO_RESET_Pos 2UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_AUTO_RESET_Msk 0x4UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_SLGEN_MAP_Pos 3UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_CNFG_SLGEN_MAP_Msk 0x38UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN.DCSG_SLGEN_INIT */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_F_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_F_Msk 0xFUL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_I_Pos 4UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_I_Msk 0xFFF0UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN.DCSG_SLGEN_TARGET */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_F_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_F_Msk 0xFUL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_I_Pos 4UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_I_Msk 0xFFF0UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN.DCSG_SLGEN_INIT_BUF */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_BUF_F_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_BUF_F_Msk 0xFUL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_BUF_I_Pos 4UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_INIT_BUF_I_Msk 0xFFF0UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN.DCSG_SLGEN_TARGET_BUF */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_BUF_F_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_BUF_F_Msk 0xFUL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_BUF_I_Pos 4UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_TARGET_BUF_I_Msk 0xFFF0UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN.DCSG_SLGEN_STEP */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_STEP_F_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_STEP_F_Msk 0xFUL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_STEP_I_Pos 4UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_STEP_I_Msk 0xFFF0UL
/* PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN.DCSG_SLGEN_MATCH */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_MATCH_TH_TRIG_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_MATCH_TH_TRIG_Msk 0xFFFUL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_MATCH_TH_TRIG_VALID_Pos 12UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_DCSG_SLGEN_MATCH_TH_TRIG_VALID_Msk 0x1000UL


/* PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK.DCSG_BLANK_CTL */
#define PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK_DCSG_BLANK_CTL_DCSG_BLANK_EN_Pos 31UL
#define PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK_DCSG_BLANK_CTL_DCSG_BLANK_EN_Msk 0x80000000UL


/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_CTL */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CTL_DAC_EN_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CTL_DAC_EN_Msk 0x1UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CTL_DAC_BUFF_EN_Pos 1UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CTL_DAC_BUFF_EN_Msk 0x2UL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_CNFG */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_R2RDAC_CNFG_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_R2RDAC_CNFG_Msk 0x7UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_DAC_OFFSET_DIS_Pos 3UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_DAC_OFFSET_DIS_Msk 0x8UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_DAC_GAIN_DIS_Pos 4UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_DAC_GAIN_DIS_Msk 0x10UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_BUF_OFFSET_DIS_Pos 5UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_BUF_OFFSET_DIS_Msk 0x20UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_EN_VREF_TO_BUF_Pos 6UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_EN_VREF_TO_BUF_Msk 0x40UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_EN_DAC_O_TO_BUF_Pos 7UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CNFG_EN_DAC_O_TO_BUF_Msk 0x80UL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_DOUT */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_DOUT_DOUT_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_DOUT_DOUT_Msk 0xFFFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_OFFSET_CNFG1 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_OFFSET_CNFG1_DAC_OFFSET_CNFG1_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_OFFSET_CNFG1_DAC_OFFSET_CNFG1_Msk 0x3FFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_OFFSET_CNFG2 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_OFFSET_CNFG2_DAC_OFFSET_CNFG2_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_OFFSET_CNFG2_DAC_OFFSET_CNFG2_Msk 0x3FFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_OFFSET_CNFG3 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_OFFSET_CNFG3_DAC_OFFSET_CNFG3_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_OFFSET_CNFG3_DAC_OFFSET_CNFG3_Msk 0x3FFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_OFFSET_CNFG4 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_OFFSET_CNFG4_DAC_OFFSET_CNFG4_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_OFFSET_CNFG4_DAC_OFFSET_CNFG4_Msk 0x3FFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_OFFSET_CNFG5 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_OFFSET_CNFG5_DAC_OFFSET_CNFG5_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_OFFSET_CNFG5_DAC_OFFSET_CNFG5_Msk 0x3FFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_GAIN_CNFG1 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_GAIN_CNFG1_DAC_GAIN_CNFG1_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_GAIN_CNFG1_DAC_GAIN_CNFG1_Msk 0x7FFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_GAIN_CNFG2 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_GAIN_CNFG2_DAC_GAIN_CNFG2_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_GAIN_CNFG2_DAC_GAIN_CNFG2_Msk 0x7FFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_GAIN_CNFG3 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_GAIN_CNFG3_DAC_GAIN_CNFG3_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_GAIN_CNFG3_DAC_GAIN_CNFG3_Msk 0x7FFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_GAIN_CNFG4 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_GAIN_CNFG4_DAC_GAIN_CNFG4_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_GAIN_CNFG4_DAC_GAIN_CNFG4_Msk 0x7FFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.DAC_GAIN_CNFG5 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_GAIN_CNFG5_DAC_GAIN_CNFG5_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_GAIN_CNFG5_DAC_GAIN_CNFG5_Msk 0x7FFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.BUFFER_OFFSET_1 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_BUFFER_OFFSET_1_BUFFER_OFFSET_1_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_BUFFER_OFFSET_1_BUFFER_OFFSET_1_Msk 0x3FFUL
/* PPCA_ATOPSS_DCSG_GRP_DAC_R2R.BUFFER_OFFSET_2 */
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_BUFFER_OFFSET_2_BUFFER_OFFSET_2_Pos 0UL
#define PPCA_ATOPSS_DCSG_GRP_DAC_R2R_BUFFER_OFFSET_2_BUFFER_OFFSET_2_Msk 0x3FFUL


#endif /* _CYIP_PPCA_H_ */


/* [] END OF FILE */
