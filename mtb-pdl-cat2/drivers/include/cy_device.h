/***************************************************************************//**
* \file cy_device.h
* \version 1.50
*
* This file specifies the structure for core and peripheral block HW base
* addresses, versions, and parameters.
*
********************************************************************************
* \copyright
* (c) (2018-2025), Cypress Semiconductor Corporation (an Infineon company) or
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


#ifndef CY_DEVICE_H_
#define CY_DEVICE_H_

#include "cy_device_headers.h"
#include <stdint.h>
#include <stddef.h>


/*******************************************************************************
*               Register Access Helper Macros
*******************************************************************************/

#define CY_SYSCLK_HF_CLK_MAX_FREQ           (CY_HF_CLK_MAX_FREQ)
#define CY_CHECK_BIT(var,pos) ((uint32_t)(var) & ((uint32_t)1UL<<(uint32_t)(pos)))


/*******************************************************************************
*                SRSS Common
*******************************************************************************/

#if defined(CY_IP_S8SRSSLT)
    #define SRSS_Type SRSSLT_Type
    #define SRSS SRSSLT
    /* Macros to concatenate register definitions (SRSSLT_CLK_SELECT). */
    #define SRSS_CONCAT(param)    SRSSLT_ ## param
#elif defined(CY_IP_M0S8SRSSHV)
    #define SRSS_Type SRSSHV_Type
    #define SRSS SRSSHV
    /* Macros to concatenate register definitions (SRSSHV_CLK_SELECT). */
    #define SRSS_CONCAT(param)    SRSSHV_ ## param
#endif /* defined(CY_IP_S8SRSSLT) */

#define SRSS_PWR_CONTROL                    (((SRSS_Type *) SRSS)->PWR_CONTROL)
#define SRSS_RES_CAUSE                      (((SRSS_Type *) SRSS)->RES_CAUSE)
#define SRSS_PWR_KEY_DELAY                  (((SRSS_Type *) SRSS)->PWR_KEY_DELAY)

#define SRSS_CLK_SELECT                     (((SRSS_Type *) SRSS)->CLK_SELECT)
#define SRSS_CLK_SELECT_HFCLK_SEL_Pos       SRSS_CONCAT(CLK_SELECT_HFCLK_SEL_Pos)
#define SRSS_CLK_SELECT_HFCLK_SEL_Msk       SRSS_CONCAT(CLK_SELECT_HFCLK_SEL_Msk)
#define SRSS_CLK_SELECT_PUMP_SEL_Pos        SRSS_CONCAT(CLK_SELECT_PUMP_SEL_Pos)
#define SRSS_CLK_SELECT_PUMP_SEL_Msk        SRSS_CONCAT(CLK_SELECT_PUMP_SEL_Msk)
#define SRSS_CLK_SELECT_HFCLK_DIV_Pos       SRSS_CONCAT(CLK_SELECT_HFCLK_DIV_Pos)
#define SRSS_CLK_SELECT_HFCLK_DIV_Msk       SRSS_CONCAT(CLK_SELECT_HFCLK_DIV_Msk)
#define SRSS_CLK_SELECT_SYSCLK_DIV_Pos      SRSS_CONCAT(CLK_SELECT_SYSCLK_DIV_Pos)
#define SRSS_CLK_SELECT_SYSCLK_DIV_Msk      SRSS_CONCAT(CLK_SELECT_SYSCLK_DIV_Msk)

#define SRSS_CLK_DFT_SELECT                 (((SRSS_Type *) SRSS)->CLK_DFT_SELECT)
#define SRSS_CLK_DFT_SELECT_DFT_SEL0_Pos    SRSS_CONCAT(CLK_DFT_SELECT_DFT_SEL0_Pos)
#define SRSS_CLK_DFT_SELECT_DFT_SEL0_Msk    SRSS_CONCAT(CLK_DFT_SELECT_DFT_SEL0_Msk)
#define SRSS_CLK_DFT_SELECT_DFT_SEL1_Pos    SRSS_CONCAT(CLK_DFT_SELECT_DFT_SEL1_Pos)
#define SRSS_CLK_DFT_SELECT_DFT_SEL1_Msk    SRSS_CONCAT(CLK_DFT_SELECT_DFT_SEL1_Msk)

#define SRSS_CLK_CAL_CNT1                   (((SRSS_Type *) SRSS)->CLK_CAL_CNT1)
#define SRSS_CLK_CAL_CNT2                   (((SRSS_Type *) SRSS)->CLK_CAL_CNT2)

#define SRSS_CLK_ILO_CONFIG                 (((SRSS_Type *) SRSS)->CLK_ILO_CONFIG)
#define SRSS_CLK_ILO_CONFIG_ENABLE_Pos      SRSS_CONCAT(CLK_ILO_CONFIG_ENABLE_Pos)
#define SRSS_CLK_ILO_CONFIG_ENABLE_Msk      SRSS_CONCAT(CLK_ILO_CONFIG_ENABLE_Msk)

#define SRSS_CLK_IMO_CONFIG                 (((SRSS_Type *) SRSS)->CLK_IMO_CONFIG)
#define SRSS_CLK_IMO_CONFIG_ENABLE_Pos      SRSS_CONCAT(CLK_IMO_CONFIG_ENABLE_Pos)
#define SRSS_CLK_IMO_CONFIG_ENABLE_Msk      SRSS_CONCAT(CLK_IMO_CONFIG_ENABLE_Msk)
#define SRSS_CLK_IMO_SELECT                 (((SRSS_Type *) SRSS)->CLK_IMO_SELECT)
#define SRSS_CLK_IMO_SELECT_FREQ_Pos        SRSS_CONCAT(CLK_IMO_SELECT_FREQ_Pos)
#define SRSS_CLK_IMO_SELECT_FREQ_Msk        SRSS_CONCAT(CLK_IMO_SELECT_FREQ_Msk)
#define SRSS_CLK_IMO_TRIM1                  (((SRSS_Type *) SRSS)->CLK_IMO_TRIM1)
#define SRSS_CLK_IMO_TRIM1_OFFSET_Pos        SRSS_CONCAT(CLK_IMO_TRIM1_OFFSET_Pos)
#define SRSS_CLK_IMO_TRIM1_OFFSET_Msk        SRSS_CONCAT(CLK_IMO_TRIM1_OFFSET_Msk)
#define SRSS_CLK_IMO_TRIM2                  (((SRSS_Type *) SRSS)->CLK_IMO_TRIM2)
#define SRSS_CLK_IMO_TRIM2_FSOFFSET_Pos     SRSS_CONCAT(CLK_IMO_TRIM2_FSOFFSET_Pos)
#define SRSS_CLK_IMO_TRIM2_FSOFFSET_Msk     SRSS_CONCAT(CLK_IMO_TRIM2_FSOFFSET_Msk)
#define SRSS_CLK_IMO_TRIM3                  (((SRSS_Type *) SRSS)->CLK_IMO_TRIM3)

#define SRSS_SRSS_INTR                      (((SRSS_Type *) SRSS)->SRSS_INTR)
#define SRSS_SRSS_INTR_SET                  (((SRSS_Type *) SRSS)->SRSS_INTR_SET)
#define SRSS_SRSS_INTR_MASK                 (((SRSS_Type *) SRSS)->SRSS_INTR_MASK)

#define SRSS_TST_DDFT_CTRL                  (*((__IOM uint32_t *)(SRSS_CONCAT(BASE) + 0x18UL)))
#define SRSS_TST_DDFT_CTRL_DFT_SEL0_Pos     0UL
#define SRSS_TST_DDFT_CTRL_DFT_SEL0_Msk     0xFUL
#define SRSS_TST_DDFT_CTRL_DFT_SEL1_Pos     8UL
#define SRSS_TST_DDFT_CTRL_DFT_SEL1_Msk     0xF00UL


/*******************************************************************************
*                SRSSLT (for SRSSLT only)
*******************************************************************************/

#if defined(CY_IP_S8SRSSLT)
    #define SRSSLT_PWR_KEY_DELAY                (((SRSSLT_Type *) SRSSLT)->PWR_KEY_DELAY)

    #define SRSSLT_CLK_SELECT                   (((SRSSLT_Type *) SRSSLT)->CLK_SELECT)
    #define SRSSLT_CLK_ILO_CONFIG               (((SRSSLT_Type *) SRSSLT)->CLK_ILO_CONFIG)
    #define SRSSLT_CLK_IMO_CONFIG               (((SRSSLT_Type *) SRSSLT)->CLK_IMO_CONFIG)
    #define SRSSLT_CLK_DFT_SELECT               (((SRSSLT_Type *) SRSSLT)->CLK_DFT_SELECT)
    #define SRSSLT_CLK_IMO_SELECT               (((SRSSLT_Type *) SRSSLT)->CLK_IMO_SELECT)
    #define SRSSLT_CLK_IMO_TRIM1                (((SRSSLT_Type *) SRSSLT)->CLK_IMO_TRIM1)
    #define SRSSLT_CLK_IMO_TRIM2                (((SRSSLT_Type *) SRSSLT)->CLK_IMO_TRIM2)
    #define SRSSLT_CLK_IMO_TRIM3                (((SRSSLT_Type *) SRSSLT)->CLK_IMO_TRIM3)

    #define SRSSLT_SRSS_INTR                      (((SRSSLT_Type *) SRSSLT)->SRSS_INTR)
    #define SRSSLT_SRSS_INTR_SET                  (((SRSSLT_Type *) SRSSLT)->SRSS_INTR_SET)
    #define SRSSLT_SRSS_INTR_MASK                 (((SRSSLT_Type *) SRSSLT)->SRSS_INTR_MASK)

    #define SRSSLT_TST_DDFT_CTRL                   (*((__IOM uint32_t *)(SRSSLT_BASE + 0x18UL)))
    #define SRSSLT_TST_DDFT_CTRL_DFT_SEL0_Pos      0UL
    #define SRSSLT_TST_DDFT_CTRL_DFT_SEL0_Msk      0xFUL
    #define SRSSLT_TST_DDFT_CTRL_DFT_SEL1_Pos      8UL
    #define SRSSLT_TST_DDFT_CTRL_DFT_SEL1_Msk      0xF00UL

    #define SRSSLT_WDT_DISABLE_KEY          (((SRSSLT_Type *) SRSSLT)->WDT_DISABLE_KEY)
    #define SRSSLT_WDT_COUNTER              (((SRSSLT_Type *) SRSSLT)->WDT_COUNTER)
    #define SRSSLT_WDT_MATCH                (((SRSSLT_Type *) SRSSLT)->WDT_MATCH)

    #define SRSSLT_TST_TRIM_CNTR1                  (*((__IOM uint32_t *)(SRSSLT_BASE + 0x1CUL)))
    #define SRSSLT_TST_TRIM_CNTR1_COUNTER_DONE_Pos 31UL
    #define SRSSLT_TST_TRIM_CNTR1_COUNTER_DONE_Msk 0x80000000UL

    #define SRSSLT_TST_TRIM_CNTR2                  (*((__IOM uint32_t *)(SRSSLT_BASE + 0x20UL)))
#endif /* defined(CY_IP_S8SRSSLT) */


/*******************************************************************************
*                SRSSHV (for SRSSHV only)
*******************************************************************************/

#if defined(CY_IP_M0S8SRSSHV)
    #define SRSS_PILO_CTL                       (((SRSS_Type *) SRSS)->PILO_CTL)
    #define SRSS_PILO_CTL_ILO_EN_Pos            SRSS_CONCAT(PILO_CTL_ILO_EN_Pos)
    #define SRSS_PILO_CTL_ILO_EN_Msk            SRSS_CONCAT(PILO_CTL_ILO_EN_Msk)
    #define SRSS_PILO_CTL_TR_CAP_Pos            SRSS_CONCAT(PILO_CTL_TR_CAP_Pos)
    #define SRSS_PILO_CTL_TR_CAP_Msk            SRSS_CONCAT(PILO_CTL_TR_CAP_Msk)

    #define SRSS_HPOSC_CTL                       (((SRSS_Type *) SRSS)->HPOSC_CTL)
    #define SRSS_HPOSC_CTL_IMO_EN_Pos            SRSS_CONCAT(HPOSC_CTL_IMO_EN_Pos)
    #define SRSS_HPOSC_CTL_IMO_EN_Msk            SRSS_CONCAT(HPOSC_CTL_IMO_EN_Msk)
#endif /* defined(CY_IP_M0S8SRSSHV) */


/*******************************************************************************
*                FLASHC
*******************************************************************************/

#define FLASHC_FLASH_CTL                    (FLASHC->FLASH_CTL)

#if defined(CPUSS_FLASHC_PRESENT_WITH_ECC) && (CPUSS_FLASHC_PRESENT_WITH_ECC == 1U)
#define CPUSS_FLASH_CTL                     (((CPUSS_Type *) CPUSS)->FLASH_CTL)
#define CPUSS_FLASHC_ECC_CTL                (((CPUSS_Type *) CPUSS)->FLASHC_ECC_CTL)
#endif /* defined(CPUSS_FLASHC_PRESENT_WITH_ECC) && (CPUSS_FLASHC_PRESENT_WITH_ECC == 1U) */

#if defined(CPUSS_SPCIF_FLASH_S8FS_VER2)
#define FLASH_MACRO_WRITE_EN                (((SPCIF_Type*) SPCIF_BASE)->FLASH_MACRO_WE)
/* Max value of MAC_WRITE_EN bit (SPCIF_FLASH_MACRO_WE register) */
#define CY_FLASH_PROTECTION_BIT_PARAM_MAX   (0x0FU)
#define LOCK_FLASH                          (((SPCIF_Type*) SPCIF_BASE)->FLASH_LOCK)
#endif /* defined(CPUSS_SPCIF_FLASH_S8FS_VER2) */


/*******************************************************************************
*                SFLASH
*******************************************************************************/

#define SFLASH_SILICON_ID                   (((SFLASH_Type *) SFLASH)->SILICON_ID)
#define SFLASH_DPSLP_KEY_DELAY              (((SFLASH_Type *) SFLASH)->DPSLP_KEY_DELAY)

#define SFLASH_IMO_TRIM_LT(freq)            ((uint32_t)(((SFLASH_Type *) SFLASH)->IMO_TRIM_LT[(freq)]))
#define SFLASH_IMO_TCTRIM_LT(freq)          ((uint32_t)(((SFLASH_Type *) SFLASH)->IMO_TCTRIM_LT[(freq)]))
#define SFLASH_IMO_STEPSIZE_LT(freq)        ((uint32_t)(((SFLASH_Type *) SFLASH)->IMO_STEPSIZE_LT[(freq)]))

/* CapSense-related trim registers */
#define SFLASH_CSD0_ADC_VREF_TRIM1          (((SFLASH_Type *) SFLASH)->CSDV2_CSD0_ADC_TRIM1)
#define SFLASH_CSD0_ADC_VREF_TRIM2          (((SFLASH_Type *) SFLASH)->CSDV2_CSD0_ADC_TRIM2)

#if defined(CY_IP_M0S8MSCV3LP)
    #define SFLASH_MSCLP0_CLK_IMO_TRIM1_46_MHZ  ((uint32_t)(((SFLASH_Type *) SFLASH)->MSCLP_CLK_IMO_TRIM1_46))
    #define SFLASH_MSCLP0_CLK_IMO_TRIM3_46_MHZ  ((uint32_t)(((SFLASH_Type *) SFLASH)->MSCLP_CLK_IMO_TRIM3_46))
    #define SFLASH_MSCLP0_CLK_IMO_TRIM1_38_MHZ  ((uint32_t)(((SFLASH_Type *) SFLASH)->MSCLP_CLK_IMO_TRIM1_38))
    #define SFLASH_MSCLP0_CLK_IMO_TRIM3_38_MHZ  ((uint32_t)(((SFLASH_Type *) SFLASH)->MSCLP_CLK_IMO_TRIM3_38))
    #define SFLASH_MSCLP0_CLK_IMO_TRIM1_25_MHZ  ((uint32_t)(((SFLASH_Type *) SFLASH)->MSCLP_CLK_IMO_TRIM1_25))
    #define SFLASH_MSCLP0_CLK_IMO_TRIM3_25_MHZ  ((uint32_t)(((SFLASH_Type *) SFLASH)->MSCLP_CLK_IMO_TRIM3_25))
#endif /* CY_IP_M0S8MSCV3LP */

#if defined (SFLASH_HAS_DYNAMIC_IMO)

#define CY_SAR_TEMP_H_TENTH_DEGREE           (1000)             /**< Hot temperature in tens of degrees Celsius (100C) */
#define CY_SAR_TEMP_RH_TENTH_DEGREE          (625)              /**< Room hot temperature in tens of degrees Celsius (62.5C) */
#define CY_SAR_TEMP_R_TENTH_DEGREE           (250)              /**< Room temperature in tens of degrees Celsius (25C) */
#define CY_SAR_TEMP_RC_TENTH_DEGREE          (-75)              /**< Room cold temperature in tens of degrees Celsius (-7.5C) */
#define CY_SAR_TEMP_C_TENTH_DEGREE           (-400)             /**< Cold temperature in tens of degrees Celsius (-40C) */

/**
  * \brief Die temperature in SAR counts
  */
typedef struct {
    volatile const uint16_t CY_SAR_TEMP_H_COUNTS;               /*!< SAR counts for dietemp at 100C */
    volatile const uint16_t CY_SAR_TEMP_C_COUNTS;               /*!< SAR counts for dietemp at 62.5C */
    volatile const uint16_t CY_SAR_TEMP_R_COUNTS;               /*!< SAR counts for dietemp at 25C */
    volatile const uint16_t CY_SAR_TEMP_RH_COUNTS;              /*!< SAR counts for dietemp at -7.5C */
    volatile const uint16_t CY_SAR_TEMP_RC_COUNTS;              /*!< SAR counts for dietemp at -40C */
}SFLASH_IMO_CAL_TEMP_Type;


#define CY_SFLASH_REG_OFFSET_ADC_DIODE_100C_LSB                 (offsetof(SFLASH_Type, DYN_IMO_ADC_DIODE_100C_LSB))  /**< The register offset */
#ifndef CY_SFLASH_IMO_CAL_TEMP_BASE
    #define CY_SFLASH_IMO_CAL_TEMP_BASE                         (SFLASH_BASE + CY_SFLASH_REG_OFFSET_ADC_DIODE_100C_LSB)
#endif
#define CY_SFLASH_IMO_CAL_TEMP                                  ((SFLASH_IMO_CAL_TEMP_Type *) CY_SFLASH_IMO_CAL_TEMP_BASE)

/**
  * \brief IMO Trim values
  */
typedef struct {
    volatile const uint8_t CY_SYSCLK_IMO_TRIM_HOT[7];           /*!<Trim value at 100C for 24Mhz, 28Mhz, ... 48Mhz */
    volatile const uint8_t CY_SYSCLK_IMO_TRIM_COLD[7];          /*!<Trim value at -40C for 24Mhz, 28Mhz, ... 48Mhz */
    volatile const uint8_t CY_SYSCLK_IMO_TRIM_ROOM[7];          /*!<Trim value at 25C for 24Mhz, 28Mhz, ... 48Mhz */
    volatile const uint8_t CY_SYSCLK_IMO_TRIM_ROOM_HOT[7];      /*!<Trim value at between Room and Hot for 24Mhz, 28Mhz, ... 48Mhz */
    volatile const uint8_t CY_SYSCLK_IMO_TRIM_ROOM_COLD[7];     /*!<Trim value at between Room and Cold for 24Mhz, 28Mhz, ... 48Mhz */
    volatile const uint8_t CY_SYSCLK_IMO_TRIM_OFFSET_HOT[7];    /*!<Offset trim value for Hot for 24Mhz, 28Mhz, ... 48Mhz */
    volatile const uint8_t CY_SYSCLK_IMO_TRIM_OFFSET_COLD[7];   /*!<Offset trim value for Cold for 24Mhz, 28Mhz, ... 48Mhz */
}SFLASH_IMO_CAL_TRIM_Type;

#define CY_SFLASH_REG_OFFSET_IMO_24MHZ_TRIM_100C                (offsetof(SFLASH_Type, DYN_IMO_24MHZ_TRIM_100C))  /**< The register offset */
#ifndef CY_SFLASH_IMO_CAL_TRIM_BASE
    #define CY_SFLASH_IMO_CAL_TRIM_BASE                         (SFLASH_BASE + CY_SFLASH_REG_OFFSET_IMO_24MHZ_TRIM_100C)
#endif
#define CY_SFLASH_IMO_CAL_TRIM                                  ((SFLASH_IMO_CAL_TRIM_Type *) CY_SFLASH_IMO_CAL_TRIM_BASE)


#endif /* SFLASH_HAS_DYNAMIC_IMO */

#if defined(CPUSS_SPCIF_FLASH_S8FS_VER2)
#define SFLASH_USER_AREA                    (((SFLASH_Type *) SFLASH)->USER_SFLASH_AREA[0U])
#define SFLASH_USER_AREA1                   (((SFLASH_Type *) SFLASH)->USER_SFLASH_AREA[1U])
#endif /* defined(CPUSS_SPCIF_FLASH_S8FS_VER2) */

/*******************************************************************************
*                CPUSS
*******************************************************************************/

#define CPUSS_FLASH_CTL                     (((CPUSS_Type *) CPUSS)->FLASH_CTL)

#define CPUSS_SYSREQ                        (((CPUSS_Type *) CPUSS)->SYSREQ)
#define CPUSS_SYSARG                        (((CPUSS_Type *) CPUSS)->SYSARG)

/* ARM core registers */
#define SYSTICK_CTRL                        (((SysTick_Type *)SysTick)->CTRL)
#define SYSTICK_LOAD                        (((SysTick_Type *)SysTick)->LOAD)
#define SYSTICK_VAL                         (((SysTick_Type *)SysTick)->VAL)
#define SCB_SCR                             (((SCB_Type *)SCB)->SCR)


/*******************************************************************************
*                LPCOMP
*******************************************************************************/

#define LPCOMP_CONFIG(base)                 (((LPCOMP_Type *)(base))->CONFIG)
#define LPCOMP_INTR(base)                   (((LPCOMP_Type *)(base))->INTR)
#define LPCOMP_INTR_SET(base)               (((LPCOMP_Type *)(base))->INTR_SET)
#define LPCOMP_INTR_MASK(base)              (((LPCOMP_Type *)(base))->INTR_MASK)
#define LPCOMP_INTR_MASKED(base)            (((LPCOMP_Type *)(base))->INTR_MASKED)
#define LPCOMP_TRIM1(base)                  (((LPCOMP_Type *)(base))->TRIM1)
#define LPCOMP_TRIM2(base)                  (((LPCOMP_Type *)(base))->TRIM2)
#define LPCOMP_TRIM3(base)                  (((LPCOMP_Type *)(base))->TRIM3)
#define LPCOMP_TRIM4(base)                  (((LPCOMP_Type *)(base))->TRIM4)

#if defined(CY_DEVICE_PSOC4HVMS64K)
    #define lpcomp_interrupt_IRQn           lpcomp_0_interrupt_IRQn
#endif
#define LPCOMP_DFT_REG                      (*((__IOM uint32_t *)(LPCOMP_BASE + 0x08UL)))

#define LPCOMP_DFT_CAL_EN_Pos               0UL
#define LPCOMP_DFT_CAL_EN_Msk               0x1UL
#define LPCOMP_DFT_BYPASS_Pos               1UL
#define LPCOMP_DFT_BYPASS_Msk               0x2UL

/*******************************************************************************
*                TCPWM
*******************************************************************************/

#define TCPWM_CTRL(base)                (((TCPWM_Type *)(base))->CTRL)
#define TCPWM_CMD(base)                 (((TCPWM_Type *)(base))->CMD)

#define TCPWM_CNT_CTRL(base, cntNum)         (((TCPWM_Type *)(base))->CNT[cntNum].CTRL)
#define TCPWM_CNT_CC(base, cntNum)           (((TCPWM_Type *)(base))->CNT[cntNum].CC)
#define TCPWM_CNT_CC_BUFF(base, cntNum)      (((TCPWM_Type *)(base))->CNT[cntNum].CC_BUFF)
#define TCPWM_CNT_COUNTER(base, cntNum)      (((TCPWM_Type *)(base))->CNT[cntNum].COUNTER)
#define TCPWM_CNT_PERIOD(base, cntNum)       (((TCPWM_Type *)(base))->CNT[cntNum].PERIOD)
#define TCPWM_CNT_PERIOD_BUFF(base, cntNum)  (((TCPWM_Type *)(base))->CNT[cntNum].PERIOD_BUFF)
#define TCPWM_CNT_STATUS(base, cntNum)       (((TCPWM_Type *)(base))->CNT[cntNum].STATUS)
#define TCPWM_CNT_INTR(base, cntNum)         (((TCPWM_Type *)(base))->CNT[cntNum].INTR)
#define TCPWM_CNT_INTR_SET(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].INTR_SET)
#define TCPWM_CNT_INTR_MASK(base, cntNum)    (((TCPWM_Type *)(base))->CNT[cntNum].INTR_MASK)
#define TCPWM_CNT_INTR_MASKED(base, cntNum)  (((TCPWM_Type *)(base))->CNT[cntNum].INTR_MASKED)
#define TCPWM_CNT_TR_CTRL0(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL0)
#define TCPWM_CNT_TR_CTRL1(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL1)
#define TCPWM_CNT_TR_CTRL2(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL2)


/*******************************************************************************
*                SAR
*******************************************************************************/

#define SAR_SAMPLE_CTRL(base)               (((SAR_Type *)(base))->SAMPLE_CTRL)
#define SAR_SAMPLE_TIME01(base)             (((SAR_Type *)(base))->SAMPLE_TIME01)
#define SAR_SAMPLE_TIME23(base)             (((SAR_Type *)(base))->SAMPLE_TIME23)

#define SAR_RANGE_THRES(base)               (((SAR_Type *)(base))->RANGE_THRES)
#define SAR_RANGE_COND(base)                (((SAR_Type *)(base))->RANGE_COND)
#define SAR_RANGE_INTR(base)                (((SAR_Type *)(base))->RANGE_INTR)
#define SAR_RANGE_INTR_SET(base)            (((SAR_Type *)(base))->RANGE_INTR_SET)

#define SAR_RANGE_INTR_MASK(base)           (((SAR_Type *)(base))->RANGE_INTR_MASK)
#define SAR_RANGE_INTR_MASKED(base)         (((SAR_Type *)(base))->RANGE_INTR_MASKED)

#define SAR_CHAN_EN(base)                   (((SAR_Type *)(base))->CHAN_EN)
#define SAR_CHAN_CONFIG(base, chan)         (((SAR_Type *)(base))->CHAN_CONFIG[(chan)])
#define SAR_CHAN_RESULT(base, chan)         (((SAR_Type *)(base))->CHAN_RESULT[(chan)])

#if defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4u <= CY_IP_M0S8PASS4A_SAR_VERSION)
    #define SAR_CHAN_RESULT_VALID(base)         (((SAR_Type *)(base))->CHAN_RESULT_UPDATED)
#else
    #define SAR_CHAN_RESULT_VALID(base)         (((SAR_Type *)(base))->CHAN_RESULT_VALID)
#endif /* 4u <= CY_IP_M0S8PASS4A_SAR_VERSION */

#define SAR_INTR(base)                      (((SAR_Type *)(base))->INTR)
#define SAR_INTR_MASK(base)                 (((SAR_Type *)(base))->INTR_MASK)
#define SAR_INTR_MASKED(base)               (((SAR_Type *)(base))->INTR_MASKED)
#define SAR_INTR_SET(base)                  (((SAR_Type *)(base))->INTR_SET)
#define SAR_INTR_CAUSE(base)                (((SAR_Type *)(base))->INTR_CAUSE)

#define SAR_MUX_SWITCH_CLEAR0(base)         (((SAR_Type *)(base))->MUX_SWITCH_CLEAR0)
#define SAR_MUX_SWITCH0(base)               (((SAR_Type *)(base))->MUX_SWITCH0)
#define SAR_MUX_SWITCH_HW_CTRL(base)        (((SAR_Type *)(base))->MUX_SWITCH_HW_CTRL)
#if defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)
#define SAR_MUX_SWITCH_CLEAR2(base)         (((SAR_Type *)(base))->MUX_SWITCH_CLEAR2)
#define SAR_MUX_SWITCH2(base)               (((SAR_Type *)(base))->MUX_SWITCH2)
#define SAR_MUX_SWITCH_HW_CTRL2(base)       (((SAR_Type *)(base))->MUX_SWITCH_HW_CTRL2)
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */

#define SAR_ANA_TRIM(base)                  (((SAR_Type *)(base))->ANA_TRIM)
#define SAR_PUMP_CTRL(base)                 (((SAR_Type *)(base))->PUMP_CTRL)
#define SAR_CTRL(base)                      (((SAR_Type *)(base))->CTRL)
#define SAR_STATUS(base)                    (((SAR_Type *)(base))->STATUS)
#define SAR_START_CTRL(base)                (((SAR_Type *)(base))->START_CTRL)

#define SAR_SATURATE_INTR(base)             (((SAR_Type *)(base))->SATURATE_INTR)
#define SAR_SATURATE_INTR_MASK(base)        (((SAR_Type *)(base))->SATURATE_INTR_MASK)
#define SAR_SATURATE_INTR_MASKED(base)      (((SAR_Type *)(base))->SATURATE_INTR_MASKED)
#define SAR_SATURATE_INTR_SET(base)         (((SAR_Type *)(base))->SATURATE_INTR_SET)

#define SAR_INJ_CHAN_CONFIG(base)           (((SAR_Type *)(base))->INJ_CHAN_CONFIG)
#define SAR_INJ_RESULT(base)                (((SAR_Type *)(base))->INJ_RESULT)


/*******************************************************************************
*                SMARTIO
*******************************************************************************/
#define SMARTIO_PRT_Type                        PRGIO_PRT_Type
#define SMARTIO_PRT_CTL(base)                   (((SMARTIO_PRT_Type *)(base))->CTL)
#define SMARTIO_PRT_SYNC_CTL(base)              (((SMARTIO_PRT_Type *)(base))->SYNC_CTL)
#define SMARTIO_PRT_LUT_SEL(base, idx)          (((SMARTIO_PRT_Type *)(base))->LUT_SEL[idx])
#define SMARTIO_PRT_LUT_CTL(base, idx)          (((SMARTIO_PRT_Type *)(base))->LUT_CTL[idx])
#define SMARTIO_PRT_DU_SEL(base)                (((SMARTIO_PRT_Type *)(base))->DU_SEL)
#define SMARTIO_PRT_DU_CTL(base)                (((SMARTIO_PRT_Type *)(base))->DU_CTL)
#define SMARTIO_PRT_DATA(base)                  (((SMARTIO_PRT_Type *)(base))->DATA)
#define SMARTIO_PRT_CTL_BYPASS_Pos              PRGIO_PRT_CTL_BYPASS_Pos
#define SMARTIO_PRT_CTL_BYPASS_Msk              PRGIO_PRT_CTL_BYPASS_Msk
#define SMARTIO_PRT_CTL_CLOCK_SRC_Pos           PRGIO_PRT_CTL_CLOCK_SRC_Pos
#define SMARTIO_PRT_CTL_CLOCK_SRC_Msk           PRGIO_PRT_CTL_CLOCK_SRC_Msk
#define SMARTIO_PRT_CTL_HLD_OVR_Pos             PRGIO_PRT_CTL_HLD_OVR_Pos
#define SMARTIO_PRT_CTL_HLD_OVR_Msk             PRGIO_PRT_CTL_HLD_OVR_Msk
#define SMARTIO_PRT_CTL_PIPELINE_EN_Pos         PRGIO_PRT_CTL_PIPELINE_EN_Pos
#define SMARTIO_PRT_CTL_PIPELINE_EN_Msk         PRGIO_PRT_CTL_PIPELINE_EN_Msk
#define SMARTIO_PRT_CTL_ENABLED_Pos             PRGIO_PRT_CTL_ENABLED_Pos
#define SMARTIO_PRT_CTL_ENABLED_Msk             PRGIO_PRT_CTL_ENABLED_Msk
#define SMARTIO_PRT_SYNC_CTL_IO_SYNC_EN_Pos     PRGIO_PRT_SYNC_CTL_IO_SYNC_EN_Pos
#define SMARTIO_PRT_SYNC_CTL_IO_SYNC_EN_Msk     PRGIO_PRT_SYNC_CTL_IO_SYNC_EN_Msk
#define SMARTIO_PRT_SYNC_CTL_CHIP_SYNC_EN_Pos   PRGIO_PRT_SYNC_CTL_CHIP_SYNC_EN_Pos
#define SMARTIO_PRT_SYNC_CTL_CHIP_SYNC_EN_Msk   PRGIO_PRT_SYNC_CTL_CHIP_SYNC_EN_Msk
#define SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Pos     PRGIO_PRT_LUT_SEL_LUT_TR0_SEL_Pos
#define SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk     PRGIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk
#define SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Pos     PRGIO_PRT_LUT_SEL_LUT_TR1_SEL_Pos
#define SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk     PRGIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk
#define SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Pos     PRGIO_PRT_LUT_SEL_LUT_TR2_SEL_Pos
#define SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk     PRGIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk
#define SMARTIO_PRT_LUT_CTL_LUT_Pos             PRGIO_PRT_LUT_CTL_LUT_Pos
#define SMARTIO_PRT_LUT_CTL_LUT_Msk             PRGIO_PRT_LUT_CTL_LUT_Msk
#define SMARTIO_PRT_LUT_CTL_LUT_OPC_Pos         PRGIO_PRT_LUT_CTL_LUT_OPC_Pos
#define SMARTIO_PRT_LUT_CTL_LUT_OPC_Msk         PRGIO_PRT_LUT_CTL_LUT_OPC_Msk
#define SMARTIO_PRT_DU_SEL_DU_TR0_SEL_Pos       PRGIO_PRT_DU_SEL_DU_TR0_SEL_Pos
#define SMARTIO_PRT_DU_SEL_DU_TR0_SEL_Msk       PRGIO_PRT_DU_SEL_DU_TR0_SEL_Msk
#define SMARTIO_PRT_DU_SEL_DU_TR1_SEL_Pos       PRGIO_PRT_DU_SEL_DU_TR1_SEL_Pos
#define SMARTIO_PRT_DU_SEL_DU_TR1_SEL_Msk       PRGIO_PRT_DU_SEL_DU_TR1_SEL_Msk
#define SMARTIO_PRT_DU_SEL_DU_TR2_SEL_Pos       PRGIO_PRT_DU_SEL_DU_TR2_SEL_Pos
#define SMARTIO_PRT_DU_SEL_DU_TR2_SEL_Msk       PRGIO_PRT_DU_SEL_DU_TR2_SEL_Msk
#define SMARTIO_PRT_DU_SEL_DU_DATA0_SEL_Pos     PRGIO_PRT_DU_SEL_DU_DATA0_SEL_Pos
#define SMARTIO_PRT_DU_SEL_DU_DATA0_SEL_Msk     PRGIO_PRT_DU_SEL_DU_DATA0_SEL_Msk
#define SMARTIO_PRT_DU_SEL_DU_DATA1_SEL_Pos     PRGIO_PRT_DU_SEL_DU_DATA1_SEL_Pos
#define SMARTIO_PRT_DU_SEL_DU_DATA1_SEL_Msk     PRGIO_PRT_DU_SEL_DU_DATA1_SEL_Msk
#define SMARTIO_PRT_DU_CTL_DU_SIZE_Pos          PRGIO_PRT_DU_CTL_DU_SIZE_Pos
#define SMARTIO_PRT_DU_CTL_DU_SIZE_Msk          PRGIO_PRT_DU_CTL_DU_SIZE_Msk
#define SMARTIO_PRT_DU_CTL_DU_OPC_Pos           PRGIO_PRT_DU_CTL_DU_OPC_Pos
#define SMARTIO_PRT_DU_CTL_DU_OPC_Msk           PRGIO_PRT_DU_CTL_DU_OPC_Msk
#define SMARTIO_PRT_DATA_DATA_Pos               PRGIO_PRT_DATA_DATA_Pos
#define SMARTIO_PRT_DATA_DATA_Msk               PRGIO_PRT_DATA_DATA_Msk


/*******************************************************************************
*                DMAC
*******************************************************************************/

#define DMAC_CTL(base)                          (((DMAC_Type*)(base))->CTL)
#define DMAC_STATUS(base)                       (((DMAC_Type*)(base))->STATUS)
#define DMAC_STATUS_SRC_ADDR(base)              (((DMAC_Type*)(base))->STATUS_SRC_ADDR)
#define DMAC_STATUS_DST_ADDR(base)              (((DMAC_Type*)(base))->STATUS_DST_ADDR)
#define DMAC_STATUS_CH_ACT(base)                (((DMAC_Type*)(base))->STATUS_CH_ACT)
#define DMAC_CH_CTL(base, chNum)                (((DMAC_Type*)(base))->CH_CTL[(chNum)])
#define DMAC_INTR(base)                         (((DMAC_Type*)(base))->INTR)
#define DMAC_INTR_SET(base)                     (((DMAC_Type*)(base))->INTR_SET)
#define DMAC_INTR_MASK(base)                    (((DMAC_Type*)(base))->INTR_MASK)
#define DMAC_INTR_MASKED(base)                  (((DMAC_Type*)(base))->INTR_MASKED)

#define DMAC_DESCR(base, chNum)                 ((DMAC_DESCR_Type*)&(((DMAC_Type*)(base))->DESCR[(chNum)]))
#define DMAC_DESCR_PING_SRC(base, chNum)        (((DMAC_DESCR(base, chNum)))->PING_SRC)
#define DMAC_DESCR_PING_DST(base, chNum)        (((DMAC_DESCR(base, chNum)))->PING_DST)
#define DMAC_DESCR_PING_CTL(base, chNum)        (((DMAC_DESCR(base, chNum)))->PING_CTL)
#define DMAC_DESCR_PING_STATUS(base, chNum)     (((DMAC_DESCR(base, chNum)))->PING_STATUS)
#define DMAC_DESCR_PONG_SRC(base, chNum)        (((DMAC_DESCR(base, chNum)))->PONG_SRC)
#define DMAC_DESCR_PONG_DST(base, chNum)        (((DMAC_DESCR(base, chNum)))->PONG_DST)
#define DMAC_DESCR_PONG_CTL(base, chNum)        (((DMAC_DESCR(base, chNum)))->PONG_CTL)
#define DMAC_DESCR_PONG_STATUS(base, chNum)     (((DMAC_DESCR(base, chNum)))->PONG_STATUS)

#define DMAC_DESCR_GET_SRC(base, chNum, descr) \
                                                ((CY_DMAC_DESCRIPTOR_PING == (descr)) ?\
                                                (DMAC_DESCR_PING_SRC(base, chNum)) :\
                                                (DMAC_DESCR_PONG_SRC(base, chNum)))
#define DMAC_DESCR_GET_DST(base, chNum, descr) \
                                                ((CY_DMAC_DESCRIPTOR_PING == (descr)) ?\
                                                (DMAC_DESCR_PING_DST(base, chNum)) :\
                                                (DMAC_DESCR_PONG_DST(base, chNum)))
#define DMAC_DESCR_GET_CTL(base, chNum, descr) \
                                                ((CY_DMAC_DESCRIPTOR_PING == (descr)) ?\
                                                (DMAC_DESCR_PING_CTL(base, chNum)) :\
                                                (DMAC_DESCR_PONG_CTL(base, chNum)))
#define DMAC_DESCR_GET_STATUS(base, chNum, descr) \
                                                ((CY_DMAC_DESCRIPTOR_PING == (descr)) ?\
                                                (DMAC_DESCR_PING_STATUS(base, chNum)) :\
                                                (DMAC_DESCR_PONG_STATUS(base, chNum)))

#define DMAC_DESCR_SET_SRC(base, chNum, descr, value) \
                                                ((CY_DMAC_DESCRIPTOR_PING == (descr)) ?\
                                                (DMAC_DESCR_PING_SRC(base, chNum) = (value)) :\
                                                (DMAC_DESCR_PONG_SRC(base, chNum) = (value)))
#define DMAC_DESCR_SET_DST(base, chNum, descr, value) \
                                                ((CY_DMAC_DESCRIPTOR_PING == (descr)) ?\
                                                (DMAC_DESCR_PING_DST(base, chNum) = (value)) :\
                                                (DMAC_DESCR_PONG_DST(base, chNum) = (value)))
#define DMAC_DESCR_SET_CTL(base, chNum, descr, value) \
                                                ((CY_DMAC_DESCRIPTOR_PING == (descr)) ?\
                                                (DMAC_DESCR_PING_CTL(base, chNum) = (value)) :\
                                                (DMAC_DESCR_PONG_CTL(base, chNum) = (value)))
#define DMAC_DESCR_SET_STATUS(base, chNum, descr, value) \
                                                ((CY_DMAC_DESCRIPTOR_PING == (descr)) ?\
                                                (DMAC_DESCR_PING_STATUS(base, chNum) = (value)) :\
                                                (DMAC_DESCR_PONG_STATUS(base, chNum) = (value)))


/*******************************************************************************
*                PERI
*******************************************************************************/

#define PERI_TR_CTL                         (PERI->TR_CTL)
#define PERI_TR_GR_TR_CTL(group, trCtl)     (PERI->TR_GROUP[group].TR_OUT_CTL[trCtl])

#define PERI_DIV_CMD                        (((PERI_Type *) PERI)->DIV_CMD)
#define PERI_PCLK_CTL                       (((PERI_Type *) PERI)->PCLK_CTL)

#define PERI_DIV_8_CTL                      (((PERI_Type *) PERI)->DIV_8_CTL)
#define PERI_DIV_16_CTL                     (((PERI_Type *) PERI)->DIV_16_CTL)
#define PERI_DIV_16_5_CTL                   (((PERI_Type *) PERI)->DIV_16_5_CTL)
#define PERI_DIV_24_5_CTL                   (((PERI_Type *) PERI)->DIV_24_5_CTL)


/*******************************************************************************
*                IOSS
*******************************************************************************/

#define GPIO_INTR_CAUSE                    (GPIO->INTR_CAUSE)

#define GPIO_PRT_DR(base)                  (((GPIO_PRT_Type*)(base))->DR)
#define GPIO_PRT_OUT_CLR(base)             (((GPIO_PRT_Type*)(base))->DR_CLR)
#define GPIO_PRT_OUT_SET(base)             (((GPIO_PRT_Type*)(base))->DR_SET)
#define GPIO_PRT_OUT_INV(base)             (((GPIO_PRT_Type*)(base))->DR_INV)
#define GPIO_PRT_IN(base)                  (((GPIO_PRT_Type*)(base))->PS)
#define GPIO_PRT_PC(base)                  (((GPIO_PRT_Type*)(base))->PC)
#define GPIO_PRT_PC2(base)                 (((GPIO_PRT_Type*)(base))->PC2)
#if defined(CY_IP_M0S8MSCV3LP)
#define GPIO_PRT_MSC_ANA(base)             (((GPIO_PRT_Type*)(base))->MSC_ANA)
#endif /* defined(CY_IP_M0S8MSCV3LP) */
#define GPIO_PRT_INTR_CFG(base)            (((GPIO_PRT_Type*)(base))->INTR_CFG)
#define GPIO_PRT_INTR(base)                (((GPIO_PRT_Type*)(base))->INTR)
#define GPIO_PRT_SIO(base)                 (((GPIO_PRT_Type*)(base))->SIO)

#define HSIOM_PRT_PORT_SEL(base)           (((HSIOM_PRT_Type *)(base))->PORT_SEL)

#define HSIOM_AMUX_SPLIT_CTL(switchCtrl)   (HSIOM->AMUX_SPLIT_CTL[switchCtrl])
#define HSIOM_PUMP_CTL                     (HSIOM->PUMP_CTL)


/*******************************************************************************
*                LCD
*******************************************************************************/

#define LCD_OCTET_NUM                       (8U) /* LCD_NUMPORTS - number of octets supporting up to 4 COMs */
#define LCD_OCTET_NUM_8                     (8U) /* LCD_NUMPORTS8 - number of octets supporting up to 8 COMs */
#define LCD_OCTET_NUM_16                    (0U) /* LCD_NUMPORTS16 - number of octets supporting up to 16 COMs */
#define LCD_COM_NUM                         (8U) /* LCD_CHIP_TOP_COM_NR - maximum number of commons */

#define LCD_ID(base)                        (((LCD_Type*)(base))->ID)
#define LCD_CONTROL(base)                   (((LCD_Type*)(base))->CONTROL)
#define LCD_DIVIDER(base)                   (((LCD_Type*)(base))->DIVIDER)
#define LCD_DATA0(base)                     (((LCD_Type*)(base))->DATA0)
#define LCD_DATA1(base)                     (((LCD_Type*)(base))->DATA1)
#define LCD_DATA2(base)                     (((LCD_Type*)(base))->DATA2)
#define LCD_DATA3(base)                     (((LCD_Type*)(base))->DATA3)


/*******************************************************************************
*                CTB
*******************************************************************************/

#define CTBM_CTB_CTRL(base)                 (((CTBM_Type *) (base))->CTB_CTRL)
#define CTBM_COMP_STAT(base)                (((CTBM_Type *) (base))->COMP_STAT)
#define CTBM_OA0_SW_CLEAR(base)             (((CTBM_Type *) (base))->OA0_SW_CLEAR)
#define CTBM_OA1_SW_CLEAR(base)             (((CTBM_Type *) (base))->OA1_SW_CLEAR)
#define CTBM_OA0_SW(base)                   (((CTBM_Type *) (base))->OA0_SW)
#define CTBM_OA1_SW(base)                   (((CTBM_Type *) (base))->OA1_SW)
#define CTBM_OA_RES0_CTRL(base)             (((CTBM_Type *) (base))->OA_RES0_CTRL)
#define CTBM_OA_RES1_CTRL(base)             (((CTBM_Type *) (base))->OA_RES1_CTRL)
#define CTBM_OA0_COMP_TRIM(base)            (((CTBM_Type *) (base))->OA0_COMP_TRIM)
#define CTBM_OA1_COMP_TRIM(base)            (((CTBM_Type *) (base))->OA1_COMP_TRIM)
#define CTBM_OA0_OFFSET_TRIM(base)          (((CTBM_Type *) (base))->OA0_OFFSET_TRIM)
#define CTBM_OA1_OFFSET_TRIM(base)          (((CTBM_Type *) (base))->OA1_OFFSET_TRIM)
#define CTBM_OA0_SLOPE_OFFSET_TRIM(base)    (((CTBM_Type *) (base))->OA0_SLOPE_OFFSET_TRIM)
#define CTBM_OA1_SLOPE_OFFSET_TRIM(base)    (((CTBM_Type *) (base))->OA1_SLOPE_OFFSET_TRIM)
#define CTBM_INTR(base)                     (((CTBM_Type *) (base))->INTR)
#define CTBM_INTR_SET(base)                 (((CTBM_Type *) (base))->INTR_SET)
#define CTBM_INTR_MASK(base)                (((CTBM_Type *) (base))->INTR_MASK)
#define CTBM_INTR_MASKED(base)              (((CTBM_Type *) (base))->INTR_MASKED)
#define CTBM_CTB_SW_HW_CTRL(base)           (((CTBM_Type *) (base))->CTB_SW_HW_CTRL)


/*******************************************************************************
*                SCB
*******************************************************************************/

#define SCB_CTRL(base)                      (((CySCB_Type*) (base))->CTRL)
#define SCB_SPI_CTRL(base)                  (((CySCB_Type*) (base))->SPI_CTRL)
#define SCB_SPI_STATUS(base)                (((CySCB_Type*) (base))->SPI_STATUS)
#define SCB_SPI_TX_CTRL(base)               (((CySCB_Type*) (base))->SPI_TX_CTRL) /* for PSOC 4100S Max only */
#define SCB_SPI_RX_CTRL(base)               (((CySCB_Type*) (base))->SPI_RX_CTRL) /* for PSOC 4100S Max only */
#define SCB_UART_CTRL(base)                 (((CySCB_Type*) (base))->UART_CTRL)
#define SCB_UART_TX_CTRL(base)              (((CySCB_Type*) (base))->UART_TX_CTRL)
#define SCB_UART_RX_CTRL(base)              (((CySCB_Type*) (base))->UART_RX_CTRL)
#define SCB_UART_RX_STATUS(base)            (((CySCB_Type*) (base))->UART_RX_STATUS)
#define SCB_UART_FLOW_CTRL(base)            (((CySCB_Type*) (base))->UART_FLOW_CTRL)
#define SCB_I2C_CTRL(base)                  (((CySCB_Type*) (base))->I2C_CTRL)
#define SCB_I2C_STATUS(base)                (((CySCB_Type*) (base))->I2C_STATUS)
#define SCB_I2C_M_CMD(base)                 (((CySCB_Type*) (base))->I2C_M_CMD)
#define SCB_I2C_S_CMD(base)                 (((CySCB_Type*) (base))->I2C_S_CMD)
#define SCB_I2C_CFG(base)                   (((CySCB_Type*) (base))->I2C_CFG)
#define SCB_I2C_STRETCH_CTRL(base)          (((CySCB_Type*) (base))->I2C_STRETCH_CTRL)   /* for PSOC 4100S Max only */
#define SCB_I2C_STRETCH_STATUS(base)        (((CySCB_Type*) (base))->I2C_STRETCH_STATUS) /* for PSOC 4100S Max only */
#define SCB_I2C_CTRL_HS(base)               (((CySCB_Type*) (base))->I2C_CTRL_HS)        /* for PSOC 4100S Max only */
#define SCB_TX_CTRL(base)                   (((CySCB_Type*) (base))->TX_CTRL)
#define SCB_TX_FIFO_CTRL(base)              (((CySCB_Type*) (base))->TX_FIFO_CTRL)
#define SCB_TX_FIFO_STATUS(base)            (((CySCB_Type*) (base))->TX_FIFO_STATUS)
#define SCB_TX_FIFO_WR(base)                (((CySCB_Type*) (base))->TX_FIFO_WR)
#define SCB_RX_CTRL(base)                   (((CySCB_Type*) (base))->RX_CTRL)
#define SCB_RX_FIFO_CTRL(base)              (((CySCB_Type*) (base))->RX_FIFO_CTRL)
#define SCB_RX_FIFO_STATUS(base)            (((CySCB_Type*) (base))->RX_FIFO_STATUS)
#define SCB_RX_MATCH(base)                  (((CySCB_Type*) (base))->RX_MATCH)
#define SCB_RX_FIFO_RD(base)                (((CySCB_Type*) (base))->RX_FIFO_RD)
#define SCB_INTR_CAUSE(base)                (((CySCB_Type*) (base))->INTR_CAUSE)
#define SCB_INTR_I2C_EC(base)               (((CySCB_Type*) (base))->INTR_I2C_EC)
#define SCB_INTR_I2C_EC_MASK(base)          (((CySCB_Type*) (base))->INTR_I2C_EC_MASK)
#define SCB_INTR_I2C_EC_MASKED(base)        (((CySCB_Type*) (base))->INTR_I2C_EC_MASKED)
#define SCB_INTR_SPI_EC(base)               (((CySCB_Type*) (base))->INTR_SPI_EC)
#define SCB_INTR_SPI_EC_MASK(base)          (((CySCB_Type*) (base))->INTR_SPI_EC_MASK)
#define SCB_INTR_SPI_EC_MASKED(base)        (((CySCB_Type*) (base))->INTR_SPI_EC_MASKED)
#define SCB_INTR_M(base)                    (((CySCB_Type*) (base))->INTR_M)
#define SCB_INTR_M_SET(base)                (((CySCB_Type*) (base))->INTR_M_SET)
#define SCB_INTR_M_MASK(base)               (((CySCB_Type*) (base))->INTR_M_MASK)
#define SCB_INTR_M_MASKED(base)             (((CySCB_Type*) (base))->INTR_M_MASKED)
#define SCB_INTR_S(base)                    (((CySCB_Type*) (base))->INTR_S)
#define SCB_INTR_S_SET(base)                (((CySCB_Type*) (base))->INTR_S_SET)
#define SCB_INTR_S_MASK(base)               (((CySCB_Type*) (base))->INTR_S_MASK)
#define SCB_INTR_S_MASKED(base)             (((CySCB_Type*) (base))->INTR_S_MASKED)
#define SCB_INTR_TX(base)                   (((CySCB_Type*) (base))->INTR_TX)
#define SCB_INTR_TX_SET(base)               (((CySCB_Type*) (base))->INTR_TX_SET)
#define SCB_INTR_TX_MASK(base)              (((CySCB_Type*) (base))->INTR_TX_MASK)
#define SCB_INTR_TX_MASKED(base)            (((CySCB_Type*) (base))->INTR_TX_MASKED)
#define SCB_INTR_RX(base)                   (((CySCB_Type*) (base))->INTR_RX)
#define SCB_INTR_RX_SET(base)               (((CySCB_Type*) (base))->INTR_RX_SET)
#define SCB_INTR_RX_MASK(base)              (((CySCB_Type*) (base))->INTR_RX_MASK)
#define SCB_INTR_RX_MASKED(base)            (((CySCB_Type*) (base))->INTR_RX_MASKED)


/*******************************************************************************
*                WCO
*******************************************************************************/

#define WCO_CONFIG                          (((WCO_Type *) WCO)->CONFIG)
#define WCO_STATUS                          (((WCO_Type *) WCO)->STATUS)
#define WCO_DPLL                            (((WCO_Type *) WCO)->DPLL)
#define WCO_TRIM                            (((WCO_Type *) WCO)->TRIM)

#define WCO_WDT_CTRLOW(base)                (((WCO_Type *) (base))->WDT_CTRLOW)
#define WCO_WDT_CTRHIGH(base)               (((WCO_Type *) (base))->WDT_CTRHIGH)
#define WCO_WDT_MATCH(base)                 (((WCO_Type *) (base))->WDT_MATCH)
#define WCO_WDT_CONFIG(base)                (((WCO_Type *) (base))->WDT_CONFIG)
#define WCO_WDT_CONTROL(base)               (((WCO_Type *) (base))->WDT_CONTROL)
#define WCO_WDT_CLKEN(base)                 (((WCO_Type *) (base))->WDT_CLKEN)


/*******************************************************************************
*                EXCO
*******************************************************************************/

#define EXCO_CLK_SELECT                          (((EXCO_Type *) EXCO)->CLK_SELECT)
#define EXCO_ECO_CONFIG                          (((EXCO_Type *) EXCO)->ECO_CONFIG)
#define EXCO_ECO_STATUS                          (((EXCO_Type *) EXCO)->ECO_STATUS)
#define EXCO_PLL_CONFIG                          (((EXCO_Type *) EXCO)->PLL_CONFIG)
#define EXCO_PLL_STATUS                          (((EXCO_Type *) EXCO)->PLL_STATUS)
#define EXCO_PLL_TEST                            (((EXCO_Type *) EXCO)->PLL_TEST)
#define EXCO_EXCO_PGM_CLK                        (((EXCO_Type *) EXCO)->EXCO_PGM_CLK)
#define EXCO_ECO_TRIM0                           (((EXCO_Type *) EXCO)->ECO_TRIM0)
#define EXCO_ECO_TRIM1                           (((EXCO_Type *) EXCO)->ECO_TRIM1)
#define EXCO_ECO_TRIM2                           (((EXCO_Type *) EXCO)->ECO_TRIM2)
#define EXCO_PLL_TRIM                            (((EXCO_Type *) EXCO)->PLL_TRIM)

#define EXCO_PLL_CONFIG                          (((EXCO_Type *) EXCO)->PLL_CONFIG)
#define EXCO_PLL_STATUS                          (((EXCO_Type *) EXCO)->PLL_STATUS)
#define EXCO_EXCO_PGM_CLK                        (((EXCO_Type *) EXCO)->EXCO_PGM_CLK)

#define EXCO_INTR                                (((EXCO_Type *) EXCO)->INTR)
#define EXCO_INTR_SET                            (((EXCO_Type *) EXCO)->INTR_SET)
#define EXCO_INTR_MASK                           (((EXCO_Type *) EXCO)->INTR_MASK)
#define EXCO_INTR_MASKED                         (((EXCO_Type *) EXCO)->INTR_MASKED)

#define EXCO_REF_CTL                             (((EXCO_Type *) EXCO)->REF_CTL)
#define EXCO_REF_LIMIT                           (((EXCO_Type *) EXCO)->REF_LIMIT)
#define EXCO_MON_CTL                             (((EXCO_Type *) EXCO)->MON_CTL)
#define EXCO_RSTDLY_CTL                          (((EXCO_Type *) EXCO)->RSTDLY_CTL)
#define EXCO_RSTDLY                              (((EXCO_Type *) EXCO)->RSTDLY)
#define EXCO_RSTDLY_COUNT_VAL                    (((EXCO_Type *) EXCO)->RSTDLY_COUNT_VAL)

/*******************************************************************************
*                CANFD
*******************************************************************************/

#define CANFD_CTL(base)                     (((CANFD_Type *)(base))->CTL)
#define CANFD_STATUS(base)                  (((CANFD_Type *)(base))->STATUS)
#define CANFD_NBTP(base, chan)              (((CANFD_Type *)(base))->CH[chan].M_TTCAN.NBTP)
#define CANFD_IR(base, chan)                (((CANFD_Type *)(base))->CH[chan].M_TTCAN.IR)
#define CANFD_IE(base, chan)                (((CANFD_Type *)(base))->CH[chan].M_TTCAN.IE)
#define CANFD_ILS(base, chan)               (((CANFD_Type *)(base))->CH[chan].M_TTCAN.ILS)
#define CANFD_ILE(base, chan)               (((CANFD_Type *)(base))->CH[chan].M_TTCAN.ILE)
#define CANFD_CCCR(base, chan)              (((CANFD_Type *)(base))->CH[chan].M_TTCAN.CCCR)
#define CANFD_SIDFC(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.SIDFC)
#define CANFD_XIDFC(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.XIDFC)
#define CANFD_XIDAM(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.XIDAM)
#define CANFD_RXESC(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXESC)
#define CANFD_RXF0C(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF0C)
#define CANFD_RXF1C(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF1C)
#define CANFD_RXFTOP_CTL(base, chan)        (((CANFD_Type *)(base))->CH[chan].RXFTOP_CTL)
#define CANFD_RXBC(base, chan)              (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXBC)
#define CANFD_TXESC(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXESC)
#define CANFD_TXEFC(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXEFC)
#define CANFD_TXBC(base, chan)              (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBC)
#define CANFD_DBTP(base, chan)              (((CANFD_Type *)(base))->CH[chan].M_TTCAN.DBTP)
#define CANFD_TDCR(base, chan)              (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TDCR)
#define CANFD_GFC(base, chan)               (((CANFD_Type *)(base))->CH[chan].M_TTCAN.GFC)
#define CANFD_TXBRP(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBRP)
#define CANFD_TXBAR(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBAR)
#define CANFD_TXBCR(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBCR)
#define CANFD_TXBTO(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBTO)
#define CANFD_TXBCF(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBCF)
#define CANFD_TXBTIE(base, chan)            (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBTIE)
#define CANFD_TXBCIE(base, chan)            (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TXBCIE)
#define CANFD_NDAT1(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.NDAT1)
#define CANFD_NDAT2(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.NDAT2)
#define CANFD_RXF0S(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF0S)
#define CANFD_RXFTOP0_DATA(base, chan)      (((CANFD_Type *)(base))->CH[chan].RXFTOP0_DATA)
#define CANFD_RXFTOP1_DATA(base, chan)      (((CANFD_Type *)(base))->CH[chan].RXFTOP1_DATA)
#define CANFD_RXF0A(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF0A)
#define CANFD_RXF1S(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF1S)
#define CANFD_RXF1A(base, chan)             (((CANFD_Type *)(base))->CH[chan].M_TTCAN.RXF1A)
#define CANFD_PSR(base, chan)               (((CANFD_Type *)(base))->CH[chan].M_TTCAN.PSR)
#define CANFD_TEST(base, chan)              (((CANFD_Type *)(base))->CH[chan].M_TTCAN.TEST)
#define CANFD_CREL(base, chan)              (((CANFD_Type *)(base))->CH[chan].M_TTCAN.CREL)

#define CY_CANFD_CHANNELS_NUM               (0x1UL)

/*******************************************************************************
*                I2S
*******************************************************************************/

#define I2S_CTL(base)                   (((I2S_Type*)(base))->CTL)
#define I2S_CMD(base)                   (((I2S_Type*)(base))->CMD)
#define I2S_CLOCK_CTL(base)             (((I2S_Type*)(base))->CLOCK_CTL)
#define I2S_TR_CTL(base)                (((I2S_Type*)(base))->TR_CTL)
#define I2S_TX_CTL(base)                (((I2S_Type*)(base))->TX_CTL)
#define I2S_TX_FIFO_CTL(base)           (((I2S_Type*)(base))->TX_FIFO_CTL)
#define I2S_TX_FIFO_STATUS(base)        (((I2S_Type*)(base))->TX_FIFO_STATUS)
#define I2S_TX_FIFO_WR(base)            (((I2S_Type*)(base))->TX_FIFO_WR)
#define I2S_TX_WATCHDOG(base)           (((I2S_Type*)(base))->TX_WATCHDOG)
#define I2S_INTR(base)                  (((I2S_Type*)(base))->INTR)
#define I2S_INTR_SET(base)              (((I2S_Type*)(base))->INTR_SET)
#define I2S_INTR_MASK(base)             (((I2S_Type*)(base))->INTR_MASK)
#define I2S_INTR_MASKED(base)           (((I2S_Type*)(base))->INTR_MASKED)

/*******************************************************************************
*                USBFS Device
*******************************************************************************/

#define USBFS_DEV_CR0(base)             (((USBFS_Type *)(base))->CR0)
#define USBFS_DEV_CR1(base)             (((USBFS_Type *)(base))->CR1)
#define USBFS_DEV_USBIO_CR0(base)       (((USBFS_Type *)(base))->USBIO_CR0)
#define USBFS_DEV_USBIO_CR2(base)       (((USBFS_Type *)(base))->USBIO_CR2)
#define USBFS_DEV_USBIO_CR1(base)       (((USBFS_Type *)(base))->USBIO_CR1)
#define USBFS_DEV_USB_CLK_EN(base)      (((USBFS_Type *)(base))->USB_CLK_EN)
#define USBFS_DEV_BUS_RST_CNT(base)     (((USBFS_Type *)(base))->BUS_RST_CNT)
#define USBFS_DEV_OSCLK_DR0(base)       (((USBFS_Type *)(base))->EP_TYPE)
#define USBFS_DEV_OSCLK_DR1(base)       (((USBFS_Type *)(base))->OSCLK_DR0)
#define USBFS_DEV_SOF0(base)            (((USBFS_Type *)(base))->SOF0)
#define USBFS_DEV_SOF1(base)            (((USBFS_Type *)(base))->SOF1)
#define USBFS_DEV_SOF16(base)           (((USBFS_Type *)(base))->OSCLK_DR1)
#define USBFS_DEV_OSCLK_DR16(base)      (((USBFS_Type *)(base))->SOF16)
#define USBFS_DEV_ARB_CFG(base)         (((USBFS_Type *)(base))->ARB_CFG)
#define USBFS_DEV_DYN_RECONFIG(base)    (((USBFS_Type *)(base))->DYN_RECONFIG)
#define USBFS_DEV_BUF_SIZE(base)        (((USBFS_Type *)(base))->BUF_SIZE)
#define USBFS_DEV_EP_ACTIVE(base)       (((USBFS_Type *)(base))->EP_ACTIVE)
#define USBFS_DEV_EP_TYPE(base)         (((USBFS_Type *)(base))->EP_TYPE)
#define USBFS_DEV_CWA16(base)           (((USBFS_Type *)(base))->CWA16)
#define USBFS_DEV_CWA(base)             (((USBFS_Type *)(base))->CWA)
#define USBFS_DEV_CWA_MSB(base)         (((USBFS_Type *)(base))->CWA_MSB)
#define USBFS_DEV_DMA_THRES16(base)     (((USBFS_Type *)(base))->DMA_THRES16)
#define USBFS_DEV_DMA_THRES(base)       (((USBFS_Type *)(base))->DMA_THRES)
#define USBFS_DEV_DMA_THRES_MSB(base)   (((USBFS_Type *)(base))->DMA_THRES_MSB)

#define USBFS_DEV_SIE_EP_INT_EN(base)   (((USBFS_Type *)(base))->SIE_EP_INT_EN)
#define USBFS_DEV_SIE_EP_INT_SR(base)   (((USBFS_Type *)(base))->SIE_EP_INT_SR)
#define USBFS_DEV_ARB_INT_EN(base)      (((USBFS_Type *)(base))->ARB_INT_EN)
#define USBFS_DEV_ARB_INT_SR(base)      (((USBFS_Type *)(base))->ARB_INT_SR)

#define USBFS_DEV_EP0_CR(base)          (((USBFS_Type *)(base))->EP0_CR)
#define USBFS_DEV_EP0_CNT(base)         (((USBFS_Type *)(base))->EP0_CNT)
#define USBFS_DEV_EP0_DR(base, idx)     (((USBFS_Type *)(base))->EP0_DR[idx])

#define USBFS_DEV_MEM_DATA(base, idx)   (((USBFS_Type *)(base))->MEM[idx])

#define USBFS_DEV_SIE_REGS_BASE        (0x30U)
#define USBFS_DEV_SIE_REGS_SIZE        (0x40U)
#define USBFS_DEV_SIE_EP_CNT0_OFFSET   (0x00U)
#define USBFS_DEV_SIE_EP_CNT1_OFFSET   (0x04U)
#define USBFS_DEV_SIE_EP_CR0_OFFSET    (0x08U)
#define USBFS_DEV_SIE_REGS(base, endpoint) ((uint32_t)(base) + USBFS_DEV_SIE_REGS_BASE + ((endpoint) * USBFS_DEV_SIE_REGS_SIZE))

#define USBFS_DEV_SIE_EP_CNT0(base, endpoint)  (*(volatile uint32_t *) (USBFS_DEV_SIE_REGS(base, endpoint) + \
                                                                        USBFS_DEV_SIE_EP_CNT0_OFFSET))
#define USBFS_DEV_SIE_EP_CNT1(base, endpoint)  (*(volatile uint32_t *) (USBFS_DEV_SIE_REGS(base, endpoint) + \
                                                                        USBFS_DEV_SIE_EP_CNT1_OFFSET))
#define USBFS_DEV_SIE_EP_CR0(base, endpoint)   (*(volatile uint32_t *) (USBFS_DEV_SIE_REGS(base, endpoint) + \
                                                                        USBFS_DEV_SIE_EP_CR0_OFFSET))

#define USBFS_DEV_ARB_REGS_BASE         (0x200U)
#define USBFS_DEV_ARB_REGS_SIZE         (0x40U)
#define USBFS_DEV_ARB_EP_CFG_OFFSET     (0x00U)
#define USBFS_DEV_ARB_EP_INT_EN_OFFSET  (0x04U)
#define USBFS_DEV_ARB_EP_SR_OFFSET      (0x08U)
#define USBFS_DEV_ARB_RW_WA_OFFSET      (0x10U)
#define USBFS_DEV_ARB_RW_WA_MSB_OFFSET  (0x14U)
#define USBFS_DEV_ARB_RW_RA_OFFSET      (0x18U)
#define USBFS_DEV_ARB_RW_RA_MSB_OFFSET  (0x1CU)
#define USBFS_DEV_ARB_RW_DR_OFFSET      (0x20U)
#define USBFS_DEV_ARB_REGS(base, endpoint) ((uint32_t)(base) + USBFS_DEV_ARB_REGS_BASE + ((endpoint) * USBFS_DEV_ARB_REGS_SIZE))

#define USBFS_DEV_ARB_EP_CFG(base, endpoint)       (*(volatile uint32_t *) (USBFS_DEV_ARB_REGS(base, endpoint) + \
                                                                            USBFS_DEV_ARB_EP_CFG_OFFSET))
#define USBFS_DEV_ARB_EP_INT_EN(base, endpoint)    (*(volatile uint32_t *) (USBFS_DEV_ARB_REGS(base, endpoint) + \
                                                                            USBFS_DEV_ARB_EP_INT_EN_OFFSET))
#define USBFS_DEV_ARB_EP_SR(base, endpoint)        (*(volatile uint32_t *) (USBFS_DEV_ARB_REGS(base, endpoint) + \
                                                                            USBFS_DEV_ARB_EP_SR_OFFSET))
#define USBFS_DEV_ARB_RW_WA(base, endpoint)        (*(volatile uint32_t *) (USBFS_DEV_ARB_REGS(base, endpoint) + \
                                                                            USBFS_DEV_ARB_RW_WA_OFFSET))
#define USBFS_DEV_ARB_RW_WA_MSB(base, endpoint)    (*(volatile uint32_t *) (USBFS_DEV_ARB_REGS(base, endpoint) + \
                                                                            USBFS_DEV_ARB_RW_WA_MSB_OFFSET))
#define USBFS_DEV_ARB_RW_RA(base, endpoint)        (*(volatile uint32_t *) (USBFS_DEV_ARB_REGS(base, endpoint) + \
                                                                            USBFS_DEV_ARB_RW_RA_OFFSET))
#define USBFS_DEV_ARB_RW_RA_MSB(base, endpoint)    (*(volatile uint32_t *) (USBFS_DEV_ARB_REGS(base, endpoint) + \
                                                                            USBFS_DEV_ARB_RW_RA_MSB_OFFSET))
#define USBFS_DEV_ARB_RW_DR(base, endpoint)        (*(volatile uint32_t *) (USBFS_DEV_ARB_REGS(base, endpoint) + \
                                                                            USBFS_DEV_ARB_RW_DR_OFFSET))

#define USBFS_DEV_ARB_REGS16_BASE       (0x1210U)
#define USBFS_DEV_ARB_REGS16_SIZE       (0x40U)
#define USBFS_DEV_ARB_RW_WA16_OFFSET    (0x00U)
#define USBFS_DEV_ARB_RW_RA16_OFFSET    (0x08U)
#define USBFS_DEV_ARB_RW_DR16_OFFSET    (0x10U)
#define USBFS_DEV_ARB_REGS_16(base, endpoint) ((uint32_t)(base) + USBFS_DEV_ARB_REGS16_BASE + ((endpoint) * USBFS_DEV_ARB_REGS16_SIZE))

#define USBFS_DEV_ARB_RW_WA16(base, endpoint)      (*(volatile uint32_t *) (USBFS_DEV_ARB_REGS_16(base, endpoint) + \
                                                                            USBFS_DEV_ARB_RW_WA16_OFFSET))
#define USBFS_DEV_ARB_RW_RA16(base, endpoint)      (*(volatile uint32_t *) (USBFS_DEV_ARB_REGS_16(base, endpoint) + \
                                                                            USBFS_DEV_ARB_RW_RA16_OFFSET))
#define USBFS_DEV_ARB_RW_DR16(base, endpoint)      (*(volatile uint32_t *) (USBFS_DEV_ARB_REGS_16(base, endpoint) + \
                                                                            USBFS_DEV_ARB_RW_DR16_OFFSET))
#define USBIO_TRIM_REG_EN_VALUE         (0x00000028)
#define USBIO_TRIM_REG_DIS_VALUE        (0x00000000)

/*
 * This bit controls the operation of the internal USB regulator. For applications
 * with supply voltages in the 5V range this bit is set high to enable the
 * internal regulator. For device supply voltage in the 3.3V range this bit
 * is cleared to connect the transceiver directly to the supply.
 */
#define USBDEV_CR1_REG_ENABLE                               (1u << 0) /* <0:0> R:RW:0: */


/*
 * This bit is set to turn on the automatic frequency locking of the internal
 * oscillator to USB traffic.  Unless an external clock is being provided
 * this bit should remain set for proper USB operation.
 */
#define USBDEV_CR1_ENABLE_LOCK                              (1u << 1) /* <1:1> R:RW:0: */



#define USBFS_DEV_POWER_CTL(base)       (((USBFS_Type *)(base))->BCD.POWER_CTRL)
#define USBFS_DEV_USBIO_CTL(base)       (((USBFS_Type *)(base))->BCD.USBIO_CTRL)
#define USBFS_DEV_FLOW_CTL(base)        (((USBFS_Type *)(base))->BCD.FLOW_CTRL)
#define USBFS_DEV_LPM_CTL(base)         (((USBFS_Type *)(base))->BCD.LPM_CTRL)
#define USBFS_DEV_LPM_STAT(base)        (((USBFS_Type const *)(base))->BCD.LPM_STAT)
#define USBFS_DEV_INTR_SIE(base)        (((USBFS_Type *)(base))->BCD.INTR_SIE)
#define USBFS_DEV_INTR_SIE_SET(base)    (((USBFS_Type *)(base))->BCD.INTR_SIE_SET)
#define USBFS_DEV_INTR_SIE_MASK(base)   (((USBFS_Type *)(base))->BCD.INTR_SIE_MASK)
#define USBFS_DEV_INTR_SIE_MASKED(base) (((USBFS_Type *)(base))->BCD.INTR_SIE_MASKED)
#define USBFS_DEV_INTR_LVL_SEL(base)    (((USBFS_Type *)(base))->BCD.INTR_LVL_SEL)
#define USBFS_DEV_INTR_CAUSE_HI(base)   (((USBFS_Type const *)(base))->BCD.INTR_CAUSE_HI)
#define USBFS_DEV_INTR_CAUSE_MED(base)  (((USBFS_Type const *)(base))->BCD.INTR_CAUSE_MED)
#define USBFS_DEV_INTR_CAUSE_LO(base)   (((USBFS_Type const *)(base))->BCD.INTR_CAUSE_LO)
#define USBFS_DEV_DFT_CTL(base)         (((USBFS_Type *)(base))->BCD.DFT_CTRL)
#define USBFS_DEV_USBIO_TRIM(base)      (((USBFS_Type *)(base))->BCD.USBIO_TRIM)

/*******************************************************************************
*                PASS
*******************************************************************************/
#define PASS_INTR_CAUSE(base)                 (((PASS_Type *) (base))->INTR_CAUSE)
#define PASS_DFT_CTRL(base)                   (((PASS_Type *) (base))->DFT_CTRL)
#define PASS_PASS_CTRL(base)                  (((PASS_Type *) (base))->PASS_CTRL)
#define PASS_DSAB_TRIM(base)                  (((PASS_Type *) (base))->DSAB_TRIM)

#define PASS_DSAB_DSAB_CTRL(base)             (((PASS_Type *) (base))->DSAB.DSAB_CTRL)
#define PASS_DSAB_DSAB_DFT(base)              (((PASS_Type *) (base))->DSAB.DSAB_DFT)

/*******************************************************************************
*                CRYPTO
*******************************************************************************/

/* Registers */
#define REG_CRYPTO_CTL(base)               (((CRYPTO_Type*)(base))->CTL)
#define REG_CRYPTO_STATUS(base)            (((CRYPTO_Type*)(base))->STATUS)
#define REG_CRYPTO_CMD(base)               (((CRYPTO_Type*)(base))->CMD)
#define REG_CRYPTO_SRC_CTL0(base)          (((CRYPTO_Type*)(base))->SRC_CTL0)
#define REG_CRYPTO_SRC_CTL1(base)          (((CRYPTO_Type*)(base))->SRC_CTL1)
#define REG_CRYPTO_DST_CTL0(base)          (((CRYPTO_Type*)(base))->DST_CTL0)
#define REG_CRYPTO_DST_CTL1(base)          (((CRYPTO_Type*)(base))->DST_CTL1)
#define REG_CRYPTO_AES_CTL(base)           (((CRYPTO_Type*)(base))->AES_CTL)
#define REG_CRYPTO_PR_CTL(base)            (((CRYPTO_Type*)(base))->PR_CTL)
#define REG_CRYPTO_PR_CMD(base)            (((CRYPTO_Type*)(base))->PR_CMD)
#define REG_CRYPTO_PR_LFSR_CTL0(base)      (((CRYPTO_Type*)(base))->PR_LFSR_CTL0)
#define REG_CRYPTO_PR_LFSR_CTL1(base)      (((CRYPTO_Type*)(base))->PR_LFSR_CTL1)
#define REG_CRYPTO_PR_LFSR_CTL2(base)      (((CRYPTO_Type*)(base))->PR_LFSR_CTL2)
#define REG_CRYPTO_PR_RESULT(base)         (((CRYPTO_Type*)(base))->PR_RESULT)
#define REG_CRYPTO_TR_CTL0(base)           (((CRYPTO_Type*)(base))->TR_CTL0)
#define REG_CRYPTO_TR_CTL1(base)           (((CRYPTO_Type*)(base))->TR_CTL1)
#define REG_CRYPTO_TR_RESULT0(base)        (((CRYPTO_Type*)(base))->TR_RESULT0)
#define REG_CRYPTO_TR_RESULT1(base)        (((CRYPTO_Type*)(base))->TR_RESULT1)
#define REG_CRYPTO_TR_CMD(base)            (((CRYPTO_Type*)(base))->TR_CMD)
#define REG_CRYPTO_TR_GARO_CTL(base)       (((CRYPTO_Type*)(base))->TR_GARO_CTL)
#define REG_CRYPTO_TR_FIRO_CTL(base)       (((CRYPTO_Type*)(base))->TR_FIRO_CTL)
#define REG_CRYPTO_TR_MON_CTL(base)        (((CRYPTO_Type*)(base))->TR_MON_CTL)
#define REG_CRYPTO_TR_MON_CMD(base)        (((CRYPTO_Type*)(base))->TR_MON_CMD)
#define REG_CRYPTO_TR_MON_RC_CTL(base)     (((CRYPTO_Type*)(base))->TR_MON_RC_CTL)
#define REG_CRYPTO_TR_MON_AP_CTL(base)     (((CRYPTO_Type*)(base))->TR_MON_AP_CTL)
#define REG_CRYPTO_TR_MON_RC_STATUS0(base) (((CRYPTO_Type*)(base))->TR_MON_RC_STATUS0)
#define REG_CRYPTO_TR_MON_RC_STATUS1(base) (((CRYPTO_Type*)(base))->TR_MON_RC_STATUS1)
#define REG_CRYPTO_TR_MON_AP_STATUS0(base) (((CRYPTO_Type*)(base))->TR_MON_AP_STATUS0)
#define REG_CRYPTO_TR_MON_AP_STATUS1(base) (((CRYPTO_Type*)(base))->TR_MON_AP_STATUS1)
#define REG_CRYPTO_SHA_CTL(base)           (((CRYPTO_Type*)(base))->SHA_CTL)
#define REG_CRYPTO_CRC_DATA_CTL0(base)     (((CRYPTO_Type*)(base))->CRC_DATA_CTL0)
#define REG_CRYPTO_CRC_DATA_CTL1(base)     (((CRYPTO_Type*)(base))->CRC_DATA_CTL1)
#define REG_CRYPTO_CRC_POL_CTL(base)       (((CRYPTO_Type*)(base))->CRC_POL_CTL)
#define REG_CRYPTO_CRC_LFSR_CTL(base)      (((CRYPTO_Type*)(base))->CRC_LFSR_CTL)
#define REG_CRYPTO_CRC_REM_CTL0(base)      (((CRYPTO_Type*)(base))->CRC_REM_CTL0)
#define REG_CRYPTO_CRC_REM_CTL1(base)      (((CRYPTO_Type*)(base))->CRC_REM_CTL1)
#define REG_CRYPTO_CRC_REM(base)           (((CRYPTO_Type*)(base))->CRC_REM)
#define REG_CRYPTO_INTR(base)              (((CRYPTO_Type*)(base))->INTR)
#define REG_CRYPTO_INTR_SET(base)          (((CRYPTO_Type*)(base))->INTR_SET)
#define REG_CRYPTO_INTR_MASK(base)         (((CRYPTO_Type*)(base))->INTR_MASK)
#define REG_CRYPTO_INTR_MASKED(base)       (((CRYPTO_Type*)(base))->INTR_MASKED)
#define REG_CRYPTO_MEM_BUFF(base)          (((CRYPTO_Type*)(base))->MEM_BUFF)


#define REG_CRYPTOLITE_CTL(base)                    (((CRYPTOLITE_Type*)(base))->CTL)
#define REG_CRYPTOLITE_STATUS(base)                 (((CRYPTOLITE_Type*)(base))->STATUS)
#define REG_CRYPTOLITE_ECC_CTL(base)                (((CRYPTOLITE_Type*)(base))->ECC_CTL)
#define REG_CRYPTOLITE_AES_DESCR(base)              (((CRYPTOLITE_Type*)(base))->AES_DESCR)
#define REG_CRYPTOLITE_VU_DESCR(base)               (((CRYPTOLITE_Type*)(base))->VU_DESCR)
#define REG_CRYPTOLITE_SHA_DESCR(base)              (((CRYPTOLITE_Type*)(base))->SHA_DESCR)
#define REG_CRYPTOLITE_INTR_ERROR(base)             (((CRYPTOLITE_Type*)(base))->INTR_ERROR)
#define REG_CRYPTOLITE_INTR_ERROR_SET(base)         (((CRYPTOLITE_Type*)(base))->INTR_ERROR_SET)
#define REG_CRYPTOLITE_INTR_ERROR_MASK(base)        (((CRYPTOLITE_Type*)(base))->INTR_ERROR_MASK)
#define REG_CRYPTOLITE_INTR_ERROR_MASKED(base)      (((CRYPTOLITE_Type*)(base))->INTR_ERROR_MASKED)
#define REG_CRYPTOLITE_TRNG_CTL0(base)              (((CRYPTOLITE_Type*)(base))->TRNG_CTL0)
#define REG_CRYPTOLITE_TRNG_CTL1(base)              (((CRYPTOLITE_Type*)(base))->TRNG_CTL1)
#define REG_CRYPTOLITE_TRNG_STATUS(base)            (((CRYPTOLITE_Type*)(base))->TRNG_STATUS)
#define REG_CRYPTOLITE_TRNG_RESULT(base)            (((CRYPTOLITE_Type*)(base))->TRNG_RESULT)
#define REG_CRYPTOLITE_TRNG_GARO_CTL(base)          (((CRYPTOLITE_Type*)(base))->TRNG_GARO_CTL)
#define REG_CRYPTOLITE_TRNG_FIRO_CTL(base)          (((CRYPTOLITE_Type*)(base))->TRNG_FIRO_CTL)
#define REG_CRYPTOLITE_TRNG_MON_CTL(base)           (((CRYPTOLITE_Type*)(base))->TRNG_MON_CTL)
#define REG_CRYPTOLITE_TRNG_MON_RC_CTL(base)        (((CRYPTOLITE_Type*)(base))->TRNG_MON_RC_CTL)
#define REG_CRYPTOLITE_TRNG_MON_RC_STATUS0(base)    (((CRYPTOLITE_Type*)(base))->TRNG_MON_RC_STATUS0)
#define REG_CRYPTOLITE_TRNG_MON_RC_STATUS1(base)    (((CRYPTOLITE_Type*)(base))->TRNG_MON_RC_STATUS1)
#define REG_CRYPTOLITE_TRNG_MON_AP_CTL(base)        (((CRYPTOLITE_Type*)(base))->TRNG_MON_AP_CTL)
#define REG_CRYPTOLITE_TRNG_MON_AP_STATUS0(base)    (((CRYPTOLITE_Type*)(base))->TRNG_MON_AP_STATUS0)
#define REG_CRYPTOLITE_TRNG_MON_AP_STATUS1(base)    (((CRYPTOLITE_Type*)(base))->TRNG_MON_AP_STATUS1)
#define REG_CRYPTOLITE_INTR_TRNG(base)              (((CRYPTOLITE_Type*)(base))->INTR_TRNG)
#define REG_CRYPTOLITE_INTR_TRNG_SET(base)          (((CRYPTOLITE_Type*)(base))->INTR_TRNG_SET)
#define REG_CRYPTOLITE_INTR_TRNG_MASK(base)         (((CRYPTOLITE_Type*)(base))->INTR_TRNG_MASK)
#define REG_CRYPTOLITE_INTR_TRNG_MASKED(base)       (((CRYPTOLITE_Type*)(base))->INTR_TRNG_MASKED)

/*******************************************************************************
*                FAULT
*******************************************************************************/

#define FAULT_CTL(base)                         (((FAULT_STRUCT_Type *)(base))->CTL)
#define FAULT_STATUS(base)                      (((FAULT_STRUCT_Type *)(base))->STATUS)
#define FAULT_DATA(base)                        (((FAULT_STRUCT_Type *)(base))->DATA)
#define FAULT_PENDING0(base)                    (((FAULT_STRUCT_Type *)(base))->PENDING0)
#define FAULT_MASK0(base)                       (((FAULT_STRUCT_Type *)(base))->MASK0)
#define FAULT_INTR(base)                        (((FAULT_STRUCT_Type *)(base))->INTR)
#define FAULT_INTR_SET(base)                    (((FAULT_STRUCT_Type *)(base))->INTR_SET)
#define FAULT_INTR_MASK(base)                   (((FAULT_STRUCT_Type *)(base))->INTR_MASK)
#define FAULT_INTR_MASKED(base)                 (((FAULT_STRUCT_Type *)(base))->INTR_MASKED)

/*******************************************************************************
*                LIN
*******************************************************************************/
#if defined (CY_IP_MXLIN)
#define LIN_CH_CTL0(base)                       (((LIN_CH_Type *)(base))->CTL0)
#define LIN_CH_CTL1(base)                       (((LIN_CH_Type *)(base))->CTL1)
#define LIN_CH_STATUS(base)                     (((LIN_CH_Type *)(base))->STATUS)
#define LIN_CH_CMD(base)                        (((LIN_CH_Type *)(base))->CMD)
#define LIN_CH_TX_RX_STATUS(base)               (((LIN_CH_Type *)(base))->TX_RX_STATUS)
#define LIN_CH_PID_CHECKSUM(base)               (((LIN_CH_Type *)(base))->PID_CHECKSUM)
#define LIN_CH_DATA0(base)                      (((LIN_CH_Type *)(base))->DATA0)
#define LIN_CH_DATA1(base)                      (((LIN_CH_Type *)(base))->DATA1)
#define LIN_CH_INTR(base)                       (((LIN_CH_Type *)(base))->INTR)
#define LIN_CH_INTR_SET(base)                   (((LIN_CH_Type *)(base))->INTR_SET)
#define LIN_CH_INTR_MASK(base)                  (((LIN_CH_Type *)(base))->INTR_MASK)
#define LIN_CH_INTR_MASKED(base)                (((LIN_CH_Type *)(base))->INTR_MASKED)

#define LIN_ERROR_CTL(base)                     (((LIN_Type *)(base))->ERROR_CTL)
#define LIN_TEST_CTL(base)                      (((LIN_Type *)(base))->TEST_CTL)
#endif /* CY_IP_MXLIN */

#endif /* CY_DEVICE_H_ */

/* [] END OF FILE */
