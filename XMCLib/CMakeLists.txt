# SPDX-License-Identifier: Apache-2.0
#
# Copyright (c) 2020 Linumiz
# Author: Parthiban Nallathambi <parthiban@linumiz.com>

string(TOUPPER "${CONFIG_SOC}" soc_name_upper_case)
zephyr_compile_definitions(${soc_name_upper_case}_${CONFIG_SOC_PART_NUMBER})
zephyr_include_directories(devices/${soc_name_upper_case}/Include)
zephyr_library_sources(devices/${soc_name_upper_case}/Source/system_${soc_name_upper_case}.c)
add_subdirectory(drivers)
