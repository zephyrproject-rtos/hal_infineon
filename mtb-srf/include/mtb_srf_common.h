/*******************************************************************************
* \file mtb_srf_common.h
*
* \brief
* Provides private helpers for the SRF implementation
*
*******************************************************************************
* \copyright
* (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
* Technologies AG.
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

// This function is only needed on the non-secure side, and its implementation depends
// on HAL headers. To avoid unnecessary compilation dependencies, do not include it
// when building for the secure world. This can be relaxed in the future
// if there is a need to call this function on the secure world, but there are no known
// situations in which the secure world SRF should be busy-waiting.
#ifdef COMPONENT_NON_SECURE_DEVICE
/**
 * \cond INTERNAL
 * Waits for the specified interval. Also decrements the timeout unless it is "never timeout"
 *
 * @param[in,out] timeout_us timeout in microseconds. To wait forever, use MTB_SRF_NEVER_TIMEOUT.
 *                           Updated with the remaining time to wait
 * @param[in]     interval_us The amount of time to delay before returning
 */
void _mtb_srf_wait(uint32_t* timeout_us, uint32_t interval_us);

/** \endcond */
#endif /* COMPONENT_NON_SECURE_DEVICE */
