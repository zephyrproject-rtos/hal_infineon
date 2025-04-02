/***************************************************************************//**
* \file psc3xxf_ns_flash.ld
* \version 1.0.0
*
* Linker file for the GNU C compiler.
*
* The main purpose of the linker script is to describe how the sections in the
* input files should be mapped into the output file, and to control the memory
* layout of the output file.
*
* \note The entry point location is fixed and starts at 0x10000000. The valid
* application image should be placed there.
*
* \note The linker files included with the PDL template projects must be generic
* and handle all common use cases. Your project may not use every section
* defined in the linker files. In that case you may see warnings during the
* build process. In your project, you can simply comment out or remove the
* relevant code in the linker file.
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation
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

OUTPUT_FORMAT ("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys )
GROUP(libgcc.a libc.a libm.a libnosys.a)
ENTRY(Reset_Handler)

_base_SRAM_NS                = 0x24000000;
_size_SRAM                   = 0x00010000; /* 64K - Total SRAM size */
_size_SRAM_S                 = DEFINED(_size_S_SRAM) ? _size_S_SRAM : 0x00004000; /* 16k for secure application */
_size_SHM_SRAM_S             = 0x00000800; /* 2k for secure shared memory*/
_size_SHM_SRAM_NS            = 0x00000800; /* 2k for non-secure shared memory*/

_base_FLASH_NS_VMA           = 0x02000000; /* cbus flash non-secure offset */
_base_FLASH_NS_LMA           = 0x22000000; /* sbus flash non-secure offset */
_base_FLASH_S_LMA            = 0x32000000; /* sbus flash secure offset */
_size_CODE_FLASH             = 0x00040000; /* 256k */
_size_CODE_FLASH_S           = DEFINED(_size_S_FLASH) ? _size_S_FLASH : 0x00010000; /* 64k for secure application */
_size_CODE_FLASH_NS          = _size_CODE_FLASH -_size_CODE_FLASH_S;

_base_DATA_SRAM_NS           = _base_SRAM_NS + _size_SRAM_S; /* 0x24004000 */
_size_DATA_SRAM_NS           = _size_SRAM - _size_SRAM_S -_size_SHM_SRAM_S - _size_SHM_SRAM_NS;  /* 0x0000B000 - 44k */
_base_SHM_SRAM_NS            = _base_SRAM_NS + _size_SRAM_S + _size_DATA_SRAM_NS; /* 0x2400F000 */

_base_CODE_FLASH_NS_VMA      = _base_FLASH_NS_VMA + _size_CODE_FLASH_S; /* 0x02010000 */
_base_CODE_FLASH_NS_LMA      = _base_FLASH_NS_LMA + _size_CODE_FLASH_S; /* 0x22010000 */


/* The size of the stack section at the end of CM33 SRAM */
RAMVECTORS_ALIGNMENT        = 1024;
STACK_SIZE = 0x1000; /* 4K for stack */


/* Force symbol to be entered in the output file as an undefined symbol. Doing
* this may, for example, trigger linking of additional modules from standard
* libraries. You may list several symbols for each EXTERN, and you may use
* EXTERN multiple times. This command has the same effect as the -u command-line
* option.
*/
EXTERN(Reset_Handler)

/* The MEMORY section below describes the location and size of blocks of memory in the target.
* Use this section to specify the memory regions available for allocation.
*/
MEMORY
{
    /* The ram and flash regions control RAM and flash memory allocation for the CM33 core.
     */

    flash             (rx)    : ORIGIN = _base_CODE_FLASH_NS_VMA, LENGTH = _size_CODE_FLASH_NS
    sram              (rwx)   : ORIGIN = _base_DATA_SRAM_NS,      LENGTH = _size_DATA_SRAM_NS
    shm_sram          (rwx)   : ORIGIN = _base_SHM_SRAM_NS,       LENGTH = _size_SHM_SRAM_NS
}

/* Library configurations */
GROUP(libgcc.a libc.a libm.a libnosys.a)

/* Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory regions FLASH and RAM.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler : Entry of reset handler
 *
 * It defines following symbols, which code can use without definition:
 *   __exidx_start
 *   __exidx_end
 *   __copy_table_start__
 *   __copy_table_end__
 *   __zero_table_start__
 *   __zero_table_end__
 *   __etext
 *   __data_start__
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __end__
 *   end
 *   __HeapLimit
 *   __StackLimit
 *   __StackTop
 *   __stack
 *   __Vectors_End
 *   __Vectors_Size
 */


SECTIONS
{
    /* Cortex-M33 application flash area */
    .text ORIGIN(flash): AT(_base_CODE_FLASH_NS_LMA)
    {
        /* Cortex-M33 flash vector table */
        . = ALIGN(4);
        __Vectors = . ;
        KEEP(*(.vectors))
        . = ALIGN(4);
        __Vectors_End = .;
        __Vectors_Size = __Vectors_End - __Vectors;
        __end__ = .;

        . = ALIGN(4);
        *(.text*)

        KEEP(*(.init))
        KEEP(*(.fini))

        /* .ctors */
        *crtbegin.o(.ctors)
        *crtbegin?.o(.ctors)
        *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
        *(SORT(.ctors.*))
        *(.ctors)

        /* .dtors */
        *crtbegin.o(.dtors)
        *crtbegin?.o(.dtors)
        *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
        *(SORT(.dtors.*))
        *(.dtors)

        /* Read-only code (constants). */
        *(.rodata .rodata.* .constdata .constdata.* .conststring .conststring.*)

        KEEP(*(.eh_frame*))
    } > flash


    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > flash

    __exidx_start = .;

    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > flash
    __exidx_end = .;


    /* copy code-RAM to data-RAM */
    .copy.table :
    {
        . = ALIGN(4);
        __copy_table_start__ = .;

        /* Copy interrupt vectors from flash to RAM */
        LONG (__Vectors)                                    /* From */
        LONG (__ram_vectors_start__)                        /* To   */
        LONG ((__Vectors_End - __Vectors)/4)                /* Size */

        /* Copy data section from flash to RAM */
        LONG (__etext)                                      /* From */
        LONG (__data_start__)                               /* To   */
        LONG ((__data_end__ - __data_start__)/4)            /* Size */

        __copy_table_end__ = .;
    } > flash


    /* Mark bss sections */
    .zero.table :
    {
        . = ALIGN(4);
        __zero_table_start__ = .;
        LONG (__bss_start__)
        LONG ((__bss_end__ - __bss_start__)/4)
        __zero_table_end__ = .;
    } > flash


    __etext =  . ;


    .ramVectors (NOLOAD) : /*ALIGN(8)*/
    {
        . = ALIGN(RAMVECTORS_ALIGNMENT);
        __ram_vectors_start__ = .;
        KEEP(*(.ram_vectors))
        __ram_vectors_end__   = .;
    } > sram


    .data __ram_vectors_end__ : AT(_base_CODE_FLASH_NS_LMA + __etext - ORIGIN(flash))
    {
        . = ALIGN(4);
        __data_start__ = .;

        *(vtable)
        *(.data*)

        . = ALIGN(4);
        /* preinit data */
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP(*(.preinit_array))
        PROVIDE_HIDDEN (__preinit_array_end = .);

        . = ALIGN(4);
        /* init data */
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE_HIDDEN (__init_array_end = .);

        . = ALIGN(4);
        /* finit data */
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array))
        PROVIDE_HIDDEN (__fini_array_end = .);

        KEEP(*(.jcr*))
        . = ALIGN(4);

        KEEP(*(.cy_ramfunc*))
        . = ALIGN(4);

        __data_end__ = .;

    } > sram


    /* Check if data size exceeds FLASH size */
    ASSERT((__etext + (__data_end__ - __data_start__)) <= (ORIGIN(flash) + _size_CODE_FLASH_NS), "Flash overflowed, increase _size_CODE_FLASH_NS")


    /* Place variables in the section that should not be initialized during the
    *  device startup.
    */
    .noinit (NOLOAD) : ALIGN(8)
    {
      KEEP(*(.noinit))
    } > sram


    /* The uninitialized global or static variables are placed in this section.
    *
    * The NOLOAD attribute tells linker that .bss section does not consume
    * any space in the image. The NOLOAD attribute changes the .bss type to
    * NOBITS, and that  makes linker to A) not allocate section in memory, and
    * B) put information to clear the section with all zeros during application
    * loading.
    *
    * Without the NOLOAD attribute, the .bss section might get PROGBITS type.
    * This  makes linker to A) allocate zeroed section in memory, and B) copy
    * this section to RAM during application loading.
    */
    .bss (NOLOAD):
    {
        . = ALIGN(4);
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } > sram


    .heap (NOLOAD):
    {
        . = ALIGN(8);
        __HeapBase = .;
        __end__ = .;
        end = __end__;
        KEEP(*(.heap*))
        . = ALIGN(8);
        . = ORIGIN(sram) + LENGTH(sram) - STACK_SIZE;
        __HeapLimit = .;
    } > sram


    /* .stack_dummy section doesn't contains any symbols. It is only
     * used for linker to calculate size of stack sections, and assign
     * values to stack symbols later */
    .stack_dummy (NOLOAD):
    {
        KEEP(*(.stack*))
    } > sram


    .cy_sharedmem (NOLOAD):
    {
        . = ALIGN(4);
        __public_ram_start__ = .;
        KEEP(*(.cy_sharedmem))
        . = ALIGN(4);
        __public_ram_end__ = .;
    } > shm_sram


    /* Set stack top to end of RAM, and stack limit move down by
     * size of stack_dummy section */
    . = ALIGN(32);
    __StackTop = ORIGIN(sram) + LENGTH(sram);
    __StackLimit = __StackTop - STACK_SIZE;
    PROVIDE(__stack = __StackTop);

    /* Check if data + heap + stack exceeds RAM limit */
    ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")

}


/* EOF */
