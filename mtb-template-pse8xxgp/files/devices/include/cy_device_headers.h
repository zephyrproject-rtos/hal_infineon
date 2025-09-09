/***************************************************************************//**
* \file cy_device_headers.h
*
* \brief
* Common header file to be included by the drivers.
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

#ifndef _CY_DEVICE_HEADERS_H_
#define _CY_DEVICE_HEADERS_H_

#if defined (COMPONENT_SECURE_DEVICE)

#if defined (PSE846GPS4DBZC4A)
    #include "pse846gps4dbzc4a_s.h"
#elif defined (PSE846GPS2DBZC4A)
    #include "pse846gps2dbzc4a_s.h"
#elif defined (PSE845GPS2DFNC4A)
    #include "pse845gps2dfnc4a_s.h"
#elif defined (PSE845GPS2DFMC4A)
    #include "pse845gps2dfmc4a_s.h"
#elif defined (PSE846GPS2DBZQ3A)
    #include "pse846gps2dbzq3a_s.h"
#else
    #error Undefined part number. Consider updating PDL via ModusToolbox Library Manager to resolve the issue.
#endif

#else
#if defined (PSE846GPS4DBZC4A)
    #include "pse846gps4dbzc4a.h"
#elif defined (PSE846GPS2DBZC4A)
    #include "pse846gps2dbzc4a.h"
#elif defined (PSE845GPS2DFNC4A)
    #include "pse845gps2dfnc4a.h"
#elif defined (PSE845GPS2DFMC4A)
    #include "pse845gps2dfmc4a.h"
#elif defined (PSE846GPS2DBZQ3A)
    #include "pse846gps2dbzq3a.h"
#else
    #error Undefined part number. Consider updating PDL via ModusToolbox Library Manager to resolve the issue.
#endif

#endif

#endif /* _CY_DEVICE_HEADERS_H_ */


/* [] END OF FILE */
