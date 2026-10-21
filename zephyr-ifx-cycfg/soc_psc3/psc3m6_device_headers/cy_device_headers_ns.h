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

#if defined (PSC3M6FDS2ACQ1)
    #include "psc3m6fds2acq1.h"
#elif defined (PSC3M6FDS2AFQ1)
    #include "psc3m6fds2afq1.h"
#elif defined (PSC3M6FDS2AHQ1)
    #include "psc3m6fds2ahq1.h"
#elif defined (PSC3M6GES3ACQ1)
    #include "psc3m6ges3acq1.h"
#elif defined (PSC3M6GES3AFQ1)
    #include "psc3m6ges3afq1.h"
#elif defined (PSC3M6GES3AHQ1)
    #include "psc3m6ges3ahq1.h"
#elif defined (PSC3P6FDS2ACQ1)
    #include "psc3p6fds2acq1.h"
#elif defined (PSC3P6FDS2AFQ1)
    #include "psc3p6fds2afq1.h"
#elif defined (PSC3P6FDS2AHQ1)
    #include "psc3p6fds2ahq1.h"
#elif defined (PSC3P6GES3ACQ1)
    #include "psc3p6ges3acq1.h"
#elif defined (PSC3P6GES3AFQ1)
    #include "psc3p6ges3afq1.h"
#elif defined (PSC3P6GES3AHQ1)
    #include "psc3p6ges3ahq1.h"
#else
    #error Undefined part number.
#endif

#endif /* _CY_DEVICE_HEADERS_H_ */

/* [] END OF FILE */
