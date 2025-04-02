#if !defined(TVIIBE_PARTITION_H)
#define TVIIBE_PARTITION_H

#if defined (CY_DEVICE_SERIES_CYT2B6)   /* *** TVIIBE 512K *** */

#define STACK_SIZE                      0x1000
#define RAMVECTORS_ALIGNMENT            8

#define SRAM_START_RESERVE              0
#define SRAM_PRIVATE_FOR_SROM           0x800 /* 2K Private SRAM for SROM (e.g. API processing). Reserved at the beginning */

/* RAM */
#define SRAM_BASE_ADDRESS               0x08000000  /* SRAM START */
#define CM0PLUS_SRAM_RESERVE            0x00004000  /* 16K cm0plus */

/* FLASH */
#define CODE_FLASH_BASE_ADDRESS         0x10000000  /* FLASH START */
#define CM0PLUS_CODE_FLASH_RESERVE      0x00008000  /* 32K CM0P FLASH SIZE (minimum sector size) */
#define CM4_0_CODE_FLASH_RESERVE        0x00088000  /* 544K CM4_0 FLASH SIZE */

#elif defined (CY_DEVICE_SERIES_CYT2B7) /* *** TVIIBE 1M *** */

#define STACK_SIZE                      0x1000
#define RAMVECTORS_ALIGNMENT            8

#define SRAM_START_RESERVE              0
#define SRAM_PRIVATE_FOR_SROM           0x800 /* 2K Private SRAM for SROM (e.g. API processing). Reserved at the beginning */

/* RAM */
#define SRAM_BASE_ADDRESS               0x08000000  /* SRAM START */
#define CM0PLUS_SRAM_RESERVE            0x00008000  /* 32K cm0plus */

/* FLASH */
#define CODE_FLASH_BASE_ADDRESS         0x10000000  /* FLASH START */
#define CM0PLUS_CODE_FLASH_RESERVE      0x00020000  /* 128K CM0P FLASH SIZE (minimum sector size) */
#define CM4_0_CODE_FLASH_RESERVE        0x000F0000  /* 960K CM4_0 FLASH SIZE */

#elif defined (CY_DEVICE_SERIES_CYT2B9) /* *** TVIIBE 2M *** */

#define STACK_SIZE                      0x1000
#define RAMVECTORS_ALIGNMENT            8

#define SRAM_START_RESERVE              0
#define SRAM_PRIVATE_FOR_SROM           0x800 /* 2K Private SRAM for SROM (e.g. API processing). Reserved at the beginning */

/* RAM */
#define SRAM_BASE_ADDRESS               0x08000000  /* SRAM START */
#define CM0PLUS_SRAM_RESERVE            0x00010000  /* 64K cm0plus */

/* FLASH */
#define CODE_FLASH_BASE_ADDRESS         0x10000000  /* FLASH START */
#define CM0PLUS_CODE_FLASH_RESERVE      0x00040000  /* 256K CM0P FLASH SIZE (minimum sector size) */
#define CM4_0_CODE_FLASH_RESERVE        0x001D0000  /* 1856K CM4_0 FLASH SIZE */

#elif defined (CY_DEVICE_SERIES_CYT2BL) /* *** TVIIBE 4M *** */

#define STACK_SIZE                      0x1000
#define RAMVECTORS_ALIGNMENT            8

#define SRAM_START_RESERVE              0
#define SRAM_PRIVATE_FOR_SROM           0x800 /* 2K Private SRAM for SROM (e.g. API processing). Reserved at the beginning */

/* RAM */
#define SRAM_BASE_ADDRESS               0x08000000  /* SRAM START */
#define CM0PLUS_SRAM_RESERVE            0x00020000  /* 128K (SRAM0/128KB) -> cm0plus */

/* FLASH */
#define CODE_FLASH_BASE_ADDRESS         0x10000000  /* FLASH START */
#define CM0PLUS_CODE_FLASH_RESERVE      0x00080000  /* 512K CM0P FLASH SIZE */
#define CM4_0_CODE_FLASH_RESERVE        0x00380000  /* 3670K CM4_0 FLASH SIZE */

#else
#error "Traveo II Body Entry partition file was included, but no device was detected."
#endif


/* Common definitions for all devices. */

/* Flash sector size */
#define TVII_FLASHC_SECTOR_SIZE         0x8000
#if (CM0PLUS_CODE_FLASH_RESERVE % TVII_FLASHC_SECTOR_SIZE != 0)
#warning "The tviibe_partition.h defines CM0PLUS_CODE_FLASH_RESERVE to a value that does not land on a flash boundary.  This will cause partial erasure of the beginning of CM4 application anytime the CM0+ application is flashed."
#endif

/* SRAM reservations */
#define BASE_SRAM_CM0P                  SRAM_BASE_ADDRESS + SRAM_START_RESERVE + SRAM_PRIVATE_FOR_SROM
#define SIZE_SRAM_CM0P                  CM0PLUS_SRAM_RESERVE - SRAM_START_RESERVE - SRAM_PRIVATE_FOR_SROM
#define BASE_SRAM_CM4_0                 SRAM_BASE_ADDRESS + CM0PLUS_SRAM_RESERVE

/* Code flash reservations */
#define BASE_CODE_FLASH_CM0P            CODE_FLASH_BASE_ADDRESS
#define SIZE_CODE_FLASH_CM0P            CM0PLUS_CODE_FLASH_RESERVE
#define BASE_CODE_FLASH_CM4_0           CODE_FLASH_BASE_ADDRESS + CM0PLUS_CODE_FLASH_RESERVE
#define SIZE_CODE_FLASH_CM4_0           CM4_0_CODE_FLASH_RESERVE

#endif /* TVIIBE_PARTITION_H */

