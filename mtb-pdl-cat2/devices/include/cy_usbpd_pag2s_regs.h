/***************************************************************************//**
* \file cy_usbpd_pag2s_regs.h
* \version 1.0
*
* Cypress product header file.
* This file is auto generated from the register map spreadsheet.
* DO NOT MODIFY THIS FILE.
*
********************************************************************************
* \copyright
* Copyright 2021 Cypress Semiconductor Corporation
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
#ifndef _CY_USBPD_PAG2S_REGS_H_
#define _CY_USBPD_PAG2S_REGS_H_

#include <stdint.h>
#include <stdbool.h>

/** \cond DOXYGEN_HIDE */

#define PDSS_BASE_ADDR                                   (0x400a0000UL)

typedef struct {
    volatile uint32_t ctrl;                               /* 0x400a0000UL */
    volatile uint32_t header_info;                        /* 0x400a0004UL */
    volatile uint32_t rsrvd0;
    volatile uint32_t tx_header;                          /* 0x400a000cUL */
    volatile uint32_t tx_mem_data[16];                    /* 0x400a0010UL */
    volatile uint32_t rsrvd1[3];
    volatile uint32_t rx_header;                          /* 0x400a005cUL */
    volatile uint32_t rx_mem_data[16];                    /* 0x400a0060UL */
    volatile uint32_t sram_ptr;                           /* 0x400a00a0UL */
    volatile uint32_t status;                             /* 0x400a00a4UL */
    volatile uint32_t rx_sop_good_crc_en_ctrl;            /* 0x400a00a8UL */
    volatile uint32_t rx_expect_goodcrc_msg;              /* 0x400a00acUL */
    volatile uint32_t rx_goodcrc_msg;                     /* 0x400a00b0UL */
    volatile uint32_t rx_cc_0_cfg;                        /* 0x400a00b4UL */
    volatile uint32_t rx_cc_1_cfg;                        /* 0x400a00b8UL */
    volatile uint32_t rx_order_set_ctrl;                  /* 0x400a00bcUL */
    volatile uint32_t tx_goodcrc_msg_order_set;           /* 0x400a00c0UL */
    volatile uint32_t tx_ctrl;                            /* 0x400a00c4UL */
    volatile uint32_t tx_sop_order_set;                   /* 0x400a00c8UL */
    volatile uint32_t tx_hard_cable_order_set;            /* 0x400a00ccUL */
    volatile uint32_t crc_counter;                        /* 0x400a00d0UL */
    volatile uint32_t inter_packet_counter;               /* 0x400a00d4UL */
    volatile uint32_t timer_trigger;                      /* 0x400a00d8UL */
    volatile uint32_t debug_ctrl;                         /* 0x400a00dcUL */
    volatile uint32_t debug_cc_0;                         /* 0x400a00e0UL */
    volatile uint32_t debug_cc_1;                         /* 0x400a00e4UL */
    volatile uint32_t debug_cc_2;                         /* 0x400a00e8UL */
    volatile uint32_t rsrvd2[15];
    volatile uint32_t bit_en_cntr_ctrl;                   /* 0x400a0128UL */
    volatile uint32_t rp_rd_cfg1;                         /* 0x400a012cUL */
    volatile uint32_t rp_rd_cfg2;                         /* 0x400a0130UL */
    volatile uint32_t lf_cntr;                            /* 0x400a0134UL */
    volatile uint32_t lf_cntr_match;                      /* 0x400a0138UL */
    volatile uint32_t rsrvd3;
    volatile uint32_t afc_1_ctrl;                         /* 0x400a0140UL */
    volatile uint32_t rsrvd4[3];
    volatile uint32_t afc_2_ctrl;                         /* 0x400a0150UL */
    volatile uint32_t rsrvd5[3];
    volatile uint32_t afc_opcode_ctrl;                    /* 0x400a0160UL */
    volatile uint32_t rsrvd6[3];
    volatile uint32_t afc_ping_pong;                      /* 0x400a0170UL */
    volatile uint32_t rsrvd7[3];
    volatile uint32_t qc3_chrger_ctrl;                    /* 0x400a0180UL */
    volatile uint32_t rsrvd8[3];
    volatile uint32_t qc3_device_ctrl;                    /* 0x400a0190UL */
    volatile uint32_t rsrvd9[3];
    volatile uint32_t afc_sm_status;                      /* 0x400a01a0UL */
    volatile uint32_t rsrvd10[3];
    volatile uint32_t afc_hs_filter_cfg;                  /* 0x400a01b0UL */
    volatile uint32_t rsrvd11[3];
    volatile uint32_t adc_sar_ctrl;                       /* 0x400a01c0UL */
    volatile uint32_t rsrvd12[7];
    volatile uint32_t refgen_sel6_sel8_ctrl;              /* 0x400a01e0UL */
    volatile uint32_t rsrvd13[19];
    volatile uint32_t vconn20_cc1_switch_1_ctrl;          /* 0x400a0230UL */
    volatile uint32_t vconn20_cc1_switch_2_ctrl;          /* 0x400a0234UL */
    volatile uint32_t vconn20_cc2_switch_1_ctrl;          /* 0x400a0238UL */
    volatile uint32_t vconn20_cc2_switch_2_ctrl;          /* 0x400a023cUL */
    volatile uint32_t vconn20_pump_en_1_ctrl;             /* 0x400a0240UL */
    volatile uint32_t vconn20_pump_en_2_ctrl;             /* 0x400a0244UL */
    volatile uint32_t rsrvd14[22];
    volatile uint32_t intr1_cfg;                          /* 0x400a02a0UL */
    volatile uint32_t intr1_cfg_cc1_cc2_ls;               /* 0x400a02a4UL */
    volatile uint32_t intr1_cfg_vcmp_up_down_ls;          /* 0x400a02a8UL */
    volatile uint32_t rsrvd15;
    volatile uint32_t intr1_cfg_cc12_ovp_hs;              /* 0x400a02b0UL */
    volatile uint32_t intr1_status;                       /* 0x400a02b4UL */
    volatile uint32_t intr1;                              /* 0x400a02b8UL */
    volatile uint32_t intr1_set;                          /* 0x400a02bcUL */
    volatile uint32_t intr1_mask;                         /* 0x400a02c0UL */
    volatile uint32_t intr1_masked;                       /* 0x400a02c4UL */
    volatile uint32_t rsrvd16[15];
    volatile uint32_t intr3_cfg_adc_hs;                   /* 0x400a0304UL */
    volatile uint32_t rsrvd17[14];
    volatile uint32_t intr3_status_0;                     /* 0x400a0340UL */
    volatile uint32_t rsrvd18;
    volatile uint32_t intr3;                              /* 0x400a0348UL */
    volatile uint32_t intr3_set;                          /* 0x400a034cUL */
    volatile uint32_t intr3_mask;                         /* 0x400a0350UL */
    volatile uint32_t intr3_masked;                       /* 0x400a0354UL */
    volatile uint32_t rsrvd19[10];
    volatile uint32_t intr5_filter_cfg[5];                /* 0x400a0380UL */
    volatile uint32_t rsrvd20[19];
    volatile uint32_t intr5_status_0;                     /* 0x400a03e0UL */
    volatile uint32_t rsrvd21;
    volatile uint32_t intr5;                              /* 0x400a03e8UL */
    volatile uint32_t intr5_set;                          /* 0x400a03ecUL */
    volatile uint32_t intr5_mask;                         /* 0x400a03f0UL */
    volatile uint32_t intr5_masked;                       /* 0x400a03f4UL */
    volatile uint32_t rsrvd22[10];
    volatile uint32_t intr7_filter_cfg[2];                /* 0x400a0420UL */
    volatile uint32_t rsrvd23[6];
    volatile uint32_t intr7_status;                       /* 0x400a0440UL */
    volatile uint32_t intr7;                              /* 0x400a0444UL */
    volatile uint32_t intr7_set;                          /* 0x400a0448UL */
    volatile uint32_t intr7_mask;                         /* 0x400a044cUL */
    volatile uint32_t intr7_masked;                       /* 0x400a0450UL */
    volatile uint32_t rsrvd24[7];
    volatile uint32_t intr9_cfg_bch_det[1];               /* 0x400a0470UL */
    volatile uint32_t rsrvd25[6];
    volatile uint32_t intr9_status_0;                     /* 0x400a048cUL */
    volatile uint32_t intr9_status_1;                     /* 0x400a0490UL */
    volatile uint32_t intr9;                              /* 0x400a0494UL */
    volatile uint32_t intr9_set;                          /* 0x400a0498UL */
    volatile uint32_t intr9_mask;                         /* 0x400a049cUL */
    volatile uint32_t intr9_masked;                       /* 0x400a04a0UL */
    volatile uint32_t rsrvd26[7];
    volatile uint32_t intr11_filter_cfg;                  /* 0x400a04c0UL */
    volatile uint32_t intr11_status_0;                    /* 0x400a04c4UL */
    volatile uint32_t intr11;                             /* 0x400a04c8UL */
    volatile uint32_t intr11_set;                         /* 0x400a04ccUL */
    volatile uint32_t intr11_mask;                        /* 0x400a04d0UL */
    volatile uint32_t intr11_masked;                      /* 0x400a04d4UL */
    volatile uint32_t rsrvd27;
    volatile uint32_t intr13_status;                      /* 0x400a04dcUL */
    volatile uint32_t intr13;                             /* 0x400a04e0UL */
    volatile uint32_t intr13_set;                         /* 0x400a04e4UL */
    volatile uint32_t intr13_mask;                        /* 0x400a04e8UL */
    volatile uint32_t intr13_masked;                      /* 0x400a04ecUL */
    volatile uint32_t intr13_cfg_csa_scp_hs;              /* 0x400a04f0UL */
    volatile uint32_t rsrvd28[3];
    volatile uint32_t intr0;                              /* 0x400a0500UL */
    volatile uint32_t intr0_set;                          /* 0x400a0504UL */
    volatile uint32_t intr0_mask;                         /* 0x400a0508UL */
    volatile uint32_t intr0_masked;                       /* 0x400a050cUL */
    volatile uint32_t intr2;                              /* 0x400a0510UL */
    volatile uint32_t intr2_set;                          /* 0x400a0514UL */
    volatile uint32_t intr2_mask;                         /* 0x400a0518UL */
    volatile uint32_t intr2_masked;                       /* 0x400a051cUL */
    volatile uint32_t intr4;                              /* 0x400a0520UL */
    volatile uint32_t intr4_set;                          /* 0x400a0524UL */
    volatile uint32_t intr4_mask;                         /* 0x400a0528UL */
    volatile uint32_t intr4_masked;                       /* 0x400a052cUL */
    volatile uint32_t intr6;                              /* 0x400a0530UL */
    volatile uint32_t intr6_set;                          /* 0x400a0534UL */
    volatile uint32_t intr6_mask;                         /* 0x400a0538UL */
    volatile uint32_t intr6_masked;                       /* 0x400a053cUL */
    volatile uint32_t intr8;                              /* 0x400a0540UL */
    volatile uint32_t intr8_set;                          /* 0x400a0544UL */
    volatile uint32_t intr8_mask;                         /* 0x400a0548UL */
    volatile uint32_t intr8_masked;                       /* 0x400a054cUL */
    volatile uint32_t intr13_cfg_ltrandet;                /* 0x400a0550UL */
    volatile uint32_t rsrvd29[11];
    volatile uint32_t ddft_mux;                           /* 0x400a0580UL */
    volatile uint32_t intr_ddft_mux;                      /* 0x400a0584UL */
    volatile uint32_t ncell_ddft_mux;                     /* 0x400a0588UL */
    volatile uint32_t gpio_ddft_mux;                      /* 0x400a058cUL */
    volatile uint32_t gpio_intr_ddft_mux;                 /* 0x400a0590UL */
    volatile uint32_t rsrvd30;
    volatile uint32_t fault_gpio_ctrl_extr;               /* 0x400a0598UL */
    volatile uint32_t rsrvd31[25];
    volatile uint32_t cc_ctrl_0;                          /* 0x400a0600UL */
    volatile uint32_t cc_ctrl_1;                          /* 0x400a0604UL */
    volatile uint32_t dpslp_ref_ctrl;                     /* 0x400a0608UL */
    volatile uint32_t rsrvd32[4];
    volatile uint32_t vreg_vsys_ctrl;                     /* 0x400a061cUL */
    volatile uint32_t rsrvd33[2];
    volatile uint32_t amux_ctrl;                          /* 0x400a0628UL */
    volatile uint32_t rsrvd34[21];
    volatile uint32_t adc_ctrl;                           /* 0x400a0680UL */
    volatile uint32_t rsrvd35[3];
    volatile uint32_t refgen_0_ctrl;                      /* 0x400a0690UL */
    volatile uint32_t rsrvd36[3];
    volatile uint32_t refgen_1_ctrl;                      /* 0x400a06a0UL */
    volatile uint32_t rsrvd37[3];
    volatile uint32_t refgen_2_ctrl;                      /* 0x400a06b0UL */
    volatile uint32_t rsrvd38[3];
    volatile uint32_t refgen_3_ctrl;                      /* 0x400a06c0UL */
    volatile uint32_t rsrvd39[3];
    volatile uint32_t refgen_4_ctrl;                      /* 0x400a06d0UL */
    volatile uint32_t rsrvd40[11];
    volatile uint32_t bch_det_0_ctrl[1];                  /* 0x400a0700UL */
    volatile uint32_t rsrvd41[3];
    volatile uint32_t bch_det_1_ctrl[1];                  /* 0x400a0710UL */
    volatile uint32_t rsrvd42[31];
    volatile uint32_t dischg_shv_ctrl[2];                 /* 0x400a0790UL */
    volatile uint32_t rsrvd43[14];
    volatile uint32_t comp_ctrl[7];                       /* 0x400a07d0UL */
    volatile uint32_t rsrvd44[32];
    volatile uint32_t pump5v_ctrl;                        /* 0x400a086cUL */
    volatile uint32_t rsrvd45[11];
    volatile uint32_t dischg_shv_1_ctrl[2];               /* 0x400a089cUL */
    volatile uint32_t rsrvd46[10];
    volatile uint32_t amux_nhvn_ctrl;                     /* 0x400a08ccUL */
    volatile uint32_t rsrvd47;
    volatile uint32_t pwm_0_ctrl;                         /* 0x400a08d4UL */
    volatile uint32_t pwm_1_ctrl;                         /* 0x400a08d8UL */
    volatile uint32_t srsns_0_ctrl;                       /* 0x400a08dcUL */
    volatile uint32_t rsrvd48[3];
    volatile uint32_t gdrv_0_ctrl;                        /* 0x400a08ecUL */
    volatile uint32_t gdrv_1_ctrl;                        /* 0x400a08f0UL */
    volatile uint32_t ea_ctrl;                            /* 0x400a08f4UL */
    volatile uint32_t pds_ea_1_ctrl;                      /* 0x400a08f8UL */
    volatile uint32_t pds_ea_2_ctrl;                      /* 0x400a08fcUL */
    volatile uint32_t rsrvd49[2];
    volatile uint32_t gdrv_2_ctrl;                        /* 0x400a0908UL */
    volatile uint32_t vconn40_ctrl;                       /* 0x400a090cUL */
    volatile uint32_t rsrvd50[4];
    volatile uint32_t ngdo30_1_ctrl;                      /* 0x400a0920UL */
    volatile uint32_t ngdo30_2_ctrl;                      /* 0x400a0924UL */
    volatile uint32_t srsns_4_ctrl;                       /* 0x400a0928UL */
    volatile uint32_t srsns_5_ctrl;                       /* 0x400a092cUL */
    volatile uint32_t srsns_6_ctrl;                       /* 0x400a0930UL */
    volatile uint32_t pds_ea_3_ctrl;                      /* 0x400a0934UL */
    volatile uint32_t rsrvd51[2];
    volatile uint32_t bch_det_2_ctrl;                     /* 0x400a0940UL */
    volatile uint32_t rsrvd52[3];
    volatile uint32_t r_amux_ctrl;                        /* 0x400a0950UL */
    volatile uint32_t r_adc_sar_ctrl;                     /* 0x400a0954UL */
    volatile uint32_t r_adc_ctrl;                         /* 0x400a0958UL */
    volatile uint32_t rndrbn_cfg;                         /* 0x400a095cUL */
    volatile uint32_t rndrbn_status;                      /* 0x400a0960UL */
    volatile uint32_t rsrvd53[3];
    volatile uint32_t rndrbn_chan_cfg[4];                 /* 0x400a0970UL */
    volatile uint32_t rsrvd54[4];
    volatile uint32_t rndrbn_chan_status[4];              /* 0x400a0990UL */
    volatile uint32_t rsrvd55[1432];
    volatile uint32_t ngdo_1_cfg;                         /* 0x400a2000UL */
    volatile uint32_t ngdo_2_cfg;                         /* 0x400a2004UL */
    volatile uint32_t srsns_1_cfg;                        /* 0x400a2008UL */
    volatile uint32_t srsns_2_cfg;                        /* 0x400a200cUL */
    volatile uint32_t rsrvd56[2];
    volatile uint32_t intr15_cfg_1_srsense;               /* 0x400a2018UL */
    volatile uint32_t rsrvd57[2];
    volatile uint32_t intr15_cfg_4_srsense;               /* 0x400a2024UL */
    volatile uint32_t intr15_cfg_0_pwm;                   /* 0x400a2028UL */
    volatile uint32_t intr15_cfg_1_pwm;                   /* 0x400a202cUL */
    volatile uint32_t intr15_cfg_cc_flag;                 /* 0x400a2030UL */
    volatile uint32_t rsrvd58;
    volatile uint32_t intr15_status;                      /* 0x400a2038UL */
    volatile uint32_t intr15;                             /* 0x400a203cUL */
    volatile uint32_t intr15_set;                         /* 0x400a2040UL */
    volatile uint32_t intr15_mask;                        /* 0x400a2044UL */
    volatile uint32_t intr15_masked;                      /* 0x400a2048UL */
    volatile uint32_t vbtr_cfg;                           /* 0x400a204cUL */
    volatile uint32_t vbtr_ctrl;                          /* 0x400a2050UL */
    volatile uint32_t vbtr_src_snk_opr_value;             /* 0x400a2054UL */
    volatile uint32_t vbtr_src_init_fin_value;            /* 0x400a2058UL */
    volatile uint32_t vbtr_snk_init_fin_value;            /* 0x400a205cUL */
    volatile uint32_t vbtr_status;                        /* 0x400a2060UL */
    volatile uint32_t pasc_ctrl;                          /* 0x400a2064UL */
    volatile uint32_t srgdrv_0_ctrl;                      /* 0x400a2068UL */
    volatile uint32_t srgdrv_1_ctrl;                      /* 0x400a206cUL */
    volatile uint32_t pasc_pwm_0_ctrl;                    /* 0x400a2070UL */
    volatile uint32_t pasc_pwm_1_ctrl;                    /* 0x400a2074UL */
    volatile uint32_t pasc_pwm_2_ctrl;                    /* 0x400a2078UL */
    volatile uint32_t mode_0_ctrl;                        /* 0x400a207cUL */
    volatile uint32_t mode_1_ctrl;                        /* 0x400a2080UL */
    volatile uint32_t mode_2_ctrl;                        /* 0x400a2084UL */
    volatile uint32_t mode_3_ctrl;                        /* 0x400a2088UL */
    volatile uint32_t mode_4_ctrl;                        /* 0x400a208cUL */
    volatile uint32_t peakgen_0_ctrl;                     /* 0x400a2090UL */
    volatile uint32_t peakgen_1_ctrl;                     /* 0x400a2094UL */
    volatile uint32_t peakgen_2_ctrl;                     /* 0x400a2098UL */
    volatile uint32_t feedfwd_ctrl;                       /* 0x400a209cUL */
    volatile uint32_t hip_seq_gen_0_ctrl;                 /* 0x400a20a0UL */
    volatile uint32_t hip_seq_gen_1_ctrl;                 /* 0x400a20a4UL */
    volatile uint32_t hip_seq_gen_2_ctrl;                 /* 0x400a20a8UL */
    volatile uint32_t pasc_status_0;                      /* 0x400a20acUL */
    volatile uint32_t pasc_status_1;                      /* 0x400a20b0UL */
    volatile uint32_t pasc_status_2;                      /* 0x400a20b4UL */
    volatile uint32_t rsrvd59;
    volatile uint32_t pasc_status_4;                      /* 0x400a20bcUL */
    volatile uint32_t pasc_ddft_mux;                      /* 0x400a20c0UL */
    volatile uint32_t pasc_gpio_ddft_mux;                 /* 0x400a20c4UL */
    volatile uint32_t rsrvd60[98];
    volatile uint32_t ibtr_cfg;                           /* 0x400a2250UL */
    volatile uint32_t ibtr_ctrl;                          /* 0x400a2254UL */
    volatile uint32_t ibtr_opr_value;                     /* 0x400a2258UL */
    volatile uint32_t ibtr_init_fin_value;                /* 0x400a225cUL */
    volatile uint32_t rsrvd61;
    volatile uint32_t ibtr_status;                        /* 0x400a2264UL */
    volatile uint32_t rsrvd62[6];
    volatile uint32_t intr17_cfg_0;                       /* 0x400a2280UL */
    volatile uint32_t rsrvd63[9];
    volatile uint32_t intr17_cfg_10;                      /* 0x400a22a8UL */
    volatile uint32_t rsrvd64[14];
    volatile uint32_t intr17_status_0;                    /* 0x400a22e4UL */
    volatile uint32_t intr17_status_1;                    /* 0x400a22e8UL */
    volatile uint32_t intr17;                             /* 0x400a22ecUL */
    volatile uint32_t intr17_set;                         /* 0x400a22f0UL */
    volatile uint32_t intr17_mask;                        /* 0x400a22f4UL */
    volatile uint32_t intr17_masked;                      /* 0x400a22f8UL */
    volatile uint32_t rsrvd65[17];
    volatile uint32_t intr10;                             /* 0x400a2340UL */
    volatile uint32_t intr10_set;                         /* 0x400a2344UL */
    volatile uint32_t intr10_mask;                        /* 0x400a2348UL */
    volatile uint32_t intr10_masked;                      /* 0x400a234cUL */
    volatile uint32_t rsrvd66[128];
    volatile uint32_t ptdrv_ctrl_0;                       /* 0x400a2550UL */
    volatile uint32_t ptdrv_ctrl_1;                       /* 0x400a2554UL */
    volatile uint32_t hip_seq_gen_3_ctrl;                 /* 0x400a2558UL */
    volatile uint32_t hip_seq_gen_4_ctrl;                 /* 0x400a255cUL */
    volatile uint32_t hip_seq_gen_5_ctrl;                 /* 0x400a2560UL */
    volatile uint32_t hip_seq_gen_6_ctrl;                 /* 0x400a2564UL */
    volatile uint32_t rsrvd67;
    volatile uint32_t pasc_ctrl_1;                        /* 0x400a256cUL */
    volatile uint32_t lscsav2_ctrl_0;                     /* 0x400a2570UL */
    volatile uint32_t lscsav2_ctrl_1;                     /* 0x400a2574UL */
    volatile uint32_t v2_40vreg_ctrl;                     /* 0x400a2578UL */
    volatile uint32_t feedfwd_1_ctrl;                     /* 0x400a257cUL */
    volatile uint32_t feedfwd_2_ctrl;                     /* 0x400a2580UL */
    volatile uint32_t bg_ref_ctrl;                        /* 0x400a2584UL */
    volatile uint32_t pasc_pwm_3_ctrl;                    /* 0x400a2588UL */
    volatile uint32_t pasc_pwm_4_ctrl;                    /* 0x400a258cUL */
    volatile uint32_t pasc_pwm_5_ctrl;                    /* 0x400a2590UL */
    volatile uint32_t pasc_pwm_6_ctrl;                    /* 0x400a2594UL */
    volatile uint32_t pasc_status_5;                      /* 0x400a2598UL */
    volatile uint32_t pasc_status_6;                      /* 0x400a259cUL */
    volatile uint32_t pasc_status_7;                      /* 0x400a25a0UL */
    volatile uint32_t srgdrv_2_ctrl;                      /* 0x400a25a4UL */
    volatile uint32_t srgdrv_3_ctrl;                      /* 0x400a25a8UL */
    volatile uint32_t peakgen_3_ctrl;                     /* 0x400a25acUL */
    volatile uint32_t intr19_cfg_0;                       /* 0x400a25b0UL */
    volatile uint32_t intr19_cfg_1;                       /* 0x400a25b4UL */
    volatile uint32_t intr19_cfg_2;                       /* 0x400a25b8UL */
    volatile uint32_t intr19_cfg_3;                       /* 0x400a25bcUL */
    volatile uint32_t intr19_cfg_4;                       /* 0x400a25c0UL */
    volatile uint32_t intr19_cfg_5;                       /* 0x400a25c4UL */
    volatile uint32_t intr19_cfg_6;                       /* 0x400a25c8UL */
    volatile uint32_t intr19_status;                      /* 0x400a25ccUL */
    volatile uint32_t intr19;                             /* 0x400a25d0UL */
    volatile uint32_t intr19_set;                         /* 0x400a25d4UL */
    volatile uint32_t intr19_mask;                        /* 0x400a25d8UL */
    volatile uint32_t intr19_masked;                      /* 0x400a25dcUL */
    volatile uint32_t pag2s_ncell_ddft_mux;               /* 0x400a25e0UL */
    volatile uint32_t sr_sen_pulldn_en_cfg;               /* 0x400a25e4UL */
    volatile uint32_t rsrvd68[6];
    volatile uint32_t valley_load[12];                    /* 0x400a2600UL */
    volatile uint32_t valley_config;                      /* 0x400a2630UL */
    volatile uint32_t valley_ctrl;                        /* 0x400a2634UL */
    volatile uint32_t valley_status;                      /* 0x400a2638UL */
    volatile uint32_t valley_line_in;                     /* 0x400a263cUL */
    volatile uint32_t valley_load_trans;                  /* 0x400a2640UL */
    volatile uint32_t rsrvd69;
    volatile uint32_t rsns_shrt;                          /* 0x400a2648UL */
    volatile uint32_t otp_ctrl;                           /* 0x400a264cUL */
} PDSS_REGS_T, *PPDSS_REGS_T;

#define PDSS        ((PPDSS_REGS_T) PDSS_BASE_ADDR)
#define PDSS0       PDSS

#define PDSS_TRIMS_BASE_ADDR                             (0x400aff00UL)

typedef struct {
    volatile uint32_t trim_cc_0;                          /* 0x400aff00UL */
    volatile uint32_t trim_cc_1;                          /* 0x400aff04UL */
    volatile uint32_t trim_cc_2;                          /* 0x400aff08UL */
    volatile uint32_t trim_cc_3;                          /* 0x400aff0cUL */
    volatile uint32_t trim_cc_4;                          /* 0x400aff10UL */
    volatile uint32_t trim_cc_5;                          /* 0x400aff14UL */
    volatile uint32_t trim_cc_6;                          /* 0x400aff18UL */
    volatile uint32_t trim_cc_7;                          /* 0x400aff1cUL */
    volatile uint32_t trim_bch_det1_0;                    /* 0x400aff20UL */
    volatile uint32_t trim_bch_det1_1;                    /* 0x400aff24UL */
    volatile uint32_t trim_bch_det1_2;                    /* 0x400aff28UL */
    volatile uint32_t trim_bch_det1_3;                    /* 0x400aff2cUL */
    volatile uint32_t trim_bch_det1_4;                    /* 0x400aff30UL */
    volatile uint32_t trim_bch_det1_5;                    /* 0x400aff34UL */
    volatile uint32_t trim_refgen1_0;                     /* 0x400aff38UL */
    volatile uint32_t trim_refgen1_1;                     /* 0x400aff3cUL */
    volatile uint32_t trim_pds_ea;                        /* 0x400aff40UL */
    volatile uint32_t trim_spare1;                        /* 0x400aff44UL */
    volatile uint32_t trim_comp1_0;                       /* 0x400aff48UL */
    volatile uint32_t trim_dpslp_0;                       /* 0x400aff4cUL */
    volatile uint32_t trim_dpslp_1;                       /* 0x400aff50UL */
    volatile uint32_t trim_sr_sense_0;                    /* 0x400aff54UL */
    volatile uint32_t trim_sr_sense_2;                    /* 0x400aff58UL */
    volatile uint32_t trim_sr_sense_5;                    /* 0x400aff5cUL */
    volatile uint32_t trim_sr_sense_6;                    /* 0x400aff60UL */
    volatile uint32_t trim_sr_sense_7;                    /* 0x400aff64UL */
    volatile uint32_t trim_sr_sense_8;                    /* 0x400aff68UL */
    volatile uint32_t trim_sr_sense_9;                    /* 0x400aff6cUL */
    volatile uint32_t trim_sr_sense_10;                   /* 0x400aff70UL */
    volatile uint32_t trim_sr_sense_11;                   /* 0x400aff74UL */
    volatile uint32_t trim_sr_sense_12;                   /* 0x400aff78UL */
    volatile uint32_t trim_sr_sense_13;                   /* 0x400aff7cUL */
    volatile uint32_t trim_sr_sense_14;                   /* 0x400aff80UL */
    volatile uint32_t trim_sr_sense_15;                   /* 0x400aff84UL */
    volatile uint32_t trim_pwm_0;                         /* 0x400aff88UL */
    volatile uint32_t trim_pwm_1;                         /* 0x400aff8cUL */
    volatile uint32_t trim_pwm_2;                         /* 0x400aff90UL */
    volatile uint32_t trim_vconn40;                       /* 0x400aff94UL */
    volatile uint32_t trim_40vreg_0;                      /* 0x400aff98UL */
    volatile uint32_t trim_40vreg_1;                      /* 0x400aff9cUL */
    volatile uint32_t trim_lscsa_0;                       /* 0x400affa0UL */
    volatile uint32_t trim_lscsa_1;                       /* 0x400affa4UL */
    volatile uint32_t trim_lscsa_2;                       /* 0x400affa8UL */
    volatile uint32_t trim_5vpump1_0;                     /* 0x400affacUL */
    volatile uint32_t trim_5vpump1_1;                     /* 0x400affb0UL */
    volatile uint32_t trim_bg_ref;                        /* 0x400affb4UL */
    volatile uint32_t trim_otp_0;                         /* 0x400affb8UL */
    volatile uint32_t trim_otp_1;                         /* 0x400affbcUL */
} PDSS_TRIMS_REGS_T, *PPDSS_TRIMS_REGS_T;

#define PDSS_TRIMS        ((PPDSS_TRIMS_REGS_T) PDSS_TRIMS_BASE_ADDR)
#define PDSS_TRIMS0        (PDSS_TRIMS)


#define ROMTABLE_BASE_ADDR                               (0xf0000000UL)

typedef struct {
    volatile uint32_t addr;                               /* 0xf0000000UL */
    volatile uint32_t rsrvd0[1010];
    volatile uint32_t did;                                /* 0xf0000fccUL */
    volatile uint32_t pid4;                               /* 0xf0000fd0UL */
    volatile uint32_t pid5;                               /* 0xf0000fd4UL */
    volatile uint32_t pid6;                               /* 0xf0000fd8UL */
    volatile uint32_t pid7;                               /* 0xf0000fdcUL */
    volatile uint32_t pid0;                               /* 0xf0000fe0UL */
    volatile uint32_t pid1;                               /* 0xf0000fe4UL */
    volatile uint32_t pid2;                               /* 0xf0000fe8UL */
    volatile uint32_t pid3;                               /* 0xf0000fecUL */
    volatile uint32_t cid0;                               /* 0xf0000ff0UL */
    volatile uint32_t cid1;                               /* 0xf0000ff4UL */
    volatile uint32_t cid2;                               /* 0xf0000ff8UL */
    volatile uint32_t cid3;                               /* 0xf0000ffcUL */
} ROMTABLE_REGS_T, *PROMTABLE_REGS_T;

#define ROMTABLE        ((PROMTABLE_REGS_T) ROMTABLE_BASE_ADDR)


/*******************************************************************************
 ************************** REGISTER FIELD DEFINITIONS *************************
 ******************************************************************************/

/*
 * Generic control register
 */
#define PDSS_CTRL_ADDRESS                                   (0x400a0000UL)
#define PDSS_CTRL                                           (*(volatile uint32_t *)(0x400a0000UL))
#define PDSS_CTRL_DEFAULT                                   (0x00000000UL)

/*
 * Setting this register will bypass 5b/4b, CRC.
 */
#define PDSS_CTRL_TX_BYPASS_EN                              (1UL << 0) /* <0:0> R:RW:0:BYPASS_MODE_EN */


/*
 * Setting this register will bypass 5b/4b, CRC.
 */
#define PDSS_CTRL_RX_BYPASS_EN_MASK                         (0x00000006UL) /* <1:2> R:RW:0:BYPASS_MODE_EN */
#define PDSS_CTRL_RX_BYPASS_EN_POS                          (1UL)


/*
 * This bit is used to selects which of the clk_filter or clk_lf drivers
 * the High-Speed filters.
 * 0: clk_lf drives the High Speed filters
 * 1: clk_filter drives the High Speed filters
 */
#define PDSS_CTRL_SEL_CLK_FILTER                            (1UL << 4) /* <4:4> R:RW:0:HS_CLK_FILT_EN */


/*
 * 0: Clock is turned off for AFC block
 * 1: Clock is running in the AFC block
 * This bit must be set after BC1.2 detection for DCP is completed and AFC
 * functionality is required.
 */
#define PDSS_CTRL_AFC_ENABLED                               (1UL << 25) /* <25:25> R:RW:0:BCH_DET_NUM */


/*
 * 0: IP is disabled, Resets the IP, this reset is an async reset.
 * 1: IP is enabled.
 * Note that when the IP is disabled, all the interrupt sources are also
 * disabled.
 * All the clocks that their source is clk_hf will be turned off when IP
 * is disabled.
 */
#define PDSS_CTRL_IP_ENABLED                                (1UL << 31) /* <31:31> R:RW:0: */


/*
 * Header INFO
 */
#define PDSS_HEADER_INFO_ADDRESS                            (0x400a0004UL)
#define PDSS_HEADER_INFO                                    (*(volatile uint32_t *)(0x400a0004UL))
#define PDSS_HEADER_INFO_DEFAULT                            (0x03f10f00UL)

/*
 * This bit will enable/disable extended data messaging.
 * 0: Disable RX extended data messaging
 * 1: Enable  RX extended data messaging
 */
#define PDSS_HEADER_INFO_EN_RX_EXTENDED_DATA                (1UL << 0) /* <0:0> R:RW:0: */


/*
 * This bit will enable/disable extended data messaging.
 * 0: Disable TX extended data messaging
 * 1: Enable  TX extended data messaging
 */
#define PDSS_HEADER_INFO_EN_TX_EXTENDED_DATA                (1UL << 1) /* <1:1> R:RW:0:EXT_DATA_MSG_EN */


/*
 * The location of the extended data field in the Header[15:0].
 * 0: First Bit of the header
 * 1: Second Bit of the header
 * ...
 * 15: 15th bit of theheader
 */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BIT_LOCATION_MASK    (0x00000f00UL) /* <8:11> R:RW:15:EXT_DATA_MSG_EN */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BIT_LOCATION_POS     (8UL)


/*
 * The first bit location of the extended data size field in the header.
 * 0: First Bit of the header
 * 1: Second Bit of the header
 * ...
 * 31: Thirt first bit of the header
 */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BYTE_FIRST_BIT_LOCATION_MASK    (0x0001f000UL) /* <12:16> R:RW:16:EXT_DATA_MSG_EN */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BYTE_FIRST_BIT_LOCATION_POS    (12UL)


/*
 * The first bit location of the extended data size field in the header.
 * 0: First Bit of the header
 * 1: Second Bit of the header
 * ...
 * 31: Thirt first bit of the header
 */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BYTE_LAST_BIT_LOCATION_MASK    (0x003e0000UL) /* <17:21> R:RW:24:EXT_DATA_MSG_EN */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BYTE_LAST_BIT_LOCATION_POS    (17UL)


/*
 * The location of the chunk field in the Header[31:16].
 * 16: 16th Bit of the header
 * 17: 17th Bit of the header
 * ...
 * 31: 31th bit of theheader
 */
#define PDSS_HEADER_INFO_CHUNK_BIT_LOCATION_MASK            (0x03c00000UL) /* <22:25> R:RW:15:KEEP_REG_BIT */
#define PDSS_HEADER_INFO_CHUNK_BIT_LOCATION_POS             (22UL)


/*
 * Transmit Header
 */
#define PDSS_TX_HEADER_ADDRESS                              (0x400a000cUL)
#define PDSS_TX_HEADER                                      (*(volatile uint32_t *)(0x400a000cUL))
#define PDSS_TX_HEADER_DEFAULT                              (0x00000000UL)

/*
 * The transmit header. This register contains the 16-bit(Regular Packet)
 * or 32-bit(Extended Packet) header. Hardware uses this register along with
 * HEADER_INFO register to send either 16-bit (Regular Packet) or 32-bit
 * (Extended Packet) header.
 */
#define PDSS_TX_HEADER_TX_HEADER_MASK                       (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_TX_HEADER_TX_HEADER_POS                        (0UL)


/*
 * TX SRAM Data
 * CMG1:  Only one storage element of 32 bytes is available for both transmit
 * and receive.
 *              Only access to address space 0x0010-0x002C maps to one storage
 * element which is also used in RX direction.
 * Others: The memory for the TX USB Power Delivery Controller is a 64 byte
 * SRAM. This SRAM contains only data part of a packet in non-bypass mode.
 *              Any access to address space 0x0010 - 0x004C will map to SRAM
 * address 0x00-0x31
 */
#define PDSS_TX_MEM_DATA_ADDRESS(n)                         (0x400a0010UL + ((n) * (0x0004UL)))
#define PDSS_TX_MEM_DATA(n)                                 (*(volatile uint32_t *)(0x400a0010UL + ((n) * 0x0004UL)))
#define PDSS_TX_MEM_DATA_DEFAULT                            (0x00000000UL)

/*
 * Data information in the transmitter SRAM. SOP/CRC/EOP will be appened
 * by Hardware.
 * The TX Header needs to be programmed in the TX_HEADER register.
 */
#define PDSS_TX_MEM_DATA_DATA_MASK                          (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_TX_MEM_DATA_DATA_POS                           (0UL)


/*
 * Receive Header
 */
#define PDSS_RX_HEADER_ADDRESS                              (0x400a005cUL)
#define PDSS_RX_HEADER                                      (*(volatile uint32_t *)(0x400a005cUL))
#define PDSS_RX_HEADER_DEFAULT                              (0x00000000UL)

/*
 * The received header. This register contains the 16-bit(Regular Packet)
 * or 32-bit(Extended Packet) header. The INTR2.EXTENDED_MSG_DET and INTR2.CHUNK_DET
 * interrupts indicates of the packet type. Hardware uses the HEADER_INFO
 * register for decoding the incoming packets.
 */
#define PDSS_RX_HEADER_RX_HEADER_MASK                       (0xffffffffUL) /* <0:31> RW:R:0: */
#define PDSS_RX_HEADER_RX_HEADER_POS                        (0UL)


/*
 * RX SRAM Data
 * CMG1:  Only one storage element of 32 bytes is available for both transmit
 * and receive.
 *              Only access to address space 0x0060-0x006C maps to one storage
 * element which is also used in RX direction.
 * Others: The memory for the RX USB power controller is a 64 byte SRAM.
 * This SRAM contains only the data part of a packet in non-bypass mode.
 *              Any access to address space 0x0060 - 0x009C will map to SRAM
 * address 0x00-0x31
 */
#define PDSS_RX_MEM_DATA_ADDRESS(n)                         (0x400a0060UL + ((n) * (0x0004UL)))
#define PDSS_RX_MEM_DATA(n)                                 (*(volatile uint32_t *)(0x400a0060UL + ((n) * 0x0004UL)))
#define PDSS_RX_MEM_DATA_DEFAULT                            (0x00000000UL)

/*
 * The data information in the received SRAM. SOP type is stored in STATUS.SOP_TYPE_DETECTED
 * register.
 * STATUS.SOP_TYPE_DETECTED contains the SOP type for the packet in the RX
 * SRAM.
 * At the start of every packet, INTR.RCV_PACKET_COMPLETE and INTR.RCV_RST
 * status is evaluated, if its reset, then only a new packet will be written
 * else new packet will be dropped.
 */
#define PDSS_RX_MEM_DATA_DATA_MASK                          (0xffffffffUL) /* <0:31> RW:R:0: */
#define PDSS_RX_MEM_DATA_DATA_POS                           (0UL)


/*
 * TX/RX SRAM Read/Write pointer
 * Firmware can use these pointers to Read/Write more data after the RX_SRAM_HALF_END/TX_SRAM_HALF_END
 * interrupts.
 */
#define PDSS_SRAM_PTR_ADDRESS                               (0x400a00a0UL)
#define PDSS_SRAM_PTR                                       (*(volatile uint32_t *)(0x400a00a0UL))
#define PDSS_SRAM_PTR_DEFAULT                               (0x00000000UL)

/*
 * The transmit SRAM read pointer.
 */
#define PDSS_SRAM_PTR_TX_FUNC_RD_PTR_MASK                   (0x0000001fUL) /* <0:4> RW:R:0: */
#define PDSS_SRAM_PTR_TX_FUNC_RD_PTR_POS                    (0UL)


/*
 * The receive SRAM write pointer.
 */
#define PDSS_SRAM_PTR_RX_FUNC_WR_PTR_MASK                   (0x00001f00UL) /* <8:12> RW:R:0: */
#define PDSS_SRAM_PTR_RX_FUNC_WR_PTR_POS                    (8UL)


/*
 * The packet size is odd. Only the first byte of the last two byte is valid.
 * (RX_FUNC_WR_PTR - 1)
 */
#define PDSS_SRAM_PTR_RX_ODD_LENGTH                         (1UL << 13) /* <13:13> RW:R:0: */


/*
 * Generic status register.
 */
#define PDSS_STATUS_ADDRESS                                 (0x400a00a4UL)
#define PDSS_STATUS                                         (*(volatile uint32_t *)(0x400a00a4UL))
#define PDSS_STATUS_DEFAULT                                 (0x00000000UL)

/*
 * Receiver is currently receiving a packet.
 * This signal gives information that the controlller has locked on to SOP
 * and is in process of receiving a packet. This will assert only after locking
 * on to SOP* symbols.
 */
#define PDSS_STATUS_RX_BUSY                                 (1UL << 0) /* <0:0> RW:R:0:PD_EN */


/*
 * Transmitter is currently transmitting a packet or the CRCReceiveTimer
 * is running.
 */
#define PDSS_STATUS_TX_BUSY                                 (1UL << 1) /* <1:1> RW:R:0:PD_EN */


/*
 * This status bit shows the CC_RX_VALID signal.
 * 0: No Valid data on the CC line.
 * 1: Valid Data detected on the CC line.
 */
#define PDSS_STATUS_CC_DATA_VALID                           (1UL << 2) /* <2:2> RW:R:0:PD_EN */


/*
 * Type of SOP detected for the packet stored in the RX SRAM:
 * At the start of every packet, INTR.RCV_PACKET_COMPLETE and INTR.RCV_RST
 * status is evaluated.
 * If both are reset, then this register will be updated with the new packet
 * SOP value.
 * There is no clearing option.
 */
#define PDSS_STATUS_SOP_TYPE_DETECTED_MASK                  (0x00000038UL) /* <3:5> RW:R:0:PD_EN */
#define PDSS_STATUS_SOP_TYPE_DETECTED_POS                   (3UL)


/*
 * GoodCRC Message SOP type detected:
 * At the start of every packet, INTR.RCV_GOODCRC_MSG_COMPLETE status is
 * evaluated, if its reset, then this register will be updated with the new
 * packet SOP value.
 */
#define PDSS_STATUS_GOODCRC_MSG_SOP_TYPE_DETECTED_MASK      (0x000001c0UL) /* <6:8> RW:R:0:PD_EN */
#define PDSS_STATUS_GOODCRC_MSG_SOP_TYPE_DETECTED_POS       (6UL)


/*
 * RST Type detected:
 */
#define PDSS_STATUS_RST_TYPE_DET_MASK                       (0x00000e00UL) /* <9:11> RW:R:0:PD_EN */
#define PDSS_STATUS_RST_TYPE_DET_POS                        (9UL)


/*
 * This status bit shows that the transmit is in the process of sending GoodCRC
 * message
 */
#define PDSS_STATUS_SENDING_GOODCRC_MSG                     (1UL << 13) /* <13:13> RW:R:0:PD_EN */


/*
 * 0: RD is enabled
 * 1: RP is enabled
 */
#define PDSS_STATUS_RP_RD_STATUS                            (1UL << 14) /* <14:14> RW:R:0:RPRD_EN */


/*
 * RX SOP Control for sending GoodCRC Message
 * Hardware will wait for programmable IDLE_COUNTER and then send Good Crc
 * Message.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_ADDRESS                (0x400a00a8UL)
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL                        (*(volatile uint32_t *)(0x400a00a8UL))
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_DEFAULT                (0x00000003UL)

/*
 * Setting this bit will enable sending GoodCrcMsg for packet with Bad EOP.
 * This should be left to default for normal operation.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_SEND_GOOD_CRC_BAD_EOP    (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Setting this bit will enable sending GoodCrcMsg for packet with KCHAR
 * Error. This should be left to default for normal operation.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_SEND_GOOD_CRC_BAD_KCHAR    (1UL << 1) /* <1:1> R:RW:1: */


/*
 * Setting this bit will enable sending GoodCrcMsg for packet even when there
 * is RX Sram Over Flow is detected. This should be left to default for normal
 * operation.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_SEND_GOOD_CRC_SRAM_OVERFLOW    (1UL << 2) /* <2:2> R:RW:0:KEEP_REG_BIT */


/*
 * RX Expected GoodCRC message to stop the CRC timers
 */
#define PDSS_RX_EXPECT_GOODCRC_MSG_ADDRESS                  (0x400a00acUL)
#define PDSS_RX_EXPECT_GOODCRC_MSG                          (*(volatile uint32_t *)(0x400a00acUL))
#define PDSS_RX_EXPECT_GOODCRC_MSG_DEFAULT                  (0x00000001UL)

/*
 * The expected GoodCRC Messgae Header on the RX side. The expected message
 * ID is handled by Firmware. The DEBUG_CC_2.EXPECTED_HEADER_MASK can be
 * used to mask comparing individual bits.
 * The CRC timer will stop on:
 * 1: On the reception of GoodCRC Messegae with good CRC32 where its header
 * matches with this register AND
 * 2: The SOP of the GoodCRC Messgae matches with the EXPECTED_SOP.
 */
#define PDSS_RX_EXPECT_GOODCRC_MSG_EXPECTED_HEADER_MASK     (0x0000ffffUL) /* <0:15> R:RW:1:NOT_USE_TX_HEADER */
#define PDSS_RX_EXPECT_GOODCRC_MSG_EXPECTED_HEADER_POS      (0UL)


/*
 * The expected SOP of GoodCRC Messgae on the RX side.
 */
#define PDSS_RX_EXPECT_GOODCRC_MSG_EXPECTED_SOP_MASK        (0x00070000UL) /* <16:18> R:RW:0:NOT_USE_RX_ORDER_SET */
#define PDSS_RX_EXPECT_GOODCRC_MSG_EXPECTED_SOP_POS         (16UL)


/*
 * FW should toggle this bit before commiting a new packet to be transferred
 * from TX_MEM.
 * 0: Don't disable the RX CRC count down
 * 1: Disable the RX CRC count down.
 *    FW can disable the RX CRC timer whenever it detects the required condition.
 */
#define PDSS_RX_EXPECT_GOODCRC_MSG_DISABLE_RX_CRC_TIMER     (1UL << 19) /* <19:19> R:RW:0: */


/*
 * The 2-Byte Header of the received GoodCRC Message
 */
#define PDSS_RX_GOODCRC_MSG_ADDRESS                         (0x400a00b0UL)
#define PDSS_RX_GOODCRC_MSG                                 (*(volatile uint32_t *)(0x400a00b0UL))
#define PDSS_RX_GOODCRC_MSG_DEFAULT                         (0x00000000UL)

/*
 * The INTR.RCV_GOODCRC_MSG_COMPLETE interrupt indicates the 2-Byte header
 * for GoodCRC message is received and stored in this registers.
 * GOODCRC_MSG_SOP_TYPE_DETECTED contains the SOP type for the GoodCRC MSG.
 * At the start of every packet, INTR.RCV_GOODCRC_MSG_COMPLETE status is
 * evaluated, if its reset, then only a new packet will be written else new
 * packet will be dropped.
 */
#define PDSS_RX_GOODCRC_MSG_HEADER_MASK                     (0x0000ffffUL) /* <0:15> RW:R:0: */
#define PDSS_RX_GOODCRC_MSG_HEADER_POS                      (0UL)


/*
 * The Receive C-Connect registers 0
 */
#define PDSS_RX_CC_0_CFG_ADDRESS                            (0x400a00b4UL)
#define PDSS_RX_CC_0_CFG                                    (*(volatile uint32_t *)(0x400a00b4UL))
#define PDSS_RX_CC_0_CFG_DEFAULT                            (0x00000580UL)

/*
 * This value is internally multiplied by 16.
 * The 16X value when multiplied by the period of CLK_RX defines the maximum
 * clock period.
 * This value is used to cause the RX state machine to return to idle state
 * if no transitions are detected.
 * For 12 Mhz, the count should be 20 Decimal ( becomes approx. 26usec)
 * For 24 Mhz, the count should be 40 Decimal
 */
#define PDSS_RX_CC_0_CFG_RX_CNT_MAX_MASK                    (0x000000ffUL) /* <0:7> R:RW:128: */
#define PDSS_RX_CC_0_CFG_RX_CNT_MAX_POS                     (0UL)


/*
 * Hardware calculates the UI by averaging the pre-programmed number of Preamble
 * Bits in the DEBUG_CC_1 register.
 * Once UI is calculated, hardware uses a sampling point percentage to know
 * whether incoming BMC pattern is a 0 or 1.
 * The Hardware automatically calculates the 75% location with respect to
 * UI.
 * The value of this register determines the sampling point by subtracting
 * number of RX_CLK from 75% UI. The value of 0 will mean that hardware samples
 * at 75% of UI and 1 will mean hardware will sample at around 72.5% of UI
 * for 12Mhz clock and 73.75 for 24Mhz RX_CLK
 * (RX_CLK period/UI will determine the step size percentage)
 * For 12 Mhz CLK_RX operations, set the value to 0x2 which means that hardware
 * will sample incoming BMC pattern at around 70%.
 * For 24Mhz CLK_RX operations, set the value to 0x4 which means that hardware
 * will sample incoming BMC pattern at around 70%
 */
#define PDSS_RX_CC_0_CFG_RX_UI_BOUNDARY_DELTA_MASK          (0x00003f00UL) /* <8:13> R:RW:5: */
#define PDSS_RX_CC_0_CFG_RX_UI_BOUNDARY_DELTA_POS           (8UL)


/*
 * The Receive C-Connect registers 1
 */
#define PDSS_RX_CC_1_CFG_ADDRESS                            (0x400a00b8UL)
#define PDSS_RX_CC_1_CFG                                    (*(volatile uint32_t *)(0x400a00b8UL))
#define PDSS_RX_CC_1_CFG_DEFAULT                            (0x00040000UL)

/*
 * Number of RX_CC transitions before RX_VALID output is raised.
 */
#define PDSS_RX_CC_1_CFG_DELAY_VALID_COUNT_MASK             (0x000f0000UL) /* <16:19> R:RW:4: */
#define PDSS_RX_CC_1_CFG_DELAY_VALID_COUNT_POS              (16UL)


/*
 * Receive SOPs and RSTs order set control
 */
#define PDSS_RX_ORDER_SET_CTRL_ADDRESS                      (0x400a00bcUL)
#define PDSS_RX_ORDER_SET_CTRL                              (*(volatile uint32_t *)(0x400a00bcUL))
#define PDSS_RX_ORDER_SET_CTRL_DEFAULT                      (0x00006103UL)

/*
 * This register is used for SOP, SOP',SOP'", DEBUG SOP', DEBUG SOP" and
 * RX_RESERVED1/2_ORDER_SET(if configured for SOP) oder set detection. It
 * is recommended that CPU program this register to 1 ( 4 out of 4 option).
 * 0: Compare 3 out of 4 order sets
 * 1: Compare 4 out of 4 order sets
 */
#define PDSS_RX_ORDER_SET_CTRL_SOP_CMP_OPT                  (1UL << 0) /* <0:0> R:RW:1:KEEP_REG_BIT */


/*
 * This register is used for Cable RST, Hard RST and RX_RESERVED1/2_ORDER_SET(if
 * configure for RST) order set detection.
 * It is recommended that CPU program this register to 1 ( 4 out of 4 option).
 * 0: Compare 3 out of 4 order sets
 * 1: Compare 4 out of 4 order sets
 */
#define PDSS_RX_ORDER_SET_CTRL_RST_CMP_OPT                  (1UL << 1) /* <1:1> R:RW:1:KEEP_REG_BIT */


/*
 * This register is used to enable/disdable 4-bit preamble detection for
 * SOP detection.
 * 0: SOP Detection:                              SOP logic detection
 * 1: SOP detection: Preamble(4-bit)+ SOP logic detection
 */
#define PDSS_RX_ORDER_SET_CTRL_PREAMBLE_SOP_EN              (1UL << 2) /* <2:2> R:RW:0:KEEP_REG_BIT */


/*
 * This register is used to enable/disdable 4-bit preamble detection for
 * RST detection.
 * 0: RST Detection:                              RST logic detection
 * 1: RST detection: Preamble(4-bit)+ RST logic detection
 */
#define PDSS_RX_ORDER_SET_CTRL_PREAMBLE_RST_EN              (1UL << 3) /* <3:3> R:RW:0:KEEP_REG_BIT */


/*
 * Host Mode: F/W can enable SOP, SOP', SOP" and Hard Reset Detection.
 * Device Mode: F/W should enable only SOP and Hard Reset Detection.
 * Cable Mode: Either SOP' or SOP" based on VCONN, Hard Reset and Cable Reset
 * should be enabled.
 */
#define PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_MASK              (0x00007f00UL) /* <8:14> R:RW:97: */
#define PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_POS               (8UL)


/*
 * Transmit GoodCRC Message order set
 */
#define PDSS_TX_GOODCRC_MSG_ORDER_SET_ADDRESS               (0x400a00c0UL)
#define PDSS_TX_GOODCRC_MSG_ORDER_SET                       (*(volatile uint32_t *)(0x400a00c0UL))
#define PDSS_TX_GOODCRC_MSG_ORDER_SET_DEFAULT               (0x00000000UL)

/*
 * [15:0]   Can also be used for Transmiting GoodCRC Message to SOP'
 * [31:16] Can also be used for Transmiting GoodCRC Message to SOP"
 * This register constains the Transmit GoodCRC Message Header except the
 * MessageID which Is handled by Hardware.
 * [11:9] Message ID (This is handled by HardWare) for SOP'
 * [27:25] Message ID (This is handled by HardWare) for SOP"
 */
#define PDSS_TX_GOODCRC_MSG_ORDER_SET_TX_GOODCRC_OS_MASK    (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_TX_GOODCRC_MSG_ORDER_SET_TX_GOODCRC_OS_POS     (0UL)


/*
 * TX Control
 */
#define PDSS_TX_CTRL_ADDRESS                                (0x400a00c4UL)
#define PDSS_TX_CTRL                                        (*(volatile uint32_t *)(0x400a00c4UL))
#define PDSS_TX_CTRL_DEFAULT                                (0x8f200041UL)

/*
 * For SOP Only.
 * This register constains the Transmit GoodCRC Message Header except the
 * MessageID which Is handled by Hardware.
 * [11:9] Message ID (This is handled by HardWare)
 */
#define PDSS_TX_CTRL_GOODCRC_MSG_BITS_MASK                  (0x0000ffffUL) /* <0:15> R:RW:65:KEEP_REG_BIT */
#define PDSS_TX_CTRL_GOODCRC_MSG_BITS_POS                   (0UL)


/*
 * Setting the EN_TX_BIST_CM2 to "1" will start the transmision of Bist Carrier
 * Mode 2 pattern.
 * FW must manually set TX_CTRL.TX_REG_EN to "1" before setting this register(EN_TX_BIST_CM2)
 * The TX_GO register is not required to be set for this mode.
 * FW should wait for TX_REG_TIMMER (50usec) before setting this bit.
 */
#define PDSS_TX_CTRL_EN_TX_BIST_CM2                         (1UL << 16) /* <16:16> R:RW:0: */


/*
 * TX_GO causes a packet to be sent. FW can send GoodCrcMsg by storing it
 * in the TX SRAM and use TX_GO to send it.
 * Writing a 1 to this bit to cause the message stored in the SRAM Memory
 * to be sent.  Hardware clears this bit once the command is accepted and
 * processing has begun.
 * If TX_GO is set and there is a ongoing receive packet, the TX packet wont
 * be sent and the COLLISION_TYPE1
 * interrupt will be set. In this case, hardware clears the TX_GO.
 * Before setting this FW should check:
 * INTR0->RX_GOOD_PKT && STATUS->DATA_VALID == 0
 */
#define PDSS_TX_CTRL_TX_GO                                  (1UL << 17) /* <17:17> RW1C:RW:0: */


/*
 * Send a Reset over the link. Write a 1 to this bit to cause the transmitter
 * to send a Hard Reset or Cable Reset(TX_HARD_CABLE_ORDER_SET register)
 * over the link. Hardware clears this bit once the command is accepted and
 * processing has begun.
 * If TX_SEND_RST is set and there is a ongoing receive packet, the Reset
 * Sequqnce wont be sent and the COLLISION_TYPE4 interrupt will be set. In
 * this case, hardware clears the TX_SEND_RST.
 * Before settting this FW should check:
 * INTR0->RX_GOOD_PKT && STATUS->DATA_VALID == 0
 */
#define PDSS_TX_CTRL_TX_SEND_RST                            (1UL << 18) /* <18:18> RW1C:RW:0: */


/*
 * Enable transmit retry. Hardware clears this bit once the command is accepted
 * and processing has begun.
 * CPU should increment the retry counter in firmware once TX_PACKET_DONE
 * interrupt is detected by CPU.
 * The following operation is recommneded to FW:
 *    - FW maintains the retry counter
 *    - FW writes a packet in TX_Memory.
 *    - FW checks its retry counter and if its >0 , sets the retry enable
 * bit.
 *    - FW sets the TX_GO.
 *    - HW sends the packet and starts CRC_Timer if enabled.
 *    - On Expiry of CRC_timer, HW retries the packet if retry enable bit
 * was set and then HW auto clears that bit and generates the
 *      TX_RETRY_ENABLE_CLRD interrupt
 *    - HW will start the CRC_timer again.
 *    - FW in parallel would have received the CRC_TIMER expiry interrupt...
 * FW will decrement its retry counter and if retry
 *      counter is still >0, then it will set the retry enable again
 *
 * The usage model is as follows for setting the retry enable bit:
 * 1. Firmware gets the CRC receive timeout interrupt. After getting this
 * interrupt, firmware can either do step 2 or step 3.
 * 2. Firmware should wait for 75 usec after the timeout interrupt and sample
 * retry bit. Retry bit should be zero at this point indicating retry packet
 * has started transmitting or if retry bit is still one, then it could be
 * that collission has been detected on the bus. If Retry bit is 0, firmware
 * can set the retry bit firmware will have approximately Packet size  time
 * + crc timer (Minimum of 1.5 msec)
 * 3. Firmware doesnt want to put delay of 75 usec, it can instead use TX_RETRY_ENABLE_CLRD
 * interrupt.
 */
#define PDSS_TX_CTRL_TX_RETRY_ENABLE                        (1UL << 19) /* <19:19> RW1C:RW:0:KEEP_REG_BIT */


/*
 * Enable the transmitter regulator.
 * This should be set to "1" for BIST mode other wise hardware automatically
 * takes enabling the regulator when TX_REG_CFG=1
 */
#define PDSS_TX_CTRL_TX_REG_EN                              (1UL << 20) /* <20:20> R:RW:0: */


/*
 * 0: Hardware controlling of TX regulator Enable is disabled. CPU can fully
 * control the TX regulator enable by using TX_REG_EN.
 * 1: Hardware controlling the TX regulator Enable is enabled. In this case,
 * CPU can only set the regulator enable to one by setting TX_REG_EN
 */
#define PDSS_TX_CTRL_TX_REG_CFG                             (1UL << 21) /* <21:21> R:RW:1: */


/*
 * The time needed to enable the TX regulator before transmission.
 * The counter runs on CLK_TX_HALF(600Khz)
 */
#define PDSS_TX_CTRL_TX_REG_TIMER_MASK                      (0x3f000000UL) /* <24:29> R:RW:15:KEEP_REG_BIT */
#define PDSS_TX_CTRL_TX_REG_TIMER_POS                       (24UL)


/*
 * Setting this bit will enable corrupting the TX CRC when there is TX Sram
 * Under Flow is detected. This should be left to default for normal operation.
 */
#define PDSS_TX_CTRL_TX_CORRUPT_CRC_ON_UNDER_FLOW           (1UL << 31) /* <31:31> R:RW:1: */


/*
 * Transmit SOP order set
 */
#define PDSS_TX_SOP_ORDER_SET_ADDRESS                       (0x400a00c8UL)
#define PDSS_TX_SOP_ORDER_SET                               (*(volatile uint32_t *)(0x400a00c8UL))
#define PDSS_TX_SOP_ORDER_SET_DEFAULT                       (0x0008e318UL)

/*
 * Transmit SOP order Set use in transmit except GoodCrcMsg
 */
#define PDSS_TX_SOP_ORDER_SET_TX_SOP_OS_MASK                (0x000fffffUL) /* <0:19> R:RW:582424: */
#define PDSS_TX_SOP_ORDER_SET_TX_SOP_OS_POS                 (0UL)


/*
 * Transmit Hard/Cable reset order set
 */
#define PDSS_TX_HARD_CABLE_ORDER_SET_ADDRESS                (0x400a00ccUL)
#define PDSS_TX_HARD_CABLE_ORDER_SET                        (*(volatile uint32_t *)(0x400a00ccUL))
#define PDSS_TX_HARD_CABLE_ORDER_SET_DEFAULT                (0x000e7393UL)

/*
 * Transmit Hard/Cable Reset order Set.
 * Default: Hard Reset Value 0xE7393
 * Cable Reset Value: 0xE0F8C
 */
#define PDSS_TX_HARD_CABLE_ORDER_SET_TX_RESET_OS_MASK       (0x000fffffUL) /* <0:19> R:RW:947091: */
#define PDSS_TX_HARD_CABLE_ORDER_SET_TX_RESET_OS_POS        (0UL)


/*
 * The CRC timer counters configuration
 * Counters used for the timmers needed by this IP
 */
#define PDSS_CRC_COUNTER_ADDRESS                            (0x400a00d0UL)
#define PDSS_CRC_COUNTER                                    (*(volatile uint32_t *)(0x400a00d0UL))
#define PDSS_CRC_COUNTER_DEFAULT                            (0x00000000UL)

/*
 * This counter will run on TX_CLK/2 (PD bit period) clock.
 * This counter is used for RCReceiveTimer(tReceive)/BISTReceiveErrorTimertBistReceive
 * 0: Counter is disabled. Hardware will NOT wait for the CRC_COUNTER to
 * expire.
 * Other: Hardware will wait for the CRC_COUNTER to expire.
 * Once the CRC_COUNTER reaches zero and no Valid CoodCRC message is not
 * received, The CRC_RX_TIMER_EXP interrupt gets set.
 *
 * If TX_BYPASS_EN = 1:
 *         [15:0]: Total number of bits
 */
#define PDSS_CRC_COUNTER_CRC_COUNTER_MASK                   (0x0000ffffUL) /* <0:15> R:RW:0: */
#define PDSS_CRC_COUNTER_CRC_COUNTER_POS                    (0UL)


/*
 * The Inter Packet counters
 * Counters used for IDLE/IFG and  by this IP
 * All the timers/counters have a resolution of 1 UI (Unit Interval) of a
 * Bit. If transmit rate is 300Khz, then each count will tick for 3.33 usec.
 */
#define PDSS_INTER_PACKET_COUNTER_ADDRESS                   (0x400a00d4UL)
#define PDSS_INTER_PACKET_COUNTER                           (*(volatile uint32_t *)(0x400a00d4UL))
#define PDSS_INTER_PACKET_COUNTER_DEFAULT                   (0x01004008UL)

/*
 * USED FOR TX->TX
 * This register is used by DUT to create gap between two back to back transmit
 * packets. For example: For a DFP application if DFP wants to send Hard
 * Reset after a valid packet, then this register could be used for complying
 * with Inter-Packet Gap of 25 usec specified by spec. In cable application,
 * after sending Good CRC handshake for request from DUT, this register could
 * be used to comply with 750usec requirement of cable response after sending
 * Good CRC pkt.
 */
#define PDSS_INTER_PACKET_COUNTER_BUS_IDLE_CNT_MASK         (0x000007ffUL) /* <0:10> R:RW:8: */
#define PDSS_INTER_PACKET_COUNTER_BUS_IDLE_CNT_POS          (0UL)


/*
 * RX -> AUTO_GOODCRC_RESPONSE
 * This counter specifies how long the HW should wait after the end of RX
 * packet to send GoodCRC message. This can be used to comply with interpacket
 * gap of 25usec.
 * 0: Counter is disabled. Hardware will issue goodcrc message if needed
 * after end of the RX Packet
 *
 * For CCG2 ** Silicon, this can stay at spec value of 25usec,
 * For CCG2 *A Silicon, this need to be programmed at minimum of 150usec
 * (Value 50). The new noise circuit gets settled at 75usec and then RX_VALID
 * logic will need another 75usec to declare IDLE on the bus. This value
 * is worst case number and can be used for CCG2 ** Silicon as well.
 * For CCG3/4: The value can be as low as 120usec.
 */
#define PDSS_INTER_PACKET_COUNTER_IDLE_COUNTER_MASK         (0x001ff800UL) /* <11:20> R:RW:8: */
#define PDSS_INTER_PACKET_COUNTER_IDLE_COUNTER_POS          (11UL)


/*
 * END OF ANY RX ON CC-LINE
 * On any RX Packet, this counter will start at end of RX Packet and will
 * reset on Start of RX Packet. This register can be again used to comply
 * with Interpacket Gap (25 usec + end of IDLE detection(12 usec)).
 * CPU after seeing no activity on the bus can immedeately set the TX_GO/TX_SEND_RST
 * bit and this register will make sure that we don't violate any interpacket
 * gap requirement.
 * 0: Counter is disabled.
 */
#define PDSS_INTER_PACKET_COUNTER_IFG_COUNTER_MASK          (0xffe00000UL) /* <21:31> R:RW:8: */
#define PDSS_INTER_PACKET_COUNTER_IFG_COUNTER_POS           (21UL)


/*
 * The trigger enable registers
 * The tr_out[4:0] pins of this IP will be connected to the tr_in pin of
 * tcpwm_ver2 IP at the full chip. The mapping of the these signals is SoC
 * depended and it is defined
 * in SAS.
 */
#define PDSS_TIMER_TRIGGER_ADDRESS                          (0x400a00d8UL)
#define PDSS_TIMER_TRIGGER                                  (*(volatile uint32_t *)(0x400a00d8UL))
#define PDSS_TIMER_TRIGGER_DEFAULT                          (0x00000000UL)

/*
 * 1: The tr_out[0] pin of the IP will toggle on the transmission of the
 * last Bit Of EOP.
 * 0: The toggling of the tr_out[0] pin of the IP is disabled.
 */
#define PDSS_TIMER_TRIGGER_EN_TRIGGER0                      (1UL << 0) /* <0:0> R:RW:0: */


/*
 * 1: The tr_out[1] pin of the IP will toggle on the reception of EOP for
 * any message with Valid CRC (Includes Good Crc Message)
 * 0: The toggling of the tr_out[1] pin of the IP is disabled.
 */
#define PDSS_TIMER_TRIGGER_EN_TRIGGER1                      (1UL << 1) /* <1:1> R:RW:0: */


/*
 * 1: The tr_out[2] pin of the IP will toggle on the reception of EOP for
 * any message with Valid CRC (Excludes the message types specified in the
 * RX_ORDER_SET_CTRL register)
 * 0: The toggling of the tr_out[2] pin of the IP is disabled.
 */
#define PDSS_TIMER_TRIGGER_EN_TRIGGER2                      (1UL << 2) /* <2:2> R:RW:0: */


/*
 * 1: The tr_out[3] pin of the IP will toggle on the reception of EOP for
 * any message (Example: RX Hard Reset/ BIST)
 * 0: The toggling of the tr_out[3] pin of the IP is disabled.
 */
#define PDSS_TIMER_TRIGGER_EN_TRIGGER3                      (1UL << 3) /* <3:3> R:RW:0: */


/*
 * 1: The tr_out[4] pin of the IP will toggle on the transmission of the
 * first Bit of SOP (Additional trigger for starting some different timer).
 * 0: The toggling of the tr_out[4] pin of the IP is disabled.
 */
#define PDSS_TIMER_TRIGGER_EN_TRIGGER4                      (1UL << 4) /* <4:4> R:RW:0: */


/*
 * 1: The tr_out[5] pin of the IP will toggle on rx_valid
 * 0: The toggling of the tr_out[5] pin of the IP is disabled.
 */
#define PDSS_TIMER_TRIGGER_EN_TRIGGER5                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * 1: The tr_out[6] pin of the IP will toggle on the reception of valid SOP.
 * 0: The toggling of the tr_out[6] pin of the IP is disabled.
 */
#define PDSS_TIMER_TRIGGER_EN_TRIGGER6                      (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Debug Control Register
 */
#define PDSS_DEBUG_CTRL_ADDRESS                             (0x400a00dcUL)
#define PDSS_DEBUG_CTRL                                     (*(volatile uint32_t *)(0x400a00dcUL))
#define PDSS_DEBUG_CTRL_DEFAULT                             (0x037f0000UL)

/*
 * This register are for debugging purposes.
 * 0: Receive path is not at reset.
 * 1: Reset the logic on the receive path except the Hard-IP.
 *     FW should check STATUS.RX_BUSY to make sure it is zero before setting
 * this bit.
 */
#define PDSS_DEBUG_CTRL_RESET_RX                            (1UL << 0) /* <0:0> R:RW:0:KEEP_REG_BIT */


/*
 * Message Cal State
 */
#define PDSS_DEBUG_CTRL_RX_MSG_CAL_STATE_MASK               (0x0000000eUL) /* <1:3> RW:R:0:KEEP_REG_BIT */
#define PDSS_DEBUG_CTRL_RX_MSG_CAL_STATE_POS                (1UL)


/*
 * This register are for debugging purposes
 * 0: Transmit path is not at reset.
 * 1: Reset the logic on the transmit path except the Hard-IP.
 *     FW should check STATUS.TX_BUSY to make sure it is zero before setting
 * this bit.
 */
#define PDSS_DEBUG_CTRL_RESET_TX                            (1UL << 8) /* <8:8> R:RW:0:KEEP_REG_BIT */


/*
 * Transmit state machine
 */
#define PDSS_DEBUG_CTRL_TX_MSG_STATE_MASK                   (0x00000e00UL) /* <9:11> RW:R:0:KEEP_REG_BIT */
#define PDSS_DEBUG_CTRL_TX_MSG_STATE_POS                    (9UL)


/*
 * TX SRC Select state machine
 */
#define PDSS_DEBUG_CTRL_TX_SRC_SEL_STATE_MASK               (0x0000e000UL) /* <13:15> RW:R:0:KEEP_REG_BIT */
#define PDSS_DEBUG_CTRL_TX_SRC_SEL_STATE_POS                (13UL)


/*
 * Number of TX preambles+1 (bit transitions)
 */
#define PDSS_DEBUG_CTRL_TX_PREAMBLE_CNT_MASK                (0x003f0000UL) /* <16:21> R:RW:63:KEEP_REG_BIT */
#define PDSS_DEBUG_CTRL_TX_PREAMBLE_CNT_POS                 (16UL)


/*
 * EOP value for Both RX and TX
 */
#define PDSS_DEBUG_CTRL_EOP_VALUE_MASK                      (0x07c00000UL) /* <22:26> R:RW:13:KEEP_REG_BIT */
#define PDSS_DEBUG_CTRL_EOP_VALUE_POS                       (22UL)


/*
 * This bit enables the Receive state machine to exit from RX DATA and CRC
 * states when an EOP is detected.
 * 0: Ignore EOP during the Data and CRC state
 * 1: Exit from Data and CRC state when an EOP is detected and move to STATUS
 * state.
 */
#define PDSS_DEBUG_CTRL_ENABLE_EXIT_ON_EOP                  (1UL << 27) /* <27:27> R:RW:0:PD_EN */


/*
 * This register are for debugging purposes.
 * 0: BB IBTR block is in non-reset mode.
 * 1: Reset the logic on the BB IBTR except the Hard-IP.
 */
#define PDSS_DEBUG_CTRL_RESET_IBTR                          (1UL << 29) /* <29:29> R:RW:0:IBTR_EN */


/*
 * This register are for debugging purposes.
 * 0: VBTR block  is not at reset.
 * 1: Reset the logic on the VBTR except the Hard-IP.
 */
#define PDSS_DEBUG_CTRL_RESET_VBTR                          (1UL << 30) /* <30:30> R:RW:0:VBTR_EN */


/*
 * This register are for debugging purposes.
 * 0: PASC block  is not at reset.
 * 1: Reset the logic on the PASC except the Hard-IP.
 */
#define PDSS_DEBUG_CTRL_RESET_PASC                          (1UL << 31) /* <31:31> R:RW:0:PASC_PASC2_EN */


/*
 * C-Connector Debug control register 0
 */
#define PDSS_DEBUG_CC_0_ADDRESS                             (0x400a00e0UL)
#define PDSS_DEBUG_CC_0                                     (*(volatile uint32_t *)(0x400a00e0UL))
#define PDSS_DEBUG_CC_0_DEFAULT                             (0x00000000UL)

/*
 * FW can only use this bit when the DEBUG_CC_0.TX_CC_DRIVE_SRC is set to
 * "1".
 * 0: Disables the Transceiver to transmit data
 * 1: Enables the Transceiver to transmit data
 */
#define PDSS_DEBUG_CC_0_TX_FIRST_BIT_LEVEL                  (1UL << 0) /* <0:0> R:RW:0:PD_EN */


/*
 * When set enables TX to RX loopback before CC encoding/Decoding data.
 */
#define PDSS_DEBUG_CC_0_LOOP_BACK_NO_BMC                    (1UL << 1) /* <1:1> R:RW:0:PD_EN */


/*
 * Loobback after data encdoing. When set, the BMC encoded tx output will
 * loop back into cc_rx module.
 */
#define PDSS_DEBUG_CC_0_LOOP_BACK_WITH_BMC                  (1UL << 2) /* <2:2> R:RW:0:PD_EN */


/*
 * When set, enables rx module to decode cc_rx line all the time. (Including
 * during transmission).
 */
#define PDSS_DEBUG_CC_0_EXT_LOOP_BACK                       (1UL << 3) /* <3:3> R:RW:0:PD_EN */


/*
 * When set to one, clears the BMC decoder RX state machines and counters.
 * It has to be set back to zero for normal operations.
 * RX_RESET is not required to be set
 */
#define PDSS_DEBUG_CC_0_RX_CLEAR                            (1UL << 4) /* <4:4> R:RW:0:PD_EN */


/*
 * When set to one, clears the TX state machines and counters. It has to
 * be set back to zero for normal operations.
 */
#define PDSS_DEBUG_CC_0_TX_CLEAR                            (1UL << 5) /* <5:5> R:RW:0:PD_EN */


/*
 * This will selects either the mxusbpd_cc_tx or FW to control the TX_EN/TX_DATA
 * ports of the s8usbpd_cc_top Hard IP.
 * 0: Hardware (mxusbpd_cc_tx) controls the TX_EN/TX_DATA ports of the s8usbpd_cc_top
 * Hard IP.
 * 1: This option is for Testing/Char. FW controls the TX_EN/TX_DATA ports
 * of the s8usbpd_cc_top Hard IP.
 */
#define PDSS_DEBUG_CC_0_TX_CC_DRIVE_SRC                     (1UL << 6) /* <6:6> R:RW:0:PD_EN */


/*
 * FW can use this bit to dirve the CC data line when the TX_CC_DRIVE_SRC=1
 * and CC_DPSLP_REF_CTRL.TX_EN=1
 * When TX_CC_DRIVE_SRC is set to one:
 * - TX_EN port of the s8usbpd_cc_top is controlled by CC_DPSLP_REF_CTRL.TX_EN
 * - TX_DATA port of s8usbpd_cc_top Hard IP is controlled by TX_CC_DATA
 */
#define PDSS_DEBUG_CC_0_TX_CC_DATA                          (1UL << 7) /* <7:7> R:RW:0:PD_EN */


/*
 * Selects the inputs to CC_DEBUG_OUT. Used for debug.
 * 0. RX clk_cnt_q[7:0]
 * 1. RX {clk_cnt_q[9:8], cdr_accum_q[11:8], cq_2, cq_3}
 * 2. {count_q, 2'h0}
 * 3. cdr_accum_q[7:0]
 * 4. {1'h0, rx_state_q, cc_rx_data_del_q}
 * 5. limit_q
 * 6. RX {one_detect_q, cc_rx_bit_early_q,  cc_rx_data, cc_rx_bit, cc_rx_valid,
 * cc_rx_data_2_sync, cc_tx_data_pin, cc_data_pin_oe}
 * 7. cdr_average_q_latched_q
 * 8. {diff_q[3:0], low_count_q[3:0]}
 * 9. cdr_average_q[7:0]
 * 16. Not defined yet.
 * 17 TX {2'h0, tx_state_q, new_data_q}
 * 18. TX {2'h0, cq_0, cq_3, cc_tx_data_lat_q, cc_tx_eof_lat_q, cc_tx_data_valid_lat_q,
 * cc_new_data_lat_q}
 * 19.  TX {3'h0, cc_tx_data_pin, cc_data_pin_oe, cc_tx_data, cc_tx_eof,
 * cc_tx_data_valid}
 * 20-15 not defined yet.
 */
#define PDSS_DEBUG_CC_0_DEBUG_SEL_MASK                      (0x00001f00UL) /* <8:12> R:RW:0:KEEP_REG_BIT */
#define PDSS_DEBUG_CC_0_DEBUG_SEL_POS                       (8UL)


/*
 * 0: RX_CC_DATA_VALID signal is not disabled.
 * 1: RX_CC_DATA_VALID signal is disabled.
 */
#define PDSS_DEBUG_CC_0_RX_CC_DATA_VALID_DIS                (1UL << 13) /* <13:13> R:RW:0:PD_EN */


/*
 * Debug output register. Its inputs are selected by CC_DEBUG_SEL
 */
#define PDSS_DEBUG_CC_0_DEBUG_OUT_MASK                      (0x0ff00000UL) /* <20:27> RW:R:0:KEEP_REG_BIT */
#define PDSS_DEBUG_CC_0_DEBUG_OUT_POS                       (20UL)


/*
 * Selection bit for deepsleep vs. active current reference for Rp pull-up
 * termination
 * 0 - Select deepsleep current reference
 * 1 - Select active current reference
 */
#define PDSS_DEBUG_CC_0_IREF_SEL                            (1UL << 28) /* <28:28> R:RW:0:KEEP_REG_BIT */


/*
 * 0: Create EOP in the case of TX BIST
 * 1: Don't create EOP in the case of TX BIST
 */
#define PDSS_DEBUG_CC_0_DISABLE_BIST_EOP                    (1UL << 29) /* <29:29> R:RW:0:PD_EN */


/*
 * C-Connector Debug control register 1
 */
#define PDSS_DEBUG_CC_1_ADDRESS                             (0x400a00e4UL)
#define PDSS_DEBUG_CC_1                                     (*(volatile uint32_t *)(0x400a00e4UL))
#define PDSS_DEBUG_CC_1_DEFAULT                             (0x000140ccUL)

/*
 * Number of preamble bits to be used in the RX for averaging CDR frequency.
 * Any time the value of these bits are changed, the values of NUM_TRANS_AVG
 * will need to be updated.
 */
#define PDSS_DEBUG_CC_1_NUM_PREAMBLE_AVG_MASK               (0x00000007UL) /* <0:2> R:RW:4:PD_EN */
#define PDSS_DEBUG_CC_1_NUM_PREAMBLE_AVG_POS                (0UL)


/*
 * Number of transitions required to complete averaging in the receiver.
 * This register will need to be updated any time values of NUM_PREAMBLE_AVG
 * is changed.
 * Total of this register and RX_IGNR_TRANS_NUM should not be more than 63
 * decimal.
 * The values programmed into this register comes from the following table:
 * NUM_PREAMBLE_AVG = 000 : Use 0x19
 * NUM_PREAMBLE_AVG = 001 : Use 0x19
 * NUM_PREAMBLE_AVG = 010 : Use 0x7
 * NUM_PREAMBLE_AVG = 011 : Use 0xd
 * NUM_PREAMBLE_AVG = 100 : Use 0x19
 * NUM_PREAMBLE_AVG = 101 : Use 0x31
 */
#define PDSS_DEBUG_CC_1_NUM_TRANS_AVG_MASK                  (0x000001f8UL) /* <3:8> R:RW:25:PD_EN */
#define PDSS_DEBUG_CC_1_NUM_TRANS_AVG_POS                   (3UL)


/*
 * 0: Automatic bit rate calculation by HW
 * 1: Disables the RX-CC automatic bit rate detection and the RX_UI_PRERIOD
 * register is used for RX UI period.
 */
#define PDSS_DEBUG_CC_1_RX_DISABLE_AUTO_ADJ                 (1UL << 9) /* <9:9> R:RW:0:PD_EN */


/*
 * When RX_DISABLE_AUTO_ADJ is set, this register value will define RX UI
 * period.
 */
#define PDSS_DEBUG_CC_1_RX_UI_PERIOD_MASK                   (0x0003fc00UL) /* <10:17> R:RW:80:PD_EN */
#define PDSS_DEBUG_CC_1_RX_UI_PERIOD_POS                    (10UL)


/*
 * 0: The TX statemachine does not reset to Idle on the assertion of "send_good_crc"
 * 1: The TX statemachine does       reset to Idle on the assertion of "send_good_crc"
 */
#define PDSS_DEBUG_CC_1_TX_STATE_RST                        (1UL << 18) /* <18:18> R:RW:0:PD_EN */


/*
 * 300ma switch CC1 Pull down value
 */
#define PDSS_DEBUG_CC_1_PFET300_PULLDN_EN_CC1               (1UL << 19) /* <19:19> R:RW:0:KEEP_REG_BIT */


/*
 * 300ma switch CC2 Pull down value
 */
#define PDSS_DEBUG_CC_1_PFET300_PULLDN_EN_CC2               (1UL << 20) /* <20:20> R:RW:0:KEEP_REG_BIT */


/*
 * This bit is used only for Receive Extended Messages with the Chunk bit
 * set.
 * 0: Include the 2-byte extended data message header count
 * 1: Don't include the 2-byte extended data message header count
 */
#define PDSS_DEBUG_CC_1_INC_EXT_CHUNK_HDR_COUNT             (1UL << 25) /* <25:25> R:RW:0:PD_EN */


/*
 * If CTRL.RX_BYPASS_EN OR DEBUG_CC_0.LOOP_BACK_NO_BMC are set then the RX
 * processes will be based on Header Length.
 * 1: The RX processes the packets based on the EOP
 * 0: The RX processes the packets based on the Header length
 */
#define PDSS_DEBUG_CC_1_RX_EOP_BASED_EN                     (1UL << 27) /* <27:27> R:RW:0:PD_EN */


/*
 * This bit will disable the RX CC to generate the last rx_cc_bit_en and
 * RX State machine will create rx_cc_bit_en when the internal counter (BIT_EN_CNTR_CTRL.BIT_EN_CNTR)
 * is equal to BIT_EN_CNTR_CTRL.GEN_BIT_EN_CNTR
 */
#define PDSS_DEBUG_CC_1_DIS_CC_LAST_BIT_EN                  (1UL << 28) /* <28:28> R:RW:0:PD_EN */


/*
 * 0: Regular operation
 * 1: If collision is seen on CRC Response, it would clrea the pending TX_GO
 */
#define PDSS_DEBUG_CC_1_EN_CRC_COLL_GO_CLR                  (1UL << 29) /* <29:29> R:RW:0:PD_EN */


/*
 * C-Connector Debug control register 2
 */
#define PDSS_DEBUG_CC_2_ADDRESS                             (0x400a00e8UL)
#define PDSS_DEBUG_CC_2                                     (*(volatile uint32_t *)(0x400a00e8UL))
#define PDSS_DEBUG_CC_2_DEFAULT                             (0x00ff0100UL)

/*
 * 0: delta value is subtracted from calculated UI period.
 * 1: delta value is added to calculated UI.
 */
#define PDSS_DEBUG_CC_2_RX_DELTA_POLARITY                   (1UL << 0) /* <0:0> R:RW:0: */


/*
 * 1: Disable CC line monitoring while waiting for Auto GoodCRC response
 * for detection collision.
 * When set, Collision will be only checked once IDLE_COUNTER reaches it
 * programmed value.
 * 0: Enable CC line monitoring even when IDLE_COUNTER
 * is running. Any activity on CC line will trigger a collision.
 */
#define PDSS_DEBUG_CC_2_DIS_CC_MON_AUTO_CRC                 (1UL << 1) /* <1:1> R:RW:0: */


/*
 * 1: If any EOP pattern is received during packet, Packet will be aborted.
 * 0: Idle condition/Normal packe-end on CC line will cause abort.
 */
#define PDSS_DEBUG_CC_2_RESET_RX_ON_EOP                     (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Number of initial transitions to be ignored before Preamble averaging
 * starts and cc_rx_valid is raised.
 * Total of this register and NUM_TRANS_AVG should not be more than 63 decimal.
 */
#define PDSS_DEBUG_CC_2_RX_IGNR_TRANS_NUM_MASK              (0x00000fc0UL) /* <6:11> R:RW:4: */
#define PDSS_DEBUG_CC_2_RX_IGNR_TRANS_NUM_POS               (6UL)


/*
 * The bit wise mask bit for RX_EXPEC_GOODCRC_MSG.
 * This is a bit wise mask and if set, that particular bit is enabled for
 * comparison.
 */
#define PDSS_DEBUG_CC_2_EXPECTED_HEADER_MASK_MASK           (0xffff0000UL) /* <16:31> R:RW:255: */
#define PDSS_DEBUG_CC_2_EXPECTED_HEADER_MASK_POS            (16UL)


/*
 * Counter for IDLE detection
 */
#define PDSS_BIT_EN_CNTR_CTRL_ADDRESS                       (0x400a0128UL)
#define PDSS_BIT_EN_CNTR_CTRL                               (*(volatile uint32_t *)(0x400a0128UL))
#define PDSS_BIT_EN_CNTR_CTRL_DEFAULT                       (0x00000000UL)

/*
 * The number of rx clock that Receiver does not see any rx_bit_en to detect
 * a idle condition
 * 0: Disabled
 */
#define PDSS_BIT_EN_CNTR_CTRL_BIT_EN_CNTR_MASK              (0x000003ffUL) /* <0:9> R:RW:0: */
#define PDSS_BIT_EN_CNTR_CTRL_BIT_EN_CNTR_POS               (0UL)


/*
 * An internal rx_bit_en is created when this counter is equal to BIT_EN_CNTR.
 */
#define PDSS_BIT_EN_CNTR_CTRL_GEN_BIT_EN_CNTR_MASK          (0x001f0000UL) /* <16:20> R:RW:0: */
#define PDSS_BIT_EN_CNTR_CTRL_GEN_BIT_EN_CNTR_POS           (16UL)


/*
 * RP, RD Control configuration1
 */
#define PDSS_RP_RD_CFG1_ADDRESS                             (0x400a012cUL)
#define PDSS_RP_RD_CFG1                                     (*(volatile uint32_t *)(0x400a012cUL))
#define PDSS_RP_RD_CFG1_DEFAULT                             (0x00000000UL)

/*
 * 0: Stop DRP process
 * 1: Start DRP process
 */
#define PDSS_RP_RD_CFG1_START_TOGGLE                        (1UL << 0) /* <0:0> RW1C:RW1S:0: */


/*
 * 0: FW controls the RP/RD
 * 1: HardWare controls the RP/RD
 */
#define PDSS_RP_RD_CFG1_HW_RP_RD_AUTO_TOGGLE                (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Toggle period of 50-100ms delay
 */
#define PDSS_RP_RD_CFG1_TOGGLE_PERIOD_MASK                  (0x00007ffcUL) /* <2:14> R:RW:0: */
#define PDSS_RP_RD_CFG1_TOGGLE_PERIOD_POS                   (2UL)


/*
 * Duration of high pulse width
 */
#define PDSS_RP_RD_CFG1_BASE_HIGH_WIDTH_MASK                (0x0fff8000UL) /* <15:27> R:RW:0: */
#define PDSS_RP_RD_CFG1_BASE_HIGH_WIDTH_POS                 (15UL)


/*
 * Counter continues toggle from PAUSE
 */
#define PDSS_RP_RD_CFG1_CONTINUE_PREV                       (1UL << 28) /* <28:28> R:RW:0: */


/*
 * Resets DRP toggle
 */
#define PDSS_RP_RD_CFG1_RESET_COUNT                         (1UL << 29) /* <29:29> RW1C:RW1S:0: */


/*
 * RP, RD Control configuration2
 */
#define PDSS_RP_RD_CFG2_ADDRESS                             (0x400a0130UL)
#define PDSS_RP_RD_CFG2                                     (*(volatile uint32_t *)(0x400a0130UL))
#define PDSS_RP_RD_CFG2_DEFAULT                             (0x00000000UL)

/*
 * This field along with CC2_ATTACH_VALUE is used to programmed the CC attach
 * to be detected when Rp is connected.
 * {CC2_ATTACH_VALUE,CC1_ATTACH_VALUE} - Action
 * 00 - Attach detected on either CC1 or CC2
 * 01 - Attach detected on CC1 only and no attach on CC2
 * 10 - No attach on CC1 and attach detected on CC2 only
 * 11 - Attach detected on both CC1 and CC2
 * FW should set CC1_ATTACH_VALUE and CC2_ATTACH_VALUE register bits appropriate
 * to the detect required.
 * HW will compare these programmed register values to the output of the
 * CC1/CC2 attach comparator to declare attach.
 * The filters on the hard-ip output will be reset by HW to 0 before enabling
 * Rp at each toggle.
 */
#define PDSS_RP_RD_CFG2_CC1_ATTACH_VALUE                    (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Refer to CC1_ATTACH_VALUE
 */
#define PDSS_RP_RD_CFG2_CC2_ATTACH_VALUE                    (1UL << 1) /* <1:1> R:RW:0: */


/*
 * When Rd is connected (acting as a sink): The following options are provided
 * to detect source attach.
 * {VBUS_DET_OVERRIDE,VCMP_CC_OVERRIDE}
 * 00 - Detect source attach either by VBUS presence or presence of Rp on
 * CC lines
 * 01 - Detect source attach by presence of Rp on CC lines only
 * 10 - Detect source attach by VBUS presence only
 * 11 - Detect source attach only when both VBUS is present and Rp is detected
 * on CC lines.
 *
 * VBUS detect is through configuring INTR3_CFG_VREG20_VBUS register.
 * The presence of Rp on the CC lines can be detect by configuring the UP/DWN
 * comparators on the CC line.
 *
 * The comparator and filter required for these detections need to be configured
 * before DRP is enabled.
 */
#define PDSS_RP_RD_CFG2_VBUS_DET_OVERRIDE                   (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Refer to VBUS_DET_OVERRIDE
 */
#define PDSS_RP_RD_CFG2_VCMP_CC_OVERRIDE                    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * 1: Deep Sleep reference is controled by register configuration (CC_CTRL_0.PWR_DISABLE
 * and DPSLP_REF_CTRL.PD_DPSLP)
 * 0: Reference is disabled when RP is present
 * As a power saving feature, when not overridden, the HW dynamically switches
 * the reference ON and OFF based on whether Rp or Rd is presented. This
 * bit is provided as an override mechanism, if issues are found on silicon,
 * with impact of additional DeepSleep power
 */
#define PDSS_RP_RD_CFG2_OVERRIDE_HW_REF_CTRL                (1UL << 4) /* <4:4> R:RW:0: */


/*
 * LF Counter Register
 * Provides actual counter value for LF counter.  LF counter always counts
 * up, is free-running and is clocked using clk_lf.
 */
#define PDSS_LF_CNTR_ADDRESS                                (0x400a0134UL)
#define PDSS_LF_CNTR                                        (*(volatile uint32_t *)(0x400a0134UL))
#define PDSS_LF_CNTR_DEFAULT                                (0x00000000UL)

/*
 * Current value of WDT Counter
 */
#define PDSS_LF_CNTR_COUNTER_MASK                           (0x0000ffffUL) /* <0:15> RW:R:0: */
#define PDSS_LF_CNTR_COUNTER_POS                            (0UL)


/*
 * LF Counter Match Register
 * Firmware provided match value that is compared against LF_CNTR.  The expectation
 * is that firmware modifies this register after each match as part of the
 * LF interrupt service routine.
 */
#define PDSS_LF_CNTR_MATCH_ADDRESS                          (0x400a0138UL)
#define PDSS_LF_CNTR_MATCH                                  (*(volatile uint32_t *)(0x400a0138UL))
#define PDSS_LF_CNTR_MATCH_DEFAULT                          (0x00001000UL)

/*
 * Match value for LF counter.  Every time LF_CNTR reaches MATCH an interrupt
 * is generated.
 */
#define PDSS_LF_CNTR_MATCH_MATCH_MASK                       (0x0000ffffUL) /* <0:15> R:RW:4096: */
#define PDSS_LF_CNTR_MATCH_MATCH_POS                        (0UL)


/*
 * The number of MSB bits of the LF timer that are NOT checked against MATCH.
 *  This value provides control over the time-to-reset of the watchdog (which
 * happens after 3 successive matches).  Note that certain products may enforce
 * a minimum value for this register through design time configuration.
 */
#define PDSS_LF_CNTR_MATCH_IGNORE_BITS_MASK                 (0x000f0000UL) /* <16:19> R:RW:0: */
#define PDSS_LF_CNTR_MATCH_IGNORE_BITS_POS                  (16UL)


/*
 * AFC Charger Detect control 1 for logic
 */
#define PDSS_AFC_1_CTRL_ADDRESS                             (0x400a0140UL)
#define PDSS_AFC_1_CTRL                                     (*(volatile uint32_t *)(0x400a0140UL))
#define PDSS_AFC_1_CTRL_DEFAULT                             (0x00002648UL)

/*
 * F/W sets this bit and hardware will transmit 1 for number of UIs programmed
 * in  RESET_UI_COUNT
 */
#define PDSS_AFC_1_CTRL_TX_RESET                            (1UL << 0) /* <0:0> RW1C:RW:0: */


/*
 * No of UIs Master will wait for slave ping response before timeout is declared
 * and master state machine will go back to IDLE
 */
#define PDSS_AFC_1_CTRL_UI_WAIT_COUNT_PING_RESPONSE_MASK    (0x0000000eUL) /* <1:3> R:RW:4: */
#define PDSS_AFC_1_CTRL_UI_WAIT_COUNT_PING_RESPONSE_POS     (1UL)


/*
 * Duration of number of UIs of 1 on Dminus used for sending/detection of
 * reset
 */
#define PDSS_AFC_1_CTRL_RESET_UI_COUNT_MASK                 (0x00000ff0UL) /* <4:11> R:RW:100: */
#define PDSS_AFC_1_CTRL_RESET_UI_COUNT_POS                  (4UL)


/*
 * Master will update its transmission rate based on the rate at which ping
 * is received (total Ping duration /16 = 1UI)
 */
#define PDSS_AFC_1_CTRL_UPDATE_TXCLK                        (1UL << 12) /* <12:12> R:RW:0: */


/*
 * No of Bytes to be transmitted as response to V_I_Byte request from Master
 */
#define PDSS_AFC_1_CTRL_NO_OF_BYTES_TX_MASK                 (0x0003e000UL) /* <13:17> R:RW:1: */
#define PDSS_AFC_1_CTRL_NO_OF_BYTES_TX_POS                  (13UL)


/*
 * This will selects either the AFC Hardware or FW to control the afc_tx_data/afc_tx_en
 * ports of the s8usbpd_chgdet_afc_top Hard IP.
 * 0: Hardware controls
 * 1: This option is for Testing/Char. FW controls.
 *     afc_tx_en    port of the s8usbpd_chgdet_afc_top is driven by AFC_TX_DATA_EN
 *     afc_tx_data port of the s8usbpd_chgdet_afc_top is driven by AFC_TX_DATA
 */
#define PDSS_AFC_1_CTRL_AFC_TX_DATA_SEL                     (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Refer to AFC_TX_DATA_SEL register
 */
#define PDSS_AFC_1_CTRL_AFC_TX_DATA_EN                      (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Refer to AFC_TX_DATA_SEL register
 */
#define PDSS_AFC_1_CTRL_AFC_TX_DATA                         (1UL << 20) /* <20:20> R:RW:0: */


/*
 * AFC Charger Detect control 2 for logic
 */
#define PDSS_AFC_2_CTRL_ADDRESS                             (0x400a0150UL)
#define PDSS_AFC_2_CTRL                                     (*(volatile uint32_t *)(0x400a0150UL))
#define PDSS_AFC_2_CTRL_DEFAULT                             (0x00000051UL)

/*
 * Setting this bit will disable the update of the UI count on SOP/EOP pulses
 */
#define PDSS_AFC_2_CTRL_DISABLE_SYNC_ON_RX_BY_4_UI          (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Unit Interval duration in Clk_bch cycles
 */
#define PDSS_AFC_2_CTRL_UI_COUNT_MASK                       (0x000001feUL) /* <1:8> R:RW:40: */
#define PDSS_AFC_2_CTRL_UI_COUNT_POS                        (1UL)


/*
 * Received Unit Interval
 */
#define PDSS_AFC_2_CTRL_RX_UI_COUNT_MASK                    (0x0001fe00UL) /* <9:16> RW:R:0: */
#define PDSS_AFC_2_CTRL_RX_UI_COUNT_POS                     (9UL)


/*
 * 1: During Receive use programmed UI_COUNT instead of RX_UI_COUNT
 * 0: Use calculated RX_UI_COUNT
 */
#define PDSS_AFC_2_CTRL_OVERRIDE_UI_FOR_RX                  (1UL << 17) /* <17:17> R:RW:0: */


/*
 * 0: TX PING low is only driven for 1/2-UI
 * 1: TX PING low is only driven for 1-UI
 */
#define PDSS_AFC_2_CTRL_DRIVE_PING_LOW_1UI                  (1UL << 18) /* <18:18> R:RW:0: */


/*
 * AFC Charger Detect Opcode control for logic
 */
#define PDSS_AFC_OPCODE_CTRL_ADDRESS                        (0x400a0160UL)
#define PDSS_AFC_OPCODE_CTRL                                (*(volatile uint32_t *)(0x400a0160UL))
#define PDSS_AFC_OPCODE_CTRL_DEFAULT                        (0x00000000UL)

/*
 * This register encodes the sequence of events to be sent/monitored on the
 * AFC DMINUS line as opcode.  An operation - sequence of opcodes- can be
 * 10 events long.
 * Each event is specified by a 3-bit opcode. Op_code0 is 2:0, Op_code1 is
 * 5:3 and so on to MSB.
 *                                          3'b000 - IDLE. No operation
 *                                          3'b001- TX_PING. Send a PING
 *                                          3'b010 - RX_PING. Wait for a
 * PING
 *                                          3'h011 - TX_DATA_M. Send Data
 * in Master Role.
 *                                          3'h100 - TX_DATA_S. Send Data
 * in Slave Role
 *                                          3'h101 - RX_DATA. Receive Data
 *
 *                                         The DATA phase includes - SOP,TX/RX
 * and EOP. Since EOP has a PING, there should be a RX_PING after DATA phase
 * if required.
 *                                         The last opcode should always
 * be IDLE.
 * The last op_code 29:27 is not available. Instead bit 29 is used to provide
 * an additional functionality. If this bit is set, on completion of the
 * sequence, HW restarts the same sequence. This can be used if the next
 * AFC transaction can happen before the FW can respond
 */
#define PDSS_AFC_OPCODE_CTRL_OP_CODE_MASK                   (0x3fffffffUL) /* <0:29> R:RW:0: */
#define PDSS_AFC_OPCODE_CTRL_OP_CODE_POS                    (0UL)


/*
 * After programming the sequence, FW should set this bit to trigger the
 * execution. On completion of execution or any error event, this bit will
 * be cleared by HW
 */
#define PDSS_AFC_OPCODE_CTRL_OP_CODE_START                  (1UL << 31) /* <31:31> RW1C:RW1S:0: */


/*
 * AFC Charger Detect Ping Pong register
 */
#define PDSS_AFC_PING_PONG_ADDRESS                          (0x400a0170UL)
#define PDSS_AFC_PING_PONG                                  (*(volatile uint32_t *)(0x400a0170UL))
#define PDSS_AFC_PING_PONG_DEFAULT                          (0x00000000UL)

/*
 * AFC TX/RX Data
 */
#define PDSS_AFC_PING_PONG_AFC_DATA_MASK                    (0x0000ffffUL) /* <0:15> RW:RW:0: */
#define PDSS_AFC_PING_PONG_AFC_DATA_POS                     (0UL)


/*
 * Slave ( Dedicated Charger) Control Registers for QC3.0
 */
#define PDSS_QC3_CHRGER_CTRL_ADDRESS                        (0x400a0180UL)
#define PDSS_QC3_CHRGER_CTRL                                (*(volatile uint32_t *)(0x400a0180UL))
#define PDSS_QC3_CHRGER_CTRL_DEFAULT                        (0x00000000UL)

/*
 * Setting this bit to 1 will enable the valid value in DP_PULSE_COUNT.
 * Hardware will clear this bit once it deposits the correct value in
 * DP_PULSE_COUNT/ DM_PULSE_COUNT register.
 */
#define PDSS_QC3_CHRGER_CTRL_READ_DPDM_COUNT                (1UL << 0) /* <0:0> RW1C:RW:0: */


/*
 * Master Enable for hardware to start sensing the pulses on Dplus and Dminus.
 */
#define PDSS_QC3_CHRGER_CTRL_QC3_0_CHG_EN                   (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Pulse count received on DPlus. Only valid when the READ_DPDM_COUNT bit
 * is 0
 */
#define PDSS_QC3_CHRGER_CTRL_DP_PULSE_COUNT_MASK            (0x00003e00UL) /* <9:13> RW:R:0: */
#define PDSS_QC3_CHRGER_CTRL_DP_PULSE_COUNT_POS             (9UL)


/*
 * Pulse count received on DMinus. Only valid when the READ_DPDM_COUNT bit
 * is 0
 */
#define PDSS_QC3_CHRGER_CTRL_DM_PULSE_COUNT_MASK            (0x0007c000UL) /* <14:18> RW:R:0: */
#define PDSS_QC3_CHRGER_CTRL_DM_PULSE_COUNT_POS             (14UL)


/*
 * Register used to control requests made by QC3.0 Portable Device
 */
#define PDSS_QC3_DEVICE_CTRL_ADDRESS                        (0x400a0190UL)
#define PDSS_QC3_DEVICE_CTRL                                (*(volatile uint32_t *)(0x400a0190UL))
#define PDSS_QC3_DEVICE_CTRL_DEFAULT                        (0x00000000UL)

/*
 * Enable to send the request. This will be cleared by hardware once it starts
 * the state-machine
 */
#define PDSS_QC3_DEVICE_CTRL_QC3_SEND_REQUEST               (1UL << 0) /* <0:0> RW1C:RW:0: */


/*
 * Pulse width of the Dplus or Dminus Signal for making requests. The charger_det_clock's
 * period will be used to program this value. Spec requires 200usec-15 msec
 * (any value can be chosen).
 */
#define PDSS_QC3_DEVICE_CTRL_TACTIVE_TIME_MASK              (0x000001feUL) /* <1:8> R:RW:0: */
#define PDSS_QC3_DEVICE_CTRL_TACTIVE_TIME_POS               (1UL)


/*
 * Inactive Period Before a new pulse is sent. Spec requires 100-200 usec
 * timing between two active pulses. Again the count will be function of
 * the  charger_det_clock's period
 */
#define PDSS_QC3_DEVICE_CTRL_TINACTIVE_TIME_MASK            (0x0001fe00UL) /* <9:16> R:RW:0: */
#define PDSS_QC3_DEVICE_CTRL_TINACTIVE_TIME_POS             (9UL)


/*
 * No of increment/decrement requests firmware wants to send on Dplus or
 * Dminus ( controlled by selection DPNDM)
 */
#define PDSS_QC3_DEVICE_CTRL_PULSE_COUNT_MASK               (0x01fe0000UL) /* <17:24> R:RW:0: */
#define PDSS_QC3_DEVICE_CTRL_PULSE_COUNT_POS                (17UL)


/*
 * 1: Increment request pulses are sent on Dplus
 * 0: Decrement request pulses are sent on Dminus
 */
#define PDSS_QC3_DEVICE_CTRL_DPNDM                          (1UL << 25) /* <25:25> R:RW:0: */


/*
 * AFC LOGIC Status
 */
#define PDSS_AFC_SM_STATUS_ADDRESS                          (0x400a01a0UL)
#define PDSS_AFC_SM_STATUS                                  (*(volatile uint32_t *)(0x400a01a0UL))
#define PDSS_AFC_SM_STATUS_DEFAULT                          (0x00000000UL)

/*
 * This is updated whenever the state machine enters the IDLE state. The
 * last state is captured from where the state machine exited.
 */
#define PDSS_AFC_SM_STATUS_LAST_AFC_SM_STATE_MASK           (0x00000007UL) /* <0:2> RW:R:0: */
#define PDSS_AFC_SM_STATUS_LAST_AFC_SM_STATE_POS            (0UL)


/*
 * This provides bit wise status of parity errors received on incoming bits.
 * The status is cleared by Hardware whenever it exits the IDLE state and
 * is updated on every end of byte parity reception
 */
#define PDSS_AFC_SM_STATUS_MASTER_PARITY_ERROR_STATUS_MASK    (0x0007fff8UL) /* <3:18> RW:R:0: */
#define PDSS_AFC_SM_STATUS_MASTER_PARITY_ERROR_STATUS_POS    (3UL)


/*
 * This indicates the number of bytes received from slave as a result of
 * request sent by master. This is cleared whenever master exits the idle
 * state.
 */
#define PDSS_AFC_SM_STATUS_MASTER_NUM_OF_SLAVE_BYTES_RCVD_MASK    (0x00f80000UL) /* <19:23> RW:R:0: */
#define PDSS_AFC_SM_STATUS_MASTER_NUM_OF_SLAVE_BYTES_RCVD_POS    (19UL)


/*
 * This field shows the current opcode in execution
 */
#define PDSS_AFC_SM_STATUS_CURR_OP_CODE_MASK                (0x0f000000UL) /* <24:27> RW:R:0: */
#define PDSS_AFC_SM_STATUS_CURR_OP_CODE_POS                 (24UL)


/*
 * BCH_DET logic HS filter config
 */
#define PDSS_AFC_HS_FILTER_CFG_ADDRESS                      (0x400a01b0UL)
#define PDSS_AFC_HS_FILTER_CFG                              (*(volatile uint32_t *)(0x400a01b0UL))
#define PDSS_AFC_HS_FILTER_CFG_DEFAULT                      (0x00000000UL)

/*
 * 1: Filter is enabled
 */
#define PDSS_AFC_HS_FILTER_CFG_DP_FILT_EN                   (1UL << 0) /* <0:0> R:RW:0: */


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_AFC_HS_FILTER_CFG_DP_FILT_RESET                (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_AFC_HS_FILTER_CFG_DP_FILT_BYPASS               (1UL << 2) /* <2:2> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_AFC_HS_FILTER_CFG_DP_FILT_SEL_MASK             (0x00000ff8UL) /* <3:11> R:RW:0: */
#define PDSS_AFC_HS_FILTER_CFG_DP_FILT_SEL_POS              (3UL)


/*
 * 1: Filter is enabled
 */
#define PDSS_AFC_HS_FILTER_CFG_DM_FILT_EN                   (1UL << 16) /* <16:16> R:RW:0: */


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_AFC_HS_FILTER_CFG_DM_FILT_RESET                (1UL << 17) /* <17:17> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_AFC_HS_FILTER_CFG_DM_FILT_BYPASS               (1UL << 18) /* <18:18> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_AFC_HS_FILTER_CFG_DM_FILT_SEL_MASK             (0x0ff80000UL) /* <19:27> R:RW:0: */
#define PDSS_AFC_HS_FILTER_CFG_DM_FILT_SEL_POS              (19UL)


/*
 * ADC#1-4 SAR Control Register
 * General Purpose voltgae measurement, Temperature Sceining
 */
#define PDSS_ADC_SAR_CTRL_ADDRESS                           (0x400a01c0UL)
#define PDSS_ADC_SAR_CTRL                                   (*(volatile uint32_t *)(0x400a01c0UL))
#define PDSS_ADC_SAR_CTRL_DEFAULT                           (0x00008000UL)

/*
 * Setting this bit will enable the HW SAR logic.
 * Once the SAR_EN is one, Hardware will update the  SAR_OUT register after
 * 8 cycles of clk_sar and clear this register.
 */
#define PDSS_ADC_SAR_CTRL_SAR_EN                            (1UL << 0) /* <0:0> RW1C:RW1S:0: */


/*
 * ADC starting mid value
 */
#define PDSS_ADC_SAR_CTRL_MID_VAL_MASK                      (0x0000ff00UL) /* <8:15> R:RW:128: */
#define PDSS_ADC_SAR_CTRL_MID_VAL_POS                       (8UL)


/*
 * ADC output resistance value
 * Stored 8-bit ADC value after the ID Pin voltage is sampled.
 */
#define PDSS_ADC_SAR_CTRL_SAR_OUT_MASK                      (0x00ff0000UL) /* <16:23> RW:R:0: */
#define PDSS_ADC_SAR_CTRL_SAR_OUT_POS                       (16UL)


/*
 * RefGen Sel8, Sel6 control
 */
#define PDSS_REFGEN_SEL6_SEL8_CTRL_ADDRESS                  (0x400a01e0UL)
#define PDSS_REFGEN_SEL6_SEL8_CTRL                          (*(volatile uint32_t *)(0x400a01e0UL))
#define PDSS_REFGEN_SEL6_SEL8_CTRL_DEFAULT                  (0x00000000UL)

/*
 * 0: HW controls the RefGen HardIP SEL6 port based on the PFC comparator
 * output.
 *     PFC comparator output 1:   RefGen HardIP SEL6 == REFGEN_2_CTRL.SEL7
 *     PFC comparator output 0:   RefGen HardIP SEL6 == REFGEN_2_CTRL.SEL6
 * 1: FW controls the RefGen HardIP SEL6 port using REFGEN_2_CTRL.SEL6 register
 */
#define PDSS_REFGEN_SEL6_SEL8_CTRL_PFC_SEL6                 (1UL << 0) /* <0:0> R:RW:0: */


/*
 * 0: HW controls the RefGen HardIP SEL8 port based on the SR  comparator
 * output.
 *     SR  comparator output 1:   RefGen HardIP SEL8 == REFGEN_3_CTRL.SEL9
 *     SR  comparator output 0:   RefGen HardIP SEL8 == REFGEN_3_CTRL.SEL8
 * 1: FW controls the RefGen HardIP SEL8 port using REFGEN_3_CTRL.SEL8 register
 */
#define PDSS_REFGEN_SEL6_SEL8_CTRL_SR_SEL8                  (1UL << 1) /* <1:1> R:RW:0: */


/*
 * VCONN20/VCONN40 en_switch_cc1 control 1
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 *
 * Timing requirement between en_pump and en_switch_cc1/2 for vconn:
 * i. en_pump has to be made high after 1us of enabling Vconn Switch (en_switch_cc1/2).
 * This will make sure that Switches turns on slowly along with Pump rampup.
 * (Have option to increase this delay up to 10us)
 * ii. Similarly while turning it off, Pump should be turned-off first followed
 * by switch after 1us. (Have option to increase this delay to 10us)
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_ADDRESS              (0x400a0230UL)
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL                      (*(volatile uint32_t *)(0x400a0230UL))
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_DEFAULT              (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the en_switch_cc1 pin
 * 1: HW controlls the  en_switch_cc1 pin
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_AUTO_MODE            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control option.
 * Any write-one to this register will reset the edge detector in the controller.
 * FW should cleared this register after the fault conditions(COMP, VBUS_LESS_5)
 * are removed by writing a "1" to this register.
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_RST_EDGE_DET         (1UL << 1) /* <1:1> R:RW:0: */


/*
 * 0: OC detection is not selected for turning off the en_switch_cc1
 * 1: OC detection is       selected for turning off the en_switch_cc1
 * CCG7D:
 *     0: CSA_OCP detection is not selected for turning off the en_switch_cc1
 *     1: CSA_OCP detection is       selected for turning off the en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CSA_OC           (1UL << 2) /* <2:2> R:RW:0: */


/*
 * 0: SWAP detection & VBUS_LESS_5 is not selected for turning off the en_switch_cc1
 * 1: SWAP detection & VBUS_LESS_5 is       selected for turning off the
 * en_switch_cc1
 * CCG7D: Unused
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_SWAP_VBUS_LESS_5_MASK    (0x00000018UL) /* <3:4> R:RW:0: */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_SWAP_VBUS_LESS_5_POS    (3UL)


/*
 * CPU can used this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected.
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_ON_OFF           (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Bit[6]:
 * 0: FILT20 detection is not selected for turning off the  en_switch_cc1
 * 1: FILT20 detection is       selected for turning off the  en_switch_cc1
 * Bit[7]:
 * 0: FILT21 detection is not selected for turning off the  en_switch_cc1
 * 1: FILT21 detection is       selected for turning off the  en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_FILT2_MASK       (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_FILT2_POS        (6UL)


/*
 * 0: CC1_OCP detection is not selected for turning off the en_switch_cc1
 * 1: CC1_OCP detection is       selected for turning off the en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CC1_OCP          (1UL << 8) /* <8:8> R:RW:0: */


/*
 * 0: CC2_OCP detection is not selected for turning off the en_switch_cc1
 * 1: CC2_OCP detection is       selected for turning off the en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CC2_OCP          (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 0: CC1_OVP detection is not selected for turning off the en_switch_cc1
 * 1: CC1_OVP detection is       selected for turning off the en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CC1_OVP          (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 0: CC2_OVP detection is not selected for turning off the en_switch_cc1
 * 1: CC2_OVP detection is       selected for turning off the en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CC2_OVP          (1UL << 11) /* <11:11> R:RW:0: */


/*
 * 0: SBU1_OVP detection is not selected for turning off the en_switch_cc1
 * 1: SBU1_OVP detection is       selected for turning off the en_switch_cc1
 * CCG7D:
 *      SEL_SBU1_OVP[3:2] Unused
 *      SEL_SBU1_OVP[1]
 *         0: PDS SCP detection is not selected for turning off the en_switch_cc1
 *         1: PDS SCP detection is       selected for turning off the en_switch_cc1
 *      SEL_SBU1_OVP[0]
 *         0: VREG in rush detection is not selected for turning off the
 * en_switch_cc1
 *         1: VREG in rush detection is       selected for turning off the
 * en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_SBU1_OVP_MASK    (0x0000f000UL) /* <12:15> R:RW:0: */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_SBU1_OVP_POS     (12UL)


/*
 * 0: SBU2_OVP detection is not selected for turning off the en_switch_cc1
 * 1: SBU2_OVP detection is       selected for turning off the en_switch_cc1
 * CCG7D:     SEL_SBU1_OVP[3]
 *         0: VIN_OV is not selected for turning off the en_switch_cc1
 *         1: VIN_OV is       selected for turning off the en_switch_cc1
 *      SEL_SBU1_OVP[2]
 *         0: VIN_UV is not selected for turning off the en_switch_cc1
 *         1: VIN_UV is       selected for turning off the en_switch_cc1
 *      SEL_SBU1_OVP[1]
 *         0: ILIM DIG is not selected for turning off the en_switch_cc1
 *         1: ILIM DIG is       selected for turning off the en_switch_cc1
 *      SEL_SBU1_OVP[0]
 *         0: VREG VDDD BOD detection is not selected for turning off the
 * en_switch_cc1
 *         1: VREG VDDD BOD detection is       selected for turning off the
 * en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_SBU2_OVP_MASK    (0x000f0000UL) /* <16:19> R:RW:0: */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_SBU2_OVP_POS     (16UL)


/*
 * The Off value used by Hardware in Automode to turn off the en_switch_cc1
 * bit
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_EN_SWITCH_CC1_OFF_VALUE    (1UL << 20) /* <20:20> R:RW:0: */


/*
 * The ON value used by Hardware to turn on the en_switch_cc1 in swap condition
 * bit
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_EN_SWITCH_CC1_ON_VALUE    (1UL << 21) /* <21:21> R:RW:0: */


/*
 * 0: SCP detection is not selected for turning off the en_switch_cc1
 * 1: SCP detection is       selected for turning off the en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CSA_SCP          (1UL << 28) /* <28:28> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * 0: CSA OUT detection is not selected for turning off the en_switch_cc1
 * 1: CSA OUT detection is       selected for turning off the en_switch_cc1
 * CCG7D: Unused
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CSA_OUT          (1UL << 29) /* <29:29> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * 0: CSA COMP OUT detection is not selected for turning off the en_switch_cc1
 * 1: CSA COMP OUT detection is       selected for turning off the en_switch_cc1
 * CCG7D:
 *     0: CC1_SCP detection is not selected for turning off the en_switch_cc1
 *     1: CC1_SCP detection is       selected for turning off the en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CSA_COMP_OUT     (1UL << 30) /* <30:30> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * 0: CSA VBUS OVP detection is not selected for turning off the en_switch_cc1
 * 1: CSA VBUS OVP detection is       selected for turning off the en_switch_cc1
 * CCG7D:
 *     0: CC2_SCP detection is not selected for turning off the en_switch_cc1
 *     1: CC2_SCP detection is       selected for turning off the en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CSA_VBUS_OVP     (1UL << 31) /* <31:31> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * VCONN20/VCONN40 en_switch_cc1 control 2
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 */
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL_ADDRESS              (0x400a0234UL)
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL                      (*(volatile uint32_t *)(0x400a0234UL))
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL_DEFAULT              (0x00000000UL)

/*
 * There can be a maximum of 24 HS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function
 */
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL_HS_SOURCE_SEL_MASK    (0x0000001fUL) /* <0:4> R:RW:0:CLK_FILTER_FILT_NUM */
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL_HS_SOURCE_SEL_POS    (0UL)


/*
 * There can be a maximum of 8 LS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function.
 */
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL_LS_SOURCE_SEL_MASK    (0x03000000UL) /* <24:25> R:RW:0:CLK_LF_FILT_NUM */
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL_LS_SOURCE_SEL_POS    (24UL)


/*
 * VCONN20/VCONN40 en_switch_cc2 control 1
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 *
 * Timing requirement between en_pump and en_switch_cc1/2 for vconn:
 * i. en_pump has to be made high after 1us of enabling Vconn Switch (en_switch_cc1/2).
 * This will make sure that Switches turns on slowly along with Pump rampup.
 * (Have option to increase this delay up to 10us)
 * ii. Similarly while turning it off, Pump should be turned-off first followed
 * by switch after 1us. (Have option to increase this delay to 10us)
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_ADDRESS              (0x400a0238UL)
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL                      (*(volatile uint32_t *)(0x400a0238UL))
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_DEFAULT              (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the en_switch_cc2 pin
 * 1: HW controlls the en_switch_cc2 pin
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_AUTO_MODE            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control option.
 * Any write-one to this register will reset the edge detector in the controller.
 * FW should cleared this register after the fault conditions(COMP, VBUS_LESS_5)
 * are removed by writing a "1" to this register.
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_RST_EDGE_DET         (1UL << 1) /* <1:1> R:RW:0: */


/*
 * 0: OC detection is not selected for turning off the en_switch_cc2
 * 1: OC detection is       selected for turning off the en_switch_cc2
 * CCG7D:
 *     0: CSA_OCP detection is not selected for turning off the en_switch_cc2
 *     1: CSA_OCP detection is       selected for turning off the en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CSA_OC           (1UL << 2) /* <2:2> R:RW:0: */


/*
 * 0: SWAP detection & VBUS_LESS_5 is not selected for turning off the en_switch_cc2
 * 1: SWAP detection & VBUS_LESS_5 is       selected for turning off the
 * en_switch_cc2
 * CCG7D: Unused
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_SWAP_VBUS_LESS_5_MASK    (0x00000018UL) /* <3:4> R:RW:0: */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_SWAP_VBUS_LESS_5_POS    (3UL)


/*
 * CPU can used this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected.
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_ON_OFF           (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Bit[6]:
 * 0: FILT20 detection is not selected for turning off the  en_switch_cc2
 * 1: FILT20 detection is       selected for turning off the  en_switch_cc2
 * Bit[7]:
 * 0: FILT21 detection is not selected for turning off the  en_switch_cc2
 * 1: FILT21 detection is       selected for turning off the  en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_FILT2_MASK       (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_FILT2_POS        (6UL)


/*
 * 0: CC1_OCP detection is not selected for turning off the en_switch_cc2
 * 1: CC1_OCP detection is       selected for turning off the en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CC1_OCP          (1UL << 8) /* <8:8> R:RW:0: */


/*
 * 0: CC2_OCP detection is not selected for turning off the en_switch_cc2
 * 1: CC2_OCP detection is       selected for turning off the en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CC2_OCP          (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 0: CC1_OVP detection is not selected for turning off the en_switch_cc2
 * 1: CC1_OVP detection is       selected for turning off the en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CC1_OVP          (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 0: CC2_OVP detection is not selected for turning off the en_switch_cc2
 * 1: CC2_OVP detection is       selected for turning off the en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CC2_OVP          (1UL << 11) /* <11:11> R:RW:0: */


/*
 * 0: SBU1_OVP detection is not selected for turning off the en_switch_cc2
 * 1: SBU1_OVP detection is       selected for turning off the en_switch_cc2
 * CCG7D:
 *      SEL_SBU1_OVP[3:2] Unused
 *      SEL_SBU1_OVP[1]
 *         0: PDS SCP detection is not selected for turning off the en_switch_cc2
 *         1: PDS SCP detection is       selected for turning off the en_switch_cc2
 *      SEL_SBU1_OVP[0]
 *         0: VREG in rush detection is not selected for turning off the
 * en_switch_cc2
 *         1: VREG in rush detection is       selected for turning off the
 * en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_SBU1_OVP_MASK    (0x0000f000UL) /* <12:15> R:RW:0: */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_SBU1_OVP_POS     (12UL)


/*
 * 0: SBU2_OVP detection is not selected for turning off the en_switch_cc2
 * 1: SBU2_OVP detection is       selected for turning off the en_switch_cc2
 * CCG7D:     SEL_SBU1_OVP[3]
 *         0: VIN_OV is not selected for turning off the en_switch_cc2
 *         1: VIN_OV is       selected for turning off the en_switch_cc2
 *      SEL_SBU1_OVP[2]
 *         0: VIN_UV is not selected for turning off the en_switch_cc2
 *         1: VIN_UV is       selected for turning off the en_switch_cc2
 *      SEL_SBU1_OVP[1]
 *         0: ILIM DIG is not selected for turning off the en_switch_cc2
 *         1: ILIM DIG is       selected for turning off the en_switch_cc2
 *      SEL_SBU1_OVP[0]
 *         0: VREG VDDD BOD detection is not selected for turning off the
 * en_switch_cc2
 *         1: VREG VDDD BOD detection is       selected for turning off the
 * en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_SBU2_OVP_MASK    (0x000f0000UL) /* <16:19> R:RW:0: */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_SBU2_OVP_POS     (16UL)


/*
 * The Off value used by Hardware in Automode to turn off the en_switch_cc2
 * bit
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_EN_SWITCH_CC2_OFF_VALUE    (1UL << 20) /* <20:20> R:RW:0: */


/*
 * The ON value used by Hardware to turn on the en_switch_cc2 in swap condition
 * bit
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_EN_SWITCH_CC2_ON_VALUE    (1UL << 21) /* <21:21> R:RW:0: */


/*
 * 0: SCP detection is not selected for turning off the en_switch_cc2
 * 1: SCP detection is       selected for turning off the en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CSA_SCP          (1UL << 28) /* <28:28> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * 0: CSA OUT detection is not selected for turning off the en_switch_cc2
 * 1: CSA OUT detection is       selected for turning off the en_switch_cc2
 * CCG7D: Unused
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CSA_OUT          (1UL << 29) /* <29:29> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * 0: CSA COMP OUT detection is not selected for turning off the en_switch_cc2
 * 1: CSA COMP OUT detection is       selected for turning off the en_switch_cc2
 * CCG7D:
 *     0: CC1_SCP detection is not selected for turning off the en_switch_cc2
 *     1: CC1_SCP detection is       selected for turning off the en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CSA_COMP_OUT     (1UL << 30) /* <30:30> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * 0: CSA VBUS OVP detection is not selected for turning off the en_switch_cc2
 * 1: CSA VBUS OVP detection is       selected for turning off the en_switch_cc2
 * CCG7D:
 *     0: CC2_SCP detection is not selected for turning off the en_switch_cc2
 *     1: CC2_SCP detection is       selected for turning off the en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CSA_VBUS_OVP     (1UL << 31) /* <31:31> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * VCONN20/VCONN40 en_switch_cc2 control 2
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 */
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_ADDRESS              (0x400a023cUL)
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL                      (*(volatile uint32_t *)(0x400a023cUL))
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_DEFAULT              (0x00000000UL)

/*
 * There can be a maximum of 24 HS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function
 */
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_HS_SOURCE_SEL_MASK    (0x0000001fUL) /* <0:4> R:RW:0:CLK_FILTER_FILT_NUM */
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_HS_SOURCE_SEL_POS    (0UL)


/*
 * There can be a maximum of 8 LS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function.
 */
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_LS_SOURCE_SEL_MASK    (0x03000000UL) /* <24:25> R:RW:0:CLK_LF_FILT_NUM */
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_LS_SOURCE_SEL_POS    (24UL)


/*
 * VCONN20/VCONN40 pump_en control 1
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_ADDRESS                 (0x400a0240UL)
#define PDSS_VCONN20_PUMP_EN_1_CTRL                         (*(volatile uint32_t *)(0x400a0240UL))
#define PDSS_VCONN20_PUMP_EN_1_CTRL_DEFAULT                 (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the vconn20 en_pump pin
 * 1: HW controlls the vconn20 en_pump pin
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_AUTO_MODE               (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control option.
 * Any write-one to this register will reset the edge detector in the controller.
 * FW should cleared this register after the fault conditions(COMP, VBUS_LESS_5)
 * are removed by writing a "1" to this register.
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_RST_EDGE_DET            (1UL << 1) /* <1:1> R:RW:0: */


/*
 * 0: OC detection is not selected for turning off the vconn20 en_pump
 * 1: OC detection is       selected for turning off the vconn20 en_pump
 * CCG7D:
 *     0: CSA_OCP detection is not selected for turning off the vconn20 en_pump
 *     1: CSA_OCP detection is       selected for turning off the vconn20
 * en_pump
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CSA_OC              (1UL << 2) /* <2:2> R:RW:0: */


/*
 * 0: SWAP detection & VBUS_LESS_5 is not selected for turning off the vconn20
 * en_pump
 * 1: SWAP detection & VBUS_LESS_5 is       selected for turning off the
 * vconn20 en_pump
 * CCG7D: Unused
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_SWAP_VBUS_LESS_5_MASK    (0x00000018UL) /* <3:4> R:RW:0: */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_SWAP_VBUS_LESS_5_POS    (3UL)


/*
 * CPU can used this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected.
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_ON_OFF              (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Bit[6]:
 * 0: FILT20 detection is not selected for turning off the  vconn20 en_pump
 * 1: FILT20 detection is       selected for turning off the  vconn20 en_pump
 * Bit[7]:
 * 0: FILT21 detection is not selected for turning off the  vconn20 en_pump
 * 1: FILT21 detection is       selected for turning off the  vconn20 en_pump
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_FILT2_MASK          (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_FILT2_POS           (6UL)


/*
 * 0: CC1_OCP detection is not selected for turning off the vconn20 en_pump
 * 1: CC1_OCP detection is       selected for turning off the vconn20 en_pump
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CC1_OCP             (1UL << 8) /* <8:8> R:RW:0: */


/*
 * 0: CC2_OCP detection is not selected for turning off the vconn20 en_pump
 * 1: CC2_OCP detection is       selected for turning off the vconn20 en_pump
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CC2_OCP             (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 0: CC1_OVP detection is not selected for turning off the vconn20 en_pump
 * 1: CC1_OVP detection is       selected for turning off the vconn20 en_pump
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CC1_OVP             (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 0: CC2_OVP detection is not selected for turning off the vconn20 en_pump
 * 1: CC2_OVP detection is       selected for turning off the vconn20 en_pump
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CC2_OVP             (1UL << 11) /* <11:11> R:RW:0: */


/*
 * 0: SBU1_OVP detection is not selected for turning off the vconn20 en_pump
 * 1: SBU1_OVP detection is       selected for turning off the vconn20 en_pump
 * CCG7D:
 *      SEL_SBU1_OVP[3:2] Unused
 *      SEL_SBU1_OVP[1]
 *         0: PDS SCP detection is not selected for turning off the en_switch_cc2
 *         1: PDS SCP detection is       selected for turning off the en_switch_cc2
 *      SEL_SBU1_OVP[0]
 *         0: VREG in rush detection is not selected for turning off the
 * vconn20 en_pump
 *         1: VREG in rush detection is       selected for turning off the
 * vconn20 en_pump
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_SBU1_OVP_MASK       (0x0000f000UL) /* <12:15> R:RW:0: */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_SBU1_OVP_POS        (12UL)


/*
 * 0: SBU2_OVP detection is not selected for turning off the vconn20 en_pump
 * 1: SBU2_OVP detection is       selected for turning off the vconn20 en_pump
 * CCG7D:     SEL_SBU1_OVP[3]
 *         0: VIN_OV is not selected for turning off the vconn20 en_pump
 *         1: VIN_OV is       selected for turning off the vconn20 en_pump
 *      SEL_SBU1_OVP[2]
 *         0: VIN_UV is not selected for turning off the vconn20 en_pump
 *         1: VIN_UV is       selected for turning off the vconn20 en_pump
 *      SEL_SBU1_OVP[1]
 *         0: ILIM DIG is not selected for turning off the vconn20 en_pump
 *         1: ILIM DIG is       selected for turning off the vconn20 en_pump
 *      SEL_SBU1_OVP[0]
 *         0: VREG VDDD BOD detection is not selected for turning off the
 * vconn20 en_pump
 *         1: VREG VDDD BOD detection is       selected for turning off the
 * vconn20 en_pump
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_SBU2_OVP_MASK       (0x000f0000UL) /* <16:19> R:RW:0: */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_SBU2_OVP_POS        (16UL)


/*
 * The Off value used by Hardware in Automode to turn off the vconn20 en_pump
 * bit
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_EN_VCONN20_PUMP_OFF_VALUE    (1UL << 20) /* <20:20> R:RW:0: */


/*
 * The ON value used by Hardware to turn on the vconn20 en_pump in swap condition
 * bit
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_EN_VCONN20_PUMP_ON_VALUE    (1UL << 21) /* <21:21> R:RW:0: */


/*
 * 0: SCP detection is not selected for turning off the vconn20 en_pump
 * 1: SCP detection is       selected for turning off the vconn20 en_pump
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CSA_SCP             (1UL << 28) /* <28:28> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * 0: CSA OUT detection is not selected for turning off the vconn20 en_pump
 * 1: CSA OUT detection is       selected for turning off the vconn20 en_pump
 * CCG7D: Unused
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CSA_OUT             (1UL << 29) /* <29:29> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * 0: CSA COMP OUT detection is not selected for turning off the vconn20
 * en_pump
 * 1: CSA COMP OUT detection is       selected for turning off the vconn20
 * en_pump
 * CCG7D:
 *     0: CC1_SCP detection is not selected for turning off the vconn20 en_pump
 *     1: CC1_SCP detection is       selected for turning off the vconn20
 * en_pump
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CSA_COMP_OUT        (1UL << 30) /* <30:30> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * 0: CSA VBUS OVP detection is not selected for turning off the vconn20
 * en_pump
 * 1: CSA VBUS OVP detection is       selected for turning off the vconn20
 * en_pump
 * CCG7D:
 *     0: CC2_SCP detection is not selected for turning off the vconn20 en_pump
 *     1: CC2_SCP detection is       selected for turning off the vconn20
 * en_pump
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CSA_VBUS_OVP        (1UL << 31) /* <31:31> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * VCONN20/VCONN40 pump_en control 2
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 */
#define PDSS_VCONN20_PUMP_EN_2_CTRL_ADDRESS                 (0x400a0244UL)
#define PDSS_VCONN20_PUMP_EN_2_CTRL                         (*(volatile uint32_t *)(0x400a0244UL))
#define PDSS_VCONN20_PUMP_EN_2_CTRL_DEFAULT                 (0x00000000UL)

/*
 * There can be a maximum of 24 HS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function
 */
#define PDSS_VCONN20_PUMP_EN_2_CTRL_HS_SOURCE_SEL_MASK      (0x0000001fUL) /* <0:4> R:RW:0:CLK_FILTER_FILT_NUM */
#define PDSS_VCONN20_PUMP_EN_2_CTRL_HS_SOURCE_SEL_POS       (0UL)


/*
 * There can be a maximum of 8 LS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function.
 */
#define PDSS_VCONN20_PUMP_EN_2_CTRL_LS_SOURCE_SEL_MASK      (0x03000000UL) /* <24:25> R:RW:0:CLK_LF_FILT_NUM */
#define PDSS_VCONN20_PUMP_EN_2_CTRL_LS_SOURCE_SEL_POS       (24UL)


/*
 * Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR1_CFG_ADDRESS                              (0x400a02a0UL)
#define PDSS_INTR1_CFG                                      (*(volatile uint32_t *)(0x400a02a0UL))
#define PDSS_INTR1_CFG_DEFAULT                              (0x00000000UL)

/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_VCMP_LA_CFG_MASK                     (0x00300000UL) /* <20:21> R:RW:0:VCMP_LA_INTR_EN */
#define PDSS_INTR1_CFG_VCMP_LA_CFG_POS                      (20UL)


/*
 * CC1/CC2 Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_ADDRESS                   (0x400a02a4UL)
#define PDSS_INTR1_CFG_CC1_CC2_LS                           (*(volatile uint32_t *)(0x400a02a4UL))
#define PDSS_INTR1_CFG_CC1_CC2_LS_DEFAULT                   (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_EN               (1UL << 0) /* <0:0> R:RW:0:CC1_INTR_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_CFG_MASK              (0x00000006UL) /* <1:2> R:RW:0:CC1_INTR_EN */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_CFG_POS               (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_RESET            (1UL << 3) /* <3:3> R:RW:0:CC1_INTR_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_BYPASS           (1UL << 4) /* <4:4> R:RW:0:CC1_INTR_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_SEL_MASK         (0x000003e0UL) /* <5:9> R:RW:0:CC1_INTR_EN */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_SEL_POS          (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_EN               (1UL << 10) /* <10:10> R:RW:0:CC2_INTR_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_CFG_MASK              (0x00001800UL) /* <11:12> R:RW:0:CC2_INTR_EN */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_CFG_POS               (11UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_RESET            (1UL << 13) /* <13:13> R:RW:0:CC2_INTR_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_BYPASS           (1UL << 14) /* <14:14> R:RW:0:CC2_INTR_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_SEL_MASK         (0x000f8000UL) /* <15:19> R:RW:0:CC2_INTR_EN */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_SEL_POS          (15UL)


/*
 * VCMP_UP/DOWN/FS Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_ADDRESS              (0x400a02a8UL)
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS                      (*(volatile uint32_t *)(0x400a02a8UL))
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_DEFAULT              (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_EN      (1UL << 0) /* <0:0> R:RW:0:VCMP_UP_INTR_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_CFG_MASK     (0x00000006UL) /* <1:2> R:RW:0:VCMP_UP_INTR_EN */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_CFG_POS      (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_RESET    (1UL << 3) /* <3:3> R:RW:0:VCMP_UP_INTR_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_BYPASS    (1UL << 4) /* <4:4> R:RW:0:VCMP_UP_INTR_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:0:VCMP_UP_INTR_EN */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_SEL_POS    (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_EN      (1UL << 10) /* <10:10> R:RW:0:VCMP_DN_INTR_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_CFG_MASK     (0x00001800UL) /* <11:12> R:RW:0:VCMP_DN_INTR_EN */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_CFG_POS      (11UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_RESET    (1UL << 13) /* <13:13> R:RW:0:VCMP_DN_INTR_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_BYPASS    (1UL << 14) /* <14:14> R:RW:0:VCMP_DN_INTR_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_SEL_MASK    (0x000f8000UL) /* <15:19> R:RW:0:VCMP_DN_INTR_EN */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_SEL_POS    (15UL)


/*
 * CC1/CC2 OVP Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_ADDRESS                  (0x400a02b0UL)
#define PDSS_INTR1_CFG_CC12_OVP_HS                          (*(volatile uint32_t *)(0x400a02b0UL))
#define PDSS_INTR1_CFG_CC12_OVP_HS_DEFAULT                  (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_EN          (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_CFG_POS     (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_RESET       (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_BYPASS      (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_SEL_POS     (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_DPSLP_MODE       (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_EN          (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_CFG_MASK    (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_CFG_POS     (12UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_RESET       (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_BYPASS      (1UL << 15) /* <15:15> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_SEL_MASK    (0x001f0000UL) /* <16:20> R:RW:0: */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_SEL_POS     (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_DPSLP_MODE       (1UL << 21) /* <21:21> R:RW:0: */


/*
 * INTR1 Status
 */
#define PDSS_INTR1_STATUS_ADDRESS                           (0x400a02b4UL)
#define PDSS_INTR1_STATUS                                   (*(volatile uint32_t *)(0x400a02b4UL))
#define PDSS_INTR1_STATUS_DEFAULT                           (0x00000000UL)

/*
 * CC1 status (wakeup interrupt from deepsleep)
 * 1: CC1 attached
 * 0: CC1 detached
 */
#define PDSS_INTR1_STATUS_CC1_STATUS                        (1UL << 4) /* <4:4> RW:R:0:CC1_INTR_EN */


/*
 * CC1 Filtered output
 */
#define PDSS_INTR1_STATUS_CC1_FILT                          (1UL << 5) /* <5:5> RW:R:0:CC1_INTR_EN */


/*
 * CC2 status (wakeup interrupt from deepsleep)
 * 1: CC2 attached
 * 0: CC2 detached
 */
#define PDSS_INTR1_STATUS_CC2_STATUS                        (1UL << 6) /* <6:6> RW:R:0:CC2_INTR_EN */


/*
 * CC2 Filtered output
 */
#define PDSS_INTR1_STATUS_CC2_FILT                          (1UL << 7) /* <7:7> RW:R:0:CC2_INTR_EN */


/*
 * This register provides the status CC_LINE_ACTIVITY (wakeup interrupt from
 * deepsleep).
 */
#define PDSS_INTR1_STATUS_VCMP_LA_STATUS                    (1UL << 8) /* <8:8> RW:R:0:VCMP_LA_INTR_EN */


/*
 * VCMP_LA Filtered output
 */
#define PDSS_INTR1_STATUS_VCMP_LA_FILT                      (1UL << 9) /* <9:9> RW:R:0:VCMP_LA_INTR_EN */


/*
 * This register provides the status of VCMP_UP (wakeup interrupt from deepsleep).
 * Not enabled unless CMP_EN bit is set.
 * Edge: Ra/Rd value changed
 * {VCMP_UP, VCMP_DN}:
 * 00: Ra connected
 * 01: Rd connected
 * 11: Nothing connected (float)
 *                OR
 * Edge: Rp value changed
 * {VCMP_UP, VCMP_DN}:
 * 00: Default Rp broadcast
 * 01: 1.5A Rp broadcast
 * 11: 3.0A Rp broadcast
 */
#define PDSS_INTR1_STATUS_VCMP_UP_STATUS                    (1UL << 10) /* <10:10> RW:R:0:VCMP_UP_INTR_EN */


/*
 * VCMP_UP Filtered output
 */
#define PDSS_INTR1_STATUS_VCMP_UP_FILT                      (1UL << 11) /* <11:11> RW:R:0:VCMP_UP_INTR_EN */


/*
 * This register provides the status of VCMP_DN (wakeup interrupt from deepsleep).
 * Not enabled unless CMP_EN bit is set.
 * Edge: Ra/Rd value changed
 *                OR
 * Edge: Rp value changed
 */
#define PDSS_INTR1_STATUS_VCMP_DN_STATUS                    (1UL << 12) /* <12:12> RW:R:0:VCMP_DN_INTR_EN */


/*
 * VCMP_DN Filtered output
 */
#define PDSS_INTR1_STATUS_VCMP_DN_FILT                      (1UL << 13) /* <13:13> RW:R:0:VCMP_DN_INTR_EN */


/*
 * This reads the CC1 over-voltage signal from s8usbpd2_20Vconn_sw_top
 */
#define PDSS_INTR1_STATUS_CC1_OVP_STATUS                    (1UL << 22) /* <22:22> RW:R:0:VCONN20_VCONN40_EN */


/*
 * CC1_OVP Detect Filtered output
 */
#define PDSS_INTR1_STATUS_CC1_OVP_FILT                      (1UL << 23) /* <23:23> RW:R:0:VCONN20_VCONN40_EN */


/*
 * This reads the CC2 over-voltage signal from s8usbpd2_20Vconn_sw_top
 */
#define PDSS_INTR1_STATUS_CC2_OVP_STATUS                    (1UL << 24) /* <24:24> RW:R:0:VCONN20_VCONN40_EN */


/*
 * CC2_OVP Detect Filtered output
 */
#define PDSS_INTR1_STATUS_CC2_OVP_FILT                      (1UL << 25) /* <25:25> RW:R:0:VCONN20_VCONN40_EN */


/*
 * INTR1 Cause.  These are the wakeup interrupts get reflected on interrupt_wakeup
 * pin.
 * The configurations for using the comparators:
 *
 * DFP waiting for attach:
 * vcmp_up connected to CC1: HI = no connect, LO = attach
 * vcmp_dn connected to CC2: HI = no connect, LO = attach
 *
 * DFP after attach:
 * vcmup_up at detach threshold: HI = detach, LO = attach
 * vcmp_dn at Rd/Ra threshold: HI = Rd connected, LO = Ra connected
 * vcmp_la at CC line activity threshold: HI = no activity, LO/Toggling =
 * activity
 *
 * UFP (with VBUS present):
 * vcmup_up at Default/1.5A threshold: HI = Default, LO = 1.5A
 * vcmp_dn at 1.5A/3.0A threshold: HI = 1.5A, LO = 3.0A
 * vcmp_la at CC line activity threshold: HI = no activity, LO/Toggling =
 * activity
 *
 * For detecting the difference between Rd/Ra, firmware will have to check
 * the "DFP after attach" state above to determine it.
 */
#define PDSS_INTR1_ADDRESS                                  (0x400a02b8UL)
#define PDSS_INTR1                                          (*(volatile uint32_t *)(0x400a02b8UL))
#define PDSS_INTR1_DEFAULT                                  (0x00000000UL)

/*
 * CC1 changed (wakeup interrupt from deepsleep)
 * Check the STATUS.CC1_STATUS value
 */
#define PDSS_INTR1_CC1_CHANGED                              (1UL << 2) /* <2:2> RW1S:RW1C:0:CC1_INTR_EN */


/*
 * CC2 changed (wakeup interrupt from deepsleep)
 * Check the STATUS.CC2_STATUS value
 */
#define PDSS_INTR1_CC2_CHANGED                              (1UL << 3) /* <3:3> RW1S:RW1C:0:CC2_INTR_EN */


/*
 * VCMP_LA changed (wakeup interrupt from deepsleep)
 * Check the STATUS.VCMP_LA_STATUS value
 */
#define PDSS_INTR1_VCMP_LA_CHANGED                          (1UL << 4) /* <4:4> RW1S:RW1C:0:VCMP_LA_INTR_EN */


/*
 * VCMP_UP changed (wakeup interrupt from deepsleep)
 * Check the STATUS.VCMP_UP_STATUS value
 */
#define PDSS_INTR1_VCMP_UP_CHANGED                          (1UL << 5) /* <5:5> RW1S:RW1C:0:VCMP_UP_INTR_EN */


/*
 * VCMP_DN changed (wakeup interrupt from deepsleep)
 * Check the STATUS.VCMP_DN_STATUS value
 */
#define PDSS_INTR1_VCMP_DN_CHANGED                          (1UL << 6) /* <6:6> RW1S:RW1C:0:VCMP_DN_INTR_EN */


/*
 * Over-Voltage is detected on CC1 line
 */
#define PDSS_INTR1_CC1_OVP_CHANGED                          (1UL << 11) /* <11:11> RW1S:RW1C:0:VCONN20_VCONN40_EN */


/*
 * Over-Voltage is detected on CC2 line
 */
#define PDSS_INTR1_CC2_OVP_CHANGED                          (1UL << 12) /* <12:12> RW1S:RW1C:0:VCONN20_VCONN40_EN */


/*
 * VSWAP and VBUS_C less that 5V is detected
 */
#define PDSS_INTR1_DRP_ATTACHED_DETECTED                    (1UL << 18) /* <18:18> RW1S:RW1C:0:RPRD_EN */


/*
 * LF Interrupt Request.  This bit is set each time LF_CNTR==LF_MATCH.
 * Due to internal synchronization, it takes 2 SYSCLK cycles to update after
 * a W1C.
 */
#define PDSS_INTR1_LF_CNTR_MATCH                            (1UL << 19) /* <19:19> RW1S:RW1C:0:LF_CNTR_EN */


/*
 * INTR1 Set
 */
#define PDSS_INTR1_SET_ADDRESS                              (0x400a02bcUL)
#define PDSS_INTR1_SET                                      (*(volatile uint32_t *)(0x400a02bcUL))
#define PDSS_INTR1_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC1_CHANGED                          (1UL << 2) /* <2:2> A:RW1S:0:CC1_INTR_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC2_CHANGED                          (1UL << 3) /* <3:3> A:RW1S:0:CC2_INTR_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_VCMP_LA_CHANGED                      (1UL << 4) /* <4:4> A:RW1S:0:VCMP_LA_INTR_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_VCMP_UP_CHANGED                      (1UL << 5) /* <5:5> A:RW1S:0:VCMP_UP_INTR_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_VCMP_DN_CHANGED                      (1UL << 6) /* <6:6> A:RW1S:0:VCMP_DN_INTR_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC1_OVP_CHANGED                      (1UL << 11) /* <11:11> A:RW1S:0:VCONN20_VCONN40_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC2_OVP_CHANGED                      (1UL << 12) /* <12:12> A:RW1S:0:VCONN20_VCONN40_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_DRP_ATTACHED_DETECTED                (1UL << 18) /* <18:18> A:RW1S:0:RPRD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_LF_CNTR_MATCH                        (1UL << 19) /* <19:19> A:RW1S:0:LF_CNTR_EN */


/*
 * INTR1 Mask
 */
#define PDSS_INTR1_MASK_ADDRESS                             (0x400a02c0UL)
#define PDSS_INTR1_MASK                                     (*(volatile uint32_t *)(0x400a02c0UL))
#define PDSS_INTR1_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC1_CHANGED_MASK                    (1UL << 2) /* <2:2> R:RW:0:CC1_INTR_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC2_CHANGED_MASK                    (1UL << 3) /* <3:3> R:RW:0:CC2_INTR_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_VCMP_LA_CHANGED_MASK                (1UL << 4) /* <4:4> R:RW:0:VCMP_LA_INTR_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_VCMP_UP_CHANGED_MASK                (1UL << 5) /* <5:5> R:RW:0:VCMP_UP_INTR_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_VCMP_DN_CHANGED_MASK                (1UL << 6) /* <6:6> R:RW:0:VCMP_DN_INTR_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC1_OVP_CHANGED_MASK                (1UL << 11) /* <11:11> R:RW:0:VCONN20_VCONN40_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC2_OVP_CHANGED_MASK                (1UL << 12) /* <12:12> R:RW:0:VCONN20_VCONN40_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_DRP_ATTACHED_DETECTED_MASK          (1UL << 18) /* <18:18> R:RW:0:RPRD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_LF_CNTR_MASK                        (1UL << 19) /* <19:19> R:RW:0:LF_CNTR_EN */


/*
 * INTR1 Masked
 */
#define PDSS_INTR1_MASKED_ADDRESS                           (0x400a02c4UL)
#define PDSS_INTR1_MASKED                                   (*(volatile uint32_t *)(0x400a02c4UL))
#define PDSS_INTR1_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC1_CHANGED_MASKED                (1UL << 2) /* <2:2> RW:R:0:CC1_INTR_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC2_CHANGED_MASKED                (1UL << 3) /* <3:3> RW:R:0:CC2_INTR_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_VCMP_LA_CHANGED_MASKED            (1UL << 4) /* <4:4> RW:R:0:VCMP_LA_INTR_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_VCMP_UP_CHANGED_MASKED            (1UL << 5) /* <5:5> RW:R:0:VCMP_UP_INTR_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_VCMP_DN_CHANGED_MASKED            (1UL << 6) /* <6:6> RW:R:0:VCMP_DN_INTR_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC1_OVP_CHANGED_MASKED            (1UL << 11) /* <11:11> RW:R:0:VCONN20_VCONN40_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC2_OVP_CHANGED_MASKED            (1UL << 12) /* <12:12> RW:R:0:VCONN20_VCONN40_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_DRP_ATTACHED_DETECTED_MASKED      (1UL << 18) /* <18:18> RW:R:0:RPRD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_LF_CNTR_MASKED                    (1UL << 19) /* <19:19> RW:R:0:LF_CNTR_EN */


/*
 * ADC1-4 High/Low Speed Filter and Edge detector configuration
 */
#define PDSS_INTR3_CFG_ADC_HS_ADDRESS                       (0x400a0304UL)
#define PDSS_INTR3_CFG_ADC_HS                               (*(volatile uint32_t *)(0x400a0304UL))
#define PDSS_INTR3_CFG_ADC_HS_DEFAULT                       (0x00000400UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR3_CFG_ADC_HS_FILT_EN                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR3_CFG_ADC_HS_FILT_CFG_MASK                 (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR3_CFG_ADC_HS_FILT_CFG_POS                  (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR3_CFG_ADC_HS_FILT_RESET                    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR3_CFG_ADC_HS_FILT_BYPASS                   (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR3_CFG_ADC_HS_FILT_SEL_MASK                 (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR3_CFG_ADC_HS_FILT_SEL_POS                  (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR3_CFG_ADC_HS_DPSLP_MODE                    (1UL << 10) /* <10:10> R:RW:1: */


/*
 * INTR3 Status 0
 */
#define PDSS_INTR3_STATUS_0_ADDRESS                         (0x400a0340UL)
#define PDSS_INTR3_STATUS_0                                 (*(volatile uint32_t *)(0x400a0340UL))
#define PDSS_INTR3_STATUS_0_DEFAULT                         (0x00000000UL)

/*
 * The status of cmp_out from the ADC#1-4
 */
#define PDSS_INTR3_STATUS_0_CMP_OUT_STATUS                  (1UL << 2) /* <2:2> RW:R:0:ADC_NUM */


/*
 * ADC1-4 COMP_OUT Filtered output
 */
#define PDSS_INTR3_STATUS_0_CMP_OUT_FILT                    (1UL << 6) /* <6:6> RW:R:0:ADC_NUM */


/*
 * INTR3 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin.
 */
#define PDSS_INTR3_ADDRESS                                  (0x400a0348UL)
#define PDSS_INTR3                                          (*(volatile uint32_t *)(0x400a0348UL))
#define PDSS_INTR3_DEFAULT                                  (0x00000000UL)

/*
 * CMP_OUT1-4 changed (wakeup interrupt from deepsleep)
 * Check the INTR3_STATUS.ADC_CMP_OUT_STATUS value
 */
#define PDSS_INTR3_CMP_OUT_CHANGED                          (1UL << 1) /* <1:1> RW1S:RW1C:0:ADC_NUM */


/*
 * INTR3 Interrupt Set
 */
#define PDSS_INTR3_SET_ADDRESS                              (0x400a034cUL)
#define PDSS_INTR3_SET                                      (*(volatile uint32_t *)(0x400a034cUL))
#define PDSS_INTR3_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_CMP_OUT_CHANGED                      (1UL << 1) /* <1:1> A:RW1S:0:ADC_NUM */


/*
 * INTR3 interrupt Mask
 */
#define PDSS_INTR3_MASK_ADDRESS                             (0x400a0350UL)
#define PDSS_INTR3_MASK                                     (*(volatile uint32_t *)(0x400a0350UL))
#define PDSS_INTR3_MASK_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_CMP_OUT_CHANGED_MASK                (1UL << 1) /* <1:1> R:RW:0:ADC_NUM */


/*
 * INTR3 interrupt Masked
 */
#define PDSS_INTR3_MASKED_ADDRESS                           (0x400a0354UL)
#define PDSS_INTR3_MASKED                                   (*(volatile uint32_t *)(0x400a0354UL))
#define PDSS_INTR3_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_CMP_OUT_CHANGED_MASKED            (1UL << 1) /* <1:1> RW:R:0:ADC_NUM */


/*
 * CLK_FILTER (Refer to CTRL.SEL_CLK_FILTER) Filter configuration
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 *
 * ##################################################
 * For PMG1S30:
 * #                       Source
 * 0                       UV
 * 1                       OV
 * 2                       s8usbpdv2_28vreg_top.in_rush_det_lv
 *
 * For PMG1S31:
 * #                       Source
 * 0                       UV
 * 1                       OV
 * ##################################################
 */
#define PDSS_INTR5_FILTER_CFG_ADDRESS(n)                    (0x400a0380UL + ((n) * (0x0004UL)))
#define PDSS_INTR5_FILTER_CFG(n)                            (*(volatile uint32_t *)(0x400a0380UL + ((n) * 0x0004UL)))
#define PDSS_INTR5_FILTER_CFG_DEFAULT                       (0x00000400UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR5_FILTER_CFG_FILT_EN                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK                 (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR5_FILTER_CFG_FILT_CFG_POS                  (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR5_FILTER_CFG_FILT_RESET                    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR5_FILTER_CFG_FILT_BYPASS                   (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK                 (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR5_FILTER_CFG_FILT_SEL_POS                  (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR5_FILTER_CFG_DPSLP_MODE                    (1UL << 10) /* <10:10> R:RW:1: */


/*
 * INTR5 Status 0
 */
#define PDSS_INTR5_STATUS_0_ADDRESS                         (0x400a03e0UL)
#define PDSS_INTR5_STATUS_0                                 (*(volatile uint32_t *)(0x400a03e0UL))
#define PDSS_INTR5_STATUS_0_DEFAULT                         (0x00000000UL)

/*
 * The status of HS/LS filter edge detectors 1-12
 */
#define PDSS_INTR5_STATUS_0_STATUS_12_MASK                  (0x0000001fUL) /* <0:4> RW:R:0:CLK_FILTER_FILT_NUM_LOG1_12 */
#define PDSS_INTR5_STATUS_0_STATUS_12_POS                   (0UL)


/*
 * 1-12 HS/LS Filtered output
 */
#define PDSS_INTR5_STATUS_0_FILT_12_MASK                    (0x0001f000UL) /* <12:16> RW:R:0:CLK_FILTER_FILT_NUM_LOG1_12 */
#define PDSS_INTR5_STATUS_0_FILT_12_POS                     (12UL)


/*
 * INTR5 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin from HS filters
 */
#define PDSS_INTR5_ADDRESS                                  (0x400a03e8UL)
#define PDSS_INTR5                                          (*(volatile uint32_t *)(0x400a03e8UL))
#define PDSS_INTR5_DEFAULT                                  (0x00000000UL)

/*
 * Change in edge of HS filter edge detectors (wakeup interrupt from deepsleep)
 * Check the  INTR5_STATUS_0/1.STATUS_12/24 value
 */
#define PDSS_INTR5_EDGE_CHANGED_MASK                        (0x0000001fUL) /* <0:4> RW1S:RW1C:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_EDGE_CHANGED_POS                         (0UL)


/*
 * INTR5 Interrupt Set
 */
#define PDSS_INTR5_SET_ADDRESS                              (0x400a03ecUL)
#define PDSS_INTR5_SET                                      (*(volatile uint32_t *)(0x400a03ecUL))
#define PDSS_INTR5_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR5_SET_EDGE_CHANGED_MASK                    (0x0000001fUL) /* <0:4> A:RW1S:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_SET_EDGE_CHANGED_POS                     (0UL)


/*
 * INTR5 interrupt Mask
 */
#define PDSS_INTR5_MASK_ADDRESS                             (0x400a03f0UL)
#define PDSS_INTR5_MASK                                     (*(volatile uint32_t *)(0x400a03f0UL))
#define PDSS_INTR5_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR5_MASK_EDGE_CHANGED_MASK_MASK              (0x0000001fUL) /* <0:4> R:RW:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_MASK_EDGE_CHANGED_MASK_POS               (0UL)


/*
 * INTR5 interrupt Masked
 */
#define PDSS_INTR5_MASKED_ADDRESS                           (0x400a03f4UL)
#define PDSS_INTR5_MASKED                                   (*(volatile uint32_t *)(0x400a03f4UL))
#define PDSS_INTR5_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR5_MASKED_EDGE_CHANGED_MASKED_MASK          (0x0000001fUL) /* <0:4> RW:R:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_MASKED_EDGE_CHANGED_MASKED_POS           (0UL)


/*
 * CLK_LF ONLY Filter configuration
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 */
#define PDSS_INTR7_FILTER_CFG_ADDRESS(n)                    (0x400a0420UL + ((n) * (0x0004UL)))
#define PDSS_INTR7_FILTER_CFG(n)                            (*(volatile uint32_t *)(0x400a0420UL + ((n) * 0x0004UL)))
#define PDSS_INTR7_FILTER_CFG_DEFAULT                       (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR7_FILTER_CFG_FILT_EN                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR7_FILTER_CFG_FILT_CFG_MASK                 (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR7_FILTER_CFG_FILT_CFG_POS                  (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_RESET             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_BYPASS            (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_SEL_MASK          (0x000000e0UL) /* <5:7> R:RW:0: */
#define PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_SEL_POS           (5UL)


/*
 * INTR7 Status
 */
#define PDSS_INTR7_STATUS_ADDRESS                           (0x400a0440UL)
#define PDSS_INTR7_STATUS                                   (*(volatile uint32_t *)(0x400a0440UL))
#define PDSS_INTR7_STATUS_DEFAULT                           (0x00000000UL)

/*
 * The status of LS filter edge detectors
 */
#define PDSS_INTR7_STATUS_STATUS_8_MASK                     (0x00000003UL) /* <0:1> RW:R:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_STATUS_STATUS_8_POS                      (0UL)


/*
 * 1-8 LS Filtered output
 */
#define PDSS_INTR7_STATUS_FILT_8_MASK                       (0x00000300UL) /* <8:9> RW:R:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_STATUS_FILT_8_POS                        (8UL)


/*
 * INTR7 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin from LS filters
 */
#define PDSS_INTR7_ADDRESS                                  (0x400a0444UL)
#define PDSS_INTR7                                          (*(volatile uint32_t *)(0x400a0444UL))
#define PDSS_INTR7_DEFAULT                                  (0x00000000UL)

/*
 * Change in edge of HS filter edge detectors (wakeup interrupt from deepsleep)
 * Check the  INTR7_STATUS.STATUS_8 value
 */
#define PDSS_INTR7_CLK_LF_EDGE_CHANGED_MASK                 (0x00000003UL) /* <0:1> RW1S:RW1C:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_CLK_LF_EDGE_CHANGED_POS                  (0UL)


/*
 * INTR7 Interrupt Set
 */
#define PDSS_INTR7_SET_ADDRESS                              (0x400a0448UL)
#define PDSS_INTR7_SET                                      (*(volatile uint32_t *)(0x400a0448UL))
#define PDSS_INTR7_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR7_SET_CLK_LF_EDGE_CHANGED_MASK             (0x00000003UL) /* <0:1> A:RW1S:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_SET_CLK_LF_EDGE_CHANGED_POS              (0UL)


/*
 * INTR7 interrupt Mask
 */
#define PDSS_INTR7_MASK_ADDRESS                             (0x400a044cUL)
#define PDSS_INTR7_MASK                                     (*(volatile uint32_t *)(0x400a044cUL))
#define PDSS_INTR7_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR7_MASK_CLK_LF_EDGE_CHANGED_MASK_MASK       (0x00000003UL) /* <0:1> R:RW:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_MASK_CLK_LF_EDGE_CHANGED_MASK_POS        (0UL)


/*
 * INTR7 interrupt Masked
 */
#define PDSS_INTR7_MASKED_ADDRESS                           (0x400a0450UL)
#define PDSS_INTR7_MASKED                                   (*(volatile uint32_t *)(0x400a0450UL))
#define PDSS_INTR7_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR7_MASKED_CLK_LF_EDGE_CHANGED_MASKED_MASK    (0x00000003UL) /* <0:1> RW:R:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_MASKED_CLK_LF_EDGE_CHANGED_MASKED_POS    (0UL)


/*
 * Battery Charger 1-4 Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR9_CFG_BCH_DET_ADDRESS                      (0x400a0470UL)
#define PDSS_INTR9_CFG_BCH_DET                              (*(volatile uint32_t *)(0x400a0470UL))
#define PDSS_INTR9_CFG_BCH_DET_DEFAULT                      (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_EN        (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_CFG_MASK       (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_CFG_POS        (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_RESET     (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_BYPASS    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_SEL_MASK    (0x000000e0UL) /* <5:7> R:RW:0: */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_SEL_POS    (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_EN        (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_CFG_MASK       (0x00000600UL) /* <9:10> R:RW:0: */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_CFG_POS        (9UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_RESET     (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_BYPASS    (1UL << 12) /* <12:12> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_SEL_MASK    (0x0000e000UL) /* <13:15> R:RW:0: */
#define PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_SEL_POS    (13UL)


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR9_CFG_BCH_DET_QCOM_RCVR_DM_CFG_MASK        (0x00030000UL) /* <16:17> R:RW:0: */
#define PDSS_INTR9_CFG_BCH_DET_QCOM_RCVR_DM_CFG_POS         (16UL)


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR9_CFG_BCH_DET_QCOM_RCVR_DP_CFG_MASK        (0x000c0000UL) /* <18:19> R:RW:0: */
#define PDSS_INTR9_CFG_BCH_DET_QCOM_RCVR_DP_CFG_POS         (18UL)


/*
 * INTR9 Status 0
 */
#define PDSS_INTR9_STATUS_0_ADDRESS                         (0x400a048cUL)
#define PDSS_INTR9_STATUS_0                                 (*(volatile uint32_t *)(0x400a048cUL))
#define PDSS_INTR9_STATUS_0_DEFAULT                         (0x00000000UL)

/*
 * The status of battery charger comparators1,0
 */
#define PDSS_INTR9_STATUS_0_BCH_DET_STATUS_MASK             (0x00000003UL) /* <0:1> RW:R:0:BCH_DET_NUM_LOG2 */
#define PDSS_INTR9_STATUS_0_BCH_DET_STATUS_POS              (0UL)


/*
 * BCH_DET comp0/1 output  Filtered output
 */
#define PDSS_INTR9_STATUS_0_BCH_DET_FILT_MASK               (0x00000300UL) /* <8:9> RW:R:0:BCH_DET_NUM_LOG2 */
#define PDSS_INTR9_STATUS_0_BCH_DET_FILT_POS                (8UL)


/*
 * INTR9 Status 1
 */
#define PDSS_INTR9_STATUS_1_ADDRESS                         (0x400a0490UL)
#define PDSS_INTR9_STATUS_1                                 (*(volatile uint32_t *)(0x400a0490UL))
#define PDSS_INTR9_STATUS_1_DEFAULT                         (0x00000000UL)

/*
 * The status of qcom receiver dm
 */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DM_STATUS             (1UL << 8) /* <8:8> RW:R:0:BCH_DET_NUM */


/*
 * QCOM RCVR DM  Filtered output
 */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DM_FILT               (1UL << 12) /* <12:12> RW:R:0:BCH_DET_NUM */


/*
 * The status of qcom receiver dp
 */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DP_STATUS             (1UL << 16) /* <16:16> RW:R:0:BCH_DET_NUM */


/*
 * QCOM RCVR DP  Filtered output
 */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DP_FILT               (1UL << 20) /* <20:20> RW:R:0:BCH_DET_NUM */


/*
 * DM  Filtered output
 */
#define PDSS_INTR9_STATUS_1_DM_FILT                         (1UL << 24) /* <24:24> RW:R:0:BCH_DET_NUM */


/*
 * DP  Filtered output
 */
#define PDSS_INTR9_STATUS_1_DP_FILT                         (1UL << 28) /* <28:28> RW:R:0:BCH_DET_NUM */


/*
 * INTR9 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin.
 */
#define PDSS_INTR9_ADDRESS                                  (0x400a0494UL)
#define PDSS_INTR9                                          (*(volatile uint32_t *)(0x400a0494UL))
#define PDSS_INTR9_DEFAULT                                  (0x00000000UL)

/*
 * Edge Detected (wakeup interrupt from deepsleep), COMP0-1=Bit0, COMP0-2=Bit1,
 *  COMP1-1=Bit2, COMP1-2=Bit3,
 * Check the  INTR9_STATUS.BCH_DET_STATUS value
 */
#define PDSS_INTR9_BCH_DET_CHANGED_MASK                     (0x00000003UL) /* <0:1> RW1S:RW1C:0:BCH_DET_NUM_LOG2 */
#define PDSS_INTR9_BCH_DET_CHANGED_POS                      (0UL)


/*
 * Edge Detected (wakeup interrupt from deepsleep)
 * Check the  INTR9_STATUS.QCOM_RCVR_DM_STATUS value
 */
#define PDSS_INTR9_QCOM_RCVR_DM_CHANGED                     (1UL << 20) /* <20:20> RW1S:RW1C:0:BCH_DET_NUM */


/*
 * Edge Detected (wakeup interrupt from deepsleep)
 * Check the  INTR9_STATUS.QCOM_RCVR_DM_STATUS value
 */
#define PDSS_INTR9_QCOM_RCVR_DP_CHANGED                     (1UL << 24) /* <24:24> RW1S:RW1C:0:BCH_DET_NUM */


/*
 * INTR9 Interrupt Set
 */
#define PDSS_INTR9_SET_ADDRESS                              (0x400a0498UL)
#define PDSS_INTR9_SET                                      (*(volatile uint32_t *)(0x400a0498UL))
#define PDSS_INTR9_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR9_SET_BCH_DET_CHANGED_MASK                 (0x00000003UL) /* <0:1> A:RW1S:0:BCH_DET_NUM_LOG2 */
#define PDSS_INTR9_SET_BCH_DET_CHANGED_POS                  (0UL)


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR9_SET_QCOM_RCVR_DM_CHANGED                 (1UL << 20) /* <20:20> A:RW1S:0:BCH_DET_NUM */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR9_SET_QCOM_RCVR_DP_CHANGED                 (1UL << 24) /* <24:24> A:RW1S:0:BCH_DET_NUM */


/*
 * INTR9 interrupt Mask
 */
#define PDSS_INTR9_MASK_ADDRESS                             (0x400a049cUL)
#define PDSS_INTR9_MASK                                     (*(volatile uint32_t *)(0x400a049cUL))
#define PDSS_INTR9_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR9_MASK_BCH_DET_CHANGED_MASK_MASK           (0x00000003UL) /* <0:1> R:RW:0:BCH_DET_NUM_LOG2 */
#define PDSS_INTR9_MASK_BCH_DET_CHANGED_MASK_POS            (0UL)


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR9_MASK_QCOM_RCVR_DM_CHANGED_MASK           (1UL << 20) /* <20:20> R:RW:0:BCH_DET_NUM */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR9_MASK_QCOM_RCVR_DP_CHANGED_MASK           (1UL << 24) /* <24:24> R:RW:0:BCH_DET_NUM */


/*
 * INTR9 interrupt Masked
 */
#define PDSS_INTR9_MASKED_ADDRESS                           (0x400a04a0UL)
#define PDSS_INTR9_MASKED                                   (*(volatile uint32_t *)(0x400a04a0UL))
#define PDSS_INTR9_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR9_MASKED_BCH_DET_CHANGED_MASKED_MASK       (0x00000003UL) /* <0:1> RW:R:0:BCH_DET_NUM_LOG2 */
#define PDSS_INTR9_MASKED_BCH_DET_CHANGED_MASKED_POS        (0UL)


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR9_MASKED_QCOM_RCVR_DM_CHANGED_MASKED       (1UL << 20) /* <20:20> RW:R:0:BCH_DET_NUM */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR9_MASKED_QCOM_RCVR_DP_CHANGED_MASKED       (1UL << 24) /* <24:24> RW:R:0:BCH_DET_NUM */


/*
 * CLK_FILTER2 (Divided version of CLK_HF) Filter configuration
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 */
#define PDSS_INTR11_FILTER_CFG_ADDRESS                      (0x400a04c0UL)
#define PDSS_INTR11_FILTER_CFG                              (*(volatile uint32_t *)(0x400a04c0UL))
#define PDSS_INTR11_FILTER_CFG_DEFAULT                      (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR11_FILTER_CFG_FILT21_EN                    (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR11_FILTER_CFG_FILT21_CFG_MASK              (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR11_FILTER_CFG_FILT21_CFG_POS               (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR11_FILTER_CFG_FILT21_RESET                 (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR11_FILTER_CFG_FILT21_BYPASS                (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_FILTER2 filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR11_FILTER_CFG_FILT21_SEL_MASK              (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR11_FILTER_CFG_FILT21_SEL_POS               (5UL)


/*
 * Select from 12 comparator output
 */
#define PDSS_INTR11_FILTER_CFG_FILT21_INPUT_SEL_MASK        (0x00003c00UL) /* <10:13> R:RW:0: */
#define PDSS_INTR11_FILTER_CFG_FILT21_INPUT_SEL_POS         (10UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR11_FILTER_CFG_FILT21_DPSLP_MODE            (1UL << 14) /* <14:14> R:RW:0: */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR11_FILTER_CFG_FILT22_EN                    (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR11_FILTER_CFG_FILT22_CFG_MASK              (0x00030000UL) /* <16:17> R:RW:0: */
#define PDSS_INTR11_FILTER_CFG_FILT22_CFG_POS               (16UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR11_FILTER_CFG_FILT22_RESET                 (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR11_FILTER_CFG_FILT22_BYPASS                (1UL << 19) /* <19:19> R:RW:0: */


/*
 * #of clock CLK_FILTER2 filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR11_FILTER_CFG_FILT22_SEL_MASK              (0x01f00000UL) /* <20:24> R:RW:0: */
#define PDSS_INTR11_FILTER_CFG_FILT22_SEL_POS               (20UL)


/*
 * Select from 12 comparator output
 */
#define PDSS_INTR11_FILTER_CFG_FILT22_INPUT_SEL_MASK        (0x1e000000UL) /* <25:28> R:RW:0: */
#define PDSS_INTR11_FILTER_CFG_FILT22_INPUT_SEL_POS         (25UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR11_FILTER_CFG_FILT22_DPSLP_MODE            (1UL << 29) /* <29:29> R:RW:0: */


/*
 * INTR11 Status 0
 */
#define PDSS_INTR11_STATUS_0_ADDRESS                        (0x400a04c4UL)
#define PDSS_INTR11_STATUS_0                                (*(volatile uint32_t *)(0x400a04c4UL))
#define PDSS_INTR11_STATUS_0_DEFAULT                        (0x00000000UL)

/*
 * The status of CLK_FILTER2 HS filter edge detectors 1-2
 */
#define PDSS_INTR11_STATUS_0_STATUS2_MASK                   (0x00000003UL) /* <0:1> RW:R:0: */
#define PDSS_INTR11_STATUS_0_STATUS2_POS                    (0UL)


/*
 * 1-2 HS Filtered output
 */
#define PDSS_INTR11_STATUS_0_FILT2_MASK                     (0x0000000cUL) /* <2:3> RW:R:0: */
#define PDSS_INTR11_STATUS_0_FILT2_POS                      (2UL)


/*
 * INTR11 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin from HS filters
 */
#define PDSS_INTR11_ADDRESS                                 (0x400a04c8UL)
#define PDSS_INTR11                                         (*(volatile uint32_t *)(0x400a04c8UL))
#define PDSS_INTR11_DEFAULT                                 (0x00000000UL)

/*
 * Change in edge of HS filter edge detectors (wakeup interrupt from deepsleep)
 * Check the  INTR11_STATUS_0.STATUS2 value
 */
#define PDSS_INTR11_FILT2_EDGE_CHANGED_MASK                 (0x00000003UL) /* <0:1> RW1S:RW1C:0: */
#define PDSS_INTR11_FILT2_EDGE_CHANGED_POS                  (0UL)


/*
 * INTR11 Interrupt Set
 */
#define PDSS_INTR11_SET_ADDRESS                             (0x400a04ccUL)
#define PDSS_INTR11_SET                                     (*(volatile uint32_t *)(0x400a04ccUL))
#define PDSS_INTR11_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR11_SET_FILT2_EDGE_CHANGED_MASK             (0x00000003UL) /* <0:1> A:RW1S:0: */
#define PDSS_INTR11_SET_FILT2_EDGE_CHANGED_POS              (0UL)


/*
 * INTR11 interrupt Mask
 */
#define PDSS_INTR11_MASK_ADDRESS                            (0x400a04d0UL)
#define PDSS_INTR11_MASK                                    (*(volatile uint32_t *)(0x400a04d0UL))
#define PDSS_INTR11_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR11_MASK_FILT2_EDGE_CHANGED_MASK_MASK       (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_INTR11_MASK_FILT2_EDGE_CHANGED_MASK_POS        (0UL)


/*
 * INTR11 interrupt Masked
 */
#define PDSS_INTR11_MASKED_ADDRESS                          (0x400a04d4UL)
#define PDSS_INTR11_MASKED                                  (*(volatile uint32_t *)(0x400a04d4UL))
#define PDSS_INTR11_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR11_MASKED_FILT2_EDGE_CHANGED_MASKED_MASK    (0x00000003UL) /* <0:1> RW:R:0: */
#define PDSS_INTR11_MASKED_FILT2_EDGE_CHANGED_MASKED_POS    (0UL)


/*
 * INTR13 Status
 */
#define PDSS_INTR13_STATUS_ADDRESS                          (0x400a04dcUL)
#define PDSS_INTR13_STATUS                                  (*(volatile uint32_t *)(0x400a04dcUL))
#define PDSS_INTR13_STATUS_DEFAULT                          (0x00000000UL)

/*
 * The status of out_d_ocp from the s8usbpdv2_csa_scp_top
 */
#define PDSS_INTR13_STATUS_CSA_OCP_STATUS                   (1UL << 8) /* <8:8> RW:R:0:CSA_SCP_V2_LSCSA_EN */


/*
 * out_d_ocp Filtered output
 */
#define PDSS_INTR13_STATUS_CSA_OCP_FILT                     (1UL << 9) /* <9:9> RW:R:0:CSA_SCP_V2_LSCSA_EN */


/*
 * The status of s8usbpdv2_csa_scp_top.out_d_scp
 */
#define PDSS_INTR13_STATUS_CSA_SCP_STATUS                   (1UL << 10) /* <10:10> RW:R:0:CSA_SCP_V2_LSCSA_EN */


/*
 * s8usbpdv2_csa_scp_top.out_d_scp Filtered output
 */
#define PDSS_INTR13_STATUS_CSA_SCP_FILT                     (1UL << 11) /* <11:11> RW:R:0:CSA_SCP_V2_LSCSA_EN */


#define PDSS_INTR13_STATUS_LSCSA_LTRANDET_H2L_STATUS        (1UL << 20) /* <20:20> RW:R:0:V2_LSCSA_EN */


#define PDSS_INTR13_STATUS_LSCSA_LTRANDET_H2L_FILT          (1UL << 21) /* <21:21> RW:R:0:V2_LSCSA_EN */


#define PDSS_INTR13_STATUS_LSCSA_LTRANDET_L2H_STATUS        (1UL << 22) /* <22:22> RW:R:0:V2_LSCSA_EN */


#define PDSS_INTR13_STATUS_LSCSA_LTRANDET_L2H_FILT          (1UL << 23) /* <23:23> RW:R:0:V2_LSCSA_EN */


/*
 * INTR13 interrupt Cause.
 */
#define PDSS_INTR13_ADDRESS                                 (0x400a04e0UL)
#define PDSS_INTR13                                         (*(volatile uint32_t *)(0x400a04e0UL))
#define PDSS_INTR13_DEFAULT                                 (0x00000000UL)

/*
 * out_d_ocp changed (wakeup interrupt from deepsleep)
 * Check the  INTR13_STATUS.CSA_OCP_STATUS value
 */
#define PDSS_INTR13_CSA_OCP_CHANGED                         (1UL << 4) /* <4:4> RW1S:RW1C:0:CSA_SCP_V2_LSCSA_EN */


/*
 * s8usbpdv2_csa_scp_top.out_d_scp changed (wakeup interrupt from deepsleep)
 * Check the INTR13_STATUS.CSA_SCP_STATUS value
 */
#define PDSS_INTR13_CSA_SCP_CHANGED                         (1UL << 5) /* <5:5> RW1S:RW1C:0:CSA_SCP_V2_LSCSA_EN */


#define PDSS_INTR13_LSCSA_LTRANDET_H2L_CHANGED              (1UL << 10) /* <10:10> RW1S:RW1C:0:V2_LSCSA_EN */


#define PDSS_INTR13_LSCSA_LTRANDET_L2H_CHANGED              (1UL << 11) /* <11:11> RW1S:RW1C:0:V2_LSCSA_EN */


/*
 * INTR13 Interrupt Set
 */
#define PDSS_INTR13_SET_ADDRESS                             (0x400a04e4UL)
#define PDSS_INTR13_SET                                     (*(volatile uint32_t *)(0x400a04e4UL))
#define PDSS_INTR13_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_CSA_OCP_CHANGED                     (1UL << 4) /* <4:4> A:RW1S:0:CSA_SCP_V2_LSCSA_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_CSA_SCP_CHANGED                     (1UL << 5) /* <5:5> A:RW1S:0:CSA_SCP_V2_LSCSA_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_LSCSA_LTRANDET_H2L_CHANGED          (1UL << 10) /* <10:10> A:RW1S:0:V2_LSCSA_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_LSCSA_LTRANDET_L2H_CHANGED          (1UL << 11) /* <11:11> A:RW1S:0:V2_LSCSA_EN */


/*
 * INTR13 interrupt Mask
 */
#define PDSS_INTR13_MASK_ADDRESS                            (0x400a04e8UL)
#define PDSS_INTR13_MASK                                    (*(volatile uint32_t *)(0x400a04e8UL))
#define PDSS_INTR13_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_CSA_OCP_CHANGED_MASK               (1UL << 4) /* <4:4> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_CSA_SCP_CHANGED_MASK               (1UL << 5) /* <5:5> R:RW:0:CSA_SCP_V2_LSCSA_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_LSCSA_LTRANDET_H2L_CHANGED_MASK    (1UL << 10) /* <10:10> R:RW:0:V2_LSCSA_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_LSCSA_LTRANDET_L2H_CHANGED_MASK    (1UL << 11) /* <11:11> R:RW:0:V2_LSCSA_EN */


/*
 * INTR13 interrupt Masked
 */
#define PDSS_INTR13_MASKED_ADDRESS                          (0x400a04ecUL)
#define PDSS_INTR13_MASKED                                  (*(volatile uint32_t *)(0x400a04ecUL))
#define PDSS_INTR13_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_CSA_OCP_CHANGED_MASKED           (1UL << 4) /* <4:4> RW:R:0:CSA_SCP_V2_LSCSA_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_CSA_SCP_CHANGED_MASKED           (1UL << 5) /* <5:5> RW:R:0:CSA_SCP_V2_LSCSA_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_LSCSA_LTRANDET_H2L_CHANGED_MASKED    (1UL << 10) /* <10:10> RW:R:0:V2_LSCSA_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_LSCSA_LTRANDET_L2H_CHANGED_MASKED    (1UL << 11) /* <11:11> RW:R:0:V2_LSCSA_EN */


/*
 * CSA SCP HardIP High/Low Speed Filter and Edge detector configuration for
 * OCP and SCP detection
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_ADDRESS                  (0x400a04f0UL)
#define PDSS_INTR13_CFG_CSA_SCP_HS                          (*(volatile uint32_t *)(0x400a04f0UL))
#define PDSS_INTR13_CFG_CSA_SCP_HS_DEFAULT                  (0x00200400UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN          (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS     (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_RESET       (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_BYPASS      (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_POS     (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_DPSLP_MODE       (1UL << 10) /* <10:10> R:RW:1: */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_EN          (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_CFG_MASK    (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_CFG_POS     (12UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_RESET       (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_BYPASS      (1UL << 15) /* <15:15> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_SEL_MASK    (0x001f0000UL) /* <16:20> R:RW:0: */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_SEL_POS     (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_DPSLP_MODE       (1UL << 21) /* <21:21> R:RW:1: */


/*
 * INTR0 Cause. These are the active interrupts get reflected on interrupt_usbpd
 * pin.
 */
#define PDSS_INTR0_ADDRESS                                  (0x400a0500UL)
#define PDSS_INTR0                                          (*(volatile uint32_t *)(0x400a0500UL))
#define PDSS_INTR0_DEFAULT                                  (0x00000000UL)

/*
 * Receive a Good non-GoodCRC-message Data Packet Complete. Indicates that
 * the Receive Packet has been received in its entirety.  The received packet
 * had no CRC and no KCHAR error.
 * If this interrupt is not cleared, then RX_OVER_RUN will be set on the
 * next new data and the new data won't be written into RX SRAM.
 */
#define PDSS_INTR0_RCV_GOOD_PACKET_COMPLETE                 (1UL << 0) /* <0:0> RW1S:RW1C:0:PD_EN */


/*
 * Receive a Bad non-GoodCRC-message Data Packet Complete. Indicates that
 * the Receive Packet has been received in its entirety.  The received packet
 * had CRC or KCHAR error.
 */
#define PDSS_INTR0_RCV_BAD_PACKET_COMPLETE                  (1UL << 1) /* <1:1> RW1S:RW1C:0:PD_EN */


/*
 * Receive a SOP. FW should read SOP_TYPE_DETECTED for the SOP type
 */
#define PDSS_INTR0_RX_SOP                                   (1UL << 2) /* <2:2> RW1S:RW1C:0:PD_EN */


/*
 * Receive GoodCRC-message Complete. Indicates that the GoodCRC-message is
 * stored in RX_GOODCRC_MSG register.
 * The received GoodCRC-message had no CRC error and no KCHAR error
 */
#define PDSS_INTR0_RCV_GOODCRC_MSG_COMPLETE                 (1UL << 3) /* <3:3> RW1S:RW1C:0:PD_EN */


/*
 * Receive the expted GoodCRC-message based on the RX_EXPECT_GOODCRC_MSG
 * register. Indicates that the expected GoodCRC-message is stored in RX_GOODCRC_MSG
 * register.
 * The received expected GoodCRC-message had no CRC error and no KCHAR error
 * This interrupt gets evaluated on end of every packet (except hard reset)
 * and needs to be cleared.
 * For Correct usage of the interrupt:
 * This interrupt should be cleared on every packet if set.
 * RCV_GOOGCRC_MSG_COMPLETE should be cleared before new good crc response
 * comes else RX_GOODCRC_MSG will not get updated.
 */
#define PDSS_INTR0_RCV_EXPT_GOODCRC_MSG_COMPLETE            (1UL << 4) /* <4:4> RW1S:RW1C:0:PD_EN */


/*
 * Received Symbol wasn't a valid EOP K-Code.  It should be evaludated after
 * RCV_PACKET_COMPLETE.
 */
#define PDSS_INTR0_EOP_ERROR                                (1UL << 5) /* <5:5> RW1S:RW1C:0:PD_EN */


/*
 * New data was received when the RCV_PACKET_COMPLETE is not cleared by CPU.
 */
#define PDSS_INTR0_RX_OVER_RUN                              (1UL << 6) /* <6:6> RW1S:RW1C:0:PD_EN */


/*
 * Transmitter done sending data packet.
 */
#define PDSS_INTR0_TX_PACKET_DONE                           (1UL << 7) /* <7:7> RW1S:RW1C:0:PD_EN */


/*
 * Transmitter done sending Hard Reset
 */
#define PDSS_INTR0_TX_HARD_RST_DONE                         (1UL << 8) /* <8:8> RW1S:RW1C:0:PD_EN */


/*
 * Received a REST. FW should read RST_TYPE for the type of RST.
 * Firmware should process this interrupt according to the USB-PD spec.
 * Hardware does not process the Reset packets other than providing this
 * interrupt.
 * Hardware will stop processing any pending transmit packet until this interrupt
 * is cleared.
 */
#define PDSS_INTR0_RCV_RST                                  (1UL << 9) /* <9:9> RW1S:RW1C:0:PD_EN */


/*
 * A GoodCRC message was transmitted.
 */
#define PDSS_INTR0_TX_GOODCRC_MSG_DONE                      (1UL << 10) /* <10:10> RW1S:RW1C:0:PD_EN */


/*
 * Valid Data detected on the CC line
 */
#define PDSS_INTR0_CC_VALID_DATA_DETECTED                   (1UL << 11) /* <11:11> RW1S:RW1C:0:PD_EN */


/*
 * Valid Data got de-asserted on the CC line
 */
#define PDSS_INTR0_CC_NO_VALID_DATA_DETECTED                (1UL << 12) /* <12:12> RW1S:RW1C:0:PD_EN */


/*
 * CRCReceiveTimer has expired
 */
#define PDSS_INTR0_CRC_RX_TIMER_EXP                         (1UL << 13) /* <13:13> RW1S:RW1C:0:PD_EN */


/*
 * Transmit Collision Type1:
 * Collsion is detected Due to TX_GO(TX Data)/RX has occurred
 */
#define PDSS_INTR0_COLLISION_TYPE1                          (1UL << 14) /* <14:14> RW1S:RW1C:0:PD_EN */


/*
 * Transmit Collision Type2:
 * Collsion is detected  due to TX-RETRY/RX has occurred
 */
#define PDSS_INTR0_COLLISION_TYPE2                          (1UL << 15) /* <15:15> RW1S:RW1C:0:PD_EN */


/*
 * Transmit Collision Type3:
 * Collsion is detected due to TX-GoodCrc_MSG/RX has occurred
 */
#define PDSS_INTR0_COLLISION_TYPE3                          (1UL << 16) /* <16:16> RW1S:RW1C:0:PD_EN */


/*
 * Transmit Collision Type4:
 * Collsion is detected due to TX_SEND_RST/RX has occurred
 */
#define PDSS_INTR0_COLLISION_TYPE4                          (1UL << 17) /* <17:17> RW1S:RW1C:0:PD_EN */


/*
 * Hardware has passed reading the data from Half or End of the TX SRAM Memory
 * Location
 */
#define PDSS_INTR0_TX_SRAM_HALF_END                         (1UL << 18) /* <18:18> RW1S:RW1C:0:KEEP_REG_BIT */


/*
 * Hardware has passed writing the data to Half or End of the RX SRAM Memory
 * Location
 */
#define PDSS_INTR0_RX_SRAM_HALF_END                         (1UL << 19) /* <19:19> RW1S:RW1C:0:KEEP_REG_BIT */


/*
 * TX_RETRY_ENABLE is cleared
 */
#define PDSS_INTR0_TX_RETRY_ENABLE_CLRD                     (1UL << 20) /* <20:20> RW1S:RW1C:0:KEEP_REG_BIT */


/*
 * Received Symbol wasn't a valid K-Code.
 */
#define PDSS_INTR0_KCHAR_ERROR                              (1UL << 21) /* <21:21> RW1S:RW1C:0:PD_EN */


/*
 * TX Data Output Enable of TX-CC is asserted
 */
#define PDSS_INTR0_TX_CC_DATA_OEN_ASSERT                    (1UL << 22) /* <22:22> RW1S:RW1C:0:PD_EN */


/*
 * TX Data Output Enable of TX-CC is de-asserted
 */
#define PDSS_INTR0_TX_CC_DATA_OEN_DEASSERT                  (1UL << 23) /* <23:23> RW1S:RW1C:0:PD_EN */


/*
 * The TX CC regulator is enabled
 */
#define PDSS_INTR0_TX_REGULATOR_ENABLED                     (1UL << 24) /* <24:24> RW1S:RW1C:0:PD_EN */


/*
 * The TX State Machine entered Idle state
 */
#define PDSS_INTR0_TX_STATE_IDLE                            (1UL << 25) /* <25:25> RW1S:RW1C:0:PD_EN */


/*
 * The RX State Machine entered Idle state
 */
#define PDSS_INTR0_RX_STATE_IDLE                            (1UL << 26) /* <26:26> RW1S:RW1C:0:PD_EN */


/*
 * Marks Completion of the ADC SAR1-4 conversion at the end of 8 cycles of
 * clk_sar when SAR_EN is "1"
 */
#define PDSS_INTR0_SAR_DONE                                 (1UL << 27) /* <27:27> RW1S:RW1C:0:ADC_NUM */


/*
 * INTR0 Set
 */
#define PDSS_INTR0_SET_ADDRESS                              (0x400a0504UL)
#define PDSS_INTR0_SET                                      (*(volatile uint32_t *)(0x400a0504UL))
#define PDSS_INTR0_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RCV_GOOD_PACKET_COMPLETE             (1UL << 0) /* <0:0> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RCV_BAD_PACKET_COMPLETE              (1UL << 1) /* <1:1> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RX_SOP                               (1UL << 2) /* <2:2> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RCV_GOODCRC_MSG_COMPLETE             (1UL << 3) /* <3:3> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RCV_EXPT_GOODCRC_MSG_COMPLETE        (1UL << 4) /* <4:4> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_EOP_ERROR                            (1UL << 5) /* <5:5> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RX_OVER_RUN                          (1UL << 6) /* <6:6> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_PACKET_DONE                       (1UL << 7) /* <7:7> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_HARD_RST_DONE                     (1UL << 8) /* <8:8> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RCV_RST                              (1UL << 9) /* <9:9> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_GOODCRC_MSG_DONE                  (1UL << 10) /* <10:10> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_CC_VALID_DATA_DETECTED               (1UL << 11) /* <11:11> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_CC_NO_VALID_DATA_DETECTED            (1UL << 12) /* <12:12> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_CRC_RX_TIMER_EXP                     (1UL << 13) /* <13:13> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_COLLISION_TYPE1                      (1UL << 14) /* <14:14> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_COLLISION_TYPE2                      (1UL << 15) /* <15:15> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_COLLISION_TYPE3                      (1UL << 16) /* <16:16> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_COLLISION_TYPE4                      (1UL << 17) /* <17:17> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_SRAM_HALF_END                     (1UL << 18) /* <18:18> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RX_SRAM_HALF_END                     (1UL << 19) /* <19:19> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_RETRY_ENABLE_CLRD                 (1UL << 20) /* <20:20> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_KCHAR_ERROR                          (1UL << 21) /* <21:21> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_CC_DATA_OEN_ASSERT                (1UL << 22) /* <22:22> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_CC_DATA_OEN_DEASSERT              (1UL << 23) /* <23:23> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_REGULATOR_ENABLED                 (1UL << 24) /* <24:24> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_STATE_IDLE                        (1UL << 25) /* <25:25> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RX_STATE_IDLE                        (1UL << 26) /* <26:26> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_SAR_DONE                             (1UL << 27) /* <27:27> A:RW1S:0:ADC_NUM */


/*
 * INTR0 Mask
 */
#define PDSS_INTR0_MASK_ADDRESS                             (0x400a0508UL)
#define PDSS_INTR0_MASK                                     (*(volatile uint32_t *)(0x400a0508UL))
#define PDSS_INTR0_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RCV_GOOD_PACKET_COMPLETE_MASK       (1UL << 0) /* <0:0> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RCV_BAD_PACKET_COMPLETE_MASK        (1UL << 1) /* <1:1> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RX_SOP_MASK                         (1UL << 2) /* <2:2> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RCV_GOODCRC_MSG_COMPLETE_MASK       (1UL << 3) /* <3:3> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RCV_EXPT_GOODCRC_MSG_COMPLETE_MASK    (1UL << 4) /* <4:4> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_EOP_ERROR_MASK                      (1UL << 5) /* <5:5> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RX_OVER_RUN_MASK                    (1UL << 6) /* <6:6> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_PACKET_DONE_MASK                 (1UL << 7) /* <7:7> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_HARD_RST_DONE_MASK               (1UL << 8) /* <8:8> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RCV_RST_MASK                        (1UL << 9) /* <9:9> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_GOODCRC_MSG_DONE_MASK            (1UL << 10) /* <10:10> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_CC_VALID_DATA_DETECTED_MASK         (1UL << 11) /* <11:11> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_CC_NO_VALID_DATA_DETECTED_MASK      (1UL << 12) /* <12:12> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_CRC_RX_TIMER_EXP_MASK               (1UL << 13) /* <13:13> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_COLLISION_TYPE1_MASK                (1UL << 14) /* <14:14> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_COLLISION_TYPE2_MASK                (1UL << 15) /* <15:15> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_COLLISION_TYPE3_MASK                (1UL << 16) /* <16:16> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_COLLISION_TYPE4_MASK                (1UL << 17) /* <17:17> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_SRAM_HALF_END_MASK               (1UL << 18) /* <18:18> R:RW:0:KEEP_REG_BIT */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RX_SRAM_HALF_END_MASK               (1UL << 19) /* <19:19> R:RW:0:KEEP_REG_BIT */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_RETRY_ENABLE_CLRD_MASK           (1UL << 20) /* <20:20> R:RW:0:KEEP_REG_BIT */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_KCHAR_ERROR_MASK                    (1UL << 21) /* <21:21> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_CC_DATA_OEN_ASSERT_MASK          (1UL << 22) /* <22:22> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_CC_DATA_OEN_DEASSERT_MASK        (1UL << 23) /* <23:23> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_REGULATOR_ENABLED_MASK           (1UL << 24) /* <24:24> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_STATE_IDLE_MASK                  (1UL << 25) /* <25:25> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RX_STATE_IDLE_MASK                  (1UL << 26) /* <26:26> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_SAR_DONE_MASK                       (1UL << 27) /* <27:27> R:RW:0:ADC_NUM */


/*
 * INTR0 Masked
 */
#define PDSS_INTR0_MASKED_ADDRESS                           (0x400a050cUL)
#define PDSS_INTR0_MASKED                                   (*(volatile uint32_t *)(0x400a050cUL))
#define PDSS_INTR0_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RCV_GOOD_PACKET_COMPLETE_MASKED    (1UL << 0) /* <0:0> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RCV_BAD_PACKET_COMPLETE_MASKED    (1UL << 1) /* <1:1> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RX_SOP_MASKED                     (1UL << 2) /* <2:2> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RCV_GOODCRC_MSG_COMPLETE_MASKED    (1UL << 3) /* <3:3> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RCV_EXPT_GOODCRC_MSG_COMPLETE_MASKED    (1UL << 4) /* <4:4> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_EOP_ERROR_MASKED                  (1UL << 5) /* <5:5> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RX_OVER_RUN_MASKED                (1UL << 6) /* <6:6> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_PACKET_DONE_MASKED             (1UL << 7) /* <7:7> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_HARD_RST_DONE_MASKED           (1UL << 8) /* <8:8> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RCV_RST_MASKED                    (1UL << 9) /* <9:9> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_GOODCRC_MSG_DONE_MASKED        (1UL << 10) /* <10:10> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_CC_VALID_DATA_DETECTED_MASKED     (1UL << 11) /* <11:11> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_CC_NO_VALID_DATA_DETECTED_MASKED    (1UL << 12) /* <12:12> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_CRC_RX_TIMER_EXP_MASKED           (1UL << 13) /* <13:13> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_COLLISION_TYPE1_MASKED            (1UL << 14) /* <14:14> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_COLLISION_TYPE2_MASKED            (1UL << 15) /* <15:15> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_COLLISION_TYPE3_MASKED            (1UL << 16) /* <16:16> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_COLLISION_TYPE4_MASKED            (1UL << 17) /* <17:17> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_SRAM_HALF_END_MASKED           (1UL << 18) /* <18:18> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RX_SRAM_HALF_END_MASKED           (1UL << 19) /* <19:19> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_RETRY_ENABLE_CLRD_MASKED       (1UL << 20) /* <20:20> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_KCHAR_ERROR_MASKED                (1UL << 21) /* <21:21> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_CC_DATA_OEN_ASSERT_MASKED      (1UL << 22) /* <22:22> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_CC_DATA_OEN_DEASSERT_MASKED    (1UL << 23) /* <23:23> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_REGULATOR_ENABLED_MASKED       (1UL << 24) /* <24:24> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_STATE_IDLE_MASKED              (1UL << 25) /* <25:25> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RX_STATE_IDLE_MASKED              (1UL << 26) /* <26:26> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_SAR_DONE_MASKED                   (1UL << 27) /* <27:27> RW:R:0:ADC_NUM */


/*
 * INTR2 Cause.  These are the active interrupts get reflected on interrupt_usbpd
 * pin.
 */
#define PDSS_INTR2_ADDRESS                                  (0x400a0510UL)
#define PDSS_INTR2                                          (*(volatile uint32_t *)(0x400a0510UL))
#define PDSS_INTR2_DEFAULT                                  (0x00000000UL)

/*
 * The interrupt is raised at the end of UI calculation during preamble.
 */
#define PDSS_INTR2_UI_CAL_DONE                              (1UL << 0) /* <0:0> RW1S:RW1C:0:PD_EN */


/*
 * The extended receive message detected
 */
#define PDSS_INTR2_EXTENDED_MSG_DET                         (1UL << 7) /* <7:7> RW1S:RW1C:0:PD_EN */


/*
 * The chunked-extended receive message detected
 */
#define PDSS_INTR2_CHUNK_DET                                (1UL << 8) /* <8:8> RW1S:RW1C:0:PD_EN */


/*
 * Hardware has passed writing the data to Half or End of the RX SRAM Memory
 * Location but CPU has not read the Data (RX_SRAM_HALF_EN not cleared bt
 * FW). This interrupt should be cleared only after the end of the RX packet.
 */
#define PDSS_INTR2_RX_SRAM_OVER_FLOW                        (1UL << 9) /* <9:9> RW1S:RW1C:0:KEEP_REG_BIT */


/*
 * Hardware has passed reading the data to Half or End of the TX SRAM Memory
 * Location but CPU has not wrote the Data (TX_SRAM_HALF_EN not cleared bt
 * FW). This interrupt should be cleared only after the end of the TX packet.
 */
#define PDSS_INTR2_TX_SRAM_UNDER_FLOW                       (1UL << 10) /* <10:10> RW1S:RW1C:0:KEEP_REG_BIT */


/*
 * VREG Switching is complete
 */
#define PDSS_INTR2_VREG20V_SWITCH_DONE                      (1UL << 15) /* <15:15> RW1S:RW1C:0:KEEP_REG_BIT */


/*
 * The discharge protection has triggered
 */
#define PDSS_INTR2_DISCHG_FAILSAFE_DETECTED_MASK            (0x00c00000UL) /* <22:23> RW1S:RW1C:0:DISCHG_PROT_NUM */
#define PDSS_INTR2_DISCHG_FAILSAFE_DETECTED_POS             (22UL)


/*
 * INTR2 Set
 */
#define PDSS_INTR2_SET_ADDRESS                              (0x400a0514UL)
#define PDSS_INTR2_SET                                      (*(volatile uint32_t *)(0x400a0514UL))
#define PDSS_INTR2_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_UI_CAL_DONE                          (1UL << 0) /* <0:0> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_EXTENDED_MSG_DET                     (1UL << 7) /* <7:7> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_CHUNK_DET                            (1UL << 8) /* <8:8> A:RW1S:0:PD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_RX_SRAM_OVER_FLOW                    (1UL << 9) /* <9:9> A:RW1S:0:KEEP_REG_BIT */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_TX_SRAM_UNDER_FLOW                   (1UL << 10) /* <10:10> A:RW1S:0:KEEP_REG_BIT */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_VREG20V_SWITCH_DONE                  (1UL << 15) /* <15:15> A:RW1S:0:KEEP_REG_BIT */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_DISCHG_FAILSAFE_DETECTED_MASK        (0x00c00000UL) /* <22:23> A:RW1S:0:DISCHG_PROT_NUM */
#define PDSS_INTR2_SET_DISCHG_FAILSAFE_DETECTED_POS         (22UL)


/*
 * INTR2 Mask
 */
#define PDSS_INTR2_MASK_ADDRESS                             (0x400a0518UL)
#define PDSS_INTR2_MASK                                     (*(volatile uint32_t *)(0x400a0518UL))
#define PDSS_INTR2_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_UI_CAL_DONE_MASK                    (1UL << 0) /* <0:0> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_EXTENDED_MSG_DET_MASK               (1UL << 7) /* <7:7> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_CHUNK_DET_MASK                      (1UL << 8) /* <8:8> R:RW:0:PD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_RX_SRAM_OVER_FLOW_MASK              (1UL << 9) /* <9:9> R:RW:0:KEEP_REG_BIT */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_TX_SRAM_UNDER_FLOW_MASK             (1UL << 10) /* <10:10> R:RW:0:KEEP_REG_BIT */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_VREG20V_SWITCH_DONE_MASK            (1UL << 15) /* <15:15> R:RW:0:KEEP_REG_BIT */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_DISCHG_FAILSAFE_DETECTED_MASK_MASK    (0x00c00000UL) /* <22:23> R:RW:0:DISCHG_PROT_NUM */
#define PDSS_INTR2_MASK_DISCHG_FAILSAFE_DETECTED_MASK_POS    (22UL)


/*
 * INTR2 Masked
 */
#define PDSS_INTR2_MASKED_ADDRESS                           (0x400a051cUL)
#define PDSS_INTR2_MASKED                                   (*(volatile uint32_t *)(0x400a051cUL))
#define PDSS_INTR2_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_UI_CAL_DONE_MASKED                (1UL << 0) /* <0:0> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_EXTENDED_MSG_DET_MASKED           (1UL << 7) /* <7:7> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_CHUNK_DET_MASKED                  (1UL << 8) /* <8:8> RW:R:0:PD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_RX_SRAM_OVER_FLOW_MASKED          (1UL << 9) /* <9:9> RW:R:0:KEEP_REG_BIT */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_TX_SRAM_UNDER_FLOW_MASKED         (1UL << 10) /* <10:10> RW:R:0:KEEP_REG_BIT */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_VREG20V_SWITCH_DONE_MASKED        (1UL << 15) /* <15:15> RW:R:0:KEEP_REG_BIT */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_DISCHG_FAILSAFE_DETECTED_MASKED_MASK    (0x00c00000UL) /* <22:23> RW:R:0:DISCHG_PROT_NUM */
#define PDSS_INTR2_MASKED_DISCHG_FAILSAFE_DETECTED_MASKED_POS    (22UL)


/*
 * INTR4 Cause for AFC. These are the active interrupts get reflected on
 * interrupt_usbpd pin.
 */
#define PDSS_INTR4_ADDRESS                                  (0x400a0520UL)
#define PDSS_INTR4                                          (*(volatile uint32_t *)(0x400a0520UL))
#define PDSS_INTR4_DEFAULT                                  (0x00000000UL)

/*
 * Interrupt whenever Ping (16UIs) is received. This is common for both master
 * and slave mode
 */
#define PDSS_INTR4_AFC_PING_RECVD                           (1UL << 0) /* <0:0> RW1S:RW1C:0:BCH_DET_NUM */


/*
 * This interrupt fires when state machine goes to idle:
 *
 * In master mode: this will happen when:
 *    - Just Ping mode: Ping is sent and either Ping is received or timeout
 * happens
 *    - Ping+ Data Mode: Ping is sent, then Ping is received, then data is
 * sent, slave data is received along with
 *       final ping, master final ping transmitted and slave final ping received
 * or any timeout happens.
 *
 * This interrupt can be used as master interrupt to sample all received
 * data from slave
 * In slave mode: this will happened when:
 *    - Ping transmitted in response to master Ping.
 *
 * All data bytes transmitted in response to master V_I_Byte request, then
 * master ping is received and final slave ping is sent.
 */
#define PDSS_INTR4_AFC_SM_IDLE                              (1UL << 12) /* <12:12> RW1S:RW1C:0:BCH_DET_NUM */


/*
 * This bit is set whenever state machine is expecting response from link
 * partner but it never gets response. This could be due to Ping response
 * timeout, data response timeout etc. The status register can be read which
 * states which was the last state before timeout was declared.
 */
#define PDSS_INTR4_AFC_TIMEOUT                              (1UL << 16) /* <16:16> RW1S:RW1C:0:BCH_DET_NUM */


/*
 * Indicated 1 was seen on DMinus for RESET_UI_COUNT number of Uis
 */
#define PDSS_INTR4_AFC_RX_RESET                             (1UL << 20) /* <20:20> RW1S:RW1C:0:BCH_DET_NUM */


/*
 * On this interrupt FW should read/update the AFC_PING_RECVD register
 */
#define PDSS_INTR4_UPDATE_PING_PONG                         (1UL << 24) /* <24:24> RW1S:RW1C:0:BCH_DET_NUM */


/*
 * This interrupt is set when a AFC master request is seen while Slave is
 * trying to send data.
 */
#define PDSS_INTR4_AFC_ERROR                                (1UL << 28) /* <28:28> RW1S:RW1C:0:BCH_DET_NUM */


/*
 * INTR4 Set
 */
#define PDSS_INTR4_SET_ADDRESS                              (0x400a0524UL)
#define PDSS_INTR4_SET                                      (*(volatile uint32_t *)(0x400a0524UL))
#define PDSS_INTR4_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_SET_AFC_PING_RECVD                       (1UL << 0) /* <0:0> A:RW1S:0:BCH_DET_NUM */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_SET_AFC_SM_IDLE                          (1UL << 12) /* <12:12> A:RW1S:0:BCH_DET_NUM */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_SET_AFC_TIMEOUT                          (1UL << 16) /* <16:16> A:RW1S:0:BCH_DET_NUM */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_SET_AFC_RX_RESET                         (1UL << 20) /* <20:20> A:RW1S:0:BCH_DET_NUM */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_SET_UPDATE_PING_PONG                     (1UL << 24) /* <24:24> A:RW1S:0:BCH_DET_NUM */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_SET_AFC_ERROR                            (1UL << 28) /* <28:28> A:RW1S:0:BCH_DET_NUM */


/*
 * INTR4 Mask
 */
#define PDSS_INTR4_MASK_ADDRESS                             (0x400a0528UL)
#define PDSS_INTR4_MASK                                     (*(volatile uint32_t *)(0x400a0528UL))
#define PDSS_INTR4_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_MASK_AFC_PING_RECVD_MASK                 (1UL << 0) /* <0:0> R:RW:0:BCH_DET_NUM */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_MASK_AFC_SM_IDLE_MASK                    (1UL << 12) /* <12:12> R:RW:0:BCH_DET_NUM */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_MASK_AFC_TIMEOUT_MASK                    (1UL << 16) /* <16:16> R:RW:0:BCH_DET_NUM */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_MASK_AFC_RX_RESET_MASK                   (1UL << 20) /* <20:20> R:RW:0:BCH_DET_NUM */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_MASK_UPDATE_PING_PONG_MASK               (1UL << 24) /* <24:24> R:RW:0:BCH_DET_NUM */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR4_MASK_AFC_ERROR_MASK                      (1UL << 28) /* <28:28> R:RW:0:BCH_DET_NUM */


/*
 * INTR4 Masked
 */
#define PDSS_INTR4_MASKED_ADDRESS                           (0x400a052cUL)
#define PDSS_INTR4_MASKED                                   (*(volatile uint32_t *)(0x400a052cUL))
#define PDSS_INTR4_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR4_MASKED_AFC_PING_RECVD_MASKED             (1UL << 0) /* <0:0> RW:R:0:BCH_DET_NUM */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR4_MASKED_AFC_SM_IDLE_MASKED                (1UL << 12) /* <12:12> RW:R:0:BCH_DET_NUM */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR4_MASKED_AFC_TIMEOUT_MASKED                (1UL << 16) /* <16:16> RW:R:0:BCH_DET_NUM */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR4_MASKED_AFC_RX_RESET_MASKED               (1UL << 20) /* <20:20> RW:R:0:BCH_DET_NUM */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR4_MASKED_UPDATE_PING_PONG_MASKED           (1UL << 24) /* <24:24> RW:R:0:BCH_DET_NUM */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR4_MASKED_AFC_ERROR_MASKED                  (1UL << 28) /* <28:28> RW:R:0:BCH_DET_NUM */


/*
 * INTR6 Cause. These are the active interrupts get reflected on interrupt_usbpd
 * pin.
 */
#define PDSS_INTR6_ADDRESS                                  (0x400a0530UL)
#define PDSS_INTR6                                          (*(volatile uint32_t *)(0x400a0530UL))
#define PDSS_INTR6_DEFAULT                                  (0x00000000UL)

/*
 * Hardware will maintain internal Dplus pulse count. Anytime the pulse count
 * is greater than 0, this interrupt will be set.
 */
#define PDSS_INTR6_QC_3_D_P_PULSE_RCVD                      (1UL << 0) /* <0:0> RW1S:RW1C:0:BCH_DET_NUM */


/*
 * Hardware will maintain internal Dminus pulse count. Anytime the pulse
 * count is greater than 0, this interrupt will be set.
 */
#define PDSS_INTR6_QC_3_D_M_PULSE_RCVD                      (1UL << 4) /* <4:4> RW1S:RW1C:0:BCH_DET_NUM */


/*
 * This is used when QC3.0 is implemented for portable device which sends
 * voltage increment/decrement requests.
 * It indicates that hardware has sent the required increment or decrement
 * requests (as programmed) on Dplus or Dminus
 */
#define PDSS_INTR6_QC_3_DEVICE_REQ_SENT                     (1UL << 8) /* <8:8> RW1S:RW1C:0:BCH_DET_NUM */


/*
 * INTR6 Set
 */
#define PDSS_INTR6_SET_ADDRESS                              (0x400a0534UL)
#define PDSS_INTR6_SET                                      (*(volatile uint32_t *)(0x400a0534UL))
#define PDSS_INTR6_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR6_SET_QC_3_D_P_PULSE_RCVD                  (1UL << 0) /* <0:0> A:RW1S:0:BCH_DET_NUM */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR6_SET_QC_3_D_M_PULSE_RCVD                  (1UL << 4) /* <4:4> A:RW1S:0:BCH_DET_NUM */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR6_SET_QC_3_DEVICE_REQ_SENT                 (1UL << 8) /* <8:8> A:RW1S:0:BCH_DET_NUM */


/*
 * INTR6 Mask
 */
#define PDSS_INTR6_MASK_ADDRESS                             (0x400a0538UL)
#define PDSS_INTR6_MASK                                     (*(volatile uint32_t *)(0x400a0538UL))
#define PDSS_INTR6_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR6_MASK_QC_3_D_P_PULSE_RCVD_MASK            (1UL << 0) /* <0:0> R:RW:0:BCH_DET_NUM */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR6_MASK_QC_3_D_M_PULSE_RCVD_MASK            (1UL << 4) /* <4:4> R:RW:0:BCH_DET_NUM */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR6_MASK_QC_3_DEVICE_REQ_SENT_MASK           (1UL << 8) /* <8:8> R:RW:0:BCH_DET_NUM */


/*
 * INTR6 Masked
 */
#define PDSS_INTR6_MASKED_ADDRESS                           (0x400a053cUL)
#define PDSS_INTR6_MASKED                                   (*(volatile uint32_t *)(0x400a053cUL))
#define PDSS_INTR6_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR6_MASKED_QC_3_D_P_PULSE_RCVD_MASKED        (1UL << 0) /* <0:0> RW:R:0:BCH_DET_NUM */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR6_MASKED_QC_3_D_M_PULSE_RCVD_MASKED        (1UL << 4) /* <4:4> RW:R:0:BCH_DET_NUM */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR6_MASKED_QC_3_DEVICE_REQ_SENT_MASKED       (1UL << 8) /* <8:8> RW:R:0:BCH_DET_NUM */


/*
 * INTR8 Cause. These are the active interrupts get reflected on interrupt_usbpd
 * pin.
 */
#define PDSS_INTR8_ADDRESS                                  (0x400a0540UL)
#define PDSS_INTR8                                          (*(volatile uint32_t *)(0x400a0540UL))
#define PDSS_INTR8_DEFAULT                                  (0x00000000UL)

/*
 * Indicates the timeout condition for Minimum Variable Frequency for secondary
 * controller.
 */
#define PDSS_INTR8_PASC_VAR_TMAX_TIMEOUT                    (1UL << 0) /* <0:0> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Indicates the secondary controller has encountered MAX frequency in QR-mode
 */
#define PDSS_INTR8_PASC_VAR_TMIN_TIMEOUT                    (1UL << 1) /* <1:1> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Inidcates the timeout condition for Maximum Audio Frequency for secondary
 * controller.
 */
#define PDSS_INTR8_PASC_AUD_TMIN_TIMEOUT                    (1UL << 2) /* <2:2> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Inidcates the timeout condition for Minimum Audio Frequency for secondary
 * controller.
 */
#define PDSS_INTR8_PASC_AUD_TMAX_TIMEOUT                    (1UL << 3) /* <3:3> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Inidicates the maximum pulse width for Secodnary FET ("gdrv_in") reached
 * for secondary controller.
 */
#define PDSS_INTR8_PASC_GDRV_IN_MAX_WIDTH_TIMEOUT           (1UL << 4) /* <4:4> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Inidicates the maximum pulse width for Primary FET ("ptdrv_in") reached
 * for secondary controller.
 */
#define PDSS_INTR8_PASC_PTDRV_IN_MAX_WIDTH_TIMEOUT          (1UL << 5) /* <5:5> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Indicates the secondary controller has hit Fix frequency time
 */
#define PDSS_INTR8_PASC_FIX_FREQ_TIMEOUT                    (1UL << 6) /* <6:6> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * NSN timeout occurred
 */
#define PDSS_INTR8_PASC_NSN_IDLE_TIMEOUT                    (1UL << 7) /* <7:7> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Calibration of PTDRV to ZCDF-in is complete
 */
#define PDSS_INTR8_PASC_LOOP_CAL_DONE                       (1UL << 8) /* <8:8> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Secondary controller has entered burst mode
 */
#define PDSS_INTR8_PASC_BURST_ENTRY                         (1UL << 9) /* <9:9> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Loop switched from CCM to DCM
 */
#define PDSS_INTR8_PASC_CCM_2_DCM_CHG                       (1UL << 10) /* <10:10> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Loop switched from DCM to CCM
 */
#define PDSS_INTR8_PASC_DCM_2_CCM_CHG                       (1UL << 11) /* <11:11> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Indicates gdrv width is smaller than turn-off width
 */
#define PDSS_INTR8_GDRV_LESS_THAN_TURN_OFF                  (1UL << 12) /* <12:12> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Indicates gdrv width has exceeded turn-off width
 */
#define PDSS_INTR8_GDRV_GREATER_THAN_TURN_OFF               (1UL << 13) /* <13:13> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * NSN OUT asserted when PTDRV is high
 */
#define PDSS_INTR8_GDRV_CONTENTION                          (1UL << 14) /* <14:14> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Secondary gate driver on time is less than min width
 */
#define PDSS_INTR8_GDRV_INPUT_WIDTH_LESS_THAN_MIN           (1UL << 15) /* <15:15> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * Calibration has failed due to NSN_OUT being seen during PTDRV high or
 * NSN has timed out
 */
#define PDSS_INTR8_CAL_FAIL                                 (1UL << 16) /* <16:16> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * The PASC entered Idle state
 */
#define PDSS_INTR8_PASC_IDLE                                (1UL << 17) /* <17:17> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * FF INTEG OUT timeout occurred
 */
#define PDSS_INTR8_PASC_FF_INTEG_OUT_IDLE_TIMEOUT           (1UL << 19) /* <19:19> RW1S:RW1C:0:PASC2_EN */


/*
 * Valley Algorithm Safe Valley Reached
 */
#define PDSS_INTR8_VALLEY_ALGO_SAFE_VAL_RCHD                (1UL << 20) /* <20:20> RW1S:RW1C:0:PASC2_EN */


/*
 * Valley Algorithm Line in crossed LINE_IN_THRESH_0
 */
#define PDSS_INTR8_VALLEY_ALGO_LINE_IN_LOW_CROSS            (1UL << 21) /* <21:21> RW1S:RW1C:0:PASC2_EN */


/*
 * Valley Algorithm Line in crossed LINE_IN_THRESH_1
 */
#define PDSS_INTR8_VALLEY_ALGO_LINE_IN_HIGH_CROSS           (1UL << 22) /* <22:22> RW1S:RW1C:0:PASC2_EN */


/*
 * Interrupt for VBUS Current transition operation done.
 * If exit is requested by FW and if any of the IBTR_STATUS.DONE
 * is "1", then this interrupt will be set.
 */
#define PDSS_INTR8_IBTR_OPR_DONE                            (1UL << 28) /* <28:28> RW1S:RW1C:0:IBTR_EN */


/*
 * Interrupt for VBUS Current transition exit done
 * This interrupt bit will be set within one IBTR clock cycle of the IBTR_CTRL.EXIT
 * bit being set.
 */
#define PDSS_INTR8_IBTR_EXIT_DONE                           (1UL << 29) /* <29:29> RW1S:RW1C:0:IBTR_EN */


/*
 * Interrupt for VBUS transition operation done.
 * If exit is requested by FW and if any of the VBTR_STATUS.SRC_DONE OR VBTR_STATUS.SNK_DONE
 * is "1", then this interrupt will be set.
 */
#define PDSS_INTR8_VBTR_OPR_DONE                            (1UL << 30) /* <30:30> RW1S:RW1C:0:VBTR_EN */


/*
 * Interrupt for VBUS transition exit done
 * This interrupt bit will be set within one VBTR clock cycle of the VBTR_CTRL.EXIT
 * bit being set.
 */
#define PDSS_INTR8_VBTR_EXIT_DONE                           (1UL << 31) /* <31:31> RW1S:RW1C:0:VBTR_EN */


/*
 * INTR8 Set
 */
#define PDSS_INTR8_SET_ADDRESS                              (0x400a0544UL)
#define PDSS_INTR8_SET                                      (*(volatile uint32_t *)(0x400a0544UL))
#define PDSS_INTR8_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_VAR_TMAX_TIMEOUT                (1UL << 0) /* <0:0> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_VAR_TMIN_TIMEOUT                (1UL << 1) /* <1:1> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_AUD_TMIN_TIMEOUT                (1UL << 2) /* <2:2> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_AUD_TMAX_TIMEOUT                (1UL << 3) /* <3:3> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_GDRV_IN_MAX_WIDTH_TIMEOUT       (1UL << 4) /* <4:4> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_PTDRV_IN_MAX_WIDTH_TIMEOUT      (1UL << 5) /* <5:5> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_FIX_FREQ_TIMEOUT                (1UL << 6) /* <6:6> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_NSN_IDLE_TIMEOUT                (1UL << 7) /* <7:7> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_LOOP_CAL_DONE                   (1UL << 8) /* <8:8> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_BURST_ENTRY                     (1UL << 9) /* <9:9> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_CCM_2_DCM_CHG                   (1UL << 10) /* <10:10> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_DCM_2_CCM_CHG                   (1UL << 11) /* <11:11> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_GDRV_LESS_THAN_TURN_OFF              (1UL << 12) /* <12:12> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_GDRV_GREATER_THAN_TURN_OFF           (1UL << 13) /* <13:13> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_GDRV_CONTENTION                      (1UL << 14) /* <14:14> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_GDRV_INPUT_WIDTH_LESS_THAN_MIN       (1UL << 15) /* <15:15> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_CAL_FAIL                             (1UL << 16) /* <16:16> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_IDLE                            (1UL << 17) /* <17:17> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_PASC_FF_INTEG_OUT_IDLE_TIMEOUT       (1UL << 19) /* <19:19> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_VALLEY_ALGO_SAFE_VAL_RCHD            (1UL << 20) /* <20:20> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_VALLEY_ALGO_LINE_IN_LOW_CROSS        (1UL << 21) /* <21:21> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_VALLEY_ALGO_LINE_IN_HIGH_CROSS       (1UL << 22) /* <22:22> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_IBTR_OPR_DONE                        (1UL << 28) /* <28:28> A:RW1S:0:IBTR_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_IBTR_EXIT_DONE                       (1UL << 29) /* <29:29> A:RW1S:0:IBTR_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_VBTR_OPR_DONE                        (1UL << 30) /* <30:30> A:RW1S:0:VBTR_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_SET_VBTR_EXIT_DONE                       (1UL << 31) /* <31:31> A:RW1S:0:VBTR_EN */


/*
 * INTR8 Mask
 */
#define PDSS_INTR8_MASK_ADDRESS                             (0x400a0548UL)
#define PDSS_INTR8_MASK                                     (*(volatile uint32_t *)(0x400a0548UL))
#define PDSS_INTR8_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_VAR_TMAX_TIMEOUT_MASK          (1UL << 0) /* <0:0> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_VAR_TMIN_TIMEOUT_MASK          (1UL << 1) /* <1:1> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_AUD_TMIN_TIMEOUT_MASK          (1UL << 2) /* <2:2> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_AUD_TMAX_TIMEOUT_MASK          (1UL << 3) /* <3:3> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_GDRV_IN_MAX_WIDTH_TIMEOUT_MASK    (1UL << 4) /* <4:4> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_PTDRV_IN_MAX_WIDTH_TIMEOUT_MASK    (1UL << 5) /* <5:5> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_FIX_FREQ_TIMEOUT_MASK          (1UL << 6) /* <6:6> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_NSN_IDLE_TIMEOUT_MASK          (1UL << 7) /* <7:7> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_LOOP_CAL_DONE_MASK             (1UL << 8) /* <8:8> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_BURST_ENTRY_MASK               (1UL << 9) /* <9:9> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_CCM_2_DCM_CHG_MASK             (1UL << 10) /* <10:10> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_DCM_2_CCM_CHG_MASK             (1UL << 11) /* <11:11> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_GDRV_LESS_THAN_TURN_OFF_MASK        (1UL << 12) /* <12:12> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_GDRV_GREATER_THAN_TURN_OFF_MASK     (1UL << 13) /* <13:13> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_GDRV_CONTENTION_MASK                (1UL << 14) /* <14:14> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_GDRV_INPUT_WIDTH_LESS_THAN_MIN_MASK    (1UL << 15) /* <15:15> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_CAL_FAIL_MASK                       (1UL << 16) /* <16:16> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_IDLE_MASK                      (1UL << 17) /* <17:17> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_PASC_FF_INTEG_OUT_IDLE_TIMEOUT_MASK    (1UL << 19) /* <19:19> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_VALLEY_ALGO_SAFE_VAL_RCHD_MASK      (1UL << 20) /* <20:20> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_VALLEY_ALGO_LINE_IN_LOW_CROSS_MASK    (1UL << 21) /* <21:21> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_VALLEY_ALGO_LINE_IN_HIGH_CROSS_MASK    (1UL << 22) /* <22:22> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_IBTR_OPR_DONE_MASK                  (1UL << 28) /* <28:28> R:RW:0:IBTR_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_IBTR_EXIT_DONE_MASK                 (1UL << 29) /* <29:29> R:RW:0:IBTR_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_VBTR_OPR_DONE_MASK                  (1UL << 30) /* <30:30> R:RW:0:VBTR_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASK_VBTR_EXIT_DONE_MASK                 (1UL << 31) /* <31:31> R:RW:0:VBTR_EN */


/*
 * INTR8 Masked
 */
#define PDSS_INTR8_MASKED_ADDRESS                           (0x400a054cUL)
#define PDSS_INTR8_MASKED                                   (*(volatile uint32_t *)(0x400a054cUL))
#define PDSS_INTR8_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_VAR_TMAX_TIMEOUT_MASKED      (1UL << 0) /* <0:0> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_VAR_TMIN_TIMEOUT_MASKED      (1UL << 1) /* <1:1> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_AUD_TMIN_TIMEOUT_MASKED      (1UL << 2) /* <2:2> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_AUD_TMAX_TIMEOUT_MASKED      (1UL << 3) /* <3:3> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_GDRV_IN_MAX_WIDTH_TIMEOUT_MASKED    (1UL << 4) /* <4:4> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_PTDRV_IN_MAX_WIDTH_TIMEOUT_MASKED    (1UL << 5) /* <5:5> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_FIX_FREQ_TIMEOUT_MASKED      (1UL << 6) /* <6:6> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_NSN_IDLE_TIMEOUT_MASKED      (1UL << 7) /* <7:7> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_LOOP_CAL_DONE_MASKED         (1UL << 8) /* <8:8> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_BURST_ENTRY_MASKED           (1UL << 9) /* <9:9> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_CCM_2_DCM_CHG_MASKED         (1UL << 10) /* <10:10> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_PASC_DCM_2_CCM_CHG_MASKED         (1UL << 11) /* <11:11> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_GDRV_LESS_THAN_TURN_OFF_MASKED    (1UL << 12) /* <12:12> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_GDRV_GREATER_THAN_TURN_OFF_MASKED    (1UL << 13) /* <13:13> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_GDRV_CONTENTION_MASKED            (1UL << 14) /* <14:14> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_GDRV_INPUT_WIDTH_LESS_THAN_MIN_MASKED    (1UL << 15) /* <15:15> RW:R:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASKED_CAL_FAIL_MASKED                   (1UL << 16) /* <16:16> RW:R:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASKED_PASC_IDLE_MASKED                  (1UL << 17) /* <17:17> RW:R:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASKED_PASC_FF_INTEG_OUT_IDLE_TIMEOUT_MASKED    (1UL << 19) /* <19:19> RW:R:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASKED_VALLEY_ALGO_SAFE_VAL_RCHD_MASKED    (1UL << 20) /* <20:20> RW:R:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASKED_VALLEY_ALGO_LINE_IN_LOW_CROSS_MASKED    (1UL << 21) /* <21:21> RW:R:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR8_MASKED_VALLEY_ALGO_LINE_IN_HIGH_CROSS_MASKED    (1UL << 22) /* <22:22> RW:R:0:PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_IBTR_OPR_DONE_MASKED              (1UL << 28) /* <28:28> RW:R:0:IBTR_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_IBTR_EXIT_DONE_MASKED             (1UL << 29) /* <29:29> RW:R:0:IBTR_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_VBTR_OPR_DONE_MASKED              (1UL << 30) /* <30:30> RW:R:0:VBTR_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR8_MASKED_VBTR_EXIT_DONE_MASKED             (1UL << 31) /* <31:31> RW:R:0:VBTR_EN */


/*
 * S8PDSV2 HardIP Filter and Edge detector config for LTRAN_DET L2H & H2L
 */
#define PDSS_INTR13_CFG_LTRANDET_ADDRESS                    (0x400a0550UL)
#define PDSS_INTR13_CFG_LTRANDET                            (*(volatile uint32_t *)(0x400a0550UL))
#define PDSS_INTR13_CFG_LTRANDET_DEFAULT                    (0x00510144UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_L2H_FILT_EN    (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_L2H_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:2: */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_L2H_FILT_CFG_POS    (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_L2H_FILT_RESET    (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_L2H_FILT_BYPASS    (1UL << 6) /* <6:6> R:RW:1: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_L2H_FILT_SEL    (1UL << 7) /* <7:7> R:RW:0: */


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_L2H_DPSLP_MODE    (1UL << 8) /* <8:8> R:RW:1: */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_H2L_FILT_EN    (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_H2L_FILT_CFG_MASK    (0x00018000UL) /* <15:16> R:RW:2: */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_H2L_FILT_CFG_POS    (15UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_H2L_FILT_RESET    (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_H2L_FILT_BYPASS    (1UL << 20) /* <20:20> R:RW:1: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_H2L_FILT_SEL    (1UL << 21) /* <21:21> R:RW:0: */


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR13_CFG_LTRANDET_CSA_LTRANDET_H2L_DPSLP_MODE    (1UL << 22) /* <22:22> R:RW:1: */


/*
 * IP DDFT0/1 and TR_OUT0/1 Selections
 */
#define PDSS_DDFT_MUX_ADDRESS                               (0x400a0580UL)
#define PDSS_DDFT_MUX                                       (*(volatile uint32_t *)(0x400a0580UL))
#define PDSS_DDFT_MUX_DEFAULT                               (0x00000000UL)

/*
 * This register selects the following inputs to be routed to DDFT0 and tr_out[0]
 * ports of the IP.
 * DDFT0 for [63:55]:
 *        63: If CC_DFP_NOTXRX_EN: vcmp_fs_fx_scan
 *              If PAG1S: pasc_ddft1
 *        62: pasc_ddft0
 *        61: vcmp_cc_vbus_fx_scan
 *            60:57 small_vconn_fx_scan
 *            56 clk_isnk
 *            55 clk_refgen
 * TR_OUT[0] for [63:55]:
 *            63: vcmp_cc_vbus_fx_scan
 *            62:55: If CCG3PA2: pwm_dischg_en_o
 *                      If CCG6:
 *                                62:58 5'd0
 *                                57: (comp_out_lv[4] | comp_out_lv[5])
 *                                56: comp_out_lv[5]
 *                                55: comp_out_lv[4]
 *                    if PAG1S:
 *                         56:  pasc_ddft1
 *                         55: pasc_ddft0
 *                      If ACG1F:
 *                                62:59 4'd0
 *                                58: vcmp_fs_fx_scan
 *                                57: (comp_out_lv[3] | comp_out_lv[4])
 *                                56: comp_out_lv[4]
 *                                55: comp_out_lv[3]
 * 54 pd2_reg_control_enable_vcr
 * 53 cc1_ovp_fx_scan
 * 52 cc2_ovp_fx_scan
 * 51 cc1_ocp_fx_scan
 * 50 cc2_ocp_fx_scan
 * 49 adc_cmp_out_fx_scan[2]
 * 48 adc_cmp_out_fx_scan[3]
 * 47 1'b0--intr_swap_queue_set
 * 46 1'b0--intr_swap_unstable_set
 * 45 intr_swap_disconnect_set
 * 44 intr_swap_rcvd_set
 * 43 intr_swap_pulse_set
 * 42 intr_swapt_command_done_set
 * 41 intr_ddft1
 * 40 intr_ddft0
 * 39 ncell_ddft1
 * 38 ncell_ddft0
 * 37 bbctrl_ddft1 -- CCG7D
 * 36 bbctrl_ddft0 -- CCG7D
 * 35 intr_hpd_queue_set
 * 34 intr_hpd_unstable_set
 * 33 intr_hpd_unpluged_set
 * 32 intr_hpd_pluged_set
 * 31 intr_hpd_irq_set
 * 30 intr_hpdt_command_done_set
 * 29 hpdin_fx_scan
 * 28 ddft_collision_src[4]
 * 27 ddft_collision_src[3]
 * 26 ddft_collision_src[2]
 * 25 ddft_collision_src[1]
 * 24 ddft_collision_src[0]
 * 23 adc_cmp_out_fx_scan[0]
 * 22 adc_cmp_out_fx_scan[1]
 * 21 v5v_fx_scan
 * 20 ddft_cc_core_rx_data
 * 19 swapr_in_fx_scan
 * 18 cc_ctrl_0_tx_en
 * 17 ddft_cc_tx_data_eop
 * 16 ddft_cc_tx_data_valid
 * 15 clk_tx  (This is 0 for tr_out[0])
 * 14 vconn2_fx_scan
 * 13 vconn1_fx_scan
 * 12 vcmp_dn_fx_scan
 * 11 vcmp_la_fx_scan
 * 10 vcmp_up_fx_scan
 * 9 ddft_sop_valid
 * 8 ddft_rx_eop
 * 7 ddft_raw_cc_rx_valid
 * 6 ddft_cc_rx_bit_en
 * 5 ddft_cc_core_tx_data
 * 4 sip_cc_tx_data
 * 3 refgen_clk_out  (This is 0 for tr_out[0])
 * 2 cc1_fx_scan
 * 1 cc2_fx_scan
 * 0 0:DDFT0 from previous mxusbpd instantiation if any
 */
#define PDSS_DDFT_MUX_DDFT0_SEL_MASK                        (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_DDFT_MUX_DDFT0_SEL_POS                         (0UL)


/*
 * This register selects the following inputs to be routed to DDFT0 and tr_out[0]
 * ports of the IP.
 * DDFT0 for [63:55]:
 *        63: If CC_DFP_NOTXRX_EN: vcmp_fs_fx_scan
 *              If PAG1S: pasc_ddft1
 *        62: pasc_ddft0
 *        61: vcmp_cc_vbus_fx_scan
 *            60:57 small_vconn_fx_scan
 *            56 clk_isnk
 *            55 clk_refgen
 * TR_OUT[0] for [63:55]:
 *            63: vcmp_cc_vbus_fx_scan
 *            62:55: If CCG3PA2: pwm_dischg_en_o
 *                      If CCG6:
 *                                62:58 5'd0
 *                                57: (comp_out_lv[4] | comp_out_lv[5])
 *                                56: comp_out_lv[5]
 *                                55: comp_out_lv[4]
 *                    if PAG1S:
 *                         56:  pasc_ddft1
 *                         55: pasc_ddft0
 *                      If ACG1F:
 *                                62:59 4'd0
 *                                58: vcmp_fs_fx_scan
 *                                57: (comp_out_lv[3] | comp_out_lv[4])
 *                                56: comp_out_lv[4]
 *                                55: comp_out_lv[3]
 * 54 pd2_reg_control_enable_vcr
 * 53 cc1_ovp_fx_scan
 * 52 cc2_ovp_fx_scan
 * 51 cc1_ocp_fx_scan
 * 50 cc2_ocp_fx_scan
 * 49 adc_cmp_out_fx_scan[2]
 * 48 adc_cmp_out_fx_scan[3]
 * 47 1'b0--intr_swap_queue_set
 * 46 1'b0--intr_swap_unstable_set
 * 45 intr_swap_disconnect_set
 * 44 intr_swap_rcvd_set
 * 43 intr_swap_pulse_set
 * 42 intr_swapt_command_done_set
 * 41 intr_ddft1
 * 40 intr_ddft0
 * 39 ncell_ddft1
 * 38 ncell_ddft0
 * 37 bbctrl_ddft1 -- CCG7D
 * 36 bbctrl_ddft0 -- CCG7D
 * 35 intr_hpd_queue_set
 * 34 intr_hpd_unstable_set
 * 33 intr_hpd_unpluged_set
 * 32 intr_hpd_pluged_set
 * 31 intr_hpd_irq_set
 * 30 intr_hpdt_command_done_set
 * 29 hpdin_fx_scan
 * 28 ddft_collision_src[4]
 * 27 ddft_collision_src[3]
 * 26 ddft_collision_src[2]
 * 25 ddft_collision_src[1]
 * 24 ddft_collision_src[0]
 * 23 adc_cmp_out_fx_scan[0]
 * 22 adc_cmp_out_fx_scan[1]
 * 21 v5v_fx_scan
 * 20 ddft_cc_core_rx_data
 * 19 swapr_in_fx_scan
 * 18 cc_ctrl_0_tx_en
 * 17 ddft_cc_tx_data_eop
 * 16 ddft_cc_tx_data_valid
 * 15 clk_tx  (This is 0 for tr_out[0])
 * 14 vconn2_fx_scan
 * 13 vconn1_fx_scan
 * 12 vcmp_dn_fx_scan
 * 11 vcmp_la_fx_scan
 * 10 vcmp_up_fx_scan
 * 9 ddft_sop_valid
 * 8 ddft_rx_eop
 * 7 ddft_raw_cc_rx_valid
 * 6 ddft_cc_rx_bit_en
 * 5 ddft_cc_core_tx_data
 * 4 sip_cc_tx_data
 * 3 refgen_clk_out  (This is 0 for tr_out[0])
 * 2 cc1_fx_scan
 * 1 cc2_fx_scan
 * 0 0:DDFT0 from previous mxusbpd instantiation if any
 */
#define PDSS_DDFT_MUX_DDFT1_SEL_MASK                        (0x00000fc0UL) /* <6:11> R:RW:0: */
#define PDSS_DDFT_MUX_DDFT1_SEL_POS                         (6UL)


/*
 * Interrupt DDFT Selections
 */
#define PDSS_INTR_DDFT_MUX_ADDRESS                          (0x400a0584UL)
#define PDSS_INTR_DDFT_MUX                                  (*(volatile uint32_t *)(0x400a0584UL))
#define PDSS_INTR_DDFT_MUX_DEFAULT                          (0x00000000UL)

/*
 * 253 MXUSBPD_REGS_INST.intr8_valley_algo_line_in_high_cross
 * 252 MXUSBPD_REGS_INST.intr8_valley_algo_line_in_low_cross
 * 251 MXUSBPD_REGS_INST.intr8_valley_algo_safe_val_rchd
 * 250 CCG7D_INTR_DDFT1 -- specific source selectable using CCG7D_INTR_DDFT_MUX
 * register
 * 249 CCG7D_INTR_DDFT0 -- specific source selectable using CCG7D_INTR_DDFT_MUX
 * register
 * 248 MXUSBPD_REGS_INST.intr1_set_vcmp_fs_changed
 * 247 MXUSBPD_REGS_INST.intr15_cause_pds_vreg_vbus_done
 * 246 MXUSBPD_REGS_INST.intr15_ea_cc_flag_changed_done
 * 245 MXUSBPD_REGS_INST.intr15_ff_ov_changed
 * 244 MXUSBPD_REGS_INST.intr15_ff_uv_changed
 * 243 MXUSBPD_REGS_INST.intr15_zcdf_out_changed
 * 242 MXUSBPD_REGS_INST.intr15_peakdet_out_changed
 * 241 MXUSBPD_REGS_INST.intr15_peakdet_rst_out_changed
 * 240 MXUSBPD_REGS_INST.intr15_peakdet_clcmp_raw_out_changed
 * 239 MXUSBPD_REGS_INST.intr15_sr_sen_ovp_out_changed
 * 238 MXUSBPD_REGS_INST.intr15_pwm_out_changed
 * 237 MXUSBPD_REGS_INST.intr15_skip_out_changed
 * 236 MXUSBPD_REGS_INST.intr15_burst_exit_out_changed
 * 235 MXUSBPD_REGS_INST.intr15_pds_scp_changed
 * 234 MXUSBPD_REGS_INST.intr15_nsn_out_changed
 * 233 MXUSBPD_REGS_INST.intr15_zcd_out_changed
 * 232 MXUSBPD_REGS_INST.intr8_pasc_idle
 * 231 MXUSBPD_REGS_INST.intr8_vbtr_exit_done
 * 230 MXUSBPD_REGS_INST.intr8_vbtr_opr_done
 * 229 MXUSBPD_REGS_INST.intr8_pasc_dcm_2_ccm_chg
 * 228 MXUSBPD_REGS_INST.intr8_pasc_ccm_2_dcm_chg
 * 227 MXUSBPD_REGS_INST.intr8_gdrv_less_than_turn_off
 * 226 MXUSBPD_REGS_INST.intr8_gdrv_input_width_less_than_min
 * 225 MXUSBPD_REGS_INST.intr8_cal_fail
 * 224 MXUSBPD_REGS_INST.intr8_gdrv_contentiion
 * 223 MXUSBPD_REGS_INST.intr8_gdrv_greater_than_turn_off
 * 222 MXUSBPD_REGS_INST.intr8_pasc_loop_cal_done
 * 221 MXUSBPD_REGS_INST.intr8_pasc_burst_entry
 * 220 MXUSBPD_REGS_INST.intr8_pasc_var_tmin_timeout
 * 219 MXUSBPD_REGS_INST.intr8_pasc_nsn_idle_timeout
 * 218 MXUSBPD_REGS_INST.intr8_pasc_ff_ov_idle_timeout
 * 217 MXUSBPD_REGS_INST.intr8_pasc_fix_freq_timeout
 * 216 MXUSBPD_REGS_INST.intr8_pasc_var_tmax_timeout
 * 215 MXUSBPD_REGS_INST.intr8_pasc_aud_tmin_timeout
 * 214 MXUSBPD_REGS_INST.intr8_pasc_aud_tmax_timeout
 * 213 MXUSBPD_REGS_INST.intr8_pasc_gdrv_in_max_width_timeout
 * 212 MXUSBPD_REGS_INST.intr8_pasc_max_width_timeout
 * 211 MXUSBPD_REGS_INST.intr1_lf_cntr_match
 * 210 MXUSBPD_REGS_INST.intr13_cause_cc_vbus_changed
 * 209 MXUSBPD_REGS_INST.intr13_set_csa_vbus_ovp_changed
 * 208 MXUSBPD_REGS_INST.intr13_set_csa_comp_out_changed
 * 207 MXUSBPD_REGS_INST.intr13_set_csa_out_changed
 * 206 MXUSBPD_REGS_INST.intr13_set_csa_scp_changed
 * 205 MXUSBPD_REGS_INST.intr13_set_csa_ocp_changed
 * 204:181 MXUSBPD_REGS_INST.intr5_set_edge_changed,
 * 180:173 MXUSBPD_REGS_INST.intr3_set_sbu1_sbu2_ovp_changed,
 * 172:165 MXUSBPD_REGS_INST.intr7_set_clk_lf_edge_changed,
 * 164:157 MXUSBPD_REGS_INST.intr9_set_det_shv_det_changed,
 * 156:149 MXUSBPD_REGS_INST.intr9_set_bch_det_changed,
 * 148:145 MXUSBPD_REGS_INST.intr3_set_csa_oc_changed,
 * 144:141 MXUSBPD_REGS_INST.intr3_set_chgdet_changed,
 * 140:137 MXUSBPD_REGS_INST.intr3_set_vreg20_vbus_changed,
 * 136:133 MXUSBPD_REGS_INST.intr3_set_csa_vbus_changed,
 * 132:129 MXUSBPD_REGS_INST.intr9_set_qcom_rcvr_dm_changed,
 * 128:125 MXUSBPD_REGS_INST.intr9_set_qcom_rcvr_dp_changed,
 * 124:121 MXUSBPD_REGS_INST.intr9_set_shvreg_det_changed,
 * 120:117 MXUSBPD_REGS_INST.intr4_set_afc_ping_recvd,
 * 116:113 MXUSBPD_REGS_INST.intr4_set_afc_sm_idle,
 * 112:109 MXUSBPD_REGS_INST.intr4_set_afc_timeout,
 * 108:105 MXUSBPD_REGS_INST.intr4_set_afc_rx_reset,
 * 104:101 MXUSBPD_REGS_INST.intr4_set_update_ping_pong,
 * 100:97  MXUSBPD_REGS_INST.intr4_set_afc_error,
 * 96:93   MXUSBPD_REGS_INST.intr6_set_qc_3_d_p_pulse_rcvd,
 * 92:89   MXUSBPD_REGS_INST.intr6_set_qc_3_d_m_pulse_rcvd,
 * 88:85   MXUSBPD_REGS_INST.intr6_set_qc_3_device_req_sent,
 * 84:83   MXUSBPD_REGS_INST.intr11_set_filt2_edge_changed,
 * 82:81   MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[3:2],
 * 80      MXUSBPD_REGS_INST.intr3_set_vsys_changed,
 * 79      MXUSBPD_REGS_INST.intr1_set_cc2_ocp_changed,
 * 78      MXUSBPD_REGS_INST.intr1_set_cc1_ocp_changed,
 * 77      MXUSBPD_REGS_INST.intr1_set_cc2_ovp_changed,
 * 76      MXUSBPD_REGS_INST.intr1_set_cc1_ovp_changed,
 * 75      MXUSBPD_REGS_INST.intr1_set_drp_attached_detected,
 * 74      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[3],
 * 73      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[2],
 * 72      MXUSBPD_REGS_INST.intr0_set_sar_done[3],
 * 71      MXUSBPD_REGS_INST.intr0_set_sar_done[2],
 * 70      MXUSBPD_REGS_INST.intr1_set_vswap_vbus_less_5_done,
 * 69      MXUSBPD_REGS_INST.intr2_set_swap_command_done,
 * 68      1'b0
 * 67      1'b0
 * 66      MXUSBPD_REGS_INST.intr2_set_swap_disconnect,
 * 65      MXUSBPD_REGS_INST.intr2_set_swap_rcvd,
 * 64      MXUSBPD_REGS_INST.intr2_set_swap_pulse,
 * 63      MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[0],
 * 62      MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[1],
 * 61      MXUSBPD_REGS_INST.intr2_set_vreg20v_switch_done,
 * 60      MXUSBPD_REGS_INST.intr2_set_vddd_sw_switch_done,
 * 59      MXUSBPD_REGS_INST.intr2_set_chunk_det,
 * 58      MXUSBPD_REGS_INST.intr2_set_tx_sram_under_flow,
 * 57      MXUSBPD_REGS_INST.intr2_set_rx_sram_over_flow,
 * 56      1'b0
 * 55      1'b0
 * 54      1'b0
 * 53      MXUSBPD_REGS_INST.intr2_set_extended_msg_det,
 * 52      MXUSBPD_REGS_INST.intr2_set_hpdt_command_done,
 * 51      MXUSBPD_REGS_INST.intr2_set_hpd_queue,
 * 50      MXUSBPD_REGS_INST.intr2_set_hpd_unstable,
 * 49      MXUSBPD_REGS_INST.intr2_set_hpd_unpluged,
 * 48      MXUSBPD_REGS_INST.intr2_set_hpd_pluged,
 * 47      MXUSBPD_REGS_INST.intr2_set_hpd_irq,
 * 46      MXUSBPD_REGS_INST.intr2_set_ui_cal_done,
 * 45      1'b0
 * 44      1'b0
 * 43      1'b0
 * 42      1'b0
 * 41      MXUSBPD_REGS_INST.intr1_set_hpdin_changed,
 * 40      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[1],
 * 39      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[0],
 * 38      MXUSBPD_REGS_INST.intr1_set_v5v_changed,
 * 37      MXUSBPD_REGS_INST.intr1_set_vcmp_dn_changed,
 * 36      MXUSBPD_REGS_INST.intr1_set_vcmp_up_changed,
 * 35      MXUSBPD_REGS_INST.intr1_set_vcmp_la_changed,
 * 34      MXUSBPD_REGS_INST.intr1_set_cc2_changed,
 * 33      MXUSBPD_REGS_INST.intr1_set_cc1_changed,
 * 32      MXUSBPD_REGS_INST.intr1_set_vconn2_changed,
 * 31      MXUSBPD_REGS_INST.intr1_set_vconn1_changed,
 * 30      1'b0
 * 29      MXUSBPD_REGS_INST.intr0_set_sar_done[1],
 * 28      MXUSBPD_REGS_INST.intr0_set_rx_state_idle,
 * 27      MXUSBPD_REGS_INST.intr0_set_tx_state_idle,
 * 26      MXUSBPD_REGS_INST.intr0_set_tx_regulator_enabled,
 * 25      MXUSBPD_REGS_INST.intr0_set_tx_cc_data_oen_deassert,
 * 24      MXUSBPD_REGS_INST.intr0_set_tx_cc_data_oen_assert,
 * 23      MXUSBPD_REGS_INST.intr0_set_kchar_error,
 * 22      MXUSBPD_REGS_INST.intr0_set_tx_retry_enable_clrd,
 * 21      MXUSBPD_REGS_INST.intr0_set_rx_sram_half_end,
 * 20      MXUSBPD_REGS_INST.intr0_set_tx_sram_half_end,
 * 19      1'b0
 * 18      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type4,
 * 17      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type3,
 * 16      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type2,
 * 15      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type1
 * 14      MXUSBPD_REGS_INST.intr0_set_crc_rx_timer_exp,
 * 13      MXUSBPD_REGS_INST.intr0_set_cc_no_valid_data_detected,
 * 12      MXUSBPD_REGS_INST.intr0_set_cc_valid_data_detected,
 * 11      MXUSBPD_REGS_INST.intr0_set_tx_goodcrc_msg_done,
 * 10      MXUSBPD_REGS_INST.intr0_set_sar_done[0],
 * 9       MXUSBPD_REGS_INST.intr0_set_rcv_rst,
 * 8       MXUSBPD_REGS_INST.intr0_set_tx_hard_rst_done,
 * 7       MXUSBPD_REGS_INST.intr0_set_tx_packet_done,
 * 6       MXUSBPD_REGS_INST.intr0_set_rx_over_run,
 * 5       MXUSBPD_REGS_INST.intr0_set_eop_error,
 * 4       MXUSBPD_REGS_INST.intr0_set_rcv_expt_goodcrc_msg_complete,
 * 3       MXUSBPD_REGS_INST.intr0_set_rcv_goodcrc_msg_complete,
 * 2       MXUSBPD_REGS_INST.intr0_set_rx_sop,
 * 1       MXUSBPD_REGS_INST.intr0_set_rcv_bad_packet_complete,
 * 0       MXUSBPD_REGS_INST.intr0_set_rcv_good_packet_complete,
 */
#define PDSS_INTR_DDFT_MUX_INTR_DDFT0_SEL_MASK              (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_INTR_DDFT_MUX_INTR_DDFT0_SEL_POS               (0UL)


/*
 * 253 MXUSBPD_REGS_INST.intr8_valley_algo_line_in_high_cross
 * 252 MXUSBPD_REGS_INST.intr8_valley_algo_line_in_low_cross
 * 251 MXUSBPD_REGS_INST.intr8_valley_algo_safe_val_rchd
 * 250 CCG7D_INTR_DDFT1 -- specific source selectable using CCG7D_INTR_DDFT_MUX
 * register
 * 249 CCG7D_INTR_DDFT0 -- specific source selectable using CCG7D_INTR_DDFT_MUX
 * register
 * 248 MXUSBPD_REGS_INST.intr1_set_vcmp_fs_changed
 * 247 MXUSBPD_REGS_INST.intr15_cause_pds_vreg_vbus_done
 * 246 MXUSBPD_REGS_INST.intr15_ea_cc_flag_changed_done
 * 245 MXUSBPD_REGS_INST.intr15_ff_ov_changed
 * 244 MXUSBPD_REGS_INST.intr15_ff_uv_changed
 * 243 MXUSBPD_REGS_INST.intr15_zcdf_out_changed
 * 242 MXUSBPD_REGS_INST.intr15_peakdet_out_changed
 * 241 MXUSBPD_REGS_INST.intr15_peakdet_rst_out_changed
 * 240 MXUSBPD_REGS_INST.intr15_peakdet_clcmp_raw_out_changed
 * 239 MXUSBPD_REGS_INST.intr15_sr_sen_ovp_out_changed
 * 238 MXUSBPD_REGS_INST.intr15_pwm_out_changed
 * 237 MXUSBPD_REGS_INST.intr15_skip_out_changed
 * 236 MXUSBPD_REGS_INST.intr15_burst_exit_out_changed
 * 235 MXUSBPD_REGS_INST.intr15_pds_scp_changed
 * 234 MXUSBPD_REGS_INST.intr15_nsn_out_changed
 * 233 MXUSBPD_REGS_INST.intr15_zcd_out_changed
 * 232 MXUSBPD_REGS_INST.intr8_pasc_idle
 * 231 MXUSBPD_REGS_INST.intr8_vbtr_exit_done
 * 230 MXUSBPD_REGS_INST.intr8_vbtr_opr_done
 * 229 MXUSBPD_REGS_INST.intr8_pasc_dcm_2_ccm_chg
 * 228 MXUSBPD_REGS_INST.intr8_pasc_ccm_2_dcm_chg
 * 227 MXUSBPD_REGS_INST.intr8_gdrv_less_than_turn_off
 * 226 MXUSBPD_REGS_INST.intr8_gdrv_input_width_less_than_min
 * 225 MXUSBPD_REGS_INST.intr8_cal_fail
 * 224 MXUSBPD_REGS_INST.intr8_gdrv_contentiion
 * 223 MXUSBPD_REGS_INST.intr8_gdrv_greater_than_turn_off
 * 222 MXUSBPD_REGS_INST.intr8_pasc_loop_cal_done
 * 221 MXUSBPD_REGS_INST.intr8_pasc_burst_entry
 * 220 MXUSBPD_REGS_INST.intr8_pasc_var_tmin_timeout
 * 219 MXUSBPD_REGS_INST.intr8_pasc_nsn_idle_timeout
 * 218 MXUSBPD_REGS_INST.intr8_pasc_ff_ov_idle_timeout
 * 217 MXUSBPD_REGS_INST.intr8_pasc_fix_freq_timeout
 * 216 MXUSBPD_REGS_INST.intr8_pasc_var_tmax_timeout
 * 215 MXUSBPD_REGS_INST.intr8_pasc_aud_tmin_timeout
 * 214 MXUSBPD_REGS_INST.intr8_pasc_aud_tmax_timeout
 * 213 MXUSBPD_REGS_INST.intr8_pasc_gdrv_in_max_width_timeout
 * 212 MXUSBPD_REGS_INST.intr8_pasc_max_width_timeout
 * 211 MXUSBPD_REGS_INST.intr1_lf_cntr_match
 * 210 MXUSBPD_REGS_INST.intr13_cause_cc_vbus_changed
 * 209 MXUSBPD_REGS_INST.intr13_set_csa_vbus_ovp_changed
 * 208 MXUSBPD_REGS_INST.intr13_set_csa_comp_out_changed
 * 207 MXUSBPD_REGS_INST.intr13_set_csa_out_changed
 * 206 MXUSBPD_REGS_INST.intr13_set_csa_scp_changed
 * 205 MXUSBPD_REGS_INST.intr13_set_csa_ocp_changed
 * 204:181 MXUSBPD_REGS_INST.intr5_set_edge_changed,
 * 180:173 MXUSBPD_REGS_INST.intr3_set_sbu1_sbu2_ovp_changed,
 * 172:165 MXUSBPD_REGS_INST.intr7_set_clk_lf_edge_changed,
 * 164:157 MXUSBPD_REGS_INST.intr9_set_det_shv_det_changed,
 * 156:149 MXUSBPD_REGS_INST.intr9_set_bch_det_changed,
 * 148:145 MXUSBPD_REGS_INST.intr3_set_csa_oc_changed,
 * 144:141 MXUSBPD_REGS_INST.intr3_set_chgdet_changed,
 * 140:137 MXUSBPD_REGS_INST.intr3_set_vreg20_vbus_changed,
 * 136:133 MXUSBPD_REGS_INST.intr3_set_csa_vbus_changed,
 * 132:129 MXUSBPD_REGS_INST.intr9_set_qcom_rcvr_dm_changed,
 * 128:125 MXUSBPD_REGS_INST.intr9_set_qcom_rcvr_dp_changed,
 * 124:121 MXUSBPD_REGS_INST.intr9_set_shvreg_det_changed,
 * 120:117 MXUSBPD_REGS_INST.intr4_set_afc_ping_recvd,
 * 116:113 MXUSBPD_REGS_INST.intr4_set_afc_sm_idle,
 * 112:109 MXUSBPD_REGS_INST.intr4_set_afc_timeout,
 * 108:105 MXUSBPD_REGS_INST.intr4_set_afc_rx_reset,
 * 104:101 MXUSBPD_REGS_INST.intr4_set_update_ping_pong,
 * 100:97  MXUSBPD_REGS_INST.intr4_set_afc_error,
 * 96:93   MXUSBPD_REGS_INST.intr6_set_qc_3_d_p_pulse_rcvd,
 * 92:89   MXUSBPD_REGS_INST.intr6_set_qc_3_d_m_pulse_rcvd,
 * 88:85   MXUSBPD_REGS_INST.intr6_set_qc_3_device_req_sent,
 * 84:83   MXUSBPD_REGS_INST.intr11_set_filt2_edge_changed,
 * 82:81   MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[3:2],
 * 80      MXUSBPD_REGS_INST.intr3_set_vsys_changed,
 * 79      MXUSBPD_REGS_INST.intr1_set_cc2_ocp_changed,
 * 78      MXUSBPD_REGS_INST.intr1_set_cc1_ocp_changed,
 * 77      MXUSBPD_REGS_INST.intr1_set_cc2_ovp_changed,
 * 76      MXUSBPD_REGS_INST.intr1_set_cc1_ovp_changed,
 * 75      MXUSBPD_REGS_INST.intr1_set_drp_attached_detected,
 * 74      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[3],
 * 73      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[2],
 * 72      MXUSBPD_REGS_INST.intr0_set_sar_done[3],
 * 71      MXUSBPD_REGS_INST.intr0_set_sar_done[2],
 * 70      MXUSBPD_REGS_INST.intr1_set_vswap_vbus_less_5_done,
 * 69      MXUSBPD_REGS_INST.intr2_set_swap_command_done,
 * 68      1'b0
 * 67      1'b0
 * 66      MXUSBPD_REGS_INST.intr2_set_swap_disconnect,
 * 65      MXUSBPD_REGS_INST.intr2_set_swap_rcvd,
 * 64      MXUSBPD_REGS_INST.intr2_set_swap_pulse,
 * 63      MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[0],
 * 62      MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[1],
 * 61      MXUSBPD_REGS_INST.intr2_set_vreg20v_switch_done,
 * 60      MXUSBPD_REGS_INST.intr2_set_vddd_sw_switch_done,
 * 59      MXUSBPD_REGS_INST.intr2_set_chunk_det,
 * 58      MXUSBPD_REGS_INST.intr2_set_tx_sram_under_flow,
 * 57      MXUSBPD_REGS_INST.intr2_set_rx_sram_over_flow,
 * 56      1'b0
 * 55      1'b0
 * 54      1'b0
 * 53      MXUSBPD_REGS_INST.intr2_set_extended_msg_det,
 * 52      MXUSBPD_REGS_INST.intr2_set_hpdt_command_done,
 * 51      MXUSBPD_REGS_INST.intr2_set_hpd_queue,
 * 50      MXUSBPD_REGS_INST.intr2_set_hpd_unstable,
 * 49      MXUSBPD_REGS_INST.intr2_set_hpd_unpluged,
 * 48      MXUSBPD_REGS_INST.intr2_set_hpd_pluged,
 * 47      MXUSBPD_REGS_INST.intr2_set_hpd_irq,
 * 46      MXUSBPD_REGS_INST.intr2_set_ui_cal_done,
 * 45      1'b0
 * 44      1'b0
 * 43      1'b0
 * 42      1'b0
 * 41      MXUSBPD_REGS_INST.intr1_set_hpdin_changed,
 * 40      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[1],
 * 39      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[0],
 * 38      MXUSBPD_REGS_INST.intr1_set_v5v_changed,
 * 37      MXUSBPD_REGS_INST.intr1_set_vcmp_dn_changed,
 * 36      MXUSBPD_REGS_INST.intr1_set_vcmp_up_changed,
 * 35      MXUSBPD_REGS_INST.intr1_set_vcmp_la_changed,
 * 34      MXUSBPD_REGS_INST.intr1_set_cc2_changed,
 * 33      MXUSBPD_REGS_INST.intr1_set_cc1_changed,
 * 32      MXUSBPD_REGS_INST.intr1_set_vconn2_changed,
 * 31      MXUSBPD_REGS_INST.intr1_set_vconn1_changed,
 * 30      1'b0
 * 29      MXUSBPD_REGS_INST.intr0_set_sar_done[1],
 * 28      MXUSBPD_REGS_INST.intr0_set_rx_state_idle,
 * 27      MXUSBPD_REGS_INST.intr0_set_tx_state_idle,
 * 26      MXUSBPD_REGS_INST.intr0_set_tx_regulator_enabled,
 * 25      MXUSBPD_REGS_INST.intr0_set_tx_cc_data_oen_deassert,
 * 24      MXUSBPD_REGS_INST.intr0_set_tx_cc_data_oen_assert,
 * 23      MXUSBPD_REGS_INST.intr0_set_kchar_error,
 * 22      MXUSBPD_REGS_INST.intr0_set_tx_retry_enable_clrd,
 * 21      MXUSBPD_REGS_INST.intr0_set_rx_sram_half_end,
 * 20      MXUSBPD_REGS_INST.intr0_set_tx_sram_half_end,
 * 19      1'b0
 * 18      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type4,
 * 17      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type3,
 * 16      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type2,
 * 15      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type1
 * 14      MXUSBPD_REGS_INST.intr0_set_crc_rx_timer_exp,
 * 13      MXUSBPD_REGS_INST.intr0_set_cc_no_valid_data_detected,
 * 12      MXUSBPD_REGS_INST.intr0_set_cc_valid_data_detected,
 * 11      MXUSBPD_REGS_INST.intr0_set_tx_goodcrc_msg_done,
 * 10      MXUSBPD_REGS_INST.intr0_set_sar_done[0],
 * 9       MXUSBPD_REGS_INST.intr0_set_rcv_rst,
 * 8       MXUSBPD_REGS_INST.intr0_set_tx_hard_rst_done,
 * 7       MXUSBPD_REGS_INST.intr0_set_tx_packet_done,
 * 6       MXUSBPD_REGS_INST.intr0_set_rx_over_run,
 * 5       MXUSBPD_REGS_INST.intr0_set_eop_error,
 * 4       MXUSBPD_REGS_INST.intr0_set_rcv_expt_goodcrc_msg_complete,
 * 3       MXUSBPD_REGS_INST.intr0_set_rcv_goodcrc_msg_complete,
 * 2       MXUSBPD_REGS_INST.intr0_set_rx_sop,
 * 1       MXUSBPD_REGS_INST.intr0_set_rcv_bad_packet_complete,
 * 0       MXUSBPD_REGS_INST.intr0_set_rcv_good_packet_complete,
 */
#define PDSS_INTR_DDFT_MUX_INTR_DDFT1_SEL_MASK              (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_INTR_DDFT_MUX_INTR_DDFT1_SEL_POS               (8UL)


/*
 * NCELL DDFT Selections
 */
#define PDSS_NCELL_DDFT_MUX_ADDRESS                         (0x400a0588UL)
#define PDSS_NCELL_DDFT_MUX                                 (*(volatile uint32_t *)(0x400a0588UL))
#define PDSS_NCELL_DDFT_MUX_DEFAULT                         (0x00000000UL)

/*
 * 230: PMG1S3_NCELL_DDFT1 -- specific source selectable using PMG1S3_NCELL_DDFT_MUX
 * register
 * 229: PMG1S3_NCELL_DDFT0 -- specific source selectable using PMG1S3_NCELL_DDFT_MUX
 * register
 * 228 CCG7D_NCELL_DDFT1  -- specific source selectable using CCG7D_NCELL_DDFT_MUX
 * register
 * 227 CCG7D_NCELL_DDFT0  -- specific source selectable using CCG7D_NCELL_DDFT_MUX
 * register
 * 226   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_frs_cp_en_ctrl.ddft_faults_masked
 * 225   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_frs_cp_en_ctrl.ddft_async_fault_det
 * 224   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_frs_sw_en_ctrl.ddft_faults_masked
 * 223   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_frs_sw_en_ctrl.ddft_async_fault_det
 * 222   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_keep_off_disable_ctrl.ddft_faults_masked
 * 221   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_keep_off_disable_ctrl.ddft_async_fault_det
 * 220   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_en_ctrl.ddft_faults_masked
 * 219   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_en_ctrl.ddft_async_fault_det
 * 218   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_gdrv_en_ctrl.ddft_faults_masked
 * 217   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_gdrv_en_ctrl.ddft_async_fault_det
 * 216   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_cp_en_ctrl.ddft_faults_masked
 * 215   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_cp_en_ctrl.ddft_async_fault_det
 * 214 MXUSBPD_MMIO_INST.ngdo_ctrl_ngdo_en_lv
 * 213 MXUSBPD_MMIO_INST.ngdo_ctrl_cp_en
 * 212 MXUSBPD_MMIO_INST.pds_vreg_ctrl_vbg_en
 * 211 MXUSBPD_MMIO_INST.gdrv_ctrl_ptdrv_pulldn_en
 * 210 MXUSBPD_MMIO_INST.gdrv_ctrl_ptdrv_pullup_en
 * 209 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_ea_top.cc_flag
 * 208 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_ea_top.cc_comp_out
 * 207 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_ea_top.cc_det
 * 206 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_ea_top.cv_det
 * 205 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_vreg_top.vbus_det
 * 204 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_scp_top.scp_out
 * 203 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.ff_uv
 * 202 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.ff_ov
 * 201 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.peakdet_out
 * 200 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.peakdet_rst_out
 * 199 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.peakdet_clcmp_raw_out
 * 198 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.zcdf_out
 * 197 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.sr_sen_ovp_out
 * 196 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.nsn_out
 * 195 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.zcd_out
 * 194 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.peakdet_rst_raw_out
 * 193 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.peakdet_pkd_raw_out
 * 192 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.pwm_out
 * 191 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.skip_out
 * 190 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.burst_exit_out
 * 189 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.eacomp_out
 * 188 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.hclamp_out
 * 187 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.pwm_ramp_reset_out
 * 186 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_srsns_ctrl.ddft_faults_masked
 * 185 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_srsns_ctrl.ddft_async_fault_det
 * 184 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_srsns_ctrl.en_lv[0]
 * 183 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_ngdo_ctrl.ddft_faults_masked
 * 182 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_ngdo_ctrl.ddft_async_fault_det
 * 181 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_ngdo_ctrl.en_lv[0]
 * 180     MXUSBPD_HARD_TOP_INST.y_cc_ufp_nord.u_s8usbpd_cc_top.vcmp_vbus
 * 179     MXUSBPD_HARD_TOP_INST.y_csa_rcp.u_s8usbpd_csa_rcp_top.vbus_ovp_comp_out_lv
 * 178     MXUSBPD_HARD_TOP_INST.y_csa_rcp.u_s8usbpd_csa_rcp_top.rcp_comp_out_lv
 * 177     MXUSBPD_HARD_TOP_INST.y_csa_rcp.u_s8usbpd_csa_rcp_top.csa_out_d
 * 176     MXUSBPD_HARD_TOP_INST.y_csa_scp.u_s8usbpd_csa_scp_top.out_d_scp
 * 175     MXUSBPD_HARD_TOP_INST.y_csa_scp.u_s8usbpd_csa_scp_top.out_d_ocp
 * 174         MXUSBPD_HARD_TOP_INST.y_csa_rcp.clk_div2_lv
 * 173         MXUSBPD_HARD_TOP_INST.y_csa_rcp.clk_div4_lv
 * 172         MXUSBPD_HARD_TOP_INST.y_csa_rcp.clk_div8_lv
 * 171         MXUSBPD_HARD_TOP_INST.y_csa_rcp.clk_div16_lv
 * 170         MXUSBPD_HARD_TOP_INST.y_csa_rcp.rignosc_out_lv
 * 169         MXUSBPD_HARD_TOP_INST.y_csa_rcp.autozero_clk_lv
 * 168         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_pump_en_ctrl.ddft_faults_masked
 * 167         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_pump_en_ctrl.ddft_async_fault_det
 * 166         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_cc1_en_ctrl.ddft_faults_masked
 * 165         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_cc1_en_ctrl.ddft_async_fault_det
 * 164         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_cc1_en_ctrl.ddft_faults_masked
 * 163         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_cc1_en_ctrl.ddft_async_fault_det
 * 162:159 MXUSBPD_MMIO_INST.y_sbu20_sbu12_en_ctrl.u_mxusbpd_gate_driver_sbu20_sbu2_en_ctrl.ddft_faults_masked[3:0]
 * 158:155 MXUSBPD_MMIO_INST.y_sbu20_sbu12_en_ctrl.u_mxusbpd_gate_driver_sbu20_sbu2_en_ctrl.ddft_async_fault_det[3:0]
 * 154:151 MXUSBPD_MMIO_INST.y_sbu20_sbu12_en_ctrl.u_mxusbpd_gate_driver_sbu20_sbu1_en_ctrl.ddft_faults_masked[3:0]
 * 150:147 MXUSBPD_MMIO_INST.y_sbu20_sbu12_en_ctrl.u_mxusbpd_gate_driver_sbu20_sbu1_en_ctrl.ddft_async_fault_det[3:0]
 * 146:143 MXUSBPD_HARD_TOP_INST.y_ngdo.ngdo_ddft[3:0]
 * 142:139 MXUSBPD_MMIO_INST.ngdo_ddft_faults_masked[3:0]
 * 138:135 MXUSBPD_MMIO_INST.ngdo_ddft_async_fault_det[3:0]
 * 134:131 MXUSBPD_MMIO_INST.y_pgdo_pu_ctrl.u_mxusbpd_pgdo_pu_ctrl.pgdo_pu_ddft_faults_masked[3:0]
 * 130:127 MXUSBPD_MMIO_INST.y_pgdo_pu_ctrl.u_mxusbpd_pgdo_pu_ctrl.pgdo_pu_ddft_async_fault_det[3:0]
 * 126:123 MXUSBPD_MMIO_INST.y_pgdo_pu_ctrl.u_mxusbpd_pgdo_pu_ctrl.pgdo_pu_ctrl_pgdo_in_lv[3:0]
 * 122:119 MXUSBPD_MMIO_INST.y_pgdo_pu_ctrl.u_mxusbpd_pgdo_pu_ctrl.pgdo_pu_ctrl_pgdo_en_lv[3:0]
 * 118:115 MXUSBPD_MMIO_INST.y_pgdo_ctrl.u_mxusbpd_pgdo_ctrl.pgdo_ddft_faults_masked[3:0]
 * 114:111 MXUSBPD_MMIO_INST.y_pgdo_ctrl.u_mxusbpd_pgdo_ctrl.pgdo_ddft_async_fault_det[3:0]
 * 110:107 MXUSBPD_MMIO_INST.y_pgdo_ctrl.u_mxusbpd_pgdo_ctrl.pgdo_ctrl_pgdo_en_lv[3:0]
 * 106:99  MXUSBPD_MMIO_INST.y_ngdo_ctrl.u_mxusbpd_ngdo_ctrl.ngdo_ctrl_ngdo_pulldn_en_lv[7:0]
 * 98:91   MXUSBPD_MMIO_INST.y_ngdo_ctrl.u_mxusbpd_ngdo_ctrl.ngdo_ctrl_ngdo_en_lv[7:0]
 * 90:87   MXUSBPD_HARD_TOP_INST.y_cc_5vpump.u_s8usbpd_5vpump_top.pump5v_clkout_ddft[3:0]
 * 86      MXUSBPD_HARD_TOP_INST.y_vsys.u_s8usbpd_vddd_sw_top.vsys_fx_scan
 * 85:84   MXUSBPD_HARD_TOP_INST.hs_filt2_fx_scan[1:0]
 * 83:60   MXUSBPD_HARD_TOP_INST.hs_filt_fx_scan[23:0]
 * 59:52   MXUSBPD_HARD_TOP_INST.ls_filt_fx_scan[7:0]
 * 51:44   MXUSBPD_HARD_TOP_INST.y_det_shv.u_s8usbpd_det_shv_top.det_shv_fx_scan[7:0]
 * 43:36   MXUSBPD_HARD_TOP_INST.y_bch_det.u_s8usbpd_bch_chgdet_top.bch_det_fx_scan[7:0]
 * 35:32   MXUSBPD_HARD_TOP_INST.y_sbu20.u_s8usbpd_sbu20_sw_top.sbu1_ovp_fx_scan[3:0]
 * 31:28   MXUSBPD_HARD_TOP_INST.y_sbu20.u_s8usbpd_sbu20_sw_top.sbu2_ovp_fx_scan[3:0]
 * 27:24   MXUSBPD_HARD_TOP_INST.qcom_rcvr_dp_fx_scan[3:0]
 * 23:20   MXUSBPD_HARD_TOP_INST.qcom_rcvr_dm_fx_scan[3:0]
 * 19:16   MXUSBPD_HARD_TOP_INST.y_shvreg.u_s8usbpd_vreg_top.shvreg_vbus_fx_scan[3:0]
 * 15:12   MXUSBPD_HARD_TOP_INST.y_20vreg.u_s8usbpd_vreg_top.vreg_vbus_fx_scan[3:0]
 * 11:8    MXUSBPD_HARD_TOP_INST.y_csa.u_s8usbpd_csa_top.csa_vbus_fx_scan[3:0]
 * 7:4     MXUSBPD_HARD_TOP_INST.y_chgdet.u_s8usbpd_chgdet_top.chgdet_fx_scan[3:0]
 * 3:0     MXUSBPD_HARD_TOP_INST.y_csa.u_s8usbpd_csa_top.csa_oc_fx_scan[3:0]
 */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT0_SEL_MASK            (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT0_SEL_POS             (0UL)


/*
 * 230: PMG1S3_NCELL_DDFT1 -- specific source selectable using PMG1S3_NCELL_DDFT_MUX
 * register
 * 229: PMG1S3_NCELL_DDFT0 -- specific source selectable using PMG1S3_NCELL_DDFT_MUX
 * register
 * 228 CCG7D_NCELL_DDFT1  -- specific source selectable using CCG7D_NCELL_DDFT_MUX
 * register
 * 227 CCG7D_NCELL_DDFT0  -- specific source selectable using CCG7D_NCELL_DDFT_MUX
 * register
 * 226   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_frs_cp_en_ctrl.ddft_faults_masked
 * 225   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_frs_cp_en_ctrl.ddft_async_fault_det
 * 224   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_frs_sw_en_ctrl.ddft_faults_masked
 * 223   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_frs_sw_en_ctrl.ddft_async_fault_det
 * 222   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_keep_off_disable_ctrl.ddft_faults_masked
 * 221   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_keep_off_disable_ctrl.ddft_async_fault_det
 * 220   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_en_ctrl.ddft_faults_masked
 * 219   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_en_ctrl.ddft_async_fault_det
 * 218   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_gdrv_en_ctrl.ddft_faults_masked
 * 217   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_gdrv_en_ctrl.ddft_async_fault_det
 * 216   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_cp_en_ctrl.ddft_faults_masked
 * 215   MXUSBPD_MMIO_INST.y_ccg6df.u_mxusbpd_gate_driver_acg1f_ngdo_cp_en_ctrl.ddft_async_fault_det
 * 214 MXUSBPD_MMIO_INST.ngdo_ctrl_ngdo_en_lv
 * 213 MXUSBPD_MMIO_INST.ngdo_ctrl_cp_en
 * 212 MXUSBPD_MMIO_INST.pds_vreg_ctrl_vbg_en
 * 211 MXUSBPD_MMIO_INST.gdrv_ctrl_ptdrv_pulldn_en
 * 210 MXUSBPD_MMIO_INST.gdrv_ctrl_ptdrv_pullup_en
 * 209 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_ea_top.cc_flag
 * 208 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_ea_top.cc_comp_out
 * 207 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_ea_top.cc_det
 * 206 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_ea_top.cv_det
 * 205 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_vreg_top.vbus_det
 * 204 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_scp_top.scp_out
 * 203 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.ff_uv
 * 202 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.ff_ov
 * 201 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.peakdet_out
 * 200 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.peakdet_rst_out
 * 199 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.peakdet_clcmp_raw_out
 * 198 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.zcdf_out
 * 197 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.sr_sen_ovp_out
 * 196 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.nsn_out
 * 195 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.zcd_out
 * 194 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.peakdet_rst_raw_out
 * 193 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_srsense_top.peakdet_pkd_raw_out
 * 192 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.pwm_out
 * 191 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.skip_out
 * 190 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.burst_exit_out
 * 189 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.eacomp_out
 * 188 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.hclamp_out
 * 187 MXUSBPD_HARD_TOP_INST.y_pag1s.u_s8usbpd_pwm_top.pwm_ramp_reset_out
 * 186 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_srsns_ctrl.ddft_faults_masked
 * 185 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_srsns_ctrl.ddft_async_fault_det
 * 184 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_srsns_ctrl.en_lv[0]
 * 183 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_ngdo_ctrl.ddft_faults_masked
 * 182 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_ngdo_ctrl.ddft_async_fault_det
 * 181 MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_gate_driver_ngdo_ctrl.en_lv[0]
 * 180     MXUSBPD_HARD_TOP_INST.y_cc_ufp_nord.u_s8usbpd_cc_top.vcmp_vbus
 * 179     MXUSBPD_HARD_TOP_INST.y_csa_rcp.u_s8usbpd_csa_rcp_top.vbus_ovp_comp_out_lv
 * 178     MXUSBPD_HARD_TOP_INST.y_csa_rcp.u_s8usbpd_csa_rcp_top.rcp_comp_out_lv
 * 177     MXUSBPD_HARD_TOP_INST.y_csa_rcp.u_s8usbpd_csa_rcp_top.csa_out_d
 * 176     MXUSBPD_HARD_TOP_INST.y_csa_scp.u_s8usbpd_csa_scp_top.out_d_scp
 * 175     MXUSBPD_HARD_TOP_INST.y_csa_scp.u_s8usbpd_csa_scp_top.out_d_ocp
 * 174         MXUSBPD_HARD_TOP_INST.y_csa_rcp.clk_div2_lv
 * 173         MXUSBPD_HARD_TOP_INST.y_csa_rcp.clk_div4_lv
 * 172         MXUSBPD_HARD_TOP_INST.y_csa_rcp.clk_div8_lv
 * 171         MXUSBPD_HARD_TOP_INST.y_csa_rcp.clk_div16_lv
 * 170         MXUSBPD_HARD_TOP_INST.y_csa_rcp.rignosc_out_lv
 * 169         MXUSBPD_HARD_TOP_INST.y_csa_rcp.autozero_clk_lv
 * 168         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_pump_en_ctrl.ddft_faults_masked
 * 167         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_pump_en_ctrl.ddft_async_fault_det
 * 166         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_cc1_en_ctrl.ddft_faults_masked
 * 165         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_cc1_en_ctrl.ddft_async_fault_det
 * 164         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_cc1_en_ctrl.ddft_faults_masked
 * 163         MXUSBPD_MMIO_INST.y_vconn20_cc12_switch.u_mxusbpd_gate_driver_vconn20_cc1_en_ctrl.ddft_async_fault_det
 * 162:159 MXUSBPD_MMIO_INST.y_sbu20_sbu12_en_ctrl.u_mxusbpd_gate_driver_sbu20_sbu2_en_ctrl.ddft_faults_masked[3:0]
 * 158:155 MXUSBPD_MMIO_INST.y_sbu20_sbu12_en_ctrl.u_mxusbpd_gate_driver_sbu20_sbu2_en_ctrl.ddft_async_fault_det[3:0]
 * 154:151 MXUSBPD_MMIO_INST.y_sbu20_sbu12_en_ctrl.u_mxusbpd_gate_driver_sbu20_sbu1_en_ctrl.ddft_faults_masked[3:0]
 * 150:147 MXUSBPD_MMIO_INST.y_sbu20_sbu12_en_ctrl.u_mxusbpd_gate_driver_sbu20_sbu1_en_ctrl.ddft_async_fault_det[3:0]
 * 146:143 MXUSBPD_HARD_TOP_INST.y_ngdo.ngdo_ddft[3:0]
 * 142:139 MXUSBPD_MMIO_INST.ngdo_ddft_faults_masked[3:0]
 * 138:135 MXUSBPD_MMIO_INST.ngdo_ddft_async_fault_det[3:0]
 * 134:131 MXUSBPD_MMIO_INST.y_pgdo_pu_ctrl.u_mxusbpd_pgdo_pu_ctrl.pgdo_pu_ddft_faults_masked[3:0]
 * 130:127 MXUSBPD_MMIO_INST.y_pgdo_pu_ctrl.u_mxusbpd_pgdo_pu_ctrl.pgdo_pu_ddft_async_fault_det[3:0]
 * 126:123 MXUSBPD_MMIO_INST.y_pgdo_pu_ctrl.u_mxusbpd_pgdo_pu_ctrl.pgdo_pu_ctrl_pgdo_in_lv[3:0]
 * 122:119 MXUSBPD_MMIO_INST.y_pgdo_pu_ctrl.u_mxusbpd_pgdo_pu_ctrl.pgdo_pu_ctrl_pgdo_en_lv[3:0]
 * 118:115 MXUSBPD_MMIO_INST.y_pgdo_ctrl.u_mxusbpd_pgdo_ctrl.pgdo_ddft_faults_masked[3:0]
 * 114:111 MXUSBPD_MMIO_INST.y_pgdo_ctrl.u_mxusbpd_pgdo_ctrl.pgdo_ddft_async_fault_det[3:0]
 * 110:107 MXUSBPD_MMIO_INST.y_pgdo_ctrl.u_mxusbpd_pgdo_ctrl.pgdo_ctrl_pgdo_en_lv[3:0]
 * 106:99  MXUSBPD_MMIO_INST.y_ngdo_ctrl.u_mxusbpd_ngdo_ctrl.ngdo_ctrl_ngdo_pulldn_en_lv[7:0]
 * 98:91   MXUSBPD_MMIO_INST.y_ngdo_ctrl.u_mxusbpd_ngdo_ctrl.ngdo_ctrl_ngdo_en_lv[7:0]
 * 90:87   MXUSBPD_HARD_TOP_INST.y_cc_5vpump.u_s8usbpd_5vpump_top.pump5v_clkout_ddft[3:0]
 * 86      MXUSBPD_HARD_TOP_INST.y_vsys.u_s8usbpd_vddd_sw_top.vsys_fx_scan
 * 85:84   MXUSBPD_HARD_TOP_INST.hs_filt2_fx_scan[1:0]
 * 83:60   MXUSBPD_HARD_TOP_INST.hs_filt_fx_scan[23:0]
 * 59:52   MXUSBPD_HARD_TOP_INST.ls_filt_fx_scan[7:0]
 * 51:44   MXUSBPD_HARD_TOP_INST.y_det_shv.u_s8usbpd_det_shv_top.det_shv_fx_scan[7:0]
 * 43:36   MXUSBPD_HARD_TOP_INST.y_bch_det.u_s8usbpd_bch_chgdet_top.bch_det_fx_scan[7:0]
 * 35:32   MXUSBPD_HARD_TOP_INST.y_sbu20.u_s8usbpd_sbu20_sw_top.sbu1_ovp_fx_scan[3:0]
 * 31:28   MXUSBPD_HARD_TOP_INST.y_sbu20.u_s8usbpd_sbu20_sw_top.sbu2_ovp_fx_scan[3:0]
 * 27:24   MXUSBPD_HARD_TOP_INST.qcom_rcvr_dp_fx_scan[3:0]
 * 23:20   MXUSBPD_HARD_TOP_INST.qcom_rcvr_dm_fx_scan[3:0]
 * 19:16   MXUSBPD_HARD_TOP_INST.y_shvreg.u_s8usbpd_vreg_top.shvreg_vbus_fx_scan[3:0]
 * 15:12   MXUSBPD_HARD_TOP_INST.y_20vreg.u_s8usbpd_vreg_top.vreg_vbus_fx_scan[3:0]
 * 11:8    MXUSBPD_HARD_TOP_INST.y_csa.u_s8usbpd_csa_top.csa_vbus_fx_scan[3:0]
 * 7:4     MXUSBPD_HARD_TOP_INST.y_chgdet.u_s8usbpd_chgdet_top.chgdet_fx_scan[3:0]
 * 3:0     MXUSBPD_HARD_TOP_INST.y_csa.u_s8usbpd_csa_top.csa_oc_fx_scan[3:0]
 */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT1_SEL_MASK            (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT1_SEL_POS             (8UL)


/*
 * IP GPIO DDFT Selections
 */
#define PDSS_GPIO_DDFT_MUX_ADDRESS                          (0x400a058cUL)
#define PDSS_GPIO_DDFT_MUX                                  (*(volatile uint32_t *)(0x400a058cUL))
#define PDSS_GPIO_DDFT_MUX_DEFAULT                          (0x00000000UL)

/*
 * 120 CCG7D_GPIO_DDFT1  -- specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 119 CCG7D_GPIO_DDFT0  -- specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 118 MXUSBPD_MMIO_INST.u_vcmp_fs.u_intr_clk_lf_filter.out
 * 117 MXUSBPD_MMIO_INST.y_pasc_gpio_ddft.u_mxusbpd_pasc_gpio_ddft1_mux.ddft_out
 * 116 MXUSBPD_MMIO_INST.y_pasc_gpio_ddft.u_mxusbpd_pasc_gpio_ddft0_mux.ddft_out
 * 115 MXUSBPD_MMIO_INST.y_cc_vbus_det.y_cc_vbus_det.u_intr_clk_filter_filter.out
 * 114   MXUSBPD_MMIO_INST.y_csa_scp_edge.u_csa_ocp_change.u_intr_clk_filter_filter.out
 * 113   MXUSBPD_MMIO_INST.y_csa_scp_edge.u_csa_scp_change.u_intr_clk_filter_filter.out
 * 112   MXUSBPD_MMIO_INST.y_csa_rcp_edge.u_csa_out_change.u_intr_clk_filter_filter.out
 * 111   MXUSBPD_MMIO_INST.y_csa_rcp_edge.u_csa_comp_out_change.u_intr_clk_filter_filter.out
 * 110   MXUSBPD_MMIO_INST.y_csa_rcp_edge.u_csa_vbus_ovp_change.u_intr_clk_filter_filter.out
 * 109:106 MXUSBPD_MMIO_INST.y_small_vconn.u_small_vconn_change.filt_out_gpio
 * 105     MXUSBPD_MMIO_INST.u_hs_filt22_change.u_intr_clk_filter_filter.out
 * 104     MXUSBPD_MMIO_INST.u_hs_filt21_change.u_intr_clk_filter_filter.out
 * 103:80  MXUSBPD_MMIO_INST.y_hs_edge_det.u_hs_change.u_intr_clk_filter_filter.out
 * 79:72   MXUSBPD_MMIO_INST.y_ls_edge.u_ls_change.u_intr_clk_lf_filter.out
 * 71:64   MXUSBPD_MMIO_INST.y_sbu20_ovp_edge.u_sbu2_ovp_change.u_intr_clk_filter_filter.out,MXUSBPD_MMIO_INST.y_sbu20_ovp_edge.u_sbu1_ovp_change.u_intr_clk_filter_filter.out
 * 63:56   MXUSBPD_MMIO_INST.y_bch_det_edge.u_bch_det_comp1_change.u_intr_clk_lf_filter.out,MXUSBPD_MMIO_INST.y_bch_det_edge.u_bch_det_comp0_change.u_intr_clk_lf_filter.out
 * 55:48   MXUSBPD_MMIO_INST.y_det_shv_edge.u_det_shv_change.u_intr_clk_lf_filter.out
 * 47:44   MXUSBPD_MMIO_INST.y_csa_edge.u_csa_vbus_change.u_intr_clk_lf_filter.out
 * 43:40   MXUSBPD_MMIO_INST.y_csa_edge.u_csa_oc_change.u_intr_clk_filter_filter.out
 * 39:36   MXUSBPD_MMIO_INST.y_bch_det_edge.u_qcom_rcvr_dm_change.u_intr_clk_lf_filter.out
 * 35:32   MXUSBPD_MMIO_INST.y_bch_det_edge.u_qcom_rcvr_dp_change.u_intr_clk_lf_filter.out
 * 31:28   MXUSBPD_MMIO_INST.y_chgdet_edge.u_chgdet_change.u_intr_clk_lf_filter.out
 * 27:24   MXUSBPD_MMIO_INST.y_shvreg_vbus_edge.u_shvreg_vbus_change.u_intr_clk_lf_filter.out
 * 23:20   MXUSBPD_MMIO_INST.y_vreg_vbus_edge.u_vreg_vbus_change.u_intr_clk_lf_filter.out
 * 19:16   MXUSBPD_MMIO_INST.y_adc.u_cmp_out_change.u_intr_clk_filter_filter.out
 * 15      MXUSBPD_MMIO_INST.y_vsys_edge.u_vsys_change.u_intr_clk_lf_filter.out
 * 14      MXUSBPD_MMIO_INST.u_hpd_change.u_intr_clk_lf_filter.out
 * 13      MXUSBPD_MMIO_INST.y_v5v_edge.u_v5v_change.u_intr_clk_lf_filter.out
 * 12      MXUSBPD_MMIO_INST.y_vconn2_edge.u_vconn2_change.u_intr_clk_lf_filter.out
 * 11      MXUSBPD_MMIO_INST.y_vconn1_edge.u_vconn1_change.u_intr_clk_lf_filter.out
 * 10      MXUSBPD_MMIO_INST.u_vcmp_up.u_intr_clk_lf_filter.out
 * 9       MXUSBPD_MMIO_INST.u_vcmp_dn.u_intr_clk_lf_filter.out
 * 8       MXUSBPD_MMIO_INST.u_vcmp_la.u_intr_clk_lf_filter.out
 * 7       MXUSBPD_MMIO_INST.y_vconn20_oxp_cc12_det.u_cc2_ocp_change.u_intr_clk_filter_filter.out
 * 6       MXUSBPD_MMIO_INST.y_vconn20_oxp_cc12_det.u_cc1_ocp_change.u_intr_clk_filter_filter.out
 * 5       MXUSBPD_MMIO_INST.y_vconn20_oxp_cc12_det.u_cc2_ovp_change.u_intr_clk_filter_filter.out
 * 4       MXUSBPD_MMIO_INST.y_vconn20_oxp_cc12_det.u_cc1_ovp_change.u_intr_clk_filter_filter.out
 * 3       MXUSBPD_MMIO_INST.u_cc2_change.u_intr_clk_lf_filter.out
 * 2       MXUSBPD_MMIO_INST.u_cc1_change.u_intr_clk_lf_filter.out
 * 1       gpio_intr_ddft1
 * 0       gpio_intr_ddft0
 */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT0_SEL_MASK              (0x0000007fUL) /* <0:6> R:RW:0: */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT0_SEL_POS               (0UL)


/*
 * 0: The selected output is not inverted
 * 1: The selected out is inverted
 */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT0_POLARITY              (1UL << 7) /* <7:7> R:RW:0: */


/*
 * 120 CCG7D_GPIO_DDFT1  -- specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 119 CCG7D_GPIO_DDFT0  -- specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 118 MXUSBPD_MMIO_INST.u_vcmp_fs.u_intr_clk_lf_filter.out
 * 117 MXUSBPD_MMIO_INST.y_pasc_gpio_ddft.u_mxusbpd_pasc_gpio_ddft1_mux.ddft_out
 * 116 MXUSBPD_MMIO_INST.y_pasc_gpio_ddft.u_mxusbpd_pasc_gpio_ddft0_mux.ddft_out
 * 115 MXUSBPD_MMIO_INST.y_cc_vbus_det.y_cc_vbus_det.u_intr_clk_filter_filter.out
 * 114   MXUSBPD_MMIO_INST.y_csa_scp_edge.u_csa_ocp_change.u_intr_clk_filter_filter.out
 * 113   MXUSBPD_MMIO_INST.y_csa_scp_edge.u_csa_scp_change.u_intr_clk_filter_filter.out
 * 112   MXUSBPD_MMIO_INST.y_csa_rcp_edge.u_csa_out_change.u_intr_clk_filter_filter.out
 * 111   MXUSBPD_MMIO_INST.y_csa_rcp_edge.u_csa_comp_out_change.u_intr_clk_filter_filter.out
 * 110   MXUSBPD_MMIO_INST.y_csa_rcp_edge.u_csa_vbus_ovp_change.u_intr_clk_filter_filter.out
 * 109:106 MXUSBPD_MMIO_INST.y_small_vconn.u_small_vconn_change.filt_out_gpio
 * 105     MXUSBPD_MMIO_INST.u_hs_filt22_change.u_intr_clk_filter_filter.out
 * 104     MXUSBPD_MMIO_INST.u_hs_filt21_change.u_intr_clk_filter_filter.out
 * 103:80  MXUSBPD_MMIO_INST.y_hs_edge_det.u_hs_change.u_intr_clk_filter_filter.out
 * 79:72   MXUSBPD_MMIO_INST.y_ls_edge.u_ls_change.u_intr_clk_lf_filter.out
 * 71:64   MXUSBPD_MMIO_INST.y_sbu20_ovp_edge.u_sbu2_ovp_change.u_intr_clk_filter_filter.out,MXUSBPD_MMIO_INST.y_sbu20_ovp_edge.u_sbu1_ovp_change.u_intr_clk_filter_filter.out
 * 63:56   MXUSBPD_MMIO_INST.y_bch_det_edge.u_bch_det_comp1_change.u_intr_clk_lf_filter.out,MXUSBPD_MMIO_INST.y_bch_det_edge.u_bch_det_comp0_change.u_intr_clk_lf_filter.out
 * 55:48   MXUSBPD_MMIO_INST.y_det_shv_edge.u_det_shv_change.u_intr_clk_lf_filter.out
 * 47:44   MXUSBPD_MMIO_INST.y_csa_edge.u_csa_vbus_change.u_intr_clk_lf_filter.out
 * 43:40   MXUSBPD_MMIO_INST.y_csa_edge.u_csa_oc_change.u_intr_clk_filter_filter.out
 * 39:36   MXUSBPD_MMIO_INST.y_bch_det_edge.u_qcom_rcvr_dm_change.u_intr_clk_lf_filter.out
 * 35:32   MXUSBPD_MMIO_INST.y_bch_det_edge.u_qcom_rcvr_dp_change.u_intr_clk_lf_filter.out
 * 31:28   MXUSBPD_MMIO_INST.y_chgdet_edge.u_chgdet_change.u_intr_clk_lf_filter.out
 * 27:24   MXUSBPD_MMIO_INST.y_shvreg_vbus_edge.u_shvreg_vbus_change.u_intr_clk_lf_filter.out
 * 23:20   MXUSBPD_MMIO_INST.y_vreg_vbus_edge.u_vreg_vbus_change.u_intr_clk_lf_filter.out
 * 19:16   MXUSBPD_MMIO_INST.y_adc.u_cmp_out_change.u_intr_clk_filter_filter.out
 * 15      MXUSBPD_MMIO_INST.y_vsys_edge.u_vsys_change.u_intr_clk_lf_filter.out
 * 14      MXUSBPD_MMIO_INST.u_hpd_change.u_intr_clk_lf_filter.out
 * 13      MXUSBPD_MMIO_INST.y_v5v_edge.u_v5v_change.u_intr_clk_lf_filter.out
 * 12      MXUSBPD_MMIO_INST.y_vconn2_edge.u_vconn2_change.u_intr_clk_lf_filter.out
 * 11      MXUSBPD_MMIO_INST.y_vconn1_edge.u_vconn1_change.u_intr_clk_lf_filter.out
 * 10      MXUSBPD_MMIO_INST.u_vcmp_up.u_intr_clk_lf_filter.out
 * 9       MXUSBPD_MMIO_INST.u_vcmp_dn.u_intr_clk_lf_filter.out
 * 8       MXUSBPD_MMIO_INST.u_vcmp_la.u_intr_clk_lf_filter.out
 * 7       MXUSBPD_MMIO_INST.y_vconn20_oxp_cc12_det.u_cc2_ocp_change.u_intr_clk_filter_filter.out
 * 6       MXUSBPD_MMIO_INST.y_vconn20_oxp_cc12_det.u_cc1_ocp_change.u_intr_clk_filter_filter.out
 * 5       MXUSBPD_MMIO_INST.y_vconn20_oxp_cc12_det.u_cc2_ovp_change.u_intr_clk_filter_filter.out
 * 4       MXUSBPD_MMIO_INST.y_vconn20_oxp_cc12_det.u_cc1_ovp_change.u_intr_clk_filter_filter.out
 * 3       MXUSBPD_MMIO_INST.u_cc2_change.u_intr_clk_lf_filter.out
 * 2       MXUSBPD_MMIO_INST.u_cc1_change.u_intr_clk_lf_filter.out
 * 1       gpio_intr_ddft1
 * 0       gpio_intr_ddft0
 */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT1_SEL_MASK              (0x00007f00UL) /* <8:14> R:RW:0: */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT1_SEL_POS               (8UL)


/*
 * 0: The selected output is not inverted
 * 1: The selected out is inverted
 */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT1_POLARITY              (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Interrupt GPIO DDFT Selections
 */
#define PDSS_GPIO_INTR_DDFT_MUX_ADDRESS                     (0x400a0590UL)
#define PDSS_GPIO_INTR_DDFT_MUX                             (*(volatile uint32_t *)(0x400a0590UL))
#define PDSS_GPIO_INTR_DDFT_MUX_DEFAULT                     (0x00000000UL)

/*
 * 250 CCG7D_GPIO_INTR_DDFT1 -- specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 249 CCG7D_GPIO_INTR_DDFT0 -- specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 248 MXUSBPD_REGS_INST.intr1_set_vcmp_fs_changed
 * 247 MXUSBPD_REGS_INST.intr15_cause_pds_vreg_vbus_done
 * 246 MXUSBPD_REGS_INST.intr15_ea_cc_flag_changed_done
 * 245 MXUSBPD_REGS_INST.intr15_ff_ov_changed
 * 244 MXUSBPD_REGS_INST.intr15_ff_uv_changed
 * 243 MXUSBPD_REGS_INST.intr15_zcdf_out_changed
 * 242 MXUSBPD_REGS_INST.intr15_peakdet_out_changed
 * 241 MXUSBPD_REGS_INST.intr15_peakdet_rst_out_changed
 * 240 MXUSBPD_REGS_INST.intr15_peakdet_clcmp_raw_out_changed
 * 239 MXUSBPD_REGS_INST.intr15_sr_sen_ovp_out_changed
 * 238 MXUSBPD_REGS_INST.intr15_pwm_out_changed
 * 237 MXUSBPD_REGS_INST.intr15_skip_out_changed
 * 236 MXUSBPD_REGS_INST.intr15_burst_exit_out_changed
 * 235 MXUSBPD_REGS_INST.intr15_pds_scp_changed
 * 234 MXUSBPD_REGS_INST.intr15_nsn_out_changed
 * 233 MXUSBPD_REGS_INST.intr15_zcd_out_changed
 * 232 MXUSBPD_REGS_INST.intr8_pasc_idle
 * 231 MXUSBPD_REGS_INST.intr8_vbtr_exit_done
 * 230 MXUSBPD_REGS_INST.intr8_vbtr_opr_done
 * 229 MXUSBPD_REGS_INST.intr8_pasc_dcm_2_ccm_chg
 * 228 MXUSBPD_REGS_INST.intr8_pasc_ccm_2_dcm_chg
 * 227 MXUSBPD_REGS_INST.intr8_gdrv_less_than_turn_off
 * 226 MXUSBPD_REGS_INST.intr8_gdrv_input_width_less_than_min
 * 225 MXUSBPD_REGS_INST.intr8_cal_fail
 * 224 MXUSBPD_REGS_INST.intr8_gdrv_contentiion
 * 223 MXUSBPD_REGS_INST.intr8_gdrv_greater_than_turn_off
 * 222 MXUSBPD_REGS_INST.intr8_pasc_loop_cal_done
 * 221 MXUSBPD_REGS_INST.intr8_pasc_burst_entry
 * 220 MXUSBPD_REGS_INST.intr8_pasc_var_tmin_timeout
 * 219 MXUSBPD_REGS_INST.intr8_pasc_nsn_idle_timeout
 * 218 MXUSBPD_REGS_INST.intr8_pasc_ff_ov_idle_timeout
 * 217 MXUSBPD_REGS_INST.intr8_pasc_fix_freq_timeout
 * 216 MXUSBPD_REGS_INST.intr8_pasc_var_tmax_timeout
 * 215 MXUSBPD_REGS_INST.intr8_pasc_aud_tmin_timeout
 * 214 MXUSBPD_REGS_INST.intr8_pasc_aud_tmax_timeout
 * 213 MXUSBPD_REGS_INST.intr8_pasc_gdrv_in_max_width_timeout
 * 212 MXUSBPD_REGS_INST.intr8_pasc_max_width_timeout
 * 211 MXUSBPD_REGS_INST.intr1_lf_cntr_match
 * 210 MXUSBPD_REGS_INST.intr13_cause_cc_vbus_changed
 * 209 MXUSBPD_REGS_INST.intr13_set_csa_vbus_ovp_changed
 * 208 MXUSBPD_REGS_INST.intr13_set_csa_comp_out_changed
 * 207 MXUSBPD_REGS_INST.intr13_set_csa_out_changed
 * 206 MXUSBPD_REGS_INST.intr13_set_csa_scp_changed
 * 205 MXUSBPD_REGS_INST.intr13_set_csa_ocp_changed
 * 204:181 MXUSBPD_REGS_INST.intr5_set_edge_changed,
 * 180:173 MXUSBPD_REGS_INST.intr3_set_sbu1_sbu2_ovp_changed,
 * 172:165 MXUSBPD_REGS_INST.intr7_set_clk_lf_edge_changed,
 * 164:157 MXUSBPD_REGS_INST.intr9_set_det_shv_det_changed,
 * 156:149 MXUSBPD_REGS_INST.intr9_set_bch_det_changed,
 * 148:145 MXUSBPD_REGS_INST.intr3_set_csa_oc_changed,
 * 144:141 MXUSBPD_REGS_INST.intr3_set_chgdet_changed,
 * 140:137 MXUSBPD_REGS_INST.intr3_set_vreg20_vbus_changed,
 * 136:133 MXUSBPD_REGS_INST.intr3_set_csa_vbus_changed,
 * 132:129 MXUSBPD_REGS_INST.intr9_set_qcom_rcvr_dm_changed,
 * 128:125 MXUSBPD_REGS_INST.intr9_set_qcom_rcvr_dp_changed,
 * 124:121 MXUSBPD_REGS_INST.intr9_set_shvreg_det_changed,
 * 120:117 MXUSBPD_REGS_INST.intr4_set_afc_ping_recvd,
 * 116:113 MXUSBPD_REGS_INST.intr4_set_afc_sm_idle,
 * 112:109 MXUSBPD_REGS_INST.intr4_set_afc_timeout,
 * 108:105 MXUSBPD_REGS_INST.intr4_set_afc_rx_reset,
 * 104:101 MXUSBPD_REGS_INST.intr4_set_update_ping_pong,
 * 100:97  MXUSBPD_REGS_INST.intr4_set_afc_error,
 * 96:93   MXUSBPD_REGS_INST.intr6_set_qc_3_d_p_pulse_rcvd,
 * 92:89   MXUSBPD_REGS_INST.intr6_set_qc_3_d_m_pulse_rcvd,
 * 88:85   MXUSBPD_REGS_INST.intr6_set_qc_3_device_req_sent,
 * 84:83   MXUSBPD_REGS_INST.intr11_set_filt2_edge_changed,
 * 82:81   MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[3:2],
 * 80      MXUSBPD_REGS_INST.intr3_set_vsys_changed,
 * 79      MXUSBPD_REGS_INST.intr1_set_cc2_ocp_changed,
 * 78      MXUSBPD_REGS_INST.intr1_set_cc1_ocp_changed,
 * 77      MXUSBPD_REGS_INST.intr1_set_cc2_ovp_changed,
 * 76      MXUSBPD_REGS_INST.intr1_set_cc1_ovp_changed,
 * 75      MXUSBPD_REGS_INST.intr1_set_drp_attached_detected,
 * 74      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[3],
 * 73      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[2],
 * 72      MXUSBPD_REGS_INST.intr0_set_sar_done[3],
 * 71      MXUSBPD_REGS_INST.intr0_set_sar_done[2],
 * 70      MXUSBPD_REGS_INST.intr1_set_vswap_vbus_less_5_done,
 * 69      MXUSBPD_REGS_INST.intr2_set_swap_command_done,
 * 68      1'b0
 * 67      1'b0
 * 66      MXUSBPD_REGS_INST.intr2_set_swap_disconnect,
 * 65      MXUSBPD_REGS_INST.intr2_set_swap_rcvd,
 * 64      MXUSBPD_REGS_INST.intr2_set_swap_pulse,
 * 63      MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[0],
 * 62      MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[1],
 * 61      MXUSBPD_REGS_INST.intr2_set_vreg20v_switch_done,
 * 60      MXUSBPD_REGS_INST.intr2_set_vddd_sw_switch_done,
 * 59      MXUSBPD_REGS_INST.intr2_set_chunk_det,
 * 58      MXUSBPD_REGS_INST.intr2_set_tx_sram_under_flow,
 * 57      MXUSBPD_REGS_INST.intr2_set_rx_sram_over_flow,
 * 56      1'b0
 * 55      1'b0
 * 54      1'b0
 * 53      MXUSBPD_REGS_INST.intr2_set_extended_msg_det,
 * 52      M+G2437XUSBPD_REGS_INST.intr2_set_hpdt_command_done,
 * 51      MXUSBPD_REGS_INST.intr2_set_hpd_queue,
 * 50      MXUSBPD_REGS_INST.intr2_set_hpd_unstable,
 * 49      MXUSBPD_REGS_INST.intr2_set_hpd_unpluged,
 * 48      MXUSBPD_REGS_INST.intr2_set_hpd_pluged,
 * 47      MXUSBPD_REGS_INST.intr2_set_hpd_irq,
 * 46      MXUSBPD_REGS_INST.intr2_set_ui_cal_done,
 * 45      1'b0
 * 44      1'b0
 * 43      1'b0
 * 42      1'b0
 * 41      MXUSBPD_REGS_INST.intr1_set_hpdin_changed,
 * 40      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[1],
 * 39      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[0],
 * 38      MXUSBPD_REGS_INST.intr1_set_v5v_changed,
 * 37      MXUSBPD_REGS_INST.intr1_set_vcmp_dn_changed,
 * 36      MXUSBPD_REGS_INST.intr1_set_vcmp_up_changed,
 * 35      MXUSBPD_REGS_INST.intr1_set_vcmp_la_changed,
 * 34      MXUSBPD_REGS_INST.intr1_set_cc2_changed,
 * 33      MXUSBPD_REGS_INST.intr1_set_cc1_changed,
 * 32      MXUSBPD_REGS_INST.intr1_set_vconn2_changed,
 * 31      MXUSBPD_REGS_INST.intr1_set_vconn1_changed,
 * 30      1'b0
 * 29      MXUSBPD_REGS_INST.intr0_set_sar_done[1],
 * 28      MXUSBPD_REGS_INST.intr0_set_rx_state_idle,
 * 27      MXUSBPD_REGS_INST.intr0_set_tx_state_idle,
 * 26      MXUSBPD_REGS_INST.intr0_set_tx_regulator_enabled,
 * 25      MXUSBPD_REGS_INST.intr0_set_tx_cc_data_oen_deassert,
 * 24      MXUSBPD_REGS_INST.intr0_set_tx_cc_data_oen_assert,
 * 23      MXUSBPD_REGS_INST.intr0_set_kchar_error,
 * 22      MXUSBPD_REGS_INST.intr0_set_tx_retry_enable_clrd,
 * 21      MXUSBPD_REGS_INST.intr0_set_rx_sram_half_end,
 * 20      MXUSBPD_REGS_INST.intr0_set_tx_sram_half_end,
 * 19      1'b0
 * 18      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type4,
 * 17      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type3,
 * 16      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type2,
 * 15      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type1
 * 14      MXUSBPD_REGS_INST.intr0_set_crc_rx_timer_exp,
 * 13      MXUSBPD_REGS_INST.intr0_set_cc_no_valid_data_detected,
 * 12      MXUSBPD_REGS_INST.intr0_set_cc_valid_data_detected,
 * 11      MXUSBPD_REGS_INST.intr0_set_tx_goodcrc_msg_done,
 * 10      MXUSBPD_REGS_INST.intr0_set_sar_done[0],
 * 9       MXUSBPD_REGS_INST.intr0_set_rcv_rst,
 * 8       MXUSBPD_REGS_INST.intr0_set_tx_hard_rst_done,
 * 7       MXUSBPD_REGS_INST.intr0_set_tx_packet_done,
 * 6       MXUSBPD_REGS_INST.intr0_set_rx_over_run,
 * 5       MXUSBPD_REGS_INST.intr0_set_eop_error,
 * 4       MXUSBPD_REGS_INST.intr0_set_rcv_expt_goodcrc_msg_complete,
 * 3       MXUSBPD_REGS_INST.intr0_set_rcv_goodcrc_msg_complete,
 * 2       MXUSBPD_REGS_INST.intr0_set_rx_sop,
 * 1       MXUSBPD_REGS_INST.intr0_set_rcv_bad_packet_complete,
 * 0       MXUSBPD_REGS_INST.intr0_set_rcv_good_packet_complete,
 */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT0_SEL_MASK    (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT0_SEL_POS     (0UL)


/*
 * 250 CCG7D_GPIO_INTR_DDFT1 -- specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 249 CCG7D_GPIO_INTR_DDFT0 -- specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 248 MXUSBPD_REGS_INST.intr1_set_vcmp_fs_changed
 * 247 MXUSBPD_REGS_INST.intr15_cause_pds_vreg_vbus_done
 * 246 MXUSBPD_REGS_INST.intr15_ea_cc_flag_changed_done
 * 245 MXUSBPD_REGS_INST.intr15_ff_ov_changed
 * 244 MXUSBPD_REGS_INST.intr15_ff_uv_changed
 * 243 MXUSBPD_REGS_INST.intr15_zcdf_out_changed
 * 242 MXUSBPD_REGS_INST.intr15_peakdet_out_changed
 * 241 MXUSBPD_REGS_INST.intr15_peakdet_rst_out_changed
 * 240 MXUSBPD_REGS_INST.intr15_peakdet_clcmp_raw_out_changed
 * 239 MXUSBPD_REGS_INST.intr15_sr_sen_ovp_out_changed
 * 238 MXUSBPD_REGS_INST.intr15_pwm_out_changed
 * 237 MXUSBPD_REGS_INST.intr15_skip_out_changed
 * 236 MXUSBPD_REGS_INST.intr15_burst_exit_out_changed
 * 235 MXUSBPD_REGS_INST.intr15_pds_scp_changed
 * 234 MXUSBPD_REGS_INST.intr15_nsn_out_changed
 * 233 MXUSBPD_REGS_INST.intr15_zcd_out_changed
 * 232 MXUSBPD_REGS_INST.intr8_pasc_idle
 * 231 MXUSBPD_REGS_INST.intr8_vbtr_exit_done
 * 230 MXUSBPD_REGS_INST.intr8_vbtr_opr_done
 * 229 MXUSBPD_REGS_INST.intr8_pasc_dcm_2_ccm_chg
 * 228 MXUSBPD_REGS_INST.intr8_pasc_ccm_2_dcm_chg
 * 227 MXUSBPD_REGS_INST.intr8_gdrv_less_than_turn_off
 * 226 MXUSBPD_REGS_INST.intr8_gdrv_input_width_less_than_min
 * 225 MXUSBPD_REGS_INST.intr8_cal_fail
 * 224 MXUSBPD_REGS_INST.intr8_gdrv_contentiion
 * 223 MXUSBPD_REGS_INST.intr8_gdrv_greater_than_turn_off
 * 222 MXUSBPD_REGS_INST.intr8_pasc_loop_cal_done
 * 221 MXUSBPD_REGS_INST.intr8_pasc_burst_entry
 * 220 MXUSBPD_REGS_INST.intr8_pasc_var_tmin_timeout
 * 219 MXUSBPD_REGS_INST.intr8_pasc_nsn_idle_timeout
 * 218 MXUSBPD_REGS_INST.intr8_pasc_ff_ov_idle_timeout
 * 217 MXUSBPD_REGS_INST.intr8_pasc_fix_freq_timeout
 * 216 MXUSBPD_REGS_INST.intr8_pasc_var_tmax_timeout
 * 215 MXUSBPD_REGS_INST.intr8_pasc_aud_tmin_timeout
 * 214 MXUSBPD_REGS_INST.intr8_pasc_aud_tmax_timeout
 * 213 MXUSBPD_REGS_INST.intr8_pasc_gdrv_in_max_width_timeout
 * 212 MXUSBPD_REGS_INST.intr8_pasc_max_width_timeout
 * 211 MXUSBPD_REGS_INST.intr1_lf_cntr_match
 * 210 MXUSBPD_REGS_INST.intr13_cause_cc_vbus_changed
 * 209 MXUSBPD_REGS_INST.intr13_set_csa_vbus_ovp_changed
 * 208 MXUSBPD_REGS_INST.intr13_set_csa_comp_out_changed
 * 207 MXUSBPD_REGS_INST.intr13_set_csa_out_changed
 * 206 MXUSBPD_REGS_INST.intr13_set_csa_scp_changed
 * 205 MXUSBPD_REGS_INST.intr13_set_csa_ocp_changed
 * 204:181 MXUSBPD_REGS_INST.intr5_set_edge_changed,
 * 180:173 MXUSBPD_REGS_INST.intr3_set_sbu1_sbu2_ovp_changed,
 * 172:165 MXUSBPD_REGS_INST.intr7_set_clk_lf_edge_changed,
 * 164:157 MXUSBPD_REGS_INST.intr9_set_det_shv_det_changed,
 * 156:149 MXUSBPD_REGS_INST.intr9_set_bch_det_changed,
 * 148:145 MXUSBPD_REGS_INST.intr3_set_csa_oc_changed,
 * 144:141 MXUSBPD_REGS_INST.intr3_set_chgdet_changed,
 * 140:137 MXUSBPD_REGS_INST.intr3_set_vreg20_vbus_changed,
 * 136:133 MXUSBPD_REGS_INST.intr3_set_csa_vbus_changed,
 * 132:129 MXUSBPD_REGS_INST.intr9_set_qcom_rcvr_dm_changed,
 * 128:125 MXUSBPD_REGS_INST.intr9_set_qcom_rcvr_dp_changed,
 * 124:121 MXUSBPD_REGS_INST.intr9_set_shvreg_det_changed,
 * 120:117 MXUSBPD_REGS_INST.intr4_set_afc_ping_recvd,
 * 116:113 MXUSBPD_REGS_INST.intr4_set_afc_sm_idle,
 * 112:109 MXUSBPD_REGS_INST.intr4_set_afc_timeout,
 * 108:105 MXUSBPD_REGS_INST.intr4_set_afc_rx_reset,
 * 104:101 MXUSBPD_REGS_INST.intr4_set_update_ping_pong,
 * 100:97  MXUSBPD_REGS_INST.intr4_set_afc_error,
 * 96:93   MXUSBPD_REGS_INST.intr6_set_qc_3_d_p_pulse_rcvd,
 * 92:89   MXUSBPD_REGS_INST.intr6_set_qc_3_d_m_pulse_rcvd,
 * 88:85   MXUSBPD_REGS_INST.intr6_set_qc_3_device_req_sent,
 * 84:83   MXUSBPD_REGS_INST.intr11_set_filt2_edge_changed,
 * 82:81   MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[3:2],
 * 80      MXUSBPD_REGS_INST.intr3_set_vsys_changed,
 * 79      MXUSBPD_REGS_INST.intr1_set_cc2_ocp_changed,
 * 78      MXUSBPD_REGS_INST.intr1_set_cc1_ocp_changed,
 * 77      MXUSBPD_REGS_INST.intr1_set_cc2_ovp_changed,
 * 76      MXUSBPD_REGS_INST.intr1_set_cc1_ovp_changed,
 * 75      MXUSBPD_REGS_INST.intr1_set_drp_attached_detected,
 * 74      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[3],
 * 73      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[2],
 * 72      MXUSBPD_REGS_INST.intr0_set_sar_done[3],
 * 71      MXUSBPD_REGS_INST.intr0_set_sar_done[2],
 * 70      MXUSBPD_REGS_INST.intr1_set_vswap_vbus_less_5_done,
 * 69      MXUSBPD_REGS_INST.intr2_set_swap_command_done,
 * 68      1'b0
 * 67      1'b0
 * 66      MXUSBPD_REGS_INST.intr2_set_swap_disconnect,
 * 65      MXUSBPD_REGS_INST.intr2_set_swap_rcvd,
 * 64      MXUSBPD_REGS_INST.intr2_set_swap_pulse,
 * 63      MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[0],
 * 62      MXUSBPD_REGS_INST.intr1_set_ngdo_spacing_done[1],
 * 61      MXUSBPD_REGS_INST.intr2_set_vreg20v_switch_done,
 * 60      MXUSBPD_REGS_INST.intr2_set_vddd_sw_switch_done,
 * 59      MXUSBPD_REGS_INST.intr2_set_chunk_det,
 * 58      MXUSBPD_REGS_INST.intr2_set_tx_sram_under_flow,
 * 57      MXUSBPD_REGS_INST.intr2_set_rx_sram_over_flow,
 * 56      1'b0
 * 55      1'b0
 * 54      1'b0
 * 53      MXUSBPD_REGS_INST.intr2_set_extended_msg_det,
 * 52      M+G2437XUSBPD_REGS_INST.intr2_set_hpdt_command_done,
 * 51      MXUSBPD_REGS_INST.intr2_set_hpd_queue,
 * 50      MXUSBPD_REGS_INST.intr2_set_hpd_unstable,
 * 49      MXUSBPD_REGS_INST.intr2_set_hpd_unpluged,
 * 48      MXUSBPD_REGS_INST.intr2_set_hpd_pluged,
 * 47      MXUSBPD_REGS_INST.intr2_set_hpd_irq,
 * 46      MXUSBPD_REGS_INST.intr2_set_ui_cal_done,
 * 45      1'b0
 * 44      1'b0
 * 43      1'b0
 * 42      1'b0
 * 41      MXUSBPD_REGS_INST.intr1_set_hpdin_changed,
 * 40      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[1],
 * 39      MXUSBPD_REGS_INST.intr3_set_cmp_out_changed[0],
 * 38      MXUSBPD_REGS_INST.intr1_set_v5v_changed,
 * 37      MXUSBPD_REGS_INST.intr1_set_vcmp_dn_changed,
 * 36      MXUSBPD_REGS_INST.intr1_set_vcmp_up_changed,
 * 35      MXUSBPD_REGS_INST.intr1_set_vcmp_la_changed,
 * 34      MXUSBPD_REGS_INST.intr1_set_cc2_changed,
 * 33      MXUSBPD_REGS_INST.intr1_set_cc1_changed,
 * 32      MXUSBPD_REGS_INST.intr1_set_vconn2_changed,
 * 31      MXUSBPD_REGS_INST.intr1_set_vconn1_changed,
 * 30      1'b0
 * 29      MXUSBPD_REGS_INST.intr0_set_sar_done[1],
 * 28      MXUSBPD_REGS_INST.intr0_set_rx_state_idle,
 * 27      MXUSBPD_REGS_INST.intr0_set_tx_state_idle,
 * 26      MXUSBPD_REGS_INST.intr0_set_tx_regulator_enabled,
 * 25      MXUSBPD_REGS_INST.intr0_set_tx_cc_data_oen_deassert,
 * 24      MXUSBPD_REGS_INST.intr0_set_tx_cc_data_oen_assert,
 * 23      MXUSBPD_REGS_INST.intr0_set_kchar_error,
 * 22      MXUSBPD_REGS_INST.intr0_set_tx_retry_enable_clrd,
 * 21      MXUSBPD_REGS_INST.intr0_set_rx_sram_half_end,
 * 20      MXUSBPD_REGS_INST.intr0_set_tx_sram_half_end,
 * 19      1'b0
 * 18      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type4,
 * 17      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type3,
 * 16      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type2,
 * 15      MXUSBPD_REGS_INST.MXUSBPD_REGS_INST.intr0_set_collision_type1
 * 14      MXUSBPD_REGS_INST.intr0_set_crc_rx_timer_exp,
 * 13      MXUSBPD_REGS_INST.intr0_set_cc_no_valid_data_detected,
 * 12      MXUSBPD_REGS_INST.intr0_set_cc_valid_data_detected,
 * 11      MXUSBPD_REGS_INST.intr0_set_tx_goodcrc_msg_done,
 * 10      MXUSBPD_REGS_INST.intr0_set_sar_done[0],
 * 9       MXUSBPD_REGS_INST.intr0_set_rcv_rst,
 * 8       MXUSBPD_REGS_INST.intr0_set_tx_hard_rst_done,
 * 7       MXUSBPD_REGS_INST.intr0_set_tx_packet_done,
 * 6       MXUSBPD_REGS_INST.intr0_set_rx_over_run,
 * 5       MXUSBPD_REGS_INST.intr0_set_eop_error,
 * 4       MXUSBPD_REGS_INST.intr0_set_rcv_expt_goodcrc_msg_complete,
 * 3       MXUSBPD_REGS_INST.intr0_set_rcv_goodcrc_msg_complete,
 * 2       MXUSBPD_REGS_INST.intr0_set_rx_sop,
 * 1       MXUSBPD_REGS_INST.intr0_set_rcv_bad_packet_complete,
 * 0       MXUSBPD_REGS_INST.intr0_set_rcv_good_packet_complete,
 */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT1_SEL_MASK    (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT1_SEL_POS     (8UL)


/*
 * The CCG6 & CCG7D Fault GPIO control
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_ADDRESS                   (0x400a0598UL)
#define PDSS_FAULT_GPIO_CTRL_EXTR                           (*(volatile uint32_t *)(0x400a0598UL))
#define PDSS_FAULT_GPIO_CTRL_EXTR_DEFAULT                   (0x00000000UL)

/*
 * 1: Fault is registered on occcurence until cleared(FAULT_CLEAR) by CPU
 * 0: Fault is transparent to External GPIO
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_EN                  (1UL << 0) /* <0:0> R:RW:0: */


/*
 * 1: Clear the registered fault
 * 0: Normal function
 * This functionality is available only the OR option , i.e FAULT_GPIO_*_SEL
 * is 0
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_CLEAR               (1UL << 1) /* <1:1> R:RW:0: */


/*
 * CCG6
 * 0: OR of 1-7 masked with FAULT_MASK register
 * 1: UV
 * 2: OV
 * 3: CSA-OCP
 * 4: CC1-OVP
 * 5: CC2-OVP
 * 6: CC1-OCP
 * 7: CC2-OCP
 * 8: CSA_SCP
 * 9: CSA_OUT
 * 10: CSA_COMP_OUT
 * 11: CSA_VBUS_OVP
 * 12:
 * 13:
 * 14:
 * 15:
 *
 * CCG7D Effective Select bits are {FAULT_GPIO_EXTR_1_SEL_4,FAULT_GPIO_EXTR_1_SEL}
 * 0: OR of 1-7 masked with FAULT_MASK register
 * 1: UV
 * 2: OV
 * 3: CSA-OCP
 * 4: CC1-OVP
 * 5: CC2-OVP
 * 6: CC1-OCP
 * 7: CC2-OCP
 * 8: CSA_SCP
 * 9: PDS_SCP
 * 10: 40CSA_ILIM_DIG
 * 11: PWM_VIN_UV
 * 12: PWM_VIN_OV
 * 13: VREG_IN_RUSH
 * 14: CC1_SCP
 * 15: CC2_SCP
 * 16: VREG_VDDD_BOD
 * NOTE: Max allowed faults are 0 - 16
 *
 * PMG1S3 #0 & #1
 * 0: OR of 1-7 masked with FAULT_MASK register
 * 1: UV
 * 2: OV
 * 3: CSA-OCP
 * 4: CC1-OVP
 * 5: CC2-OVP
 * 6: CC1-OCP
 * 7: CC2-OCP
 * 8: CSA_SCP
 * 9: 0
 * 10: CSA_RCP
 * 11: 0
 * 12: 0
 * 13: 0
 * 14: 0
 * 15: 0
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_0_SEL_MASK    (0x0000003cUL) /* <2:5> R:RW:0: */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_0_SEL_POS    (2UL)


/*
 * 0: The selected output is not inverted
 * 1: The selected out is inverted
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_0_POLARITY    (1UL << 6) /* <6:6> R:RW:0: */


/*
 * CCG6
 * 0: OR of 1-7 masked with FAULT_MASK register
 * 1: UV
 * 2: OV
 * 3: CSA-OCP
 * 4: CC1-OVP
 * 5: CC2-OVP
 * 6: CC1-OCP
 * 7: CC2-OCP
 * 8: CSA_SCP
 * 9: CSA_OUT
 * 10: CSA_COMP_OUT
 * 11: CSA_VBUS_OVP
 * 12:
 * 13:
 * 14:
 * 15:
 *
 * CCG7D Effective Select bits are {FAULT_GPIO_EXTR_1_SEL_4,FAULT_GPIO_EXTR_1_SEL}
 * 0: OR of 1-7 masked with FAULT_MASK register
 * 1: UV
 * 2: OV
 * 3: CSA-OCP
 * 4: CC1-OVP
 * 5: CC2-OVP
 * 6: CC1-OCP
 * 7: CC2-OCP
 * 8: CSA_SCP
 * 9: PDS_SCP
 * 10: 40CSA_ILIM_DIG
 * 11: PWM_VIN_UV
 * 12: PWM_VIN_OV
 * 13: VREG_IN_RUSH (ONLY INST0)
 * 14: CC1_SCP
 * 15: CC2_SCP
 * 16: VREG_VDDD_BOD (ONLY INST0)
 * NOTE: Max allowed faults are 0 - 16
 *
 * PMG1S3 #0 & #1
 * 0: OR of 1-7 masked with FAULT_MASK register
 * 1: UV
 * 2: OV
 * 3: CSA-OCP
 * 4: CC1-OVP
 * 5: CC2-OVP
 * 6: CC1-OCP
 * 7: CC2-OCP
 * 8: CSA_SCP
 * 9: 0
 * 10: CSA_RCP
 * 11: 0
 * 12: 0
 * 13: 0
 * 14: 0
 * 15: 0
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_1_SEL_MASK    (0x00000780UL) /* <7:10> R:RW:0: */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_1_SEL_POS    (7UL)


/*
 * 0: The selected output is not inverted
 * 1: The selected out is inverted
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_1_POLARITY    (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Individual mask bit for FAULT_GPIO_0, FAULT_GPIO_1
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_MASK_EXTR_MASK      (0x07fff000UL) /* <12:26> R:RW:0: */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_MASK_EXTR_POS       (12UL)


/*
 * USBPD Hard IP C-connector Control Register 0
 */
#define PDSS_CC_CTRL_0_ADDRESS                              (0x400a0600UL)
#define PDSS_CC_CTRL_0                                      (*(volatile uint32_t *)(0x400a0600UL))
#define PDSS_CC_CTRL_0_DEFAULT                              (0xb0000000UL)

/*
 * FW can only use this bit when the DEBUG_CC_0.TX_CC_DRIVE_SRC is set to
 * "1".
 * 0: Disables the Transceiver to transmit data
 * 1: Enables the Transceiver to transmit data
 * Notes: This bit is not needed for normal data transmit . This is reqiired
 * only for manual data tranmit .
 *
 */
#define PDSS_CC_CTRL_0_TX_EN                                (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Enables the Transceiver to receive data, Active High
 * This bit should be set after CC Line active interrupt (wakeup) in DeepSleep.
 * FW should set this bit at init and not change after across deep sleep
 * and wake.
 * Notes: DFP_unatached : 1'b0
 *            DFP attached    :  1'b1
 *            UFP , Cable       : 1'b1  (It can se set to 1 from beginning
 * )
 */
#define PDSS_CC_CTRL_0_RX_EN                                (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Firmware detects cable attach and specifies whether CC1 or CC2 is connected
 * to the CC-line of the cable.
 * 0 - CC1
 * 1 - CC2
 * Notes:
 * DFP: 0 or 1 based on the plug orientation .
 * UFP: 0 or 1 based on the plug orientation.
 * AMA: 0 or 1 based on board , which ever line is being used for communication.
 * Cable: 0  (Only CC1 line is used)
 * As a SOURCE, when VCONN is presented on a CC pin, all of the *CC1V2 registers
 * must be set to point to the CC pin connecting to the cable's CC line.
 *  This is required to prevent the VCONN voltage from affecting the comparator
 * thresholds on the active CC line.  This includes the FRS register: CC_CTRL_1.CMP_FS_CC1V2
 *
 */
#define PDSS_CC_CTRL_0_CC_1V2                               (1UL << 2) /* <2:2> R:RW:0: */


/*
 * CC line voltage Comparator enable
 * Notes: Set this bit as need basis . No need to set for DFP unattachd .
 */
#define PDSS_CC_CTRL_0_CMP_EN                               (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Connects cmp_dn comparator to CC1/CC2
 * 0 - CC1
 * 1 - CC2
 * See Note from CC_1V2 register.
 */
#define PDSS_CC_CTRL_0_CMP_DN_CC1V2                         (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Selects the voltage threshold for cmp_dn comparator
 * Notes: Pair of DN and UP comprator should be used to determine remote
 * Rp value when acting as UFP. Firmware can set DN comparator to 0.655V
 * in UFP mode. In DFP mode firmware can use this comparator to detect detach
 * by selecting 2.6V reference .
 */
#define PDSS_CC_CTRL_0_CMP_DN_VSEL_MASK                     (0x000000e0UL) /* <5:7> R:RW:0: */
#define PDSS_CC_CTRL_0_CMP_DN_VSEL_POS                      (5UL)


/*
 * Connects cmp_up comparator to CC1/CC2
 * 0 - CC1
 * 1 - CC2
 * See Note from CC_1V2 register.
 */
#define PDSS_CC_CTRL_0_CMP_UP_CC1V2                         (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Selects the voltage threshold for cmp_up comparator.
 * Notes: Pair of DN and UP comprator should be used to determine remote
 * Rp value when acting as UFP. Firmware can set UP comparator to 1.235V
 * in UFP mode. In DFP mode firmware can use this comparator to detect detach
 * by selecting 2.6V reference .
 */
#define PDSS_CC_CTRL_0_CMP_UP_VSEL_MASK                     (0x00000e00UL) /* <9:11> R:RW:0: */
#define PDSS_CC_CTRL_0_CMP_UP_VSEL_POS                      (9UL)


/*
 * SPARE
 * Used in CCG3PA
 * Bit 0: Uses as FAILSAFE_EN for the discharge protection on VBUS_P
 * Bit 1: Used as FAILSAFE_EN for the discharge protection on VBUS_C
 * Bit 2: Used to invert the SWAP source selected (CDT#281193)
 */
#define PDSS_CC_CTRL_0_CMP_UP_OFFSET_MASK                   (0x00007000UL) /* <12:14> R:RW:0: */
#define PDSS_CC_CTRL_0_CMP_UP_OFFSET_POS                    (12UL)


/*
 * SPARE
 */
#define PDSS_CC_CTRL_0_CMP_UP_OFFSET_EN                     (1UL << 15) /* <15:15> R:RW:0: */


/*
 * SPARE
 */
#define PDSS_CC_CTRL_0_CMP_LA_CC1V2                         (1UL << 16) /* <16:16> R:RW:0: */


/*
 * SPARE
 * Used in CCG3PA
 * Bit 0: Used to enable PWM mode of discharge enable on VBUS_P
 * Bit 1: Used to enable PWM mode of discharge enable on VBUS_C
 */
#define PDSS_CC_CTRL_0_CMP_LA_VSEL_MASK                     (0x000e0000UL) /* <17:19> R:RW:0: */
#define PDSS_CC_CTRL_0_CMP_LA_VSEL_POS                      (17UL)


/*
 * Disable Dead Battery Rd termination on CC1
 * Notes:
 * DFP  (Unattached and attached) : 1'b1
 * UFP_dead : 1'b0
 * UFP_attached: 1'b1
 * Cable: Don't care
 */
#define PDSS_CC_CTRL_0_RD_CC1_DB_DIS                        (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Disable Dead Battery Rd termination on CC2
 * Notes:
 * DFP  (Unattached and attached) : 1'b1
 * UFP_dead : 1'b0
 * UFP_attached: 1'b1
 * Cable: Don't care
 */
#define PDSS_CC_CTRL_0_RD_CC2_DB_DIS                        (1UL << 21) /* <21:21> R:RW:0: */


/*
 * If RP_RD_CFG.HW_RP_RD_AUTO_TOGGLE == 0, then FW can use this register
 * 0: Disable CC1 Trimmed Rd Termination
 * 1: Enable CC1 Trimmed Rd Termination
 * Notes:
 * DFP_UA , DFP_A : 0
 * UFP_DEAD: 0
 * UFP_A: 1
 * Cable: 0
 */
#define PDSS_CC_CTRL_0_RD_CC1_EN                            (1UL << 22) /* <22:22> R:RW:0: */


/*
 * If RP_RD_CFG.HW_RP_RD_AUTO_TOGGLE == 0, then FW can use this register
 * 0: Disable CC2 Trimmed Rd Termination
 * 1: Enable CC2 Trimmed Rd Termination
 * Notes:
 * DFP_UA , DFP_A : 0
 * UFP_DEAD: 0
 * UFP_A: 1
 * Cable: 0
 * -------------
 * DFP_UA: DFP unattached
 * DFP_A: DFP attached
 * UFP_A: UFP attached
 */
#define PDSS_CC_CTRL_0_RD_CC2_EN                            (1UL << 23) /* <23:23> R:RW:0: */


/*
 * If RP_RD_CFG.HW_RP_RD_AUTO_TOGGLE == 0, then FW can use this register
 * 0: Disable CC1 Pull-up Termination (Rp)
 * 1: Enable CC1 Pull-up Termination
 * Notes:
 * DFP_UA  = 0
 * DFP_A : 1  (This bit must be set to 1'b0 if CC1 is not used for communication)
 * UFP_DEAD: 0
 * UFP_A: 0
 * Cable: 0
 */
#define PDSS_CC_CTRL_0_RP_CC1_EN                            (1UL << 24) /* <24:24> R:RW:0: */


/*
 * If RP_RD_CFG.HW_RP_RD_AUTO_TOGGLE == 0, then FW can use this register
 * 0: Disable CC2 Pull-up Termination (Rp)
 * 1: Enable CC2 Pull-up Termination
 * Notes:
 * DFP_UA  = 0
 * DFP_A : 1 ( (This bit must be set to 1'b0 if CC2 is not used for communication)
 * UFP_DEAD: 0
 * UFP_A: 0
 * Cable: 0
 */
#define PDSS_CC_CTRL_0_RP_CC2_EN                            (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Selects the Pull-up Termination current value
 * 0, 2 - 80uA (Default current broadcast)
 * 1 - 180uA (1.5A current broadcast)
 * 3 - 330uA (3.0A current broadcast)
 * Notes: This field matters only when RP_CC1/2_EN is set.
 */
#define PDSS_CC_CTRL_0_RP_MODE_MASK                         (0x0c000000UL) /* <26:27> R:RW:0: */
#define PDSS_CC_CTRL_0_RP_MODE_POS                          (26UL)


/*
 * SPARE
 */
#define PDSS_CC_CTRL_0_EN_HYST                              (1UL << 28) /* <28:28> R:RW:1: */


/*
 * SPARE
 */
#define PDSS_CC_CTRL_0_HYST_MODE                            (1UL << 29) /* <29:29> R:RW:1: */


/*
 * Controls the reference voltage generator for DFP vs. UFP/Cable operation
 * 0: UFP/Cable - voltage reference is 2.4V
 * 1: DFP - voltage reference is 2.6V
 * This register is a user configuration that must be set.
 * Notes: This bit should only be enablled for DFP
 */
#define PDSS_CC_CTRL_0_DFP_EN                               (1UL << 30) /* <30:30> R:RW:0: */


/*
 * Disables all active circuitry and DC paths
 * DS_ATTACH_DET_EN is still active
 * Notes: Firmware can disable the PHY for DFP waiting for attach. This will
 * save power while waiting for attach. Friware sets DS_ATTACH_DET_EN bit
 * to enable resistor based pullup on both CC lines. This pullup can be enabled
 * independent of PHY state.
 * DFP_UA: 1
 * DFP_A: 0
 * UFP: 0
 * Cable: 0
 */
#define PDSS_CC_CTRL_0_PWR_DISABLE                          (1UL << 31) /* <31:31> R:RW:1: */


/*
 * USBPD Hard IP C-connector Control Register 1
 */
#define PDSS_CC_CTRL_1_ADDRESS                              (0x400a0604UL)
#define PDSS_CC_CTRL_1                                      (*(volatile uint32_t *)(0x400a0604UL))
#define PDSS_CC_CTRL_1_DEFAULT                              (0x00005000UL)

/*
 * Enables ADFT Mode
 */
#define PDSS_CC_CTRL_1_CC_ADFT_EN                           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Selects ADFT connection
 * See s8usbpd BROS for decoding details
 */
#define PDSS_CC_CTRL_1_CC_ADFT_CTRL_MASK                    (0x0000003eUL) /* <1:5> R:RW:0: */
#define PDSS_CC_CTRL_1_CC_ADFT_CTRL_POS                     (1UL)


/*
 * SPARE
 */
#define PDSS_CC_CTRL_1_RX_OFFSET_EN                         (1UL << 6) /* <6:6> R:RW:0: */


/*
 * SPARE
 */
#define PDSS_CC_CTRL_1_RX_OFFSET_MASK                       (0x00000380UL) /* <7:9> R:RW:0: */
#define PDSS_CC_CTRL_1_RX_OFFSET_POS                        (7UL)


/*
 * Enables the deepsleep attach detect pull-up resistor
 * Set HI for a DFP waiting for attach
 */
#define PDSS_CC_CTRL_1_DS_ATTACH_DET_EN                     (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Transmit voltage select
 */
#define PDSS_CC_CTRL_1_VTX_SEL_MASK                         (0x00003800UL) /* <11:13> R:RW:2: */
#define PDSS_CC_CTRL_1_VTX_SEL_POS                          (11UL)


/*
 * 0: All outputs are isolated to a known value
 * 1: Normal operation
 */
#define PDSS_CC_CTRL_1_CC_ISO_N                             (1UL << 14) /* <14:14> R:RW:1: */


/*
 * Select reference source for transmitter
 * 0- Internal deepsleep reference
 * 1-CC_SHVT reference from reference generator selected
 */
#define PDSS_CC_CTRL_1_CC_VREF_1P1_SEL                      (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Controls the CC Charge Pump voltage references
 * 0 - Charge pump voltage is lower
 * 1 - Charge pump voltage is higher
 */
#define PDSS_CC_CTRL_1_CP_REF_SEL                           (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Connects cmp_dn comparator to CC1/CC2
 * 0 - CC1
 * 1 - CC2
 * See Note from CC_CTRL_0.CC_1V2 register.
 */
#define PDSS_CC_CTRL_1_CMP_FS_CC1V2                         (1UL << 17) /* <17:17> R:RW:0: */


/*
 * Selects the voltage threshold for cmp_fs comparator
 * Notes: 0.52V reference should be used for Fast Swap Detection
 */
#define PDSS_CC_CTRL_1_CMP_FS_VSEL_MASK                     (0x001c0000UL) /* <18:20> R:RW:0: */
#define PDSS_CC_CTRL_1_CMP_FS_VSEL_POS                      (18UL)


/*
 * not used inside
 */
#define PDSS_CC_CTRL_1_T_CC_40SHVT_MASK                     (0x7f000000UL) /* <24:30> R:RW:0:CC_40SHVT_EN */
#define PDSS_CC_CTRL_1_T_CC_40SHVT_POS                      (24UL)


/*
 * rx_alt_dis = 0 -> Newly added receiver is enabled.
 * rx_alt_dis = 1 -> Newly added receiver is disabled.
 */
#define PDSS_CC_CTRL_1_RX_ALT_DIS                           (1UL << 31) /* <31:31> R:RW:0:CC_40SHVT_EN */


/*
 * USBPD Hard IP DeepSleep-Reference Control Register
 */
#define PDSS_DPSLP_REF_CTRL_ADDRESS                         (0x400a0608UL)
#define PDSS_DPSLP_REF_CTRL                                 (*(volatile uint32_t *)(0x400a0608UL))
#define PDSS_DPSLP_REF_CTRL_DEFAULT                         (0x00000031UL)

/*
 * Setting this bit will enable the deepsleep current reference outputs.
 */
#define PDSS_DPSLP_REF_CTRL_IGEN_EN                         (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Setting this bit will enable the deepsleep reference generator ADFT mode.
 */
#define PDSS_DPSLP_REF_CTRL_DPSLP_ADFT_EN                   (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Controls the Deep Sleep reference ADFT mode
 * 0: ganged 7 iref current sources
 * 1: vrefdpslp voltage reference
 *
 */
#define PDSS_DPSLP_REF_CTRL_ADFT_CTRL                       (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Block enable input
 * 1 - All analog and DC paths cut off, outputs forced to known value
 *      This completely disables the CC Transceiver/Detect block.
 * 0 - Normal functionality
 * Notes: Firmware can disable the PHY for DFP waiting for attach. This will
 * save power while waiting for attach. Friware sets DS_ATTACH_DET_EN bit
 * to enable resistor based pullup on both CC lines. This pullup can be enabled
 * independent of PHY state.
 * DFP_UA: 1
 * DFP_A: 0
 * UFP: 0
 * Cable: 0
 */
#define PDSS_DPSLP_REF_CTRL_PD_DPSLP                        (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Control to "zero-out" PTAT/CTAT currents
 * 1. 00 : PTAT-CTAT Zeroed-out (ibias=0)
 * 2. 01 : CTAT zeroed-out, IBIAS = IPTAT
 * 3. 10 : PTAT zeroed-out, IBIAS-ICTAT
 * 4. 11 : Both enabled
 */
#define PDSS_DPSLP_REF_CTRL_PCTAT_CTRL_MASK                 (0x00000030UL) /* <4:5> R:RW:3: */
#define PDSS_DPSLP_REF_CTRL_PCTAT_CTRL_POS                  (4UL)


/*
 * USBPD Hard IP Regulator #1-4 and VSYS Supply Switch 1 Register
 */
#define PDSS_VREG_VSYS_CTRL_ADDRESS                         (0x400a061cUL)
#define PDSS_VREG_VSYS_CTRL                                 (*(volatile uint32_t *)(0x400a061cUL))
#define PDSS_VREG_VSYS_CTRL_DEFAULT                         (0x00000000UL)

/*
 * When VREG20_EN is set/de-assert, the regulator will turn off/on after
 * VREG20_ONOFF_CNTR cycle of clk_tx.
 * There won't be any delay is this register is set to zero.
 */
#define PDSS_VREG_VSYS_CTRL_VREG20_ONOFF_CNTR_MASK          (0x0000ff00UL) /* <8:15> R:RW:0:KEEP_REG_BIT */
#define PDSS_VREG_VSYS_CTRL_VREG20_ONOFF_CNTR_POS           (8UL)


/*
 * USBPD Hard IP AMUX #1-32 Register
 */
#define PDSS_AMUX_CTRL_ADDRESS                              (0x400a0628UL)
#define PDSS_AMUX_CTRL                                      (*(volatile uint32_t *)(0x400a0628UL))
#define PDSS_AMUX_CTRL_DEFAULT                              (0x00000000UL)

/*
 * AMUX select control
 */
#define PDSS_AMUX_CTRL_SEL_MASK                             (0x001fffffUL) /* <0:20> R:RW:0:USB_AMUX_NUM */
#define PDSS_AMUX_CTRL_SEL_POS                              (0UL)


/*
 * USBPD Hard IP DAC #1-4 Register
 */
#define PDSS_ADC_CTRL_ADDRESS                               (0x400a0680UL)
#define PDSS_ADC_CTRL                                       (*(volatile uint32_t *)(0x400a0680UL))
#define PDSS_ADC_CTRL_DEFAULT                               (0x80000200UL)

/*
 * Control bits for 8-bit DAC.
 * DAC_CNTRL register is used only if CPU wants to implement the SAR algorithm
 * in FW.
 */
#define PDSS_ADC_CTRL_DAC_CNTRL_MASK                        (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_ADC_CTRL_DAC_CNTRL_POS                         (0UL)


/*
 * ADC DFT Control:
 * 0: Normal operation
 * 1: DAC output voltage
 * p
 */
#define PDSS_ADC_CTRL_DFT_MUXSEL                            (1UL << 8) /* <8:8> R:RW:0: */


/*
 * This is for when high voltage supply for a port is not present. This bit
 * should be set when the high voltage is present,
 * in order to ensure that the outputs are set to know values.
 * 0: All outputs are isolated to a known value
 * 1: Normal operation
 */
#define PDSS_ADC_CTRL_ADC_ISO_N                             (1UL << 9) /* <9:9> R:RW:1: */


/*
 * Comparator Output.  If voltage on ID pin is less than DAC voltage, then
 * cmp_out is HIGH.
 */
#define PDSS_ADC_CTRL_CMP_OUT                               (1UL << 15) /* <15:15> RW:R:0: */


/*
 * Input Voltage select
 * p
 */
#define PDSS_ADC_CTRL_VSEL_MASK                             (0x00060000UL) /* <17:18> R:RW:0: */
#define PDSS_ADC_CTRL_VSEL_POS                              (17UL)


/*
 * Bit to select between VDDD reference and vref_dac
 * 0 : vref_dac
 * 1 : vddd
 */
#define PDSS_ADC_CTRL_VREF_DAC_SEL                          (1UL << 19) /* <19:19> R:RW:0: */


/*
 * ADC Power down control, active high.
 * p
 */
#define PDSS_ADC_CTRL_PD_LV                                 (1UL << 31) /* <31:31> R:RW:1: */


/*
 * USBPD Hard IP RefGen #1-4 Register 0
 */
#define PDSS_REFGEN_0_CTRL_ADDRESS                          (0x400a0690UL)
#define PDSS_REFGEN_0_CTRL                                  (*(volatile uint32_t *)(0x400a0690UL))
#define PDSS_REFGEN_0_CTRL_DEFAULT                          (0x80000000UL)

/*
 * DFT input clock enable.  Overrides all other clock inputs and modes.
 */
#define PDSS_REFGEN_0_CTRL_REFGEN_CLK_DFT_EN                (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Selection for external vs internal clock: For clk_sel=0 (default), internal
 * clock is used.
 */
#define PDSS_REFGEN_0_CTRL_REFGEN_CLK_SEL                   (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable for internal clock driver and gate for input clock
 */
#define PDSS_REFGEN_0_CTRL_REFGEN_CLK_EN                    (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Vref input select for the reference opamp for regulation blocks such as
 * lscsa, EA, CC block and vbus_mon. 0 for deepsleep reference of 0.74V and
 * 1 for bandgap reference of 1.2V
 */
#define PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_SEL                (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Vref input select for the reference opamp for monitor blocks UV-OV. 0
 * for deepsleep reference of 0.74V and 1 for bandgap reference of 1.2V
 */
#define PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_MON_SEL            (1UL << 4) /* <4:4> R:RW:0: */


/*
 * adft control inputs used to connect various analog internal signals to
 * atstio. See BROS for connectivity
 */
#define PDSS_REFGEN_0_CTRL_REFGEN_ATSTCFG_MASK              (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_REFGEN_0_CTRL_REFGEN_ATSTCFG_POS               (5UL)


/*
 * Block power down input
 * 1 - All analog and DC paths cut off, outputs forced to known value
 * 0 - Normal functionality
 */
#define PDSS_REFGEN_0_CTRL_REFGEN_PD                        (1UL << 31) /* <31:31> R:RW:1: */


/*
 * USBPD Hard IP RefGen #1-4 Register 1
 */
#define PDSS_REFGEN_1_CTRL_ADDRESS                          (0x400a06a0UL)
#define PDSS_REFGEN_1_CTRL                                  (*(volatile uint32_t *)(0x400a06a0UL))
#define PDSS_REFGEN_1_CTRL_DEFAULT                          (0x00000000UL)

/*
 * Selection for vsrc_new_p[0] comparator. This selection ranges from 200mV
 * to 2190mV for 0 to 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 * ACG1F:
 *     Selection bits for VBUS_C monitor comparator reference. This selection
 * ranges from 200mV to 2190mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 * CCG7D:
 * Selection for vsrc_new_p[0] comparator and PWM VIN OV comparator. This
 * selection ranges from 200mV to 2190mV for 0 to 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_1_CTRL_SEL0_MASK                        (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_REFGEN_1_CTRL_SEL0_POS                         (0UL)


/*
 * Selection for vsrc_new_m[0]  comparator. This selection ranges from 200mV
 * to 2190mV for 0 to 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 * ACG1F:
 *     Selection bits for VCONN switch reference. This selection ranges from
 * 200mV to 2190mV for 0 to 199 respectively.
 *      With the extra bits meaning a floating (unconnected) output
 * CCG7D:
 * Selection for vsrc_new_m[0]  comparator and PWM VIN UV comparator. This
 * selection ranges from 200mV to 2190mV for 0 to 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_1_CTRL_SEL1_MASK                        (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_REFGEN_1_CTRL_SEL1_POS                         (8UL)


/*
 * Selection for UV comparator. This selection ranges from 200mV to 2190mV
 * for 0 to 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 * ACG1F:
 *     Selection bits for VBUS_C UV comparator reference. This selection
 * ranges from 200mV to 2190mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_1_CTRL_SEL2_MASK                        (0x00ff0000UL) /* <16:23> R:RW:0: */
#define PDSS_REFGEN_1_CTRL_SEL2_POS                         (16UL)


/*
 * Selection for OV comparator. This selection ranges from 200mV to 2190mV
 * for 0 to 199 respectively. With the extra bits meaning a floating (unconnected)
 * output
 * ACG1F:
 *     Selection bits for VBUS_C  OV comparator reference. This selection
 * ranges from 200mV to 2190mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_1_CTRL_SEL3_MASK                        (0xff000000UL) /* <24:31> R:RW:0: */
#define PDSS_REFGEN_1_CTRL_SEL3_POS                         (24UL)


/*
 * USBPD Hard IP RefGen #1-4 Register 2
 */
#define PDSS_REFGEN_2_CTRL_ADDRESS                          (0x400a06b0UL)
#define PDSS_REFGEN_2_CTRL                                  (*(volatile uint32_t *)(0x400a06b0UL))
#define PDSS_REFGEN_2_CTRL_DEFAULT                          (0x00000000UL)

/*
 * Selection for SCP  comparator. This selection ranges from 130mV to 2120mV
 * for 0 to 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 * PAG1S:
 *     FeedForward OV
 * ACG1F :
 *     Selection bits for NGDO block reference. This selection ranges from
 * 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 * CCG7D:
 *   Selection bits for 20CSA SCP comparator reference. This selection ranges
 * from 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 * PAG2S : Vref_integ [FW]
 */
#define PDSS_REFGEN_2_CTRL_SEL4_MASK                        (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_REFGEN_2_CTRL_SEL4_POS                         (0UL)


/*
 * Selection for OCP comparator. This selection ranges from 130mV to 2120mV
 * for 0 to 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 * ACG1F:
 *     Selection bits for HSCSA OCP comparator reference. This selection
 * ranges from 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 * CCG7D:
 *   Selection bits for 20CSA OCP comparator reference. This selection ranges
 * from 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_2_CTRL_SEL5_MASK                        (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_REFGEN_2_CTRL_SEL5_POS                         (8UL)


/*
 * Selection for PFC_disable comparator. This selection ranges from 130mV
 * to 2120mV for 0 to 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 * ACG1F:
 *     Selection bits for C2A dongle detect comparator reference. This selection
 * ranges from 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 * CCG7D:
 *   Selection bits for CBL_1 (PFC) comparator reference. This selection
 * ranges from 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_2_CTRL_SEL6_MASK                        (0x00ff0000UL) /* <16:23> R:RW:0: */
#define PDSS_REFGEN_2_CTRL_SEL6_POS                         (16UL)


/*
 * Selection for PFC_enable comparator. This selection ranges from 130mV
 * to 2120mV for 0 to 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 * ACG1F:
 *     Selection bits for HS CSA SCP comparator reference. This selection
 * ranges from 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 * CCG7D:
 *   Selection bits for ILIM reference. This selection ranges from 130mV
 * to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_2_CTRL_SEL7_MASK                        (0xff000000UL) /* <24:31> R:RW:0: */
#define PDSS_REFGEN_2_CTRL_SEL7_POS                         (24UL)


/*
 * USBPD Hard IP RefGen #1-4 Register 3
 */
#define PDSS_REFGEN_3_CTRL_ADDRESS                          (0x400a06c0UL)
#define PDSS_REFGEN_3_CTRL                                  (*(volatile uint32_t *)(0x400a06c0UL))
#define PDSS_REFGEN_3_CTRL_DEFAULT                          (0x00000000UL)

/*
 * Selection for SR_disable comparator. This selection ranges from 130mV
 * to 2120mV for 0 to 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 * ACG1F:
 *     Selection bits for RCP CSA comparator reference. This selection ranges
 * from 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 * CCG7D/PAG2S:
 *   Selection bits for CBL_0 (SR) Comparator reference. This selection ranges
 * from 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_3_CTRL_SEL8_MASK                        (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_REFGEN_3_CTRL_SEL8_POS                         (0UL)


/*
 * Selection for SR_enable comparator. This selection ranges from 130mV to
 * 2120mV for 0 to 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 * PAG1S:
 *     FeedForward UV
 * ACG1F:
 *     Selection bits for 5V pump block reference. This selection ranges
 * from 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 * CCG7D:
 *   Selection bits for PWM SKIP Comparator reference. This selection ranges
 * from 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 * PAG2S: : Selection of vref_0p74 from refgen
 */
#define PDSS_REFGEN_3_CTRL_SEL9_MASK                        (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_REFGEN_3_CTRL_SEL9_POS                         (8UL)


/*
 * Selection for EA. This selection ranges from 130mV to 2120mV for 0 to
 * 199 respectively.
 * With the extra bits meaning a floating (unconnected) output
 * ACG1F:
 *     Selection for RCP block VBUS_P monitor comparator reference. This
 * selection ranges from 130mV to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 * CCG7D:
 *   Selection bits for EA CC  reference. This selection ranges from 130mV
 * to 2120mV for 0 to 199 respectively.
 *     With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_3_CTRL_SEL10_MASK                       (0x00ff0000UL) /* <16:23> R:RW:0: */
#define PDSS_REFGEN_3_CTRL_SEL10_POS                        (16UL)


/*
 * USBPD Hard IP RefGen #1-4 Register 4
 */
#define PDSS_REFGEN_4_CTRL_ADDRESS                          (0x400a06d0UL)
#define PDSS_REFGEN_4_CTRL                                  (*(volatile uint32_t *)(0x400a06d0UL))
#define PDSS_REFGEN_4_CTRL_DEFAULT                          (0x0000091bUL)

/*
 * Not Used in ACG1F.
 * Selection for dischg_en. This selection ranges from 450mV to 800mV for
 * 0 to 7 respectively in steps of 50mV.
 * With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_4_CTRL_SEL11_MASK                       (0x00000007UL) /* <0:2> R:RW:3: */
#define PDSS_REFGEN_4_CTRL_SEL11_POS                        (0UL)


/*
 * Not Used in ACG1F and PAG2S.
 * Selection for vbus_c_mon. This selection ranges from 650mV to 1000mV for
 * 0 to 7 respectively in steps of 50mV.
 * With the extra bits meaning a floating (unconnected) output
 * CCG7D:
 * Selection for 40VREG reference. This selection ranges from 650mV to 1000mV
 * for 0 to 7 respectively in steps of 50mV.
 * With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_4_CTRL_SEL12_MASK                       (0x00000038UL) /* <3:5> R:RW:3: */
#define PDSS_REFGEN_4_CTRL_SEL12_POS                        (3UL)


/*
 * Selection for ADC_Ref. This selection ranges from 1960mV to 2030mV for
 * 0 to 7 respectively in steps of 10mV.
 * With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_4_CTRL_SEL13_MASK                       (0x000001c0UL) /* <6:8> R:RW:4: */
#define PDSS_REFGEN_4_CTRL_SEL13_POS                        (6UL)


/*
 * Not Used in ACG1F.
 * Selection for CC_SHVT Ref. This selection ranges from 1090mV to 1160mV
 * for 0 to 7 respectively in steps of 10mV.
 * With the extra bits meaning a floating (unconnected) output
 */
#define PDSS_REFGEN_4_CTRL_SEL14_MASK                       (0x00000e00UL) /* <9:11> R:RW:4: */
#define PDSS_REFGEN_4_CTRL_SEL14_POS                        (9UL)


/*
 * USBPD Hard IP Battery Charger #1-4 Register0
 */
#define PDSS_BCH_DET_0_CTRL_ADDRESS                         (0x400a0700UL)
#define PDSS_BCH_DET_0_CTRL                                 (*(volatile uint32_t *)(0x400a0700UL))
#define PDSS_BCH_DET_0_CTRL_DEFAULT                         (0x80000000UL)

/*
 * Enables BC1.2 Circuitry, Active High
 */
#define PDSS_BCH_DET_0_CTRL_EN_CHGDET                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * IDP_SINK enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_IDP_SNK_EN                      (1UL << 1) /* <1:1> R:RW:0: */


/*
 * IDM_SINK enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_IDM_SNK_EN                      (1UL << 2) /* <2:2> R:RW:0: */


/*
 * VDP_SRC enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_VDP_SRC_EN                      (1UL << 3) /* <3:3> R:RW:0: */


/*
 * VDM_SRC enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_VDM_SRC_EN                      (1UL << 4) /* <4:4> R:RW:0: */


/*
 * IDP_SRC enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_IDP_SRC_EN                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * DCP Short enable, Active High
 * Shorts D+ to D- with low resistance path
 */
#define PDSS_BCH_DET_0_CTRL_DCP_EN                          (1UL << 6) /* <6:6> R:RW:0: */


/*
 * RDM_DWN enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_RDM_PD_EN                       (1UL << 7) /* <7:7> R:RW:0: */


/*
 * RDM_UP enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_RDM_PU_EN                       (1UL << 8) /* <8:8> R:RW:0: */


/*
 * RDP_DWN enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_RDP_PD_EN                       (1UL << 9) /* <9:9> R:RW:0: */


/*
 * RDP_UP enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_RDP_PU_EN                       (1UL << 10) /* <10:10> R:RW:0: */


/*
 * RDAT_LKG_DP enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_RDAT_LKG_DP_EN                  (1UL << 11) /* <11:11> R:RW:0: */


/*
 * RDAT_LKG_DM enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_RDAT_LKG_DM_EN                  (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Output Comparator Negative input select bits:
 * 00 - DM pin
 * 01 - Vref
 * 10 - DP pin
 * 11 - GND
 */
#define PDSS_BCH_DET_0_CTRL_CMP1_INN_SEL_MASK               (0x00006000UL) /* <13:14> R:RW:0: */
#define PDSS_BCH_DET_0_CTRL_CMP1_INN_SEL_POS                (13UL)


/*
 * Output Comparator Positive input select bits:
 * 00 - DM pin
 * 01 - Vref
 * 10 - DP pin
 * 11 - GND
 */
#define PDSS_BCH_DET_0_CTRL_CMP1_INP_SEL_MASK               (0x00018000UL) /* <15:16> R:RW:0: */
#define PDSS_BCH_DET_0_CTRL_CMP1_INP_SEL_POS                (15UL)


/*
 * Reference voltage select bits
 * 0 - 0.325V
 * 1 - 0.7V
 * 2 - 0.85V
 * 3 - 1.4V
 * 4 - 1.7V
 * 5 - 2.0V
 * 6 - 2.2V
 * 7 - 2.9V
 */
#define PDSS_BCH_DET_0_CTRL_CMP1_VREF_SEL_MASK              (0x000e0000UL) /* <17:19> R:RW:0: */
#define PDSS_BCH_DET_0_CTRL_CMP1_VREF_SEL_POS               (17UL)


/*
 * Enable Output Comparator, Active High
 */
#define PDSS_BCH_DET_0_CTRL_EN_COMP1_CHGDET                 (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Comparator Offset Select:
 * 0: -50mV
 * 1: -100mV
 * 2: -150mV
 * 3: -200mV
 * 4: +50mV
 * 5: +100mV
 * 6: +150mV
 * 7: +200mV
 */
#define PDSS_BCH_DET_0_CTRL_CMP1_OFFSET_SEL_MASK            (0x00e00000UL) /* <21:23> R:RW:0: */
#define PDSS_BCH_DET_0_CTRL_CMP1_OFFSET_SEL_POS             (21UL)


/*
 * Output Comparator Offset Enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_CMP1_OFFSET_EN                  (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Output Comparator Unity Gain Mode Enable, Active High
 */
#define PDSS_BCH_DET_0_CTRL_CMP1_UGM_EN                     (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Charger Detect Block Power Down
 */
#define PDSS_BCH_DET_0_CTRL_PD                              (1UL << 31) /* <31:31> R:RW:1: */


/*
 * USBPD Hard IP Battery Charger #1-4 Register1
 */
#define PDSS_BCH_DET_1_CTRL_ADDRESS                         (0x400a0710UL)
#define PDSS_BCH_DET_1_CTRL                                 (*(volatile uint32_t *)(0x400a0710UL))
#define PDSS_BCH_DET_1_CTRL_DEFAULT                         (0x00001000UL)

/*
 * Enable Charger Detect ADFT Mode
 */
#define PDSS_BCH_DET_1_CTRL_CHGDET_ADFT_EN                  (1UL << 0) /* <0:0> R:RW:0: */


/*
 * ADFT Select Control.  See the s8usbpd_ver3 BROS for more details
 */
#define PDSS_BCH_DET_1_CTRL_CHGDET_ADFT_CTRL_MASK           (0x0000001eUL) /* <1:4> R:RW:0: */
#define PDSS_BCH_DET_1_CTRL_CHGDET_ADFT_CTRL_POS            (1UL)


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced low
 */
#define PDSS_BCH_DET_1_CTRL_CHGDET_ISO_N                    (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Apple detection enable to detect the 2.9V termination voltage on
 */
#define PDSS_BCH_DET_1_CTRL_CHGDET_APP_DET                  (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Apple DM termination enable control
 * 00 - Termination disabled
 * 01 - 1.5V
 * 10 - 2.5V: This mode uses the BC1.2 Driver, so BCH_DET_1_CTRL.CHGDET_APP_DET,
 * BCH_DET_0_CTRL.EN_CHGDET and BCH_DET_0_CTRL.VDM_SRC_EN must be set high
 * 11 - DO NOT USE: For 3.3V termination, use the RPU pullup. Set BCH_DET_0_CTRL.RDM_PU_EN
 * high
 */
#define PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DM_MASK       (0x00000180UL) /* <7:8> R:RW:0: */
#define PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DM_POS        (7UL)


/*
 * Apple DP termination enable control
 * 00 - Termination disabled
 * 01 - 1.5V
 * 10 - 2.5V: This mode uses the BC1.2 Driver, so BCH_DET_1_CTRL.CHGDET_APP_DET,
 * BCH_DET_0_CTRL.EN_CHGDET and BCH_DET_0_CTRL.VDP_SRC_EN must be set high
 * 11 - DO NOT USE: For 3.3V termination, use the RPU pullup. Set BCH_DET_0_CTRL.RDP_PU_EN
 * high
 */
#define PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DP_MASK       (0x00000600UL) /* <9:10> R:RW:0: */
#define PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DP_POS        (9UL)


/*
 * IDP_SRC enable, Active High. Enables idm source current to detect Samsung
 * AFC termination.
 */
#define PDSS_BCH_DET_1_CTRL_CHGDET_IDM_SRC_EN               (1UL << 11) /* <11:11> R:RW:0: */


/*
 * To select between bandgap or deepsleep reference volatge as input.
 * 1 -> Bandgap reference voltage.
 * 0 -> Deepsleep reference voltage.
 */
#define PDSS_BCH_DET_1_CTRL_REFGEN_REFSEL                   (1UL << 12) /* <12:12> R:RW:1: */


/*
 * Output Comparator Negative input select bits:
 * 00 - DM pin
 * 01 - Vref
 * 10 - DP pin
 * 11 - GND
 */
#define PDSS_BCH_DET_1_CTRL_CMP2_INN_SEL_MASK               (0x00006000UL) /* <13:14> R:RW:0: */
#define PDSS_BCH_DET_1_CTRL_CMP2_INN_SEL_POS                (13UL)


/*
 * Output Comparator Positive input select bits:
 * 00 - DM pin
 * 01 - Vref
 * 10 - DP pin
 * 11 - GND
 */
#define PDSS_BCH_DET_1_CTRL_CMP2_INP_SEL_MASK               (0x00018000UL) /* <15:16> R:RW:0: */
#define PDSS_BCH_DET_1_CTRL_CMP2_INP_SEL_POS                (15UL)


/*
 * Reference voltage select bits
 * 0 - 0.325V
 * 1 - 0.7V
 * 2 - 0.85V
 * 3 - 1.4V
 * 4 - 1.7V
 * 5 - 2.0V
 * 6 - 2.2V
 * 7 - 2.9V
 */
#define PDSS_BCH_DET_1_CTRL_CMP2_VREF_SEL_MASK              (0x000e0000UL) /* <17:19> R:RW:0: */
#define PDSS_BCH_DET_1_CTRL_CMP2_VREF_SEL_POS               (17UL)


/*
 * Enable Output Comparator, Active High
 */
#define PDSS_BCH_DET_1_CTRL_EN_COMP2_CHGDET                 (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Comparator Offset Select:
 * 0: -50mV
 * 1: -100mV
 * 2: -150mV
 * 3: -200mV
 * 4: +50mV
 * 5: +100mV
 * 6: +150mV
 * 7: +200mV
 */
#define PDSS_BCH_DET_1_CTRL_CMP2_OFFSET_SEL_MASK            (0x00e00000UL) /* <21:23> R:RW:0: */
#define PDSS_BCH_DET_1_CTRL_CMP2_OFFSET_SEL_POS             (21UL)


/*
 * Output Comparator Offset Enable, Active High
 */
#define PDSS_BCH_DET_1_CTRL_CMP2_OFFSET_EN                  (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Output Comparator Unity Gain Mode Enable, Active High
 */
#define PDSS_BCH_DET_1_CTRL_CMP2_UGM_EN                     (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Apple 2.5V DP termination with 5K,10K,20K,100K resistance in series path
 * to enable simultaneous apple and BC detection
 */
#define PDSS_BCH_DET_1_CTRL_APPLE_TERM_MASK                 (0x3c000000UL) /* <26:29> R:RW:0:PASC_PASC2_CCG7D_EN */
#define PDSS_BCH_DET_1_CTRL_APPLE_TERM_POS                  (26UL)


/*
 * USBPD Hard IP VBUS Discharge SHV #1-8 Register0
 */
#define PDSS_DISCHG_SHV_CTRL_ADDRESS(n)                     (0x400a0790UL + ((n) * (0x0004UL)))
#define PDSS_DISCHG_SHV_CTRL(n)                             (*(volatile uint32_t *)(0x400a0790UL + ((n) * 0x0004UL)))
#define PDSS_DISCHG_SHV_CTRL_DEFAULT                        (0x00000000UL)

/*
 * VBUS Discharge 1-8 control signal, Active High
 */
#define PDSS_DISCHG_SHV_CTRL_DISCHG_EN                      (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Used only for CCG3PA-VBUS_IN, Second instance of s8usbpd_dischg_shv_top
 * (Address 0x0794)
 *    0: The disch_en pin of s8usbpd_dischg_shv_top is driven by comparator
 * output;
 *        In this Mode Discharge Enable/Disable is controlled through Discharge
 * Comparator Control Register (COMP_CTRL[3].COMP_PD)
 *        Discharge Enabled: COMP_PD = 0; Disabled: COMP_PD = 1;
 *    1: The disch_en pin of s8usbpd_dischg_shv_top is driven by DISCHG_SHV_CTRL.DISCHG_EN
 * register
 */
#define PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG                  (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Following are for CCG5  specific vbus discaharge control seetings
 * 00000: HiZ
 * 00001: 2K Ohms
 * 00011: 1K Ohms
 * 00111: 0.66K Ohms
 * 01111: 0.5K Ohms
 * 11111: 0.4K Ohms
 *
 * CCG3PA*A and CCG3PA2 - pluese use following discharge control settings
 * Discharge Drive Strenght control
 * 00000:HIZ
 * 00001: 500 Ohms - 2000Ohms
 * 00010: 250 Ohms - 1000Ohms
 * 00100: 125 Ohms - 500Ohms
 * 01000: 62.5 Ohms - 250Ohms
 * 10000: 31.25 Ohms - 125Ohms
 *
 * PAG2S - please use following discharge control settings
 * Discharge Drive Strenght control
 * VBUS_IN discharge :(look at s8pdsv2 BROS XLS for VBUS_C discharge which
 * is using dischg_low_r)
 * 00000:HIZ
 * 00001: 500 Ohms - 2400Ohms
 * 00010: 250 Ohms - 1600Ohms
 * 00100: 125 Ohms - 600Ohms
 * 01000: 62.5 Ohms - 300Ohms
 * 10000: 31.25 Ohms - 150Ohms
 */
#define PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK                 (0x0000007cUL) /* <2:6> R:RW:0: */
#define PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS                  (2UL)


/*
 * VBUS_IN discharge : LSB bit --> 1: 1000 Ohms - 4000Ohms
 * :(look at s8pdsv2 BROS XLS for VBUS_C discharge which is using dischg_low_r)
 */
#define PDSS_DISCHG_SHV_CTRL_DISCHG_DS_EXT_MASK             (0x00000180UL) /* <7:8> R:RW:0:DISCHG40_EN */
#define PDSS_DISCHG_SHV_CTRL_DISCHG_DS_EXT_POS              (7UL)


/*
 * Used to select the source of dischg enable
 *    0: Use the default sync dischg module
 *    1: Use the async gate contoller module
 */
#define PDSS_DISCHG_SHV_CTRL_SEL_DISCHG_EN_SRC              (1UL << 9) /* <9:9> R:RW:0:DISCHG40_EN */


/*
 * USBPD Hard IP Comparators #1-24 Register
 * CCG3PA:
 *       Function                            Comparator#       CLK_FILTER#
 *       CLK_LF#    FILTER21  FILTER22
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *           UV                                        #0               
 *              #0                                   #0            #0
 *           OV                                        #1               
 *              #1                                   #1            #1
 *           VBUS_MON                          #2                       
 *     N/A                 #0              #7            #7
 *           DISCHG                                #3                   
 *          #2                                   #2            #2
 *           SCP                                      #4                
 *             #3                                   #3            #3
 *           OCP                                      #5                
 *             #4                                   #4            #4
 *           PFC                                      #6                
 *             #5                                   #5            #5
 *           VSRC_NEW_P                      #7                         
 *     N/A                #1             #8            #8
 *           VSRC_NEW_P                      #8                         
 *     N/A                #2             #9            #9
 * CCG5-Port0 / CCG5C:
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *           UV                                        #0               
 *              #0                                   #0            #0
 *           OV                                        #1               
 *              #1                                   #1            #1
 *           VBUS_MON                          #2                       
 *     N/A                 #0              #2            #2
 *           VSYS_DET                           #3                      
 *       N/A                #1               #3           #3
 * CCG5-Port1:
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *           UV                                        #0               
 *              #0                                   #0            #0
 *           OV                                        #1               
 *              #1                                   #1            #1
 *           VBUS_MON                          #2                       
 *     N/A                 #0              #2            #2
 * CCG6:
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *           UV                                        #0               
 *              #0                                   #0            #0
 *           OV                                        #1               
 *              #1                                   #1            #1
 *           VBUS_MON                          #2                       
 *     N/A                 #0              #2            #2
 *           VSYS_DET                           #3                      
 *       N/A                #1               #3           #3
 *           DP_SYS COMP                    #4                          
 *  N/A                N/A              N/A      N/A
 *           DM_SYS COMP                   #5                           
 * N/A                N/A               N/A       N/A
 * ACG1F:
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *           UV                                        #0               
 *              #0                                   #0            #0
 *           OV                                        #1               
 *              #1                                   #1            #1
 *           VBUS_MON                          #2                       
 *     N/A                 #0              #2            #2
 *           DP_SYS COMP                     #3                         
 *   N/A                N/A              N/A      N/A
 *           DM_SYS COMP                    #4                          
 *  N/A                N/A               N/A       N/A
 *
 * CCG6DF-Port0 / CCG6SF:
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *           UV                                        #0               
 *              #0                                   #0            #0
 *           OV                                        #1               
 *              #1                                   #1            #1
 *           VSYS_DET                           #2                      
 *       N/A                #1             #3           #3
 * CCG6DF-Port1:
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *           UV                                        #0               
 *              #0                                   #0            #0
 *           OV                                        #1               
 *              #1                                   #1            #1
 * CCG7D:
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *           UV                                       #0                
 *             #0                    N/A           #0          #0
 *           OV                                       #1                
 *             #1                    N/A           #1          #1
 *           CBL_1                                 #2                   
 *          #4                    N/A           #2          #2
 *           DISCHG                              #3                     
 *        #2                    N/A           #3          #3
 *           CBL_0                                 #4                   
 *          #3                    N/A           #4          #4
 *           VSRC_NEW_P                   #5                            
 * N/A                 #1              #5          #5
 *           VSRC_NEW_M                 #6                             N/A
 *                 #2              #6          #6
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------/
 *  Function                            Comparator#       CLK_FILTER#   
 *    CLK_LF#    FILTER21  FILTER22
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------/
 * PMG1S3-Port0:
 *           UV                                    #0                   
 *             #0                   NA           #0          #0
 *           OV                                    #1                   
 *             #1                   NA           #1          #1
 *           Vsys_det                        #2                         
 *       NA                  #3            NA         NA
 *           SBU1                                #3                     
 *           NA                  #0            NA         NA
 *           SBU2                                #4                     
 *           NA                  #1            NA         NA
 *
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------/
 * PMG1S3-Port1:
 *           UV                                    #0                   
 *             #0                   NA           #0          #0
 *           OV                                    #1                   
 *             #1                   NA           #1          #1
 *           SBU1                                #2                     
 *           NA                  #0            NA          NA
 *           SBU2                                #3                     
 *           NA                  #1            NA          NA
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------/
 *
 *
 *
 *
 */
#define PDSS_COMP_CTRL_ADDRESS(n)                           (0x400a07d0UL + ((n) * (0x0004UL)))
#define PDSS_COMP_CTRL(n)                                   (*(volatile uint32_t *)(0x400a07d0UL + ((n) * 0x0004UL)))
#define PDSS_COMP_CTRL_DEFAULT                              (0x80000001UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_COMP_CTRL_COMP_ISO_N                           (1UL << 0) /* <0:0> R:RW:1: */


/*
 * ADFT control inputs used to connect various analog internal signals to
 * ADFT buses
 */
#define PDSS_COMP_CTRL_COMP_ADFT_CTRL_MASK                  (0x0000000eUL) /* <1:3> R:RW:0: */
#define PDSS_COMP_CTRL_COMP_ADFT_CTRL_POS                   (1UL)


/*
 * Rising edge hysteresis enable.  Does not affect falling edge accuracy.
 */
#define PDSS_COMP_CTRL_COMP_HYST_R_EN                       (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Falling edge hysteresis enable.  Does not affect rising edge accuracy.
 */
#define PDSS_COMP_CTRL_COMP_HYST_F_EN                       (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Block power down input
 * 1 - All analog and DC paths cut off, outputs forced to known value
 * 0 - Normal functionality
 */
#define PDSS_COMP_CTRL_COMP_PD                              (1UL << 31) /* <31:31> R:RW:1: */


/*
 * USBPD Hard IP 5V PUMP control Register
 * CCG5:
 *   First Instance:
 *   USBPD0.5VPUMP[0] ==> cc_shvt_top
 *   USBPD0.5VPUMP[1] ==> SBU switch
 *   USBPD0.5VPUMP[2] ==> DPDM
 *  Second Instance
 *   USBPD0.5VPUMP[0] ==> cc_shvt_top
 *   USBPD1.5VPUMP[0] ==> SBU switch
 *   USBPD1.5VPUMP[1] ==> DPDM
 * CCG6:
 *   First Instance:
 *   USBPD.5VPUMP[0] ==> cc_shvt_top
 *   USBPD.5VPUMP[1] ==> SBU switch
 *   USBPD.5VPUMP[2] ==> DPDM
 */
#define PDSS_PUMP5V_CTRL_ADDRESS                            (0x400a086cUL)
#define PDSS_PUMP5V_CTRL                                    (*(volatile uint32_t *)(0x400a086cUL))
#define PDSS_PUMP5V_CTRL_DEFAULT                            (0x00000008UL)

/*
 * ADFT control bits : to get internal signals of 5vpump on adft<1:0>
 * control signal
 * 000 : adft<0> : Z                                                    ;
 * adft<1> : Z
 * 001 : adft<0> : vref (internal reference voltage)   ; adft<1> : vfb (feed
 * back of the opamp)
 * 010 : adft<0> : internal regulated voltage              ; adft<1> : charge
 * pump output voltage
 * 011 : adft<0> : internal lv clock                              ; adft<1>
 *  : internal hv clk
 * 100 : adft<0> : comparator for SOA output           ; adft<1>   : Resistive
 * divider feed back voltage for comparator
 * 101 : adft<0> : gnd                                                 ;
 * adft<1>   : Resistive divider feedback voltage for pump good comparator
 */
#define PDSS_PUMP5V_CTRL_PUMP5V_ADFT_MASK                   (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_PUMP5V_CTRL_PUMP5V_ADFT_POS                    (0UL)


/*
 * Bypasses the pump output and connects the vddd to pump output
 * PUMP5V_BYPASS_LV = 1 : pump output is connected to VDDD through a PMOS
 * switch
 * In CMG1, The bypass_lv port of First 5V Pump hard IP will be driven to
 * "0" until there is a write to this register for the first 5V Pump hard
 * IP.
 * After the first write to the first 5V Pump hard IP, the value of the bypass_lv
 * port of the first 5V Pump Hard IP will be driven by PUMP5V_BYPASS_LV register
 * value.
 */
#define PDSS_PUMP5V_CTRL_PUMP5V_BYPASS_LV                   (1UL << 3) /* <3:3> R:RW:1: */


/*
 * External clock enable signal for pump.
 * PUMP5V_CLK_SEL = 1 Bypasses the LV clock and external clock can be used
 */
#define PDSS_PUMP5V_CTRL_PUMP5V_CLK_SEL                     (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Enable signal for the pump.
 *  PUMP5V_PUMP_EN = 0 will disable the pump and set the output of pump to
 * 0
 *  Delay/sequencing requirement:
 *      i. pump5v_pump_en going high  to pump5v_del_pump_en going high should
 * be 50us later. (50us should be programmable from 30us to 100us).
 *     ii. pump5v_pump_en going low to pump5v_del_pump_en going low need
 * not have any delay.
 *     iii. pump5v_pump_en going high should go prior to pump5v_bypass_lv
 * going low with a delay of 10us.
 *     iv. pump5v_bypass_lv should go high prior to pump5v_pump_en going
 * low (100ns to few uS earlier is fine)
 *
 * In CMG1, The pump_en port of First 5V Pump hard IP will be driven to "1"
 * until there is a write to this register for the first 5V Pump hard IP.
 * After the first write to the first 5V Pump hard IP, the value of the pump_en
 * port of the first 5V Pump Hard IP will be driven by PUMP5V_PUMP_EN register
 * value.
 */
#define PDSS_PUMP5V_CTRL_PUMP5V_PUMP_EN                     (1UL << 5) /* <5:5> R:RW:0: */


/*
 * adft enable signal for 5v pump.
 * PUMP5V_ADFT_EN = 1 adft block would be enabled
 */
#define PDSS_PUMP5V_CTRL_PUMP5V_ADFT_EN                     (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Delayed enable signal for the pump.
 * In CMG1, The del_pump_en port of First 5V Pump hard IP will be driven
 * to "1" until there is a write to this register for the first 5V Pump hard
 * IP.
 * After the first write to the first 5V Pump hard IP, the value of the del_pump_en
 * port of the first 5V Pump Hard IP will be driven by PUMP5V_DEL_PUMP_EN
 * register value.
 */
#define PDSS_PUMP5V_CTRL_PUMP5V_DEL_PUMP_EN                 (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Test modes for the 5v pump
 * t_pump[15:12] : Change the trip point for pump_good_hv.
 * t_pump[11]      : bypasses the opamp and connects the pump in comparator
 * mode
 * t_pump[10:8]   :  Change the trip point for comparator whuch is used for
 * SOA protection
 */
#define PDSS_PUMP5V_CTRL_PUMP5V_T_PUMP_MASK                 (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_PUMP5V_CTRL_PUMP5V_T_PUMP_POS                  (8UL)


/*
 * USBPD Hard IP VBUS Discharge SHV #1-8 Register1
 */
#define PDSS_DISCHG_SHV_1_CTRL_ADDRESS(n)                   (0x400a089cUL + ((n) * (0x0004UL)))
#define PDSS_DISCHG_SHV_1_CTRL(n)                           (*(volatile uint32_t *)(0x400a089cUL + ((n) * 0x0004UL)))
#define PDSS_DISCHG_SHV_1_CTRL_DEFAULT                      (0x00004000UL)

/*
 * This bit enables the discharge protection funcitonality
 */
#define PDSS_DISCHG_SHV_1_CTRL_FAILSAFE_EN                  (1UL << 0) /* <0:0> R:RW:0: */


/*
 * this bit selects the driving of the s8usbpd_dischg_shv_top enable
 * 0 - Enabled when FW enables the DISCHG
 * 1 - Dutycycle configured by FW is applied on DISCHG
 */
#define PDSS_DISCHG_SHV_1_CTRL_MODE                         (1UL << 1) /* <1:1> R:RW:0: */


/*
 * This bit selects the source for monitoring the voltage level of VBUS.
 * IF the selected source does not fall when the programmed timer expires,
 * the protection is triggered.
 * CCG3PA2:
 * 0 - HS Filter 0 output (UV)                     1 - HS Filter 1 output
 * (OV)
 * 2 - HS Filter 2 output (DISCHG_EN)       3 - HS Filter 3 output (SCP)
 * 4 - HS Filter 4 output (OCP)                   5 - HS Filter 5 output
 * (PFC)
 * 6 - HS Filter 6 output (SR)                     7 - LS Filter 0 output
 * (VBUS_MON)
 * 8 - LS Filter 1 output (Vsrc_new_p)        9 - LS Filter 2 output (Vsrc_new_m)
 * 10 - ADC 0 Filter output                       11 - ADC 1 Filter output
 * PAG1S:
 * 0 - HS Filter 0 output (UV)                       1 - HS Filter 1 output
 * (OV)
 * 2 - HS Filter 2 output (DISCHG_EN)         3 - HS Filter 3 output (SCP)
 * 4 - HS Filter 4 output (OCP)                     5 - HS Filter 5 output
 * (PFC)
 * 6 - HS Filter 6 output (SR)                       7 - LS Filter 0 output
 * (VBUS_MON)
 * 8 - LS Filter 1 output (Vsrc_new_p)           9 - LS Filter 2 output (Vsrc_new_m)
 * 10 - ADC 0 Filter output                          11 - FILT21 output (Based
 * on INTR11_FILTER_CFG.FILT21_INPUT_SEL)
 * 12 - FILT22 output (Based on INTR11_FILTER_CFG.FILT22_INPUT_SEL)
 * This field needs to be programmed only when FAILSAFE_EN is 0
 * Source_sel programming for PAG1S ONLY:
 * FET0 SOURCE_SEL[4:0] =  DISCHG_SHV_1_CTRL0[6:2]
 * FET1 SOURCE_SEL[4:0] = {DISCHG_SHV_1_CTRL1[3:2],DISCHG_SHV_1_CTRL0[9:7]}
 * FET2 SOURCE_SEL[4:0] =  DISCHG_SHV_1_CTRL1[8:4]
 * FET3 SOURCE_SEL[4:0] = {DISCHG_SHV_1_CTRL2[5:2],DISCHG_SHV_1_CTRL1[9]}
 * FET4 SOURCE_SEL[4:0] = {DISCHG_SHV_1_CTRL3[2],DISCHG_SHV_1_CTRL2[9:6]}
 * FET5 SOURCE_SEL[4:0] =  DISCHG_SHV_1_CTRL3[7:3]
 * FET6 SOURCE_SEL[4:0] = {DISCHG_SHV_1_CTRL4[4:2],DISCHG_SHV_1_CTRL3[9:8]}
 * FET7 SOURCE_SEL[4:0] =  DISCHG_SHV_1_CTRL4[9:5]
 * Source_sel programming for CCG7D ONLY:
 * FET0 SOURCE_SEL[4:0] =  DISCHG_SHV_1_CTRL0[6:2]
 * FET1 SOURCE_SEL[4:0] = {DISCHG_SHV_1_CTRL1[3:2],DISCHG_SHV_1_CTRL0[9:7]}
 */
#define PDSS_DISCHG_SHV_1_CTRL_SOURCE_SEL_MASK              (0x000003fcUL) /* <2:9> R:RW:0: */
#define PDSS_DISCHG_SHV_1_CTRL_SOURCE_SEL_POS               (2UL)


/*
 * Time period in LF clock cycles after which the selected source has to
 * be monitored to trigger the protection circuit. This field needs to be
 * programmed only when FAILSAFE_EN is 0.
 * [FW]This field needs to be programmed to non-zero value at initialization.
 */
#define PDSS_DISCHG_SHV_1_CTRL_TIMER_VALUE_MASK             (0x000ffc00UL) /* <10:19> R:RW:16: */
#define PDSS_DISCHG_SHV_1_CTRL_TIMER_VALUE_POS              (10UL)


/*
 * Time period in LF clock cycles of the time period on DISCHG enable, ON
 * + OFF Time. This field needs to be programmed only when MODE is 0
 */
#define PDSS_DISCHG_SHV_1_CTRL_PWM_PERIOD_MASK              (0x01f00000UL) /* <20:24> R:RW:0: */
#define PDSS_DISCHG_SHV_1_CTRL_PWM_PERIOD_POS               (20UL)


/*
 * Time period in LF clock cycles of the ON time on DISCHG enable, ON + OFF
 * Time. This field needs to be programmed only when MODE is 0
 */
#define PDSS_DISCHG_SHV_1_CTRL_ON_TIME_MASK                 (0x3e000000UL) /* <25:29> R:RW:0: */
#define PDSS_DISCHG_SHV_1_CTRL_ON_TIME_POS                  (25UL)


/*
 * USBPD Hard IP AMUX_NHVN #1-32 Register
 */
#define PDSS_AMUX_NHVN_CTRL_ADDRESS                         (0x400a08ccUL)
#define PDSS_AMUX_NHVN_CTRL                                 (*(volatile uint32_t *)(0x400a08ccUL))
#define PDSS_AMUX_NHVN_CTRL_DEFAULT                         (0x00000000UL)

/*
 * AMUX select control
 */
#define PDSS_AMUX_NHVN_CTRL_SEL_MASK                        (0xffffffffUL) /* <0:31> R:RW:0:USB_AMUX_NHVN_NUM */
#define PDSS_AMUX_NHVN_CTRL_SEL_POS                         (0UL)


/*
 * S8PDS Hard IP PWM Register 0
 */
#define PDSS_PWM_0_CTRL_ADDRESS                             (0x400a08d4UL)
#define PDSS_PWM_0_CTRL                                     (*(volatile uint32_t *)(0x400a08d4UL))
#define PDSS_PWM_0_CTRL_DEFAULT                             (0x0005e000UL)

/*
 * Enable Signal for the whole PWM Block
 */
#define PDSS_PWM_0_CTRL_ENABLE_PWM                          (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_PWM_0_CTRL_PWM_ISO_N                           (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable signal for fixed DAC
 */
#define PDSS_PWM_0_CTRL_ENABLE_PWDM_DAC                     (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Enable signal for feedforward/Vin DAC
 */
#define PDSS_PWM_0_CTRL_ENABLE_PWM_DAC_FF                   (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Enable signal for hclamp comparator
 */
#define PDSS_PWM_0_CTRL_ENABLE_PWM_HCLAMP                   (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Enable signal for lclamp reference generation block
 */
#define PDSS_PWM_0_CTRL_ENABLE_PWM_LCLAMP                   (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Enable signal for skip comparator
 */
#define PDSS_PWM_0_CTRL_ENABLE_PWM_SKIP                     (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Fixed DAC Input current prescalar (0 : 80nA; 1: 160nA)
 */
#define PDSS_PWM_0_CTRL_DRV_IDAC                            (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Frequecny shift from 150KHz to 450Khz (0:150KHz; 1: 450Khz)
 */
#define PDSS_PWM_0_CTRL_OFFSET_EN_IDAC                      (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Enable signal for PWM capacitor trimming (FF_enable, Fixed_enable)
 */
#define PDSS_PWM_0_CTRL_ENABLE_CAP_TRIM_MASK                (0x00000600UL) /* <9:10> R:RW:0: */
#define PDSS_PWM_0_CTRL_ENABLE_CAP_TRIM_POS                 (9UL)


/*
 * operate pwm comparator at half current
 */
#define PDSS_PWM_0_CTRL_ENABLE_PWM_COMP_HALF                (1UL << 11) /* <11:11> R:RW:0: */


/*
 * enable burst exit comparator
 */
#define PDSS_PWM_0_CTRL_ENABLE_PWM_BURST_EXIT               (1UL << 12) /* <12:12> R:RW:0: */


/*
 * pre-scaling of current in ff dac (1: 2.4uA; 0: 1.2uA)
 */
#define PDSS_PWM_0_CTRL_DRV_IDAC_FF                         (1UL << 13) /* <13:13> R:RW:1: */


/*
 * selection bits for burst exit reference(threshold)
 */
#define PDSS_PWM_0_CTRL_PWM_BURST_EXIT_SEL_MASK             (0x0003c000UL) /* <14:17> R:RW:7: */
#define PDSS_PWM_0_CTRL_PWM_BURST_EXIT_SEL_POS              (14UL)


/*
 * test-mode pins for PWM block: <increase EA low level by 100mV,increase
 * EA low level by 100mV,spare,enabling diode in skip_comparator>
 * PAG2S: test-mode pins for PWM block: <increase EA low level by 100mV,increase
 * EA low level by 100mV,enable PWM cap test,enabling diode in skip_comparator>
 */
#define PDSS_PWM_0_CTRL_T_PWM_MASK                          (0x003c0000UL) /* <18:21> R:RW:1: */
#define PDSS_PWM_0_CTRL_T_PWM_POS                           (18UL)


/*
 * ADFT Control for PWM Block
 */
#define PDSS_PWM_0_CTRL_ADFT_PWM_MASK                       (0x1fc00000UL) /* <22:28> R:RW:0: */
#define PDSS_PWM_0_CTRL_ADFT_PWM_POS                        (22UL)


/*
 * S8PDS Hard IP PWM Register 1
 */
#define PDSS_PWM_1_CTRL_ADDRESS                             (0x400a08d8UL)
#define PDSS_PWM_1_CTRL                                     (*(volatile uint32_t *)(0x400a08d8UL))
#define PDSS_PWM_1_CTRL_DEFAULT                             (0x00610294UL)

/*
 * Fixed DAC input
 */
#define PDSS_PWM_1_CTRL_PWM_DAC_MASK                        (0x0000003fUL) /* <0:5> R:RW:20: */
#define PDSS_PWM_1_CTRL_PWM_DAC_POS                         (0UL)


/*
 * Feedforward/Vin DAC input
 */
#define PDSS_PWM_1_CTRL_PWM_DAC_FF_MASK                     (0x00000fc0UL) /* <6:11> R:RW:10: */
#define PDSS_PWM_1_CTRL_PWM_DAC_FF_POS                      (6UL)


/*
 * hclamp reference selection
 */
#define PDSS_PWM_1_CTRL_PWM_HCLAMP_SEL_MASK                 (0x00030000UL) /* <16:17> R:RW:1: */
#define PDSS_PWM_1_CTRL_PWM_HCLAMP_SEL_POS                  (16UL)


/*
 * lclamp reference selection
 */
#define PDSS_PWM_1_CTRL_PWM_LCLAMP_SEL_MASK                 (0x00f00000UL) /* <20:23> R:RW:6: */
#define PDSS_PWM_1_CTRL_PWM_LCLAMP_SEL_POS                  (20UL)


/*
 * S8PDS Hard IP SRSENSE Register 0
 */
#define PDSS_SRSNS_0_CTRL_ADDRESS                           (0x400a08dcUL)
#define PDSS_SRSNS_0_CTRL                                   (*(volatile uint32_t *)(0x400a08dcUL))
#define PDSS_SRSNS_0_CTRL_DEFAULT                           (0xe4000008UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_SRSNS_0_CTRL_SRSNS_ISO_N                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Feed-forward voltage sense block enable
 * This should be enabled only for PWM option and should have Firmware option
 * to keep it disabled for SR-Only option.
 */
#define PDSS_SRSNS_0_CTRL_FEEDFWD_EN                        (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Vbg by R  block enable signal
 */
#define PDSS_SRSNS_0_CTRL_VBGBYR_EN                         (1UL << 3) /* <3:3> R:RW:1: */


/*
 * ADFT master enable  for srsense block
 */
#define PDSS_SRSNS_0_CTRL_ADFT_EN_SRSENSE                   (1UL << 15) /* <15:15> R:RW:0: */


/*
 * ADFT control for drain sensing block
 */
#define PDSS_SRSNS_0_CTRL_ADFT_CTRL_DRAIN_MASK              (0x03ff0000UL) /* <16:25> R:RW:0: */
#define PDSS_SRSNS_0_CTRL_ADFT_CTRL_DRAIN_POS               (16UL)


/*
 * ZCDF comparator powerdown signal
 */
#define PDSS_SRSNS_0_CTRL_ZCDF_PD                           (1UL << 26) /* <26:26> R:RW:1: */


/*
 * nsn power down Signal
 */
#define PDSS_SRSNS_0_CTRL_NSN_PD                            (1UL << 29) /* <29:29> R:RW:1: */


/*
 * Zcd Power Down Signal
 */
#define PDSS_SRSNS_0_CTRL_ZCD_PD                            (1UL << 30) /* <30:30> R:RW:1: */


/*
 * Peak detector power down signal
 * This bit is enabled only for PWM mode.
 * Firmware option to keep it disabled for SR-Only option.
 */
#define PDSS_SRSNS_0_CTRL_PEAKDET_PD                        (1UL << 31) /* <31:31> R:RW:1: */


/*
 * S8PDS Hard IP GDRV Register 0
 */
#define PDSS_GDRV_0_CTRL_ADDRESS                            (0x400a08ecUL)
#define PDSS_GDRV_0_CTRL                                    (*(volatile uint32_t *)(0x400a08ecUL))
#define PDSS_GDRV_0_CTRL_DEFAULT                            (0x000ffb82UL)

/*
 * This bit is used to enable the Gate driver operation.
 */
#define PDSS_GDRV_0_CTRL_GDRV_EN                            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * charge pump enable signal
 */
#define PDSS_GDRV_0_CTRL_CP_EN                              (1UL << 1) /* <1:1> R:RW:1: */


/*
 * Enable signal for doubler, 1: doubler will be bypassed to vddd. Firmware
 * should make it 0 if doubler needs to be used. [FW]
 */
#define PDSS_GDRV_0_CTRL_DOUBLER_BYPASS                     (1UL << 7) /* <7:7> R:RW:1: */


/*
 * Skew options for nfet of gate driver;
 * For PAG2S : Change it to 0xf [FW]
 */
#define PDSS_GDRV_0_CTRL_GDRV_NCONF_MASK                    (0x00000f00UL) /* <8:11> R:RW:11: */
#define PDSS_GDRV_0_CTRL_GDRV_NCONF_POS                     (8UL)


/*
 * skew options for nfet of doubler
 */
#define PDSS_GDRV_0_CTRL_GDRV_NCONF_BOT_MASK                (0x0000f000UL) /* <12:15> R:RW:15: */
#define PDSS_GDRV_0_CTRL_GDRV_NCONF_BOT_POS                 (12UL)


/*
 * skew options for boot-strap pfet of doubler
 */
#define PDSS_GDRV_0_CTRL_GDRV_PCONF_BOT_MASK                (0x000f0000UL) /* <16:19> R:RW:15: */
#define PDSS_GDRV_0_CTRL_GDRV_PCONF_BOT_POS                 (16UL)


/*
 * S8PDS Hard IP GDRV Register 1
 */
#define PDSS_GDRV_1_CTRL_ADDRESS                            (0x400a08f0UL)
#define PDSS_GDRV_1_CTRL                                    (*(volatile uint32_t *)(0x400a08f0UL))
#define PDSS_GDRV_1_CTRL_DEFAULT                            (0x00000124UL)

/*
 * Testmodes for Gate-driver (PAG2S): 0x00016D [FW]
 * <21:20>  : Slew option for pre-drivers --> Default 00
 * <19>       : Power up nreset pullup to vddd --> Default 0
 * <18>       : ext_clk_sel for charge pump --> Default 0
 * <17>       : make all pads tristate --> Default 0
 * <16>       : to disable the pull down path of pwrup_nreset  --> Default
 * 0
 * <15>       : to bypass the vddd comparator which will turn on doubler.-->
 * Default 0
 * <14>       : MSB of config that controls the delay of bypass signal of
 * vddd comparator.--> Default 0
 * <13:12>  : LSB 2 bits of config that controls the delay of bypass signal
 * of vddd comparator.--> Default 00
 * <11>       : bypass option for delay control between pad_sr_cpn pull down
 * and pad_sr_gdrv_pull down.
 *                 (higher delay will reduce current consumption but increases
 * fall delay). when set to 0 no delay.--> Default 0
 * <10:9>    : option to change the delay in delay control block which is
 * used to control the delay between between pad_sr_cpn pull down and pad_sr_gdrv_pull
 * down. --> Default 00
 * <8>         : bypass option for slew control of pad_sr_cpn pull up.  -->
 * Default 1
 *                 1 : slew will be present
 *                 0 : no slew will be present.
 * <7:6>      : option to control the delay for pad_sr_cpn pull up slew-->
 * Default 01
 * <5>         : bypass option for slew control of pad_sr_cpn pull down.-->
 * Default 1
 *                 1 : slew will be present
 *                 0 : no slew will be present.
 * <4:3>      : option to control the delay for pad_sr_cpn pull down slew.
 * --> Default 01
 * <2>         : bypass option for slew control of pad_sr_gdrv pull down.
 * --> Default 1
 *                 1 : slew will be present
 *                 0 : no slew will be present.
 * <1:0>      : option to control the delay for pad_sr_gdrv pull down slew.
 *  --> Default 01
 *
 *
 * Testmodes for Gate-driver(PAG1S):
 * <21:19>  : spare
 * <18>       : ext_lk_sel for charge pump
 * <17>       : make all pads tristate
 * <16>       : disable pwrup_nreset
 * <15>       : bypass vdd comparator to delay based
 * <14>       : minimal or zero delay of bypassed vdd comparator
 * <13:12>  : control the delay of bypassed vdd comparator
 * <11>       : bypass the delay between ngdrv_bot en to pd_en
 *                  1 : delay  between ngdrv_bot_en to pd_en reduces the
 * average current consumption
 *                  0 : delay will be bypassed and pull down will be faster
 * <10:9>    : controls the delay between ngdrv_bot en to pd_en
 * <8>         : bypass the slewing option for pgdrv_bot en
 *                 1 : slew will be present between pgdrv_bot_en legs
 *                 0 : no slew will be present.
 * <7:6>      : controls the  slew delay for pgdrv_bot en
 * <5>         : bypass the slewing option for ngdrv_bot en
 *                 1 : slew will be present between ngdrv_bot_en legs
 *                 0 : no slew will be present.
 * <4:3>      : controls the  slew delay for ngdrv_bot en
 * <2>         : bypass the slewing option for pd
 *                 1 : slew will be present between nfet pd legs
 *                 0 : no slew will be present.
 * <1:0>      : controls the  slew delay for nfet pd legs
 */
#define PDSS_GDRV_1_CTRL_T_SRGDRV_MASK                      (0x003fffffUL) /* <0:21> R:RW:292: */
#define PDSS_GDRV_1_CTRL_T_SRGDRV_POS                       (0UL)


/*
 * adft control signal for gate-driver block
 */
#define PDSS_GDRV_1_CTRL_ADFT_CTRL_SRGDRV_MASK              (0x03c00000UL) /* <22:25> R:RW:0: */
#define PDSS_GDRV_1_CTRL_ADFT_CTRL_SRGDRV_POS               (22UL)


/*
 * PTDRV_IN pulldown enable for start/stop sequence  (0:disable, 1: enable)
 */
#define PDSS_GDRV_1_CTRL_PTDRV_PULLDN_EN                    (1UL << 26) /* <26:26> R:RW:0: */


/*
 * PTDRV_IN pullup enable for start/stop sequence (0:disable, 1: enable)
 */
#define PDSS_GDRV_1_CTRL_PTDRV_PULLUP_EN                    (1UL << 27) /* <27:27> R:RW:0: */


/*
 * Master adft enable signal for gate-driver block
 */
#define PDSS_GDRV_1_CTRL_ADFT_EN_SRGDRV                     (1UL << 31) /* <31:31> R:RW:0: */


/*
 * S8PDS Hard IP Error Amplifier Register 0
 */
#define PDSS_EA_CTRL_ADDRESS                                (0x400a08f4UL)
#define PDSS_EA_CTRL                                        (*(volatile uint32_t *)(0x400a08f4UL))
#define PDSS_EA_CTRL_DEFAULT                                (0x00400004UL)

/*
 * Enable signal for constant current path
 * 0 - Disable
 * 1 - Enable
 */
#define PDSS_EA_CTRL_EN_CC                                  (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Enable signal for IDAC
 * 0 - Disable
 * 1 - Enable
 */
#define PDSS_EA_CTRL_EN_CV                                  (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable signal for CV AMP
 * 0 - Disable
 * 1 - Enable
 */
#define PDSS_EA_CTRL_EN_SHNT                                (1UL << 2) /* <2:2> R:RW:1: */


/*
 * Enable signal for current sink DAC
 * 0 - Disable
 * 1 - Enable
 */
#define PDSS_EA_CTRL_ISNK_EN                                (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Enable signal for current source DAC
 * 0 - Disable
 * 1 - Enable
 */
#define PDSS_EA_CTRL_ISRC_EN                                (1UL << 4) /* <4:4> R:RW:0: */


/*
 * 10-bit DAC control for current sink
 */
#define PDSS_EA_CTRL_ISNK_DAC_CTRL_MASK                     (0x00007fe0UL) /* <5:14> R:RW:0: */
#define PDSS_EA_CTRL_ISNK_DAC_CTRL_POS                      (5UL)


/*
 * 7-bit DAC control for current source
 */
#define PDSS_EA_CTRL_ISRC_DAC_CTRL_MASK                     (0x003f8000UL) /* <15:21> R:RW:0: */
#define PDSS_EA_CTRL_ISRC_DAC_CTRL_POS                      (15UL)


/*
 * Reference current selection for Constant voltage DAC
 * 00 - Deep sleep Refgen current
 * 01 - Internal Vgb/R current
 * 10 - BG current
 * 11 - Not used
 */
#define PDSS_EA_CTRL_EA_IREF_SEL_MASK                       (0x00c00000UL) /* <22:23> R:RW:1: */
#define PDSS_EA_CTRL_EA_IREF_SEL_POS                        (22UL)


/*
 * VBUS Internal resistor divider bypass enable
 * 0 - Resistor divider is included
 * 1 - Resistor divider is bypassed
 */
#define PDSS_EA_CTRL_RES_DIV_BYPASS                         (1UL << 27) /* <27:27> R:RW:0: */


/*
 * Enable signal for CV AMP to work in low VDDD range
 * 1 - Disable
 * 0 - Enable
 */
#define PDSS_EA_CTRL_SHNT_ST_OPAMP_ENB                      (1UL << 28) /* <28:28> R:RW:0: */


/*
 * 11th-bit DAC control for current sink in EPR mode
 */
#define PDSS_EA_CTRL_ISNK_DAC_CTRL_EPR                      (1UL << 29) /* <29:29> R:RW:0:PASC2_EN */


/*
 * Powers down the block, active high
 */
#define PDSS_EA_CTRL_EA_PD                                  (1UL << 31) /* <31:31> R:RW:0: */


/*
 * S8PDS Hard IP Error Amplifier Register 1
 */
#define PDSS_PDS_EA_1_CTRL_ADDRESS                          (0x400a08f8UL)
#define PDSS_PDS_EA_1_CTRL                                  (*(volatile uint32_t *)(0x400a08f8UL))
#define PDSS_PDS_EA_1_CTRL_DEFAULT                          (0x00002460UL)

/*
 * Select signal for shunt regulator to work in srss or dpslp current
 * 0 - CV AMP work with srss current
 * 1 - CV AMP work with dpslp current
 */
#define PDSS_PDS_EA_1_CTRL_EN_SHNT_DPSLP                    (1UL << 0) /* <0:0> R:RW:0: */


/*
 * This pin is used to enable cc_comp_out_hv output which is same as ea_out_pwm
 * pin.
 */
#define PDSS_PDS_EA_1_CTRL_EN_CC_COMP                       (1UL << 1) /* <1:1> R:RW:0: */


/*
 * To enable CC Flag circuit
 */
#define PDSS_PDS_EA_1_CTRL_EN_CC_CV_FLAG                    (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Enable signal for PWM mode
 * 1 - Error Amplifier supports PWM mode
 * 0 - Error Amplifier supports OPTO mode
 */
#define PDSS_PDS_EA_1_CTRL_EN_PWM_MODE                      (1UL << 3) /* <3:3> R:RW:0: */


/*
 * This pin is used to tristate pad_esd_cc_bufout (look at T_EA<2> as well)
 * en_cc=0, en_tristate=x - buffer is disabled and output is pulled to 0V
 * en_cc=1, en_tristate=0 - buffer is enabled
 * en_cc=1, en_tristate=1 -  buffer is disabled and output is pulled to hiZ
 */
#define PDSS_PDS_EA_1_CTRL_EN_CCBUFOUT_TRISTATE             (1UL << 4) /* <4:4> R:RW:0: */


/*
 * To select ccdet in cc_flag output:
 * 0: cc_flag output will not include cc_det
 * 1: cc_flag output will include cc_det
 */
#define PDSS_PDS_EA_1_CTRL_SEL_CCDET                        (1UL << 5) /* <5:5> R:RW:1: */


/*
 * To select cvdet in cc_flag output:
 * 0: cc_flag output will not include cv_det_n
 * 1: cc_flag output will include cv_det_n
 */
#define PDSS_PDS_EA_1_CTRL_SEL_CVDET                        (1UL << 6) /* <6:6> R:RW:1: */


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_PDS_EA_1_CTRL_EA_ISO_N                         (1UL << 7) /* <7:7> R:RW:0: */


/*
 * trims to vary CC error amp input bias current.
 */
#define PDSS_PDS_EA_1_CTRL_TR_CC_ERR_AMP_IBIAS_MASK         (0x00000700UL) /* <8:10> R:RW:4: */
#define PDSS_PDS_EA_1_CTRL_TR_CC_ERR_AMP_IBIAS_POS          (8UL)


/*
 * trims to vary CV error amp input bias current.
 */
#define PDSS_PDS_EA_1_CTRL_TR_CV_ERR_AMP_IBIAS_MASK         (0x00003800UL) /* <11:13> R:RW:4: */
#define PDSS_PDS_EA_1_CTRL_TR_CV_ERR_AMP_IBIAS_POS          (11UL)


/*
 * test mode options:
 * t_ea<14:7>: not used.
 *
 * t_ea<6>: [FW] (PAG2S)
 *  0 -> Disable clamp on cv/cc_shnt_gate
 *  1-> Enable clamp on cv/cc_shnt_gate (to be used only in PWM part)
 *
 * t_ea<5>: [FW](PAG2S)
 *  0 -> SRSS_IREF used for CC/CV amp
 *  1-> dpslp_IREF used for CC/CV amp
 *
 * t_ea<4>: (PAG2S)
 *  0 -> ea_out_pwm_bypass pull-down disabled
 *  1-> ea_out_pwm_bypass pull-down enabled
 *
 * t_ea<3>: 0 -> pad_cc_compn is isolated from EA.
 *   1 -> enables path from the inp terminal of CC AMP to pad_cc_compn.
 *
 * t_ea<2>: 0 -> pad_esd_cc_bufout is isolated from EA.
 *    1 -> enables path from the output of csainp_ugbuf to pad_esd_cc_bufout.
 *
 * t_ea<1>: 0 -> resistance between output of csainp_ugbuf and adft_out1(amuxbus_a)
 * is 3Kohm.
 *                   0 -> resistance between output of csainp_ugbuf and pad_esd_cc_bufout
 * is 3Kohm.
 *   1 ->  Test mode to increase resistance between output of csainp_ugbuf
 * and adft_out1(amuxbus_a) to 6K from 3K.
 *                  1 -> Test mode to increase resistance between output
 * of csainp_ugbuf and pad_esd_cc_bufout to 6K from 3K.
 *
 * t_ea<0>: To enable 1pF cap parallel to 200K of vbus resistor divider.
 */
#define PDSS_PDS_EA_1_CTRL_T_EA_MASK                        (0x7fff0000UL) /* <16:30> R:RW:0: */
#define PDSS_PDS_EA_1_CTRL_T_EA_POS                         (16UL)


/*
 * S8PDS Hard IP Error Amplifier Register 2
 */
#define PDSS_PDS_EA_2_CTRL_ADDRESS                          (0x400a08fcUL)
#define PDSS_PDS_EA_2_CTRL                                  (*(volatile uint32_t *)(0x400a08fcUL))
#define PDSS_PDS_EA_2_CTRL_DEFAULT                          (0x00422402UL)

/*
 * trims to vary CC_DET current
 */
#define PDSS_PDS_EA_2_CTRL_TR_CC_CV_FLAG_CCDET_MASK         (0x0000001fUL) /* <0:4> R:RW:2: */
#define PDSS_PDS_EA_2_CTRL_TR_CC_CV_FLAG_CCDET_POS          (0UL)


/*
 * trims to vary Bandwidth of CC input filter
 * PAG2S : [FW] Change to 0xC ; To be matched with TR_VREF_CC_RCFILTER_BW
 */
#define PDSS_PDS_EA_2_CTRL_TR_CCIN_RCFILTER_BW_MASK         (0x00000f00UL) /* <8:11> R:RW:4: */
#define PDSS_PDS_EA_2_CTRL_TR_CCIN_RCFILTER_BW_POS          (8UL)


/*
 * trims to vary pwm load current.
 * 000 - 0uA,     001 - 50uA,   010 - 75uA,    011 - 125uA,
 * 100 - 150uA, 101 - 200uA, 110 - 225uA, 111 - 275uA.
 */
#define PDSS_PDS_EA_2_CTRL_TR_ERR_AMP_PWM_ILOAD_MASK        (0x00007000UL) /* <12:14> R:RW:2: */
#define PDSS_PDS_EA_2_CTRL_TR_ERR_AMP_PWM_ILOAD_POS         (12UL)


/*
 * trims to vary CV_DET current
 */
#define PDSS_PDS_EA_2_CTRL_TR_CC_CV_FLAG_CVDET_MASK         (0x001f0000UL) /* <16:20> R:RW:2: */
#define PDSS_PDS_EA_2_CTRL_TR_CC_CV_FLAG_CVDET_POS          (16UL)


/*
 * trims to vary CC Buffer final stage source current
 */
#define PDSS_PDS_EA_2_CTRL_TR_CC_CSAINP_UGBUF_ILOAD_MASK    (0x00600000UL) /* <21:22> R:RW:2: */
#define PDSS_PDS_EA_2_CTRL_TR_CC_CSAINP_UGBUF_ILOAD_POS     (21UL)


/*
 * Control bits for the analog test mux
 * 0000-Normal operation adft_out's are hiZ
 */
#define PDSS_PDS_EA_2_CTRL_PDS_EA_ADFT_MASK                 (0x07800000UL) /* <23:26> R:RW:0: */
#define PDSS_PDS_EA_2_CTRL_PDS_EA_ADFT_POS                  (23UL)


/*
 * S8PDSV2 Hard IP SRGDRV Register 2
 */
#define PDSS_GDRV_2_CTRL_ADDRESS                            (0x400a0908UL)
#define PDSS_GDRV_2_CTRL                                    (*(volatile uint32_t *)(0x400a0908UL))
#define PDSS_GDRV_2_CTRL_DEFAULT                            (0x23bc782bUL)

/*
 * t_srgdrv_reserved<1>: zvs_bypass_mode
 * t_srgdrv_reserved<0>: bypass option for slew control of vddd pull up
 */
#define PDSS_GDRV_2_CTRL_T_SRGDRV_RESERVED_MASK             (0x00000003UL) /* <0:1> R:RW:3: */
#define PDSS_GDRV_2_CTRL_T_SRGDRV_RESERVED_POS              (0UL)


/*
 * enable bit for ptdrv_in_lv
 */
#define PDSS_GDRV_2_CTRL_PTDRV_IN_EN                        (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Configuration options to change the internal oscillator frequency
 */
#define PDSS_GDRV_2_CTRL_GDRV_OSC_FREQ_CONF_MASK            (0x00000018UL) /* <3:4> R:RW:1: */
#define PDSS_GDRV_2_CTRL_GDRV_OSC_FREQ_CONF_POS             (3UL)


/*
 * Resistive divider for Pump to change pump voltage
 */
#define PDSS_GDRV_2_CTRL_GDRV_VCP_RDIV_CONF_MASK            (0x00000060UL) /* <5:6> R:RW:1: */
#define PDSS_GDRV_2_CTRL_GDRV_VCP_RDIV_CONF_POS             (5UL)


/*
 * <3>:unused; <2> : MSB Configuration options to change the internal oscillator
 * frequency; <1:0> :unused
 */
#define PDSS_GDRV_2_CTRL_GDRV_CONF_RESERVED_MASK            (0x00000780UL) /* <7:10> R:RW:0: */
#define PDSS_GDRV_2_CTRL_GDRV_CONF_RESERVED_POS             (7UL)


/*
 * Configuration options to change the drive strength of pad_sr_gdrv vddd
 * pull up
 */
#define PDSS_GDRV_2_CTRL_GDRV_PCONF_MASK                    (0x00007800UL) /* <11:14> R:RW:15: */
#define PDSS_GDRV_2_CTRL_GDRV_PCONF_POS                     (11UL)


/*
 * Gpio pull down input
 */
#define PDSS_GDRV_2_CTRL_GDRV_GPIO_PULLDN                   (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Gpio pull down enable
 */
#define PDSS_GDRV_2_CTRL_GDRV_GPIO_PULLDN_EN                (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Path select RTl/HardIP
 * 0: RTL path SET/RESET- gdrv_in & gdrv_in_zvs
 * 1: HardIP Path SET/RETSET- nsn_lv, zcd_lv, zcdf_lv, ptdrv_in_lv & gpio_pulldn
 */
#define PDSS_GDRV_2_CTRL_GDRV_PATH_SEL                      (1UL << 17) /* <17:17> R:RW:0: */


/*
 * Configuration control option to enable dual gate driver mode ; 0 - dual
 * drive mode disabled; 1-dual drive mode enabled
 */
#define PDSS_GDRV_2_CTRL_DUAL_MODE_CTRL                     (1UL << 18) /* <18:18> R:RW:1: */


/*
 * skew options for boot-strap pfet of doubler during gdrv_in_zvs assertion
 */
#define PDSS_GDRV_2_CTRL_GDRV_PCONF_BOT_ZVS_MASK            (0x00780000UL) /* <19:22> R:RW:7: */
#define PDSS_GDRV_2_CTRL_GDRV_PCONF_BOT_ZVS_POS             (19UL)


/*
 * skew options for boot-strap pfet during gdrv_in_zvs assertion
 */
#define PDSS_GDRV_2_CTRL_GDRV_PCONF_ZVS_MASK                (0x07800000UL) /* <23:26> R:RW:7: */
#define PDSS_GDRV_2_CTRL_GDRV_PCONF_ZVS_POS                 (23UL)


/*
 * Delay for which skew option will remain while switching from gdrv to gdrv_in_zvs
 * skew for pos-edge of srgdrv
 */
#define PDSS_GDRV_2_CTRL_GDRV_MUX_DLY_MASK                  (0x78000000UL) /* <27:30> R:RW:4: */
#define PDSS_GDRV_2_CTRL_GDRV_MUX_DLY_POS                   (27UL)


/*
 * Output isolation control.  Active Low
 * 0: srgdrv_ddft_out and gdrv_sense_out_lv is low
 */
#define PDSS_GDRV_2_CTRL_GDRV_ISO_N                         (1UL << 31) /* <31:31> R:RW:0: */


/*
 * USBPD Hard IP VCONN20 V5V Power FET Register
 */
#define PDSS_VCONN40_CTRL_ADDRESS                           (0x400a090cUL)
#define PDSS_VCONN40_CTRL                                   (*(volatile uint32_t *)(0x400a090cUL))
#define PDSS_VCONN40_CTRL_DEFAULT                           (0x80005000UL)

/*
 *  Change the SCP detection threshold to 60m(typ)
 * 0 : SCP detection threshold is 75mA (typ)
 * 1 : SCP detection threshold is 60mA (typ)
 */
#define PDSS_VCONN40_CTRL_EN_SCP_60M                        (1UL << 0) /* <0:0> R:RW:0: */


/*
 *  Enable SCP fault detection on CC1
 * 0 : Disable the SCP detection
 * 1 : Enable the SCP detection
 */
#define PDSS_VCONN40_CTRL_EN_SCP_CC1                        (1UL << 1) /* <1:1> R:RW:0: */


/*
 *  Enable SCP fault detection on CC2
 * 0 : Disable the SCP detection
 * 1 : Enable the SCP detection
 */
#define PDSS_VCONN40_CTRL_EN_SCP_CC2                        (1UL << 2) /* <2:2> R:RW:0: */


/*
 *  Enable the SCP fault based shut down of CC1/CC2 switches
 * 0 : SCP based shut down is Disabled
 * 1 : SCP based shut down is Enabled
 */
#define PDSS_VCONN40_CTRL_EN_SCP_PD_SW                      (1UL << 3) /* <3:3> R:RW:0: */


/*
 *  Enable OVP fault detection on CC1/CC2
 * 0 :  Disable OVP detection
 * 1 : Enable OVP detection
 */
#define PDSS_VCONN40_CTRL_EN_OVP                            (1UL << 4) /* <4:4> R:RW:0: */


/*
 *  Reduce the OVP_6V threshold to ~5.2V for testability
 * 0 : Default OVP_6V threshold
 * 1 : OVP_6V threshold is reduced to ~5.2V
 */
#define PDSS_VCONN40_CTRL_EN_OVP6V_TEST                     (1UL << 5) /* <5:5> R:RW:0: */


/*
 *  Use external clock for charge pump, instead of internal oscillator
 * 0 : Use internal oscillator
 * 1 : Use external clock
 */
#define PDSS_VCONN40_CTRL_EXT_CLK_SEL                       (1UL << 6) /* <6:6> R:RW:0: */


/*
 *  Increase the OVP_6V tri point
 * 0 : Default trip point ~6V
 * 1 : Increased trip point ~6.3V
 */
#define PDSS_VCONN40_CTRL_INC_OVP6V_COMP                    (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Disable OVP_6V comparator
 * 0 : OVP_6V comp is enabled
 * 1 : OVP_6V comp is disabled
 */
#define PDSS_VCONN40_CTRL_DIS_OVP6V_COMP                    (1UL << 8) /* <8:8> R:RW:0: */


/*
 * DIS_OVP_AUTOSHUTDN<0> - Disable auto shut down of vconn when ovp is detected
 * 0 : OVP based auto shutdown is Enabled
 * 1 : OVP based auto shutdown is Disabled
 *
 * DIS_OVP_AUTOSHUTDN<1> - Disable auto shut down of vconn when ovp_6v is
 * detected
 * 0 : OVP_6V based auto shutdown is Enabled
 * 1 : OVP_6V based auto shutdown is Disabled
 */
#define PDSS_VCONN40_CTRL_DIS_OVP_AUTOSHUTDN_MASK           (0x00000600UL) /* <9:10> R:RW:0: */
#define PDSS_VCONN40_CTRL_DIS_OVP_AUTOSHUTDN_POS            (9UL)


/*
 *  Enable the gate charging of 42V native switch for CC1/CC2 [FW]
 * 0 : 42V native switch is off; gate is pulled down
 * 1 : 42V native switch gate is charged through inrush control circuit
 */
#define PDSS_VCONN40_CTRL_EN_INRUSH_CTRL                    (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Control the charging current of 42V native switch for inrush control
 * (LSB is inverted)
 * 0000 : 25nA
 * 0001 : 0nA (INVALID; SHOULD NOT BE USED)
 * 0010 : 75nA -- inrush = 120mA
 * 0100 : 125nA -- inrush = 150mA
 * 0101 : 100nA (Default)
 * 1000 : 225nA -- inrush = 200mA
 * 1110 : 375nA (Max)
 * 1111 : 350nA --inrush = 225mA
 */
#define PDSS_VCONN40_CTRL_INRUSH_CTRL_MASK                  (0x0000f000UL) /* <12:15> R:RW:5: */
#define PDSS_VCONN40_CTRL_INRUSH_CTRL_POS                   (12UL)


/*
 *  Enable HV to LV level shifters
 * 0 : Disable the LS
 * 1 : Enable the LS
 */
#define PDSS_VCONN40_CTRL_VCONN40_ISO_N                     (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Increase the charging current for gate of 42VNative to 5x after SW turn-on
 * [FW]
 */
#define PDSS_VCONN40_CTRL_EN_5X_G2_CHRG                     (1UL << 17) /* <17:17> R:RW:0: */


/*
 * The master enbale of adft
 * 0-disable adft
 * 1-enable adft configuration
 */
#define PDSS_VCONN40_CTRL_VCONN40_ADFT_EN                   (1UL << 24) /* <24:24> R:RW:0: */


/*
 *  ADFT control signals
 * 0000 : adft[1] - HiZ  ; adft[0] = HiZ
 * 0001 : adft[1] - Vpump10v  ; adft[0] = isink_pump
 * 0010 : adft[1] - IREF_OCP  ; adft[0] = SCP_VCC_COMB
 * 0011 : adft[1] - SCP_VTRIP  ; adft[0] = ISINK_SCP
 * 0100 : adft[1] - CC1  ; adft[0] = VDDD_SW
 * 0101 : adft[1] - CC2  ; adft[0] = VDDD_SW
 * 0110 : adft[1] - VGATE_CC1  ; adft[0] = HiZ
 * 0111 : adft[1] - VGATE_CC2  ; adft[0] = HiZ
 */
#define PDSS_VCONN40_CTRL_VCONN40_ADFT_CTRL_MASK            (0x78000000UL) /* <27:30> R:RW:0: */
#define PDSS_VCONN40_CTRL_VCONN40_ADFT_CTRL_POS             (27UL)


/*
 *  Enable bias currents
 * 0 : Disable bias currents
 * 1 : Enable bias currents
 */
#define PDSS_VCONN40_CTRL_EN_IBIAS                          (1UL << 31) /* <31:31> R:RW:1: */


/*
 * S8PDSV2 Hard IP NGDO30 Register (Only for PAG2S )
 */
#define PDSS_NGDO30_1_CTRL_ADDRESS                          (0x400a0920UL)
#define PDSS_NGDO30_1_CTRL                                  (*(volatile uint32_t *)(0x400a0920UL))
#define PDSS_NGDO30_1_CTRL_DEFAULT                          (0x44409080UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_NGDO30_1_CTRL_NGDO30_ISO_N                     (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Enable signal for NGDO
 * ngdo_en = 0 ; disabled
 * ngdo_en = 1 ; enabled
 */
#define PDSS_NGDO30_1_CTRL_NGDO30_EN_LV                     (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Charge-pump ouptut control;
 * cp_en = 0 ; cp output = vbus
 * cp_en = 1 ; cp output = driven by cp action
 */
#define PDSS_NGDO30_1_CTRL_NGDO30_CP_EN                     (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Enable signal for adft.
 * adft_en = 0 ; ADFT disabled, normal functionality
 * adft_en = 1 ; ADFT network enabled
 */
#define PDSS_NGDO30_1_CTRL_NGDO30_ADFT_EN                   (1UL << 3) /* <3:3> R:RW:0: */


/*
 * NGDO Keepoff disable
 * 0 : Keepoff enabled
 * 1: Keepoff disabled
 */
#define PDSS_NGDO30_1_CTRL_NGDO30_KEEP_OFF_DISABLE          (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Disable signal for vbus_c comparator
 * vbusc_comp_disable = 1, resistor based gate pull-down disabled
 * vbusc_comp_disable = 0, resistor based gate pull-down enabled
 */
#define PDSS_NGDO30_1_CTRL_VBUSC_COMP_DISABLE               (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Enable signal for vbus_c comparator
 * 1: Hysteresis is enabled
 * 0: Hysteresis is disabled
 */
#define PDSS_NGDO30_1_CTRL_VBUSC_COMP_HYS_EN                (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Enable signal for 0.3uA offset current in slew ctrl
 * en_0p3u_slewctrl_current = 1, 0.3uA offset slew control current enabled
 * en_0p3u_slewctrl_current = 0, 0.3uA offset slew control current disabled
 */
#define PDSS_NGDO30_1_CTRL_SLEWCTRL_0P3U_CURR_EN            (1UL << 7) /* <7:7> R:RW:1: */


/*
 * Enable signal to bring oscillator clock on DDFT output
 * clk_dft_en = 1, clk on ddft output
 * clk_dft_en = 0, 0 on ddft output
 */
#define PDSS_NGDO30_1_CTRL_CLK_DFT_EN                       (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Enable signal to bring comparator output on DDFT
 * comp_dft_en = 1, comp on ddft output
 * comp_dft_en = 0, 0 on ddft output
 */
#define PDSS_NGDO30_1_CTRL_COMP_DFT_EN                      (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Enable signal for resistive pull down on pad_vbus_ctrl
 * res_pd_en = 0, resistive pull-down disable
 * res_pd_en = 1, resistive pull-down enable
 */
#define PDSS_NGDO30_1_CTRL_RES_PD_EN                        (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Enable signal to scale slew_ctrl current by 2x
 * en_2x_slewctrl_current = 1, slew_ctrl current 2x
 * en_2x_slewctrl_current = 0, slew_ctrl current 1x
 */
#define PDSS_NGDO30_1_CTRL_SLEWCTRL_2X_CURR_EN              (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Enable signal for VGS clamp
 * clamp_en = 0; VGS clamp disabled
 * clamp_en = 1: VGS clamp enabled
 */
#define PDSS_NGDO30_1_CTRL_CLAMP_EN                         (1UL << 12) /* <12:12> R:RW:1: */


/*
 * To config the ngdo output charging current (with 0.3uA offset current
 * enabled)
 * = 2 for 1nF Cgs for 125C max
 * = 9 for 1nF Cgs for 150C max
 * = 13 for 3nF Cgs for 150C max
 * measured for Vbus_in=5V and pad_vbus_ctrl from 1V to Vbus_in+1V
 */
#define PDSS_NGDO30_1_CTRL_NGDO30_SLEW_CTRL_MASK            (0x000fc000UL) /* <14:19> R:RW:2: */
#define PDSS_NGDO30_1_CTRL_NGDO30_SLEW_CTRL_POS             (14UL)


/*
 * To config sink current which creates Vgs for equalization PFET
 */
#define PDSS_NGDO30_1_CTRL_GATE_PD_BIAS_CTRL_MASK           (0x00f00000UL) /* <20:23> R:RW:4: */
#define PDSS_NGDO30_1_CTRL_GATE_PD_BIAS_CTRL_POS            (20UL)


/*
 * To config pull-down resistor for comaparator based turn OFF
 */
#define PDSS_NGDO30_1_CTRL_GATE_PD_RES_CTRL_MASK            (0x07000000UL) /* <24:26> R:RW:4: */
#define PDSS_NGDO30_1_CTRL_GATE_PD_RES_CTRL_POS             (24UL)


/*
 * Programmibility for gate sink idac
 */
#define PDSS_NGDO30_1_CTRL_GATE_SINK_CTRL_MASK              (0x38000000UL) /* <27:29> R:RW:0: */
#define PDSS_NGDO30_1_CTRL_GATE_SINK_CTRL_POS               (27UL)


/*
 * Programmibility for vbus_c comparator trip point in gate pd
 */
#define PDSS_NGDO30_1_CTRL_VBUSC_COMP_BIAS_CTRL_MASK        (0xc0000000UL) /* <30:31> R:RW:1: */
#define PDSS_NGDO30_1_CTRL_VBUSC_COMP_BIAS_CTRL_POS         (30UL)


/*
 * S8PDSV2 Hard IP NGDO30 Register (Only for PAG2S )
 */
#define PDSS_NGDO30_2_CTRL_ADDRESS                          (0x400a0924UL)
#define PDSS_NGDO30_2_CTRL                                  (*(volatile uint32_t *)(0x400a0924UL))
#define PDSS_NGDO30_2_CTRL_DEFAULT                          (0x0000010cUL)

/*
 * To program the oscillator frequency
 */
#define PDSS_NGDO30_2_CTRL_TRIM_OSC_MASK                    (0x00000007UL) /* <0:2> R:RW:4: */
#define PDSS_NGDO30_2_CTRL_TRIM_OSC_POS                     (0UL)


/*
 * To program the regulated voltage
 */
#define PDSS_NGDO30_2_CTRL_TRIM_REG_MASK                    (0x00000018UL) /* <3:4> R:RW:1: */
#define PDSS_NGDO30_2_CTRL_TRIM_REG_POS                     (3UL)


/*
 * ADFT selection pins.
 */
#define PDSS_NGDO30_2_CTRL_NGDO30_DFT_MASK                  (0x000000e0UL) /* <5:7> R:RW:0: */
#define PDSS_NGDO30_2_CTRL_NGDO30_DFT_POS                   (5UL)


/*
 * Programmibility for external nfet vgs clamp
 */
#define PDSS_NGDO30_2_CTRL_CLAMP_CTRL_MASK                  (0x00000300UL) /* <8:9> R:RW:1: */
#define PDSS_NGDO30_2_CTRL_CLAMP_CTRL_POS                   (8UL)


/*
 * tm_ngdo<4:2> : unused
 * tm_ngdo<1>: connects external clock (clk_lv) to the charge pump input
 * tm_ngdo<0>: enables 9.6uA current sink on vbus_ctrl when gdrv_en is LOW
 */
#define PDSS_NGDO30_2_CTRL_TM_NGDO_MASK                     (0x00007c00UL) /* <10:14> R:RW:0: */
#define PDSS_NGDO30_2_CTRL_TM_NGDO_POS                      (10UL)


/*
 * S8PDSV2 Hard IP SRSENSE Register 4
 */
#define PDSS_SRSNS_4_CTRL_ADDRESS                           (0x400a0928UL)
#define PDSS_SRSNS_4_CTRL                                   (*(volatile uint32_t *)(0x400a0928UL))
#define PDSS_SRSNS_4_CTRL_DEFAULT                           (0xc0000064UL)

/*
 * 1 : disabling the opamp clamp on peakdetect
 */
#define PDSS_SRSNS_4_CTRL_DIS_CLAMP_PKD                     (1UL << 0) /* <0:0> R:RW:0: */


/*
 * To double the capacitive current for peak detection
 * 1- current inside peakdetect block is equal to capacitor current (>1MHz)
 * 0 - current inside peakdetect block is double that of capacitor current
 * (<1MHz)
 */
#define PDSS_SRSNS_4_CTRL_DOUB_IACT_GEN_PKD                 (1UL << 1) /* <1:1> R:RW:0: */


/*
 * To double the capacitive current for valley detection
 * 0- current inside valleydetect block is equal to capacitor current (>1Mhz)
 * 1 - current inside valleydetect block is double that of capacitor current
 * (<1Mhz)
 */
#define PDSS_SRSNS_4_CTRL_DOUB_IACT_GEN_VALD                (1UL << 2) /* <2:2> R:RW:1: */


/*
 * enable the vbus compensation current for peakdetect
 * 0 - disable vbus compensation current
 * 1 - enable the vbus compensation current [FW]
 */
#define PDSS_SRSNS_4_CTRL_EN_VBUS_COMP                      (1UL << 3) /* <3:3> R:RW:0: */


/*
 * 1-> increase leakage on diode mid node
 */
#define PDSS_SRSNS_4_CTRL_INC_P_SR_SEN_MID_LKG              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * reference selection bit for opamp clamp on peakdetect
 * 0 - reference based on vbgbyr
 * 1- reference based on reference current
 */
#define PDSS_SRSNS_4_CTRL_PKD_CLAMP_REF_SEL                 (1UL << 5) /* <5:5> R:RW:1: */


/*
 * Power-down signal for complete peak-detect and valleydetect block (master
 * PD)
 * 1 - Power down of entire block
 * 0 - enable bit
 */
#define PDSS_SRSNS_4_CTRL_PKD_TOP_PD                        (1UL << 6) /* <6:6> R:RW:1: */


/*
 * reference selection bit for opamp on diode based backup scheme
 * 0 - reference based on vbgbyr current
 * 1 - reference based on vbgbyr voltage from srsense
 */
#define PDSS_SRSNS_4_CTRL_RST_REF_SEL                       (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Selection pin for increasing the trip margin for clamp (used for comparator
 * speed up)
 * 0 - default margin
 * 1 - increased margin
 */
#define PDSS_SRSNS_4_CTRL_ZCDF_CLAMP_RES_BYPASS             (1UL << 8) /* <8:8> R:RW:0: */


/*
 * srsense DDFT master enable
 */
#define PDSS_SRSNS_4_CTRL_DDFT_EN_SRSENSE                   (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Increase the blanking time srgdrv disable control in ZVS
 */
#define PDSS_SRSNS_4_CTRL_INC_GDRV_ZVS_BLNK_TIME            (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Select HardIP NSN raw output to turn-off the pulldown resistor of 250Ohm
 * on pad_sr_sen
 */
#define PDSS_SRSNS_4_CTRL_SEL_CTRLN_HARDIP_NSN_PATH         (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Select HardIP control path to turn-on and off the pulldown resistor of
 * 250Ohm on pad_sr_sen
 */
#define PDSS_SRSNS_4_CTRL_SEL_CTRLN_HARDIP_PATH             (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Bypass srcomp latch output used to turn-off the pad_sr_sen pull-down resistor
 * of 250Ohm
 */
#define PDSS_SRSNS_4_CTRL_SEL_CTRLN_SRCOMP_LATCH_BYPASS     (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Select HardIP control path to turn-on and off the pulldown resistor of
 * 4K on pad_sr_sen during Peakdet
 */
#define PDSS_SRSNS_4_CTRL_SEL_CTRLP_HARDIP_PATH             (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Select HardIP control path to disable the srgdrv in ZVS
 */
#define PDSS_SRSNS_4_CTRL_SEL_GDRV_ZVS_HARDIP_PATH          (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Select NSN output to srgdrv HardIP Path
 */
#define PDSS_SRSNS_4_CTRL_SEL_NSN_HARDIP_PATH               (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Select ZCD output to srgdrv HardIP Path
 */
#define PDSS_SRSNS_4_CTRL_SEL_ZCD_HARDIP_PATH               (1UL << 17) /* <17:17> R:RW:0: */


/*
 * Select ZCDF output to srgdrv HardIP Path
 */
#define PDSS_SRSNS_4_CTRL_SEL_ZCDF_HARDIP_PATH              (1UL << 18) /* <18:18> R:RW:0: */


/*
 * srsense DDFT config control
 */
#define PDSS_SRSNS_4_CTRL_DDFT_CTRL_SRSENSE_MASK            (0x00e00000UL) /* <21:23> R:RW:0: */
#define PDSS_SRSNS_4_CTRL_DDFT_CTRL_SRSENSE_POS             (21UL)


/*
 * Power-down signal for Valley-detect block
 * 1- valleydetect PD
 * 0 - valleydetect enable
 */
#define PDSS_SRSNS_4_CTRL_VALLEYDET_PD                      (1UL << 30) /* <30:30> R:RW:1: */


/*
 * Power-down signal for diode based peak-detect scheme
 * 1- backup scheme comparator PD
 * 0 - backup scheme enable
 */
#define PDSS_SRSNS_4_CTRL_RSTCOMP_PD                        (1UL << 31) /* <31:31> R:RW:1: */


/*
 * S8PDSV2 Hard IP SRSENSE Register 5
 */
#define PDSS_SRSNS_5_CTRL_ADDRESS                           (0x400a092cUL)
#define PDSS_SRSNS_5_CTRL                                   (*(volatile uint32_t *)(0x400a092cUL))
#define PDSS_SRSNS_5_CTRL_DEFAULT                           (0x00221008UL)

/*
 * Option for low power mode
 * 1-> low power mode
 * 0 -> normal mode
 */
#define PDSS_SRSNS_5_CTRL_NSN_LP_EN                         (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Option to enable -100mV trip threshold
 * 1-> -100mV sense enable
 * 0 -> positive sense enable
 */
#define PDSS_SRSNS_5_CTRL_NSN_M100_SENSE_EN                 (1UL << 1) /* <1:1> R:RW:0: */


/*
 * To enable srcomp in negative sense mode
 * 1-> enable srcomp
 * 0-> disable srcomp
 */
#define PDSS_SRSNS_5_CTRL_NSN_M100_SRCOMP_EN                (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Power Down signal for Inverter based fast NSN detection
 */
#define PDSS_SRSNS_5_CTRL_NSN_FAST_COMP_PD                  (1UL << 3) /* <3:3> R:RW:1: */


/*
 * Enable FF based PAD_SR_SEN pull down during OVP
 */
#define PDSS_SRSNS_5_CTRL_OVP_FF_EN                         (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Disconnect 42V NFET GATE from VCCD,VDDD_CRUDE and pull it down to 0V
 */
#define PDSS_SRSNS_5_CTRL_PG_NFET42_DIS                     (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Connect GATE of 42V NFETdevice to VCCD if  high and to VDDD_CRUDE if 
 * LOW
 */
#define PDSS_SRSNS_5_CTRL_PG_NFET42_VCCDMODE                (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Disable RC network on PAD_SR_VSS
 */
#define PDSS_SRSNS_5_CTRL_RCEFFECT_DIS                      (1UL << 7) /* <7:7> R:RW:0: */


/*
 * backup diode scheme comparator output gating
 */
#define PDSS_SRSNS_5_CTRL_RSTCOMP_EN                        (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Enable Low power mode for SR comparator and OVP comparator
 */
#define PDSS_SRSNS_5_CTRL_SR_DRAIN_LPM_EN                   (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Connect SR_SEN_INT , SR_VSS_INT to 0V
 */
#define PDSS_SRSNS_5_CTRL_SR_SEN_VSS_DIS                    (1UL << 10) /* <10:10> R:RW:0: */


/*
 * external capacitor is used instead of internal one for peak detectwhen
 * set to 1
 */
#define PDSS_SRSNS_5_CTRL_EN_EXT_CAP_PKD                    (1UL << 11) /* <11:11> R:RW:0: */


/*
 * weak pull down enable on peakdetect sr drain cap path for backup scheme
 */
#define PDSS_SRSNS_5_CTRL_EN_WK_PD_PKD_DRAIN                (1UL << 12) /* <12:12> R:RW:1: */


/*
 * double the bias current for comparator in extcap mode for valley detect
 */
#define PDSS_SRSNS_5_CTRL_DOUB_BIAS_PEAK                    (1UL << 13) /* <13:13> R:RW:0: */


/*
 * double the bias current for the entire peakdetect block
 */
#define PDSS_SRSNS_5_CTRL_DOUB_BIAS_VALLEY                  (1UL << 14) /* <14:14> R:RW:0: */


/*
 * To configure positive trip threshold (50mV resolution)
 * (2 for +100mV reference)
 */
#define PDSS_SRSNS_5_CTRL_NSN_POS_REF_MASK                  (0x001f0000UL) /* <16:20> R:RW:2: */
#define PDSS_SRSNS_5_CTRL_NSN_POS_REF_POS                   (16UL)


/*
 * bits to change the bias current for peak detect
 * 0 - 0 nA
 * 1- 200 nA
 * 2 - 400 nA
 * 4 - 800 nA
 * 7 - 1400 nA
 */
#define PDSS_SRSNS_5_CTRL_PEAKDET_BIAS_MASK                 (0x00e00000UL) /* <21:23> R:RW:1: */
#define PDSS_SRSNS_5_CTRL_PEAKDET_BIAS_POS                  (21UL)


/*
 * <31:27> : unused
 * <26>= 1 :  ZCD 2nd stage tail current pulldown nbti fix disable.
 * <25:24>: SR-cap mode pulldown res options for ZCDF (00:2K default; 01:
 * 1K; 10: 4K; 11: 3K)
 */
#define PDSS_SRSNS_5_CTRL_SRSENSE_CONFIG_MASK               (0xff000000UL) /* <24:31> R:RW:0: */
#define PDSS_SRSNS_5_CTRL_SRSENSE_CONFIG_POS                (24UL)


/*
 * S8PDSV2 Hard IP SRSENSE Register 6
 */
#define PDSS_SRSNS_6_CTRL_ADDRESS                           (0x400a0930UL)
#define PDSS_SRSNS_6_CTRL                                   (*(volatile uint32_t *)(0x400a0930UL))
#define PDSS_SRSNS_6_CTRL_DEFAULT                           (0x00806000UL)

/*
 * Valley detector output enable signal
 */
#define PDSS_SRSNS_6_CTRL_VALLEYDET_EN                      (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Bypass crude regulator
 * 0: crude regulator is enabled
 * 1: crude regulator is disabled
 */
#define PDSS_SRSNS_6_CTRL_VDDD_CRUDE_BYPASS_EN              (1UL << 1) /* <1:1> R:RW:0: */


/*
 * SR Drain VSS is connected to  VGND pin
 */
#define PDSS_SRSNS_6_CTRL_VGND_AS_SR_VSS_EN                 (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Enable signal to increase hysteresis to 8mV
 */
#define PDSS_SRSNS_6_CTRL_ZCD_HYST_8M                       (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Hysteresis enable signal
 * 1: enable (Default: 4mV)
 * 0: disable
 */
#define PDSS_SRSNS_6_CTRL_ZCD_HYST_DEF                      (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Low Power Mode enable signal
 * 0: disable (Default)
 * 1: enable
 */
#define PDSS_SRSNS_6_CTRL_ZCD_LP_EN                         (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Offset Control signals
 * 00: +16mV to -16mV (Default)
 * 01: +32mV to -32mV
 * 10: Invalid
 * 11: +48mV to -48mV
 */
#define PDSS_SRSNS_6_CTRL_ZCD_WIDE_TRIP_RANGE_MASK          (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_SRSNS_6_CTRL_ZCD_WIDE_TRIP_RANGE_POS           (6UL)


/*
 * Selection pin for defining supply(vddd or crude regulator output) to the
 * comparator
 * 0 - crude regulator output
 * 1 - vddd
 */
#define PDSS_SRSNS_6_CTRL_ZCDF_BYPASS_VDDD_CR               (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Selection pin for input to the zcdf comparator input through Res path
 * or Cap path
 * 0 - input through pad_sr_sen(Res path)
 * 1 - input through pad_sr_cap(Cap path)
 */
#define PDSS_SRSNS_6_CTRL_ZCDF_COMP_INP_SEL                 (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Selection pin for comparator low power mode(half current in comparator)
 * enable/disable
 * 0 - low power mode disable
 * 1 - low power mode enable
 */
#define PDSS_SRSNS_6_CTRL_ZCDF_HALF_MODE_EN                 (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Selection pin for comparator hysteresis enable/disable
 * 0 - hysteresis disabled
 * 1 - hysteresis enabled
 */
#define PDSS_SRSNS_6_CTRL_ZCDF_HYS_EN                       (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Selection pin for comparator hysteresis width
 * 0 - default width
 * 1 - double width
 */
#define PDSS_SRSNS_6_CTRL_ZCDF_HYS_SEL                      (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Option to change hysteresis
 * 1-> 0 hysteresis
 * 0-> 20m hysteresis
 */
#define PDSS_SRSNS_6_CTRL_NSN_HYST_20M                      (1UL << 13) /* <13:13> R:RW:1: */


/*
 * Option to change hysteresis
 * 1-> 0 hysteresis
 * 0-> 40m hysteresis
 */
#define PDSS_SRSNS_6_CTRL_NSN_HYST_40M                      (1UL << 14) /* <14:14> R:RW:1: */


/*
 * Enable Internal 4K pulldown
 */
#define PDSS_SRSNS_6_CTRL_RES_4K_PULLDN                     (1UL << 15) /* <15:15> R:RW:0: */


/*
 * low power mode in VBGBYR- half current
 */
#define PDSS_SRSNS_6_CTRL_VBGBYR_IBIAS_0P5X                 (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Double current in VBGBYR
 */
#define PDSS_SRSNS_6_CTRL_VBGBYR_IBIAS_2X                   (1UL << 17) /* <17:17> R:RW:0: */


/*
 * bits to change the bias current for valley detect
 * 0 - 0 nA
 * 1- 200 nA
 * 2 - 400 nA
 * 4 - 800 nA
 * 7 - 1400 nA
 */
#define PDSS_SRSNS_6_CTRL_VALLEYDET_BIAS_MASK               (0x03800000UL) /* <23:25> R:RW:1: */
#define PDSS_SRSNS_6_CTRL_VALLEYDET_BIAS_POS                (23UL)


/*
 * trim vref for peakdet backup scheme comparator reference
 * 0 - 0
 * 1 - 0.124
 * 2 - 0.205
 * 3 - 0.244
 * 4 - 0.284
 * 5 - 0.325
 * 6 - 0.364
 * 7 - 0.405
 */
#define PDSS_SRSNS_6_CTRL_VBGBYR_TRIM_VREF_PEAKDET_MASK     (0x1c000000UL) /* <26:28> R:RW:0: */
#define PDSS_SRSNS_6_CTRL_VBGBYR_TRIM_VREF_PEAKDET_POS      (26UL)


/*
 * S8PDSV2 Hard IP Error Amplifier Register 3
 */
#define PDSS_PDS_EA_3_CTRL_ADDRESS                          (0x400a0934UL)
#define PDSS_PDS_EA_3_CTRL                                  (*(volatile uint32_t *)(0x400a0934UL))
#define PDSS_PDS_EA_3_CTRL_DEFAULT                          (0x000181c0UL)

/*
 * Enable bit for buffering in vref_cc path for 2.5mV trimming as well matching
 * cc_ctrl_in path [FW]
 * 0: Same as legacy
 * Internally gated with EN_CC
 */
#define PDSS_PDS_EA_3_CTRL_EN_CC_VREF_BUFFER                (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Resolution for EPR range (beyond 1023 DAC code):
 * 1 : 100mV step
 * 0 : 50mV step
 */
#define PDSS_PDS_EA_3_CTRL_EN_LOWRES_EPR                    (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Enabling bit for high side clamp for EA [FW]
 */
#define PDSS_PDS_EA_3_CTRL_EN_MAX_VCLAMP                    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Enabling bit for low side clamp for EA [FW]
 */
#define PDSS_PDS_EA_3_CTRL_EN_MIN_VCLAMP                    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Max clamp setting ; Each step is 100mV; Setting of 2 = 2.3V
 */
#define PDSS_PDS_EA_3_CTRL_SEL_MAX_VCLAMP_MASK              (0x00000060UL) /* <5:6> R:RW:2: */
#define PDSS_PDS_EA_3_CTRL_SEL_MAX_VCLAMP_POS               (5UL)


/*
 * Min Clamp setting ; Each step is 50mV ; Setting of 3 = 250mV
 */
#define PDSS_PDS_EA_3_CTRL_SEL_MIN_VCLAMP_MASK              (0x00000780UL) /* <7:10> R:RW:3: */
#define PDSS_PDS_EA_3_CTRL_SEL_MIN_VCLAMP_POS               (7UL)


/*
 * Additional trim to get 2.5mV resolution for vref_cc
 */
#define PDSS_PDS_EA_3_CTRL_TR_VREF_CC_MASK                  (0x00001800UL) /* <11:12> R:RW:0: */
#define PDSS_PDS_EA_3_CTRL_TR_VREF_CC_POS                   (11UL)


/*
 * RC filter on vref_cc [FW] ; To be matched with TR_CCIN_RCFILTER_BW
 */
#define PDSS_PDS_EA_3_CTRL_TR_VREF_CC_RCFILTER_BW_MASK      (0x0001e000UL) /* <13:16> R:RW:12: */
#define PDSS_PDS_EA_3_CTRL_TR_VREF_CC_RCFILTER_BW_POS       (13UL)


/*
 * USBPD Hard IP Battery Charger #1-4 Register2
 */
#define PDSS_BCH_DET_2_CTRL_ADDRESS                         (0x400a0940UL)
#define PDSS_BCH_DET_2_CTRL                                 (*(volatile uint32_t *)(0x400a0940UL))
#define PDSS_BCH_DET_2_CTRL_DEFAULT                         (0x00014000UL)

/*
 * DP/DM Impedance Detection enable signal
 * 1 - Enable
 * 0 - Disable
 */
#define PDSS_BCH_DET_2_CTRL_EN_IMP_DET                      (1UL << 0) /* <0:0> R:RW:0: */


/*
 * DP/DM OVP Detection enable signal
 * 1 - Enable
 * 0 - Disable
 */
#define PDSS_BCH_DET_2_CTRL_EN_OVP_DET                      (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Select bit for Impedance Detection on DP or DM pin
 * 0: DP pin
 * 1: DM pin
 */
#define PDSS_BCH_DET_2_CTRL_SEL_IMP_DPDM                    (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Select bit for Impedance Detection Reference Voltage
 * 0: 400mV
 * 1: 296mV
 */
#define PDSS_BCH_DET_2_CTRL_SEL_IMP_VREF                    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Enable DPDM_IMP_OVP Block ADFT Mode
 */
#define PDSS_BCH_DET_2_CTRL_ADFT_IMP_OVP_EN                 (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Current Sink Enable for DM
 * 1 - Enable
 * 0 - Disable
 */
#define PDSS_BCH_DET_2_CTRL_ISINK_TRIM_DN_EN                (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Current Sink Enable for DP
 * 1 - Enable
 * 0 - Disable
 */
#define PDSS_BCH_DET_2_CTRL_ISINK_TRIM_DP_EN                (1UL << 6) /* <6:6> R:RW:0: */


/*
 * DPDM_IMP_OVP Block ADFT Select Control.
 * See the s8pdsv2 BROS for more details
 */
#define PDSS_BCH_DET_2_CTRL_ADFT_IMP_OVP_SEL_MASK           (0x00001800UL) /* <11:12> R:RW:0: */
#define PDSS_BCH_DET_2_CTRL_ADFT_IMP_OVP_SEL_POS            (11UL)


/*
 * Control bits to alter hysteresis of impedance detection comparator
 * 2'b00 = 0mV
 * 2'b01 = 13.94mV - 26.4mV
 * 2'b10 = 28.25mV - 54.2mV
 * 2'b11 = 43.66mV - 85.84mV
 */
#define PDSS_BCH_DET_2_CTRL_HYST_IMP_COMP_MASK              (0x00006000UL) /* <13:14> R:RW:2: */
#define PDSS_BCH_DET_2_CTRL_HYST_IMP_COMP_POS               (13UL)


/*
 * Control bits to alter hysteresis of OVP detection comparator wrt DP/DM
 * 2'b00 = 0mV
 * 2'b01 = 60.73mV - 119.35mV
 * 2'b10 = 123.15mV - 245.77mV
 * 2'b11 = 190.56mV - 390.35mV
 */
#define PDSS_BCH_DET_2_CTRL_HYST_OVP_COMP_MASK              (0x00018000UL) /* <15:16> R:RW:2: */
#define PDSS_BCH_DET_2_CTRL_HYST_OVP_COMP_POS               (15UL)


/*
 * USBPD Hard IP R AMUX #1-6 Register
 */
#define PDSS_R_AMUX_CTRL_ADDRESS                            (0x400a0950UL)
#define PDSS_R_AMUX_CTRL                                    (*(volatile uint32_t *)(0x400a0950UL))
#define PDSS_R_AMUX_CTRL_DEFAULT                            (0x00000000UL)

/*
 * R_AMUX select control. Used when adc_meas_en is not set.
 */
#define PDSS_R_AMUX_CTRL_SELECT_MASK                        (0x00000006UL) /* <1:2> R:RW:0:USB_R_AMUX_NUM */
#define PDSS_R_AMUX_CTRL_SELECT_POS                         (1UL)


/*
 * Round Robin ADC SAR Control Register
 */
#define PDSS_R_ADC_SAR_CTRL_ADDRESS                         (0x400a0954UL)
#define PDSS_R_ADC_SAR_CTRL                                 (*(volatile uint32_t *)(0x400a0954UL))
#define PDSS_R_ADC_SAR_CTRL_DEFAULT                         (0x00008000UL)

/*
 * Setting this bit will enable the HW SAR logic.
 * Once the SAR_EN is one, Hardware will update the  SAR_OUT register after
 * 8 cycles of clk_sar and clear this register.
 */
#define PDSS_R_ADC_SAR_CTRL_SAR_EN                          (1UL << 0) /* <0:0> RW1C:RW1S:0: */


/*
 * ADC starting mid value
 */
#define PDSS_R_ADC_SAR_CTRL_MID_VAL_MASK                    (0x0000ff00UL) /* <8:15> R:RW:128: */
#define PDSS_R_ADC_SAR_CTRL_MID_VAL_POS                     (8UL)


/*
 * ADC output resistance value
 * Stored 8-bit ADC value after the ID Pin voltage is sampled.
 */
#define PDSS_R_ADC_SAR_CTRL_SAR_OUT_MASK                    (0x00ff0000UL) /* <16:23> RW:R:0: */
#define PDSS_R_ADC_SAR_CTRL_SAR_OUT_POS                     (16UL)


/*
 * Round Robin ADC DAC Register
 */
#define PDSS_R_ADC_CTRL_ADDRESS                             (0x400a0958UL)
#define PDSS_R_ADC_CTRL                                     (*(volatile uint32_t *)(0x400a0958UL))
#define PDSS_R_ADC_CTRL_DEFAULT                             (0x80000200UL)

/*
 * Control bits for 8-bit DAC.
 * DAC_CNTRL register is used only if CPU wants to implement the SAR algorithm
 * in FW.
 */
#define PDSS_R_ADC_CTRL_DAC_CNTRL_MASK                      (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_R_ADC_CTRL_DAC_CNTRL_POS                       (0UL)


/*
 * ADC DFT Control:
 * 0: Normal operation
 * 1: DAC output voltage
 * p
 */
#define PDSS_R_ADC_CTRL_DFT_MUXSEL                          (1UL << 8) /* <8:8> R:RW:0: */


/*
 * This is for when high voltage supply for a port is not present. This bit
 * should be set when the high voltage is present,
 * in order to ensure that the outputs are set to know values.
 * 0: All outputs are isolated to a known value
 * 1: Normal operation
 */
#define PDSS_R_ADC_CTRL_ADC_ISO_N                           (1UL << 9) /* <9:9> R:RW:1: */


/*
 * Comparator Output.  If voltage on ID pin is less than DAC voltage, then
 * cmp_out is HIGH.
 */
#define PDSS_R_ADC_CTRL_CMP_OUT                             (1UL << 15) /* <15:15> RW:R:0: */


/*
 * Input Voltage select
 * p
 */
#define PDSS_R_ADC_CTRL_VSEL_MASK                           (0x00060000UL) /* <17:18> R:RW:0: */
#define PDSS_R_ADC_CTRL_VSEL_POS                            (17UL)


/*
 * Bit to select between VDDD reference and vref_dac
 * 0 : vref_dac
 * 1 : vddd
 */
#define PDSS_R_ADC_CTRL_VREF_DAC_SEL                        (1UL << 19) /* <19:19> R:RW:0: */


/*
 * 0 : Works like legacy ADC function
 * 1. Works like RoundRobin ADC enable
 */
#define PDSS_R_ADC_CTRL_ADC_MEAS_EN                         (1UL << 30) /* <30:30> R:RW:0: */


/*
 * ADC Power down control, active high.
 */
#define PDSS_R_ADC_CTRL_PD_LV                               (1UL << 31) /* <31:31> R:RW:1: */


/*
 * Round Robin CONFIG Register
 */
#define PDSS_RNDRBN_CFG_ADDRESS                             (0x400a095cUL)
#define PDSS_RNDRBN_CFG                                     (*(volatile uint32_t *)(0x400a095cUL))
#define PDSS_RNDRBN_CFG_DEFAULT                             (0x00c0001fUL)

/*
 * Time after which entire one round of round-robin measurement is repeated.
 * Running on ADC clk (1Mhz)
 */
#define PDSS_RNDRBN_CFG_IDLE_TIME_MASK                      (0x0001ffffUL) /* <0:16> R:RW:31: */
#define PDSS_RNDRBN_CFG_IDLE_TIME_POS                       (0UL)


/*
 * Settling time before measruement of any new channel (if a particular channel
 * is measured 4 times, settling time is only for the first measurement);
 * Running on ADC clk (1Mhz)
 */
#define PDSS_RNDRBN_CFG_SETTLING_TIME_MASK                  (0x01f00000UL) /* <20:24> R:RW:12: */
#define PDSS_RNDRBN_CFG_SETTLING_TIME_POS                   (20UL)


/*
 * To Powerdown ADC during Idle time
 */
#define PDSS_RNDRBN_CFG_ADC_PD_IN_IDLE                      (1UL << 31) /* <31:31> R:RW:0: */


/*
 * Round Robin STATUS Register
 */
#define PDSS_RNDRBN_STATUS_ADDRESS                          (0x400a0960UL)
#define PDSS_RNDRBN_STATUS                                  (*(volatile uint32_t *)(0x400a0960UL))
#define PDSS_RNDRBN_STATUS_DEFAULT                          (0x00000000UL)

#define PDSS_RNDRBN_STATUS_CURR_CHAN_NUM_MASK               (0x00007000UL) /* <12:14> RW:R:0: */
#define PDSS_RNDRBN_STATUS_CURR_CHAN_NUM_POS                (12UL)


#define PDSS_RNDRBN_STATUS_CURR_SAMPLE_CNT_MASK             (0x00070000UL) /* <16:18> RW:R:0: */
#define PDSS_RNDRBN_STATUS_CURR_SAMPLE_CNT_POS              (16UL)


#define PDSS_RNDRBN_STATUS_CURR_ACCUM_VAL_MASK              (0xffe00000UL) /* <21:31> RW:R:0: */
#define PDSS_RNDRBN_STATUS_CURR_ACCUM_VAL_POS               (21UL)


/*
 * Round Robin Channel CONFIG Register
 */
#define PDSS_RNDRBN_CHAN_CFG_ADDRESS(n)                     (0x400a0970UL + ((n) * (0x0004UL)))
#define PDSS_RNDRBN_CHAN_CFG(n)                             (*(volatile uint32_t *)(0x400a0970UL + ((n) * 0x0004UL)))
#define PDSS_RNDRBN_CHAN_CFG_DEFAULT                        (0x00000000UL)

#define PDSS_RNDRBN_CHAN_CFG_SAMPLE_CNT_MASK                (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_RNDRBN_CHAN_CFG_SAMPLE_CNT_POS                 (0UL)


#define PDSS_RNDRBN_CHAN_CFG_EN_SAMPLING                    (1UL << 31) /* <31:31> R:RW:0: */


/*
 * Round Robin Channel STATUS Register
 */
#define PDSS_RNDRBN_CHAN_STATUS_ADDRESS(n)                  (0x400a0990UL + ((n) * (0x0004UL)))
#define PDSS_RNDRBN_CHAN_STATUS(n)                          (*(volatile uint32_t *)(0x400a0990UL + ((n) * 0x0004UL)))
#define PDSS_RNDRBN_CHAN_STATUS_DEFAULT                     (0x00000000UL)

#define PDSS_RNDRBN_CHAN_STATUS_AVG_MEAS_VAL_MASK           (0x000000ffUL) /* <0:7> RW:RW:0: */
#define PDSS_RNDRBN_CHAN_STATUS_AVG_MEAS_VAL_POS            (0UL)


#define PDSS_RNDRBN_CHAN_STATUS_MEAS_DONE_MASK              (0x0000f000UL) /* <12:15> RW1SC:RW:0: */
#define PDSS_RNDRBN_CHAN_STATUS_MEAS_DONE_POS               (12UL)


/*
 * S8PDS NGDO Gate driver config1 (Only for PAG1S)
 */
#define PDSS_NGDO_1_CFG_ADDRESS                             (0x400a2000UL)
#define PDSS_NGDO_1_CFG                                     (*(volatile uint32_t *)(0x400a2000UL))
#define PDSS_NGDO_1_CFG_DEFAULT                             (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gdrv_en  pin
 * 1: HW controlls the  gdrv_en  pin
 */
#define PDSS_NGDO_1_CFG_AUTO_MODE                           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control option.
 * Any write-one to this register will reset the edge detector in the controller.
 * FW should cleared this register after the fault conditions are removed
 * by writing a "1" to this register.
 */
#define PDSS_NGDO_1_CFG_RST_EDGE_DET                        (1UL << 1) /* <1:1> R:RW:0: */


/*
 * CPU can used this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected.
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_NGDO_1_CFG_SEL_ON_OFF                          (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Bit[18]:
 * 0: FILT20 detection is not selected for turning off the gdrv_en
 * 1: FILT20 detection is       selected for turning off the gdrv_en
 * Bit[19]:
 * 0: FILT21 detection is not selected for turning off the gdrv_en
 * 1: FILT21 detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_FILT2_MASK                      (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_NGDO_1_CFG_SEL_FILT2_POS                       (6UL)


/*
 * The Off value used by Hardware in Automode to turn off the gdrv_en bit
 */
#define PDSS_NGDO_1_CFG_GDRV_EN_OFF_VALUE                   (1UL << 17) /* <17:17> R:RW:0: */


/*
 * The ON value used by Hardware to turn on the gdrv_en bit
 */
#define PDSS_NGDO_1_CFG_GDRV_EN_ON_VALUE                    (1UL << 18) /* <18:18> R:RW:0: */


/*
 * 0: zcd_out detection is not selected for turning off the gdrv_en
 * 1: zcd_out detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_ZCD_OUT                         (1UL << 19) /* <19:19> R:RW:0: */


/*
 * 0: nsn_out detection is not selected for turning off the gdrv_en
 * 1: nsn_out detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_NSN_OUT                         (1UL << 20) /* <20:20> R:RW:0: */


/*
 * 0: pwm_out detection is not selected for turning off the gdrv_en
 * 1: pwm_out detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_PWM_OUT                         (1UL << 21) /* <21:21> R:RW:0: */


/*
 * 0: burst_exit_out detection is not selected for turning off the gdrv_en
 * 1: burst_exit_out detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_BURST_EXIT_OUT                  (1UL << 22) /* <22:22> R:RW:0: */


/*
 * 0: sr_sen_ovp_out detection is not selected for turning off the gdrv_en
 * 1: sr_sen_ovp_out detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_SR_SEN_OVP_OUT                  (1UL << 23) /* <23:23> R:RW:0: */


/*
 * 0: skip_out detection is not selected for turning off the gdrv_en
 * 1: skip_out detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_SKIP_OUT                        (1UL << 24) /* <24:24> R:RW:0: */


/*
 * 0: peakdet_out detection is not selected for turning off the gdrv_en
 * 1: peakdet_out detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_PEAKDET_OUT                     (1UL << 25) /* <25:25> R:RW:0: */


/*
 * 0: peakdet_rst_out detection is not selected for turning off the gdrv_en
 * 1: peakdet_rst_out detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_PEAKDET_RST_OUT                 (1UL << 26) /* <26:26> R:RW:0: */


/*
 * 0: peakdet_clcmp_raw_out detection is not selected for turning off the
 * gdrv_en
 * 1: peakdet_clcmp_raw_out detection is       selected for turning off the
 * gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_PEAKDET_CLCMP_RAW_OUT           (1UL << 27) /* <27:27> R:RW:0: */


/*
 * 0: zcdf_out detection is not selected for turning off the gdrv_en
 * 1: zcdf_out detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_ZCDF_OUT                        (1UL << 28) /* <28:28> R:RW:0: */


/*
 * 0: SCP detection is not selected for turning off the gdrv_en
 * 1: SCP detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_PDS_SCP                         (1UL << 29) /* <29:29> R:RW:0: */


/*
 * 0: FF_UV detection is not selected for turning off the gdrv_en
 * 1:FF_UV detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_FF_UV                           (1UL << 30) /* <30:30> R:RW:0: */


/*
 * 0: FF_OV detection is not selected for turning off the gdrv_en
 * 1: FF_OV detection is       selected for turning off the gdrv_en
 */
#define PDSS_NGDO_1_CFG_SEL_FF_OV                           (1UL << 31) /* <31:31> R:RW:0: */


/*
 * S8PDS NGDO Gate driver config2 (Only for PAG1S)
 */
#define PDSS_NGDO_2_CFG_ADDRESS                             (0x400a2004UL)
#define PDSS_NGDO_2_CFG                                     (*(volatile uint32_t *)(0x400a2004UL))
#define PDSS_NGDO_2_CFG_DEFAULT                             (0x00000000UL)

/*
 * There can be a maximum of 24 HS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function
 */
#define PDSS_NGDO_2_CFG_HS_SOURCE_SEL_MASK                  (0x0000001fUL) /* <0:4> R:RW:0:CLK_FILTER_FILT_NUM */
#define PDSS_NGDO_2_CFG_HS_SOURCE_SEL_POS                   (0UL)


/*
 * There can be a maximum of 8 LS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function.
 */
#define PDSS_NGDO_2_CFG_LS_SOURCE_SEL_MASK                  (0x03000000UL) /* <24:25> R:RW:0:CLK_LF_FILT_NUM */
#define PDSS_NGDO_2_CFG_LS_SOURCE_SEL_POS                   (24UL)


/*
 * SRSENSE gate driver config1
 */
#define PDSS_SRSNS_1_CFG_ADDRESS                            (0x400a2008UL)
#define PDSS_SRSNS_1_CFG                                    (*(volatile uint32_t *)(0x400a2008UL))
#define PDSS_SRSNS_1_CFG_DEFAULT                            (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the sr_sen_pulldn_en  pin
 * 1: HW controlls the  sr_sen_pulldn_en  pin
 */
#define PDSS_SRSNS_1_CFG_AUTO_MODE                          (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control option.
 * Any write-one to this register will reset the edge detector in the controller.
 * FW should cleared this register after the fault conditions are removed
 * by writing a "1" to this register.
 */
#define PDSS_SRSNS_1_CFG_RST_EDGE_DET                       (1UL << 1) /* <1:1> R:RW:0: */


/*
 * CPU can used this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected.
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SRSNS_1_CFG_SEL_ON_OFF                         (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Bit[18]:
 * 0: FILT20 detection is not selected for turning off the sr_sen_pulldn_en
 * 1: FILT20 detection is       selected for turning off the sr_sen_pulldn_en
 * Bit[19]:
 * 0: FILT21 detection is not selected for turning off the sr_sen_pulldn_en
 * 1: FILT21 detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_FILT2_MASK                     (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_SRSNS_1_CFG_SEL_FILT2_POS                      (6UL)


/*
 * The Off value used by Hardware in Automode to turn off the sr_sen_pulldn_en
 * bit
 */
#define PDSS_SRSNS_1_CFG_PULLDN_EN_OFF_VALUE                (1UL << 17) /* <17:17> R:RW:0: */


/*
 * The ON value used by Hardware to turn on the sr_sen_pulldn_en bit
 */
#define PDSS_SRSNS_1_CFG_PULLDN_EN_ON_VALUE                 (1UL << 18) /* <18:18> R:RW:0: */


/*
 * 0: zcd_out detection is not selected for turning off the sr_sen_pulldn_en
 * 1: zcd_out detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_ZCD_OUT                        (1UL << 19) /* <19:19> R:RW:0: */


/*
 * 0: nsn_out detection is not selected for turning off the sr_sen_pulldn_en
 * 1: nsn_out detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_NSN_OUT                        (1UL << 20) /* <20:20> R:RW:0: */


/*
 * 0: pwm_out detection is not selected for turning off the sr_sen_pulldn_en
 * 1: pwm_out detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_PWM_OUT                        (1UL << 21) /* <21:21> R:RW:0: */


/*
 * 0: burst_exit_out detection is not selected for turning off the sr_sen_pulldn_en
 * 1: burst_exit_out detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_BURST_EXIT_OUT                 (1UL << 22) /* <22:22> R:RW:0: */


/*
 * 0: sr_sen_ovp_out detection is not selected for turning off the sr_sen_pulldn_en
 * 1: sr_sen_ovp_out detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_SR_SEN_OVP_OUT                 (1UL << 23) /* <23:23> R:RW:0: */


/*
 * 0: skip_out detection is not selected for turning off the sr_sen_pulldn_en
 * 1: skip_out detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_SKIP_OUT                       (1UL << 24) /* <24:24> R:RW:0: */


/*
 * 0: peakdet_out detection is not selected for turning off the sr_sen_pulldn_en
 * 1: peakdet_out detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_PEAKDET_OUT                    (1UL << 25) /* <25:25> R:RW:0: */


/*
 * 0: peakdet_rst_out detection is not selected for turning off the sr_sen_pulldn_en
 * 1: peakdet_rst_out detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_PEAKDET_RST_OUT                (1UL << 26) /* <26:26> R:RW:0: */


/*
 * 0: peakdet_clcmp_raw_out detection is not selected for turning off the
 * sr_sen_pulldn_en
 * 1: peakdet_clcmp_raw_out detection is       selected for turning off the
 * sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_PEAKDET_CLCMP_RAW_OUT          (1UL << 27) /* <27:27> R:RW:0: */


/*
 * 0: zcdf_out detection is not selected for turning off the sr_sen_pulldn_en
 * 1: zcdf_out detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_ZCDF_OUT                       (1UL << 28) /* <28:28> R:RW:0: */


/*
 * 0: SCP detection is not selected for turning off the sr_sen_pulldn_en
 * 1: SCP detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_PDS_SCP                        (1UL << 29) /* <29:29> R:RW:0: */


/*
 * 0: FF_UV detection is not selected for turning off the sr_sen_pulldn_en
 * 1:FF_UV detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_FF_UV                          (1UL << 30) /* <30:30> R:RW:0: */


/*
 * 0: FF_OV detection is not selected for turning off the sr_sen_pulldn_en
 * 1: FF_OV detection is       selected for turning off the sr_sen_pulldn_en
 */
#define PDSS_SRSNS_1_CFG_SEL_FF_OV                          (1UL << 31) /* <31:31> R:RW:0: */


/*
 * SRSENSE gate driver config2
 */
#define PDSS_SRSNS_2_CFG_ADDRESS                            (0x400a200cUL)
#define PDSS_SRSNS_2_CFG                                    (*(volatile uint32_t *)(0x400a200cUL))
#define PDSS_SRSNS_2_CFG_DEFAULT                            (0x00000000UL)

/*
 * There can be a maximum of 24 HS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function
 */
#define PDSS_SRSNS_2_CFG_HS_SOURCE_SEL_MASK                 (0x0000001fUL) /* <0:4> R:RW:0:CLK_FILTER_FILT_NUM */
#define PDSS_SRSNS_2_CFG_HS_SOURCE_SEL_POS                  (0UL)


/*
 * There can be a maximum of 8 LS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function.
 */
#define PDSS_SRSNS_2_CFG_LS_SOURCE_SEL_MASK                 (0x03000000UL) /* <24:25> R:RW:0:CLK_LF_FILT_NUM */
#define PDSS_SRSNS_2_CFG_LS_SOURCE_SEL_POS                  (24UL)


/*
 * SRSENSE HardIP CLK_PASC Filter and Edge detector configuration for PEAKDET_OUT
 * and ZCDF_OUT detection
 */
#define PDSS_INTR15_CFG_1_SRSENSE_ADDRESS                   (0x400a2018UL)
#define PDSS_INTR15_CFG_1_SRSENSE                           (*(volatile uint32_t *)(0x400a2018UL))
#define PDSS_INTR15_CFG_1_SRSENSE_DEFAULT                   (0x00208410UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR15_CFG_1_SRSENSE_PEAKDET_OUT_FILT_EN       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR15_CFG_1_SRSENSE_PEAKDET_OUT_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR15_CFG_1_SRSENSE_PEAKDET_OUT_FILT_CFG_POS    (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR15_CFG_1_SRSENSE_PEAKDET_OUT_FILT_RESET    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR15_CFG_1_SRSENSE_PEAKDET_OUT_FILT_BYPASS    (1UL << 4) /* <4:4> R:RW:1: */


/*
 * #of clock CLK_PASC filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR15_CFG_1_SRSENSE_PEAKDET_OUT_FILT_SEL_MASK    (0x000000e0UL) /* <5:7> R:RW:0: */
#define PDSS_INTR15_CFG_1_SRSENSE_PEAKDET_OUT_FILT_SEL_POS    (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR15_CFG_1_SRSENSE_PEAKDET_OUT_DPSLP_MODE    (1UL << 10) /* <10:10> R:RW:1: */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR15_CFG_1_SRSENSE_ZCDF_OUT_FILT_EN          (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR15_CFG_1_SRSENSE_ZCDF_OUT_FILT_CFG_MASK    (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_INTR15_CFG_1_SRSENSE_ZCDF_OUT_FILT_CFG_POS     (12UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR15_CFG_1_SRSENSE_ZCDF_OUT_FILT_RESET       (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR15_CFG_1_SRSENSE_ZCDF_OUT_FILT_BYPASS      (1UL << 15) /* <15:15> R:RW:1: */


/*
 * #of clock CLK_PASC filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR15_CFG_1_SRSENSE_ZCDF_OUT_FILT_SEL_MASK    (0x000f0000UL) /* <16:19> R:RW:0: */
#define PDSS_INTR15_CFG_1_SRSENSE_ZCDF_OUT_FILT_SEL_POS     (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR15_CFG_1_SRSENSE_ZCDF_OUT_DPSLP_MODE       (1UL << 21) /* <21:21> R:RW:1: */


/*
 * SRSENSE HardIP High/Low Speed Filter and Edge detector configuration for
 * NSN_OUT and ZCD_OUT detection
 */
#define PDSS_INTR15_CFG_4_SRSENSE_ADDRESS                   (0x400a2024UL)
#define PDSS_INTR15_CFG_4_SRSENSE                           (*(volatile uint32_t *)(0x400a2024UL))
#define PDSS_INTR15_CFG_4_SRSENSE_DEFAULT                   (0x00208410UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR15_CFG_4_SRSENSE_NSN_OUT_FILT_EN           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR15_CFG_4_SRSENSE_NSN_OUT_FILT_CFG_MASK     (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR15_CFG_4_SRSENSE_NSN_OUT_FILT_CFG_POS      (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR15_CFG_4_SRSENSE_NSN_OUT_FILT_RESET        (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR15_CFG_4_SRSENSE_NSN_OUT_FILT_BYPASS       (1UL << 4) /* <4:4> R:RW:1: */


/*
 * #of clock CLK_PASC filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR15_CFG_4_SRSENSE_NSN_OUT_FILT_SEL_MASK     (0x000001e0UL) /* <5:8> R:RW:0: */
#define PDSS_INTR15_CFG_4_SRSENSE_NSN_OUT_FILT_SEL_POS      (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR15_CFG_4_SRSENSE_NSN_OUT_DPSLP_MODE        (1UL << 10) /* <10:10> R:RW:1: */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR15_CFG_4_SRSENSE_ZCD_OUT_FILT_EN           (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR15_CFG_4_SRSENSE_ZCD_OUT_FILT_CFG_MASK     (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_INTR15_CFG_4_SRSENSE_ZCD_OUT_FILT_CFG_POS      (12UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR15_CFG_4_SRSENSE_ZCD_OUT_FILT_RESET        (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR15_CFG_4_SRSENSE_ZCD_OUT_FILT_BYPASS       (1UL << 15) /* <15:15> R:RW:1: */


/*
 * #of clock CLK_PASC filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR15_CFG_4_SRSENSE_ZCD_OUT_FILT_SEL_MASK     (0x000f0000UL) /* <16:19> R:RW:0: */
#define PDSS_INTR15_CFG_4_SRSENSE_ZCD_OUT_FILT_SEL_POS      (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR15_CFG_4_SRSENSE_ZCD_OUT_DPSLP_MODE        (1UL << 21) /* <21:21> R:RW:1: */


/*
 * PWM Hard IP CLK_PASC Filter and Edge detector configuration for PWM_OUT
 * and SKIP_OUT
 */
#define PDSS_INTR15_CFG_0_PWM_ADDRESS                       (0x400a2028UL)
#define PDSS_INTR15_CFG_0_PWM                               (*(volatile uint32_t *)(0x400a2028UL))
#define PDSS_INTR15_CFG_0_PWM_DEFAULT                       (0x00250c10UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR15_CFG_0_PWM_PWM_OUT_FILT_EN               (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR15_CFG_0_PWM_PWM_OUT_FILT_CFG_MASK         (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR15_CFG_0_PWM_PWM_OUT_FILT_CFG_POS          (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR15_CFG_0_PWM_PWM_OUT_FILT_RESET            (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR15_CFG_0_PWM_PWM_OUT_FILT_BYPASS           (1UL << 4) /* <4:4> R:RW:1: */


/*
 * PAG1S: #of clock CLK_PASC filtering. Should be programmed before FILTER
 * is enabled.
 * CCG7D: #of clock CLK_BB filtering. Should be programmed before FILTER
 * is enabled.
 */
#define PDSS_INTR15_CFG_0_PWM_PWM_OUT_FILT_SEL_MASK         (0x000000e0UL) /* <5:7> R:RW:0: */
#define PDSS_INTR15_CFG_0_PWM_PWM_OUT_FILT_SEL_POS          (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR15_CFG_0_PWM_PWM_OUT_DPSLP_MODE            (1UL << 10) /* <10:10> R:RW:1: */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR15_CFG_0_PWM_SKIP_OUT_FILT_EN              (1UL << 11) /* <11:11> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR15_CFG_0_PWM_SKIP_OUT_FILT_CFG_MASK        (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_INTR15_CFG_0_PWM_SKIP_OUT_FILT_CFG_POS         (12UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR15_CFG_0_PWM_SKIP_OUT_FILT_RESET           (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR15_CFG_0_PWM_SKIP_OUT_FILT_BYPASS          (1UL << 15) /* <15:15> R:RW:0: */


/*
 * PAG1S: #of clock CLK_PASC filtering. Should be programmed before FILTER
 * is enabled.
 * CCG7D: #of clock CLK_BB filtering. Should be programmed before FILTER
 * is enabled.
 */
#define PDSS_INTR15_CFG_0_PWM_SKIP_OUT_FILT_SEL_MASK        (0x001f0000UL) /* <16:20> R:RW:5: */
#define PDSS_INTR15_CFG_0_PWM_SKIP_OUT_FILT_SEL_POS         (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR15_CFG_0_PWM_SKIP_OUT_DPSLP_MODE           (1UL << 21) /* <21:21> R:RW:1: */


/*
 * PWM Hard IP CLK_PASC Filter and Edge detector configuration for BURST_EXIT_OUT
 */
#define PDSS_INTR15_CFG_1_PWM_ADDRESS                       (0x400a202cUL)
#define PDSS_INTR15_CFG_1_PWM                               (*(volatile uint32_t *)(0x400a202cUL))
#define PDSS_INTR15_CFG_1_PWM_DEFAULT                       (0x00000410UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR15_CFG_1_PWM_BURST_EXIT_OUT_FILT_EN        (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR15_CFG_1_PWM_BURST_EXIT_OUT_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR15_CFG_1_PWM_BURST_EXIT_OUT_FILT_CFG_POS    (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR15_CFG_1_PWM_BURST_EXIT_OUT_FILT_RESET     (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR15_CFG_1_PWM_BURST_EXIT_OUT_FILT_BYPASS    (1UL << 4) /* <4:4> R:RW:1: */


/*
 * #of clock CLK_PASC filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR15_CFG_1_PWM_BURST_EXIT_OUT_FILT_SEL_MASK    (0x000000e0UL) /* <5:7> R:RW:0: */
#define PDSS_INTR15_CFG_1_PWM_BURST_EXIT_OUT_FILT_SEL_POS    (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR15_CFG_1_PWM_BURST_EXIT_OUT_DPSLP_MODE     (1UL << 10) /* <10:10> R:RW:1: */


/*
 * S8PDS EA Hard IP CLK_LF Filter and Edge detector configuration for CC_FLAG
 */
#define PDSS_INTR15_CFG_CC_FLAG_ADDRESS                     (0x400a2030UL)
#define PDSS_INTR15_CFG_CC_FLAG                             (*(volatile uint32_t *)(0x400a2030UL))
#define PDSS_INTR15_CFG_CC_FLAG_DEFAULT                     (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_EN             (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_CFG_MASK       (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_CFG_POS        (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_RESET          (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_BYPASS         (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_SEL_MASK       (0x00003fe0UL) /* <5:13> R:RW:0: */
#define PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_SEL_POS        (5UL)


/*
 * INTR15 Status
 */
#define PDSS_INTR15_STATUS_ADDRESS                          (0x400a2038UL)
#define PDSS_INTR15_STATUS                                  (*(volatile uint32_t *)(0x400a2038UL))
#define PDSS_INTR15_STATUS_DEFAULT                          (0x00000000UL)

/*
 * The status of s8pds_ea_top.cc_flag
 */
#define PDSS_INTR15_STATUS_CC_FLAG_STATUS                   (1UL << 0) /* <0:0> RW:R:0: */


/*
 * s8pds_ea_top.cc_flag Filtered output
 */
#define PDSS_INTR15_STATUS_CC_FLAG_FILT                     (1UL << 1) /* <1:1> RW:R:0: */


/*
 * The status of vs8pds_srsense_top.peakdet_out
 */
#define PDSS_INTR15_STATUS_PEAKDET_OUT_STATUS               (1UL << 10) /* <10:10> RW:R:0:PASC_PASC2_EN */


/*
 * s8pds_srsense_top.peakdet_out Filtered output
 */
#define PDSS_INTR15_STATUS_PEAKDET_OUT_FILT                 (1UL << 11) /* <11:11> RW:R:0:PASC_PASC2_EN */


/*
 * The status of vs8pds_srsense_top.zcdf_out
 */
#define PDSS_INTR15_STATUS_ZCDF_OUT_STATUS                  (1UL << 16) /* <16:16> RW:R:0:PASC_PASC2_EN */


/*
 * s8pds_srsense_top.zcdf_out Filtered output
 */
#define PDSS_INTR15_STATUS_ZCDF_OUT_FILT                    (1UL << 17) /* <17:17> RW:R:0:PASC_PASC2_EN */


/*
 * The status of vs8pds_srsense_top.nsn
 */
#define PDSS_INTR15_STATUS_NSN_OUT_STATUS                   (1UL << 20) /* <20:20> RW:R:0:PASC_PASC2_EN */


/*
 * s8pds_srsense_top.nsn Filtered output
 */
#define PDSS_INTR15_STATUS_NSN_OUT_FILT                     (1UL << 21) /* <21:21> RW:R:0:PASC_PASC2_EN */


/*
 * The status of vs8pds_srsense_top.zcd_out
 */
#define PDSS_INTR15_STATUS_ZCD_OUT_STATUS                   (1UL << 22) /* <22:22> RW:R:0:PASC_PASC2_EN */


/*
 * s8pds_srsense_top.zcd_out Filtered output
 */
#define PDSS_INTR15_STATUS_ZCD_OUT_FILT                     (1UL << 23) /* <23:23> RW:R:0:PASC_PASC2_EN */


/*
 * The status of s8pds_pwm_top.pwm_out
 */
#define PDSS_INTR15_STATUS_PWM_OUT_STATUS                   (1UL << 24) /* <24:24> RW:R:0: */


/*
 * s8pds_pwm_top.pwm_out Filtered output
 */
#define PDSS_INTR15_STATUS_PWM_OUT_FILT                     (1UL << 25) /* <25:25> RW:R:0: */


/*
 * The status of s8pds_pwm_top.skip_out
 */
#define PDSS_INTR15_STATUS_SKIP_OUT_STATUS                  (1UL << 26) /* <26:26> RW:R:0: */


/*
 * s8pds_pwm_top.skip_out Filtered output
 */
#define PDSS_INTR15_STATUS_SKIP_OUT_FILT                    (1UL << 27) /* <27:27> RW:R:0: */


/*
 * The status of s8pds_pwm_top.burst_exit_out
 */
#define PDSS_INTR15_STATUS_BURST_EXIT_OUT_STATUS            (1UL << 28) /* <28:28> RW:R:0:PASC_PASC2_EN */


/*
 * s8pds_pwm_top.burst_exit_out Filtered output
 */
#define PDSS_INTR15_STATUS_BURST_EXIT_OUT_FILT              (1UL << 29) /* <29:29> RW:R:0:PASC_PASC2_EN */


/*
 * INTR15 interrupt Cause.
 */
#define PDSS_INTR15_ADDRESS                                 (0x400a203cUL)
#define PDSS_INTR15                                         (*(volatile uint32_t *)(0x400a203cUL))
#define PDSS_INTR15_DEFAULT                                 (0x00000000UL)

/*
 * s8pds_ea_top.cc_flag changed (wakeup interrupt from deepsleep)
 * Check the  INTR15_STATUS.CC_FLAG_STATUS value
 */
#define PDSS_INTR15_CC_FLAG_CHANGED                         (1UL << 0) /* <0:0> RW1S:RW1C:0: */


/*
 * s8pds_srsense_top.peakdet_out changed (wakeup interrupt from deepsleep)
 * Check the  INTR15_STATUS.PEACKDET_OUT_STATUS value
 */
#define PDSS_INTR15_PEAKDET_OUT_CHANGED                     (1UL << 5) /* <5:5> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * s8pds_srsense_top.zcdf_out changed (wakeup interrupt from deepsleep)
 * Check the  INTR15_STATUS.ZCDF_OUT_STATUS value
 */
#define PDSS_INTR15_ZCDF_OUT_CHANGED                        (1UL << 8) /* <8:8> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * s8pds_srsense_top.nsn_out changed (wakeup interrupt from deepsleep)
 * Check the  INTR15_STATUS.NSN'_OUT_STATUS value
 */
#define PDSS_INTR15_NSN_OUT_CHANGED                         (1UL << 10) /* <10:10> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * s8pds_srsense_top.zcd_out changed (wakeup interrupt from deepsleep)
 * Check the  INTR15_STATUS.ZCD_OUT_STATUS value
 */
#define PDSS_INTR15_ZCD_OUT_CHANGED                         (1UL << 11) /* <11:11> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * s8pds_pwm_top.pwm_out changed (wakeup interrupt from deepsleep)
 * Check the  INTR15_STATUS.PWM_OUT_STATUS value
 */
#define PDSS_INTR15_PWM_OUT_CHANGED                         (1UL << 12) /* <12:12> RW1S:RW1C:0: */


/*
 * s8pds_pwm_top.pwm_out changed (wakeup interrupt from deepsleep)
 * Check the  INTR15_STATUS.SKIP_OUT_STATUS value
 */
#define PDSS_INTR15_SKIP_OUT_CHANGED                        (1UL << 13) /* <13:13> RW1S:RW1C:0: */


/*
 * s8pds_pwm_top.pwm_out changed (wakeup interrupt from deepsleep)
 * Check the  INTR15_STATUS.BURST_EXIT_OUT_STATUS value
 */
#define PDSS_INTR15_BURST_EXIT_OUT_CHANGED                  (1UL << 14) /* <14:14> RW1S:RW1C:0:PASC_PASC2_EN */


/*
 * INTR15 Interrupt Set
 */
#define PDSS_INTR15_SET_ADDRESS                             (0x400a2040UL)
#define PDSS_INTR15_SET                                     (*(volatile uint32_t *)(0x400a2040UL))
#define PDSS_INTR15_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_SET_CC_FLAG_CHANGED                     (1UL << 0) /* <0:0> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_SET_PEAKDET_OUT_CHANGED                 (1UL << 5) /* <5:5> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_SET_ZCDF_OUT_CHANGED                    (1UL << 8) /* <8:8> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_SET_NSN_OUT_CHANGED                     (1UL << 10) /* <10:10> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_SET_ZCD_OUT_CHANGED                     (1UL << 11) /* <11:11> A:RW1S:0:PASC_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_SET_PWM_OUT_CHANGED                     (1UL << 12) /* <12:12> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_SET_SKIP_OUT_CHANGED                    (1UL << 13) /* <13:13> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_SET_BURST_EXIT_OUT_CHANGED              (1UL << 14) /* <14:14> A:RW1S:0:PASC_PASC2_EN */


/*
 * INTR15 interrupt Mask
 */
#define PDSS_INTR15_MASK_ADDRESS                            (0x400a2044UL)
#define PDSS_INTR15_MASK                                    (*(volatile uint32_t *)(0x400a2044UL))
#define PDSS_INTR15_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_MASK_CC_FLAG_CHANGED_MASK               (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_MASK_PEAKDET_OUT_CHANGED_MASK           (1UL << 5) /* <5:5> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_MASK_ZCDF_OUT_CHANGED_MASK              (1UL << 8) /* <8:8> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_MASK_NSN_OUT_CHANGED_MASK               (1UL << 10) /* <10:10> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_MASK_ZCD_OUT_CHANGED_MASK               (1UL << 11) /* <11:11> R:RW:0:PASC_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_MASK_PWM_OUT_CHANGED_MASK               (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_MASK_SKIP_OUT_CHANGED_MASK              (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_MASK_BURST_EXIT_OUT_CHANGED_MASK        (1UL << 14) /* <14:14> R:RW:0:PASC_PASC2_EN */


/*
 * INTR15 interrupt Masked
 */
#define PDSS_INTR15_MASKED_ADDRESS                          (0x400a2048UL)
#define PDSS_INTR15_MASKED                                  (*(volatile uint32_t *)(0x400a2048UL))
#define PDSS_INTR15_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR15_MASKED_CC_FLAG_CHANGED_MASKED           (1UL << 0) /* <0:0> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR15_MASKED_PEAKDET_OUT_CHANGED_MASKED       (1UL << 5) /* <5:5> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR15_MASKED_ZCDF_OUT_CHANGED_MASKED          (1UL << 8) /* <8:8> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR15_MASKED_NSN_OUT_CHANGED_MASKED           (1UL << 10) /* <10:10> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR15_MASKED_ZCD_OUT_CHANGED_MASKED           (1UL << 11) /* <11:11> RW:R:0:PASC_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR15_MASKED_PWM_OUT_CHANGED_MASKED           (1UL << 12) /* <12:12> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR15_MASKED_SKIP_OUT_CHANGED_MASKED          (1UL << 13) /* <13:13> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR15_MASKED_BURST_EXIT_OUT_CHANGED_MASKED    (1UL << 14) /* <14:14> RW:R:0:PASC_PASC2_EN */


/*
 * VBUS Transition config
 */
#define PDSS_VBTR_CFG_ADDRESS                               (0x400a204cUL)
#define PDSS_VBTR_CFG                                       (*(volatile uint32_t *)(0x400a204cUL))
#define PDSS_VBTR_CFG_DEFAULT                               (0x00000000UL)

/*
 * Enable/Disable SRC operation on isrc_dac_ctrl pin of s8pds_ea_top.
 * 1 - Enable
 * 0 - Disable
 */
#define PDSS_VBTR_CFG_SRC_EN                                (1UL << 0) /* <0:0> R:RW:0: */


/*
 * SRC operation type
 * 1 - Increment
 * 0 - Decrement
 */
#define PDSS_VBTR_CFG_SRC_UP_DOWN                           (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable/Disable SNK operation on isnk_dac_ctrl pin of s8pds_ea_top.
 * 1 - Enable
 * 0 - Disable
 */
#define PDSS_VBTR_CFG_SNK_EN                                (1UL << 8) /* <8:8> R:RW:0: */


/*
 * SNK operation type
 * 1 - Increment
 * 0 - Decrement
 */
#define PDSS_VBTR_CFG_SNK_UP_DOWN                           (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Selects which operation starts first
 * 0 - Source then Sink (if SNK_EN==1)
 * 1 - Sink then Source (if SRC_EN==1)
 */
#define PDSS_VBTR_CFG_VBTR_SEL                              (1UL << 16) /* <16:16> R:RW:0: */


/*
 * To Enable EPR mode
 */
#define PDSS_VBTR_CFG_EPR_MODE_EN                           (1UL << 31) /* <31:31> R:RW:0:EPR_EN */


/*
 * VBUS Transition control
 */
#define PDSS_VBTR_CTRL_ADDRESS                              (0x400a2050UL)
#define PDSS_VBTR_CTRL                                      (*(volatile uint32_t *)(0x400a2050UL))
#define PDSS_VBTR_CTRL_DEFAULT                              (0x00000000UL)

/*
 * Start the VBTR Operation.
 * FW sets this bit to start the VBTR operation.
 * The operation starts about 3 VBTR clock cycle.
 * HW clears this bit when the current operation is complete or an exit request
 * has been processed and
 * the INTR8.VBTR_OPR_DONE/INTR8.VBTR_EXIT_DONE interrupt is cleared
 */
#define PDSS_VBTR_CTRL_START                                (1UL << 0) /* <0:0> RW0C:RW1S:0: */


/*
 * Exit the current VBTR operation.
 * The operation (incr/decr) is immediately stopped.
 * The EXIT interrupt bit is getting set within one VBTR clock cycle of the
 * EXIT bit being set.
 * SW sets this bit to exit from the current VBTR operation.
 * HW clears this bit once the exit request has been processed and
 * the INTR8.VBTR_OPR_DONE/INTR8.VBTR_EXIT_DONE interrupt is cleared
 */
#define PDSS_VBTR_CTRL_EXIT                                 (1UL << 1) /* <1:1> RW0C:RW1S:0: */


/*
 * VBUS Transition Source/Sink shadow registers
 */
#define PDSS_VBTR_SRC_SNK_OPR_VALUE_ADDRESS                 (0x400a2054UL)
#define PDSS_VBTR_SRC_SNK_OPR_VALUE                         (*(volatile uint32_t *)(0x400a2054UL))
#define PDSS_VBTR_SRC_SNK_OPR_VALUE_DEFAULT                 (0x00000000UL)

/*
 * Indicates Final SRC Register value after SRC Operation completion.
 */
#define PDSS_VBTR_SRC_SNK_OPR_VALUE_SRC_DAC_MASK            (0x0000007fUL) /* <0:6> RW:R:0: */
#define PDSS_VBTR_SRC_SNK_OPR_VALUE_SRC_DAC_POS             (0UL)


/*
 * Indicates Final SNK Register value after SNK Operation completion.
 */
#define PDSS_VBTR_SRC_SNK_OPR_VALUE_SNK_DAC_MASK            (0x03ff0000UL) /* <16:25> RW:R:0: */
#define PDSS_VBTR_SRC_SNK_OPR_VALUE_SNK_DAC_POS             (16UL)


#define PDSS_VBTR_SRC_SNK_OPR_VALUE_SNK_DAC_EPR             (1UL << 26) /* <26:26> RW:R:0:EPR_EN */


/*
 * VBUS Transition Source Initial/Final value registers
 */
#define PDSS_VBTR_SRC_INIT_FIN_VALUE_ADDRESS                (0x400a2058UL)
#define PDSS_VBTR_SRC_INIT_FIN_VALUE                        (*(volatile uint32_t *)(0x400a2058UL))
#define PDSS_VBTR_SRC_INIT_FIN_VALUE_DEFAULT                (0x00000000UL)

/*
 * Indicates the Initial SRC Register value to be loaded into VBTR_SRC_SNK_OPR_VALUE
 * Register.
 */
#define PDSS_VBTR_SRC_INIT_FIN_VALUE_SRC_INIT_MASK          (0x0000007fUL) /* <0:6> R:RW:0: */
#define PDSS_VBTR_SRC_INIT_FIN_VALUE_SRC_INIT_POS           (0UL)


/*
 * Indicates the Final SRC Register value to be reached after operation completion.
 */
#define PDSS_VBTR_SRC_INIT_FIN_VALUE_SRC_FIN_MASK           (0x00007f00UL) /* <8:14> R:RW:0: */
#define PDSS_VBTR_SRC_INIT_FIN_VALUE_SRC_FIN_POS            (8UL)


/*
 * VBUS Transition Sink Initial/Final value registers
 */
#define PDSS_VBTR_SNK_INIT_FIN_VALUE_ADDRESS                (0x400a205cUL)
#define PDSS_VBTR_SNK_INIT_FIN_VALUE                        (*(volatile uint32_t *)(0x400a205cUL))
#define PDSS_VBTR_SNK_INIT_FIN_VALUE_DEFAULT                (0x00000000UL)

/*
 * Indicates the Initial SNK Register value to be loaded into VBTR_SRC_SNK_OPR_VALUE
 * Register.
 */
#define PDSS_VBTR_SNK_INIT_FIN_VALUE_SNK_INIT_MASK          (0x000003ffUL) /* <0:9> R:RW:0: */
#define PDSS_VBTR_SNK_INIT_FIN_VALUE_SNK_INIT_POS           (0UL)


/*
 * Indicates the MSB of Initial SNK Register value to be loaded into VBTR_SRC_SNK_OPR_VALUE
 * Register. This is applicable only in EPR
 */
#define PDSS_VBTR_SNK_INIT_FIN_VALUE_SNK_INIT_EPR           (1UL << 10) /* <10:10> R:RW:0:EPR_EN */


/*
 * Indicates the Final SNK Register value to be reached after operation completion.
 */
#define PDSS_VBTR_SNK_INIT_FIN_VALUE_SNK_FIN_MASK           (0x03ff0000UL) /* <16:25> R:RW:0: */
#define PDSS_VBTR_SNK_INIT_FIN_VALUE_SNK_FIN_POS            (16UL)


/*
 * Indicates the MSB of Final SNK Register value to be reached after operation
 * completion. This is applicable only in EPR.
 */
#define PDSS_VBTR_SNK_INIT_FIN_VALUE_SNK_FIN_EPR            (1UL << 26) /* <26:26> R:RW:0:EPR_EN */


/*
 * VBUS Transition Status registers
 */
#define PDSS_VBTR_STATUS_ADDRESS                            (0x400a2060UL)
#define PDSS_VBTR_STATUS                                    (*(volatile uint32_t *)(0x400a2060UL))
#define PDSS_VBTR_STATUS_DEFAULT                            (0x00000000UL)

/*
 * Status of Source vbus transition completion
 */
#define PDSS_VBTR_STATUS_SRC_DONE                           (1UL << 0) /* <0:0> RW:R:0: */


/*
 * Status of Sink vbus transition completion
 */
#define PDSS_VBTR_STATUS_SNK_DONE                           (1UL << 1) /* <1:1> RW:R:0: */


/*
 * Power Adapter Secondary Controller (PASC) Configuration Registers
 */
#define PDSS_PASC_CTRL_ADDRESS                              (0x400a2064UL)
#define PDSS_PASC_CTRL                                      (*(volatile uint32_t *)(0x400a2064UL))
#define PDSS_PASC_CTRL_DEFAULT                              (0x0000c144UL)

/*
 * Indicates Configuration of PASC.
 * 0 - PWM
 * 1 - SR_ONLY
 */
#define PDSS_PASC_CTRL_PASC_CFG                             (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Indicates operational mode of PASC. This register hasa shadow register
 * in logic
 * 00 - Fixed Frequency (FF)
 * 01 - Psuedo Fixed Frequency (PFF)
 * 10 - QR-Valley Mode (QR)
 */
#define PDSS_PASC_CTRL_PASC_MODE_MASK                       (0x00000006UL) /* <1:2> R:RW:2: */
#define PDSS_PASC_CTRL_PASC_MODE_POS                        (1UL)


/*
 * Indicates Dynamic Switching
 * 00 - No dynamic swicthing
 * 01 - FF <-> PFF
 * 10 - FF <-> QR
 */
#define PDSS_PASC_CTRL_PASC_DS_MASK                         (0x00000018UL) /* <3:4> R:RW:0: */
#define PDSS_PASC_CTRL_PASC_DS_POS                          (3UL)


/*
 * Indicates the width of PTDRV pulses during calibration.
 * Minimum value that can be programmed is 0x3
 */
#define PDSS_PASC_CTRL_CAL_WIDTH_MASK                       (0x000003e0UL) /* <5:9> R:RW:10: */
#define PDSS_PASC_CTRL_CAL_WIDTH_POS                        (5UL)


/*
 * Indicates the sepeartion time between consecutive calibration pulses.
 * Minimum value that can be programmed 0x5
 */
#define PDSS_PASC_CTRL_CAL_SEPARATION_MASK                  (0x0003fc00UL) /* <10:17> R:RW:48: */
#define PDSS_PASC_CTRL_CAL_SEPARATION_POS                   (10UL)


/*
 * Control bit for PWM out signal.
 * 0 - Logic uses Hard-Ip generated signal
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_PASC_CTRL_SEL_EXT_PWM_OUT                      (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Control bit for ZCD out signal.
 * 0 - Logic uses Hard-Ip generated signal
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_PASC_CTRL_SEL_EXT_ZCD_OUT                      (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Control bit for NSN out signal.
 * 0 - Logic uses Hard-Ip generated signal
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_PASC_CTRL_SEL_EXT_NSN_OUT                      (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Control bit for PEAKDET out signal.
 * 0 - Logic uses Hard-Ip generated signal
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_PASC_CTRL_SEL_EXT_PEAKDET_OUT                  (1UL << 21) /* <21:21> R:RW:0: */


/*
 * Bit22: Disable nsn idle timeout check.
 * Bit23:
 * Bit30:24: Un-used
 */
#define PDSS_PASC_CTRL_PASC_SPARE_MASK                      (0x7fc00000UL) /* <22:30> R:RW:0: */
#define PDSS_PASC_CTRL_PASC_SPARE_POS                       (22UL)


/*
 * FW should set this bit to turn on the secondary controller power state
 * machine.
 * On deasserting this bit, the PASC block must be reset by toggling DEBUG_CTRL.RESET_PASC
 * to reset the FSM.
 */
#define PDSS_PASC_CTRL_PA_EN                                (1UL << 31) /* <31:31> R:RW:0: */


/*
 * SR GDRV Control Register 0
 */
#define PDSS_SRGDRV_0_CTRL_ADDRESS                          (0x400a2068UL)
#define PDSS_SRGDRV_0_CTRL                                  (*(volatile uint32_t *)(0x400a2068UL))
#define PDSS_SRGDRV_0_CTRL_DEFAULT                          (0x0c980000UL)

/*
 * Controls the assertion delay of "gdrv_in" signal
 */
#define PDSS_SRGDRV_0_CTRL_GDRV_IN_ON_DLY_MASK              (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_SRGDRV_0_CTRL_GDRV_IN_ON_DLY_POS               (0UL)


/*
 * Controls the de-assertion delay of "gdrv_in" signal
 */
#define PDSS_SRGDRV_0_CTRL_GDRV_IN_OFF_DLY_MASK             (0x00000fc0UL) /* <6:11> R:RW:0: */
#define PDSS_SRGDRV_0_CTRL_GDRV_IN_OFF_DLY_POS              (6UL)


/*
 * Control bit for signal "gdrv_in"
 * 0: Logic output is propagated as "gdrv_in".
 * 1: External GPIO input is propagated as "gdrv_in"
 */
#define PDSS_SRGDRV_0_CTRL_GDRV_IN_OUT_CTRL                 (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Override Register.
 * 1 - FW Override Enabled. GDRV_IN_OVR_VAL is driven on secondary gate driver
 */
#define PDSS_SRGDRV_0_CTRL_GDRV_IN_OVR                      (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Override Value for "gdrv_in" Signal
 */
#define PDSS_SRGDRV_0_CTRL_GDRV_IN_OVR_VAL                  (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this override will prevent turn-off width check
 */
#define PDSS_SRGDRV_0_CTRL_GDRV_TURN_OFF_OVERRIDE           (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Secondary SR gate turn-on pulse-Width below which GDRV will be turned-off
 * in next cycle. The secondary width is measured as the time from NSN triggering
 * to ZCD or ZCDF  (whichever comes earlier) triggering. This register has
 * a shadow register in Logic
 */
#define PDSS_SRGDRV_0_CTRL_GDRV_IN_TURN_OFF_WIDTH_MASK      (0x007f0000UL) /* <16:22> R:RW:24: */
#define PDSS_SRGDRV_0_CTRL_GDRV_IN_TURN_OFF_WIDTH_POS       (16UL)


/*
 * 0: When minimum width is violated GDRV is shut-off and only turned back
 * on when the INTR8.13 is cleared
 * 1: GDRV is only turned off for the current power cycle
 */
#define PDSS_SRGDRV_0_CTRL_GDRV_GATE_EVERY_CYCLE            (1UL << 23) /* <23:23> R:RW:1: */


/*
 * Delay from gdrv max time out to nsn enable in SR-Mode only
 */
#define PDSS_SRGDRV_0_CTRL_GDRV_TMR_FOR_NSN_DLY_MASK        (0x7f000000UL) /* <24:30> R:RW:12: */
#define PDSS_SRGDRV_0_CTRL_GDRV_TMR_FOR_NSN_DLY_POS         (24UL)


/*
 * SR GDRV Control Register 1
 */
#define PDSS_SRGDRV_1_CTRL_ADDRESS                          (0x400a206cUL)
#define PDSS_SRGDRV_1_CTRL                                  (*(volatile uint32_t *)(0x400a206cUL))
#define PDSS_SRGDRV_1_CTRL_DEFAULT                          (0x00009c05UL)

/*
 * Minimum Pulse Width of "gdrv_in". This register has a shadow register
 * in Logic
 */
#define PDSS_SRGDRV_1_CTRL_GDRV_IN_MIN_WIDTH_MASK           (0x0000003fUL) /* <0:5> R:RW:5: */
#define PDSS_SRGDRV_1_CTRL_GDRV_IN_MIN_WIDTH_POS            (0UL)


/*
 * Maximum Pulse Width of "gdrv_in"
 */
#define PDSS_SRGDRV_1_CTRL_GDRV_IN_MAX_WIDTH_MASK           (0x0001ffc0UL) /* <6:16> R:RW:624: */
#define PDSS_SRGDRV_1_CTRL_GDRV_IN_MAX_WIDTH_POS            (6UL)


/*
 * Width of "gdrv_in" signal in the latest power cycle
 */
#define PDSS_SRGDRV_1_CTRL_GDRV_IN_STATUS_UPD_MASK          (0x0ffe0000UL) /* <17:27> RW:R:0: */
#define PDSS_SRGDRV_1_CTRL_GDRV_IN_STATUS_UPD_POS           (17UL)


/*
 * MSB of Width of "gdrv_in" signal in the latest power cycle along with
 * GDRV_IN_STATUS_UPD
 */
#define PDSS_SRGDRV_1_CTRL_GDRV_IN_STATUS_UPD_MSB           (1UL << 28) /* <28:28> RW:R:0:PASC2_EN */


/*
 * MSB of Maximum Pulse Width of "gdrv_in" along with GDRV_IN_MAX_WIDTH
 */
#define PDSS_SRGDRV_1_CTRL_GDRV_IN_MAX_WIDTH_MSB            (1UL << 29) /* <29:29> R:RW:0:PASC2_EN */


/*
 * PASC-PWM Control Register 0
 */
#define PDSS_PASC_PWM_0_CTRL_ADDRESS                        (0x400a2070UL)
#define PDSS_PASC_PWM_0_CTRL                                (*(volatile uint32_t *)(0x400a2070UL))
#define PDSS_PASC_PWM_0_CTRL_DEFAULT                        (0x0c000000UL)

/*
 * Controls the assertion delay of "ptdrv_in" signal
 */
#define PDSS_PASC_PWM_0_CTRL_PTDRV_IN_ON_DLY_MASK           (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_PASC_PWM_0_CTRL_PTDRV_IN_ON_DLY_POS            (0UL)


/*
 * Controls the de-assertion delay of "ptdrv_in" signal
 */
#define PDSS_PASC_PWM_0_CTRL_PTDRV_IN_OFF_DLY_MASK          (0x00000fc0UL) /* <6:11> R:RW:0: */
#define PDSS_PASC_PWM_0_CTRL_PTDRV_IN_OFF_DLY_POS           (6UL)


/*
 * Setting this bit will gate the PTDRV on the negative edge of primary pulse.
 * FW can use this bit to smoothly transition control from logic. After setting
 * this bit, FW has to read the PTDRV GPIO to check if low. Then take control
 * of the GPIO
 */
#define PDSS_PASC_PWM_0_CTRL_PTDRV_GATE_FW                  (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Minimum Pulse width of "ptdrv_in" signal. This register has a shadow register
 * in logic.
 */
#define PDSS_PASC_PWM_0_CTRL_PTDRV_IN_MIN_WIDTH_MASK        (0x7f000000UL) /* <24:30> R:RW:12: */
#define PDSS_PASC_PWM_0_CTRL_PTDRV_IN_MIN_WIDTH_POS         (24UL)


/*
 * Control bit for signal "ptdrv_in"
 * 0 - Logic output is propagated as "ptdrv_in".
 * 1 - External GPIO input is propagated as "ptdrv_in"
 */
#define PDSS_PASC_PWM_0_CTRL_PTDRV_IN_OUT_CTRL              (1UL << 31) /* <31:31> R:RW:0: */


/*
 * PASC-PWM Control Register 1
 */
#define PDSS_PASC_PWM_1_CTRL_ADDRESS                        (0x400a2074UL)
#define PDSS_PASC_PWM_1_CTRL                                (*(volatile uint32_t *)(0x400a2074UL))
#define PDSS_PASC_PWM_1_CTRL_DEFAULT                        (0x000002a0UL)

/*
 * Maximum Pulse width of "ptdrv_in" signal. This register has a shadow register
 * in logic
 */
#define PDSS_PASC_PWM_1_CTRL_PTDRV_IN_MAX_WIDTH_MASK        (0x000007ffUL) /* <0:10> R:RW:672: */
#define PDSS_PASC_PWM_1_CTRL_PTDRV_IN_MAX_WIDTH_POS         (0UL)


/*
 * Width of "ptdrv_in" signal in the latest power cycle
 */
#define PDSS_PASC_PWM_1_CTRL_PTDRV_IN_STATUS_UPD_MASK       (0x003ff800UL) /* <11:21> RW:R:0: */
#define PDSS_PASC_PWM_1_CTRL_PTDRV_IN_STATUS_UPD_POS        (11UL)


/*
 * PASC-PWM Control Register 2
 */
#define PDSS_PASC_PWM_2_CTRL_ADDRESS                        (0x400a2078UL)
#define PDSS_PASC_PWM_2_CTRL                                (*(volatile uint32_t *)(0x400a2078UL))
#define PDSS_PASC_PWM_2_CTRL_DEFAULT                        (0x08080018UL)

/*
 * If this bit is set, srgdrv is gated when primary is doing the burst pulses.
 */
#define PDSS_PASC_PWM_2_CTRL_GATE_SRGDRV_BURST_EN           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Minimum pulse width of burst pulse.
 */
#define PDSS_PASC_PWM_2_CTRL_BURST_MIN_WIDTH_MASK           (0x000000feUL) /* <1:7> R:RW:12: */
#define PDSS_PASC_PWM_2_CTRL_BURST_MIN_WIDTH_POS            (1UL)


/*
 * Burst pulse width incremental delta value
 */
#define PDSS_PASC_PWM_2_CTRL_BURST_INCR_VAL_MASK            (0x00f80000UL) /* <19:23> R:RW:1: */
#define PDSS_PASC_PWM_2_CTRL_BURST_INCR_VAL_POS             (19UL)


/*
 * 1 - if burst exit happens when in audio range, move to normal mode
 */
#define PDSS_PASC_PWM_2_CTRL_ALLOW_BURST_EXIT_IN_AUDIO      (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Change_pwm - setting this bit will update the shadow registers for the
 * following when PTDRV is low
 * a. PWM_BURST_EXIT_SEL
 * b. PWM_DAC
 * c. PWM_LCLAMP_SEL
 * d. BURST_MIN_WIDTH
 * e. BURST_TRIM_VAL
 * f. SKIP_TRIM_VAL
 */
#define PDSS_PASC_PWM_2_CTRL_CHANGE_PWM                     (1UL << 25) /* <25:25> RW1C:RW1S:0: */


/*
 * Setting this bit will update the shadow registers on DOUBLER_BYPASS at
 * GDRV negative edge.
 */
#define PDSS_PASC_PWM_2_CTRL_DOUBLER_BYPASS_CHANGE          (1UL << 26) /* <26:26> RW1C:RW1S:0: */


/*
 * 1 - if Skip exit happens when in audio range, move to Burst mode
 */
#define PDSS_PASC_PWM_2_CTRL_ALLOW_SKIP_EXIT_IN_AUDIO       (1UL << 27) /* <27:27> R:RW:1:PASC2_EN */


/*
 * PASC-MODE Control Register 0
 */
#define PDSS_MODE_0_CTRL_ADDRESS                            (0x400a207cUL)
#define PDSS_MODE_0_CTRL                                    (*(volatile uint32_t *)(0x400a207cUL))
#define PDSS_MODE_0_CTRL_DEFAULT                            (0x00000000UL)

/*
 * Controls the assertion delay of "pwm_reset" signal
 */
#define PDSS_MODE_0_CTRL_PWM_RESET_ON_DLY_MASK              (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_MODE_0_CTRL_PWM_RESET_ON_DLY_POS               (0UL)


/*
 * Controls the de-assertion delay of "pwm_reset" signal
 */
#define PDSS_MODE_0_CTRL_PWM_RESET_OFF_DLY_MASK             (0x00000fc0UL) /* <6:11> R:RW:0: */
#define PDSS_MODE_0_CTRL_PWM_RESET_OFF_DLY_POS              (6UL)


/*
 * Clear the PWM Cap Dithering offset
 */
#define PDSS_MODE_0_CTRL_PWM_CAP_DITH_OFFSET_CLR            (1UL << 18) /* <18:18> RW1C:RW1S:0:PASC2_EN */


/*
 * Clear the FF Dithering offset
 */
#define PDSS_MODE_0_CTRL_FF_DITH_OFFSET_CLR                 (1UL << 19) /* <19:19> RW1C:RW1S:0:PASC2_EN */


/*
 * Enables PWM CAP Modulation, dithering
 */
#define PDSS_MODE_0_CTRL_PWM_CAP_UPD_EN                     (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Firmware update set for "pwm_cap". Firmware can use this to set the PWM
 * cap value dynamically. When set, the value in PWM_CAP_FW_UPD_VAL is used
 * for the next cycle.
 */
#define PDSS_MODE_0_CTRL_PWM_CAP_FW_UPD                     (1UL << 21) /* <21:21> RW1C:RW1S:0: */


/*
 * This register is used during trimming to create a pwm_reset deassertion.
 * This will be used to measure the PWM pulse width
 */
#define PDSS_MODE_0_CTRL_PWM_RESET_FW                       (1UL << 27) /* <27:27> RW1C:RW1S:0: */


/*
 * Enables the frequency dithering in FF and PFF modes.
 */
#define PDSS_MODE_0_CTRL_FF_SPREAD_EN                       (1UL << 28) /* <28:28> R:RW:0: */


/*
 * Increment value used in Frequency dithering.
 */
#define PDSS_MODE_0_CTRL_FF_SPREAD_INC_MASK                 (0xe0000000UL) /* <29:31> R:RW:0: */
#define PDSS_MODE_0_CTRL_FF_SPREAD_INC_POS                  (29UL)


/*
 * PASC-MODE Control Register 1
 */
#define PDSS_MODE_1_CTRL_ADDRESS                            (0x400a2080UL)
#define PDSS_MODE_1_CTRL                                    (*(volatile uint32_t *)(0x400a2080UL))
#define PDSS_MODE_1_CTRL_DEFAULT                            (0x803060f0UL)

/*
 * Fixed Frequency Value. This register has a shadow in logic
 */
#define PDSS_MODE_1_CTRL_FIX_FREQ_MASK                      (0x000007ffUL) /* <0:10> R:RW:240: */
#define PDSS_MODE_1_CTRL_FIX_FREQ_POS                       (0UL)


/*
 * Fixed Frequency Offset Value
 */
#define PDSS_MODE_1_CTRL_FIX_FREQ_OFFSET_MASK               (0x0001f800UL) /* <11:16> R:RW:12: */
#define PDSS_MODE_1_CTRL_FIX_FREQ_OFFSET_POS                (11UL)


/*
 * QR mode dithering range using CAP (~0.4% per bit)
 */
#define PDSS_MODE_1_CTRL_PWM_DITH_CAP_RANGE_MASK            (0x00fe0000UL) /* <17:23> R:RW:24:PASC2_EN */
#define PDSS_MODE_1_CTRL_PWM_DITH_CAP_RANGE_POS             (17UL)


/*
 * Sets the mid-value of dithering cap
 */
#define PDSS_MODE_1_CTRL_PWM_DITH_CAP_VAL_MASK              (0xff000000UL) /* <24:31> R:RW:128:PASC2_EN */
#define PDSS_MODE_1_CTRL_PWM_DITH_CAP_VAL_POS               (24UL)


/*
 * PASC-MODE Control Register 2
 */
#define PDSS_MODE_2_CTRL_ADDRESS                            (0x400a2084UL)
#define PDSS_MODE_2_CTRL                                    (*(volatile uint32_t *)(0x400a2084UL))
#define PDSS_MODE_2_CTRL_DEFAULT                            (0x401e10a0UL)

/*
 * This field set the max frequency possible in QR mode of operation. This
 * register has a shadow in logic
 */
#define PDSS_MODE_2_CTRL_VAR_TMIN_MASK                      (0x000007ffUL) /* <0:10> R:RW:160: */
#define PDSS_MODE_2_CTRL_VAR_TMIN_POS                       (0UL)


/*
 * This field set the min frequency possible in QR mode of operation. This
 * register has a shadow in logic
 */
#define PDSS_MODE_2_CTRL_VAR_TMAX_MASK                      (0x007ff800UL) /* <11:22> R:RW:962: */
#define PDSS_MODE_2_CTRL_VAR_TMAX_POS                       (11UL)


/*
 * QR mode dithering step using CAP (~0.4% per bit)
 */
#define PDSS_MODE_2_CTRL_PWM_DITH_CAP_STEP_MASK             (0xe0000000UL) /* <29:31> R:RW:2:PASC2_EN */
#define PDSS_MODE_2_CTRL_PWM_DITH_CAP_STEP_POS              (29UL)


/*
 * PASC-MODE Control Register 3
 */
#define PDSS_MODE_3_CTRL_ADDRESS                            (0x400a2088UL)
#define PDSS_MODE_3_CTRL                                    (*(volatile uint32_t *)(0x400a2088UL))
#define PDSS_MODE_3_CTRL_DEFAULT                            (0x19005dc0UL)

/*
 * This register defines the min frequency of audio range.
 */
#define PDSS_MODE_3_CTRL_AUDIO_TMAX_MASK                    (0x001fffffUL) /* <0:20> R:RW:24000: */
#define PDSS_MODE_3_CTRL_AUDIO_TMAX_POS                     (0UL)


/*
 * FF mode dithering range
 */
#define PDSS_MODE_3_CTRL_PWM_DITH_FF_RANGE_MASK             (0xff000000UL) /* <24:31> R:RW:25:PASC2_EN */
#define PDSS_MODE_3_CTRL_PWM_DITH_FF_RANGE_POS              (24UL)


/*
 * PASC-MODE Control Register 4
 */
#define PDSS_MODE_4_CTRL_ADDRESS                            (0x400a208cUL)
#define PDSS_MODE_4_CTRL                                    (*(volatile uint32_t *)(0x400a208cUL))
#define PDSS_MODE_4_CTRL_DEFAULT                            (0x001904c3UL)

/*
 * This register defines the max frequency of audio range (default 20kHZ)
 */
#define PDSS_MODE_4_CTRL_AUDIO_TMIN_MASK                    (0x00001fffUL) /* <0:12> R:RW:1219: */
#define PDSS_MODE_4_CTRL_AUDIO_TMIN_POS                     (0UL)


/*
 * Time for which dithering remains at same step ; Uses 1MHz clk cycle
 */
#define PDSS_MODE_4_CTRL_PWM_DITH_RPT_MASK                  (0x00ffc000UL) /* <14:23> R:RW:100:PASC2_EN */
#define PDSS_MODE_4_CTRL_PWM_DITH_RPT_POS                   (14UL)


/*
 * PEAK Generator Control Register 0
 */
#define PDSS_PEAKGEN_0_CTRL_ADDRESS                         (0x400a2090UL)
#define PDSS_PEAKGEN_0_CTRL                                 (*(volatile uint32_t *)(0x400a2090UL))
#define PDSS_PEAKGEN_0_CTRL_DEFAULT                         (0x00009000UL)

/*
 * Controls the "peak to peak" delay. This register has a shadow in logic.
 */
#define PDSS_PEAKGEN_0_CTRL_PEAK2PEAK_DLY_MASK              (0x0003fe00UL) /* <9:17> R:RW:72: */
#define PDSS_PEAKGEN_0_CTRL_PEAK2PEAK_DLY_POS               (9UL)


/*
 * Setting this bit ignores the peaks from Hard-IP and uses only digital
 * computation
 */
#define PDSS_PEAKGEN_0_CTRL_PEAK_OVR                        (1UL << 26) /* <26:26> R:RW:0: */


/*
 * This bit must be set before PA_EN is set to prevent calibration from happening.
 * When set, there will be 1 start pulse instead of 2
 */
#define PDSS_PEAKGEN_0_CTRL_CALIBRATE_OVERRIDE              (1UL << 27) /* <27:27> R:RW:0: */


/*
 * PEAK Generator Control Register 1
 */
#define PDSS_PEAKGEN_1_CTRL_ADDRESS                         (0x400a2094UL)
#define PDSS_PEAKGEN_1_CTRL                                 (*(volatile uint32_t *)(0x400a2094UL))
#define PDSS_PEAKGEN_1_CTRL_DEFAULT                         (0x0541209aUL)

/*
 * Enables the use of updating the trim values for SKIP.
 * 1 - Skip Trim Update is enabled.
 */
#define PDSS_PEAKGEN_1_CTRL_SKIP_TRIM_EN                    (1UL << 1) /* <1:1> R:RW:1: */


/*
 * Indicates the value to be used for SKIP TRIM bits once "skip_out" is encountered.
 */
#define PDSS_PEAKGEN_1_CTRL_BURST_TRIM_VAL_MASK             (0x0000003cUL) /* <2:5> R:RW:6: */
#define PDSS_PEAKGEN_1_CTRL_BURST_TRIM_VAL_POS              (2UL)


/*
 * Indicates the value of SKIP TRIM bits before "skip_out" and after "burst_exit"
 * is encountered.
 */
#define PDSS_PEAKGEN_1_CTRL_SKIP_TRIM_VAL_MASK              (0x000003c0UL) /* <6:9> R:RW:2: */
#define PDSS_PEAKGEN_1_CTRL_SKIP_TRIM_VAL_POS               (6UL)


/*
 * Indicates the time between "zcd_out" encountered to the first peak. This
 * is used if full digital scheme of peak generation is used. This register
 * has a shadow in logic
 */
#define PDSS_PEAKGEN_1_CTRL_ZCD_TO_PEAK_TIME_MASK           (0x000ff800UL) /* <11:19> R:RW:36: */
#define PDSS_PEAKGEN_1_CTRL_ZCD_TO_PEAK_TIME_POS            (11UL)


/*
 * Indicates the maximum time (expected) between two consecutive peaks. If
 * this timer times out, digital peak generation will take over.
 */
#define PDSS_PEAKGEN_1_CTRL_PEAK_EXPECT_DLY_MASK            (0x1ff00000UL) /* <20:28> R:RW:84: */
#define PDSS_PEAKGEN_1_CTRL_PEAK_EXPECT_DLY_POS             (20UL)


/*
 * PEAK Generator Control Register 2
 */
#define PDSS_PEAKGEN_2_CTRL_ADDRESS                         (0x400a2098UL)
#define PDSS_PEAKGEN_2_CTRL                                 (*(volatile uint32_t *)(0x400a2098UL))
#define PDSS_PEAKGEN_2_CTRL_DEFAULT                         (0x0011e01fUL)

/*
 * Setting this bit will ignore Hard IP generated peaks after the programmed
 * number of STOP_PEAK
 */
#define PDSS_PEAKGEN_2_CTRL_STOP_HIP_ON_NTH_PEAK            (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Peak at which Hard IP output is ignored. Programmed peak + 1 is used.
 */
#define PDSS_PEAKGEN_2_CTRL_STOP_PEAK_MASK                  (0x0000007eUL) /* <1:6> R:RW:15: */
#define PDSS_PEAKGEN_2_CTRL_STOP_PEAK_POS                   (1UL)


/*
 * MSB 2 bits of Peak at which Hard IP output is ignored. Programmed peak
 * + 1 is used.
 */
#define PDSS_PEAKGEN_2_CTRL_STOP_PEAK_EXT_MASK              (0x00000180UL) /* <7:8> R:RW:0:PASC2_EN */
#define PDSS_PEAKGEN_2_CTRL_STOP_PEAK_EXT_POS               (7UL)


/*
 * Indicates the time between "zcdf_out" encountered to the first Valley.
 * This is used if full digital scheme of valley generation is used. This
 * register has a shadow in logic
 */
#define PDSS_PEAKGEN_2_CTRL_ZCD_TO_VALLEY_TIME_MASK         (0x000ff800UL) /* <11:19> R:RW:60:PASC2_EN */
#define PDSS_PEAKGEN_2_CTRL_ZCD_TO_VALLEY_TIME_POS          (11UL)


/*
 * When set, the Calibration cycle will measure 4 consecutive peak-to-peak
 * delay from 2nd peak and get the average value to peak-topeak delay (Tpkpk)
 */
#define PDSS_PEAKGEN_2_CTRL_CAL_SKIP_FIRST_PEAK             (1UL << 20) /* <20:20> R:RW:1:PASC2_EN */


/*
 * Feed Forward Control Register
 */
#define PDSS_FEEDFWD_CTRL_ADDRESS                           (0x400a209cUL)
#define PDSS_FEEDFWD_CTRL                                   (*(volatile uint32_t *)(0x400a209cUL))
#define PDSS_FEEDFWD_CTRL_DEFAULT                           (0x040c0000UL)

/*
 * Control bit for signal "feedfwd_sw_en" signal
 * 0 - Logic output is propagated as "feedfwd_sw_en".
 * 1 - External GPIO input is propagated as "feedfwd_sw_en"
 */
#define PDSS_FEEDFWD_CTRL_FEEDFWD_SW_EN_OUT_CTRL            (1UL << 1) /* <1:1> R:RW:0: */


/*
 * FW Override bit for "feedfwd_sw_en"
 */
#define PDSS_FEEDFWD_CTRL_FEEDFWD_SW_EN_OVR                 (1UL << 2) /* <2:2> R:RW:0: */


/*
 * FW Override value for "feedfwd_sw_en"
 */
#define PDSS_FEEDFWD_CTRL_FEEDFWD_SW_EN_OVR_VAL             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Controls the width of "feedfwd_sw_en" signal.
 */
#define PDSS_FEEDFWD_CTRL_FEEDFWD_PRE_SW_EN_WIDTH_MASK      (0x01fc0000UL) /* <18:24> R:RW:3: */
#define PDSS_FEEDFWD_CTRL_FEEDFWD_PRE_SW_EN_WIDTH_POS       (18UL)


/*
 * PAG1S: Controls the assertion delay of "feedfwd_sw_en" signal after the
 * assertion of "feedfwd_pre_sw_en" signal.
 * PAG2S: Controls the assertion delay of "feedfwd_sw_en" signal
 */
#define PDSS_FEEDFWD_CTRL_FEEDFWD_SW_EN_ON_DLY_MASK         (0x7e000000UL) /* <25:30> R:RW:2: */
#define PDSS_FEEDFWD_CTRL_FEEDFWD_SW_EN_ON_DLY_POS          (25UL)


/*
 * Disables Feedforward width calculation. Feedforward is disabled on PTDRV
 * negedge only
 */
#define PDSS_FEEDFWD_CTRL_FEEDFWD_NO_FEEDFWD_DEASSERT_ON_WIDTH    (1UL << 31) /* <31:31> R:RW:0: */


/*
 * PASC Hard-Ip Sequence Generator Control Register 0
 */
#define PDSS_HIP_SEQ_GEN_0_CTRL_ADDRESS                     (0x400a20a0UL)
#define PDSS_HIP_SEQ_GEN_0_CTRL                             (*(volatile uint32_t *)(0x400a20a0UL))
#define PDSS_HIP_SEQ_GEN_0_CTRL_DEFAULT                     (0x00060000UL)

/*
 * Controls assertion delay of "nsn_en" signal
 */
#define PDSS_HIP_SEQ_GEN_0_CTRL_NSN_EN_ON_DLY_MASK          (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_HIP_SEQ_GEN_0_CTRL_NSN_EN_ON_DLY_POS           (0UL)


/*
 * Controls assertion delay of "zcd_en" signal
 */
#define PDSS_HIP_SEQ_GEN_0_CTRL_ZCD_EN_ON_DLY_MASK          (0x003fc000UL) /* <14:21> R:RW:24: */
#define PDSS_HIP_SEQ_GEN_0_CTRL_ZCD_EN_ON_DLY_POS           (14UL)


/*
 * Override Register for "nsn_en" signal
 */
#define PDSS_HIP_SEQ_GEN_0_CTRL_NSN_EN_OVR                  (1UL << 28) /* <28:28> R:RW:0: */


/*
 * Override value for "nsn_en" signal
 */
#define PDSS_HIP_SEQ_GEN_0_CTRL_NSN_EN_OVR_VAL              (1UL << 29) /* <29:29> R:RW:0: */


/*
 * Override Register for "zcd_en" signal
 */
#define PDSS_HIP_SEQ_GEN_0_CTRL_ZCD_EN_OVR                  (1UL << 30) /* <30:30> R:RW:0: */


/*
 * Override value for "zcd_en" signal
 */
#define PDSS_HIP_SEQ_GEN_0_CTRL_ZCD_EN_OVR_VAL              (1UL << 31) /* <31:31> R:RW:0: */


/*
 * PASC Hard-Ip Sequence Generator Control Register 1
 */
#define PDSS_HIP_SEQ_GEN_1_CTRL_ADDRESS                     (0x400a20a4UL)
#define PDSS_HIP_SEQ_GEN_1_CTRL                             (*(volatile uint32_t *)(0x400a20a4UL))
#define PDSS_HIP_SEQ_GEN_1_CTRL_DEFAULT                     (0x00000005UL)

/*
 * Controls assertion delay of "zcdf_en" signal
 */
#define PDSS_HIP_SEQ_GEN_1_CTRL_ZCDF_EN_ON_DLY_MASK         (0x000000ffUL) /* <0:7> R:RW:5: */
#define PDSS_HIP_SEQ_GEN_1_CTRL_ZCDF_EN_ON_DLY_POS          (0UL)


/*
 * Override Register for "zcdf_en" signal
 */
#define PDSS_HIP_SEQ_GEN_1_CTRL_ZCDF_EN_OVR                 (1UL << 26) /* <26:26> R:RW:0: */


/*
 * Override value for "zcdf_en" signal
 */
#define PDSS_HIP_SEQ_GEN_1_CTRL_ZCDF_EN_OVR_VAL             (1UL << 27) /* <27:27> R:RW:0: */


/*
 * Controls the use of either "zcd_out" or "zcdf" for the assertion of "peakdet_sw_en".
 * 0 - use zcdf
 * 1 - use zcd_out or zcdf_out
 */
#define PDSS_HIP_SEQ_GEN_1_CTRL_ZCD_OUT_FOR_PEAK            (1UL << 30) /* <30:30> R:RW:0: */


/*
 * PASC Hard-Ip Sequence Generator Control Register 2
 */
#define PDSS_HIP_SEQ_GEN_2_CTRL_ADDRESS                     (0x400a20a8UL)
#define PDSS_HIP_SEQ_GEN_2_CTRL                             (*(volatile uint32_t *)(0x400a20a8UL))
#define PDSS_HIP_SEQ_GEN_2_CTRL_DEFAULT                     (0x0006000aUL)

/*
 * Controls assertion delay of "peakdet_en" signal
 */
#define PDSS_HIP_SEQ_GEN_2_CTRL_PEAKDET_EN_ON_DLY_MASK      (0x0000003fUL) /* <0:5> R:RW:10: */
#define PDSS_HIP_SEQ_GEN_2_CTRL_PEAKDET_EN_ON_DLY_POS       (0UL)


/*
 * Override Register for "peakdet_en" signal
 */
#define PDSS_HIP_SEQ_GEN_2_CTRL_PEAKDET_EN_OVR              (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Override value for "peakdet_en" signal
 */
#define PDSS_HIP_SEQ_GEN_2_CTRL_PEAKDET_EN_OVR_VAL          (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Override Register for HIP SEQ GEN State
 */
#define PDSS_HIP_SEQ_GEN_2_CTRL_STATE_OVR                   (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Override Value for HIP SEQ GEN State
 */
#define PDSS_HIP_SEQ_GEN_2_CTRL_STATE_OVR_VAL_MASK          (0x00000e00UL) /* <9:11> R:RW:0: */
#define PDSS_HIP_SEQ_GEN_2_CTRL_STATE_OVR_VAL_POS           (9UL)


/*
 * Controls the time duration for which state machine waits for "nsn_out"
 * to arrive.
 */
#define PDSS_HIP_SEQ_GEN_2_CTRL_NSN_IDLE_TIME_MASK          (0x001ff000UL) /* <12:20> R:RW:96: */
#define PDSS_HIP_SEQ_GEN_2_CTRL_NSN_IDLE_TIME_POS           (12UL)


/*
 * Controls the MSB 3 bits of the time duration, along with NSN_IDLE_TIME
 * for which state machine waits for "nsn_out" to arrive.
 */
#define PDSS_HIP_SEQ_GEN_2_CTRL_NSN_IDLE_TIME_EXT_MASK      (0x00e00000UL) /* <21:23> R:RW:0:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_2_CTRL_NSN_IDLE_TIME_EXT_POS       (21UL)


/*
 * When set ZCD is used as ZCDF
 */
#define PDSS_HIP_SEQ_GEN_2_CTRL_USE_ZCDF_AS_ZCD             (1UL << 30) /* <30:30> R:RW:0: */


/*
 * When set ZCDF is used as ZCD
 */
#define PDSS_HIP_SEQ_GEN_2_CTRL_USE_ZCD_AS_ZCDF             (1UL << 31) /* <31:31> R:RW:0: */


/*
 * PASC Status registers 0
 */
#define PDSS_PASC_STATUS_0_ADDRESS                          (0x400a20acUL)
#define PDSS_PASC_STATUS_0                                  (*(volatile uint32_t *)(0x400a20acUL))
#define PDSS_PASC_STATUS_0_DEFAULT                          (0x00000000UL)

/*
 * Indicates the status of current state within Hard-Ip Sequence Generator
 * block.
 */
#define PDSS_PASC_STATUS_0_STATE_STATUS_MASK                (0x00000007UL) /* <0:2> RW:R:0: */
#define PDSS_PASC_STATUS_0_STATE_STATUS_POS                 (0UL)


/*
 * Indicates the Turn around delay measured by RTL during calibration.
 */
#define PDSS_PASC_STATUS_0_TURN_AROUND_DELAY_MASK           (0x00003ff8UL) /* <3:13> RW:R:0: */
#define PDSS_PASC_STATUS_0_TURN_AROUND_DELAY_POS            (3UL)


/*
 * Indicates the calibrated value of ZCD to first peak.
 */
#define PDSS_PASC_STATUS_0_ZCD_TO_PEAK_CAL_VAL_MASK         (0x7fc00000UL) /* <22:30> RW:R:0: */
#define PDSS_PASC_STATUS_0_ZCD_TO_PEAK_CAL_VAL_POS          (22UL)


/*
 * PASC Status registers 1
 */
#define PDSS_PASC_STATUS_1_ADDRESS                          (0x400a20b0UL)
#define PDSS_PASC_STATUS_1                                  (*(volatile uint32_t *)(0x400a20b0UL))
#define PDSS_PASC_STATUS_1_DEFAULT                          (0x00000000UL)

/*
 * Indicates the "pwm_reset" width. (Indirectly indicates the load)
 */
#define PDSS_PASC_STATUS_1_PWM_RESET_WIDTH_MASK             (0x000003ffUL) /* <0:9> RW:R:0: */
#define PDSS_PASC_STATUS_1_PWM_RESET_WIDTH_POS              (0UL)


/*
 * Indicates the "pwm_reset" width for current switching cycle
 */
#define PDSS_PASC_STATUS_1_PWM_PULSE_WIDTH_FOR_PEAK_MASK    (0x001ffc00UL) /* <10:20> RW:R:0: */
#define PDSS_PASC_STATUS_1_PWM_PULSE_WIDTH_FOR_PEAK_POS     (10UL)


/*
 * Indicates the peak value for current switching cycle
 */
#define PDSS_PASC_STATUS_1_CURR_PEAK_MASK                   (0x07e00000UL) /* <21:26> RW:R:0: */
#define PDSS_PASC_STATUS_1_CURR_PEAK_POS                    (21UL)


/*
 * PASC Status registers 2
 */
#define PDSS_PASC_STATUS_2_ADDRESS                          (0x400a20b4UL)
#define PDSS_PASC_STATUS_2                                  (*(volatile uint32_t *)(0x400a20b4UL))
#define PDSS_PASC_STATUS_2_DEFAULT                          (0x00000000UL)

/*
 * Indicates Peak to Peak to Calibration Value 0. Used by Firmware for average
 * calculation.
 */
#define PDSS_PASC_STATUS_2_P2P_CAL_VAL0_MASK                (0x000001ffUL) /* <0:8> RW:R:0: */
#define PDSS_PASC_STATUS_2_P2P_CAL_VAL0_POS                 (0UL)


/*
 * Indicates Peak to Peak to Calibration Value 1. Used by Firmware for average
 * calculation.
 */
#define PDSS_PASC_STATUS_2_P2P_CAL_VAL1_MASK                (0x0003fe00UL) /* <9:17> RW:R:0: */
#define PDSS_PASC_STATUS_2_P2P_CAL_VAL1_POS                 (9UL)


/*
 * Indicates Peak to Peak to Calibration Value 2. Used by Firmware for average
 * calculation.
 */
#define PDSS_PASC_STATUS_2_P2P_CAL_VAL2_MASK                (0x07fc0000UL) /* <18:26> RW:R:0: */
#define PDSS_PASC_STATUS_2_P2P_CAL_VAL2_POS                 (18UL)


/*
 * PASC Status registers 4
 */
#define PDSS_PASC_STATUS_4_ADDRESS                          (0x400a20bcUL)
#define PDSS_PASC_STATUS_4                                  (*(volatile uint32_t *)(0x400a20bcUL))
#define PDSS_PASC_STATUS_4_DEFAULT                          (0x00000000UL)

/*
 * Indicates Peak to Peak to Calibration Value 3. Used by Firmware for average
 * calculation.
 */
#define PDSS_PASC_STATUS_4_P2P_CAL_VAL3_MASK                (0x000001ffUL) /* <0:8> RW:R:0: */
#define PDSS_PASC_STATUS_4_P2P_CAL_VAL3_POS                 (0UL)


/*
 * Indicates the Peak to Reset (peak_reset) Calibration Value 3. Used by
 * Firmware for average calculation.
 */
#define PDSS_PASC_STATUS_4_PEAK_RST_CAL_VAL3_MASK           (0x0003fe00UL) /* <9:17> RW:R:0: */
#define PDSS_PASC_STATUS_4_PEAK_RST_CAL_VAL3_POS            (9UL)


/*
 * PASC DDFT MUX
 */
#define PDSS_PASC_DDFT_MUX_ADDRESS                          (0x400a20c0UL)
#define PDSS_PASC_DDFT_MUX                                  (*(volatile uint32_t *)(0x400a20c0UL))
#define PDSS_PASC_DDFT_MUX_DEFAULT                          (0x00000000UL)

/*
 * 31:28   MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.skip_trim,
 * 27      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.feedfwd_pre_sw_en,
 * 26:22   MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.pwm_cap,
 * 21      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.nsn_en,
 * 20      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.zcd_en,
 * 19      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.zcdf_en,
 * 18      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.peakdet_sw_en,
 * 17      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.peakdet_en,
 * 16      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.peak_reset,
 * 15      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.pwm_reset,
 * 14      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.ptdrv_in,
 * 13      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.feedfwd_sw_en,
 * 12      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.gdrv_in,
 * 11      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.pulse_disable,
 * 10      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.burst_enable,
 * 9       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.intr_fix_freq_timeout_set,
 * 8       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.intr_var_tmin_timeout_set,
 * 7       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.intr_var_tmax_timeout_set,
 * 6       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.intr_aud_tmin_timeout_set,
 * 5       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.intr_aud_tmax_timeout_set,
 * 4       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.gdrv_in_max_width_timeout,
 * 3       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.ptdrv_in_max_width_timeout,
 * 2       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.skip_entry_filt_posedge_sync,
 * 1       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.skip_entry_filt_negedge_sync,
 * 0       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.burst_exit_filt_posedge_sync
 */
#define PDSS_PASC_DDFT_MUX_DDFT0_SEL_MASK                   (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_PASC_DDFT_MUX_DDFT0_SEL_POS                    (0UL)


/*
 * 31:28   MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.skip_trim,
 * 27      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.feedfwd_pre_sw_en,
 * 26:22   MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.pwm_cap,
 * 21      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.nsn_en,
 * 20      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.zcd_en,
 * 19      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.zcdf_en,
 * 18      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.peakdet_sw_en,
 * 17      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.peakdet_en,
 * 16      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.peak_reset,
 * 15      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.pwm_reset,
 * 14      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.ptdrv_in,
 * 13      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.feedfwd_sw_en,
 * 12      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.gdrv_in,
 * 11      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.pulse_disable,
 * 10      MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.burst_enable,
 * 9       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.intr_fix_freq_timeout_set,
 * 8       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.intr_var_tmin_timeout_set,
 * 7       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.intr_var_tmax_timeout_set,
 * 6       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.intr_aud_tmin_timeout_set,
 * 5       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.intr_aud_tmax_timeout_set,
 * 4       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.gdrv_in_max_width_timeout,
 * 3       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.ptdrv_in_max_width_timeout,
 * 2       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.skip_entry_filt_posedge_sync,
 * 1       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.skip_entry_filt_negedge_sync,
 * 0       MXUSBPD_MMIO_INST.y_pasc_en.u_mxusbpd_pasc.burst_exit_filt_posedge_sync
 */
#define PDSS_PASC_DDFT_MUX_DDFT1_SEL_MASK                   (0x00000fc0UL) /* <6:11> R:RW:0: */
#define PDSS_PASC_DDFT_MUX_DDFT1_SEL_POS                    (6UL)


#define PDSS_PASC_DDFT_MUX_DDFT0_SEL_MSB                    (1UL << 12) /* <12:12> R:RW:0: */


#define PDSS_PASC_DDFT_MUX_DDFT1_SEL_MSB                    (1UL << 13) /* <13:13> R:RW:0: */


/*
 * PASC GPIO DDFT Selections
 */
#define PDSS_PASC_GPIO_DDFT_MUX_ADDRESS                     (0x400a20c4UL)
#define PDSS_PASC_GPIO_DDFT_MUX                             (*(volatile uint32_t *)(0x400a20c4UL))
#define PDSS_PASC_GPIO_DDFT_MUX_DEFAULT                     (0x00000000UL)

/*
 * 14 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_nsn_out_change.filt_out_gpio
 * 13 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_zcd_out_change.filt_out_gpio
 * 12 MXUSBPD_MMIO_INST.y_pasc_en.u_pds_vreg_vbus_change.filt_out_gpio
 * 11  MXUSBPD_MMIO_INST.y_pasc_en.u_pds_scp_change.filt_out_gpio
 * 10 MXUSBPD_MMIO_INST.y_pasc_en.u_pwm_skip_out_change.filt_out_gpio
 * 9 MXUSBPD_MMIO_INST.y_pasc_en.u_pwm_burst_exit_out_change.filt_out_gpio
 * 8 MXUSBPD_MMIO_INST.y_pasc_en.u_pwm_out_change.filt_out_gpio
 * 7 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_zcdf_out_change.filt_out_gpio
 * 6 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_ovp_change.filt_out_gpio
 * 5 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_peakdet_out_change.filt_out_gpio
 * 4 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_peakdet_rst_out_change.filt_out_gpio
 * 3 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_peakdet_clcmp_raw_out_change.filt_out_gpio
 * 2 MXUSBPD_MMIO_INST.y_pasc_en.u_ea_cc_flag_change.filt_out_gpio
 * 1  MXUSBPD_MMIO_INST.y_pasc_en.u_ff_ov_change.filt_out_gpio
 * 0 MXUSBPD_MMIO_INST.y_pasc_en.u_ff_uv_change.filt_out_gpio
 */
#define PDSS_PASC_GPIO_DDFT_MUX_GPIO_DDFT0_SEL_MASK         (0x0000007fUL) /* <0:6> R:RW:0: */
#define PDSS_PASC_GPIO_DDFT_MUX_GPIO_DDFT0_SEL_POS          (0UL)


/*
 * 14 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_nsn_out_change.filt_out_gpio
 * 13 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_zcd_out_change.filt_out_gpio
 * 12 MXUSBPD_MMIO_INST.y_pasc_en.u_pds_vreg_vbus_change.filt_out_gpio
 * 11  MXUSBPD_MMIO_INST.y_pasc_en.u_pds_scp_change.filt_out_gpio
 * 10 MXUSBPD_MMIO_INST.y_pasc_en.u_pwm_skip_out_change.filt_out_gpio
 * 9 MXUSBPD_MMIO_INST.y_pasc_en.u_pwm_burst_exit_out_change.filt_out_gpio
 * 8 MXUSBPD_MMIO_INST.y_pasc_en.u_pwm_out_change.filt_out_gpio
 * 7 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_zcdf_out_change.filt_out_gpio
 * 6 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_ovp_change.filt_out_gpio
 * 5 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_peakdet_out_change.filt_out_gpio
 * 4 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_peakdet_rst_out_change.filt_out_gpio
 * 3 MXUSBPD_MMIO_INST.y_pasc_en.u_srsense_peakdet_clcmp_raw_out_change.filt_out_gpio
 * 2 MXUSBPD_MMIO_INST.y_pasc_en.u_ea_cc_flag_change.filt_out_gpio
 * 1  MXUSBPD_MMIO_INST.y_pasc_en.u_ff_ov_change.filt_out_gpio
 * 0 MXUSBPD_MMIO_INST.y_pasc_en.u_ff_uv_change.filt_out_gpio
 */
#define PDSS_PASC_GPIO_DDFT_MUX_GPIO_DDFT1_SEL_MASK         (0x00007f00UL) /* <8:14> R:RW:0: */
#define PDSS_PASC_GPIO_DDFT_MUX_GPIO_DDFT1_SEL_POS          (8UL)


/*
 * IBUS Transition config
 */
#define PDSS_IBTR_CFG_ADDRESS                               (0x400a2250UL)
#define PDSS_IBTR_CFG                                       (*(volatile uint32_t *)(0x400a2250UL))
#define PDSS_IBTR_CFG_DEFAULT                               (0x00000000UL)

/*
 * Enable/Disable IBTR operation
 * 1 - Enable
 * 0 - Disable
 */
#define PDSS_IBTR_CFG_IBTR_EN                               (1UL << 0) /* <0:0> R:RW:0: */


/*
 * IBTR operation type
 * 1 - Increment
 * 0 - Decrement
 */
#define PDSS_IBTR_CFG_IBTR_UP_DOWN                          (1UL << 1) /* <1:1> R:RW:0: */


/*
 * IBUS Transition control
 */
#define PDSS_IBTR_CTRL_ADDRESS                              (0x400a2254UL)
#define PDSS_IBTR_CTRL                                      (*(volatile uint32_t *)(0x400a2254UL))
#define PDSS_IBTR_CTRL_DEFAULT                              (0x00000000UL)

/*
 * Start the IBTR Operation.
 * FW sets this bit to start the IBTR operation.
 * The operation starts about 3 IBTR clock cycle.
 * HW clears this bit when the current operation is complete or an exit request
 * has been processed and
 * the INTR10.IBTR_OPR_DONE/INTR10.IBTR_EXIT_DONE interrupt is cleared
 */
#define PDSS_IBTR_CTRL_START                                (1UL << 0) /* <0:0> RW0C:RW1S:0: */


/*
 * Exit the current IBTR operation.
 * The operation (incr/decr) is immediately stopped.
 * The EXIT interrupt bit is getting set within one IBTR clock cycle of the
 * EXIT bit being set.
 * SW sets this bit to exit from the current IBTR operation.
 * HW clears this bit once the exit request has been processed and
 * the INTR10.IBTR_OPR_DONE/INTR10.IBTR_EXIT_DONE interrupt is cleared
 */
#define PDSS_IBTR_CTRL_EXIT                                 (1UL << 1) /* <1:1> RW0C:RW1S:0: */


/*
 * IBUS Transition shadow registers
 */
#define PDSS_IBTR_OPR_VALUE_ADDRESS                         (0x400a2258UL)
#define PDSS_IBTR_OPR_VALUE                                 (*(volatile uint32_t *)(0x400a2258UL))
#define PDSS_IBTR_OPR_VALUE_DEFAULT                         (0x00000000UL)

/*
 * Indicates Final Register value after IBTR Operation completion.
 */
#define PDSS_IBTR_OPR_VALUE_IBTR_DAC_MASK                   (0x000000ffUL) /* <0:7> RW:R:0: */
#define PDSS_IBTR_OPR_VALUE_IBTR_DAC_POS                    (0UL)


/*
 * IBUS Transition Initial/Final value registers
 */
#define PDSS_IBTR_INIT_FIN_VALUE_ADDRESS                    (0x400a225cUL)
#define PDSS_IBTR_INIT_FIN_VALUE                            (*(volatile uint32_t *)(0x400a225cUL))
#define PDSS_IBTR_INIT_FIN_VALUE_DEFAULT                    (0x00000000UL)

/*
 * Indicates the Initial Register value to be loaded into IBTR_OPR_VALUE
 * Register.
 */
#define PDSS_IBTR_INIT_FIN_VALUE_IBTR_INIT_MASK             (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_IBTR_INIT_FIN_VALUE_IBTR_INIT_POS              (0UL)


/*
 * Indicates the Final Register value to be reached after operation completion.
 */
#define PDSS_IBTR_INIT_FIN_VALUE_IBTR_FIN_MASK              (0x00ff0000UL) /* <16:23> R:RW:0: */
#define PDSS_IBTR_INIT_FIN_VALUE_IBTR_FIN_POS               (16UL)


/*
 * IBUS Transition Status registers
 */
#define PDSS_IBTR_STATUS_ADDRESS                            (0x400a2264UL)
#define PDSS_IBTR_STATUS                                    (*(volatile uint32_t *)(0x400a2264UL))
#define PDSS_IBTR_STATUS_DEFAULT                            (0x00000000UL)

/*
 * Status of IBTR completion
 */
#define PDSS_IBTR_STATUS_IBTR_DONE                          (1UL << 0) /* <0:0> RW:R:0: */


/*
 * S8PDBB HardIP Filter and Edge detector config for VREG VIN_DET & INRUSH_DET
 */
#define PDSS_INTR17_CFG_0_ADDRESS                           (0x400a2280UL)
#define PDSS_INTR17_CFG_0                                   (*(volatile uint32_t *)(0x400a2280UL))
#define PDSS_INTR17_CFG_0_DEFAULT                           (0x00213827UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_0_PDBB_VREG_VIN_DET_FILT_EN         (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_0_PDBB_VREG_VIN_DET_CFG_MASK        (0x00000006UL) /* <1:2> R:RW:3: */
#define PDSS_INTR17_CFG_0_PDBB_VREG_VIN_DET_CFG_POS         (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR17_CFG_0_PDBB_VREG_VIN_DET_FILT_RESET      (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_0_PDBB_VREG_VIN_DET_FILT_BYPASS     (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_0_PDBB_VREG_VIN_DET_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:1: */
#define PDSS_INTR17_CFG_0_PDBB_VREG_VIN_DET_FILT_SEL_POS    (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_EN     (1UL << 11) /* <11:11> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_CFG_MASK    (0x00003000UL) /* <12:13> R:RW:3: */
#define PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_CFG_POS     (12UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_RESET    (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_BYPASS    (1UL << 15) /* <15:15> R:RW:0: */


/*
 * #of clock CLK_BB_SOFT filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_SEL_MASK    (0x001f0000UL) /* <16:20> R:RW:1: */
#define PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_SEL_POS    (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_DPSLP_MODE    (1UL << 21) /* <21:21> R:RW:1:PASC2_EN */


/*
 * S8PDBB HardIP Filter and Edge detector config for CC1_SCP & CC2_SCP
 */
#define PDSS_INTR17_CFG_10_ADDRESS                          (0x400a22a8UL)
#define PDSS_INTR17_CFG_10                                  (*(volatile uint32_t *)(0x400a22a8UL))
#define PDSS_INTR17_CFG_10_DEFAULT                          (0x00814814UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_10_BB_CC1_SCP_FILT_EN               (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_10_BB_CC1_SCP_FILT_CFG_MASK         (0x00000006UL) /* <1:2> R:RW:2: */
#define PDSS_INTR17_CFG_10_BB_CC1_SCP_FILT_CFG_POS          (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR17_CFG_10_BB_CC1_SCP_FILT_RESET            (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_10_BB_CC1_SCP_FILT_BYPASS           (1UL << 4) /* <4:4> R:RW:1: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_10_BB_CC1_SCP_FILT_SEL_MASK         (0x000007e0UL) /* <5:10> R:RW:0: */
#define PDSS_INTR17_CFG_10_BB_CC1_SCP_FILT_SEL_POS          (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR17_CFG_10_BB_CC1_SCP_DPSLP_MODE            (1UL << 11) /* <11:11> R:RW:1:PASC2_EN */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_10_BB_CC2_SCP_FILT_EN               (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_10_BB_CC2_SCP_FILT_CFG_MASK         (0x00006000UL) /* <13:14> R:RW:2: */
#define PDSS_INTR17_CFG_10_BB_CC2_SCP_FILT_CFG_POS          (13UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR17_CFG_10_BB_CC2_SCP_FILT_RESET            (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_10_BB_CC2_SCP_FILT_BYPASS           (1UL << 16) /* <16:16> R:RW:1: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_10_BB_CC2_SCP_FILT_SEL_MASK         (0x007e0000UL) /* <17:22> R:RW:0: */
#define PDSS_INTR17_CFG_10_BB_CC2_SCP_FILT_SEL_POS          (17UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR17_CFG_10_BB_CC2_SCP_DPSLP_MODE            (1UL << 23) /* <23:23> R:RW:1:PASC2_EN */


/*
 * INTR17 Status
 */
#define PDSS_INTR17_STATUS_0_ADDRESS                        (0x400a22e4UL)
#define PDSS_INTR17_STATUS_0                                (*(volatile uint32_t *)(0x400a22e4UL))
#define PDSS_INTR17_STATUS_0_DEFAULT                        (0x00000000UL)

/*
 * The status of s8pdbb_40vreg_top.vin_det
 */
#define PDSS_INTR17_STATUS_0_PDBB_40VREG_VIN_DET_STATUS     (1UL << 0) /* <0:0> RW:R:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * The filtered output of s8pdbb_40vreg_top.vin_det
 */
#define PDSS_INTR17_STATUS_0_PDBB_40VREG_VIN_DET_FILT       (1UL << 1) /* <1:1> RW:R:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * The status of s8pdbb_40vreg_top.in_rush_det_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_40VREG_IN_RUSH_DET_STATUS    (1UL << 2) /* <2:2> RW:R:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * The filtered output of s8pdbb_40vreg_top.in_rush_det_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_40VREG_IN_RUSH_DET_FILT    (1UL << 3) /* <3:3> RW:R:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * INTR17 Status
 */
#define PDSS_INTR17_STATUS_1_ADDRESS                        (0x400a22e8UL)
#define PDSS_INTR17_STATUS_1                                (*(volatile uint32_t *)(0x400a22e8UL))
#define PDSS_INTR17_STATUS_1_DEFAULT                        (0x00000000UL)

/*
 * The status of s8pdbb_20vconn_top.scp_cc1
 */
#define PDSS_INTR17_STATUS_1_PDBB_CC1_SCP_STATUS            (1UL << 18) /* <18:18> RW:R:0:CCG7D_CCG7S_PASC2_EN */


/*
 * The filtered output of s8pdbb_ea_top.scp_cc1
 */
#define PDSS_INTR17_STATUS_1_PDBB_CC1_SCP_FILT              (1UL << 19) /* <19:19> RW:R:0:CCG7D_CCG7S_PASC2_EN */


/*
 * The status of s8pdbb_20vconn_top.scp_cc2
 */
#define PDSS_INTR17_STATUS_1_PDBB_CC2_SCP_STATUS            (1UL << 20) /* <20:20> RW:R:0:CCG7D_CCG7S_PASC2_EN */


/*
 * The filtered output of s8pdbb_ea_top.scp_cc2
 */
#define PDSS_INTR17_STATUS_1_PDBB_CC2_SCP_FILT              (1UL << 21) /* <21:21> RW:R:0:CCG7D_CCG7S_PASC2_EN */


/*
 * INTR17 interrupt Cause.
 */
#define PDSS_INTR17_ADDRESS                                 (0x400a22ecUL)
#define PDSS_INTR17                                         (*(volatile uint32_t *)(0x400a22ecUL))
#define PDSS_INTR17_DEFAULT                                 (0x00000000UL)

/*
 * s8pdbb_40vreg_top.vin_det changed. Check the INTR17_STATUS_0.PDBB_40VREG_VIN_DET_STATUS
 */
#define PDSS_INTR17_PDBB_40VREG_VIN_DET                     (1UL << 0) /* <0:0> RW1S:RW1C:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * s8pdbb_40vreg_top.in_rush_det_lv changed. Check the INTR17_STATUS_0.PDBB_40VREG_IN_RUSH_DET_STATUS
 */
#define PDSS_INTR17_PDBB_40VREG_IN_RUSH_DET                 (1UL << 1) /* <1:1> RW1S:RW1C:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * changed. Check the INTR17_STATUS_1.PDBB_CC1_SCP_STATUS
 */
#define PDSS_INTR17_PDBB_CC1_SCP                            (1UL << 21) /* <21:21> RW1S:RW1C:0:CCG7D_CCG7S_PASC2_EN */


/*
 * changed. Check the INTR17_STATUS_1.PDBB_CC2_SCP_STATUS
 */
#define PDSS_INTR17_PDBB_CC2_SCP                            (1UL << 22) /* <22:22> RW1S:RW1C:0:CCG7D_CCG7S_PASC2_EN */


/*
 * INTR17 Interrupt Set
 */
#define PDSS_INTR17_SET_ADDRESS                             (0x400a22f0UL)
#define PDSS_INTR17_SET                                     (*(volatile uint32_t *)(0x400a22f0UL))
#define PDSS_INTR17_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_40VREG_VIN_DET                 (1UL << 0) /* <0:0> A:RW1S:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_40VREG_IN_RUSH_DET             (1UL << 1) /* <1:1> A:RW1S:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_CC1_SCP                        (1UL << 21) /* <21:21> A:RW1S:0:CCG7D_CCG7S_PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_CC2_SCP                        (1UL << 22) /* <22:22> A:RW1S:0:CCG7D_CCG7S_PASC2_EN */


/*
 * INTR17 interrupt Mask
 */
#define PDSS_INTR17_MASK_ADDRESS                            (0x400a22f4UL)
#define PDSS_INTR17_MASK                                    (*(volatile uint32_t *)(0x400a22f4UL))
#define PDSS_INTR17_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_40VREG_VIN_DET_MASK           (1UL << 0) /* <0:0> R:RW:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_40VREG_IN_RUSH_DET_MASK       (1UL << 1) /* <1:1> R:RW:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_CC1_SCP_MASK                  (1UL << 21) /* <21:21> R:RW:0:CCG7D_CCG7S_PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_CC2_SCP_MASK                  (1UL << 22) /* <22:22> R:RW:0:CCG7D_CCG7S_PASC2_EN */


/*
 * INTR17 interrupt Masked
 */
#define PDSS_INTR17_MASKED_ADDRESS                          (0x400a22f8UL)
#define PDSS_INTR17_MASKED                                  (*(volatile uint32_t *)(0x400a22f8UL))
#define PDSS_INTR17_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_40VREG_VIN_DET_MASKED       (1UL << 0) /* <0:0> RW:R:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_40VREG_IN_RUSH_DET_MASKED    (1UL << 1) /* <1:1> RW:R:0:CCG7D_EN_INST_ZERO_PASC2 */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_CC1_SCP_MASKED              (1UL << 21) /* <21:21> RW:R:0:CCG7D_CCG7S_PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_CC2_SCP_MASKED              (1UL << 22) /* <22:22> RW:R:0:CCG7D_CCG7S_PASC2_EN */


/*
 * INTR10 Cause. These are the active interrupts get reflected on interrupt_usbpd
 * pin.
 */
#define PDSS_INTR10_ADDRESS                                 (0x400a2340UL)
#define PDSS_INTR10                                         (*(volatile uint32_t *)(0x400a2340UL))
#define PDSS_INTR10_DEFAULT                                 (0x00000000UL)

/*
 * This interrupt indicates Die temparature has crossed above Over Temparature
 * Protection Threshold
 */
#define PDSS_INTR10_OTP_DET                                 (1UL << 7) /* <7:7> RW1S:RW1C:0:EN_OTP */


/*
 * This interrupt indicates a possible Rsense Short condition
 */
#define PDSS_INTR10_RSNS_SHRT_DET                           (1UL << 8) /* <8:8> RW1S:RW1C:0:PASC2_EN */


/*
 * INTR10 Set
 */
#define PDSS_INTR10_SET_ADDRESS                             (0x400a2344UL)
#define PDSS_INTR10_SET                                     (*(volatile uint32_t *)(0x400a2344UL))
#define PDSS_INTR10_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_SET_OTP_DET                             (1UL << 7) /* <7:7> A:RW1S:0:EN_OTP */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_SET_RSNS_SHRT_DET                       (1UL << 8) /* <8:8> A:RW1S:0:PASC2_EN */


/*
 * INTR10 Mask
 */
#define PDSS_INTR10_MASK_ADDRESS                            (0x400a2348UL)
#define PDSS_INTR10_MASK                                    (*(volatile uint32_t *)(0x400a2348UL))
#define PDSS_INTR10_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_MASK_OTP_DET_MASK                       (1UL << 7) /* <7:7> R:RW:0:EN_OTP */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_MASK_RSNS_SHRT_DET_MASK                 (1UL << 8) /* <8:8> R:RW:0:PASC2_EN */


/*
 * INTR10 Masked
 */
#define PDSS_INTR10_MASKED_ADDRESS                          (0x400a234cUL)
#define PDSS_INTR10_MASKED                                  (*(volatile uint32_t *)(0x400a234cUL))
#define PDSS_INTR10_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR10_MASKED_OTP_DET_MASKED                   (1UL << 7) /* <7:7> RW:R:0:EN_OTP */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR10_MASKED_RSNS_SHRT_DET_MASKED             (1UL << 8) /* <8:8> RW:R:0:PASC2_EN */


/*
 * S8PDS Hard IP PTDRV Register
 */
#define PDSS_PTDRV_CTRL_0_ADDRESS                           (0x400a2550UL)
#define PDSS_PTDRV_CTRL_0                                   (*(volatile uint32_t *)(0x400a2550UL))
#define PDSS_PTDRV_CTRL_0_DEFAULT                           (0x80fc0000UL)

/*
 * isolation signal for LV supply
 */
#define PDSS_PTDRV_CTRL_0_PTDRV_ISO_N                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * adft control signal for pulse-transformer-driver block
 * <1:0>        adft0
 * 00                 Z
 * 01                 Driver output (star connection)
 * <3:2>        adft1
 * 00                 Z
 * 01                 vddd supply
 */
#define PDSS_PTDRV_CTRL_0_ADFT_CTRL_PTDRV_MASK              (0x0000003cUL) /* <2:5> R:RW:0: */
#define PDSS_PTDRV_CTRL_0_ADFT_CTRL_PTDRV_POS               (2UL)


/*
 * To alter delay of HV to LV and LV to HV delay
 */
#define PDSS_PTDRV_CTRL_0_T_PTDRV_MASK                      (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_PTDRV_CTRL_0_T_PTDRV_POS                       (6UL)


/*
 * pulse-transformer-driver enable signal
 */
#define PDSS_PTDRV_CTRL_0_PTDRV_EN                          (1UL << 8) /* <8:8> R:RW:0: */


/*
 * 1: tristate ptdriver output
 */
#define PDSS_PTDRV_CTRL_0_PTDRV_TRISTATE                    (1UL << 9) /* <9:9> R:RW:0: */


/*
 * enable internal delay path for ptdrv_in going low to acf_weakp going high
 */
#define PDSS_PTDRV_CTRL_0_EN_INT_DEL_ACF_WEAKP              (1UL << 10) /* <10:10> R:RW:0: */


/*
 * internal delay block to generate hardware delay between ptdrv_in going
 * low to acf_weakp going high
 * <24>= 1 : bypass delay
 * <23:18> :
 * 0 -5ns
 * 63 - 220 ns
 */
#define PDSS_PTDRV_CTRL_0_DELAY_HV_LV_MASK                  (0x01fc0000UL) /* <18:24> R:RW:63: */
#define PDSS_PTDRV_CTRL_0_DELAY_HV_LV_POS                   (18UL)


/*
 * internal delay block to delay pwm pos-edge
 * <31>= 1 : bypass delay
 * <30:25> :
 * 0 -5ns
 * 63 - 220 ns
 */
#define PDSS_PTDRV_CTRL_0_DELAY_LV_HV_MASK                  (0xfe000000UL) /* <25:31> R:RW:64: */
#define PDSS_PTDRV_CTRL_0_DELAY_LV_HV_POS                   (25UL)


/*
 * S8PDS Hard IP PTDRV Register
 */
#define PDSS_PTDRV_CTRL_1_ADDRESS                           (0x400a2554UL)
#define PDSS_PTDRV_CTRL_1                                   (*(volatile uint32_t *)(0x400a2554UL))
#define PDSS_PTDRV_CTRL_1_DEFAULT                           (0x097f007fUL)

/*
 * Drive strength options for HV driver pull up
 * 0x0 - 25k ohm
 * 0x1 - 100 ohm
 * 0x8 - 12 ohm
 * 0xF - 6 ohm
 */
#define PDSS_PTDRV_CTRL_1_PTDRV_HVDRV_PCONF_MASK            (0x0000000fUL) /* <0:3> R:RW:15: */
#define PDSS_PTDRV_CTRL_1_PTDRV_HVDRV_PCONF_POS             (0UL)


/*
 * HV drive slew options pull up
 * <1:0>  :00 lowest drive; 11 highest drive strength of predrivers
 * <2> enables the delay between predrivers
 * <3> Option to reduce the delay between predrivers
 */
#define PDSS_PTDRV_CTRL_1_PTDRV_HVDRV_PSLEW_MASK            (0x000000f0UL) /* <4:7> R:RW:7: */
#define PDSS_PTDRV_CTRL_1_PTDRV_HVDRV_PSLEW_POS             (4UL)


/*
 * HV Pull down drive strength
 * 0x0 - 25k ohm
 * 0x1 - 75 ohm
 * 0x8 - 10 ohm
 * 0xF - 5 ohm
 */
#define PDSS_PTDRV_CTRL_1_PTDRV_NCONF_MASK                  (0x000f0000UL) /* <16:19> R:RW:15: */
#define PDSS_PTDRV_CTRL_1_PTDRV_NCONF_POS                   (16UL)


/*
 * HV Pull down slew options
 * <1:0>  :00 lowest drive; 11 highest drive strength of predrivers
 * <2> enables the delay between predrivers
 * <3> Option to reduce the delay between predrivers
 */
#define PDSS_PTDRV_CTRL_1_PTDRV_NSLEW_MASK                  (0x00f00000UL) /* <20:23> R:RW:7: */
#define PDSS_PTDRV_CTRL_1_PTDRV_NSLEW_POS                   (20UL)


/*
 * Change the source current during weak pull up
 * 0x1 - 0.5 mA
 * 0x8 - 4 mA
 * 0x15 - 8 mA
 */
#define PDSS_PTDRV_CTRL_1_PTDRV_RES_CONF_MASK               (0x0f000000UL) /* <24:27> R:RW:9: */
#define PDSS_PTDRV_CTRL_1_PTDRV_RES_CONF_POS                (24UL)


/*
 * PASC Hard-Ip Sequence Generator Control Register 3
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_ADDRESS                     (0x400a2558UL)
#define PDSS_HIP_SEQ_GEN_3_CTRL                             (*(volatile uint32_t *)(0x400a2558UL))
#define PDSS_HIP_SEQ_GEN_3_CTRL_DEFAULT                     (0x10604070UL)

/*
 * ZVS enable (ZVS and ACF cannot be enabled together)
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_ZVS_ON_ANY_VALLEY           (1UL << 0) /* <0:0> R:RW:0:PASC2_EN */


/*
 * ACF enable (ACF and ZVS cannot be enabled together)
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_ACF_EN                      (1UL << 1) /* <1:1> R:RW:0:PASC2_EN */


/*
 * 1:  NSN_EN does not depend on feedfwd_integ_resetb_out going high for
 * legacy mode (non-False-NSN)
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_FF_INTEG_RESETB_DIS_FOR_NSN_EN    (1UL << 2) /* <2:2> R:RW:0:PASC2_EN */


/*
 * 1: ZCDF_OUT not used for NSN_EN in SR-mode
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_ZCDF_DIS_FOR_NSN_EN         (1UL << 3) /* <3:3> R:RW:0:PASC2_EN */


/*
 * 1: ZCD_OUT not used for NSN_EN in SR-mode
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_ZCD_DIS_FOR_NSN_EN          (1UL << 4) /* <4:4> R:RW:1:PASC2_EN */


/*
 * In SR-Only Mode wait for FF Integ out to enable NSN (False-NSN mode)
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_FALSE_NSN_FOR_NSN_EN        (1UL << 5) /* <5:5> R:RW:1:PASC2_EN */


/*
 * 1: NSN IDLE Timer expiry not used for NSN_EN while waiting for FF_integ_out
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_NSN_IDL_TMR_DIS_FOR_NSN_EN    (1UL << 6) /* <6:6> R:RW:1:PASC2_EN */


/*
 * 1: PTDRV_IN Neg-edge not used for NSN_EN async assertion for PWM mode
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_PTDRV_NEG_DIS_FOR_NSN_EN    (1UL << 7) /* <7:7> R:RW:0:PASC2_EN */


/*
 * 1: Dual_gdrv_mode override
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_OVR_DUAL_GDRV_MODE          (1UL << 8) /* <8:8> R:RW:0:PASC2_EN */


/*
 * Dual_gdrv_mode value in override mode
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_OVR_DUAL_GDRV_MODE_VAL      (1UL << 9) /* <9:9> R:RW:0:PASC2_EN */


/*
 * 1: sr_sen_ctrln_en override
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_OVR_SR_SEN_CTRLN_EN_MODE    (1UL << 10) /* <10:10> R:RW:0:PASC2_EN */


/*
 * sr_sen_ctrln_en value in override mode
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_OVR_SR_SEN_CTRLN_EN_MODE_VAL    (1UL << 11) /* <11:11> R:RW:0:PASC2_EN */


/*
 * 1: sr_sen_ctrlp_en override
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_OVR_SR_SEN_CTRLP_EN_MODE    (1UL << 12) /* <12:12> R:RW:0:PASC2_EN */


/*
 * sr_sen_ctrlp_en value in override mode
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_OVR_SR_SEN_CTRLP_EN_MODE_VAL    (1UL << 13) /* <13:13> R:RW:0:PASC2_EN */


/*
 * 1: ACF_IN pos-edge not used for deassertion of ZCD_EN, ZCDF_EN, GDRV_IN
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_ACF_IN_DIS_FOR_SIG_DSRT     (1UL << 14) /* <14:14> R:RW:1:PASC2_EN */


/*
 * Mask L2H event based transition from SKIP to EA mode
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_MASK_L2H_IN_SKIP            (1UL << 15) /* <15:15> R:RW:0:PASC2_EN */


/*
 * Setting this bit makes burst_entry signal as burst exit signal. This also
 * block burst entry from SKIP and moves to EA mode on Burst entry detection.
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_BLOCK_BURST_MODE            (1UL << 16) /* <16:16> R:RW:0:PASC2_EN */


/*
 * Control bit to enable ACF Calibration. To enable ACF cal, this bit must
 * be set before setting ACF_EN. This bit is acuto cleared once the ACF calibration
 * is either completed successfully or fails.
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_ACF_CAL_EN                  (1UL << 17) /* <17:17> RW1C:RW:0:PASC2_EN */


/*
 * Control bit to enable DT Mask Calibration. To enable ACF cal, this bit
 * must be set before setting ACF_EN. This bit is acuto cleared once the
 * ACF calibration is either completed successfully or fails.
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_DT_CAL_EN                   (1UL << 18) /* <18:18> RW1C:RW:0:PASC2_EN */


/*
 * SR Mode: For GDRV pulse-width higher than this threshold, will enable
 * dual_gdrv_mode
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_DOUBLER_EN_THRESHOLD_MASK    (0x03f80000UL) /* <19:25> R:RW:12:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_3_CTRL_DOUBLER_EN_THRESHOLD_POS    (19UL)


/*
 * SR Mode:  Dual_gdrv_mode deassertion after (previous switching cycle GDRV
 * pulse-width - this delay) from assertion of  GDRV_IN
 */
#define PDSS_HIP_SEQ_GEN_3_CTRL_DOUBLER_DIS_PRE_DLY_MASK    (0xfc000000UL) /* <26:31> R:RW:4:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_3_CTRL_DOUBLER_DIS_PRE_DLY_POS     (26UL)


/*
 * PASC Hard-Ip Sequence Generator Control Register 4
 */
#define PDSS_HIP_SEQ_GEN_4_CTRL_ADDRESS                     (0x400a255cUL)
#define PDSS_HIP_SEQ_GEN_4_CTRL                             (*(volatile uint32_t *)(0x400a255cUL))
#define PDSS_HIP_SEQ_GEN_4_CTRL_DEFAULT                     (0x0006060dUL)

/*
 * SR mode : Feedfwd_integ_resetb pulse-width above this threshold will result
 * in enabling of nsn_en
 */
#define PDSS_HIP_SEQ_GEN_4_CTRL_FF_INTEG_RSTB_PW_THRESH_MASK    (0x000001ffUL) /* <0:8> R:RW:13:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_4_CTRL_FF_INTEG_RSTB_PW_THRESH_POS    (0UL)


/*
 * Enable generation of dual_gdrv_mode signal.
 */
#define PDSS_HIP_SEQ_GEN_4_CTRL_DUAL_GDRV_PULSE_EN          (1UL << 9) /* <9:9> R:RW:1:PASC2_EN */


/*
 * Pulse width of dual_gdrv_pulse after deassertion of dual_gdrv_mode signal.
 */
#define PDSS_HIP_SEQ_GEN_4_CTRL_DUAL_GDRV_PW_MASK           (0x00001c00UL) /* <10:12> R:RW:1:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_4_CTRL_DUAL_GDRV_PW_POS            (10UL)


/*
 * Enables SR_SEN_CTRLN_EN controlled assertion during ACF cal mode.
 */
#define PDSS_HIP_SEQ_GEN_4_CTRL_EN_SR_SEN_CTRLN_EN_IN_ACF_CAL    (1UL << 13) /* <13:13> R:RW:0:PASC2_EN */


/*
 * SR_SEN_CTRLN timeout from assertion of SR_SEN_CTRLN. Should be programmed
 * 1 more than the calculated value.
 * For SR mode : Programme it to high value (100us).
 */
#define PDSS_HIP_SEQ_GEN_4_CTRL_SR_SEN_CTRLN_DSRT_DLY_MASK    (0x03ffc000UL) /* <14:25> R:RW:24:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_4_CTRL_SR_SEN_CTRLN_DSRT_DLY_POS    (14UL)


/*
 * PWM mode: SR_SEN_CTRLN on delay;
 * SR-mode : NSN_EN pos-edge + [(NSN_WAIT_TIME - ctrln_en_buffer_delay)]
 */
#define PDSS_HIP_SEQ_GEN_4_CTRL_SR_SEN_CTRLN_BUF_DLY_MASK    (0xfc000000UL) /* <26:31> R:RW:0:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_4_CTRL_SR_SEN_CTRLN_BUF_DLY_POS    (26UL)


/*
 * PASC Hard-Ip Sequence Generator Control Register 5
 */
#define PDSS_HIP_SEQ_GEN_5_CTRL_ADDRESS                     (0x400a2560UL)
#define PDSS_HIP_SEQ_GEN_5_CTRL                             (*(volatile uint32_t *)(0x400a2560UL))
#define PDSS_HIP_SEQ_GEN_5_CTRL_DEFAULT                     (0x00800703UL)

/*
 * Controls assertion delay of "zcd_en" signal. Used in Low Frequency Mode.
 */
#define PDSS_HIP_SEQ_GEN_5_CTRL_ZCD_EN_ON_DLY_LFM_MASK      (0x000000ffUL) /* <0:7> R:RW:3:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_5_CTRL_ZCD_EN_ON_DLY_LFM_POS       (0UL)


/*
 * Pulse-width of ACF_WeakP
 */
#define PDSS_HIP_SEQ_GEN_5_CTRL_ACF_WEAKP_PW_MASK           (0x00003f00UL) /* <8:13> R:RW:7:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_5_CTRL_ACF_WEAKP_PW_POS            (8UL)


/*
 * Controls assertion delay of ACF_IN signal. The delay is appicable after
 * VAR_TMIN_TIMEOUT.
 */
#define PDSS_HIP_SEQ_GEN_5_CTRL_ACF_IN_ON_DLY_MASK          (0x000fc000UL) /* <14:19> R:RW:0:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_5_CTRL_ACF_IN_ON_DLY_POS           (14UL)


/*
 * FW override control of PTDRV_IN. To be used when PASC is in IDLE mode
 */
#define PDSS_HIP_SEQ_GEN_5_CTRL_OVR_PTDRV_IN                (1UL << 20) /* <20:20> R:RW:0:PASC2_EN */


/*
 * FW override value of PTDRV_IN.
 */
#define PDSS_HIP_SEQ_GEN_5_CTRL_OVR_PTDRV_IN_VAL            (1UL << 21) /* <21:21> R:RW:0:PASC2_EN */


/*
 * SR_SEN_CTRLN_EN off delay from NSN_EN deassertion. This should be atleast
 * 2 lesser than the ZCDF_EN/ZCD_EN ON delays.
 */
#define PDSS_HIP_SEQ_GEN_5_CTRL_SR_SEN_CTRLN_OFF_DLY_MASK    (0x03c00000UL) /* <22:25> R:RW:2:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_5_CTRL_SR_SEN_CTRLN_OFF_DLY_POS    (22UL)


/*
 * ACF mode : PTDRV_IN neg-edge to ACF_weakP on delay; [FW]
 * ZVS mode : GDRV_IN_ZVS on delay from Valid Peak
 */
#define PDSS_HIP_SEQ_GEN_5_CTRL_ACF_WEAKP_ZVS_ON_VALLEY_DLY_MASK    (0xfc000000UL) /* <26:31> R:RW:0:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_5_CTRL_ACF_WEAKP_ZVS_ON_VALLEY_DLY_POS    (26UL)


/*
 * PASC Hard-Ip Sequence Generator Control Register 6
 */
#define PDSS_HIP_SEQ_GEN_6_CTRL_ADDRESS                     (0x400a2564UL)
#define PDSS_HIP_SEQ_GEN_6_CTRL                             (*(volatile uint32_t *)(0x400a2564UL))
#define PDSS_HIP_SEQ_GEN_6_CTRL_DEFAULT                     (0x0a140a0cUL)

/*
 * ACF DCM mode : ACF_IN pulse width;
 * ZVS mode : ZVS pulse width
 */
#define PDSS_HIP_SEQ_GEN_6_CTRL_ACF_DCM_ZVS_PW_MASK         (0x000001ffUL) /* <0:8> R:RW:12:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_6_CTRL_ACF_DCM_ZVS_PW_POS          (0UL)


/*
 * ACF CCM mode : ACF_IN pulse width
 */
#define PDSS_HIP_SEQ_GEN_6_CTRL_ACF_CCM_PW_MASK             (0x0003fe00UL) /* <9:17> R:RW:5:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_6_CTRL_ACF_CCM_PW_POS              (9UL)


/*
 * ACF DCM mode: ACF_IN neg-edge to PTDRV pos-edge delay;
 * ZVS mode : GDRV_IN_ZVS neg-edge to PTDRV pos-edge delay
 */
#define PDSS_HIP_SEQ_GEN_6_CTRL_ACF_ZVS_PTDRV_DCM_DLY_MASK    (0x01fc0000UL) /* <18:24> R:RW:5:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_6_CTRL_ACF_ZVS_PTDRV_DCM_DLY_POS    (18UL)


/*
 * ACF CCM mode: ACF_IN neg-edge to PTDRV pos-edge delay;
 */
#define PDSS_HIP_SEQ_GEN_6_CTRL_ACF_PTDRV_CCM_DLY_MASK      (0xfe000000UL) /* <25:31> R:RW:5:PASC2_EN */
#define PDSS_HIP_SEQ_GEN_6_CTRL_ACF_PTDRV_CCM_DLY_POS       (25UL)


/*
 * Power Adapter Secondary Controller (PASC) Configuration Register 1
 */
#define PDSS_PASC_CTRL_1_ADDRESS                            (0x400a256cUL)
#define PDSS_PASC_CTRL_1                                    (*(volatile uint32_t *)(0x400a256cUL))
#define PDSS_PASC_CTRL_1_DEFAULT                            (0x00000070UL)

/*
 * Indicates Frequency mode of operation. When enabled, the delay registers
 * pertaining to the Low Frequency Mode of operation are used in timers.
 * 0 - High Frequency Mode
 * 1 - Low Frequency Mode (LFM)
 */
#define PDSS_PASC_CTRL_1_LFM_MODE                           (1UL << 0) /* <0:0> R:RW:0:PASC2_EN */


/*
 * Control bit for feedfwd_integ_resetb_in signal.
 * 0 - Logic uses FEEDFWD_2_CTRL::feedfwd_integ_resetb_in register value
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_PASC_CTRL_1_SEL_EXT_FF_INTEG_RESETB_IN         (1UL << 1) /* <1:1> R:RW:0:PASC2_EN */


/*
 * Control bit for ACF_IN signal.
 * 0 - Logic uses Hard-Ip generated signal
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_PASC_CTRL_1_SEL_EXT_ACF_IN                     (1UL << 2) /* <2:2> R:RW:0:PASC2_EN */


/*
 * Control bit for ACF_WEAKP signal.
 * 0 - Logic uses Hard-Ip generated signal
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_PASC_CTRL_1_SEL_EXT_ACF_WEAKP                  (1UL << 3) /* <3:3> R:RW:0:PASC2_EN */


/*
 * Control bit for Fix Freq timeout mask in FF-QR dynamic switching mode
 * 0 - Fix Freq timeout is not masked.
 * 1 - Fix Freq timeout detection is masked if Valley is not 0, forcing the
 * system to be in QR mode.
 */
#define PDSS_PASC_CTRL_1_EN_FF_MASK_QR_FF_DS                (1UL << 4) /* <4:4> R:RW:1:PASC2_EN */


/*
 * Control bit for Fix Freq timeout mask in during SKIP
 * 0 - Fix Freq timeout is not masked.
 * 1 - Fix Freq timeout detection is masked if skip entry is asserted allowing
 * SKIP state entry
 */
#define PDSS_PASC_CTRL_1_EN_FF_MASK_SKIP                    (1UL << 5) /* <5:5> R:RW:1:PASC2_EN */


/*
 * Control bit for Var TMAX timeout mask during SKIP and IDLE entry
 * 0 - Var TMAX timeout is not masked.
 * 1 - Var TMAX timeout detection is masked if skip entry is asserted allowing
 * SKIP state entry or IDLE when Idle entry is asserted
 */
#define PDSS_PASC_CTRL_1_EN_VAR_TMAX_MASK                   (1UL << 6) /* <6:6> R:RW:1:PASC2_EN */


/*
 * S8PDS Hard IP LSCSA V2 Register
 */
#define PDSS_LSCSAV2_CTRL_0_ADDRESS                         (0x400a2570UL)
#define PDSS_LSCSAV2_CTRL_0                                 (*(volatile uint32_t *)(0x400a2570UL))
#define PDSS_LSCSAV2_CTRL_0_DEFAULT                         (0x80000000UL)

/*
 * ADFT master enable
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_LSCSAV2_ADFT_EN                 (1UL << 0) /* <0:0> R:RW:0: */


/*
 * ADFT control bits
 * adft_ctrl<3:0>=adft<0>
 * 0=Hi-Z
 * 1=pad_inp
 * 2=Reserved
 * 3=Reserved
 * 4=Measure SCP current COMP's stack current
 * 5=Measure vrefin_ocp coming to lscsa from refgen
 * 6=Force OCP vrefin_ocp through adft
 * 7=Force LTRAN S/H voltage (vmid_sf) through adft
 * 8=adft UGB input offset voltage calibration, Force UGB input voltage through
 * adft<1> and measure UGB output through adft<0>
 * 9=Measure VOUT_CC and adft_ctrl<7:4>=0 should be kept at zero
 * 10=Measure VOUT_CBL and adft_ctrl<7:4>=0 should be kept at zero
 * 11=Measure VOUT_MON and adft_ctrl<7:4>=0 should be kept at zero
 * 12=Measure VOUT_OCP and adft_ctrl<7:4>=0 should be kept at zero
 * [15:13]=Reserved for UGB output type signal only
 *
 * adft_ctrl<7:4>=adft<1>
 * 0=Hi-Z
 * 1=pad_inn
 * 2=Reserved
 * 3=Measure LTRAN vmid_sf
 * 4=Measure LTRAN deltavn_sf
 * 5=Measure LTRAN deltavp_sf
 * 6=Force OCP vin_ocp through adft
 * 7=Force LTRAN deltav (both vmid_deltavn_sf, vmid_deltavp_sf) through adft
 * 8=adft UGB input offset voltage calibration, Force UGB input voltage through
 * adft<1> and measure UGB output through adft<0>
 * [15;9]=Reserved for UGB input type signal only
 */
#define PDSS_LSCSAV2_CTRL_0_ADFT_CTRL_LSCSAV2_MASK          (0x000001feUL) /* <1:8> R:RW:0: */
#define PDSS_LSCSAV2_CTRL_0_ADFT_CTRL_LSCSAV2_POS           (1UL)


/*
 * Enable of lscsa block (VOUT_CC,VOUT_CBL,VOUT_MON, VOUT_CC_RCFILTER)
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_EN_LSCSA                        (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Enable of load transient detect block (LTRAN)
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_EN_LTRAN                        (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Enable signal of LTRAN high to low comparator
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_EN_LTRANCOMP_H2L                (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Enable signal of LTRAN low to high comparator
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_EN_LTRANCOMP_L2H                (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Enable of OCP block
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_EN_OCP                          (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Enable of OCP hysteresis
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_EN_OCP_HYST                     (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Enable of OCP Comparator output
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_EN_OCP_OUT_D                    (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Enable of SCP block
 * 0- OFF
 * 1- ON
 */
#define PDSS_LSCSAV2_CTRL_0_EN_SCP                          (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Enable of SCP hysteresis
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_EN_SCP_HYST                     (1UL << 17) /* <17:17> R:RW:0: */


/*
 * Enable of SCP Comparator output
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_EN_SCP_OUT_D                    (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Enable of vbg/r current reference
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_EN_VBGBYR                       (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Engineering Option: Increase bias current of LTRAN Source follower Buffer
 */
#define PDSS_LSCSAV2_CTRL_0_LTRAN_BUFFER_IBIAS_INC          (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Engineering Option: Set pin leakage compensation current for pad_inp to
 * match pad_inp leakage with pad_vgnd
 */
#define PDSS_LSCSAV2_CTRL_0_SEL_ICOMP_PAD_INP               (1UL << 21) /* <21:21> R:RW:0: */


/*
 * Engineering Option: Disable cascode bias of V2I converter amplifier input
 * stage PMOS differential pair
 */
#define PDSS_LSCSAV2_CTRL_0_V2I_AMP_DIFFPAIR_CASCODE_DIS    (1UL << 22) /* <22:22> R:RW:0: */


/*
 * Engineering Option: Configure extra pin current on pad_vgnd to measure
 * contact resistance during production test
 */
#define PDSS_LSCSAV2_CTRL_0_SEL_ISINK_PAD_VGND              (1UL << 23) /* <23:23> R:RW:0: */


/*
 * select SCP output latch path inside this IP
 */
#define PDSS_LSCSAV2_CTRL_0_SEL_SCP_LATCH_PATH              (1UL << 24) /* <24:24> R:RW:0: */


/*
 * isolation signal for LV supply
 * 0 - OFF
 * 1 - ON
 */
#define PDSS_LSCSAV2_CTRL_0_LSCSA_V2_ISO_N                  (1UL << 30) /* <30:30> R:RW:0: */


/*
 * Block power down input (Master PD)
 * 1 - All analog and DC paths cut off, outputs forced to known value
 * 0 - Normal functionality
 */
#define PDSS_LSCSAV2_CTRL_0_LSCSA_V2_PD                     (1UL << 31) /* <31:31> R:RW:1: */


/*
 * S8PDS Hard IP LSCSA V2 Register
 */
#define PDSS_LSCSAV2_CTRL_1_ADDRESS                         (0x400a2574UL)
#define PDSS_LSCSAV2_CTRL_1                                 (*(volatile uint32_t *)(0x400a2574UL))
#define PDSS_LSCSAV2_CTRL_1_DEFAULT                         (0x002002d9UL)

/*
 * Selects the voltage gain for LTRAN
 * 2'b00-AV=20
 * 2'b01-AV=30(Default)
 * 2'b10-AV=40
 * 2'b11-AV=50
 */
#define PDSS_LSCSAV2_CTRL_1_SEL_AV_LTRAN_MASK               (0x00000003UL) /* <0:1> R:RW:1: */
#define PDSS_LSCSAV2_CTRL_1_SEL_AV_LTRAN_POS                (0UL)


/*
 * Selects the voltage gain for OCP
 * 2'b00-AV=30
 * 2'b01-AV=40
 * 2'b10-AV=50(Default)
 * 2'b11-AV=60
 */
#define PDSS_LSCSAV2_CTRL_1_SEL_AV_OCP_MASK                 (0x0000000cUL) /* <2:3> R:RW:2: */
#define PDSS_LSCSAV2_CTRL_1_SEL_AV_OCP_POS                  (2UL)


/*
 * Selects the voltage gain for VOUT_CBL
 * 2'b00->AV=30
 * 2'b01->AV=60(Default)
 * 2'b10->AV=150
 * 2'b11->AV=200
 */
#define PDSS_LSCSAV2_CTRL_1_SEL_AV_VOUT_CBL_MASK            (0x00000030UL) /* <4:5> R:RW:1: */
#define PDSS_LSCSAV2_CTRL_1_SEL_AV_VOUT_CBL_POS             (4UL)


/*
 * Selects the voltage gain for VOUT_CC
 * 3'b000->AV=30
 * 3'b001->AV=40
 * 3'b010->AV=50
 * 3'b011->AV=60(Default)
 * 3'b100->AV=70
 * 3'b101->AV=80
 * 3'b110->AV=90
 * 3'b111->AV=100
 */
#define PDSS_LSCSAV2_CTRL_1_SEL_AV_VOUT_CC_MASK             (0x000001c0UL) /* <6:8> R:RW:3: */
#define PDSS_LSCSAV2_CTRL_1_SEL_AV_VOUT_CC_POS              (6UL)


/*
 * Selects the voltage gain for VOUT_MON
 * 2'b00->AV=30
 * 2'b01->AV=60(Default)
 * 2'b10->AV=150
 * 2'b11->AV=200
 */
#define PDSS_LSCSAV2_CTRL_1_SEL_AV_VOUT_MON_MASK            (0x00000600UL) /* <9:10> R:RW:1: */
#define PDSS_LSCSAV2_CTRL_1_SEL_AV_VOUT_MON_POS             (9UL)


/*
 * Selects the OCP analog bandwidth
 * 2'b00->BW=44KHz(default)
 * 2'b01->BW=62KHz
 * 2'b10->BW=98KHZ
 * 2'b11->BW=206KHz
 */
#define PDSS_LSCSAV2_CTRL_1_SEL_BW_OCP_MASK                 (0x00007800UL) /* <11:14> R:RW:0: */
#define PDSS_LSCSAV2_CTRL_1_SEL_BW_OCP_POS                  (11UL)


/*
 * Selects the SCP analog bandwidth
 * 2'b00->BW=4.1MHz(default)
 * 2'b01->BW=3.2MHz
 * 2'b10->BW=2.7MHZ
 * 2'b11->BW=2.4MHz
 */
#define PDSS_LSCSAV2_CTRL_1_SEL_BW_SCP_MASK                 (0x00018000UL) /* <15:16> R:RW:0: */
#define PDSS_LSCSAV2_CTRL_1_SEL_BW_SCP_POS                  (15UL)


/*
 * Selects the VOUT_CC_RCFILTER analog bandwidth, VOUT_CC analog bandwidth
 * option available in EA
 * 4'b0000->BW=10KHz(default)
 * 4'b0001->BW=14KHz
 * 4'b0010->BW=25KHz
 * 4'b0011->BW=91KHz
 *
 * 4'b0100->BW=14KHz
 * 4'b0101->BW=19KHz
 * 4'b0110->BW=33KHz
 * 4'b0111->BW=107KHz
 *
 * 4'b1000->BW=20KHz
 * 4'b1001->BW=28KHz
 * 4'b1010->BW=45KHz
 * 4'b1011->BW=106KHz
 *
 * 4'b1100->BW=46KHz
 * 4'b1101->BW=59KHz
 * 4'b0110->BW=80KHz
 * 4'b1111->BW=116KHz
 */
#define PDSS_LSCSAV2_CTRL_1_SEL_BW_VOUT_CC_MASK             (0x001e0000UL) /* <17:20> R:RW:0: */
#define PDSS_LSCSAV2_CTRL_1_SEL_BW_VOUT_CC_POS              (17UL)


/*
 * Selects the delta voltage for LTRAN detection
 * 3'b000->deltaV=50mV
 * 3'b001->deltaV=75mV(default)
 * 3'b010->deltaV=100mV
 * 3'b011->deltaV=125mV
 * 3'b100->deltaV=150mV
 * 3'b101->deltaV=200mV
 * 3'b110->deltaV=250mV
 * 3'b111->deltaV=300mV
 */
#define PDSS_LSCSAV2_CTRL_1_SEL_LTRAN_DELTAV_MASK           (0x00e00000UL) /* <21:23> R:RW:1: */
#define PDSS_LSCSAV2_CTRL_1_SEL_LTRAN_DELTAV_POS            (21UL)


/*
 * Selects SCP detection threshold
 * 3'b000->SCP=6A(default)
 * 3'b001->SCP=8A
 * 3'b010->SCP=10A
 * 3'b011->SCP=12A
 * 3'b100->SCP=14A
 * 3'b101->SCP=16A
 * 3'b110->SCP=18A
 * 3'b111->SCP=20A
 */
#define PDSS_LSCSAV2_CTRL_1_SEL_SCP_MASK                    (0x07000000UL) /* <24:26> R:RW:0: */
#define PDSS_LSCSAV2_CTRL_1_SEL_SCP_POS                     (24UL)


/*
 * Selects SCP output blanking time(analog filter), rising edge
 * 3'b000->DELAY=0uS(Default)
 * 3'b001->DELAY=0.42uS
 * 3'b010->DELAY=0.68uS
 * 3'b011->DELAY=0.93uS
 * 3'b100->DELAY=1.17uS
 * 3'b101->DELAY=1.40uS
 * 3'b110->DELAY=1.64uS
 * 3'b111->DELAY=1.87S
 */
#define PDSS_LSCSAV2_CTRL_1_SEL_SCP_BLNK_TIME_MASK          (0x38000000UL) /* <27:29> R:RW:0: */
#define PDSS_LSCSAV2_CTRL_1_SEL_SCP_BLNK_TIME_POS           (27UL)


/*
 * S8PDSV2 40V Regulator Control Register
 */
#define PDSS_V2_40VREG_CTRL_ADDRESS                         (0x400a2578UL)
#define PDSS_V2_40VREG_CTRL                                 (*(volatile uint32_t *)(0x400a2578UL))
#define PDSS_V2_40VREG_CTRL_DEFAULT                         (0x008acf82UL)

/*
 * LV output isolation (active low)
 * 0 : All the LV outputs are forced to a known value
 * 1 : Actual LV outputs are passed through
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_ISO_N                 (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Regulator enable signal in LV (vccd) domain
 * 0: Regulator is disabled
 * 1: Regulator is enabled
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_VREG_EN               (1UL << 1) /* <1:1> R:RW:1: */


/*
 * adft_ctrl<3> : reserved                                              
 *                                                                      
 *                                                             000 - adft<0>=
 * HiZ , adft<1>=HiZ                                                    
 *                                                                      
 *                                                      001 - adft<0>= vreg_cr_out
 * , adft<1>=Vfb for Vin reg                                            
 *                                                                      
 *                                                              010 - adft<0>=
 * vin_good_vcrude , adft<1>=vbus_clip_adft                             
 *                                                                      
 *                                                                      
 *      011 - adft<0>= clamp_ctrl_cr for inrush , adft<1>=Not used      
 *                                                                      
 *                                                                      
 *                              100 - adft<0>= ib 0.64uA , adft<1>=inrush_det_out_cr
 *                                                                      
 *                                                                      
 *                                    101 - adft<0>= vreg_en_vcr , adft<1>=vreg_out
 *                                                                      
 *                                                                      
 *                                    110 - adft<0>= load_sense , adft<1>=vref_int
 *                                                                      
 *                                                                      
 *                                    111 - adft<0>= Dynamic bias , adft<1>=Not
 * used
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_ADFT_CTRL_MASK        (0x0000003cUL) /* <2:5> R:RW:0: */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_ADFT_CTRL_POS         (2UL)


/*
 * Reference voltage select signal
 * 0 - Use 0.74V dpslp reference
 * 1 - Use 0.74V derived from bandgap reference
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_VBG_EN                (1UL << 6) /* <6:6> R:RW:0: */


/*
 *  Test-mode to change the regulator output to 3.0V
 * 00 : vreg_out = 5v [FW]
 * 01 : vreg_out = 2.7v
 * 10 : vreg_out = 3.0v
 * 11 : vreg_out = 3.3v
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_VREG_3P3_MASK       (0x00000180UL) /* <7:8> R:RW:3: */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_VREG_3P3_POS        (7UL)


/*
 * <3> - TO disable the load sense feedback current in amplifier first stage
 * of regulator, 0- Active mode , 1-Deep-sleep mode                     
 *                                <2:0>:  Controls for changing the active
 * mode bias current
 * 111 : Active mode full current
 * 000 : Dpslp mode, no current [FW]
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_ACT_BIAS_DAC_MASK     (0x00001e00UL) /* <9:12> R:RW:7: */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_ACT_BIAS_DAC_POS      (9UL)


/*
 * Disable the additional bias current added in first stage
 * 0 : Keep bias on
 * 1 : Disable the bias
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_DIS_LUA_LEAKER      (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Turn on the inrush current limiting clamp bypassing the inrush current
 * detection
 * 0 : Normal operation [FW]
 * 1 : Force the clamp on
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_INRSH_CLAMP_ON      (1UL << 14) /* <14:14> R:RW:1: */


/*
 * Enable signal for regulator active mode
 * 0 : Regulator in Deepsleep mode
 * 1 : Regulator in active mode
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_VREG_ACT_EN           (1UL << 15) /* <15:15> R:RW:1: */


/*
 * Selection bits to vary the inrush limit for dpslp mode
 * 00 : in-rush limit in dpslp = 20mA
 * 01 : in-rush limit in dpslp = 30mA
 * 10 : in-rush limit in dpslp = 40mA
 * 11 : in-rush limit in dpslp = 50mA
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_DPSLP_CLAMP_SEL_MASK    (0x00030000UL) /* <16:17> R:RW:2: */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_DPSLP_CLAMP_SEL_POS    (16UL)


/*
 * Selection bits to vary the inrush detection threshold for active mode
 * 00 : inrush detection threshold = 100mA
 * 01 : inrush detection threshold = 170mA
 * 10 : inrush detection threshold = 240mA
 * 11 : inrush detection threshold = 310mA
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_INRSH_DET_SEL_MASK    (0x000c0000UL) /* <18:19> R:RW:2: */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_INRSH_DET_SEL_POS     (18UL)


/*
 * Test-mode to force the in-rush clamp OFF ( 1 - Clamp always off , 0 -
 * Normal operation)
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_DIS_INRSH_CLAMP     (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Test-mode to enable the 5uA leaker on VREG_OUT/VDDD ( 1 - Enable the leaker
 * , 0 - Disable the leaker)
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_EN_5UA_LEAKER       (1UL << 21) /* <21:21> R:RW:0: */


/*
 * Test-mode to disable the 20uA leaker on VREG_OUT/VDDD ( 1 - Disbale the
 * leaker , 0 - Enable the leaker) (DPSLP=1)
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_DIS_20UA_LEAKER     (1UL << 22) /* <22:22> R:RW:0: */


/*
 * Test-mode to disable the load based biasing in dpslp mode (1: disable
 * this feature , 0 : Enable) [FW]
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_DIS_LOAD_SENS_FB    (1UL << 23) /* <23:23> R:RW:1: */


/*
 * Test-mode to halve the gain of load based biasing in dpslp mode (1: half
 * gain , 0 : defualt gain)
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_HALF_LOAD_SENS_FB    (1UL << 24) /* <24:24> R:RW:0: */


/*
 * unused
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_VDDD_DET_ON         (1UL << 25) /* <25:25> R:RW:0: */


/*
 * <5:1> Unused , <0> Reduce the opamp bias current in active mode [FW]
 */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_VIN_REG_MASK        (0xfc000000UL) /* <26:31> R:RW:0: */
#define PDSS_V2_40VREG_CTRL_V2_40VREG_T_VIN_REG_POS         (26UL)


/*
 * Feed Forward 1 Control Register
 */
#define PDSS_FEEDFWD_1_CTRL_ADDRESS                         (0x400a257cUL)
#define PDSS_FEEDFWD_1_CTRL                                 (*(volatile uint32_t *)(0x400a257cUL))
#define PDSS_FEEDFWD_1_CTRL_DEFAULT                         (0x004e1000UL)

/*
 * Integrator output masking and latch reset
 * 0-> disable output & reset latch
 * 1-> enable output & release latch
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_COMP_EN                 (1UL << 0) /* <0:0> R:RW:0: */


/*
 * 1-> Disable I_FF linearity
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_ICOMP_PD                (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable bit for false-NSN block. 0 in PWM mode; 1 in SR mode
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_INTEG_EN                (1UL << 4) /* <4:4> R:RW:0: */


/*
 * 1-> Disable minimum I_FF
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_MIN_IFF_PD              (1UL << 5) /* <5:5> R:RW:0: */


/*
 * 1->Disable internal sampling switch logic
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_SW_LOGIC_PD             (1UL << 6) /* <6:6> R:RW:0: */


/*
 * 1-> Disable  VIN comparator 1
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_VINCOMP1_PD             (1UL << 7) /* <7:7> R:RW:0: */


/*
 * 1-> Disable  VIN comparator 2
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_VINCOMP2_PD             (1UL << 8) /* <8:8> R:RW:0: */


/*
 * 1-> Disable  VIN comparator 3
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_VINCOMP3_PD             (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 1-> Disable  VIN comparator 4
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_VINCOMP4_PD             (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 1-> Disable  VIN comparator 5
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_VINCOMP5_PD             (1UL << 11) /* <11:11> R:RW:0: */


/*
 * config to cancel turn ratio (33 FOR N:7)
 * Turn ratio : CONFIG
 * 3  : 53
 * 4 : 36
 * 5 : 25
 * 6 : 41
 * 7 : 33 (in funtional/operational mode)
 * 8 : 27
 * 9 : 22
 * 10 : 18
 * 11 : 15
 * 12 : 12
 * 13 : 10
 * 14 : 8
 * 15 : 6
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_IFF_CONFIG_MASK         (0x0003f000UL) /* <12:17> R:RW:33: */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_IFF_CONFIG_POS          (12UL)


/*
 * To configure integration current for different frequency
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_INTEG_CONFIG_MASK       (0x03fc0000UL) /* <18:25> R:RW:19: */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_INTEG_CONFIG_POS        (18UL)


/*
 * Option to increase reset comparator trip point
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_INTEG_RESET_CONFIG_MASK    (0x1c000000UL) /* <26:28> R:RW:0: */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_INTEG_RESET_CONFIG_POS    (26UL)


/*
 * Option to change minimum feedfwd current
 * 0  -> 1.4uA (in funtional/operational mode)
 * 1 ->  1.6uA
 * 2 -> 1uA
 * 3 -> 1.2uA
 * 4 -> 2.2uA
 * 5 -> 2.4uA
 * 6 -> 1.8uA
 * 7 -> 2uA
 */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_MIN_IFF_CONFIG_MASK     (0xe0000000UL) /* <29:31> R:RW:0: */
#define PDSS_FEEDFWD_1_CTRL_FEEDFWD_MIN_IFF_CONFIG_POS      (29UL)


/*
 * Feed Forward 2 Control Register
 */
#define PDSS_FEEDFWD_2_CTRL_ADDRESS                         (0x400a2580UL)
#define PDSS_FEEDFWD_2_CTRL                                 (*(volatile uint32_t *)(0x400a2580UL))
#define PDSS_FEEDFWD_2_CTRL_DEFAULT                         (0x0200c200UL)

/*
 * External reset input
 * 1-> release cap
 * 0-> short cap
 */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_INTEG_RESETB_IN         (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Integrator - Select external reset during trim
 * 1 -> reset cap with external input (in Trim mode)
 * 0-> reset with internal comparator (in funtional/operational mode)
 */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_INTEG_SEL_EXT_RESET     (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable integration cap trim
 * 0-> in functional
 * 1-> in trim mode
 */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_INTEG_CAP_TRIM_EN       (1UL << 2) /* <2:2> R:RW:0: */


/*
 * 1-> disable leakge on nbias of V2I diode
 */
#define PDSS_FEEDFWD_2_CTRL_DIS_FEEDFWD_NBIAS_LKG           (1UL << 3) /* <3:3> R:RW:0: */


/*
 * 1-> disable sample hold voltage clamp
 */
#define PDSS_FEEDFWD_2_CTRL_DIS_FFWD_SAMPLEHOLD_CLAMP       (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Enable/disable option for internal vref plan
 * 1-> disable internal vbus dependent vref
 * 0-> enable internal vbus dependent vref
 */
#define PDSS_FEEDFWD_2_CTRL_DIS_FFWD_INT_VREF               (1UL << 5) /* <5:5> R:RW:0: */


/*
 * 1-> integ_out will be latched; by default integ_out is not latched (0)
 */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_INTEG_SEL_LATCH_PATH    (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Option to change minimum vref
 */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_INT_MIN_VREF_CONFIG_MASK    (0x00000300UL) /* <8:9> R:RW:2: */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_INT_MIN_VREF_CONFIG_POS    (8UL)


/*
 * Option to change vref slope with respect to VBUS
 */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_INT_VREF_SLP_CONFIG_MASK    (0x00000c00UL) /* <10:11> R:RW:0: */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_INT_VREF_SLP_CONFIG_POS    (10UL)


/*
 * I_FF linearity config (12 for N:7)
 * Turn ratio : CONFIG
 * 3  : 6
 * 4 : 7
 * 5 : 8
 * 6 : 11
 * 7 : 12 (in funtional/operational mode)
 * 8 : 14
 * 9 : 15
 * 10 : 16
 * 11 : 17
 * 12 : 18
 * 13 : 21
 * 14 : 22
 * 15 : 23
 */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_ICOMP_CONFIG_MASK       (0x0003f000UL) /* <12:17> R:RW:12: */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_ICOMP_CONFIG_POS        (12UL)


/*
 * I_FF multiply range from 1.5X to 4.5X
 * 0 : 1X (in funtional/operational mode)
 * 1 : 1.5X
 * 2 : 2X
 * 3 : 2.5X
 * 4 : 3X
 * 5 : 3.5X
 * 6 : 4X (in trim mode)
 * 7 :4.5X
 */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_IFF_SEL_IMULT_MASK      (0x001c0000UL) /* <18:20> R:RW:0: */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_IFF_SEL_IMULT_POS       (18UL)


/*
 * unused
 */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_SPARE_MASK              (0x01e00000UL) /* <21:24> R:RW:0: */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_SPARE_POS               (21UL)


/*
 * Controls the assertion delay of "feedfwd_sw_en" signal from ptdrv_in pos-edge.
 * Used in Low Frequency Mode.
 */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_SW_EN_ON_DLY_LFM_MASK    (0x7e000000UL) /* <25:30> R:RW:1: */
#define PDSS_FEEDFWD_2_CTRL_FEEDFWD_SW_EN_ON_DLY_LFM_POS    (25UL)


/*
 * Bandgap reference Control Register
 */
#define PDSS_BG_REF_CTRL_ADDRESS                            (0x400a2584UL)
#define PDSS_BG_REF_CTRL                                    (*(volatile uint32_t *)(0x400a2584UL))
#define PDSS_BG_REF_CTRL_DEFAULT                            (0x00000000UL)

/*
 * ADFT control signals
 * 000 : adft[0] = Hi-Z                      ; adft[1] = Hi-Z
 * 001 : adft[0] = vbg_1p25            ; adft[1] = Hi-Z
 * 010 : adft[0] = vref_1p2              ; adft[1] = Hi-Z
 * 011 : adft[0] = UGB_vref_out     ; adft[1] = adft_vref_in
 * 100 : adft[0] = UGB_vref_in       ; adft[1] = adft_vref_in
 * 101 : adft[0] = UGB_vref_out     ; adft[1] = Hi-Z
 * 110 : adft[0] = Hi-Z                      ; adft[1] = Hi-Z
 * 111 : adft[0] = Hi-Z                      ; adft[1] = Hi-Z
 */
#define PDSS_BG_REF_CTRL_BG_ADFT_CTRL_MASK                  (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_BG_REF_CTRL_BG_ADFT_CTRL_POS                   (0UL)


/*
 * Enable signal for BG core
 * 0 : BG core is disabled
 * 1 : BG core is enabled
 */
#define PDSS_BG_REF_CTRL_EN_BG                              (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Selection bit to bypass 2.1V UGB
 * 0 : 2.1V output is driven through UGB
 * 1 : 2.1V UGB is bypassed
 */
#define PDSS_BG_REF_CTRL_SEL_VREF_OUT                       (1UL << 4) /* <4:4> R:RW:0: */


/*
 *  Spare config bits (UNUSED)
 */
#define PDSS_BG_REF_CTRL_BG_CONFIG_MASK                     (0x000000e0UL) /* <5:7> R:RW:0: */
#define PDSS_BG_REF_CTRL_BG_CONFIG_POS                      (5UL)


/*
 * Enabled signal for 2.1V UGB
 * 0 : UGB is disabled
 * 1 : UGB is enabled (Required in Bypass mode also)
 */
#define PDSS_BG_REF_CTRL_EN_BG_UGB                          (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Test mode bit to select vref_0p74 as input reference for UGB
 * 0 : UGB input reference is vref_2p1
 * 1 : UGB input reference is vref_0p74 (Used to measure vref_0p74 through
 * ADFT)
 */
#define PDSS_BG_REF_CTRL_SEL_VREFIN_0P74                    (1UL << 9) /* <9:9> R:RW:0: */


/*
 * PASC-PWM Control Register 3
 */
#define PDSS_PASC_PWM_3_CTRL_ADDRESS                        (0x400a2588UL)
#define PDSS_PASC_PWM_3_CTRL                                (*(volatile uint32_t *)(0x400a2588UL))
#define PDSS_PASC_PWM_3_CTRL_DEFAULT                        (0x20000780UL)

/*
 * Minimum pulse width of burst pulse. Used in Low Frequency mode only. Used
 * in Low Frequency Mode.
 */
#define PDSS_PASC_PWM_3_CTRL_BURST_MIN_WIDTH_LFM_MASK       (0x0000007fUL) /* <0:6> R:RW:0: */
#define PDSS_PASC_PWM_3_CTRL_BURST_MIN_WIDTH_LFM_POS        (0UL)


/*
 * Burst frequency. Used in Low frequency mode only. Used in Low Frequency
 * Mode.
 */
#define PDSS_PASC_PWM_3_CTRL_BURST_FREQ_LFM_MASK            (0x000fff80UL) /* <7:19> R:RW:15: */
#define PDSS_PASC_PWM_3_CTRL_BURST_FREQ_LFM_POS             (7UL)


/*
 * Burst pulse width incremental delta value. Used in Low Frequency Mode.
 */
#define PDSS_PASC_PWM_3_CTRL_BURST_INCR_VAL_LFM_MASK        (0x01f00000UL) /* <20:24> R:RW:0: */
#define PDSS_PASC_PWM_3_CTRL_BURST_INCR_VAL_LFM_POS         (20UL)


/*
 * Enable Fixed-Freq mode in Constant-current (CC) mode, if Dynamic-switching
 * is enabled (FF-QR)
 */
#define PDSS_PASC_PWM_3_CTRL_EN_FF_MODE_IN_CC               (1UL << 29) /* <29:29> R:RW:1: */


/*
 * 1: With VINCOMP5 pos-edge; PASC will be moved to IDLE mode
 */
#define PDSS_PASC_PWM_3_CTRL_EN_SRSEN_PULLDN_PASC_HW_DIS    (1UL << 30) /* <30:30> R:RW:0: */


/*
 * 1: With Vreg inrush detect; PASC will be moved to IDLE mode
 */
#define PDSS_PASC_PWM_3_CTRL_EN_VREG_INRUSH_PASC_HW_DIS     (1UL << 31) /* <31:31> R:RW:0: */


/*
 * PASC-PWM Control Register 4
 */
#define PDSS_PASC_PWM_4_CTRL_ADDRESS                        (0x400a258cUL)
#define PDSS_PASC_PWM_4_CTRL                                (*(volatile uint32_t *)(0x400a258cUL))
#define PDSS_PASC_PWM_4_CTRL_DEFAULT                        (0x00002a01UL)

/*
 * Minimum Pulse width of "ptdrv_in" signal. This register has a shadow register
 * in logic. Used in Low Frequency Mode.
 */
#define PDSS_PASC_PWM_4_CTRL_PTDRV_IN_MIN_WIDTH_LFM_MASK    (0x0000007fUL) /* <0:6> R:RW:1: */
#define PDSS_PASC_PWM_4_CTRL_PTDRV_IN_MIN_WIDTH_LFM_POS     (0UL)


/*
 * Maximum Pulse width of "ptdrv_in" signal. This register has a shadow register
 * in logic. Used in Low Frequency Mode.
 */
#define PDSS_PASC_PWM_4_CTRL_PTDRV_IN_MAX_WIDTH_LFM_MASK    (0x0003ff80UL) /* <7:17> R:RW:84: */
#define PDSS_PASC_PWM_4_CTRL_PTDRV_IN_MAX_WIDTH_LFM_POS     (7UL)


/*
 * Enables Dithering of PTDRV_IN_MAX_WIDTH based on FF dithering
 */
#define PDSS_PASC_PWM_4_CTRL_PTDRV_IN_MAX_WIDTH_DITH_EN     (1UL << 18) /* <18:18> R:RW:0: */


/*
 * PASC-PWM Control Register 5
 */
#define PDSS_PASC_PWM_5_CTRL_ADDRESS                        (0x400a2590UL)
#define PDSS_PASC_PWM_5_CTRL                                (*(volatile uint32_t *)(0x400a2590UL))
#define PDSS_PASC_PWM_5_CTRL_DEFAULT                        (0x09600050UL)

/*
 * Burst frequency.
 */
#define PDSS_PASC_PWM_5_CTRL_BURST_PULSE_FREQ_MASK          (0x00001fffUL) /* <0:12> R:RW:80: */
#define PDSS_PASC_PWM_5_CTRL_BURST_PULSE_FREQ_POS           (0UL)


/*
 * Burst repeat deay including the last burst pulse in the repeat cycle.
 */
#define PDSS_PASC_PWM_5_CTRL_BURST_REPEAT_DELAY_MASK        (0xffff0000UL) /* <16:31> R:RW:2400: */
#define PDSS_PASC_PWM_5_CTRL_BURST_REPEAT_DELAY_POS         (16UL)


/*
 * PASC-PWM Control Register 6
 */
#define PDSS_PASC_PWM_6_CTRL_ADDRESS                        (0x400a2594UL)
#define PDSS_PASC_PWM_6_CTRL                                (*(volatile uint32_t *)(0x400a2594UL))
#define PDSS_PASC_PWM_6_CTRL_DEFAULT                        (0x012c0003UL)

/*
 * Number of Burst pulses in a repeat cycle.
 */
#define PDSS_PASC_PWM_6_CTRL_BURST_PULSE_NUM_MASK           (0x0000000fUL) /* <0:3> R:RW:3: */
#define PDSS_PASC_PWM_6_CTRL_BURST_PULSE_NUM_POS            (0UL)


/*
 * Burst repeat deay including the last burst pulse in the repeat cycle.
 * Used in Low Frequency Mode.
 */
#define PDSS_PASC_PWM_6_CTRL_BURST_REPEAT_DELAY_LFM_MASK    (0xffff0000UL) /* <16:31> R:RW:300: */
#define PDSS_PASC_PWM_6_CTRL_BURST_REPEAT_DELAY_LFM_POS     (16UL)


/*
 * PASC Status registers 5
 */
#define PDSS_PASC_STATUS_5_ADDRESS                          (0x400a2598UL)
#define PDSS_PASC_STATUS_5                                  (*(volatile uint32_t *)(0x400a2598UL))
#define PDSS_PASC_STATUS_5_DEFAULT                          (0x00000000UL)

/*
 * NSN_EN to (nsn_out or nsn_out_timeout) delay
 */
#define PDSS_PASC_STATUS_5_NSN_WAIT_TIME_MASK               (0x00000fffUL) /* <0:11> RW:R:0:PASC2_EN */
#define PDSS_PASC_STATUS_5_NSN_WAIT_TIME_POS                (0UL)


/*
 * Stores the last measured HIP "peak to peak" delay.
 */
#define PDSS_PASC_STATUS_5_HIP_PEAK2PEAK_MASK               (0x001ff000UL) /* <12:20> RW:R:0:PASC2_EN */
#define PDSS_PASC_STATUS_5_HIP_PEAK2PEAK_POS                (12UL)


/*
 * PASC Status registers 6
 */
#define PDSS_PASC_STATUS_6_ADDRESS                          (0x400a259cUL)
#define PDSS_PASC_STATUS_6                                  (*(volatile uint32_t *)(0x400a259cUL))
#define PDSS_PASC_STATUS_6_DEFAULT                          (0x00000000UL)

/*
 * Stores the Frequency Dithering offset
 */
#define PDSS_PASC_STATUS_6_DITH_FF_OFFSET_MASK              (0x0000007fUL) /* <0:6> RW:R:0:PASC2_EN */
#define PDSS_PASC_STATUS_6_DITH_FF_OFFSET_POS               (0UL)


/*
 * Stores the Frequency Dithering offset addition/subtraction polarity
 */
#define PDSS_PASC_STATUS_6_DITH_FF_OFFSET_DIR               (1UL << 7) /* <7:7> RW:R:0:PASC2_EN */


/*
 * Stores the PWM Cap Dithering offset
 */
#define PDSS_PASC_STATUS_6_DITH_CAP_OFFSET_MASK             (0x00007f00UL) /* <8:14> RW:R:0:PASC2_EN */
#define PDSS_PASC_STATUS_6_DITH_CAP_OFFSET_POS              (8UL)


/*
 * Stores the PWM Cap Dithering offset addition/subtraction polarity
 */
#define PDSS_PASC_STATUS_6_DITH_CAP_OFFSET_DIR              (1UL << 15) /* <15:15> RW:R:0:PASC2_EN */


/*
 * PASC Status registers 7
 */
#define PDSS_PASC_STATUS_7_ADDRESS                          (0x400a25a0UL)
#define PDSS_PASC_STATUS_7                                  (*(volatile uint32_t *)(0x400a25a0UL))
#define PDSS_PASC_STATUS_7_DEFAULT                          (0x00000000UL)

/*
 * Stores the TLOOP ACF ON calibration data.
 */
#define PDSS_PASC_STATUS_7_TLOOP_ACF_ON_MASK                (0x0000001fUL) /* <0:4> RW:R:0:PASC2_EN */
#define PDSS_PASC_STATUS_7_TLOOP_ACF_ON_POS                 (0UL)


/*
 * Stores the TLOOP ACF OFF calibration data.
 */
#define PDSS_PASC_STATUS_7_TLOOP_ACF_OFF_MASK               (0x000003e0UL) /* <5:9> RW:R:0:PASC2_EN */
#define PDSS_PASC_STATUS_7_TLOOP_ACF_OFF_POS                (5UL)


/*
 * Stores the TLOOP ACF calibration success status. This should be read after
 * the ACF_CAL_EN is cleared by the HW indicating ACF calibration completion.
 */
#define PDSS_PASC_STATUS_7_TLOOP_ACF_CAL_NSN_OUT_FAIL       (1UL << 10) /* <10:10> RW1S:RW1C:0:PASC2_EN */


/*
 * Stores the TLOOP ACF calibration success status. This should be read after
 * the ACF_CAL_EN is cleared by the HW indicating ACF calibration completion.
 */
#define PDSS_PASC_STATUS_7_TLOOP_ACF_CAL_ZCDF_OUT_FAIL      (1UL << 11) /* <11:11> RW1S:RW1C:0:PASC2_EN */


/*
 * Stores theDT MASK calibration success status. This should be read after
 * the DT_CAL_EN is cleared by the HW indicating DT Mask calibration completion.
 */
#define PDSS_PASC_STATUS_7_DT_MASK_CAL_FAIL                 (1UL << 13) /* <13:13> RW1S:RW1C:0:PASC2_EN */


/*
 * Stores the DT Mask calibration data (ACF_IN Negedge tp FF_integ_resetb
 * delay).
 */
#define PDSS_PASC_STATUS_7_DT_MASK_MEAS1_MASK               (0x00ff0000UL) /* <16:23> RW:R:0:PASC2_EN */
#define PDSS_PASC_STATUS_7_DT_MASK_MEAS1_POS                (16UL)


/*
 * Stores the DT Mask calibration data (ACF_IN Negedge tp FF_integ_resetb
 * delay).
 */
#define PDSS_PASC_STATUS_7_DT_MASK_MEAS2_MASK               (0xff000000UL) /* <24:31> RW:R:0:PASC2_EN */
#define PDSS_PASC_STATUS_7_DT_MASK_MEAS2_POS                (24UL)


/*
 * SR GDRV Control Register 2
 */
#define PDSS_SRGDRV_2_CTRL_ADDRESS                          (0x400a25a4UL)
#define PDSS_SRGDRV_2_CTRL                                  (*(volatile uint32_t *)(0x400a25a4UL))
#define PDSS_SRGDRV_2_CTRL_DEFAULT                          (0x000c1503UL)

/*
 * Minimum Pulse Width of "gdrv_in". This register has a shadow register
 * in Logic. Used in Low Frequency Mode.
 */
#define PDSS_SRGDRV_2_CTRL_GDRV_IN_MIN_WIDTH_LFM_MASK       (0x0000003fUL) /* <0:5> R:RW:3: */
#define PDSS_SRGDRV_2_CTRL_GDRV_IN_MIN_WIDTH_LFM_POS        (0UL)


/*
 * Maximum Pulse Width of "gdrv_in". Used in Low Frequency Mode.
 */
#define PDSS_SRGDRV_2_CTRL_GDRV_IN_MAX_WIDTH_LFM_MASK       (0x0003ffc0UL) /* <6:17> R:RW:84: */
#define PDSS_SRGDRV_2_CTRL_GDRV_IN_MAX_WIDTH_LFM_POS        (6UL)


/*
 * Secondary SR gate turn-on pulse-Width below which GDRV will be turned-off
 * in next cycle. The secondary width is measured as the time from NSN triggering
 * to ZCD or ZCDF  (whichever comes earlier) triggering. This register has
 * a shadow register in Logic. Used in Low Frequency Mode.
 */
#define PDSS_SRGDRV_2_CTRL_GDRV_IN_TURN_OFF_WIDTH_LFM_MASK    (0x01fc0000UL) /* <18:24> R:RW:3: */
#define PDSS_SRGDRV_2_CTRL_GDRV_IN_TURN_OFF_WIDTH_LFM_POS    (18UL)


/*
 * Override Register.
 * 1 - FW Override Enabled. GDRV_IN_ZVS_OVR_VAL is driven on gdrv_in_zvs
 */
#define PDSS_SRGDRV_2_CTRL_GDRV_IN_ZVS_OVR                  (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Override Value for "gdrv_in_zvs" Signal
 */
#define PDSS_SRGDRV_2_CTRL_GDRV_IN_ZVS_OVR_VAL              (1UL << 26) /* <26:26> R:RW:0: */


/*
 * SR GDRV Control Register 3
 */
#define PDSS_SRGDRV_3_CTRL_ADDRESS                          (0x400a25a8UL)
#define PDSS_SRGDRV_3_CTRL                                  (*(volatile uint32_t *)(0x400a25a8UL))
#define PDSS_SRGDRV_3_CTRL_DEFAULT                          (0x0000814eUL)

/*
 * Minimum is 2.;Timer for which is SRGDRV is not turned on, it would not
 * get turned on for next GDRV_IN_MASK_NUM switching cycles. Working on LF
 * clock. The programmed minimum value should not be less than 6.
 */
#define PDSS_SRGDRV_3_CTRL_GDRV_IN_LONG_TIM_MASK            (0x000003ffUL) /* <0:9> R:RW:334: */
#define PDSS_SRGDRV_3_CTRL_GDRV_IN_LONG_TIM_POS             (0UL)


/*
 * No of switching cycles for which SRGDRV will remain off post GDRV_IN_LONG_TIM
 * timer expiry
 */
#define PDSS_SRGDRV_3_CTRL_GDRV_IN_MASK_NUM_MASK            (0x0000e000UL) /* <13:15> R:RW:4: */
#define PDSS_SRGDRV_3_CTRL_GDRV_IN_MASK_NUM_POS             (13UL)


/*
 * To enable GDRVIN long masking
 */
#define PDSS_SRGDRV_3_CTRL_EN_GDRV_IN_MASK                  (1UL << 31) /* <31:31> R:RW:0: */


/*
 * PEAK Generator Control Register 4
 */
#define PDSS_PEAKGEN_3_CTRL_ADDRESS                         (0x400a25acUL)
#define PDSS_PEAKGEN_3_CTRL                                 (*(volatile uint32_t *)(0x400a25acUL))
#define PDSS_PEAKGEN_3_CTRL_DEFAULT                         (0x00001806UL)

/*
 * Controls the "peak to peak" delay. This register has a shadow in logic.
 * Used in Low Frequency Mode.
 */
#define PDSS_PEAKGEN_3_CTRL_PEAK2PEAK_DLY_LFM_MASK          (0x000001ffUL) /* <0:8> R:RW:6: */
#define PDSS_PEAKGEN_3_CTRL_PEAK2PEAK_DLY_LFM_POS           (0UL)


/*
 * Indicates the time between "zcd_out" encountered to the first peak. This
 * is used if full digital scheme of peak generation is used. This register
 * has a shadow in logic. Used in Low Frequency Mode.
 */
#define PDSS_PEAKGEN_3_CTRL_ZCD_TO_PEAK_TIME_LFM_MASK       (0x000ff800UL) /* <11:19> R:RW:3: */
#define PDSS_PEAKGEN_3_CTRL_ZCD_TO_PEAK_TIME_LFM_POS        (11UL)


/*
 * SRSENSE HardIP CLK_LF Filter and Edge detector configuration for Feedfwd_vincomp1
 * and Feedfwd_vincomp2
 */
#define PDSS_INTR19_CFG_0_ADDRESS                           (0x400a25b0UL)
#define PDSS_INTR19_CFG_0                                   (*(volatile uint32_t *)(0x400a25b0UL))
#define PDSS_INTR19_CFG_0_DEFAULT                           (0x00200400UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP1_FILT_EN                (1UL << 0) /* <0:0> R:RW:0:PASC2_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP1_FILT_CFG_MASK          (0x00000006UL) /* <1:2> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_0_FF_VINCMP1_FILT_CFG_POS           (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP1_FILT_RESET             (1UL << 3) /* <3:3> R:RW:0:PASC2_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP1_FILT_BYPASS            (1UL << 4) /* <4:4> R:RW:0:PASC2_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP1_FILT_SEL_MASK          (0x000003e0UL) /* <5:9> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_0_FF_VINCMP1_FILT_SEL_POS           (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP1_DPSLP_MODE             (1UL << 10) /* <10:10> R:RW:1:PASC2_EN */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP2_FILT_EN                (1UL << 11) /* <11:11> R:RW:0:PASC2_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP2_FILT_CFG_MASK          (0x00003000UL) /* <12:13> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_0_FF_VINCMP2_FILT_CFG_POS           (12UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP2_FILT_RESET             (1UL << 14) /* <14:14> R:RW:0:PASC2_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP2_FILT_BYPASS            (1UL << 15) /* <15:15> R:RW:0:PASC2_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP2_FILT_SEL_MASK          (0x001f0000UL) /* <16:20> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_0_FF_VINCMP2_FILT_SEL_POS           (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR19_CFG_0_FF_VINCMP2_DPSLP_MODE             (1UL << 21) /* <21:21> R:RW:1:PASC2_EN */


/*
 * SRSENSE HardIP CLK_LF Filter and Edge detector configuration for Feedfwd_vincomp3
 * and Feedfwd_vincomp4
 */
#define PDSS_INTR19_CFG_1_ADDRESS                           (0x400a25b4UL)
#define PDSS_INTR19_CFG_1                                   (*(volatile uint32_t *)(0x400a25b4UL))
#define PDSS_INTR19_CFG_1_DEFAULT                           (0x00200400UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP3_FILT_EN                (1UL << 0) /* <0:0> R:RW:0:PASC2_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP3_FILT_CFG_MASK          (0x00000006UL) /* <1:2> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_1_FF_VINCMP3_FILT_CFG_POS           (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP3_FILT_RESET             (1UL << 3) /* <3:3> R:RW:0:PASC2_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP3_FILT_BYPASS            (1UL << 4) /* <4:4> R:RW:0:PASC2_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP3_FILT_SEL_MASK          (0x000003e0UL) /* <5:9> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_1_FF_VINCMP3_FILT_SEL_POS           (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP3_DPSLP_MODE             (1UL << 10) /* <10:10> R:RW:1:PASC2_EN */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP4_FILT_EN                (1UL << 11) /* <11:11> R:RW:0:PASC2_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP4_FILT_CFG_MASK          (0x00003000UL) /* <12:13> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_1_FF_VINCMP4_FILT_CFG_POS           (12UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP4_FILT_RESET             (1UL << 14) /* <14:14> R:RW:0:PASC2_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP4_FILT_BYPASS            (1UL << 15) /* <15:15> R:RW:0:PASC2_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP4_FILT_SEL_MASK          (0x001f0000UL) /* <16:20> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_1_FF_VINCMP4_FILT_SEL_POS           (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR19_CFG_1_FF_VINCMP4_DPSLP_MODE             (1UL << 21) /* <21:21> R:RW:1:PASC2_EN */


/*
 * SRSENSE HardIP CLK_LF Filter and Edge detector configuration for Feedfwd_vincomp5
 */
#define PDSS_INTR19_CFG_2_ADDRESS                           (0x400a25b8UL)
#define PDSS_INTR19_CFG_2                                   (*(volatile uint32_t *)(0x400a25b8UL))
#define PDSS_INTR19_CFG_2_DEFAULT                           (0x00000400UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR19_CFG_2_FF_VINCMP5_FILT_EN                (1UL << 0) /* <0:0> R:RW:0:PASC2_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR19_CFG_2_FF_VINCMP5_FILT_CFG_MASK          (0x00000006UL) /* <1:2> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_2_FF_VINCMP5_FILT_CFG_POS           (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR19_CFG_2_FF_VINCMP5_FILT_RESET             (1UL << 3) /* <3:3> R:RW:0:PASC2_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR19_CFG_2_FF_VINCMP5_FILT_BYPASS            (1UL << 4) /* <4:4> R:RW:0:PASC2_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR19_CFG_2_FF_VINCMP5_FILT_SEL_MASK          (0x000003e0UL) /* <5:9> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_2_FF_VINCMP5_FILT_SEL_POS           (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR19_CFG_2_FF_VINCMP5_DPSLP_MODE             (1UL << 10) /* <10:10> R:RW:1:PASC2_EN */


/*
 * CHGDET HardIP CLK_LF Filter and Edge detector configuration for dm_ovp_comp_out
 * and dp_ovp_comp_out
 */
#define PDSS_INTR19_CFG_3_ADDRESS                           (0x400a25bcUL)
#define PDSS_INTR19_CFG_3                                   (*(volatile uint32_t *)(0x400a25bcUL))
#define PDSS_INTR19_CFG_3_DEFAULT                           (0x00200400UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR19_CFG_3_DP_OVP_COMP_OUT_FILT_EN           (1UL << 0) /* <0:0> R:RW:0:PASC2_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR19_CFG_3_DP_OVP_COMP_OUT_FILT_CFG_MASK     (0x00000006UL) /* <1:2> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_3_DP_OVP_COMP_OUT_FILT_CFG_POS      (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR19_CFG_3_DP_OVP_COMP_OUT_FILT_RESET        (1UL << 3) /* <3:3> R:RW:0:PASC2_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR19_CFG_3_DP_OVP_COMP_OUT_FILT_BYPASS       (1UL << 4) /* <4:4> R:RW:0:PASC2_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR19_CFG_3_DP_OVP_COMP_OUT_FILT_SEL_MASK     (0x000003e0UL) /* <5:9> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_3_DP_OVP_COMP_OUT_FILT_SEL_POS      (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR19_CFG_3_DP_OVP_COMP_OUT_DPSLP_MODE        (1UL << 10) /* <10:10> R:RW:1:PASC2_EN */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR19_CFG_3_DM_OVP_COMP_OUT_FILT_EN           (1UL << 11) /* <11:11> R:RW:0:PASC2_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR19_CFG_3_DM_OVP_COMP_OUT_FILT_CFG_MASK     (0x00003000UL) /* <12:13> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_3_DM_OVP_COMP_OUT_FILT_CFG_POS      (12UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR19_CFG_3_DM_OVP_COMP_OUT_FILT_RESET        (1UL << 14) /* <14:14> R:RW:0:PASC2_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR19_CFG_3_DM_OVP_COMP_OUT_FILT_BYPASS       (1UL << 15) /* <15:15> R:RW:0:PASC2_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR19_CFG_3_DM_OVP_COMP_OUT_FILT_SEL_MASK     (0x001f0000UL) /* <16:20> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_3_DM_OVP_COMP_OUT_FILT_SEL_POS      (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR19_CFG_3_DM_OVP_COMP_OUT_DPSLP_MODE        (1UL << 21) /* <21:21> R:RW:1:PASC2_EN */


/*
 * CHGDET HardIP CLK_LF Filter and Edge detector configuration for dmdp_imp_comp_out
 */
#define PDSS_INTR19_CFG_4_ADDRESS                           (0x400a25c0UL)
#define PDSS_INTR19_CFG_4                                   (*(volatile uint32_t *)(0x400a25c0UL))
#define PDSS_INTR19_CFG_4_DEFAULT                           (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR19_CFG_4_DPDM_IMP_COMP_OUT_FILT_EN         (1UL << 0) /* <0:0> R:RW:0:PASC2_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR19_CFG_4_DPDM_IMP_COMP_OUT_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_4_DPDM_IMP_COMP_OUT_FILT_CFG_POS    (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR19_CFG_4_DPDM_IMP_COMP_OUT_FILT_RESET      (1UL << 3) /* <3:3> R:RW:0:PASC2_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR19_CFG_4_DPDM_IMP_COMP_OUT_FILT_BYPASS     (1UL << 4) /* <4:4> R:RW:0:PASC2_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR19_CFG_4_DPDM_IMP_COMP_OUT_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_4_DPDM_IMP_COMP_OUT_FILT_SEL_POS    (5UL)


/*
 * SRSENSE HardIP CLK_PASC Filter and Edge detector configuration for FEEDFWD_INTEG_OUT
 * and FEEDFWD_INTEG_RESETB detection
 */
#define PDSS_INTR19_CFG_5_ADDRESS                           (0x400a25c4UL)
#define PDSS_INTR19_CFG_5                                   (*(volatile uint32_t *)(0x400a25c4UL))
#define PDSS_INTR19_CFG_5_DEFAULT                           (0x00208410UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_OUT_FILT_EN              (1UL << 0) /* <0:0> R:RW:0:PASC2_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_OUT_FILT_CFG_MASK        (0x00000006UL) /* <1:2> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_5_FF_INTEG_OUT_FILT_CFG_POS         (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_OUT_FILT_RESET           (1UL << 3) /* <3:3> R:RW:0:PASC2_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_OUT_FILT_BYPASS          (1UL << 4) /* <4:4> R:RW:1:PASC2_EN */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_OUT_FILT_SEL_MASK        (0x000003e0UL) /* <5:9> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_5_FF_INTEG_OUT_FILT_SEL_POS         (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_OUT_DPSLP_MODE           (1UL << 10) /* <10:10> R:RW:1:PASC2_EN */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_RESETB_OUT_FILT_EN       (1UL << 11) /* <11:11> R:RW:0:PASC2_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_RESETB_OUT_FILT_CFG_MASK    (0x00003000UL) /* <12:13> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_5_FF_INTEG_RESETB_OUT_FILT_CFG_POS    (12UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_RESETB_OUT_FILT_RESET    (1UL << 14) /* <14:14> R:RW:0:PASC2_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_RESETB_OUT_FILT_BYPASS    (1UL << 15) /* <15:15> R:RW:1:PASC2_EN */


/*
 * #of clock CLK_PASC filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_RESETB_OUT_FILT_SEL_MASK    (0x001f0000UL) /* <16:20> R:RW:0:PASC2_EN */
#define PDSS_INTR19_CFG_5_FF_INTEG_RESETB_OUT_FILT_SEL_POS    (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR19_CFG_5_FF_INTEG_RESETB_OUT_DPSLP_MODE    (1UL << 21) /* <21:21> R:RW:1:PASC2_EN */


/*
 * Round Robin ADC CLK_FILT[0] Filter and Edge Detector configuration
 */
#define PDSS_INTR19_CFG_6_ADDRESS                           (0x400a25c8UL)
#define PDSS_INTR19_CFG_6                                   (*(volatile uint32_t *)(0x400a25c8UL))
#define PDSS_INTR19_CFG_6_DEFAULT                           (0x00000400UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR19_CFG_6_R_ADC_CMP_OUT_FILT_EN             (1UL << 0) /* <0:0> R:RW:0:RNDRBN_ADC_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR19_CFG_6_R_ADC_CMP_OUT_FILT_CFG_MASK       (0x00000006UL) /* <1:2> R:RW:0:RNDRBN_ADC_EN */
#define PDSS_INTR19_CFG_6_R_ADC_CMP_OUT_FILT_CFG_POS        (1UL)


/*
 * This field specifies the reset value of the Filter.
 * To reset the Filter, set this bit to the appropriate value and Toggle
 * FILTER_EN.
 *   Firmware can set the values (Reset Values, Config values etc when the
 * filter_en is 0 and next cycle it can take the filter out of reset by writing
 * 1 to filter_en).
 * FILTER_EN =0 acts as an asynchronous reset. Internally when filter is
 * enabled, the deassertion of reset is synchronized and it takes 3-4 cycles.
 * So firmware should at-least wait 5 cycles for dynamically changing filter
 * values and applying reset again.
 */
#define PDSS_INTR19_CFG_6_R_ADC_CMP_OUT_FILT_RESET          (1UL << 3) /* <3:3> R:RW:0:RNDRBN_ADC_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR19_CFG_6_R_ADC_CMP_OUT_FILT_BYPASS         (1UL << 4) /* <4:4> R:RW:0:RNDRBN_ADC_EN */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR19_CFG_6_R_ADC_CMP_OUT_FILT_SEL_MASK       (0x000003e0UL) /* <5:9> R:RW:0:RNDRBN_ADC_EN */
#define PDSS_INTR19_CFG_6_R_ADC_CMP_OUT_FILT_SEL_POS        (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR19_CFG_6_R_ADC_CMP_OUT_DPSLP_MODE          (1UL << 10) /* <10:10> R:RW:1:RNDRBN_ADC_EN */


/*
 * INTR19 Status
 */
#define PDSS_INTR19_STATUS_ADDRESS                          (0x400a25ccUL)
#define PDSS_INTR19_STATUS                                  (*(volatile uint32_t *)(0x400a25ccUL))
#define PDSS_INTR19_STATUS_DEFAULT                          (0x00000000UL)

#define PDSS_INTR19_STATUS_FF_VINCMP1_STATUS                (1UL << 0) /* <0:0> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_VINCMP1_FILT                  (1UL << 1) /* <1:1> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_VINCMP2_STATUS                (1UL << 2) /* <2:2> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_VINCMP2_FILT                  (1UL << 3) /* <3:3> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_VINCMP3_STATUS                (1UL << 4) /* <4:4> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_VINCMP3_FILT                  (1UL << 5) /* <5:5> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_VINCMP4_STATUS                (1UL << 6) /* <6:6> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_VINCMP4_FILT                  (1UL << 7) /* <7:7> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_VINCMP5_STATUS                (1UL << 8) /* <8:8> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_VINCMP5_FILT                  (1UL << 9) /* <9:9> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_DM_OVP_COMP_OUT_STATUS           (1UL << 10) /* <10:10> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_DM_OVP_COMP_OUT_FILT             (1UL << 11) /* <11:11> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_DP_OVP_COMP_OUT_STATUS           (1UL << 12) /* <12:12> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_DP_OVP_COMP_OUT_FILT             (1UL << 13) /* <13:13> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_DPDM_IMP_COMP_OUT_STATUS         (1UL << 14) /* <14:14> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_DPDM_IMP_COMP_OUT_FILT           (1UL << 15) /* <15:15> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_INTEG_OUT_STATUS              (1UL << 16) /* <16:16> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_INTEG_OUT_FILT                (1UL << 17) /* <17:17> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_INTEG_RESETB_OUT_STATUS       (1UL << 18) /* <18:18> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_FF_INTEG_RESETB_OUT_FILT         (1UL << 19) /* <19:19> RW:R:0:PASC2_EN */


#define PDSS_INTR19_STATUS_R_ADC_CMP_OUT_STATUS             (1UL << 20) /* <20:20> RW:R:0:RNDRBN_ADC_EN */


#define PDSS_INTR19_STATUS_R_ADC_CMP_OUT_FILT               (1UL << 21) /* <21:21> RW:R:0:RNDRBN_ADC_EN */


/*
 * INTR19 interrupt Cause.
 */
#define PDSS_INTR19_ADDRESS                                 (0x400a25d0UL)
#define PDSS_INTR19                                         (*(volatile uint32_t *)(0x400a25d0UL))
#define PDSS_INTR19_DEFAULT                                 (0x00000000UL)

#define PDSS_INTR19_FF_VINCMP1_CHANGED                      (1UL << 0) /* <0:0> RW1S:RW1C:0:PASC2_EN */


#define PDSS_INTR19_FF_VINCMP2_CHANGED                      (1UL << 1) /* <1:1> RW1S:RW1C:0:PASC2_EN */


#define PDSS_INTR19_FF_VINCMP3_CHANGED                      (1UL << 2) /* <2:2> RW1S:RW1C:0:PASC2_EN */


#define PDSS_INTR19_FF_VINCMP4_CHANGED                      (1UL << 3) /* <3:3> RW1S:RW1C:0:PASC2_EN */


#define PDSS_INTR19_FF_VINCMP5_CHANGED                      (1UL << 4) /* <4:4> RW1S:RW1C:0:PASC2_EN */


#define PDSS_INTR19_DM_OVP_COMP_OUT_CHANGED                 (1UL << 5) /* <5:5> RW1S:RW1C:0:PASC2_EN */


#define PDSS_INTR19_DP_OVP_COMP_OUT_CHANGED                 (1UL << 6) /* <6:6> RW1S:RW1C:0:PASC2_EN */


#define PDSS_INTR19_DPDM_IMP_COMP_OUT_CHANGED               (1UL << 7) /* <7:7> RW1S:RW1C:0:PASC2_EN */


#define PDSS_INTR19_FF_INTEG_OUT_CHANGED                    (1UL << 8) /* <8:8> RW1S:RW1C:0:PASC2_EN */


#define PDSS_INTR19_FF_INTEG_RESETB_OUT_CHANGED             (1UL << 9) /* <9:9> RW1S:RW1C:0:PASC2_EN */


#define PDSS_INTR19_R_ADC_CMP_OUT_CHANGED                   (1UL << 10) /* <10:10> RW1S:RW1C:0:RNDRBN_ADC_EN */


/*
 * INTR19 Interrupt Set
 */
#define PDSS_INTR19_SET_ADDRESS                             (0x400a25d4UL)
#define PDSS_INTR19_SET                                     (*(volatile uint32_t *)(0x400a25d4UL))
#define PDSS_INTR19_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_SET_FF_VINCMP1_CHANGED                  (1UL << 0) /* <0:0> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_SET_FF_VINCMP2_CHANGED                  (1UL << 1) /* <1:1> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_SET_FF_VINCMP3_CHANGED                  (1UL << 2) /* <2:2> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_SET_FF_VINCMP4_CHANGED                  (1UL << 3) /* <3:3> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_SET_FF_VINCMP5_CHANGED                  (1UL << 4) /* <4:4> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_SET_DM_OVP_COMP_OUT_CHANGED             (1UL << 5) /* <5:5> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_SET_DP_OVP_COMP_OUT_CHANGED             (1UL << 6) /* <6:6> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_SET_DPDM_IMP_COMP_OUT_CHANGED           (1UL << 7) /* <7:7> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_SET_FF_INTEG_OUT_CHANGED                (1UL << 8) /* <8:8> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_SET_FF_INTEG_RESETB_OUT_CHANGED         (1UL << 9) /* <9:9> A:RW1S:0:PASC2_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_SET_R_ADC_CMP_OUT_CHANGED               (1UL << 10) /* <10:10> A:RW1S:0:RNDRBN_ADC_EN */


/*
 * INTR19 interrupt Mask
 */
#define PDSS_INTR19_MASK_ADDRESS                            (0x400a25d8UL)
#define PDSS_INTR19_MASK                                    (*(volatile uint32_t *)(0x400a25d8UL))
#define PDSS_INTR19_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_MASK_FF_VINCMP1_CHANGED_MASK            (1UL << 0) /* <0:0> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_MASK_FF_VINCMP2_CHANGED_MASK            (1UL << 1) /* <1:1> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_MASK_FF_VINCMP3_CHANGED_MASK            (1UL << 2) /* <2:2> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_MASK_FF_VINCMP4_CHANGED_MASK            (1UL << 3) /* <3:3> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_MASK_FF_VINCMP5_CHANGED_MASK            (1UL << 4) /* <4:4> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_MASK_DM_OVP_COMP_OUT_CHANGED_MASK       (1UL << 5) /* <5:5> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_MASK_DP_OVP_COMP_OUT_CHANGED_MASK       (1UL << 6) /* <6:6> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_MASK_DPDM_IMP_COMP_OUT_CHANGED_MASK     (1UL << 7) /* <7:7> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_MASK_FF_INTEG_OUT_CHANGED_MASK          (1UL << 8) /* <8:8> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_MASK_FF_INTEG_RESETB_OUT_CHANGED_MASK    (1UL << 9) /* <9:9> R:RW:0:PASC2_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR19_MASK_R_ADC_CMP_OUT_CHANGED_MASK         (1UL << 10) /* <10:10> R:RW:0:RNDRBN_ADC_EN */


/*
 * INTR19 interrupt Masked
 */
#define PDSS_INTR19_MASKED_ADDRESS                          (0x400a25dcUL)
#define PDSS_INTR19_MASKED                                  (*(volatile uint32_t *)(0x400a25dcUL))
#define PDSS_INTR19_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR19_MASKED_FF_VINCMP1_CHANGED_MASKED        (1UL << 0) /* <0:0> RW:R:0:PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR19_MASKED_FF_VINCMP2_CHANGED_MASKED        (1UL << 1) /* <1:1> RW:R:0:PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR19_MASKED_FF_VINCMP3_CHANGED_MASKED        (1UL << 2) /* <2:2> RW:R:0:PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR19_MASKED_FF_VINCMP4_CHANGED_MASKED        (1UL << 3) /* <3:3> RW:R:0:PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR19_MASKED_FF_VINCMP5_CHANGED_MASKED        (1UL << 4) /* <4:4> RW:R:0:PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR19_MASKED_DM_OVP_COMP_OUT_CHANGED_MASKED    (1UL << 5) /* <5:5> RW:R:0:PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR19_MASKED_DP_OVP_COMP_OUT_CHANGED_MASKED    (1UL << 6) /* <6:6> RW:R:0:PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR19_MASKED_DPDM_IMP_COMP_OUT_CHANGED_MASKED    (1UL << 7) /* <7:7> RW:R:0:PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR19_MASKED_FF_INTEG_OUT_CHANGED_MASKED      (1UL << 8) /* <8:8> RW:R:0:PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR19_MASKED_FF_INTEG_RESETB_OUT_CHANGED_MASKED    (1UL << 9) /* <9:9> RW:R:0:PASC2_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR19_MASKED_R_ADC_CMP_OUT_CHANGED_MASKED     (1UL << 10) /* <10:10> RW:R:0:RNDRBN_ADC_EN */


/*
 * DDFT Mux for PAG2S Hard-Ip Signals
 */
#define PDSS_PAG2S_NCELL_DDFT_MUX_ADDRESS                   (0x400a25e0UL)
#define PDSS_PAG2S_NCELL_DDFT_MUX                           (*(volatile uint32_t *)(0x400a25e0UL))
#define PDSS_PAG2S_NCELL_DDFT_MUX_DEFAULT                   (0x00000000UL)

/*
 * 11 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srgdrv_top.srgdrv_ddft_out
 * 10 : MXUSBPD_HIP_TOP_INST.y_vconn40_u_s8usbpd_40vconn_top.scp_cc2
 * 09 : MXUSBPD_HIP_TOP_INST.y_vconn40_u_s8usbpd_40vconn_top.scp_cc1
 * 08 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_vincomp1_out
 * 07 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_vincomp2_out
 * 06 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_vincomp3_out
 * 05 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_vincomp4_out
 * 04 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_vincomp5_out
 * 03 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.ddft_out
 * 02 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_integ_out
 * 01 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_integ_resetb_out
 * 00 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_integ_resetb_in
 */
#define PDSS_PAG2S_NCELL_DDFT_MUX_PAG2S_NCELL_DDFT0_SEL_MASK    (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_PAG2S_NCELL_DDFT_MUX_PAG2S_NCELL_DDFT0_SEL_POS    (0UL)


/*
 * 0: The selected output is not inverted
 * 1: The selected out is inverted
 */
#define PDSS_PAG2S_NCELL_DDFT_MUX_PAG2S_NCELL_DDFT0_POLARITY    (1UL << 6) /* <6:6> R:RW:0: */


/*
 * 11 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srgdrv_top.srgdrv_ddft_out
 * 10 : MXUSBPD_HIP_TOP_INST.y_vconn40_u_s8usbpd_40vconn_top.scp_cc2
 * 09 : MXUSBPD_HIP_TOP_INST.y_vconn40_u_s8usbpd_40vconn_top.scp_cc1
 * 08 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_vincomp1_out
 * 07 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_vincomp2_out
 * 06 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_vincomp3_out
 * 05 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_vincomp4_out
 * 04 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_vincomp5_out
 * 03 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.ddft_out
 * 02 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_integ_out
 * 01 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_integ_resetb_out
 * 00 : MXUSBPD_HIP_TOP_INST.y_pag2s_u_s8usbpd_srsense_top.feedfwd_integ_resetb_in
 */
#define PDSS_PAG2S_NCELL_DDFT_MUX_PAG2S_NCELL_DDFT1_SEL_MASK    (0x00001f80UL) /* <7:12> R:RW:0: */
#define PDSS_PAG2S_NCELL_DDFT_MUX_PAG2S_NCELL_DDFT1_SEL_POS    (7UL)


/*
 * 0: The selected output is not inverted
 * 1: The selected out is inverted
 */
#define PDSS_PAG2S_NCELL_DDFT_MUX_PAG2S_NCELL_DDFT1_POLARITY    (1UL << 13) /* <13:13> R:RW:0: */


/*
 * SR_SEN_PULLDN_EN config register
 */
#define PDSS_SR_SEN_PULLDN_EN_CFG_ADDRESS                   (0x400a25e4UL)
#define PDSS_SR_SEN_PULLDN_EN_CFG                           (*(volatile uint32_t *)(0x400a25e4UL))
#define PDSS_SR_SEN_PULLDN_EN_CFG_DEFAULT                   (0x00000000UL)

/*
 * Firmware override for SR_SENSE pulldown enable signal
 */
#define PDSS_SR_SEN_PULLDN_EN_CFG_SR_SEN_PULLDN_EN_OVR      (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Value for SR_SENSE pulldown enable signal
 */
#define PDSS_SR_SEN_PULLDN_EN_CFG_SR_SEN_PULLDN_EN_OVR_VAL    (1UL << 1) /* <1:1> R:RW:0: */


/*
 * 1: SR_SENSE pulldown enable is always 0
 */
#define PDSS_SR_SEN_PULLDN_EN_CFG_DIS_SR_SEN_PULLDN_EN      (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Valley vs LSCSA I Load Look Up Table
 */
#define PDSS_VALLEY_LOAD_ADDRESS(n)                         (0x400a2600UL + ((n) * (0x0004UL)))
#define PDSS_VALLEY_LOAD(n)                                 (*(volatile uint32_t *)(0x400a2600UL + ((n) * 0x0004UL)))
#define PDSS_VALLEY_LOAD_DEFAULT                            (0x00000000UL)

/*
 * Valley number
 */
#define PDSS_VALLEY_LOAD_VALLEY_NUM_MASK                    (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_VALLEY_LOAD_VALLEY_NUM_POS                     (0UL)


/*
 * ILoad Threshold corresponding to the valley number
 */
#define PDSS_VALLEY_LOAD_ILOAD_THRESH_MASK                  (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_VALLEY_LOAD_ILOAD_THRESH_POS                   (8UL)


/*
 * Valley Algorithm Config register
 */
#define PDSS_VALLEY_CONFIG_ADDRESS                          (0x400a2630UL)
#define PDSS_VALLEY_CONFIG                                  (*(volatile uint32_t *)(0x400a2630UL))
#define PDSS_VALLEY_CONFIG_DEFAULT                          (0x07f3ff01UL)

/*
 * Programmable Valley increment/decrement value for each valley update cycle
 */
#define PDSS_VALLEY_CONFIG_VALLEY_JUMP_MASK                 (0x0000000fUL) /* <0:3> R:RW:1: */
#define PDSS_VALLEY_CONFIG_VALLEY_JUMP_POS                  (0UL)


/*
 * Valley Increment cycle delay. Valley update will be done on the first
 * PTDRV_IN negede following the expiry of this delay. The update will be
 * based on the live value of the VALLEY_TGT and hene can be increment or
 * decrement. The delay timer is on ADC_CLK.
 */
#define PDSS_VALLEY_CONFIG_VALLEY_INC_DLY_MASK              (0x000fff00UL) /* <8:19> R:RW:1023: */
#define PDSS_VALLEY_CONFIG_VALLEY_INC_DLY_POS               (8UL)


/*
 * Valley Decrement cycle delay. Valley update will be done on the first
 * PTDRV_IN negede following the expiry of this delay. The update will be
 * based on the live value of the VALLEY_TGT and hene can be increment or
 * decrement.  The delay timer is on ADC_CLK.
 */
#define PDSS_VALLEY_CONFIG_VALLEY_DEC_DLY_MASK              (0xfff00000UL) /* <20:31> R:RW:127: */
#define PDSS_VALLEY_CONFIG_VALLEY_DEC_DLY_POS               (20UL)


/*
 * Valley Algorithm Control register
 */
#define PDSS_VALLEY_CTRL_ADDRESS                            (0x400a2634UL)
#define PDSS_VALLEY_CTRL                                    (*(volatile uint32_t *)(0x400a2634UL))
#define PDSS_VALLEY_CTRL_DEFAULT                            (0x00000030UL)

/*
 * Enables the Valley Algorithm.
 */
#define PDSS_VALLEY_CTRL_VALLEY_ALGO_EN                     (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The VALLEY_TGT will be loaded directly at the subsequent PTDRV negedge
 * without jumps or delays.
 */
#define PDSS_VALLEY_CTRL_ABRUPT_VALLEY_CHANGE               (1UL << 1) /* <1:1> RW:RW:0: */


/*
 * FW sets this bit while updating the VALLEY_LOAD LUT.
 */
#define PDSS_VALLEY_CTRL_LUT_UPDT                           (1UL << 2) /* <2:2> R:RW:0: */


/*
 * When set, VALLEY_NUM_UPDT uses SAFE_VALLEY value. Else, uses value calculated
 * by the Valley Algorithm.
 */
#define PDSS_VALLEY_CTRL_SEL_SAFE_VALLEY                    (1UL << 3) /* <3:3> RW:RW:0: */


/*
 * ILoad Hysterisis depth
 */
#define PDSS_VALLEY_CTRL_ILOAD_HYST_MASK                    (0x000000f0UL) /* <4:7> R:RW:3: */
#define PDSS_VALLEY_CTRL_ILOAD_HYST_POS                     (4UL)


/*
 * FW programmable Valley Number (0 means 1st Valley)
 */
#define PDSS_VALLEY_CTRL_SAFE_VALLEY_MASK                   (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_VALLEY_CTRL_SAFE_VALLEY_POS                    (8UL)


/*
 * Valley number Target loaded from either Safe valley or from the Valley
 * Algorithm
 */
#define PDSS_VALLEY_CTRL_VALLEY_TGT_MASK                    (0x00ff0000UL) /* <16:23> RW:RW:0: */
#define PDSS_VALLEY_CTRL_VALLEY_TGT_POS                     (16UL)


/*
 * Valley Algorithm Status register
 */
#define PDSS_VALLEY_STATUS_ADDRESS                          (0x400a2638UL)
#define PDSS_VALLEY_STATUS                                  (*(volatile uint32_t *)(0x400a2638UL))
#define PDSS_VALLEY_STATUS_DEFAULT                          (0x00000000UL)

/*
 * Index of the LUT from which the ILOAD is loaded
 */
#define PDSS_VALLEY_STATUS_INDEX_S0_MASK                    (0x0000000fUL) /* <0:3> RW:R:0: */
#define PDSS_VALLEY_STATUS_INDEX_S0_POS                     (0UL)


/*
 * ILOAD corresponding to the selected index.
 */
#define PDSS_VALLEY_STATUS_ILOAD_S0_MASK                    (0x00000ff0UL) /* <4:11> RW:R:0: */
#define PDSS_VALLEY_STATUS_ILOAD_S0_POS                     (4UL)


/*
 * Index of the LUT from which the ILOAD is loaded
 */
#define PDSS_VALLEY_STATUS_INDEX_S1_MASK                    (0x0000f000UL) /* <12:15> RW:R:0: */
#define PDSS_VALLEY_STATUS_INDEX_S1_POS                     (12UL)


/*
 * ILOAD corresponding to the selected index.
 */
#define PDSS_VALLEY_STATUS_ILOAD_S1_MASK                    (0x00ff0000UL) /* <16:23> RW:R:0: */
#define PDSS_VALLEY_STATUS_ILOAD_S1_POS                     (16UL)


/*
 * Final Valley number generated from the Valley Algorithm
 */
#define PDSS_VALLEY_STATUS_VALLEY_MASK                      (0xff000000UL) /* <24:31> RW:R:0: */
#define PDSS_VALLEY_STATUS_VALLEY_POS                       (24UL)


/*
 * Valley Algorithm Config register for LINE IN based Valley Algorithm control
 */
#define PDSS_VALLEY_LINE_IN_ADDRESS                         (0x400a263cUL)
#define PDSS_VALLEY_LINE_IN                                 (*(volatile uint32_t *)(0x400a263cUL))
#define PDSS_VALLEY_LINE_IN_DEFAULT                         (0x00000000UL)

/*
 * Line in Lower threshold to be compared by Valley Algorithm to move to
 * safe valley mode and indicate to FW
 */
#define PDSS_VALLEY_LINE_IN_LINE_IN_THRESH_LOW_MASK         (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_VALLEY_LINE_IN_LINE_IN_THRESH_LOW_POS          (0UL)


/*
 * Line in Higher threshold to be compared by Valley Algorithm to indicate
 * to FW
 */
#define PDSS_VALLEY_LINE_IN_LINE_IN_THRESH_HIGH_MASK        (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_VALLEY_LINE_IN_LINE_IN_THRESH_HIGH_POS         (8UL)


/*
 * Override HW based move to Safe Valley Mode based on Line in threshold
 * crossing
 */
#define PDSS_VALLEY_LINE_IN_LINE_IN_SAFE_DIS                (1UL << 29) /* <29:29> R:RW:0: */


/*
 * 0 - Enable Line in threshold cross detection
 * 1 - Temporarily Disable Line in threshold cross detection while updating
 * Threshold values
 */
#define PDSS_VALLEY_LINE_IN_S_UPD_LINE                      (1UL << 31) /* <31:31> R:RW:0: */


/*
 * Valley Algorithm Config register for Load Transient detection based Valley
 * Algorithm control
 */
#define PDSS_VALLEY_LOAD_TRANS_ADDRESS                      (0x400a2640UL)
#define PDSS_VALLEY_LOAD_TRANS                              (*(volatile uint32_t *)(0x400a2640UL))
#define PDSS_VALLEY_LOAD_TRANS_DEFAULT                      (0x00005109UL)

/*
 * Transient load detect sample-and-hold Pulse width in terms of PASC clock
 * cycles
 */
#define PDSS_VALLEY_LOAD_TRANS_SH_LTRANDET_PW_MASK          (0x0000001fUL) /* <0:4> R:RW:9: */
#define PDSS_VALLEY_LOAD_TRANS_SH_LTRANDET_PW_POS           (0UL)


/*
 * Transient load detect sample-and-hold Period in terms of PASC clock cycles
 */
#define PDSS_VALLEY_LOAD_TRANS_SH_LTRANDET_PER_MASK         (0x0007ff00UL) /* <8:18> R:RW:81: */
#define PDSS_VALLEY_LOAD_TRANS_SH_LTRANDET_PER_POS          (8UL)


/*
 * Override HW based move to Safe Valley Mode based on LTRAN detection
 */
#define PDSS_VALLEY_LOAD_TRANS_LTRANDET_SAFE_DIS            (1UL << 29) /* <29:29> R:RW:0: */


/*
 * Rsense short detection control register
 */
#define PDSS_RSNS_SHRT_ADDRESS                              (0x400a2648UL)
#define PDSS_RSNS_SHRT                                      (*(volatile uint32_t *)(0x400a2648UL))
#define PDSS_RSNS_SHRT_DEFAULT                              (0x00000000UL)

/*
 * Rsense Short - Threshold value of output load current used for  Resene
 * short detection (ADC based value)
 */
#define PDSS_RSNS_SHRT_LSCSA_THRESH_VAL_MASK                (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_RSNS_SHRT_LSCSA_THRESH_VAL_POS                 (0UL)


/*
 * Rsense Short - Threshold value of ptdrv Pulse-width used for  Resene short
 * detection (PASC_CLK based counter)
 */
#define PDSS_RSNS_SHRT_PTDRV_IN_PW_THRESH_MASK              (0x0007ff00UL) /* <8:18> R:RW:0: */
#define PDSS_RSNS_SHRT_PTDRV_IN_PW_THRESH_POS               (8UL)


/*
 * Enable bit for Rsense short detection
 */
#define PDSS_RSNS_SHRT_RSNS_SHRT_DET_EN                     (1UL << 31) /* <31:31> R:RW:0: */


/*
 * Over Temparature Protection control register
 */
#define PDSS_OTP_CTRL_ADDRESS                               (0x400a264cUL)
#define PDSS_OTP_CTRL                                       (*(volatile uint32_t *)(0x400a264cUL))
#define PDSS_OTP_CTRL_DEFAULT                               (0x00000000UL)

/*
 * Over-Temp threshold where OTP det will get triggered (ADC based value)
 * (higher or lower is decided by OTP_COMP_SEL)
 */
#define PDSS_OTP_CTRL_OTP_THRESH_MASK                       (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_OTP_CTRL_OTP_THRESH_POS                        (0UL)


/*
 * 1: ADC value checked for higher than OTP threshold
 * 0: ADC value checked for lower than OTP threshold
 */
#define PDSS_OTP_CTRL_OTP_COMP_SEL                          (1UL << 29) /* <29:29> R:RW:0: */


/*
 * 1: PASC will go into IDLE with OTP detect
 */
#define PDSS_OTP_CTRL_EN_OTP_PASC_HW_DIS                    (1UL << 30) /* <30:30> R:RW:0: */


/*
 * Enable bit for HW based OTP detection
 */
#define PDSS_OTP_CTRL_EN_OTP_DET                            (1UL << 31) /* <31:31> R:RW:0: */


/*
 * USBPD Hard IP C-connector Trim Register0. Production trims stored in flash
 */
#define PDSS_TRIM_CC_0_ADDRESS                              (0x400aff00UL)
#define PDSS_TRIM_CC_0                                      (*(volatile uint32_t *)(0x400aff00UL))
#define PDSS_TRIM_CC_0_DEFAULT                              (0x00000000UL)

/*
 * Trim bits for Driver termination impedance. BROS describes the step
 */
#define PDSS_TRIM_CC_0_ZDRV_TRIM_MASK                       (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_CC_0_ZDRV_TRIM_POS                        (0UL)


/*
 * Trim bits for TX Driver rise/fall slew rate. 00 for minimum and 11 for
 * fastest slew rate.
 */
#define PDSS_TRIM_CC_0_TX_TRIM_MASK                         (0x00000018UL) /* <3:4> R:RW:0: */
#define PDSS_TRIM_CC_0_TX_TRIM_POS                          (3UL)


/*
 * USBPD Hard IP C-connector Trim Register1. Production trims stored in flash
 */
#define PDSS_TRIM_CC_1_ADDRESS                              (0x400aff04UL)
#define PDSS_TRIM_CC_1                                      (*(volatile uint32_t *)(0x400aff04UL))
#define PDSS_TRIM_CC_1_DEFAULT                              (0x00000000UL)

/*
 * Trim bits for CC1 Pull-up current source
 * Firmware must read SFlash and set this value for each Rp value (CC_CTRL_0.RP_MODE)
 * 0FFF_F079 : Port 0 - Default
 * 0FFF_F07A : Port 0 - 1p5
 * 0FFF_F07B : Port 0 - 3p0
 * 0FFF_F085 : Port 1 - Default
 * 0FFF_F086 : Port 1 - 1p5
 * 0FFF_F087 : Port 1 - 3p0
 */
#define PDSS_TRIM_CC_1_RP_CC1_TRIM_MASK                     (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_TRIM_CC_1_RP_CC1_TRIM_POS                      (0UL)


/*
 * USBPD Hard IP C-connector Trim Register2. Production trims stored in flash
 */
#define PDSS_TRIM_CC_2_ADDRESS                              (0x400aff08UL)
#define PDSS_TRIM_CC_2                                      (*(volatile uint32_t *)(0x400aff08UL))
#define PDSS_TRIM_CC_2_DEFAULT                              (0x00000000UL)

/*
 * Trim bits for CC2 Pull-up current source
 * Firmware must read SFlash and set this value for each Rp value (CC_CTRL_0.RP_MODE)
 * 0FFF_F079 : Port 0 - Default
 * 0FFF_F07A : Port 0 - 1p5
 * 0FFF_F07B : Port 0 - 3p0
 * 0FFF_F085 : Port 1 - Default
 * 0FFF_F086 : Port 1 - 1p5
 * 0FFF_F087 : Port 1 - 3p0
 */
#define PDSS_TRIM_CC_2_RP_CC2_TRIM_MASK                     (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_TRIM_CC_2_RP_CC2_TRIM_POS                      (0UL)


/*
 * USBPD Hard IP C-connector Trim Register3. Production trims stored in flash
 */
#define PDSS_TRIM_CC_3_ADDRESS                              (0x400aff0cUL)
#define PDSS_TRIM_CC_3                                      (*(volatile uint32_t *)(0x400aff0cUL))
#define PDSS_TRIM_CC_3_DEFAULT                              (0x00000024UL)

/*
 * Trim bits for 0.5V comparator reference. Default is 0.53. Check BROS for
 * complete description of the steps.
 * This should be programmed to 0x2 for CCG2*A Silicon. Leave default for
 * ** silicon.
 * Notes: This filed should be 0x2 for all application (DFP,UFP,AMA ,cable)
 */
#define PDSS_TRIM_CC_3_V0P5_TRIM_MASK                       (0x00000007UL) /* <0:2> R:RW:4: */
#define PDSS_TRIM_CC_3_V0P5_TRIM_POS                        (0UL)


/*
 * Trim bits for 0.655V comparator reference. Default value is 0.6475V
 */
#define PDSS_TRIM_CC_3_V0P655_TRIM_MASK                     (0x00000038UL) /* <3:5> R:RW:4: */
#define PDSS_TRIM_CC_3_V0P655_TRIM_POS                      (3UL)


/*
 * USBPD Hard IP C-connector Trim Register4. Production trims stored in flash
 */
#define PDSS_TRIM_CC_4_ADDRESS                              (0x400aff10UL)
#define PDSS_TRIM_CC_4                                      (*(volatile uint32_t *)(0x400aff10UL))
#define PDSS_TRIM_CC_4_DEFAULT                              (0x00000000UL)

/*
 * Trim bits for 0.74V comparator reference. Default value is 0.735V. Check
 * BROS for complete description of the steps.
 */
#define PDSS_TRIM_CC_4_V0P74_TRIM_MASK                      (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_CC_4_V0P74_TRIM_POS                       (0UL)


/*
 * Trim bits for 1.63V comparator reference. Default value is 1.71V
 */
#define PDSS_TRIM_CC_4_V1P63_TRIM_MASK                      (0x00000070UL) /* <4:6> R:RW:0: */
#define PDSS_TRIM_CC_4_V1P63_TRIM_POS                       (4UL)


/*
 * USBPD Hard IP C-connector Trim Register5. Production trims stored in flash
 */
#define PDSS_TRIM_CC_5_ADDRESS                              (0x400aff14UL)
#define PDSS_TRIM_CC_5                                      (*(volatile uint32_t *)(0x400aff14UL))
#define PDSS_TRIM_CC_5_DEFAULT                              (0x00000000UL)

/*
 * Trim bits for 1.125V comparator reference. Default is 1.125. Check BROS
 * for complete description of the steps.
 */
#define PDSS_TRIM_CC_5_V1P125_TRIM_MASK                     (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_CC_5_V1P125_TRIM_POS                      (0UL)


/*
 * Trim bits for 1.235V comparator reference. Default is 1.22V. Check BROS
 * for complete description of the steps.
 */
#define PDSS_TRIM_CC_5_V1P235_TRIM_MASK                     (0x00000038UL) /* <3:5> R:RW:0: */
#define PDSS_TRIM_CC_5_V1P235_TRIM_POS                      (3UL)


/*
 * USBPD Hard IP C-connector Trim Register6. Production trims stored in flash
 */
#define PDSS_TRIM_CC_6_ADDRESS                              (0x400aff18UL)
#define PDSS_TRIM_CC_6                                      (*(volatile uint32_t *)(0x400aff18UL))
#define PDSS_TRIM_CC_6_DEFAULT                              (0x00000000UL)

/*
 * Trim bits for 1.575V comparator reference. Default value being 1.56V .
 * Check BROS for complete description for the trim.
 * This should be programmed to 0x3 for CCG2*A Silicon. Leave default for
 * ** silicon.
 * Notes: This field should be 0x3 for all application (DFP,UFP,AMA ,cable)
 */
#define PDSS_TRIM_CC_6_V1P575_TRIM_MASK                     (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_CC_6_V1P575_TRIM_POS                      (0UL)


/*
 * Trim bits for Rd pull-down resistor
 */
#define PDSS_TRIM_CC_6_RD_TRIM_MASK                         (0x00000078UL) /* <3:6> R:RW:0: */
#define PDSS_TRIM_CC_6_RD_TRIM_POS                          (3UL)


/*
 * USBPD Hard IP C-connector Trim Register7. Production trims stored in flash
 */
#define PDSS_TRIM_CC_7_ADDRESS                              (0x400aff1cUL)
#define PDSS_TRIM_CC_7                                      (*(volatile uint32_t *)(0x400aff1cUL))
#define PDSS_TRIM_CC_7_DEFAULT                              (0x00000001UL)

/*
 * Trim bits for 1.97V comparator reference. Default value being 2.09V. Check
 * BROS for complete description for the trim.
 */
#define PDSS_TRIM_CC_7_V1P97_TRIM_MASK                      (0x00000007UL) /* <0:2> R:RW:1: */
#define PDSS_TRIM_CC_7_V1P97_TRIM_POS                       (0UL)


/*
 * USBPD Hard IP battery charger Detect#1 Trim Register 0. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET1_0_ADDRESS                        (0x400aff20UL)
#define PDSS_TRIM_BCH_DET1_0                                (*(volatile uint32_t *)(0x400aff20UL))
#define PDSS_TRIM_BCH_DET1_0_DEFAULT                        (0x00000000UL)

/*
 * 0.6V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_0_V600M_TRIM_MASK                (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_0_V600M_TRIM_POS                 (0UL)


/*
 * Reference Generator trim control
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_0_V740M_CHGDET_TRIM_MASK         (0x00000078UL) /* <3:6> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_0_V740M_CHGDET_TRIM_POS          (3UL)


/*
 * USBPD Hard IP battery charger Detect#1 Trim Register 1. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET1_1_ADDRESS                        (0x400aff24UL)
#define PDSS_TRIM_BCH_DET1_1                                (*(volatile uint32_t *)(0x400aff24UL))
#define PDSS_TRIM_BCH_DET1_1_DEFAULT                        (0x00000000UL)

/*
 * 0.325V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_1_V325M_TRIM_MASK                (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_1_V325M_TRIM_POS                 (0UL)


/*
 * 2.0V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_1_V2P0V_TRIM_MASK                (0x0000000cUL) /* <2:3> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_1_V2P0V_TRIM_POS                 (2UL)


/*
 * 1.2V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_1_V1P2V_TRIM_MASK                (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_1_V1P2V_TRIM_POS                 (4UL)


/*
 * USBPD Hard IP battery charger Detect#1 Trim Register 2. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET1_2_ADDRESS                        (0x400aff28UL)
#define PDSS_TRIM_BCH_DET1_2                                (*(volatile uint32_t *)(0x400aff28UL))
#define PDSS_TRIM_BCH_DET1_2_DEFAULT                        (0x00000000UL)

/*
 * 0.325V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_2_V850M_TRIM_MASK                (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_2_V850M_TRIM_POS                 (0UL)


/*
 * 2.2V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_2_V2P2V_TRIM_MASK                (0x0000000cUL) /* <2:3> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_2_V2P2V_TRIM_POS                 (2UL)


/*
 * 2.9V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_2_V2P9V_TRIM_MASK                (0x00000030UL) /* <4:5> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_2_V2P9V_TRIM_POS                 (4UL)


/*
 * 2.5V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_2_V2P5V_TRIM_MASK                (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_2_V2P5V_TRIM_POS                 (6UL)


/*
 * USBPD Hard IP battery charger Detect#1 Trim Register 3. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET1_3_ADDRESS                        (0x400aff2cUL)
#define PDSS_TRIM_BCH_DET1_3                                (*(volatile uint32_t *)(0x400aff2cUL))
#define PDSS_TRIM_BCH_DET1_3_DEFAULT                        (0x00000000UL)

/*
 * 0.700V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_3_V700M_TRIM_MASK                (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_3_V700M_TRIM_POS                 (0UL)


/*
 * 1.4V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_3_V1P4V_TRIM_MASK                (0x00000038UL) /* <3:5> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_3_V1P4V_TRIM_POS                 (3UL)


/*
 * 1.7V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET1_3_V1P7V_TRIM_MASK                (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_3_V1P7V_TRIM_POS                 (6UL)


/*
 * USBPD Hard IP battery charger Detect#1 Trim Register 4. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET1_4_ADDRESS                        (0x400aff30UL)
#define PDSS_TRIM_BCH_DET1_4                                (*(volatile uint32_t *)(0x400aff30UL))
#define PDSS_TRIM_BCH_DET1_4_DEFAULT                        (0x00000000UL)

/*
 * DP/DM Sink Current Trim
 * 0000: 21.6uA
 * 0001: 24.0uA
 * 0010: 26.4uA
 * 0011: 28.8uA
 * 0100: 31.2uA
 * 0101: 33.6uA
 * 0110: 36.0uA
 * 0111: 38.4uA
 * 1000: 40.8uA
 * 1001: 43.2uA
 * 1010: 45.6uA
 * 1011: 48.0uA
 * 1100: 50.4uA
 * 1101: 52.8uA
 * 1110: 55.2uA
 * 1111: 57.6uA
 */
#define PDSS_TRIM_BCH_DET1_4_ISINK_TRIM_MASK                (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_4_ISINK_TRIM_POS                 (0UL)


/*
 * DP OVP Detection Voltage Trim
 * xx00: 4.50V(Default)
 * xx01: 4.25V
 * xx10: 4.80V
 * xx11: 5.00V
 * DM OVP Detection Voltage Trim
 * 00xx: 4.50V(Default)
 * 01xx: 4.25V
 * 10xx: 4.80V
 * 11xx: 5.00V
 */
#define PDSS_TRIM_BCH_DET1_4_OVP_VREF_TRIM_MASK             (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_4_OVP_VREF_TRIM_POS              (4UL)


/*
 * USBPD Hard IP battery charger Detect#1 Trim Register 5. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET1_5_ADDRESS                        (0x400aff34UL)
#define PDSS_TRIM_BCH_DET1_5                                (*(volatile uint32_t *)(0x400aff34UL))
#define PDSS_TRIM_BCH_DET1_5_DEFAULT                        (0x00000000UL)

/*
 * 400mV Reference Voltage Trim for Impedance Detection on DP/DM
 * Only these are valid combinations -
 * 0000: 400mV(Default)
 * 0101: 310mV
 * 0110: 340mV
 * 1100: 460mV
 */
#define PDSS_TRIM_BCH_DET1_5_IMP_VREF_TRIM_MASK             (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_BCH_DET1_5_IMP_VREF_TRIM_POS              (0UL)


/*
 * USBPD Hard IP REFGEN#1 Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_REFGEN1_0_ADDRESS                         (0x400aff38UL)
#define PDSS_TRIM_REFGEN1_0                                 (*(volatile uint32_t *)(0x400aff38UL))
#define PDSS_TRIM_REFGEN1_0_DEFAULT                         (0x00000000UL)

/*
 * Trim for input reference voltage/ Offset of regulation amplifier. This
 * provides the reference for the regulation blocks in the CSA,EA, and other
 * blocks such as CC_SHVT reference and VBUS_dischg. Default value is 0 with
 * bits bit 1-7 trimming down and 9-15 trimming up. BROS shows complete description
 * for the trim.
 */
#define PDSS_TRIM_REFGEN1_0_REFGEN_VREF_TRIM_MASK           (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_REFGEN1_0_REFGEN_VREF_TRIM_POS            (0UL)


/*
 * Trim for input reference voltage/ Offset of regulation amplifier. This
 * provides the reference for the regulation blocks in the CSA,EA, and other
 * blocks such as CC_SHVT reference and VBUS_dischg. Default value is 0 with
 * bits bit 1-7 trimming down and 9-15 trimming up. BROS shows complete description
 * for the trim.
 */
#define PDSS_TRIM_REFGEN1_0_REFGEN_VREF_MON_TRIM_MASK       (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_TRIM_REFGEN1_0_REFGEN_VREF_MON_TRIM_POS        (4UL)


/*
 * USBPD Hard IP REFGEN#1 Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_REFGEN1_1_ADDRESS                         (0x400aff3cUL)
#define PDSS_TRIM_REFGEN1_1                                 (*(volatile uint32_t *)(0x400aff3cUL))
#define PDSS_TRIM_REFGEN1_1_DEFAULT                         (0x00000000UL)

/*
 * Trim bit for internal clock generator
 * 0: No trim
 * 1: Higher Frequency
 */
#define PDSS_TRIM_REFGEN1_1_REFGEN_ICLK_TRIM                (1UL << 0) /* <0:0> R:RW:0: */


/*
 * USBPD Hard IP EA#1 Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_PDS_EA_ADDRESS                            (0x400aff40UL)
#define PDSS_TRIM_PDS_EA                                    (*(volatile uint32_t *)(0x400aff40UL))
#define PDSS_TRIM_PDS_EA_DEFAULT                            (0x00000020UL)

/*
 * Trim bits to alter IDAC current resolution which would change VBUS resolution.
 */
#define PDSS_TRIM_PDS_EA_IREF_CV_TRIM_MASK                  (0x000000ffUL) /* <0:7> R:RW:32: */
#define PDSS_TRIM_PDS_EA_IREF_CV_TRIM_POS                   (0UL)


/*
 * USBPD Hard IP Spare1 Trim Register
 */
#define PDSS_TRIM_SPARE1_ADDRESS                            (0x400aff44UL)
#define PDSS_TRIM_SPARE1                                    (*(volatile uint32_t *)(0x400aff44UL))
#define PDSS_TRIM_SPARE1_DEFAULT                            (0x00000000UL)

/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_TRIM_SPARE1_SPARE1_TRIM_MASK                   (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_TRIM_SPARE1_SPARE1_TRIM_POS                    (0UL)


/*
 * USBPD Hard IP Comparator#0 Trim Register. Production trims stored in flash
 */
#define PDSS_TRIM_COMP1_0_ADDRESS                           (0x400aff48UL)
#define PDSS_TRIM_COMP1_0                                   (*(volatile uint32_t *)(0x400aff48UL))
#define PDSS_TRIM_COMP1_0_DEFAULT                           (0x00000000UL)

/*
 * Input offset trim.
 */
#define PDSS_TRIM_COMP1_0_VIOS_TRIM_MASK                    (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_TRIM_COMP1_0_VIOS_TRIM_POS                     (0UL)


/*
 * USBPD Hard IP Deep Sleep   Trim Register0. Production trims stored in
 * flash
 */
#define PDSS_TRIM_DPSLP_0_ADDRESS                           (0x400aff4cUL)
#define PDSS_TRIM_DPSLP_0                                   (*(volatile uint32_t *)(0x400aff4cUL))
#define PDSS_TRIM_DPSLP_0_DEFAULT                           (0x000000f1UL)

/*
 * DeepSleep 2.4uA current reference trim bit.
 * Refer to s8usbpd_ver3 BROS for bit settings.
 */
#define PDSS_TRIM_DPSLP_0_I_TRIM_MASK                       (0x000000ffUL) /* <0:7> R:RW:241: */
#define PDSS_TRIM_DPSLP_0_I_TRIM_POS                        (0UL)


/*
 * USBPD Hard IP Deep Sleep  Trim Register1. Production trims stored in flash
 */
#define PDSS_TRIM_DPSLP_1_ADDRESS                           (0x400aff50UL)
#define PDSS_TRIM_DPSLP_1                                   (*(volatile uint32_t *)(0x400aff50UL))
#define PDSS_TRIM_DPSLP_1_DEFAULT                           (0x00000000UL)

/*
 * Beta multiplier reference trim bits.
 * Refer to GPM-541 for trim settings.
 */
#define PDSS_TRIM_DPSLP_1_REF_TRIM_MASK                     (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_DPSLP_1_REF_TRIM_POS                      (0UL)


/*
 * Deepsleep 2.4uA current reference temperature coefficient trim bits
 */
#define PDSS_TRIM_DPSLP_1_ITRIM_TC_MASK                     (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_TRIM_DPSLP_1_ITRIM_TC_POS                      (4UL)


/*
 * USBPD Hard IP SR Sense Trim Register0. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_0_ADDRESS                        (0x400aff54UL)
#define PDSS_TRIM_SR_SENSE_0                                (*(volatile uint32_t *)(0x400aff54UL))
#define PDSS_TRIM_SR_SENSE_0_DEFAULT                        (0x00000000UL)

/*
 * trim bits for trimming resistive RC filter on sr_vss_int node.
 */
#define PDSS_TRIM_SR_SENSE_0_DRAIN_TRIM_MASK                (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_TRIM_SR_SENSE_0_DRAIN_TRIM_POS                 (0UL)


/*
 * USBPD Hard IP SR Sense Trim Register2. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_2_ADDRESS                        (0x400aff58UL)
#define PDSS_TRIM_SR_SENSE_2                                (*(volatile uint32_t *)(0x400aff58UL))
#define PDSS_TRIM_SR_SENSE_2_DEFAULT                        (0x00000020UL)

/*
 * Unused
 */
#define PDSS_TRIM_SR_SENSE_2_FEEDFWD_IFF_TRIM_MASK          (0x0000003fUL) /* <0:5> R:RW:32: */
#define PDSS_TRIM_SR_SENSE_2_FEEDFWD_IFF_TRIM_POS           (0UL)


/*
 * USBPD Hard IP SR Sense Trim Register5. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_5_ADDRESS                        (0x400aff5cUL)
#define PDSS_TRIM_SR_SENSE_5                                (*(volatile uint32_t *)(0x400aff5cUL))
#define PDSS_TRIM_SR_SENSE_5_DEFAULT                        (0x00000010UL)

/*
 * trim bits for feed-forward V_feedfwd
 */
#define PDSS_TRIM_SR_SENSE_5_FEEDFWD_VFF_TRIM_MASK          (0x0000003fUL) /* <0:5> R:RW:16: */
#define PDSS_TRIM_SR_SENSE_5_FEEDFWD_VFF_TRIM_POS           (0UL)


/*
 * USBPD Hard IP SR Sense Trim Register6. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_6_ADDRESS                        (0x400aff60UL)
#define PDSS_TRIM_SR_SENSE_6                                (*(volatile uint32_t *)(0x400aff60UL))
#define PDSS_TRIM_SR_SENSE_6_DEFAULT                        (0x00000003UL)

/*
 * To trim/config -100mV sensing threshold
 * For +ve NSN threshold; keep this as 0x3
 */
#define PDSS_TRIM_SR_SENSE_6_NSN_TRIM_MASK                  (0x0000003fUL) /* <0:5> R:RW:3: */
#define PDSS_TRIM_SR_SENSE_6_NSN_TRIM_POS                   (0UL)


/*
 * USBPD Hard IP SR Sense Trim Register7. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_7_ADDRESS                        (0x400aff64UL)
#define PDSS_TRIM_SR_SENSE_7                                (*(volatile uint32_t *)(0x400aff64UL))
#define PDSS_TRIM_SR_SENSE_7_DEFAULT                        (0x0000000aUL)

/*
 * Trim bits for peakdet comparator for trimming peak detect trip current
 * 0 - 0 nA
 * 1 - 200 nA
 * 2 - 400 nA
 * 4 - 800 nA
 * 8 - 1600 nA
 * 16 - 3200 nA
 * 32 - 6400 nA
 */
#define PDSS_TRIM_SR_SENSE_7_PEAKDET_TRIM_MASK              (0x0000003fUL) /* <0:5> R:RW:10: */
#define PDSS_TRIM_SR_SENSE_7_PEAKDET_TRIM_POS               (0UL)


/*
 * USBPD Hard IP SR Sense Trim Register8. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_8_ADDRESS                        (0x400aff68UL)
#define PDSS_TRIM_SR_SENSE_8                                (*(volatile uint32_t *)(0x400aff68UL))
#define PDSS_TRIM_SR_SENSE_8_DEFAULT                        (0x00000017UL)

/*
 * Trim bits for ZCD
 */
#define PDSS_TRIM_SR_SENSE_8_ZCD_TRIM_MASK                  (0x000000ffUL) /* <0:7> R:RW:23: */
#define PDSS_TRIM_SR_SENSE_8_ZCD_TRIM_POS                   (0UL)


/*
 * USBPD Hard IP SR Sense Trim Register9. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_9_ADDRESS                        (0x400aff6cUL)
#define PDSS_TRIM_SR_SENSE_9                                (*(volatile uint32_t *)(0x400aff6cUL))
#define PDSS_TRIM_SR_SENSE_9_DEFAULT                        (0x0000002aUL)

/*
 * Trim bits for ZCDF
 * 42 - 5mV vtrip(Internal Rpath)
 * 79 - 50mV vtrip( External Cpath)
 */
#define PDSS_TRIM_SR_SENSE_9_ZCDF_TRIM_MASK                 (0x000000ffUL) /* <0:7> R:RW:42: */
#define PDSS_TRIM_SR_SENSE_9_ZCDF_TRIM_POS                  (0UL)


/*
 * USBPD Hard IP SR Sense Trim Register10. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_10_ADDRESS                       (0x400aff70UL)
#define PDSS_TRIM_SR_SENSE_10                               (*(volatile uint32_t *)(0x400aff70UL))
#define PDSS_TRIM_SR_SENSE_10_DEFAULT                       (0x00000078UL)

/*
 * CLAMP_PKD_REF_TRIM<0>:
 * 0 : nsn_en is used to turn on the peakdet_switch
 * 1 ; sr_sen_ctrlp is used to turn on the peakder_switch
 * CLAMP_PKD_REF_TRIM<1>:
 * 0 : lower cap section is added to couple sr_sense to peakdetect
 * 1 : Disables the lower cap section from sr_sense to peakdetect
 * CLAMP_PKD_REF_TRIM<2>:
 * 0 : higher cap section is added to couple sr_sense to peakdetect
 * 1 : Disables the higher cap section from sr_sense to peakdetect
 */
#define PDSS_TRIM_SR_SENSE_10_CLAMP_PKD_REF_TRIM_MASK       (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_SR_SENSE_10_CLAMP_PKD_REF_TRIM_POS        (0UL)


/*
 * To trim Integration current for capacitor variation
 */
#define PDSS_TRIM_SR_SENSE_10_FEEDFWD_INTEG_TRIM_MASK       (0x000000f8UL) /* <3:7> R:RW:15: */
#define PDSS_TRIM_SR_SENSE_10_FEEDFWD_INTEG_TRIM_POS        (3UL)


/*
 * USBPD Hard IP SR Sense Trim Register11. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_11_ADDRESS                       (0x400aff74UL)
#define PDSS_TRIM_SR_SENSE_11                               (*(volatile uint32_t *)(0x400aff74UL))
#define PDSS_TRIM_SR_SENSE_11_DEFAULT                       (0x0000000fUL)

/*
 * I_FF linearity trim
 */
#define PDSS_TRIM_SR_SENSE_11_FEEDFWD_ICOMP_TRIM_MASK       (0x0000003fUL) /* <0:5> R:RW:15: */
#define PDSS_TRIM_SR_SENSE_11_FEEDFWD_ICOMP_TRIM_POS        (0UL)


/*
 * USBPD Hard IP SR Sense Trim Register12. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_12_ADDRESS                       (0x400aff78UL)
#define PDSS_TRIM_SR_SENSE_12                               (*(volatile uint32_t *)(0x400aff78UL))
#define PDSS_TRIM_SR_SENSE_12_DEFAULT                       (0x00000077UL)

/*
 * VINCOMP1 trim
 */
#define PDSS_TRIM_SR_SENSE_12_FEEDFWD_VINCOMP1_TRIM_MASK    (0x0000000fUL) /* <0:3> R:RW:7: */
#define PDSS_TRIM_SR_SENSE_12_FEEDFWD_VINCOMP1_TRIM_POS     (0UL)


/*
 * VINCOMP2 trim
 */
#define PDSS_TRIM_SR_SENSE_12_FEEDFWD_VINCOMP2_TRIM_MASK    (0x000000f0UL) /* <4:7> R:RW:7: */
#define PDSS_TRIM_SR_SENSE_12_FEEDFWD_VINCOMP2_TRIM_POS     (4UL)


/*
 * USBPD Hard IP SR Sense Trim Register13. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_13_ADDRESS                       (0x400aff7cUL)
#define PDSS_TRIM_SR_SENSE_13                               (*(volatile uint32_t *)(0x400aff7cUL))
#define PDSS_TRIM_SR_SENSE_13_DEFAULT                       (0x00000087UL)

/*
 * VINCOMP3 trim
 */
#define PDSS_TRIM_SR_SENSE_13_FEEDFWD_VINCOMP3_TRIM_MASK    (0x0000000fUL) /* <0:3> R:RW:7: */
#define PDSS_TRIM_SR_SENSE_13_FEEDFWD_VINCOMP3_TRIM_POS     (0UL)


/*
 * VINCOMP4 trim
 */
#define PDSS_TRIM_SR_SENSE_13_FEEDFWD_VINCOMP4_TRIM_MASK    (0x000000f0UL) /* <4:7> R:RW:8: */
#define PDSS_TRIM_SR_SENSE_13_FEEDFWD_VINCOMP4_TRIM_POS     (4UL)


/*
 * USBPD Hard IP SR Sense Trim Register14. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_14_ADDRESS                       (0x400aff80UL)
#define PDSS_TRIM_SR_SENSE_14                               (*(volatile uint32_t *)(0x400aff80UL))
#define PDSS_TRIM_SR_SENSE_14_DEFAULT                       (0x00000097UL)

/*
 * VINCOMP5 trim
 */
#define PDSS_TRIM_SR_SENSE_14_FEEDFWD_VINCOMP5_TRIM_MASK    (0x0000000fUL) /* <0:3> R:RW:7: */
#define PDSS_TRIM_SR_SENSE_14_FEEDFWD_VINCOMP5_TRIM_POS     (0UL)


/*
 * trim bits for peak-detector block for trimming reference voltage for backup
 * scheme comparator and output clamp voltages for comparator
 * <3:2> -  backup scheme comparator
 * 00 - 346m
 * 11 - 370m
 * <1:0> - output comparator clamp
 * 00 - 1.78
 * 11 - 1.44
 */
#define PDSS_TRIM_SR_SENSE_14_RSTCMP_PKD_REF_TRIM_MASK      (0x000000f0UL) /* <4:7> R:RW:9: */
#define PDSS_TRIM_SR_SENSE_14_RSTCMP_PKD_REF_TRIM_POS       (4UL)


/*
 * USBPD Hard IP SR Sense Trim Register15. Production trims stored in flash
 */
#define PDSS_TRIM_SR_SENSE_15_ADDRESS                       (0x400aff84UL)
#define PDSS_TRIM_SR_SENSE_15                               (*(volatile uint32_t *)(0x400aff84UL))
#define PDSS_TRIM_SR_SENSE_15_DEFAULT                       (0x0000000aUL)

/*
 * trim bits for peak-detector block for trimming valleydetect trip current
 * 0 - 0 nA
 * 1 - 200 nA
 * 2 - 400 nA
 * 4 - 800 nA
 * 8 - 1600 nA
 * 16 - 3200 nA
 * 32 - 6400 nA
 */
#define PDSS_TRIM_SR_SENSE_15_VALLEYDET_TRIM_MASK           (0x0000003fUL) /* <0:5> R:RW:10: */
#define PDSS_TRIM_SR_SENSE_15_VALLEYDET_TRIM_POS            (0UL)


/*
 * USBPD Hard IP PWM Trim Register0. Production trims stored in flash
 */
#define PDSS_TRIM_PWM_0_ADDRESS                             (0x400aff88UL)
#define PDSS_TRIM_PWM_0                                     (*(volatile uint32_t *)(0x400aff88UL))
#define PDSS_TRIM_PWM_0_DEFAULT                             (0x00000010UL)

/*
 * trim bits for PWM capacitor trimming in fixed DAC path
 */
#define PDSS_TRIM_PWM_0_CAP_DAC_TRIM_MASK                   (0x0000001fUL) /* <0:4> R:RW:16: */
#define PDSS_TRIM_PWM_0_CAP_DAC_TRIM_POS                    (0UL)


/*
 * USBPD Hard IP PWM Trim Register1. Production trims stored in flash
 */
#define PDSS_TRIM_PWM_1_ADDRESS                             (0x400aff8cUL)
#define PDSS_TRIM_PWM_1                                     (*(volatile uint32_t *)(0x400aff8cUL))
#define PDSS_TRIM_PWM_1_DEFAULT                             (0x00000010UL)

/*
 * trim bits for PWM capacitor trimming in feedforward DAC path
 */
#define PDSS_TRIM_PWM_1_CAP_DAC_FF_TRIM_MASK                (0x0000001fUL) /* <0:4> R:RW:16: */
#define PDSS_TRIM_PWM_1_CAP_DAC_FF_TRIM_POS                 (0UL)


/*
 * USBPD Hard IP PWM Trim Register2. Production trims stored in flash
 */
#define PDSS_TRIM_PWM_2_ADDRESS                             (0x400aff90UL)
#define PDSS_TRIM_PWM_2                                     (*(volatile uint32_t *)(0x400aff90UL))
#define PDSS_TRIM_PWM_2_DEFAULT                             (0x0000002aUL)

/*
 * pwm comparator hysteresis trimming
 */
#define PDSS_TRIM_PWM_2_TRIM_PWM_COMP_HYST_MASK             (0x00000003UL) /* <0:1> R:RW:2: */
#define PDSS_TRIM_PWM_2_TRIM_PWM_COMP_HYST_POS              (0UL)


/*
 * hclamp comparator hysteresis trimming
 */
#define PDSS_TRIM_PWM_2_TRIM_HCLAMP_COMP_HYST_MASK          (0x0000000cUL) /* <2:3> R:RW:2: */
#define PDSS_TRIM_PWM_2_TRIM_HCLAMP_COMP_HYST_POS           (2UL)


/*
 * burst exit comparator hysteresis trimming
 */
#define PDSS_TRIM_PWM_2_TRIM_BURST_EXIT_COMP_HYST_MASK      (0x00000030UL) /* <4:5> R:RW:2: */
#define PDSS_TRIM_PWM_2_TRIM_BURST_EXIT_COMP_HYST_POS       (4UL)


/*
 * USBPD Hard IP VCONN40 trim Register. Production trims stored in flash
 */
#define PDSS_TRIM_VCONN40_ADDRESS                           (0x400aff94UL)
#define PDSS_TRIM_VCONN40                                   (*(volatile uint32_t *)(0x400aff94UL))
#define PDSS_TRIM_VCONN40_DEFAULT                           (0x00000000UL)

/*
 *  Trim bits for SCP detection
 * (MSB is inverted)
 * 0000 :  86.34mA (Default)
 * 0001 : 92.94mA
 * 0010 : 99.5mA
 * 0100 : 112.63mA
 * 0111 : 132.31mA (Max)
 * 1000 : 33.51mA
 * 1111 : 79.77mA
 */
#define PDSS_TRIM_VCONN40_SCP_TRIM_MASK                     (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_VCONN40_SCP_TRIM_POS                      (0UL)


/*
 *  Trim bits for oscillator clk frequency
 * 0000 : 3.15MHz
 * 0001 : 2.55MHz
 * 0010 : 1.88MHz
 * 0011 : 1.1MHz
 * 0100 : 5.12MHz
 * 0101 : 4.66MHz
 * 0110 : 4.2MHz
 * 0111 : 3.68MHz
 */
#define PDSS_TRIM_VCONN40_OSC_TRIM_MASK                     (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_TRIM_VCONN40_OSC_TRIM_POS                      (4UL)


/*
 * USBPD Hard IP 40VREG Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_40VREG_0_ADDRESS                          (0x400aff98UL)
#define PDSS_TRIM_40VREG_0                                  (*(volatile uint32_t *)(0x400aff98UL))
#define PDSS_TRIM_40VREG_0_DEFAULT                          (0x00000005UL)

/*
 * Main trim for vreg_out (vddd) with the resolution of 100mV. Vreg_out increases
 * linearly from 4.5v (VREG_MAIN_TRIM = 0x0) to 5.5v (VREG_MAIN_TRIM = 0xA)
 */
#define PDSS_TRIM_40VREG_0_VREG_MAIN_TRIM_MASK              (0x0000000fUL) /* <0:3> R:RW:5: */
#define PDSS_TRIM_40VREG_0_VREG_MAIN_TRIM_POS               (0UL)


/*
 * Fine trim for vreg_out (vddd) with the resolution of ~15mV
 * 000       default
 * 001       default + 15mV
 * 010       default + 30mV
 * 011       default + 45mV
 * 100       default + 60mV
 * 101       default + 75mV
 * 110       default + 90mV
 * 111       default + 105mV
 */
#define PDSS_TRIM_40VREG_0_VREG_FINE_TRIM_MASK              (0x00000070UL) /* <4:6> R:RW:0: */
#define PDSS_TRIM_40VREG_0_VREG_FINE_TRIM_POS               (4UL)


/*
 * USBPD Hard IP 40VREG Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_40VREG_1_ADDRESS                          (0x400aff9cUL)
#define PDSS_TRIM_40VREG_1                                  (*(volatile uint32_t *)(0x400aff9cUL))
#define PDSS_TRIM_40VREG_1_DEFAULT                          (0x0000000bUL)

/*
 * 40Vreg Inrush trimming register with trim step = 10*(1+inrush_det_sel<1:0>)mA;
 * Inrush linearly increases with trim setting.
 */
#define PDSS_TRIM_40VREG_1_VREG_TRIM_INRUSH_MASK            (0x0000000fUL) /* <0:3> R:RW:11: */
#define PDSS_TRIM_40VREG_1_VREG_TRIM_INRUSH_POS             (0UL)


/*
 * USBPD Hard IP LSCSA#1 Trim Register 3. Production trims stored in flash
 */
#define PDSS_TRIM_LSCSA_0_ADDRESS                           (0x400affa0UL)
#define PDSS_TRIM_LSCSA_0                                   (*(volatile uint32_t *)(0x400affa0UL))
#define PDSS_TRIM_LSCSA_0_DEFAULT                           (0x0000001fUL)

/*
 * trim bits for 1st stage V2I Converter input offset correction
 * TRIM CODE from 0 to 63 with a setp of 150uV and from 64 to
 * 0=9.65mV
 * 1=9.5mV
 * ....................
 * 30=5.15mV
 * 31=5mV
 * 32=4.85mV
 * ...........................
 * 62=0.35mV
 * 63=0.2mV
 *
 * trim_v2i_amp_vios<5:0>, set Positive offset asper above table
 * trim_v2i_amp_vios<6>=1, set negative offset of above table
 * trim_v2i_amp_vios<7>=1, double trim step and range of above table
 */
#define PDSS_TRIM_LSCSA_0_V2I_AMP_VIOS_TRIM_MASK            (0x000000ffUL) /* <0:7> R:RW:31: */
#define PDSS_TRIM_LSCSA_0_V2I_AMP_VIOS_TRIM_POS             (0UL)


/*
 * USBPD Hard IP LSCSA#1 Trim Register 4. Production trims stored in flash
 */
#define PDSS_TRIM_LSCSA_1_ADDRESS                           (0x400affa4UL)
#define PDSS_TRIM_LSCSA_1                                   (*(volatile uint32_t *)(0x400affa4UL))
#define PDSS_TRIM_LSCSA_1_DEFAULT                           (0x00000000UL)

/*
 * trim bits for input offset correction of LTRAN High to Low comparator
 * 0=0.5mV
 * 1=3.5mV
 * 2=6.5mV
 * 3=9.5mV
 * 4=12.5mV
 * 5=15.5mV
 * 6=18.5mV
 * 7=21.5mV
 * 8=0.5mV
 * 9=-2.5mV
 * 10=-5.6mV
 * 11=-8.6mV
 * 12=-11.6mV
 * 13=-14.7mV
 * 14=-17.7mV
 * 15=-20.8mV
 */
#define PDSS_TRIM_LSCSA_1_LTRANCOMP_H2L_VIOS_TRIM_MASK      (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_LSCSA_1_LTRANCOMP_H2L_VIOS_TRIM_POS       (0UL)


/*
 * trim bits for input offset correction of LTRAN Low to High comparator
 * 0=0.5mV
 * 1=3.5mV
 * 2=6.5mV
 * 3=9.5mV
 * 4=12.5mV
 * 5=15.5mV
 * 6=18.5mV
 * 7=21.5mV
 * 8=0.5mV
 * 9=-2.5mV
 * 10=-5.6mV
 * 11=-8.6mV
 * 12=-11.6mV
 * 13=-14.7mV
 * 14=-17.7mV
 * 15=-20.8mV
 */
#define PDSS_TRIM_LSCSA_1_LTRANCOMP_L2H_VIOS_TRIM_MASK      (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_TRIM_LSCSA_1_LTRANCOMP_L2H_VIOS_TRIM_POS       (4UL)


/*
 * USBPD Hard IP LSCSA#1 Trim Register 5. Production trims stored in flash
 */
#define PDSS_TRIM_LSCSA_2_ADDRESS                           (0x400affa8UL)
#define PDSS_TRIM_LSCSA_2                                   (*(volatile uint32_t *)(0x400affa8UL))
#define PDSS_TRIM_LSCSA_2_DEFAULT                           (0x00000007UL)

/*
 * trim bits for SCP Comparator to correct vbg_1p2 variation of
 * 0=4.3%
 * 1=3.7%
 * 2=3.1%
 * 3=2.4%
 * 4=1.6%
 * 5=1.1%
 * 6=0.5%
 * 7=0.0%
 * 8=-0.7%
 * 9=-1.176
 * 10=-1.7%
 * 11=-2.1%
 * 12=-2.7%
 * 13=-3.2%
 * 14=-3.6%
 * 15=-4.1%
 */
#define PDSS_TRIM_LSCSA_2_SCP_TRIM_MASK                     (0x0000000fUL) /* <0:3> R:RW:7: */
#define PDSS_TRIM_LSCSA_2_SCP_TRIM_POS                      (0UL)


/*
 * USBPD Hard IP 5V PUMP#1 trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_5VPUMP1_0_ADDRESS                         (0x400affacUL)
#define PDSS_TRIM_5VPUMP1_0                                 (*(volatile uint32_t *)(0x400affacUL))
#define PDSS_TRIM_5VPUMP1_0_DEFAULT                         (0x00000041UL)

/*
 * Trim to change the comparator (used for SOA protection) hysteresis value.
 */
#define PDSS_TRIM_5VPUMP1_0_V5PUMP_PUMP_TRIM8_7_MASK        (0x00000003UL) /* <0:1> R:RW:1: */
#define PDSS_TRIM_5VPUMP1_0_V5PUMP_PUMP_TRIM8_7_POS         (0UL)


/*
 * Trim to change the oscillator frequency which is inside the charge pump.
 * Trim increases the current in oscillator cell which increases the frequency
 */
#define PDSS_TRIM_5VPUMP1_0_V5PUMP_PUMP_TRIM6_4_MASK        (0x0000001cUL) /* <2:4> R:RW:0: */
#define PDSS_TRIM_5VPUMP1_0_V5PUMP_PUMP_TRIM6_4_POS         (2UL)


/*
 * Trim to change the tail current in opamp
 */
#define PDSS_TRIM_5VPUMP1_0_V5PUMP_OPA_TRIM_MASK            (0x00000060UL) /* <5:6> R:RW:2: */
#define PDSS_TRIM_5VPUMP1_0_V5PUMP_OPA_TRIM_POS             (5UL)


/*
 * USBPD Hard IP 5V PUMP#1 trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_5VPUMP1_1_ADDRESS                         (0x400affb0UL)
#define PDSS_TRIM_5VPUMP1_1                                 (*(volatile uint32_t *)(0x400affb0UL))
#define PDSS_TRIM_5VPUMP1_1_DEFAULT                         (0x00000005UL)

/*
 * Trim to change the charge pump output voltage by modifying the resistance
 * in the feed back divider
 */
#define PDSS_TRIM_5VPUMP1_1_V5PUMP_PUMP_TRIM3_0_MASK        (0x0000000fUL) /* <0:3> R:RW:5: */
#define PDSS_TRIM_5VPUMP1_1_V5PUMP_PUMP_TRIM3_0_POS         (0UL)


/*
 * USBPD Hard IP BG ref trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_BG_REF_ADDRESS                            (0x400affb4UL)
#define PDSS_TRIM_BG_REF                                    (*(volatile uint32_t *)(0x400affb4UL))
#define PDSS_TRIM_BG_REF_DEFAULT                            (0x00000016UL)

/*
 *  Signal for trimming vref_1p2 output
 */
#define PDSS_TRIM_BG_REF_REF_VTRIM_MASK                     (0x0000003fUL) /* <0:5> R:RW:22: */
#define PDSS_TRIM_BG_REF_REF_VTRIM_POS                      (0UL)


/*
 *  Signal for trimming temperature coefficient of BG
 */
#define PDSS_TRIM_BG_REF_REF_TCTRIM_MASK                    (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_TRIM_BG_REF_REF_TCTRIM_POS                     (6UL)


/*
 * USBPD 150C ADC Data. Production trims stored in flash
 */
#define PDSS_TRIM_OTP_0_ADDRESS                             (0x400affb8UL)
#define PDSS_TRIM_OTP_0                                     (*(volatile uint32_t *)(0x400affb8UL))
#define PDSS_TRIM_OTP_0_DEFAULT                             (0x00000000UL)

/*
 * ADC value for 150C
 */
#define PDSS_TRIM_OTP_0_ADC_150C_TRIM_MASK                  (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_TRIM_OTP_0_ADC_150C_TRIM_POS                   (0UL)


/*
 * USBPD -45C ADC Data. Production trims stored in flash
 */
#define PDSS_TRIM_OTP_1_ADDRESS                             (0x400affbcUL)
#define PDSS_TRIM_OTP_1                                     (*(volatile uint32_t *)(0x400affbcUL))
#define PDSS_TRIM_OTP_1_DEFAULT                             (0x00000000UL)

/*
 * ADC value for -45C
 */
#define PDSS_TRIM_OTP_1_ADC_N45C_TRIM_MASK                  (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_TRIM_OTP_1_ADC_N45C_TRIM_POS                   (0UL)


/*
 * Link to Cortex M0 ROM Table.
 */
#define ROMTABLE_ADDR_ADDRESS                               (0xf0000000UL)
#define ROMTABLE_ADDR                                       (*(volatile uint32_t *)(0xf0000000UL))
#define ROMTABLE_ADDR_DEFAULT                               (0xf00ff003UL)

/*
 * Entry present.
 */
#define ROMTABLE_ADDR_PRESENT                               (1UL << 0) /* <0:0> R:R:1: */


/*
 * ROM Table format:
 * '0: 8-bit format.
 * '1': 32-bit format.
 */
#define ROMTABLE_ADDR_FORMAT_32BIT                          (1UL << 1) /* <1:1> R:R:1: */


/*
 * Address offset of the Cortex-M0 ROM Table base address (0xe00f:f000) wrt.
 * Cypress chip specific ROM Table base address (0xf000:0000). ADDR_OFFSET[19:0]
 * = 0xe00f:f - 0xf000:0 = 0xf00f:f.
 */
#define ROMTABLE_ADDR_ADDR_OFFSET_MASK                      (0xfffff000UL) /* <12:31> R:R:983295: */
#define ROMTABLE_ADDR_ADDR_OFFSET_POS                       (12UL)


/*
 * Device Type Identifier register.
 */
#define ROMTABLE_DID_ADDRESS                                (0xf0000fccUL)
#define ROMTABLE_DID                                        (*(volatile uint32_t *)(0xf0000fccUL))
#define ROMTABLE_DID_DEFAULT                                (0x00000001UL)

/*
 * .
 */
#define ROMTABLE_DID_VALUE_MASK                             (0xffffffffUL) /* <0:31> R:R:1: */
#define ROMTABLE_DID_VALUE_POS                              (0UL)


/*
 * Peripheral Identification Register 4.
 */
#define ROMTABLE_PID4_ADDRESS                               (0xf0000fd0UL)
#define ROMTABLE_PID4                                       (*(volatile uint32_t *)(0xf0000fd0UL))
#define ROMTABLE_PID4_DEFAULT                               (0x00000000UL)

/*
 * JEP106 continuation code.  This value is product specific and specified
 * as part of the product definition in the CPUSS.JEPCONTINUATION parameter.
 */
#define ROMTABLE_PID4_JEP_CONTINUATION_MASK                 (0x0000000fUL) /* <0:3> R:R:Undefined: */
#define ROMTABLE_PID4_JEP_CONTINUATION_POS                  (0UL)


/*
 * Size of ROM Table is 2^COUNT * 4 KByte.
 */
#define ROMTABLE_PID4_COUNT_MASK                            (0x000000f0UL) /* <4:7> R:R:0: */
#define ROMTABLE_PID4_COUNT_POS                             (4UL)


/*
 * Peripheral Identification Register 5.
 */
#define ROMTABLE_PID5_ADDRESS                               (0xf0000fd4UL)
#define ROMTABLE_PID5                                       (*(volatile uint32_t *)(0xf0000fd4UL))
#define ROMTABLE_PID5_DEFAULT                               (0x00000000UL)

/*
 * .
 */
#define ROMTABLE_PID5_VALUE_MASK                            (0xffffffffUL) /* <0:31> R:R:0: */
#define ROMTABLE_PID5_VALUE_POS                             (0UL)


/*
 * Peripheral Identification Register 6.
 */
#define ROMTABLE_PID6_ADDRESS                               (0xf0000fd8UL)
#define ROMTABLE_PID6                                       (*(volatile uint32_t *)(0xf0000fd8UL))
#define ROMTABLE_PID6_DEFAULT                               (0x00000000UL)

/*
 * .
 */
#define ROMTABLE_PID6_VALUE_MASK                            (0xffffffffUL) /* <0:31> R:R:0: */
#define ROMTABLE_PID6_VALUE_POS                             (0UL)


/*
 * Peripheral Identification Register 7.
 */
#define ROMTABLE_PID7_ADDRESS                               (0xf0000fdcUL)
#define ROMTABLE_PID7                                       (*(volatile uint32_t *)(0xf0000fdcUL))
#define ROMTABLE_PID7_DEFAULT                               (0x00000000UL)

/*
 * .
 */
#define ROMTABLE_PID7_VALUE_MASK                            (0xffffffffUL) /* <0:31> R:R:0: */
#define ROMTABLE_PID7_VALUE_POS                             (0UL)


/*
 * Peripheral Identification Register 0.
 */
#define ROMTABLE_PID0_ADDRESS                               (0xf0000fe0UL)
#define ROMTABLE_PID0                                       (*(volatile uint32_t *)(0xf0000fe0UL))
#define ROMTABLE_PID0_DEFAULT                               (0x00000000UL)

/*
 * JEP106 part number. 4 lsbs of CPUSS.PARTNUMBER parameter.  These part
 * numbers are maintained in spec 40-9500.
 */
#define ROMTABLE_PID0_PN_MIN_MASK                           (0x000000ffUL) /* <0:7> R:R:Undefined: */
#define ROMTABLE_PID0_PN_MIN_POS                            (0UL)


/*
 * Peripheral Identification Register 1.
 */
#define ROMTABLE_PID1_ADDRESS                               (0xf0000fe4UL)
#define ROMTABLE_PID1                                       (*(volatile uint32_t *)(0xf0000fe4UL))
#define ROMTABLE_PID1_DEFAULT                               (0x00000000UL)

/*
 * JEP106 part number. 4 msbs of CPUSS.PARTNUMBER parameter.  These part
 * numbers are maintained in spec 40-9500.
 */
#define ROMTABLE_PID1_PN_MAJ_MASK                           (0x0000000fUL) /* <0:3> R:R:Undefined: */
#define ROMTABLE_PID1_PN_MAJ_POS                            (0UL)


/*
 * JEP106 vendor id. 4 lsbs of CPUSS.JEPID parameter.  This number is maintained
 * in spec 40-9500.
 */
#define ROMTABLE_PID1_JEPID_MIN_MASK                        (0x000000f0UL) /* <4:7> R:R:Undefined: */
#define ROMTABLE_PID1_JEPID_MIN_POS                         (4UL)


/*
 * Peripheral Identification Register 2.
 */
#define ROMTABLE_PID2_ADDRESS                               (0xf0000fe8UL)
#define ROMTABLE_PID2                                       (*(volatile uint32_t *)(0xf0000fe8UL))
#define ROMTABLE_PID2_DEFAULT                               (0x00000000UL)

/*
 * JEP106 vendor id. 4 msbs of CPUSS.JEPID parameter.  This number is maintained
 * in spec 40-9500.
 */
#define ROMTABLE_PID2_JEPID_MAJ_MASK                        (0x00000007UL) /* <0:2> R:R:Undefined: */
#define ROMTABLE_PID2_JEPID_MAJ_POS                         (0UL)


/*
 * Major REVision number (chip specific). Identifies the design iteration
 * of the component. For first tape out: 0x1. This field is implemented in
 * RTL by an ECO-able tie-off structure and is incremented on subsequent
 * tape outs.
 */
#define ROMTABLE_PID2_REV_MASK                              (0x000000f0UL) /* <4:7> R:R:Undefined: */
#define ROMTABLE_PID2_REV_POS                               (4UL)


/*
 * Peripheral Identification Register 3.
 */
#define ROMTABLE_PID3_ADDRESS                               (0xf0000fecUL)
#define ROMTABLE_PID3                                       (*(volatile uint32_t *)(0xf0000fecUL))
#define ROMTABLE_PID3_DEFAULT                               (0x00000000UL)

/*
 * Customer modified field. This field is used to track modifications to
 * the original component design as a result of component IP reuse.
 */
#define ROMTABLE_PID3_CM_MASK                               (0x0000000fUL) /* <0:3> R:R:0: */
#define ROMTABLE_PID3_CM_POS                                (0UL)


/*
 * Minor REVision number (chip specific). For first tape out: 0x1. This field
 * is implemented in RTL by an ECO-able tie-off structure and is incremented
 * on subsequent tape outs.
 */
#define ROMTABLE_PID3_REV_AND_MASK                          (0x000000f0UL) /* <4:7> R:R:Undefined: */
#define ROMTABLE_PID3_REV_AND_POS                           (4UL)


/*
 * Component Identification Register 0.
 */
#define ROMTABLE_CID0_ADDRESS                               (0xf0000ff0UL)
#define ROMTABLE_CID0                                       (*(volatile uint32_t *)(0xf0000ff0UL))
#define ROMTABLE_CID0_DEFAULT                               (0x0000000dUL)

/*
 * Component identification byte 0 of 4-byte component identification 0xB105:100D.
 */
#define ROMTABLE_CID0_VALUE_MASK                            (0xffffffffUL) /* <0:31> R:R:13: */
#define ROMTABLE_CID0_VALUE_POS                             (0UL)


/*
 * Component Identification Register 1.
 */
#define ROMTABLE_CID1_ADDRESS                               (0xf0000ff4UL)
#define ROMTABLE_CID1                                       (*(volatile uint32_t *)(0xf0000ff4UL))
#define ROMTABLE_CID1_DEFAULT                               (0x00000010UL)

/*
 * Component identification byte 1 of 4-byte component identification 0xB105:100D.
 * Component class: "ROM Table".
 */
#define ROMTABLE_CID1_VALUE_MASK                            (0xffffffffUL) /* <0:31> R:R:16: */
#define ROMTABLE_CID1_VALUE_POS                             (0UL)


/*
 * Component Identification Register 2.
 */
#define ROMTABLE_CID2_ADDRESS                               (0xf0000ff8UL)
#define ROMTABLE_CID2                                       (*(volatile uint32_t *)(0xf0000ff8UL))
#define ROMTABLE_CID2_DEFAULT                               (0x00000005UL)

/*
 * Component identification byte 2 of 4-byte component identification 0xB105:100D.
 */
#define ROMTABLE_CID2_VALUE_MASK                            (0xffffffffUL) /* <0:31> R:R:5: */
#define ROMTABLE_CID2_VALUE_POS                             (0UL)


/*
 * Component Identification Register 3.
 */
#define ROMTABLE_CID3_ADDRESS                               (0xf0000ffcUL)
#define ROMTABLE_CID3                                       (*(volatile uint32_t *)(0xf0000ffcUL))
#define ROMTABLE_CID3_DEFAULT                               (0x000000b1UL)

/*
 * Component identification byte 3 of 4-byte component identification 0xB105:100D.
 */
#define ROMTABLE_CID3_VALUE_MASK                            (0xffffffffUL) /* <0:31> R:R:177: */
#define ROMTABLE_CID3_VALUE_POS                             (0UL)



/** \endcond */

#endif /* _REG_TOP_H_ */

