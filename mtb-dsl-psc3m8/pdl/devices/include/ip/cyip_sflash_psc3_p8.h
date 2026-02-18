/***************************************************************************//**
* SFLASH IP definitions
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

#ifndef _CYIP_SFLASH_PSC3_P8_H_
#define _CYIP_SFLASH_PSC3_P8_H_

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
  __IOM uint32_t SFLASH_SVN;                    /*!< 0x00000018 SFLASH Subversion -- Manually read from 'show log' of repo root */
   __IM uint32_t RESERVED2[212];
  __IOM uint32_t SVGS_CMP_CFG;                  /*!< 0x0000036C Trim value to load into the SVGS Comparator Configuration
                                                                register */
  __IOM uint32_t SVGS_CMP_TRIP;                 /*!< 0x00000370 Trim value to load into the SVGS Comparator trip-point
                                                                configuration register */
  __IOM uint32_t SVGS_TRIM;                     /*!< 0x00000374 Trim value to load into the SVGS Trim Register */
  __IOM uint32_t SAR_INFRA_TRIM_TABLE[17];      /*!< 0x00000378 Table of trim values loaded to SAR by the mcpass init function.
                                                                The table format is as follows: [32-bits] n_trim_pairs [32-bits
                                                                list] (mmio_addr, mmio_value) x (n_trim_pairs) */
   __IM uint32_t RESERVED3[145];
  __IOM uint8_t  DIE_LOT[3];                    /*!< 0x00000600 Lot Number (3 bytes) */
  __IOM uint8_t  DIE_WAFER;                     /*!< 0x00000603 Wafer Number */
  __IOM uint8_t  DIE_X;                         /*!< 0x00000604 X Position on Wafer, CRI Pass/Fail Bin */
  __IOM uint8_t  DIE_Y;                         /*!< 0x00000605 Y Position on Wafer, CHI Pass/Fail Bin */
  __IOM uint8_t  DIE_SORT;                      /*!< 0x00000606 Sort1/2/3 Pass/Fail Bin */
  __IOM uint8_t  DIE_MINOR;                     /*!< 0x00000607 Minor Revision Number */
  __IOM uint8_t  DIE_DAY;                       /*!< 0x00000608 Day number */
  __IOM uint8_t  DIE_MONTH;                     /*!< 0x00000609 Month number */
  __IOM uint8_t  DIE_YEAR;                      /*!< 0x0000060A Year number */
   __IM uint8_t  RESERVED4;
  __IOM uint32_t CSP_PANEL_ID;                  /*!< 0x0000060C CSP Panel Id to record panel ID of CSP die */
  __IOM uint8_t  GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM; /*!< 0x00000610 SARADC STARTUP Control Register */
   __IM uint8_t  RESERVED5[3];
  __IOM uint32_t GRP0_ADC_CALOFFSET[8];         /*!< 0x00000614 SARADC CAL offset per channel */
  __IOM uint32_t GRP0_ADC_CALGAIN_GAINX1[8];    /*!< 0x00000634 Loaded to the ADC_CALGAIN registers (8 in group 0) */
  __IOM uint32_t GRP0_AFE_CALGAIN_AFE_1;        /*!< 0x00000654 Trim value for AFE_CALGAINAFE_1 register */
  __IOM uint32_t GRP0_AFE_CALGAIN_AFE_2;        /*!< 0x00000658 Trim value for AFE_CALGAINAFE_2 register */
  __IOM uint32_t GRP0_AFE_CALGAIN_AFE_3;        /*!< 0x0000065C Trim value for AFE_CALGAINAFE_3 register */
  __IOM uint32_t GRP0_AFE_CALGAIN_AFE_4;        /*!< 0x00000660 Trim value for AFE_CALGAINAFE_4 register */
  __IOM uint32_t GRP0_AFE_CALOFFSET_AFE_1;      /*!< 0x00000664 Trim value for AFE_CALOFFSETAFE_1 register */
  __IOM uint32_t GRP0_AFE_CALOFFSET_AFE_2;      /*!< 0x00000668 Trim value for AFE_CALOFFSETAFE_2 register */
  __IOM uint32_t GRP0_AFE_CALOFFSET_AFE_3;      /*!< 0x0000066C Trim value for AFE_CALOFFSETAFE_3 register */
  __IOM uint32_t GRP0_AFE_CALOFFSET_AFE_4;      /*!< 0x00000670 Trim value for AFE_CALOFFSETAFE_4 register */
  __IOM uint8_t  GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM; /*!< 0x00000674 SARADC STARTUP Control Register */
   __IM uint8_t  RESERVED6[3];
  __IOM uint32_t GRP1_ADC_CALOFFSET[4];         /*!< 0x00000678 SARADC CAL offset per channel */
  __IOM uint32_t GRP1_ADC_CALGAIN_GAINX1[4];    /*!< 0x00000688 Loaded to the ADC_CALGAIN registers (8 in group 0) */
  __IOM uint32_t GRP1_AFE_CALGAIN_AFE_1;        /*!< 0x00000698 Trim value for AFE_CALGAINAFE_1 register */
  __IOM uint32_t GRP1_AFE_CALGAIN_AFE_2;        /*!< 0x0000069C Trim value for AFE_CALGAINAFE_2 register */
  __IOM uint32_t GRP1_AFE_CALGAIN_AFE_3;        /*!< 0x000006A0 Trim value for AFE_CALGAINAFE_3 register */
  __IOM uint32_t GRP1_AFE_CALGAIN_AFE_4;        /*!< 0x000006A4 Trim value for AFE_CALGAINAFE_4 register */
  __IOM uint32_t GRP1_AFE_CALOFFSET_AFE_1;      /*!< 0x000006A8 Trim value for AFE_CALOFFSETAFE_1 register */
  __IOM uint32_t GRP1_AFE_CALOFFSET_AFE_2;      /*!< 0x000006AC Trim value for AFE_CALOFFSETAFE_2 register */
  __IOM uint32_t GRP1_AFE_CALOFFSET_AFE_3;      /*!< 0x000006B0 Trim value for AFE_CALOFFSETAFE_3 register */
  __IOM uint32_t GRP1_AFE_CALOFFSET_AFE_4;      /*!< 0x000006B4 Trim value for AFE_CALOFFSETAFE_4 register */
  __IOM uint8_t  GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM; /*!< 0x000006B8 SARADC STARTUP Control Register */
   __IM uint8_t  RESERVED7[3];
  __IOM uint32_t GRP2_ADC_CALOFFSET[4];         /*!< 0x000006BC SARADC CAL offset per channel */
  __IOM uint32_t GRP2_ADC_CALGAIN_GAINX1[4];    /*!< 0x000006CC Loaded to the ADC_CALGAIN registers (8 in group 0) */
  __IOM uint32_t GRP2_AFE_CALGAIN_AFE_1;        /*!< 0x000006DC Trim value for AFE_CALGAINAFE_1 register */
  __IOM uint32_t GRP2_AFE_CALGAIN_AFE_2;        /*!< 0x000006E0 Trim value for AFE_CALGAINAFE_2 register */
  __IOM uint32_t GRP2_AFE_CALGAIN_AFE_3;        /*!< 0x000006E4 Trim value for AFE_CALGAINAFE_3 register */
  __IOM uint32_t GRP2_AFE_CALGAIN_AFE_4;        /*!< 0x000006E8 Trim value for AFE_CALGAINAFE_4 register */
  __IOM uint32_t GRP2_AFE_CALOFFSET_AFE_1;      /*!< 0x000006EC Trim value for AFE_CALOFFSETAFE_1 register */
  __IOM uint32_t GRP2_AFE_CALOFFSET_AFE_2;      /*!< 0x000006F0 Trim value for AFE_CALOFFSETAFE_2 register */
  __IOM uint32_t GRP2_AFE_CALOFFSET_AFE_3;      /*!< 0x000006F4 Trim value for AFE_CALOFFSETAFE_3 register */
  __IOM uint32_t GRP2_AFE_CALOFFSET_AFE_4;      /*!< 0x000006F8 Trim value for AFE_CALOFFSETAFE_4 register */
  __IOM uint8_t  GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM; /*!< 0x000006FC SARADC STARTUP Control Register */
   __IM uint8_t  RESERVED8[3];
  __IOM uint32_t GRP3_ADC_CALOFFSET[8];         /*!< 0x00000700 SARADC CAL offset per channel */
  __IOM uint32_t GRP3_ADC_CALGAIN_GAINX1[8];    /*!< 0x00000720 Loaded to the ADC_CALGAIN registers (8 in group 0) */
  __IOM uint32_t GRP3_AFE_CALGAIN_AFE_1;        /*!< 0x00000740 Trim value for AFE_CALGAINAFE_1 register */
  __IOM uint32_t GRP3_AFE_CALGAIN_AFE_2;        /*!< 0x00000744 Trim value for AFE_CALGAINAFE_2 register */
  __IOM uint32_t GRP3_AFE_CALGAIN_AFE_3;        /*!< 0x00000748 Trim value for AFE_CALGAINAFE_3 register */
  __IOM uint32_t GRP3_AFE_CALGAIN_AFE_4;        /*!< 0x0000074C Trim value for AFE_CALGAINAFE_4 register */
  __IOM uint32_t GRP3_AFE_CALOFFSET_AFE_1;      /*!< 0x00000750 Trim value for AFE_CALOFFSETAFE_1 register */
  __IOM uint32_t GRP3_AFE_CALOFFSET_AFE_2;      /*!< 0x00000754 Trim value for AFE_CALOFFSETAFE_2 register */
  __IOM uint32_t GRP3_AFE_CALOFFSET_AFE_3;      /*!< 0x00000758 Trim value for AFE_CALOFFSETAFE_3 register */
  __IOM uint32_t GRP3_AFE_CALOFFSET_AFE_4;      /*!< 0x0000075C Trim value for AFE_CALOFFSETAFE_4 register */
  __IOM uint32_t GRP0_DCSG_TEST_VREF_TRIM;      /*!< 0x00000760 Trim value to load into the Analog Comparator Differential Mode
                                                                Calibration register */
  __IOM uint32_t GRP0_DCSG_DIFF_CALOFFSET;      /*!< 0x00000764 Trim value to load into the Analog Comparator Differential Mode
                                                                Calibration register */
  __IOM uint32_t GRP0_DCSG_SE_CALOFFSET;        /*!< 0x00000768 Trim value to load into the Analog Comparator Single Ended Mode
                                                                Calibration register */
  __IOM uint32_t GRP0_DCSG_DIFF_CALGAIN_1;      /*!< 0x0000076C Trim value to load into the Analog Comparator Differential Mode
                                                                Gain 1 register */
  __IOM uint32_t GRP0_DCSG_DIFF_CALGAIN_2;      /*!< 0x00000770 Trim value to load into the Analog Comparator Differential Mode
                                                                Gain 2 register */
  __IOM uint32_t GRP0_DCSG_SE_CALGAIN;          /*!< 0x00000774 Trim value to load into the Analog Comparator Single Ended Mode
                                                                Gain register */
   __IM uint32_t RESERVED9[30];
  __IOM uint16_t GRP0_DAC_OFFSET_CNFG1;         /*!< 0x000007F0 0 */
  __IOM uint16_t GRP0_DAC_OFFSET_CNFG2;         /*!< 0x000007F2 0 */
  __IOM uint16_t GRP0_DAC_OFFSET_CNFG3;         /*!< 0x000007F4 0 */
  __IOM uint16_t GRP0_DAC_OFFSET_CNFG4;         /*!< 0x000007F6 0 */
  __IOM uint16_t GRP0_DAC_OFFSET_CNFG5;         /*!< 0x000007F8 0 */
  __IOM uint16_t GRP0_DAC_GAIN_CNFG1;           /*!< 0x000007FA 0 */
  __IOM uint16_t GRP0_DAC_GAIN_CNFG2;           /*!< 0x000007FC 0 */
  __IOM uint16_t GRP0_DAC_GAIN_CNFG3;           /*!< 0x000007FE 0 */
  __IOM uint16_t GRP0_DAC_GAIN_CNFG4;           /*!< 0x00000800 0 */
  __IOM uint16_t GRP0_DAC_GAIN_CNFG5;           /*!< 0x00000802 0 */
  __IOM uint16_t GRP0_BUFFER_OFFSET_1;          /*!< 0x00000804 0 */
  __IOM uint16_t GRP0_BUFFER_OFFSET_2;          /*!< 0x00000806 0 */
  __IOM uint32_t GRP1_DCSG_TEST_VREF_TRIM;      /*!< 0x00000808 Note: There are three sets of 6 DCSG registers in GRP1, one for
                                                                each DCSG in the group Trim values to load into the lower 6 bits
                                                                of the TEST register in the DCSG */
  __IOM uint32_t GRP1_DCSG_DIFF_CALOFFSET;      /*!< 0x0000080C Trim value to load into the Analog Comparator Differential Mode
                                                                Calibration register */
  __IOM uint32_t GRP1_DCSG_SE_CALOFFSET;        /*!< 0x00000810 Trim value to load into the Analog Comparator Single Ended Mode
                                                                Calibration register */
  __IOM uint32_t GRP1_DCSG_DIFF_CALGAIN_1;      /*!< 0x00000814 Trim value to load into the Analog Comparator Differential Mode
                                                                Gain 1 register */
  __IOM uint32_t GRP1_DCSG_DIFF_CALGAIN_2;      /*!< 0x00000818 Trim value to load into the Analog Comparator Differential Mode
                                                                Gain 2 register */
  __IOM uint32_t GRP1_DCSG_SE_CALGAIN;          /*!< 0x0000081C Trim value to load into the Analog Comparator Single Ended Mode
                                                                Gain register */
   __IM uint32_t RESERVED10[12];
  __IOM uint16_t GRP1_DAC_OFFSET_CNFG1;         /*!< 0x00000850 Trim value to load into the DAC Offset CNFG1 register */
  __IOM uint16_t GRP1_DAC_OFFSET_CNFG2;         /*!< 0x00000852 Trim value to load into the DAC Offset CNFG2 register */
  __IOM uint16_t GRP1_DAC_OFFSET_CNFG3;         /*!< 0x00000854 Trim value to load into the DAC Offset CNFG3 register */
  __IOM uint16_t GRP1_DAC_OFFSET_CNFG4;         /*!< 0x00000856 Trim value to load into the DAC Offset CNFG4 register */
  __IOM uint16_t GRP1_DAC_OFFSET_CNFG5;         /*!< 0x00000858 Trim value to load into the DAC Offset CNFG5 register */
  __IOM uint16_t GRP1_DAC_GAIN_CNFG1;           /*!< 0x0000085A Trim value to load into the DAC Gain CNFG1 register */
  __IOM uint16_t GRP1_DAC_GAIN_CNFG2;           /*!< 0x0000085C Trim value to load into the DAC Gain CNFG2 register */
  __IOM uint16_t GRP1_DAC_GAIN_CNFG3;           /*!< 0x0000085E Trim value to load into the DAC Gain CNFG3 register */
  __IOM uint16_t GRP1_DAC_GAIN_CNFG4;           /*!< 0x00000860 Trim value to load into the DAC Gain CNFG4 register */
  __IOM uint16_t GRP1_DAC_GAIN_CNFG5;           /*!< 0x00000862 Trim value to load into the DAC Gain CNFG5 register */
  __IOM uint16_t GRP1_BUFFER_OFFSET_1;          /*!< 0x00000864 Trim value to load into the Buffer Offset 1 register */
  __IOM uint16_t GRP1_BUFFER_OFFSET_2;          /*!< 0x00000866 Trim value to load into the Buffer Offset 2 register */
  __IOM uint16_t GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_EXT; /*!< 0x00000868 0 */
   __IM uint16_t RESERVED11[311];
  __IOM uint16_t SAR_TEMP_COEF_A;               /*!< 0x00000AD8 Trim value to convert counts to degrees C using the formula
                                                                temp = VBE * A - B. VBE is a floating point voltage. */
  __IOM uint16_t SAR_TEMP_COEF_B;               /*!< 0x00000ADA Trim value to convert counts to degrees C using the formula
                                                                temp = VBE * A - B. VBE is a floating point voltage. */
  __IOM uint16_t R2R_DAC_GRP0_OFFSET;           /*!< 0x00000ADC Offset trim value for R2R DAC group 0 */
  __IOM uint16_t R2R_DAC_GRP1_OFFSET;           /*!< 0x00000ADE Offset trim value for R2R DAC group 1 */
   __IM uint32_t RESERVED12[3];
  __IOM uint32_t LDO_0P9V_TRIM;                 /*!< 0x00000AEC LDO trim value for 0.9V. Loaded to the SRSS_PWR_TRIM_PWRSYS_CTL
                                                                register when changing LDO regulator settings. */
  __IOM uint32_t LDO_1P0V_TRIM;                 /*!< 0x00000AF0 LDO trim value for 1.0V. Loaded to the SRSS_PWR_TRIM_PWRSYS_CTL
                                                                register when changing LDO regulator settings. */
  __IOM uint32_t LDO_1P1V_TRIM;                 /*!< 0x00000AF4 LDO trim value for 1.1V. Loaded to the SRSS_PWR_TRIM_PWRSYS_CTL
                                                                register when changing LDO regulator settings. */
  __IOM uint32_t LDO_1P2V_TRIM;                 /*!< 0x00000AF8 LDO trim value for 1.2V. Loaded to the SRSS_PWR_TRIM_PWRSYS_CTL
                                                                register when changing LDO regulator settings. */
  __IOM uint32_t PWR_TRIM_WAKE_CTL;             /*!< 0x00000AFC Wakeup delay values for ULP, LP, MF and OD modes (4 values)
                                                                loaded to the PWR_TRIM_WAKE_CTL register */
   __IM uint32_t RESERVED13[16];
  __IOM uint32_t BASIC_TRIMS_SORT_FLAG;         /*!< 0x00000B40 Signature that indicates that the sort trims are valid =
                                                                0x631A_1FAC */
  __IOM uint32_t BASIC_TRIM_SORT[6];            /*!< 0x00000B44 Copy of the BASIC_TRIM values from EFUSE. Used in SORT and
                                                                PROVISIONED life cycles before BASIC_TRIM values are written to
                                                                the efuses */
   __IM uint32_t RESERVED14[41];
  __IOM uint32_t COUNTER_FLASH_ROW6;            /*!< 0x00000C00 Write counter for working copy of counter page */
  __IOM uint32_t BOOTROW_CRC;                   /*!< 0x00000C04 CRC of the BOOTROW -- See Boot SAS 12.1 'Security Requirements'
                                                                item #5 */
  __IOM uint8_t  IFX_ROT_KEY_REVOCATION;        /*!< 0x00000C08 IFX Root Of Trust Key Revocation to allow for using the second
                                                                key if the first key is revoked due to compromised. The pattern
                                                                of 1-byte state that indicate the key has been revoked can be
                                                                any numbers but not all zeros or all ones */
  __IOM uint8_t  IFX_RMA_MASTER_KEY_REVOCATION; /*!< 0x00000C09 IFX RMA Key Revocation to allow for using the second key if the
                                                                first key is revoked due to compromised. The pattern of 1-byte
                                                                state that indicate the key has been revoked can be any numbers
                                                                but not all zeros or all ones */
  __IOM uint8_t  PROT_FW_ROT_KEY_REVOCATION;    /*!< 0x00000C0A Protected FW Root Of Trust Key Revocation to allow for using
                                                                the second key if the first key is revoked due to compromised.
                                                                The pattern of 1-byte state that indicate the key has been
                                                                revoked can be any numbers but not all zeros or all ones */
  __IOM uint8_t  OEM_ROT_KEY_REVOCATION;        /*!< 0x00000C0B OEM Root Of Trust Key Revocation to allow for using the second
                                                                key if the first key is revoked due to compromised. The pattern
                                                                of 1-byte state that indicate the key has been revoked can be
                                                                any numbers but not all zeros or all ones */
  __IOM uint8_t  NV_COUNTER_RAMAPP;             /*!< 0x00000C0C 8-bit ANTI_ROLLBACK_COUNTER for RAM Apps */
  __IOM uint8_t  NV_COUNTER_A1;                 /*!< 0x00000C0D 8-bit ANTI_ROLLBACK_COUNTER is used to prevent rollback of
                                                                first image - OEM_S or PROT_FW */
  __IOM uint8_t  NV_COUNTER_A2;                 /*!< 0x00000C0E 8-bit ANTI_ROLLBACK_COUNTER is used to prevent rollback of
                                                                second image */
  __IOM uint8_t  NV_COUNTER_A3;                 /*!< 0x00000C0F 8-bit ANTI_ROLLBACK_COUNTER is used to prevent rollback of
                                                                third image */
  __IOM uint8_t  NV_COUNTER_A4;                 /*!< 0x00000C10 8-bit ANTI_ROLLBACK_COUNTER is used to prevent rollback of
                                                                fourth image */
  __IOM uint8_t  RMA_ATTEMPT_COUNTER;           /*!< 0x00000C11 8-bit COUNTER Limits unsuccessful RMA attempts */
   __IM uint16_t RESERVED15;
  __IOM uint32_t PROV_OEM_COMPLETE;             /*!< 0x00000C14 OEM assets are finalized in SFLASH, no further update is
                                                                allowed vs. further updates are allowed */
  __IOM uint8_t  HASH_SLOT_1[32];               /*!< 0x00000C18 Truncated SHA-512 hash of L1 image. Updated after signature
                                                                check succeeds. */
  __IOM uint8_t  HASH_SLOT_2[32];               /*!< 0x00000C38 Truncated SHA-512 hash of L2 image. Updated after signature
                                                                check succeeds. */
  __IOM uint8_t  HASH_SLOT_3[32];               /*!< 0x00000C58 Truncated SHA-512 hash of third FW image. Updated after
                                                                signature check succeeds. */
  __IOM uint8_t  HASH_SLOT_4[32];               /*!< 0x00000C78 Truncated SHA-512 hash of fourth FW image. Updated after
                                                                signature check succeeds. */
  __IOM uint32_t SECURE_HASH_LIST[31];          /*!< 0x00000C98 Secure hash list - Count of active entries followed by
                                                                address/length pairs */
  __IOM uint32_t PROT_FW_HASH_LIST[31];         /*!< 0x00000D14 Protected FW hash list - Count of active entries followed by
                                                                address / length pairs */
  __IOM uint16_t FAILED_SIGNATURE_COUNTER[6];   /*!< 0x00000D90 6 failed signature counters - 0 = RAM Apps, 1 = loaded image 1,
                                                                etc. */
  __IOM uint8_t  SECURE_HASH[32];               /*!< 0x00000D9C Truncated hash of assets in the SECURE_HASH_LIST */
  __IOM uint8_t  PROT_FW_HASH[32];              /*!< 0x00000DBC Truncated hash of assets in the PROT_FW_HASH_LIST */
   __IM uint32_t RESERVED16[9];
  __IOM uint32_t COUNTER_FLASH_ROW7;            /*!< 0x00000E00 Tear safe counter for this flash row */
  __IOM uint32_t ACCESS_RESTRICT;               /*!< 0x00000E04 A debug policy, bits are the same as CPUSS.AP_CTL register When
                                                                PROT_FW is enabled, Secure debug cannot be updated by OEM
                                                                policy. PROT_FW is responsible for disabling the debug ports on
                                                                the PPCA */
  __IOM uint32_t ACCESS_RESTRICT_2;             /*!< 0x00000E08 Additional debug policies.  See _Regs tab for details */
  __IOM uint32_t LISTEN_WINDOW;                 /*!< 0x00000E0C 0xC39D_5401 - 0xC39D_547F : Listen window 1ms - 127ms
                                                                0x151D_D9BB (SEC_FALSE) : 0 ms listen window, the feature is
                                                                disabled. Other - invalid data. Listen window is disabled. */
  __IOM uint32_t BOOT_CFG_ID;                   /*!< 0x00000E10 0x9ADC8D08 (SIMPLE_APP) 0x4FBEEF63 (SECURE_APP) 0xECDB4B1F (
                                                                EPB ) 0x39B92974 (DUAL_BANK_SIMPLE_APP) 0x77D56A80
                                                                (DUAL_BANK_SECURE_APP) 0x4A656DBD (PROT_FW) 0xA155E76E
                                                                (BOOT_IDLE), no app is expected. An internal state for a
                                                                validation of MPC policy. Other - Boot policy is invalid. */
  __IOM uint32_t BOOT_BANK_CTR_OFFSET;          /*!< 0x00000E14 An offset from a start of a Flash bank (for flash dual-bank
                                                                mode) to a 32-bit counter that indicates the valid bank. Each
                                                                flash bank must contain this counter. This counter is updated by
                                                                DFU. Flash bank is selected to be the lower address range (a
                                                                start of flash address) if: * It has a valid counter. * Its
                                                                counter value is bigger than for the other flash-bank, if both
                                                                counters are valid. For each dual-bank counter, bits [31:16]
                                                                should be a fixed value (0x5A3C), otherwise counter is invalid. */
  __IOM uint32_t BOOT_HASH_LOCKING;             /*!< 0x00000E18 0xC39D_5455 - Enable hash locking 0x151D_D9BB - Disable hash
                                                                locking . */
  __IOM uint32_t BOOT_AUTH;                     /*!< 0x00000E1C What will be authenticated, or moved from a Shared Secondary
                                                                Slot after a DFU update. 0x16FF363E (BOOT_AUTH_ALL_MOVE) -
                                                                Authenticate all images, move from a shared secondary slot on a
                                                                successful DFU update. 0xEAE22644 (BOOT_AUTH_ALL) - Authenticate
                                                                all images. 0xFE2D5368 (BOOT_AUTH_ONE) - Authenticate the first
                                                                image, ignore the other images. 0x71EC07DB (BOOT_AUTH_NONE) -
                                                                Disable all authentications for LCS=NORMAL_P when ASSET_HASH is
                                                                not computed. In other cases an invalid combination. Other -
                                                                invalid. */
  __IOM uint32_t BOOT_APP_LAYOUT[10];           /*!< 0x00000E20 A layout of the applications in FLASH. Consists of (addr,
                                                                size)*5 which may define a layout up to four applications +
                                                                Shared Secondary Slot. */
  __IOM uint8_t  BOOT_OD_CLK;                   /*!< 0x00000E48 0 - 50MHz@1.2V 0x55 - 100MHz@1.2V 0xaa - 180MHz@1.2V */
  __IOM uint8_t  PC_CTL_VALID;                  /*!< 0x00000E49 4-bit Bitfield - Bits 0-1 are unused, Bits 2-3 control PC2-3
                                                                handlers 1 = PCx can only be entered via PCx interrupt handler
                                                                (Sets CM33_PC_CTL.VALID[bit x] = 1) 0 = PCx is not 'special'. PC
                                                                may be switched to this value without CM33_PCx_HANDLER interrupt
                                                                vector When Protected FW is active, bit 2 cannot be set from OEM
                                                                policy */
  __IOM uint8_t  OEM_DEVICE_CERT_BLOCKS;        /*!< 0x00000E4A Number of 2K blocks to protect at PC0 for OEM_DEVICE_CERT */
   __IM uint8_t  RESERVED17;
  __IOM uint32_t PC2_HANDLER;                   /*!< 0x00000E4C PC2_HANDLER is used to switch to PC2 when it is a 'Special' PC */
  __IOM uint32_t PC3_HANDLER;                   /*!< 0x00000E50 PC3_HANDLER is used to switch to PC3 when it is a 'Special' PC */
  __IOM uint32_t DFU_POLICY;                    /*!< 0x00000E54 DFU policy: 0xC39D_5455 (SEC_TRUE) - DFU is enabled.
                                                                0x151D_D9BB (SEC_FALSE) - DFU is disabled Other - Invalid
                                                                values. DFU is disabled. */
  __IOM uint32_t OEM_DEVICE_CERT_ADDR;          /*!< 0x00000E58 Pointer to OEM device certificate in user flash -- Protected
                                                                for PC=0 access only */
  __IOM uint32_t BOUNDARY_SCAN_EN;              /*!< 0x00000E5C Boundary Scan policy: -	0x151DD9BB (default), Boundary scan is
                                                                disabled. -	0xC39D5455, Boundary scan is enabled. */
  __IOM uint32_t OEM_POLICY_RESERVED[2];        /*!< 0x00000E60 Reserved for OEM_POLICY expansion */
  __IOM uint8_t  OEM_ROT_KEY_0[136];            /*!< 0x00000E68 Primary OEM_ROT_KEY */
  __IOM uint8_t  OEM_ROT_KEY_1[136];            /*!< 0x00000EF0 Secondary OEM_ROT_KEY */
  __IOM uint32_t DISABLE_RAM_APP;               /*!< 0x00000F78 Disables execution of RAM_APPs 0xC39D_5455 (SEC_TRUE) - RAM_APP
                                                                execution is disabled. 0x151D_D9BB (SEC_FALSE) - RAM_APP
                                                                execution is enabled Other - Invalid values. */
   __IM uint32_t RESERVED18[33];
  __IOM uint32_t COUNTER_FLASH_ROW8;            /*!< 0x00001000 Tear safe counter for this flash row */
  __IOM uint8_t  UNUSED_2;                      /*!< 0x00001004 Unused */
  __IOM uint8_t  N_FLASH_MPC;                   /*!< 0x00001005 Number of flash MPC structs in the following table */
   __IM uint16_t RESERVED19;
  __IOM uint32_t MPC_STRUCT[20];                /*!< 0x00001008 RAM MPC structs followed by Flash MPC structs */
  __IOM uint8_t  PROT_FW_ROT_KEY_0[136];        /*!< 0x00001058 Public key which authenticates this application. May be revoked
                                                                by PROT_FW_ROT_KEY_REVOCATION (which belongs to IFX policy) */
  __IOM uint8_t  PROT_FW_ROT_KEY_1[136];        /*!< 0x000010E0 Public key which authenticates this application. Used if first
                                                                key has been revoked. */
  __IOM uint32_t PROT_FW_ADDR;                  /*!< 0x00001168 Start address of protected FW - Used to set MPC policy */
  __IOM uint32_t PROT_FW_SIZE;                  /*!< 0x0000116C Size of protected FW */
  __IOM uint32_t PROT_FW_RW_ADDR;               /*!< 0x00001170 Start of protected FW RW area in flash - Used to set MPC policy */
  __IOM uint32_t PROT_FW_RW_SIZE;               /*!< 0x00001174 Size of protected FW RW area in flash */
  __IOM uint32_t PROT_FW_RAM_ADDR;              /*!< 0x00001178 Start of protected FW RAM - Used to set MPC policy */
  __IOM uint32_t PROT_FW_RAM_SIZE;              /*!< 0x0000117C Size of protected FW RAM */
  __IOM uint32_t PROT_FW_COMPLETE;              /*!< 0x00001180 0xC39D_5455 (SEC_TRUE), the assets are finalized in SFLASH, no
                                                                further update is allowed. 0x151D_D9BB (SEC_FALSE),
                                                                cyapp_prot_fw_policy may be called multiple times to rewrite the
                                                                PROT_FW assets in SFLASH. Other, the same as SEC_TRUE. */
   __IM uint32_t RESERVED20[31];
  __IOM uint32_t COUNTER_FLASH_ROW9;            /*!< 0x00001200 Tear safe counter for this flash row */
  __IOM uint8_t  OEM_DEBUG_KEY[136];            /*!< 0x00001204 Debugging key */
  __IOM uint8_t  OEM_ROT_KEY_DEV[136];          /*!< 0x0000128C Development OEM_ROT_KEY */
  __IOM uint8_t  PROT_FW_DEBUG_KEY[136];        /*!< 0x00001314 Debugging key for Protected FW */
  __IOM uint8_t  IFX_REVOCATION_KEY[136];       /*!< 0x0000139C IFX revocation key */
  __IOM uint8_t  IFX_ROT_KEY_0[136];            /*!< 0x00001424 Infineon Root of Trust Key 0 */
  __IOM uint8_t  IFX_ROT_KEY_1[136];            /*!< 0x000014AC Infineon Root of Trust Key 1 */
  __IOM uint8_t  IFX_RMA_MASTER_KEY_0[136];     /*!< 0x00001534 Infineon RMA Key 0 */
  __IOM uint8_t  IFX_RMA_MASTER_KEY_1[136];     /*!< 0x000015BC Infineon RMA Key 1 */
  __IOM uint32_t TOC1[16];                      /*!< 0x00001644 TOC1 - See SAS for definition */
  __IOM uint32_t TOC2[8];                       /*!< 0x00001684 TOC2 - See SAS for definition */
  __IOM uint32_t ASSET_HASH_LIST[31];           /*!< 0x000016A4 See SAS table 3.22 AND 5.1.5 */
  __IOM uint32_t FACTORY_HASH_LIST[45];         /*!< 0x00001720 See SAS table 3.22 AND 5.1.5 */
   __IM uint32_t RESERVED21[779];
  __IOM uint32_t FLASH_BOOT_OBJECT_SIZE;        /*!< 0x00002400 Flash Boot - Object Size */
  __IOM uint32_t FLASH_BOOT_VERSION_HIGH;       /*!< 0x00002404 Flash Boot - Major Version */
  __IOM uint32_t FLASH_BOOT_VERSION_LOW;        /*!< 0x00002408 Flash Boot - Minor version */
  __IOM uint32_t FB_STACK_ADDR;                 /*!< 0x0000240C Flash Boot - Stack Addr */
  __IOM uint32_t FB_RESET_HANDLER_ADDR;         /*!< 0x00002410 Flash Boot - Reset vector */
  __IOM uint32_t FB_FUNC_LIST[8];               /*!< 0x00002414 Flash Boot - Function pointer table */
  __IOM uint8_t  FLASH_BOOT_CODE[19916];        /*!< 0x00002434 Flash Boot - Code and Data */
  __IOM uint8_t  ALIAS_PRIVATE_KEY[206];        /*!< 0x00007200 Alias private key */
   __IM uint16_t RESERVED22;
  __IOM uint8_t  ALIAS_PUBLIC_KEY[140];         /*!< 0x000072D0 Alias public key */
   __IM uint32_t RESERVED23[169];
  __IOM uint32_t COUNTER_FLASH_HUK;             /*!< 0x00007600 Write counter for HUK flash row + tag indicating HUK flash row */
  __IOM uint8_t  HUK[32];                       /*!< 0x00007604 Hardware Unique Key */
   __IM uint32_t RESERVED24[72];
  __IOM uint8_t  DICE_PUBLIC_KEY[140];          /*!< 0x00007744 Dice public key */
} SFLASH_Type;                                  /*!< Size = 30672 (0x77D0) */


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
/* SFLASH.SVGS_CMP_CFG */
#define SFLASH_SVGS_CMP_CFG_UVC_EN_Pos          0UL
#define SFLASH_SVGS_CMP_CFG_UVC_EN_Msk          0x1UL
#define SFLASH_SVGS_CMP_CFG_OVC_EN_Pos          1UL
#define SFLASH_SVGS_CMP_CFG_OVC_EN_Msk          0x2UL
#define SFLASH_SVGS_CMP_CFG_UVFC_EN_Pos         2UL
#define SFLASH_SVGS_CMP_CFG_UVFC_EN_Msk         0x4UL
#define SFLASH_SVGS_CMP_CFG_NVC_EN_Pos          3UL
#define SFLASH_SVGS_CMP_CFG_NVC_EN_Msk          0x8UL
#define SFLASH_SVGS_CMP_CFG_UVC_PWR_Pos         8UL
#define SFLASH_SVGS_CMP_CFG_UVC_PWR_Msk         0x100UL
#define SFLASH_SVGS_CMP_CFG_OVC_PWR_Pos         9UL
#define SFLASH_SVGS_CMP_CFG_OVC_PWR_Msk         0x200UL
#define SFLASH_SVGS_CMP_CFG_UVFC_PWR_Pos        10UL
#define SFLASH_SVGS_CMP_CFG_UVFC_PWR_Msk        0x400UL
#define SFLASH_SVGS_CMP_CFG_NVC_PWR_Pos         11UL
#define SFLASH_SVGS_CMP_CFG_NVC_PWR_Msk         0x800UL
#define SFLASH_SVGS_CMP_CFG_UVC_MASK_Pos        16UL
#define SFLASH_SVGS_CMP_CFG_UVC_MASK_Msk        0x10000UL
#define SFLASH_SVGS_CMP_CFG_OVC_MASK_Pos        17UL
#define SFLASH_SVGS_CMP_CFG_OVC_MASK_Msk        0x20000UL
#define SFLASH_SVGS_CMP_CFG_UVFC_MASK_Pos       18UL
#define SFLASH_SVGS_CMP_CFG_UVFC_MASK_Msk       0x40000UL
#define SFLASH_SVGS_CMP_CFG_NVC_MASK_Pos        19UL
#define SFLASH_SVGS_CMP_CFG_NVC_MASK_Msk        0x80000UL
#define SFLASH_SVGS_CMP_CFG_HVC_MASK_Pos        20UL
#define SFLASH_SVGS_CMP_CFG_HVC_MASK_Msk        0x100000UL
#define SFLASH_SVGS_CMP_CFG_SVGS_UVFC_TC_Pos    24UL
#define SFLASH_SVGS_CMP_CFG_SVGS_UVFC_TC_Msk    0xF000000UL
/* SFLASH.SVGS_CMP_TRIP */
#define SFLASH_SVGS_CMP_TRIP_SVGS_UVC_TRIP_Pos  0UL
#define SFLASH_SVGS_CMP_TRIP_SVGS_UVC_TRIP_Msk  0x3FUL
#define SFLASH_SVGS_CMP_TRIP_SVGS_OVC_TRIP_Pos  8UL
#define SFLASH_SVGS_CMP_TRIP_SVGS_OVC_TRIP_Msk  0x300UL
#define SFLASH_SVGS_CMP_TRIP_SVGS_UVFC_TRIP_Pos 16UL
#define SFLASH_SVGS_CMP_TRIP_SVGS_UVFC_TRIP_Msk 0x3F0000UL
#define SFLASH_SVGS_CMP_TRIP_SVGS_NVC_TRIP_Pos  24UL
#define SFLASH_SVGS_CMP_TRIP_SVGS_NVC_TRIP_Msk  0xF000000UL
/* SFLASH.SVGS_TRIM */
#define SFLASH_SVGS_TRIM_SVGS_VREG_TRIM_Pos     0UL
#define SFLASH_SVGS_TRIM_SVGS_VREG_TRIM_Msk     0xFUL
#define SFLASH_SVGS_TRIM_SVGS_IBIAS_TRIM_Pos    8UL
#define SFLASH_SVGS_TRIM_SVGS_IBIAS_TRIM_Msk    0xF00UL
/* SFLASH.SAR_INFRA_TRIM_TABLE */
#define SFLASH_SAR_INFRA_TRIM_TABLE_DATA32_Pos  0UL
#define SFLASH_SAR_INFRA_TRIM_TABLE_DATA32_Msk  0xFFFFFFFFUL
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
#define SFLASH_CSP_PANEL_ID_CSP_X_Pos           0UL
#define SFLASH_CSP_PANEL_ID_CSP_X_Msk           0xFFUL
#define SFLASH_CSP_PANEL_ID_CSP_Y_Pos           8UL
#define SFLASH_CSP_PANEL_ID_CSP_Y_Msk           0xFF00UL
#define SFLASH_CSP_PANEL_ID_CSP_LOT_Pos         16UL
#define SFLASH_CSP_PANEL_ID_CSP_LOT_Msk         0xFF0000UL
#define SFLASH_CSP_PANEL_ID_PAD_Pos             24UL
#define SFLASH_CSP_PANEL_ID_PAD_Msk             0xFF000000UL
/* SFLASH.GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM */
#define SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_TIMCAL_ON_Pos 0UL
#define SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_TIMCAL_ON_Msk 0x1UL
#define SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_OFFCAL_ON_Pos 1UL
#define SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_OFFCAL_ON_Msk 0x2UL
#define SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_GAICAL_ON_Pos 2UL
#define SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_GAICAL_ON_Msk 0x4UL
#define SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_VTOICAL_TRIM_Pos 24UL
#define SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_VTOICAL_TRIM_Msk 0x1F000000UL
/* SFLASH.GRP0_ADC_CALOFFSET */
#define SFLASH_GRP0_ADC_CALOFFSET_OFFSET_SE_Pos 0UL
#define SFLASH_GRP0_ADC_CALOFFSET_OFFSET_SE_Msk 0xFFUL
#define SFLASH_GRP0_ADC_CALOFFSET_OFFSET_DIFF_Pos 16UL
#define SFLASH_GRP0_ADC_CALOFFSET_OFFSET_DIFF_Msk 0xFF0000UL
/* SFLASH.GRP0_ADC_CALGAIN_GAINX1 */
#define SFLASH_GRP0_ADC_CALGAIN_GAINX1_GAINX1_SE_MODE_Pos 0UL
#define SFLASH_GRP0_ADC_CALGAIN_GAINX1_GAINX1_SE_MODE_Msk 0x7FFUL
#define SFLASH_GRP0_ADC_CALGAIN_GAINX1_GAINX1_DIFF_MODE_Pos 16UL
#define SFLASH_GRP0_ADC_CALGAIN_GAINX1_GAINX1_DIFF_MODE_Msk 0x7FF0000UL
/* SFLASH.GRP0_AFE_CALGAIN_AFE_1 */
#define SFLASH_GRP0_AFE_CALGAIN_AFE_1_HFLG2_3_Pos 0UL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_1_HFLG2_3_Msk 0x7FFUL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_1_HFLG2_6_Pos 16UL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_1_HFLG2_6_Msk 0x7FF0000UL
/* SFLASH.GRP0_AFE_CALGAIN_AFE_2 */
#define SFLASH_GRP0_AFE_CALGAIN_AFE_2_HFLG3_3_Pos 0UL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_2_HFLG3_3_Msk 0x7FFUL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_2_HFLG3_6_Pos 16UL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_2_HFLG3_6_Msk 0x7FF0000UL
/* SFLASH.GRP0_AFE_CALGAIN_AFE_3 */
#define SFLASH_GRP0_AFE_CALGAIN_AFE_3_LFHG1_12_Pos 0UL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_3_LFHG1_12_Msk 0x7FFUL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_3_LFHG1_24_Pos 16UL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_3_LFHG1_24_Msk 0x7FF0000UL
/* SFLASH.GRP0_AFE_CALGAIN_AFE_4 */
#define SFLASH_GRP0_AFE_CALGAIN_AFE_4_HFLG1_3_Pos 0UL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_4_HFLG1_3_Msk 0x7FFUL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_4_HFLG1_6_Pos 16UL
#define SFLASH_GRP0_AFE_CALGAIN_AFE_4_HFLG1_6_Msk 0x7FF0000UL
/* SFLASH.GRP0_AFE_CALOFFSET_AFE_1 */
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_1_HFLG2_3_OS_Pos 0UL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_1_HFLG2_3_OS_Msk 0xFFUL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_1_HFLG2_6_OS_Pos 16UL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_1_HFLG2_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP0_AFE_CALOFFSET_AFE_2 */
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_2_HFLG3_3_OS_Pos 0UL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_2_HFLG3_3_OS_Msk 0xFFUL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_2_HFLG3_6_OS_Pos 16UL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_2_HFLG3_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP0_AFE_CALOFFSET_AFE_3 */
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_3_LFHG1_12_OS_Pos 0UL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_3_LFHG1_12_OS_Msk 0xFFUL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_3_LFHG1_24_OS_Pos 16UL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_3_LFHG1_24_OS_Msk 0xFF0000UL
/* SFLASH.GRP0_AFE_CALOFFSET_AFE_4 */
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_4_HFLG1_3_OS_Pos 0UL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_4_HFLG1_3_OS_Msk 0xFFUL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_4_HFLG1_6_OS_Pos 16UL
#define SFLASH_GRP0_AFE_CALOFFSET_AFE_4_HFLG1_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM */
#define SFLASH_GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM_TIMCAL_ON_Pos 0UL
#define SFLASH_GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM_TIMCAL_ON_Msk 0x1UL
#define SFLASH_GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM_OFFCAL_ON_Pos 1UL
#define SFLASH_GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM_OFFCAL_ON_Msk 0x2UL
#define SFLASH_GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM_GAICAL_ON_Pos 2UL
#define SFLASH_GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM_GAICAL_ON_Msk 0x4UL
#define SFLASH_GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM_VTOICAL_TRIM_Pos 24UL
#define SFLASH_GRP1_ADC_STARTUPCTRL_VTOICAL_TRIM_VTOICAL_TRIM_Msk 0x1F000000UL
/* SFLASH.GRP1_ADC_CALOFFSET */
#define SFLASH_GRP1_ADC_CALOFFSET_OFFSET_SE_Pos 0UL
#define SFLASH_GRP1_ADC_CALOFFSET_OFFSET_SE_Msk 0xFFUL
#define SFLASH_GRP1_ADC_CALOFFSET_OFFSET_DIFF_Pos 16UL
#define SFLASH_GRP1_ADC_CALOFFSET_OFFSET_DIFF_Msk 0xFF0000UL
/* SFLASH.GRP1_ADC_CALGAIN_GAINX1 */
#define SFLASH_GRP1_ADC_CALGAIN_GAINX1_GAINX1_SE_MODE_Pos 0UL
#define SFLASH_GRP1_ADC_CALGAIN_GAINX1_GAINX1_SE_MODE_Msk 0x7FFUL
#define SFLASH_GRP1_ADC_CALGAIN_GAINX1_GAINX1_DIFF_MODE_Pos 16UL
#define SFLASH_GRP1_ADC_CALGAIN_GAINX1_GAINX1_DIFF_MODE_Msk 0x7FF0000UL
/* SFLASH.GRP1_AFE_CALGAIN_AFE_1 */
#define SFLASH_GRP1_AFE_CALGAIN_AFE_1_HFLG2_3_Pos 0UL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_1_HFLG2_3_Msk 0x7FFUL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_1_HFLG2_6_Pos 16UL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_1_HFLG2_6_Msk 0x7FF0000UL
/* SFLASH.GRP1_AFE_CALGAIN_AFE_2 */
#define SFLASH_GRP1_AFE_CALGAIN_AFE_2_HFLG3_3_Pos 0UL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_2_HFLG3_3_Msk 0x7FFUL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_2_HFLG3_6_Pos 16UL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_2_HFLG3_6_Msk 0x7FF0000UL
/* SFLASH.GRP1_AFE_CALGAIN_AFE_3 */
#define SFLASH_GRP1_AFE_CALGAIN_AFE_3_LFHG1_12_Pos 0UL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_3_LFHG1_12_Msk 0x7FFUL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_3_LFHG1_24_Pos 16UL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_3_LFHG1_24_Msk 0x7FF0000UL
/* SFLASH.GRP1_AFE_CALGAIN_AFE_4 */
#define SFLASH_GRP1_AFE_CALGAIN_AFE_4_HFLG1_3_Pos 0UL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_4_HFLG1_3_Msk 0x7FFUL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_4_HFLG1_6_Pos 16UL
#define SFLASH_GRP1_AFE_CALGAIN_AFE_4_HFLG1_6_Msk 0x7FF0000UL
/* SFLASH.GRP1_AFE_CALOFFSET_AFE_1 */
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_1_HFLG2_3_OS_Pos 0UL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_1_HFLG2_3_OS_Msk 0xFFUL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_1_HFLG2_6_OS_Pos 16UL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_1_HFLG2_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP1_AFE_CALOFFSET_AFE_2 */
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_2_HFLG3_3_OS_Pos 0UL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_2_HFLG3_3_OS_Msk 0xFFUL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_2_HFLG3_6_OS_Pos 16UL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_2_HFLG3_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP1_AFE_CALOFFSET_AFE_3 */
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_3_LFHG1_12_OS_Pos 0UL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_3_LFHG1_12_OS_Msk 0xFFUL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_3_LFHG1_24_OS_Pos 16UL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_3_LFHG1_24_OS_Msk 0xFF0000UL
/* SFLASH.GRP1_AFE_CALOFFSET_AFE_4 */
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_4_HFLG1_3_OS_Pos 0UL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_4_HFLG1_3_OS_Msk 0xFFUL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_4_HFLG1_6_OS_Pos 16UL
#define SFLASH_GRP1_AFE_CALOFFSET_AFE_4_HFLG1_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM */
#define SFLASH_GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM_TIMCAL_ON_Pos 0UL
#define SFLASH_GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM_TIMCAL_ON_Msk 0x1UL
#define SFLASH_GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM_OFFCAL_ON_Pos 1UL
#define SFLASH_GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM_OFFCAL_ON_Msk 0x2UL
#define SFLASH_GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM_GAICAL_ON_Pos 2UL
#define SFLASH_GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM_GAICAL_ON_Msk 0x4UL
#define SFLASH_GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM_VTOICAL_TRIM_Pos 24UL
#define SFLASH_GRP2_ADC_STARTUPCTRL_VTOICAL_TRIM_VTOICAL_TRIM_Msk 0x1F000000UL
/* SFLASH.GRP2_ADC_CALOFFSET */
#define SFLASH_GRP2_ADC_CALOFFSET_OFFSET_SE_Pos 0UL
#define SFLASH_GRP2_ADC_CALOFFSET_OFFSET_SE_Msk 0xFFUL
#define SFLASH_GRP2_ADC_CALOFFSET_OFFSET_DIFF_Pos 16UL
#define SFLASH_GRP2_ADC_CALOFFSET_OFFSET_DIFF_Msk 0xFF0000UL
/* SFLASH.GRP2_ADC_CALGAIN_GAINX1 */
#define SFLASH_GRP2_ADC_CALGAIN_GAINX1_GAINX1_SE_MODE_Pos 0UL
#define SFLASH_GRP2_ADC_CALGAIN_GAINX1_GAINX1_SE_MODE_Msk 0x7FFUL
#define SFLASH_GRP2_ADC_CALGAIN_GAINX1_GAINX1_DIFF_MODE_Pos 16UL
#define SFLASH_GRP2_ADC_CALGAIN_GAINX1_GAINX1_DIFF_MODE_Msk 0x7FF0000UL
/* SFLASH.GRP2_AFE_CALGAIN_AFE_1 */
#define SFLASH_GRP2_AFE_CALGAIN_AFE_1_HFLG2_3_Pos 0UL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_1_HFLG2_3_Msk 0x7FFUL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_1_HFLG2_6_Pos 16UL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_1_HFLG2_6_Msk 0x7FF0000UL
/* SFLASH.GRP2_AFE_CALGAIN_AFE_2 */
#define SFLASH_GRP2_AFE_CALGAIN_AFE_2_HFLG3_3_Pos 0UL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_2_HFLG3_3_Msk 0x7FFUL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_2_HFLG3_6_Pos 16UL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_2_HFLG3_6_Msk 0x7FF0000UL
/* SFLASH.GRP2_AFE_CALGAIN_AFE_3 */
#define SFLASH_GRP2_AFE_CALGAIN_AFE_3_LFHG1_12_Pos 0UL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_3_LFHG1_12_Msk 0x7FFUL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_3_LFHG1_24_Pos 16UL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_3_LFHG1_24_Msk 0x7FF0000UL
/* SFLASH.GRP2_AFE_CALGAIN_AFE_4 */
#define SFLASH_GRP2_AFE_CALGAIN_AFE_4_HFLG1_3_Pos 0UL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_4_HFLG1_3_Msk 0x7FFUL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_4_HFLG1_6_Pos 16UL
#define SFLASH_GRP2_AFE_CALGAIN_AFE_4_HFLG1_6_Msk 0x7FF0000UL
/* SFLASH.GRP2_AFE_CALOFFSET_AFE_1 */
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_1_HFLG2_3_OS_Pos 0UL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_1_HFLG2_3_OS_Msk 0xFFUL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_1_HFLG2_6_OS_Pos 16UL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_1_HFLG2_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP2_AFE_CALOFFSET_AFE_2 */
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_2_HFLG3_3_OS_Pos 0UL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_2_HFLG3_3_OS_Msk 0xFFUL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_2_HFLG3_6_OS_Pos 16UL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_2_HFLG3_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP2_AFE_CALOFFSET_AFE_3 */
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_3_LFHG1_12_OS_Pos 0UL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_3_LFHG1_12_OS_Msk 0xFFUL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_3_LFHG1_24_OS_Pos 16UL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_3_LFHG1_24_OS_Msk 0xFF0000UL
/* SFLASH.GRP2_AFE_CALOFFSET_AFE_4 */
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_4_HFLG1_3_OS_Pos 0UL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_4_HFLG1_3_OS_Msk 0xFFUL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_4_HFLG1_6_OS_Pos 16UL
#define SFLASH_GRP2_AFE_CALOFFSET_AFE_4_HFLG1_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM */
#define SFLASH_GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM_TIMCAL_ON_Pos 0UL
#define SFLASH_GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM_TIMCAL_ON_Msk 0x1UL
#define SFLASH_GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM_OFFCAL_ON_Pos 1UL
#define SFLASH_GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM_OFFCAL_ON_Msk 0x2UL
#define SFLASH_GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM_GAICAL_ON_Pos 2UL
#define SFLASH_GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM_GAICAL_ON_Msk 0x4UL
#define SFLASH_GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM_VTOICAL_TRIM_Pos 24UL
#define SFLASH_GRP3_ADC_STARTUPCTRL_VTOICAL_TRIM_VTOICAL_TRIM_Msk 0x1F000000UL
/* SFLASH.GRP3_ADC_CALOFFSET */
#define SFLASH_GRP3_ADC_CALOFFSET_OFFSET_SE_Pos 0UL
#define SFLASH_GRP3_ADC_CALOFFSET_OFFSET_SE_Msk 0xFFUL
#define SFLASH_GRP3_ADC_CALOFFSET_OFFSET_DIFF_Pos 16UL
#define SFLASH_GRP3_ADC_CALOFFSET_OFFSET_DIFF_Msk 0xFF0000UL
/* SFLASH.GRP3_ADC_CALGAIN_GAINX1 */
#define SFLASH_GRP3_ADC_CALGAIN_GAINX1_GAINX1_SE_MODE_Pos 0UL
#define SFLASH_GRP3_ADC_CALGAIN_GAINX1_GAINX1_SE_MODE_Msk 0x7FFUL
#define SFLASH_GRP3_ADC_CALGAIN_GAINX1_GAINX1_DIFF_MODE_Pos 16UL
#define SFLASH_GRP3_ADC_CALGAIN_GAINX1_GAINX1_DIFF_MODE_Msk 0x7FF0000UL
/* SFLASH.GRP3_AFE_CALGAIN_AFE_1 */
#define SFLASH_GRP3_AFE_CALGAIN_AFE_1_HFLG2_3_Pos 0UL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_1_HFLG2_3_Msk 0x7FFUL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_1_HFLG2_6_Pos 16UL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_1_HFLG2_6_Msk 0x7FF0000UL
/* SFLASH.GRP3_AFE_CALGAIN_AFE_2 */
#define SFLASH_GRP3_AFE_CALGAIN_AFE_2_HFLG3_3_Pos 0UL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_2_HFLG3_3_Msk 0x7FFUL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_2_HFLG3_6_Pos 16UL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_2_HFLG3_6_Msk 0x7FF0000UL
/* SFLASH.GRP3_AFE_CALGAIN_AFE_3 */
#define SFLASH_GRP3_AFE_CALGAIN_AFE_3_LFHG1_12_Pos 0UL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_3_LFHG1_12_Msk 0x7FFUL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_3_LFHG1_24_Pos 16UL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_3_LFHG1_24_Msk 0x7FF0000UL
/* SFLASH.GRP3_AFE_CALGAIN_AFE_4 */
#define SFLASH_GRP3_AFE_CALGAIN_AFE_4_HFLG1_3_Pos 0UL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_4_HFLG1_3_Msk 0x7FFUL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_4_HFLG1_6_Pos 16UL
#define SFLASH_GRP3_AFE_CALGAIN_AFE_4_HFLG1_6_Msk 0x7FF0000UL
/* SFLASH.GRP3_AFE_CALOFFSET_AFE_1 */
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_1_HFLG2_3_OS_Pos 0UL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_1_HFLG2_3_OS_Msk 0xFFUL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_1_HFLG2_6_OS_Pos 16UL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_1_HFLG2_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP3_AFE_CALOFFSET_AFE_2 */
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_2_HFLG3_3_OS_Pos 0UL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_2_HFLG3_3_OS_Msk 0xFFUL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_2_HFLG3_6_OS_Pos 16UL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_2_HFLG3_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP3_AFE_CALOFFSET_AFE_3 */
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_3_LFHG1_12_OS_Pos 0UL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_3_LFHG1_12_OS_Msk 0xFFUL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_3_LFHG1_24_OS_Pos 16UL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_3_LFHG1_24_OS_Msk 0xFF0000UL
/* SFLASH.GRP3_AFE_CALOFFSET_AFE_4 */
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_4_HFLG1_3_OS_Pos 0UL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_4_HFLG1_3_OS_Msk 0xFFUL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_4_HFLG1_6_OS_Pos 16UL
#define SFLASH_GRP3_AFE_CALOFFSET_AFE_4_HFLG1_6_OS_Msk 0xFF0000UL
/* SFLASH.GRP0_DCSG_TEST_VREF_TRIM */
#define SFLASH_GRP0_DCSG_TEST_VREF_TRIM_VREF_TRIM_Pos 0UL
#define SFLASH_GRP0_DCSG_TEST_VREF_TRIM_VREF_TRIM_Msk 0x3FUL
/* SFLASH.GRP0_DCSG_DIFF_CALOFFSET */
#define SFLASH_GRP0_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_ER_Pos 0UL
#define SFLASH_GRP0_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_ER_Msk 0x3FFUL
#define SFLASH_GRP0_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_FR_Pos 10UL
#define SFLASH_GRP0_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_FR_Msk 0xFFC00UL
#define SFLASH_GRP0_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_RR_Pos 20UL
#define SFLASH_GRP0_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_RR_Msk 0x3FF00000UL
/* SFLASH.GRP0_DCSG_SE_CALOFFSET */
#define SFLASH_GRP0_DCSG_SE_CALOFFSET_OFFSET_SE_SP_Pos 0UL
#define SFLASH_GRP0_DCSG_SE_CALOFFSET_OFFSET_SE_SP_Msk 0x3FFUL
#define SFLASH_GRP0_DCSG_SE_CALOFFSET_OFFSET_SE_SN_Pos 10UL
#define SFLASH_GRP0_DCSG_SE_CALOFFSET_OFFSET_SE_SN_Msk 0xFFC00UL
#define SFLASH_GRP0_DCSG_SE_CALOFFSET_OFFSET_A_VS_B_Pos 20UL
#define SFLASH_GRP0_DCSG_SE_CALOFFSET_OFFSET_A_VS_B_Msk 0x3FF00000UL
/* SFLASH.GRP0_DCSG_DIFF_CALGAIN_1 */
#define SFLASH_GRP0_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_ER_Pos 0UL
#define SFLASH_GRP0_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_ER_Msk 0x7FFUL
#define SFLASH_GRP0_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_FR_Pos 16UL
#define SFLASH_GRP0_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_FR_Msk 0x7FF0000UL
/* SFLASH.GRP0_DCSG_DIFF_CALGAIN_2 */
#define SFLASH_GRP0_DCSG_DIFF_CALGAIN_2_GAIN_DIFF_RR_Pos 0UL
#define SFLASH_GRP0_DCSG_DIFF_CALGAIN_2_GAIN_DIFF_RR_Msk 0x7FFUL
/* SFLASH.GRP0_DCSG_SE_CALGAIN */
#define SFLASH_GRP0_DCSG_SE_CALGAIN_GAIN_SE_SP_Pos 0UL
#define SFLASH_GRP0_DCSG_SE_CALGAIN_GAIN_SE_SP_Msk 0x7FFUL
#define SFLASH_GRP0_DCSG_SE_CALGAIN_GAIN_SE_SN_Pos 16UL
#define SFLASH_GRP0_DCSG_SE_CALGAIN_GAIN_SE_SN_Msk 0x7FF0000UL
/* SFLASH.GRP0_DAC_OFFSET_CNFG1 */
#define SFLASH_GRP0_DAC_OFFSET_CNFG1_DAC_OFFSET_CNFG1_Pos 0UL
#define SFLASH_GRP0_DAC_OFFSET_CNFG1_DAC_OFFSET_CNFG1_Msk 0x3FFUL
/* SFLASH.GRP0_DAC_OFFSET_CNFG2 */
#define SFLASH_GRP0_DAC_OFFSET_CNFG2_DAC_OFFSET_CNFG2_Pos 0UL
#define SFLASH_GRP0_DAC_OFFSET_CNFG2_DAC_OFFSET_CNFG2_Msk 0x3FFUL
/* SFLASH.GRP0_DAC_OFFSET_CNFG3 */
#define SFLASH_GRP0_DAC_OFFSET_CNFG3_DAC_OFFSET_CNFG3_Pos 0UL
#define SFLASH_GRP0_DAC_OFFSET_CNFG3_DAC_OFFSET_CNFG3_Msk 0x3FFUL
/* SFLASH.GRP0_DAC_OFFSET_CNFG4 */
#define SFLASH_GRP0_DAC_OFFSET_CNFG4_DAC_OFFSET_CNFG4_Pos 0UL
#define SFLASH_GRP0_DAC_OFFSET_CNFG4_DAC_OFFSET_CNFG4_Msk 0x3FFUL
/* SFLASH.GRP0_DAC_OFFSET_CNFG5 */
#define SFLASH_GRP0_DAC_OFFSET_CNFG5_DAC_OFFSET_CNFG5_Pos 0UL
#define SFLASH_GRP0_DAC_OFFSET_CNFG5_DAC_OFFSET_CNFG5_Msk 0x3FFUL
/* SFLASH.GRP0_DAC_GAIN_CNFG1 */
#define SFLASH_GRP0_DAC_GAIN_CNFG1_DAC_GAIN_CNFG1_Pos 0UL
#define SFLASH_GRP0_DAC_GAIN_CNFG1_DAC_GAIN_CNFG1_Msk 0x7FFUL
/* SFLASH.GRP0_DAC_GAIN_CNFG2 */
#define SFLASH_GRP0_DAC_GAIN_CNFG2_DAC_GAIN_CNFG2_Pos 0UL
#define SFLASH_GRP0_DAC_GAIN_CNFG2_DAC_GAIN_CNFG2_Msk 0x7FFUL
/* SFLASH.GRP0_DAC_GAIN_CNFG3 */
#define SFLASH_GRP0_DAC_GAIN_CNFG3_DAC_GAIN_CNFG3_Pos 0UL
#define SFLASH_GRP0_DAC_GAIN_CNFG3_DAC_GAIN_CNFG3_Msk 0x7FFUL
/* SFLASH.GRP0_DAC_GAIN_CNFG4 */
#define SFLASH_GRP0_DAC_GAIN_CNFG4_DAC_GAIN_CNFG4_Pos 0UL
#define SFLASH_GRP0_DAC_GAIN_CNFG4_DAC_GAIN_CNFG4_Msk 0x7FFUL
/* SFLASH.GRP0_DAC_GAIN_CNFG5 */
#define SFLASH_GRP0_DAC_GAIN_CNFG5_DAC_GAIN_CNFG5_Pos 0UL
#define SFLASH_GRP0_DAC_GAIN_CNFG5_DAC_GAIN_CNFG5_Msk 0x7FFUL
/* SFLASH.GRP0_BUFFER_OFFSET_1 */
#define SFLASH_GRP0_BUFFER_OFFSET_1_BUFFER_OFFSET_1_Pos 0UL
#define SFLASH_GRP0_BUFFER_OFFSET_1_BUFFER_OFFSET_1_Msk 0x3FFUL
/* SFLASH.GRP0_BUFFER_OFFSET_2 */
#define SFLASH_GRP0_BUFFER_OFFSET_2_BUFFER_OFFSET_2_Pos 0UL
#define SFLASH_GRP0_BUFFER_OFFSET_2_BUFFER_OFFSET_2_Msk 0x3FFUL
/* SFLASH.GRP1_DCSG_TEST_VREF_TRIM */
#define SFLASH_GRP1_DCSG_TEST_VREF_TRIM_VREF_TRIM_Pos 0UL
#define SFLASH_GRP1_DCSG_TEST_VREF_TRIM_VREF_TRIM_Msk 0x3FUL
/* SFLASH.GRP1_DCSG_DIFF_CALOFFSET */
#define SFLASH_GRP1_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_ER_Pos 0UL
#define SFLASH_GRP1_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_ER_Msk 0x3FFUL
#define SFLASH_GRP1_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_FR_Pos 10UL
#define SFLASH_GRP1_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_FR_Msk 0xFFC00UL
#define SFLASH_GRP1_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_RR_Pos 20UL
#define SFLASH_GRP1_DCSG_DIFF_CALOFFSET_OFFSET_DIFF_RR_Msk 0x3FF00000UL
/* SFLASH.GRP1_DCSG_SE_CALOFFSET */
#define SFLASH_GRP1_DCSG_SE_CALOFFSET_OFFSET_SE_SP_Pos 0UL
#define SFLASH_GRP1_DCSG_SE_CALOFFSET_OFFSET_SE_SP_Msk 0x3FFUL
#define SFLASH_GRP1_DCSG_SE_CALOFFSET_OFFSET_SE_SN_Pos 10UL
#define SFLASH_GRP1_DCSG_SE_CALOFFSET_OFFSET_SE_SN_Msk 0xFFC00UL
#define SFLASH_GRP1_DCSG_SE_CALOFFSET_OFFSET_A_VS_B_Pos 20UL
#define SFLASH_GRP1_DCSG_SE_CALOFFSET_OFFSET_A_VS_B_Msk 0x3FF00000UL
/* SFLASH.GRP1_DCSG_DIFF_CALGAIN_1 */
#define SFLASH_GRP1_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_ER_Pos 0UL
#define SFLASH_GRP1_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_ER_Msk 0x7FFUL
#define SFLASH_GRP1_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_FR_Pos 16UL
#define SFLASH_GRP1_DCSG_DIFF_CALGAIN_1_GAIN_DIFF_FR_Msk 0x7FF0000UL
/* SFLASH.GRP1_DCSG_DIFF_CALGAIN_2 */
#define SFLASH_GRP1_DCSG_DIFF_CALGAIN_2_GAIN_DIFF_RR_Pos 0UL
#define SFLASH_GRP1_DCSG_DIFF_CALGAIN_2_GAIN_DIFF_RR_Msk 0x7FFUL
/* SFLASH.GRP1_DCSG_SE_CALGAIN */
#define SFLASH_GRP1_DCSG_SE_CALGAIN_GAIN_SE_SP_Pos 0UL
#define SFLASH_GRP1_DCSG_SE_CALGAIN_GAIN_SE_SP_Msk 0x7FFUL
#define SFLASH_GRP1_DCSG_SE_CALGAIN_GAIN_SE_SN_Pos 16UL
#define SFLASH_GRP1_DCSG_SE_CALGAIN_GAIN_SE_SN_Msk 0x7FF0000UL
/* SFLASH.GRP1_DAC_OFFSET_CNFG1 */
#define SFLASH_GRP1_DAC_OFFSET_CNFG1_DAC_OFFSET_CNFG1_Pos 0UL
#define SFLASH_GRP1_DAC_OFFSET_CNFG1_DAC_OFFSET_CNFG1_Msk 0x3FFUL
/* SFLASH.GRP1_DAC_OFFSET_CNFG2 */
#define SFLASH_GRP1_DAC_OFFSET_CNFG2_DAC_OFFSET_CNFG2_Pos 0UL
#define SFLASH_GRP1_DAC_OFFSET_CNFG2_DAC_OFFSET_CNFG2_Msk 0x3FFUL
/* SFLASH.GRP1_DAC_OFFSET_CNFG3 */
#define SFLASH_GRP1_DAC_OFFSET_CNFG3_DAC_OFFSET_CNFG3_Pos 0UL
#define SFLASH_GRP1_DAC_OFFSET_CNFG3_DAC_OFFSET_CNFG3_Msk 0x3FFUL
/* SFLASH.GRP1_DAC_OFFSET_CNFG4 */
#define SFLASH_GRP1_DAC_OFFSET_CNFG4_DAC_OFFSET_CNFG4_Pos 0UL
#define SFLASH_GRP1_DAC_OFFSET_CNFG4_DAC_OFFSET_CNFG4_Msk 0x3FFUL
/* SFLASH.GRP1_DAC_OFFSET_CNFG5 */
#define SFLASH_GRP1_DAC_OFFSET_CNFG5_DAC_OFFSET_CNFG5_Pos 0UL
#define SFLASH_GRP1_DAC_OFFSET_CNFG5_DAC_OFFSET_CNFG5_Msk 0x3FFUL
/* SFLASH.GRP1_DAC_GAIN_CNFG1 */
#define SFLASH_GRP1_DAC_GAIN_CNFG1_DAC_GAIN_CNFG1_Pos 0UL
#define SFLASH_GRP1_DAC_GAIN_CNFG1_DAC_GAIN_CNFG1_Msk 0x7FFUL
/* SFLASH.GRP1_DAC_GAIN_CNFG2 */
#define SFLASH_GRP1_DAC_GAIN_CNFG2_DAC_GAIN_CNFG2_Pos 0UL
#define SFLASH_GRP1_DAC_GAIN_CNFG2_DAC_GAIN_CNFG2_Msk 0x7FFUL
/* SFLASH.GRP1_DAC_GAIN_CNFG3 */
#define SFLASH_GRP1_DAC_GAIN_CNFG3_DAC_GAIN_CNFG3_Pos 0UL
#define SFLASH_GRP1_DAC_GAIN_CNFG3_DAC_GAIN_CNFG3_Msk 0x7FFUL
/* SFLASH.GRP1_DAC_GAIN_CNFG4 */
#define SFLASH_GRP1_DAC_GAIN_CNFG4_DAC_GAIN_CNFG4_Pos 0UL
#define SFLASH_GRP1_DAC_GAIN_CNFG4_DAC_GAIN_CNFG4_Msk 0x7FFUL
/* SFLASH.GRP1_DAC_GAIN_CNFG5 */
#define SFLASH_GRP1_DAC_GAIN_CNFG5_DAC_GAIN_CNFG5_Pos 0UL
#define SFLASH_GRP1_DAC_GAIN_CNFG5_DAC_GAIN_CNFG5_Msk 0x7FFUL
/* SFLASH.GRP1_BUFFER_OFFSET_1 */
#define SFLASH_GRP1_BUFFER_OFFSET_1_BUFFER_OFFSET_1_Pos 0UL
#define SFLASH_GRP1_BUFFER_OFFSET_1_BUFFER_OFFSET_1_Msk 0x3FFUL
/* SFLASH.GRP1_BUFFER_OFFSET_2 */
#define SFLASH_GRP1_BUFFER_OFFSET_2_BUFFER_OFFSET_2_Pos 0UL
#define SFLASH_GRP1_BUFFER_OFFSET_2_BUFFER_OFFSET_2_Msk 0x3FFUL
/* SFLASH.GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_EXT */
#define SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_EXT_DATA32_Pos 0UL
#define SFLASH_GRP0_ADC_STARTUPCTRL_VTOICAL_TRIM_EXT_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.SAR_TEMP_COEF_A */
#define SFLASH_SAR_TEMP_COEF_A_DATA16_Pos       0UL
#define SFLASH_SAR_TEMP_COEF_A_DATA16_Msk       0xFFFFUL
/* SFLASH.SAR_TEMP_COEF_B */
#define SFLASH_SAR_TEMP_COEF_B_DATA16_Pos       0UL
#define SFLASH_SAR_TEMP_COEF_B_DATA16_Msk       0xFFFFUL
/* SFLASH.R2R_DAC_GRP0_OFFSET */
#define SFLASH_R2R_DAC_GRP0_OFFSET_DATA16_Pos   0UL
#define SFLASH_R2R_DAC_GRP0_OFFSET_DATA16_Msk   0xFFFFUL
/* SFLASH.R2R_DAC_GRP1_OFFSET */
#define SFLASH_R2R_DAC_GRP1_OFFSET_DATA16_Pos   0UL
#define SFLASH_R2R_DAC_GRP1_OFFSET_DATA16_Msk   0xFFFFUL
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
/* SFLASH.BASIC_TRIMS_SORT_FLAG */
#define SFLASH_BASIC_TRIMS_SORT_FLAG_DATA32_Pos 0UL
#define SFLASH_BASIC_TRIMS_SORT_FLAG_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.BASIC_TRIM_SORT */
#define SFLASH_BASIC_TRIM_SORT_DATA32_Pos       0UL
#define SFLASH_BASIC_TRIM_SORT_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.COUNTER_FLASH_ROW6 */
#define SFLASH_COUNTER_FLASH_ROW6_DATA32_Pos    0UL
#define SFLASH_COUNTER_FLASH_ROW6_DATA32_Msk    0xFFFFFFFFUL
/* SFLASH.BOOTROW_CRC */
#define SFLASH_BOOTROW_CRC_DATA32_Pos           0UL
#define SFLASH_BOOTROW_CRC_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.IFX_ROT_KEY_REVOCATION */
#define SFLASH_IFX_ROT_KEY_REVOCATION_DATA32_Pos 0UL
#define SFLASH_IFX_ROT_KEY_REVOCATION_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.IFX_RMA_MASTER_KEY_REVOCATION */
#define SFLASH_IFX_RMA_MASTER_KEY_REVOCATION_DATA8_Pos 0UL
#define SFLASH_IFX_RMA_MASTER_KEY_REVOCATION_DATA8_Msk 0xFFUL
/* SFLASH.PROT_FW_ROT_KEY_REVOCATION */
#define SFLASH_PROT_FW_ROT_KEY_REVOCATION_DATA32_Pos 0UL
#define SFLASH_PROT_FW_ROT_KEY_REVOCATION_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.OEM_ROT_KEY_REVOCATION */
#define SFLASH_OEM_ROT_KEY_REVOCATION_DATA8_Pos 0UL
#define SFLASH_OEM_ROT_KEY_REVOCATION_DATA8_Msk 0xFFUL
/* SFLASH.NV_COUNTER_RAMAPP */
#define SFLASH_NV_COUNTER_RAMAPP_DATA8_Pos      0UL
#define SFLASH_NV_COUNTER_RAMAPP_DATA8_Msk      0xFFUL
/* SFLASH.NV_COUNTER_A1 */
#define SFLASH_NV_COUNTER_A1_DATA8_Pos          0UL
#define SFLASH_NV_COUNTER_A1_DATA8_Msk          0xFFUL
/* SFLASH.NV_COUNTER_A2 */
#define SFLASH_NV_COUNTER_A2_DATA8_Pos          0UL
#define SFLASH_NV_COUNTER_A2_DATA8_Msk          0xFFUL
/* SFLASH.NV_COUNTER_A3 */
#define SFLASH_NV_COUNTER_A3_DATA32_Pos         0UL
#define SFLASH_NV_COUNTER_A3_DATA32_Msk         0xFFFFFFFFUL
/* SFLASH.NV_COUNTER_A4 */
#define SFLASH_NV_COUNTER_A4_DATA32_Pos         0UL
#define SFLASH_NV_COUNTER_A4_DATA32_Msk         0xFFFFFFFFUL
/* SFLASH.RMA_ATTEMPT_COUNTER */
#define SFLASH_RMA_ATTEMPT_COUNTER_DATA32_Pos   0UL
#define SFLASH_RMA_ATTEMPT_COUNTER_DATA32_Msk   0xFFFFFFFFUL
/* SFLASH.PROV_OEM_COMPLETE */
#define SFLASH_PROV_OEM_COMPLETE_DATA32_Pos     0UL
#define SFLASH_PROV_OEM_COMPLETE_DATA32_Msk     0xFFFFFFFFUL
/* SFLASH.HASH_SLOT_1 */
#define SFLASH_HASH_SLOT_1_DATA8_Pos            0UL
#define SFLASH_HASH_SLOT_1_DATA8_Msk            0xFFUL
/* SFLASH.HASH_SLOT_2 */
#define SFLASH_HASH_SLOT_2_DATA8_Pos            0UL
#define SFLASH_HASH_SLOT_2_DATA8_Msk            0xFFUL
/* SFLASH.HASH_SLOT_3 */
#define SFLASH_HASH_SLOT_3_DATA8_Pos            0UL
#define SFLASH_HASH_SLOT_3_DATA8_Msk            0xFFUL
/* SFLASH.HASH_SLOT_4 */
#define SFLASH_HASH_SLOT_4_DATA8_Pos            0UL
#define SFLASH_HASH_SLOT_4_DATA8_Msk            0xFFUL
/* SFLASH.SECURE_HASH_LIST */
#define SFLASH_SECURE_HASH_LIST_DATA8_Pos       0UL
#define SFLASH_SECURE_HASH_LIST_DATA8_Msk       0xFFUL
/* SFLASH.PROT_FW_HASH_LIST */
#define SFLASH_PROT_FW_HASH_LIST_DATA8_Pos      0UL
#define SFLASH_PROT_FW_HASH_LIST_DATA8_Msk      0xFFUL
/* SFLASH.FAILED_SIGNATURE_COUNTER */
#define SFLASH_FAILED_SIGNATURE_COUNTER_DATA8_Pos 0UL
#define SFLASH_FAILED_SIGNATURE_COUNTER_DATA8_Msk 0xFFUL
/* SFLASH.SECURE_HASH */
#define SFLASH_SECURE_HASH_DATA8_Pos            0UL
#define SFLASH_SECURE_HASH_DATA8_Msk            0xFFUL
/* SFLASH.PROT_FW_HASH */
#define SFLASH_PROT_FW_HASH_DATA8_Pos           0UL
#define SFLASH_PROT_FW_HASH_DATA8_Msk           0xFFUL
/* SFLASH.COUNTER_FLASH_ROW7 */
#define SFLASH_COUNTER_FLASH_ROW7_DATA32_Pos    0UL
#define SFLASH_COUNTER_FLASH_ROW7_DATA32_Msk    0xFFFFFFFFUL
/* SFLASH.ACCESS_RESTRICT */
#define SFLASH_ACCESS_RESTRICT_DATA32_Pos       0UL
#define SFLASH_ACCESS_RESTRICT_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.ACCESS_RESTRICT_2 */
#define SFLASH_ACCESS_RESTRICT_2_SYS_AP_MMIO_Pos 0UL
#define SFLASH_ACCESS_RESTRICT_2_SYS_AP_MMIO_Msk 0x3UL
#define SFLASH_ACCESS_RESTRICT_2_DEBUG_PINS_Pos 4UL
#define SFLASH_ACCESS_RESTRICT_2_DEBUG_PINS_Msk 0xF0UL
#define SFLASH_ACCESS_RESTRICT_2_CM33_DEBUG_ALLOWED_Pos 8UL
#define SFLASH_ACCESS_RESTRICT_2_CM33_DEBUG_ALLOWED_Msk 0x300UL
#define SFLASH_ACCESS_RESTRICT_2_SYS_DEBUG_ALLOWED_Pos 10UL
#define SFLASH_ACCESS_RESTRICT_2_SYS_DEBUG_ALLOWED_Msk 0xC00UL
#define SFLASH_ACCESS_RESTRICT_2_DEBUG_TAG_Pos  24UL
#define SFLASH_ACCESS_RESTRICT_2_DEBUG_TAG_Msk  0xFF000000UL
/* SFLASH.LISTEN_WINDOW */
#define SFLASH_LISTEN_WINDOW_DATA32_Pos         0UL
#define SFLASH_LISTEN_WINDOW_DATA32_Msk         0xFFFFFFFFUL
/* SFLASH.BOOT_CFG_ID */
#define SFLASH_BOOT_CFG_ID_DATA32_Pos           0UL
#define SFLASH_BOOT_CFG_ID_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.BOOT_BANK_CTR_OFFSET */
#define SFLASH_BOOT_BANK_CTR_OFFSET_DATA8_Pos   0UL
#define SFLASH_BOOT_BANK_CTR_OFFSET_DATA8_Msk   0xFFUL
/* SFLASH.BOOT_HASH_LOCKING */
#define SFLASH_BOOT_HASH_LOCKING_DATA8_Pos      0UL
#define SFLASH_BOOT_HASH_LOCKING_DATA8_Msk      0xFFUL
/* SFLASH.BOOT_AUTH */
#define SFLASH_BOOT_AUTH_DATA8_Pos              0UL
#define SFLASH_BOOT_AUTH_DATA8_Msk              0xFFUL
/* SFLASH.BOOT_APP_LAYOUT */
#define SFLASH_BOOT_APP_LAYOUT_DATA32_Pos       0UL
#define SFLASH_BOOT_APP_LAYOUT_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.BOOT_OD_CLK */
#define SFLASH_BOOT_OD_CLK_DATA32_Pos           0UL
#define SFLASH_BOOT_OD_CLK_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.PC_CTL_VALID */
#define SFLASH_PC_CTL_VALID_DATA8_Pos           0UL
#define SFLASH_PC_CTL_VALID_DATA8_Msk           0xFFUL
/* SFLASH.OEM_DEVICE_CERT_BLOCKS */
#define SFLASH_OEM_DEVICE_CERT_BLOCKS_DATA8_Pos 0UL
#define SFLASH_OEM_DEVICE_CERT_BLOCKS_DATA8_Msk 0xFFUL
/* SFLASH.PC2_HANDLER */
#define SFLASH_PC2_HANDLER_DATA32_Pos           0UL
#define SFLASH_PC2_HANDLER_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.PC3_HANDLER */
#define SFLASH_PC3_HANDLER_DATA32_Pos           0UL
#define SFLASH_PC3_HANDLER_DATA32_Msk           0xFFFFFFFFUL
/* SFLASH.DFU_POLICY */
#define SFLASH_DFU_POLICY_DATA32_Pos            0UL
#define SFLASH_DFU_POLICY_DATA32_Msk            0xFFFFFFFFUL
/* SFLASH.OEM_DEVICE_CERT_ADDR */
#define SFLASH_OEM_DEVICE_CERT_ADDR_DATA32_Pos  0UL
#define SFLASH_OEM_DEVICE_CERT_ADDR_DATA32_Msk  0xFFFFFFFFUL
/* SFLASH.BOUNDARY_SCAN_EN */
#define SFLASH_BOUNDARY_SCAN_EN_DATA32_Pos      0UL
#define SFLASH_BOUNDARY_SCAN_EN_DATA32_Msk      0xFFFFFFFFUL
/* SFLASH.OEM_POLICY_RESERVED */
#define SFLASH_OEM_POLICY_RESERVED_DATA32_Pos   0UL
#define SFLASH_OEM_POLICY_RESERVED_DATA32_Msk   0xFFFFFFFFUL
/* SFLASH.OEM_ROT_KEY_0 */
#define SFLASH_OEM_ROT_KEY_0_DATA8_Pos          0UL
#define SFLASH_OEM_ROT_KEY_0_DATA8_Msk          0xFFUL
/* SFLASH.OEM_ROT_KEY_1 */
#define SFLASH_OEM_ROT_KEY_1_DATA8_Pos          0UL
#define SFLASH_OEM_ROT_KEY_1_DATA8_Msk          0xFFUL
/* SFLASH.DISABLE_RAM_APP */
#define SFLASH_DISABLE_RAM_APP_DATA32_Pos       0UL
#define SFLASH_DISABLE_RAM_APP_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.COUNTER_FLASH_ROW8 */
#define SFLASH_COUNTER_FLASH_ROW8_DATA32_Pos    0UL
#define SFLASH_COUNTER_FLASH_ROW8_DATA32_Msk    0xFFFFFFFFUL
/* SFLASH.UNUSED_2 */
#define SFLASH_UNUSED_2_DATA8_Pos               0UL
#define SFLASH_UNUSED_2_DATA8_Msk               0xFFUL
/* SFLASH.N_FLASH_MPC */
#define SFLASH_N_FLASH_MPC_DATA8_Pos            0UL
#define SFLASH_N_FLASH_MPC_DATA8_Msk            0xFFUL
/* SFLASH.MPC_STRUCT */
#define SFLASH_MPC_STRUCT_DATA32_Pos            0UL
#define SFLASH_MPC_STRUCT_DATA32_Msk            0xFFFFFFFFUL
/* SFLASH.PROT_FW_ROT_KEY_0 */
#define SFLASH_PROT_FW_ROT_KEY_0_DATA32_Pos     0UL
#define SFLASH_PROT_FW_ROT_KEY_0_DATA32_Msk     0xFFFFFFFFUL
/* SFLASH.PROT_FW_ROT_KEY_1 */
#define SFLASH_PROT_FW_ROT_KEY_1_DATA32_Pos     0UL
#define SFLASH_PROT_FW_ROT_KEY_1_DATA32_Msk     0xFFFFFFFFUL
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
/* SFLASH.PROT_FW_COMPLETE */
#define SFLASH_PROT_FW_COMPLETE_DATA32_Pos      0UL
#define SFLASH_PROT_FW_COMPLETE_DATA32_Msk      0xFFFFFFFFUL
/* SFLASH.COUNTER_FLASH_ROW9 */
#define SFLASH_COUNTER_FLASH_ROW9_DATA32_Pos    0UL
#define SFLASH_COUNTER_FLASH_ROW9_DATA32_Msk    0xFFFFFFFFUL
/* SFLASH.OEM_DEBUG_KEY */
#define SFLASH_OEM_DEBUG_KEY_DATA32_Pos         0UL
#define SFLASH_OEM_DEBUG_KEY_DATA32_Msk         0xFFFFFFFFUL
/* SFLASH.OEM_ROT_KEY_DEV */
#define SFLASH_OEM_ROT_KEY_DEV_DATA32_Pos       0UL
#define SFLASH_OEM_ROT_KEY_DEV_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.PROT_FW_DEBUG_KEY */
#define SFLASH_PROT_FW_DEBUG_KEY_DATA32_Pos     0UL
#define SFLASH_PROT_FW_DEBUG_KEY_DATA32_Msk     0xFFFFFFFFUL
/* SFLASH.IFX_REVOCATION_KEY */
#define SFLASH_IFX_REVOCATION_KEY_DATA32_Pos    0UL
#define SFLASH_IFX_REVOCATION_KEY_DATA32_Msk    0xFFFFFFFFUL
/* SFLASH.IFX_ROT_KEY_0 */
#define SFLASH_IFX_ROT_KEY_0_DATA8_Pos          0UL
#define SFLASH_IFX_ROT_KEY_0_DATA8_Msk          0xFFUL
/* SFLASH.IFX_ROT_KEY_1 */
#define SFLASH_IFX_ROT_KEY_1_DATA8_Pos          0UL
#define SFLASH_IFX_ROT_KEY_1_DATA8_Msk          0xFFUL
/* SFLASH.IFX_RMA_MASTER_KEY_0 */
#define SFLASH_IFX_RMA_MASTER_KEY_0_DATA8_Pos   0UL
#define SFLASH_IFX_RMA_MASTER_KEY_0_DATA8_Msk   0xFFUL
/* SFLASH.IFX_RMA_MASTER_KEY_1 */
#define SFLASH_IFX_RMA_MASTER_KEY_1_DATA8_Pos   0UL
#define SFLASH_IFX_RMA_MASTER_KEY_1_DATA8_Msk   0xFFUL
/* SFLASH.TOC1 */
#define SFLASH_TOC1_DATA32_Pos                  0UL
#define SFLASH_TOC1_DATA32_Msk                  0xFFFFFFFFUL
/* SFLASH.TOC2 */
#define SFLASH_TOC2_DATA32_Pos                  0UL
#define SFLASH_TOC2_DATA32_Msk                  0xFFFFFFFFUL
/* SFLASH.ASSET_HASH_LIST */
#define SFLASH_ASSET_HASH_LIST_DATA32_Pos       0UL
#define SFLASH_ASSET_HASH_LIST_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.FACTORY_HASH_LIST */
#define SFLASH_FACTORY_HASH_LIST_DATA32_Pos     0UL
#define SFLASH_FACTORY_HASH_LIST_DATA32_Msk     0xFFFFFFFFUL
/* SFLASH.FLASH_BOOT_OBJECT_SIZE */
#define SFLASH_FLASH_BOOT_OBJECT_SIZE_DATA32_Pos 0UL
#define SFLASH_FLASH_BOOT_OBJECT_SIZE_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.FLASH_BOOT_VERSION_HIGH */
#define SFLASH_FLASH_BOOT_VERSION_HIGH_DATA32_Pos 0UL
#define SFLASH_FLASH_BOOT_VERSION_HIGH_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.FLASH_BOOT_VERSION_LOW */
#define SFLASH_FLASH_BOOT_VERSION_LOW_DATA32_Pos 0UL
#define SFLASH_FLASH_BOOT_VERSION_LOW_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.FB_STACK_ADDR */
#define SFLASH_FB_STACK_ADDR_DATA32_Pos         0UL
#define SFLASH_FB_STACK_ADDR_DATA32_Msk         0xFFFFFFFFUL
/* SFLASH.FB_RESET_HANDLER_ADDR */
#define SFLASH_FB_RESET_HANDLER_ADDR_DATA32_Pos 0UL
#define SFLASH_FB_RESET_HANDLER_ADDR_DATA32_Msk 0xFFFFFFFFUL
/* SFLASH.FB_FUNC_LIST */
#define SFLASH_FB_FUNC_LIST_DATA32_Pos          0UL
#define SFLASH_FB_FUNC_LIST_DATA32_Msk          0xFFFFFFFFUL
/* SFLASH.FLASH_BOOT_CODE */
#define SFLASH_FLASH_BOOT_CODE_DATA32_Pos       0UL
#define SFLASH_FLASH_BOOT_CODE_DATA32_Msk       0xFFFFFFFFUL
/* SFLASH.ALIAS_PRIVATE_KEY */
#define SFLASH_ALIAS_PRIVATE_KEY_DATA32_Pos     0UL
#define SFLASH_ALIAS_PRIVATE_KEY_DATA32_Msk     0xFFFFFFFFUL
/* SFLASH.ALIAS_PUBLIC_KEY */
#define SFLASH_ALIAS_PUBLIC_KEY_DATA32_Pos      0UL
#define SFLASH_ALIAS_PUBLIC_KEY_DATA32_Msk      0xFFFFFFFFUL
/* SFLASH.COUNTER_FLASH_HUK */
#define SFLASH_COUNTER_FLASH_HUK_DATA32_Pos     0UL
#define SFLASH_COUNTER_FLASH_HUK_DATA32_Msk     0xFFFFFFFFUL
/* SFLASH.HUK */
#define SFLASH_HUK_DATA32_Pos                   0UL
#define SFLASH_HUK_DATA32_Msk                   0xFFFFFFFFUL
/* SFLASH.DICE_PUBLIC_KEY */
#define SFLASH_DICE_PUBLIC_KEY_DATA32_Pos       0UL
#define SFLASH_DICE_PUBLIC_KEY_DATA32_Msk       0xFFFFFFFFUL


#endif /* _CYIP_SFLASH_PSC3_P8_H_ */


/* [] END OF FILE */
