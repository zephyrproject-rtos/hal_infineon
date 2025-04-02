/***************************************************************************//**
* \file psc3_s_ram.ld
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
* Copyright 2016-2020 Cypress Semiconductor Corporation
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

SRAM0_SIZE              = 0x00010000; /* 64K - Total SRAM size */
SRAM0_S_SIZE            = 0x00004000; /* 16K reserved for secure application */

/* secure addresses */
CODE_SRAM0_S_SAHB_START = 0x34000000; /* SBUS: Start of SRAM */
CODE_SRAM0_S_CBUS_START = 0x14000000; /* CBUS: Start of SRAM */
CODE_SRAM0_S_SIZE       = SRAM0_S_SIZE;

SRAM0_NSC_SIZE          = 0x00000800; /* 2K reserved for NSC */
SRAM0_S_SHM_SIZE        = 0x00000800; /* 2K reserved for secure shared memory */
SHM_SRAM0_S_SAHB_START  = CODE_SRAM0_S_SAHB_START + SRAM0_SIZE - SRAM0_S_SHM_SIZE - SRAM0_NSC_SIZE; /* 0x3400F800 */

DATA_SRAM0_S_SAHB_START = CODE_SRAM0_S_SAHB_START;
DATA_SRAM0_S_SIZE       = SRAM0_S_SIZE;

CODE_SRAM0_S_START      = CODE_SRAM0_S_CBUS_START;
DATA_SRAM0_S_START      = DATA_SRAM0_S_SAHB_START;

SRAM0_S_SHM_START       = SHM_SRAM0_S_SAHB_START;

SRAM0_NSC_VMA_START     = CODE_SRAM0_S_CBUS_START + SRAM0_SIZE - SRAM0_NSC_SIZE;
SRAM0_NSC_LMA_START     = CODE_SRAM0_S_SAHB_START + SRAM0_SIZE - SRAM0_NSC_SIZE;

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

    code             (rx)    : ORIGIN = CODE_SRAM0_S_START,  LENGTH = CODE_SRAM0_S_SIZE
    data             (rwx)   : ORIGIN = DATA_SRAM0_S_START,  LENGTH = DATA_SRAM0_S_SIZE
    shm_sram0        (rwx)   : ORIGIN = SRAM0_S_SHM_START,   LENGTH = SRAM0_S_SHM_SIZE
    nsc              (rwx)   : ORIGIN = SRAM0_NSC_VMA_START, LENGTH = SRAM0_NSC_SIZE
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
    .text ORIGIN(code) : AT(CODE_SRAM0_S_SAHB_START)
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
    } > code


    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > code

    __exidx_start = .;

    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > code
    __exidx_end = .;


    /* copy code-RAM to data-RAM */
    .copy.table :
    {
        . = ALIGN(4);
        __copy_table_start__ = .;
        __copy_table_end__ = .;
    } > code


    /* Mark bss sections */
    .zero.table :
    {
        . = ALIGN(4);
        __zero_table_start__ = .;
        LONG (__bss_start__)
        LONG ((__bss_end__ - __bss_start__)/4)
        __zero_table_end__ = .;
    } > code

    __etext =  . ;

    __ramVectors_vma__ = ORIGIN(data) + (__etext - ORIGIN(code));

    .ramVectors __ramVectors_vma__ (NOLOAD) : /*ALIGN(8)*/
    {
        . = ALIGN(RAMVECTORS_ALIGNMENT);
        __ram_vectors_start__ = .;
        KEEP(*(.ram_vectors))
        __ram_vectors_end__   = .;
    } > data


    .data :
    {
        __data_start__ = .;

        . = ALIGN(4);
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

    } > data


    /* Place variables in the section that should not be initialized during the
    *  device startup.
    */
    .noinit (NOLOAD) : ALIGN(8)
    {
      KEEP(*(.noinit))
    } > data


    /* The uninitialized global or static variables are placed in this section.
    *
    * The NOLOAD attribute tells linker that .bss section does not consume
    * any space in the image. The NOLOAD attribute changes the .bss type to
    * NOBITS, and that  makes linker to A) not allocate section in memory, and
    * A) put information to clear the section with all zeros during application
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
    } > data


    .heap (NOLOAD):
    {
        . = ALIGN(8);
        __HeapBase = .;
        __end__ = .;
        end = __end__;
        KEEP(*(.heap*))
        . = ALIGN(8);
        . = ORIGIN(data) + LENGTH(data) - STACK_SIZE;
        __HeapLimit = .;
    } > data


    /* .stack_dummy section doesn't contains any symbols. It is only
     * used for linker to calculate size of stack sections, and assign
     * values to stack symbols later */
    .stack_dummy (NOLOAD):
    {
        KEEP(*(.stack*))
    } > data


    .cy_sharedmem (NOLOAD):
    {
        . = ALIGN(4);
        __public_ram_start__ = .;
        KEEP(*(.cy_sharedmem))
        . = ALIGN(4);
        __public_ram_end__ = .;
    } > shm_sram0

    .gnu.sgstubs : AT(SRAM0_NSC_LMA_START)
    {
        . = ALIGN(32);
        _start_sg = .;
        *(.gnu.sgstubs*)
        . = ALIGN(32);
        _end_sg = .;
    } > nsc

    /* Set stack top to end of RAM, and stack limit move down by
     * size of stack_dummy section */
    . = ALIGN(32);
    __StackTop = ORIGIN(data) + LENGTH(data);
    __StackLimit = __StackTop - STACK_SIZE;
    PROVIDE(__stack = __StackTop);

    /* Check if data + heap + stack exceeds RAM limit */
    ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")

}


/* EOF */
