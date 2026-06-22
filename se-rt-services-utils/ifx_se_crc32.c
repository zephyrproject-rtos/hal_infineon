/***************************************************************************//**
* \file ifx_se_crc32.c
* \version 1.4.1
*
* \brief
* Fast high-distance 32-bit CRC for data integrity protection.
*
********************************************************************************
* \copyright
* Copyright (c) 2022-2026, Infineon Technologies AG, or an affiliate of
* Infineon Technologies AG. All rights reserved.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
******************************************************************************/

#include "ifx_se_crc32.h"

void ifx_se_crc32d6_open(uint32_t *P, uint32_t init)
{
    *P = init;
}

uint32_t ifx_se_crc32d6_close(uint32_t const *P)
{
    return *P; /* digest is identical to last state */
}

void ifx_se_crc32d6a_update(uint32_t *P, uint8_t Q)
{
    uint32_t A = (*P >> (IFX_CRC32_CRC_WIDTH - IFX_CRC32_BYTE_WIDTH)) ^ Q;
    uint32_t B = (A << 18u) ^ (A << 17u) ^ (A << 15u) ^ (A << 14u) ^ A;

    *P = B ^ (*P << IFX_CRC32_BYTE_WIDTH);
}

uint32_t ifx_se_crc32d6a(size_t n, uint8_t const *Q, uint32_t init)
{
    uint32_t P;

    ifx_se_crc32d6_open(&P, init);

    for (size_t i = 0; i < n; ++i)
    {
        ifx_se_crc32d6a_update(&P, Q[i]);
    }

    return ifx_se_crc32d6_close(&P);
}

void ifx_se_crc32d6b_update(uint32_t *P, uint16_t Q)
{
    const uint32_t T[4] = { 0x00000000uL, 0x8006C001uL, 0x000B4003uL, 0x800D8002uL };

    uint32_t A = (*P >> (IFX_CRC32_CRC_WIDTH - IFX_CRC32_WORD_WIDTH)) ^ Q;
    uint32_t A1 = A >> 14u;
    uint32_t A2 = A & 0x3FFFuL;
    uint32_t B = T[A1] ^ (A2 << 18u) ^ (A2 << 17u) ^ (A << 15u) ^ (A << 14u) ^ A;

    *P = B ^ (*P << IFX_CRC32_WORD_WIDTH);
}

uint32_t ifx_se_crc32d6b(size_t n, uint16_t const *Q, uint32_t init)
{
    uint32_t P;

    ifx_se_crc32d6_open(&P, init);

    for (size_t i = 0; i < n; ++i)
    {
        ifx_se_crc32d6b_update(&P, Q[i]);
    }

    return ifx_se_crc32d6_close(&P);
}

