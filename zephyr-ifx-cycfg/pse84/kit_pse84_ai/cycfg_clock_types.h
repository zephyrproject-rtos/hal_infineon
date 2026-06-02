/*******************************************************************************
 * File Name: cycfg_clock_types.h
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

#if !defined(CYCFG_CLOCK_TYPES_H)
#define CYCFG_CLOCK_TYPES_H

#include "cy_sysclk.h"

/**  HF Clock Configuration  */
typedef struct
{
    /**  HF clock source  */
    cy_en_clkhf_in_sources_t source;
    /**  HF clock divider  */
    cy_en_clkhf_dividers_t divider;
} cycfg_clkhf_config_t;

/**  HF Clock Supervisor Configuration  */
typedef struct
{
    /**  HF Clock Supervisor reference clock  */
    cy_en_clkhf_csv_ref_clk_t refClk;
    /**  HF Clock Supervisor accuracy  */
    uint32_t accuracy;
    /**  HF Clock Supervisor action  */
    cy_en_clkhf_csv_action_t action;
} cycfg_clkhf_csv_config_t;

#endif /* CYCFG_CLOCK_TYPES_H */
