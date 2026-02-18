/***************************************************************************//**
* \file cy_system_ppca_init.h
* \version 1.0
*
* The header file of the PPCA System init driver.
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


#if !defined(CY_SYSTEM_PPCA_INIT_H)
#define CY_SYSTEM_PPCA_INIT_H

#include "cy_device.h"
#include "cy_device_headers.h"

#if defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN)

#if defined(__cplusplus)
extern "C" {
#endif

#if !defined (COMPONENT_PPCA_DEVICE)

/**
* \addtogroup group_ppca_startup
* Driver API for PPCA ADC.
*
* \{
*/

/**
* \defgroup group_ppca_startup_functions             Functions
* \defgroup group_ppca_startup_data_structures Data Structures
* \} */


/** \cond INTERNAL */
/** TBD :  This should be moved to cy_device.h */
#define CY_SRAM_M0_OFFSET                 0x00010000UL
#define CY_SRAM_M0_BASE                   (PPCA_BASE + CY_SRAM_M0_OFFSET)
#define CY_SRAM_M0_SIZE                   0x8000UL

#define CY_SRAM_M1_OFFSET                 0x00020000UL
#define CY_SRAM_M1_BASE                   (PPCA_BASE + CY_SRAM_M1_OFFSET)
#define CY_SRAM_M1_SIZE                   0x4000UL

#define CY_SRAM_M2_OFFSET                 0x00030000UL
#define CY_SRAM_M2_BASE                   (PPCA_BASE + CY_SRAM_M2_OFFSET)
#define CY_SRAM_M2_SIZE                   0x8000UL

#define CY_SRAM_M3_OFFSET                 0x00040000UL
#define CY_SRAM_M3_BASE                   (PPCA_BASE + CY_SRAM_M3_OFFSET)
#define CY_SRAM_M3_SIZE                   0x4000UL

#define CY_SRAM_M4_OFFSET                 0x00050000UL
#define CY_SRAM_M4_BASE                   (PPCA_BASE + CY_SRAM_M4_OFFSET)
#define CY_SRAM_M4_SIZE                   0x4000UL

#define CY_SRAM_CPU0_BASE                 0x00000000UL
#define CY_SRAM_CPU1_BASE                 0x00000000UL


#define CY_SYS_CORE_PWR_CTL_KEY_OPEN            (0x05FAUL)  /**< Power Control Key Open */
#define CY_SYS_CORE_PWR_CTL_KEY_CLOSE           (0xFA05UL)  /**< Power Control Key Close */

#define CY_SYS_CM33_IN_RESET                    (0x0U)
#define CY_SYS_CM33_NOT_IN_RESET                (0x1U)

#define CM33_CPU_EVENT                          (0xFU)
#define CY_SYS_CPU_WAIT_DEFAULT                 (0x1U)

#define CY_SYS_CORE_STATUS_ACTIVE               (0x0U)    /**< The core is in Active mode */
#define CY_SYS_CORE_WAIT_INFINITE               (0x0U)    /**< Wait in a loop for Infinite micro second */
#define CY_SYS_CORE_WAIT_10US                   (10U)

#define DW_CHANNEL_0 0
/** \endcond */

/**
* \addtogroup group_ppca_startup_data_structures
* \{
*/

/** Specifies the PPCA Core  */
typedef enum
{
    CY_PPCA_CORE_0      = 0UL,        /**< PPCA Core 0    */
    CY_PPCA_CORE_1      = 1UL,        /**< PPCA Core 1    */
} cy_en_ppca_core_t;

/** Specifies the PPCA Memory  */
typedef enum
{
    CY_PPCA_MEMORY_0      = 0UL,        /**< PPCA Memory 0    */
    CY_PPCA_MEMORY_2      = 2UL,        /**< PPCA Memory 2    */
    CY_PPCA_MEMORY_3      = 3UL,        /**< PPCA Memory 3    */
} cy_en_ppca_memory_t;


/** \} group_ppca_startup_data_structures */


/**
* \addtogroup group_ppca_startup_functions
* \{
*/
/******************************************************************************
* Function Name: Cy_System_PPCA_RAM_Enable
***************************************************************************//**
*
* Enables PPCA RAM. This needs to be called before starting the PPCA core
*
* \note This is enabled from Syspm init. If Power is not enabled then this needs to be called by the application.
*
******************************************************************************/
void Cy_System_PPCA_RAM_Enable(void);

/******************************************************************************
* Function Name: Cy_System_PPCA_RAM_Enable
***************************************************************************//**
*
* Disables PPCA RAM. This needs to be called before going to Deepsleep.
*
******************************************************************************/
void Cy_System_PPCA_RAM_Disable(void);

/******************************************************************************
* Function Name: Cy_System_Init_CPU0
***************************************************************************//**
*
* Copies image from the given address to PPCA CPU0 RAM0.
* Initializes and starts CPU0
*
* \param flash_address The pointer to the flash address where the CPU0 image is present.
*
* \param image_size Size of CPU0 image.
*
******************************************************************************/
void Cy_System_Init_CPU0(void *flash_address, uint32_t image_size);

#if !defined (PPCA_CORE1_WOUNDING_ENABLED)
/******************************************************************************
* Function Name: Cy_System_Init_CPU1
***************************************************************************//**
*
* Copies image from the given address to PPCA CPU1 RAM3.
* Initializes and starts CPU1
*
* \param flash_address The pointer to the flash address where the CPU1 image is present.
*
* \param image_size Size of CPU1 image.
*
******************************************************************************/
void Cy_System_Init_CPU1(void *flash_address, uint32_t image_size);


/******************************************************************************
* Function Name: Cy_System_Init_CPU0_CPU1
***************************************************************************//**
*
* Copies images from the given addresses to their respective PPCA RAM.
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
void Cy_System_Init_CPU0_CPU1(void *flash_cpu0_address, uint32_t cpu0_image_size, void *flash_cpu1_address, uint32_t cpu1_image_size);

#endif /* !defined (PPCA_CORE1_WOUNDING_ENABLED) */
/*******************************************************************************
* Function Name: Cy_SysGetCM33_0_Status
****************************************************************************//**
*
* Returns the Cortex-M33 core power mode.
*
* \return \ref group_system_config_core_status_macro_1d
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysGetCM33_0_Status(void)
{
    /* Return current power mode */
    return (PPCA_CPUSS_CNFG_MXCM330->CM33_STATUS);
}
#if !defined (PPCA_CORE1_WOUNDING_ENABLED)
/*******************************************************************************
* Function Name: Cy_SysGetCM33_1_Status
****************************************************************************//**
*
* Returns the Cortex-M33 core power mode.
*
* \return \ref group_system_config_core_status_macro_1d
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysGetCM33_1_Status(void)
{
    /* Return current power mode */
    return (PPCA_CPUSS_CNFG_MXCM331->CM33_STATUS);
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
* \note User has to copy PPCA core image to PPCA memory. before calling this function.
*
*
*******************************************************************************/
void Cy_SysEnable_PPCA_Core0(void);

/*******************************************************************************
* Function Name: Cy_SysEnable_PPCA_Core1
****************************************************************************//**
*
* Sets vector table base address and enables the PPCA Cortex-M33 core1.
*
* \note If the CPU is already enabled, it is reset and then enabled.
*
* \note User has to copy PPCA core image to PPCA memory. before calling this function.
*
*
*******************************************************************************/
void Cy_SysEnable_PPCA_Core1(void);


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
* \param core_number image is for Core 0 or Core 1. \ref cy_en_ppca_core_t
*
******************************************************************************/
void Cy_System_Copy_PPCA_Image(void *flash_address, uint32_t image_size, cy_en_ppca_core_t core_number);

/******************************************************************************
* Function Name: Cy_System_Copy_PPCA_Image_Memcpy
***************************************************************************//**
*
* Copies image from the given address to PPCA RAM for Core 0 or Core1 using memcpy.
*
* \param flash_address The pointer to the flash address where the image is present.
*
* \param image_size Size of the image.
*
* \param core_number image is for Core 0 or Core 1. \ref cy_en_ppca_core_t
*
******************************************************************************/
void Cy_System_Copy_PPCA_Image_Memcpy(void *flash_address, uint32_t image_size, cy_en_ppca_core_t core_number);

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
void Cy_System_Copy_PPCA_Image_To_Memory(void *flash_address, uint32_t image_size, cy_en_ppca_memory_t memory_number);

/** \} group_ppca_startup_functions */

#endif /*!defined (COMPONENT_PPCA_DEVICE)*/

#if defined(__cplusplus)
}
#endif
#endif /*defined (CY_IP_MXS40PPSS) */

#endif /* CY_SYSTEM_PPCA_INIT_H */

