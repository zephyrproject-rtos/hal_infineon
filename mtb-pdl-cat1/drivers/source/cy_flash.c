/***************************************************************************//**
* \file cy_flash.c
* \version 3.130
*
* \brief
* Provides the public functions for the API for the PSOC 6 and PSOC C3 Flash Driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2024 Cypress Semiconductor Corporation
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

#include "cy_device.h"

#if ((defined (CY_IP_M4CPUSS) && !defined (CY_IP_MXFLASHC_VERSION_ECT)) || defined (CY_IP_MXS40FLASHC))

#include "cy_flash.h"
#include "cy_sysclk.h"
#include "cy_sysint.h"
#include "cy_ipc_drv.h"
#include "cy_ipc_sema.h"
#include "cy_ipc_pipe.h"
#include "cy_syslib.h"
#if defined (CY_DEVICE_SECURE)
    #include "cy_pra.h"
#endif /* defined (CY_DEVICE_SECURE) */
#if defined (CY_IP_MXS40FLASHC)
#include "cyboot_flash_list.h"
#endif

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 2, \
'IPC_STRUCT_Type will typecast to either IPC_STRUCT_V1_Type or IPC_STRUCT_V2_Type but not both on PDL initialization based on the target device at compile time.')

/***************************************
* Data Structure definitions
***************************************/

/* Flash driver context */
typedef struct
{
    uint32_t opcode;      /**< Specifies the code of flash operation */
    uint32_t arg1;        /**< Specifies the configuration of flash operation */
    uint32_t arg2;        /**< Specifies the configuration of flash operation */
    uint32_t arg3;        /**< Specifies the configuration of flash operation */
} cy_stc_flash_context_t;


/***************************************
* Macro definitions
***************************************/

/** \cond INTERNAL */
/** Set SROM API in blocking mode */
#define CY_FLASH_BLOCKING_MODE             ((0x01UL) << 8UL)
/** Set SROM API in non blocking mode */
#define CY_FLASH_NON_BLOCKING_MODE         (0UL)

/** SROM API flash region ID shift for flash row information */
#define CY_FLASH_REGION_ID_SHIFT           (16U)
#define CY_FLASH_REGION_ID_MASK            (3U)
#define CY_FLASH_ROW_ID_MASK               (0xFFFFU)
/** SROM API flash region IDs */
#define CY_FLASH_REGION_ID_MAIN            (0UL)
#define CY_FLASH_REGION_ID_EM_EEPROM       (1UL)
#define CY_FLASH_REGION_ID_SFLASH          (2UL)

/** SROM API opcode mask */
#define CY_FLASH_OPCODE_Msk                ((0xFFUL) << 24UL)
/** SROM API opcode for flash write operation */
#define CY_FLASH_OPCODE_WRITE_ROW          ((0x05UL) << 24UL)
/** SROM API opcode for flash program operation */
#define CY_FLASH_OPCODE_PROGRAM_ROW        ((0x06UL) << 24UL)
/** SROM API opcode for row erase operation */
#define CY_FLASH_OPCODE_ERASE_ROW          ((0x1CUL) << 24UL)
/** SROM API opcode for sub sector erase operation */
#define CY_FLASH_OPCODE_ERASE_SUB_SECTOR   ((0x1DUL) << 24UL)
/** SROM API opcode for sector erase operation */
#define CY_FLASH_OPCODE_ERASE_SECTOR       ((0x14UL) << 24UL)
/** SROM API opcode for flash checksum operation */
#define CY_FLASH_OPCODE_CHECKSUM           ((0x0BUL) << 24UL)
/** SROM API opcode for flash hash operation */
#define CY_FLASH_OPCODE_HASH               ((0x0DUL) << 24UL)
/** SROM API flash row shift for flash checksum operation */
#define CY_FLASH_OPCODE_CHECKSUM_ROW_SHIFT (8UL)
/** SROM API flash row shift for flash checksum operation */
#define CY_FLASH_OPCODE_CHECKSUM_REGION_SHIFT (22UL)
/** Data to be programmed to flash is located in SRAM memory region */
#define CY_FLASH_DATA_LOC_SRAM             (0x100UL)
/** SROM API flash verification option for flash write operation */
#define CY_FLASH_CONFIG_VERIFICATION_EN    ((0x01UL) << 16u)

/** Command completed with no errors */
#define CY_FLASH_ROMCODE_SUCCESS                   (0xA0000000UL)
/** Invalid device protection state */
#define CY_FLASH_ROMCODE_INVALID_PROTECTION        (0xF0000001UL)
/** Invalid flash page latch address */
#define CY_FLASH_ROMCODE_INVALID_FM_PL             (0xF0000003UL)
/** Invalid flash address */
#define CY_FLASH_ROMCODE_INVALID_FLASH_ADDR        (0xF0000004UL)
/** Row is write protected */
#define CY_FLASH_ROMCODE_ROW_PROTECTED             (0xF0000005UL)
/** Comparison between Page Latches and FM row failed */
#define CY_FLASH_ROMCODE_PL_ROW_COMP_FA            (0xF0000022UL)
/** Command in progress; no error */
#define CY_FLASH_ROMCODE_IN_PROGRESS_NO_ERROR      (0xA0000009UL)
/** Flash operation is successfully initiated */
#define CY_FLASH_IS_OPERATION_STARTED              (0x00000010UL)
/** Flash is under operation */
#define CY_FLASH_IS_BUSY                           (0x00000040UL)
/** IPC structure is already locked by another process */
#define CY_FLASH_IS_IPC_BUSY                       (0x00000080UL)
/** Input parameters passed to Flash API are not valid */
#define CY_FLASH_IS_INVALID_INPUT_PARAMETERS       (0x00000100UL)

/** Result mask */
#define CY_FLASH_RESULT_MASK                       (0x0FFFFFFFUL)
/** Error shift */
#define CY_FLASH_ERROR_SHIFT                       (28UL)
/** No error */
#define CY_FLASH_ERROR_NO_ERROR                    (0xAUL)

/** CM4 Flash Proxy address */
#define CY_FLASH_CM4_FLASH_PROXY_ADDR              (*(Cy_Flash_Proxy *)(0x00000D1CUL))
typedef cy_en_flashdrv_status_t (*Cy_Flash_Proxy)(cy_stc_flash_context_t *context);

/** IPC notify bit for IPC0 structure (dedicated to flash operation) */
#define CY_FLASH_IPC_NOTIFY_STRUCT0                (0x1UL << CY_IPC_INTR_SYSCALL1)

/** Disable delay */
#define CY_FLASH_NO_DELAY                          (0U)

#if !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED)
    /** Number of ticks to wait 1 uS */
    #define CY_FLASH_TICKS_FOR_1US                     (8U)
    /** Define to set the IMO to perform a delay after the flash operation started */
    #define CY_FLASH_TST_DDFT_SLOW_CTL_MASK            (0x00001F1EUL)
    /** Fast control register */
    #define CY_FLASH_TST_DDFT_FAST_CTL_MASK            (62U)
    /** Slow output register - output disabled */
    #define CY_FLASH_CLK_OUTPUT_DISABLED               (0U)

    /* The default delay time value */
    #define CY_FLASH_DEFAULT_DELAY                     (150UL)
    /* Calculates the time in microseconds to wait for the number of the CM0P ticks */
    #define CY_FLASH_DELAY_CORRECTIVE(ticks)           (((ticks) * 1000UL) / (Cy_SysClk_ClkSlowGetFrequency() / 1000UL))

    /* Number of the CM0P ticks for StartProgram function delay corrective time */
    #define CY_FLASH_START_PROGRAM_DELAY_TICKS         (6000UL)
    /* Delay time for StartProgram function in us */
    #define CY_FLASH_START_PROGRAM_DELAY_TIME          (900UL + CY_FLASH_DELAY_CORRECTIVE(CY_FLASH_START_PROGRAM_DELAY_TICKS))
    /* Number of the CM0P ticks for StartErase functions delay corrective time */
    #define CY_FLASH_START_ERASE_DELAY_TICKS           (9500UL)
    /* Delay time for StartErase functions in us */
    #define CY_FLASH_START_ERASE_DELAY_TIME            (2200UL + CY_FLASH_DELAY_CORRECTIVE(CY_FLASH_START_ERASE_DELAY_TICKS))
    /* Number of the CM0P ticks for StartWrite function delay corrective time */
    #define CY_FLASH_START_WRITE_DELAY_TICKS           (19000UL)
    /* Delay time for StartWrite function in us */
    #define CY_FLASH_START_WRITE_DELAY_TIME            (9800UL + CY_FLASH_DELAY_CORRECTIVE(CY_FLASH_START_WRITE_DELAY_TICKS))

    /** Delay time for Start Write function in us with corrective time */
    #define CY_FLASH_START_WRITE_DELAY                 (CY_FLASH_START_WRITE_DELAY_TIME)
    /** Delay time for Start Program function in us with corrective time */
    #define CY_FLASH_START_PROGRAM_DELAY               (CY_FLASH_START_PROGRAM_DELAY_TIME)
    /** Delay time for Start Erase function in uS with corrective time */
    #define CY_FLASH_START_ERASE_DELAY                 (CY_FLASH_START_ERASE_DELAY_TIME)

    #define CY_FLASH_ENTER_WAIT_LOOP                   (0xFFU)
    #define CY_FLASH_IPC_CLIENT_ID                     (2U)

    /** Semaphore number reserved for flash driver */
    #define CY_FLASH_WAIT_SEMA                         (0UL)
    /* Semaphore check timeout (in tries) */
    #define CY_FLASH_SEMA_WAIT_MAX_TRIES               (150000UL)
#if !defined (CY_IP_MXS40FLASHC)
    static void Cy_Flash_RAMDelay(uint32_t microseconds);

    #if (CY_CPU_CORTEX_M0P)
        #define IS_CY_PIPE_FREE(...)       (!Cy_IPC_Drv_IsLockAcquired(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_CYPIPE_EP1)))
        #define NOTIFY_PEER_CORE(a)         Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, CY_IPC_EP_CYPIPE_CM0_ADDR, (a), NULL)
    #else
        #define IS_CY_PIPE_FREE(...)       (!Cy_IPC_Drv_IsLockAcquired(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_CYPIPE_EP0)))
        #define NOTIFY_PEER_CORE(a)         Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM0_ADDR, CY_IPC_EP_CYPIPE_CM4_ADDR, (a), NULL)
    #endif

    static void Cy_Flash_NotifyHandler(uint32_t * msgPtr);

    static cy_stc_flash_notify_t * ipcWaitMessage;
#endif /* !defined (CY_IP_MXS40FLASHC) */
#else
    /** Delay time for Start Write function in us with corrective time */
    #define CY_FLASH_START_WRITE_DELAY                 (CY_FLASH_NO_DELAY)
    /** Delay time for Start Program function in us with corrective time */
    #define CY_FLASH_START_PROGRAM_DELAY               (CY_FLASH_NO_DELAY)
    /** Delay time for Start Erase function in uS with corrective time */
    #define CY_FLASH_START_ERASE_DELAY                 (CY_FLASH_NO_DELAY)

#endif /* !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED) */
/** \endcond */

/* Static functions */
static cy_en_flashdrv_status_t Cy_Flash_OperationStatus(void);
#if !defined (CY_IP_MXS40FLASHC)
static bool Cy_Flash_BoundsCheck(uint32_t flashAddr);
static cy_en_flashdrv_status_t Cy_Flash_ProcessOpcode(uint32_t opcode);
static uint32_t Cy_Flash_GetRowNum(uint32_t flashAddr);
static cy_en_flashdrv_status_t Cy_Flash_SendCmd(uint32_t mode, uint32_t microseconds);
static volatile cy_stc_flash_context_t flashContext;
#endif

#if defined (CY_IP_MXS40FLASHC)

#define CYBOOT_FLAGS_BLOCKING 0U
#define CYBOOT_FLAGS_NON_BLOCKING 1U
#define HASH_CALC_DIVISOR 127U
#define HASH_CALC_DIVISOR_LEN 7U
#define REG8(addr)                      ( *( (volatile uint8_t  *)(addr) ) )
#define SECTOR_INDEX_WITHOUT_SFLASH  0U

static cyboot_flash_context_t boot_rom_context;
/* This is a work around in PDL. To cyboot_flash_refresh_init passing an array of cyboot_flash_refresh_t instead of passing a pointer to cyboot_flash_refresh_t.
The change is required to prevent writes to sector 1 from corrupting memory adjacent to the refresh_t structure.
The refresh structure is updated by the flash write routine even if it is not initialized.
This should be fixed in the Boot code later. */
static cyboot_flash_refresh_t flash_refresh[CPUSS_FLASHC_SECTOR_M];
static bool refresh_feature_enable;

/* To calculate hash */
static uint8_t Cy_Flash_GetHash(uint32_t startAddr,uint32_t numberOfBytes);
static void Cy_Flash_Callback_PreIRQ(cyboot_flash_context_t *ctx);
static void Cy_Flash_Callback_PostIRQ(cyboot_flash_context_t *ctx);
static void Cy_Flash_Callback_IRQComplete(cyboot_flash_context_t *ctx);

#endif /* defined (CY_IP_MXS40FLASHC) */

#if !defined (CY_IP_MXS40FLASHC)
#if !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED)
/*******************************************************************************
* Function Name: Cy_Flash_InitExt
****************************************************************************//**
*
* Initiates all needed prerequisites to support flash erase/write.
* Should be called from each core. Defines the address of the message structure.
*
* Requires a call to Cy_IPC_Sema_Init(), Cy_IPC_Pipe_Config() and
* Cy_IPC_Pipe_Init() functions before use.
*
* This function is called in the Cy_Flash_Init() function - see the
* Cy_Flash_Init usage considerations.
*
*******************************************************************************/
void Cy_Flash_InitExt(cy_stc_flash_notify_t *ipcWaitMessageAddr)
{
    ipcWaitMessage = ipcWaitMessageAddr;

    if(ipcWaitMessage != NULL)
    {
        ipcWaitMessage->clientID = CY_FLASH_IPC_CLIENT_ID;
        ipcWaitMessage->pktType = CY_FLASH_ENTER_WAIT_LOOP;
        ipcWaitMessage->intrRelMask = 0U;
    }

    if (cy_device->flashRwwRequired != 0U)
    {
        #if (CY_CPU_CORTEX_M4)
            cy_stc_sysint_t flashIntConfig =
            {
                (IRQn_Type)cy_device->cpussFmIrq,   /* .intrSrc */
                0U                                  /* .intrPriority */
            };

            (void)Cy_SysInt_Init(&flashIntConfig, &Cy_Flash_ResumeIrqHandler);
            NVIC_EnableIRQ(flashIntConfig.intrSrc);
        #endif

            if (cy_device->flashPipeRequired != 0U)
            {
                (void)Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_ADDR, &Cy_Flash_NotifyHandler,
                                                  (uint32_t)CY_FLASH_IPC_CLIENT_ID);
            }
    }
}


/*******************************************************************************
* Function Name: Cy_Flash_NotifyHandler
****************************************************************************//**
*
* This is the interrupt service routine for the pipe notifications.
*
*******************************************************************************/
CY_SECTION_RAMFUNC_BEGIN
#if !defined (__ICCARM__)
    CY_NOINLINE
#endif
static void Cy_Flash_NotifyHandler(uint32_t * msgPtr)
{
#if !((CY_CPU_CORTEX_M0P) && (defined (CY_DEVICE_SECURE)))
    uint32_t intr;
#endif /* !((CY_CPU_CORTEX_M0P) && (defined (CY_DEVICE_SECURE))) */
    static uint32_t semaIndex;
    static uint32_t semaMask;
    static volatile uint32_t *semaPtr;
    static cy_stc_ipc_sema_t *semaStruct;

    cy_stc_flash_notify_t *ipcMsgPtr = (cy_stc_flash_notify_t *) (void *) msgPtr;

    if (CY_FLASH_ENTER_WAIT_LOOP == ipcMsgPtr->pktType)
    {
    #if !((CY_CPU_CORTEX_M0P) && (defined (CY_DEVICE_SECURE)))
        intr = Cy_SysLib_EnterCriticalSection();
    #endif /* !((CY_CPU_CORTEX_M0P) && (defined (CY_DEVICE_SECURE))) */

        /* Get pointer to structure */
        semaStruct = (cy_stc_ipc_sema_t *)Cy_IPC_Drv_ReadDataValue(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_SEMA));

        /* Get the index into the semaphore array and calculate the mask */
        semaIndex = CY_FLASH_WAIT_SEMA / CY_IPC_SEMA_PER_WORD;
        semaMask = (uint32_t)(1UL << (CY_FLASH_WAIT_SEMA - (semaIndex * CY_IPC_SEMA_PER_WORD) ));
        semaPtr = &semaStruct->arrayPtr[semaIndex];

        /* Notification to the Flash driver to start the current operation */
        *semaPtr |= semaMask;

        /* Check a notification from other core to end of waiting */
        while (((*semaPtr) & semaMask) != 0UL)
        {
        }

    #if !((CY_CPU_CORTEX_M0P) && (defined (CY_DEVICE_SECURE)))
        Cy_SysLib_ExitCriticalSection(intr);
    #endif /* !((CY_CPU_CORTEX_M0P) && (defined (CY_DEVICE_SECURE))) */
    }
}
CY_SECTION_RAMFUNC_END
#endif /* !defined(CY_FLASH_RWW_DRV_SUPPORT_DISABLED) */
#endif /* !defined (CY_IP_MXS40FLASHC) */

#if !defined (CY_IP_MXS40FLASHC)
/*******************************************************************************
* Function Name: Cy_Flash_Init
****************************************************************************//**
*
* Initiates all needed prerequisites to support flash erase/write.
* Should be called from each core.
*
* Requires a call to Cy_IPC_Sema_Init(), Cy_IPC_Pipe_Config() and
* Cy_IPC_Pipe_Init() functions before use.
*
* This function is called in the SystemInit() function, for proper flash write
* and erase operations. If the default startup file is not used, or the function
* SystemInit() is not called in your project, ensure to perform the following steps
* before any flash or EmEEPROM write/erase operations:
*
*******************************************************************************/
void Cy_Flash_Init(void)
{

    #if !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED)
        CY_SECTION_SHAREDMEM
        static cy_stc_flash_notify_t ipcWaitMessageStc CY_ALIGN(4);

        Cy_Flash_InitExt(&ipcWaitMessageStc);
    #endif /* !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED) */

}


/*******************************************************************************
* Function Name: Cy_Flash_SendCmd
****************************************************************************//**
*
* Sends a command to the SROM via the IPC channel. The function is placed to the
* SRAM memory to guarantee successful operation. After an IPC message is sent,
* the function waits for a defined time before exiting the function.
*
*******************************************************************************/
CY_SECTION_RAMFUNC_BEGIN
#if !defined (__ICCARM__)
    CY_NOINLINE
#endif
static cy_en_flashdrv_status_t Cy_Flash_SendCmd(uint32_t mode, uint32_t microseconds)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_IPC_BUSY;
    IPC_STRUCT_Type * locIpcBase = Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_SYSCALL);
    volatile uint32_t *ipcLockStatus = &REG_IPC_STRUCT_LOCK_STATUS(locIpcBase);

#if !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED)
    uint32_t intr;
    uint32_t semaTryCount = 0uL;

    if (cy_device->flashRwwRequired != 0U)
    {
        /* Check for active core is CM0+, or CM4 on single core device */
    #if (CY_CPU_CORTEX_M0P)
        bool isPeerCoreEnabled = (CY_SYS_CM4_STATUS_ENABLED == Cy_SysGetCM4Status());
    #else
        bool isPeerCoreEnabled = false;

        if (SFLASH_SINGLE_CORE == 0U)
        {
            isPeerCoreEnabled = true;
        }
    #endif

        if (!isPeerCoreEnabled)
        {
            result = CY_FLASH_DRV_SUCCESS;
        }
        else
        {
            if (IS_CY_PIPE_FREE())
            {
                if (CY_IPC_SEMA_STATUS_LOCKED != Cy_IPC_Sema_Status(CY_FLASH_WAIT_SEMA))
                {
                    if (CY_IPC_PIPE_SUCCESS == NOTIFY_PEER_CORE(ipcWaitMessage))
                    {
                        /* Wait for SEMA lock by peer core */
                        while ((CY_IPC_SEMA_STATUS_LOCKED != Cy_IPC_Sema_Status(CY_FLASH_WAIT_SEMA)) && ((semaTryCount < CY_FLASH_SEMA_WAIT_MAX_TRIES)))
                        {
                            /* check for timeout (as maximum tries count) */
                            ++semaTryCount;
                        }

                        if (semaTryCount < CY_FLASH_SEMA_WAIT_MAX_TRIES)
                        {
                            result = CY_FLASH_DRV_SUCCESS;
                        }
                    }
                }
            }
        }

        if (CY_FLASH_DRV_SUCCESS == result)
        {
            /* Notifier is ready, start of the operation */
            intr = Cy_SysLib_EnterCriticalSection();

            while (0UL == _FLD2VAL(SRSS_CLK_CAL_CNT1_CAL_COUNTER_DONE, SRSS_CLK_CAL_CNT1))
            {
                /* wait here */
            }

            if (0UL != _FLD2VAL(SRSS_CLK_CAL_CNT1_CAL_COUNTER_DONE, SRSS_CLK_CAL_CNT1))
            {
               /* Tries to acquire the IPC structure and pass the arguments to SROM API */
                if (Cy_IPC_Drv_SendMsgPtr(locIpcBase, CY_FLASH_IPC_NOTIFY_STRUCT0, (void*)&flashContext) == CY_IPC_DRV_SUCCESS)
                {
                    Cy_Flash_RAMDelay(microseconds);

                    if (mode == CY_FLASH_NON_BLOCKING_MODE)
                    {
                        /* The Flash operation is successfully initiated */
                        result = CY_FLASH_DRV_OPERATION_STARTED;
                    }
                    else
                    {
                        while (0U != _FLD2VAL(IPC_STRUCT_ACQUIRE_SUCCESS, *ipcLockStatus))
                        {
                            /* Polls whether the IPC is released and the Flash operation is performed */
                        }
                        result = Cy_Flash_OperationStatus();
                    }
                }
                else
                {
                    /* The IPC structure is already locked by another process */
                    result = CY_FLASH_DRV_IPC_BUSY;
                }
            }
            else
            {
                /* SysClk measurement counter is busy */
                result = CY_FLASH_DRV_IPC_BUSY;
            }

            if (isPeerCoreEnabled)
            {
                while (CY_IPC_SEMA_SUCCESS != Cy_IPC_Sema_Clear(CY_FLASH_WAIT_SEMA, true))
                {
                    /* Clear SEMA lock */
                }
            }

            Cy_SysLib_ExitCriticalSection(intr);
            /* End of the flash operation */
        }
    }
    else
#endif /* !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED) */
    {
    #if !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED)
        intr = Cy_SysLib_EnterCriticalSection();
    #endif /* !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED) */
        /* Tries to acquire the IPC structure and pass the arguments to SROM API */
        if (Cy_IPC_Drv_SendMsgPtr(locIpcBase, CY_FLASH_IPC_NOTIFY_STRUCT0, (void*)&flashContext) == CY_IPC_DRV_SUCCESS)
        {
            if (mode == CY_FLASH_NON_BLOCKING_MODE)
            {
                /* The Flash operation is successfully initiated */
                result = CY_FLASH_DRV_OPERATION_STARTED;
            }
            else
            {
                while (0U != _FLD2VAL(IPC_STRUCT_ACQUIRE_SUCCESS, *ipcLockStatus))
                {
                    /* Polls whether the IPC is released and the Flash operation is performed */
                }

                result = Cy_Flash_OperationStatus();
            }
        }
        else
        {
            /* The IPC structure is already locked by another process */
            result = CY_FLASH_DRV_IPC_BUSY;
        }
    #if !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED)
        Cy_SysLib_ExitCriticalSection(intr);
    #endif /* !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED) */
    }

    return (result);
}
CY_SECTION_RAMFUNC_END


#if !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED)
    /*******************************************************************************
    * Function Name: Cy_Flash_RAMDelay
    ****************************************************************************//**
    *
    * Wait for a defined time in the SRAM memory region.
    *
    *******************************************************************************/
    CY_SECTION_RAMFUNC_BEGIN
    #if !defined (__ICCARM__)
        CY_NOINLINE
    #endif
    static void Cy_Flash_RAMDelay(uint32_t microseconds)
    {
        uint32_t ticks = (microseconds & 0xFFFFUL) * CY_FLASH_TICKS_FOR_1US;
        if (ticks != CY_FLASH_NO_DELAY)
        {
            /* Acquire the IPC to prevent changing of the shared resources at the same time */
            while(0U == _FLD2VAL(IPC_STRUCT_ACQUIRE_SUCCESS, REG_IPC_STRUCT_ACQUIRE(CY_IPC_STRUCT_PTR(CY_IPC_CHAN_DDFT))))
            {
                /* Wait until the IPC structure is released by another process */
            }

            SRSS_TST_DDFT_FAST_CTL_REG  = SRSS_TST_DDFT_FAST_CTL_MASK;
            SRSS_TST_DDFT_SLOW_CTL_REG  = SRSS_TST_DDFT_SLOW_CTL_MASK;

            SRSS_CLK_OUTPUT_SLOW = _VAL2FLD(SRSS_CLK_OUTPUT_SLOW_SLOW_SEL0, CY_SYSCLK_MEAS_CLK_IMO) |
                                   _VAL2FLD(SRSS_CLK_OUTPUT_SLOW_SLOW_SEL1, CY_FLASH_CLK_OUTPUT_DISABLED);

            /* Load the down-counter without status bit value */
            SRSS_CLK_CAL_CNT1 = _VAL2FLD(SRSS_CLK_CAL_CNT1_CAL_COUNTER1, ticks);

            /* Make sure that the counter is started */
            ticks = _FLD2VAL(SRSS_CLK_CAL_CNT1_CAL_COUNTER_DONE, SRSS_CLK_CAL_CNT1);

            /* Release the IPC */
            REG_IPC_STRUCT_RELEASE(CY_IPC_STRUCT_PTR(CY_IPC_CHAN_DDFT)) = 0U;

            while (0UL == _FLD2VAL(SRSS_CLK_CAL_CNT1_CAL_COUNTER_DONE, SRSS_CLK_CAL_CNT1))
            {
                /* Wait until the counter stops counting */
            }
        }
    }
    CY_SECTION_RAMFUNC_END

    #if (CY_CPU_CORTEX_M4)

        /* Based on bookmark codes of mxs40srompsoc BROS,002-03298 */
        #define CY_FLASH_PROGRAM_ROW_BOOKMARK        (0x00000001UL)
        #define CY_FLASH_ERASE_ROW_BOOKMARK          (0x00000002UL)
        #define CY_FLASH_WRITE_ROW_ERASE_BOOKMARK    (0x00000003UL)
        #define CY_FLASH_WRITE_ROW_PROGRAM_BOOKMARK  (0x00000004UL)

        /* Number of the CM0P ticks for function delay corrective time at final stage */
        #define CY_FLASH_FINAL_STAGE_DELAY_TICKS     (1000UL)
        #define CY_FLASH_FINAL_STAGE_DELAY           (130UL + CY_FLASH_DELAY_CORRECTIVE(CY_FLASH_FINAL_STAGE_DELAY_TICKS))


        /*******************************************************************************
        * Function Name: Cy_Flash_ResumeIrqHandler
        ****************************************************************************//**
        *
        * This is the interrupt service routine to make additional processing of the
        * flash operations resume phase.
        *
        *******************************************************************************/
        CY_SECTION_RAMFUNC_BEGIN
        #if !defined (__ICCARM__)
            CY_NOINLINE
        #endif
        void Cy_Flash_ResumeIrqHandler(void)
        {
            IPC_STRUCT_Type * locIpcBase = Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_CYPIPE_EP0);

            uint32_t bookmark;
            #if ((CY_CPU_CORTEX_M4) && (defined (CY_DEVICE_SECURE)))
                bookmark = CY_PRA_REG32_GET(CY_PRA_INDX_FLASHC_FM_CTL_BOOKMARK) & 0xffffUL;
            #else
                bookmark = FLASHC_FM_CTL_BOOKMARK & 0xffffUL;
            #endif /* ((CY_CPU_CORTEX_M4) && (defined (CY_DEVICE_SECURE))) */

            uint32_t intr = Cy_SysLib_EnterCriticalSection();

            uint32_t cm0s = CPUSS_CM0_STATUS;
            bool sflashSingleCore = (0U == SFLASH_SINGLE_CORE);

            if ((bookmark == CY_FLASH_PROGRAM_ROW_BOOKMARK) || (bookmark == CY_FLASH_ERASE_ROW_BOOKMARK) ||
                (bookmark == CY_FLASH_WRITE_ROW_ERASE_BOOKMARK) || (bookmark == CY_FLASH_WRITE_ROW_PROGRAM_BOOKMARK))
            {
                if ((cm0s == (CPUSS_CM0_STATUS_SLEEPING_Msk | CPUSS_CM0_STATUS_SLEEPDEEP_Msk)) && sflashSingleCore)
                {
                    REG_IPC_STRUCT_NOTIFY(locIpcBase) = _VAL2FLD(IPC_STRUCT_NOTIFY_INTR_NOTIFY, (1UL << CY_IPC_INTR_CYPIPE_EP0));
                    while (CPUSS_CM0_STATUS == (CPUSS_CM0_STATUS_SLEEPING_Msk | CPUSS_CM0_STATUS_SLEEPDEEP_Msk))
                    {
                        /* Wait until the core is active */
                    }
                }
                Cy_Flash_RAMDelay(CY_FLASH_FINAL_STAGE_DELAY);
            }

            Cy_SysLib_ExitCriticalSection(intr);
        }
        CY_SECTION_RAMFUNC_END
    #endif /* (CY_CPU_CORTEX_M4) */
#endif /* !defined (CY_FLASH_RWW_DRV_SUPPORT_DISABLED) */

#else

/*******************************************************************************
* Function Name: Cy_Flash_Process_BootRom_Error_Code
****************************************************************************//**
*
* Converts Boot Rom Call returns to the Flash driver return defines.
*******************************************************************************/
static cy_en_flashdrv_status_t Cy_Flash_Process_BootRom_Error_Code(uint32_t error_code)
{
    cy_en_flashdrv_status_t result;

    switch (error_code)
    {
        case CYBOOT_FLASH_SUCCESS:
        {
            result = CY_FLASH_DRV_SUCCESS;
            break;
        }
        case CYBOOT_FLASH_INIT_FAILED:
        {
            result = CY_FLASH_DRV_INIT_FAILED;
            break;
        }
        case CYBOOT_FLASH_ADDR_INVALID:
        {
            result = CY_FLASH_DRV_INVALID_FLASH_ADDR;
            break;
        }
        case CYBOOT_FLASH_PARAM_INVALID:
        {
            result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
            break;
        }
        case CYBOOT_FLASH_RECOVER_ERR:
        {
        #if defined(CY_DEVICE_PSC3)
            result = CY_FLASH_DRV_REFRESH_NOTHING;
        #else
            result = CY_FLASH_DRV_ERR_UNC;
        #endif /* defined(CY_DEVICE_PSC3) */
            break;
        }
        case CYBOOT_FAULT_UNEXPECTED:
        {
            result = CY_FLASH_DRV_ERR_UNC;
            break;
        }
        default:
        {
            result = CY_FLASH_DRV_ERR_UNC;
            break;
        }
    }

    return (result);
}


/* These API's are call back functions from boot rom code.
   These needs to be passed to the boot rom in the init function.
   Current architecture in the PDL is not using the callback calls from boot rom.
   PDL gets the status of the operation complete by calling cyboot_is_flash_ready().
   cyboot_is_flash_ready is called from the existing function Cy_Flash_IsOperationComplete().
*/
/*******************************************************************************
* Function Name: Cy_Flash_Callback_PreIRQ
****************************************************************************//**
*
* Call back function from boot rom before the non blocking operation is started.
*
*******************************************************************************/
static void Cy_Flash_Callback_PreIRQ(cyboot_flash_context_t *ctx)
{
    (void) ctx;
}
/*******************************************************************************
* Function Name: Cy_Flash_Callback_PostIRQ
****************************************************************************//**
*
* Call back function from boot rom after the non blocking operation is started.
*
*******************************************************************************/
static void Cy_Flash_Callback_PostIRQ(cyboot_flash_context_t *ctx)
{
    (void) ctx;
}
/*******************************************************************************
* Function Name: Cy_Flash_Callback_IRQComplete
****************************************************************************//**
*
* Call back function from boot rom after the completion of non blocking operation.
*
*******************************************************************************/
static void Cy_Flash_Callback_IRQComplete(cyboot_flash_context_t *ctx)
{
    (void) ctx;
}

/*******************************************************************************
* Function Name: Cy_Flash_Init
****************************************************************************//**
*
* Initiates all needed prerequisites to support flash erase/write.
* Should be once before starting any flash operations.
*
* param refresh_enable enable disable refresh feature
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_Init(bool refresh_enable)
{
    cy_en_sysint_status_t sysStatus;
    const cy_stc_sysint_t flash_isr_cfg =
    {
        .intrSrc = (IRQn_Type) cpuss_interrupt_fm_cbus_IRQn,
        .intrPriority = 7,
    };

    sysStatus = Cy_SysInt_Init(&flash_isr_cfg, ROM_FUNC->cyboot_flash_irq_handler);
    if(CY_SYSINT_SUCCESS != sysStatus)
    {
        return CY_FLASH_DRV_ERR_UNC;
    }
    NVIC_EnableIRQ(flash_isr_cfg.intrSrc);

    __enable_irq();
    boot_rom_context.callback_pre_irq  = (cyboot_flash_callback_t)Cy_Flash_Callback_PreIRQ;
    boot_rom_context.callback_post_irq = (cyboot_flash_callback_t)Cy_Flash_Callback_PostIRQ;
    boot_rom_context.callback_complete = (cyboot_flash_callback_t)Cy_Flash_Callback_IRQComplete;

    if(refresh_enable)
    {
        refresh_feature_enable = refresh_enable;
        boot_rom_context.refresh = flash_refresh;
        /* Need to initialize boot_rom_context.refresh before working with flash */
        ROM_FUNC->cyboot_flash_refresh_init((uint32_t)SECTOR_INDEX_WITHOUT_SFLASH, flash_refresh);
        /* To recover a previous failure, if any */
        uint32_t ret = ROM_FUNC->cyboot_flash_refresh_recover((uint32_t)SECTOR_INDEX_WITHOUT_SFLASH, flash_refresh);
        return Cy_Flash_Process_BootRom_Error_Code(ret);
    }
    return CY_FLASH_DRV_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Flash_Is_Refresh_Required
********************************************************************************
* Checks whether a flash refresh is needed for a sector.
* \param refresh    A pointer to a single refresh structure.
* \returns
* - TRUE, if a refresh is needed.
* - FALSE, if a refresh is not needed.
*******************************************************************************/
bool Cy_Flash_Is_Refresh_Required(void)
{
    return ROM_FUNC->cyboot_flash_refresh_test(flash_refresh);
}
#endif /* !defined (CY_IP_MXS40FLASHC) */

/*******************************************************************************
* Function Name: Cy_Flash_EraseRow
****************************************************************************//**
*
* This function erases a single row of flash. Reports success or
* a reason for failure. Does not return until the Write operation is
* complete. Returns immediately and reports a CY_FLASH_DRV_IPC_BUSY error in
* the case when another process is writing to flash or erasing the row.
* User firmware should not enter the Hibernate or Deep Sleep mode until flash Erase
* is complete. The Flash operation is allowed in Sleep mode.
* During the Flash operation, the device should not be reset, including the
* XRES pin, a software reset, and watchdog reset sources. Also, low-voltage
* detect circuits should be configured to generate an interrupt instead of a
* reset. Otherwise, portions of flash may undergo unexpected changes.
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_EraseRow(uint32_t rowAddr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;

#if !defined (CY_IP_MXS40FLASHC)
    /* Prepares arguments to be passed to SROM API */
    if (Cy_Flash_BoundsCheck(rowAddr) != false)
    {
        SystemCoreClockUpdate();
        flashContext.opcode = CY_FLASH_OPCODE_ERASE_ROW | CY_FLASH_BLOCKING_MODE;
        flashContext.arg1 = rowAddr;
        flashContext.arg2 = 0UL;
        flashContext.arg3 = 0UL;

        if (cy_device->flashEraseDelay != 0U)
        {
            result = Cy_Flash_SendCmd(CY_FLASH_BLOCKING_MODE, CY_FLASH_START_ERASE_DELAY);
        }
        else
        {
            result = Cy_Flash_SendCmd(CY_FLASH_BLOCKING_MODE, CY_FLASH_NO_DELAY);
        }
    }
#else
        boot_rom_context.flags = CYBOOT_FLAGS_BLOCKING;
        uint32_t status = ROM_FUNC->cyboot_flash_erase_row(FLASH_SBUS_ALIAS_ADDRESS(rowAddr), &boot_rom_context);
        result = Cy_Flash_Process_BootRom_Error_Code(status);
#endif /* !defined (CY_IP_MXS40FLASHC) */


    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_StartEraseRow
****************************************************************************//**
*
* Starts erasing a single row of flash. Returns immediately
* and reports a successful start or reason for failure.
* Reports a CY_FLASH_DRV_IPC_BUSY error in the case when IPC structure is locked
* by another process. User firmware should not enter the Hibernate or Deep Sleep mode until
* flash Erase is complete. The Flash operation is allowed in Sleep mode.
* During the flash operation, the device should not be reset, including the
* XRES pin, a software reset, and watchdog reset sources. Also, the low-voltage
* detect circuits should be configured to generate an interrupt instead of a reset.
* Otherwise, portions of flash may undergo unexpected changes.
* To avoid situation of reading data from cache memory - before
* reading data from previously programmed/erased flash rows, the user must
* clear the flash cache with the Cy_SysLib_ClearFlashCacheAndBuffer()
* function.
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_StartEraseRow(uint32_t rowAddr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
#if !defined (CY_IP_MXS40FLASHC)
    if (Cy_Flash_BoundsCheck(rowAddr) != false)
    {
        SystemCoreClockUpdate();

        /* Prepares arguments to be passed to SROM API */
        flashContext.opcode = CY_FLASH_OPCODE_ERASE_ROW;
        if (SFLASH_SINGLE_CORE != 0U)
        {
            flashContext.opcode |= CY_FLASH_BLOCKING_MODE;
        }

        flashContext.arg1 = rowAddr;
        flashContext.arg2 = 0UL;
        flashContext.arg3 = 0UL;

        if (cy_device->flashEraseDelay != 0U)
        {
            result = Cy_Flash_SendCmd(CY_FLASH_NON_BLOCKING_MODE, CY_FLASH_START_ERASE_DELAY);
        }
        else
        {
            result = Cy_Flash_SendCmd(CY_FLASH_NON_BLOCKING_MODE, CY_FLASH_NO_DELAY);
        }
    }
#else
        boot_rom_context.flags = CYBOOT_FLAGS_NON_BLOCKING;
        uint32_t status = ROM_FUNC->cyboot_flash_erase_row_start(FLASH_SBUS_ALIAS_ADDRESS(rowAddr), &boot_rom_context);
        if(status == (uint32_t)CYBOOT_FLASH_SUCCESS)
        {
            result = CY_FLASH_DRV_OPERATION_STARTED;
        }
        else
        {
            result = Cy_Flash_Process_BootRom_Error_Code(status);
        }
#endif /* !defined (CY_IP_MXS40FLASHC) */

    return (result);
}

#if !defined (CY_IP_MXS40FLASHC)
/*******************************************************************************
* Function Name: Cy_Flash_EraseSector
****************************************************************************//**
*
* This function erases a sector of flash. Reports success or
* a reason for failure. Does not return until the Erase operation is
* complete. Returns immediately and reports a CY_FLASH_DRV_IPC_BUSY error in
* the case when another process is writing to flash or erasing the row.
* User firmware should not enter the Hibernate or Deep Sleep mode until flash Erase
* is complete. The Flash operation is allowed in Sleep mode.
* During the Flash operation, the device should not be reset, including the
* XRES pin, a software reset, and watchdog reset sources. Also, low-voltage
* detect circuits should be configured to generate an interrupt instead of a
* reset. Otherwise, portions of flash may undergo unexpected changes.
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_EraseSector(uint32_t sectorAddr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;

    /* Prepares arguments to be passed to SROM API */
    if (Cy_Flash_BoundsCheck(sectorAddr) != false)
    {
        SystemCoreClockUpdate();

        flashContext.opcode = CY_FLASH_OPCODE_ERASE_SECTOR | CY_FLASH_BLOCKING_MODE;
        flashContext.arg1 = sectorAddr;
        flashContext.arg2 = 0UL;
        flashContext.arg3 = 0UL;

        if (cy_device->flashEraseDelay != 0U)
        {
            result = Cy_Flash_SendCmd(CY_FLASH_BLOCKING_MODE, CY_FLASH_START_ERASE_DELAY);
        }
        else
        {
            result = Cy_Flash_SendCmd(CY_FLASH_BLOCKING_MODE, CY_FLASH_NO_DELAY);
        }
    }

    return (result);
}

/*******************************************************************************
* Function Name: Cy_Flash_StartEraseSector
****************************************************************************//**
*
* Starts erasing a sector of flash. Returns immediately
* and reports a successful start or reason for failure.
* Reports a CY_FLASH_DRV_IPC_BUSY error in the case when IPC structure is locked
* by another process. User firmware should not enter the Hibernate or Deep Sleep mode until
* flash Erase is complete. The Flash operation is allowed in Sleep mode.
* During the flash operation, the device should not be reset, including the
* XRES pin, a software reset, and watchdog reset sources. Also, the low-voltage
* detect circuits should be configured to generate an interrupt instead of a reset.
* Otherwise, portions of flash may undergo unexpected changes.
* Before reading data from previously programmed/erased flash rows, the
* user must clear the flash cache with the Cy_SysLib_ClearFlashCacheAndBuffer()
* function.
*
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_StartEraseSector(uint32_t sectorAddr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;

    if (Cy_Flash_BoundsCheck(sectorAddr) != false)
    {
        SystemCoreClockUpdate();

        /* Prepares arguments to be passed to SROM API */
        flashContext.opcode = CY_FLASH_OPCODE_ERASE_SECTOR;
        if (SFLASH_SINGLE_CORE != 0U)
        {
            flashContext.opcode |= CY_FLASH_BLOCKING_MODE;
        }

        flashContext.arg1 = sectorAddr;
        flashContext.arg2 = 0UL;
        flashContext.arg3 = 0UL;

        if (cy_device->flashEraseDelay != 0U)
        {
            result = Cy_Flash_SendCmd(CY_FLASH_NON_BLOCKING_MODE, CY_FLASH_START_ERASE_DELAY);
        }
        else
        {
            result = Cy_Flash_SendCmd(CY_FLASH_NON_BLOCKING_MODE, CY_FLASH_NO_DELAY);
        }
    }

    return (result);
}

/*******************************************************************************
* Function Name: Cy_Flash_EraseSubsector
****************************************************************************//**
*
* This function erases an 8-row subsector of flash. Reports success or
* a reason for failure. Does not return until the Write operation is
* complete. Returns immediately and reports a CY_FLASH_DRV_IPC_BUSY error in
* the case when another process is writing to flash or erasing the row.
* User firmware should not enter the Hibernate or Deep-Sleep mode until flash Erase
* is complete. The Flash operation is allowed in Sleep mode.
* During the Flash operation, the device should not be reset, including the
* XRES pin, a software reset, and watchdog reset sources. Also, low-voltage
* detect circuits should be configured to generate an interrupt instead of a
* reset. Otherwise, portions of flash may undergo unexpected changes.
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_EraseSubsector(uint32_t subSectorAddr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;

    /* Prepares arguments to be passed to SROM API */
    if (Cy_Flash_BoundsCheck(subSectorAddr) != false)
    {
        SystemCoreClockUpdate();

        flashContext.opcode = CY_FLASH_OPCODE_ERASE_SUB_SECTOR | CY_FLASH_BLOCKING_MODE;
        flashContext.arg1 = subSectorAddr;
        flashContext.arg2 = 0UL;
        flashContext.arg3 = 0UL;

        if (cy_device->flashEraseDelay != 0U)
        {
            result = Cy_Flash_SendCmd(CY_FLASH_BLOCKING_MODE, CY_FLASH_START_ERASE_DELAY);
        }
        else
        {
            result = Cy_Flash_SendCmd(CY_FLASH_BLOCKING_MODE, CY_FLASH_NO_DELAY);
        }
    }

    return (result);
}

/*******************************************************************************
* Function Name: Cy_Flash_StartEraseSubsector
****************************************************************************//**
*
* Starts erasing an 8-row subsector of flash. Returns immediately
* and reports a successful start or reason for failure.
* Reports a CY_FLASH_DRV_IPC_BUSY error in the case when IPC structure is locked
* by another process. User firmware should not enter the Hibernate or Deep-Sleep mode until
* flash Erase is complete. The Flash operation is allowed in Sleep mode.
* During the flash operation, the device should not be reset, including the
* XRES pin, a software reset, and watchdog reset sources. Also, the low-voltage
* detect circuits should be configured to generate an interrupt instead of a reset.
* Otherwise, portions of flash may undergo unexpected changes.
* Before reading data from previously programmed/erased flash rows, the
* user must clear the flash cache with the Cy_SysLib_ClearFlashCacheAndBuffer()
* function.
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_StartEraseSubsector(uint32_t subSectorAddr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;

    if (Cy_Flash_BoundsCheck(subSectorAddr) != false)
    {
        SystemCoreClockUpdate();

        /* Prepares arguments to be passed to SROM API */
        flashContext.opcode = CY_FLASH_OPCODE_ERASE_SUB_SECTOR;
        if (SFLASH_SINGLE_CORE != 0U)
        {
            flashContext.opcode |= CY_FLASH_BLOCKING_MODE;
        }

        flashContext.arg1 = subSectorAddr;
        flashContext.arg2 = 0UL;
        flashContext.arg3 = 0UL;

        if (cy_device->flashEraseDelay != 0U)
        {
            result = Cy_Flash_SendCmd(CY_FLASH_NON_BLOCKING_MODE, CY_FLASH_START_ERASE_DELAY);
        }
        else
        {
            result = Cy_Flash_SendCmd(CY_FLASH_NON_BLOCKING_MODE, CY_FLASH_NO_DELAY);
        }
    }

    return (result);
}
#endif /* !defined (CY_IP_MXS40FLASHC) */

/*******************************************************************************
* Function Name: Cy_Flash_ProgramRow
****************************************************************************//**
*
* This function writes an array of data to a single row of flash. Reports
* success or a reason for failure. Does not return until the Program operation
* is complete.
* Returns immediately and reports a CY_FLASH_DRV_IPC_BUSY error in the case
* when another process is writing to flash. User firmware should not enter the
* Hibernate or Deep-sleep mode until flash Write is complete. The Flash operation
* is allowed in Sleep mode. During the Flash operation, the device should not be
* reset, including the XRES pin, a software reset, and watchdog reset sources.
* Also, low-voltage detect circuits should be configured to generate an interrupt
* instead of a reset. Otherwise, portions of flash may undergo unexpected
* changes.\n
* Before calling this function, the target flash region must be erased by
* the StartErase/EraseRow function.\n
* Data to be programmed must be located in the SRAM memory region.
* Before reading data from previously programmed/erased flash rows, the
* user must clear the flash cache with the Cy_SysLib_ClearFlashCacheAndBuffer()
* function.
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_ProgramRow(uint32_t rowAddr, const uint32_t* data)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;

#if !defined (CY_IP_MXS40FLASHC)
    /* Checks whether the input parameters are valid */
    if ((Cy_Flash_BoundsCheck(rowAddr) != false) && (NULL != data))
    {
        SystemCoreClockUpdate();
        /* Prepares arguments to be passed to SROM API */
        flashContext.opcode = CY_FLASH_OPCODE_PROGRAM_ROW | CY_FLASH_BLOCKING_MODE;
        flashContext.arg1   = CY_FLASH_DATA_LOC_SRAM;
        flashContext.arg2   = rowAddr;
        flashContext.arg3   = (uint32_t)data;

        if (cy_device->flashProgramDelay != 0U)
        {
            result = Cy_Flash_SendCmd(CY_FLASH_BLOCKING_MODE, CY_FLASH_START_PROGRAM_DELAY);
        }
        else
        {
            result = Cy_Flash_SendCmd(CY_FLASH_BLOCKING_MODE, CY_FLASH_NO_DELAY);
        }
    }
#else

        boot_rom_context.flags = CYBOOT_FLAGS_BLOCKING;
        uint32_t status = ROM_FUNC->cyboot_flash_program_row(FLASH_SBUS_ALIAS_ADDRESS(rowAddr), (void *)data, &boot_rom_context);
        result = Cy_Flash_Process_BootRom_Error_Code(status);
#endif /* !defined (CY_IP_MXS40FLASHC) */

    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_WriteRow
****************************************************************************//**
*
* This function writes an array of data to a single row of flash. This is done
* in three steps - pre-program, erase and then program flash row with the input
* data. Reports success or a reason for failure. Does not return until the Write
* operation is complete.
* Returns immediately and reports a CY_FLASH_DRV_IPC_BUSY error in the case
* when another process is writing to flash. User firmware should not enter the
* Hibernate or Deep-sleep mode until flash Write is complete. The Flash operation
* is allowed in Sleep mode. During the Flash operation, the
* device should not be reset, including the XRES pin, a software
* reset, and watchdog reset sources. Also, low-voltage detect
* circuits should be configured to generate an interrupt
* instead of a reset. Otherwise, portions of flash may undergo
* unexpected changes.
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_WriteRow(uint32_t rowAddr, const uint32_t* data)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;

#if !defined (CY_IP_MXS40FLASHC)
    /* Checks whether the input parameters are valid */
    if ((Cy_Flash_BoundsCheck(rowAddr) != false) && (NULL != data))
    {
        SystemCoreClockUpdate();
        /* Prepares arguments to be passed to SROM API */
        flashContext.opcode = CY_FLASH_OPCODE_WRITE_ROW | CY_FLASH_BLOCKING_MODE;
        flashContext.arg1   = 0UL;
        flashContext.arg2   = rowAddr;
        flashContext.arg3   = (uint32_t)data;

        if (cy_device->flashWriteDelay != 0U)
        {
            result = Cy_Flash_SendCmd(CY_FLASH_BLOCKING_MODE, CY_FLASH_START_WRITE_DELAY);
        }
        else
        {
            result = Cy_Flash_SendCmd(CY_FLASH_BLOCKING_MODE, CY_FLASH_NO_DELAY);
        }
    }
#else

        boot_rom_context.flags = CYBOOT_FLAGS_BLOCKING;
        uint32_t status = ROM_FUNC->cyboot_flash_write_row(FLASH_SBUS_ALIAS_ADDRESS(rowAddr), (void *)data, &boot_rom_context);
        result = Cy_Flash_Process_BootRom_Error_Code(status);
#endif /* !defined (CY_IP_MXS40FLASHC) */


    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_StartWrite
****************************************************************************//**
*
* Performs pre-program, erase and then starts programming the flash row with
* the input data. Returns immediately and reports a successful start
* or reason for failure. Reports a CY_FLASH_DRV_IPC_BUSY error
* in the case when another process is writing to flash. User
* firmware should not enter the Hibernate or Deep-Sleep mode until
* flash Write is complete. The Flash operation is allowed in Sleep mode.
* During the flash operation, the device should not be reset, including the
* XRES pin, a software reset, and watchdog reset sources. Also, the low-voltage
* detect circuits should be configured to generate an interrupt instead of a reset.
* Otherwise, portions of flash may undergo unexpected changes.
* Before reading data from previously programmed/erased flash rows, the
* user must clear the flash cache with the Cy_SysLib_ClearFlashCacheAndBuffer()
* function.
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_StartWrite(uint32_t rowAddr, const uint32_t* data)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
#if !defined (CY_IP_MXS40FLASHC)
    /* Checks whether the input parameters are valid */
    if ((Cy_Flash_BoundsCheck(rowAddr) != false) && (NULL != data))
    {
        result = Cy_Flash_StartEraseRow(rowAddr);

        if (CY_FLASH_DRV_OPERATION_STARTED == result)
        {
            /* Polls whether the IPC is released and the Flash operation is performed */
            do
            {
                result = Cy_Flash_OperationStatus();
            }
            while (result == CY_FLASH_DRV_OPCODE_BUSY);

            if (CY_FLASH_DRV_SUCCESS == result)
            {
                result = Cy_Flash_StartProgram(rowAddr, data);
            }
        }

    }

#else
        boot_rom_context.flags = CYBOOT_FLAGS_NON_BLOCKING;
        uint32_t status = ROM_FUNC->cyboot_flash_write_row_start(FLASH_SBUS_ALIAS_ADDRESS(rowAddr), (void *)data, &boot_rom_context);
        if(status == (uint32_t)CYBOOT_FLASH_SUCCESS)
        {
            result = CY_FLASH_DRV_OPERATION_STARTED;
        }
        else
        {
            result = Cy_Flash_Process_BootRom_Error_Code(status);
        }
#endif /* !defined (CY_IP_MXS40FLASHC) */
    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_IsOperationComplete
****************************************************************************//**
*
* Reports a successful operation result, reason of failure or busy status
* ( CY_FLASH_DRV_OPCODE_BUSY ).
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_IsOperationComplete(void)
{
    return (Cy_Flash_OperationStatus());
}


/*******************************************************************************
* Function Name: Cy_Flash_StartProgram
****************************************************************************//**
*
* Starts writing an array of data to a single row of flash. Returns immediately
* and reports a successful start or reason for failure.
* Reports a CY_FLASH_DRV_IPC_BUSY error if another process is writing
* to flash. The user firmware should not enter Hibernate or Deep-Sleep mode until flash
* Program is complete. The Flash operation is allowed in Sleep mode.
* During the Flash operation, the device should not be reset, including the
* XRES pin, a software reset, and watchdog reset sources. Also, the low-voltage
* detect circuits should be configured to generate an interrupt instead of a reset.
* Otherwise, portions of flash may undergo unexpected changes.\n
* Before calling this function, the target flash region must be erased by
* the StartEraseRow/EraseRow function.\n
* Data to be programmed must be located in the SRAM memory region.
* Before reading data from previously programmed/erased flash rows, the
* user must clear the flash cache with the Cy_SysLib_ClearFlashCacheAndBuffer()
* function.
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_StartProgram(uint32_t rowAddr, const uint32_t* data)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
#if !defined (CY_IP_MXS40FLASHC)
    if ((Cy_Flash_BoundsCheck(rowAddr) != false) && (NULL != data))
    {
        SystemCoreClockUpdate();
        /* Prepares arguments to be passed to SROM API */
        flashContext.opcode = CY_FLASH_OPCODE_PROGRAM_ROW;

        if (SFLASH_SINGLE_CORE != 0U)
        {
            flashContext.opcode |= CY_FLASH_BLOCKING_MODE;
        }

        flashContext.arg1   = CY_FLASH_DATA_LOC_SRAM;
        flashContext.arg2   = rowAddr;
        flashContext.arg3   = (uint32_t)data;

        if (cy_device->flashProgramDelay != 0U)
        {
            result = Cy_Flash_SendCmd(CY_FLASH_NON_BLOCKING_MODE, CY_FLASH_START_PROGRAM_DELAY);
        }
        else
        {
            result = Cy_Flash_SendCmd(CY_FLASH_NON_BLOCKING_MODE, CY_FLASH_NO_DELAY);
        }
    }
#else
        boot_rom_context.flags = CYBOOT_FLAGS_NON_BLOCKING;
        uint32_t status = ROM_FUNC->cyboot_flash_program_row_start(FLASH_SBUS_ALIAS_ADDRESS(rowAddr), (void *)data, &boot_rom_context);
        if(status == (uint32_t)CYBOOT_FLASH_SUCCESS)
        {
            result = CY_FLASH_DRV_OPERATION_STARTED;
        }
        else
        {
            result = Cy_Flash_Process_BootRom_Error_Code(status);
        }
#endif /* !defined (CY_IP_MXS40FLASHC) */

    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_RowChecksum
****************************************************************************//**
*
* Returns a checksum value of the specified flash row.
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_RowChecksum (uint32_t rowAddr, uint32_t* checksumPtr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
#if !defined (CY_IP_MXS40FLASHC)
    /* Checks whether the input parameters are valid */
    if ((Cy_Flash_BoundsCheck(rowAddr) != false) && (NULL != checksumPtr))
    {

        uint32_t resTmp;
        uint32_t rowID;
        rowID = Cy_Flash_GetRowNum(rowAddr);

        /* Prepares arguments to be passed to SROM API */
        flashContext.opcode = CY_FLASH_OPCODE_CHECKSUM |
                              (((rowID >> CY_FLASH_REGION_ID_SHIFT) & CY_FLASH_REGION_ID_MASK) << CY_FLASH_OPCODE_CHECKSUM_REGION_SHIFT) |
                              ((rowID & CY_FLASH_ROW_ID_MASK) << CY_FLASH_OPCODE_CHECKSUM_ROW_SHIFT);

        /* Tries to acquire the IPC structure and pass the arguments to SROM API */
        if (Cy_IPC_Drv_SendMsgPtr(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_SYSCALL), CY_FLASH_IPC_NOTIFY_STRUCT0,
                                  (void*)&flashContext) == CY_IPC_DRV_SUCCESS)
        {
            /* Polls whether IPC is released and the Flash operation is performed */
            while (Cy_IPC_Drv_IsLockAcquired(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_SYSCALL)) != false)
            {
                /* Wait till IPC is released */
            }

            resTmp = flashContext.opcode >> CY_FLASH_ERROR_SHIFT;

            if (resTmp == CY_FLASH_ERROR_NO_ERROR)
            {
                result = CY_FLASH_DRV_SUCCESS;

                if (CY_IPC_V1)
                {
                    *checksumPtr = flashContext.opcode & CY_FLASH_RESULT_MASK;
                }
                else
                {
                    *checksumPtr = REG_IPC_STRUCT_DATA1(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_SYSCALL));
                }
            }
            else
            {
                result = Cy_Flash_ProcessOpcode(flashContext.opcode);
            }

        }
        else
        {
            /* The IPC structure is already locked by another process */
            result = CY_FLASH_DRV_IPC_BUSY;
        }
    }
#else
        uint32_t startAddress, endAddress;
        volatile uint32_t i, j;
        uint32_t checksum_value=0U;

        startAddress = FLASH_SBUS_ALIAS_ADDRESS(rowAddr);
        endAddress = startAddress + CY_FLASH_SIZEOF_ROW;

        i = startAddress;
        j = endAddress;
        do
        {
            checksum_value += REG8(i);
            i++;
            j--;
        }while(i<endAddress);
        *checksumPtr = checksum_value;
        result = CY_FLASH_DRV_SUCCESS;
#endif /* !defined (CY_IP_MXS40FLASHC) */

    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_CalculateHash
****************************************************************************//**
*
* Returns a hash value of the specified region of flash.
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_CalculateHash (const uint32_t* data, uint32_t numberOfBytes,  uint32_t* hashPtr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;

    /* Checks whether the input parameters are valid */
    if ((data != NULL) && (0UL != numberOfBytes))
    {
#if !defined (CY_IP_MXS40FLASHC)
        volatile uint32_t resTmp;
        /* Prepares arguments to be passed to SROM API */
        flashContext.opcode = CY_FLASH_OPCODE_HASH;
        flashContext.arg1 = (uint32_t)data;
        flashContext.arg2 = numberOfBytes;

        /* Tries to acquire the IPC structure and pass the arguments to SROM API */
        if (Cy_IPC_Drv_SendMsgPtr(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_SYSCALL), CY_FLASH_IPC_NOTIFY_STRUCT0,
                                  (void*)&flashContext) == CY_IPC_DRV_SUCCESS)
        {
            /* Polls whether IPC is released and the Flash operation is performed */
            while (Cy_IPC_Drv_IsLockAcquired(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_SYSCALL)) != false)
            {
                /* Wait till IPC is released */
            }

            resTmp = flashContext.opcode;

            if ((resTmp >> CY_FLASH_ERROR_SHIFT) == CY_FLASH_ERROR_NO_ERROR)
            {
                result = CY_FLASH_DRV_SUCCESS;
                *hashPtr = flashContext.opcode & CY_FLASH_RESULT_MASK;
            }
            else
            {
                result = Cy_Flash_ProcessOpcode(flashContext.opcode);
            }
        }
        else
        {
            /* The IPC structure is already locked by another process */
            result = CY_FLASH_DRV_IPC_BUSY;
        }
#else
        *hashPtr = (uint32_t)Cy_Flash_GetHash((uint32_t)FLASH_SBUS_ALIAS_ADDRESS(data), numberOfBytes);
        result = CY_FLASH_DRV_SUCCESS;

#endif /* !defined (CY_IP_MXS40FLASHC) */
    }

    return (result);
}

#if !defined (CY_IP_MXS40FLASHC)
/*******************************************************************************
* Function Name: Cy_Flash_GetRowNum
****************************************************************************//**
*
* Returns flash region ID and row number of the Flash address.
*******************************************************************************/
static uint32_t Cy_Flash_GetRowNum(uint32_t flashAddr)
{
    uint32_t result;

#if (CY_EM_EEPROM_SIZE>0)
    if ((flashAddr >= CY_EM_EEPROM_BASE) && (flashAddr < (CY_EM_EEPROM_BASE + CY_EM_EEPROM_SIZE)))
    {
        result = (CY_FLASH_REGION_ID_EM_EEPROM << CY_FLASH_REGION_ID_SHIFT) |
                 ((flashAddr - CY_EM_EEPROM_BASE) / CY_FLASH_SIZEOF_ROW);
    }
    else
#endif
    if ((flashAddr >= SFLASH_BASE) && (flashAddr < (SFLASH_BASE + SFLASH_SECTION_SIZE)))
    {
        result = (CY_FLASH_REGION_ID_SFLASH << CY_FLASH_REGION_ID_SHIFT) |
                 ((flashAddr - SFLASH_BASE) / CY_FLASH_SIZEOF_ROW);
    }
    else
    {
        result = (CY_FLASH_REGION_ID_MAIN << CY_FLASH_REGION_ID_SHIFT) |
                 ((flashAddr - CY_FLASH_BASE) / CY_FLASH_SIZEOF_ROW);
    }

    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_BoundsCheck
****************************************************************************//**
*
* The function checks the following conditions:
*  - if Flash address is equal to start address of the row
*******************************************************************************/
static bool Cy_Flash_BoundsCheck(uint32_t flashAddr)
{
    return ((flashAddr % CY_FLASH_SIZEOF_ROW) == 0UL);
}


/*******************************************************************************
* Function Name: Cy_Flash_ProcessOpcode
****************************************************************************//**
*
* Converts System Call returns to the Flash driver return defines.
*******************************************************************************/
static cy_en_flashdrv_status_t Cy_Flash_ProcessOpcode(uint32_t opcode)
{
    cy_en_flashdrv_status_t result;

    switch (opcode)
    {
        case 0UL:
        {
            result = CY_FLASH_DRV_SUCCESS;
            break;
        }
        case CY_FLASH_ROMCODE_SUCCESS:
        {
            result = CY_FLASH_DRV_SUCCESS;
            break;
        }
        case CY_FLASH_ROMCODE_INVALID_PROTECTION:
        {
            result = CY_FLASH_DRV_INV_PROT;
            break;
        }
        case CY_FLASH_ROMCODE_INVALID_FM_PL:
        {
            result = CY_FLASH_DRV_INVALID_FM_PL;
            break;
        }
        case CY_FLASH_ROMCODE_INVALID_FLASH_ADDR:
        {
            result = CY_FLASH_DRV_INVALID_FLASH_ADDR;
            break;
        }
        case CY_FLASH_ROMCODE_ROW_PROTECTED:
        {
            result = CY_FLASH_DRV_ROW_PROTECTED;
            break;
        }
        case CY_FLASH_ROMCODE_IN_PROGRESS_NO_ERROR:
        {
            result = CY_FLASH_DRV_PROGRESS_NO_ERROR;
            break;
        }
        case (uint32_t)CY_FLASH_DRV_INVALID_INPUT_PARAMETERS:
        {
            result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
            break;
        }
        case CY_FLASH_IS_OPERATION_STARTED :
        {
            result = CY_FLASH_DRV_OPERATION_STARTED;
            break;
        }
        case CY_FLASH_IS_BUSY :
        {
            result = CY_FLASH_DRV_OPCODE_BUSY;
            break;
        }
        case CY_FLASH_IS_IPC_BUSY :
        {
            result = CY_FLASH_DRV_IPC_BUSY;
            break;
        }
        case CY_FLASH_IS_INVALID_INPUT_PARAMETERS :
        {
            result = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
            break;
        }
        default:
        {
            result = CY_FLASH_DRV_ERR_UNC;
            break;
        }
    }

    return (result);
}
#endif /* !defined (CY_IP_MXS40FLASHC) */

/*******************************************************************************
* Function Name: Cy_Flash_OperationStatus
****************************************************************************//**
*
* Checks the status of the Flash Operation, and returns it.
*******************************************************************************/
static cy_en_flashdrv_status_t Cy_Flash_OperationStatus(void)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_OPCODE_BUSY;
#if !defined (CY_IP_MXS40FLASHC)
    /* Checks if the IPC structure is not locked */
    if (Cy_IPC_Drv_IsLockAcquired(Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_SYSCALL)) == false)
    {
        /* The result of SROM API calling is returned to the driver context */
        result = Cy_Flash_ProcessOpcode(flashContext.opcode);

        /* Clear pre-fetch cache after flash operation */
        #if CY_CPU_CORTEX_M4 && defined (CY_DEVICE_SECURE)
            CY_PRA_REG32_SET(CY_PRA_INDX_FLASHC_FLASH_CMD, FLASHC_FLASH_CMD_INV_Msk);
            while (CY_PRA_REG32_GET(CY_PRA_INDX_FLASHC_FLASH_CMD) != 0U)
            {
            }
        #else
            FLASHC_FLASH_CMD = FLASHC_FLASH_CMD_INV_Msk;
            while (FLASHC_FLASH_CMD != 0U)
            {
            }
        #endif /* CY_CPU_CORTEX_M4 && defined (CY_DEVICE_SECURE) */
    }
#else
    if(ROM_FUNC->cyboot_is_flash_ready(&boot_rom_context))
    {
        return CY_FLASH_DRV_SUCCESS;
    }
#endif /* !defined (CY_IP_MXS40FLASHC) */
    return (result);
}


/*******************************************************************************
* Function Name: Cy_Flash_GetExternalStatus
****************************************************************************//**
*
* This function handles the case where a module such as security image captures
* a system call from this driver and reports its own status or error code,
* for example protection violation. In that case, a function from this
* driver returns an unknown error (see cy_en_flashdrv_status_t). After receipt
* of an unknown error, the user may call this function to get the status
* of the capturing module.
*
* The user is responsible for parsing the content of the returned value
* and casting it to the appropriate enumeration.
*******************************************************************************/
uint32_t Cy_Flash_GetExternalStatus(void)
{
#if !defined (CY_IP_MXS40FLASHC)
    return (flashContext.opcode);
#else
    if(Cy_Flash_IsOperationComplete() == CY_FLASH_DRV_SUCCESS)
    {
        return (uint32_t)CY_FLASH_DRV_SUCCESS;
    }
    else
    {
        return (uint32_t)CY_FLASH_DRV_OPCODE_BUSY;
    }
#endif /* !defined (CY_IP_MXS40FLASHC) */
}


#if defined (CY_IP_MXS40FLASHC)

/** \cond INTERNAL */

/*******************************************************************************
* Function Name: memcpy8
********************************************************************************
* Performs a fast memcpy4 by unrolling a loop.
* \param dst    A pointer to a destination buffer, should be aligned to 4 bytes.
* \param src    A pointer to a source buffer, should be aligned to 4 bytes.
* \param size   A size in byte to be copied, must be a multiple of 8 bytes
*******************************************************************************/
static void memcpy8(uint32_t *dst, const uint32_t *src, uint32_t size)
{
    do
    {
        dst[0] = src[0];
        dst[1] = src[1];
        dst = &dst[2];
        src = &src[2];
        size -= 8UL;
    } while (size != 0UL);
}

/*******************************************************************************
* Function Name: cy_flash_scratch_row_addr
********************************************************************************
* Computes an address for a flash scratch row \c scratch_row_idx in a sector
* \c sector_idx.
* \param sector_idx         A flash sector.
* \param scratch_row_idx    A flash scratch row index within a flash sector.
*
* \returns An address for a flash scratch row.
*******************************************************************************/
static uint32_t cy_flash_scratch_row_addr(uint32_t sector_idx, uint32_t scratch_row_idx)
{
    return CYBOOT_SCRATCH_BASE_ADDR
            + (sector_idx * (CYBOOT_N_SCRATCH_ROWS * CY_FLASH_ROW_SIZE))
            + (scratch_row_idx * CY_FLASH_ROW_SIZE);
}

/*******************************************************************************
* Function Name: cy_flash_refresh_perform
********************************************************************************
* Performs a blocking flash refresh operation for one flash sector.
* \param sector_idx     A sector index.
* \param refresh        A pointer to a single refresh structure.
*
* \returns  A status code.
*******************************************************************************/
static cy_en_flashdrv_status_t cy_flash_refresh_perform(uint32_t sector_idx, cyboot_flash_refresh_t *refresh)
{
    cyboot_flash_context_t ctx = { 0UL, };

    /* An index for flash row's column 33 in uint32_t[] */
    uint32_t COL33_IDX = (CY_FLASH_ROW_SIZE / sizeof(uint32_t));
    cyboot_flash_row_t row_data;
    uint32_t ret = CYBOOT_FLASH_FAILED;
    uint32_t scratch_addr;
    uint32_t min_addr;
    ctx.flags = CY_FLASH_MODE_REFRESH_MANUAL;

    if (!ROM_FUNC->cyboot_flash_refresh_test(refresh))
    {
        return CY_FLASH_DRV_REFRESH_NOTHING;
    }

    scratch_addr = cy_flash_scratch_row_addr(sector_idx, refresh->scratch_row_idx);
    refresh->scratch_row_idx = (refresh->scratch_row_idx + 1UL) % CYBOOT_N_SCRATCH_ROWS;
    min_addr = refresh->min_page_addr;

    memcpy8((uint32_t *)row_data, (uint32_t *)min_addr, CY_FLASH_ROW_SIZE);
    ++refresh->max_count;
    row_data[COL33_IDX      ] = CYBOOT_FLASH_REFRESH_TAG;
    row_data[COL33_IDX + 1UL] = refresh->max_count;
    row_data[COL33_IDX + 2UL] = min_addr;
    row_data[COL33_IDX + 3UL] = 0UL;
    (void)ROM_FUNC->cyboot_flash_write_row(scratch_addr, row_data, &ctx);

    CY_SET_REG32(0x52152A10, 0x01000000); /* if_sel=1 (FLASH_MACRO_CTL) */
    CY_SET_REG32(0x52152A58, 0x00000001); /* ACLK  (ACLK_CTL) */
    CY_SET_REG32(0x52152A10, 0x00000000); /* if_sel=0  (FLASH_MACRO_CTL) */

    ++refresh->max_count;
    row_data[COL33_IDX + 1UL] = refresh->max_count;
    row_data[COL33_IDX + 2UL] = 0UL;
    ret = ROM_FUNC->cyboot_flash_write_row(min_addr, row_data, &ctx);
    if (CYBOOT_FLASH_SUCCESS == ret)
    {
        ROM_FUNC->cyboot_flash_refresh_get_min_max(sector_idx, refresh);
    }

    return Cy_Flash_Process_BootRom_Error_Code(ret);
}
/** \endcond */

/*******************************************************************************
* Function Name: Cy_Flash_Refresh
****************************************************************************//**
*
* This is a blocking call.
* Writes to the flash will cause slight degradation of the other cells in the flash.
* If the flash is written more than 100,000 times, errors may appear on flash reads.
* To prevent this, the refresh functions should be called before or after flash writes.
* The refresh functions are not available on CPUSS_FLASHC_SFLASH_SECNUM because it includes the SFLASH.
*
* param address of the row that needs to be refreshed.
*
* return success if refresh is complete. will return err
*
* \note Refresh is not allowed on sector which has SFLASH. That sector must be left immutable.
*       This is a blocking call.
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_Refresh(uint32_t flashAddr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_REFRESH_NOT_ENABLED;
    if (IS_FLASH_ADDRESS_IN_SFLASH_SECNUM(FLASH_SBUS_ALIAS_ADDRESS(flashAddr)))
    {
        return CY_FLASH_DRV_REFRESH_NOT_SUPPORTED;
    }
    if (refresh_feature_enable)
    {
        uint32_t sector_Idx;
        uint32_t row_Idx;
        uint32_t status = ROM_FUNC->cyboot_flash_refresh_get_sector_idx(FLASH_SBUS_ALIAS_ADDRESS(flashAddr), &sector_Idx, &row_Idx);
        (void)row_Idx;

        if (status == CYBOOT_FLASH_SUCCESS)
        {
        #if defined(CY_DEVICE_PSC3)
            result = (cy_en_flashdrv_status_t)cy_flash_refresh_perform(sector_Idx, flash_refresh);
        #else
            status = ROM_FUNC->cyboot_flash_refresh_perform(sector_Idx, flash_refresh);
            result = Cy_Flash_Process_BootRom_Error_Code(status);
        #endif
        }
        else
        {
            result = Cy_Flash_Process_BootRom_Error_Code(status);
        }
    }
    return result;
}

/*******************************************************************************
* Function Name: Cy_Flash_Refresh_Start
****************************************************************************//**
*
* This is a non-blocking call.
* Writes to the flash will cause slight degradation of the other cells in the flash.
* If the flash is written more than 100,000 times, errors may appear on flash reads.
* To prevent this, the refresh functions should be called before or after flash writes.
* The refresh functions are not available on CPUSS_FLASHC_SFLASH_SECNUM because it includes the SFLASH.
*
* \param address of the row that needs to be refreshed.
*
* \return success if refresh is started. Else will return err
*
*
*******************************************************************************/
cy_en_flashdrv_status_t Cy_Flash_Refresh_Start(uint32_t flashAddr)
{
    cy_en_flashdrv_status_t result = CY_FLASH_DRV_REFRESH_NOT_ENABLED;
    if (IS_FLASH_ADDRESS_IN_SFLASH_SECNUM(FLASH_SBUS_ALIAS_ADDRESS(flashAddr)))
    {
        return CY_FLASH_DRV_REFRESH_NOT_SUPPORTED;
    }
    if (refresh_feature_enable)
    {
        uint32_t sector_Idx;
        uint32_t row_Idx;
        uint32_t status = ROM_FUNC->cyboot_flash_refresh_get_sector_idx(FLASH_SBUS_ALIAS_ADDRESS(flashAddr), &sector_Idx, &row_Idx);
        if (status == CYBOOT_FLASH_SUCCESS)
        {
            status = ROM_FUNC->cyboot_flash_refresh_perform_start(sector_Idx, flash_refresh, &boot_rom_context);
            if (status == (uint32_t)CYBOOT_FLASH_SUCCESS)
            {
                return CY_FLASH_DRV_OPERATION_STARTED;
            }
        }
        (void)row_Idx;
        result = Cy_Flash_Process_BootRom_Error_Code(status);
    }
    return result;
}
/*****************************************************************************
* Function Name: GetHash()
******************************************************************************
* Summary:
*  This function computes the hash based on formula
*  H(n+1)=(H(n)*2+Byte)%127,where H(0)=0
*
* Parameters:
*  uint32_t startAddr - 32 bit system address of  first byte of data chunk
*  uint32_t numberOfBytes    - total number of bytes of data chunk on which hash needs
*  to be computed

* Return:
*  uint8_t hash
*
* Calls:
*  None
*
* Called by:
*  Boot
*
* Note:
*  cHash represents the calculated hash (H in the above formula).
*  HASH_CALC_DIVISOR = 127 and HASH_CALC_DIVISOR_LEN = 7
*  Mod 127 is calculated using the following method.
*  Any number N (< 128*127 + 127 = 16383) can be represented in the form of
*  N = 128*A + B = 127*A + A + B. Thus, N mod 127 can be calculated from A + B.
*  If A + B == 254, then N mod 127 = 0
*  Else if A + B >= 127, then N mod 127 = A + B - 127
*  Else N mod 127 = A + B
*  For the given implementation, N < 255*2 + 255 = 766. Hence, A + B < 254
*  This method reduces the computational cost by avoiding divide operation.
*****************************************************************************/
static uint8_t Cy_Flash_GetHash(uint32_t startAddr,uint32_t numberOfBytes)
{
    uint32_t i;
    uint8_t hash = 0U;
    uint32_t cHashSum;

     uint8_t cData, cHigherPart, cLowerPart;
    for (i = 0U; i < numberOfBytes; i++)
    {
        cData = REG8(startAddr + i);
        cHashSum = (((uint32_t) hash << 1U) + cData);
         /* PRQA S 2985 4 */ /* FIXMISRA */ /* MISRA C:2012 Rule 2.2 Required
            This operation is redundant. The value of the result is always that of the left-hand operand.
            The cHashSum equals cData, that is 8-bit value, shifted left by 7 bit (HASH_CALC_DIVISOR_LEN).
        */
        cHigherPart = (uint8_t)(cHashSum >> HASH_CALC_DIVISOR_LEN) & HASH_CALC_DIVISOR;
        cLowerPart = (uint8_t) (cHashSum & HASH_CALC_DIVISOR);
        hash = ( (cHigherPart + cLowerPart) >=  HASH_CALC_DIVISOR ) ? (cHigherPart + cLowerPart - HASH_CALC_DIVISOR) :
                 (cHigherPart + cLowerPart);
    }
    return hash;
}

/*******************************************************************************
* Function Name: Cy_Flashc_ECCEnable
****************************************************************************//**
*
* \brief Enables ECC for flash
* ECC checking/reporting on FLASH interface is enabled.
* Correctable or non-correctable faults are reported by enabling ECC.
*
* \return none
*
*******************************************************************************/
void Cy_Flashc_ECCEnable(void)
{
    FLASHC_FLASH_CTL |= FLASHC_FLASH_CTL_ECC_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_Flashc_ECCDisable
****************************************************************************//**
*
* \brief Disables ECC for flash
* ECC checking/reporting on FLASH interface is disabled.
* Correctable or non-correctable faults are not reported by disabling ECC.
*
* \return none
*
*******************************************************************************/
void Cy_Flashc_ECCDisable(void)
{
    FLASHC_FLASH_CTL &= (uint32_t) ~FLASHC_FLASH_CTL_ECC_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_Flashc_INJ_ECCEnable
****************************************************************************//**
*
* This function enable ECC error injection for FLASH interface
* And is applicable while ECC is enabled.
*
* \return none
*
*******************************************************************************/
void Cy_Flashc_INJ_ECCEnable(void)
{
    FLASHC_FLASH_ECC_INJ_EN |= (FLASHC_ECC_INJ_EN_ECC_INJ_ENABLE_Msk |
                               FLASHC_ECC_INJ_EN_ECC_ERROR_Msk);
}

/*******************************************************************************
* Function Name: Cy_Flashc_INJ_ECCDisable
****************************************************************************//**
*
* This function disables ECC error injection for FLASH interface
*
* \return none
*
*******************************************************************************/
void Cy_Flashc_INJ_ECCDisable(void)
{
    FLASHC_FLASH_ECC_INJ_EN &= (uint32_t) ~(FLASHC_ECC_INJ_EN_ECC_INJ_ENABLE_Msk |
                               FLASHC_ECC_INJ_EN_ECC_ERROR_Msk);
}


/*******************************************************************************
* Function Name: Cy_Flashc_InjectECC
****************************************************************************//**
*
* This function enables ECC injection and sets the address where a parity will be injected
* and the parity value.
* Reports success or a reason for failure.
*
* \address The address where ECC parity will be injected.
*
* \parity The parity value which will be injected.
*
* \returns none
*
*******************************************************************************/
void Cy_Flashc_InjectECC(uint32_t address, uint8_t parity)
{
    FLASHC_FLASH_ECC_INJ_CTL = (_VAL2FLD(FLASHC_ECC_INJ_CTL_WORD_ADDR, address) |
                                _VAL2FLD(FLASHC_ECC_INJ_CTL_PARITY, parity ));
}

/*******************************************************************************
* Function Name: Cy_Flashc_Get_ECC_Error
****************************************************************************//**
*
* \brief This function when ECC injection is enabled and error is injected will return no of errors generated.
*
* \returns no of errors generated with ECC error injection \ref cy_en_flash_ecc_inject_errors_t.
*
*******************************************************************************/
cy_en_flash_ecc_inject_errors_t Cy_Flashc_Get_ECC_Error(void)
{
    if (0UL != _FLD2VAL(FLASHC_ECC_INJ_EN_ECC_ERROR, FLASHC_FLASH_ECC_INJ_EN))
    {
        return CY_FLASH_ECC_ERRORS_MORE_THAN_ONE;
    }
    return CY_FLASH_ECC_ERRORS_LESS_THAN_TWO;
}


/*******************************************************************************
* Function Name: Cy_Flashc_Dual_Bank_Mode_Enable
****************************************************************************//**
*
* \brief Enables Dual bank Mode for flash
*
* \param mapping : Mapping for the main and work regions.
*
* \return none
*
*******************************************************************************/
void Cy_Flashc_Dual_Bank_Mode_Enable(cy_en_flash_dual_bank_mapping_t mapping)
{
    FLASHC_FLASH_CTL |= (_VAL2FLD(FLASHC_FLASH_CTL_BANK_MODE, 1U) |
                         _VAL2FLD(FLASHC_FLASH_CTL_BANK_MAPPING, mapping ));;
}

/*******************************************************************************
* Function Name: Cy_Flashc_Dual_Bank_Mode_Disable
****************************************************************************//**
*
* \brief Disables Dual bank Mode for flash
*
* \return none
*
*******************************************************************************/
void Cy_Flashc_Dual_Bank_Mode_Disable(void)
{
    FLASHC_FLASH_CTL &= (uint32_t) ~(FLASHC_FLASH_CTL_BANK_MODE_Msk |
                                     FLASHC_FLASH_CTL_BANK_MAPPING_Msk);
}


#endif /*defined (CY_IP_MXS40FLASHC)*/

#if (defined (CY_IP_M4CPUSS) && (CY_IP_M4CPUSS_VERSION >=2))
/*******************************************************************************
* Function Name: Cy_Flashc_SetWorkBankMode
****************************************************************************//**
*
* Sets bank mode for work flash
*
* mode bank mode to be set
*
*******************************************************************************/
void Cy_Flashc_SetWorkBankMode(cy_en_bankmode_t mode)
{
    if(CY_FLASH_DUAL_BANK_MODE == mode)
    {
        FLASHC_FLASH_CTL |= FLASHC_V2_FLASH_CTL_WORK_BANK_MODE_Msk;
    }
    else
    {
        FLASHC_FLASH_CTL &= (uint32_t) ~FLASHC_V2_FLASH_CTL_WORK_BANK_MODE_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_Flashc_GetWorkBankMode
****************************************************************************//**
*
* Gets current bank mode for work flash
*
*******************************************************************************/
cy_en_bankmode_t Cy_Flashc_GetWorkBankMode(void)
{
   uint32_t bank_mode = _FLD2VAL(FLASHC_V2_FLASH_CTL_WORK_BANK_MODE, FLASHC_FLASH_CTL);
   if(bank_mode == 0UL)
    {
        return CY_FLASH_SINGLE_BANK_MODE;
    }
    else
    {
        return CY_FLASH_DUAL_BANK_MODE;
    }
}
/*******************************************************************************
* Function Name: Cy_Flashc_SetMainBankMode
****************************************************************************//**
*
*  Sets bank mode for main flash
*
*  mode bank mode to be set
*
*******************************************************************************/
void Cy_Flashc_SetMainBankMode(cy_en_bankmode_t mode)
{
   if(CY_FLASH_DUAL_BANK_MODE == mode)
    {
        FLASHC_FLASH_CTL |= FLASHC_V2_FLASH_CTL_MAIN_BANK_MODE_Msk;
    }
    else
    {
        FLASHC_FLASH_CTL &= (uint32_t) ~FLASHC_V2_FLASH_CTL_MAIN_BANK_MODE_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_Flashc_GetMainBankMode
****************************************************************************//**
*
*  Gets current bank mode for main flash
*
*******************************************************************************/
cy_en_bankmode_t Cy_Flashc_GetMainBankMode(void)
{
    uint32_t bank_mode = _FLD2VAL(FLASHC_V2_FLASH_CTL_MAIN_BANK_MODE, FLASHC_FLASH_CTL);
    if(bank_mode == 0UL)
    {
        return CY_FLASH_SINGLE_BANK_MODE;
    }
    else
    {
        return CY_FLASH_DUAL_BANK_MODE;
    }
}

/*******************************************************************************
* Function Name: Cy_Flashc_SetMain_Flash_Mapping
****************************************************************************//**
*
* \brief Sets mapping for main flash region. Applicable only in Dual Bank mode of Main flash region
*
* \param mapping mapping to be set
*
* \return none
*******************************************************************************/
void Cy_Flashc_SetMain_Flash_Mapping(cy_en_maptype_t  mapping)
{
    FLASHC_FLASH_CTL &= ~FLASHC_V2_FLASH_CTL_MAIN_MAP_Msk;
    FLASHC_FLASH_CTL |= _VAL2FLD(FLASHC_V2_FLASH_CTL_MAIN_MAP, mapping);
}

/*******************************************************************************
* Function Name: Cy_Flashc_SetWork_Flash_Mapping
****************************************************************************//**
*
* \brief Sets mapping for work flash region. Applicable only in Dual Bank mode of Work flash region
*
* \param mapping mapping to be set
*
* \return none
*******************************************************************************/
void Cy_Flashc_SetWork_Flash_Mapping(cy_en_maptype_t mapping)
{
    FLASHC_FLASH_CTL &= ~FLASHC_V2_FLASH_CTL_WORK_MAP_Msk;
    FLASHC_FLASH_CTL |= _VAL2FLD(FLASHC_V2_FLASH_CTL_WORK_MAP, mapping);
}

#endif /* (defined (CY_IP_M4CPUSS) && (CY_IP_M4CPUSS_VERSION >=2)) */
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')
#endif /* CY_IP_M4CPUSS */

/* [] END OF FILE */
