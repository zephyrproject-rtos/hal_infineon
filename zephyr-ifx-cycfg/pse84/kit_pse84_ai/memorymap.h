/* AUTO-GENERATED FILE, DO NOT EDIT. ALL CHANGES WILL BE LOST! */
#pragma once

#if defined(COMPONENT_MW_IFX_MCUBOOT_PSE84)

#include <stdint.h>
#include "bootutil/bootutil.h"
#include "flash_map_backend.h"

#define MEMORYMAP_GENERATED_AREAS 1

extern struct flash_device flash_devices[];
extern struct flash_area *boot_area_descs[];

extern uint8_t memory_areas_primary[];
extern uint8_t memory_areas_secondary[];

enum 
{
 INTERNAL_S_SRAM,
 INTERNAL_NS_SRAM,
 INTERNAL_RRAM,
 EXTERNAL_S_FLASH,
 EXTERNAL_NS_FLASH,
};

enum 
{
 FLASH_AREA_BOOTLOADER = 0U,
 FLASH_AREA_IMG_1_PRIMARY = 1U,
 FLASH_AREA_IMG_1_SECONDARY = 2U,
 FLASH_AREA_IMG_2_PRIMARY = 4U,
 FLASH_AREA_IMG_2_SECONDARY = 5U,
 FLASH_AREA_IMG_3_PRIMARY = 6U,
 FLASH_AREA_IMG_3_SECONDARY = 7U,
 FLASH_AREA_IMG_4_PRIMARY = 8U,
 FLASH_AREA_IMG_4_SECONDARY = 9U,
 FLASH_AREA_IMG_5_PRIMARY = 10U,
 FLASH_AREA_IMG_5_SECONDARY = 11U,
 FLASH_AREA_IMAGE_SWAP_STATUS = 12U,
 FLASH_AREA_IMAGE_SCRATCH = 13U,
};

typedef enum 
{
 IMAGE_BOOT_MODE_FLASH = 0U,
 IMAGE_BOOT_MODE_RAM = 1U,
} image_boot_mode_t;

typedef struct image_boot_config_s 
{
 image_boot_mode_t mode;
 uint32_t address;
 uint32_t size;
} image_boot_config_t;

extern image_boot_config_t image_boot_config[BOOT_IMAGE_NUMBER];

#endif /* defined(COMPONENT_MW_IFX_MCUBOOT_PSE84) */
