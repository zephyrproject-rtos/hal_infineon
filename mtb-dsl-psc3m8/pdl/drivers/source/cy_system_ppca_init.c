/***************************************************************************//**
* \file cy_system_ppca_init.c
* \version 1.0
*
* The PPCA system-source file.
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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

#if defined (CY_IP_MXS40PPSS)
#if !defined (COMPONENT_PPCA_DEVICE)
#include "cy_device.h"
#include "cy_device_headers.h"
#include "cmsis_compiler.h"
#include "cy_syslib.h"
#include "cy_pdl.h"
#include "cy_system_ppca_init.h"
#include "cy_syspm_ppu.h"
#include <stdio.h>
#include <string.h>

/* xCount is hardcoded to 256 bytes. and yCount will vary based on the image size. */
#define XCOUNT_VALUE                        (256UL)
#define CY_PD1_PWR_UP_US                    (20U)
static cy_stc_dma_descriptor_config_t descriptor_config =
{
    .retrigger = CY_DMA_RETRIG_IM,
    .interruptType = CY_DMA_DESCR_CHAIN,
    .triggerOutType = CY_DMA_DESCR,
    .channelState = CY_DMA_CHANNEL_ENABLED,
    .triggerInType = CY_DMA_DESCR,
    .dataSize = CY_DMA_WORD,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType = CY_DMA_2D_TRANSFER,
    .srcAddress = NULL,
    .dstAddress = NULL,
    .srcXincrement = 1,
    .dstXincrement = 1,
    .xCount = XCOUNT_VALUE,
    .srcYincrement = (int32_t)XCOUNT_VALUE,
    .dstYincrement = (int32_t)XCOUNT_VALUE,
    .yCount = 32,
    .nextDescriptor = NULL,
};
static cy_stc_dma_descriptor_t descriptor_0 =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL,
};
static cy_stc_dma_channel_config_t channelConfig =
{
    .descriptor = &descriptor_0,
    .preemptable = true,
    .priority = 3,
    .enable = false,
    .bufferable = true,
};

static void Cy_SysEnableCM33_0(uint32_t vectorTableOffset, uint32_t waitus);
static void Cy_SysResetCM33_0(uint32_t waitus);
#if !defined (PPCA_CORE1_WOUNDING_ENABLED)
static void Cy_SysEnableCM33_1(uint32_t vectorTableOffset, uint32_t waitus);
static void Cy_SysResetCM33_1(uint32_t waitus);
#endif /* !defined (PPCA_CORE1_WOUNDING_ENABLED) */

/*******************************************************************************
* Function Name: Cy_SysEnableCM33_0
****************************************************************************//**
*
* Sets vector table base address and enables the Cortex-M33 core.
*
* \note If the CPU is already enabled, it is reset and then enabled.
*
* \param vectorTableOffset The offset of the vector table base address from
* memory address 0x00000000. The offset should be multiple to 512 bytes.
* \param waitus The timeout value in microsecond used to wait for core to be
* booted. value zero is for infinite wait till the core is booted successfully.
*
*******************************************************************************/
static void Cy_SysEnableCM33_0(uint32_t vectorTableOffset, uint32_t waitus)
{
    uint32_t interruptState;
    uint32_t cpuState;

    interruptState = Cy_SysLib_EnterCriticalSection();

    cpuState = Cy_SysGetCM33_0_Status();
    if (CY_SYS_CORE_STATUS_ACTIVE == cpuState)
    {
        Cy_SysResetCM33_0(CY_SYS_CORE_WAIT_10US);
    }
    else
    {
        Cy_PPCA_CNFG_CPU0_Reset(PPCA_CNFG_CNFG, CY_CPU_RESET);
    }

    PPCA_CPUSS_CNFG_MXCM330->CM33_S_VECTOR_TABLE_BASE = vectorTableOffset;

    Cy_PPCA_CNFG_CPU0_Reset(PPCA_CNFG_CNFG, CY_CPU_RESET_RELEASE);
    if (waitus == CY_SYS_CORE_WAIT_INFINITE)
    {
        while (Cy_SysGetCM33_0_Status() != CY_SYS_CORE_STATUS_ACTIVE)
        {
            /* Wait for the power mode to take effect */
        }
    }
    else
    {
        if (Cy_SysGetCM33_0_Status() != CY_SYS_CORE_STATUS_ACTIVE)
        {
            Cy_SysLib_DelayUs((uint16_t)waitus);
        }
    }

    PPCA_CPUSS_CNFG_MXCM330->CM33_CTL &= ~(_VAL2FLD(PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_CPU_WAIT, CY_SYS_CPU_WAIT_DEFAULT));

    /* Enable Event from other CM33 */
    PPCA_CPUSS_CNFG_MXCM330->CM33_EVENT_CTL = CM33_CPU_EVENT;

    Cy_SysLib_ExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Cy_SysResetCM33_0
****************************************************************************//**
*
* Resets the Cortex-M33 core and waits for the mode to take the effect.
*
* \param waitus The timeout value in microsecond used to wait for core to be
* reset. value zero is for infinite wait till the core is reset successfully.
*
* \warning Do not call the function while the Cortex-M33 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M55 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
static void Cy_SysResetCM33_0(uint32_t waitus)
{
    uint32_t interruptState;

    interruptState = Cy_SysLib_EnterCriticalSection();

    Cy_PPCA_CNFG_CPU0_Reset(PPCA_CNFG_CNFG, CY_CPU_RESET);

    if (waitus == CY_SYS_CORE_WAIT_INFINITE)
    {
        /* After SW clears this field to '0', HW automatically sets this field to '1'.
         * This effectively results in a CM33 reset, followed by a CM33 warm boot. */
        while ( _FLD2VAL(PPCA_CPUSS_CNFG_MXCM33_CM33_CMD_ENABLED, PPCA_CPUSS_CNFG_MXCM330->CM33_CMD) != CY_SYS_CM33_NOT_IN_RESET)
        {
            /* Wait for the power mode to take effect */
        }
    }
    else
    {
        if ( _FLD2VAL(MXCM33_CM33_CMD_ENABLED, PPCA_CPUSS_CNFG_MXCM330->CM33_CMD) != CY_SYS_CM33_NOT_IN_RESET)
        {
            Cy_SysLib_DelayUs((uint16_t)waitus);
        }
    }

    Cy_SysLib_ExitCriticalSection(interruptState);
}

#if !defined (PPCA_CORE1_WOUNDING_ENABLED)
/*******************************************************************************
* Function Name: Cy_SysEnableCM33_1
****************************************************************************//**
*
* Sets vector table base address and enables the Cortex-M33 core.
*
* \note If the CPU is already enabled, it is reset and then enabled.
*
* \param vectorTableOffset The offset of the vector table base address from
* memory address 0x00000000. The offset should be multiple to 512 bytes.
* \param waitus The timeout value in microsecond used to wait for core to be
* booted. value zero is for infinite wait till the core is booted successfully.
*
*******************************************************************************/
static void Cy_SysEnableCM33_1(uint32_t vectorTableOffset, uint32_t waitus)
{
    uint32_t interruptState;
    uint32_t cpuState;

    interruptState = Cy_SysLib_EnterCriticalSection();

    cpuState = Cy_SysGetCM33_1_Status();
    if (CY_SYS_CORE_STATUS_ACTIVE == cpuState)
    {
        Cy_SysResetCM33_1(CY_SYS_CORE_WAIT_10US);
    }
    else
    {
        Cy_PPCA_CNFG_CPU1_Reset(PPCA_CNFG_CNFG, CY_CPU_RESET);
    }

    PPCA_CPUSS_CNFG_MXCM331->CM33_S_VECTOR_TABLE_BASE = vectorTableOffset;

    Cy_PPCA_CNFG_CPU1_Reset(PPCA_CNFG_CNFG, CY_CPU_RESET_RELEASE);

    if (waitus == CY_SYS_CORE_WAIT_INFINITE)
    {
        while (Cy_SysGetCM33_1_Status() != CY_SYS_CORE_STATUS_ACTIVE)
        {
            /* Wait for the power mode to take effect */
        }
    }
    else
    {
        if (Cy_SysGetCM33_1_Status() != CY_SYS_CORE_STATUS_ACTIVE)
        {
            Cy_SysLib_DelayUs((uint16_t)waitus);
        }
    }

    PPCA_CPUSS_CNFG_MXCM331->CM33_CTL &= ~(_VAL2FLD(PPCA_CPUSS_CNFG_MXCM33_CM33_CTL_CPU_WAIT, CY_SYS_CPU_WAIT_DEFAULT));

    /* Enable Event from other CM33 */
    PPCA_CPUSS_CNFG_MXCM331->CM33_EVENT_CTL = CM33_CPU_EVENT;

    Cy_SysLib_ExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Cy_SysResetCM33_1
****************************************************************************//**
*
* Resets the Cortex-M33 core and waits for the mode to take the effect.
*
* \param waitus The timeout value in microsecond used to wait for core to be
* reset. value zero is for infinite wait till the core is reset successfully.
*
* \warning Do not call the function while the Cortex-M33 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M55 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
static void Cy_SysResetCM33_1(uint32_t waitus)
{
    uint32_t interruptState;

    interruptState = Cy_SysLib_EnterCriticalSection();
    Cy_PPCA_CNFG_CPU1_Reset(PPCA_CNFG_CNFG, CY_CPU_RESET);

    if (waitus == CY_SYS_CORE_WAIT_INFINITE)
    {
        /* After SW clears this field to '0', HW automatically sets this field to '1'.
         * This effectively results in a CM33 reset, followed by a CM33 warm boot. */
        while ( _FLD2VAL(PPCA_CPUSS_CNFG_MXCM33_CM33_CMD_ENABLED, PPCA_CPUSS_CNFG_MXCM331->CM33_CMD) != CY_SYS_CM33_NOT_IN_RESET)
        {
            /* Wait for the power mode to take effect */
        }
    }
    else
    {
        if ( _FLD2VAL(MXCM33_CM33_CMD_ENABLED, PPCA_CPUSS_CNFG_MXCM331->CM33_CMD) != CY_SYS_CM33_NOT_IN_RESET)
        {
            Cy_SysLib_DelayUs((uint16_t)waitus);
        }
    }

    Cy_SysLib_ExitCriticalSection(interruptState);
}
#endif /* !defined (PPCA_CORE1_WOUNDING_ENABLED) */

/******************************************************************************
* Function Name: Cy_System_Init_CPU0
***************************************************************************//**
*
* Initializes and starts CPU0
*
* \param flash_address The pointer to the flash address where the CPU0 image is present.
*
* \param image_size Size of CPU0 image.
*
******************************************************************************/
void Cy_System_Init_CPU0(void *flash_address, uint32_t image_size)
{
    /* Keep PPCA core in reset state to safely copy application image to CODE SRAM.
     * Reset is released inside Cy_SysEnableCM33_0 after CM33_S_VECTOR_TABLE_BASE
     * has been set to the correct application address. */
    Cy_PPCA_CNFG_CPU0_Reset(PPCA_CNFG_CNFG, CY_CPU_RESET);
    Cy_System_PPCA_RAM_Enable();
    Cy_System_Copy_PPCA_Image_Memcpy(flash_address, image_size, CY_PPCA_CORE_0);
    Cy_SysEnableCM33_0(CY_SRAM_CPU0_BASE , CY_SYS_CORE_WAIT_INFINITE);
}

#if !defined (PPCA_CORE1_WOUNDING_ENABLED)
/******************************************************************************
* Function Name: Cy_System_Init_CPU1
***************************************************************************//**
*
* Initializes and starts CPU1
*
* \param flash_address The pointer to the flash address where the CPU1 image is present.
*
* \param image_size Size of CPU1 image.
*
******************************************************************************/
void Cy_System_Init_CPU1(void *flash_address, uint32_t image_size)
{
    /* Keep PPCA core in reset state to safely copy application image to CODE SRAM.
     * Reset is released inside Cy_SysEnableCM33_1 after CM33_S_VECTOR_TABLE_BASE
     * has been set to the correct application address. */
    Cy_PPCA_CNFG_CPU1_Reset(PPCA_CNFG_CNFG, CY_CPU_RESET);
    Cy_System_PPCA_RAM_Enable();
    Cy_System_Copy_PPCA_Image_Memcpy(flash_address, image_size, CY_PPCA_CORE_1);
    Cy_SysEnableCM33_1(CY_SRAM_CPU1_BASE , CY_SYS_CORE_WAIT_INFINITE);
}

/******************************************************************************
* Function Name: Cy_System_Init_CPU0_CPU1
***************************************************************************//**
*
* Initializes and starts both CPU0 and CPU1
*
* \param flash_cpu0_address The pointer to the flash address where the CPU0 image is present.
*
* \param cpu0_image_size Size of CPU0 image.
*
* \param flash_cpu1_address The pointer to the flash address where the CPU1 image is present.
*
* \param cpu1_image_size Size of CPU1 image.
*
******************************************************************************/
void Cy_System_Init_CPU0_CPU1(void *flash_cpu0_address, uint32_t cpu0_image_size, void *flash_cpu1_address, uint32_t cpu1_image_size)
{
    /* Keep PPCA cores in reset state to safely copy application image to CODE SRAM.
     * Reset is released inside Cy_SysEnableCM33_0/1 after CM33_S_VECTOR_TABLE_BASE
     * has been set to the correct application address. */
    Cy_PPCA_CNFG_CPU0_Reset(PPCA_CNFG_CNFG, CY_CPU_RESET);
    Cy_PPCA_CNFG_CPU1_Reset(PPCA_CNFG_CNFG, CY_CPU_RESET);

    Cy_System_PPCA_RAM_Enable();
    Cy_System_Copy_PPCA_Image_Memcpy(flash_cpu0_address, cpu0_image_size, CY_PPCA_CORE_0);
    Cy_System_Copy_PPCA_Image_Memcpy(flash_cpu1_address, cpu1_image_size, CY_PPCA_CORE_1);

    Cy_SysEnableCM33_0(CY_SRAM_CPU0_BASE , CY_SYS_CORE_WAIT_INFINITE);
    Cy_SysEnableCM33_1(CY_SRAM_CPU1_BASE , CY_SYS_CORE_WAIT_INFINITE);

}

#endif /* !defined (PPCA_CORE1_WOUNDING_ENABLED) */
/*******************************************************************************
* Function Name: Cy_SysEnable_PPCA_Core0
****************************************************************************//**
*
* Sets vector table base address and enables the PPCA Cortex-M33 core0.
*
* \note If the CPU is already enabled, it is reset and then enabled.
*
* \note User's has to copy PPCA core image to PPCA memory before calling this function.
*
*
*******************************************************************************/
void Cy_SysEnable_PPCA_Core0(void)
{
    Cy_SysEnableCM33_0(CY_SRAM_CPU0_BASE , CY_SYS_CORE_WAIT_INFINITE);
}

#if !defined (PPCA_CORE1_WOUNDING_ENABLED)
/*******************************************************************************
* Function Name: Cy_SysEnable_PPCA_Core1
****************************************************************************//**
*
* Sets vector table base address and enables the PPCA Cortex-M33 core1.
*
* \note If the CPU is already enabled, it is reset and then enabled.
*
* \note User's has to copy PPCA core image to PPCA memory before calling this function.
*
*
*******************************************************************************/
void Cy_SysEnable_PPCA_Core1(void)
{
    Cy_SysEnableCM33_1(CY_SRAM_CPU1_BASE , CY_SYS_CORE_WAIT_INFINITE);
}

#endif /* !defined (PPCA_CORE1_WOUNDING_ENABLED) */

/******************************************************************************
* Function Name: Cy_System_Copy_PPCA_Image_Memcpy
***************************************************************************//**
*
* Copies image from the given address to PPCA RAM for Core 0 or Core1.
*
* \note Uses 32-bit word writes. The PPCA SRAM peripheral bus requires
* word-aligned accesses; byte-level copies (e.g. memcpy) will not work.
*
* \param flash_address The pointer to the flash address where the image is present.
*
* \param image_size Size of the image in bytes (must be 4-byte aligned).
*
* \param core_number image is for Core 0 or Core 1.
*
******************************************************************************/
void Cy_System_Copy_PPCA_Image_Memcpy(void *flash_address, uint32_t image_size, cy_en_ppca_core_t core_number)
{
    CY_ASSERT_L3(image_size <= CY_SRAM_M0_SIZE);
    CY_ASSERT_L3(flash_address);

    uint32_t *dst;
    const uint32_t *src = (const uint32_t *)flash_address;
    uint32_t word_count = image_size / 4U;
    uint32_t remaining = image_size & 3U;
    uint32_t i;

    if(core_number == CY_PPCA_CORE_1)
    {
        dst = (uint32_t *)(CY_SRAM_M2_BASE);
    }
    else
    {
        dst = (uint32_t *)(CY_SRAM_M0_BASE);
    }

    for(i = 0U; i < word_count; i++)
    {
        dst[i] = src[i];
    }

    /* Handle remaining bytes (1-3) with a read-modify-write of the last word */
    if(remaining != 0U)
    {
        uint32_t last_word = 0U;
        const uint8_t *src_bytes = (const uint8_t *)&src[word_count];
        uint32_t j;
        for(j = 0U; j < remaining; j++)
        {
            last_word |= ((uint32_t)src_bytes[j]) << (j * 8U);
        }
        dst[word_count] = last_word;
    }
}

/******************************************************************************
* Function Name: Cy_System_Copy_PPCA_Image
***************************************************************************//**
*
* Copies image from the given address to PPCA RAM for Core 0 or Core1.
*
* \note Enables DMA and uses channel 0 for copying. Disables DMA after copying the image.
*
* \param flash_address The pointer to the flash address where the CPU0 image is present.
*
* \param image_size Size of the image.
*
* \param core image is for Core 0 or Core 1.
*
******************************************************************************/
void Cy_System_Copy_PPCA_Image(void *flash_address, uint32_t image_size, cy_en_ppca_core_t core_number)
{
    CY_ASSERT_L3(image_size <= CY_SRAM_M0_SIZE);
    CY_ASSERT_L3(flash_address);
    (void)image_size;
    uint32_t interruptState;

    interruptState = Cy_SysLib_EnterCriticalSection();
    /* DMA the flash image to CPU1 RAM memory */
    /* make sure that the CPU is up in the specified time */
    Cy_DMA_Enable(DW0);
    (void)Cy_DMA_Descriptor_Init(&descriptor_0, &descriptor_config);

    Cy_DMA_Descriptor_SetSrcAddress(&descriptor_0, flash_address);
    if(core_number == CY_PPCA_CORE_1)
    {
        Cy_DMA_Descriptor_SetDstAddress(&descriptor_0, (void*)(CY_SRAM_M2_BASE));
    }
    else
    {
        Cy_DMA_Descriptor_SetDstAddress(&descriptor_0, (void*)(CY_SRAM_M0_BASE));
    }

    /* Init channel 0 on DMA0 HW Block*/
    (void)Cy_DMA_Channel_Init(DW0, DW_CHANNEL_0, &channelConfig);
    (void)Cy_DMA_Channel_Enable(DW0, DW_CHANNEL_0);
    (void)Cy_TrigMux_SwTrigger((uint32_t)TRIG_OUT_MUX_0_PDMA0_TR_IN0, CY_TRIGGER_TWO_CYCLES);

    Cy_SysLib_ExitCriticalSection(interruptState);
    while(Cy_DMA_Channel_GetInterruptStatus(DW0,DW_CHANNEL_0) == 0UL)
    {

    }
    Cy_DMA_Disable(DW0);
}


/******************************************************************************
* Function Name: Cy_System_Copy_PPCA_Image_To_Memory
***************************************************************************//**
*
* Copies image from the given address to PPCA RAM.
*
* \note Enables DMA and uses channel 0 for copying. Disables DMA after copying the image.
* This is mainly used when remap memory is enabled and only core0 is used.
* M0, M2 and M3 are used for Core0 code and M1 and M4 for Core0 data.
* If the image size is more then 32k, user has to use this function to copy first 32k to M0, next 32K to M2 and next 16K to M3
*
* \param flash_address The pointer to the flash address where the CPU0 image is present.
*
* \param image_size Size of the image.
*
* \param memory_number image is for M0, M2 or M3. \ref cy_en_ppca_memory_t
*
******************************************************************************/
void Cy_System_Copy_PPCA_Image_To_Memory(void *flash_address, uint32_t image_size, cy_en_ppca_memory_t memory_number)
{
    CY_ASSERT_L3(image_size <= CY_SRAM_M0_SIZE);
    CY_ASSERT_L3(flash_address);
    (void)image_size;
    uint32_t interruptState;

    interruptState = Cy_SysLib_EnterCriticalSection();

    Cy_DMA_Enable(DW0);
    (void)Cy_DMA_Descriptor_Init(&descriptor_0, &descriptor_config);
    if(memory_number == CY_PPCA_MEMORY_3)
    {
        Cy_DMA_Descriptor_SetYloopDataCount(&descriptor_0, 16u);
    }
    else
    {
        Cy_DMA_Descriptor_SetYloopDataCount(&descriptor_0, 32u);
    }

    Cy_DMA_Descriptor_SetSrcAddress(&descriptor_0, flash_address);
    if(memory_number == CY_PPCA_MEMORY_2)
    {
        Cy_DMA_Descriptor_SetDstAddress(&descriptor_0, (void*)(CY_SRAM_M2_BASE));
    }
    else if(memory_number == CY_PPCA_MEMORY_0)
    {
        Cy_DMA_Descriptor_SetDstAddress(&descriptor_0, (void*)(CY_SRAM_M0_BASE));
    }
    else
    {
        Cy_DMA_Descriptor_SetDstAddress(&descriptor_0, (void*)(CY_SRAM_M3_BASE));
    }

    /* Init channel 0 on DMA0 HW Block*/
    (void)Cy_DMA_Channel_Init(DW0, DW_CHANNEL_0, &channelConfig);
    (void)Cy_DMA_Channel_Enable(DW0, DW_CHANNEL_0);
    (void)Cy_TrigMux_SwTrigger((uint32_t)TRIG_OUT_MUX_0_PDMA0_TR_IN0, CY_TRIGGER_TWO_CYCLES);

    Cy_SysLib_ExitCriticalSection(interruptState);
    while(Cy_DMA_Channel_GetInterruptStatus(DW0,DW_CHANNEL_0) == 0UL)
    {

    }
    Cy_DMA_Disable(DW0);
}

/******************************************************************************
* Function Name: Cy_System_PPCA_RAM_Enable
***************************************************************************//**
*
* Enables PPCA RAM. This needs to be called before starting the PPCA core
*
******************************************************************************/
void Cy_System_PPCA_RAM_Enable(void)
{
    uint32_t timeoutUs = CY_PD1_PWR_UP_US;
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM0_BASE, (uint32_t)CY_PPCA_SRAM_PPU_ON_MODE);
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM1_BASE, (uint32_t)CY_PPCA_SRAM_PPU_ON_MODE);
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM2_BASE, (uint32_t)CY_PPCA_SRAM_PPU_ON_MODE);
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM3_BASE, (uint32_t)CY_PPCA_SRAM_PPU_ON_MODE);
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM4_BASE, (uint32_t)CY_PPCA_SRAM_PPU_ON_MODE);
    /* Wait for up to PD1_PWR_UP_US timeout while polling CY_PPU_PPCA_SRAM4_BASE->PWSR_PWR_POLICY == 0x8 */
    for (; (cy_pd_ppu_get_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM4_BASE) != CY_PPCA_SRAM_PPU_ON_MODE ) && (0UL != timeoutUs); timeoutUs--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    CY_ASSERT(timeoutUs != 0);
}

/******************************************************************************
* Function Name: Cy_System_PPCA_RAM_Disable
***************************************************************************//**
*
* Disables PPCA RAM. This needs to be called before going to Deepsleep.
*
******************************************************************************/
void Cy_System_PPCA_RAM_Disable(void)
{
    uint32_t timeoutUs = CY_PD1_PWR_UP_US;
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM0_BASE, (uint32_t)CY_PPCA_SRAM_PPU_OFF_MODE);
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM1_BASE, (uint32_t)CY_PPCA_SRAM_PPU_OFF_MODE);
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM2_BASE, (uint32_t)CY_PPCA_SRAM_PPU_OFF_MODE);
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM3_BASE, (uint32_t)CY_PPCA_SRAM_PPU_OFF_MODE);
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM4_BASE, (uint32_t)CY_PPCA_SRAM_PPU_OFF_MODE);
    /* Wait for up to PD1_PWR_UP_US timeout while polling CY_PPU_PPCA_SRAM4_BASE->PWSR_PWR_POLICY == 0x0 */
    for (; (cy_pd_ppu_get_power_mode((struct ppu_v1_reg *)CY_PPU_PPCA_SRAM4_BASE) != CY_PPCA_SRAM_PPU_OFF_MODE ) && (0UL != timeoutUs); timeoutUs--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    CY_ASSERT(timeoutUs != 0);
}
#endif /*!defined (COMPONENT_PPCA_DEVICE)*/
#endif /* defined (CY_IP_MXS40PPSS) */
/* [] END OF FILE */

