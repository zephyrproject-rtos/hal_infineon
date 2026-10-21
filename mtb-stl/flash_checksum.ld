/*
 * Linker script to place .flash_checksum section at the end of flash
 * This ensures the checksum is excluded from its own calculation
 */

SECTION_PROLOGUE(.flash_checksum,,)
{
    KEEP(*(.flash_checksum))
} GROUP_LINK_IN(ROMABLE_REGION)

