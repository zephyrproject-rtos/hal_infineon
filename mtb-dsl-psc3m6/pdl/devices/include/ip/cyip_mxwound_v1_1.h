/***************************************************************************//**
* MXWOUND IP definitions
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

#ifndef _CYIP_MXWOUND_V1_1_H_
#define _CYIP_MXWOUND_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                   MXWOUND
*******************************************************************************/

#define MXWOUND_MXWOUND_PROP_SECTION_SIZE       0x00000040UL
#define MXWOUND_SECTION_SIZE                    0x00001000UL

/**
  * \brief 0 (MXWOUND_MXWOUND_PROP)
  */
typedef struct {
  __IOM uint32_t PROP;                          /*!< 0x00000000 Property value register */
   __IM uint32_t RESERVED[15];
} MXWOUND_MXWOUND_PROP_Type;                    /*!< Size = 64 (0x40) */

/**
  * \brief 0 (MXWOUND)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 MXWOUND Control Reg */
   __IM uint32_t RESERVED[63];
        MXWOUND_MXWOUND_PROP_Type MXWOUND_PROP[8]; /*!< 0x00000100 0 */
} MXWOUND_Type;                                 /*!< Size = 768 (0x300) */


/* MXWOUND_MXWOUND_PROP.PROP */
#define MXWOUND_MXWOUND_PROP_PROP_PROP_Pos      0UL
#define MXWOUND_MXWOUND_PROP_PROP_PROP_Msk      0xFFFFFFFFUL


/* MXWOUND.CTL */
#define MXWOUND_CTL_ENABLED_Pos                 31UL
#define MXWOUND_CTL_ENABLED_Msk                 0x80000000UL


#endif /* _CYIP_MXWOUND_V1_1_H_ */


/* [] END OF FILE */
