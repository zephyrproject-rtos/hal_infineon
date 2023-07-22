/***************************************************************************//**
* \file cyhal_flash.h
*
* \brief
* OBSOLETED: DO NOT USE FLASH APIs IN THE NEW DESIGN.
* Provides a high level interface for interacting with the Infineon Flash memory.
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation
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

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "cyhal_hw_types.h"

#if (CYHAL_DRIVER_AVAILABLE_FLASH)
#include "cyhal_nvm.h"
#endif /* (CYHAL_DRIVER_AVAILABLE_FLASH) */

#if defined(__cplusplus)
extern "C" {
#endif


/* Macros for BWC with Flash HAL
*    DO NOT USE THEM IN THE NEW DESIGN
*/

/*******************************************************************************
*       Defines
*******************************************************************************/

/** Deprecated. Invalid argument */
#define CYHAL_FLASH_RSLT_ERR_ADDRESS                    (CYHAL_NVM_RSLT_ERR_ADDRESS)
/** Deprecated. API is not supported */
#define CYHAL_FLASH_RSLT_ERR_NOT_SUPPORTED              (CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED)

/** Deprecated. Reference to NVM object */
#define cyhal_flash_t                           cyhal_nvm_t

/** @brief Deprecated. Information about a single block of flash memory */
typedef struct
{
    uint32_t start_address; //!< Start address of the memory
    uint32_t size;          //!< Size of the flash memory
    uint32_t sector_size;   //!< Sector size of the memory
    uint32_t page_size;     //!< Page size of the memory
    uint8_t  erase_value;   //!< The flash erase value
} cyhal_flash_block_info_t;

/** @brief Deprecated. Information about all of the blocks of flash memory */
typedef struct
{
    uint8_t block_count; //!< The number of distinct flash blocks
    const cyhal_flash_block_info_t *blocks; //!< Array of the distinct flash blocks
} cyhal_flash_info_t;


/*******************************************************************************
*       Functions
*******************************************************************************/

/** Deprecated. Initialize the \ref cyhal_nvm_t object for accessing flash through the HAL
 *
 * @param[out] obj  Pointer to a flash object. The caller must allocate the memory
 *  for this object but the init function will initialize its contents.
 * @return The status of the init request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 */
#define cyhal_flash_init               		    cyhal_nvm_init

/** Deprecated. Free resources associated with flash object through the HAL.
 *
 * @param[out] obj The flash object.
 *
 */
#define cyhal_flash_free                        cyhal_nvm_free

/** Deprecated. Gets flash characteristics like the start address, size, erase values etc.
 * Refer \ref cyhal_flash_info_t for more information.
 *
 * @param[in]  obj  The flash object.
 * @param[out] info The flash characteristic info.
 *
 */
void cyhal_flash_get_info(const cyhal_flash_t *obj, cyhal_flash_info_t *info);

/** Deprecated. Read data starting at a defined address.
 *
 * @param[in]  obj     The flash object.
 * @param[in]  address Address to begin reading from.
 * @param[out] data    The buffer to read data into.
 * @param[in]  size    The number of bytes to read.
 * @return The status of the read request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 *
 */
#define cyhal_flash_read                        cyhal_nvm_read

/** Deprecated. Erase one sector starting at a defined address. The address must be at sector boundary. This
 *  will block until the erase operation is complete.
 *
 *  @see cyhal_flash_get_info() to get the flash characteristics for legal address values and
 *  the page erase size.
 *
 * @param[in] obj The flash object
 * @param[in] address The sector starting address
 * @return The status of the erase request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 *
 */
#define cyhal_flash_erase                       cyhal_nvm_erase

/** Deprecated. This function erases the page and writes the new data into the page starting at a defined
 *  address. The address must be at page boundary. This will block until the write operation is
 *  complete.
 *
 *  @see cyhal_flash_get_info() to get the flash characteristics for legal address values and
 *  the page write size. The provided data buffer must be at least as large as the flash
 *  page_size.
 *  @note Generally the \p data to be written must be located in the SRAM memory region.
 *
 * @param[in] obj The flash object
 * @param[in] address The page starting address
 * @param[in] data The data to write to the flash
 * @return The status of the write request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 *
 */
#define cyhal_flash_write                       cyhal_nvm_write

/** Deprecated. Program one page with given data starting at defined address. The address must be at page
 *  boundary. This will block until the write operation is complete.
 *  \note This function does not erase the page prior to writing. The page must be erased
 *  first via a separate call to erase.
 *
 *  @see cyhal_flash_get_info() to get the flash characteristics for legal address values and
 *  the total page size. The provided data buffer must be at least as large as the flash
 *  page_size.
 *  @note Generally the \p data to be programmed must be located in the SRAM memory region.
 *
 * @param[in] obj The flash object
 * @param[in] address The sector starting address
 * @param[in] data The data buffer to be programmed
 * @return The status of the program request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 */
#define cyhal_flash_program                     cyhal_nvm_program

/** Deprecated. Starts an asynchronous erase of a single sector of flash. Returns immediately and reports
 *  a successful start or reason for failure. The address must be aligned on a sector boundary.
 *
 *  @see cyhal_flash_get_info() to get the flash characteristics for legal address values and
 *  the page erase size.
 *
 * @param[in] obj The Flash object being operated on
 * @param[in] address The address to start erasing from
 * @return The status of the start_erase request.
 *
 */
#define cyhal_flash_start_erase                 cyhal_nvm_start_erase

/** Deprecated. Starts an asynchronous write to a single page of flash. Returns immediately and reports
 *  a successful start or reason for failure. The address must be aligned on a page boundary.
 *
 *  @see cyhal_flash_get_info() to get the flash characteristics for legal address values and
 *  the page write size. The provided data buffer must be at least as large as the flash
 *  page_size.
 *  @note Generally the \p data to be written must be located in the SRAM memory region.
 *
 * @param[in] obj The Flash object being operated on
 * @param[in] address The address to start writing to
 * @param[in] data The data to write to flash
 * @return The status of the start_write request.
 *
 */
#define cyhal_flash_start_write                 cyhal_nvm_start_write

/** Deprecated. Starts asynchronous programming of a single page of flash. Returns immediately and reports
 *  a successful start or reason for failure.
 *
 * \note Perform erase operation prior to calling this.
 *
 *  @see cyhal_flash_get_info() to get the flash characteristics for legal address values and
 *  the total page size. The provided data buffer must be at least as large as the flash
 *  page_size.
 *  @note Generally the \p data to be programmed must be located in the SRAM memory region.
 *
 * @param[in] obj The Flash object being operated on
 * @param[in] address The address to start programming
 * @param[in] data The data to write to flash
 * @return The status of the start_program request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 */
#define cyhal_flash_start_program               cyhal_nvm_start_program

/** Deprecated. Reports status of the flash operation
 *
 * @param[in]  obj      The Flash object being operated on
 * @return true if flash operation is complete. false otherwise.
 */
#define cyhal_flash_is_operation_complete       cyhal_nvm_is_operation_complete


#if defined(__cplusplus)
}
#endif

#ifdef CYHAL_FLASH_IMPL_HEADER
#include CYHAL_FLASH_IMPL_HEADER
#endif /* CYHAL_FLASH_IMPL_HEADER */
