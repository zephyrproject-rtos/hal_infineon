/***************************************************************************//**
* \file system_xmc5000_cm0plus.c
* \version 2.120
*
* The device system-source file.
*
********************************************************************************
* \copyright
* Copyright 2016-2025 Infineon Technologies AG, or an affiliate of Infineon Technologies AG.
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

#include <stdbool.h>
#include "system_psoc6.h"
#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_syslib.h"
#include "cy_sysclk.h"
#include "cy_wdt.h"

#if defined(CY_DEVICE_XMC5000)

#include "cmsis_compiler.h"

#include "xmc5000_partition.h"

#define FIXED_EXP_NR            (15u)
#define VECTORTABLE_SIZE        (16u + FIXED_EXP_NR + 1u) /* +1 is for Stack pointer */
#define VECTORTABLE_ALIGN       (128) /* alignment for 85 entries (32x4=128) is 2^7=128 bytes */

#define FIXED_EXP_NR            (15u)
#define VECTORTABLE_SIZE        (16u + FIXED_EXP_NR + 1u) /* +1 is for Stack pointer */
#define VECTORTABLE_ALIGN       (128) /* alignment for 85 entries (32x4=128) is 2^7=128 bytes */

#define CY_SYS_CM4_PWR_CTL_KEY_OPEN  (0x05FAUL)
#define CY_SYS_CM4_PWR_CTL_KEY_CLOSE (0xFA05UL)
#define CY_SYS_CM4_VECTOR_TABLE_VALID_ADDR  (0x000003FFUL)

static void EnableEcc(void);
static void PrepareSystemCallInfrastructure(void);

extern uint32_t Cy_u32StartupStackStartAddress;
extern uint32_t Cy_u32StartupStackEndAddress;
extern cy_israddress __ramVectors[];

/* Interrupt Logic */

static void SystemIrqInit(void);
void Cy_DefaultUserHandler(void);

#define DEFAULT_HANDLER_NAME Cy_DefaultUserHandler

CY_NOINIT cy_israddress Cy_SystemIrqUserTable[CPUSS_SYSTEM_INT_NR] ;
CY_NOINIT cy_israddress * Cy_SysInt_SystemIrqUserTableRamPointer ;
__STATIC_FORCEINLINE void CM0_CpuIntr_Handler(uint8_t intrNum);

/*******************************************************************************
* SystemCoreClockUpdate()
*******************************************************************************/

/** Default HFClk frequency in Hz */
#define CY_CLK_HFCLK0_FREQ_HZ_DEFAULT       (8000000UL)

/** Default PeriClk frequency in Hz */
#define CY_CLK_PERICLK_FREQ_HZ_DEFAULT      (8000000UL)

/** Default system core frequency in Hz */
#define CY_CLK_SYSTEM_FREQ_HZ_DEFAULT       (100000000UL)

/** Holds the CLK_SLOW(Cortex-M0+) or CLK_FAST0(Cortex-M7_0) or CLK_FAST(Cortex-M7_1) system core clock */
CY_NOINIT uint32_t SystemCoreClock ;

/** Holds the HFClk0 clock frequency. Updated by \ref SystemCoreClockUpdate(). */
CY_NOINIT uint32_t cy_Hfclk0FreqHz ;

/** Holds the PeriClk clock frequency. Updated by \ref SystemCoreClockUpdate(). */
CY_NOINIT uint32_t cy_PeriClkFreqHz ;

/** Holds the AHB frequency. Updated by \ref SystemCoreClockUpdate(). */
CY_NOINIT uint32_t cy_AhbFreqHz ;

/*******************************************************************************
* SystemCoreClockUpdate (void)
*******************************************************************************/

/* Do not use these definitions directly in your application */
#define CY_DELAY_MS_OVERFLOW_THRESHOLD  (0x8000u)
#define CY_DELAY_1K_THRESHOLD           (1000u)
#define CY_DELAY_1K_MINUS_1_THRESHOLD   (CY_DELAY_1K_THRESHOLD - 1u)
#define CY_DELAY_1M_THRESHOLD           (1000000u)
#define CY_DELAY_1M_MINUS_1_THRESHOLD   (CY_DELAY_1M_THRESHOLD - 1u)

CY_NOINIT uint32_t cy_delayFreqKhz ;
CY_NOINIT uint8_t  cy_delayFreqMhz ;


/*****************************************************************************
* Global variable definitions (declared in header file with 'extern')
*****************************************************************************/
// CAUTION: Static or global initialized and non-const variables will not have their init value yet!


#define SRAM_BEGIN_ADDR                     (BASE_SRAM_CM0P)
#define SRAM_END_ADDR                       (CY_SRAM_BASE + CY_SRAM_SIZE)
#define STARTUP_STACK_OFFSEST               (0x100) /* 32 2-words are cleaned by startup */

#define ECC_INIT_WIDTH_BYTES                8
#define SROM_VECTOR_TABLE_BASE_ADDRESS      0x00000000
#define VECTOR_TABLE_OFFSET_IRQ0            0x40
#define VECTOR_TABLE_OFFSET_IRQ1            0x44

#if defined(__ARMCC_VERSION)
extern unsigned int Image$$ARM_LIB_STACK$$ZI$$Limit;            /* for (default) One Region model */
extern void __main(void);
#elif defined (__GNUC__)
extern unsigned int __StackTop;
#elif defined (__ICCARM__)
extern unsigned int CSTACK$$Limit;                      /* for (default) One Region model */
#endif

/******************************************************************************/

/*******************************************************************************
* Function Name: Cy_DefaultUserHandler
****************************************************************************//**
*
* The Handler is called when the CPU attempts to call IRQ that has not been mapped to user functions.
*
*******************************************************************************/
void Cy_DefaultUserHandler(void)
{
    // This IRQ occurred because CPU attempted to call IRQ that has not been mapped to user function
    while(1);
}

/*******************************************************************************
* Function Name: NvicMux0_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt0 occurs.
*
*******************************************************************************/
void NvicMux0_IRQHandler(void)
{
    CM0_CpuIntr_Handler(0);
}

/*******************************************************************************
* Function Name: NvicMux1_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt0 occurs.
*
*******************************************************************************/
void NvicMux1_IRQHandler(void)
{
    CM0_CpuIntr_Handler(1);
}

/*******************************************************************************
* Function Name: NvicMux2_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt2 occurs.
*
*******************************************************************************/
void NvicMux2_IRQHandler(void)
{
    CM0_CpuIntr_Handler(2);
}

/*******************************************************************************
* Function Name: NvicMux3_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt3 occurs.
*
*******************************************************************************/
void NvicMux3_IRQHandler(void)
{
    CM0_CpuIntr_Handler(3);
}

/*******************************************************************************
* Function Name: NvicMux4_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt4 occurs.
*
*******************************************************************************/
void NvicMux4_IRQHandler(void)
{
    CM0_CpuIntr_Handler(4);
}

/*******************************************************************************
* Function Name: NvicMux5_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt5 occurs.
*
*******************************************************************************/
void NvicMux5_IRQHandler(void)
{
    CM0_CpuIntr_Handler(5);
}

/*******************************************************************************
* Function Name: NvicMux6_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt6 occurs.
*
*******************************************************************************/
void NvicMux6_IRQHandler(void)
{
    CM0_CpuIntr_Handler(6);
}

/*******************************************************************************
* Function Name: NvicMux7_IRQHandler
****************************************************************************//**
*
* The Handler is called when the CPU interrupt7 occurs.
*
*******************************************************************************/
void NvicMux7_IRQHandler(void)
{
    CM0_CpuIntr_Handler(7);
}

/*******************************************************************************
* Function Name: CM0_CpuIntr_Handler
****************************************************************************//**
*
* The Inline handler for CPU interrupt.
* The system interrupt mapped to CPU interrupt will be fetched and executed
*
*******************************************************************************/
__STATIC_FORCEINLINE void CM0_CpuIntr_Handler(uint8_t intrNum)
{
    uint32_t system_int_idx;
    cy_israddress handler;

    if((_FLD2VAL(CPUSS_V2_CM0_INT0_STATUS_SYSTEM_INT_VALID, CPUSS_CM0_INT_STATUS[intrNum])))
    {
        system_int_idx = _FLD2VAL(CPUSS_V2_CM0_INT0_STATUS_SYSTEM_INT_IDX, CPUSS_CM0_INT_STATUS[intrNum]);
        handler = Cy_SystemIrqUserTable[system_int_idx];
        if(handler != NULL)
        {
            handler(); // jump to system interrupt handler
        }
    }
    else
    {
        // Triggered by software or because software cleared a peripheral interrupt flag but did not clear the pending flag at NVIC
    }
    NVIC_ClearPendingIRQ((IRQn_Type)intrNum);
}

/*******************************************************************************
* Function Name: SystemIrqInit
****************************************************************************//**
*
* The function is called during device startup.
*
*******************************************************************************/
static void SystemIrqInit(void)
{
    for (int i=0; i<(int)CPUSS_SYSTEM_INT_NR; i++)
    {
        Cy_SystemIrqUserTable[i] = DEFAULT_HANDLER_NAME;
    }

    Cy_SysInt_SystemIrqUserTableRamPointer = Cy_SystemIrqUserTable;
}

/** Define an abstract type for the chosen ECC initialization granularity */
typedef uint64_t ecc_init_width_t;

/* Provide empty __WEAK implementation for the low-level initialization
   routine required by the RTOS-enabled applications.
   clib-support library provides FreeRTOS-specific implementation:
   https://github.com/Infineon/clib-support */
void cy_toolchain_init(void);
__WEAK void cy_toolchain_init(void)
{
}

#if defined(__GNUC__) && !defined(__ARMCC_VERSION)
/* GCC: newlib crt0 _start executes software_init_hook.
   The cy_toolchain_init hook provided by clib-support library must execute
   after static data initialization and before static constructors. */
void software_init_hook();
void software_init_hook()
{
    cy_toolchain_init();
}
#elif defined(__ICCARM__)
/* Initialize data section */
void __iar_data_init3(void);

/* Call the constructors of all global objects */
void __iar_dynamic_initialization(void);

#else
/**/
#endif /* defined(__GNUC__) && !defined(__ARMCC_VERSION) */


void CyMain(void)
{
#if defined(__ICCARM__)
    /* Initialize data section */
    __iar_data_init3();

    /* Initialization hook for RTOS environment  */
    cy_toolchain_init();

    /* Call the constructors of all global objects */
    __iar_dynamic_initialization();
#endif

    __PROGRAM_START();
}


/******************************************************************************/

void SystemInit(void)
{
    /* Startup Init */
    EnableEcc();
    PrepareSystemCallInfrastructure();
    /* Startup Init Done */

    Cy_PDL_Init(CY_DEVICE_CFG);
    Cy_WDT_Unlock();
    Cy_WDT_Disable();

    // Call custom user system init function (assuming weak ref was overridden by user)
    Cy_SystemInit();
    SystemCoreClockUpdate();

    SystemIrqInit();
}


/*******************************************************************************
* Function Name: EnableEcc
****************************************************************************//**
*
* The function is called during device startup.
*
*******************************************************************************/
static void EnableEcc(void)
{
    /* Enable ECC checking in SRAM controllers again (had been switched off by assembly startup code) */
    CPUSS->RAM0_CTL0 &= ~(0x80000); /* set bit 19 to 0 */
#if (CPUSS_RAMC1_PRESENT == 1u)
    CPUSS->RAM1_CTL0 &= ~(0x80000); /* set bit 19 to 0 */
#endif
#if (CPUSS_RAMC2_PRESENT == 1u)
    CPUSS->RAM2_CTL0 &= ~(0x80000); /* set bit 19 to 0 */
#endif
}


/**
 *****************************************************************************
 ** Prepares necessary settings to get SROM system calls working
 **
 ** \return none
 *****************************************************************************/
static void PrepareSystemCallInfrastructure(void)
{
    const uint8_t u8Irq0Index = (uint8_t) (VECTOR_TABLE_OFFSET_IRQ0 / 4);
    const uint8_t u8Irq1Index = (uint8_t) (VECTOR_TABLE_OFFSET_IRQ1 / 4);
    volatile uint32_t * const ramTable   = (uint32_t *) __ramVectors;
    /* The array syntax is necessary to avoid out-of-bounds warnings in some compilers. */
    volatile uint32_t (* const sromTable)[VECTORTABLE_SIZE]  = (uint32_t (*)[VECTORTABLE_SIZE])SROM_VECTOR_TABLE_BASE_ADDRESS;

    // Use IRQ0 and IRQ1 handlers from SROM vector table
    ramTable[u8Irq0Index] = (*sromTable)[u8Irq0Index];
    ramTable[u8Irq1Index] = (*sromTable)[u8Irq1Index];

    NVIC_SetPriority(NvicMux0_IRQn, 1);
    NVIC_SetPriority(NvicMux1_IRQn, 0);
    NVIC_EnableIRQ(NvicMux0_IRQn);
    NVIC_EnableIRQ(NvicMux1_IRQn);

    // Only item left is clearing of PRIMASK:
    // This should be done by the application at a later point in time (e.g. in main())
}

/*******************************************************************************
* Function Name: Cy_SystemInit
****************************************************************************//**
*
* The function is called during device startup.
*
*******************************************************************************/
__WEAK void Cy_SystemInit(void)
{
     /* Empty weak function. The actual implementation to be in the app
      * generated strong function.
     */
}

/*******************************************************************************
* Function Name: SystemCoreClockUpdate
****************************************************************************//**
*
* Gets core clock frequency and updates \ref SystemCoreClock.
*
* Updates global variables used by the \ref Cy_SysLib_Delay(), \ref
* Cy_SysLib_DelayUs(), and \ref Cy_SysLib_DelayCycles().
*
*******************************************************************************/
void SystemCoreClockUpdate (void)
{
    /* Get frequency for the high-frequency clock*/
    cy_Hfclk0FreqHz = Cy_SysClk_ClkHfGetFrequency(CY_SYSCLK_CLK_CORE_HF_PATH_NUM);

    /* The CM0P core's clock source is the slow clock. */
    SystemCoreClock = Cy_SysClk_ClkSlowGetFrequency();

    /* Get Peripheral clock Frequency*/
    cy_PeriClkFreqHz = Cy_SysClk_ClkHfGetFrequency(CY_SYSCLK_CLK_PERI_HF_PATH_NUM);

    /* Sets clock frequency for Delay API */
    cy_delayFreqMhz = (uint32_t)((SystemCoreClock + CY_DELAY_1M_MINUS_1_THRESHOLD) / CY_DELAY_1M_THRESHOLD);
    cy_delayFreqKhz = (SystemCoreClock + CY_DELAY_1K_MINUS_1_THRESHOLD) / CY_DELAY_1K_THRESHOLD;

    /* Get the frequency of AHB source, CLK HF0 is the source for AHB*/
    cy_AhbFreqHz = Cy_SysClk_ClkHfGetFrequency(0UL);
}


/*******************************************************************************
* Function Name: Cy_SysGetCM4Status
****************************************************************************//**
*
* Returns the Cortex-M4 core power mode.
*
* \return \ref group_system_config_cm4_status_macro
*
*******************************************************************************/
uint32_t Cy_SysGetCM4Status(void)
{
    uint32_t regValue;

    /* Get current power mode */
    regValue = CPUSS->CM4_PWR_CTL & CPUSS_CM4_PWR_CTL_PWR_MODE_Msk;

    return (regValue);
}


/*******************************************************************************
* Function Name: Cy_SysEnableCM4
****************************************************************************//**
*
* Sets vector table base address and enables the Cortex-M4 core.
*
* \note If the CPU is already enabled, it is reset and then enabled.
*
* \param vectorTableOffset The offset of the vector table base address from
* memory address 0x00000000. The offset should be multiple to 1024 bytes.
*
*******************************************************************************/
void Cy_SysEnableCM4(uint32_t vectorTableOffset)
{
    uint32_t regValue;
    uint32_t interruptState;
    uint32_t cpuState;

    CY_ASSERT_L2((vectorTableOffset & CY_SYS_CM4_VECTOR_TABLE_VALID_ADDR) == 0UL);

    interruptState = Cy_SysLib_EnterCriticalSection();

    cpuState = Cy_SysGetCM4Status();
    if (CY_SYS_CM4_STATUS_ENABLED == cpuState)
    {
        Cy_SysResetCM4();
    }

    CPUSS->CM4_VECTOR_TABLE_BASE = vectorTableOffset;

    regValue = CPUSS->CM4_PWR_CTL & ~(CPUSS_CM4_PWR_CTL_VECTKEYSTAT_Msk | CPUSS_CM4_PWR_CTL_PWR_MODE_Msk);
    regValue |= _VAL2FLD(CPUSS_CM4_PWR_CTL_VECTKEYSTAT, CY_SYS_CM4_PWR_CTL_KEY_OPEN);
    regValue |= CY_SYS_CM4_STATUS_ENABLED;
    CPUSS->CM4_PWR_CTL = regValue;

    while((CPUSS->CM4_STATUS & CPUSS_CM4_STATUS_PWR_DONE_Msk) == 0UL)
    {
        /* Wait for the power mode to take effect */
    }

    Cy_SysLib_ExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Cy_SysDisableCM4
****************************************************************************//**
*
* Disables the Cortex-M4 core and waits for the mode to take the effect.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the
* CPU.
*
*******************************************************************************/
void Cy_SysDisableCM4(void)
{
    uint32_t interruptState;
    uint32_t regValue;

    interruptState = Cy_SysLib_EnterCriticalSection();

    regValue = CPUSS->CM4_PWR_CTL & ~(CPUSS_CM4_PWR_CTL_VECTKEYSTAT_Msk | CPUSS_CM4_PWR_CTL_PWR_MODE_Msk);
    regValue |= _VAL2FLD(CPUSS_CM4_PWR_CTL_VECTKEYSTAT, CY_SYS_CM4_PWR_CTL_KEY_OPEN);
    regValue |= CY_SYS_CM4_STATUS_DISABLED;
    CPUSS->CM4_PWR_CTL = regValue;

    while((CPUSS->CM4_STATUS & CPUSS_CM4_STATUS_PWR_DONE_Msk) == 0UL)
    {
        /* Wait for the power mode to take effect */
    }

    Cy_SysLib_ExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Cy_SysRetainCM4
****************************************************************************//**
*
* Retains the Cortex-M4 core and exists without waiting for the mode to take
* effect.
*
* \note The retained mode can be entered only from the enabled mode.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void Cy_SysRetainCM4(void)
{
    uint32_t interruptState;
    uint32_t regValue;

    interruptState = Cy_SysLib_EnterCriticalSection();

    regValue = CPUSS->CM4_PWR_CTL & ~(CPUSS_CM4_PWR_CTL_VECTKEYSTAT_Msk | CPUSS_CM4_PWR_CTL_PWR_MODE_Msk);
    regValue |= _VAL2FLD(CPUSS_CM4_PWR_CTL_VECTKEYSTAT, CY_SYS_CM4_PWR_CTL_KEY_OPEN);
    regValue |= CY_SYS_CM4_STATUS_RETAINED;
    CPUSS->CM4_PWR_CTL = regValue;

    Cy_SysLib_ExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Cy_SysResetCM4
****************************************************************************//**
*
* Resets the Cortex-M4 core and waits for the mode to take the effect.
*
* \note The reset mode can not be entered from the retained mode.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void Cy_SysResetCM4(void)
{
    uint32_t interruptState;
    uint32_t regValue;

    interruptState = Cy_SysLib_EnterCriticalSection();

    regValue = CPUSS->CM4_PWR_CTL & ~(CPUSS_CM4_PWR_CTL_VECTKEYSTAT_Msk | CPUSS_CM4_PWR_CTL_PWR_MODE_Msk);
    regValue |= _VAL2FLD(CPUSS_CM4_PWR_CTL_VECTKEYSTAT, CY_SYS_CM4_PWR_CTL_KEY_OPEN);
    regValue |= CY_SYS_CM4_STATUS_RESET;
    CPUSS->CM4_PWR_CTL = regValue;

    while((CPUSS->CM4_STATUS & CPUSS_CM4_STATUS_PWR_DONE_Msk) == 0UL)
    {
        /* Wait for the power mode to take effect */
    }

    Cy_SysLib_ExitCriticalSection(interruptState);
}

#endif /* defined(CY_DEVICE_XMC5000) */

/* [] END OF FILE */
