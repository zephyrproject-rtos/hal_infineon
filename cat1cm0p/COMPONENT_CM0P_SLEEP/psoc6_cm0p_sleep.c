/*
Copyright 2020-2022, Cypress Semiconductor Corporation (an Infineon company)
SPDX-License-Identifier: Apache-2.0

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/


#include <stdint.h>
#include "cy_device_headers.h"

#if defined(CY_DEVICE_PSOC6ABLE2) || defined(CY_DEVICE_PSOC6A2M) || defined(CY_DEVICE_PSOC6A512K) || defined(CY_DEVICE_PSOC6A256K)

#if defined(__APPLE__) && defined(__clang__)
__attribute__ ((__section__("__CY_M0P_IMAGE,__cy_m0p_image"), used))
#elif defined(__GNUC__) || defined(__ARMCC_VERSION)
__attribute__ ((__section__(".cy_m0p_image"), used))
#elif defined(__ICCARM__)
#pragma  location=".cy_m0p_image"
#else
#error "An unsupported toolchain"
#endif
const uint8_t cy_m0p_image[] = {
    #include <psoc6_cm0p_sleep.bin.inc>
};
#endif /* defined(CY_DEVICE_PSOC6ABLE2) || defined(CY_DEVICE_PSOC6A2M) || defined(CY_DEVICE_PSOC6A512K) || defined(CY_DEVICE_PSOC6A256K) */
