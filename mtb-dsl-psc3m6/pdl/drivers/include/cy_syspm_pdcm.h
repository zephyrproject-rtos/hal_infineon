/***************************************************************************//**
* \file cy_syspm_pdcm.h
* \version 5.150
*
* \brief
* This file provides the header for PDCM driver, where the APIs are used by Syspm driver and BTSS driver.
*
********************************************************************************
* \copyright
* Copyright(c) 2016-2026 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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


/**
* \addtogroup group_syspm_pdcm             PDCM (Power Dependency Control Matrix)
* \{
* PDCM driver provides APIs for controlling the Power Dependency Control Matrix
* across Power Domains
*
* The functions and other declarations used in this driver are in cy_syspm_pdcm.h.
*
* \section group_syspm_pdcm_more_information More Information
*
* For more information on the PDCM, refer to
* the technical reference manual (TRM).
*
* \section group_syspm_pdcm_MISRA MISRA-C Compliance
* The PDCM driver does not have any specific deviations.
*
* \defgroup group_syspm_pdcm_macros Macros
* \defgroup group_syspm_pdcm_functions Functions
* \defgroup group_syspm_pdcm_enums Enumerated Types
*/
/** \} group_syspm_pdcm */

#ifndef CY_PD_PDCM_H
#define CY_PD_PDCM_H

#include "cy_device.h"

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)

#include <stdint.h>
#include "cy_syslib.h"
#include "cy_syspm.h"

/*******************************************************************************
*       Enumerated Types
*******************************************************************************/

/**
* \addtogroup group_syspm_pdcm_enums
* \{
*/

/** Defines ID's for each of the PDCM's */
#if defined (CY_IP_MXS22SRSS)


#if (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1) && defined(CY_DEVICE_PSB3)
typedef enum
{
    CY_PD_PDCM_MAIN             = 0x00UL, /**< For MAIN/SRSS Power domain */
    CY_PD_PDCM_SYSCPUSS         = 0x01UL, /**< For SYSCPUSS Power domain */
    CY_PD_PDCM_RRAM             = 0x02UL, /**< For RRAM Power domain */
    CY_PD_PDCM_RRAMC            = 0x03UL, /**< For RRAMC Power domain */
    CY_PD_PDCM_CPUSS            = 0x04UL, /**< For CPUSS Power domain */
    CY_PD_PDCM_BTSS_TOP         = 0x05UL, /**< For BTSS_TOP Power domain */
    CY_PD_PDCM_BTSS_DPLL        = 0x06UL, /**< For BTSS_DPLL Power domain */
    CY_PD_PDCM_BTSS_XTAL_PWR    = 0x07UL, /**< For BTSS_XTAL_PWR Power domain */
} cy_pd_pdcm_id_t;


#else
#if defined(CY_DEVICE_ACW)
typedef enum
{
    CY_PD_PDCM_MAIN       = 0x00UL, /**< For MAIN/SRSS Power domain */
    CY_PD_PDCM_SYSCPUSS   = 0x01UL, /**< For SYSCPUSS Power domain */
    CY_PD_PDCM_RRAM       = 0x02UL, /**< For RRAM Power domain */
    CY_PD_PDCM_BTSS       = 0x03UL, /**< For BTSS Power domain */
    CY_PD_PDCM_WIFI       = 0x04UL, /**< For WIFI Power domain */
    CY_PD_PDCM_RRAMC      = 0x05UL, /**< For RRAMC Power domain */
    CY_PD_PDCM_W2R_WAKE   = 0x06UL, /**< For W2R_WAKE Power domain */
    CY_PD_PDCM_CPUSS      = 0x07UL, /**< For CPUSS Power domain */
    CY_PD_PDCM_W2C_WAKE   = 0x08UL, /**< For W2C_WAKE Power domain */
    CY_PD_PDCM_B2R_WAKE   = 0x09UL, /**< For B2R_WAKE Power domain */
    CY_PD_PDCM_WIFISS_TOP = 0x0AUL, /**< For WIFISS_TOP Power domain */
    CY_PD_PDCM_WIFISS_CORE= 0x0BUL, /**< For WIFISS_CORE Power domain */
    CY_PD_PDCM_BTSS_TOP   = 0x0CUL, /**< For BTSS_TOP Power domain */
    CY_PD_PDCM_BTSS_DPLL  = 0x0DUL, /**< For BTSS_DPLL Power domain */
} cy_pd_pdcm_id_t;
#else

typedef enum
{
#if (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR >= 2) /** Should be replaced by device specific macro */
    CY_PD_PDCM_PD_SRSS      = 0x00UL, /**< For SRSS Power domain */
    CY_PD_PDCM_PD_CORESS    = 0x01UL, /**< For CORESS Power domain */
    CY_PD_PDCM_PD_MEM       = 0x02UL, /**< For MEM Power domain */
    CY_PD_PDCM_PD_APPSS     = 0x03UL, /**< For APPSS Power domain */
    CY_PD_PDCM_PD_M0SEC     = 0x04UL, /**< For M0SEC Power domain */
    CY_PD_PDCM_PD_LPPASS    = 0x05UL, /**< For LPPASS Power domain */
    CY_PD_PDCM_SYSCPUSS     = 0x06UL, /**< For SYSCPUSS Power domain */
    CY_PD_PDCM_APPSS        = 0x07UL, /**< For APPSS Power domain */
    CY_PD_PDCM_PD_APPCPU    = 0x08UL, /**< For APPCPU Power domain */
    CY_PD_PDCM_PD_U85       = 0x09UL, /**< For U85 Power domain */
    CY_PD_PDCM_PD_GFXSS     = 0x0AUL, /**< For GFXSS Power domain */
    CY_PD_PDCM_PD_ISP       = 0x0BUL, /**< For ISP Power domain */
    CY_PD_PDCM_PD_VDEC      = 0x0CUL, /**< For VDEC Power domain */
    CY_PD_PDCM_PD_VENC      = 0x0DUL, /**< For VENC Power domain */
#else
    CY_PD_PDCM_MAIN      = 0x00UL, /**< For MAIN/PD0 Power domain */
    CY_PD_PDCM_PD1       = 0x01UL, /**< For PD1 Power domain */
    CY_PD_PDCM_SRAM0     = 0x02UL, /**< For SRAM0 Power domain */
    CY_PD_PDCM_SRAM1     = 0x03UL, /**< For SRAM1 Power domain */
    CY_PD_PDCM_SYSCPU    = 0x04UL, /**< For SYSCPU Power domain */
    CY_PD_PDCM_APPCPUSS  = 0x05UL, /**< For APPCPUSS Power domain */
    CY_PD_PDCM_APPCPU    = 0x06UL, /**< For APPCPU Power domain */
    CY_PD_PDCM_SOCMEM    = 0x07UL, /**< For SOCMEM Power domain */
    CY_PD_PDCM_U55       = 0x08UL, /**< For U55 Power domain */
#endif
} cy_pd_pdcm_id_t;
#endif
#endif
#else
typedef enum
{
    CY_PD_PDCM_MAIN      = 0x00UL, /**< For MAIN Power domain */
    CY_PD_PDCM_CPUSS     = 0x01UL, /**< For CPUSS Power domain */
    CY_PD_PDCM_SRAM      = 0x02UL, /**< For SRAM Power domain */
#if defined (CY_PPU_SRAM1_BASE)
    CY_PD_PDCM_SRAM1      = 0x03UL, /**< For SRAM1 Power domain */
#elif defined (BTSS)
    CY_PD_PDCM_BTSS      = 0x03UL, /**< For BTSS Power domain */
#endif
#if defined (CY_IP_MXS40PPSS)
    CY_PD_PDCM_PPCA_SRAM0 = 0x04UL, /**< For PPCA SRAM0 Power domain */
    CY_PD_PDCM_PPCA_SRAM1 = 0x05UL, /**< For PPCA SRAM1 Power domain */
    CY_PD_PDCM_PPCA_SRAM2 = 0x06UL, /**< For PPCA SRAM2 Power domain */
    CY_PD_PDCM_PPCA_SRAM3 = 0x07UL, /**< For PPCA SRAM3 Power domain */
    CY_PD_PDCM_PPCA_SRAM4 = 0x08UL, /**< For PPCA SRAM4 Power domain */
#endif /* #if defined (CY_IP_MXS40PPSS) */

} cy_pd_pdcm_id_t;
#endif
/** Defines Dependency Matrix for PD's */
typedef enum
{
    CY_PD_PDCM_DEP_NONE         = 0x00UL, /**< No Direct Dependency */
    CY_PD_PDCM_DEP_DIRECT       = 0x01UL, /**< Direct Dependency */
    CY_PD_PDCM_DEP_CONFIG       = 0x02UL, /**< Configurable Dependency */
} cy_pd_pdcm_dep_t;

#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION >= 2)

/** Power Domain Resources
* \note
* Power Mode[2],Power Mode[1],Power Mode[0]
* 000: No power mode request. DEEPSLEEP settings are acceptable.
* 001: ULP power mode required.
* 01X: MF power mode required.
* 1XX: LP power mode required.
*/
typedef enum
{
    CY_SYSPM_PD_RESOURCE_DPLL_0                    = ((uint32)1 << 0),  /**< DPLL0 */
    CY_SYSPM_PD_RESOURCE_DPLL_1                    = ((uint32)1 << 1),  /**< DPLL1 */
    CY_SYSPM_PD_RESOURCE_DPLL_2                    = ((uint32)1 << 2),  /**< DPLL2 */
    CY_SYSPM_PD_RESOURCE_DPLL_3                    = ((uint32)1 << 3),  /**< DPLL3 */
    CY_SYSPM_PD_RESOURCE_DPLL_4                    = ((uint32)1 << 4),  /**< DPLL4 */
    CY_SYSPM_PD_RESOURCE_DPLL_5                    = ((uint32)1 << 5),  /**< DPLL5 */
    CY_SYSPM_PD_RESOURCE_DPLL_6                    = ((uint32)1 << 6),  /**< DPLL6 */
    CY_SYSPM_PD_RESOURCE_DPLL_7                    = ((uint32)1 << 7),  /**< DPLL7 */
    CY_SYSPM_PD_RESOURCE_DPLL_8                    = ((uint32)1 << 8),  /**< DPLL8 */
    CY_SYSPM_PD_RESOURCE_DPLL_9                    = ((uint32)1 << 9),  /**< DPLL9 */
    CY_SYSPM_PD_RESOURCE_DPLL_10                   = ((uint32)1 << 10),  /**< DPLL10 */
    CY_SYSPM_PD_RESOURCE_DPLL_11                   = ((uint32)1 << 11),  /**< DPLL11 */
    CY_SYSPM_PD_RESOURCE_DPLL_12                   = ((uint32)1 << 12),  /**< DPLL12 */
    CY_SYSPM_PD_RESOURCE_DPLL_13                   = ((uint32)1 << 13),  /**< DPLL13 */
    CY_SYSPM_PD_RESOURCE_DPLL_14                   = ((uint32)1 << 14),  /**< DPLL14 */
    CY_SYSPM_PD_RESOURCE_DPLL_15                   = ((uint32)1 << 15),  /**< DPLL15 */
    CY_SYSPM_PD_RESOURCE_ECO                       = ((uint32)1 << 16),  /**< ECO */
    CY_SYSPM_PD_RESOURCE_IMO                       = ((uint32)1 << 17),  /**< IMO */
    CY_SYSPM_PD_RESOURCE_IHO                       = ((uint32)1 << 18),  /**< IHO */
    CY_SYSPM_PD_RESOURCE_IREF                      = ((uint32)1 << 19),  /**< IREF */
    CY_SYSPM_PD_RESOURCE_VREFBUF                   = ((uint32)1 << 20),  /**< VREFBUF */
    CY_SYSPM_PD_RESOURCE_BOOTROW                   = ((uint32)1 << 21),  /**< BOOTROW */
    CY_SYSPM_PD_RESOURCE_OVD                       = ((uint32)1 << 22),  /**< OVD */
    CY_SYSPM_PD_RESOURCE_ECO_WAIT_FOR_LOCK         = ((uint32)1 << 24),  /**< ECO Wait For Lock */
    CY_SYSPM_PD_RESOURCE_DPLL_WAIT_FOR_LOCK        = ((uint32)1 << 25),  /**< DPLL Wait For Lock */
    CY_SYSPM_PD_RESOURCE_CLK_ALTHF_REQUEST         = ((uint32)1 << 26),  /**< Clock ALTHF Request */
    CY_SYSPM_PD_RESOURCE_CLK_ALTHF_REQUIRED        = ((uint32)1 << 27),  /**< Clock ALTHF Required  */
    CY_SYSPM_PD_RESOURCE_POWER_MODE_2              = ((uint32)1 << 28),  /**< Power Mode[2] */
    CY_SYSPM_PD_RESOURCE_POWER_MODE_1              = ((uint32)1 << 29),  /**< Power Mode[1] */
    CY_SYSPM_PD_RESOURCE_POWER_MODE_0              = ((uint32)1 << 30),  /**< Power Mode[0] */
} cy_en_syspm_pd_resource_t;

#endif /* defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION >= 2) */

/** \} group_syspm_pdcm_enums */

/**
* \addtogroup group_syspm_pdcm_macros
* \{
*/

/** Driver major version */
#define CY_PD_PDCM_DRV_VERSION_MAJOR       5
/** Driver minor version */
#define CY_PD_PDCM_DRV_VERSION_MINOR       150

/** Macro to validate the PDCM PPU ID in API's : /ref cy_pd_pdcm_get_dependency, /ref cy_pd_pdcm_set_dependency() and /ref cy_pd_pdcm_clear_dependency */
#if defined (CY_IP_MXS22SRSS)
#if (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1) && defined(CY_DEVICE_PSB3)
#define CY_SYSPM_IS_PDCM_ID_VALID(id)     (((id) == CY_PD_PDCM_MAIN)          || \
                                           ((id) == CY_PD_PDCM_SYSCPUSS)      || \
                                           ((id) == CY_PD_PDCM_RRAM)          || \
                                           ((id) == CY_PD_PDCM_RRAMC)         || \
                                           ((id) == CY_PD_PDCM_CPUSS)         || \
                                           ((id) == CY_PD_PDCM_BTSS_TOP)      || \
                                           ((id) == CY_PD_PDCM_BTSS_DPLL)     || \
                                           ((id) == CY_PD_PDCM_BTSS_XTAL_PWR))
#else
#if (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR >= 2) /** Should be replaced by device specific macro */
#define CY_SYSPM_IS_PDCM_ID_VALID(id)    (((id) == CY_PD_PDCM_PD_SRSS)   || \
                                           ((id) == CY_PD_PDCM_PD_CORESS) || \
                                           ((id) == CY_PD_PDCM_PD_MEM)    || \
                                           ((id) == CY_PD_PDCM_PD_APPSS)  || \
                                           ((id) == CY_PD_PDCM_PD_M0SEC)  || \
                                           ((id) == CY_PD_PDCM_PD_LPPASS) || \
                                           ((id) == CY_PD_PDCM_SYSCPUSS)  || \
                                           ((id) == CY_PD_PDCM_APPSS)     || \
                                           ((id) == CY_PD_PDCM_PD_APPCPU) || \
                                           ((id) == CY_PD_PDCM_PD_U85)    || \
                                           ((id) == CY_PD_PDCM_PD_GFXSS)  || \
                                           ((id) == CY_PD_PDCM_PD_ISP)    || \
                                           ((id) == CY_PD_PDCM_PD_VDEC)   || \
                                           ((id) == CY_PD_PDCM_PD_VENC))
#else
#define CY_SYSPM_IS_PDCM_ID_VALID(id)    (((id) == CY_PD_PDCM_MAIN)      || \
                                           ((id) == CY_PD_PDCM_PD1)      || \
                                           ((id) == CY_PD_PDCM_SRAM0)    || \
                                           ((id) == CY_PD_PDCM_SRAM1)    || \
                                           ((id) == CY_PD_PDCM_SYSCPU)   || \
                                           ((id) == CY_PD_PDCM_APPCPUSS) || \
                                           ((id) == CY_PD_PDCM_APPCPU)   || \
                                           ((id) == CY_PD_PDCM_SOCMEM)   || \
                                           ((id) == CY_PD_PDCM_U55))
#endif
#endif
#else
#if defined (CY_DEVICE_ACW)
#define CY_SYSPM_IS_PDCM_ID_VALID(id)    (((id) == CY_PD_PDCM_MAIN)      || \
                                           ((id) == CY_PD_PDCM_SYSCPUSS) || \
                                           ((id) == CY_PD_PDCM_RRAM) || \
                                           ((id) == CY_PD_PDCM_BTSS) || \
                                           ((id) == CY_PD_PDCM_WIFI) || \
                                           ((id) == CY_PD_PDCM_RRAMC) || \
                                           ((id) == CY_PD_PDCM_W2R_WAKE) || \
                                           ((id) == CY_PD_PDCM_CPUSS) || \
                                           ((id) == CY_PD_PDCM_W2C_WAKE) || \
                                           ((id) == CY_PD_PDCM_B2R_WAKE) || \
                                           ((id) == CY_PD_PDCM_WIFISS_TOP) || \
                                           ((id) == CY_PD_PDCM_WIFISS_CORE) || \
                                           ((id) == CY_PD_PDCM_BTSS_TOP) || \
                                           ((id) == CY_PD_PDCM_BTSS_DPLL))

#else
#if defined (CY_PPU_SRAM1_BASE) && defined (CY_IP_MXS40PPSS)
#define CY_SYSPM_IS_PDCM_ID_VALID(id)    (((id) == CY_PD_PDCM_MAIN)      || \
                                           ((id) == CY_PD_PDCM_CPUSS)    || \
                                           ((id) == CY_PD_PDCM_SRAM)     || \
                                           ((id) == CY_PD_PDCM_SRAM1)    || \
                                           ((id) == CY_PD_PDCM_PPCA_SRAM0)    || \
                                           ((id) == CY_PD_PDCM_PPCA_SRAM1)    || \
                                           ((id) == CY_PD_PDCM_PPCA_SRAM2)    || \
                                           ((id) == CY_PD_PDCM_PPCA_SRAM3)    || \
                                           ((id) == CY_PD_PDCM_PPCA_SRAM4))
#elif defined (BTSS)

#define CY_SYSPM_IS_PDCM_ID_VALID(id)    (((id) == CY_PD_PDCM_MAIN)      || \
                                           ((id) == CY_PD_PDCM_SRAM)     || \
                                           ((id) == CY_PD_PDCM_CPUSS)    || \
                                           ((id) == CY_PD_PDCM_BTSS))
#elif defined (CY_PPU_SRAM1_BASE)
#define CY_SYSPM_IS_PDCM_ID_VALID(id)    (((id) == CY_PD_PDCM_MAIN)      || \
                                           ((id) == CY_PD_PDCM_CPUSS)    || \
                                           ((id) == CY_PD_PDCM_SRAM)     || \
                                           ((id) == CY_PD_PDCM_SRAM1))

#else
#define CY_SYSPM_IS_PDCM_ID_VALID(id)    (((id) == CY_PD_PDCM_MAIN)      || \
                                           ((id) == CY_PD_PDCM_CPUSS)    || \
                                           ((id) == CY_PD_PDCM_SRAM))
#endif
#endif
#endif
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION >= 2)
/** Resources available */
#define CY_SYSPM_PD_ALL_RESOURCES       ( (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_0            | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_1            | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_2            | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_3            | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_4            | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_5            | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_6            | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_7            | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_8            | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_9            | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_10           | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_11           | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_12           | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_13           | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_14           | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_15           | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_ECO               | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_IMO               | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_IHO               | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_IREF              | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_VREFBUF           | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_BOOTROW           | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_OVD               | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_ECO_WAIT_FOR_LOCK | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_DPLL_WAIT_FOR_LOCK| \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_CLK_ALTHF_REQUEST | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_CLK_ALTHF_REQUIRED| \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_POWER_MODE_2      | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_POWER_MODE_1      | \
                                          (uint32_t)CY_SYSPM_PD_RESOURCE_POWER_MODE_0 )
/** Macro to validate the resources */
#define CY_SYSPM_IS_PD_RESOURCE_VALID(resource)   ( (((uint32_t)(resource)) & ~(CY_SYSPM_PD_ALL_RESOURCES)) == 0UL )
#endif /* defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION >= 2) */
/** \} group_syspm_pdcm_macros */

/**
* \addtogroup group_syspm_pdcm_functions
* \{
*/
cy_pd_pdcm_dep_t cy_pd_pdcm_get_dependency(cy_pd_pdcm_id_t host_pd,cy_pd_pdcm_id_t dest_pd);
cy_en_syspm_status_t cy_pd_pdcm_set_dependency(cy_pd_pdcm_id_t host_pd,cy_pd_pdcm_id_t dest_pd);
cy_en_syspm_status_t cy_pd_pdcm_clear_dependency(cy_pd_pdcm_id_t host_pd,cy_pd_pdcm_id_t dest_pd);
/** \} group_syspm_pdcm_functions */

#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION >= 2)

/**
* \addtogroup group_syspm_pd_resource_map_functions
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysPm_PDResourceMapEnable
****************************************************************************//**
*
* Power Domain requests the resource/resources to be enabled/disabled using this
* function. A resource can be enabled or disabled when it is defined as a
* configurable resource. The configurability is device-specific.
*
* \param pd
* Power Domain ID that requests for the resource
*
* \param resource
* Bitmask of resource/resources to be enabled \ref cy_en_syspm_pd_resource_t
*
* \param enable
* 1 to request the resources to be enabled
* 0 to request the resources to be disabled
*
* \return
* the status of the resource enable/disable request
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_PDResourceMapEnable(cy_pd_pdcm_id_t pd, cy_en_syspm_pd_resource_t resource, bool enable);

#if (CY_IP_MXS22SRSS_VERSION_MINOR == 2)
/*******************************************************************************
* Function Name: Cy_SysPm_PDResourceMapDisable
****************************************************************************//**
*
* Power Domain requests the resource/resources to be disabled using this
* function. A resource can be disabled when it is defined as a configurable
* resource. The configurability is device-specific.
*
* \param pd
* Power Domain ID that requests for the resource
*
* \param resource
* Bitmask of resource/resources to be disabled \ref cy_en_syspm_pd_resource_t
*
* \return
* the status of the resource disable request
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_PDResourceMapDisable(cy_pd_pdcm_id_t pd, cy_en_syspm_pd_resource_t resource);

/*******************************************************************************
* Function Name: Cy_SysPm_PDResourceMapGet
****************************************************************************//**
*
* Returns the current resource map sense register value for the given
* Power Domain. Each bit position corresponds to a resource defined in
* \ref cy_en_syspm_pd_resource_t.
*
* \param pd
* Power Domain ID
*
* \return
* Bitmask of currently enabled resources \ref cy_en_syspm_pd_resource_t
*
*******************************************************************************/
uint32_t Cy_SysPm_PDResourceMapGet(cy_pd_pdcm_id_t pd);

#endif /* (CY_IP_MXS22SRSS_VERSION_MINOR == 2) */

/** \} group_syspm_pd_resource_map_functions */
#endif /* defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION >= 2)*/
#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) */
#endif /* CY_PD_PDCM_H */
