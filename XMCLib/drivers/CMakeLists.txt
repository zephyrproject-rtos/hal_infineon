# SPDX-License-Identifier: Apache-2.0
#
# Copyright (c) 2020 Linumiz
# Author: Parthiban Nallathambi <parthiban@linumiz.com>

if(CONFIG_CPU_CORTEX_M4)
  zephyr_compile_definitions( -DCORE_CM4 )
endif()

zephyr_include_directories(inc)

# TODO: conditional include for PIO & SCU after zephyr support
zephyr_sources(src/xmc_usic.c)
zephyr_sources(src/xmc4_scu.c)
zephyr_sources(src/xmc_gpio.c)
zephyr_sources(src/xmc4_gpio.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_UART src/xmc_uart.c)
