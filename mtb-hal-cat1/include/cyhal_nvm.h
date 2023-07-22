/***************************************************************************//**
* \file cyhal_nvm.h
*
* \brief
* Provides a high level interface for interacting with the Infineon onboard
* NVM(Non-Volatile Memory).
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

/**
* \addtogroup group_hal_nvm NVM (Onboard Non-Volatile Memory)
* \ingroup group_hal
* \{
* High level interface to the onboard Non-Volatile memory (Internal Flash, RRAM, OTP region).
*
* Onboard NVM provides non-volatile storage for factory settings, secure data,
* user firmware, configuration, and bulk data.
*
* This driver allows data to be read from and written to NVM. It also provides the
* ability to obtain information about the address and characteristics of the NVM
* block(s) contained on the device. During NVM write time, the device should not be
* reset (including XRES pin, software reset, and watchdog) or unexpected changes may
* be made to portions of the NVM. Also, the low-voltage detect circuits should be
* configured to generate an interrupt instead of a reset.
*
* \note A Read while Write violation may occur for some devices when a NVM Read
* operation is initiated in the same or neighboring NVM sector/region where the NVM
* Write, Erase(if applicable), or Program operation is working. Refer the device datasheet
* for more information. This violation may cause a HardFault exception. To avoid the
* Read while Write violation, the user must carefully split the Read and Write
* operations on NVM sectors/regions which are not neighboring, considering all cores in
* a multi-processor device. User may edit the linker script to place the code into
* neighboring sectors/regions. For example, use sectors number 0 and 1 for code and sectors
* 2 and 3 for data storage.
*
* \section hal_nvm_features Features
* * NVM operations are performed on a per-block (program) or per-sector (erase if applicable) basis
*   (Refer the device datasheet for more information on the block size)
* * Supports Blocking or Non-Blocking erase(if applicable), program, and write
* \section hal_nvm_code_snippet Code Snippets
* \subsection subsection_nvm_use_case_1 Snippet 1: Get NVM Characteristics
* Following code snippet demonstrates how to fetch NVM characteristics. Refer \ref
* cyhal_nvm_info_t for more information.
* \snippet hal_nvm.c snippet_cyhal_nvm_get_nvm_info
*
* \subsection subsection_nvm_use_case_2 Snippet 2: Blocking NVM Erase-Write and Read
* Following code snippet demonstrates blocking NVM write.
* It uses a constant array with a size equaling the size of one NVM row/block.
* It uses blocking NVM write operation which blocks the caller until the write is
* completed. It then verifies the NVM data by comparing the NVM data with the
* written data.
* \snippet hal_nvm.c snippet_cyhal_nvm_blocking_mode_nvmwrite
*
* \subsection subsection_nvm_use_case_3 Snippet 3: Non-blocking NVM Erase-Write and Read
* Following code snippet implements the non-blocking NVM write using polling to
* complete the NVM write operation. It uses a constant array with a size equaling
* the size of one NVM row/block. It uses a polling method to complete the NVM
* write operation. It then verifies the NVM data by comparing the NVM data with
* the written data.
* \snippet hal_nvm.c snippet_cyhal_nvm_non_blocking_mode_polling_nvmwrite
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cyhal_general_types.h"
#include "cyhal_hw_types.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*       Defines
*******************************************************************************/

/** \addtogroup group_hal_results_nvm NVM HAL Results
 *  NVM specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */
/** Invalid argument */
#define CYHAL_NVM_RSLT_ERR_ADDRESS                    \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, CYHAL_RSLT_MODULE_NVM, 0))
/** API is not supported */
#define CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED              \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, CYHAL_RSLT_MODULE_NVM, 1))
/** Unable to support due to power state */

/**
 * \}
 */

/** Enum of Non-volatile memory (NVM) types */
typedef enum
{
    CYHAL_NVM_TYPE_INVALID = 0U,  //!< Invalid type of NVM
	CYHAL_NVM_TYPE_FLASH   = 1U,  //!< Internal Flash
	CYHAL_NVM_TYPE_RRAM    = 2U,  //!< RRAM
	CYHAL_NVM_TYPE_OTP     = 3U   //!< OTP
} cyhal_nvm_type_t;

/** @brief Information about a single region of NVM memory */
typedef struct
{
	cyhal_nvm_type_t    nvm_type;              //!< NVM type.
	uint32_t            start_address;         //!< Base address of the distinct NVM region.
	uint32_t            offset;                //!< Offset to the address in the distinct NVM region.
	uint32_t            size;                  //!< Size of the distinct NVM region.
	uint32_t            sector_size;           //!< Sector size of the distinct NVM region.
    uint32_t            block_size;            //!< Block size (programming granularity) of the distinct NVM region.
	bool                is_erase_required;     //!< true = erase required before program, false = erase not required before program.
	uint8_t             erase_value;           //!< NVM erase value (if applicable).
} cyhal_nvm_region_info_t;

/** @brief Information about all of the regions of NVM memory */
typedef struct
{
    uint8_t region_count;                     //!< The number of distinct NVM regions.
    const cyhal_nvm_region_info_t* regions;   //!< Array of the distinct NVM regions.
} cyhal_nvm_info_t;


/*******************************************************************************
*       Functions
*******************************************************************************/

/** Initialize the \ref cyhal_nvm_t object for accessing NVM through the HAL.
 *
 * @param[in] obj Pointer to a NVM object. The caller must allocate the memory
 * for this object but the init function will initialize its contents.
 * @return The status of the init request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 */
cy_rslt_t cyhal_nvm_init(cyhal_nvm_t* obj);

/** Free resources associated with the NVM HAL driver.
 *
 * @param[out] obj The NVM object.
 *
 */
void cyhal_nvm_free(cyhal_nvm_t* obj);

/** Get details about the NVM memory regions such as NVM type, start address, size, is_erase_required, and erase values etc.
 * Refer \ref cyhal_nvm_info_t, cyhal_nvm_region_info_t for more information.
 *
 * @param[in]  obj  The NVM object.
 * @param[out] info The NVM characteristic info.
 *
 * Refer \ref subsection_nvm_use_case_1 for more information.
 */
void cyhal_nvm_get_info(cyhal_nvm_t* obj, cyhal_nvm_info_t* info);

/** Read size amount of data starting from the given address of NVM.
 *
 * @param[in]  obj     The NVM object.
 * @param[in]  address Address to begin reading from.
 * @param[out] data    The buffer to read data into.
 * @param[in]  size    The number of bytes to read.
 * @return The status of the read request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 *
 * Refer \ref subsection_nvm_use_case_2 for more information.
 *
 */
cy_rslt_t cyhal_nvm_read(cyhal_nvm_t* obj, uint32_t address, uint8_t* data, size_t size);

/** Erase one block of NVM starting at the given address. The address must be at block boundary.
 * This will block until the erase operation is complete.
 *
 * @see cyhal_nvm_get_info() to get the NVM characteristics for legal address values, is erase
 * required/applicable, and the erase block size(if applicable).
 *
 * @param[in] obj The NVM object
 * @param[in] address The block address to be erased
 * @return The status of the erase request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 *
 * Refer \ref subsection_nvm_use_case_2 for more information.
 */
cy_rslt_t cyhal_nvm_erase(cyhal_nvm_t* obj, uint32_t address);

/** This function erases the block, if required, and writes the new data into the block starting
 * at the given address. The address must be at block boundary. This will block until the write
 * operation is complete.
 *
 * @see cyhal_nvm_get_info() to get the NVM characteristics for legal address values and
 * the write block size. The provided data buffer must be at least as large as the NVM
 * block_size.
 * @note Generally the \p data to be written must be located in the SRAM memory region.
 *
 * @param[in] obj The NVM object
 * @param[in] address The address of the block to be written
 * @param[in] data The data buffer to be written to the NVM block
 * @return The status of the write request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 *
 * Refer \ref subsection_nvm_use_case_2 for more information.
 */
cy_rslt_t cyhal_nvm_write(cyhal_nvm_t* obj, uint32_t address, const uint32_t* data);

/** Write one-time data to the given byte location in the provided block of NVM OTP region. The block
 * must be within the defined block range of the OTP (refer the device datasheet for more information).
 *
 * @note You can only ONCE write data at desired byte in specific block,
 * if you will try to do it more times, you can have broken data at this location.
 * @see cyhal_nvm_get_info() to get the NVM OTP region characteristics for legal address values, size
 * and the OTP block size.
 *
 * @param[in] obj The NVM object
 * @param[in] address The address of the block to be written
 * @param[in] data The data to be written to the OTP memory
 * @return The status of the program request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 */
cy_rslt_t cyhal_nvm_otp_write(cyhal_nvm_t* obj, uint32_t address, uint8_t data);

/** Program one block with the provided data starting at the given address. The address must be
 * at block boundary. This will block until the write operation is complete.
 *
 * @note This function does not erase the block prior to writing. The block must be erased
 * first via a separate call to erase.
 * @see cyhal_nvm_get_info() to get the NVM characteristics for legal address values and
 * the total block size. The provided data buffer must be at least as large as the NVM
 * block_size.
 * @note Generally the \p data to be programmed must be located in the SRAM memory region.
 *
 * @param[in] obj The NVM object
 * @param[in] address The address of the block to be programmed
 * @param[in] data The data buffer to be programmed to the NVM block
 * @return The status of the program request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 */
cy_rslt_t cyhal_nvm_program(cyhal_nvm_t* obj, uint32_t address, const uint32_t* data);

/** Start an asynchronous erase of a single block of NVM starting at the given address.
 * Returns immediately and reports a successful start or reason for failure. The address must
 * be aligned on a block boundary.
 *
 * @see cyhal_nvm_get_info() to get the NVM characteristics for legal address values, is erase
 * required/applicable, and the erase block size(if applicable).
 *
 * @param[in] obj The NVM object
 * @param[in] address The block address to be erased
 * @return The status of the start_erase request.
 *
 * Refer \ref subsection_nvm_use_case_3 for more information.
 */
cy_rslt_t cyhal_nvm_start_erase(cyhal_nvm_t* obj, uint32_t address);

/** Start an asynchronous write (Erase if required + Program) on single block of NVM starting at the
 * given address.
 * Returns immediately and reports a successful start or reason for failure. The address must be
 * aligned on a block boundary.
 *
 * @see cyhal_nvm_get_info() to get the NVM characteristics for legal address values and
 * the write block size. The provided data buffer must be at least as large as the NVM
 * block_size.
 * @note Generally the \p data to be written must be located in the SRAM memory region.
 *
 * @param[in] obj The NVM object
 * @param[in] address The address of the block to be written
 * @param[in] data The data buffer to be written to the NVM block
 * @return The status of the start_write request.
 *
 * Refer \ref subsection_nvm_use_case_3 for more information.
 */
cy_rslt_t cyhal_nvm_start_write(cyhal_nvm_t* obj, uint32_t address, const uint32_t* data);


/** Start asynchronous programming of a single block of NVM starting at the given address.
 * Returns immediately and reports a successful start or reason for failure.
 *
 * \note This function does not erase the block prior to writing. The block must be erased
 * first via a separate call to erase.
 *
 * @see cyhal_nvm_get_info() to get the NVM characteristics for legal address values and
 * the total block size. The provided data buffer must be at least as large as the NVM
 * block_size.
 * @note Generally the \p data to be programmed must be located in the SRAM memory region.
 *
 * @param[in] obj The NVM object
 * @param[in] address The address of the block to be programmed
 * @param[in] data The data buffer to be programmed to the NVM block
 * @return The status of the program request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 */
cy_rslt_t cyhal_nvm_start_program(cyhal_nvm_t *obj, uint32_t address, const uint32_t* data);

/** Reports status of the last NVM operation.
 *
 * @param[in] obj The NVM object
 * @return true if NVM operation is complete. false otherwise.
 */
bool cyhal_nvm_is_operation_complete(cyhal_nvm_t *obj);


#if defined(__cplusplus)
}
#endif

#ifdef CYHAL_NVM_IMPL_HEADER
#include CYHAL_NVM_IMPL_HEADER
#endif /* CYHAL_NVM_IMPL_HEADER */

/** \} group_hal_nvm */
