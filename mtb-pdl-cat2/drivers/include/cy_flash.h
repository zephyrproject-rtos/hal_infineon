/***************************************************************************//**
* \file cy_flash.h
* \version 1.30
*
* Provides the API declarations of the Flash driver.
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
*
*******************************************************************************/

#if !defined(CY_FLASH_H)
#define CY_FLASH_H

/**
* \addtogroup group_flash
* \{
* Internal Flash and Supervisory Flash memory programming.
*
* The functions and other declarations used in this driver are in cy_flash.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* Flash memory in PSOC devices provides non-volatile storage for the user firmware,
* user configuration data, and bulk data storage.
*
* Flash programming operations are implemented as system calls. System calls are
* executed out of SROM in the privileged mode of operation. Users have no access
* to read or modify the SROM code. The CPU requests the system call by writing
* the function opcode and parameters to the System Performance Controller (SPC)
* input registers, and then requesting the SROM to execute the function. Based
* on the function opcode, the SPC executes the corresponding system call from
* SROM and updates the SPC status register. The CPU should read this status
* register for the pass/fail result of the function execution.
*
*\note Flash write operations modify the clock settings of the device during the
* period of the write operation. Refer to the \ref Cy_Flash_WriteRow()
* documentation for details.
*
********************************************************************************
* \section group_flash_configuration Configuration Considerations
********************************************************************************
*
* Writing to Flash can take up to 20 milliseconds. During this time,
* the device should not be reset (including XRES pin, software  reset, and
* watchdog) or unexpected changes may be made to portions of the Flash.
* Also, the low-voltage detect circuits should be configured to generate an
* interrupt instead of a reset.
*
* The Flash can be read either by the cache controller or the SPC. Flash write
* can be performed only by the SPC. Both the SPC and cache cannot simultaneously
* access Flash memory. If the cache controller tries to access Flash at the same
* time as the SPC, then it must wait until the SPC completes its Flash access
* operation. The CPU, which accesses the Flash memory through the cache
* controller, is therefore also stalled in this circumstance. If a CPU code
* fetch has to be done from Flash memory due to a cache miss condition, then the
* cache would have to wait until the SPC completes the Flash write operation.
* Thus the CPU code execution will also be halted till the Flash write is
* complete. Flash is directly mapped into memory space and can be read directly.
*
********************************************************************************
* \section group_flash_more_information More Information
********************************************************************************
*
* See the technical reference manual (TRM) for more information about the Flash
* architecture.
*
********************************************************************************
* \section group_flash_changelog Changelog
********************************************************************************
*
* <table class="doxtable">
*   <tr><th>Version</th><th style="width: 52%;">Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td rowspan="2">1.30</td>
*     <td>Added check for syscall completion .</td>
*     <td>Bug fix.</td>
*   </tr>
*   <tr>
*     <td>Improved FLASH Macro number calculation.</td>
*     <td>Minor enhancement.</td>
*   </tr>
*   <tr>
*     <td rowspan="1">1.20</td>
*     <td>Enabled flash non-blocking write operations for devices with 1 flash array.</td>
*     <td>Minor enhancement.</td>
*   </tr>
*   <tr>
*     <td rowspan="3">1.10</td>
*     <td>Added Flash protection control support, Added ECC support.</td>
*     <td>New feature support.</td>
*   </tr>
*   <tr>
*     <td>Added support for extra rows FLASH Macro.</td>
*     <td>Minor enhancement.</td>
*   </tr>
*   <tr>
*     <td>Added support for latest FLASH page size macro.</td>
*     <td>Minor enhancement.</td>
*   </tr>
*   <tr>
*     <td>1.0.1</td>
*     <td>Removed unused library.</td>
*     <td>Minor enhancement.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_flash_macros Macros
* \{
*     \defgroup group_flash_general_macros Flash general parameters
*         Provides general definitions
*
*     \defgroup group_flash_config_macros  Flash Configuration
*         Provides device-specific definitions
* \}
* \defgroup group_flash_functions Functions
* \defgroup group_flash_enumerated_types Enumerated Types
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
* \addtogroup group_flash_general_macros
* \{
*/

/** Driver major version */
#define CY_FLASH_DRV_VERSION_MAJOR       1

/** Driver minor version */
#define CY_FLASH_DRV_VERSION_MINOR       30

#define CY_FLASH_ID               (CY_PDL_DRV_ID(0x14UL))                          /**< FLASH PDL ID */

#define CY_FLASH_ID_INFO          (uint32_t)( CY_FLASH_ID | CY_PDL_STATUS_INFO )   /**< Return prefix for FLASH driver function status codes */
#define CY_FLASH_ID_WARNING       (uint32_t)( CY_FLASH_ID | CY_PDL_STATUS_WARNING) /**< Return prefix for FLASH driver function warning return values */
#define CY_FLASH_ID_ERROR         (uint32_t)( CY_FLASH_ID | CY_PDL_STATUS_ERROR)   /**< Return prefix for FLASH driver function error return values */

/** \} group_flash_general_macros */


/**
* \addtogroup group_flash_config_macros
* \{
*/

/** The size of the Flash memory */
#define CY_FLASH_SIZEOF_FLASH               (CY_FLASH_SIZE)

#if (CPUSS_SPCIF_FLASH_PAGE_SIZE == 0U) || (CPUSS_SPCIF_FLASH_PAGE_SIZE == 64U)
    /** The size of the Flash row */
    #define CY_FLASH_SIZEOF_ROW             (64U)
#elif (CPUSS_SPCIF_FLASH_PAGE_SIZE == 1U) || (CPUSS_SPCIF_FLASH_PAGE_SIZE == 128U)
    /** The size of the Flash row */
    #define CY_FLASH_SIZEOF_ROW             (128U)
#elif (CPUSS_SPCIF_FLASH_PAGE_SIZE == 3U) || (CPUSS_SPCIF_FLASH_PAGE_SIZE == 256U)
    /** The size of the Flash row */
    #define CY_FLASH_SIZEOF_ROW             (256U)
#endif /* (CPUSS_SPCIF_FLASH_PAGE_SIZE > 3U) */

/** The number of Flash rows */
#define CY_FLASH_NUMBER_ROWS                (CY_FLASH_SIZE / CY_FLASH_SIZEOF_ROW)

/** The size of the Flash macro in the number of Flash rows */
#define CY_FLASH_SIZEOF_MACRO               (((CPUSS_SPCIF_FLASH_SIZE + 1U) * 256U / CY_FLASH_SIZEOF_ROW) / CPUSS_SPCIF_FLASH_MACROS)

/** The number of the Flash macros */
#define CY_FLASH_NUMBER_MACROS              (CPUSS_SPCIF_FLASH_MACROS)

#if (defined (SFLASH_FLASH_M0_XTRA_ROWS) && (SFLASH_FLASH_M0_XTRA_ROWS == 1U)) || defined (CY_DOXYGEN)
    #if (CY_FLASH_SIZEOF_ROW == 256U)
        /** The Supervisory Flash memory user base address */
        #define CY_FLASH_SFLASH_USERBASE    (CY_SFLASH_BASE + 0x400U)
    #else
        /** The Supervisory Flash memory user base address */
        #define CY_FLASH_SFLASH_USERBASE    (CY_SFLASH_BASE + 0x200U)
    #endif /* (CY_FLASH_SIZEOF_ROW == 256U) */

    /** The size of the SFlash row */
    #define CY_FLASH_SIZEOF_SFLASH_ROW      (CY_FLASH_SIZEOF_ROW)

    /** The number of SFlash rows */
    #define CY_FLASH_NUMBER_SFLASH_ROWS     (4U)

    /** The size of the Supervisory Flash user memory */
    #define CY_FLASH_SIZEOF_USERSFLASH      (CY_FLASH_NUMBER_SFLASH_ROWS * CY_FLASH_SIZEOF_SFLASH_ROW)
#elif (defined (SFLASH_USER_SFLASH_AREA_LOCATION_Pos))
    #define SFLASH_HIGH_BASE_ADDR               (0x0FFF0000UL)
    /* If user area exist */
    /* The User SFlash memory base address */
    #define CY_FLASH_SFLASH_USERBASE    (SFLASH_HIGH_BASE_ADDR | _FLD2VAL(SFLASH_USER_SFLASH_AREA_LOCATION, SFLASH_USER_AREA))
    /* The User SFlash memory base address */
    #define CY_FLASH_SFLASH_USERBASE1    (SFLASH_HIGH_BASE_ADDR | _FLD2VAL(SFLASH_USER_SFLASH_AREA_LOCATION, SFLASH_USER_AREA1))
    /* The size of the Supervisory Flash user memory */
    #define CY_FLASH_SIZEOF_USERSFLASH    _FLD2VAL(SFLASH_USER_SFLASH_AREA_SIZE, SFLASH_USER_AREA)
    #define CY_FLASH_SIZEOF_USERSFLASH1    _FLD2VAL(SFLASH_USER_SFLASH_AREA_SIZE, SFLASH_USER_AREA1)
#endif /* (SFLASH_FLASH_M0_XTRA_ROWS == 1U) || defined (CY_DOXYGEN) */

/** Reports if device supports non-blocking Flash operations */
#define CY_FLASH_NON_BLOCKING_SUPPORTED     \
        (CPUSS_SPCIF_FLASH_PARALLEL_PGM_EN && (CPUSS_SPCIF_FLASH_MACROS > 1U))

/** \} group_flash_config_macros */


/**
* \addtogroup group_flash_enumerated_types
* \{
*/

/** Status of the Flash driver */
typedef enum cy_en_flashdrv_status
{
    /** Success */
    CY_FLASH_DRV_SUCCESS                  =   0x00UL,
    /** Invalid device protection state */
    CY_FLASH_DRV_INVALID_PROT             =   ( CY_FLASH_ID_ERROR + 0x01UL),
    /** Invalid Flash address */
    CY_FLASH_DRV_INVALID_FLASH_ADDR       =   ( CY_FLASH_ID_ERROR + 0x04UL),
    /** Row is write protected */
    CY_FLASH_DRV_ROW_PROTECTED            =   ( CY_FLASH_ID_ERROR + 0x05UL),
    /** Input parameters passed to Flash API are not valid */
    CY_FLASH_DRV_INVALID_INPUT_PARAMETERS =   ( CY_FLASH_ID_ERROR + 0x20UL),
    /** API not supported for the selected device */
    CY_FLASH_DRV_DEV_NOT_SUPPORTED        =   ( CY_FLASH_ID_ERROR + 0x21UL),
    /** Unknown error code */
    CY_FLASH_DRV_ERROR_UNKNOWN            =   ( CY_FLASH_ID_ERROR + 0xFFUL),
    /** Command in progress; no error. Status returned by \ref Cy_Flash_IsOperationComplete()
     * when a Flash operation is in progress */
    CY_FLASH_DRV_PROGRESS_NO_ERROR        =   ( CY_FLASH_ID_INFO  + 0x09UL),
    /** Flash operation is successfully initiated. Status returned when \ref Cy_Flash_StartWrite() succeeds */
    CY_FLASH_DRV_OPERATION_STARTED        =   ( CY_FLASH_ID_INFO  + 0x23UL),
    /** Flash is under operation. Status is returned when flash non-blocking operation is complete and waiting for
     * \ref Cy_Flash_ResumeWrite() API call */
    CY_FLASH_DRV_PENDING_RESUME           =   ( CY_FLASH_ID_INFO  + 0x08UL)
} cy_en_flashdrv_status_t;

/** \} group_flash_enumerated_types */

/***************************************
* Function Prototypes
***************************************/

/**
* \addtogroup group_flash_functions
* \{
*/
cy_en_flashdrv_status_t Cy_Flash_WriteRow(uint32_t rowAddr, const uint32_t* data);
cy_en_flashdrv_status_t Cy_Flash_StartWrite(uint32_t rowAddr, const uint32_t* data);
cy_en_flashdrv_status_t Cy_Flash_ResumeWrite(void);
cy_en_flashdrv_status_t Cy_Flash_IsOperationComplete(void);
cy_en_flashdrv_status_t Cy_Flash_RowChecksum(uint32_t rowAddr, uint32_t* checksumPtr);
#if defined(CPUSS_SPCIF_FLASH_S8FS_VER2) || defined (CY_DOXYGEN)
cy_en_flashdrv_status_t Cy_Flash_SetProtection(const uint32_t bitField);
cy_en_flashdrv_status_t Cy_Flash_GetProtectionStatus(uint32_t* statusPtr);
#endif /* defined(CPUSS_SPCIF_FLASH_S8FS_VER2) || defined (CY_DOXYGEN) */
#if (defined(CPUSS_FLASHC_PRESENT_WITH_ECC) && (CPUSS_FLASHC_PRESENT_WITH_ECC == 1U))  || defined (CY_DOXYGEN)
cy_en_flashdrv_status_t Cy_Flash_SetupEccInjection(const uint32_t address, const uint8_t parity);
void Cy_Flash_EnableEccInjection(void);
void Cy_Flash_DisableEccInjection(void);
bool Cy_Flash_IsEccInjectionEnabled(void);
#endif /* (defined(CPUSS_FLASHC_PRESENT_WITH_ECC) && (CPUSS_FLASHC_PRESENT_WITH_ECC == 1U))  || defined (CY_DOXYGEN) */

/** \} group_flash_functions */

#if defined(__cplusplus)
}
#endif


#endif /* #if !defined(CY_FLASH_H) */

/** \} group_flash */


/* [] END OF FILE */
