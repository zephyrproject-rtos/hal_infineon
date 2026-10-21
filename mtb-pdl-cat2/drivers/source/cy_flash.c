/***************************************************************************//**
* \file cy_flash.c
* \version 1.30
*
* \brief
* Provides the public functions for the API for the Flash driver.
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
#include "cy_flash.h"
#include "cy_sysclk.h"
#include "cy_device.h"
#include "cy_syslib.h"

#include <string.h>

/***************************************
* Macro definitions
***************************************/

/** \cond INTERNAL */

/** Command completed with no errors */
#define SROMCODE_SUCCESS                        (0xA0000000UL)
/** Command completed with error flag */
#define SROMCODE_ERROR_FLAG                     (0xF0000000UL)
/** Invalid device protection state */
#define SROMCODE_INVALID_PROTECTION             (0xF0000001UL)
/** Invalid flash page latch address */
#define SROMCODE_INVALID_FM_PL                  (0xF0000003UL)
/** Invalid flash address */
#define SROMCODE_INVALID_FLASH_ADDR             (0xF0000004UL)
/** Row is write protected */
#define SROMCODE_ROW_PROTECTED                  (0xF0000005UL)
/** All non-blocking API have completed */
#define SROMCODE_RESUME_COMPLETE                (0xF0000007UL)
/** A resume or non-blocking is still in progress. */
#define SROMCODE_PENDING_RESUME                 (0xF0000008UL)
/** Command in progress; no error */
#define SROMCODE_SYSCALL_IN_PROGRESS            (0xF0000009UL)
/** API not instantiated */
#define SROMCODE_API_NOT_INSTANTIATED           (0xF0000011UL)
/** Invalid Flash Clock */
#define SROMCODE_INVALID_CLOCK                  (0xF0000012UL)
/** Command invalid for SPCIF_SYNCHRONOUS=0. */
#define SROMCODE_INVALID_FLASH_IP               (0xF0000013UL)
/** Command Not Available in DEAD Mode */
#define SROMCODE_NA_IN_DEAD_MODE                (0xF0000014UL)
/** SROM return status mask for ERROR/SUCCESS */
#define SROMCODE_STATUS_MASK                    (0xF0000000UL)
/** \endcond */

#define CY_FLASH_SRAM_ROM_KEY1                          (0U)
#define CY_FLASH_SRAM_ROM_DATA                          (CY_FLASH_SRAM_ROM_KEY1 + 0x08U)

/* SROM API parameters offsets */
#define CY_FLASH_PARAM_KEY_TWO_OFFSET                   (8U)
#define CY_FLASH_PARAM_ADDR_OFFSET                      (16U)
#define CY_FLASH_PARAM_MACRO_SEL_OFFSET                 (24U)
#define CY_FLASH_PAGE_LATCH_START_ADDR                  (0UL)

/* Opcodes */
#define CY_FLASH_API_OPCODE_LOAD                        (0x04U)
#define CY_FLASH_API_OPCODE_WRITE_ROW                   (0x05U)
#define CY_FLASH_API_OPCODE_NON_BLOCKING_WRITE_ROW      (0x07U)
#define CY_FLASH_API_OPCODE_RESUME_NON_BLOCKING         (0x09U)

#define CY_FLASH_API_OPCODE_PROGRAM_ROW                 (0x06U)
#define CY_FLASH_API_OPCODE_WRITE_SFLASH_ROW            (0x18U)

#define CY_FLASH_API_OPCODE_CHECKSUM                    (0x0BU)
#define CY_FLASH_API_OPCODE_ERASE_SECTOR                (0x14U)

#define CY_FLASH_API_OPCODE_CLK_CONFIG                  (0x15U)
#define CY_FLASH_API_OPCODE_CLK_BACKUP                  (0x16U)
#define CY_FLASH_API_OPCODE_CLK_RESTORE                 (0x17U)


#define CY_FLASH_CPUSS_REQ_START                        ((uint32_t) ((uint32_t) 0x1U << 31U))
#define CY_FLASH_CPUSS_SYSARG_CHECKSUM_MASK             (0x00FFFFFFUL)

#define CY_FLASH_KEY_ONE                                (0xB6U)
#define CY_FLASH_KEY_TWO(x)                             ((uint32_t) (((uint16_t) 0xD3U) + ((uint16_t) (x))))

/* Calculates proportional number of macros based on actual flash size */
#define CY_FLASH_CALC_MACROS_BY_SIZE            ((CY_FLASH_SIZE * CY_FLASH_NUMBER_MACROS) / ((CPUSS_SPCIF_FLASH_SIZE + 1U) * 256U))
/* Calculate real number of the macros */
#define CY_GET_MAX_MACROS_NUMBER                (((CY_FLASH_SIZE == (CPUSS_SPCIF_FLASH_SIZE + 1U) * 256U) ? CY_FLASH_NUMBER_MACROS : \
                                                  (CY_FLASH_CALC_MACROS_BY_SIZE > 0U) ? CY_FLASH_CALC_MACROS_BY_SIZE : 1U))

#define CY_SFLASH_GET_MACRO_FROM_ADDR(addr)     (((addr) - CY_SFLASH_BASE) / (CY_SFLASH_SIZE / CY_GET_MAX_MACROS_NUMBER))

#define CY_FLASH_GET_MACRO_FROM_ADDR(addr)      (((addr) - CY_FLASH_BASE) / (CY_FLASH_SIZE / CY_GET_MAX_MACROS_NUMBER))

#define CY_GET_MACRO_FROM_ADDR(addr)            (((addr) >= CY_SFLASH_BASE && (addr) < (CY_SFLASH_BASE + CY_SFLASH_SIZE)) ? \
                                                 CY_SFLASH_GET_MACRO_FROM_ADDR(addr) : CY_FLASH_GET_MACRO_FROM_ADDR(addr))

/* key write value to SPCIF_FLASH_LOCK register */
#define CY_FLASH_PROTECTION_LOCK_KEY                    (0xF56B3A81UL)
/* Macro value of mask for flash address */
#define CY_FLASH_WORD_ADDR_CHECK_MSK                    (0x00000007U)
/* Used to get the flash word address for ECC injection   */
#define CY_CPU_FLASH_WORD_ADDR_CHECK_POS                (0x00000003U)

#define CY_FLASH_CLOCK_BACKUP_SIZE      (6U)

/* Number of attempts to wait for the system call to finish */
#define CY_FLASH_SYS_CALL_RETRY_LIMIT (1000U)

typedef struct Cy_Flash_ClockBackupStruct
{
    uint32_t clockSettings[CY_FLASH_CLOCK_BACKUP_SIZE];       /* FM-Lite Clock Backup */
} CY_SYS_FLASH_CLOCK_BACKUP_STRUCT;
static CY_SYS_FLASH_CLOCK_BACKUP_STRUCT cySysFlashBackup;

static uint32_t Cy_Flash_GetRowNum(uint32_t flashAddr);
static cy_en_flashdrv_status_t ProcessStatusCode(void);
static cy_en_flashdrv_status_t Cy_Flash_ClockBackup(void);
static cy_en_flashdrv_status_t Cy_Flash_ClockConfig(void);
static cy_en_flashdrv_status_t Cy_Flash_ClockRestore(void);
static bool Cy_Flash_ValidAddr(uint32_t flashAddr);
static bool Cy_Flash_ValidFlashAddr(uint32_t flashAddr);


#if defined(CPUSS_SPCIF_FLASH_S8FS_VER2)
/******************************************************************************
* Function Name: Cy_Flash_GetMacroNumFromRowNum
********************************************************************************
*
* \brief
*  Get flash macro number from row number
* \param [in] rowNum
*  The flash row number.
* \return
*  flash macro number
*
*******************************************************************************/
static uint32_t Cy_Flash_GetMacroNumFromRowNum(uint32_t rowNum)
{
    /* The number of the flash macro cell, which contains the required row */
    uint32_t flashMacroNum = 0UL;
    /* flashMacroLowNum - the number of rows in one flash macro cell*/
    uint32_t flashMacroLowNum = CY_FLASH_SIZEOF_MACRO;
    uint32_t tmpRowNum = rowNum;

    /*
     * Decrement RowNum until the remainder is less than the size
     * The number of decrements will represent the number of cells
     */
    while(tmpRowNum >= flashMacroLowNum)
    {
        tmpRowNum -= flashMacroLowNum;
        flashMacroNum++;
    }

    return (flashMacroNum);
}
#endif /* defined(CPUSS_SPCIF_FLASH_S8FS_VER2) */

/*******************************************************************************
* Function Name: Cy_Flash_WriteRow
****************************************************************************//**
*
* \brief Erases a row of Flash or Supervisory Flash and programs it with the
* new data. Does not return until the write operation is complete. Refer to the
* device datasheet for the details.
*
* This API will automatically enable IMO and modify the clock settings for the
* device. Writing to Flash requires 48 MHz IMO and changes be made to the HFCLK
* settings. The configuration is restored before returning. HFCLK will have
* several frequency changes during the operation of this API between a minimum
* frequency of the current IMO frequency divided by 8 and a maximum frequency of
* 12 MHz. This will impact the operation of most of the hardware in the device.
*
* \param rowAddr Address of the Flash or Supervisory Flash row to which the data
* needs to be written. The address shall be aligned to the beginning of the row.
*
* \param data Array of bytes to write. The size of the array must be equal to
* the Flash row size defined by \ref CY_FLASH_SIZEOF_ROW.
*
* \return \ref group_flash_enumerated_types
*
* \funcusage
* \snippet flash_snippet.c SNIPPET_FLASH_INIT
* \snippet flash_snippet.c SNIPPET_FLASH_WRITE
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_WriteRow(uint32_t rowAddr, const uint32_t* data)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_DEV_NOT_SUPPORTED;

    volatile uint32_t parameters[(CY_FLASH_SIZEOF_ROW + CY_FLASH_SRAM_ROM_DATA) / sizeof(uint32_t)];
    uint32_t interruptState;
    uint32_t rowNum = Cy_Flash_GetRowNum(rowAddr);

    if ((Cy_Flash_ValidAddr(rowAddr)) && (NULL != data))
    {
        /* Copy data to be written into internal variable */
        (void) memcpy((void *) &parameters[2U], (const void *) data, CY_FLASH_SIZEOF_ROW);
        CY_MISRA_FP_LINE('MISRA C-2012 Rule 14.3', 'CY_GET_MACRO_FROM_ADDR is device-specific, and so it may be invariant.');
        parameters[0U] = (uint32_t) (CY_GET_MACRO_FROM_ADDR(rowAddr)            << CY_FLASH_PARAM_MACRO_SEL_OFFSET) |
                         (uint32_t) (CY_FLASH_PAGE_LATCH_START_ADDR             << CY_FLASH_PARAM_ADDR_OFFSET     ) |
                         (uint32_t) (CY_FLASH_KEY_TWO(CY_FLASH_API_OPCODE_LOAD) << CY_FLASH_PARAM_KEY_TWO_OFFSET  ) |
                         CY_FLASH_KEY_ONE;
        parameters[1U] = CY_FLASH_SIZEOF_ROW - 1U;

        CPUSS_SYSARG = (uint32_t) &parameters[0U];
        CPUSS_SYSREQ = CY_FLASH_CPUSS_REQ_START | CY_FLASH_API_OPCODE_LOAD;

        result = ProcessStatusCode();
        if(CY_FLASH_DRV_SUCCESS == result)
        {
            interruptState = Cy_SysLib_EnterCriticalSection();
            result = Cy_Flash_ClockBackup();
            if (CY_FLASH_DRV_SUCCESS == result)
            {
                result = Cy_Flash_ClockConfig();
                if (CY_FLASH_DRV_SUCCESS == result)
                {
                    cy_en_flashdrv_status_t resultClockRestore;

                    /* Write Row */
                    CPUSS_SYSARG = (uint32_t) &parameters[0U];
                    if (rowAddr >= CY_SFLASH_BASE)
                    {
                        /* Supervisory Flash */
                        parameters[0U] = (uint32_t) (((uint32_t) CY_FLASH_KEY_TWO(CY_FLASH_API_OPCODE_WRITE_SFLASH_ROW) <<  CY_FLASH_PARAM_KEY_TWO_OFFSET) | CY_FLASH_KEY_ONE);
                        parameters[1U] = (uint32_t) rowNum;
                        CPUSS_SYSREQ = CY_FLASH_CPUSS_REQ_START | CY_FLASH_API_OPCODE_WRITE_SFLASH_ROW;
                    }
                    else
                    {
                        /* Flash */
                        parameters[0U]  = (uint32_t) (((uint32_t) CY_FLASH_KEY_TWO(CY_FLASH_API_OPCODE_WRITE_ROW) <<  CY_FLASH_PARAM_KEY_TWO_OFFSET) | CY_FLASH_KEY_ONE);
                        parameters[0U] |= (uint32_t)(rowNum << 16U);
                        CPUSS_SYSREQ = CY_FLASH_CPUSS_REQ_START | CY_FLASH_API_OPCODE_WRITE_ROW;
                    }

                    result = ProcessStatusCode();
                    resultClockRestore = Cy_Flash_ClockRestore();
                    if (CY_FLASH_DRV_SUCCESS == result)
                    {
                        result = resultClockRestore;
                    }
#if defined(CPUSS_SPCIF_FLASH_S8FS_VER2)
                    /*
                     * if the whole flash macro cell is locked, the return code from SROM is UNKNOWN
                     */
                    else
                    {
                        /*
                         * Check if the macro cell is protected
                         * 1 - unprotected
                         * 0 - protected
                         */
                        uint32_t protection;
                        uint32_t macroNum;
                        /* It is safe to suppress return code as the pointer is always valid */
                        (void)Cy_Flash_GetProtectionStatus(&protection);
                        macroNum = Cy_Flash_GetMacroNumFromRowNum(rowNum);
                        /*
                         * macroNum bit into the protection represent state
                         * of the macroNum flash macro cell
                         */
                        if(0U == CY_CHECK_BIT(protection,macroNum))
                        {
                            /* If the macro is protected, replace the error code by more readable */
                            result = CY_FLASH_DRV_ROW_PROTECTED;
                        }
                    }
#endif /* defined(CPUSS_SPCIF_FLASH_S8FS_VER2) */
                }
            }
            Cy_SysLib_ExitCriticalSection(interruptState);
        }
    }
    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_StartWrite
****************************************************************************//**
*
* Initiates a write to a row of Flash. A call to this API is non-blocking.
* Use \ref Cy_Flash_ResumeWrite() to resume Flash writes and
* \ref Cy_Flash_IsOperationComplete() to ascertain status of the write
* operation. Supervisory Flash does not support non-blocking write.
*
* This API will automatically enable IMO and modify the clock settings for the
* device. Writing to Flash requires 48 MHz IMO and changes be made to the HFCLK
* settings. The configuration is restored to original configuration by calling
* \ref Cy_Flash_IsOperationComplete(). HFCLK will have several frequency changes
* during the operation of these API between a minimum frequency of the current
* IMO frequency divided by 8 and a maximum frequency of 12 MHz. This will impact
* the operation of most of the hardware in the device.
*
* This API will automatically enable IMO and modify the clock settings for the
* device. Writing to Flash requires 48 MHz IMO and changes be made to the HFCLK
* settings. The configuration is restored to original configuration by calling
* \ref Cy_Flash_IsOperationComplete(). HFCLK will have several frequency
* changes during the operation of this API and \ref Cy_Flash_IsOperationComplete()
* API between a minimum frequency of the current IMO frequency divided by 8 and
* a maximum frequency of 12 MHz. This will impact the operation of most of the
* hardware in the device.
*
* The devices require HFCLK to be sourced by 48 MHz IMO during Flash write.
* The IMO must be enabled before calling this function. This API will modify
* IMO configuration; it can be later restored to original configuration by
* calling \ref Cy_Flash_IsOperationComplete().
*
* The non-blocking write row API \ref Cy_Flash_StartWrite() requires
* \ref Cy_Flash_ResumeWrite() to be called 3 times to complete the write. This
* can be done by configuring SPCIF interrupt and placing a call to this API.
*
* For Cortex-M0+ based devices, if the user wants to keep the vector table in
* Flash when performing non-blocking Flash write then they need to make sure the
* vector table is placed in the Flash macro which is not getting programmed by
* configuring the VTOR register.
*
* \param rowAddr Address of the Flash row to which the data needs to be written.
* The address shall be aligned to the beginning of the row. Supervisory Flash is
* not supported.
*
* \param data Array of bytes to write. The size of the array must be equal to
* the Flash row size. The Flash row size for the selected device is defined by
* the \ref CY_FLASH_SIZEOF_ROW macro. Refer to the device datasheet for the
* details.
*
* \return \ref group_flash_enumerated_types.
* Returns \ref CY_FLASH_DRV_OPERATION_STARTED in case of successful start.
*
* \note The non-blocking operation does not return success status
* CY_FLASH_DRV_SUCCESS until the last \ref Cy_Flash_ResumeWrite() API
* is complete. The CPUSS_SYSARG register will be reflecting the SRAM address
* during an ongoing non-blocking operation.
*
* \funcusage
* \snippet flash_snippet.c SNIPPET_FLASH_INIT
* \snippet flash_snippet.c SNIPPET_FLASH_NONBLOCKING_INIT
* \snippet flash_snippet.c SNIPPET_FLASH_NONBLOCKING
* \note This function can be called when code is executed only from different
* flash array or from the RAM till the end of flash write. The information
* regarding flash architecture you can find in the device TRM.
* Alternatively you can see macro \ref CY_FLASH_NON_BLOCKING_SUPPORTED return
* value: if it returns 'true' this means the device you are using has other
* flash array to use, if not - the only way is to use RAM memory for both flash
* driver and the code that will be executed during flash write.
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_StartWrite(uint32_t rowAddr, const uint32_t* data)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_SUCCESS;
    volatile uint32_t parameters[(CY_FLASH_SIZEOF_ROW + CY_FLASH_SRAM_ROM_DATA) / sizeof(uint32_t)];
    uint32_t interruptState;
    uint32_t rowNum = Cy_Flash_GetRowNum(rowAddr);

    if ((Cy_Flash_ValidFlashAddr(rowAddr)) && (NULL != data))
    {
        /* Copy data to be written into internal variable */
        (void) memcpy((void *) &parameters[2U], (const void *) data, CY_FLASH_SIZEOF_ROW);

        /* Load Flash Bytes */
        CY_MISRA_FP_LINE('MISRA C-2012 Rule 14.3', 'CY_GET_MACRO_FROM_ADDR is device-specific, and so it may be invariant.');
        parameters[0U] = (uint32_t) (CY_GET_MACRO_FROM_ADDR(rowAddr)            << CY_FLASH_PARAM_MACRO_SEL_OFFSET) |
                         (uint32_t) (CY_FLASH_PAGE_LATCH_START_ADDR             << CY_FLASH_PARAM_ADDR_OFFSET     ) |
                         (uint32_t) (CY_FLASH_KEY_TWO(CY_FLASH_API_OPCODE_LOAD) << CY_FLASH_PARAM_KEY_TWO_OFFSET  ) |
                         CY_FLASH_KEY_ONE;
        parameters[1U] = CY_FLASH_SIZEOF_ROW - 1U;

        CPUSS_SYSARG = (uint32_t) &parameters[0U];
        CPUSS_SYSREQ = CY_FLASH_CPUSS_REQ_START | CY_FLASH_API_OPCODE_LOAD;

        result = ProcessStatusCode();

        if(result == CY_FLASH_DRV_SUCCESS)
        {
            /***************************************************************
            * Mask all the exceptions to guarantee that Flash write will
            * occur in the atomic way. It will not affect system call
            * execution (flash row write) since it is executed in the NMI
            * context.
            ***************************************************************/
            interruptState = Cy_SysLib_EnterCriticalSection();

            result = Cy_Flash_ClockBackup();
        #if(CPUSS_SPCIF_SYNCHRONOUS)
            if(result == CY_FLASH_DRV_SUCCESS)
            {
                result = Cy_Flash_ClockConfig();
            }
        #endif  /* (CPUSS_SPCIF_SYNCHRONOUS) */
            if(result == CY_FLASH_DRV_SUCCESS)
            {
                /* Non-blocking Write Row */
                parameters[0U]  = (uint32_t) (((uint32_t) CY_FLASH_KEY_TWO(CY_FLASH_API_OPCODE_NON_BLOCKING_WRITE_ROW) <<
                                                        CY_FLASH_PARAM_KEY_TWO_OFFSET) | CY_FLASH_KEY_ONE);
                parameters[0U] |= (uint32_t)(rowNum << 16U);

                CPUSS_SYSARG = (uint32_t) &parameters[0U];
                CPUSS_SYSREQ = CY_FLASH_CPUSS_REQ_START | CY_FLASH_API_OPCODE_NON_BLOCKING_WRITE_ROW;

                result = ProcessStatusCode();
            }

            Cy_SysLib_ExitCriticalSection(interruptState);
        }
    }
    else
    {
        result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
    }

    return result;
}


/*******************************************************************************
* Function Name: Cy_Flash_ResumeWrite
****************************************************************************//**
*
* The non-blocking write row API \ref Cy_Flash_StartWrite() requires that
* this function be called 3 times to complete the write. This can be done by
* configuring SPCIF interrupt and placing a call to this API.
*
* It is advised not to prolong calling this API for more than 25 ms.
*
* \note The non-blocking operation does not return success status
* CY_FLASH_DRV_SUCCESS until the last Resume API is complete.
* The CPUSS_SYSARG register will be reflecting the SRAM address during an
* ongoing non-blocking operation.
*
* \return \ref group_flash_enumerated_types
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_ResumeWrite(void)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_SUCCESS;
    static volatile uint32_t parameters[1U];

    /* Resume */
    parameters[0U] = (uint32_t) (((uint32_t) CY_FLASH_KEY_TWO(CY_FLASH_API_OPCODE_RESUME_NON_BLOCKING) <<
                                         CY_FLASH_PARAM_KEY_TWO_OFFSET) | CY_FLASH_KEY_ONE);
    CPUSS_SYSARG = (uint32_t) &parameters[0U];
    CPUSS_SYSREQ = CY_FLASH_CPUSS_REQ_START | CY_FLASH_API_OPCODE_RESUME_NON_BLOCKING;

    result = ProcessStatusCode();

    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_IsOperationComplete
****************************************************************************//**
*
* Returns the current status of the Flash write operation.
*
* \note The non-blocking operation does not return success status
* \ref CY_FLASH_DRV_SUCCESS until the last \ref Cy_Flash_ResumeWrite() is
* complete. The CPUSS_SYSARG register will be reflecting the SRAM address
* during an ongoing non-blocking operation.
*
* Calling this API before starting a non-blocking write row operation
* using the \ref Cy_Flash_StartWrite API will cause improper operation.
*
* \return \ref cy_en_flashdrv_status_t
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_IsOperationComplete(void)
{
    cy_en_flashdrv_status_t result;
    volatile cy_en_flashdrv_status_t resultClockRestore;
    bool operationCompleted;

    result = ProcessStatusCode();
    operationCompleted =    (CY_FLASH_DRV_OPERATION_STARTED != result) &&
                            (CY_FLASH_DRV_PROGRESS_NO_ERROR != result) &&
                            (CY_FLASH_DRV_PENDING_RESUME    != result);
    if (operationCompleted)
    {
        /* Operation completed with success or error. Clock should be restored
         * in any case. */
        resultClockRestore = Cy_Flash_ClockRestore();
        /* Return result of clock restore operation, only in case of
         * operation success. Operation error has a return priority. */
        if (CY_FLASH_DRV_SUCCESS == result)
        {
            result = resultClockRestore;
        }
    }

    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_ValidFlashAddr
********************************************************************************
*
* Checks if the specified address is valid Flash address.
*
* \return Returns True if the specified address is valid.
*
*******************************************************************************/
static bool Cy_Flash_ValidFlashAddr(uint32_t flashAddr)
{
    bool valid = false;

    if (flashAddr < (CY_FLASH_BASE + CY_FLASH_SIZEOF_FLASH))
    {
        if ((flashAddr % CY_FLASH_SIZEOF_ROW) == 0UL)
        {
            valid = true;
        }
    }

    return (valid);
}


/*******************************************************************************
* Function Name: Cy_Flash_RowChecksum
****************************************************************************//**
*
* Returns a checksum value of the specified Flash or Supervisory Flash row.
*
* \param rowAddr The address of the row. The address shall be aligned to the
* beginning of the row.
*
* \param checksumPtr The pointer to the address where checksum is to be stored.
*
* \return \ref cy_en_flashdrv_status_t
*
* \funcusage
* \snippet flash_snippet.c SNIPPET_FLASH_CHECKSUM
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_RowChecksum(uint32_t rowAddr, uint32_t* checksumPtr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_DEV_NOT_SUPPORTED;
    volatile uint32_t parameters[1U];
    uint32_t rowNum = Cy_Flash_GetRowNum(rowAddr);

    if (Cy_Flash_ValidAddr(rowAddr))
    {
        /* Checksum */
        parameters[0U]  = (uint32_t) (((uint32_t) CY_FLASH_KEY_TWO(CY_FLASH_API_OPCODE_CHECKSUM) <<  CY_FLASH_PARAM_KEY_TWO_OFFSET) | CY_FLASH_KEY_ONE);
        parameters[0U] |= (uint32_t)(rowNum << 16U);

        CPUSS_SYSARG = (uint32_t) parameters[0U];
        CPUSS_SYSREQ = CY_FLASH_CPUSS_REQ_START | CY_FLASH_API_OPCODE_CHECKSUM;

        result = ProcessStatusCode();
        if (CY_FLASH_DRV_SUCCESS == result)
        {
            *checksumPtr = CPUSS_SYSARG & CY_FLASH_CPUSS_SYSARG_CHECKSUM_MASK;
        }
    }

    return (result);
}

/*******************************************************************************
* Function Name: WaitForSysCallFinish
****************************************************************************//**
*
* Waits for the system call to complete.
*
* This function ensures that the system call operation has been finished by
* polling the CPUSS_SYSREQ register until the SYSCALL_REQ and PRIVILEGED bits
* are cleared.
*
* \return \ref cy_en_flashdrv_status_t
*
*******************************************************************************/
static cy_en_flashdrv_status_t WaitForSysCallFinish(void)
{
    uint32_t attempts = CY_FLASH_SYS_CALL_RETRY_LIMIT;
    uint32_t statusCode;
    __DMB(); // Data memory barrier to ensure the latest status is read
    do
    {
        statusCode = CPUSS_SYSREQ & (CPUSS_SYSREQ_SYSCALL_REQ_Msk | CPUSS_SYSREQ_PRIVILEGED_Msk);
        if (attempts == 0u)
        {
            break;
        }
        attempts--;
    } while (statusCode != 0u);

    return ((statusCode == 0u) ? CY_FLASH_DRV_SUCCESS : CY_FLASH_DRV_PROGRESS_NO_ERROR);
}

/*******************************************************************************
* Function Name: ProcessStatusCode
****************************************************************************//**
*
* Converts System Call returns to the Flash driver return defines.
*
* \return \ref cy_en_flashdrv_status_t
*
*******************************************************************************/
static cy_en_flashdrv_status_t ProcessStatusCode(void)
{
    cy_en_flashdrv_status_t result = WaitForSysCallFinish();

    if (CY_FLASH_DRV_SUCCESS == result)
    {
        uint32_t statuscode = CPUSS_SYSARG;

        if ((statuscode & SROMCODE_STATUS_MASK) == SROMCODE_SUCCESS)
        {
            result = CY_FLASH_DRV_SUCCESS;
        }
        else if ((statuscode & SROMCODE_STATUS_MASK) == SROMCODE_ERROR_FLAG)
        {
            /* Process error code */
            switch (statuscode)
            {
                case SROMCODE_INVALID_PROTECTION:
                    result = CY_FLASH_DRV_INVALID_PROT;
                    break;
                case SROMCODE_INVALID_FM_PL:
                case SROMCODE_INVALID_FLASH_ADDR:
                    result = CY_FLASH_DRV_INVALID_FLASH_ADDR;
                    break;
                case SROMCODE_ROW_PROTECTED:
                    result = CY_FLASH_DRV_ROW_PROTECTED;
                    break;
                case SROMCODE_RESUME_COMPLETE:
                    result = CY_FLASH_DRV_SUCCESS;
                    break;
                case SROMCODE_PENDING_RESUME:
                    result = CY_FLASH_DRV_PENDING_RESUME;
                    break;
                case SROMCODE_SYSCALL_IN_PROGRESS:
                    result = CY_FLASH_DRV_PROGRESS_NO_ERROR;
                    break;
                case SROMCODE_API_NOT_INSTANTIATED:
                case SROMCODE_INVALID_FLASH_IP:
                case SROMCODE_NA_IN_DEAD_MODE:
                    result = CY_FLASH_DRV_DEV_NOT_SUPPORTED;
                    break;
                default:
                    result = CY_FLASH_DRV_ERROR_UNKNOWN;
                    break;
            }
        }
        else
        {
            /* Not an error or success - the operation in not finished */
            result = CY_FLASH_DRV_OPERATION_STARTED;
        }
    }

    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_ValidAddr
********************************************************************************
*
* Checks if the specified Flash address is valid.
*
* \param flashAddr Flash row address.
*
* \return Returns true if the specified address is valid.
*
*******************************************************************************/
static bool Cy_Flash_ValidAddr(uint32_t flashAddr)
{
    bool valid = false;

    if (flashAddr < (CY_FLASH_BASE + CY_FLASH_SIZEOF_FLASH))
    {
        if ((flashAddr % CY_FLASH_SIZEOF_ROW) == 0UL)
        {
            valid = true;
        }
    }
    else
    #if (defined (SFLASH_FLASH_M0_XTRA_ROWS) && (SFLASH_FLASH_M0_XTRA_ROWS == 1U)) || defined (SFLASH_USER_SFLASH_AREA_LOCATION_Pos)
        if (((flashAddr >= CY_FLASH_SFLASH_USERBASE) && (flashAddr < (CY_FLASH_SFLASH_USERBASE + CY_FLASH_SIZEOF_USERSFLASH)))
    #if (defined (SFLASH_USER_SFLASH_AREA_LOCATION_Pos))
            || ((flashAddr >= CY_FLASH_SFLASH_USERBASE1) && (flashAddr < (CY_FLASH_SFLASH_USERBASE1 + CY_FLASH_SIZEOF_USERSFLASH1)))
    #endif /* defined (SFLASH_USER_SFLASH_AREA_LOCATION_Pos */
            )
        {
            if ((flashAddr % CY_FLASH_SIZEOF_ROW) == 0UL)
            {
                valid = true;
            }
        }
        else
    #endif /* defined (SFLASH_FLASH_M0_XTRA_ROWS) && (SFLASH_FLASH_M0_XTRA_ROWS == 1U) || defined (SFLASH_USER_SFLASH_AREA_LOCATION_Pos) */
    {
        valid = false;
    }

    return (valid);
}


/*******************************************************************************
* Function Name: Cy_Flash_GetRowNum
********************************************************************************
*
* Gets the (supervisory) Flash row number out of the absolute address.
*
* \param flashAddr Flash row address.
*
* \return Row number. Returns zero for invalid address.
*
*******************************************************************************/
static uint32_t Cy_Flash_GetRowNum(uint32_t flashAddr)
{
    uint32_t result = 0U;

    if (flashAddr < (CY_FLASH_BASE + CY_FLASH_SIZEOF_FLASH))
    {
        result = (flashAddr - CY_FLASH_BASE) / CY_FLASH_SIZEOF_ROW;
    }
    #if defined (SFLASH_FLASH_M0_XTRA_ROWS) && (SFLASH_FLASH_M0_XTRA_ROWS == 1U)
        else /* Assume SFLASH */
        {
            result = (flashAddr - CY_FLASH_SFLASH_USERBASE) / CY_FLASH_SIZEOF_ROW;
        }
    #elif (defined (SFLASH_USER_SFLASH_AREA_LOCATION_Pos))
        /* if USER SFLASH AREA defined */
        /* Check 0th USER SFLASH */
        else if ((flashAddr >= CY_FLASH_SFLASH_USERBASE) && (flashAddr < (CY_FLASH_SFLASH_USERBASE + CY_FLASH_SIZEOF_USERSFLASH)))
        {
            if (CY_FLASH_SIZEOF_USERSFLASH > CY_FLASH_SIZEOF_ROW)
            {
                result = (flashAddr - CY_FLASH_SFLASH_USERBASE) / CY_FLASH_SIZEOF_ROW;
            }
        }
        /* Check 2th USER SFLASH */
        else if ((flashAddr >= CY_FLASH_SFLASH_USERBASE1) && (flashAddr < (CY_FLASH_SFLASH_USERBASE1 + CY_FLASH_SIZEOF_USERSFLASH1)))
        {
            if (CY_FLASH_SIZEOF_USERSFLASH1 > CY_FLASH_SIZEOF_ROW)
            {
                result = (flashAddr - CY_FLASH_SFLASH_USERBASE1) / CY_FLASH_SIZEOF_ROW;
            }
        }
        else
        {
            result = 0U;
        }
    #endif /* defined (SFLASH_FLASH_M0_XTRA_ROWS) && (SFLASH_FLASH_M0_XTRA_ROWS == 1U) */

    return (result);
}


/*******************************************************************************
 * Function Name: Cy_Flash_ClockBackup
********************************************************************************
*
* Backups the device clock configuration.
*
* \return \ref cy_en_flashdrv_status_t
*
*******************************************************************************/
static cy_en_flashdrv_status_t Cy_Flash_ClockBackup(void)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_SUCCESS;
    volatile uint32_t   parameters[2U];

    parameters[0U] =(uint32_t) ((CY_FLASH_KEY_TWO(CY_FLASH_API_OPCODE_CLK_BACKUP) <<  CY_FLASH_PARAM_KEY_TWO_OFFSET) |
                            CY_FLASH_KEY_ONE);
    parameters[1U] = (uint32_t) &cySysFlashBackup.clockSettings[0U];
    CPUSS_SYSARG = (uint32_t) &parameters[0U];
    CPUSS_SYSREQ = CY_FLASH_CPUSS_REQ_START | CY_FLASH_API_OPCODE_CLK_BACKUP;

    result = ProcessStatusCode();

    /* Enabling IMO after backup completion as required by hardware.
    *  The Cy_Flash_ClockRestore() restores original state of the system.
    */
    Cy_SysClk_ImoEnable();

    return (result);
}


/*******************************************************************************
 * Function Name: Cy_Flash_ClockConfig
********************************************************************************
*
* \brief Configures the device clocks for the Flash writing.
*
* \return \ref cy_en_flashdrv_status_t
*
*******************************************************************************/
static cy_en_flashdrv_status_t Cy_Flash_ClockConfig(void)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_SUCCESS;
#if defined(CY_IP_M0S8SRSSHV)
    Cy_SysClk_UnlockProtReg();
#endif /* defined(CY_IP_M0S8SRSSHV) */
    /* FM-Lite Clock Configuration */
    CPUSS_SYSARG =(uint32_t) ((CY_FLASH_KEY_TWO(CY_FLASH_API_OPCODE_CLK_CONFIG) <<  CY_FLASH_PARAM_KEY_TWO_OFFSET) |
                    CY_FLASH_KEY_ONE);
    CPUSS_SYSREQ = CY_FLASH_CPUSS_REQ_START | CY_FLASH_API_OPCODE_CLK_CONFIG;

    result = ProcessStatusCode();
#if defined(CY_IP_M0S8SRSSHV)
    Cy_SysClk_LockProtReg();
#endif /* defined(CY_IP_M0S8SRSSHV) */
    return (result);
}


/*******************************************************************************
 * Function Name: Cy_Flash_ClockRestore
********************************************************************************
*
* \brief Restores the device clock configuration previously saved with
* \ref Cy_Flash_ClockBackup.
*
* \return \ref cy_en_flashdrv_status_t
*
********************************************************************************/
static cy_en_flashdrv_status_t Cy_Flash_ClockRestore(void)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_SUCCESS;
    volatile uint32_t   parameters[2U];
#if defined(CY_IP_M0S8SRSSHV)
    Cy_SysClk_UnlockProtReg();
#endif /* defined(CY_IP_M0S8SRSSHV) */
    /* FM-Lite Clock Restore */
    parameters[0U] = (uint32_t) ((CY_FLASH_KEY_TWO(CY_FLASH_API_OPCODE_CLK_RESTORE) <<  CY_FLASH_PARAM_KEY_TWO_OFFSET) |
                    CY_FLASH_KEY_ONE);
    parameters[1U] = (uint32_t) &cySysFlashBackup.clockSettings[0U];
    CPUSS_SYSARG = (uint32_t) &parameters[0U];
    CPUSS_SYSREQ = CY_FLASH_CPUSS_REQ_START | CY_FLASH_API_OPCODE_CLK_RESTORE;

    result = ProcessStatusCode();
#if defined(CY_IP_M0S8SRSSHV)
    Cy_SysClk_LockProtReg();
#endif /* defined(CY_IP_M0S8SRSSHV) */
    return (result);
}

#if defined(CPUSS_SPCIF_FLASH_S8FS_VER2) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_Flash_SetProtection
****************************************************************************//**
*
* \brief
*  Controls protection against the program/erase operation of the flash.
*
* \param bitField Bitfield value that specify the protection setting of Flash macros.
*
* \return \ref group_flash_enumerated_types
*
* \funcusage
* \snippet flash_snippet.c SNIPPET_FLASH_PROTECT
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_SetProtection(const uint32_t bitField)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_SUCCESS;
    /* Check the range of the bitfield */
    if(bitField <= CY_FLASH_PROTECTION_BIT_PARAM_MAX)
    {
        /* Check if the write access to FLASH_MACRO_WE.MAC_WRITE_EN is locked */
        if(0UL != _FLD2VAL(SPCIF_FLASH_MACRO_WE_LOCKED,FLASH_MACRO_WRITE_EN))
        {
            /* Set the key to unlock */
            LOCK_FLASH = (uint32_t)CY_FLASH_PROTECTION_LOCK_KEY;
            /* Set protection setting */
            FLASH_MACRO_WRITE_EN = _VAL2FLD(SPCIF_FLASH_MACRO_WE_MAC_WRITE_EN,bitField);
            /* Set the key to lock */
            LOCK_FLASH = (uint32_t)CY_FLASH_PROTECTION_LOCK_KEY;
        }
        else
        {
            /* Set protection setting */
            FLASH_MACRO_WRITE_EN = _VAL2FLD(SPCIF_FLASH_MACRO_WE_MAC_WRITE_EN,bitField);
        }
        /* Protection is success */
        result = CY_FLASH_DRV_SUCCESS;
    }
    else
    {
        result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
    } /* if(bitField <= CY_FLASH_PROTECTION_BIT_PARAM_MAX) */
    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_GetProtectionStatus
****************************************************************************//**
*
* \brief Gets the flash protection status of the specified flash.
*
* \param statusPtr
*  The pointer to the area to store the protection status.
*
* \return \ref group_flash_enumerated_types
*
* \funcusage
* \snippet flash_snippet.c SNIPPET_FLASH_PROTECT
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_GetProtectionStatus(uint32_t* statusPtr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_SUCCESS;
    /* NULL check of Status pointer */
    if(NULL != statusPtr)
    {
        *statusPtr = _FLD2VAL(SPCIF_FLASH_MACRO_WE_MAC_WRITE_EN,FLASH_MACRO_WRITE_EN);
    }
    else
    {
        result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
    }
    return (result);
}
#endif /* defined(CPUSS_SPCIF_FLASH_S8FS_VER2) */

#if (defined(CPUSS_FLASHC_PRESENT_WITH_ECC) && (CPUSS_FLASHC_PRESENT_WITH_ECC == 1U))  || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_Flash_SetupEccInjection
****************************************************************************//**
*
* \brief
*  Set CPUSS_FLASHC_ECC_CTL register to setup ECC error injection.
*
* \param [in] address
*  Specifies the address where an ECC error will be injected.
*
* \param [in] parity
*  Specifies the parity, which will be injected to the word address.
*
* \return \ref group_flash_enumerated_types
*
* * \funcusage
* \snippet flash_snippet.c SNIPPET_FLASH_ECC
*
* \note
*  Set the lowest three bits of the address to zero.
*  For FLASH ECC, the word address WORD_ADDR[23:0] is device address A[26:3].
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_SetupEccInjection(const uint32_t address, const uint8_t parity)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_SUCCESS;
    /* Check if parameters are valid */
    if(0U != (address & CY_FLASH_WORD_ADDR_CHECK_MSK))
    {
        result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
    }
    else if(((CY_FLASH_BASE + CY_FLASH_SIZEOF_FLASH) <= address) || (CY_FLASH_BASE >= (address + 1U)))
    {
        result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
    }
    else
    {
        CPUSS_FLASHC_ECC_CTL = _VAL2FLD(CPUSS_FLASHC_ECC_CTL_FLASH_WORD_ADDR,(address >> CY_CPU_FLASH_WORD_ADDR_CHECK_POS)) |
                _VAL2FLD(CPUSS_FLASHC_ECC_CTL_PARITY,parity);
    } /* (0U != (address & CY_FLASH_WORD_ADDR_CHECK_MSK)) */
    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_EnableEccInjection
****************************************************************************//**
*
* \brief Set CPUSS_FLASH_CTL register to enable ECC injection.
*
* \return None
*
* \funcusage
* \snippet flash_snippet.c SNIPPET_FLASH_ECC
*
*******************************************************************************/
void Cy_Flash_EnableEccInjection(void)
{
    CPUSS_FLASH_CTL |= CPUSS_FLASH_CTL_FLASH_ECC_INJ_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_Flash_DisableEccInjection
****************************************************************************//**
*
* \brief Set CPUSS_FLASH_CTL register to disable ECC injection
*
* \return None
*
* \funcusage
* \snippet flash_snippet.c SNIPPET_FLASH_ECC
*
*******************************************************************************/
void Cy_Flash_DisableEccInjection(void)
{
    CPUSS_FLASH_CTL &= ~CPUSS_FLASH_CTL_FLASH_ECC_INJ_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_Flash_IsEccInjectionEnabled
****************************************************************************//**
*
* \brief Check whether the ECC error injection of data flash is enabled.
*
* \return TRUE if injection enabled, FALSE - otherwise.
*
* \funcusage
* \snippet flash_snippet.c SNIPPET_FLASH_ECC
*
*******************************************************************************/
bool Cy_Flash_IsEccInjectionEnabled(void)
{
    return (bool)_FLD2VAL(CPUSS_FLASH_CTL_FLASH_ECC_INJ_EN,CPUSS_FLASH_CTL);
}
#endif /* (defined(CPUSS_FLASHC_PRESENT_WITH_ECC) && (CPUSS_FLASHC_PRESENT_WITH_ECC == 1U))  || defined (CY_DOXYGEN) */

/* [] END OF FILE */
