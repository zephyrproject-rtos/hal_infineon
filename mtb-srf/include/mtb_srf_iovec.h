/*******************************************************************************
* \file mtb_srf_iovec.h
*
* \brief
* Defines data types that are placed in SRF input/output vectors
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
#pragma once

#if defined(MTB_SRF_USE_PSA)
#include "psa/client.h"
#endif

#include "cy_result.h"
#include "cy_utils.h"

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

/*******************************************************************************
*                          Data Structures
*******************************************************************************/
/**
 * \addtogroup group_mtb_srf_structures Data Structures
 * \{
 */

/** Secure request description structure.  A non-secure application invokes an operation by
   submitting a secure request description that contains all information about the requested
   operation.
 */
typedef struct
{
    uint8_t                 module_id;          //!< ID of the module containing the requested
                                                //!< operation
    uint8_t                 submodule_id;       //!< ID of the submodule containing within the
                                                //!< module
    uint8_t                 op_id;              //!< ID of the requested operation within the
                                                //!< submodule
    void*                   base;               //!< Register base address for the operation
    uint32_t                sub_block;          //!< Sub-block index for this operation
} mtb_srf_request_ns_t;

#if defined(MTB_SRF_USE_PSA)
#define MTB_SRF_MAX_IOVEC (PSA_MAX_IOVEC)
typedef psa_invec      mtb_srf_invec_ns_t;
typedef psa_outvec     mtb_srf_outvec_ns_t;
#else
/** Max number of vectors that can be provided to \ref mtb_srf_request_submit */
#if !defined(MTB_SRF_MAX_IOVEC)
#define MTB_SRF_MAX_IOVEC (4U)
#endif

/** An input vector - a section of memory to be used along with the length */
typedef struct
{
    const void*             base;               //!< Start address of the memory buffer
    size_t                  len;                //!< Size of memory buffer in bytes
} mtb_srf_invec_ns_t;

/** An output vector - a section of memory to be used along with the length */
typedef struct
{
    void*                   base;               //!< Start address of the memory buffer */
    size_t                  len;                //!< Size of memory buffer in bytes */
} mtb_srf_outvec_ns_t;
#endif // defined(MTB_SRF_USE_PSA)

/** An input structure.  This includes a request and an array for non-pointer input arguments.
 * This is always the first element of the inVec array passed to \ref mtb_srf_request_submit
 */
typedef struct
{
    mtb_srf_request_ns_t    request;            //!< Request information
    size_t                  len;                //!< Size of the input_values array
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 18.7', 1,
                                 'Flexibly sized array is statically allocated by the users of this library')
    uint8_t                 input_values[];     //!< Flexible size array for non-pointer input
                                                //!< arguments
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 18.7')
} mtb_srf_input_ns_t;

/** An input structure.  This includes the operation result and an array for non-pointer output
 * arguments. This is always the first element of the outVec array passed to \ref
 * mtb_srf_request_submit
 */
typedef struct
{
    cy_rslt_t               result;             //!< Result of the operation
    size_t                  len;                //!< Size of the output_values array
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 18.7', 1,
                                 'Flexibly sized array is statically allocated by the users of this library')
    uint8_t                 output_values[];    //!< Flexible size array for non-pointer output
                                                //!< arguments
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 18.7')
} mtb_srf_output_ns_t;

/** \} group_mtb_srf_structures */

#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */
