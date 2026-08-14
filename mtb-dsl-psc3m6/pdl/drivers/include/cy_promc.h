/***************************************************************************//**
* \file cy_promc.h
* \version 1.0
*
* This file defines the public interface for the PROMC driver.
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG, or an affiliate of Infineon
* Technologies AG.
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
*
*******************************************************************************/

#ifndef CY_PROMC_H
#define CY_PROMC_H

#include <stdint.h>
#include "cy_device_headers.h"
#include "cy_device.h"

#if defined (CY_IP_MXPROMC) && (CPUSS_PROMC_PATCH_PRESENT == 1UL)

/**
* \addtogroup group_promc PROMC
* \{
*
* The Patchable ROM Controller (PROMC) provides ability to alter the code
* residing in ROM without re-spinning silicon. A limited amount of patch
* entries (address-data pairs) can be loaded into the PROMC patch table and
* patch data RAM as a replacement of original ROM content.
* All address entries are compared with the address of the actual ROM access.
* In case of an address match, the ROM content is replaced with the associated
* data from the patch data RAM.
*
*
* \section group_promc_configuration Configuration Considerations
*
* For using patching functionality, the firmware retrieves the patch information
* through some interface and installs the patches into PROMC MIMIO registers.
* This needs to be done before the application code executes the portion of code
* which needs to be patchable. The portion of code executed before retrieving
* patch data cannot be patched.
* Once the patches are installed, the patching is invisible to the application.
* To initialize the driver, call Cy_PROMC_Init
* function providing a pointer to the allocated \ref cy_stc_promc_context_t
* structure.
*
* \section group_promc_section_more_information More Information
*
* For more information on the PROMC, refer to the technical reference
* manual (TRM).
*
* \section group_promc_MISRA MISRA-C Compliance
* The PROMC driver does not have any specific deviations.
*
* \section group_promc_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_promc_macros Macros
* \defgroup group_promc_functions Functions
* \defgroup group_promc_data_structures Data Structures
* \defgroup group_promc_enums Enumerated Types
*
*/

/*******************************************************************************
*       Public Constants
*******************************************************************************/

/**
* \addtogroup group_promc_macros
* \{
*/

/** The driver major version */
#define CY_PROMC_DRV_VERSION_MAJOR      (1)

/** The driver minor version */
#define CY_PROMC_DRV_VERSION_MINOR      (0)

/** Patch entry size is fixed at design time using CPUSS_PROMC_PATCH_SIZE
* parameter. The supported values are:
* 0 -  8 bytes
* 1 - 16 bytes
* 2 - 32 bytes
* 3 - 64 bytes
* The patch size in bytes is calculated as 2^(3+CPUSS_PROMC_PATCH_SIZE)
*/
#define CY_PROMC_ENTRY_BYTES       (1UL << (3UL + CPUSS_PROMC_PATCH_SIZE))
/** The patch size in word */
#define CY_PROMC_ENTRY_WORDS       (CY_PROMC_ENTRY_BYTES / 4UL)

/** \} group_promc_macros */


/*******************************************************************************
*        Public Types
*******************************************************************************/

/**
* \addtogroup group_promc_enums
* \{
*/

 /** PROMC status codes */
typedef enum
{
    /** Operation completed successfully */
    CY_PROMC_SUCCESS = 0U,

    /** Invalid input parameters */
    CY_PROMC_BAD_PARAM = 1U,

    /** Not enough room in patch table */
    CY_PROMC_NO_MORE_ROOM = 2U,

    /** Patch is out of bounds of ROM address space */
    CY_PROMC_OUT_OF_BOUNDS = 3U
} cy_en_promc_status_t;

/** PROMC wait state */
typedef enum
{
    /** Waite state 0 */
    CY_PROMC_WAIT_STATE_0 = 0U,

    /** Waite state 1 */
    CY_PROMC_WAIT_STATE_1 = 1U,

    /** Waite state 2 */
    CY_PROMC_WAIT_STATE_2 = 2U,

    /** Waite state 3 */
    CY_PROMC_WAIT_STATE_3 = 3U
} cy_en_promc_wait_state_t;

/** PROMC patch size */
typedef enum
{
    /** Entry size is 8 byte */
    CY_PROMC_PATCH_SIZE_8_BYTE = 0U,

    /** Entry size is 16 byte */
    CY_PROMC_PATCH_SIZE_16_BYTE = 1U,

    /** Entry size is 32 byte */
    CY_PROMC_PATCH_SIZE_32_BYTE = 2U,

    /** Entry size is 64 byte */
    CY_PROMC_PATCH_SIZE_64_BYTE = 3U
} cy_en_promc_patch_size_t;

/** \} group_promc_enums */


/**
* \addtogroup group_promc_data_structures
* \{
*/

/** PROMC context structure.
* All fields for the context structure are internal. Firmware never reads or
* writes these values. Firmware allocates the structure and provides the
* address of the structure to the driver in function calls. Firmware must
* ensure that the defined instance of this structure remains in scope
* while the drive is in use.
*/
typedef struct {
          uint32_t index;   /**< PROMC table entry index */
} cy_stc_promc_context_t;

/** Configuration information structure */
typedef struct {
    uint32_t patchNumber;              /**< Number of the patch structure */
    cy_en_promc_patch_size_t size;     /**< Patch data size */
} cy_stc_promc_config_info_t;

/** PROMC patch table entry. Describes address-data pair stored in the
* PROMC for each table index.
*/
typedef struct {
    uint32_t addr;                              /**< Match address. Must be 16-byte aligned and point to start entry. Unaligned data causes memory corruption. */
    uint32_t data[CY_PROMC_ENTRY_WORDS];        /**< Patch data to update one SROM entry. */
} cy_stc_promc_entry_t;

/** Patch status structure */
typedef struct {
    uint32_t patchIndex;   /**< Match index of the patch structure that produced the most recent valid address match. */
    bool status;           /**< Validity of the patch_index */
} cy_stc_promc_patch_status_t;

/** Patch structure */
typedef struct {
          uint32_t addr;    /**< Replacement address. Must be 4-byte aligned */
          uint32_t size;    /**< Patch data size in word */
    const uint32_t *data;   /**< Pointer to the patch data */
} cy_stc_promc_patch_t;

/** \} group_promc_data_structures */


/*******************************************************************************
*        Function Prototypes
*******************************************************************************/
/**
* \addtogroup group_promc_functions
* \{
*/

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Function Name: Cy_PROMC_Init
****************************************************************************//**
*
* Initializes the patching logic of the PROMC.
*
* \param base
* The pointer to the PROMC instance.
*
* \param context
* The pointer to the context structure \ref cy_stc_promc_context_t allocated
* by the caller. The structure is used during the PROMC operation to keep track
* of the PROMC table index. The caller must not modify anything in this
* structure.
*
* \return
* The status of the init request \ref cy_en_promc_status_t
*
* \note
* Calling any PROMC function before \ref Cy_PROMC_Init will result in undefined
* behavior.
*
*******************************************************************************/
cy_en_promc_status_t Cy_PROMC_Init(PROMC_Type *base, cy_stc_promc_context_t *context);

/*******************************************************************************
* Function Name: Cy_PROMC_DeInit
****************************************************************************//**
*
* Invalidates all installed patch entries in the PROMC patch entry table.
* This function does not clear the content of the patch data RAM. Only match
* addresses along with the valid bit are cleared.
*
* \param base
* The pointer to the PROMC instance.
*
*******************************************************************************/
void Cy_PROMC_DeInit(PROMC_Type *base);

/*******************************************************************************
* Function Name: Cy_PROMC_Enable
****************************************************************************//**
*
* Enables the patching logic of the PROMC.
*
* \param base
* The pointer to the PROMC instance.
*
*******************************************************************************/
void Cy_PROMC_Enable(PROMC_Type *base);

/*******************************************************************************
* Function Name: Cy_PROMC_Disable
****************************************************************************//**
*
* Disables the patching logic of the PROMC.
*
* \param base
* The pointer to the PROMC instance.
*
*******************************************************************************/
void Cy_PROMC_Disable(PROMC_Type *base);

/*******************************************************************************
* Function Name: Cy_PROMC_GetWaitState
****************************************************************************//**
*
* Get wait states.
*
* \param base
* The pointer to the PROMC instance.
*
* \return
* Return the wait state value \ref cy_en_promc_wait_state_t
*
*******************************************************************************/
cy_en_promc_wait_state_t Cy_PROMC_GetWaitState(PROMC_Type *base);

/*******************************************************************************
* Function Name: Cy_PROMC_SetWaitState
****************************************************************************//**
*
* Set wait states.
*
* \param base
* The pointer to the PROMC instance.
*
* \param ws
* Wait state value \ref cy_en_promc_wait_state_t
*
*******************************************************************************/
void Cy_PROMC_SetWaitState(PROMC_Type *base, cy_en_promc_wait_state_t ws);

/*******************************************************************************
* Function Name: Cy_PROMC_SetPatchEntryValidBit
****************************************************************************//**
*
* Set the valid bit of a particular patch entry.
*
* \param base
* The pointer to the PROMC instance.
*
* \param index
* Index of PROMC patch structure.
*
* \return
* The status of request \ref cy_en_promc_status_t
*
*******************************************************************************/
cy_en_promc_status_t Cy_PROMC_SetPatchEntryValidBit(PROMC_Type *base, uint32_t index);

/*******************************************************************************
* Function Name: Cy_PROMC_ClearPatchEntryValidBit
****************************************************************************//**
*
* Clear the valid bit of a particular patch entry.
*
* \param base
* The pointer to the PROMC instance.
*
* \param index
* Index of PROMC patch structure.
*
* \return
* The status of request \ref cy_en_promc_status_t
*
*******************************************************************************/
cy_en_promc_status_t Cy_PROMC_ClearPatchEntryValidBit(PROMC_Type *base, uint32_t index);

/*******************************************************************************
* Function Name: Cy_PROMC_GetPatchEntryValidBit
****************************************************************************//**
*
* Get the valid bit of a particular patch entry.
*
* \param base
* The pointer to the PROMC instance.
*
* \param index
* Index of PROMC patch structure.
*
* \return
* Bool value of the status.
*
*******************************************************************************/
bool Cy_PROMC_GetPatchEntryValidBit(PROMC_Type *base, uint32_t index);

/*******************************************************************************
* Function Name: Cy_PROMC_GetConfiguration
****************************************************************************//**
*
* Write current configuration of PROMC into \ref cy_stc_promc_config_info_t.
*
* \param base
* The pointer to the PROMC instance.
*
* \param configInfo
* The pointer to the structure where stored configuration.
*
* \return
* The status of request \ref cy_en_promc_status_t.
*
*******************************************************************************/
cy_en_promc_status_t Cy_PROMC_GetConfiguration(PROMC_Type *base, cy_stc_promc_config_info_t *configInfo);

/*******************************************************************************
* Function Name: Cy_PROMC_GetPatchEntry
****************************************************************************//**
*
* Get the replacement data at address, and valid status for a given patch entry
* index.
*
* \param base
* The pointer to the PROMC instance.
*
* \param entry
* Pointer to the patch entry.
*
* \param index
* Index
*
* \return
* The status of the init request \ref cy_en_promc_status_t
*
*******************************************************************************/
cy_en_promc_status_t Cy_PROMC_GetPatchEntry(PROMC_Type *base, cy_stc_promc_entry_t *entry, uint32_t index);

/*******************************************************************************
* Function Name: Cy_PROMC_SetPatchEntry
****************************************************************************//**
*
* Set the replacement data at address, and valid status for a given patch
* entry index.
*
* \param base
* The pointer to the PROMC instance.
*
* \param entry
* Pointer to the patch entry.
*
* \param index
* Index of PROMC patch structure.
*
* \return
* The status of the request \ref cy_en_promc_status_t
*
*******************************************************************************/
cy_en_promc_status_t Cy_PROMC_SetPatchEntry(PROMC_Type *base, cy_stc_promc_entry_t *entry, uint32_t index);

/*******************************************************************************
* Function Name: Cy_PROMC_SetIndex
****************************************************************************//**
*
* Set the index into context. Init context structure.
*
* \note:
* This function linked low-level functions with high-level functions. This
* function must be called before Cy_PROMC_SetPatch. It shares the index of
* the structure that can be patched.
*
* \param base
* The pointer to the PROMC instance.
*
* \param context
* Pointer to the context structure.
*
* \param index
* Index of PROMC patch structure.
*
* \return
* The status of the request \ref cy_en_promc_status_t
*
*******************************************************************************/
cy_en_promc_status_t Cy_PROMC_SetIndex(PROMC_Type *base, cy_stc_promc_context_t *context, uint32_t index);

/*******************************************************************************
* Function Name: Cy_PROMC_GetIndex
****************************************************************************//**
*
* Get the index into context. Init context structure.
*
* \note:
* This function linked high-level functions with low-level functions. This
* function must be called beforeCy_PROMC_SetPatchEntry to get the index of
* the structure that can be patched.
*
* \param base
* The pointer to the PROMC instance.
*
* \param context
* Pointer to the context structure.
*
* \return
* The index.
*
*******************************************************************************/
uint32_t Cy_PROMC_GetIndex(PROMC_Type *base, cy_stc_promc_context_t *context);

/*******************************************************************************
* Function Name: Cy_PROMC_Status
****************************************************************************//**
*
* Get the last patch entry index and valid status that was matched that stored
* into \ref cy_stc_promc_patch_status_t.
*
* \param base
* The pointer to the PROMC instance.
*
* \param patchStatus
* Pointer to the structure where status of patch stored.
*
* \return
* Return the status of request \ref cy_en_promc_status_t.
*
*******************************************************************************/
cy_en_promc_status_t Cy_PROMC_Status(PROMC_Type *base, cy_stc_promc_patch_status_t *patchStatus);

/*******************************************************************************
* Function Name: Cy_PROMC_SetPatch
****************************************************************************//**
*
* Installs the patch data into a PROMC. The patch may span multiple MXPROMC table
* entries. Any patch data RAM boundary overruns increment the table index and set
* an appropriate match address in the MXPROMC.
*
* \param base
* The pointer to the PROMC instance.
*
* \param patch
* The pointer to the patch structure \ref cy_stc_promc_patch_t specifying
* the patch entry to be installed.
*
* \param context
* The pointer to the context structure \ref cy_stc_promc_context_t allocated
* by the caller. The structure is used during the PROMC operation to keep track
* of the PROMC table index. The caller must not modify anything in this
* structure.
*
* \return
* \ref cy_en_promc_status_t
*
*******************************************************************************/
cy_en_promc_status_t Cy_PROMC_SetPatch(PROMC_Type *base, cy_stc_promc_patch_t *patch, cy_stc_promc_context_t *context);

#if defined(__cplusplus)
}
#endif

/** \} group_promc_functions */

/** \} group_promc */

#endif /* (CY_IP_MXPROMC) && (CPUSS_PROMC_PATCH_PRESENT > 0UL) */

#endif /* CY_PROMC_H */

/* [] END OF FILE */
