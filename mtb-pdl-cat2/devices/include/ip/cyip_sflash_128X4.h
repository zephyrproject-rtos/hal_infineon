/***************************************************************************//**
* \file cyip_sflash_128X4.h
*
* \brief
* SFLASH IP definitions
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

#ifndef _CYIP_SFLASH_128X4_H_
#define _CYIP_SFLASH_128X4_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    SFLASH
*******************************************************************************/

#define SFLASH_SECTION_SIZE                     0x00000400UL

/**
  * \brief Supervisory Flash Area (Infineon Trim & Wounding Info) (SFLASH)
  */
typedef struct {
  __IOM uint16_t SILICON_ID;                    /*!< 0x00000000 Silicon ID */
   __IM uint16_t RESERVED[8];
  __IOM uint16_t DPSLP_KEY_DELAY;               /*!< 0x00000012 DeepSleep wakeup value for PWR_KEY_DELAY */
  __IOM uint32_t SWD_LISTEN;                    /*!< 0x00000014 Listen Window Length */
  __IOM uint32_t FLASH_START;                   /*!< 0x00000018 Flash Image Start Address */
   __IM uint32_t RESERVED1[9];
  __IOM uint32_t USER_SFLASH_AREA[2];           /*!< 0x00000040 Pointer to between 0 and 2 customer usable SFLASH regions */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t DIE_UNIQUE_ID[6];              /*!< 0x00000050 Uses manufacturing identity to create a unique die ID */
   __IM uint32_t RESERVED3[93];
  __IOM uint8_t  PACSS_CHAN0_OCD_VTH_TRIM[18];  /*!< 0x000001DC Channel 0 OCD threshold voltage trim */
  __IOM uint8_t  PACSS_CHAN1_OCD_VTH_TRIM[18];  /*!< 0x000001EE Channel 1 OCD threshold voltage trim */
  __IOM uint8_t  IMO_TRIM_LT[8];                /*!< 0x00000200 IMO Frequency Trim Register (SRSS-Lite) - From 24 to 48 MHz in
                                                                steps of 4 MHz */
  __IOM uint8_t  IMO_TCTRIM_LT[8];              /*!< 0x00000208 IMO Temperature Compensation Trim - From 24 to 48 MHz in steps
                                                                of 4 MHz */
  __IOM uint8_t  IMO_STEPSIZE_LT[8];            /*!< 0x00000210 IMO Stepsize Trim - From 24 to 48 MHz in steps of 4 MHz */
  __IOM uint8_t  IMO_4PCT_LIM;                  /*!< 0x00000218 IMO trim 4 percent deviation from nominal */
  __IOM uint8_t  IMO_3PCT_LIM;                  /*!< 0x00000219 IMO trim 3 percent deviation from nominal */
  __IOM uint8_t  PILO_6PCT_LIM;                 /*!< 0x0000021A PILO trim 6 percent deviation from nominal */
   __IM uint8_t  RESERVED4[101];
  __IOM uint32_t PACSS_CHAN0_2TEMP_TRIM[20];    /*!< 0x00000280 Channel 0 two temperature trim values for software lookup. */
  __IOM uint32_t PACSS_CHAN1_2TEMP_TRIM[22];    /*!< 0x000002D0 Channel 1 two temperature trim values for software lookup. */
  __IOM uint32_t PACSS_CHAN1_3TEMP_TRIM[12];    /*!< 0x00000328 Channel 1 three temperature trim values for software lookup. */
  __IOM uint8_t  PACSS_CHAN_3TEMP_CENTERTEMP;   /*!< 0x00000358 Defines the center temperature for three temperature trim
                                                                values */
  __IOM uint8_t  PACSS_CHAN_OFFSET_SCLR;        /*!< 0x00000359 Defines the offset scaler for all offset calibration values */
  __IOM uint16_t PACSS_DIAG_RSH_PURES;          /*!< 0x0000035A Measured RSH pull-up resistor value for shunt open testing */
  __IOM uint16_t PACSS_DIAG_RSL_PURES;          /*!< 0x0000035C Measured RSL pull-up resistor value for shunt open testing */
  __IOM uint16_t PACSS_DIAG_RSH2_PURES;         /*!< 0x0000035E Measured RSH2 pull-up resistor value for shunt open testing */
  __IOM uint16_t PACSS_DIAG_RSL2_PURES;         /*!< 0x00000360 Measured RSL2 pull-up resistor value for shunt open testing */
  __IOM uint16_t PACSS_CHAN1_ETEMP_TRIM;        /*!< 0x00000362 Channel 1 gain adjust to be used with external temperature
                                                                measurements, -40C value */
  __IOM uint32_t PACSS_DIAG_TEMP_P_CAL_S;       /*!< 0x00000364 Primary temperature calibration data setup */
  __IOM uint16_t PACSS_DIAG_TEMP_P_CAL_A2;      /*!< 0x00000368 Primary temperature calibration data polynomial a2 */
  __IOM uint16_t PACSS_DIAG_TEMP_P_CAL_A1;      /*!< 0x0000036A Primary temperature calibration data polynomial a1 */
  __IOM uint16_t PACSS_DIAG_TEMP_P_CAL_A0;      /*!< 0x0000036C Primary temperature calibration data polynomial a0 */
  __IOM uint16_t PACSS_CHAN1_ETEMP_TRIM_2;      /*!< 0x0000036E Channel 1 gain adjust to be used with external temperature
                                                                measurements, 150C value */
  __IOM uint32_t PACSS_DIAG_TEMP_A_CAL_S;       /*!< 0x00000370 Alternate temperature calibration data setup */
  __IOM uint16_t PACSS_DIAG_TEMP_A_CAL_A2;      /*!< 0x00000374 Alternate temperature calibration data polynomial a2 */
  __IOM uint16_t PACSS_DIAG_TEMP_A_CAL_A1;      /*!< 0x00000376 Alternate temperature calibration data polynomial a1 */
  __IOM uint16_t PACSS_DIAG_TEMP_A_CAL_A0;      /*!< 0x00000378 Alternate temperature calibration data polynomial a0 */
   __IM uint16_t RESERVED5;
  __IOM uint16_t SAR_TEMP_MULTIPLIER;           /*!< 0x0000037C SAR Temperature Sensor Multiplication Factor */
  __IOM uint16_t SAR_TEMP_OFFSET;               /*!< 0x0000037E SAR Temperature Sensor Offset */
} SFLASH_Type;                                  /*!< Size = 896 (0x380) */


/* SFLASH.SILICON_ID */
#define SFLASH_SILICON_ID_SI_ID_Pos             0UL
#define SFLASH_SILICON_ID_SI_ID_Msk             0xFFFFUL
/* SFLASH.DPSLP_KEY_DELAY */
#define SFLASH_DPSLP_KEY_DELAY_WAKEUP_HOLDOFF_Pos 0UL
#define SFLASH_DPSLP_KEY_DELAY_WAKEUP_HOLDOFF_Msk 0x3FFUL
/* SFLASH.SWD_LISTEN */
#define SFLASH_SWD_LISTEN_CYCLES_Pos            0UL
#define SFLASH_SWD_LISTEN_CYCLES_Msk            0xFFFFFFFFUL
/* SFLASH.FLASH_START */
#define SFLASH_FLASH_START_ADDRESS_Pos          0UL
#define SFLASH_FLASH_START_ADDRESS_Msk          0xFFFFFFFFUL
/* SFLASH.USER_SFLASH_AREA */
#define SFLASH_USER_SFLASH_AREA_LOCATION_Pos    0UL
#define SFLASH_USER_SFLASH_AREA_LOCATION_Msk    0xFFFFUL
#define SFLASH_USER_SFLASH_AREA_SIZE_Pos        16UL
#define SFLASH_USER_SFLASH_AREA_SIZE_Msk        0xFFFF0000UL
/* SFLASH.DIE_UNIQUE_ID */
#define SFLASH_DIE_UNIQUE_ID_ID_Pos             0UL
#define SFLASH_DIE_UNIQUE_ID_ID_Msk             0xFFFFFFFFUL
/* SFLASH.PACSS_CHAN0_OCD_VTH_TRIM */
#define SFLASH_PACSS_CHAN0_OCD_VTH_TRIM_OCD0_VTH_TRIM_Pos 0UL
#define SFLASH_PACSS_CHAN0_OCD_VTH_TRIM_OCD0_VTH_TRIM_Msk 0xFFUL
/* SFLASH.PACSS_CHAN1_OCD_VTH_TRIM */
#define SFLASH_PACSS_CHAN1_OCD_VTH_TRIM_OCD1_VTH_TRIM_Pos 0UL
#define SFLASH_PACSS_CHAN1_OCD_VTH_TRIM_OCD1_VTH_TRIM_Msk 0xFFUL
/* SFLASH.IMO_TRIM_LT */
#define SFLASH_IMO_TRIM_LT_OFFSET_Pos           0UL
#define SFLASH_IMO_TRIM_LT_OFFSET_Msk           0xFFUL
/* SFLASH.IMO_TCTRIM_LT */
#define SFLASH_IMO_TCTRIM_LT_FSOFFSET_Pos       0UL
#define SFLASH_IMO_TCTRIM_LT_FSOFFSET_Msk       0x7UL
#define SFLASH_IMO_TCTRIM_LT_TCTRIM_Pos         4UL
#define SFLASH_IMO_TCTRIM_LT_TCTRIM_Msk         0xF0UL
/* SFLASH.IMO_STEPSIZE_LT */
#define SFLASH_IMO_STEPSIZE_LT_STEPSIZE_Pos     0UL
#define SFLASH_IMO_STEPSIZE_LT_STEPSIZE_Msk     0x1FUL
/* SFLASH.IMO_4PCT_LIM */
#define SFLASH_IMO_4PCT_LIM_TRIM_LIMIT_Pos      0UL
#define SFLASH_IMO_4PCT_LIM_TRIM_LIMIT_Msk      0xFFUL
/* SFLASH.IMO_3PCT_LIM */
#define SFLASH_IMO_3PCT_LIM_TRIM_LIMIT_Pos      0UL
#define SFLASH_IMO_3PCT_LIM_TRIM_LIMIT_Msk      0xFFUL
/* SFLASH.PILO_6PCT_LIM */
#define SFLASH_PILO_6PCT_LIM_TRIM_LIMIT_Pos     0UL
#define SFLASH_PILO_6PCT_LIM_TRIM_LIMIT_Msk     0xFFUL
/* SFLASH.PACSS_CHAN0_2TEMP_TRIM */
#define SFLASH_PACSS_CHAN0_2TEMP_TRIM_OFFSETADJ_Pos 0UL
#define SFLASH_PACSS_CHAN0_2TEMP_TRIM_OFFSETADJ_Msk 0xFFFFUL
#define SFLASH_PACSS_CHAN0_2TEMP_TRIM_GAINADJ_Pos 16UL
#define SFLASH_PACSS_CHAN0_2TEMP_TRIM_GAINADJ_Msk 0xFFFF0000UL
/* SFLASH.PACSS_CHAN1_2TEMP_TRIM */
#define SFLASH_PACSS_CHAN1_2TEMP_TRIM_OFFSETADJ_Pos 0UL
#define SFLASH_PACSS_CHAN1_2TEMP_TRIM_OFFSETADJ_Msk 0xFFFFUL
#define SFLASH_PACSS_CHAN1_2TEMP_TRIM_GAINADJ_Pos 16UL
#define SFLASH_PACSS_CHAN1_2TEMP_TRIM_GAINADJ_Msk 0xFFFF0000UL
/* SFLASH.PACSS_CHAN1_3TEMP_TRIM */
#define SFLASH_PACSS_CHAN1_3TEMP_TRIM_OFFSETADJ_Pos 0UL
#define SFLASH_PACSS_CHAN1_3TEMP_TRIM_OFFSETADJ_Msk 0xFFFFUL
#define SFLASH_PACSS_CHAN1_3TEMP_TRIM_GAINADJ_Pos 16UL
#define SFLASH_PACSS_CHAN1_3TEMP_TRIM_GAINADJ_Msk 0xFFFF0000UL
/* SFLASH.PACSS_CHAN_3TEMP_CENTERTEMP */
#define SFLASH_PACSS_CHAN_3TEMP_CENTERTEMP_CENTERTEMP_Pos 0UL
#define SFLASH_PACSS_CHAN_3TEMP_CENTERTEMP_CENTERTEMP_Msk 0xFFUL
/* SFLASH.PACSS_CHAN_OFFSET_SCLR */
#define SFLASH_PACSS_CHAN_OFFSET_SCLR_OFFSETSCLR_Pos 0UL
#define SFLASH_PACSS_CHAN_OFFSET_SCLR_OFFSETSCLR_Msk 0xFFUL
/* SFLASH.PACSS_DIAG_RSH_PURES */
#define SFLASH_PACSS_DIAG_RSH_PURES_RES_COLD_Pos 0UL
#define SFLASH_PACSS_DIAG_RSH_PURES_RES_COLD_Msk 0xFFUL
#define SFLASH_PACSS_DIAG_RSH_PURES_RES_HOT_Pos 8UL
#define SFLASH_PACSS_DIAG_RSH_PURES_RES_HOT_Msk 0xFF00UL
/* SFLASH.PACSS_DIAG_RSL_PURES */
#define SFLASH_PACSS_DIAG_RSL_PURES_RES_COLD_Pos 0UL
#define SFLASH_PACSS_DIAG_RSL_PURES_RES_COLD_Msk 0xFFUL
#define SFLASH_PACSS_DIAG_RSL_PURES_RES_HOT_Pos 8UL
#define SFLASH_PACSS_DIAG_RSL_PURES_RES_HOT_Msk 0xFF00UL
/* SFLASH.PACSS_DIAG_RSH2_PURES */
#define SFLASH_PACSS_DIAG_RSH2_PURES_RES_COLD_Pos 0UL
#define SFLASH_PACSS_DIAG_RSH2_PURES_RES_COLD_Msk 0xFFUL
#define SFLASH_PACSS_DIAG_RSH2_PURES_RES_HOT_Pos 8UL
#define SFLASH_PACSS_DIAG_RSH2_PURES_RES_HOT_Msk 0xFF00UL
/* SFLASH.PACSS_DIAG_RSL2_PURES */
#define SFLASH_PACSS_DIAG_RSL2_PURES_RES_COLD_Pos 0UL
#define SFLASH_PACSS_DIAG_RSL2_PURES_RES_COLD_Msk 0xFFUL
#define SFLASH_PACSS_DIAG_RSL2_PURES_RES_HOT_Pos 8UL
#define SFLASH_PACSS_DIAG_RSL2_PURES_RES_HOT_Msk 0xFF00UL
/* SFLASH.PACSS_CHAN1_ETEMP_TRIM */
#define SFLASH_PACSS_CHAN1_ETEMP_TRIM_ETGAINADJ_Pos 0UL
#define SFLASH_PACSS_CHAN1_ETEMP_TRIM_ETGAINADJ_Msk 0xFFFFUL
/* SFLASH.PACSS_DIAG_TEMP_P_CAL_S */
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_1_MASK_Pos 0UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_1_MASK_Msk 0x1FFUL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_BIPOLAR_1_MASK_Pos 10UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_BIPOLAR_1_MASK_Msk 0x7FC00UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_BIPOLAR_UNIT_MASK_Pos 20UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_BIPOLAR_UNIT_MASK_Msk 0x1FF00000UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_UNIT_MODE_Pos 29UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_UNIT_MODE_Msk 0x20000000UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_SEL_Pos 30UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_SEL_Msk 0x40000000UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_LOAD_MODE_Pos 31UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_S_LOAD_MODE_Msk 0x80000000UL
/* SFLASH.PACSS_DIAG_TEMP_P_CAL_A2 */
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_A2_A2_Pos  0UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_A2_A2_Msk  0xFFFFUL
/* SFLASH.PACSS_DIAG_TEMP_P_CAL_A1 */
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_A1_A1_Pos  0UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_A1_A1_Msk  0xFFFFUL
/* SFLASH.PACSS_DIAG_TEMP_P_CAL_A0 */
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_A0_A0_Pos  0UL
#define SFLASH_PACSS_DIAG_TEMP_P_CAL_A0_A0_Msk  0xFFFFUL
/* SFLASH.PACSS_CHAN1_ETEMP_TRIM_2 */
#define SFLASH_PACSS_CHAN1_ETEMP_TRIM_2_ETGAINADJ2_Pos 0UL
#define SFLASH_PACSS_CHAN1_ETEMP_TRIM_2_ETGAINADJ2_Msk 0xFFFFUL
/* SFLASH.PACSS_DIAG_TEMP_A_CAL_S */
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_1_MASK_Pos 0UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_1_MASK_Msk 0x1FFUL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_BIPOLAR_1_MASK_Pos 10UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_BIPOLAR_1_MASK_Msk 0x7FC00UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_BIPOLAR_UNIT_MASK_Pos 20UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_BIPOLAR_UNIT_MASK_Msk 0x1FF00000UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_UNIT_MODE_Pos 29UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_UNIT_MODE_Msk 0x20000000UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_SEL_Pos 30UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_SEL_Msk 0x40000000UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_LOAD_MODE_Pos 31UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_S_LOAD_MODE_Msk 0x80000000UL
/* SFLASH.PACSS_DIAG_TEMP_A_CAL_A2 */
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_A2_A2_Pos  0UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_A2_A2_Msk  0xFFFFUL
/* SFLASH.PACSS_DIAG_TEMP_A_CAL_A1 */
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_A1_A1_Pos  0UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_A1_A1_Msk  0xFFFFUL
/* SFLASH.PACSS_DIAG_TEMP_A_CAL_A0 */
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_A0_A0_Pos  0UL
#define SFLASH_PACSS_DIAG_TEMP_A_CAL_A0_A0_Msk  0xFFFFUL
/* SFLASH.SAR_TEMP_MULTIPLIER */
#define SFLASH_SAR_TEMP_MULTIPLIER_TEMP_MULTIPLIER_Pos 0UL
#define SFLASH_SAR_TEMP_MULTIPLIER_TEMP_MULTIPLIER_Msk 0xFFFFUL
/* SFLASH.SAR_TEMP_OFFSET */
#define SFLASH_SAR_TEMP_OFFSET_TEMP_OFFSET_Pos  0UL
#define SFLASH_SAR_TEMP_OFFSET_TEMP_OFFSET_Msk  0xFFFFUL


#endif /* _CYIP_SFLASH_128X4_H_ */


/* [] END OF FILE */
