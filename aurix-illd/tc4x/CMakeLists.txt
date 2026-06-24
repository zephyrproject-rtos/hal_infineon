# SPDX-License-Identifier: Apache-2.0
#
# Copyright (c) 2026 Linumiz
# Author: Parthiban Nallathambi <parthiban@linumiz.com>

zephyr_include_directories(pinctrl/)

if(CONFIG_SOC_TC4Dx)
  zephyr_include_directories(Sfr/TC4Dx/)
endif()
