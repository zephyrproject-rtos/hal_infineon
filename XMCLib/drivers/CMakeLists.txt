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
zephyr_sources(src/xmc_gpio.c)

if(CONFIG_SOC_SERIES_XMC_1XXX)
  zephyr_sources(src/xmc1_scu.c)
  zephyr_sources(src/xmc1_gpio.c)
elseif(CONFIG_SOC_SERIES_XMC_4XXX)
  zephyr_sources(src/xmc4_scu.c)
  zephyr_sources(src/xmc4_gpio.c)
endif()

zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_UART src/xmc_uart.c)
