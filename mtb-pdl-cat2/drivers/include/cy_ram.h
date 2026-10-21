/***************************************************************************//**
* \file cy_ram.h
* \version 1.0
*
* Provides the API declarations of the RAM driver.
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation
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

#if !defined(CY_RAM_H)
#define CY_RAM_H

/**
* \addtogroup group_ram
* \{
* Error Correction Code (ECC) for RAM
*
* The functions and other declarations used in this driver are in cy_ram.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* The PSOC4 HV PA has a volatile static random access memory (SRAM) with
* Error Correction Code (ECC).
* The SRAM is used by the processor for storing variables and can program code,
* which can be written and executed in SRAM. SRAM memory is retained in all
* power modes (Active, Sleep, and Deep Sleep).
* At power-up, SRAM is uninitialized and should be written by application
* code before reading.
********************************************************************************
* \section group_ram_configuration ECC Considerations
********************************************************************************
* The ECC engine provides supports for Hamming code with an additional parity bit.
* This code supports single error correction and double error detection (SECDED).
* The ECC is applied to the SRAM data and address.
*     - The ECC corrects single bit errors in SRAM data (stored in SRAM memory).
*     - The ECC detects single and double bit errors in SRAM data
*     (stored in SRAM memory) and the SRAM address logic.
* The SRAM stores 40-bit of data:
*     - a 32-bit data word
*     - a 7-bit parity
*     - redundant 1-bit.
* The 32-bit SRAM data word allows 8-bit, 16-bit, and 32-bit AHB-Lite bus transfers
* in a single cycle.
* The 7-bit parity provides error correction and error detection.
* A 7-bit SECDED parity covers up to 57 data bits, which also provides space
* for additional 57-32 = 25 data bits.
* These 25 additional data bits will be used for the SRAM address.
*
********************************************************************************
* \section group_ram_more_information More Information
********************************************************************************
*
* See the technical reference manual (TRM) for more information about the RAM
* architecture.
*
********************************************************************************
* \section group_ram_changelog Changelog
********************************************************************************
*
* <table class="doxtable">
*   <tr><th>Version</th><th style="width: 52%;">Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_ram_macros Macros
* \{
*     \defgroup group_ram_general_macros RAM general parameters
*     \defgroup group_ram_init_macros RAM initialization parameters
* \}
* \defgroup group_ram_functions Functions
* \defgroup group_ram_data_structures Data Structure
* \defgroup group_ram_enumerated_types Enumerated Types
*/

#include "cy_device.h"
#include <cy_device_headers.h>

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
* Macro definitions
***************************************/
/**
* \addtogroup group_ram_general_macros
* \{
*/

/** Driver major version */
#define CY_RAM_DRV_VERSION_MAJOR       1

/** Driver minor version */
#define CY_RAM_DRV_VERSION_MINOR       0
#define CY_RAM_ID               (CY_PDL_DRV_ID(0x17UL))                          /**< RAM PDL ID */

#define CY_RAM_ID_INFO          (uint32_t)( CY_RAM_ID | CY_PDL_STATUS_INFO )   /**< Return prefix for RAM driver function status codes */
#define CY_RAM_ID_WARNING       (uint32_t)( CY_RAM_ID | CY_PDL_STATUS_WARNING) /**< Return prefix for RAM driver function warning return values */
#define CY_RAM_ID_ERROR         (uint32_t)( CY_RAM_ID | CY_PDL_STATUS_ERROR)   /**< Return prefix for RAM driver function error return values */

#define CY_RAM_WORD_ADDR_CHECK_MSK  (0x00000003U) /**< Used to get the lowest two bits of the RAM address    */
#define CY_RAM_WORD_ADDR_CHECK_POS  (0x00000002U) /**< Used to get the RAM word address for ECC injection    */

/** \} group_ram_general_macros */

/**
* \addtogroup group_ram_init_macros
* \{
*/

#define CY_RAM_ECC_ENABLE           (0x00000001U) /**< Used to enable or disable ECC */
#define CY_RAM_ECC_AUTO_CORRECT     (0x00000004U) /**< Used to enable automatic ECC error correction or disable it */

/** \} group_ram_init_macros */

/** \cond INTERNAL */
#define CY_RAM_ECC_CHECK_MSK        (CY_RAM_ECC_ENABLE | CY_RAM_ECC_AUTO_CORRECT)
/** \endcond */

/**
* \addtogroup group_ram_enumerated_types
* \{
*/

/** Status of the RAM driver */
typedef enum cy_ram_status
{
    /** Success */
    CY_RAM_DRV_SUCCESS                  =   0x00UL,
    /** Invalid device protection state */
    CY_RAM_DRV_INVALID_PROT             =   ( CY_RAM_ID_ERROR + 0x01UL),
    /** Invalid Ram address */
    CY_RAM_DRV_INVALID_RAM_ADDR         =   ( CY_RAM_ID_ERROR + 0x04UL),
    /** Row is write protected */
    CY_RAM_DRV_ROW_PROTECTED            =   ( CY_RAM_ID_ERROR + 0x05UL),
    /** Input parameters passed to RAM API are not valid */
    CY_RAM_DRV_INVALID_INPUT_PARAMETERS =   ( CY_RAM_ID_ERROR + 0x20UL),
    /** API not supported for the selected device */
    CY_RAM_DRV_DEV_NOT_SUPPORTED        =   ( CY_RAM_ID_ERROR + 0x21UL),
    /** Unknown error code */
    CY_RAM_DRV_ERROR_UNKNOWN            =   ( CY_RAM_ID_ERROR + 0xFFUL),
} cy_ram_status_t;

/** \} group_ram_enumerated_types */

/** \addtogroup group_ram_data_structures
* \{
*/

/**
* This configuration structure is used to initialize only RAM ECC Interface in the CPUSS block.
* This structure is used with \ref Cy_RAM_ECC_Init.
*/
typedef struct
{
    bool    eccEnable;      /**< ECC Enable or Disable. */
    bool    eccAutoCorrect; /**< Ecc Auto Correct Enable or Disable. */
} cy_ram_config_t;
/** \} group_ram_data_structures */

/***************************************
* Function Prototypes
***************************************/

/**
* \addtogroup group_ram_functions
* \{
*/
#if defined (CPUSS_RAMC_ECC_PRESENT) || defined (CY_DOXYGEN)
void Cy_RAM_ECC_Init (CPUSS_Type * base, uint32_t config);
void Cy_RAM_SetupEccInjection (CPUSS_Type* base, const uint32_t address, const uint8_t parity);
void Cy_RAM_EnableEccInjection(CPUSS_Type* base);
void Cy_RAM_DisableEccInjection(CPUSS_Type* base);
bool Cy_RAM_IsEccInjectionEnabled(CPUSS_Type* base);
uint32_t Cy_RAM_GetEccWordAddr(CPUSS_Type* base);
uint8_t Cy_RAM_GetEccSyndrome(CPUSS_Type* base);
void Cy_RAM_ClearEccSyndrome(CPUSS_Type* base);
bool Cy_RAM_IsWritebufferEmpty(CPUSS_Type* base);
#endif /* defined (CPUSS_RAMC_ECC_PRESENT) */

/** \} group_ram_functions */

#if defined(__cplusplus)
}
#endif


#endif /* #if !defined(CY_RAM_H) */

/** \} group_ram */

/* [] END OF FILE */
