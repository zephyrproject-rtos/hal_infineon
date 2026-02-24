/***************************************************************************//**
* Common header file to be included by the drivers.
*
********************************************************************************
* \copyright
* (c) 2016-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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

#if defined (PSC3M8FES2PLGQ1)
    #include "psc3m8fes2plgq1.h"
#elif defined (PSC3M8FES2PLHQ1)
    #include "psc3m8fes2plhq1.h"
#elif defined (PSC3M8GFS3PABQ1)
    #include "psc3m8gfs3pabq1.h"
#elif defined (PSC3M8GFS3PACQ1)
    #include "psc3m8gfs3pacq1.h"
#elif defined (PSC3M8GFS3PAFQ1)
    #include "psc3m8gfs3pafq1.h"
#elif defined (PSC3M8GFS3PAHQ1)
    #include "psc3m8gfs3pahq1.h"
#elif defined (PSC3M8GFS3PLGQ1)
    #include "psc3m8gfs3plgq1.h"
#elif defined (PSC3M8GFS3PLHQ1)
    #include "psc3m8gfs3plhq1.h"
#else
    #error Undefined part number.
#endif

#endif /* _CY_DEVICE_HEADERS_H_ */

/* [] END OF FILE */
