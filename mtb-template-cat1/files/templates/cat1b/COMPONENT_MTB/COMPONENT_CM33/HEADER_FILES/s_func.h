/***************************************************************************//**
* \file s_func.h
* \version 1.1
*
* \brief Header file for non-secure callable functions
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation
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


#ifndef S_FUNC_H_
#define S_FUNC_H_

cy_en_flashdrv_status_t secure_Flash_Init(bool refresh_enable);
cy_en_flashdrv_status_t secure_Flash_Erase_Row(uint32_t rowAddr);
cy_en_flashdrv_status_t secure_Flash_Write_Row(uint32_t rowAddr, const uint32_t* data);

#endif /* S_FUNC_H_ */
