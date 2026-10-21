/*******************************************************************************
 * File Name: ifx_tfm_image_config.h
 * This file was automatically generated and should not be modified.
 *
 *******************************************************************************
 * Copyright 2026 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
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
 ******************************************************************************/

#if !defined(IFX_TFM_IMAGE_CONFIG_H)
#define IFX_TFM_IMAGE_CONFIG_H

// Allows execution of TF-M image from different memory areas
#define IFX_TFM_IMAGE_EXECUTE_REGION_NAME     m33s_nvm

#define IFX_TFM_IMAGE_EXECUTE_OFFSET          CYMEM_CM33_0_S_m33s_nvm_OFFSET
#define IFX_TFM_IMAGE_EXECUTE_ADDR            CYMEM_CM33_0_S_m33s_nvm_C_S_START
#define IFX_TFM_IMAGE_EXECUTE_SIZE            CYMEM_CM33_0_S_m33s_nvm_SIZE
#define IFX_TFM_IMAGE_EXECUTE_LOCATION        CYMEM_CM33_0_S_m33s_nvm_LOCATION

#endif /* IFX_TFM_IMAGE_CONFIG_H */
