# Copyright (c) 2026 Infineon Technologies AG,
# or a subsidiary of Infineon Technologies AG.
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_POST_VENDOR_MTB_STL)

# Set base path to MTB-STL library (fetched via west)
# Path matches west.yml: modules/lib/mtb-stl
set(MTB_STL_BASE ${ZEPHYR_BASE}/../modules/lib/mtb-stl)

if(NOT EXISTS ${MTB_STL_BASE})
  message(FATAL_ERROR "MTB-STL module not found at ${MTB_STL_BASE}. Run 'west update' to fetch it.")
endif()

zephyr_library()

zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
zephyr_include_directories(${MTB_STL_BASE}/stl)
zephyr_include_directories(${MTB_STL_BASE}/export)

# Include component directories
zephyr_include_directories(${MTB_STL_BASE}/stl/cpu)
zephyr_include_directories(${MTB_STL_BASE}/stl/ram)
zephyr_include_directories(${MTB_STL_BASE}/stl/stack)
zephyr_include_directories(${MTB_STL_BASE}/stl/flash)
zephyr_include_directories(${MTB_STL_BASE}/stl/clock)
zephyr_include_directories(${MTB_STL_BASE}/stl/wdt)
zephyr_include_directories(${MTB_STL_BASE}/stl/fpu)
zephyr_include_directories(${MTB_STL_BASE}/stl/analog)
zephyr_include_directories(${MTB_STL_BASE}/stl/scb)
zephyr_include_directories(${MTB_STL_BASE}/stl/regs)
zephyr_include_directories(${MTB_STL_BASE}/stl/crc)
zephyr_include_directories(${MTB_STL_BASE}/stl/io)
zephyr_include_directories(${MTB_STL_BASE}/stl/dmac)
zephyr_include_directories(${MTB_STL_BASE}/stl/intr)
zephyr_include_directories(${MTB_STL_BASE}/stl/pwm)
zephyr_include_directories(${MTB_STL_BASE}/stl/pwm_gatekill)
zephyr_include_directories(${MTB_STL_BASE}/stl/timer_counter)

# Define linker sections for CPU tests
zephyr_linker_sources_ifdef(CONFIG_POST_MTB_STL_CPU_PC
  SECTIONS
  ${CMAKE_CURRENT_SOURCE_DIR}/cpu_test_sections.ld
)

# Define linker sections for flash checksum (place at end of flash)
zephyr_linker_sources_ifdef(CONFIG_POST_MTB_STL_FLASH
  SECTIONS
  ${CMAKE_CURRENT_SOURCE_DIR}/flash_checksum.ld
)

# POST wrapper sources
zephyr_library_sources(mtb_stl_post.c)
zephyr_library_sources(cy_sysint_zephyr.c)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_SHARED
  ${MTB_STL_BASE}/stl/common/SelfTest_common.c
)

# MTB-STL library sources
if(CONFIG_POST_MTB_STL_CPU_REGS OR CONFIG_POST_MTB_STL_CPU_PC OR CONFIG_POST_MTB_STL_PROGRAM_FLOW)
  zephyr_library_sources(${MTB_STL_BASE}/stl/cpu/SelfTest_CPU.c)
  zephyr_library_sources(${MTB_STL_BASE}/stl/TOOLCHAIN_GCC_ARM/SelfTest_CPU_Regs_GCC.S)
endif()

if(CONFIG_POST_MTB_STL_STARTUP_CFGREG OR CONFIG_POST_MTB_STL_SAVE_STARTUP_CFGREG)
  zephyr_library_sources(${MTB_STL_BASE}/stl/regs/SelfTest_ConfigRegisters.c)
  zephyr_library_sources(${MTB_STL_BASE}/stl/crc/SelfTest_CRC_calc.c)
endif()

if(CONFIG_POST_MTB_STL_RAM_MARCH OR CONFIG_POST_MTB_STL_STACK_MARCH)
  zephyr_library_sources(${MTB_STL_BASE}/stl/ram/SelfTest_RAM.c)
endif()

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_STACK
  ${MTB_STL_BASE}/stl/stack/SelfTest_Stack.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_FLASH
  ${MTB_STL_BASE}/stl/flash/SelfTest_Flash.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_GPIO
  ${MTB_STL_BASE}/stl/io/SelfTest_IO.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_WDT
  ${MTB_STL_BASE}/stl/wdt/SelfTest_WDT.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_FPU
  ${MTB_STL_BASE}/stl/fpu/SelfTest_FPU_Regs.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_DMA
  ${MTB_STL_BASE}/stl/dmac/SelfTest_DMAC.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_INTERRUPT
  ${MTB_STL_BASE}/stl/intr/SelfTest_Interrupt.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_CLOCK
  ${MTB_STL_BASE}/stl/clock/SelfTest_Clock.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_UART_LOOPBACK
  ${MTB_STL_BASE}/stl/scb/SelfTest_UART_SCB.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_COUNTER
  ${MTB_STL_BASE}/stl/timer_counter/SelfTest_Timer_Counter.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_PWM
  ${MTB_STL_BASE}/stl/pwm/SelfTest_PWM.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_PWM_GATEKILL
  ${MTB_STL_BASE}/stl/pwm_gatekill/SelfTest_PWM_GateKill.c
)

if(CONFIG_POST_MTB_STL_COMM)
  zephyr_library_sources(${MTB_STL_BASE}/stl/scb/SelfTest_UART_master_message.c)
  zephyr_library_sources(${MTB_STL_BASE}/stl/scb/SelfTest_UART_slave_message.c)
  zephyr_library_sources(${MTB_STL_BASE}/stl/crc/SelfTest_CRC_calc.c)
endif()

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_SPI_LOOPBACK
  ${MTB_STL_BASE}/stl/scb/SelfTest_SPI_SCB.c
)

zephyr_library_sources_ifdef(CONFIG_POST_MTB_STL_I2C
  ${MTB_STL_BASE}/stl/scb/SelfTest_I2C_SCB.c
)

endif()
