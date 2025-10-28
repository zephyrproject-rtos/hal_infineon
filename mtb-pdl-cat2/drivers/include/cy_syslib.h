/***************************************************************************//**
* \file cy_syslib.h
* \version 3.30.1
*
* Provides an API declaration of the SysLib driver.
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

/**
* \addtogroup group_syslib
* \{
* The system libraries provide APIs that can be called in the user application
* to handle the timing, logical checking or register.
*
* The functions and other declarations used in this driver are in cy_syslib.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* The SysLib driver contains a set of different system functions. These functions
* can be called in the application routine. Major features of the system library:
* * Delay functions
* * The register Read/Write macro
* * Assert and Halt
* * Assert Classes and Levels
* * Reading the reset cause
* * An API to invalidate the flash cache and buffer
* * Data manipulation macro
* * A variable type definition from MISRA-C which specifies signedness
* * Cross compiler compatible attributes
* * Setting wait states API
* * APIs to serve Fault handler
*
* \section group_syslib_configuration Configuration Considerations
* <b> Assertion Usage </b> <br />
* Use the CY_ASSERT() macro to check expressions that must be true as long as the
* program is running correctly. It is a convenient way to insert sanity checks.
* The CY_ASSERT() macro is defined in the cy_utils.h file which is part of the
* <a href="https://github.com/Infineon/core-lib">Core Library (core-lib)</a>.
* The behavior of the macro is as follows: if the expression passed
*  to the macro is false the CPU will be halted. \n
*
* The PDL source code uses this assert mechanism extensively. It is recommended
* that you enable asserts when debugging firmware. \n
* <b> Assertion Classes and Levels </b> <br />
* The <a href="https://github.com/Infineon/core-lib">Infineon Core Library</a>
* defines three assert classes, which correspond to different
* kinds of parameters. There is a corresponding assert "level" for each class.
* <table class="doxtable">
*   <tr><th>Class Macro</th><th>Level Macro</th><th>Type of check</th></tr>
*   <tr>
*     <td>CY_ASSERT_CLASS_1</td>
*     <td>CY_ASSERT_L1</td>
*     <td>A parameter that could change between different PSOC devices
*         (e.g. the number of clock paths)</td>
*   </tr>
*   <tr>
*     <td>CY_ASSERT_CLASS_2</td>
*     <td>CY_ASSERT_L2</td>
*     <td>A parameter that has fixed limits such as a counter period</td>
*   </tr>
*   <tr>
*     <td>CY_ASSERT_CLASS_3</td>
*     <td>CY_ASSERT_L3</td>
*     <td>A parameter that is an enum constant</td>
*   </tr>
* </table>
* Firmware defines which ASSERT class is enabled by defining CY_ASSERT_LEVEL.
* This is a compiler command line argument, similar to how the DEBUG / NDEBUG
* macro is passed. \n
* Enabling any class also enables any lower-numbered class.
* CY_ASSERT_CLASS_3 is the default level, and it enables asserts for all three
* classes. The following example shows the command-line option to enable all
* the assert levels:
* \code -D CY_ASSERT_LEVEL=CY_ASSERT_CLASS_3 \endcode
* \note The use of special characters, such as spaces, parenthesis, etc. must
* be protected with quotes.
*
* After CY_ASSERT_LEVEL is defined, firmware can use
* one of the three level macros to make an assertion. For example, if the
* parameter can vary between devices, firmware uses the L1 macro.
* \code CY_ASSERT_L1(clkPath < SRSS_NUM_CLKPATH); \endcode
* If the parameter has bounds, firmware uses L2.
* \code CY_ASSERT_L2(trim <= CY_CTB_TRIM_VALUE_MAX); \endcode
* If the parameter is an enum, firmware uses L3.
* \code CY_ASSERT_L3(config->LossAction <= CY_SYSCLK_CSV_ERROR_FAULT_RESET); \endcode
* Each check uses the appropriate level macro for the kind of parameter being checked.
* If a particular assert class/level is not enabled, then the assert does nothing.
*
* \section group_syslib_more_information More Information
* Refer to the technical reference manual (TRM).
*
* \section group_syslib_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>3.30.1</td>
*     <td>Updated \ref group_syslib_macros_reset_cause macros description.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td rowspan="3">3.30</td>
*     <td>Added support for PSOC4 HVMS/PA platform.</td>
*     <td>New device support.</td>
*   </tr>
*   <tr>
*     <td>Extended syslib reset reason mask for PSOC4 HVMS/PA devices.
*     \ref Cy_SysLib_GetResetReason() and \ref Cy_SysLib_ClearResetReason() API functions implementation is updated.
*     Minor documentation updates.</td>
*     <td>Minor enhancement.</td>
*   </tr>
*   <tr>
*     <td>Added \ref Cy_SysLib_GetBootStatus() and \ref Cy_SysLib_GetBootResult() functions to handle Boot-Up Status and Results.
*     Applicable to PSOC4 HVMS/PA only.</td>
*     <td>New feature support.</td>
*   </tr>
*   <tr>
*     <td>3.20</td>
*     <td>Updated the flash wait state register configuration in \ref Cy_SysLib_SetWaitStates() for devices with FLASH ECC support.</td>
*     <td>Support for devices with FLASH ECC feature.</td>
*   </tr>
*   <tr>
*     <td>3.10</td>
*     <td>Added Cy_SysLib_GetUniqueId() to fetch silicon unique information.</td>
*     <td>New feature support.</td>
*   </tr>
*   <tr>
*     <td>3.0</td>
*     <td>Removed all the outdated legacy declarations.</td>
*     <td>Major PDL revision.</td>
*   </tr>
*   <tr>
*     <td>2.20</td>
*     <td>Updated \ref Cy_SysLib_SetWaitStates() to enable flash prefetch buffer
*         for the wait states above zero.</td>
*     <td>Speed up code execution.</td>
*   </tr>
*   <tr>
*     <td>2.10.2</td>
*     <td>Corrected source code comments text.</td>
*     <td></td>
*   </tr>
*   <tr>
*     <td>2.10.1</td>
*     <td>Updated the CY_ASSERT_LX macros implementation.</td>
*     <td>Replaced "0" with "false" in the do{}while(...) macro.</td>
*   </tr>
*   <tr>
*     <td>2.10</td>
*     <td>Updated \ref Cy_SysLib_DelayCycles() with Cortex-M0 devices support.</td>
*     <td>Fixed incorrect delay provided by \ref Cy_SysLib_DelayCycles() on Cortex-M0 devices. </td>
*   </tr>
*   <tr>
*     <td>2.0</td>
*     <td>Removed redundant functions Cy_SysLib_Halt(), Cy_SysLib_AssertFailed()</td>
*     <td>CY_ASSERT() and CY_HALT() functions of the
*         [core library](https://infineon.github.io/core-lib/html/group__group__utils.html)
*         should be used instead.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_syslib_macros Macros
* \defgroup group_syslib_functions Functions
* \defgroup group_syslib_data_structures Data Structures
* \defgroup group_syslib_enumerated_types Enumerated Types
*
*/

#if !defined(CY_SYSLIB_H)
#define CY_SYSLIB_H

#include <stdint.h>
#include <stdbool.h>
#include "cy_utils.h"
#include "cy_result.h"
#include "cy_device.h"
#include "cy_device_headers.h"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined( __ICCARM__ )
    /* Suppress the warning for multiple volatile variables in an expression. */
    /* This is common for driver's code and the usage is not order-dependent. */
    #pragma diag_suppress=Pa082
#endif  /* defined( __ICCARM__ ) */

/**
* \addtogroup group_syslib_macros
* \{
*/

/******************************************************************************
* Macros
*****************************************************************************/

#define CY_CPU_CORTEX_M0P   (__CORTEX_M == 0)    /**< Arm Cortex M0/M0+ CPU core */

/** The macro to disable the Fault Handler */
#define CY_ARM_FAULT_DEBUG_DISABLED    (0U)
/** The macro to enable the Fault Handler */
#define CY_ARM_FAULT_DEBUG_ENABLED     (1U)

#if !defined(CY_ARM_FAULT_DEBUG)
    /** The macro defines if the Fault Handler is enabled. Enabled by default. */
    #define CY_ARM_FAULT_DEBUG         (CY_ARM_FAULT_DEBUG_ENABLED)
#endif /* CY_ARM_FAULT_DEBUG */

/*
 * DIE offset related to the flash type
 * There is no direct information about the flash type,
 * but it is possible to identify flash indirectly.
 * In the previous versions of SAS, FLASH_PAGE_SIZE was coded by
 * 0-1-3 for 64-128-256 bytes of the page size
 * in the new version of SAS, FLASH PAGE SIZE directly represents the page size in bytes
 * flash coded as 0-1-3 have offset 0x178-0x278
 * flash coded in bytes have offset 0x050
 * PSOC4HV192K can be exception (coded in bytes but offset 0x178)
 * but PSOC4HV192K not exist in silicon
 */
#if (CPUSS_SPCIF_FLASH_PAGE_SIZE == 128U)
    /** The macro to DIE offset address of the devices with flash.128x4 */
    #define CY_PDL_DIE_OFFSET_ADDR        (0x050U)
/* Handling devices with different die offset via Flash page size (0=64, 1=128 or 3=256 bytes) */
#elif ((CPUSS_SPCIF_FLASH_PAGE_SIZE == 0U) || (CPUSS_SPCIF_FLASH_PAGE_SIZE == 1U))
    /** The macro to DIE offset address of the devices with flash page size 64 or 128 bytes */
    #define CY_PDL_DIE_OFFSET_ADDR        (0x178U)
#elif (CPUSS_SPCIF_FLASH_PAGE_SIZE == 3U)
    /** The macro to DIE offset address of the devices with flash page size 256 bytes */
    #define CY_PDL_DIE_OFFSET_ADDR        (0x278U)
#endif /* CPUSS_SPCIF_FLASH_PAGE_SIZE */

/**
* \defgroup group_syslib_macros_status_codes Status codes
* \{
* Function status type codes
*/
#define CY_PDL_STATUS_CODE_Pos  (CY_RSLT_CODE_POSITION)     /**< The module status code position in the status code */
#define CY_PDL_STATUS_TYPE_Pos  (CY_RSLT_TYPE_POSITION)     /**< The status type position in the status code */
#define CY_PDL_MODULE_ID_Pos    (CY_RSLT_MODULE_POSITION)   /**< The software module ID position in the status code */
#define CY_PDL_STATUS_INFO      ((uint32_t)CY_RSLT_TYPE_INFO << CY_PDL_STATUS_TYPE_Pos)     /**< The information status type */
#define CY_PDL_STATUS_WARNING   ((uint32_t)CY_RSLT_TYPE_WARNING << CY_PDL_STATUS_TYPE_Pos)  /**< The warning status type */
#define CY_PDL_STATUS_ERROR     ((uint32_t)CY_RSLT_TYPE_ERROR << CY_PDL_STATUS_TYPE_Pos)    /**< The error status type */
#define CY_PDL_MODULE_ID_Msk    (CY_RSLT_MODULE_MASK)       /**< The software module ID mask */
/** Get the software PDL module ID */
#define CY_PDL_DRV_ID(id)       ((uint32_t)((uint32_t)((id) & CY_PDL_MODULE_ID_Msk) << CY_PDL_MODULE_ID_Pos))
#define CY_SYSLIB_ID            CY_PDL_DRV_ID(0x11U)     /**< SYSLIB PDL ID */
/** \} group_syslib_macros_status_codes */

/** \} group_syslib_macros */

/**
* \addtogroup group_syslib_enumerated_types
* \{
*/

/** The SysLib status code structure. */
typedef enum
{
    CY_SYSLIB_SUCCESS       = 0x00UL,    /**< The success status code */
    CY_SYSLIB_BAD_PARAM     = CY_SYSLIB_ID | CY_PDL_STATUS_ERROR | 0x01UL,    /**< The bad parameter status code */
    CY_SYSLIB_TIMEOUT       = CY_SYSLIB_ID | CY_PDL_STATUS_ERROR | 0x02UL,    /**< The time out status code */
    CY_SYSLIB_INVALID_STATE = CY_SYSLIB_ID | CY_PDL_STATUS_ERROR | 0x03UL,    /**< The invalid state status code */
    CY_SYSLIB_UNKNOWN       = CY_SYSLIB_ID | CY_PDL_STATUS_ERROR | 0xFFUL     /**< Unknown status code */
} cy_en_syslib_status_t;

#if defined(SFLASH_AUTO_SFLASH) || defined(CY_DOXYGEN)
    /** Instances of Boot Result data register. */
    /**
    * \note This Enum is applicable to PSOC4 HVMS/PA only.
    **/
    typedef enum
    {
        CY_SYSLIB_BOOT_RESULT_0 = 0UL, /**< Used to get the Boot Result data for BOOT_RESULT_0 register */
        CY_SYSLIB_BOOT_RESULT_1 = 1UL, /**< Used to get the Boot Result data for BOOT_RESULT_1 register */
    } cy_en_syslib_boot_result_t;

    /** \cond INTERNAL */
    /* Macro to validate parameters in \ref Cy_SysLib_GetBootResult() function */
    #define CY_SYSLIB_IS_BOOT_DATA_SET_VALID(dataSet)   (((dataSet) == CY_SYSLIB_BOOT_RESULT_0) || \
                                                        ((dataSet) == CY_SYSLIB_BOOT_RESULT_1))
    /** \endcond */

#endif /* SFLASH_AUTO_SFLASH */
/** \} group_syslib_enumerated_types */

/**
* \addtogroup group_syslib_data_structures
* \{
*/
#if (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED)
    /** The fault configuration structure. */
    typedef struct
    {
        uint32_t r0;       /**< R0 register content */
        uint32_t r1;       /**< R1 register content */
        uint32_t r2;       /**< R2 register content */
        uint32_t r3;       /**< R3 register content */
        uint32_t r12;      /**< R12 register content */
        uint32_t lr;       /**< LR register content */
        uint32_t pc;       /**< PC register content */
        uint32_t psr;      /**< PSR register content */
    } cy_stc_fault_frame_t;
#endif /* (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED) */

/** \} group_syslib_data_structures */

/**
* \addtogroup group_syslib_macros
* \{
*/

/** The driver major version */
#define CY_SYSLIB_DRV_VERSION_MAJOR    3

/** The driver minor version */
#define CY_SYSLIB_DRV_VERSION_MINOR    30

#if defined (__ICCARM__)
    typedef union { cy_israddress __fun; void * __ptr; } cy_intvec_elem;
#endif  /* defined (__ICCARM__) */

/* MISRA rule 6.3 recommends using specific-length typedef for the basic
 * numerical types of signed and unsigned variants of char, float, and double.
 */
typedef char     char_t;    /**< Specific-length typedef for the basic numerical types of char */
typedef float    float32_t; /**< Specific-length typedef for the basic numerical types of float */
typedef double   float64_t; /**< Specific-length typedef for the basic numerical types of double */


#if (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED)
    #define CY_R0_Pos             (0U)     /**< The position of the R0  content in a fault structure */
    #define CY_R1_Pos             (1U)     /**< The position of the R1  content in a fault structure */
    #define CY_R2_Pos             (2U)     /**< The position of the R2  content in a fault structure */
    #define CY_R3_Pos             (3U)     /**< The position of the R3  content in a fault structure */
    #define CY_R12_Pos            (4U)     /**< The position of the R12 content in a fault structure */
    #define CY_LR_Pos             (5U)     /**< The position of the LR  content in a fault structure */
    #define CY_PC_Pos             (6U)     /**< The position of the PC  content in a fault structure */
    #define CY_PSR_Pos            (7U)     /**< The position of the PSR content in a fault structure */

    extern CY_NOINIT cy_stc_fault_frame_t cy_faultFrame;    /**< Fault frame structure */
#endif /* (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED) */


/**
* \defgroup group_syslib_macros_assert Assert Classes and Levels
* \{
* Defines for the Assert Classes and Levels
*/

/**
* Class 1 - The highest class, safety-critical functions which rely on parameters that could be
* changed between different PSOC devices
*/
#define CY_ASSERT_CLASS_1           (1U)

/** Class 2 - Functions that have fixed limits such as counter periods (16-bits/32-bits etc.) */
#define CY_ASSERT_CLASS_2           (2U)

/** Class 3 - Functions that accept enums as constant parameters */
#define CY_ASSERT_CLASS_3           (3U)

#ifndef CY_ASSERT_LEVEL
    /** The user-definable assert level from compiler command-line argument (similarly to DEBUG / NDEBUG) */
    #define CY_ASSERT_LEVEL         CY_ASSERT_CLASS_3
#endif /* CY_ASSERT_LEVEL */

#if (CY_ASSERT_LEVEL == CY_ASSERT_CLASS_1)
    #define CY_ASSERT_L1(x)         CY_ASSERT(x)        /**< Assert Level 1 */
    #define CY_ASSERT_L2(x)         do{} while(false)   /**< Assert Level 2 */
    #define CY_ASSERT_L3(x)         do{} while(false)   /**< Assert Level 3 */
#elif (CY_ASSERT_LEVEL == CY_ASSERT_CLASS_2)
    #define CY_ASSERT_L1(x)         CY_ASSERT(x)        /**< Assert Level 1 */
    #define CY_ASSERT_L2(x)         CY_ASSERT(x)        /**< Assert Level 2 */
    #define CY_ASSERT_L3(x)         do{} while(false)   /**< Assert Level 3 */
#else /* Default is Level 3 */
    #define CY_ASSERT_L1(x)         CY_ASSERT(x)        /**< Assert Level 1 */
    #define CY_ASSERT_L2(x)         CY_ASSERT(x)        /**< Assert Level 2 */
    #define CY_ASSERT_L3(x)         CY_ASSERT(x)        /**< Assert Level 3 */
#endif /* CY_ASSERT_LEVEL == CY_ASSERT_CLASS_1 */

/** \} group_syslib_macros_assert */


/******************************************************************************
* Constants
*****************************************************************************/
/** Defines a 32-kHz clock delay */
#define CY_DELAY_MS_OVERFLOW            (0x8000U)

/**
* \defgroup group_syslib_macros_reset_cause Reset cause
* \{
* Define RESET_CAUSE mask values
*/
#if defined(CY_IP_S8SRSSLT) || defined(CY_IP_M0S8SRSSHV)
    /** A basic WatchDog Timer (WDT) reset has occurred since the last power cycle. */
    #define CY_SYSLIB_RESET_HWWDT           SRSS_CONCAT(RES_CAUSE_RESET_WDT_Msk)
    /** A protection violation occurred that requires a reset */
    #define CY_SYSLIB_PROT_FAULT            SRSS_CONCAT(RES_CAUSE_RESET_PROT_FAULT_Msk)
    /** The CPU requested a system reset through it's SYSRESETREQ. This can be done via a debugger probe or in firmware. */
    #define CY_SYSLIB_RESET_SOFT            SRSS_CONCAT(RES_CAUSE_RESET_SOFT_Msk)
#endif /* defined(CY_IP_S8SRSSLT) || defined(CY_IP_M0S8SRSSHV) */
#if defined(CY_IP_M0S8SRSSHV)
    /** Reset caused by the Fault Infrastructure.
     * \note Only applicable for PSOC 4 HVMS/PA devices. */
    #define CY_SYSLIB_RESET_ACT_FAULT       SRSSHV_RES_CAUSE_RESET_ACT_FAULT_Msk
    /** Challenge/Response Watchdog reset.
     * \note Only applicable for PSOC 4 HVMS/PA devices. */
    #define CY_SYSLIB_RESET_CRWDT           SRSSHV_RES_CAUSE_RESET_CRWDT_Msk
    /** External XRES pin was asserted.
     * \note Only applicable for PSOC 4 HVMS/PA devices. */
    #define CY_SYSLIB_RESET_XRES            SRSSHV_RES_CAUSE_RESET_XRES_Msk
    /** Internal VDDD supply crossed brown-out limit.
     * \note Only applicable for PSOC 4 HVMS/PA devices. */
    #define CY_SYSLIB_RESET_BODVDDD         SRSSHV_RES_CAUSE_RESET_BODVDDD_Msk
    /** Internal VCCD core supply crossed the brown-out limit.
     * \note Only applicable for PSOC 4 HVMS/PA devices. */
    #define CY_SYSLIB_RESET_BODVCCD         SRSSHV_RES_CAUSE_RESET_BODVCCD_Msk
    /** Overvoltage detection on the external VDDD supply.
     * \note Only applicable for PSOC 4 HVMS/PA devices. */
    #define CY_SYSLIB_RESET_OVDVDDD         SRSSHV_RES_CAUSE_RESET_OVDVDDD_Msk
    /** Overvoltage detection on the internal core VCCD supply.
     * \note Only applicable for PSOC 4 HVMS/PA devices. */
    #define CY_SYSLIB_RESET_OVDVCCD         SRSSHV_RES_CAUSE_RESET_OVDVCCD_Msk
    /** Internal VDDD supply crossed brown-out limit.
     * This detector is a backup detector in the high voltage sub-system that is
     * on even in deep sleep. This detector is used for engineering debug purposes only.
     * \note Only applicable for PSOC 4 HVMS/PA devices. */
    #define CY_SYSLIB_RESET_BODHVSS         SRSSHV_RES_CAUSE_RESET_BODHVSS_Msk
    /** Indicator that a POR occurred.
     * \note Only applicable for PSOC 4 HVMS/PA devices. */
    #define CY_SYSLIB_RESET_PORVDDD         SRSSHV_RES_CAUSE_RESET_PORVDDD_Msk
#endif /* defined(CY_IP_M0S8SRSSHV) */

/** \cond INTERNAL */
#if defined(CY_IP_S8SRSSLT)
    /** Define Reset Reason mask */
    #define CY_SYSLIB_RESET_REASON_MASK    (CY_SYSLIB_RESET_HWWDT | CY_SYSLIB_PROT_FAULT | CY_SYSLIB_RESET_SOFT)
#elif defined(CY_IP_M0S8SRSSHV)
    /** Define Reset Reason mask */
    #define CY_SYSLIB_RESET_REASON_MASK    (CY_SYSLIB_RESET_HWWDT     | CY_SYSLIB_PROT_FAULT    | CY_SYSLIB_RESET_SOFT    |\
                                            CY_SYSLIB_RESET_ACT_FAULT | CY_SYSLIB_RESET_CRWDT   | CY_SYSLIB_RESET_XRES    |\
                                            CY_SYSLIB_RESET_BODVDDD   | CY_SYSLIB_RESET_BODVCCD | CY_SYSLIB_RESET_OVDVDDD |\
                                            CY_SYSLIB_RESET_OVDVCCD   | CY_SYSLIB_RESET_BODHVSS | CY_SYSLIB_RESET_PORVDDD )
#endif /* defined(CY_IP_S8SRSSLT) */
/** \endcond */

/** \} group_syslib_macros_reset_cause */

/** \} group_syslib_macros */

/** \cond */
CY_MISRA_FP_BLOCK_START('MISRA C-2012 Rule 8.6', 3, \
'Coverity does not check the assembly files, the definitions of the \
Cy_SysLib_DelayCycles, Cy_SysLib_EnterCriticalSection, and \
Cy_SysLib_ExitCriticalSection functions are a part of syslib assembly \
source file.');
/** \endcond */

/******************************************************************************
* Function prototypes
******************************************************************************/

/**
* \addtogroup group_syslib_functions
* \{
*/

void Cy_SysLib_Delay(uint32_t milliseconds);
void Cy_SysLib_DelayUs(uint16_t microseconds);
/** Delays for the specified number of cycles.
 *  The function is implemented in the assembler for each supported compiler.
 *  \param cycles  The number of cycles to delay.
 */
void Cy_SysLib_DelayCycles(uint32_t cycles);
void Cy_SysLib_ClearFlashCacheAndBuffer(void);
uint32_t Cy_SysLib_GetResetReason(void);
void Cy_SysLib_ClearResetReason(void);
#if (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED) || defined(CY_DOXYGEN)
    void Cy_SysLib_FaultHandler(uint32_t const *faultStackAddr);
    void Cy_SysLib_ProcessingFault(void);
#endif /* (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED) */
void Cy_SysLib_SetWaitStates(uint32_t clkHfMHz);

#if defined(SFLASH_AUTO_SFLASH) || defined(CY_DOXYGEN)
    uint32_t Cy_SysLib_GetBootStatus(void);
    uint32_t Cy_SysLib_GetBootResult(cy_en_syslib_boot_result_t bootResultSet);
#endif /* SFLASH_AUTO_SFLASH */

/*******************************************************************************
* Function Name: Cy_SysLib_EnterCriticalSection
****************************************************************************//**
*
*  Cy_SysLib_EnterCriticalSection disables interrupts and returns a value
*  indicating whether the interrupts were previously enabled.
*
*  \return Returns the current interrupt status. Returns 0 if the interrupts
*          were previously enabled or 1 if the interrupts were previously
*          disabled.
*
*  \note Implementation of Cy_SysLib_EnterCriticalSection manipulates the IRQ
*        enable bit with interrupts still enabled.
*
*******************************************************************************/
uint32_t Cy_SysLib_EnterCriticalSection(void);


/*******************************************************************************
* Function Name: Cy_SysLib_ExitCriticalSection
****************************************************************************//**
*
*  Re-enables the interrupts if they were enabled before
*  Cy_SysLib_EnterCriticalSection() was called. The argument should be the value
*  returned from \ref Cy_SysLib_EnterCriticalSection().
*
*  \param savedIntrStatus  Puts the saved interrupts status returned by
*                          the \ref Cy_SysLib_EnterCriticalSection().
*
*******************************************************************************/
void Cy_SysLib_ExitCriticalSection(uint32_t savedIntrStatus);

/*******************************************************************************
* Function Name: Cy_SysLib_GetUniqueId
****************************************************************************//**
*
* This function returns the silicon unique ID.
* The ID includes Die lot[3]#, Die Wafer#, Die X, Die Y, Die Sort# and Die Minor.
*
* \return  A combined 64-bit unique ID.
*          [63:56] - DIE_MINOR
*          [55:48] - DIE_SORT
*          [47:40] - DIE_Y
*          [39:32] - DIE_X
*          [31:24] - DIE_WAFER
*          [23:16] - DIE_LOT[2]
*          [15: 8] - DIE_LOT[1]
*          [ 7: 0] - DIE_LOT[0]
*******************************************************************************/
uint64_t Cy_SysLib_GetUniqueId(void);

/** \} group_syslib_functions */

/** \cond */
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.6');
/** \endcond */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CY_SYSLIB_H */

/** \} group_syslib */

/* [] END OF FILE */
