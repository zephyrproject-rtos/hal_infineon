# SPDX-License-Identifier: Apache-2.0
#
# Copyright (c) 2026 Linumiz
# Author: Parthiban Nallathambi <parthiban@linumiz.com>

zephyr_include_directories(pinctrl/)

if(CONFIG_SOC_TC37x)
  zephyr_include_directories(Sfr/TC37x/)
endif()

if(CONFIG_SOC_TC39xB)
  zephyr_include_directories(Sfr/TC39xB/)
endif()
