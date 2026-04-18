/***************************************************************************//**
* \file cy_device_headers.h
*
* \brief
* Top-level header that selects the appropriate device header based on the
* security state of the current project.
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
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

#pragma once

#if defined(PSE846GPS2DBZC4A)
    #if defined(COMPONENT_SECURE_DEVICE)
        #include "pse846gps2dbzc4a_s.h"
    #else
        #include "pse846gps2dbzc4a.h"
    #endif
#else
    #error "Unsupported PSE84 device."
#endif

/* [] END OF FILE */
