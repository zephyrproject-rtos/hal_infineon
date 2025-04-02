/***************************************************************************//**
* \file cyip_sflash_psc3.h
*
* \brief
* SFLASH IP definitions
*
********************************************************************************
* \copyright
* (c) (2016-2024), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _CYIP_SFLASH_PSC3_H_
#define _CYIP_SFLASH_PSC3_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    SFLASH
*******************************************************************************/

#define SFLASH_SECTION_SIZE                     0x00008000UL

/**
  * \brief FLASH Supervisory Region (SFLASH)
  */
typedef struct {
   __IM uint8_t  RESERVED;
  __IOM uint8_t  SI_REVISION_ID;                /*!< 0x00000001 Indicates Silicon Revision ID of the device */
  __IOM uint16_t SILICON_ID;                    /*!< 0x00000002 Indicates Silicon ID of the device */
  __IOM uint16_t FAMILY_ID;                     /*!< 0x00000004 Indicates Family ID of the device */
   __IM uint16_t RESERVED1[9];
  __IOM uint32_t SFLASH_SVN;                    /*!< 0x00000018 SFLASH Subversion */
   __IM uint32_t RESERVED2[377];
  __IOM uint8_t  DIE_LOT[3];                    /*!< 0x00000600 Lot Number (3 bytes) */
  __IOM uint8_t  DIE_WAFER;                     /*!< 0x00000603 Wafer Number */
  __IOM uint8_t  DIE_X;                         /*!< 0x00000604 X Position on Wafer, CRI Pass/Fail Bin */
  __IOM uint8_t  DIE_Y;                         /*!< 0x00000605 Y Position on Wafer, CHI Pass/Fail Bin */
  __IOM uint8_t  DIE_SORT;                      /*!< 0x00000606 Sort1/2/3 Pass/Fail Bin */
  __IOM uint8_t  DIE_MINOR;                     /*!< 0x00000607 Minor Revision Number */
  __IOM uint8_t  DIE_DAY;                       /*!< 0x00000608 Day number */
  __IOM uint8_t  DIE_MONTH;                     /*!< 0x00000609 Month number */
  __IOM uint8_t  DIE_YEAR;                      /*!< 0x0000060A Year number */
   __IM uint8_t  RESERVED3;
  __IOM uint32_t CSP_PANEL_ID;                  /*!< 0x0000060C CSP Panel Id to record panel ID of CSP die */
  __IOM uint32_t SAR_CALOFFST_0_N40C;           /*!< 0x00000610 SAR calibration offset at -40C. Each of these 4 registers
                                                                contains the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc. */
  __IOM uint32_t SAR_CALOFFST_1_N40C;           /*!< 0x00000614 SAR calibration offset at -40C. Each of these 4 registers
                                                                contains the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc. */
  __IOM uint32_t SAR_CALOFFST_2_N40C;           /*!< 0x00000618 SAR calibration offset at -40C. Each of these 4 registers
                                                                contains the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc. */
  __IOM uint32_t SAR_CALOFFST_3_N40C;           /*!< 0x0000061C SAR calibration offset at -40C. Each of these 4 registers
                                                                contains the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc. */
  __IOM uint32_t SAR_CALOFFST_0_125C;           /*!< 0x00000620 SAR calibration offset at 125C. Each of these 4 registers
                                                                contains the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc. */
  __IOM uint32_t SAR_CALOFFST_1_125C;           /*!< 0x00000624 SAR calibration offset at 125C. Each of these 4 registers
                                                                contains the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc. */
  __IOM uint32_t SAR_CALOFFST_2_125C;           /*!< 0x00000628 SAR calibration offset at 125C. Each of these 4 registers
                                                                contains the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc. */
  __IOM uint32_t SAR_CALOFFST_3_125C;           /*!< 0x0000062C SAR calibration offset at 125C. Each of these 4 registers
                                                                contains the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc. */
  __IOM uint32_t SAR_CALOFFST_0_25C;            /*!< 0x00000630 SAR Calibration Offset for sampler 0 at 25C measured after
                                                                packaging. This value is copied to the CALOFFST register in the
                                                                SAR during the init function. Each of these 4 registers contains
                                                                the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc */
  __IOM uint32_t SAR_CALOFFST_1_25C;            /*!< 0x00000634 SAR Calibration Offset for sampler 0 at 25C measured after
                                                                packaging. This value is copied to the CALOFFST register in the
                                                                SAR during the init function. Each of these 4 registers contains
                                                                the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc */
  __IOM uint32_t SAR_CALOFFST_2_25C;            /*!< 0x00000638 SAR Calibration Offset for sampler 0 at 25C measured after
                                                                packaging. This value is copied to the CALOFFST register in the
                                                                SAR during the init function. Each of these 4 registers contains
                                                                the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc */
  __IOM uint32_t SAR_CALOFFST_3_25C;            /*!< 0x0000063C SAR Calibration Offset for sampler 0 at 25C measured after
                                                                packaging. This value is copied to the CALOFFST register in the
                                                                SAR during the init function. Each of these 4 registers contains
                                                                the offset cal for 4 succesive samplers, where N is the
                                                                iteration of each of the 4 registers. For example CALOFFST_0
                                                                contains the offset cal for samplers 0-3, CAOFFST_1 contains the
                                                                offset cal for samplers 4-7, etc */
  __IOM uint32_t SAR_CALREFPT;                  /*!< 0x00000640 SAR Calibration Reference Point (Voltage) AKA VAREF_PROD */
  __IOM uint32_t SAR_TEMP_COEF_A;               /*!< 0x00000644 Factors used in temperature calculation formula Temperature = a
                                                                * ratio^3 + b * ratio^2 + c * ratio^1 + d */
  __IOM uint32_t SAR_TEMP_COEF_B;               /*!< 0x00000648 Factors used in temperature calculation formula Temperature = a
                                                                * ratio^3 + b * ratio^2 + c * ratio^1 + d */
  __IOM uint32_t SAR_TEMP_COEF_C;               /*!< 0x0000064C Factors used in temperature calculation formula Temperature = a
                                                                * ratio^3 + b * ratio^2 + c * ratio^1 + d */
  __IOM uint32_t SAR_TEMP_COEF_D;               /*!< 0x00000650 Factors used in temperature calculation formula Temperature = a
                                                                * ratio^3 + b * ratio^2 + c * ratio^1 + d */
  __IOM uint32_t SAR_CAL_LIN_TABLE[16];         /*!< 0x00000654 Table of values that are loaded in the HPPASS_SARADC_CALLIN0 -
                                                                15 registers by the init function. Each value contains 4x 7 bit
                                                                calibration values. See the Registers Technical Reference Manual
                                                                for the details of these calibration registers. */
  __IOM uint32_t SAR_CALGAINC;                  /*!< 0x00000694 SARADC Coarse-grained Gain Calibration Values - Load to
                                                                CALGAINC register */
  __IOM uint32_t SAR_CALGAINF;                  /*!< 0x00000698 SARADC Fine-grained Gain Calibration Values - Load to CALGAINF
                                                                register */
  __IOM uint32_t SAR_INFRA_TRIM_TABLE[16];      /*!< 0x0000069C Table of trim values loaded to SAR by the mcpass init function.
                                                                The table format is as follows: [32-bits] n_trim_pairs [32-bits
                                                                list] (mmio_addr, mmio_value) x (n_trim_pairs) */
  __IOM uint32_t LDO_0P9V_TRIM;                 /*!< 0x000006DC LDO trim value for 0.9V. Loaded to the SRSS_PWR_TRIM_PWRSYS_CTL
                                                                register when changing LDO regulator settings. */
  __IOM uint32_t LDO_1P0V_TRIM;                 /*!< 0x000006E0 LDO trim value for 1.0V. Loaded to the SRSS_PWR_TRIM_PWRSYS_CTL
                                                                register when changing LDO regulator settings. */
  __IOM uint32_t LDO_1P1V_TRIM;                 /*!< 0x000006E4 LDO trim value for 1.1V. Loaded to the SRSS_PWR_TRIM_PWRSYS_CTL
                                                                register when changing LDO regulator settings. */
  __IOM uint32_t LDO_1P2V_TRIM;                 /*!< 0x000006E8 LDO trim value for 1.2V. Loaded to the SRSS_PWR_TRIM_PWRSYS_CTL
                                                                register when changing LDO regulator settings. */
   __IM uint32_t RESERVED4[4];
  __IOM uint32_t PWR_TRIM_WAKE_CTL;             /*!< 0x000006FC Wakeup delay values for ULP, LP, MF and OD modes (4 values)
                                                                loaded to the PWR_TRIM_WAKE_CTL register */
  __IOM uint32_t CPUSS_TRIM_ROM_CTL_ULP;        /*!< 0x00000700 CPUSS TRIM ROM CTL ULP value */
  __IOM uint32_t CPUSS_TRIM_ROM_CTL_LP;         /*!< 0x00000704 CPUSS TRIM ROM CTL LP  value */
  __IOM uint32_t CPUSS_TRIM_ROM_CTL_MF;         /*!< 0x00000708 CPUSS TRIM ROM CTL MF  value */
  __IOM uint32_t CPUSS_TRIM_ROM_CTL_OD;         /*!< 0x0000070C CPUSS TRIM ROM CTL OD  value */
  __IOM uint32_t CPUSS_TRIM_RAM_CTL_ULP;        /*!< 0x00000710 CPUSS TRIM RAM CTL ULP value */
  __IOM uint32_t CPUSS_TRIM_RAM_CTL_LP;         /*!< 0x00000714 CPUSS TRIM RAM CTL LP  value */
  __IOM uint32_t CPUSS_TRIM_RAM_CTL_MF;         /*!< 0x00000718 CPUSS TRIM RAM CTL MF  value */
  __IOM uint32_t CPUSS_TRIM_RAM_CTL_OD;         /*!< 0x0000071C CPUSS TRIM RAM CTL OD  value */
  __IOM uint32_t CPUSS_TRIM_ROM_CTL_HALF_ULP;   /*!< 0x00000720 CPUSS TRIM ROM CTL HALF ULP value */
  __IOM uint32_t CPUSS_TRIM_ROM_CTL_HALF_LP;    /*!< 0x00000724 CPUSS TRIM ROM CTL HALF LP  value */
  __IOM uint32_t CPUSS_TRIM_ROM_CTL_HALF_MF;    /*!< 0x00000728 CPUSS TRIM ROM CTL HALF MF  value */
  __IOM uint32_t CPUSS_TRIM_ROM_CTL_HALF_OD;    /*!< 0x0000072C CPUSS TRIM ROM CTL HALF OD  value */
  __IOM uint32_t CPUSS_TRIM_RAM_CTL_HALF_ULP;   /*!< 0x00000730 CPUSS TRIM RAM CTL HALF ULP value */
  __IOM uint32_t CPUSS_TRIM_RAM_CTL_HALF_LP;    /*!< 0x00000734 CPUSS TRIM RAM CTL HALF LP  value */
  __IOM uint32_t CPUSS_TRIM_RAM_CTL_HALF_MF;    /*!< 0x00000738 CPUSS TRIM RAM CTL HALF MF  value */
  __IOM uint32_t CPUSS_TRIM_RAM_CTL_HALF_OD;    /*!< 0x0000073C CPUSS TRIM RAM CTL HALF OD  value */
  __IOM uint32_t BASIC_TRIMS_SORT_FLAG;         /*!< 0x00000740 Signature that indicates that the sort trims are valid =
                                                                0x631A_1FAC */
  __IOM uint32_t BASIC_TRIMS_SORT[6];           /*!< 0x00000744 Copy of the BASIC_TRIM values from EFUSE. Used in SORT and
                                                                PROVISIONED life cycles before BASIC_TRIM values are written to
                                                                the efuses */
   __IM uint32_t RESERVED5[41];
  __IOM uint32_t SFLASH_ROW_COUNTER_IFX;        /*!< 0x00000800 Write counter for working copy of counter page */
  __IOM uint32_t BOOTROW_CRC;                   /*!< 0x00000804 CRC of the BOOTROW -- See Boot SAS 12.1 'Security Requirements'
                                                                item #5 */
  __IOM uint8_t  ICV_ROT_KEY_REVOCATION;        /*!< 0x00000808 IFX Root Of Trust Key Revocation to allow for using the second
                                                                key if the first key is revoked due to compromised. The pattern
                                                                of 1-byte state that indicate the key has been revoked can be
                                                                any numbers but not all zeros or all ones */
  __IOM uint8_t  UNUSED_BYTE;                   /*!< 0x00000809 Unused for BOY2. */
  __IOM uint8_t  PROT_FW_ROT_KEY_REVOCATION;    /*!< 0x0000080A Protected FW Root Of Trust Key Revocation to allow for using
                                                                the second key if the first key is revoked due to compromised.
                                                                The pattern of 1-byte state that indicate the key has been
                                                                revoked can be any numbers but not all zeros or all ones */
  __IOM uint8_t  OEM_ROT_KEY_REVOCATION;        /*!< 0x0000080B OEM Root Of Trust Key Revocation to allow for using the second
                                                                key if the first key is revoked due to compromised. The pattern
                                                                of 1-byte state that indicate the key has been revoked can be
                                                                any numbers but not all zeros or all ones */
  __IOM uint8_t  NV_COUNTER_RAMAPP;             /*!< 0x0000080C 8-bit ANTI_ROLLBACK_COUNTER for RAM Apps */
  __IOM uint8_t  NV_COUNTER_L1;                 /*!< 0x0000080D 8-bit ANTI_ROLLBACK_COUNTER is used to prevent rollback of OEM
                                                                application update. */
  __IOM uint8_t  NV_COUNTER_L2;                 /*!< 0x0000080E 8-bit ANTI_ROLLBACK_COUNTER is used to prevent rollback of OEM
                                                                application update. */
  __IOM uint8_t  NV_COUNTER_PROT_FW;            /*!< 0x0000080F 8-bit ANTI_ROLLBACK_COUNTER is used to prevent rollback of
                                                                Protected FW */
  __IOM uint8_t  RMA_ATTEMPT_COUNTER;           /*!< 0x00000810 8-bit COUNTER Limits unsuccessful RMA attempts */
   __IM uint8_t  RESERVED6[3];
  __IOM uint32_t PROV_OEM_COMPLETE;             /*!< 0x00000814 OEM assets are finalized in SFLASH, no further update is
                                                                allowed vs. further updates are allowed */
  __IOM uint8_t  FB_FLAGS[4];                   /*!< 0x00000818 For internal use only, a default value of 0 should be used at
                                                                production. Allows togging GPIO pin at the start and end of
                                                                Flash boot to perform the boot time measurements. */
  __IOM uint8_t  L1_HASH[16];                   /*!< 0x0000081C SHA-256 hash of L1 image. Updated after signature check
                                                                succeeds. */
  __IOM uint8_t  L2_HASH[16];                   /*!< 0x0000082C SHA-256 hash of L2 image. Updated after signature check
                                                                succeeds. */
  __IOM uint8_t  PROT_FW_HASH[16];              /*!< 0x0000083C SHA-256 hash of protected FW image. Updated after signature
                                                                check succeeds. */
   __IM uint32_t RESERVED7[2];
  __IOM uint32_t PROT_FW_ENABLED;               /*!< 0x00000854 When enabled, BootFW launches PROTECTED_FW and uses PROT_FW
                                                                policy to configure PROTECTED_FW. 0xC39D_5455 (SEC_TRUE) -
                                                                Protected FW is enabled. 0x151D_D9BB (SEC_FALSE) - Protected FW
                                                                is disabled. Other - Invalid value. */
  __IOM uint32_t PROT_FW_AUTH_CTL;              /*!< 0x00000858 An authentication control for PROT_FW: 0xXXXX_5A3C - Use
                                                                SHA-256 comparison against PROT_FW_HASH instead of ECDSA as a
                                                                signature authentication of PROT_FW app image. 0xXXXX_0F96 - Use
                                                                ECDSA as a signature authentication of PROT_FW app image.
                                                                0x5A3C_XXXX - BootFW to skip an authentication for the next
                                                                application. 0x0F96_XXXX - BootFW to authenticate a next
                                                                application after PROT_FW app. */
  __IOM uint8_t  PROT_FW_ROT_KEY_0_HASH[16];    /*!< 0x0000085C Truncated SHA-256 for a public key which authenticates this
                                                                application. May be revoked by PROT_FW_ROT_KEY_REVOCATION (which
                                                                belongs to IFX policy) */
  __IOM uint8_t  PROT_FW_ROT_KEY_1_HASH[16];    /*!< 0x0000086C Truncated SHA-256 for a public key which authenticates this
                                                                application. Used if first key has been revoked. */
   __IM uint32_t RESERVED8[4];
  __IOM uint32_t PROT_FW_ADDR;                  /*!< 0x0000088C Start address of protected FW */
  __IOM uint32_t PROT_FW_SIZE;                  /*!< 0x00000890 Size of protected FW */
  __IOM uint32_t PROT_FW_RW_ADDR;               /*!< 0x00000894 Start of protected FW RW area in flash */
  __IOM uint32_t PROT_FW_RW_SIZE;               /*!< 0x00000898 Size of protected FW RW area in flash */
  __IOM uint32_t PROT_FW_RAM_ADDR;              /*!< 0x0000089C Start of protected FW RAM */
  __IOM uint32_t PROT_FW_RAM_SIZE;              /*!< 0x000008A0 Size of protected FW RAM */
  __IOM uint32_t PROT_FW_PC_CTL_VALID;          /*!< 0x000008A4 1 = PC1 can only be entered via PC1 interrupt handler (Sets
                                                                CM33_PC_CTL.VALID[bit 1] = 1) 0 = PC1 is not 'special'.
                                                                Protected FW may be called without CM33_PC1_HANDLER interrupt
                                                                vector */
  __IOM uint32_t PROT_FW_PC1_HANDLER;           /*!< 0x000008A8 PC1_HANDLER is used to switch to PC1 when it is a 'Special' PC */
  __IOM uint32_t PROT_FW_COMPLETE;              /*!< 0x000008AC 0xC39D_5455 (SEC_TRUE), the assets are finalized in SFLASH, no
                                                                further update is allowed. 0x151D_D9BB (SEC_FALSE),
                                                                cyapp_prot_fw_policy may be called multiple times to rewrite the
                                                                PROT_FW assets in SFLASH. Other, the same as SEC_TRUE. */
  __IOM uint8_t  IFX_REVOCATION_KEY_HASH[16];   /*!< 0x000008B0 Hash of IFX revocation key */
  __IOM uint8_t  IFX_ROT_KEY_0_HASH[16];        /*!< 0x000008C0 Hash of Infineon Root of Trust Key 0 */
  __IOM uint8_t  IFX_ROT_KEY_1_HASH[16];        /*!< 0x000008D0 Hash of Infineon Root of Trust Key 1 */
   __IM uint32_t RESERVED9[72];
  __IOM uint32_t ACCESS_RESTRICT;               /*!< 0x00000A00 A debug policy, bits are the same as CPUSS.AP_CTL register */
  __IOM uint32_t ACCESS_RESTRICT_2;             /*!< 0x00000A04 Additional debug policies.  See _Regs tab for details */
  __IOM uint32_t LISTEN_WINDOW;                 /*!< 0x00000A08 A debug policy, bits are the same as CPUSS.AP_CTL register */
  __IOM uint32_t BOOT_CFG_ID;                   /*!< 0x00000A0C See the Confluence page MXSV2BOOT/PSOC_C3+Provisioning */
  __IOM uint32_t BOOT_BANK_CTR_ADDR;            /*!< 0x00000A10 Pointer to a 32-bit counter that indicates the valid bank. If
                                                                the pointer is 0, bank switching is disabled. When the pointer
                                                                is non-zero, it refers to a pair of counters at the same offset
                                                                in flash, one in bank 0, the other in bank 1. This counter is
                                                                updated during the live update DFU procedure after the signature
                                                                check has been performed. If the counter in bank 0 is larger,
                                                                bank 0 is selected as the lower address range. If the counter in
                                                                bank 1 is larger, bank 1 is selected as the lower address range.
                                                                After the bank has been selected, the boot flow is the same as
                                                                the non-banked flow. */
  __IOM uint32_t BOOT_FAST_AUTH;                /*!< 0x00000A14 0xXXXX_5A3C - Fast authentication for L1 application (also for
                                                                Protected FW). 0x5A3C_XXXX - Fast authentication for L2
                                                                application. 0xXXXX_0000 - no Fast authentication for L1 app.
                                                                0x0000_XXXX - no Fast authentication for L2 app. Other - Invalid
                                                                data. */
  __IOM uint32_t BOOT_AUTH_L2;                  /*!< 0x00000A18 0xC39D_5455 (SEC_TRUE) - Authenticate L2 slot. 0x151D_D9BB
                                                                (SEC_FALSE) - Skip L2 slot authentication. Other - invalid. */
  __IOM uint32_t BOOT_MOVE_APP;                 /*!< 0x00000A1C 0xC39D_5455 (SEC_TRUE) - Enable a feature. 0x151D_D9BB
                                                                (SEC_FALSE) - Disable a feature. Other - Invalid value. */
  __IOM uint32_t BOOT_APP_LAYOUT_0_ADDR;        /*!< 0x00000A20 A layout of the applications in FLASH. Note PROT_FW app and IFX
                                                                RAM applications do are not using this layout. Consists of
                                                                (addr, size)*3 which may define a layout up to three
                                                                applications. */
  __IOM uint32_t BOOT_APP_LAYOUT_0_SIZE;        /*!< 0x00000A24 0 */
  __IOM uint32_t BOOT_APP_LAYOUT_1_ADDR;        /*!< 0x00000A28 0 */
  __IOM uint32_t BOOT_APP_LAYOUT_1_SIZE;        /*!< 0x00000A2C 0 */
  __IOM uint32_t BOOT_APP_LAYOUT_2_ADDR;        /*!< 0x00000A30 0 */
  __IOM uint32_t BOOT_APP_LAYOUT_2_SIZE;        /*!< 0x00000A34 0 */
  __IOM uint8_t  OEM_ROT_KEY_0_HASH[16];        /*!< 0x00000A38 Hash of primary OEM_ROT_KEY */
  __IOM uint8_t  OEM_ROT_KEY_1_HASH[16];        /*!< 0x00000A48 Hash of secondary OEM_ROT_KEY */
  __IOM uint8_t  BOOT_OD_CLK;                   /*!< 0x00000A58 For PSOC C3: 0 - 50MHz@1.2V 0x55 - 100MHz@1.2V 0xaa
                                                                - 180MHz@1.2V */
  __IOM uint8_t  PC_CTL_VALID;                  /*!< 0x00000A59 4-bit Bitfield - Bit 0 is unused, Bits 1-3 control PC1-3
                                                                handlers 1 = PCx can only be entered via PCx interrupt handler
                                                                (Sets CM33_PC_CTL.VALID[bit x] = 1) 0 = PCx is not 'special'. PC
                                                                may be switched to this value without CM33_PCx_HANDLER interrupt
                                                                vector When Protected FW is active, bit 1 cannot be set from OEM
                                                                policy */
   __IM uint16_t RESERVED10;
  __IOM uint32_t PC1_HANDLER;                   /*!< 0x00000A5C PC1_HANDLER is used to switch to PC1 when it is a 'Special' PC */
  __IOM uint32_t PC2_HANDLER;                   /*!< 0x00000A60 PC2_HANDLER is used to switch to PC1 when it is a 'Special' PC */
  __IOM uint32_t PC3_HANDLER;                   /*!< 0x00000A64 PC3_HANDLER is used to switch to PC1 when it is a 'Special' PC */
  __IOM uint32_t DFU_ENABLE;                    /*!< 0x00000A68 DFU is enabled when (GPIO_DFU_PINS != 0) and (DFU_ENABLE ==
                                                                SEC_TRUE). 0xC39D_5455 (SEC_TRUE) - DFU policy is enabled.
                                                                0x151D_D9BB (SEC_FALSE) - DFU policy is disabled. Other -
                                                                Invalid values. */
  __IOM uint32_t DFU_L1_UPDATE;                 /*!< 0x00000A6C Allow L1 update for (BOOT_CFG_ID == THREE_SLOTS). 0xC39D_5455
                                                                (SEC_TRUE) - L1 may be updated many times. 0x151D_D9BB
                                                                (SEC_FALSE) - Do not allow L1 update with DFU. Other - invalid
                                                                values. */
  __IOM uint8_t  N_RAM_MPC;                     /*!< 0x00000A70 Number of RAM MPC structs in the following table */
  __IOM uint8_t  N_FLASH_MPC;                   /*!< 0x00000A71 Number of flash MPC structs in the following table */
   __IM uint16_t RESERVED11;
  __IOM uint32_t MPC_STRUCT[64];                /*!< 0x00000A74 RAM MPC structs followed by Flash MPC structs */
   __IM uint32_t RESERVED12[547];
  __IOM uint32_t FLASH_BOOT_OBJECT_SIZE;        /*!< 0x00001400 Flash Boot - Object Size */
  __IOM uint32_t FLASH_BOOT_VERSION_HIGH;       /*!< 0x00001404 Flash Boot - Major Version */
  __IOM uint32_t FLASH_BOOT_VERSION_LOW;        /*!< 0x00001408 Flash Boot - Minor version */
  __IOM uint32_t FB_RESET_HANDLER_ADDR;         /*!< 0x0000140C Flash Boot - Reset vector */
  __IOM uint32_t FB_FUNC_LIST[8];               /*!< 0x00001410 Flash Boot - Function pointer table */
  __IOM uint8_t  FLASH_BOOT_CODE[25040];        /*!< 0x00001430 Flash Boot - Code and Data */
  __IOM uint32_t SFLASH_ROW_COUNTER_HUK;        /*!< 0x00007600 Write counter for HUK flash row + tag indicating HUK flash row */
  __IOM uint8_t  HUK[32];                       /*!< 0x00007604 Hardware Unique Key */
} SFLASH_Type;                                  /*!< Size = 30244 (0x7624) */


/* SFLASH.SI_REVISION_ID */
#define SFLASH_SI_REVISION_ID_SI_REVISION_ID_Pos 0UL
#define SFLASH_SI_REVISION_ID_SI_REVISION_ID_Msk 0xFFUL
/* SFLASH.SILICON_ID */
#define SFLASH_SILICON_ID_ID_Pos                0UL
#define SFLASH_SILICON_ID_ID_Msk                0xFFFFUL
/* SFLASH.FAMILY_ID */
#define SFLASH_FAMILY_ID_FAMILY_ID_Pos          0UL
#define SFLASH_FAMILY_ID_FAMILY_ID_Msk          0xFFFFUL
/* SFLASH.SFLASH_SVN */
#define SFLASH_SFLASH_SVN_DATA32_Pos            0UL
#define SFLASH_SFLASH_SVN_DATA32_Msk            0xFFFFFFFFUL
/* SFLASH.DIE_LOT */
#define SFLASH_DIE_LOT_LOT_Pos                  0UL
#define SFLASH_DIE_LOT_LOT_Msk                  0xFFUL
/* SFLASH.DIE_WAFER */
#define SFLASH_DIE_WAFER_WAFER_Pos              0UL
#define SFLASH_DIE_WAFER_WAFER_Msk              0xFFUL
/* SFLASH.DIE_X */
#define SFLASH_DIE_X_X_Pos                      0UL
#define SFLASH_DIE_X_X_Msk                      0xFFUL
/* SFLASH.DIE_Y */
#define SFLASH_DIE_Y_Y_Pos                      0UL
#define SFLASH_DIE_Y_Y_Msk                      0xFFUL
/* SFLASH.DIE_SORT */
#define SFLASH_DIE_SORT_S1_PASS_Pos             0UL
#define SFLASH_DIE_SORT_S1_PASS_Msk             0x1UL
#define SFLASH_DIE_SORT_S2_PASS_Pos             1UL
#define SFLASH_DIE_SORT_S2_PASS_Msk             0x2UL
#define SFLASH_DIE_SORT_S3_PASS_Pos             2UL
#define SFLASH_DIE_SORT_S3_PASS_Msk             0x4UL
#define SFLASH_DIE_SORT_CRI_PASS_Pos            3UL
#define SFLASH_DIE_SORT_CRI_PASS_Msk            0x8UL
#define SFLASH_DIE_SORT_CHI_PASS_Pos            4UL
#define SFLASH_DIE_SORT_CHI_PASS_Msk            0x10UL
#define SFLASH_DIE_SORT_ENG_PASS_Pos            5UL
#define SFLASH_DIE_SORT_ENG_PASS_Msk            0x20UL
/* SFLASH.DIE_MINOR */
#define SFLASH_DIE_MINOR_MINOR_Pos              0UL
#define SFLASH_DIE_MINOR_MINOR_Msk              0xFFUL
/* SFLASH.DIE_DAY */
#define SFLASH_DIE_DAY_MINOR_Pos                0UL
#define SFLASH_DIE_DAY_MINOR_Msk                0xFFUL
/* SFLASH.DIE_MONTH */
#define SFLASH_DIE_MONTH_MINOR_Pos              0UL
#define SFLASH_DIE_MONTH_MINOR_Msk              0xFFUL
/* SFLASH.DIE_YEAR */
#define SFLASH_DIE_YEAR_MINOR_Pos               0UL
#define SFLASH_DIE_YEAR_MINOR_Msk               0xFFUL
/* SFLASH.CSP_PANEL_ID */
#define SFLASH_CSP_PANEL_ID_DATA32_Pos          0UL
#define SFLASH_CSP_PANEL_ID_DATA32_Msk          0xFFFFFFFFUL
/* SFLASH.SAR_CALOFFST_0_N40C */
#define SFLASH_SAR_CALOFFST_0_N40C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_0_N40C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_0_N40C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_0_N40C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_0_N40C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_0_N40C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_0_N40C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_0_N40C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALOFFST_1_N40C */
#define SFLASH_SAR_CALOFFST_1_N40C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_1_N40C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_1_N40C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_1_N40C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_1_N40C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_1_N40C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_1_N40C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_1_N40C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALOFFST_2_N40C */
#define SFLASH_SAR_CALOFFST_2_N40C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_2_N40C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_2_N40C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_2_N40C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_2_N40C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_2_N40C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_2_N40C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_2_N40C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALOFFST_3_N40C */
#define SFLASH_SAR_CALOFFST_3_N40C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_3_N40C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_3_N40C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_3_N40C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_3_N40C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_3_N40C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_3_N40C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_3_N40C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALOFFST_0_125C */
#define SFLASH_SAR_CALOFFST_0_125C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_0_125C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_0_125C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_0_125C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_0_125C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_0_125C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_0_125C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_0_125C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALOFFST_1_125C */
#define SFLASH_SAR_CALOFFST_1_125C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_1_125C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_1_125C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_1_125C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_1_125C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_1_125C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_1_125C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_1_125C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALOFFST_2_125C */
#define SFLASH_SAR_CALOFFST_2_125C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_2_125C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_2_125C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_2_125C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_2_125C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_2_125C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_2_125C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_2_125C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALOFFST_3_125C */
#define SFLASH_SAR_CALOFFST_3_125C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_3_125C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_3_125C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_3_125C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_3_125C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_3_125C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_3_125C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_3_125C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALOFFST_0_25C */
#define SFLASH_SAR_CALOFFST_0_25C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_0_25C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_0_25C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_0_25C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_0_25C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_0_25C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_0_25C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_0_25C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALOFFST_1_25C */
#define SFLASH_SAR_CALOFFST_1_25C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_1_25C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_1_25C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_1_25C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_1_25C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_1_25C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_1_25C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_1_25C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALOFFST_2_25C */
#define SFLASH_SAR_CALOFFST_2_25C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_2_25C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_2_25C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_2_25C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_2_25C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_2_25C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_2_25C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_2_25C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALOFFST_3_25C */
#define SFLASH_SAR_CALOFFST_3_25C_OFFSET_4N_0_Pos 0UL
#define SFLASH_SAR_CALOFFST_3_25C_OFFSET_4N_0_Msk 0x7FUL
#define SFLASH_SAR_CALOFFST_3_25C_OFFSET_4N_1_Pos 8UL
#define SFLASH_SAR_CALOFFST_3_25C_OFFSET_4N_1_Msk 0x7F00UL
#define SFLASH_SAR_CALOFFST_3_25C_OFFSET_4N_2_Pos 16UL
#define SFLASH_SAR_CALOFFST_3_25C_OFFSET_4N_2_Msk 0x7F0000UL
#define SFLASH_SAR_CALOFFST_3_25C_OFFSET_4N_3_Pos 24UL
#define SFLASH_SAR_CALOFFST_3_25C_OFFSET_4N_3_Msk 0x7F000000UL
/* SFLASH.SAR_CALREFPT */
#define SFLASH_SAR_CALREFPT_DATA32_Pos          0UL
#define SFLASH_SAR_CALREFPT_DATA32_Msk          0xFFFFFFFFUL
/* SFLASH.SAR_TEMP_COEF_A */
#define SFLASH_SAR_TEMP_COEF_A_DATA32_Pos       0UL
#define SFLASH_SAR_TEMP_COEF_A_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.SAR_TEMP_COEF_B */
#define SFLASH_SAR_TEMP_COEF_B_DATA32_Pos       0UL
#define SFLASH_SAR_TEMP_COEF_B_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.SAR_TEMP_COEF_C */
#define SFLASH_SAR_TEMP_COEF_C_DATA32_Pos       0UL
#define SFLASH_SAR_TEMP_COEF_C_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.SAR_TEMP_COEF_D */
#define SFLASH_SAR_TEMP_COEF_D_DATA32_Pos       0UL
#define SFLASH_SAR_TEMP_COEF_D_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.SAR_CAL_LIN_TABLE */
#define SFLASH_SAR_CAL_LIN_TABLE_DATA32_Pos     0UL
#define SFLASH_SAR_CAL_LIN_TABLE_DATA32_Msk     0xFFFFFFFFUL
/* SFLASH.SAR_CALGAINC */
#define SFLASH_SAR_CALGAINC_DATA32_Pos          0UL
#define SFLASH_SAR_CALGAINC_DATA32_Msk          0xFFFFFFFFUL
/* SFLASH.SAR_CALGAINF */
#define SFLASH_SAR_CALGAINF_DATA32_Pos          0UL
#define SFLASH_SAR_CALGAINF_DATA32_Msk          0xFFFFFFFFUL
/* SFLASH.SAR_INFRA_TRIM_TABLE */
#define SFLASH_SAR_INFRA_TRIM_TABLE_DATA32_Pos  0UL
#define SFLASH_SAR_INFRA_TRIM_TABLE_DATA32_Msk  0xFFFFFFFFUL
/* SFLASH.LDO_0P9V_TRIM */
#define SFLASH_LDO_0P9V_TRIM_DATA32_Pos         0UL
#define SFLASH_LDO_0P9V_TRIM_DATA32_Msk         0xFFFFFFFFUL
/* SFLASH.LDO_1P0V_TRIM */
#define SFLASH_LDO_1P0V_TRIM_DATA32_Pos         0UL
#define SFLASH_LDO_1P0V_TRIM_DATA32_Msk         0xFFFFFFFFUL
/* SFLASH.LDO_1P1V_TRIM */
#define SFLASH_LDO_1P1V_TRIM_DATA32_Pos         0UL
#define SFLASH_LDO_1P1V_TRIM_DATA32_Msk         0xFFFFFFFFUL
/* SFLASH.LDO_1P2V_TRIM */
#define SFLASH_LDO_1P2V_TRIM_DATA32_Pos         0UL
#define SFLASH_LDO_1P2V_TRIM_DATA32_Msk         0xFFFFFFFFUL
/* SFLASH.PWR_TRIM_WAKE_CTL */
#define SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_0P9V_Pos 0UL
#define SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_0P9V_Msk 0xFFUL
#define SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_1P0V_Pos 8UL
#define SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_1P0V_Msk 0xFF00UL
#define SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_1P1V_Pos 16UL
#define SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_1P1V_Msk 0xFF0000UL
#define SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_1P2V_Pos 24UL
#define SFLASH_PWR_TRIM_WAKE_CTL_WAKE_DELAY_1P2V_Msk 0xFF000000UL
/* SFLASH.CPUSS_TRIM_ROM_CTL_ULP */
#define SFLASH_CPUSS_TRIM_ROM_CTL_ULP_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_ROM_CTL_ULP_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_ROM_CTL_LP */
#define SFLASH_CPUSS_TRIM_ROM_CTL_LP_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_ROM_CTL_LP_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_ROM_CTL_MF */
#define SFLASH_CPUSS_TRIM_ROM_CTL_MF_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_ROM_CTL_MF_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_ROM_CTL_OD */
#define SFLASH_CPUSS_TRIM_ROM_CTL_OD_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_ROM_CTL_OD_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_RAM_CTL_ULP */
#define SFLASH_CPUSS_TRIM_RAM_CTL_ULP_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_RAM_CTL_ULP_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_RAM_CTL_LP */
#define SFLASH_CPUSS_TRIM_RAM_CTL_LP_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_RAM_CTL_LP_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_RAM_CTL_MF */
#define SFLASH_CPUSS_TRIM_RAM_CTL_MF_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_RAM_CTL_MF_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_RAM_CTL_OD */
#define SFLASH_CPUSS_TRIM_RAM_CTL_OD_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_RAM_CTL_OD_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_ROM_CTL_HALF_ULP */
#define SFLASH_CPUSS_TRIM_ROM_CTL_HALF_ULP_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_ROM_CTL_HALF_ULP_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_ROM_CTL_HALF_LP */
#define SFLASH_CPUSS_TRIM_ROM_CTL_HALF_LP_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_ROM_CTL_HALF_LP_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_ROM_CTL_HALF_MF */
#define SFLASH_CPUSS_TRIM_ROM_CTL_HALF_MF_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_ROM_CTL_HALF_MF_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_ROM_CTL_HALF_OD */
#define SFLASH_CPUSS_TRIM_ROM_CTL_HALF_OD_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_ROM_CTL_HALF_OD_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_RAM_CTL_HALF_ULP */
#define SFLASH_CPUSS_TRIM_RAM_CTL_HALF_ULP_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_RAM_CTL_HALF_ULP_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_RAM_CTL_HALF_LP */
#define SFLASH_CPUSS_TRIM_RAM_CTL_HALF_LP_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_RAM_CTL_HALF_LP_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_RAM_CTL_HALF_MF */
#define SFLASH_CPUSS_TRIM_RAM_CTL_HALF_MF_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_RAM_CTL_HALF_MF_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.CPUSS_TRIM_RAM_CTL_HALF_OD */
#define SFLASH_CPUSS_TRIM_RAM_CTL_HALF_OD_DATA32_Pos 0UL
#define SFLASH_CPUSS_TRIM_RAM_CTL_HALF_OD_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.BASIC_TRIMS_SORT_FLAG */
#define SFLASH_BASIC_TRIMS_SORT_FLAG_DATA32_Pos 0UL
#define SFLASH_BASIC_TRIMS_SORT_FLAG_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.BASIC_TRIMS_SORT */
#define SFLASH_BASIC_TRIMS_SORT_DATA32_Pos      0UL
#define SFLASH_BASIC_TRIMS_SORT_DATA32_Msk      0xFFFFFFFFUL
/* SFLASH.SFLASH_ROW_COUNTER_IFX */
#define SFLASH_SFLASH_ROW_COUNTER_IFX_DATA32_Pos 0UL
#define SFLASH_SFLASH_ROW_COUNTER_IFX_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.BOOTROW_CRC */
#define SFLASH_BOOTROW_CRC_DATA32_Pos           0UL
#define SFLASH_BOOTROW_CRC_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.ICV_ROT_KEY_REVOCATION */
#define SFLASH_ICV_ROT_KEY_REVOCATION_DATA32_Pos 0UL
#define SFLASH_ICV_ROT_KEY_REVOCATION_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.UNUSED_BYTE */
#define SFLASH_UNUSED_BYTE_DATA32_Pos           0UL
#define SFLASH_UNUSED_BYTE_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.PROT_FW_ROT_KEY_REVOCATION */
#define SFLASH_PROT_FW_ROT_KEY_REVOCATION_DATA32_Pos 0UL
#define SFLASH_PROT_FW_ROT_KEY_REVOCATION_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.OEM_ROT_KEY_REVOCATION */
#define SFLASH_OEM_ROT_KEY_REVOCATION_DATA8_Pos 0UL
#define SFLASH_OEM_ROT_KEY_REVOCATION_DATA8_Msk 0xFFUL
/* SFLASH.NV_COUNTER_RAMAPP */
#define SFLASH_NV_COUNTER_RAMAPP_DATA8_Pos      0UL
#define SFLASH_NV_COUNTER_RAMAPP_DATA8_Msk      0xFFUL
/* SFLASH.NV_COUNTER_L1 */
#define SFLASH_NV_COUNTER_L1_DATA8_Pos          0UL
#define SFLASH_NV_COUNTER_L1_DATA8_Msk          0xFFUL
/* SFLASH.NV_COUNTER_L2 */
#define SFLASH_NV_COUNTER_L2_DATA8_Pos          0UL
#define SFLASH_NV_COUNTER_L2_DATA8_Msk          0xFFUL
/* SFLASH.NV_COUNTER_PROT_FW */
#define SFLASH_NV_COUNTER_PROT_FW_DATA32_Pos    0UL
#define SFLASH_NV_COUNTER_PROT_FW_DATA32_Msk    0xFFFFFFFFUL
/* SFLASH.RMA_ATTEMPT_COUNTER */
#define SFLASH_RMA_ATTEMPT_COUNTER_DATA32_Pos   0UL
#define SFLASH_RMA_ATTEMPT_COUNTER_DATA32_Msk   0xFFFFFFFFUL
/* SFLASH.PROV_OEM_COMPLETE */
#define SFLASH_PROV_OEM_COMPLETE_DATA32_Pos     0UL
#define SFLASH_PROV_OEM_COMPLETE_DATA32_Msk     0xFFFFFFFFUL
/* SFLASH.FB_FLAGS */
#define SFLASH_FB_FLAGS_DATA32_Pos              0UL
#define SFLASH_FB_FLAGS_DATA32_Msk              0xFFFFFFFFUL
/* SFLASH.L1_HASH */
#define SFLASH_L1_HASH_DATA8_Pos                0UL
#define SFLASH_L1_HASH_DATA8_Msk                0xFFUL
/* SFLASH.L2_HASH */
#define SFLASH_L2_HASH_DATA8_Pos                0UL
#define SFLASH_L2_HASH_DATA8_Msk                0xFFUL
/* SFLASH.PROT_FW_HASH */
#define SFLASH_PROT_FW_HASH_DATA8_Pos           0UL
#define SFLASH_PROT_FW_HASH_DATA8_Msk           0xFFUL
/* SFLASH.PROT_FW_ENABLED */
#define SFLASH_PROT_FW_ENABLED_DATA8_Pos        0UL
#define SFLASH_PROT_FW_ENABLED_DATA8_Msk        0xFFUL
/* SFLASH.PROT_FW_AUTH_CTL */
#define SFLASH_PROT_FW_AUTH_CTL_DATA8_Pos       0UL
#define SFLASH_PROT_FW_AUTH_CTL_DATA8_Msk       0xFFUL
/* SFLASH.PROT_FW_ROT_KEY_0_HASH */
#define SFLASH_PROT_FW_ROT_KEY_0_HASH_DATA32_Pos 0UL
#define SFLASH_PROT_FW_ROT_KEY_0_HASH_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.PROT_FW_ROT_KEY_1_HASH */
#define SFLASH_PROT_FW_ROT_KEY_1_HASH_DATA32_Pos 0UL
#define SFLASH_PROT_FW_ROT_KEY_1_HASH_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.PROT_FW_ADDR */
#define SFLASH_PROT_FW_ADDR_DATA32_Pos          0UL
#define SFLASH_PROT_FW_ADDR_DATA32_Msk          0xFFFFFFFFUL
/* SFLASH.PROT_FW_SIZE */
#define SFLASH_PROT_FW_SIZE_DATA32_Pos          0UL
#define SFLASH_PROT_FW_SIZE_DATA32_Msk          0xFFFFFFFFUL
/* SFLASH.PROT_FW_RW_ADDR */
#define SFLASH_PROT_FW_RW_ADDR_DATA32_Pos       0UL
#define SFLASH_PROT_FW_RW_ADDR_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.PROT_FW_RW_SIZE */
#define SFLASH_PROT_FW_RW_SIZE_DATA32_Pos       0UL
#define SFLASH_PROT_FW_RW_SIZE_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.PROT_FW_RAM_ADDR */
#define SFLASH_PROT_FW_RAM_ADDR_DATA32_Pos      0UL
#define SFLASH_PROT_FW_RAM_ADDR_DATA32_Msk      0xFFFFFFFFUL
/* SFLASH.PROT_FW_RAM_SIZE */
#define SFLASH_PROT_FW_RAM_SIZE_DATA32_Pos      0UL
#define SFLASH_PROT_FW_RAM_SIZE_DATA32_Msk      0xFFFFFFFFUL
/* SFLASH.PROT_FW_PC_CTL_VALID */
#define SFLASH_PROT_FW_PC_CTL_VALID_DATA32_Pos  0UL
#define SFLASH_PROT_FW_PC_CTL_VALID_DATA32_Msk  0xFFFFFFFFUL
/* SFLASH.PROT_FW_PC1_HANDLER */
#define SFLASH_PROT_FW_PC1_HANDLER_DATA32_Pos   0UL
#define SFLASH_PROT_FW_PC1_HANDLER_DATA32_Msk   0xFFFFFFFFUL
/* SFLASH.PROT_FW_COMPLETE */
#define SFLASH_PROT_FW_COMPLETE_DATA32_Pos      0UL
#define SFLASH_PROT_FW_COMPLETE_DATA32_Msk      0xFFFFFFFFUL
/* SFLASH.IFX_REVOCATION_KEY_HASH */
#define SFLASH_IFX_REVOCATION_KEY_HASH_DATA32_Pos 0UL
#define SFLASH_IFX_REVOCATION_KEY_HASH_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.IFX_ROT_KEY_0_HASH */
#define SFLASH_IFX_ROT_KEY_0_HASH_DATA8_Pos     0UL
#define SFLASH_IFX_ROT_KEY_0_HASH_DATA8_Msk     0xFFUL
/* SFLASH.IFX_ROT_KEY_1_HASH */
#define SFLASH_IFX_ROT_KEY_1_HASH_DATA8_Pos     0UL
#define SFLASH_IFX_ROT_KEY_1_HASH_DATA8_Msk     0xFFUL
/* SFLASH.ACCESS_RESTRICT */
#define SFLASH_ACCESS_RESTRICT_DATA32_Pos       0UL
#define SFLASH_ACCESS_RESTRICT_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.ACCESS_RESTRICT_2 */
#define SFLASH_ACCESS_RESTRICT_2_SYS_AP_MMIO_Pos 0UL
#define SFLASH_ACCESS_RESTRICT_2_SYS_AP_MMIO_Msk 0x3UL
#define SFLASH_ACCESS_RESTRICT_2_DEBUG_PINS_Pos 4UL
#define SFLASH_ACCESS_RESTRICT_2_DEBUG_PINS_Msk 0xF0UL
#define SFLASH_ACCESS_RESTRICT_2_UNUSED_Pos     8UL
#define SFLASH_ACCESS_RESTRICT_2_UNUSED_Msk     0xFFFF00UL
#define SFLASH_ACCESS_RESTRICT_2_DEBUG_TAG_Pos  24UL
#define SFLASH_ACCESS_RESTRICT_2_DEBUG_TAG_Msk  0xFF000000UL
/* SFLASH.LISTEN_WINDOW */
#define SFLASH_LISTEN_WINDOW_DATA32_Pos         0UL
#define SFLASH_LISTEN_WINDOW_DATA32_Msk         0xFFFFFFFFUL
/* SFLASH.BOOT_CFG_ID */
#define SFLASH_BOOT_CFG_ID_DATA32_Pos           0UL
#define SFLASH_BOOT_CFG_ID_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.BOOT_BANK_CTR_ADDR */
#define SFLASH_BOOT_BANK_CTR_ADDR_DATA8_Pos     0UL
#define SFLASH_BOOT_BANK_CTR_ADDR_DATA8_Msk     0xFFUL
/* SFLASH.BOOT_FAST_AUTH */
#define SFLASH_BOOT_FAST_AUTH_DATA8_Pos         0UL
#define SFLASH_BOOT_FAST_AUTH_DATA8_Msk         0xFFUL
/* SFLASH.BOOT_AUTH_L2 */
#define SFLASH_BOOT_AUTH_L2_DATA8_Pos           0UL
#define SFLASH_BOOT_AUTH_L2_DATA8_Msk           0xFFUL
/* SFLASH.BOOT_MOVE_APP */
#define SFLASH_BOOT_MOVE_APP_DATA8_Pos          0UL
#define SFLASH_BOOT_MOVE_APP_DATA8_Msk          0xFFUL
/* SFLASH.BOOT_APP_LAYOUT_0_ADDR */
#define SFLASH_BOOT_APP_LAYOUT_0_ADDR_DATA32_Pos 0UL
#define SFLASH_BOOT_APP_LAYOUT_0_ADDR_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.BOOT_APP_LAYOUT_0_SIZE */
#define SFLASH_BOOT_APP_LAYOUT_0_SIZE_DATA32_Pos 0UL
#define SFLASH_BOOT_APP_LAYOUT_0_SIZE_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.BOOT_APP_LAYOUT_1_ADDR */
#define SFLASH_BOOT_APP_LAYOUT_1_ADDR_DATA32_Pos 0UL
#define SFLASH_BOOT_APP_LAYOUT_1_ADDR_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.BOOT_APP_LAYOUT_1_SIZE */
#define SFLASH_BOOT_APP_LAYOUT_1_SIZE_DATA8_Pos 0UL
#define SFLASH_BOOT_APP_LAYOUT_1_SIZE_DATA8_Msk 0xFFUL
/* SFLASH.BOOT_APP_LAYOUT_2_ADDR */
#define SFLASH_BOOT_APP_LAYOUT_2_ADDR_DATA32_Pos 0UL
#define SFLASH_BOOT_APP_LAYOUT_2_ADDR_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.BOOT_APP_LAYOUT_2_SIZE */
#define SFLASH_BOOT_APP_LAYOUT_2_SIZE_DATA8_Pos 0UL
#define SFLASH_BOOT_APP_LAYOUT_2_SIZE_DATA8_Msk 0xFFUL
/* SFLASH.OEM_ROT_KEY_0_HASH */
#define SFLASH_OEM_ROT_KEY_0_HASH_DATA8_Pos     0UL
#define SFLASH_OEM_ROT_KEY_0_HASH_DATA8_Msk     0xFFUL
/* SFLASH.OEM_ROT_KEY_1_HASH */
#define SFLASH_OEM_ROT_KEY_1_HASH_DATA8_Pos     0UL
#define SFLASH_OEM_ROT_KEY_1_HASH_DATA8_Msk     0xFFUL
/* SFLASH.BOOT_OD_CLK */
#define SFLASH_BOOT_OD_CLK_DATA32_Pos           0UL
#define SFLASH_BOOT_OD_CLK_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.PC_CTL_VALID */
#define SFLASH_PC_CTL_VALID_DATA32_Pos          0UL
#define SFLASH_PC_CTL_VALID_DATA32_Msk          0xFFFFFFFFUL
/* SFLASH.PC1_HANDLER */
#define SFLASH_PC1_HANDLER_DATA32_Pos           0UL
#define SFLASH_PC1_HANDLER_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.PC2_HANDLER */
#define SFLASH_PC2_HANDLER_DATA32_Pos           0UL
#define SFLASH_PC2_HANDLER_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.PC3_HANDLER */
#define SFLASH_PC3_HANDLER_DATA32_Pos           0UL
#define SFLASH_PC3_HANDLER_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.DFU_ENABLE */
#define SFLASH_DFU_ENABLE_DATA32_Pos            0UL
#define SFLASH_DFU_ENABLE_DATA32_Msk            0xFFFFFFFFUL
/* SFLASH.DFU_L1_UPDATE */
#define SFLASH_DFU_L1_UPDATE_DATA32_Pos         0UL
#define SFLASH_DFU_L1_UPDATE_DATA32_Msk         0xFFFFFFFFUL
/* SFLASH.N_RAM_MPC */
#define SFLASH_N_RAM_MPC_DATA8_Pos              0UL
#define SFLASH_N_RAM_MPC_DATA8_Msk              0xFFUL
/* SFLASH.N_FLASH_MPC */
#define SFLASH_N_FLASH_MPC_DATA8_Pos            0UL
#define SFLASH_N_FLASH_MPC_DATA8_Msk            0xFFUL
/* SFLASH.MPC_STRUCT */
#define SFLASH_MPC_STRUCT_DATA32_Pos            0UL
#define SFLASH_MPC_STRUCT_DATA32_Msk            0xFFFFFFFFUL
/* SFLASH.FLASH_BOOT_OBJECT_SIZE */
#define SFLASH_FLASH_BOOT_OBJECT_SIZE_DATA32_Pos 0UL
#define SFLASH_FLASH_BOOT_OBJECT_SIZE_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.FLASH_BOOT_VERSION_HIGH */
#define SFLASH_FLASH_BOOT_VERSION_HIGH_DATA32_Pos 0UL
#define SFLASH_FLASH_BOOT_VERSION_HIGH_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.FLASH_BOOT_VERSION_LOW */
#define SFLASH_FLASH_BOOT_VERSION_LOW_DATA32_Pos 0UL
#define SFLASH_FLASH_BOOT_VERSION_LOW_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.FB_RESET_HANDLER_ADDR */
#define SFLASH_FB_RESET_HANDLER_ADDR_DATA32_Pos 0UL
#define SFLASH_FB_RESET_HANDLER_ADDR_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.FB_FUNC_LIST */
#define SFLASH_FB_FUNC_LIST_DATA32_Pos          0UL
#define SFLASH_FB_FUNC_LIST_DATA32_Msk          0xFFFFFFFFUL
/* SFLASH.FLASH_BOOT_CODE */
#define SFLASH_FLASH_BOOT_CODE_DATA32_Pos       0UL
#define SFLASH_FLASH_BOOT_CODE_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.SFLASH_ROW_COUNTER_HUK */
#define SFLASH_SFLASH_ROW_COUNTER_HUK_DATA32_Pos 0UL
#define SFLASH_SFLASH_ROW_COUNTER_HUK_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.HUK */
#define SFLASH_HUK_DATA32_Pos                   0UL
#define SFLASH_HUK_DATA32_Msk                   0xFFFFFFFFUL


#endif /* _CYIP_SFLASH_PSC3_H_ */


/* [] END OF FILE */
