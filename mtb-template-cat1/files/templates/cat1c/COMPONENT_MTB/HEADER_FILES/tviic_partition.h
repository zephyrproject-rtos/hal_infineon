#if !defined(TVIIC_PARTITION_H)
#define TVIIC_PARTITION_H

#define STACK_SIZE                      0x1000
#define RAMVECTORS_ALIGNMENT            128

#define SRAM_START_RESERVE              0
#define SRAM_PRIVATE_FOR_SROM           0x800 /* 2K Private SRAM for SROM (e.g. API processing). Reserved at the beginning */

/* DEVICE RAM */
#define SRAM_BASE_ADDRESS               CY_SRAM_BASE  /* SRAM START */
#define TOTAL_RAM                       CY_SRAM_SIZE

/* DEVICE FLASH */
#define CODE_FLASH_BASE_ADDRESS         CY_FLASH_LG_SBM_BASE  /* FLASH START */
#define TOTAL_FLASH                     (CY_FLASH_LG_SBM_SIZE + CY_FLASH_SM_SBM_SIZE)

/* CM0P FLASH/RAM */
#define CM0PLUS_CODE_FLASH_RESERVE      0x00080000      /* 512K CM0P flash size */
#define CM0PLUS_SRAM_RESERVE            0x00004000      /* 16K cm0plus */

/* CM7_1 RAM */
#if defined (__CM7_1_PRESENT)
    #define CM7_1_SRAM_RESERVE          0x00010000      /* 64KB CM7_1 SRAM size, if present */
#else
    #define CM7_1_SRAM_RESERVE          0x00000000UL
#endif

/* CM7_0 FLASH */
#if (TOTAL_FLASH == 0x630000) /** 6M device */
    #define CM7_0_CODE_FLASH_RESERVE    0x00200000      /* 2MB CM7_0 flash size. */
#else
    #error "Invalid device"
#endif


/* SRAM reservations */
#define BASE_SRAM_CM0P                  (SRAM_BASE_ADDRESS + SRAM_START_RESERVE + SRAM_PRIVATE_FOR_SROM)
#define SIZE_SRAM_CM0P                  (CM0PLUS_SRAM_RESERVE - SRAM_START_RESERVE - SRAM_PRIVATE_FOR_SROM)
#define BASE_SRAM_CM7_0                 (SRAM_BASE_ADDRESS + CM0PLUS_SRAM_RESERVE)
#define SIZE_SRAM_CM7_0                 TOTAL_RAM - CM0PLUS_SRAM_RESERVE - CM7_1_SRAM_RESERVE
#define BASE_SRAM_CM7_1                 SRAM_BASE_ADDRESS + CM0PLUS_SRAM_RESERVE + SIZE_SRAM_CM7_0
#define SIZE_SRAM_CM7_1                 CM7_1_SRAM_RESERVE

/* Code flash reservations */
#define BASE_CODE_FLASH_CM0P            CODE_FLASH_BASE_ADDRESS
#define SIZE_CODE_FLASH_CM0P            CM0PLUS_CODE_FLASH_RESERVE
#define BASE_CODE_FLASH_CM7_0           CODE_FLASH_BASE_ADDRESS + CM0PLUS_CODE_FLASH_RESERVE
#define SIZE_CODE_FLASH_CM7_0           CM7_0_CODE_FLASH_RESERVE
#define BASE_CODE_FLASH_CM7_1           CODE_FLASH_BASE_ADDRESS + CM0PLUS_CODE_FLASH_RESERVE + CM7_0_CODE_FLASH_RESERVE
#define SIZE_CODE_FLASH_CM7_1           TOTAL_FLASH - SIZE_CODE_FLASH_CM0P - SIZE_CODE_FLASH_CM7_0

/* Partitioning validation */ 
/* Flash sector size */
#define TVIIC_FLASHC_SECTOR_SIZE         0x8000  /* Large sector size is 32KB */
#if (CM0PLUS_CODE_FLASH_RESERVE % TVIIC_FLASHC_SECTOR_SIZE != 0) 
#warning "The tviic_partition.h defines CM0PLUS_CODE_FLASH_RESERVE to a value that does not land on a flash boundary.  This can potentially cause partial erasure of the beginning of CM7_0 application anytime the CM0+ application is separately flashed."
#endif
#if (CM7_0_CODE_FLASH_RESERVE % TVIIC_FLASHC_SECTOR_SIZE != 0)
#warning "The tviic_partition.h defines CM7_0_CODE_FLASH_RESERVE to a value that does not land on a flash boundary.  This can potentially cause partial erasure of the beginning of CM7_1 application anytime the CM7_0 application is flashed."
#endif


#endif /* TVIIC_PARTITION_H */


/* [] END OF FILE */
