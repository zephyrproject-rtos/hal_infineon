/***************************************************************************//**
* \file cyip_pd.h
*
* \brief
* PD IP definitions
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

#ifndef _CYIP_PD_H_
#define _CYIP_PD_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                      PD
*******************************************************************************/

#define PD_SECTION_SIZE                         0x00000400UL

/**
  * \brief Power Domain and Switch Block (PD)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Power Domain Control */
   __IM uint32_t RESERVED[3];
   __IM uint32_t STATUS;                        /*!< 0x00000010 Power Domain Status */
   __IM uint32_t RESERVED1[27];
  __IOM uint32_t TRIM;                          /*!< 0x00000080 Power Switch Trim */
} PD_Type;                                      /*!< Size = 132 (0x84) */


/* PD.CTL */
#define PD_CTL_PWR_MODE_Pos                     0UL
#define PD_CTL_PWR_MODE_Msk                     0x3UL
/* PD.STATUS */
#define PD_STATUS_PWR_DONE_Pos                  4UL
#define PD_STATUS_PWR_DONE_Msk                  0x10UL
/* PD.TRIM */
#define PD_TRIM_PWRSW_WAIT_CNT_Pos              0UL
#define PD_TRIM_PWRSW_WAIT_CNT_Msk              0x3UL


#endif /* _CYIP_PD_H_ */


/* [] END OF FILE */
