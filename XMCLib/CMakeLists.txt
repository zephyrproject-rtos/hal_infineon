# SPDX-License-Identifier: Apache-2.0
#
# Copyright (c) 2020 Linumiz
# Author: Parthiban Nallathambi <parthiban@linumiz.com>

zephyr_compile_definitions(${CONFIG_SOC}_${CONFIG_SOC_PART_NUMBER})
zephyr_include_directories(devices/${CONFIG_SOC}/Include)
zephyr_library_sources(devices/${CONFIG_SOC}/Source/system_${CONFIG_SOC}.c)
add_subdirectory(drivers)
