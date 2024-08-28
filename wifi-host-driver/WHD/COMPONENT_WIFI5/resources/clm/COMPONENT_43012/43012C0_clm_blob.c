/*
 * Copyright 2024, Cypress Semiconductor Corporation (an Infineon company)
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
 */
#include "wiced_resource.h"

#ifndef WLAN_MFG_FIRMWARE
#if defined(CY_STORAGE_WIFI_DATA)
CY_SECTION_WHD(CY_STORAGE_WIFI_DATA) __attribute__( (used) )
#endif
const unsigned char wifi_firmware_clm_blob_data[7697] =
{
    #include <cyw43xx_clm_blob.inc>
};
const resource_hnd_t wifi_firmware_clm_blob =
{ RESOURCE_IN_MEMORY, 7697, {.mem = { (const char *)wifi_firmware_clm_blob_data }}};
#endif /* !WLAN_MFG_FIRMWARE */
