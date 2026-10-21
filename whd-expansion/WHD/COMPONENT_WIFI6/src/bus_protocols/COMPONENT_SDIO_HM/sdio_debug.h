/*
 * Copyright 2024, Cypress Semiconductor Corporation (an Infineon company)
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
 */

#ifndef _SDIO_DEBUG_H_
#define _SDIO_DEBUG_H_

#if defined(COMPONENT_SDIO_HM)

//==================================================================================================
// Types and constants
//==================================================================================================

/* Enabling Info and Error msgs by default */
#define ENABLE_SDIO_HM_DBG
#define ENABLE_SDIO_HM_ERROR
/* #define ENABLE_SDIO_HM_DEBUG */
#define ENABLE_SDIO_HM_HEX

/* message levels */
#define SDIO_LV_INFO    0x00000001
#define SDIO_LV_HEX     0x00000002
#define SDIO_LV_TX      0x00000004
#define SDIO_LV_RX      0x00000008
#define SDIO_LV_CMD     0x00000010
#define SDIO_LV_EVENT   0x00000020

/* DEBUG related Macros */
#define PRINT_MACRO(args) do { printf args; } while (0 == 1)

extern uint32_t msg_level;

#ifdef ENABLE_SDIO_HM_DBG
#define HM_INFO_MSG(args) if (msg_level & SDIO_LV_INFO) PRINT_MACRO(args)
#define HM_TX_MSG(args) if (msg_level & SDIO_LV_TX) PRINT_MACRO(args)
#define HM_RX_MSG(args) if (msg_level & SDIO_LV_RX) PRINT_MACRO(args)
#define HM_CMD_MSG(args) if (msg_level & SDIO_LV_CMD) PRINT_MACRO(args)
#define HM_EVENT_MSG(args) if (msg_level & SDIO_LV_EVENT) PRINT_MACRO(args)
#else
#define HM_INFO_MSG(args)
#define HM_TX_MSG(args)
#define HM_RX_MSG(args)
#define HM_CMD_MSG(args)
#define HM_EVENT_MSG(args)
#endif

#ifdef ENABLE_SDIO_HM_DEBUG
#define PRINT_HM_DEBUG(args) PRINT_MACRO(args)
#else
#define PRINT_HM_DEBUG(args)
#endif

#ifdef ENABLE_SDIO_HM_ERROR
#define PRINT_HM_ERROR(args) PRINT_MACRO(args)
#else
#define PRINT_HM_ERROR(args)
#endif

#ifdef ENABLE_SDIO_HM_HEX
#define HM_HEX_DUMP(args, data, data_len) \
    if (msg_level & SDIO_LV_HEX) { \
        { \
            uint16_t i, j; \
            PRINT_MACRO((args)); \
            for (i = 0; i < data_len; i += 16) { \
                PRINT_MACRO(("%08x:", i)); \
                for (j = i; (j < data_len && j < (i + 16)); j++) { \
                    PRINT_MACRO((" %02x", *((uint8_t *)data + j))); \
                } \
                PRINT_MACRO(("\n")); \
            } \
        } \
    } \

#define HM_TX_HEX_DUMP(args, data, data_len) \
    if (msg_level & SDIO_LV_TX) HM_HEX_DUMP(args, data, data_len)
#define HM_RX_HEX_DUMP(args, data, data_len) \
    if (msg_level & SDIO_LV_RX) HM_HEX_DUMP(args, data, data_len)
#define HM_CMD_HEX_DUMP(args, data, data_len) \
    if (msg_level & SDIO_LV_CMD) HM_HEX_DUMP(args, data, data_len)

#else
#define HM_TX_HEX_DUMP(args, data, data_len)
#define HM_RX_HEX_DUMP(args, data, data_len)
#define HM_CMD_HEX_DUMP(args, data, data_len)
#endif

#define CHK_RET(expr)  { \
        cy_rslt_t check_res = (expr); \
        if (check_res != CY_RSLT_SUCCESS) \
        { \
            PRINT_HM_ERROR(("Function %s failed at line %d type 0x%lx module 0x%lx submodule 0x%lx code 0x%lx\n", \
                __func__, __LINE__, \
                (check_res >> CY_RSLT_TYPE_POSITION) & CY_RSLT_TYPE_MASK, \
                (check_res >> CY_RSLT_MODULE_POSITION) & CY_RSLT_MODULE_MASK, \
                (check_res >> CY_RSLT_SUBMODULE_POSITION) & CY_RSLT_SUBMODULE_MASK, \
                (check_res >> CY_RSLT_CODE_POSITION) & CY_RSLT_CODE_MASK)); \
            return check_res; \
        } \
}

#endif /* COMPONENT_SDIO_HM */

#endif /* _SDIO_DEBUG_H_ */
