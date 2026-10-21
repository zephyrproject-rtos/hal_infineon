/***************************************************************************//**
* \file cyip_cm33.h
*
* \brief
* CM33 IP definitions
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

#ifndef _CYIP_CM33_H_
#define _CYIP_CM33_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     CM33
*******************************************************************************/

#define CM33_CTI_SECTION_SIZE                   0x00001000UL
#define CM33_TRC_CTI_SECTION_SIZE               0x00001000UL
#define CM33_TRC_SECTION_SIZE                   0x00001000UL
#define CM33_SECTION_SIZE                       0x20000000UL

/**
  * \brief Cortex-M33 Cross Trigger Interface (CTI) Registers (CM33_CTI)
  */
typedef struct {
  __IOM uint32_t CTICONTROL;                    /*!< 0x00000000 CTI Control Register */
   __IM uint32_t RESERVED[3];
   __OM uint32_t CTIINTACK;                     /*!< 0x00000010 CTI Interrupt Acknowledge Register */
  __IOM uint32_t CTIAPPSET;                     /*!< 0x00000014 CTI Application Trigger Set Register */
  __IOM uint32_t CTIAPPCLEAR;                   /*!< 0x00000018 CTI Application Trigger Clear Register */
   __OM uint32_t CTIAPPPULSE;                   /*!< 0x0000001C CTI Application Pulse Register */
  __IOM uint32_t CTIINEN[8];                    /*!< 0x00000020 CTI Trigger to Channel Enable Registers */
   __IM uint32_t RESERVED1[24];
  __IOM uint32_t CTIOUTEN[8];                   /*!< 0x000000A0 CTI Channel to Trigger Enable Registers */
   __IM uint32_t RESERVED2[28];
   __IM uint32_t CTITRIGINSTATUS;               /*!< 0x00000130 CTI Trigger In Status Register */
   __IM uint32_t CTITRIGOUTSTATUS;              /*!< 0x00000134 CTI Trigger Out Status Register */
   __IM uint32_t CTICHINSTATUS;                 /*!< 0x00000138 CTI Channel In Status Register */
   __IM uint32_t RESERVED3;
  __IOM uint32_t CTIGATE;                       /*!< 0x00000140 Enable CTI Channel Gate Register */
  __IOM uint32_t ASICCTL;                       /*!< 0x00000144 External Multiplexor Control Register */
   __IM uint32_t RESERVED4[871];
   __OM uint32_t ITCHOUT;                       /*!< 0x00000EE4 ITCHOUT Register */
   __OM uint32_t ITTRIGOUT;                     /*!< 0x00000EE8 ITTRIGOUT Register */
   __IM uint32_t RESERVED5[2];
   __IM uint32_t ITCHIN;                        /*!< 0x00000EF4 ITCHIN Register */
   __IM uint32_t RESERVED6[2];
  __IOM uint32_t ITCTRL;                        /*!< 0x00000F00 Integration Mode Control Register */
   __IM uint32_t RESERVED7[46];
   __IM uint32_t DEVARCH;                       /*!< 0x00000FBC Device Architecture register */
   __IM uint32_t RESERVED8[2];
   __IM uint32_t DEVID;                         /*!< 0x00000FC8 Device Configuration Register */
   __IM uint32_t DEVTYPE;                       /*!< 0x00000FCC Device Type Identifier Register */
   __IM uint32_t PIDR4;                         /*!< 0x00000FD0 Peripheral Identification Register 4 */
   __IM uint32_t PIDR5;                         /*!< 0x00000FD4 Peripheral Identification Register 5 */
   __IM uint32_t PIDR6;                         /*!< 0x00000FD8 Peripheral Identification Register 6 */
   __IM uint32_t PIDR7;                         /*!< 0x00000FDC Peripheral Identification Register 7 */
   __IM uint32_t PIDR0;                         /*!< 0x00000FE0 Peripheral Identification Register 0 */
   __IM uint32_t PIDR1;                         /*!< 0x00000FE4 Peripheral Identification Register 1 */
   __IM uint32_t PIDR2;                         /*!< 0x00000FE8 Peripheral Identification Register 2 */
   __IM uint32_t PIDR3;                         /*!< 0x00000FEC Peripheral Identification Register 3 */
   __IM uint32_t CIDR0;                         /*!< 0x00000FF0 Component Identification Register 0 */
   __IM uint32_t CIDR1;                         /*!< 0x00000FF4 Component Identification Register 1 */
   __IM uint32_t CIDR2;                         /*!< 0x00000FF8 Component Identification Register 2 */
   __IM uint32_t CIDR3;                         /*!< 0x00000FFC Component Identification Register 3 */
} CM33_CTI_Type;                                /*!< Size = 4096 (0x1000) */

/**
  * \brief System Trace Cross Trigger Interface (CTI) (CM33_TRC_CTI)
  */
typedef struct {
  __IOM uint32_t CTICONTROL;                    /*!< 0x00000000 CTI Control Register */
   __IM uint32_t RESERVED[3];
   __OM uint32_t CTIINTACK;                     /*!< 0x00000010 CTI Interrupt Acknowledge Register */
  __IOM uint32_t CTIAPPSET;                     /*!< 0x00000014 CTI Application Trigger Set Register */
   __OM uint32_t CTIAPPCLEAR;                   /*!< 0x00000018 CTI Application Trigger Clear Register */
   __OM uint32_t CTIAPPPULSE;                   /*!< 0x0000001C CTI Application Pulse Register */
  __IOM uint32_t CTIINEN[32];                   /*!< 0x00000020 CTI Trigger to Channel Enable Registers */
  __IOM uint32_t CTIOUTEN[32];                  /*!< 0x000000A0 CTI Channel to Trigger Enable Registers */
   __IM uint32_t RESERVED1[4];
   __IM uint32_t CTITRIGINSTATUS;               /*!< 0x00000130 CTI Trigger In Status Register */
   __IM uint32_t CTITRIGOUTSTATUS;              /*!< 0x00000134 CTI Trigger Out Status Register */
   __IM uint32_t CTICHINSTATUS;                 /*!< 0x00000138 CTI Channel In Status Register */
   __IM uint32_t CTICHOUTSTATUS;                /*!< 0x0000013C CTI Channel Out Status Register */
  __IOM uint32_t CTIGATE;                       /*!< 0x00000140 Enable CTI Channel Gate Register */
  __IOM uint32_t ASICCTRL;                      /*!< 0x00000144 External Multiplexor Control Register */
   __IM uint32_t RESERVED2[869];
   __OM uint32_t ITCHINACK;                     /*!< 0x00000EDC ITCHINACK Register */
   __OM uint32_t ITTRIGINACK;                   /*!< 0x00000EE0 ITTRIGINACK Register */
   __OM uint32_t ITCHOUT;                       /*!< 0x00000EE4 ITCHOUT Register */
   __OM uint32_t ITTRIGOUT;                     /*!< 0x00000EE8 ITTRIGOUT Register */
   __IM uint32_t ITCHOUTACK;                    /*!< 0x00000EEC ITCHOUTACK Register */
   __IM uint32_t ITTRIGOUTACK;                  /*!< 0x00000EF0 ITTRIGOUTACK Register */
   __IM uint32_t ITCHIN;                        /*!< 0x00000EF4 ITCHIN Register */
   __IM uint32_t ITTRIGIN;                      /*!< 0x00000EF8 ITTRIGIN Register */
   __IM uint32_t RESERVED3;
  __IOM uint32_t ITCTRL;                        /*!< 0x00000F00 Integration Mode Control Register */
   __IM uint32_t RESERVED4[39];
  __IOM uint32_t CLAIMSET;                      /*!< 0x00000FA0 Claim Tag Set Register */
  __IOM uint32_t CLAIMCLR;                      /*!< 0x00000FA4 Claim Tag Clear Register */
   __IM uint32_t DEVAFF0;                       /*!< 0x00000FA8 Device Affinity Register 0 */
   __IM uint32_t DEVAFF1;                       /*!< 0x00000FAC Device Affinity Register 1 */
  __IOM uint32_t LAR;                           /*!< 0x00000FB0 Lock Access Register */
   __IM uint32_t LSR;                           /*!< 0x00000FB4 Lock Status Register */
   __IM uint32_t AUTHSTATUS;                    /*!< 0x00000FB8 Authentication Status Register */
   __IM uint32_t DEVARCH;                       /*!< 0x00000FBC Device Architecture Register */
   __IM uint32_t RESERVED5[2];
   __IM uint32_t DEVID;                         /*!< 0x00000FC8 Device Configuration Register */
   __IM uint32_t DEVTYPE;                       /*!< 0x00000FCC Device Type Identifier Register */
   __IM uint32_t PIDR4;                         /*!< 0x00000FD0 Peripheral Identification Register 4 */
   __IM uint32_t PIDR5;                         /*!< 0x00000FD4 Peripheral Identification Register 5 */
   __IM uint32_t PIDR6;                         /*!< 0x00000FD8 Peripheral Identification Register 6 */
   __IM uint32_t PIDR7;                         /*!< 0x00000FDC Peripheral Identification Register 7 */
   __IM uint32_t PIDR0;                         /*!< 0x00000FE0 Peripheral Identification Register 0 */
   __IM uint32_t PIDR1;                         /*!< 0x00000FE4 Peripheral Identification Register 1 */
   __IM uint32_t PIDR2;                         /*!< 0x00000FE8 Peripheral Identification Register 2 */
   __IM uint32_t PIDR3;                         /*!< 0x00000FEC Peripheral Identification Register 3 */
   __IM uint32_t CIDR0;                         /*!< 0x00000FF0 Component Identification Register 0 */
   __IM uint32_t CIDR1;                         /*!< 0x00000FF4 Component Identification Register 1 */
   __IM uint32_t CIDR2;                         /*!< 0x00000FF8 Component Identification Register 2 */
   __IM uint32_t CIDR3;                         /*!< 0x00000FFC Component Identification Register 3 */
} CM33_TRC_CTI_Type;                            /*!< Size = 4096 (0x1000) */

/**
  * \brief System Trace Cross Trigger Interface (CTI) (CM33_TRC)
  */
typedef struct {
        CM33_TRC_CTI_Type CTI;                  /*!< 0x00000000 System Trace Cross Trigger Interface (CTI) */
} CM33_TRC_Type;                                /*!< Size = 4096 (0x1000) */

/**
  * \brief Cortex-M33 specific registers (CM33)
  */
typedef struct {
   __IM uint32_t RESERVED[67584];
        CM33_CTI_Type CTI;                      /*!< 0x00042000 Cortex-M33 Cross Trigger Interface (CTI) Registers */
   __IM uint32_t RESERVED1[62464];
        CM33_TRC_Type TRC;                      /*!< 0x00080000 System Trace Cross Trigger Interface (CTI) */
} CM33_Type;                                    /*!< Size = 528384 (0x81000) */


/* CM33_CTI.CTICONTROL */
#define CM33_CTI_CTICONTROL_VALUE_Pos           0UL
#define CM33_CTI_CTICONTROL_VALUE_Msk           0xFFFFFFFFUL
/* CM33_CTI.CTIINTACK */
#define CM33_CTI_CTIINTACK_VALUE_Pos            0UL
#define CM33_CTI_CTIINTACK_VALUE_Msk            0xFFFFFFFFUL
/* CM33_CTI.CTIAPPSET */
#define CM33_CTI_CTIAPPSET_VALUE_Pos            0UL
#define CM33_CTI_CTIAPPSET_VALUE_Msk            0xFFFFFFFFUL
/* CM33_CTI.CTIAPPCLEAR */
#define CM33_CTI_CTIAPPCLEAR_VALUE_Pos          0UL
#define CM33_CTI_CTIAPPCLEAR_VALUE_Msk          0xFFFFFFFFUL
/* CM33_CTI.CTIAPPPULSE */
#define CM33_CTI_CTIAPPPULSE_VALUE_Pos          0UL
#define CM33_CTI_CTIAPPPULSE_VALUE_Msk          0xFFFFFFFFUL
/* CM33_CTI.CTIINEN */
#define CM33_CTI_CTIINEN_VALUE_Pos              0UL
#define CM33_CTI_CTIINEN_VALUE_Msk              0xFFFFFFFFUL
/* CM33_CTI.CTIOUTEN */
#define CM33_CTI_CTIOUTEN_VALUE_Pos             0UL
#define CM33_CTI_CTIOUTEN_VALUE_Msk             0xFFFFFFFFUL
/* CM33_CTI.CTITRIGINSTATUS */
#define CM33_CTI_CTITRIGINSTATUS_VALUE_Pos      0UL
#define CM33_CTI_CTITRIGINSTATUS_VALUE_Msk      0xFFFFFFFFUL
/* CM33_CTI.CTITRIGOUTSTATUS */
#define CM33_CTI_CTITRIGOUTSTATUS_VALUE_Pos     0UL
#define CM33_CTI_CTITRIGOUTSTATUS_VALUE_Msk     0xFFFFFFFFUL
/* CM33_CTI.CTICHINSTATUS */
#define CM33_CTI_CTICHINSTATUS_VALUE_Pos        0UL
#define CM33_CTI_CTICHINSTATUS_VALUE_Msk        0xFFFFFFFFUL
/* CM33_CTI.CTIGATE */
#define CM33_CTI_CTIGATE_VALUE_Pos              0UL
#define CM33_CTI_CTIGATE_VALUE_Msk              0xFFFFFFFFUL
/* CM33_CTI.ASICCTL */
#define CM33_CTI_ASICCTL_VALUE_Pos              0UL
#define CM33_CTI_ASICCTL_VALUE_Msk              0xFFFFFFFFUL
/* CM33_CTI.ITCHOUT */
#define CM33_CTI_ITCHOUT_VALUE_Pos              0UL
#define CM33_CTI_ITCHOUT_VALUE_Msk              0xFFFFFFFFUL
/* CM33_CTI.ITTRIGOUT */
#define CM33_CTI_ITTRIGOUT_VALUE_Pos            0UL
#define CM33_CTI_ITTRIGOUT_VALUE_Msk            0xFFFFFFFFUL
/* CM33_CTI.ITCHIN */
#define CM33_CTI_ITCHIN_VALUE_Pos               0UL
#define CM33_CTI_ITCHIN_VALUE_Msk               0xFFFFFFFFUL
/* CM33_CTI.ITCTRL */
#define CM33_CTI_ITCTRL_VALUE_Pos               0UL
#define CM33_CTI_ITCTRL_VALUE_Msk               0xFFFFFFFFUL
/* CM33_CTI.DEVARCH */
#define CM33_CTI_DEVARCH_VALUE_Pos              0UL
#define CM33_CTI_DEVARCH_VALUE_Msk              0xFFFFFFFFUL
/* CM33_CTI.DEVID */
#define CM33_CTI_DEVID_VALUE_Pos                0UL
#define CM33_CTI_DEVID_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.DEVTYPE */
#define CM33_CTI_DEVTYPE_VALUE_Pos              0UL
#define CM33_CTI_DEVTYPE_VALUE_Msk              0xFFFFFFFFUL
/* CM33_CTI.PIDR4 */
#define CM33_CTI_PIDR4_VALUE_Pos                0UL
#define CM33_CTI_PIDR4_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.PIDR5 */
#define CM33_CTI_PIDR5_VALUE_Pos                0UL
#define CM33_CTI_PIDR5_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.PIDR6 */
#define CM33_CTI_PIDR6_VALUE_Pos                0UL
#define CM33_CTI_PIDR6_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.PIDR7 */
#define CM33_CTI_PIDR7_VALUE_Pos                0UL
#define CM33_CTI_PIDR7_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.PIDR0 */
#define CM33_CTI_PIDR0_VALUE_Pos                0UL
#define CM33_CTI_PIDR0_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.PIDR1 */
#define CM33_CTI_PIDR1_VALUE_Pos                0UL
#define CM33_CTI_PIDR1_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.PIDR2 */
#define CM33_CTI_PIDR2_VALUE_Pos                0UL
#define CM33_CTI_PIDR2_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.PIDR3 */
#define CM33_CTI_PIDR3_VALUE_Pos                0UL
#define CM33_CTI_PIDR3_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.CIDR0 */
#define CM33_CTI_CIDR0_VALUE_Pos                0UL
#define CM33_CTI_CIDR0_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.CIDR1 */
#define CM33_CTI_CIDR1_VALUE_Pos                0UL
#define CM33_CTI_CIDR1_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.CIDR2 */
#define CM33_CTI_CIDR2_VALUE_Pos                0UL
#define CM33_CTI_CIDR2_VALUE_Msk                0xFFFFFFFFUL
/* CM33_CTI.CIDR3 */
#define CM33_CTI_CIDR3_VALUE_Pos                0UL
#define CM33_CTI_CIDR3_VALUE_Msk                0xFFFFFFFFUL


/* CM33_TRC_CTI.CTICONTROL */
#define CM33_TRC_CTI_CTICONTROL_GLBEN_Pos       0UL
#define CM33_TRC_CTI_CTICONTROL_GLBEN_Msk       0x1UL
/* CM33_TRC_CTI.CTIINTACK */
#define CM33_TRC_CTI_CTIINTACK_INTACK_Pos       0UL
#define CM33_TRC_CTI_CTIINTACK_INTACK_Msk       0xFFFFFFFFUL
/* CM33_TRC_CTI.CTIAPPSET */
#define CM33_TRC_CTI_CTIAPPSET_APPSET_Pos       0UL
#define CM33_TRC_CTI_CTIAPPSET_APPSET_Msk       0xFUL
/* CM33_TRC_CTI.CTIAPPCLEAR */
#define CM33_TRC_CTI_CTIAPPCLEAR_APPCLEAR_Pos   0UL
#define CM33_TRC_CTI_CTIAPPCLEAR_APPCLEAR_Msk   0xFUL
/* CM33_TRC_CTI.CTIAPPPULSE */
#define CM33_TRC_CTI_CTIAPPPULSE_APPULSE_Pos    0UL
#define CM33_TRC_CTI_CTIAPPPULSE_APPULSE_Msk    0xFUL
/* CM33_TRC_CTI.CTIINEN */
#define CM33_TRC_CTI_CTIINEN_TRIGINEN_Pos       0UL
#define CM33_TRC_CTI_CTIINEN_TRIGINEN_Msk       0xFUL
/* CM33_TRC_CTI.CTIOUTEN */
#define CM33_TRC_CTI_CTIOUTEN_TRIGOUTEN_Pos     0UL
#define CM33_TRC_CTI_CTIOUTEN_TRIGOUTEN_Msk     0xFUL
/* CM33_TRC_CTI.CTITRIGINSTATUS */
#define CM33_TRC_CTI_CTITRIGINSTATUS_TRIGINSTATUS_Pos 0UL
#define CM33_TRC_CTI_CTITRIGINSTATUS_TRIGINSTATUS_Msk 0xFFFFFFFFUL
/* CM33_TRC_CTI.CTITRIGOUTSTATUS */
#define CM33_TRC_CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_Pos 0UL
#define CM33_TRC_CTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_Msk 0xFFFFFFFFUL
/* CM33_TRC_CTI.CTICHINSTATUS */
#define CM33_TRC_CTI_CTICHINSTATUS_CTICHINSTATUS_Pos 0UL
#define CM33_TRC_CTI_CTICHINSTATUS_CTICHINSTATUS_Msk 0xFUL
/* CM33_TRC_CTI.CTICHOUTSTATUS */
#define CM33_TRC_CTI_CTICHOUTSTATUS_CTICHOUTSTATUS_Pos 0UL
#define CM33_TRC_CTI_CTICHOUTSTATUS_CTICHOUTSTATUS_Msk 0xFUL
/* CM33_TRC_CTI.CTIGATE */
#define CM33_TRC_CTI_CTIGATE_CTIGATEEN0_Pos     0UL
#define CM33_TRC_CTI_CTIGATE_CTIGATEEN0_Msk     0x1UL
#define CM33_TRC_CTI_CTIGATE_CTIGATEEN1_Pos     1UL
#define CM33_TRC_CTI_CTIGATE_CTIGATEEN1_Msk     0x2UL
#define CM33_TRC_CTI_CTIGATE_CTIGATEEN2_Pos     2UL
#define CM33_TRC_CTI_CTIGATE_CTIGATEEN2_Msk     0x4UL
#define CM33_TRC_CTI_CTIGATE_CTIGATEEN3_Pos     3UL
#define CM33_TRC_CTI_CTIGATE_CTIGATEEN3_Msk     0x8UL
/* CM33_TRC_CTI.ASICCTRL */
#define CM33_TRC_CTI_ASICCTRL_ASICCTL_Pos       0UL
#define CM33_TRC_CTI_ASICCTRL_ASICCTL_Msk       0xFFUL
/* CM33_TRC_CTI.ITCHINACK */
#define CM33_TRC_CTI_ITCHINACK_CTCHINACK_Pos    0UL
#define CM33_TRC_CTI_ITCHINACK_CTCHINACK_Msk    0xFUL
/* CM33_TRC_CTI.ITTRIGINACK */
#define CM33_TRC_CTI_ITTRIGINACK_CTTRIGINACK_Pos 0UL
#define CM33_TRC_CTI_ITTRIGINACK_CTTRIGINACK_Msk 0xFFUL
/* CM33_TRC_CTI.ITCHOUT */
#define CM33_TRC_CTI_ITCHOUT_CTCHOUT_Pos        0UL
#define CM33_TRC_CTI_ITCHOUT_CTCHOUT_Msk        0xFUL
/* CM33_TRC_CTI.ITTRIGOUT */
#define CM33_TRC_CTI_ITTRIGOUT_CTTRIGOUT_Pos    0UL
#define CM33_TRC_CTI_ITTRIGOUT_CTTRIGOUT_Msk    0xFFFFFFFFUL
/* CM33_TRC_CTI.ITCHOUTACK */
#define CM33_TRC_CTI_ITCHOUTACK_CTCHOUTACK_Pos  0UL
#define CM33_TRC_CTI_ITCHOUTACK_CTCHOUTACK_Msk  0xFUL
/* CM33_TRC_CTI.ITTRIGOUTACK */
#define CM33_TRC_CTI_ITTRIGOUTACK_CTTRIGOUTACK_Pos 0UL
#define CM33_TRC_CTI_ITTRIGOUTACK_CTTRIGOUTACK_Msk 0xFFUL
/* CM33_TRC_CTI.ITCHIN */
#define CM33_TRC_CTI_ITCHIN_CTCHIN_Pos          0UL
#define CM33_TRC_CTI_ITCHIN_CTCHIN_Msk          0xFUL
/* CM33_TRC_CTI.ITTRIGIN */
#define CM33_TRC_CTI_ITTRIGIN_CTTRIGIN_Pos      0UL
#define CM33_TRC_CTI_ITTRIGIN_CTTRIGIN_Msk      0xFFFFFFFFUL
/* CM33_TRC_CTI.ITCTRL */
#define CM33_TRC_CTI_ITCTRL_MODE_Pos            0UL
#define CM33_TRC_CTI_ITCTRL_MODE_Msk            0x1UL
/* CM33_TRC_CTI.CLAIMSET */
#define CM33_TRC_CTI_CLAIMSET_TAG_Pos           0UL
#define CM33_TRC_CTI_CLAIMSET_TAG_Msk           0xFUL
/* CM33_TRC_CTI.CLAIMCLR */
#define CM33_TRC_CTI_CLAIMCLR_TAG_Pos           0UL
#define CM33_TRC_CTI_CLAIMCLR_TAG_Msk           0xFUL
/* CM33_TRC_CTI.DEVAFF0 */
#define CM33_TRC_CTI_DEVAFF0_DEVAFF0_Pos        0UL
#define CM33_TRC_CTI_DEVAFF0_DEVAFF0_Msk        0xFFFFFFFFUL
/* CM33_TRC_CTI.DEVAFF1 */
#define CM33_TRC_CTI_DEVAFF1_DEVAFF0_Pos        0UL
#define CM33_TRC_CTI_DEVAFF1_DEVAFF0_Msk        0xFFFFFFFFUL
/* CM33_TRC_CTI.LAR */
#define CM33_TRC_CTI_LAR_KEY_Pos                0UL
#define CM33_TRC_CTI_LAR_KEY_Msk                0xFFFFFFFFUL
/* CM33_TRC_CTI.LSR */
#define CM33_TRC_CTI_LSR_SLI_Pos                0UL
#define CM33_TRC_CTI_LSR_SLI_Msk                0x1UL
#define CM33_TRC_CTI_LSR_SLK_Pos                1UL
#define CM33_TRC_CTI_LSR_SLK_Msk                0x2UL
#define CM33_TRC_CTI_LSR_NTT_Pos                2UL
#define CM33_TRC_CTI_LSR_NTT_Msk                0x4UL
/* CM33_TRC_CTI.AUTHSTATUS */
#define CM33_TRC_CTI_AUTHSTATUS_NSIDBG_Pos      0UL
#define CM33_TRC_CTI_AUTHSTATUS_NSIDBG_Msk      0x3UL
#define CM33_TRC_CTI_AUTHSTATUS_NSNIDBG_Pos     2UL
#define CM33_TRC_CTI_AUTHSTATUS_NSNIDBG_Msk     0xCUL
#define CM33_TRC_CTI_AUTHSTATUS_SIDBG_Pos       4UL
#define CM33_TRC_CTI_AUTHSTATUS_SIDBG_Msk       0x30UL
#define CM33_TRC_CTI_AUTHSTATUS_SNIDBG_Pos      6UL
#define CM33_TRC_CTI_AUTHSTATUS_SNIDBG_Msk      0xC0UL
/* CM33_TRC_CTI.DEVARCH */
#define CM33_TRC_CTI_DEVARCH_ARCHID_Pos         0UL
#define CM33_TRC_CTI_DEVARCH_ARCHID_Msk         0xFFFFUL
#define CM33_TRC_CTI_DEVARCH_REVISION_Pos       16UL
#define CM33_TRC_CTI_DEVARCH_REVISION_Msk       0xF0000UL
#define CM33_TRC_CTI_DEVARCH_PRESENT_Pos        20UL
#define CM33_TRC_CTI_DEVARCH_PRESENT_Msk        0x100000UL
#define CM33_TRC_CTI_DEVARCH_ARCHITECT_Pos      21UL
#define CM33_TRC_CTI_DEVARCH_ARCHITECT_Msk      0xFFE00000UL
/* CM33_TRC_CTI.DEVID */
#define CM33_TRC_CTI_DEVID_EXTMUXNUM_Pos        0UL
#define CM33_TRC_CTI_DEVID_EXTMUXNUM_Msk        0x1FUL
#define CM33_TRC_CTI_DEVID_NUMTRIG_Pos          8UL
#define CM33_TRC_CTI_DEVID_NUMTRIG_Msk          0xFF00UL
#define CM33_TRC_CTI_DEVID_NUMCH_Pos            16UL
#define CM33_TRC_CTI_DEVID_NUMCH_Msk            0xF0000UL
/* CM33_TRC_CTI.DEVTYPE */
#define CM33_TRC_CTI_DEVTYPE_CLASS_Pos          0UL
#define CM33_TRC_CTI_DEVTYPE_CLASS_Msk          0xFUL
#define CM33_TRC_CTI_DEVTYPE_SUB_TYPE_Pos       4UL
#define CM33_TRC_CTI_DEVTYPE_SUB_TYPE_Msk       0xF0UL
/* CM33_TRC_CTI.PIDR4 */
#define CM33_TRC_CTI_PIDR4_VALUE_Pos            0UL
#define CM33_TRC_CTI_PIDR4_VALUE_Msk            0xFFFFFFFFUL
/* CM33_TRC_CTI.PIDR5 */
#define CM33_TRC_CTI_PIDR5_VALUE_Pos            0UL
#define CM33_TRC_CTI_PIDR5_VALUE_Msk            0xFFFFFFFFUL
/* CM33_TRC_CTI.PIDR6 */
#define CM33_TRC_CTI_PIDR6_VALUE_Pos            0UL
#define CM33_TRC_CTI_PIDR6_VALUE_Msk            0xFFFFFFFFUL
/* CM33_TRC_CTI.PIDR7 */
#define CM33_TRC_CTI_PIDR7_VALUE_Pos            0UL
#define CM33_TRC_CTI_PIDR7_VALUE_Msk            0xFFFFFFFFUL
/* CM33_TRC_CTI.PIDR0 */
#define CM33_TRC_CTI_PIDR0_VALUE_Pos            0UL
#define CM33_TRC_CTI_PIDR0_VALUE_Msk            0xFFFFFFFFUL
/* CM33_TRC_CTI.PIDR1 */
#define CM33_TRC_CTI_PIDR1_VALUE_Pos            0UL
#define CM33_TRC_CTI_PIDR1_VALUE_Msk            0xFFFFFFFFUL
/* CM33_TRC_CTI.PIDR2 */
#define CM33_TRC_CTI_PIDR2_VALUE_Pos            0UL
#define CM33_TRC_CTI_PIDR2_VALUE_Msk            0xFFFFFFFFUL
/* CM33_TRC_CTI.PIDR3 */
#define CM33_TRC_CTI_PIDR3_ECOREVNUM_Pos        4UL
#define CM33_TRC_CTI_PIDR3_ECOREVNUM_Msk        0xF0UL
/* CM33_TRC_CTI.CIDR0 */
#define CM33_TRC_CTI_CIDR0_VALUE_Pos            0UL
#define CM33_TRC_CTI_CIDR0_VALUE_Msk            0xFFFFFFFFUL
/* CM33_TRC_CTI.CIDR1 */
#define CM33_TRC_CTI_CIDR1_VALUE_Pos            0UL
#define CM33_TRC_CTI_CIDR1_VALUE_Msk            0xFFFFFFFFUL
/* CM33_TRC_CTI.CIDR2 */
#define CM33_TRC_CTI_CIDR2_VALUE_Pos            0UL
#define CM33_TRC_CTI_CIDR2_VALUE_Msk            0xFFFFFFFFUL
/* CM33_TRC_CTI.CIDR3 */
#define CM33_TRC_CTI_CIDR3_VALUE_Pos            0UL
#define CM33_TRC_CTI_CIDR3_VALUE_Msk            0xFFFFFFFFUL


#endif /* _CYIP_CM33_H_ */


/* [] END OF FILE */
