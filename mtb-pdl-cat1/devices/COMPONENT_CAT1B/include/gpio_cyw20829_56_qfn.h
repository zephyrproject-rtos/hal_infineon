/***************************************************************************//**
* \file gpio_cyw20829_56_qfn.h
*
* \brief
* CYW20829 device GPIO header inclusion for 56-QFN package
*
********************************************************************************
* \copyright
* (c) (2016-2022), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _GPIO_CYW20829_56_QFN_H_
#define _GPIO_CYW20829_56_QFN_H_

#if defined(CYW20829A0LKML) || defined(CYW20829A0KML) || defined(CYW89829A0KML)
   #include "gpio_cyw20829a0_56_qfn.h"
#else 
   #include "gpio_cyw20829b0_56_qfn.h"
#endif

#endif /* _GPIO_CYW20829_56_QFN_H_ */
