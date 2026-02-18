################################################################################
# \file library.mk
#
# \brief
# Makefile to identify the presence of MTB_HAL
#
################################################################################
# \copyright
# Copyright (c) 2022-2026 Infineon Technologies AG
# an affiliate of Infineon Technologies AG
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
################################################################################

COMPONENTS+=MTB_HAL

ifneq (,$(filter $(DEVICE_COMPONENTS),PSC3_P8))
ifneq (,$(filter $(DEFINES),CY_PDL_PPCA_BOOT CY_PDL_PPCA_CORE0 CY_PDL_PPCA_CORE1 COMPONENT_PPCA_DEVICE))
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_aes_ccm.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_aes.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_cmac.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_ecc_ec25519.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_ecc_eddsa.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_ecc_key_gen.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_ecdsa.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_hkdf.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_hmac.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_nist_p.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_rsa.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_sha.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_sha256.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_trng.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_utils.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_cryptolite_vu.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_efuse_v3.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_efuse.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_flash.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_lvd.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_mpc.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_ms_ctl.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_ppc.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_svgs.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_sysfault.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_syspm.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/pdl/drivers/source/cy_syspm_pcdm.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/hal/source/mtb_hal_nvm.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/hal/source/mtb_hal_syspm.c
CY_IGNORE+=$(SEARCH_mtb-dsl-psc3m8)/device-utils/syspm
$(info INFO: Skip build for $(CY_IGNORE))
endif
endif
