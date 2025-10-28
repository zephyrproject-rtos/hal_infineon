/***************************************************************************//**
* \file cy_syslib.c
* \version 3.30.1
*
*  Description:
*   Provides system API implementation for the SysLib driver.
*
********************************************************************************
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

#include "cy_syslib.h"
#if !defined(NDEBUG)
    #include <string.h>
#endif /* NDEBUG */

/* Flash wait states */
#if defined(CPUSS_FLASHC_PRESENT_WITH_ECC)
#define CY_SYSLIB_FLASH_WS_0_FREQ_MAX       ( 12UL)
#define CY_SYSLIB_FLASH_WS_1_FREQ_MAX       ( 24UL)
#define CY_SYSLIB_FLASH_WS_2_FREQ_MAX       ( 36UL)
#else
#define CY_SYSLIB_FLASH_WS_0_FREQ_MAX       ( 16UL)
#define CY_SYSLIB_FLASH_WS_1_FREQ_MAX       ( 32UL)
#endif /* CPUSS_FLASHC_PRESENT_WITH_ECC */

/* Flash invalidation bit position in CPUSS_FLASH_CTL register*/
#define CPUSS_FLASH_INVALIDATE_BIT (1UL << 8)


#if (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED)
    CY_NOINIT cy_stc_fault_frame_t cy_faultFrame;
#endif /* (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED) */

#if defined(__ARMCC_VERSION)
        #if (__ARMCC_VERSION >= 6010050)
            static void Cy_SysLib_AsmInfiniteLoop(void) { __ASM (" b . "); };
        #else
            static __ASM void Cy_SysLib_AsmInfiniteLoop(void) { b . };
        #endif /* (__ARMCC_VERSION >= 6010050) */
#endif  /* (__ARMCC_VERSION) */


/*******************************************************************************
* Function Name: Cy_SysLib_Delay
****************************************************************************//**
*
* The function delays by the specified number of milliseconds.
* By default, the number of cycles to delay is calculated based on the
* \ref SystemCoreClock.
*
* \param milliseconds  The number of milliseconds to delay.
*
* \note The function calls \ref Cy_SysLib_DelayCycles() API to generate a delay.
*       If the function parameter (milliseconds) is bigger than
*       CY_DELAY_MS_OVERFLOW constant, then an additional loop runs to prevent
*       an overflow in parameter passed to \ref Cy_SysLib_DelayCycles() API.
*
*******************************************************************************/
void Cy_SysLib_Delay(uint32_t milliseconds)
{
    uint32_t ms = milliseconds;

    while(ms > CY_DELAY_MS_OVERFLOW)
    {
        /* This loop prevents an overflow in value passed to Cy_SysLib_DelayCycles() API.
         * At 100 MHz, (ms * cy_delayFreqKhz) product overflows
         * in case if ms parameter is more than 42 seconds.
         */
        Cy_SysLib_DelayCycles(cy_delay32kMs);
        ms -= CY_DELAY_MS_OVERFLOW;
    }

    Cy_SysLib_DelayCycles(ms * cy_delayFreqKhz);
}


/*******************************************************************************
* Function Name: Cy_SysLib_DelayUs
****************************************************************************//**
*
* The function delays by the specified number of microseconds.
* By default, the number of cycles to delay is calculated based on the
* \ref SystemCoreClock.
*
* \param microseconds  The number of microseconds to delay.
*
* \note If the CPU frequency is a small non-integer number, the actual delay
*       can be up to twice as long as the nominal value. The actual delay
*       cannot be shorter than the nominal one.
*
*******************************************************************************/
void Cy_SysLib_DelayUs(uint16_t microseconds)
{
    Cy_SysLib_DelayCycles((uint32_t) microseconds * cy_delayFreqMhz);
}


/*******************************************************************************
* Function Name: Cy_SysLib_ClearFlashCacheAndBuffer
****************************************************************************//**
*
* This function invalidates the flash cache and buffer. It ensures the valid
* data is read from flash instead of using outdated data from the cache.
* The caches' Least Recently Used (LRU)  structure is also reset to their
* default state.
*
*******************************************************************************/
void Cy_SysLib_ClearFlashCacheAndBuffer(void)
{
    /* Flash invalidation bit in FLASH_CTL register is RW1C
     * (bit is cleared upon writing 1), so write 1 to invalidate the content of
     * flash controller's buffer.
     */
    CPUSS_FLASH_CTL |= CPUSS_FLASH_INVALIDATE_BIT;
}


/*******************************************************************************
* Function Name: Cy_SysLib_GetResetReason
****************************************************************************//**
*
* The function returns the cause for the latest reset(s) that occurred in
* the system. The reset causes are taken by reading RES_CAUSE register.
*
* \return The cause of a system reset.
*
* | Name                          | Value
* |-------------------------------|---------------------
* | CY_SYSLIB_RESET_HWWDT         | 0x00000001UL (bit0)
* | CY_SYSLIB_PROT_FAULT          | 0x00000008UL (bit3)
* | CY_SYSLIB_RESET_SOFT          | 0x00000010UL (bit4)
* \note The below system resets are only applicable for PSOC 4 HVMS/PA devices.
* | Name                          | Value
* |-------------------------------|---------------------
* | CY_SYSLIB_RESET_ACT_FAULT     | 0x00000002UL (bit1)
* | CY_SYSLIB_RESET_CRWDT         | 0x00000200UL (bit9)
* | CY_SYSLIB_RESET_XRES          | 0x00010000UL (bit16)
* | CY_SYSLIB_RESET_BODVDDD       | 0x00020000UL (bit17)
* | CY_SYSLIB_RESET_BODVCCD       | 0x00080000UL (bit19)
* | CY_SYSLIB_RESET_OVDVDDD       | 0x00100000UL (bit20)
* | CY_SYSLIB_RESET_OVDVCCD       | 0x00400000UL (bit22)
* | CY_SYSLIB_RESET_BODHVSS       | 0x01000000UL (bit24)
* | CY_SYSLIB_RESET_PORVDDD       | 0x40000000UL (bit30)
*
*******************************************************************************/
uint32_t Cy_SysLib_GetResetReason(void)
{
    return (SRSS_RES_CAUSE & CY_SYSLIB_RESET_REASON_MASK);
}


/*******************************************************************************
* Function Name: Cy_SysLib_ClearResetReason
****************************************************************************//**
*
* This function clears the values of the RES_CAUSE register.
*
*******************************************************************************/
void Cy_SysLib_ClearResetReason(void)
{
    /* RES_CAUSE register bits are RW1C (every bit is cleared upon writing 1),
     * so write all ones to clear all the reset reasons.
     */
    SRSS_RES_CAUSE = CY_SYSLIB_RESET_REASON_MASK;
}


#if (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED) || defined(CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysLib_FaultHandler
****************************************************************************//**
*
* This function stores the ARM Cortex registers into a non-zero init area for
* debugging. This function calls Cy_SysLib_ProcessingFault() after storing all
* information.
*
* \param faultStackAddr The address of the stack pointer, indicates the lowest
*                       address in the fault stack frame to be stored.
* \note This function stores the fault stack frame only for the first occurred
*       fault.
* \note The PDL doesn't provide an API to analyze the stored register
*       values. The user has to add additional functions for the analysis,
*       if necessary.
* \note The CY_ARM_FAULT_DEBUG macro defines if the Fault Handler is enabled.
*       By default it is set to CY_ARM_FAULT_DEBUG_ENABLED and enables the
*       Fault Handler.
*       If there is a necessity to save memory or have some specific custom
*       handler, etc. then CY_ARM_FAULT_DEBUG should be redefined as
*       CY_ARM_FAULT_DEBUG_DISABLED. To do this, the following definition should
*       be added to the compiler Command Line (through the project Build
*       Settings): "-D CY_ARM_FAULT_DEBUG=0".
*
*******************************************************************************/
void Cy_SysLib_FaultHandler(uint32_t const *faultStackAddr)
{
    /* Stores general registers */
    cy_faultFrame.r0  = faultStackAddr[CY_R0_Pos];
    cy_faultFrame.r1  = faultStackAddr[CY_R1_Pos];
    cy_faultFrame.r2  = faultStackAddr[CY_R2_Pos];
    cy_faultFrame.r3  = faultStackAddr[CY_R3_Pos];
    cy_faultFrame.r12 = faultStackAddr[CY_R12_Pos];
    cy_faultFrame.lr  = faultStackAddr[CY_LR_Pos];
    cy_faultFrame.pc  = faultStackAddr[CY_PC_Pos];
    cy_faultFrame.psr = faultStackAddr[CY_PSR_Pos];

    Cy_SysLib_ProcessingFault();
}


/*******************************************************************************
* Function Name: Cy_SysLib_ProcessingFault
****************************************************************************//**
*
* This function determines how to process the current fault state. By default
* in case of exception the system will stay in the infinite loop of this
* function.
*
* \note This function has the WEAK option, so the user can redefine the function
*       behavior for a custom processing.
*       For example, the function redefinition could be constructed from fault
*       stack processing and NVIC_SystemReset() function call.
*
*******************************************************************************/
__WEAK void Cy_SysLib_ProcessingFault(void)
{
    #if defined(__ARMCC_VERSION)
        /* Assembly implementation of an infinite loop
         * is used for the armcc compiler to preserve the call stack.
         * Otherwise, the compiler destroys the call stack,
         * because treats this API as a no return function.
         */
        Cy_SysLib_AsmInfiniteLoop();
    #else
        while(true) {}
    #endif  /* (__ARMCC_VERSION) */
}
#endif /* (CY_ARM_FAULT_DEBUG == CY_ARM_FAULT_DEBUG_ENABLED) || defined(CY_DOXYGEN) */


/*******************************************************************************
* Function Name: Cy_SysLib_SetWaitStates
****************************************************************************//**
*
* Sets the number of clock cycles the cache will wait before it samples data
* coming back from Flash. This function must be called before increasing the
* SYSCLK clock frequency. It can optionally be called after lowering SYSCLK
* clock frequency in order to improve the CPU performance.
*
* \param clkHfMHz  The SYSCLK clock frequency in MHz. Specifying a frequency
*                  above the supported maximum will set the wait states as for
*                  the maximum frequency.
*
*******************************************************************************/
void Cy_SysLib_SetWaitStates(uint32_t clkHfMHz)
{
    uint32_t waitStates;
#if defined(CPUSS_FLASHC_PRESENT_WITH_ECC)
    waitStates =  (clkHfMHz <= CY_SYSLIB_FLASH_WS_0_FREQ_MAX) ? 0UL :
                  (clkHfMHz <= CY_SYSLIB_FLASH_WS_1_FREQ_MAX) ? 1UL :
                  ((clkHfMHz <= CY_SYSLIB_FLASH_WS_2_FREQ_MAX) ? 2UL : 3UL);
#else
    waitStates =  (clkHfMHz <= CY_SYSLIB_FLASH_WS_0_FREQ_MAX) ? 0UL :
                  ((clkHfMHz <= CY_SYSLIB_FLASH_WS_1_FREQ_MAX) ? 1UL : 2UL);
#endif /* defined(CPUSS_FLASHC_PRESENT_WITH_ECC) */

    CY_REG32_CLR_SET(CPUSS_FLASH_CTL, CPUSS_FLASH_CTL_FLASH_WS, waitStates);

    /* Enable flash prefetch buffer for the wait states greater than zero. */
    CY_REG32_CLR_SET(CPUSS_FLASH_CTL, CPUSS_FLASH_CTL_PREF_EN, (waitStates != 0UL) ? 1UL : 0UL);
}

uint64_t Cy_SysLib_GetUniqueId(void)
{
    return (*((uint64_t *)(SFLASH_BASE + CY_PDL_DIE_OFFSET_ADDR)));
}

/* Only a specific version of BootRom supports Boot Status.
This version of BootRom was created to work with Automotive SFLASH. */
#if defined(SFLASH_AUTO_SFLASH) || defined(CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysLib_GetBootStatus
****************************************************************************//**
*
* \brief
* Returns the boot status.
* The Boot process uses CPUSS_SYSARG register to signal success/failure of Boot.
*
* \return Boot status. If the return value is "0x0" boot was successful.
* If the return value is other than "0x0", the boot process failed.
* For a description of the meaning of the return value OTHER than zero,
* refer to the device TRM.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
*******************************************************************************/
uint32_t Cy_SysLib_GetBootStatus(void)
{
  return (CPUSS_SYSARG);
}


/*******************************************************************************
* Function Name: Cy_SysLib_GetBootResult
****************************************************************************//**
*
* \brief
* Returns the results from the Boot Process for the provided
* \ref cy_en_syslib_boot_result_t.
*
* \param bootResultSet
* Instance of Boot Result data register \ref cy_en_syslib_boot_result_t.
* This register contains details of any results from the Boot Process.
* Register Content only valid if there is an error indication
* from the boot process \ref Cy_SysLib_GetBootStatus.
*
* \return
* Boot Result data register. Default value is "0x0".
* For a description of the meaning of the return value OTHER than zero,
* refer to the device TRM.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
*******************************************************************************/
uint32_t Cy_SysLib_GetBootResult(cy_en_syslib_boot_result_t bootResultSet)
{
    CY_ASSERT_L2(CY_SYSLIB_IS_BOOT_DATA_SET_VALID(bootResultSet));

    uint32_t boot_result_data = 0x0;

    if (CY_SYSLIB_BOOT_RESULT_0 == bootResultSet)
    {
        boot_result_data = ((CPUSS_Type *) CPUSS)->BOOT_RESULT_0;
    }
    else
    {
        boot_result_data = ((CPUSS_Type *) CPUSS)->BOOT_RESULT_1;
    }

  return (boot_result_data);
}
#endif /* SFLASH_AUTO_SFLASH */
/* [] END OF FILE */
