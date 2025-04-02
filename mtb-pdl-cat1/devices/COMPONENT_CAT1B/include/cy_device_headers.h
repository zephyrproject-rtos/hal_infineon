/***************************************************************************//**
* \file cy_device_headers.h
*
* \brief
* Common header file to be included by the drivers.
*
********************************************************************************
* \copyright
* (c) (2016-2024), Cypress Semiconductor Corporation (an Infineon company) or
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

#if defined (PSC3M5FDS2AFQ1)
    #include "psc3m5fds2afq1_s.h"
#elif defined (PSC3M5FDS2LGQ1)
    #include "psc3m5fds2lgq1_s.h"
#elif defined (PSC3M5FDS2ACQ1)
    #include "psc3m5fds2acq1_s.h"
#elif defined (PSC3M5FDS2LHQ1)
    #include "psc3m5fds2lhq1_s.h"
#elif defined (PSC3M5FDS2ABQ1)
    #include "psc3m5fds2abq1_s.h"
#elif defined (PSC3M5EDAFQ1)
    #include "psc3m5edafq1_s.h"
#elif defined (PSC3M5EDLGQ1)
    #include "psc3m5edlgq1_s.h"
#elif defined (PSC3M5EDACQ1)
    #include "psc3m5edacq1_s.h"
#elif defined (PSC3M5EDLHQ1)
    #include "psc3m5edlhq1_s.h"
#elif defined (PSC3M5EDABQ1)
    #include "psc3m5edabq1_s.h"
#elif defined (PSC3P5EDLGQ1)
    #include "psc3p5edlgq1_s.h"
#elif defined (PSC3P5FDS2LGQ1)
    #include "psc3p5fds2lgq1_s.h"
#elif defined (PSC3P5EDACQ1)
    #include "psc3p5edacq1_s.h"
#elif defined (PSC3P5FDS2ACQ1)
    #include "psc3p5fds2acq1_s.h"
#elif defined (PSC3P5EDLHQ1)
    #include "psc3p5edlhq1_s.h"
#elif defined (PSC3P5FDS2LHQ1)
    #include "psc3p5fds2lhq1_s.h"
#elif defined (PSC3P5EDABQ1)
    #include "psc3p5edabq1_s.h"
#elif defined (PSC3P5FDS2ABQ1)
    #include "psc3p5fds2abq1_s.h"
#elif defined (PSC3P2EDLGQ1)
    #include "psc3p2edlgq1_s.h"
#elif defined (PSC3P2FDS2LGQ1)
    #include "psc3p2fds2lgq1_s.h"
#elif defined (PSC3M3EDLGQ1)
    #include "psc3m3edlgq1_s.h"
#elif defined (PSC3M3FDS2LGQ1)
    #include "psc3m3fds2lgq1_s.h"
#elif defined (PSC3P2EDACQ1)
    #include "psc3p2edacq1_s.h"
#elif defined (PSC3P2FDS2ACQ1)
    #include "psc3p2fds2acq1_s.h"
#elif defined (PSC3M3EDACQ1)
    #include "psc3m3edacq1_s.h"
#elif defined (PSC3M3FDS2ACQ1)
    #include "psc3m3fds2acq1_s.h"
#elif defined (PSC3P2EDLHQ1)
    #include "psc3p2edlhq1_s.h"
#elif defined (PSC3P2FDS2LHQ1)
    #include "psc3p2fds2lhq1_s.h"
#elif defined (PSC3M3EDLHQ1)
    #include "psc3m3edlhq1_s.h"
#elif defined (PSC3M3FDS2LHQ1)
    #include "psc3m3fds2lhq1_s.h"
#elif defined (PSC3P2EDABQ1)
    #include "psc3p2edabq1_s.h"
#elif defined (PSC3P2FDS2ABQ1)
    #include "psc3p2fds2abq1_s.h"
#elif defined (PSC3M3EDABQ1)
    #include "psc3m3edabq1_s.h"
#elif defined (PSC3M3FDS2ABQ1)
    #include "psc3m3fds2abq1_s.h"
#else
    #error Undefined part number. Consider updating PDL via ModusToolbox Library Manager to resolve the issue.
#endif

#else
#if defined (CYW20829B0LKML)
    #include "cyw20829b0lkml.h"
#elif defined (CYW89829B0022)
    #include "cyw89829b0022.h"
#elif defined (CYW89829B0232)
    #include "cyw89829b0232.h"
#elif defined (CYW20829B0000)
    #include "cyw20829b0000.h"
#elif defined (CYW20829B0010)
    #include "cyw20829b0010.h"
#elif defined (CYW20829B0021)
    #include "cyw20829b0021.h"
#elif defined (CYW20829B1240)
    #include "cyw20829b1240.h"
#elif defined (CYW20829B1340)
    #include "cyw20829b1340.h"
#elif defined (PSC3M5FDS2AFQ1)
    #include "psc3m5fds2afq1.h"
#elif defined (PSC3M5FDS2LGQ1)
    #include "psc3m5fds2lgq1.h"
#elif defined (PSC3M5FDS2ACQ1)
    #include "psc3m5fds2acq1.h"
#elif defined (PSC3M5FDS2LHQ1)
    #include "psc3m5fds2lhq1.h"
#elif defined (PSC3M5FDS2ABQ1)
    #include "psc3m5fds2abq1.h"
#elif defined (PSC3M5EDAFQ1)
    #include "psc3m5edafq1.h"
#elif defined (PSC3M5EDLGQ1)
    #include "psc3m5edlgq1.h"
#elif defined (PSC3M5EDACQ1)
    #include "psc3m5edacq1.h"
#elif defined (PSC3M5EDLHQ1)
    #include "psc3m5edlhq1.h"
#elif defined (PSC3M5EDABQ1)
    #include "psc3m5edabq1.h"
#elif defined (PSC3P5EDLGQ1)
    #include "psc3p5edlgq1.h"
#elif defined (PSC3P5FDS2LGQ1)
    #include "psc3p5fds2lgq1.h"
#elif defined (PSC3P5EDACQ1)
    #include "psc3p5edacq1.h"
#elif defined (PSC3P5FDS2ACQ1)
    #include "psc3p5fds2acq1.h"
#elif defined (PSC3P5EDLHQ1)
    #include "psc3p5edlhq1.h"
#elif defined (PSC3P5FDS2LHQ1)
    #include "psc3p5fds2lhq1.h"
#elif defined (PSC3P5EDABQ1)
    #include "psc3p5edabq1.h"
#elif defined (PSC3P5FDS2ABQ1)
    #include "psc3p5fds2abq1.h"
#elif defined (PSC3P2EDLGQ1)
    #include "psc3p2edlgq1.h"
#elif defined (PSC3P2FDS2LGQ1)
    #include "psc3p2fds2lgq1.h"
#elif defined (PSC3M3EDLGQ1)
    #include "psc3m3edlgq1.h"
#elif defined (PSC3M3FDS2LGQ1)
    #include "psc3m3fds2lgq1.h"
#elif defined (PSC3P2EDACQ1)
    #include "psc3p2edacq1.h"
#elif defined (PSC3P2FDS2ACQ1)
    #include "psc3p2fds2acq1.h"
#elif defined (PSC3M3EDACQ1)
    #include "psc3m3edacq1.h"
#elif defined (PSC3M3FDS2ACQ1)
    #include "psc3m3fds2acq1.h"
#elif defined (PSC3P2EDLHQ1)
    #include "psc3p2edlhq1.h"
#elif defined (PSC3P2FDS2LHQ1)
    #include "psc3p2fds2lhq1.h"
#elif defined (PSC3M3EDLHQ1)
    #include "psc3m3edlhq1.h"
#elif defined (PSC3M3FDS2LHQ1)
    #include "psc3m3fds2lhq1.h"
#elif defined (PSC3P2EDABQ1)
    #include "psc3p2edabq1.h"
#elif defined (PSC3P2FDS2ABQ1)
    #include "psc3p2fds2abq1.h"
#elif defined (PSC3M3EDABQ1)
    #include "psc3m3edabq1.h"
#elif defined (PSC3M3FDS2ABQ1)
    #include "psc3m3fds2abq1.h"
#else
    #error Undefined part number. Consider updating PDL via ModusToolbox Library Manager to resolve the issue.
#endif

#endif

#endif /* _CY_DEVICE_HEADERS_H_ */


/* [] END OF FILE */
