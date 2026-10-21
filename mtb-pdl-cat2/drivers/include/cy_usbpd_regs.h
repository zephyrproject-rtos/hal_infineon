/***************************************************************************//**
* \file cy_usbpd_regs.h
* \version 2.110
*
* Generic device specific USBPD register header definition.
*
********************************************************************************
* \copyright
* (c) (2022 - 2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _CY_USBPD_REGS_H_
#define _CY_USBPD_REGS_H_

#include "cy_device_headers.h"

#if defined (CY_DEVICE_CCG3)
#include "cy_usbpd_pmg1s2_regs.h"

#elif defined(CY_DEVICE_CCG3PA)
#include "cy_usbpd_pmg1s0_regs.h"    

#elif defined(CY_DEVICE_CCG6)
#include "cy_usbpd_pmg1s1_regs.h"

#elif defined(CY_DEVICE_PMG1S3)
#include "cy_usbpd_pmg1s3_regs.h"

#elif defined(CY_DEVICE_CCG6DF_CFP)
#include "cy_usbpd_ccg6dfcfp_regs.h"

#elif defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1)
#include "cy_usbpd_ccg7d_regs.h"

#elif defined(CY_DEVICE_CCG7S) 
#include "cy_usbpd_ccg7s_regs.h"

#else
/* Do nothing */
#endif

#endif /* _CY_USBPD_REGS_H_ */

/*[] END OF FILE */
