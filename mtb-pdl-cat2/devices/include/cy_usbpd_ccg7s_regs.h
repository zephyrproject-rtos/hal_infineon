/***************************************************************************//**
* \file cy_usbpd_ccg7s_regs.h
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
#ifndef _CY_USBPD_CCG7S_REGS_H_
#define _CY_USBPD_CCG7S_REGS_H_

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
    volatile uint32_t hpd_ctrl1;                          /* 0x400a00ecUL */
    volatile uint32_t hpd_ctrl2;                          /* 0x400a00f0UL */
    volatile uint32_t hpd_ctrl3;                          /* 0x400a00f4UL */
    volatile uint32_t hpd_ctrl4;                          /* 0x400a00f8UL */
    volatile uint32_t hpd_ctrl5;                          /* 0x400a00fcUL */
    volatile uint32_t hpd_queue;                          /* 0x400a0100UL */
    volatile uint32_t hpdt_ctrl1;                         /* 0x400a0104UL */
    volatile uint32_t hpdt_ctrl2;                         /* 0x400a0108UL */
    volatile uint32_t rsrvd2[7];
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
    volatile uint32_t adc_sar_ctrl[2];                    /* 0x400a01c0UL */
    volatile uint32_t rsrvd12[6];
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
    volatile uint32_t intr1_cfg_cc12_ocp_hs;              /* 0x400a02acUL */
    volatile uint32_t intr1_cfg_cc12_ovp_hs;              /* 0x400a02b0UL */
    volatile uint32_t intr1_status;                       /* 0x400a02b4UL */
    volatile uint32_t intr1;                              /* 0x400a02b8UL */
    volatile uint32_t intr1_set;                          /* 0x400a02bcUL */
    volatile uint32_t intr1_mask;                         /* 0x400a02c0UL */
    volatile uint32_t intr1_masked;                       /* 0x400a02c4UL */
    volatile uint32_t rsrvd15[15];
    volatile uint32_t intr3_cfg_adc_hs[2];                /* 0x400a0304UL */
    volatile uint32_t rsrvd16[13];
    volatile uint32_t intr3_status_0;                     /* 0x400a0340UL */
    volatile uint32_t rsrvd17;
    volatile uint32_t intr3;                              /* 0x400a0348UL */
    volatile uint32_t intr3_set;                          /* 0x400a034cUL */
    volatile uint32_t intr3_mask;                         /* 0x400a0350UL */
    volatile uint32_t intr3_masked;                       /* 0x400a0354UL */
    volatile uint32_t rsrvd18[10];
    volatile uint32_t intr5_filter_cfg[5];                /* 0x400a0380UL */
    volatile uint32_t rsrvd19[19];
    volatile uint32_t intr5_status_0;                     /* 0x400a03e0UL */
    volatile uint32_t rsrvd20;
    volatile uint32_t intr5;                              /* 0x400a03e8UL */
    volatile uint32_t intr5_set;                          /* 0x400a03ecUL */
    volatile uint32_t intr5_mask;                         /* 0x400a03f0UL */
    volatile uint32_t intr5_masked;                       /* 0x400a03f4UL */
    volatile uint32_t rsrvd21[10];
    volatile uint32_t intr7_filter_cfg[2];                /* 0x400a0420UL */
    volatile uint32_t rsrvd22[6];
    volatile uint32_t intr7_status;                       /* 0x400a0440UL */
    volatile uint32_t intr7;                              /* 0x400a0444UL */
    volatile uint32_t intr7_set;                          /* 0x400a0448UL */
    volatile uint32_t intr7_mask;                         /* 0x400a044cUL */
    volatile uint32_t intr7_masked;                       /* 0x400a0450UL */
    volatile uint32_t rsrvd23[7];
    volatile uint32_t intr9_cfg_bch_det[1];               /* 0x400a0470UL */
    volatile uint32_t rsrvd24[6];
    volatile uint32_t intr9_status_0;                     /* 0x400a048cUL */
    volatile uint32_t intr9_status_1;                     /* 0x400a0490UL */
    volatile uint32_t intr9;                              /* 0x400a0494UL */
    volatile uint32_t intr9_set;                          /* 0x400a0498UL */
    volatile uint32_t intr9_mask;                         /* 0x400a049cUL */
    volatile uint32_t intr9_masked;                       /* 0x400a04a0UL */
    volatile uint32_t rsrvd25[7];
    volatile uint32_t intr11_filter_cfg;                  /* 0x400a04c0UL */
    volatile uint32_t intr11_status_0;                    /* 0x400a04c4UL */
    volatile uint32_t intr11;                             /* 0x400a04c8UL */
    volatile uint32_t intr11_set;                         /* 0x400a04ccUL */
    volatile uint32_t intr11_mask;                        /* 0x400a04d0UL */
    volatile uint32_t intr11_masked;                      /* 0x400a04d4UL */
    volatile uint32_t rsrvd26;
    volatile uint32_t intr13_status;                      /* 0x400a04dcUL */
    volatile uint32_t intr13;                             /* 0x400a04e0UL */
    volatile uint32_t intr13_set;                         /* 0x400a04e4UL */
    volatile uint32_t intr13_mask;                        /* 0x400a04e8UL */
    volatile uint32_t intr13_masked;                      /* 0x400a04ecUL */
    volatile uint32_t intr13_cfg_csa_scp_hs;              /* 0x400a04f0UL */
    volatile uint32_t rsrvd27[3];
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
    volatile uint32_t rsrvd28[12];
    volatile uint32_t ddft_mux;                           /* 0x400a0580UL */
    volatile uint32_t intr_ddft_mux;                      /* 0x400a0584UL */
    volatile uint32_t ncell_ddft_mux;                     /* 0x400a0588UL */
    volatile uint32_t gpio_ddft_mux;                      /* 0x400a058cUL */
    volatile uint32_t gpio_intr_ddft_mux;                 /* 0x400a0590UL */
    volatile uint32_t rsrvd29;
    volatile uint32_t fault_gpio_ctrl_extr;               /* 0x400a0598UL */
    volatile uint32_t rsrvd30[25];
    volatile uint32_t cc_ctrl_0;                          /* 0x400a0600UL */
    volatile uint32_t cc_ctrl_1;                          /* 0x400a0604UL */
    volatile uint32_t dpslp_ref_ctrl;                     /* 0x400a0608UL */
    volatile uint32_t rsrvd31[4];
    volatile uint32_t vreg_vsys_ctrl;                     /* 0x400a061cUL */
    volatile uint32_t rsrvd32[2];
    volatile uint32_t amux_ctrl;                          /* 0x400a0628UL */
    volatile uint32_t rsrvd33;
    volatile uint32_t amux_denfet_ctrl;                   /* 0x400a0630UL */
    volatile uint32_t rsrvd34[19];
    volatile uint32_t adc_ctrl[2];                        /* 0x400a0680UL */
    volatile uint32_t rsrvd35[2];
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
    volatile uint32_t rsrvd44[31];
    volatile uint32_t vconn20_ctrl;                       /* 0x400a0868UL */
    volatile uint32_t pump5v_ctrl;                        /* 0x400a086cUL */
    volatile uint32_t rsrvd45[11];
    volatile uint32_t dischg_shv_1_ctrl[2];               /* 0x400a089cUL */
    volatile uint32_t rsrvd46[6];
    volatile uint32_t csa_scp_0_ctrl;                     /* 0x400a08bcUL */
    volatile uint32_t csa_scp_1_ctrl;                     /* 0x400a08c0UL */
    volatile uint32_t rsrvd47[2];
    volatile uint32_t amux_nhvn_ctrl;                     /* 0x400a08ccUL */
    volatile uint32_t pds_scp_ctrl;                       /* 0x400a08d0UL */
    volatile uint32_t rsrvd48[11];
    volatile uint32_t ngdo_ctrl;                          /* 0x400a0900UL */
    volatile uint32_t rsrvd49[1475];
    volatile uint32_t intr15_cfg_pds_scp;                 /* 0x400a2010UL */
    volatile uint32_t rsrvd50[5];
    volatile uint32_t intr15_cfg_0_pwm;                   /* 0x400a2028UL */
    volatile uint32_t rsrvd51;
    volatile uint32_t intr15_cfg_cc_flag;                 /* 0x400a2030UL */
    volatile uint32_t rsrvd52;
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
    volatile uint32_t rsrvd53[41];
    volatile uint32_t bb_40vreg_ctrl;                     /* 0x400a2108UL */
    volatile uint32_t bb_ea_0_ctrl;                       /* 0x400a210cUL */
    volatile uint32_t bb_ea_1_ctrl;                       /* 0x400a2110UL */
    volatile uint32_t bb_ea_2_ctrl;                       /* 0x400a2114UL */
    volatile uint32_t bb_ea_3_ctrl;                       /* 0x400a2118UL */
    volatile uint32_t bb_40csa_0_ctrl;                    /* 0x400a211cUL */
    volatile uint32_t bb_40csa_1_ctrl;                    /* 0x400a2120UL */
    volatile uint32_t bb_40csa_2_ctrl;                    /* 0x400a2124UL */
    volatile uint32_t bb_40csa_3_ctrl;                    /* 0x400a2128UL */
    volatile uint32_t bb_pwm_0_ctrl;                      /* 0x400a212cUL */
    volatile uint32_t bb_pwm_1_ctrl;                      /* 0x400a2130UL */
    volatile uint32_t bb_pwm_2_ctrl;                      /* 0x400a2134UL */
    volatile uint32_t bb_gdrvo_0_ctrl;                    /* 0x400a2138UL */
    volatile uint32_t bb_gdrvo_1_ctrl;                    /* 0x400a213cUL */
    volatile uint32_t bb_gdrvo_2_ctrl;                    /* 0x400a2140UL */
    volatile uint32_t bb_gdrvo_3_ctrl;                    /* 0x400a2144UL */
    volatile uint32_t bb_gdrvo_4_ctrl;                    /* 0x400a2148UL */
    volatile uint32_t bb_gdrvi_0_ctrl;                    /* 0x400a214cUL */
    volatile uint32_t bb_gdrvi_1_ctrl;                    /* 0x400a2150UL */
    volatile uint32_t bb_gdrvi_2_ctrl;                    /* 0x400a2154UL */
    volatile uint32_t bb_gdrvi_3_ctrl;                    /* 0x400a2158UL */
    volatile uint32_t bb_gdrvi_4_ctrl;                    /* 0x400a215cUL */
    volatile uint32_t bb_ctrl_ovrd;                       /* 0x400a2160UL */
    volatile uint32_t bb_40csa_autocal;                   /* 0x400a2164UL */
    volatile uint32_t bb_bat2gnd_prot_cnfg;               /* 0x400a2168UL */
    volatile uint32_t bb_gdrv_test_ctrl;                  /* 0x400a216cUL */
    volatile uint32_t bb_40csa_4_ctrl;                    /* 0x400a2170UL */
    volatile uint32_t bb_40vregld_ctrl;                   /* 0x400a2174UL */
    volatile uint32_t bb_hssw_ctrl;                       /* 0x400a2178UL */
    volatile uint32_t cc_ctrl_2;                          /* 0x400a217cUL */
    volatile uint32_t rsrvd54[32];
    volatile uint32_t bbctrl_clk_ctrl1;                   /* 0x400a2200UL */
    volatile uint32_t bbctrl_clk_ctrl2;                   /* 0x400a2204UL */
    volatile uint32_t bbctrl_ff_sprd_ctrl;                /* 0x400a2208UL */
    volatile uint32_t bbctrl_audio_t_cnfg;                /* 0x400a220cUL */
    volatile uint32_t bbctrl_buck_sw_ctrl;                /* 0x400a2210UL */
    volatile uint32_t bbctrl_boost_sw_ctrl;               /* 0x400a2214UL */
    volatile uint32_t bbctrl_dutycycle_ctrl;              /* 0x400a2218UL */
    volatile uint32_t bbctrl_func_ctrl;                   /* 0x400a221cUL */
    volatile uint32_t bbctrl_func_ctrl2;                  /* 0x400a2220UL */
    volatile uint32_t bbctrl_func_ctrl3;                  /* 0x400a2224UL */
    volatile uint32_t bbctrl_status;                      /* 0x400a2228UL */
    volatile uint32_t bbctrl_filt_ctrl;                   /* 0x400a222cUL */
    volatile uint32_t bbctrl_ddft_mux;                    /* 0x400a2230UL */
    volatile uint32_t bbctrl_ff_strtup;                   /* 0x400a2234UL */
    volatile uint32_t bbctrl_bb_fixed_cycle_sw_ctrl;      /* 0x400a2238UL */
    volatile uint32_t rsrvd55[5];
    volatile uint32_t ibtr_cfg;                           /* 0x400a2250UL */
    volatile uint32_t ibtr_ctrl;                          /* 0x400a2254UL */
    volatile uint32_t ibtr_opr_value;                     /* 0x400a2258UL */
    volatile uint32_t ibtr_init_fin_value;                /* 0x400a225cUL */
    volatile uint32_t rsrvd56;
    volatile uint32_t ibtr_status;                        /* 0x400a2264UL */
    volatile uint32_t rsrvd57[6];
    volatile uint32_t intr17_cfg_0;                       /* 0x400a2280UL */
    volatile uint32_t intr17_cfg_1;                       /* 0x400a2284UL */
    volatile uint32_t rsrvd58[2];
    volatile uint32_t intr17_cfg_4;                       /* 0x400a2290UL */
    volatile uint32_t intr17_cfg_5;                       /* 0x400a2294UL */
    volatile uint32_t intr17_cfg_6;                       /* 0x400a2298UL */
    volatile uint32_t intr17_cfg_7;                       /* 0x400a229cUL */
    volatile uint32_t intr17_cfg_8;                       /* 0x400a22a0UL */
    volatile uint32_t intr17_cfg_9;                       /* 0x400a22a4UL */
    volatile uint32_t intr17_cfg_10;                      /* 0x400a22a8UL */
    volatile uint32_t intr17_cfg_11;                      /* 0x400a22acUL */
    volatile uint32_t rsrvd59[13];
    volatile uint32_t intr17_status_0;                    /* 0x400a22e4UL */
    volatile uint32_t intr17_status_1;                    /* 0x400a22e8UL */
    volatile uint32_t intr17;                             /* 0x400a22ecUL */
    volatile uint32_t intr17_set;                         /* 0x400a22f0UL */
    volatile uint32_t intr17_mask;                        /* 0x400a22f4UL */
    volatile uint32_t intr17_masked;                      /* 0x400a22f8UL */
    volatile uint32_t rsrvd60[17];
    volatile uint32_t intr10;                             /* 0x400a2340UL */
    volatile uint32_t intr10_set;                         /* 0x400a2344UL */
    volatile uint32_t intr10_mask;                        /* 0x400a2348UL */
    volatile uint32_t intr10_masked;                      /* 0x400a234cUL */
    volatile uint32_t rsrvd61[13];
    volatile uint32_t ccg7d_gpio_ddft_mux;                /* 0x400a2384UL */
    volatile uint32_t ccg7d_ncell_ddft_mux;               /* 0x400a2388UL */
    volatile uint32_t ccg7d_intr_ddft_mux;                /* 0x400a238cUL */
    volatile uint32_t rsrvd62[92];
    volatile uint32_t bb_ngdo_0_gdrv_en_ctrl;             /* 0x400a2500UL */
    volatile uint32_t bb_ngdo_1_gdrv_en_ctrl;             /* 0x400a2504UL */
} PDSS_REGS_T, *PPDSS_REGS_T;

#define PDSS        ((PPDSS_REGS_T) PDSS_BASE_ADDR)
#define PDSS0        PDSS


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
    volatile uint32_t trim_spare0;                        /* 0x400aff20UL */
    volatile uint32_t trim_spare1;                        /* 0x400aff24UL */
    volatile uint32_t trim_5vpump1_0;                     /* 0x400aff28UL */
    volatile uint32_t trim_5vpump1_1;                     /* 0x400aff2cUL */
    volatile uint32_t trim_dpslp_0;                       /* 0x400aff30UL */
    volatile uint32_t trim_dpslp_1;                       /* 0x400aff34UL */
    volatile uint32_t trim_refgen1_0;                     /* 0x400aff38UL */
    volatile uint32_t trim_refgen1_1;                     /* 0x400aff3cUL */
    volatile uint32_t trim_ngdo_0;                        /* 0x400aff40UL */
    volatile uint32_t trim_ngdo_1;                        /* 0x400aff44UL */
    volatile uint32_t trim_bch_det1_0;                    /* 0x400aff48UL */
    volatile uint32_t trim_bch_det1_1;                    /* 0x400aff4cUL */
    volatile uint32_t trim_bch_det1_2;                    /* 0x400aff50UL */
    volatile uint32_t trim_bch_det1_3;                    /* 0x400aff54UL */
    volatile uint32_t trim_scp;                           /* 0x400aff58UL */
    volatile uint32_t trim_bb_20vconn_0;                  /* 0x400aff5cUL */
    volatile uint32_t trim_bb_20vconn_1;                  /* 0x400aff60UL */
    volatile uint32_t trim_bb_20vconn_2;                  /* 0x400aff64UL */
    volatile uint32_t trim_bb_20vconn_3;                  /* 0x400aff68UL */
    volatile uint32_t trim_bb_20csa_0;                    /* 0x400aff6cUL */
    volatile uint32_t trim_bb_20csa_1;                    /* 0x400aff70UL */
    volatile uint32_t trim_bb_20csa_2;                    /* 0x400aff74UL */
    volatile uint32_t trim_bb_20csa_3;                    /* 0x400aff78UL */
    volatile uint32_t trim_bb_40vreg_0;                   /* 0x400aff7cUL */
    volatile uint32_t trim_bb_40vreg_1;                   /* 0x400aff80UL */
    volatile uint32_t trim_bb_ea_0;                       /* 0x400aff84UL */
    volatile uint32_t trim_bb_ea_1;                       /* 0x400aff88UL */
    volatile uint32_t trim_bb_ea_2;                       /* 0x400aff8cUL */
    volatile uint32_t trim_bb_ea_3;                       /* 0x400aff90UL */
    volatile uint32_t trim_bb_40csa_0;                    /* 0x400aff94UL */
    volatile uint32_t trim_bb_40csa_1;                    /* 0x400aff98UL */
    volatile uint32_t trim_bb_40csa_2;                    /* 0x400aff9cUL */
    volatile uint32_t trim_bb_pwm_0;                      /* 0x400affa0UL */
    volatile uint32_t trim_bb_pwm_1;                      /* 0x400affa4UL */
    volatile uint32_t trim_bb_pwm_2;                      /* 0x400affa8UL */
    volatile uint32_t trim_bb_pwm_3;                      /* 0x400affacUL */
    volatile uint32_t trim_bb_gdrvo_0;                    /* 0x400affb0UL */
    volatile uint32_t trim_bb_gdrvo_1;                    /* 0x400affb4UL */
    volatile uint32_t trim_bb_gdrvi_0;                    /* 0x400affb8UL */
    volatile uint32_t trim_bb_gdrvi_1;                    /* 0x400affbcUL */
    volatile uint32_t trim_cc_8;                          /* 0x400affc0UL */
} PDSS_TRIMS_REGS_T, *PPDSS_TRIMS_REGS_T;

#define PDSS_TRIMS        ((PPDSS_TRIMS_REGS_T) PDSS_TRIMS_BASE_ADDR)
#define PDSS_TRIMS0        PDSS_TRIMS


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
 * Defines the direction of GPIO used for HPD operation.
 * 0: GPIO is input. Receive operation.
 * 1: GPIO is output. Transmit operation
 * This bit must be set for correct mode of HPD operation (Receive / Transmit).
 */
#define PDSS_CTRL_HPD_DIRECTION                             (1UL << 3) /* <3:3> R:RW:0:HPD_EN */


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
 * 0: Clocks is turn off for HPD block
 * 1: Clock is runing in the HPD block
 * This bit must be set when HPD Receive functionality is needed. This will
 * turn clock on for the RX module. resetting to zero will turn clock off.
 * Clock used for HPD is same clock that is used for CC transmit module (600
 * Khz).
 */
#define PDSS_CTRL_HPD_ENABLED                               (1UL << 29) /* <29:29> R:RW:0:HPD_EN */


/*
 * 0: Clocks is turn off for HPDT block
 * 1: Clock is runing in the HPDT block.
 * This bit must be set when HPDT transmit functionality is needed. This
 * will turn clock on for the TX module. resetting to zero will turn clock
 * off.
 * Clock used for HPD is same clock that is used for CC transmit module (600
 * Khz).
 */
#define PDSS_CTRL_HPDT_ENABLED                              (1UL << 30) /* <30:30> R:RW:0:HPD_EN */


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
 * This register are for debugging purposes.
 * 0: BBCTRL block  is in non-reset mode.
 * 1: Reset the logic on the BBCTRL except the Hard-IP.
 */
#define PDSS_DEBUG_CTRL_RESET_BBCTRL                        (1UL << 12) /* <12:12> R:RW:0:PDBBC_EN */


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
 * 0: BB_SOFT clock domain  is in non-reset mode.
 * 1: Reset the logic on the BB_SOFT clock domain.
 */
#define PDSS_DEBUG_CTRL_RESET_BB_SOFT                       (1UL << 28) /* <28:28> R:RW:0:PDBBC_EN */


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
 * Configures HPD module, IRQ_MIN, IRQ_MAX and ENABLE
 */
#define PDSS_HPD_CTRL1_ADDRESS                              (0x400a00ecUL)
#define PDSS_HPD_CTRL1                                      (*(volatile uint32_t *)(0x400a00ecUL))
#define PDSS_HPD_CTRL1_DEFAULT                              (0x8025812cUL)

/*
 * Defines the min width of IRQ pulse. Default = 0.5 ms. Assumes 600 Khz
 * clock.
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPD_CTRL1_IRQ_MIN_MASK                         (0x00000fffUL) /* <0:11> R:RW:300: */
#define PDSS_HPD_CTRL1_IRQ_MIN_POS                          (0UL)


/*
 * Defines the max width of IRQ pulse. Default = 1.0 ms. Assumes 600 Khz
 * clock.
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPD_CTRL1_IRQ_MAX_MASK                         (0x00fff000UL) /* <12:23> R:RW:600: */
#define PDSS_HPD_CTRL1_IRQ_MAX_POS                          (12UL)


/*
 * When set it flushes the queue.
 */
#define PDSS_HPD_CTRL1_FLUSH_QUEUE                          (1UL << 24) /* <24:24> R:RW:0: */


/*
 * When set, input to hpd module will come from output of hpdt module.
 */
#define PDSS_HPD_CTRL1_LOOPBACK_EN                          (1UL << 30) /* <30:30> R:RW:0: */


/*
 * When set, HPD state machine is at Idle. This bit must be set to zero for
 * HPD module to operate.
 */
#define PDSS_HPD_CTRL1_RESET_HPD_STATE                      (1UL << 31) /* <31:31> R:RW:1: */


/*
 * Configures HPD module, Glitch width.
 */
#define PDSS_HPD_CTRL2_ADDRESS                              (0x400a00f0UL)
#define PDSS_HPD_CTRL2                                      (*(volatile uint32_t *)(0x400a00f0UL))
#define PDSS_HPD_CTRL2_DEFAULT                              (0x00096096UL)

/*
 * Defines the width of glitch. Default = 0.25 ms. Assumes clk of 600 Khz
 * on the rising edge of hpd_in input
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPD_CTRL2_GLITCH_WIDTH_HIGH_MASK               (0x00000fffUL) /* <0:11> R:RW:150: */
#define PDSS_HPD_CTRL2_GLITCH_WIDTH_HIGH_POS                (0UL)


/*
 * Defines the width of glitch. Default = 0.25 ms. Assumes clk of 600 Khz
 * on the falling edge of hpd_in input
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPD_CTRL2_GLITCH_WIDTH_LOW_MASK                (0x00fff000UL) /* <12:23> R:RW:150: */
#define PDSS_HPD_CTRL2_GLITCH_WIDTH_LOW_POS                 (12UL)


/*
 * This field selects the source for the HPD RX Block
 * 0 - GPIO
 * 1 - DDFT0
 * 2 - GPIO_DDFT0
 * 3 - GPIO_DDFT1
 */
#define PDSS_HPD_CTRL2_HPD_IN_SOURCE_SEL_MASK               (0x03000000UL) /* <24:25> R:RW:0:HPD_IN_MUX_EN */
#define PDSS_HPD_CTRL2_HPD_IN_SOURCE_SEL_POS                (24UL)


/*
 * Configures HPD module, stable high and stable low values
 */
#define PDSS_HPD_CTRL3_ADDRESS                              (0x400a00f4UL)
#define PDSS_HPD_CTRL3                                      (*(volatile uint32_t *)(0x400a00f4UL))
#define PDSS_HPD_CTRL3_DEFAULT                              (0x0004b04bUL)

/*
 * Defines the minimum time before plugged condition is detected for subsequent
 * connect.  Default = 2 ms. Assumes 600 Khz clock. This value is internally
 * multiplied by 16.
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPD_CTRL3_STABLE_HIGH_MASK                     (0x00000fffUL) /* <0:11> R:RW:75: */
#define PDSS_HPD_CTRL3_STABLE_HIGH_POS                      (0UL)


/*
 * Defines the minimum time before unplugged condition is detected for subsequent
 * connect.  Default = 2 ms. Assumes 600 Khz clock. This value is internally
 * multiplied by 16.
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPD_CTRL3_STABLE_LOW_MASK                      (0x00fff000UL) /* <12:23> R:RW:75: */
#define PDSS_HPD_CTRL3_STABLE_LOW_POS                       (12UL)


/*
 * Configures HPD module, irq spacing and unplug event
 */
#define PDSS_HPD_CTRL4_ADDRESS                              (0x400a00f8UL)
#define PDSS_HPD_CTRL4                                      (*(volatile uint32_t *)(0x400a00f8UL))
#define PDSS_HPD_CTRL4_DEFAULT                              (0x000004b0UL)

/*
 * Defines the minimum spacing between interrupts  Default = 2 ms. Assumes
 * 600 Khz clock.  If spacing of interrupts received is less than this value,
 * they will be ignored.
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPD_CTRL4_IRQ_SPACING_MASK                     (0x00000fffUL) /* <0:11> R:RW:1200: */
#define PDSS_HPD_CTRL4_IRQ_SPACING_POS                      (0UL)


/*
 * Configures HPD module, Initial LOW and HIGH times
 */
#define PDSS_HPD_CTRL5_ADDRESS                              (0x400a00fcUL)
#define PDSS_HPD_CTRL5                                      (*(volatile uint32_t *)(0x400a00fcUL))
#define PDSS_HPD_CTRL5_DEFAULT                              (0x0ea50ea5UL)

/*
 * Defines the minimum time before plugged condion is detected for initial
 * connect.  Default = 100 ms. Assumes 600 Khz clock. This value is internally
 * multiplied by 16.
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPD_CTRL5_LONG_HIGH_MASK                       (0x0000ffffUL) /* <0:15> R:RW:3749: */
#define PDSS_HPD_CTRL5_LONG_HIGH_POS                        (0UL)


/*
 * Defines the minimum width before unplugged condition is detected.  Default
 * = 100 ms. Assumes 600 Khz clock. This value is internally multiplied by
 * 16..  After LONG_LOW condition is detected, HPD input is expected to stay
 * high equal to LONG_HIGH before plugged condition is reached. This is the
 * optional 100 ms debounce time
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPD_CTRL5_LONG_LOW_MASK                        (0xffff0000UL) /* <16:31> R:RW:3749: */
#define PDSS_HPD_CTRL5_LONG_LOW_POS                         (16UL)


/*
 * HPD queue register
 */
#define PDSS_HPD_QUEUE_ADDRESS                              (0x400a0100UL)
#define PDSS_HPD_QUEUE                                      (*(volatile uint32_t *)(0x400a0100UL))
#define PDSS_HPD_QUEUE_DEFAULT                              (0x00000000UL)

/*
 * This is a read only register. Reading this register will clear the queue
 * in HW. This queue holds 4 locations.
 * Location 0 : bits 1:0.
 * Location 1 : bits 3:2.
 * Location 2 : bits 5:4.
 * Location 3 : bits 7:6.
 * This queue provides a FIFO function. First location written by HW is location
 * 0. The last location is location 3. HW will not write once this queue
 * is full. Reading the Queue will clear the contents. Reading an empty queue
 * will not cause FIFO under run.
 * This queue will hold hpd input events. These events are PLUGGED, UNPLUGGED
 * and IRQ.  Only 2 back to back IRQ will be written into the queue and additional
 * ones will be dropped. When UNPLUGGED is detected, the event will always
 * be written to location 0 of the queue and locations 1 to 3 will be cleared.
 *  The following codes are used to encode events in the queue.
 * 00  : Empty location.
 * 01  : UNPLUGGED.
 * 10  : PLUGGED.
 * 11  : IRQ.
 *
 * Hardware will clear this register when CPU reads it.
 */
#define PDSS_HPD_QUEUE_DATA_OUT_MASK                        (0x000000ffUL) /* <0:7> RW:R:0: */
#define PDSS_HPD_QUEUE_DATA_OUT_POS                         (0UL)


/*
 * HPDT module configure and IRQ width and delay parameters
 */
#define PDSS_HPDT_CTRL1_ADDRESS                             (0x400a0104UL)
#define PDSS_HPDT_CTRL1                                     (*(volatile uint32_t *)(0x400a0104UL))
#define PDSS_HPDT_CTRL1_DEFAULT                             (0x404af1c2UL)

/*
 * Defines the width of IRQ pulse in muliples of 600KHZ clock period. This
 * value sets the width at 0.75 ms.
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPDT_CTRL1_IRQ_WIDTH_MASK                      (0x00000fffUL) /* <0:11> R:RW:450: */
#define PDSS_HPDT_CTRL1_IRQ_WIDTH_POS                       (0UL)


/*
 * Defines the delay to execute IRQ command in multiples of 600KHZ clock
 * period. The default value is 2 ms.
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPDT_CTRL1_SET_IRQ_DELAY_MASK                  (0x00fff000UL) /* <12:23> R:RW:1199: */
#define PDSS_HPDT_CTRL1_SET_IRQ_DELAY_POS                   (12UL)


/*
 * Defines the initial level of the hpdt output.
 */
#define PDSS_HPDT_CTRL1_DEFAULT_LEVEL                       (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Source of data to hpdt_out signal. 0: comes from hpdt module.  1: comes
 * from DATA_SOURCE bit of this register
 */
#define PDSS_HPDT_CTRL1_DATA_SOURCE_SELECT                  (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Data source of hpdt_out output when DATA_SOURCE_SELECT is set high
 */
#define PDSS_HPDT_CTRL1_DATA_SOURCE                         (1UL << 26) /* <26:26> R:RW:0: */


/*
 * Defines the commands to be executed by hpdt module.
 * 0: set hpdt_out to low.
 * 1: set hpdt_out to high.
 * 2: send an IRQ.
 * 3: unused.
 * Note: Send IRQ command does not set GPIO to high level before driving
 * IRQ pulse low. It assumes IRQ is being sent to a plugged device all the
 * time which would mean the GPIO is already at high level.  An IRQ command
 * is received before GPIO is driven to a plugged level, creates an error
 * condition that must be filtered by CPU.
 */
#define PDSS_HPDT_CTRL1_COMMAND_MASK                        (0x18000000UL) /* <27:28> R:RW:0: */
#define PDSS_HPDT_CTRL1_COMMAND_POS                         (27UL)


/*
 * When set, the commands specified by COMMAND bits will be executed. Execution
 * happens on the rising edge of this bit.
 * FW should not clear this bit until INTR2.HPDT_COMMAND_DONE interrupt is
 * set.
 * Hardware clears this bit when command_done is set.
 * Clearing of this command by FW is not necessary and is not recommended.
 */
#define PDSS_HPDT_CTRL1_COMMAND_START                       (1UL << 29) /* <29:29> RW1C:RW:0: */


/*
 * When set, HPDT state machine is at Idle
 * This bit must be reset to zero for the module to operate.
 */
#define PDSS_HPDT_CTRL1_RESET_HPDT_STATE                    (1UL << 30) /* <30:30> R:RW:1: */


/*
 * Defines the HIGH & LOW transition delays.
 */
#define PDSS_HPDT_CTRL2_ADDRESS                             (0x400a0108UL)
#define PDSS_HPDT_CTRL2                                     (*(volatile uint32_t *)(0x400a0108UL))
#define PDSS_HPDT_CTRL2_DEFAULT                             (0x014af4afUL)

/*
 * Defines the delay from HIGH -> LOW transition.  In multiples of 600KHZ
 * clock period. The defaul value is 2 ms.
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPDT_CTRL2_SET_LOW_DELAY_MASK                  (0x00000fffUL) /* <0:11> R:RW:1199: */
#define PDSS_HPDT_CTRL2_SET_LOW_DELAY_POS                   (0UL)


/*
 * Defines the delay from LOW --> HIGH transition.  In multiples of 600KHZ
 * clock period. The defaul value is 2 ms.
 * This register should be adjusted when a different value is needed.
 */
#define PDSS_HPDT_CTRL2_SET_HIGH_DELAY_MASK                 (0x00fff000UL) /* <12:23> R:RW:1199: */
#define PDSS_HPDT_CTRL2_SET_HIGH_DELAY_POS                  (12UL)


/*
 * Defines the default level of HPDT transmit OE.
 * 0: HPD output goes IDLE (OE=0) when module is not selected or module is
 * IDLE state
 * 1: HPD output stays active.
 */
#define PDSS_HPDT_CTRL2_DEFAULT_OE                          (1UL << 24) /* <24:24> R:RW:1: */


/*
 * Defines the source of HPD pin OE.
 * 0: Driven by HW
 * 1: Driven by bit CTRL.HPD_DIRECTION
 */
#define PDSS_HPDT_CTRL2_OE_SOURCE_SELECT                    (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Selects which pins to appear on HPDT debug bus
 *      2'h1     : debug_out   <= count_12_bits_q[3:0]
 *     2'h2     : debug_out   <= count_12_bits_q[7:4]
 *     2'h3     : debug_out   <= count_12_bits_q[11:8]
 *     default  : debug_out   <= {1'h0, state_q}
 */
#define PDSS_HPDT_CTRL2_HPDT_DEBUG_SEL_MASK                 (0x0c000000UL) /* <26:27> R:RW:0: */
#define PDSS_HPDT_CTRL2_HPDT_DEBUG_SEL_POS                  (26UL)


/*
 * The output of debug bus.
 */
#define PDSS_HPDT_CTRL2_HPDT_DEBUG_OUT_MASK                 (0xf0000000UL) /* <28:31> RW:R:0: */
#define PDSS_HPDT_CTRL2_HPDT_DEBUG_OUT_POS                  (28UL)


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
#define PDSS_ADC_SAR_CTRL_ADDRESS(n)                        (0x400a01c0UL + ((n) * (0x0004UL)))
#define PDSS_ADC_SAR_CTRL(n)                                (*(volatile uint32_t *)(0x400a01c0UL + ((n) * 0x0004UL)))
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
 * VCONN20 en_switch_cc1 control 1
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
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CSA_SCP          (1UL << 28) /* <28:28> R:RW:0:CSA_SCP_RCP_EN */


/*
 * 0: CSA OUT detection is not selected for turning off the en_switch_cc1
 * 1: CSA OUT detection is       selected for turning off the en_switch_cc1
 * CCG7D: Unused
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CSA_OUT          (1UL << 29) /* <29:29> R:RW:0:CSA_SCP_RCP_EN */


/*
 * 0: CSA COMP OUT detection is not selected for turning off the en_switch_cc1
 * 1: CSA COMP OUT detection is       selected for turning off the en_switch_cc1
 * CCG7D:
 *     0: CC1_SCP detection is not selected for turning off the en_switch_cc1
 *     1: CC1_SCP detection is       selected for turning off the en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CSA_COMP_OUT     (1UL << 30) /* <30:30> R:RW:0:CSA_SCP_RCP_EN */


/*
 * 0: CSA VBUS OVP detection is not selected for turning off the en_switch_cc1
 * 1: CSA VBUS OVP detection is       selected for turning off the en_switch_cc1
 * CCG7D:
 *     0: CC2_SCP detection is not selected for turning off the en_switch_cc1
 *     1: CC2_SCP detection is       selected for turning off the en_switch_cc1
 */
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CSA_VBUS_OVP     (1UL << 31) /* <31:31> R:RW:0:CSA_SCP_RCP_EN */


/*
 * VCONN20 en_switch_cc1 control 2
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
 * VCONN20 en_switch_cc2 control 1
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
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CSA_SCP          (1UL << 28) /* <28:28> R:RW:0:CSA_SCP_RCP_EN */


/*
 * 0: CSA OUT detection is not selected for turning off the en_switch_cc2
 * 1: CSA OUT detection is       selected for turning off the en_switch_cc2
 * CCG7D: Unused
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CSA_OUT          (1UL << 29) /* <29:29> R:RW:0:CSA_SCP_RCP_EN */


/*
 * 0: CSA COMP OUT detection is not selected for turning off the en_switch_cc2
 * 1: CSA COMP OUT detection is       selected for turning off the en_switch_cc2
 * CCG7D:
 *     0: CC1_SCP detection is not selected for turning off the en_switch_cc2
 *     1: CC1_SCP detection is       selected for turning off the en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CSA_COMP_OUT     (1UL << 30) /* <30:30> R:RW:0:CSA_SCP_RCP_EN */


/*
 * 0: CSA VBUS OVP detection is not selected for turning off the en_switch_cc2
 * 1: CSA VBUS OVP detection is       selected for turning off the en_switch_cc2
 * CCG7D:
 *     0: CC2_SCP detection is not selected for turning off the en_switch_cc2
 *     1: CC2_SCP detection is       selected for turning off the en_switch_cc2
 */
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CSA_VBUS_OVP     (1UL << 31) /* <31:31> R:RW:0:CSA_SCP_RCP_EN */


/*
 * VCONN20 en_switch_cc2 control 2
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
 * VCONN20 pump_en control 1
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
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CSA_SCP             (1UL << 28) /* <28:28> R:RW:0:CSA_SCP_RCP_EN */


/*
 * 0: CSA OUT detection is not selected for turning off the vconn20 en_pump
 * 1: CSA OUT detection is       selected for turning off the vconn20 en_pump
 * CCG7D: Unused
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CSA_OUT             (1UL << 29) /* <29:29> R:RW:0:CSA_SCP_RCP_EN */


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
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CSA_COMP_OUT        (1UL << 30) /* <30:30> R:RW:0:CSA_SCP_RCP_EN */


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
#define PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CSA_VBUS_OVP        (1UL << 31) /* <31:31> R:RW:0:CSA_SCP_RCP_EN */


/*
 * VCONN20 pump_en control 2
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
 * Filtering the v5v_det from s8usbpd so FW can enable the VCONN FET to route
 * the V5V to appropriate VCONN line (CC1/CC2)
 * 0: No Filtering
 * 1: Enable 2 cycles of clk_lf filtering
 */
#define PDSS_INTR1_CFG_V5V_FILT_EN                          (1UL << 10) /* <10:10> R:RW:0:V5V_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_V5V_CFG_MASK                         (0x00001800UL) /* <11:12> R:RW:0:V5V_EN */
#define PDSS_INTR1_CFG_V5V_CFG_POS                          (11UL)


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
#define PDSS_INTR1_CFG_V5V_FILT_RESET                       (1UL << 13) /* <13:13> R:RW:0:V5V_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_V5V_FILT_BYPASS                      (1UL << 14) /* <14:14> R:RW:0:V5V_EN */


/*
 * Filtering the HPDIN_ATTACH .
 * 0: No Filtering
 * 1: Enable 2 cycles of clk_lf filtering
 */
#define PDSS_INTR1_CFG_HPDIN_FILT_EN                        (1UL << 15) /* <15:15> R:RW:0:HPD_EN */


/*
 * Edge detect positive/negative enable/disable. For HPD_IN input
 */
#define PDSS_INTR1_CFG_HPDIN_CFG_MASK                       (0x00030000UL) /* <16:17> R:RW:0:HPD_EN */
#define PDSS_INTR1_CFG_HPDIN_CFG_POS                        (16UL)


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
#define PDSS_INTR1_CFG_HPDIN_FILT_RESET                     (1UL << 18) /* <18:18> R:RW:0:HPD_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_HPDIN_FILT_BYPASS                    (1UL << 19) /* <19:19> R:RW:0:HPD_EN */


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
 * CC1/CC2 OCP Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_ADDRESS                  (0x400a02acUL)
#define PDSS_INTR1_CFG_CC12_OCP_HS                          (*(volatile uint32_t *)(0x400a02acUL))
#define PDSS_INTR1_CFG_CC12_OCP_HS_DEFAULT                  (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_EN          (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_CFG_POS     (1UL)


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
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_RESET       (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_BYPASS      (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_SEL_POS     (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_DPSLP_MODE       (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_EN          (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_CFG_MASK    (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_CFG_POS     (12UL)


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
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_RESET       (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_BYPASS      (1UL << 15) /* <15:15> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_SEL_MASK    (0x001f0000UL) /* <16:20> R:RW:0: */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_SEL_POS     (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_DPSLP_MODE       (1UL << 21) /* <21:21> R:RW:0: */


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
 * This status bit shows the v5v from 300ma or Vconn20
 */
#define PDSS_INTR1_STATUS_V5V_STATUS                        (1UL << 14) /* <14:14> RW:R:0:V5V_EN */


/*
 * V5V Filtered output
 */
#define PDSS_INTR1_STATUS_V5V_FILT                          (1UL << 15) /* <15:15> RW:R:0:V5V_EN */


/*
 * This reads the level of HPD input from GPIO.
 */
#define PDSS_INTR1_STATUS_HPD_STATUS                        (1UL << 16) /* <16:16> RW:R:0:HPD_EN */


/*
 * HDPIN OUT Filtered output
 */
#define PDSS_INTR1_STATUS_HPD_FILT                          (1UL << 17) /* <17:17> RW:R:0:HPD_EN */


/*
 * This reads the CC1 over-current signal from s8usbpd2_20Vconn_sw_top
 */
#define PDSS_INTR1_STATUS_CC1_OCP_STATUS                    (1UL << 18) /* <18:18> RW:R:0:VCONN20_EN */


/*
 * CC1_OCP Detect Filtered output
 */
#define PDSS_INTR1_STATUS_CC1_OCP_FILT                      (1UL << 19) /* <19:19> RW:R:0:VCONN20_EN */


/*
 * This reads the CC2 over-current signal from s8usbpd2_20Vconn_sw_top
 */
#define PDSS_INTR1_STATUS_CC2_OCP_STATUS                    (1UL << 20) /* <20:20> RW:R:0:VCONN20_EN */


/*
 * CC2_OCP Detect Filtered output
 */
#define PDSS_INTR1_STATUS_CC2_OCP_FILT                      (1UL << 21) /* <21:21> RW:R:0:VCONN20_EN */


/*
 * This reads the CC1 over-voltage signal from s8usbpd2_20Vconn_sw_top
 */
#define PDSS_INTR1_STATUS_CC1_OVP_STATUS                    (1UL << 22) /* <22:22> RW:R:0:VCONN20_EN */


/*
 * CC1_OVP Detect Filtered output
 */
#define PDSS_INTR1_STATUS_CC1_OVP_FILT                      (1UL << 23) /* <23:23> RW:R:0:VCONN20_EN */


/*
 * This reads the CC2 over-voltage signal from s8usbpd2_20Vconn_sw_top
 */
#define PDSS_INTR1_STATUS_CC2_OVP_STATUS                    (1UL << 24) /* <24:24> RW:R:0:VCONN20_EN */


/*
 * CC2_OVP Detect Filtered output
 */
#define PDSS_INTR1_STATUS_CC2_OVP_FILT                      (1UL << 25) /* <25:25> RW:R:0:VCONN20_EN */


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
 * V5V changed (wakeup interrupt from deepsleep)
 * Check the STATUS.V5V_STATUS value
 */
#define PDSS_INTR1_V5V_CHANGED                              (1UL << 7) /* <7:7> RW1S:RW1C:0:V5V_EN */


/*
 * HPD_IN changed (wakeup interrupt from deepsleep). For HPD input
 * Check the STATUS.HPDIN_STATUS value. Any change in HPD input will trigger
 * a wakeup interrupt.
 */
#define PDSS_INTR1_HPDIN_CHANGED                            (1UL << 8) /* <8:8> RW1S:RW1C:0:HPD_EN */


/*
 * Over-Current is detected on CC1 line
 */
#define PDSS_INTR1_CC1_OCP_CHANGED                          (1UL << 9) /* <9:9> RW1S:RW1C:0:VCONN20_EN */


/*
 * Over-Current is detected on CC2 line
 */
#define PDSS_INTR1_CC2_OCP_CHANGED                          (1UL << 10) /* <10:10> RW1S:RW1C:0:VCONN20_EN */


/*
 * Over-Voltage is detected on CC1 line
 */
#define PDSS_INTR1_CC1_OVP_CHANGED                          (1UL << 11) /* <11:11> RW1S:RW1C:0:VCONN20_EN */


/*
 * Over-Voltage is detected on CC2 line
 */
#define PDSS_INTR1_CC2_OVP_CHANGED                          (1UL << 12) /* <12:12> RW1S:RW1C:0:VCONN20_EN */


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
#define PDSS_INTR1_SET_V5V_CHANGED                          (1UL << 7) /* <7:7> A:RW1S:0:V5V_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_HPDIN_CHANGED                        (1UL << 8) /* <8:8> A:RW1S:0:HPD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC1_OCP_CHANGED                      (1UL << 9) /* <9:9> A:RW1S:0:VCONN20_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC2_OCP_CHANGED                      (1UL << 10) /* <10:10> A:RW1S:0:VCONN20_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC1_OVP_CHANGED                      (1UL << 11) /* <11:11> A:RW1S:0:VCONN20_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC2_OVP_CHANGED                      (1UL << 12) /* <12:12> A:RW1S:0:VCONN20_EN */


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
#define PDSS_INTR1_MASK_V5V_CHANGED_MASK                    (1UL << 7) /* <7:7> R:RW:0:V5V_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_HPDIN_CHANGED_MASK                  (1UL << 8) /* <8:8> R:RW:0:HPD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC1_OCP_CHANGED_MASK                (1UL << 9) /* <9:9> R:RW:0:VCONN20_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC2_OCP_CHANGED_MASK                (1UL << 10) /* <10:10> R:RW:0:VCONN20_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC1_OVP_CHANGED_MASK                (1UL << 11) /* <11:11> R:RW:0:VCONN20_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC2_OVP_CHANGED_MASK                (1UL << 12) /* <12:12> R:RW:0:VCONN20_EN */


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
#define PDSS_INTR1_MASKED_V5V_CHANGED_MASKED                (1UL << 7) /* <7:7> RW:R:0:V5V_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_HPDIN_CHANGED_MASKED              (1UL << 8) /* <8:8> RW:R:0:HPD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC1_OCP_CHANGED_MASKED            (1UL << 9) /* <9:9> RW:R:0:VCONN20_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC2_OCP_CHANGED_MASKED            (1UL << 10) /* <10:10> RW:R:0:VCONN20_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC1_OVP_CHANGED_MASKED            (1UL << 11) /* <11:11> RW:R:0:VCONN20_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC2_OVP_CHANGED_MASKED            (1UL << 12) /* <12:12> RW:R:0:VCONN20_EN */


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
#define PDSS_INTR3_CFG_ADC_HS_ADDRESS(n)                    (0x400a0304UL + ((n) * (0x0004UL)))
#define PDSS_INTR3_CFG_ADC_HS(n)                            (*(volatile uint32_t *)(0x400a0304UL + ((n) * 0x0004UL)))
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
#define PDSS_INTR3_STATUS_0_CMP_OUT_STATUS_MASK             (0x0000000cUL) /* <2:3> RW:R:0:ADC_NUM */
#define PDSS_INTR3_STATUS_0_CMP_OUT_STATUS_POS              (2UL)


/*
 * ADC1-4 COMP_OUT Filtered output
 */
#define PDSS_INTR3_STATUS_0_CMP_OUT_FILT_MASK               (0x000000c0UL) /* <6:7> RW:R:0:ADC_NUM */
#define PDSS_INTR3_STATUS_0_CMP_OUT_FILT_POS                (6UL)


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
#define PDSS_INTR3_CMP_OUT_CHANGED_MASK                     (0x00000006UL) /* <1:2> RW1S:RW1C:0:ADC_NUM */
#define PDSS_INTR3_CMP_OUT_CHANGED_POS                      (1UL)


/*
 * INTR3 Interrupt Set
 */
#define PDSS_INTR3_SET_ADDRESS                              (0x400a034cUL)
#define PDSS_INTR3_SET                                      (*(volatile uint32_t *)(0x400a034cUL))
#define PDSS_INTR3_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_CMP_OUT_CHANGED_MASK                 (0x00000006UL) /* <1:2> A:RW1S:0:ADC_NUM */
#define PDSS_INTR3_SET_CMP_OUT_CHANGED_POS                  (1UL)


/*
 * INTR3 interrupt Mask
 */
#define PDSS_INTR3_MASK_ADDRESS                             (0x400a0350UL)
#define PDSS_INTR3_MASK                                     (*(volatile uint32_t *)(0x400a0350UL))
#define PDSS_INTR3_MASK_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_CMP_OUT_CHANGED_MASK_MASK           (0x00000006UL) /* <1:2> R:RW:0:ADC_NUM */
#define PDSS_INTR3_MASK_CMP_OUT_CHANGED_MASK_POS            (1UL)


/*
 * INTR3 interrupt Masked
 */
#define PDSS_INTR3_MASKED_ADDRESS                           (0x400a0354UL)
#define PDSS_INTR3_MASKED                                   (*(volatile uint32_t *)(0x400a0354UL))
#define PDSS_INTR3_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_CMP_OUT_CHANGED_MASKED_MASK       (0x00000006UL) /* <1:2> RW:R:0:ADC_NUM */
#define PDSS_INTR3_MASKED_CMP_OUT_CHANGED_MASKED_POS        (1UL)


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
#define PDSS_INTR13_STATUS_CSA_OCP_STATUS                   (1UL << 8) /* <8:8> RW:R:0:CSA_SCP_EN */


/*
 * out_d_ocp Filtered output
 */
#define PDSS_INTR13_STATUS_CSA_OCP_FILT                     (1UL << 9) /* <9:9> RW:R:0:CSA_SCP_EN */


/*
 * The status of s8usbpdv2_csa_scp_top.out_d_scp
 */
#define PDSS_INTR13_STATUS_CSA_SCP_STATUS                   (1UL << 10) /* <10:10> RW:R:0:CSA_SCP_EN */


/*
 * s8usbpdv2_csa_scp_top.out_d_scp Filtered output
 */
#define PDSS_INTR13_STATUS_CSA_SCP_FILT                     (1UL << 11) /* <11:11> RW:R:0:CSA_SCP_EN */


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
#define PDSS_INTR13_CSA_OCP_CHANGED                         (1UL << 4) /* <4:4> RW1S:RW1C:0:CSA_SCP_EN */


/*
 * s8usbpdv2_csa_scp_top.out_d_scp changed (wakeup interrupt from deepsleep)
 * Check the INTR13_STATUS.CSA_SCP_STATUS value
 */
#define PDSS_INTR13_CSA_SCP_CHANGED                         (1UL << 5) /* <5:5> RW1S:RW1C:0:CSA_SCP_EN */


/*
 * INTR13 Interrupt Set
 */
#define PDSS_INTR13_SET_ADDRESS                             (0x400a04e4UL)
#define PDSS_INTR13_SET                                     (*(volatile uint32_t *)(0x400a04e4UL))
#define PDSS_INTR13_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_CSA_OCP_CHANGED                     (1UL << 4) /* <4:4> A:RW1S:0:CSA_SCP_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_CSA_SCP_CHANGED                     (1UL << 5) /* <5:5> A:RW1S:0:CSA_SCP_EN */


/*
 * INTR13 interrupt Mask
 */
#define PDSS_INTR13_MASK_ADDRESS                            (0x400a04e8UL)
#define PDSS_INTR13_MASK                                    (*(volatile uint32_t *)(0x400a04e8UL))
#define PDSS_INTR13_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_CSA_OCP_CHANGED_MASK               (1UL << 4) /* <4:4> R:RW:0:CSA_SCP_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_CSA_SCP_CHANGED_MASK               (1UL << 5) /* <5:5> R:RW:0:CSA_SCP_EN */


/*
 * INTR13 interrupt Masked
 */
#define PDSS_INTR13_MASKED_ADDRESS                          (0x400a04ecUL)
#define PDSS_INTR13_MASKED                                  (*(volatile uint32_t *)(0x400a04ecUL))
#define PDSS_INTR13_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_CSA_OCP_CHANGED_MASKED           (1UL << 4) /* <4:4> RW:R:0:CSA_SCP_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_CSA_SCP_CHANGED_MASKED           (1UL << 5) /* <5:5> RW:R:0:CSA_SCP_EN */


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
#define PDSS_INTR0_SAR_DONE_MASK                            (0x18000000UL) /* <27:28> RW1S:RW1C:0:ADC_NUM */
#define PDSS_INTR0_SAR_DONE_POS                             (27UL)


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
#define PDSS_INTR0_SET_SAR_DONE_MASK                        (0x18000000UL) /* <27:28> A:RW1S:0:ADC_NUM */
#define PDSS_INTR0_SET_SAR_DONE_POS                         (27UL)


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
#define PDSS_INTR0_MASK_SAR_DONE_MASK_MASK                  (0x18000000UL) /* <27:28> R:RW:0:ADC_NUM */
#define PDSS_INTR0_MASK_SAR_DONE_MASK_POS                   (27UL)


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
#define PDSS_INTR0_MASKED_SAR_DONE_MASKED_MASK              (0x18000000UL) /* <27:28> RW:R:0:ADC_NUM */
#define PDSS_INTR0_MASKED_SAR_DONE_MASKED_POS               (27UL)


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
 * The interrupt is raised when HPD detects IRQ signaling on HPD line
 */
#define PDSS_INTR2_HPD_IRQ                                  (1UL << 1) /* <1:1> RW1S:RW1C:0:HPD_EN */


/*
 * The interrupt is raised when HPD detects pluged condition
 */
#define PDSS_INTR2_HPD_PLUGED                               (1UL << 2) /* <2:2> RW1S:RW1C:0:HPD_EN */


/*
 * The interrupt is raised when HPD detects unpluged condition
 */
#define PDSS_INTR2_HPD_UNPLUGED                             (1UL << 3) /* <3:3> RW1S:RW1C:0:HPD_EN */


/*
 * The interrupt is raised when HPD detects undefined activity
 */
#define PDSS_INTR2_HPD_UNSTABLE                             (1UL << 4) /* <4:4> RW1S:RW1C:0:HPD_EN */


/*
 * The interrupt is raised when an entry to HPD queue is made.
 */
#define PDSS_INTR2_HPD_QUEUE                                (1UL << 5) /* <5:5> RW1S:RW1C:0:HPD_EN */


/*
 * The interrupt is raised when HPDT completes the command
 */
#define PDSS_INTR2_HPDT_COMMAND_DONE                        (1UL << 6) /* <6:6> RW1S:RW1C:0:HPD_EN */


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
#define PDSS_INTR2_SET_HPD_IRQ                              (1UL << 1) /* <1:1> A:RW1S:0:HPD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_HPD_PLUGED                           (1UL << 2) /* <2:2> A:RW1S:0:HPD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_HPD_UNPLUGED                         (1UL << 3) /* <3:3> A:RW1S:0:HPD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_HPD_UNSTABLE                         (1UL << 4) /* <4:4> A:RW1S:0:HPD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_HPD_QUEUE                            (1UL << 5) /* <5:5> A:RW1S:0:HPD_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_HPDT_COMMAND_DONE                    (1UL << 6) /* <6:6> A:RW1S:0:HPD_EN */


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
#define PDSS_INTR2_MASK_HPD_IRQ_MASK                        (1UL << 1) /* <1:1> R:RW:0:HPD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_HPD_PLUGED_MASK                     (1UL << 2) /* <2:2> R:RW:0:HPD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_HPD_UNPLUGED_MASK                   (1UL << 3) /* <3:3> R:RW:0:HPD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_HPD_UNSTABLE_MASK                   (1UL << 4) /* <4:4> R:RW:0:HPD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_HPD_QUEUE_MASK                      (1UL << 5) /* <5:5> R:RW:0:HPD_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_HPDT_COMMAND_DONE_MASK              (1UL << 6) /* <6:6> R:RW:0:HPD_EN */


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
#define PDSS_INTR2_MASKED_HPD_IRQ_MASKED                    (1UL << 1) /* <1:1> RW:R:0:HPD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_HPD_PLUGED_MASKED                 (1UL << 2) /* <2:2> RW:R:0:HPD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_HPD_UNPLUGED_MASKED               (1UL << 3) /* <3:3> RW:R:0:HPD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_HPD_UNSTABLE_MASKED               (1UL << 4) /* <4:4> RW:R:0:HPD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_HPD_QUEUE_MASKED                  (1UL << 5) /* <5:5> RW:R:0:HPD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_HPDT_COMMAND_DONE_MASKED          (1UL << 6) /* <6:6> RW:R:0:HPD_EN */


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
 * 47 1'b0//intr_swap_queue_set
 * 46 1'b0//intr_swap_unstable_set
 * 45 intr_swap_disconnect_set
 * 44 intr_swap_rcvd_set
 * 43 intr_swap_pulse_set
 * 42 intr_swapt_command_done_set
 * 41 intr_ddft1
 * 40 intr_ddft0
 * 39 ncell_ddft1
 * 38 ncell_ddft0
 * 37 bbctrl_ddft1 // CCG7D
 * 36 bbctrl_ddft0 // CCG7D
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
 * 47 1'b0//intr_swap_queue_set
 * 46 1'b0//intr_swap_unstable_set
 * 45 intr_swap_disconnect_set
 * 44 intr_swap_rcvd_set
 * 43 intr_swap_pulse_set
 * 42 intr_swapt_command_done_set
 * 41 intr_ddft1
 * 40 intr_ddft0
 * 39 ncell_ddft1
 * 38 ncell_ddft0
 * 37 bbctrl_ddft1 // CCG7D
 * 36 bbctrl_ddft0 // CCG7D
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
 * 250 CCG7D_INTR_DDFT1 // specific source selectable using CCG7D_INTR_DDFT_MUX
 * register
 * 249 CCG7D_INTR_DDFT0 // specific source selectable using CCG7D_INTR_DDFT_MUX
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
 * 250 CCG7D_INTR_DDFT1 // specific source selectable using CCG7D_INTR_DDFT_MUX
 * register
 * 249 CCG7D_INTR_DDFT0 // specific source selectable using CCG7D_INTR_DDFT_MUX
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
 * 230: PMG1S3_NCELL_DDFT1 // specific source selectable using PMG1S3_NCELL_DDFT_MUX
 * register
 * 229: PMG1S3_NCELL_DDFT0 // specific source selectable using PMG1S3_NCELL_DDFT_MUX
 * register
 * 228 CCG7D_NCELL_DDFT1  // specific source selectable using CCG7D_NCELL_DDFT_MUX
 * register
 * 227 CCG7D_NCELL_DDFT0  // specific source selectable using CCG7D_NCELL_DDFT_MUX
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
 * 230: PMG1S3_NCELL_DDFT1 // specific source selectable using PMG1S3_NCELL_DDFT_MUX
 * register
 * 229: PMG1S3_NCELL_DDFT0 // specific source selectable using PMG1S3_NCELL_DDFT_MUX
 * register
 * 228 CCG7D_NCELL_DDFT1  // specific source selectable using CCG7D_NCELL_DDFT_MUX
 * register
 * 227 CCG7D_NCELL_DDFT0  // specific source selectable using CCG7D_NCELL_DDFT_MUX
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
 * 120 CCG7D_GPIO_DDFT1  // specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 119 CCG7D_GPIO_DDFT0  // specific source selectable using CCG7D_GPIO_DDFT_MUX
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
 * 120 CCG7D_GPIO_DDFT1  // specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 119 CCG7D_GPIO_DDFT0  // specific source selectable using CCG7D_GPIO_DDFT_MUX
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
 * 250 CCG7D_GPIO_INTR_DDFT1 // specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 249 CCG7D_GPIO_INTR_DDFT0 // specific source selectable using CCG7D_GPIO_DDFT_MUX
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
 * 250 CCG7D_GPIO_INTR_DDFT1 // specific source selectable using CCG7D_GPIO_DDFT_MUX
 * register
 * 249 CCG7D_GPIO_INTR_DDFT0 // specific source selectable using CCG7D_GPIO_DDFT_MUX
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
 * mask bit for FAULT_GPIO_0[15], FAULT_GPIO_1[15]
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_MASK_EXTR_15        (1UL << 27) /* <27:27> R:RW:0:CCG7D_CCG7S_EN */


/*
 * Additional MSB (bit <4>) for FAULT_GPIO_EXTR_0_SEL
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_0_SEL_4    (1UL << 30) /* <30:30> R:RW:0:CCG7D_CCG7S_EN */


/*
 * Additional MSB (bit <4>) for FAULT_GPIO_EXTR_1_SEL
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_1_SEL_4    (1UL << 31) /* <31:31> R:RW:0:CCG7D_CCG7S_EN */


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
#define PDSS_AMUX_CTRL_SEL_MASK                             (0x0003ffffUL) /* <0:17> R:RW:0:USB_AMUX_NUM */
#define PDSS_AMUX_CTRL_SEL_POS                              (0UL)


/*
 * USBPD Hard IP AMUX_DENFET #1-32 Register
 * Function                            SWITCH#          SEL[0]    SEL[1]
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 * ACG1F:
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *           VBUS_MON                          #0                  100% 
 *     10%
 */
#define PDSS_AMUX_DENFET_CTRL_ADDRESS                       (0x400a0630UL)
#define PDSS_AMUX_DENFET_CTRL                               (*(volatile uint32_t *)(0x400a0630UL))
#define PDSS_AMUX_DENFET_CTRL_DEFAULT                       (0x00000000UL)

/*
 * AMUX select control
 */
#define PDSS_AMUX_DENFET_CTRL_SEL                           (1UL << 0) /* <0:0> R:RW:0:USB_AMUX_DENFET_NUM */


/*
 * USBPD Hard IP DAC #1-4 Register
 */
#define PDSS_ADC_CTRL_ADDRESS(n)                            (0x400a0680UL + ((n) * (0x0004UL)))
#define PDSS_ADC_CTRL(n)                                    (*(volatile uint32_t *)(0x400a0680UL + ((n) * 0x0004UL)))
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
 * CCG7D:
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
 * Not Used in ACG1F.
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
#define PDSS_BCH_DET_1_CTRL_APPLE_TERM_MASK                 (0x3c000000UL) /* <26:29> R:RW:0:PASC_CCG7D_EN */
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
 */
#define PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK                 (0x0000007cUL) /* <2:6> R:RW:0: */
#define PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS                  (2UL)


/*
 * USBPD Hard IP Comparators #1-24 Register
 * CCG3PA:
 *       Function                            Comparator#       CLK_FILTER#
 *       CLK_LF#    FILTER21  FILTER22
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *           UV                                        #0               
 *              #0                                   #0            #0
 *           OV                                        #1               
 *              #1                                   #1            #1
 *           VBUS_MON                          #2                       
 *     N/A                 #0              #2            #2
 *           VSYS_DET                           #3                      
 *       N/A                #1               #3           #3
 * CCG5-Port1:
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *           UV                                        #0               
 *              #0                                   #0            #0
 *           OV                                        #1               
 *              #1                                   #1            #1
 *           VBUS_MON                          #2                       
 *     N/A                 #0              #2            #2
 * CCG6:
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *           UV                                        #0               
 *              #0                                   #0            #0
 *           OV                                        #1               
 *              #1                                   #1            #1
 *           VSYS_DET                           #2                      
 *       N/A                #1             #3           #3
 * CCG6DF-Port1:
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *           UV                                        #0               
 *              #0                                   #0            #0
 *           OV                                        #1               
 *              #1                                   #1            #1
 * CCG7D:
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
 * ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *  Function                            Comparator#       CLK_FILTER#   
 *    CLK_LF#    FILTER21  FILTER22
 * ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
 * ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 * PMG1S3-Port1:
 *           UV                                    #0                   
 *             #0                   NA           #0          #0
 *           OV                                    #1                   
 *             #1                   NA           #1          #1
 *           SBU1                                #2                     
 *           NA                  #0            NA          NA
 *           SBU2                                #3                     
 *           NA                  #1            NA          NA
 * ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
 * USBPD Hard IP VCONN20 V5V Power FET Register
 */
#define PDSS_VCONN20_CTRL_ADDRESS                           (0x400a0868UL)
#define PDSS_VCONN20_CTRL                                   (*(volatile uint32_t *)(0x400a0868UL))
#define PDSS_VCONN20_CTRL_DEFAULT                           (0x02000000UL)

/*
 * Detects if V5V supply is present.
 * 0-disbale
 * 1-enable
 */
#define PDSS_VCONN20_CTRL_EN_COMP                           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Over-current detection enable when cc1 switch is enabled.
 * 0-disable
 * 1-enable
 */
#define PDSS_VCONN20_CTRL_EN_OCP_CC1                        (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Over-current detection enable when cc2 swithc is enabled.
 * 0-disable
 * 1-enable
 */
#define PDSS_VCONN20_CTRL_EN_OCP_CC2                        (1UL << 2) /* <2:2> R:RW:0: */


/*
 * The engineering option to alternate analog circuit configuration
 * t_vconn[0]=1 Disable the 6V detect comparator on v5v (for the case where
 * OVP through slow ramp and vconn switch on)
 * t_vconn[1]=1 Enable trim controlled ovp detection circuit
 * t_vconn[2]=1 Enable crude ovp detection(supply+vtp) circuit
 * t_vconn[3]=1 Increase self bias geneation stack current
 * t_vconn[4]=1 Decrease self bias geneation stack current
 *                       ACG1F, CCG7D - Enable the 5K Rd termination on CC1
 * t_vconn[5]=1 Disable the reverse current protection comparator for Vconn
 * switch on
 * t_vconn[6]=1 Increase the 6V detect compartor on v5v threshold to 6.4V
 * from 6V
 *                       ACG1F - Enable the 5K Rd termination on CC2
 * t_vconn[7]=1 Disable the pulse scheme used for VDB SOA protection of first
 * transistor of switch in 24V fault case
 *                       ACG1F: t_vconn[7]=1 Change the OCP gain to 4. Default
 * is gain =2.
 *                       CCG7D : gate the scp signal from turning on vconn
 * switches
 * t_vconn[8]=1 Short V5V to VDDD through NMOS (to be used in case v5v is
 * floating at system level)
 * t_vconn[9]=1 Enable external clock to use forthe charge pump
 *                       CCG7D : Disable the OVP irefgen
 * t_vconn[10]=1 Disable internal reference of ocp detects threshold and
 * force externally it through adft
 *                       CCG7D : Unused
 * t_vconn[11]=1 Reduce the reverse current protection comparator differential
 * sensing threshold by 150mV (between CC and v5v)
 * t_vconn[12]=1 Disable crude ocp detection circuit
 *                       CCG7D : to turn ON & enable the slow charging of
 * 20vswitch for inrush current control
 * t_vconn[13]=1 Disable auto shut down of vconn when ovp is detected
 * t_vconn[14]=1 set OCP trip point @100mA for SORT testing
 *                       CCG7D: t_vconn[14]=1 inrush control based on scp
 * comparator or default current stack
 * t_vconn[15]=1 Disable the OVP sensing PMOS gate from VDDD to vgnd in vconn
 * switch on case
 *
 * For PMG1S3:
 * t_vconn[0] Not Used-
 * t_vconn[1] Enable higher OVP trip
 *                   0 = OVP Trips at 334mV
 *                   1 = OVP Trips at 780mV
 * t_vconn[2] Enable crude ovp detection(supply+vtp) circuit & disable OVP
 * during Zopen
 *                   0 = OVP Trip Final Comparator Stage gating Disabled
 *                   1 = OVP Trip Final Comparator Stage gating Enabled
 * t_vconn[3] Enable trim Current
 *                   0 = OCP Trim Current gating Disabled
 *                   1 = OCP Trim Current gating Enabled
 * t_vconn[4] Disable auto shut down of vconn when ovp is detected
 *                   0 = OVP Trip (VDDD output) Enabled
 *                   1 = OVP Trip (VDDD output) Disabled
 * t_vconn[5] Enable Gate Pull Up
 *                   0 = Vgate is pulled up with trim_ocp<7:4>=Inrush trim
 * bits
 *                   1 = Vgate is pulled up with trim_ocp<7:4>=Inrush trim
 * bits
 *                   + 1p2uA, need to enabled after 500us of vconn switch
 * enable i.e. write this bit to 1.
 * t_vconn[6] SET OCP trip @100mA for testing at short
 *                   0 = OCP Trips at ~600mA
 *                   1 = OCP Trips at ~80mA
 * t_vconn[7] OCP tap enable
 *                   0 = OCP Comparator Input Gating Disabled
 *                   1 = OCP Comparator Input Gating Enabled
 * t_vconn[8] Disable 6v ovp comp
 *                   0 = Disable 6V comparator to take care of OVP
 *                   1 = Enable 6V comparator to take care of OVP
 * t_vconn[9] Enable external clock to use for the charge pump
 *                   0 = Disable external clock to use for the charge pump
 *                   1 = Enable external clock to use for the charge pump
 */
#define PDSS_VCONN20_CTRL_T_VCONN_MASK                      (0x0007fff8UL) /* <3:18> R:RW:0: */
#define PDSS_VCONN20_CTRL_T_VCONN_POS                       (3UL)


/*
 * The master enbale of adft
 * 0-disable adft
 * 1-enable adft configuration
 */
#define PDSS_VCONN20_CTRL_VCONN20_ADFT_EN                   (1UL << 19) /* <19:19> R:RW:0: */


/*
 * The adft configuration control lines
 * 00000: adft[1]=hiZ , adft[0]=hiZ
 * 00001: adft[1]=10v vpump output , adft[0]=pump clock
 * 00010: adft[1]=1st stage pump output , adft[0]=pump regulator output
 * 00011: adft[1]=pump reference voltage , adft[0]=pump feedback node
 * 00100: adft[1]=hiZ , adft[0]=pump current reference
 * 00101: adft[1]=hiZ , adft[0]=hiZ
 * 00110: adft[1]=gate voltage of CC1 nmos switch  , adft[0]=CC1 OVP detects
 * out
 * 00111: adft[1]=gate voltage of CC2 nmos switch  , adft[0]=CC2 OVP detects
 * out
 * 01000: adft[1]=ovp isink1 cc1, adft[0]=ovp isink0 cc1
 * 01001: adft[1]=ovp isink0 cc2, adft[0]=ovp isink2 cc1
 * 01010: adft[1]=ovp isink2 cc2, adft[0]=ovp isink1 cc2
 * 01011: adft[1]=hiZ , adft[0]=hiZ
 * 01100: adft[1]=ocp vtrip reference , adft[0]=OCP detects out
 * 01101: adft[1]=ocp cc opamp out , adft[0]=ocp vtrip opamp out
 * 01110: adft[1]=crude ocp detects out , adft[0]=ocp isink
 * 01111: adft[1]=hiZ , adft[0]=hiZ
 * The other configurations are reserved. adft[1]=hiZ , adft[0]=hiZ
 * ACG1F, CCG7D:
 * 00000: adft[1]=hiZ , adft[0]=hiZ
 * 00001: adft[1]=10v vpump output , adft[0]=pump clock
 * 00010: adft[1]=1st stage pump output , adft[0]=pump regulator output
 * 00011: adft[1]=pump reference voltage , adft[0]=pump feedback node
 * 00100: adft[1]=CC1 , adft[0]=V5V
 * 00101: adft[1]=CC2 , adft[0]=V5V
 * 00110: adft[1]=gate voltage of CC1 nmos switch , adft[0]=CC1 OVP detects
 * out
 * 00111: adft[1]=gate voltage of CC2 nmos switch , adft[0]=CC2 OVP detects
 * out
 * 01000: adft[1]=ovp isink1 cc1, adft[0]=ovp isink0 cc1
 * 01001: adft[1]=ovp isink0 cc2, adft[0]=ovp isink2 cc1
 * 01010: adft[1]=ovp isink2 cc2, adft[0]=ovp isink1 cc2
 * 01011: adft[1]=iref_ocp , adft[0]=isink_pump
 * 01100: adft[1]=ocp vtrip reference , adft[0]=OCP detects out
 * 01101: adft[1]=ocp cc opamp out , adft[0]=ocp vtrip opamp out
 * 01110: adft[1]=crude ocp detects out , adft[0]=ocp isink
 * 01111: adft[1]=ocp cc opamp in , adft[0]=ocp vtrip reference
 * The other configurations are reserved. adft[1]=hiZ , adft[0]=hiZ
 *
 * For PMG1S3:
 * Refer s8usbpdv2 BROS - s8usbpdv2_pmg1s3_vconn_sw_top ADFT Truth Table
 */
#define PDSS_VCONN20_CTRL_VCONN20_ADFT_CTRL_MASK            (0x01f00000UL) /* <20:24> R:RW:0: */
#define PDSS_VCONN20_CTRL_VCONN20_ADFT_CTRL_POS             (20UL)


/*
 * enables the deep sleep current copies to be generated for other blocks
 */
#define PDSS_VCONN20_CTRL_VCONN20_EN_IBIAS                  (1UL << 25) /* <25:25> R:RW:1:CCG7D_CCG7S_EN */


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
 * USBPD Hard IP VBUS Discharge SHV #1-8 Register1 (NA in PMG1S3)
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
 * USBPD Hard IP CSA SCP Register0
 */
#define PDSS_CSA_SCP_0_CTRL_ADDRESS                         (0x400a08bcUL)
#define PDSS_CSA_SCP_0_CTRL                                 (*(volatile uint32_t *)(0x400a08bcUL))
#define PDSS_CSA_SCP_0_CTRL_DEFAULT                         (0xc03f007dUL)

/*
 * Selects the nominal voltage gain.
 * For R_sense of 5mohm, default value of Av1=5.
 * For R_sense of 10mohm default value of Av1=2.
 * CCG7D:
 * Selects the voltage gain for vout_cc output.
 * 0 - Av_cc=40
 * 1 - Av_cc=50
 * 2 - Av_cc=60
 * 3 - Av_cc=70
 * 4 - Av_cc=80
 * 5 - Av_cc=90
 * 6 - Av_cc=100
 * 7 - Av_cc=110
 * The Default functional value for CCG7D is 3. FW has to set this filed
 * value to 3 before enabling Buck Boost operation.
 */
#define PDSS_CSA_SCP_0_CTRL_AV1_MASK                        (0x00000007UL) /* <0:2> R:RW:5: */
#define PDSS_CSA_SCP_0_CTRL_AV1_POS                         (0UL)


/*
 * Enable signal for Load transient detection block
 */
#define PDSS_CSA_SCP_0_CTRL_EN_ITRAN_DET                    (1UL << 3) /* <3:3> R:RW:1:CCG7D_CCG7S_EN */


/*
 * Enable signal for Load transient detection Low-to-high comparator block
 */
#define PDSS_CSA_SCP_0_CTRL_EN_ITRANCOMP_L2H                (1UL << 4) /* <4:4> R:RW:1:CCG7D_CCG7S_EN */


/*
 * Enable signal for Load transient detection high-to-Low comparator block
 */
#define PDSS_CSA_SCP_0_CTRL_EN_ITRANCOMP_H2L                (1UL << 5) /* <5:5> R:RW:1:CCG7D_CCG7S_EN */


/*
 * Configuration: 1 - Out_d_ocp and out_d_scp used,
 *                            0 - Out_d_ocp=LOW and out_d_scp=LOW
 */
#define PDSS_CSA_SCP_0_CTRL_SEL_OUT_D                       (1UL << 6) /* <6:6> R:RW:1: */


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_CSA_SCP_0_CTRL_CSA_ISO_N                       (1UL << 7) /* <7:7> R:RW:0: */


/*
 * adft control inputs used to connect various analog internal signals to
 * atstio.
 * See BROS doc for more info.
 * CCG7D :
 * adft control inputs used to connect various analog internal signals to
 * atstio.
 * See BROS doc for more info
 *        adft<1>                                     adft<0>
 * adft=0  hiZ                                             hiZ
 * adft=1  observe stg2_in_ocp                 observe vout_cbl from livemon
 * UGB
 * adft=2   force adft<1> stg2_in_ocp         observe afdt<0> comp_out_ocp
 * adft=3  force stg2_in_ocp                     observe out2_ocp_hv
 * adft=4  observe vref_scp                      observe vref_ocp
 * adft=5  force vref_ocp                           force stg2_in_ocp
 * adft=6   force Livemon UGB INP             observe Livemon UGB INN from
 * adft<0>
 * adft=7  observe stg2_in_scp                 observe vout_mon from livemon
 * UGB
 * adft=8   force adft<1> stg2_in_scp         observe afdt<0> comp_out_scp
 * adft=9  force stg2_in_scp                      observe out2_scp_hv
 * adft=10 observe inp_div_10                   observe  stg2_in_scp from
 * livemon UGB
 * adft=11 force vref_scp                            force  stg2_in_scp
 * adft=12 hiZ                                             observe inp_div_10
 * adft=13 hiZ                                             observe vout_cc
 * from livemon UGB
 * adft=14 hiZ                                             observe stg2_in_ocp
 * from livemon UGB
 * adft=15 observe(sh_itrandet=1)/              observe stg2_in_ocp from
 * ocp comp UGB
 *                   force(sh_itrandet=0) itrandet_UGB output
 */
#define PDSS_CSA_SCP_0_CTRL_CSA_ADFT_CTRL_MASK              (0x00000f00UL) /* <8:11> R:RW:0: */
#define PDSS_CSA_SCP_0_CTRL_CSA_ADFT_CTRL_POS               (8UL)


/*
 *  Dummy bits - not used inside schematic.
 */
#define PDSS_CSA_SCP_0_CTRL_AV1_TR_MASK                     (0x0000f000UL) /* <12:15> R:RW:0:CCG7D_CCG7S_EN */
#define PDSS_CSA_SCP_0_CTRL_AV1_TR_POS                      (12UL)


/*
 * Control bits to alter stage-1 vout_cc Bandwidth
 * Vout_cc 3dB BW:
 *
 * bw_cc<3:0>      BW(KHz)        comment
 * 0                          18                7Rx3C
 * 1                          25                7Rx2C
 * 2                          39                7Rx1C
 * 3                          93                7Rx0C
 * 4                          21                6Rx3C
 * 5                          29                6Rx2C
 * 6                          45                6Rx1C
 * 7                          110              6Rx0C
 * 8                          98                1Rx3C
 * 9                          133              1Rx2C
 * 10                         210              1Rx1C
 * 11                         419              1Rx0C
 * 12                         443               (R/6)x3C
 * 13                         602               (R/6)x2C
 * 14                         930               (R/6)x1C
 * 15                         2044               (R/6)x0C
 * R=300kohm, C=1pF.
 */
#define PDSS_CSA_SCP_0_CTRL_BW_CC_MASK                      (0x000f0000UL) /* <16:19> R:RW:15:CCG7D_CCG7S_EN */
#define PDSS_CSA_SCP_0_CTRL_BW_CC_POS                       (16UL)


/*
 * Control bits to alter Sample and Hold comparison voltage.
 * To detect load transient of 1A/10us, then use tr_itranugb_ifb=1 for av1=1,
 * use tr_itranugb_ifb=2 for av1=2, use tr_itranugb_ifb=3 for av1=3 and so
 * on.
 * 1-dV=75mV, 2-dV=90mV, 3-dV=105mV,
 * 4-dV=120mV, 5-dV=135mV, 6-dV=150mV, 7-dV=175mV
 */
#define PDSS_CSA_SCP_0_CTRL_TR_ITRANUGB_IFB_MASK            (0x00700000UL) /* <20:22> R:RW:3:CCG7D_CCG7S_EN */
#define PDSS_CSA_SCP_0_CTRL_TR_ITRANUGB_IFB_POS             (20UL)


/*
 * Control bits to alter hysteresis of itrandet_l2h comparator
 * 2'b00 = 0mV
 * 2'b01 = 15mV
 * 2'b10 = 30mV
 * 2'b11 = 45mV
 */
#define PDSS_CSA_SCP_0_CTRL_TR_ITRANCOMP_L2H_HYS_MASK       (0x01800000UL) /* <23:24> R:RW:0:CCG7D_CCG7S_EN */
#define PDSS_CSA_SCP_0_CTRL_TR_ITRANCOMP_L2H_HYS_POS        (23UL)


/*
 * Control bits to alter hysteresis of itrandet_h2l comparator
 * 2'b00 = 0mV
 * 2'b01 = 15mV
 * 2'b10 = 30mV
 * 2'b11 = 45mV
 */
#define PDSS_CSA_SCP_0_CTRL_TR_ITRANCOMP_H2L_HYS_MASK       (0x06000000UL) /* <25:26> R:RW:0:CCG7D_CCG7S_EN */
#define PDSS_CSA_SCP_0_CTRL_TR_ITRANCOMP_H2L_HYS_POS        (25UL)


/*
 * Hysteresis enable for Stage 2
 * CCG7D:  Hysteresis enable signal for stage-2 OCP and SCP comparators
 */
#define PDSS_CSA_SCP_0_CTRL_HYST_EN                         (1UL << 28) /* <28:28> R:RW:0: */


/*
 * Trim control for analog bandwidth.
 * If Av1=5, then bw=2
 * if Av1=2, then bw=1
 * For ACG1F , recommended setting BW= 3 for fastest SCP response
 * CCG7D:
 * Control bits to alter stage-1 vout_ocp bandwidth
 * Vout_ocp 3dB BW:
 * 2'b00 = 100KHz
 * 2'b01 = 150KHz
 * 2'b10 = 270KHz
 * 2'b11 = 1600KHz
 */
#define PDSS_CSA_SCP_0_CTRL_BW_MASK                         (0x60000000UL) /* <29:30> R:RW:2: */
#define PDSS_CSA_SCP_0_CTRL_BW_POS                          (29UL)


/*
 * Block power down input
 * 1 - All analog and DC paths cut off, outputs forced to known value
 * 0 - Normal functionality
 */
#define PDSS_CSA_SCP_0_CTRL_PD_CSA                          (1UL << 31) /* <31:31> R:RW:1: */


/*
 * USBPD Hard IP CSA SCP Register1
 */
#define PDSS_CSA_SCP_1_CTRL_ADDRESS                         (0x400a08c0UL)
#define PDSS_CSA_SCP_1_CTRL                                 (*(volatile uint32_t *)(0x400a08c0UL))
#define PDSS_CSA_SCP_1_CTRL_DEFAULT                         (0x00000000UL)

/*
 * t_csa_scp<1:0>=0 --> Gain of OCP will be same as in ver2 CSA,
 *                                      Gain of SCP will be clamped to 15
 * irrespective of OCP gain setting except for OCP AV1 = 0
 * t_csa_scp<0>=1   --> Gain of OCP and SCP will be same determinted by AV1.
 * t_csa_scp<1>=1   --> Gain of OCP=60 and SCP=15
 * t_csa_scp<2>        --> reset for the SCP output latch
 * 0   -->  SCP output latch in reset mode and SCP output of the block is
 * set to 0.
 * 1   --> SCP output latch in sample mode. Once set, the latch output (i.e
 * SCP output) can only be cleared by making this bit 0.
 * t_csa_scp<5:3> --> SCP output glitch filter delay settings
 * 000 - bypass the glitch filter
 * 001 - 6uS glitch filter
 * 010 - 10 uS glitch filter
 * 011 - 13uS glitch filter
 * 100 - 17uS glitch filter
 * 101 - 20uS glitch filter
 * 110 - 24uS glitch filter
 * 111 - 27uS glitch filter
 *
 * t_csa_scp<6> -  0 , output latch on scp hv/lv outputs
 *                          1,  output latch on scp hv/lv output in bypass
 * mode (i.e. no latch funciton on SCP output)
 * CCG7D:  Lower 8 bits of T_CSA_SCP[15:0] Test-Mode bits to modify circuit
 * functionality in future. See BROS doc for description
 * t_csa_scp<0>   0: cbl/mon low gain stack Av=70
 * 1: cbl/mon low gain stack Av=40
 * t_csa_scp<1>   0: cbl/mon high gain stack Av=150
 * 1: cbl/mon high gain stack Av=200
 * t_csa_scp<2>   0: SCP output latch will be reseted to zero.
 * 0->1: to sample SCP output this bit has to be toggled from 0 to 1
 * t_csa_scp<5:3> SCP output delay trims for masking faulty events
 * t_csa_scp<6>   0: SCP output will come through latch
 * 1: SCP output will bypass latch. [FW]: This bit must be set to 1 during
 * initialization to bypass the latch
 * t_csa_scp<7>   0: stage-1 offset trim step = 0.32
 * 1: stage-1 offset trim step = 2*0.32
 * t_csa_scp<8>   0: optioned-out cap on OCP path
 * 1: optioned-in cap on OCP path
 */
#define PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_MASK                  (0x000000ffUL) /* <0:7> R:RW:0:CCG6_CCG7D_EN */
#define PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_POS                   (0UL)


/*
 * CCG7D:  Upper 8 bits of
 * t_csa_scp<8>   0: optioned-out cap on OCP path
 * 1: optioned-in cap on OCP path
 * t_csa_scp<9>   0: optioned-out cap on SCP path
 * 1: optioned-in cap on SCP path
 * t_csa_scp<10> 0: 200kohm resistor included in OCP path
 * 1: 200kohm resistor shorted in OCP path
 * t_csa_scp<11> 0: itrandet_l2h/h2l comparator bias current = x
 * 1: itrandet_l2h/h2l comparator bias current = 0.5x
 * t_csa_scp<12> 0: itrandet comparators used for itrandet function
 * 1: itrandet comparators used for ADFT access
 * t_csa_scp<13> 0: Av_ocp=40, Av_scp=20
 * 1: Av_ocp=60, Av_scp=30
 * t_csa_scp<14> 0: vout_cbl gain mux slects low gain stack(70/40)
 * 1: vout_cbl gain mux slects high gain stack(150/200)
 * t_csa_scp<15> 0: vout_mon gain mux slects low gain stack(70/40)
 * 1: vout_mon gain mux slects high gain stack(150/200) T_CSA_SCP[15:0] Test-Mode
 * bits to modify circuit functionality in future. See BROS doc for description
 */
#define PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_EXT_MASK              (0x0ff00000UL) /* <20:27> R:RW:0:CCG7D_CCG7S_EN */
#define PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_EXT_POS               (20UL)


/*
 *  Enable signal for biasgen block and isrc_2p4u<7:0>/isnk_2p4u<3:0> outputs
 */
#define PDSS_CSA_SCP_1_CTRL_CSA_EN_IBIAS                    (1UL << 28) /* <28:28> R:RW:0:CCG7D_CCG7S_EN */


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
 * S8PDS Hard IP SCP Register (NA in PMG1S3)
 */
#define PDSS_PDS_SCP_CTRL_ADDRESS                           (0x400a08d0UL)
#define PDSS_PDS_SCP_CTRL                                   (*(volatile uint32_t *)(0x400a08d0UL))
#define PDSS_PDS_SCP_CTRL_DEFAULT                           (0x20000000UL)

/*
 * SCP enable signal
 */
#define PDSS_PDS_SCP_CTRL_SCP_EN                            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_PDS_SCP_CTRL_SCP_ISO_N                         (1UL << 7) /* <7:7> R:RW:0: */


/*
 * adft control inputs used to connect various analog internal signals to
 * atstio.
 * See BROS doc for more info.
 */
#define PDSS_PDS_SCP_CTRL_SCP_ADFT_EN                       (1UL << 8) /* <8:8> R:RW:0: */


/*
 * adft control inputs used to connect various analog internal signals to
 * atstio.
 * See BROS doc for more info.
 */
#define PDSS_PDS_SCP_CTRL_SCP_ADFT_CTRL_MASK                (0x00000e00UL) /* <9:11> R:RW:0: */
#define PDSS_PDS_SCP_CTRL_SCP_ADFT_CTRL_POS                 (9UL)


/*
 * testmode for SCP block:
 * <6>    : Hysteresis Increase Option
 * <5>    : Slow mode, block current reduced by half (default 0:  1x current)
 * <4:3> : Mode control (6A, 10A)
 *             00 : 0A SCP - works as ideal comparator : Should not be used
 *             01 : 8A SCP (40mV with 5mOhm Rsense)
 *             10 : 6A SCP (30mV with 5mOhm Rsense)
 *             11 : 10A SCP (50mV with 5mOhm Rsense)
 * <2>    : Hysteresis disable (0 : Enable, 1 : disable)
 * <1>    : Fast mode, double the block current; Also used for 10mOhm Rsense
 * <0>    : Vddd_crude bypass
 */
#define PDSS_PDS_SCP_CTRL_SCP_TESTMODE_MASK                 (0xfe000000UL) /* <25:31> R:RW:16: */
#define PDSS_PDS_SCP_CTRL_SCP_TESTMODE_POS                  (25UL)


/*
 * S8PDS Hard IP NGDO Register (Only for PAG1S and CCG6DF and CCG7D) (NA
 * in PMG1S3)
 */
#define PDSS_NGDO_CTRL_ADDRESS                              (0x400a0900UL)
#define PDSS_NGDO_CTRL                                      (*(volatile uint32_t *)(0x400a0900UL))
#define PDSS_NGDO_CTRL_DEFAULT                              (0x00010300UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_NGDO_CTRL_NGDO_ISO_N                           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Enable signal for the bias circuitry, comparator and slew rate block
 * ngdo_en = 0 ; disabled
 * ngdo_en = 1 ; enabled
 */
#define PDSS_NGDO_CTRL_NGDO_EN_LV                           (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Optioned out bit in case required in future for clamp disable (not used
 * internally)
 */
#define PDSS_NGDO_CTRL_NGDO_CLAMP_EN                        (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Charge-pump ouptut control;
 * cp_en = 0 ; cp output = vbus
 * cp_en = 1 ; cp output = driven by cp action
 */
#define PDSS_NGDO_CTRL_NGDO_CP_EN                           (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Enable signal for adft.
 * adft_en = 0 ; ADFT disabled, normal functionality
 * adft_en = 1 ; ADFT network enabled
 */
#define PDSS_NGDO_CTRL_NGDO_ADFT_EN                         (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Current programmibility for shv vclamp voltage (default 00 = 9V)
 */
#define PDSS_NGDO_CTRL_NGDO_CLAMP_CTRL_MASK                 (0x00000060UL) /* <5:6> R:RW:0: */
#define PDSS_NGDO_CTRL_NGDO_CLAMP_CTRL_POS                  (5UL)


/*
 * Current programmibility to adjust comparator offset (default 10=8V)
 */
#define PDSS_NGDO_CTRL_NGDO_CP_CTRL_MASK                    (0x00000180UL) /* <7:8> R:RW:2: */
#define PDSS_NGDO_CTRL_NGDO_CP_CTRL_POS                     (7UL)


/*
 * Test mode bits for ngdo : <spare,spare,spare, extra charging current for
 * 0.3uA>
 */
#define PDSS_NGDO_CTRL_NGDO_TM_NGDO_MASK                    (0x00001e00UL) /* <9:12> R:RW:1: */
#define PDSS_NGDO_CTRL_NGDO_TM_NGDO_POS                     (9UL)


/*
 * ADFT selection pins.
 */
#define PDSS_NGDO_CTRL_NGDO_DFT_MASK                        (0x0000e000UL) /* <13:15> R:RW:0: */
#define PDSS_NGDO_CTRL_NGDO_DFT_POS                         (13UL)


/*
 * Programmibility for external nfet gate charging current (default 000001=
 * 0.15u)
 */
#define PDSS_NGDO_CTRL_NGDO_SLEW_CTRL_MASK                  (0x003f0000UL) /* <16:21> R:RW:1: */
#define PDSS_NGDO_CTRL_NGDO_SLEW_CTRL_POS                   (16UL)


/*
 * Test mode bits for bias control : <spare,spare,spare>
 */
#define PDSS_NGDO_CTRL_NGDO_BIAS_CTRL_MASK                  (0x01c00000UL) /* <22:24> R:RW:0: */
#define PDSS_NGDO_CTRL_NGDO_BIAS_CTRL_POS                   (22UL)


/*
 * Current programmability for Vbg/R block (default 00 = 2.4uA)
 */
#define PDSS_NGDO_CTRL_VBGBYR_CTRL_MASK                     (0x06000000UL) /* <25:26> R:RW:0: */
#define PDSS_NGDO_CTRL_VBGBYR_CTRL_POS                      (25UL)


/*
 * Testmode to enable discharge on pmos gate in slew control block with gdrv_en
 */
#define PDSS_NGDO_CTRL_SLEW_P_GATE_DSCHG                    (1UL << 27) /* <27:27> R:RW:0: */


/*
 * SRSENSE HardIP High/Low Speed Filter and Edge detector configuration for
 * SCP_OUT detection (NA in PMG1S3)
 */
#define PDSS_INTR15_CFG_PDS_SCP_ADDRESS                     (0x400a2010UL)
#define PDSS_INTR15_CFG_PDS_SCP                             (*(volatile uint32_t *)(0x400a2010UL))
#define PDSS_INTR15_CFG_PDS_SCP_DEFAULT                     (0x00000400UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_EN             (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_CFG_MASK       (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_CFG_POS        (1UL)


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
#define PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_RESET          (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_BYPASS         (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_FILT[0] filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_SEL_MASK       (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_SEL_POS        (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_DPSLP_MODE          (1UL << 10) /* <10:10> R:RW:1: */


/*
 * PWM Hard IP CLK_PASC Filter and Edge detector configuration for PWM_OUT
 * and SKIP_OUT (NA in PMG1S3)
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
 * S8PDS EA Hard IP CLK_LF Filter and Edge detector configuration for CC_FLAG
 * (NA in PMG1S3)
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
 * INTR15 Status (NA in PMG1S3)
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
 * The status of s8pds_scp_top.scp_out
 */
#define PDSS_INTR15_STATUS_PDS_SCP_STATUS                   (1UL << 4) /* <4:4> RW:R:0: */


/*
 * s8pds_scp_top.scp_out Filtered output
 */
#define PDSS_INTR15_STATUS_PDS_SCP_FILT                     (1UL << 5) /* <5:5> RW:R:0: */


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
 * INTR15 interrupt Cause.(NA in PMG1S3)
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
 * s8pds_scp_top.scp_out changed (wakeup interrupt from deepsleep)
 * Check the INTR15_STATUS.PDS_SCP_STATUS value
 */
#define PDSS_INTR15_PDS_SCP_CHANGED                         (1UL << 2) /* <2:2> RW1S:RW1C:0: */


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
 * INTR15 Interrupt Set (NA in PMG1S3)
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
#define PDSS_INTR15_SET_PDS_SCP_CHANGED                     (1UL << 2) /* <2:2> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_SET_PWM_OUT_CHANGED                     (1UL << 12) /* <12:12> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_SET_SKIP_OUT_CHANGED                    (1UL << 13) /* <13:13> A:RW1S:0: */


/*
 * INTR15 interrupt Mask (NA in PMG1S3)
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
#define PDSS_INTR15_MASK_PDS_SCP_CHANGED_MASK               (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_MASK_PWM_OUT_CHANGED_MASK               (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR15_MASK_SKIP_OUT_CHANGED_MASK              (1UL << 13) /* <13:13> R:RW:0: */


/*
 * INTR15 interrupt Masked (NA in PMG1S3)
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
#define PDSS_INTR15_MASKED_PDS_SCP_CHANGED_MASKED           (1UL << 2) /* <2:2> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR15_MASKED_PWM_OUT_CHANGED_MASKED           (1UL << 12) /* <12:12> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR15_MASKED_SKIP_OUT_CHANGED_MASKED          (1UL << 13) /* <13:13> RW:R:0: */


/*
 * VBUS Transition config (NA in PMG1S3)
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
 * VBUS Transition control (NA in PMG1S3)
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
 * VBUS Transition Source/Sink shadow registers (NA in PMG1S3)
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


/*
 * VBUS Transition Source Initial/Final value registers (NA in PMG1S3)
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
 * VBUS Transition Sink Initial/Final value registers (NA in PMG1S3)
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
 * Indicates the Final SNK Register value to be reached after operation completion.
 */
#define PDSS_VBTR_SNK_INIT_FIN_VALUE_SNK_FIN_MASK           (0x03ff0000UL) /* <16:25> R:RW:0: */
#define PDSS_VBTR_SNK_INIT_FIN_VALUE_SNK_FIN_POS            (16UL)


/*
 * VBUS Transition Status registers (NA in PMG1S3)
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
 * S8PDBB 40V Regulator Control Register (NA in PMG1S3)
 */
#define PDSS_BB_40VREG_CTRL_ADDRESS                         (0x400a2108UL)
#define PDSS_BB_40VREG_CTRL                                 (*(volatile uint32_t *)(0x400a2108UL))
#define PDSS_BB_40VREG_CTRL_DEFAULT                         (0x04567082UL)

/*
 * LV output isolation (active low)
 * 0 : All the LV outputs are forced to a known value
 * 1 : Actual LV outputs are passed through
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_ISO_N                 (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Regulator enable signal in LV (vccd) domain
 * 0: Regulator is disabled
 * 1: Regulator is enabled
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_VREG_EN               (1UL << 1) /* <1:1> R:RW:1: */


/*
 * Master control for ADFT
 * 0 : ADFT outputs are disabled
 * 1 : ADFT outputs are enabled
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_ADFT_CTRL_MASK        (0x0000001cUL) /* <2:4> R:RW:0: */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_ADFT_CTRL_POS         (2UL)


/*
 * Reference voltage select signal
 * 0 - Use 0.74V dpslp reference
 * 1 - Use 0.74V derived from bandgap reference
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_VBG_EN                (1UL << 5) /* <5:5> R:RW:0: */


/*
 *  Test-mode to change the regulator output to 3.0V
 * 00 : vreg_out = 5v [FW]
 * 01 : vreg_out = 2.7v
 * 10 : vreg_out = 3.0v
 * 11 : vreg_out = 3.3v
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_T_VREG_3P3_MASK       (0x000000c0UL) /* <6:7> R:RW:2: */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_T_VREG_3P3_POS        (6UL)


/*
 * Controls for changing the active mode bias current
 * 1111 : Active mode full current
 * 0000 : Dpslp mode, no current [FW]
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_ACT_BIAS_DAC_MASK     (0x0000f000UL) /* <12:15> R:RW:7: */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_ACT_BIAS_DAC_POS      (12UL)


/*
 * Disables 1uA leaker on vreg_out
 * 0 : Keep leaker on
 * 1 : Disable the leaker
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_T_DIS_LUA_LEAKER      (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Turn on the inrush current limiting clamp bypassing the inrush current
 * detection
 * 0 : Normal operation [FW]
 * 1 : Force the clamp on
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_T_INRSH_CLAMP_ON      (1UL << 17) /* <17:17> R:RW:1: */


/*
 * Enable signal for regulator active mode
 * 0 : Regulator in Deepsleep mode
 * 1 : Regulator in active mode
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_VREG_ACT_EN           (1UL << 18) /* <18:18> R:RW:1: */


/*
 * Selection bits to vary the inrush limit for dpslp mode
 * 00 : in-rush limit in dpslp = 20mA
 * 01 : in-rush limit in dpslp = 30mA
 * 10 : in-rush limit in dpslp = 40mA
 * 11 : in-rush limit in dpslp = 50mA
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_DPSLP_CLAMP_SEL_MASK    (0x00180000UL) /* <19:20> R:RW:2: */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_DPSLP_CLAMP_SEL_POS    (19UL)


/*
 * Selection bits to vary the inrush detection threshold for active mode
 * 00 : inrush detection threshold = 250mA
 * 01 : inrush detection threshold = 300mA
 * 10 : inrush detection threshold = 400mA
 * 11 : inrush detection threshold = 500mA
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_INRSH_DET_SEL_MASK    (0x00600000UL) /* <21:22> R:RW:2: */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_INRSH_DET_SEL_POS     (21UL)


/*
 * Test-mode to force the in-rush clamp OFF ( 1 - Clamp always off , 0 -
 * Normal operation)
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_T_DIS_INRSH_CLAMP     (1UL << 23) /* <23:23> R:RW:0: */


/*
 * Test-mode to enable the 5uA leaker on VREG_OUT/VDDD ( 1 - Enable the leaker
 * , 0 - Disable the leaker)
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_T_EN_5UA_LEAKER       (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Test-mode to disable the 20uA leaker on VREG_OUT/VDDD ( 1 - Disbale the
 * leaker , 0 - Enable the leaker) (DPSLP=1)
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_T_DIS_20UA_LEAKER     (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Test-mode to disable the load based biasing in dpslp mode (1: disable
 * this feature , 0 : Enable) [FW]
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_T_DIS_LOAD_SENS_FB    (1UL << 26) /* <26:26> R:RW:1: */


/*
 * Test-mode to halve the gain of load based biasing in dpslp mode (1: half
 * gain , 0 : defualt gain)
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_T_HALF_LOAD_SENS_FB    (1UL << 27) /* <27:27> R:RW:0: */


/*
 * T bit to enable resistor divider on vreg_out(vddd) in case regulator is
 * disabled and Vddd is forced externally (FW)
 * 0 : resistor divider cut-off
 * 1 : resistor divider enabled
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_T_VDDD_DET_ON         (1UL << 28) /* <28:28> R:RW:0: */


/*
 * Enabling half current mode for VDDD BOD comparator
 * 0 : 1x current
 * 1 : 0.5x current
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_T_VDDD_COMP_HALF_I    (1UL << 29) /* <29:29> R:RW:0: */


/*
 * VDDD Brown-out-detect enable bit (FW)
 * 0 : disable
 * 1 : enable
 */
#define PDSS_BB_40VREG_CTRL_BB_40VREG_EN_VDDD_DET_COMP      (1UL << 30) /* <30:30> R:RW:0: */


/*
 * S8PDBB EA Control Register 0 (NA in PMG1S3)
 */
#define PDSS_BB_EA_0_CTRL_ADDRESS                           (0x400a210cUL)
#define PDSS_BB_EA_0_CTRL                                   (*(volatile uint32_t *)(0x400a210cUL))
#define PDSS_BB_EA_0_CTRL_DEFAULT                           (0x1112d462UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_ISO_N                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Powers down the block, active high
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_PD                          (1UL << 1) /* <1:1> R:RW:1: */


/*
 * Enable signal for IDAC
 * 0 - Disable
 * 1 - Enable
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_EN_CV                       (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Enable signal for cc gm amplifier
 * 0 - Disable
 * 1 - Enable
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_EN_CCAMP                    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Enable signal for cv gm amplifier
 * 0 - Disable
 * 1 - Enable
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_EN_CVAMP                    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * To select ccdet in cc_flag output:
 * 0: cc_flag output will not include cc_det
 * 1: cc_flag output will include cc_det
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_EN_CCDET                    (1UL << 5) /* <5:5> R:RW:1: */


/*
 * To select cvdet in cc_flag output:
 * 0: cc_flag output will not include cv_det_n
 * 1: cc_flag output will include cv_det_n
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_EN_CVDET                    (1UL << 6) /* <6:6> R:RW:1: */


/*
 * To enable CC Flag circuit
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_EN_CC_CV_FLAG               (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Enable signal for current sink DAC
 * 0 - Disable
 * 1 - Enable
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_ISNK_EN                     (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Enable signal for current source DAC
 * 0 - Disable
 * 1 - Enable
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_ISRC_EN                     (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Reference current selection for Constant voltage DAC
 * 00 - Deep sleep Refgen current
 * 01 - Internal Vgb/R current
 * 10 - BG current
 * 11 - Not used
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_IREF_SEL_MASK               (0x00000c00UL) /* <10:11> R:RW:1: */
#define PDSS_BB_EA_0_CTRL_BB_EA_IREF_SEL_POS                (10UL)


/*
 * trims to vary CV gm amp input bias current.
 * 14th bit is reserved for future use
 * 13:12 00 - 0uA; 01 - 8uA; 10 - 16uA 11 - 24uA
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_TRIM_CVAMP_IBIAS_MASK       (0x00007000UL) /* <12:14> R:RW:5: */
#define PDSS_BB_EA_0_CTRL_BB_EA_TRIM_CVAMP_IBIAS_POS        (12UL)


/*
 * trims to vary CC gm amp input bias current.
 * 17th bit is reserved for future use
 * 16:15 00 - 0uA; 01 - 8uA; 10 - 16uA 11 - 24uA
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_TRIM_CCAMP_IBIAS_MASK       (0x00038000UL) /* <15:17> R:RW:5: */
#define PDSS_BB_EA_0_CTRL_BB_EA_TRIM_CCAMP_IBIAS_POS        (15UL)


/*
 * trims to vary the CV amplifier gmboosting gain from sink side
 * 21st bit increases the offset for Gmboosting of CV amplifier
 * 20:18 increases the bias current on ptail to increase the gm of amplifier
 * dyanamically once it crosses the offset of CV amplifier
 * 20:18 000 - no boost gain; 001 - 0.25X gm_boost; 010 - 0.5X gm_boost;
 * 011 - 0.75X gm_boost ; 100 - 1X gm_boost;
 *  101 - 1.25X gm_boost; 110 - 1.5X gm_boost; 111 - 1.75X gm_boost ;
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_TRIM_GMBOOSTN_CV_MASK       (0x003c0000UL) /* <18:21> R:RW:4: */
#define PDSS_BB_EA_0_CTRL_BB_EA_TRIM_GMBOOSTN_CV_POS        (18UL)


/*
 * trims to vary the CC amplifier gmboosting gain from sink side
 * 25th bit increases the offset for Gmboosting
 * 24:22 increases the bias current on ptail to increase the gm of amplifier
 * dynamically once it crosses the offset of CC amplifier
 * 24:22 000 - no boost gain; 001 - 0.25X gm_boost; 010 - 0.5X gm_boost;
 * 011 - 0.75X gm_boost ; 100 - 1X gm_boost;
 *  101 - 1.25X gm_boost; 110 - 1.5X gm_boost; 111 - 1.75X gm_boost ;
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_TRIM_GMBOOSTN_CC_MASK       (0x03c00000UL) /* <22:25> R:RW:4: */
#define PDSS_BB_EA_0_CTRL_BB_EA_TRIM_GMBOOSTN_CC_POS        (22UL)


/*
 * trims to vary the amplifier gmboosting gain from source side
 * 29th bit increases the offset for gm boosting of CV amplifier
 * 28:26 increases the bias current on ptail to increase the gm of amplifier
 * dyanamically once it crosses the offset
 * 28:26 000 - no boost gain; 001 - 0.5X gm_boost; 010 - 1X gm_boost; 011
 * - 1.5X gm_boost ; 100 - 2X gm_boost;
 *  101 - 2.5X gm_boost; 110 - 3X gm_boost; 111 - 3.5X gm_boost ;
 */
#define PDSS_BB_EA_0_CTRL_BB_EA_TRIM_GMBOOSTP_CV_MASK       (0x3c000000UL) /* <26:29> R:RW:4: */
#define PDSS_BB_EA_0_CTRL_BB_EA_TRIM_GMBOOSTP_CV_POS        (26UL)


/*
 * S8PDBB EA Control Register 1 (NA in PMG1S3)
 */
#define PDSS_BB_EA_1_CTRL_ADDRESS                           (0x400a2110UL)
#define PDSS_BB_EA_1_CTRL                                   (*(volatile uint32_t *)(0x400a2110UL))
#define PDSS_BB_EA_1_CTRL_DEFAULT                           (0x00110804UL)

/*
 * trims to vary the amplifier gmboosting gain from source side
 * 3rd bit increases the offset for gm boosting of CC amplifier
 * 2:0 increases the sourcing current at pad_ea_out so that amplifier never
 * saturates
 * 2:0 000 - no boost gain; 001 - 0.5X gmamp_current; 010 - 1X gm_boost;
 * 011 - 1.5X gm_boost ; 100 - 2X gm_boost;
 *  101 - 2.5X gm_boost; 110 - 3X gm_boost; 111 - 3.5X gm_boost ;
 */
#define PDSS_BB_EA_1_CTRL_BB_EA_TRIM_BOOSTP_CC_MASK         (0x0000000fUL) /* <0:3> R:RW:4: */
#define PDSS_BB_EA_1_CTRL_BB_EA_TRIM_BOOSTP_CC_POS          (0UL)


/*
 * Control bits for the analog test mux
 * Bits adft0
 * 0000  Z
 * 0001  observe ivbgbyR/i2p4u_*
 * 0010  Observe Sink(NMOS) DAC current on resistor
 * 0011  Observe DAC current
 * 0100  vref_0p74
 * 0101  vref_cv
 * 0110  vref_1p2
 * 0111  iref_2p4u
 * 1000  Z
 * 1001  vref_cc
 * 1010  vbus_feedback divider
 * 1011  igmboostn_cv
 * 1100  igmboostn_cc
 * 1101  vref_2p4
 * 1110  vref_2p1
 * 1111  vref_lo
 *
 * Bits adft1
 * 0000  Z
 * 0001  observe ivbgbyR/i2p4u_*
 * 0010   Observe Source(PMOS) DAC current on resistor
 * 0011  Z
 * 0100  Z
 * 0101  ibetamultiplier
 * 0110  ivbgbyr
 * 0111  cc_ctrl_in
 * 1000  Z
 * 1001  igm_CV
 * 1010  igm_CC
 * 1011  igmboostp_cv
 * 1100  igmboostp_cc
 * 1101  igmboostp_pload
 * 1110  ioscanc
 * 1111  Z
 */
#define PDSS_BB_EA_1_CTRL_BB_EA_ADFT_CTRL_MASK              (0x000007f0UL) /* <4:10> R:RW:0: */
#define PDSS_BB_EA_1_CTRL_BB_EA_ADFT_CTRL_POS               (4UL)


/*
 * trims to vary the source load current on pad_ea_out.
 * 000 - 5uA, 001 - 10uA, 010 - 15uA, 011 - 20uA,
 * 100 - 20uA, 101 - 25uA, 110 - 30uA, 111 -35uA.
 */
#define PDSS_BB_EA_1_CTRL_BB_EA_TRIM_PLOAD_MASK             (0x00003800UL) /* <11:13> R:RW:1: */
#define PDSS_BB_EA_1_CTRL_BB_EA_TRIM_PLOAD_POS              (11UL)


/*
 * trims to vary CC_DET current
 * 00000 - 0.0uA; 00001 - 0.6uA ; 00010 - 1.2uA ; 00011 - 1.8uA
 * 00100 - 2.4uA;
 * 01000 - 4.8uA;
 * 10000 - 9.6uA;
 */
#define PDSS_BB_EA_1_CTRL_TRIM_CC_FLAG_MASK                 (0x0007c000UL) /* <14:18> R:RW:4: */
#define PDSS_BB_EA_1_CTRL_TRIM_CC_FLAG_POS                  (14UL)


/*
 * trims to vary CV_DET current
 * 00000 - 0.0uA; 00001 - 0.6uA ; 00010 - 1.2uA ; 00011 - 1.8uA
 * 00100 - 2.4uA;
 * 01000 - 4.8uA;
 * 10000 - 9.6uA;
 */
#define PDSS_BB_EA_1_CTRL_TRIM_CV_FLAG_MASK                 (0x00f80000UL) /* <19:23> R:RW:2: */
#define PDSS_BB_EA_1_CTRL_TRIM_CV_FLAG_POS                  (19UL)


/*
 * S8PDBB EA Control Register 2 (NA in PMG1S3)
 */
#define PDSS_BB_EA_2_CTRL_ADDRESS                           (0x400a2114UL)
#define PDSS_BB_EA_2_CTRL                                   (*(volatile uint32_t *)(0x400a2114UL))
#define PDSS_BB_EA_2_CTRL_DEFAULT                           (0x0000105cUL)

/*
 * test mode options for EA
 * t_ea<0>            This will enable 1pF compensation cap parallel to 200kohm
 * of VBUS resistor divider.
 * t_ea<4:1>         limit max voltage on pad_ea_out
 * t_ea<7:5>         limit min vfoltage on pad_ea_out
 * t_ea<8>            vref_dpslp will be used as vref_cv
 * t_ea<9>            zero offset scheme enabled for cc
 * t_ea<10>          zero offset scheme enabled for cv
 * t_ea<11>          srss_iref will be used everywhere instead of betamult
 * and vbgbyr current
 * t_ea<12>          offset cancellation scheme at cv/cc transition is enabled
 * t_ea<13>          enables the sort loop to trim cvdac and cc vref
 * t_ea<14>          disables the default on pload current
 * t_ea<15>          pad_ea_out pulled down to ground
 */
#define PDSS_BB_EA_2_CTRL_BB_EA_T_EA_MASK                   (0x0001ffffUL) /* <0:16> R:RW:4188: */
#define PDSS_BB_EA_2_CTRL_BB_EA_T_EA_POS                    (0UL)


/*
 * S8PDBB EA Control Register 3 (NA in PMG1S3)
 */
#define PDSS_BB_EA_3_CTRL_ADDRESS                           (0x400a2118UL)
#define PDSS_BB_EA_3_CTRL                                   (*(volatile uint32_t *)(0x400a2118UL))
#define PDSS_BB_EA_3_CTRL_DEFAULT                           (0x00000000UL)

/*
 * 10-bit DAC control for current sink
 */
#define PDSS_BB_EA_3_CTRL_BB_ISNK_DAC_CTRL_MASK             (0x000003ffUL) /* <0:9> R:RW:0: */
#define PDSS_BB_EA_3_CTRL_BB_ISNK_DAC_CTRL_POS              (0UL)


/*
 * 7-bit DAC control for current source
 */
#define PDSS_BB_EA_3_CTRL_BB_ISRC_DAC_CTRL_MASK             (0x0001fc00UL) /* <10:16> R:RW:0: */
#define PDSS_BB_EA_3_CTRL_BB_ISRC_DAC_CTRL_POS              (10UL)


/*
 * S8PDBB 40CSA Control Register 0 (NA in PMG1S3)
 */
#define PDSS_BB_40CSA_0_CTRL_ADDRESS                        (0x400a211cUL)
#define PDSS_BB_40CSA_0_CTRL                                (*(volatile uint32_t *)(0x400a211cUL))
#define PDSS_BB_40CSA_0_CTRL_DEFAULT                        (0x40000011UL)

/*
 * 0: scap reset controlled by csa_blk_dis2_lv (configuration bit)
 * 1: scap reset controlled by RTL(scap_rst_rtl_lv)
 */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_SCAP_RST_RTL_CTRL_LV    (1UL << 0) /* <0:0> R:RW:1: */


/*
 * R2R buffer enable signal
 * 0: disable
 * 1: enable
 */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_EN_40CSA_LEV_LV       (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Does not control any functionality in 40CSA
 */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_ICONST_BYPASS_EN_LV    (1UL << 2) /* <2:2> R:RW:0: */


/*
 * nmos cap trim dac & pmos output dac enable signal
 * 0: disable
 * 1: enable
 */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_EN_SCOMP_DAC_LV       (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Ilim comparator hysteresis control
 * 00: no hysteresis
 * 01: 11mv
 * 10: 22mv
 * 11: 33mv
 */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_ILIM_CMP_HYS_SEL_LV_MASK    (0x00000030UL) /* <4:5> R:RW:1: */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_ILIM_CMP_HYS_SEL_LV_POS    (4UL)


/*
 * Testmodes for 40csa top level block
 * 15: enable csa stage1 output connection to amux
 * 14: 13 : controls csa stage1 output level in combination with sel_csa_lev_lv
 * bits
 *    00 - Step size of current is 10uA
 *    01 - Step size of current is 20uA
 *    10 - Step size of current is 2.5uA
 *     11 - Step size of current is 5uA
 * 12: spare
 * 11: disable overshoot clamping in r2r buffer
 * 10: enable slow current mode in r2r buffer
 * 9: disable output internal clamp in ilim comparator
 * 8: bypass final inverter ibias in ilim comparator
 * 7: enable slow current mode in ilim comparator
 * 6: csa40_out_hv (40CSA output) connected to ilim comparator
 * 5: disables self biasing scheme in config delay
 * 4:2 : controls config delay bias settings
 * 1: enable slow current mode in csa 1st stage
 * 0: disable fixed offset current in csa 1st stage
 */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_T_40CSA_LV_MASK       (0x003fffc0UL) /* <6:21> R:RW:0: */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_T_40CSA_LV_POS        (6UL)


/*
 * adft_lv<24:22> controls adft_out_hv<0>
 * 7: iout_voutbyr_adft_hv
 * 6: ibias_2p4_vbgbyr_snko<0>
 * 5: csa_stg1_buf_out_hv
 * 4: vgnd
 * 3: vref_ilim_filt
 * 2: ilim_ana_out_hv
 * 1: csa_stg1_out_int_hv
 * 0: highz
 *
 * adft_lv<27:25> controls adft_out_hv<1>
 * 7: vgnd
 * 6: vout9p0_adft_hv
 * 5: iout_scomp_hv
 * 4: vgnd
 * 3: iout_const_adft_hv
 * 2: vgnd
 * 1: vgnd
 * 0: highz
 */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_ADFT_LV_MASK          (0x0fc00000UL) /* <22:27> R:RW:0: */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_ADFT_LV_POS           (22UL)


/*
 * Controls the fixed offset current flowing into csa 1st stage output. Step
 * size is 10uA.
 * 0- 0uA
 * 1-10uA
 * 2-20uA
 * ....
 * 7:70uA
 */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_SEL_FIX_OFF_LV_MASK    (0x70000000UL) /* <28:30> R:RW:4: */
#define PDSS_BB_40CSA_0_CTRL_BB_40CSA_SEL_FIX_OFF_LV_POS    (28UL)


/*
 * S8PDBB 40CSA Control Register 1 (NA in PMG1S3)
 */
#define PDSS_BB_40CSA_1_CTRL_ADDRESS                        (0x400a2120UL)
#define PDSS_BB_40CSA_1_CTRL                                (*(volatile uint32_t *)(0x400a2120UL))
#define PDSS_BB_40CSA_1_CTRL_DEFAULT                        (0x01010120UL)

/*
 * summing cap selection signal
 * 0 - 12.6p
 * 1 - 6.3p
 * 2 - 3.15p
 * 3 - 1.575p
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_SEL_SCAP_LV_MASK      (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_SEL_SCAP_LV_POS       (0UL)


/*
 * controls pmos output dac when scomp_out_en_lv=0. X is the lsb current
 * of the DAC.
 * 0 - 0
 * 1 - 1X
 * 2 - 2X
 * 3 - 4X
 * 4 - 8X
 * 5 - 16X
 * 6 - 32X
 * 7 - 64X
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_SEL_IDAC_10P_BYPASS_LV_MASK    (0x0000001cUL) /* <2:4> R:RW:0: */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_SEL_IDAC_10P_BYPASS_LV_POS    (2UL)


/*
 * Voutbyr mode enable signal  - Ivoutbyr connected to nmos dac
 * 0 - Ivoutbyr disconnected
 * 1 - Ivoutbyr connected
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_VOUTBYR_MODE_EN_LV    (1UL << 5) /* <5:5> R:RW:1: */


/*
 * Signal controlling the csa stage1 variable offset level.
 * Following table is for t_40csa_lv<14:13> = 00. Step size of current is
 * 10uA.
 * <3>- NC
 * <2:0> - 3 bit control
 * 0- 0uA
 * 1-10uA
 * 2-20uA
 * ....
 * 7:70uA
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_SEL_CSA_LEV_LV_MASK    (0x000003c0UL) /* <6:9> R:RW:4: */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_SEL_CSA_LEV_LV_POS    (6UL)


/*
 * Signal to set scap_reset high when bb_40csa_scap_rst_rtl_ctrl_lv is set
 * low
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_CSA_BLK_DIS2_LV       (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Signal to set Iconstant value in slope compensation block. Step size of
 * current is 0.4uA.
 * <4> : NC
 * <3:0> - 4 bit control
 * 0 - 0uA
 * 1 - 0.4uA
 * 2 - 0.8uA
 * .....
 * 15 - 6uA
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_SEL_ICONST_LV_MASK    (0x0000f800UL) /* <11:15> R:RW:0: */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_SEL_ICONST_LV_POS     (11UL)


/*
 * 0: reset sw1 (switch in csa 1stage) controlled by csa_blk_dis1_lv(configuration
 * bit)
 * 1: reset sw1 controlled by RTL(rst_sw1_rtl_lv)
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_RESET_SW1_RTL_CTRL_LV    (1UL << 16) /* <16:16> R:RW:1: */


/*
 * Signal to set reset_sw1 high when bb_40csa_reset_sw1_rtl_ctrl_lv is set
 * low
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_CSA_BLK_DIS1_LV       (1UL << 17) /* <17:17> R:RW:0: */


/*
 * Enable signal for voutbyr block
 * 0 - disable
 * 1 - enable
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_SCOMP_VOUTBYR_LV    (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Not used. Does not control any functionality in 40CSA.
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_DEL_SEL_PWMOUT_BLK_LV_MASK    (0x00f80000UL) /* <19:23> R:RW:0: */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_DEL_SEL_PWMOUT_BLK_LV_POS    (19UL)


/*
 * Gain selection for current limit path in csa 1st stage
 * 00 - G=5
 * 01 - G=10
 * 10 - G=20
 * 11 - G=40
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_SEL_ILIM_AV_LV_MASK    (0x03000000UL) /* <24:25> R:RW:1: */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_SEL_ILIM_AV_LV_POS    (24UL)


/*
 * Iconst mode enable signal  - Iconst output connected to nmos dac
 * 0 - iconst disconnected
 * 1 - iconst connected
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_ICONST_MODE_EN_LV     (1UL << 26) /* <26:26> R:RW:0: */


/*
 * Enable signal for contant bias and vbgbyr bias block
 * 0 - disable
 * 1 - enable
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_BIAS_LV            (1UL << 27) /* <27:27> R:RW:0: */


/*
 * Master enable signal for ADFT
 * 0 - disable
 * 1 - enable
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_ADFT_EN_LV            (1UL << 28) /* <28:28> R:RW:0: */


/*
 * Enable signal for contant curent block in slope compensation
 * 0 - disable
 * 1 - enable
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_SCOMP_CONST_LV     (1UL << 29) /* <29:29> R:RW:0: */


/*
 * Enable signal for csa 1st stage
 * 0 - disable
 * 1 - enable
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_40CSA_STG1_LV      (1UL << 30) /* <30:30> R:RW:0: */


/*
 * Global enable signal for 40CSA block
 * 0 - disable
 * 1 - enable
 */
#define PDSS_BB_40CSA_1_CTRL_BB_40CSA_ENABLE_40CSA_LV       (1UL << 31) /* <31:31> R:RW:0: */


/*
 * S8PDBB 40CSA Control Register 2 (NA in PMG1S3)
 */
#define PDSS_BB_40CSA_2_CTRL_ADDRESS                        (0x400a2124UL)
#define PDSS_BB_40CSA_2_CTRL                                (*(volatile uint32_t *)(0x400a2124UL))
#define PDSS_BB_40CSA_2_CTRL_DEFAULT                        (0x03070000UL)

/*
 * Test modes for slope comp block
 * <1:0>
 * 00 - No additional current added to the slope compensation output
 * 01 - adds 9.4% current with max dac code to the slope compensation output
 * 10 - adds 18.8% current with max dac code to the slope compensation output
 * 11 - adds 28.2% current with max dac code to the slope compensation output
 * <2>
 * 0 - 9% vout connected to voutbyr opamp
 * 1 - vbg connected to voutbyr opamp
 * <3>
 * 0: iout_voutbyr_adft signal connected to adft block
 * 1: iout_voutbyr_adft signal connected to ivoutbyr_hv output pin
 * <5:4>
 * 00 : 6k connected at the csa stage1 output while reset_sw1=0
 * 01 : 3k connected at the csa stage1 output while reset_sw1=0
 * 10 : 12k connected at the csa stage1 output while reset_sw1=0
 * 11 : 24k connected at the csa stage1 output while reset_sw1=0
 * <7:6>
 * spares
 */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_T_SCOMP_LV_MASK       (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_T_SCOMP_LV_POS        (0UL)


/*
 * Connected to Delay block. But delay block is not used inside the HardIP
 * currently.
 */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_DEL_SEL_BLK_DIS1_LV_MASK    (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_DEL_SEL_BLK_DIS1_LV_POS    (8UL)


/*
 * PWM output blanking control
 * <18:16> - 3 bit control gives 7 step control for each step size
 * <19> - spare
 * <22:20>
 * 000 - step size ~5ns
 * 001 - step size ~10ns
 * 011 - step size ~20ns
 * 111 - step size ~40ns
 * <23> - spare
 */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_DEL_SEL_BLK_DIS2_LV_MASK    (0x00ff0000UL) /* <16:23> R:RW:7: */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_DEL_SEL_BLK_DIS2_LV_POS    (16UL)


/*
 * Power down signal of Ilim comparator
 * 0 - enable
 * 1 - disable
 */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_PD_ILIMCMP_LV         (1UL << 24) /* <24:24> R:RW:1: */


/*
 * Gain selection for csa path in csa 1st stage
 * 00 - G=5
 * 01 - G=10
 * 10 - G=20
 * 11 - G=40
 */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_SEL_CSA_AV_LV_MASK    (0x06000000UL) /* <25:26> R:RW:1: */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_SEL_CSA_AV_LV_POS     (25UL)


/*
 * Disconnects the hv signal path coming from PWM block to the logic. Must
 * be always 0.
 */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_MODE_CTRL_LV          (1UL << 29) /* <29:29> R:RW:0: */


/*
 * Does not control any functionality in 40CSA (Spare)
 */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_MODE_SEL_LV_MASK      (0xc0000000UL) /* <30:31> R:RW:0: */
#define PDSS_BB_40CSA_2_CTRL_BB_40CSA_MODE_SEL_LV_POS       (30UL)


/*
 * S8PDBB 40CSA Control Register 3 (NA in PMG1S3)
 */
#define PDSS_BB_40CSA_3_CTRL_ADDRESS                        (0x400a2128UL)
#define PDSS_BB_40CSA_3_CTRL                                (*(volatile uint32_t *)(0x400a2128UL))
#define PDSS_BB_40CSA_3_CTRL_DEFAULT                        (0x00000040UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 * 1: Digital outputs from the 40CSA block are connected to the LV outputs
 */
#define PDSS_BB_40CSA_3_CTRL_BB_40CSA_ISO_N                 (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Does not control any functionality in 40CSA (spare)
 */
#define PDSS_BB_40CSA_3_CTRL_BB_40CSA_SET_BUCK_LV           (1UL << 1) /* <1:1> R:RW:0: */


/*
 * PMOS output dac selection bits in slope compensation block. X is the lsb
 * current of the DAC.
 * 0 - 0
 * 1 - 1X
 * 2 - 2X
 * 3 - 3X
 * .......
 * 255 - 255X
 */
#define PDSS_BB_40CSA_3_CTRL_BB_40CSA_SEL_IDAC_LV_MASK      (0x000003fcUL) /* <2:9> R:RW:16: */
#define PDSS_BB_40CSA_3_CTRL_BB_40CSA_SEL_IDAC_LV_POS       (2UL)


/*
 * <0> 1: In Buck mode scap_rst_rtl_lv de-asserts at end of switching cycle
 * and not after fix width
 * <1> 1: In BBBuck mode scap_rst_rtl_lv de-asserts at end of switching cycle
 * and not after fix width
 * <2> 1: In BBBoost mode scap_rst_rtl_lv de-asserts at end of switching
 * cycle and not after fix width
 * <3> 1: In Boost mode scap_rst_rtl_lv de-asserts at end of switching cycle
 * and not after fix width
 */
#define PDSS_BB_40CSA_3_CTRL_BB_40CSA_SCAP_RST_EOC_CTRL_MASK    (0x78000000UL) /* <27:30> R:RW:0: */
#define PDSS_BB_40CSA_3_CTRL_BB_40CSA_SCAP_RST_EOC_CTRL_POS    (27UL)


/*
 * 0 : BB_40CSA_3_CTRL.BB_40CSA_SEL_IDAC_LV is used in all modes as input
 * to sel_idac_lv<7:0>
 * 1 : In Buck mode BB_40CSA_SEL_IDAC_LV is used as input to sel_idac_lv<7:0>
 *      In BBBuck mode BB_40CSA_4_CTRL.BB_40CSA_SEL_IDAC_BBBUCK_LV is used
 * as input to sel_idac_lv<7:0>
 *      In BBBoost mode BB_40CSA_4_CTRL.BB_40CSA_SEL_IDAC_BBBOOST_LV is used
 * as input to sel_idac_lv<7:0>
 *      In Boost mode BB_40CSA_4_CTRL.BB_40CSA_SEL_IDAC_BOOST_LV is used
 * as input to sel_idac_lv<7:0>
 */
#define PDSS_BB_40CSA_3_CTRL_BB_40CSA_SEL_IDAC_INDPNT       (1UL << 31) /* <31:31> R:RW:0: */


/*
 * S8PDBB PWM Control Register 0 (NA in PMG1S3)
 */
#define PDSS_BB_PWM_0_CTRL_ADDRESS                          (0x400a212cUL)
#define PDSS_BB_PWM_0_CTRL                                  (*(volatile uint32_t *)(0x400a212cUL))
#define PDSS_BB_PWM_0_CTRL_DEFAULT                          (0x52a404ceUL)

/*
 * Control bits to alter hysteresis of vout under voltage detection comparator
 * 2'b00 = 0mV
 * 2'b01 = 2.84mV - 9mV
 * 2'b10 = 5.88mV - 19mV
 * 2'b11 = 8.70mV - 29mV
 */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUTUV_COMP_HYS_MASK    (0x00000003UL) /* <0:1> R:RW:2: */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUTUV_COMP_HYS_POS    (0UL)


/*
 * Control bits to alter boost comparator detection threshold. This detection
 * can be changed from 104% to 42% in steps of 2% with 31 steps.
 * 0-42%, 1-44%, 2-46%......31-104%.
 */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BOOST_2_MASK    (0x0000007cUL) /* <2:6> R:RW:19: */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BOOST_2_POS    (2UL)


/*
 * Control bits to alter bb_comp comparator detection threshold (for hysteresis).
 * This detection can be changed from 89% to 120% in steps of 2% with 31
 * steps.
 * 0-89%, 1-90%, 2-91%......31-120%.
 */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BB_2_MASK    (0x00000f80UL) /* <7:11> R:RW:9: */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BB_2_POS    (7UL)


/*
 * Control bits to alter hysteresis of boost comparator.
 * 2'b00 = 0mV
 * 2'b01 = 2.84mV - 9mV
 * 2'b10 = 5.88mV - 19mV
 * 2'b11 = 8.70mV - 29mV
 */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_BOOST_COMP_HYS_MASK    (0x0000c000UL) /* <14:15> R:RW:0: */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_BOOST_COMP_HYS_POS     (14UL)


/*
 * Enable signal for spare PWM comparator (planned for EA offset scheme)
 */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_EN_PWMCOMP_NOS            (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Control bits to alter hysteresis of vin under voltage detection comparator.
 * 2'b00 = 0mV
 * 2'b01 = 2.84mV - 9mV
 * 2'b10 = 5.88mV - 19mV
 * 2'b11 = 8.70mV - 29mV
 */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VINUV_COMP_HYS_MASK    (0x00060000UL) /* <17:18> R:RW:2: */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VINUV_COMP_HYS_POS     (17UL)


/*
 * Control bits to alter hysteresis of buck comparator.
 * 2'b00 = 0mV
 * 2'b01 = 2.84mV - 9mV
 * 2'b10 = 5.88mV - 19mV
 * 2'b11 = 8.70mV - 29mV
 */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_BUCK_COMP_HYS_MASK     (0x00180000UL) /* <19:20> R:RW:0: */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_BUCK_COMP_HYS_POS      (19UL)


/*
 * Control bits to alter boost comparator detection threshold(for hysteresis).
 * This detection can be changed from 104% to 42% in steps of 2% with 31
 * steps.
 * 0-42%, 1-44%, 2-46%......31-104%.
 */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BOOST_1_MASK    (0x03e00000UL) /* <21:25> R:RW:21: */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BOOST_1_POS    (21UL)


/*
 * Enable signal for PWM comparator
 */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_EN_PWMCOMP                (1UL << 26) /* <26:26> R:RW:0: */


/*
 * Control bits to alter buck comparator detection threshold (for hysteresis).
 * This detection can be changed from 96% to 158% in steps of 2% with 31
 * steps.
 * 0-96%, 1-98%, 2-100%......31-158%.
 *
 */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BUCK_2_MASK    (0xf8000000UL) /* <27:31> R:RW:10: */
#define PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BUCK_2_POS    (27UL)


/*
 * S8PDBB PWM Control Register 1 (NA in PMG1S3)
 */
#define PDSS_BB_PWM_1_CTRL_ADDRESS                          (0x400a2130UL)
#define PDSS_BB_PWM_1_CTRL                                  (*(volatile uint32_t *)(0x400a2130UL))
#define PDSS_BB_PWM_1_CTRL_DEFAULT                          (0x64121a01UL)

/*
 * Control bits to alter hysteresis of spare PWM comparator.
 * 2'b00 = 0mV
 * 2'b01 = 7.90mV - 24mV
 * 2'b10 = 15.3mV - 46mV
 * 2'b11 = 23.0mV - 75mV
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_PWMCOMP_NOS_HYS_MASK    (0x00000003UL) /* <0:1> R:RW:1: */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_PWMCOMP_NOS_HYS_POS    (0UL)


/*
 * Control bits for the ADFT switches. For detailed table check BROS doc.
 * 0000-adft output's are hiZ
 *
 * pwm_adft<6>    pwm_adft<2:0>             adft<0>
 * 0                      000                               z
 * 0                      001                               "Force vin_ea"
 * 0                      010                               "Force vout_resdiv_10per"
 * 0                      011                               "Force vref_vinuv"
 * 0                      100                               "Force vref_vinov"
 * 0                      101                               "observe isrc_2p4u"
 * 0                      110                               "Force vout_resdiv_10per_voutuv"
 * 0                      111                               "Force vinn pwmcomp_2"
 * 1                      000                               z
 * 1                      001                               "Observe vin_ea"
 * 1                      010                               "Observe vin_resdiv_10per"
 * 1                      011                               "Observe vin_resdiv_8per"
 * 1                      100                               "Observe vin_resdiv_4per"
 * 1                      101                               "Observe vout_resdiv_10per"
 * 1                      110                               "Observe vout_resdiv_4per"
 * 1                      111                                         "Observe
 * calibration UGB-out"
 *
 * pwm_adft<6>    pwm_adft<5:3>             adft<1>
 * 0                      000                               z
 * 0                      001                               "Force vref_skip"
 * 0                      010                               "Force vin_csa"
 * 0                      011                               "Force vin_resdiv_10per"
 * 0                      100                               "Force vin_resdiv_4per"
 * 0                      101                               rgnd
 * 0                      110                               "Force vref_voutuv"
 * 0                      111                               "Force vinp pwmcomp_2"
 * 1                      000                               z
 * 1                      001                               "Observe vref_skip"
 * 1                      010                               "Observe vref_vin_uv"
 * 1                      011                               "Observe vref_vin_ov"
 * 1                      100                               "Observe vref_vout_uv"
 * 1                      101                               "Observe vin_csa"
 * 1                      110                               rgnd
 * 1                      111                                         "Force
 * calibration UGB-in"
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_PWM_ADFT_MASK             (0x000001fcUL) /* <2:8> R:RW:0: */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_PWM_ADFT_POS              (2UL)


/*
 * Control bits to alter bb_comp comparator detection threshold. This detection
 * can be changed from 89% to 120% in steps of 2% with 31 steps.
 * 0-89%, 1-90%, 2-91%......31-120%.
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BB_1_MASK    (0x00003e00UL) /* <9:13> R:RW:13: */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BB_1_POS    (9UL)


/*
 * Enable signal for vin/vout under voltage and over voltage detection block.
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_EN_VINVOUT_UVOV_DET       (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Enable signal for SKIP comparator
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_EN_SKIP_COMP              (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Control bits to alter hysteresis of vin over voltage detection comparator.
 * 2'b00 = 0mV
 * 2'b01 = 2.84mV - 9mV
 * 2'b10 = 5.88mV - 19mV
 * 2'b11 = 8.70mV - 29mV
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_VINOV_COMP_HYS_MASK    (0x00030000UL) /* <16:17> R:RW:2: */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_VINOV_COMP_HYS_POS     (16UL)


/*
 * Enable signal for whole PWM block except vin resistor divider
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_ENABLE_PWM                (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Control bits to alter hysteresis of skip comparator.
 * 2'b00 = 0mV
 * 2'b01 = 2.84mV - 9mV
 * 2'b10 = 5.88mV - 19mV
 * 2'b11 = 8.70mV - 29mV
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_SKIP_COMP_HYS_MASK     (0x00180000UL) /* <19:20> R:RW:2: */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_SKIP_COMP_HYS_POS      (19UL)


/*
 * Control bits to alter hysteresis of bb_comp comparator.
 * 2'b00 = 0mV
 * 2'b01 = 2.84mV - 9mV
 * 2'b10 = 5.88mV - 19mV
 * 2'b11 = 8.70mV - 29mV
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_BB_COMP_HYS_MASK       (0x00600000UL) /* <21:22> R:RW:0: */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_BB_COMP_HYS_POS        (21UL)


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_ISO_N                     (1UL << 23) /* <23:23> R:RW:0: */


/*
 * Enable signal for mode detection comparators block.
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_EN_MODE_DET               (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Control bits to alter hysteresis of pwm comparator.
 * 2'b00 = 0mV
 * 2'b01 = 7.90mV - 24mV
 * 2'b10 = 15.3mV - 46mV
 * 2'b11 = 23.0mV - 75mV
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_PWMCOMP_HYS_MASK       (0x06000000UL) /* <25:26> R:RW:2: */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_PWMCOMP_HYS_POS        (25UL)


/*
 * Control bits to alter buck comparator detection threshold. This detection
 * can be changed from 96% to 158% in steps of 2% with 31 steps.
 * 0-96%, 1-98%, 2-100%......31-158%.
 */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BUCK_1_MASK    (0xf8000000UL) /* <27:31> R:RW:12: */
#define PDSS_BB_PWM_1_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BUCK_1_POS    (27UL)


/*
 * S8PDBB PWM Control Register 2 (NA in PMG1S3)
 */
#define PDSS_BB_PWM_2_CTRL_ADDRESS                          (0x400a2134UL)
#define PDSS_BB_PWM_2_CTRL                                  (*(volatile uint32_t *)(0x400a2134UL))
#define PDSS_BB_PWM_2_CTRL_DEFAULT                          (0x00020018UL)

/*
 * Enable signal for vin resistor divider
 */
#define PDSS_BB_PWM_2_CTRL_BB_PWM_EN_VIN_RES                (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Test-Mode bits to modify circuit functionality in future.
 * t_pwm<0>:        0 -PWM comparator bias currents will be as per design
 *                           1 -PWM comparator bias currents will be 0.5x
 * t_pwm<1>:        0 -SKIP comparator bias currents will be as per design
 *                           1 -SKIP comparator bias currents will be 2x
 * t_pwm<2>:        0 - ilimit_det from 40CSA will have control on hs1/ls1/ls2/hs2_pwm
 * outputs.
 *                           1 - ilimit_det will be don't care.
 * t_pwm<3>:        0 - RTL+PWM_comp will control hs1/ls1/ls2/hs2_pwm outputs.
 *                            1 - only RTL will control hs1/ls1/ls2/hs2_pwm
 * outputs.
 * t_pwm<4>:        0 -All 3 mode detection comparators bias currents will
 * be as per design
 *                           1 -All 3 mode detection comparators bias currents
 * will be 2x
 * t_pwm<5>:        0 -All 3 vinvout_uvov detection comparators bias currents
 * will be as per design
 *                            1 -All 3 vinvout_uvov detection comparators
 * bias currents will be 2x
 * t_pwm<6>:        0 -mode detection comparator hysteresis switches will
 * be controlled from filtered version of comparator outputs from RTL.
 *                            1 -mode detection comparator hysteresis switches
 * will be controlled directly from comparator outputs. "
 * t_pwm<7>:        0 -PWM comparator scheme out_int clamp is enabled .
 *                            1 -PWM comparator scheme out_int clamp is disabled
 * .
 * t_pwm<8>:        0 -PWM comparator offset trim network in enabled.
 *                           1 -PWM comparator offset trim network in disabled.
 * t_pwm<9>:        0 -PWM comparator final inverter in current starved mode.
 *                           1 -PWM comparator final inverter current is
 * bypassed.
 * t_pwm<10>:      0 -PWM comparator bias currents will be as per design
 *                           1 -PWM comparator bias currents will be 0.5x
 * t_pwm<11>:      0 -PWM comparator scheme out_int clamp is enabled .
 *                           1 -PWM comparator scheme out_int clamp is disabled
 * .
 * t_pwm<12>:      0 -PWM comparator offset trim network in enabled.
 *                            1 -PWM comparator offset trim network in disabled.
 * t_pwm<13>:      0 -PWM comparator final inverter in current starved mode.
 *                           1 -PWM comparator final inverter current is
 * bypassed.
 * t_pwm<14>:      0 -LS2 is reset from pwm_comp || reset_boost.
 *                            1 -LS2 is reset from pwm_comp_nos || reset_boost.
 * t_pwm<16:15>: Trimmable RC filter on vout resistor divider tap points.
 * t_pwm<17>:      0 -ilimit_det is selceted from 40csa hardIP.
 *                            1 -ilimit_det is selceted from RTL.
 * t_pwm<18>:      0 -pwmcomp_blnk is selceted from 40csa hardIP.
 *                           1 -pwmcomp_blnk is selceted from RTL.
 * t_pwm<23:17>: reserved
 */
#define PDSS_BB_PWM_2_CTRL_BB_PWM_T_PWM_MASK                (0x01fffffeUL) /* <1:24> R:RW:65548: */
#define PDSS_BB_PWM_2_CTRL_BB_PWM_T_PWM_POS                 (1UL)


/*
 * S8PDBB GDRVO Control Register 0 (NA in PMG1S3)
 */
#define PDSS_BB_GDRVO_0_CTRL_ADDRESS                        (0x400a2138UL)
#define PDSS_BB_GDRVO_0_CTRL                                (*(volatile uint32_t *)(0x400a2138UL))
#define PDSS_BB_GDRVO_0_CTRL_DEFAULT                        (0x2c820799UL)

/*
 * HSDR PMOS/Pull-up driver Strength Configuration (Ohm):
 * 0x0=30.0 Ohm
 * 0x1=20.1 Ohm
 * 0x2=15.5 Ohm
 * 0x3=12.2 Ohm
 * 0x4=9.7 Ohm
 * 0x5=6.9 Ohm
 * 0x6=4.4 Ohm
 * 0x7=3.3 Ohm
 * 0x8=2.4 Ohm
 * 0x9=1.71 Ohm(default)
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_PCONFIG_MASK    (0x0000000fUL) /* <0:3> R:RW:9: */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_PCONFIG_POS     (0UL)


/*
 * HSDR NMOS/Pull-down driver Strength Configuration (Ohm):
 * 0x0=29.2 Ohm
 * 0x1=20.4 Ohm
 * 0x2=15.7 Ohm
 * 0x3=12.8 Ohm
 * 0x4=10.1 Ohm
 * 0x5=7.1 Ohm
 * 0x6=4.5 Ohm
 * 0x7=3.4 Ohm
 * 0x8=2.0 Ohm
 * 0x9=1.34 Ohm (default)
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_NCONFIG_MASK    (0x000000f0UL) /* <4:7> R:RW:9: */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_NCONFIG_POS     (4UL)


/*
 * Keep-off Enable
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_KEEPOFF_EN            (1UL << 8) /* <8:8> R:RW:1: */


/*
 * HSDR block power down signal
 * 0: Active Mode
 * 1: Power-Down Mode
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_PD              (1UL << 9) /* <9:9> R:RW:1: */


/*
 * VBG by R  block enable signal (at powerup it is disabled as it is gated
 * by BB_GDRVO_GDRV_PD)
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_VBGBYR_EN             (1UL << 10) /* <10:10> R:RW:1: */


/*
 * Test Mode bits for VBG by R block:
 * t_vbgbyr[0]=1 :half output current
 * t_vbgbyr[1]=1 :Double output current
 * t_vbgbyr[3:2] :Spare
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_T_VBGBYR_MASK         (0x00007800UL) /* <11:14> R:RW:0: */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_T_VBGBYR_POS          (11UL)


/*
 * VBST Comparator Enable
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_VBST_COMP_EN          (1UL << 15) /* <15:15> R:RW:0: */


/*
 * LSDR output Falling slew control configuration bits:
 * 0x0=16.1nS
 * 0x1=17.2nS
 * 0x2=18.9nS(default)
 * 0x3=23.8nS
 * 0x4=16.1nS
 * 0x5=17.2nS
 * 0x6=18.8nS
 * 0x7=23.7nS
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_LSDR2_NSLEW_MASK      (0x00070000UL) /* <16:18> R:RW:2: */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_LSDR2_NSLEW_POS       (16UL)


/*
 * adft configuration bits for GDRVO_TOP:
 *
 * adft_ctrl<1:0>   adft<0>
 * 2'b00=Z
 * 2'b01=reserved
 * 2'b10=vcpout of VBST CPCTRL
 * 2'b11=ibias_2p4
 *
 * adft_ctrl<3:2>   adft<1>
 * 2'b00=Z
 * 2'b01=reserved
 * 2'b10=del_nbias1_stg2
 * 2'b11=ib2p4u_del
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_ADFT_CTRL_MASK        (0x00780000UL) /* <19:22> R:RW:0: */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_ADFT_CTRL_POS         (19UL)


/*
 * LSDR NMOS/Pull-down driver Strength Configuration (Ohm):
 * 0x0=26.9 Ohm
 * 0x1=20.3 Ohm
 * 0x2=16.3 Ohm
 * 0x3=11.8 Ohm
 * 0x4=9.3 Ohm
 * 0x5=6.6 Ohm
 * 0x6=4.4 Ohm
 * 0x7=3.1 Ohm
 * 0x8=1.7 Ohm
 * 0x9=1.12 Ohm (default)
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_LSDR2_NCONFIG_MASK    (0x07800000UL) /* <23:26> R:RW:9: */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_LSDR2_NCONFIG_POS     (23UL)


/*
 * HSRCP block power down signal
 * 0: Active Mode
 * 1: Power-Down Mode
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSRCP_PD              (1UL << 27) /* <27:27> R:RW:1: */


/*
 * HSDR output Falling slew control configuration bits:
 * 0x0=13.48nS
 * 0x1=14.95nS
 * 0x2=17.34nS (default)
 * 0x3=24.47nS
 * 0x4=13.33nS
 * 0x5=14.74nS
 * 0x6=17.07nS
 * 0x7=23.44nS
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_NSLEW_MASK      (0x70000000UL) /* <28:30> R:RW:2: */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_NSLEW_POS       (28UL)


/*
 * Select LSDR enable signal from RTL:
 * 0: LSDR enabled by PWM
 * 1: LSDR enabled by RTL
 */
#define PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_SEL_LSDR2_TEST        (1UL << 31) /* <31:31> R:RW:0: */


/*
 * S8PDBB GDRVO Control Register 1 (NA in PMG1S3)
 */
#define PDSS_BB_GDRVO_1_CTRL_ADDRESS                        (0x400a213cUL)
#define PDSS_BB_GDRVO_1_CTRL                                (*(volatile uint32_t *)(0x400a213cUL))
#define PDSS_BB_GDRVO_1_CTRL_DEFAULT                        (0x00012942UL)

/*
 * Select HSDR enable signal from RTL:
 * 0: HSDR enabled by PWM
 * 1: HSDR enabled by RTL
 */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_SEL_HSDR2_TEST        (1UL << 0) /* <0:0> R:RW:0: */


/*
 * LSDR block power down signal
 * 0: Active Mode
 * 1: Power-Down Mode
 */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_LSDR2_PD              (1UL << 1) /* <1:1> R:RW:1: */


/*
 * adft master enable
 */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_ADFT_EN               (1UL << 2) /* <2:2> R:RW:0: */


/*
 * HSRCP output hysteresis enable signal
 */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_HSRCP_HYST_EN         (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_ISO_N                 (1UL << 5) /* <5:5> R:RW:0: */


/*
 * GDRVO master power down signal
 * 0: Active Mode
 * 1: Power-Down Mode
 */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_GDRV_PD               (1UL << 6) /* <6:6> R:RW:1: */


/*
 * LSDR output Rising slew control configuration bits:
 * 0x0=15.87nS
 * 0x1=16.84nS
 * 0x2=18.34nS(default)
 * 0x3=22.06nS
 * 0x4=15.89nS
 * 0x5=16.79nS
 * 0x6=18.34nS
 * 0x7=21.96nS
 */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_LSDR2_PSLEW_MASK      (0x00000380UL) /* <7:9> R:RW:2: */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_LSDR2_PSLEW_POS       (7UL)


/*
 * HSDR output Rising slew control configuration bits:
 * 0x0=16.22nS
 * 0x1=17.31nS
 * 0x2=19.19nS(default)
 * 0x3=24.43nS
 * 0x4=16.12nS
 * 0x5=17.15nS
 * 0x6=18.82nS
 * 0x7=23.22nS
 */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_HSDR2_PSLEW_MASK      (0x00001c00UL) /* <10:12> R:RW:2: */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_HSDR2_PSLEW_POS       (10UL)


/*
 * LSDR PMOS/Pull-up driver Strength Configuration (Ohm):
 * 0x0=26.7 Ohm
 * 0x1=17.9 Ohm
 * 0x2=13.4 Ohm
 * 0x3=10.8 Ohm
 * 0x4=8.2 Ohm
 * 0x5=5.9 Ohm
 * 0x6=4.2 Ohm
 * 0x7=2.9 Ohm
 * 0x8=2.2 Ohm
 * 0x9=1.69 Ohm (default)
 */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_LSDR2_PCONFIG_MASK    (0x0001e000UL) /* <13:16> R:RW:9: */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_LSDR2_PCONFIG_POS     (13UL)


/*
 * Test Mode bits for HSCP
 * t_hsrcp[0]=Bypass 10nS glitch filter of HSRCP out
 * t_hsrcp[1]=0: Hysteresis of 5mV(default), 1: Hysteresis of 10mV
 * t_hsrcp[2]=Disable HSRCP trim
 * t_hsrcp[3]=Enable slow mode
 * t_hsrcp[4]=Enable fast mode
 * t_hsrcp[5]=Disable HSRCP out good detection logic
 * t_hsrcp[6]=Double the trim range
 * t_hsrcp[7]=spare
 */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_T_HSRCP_MASK          (0x01fe0000UL) /* <17:24> R:RW:0: */
#define PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_T_HSRCP_POS           (17UL)


/*
 * S8PDBB GDRVO Control Register 2 (NA in PMG1S3)
 */
#define PDSS_BB_GDRVO_2_CTRL_ADDRESS                        (0x400a2140UL)
#define PDSS_BB_GDRVO_2_CTRL                                (*(volatile uint32_t *)(0x400a2140UL))
#define PDSS_BB_GDRVO_2_CTRL_DEFAULT                        (0x75740000UL)

/*
 * Test mode bits for HSDR:
 * t_hsdr[1:0]=Set vtrip threshold of HSDR_SEN of High-to-Low detection
 * 2'b00=1V
 * 2'b01=1.2V
 * 2'b10=1.6V
 * 2'b11=1.8V
 * t_hsdr[3:2]=Set vtrip threshold of HSDR_SEN of Low-to-High detection
 * t_hsdr[4]=Disable the break-before-make gating between predrv_ngate and
 * predrv_gate
 * t_hsdr[5]=Make HSDR out HiZ
 * t_hsdr[6]=Disable HSDR2 nslew control
 * t_hsdr[7]=Disable HSDR2 pslew control
 * t_hsdr[9:8]=Spare
 * t_hsdr[10]=Disable NAND-SR Latch in HSDR sensing
 * t_hsdr[11]= Increase pulse width to 40u in fast LS
 * t_hsdr[12]=Disable break-before-make gating between HSDR & LSDR
 * t_hsdr[13]=Enable SW-going-High detection based HSDR Sensing
 * t_hsdr[14]=Disable SW-going-High detection based dynamic biasing in VDDD-to-VBST
 * level shifter
 * t_hsdr[15]=Double LS bias current (4.8uA to 9.8uA per LS)
 */
#define PDSS_BB_GDRVO_2_CTRL_BB_GDRVO_T_HSDR2_MASK          (0x0000ffffUL) /* <0:15> R:RW:0: */
#define PDSS_BB_GDRVO_2_CTRL_BB_GDRVO_T_HSDR2_POS           (0UL)


/*
 * HSRCP output Leading Edge Blanking (LEB) Time configuration bits:
 *
 * (default =318ns in layout extracted sims)
 *
 * Total delay= Sum of two delay cells. <31:24> = one delay cell. <23:16>
 * another delay cell.
 * Each delay cell has config option of 8 bits :
 * <7> : not used
 * <6:4> : Defining step size; 000 - 5ns, 001 - 10ns, 010 - 15ns ... 111
 * - 40ns
 * <3> : not used
 * <2:0> : multipler of the step defined by <6:4>
 *  Few examples for delay configurations :
 * Example1:  We need 10ns. 10ns can be set by three ways:
 * 1. cell1 delay=0 + cell2 delay=10n :      Settings of 16bits=x0002 or
 * x0011
 * 2. cell1 delay=10ns + cell2 delay=0 :     Settings of 16bits=x0200 or
 * x1100
 * 3. cell1 delay=5ns + cell2 delay=5ns :      Settings of 16bits=x0101
 *
 * Example2:  We need 300ns. 300ns can be set by two ways:
 * 1. cell1 delay=280n + cell2 delay=20n :     Settings of 16bits=x7704
 * 2. cell1 delay=20ns + cell2 delay=280ns :      Settings of 16bits=x0477
 */
#define PDSS_BB_GDRVO_2_CTRL_BB_GDRVO_HSRCP_LEB_TIME_CONFIG_MASK    (0xffff0000UL) /* <16:31> R:RW:30068: */
#define PDSS_BB_GDRVO_2_CTRL_BB_GDRVO_HSRCP_LEB_TIME_CONFIG_POS    (16UL)


/*
 * S8PDBB GDRVO Control Register 3 (NA in PMG1S3)
 */
#define PDSS_BB_GDRVO_3_CTRL_ADDRESS                        (0x400a2144UL)
#define PDSS_BB_GDRVO_3_CTRL                                (*(volatile uint32_t *)(0x400a2144UL))
#define PDSS_BB_GDRVO_3_CTRL_DEFAULT                        (0x00000000UL)

/*
 * LSDR2 Programmable dead time configuration bits:
 * <15:8> =spare, <7:0>= delay cell.
 * The delay cell has config option of 8 bits :
 * <7> : not used
 * <6:4> : Defining step size; 000 - 5ns, 001 - 10ns, 011 - 20ns, 111 - 40ns
 * <3> : not used
 * <2:0> : multipler of the step defined by <6:4>
 *  Few examples for delay configurations :
 * Example1:  We need 10ns. 10ns can be set by two ways:
 * 1. Settings of 16bits=x0002
 * 2. Settings of 16bits=x0011
 *
 * Example2:  We need 30ns. 30ns can be set by two ways:
 * 1. Settings of 16bits=x0006
 * 2. Settings of 16bits=x0013
 */
#define PDSS_BB_GDRVO_3_CTRL_BB_GDRVO_LSDR2_DEAD_TIME_CONFIG_MASK    (0x0000ffffUL) /* <0:15> R:RW:0: */
#define PDSS_BB_GDRVO_3_CTRL_BB_GDRVO_LSDR2_DEAD_TIME_CONFIG_POS    (0UL)


/*
 * HSDR2 Programmable dead time configuration bits:
 * <31:24> =spare, <23:16>= delay cell.
 * The delay cell has config option of 8 bits :
 * <7> : not used
 * <6:4> : Defining step size; 000 - 5ns, 001 - 10ns, 011 - 20ns, 111 - 40ns
 * <3> : not used
 * <2:0> : multipler of the step defined by <6:4>
 *  Few examples for delay configurations :
 * Example1:  We need 10ns. 10ns can be set by two ways:
 * 1. Settings of 16bits=x0002
 * 2. Settings of 16bits=x0011
 *
 * Example2:  We need 30ns. 30ns can be set by two ways:
 * 1. Settings of 16bits=x0006
 * 2. Settings of 16bits=x0013
 */
#define PDSS_BB_GDRVO_3_CTRL_BB_GDRVO_HSDR2_DEAD_TIME_CONFIG_MASK    (0xffff0000UL) /* <16:31> R:RW:0: */
#define PDSS_BB_GDRVO_3_CTRL_BB_GDRVO_HSDR2_DEAD_TIME_CONFIG_POS    (16UL)


/*
 * S8PDBB GDRVO Control Register 4 (NA in PMG1S3)
 */
#define PDSS_BB_GDRVO_4_CTRL_ADDRESS                        (0x400a2148UL)
#define PDSS_BB_GDRVO_4_CTRL                                (*(volatile uint32_t *)(0x400a2148UL))
#define PDSS_BB_GDRVO_4_CTRL_DEFAULT                        (0x00100000UL)

/*
 * Test mode bits for LSDR:
 * t_lsdr[1:0]=Set vtrip threshold of LSDR_SEN of High-to-Low detection
 * 2'b00=1V
 * 2'b01=1.2V
 * 2'b10=1.6V
 * 2'b11=1.8V
 * t_lsdr[3:2]=Set vtrip threshold of LSDR_SEN of Low-to-High detection
 * t_lsdr[4]=Disable the break-before-make gating between predrv_ngate and
 * predrv_gate
 * t_lsdr[5]=Make LSDR out HiZ
 * t_lsdr[6]=Disable LSDR2 nslew control
 * t_lsdr[7]=Disable LSDR2 pslew control
 * t_lsdr[11:8]=Spare
 * t_lsdr[12]=Disable break-before-make gating between HSDR & LSDR
 * t_lsdr[15:13]=Spare
 */
#define PDSS_BB_GDRVO_4_CTRL_BB_GDRVO_T_LSDR2_MASK          (0x0000ffffUL) /* <0:15> R:RW:0: */
#define PDSS_BB_GDRVO_4_CTRL_BB_GDRVO_T_LSDR2_POS           (0UL)


/*
 * Test Mode Bits for GDRVO_TOP:
 * t_gdrvo[2:0]: Config Delay Bias current settings
 * 3'b000=6uA
 * 3'b001=7.2uA
 * 3'b010=8.4uA
 * 3'b011=9.6uA
 * 3'b100=2.4uA
 * 3'b101=3.6uA
 * 3'b110=4.8uA
 * 3'b111=6uA
 * t_gdrvo[3]=Disable self-biasing scheme in config delay
 * t_gdrvo[4]=Bypass HSRCP internal Latch and take hsrcp_in signal from RTL
 * to turn-off HSDR in DCM mode((default=1)
 * t_gdrvo[5]=Disable external reset of HSRCP latch
 * t_gdrvo[6]=Bypass LSDR config dead time
 * t_gdrvo[7]=Bypass HSDR config dead time
 * t_gdrvo[9:8]=VBST Charge Pump Controller (VBST CPCTRL) Charging current
 * config:
 * 2'b00=1.84mA(default)
 * 2'b01=2.46mA
 * 2'b10=0.61mA
 * 2'b11=1.23mA
 * t_gdrvo[11:0]=VBST Comparator hysteresis config:
 * 2'b00=300mV(default)
 * 2'b01=150mV
 * 2'b10=600mV
 * 2'b11=450mV
 * t_gdrvo[12]=Disable analog VBST refresh scheme
 * t_gdrvo[13]=Turn-off VBST Comparator hysteresis
 * t_gdrvo[14]=Enable VBST Charge Pump Controller adft output at SORT
 * t_gdrvo[15]=Enable HSRCP out through DDFT at SORT
 */
#define PDSS_BB_GDRVO_4_CTRL_BB_GDRVO_T_GDRVO_MASK          (0xffff0000UL) /* <16:31> R:RW:16: */
#define PDSS_BB_GDRVO_4_CTRL_BB_GDRVO_T_GDRVO_POS           (16UL)


/*
 * S8PDBB GDRVI Control Register 0 (NA in PMG1S3)
 */
#define PDSS_BB_GDRVI_0_CTRL_ADDRESS                        (0x400a214cUL)
#define PDSS_BB_GDRVI_0_CTRL                                (*(volatile uint32_t *)(0x400a214cUL))
#define PDSS_BB_GDRVI_0_CTRL_DEFAULT                        (0x00200109UL)

/*
 * LSDR PMOS/Pull-up driver Strength Configuration (Ohm):
 * 0x0=26.7 Ohm
 * 0x1=17.9 Ohm
 * 0x2=13.4 Ohm
 * 0x3=10.8 Ohm
 * 0x4=8.2 Ohm
 * 0x5=5.9 Ohm
 * 0x6=4.2 Ohm
 * 0x7=2.9 Ohm
 * 0x8=2.2 Ohm
 * 0x9=1.69 Ohm (default)
 */
#define PDSS_BB_GDRVI_0_CTRL_BB_GDRVI_LSDR1_PCONFIG_MASK    (0x0000000fUL) /* <0:3> R:RW:9: */
#define PDSS_BB_GDRVI_0_CTRL_BB_GDRVI_LSDR1_PCONFIG_POS     (0UL)


/*
 * Test Mode Bits for GDRVI_TOP:
 * t_gdrvi[2:0]: Config Delay Bias current settings
 * 3'b000=6uA
 * 3'b001=7.2uA
 * 3'b010=8.4uA
 * 3'b011=9.6uA
 * 3'b100=2.4uA
 * 3'b101=3.6uA
 * 3'b110=4.8uA
 * 3'b111=6uA
 * t_gdrvi[3]=Disable self-biasing scheme in config delay
 * t_gdrvi[4]=Bypass LSZCD internal Latch and take lszcd_in signal from RTL
 * to turn-off LSDR in DCM mode(default=1)
 * t_gdrvi[5]=spare
 * t_gdrvi[6]=Bypass LSDR config dead time
 * t_gdrvi[7]=Bypass HSDR config dead time
 * t_gdrvi[9:8]=VBST Charge Pump Controller (VBST CPCTRL) Charging current
 * config:
 * 2'b00=1.84mA(default)
 * 2'b01=2.46mA
 * 2'b10=0.61mA
 * 2'b11=1.23mA
 * t_gdrvi[11:0]=VBST Comparator hysteresis config:
 * 2'b00=300mV(default)
 * 2'b01=150mV
 * 2'b10=600mV
 * 2'b11=450mV
 * t_gdrvi[12]=Disable analog VBST refresh scheme
 * t_gdrvi[13]=Turn-off VBST Comparator hysteresis
 * t_gdrvi[14]=Enable VBST Charge Pump Controller adft output at SORT
 * t_gdrvi[15]=Enable LSZCD out through DDFT at SORT
 */
#define PDSS_BB_GDRVI_0_CTRL_BB_GDRVI_T_GDRVI_MASK          (0x000ffff0UL) /* <4:19> R:RW:16: */
#define PDSS_BB_GDRVI_0_CTRL_BB_GDRVI_T_GDRVI_POS           (4UL)


/*
 * LSDR output Falling slew control configuration bits:
 * 0x0=16.1nS
 * 0x1=17.2nS
 * 0x2=18.9nS(default)
 * 0x3=23.8nS
 * 0x4=16.1nS
 * 0x5=17.2nS
 * 0x6=18.8nS
 * 0x7=23.7nS
 */
#define PDSS_BB_GDRVI_0_CTRL_BB_GDRVI_LSDR1_NSLEW_MASK      (0x00700000UL) /* <20:22> R:RW:2: */
#define PDSS_BB_GDRVI_0_CTRL_BB_GDRVI_LSDR1_NSLEW_POS       (20UL)


/*
 * Test Mode bits for LSZCD:
 * t_lszcd[0]=Bypass 10nS glitch filter of LSZCD out
 * t_lszcd[1]=0: Hysteresis of 5mV(default), 1: Hysteresis of 10mV
 * t_lszcd[2]=Disable LSZCD trim
 * t_lszcd[3]=Enable slow mode
 * t_lszcd[4]=Enable fast mode
 * t_lszcd[5]=Spare
 * t_lszcd[6]= Double the trim Range
 * t_lszcd[7]=0: diode path enabled, 1: diode path disabled
 */
#define PDSS_BB_GDRVI_0_CTRL_BB_GDRVI_T_LSZCD_MASK          (0x7f800000UL) /* <23:30> R:RW:0: */
#define PDSS_BB_GDRVI_0_CTRL_BB_GDRVI_T_LSZCD_POS           (23UL)


/*
 * S8PDBB GDRVI Control Register 1 (NA in PMG1S3)
 */
#define PDSS_BB_GDRVI_1_CTRL_ADDRESS                        (0x400a2150UL)
#define PDSS_BB_GDRVI_1_CTRL                                (*(volatile uint32_t *)(0x400a2150UL))
#define PDSS_BB_GDRVI_1_CTRL_DEFAULT                        (0x97049039UL)

/*
 * LSDR NMOS/Pull-down driver Strength Configuration (Ohm):
 * 0x0=26.9 Ohm
 * 0x1=20.3 Ohm
 * 0x2=16.3 Ohm
 * 0x3=11.8 Ohm
 * 0x4=9.3 Ohm
 * 0x5=6.6 Ohm
 * 0x6=4.4 Ohm
 * 0x7=3.1 Ohm
 * 0x8=1.7 Ohm
 * 0x9=1.12 Ohm (default)
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSDR1_NCONFIG_MASK    (0x0000000fUL) /* <0:3> R:RW:9: */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSDR1_NCONFIG_POS     (0UL)


/*
 * Keep-off Enable
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_KEEPOFF_EN            (1UL << 4) /* <4:4> R:RW:1: */


/*
 * VBG by R  block enable signal (at powerup it is disabled as it is gated
 * by BB_GDRVO_GDRV_PD)
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_VBGBYR_EN             (1UL << 5) /* <5:5> R:RW:1: */


/*
 * Test Mode bits for VBG by R block:
 * t_vbgbyr[0]=1 :half output current
 * t_vbgbyr[1]=1 :Double output current
 * t_vbgbyr[3:2] :Spare
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_T_VBGBYR_MASK         (0x000003c0UL) /* <6:9> R:RW:0: */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_T_VBGBYR_POS          (6UL)


/*
 * VBST Comparator Enable
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_VBST_COMP_EN          (1UL << 10) /* <10:10> R:RW:0: */


/*
 * HSDR output Rising slew control configuration bits:
 * 0x0=16.22nS
 * 0x1=17.31nS
 * 0x2=19.19nS(default)
 * 0x3=24.43nS
 * 0x4=16.12nS
 * 0x5=17.15nS
 * 0x6=18.82nS
 * 0x7=23.22nS
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_PSLEW_MASK      (0x00003800UL) /* <11:13> R:RW:2: */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_PSLEW_POS       (11UL)


/*
 * LSZCD output hysteresis enable signal
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSZCD_HYST_EN         (1UL << 14) /* <14:14> R:RW:0: */


/*
 * HSDR PMOS/Pull-up driver Strength Configuration (Ohm):
 * 0x0=30.0 Ohm
 * 0x1=20.1 Ohm
 * 0x2=15.5 Ohm
 * 0x3=12.2 Ohm
 * 0x4=9.7 Ohm
 * 0x5=6.9 Ohm
 * 0x6=4.4 Ohm
 * 0x7=3.3 Ohm
 * 0x8=2.4 Ohm
 * 0x9=1.71 Ohm(default)
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_PCONFIG_MASK    (0x00078000UL) /* <15:18> R:RW:9: */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_PCONFIG_POS     (15UL)


/*
 * adft configuration bits for GDRVI_TOP:
 *
 * adft_ctrl<1:0>   adft<0>
 * 2'b00=Z
 * 2'b01=lszcd_inp_int
 * 2'b10=vcpout of VBST CPCTRL
 * 2'b11=ibias_2p4
 *
 * adft_ctrl<3:2>   adft<1>
 * 2'b00=Z
 * 2'b01=lszcd_inn_int
 * 2'b10=del_nbias1_stg2
 * 2'b11=ib2p4u_del
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_ADFT_CTRL_MASK        (0x00780000UL) /* <19:22> R:RW:0: */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_ADFT_CTRL_POS         (19UL)


/*
 * LSZCD power down signal
 * 0: Active Mode
 * 1: Power-Down Mode
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSZCD_PD              (1UL << 24) /* <24:24> R:RW:1: */


/*
 * HSDR block power down signal
 * 0: Active Mode
 * 1: Power-Down Mode
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_PD              (1UL << 25) /* <25:25> R:RW:1: */


/*
 * LSDR block power down signal
 * 0: Active Mode
 * 1: Power-Down Mode
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSDR1_PD              (1UL << 26) /* <26:26> R:RW:1: */


/*
 * Select LSDR enable signal from RTL:
 * 0: LSDR enabled by PWM
 * 1: LSDR enabled by RTL
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_SEL_LSDR1_TEST        (1UL << 27) /* <27:27> R:RW:0: */


/*
 * HSDR NMOS/Pull-down driver Strength Configuration (Ohm):
 * 0x0=29.2 Ohm
 * 0x1=20.4 Ohm
 * 0x2=15.7 Ohm
 * 0x3=12.8 Ohm
 * 0x4=10.1 Ohm
 * 0x5=7.1 Ohm
 * 0x6=4.5 Ohm
 * 0x7=3.4 Ohm
 * 0x8=2.0 Ohm
 * 0x9=1.34 Ohm (default)
 */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_NCONFIG_MASK    (0xf0000000UL) /* <28:31> R:RW:9: */
#define PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_NCONFIG_POS     (28UL)


/*
 * S8PDBB GDRVI Control Register 2 (NA in PMG1S3)
 */
#define PDSS_BB_GDRVI_2_CTRL_ADDRESS                        (0x400a2154UL)
#define PDSS_BB_GDRVI_2_CTRL                                (*(volatile uint32_t *)(0x400a2154UL))
#define PDSS_BB_GDRVI_2_CTRL_DEFAULT                        (0x0001d942UL)

/*
 * HSDR output Falling slew control configuration bits:
 * 0x0=13.48nS
 * 0x1=14.95nS
 * 0x2=17.34nS (default)
 * 0x3=24.47nS
 * 0x4=13.33nS
 * 0x5=14.74nS
 * 0x6=17.07nS
 * 0x7=23.44nS
 */
#define PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_HSDR1_NSLEW_MASK      (0x00000007UL) /* <0:2> R:RW:2: */
#define PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_HSDR1_NSLEW_POS       (0UL)


/*
 * adft master enable
 */
#define PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_ADFT_EN               (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_ISO_N                 (1UL << 5) /* <5:5> R:RW:0: */


/*
 * GDRVI master power down signal
 * 0: Active Mode
 * 1: Power-Down Mode
 */
#define PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_GDRV_PD               (1UL << 6) /* <6:6> R:RW:1: */


/*
 * LSDR output Rising slew control configuration bits:
 * 0x0=15.87nS
 * 0x1=16.84nS
 * 0x2=18.34nS(default)
 * 0x3=22.06nS
 * 0x4=15.89nS
 * 0x5=16.79nS
 * 0x6=18.34nS
 * 0x7=21.96nS
 */
#define PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_LSDR1_PSLEW_MASK      (0x00000380UL) /* <7:9> R:RW:2: */
#define PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_LSDR1_PSLEW_POS       (7UL)


/*
 * LSZCD output Leading Edge Blanking (LEB) Time configuration bits:
 *
 * (default= 214ns in Layout extracted sims)
 *
 * Total delay= Sum of two delay cells. <25:18> = one delay cell. <17:10>
 * another delay cell.
 * Each delay cell has config option of 8 bits :
 * <7> : not used
 * <6:4> : Defining step size; 000 - 5ns, 001 - 10ns, 010 - 15ns ... 111
 * - 40ns
 * <3> : not used
 * <2:0> : multipler of the step defined by <6:4>
 *  Few examples for delay configurations :
 * Example1:  We need 10ns. 10ns can be set by three ways:
 * 1. cell1 delay=0 + cell2 delay=10n :      Settings of 16bits=x0002 or
 * x0011
 * 2. cell1 delay=10ns + cell2 delay=0 :     Settings of 16bits=x0200 or
 * x1100
 * 3. cell1 delay=5ns + cell2 delay=5ns :      Settings of 16bits=x0101
 *
 * Example2:  We need 300ns. 300ns can be set by two ways:
 * 1. cell1 delay=280n + cell2 delay=20n :     Settings of 16bits=x7704
 * 2. cell1 delay=20ns + cell2 delay=280ns :      Settings of 16bits=x0477
 */
#define PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_LSZCD_LEB_TIME_CONFIG_MASK    (0x03fffc00UL) /* <10:25> R:RW:118: */
#define PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_LSZCD_LEB_TIME_CONFIG_POS    (10UL)


/*
 * GDRVI Select HSDR1 test mode
 */
#define PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_SEL_HSDR1_TEST        (1UL << 26) /* <26:26> R:RW:0: */


/*
 * S8PDBB GDRVI Control Register 3 (NA in PMG1S3)
 */
#define PDSS_BB_GDRVI_3_CTRL_ADDRESS                        (0x400a2158UL)
#define PDSS_BB_GDRVI_3_CTRL                                (*(volatile uint32_t *)(0x400a2158UL))
#define PDSS_BB_GDRVI_3_CTRL_DEFAULT                        (0x00000000UL)

/*
 * Test mode bits for LSDR:
 * t_lsdr[1:0]=Set vtrip threshold of LSDR_SEN of High-to-Low detection
 * 2'b00=1V
 * 2'b01=1.2V
 * 2'b10=1.6V
 * 2'b11=1.8V
 * t_lsdr[3:2]=Set vtrip threshold of LSDR_SEN of Low-to-High detection
 * t_lsdr[4]=Disable the break-before-make gating between predrv_ngate and
 * predrv_gate
 * t_lsdr[5]=Make LSDR out HiZ
 * t_lsdr[6]=Disable LSDR1 nslew control
 * t_lsdr[7]=Disable LSDR1 pslew control
 * t_lsdr[11:8]=Spare
 * t_lsdr[12]=Disable break-before-make gating between HSDR & LSDR
 * t_lsdr[15:13]=Spare
 */
#define PDSS_BB_GDRVI_3_CTRL_BB_GDRVI_T_LSDR1_MASK          (0x0000ffffUL) /* <0:15> R:RW:0: */
#define PDSS_BB_GDRVI_3_CTRL_BB_GDRVI_T_LSDR1_POS           (0UL)


/*
 * HSDR1 Programmable dead time configuration bits:
 * <31:24> =spare, <23:16>= delay cell.
 * The delay cell has config option of 8 bits :
 * <7> : not used
 * <6:4> : Defining step size; 000 - 5ns, 001 - 10ns, 011 - 20ns, 111 - 40ns
 * <3> : not used
 * <2:0> : multipler of the step defined by <6:4>
 *  Few examples for delay configurations :
 * Example1:  We need 10ns. 10ns can be set by two ways:
 * 1. Settings of 16bits=x0002
 * 2. Settings of 16bits=x0011
 *
 * Example2:  We need 30ns. 30ns can be set by two ways:
 * 1. Settings of 16bits=x0006
 * 2. Settings of 16bits=x0013
 */
#define PDSS_BB_GDRVI_3_CTRL_BB_GDRVI_HSDR1_DEAD_TIME_CONFIG_MASK    (0xffff0000UL) /* <16:31> R:RW:0: */
#define PDSS_BB_GDRVI_3_CTRL_BB_GDRVI_HSDR1_DEAD_TIME_CONFIG_POS    (16UL)


/*
 * S8PDBB GDRVI Control Register 4 (NA in PMG1S3)
 */
#define PDSS_BB_GDRVI_4_CTRL_ADDRESS                        (0x400a215cUL)
#define PDSS_BB_GDRVI_4_CTRL                                (*(volatile uint32_t *)(0x400a215cUL))
#define PDSS_BB_GDRVI_4_CTRL_DEFAULT                        (0x00000000UL)

/*
 * Test mode bits for HSDR:
 * t_hsdr[1:0]=Set vtrip threshold of HSDR_SEN of High-to-Low detection
 * 2'b00=1V
 * 2'b01=1.2V
 * 2'b10=1.6V
 * 2'b11=1.8V
 * t_hsdr[3:2]=Set vtrip threshold of HSDR_SEN of Low-to-High detection
 * t_hsdr[4]=Disable the break-before-make gating between predrv_ngate and
 * predrv_gate
 * t_hsdr[5]=Make HSDR out HiZ
 * t_hsdr[6]=Disable HSDR1 nslew control
 * t_hsdr[7]=Disable HSDR1 pslew control
 * t_hsdr[9:8]=Spare
 * t_hsdr[10]=Disable NAND-SR Latch in HSDR sensing
 * t_hsdr[11]= Increase pulse width to 40u in fast LS
 * t_hsdr[12]=Disable break-before-make gating between HSDR & LSDR
 * t_hsdr[13]=Enable SW-going-High detection based HSDR Sensing
 * t_hsdr[14]=Disable SW-going-High detection based dynamic biasing in VDDD-to-VBST
 * level shifter
 * t_hsdr[15]=Double LS bias current (4.8uA to 9.8uA per LS)
 */
#define PDSS_BB_GDRVI_4_CTRL_BB_GDRVI_T_HSDR1_MASK          (0x0000ffffUL) /* <0:15> R:RW:0: */
#define PDSS_BB_GDRVI_4_CTRL_BB_GDRVI_T_HSDR1_POS           (0UL)


/*
 * LSDR1 Programmable dead time configuration bits:
 * <31:24> =spare, <23:16>= delay cell.
 * The delay cell has config option of 8 bits :
 * <7> : not used
 * <6:4> : Defining step size; 000 - 5ns, 001 - 10ns, 011 - 20ns, 111 - 40ns
 * <3> : not used
 * <2:0> : multipler of the step defined by <6:4>
 *  Few examples for delay configurations :
 * Example1:  We need 10ns. 10ns can be set by two ways:
 * 1. Settings of 16bits=x0002
 * 2. Settings of 16bits=x0011
 *
 * Example2:  We need 30ns. 30ns can be set by two ways:
 * 1. Settings of 16bits=x0006
 * 2. Settings of 16bits=x0013
 */
#define PDSS_BB_GDRVI_4_CTRL_BB_GDRVI_LSDR1_DEAD_TIME_CONFIG_MASK    (0xffff0000UL) /* <16:31> R:RW:0: */
#define PDSS_BB_GDRVI_4_CTRL_BB_GDRVI_LSDR1_DEAD_TIME_CONFIG_POS    (16UL)


/*
 * S8PDBB FW & External Override Control Register (NA in PMG1S3)
 */
#define PDSS_BB_CTRL_OVRD_ADDRESS                           (0x400a2160UL)
#define PDSS_BB_CTRL_OVRD                                   (*(volatile uint32_t *)(0x400a2160UL))
#define PDSS_BB_CTRL_OVRD_DEFAULT                           (0x00000000UL)

/*
 * SCOMP_OUT_EN_LV Override Control signal
 * 0: Logic uses functional signal
 * 1: Signal overridden by FW programmable value or by external input based
 * on OVRD_SEL bit
 */
#define PDSS_BB_CTRL_OVRD_SCOMP_OUT_EN_LV_OVRD_CTRL         (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Select bit for SCOMP_OUT_EN_LV override signal.
 * 0 - Logic uses FW programmable OVRD_VAL
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_BB_CTRL_OVRD_SCOMP_OUT_EN_LV_OVRD_SEL          (1UL << 1) /* <1:1> R:RW:0: */


/*
 * FW programmable override value for scomp_out_en_lv
 */
#define PDSS_BB_CTRL_OVRD_SCOMP_OUT_EN_LV_OVRD_VAL          (1UL << 2) /* <2:2> R:RW:0: */


/*
 * SCAP_RST_LV Override Control signal
 * 0 - Logic uses functional signal
 * 1 - Signal overridden by FW programmable value or by external input based
 * on OVRD_SEL bit
 * NOTE: This override control bit must be set for 40CSA Autocal
 */
#define PDSS_BB_CTRL_OVRD_SCAP_RST_OVRD_CTRL                (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Select bit for SCAP_RST override signal.
 * 0 - Logic uses FW programmable OVRD_VAL
 * 1 - Logic uses external GPIO signal.
 * NOTE: This select bit must select FW Programmable override for 40CSA Autocal
 */
#define PDSS_BB_CTRL_OVRD_SCAP_RST_OVRD_SEL                 (1UL << 4) /* <4:4> R:RW:0: */


/*
 * The SCAP_RST_LV Override value driven to the 40csa module.
 * NOTE: This bit must be controlled for 40CSA Autocal
 */
#define PDSS_BB_CTRL_OVRD_SCAP_RST_OVRD_VAL                 (1UL << 5) /* <5:5> R:RW:0: */


/*
 * RST_SW1_RTL_LV Override signal
 * 0 - Logic uses functional signal
 * 1 - Signal overridden by FW programmable value or by external input based
 * on OVRD_SEL bit
 */
#define PDSS_BB_CTRL_OVRD_RST_SW1_OVRD_CTRL                 (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Select bit for RST_SW1 Control override signal.
 * 0 - Logic uses FW programmable OVRD_VAL
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_BB_CTRL_OVRD_RST_SW1_OVRD_SEL                  (1UL << 7) /* <7:7> R:RW:0: */


/*
 * The RST_SW1_RTL_LV Override value driven to the 40csa module
 */
#define PDSS_BB_CTRL_OVRD_RST_SW1_OVRD_VAL                  (1UL << 8) /* <8:8> R:RW:0: */


/*
 * SET_BUCK_LV Override Control signal
 * 0 - Logic uses functional signal
 * 1 - Signal overridden by FW programmable value or by external input based
 * on OVRD_SEL bit
 */
#define PDSS_BB_CTRL_OVRD_SET_BUCK_OVRD_CTRL                (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Select bit for SET_BUCK override signal.
 * 0 - Logic uses FW programmable OVRD_VAL
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_BB_CTRL_OVRD_SET_BUCK_OVRD_SEL                 (1UL << 10) /* <10:10> R:RW:0: */


/*
 * The SET_BUCK_LV Override value driven to the 40csa module
 */
#define PDSS_BB_CTRL_OVRD_SET_BUCK_OVRD_VAL                 (1UL << 11) /* <11:11> R:RW:0: */


/*
 * SET_BOOST_LV Override Control signal
 * 0 - Logic uses functional signal
 * 1 - Signal overridden by FW programmable value or by external input based
 * on OVRD_SEL bit
 */
#define PDSS_BB_CTRL_OVRD_SET_BOOST_OVRD_CTRL               (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Select bit for SET_BOOST override signal.
 * 0 - Logic uses FW programmable OVRD_VAL
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_BB_CTRL_OVRD_SET_BOOST_OVRD_SEL                (1UL << 13) /* <13:13> R:RW:0: */


/*
 * The SET_BOOST_LV Override value driven to the 40csa module
 */
#define PDSS_BB_CTRL_OVRD_SET_BOOST_OVRD_VAL                (1UL << 14) /* <14:14> R:RW:0: */


/*
 * HSRCP_IN Override Control signal
 * 0 - Logic uses functional signal
 * 1 - Signal overridden by FW programmable value or by external input based
 * on OVRD_SEL bit
 */
#define PDSS_BB_CTRL_OVRD_HSRCP_OVRD_CTRL                   (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Select bit for HSRCP override signal.
 * 0 - Logic uses FW programmable OVRD_VAL
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_BB_CTRL_OVRD_HSRCP_OVRD_SEL                    (1UL << 16) /* <16:16> R:RW:0: */


/*
 * The HSRCP_IN Override value driven to the 40csa module
 */
#define PDSS_BB_CTRL_OVRD_HSRCP_OVRD_VAL                    (1UL << 17) /* <17:17> R:RW:0: */


/*
 * LSZCD_IN Override Control signal
 * 0 - Logic uses functional signal
 * 1 - Signal overridden by FW programmable value or by external input based
 * on OVRD_SEL bit
 */
#define PDSS_BB_CTRL_OVRD_LSZCD_OVRD_CTRL                   (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Select bit for LSZCD override signal.
 * 0 - Logic uses FW programmable OVRD_VAL
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_BB_CTRL_OVRD_LSZCD_OVRD_SEL                    (1UL << 19) /* <19:19> R:RW:0: */


/*
 * The LSZCD_IN Override value driven to the 40csa module
 */
#define PDSS_BB_CTRL_OVRD_LSZCD_OVRD_VAL                    (1UL << 20) /* <20:20> R:RW:0: */


/*
 * RESET_BUCK_LV Override Control signal
 * 0 - Logic uses functional signal
 * 1 - Logic uses FW programmable OVRD_VAL
 */
#define PDSS_BB_CTRL_OVRD_RESET_BUCK_OVRD_CTRL              (1UL << 21) /* <21:21> R:RW:0: */


/*
 * The RESET_BUCK_LV Override value driven to the 40csa module
 */
#define PDSS_BB_CTRL_OVRD_RESET_BUCK_OVRD_VAL               (1UL << 22) /* <22:22> R:RW:0: */


/*
 * RESET_BOOST_LV Override Control signal
 * 0 - Logic uses functional signal
 * 1 - Logic uses FW programmable OVRD_VAL
 */
#define PDSS_BB_CTRL_OVRD_RESET_BOOST_OVRD_CTRL             (1UL << 23) /* <23:23> R:RW:0: */


/*
 * The RESET_BOOST_LV Override value driven to the 40csa module
 */
#define PDSS_BB_CTRL_OVRD_RESET_BOOST_OVRD_VAL              (1UL << 24) /* <24:24> R:RW:0: */


/*
 * S8PDBB 40CSA Auto trim control register (NA in PMG1S3)
 */
#define PDSS_BB_40CSA_AUTOCAL_ADDRESS                       (0x400a2164UL)
#define PDSS_BB_40CSA_AUTOCAL                               (*(volatile uint32_t *)(0x400a2164UL))
#define PDSS_BB_40CSA_AUTOCAL_DEFAULT                       (0x00000000UL)

/*
 * Auto calibration Enable bit.
 * NOTE: Before enabling the Auto calibration, the BB_CTRL_OVRD.SCAP_RST_OVRD_CTRL
 * must be set to 1, BB_CTRL_OVRD.SCAP_RST_OVRD_SEL must be set to 0 and
 * the BB_CTRL_OVER.SCAP_RST_OVRD_VAL must be configured.
 */
#define PDSS_BB_40CSA_AUTOCAL_AUTOCAL_EN                    (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Auto calibration counter overflow settings.
 * 0: Overflow occurs when count reaches 512 and the counter is stopped &
 * AUTOCAL_OVERFLOW_STATUS is set
 * 1: Overflow occurs when count reaches 1023 and the counter is stopped
 * & AUTOCAL_OVERFLOW_STATUS is set
 */
#define PDSS_BB_40CSA_AUTOCAL_AUTOCAL_OVERFLOW_SEL          (1UL << 1) /* <1:1> R:RW:0: */


/*
 * 10 bit Auto Calibration counter value.
 */
#define PDSS_BB_40CSA_AUTOCAL_SCAP_RST_WIDTH_MASK           (0x000ffc00UL) /* <10:19> RW:R:0: */
#define PDSS_BB_40CSA_AUTOCAL_SCAP_RST_WIDTH_POS            (10UL)


/*
 * Status of synchronised ILIM_DIG_OUT in AUTOCAL module. FW can poll this
 * bit during the Auto calibration sequence
 */
#define PDSS_BB_40CSA_AUTOCAL_AUTOCAL_ILIM_DIG_OUT_SYNC     (1UL << 29) /* <29:29> RW:R:0: */


/*
 * Status of overflow condition based on overflow select
 */
#define PDSS_BB_40CSA_AUTOCAL_AUTOCAL_OVERFLOW_STATUS       (1UL << 30) /* <30:30> RW:R:0: */


/*
 * Status indicating COUNTER stopped either due to AUTOCAL_ILIM_DIG_OUT_SYNC
 * set or AUTOCAL_OVERFLOW_STATUS  set. FW can poll this bit during trimming.
 * Once set, the FW has to clear the bit to start the counter again.
 */
#define PDSS_BB_40CSA_AUTOCAL_AUTOCAL_CNTR_STOPPED          (1UL << 31) /* <31:31> RW1S:RW1C:0: */


/*
 * S8PDBB battery to grount control Register (NA in PMG1S3)
 */
#define PDSS_BB_BAT2GND_PROT_CNFG_ADDRESS                   (0x400a2168UL)
#define PDSS_BB_BAT2GND_PROT_CNFG                           (*(volatile uint32_t *)(0x400a2168UL))
#define PDSS_BB_BAT2GND_PROT_CNFG_DEFAULT                   (0x08000000UL)

/*
 * Battery to ground protection select
 * <2> : 1 floats GPIO (pulldn pin); 0 shorts pulldn pin to ground with 10K
 * resistor.
 * <1> : 1 shorts CSNIN to internal CSN; 0 shorts internal CSN to ground
 * with 10K resistor
 * <0> : 1 shorts CSPIN to internal CSP; 0 shorts internal CSP to ground
 * with 10K resistor
 */
#define PDSS_BB_BAT2GND_PROT_CNFG_BAT2GND_PROT_SEL_MASK     (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_BB_BAT2GND_PROT_CNFG_BAT2GND_PROT_SEL_POS      (0UL)


/*
 * Spare bits
 */
#define PDSS_BB_BAT2GND_PROT_CNFG_SPARE_0_MASK              (0x01c00000UL) /* <22:24> R:RW:0: */
#define PDSS_BB_BAT2GND_PROT_CNFG_SPARE_0_POS               (22UL)


/*
 * Spare bits
 */
#define PDSS_BB_BAT2GND_PROT_CNFG_SPARE_1                   (1UL << 27) /* <27:27> R:RW:1: */


/*
 * S8PDBB External input Control Register (NA in PMG1S3)
 */
#define PDSS_BB_GDRV_TEST_CTRL_ADDRESS                      (0x400a216cUL)
#define PDSS_BB_GDRV_TEST_CTRL                              (*(volatile uint32_t *)(0x400a216cUL))
#define PDSS_BB_GDRV_TEST_CTRL_DEFAULT                      (0x00000000UL)

/*
 * Control bit for GDRVI LS1 test signal. Selects what drives the en_lsdr1_test
 * input of the GDRVI
 * 0 - Logic uses Configuration bit
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_BB_GDRV_TEST_CTRL_BB_LS1_TEST_SEL              (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Config bit for GDRVI LS1 test. This value is driven to en_lsdr1_test input
 * of GDRVI when selected
 */
#define PDSS_BB_GDRV_TEST_CTRL_BB_LS1_TEST_CFG              (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Control bit for GDRVI HS1 test signal. Selects what drives the en_hsdr1_test
 * input of the GDRVI
 * 0 - Logic uses Configuration bit
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_BB_GDRV_TEST_CTRL_BB_HS1_TEST_SEL              (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Config bit for GDRVI HS1 test. This value is driven to en_hsdr1_test input
 * of GDRVI when selected
 */
#define PDSS_BB_GDRV_TEST_CTRL_BB_HS1_TEST_CFG              (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Control bit for GDRVO LS2 test signal. Selects what drives the en_lsdr2_test
 * input of the GDRVO
 * 0 - Logic uses Configuration bit
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_BB_GDRV_TEST_CTRL_BB_LS2_TEST_SEL              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Config bit for GDRVO LS2 test. This value is driven to en_lsdr2_test input
 * of GDRVO when selected
 */
#define PDSS_BB_GDRV_TEST_CTRL_BB_LS2_TEST_CFG              (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Control bit for GDRVO HS2 test signal. Selects what drives the en_hsdr2_test
 * input of the GDRVO
 * 0 - Logic uses Configuration bit
 * 1 - Logic uses external GPIO signal.
 */
#define PDSS_BB_GDRV_TEST_CTRL_BB_HS2_TEST_SEL              (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Config bit for GDRVO HS2 test. This value is driven to en_hsdr2_test input
 * of GDRVO when selected
 */
#define PDSS_BB_GDRV_TEST_CTRL_BB_HS2_TEST_CFG              (1UL << 7) /* <7:7> R:RW:0: */


/*
 * S8PDBB 40CSA Control Register 4 (NA in PMG1S3)
 */
#define PDSS_BB_40CSA_4_CTRL_ADDRESS                        (0x400a2170UL)
#define PDSS_BB_40CSA_4_CTRL                                (*(volatile uint32_t *)(0x400a2170UL))
#define PDSS_BB_40CSA_4_CTRL_DEFAULT                        (0x00101010UL)

/*
 * PMOS output dac selection bits in slope compensation block. X is the lsb
 * current of the DAC.
 * 0 - 0
 * 1 - 1X
 * 2 - 2X
 * 3 - 3X
 * .......
 * 255 - 255X
 * NOTE: This value is selected in BBBUCK mode when BB_40CSA_3_CTRL.BB_40CSA_SEL_IDAC_INDPNT
 * == 1
 */
#define PDSS_BB_40CSA_4_CTRL_BB_40CSA_SEL_IDAC_BBBUCK_LV_MASK    (0x000000ffUL) /* <0:7> R:RW:16: */
#define PDSS_BB_40CSA_4_CTRL_BB_40CSA_SEL_IDAC_BBBUCK_LV_POS    (0UL)


/*
 * PMOS output dac selection bits in slope compensation block. X is the lsb
 * current of the DAC.
 * 0 - 0
 * 1 - 1X
 * 2 - 2X
 * 3 - 3X
 * .......
 * 255 - 255X
 *
 * NOTE: This value is selected in BBBOOST mode when BB_40CSA_3_CTRL.BB_40CSA_SEL_IDAC_INDPNT
 * == 1
 */
#define PDSS_BB_40CSA_4_CTRL_BB_40CSA_SEL_IDAC_BBBOOST_LV_MASK    (0x0000ff00UL) /* <8:15> R:RW:16: */
#define PDSS_BB_40CSA_4_CTRL_BB_40CSA_SEL_IDAC_BBBOOST_LV_POS    (8UL)


/*
 * PMOS output dac selection bits in slope compensation block. X is the lsb
 * current of the DAC.
 * 0 - 0
 * 1 - 1X
 * 2 - 2X
 * 3 - 3X
 * .......
 * 255 - 255X
 *
 * NOTE: This value is selected in BOOST mode when BB_40CSA_3_CTRL.BB_40CSA_SEL_IDAC_INDPNT
 * == 1
 */
#define PDSS_BB_40CSA_4_CTRL_BB_40CSA_SEL_IDAC_BOOST_LV_MASK    (0x00ff0000UL) /* <16:23> R:RW:16: */
#define PDSS_BB_40CSA_4_CTRL_BB_40CSA_SEL_IDAC_BOOST_LV_POS    (16UL)


/*
 * S8PDBB 40V Regulator Control LD Register (NA in PMG1S3)
 */
#define PDSS_BB_40VREGLD_CTRL_ADDRESS                       (0x400a2174UL)
#define PDSS_BB_40VREGLD_CTRL                               (*(volatile uint32_t *)(0x400a2174UL))
#define PDSS_BB_40VREGLD_CTRL_DEFAULT                       (0x00000003UL)

/*
 * Enable signal for vbus_in regulator
 * 1 : vbus_in regulator loop enabled
 * 0 : Vbus_in regulator powered down
 */
#define PDSS_BB_40VREGLD_CTRL_BB_40VREG_VBUSIN_REG_EN       (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Enable signal for driving vddd through standby(vbus_in) regulator
 * 1: Enable vbus_in regulator to vddd path
 * 0 : Disable vbus_in regulator to vddd path
 */
#define PDSS_BB_40VREGLD_CTRL_BB_40VREG_VREG_STDBY_EN       (1UL << 1) /* <1:1> R:RW:1: */


/*
 *  MSB for adft control bus, adft_ctrl < 3:0 >
 */
#define PDSS_BB_40VREGLD_CTRL_BB_40VREG_ADFT_CTRL_EXT       (1UL << 2) /* <2:2> R:RW:0: */


/*
 *  Generic testmode bits for vbus_in regulator:
 */
#define PDSS_BB_40VREGLD_CTRL_BB_40VREG_T_VBUSIN_REG_MASK    (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_BB_40VREGLD_CTRL_BB_40VREG_T_VBUSIN_REG_POS    (8UL)


/*
 *  Generic testmode bits for vin regulator:
 */
#define PDSS_BB_40VREGLD_CTRL_BB_40VREG_T_VIN_REG_MASK      (0x00fc0000UL) /* <18:23> R:RW:0: */
#define PDSS_BB_40VREGLD_CTRL_BB_40VREG_T_VIN_REG_POS       (18UL)


/*
 * S8PDBB HIGH SIDE Switch Control Register (NA in PMG1S3)
 */
#define PDSS_BB_HSSW_CTRL_ADDRESS                           (0x400a2178UL)
#define PDSS_BB_HSSW_CTRL                                   (*(volatile uint32_t *)(0x400a2178UL))
#define PDSS_BB_HSSW_CTRL_DEFAULT                           (0x00000001UL)

/*
 * Block enable for high-side switch . en_sw=0 block is disabled , en_sw=1
 * block is enabled
 */
#define PDSS_BB_HSSW_CTRL_BB_HSSW_EN_SW                     (1UL << 0) /* <0:0> R:RW:1: */


/*
 * T-bits for high-side switch block
 * <1> = Adft enable , connects switch output, vbus_sw to adft<0>
 * <2> = enable 1kohm pull-down on switch output (vbus_sw)
 * <4:3> = not used
 */
#define PDSS_BB_HSSW_CTRL_BB_HSSW_T_HSSW_MASK               (0x0000001eUL) /* <1:4> R:RW:0: */
#define PDSS_BB_HSSW_CTRL_BB_HSSW_T_HSSW_POS                (1UL)


/*
 * USBPD Hard IP C-connector Control Register 2
 */
#define PDSS_CC_CTRL_2_ADDRESS                              (0x400a217cUL)
#define PDSS_CC_CTRL_2                                      (*(volatile uint32_t *)(0x400a217cUL))
#define PDSS_CC_CTRL_2_DEFAULT                              (0x00000000UL)

/*
 * enable signal for 'vccd+cgnd' regulator in wrapper block.
 * 1: output is regulated to 'vccd+cgnd'
 * 0: output is bypassed to vccd
 */
#define PDSS_CC_CTRL_2_CC_EN_VCCDSH_REG_WRAP                (1UL << 0) /* <0:0> R:RW:0: */


/*
 * enable signal for 'vref_1p1_ext+cgnd' buffer in wrapper block
 * 1: output is regulated to 'vref_1p1_ext +cgnd'
 * 0: output is bypassed to vref_1p1_ext
 */
#define PDSS_CC_CTRL_2_CC_EN_V0P74_BUFF_WRAP                (1UL << 1) /* <1:1> R:RW:0: */


/*
 * enable signal for 'vref_0p74+cgnd' buffer in wrapper block
 * 1: output is regulated to 'vref_0p74 +cgnd'
 * 0: output is bypassed to vref_0p74
 */
#define PDSS_CC_CTRL_2_CC_EN_V1P1_BUFF_WRAP                 (1UL << 2) /* <2:2> R:RW:0: */


/*
 * enable signal for biasgen in wrapper block
 * 1: iref_0p6u & iref_2p4_act<1:0> inputs are mirrored in wrapper block(and
 * also used for blocks inside wrapper)  and given to CC block
 * 0: iref_0p6u & iref_2p4_act<1:0> inputs are bypassed and directly given
 * to CC block
 */
#define PDSS_CC_CTRL_2_CC_BYP_BIASGEN_WRAP                  (1UL << 3) /* <3:3> R:RW:0: */


/*
 * bypass signal for biasgen in wrapper block
 * 1: iref_2p4_act<1:0> inputs are bypassed and directly given to CC block
 */
#define PDSS_CC_CTRL_2_CC_EN_BIASGEN_WRAP                   (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Trim options for 'vccd+cgnd' regulator output.
 * For code 0: default
 * For codes 1 to 4: default+N*35mV
 * For codes 5 to 7: default+(4-N)*35mV
 */
#define PDSS_CC_CTRL_2_CC_VCCD_SH_TRIM_MASK                 (0x00f00000UL) /* <20:23> R:RW:0: */
#define PDSS_CC_CTRL_2_CC_VCCD_SH_TRIM_POS                  (20UL)


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_CLK_CTRL1_ADDRESS                       (0x400a2200UL)
#define PDSS_BBCTRL_CLK_CTRL1                               (*(volatile uint32_t *)(0x400a2200UL))
#define PDSS_BBCTRL_CLK_CTRL1_DEFAULT                       (0x0000203bUL)

/*
 * Frequency of Buck Boost controller defined in one less than number of
 * cycles of 24/48 MHz clock
 */
#define PDSS_BBCTRL_CLK_CTRL1_BBCTRL_CLK_FIX_FREQ_MASK      (0x000001ffUL) /* <0:8> R:RW:59: */
#define PDSS_BBCTRL_CLK_CTRL1_BBCTRL_CLK_FIX_FREQ_POS       (0UL)


/*
 * Blanking time for HS1 trailing edge in BB Buck mode during transition
 * in 24/48 MHz cycles
 */
#define PDSS_BBCTRL_CLK_CTRL1_BBCTRL_HS1_BLANKING_TIME_TRAIL_MASK    (0x0000f000UL) /* <12:15> R:RW:2: */
#define PDSS_BBCTRL_CLK_CTRL1_BBCTRL_HS1_BLANKING_TIME_TRAIL_POS    (12UL)


/*
 * max_duty_hs1/ls2+blanking_time must be less than switching_freq by atleast
 * 2 cycles
 */
#define PDSS_BBCTRL_CLK_CTRL1_BBCTRL_HS1_LS2_BLANKING_TIME_MASK    (0x00070000UL) /* <16:18> R:RW:0: */
#define PDSS_BBCTRL_CLK_CTRL1_BBCTRL_HS1_LS2_BLANKING_TIME_POS    (16UL)


/*
 * Phase shift value in 24/48 MHz cycles. The value to be programmed is "1"
 * more than actual required phase shift count.
 */
#define PDSS_BBCTRL_CLK_CTRL1_BBCTRL_CLK_PHASE_SHIFT_MASK    (0x0ff00000UL) /* <20:27> R:RW:0: */
#define PDSS_BBCTRL_CLK_CTRL1_BBCTRL_CLK_PHASE_SHIFT_POS    (20UL)


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_CLK_CTRL2_ADDRESS                       (0x400a2204UL)
#define PDSS_BBCTRL_CLK_CTRL2                               (*(volatile uint32_t *)(0x400a2204UL))
#define PDSS_BBCTRL_CLK_CTRL2_DEFAULT                       (0x000003ceUL)

/*
 * Transient load detect sample-and-hold Pulse width in terms of 24/48 MHz
 * clock cycles
 */
#define PDSS_BBCTRL_CLK_CTRL2_BBCTRL_PW_ILOAD_MASK          (0x0000001eUL) /* <1:4> R:RW:7: */
#define PDSS_BBCTRL_CLK_CTRL2_BBCTRL_PW_ILOAD_POS           (1UL)


/*
 * Transient load detect sample-and-hold Period in terms of the 24/48 MHz
 * clock cycles
 */
#define PDSS_BBCTRL_CLK_CTRL2_BBCTRL_PER_ILOAD_MASK         (0x00003fe0UL) /* <5:13> R:RW:30: */
#define PDSS_BBCTRL_CLK_CTRL2_BBCTRL_PER_ILOAD_POS          (5UL)


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_FF_SPRD_CTRL_ADDRESS                    (0x400a2208UL)
#define PDSS_BBCTRL_FF_SPRD_CTRL                            (*(volatile uint32_t *)(0x400a2208UL))
#define PDSS_BBCTRL_FF_SPRD_CTRL_DEFAULT                    (0x00003008UL)

/*
 * Enable spread spectrum
 */
#define PDSS_BBCTRL_FF_SPRD_CTRL_BBCTRL_FF_SPRD_EN          (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Spread spectrum mode
 * 00 - Triangular spread spectrum
 * 01 - Pseudo random based on Galois (Preferred Pseudo-Random, use Initial
 * value for the LFSR of 0x2C for BBCTRL_FF_SPRD_LFSR_INIT[10:3])
 * 10 - Pseudo random based on Fibonacci
 * 11 - Unused
 */
#define PDSS_BBCTRL_FF_SPRD_CTRL_BBCTRL_FF_SPRD_MODE_MASK    (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_BBCTRL_FF_SPRD_CTRL_BBCTRL_FF_SPRD_MODE_POS    (1UL)


/*
 * [10:3] - Initial value for the LFSR
 * [15:11] -  Triangular spread sprectrum - Defines the positive and negative
 * peaks of the triangular waveform, where cycle to
 *                 cycle increment is by one 24/48MHz clock
 *                 Pseudo random based spread spectrum - Defines the limits
 * for the maximum value or percentage of dithering allowed
 * [18:16] - Defines the maximum cycle to cycle variation allowed in the
 * case of pseudo random
 */
#define PDSS_BBCTRL_FF_SPRD_CTRL_BBCTRL_FF_SPRD_LFSR_INIT_MASK    (0x0007fff8UL) /* <3:18> R:RW:1537: */
#define PDSS_BBCTRL_FF_SPRD_CTRL_BBCTRL_FF_SPRD_LFSR_INIT_POS    (3UL)


/*
 * 0: The following duty cycle values follow the variation in spread spectrum,
 * i.e. increase in period of switching frequency results in corresponding
 * increase in duty cycle and vice-versa
 *               a. BBCTRL_BUCK_SW_CTRL:: BBCTRL_HS1_MAX_DUTY_CYCLE
 *               b. BBCTRL_BOOST_SW_CTRL :: BBCTRL_LS2_MAX_DUTY_CYCLE
 *               c. BBCTRL_BB_FIXED_CYCLE_SW_CTRL :: HS1_FIXED_DUTY_CYCLE_BBBOOST
 * 1: will keep the duty cycle same irrespective of the change in period
 * of switching frequency
 */
#define PDSS_BBCTRL_FF_SPRD_CTRL_BBCTRL_DITHERING_OFFSET_OVRD    (1UL << 30) /* <30:30> R:RW:0: */


/*
 * 0: The scap reset count value will follow the variation in spread spectrum,
 * i.e. increase in period of switching frequency results in corresponding
 * increase in scap reset count value and vice-versa
 * BBCTRL_FUNC_CTRL2:: BBCTRL_SCAP_RST_CNT_WDTH
 * 1: will keep the scap reset count value same irrespective of the change
 * in period of switching frequency
 */
#define PDSS_BBCTRL_FF_SPRD_CTRL_BBCTRL_DITHERING_SCAP_OFFSET_OVRD    (1UL << 31) /* <31:31> R:RW:0: */


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_AUDIO_T_CNFG_ADDRESS                    (0x400a220cUL)
#define PDSS_BBCTRL_AUDIO_T_CNFG                            (*(volatile uint32_t *)(0x400a220cUL))
#define PDSS_BBCTRL_AUDIO_T_CNFG_DEFAULT                    (0x0500000eUL)

/*
 * This register defines the max frequency of audio range.
 */
#define PDSS_BBCTRL_AUDIO_T_CNFG_BBCTRL_AUDIO_TMIN_MASK     (0x0000007fUL) /* <0:6> R:RW:14: */
#define PDSS_BBCTRL_AUDIO_T_CNFG_BBCTRL_AUDIO_TMIN_POS      (0UL)


/*
 * This register defines the min frequency of audio range.
 */
#define PDSS_BBCTRL_AUDIO_T_CNFG_BBCTRL_AUDIO_TMAX_MASK     (0x0ffff000UL) /* <12:27> R:RW:20480: */
#define PDSS_BBCTRL_AUDIO_T_CNFG_BBCTRL_AUDIO_TMAX_POS      (12UL)


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_BUCK_SW_CTRL_ADDRESS                    (0x400a2210UL)
#define PDSS_BBCTRL_BUCK_SW_CTRL                            (*(volatile uint32_t *)(0x400a2210UL))
#define PDSS_BBCTRL_BUCK_SW_CTRL_DEFAULT                    (0x0060d806UL)

/*
 * HS1 minimum  duty cycle in 24/48 MHz cycles
 */
#define PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_HS1_MIN_DUTY_CYCLE_MASK    (0x0000007fUL) /* <0:6> R:RW:6: */
#define PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_HS1_MIN_DUTY_CYCLE_POS    (0UL)


/*
 * HS1 maximum duty cycle in 24/48 MHz cycles.
 * NOTE: This value should always be lesser than or equal to "Total # of
 * BB-CLK cycles in one switching cycle - 3 BB-clk" CDT366654
 */
#define PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_HS1_MAX_DUTY_CYCLE_MASK    (0x0007fc00UL) /* <10:18> R:RW:54: */
#define PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_HS1_MAX_DUTY_CYCLE_POS    (10UL)


/*
 * HS1 pulse width in 24/48 MHz cycles during soft start
 * NOTE: The value programmed has to be 1 less than the required value.
 */
#define PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_SS_PW_HS1_MASK      (0x07f00000UL) /* <20:26> R:RW:6: */
#define PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_SS_PW_HS1_POS       (20UL)


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_BOOST_SW_CTRL_ADDRESS                   (0x400a2214UL)
#define PDSS_BBCTRL_BOOST_SW_CTRL                           (*(volatile uint32_t *)(0x400a2214UL))
#define PDSS_BBCTRL_BOOST_SW_CTRL_DEFAULT                   (0x0060d806UL)

/*
 * LS2 maximum duty cycle in 24/48 MHz cycles
 */
#define PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_LS2_MIN_DUTY_CYCLE_MASK    (0x0000007fUL) /* <0:6> R:RW:6: */
#define PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_LS2_MIN_DUTY_CYCLE_POS    (0UL)


/*
 * LS2 maximum duty cycle in 24/48 MHz cycles.
 * NOTE: This value should always be lesser than or equal to "Total # of
 * BB-CLK cycles in one switching cycle - 3 BB-clk" CDT366654
 */
#define PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_LS2_MAX_DUTY_CYCLE_MASK    (0x0007fc00UL) /* <10:18> R:RW:54: */
#define PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_LS2_MAX_DUTY_CYCLE_POS    (10UL)


/*
 * LS2 pulse width in 24/48 MHz cycles during soft start
 * NOTE: The value programmed has to be 1 less than the required value.
 */
#define PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_SS_PW_LS2_MASK     (0x07f00000UL) /* <20:26> R:RW:6: */
#define PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_SS_PW_LS2_POS      (20UL)


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_DUTYCYCLE_CTRL_ADDRESS                  (0x400a2218UL)
#define PDSS_BBCTRL_DUTYCYCLE_CTRL                          (*(volatile uint32_t *)(0x400a2218UL))
#define PDSS_BBCTRL_DUTYCYCLE_CTRL_DEFAULT                  (0x00001806UL)

/*
 * Maximum value by which HS1 duty cycle can jump across two consecutive
 * cycle
 * Note: The de-assertion of HS1 will have a jump of an additional value,
 * if in the previous cycle the de-assertion was as a result of "ilimit"
 * detection
 */
#define PDSS_BBCTRL_DUTYCYCLE_CTRL_BBCTRL_HS1_DUTYCYCLE_UPDT_MASK    (0x0000007fUL) /* <0:6> R:RW:6: */
#define PDSS_BBCTRL_DUTYCYCLE_CTRL_BBCTRL_HS1_DUTYCYCLE_UPDT_POS    (0UL)


/*
 * Maximum value by which LS2 duty cycle can jump  across two consecutive
 * cycle
 * Note: The de-assertion of LS2 will have a jump of an additional value,
 * if in the previous cycle the de-assertion was as a result of "ilimit"
 * detection
 */
#define PDSS_BBCTRL_DUTYCYCLE_CTRL_BBCTRL_LS2_DUTYCYCLE_UPDT_MASK    (0x0001fc00UL) /* <10:16> R:RW:6: */
#define PDSS_BBCTRL_DUTYCYCLE_CTRL_BBCTRL_LS2_DUTYCYCLE_UPDT_POS    (10UL)


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_FUNC_CTRL_ADDRESS                       (0x400a221cUL)
#define PDSS_BBCTRL_FUNC_CTRL                               (*(volatile uint32_t *)(0x400a221cUL))
#define PDSS_BBCTRL_FUNC_CTRL_DEFAULT                       (0x079c0442UL)

/*
 * Bypass the PWM Hard IP. The controls are now performed by Soft IP
 * 0 : Hard IP mode (set/reset_buck/boost used by HardIP)
 * 1 : RTL mode (reset_buck/boost ignored)
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_PWM_HIP_BYP            (1UL << 1) /* <1:1> R:RW:1: */


/*
 * Enables BuckBoost Controller
 * 0 - Disable state machine (Idle)
 * 1 - Enable state machine (required for EA or SS modes)
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_EN                     (1UL << 2) /* <2:2> R:RW:0: */


/*
 * This controls the mode of operation (Enabling this along with BBCTRL_STARTUP_MODE
 * will make FSM to go to IDLE)
 * 0 - EA based loop control is disabled.
 * 1 - EA based loop control is enabled.
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_EA_MODE                (1UL << 3) /* <3:3> R:RW:0: */


/*
 * FW Control Bit to push FSM to Next State
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_FORCE_FSM              (1UL << 4) /* <4:4> RW1C:RW1S:0: */


/*
 * FW Control Bit to push FSM to Reset State
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_RST_CTRL               (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Enables exiting of SKIP mode irrespective of Audio range.
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_AUDIO_SKIP_OVR         (1UL << 6) /* <6:6> R:RW:1: */


/*
 * Enable soft-start mode of operation for BB Controller
 * 0 - Soft-start mode disabled
 * 1 - Soft-start mode enabled (Enabling this along with BBCTRL_EA_MODE will
 * make FSM to go to IDLE)
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_STARTUP_MODE           (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Enables FW soft-start Control for HS1 (Applicable when BBCTL_STARTUP_MODE=1)
 * 00 - Soft-start pulse on HS1
 * 01 - LOW on HS1
 * 10 - HIGH on HS1
 * 11 - not valid (low on HS1)
 */
#define PDSS_BBCTRL_FUNC_CTRL_BB_FW_STARTUP_CTRL_HS1_MASK    (0x00000300UL) /* <8:9> R:RW:0: */
#define PDSS_BBCTRL_FUNC_CTRL_BB_FW_STARTUP_CTRL_HS1_POS    (8UL)


/*
 * Enables FW soft-start Control for LS2 (Applicable when BBCTL_STARTUP_MODE=1)
 * 00 - Soft-start pulse on LS2
 * 01 - LOW on LS2
 * 10 - HIGH on LS2
 * 11 - not valid (low on LS2)
 */
#define PDSS_BBCTRL_FUNC_CTRL_BB_FW_STARTUP_CTRL_LS2_MASK    (0x00000c00UL) /* <10:11> R:RW:1: */
#define PDSS_BBCTRL_FUNC_CTRL_BB_FW_STARTUP_CTRL_LS2_POS    (10UL)


/*
 * When set, Forces Buck mode of operation
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_FORCE_BUCK_MODE        (1UL << 12) /* <12:12> R:RW:0: */


/*
 * When set, Forces Boost mode of operation
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_FORCE_BOOST_MODE       (1UL << 13) /* <13:13> R:RW:0: */


/*
 * RCP control register
 * <2> : 1 : Disables RCP in Boost, BB-Boost and forced-boost modes
 * <1> : 1 : Disables RCP in Buck, BB-buck and forced-buck modes
 * <0> : 1 : Disables RCP in Skip,  idle and startup modes
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_GDRVO_RCP_DISABE_MASK    (0x0001c000UL) /* <14:16> R:RW:0: */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_GDRVO_RCP_DISABE_POS    (14UL)


/*
 * ZCD control register
 * <2> : 1 : Disables ZCD in Boost, BB-Boost and forced-boost modes
 * <1> : 1 : Disables ZCD in Buck, BB-buck and forced-buck modes
 * <0> : 1 : Disables ZCD in Skip,  idle and startup modes
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_GDRVI_ZCD_DISABE_MASK    (0x001c0000UL) /* <18:20> R:RW:7: */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_GDRVI_ZCD_DISABE_POS    (18UL)


/*
 * Port0 to Port1start-of-cycle clk sync :
 * 0 : Start-of-cycle is synchronized between Port0 and Port1 with respect
 * to reference clk
 * 1 : Start-of-cycle is async between Port0 and Port1
 */
#define PDSS_BBCTRL_FUNC_CTRL_BB_CTRL_CLKREF_SYNC_DISABLE    (1UL << 22) /* <22:22> R:RW:0: */


/*
 * 1: Override for HS1 duty cycle jump UP across two consecutive cycle
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_HS1_DUTYCYCLE_UP_OVR    (1UL << 23) /* <23:23> R:RW:1: */


/*
 * 1: Override for HS1 duty cycle jump DOWN across two consecutive cycle
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_HS1_DUTYCYCLE_DN_OVR    (1UL << 24) /* <24:24> R:RW:1: */


/*
 * 1: Override for LS2  duty cycle jump UP across two consecutive cycle
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_LS2_DUTYCYCLE_UP_OVR    (1UL << 25) /* <25:25> R:RW:1: */


/*
 * 1: Override for LS2 duty cycle jump DOWN across two consecutive cycle
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_LS2_DUTYCYCLE_DN_OVR    (1UL << 26) /* <26:26> R:RW:1: */


/*
 * Soft-Start mode completed
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_STARTUP_MODE_DONE      (1UL << 27) /* <27:27> R:RW:0: */


/*
 * 1: Disable refresh cycle in 4-switch Boost mode
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_DISABLE_BOOST_REFRESH    (1UL << 28) /* <28:28> R:RW:0: */


/*
 * 1: Disable refresh cycle in 4-switch Buck mode
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_DISABLE_BUCK_REFRESH    (1UL << 29) /* <29:29> R:RW:0: */


/*
 * 1: Disable refresh during SKIP for 2-switch Buck or Boost mode
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_SKIP_REFRESH_DISABLE    (1UL << 30) /* <30:30> R:RW:0: */


/*
 * 1: Disable refresh during IDLE for 2-switch Buck or Boost mode
 */
#define PDSS_BBCTRL_FUNC_CTRL_BBCTRL_IDLE_REFRESH_DISABLE    (1UL << 31) /* <31:31> R:RW:0: */


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_FUNC_CTRL2_ADDRESS                      (0x400a2220UL)
#define PDSS_BBCTRL_FUNC_CTRL2                              (*(volatile uint32_t *)(0x400a2220UL))
#define PDSS_BBCTRL_FUNC_CTRL2_DEFAULT                      (0x08f0700bUL)

/*
 * 1 : Enables digital SKIP logic
 */
#define PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_DIG_EN           (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Defines the HS1/LS2 pulse width below which the part will enter SKIP mode
 * (valid only when BBCTRL_SKIP_DIG_EN=1)
 * 0 would mean 1 clk cycle
 */
#define PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_WIDTH_LOW_MASK    (0x0000007eUL) /* <1:6> R:RW:5: */
#define PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_WIDTH_LOW_POS    (1UL)


/*
 * Defines the HS1/LS2 pulse width above which the part will exit SKIP mode
 * (valid only when BBCTRL_SKIP_DIG_EN=1)
 * 0 would mean 1 clk cycle
 */
#define PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_WIDTH_HIGH_MASK    (0x0007f000UL) /* <12:18> R:RW:7: */
#define PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_WIDTH_HIGH_POS    (12UL)


/*
 * Defines Width of SCAP_RST pulse.
 */
#define PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SCAP_RST_CNT_WDTH_MASK    (0x01f00000UL) /* <20:24> R:RW:15: */
#define PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SCAP_RST_CNT_WDTH_POS    (20UL)


/*
 * Blanking time of RST_SW1 signal from leading edge of HS1/LS2
 */
#define PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_RST_SW_BLNK_TIM_MASK    (0x1e000000UL) /* <25:28> R:RW:4: */
#define PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_RST_SW_BLNK_TIM_POS    (25UL)


/*
 * 1: Entering to SKIP does not depend on previous switching cycle to be
 * DCM (detected by ZCD/RCP)
 */
#define PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_DCM_DISABLE      (1UL << 29) /* <29:29> R:RW:0: */


/*
 * 1: Disable the refresh cycle triggered by VBST comparator output
 */
#define PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_VBST_REFRESH_DISABLE    (1UL << 30) /* <30:30> R:RW:0: */


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_FUNC_CTRL3_ADDRESS                      (0x400a2224UL)
#define PDSS_BBCTRL_FUNC_CTRL3                              (*(volatile uint32_t *)(0x400a2224UL))
#define PDSS_BBCTRL_FUNC_CTRL3_DEFAULT                      (0x000003ffUL)

/*
 * 1: The scomp output is set HIGH from the entry cycle to SKIP to the exit
 * cycle of SKIP.
 * 0: Debug Only. not supported in functional mode
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_SCOMP_SKIP_MODE_SET_HIGH    (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Defines the maximum possible width of scomp pulse.
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_SCOMP_COUNT_WIDTH_MASK    (0x000003feUL) /* <1:9> R:RW:511: */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_SCOMP_COUNT_WIDTH_POS    (1UL)


/*
 * Disable the detection of fault in VIN_UV
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VIN_UV    (1UL << 16) /* <16:16> R:RW:0: */


/*
 * 1: F/W writes 1 to clear the UV, OV faults in VIN or VOUT
 * The bit self clears once written.
 * The firmware should write "1" in this field when all the conditions pertaining
 * to the particular fault that occurred is addressed
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_CLR         (1UL << 17) /* <17:17> RW1C:RW1S:0: */


/*
 *  1: The ilimit detection is treated as fault and the state machine is
 * moved to IDLE
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_ILIM_FAULT_DET_EN     (1UL << 18) /* <18:18> R:RW:0: */


/*
 * 1: F/W writes 1 to clear the ilimit fault and allow FSM to move out of
 * IDLE
 * The bit self clears once written and this bit is valid only if BBCTRL_ILIM_FAULT_DET_EN
 * is set to 1.
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_ILIM_FAULT_DET_CLR    (1UL << 19) /* <19:19> RW1C:RW1S:0: */


/*
 * Disable the detection of fault VIN_OV
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VIN_OV    (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Disable the detection of fault VOUT_UV
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VOUT_UV    (1UL << 21) /* <21:21> R:RW:0: */


/*
 * Disable the detection of fault VOUT_UV
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VOUT_OV    (1UL << 22) /* <22:22> R:RW:0: */


/*
 * Disable the detection of fault VSRC_NEW_P
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VSRC_NEW_P    (1UL << 23) /* <23:23> R:RW:0: */


/*
 * Disable the detection of fault VSRC_NEW_N
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VSRC_NEW_N    (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Disable the detection of fault PDS_SCP
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_PDS_SCP    (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Disable the detection of fault OCP
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_OCP     (1UL << 26) /* <26:26> R:RW:0: */


/*
 * Disable the detection of fault SCP
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_SCP     (1UL << 27) /* <27:27> R:RW:0: */


/*
 * Disable the detection of fault VREG_INRUSH
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VREG_INRUSH    (1UL << 28) /* <28:28> R:RW:0: */


/*
 * Disable the detection of fault ILIM
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_ILIM    (1UL << 29) /* <29:29> R:RW:0: */


/*
 * Disable the detection of fault VDDD_BOD
 */
#define PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VDDD_BOD    (1UL << 30) /* <30:30> R:RW:0: */


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_STATUS_ADDRESS                          (0x400a2228UL)
#define PDSS_BBCTRL_STATUS                                  (*(volatile uint32_t *)(0x400a2228UL))
#define PDSS_BBCTRL_STATUS_DEFAULT                          (0x00000000UL)

/*
 * Status of Filtered BUCK_COMP_OUT going back to PWM HardIP
 */
#define PDSS_BBCTRL_STATUS_BBCTRL_BUCK_COMP_OUT_HYST        (1UL << 0) /* <0:0> RW:R:0: */


/*
 * Status of Filtered BOOST_COMP_OUT going back to PWM HardIP
 */
#define PDSS_BBCTRL_STATUS_BBCTRL_BOOST_COMP_OUT_HYST       (1UL << 1) /* <1:1> RW:R:0: */


/*
 * Status of Filtered BBCOMP_OUT going back to PWM HardIP
 */
#define PDSS_BBCTRL_STATUS_BBCTRL_BBCOMP_OUT_HYST           (1UL << 3) /* <3:3> RW:R:0: */


/*
 * FSM error code :
 * 000 : No error
 * 001 : Indicate invalid combination of Buck_comp and Bbcomp
 * Rest : Not used
 */
#define PDSS_BBCTRL_STATUS_BBCTRL_ERR_CODE_MASK             (0x00001c00UL) /* <10:12> RW:R:0: */
#define PDSS_BBCTRL_STATUS_BBCTRL_ERR_CODE_POS              (10UL)


/*
 * FSM State
 * 5'h00 : IDLE
 * 5'h01 : STARTUP_MODE
 * 5'h02 : BOOST_MODE
 * 5'h03 : BUCK_MODE
 * 5'h04 : BOOST_MODE_PWM_DONE
 * 5'h05 : BOOST_MODE_MAXDUTY_DONE
 * 5'h06 : BUCK_MODE_PWM_DONE
 * 5'h07 : BUCK_MODE_MAXDUTY_DONE
 * 5'h08 : BBBOOST_MODE
 * 5'h09 : BBBOOST_MODE_PWM_DONE
 * 5'h0a : BBBOOST_MODE_MAXDUTY_DONE
 * 5'h0b : BBBUCK_MODE
 * 5'h0c : BBBUCK_MODE_PWM_DONE
 * 5'h0d : BBBUCK_MODE_MAXDUTY_DONE
 * 5'h0e : SKIP_MODE
 */
#define PDSS_BBCTRL_STATUS_BBCTRL_FSM_STATE_MASK            (0x0003e000UL) /* <13:17> RW:R:0: */
#define PDSS_BBCTRL_STATUS_BBCTRL_FSM_STATE_POS             (13UL)


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_FILT_CTRL_ADDRESS                       (0x400a222cUL)
#define PDSS_BBCTRL_FILT_CTRL                               (*(volatile uint32_t *)(0x400a222cUL))
#define PDSS_BBCTRL_FILT_CTRL_DEFAULT                       (0x00000325UL)

/*
 * pwmcomp_out final filter input select
 * 0: Select between pwmcomp_out from PWM module or external PWM signal based
 * on BB_EXT_PWM_OUT_SEL bit
 * 1: Select pwmcomp_rawout signal from the PWM module
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_PWMCOMP_OUT_SEL            (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Not Used
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_PWMCOMP_RAWOUT_SEL         (1UL << 1) /* <1:1> R:RW:0: */


/*
 * pwmcomp_rawout  edge detect, enable positive edge detection
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_PWMCOMP_RAWOUT_EDGE_DET_POS_EN    (1UL << 2) /* <2:2> R:RW:1: */


/*
 * Control bit for PWM out signal.
 * 0 - Logic uses pwmcomp_out from PWM module
 * 1 - Logic uses external GPIO signal.
 * Note: This selection is functional only when pwmcomp_out sel is not selected.
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_EXT_PWM_OUT_SEL            (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Not Used
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_ILIM_DIG_SEL               (1UL << 4) /* <4:4> R:RW:0: */


/*
 * ilim_dig edge detect, enable positive edge detection
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_ILIM_DIG_EDGE_DET_POS_EN    (1UL << 5) /* <5:5> R:RW:1: */


/*
 * ilim_dig edge detect, enable negative edge detection
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_ILIM_DIG_EDGE_DET_NEG_EN    (1UL << 6) /* <6:6> R:RW:0: */


/*
 * pwmcomp_rawout  edge detect, enable negative edge detection
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_PWMCOMP_RAWOUT_EDGE_DET_NEG_EN    (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Control for pwmcomp_out sync input to BBCTRL block
 * 0: Debug Only. Unsynchronized final PWM edge detector output
 * 1: Synchronized final PWM edge detector output
 * Note: For functional mode the following must be followed
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_PWMCOMP_OUT_FINAL_SEL      (1UL << 8) /* <8:8> R:RW:1: */


/*
 * 1: Enables early detection of PWM toggle for de-assertion of set_buck
 * and set_boost synchronously
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_PWMCOMP_EARLY_DET_SYNC     (1UL << 9) /* <9:9> R:RW:1: */


/*
 * 1: Enables early detection of PWM toggle for de-assertion of set_buck
 * and set_boost asynchronously
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_PWMCOMP_EARLY_DET_ASYNC    (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Controls the source of bbpwmcomp_edge source
 * 0: Selects conditioned filter output
 * 1: Selects raw output
 */
#define PDSS_BBCTRL_FILT_CTRL_BB_PWMCOMP_ASYNC_RAW_BYP      (1UL << 11) /* <11:11> R:RW:0:BB_ASYNC_NEW_EN */


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_DDFT_MUX_ADDRESS                        (0x400a2230UL)
#define PDSS_BBCTRL_DDFT_MUX                                (*(volatile uint32_t *)(0x400a2230UL))
#define PDSS_BBCTRL_DDFT_MUX_DEFAULT                        (0x00000000UL)

/*
 * 52: 1'b0
 * 51: 1'b0
 * 50: 1'b0
 * 49: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.reset_sw1
 * 48: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.scap_reset_lv
 * 47: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.scomp_sw_lv
 * 46: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.set_buck
 * 45: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.reset_buck
 * 44: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.set_boost
 * 43: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.reset_boost
 * 42: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.mode_buck
 * 41: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.mode_boost
 * 40: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.bbctrl_lszcd_en
 * 39: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.hsrcp_en
 * 38: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.from_buck_mode
 * 37: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.1'b0
 * 36: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.1'b0
 * 35: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.intr_ilimit_det
 * 34: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.intr_err_cond
 * 33: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.bbbuck_to_bbboost_trans
 * 32: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.bbboost_to_bbbuck_trans
 * 31: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.u_mxusbpd_bbctrl_timer_ctrl.start_pulse
 * 30: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.reg_startup_mode
 * 29: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.blanking_pulse
 * 28: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.skip_mode_enter
 * 27: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.skip_mode_exit
 * 26: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.sh_itran_det
 * 25: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.intr_audio_tmin_timeout
 * 24: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.intr_audio_tmax_timeout
 * 23: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.hs1_h2l_trans_large
 * 22: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.ls2_h2l_trans_large
 * 21: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.maxduty_done
 * 20: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.minduty_done
 * 19: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.dcm_det
 * 18: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.reg_enable
 * 17: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.vin_uv_det_filt
 * 16: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.vin_ov_det_filt
 * 15: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.ilimit_det_filt
 * 14: 1'b0
 * 13: 1'b0
 * 12: 1'b0
 * 11: 1'b0
 * 10: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.skipcomp_out_filt
 * 09: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.pwmcomp_out_filt
 * 08: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.buckcomp_out_filt
 * 07: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.boostcomp_out_filt
 * 06: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.bbcomp_out_filt
 * 05: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.hsrcp_out_filt
 * 04: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.lszcd_out_filt
 * 03: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.cc_flag_filt
 * 02: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.cc_det_filt
 * 01: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.cv_det_filt
 * 00: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.fault_det
 */
#define PDSS_BBCTRL_DDFT_MUX_BBCTRL_DDFT0_SEL_MASK          (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_BBCTRL_DDFT_MUX_BBCTRL_DDFT0_SEL_POS           (0UL)


/*
 * 52: 1'b0
 * 51: 1'b0
 * 50: 1'b0
 * 49: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.reset_sw1
 * 48: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.scap_reset_lv
 * 47: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.scomp_sw_lv
 * 46: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.set_buck
 * 45: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.reset_buck
 * 44: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.set_boost
 * 43: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.reset_boost
 * 42: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.mode_buck
 * 41: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.mode_boost
 * 40: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.bbctrl_lszcd_en
 * 39: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.hsrcp_en
 * 38: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.from_buck_mode
 * 37: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.1'b0
 * 36: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.1'b0
 * 35: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.intr_ilimit_det
 * 34: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.intr_err_cond
 * 33: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.bbbuck_to_bbboost_trans
 * 32: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.bbboost_to_bbbuck_trans
 * 31: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.u_mxusbpd_bbctrl_timer_ctrl.start_pulse
 * 30: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.reg_startup_mode
 * 29: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.blanking_pulse
 * 28: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.skip_mode_enter
 * 27: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.skip_mode_exit
 * 26: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.sh_itran_det
 * 25: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.intr_audio_tmin_timeout
 * 24: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.intr_audio_tmax_timeout
 * 23: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.hs1_h2l_trans_large
 * 22: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.ls2_h2l_trans_large
 * 21: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.maxduty_done
 * 20: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.minduty_done
 * 19: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.dcm_det
 * 18: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.reg_enable
 * 17: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.vin_uv_det_filt
 * 16: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.vin_ov_det_filt
 * 15: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.ilimit_det_filt
 * 14: 1'b0
 * 13: 1'b0
 * 12: 1'b0
 * 11: 1'b0
 * 10: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.skipcomp_out_filt
 * 09: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.pwmcomp_out_filt
 * 08: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.buckcomp_out_filt
 * 07: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.boostcomp_out_filt
 * 06: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.bbcomp_out_filt
 * 05: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.hsrcp_out_filt
 * 04: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.lszcd_out_filt
 * 03: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.cc_flag_filt
 * 02: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.cc_det_filt
 * 01: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.cv_det_filt
 * 00: MXUSBPD_MMIO_INST.y_bbctrl.u_mxusbpd_bbctrl_top.fault_det
 */
#define PDSS_BBCTRL_DDFT_MUX_BBCTRL_DDFT1_SEL_MASK          (0x0000fc00UL) /* <10:15> R:RW:0: */
#define PDSS_BBCTRL_DDFT_MUX_BBCTRL_DDFT1_SEL_POS           (10UL)


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_FF_STRTUP_ADDRESS                       (0x400a2234UL)
#define PDSS_BBCTRL_FF_STRTUP                               (*(volatile uint32_t *)(0x400a2234UL))
#define PDSS_BBCTRL_FF_STRTUP_DEFAULT                       (0x003e80f0UL)

/*
 * Soft-start switching period defined in one less than 24/48 MHz clock cycles
 */
#define PDSS_BBCTRL_FF_STRTUP_BBCTRL_SS_FREQ_MASK           (0x000007ffUL) /* <0:10> R:RW:240: */
#define PDSS_BBCTRL_FF_STRTUP_BBCTRL_SS_FREQ_POS            (0UL)


/*
 * refresh rate time in switching cycles (e.g. 400kHz)
 */
#define PDSS_BBCTRL_FF_STRTUP_BBCTRL_REFRESH_RATE_MASK      (0x01fff800UL) /* <11:24> R:RW:2000: */
#define PDSS_BBCTRL_FF_STRTUP_BBCTRL_REFRESH_RATE_POS       (11UL)


/*
 * MXUSBPD BB Control Register (NA in PMG1S3)
 */
#define PDSS_BBCTRL_BB_FIXED_CYCLE_SW_CTRL_ADDRESS          (0x400a2238UL)
#define PDSS_BBCTRL_BB_FIXED_CYCLE_SW_CTRL                  (*(volatile uint32_t *)(0x400a2238UL))
#define PDSS_BBCTRL_BB_FIXED_CYCLE_SW_CTRL_DEFAULT          (0x00003030UL)

/*
 * HS1 Fixed duty cycle in BB-Boost mode in 24/48 MHz cycles
 * NOTE: If BBCTRL_FILT_CTRL.BB_PWMCOMP_EARLY_DET_ASYNC is set, then the
 * value programmed has to be 1 more than the required value.
 */
/* Changing name of the macros to resolve coverity issues : MISRA C-2012 Rule 5.4  */
#define PDSS_BBCTRL_BB_FIXED_CYCLE_SW_CTRL_HS1_FIXD_DUTY_CYCLE_BBOOST_MASK    (0x000001ffUL) /* <0:8> R:RW:48: */
#define PDSS_BBCTRL_BB_FIXED_CYCLE_SW_CTRL_HS1_FIXD_DUTY_CYCLE_BBOOST_POS    (0UL)


/*
 * LS2 Fixed duty cycle in BB-Buck mode in 24/48 MHz cycles
 */
 /* Changing name of the macros to resolve coverity issues : MISRA C-2012 Rule 5.4  */
#define PDSS_BBCTRL_BB_FIXED_CYCLE_SW_CTRL_LS2_FIXD_DUTY_CYCLE_BBUCK_MASK    (0x0001fc00UL) /* <10:16> R:RW:12: */
#define PDSS_BBCTRL_BB_FIXED_CYCLE_SW_CTRL_LS2_FIXD_DUTY_CYCLE_BBUCK_POS    (10UL)


/*
 * IBUS Transition config (NA in PMG1S3)
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
 * IBUS Transition control (NA in PMG1S3)
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
 * IBUS Transition shadow registers (NA in PMG1S3)
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
 * IBUS Transition Initial/Final value registers (NA in PMG1S3)
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
 * IBUS Transition Status registers (NA in PMG1S3)
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
 * (NA in PMG1S3)
 */
#define PDSS_INTR17_CFG_0_ADDRESS                           (0x400a2280UL)
#define PDSS_INTR17_CFG_0                                   (*(volatile uint32_t *)(0x400a2280UL))
#define PDSS_INTR17_CFG_0_DEFAULT                           (0x00013827UL)

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
 * S8PDBB HardIP Filter and Edge detector config for 20CSA_ITRAN_DET L2H
 * & H2L (NA in PMG1S3)
 */
#define PDSS_INTR17_CFG_1_ADDRESS                           (0x400a2284UL)
#define PDSS_INTR17_CFG_1                                   (*(volatile uint32_t *)(0x400a2284UL))
#define PDSS_INTR17_CFG_1_DEFAULT                           (0x00050014UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_L2H_FILT_EN    (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_L2H_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:2: */
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_L2H_FILT_CFG_POS    (1UL)


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
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_L2H_FILT_RESET    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_L2H_FILT_BYPASS    (1UL << 4) /* <4:4> R:RW:1: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_L2H_FILT_SEL    (1UL << 5) /* <5:5> R:RW:0: */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_H2L_FILT_EN    (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_H2L_FILT_CFG_MASK    (0x00018000UL) /* <15:16> R:RW:2: */
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_H2L_FILT_CFG_POS    (15UL)


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
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_H2L_FILT_RESET    (1UL << 17) /* <17:17> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_H2L_FILT_BYPASS    (1UL << 18) /* <18:18> R:RW:1: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_1_BB_20CSA_ITRAN_DET_H2L_FILT_SEL    (1UL << 19) /* <19:19> R:RW:0: */


/*
 * S8PDBB HardIP Filter and Edge detector config for VIN OV & UV DET (NA
 * in PMG1S3)
 */
#define PDSS_INTR17_CFG_4_ADDRESS                           (0x400a2290UL)
#define PDSS_INTR17_CFG_4                                   (*(volatile uint32_t *)(0x400a2290UL))
#define PDSS_INTR17_CFG_4_DEFAULT                           (0x00012825UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_UV_DET_FILT_EN         (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_UV_DET_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:2: */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_UV_DET_FILT_CFG_POS    (1UL)


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
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_UV_DET_FILT_RESET      (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_UV_DET_FILT_BYPASS     (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_BB_SOFT filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_UV_DET_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:1: */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_UV_DET_FILT_SEL_POS    (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_OV_DET_FILT_EN         (1UL << 11) /* <11:11> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_OV_DET_FILT_CFG_MASK    (0x00003000UL) /* <12:13> R:RW:2: */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_OV_DET_FILT_CFG_POS    (12UL)


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
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_OV_DET_FILT_RESET      (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_OV_DET_FILT_BYPASS     (1UL << 15) /* <15:15> R:RW:0: */


/*
 * #of clock CLK_BB_SOFT filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_OV_DET_FILT_SEL_MASK    (0x001f0000UL) /* <16:20> R:RW:1: */
#define PDSS_INTR17_CFG_4_BB_PWM_VIN_OV_DET_FILT_SEL_POS    (16UL)


/*
 * S8PDBB HardIP Filter and Edge detector config for 40CSA ILIM_DIG & PWM_BLK_OUT
 * (NA in PMG1S3)
 */
#define PDSS_INTR17_CFG_5_ADDRESS                           (0x400a2294UL)
#define PDSS_INTR17_CFG_5                                   (*(volatile uint32_t *)(0x400a2294UL))
#define PDSS_INTR17_CFG_5_DEFAULT                           (0x00008014UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_EN         (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:2: */
#define PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_CFG_POS    (1UL)


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
#define PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_RESET      (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_BYPASS     (1UL << 4) /* <4:4> R:RW:1: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_SEL_POS    (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_5_BB_PWM_OUT_BLK_FILT_EN            (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_5_BB_PWM_OUT_BLK_FILT_CFG_MASK      (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_INTR17_CFG_5_BB_PWM_OUT_BLK_FILT_CFG_POS       (12UL)


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
#define PDSS_INTR17_CFG_5_BB_PWM_OUT_BLK_FILT_RESET         (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_5_BB_PWM_OUT_BLK_FILT_BYPASS        (1UL << 15) /* <15:15> R:RW:1: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_5_BB_PWM_OUT_BLK_FILT_SEL_MASK      (0x001f0000UL) /* <16:20> R:RW:0: */
#define PDSS_INTR17_CFG_5_BB_PWM_OUT_BLK_FILT_SEL_POS       (16UL)


/*
 * S8PDBB HardIP Filter and Edge detector config for PWM BUCK, BOOST& BB
 * COMP_OUT (NA in PMG1S3)
 */
#define PDSS_INTR17_CFG_6_ADDRESS                           (0x400a2298UL)
#define PDSS_INTR17_CFG_6                                   (*(volatile uint32_t *)(0x400a2298UL))
#define PDSS_INTR17_CFG_6_DEFAULT                           (0x28ea3947UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BUCKCOMP_OUT_FILT_EN       (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BUCKCOMP_OUT_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:3: */
#define PDSS_INTR17_CFG_6_BB_PWM_BUCKCOMP_OUT_FILT_CFG_POS    (1UL)


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
#define PDSS_INTR17_CFG_6_BB_PWM_BUCKCOMP_OUT_FILT_RESET    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BUCKCOMP_OUT_FILT_BYPASS    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_BB_SOFT filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BUCKCOMP_OUT_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:10: */
#define PDSS_INTR17_CFG_6_BB_PWM_BUCKCOMP_OUT_FILT_SEL_POS    (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BOOSTCOMP_OUT_FILT_EN      (1UL << 11) /* <11:11> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BOOSTCOMP_OUT_FILT_CFG_MASK    (0x00003000UL) /* <12:13> R:RW:3: */
#define PDSS_INTR17_CFG_6_BB_PWM_BOOSTCOMP_OUT_FILT_CFG_POS    (12UL)


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
#define PDSS_INTR17_CFG_6_BB_PWM_BOOSTCOMP_OUT_FILT_RESET    (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BOOSTCOMP_OUT_FILT_BYPASS    (1UL << 15) /* <15:15> R:RW:0: */


/*
 * #of clock CLK_BB_SOFT filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BOOSTCOMP_OUT_FILT_SEL_MASK    (0x001f0000UL) /* <16:20> R:RW:10: */
#define PDSS_INTR17_CFG_6_BB_PWM_BOOSTCOMP_OUT_FILT_SEL_POS    (16UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BBCOMP_OUT_FILT_EN         (1UL << 21) /* <21:21> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BBCOMP_OUT_FILT_CFG_MASK    (0x00c00000UL) /* <22:23> R:RW:3: */
#define PDSS_INTR17_CFG_6_BB_PWM_BBCOMP_OUT_FILT_CFG_POS    (22UL)


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
#define PDSS_INTR17_CFG_6_BB_PWM_BBCOMP_OUT_FILT_RESET      (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BBCOMP_OUT_FILT_BYPASS     (1UL << 25) /* <25:25> R:RW:0: */


/*
 * #of clock CLK_BB_SOFT filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR17_CFG_6_BB_PWM_BBCOMP_OUT_FILT_SEL_MASK    (0x7c000000UL) /* <26:30> R:RW:10: */
#define PDSS_INTR17_CFG_6_BB_PWM_BBCOMP_OUT_FILT_SEL_POS    (26UL)


/*
 * S8PDBB HardIP Filter and Edge detector config for GDRVO VBST_COMP & HSRCP
 * (NA in PMG1S3)
 */
#define PDSS_INTR17_CFG_7_ADDRESS                           (0x400a229cUL)
#define PDSS_INTR17_CFG_7                                   (*(volatile uint32_t *)(0x400a229cUL))
#define PDSS_INTR17_CFG_7_DEFAULT                           (0x00014401UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_7_BB_GDRVO_VBST_COMP_OUT_FILT_EN    (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_7_BB_GDRVO_VBST_COMP_OUT_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR17_CFG_7_BB_GDRVO_VBST_COMP_OUT_FILT_CFG_POS    (1UL)


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
#define PDSS_INTR17_CFG_7_BB_GDRVO_VBST_COMP_OUT_FILT_RESET    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_7_BB_GDRVO_VBST_COMP_OUT_FILT_BYPASS    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_7_BB_GDRVO_VBST_COMP_OUT_FILT_SEL_MASK    (0x00000fe0UL) /* <5:11> R:RW:32: */
#define PDSS_INTR17_CFG_7_BB_GDRVO_VBST_COMP_OUT_FILT_SEL_POS    (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_7_BB_GDRVO_HSRCP_OUT_FILT_EN        (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_7_BB_GDRVO_HSRCP_OUT_FILT_CFG_MASK    (0x00006000UL) /* <13:14> R:RW:2: */
#define PDSS_INTR17_CFG_7_BB_GDRVO_HSRCP_OUT_FILT_CFG_POS    (13UL)


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
#define PDSS_INTR17_CFG_7_BB_GDRVO_HSRCP_OUT_FILT_RESET     (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_7_BB_GDRVO_HSRCP_OUT_FILT_BYPASS    (1UL << 16) /* <16:16> R:RW:1: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_7_BB_GDRVO_HSRCP_OUT_FILT_SEL_MASK    (0x003e0000UL) /* <17:21> R:RW:0: */
#define PDSS_INTR17_CFG_7_BB_GDRVO_HSRCP_OUT_FILT_SEL_POS    (17UL)


/*
 * S8PDBB HardIP Filter and Edge detector config for GDRVI VBST_COMP & LSZCD
 * (NA in PMG1S3)
 */
#define PDSS_INTR17_CFG_8_ADDRESS                           (0x400a22a0UL)
#define PDSS_INTR17_CFG_8                                   (*(volatile uint32_t *)(0x400a22a0UL))
#define PDSS_INTR17_CFG_8_DEFAULT                           (0x00014401UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_8_BB_GDRVI_VBST_COMP_OUT_FILT_EN    (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_8_BB_GDRVI_VBST_COMP_OUT_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR17_CFG_8_BB_GDRVI_VBST_COMP_OUT_FILT_CFG_POS    (1UL)


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
#define PDSS_INTR17_CFG_8_BB_GDRVI_VBST_COMP_OUT_FILT_RESET    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_8_BB_GDRVI_VBST_COMP_OUT_FILT_BYPASS    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_8_BB_GDRVI_VBST_COMP_OUT_FILT_SEL_MASK    (0x00000fe0UL) /* <5:11> R:RW:32: */
#define PDSS_INTR17_CFG_8_BB_GDRVI_VBST_COMP_OUT_FILT_SEL_POS    (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_8_BB_GDRVI_LSZCD_OUT_FILT_EN        (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_8_BB_GDRVI_LSZCD_OUT_FILT_CFG_MASK    (0x00006000UL) /* <13:14> R:RW:2: */
#define PDSS_INTR17_CFG_8_BB_GDRVI_LSZCD_OUT_FILT_CFG_POS    (13UL)


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
#define PDSS_INTR17_CFG_8_BB_GDRVI_LSZCD_OUT_FILT_RESET     (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_8_BB_GDRVI_LSZCD_OUT_FILT_BYPASS    (1UL << 16) /* <16:16> R:RW:1: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_8_BB_GDRVI_LSZCD_OUT_FILT_SEL_MASK    (0x003e0000UL) /* <17:21> R:RW:0: */
#define PDSS_INTR17_CFG_8_BB_GDRVI_LSZCD_OUT_FILT_SEL_POS    (17UL)


/*
 * S8PDBB HardIP Filter and Edge detector config for EA CC & CV DET (NA in
 * PMG1S3)
 */
#define PDSS_INTR17_CFG_9_ADDRESS                           (0x400a22a4UL)
#define PDSS_INTR17_CFG_9                                   (*(volatile uint32_t *)(0x400a22a4UL))
#define PDSS_INTR17_CFG_9_DEFAULT                           (0x00108021UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_9_BB_EA_CC_FILT_EN                  (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_9_BB_EA_CC_FILT_CFG_MASK            (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR17_CFG_9_BB_EA_CC_FILT_CFG_POS             (1UL)


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
#define PDSS_INTR17_CFG_9_BB_EA_CC_FILT_RESET               (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_9_BB_EA_CC_FILT_BYPASS              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_9_BB_EA_CC_FILT_SEL_MASK            (0x00003fe0UL) /* <5:13> R:RW:1: */
#define PDSS_INTR17_CFG_9_BB_EA_CC_FILT_SEL_POS             (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_9_BB_EA_CV_FILT_EN                  (1UL << 15) /* <15:15> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_9_BB_EA_CV_FILT_CFG_MASK            (0x00030000UL) /* <16:17> R:RW:0: */
#define PDSS_INTR17_CFG_9_BB_EA_CV_FILT_CFG_POS             (16UL)


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
#define PDSS_INTR17_CFG_9_BB_EA_CV_FILT_RESET               (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_9_BB_EA_CV_FILT_BYPASS              (1UL << 19) /* <19:19> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_9_BB_EA_CV_FILT_SEL_MASK            (0x1ff00000UL) /* <20:28> R:RW:1: */
#define PDSS_INTR17_CFG_9_BB_EA_CV_FILT_SEL_POS             (20UL)


/*
 * S8PDBB HardIP Filter and Edge detector config for CC1_SCP & CC2_SCP (NA
 * in PMG1S3)
 */
#define PDSS_INTR17_CFG_10_ADDRESS                          (0x400a22a8UL)
#define PDSS_INTR17_CFG_10                                  (*(volatile uint32_t *)(0x400a22a8UL))
#define PDSS_INTR17_CFG_10_DEFAULT                          (0x00014014UL)

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
 * S8PDBB HardIP Filter and Edge detector config for VDDD_BOD (NA in PMG1S3)
 */
#define PDSS_INTR17_CFG_11_ADDRESS                          (0x400a22acUL)
#define PDSS_INTR17_CFG_11                                  (*(volatile uint32_t *)(0x400a22acUL))
#define PDSS_INTR17_CFG_11_DEFAULT                          (0x00014025UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_11_PDBB_VREG_VDDD_BOD_FILT_EN       (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_11_PDBB_VREG_VDDD_BOD_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:2: */
#define PDSS_INTR17_CFG_11_PDBB_VREG_VDDD_BOD_FILT_CFG_POS    (1UL)


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
#define PDSS_INTR17_CFG_11_PDBB_VREG_VDDD_BOD_FILT_RESET    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_11_PDBB_VREG_VDDD_BOD_FILT_BYPASS    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_11_PDBB_VREG_VDDD_BOD_FILT_SEL_MASK    (0x000007e0UL) /* <5:10> R:RW:1: */
#define PDSS_INTR17_CFG_11_PDBB_VREG_VDDD_BOD_FILT_SEL_POS    (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR17_CFG_11_PDBB_VIN_REG_CTRL_OUT_FILT_EN    (1UL << 12) /* <12:12> R:RW:0:BB40VREGLD_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR17_CFG_11_PDBB_VIN_REG_CTRL_OUT_FILT_CFG_MASK    (0x00006000UL) /* <13:14> R:RW:2:BB40VREGLD_EN */
#define PDSS_INTR17_CFG_11_PDBB_VIN_REG_CTRL_OUT_FILT_CFG_POS    (13UL)


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
#define PDSS_INTR17_CFG_11_PDBB_VIN_REG_CTRL_OUT_FILT_RESET    (1UL << 15) /* <15:15> R:RW:0:BB40VREGLD_EN */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR17_CFG_11_PDBB_VIN_REG_CTRL_OUT_FILT_BYPASS    (1UL << 16) /* <16:16> R:RW:1:BB40VREGLD_EN */


/*
 * #of clock CLK_BB filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR17_CFG_11_PDBB_VIN_REG_CTRL_OUT_FILT_SEL_MASK    (0x007e0000UL) /* <17:22> R:RW:0:BB40VREGLD_EN */
#define PDSS_INTR17_CFG_11_PDBB_VIN_REG_CTRL_OUT_FILT_SEL_POS    (17UL)


/*
 * INTR17 Status  (NA in PMG1S3)
 */
#define PDSS_INTR17_STATUS_0_ADDRESS                        (0x400a22e4UL)
#define PDSS_INTR17_STATUS_0                                (*(volatile uint32_t *)(0x400a22e4UL))
#define PDSS_INTR17_STATUS_0_DEFAULT                        (0x00000000UL)

/*
 * The status of s8pdbb_40vreg_top.vin_det
 */
#define PDSS_INTR17_STATUS_0_PDBB_40VREG_VIN_DET_STATUS     (1UL << 0) /* <0:0> RW:R:0:CCG7D_EN_INST_ZERO */


/*
 * The filtered output of s8pdbb_40vreg_top.vin_det
 */
#define PDSS_INTR17_STATUS_0_PDBB_40VREG_VIN_DET_FILT       (1UL << 1) /* <1:1> RW:R:0:CCG7D_EN_INST_ZERO */


/*
 * The status of s8pdbb_40vreg_top.in_rush_det_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_40VREG_IN_RUSH_DET_STATUS    (1UL << 2) /* <2:2> RW:R:0:CCG7D_EN_INST_ZERO */


/*
 * The filtered output of s8pdbb_40vreg_top.in_rush_det_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_40VREG_IN_RUSH_DET_FILT    (1UL << 3) /* <3:3> RW:R:0:CCG7D_EN_INST_ZERO */


/*
 * The status of s8pdbb_20csa_scp_top.itran_det_h2l
 */
#define PDSS_INTR17_STATUS_0_PDBB_20CSA_ITRAN_DET_L2H_STATUS    (1UL << 4) /* <4:4> RW:R:0: */


/*
 * The filtered output of s8pdbb_20csa_scp_top.itran_det_h2l
 */
#define PDSS_INTR17_STATUS_0_PDBB_20CSA_ITRAN_DET_L2H_FILT    (1UL << 5) /* <5:5> RW:R:0: */


/*
 * The status of s8pdbb_20csa_scp_top.itran_det_l2h
 */
#define PDSS_INTR17_STATUS_0_PDBB_20CSA_ITRAN_DET_H2L_STATUS    (1UL << 6) /* <6:6> RW:R:0: */


/*
 * The filtered output of s8pdbb_20csa_scp_top.itran_det_l2h
 */
#define PDSS_INTR17_STATUS_0_PDBB_20CSA_ITRAN_DET_H2L_FILT    (1UL << 7) /* <7:7> RW:R:0: */


/*
 * The status of s8pdbb_40csa_top.ilim_dig_out_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_40CSA_ILIM_DIG_OUT_STATUS    (1UL << 8) /* <8:8> RW:R:0: */


/*
 * The filtered output of s8pdbb_40csa_top.ilim_dig_out_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_40CSA_ILIM_DIG_OUT_FILT    (1UL << 9) /* <9:9> RW:R:0: */


/*
 * The status of s8pdbb_40csa_top.pwm_out_blk_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_PWM_OUT_BLK_STATUS        (1UL << 10) /* <10:10> RW:R:0: */


/*
 * The filtered output of s8pdbb_40csa_top.pwm_out_blk_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_PWM_OUT_BLK_FILT          (1UL << 11) /* <11:11> RW:R:0: */


/*
 * The status of s8pdbb_pwm_top.vin_uv_det_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_PWM_VIN_UV_DET_STATUS     (1UL << 20) /* <20:20> RW:R:0: */


/*
 * The filtered output of s8pdbb_pwm_top.vin_uv_det_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_PWM_VIN_UV_DET_FILT       (1UL << 21) /* <21:21> RW:R:0: */


/*
 * The status of s8pdbb_pwm_top.vin_ov_det_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_PWM_VIN_OV_DET_STATUS     (1UL << 22) /* <22:22> RW:R:0: */


/*
 * The filtered output of s8pdbb_pwm_top.vin_ov_det_lv
 */
#define PDSS_INTR17_STATUS_0_PDBB_PWM_VIN_OV_DET_FILT       (1UL << 23) /* <23:23> RW:R:0: */


/*
 * INTR17 Status  (NA in PMG1S3)
 */
#define PDSS_INTR17_STATUS_1_ADDRESS                        (0x400a22e8UL)
#define PDSS_INTR17_STATUS_1                                (*(volatile uint32_t *)(0x400a22e8UL))
#define PDSS_INTR17_STATUS_1_DEFAULT                        (0x00000000UL)

/*
 * The status of s8pdbb_pwm_top.buckcomp_out_lv
 */
#define PDSS_INTR17_STATUS_1_PDBB_PWM_BUCK_COMP_STATUS      (1UL << 0) /* <0:0> RW:R:0: */


/*
 * The filtered output of s8pdbb_pwm_top.buckcomp_out_lv
 */
#define PDSS_INTR17_STATUS_1_PDBB_PWM_BUCK_COMP_FILT        (1UL << 1) /* <1:1> RW:R:0: */


/*
 * The status of s8pdbb_pwm_top.boostcomp_out_lv
 */
#define PDSS_INTR17_STATUS_1_PDBB_PWM_BOOST_COMP_STATUS     (1UL << 2) /* <2:2> RW:R:0: */


/*
 * The filtered output of s8pdbb_pwm_top.boostcomp_out_lv
 */
#define PDSS_INTR17_STATUS_1_PDBB_PWM_BOOST_COMP_FILT       (1UL << 3) /* <3:3> RW:R:0: */


/*
 * The status of s8pdbb_pwm_top.bbcomp_out_lv
 */
#define PDSS_INTR17_STATUS_1_PDBB_PWM_BB_COMP_STATUS        (1UL << 4) /* <4:4> RW:R:0: */


/*
 * The filtered output of s8pdbb_pwm_top.bbcomp_out_lv
 */
#define PDSS_INTR17_STATUS_1_PDBB_PWM_BB_COMP_FILT          (1UL << 5) /* <5:5> RW:R:0: */


/*
 * The status of s8pdbb_gdrvo_top.vbst_comp_out
 */
#define PDSS_INTR17_STATUS_1_PDBB_GDRVO_VBST_COMP_STATUS    (1UL << 6) /* <6:6> RW:R:0: */


/*
 * The filtered output of s8pdbb_gdrvo_top.vbst_comp_out
 */
#define PDSS_INTR17_STATUS_1_PDBB_GDRVO_VBST_COMP_FILT      (1UL << 7) /* <7:7> RW:R:0: */


/*
 * The status of s8pdbb_gdrvo_top.hsrcp_out
 */
#define PDSS_INTR17_STATUS_1_PDBB_GDRVO_HSRCP_STATUS        (1UL << 8) /* <8:8> RW:R:0: */


/*
 * The filtered output of s8pdbb_gdrvo_top.hsrcp_out
 */
#define PDSS_INTR17_STATUS_1_PDBB_GDRVO_HSRCP_FILT          (1UL << 9) /* <9:9> RW:R:0: */


/*
 * The status of s8pdbb_gdrvi_top.vbst_comp_out
 */
#define PDSS_INTR17_STATUS_1_PDBB_GDRVI_VBST_COMP_STATUS    (1UL << 10) /* <10:10> RW:R:0: */


/*
 * The filtered output of s8pdbb_gdrvi_top.vbst_comp_out
 */
#define PDSS_INTR17_STATUS_1_PDBB_GDRVI_VBST_COMP_FILT      (1UL << 11) /* <11:11> RW:R:0: */


/*
 * The status of s8pdbb_gdrvi_top.lszcd_out
 */
#define PDSS_INTR17_STATUS_1_PDBB_GDRVI_LSZCD_STATUS        (1UL << 12) /* <12:12> RW:R:0: */


/*
 * The filtered output of s8pdbb_gdrvi_top.lszcd_out
 */
#define PDSS_INTR17_STATUS_1_PDBB_GDRVI_LSZCD_FILT          (1UL << 13) /* <13:13> RW:R:0: */


/*
 * The status of s8pdbb_ea_top.cc_det
 */
#define PDSS_INTR17_STATUS_1_PDBB_EA_CC_DET_STATUS          (1UL << 14) /* <14:14> RW:R:0: */


/*
 * The filtered output of s8pdbb_ea_top.cc_det
 */
#define PDSS_INTR17_STATUS_1_PDBB_EA_CC_DET_FILT            (1UL << 15) /* <15:15> RW:R:0: */


/*
 * The status of s8pdbb_ea_top.cv_det
 */
#define PDSS_INTR17_STATUS_1_PDBB_EA_CV_DET_STATUS          (1UL << 16) /* <16:16> RW:R:0: */


/*
 * The filtered output of s8pdbb_ea_top.cv_det
 */
#define PDSS_INTR17_STATUS_1_PDBB_EA_CV_DET_FILT            (1UL << 17) /* <17:17> RW:R:0: */


/*
 * The status of s8pdbb_20vconn_top.scp_cc1
 */
#define PDSS_INTR17_STATUS_1_PDBB_CC1_SCP_STATUS            (1UL << 18) /* <18:18> RW:R:0: */


/*
 * The filtered output of s8pdbb_ea_top.scp_cc1
 */
#define PDSS_INTR17_STATUS_1_PDBB_CC1_SCP_FILT              (1UL << 19) /* <19:19> RW:R:0: */


/*
 * The status of s8pdbb_20vconn_top.scp_cc2
 */
#define PDSS_INTR17_STATUS_1_PDBB_CC2_SCP_STATUS            (1UL << 20) /* <20:20> RW:R:0: */


/*
 * The filtered output of s8pdbb_ea_top.scp_cc2
 */
#define PDSS_INTR17_STATUS_1_PDBB_CC2_SCP_FILT              (1UL << 21) /* <21:21> RW:R:0: */


/*
 * The status of s8pdbb_40vreg_top.vddd_bod_lv
 */
#define PDSS_INTR17_STATUS_1_PDBB_VREG_VDDD_BOD_STATUS      (1UL << 22) /* <22:22> RW:R:0:CCG7D_EN_INST_ZERO */


/*
 * The filtered output of s8pdbb_40vreg_top.vddd_bod_lv
 */
#define PDSS_INTR17_STATUS_1_PDBB_VREG_VDDD_BOD_FILT        (1UL << 23) /* <23:23> RW:R:0:CCG7D_EN_INST_ZERO */


/*
 * The status of s8pdbb_40vregld_top.vin_reg_ctrl_out_lv
 */
#define PDSS_INTR17_STATUS_1_PDBB_VIN_REG_CTRL_OUT_STATUS    (1UL << 24) /* <24:24> RW:R:0:BB40VREGLD_EN */


/*
 * The filtered output of s8pdbb_40vregld_top.vin_reg_ctrl_out_lv
 */
#define PDSS_INTR17_STATUS_1_PDBB_VIN_REG_CTRL_OUT_FILT     (1UL << 25) /* <25:25> RW:R:0:BB40VREGLD_EN */


/*
 * INTR17 interrupt Cause. (NA in PMG1S3)
 */
#define PDSS_INTR17_ADDRESS                                 (0x400a22ecUL)
#define PDSS_INTR17                                         (*(volatile uint32_t *)(0x400a22ecUL))
#define PDSS_INTR17_DEFAULT                                 (0x00000000UL)

/*
 * s8pdbb_40vreg_top.vin_det changed. Check the INTR17_STATUS_0.PDBB_40VREG_VIN_DET_STATUS
 */
#define PDSS_INTR17_PDBB_40VREG_VIN_DET                     (1UL << 0) /* <0:0> RW1S:RW1C:0:CCG7D_EN_INST_ZERO */


/*
 * s8pdbb_40vreg_top.in_rush_det_lv changed. Check the INTR17_STATUS_0.PDBB_40VREG_IN_RUSH_DET_STATUS
 */
#define PDSS_INTR17_PDBB_40VREG_IN_RUSH_DET                 (1UL << 1) /* <1:1> RW1S:RW1C:0:CCG7D_EN_INST_ZERO */


/*
 * s8pdbb_20csa_scp_top.itran_det_h2l changed. Check the INTR17_STATUS_0.PDBB_20CSA_ITRAN_DET_L2H_STATUS
 */
#define PDSS_INTR17_PDBB_20CSA_ITRAN_DET_L2H                (1UL << 2) /* <2:2> RW1S:RW1C:0: */


/*
 * s8pdbb_20csa_scp_top.itran_det_l2h changed. Check the INTR17_STATUS_0.PDBB_20CSA_ITRAN_DET_H2L_STATUS
 */
#define PDSS_INTR17_PDBB_20CSA_ITRAN_DET_H2L                (1UL << 3) /* <3:3> RW1S:RW1C:0: */


/*
 * s8pdbb_40csa_top.ilim_dig_out_lv changed. Check the INTR17_STATUS_0.PDBB_40CSA_ILIM_DIG_OUT_STATUS
 */
#define PDSS_INTR17_PDBB_40CSA_ILIM_DIG_OUT                 (1UL << 4) /* <4:4> RW1S:RW1C:0: */


/*
 * s8pdbb_40csa_top.pwm_out_blk_lv changed. Check the INTR17_STATUS_0.PDBB_PWM_OUT_BLK_STATUS
 */
#define PDSS_INTR17_PDBB_PWM_OUT_BLK                        (1UL << 5) /* <5:5> RW1S:RW1C:0: */


/*
 * s8pdbb_pwm_top.vin_uv_det_lv changed. Check the INTR17_STATUS_0.PDBB_PWM_VIN_UV_DET_STATUS
 */
#define PDSS_INTR17_PDBB_PWM_VIN_UV_DET                     (1UL << 10) /* <10:10> RW1S:RW1C:0: */


/*
 * s8pdbb_pwm_top.vin_ov_det_lv changed. Check the INTR17_STATUS_0.PDBB_PWM_VIN_OV_DET_STATUS
 */
#define PDSS_INTR17_PDBB_PWM_VIN_OV_DET                     (1UL << 11) /* <11:11> RW1S:RW1C:0: */


/*
 * s8pdbb_pwm_top.buckcomp_out_lv changed. Check the INTR17_STATUS_1.PDBB_PWM_BUCK_COMP_STATUS
 */
#define PDSS_INTR17_PDBB_PWM_BUCK_COMP                      (1UL << 12) /* <12:12> RW1S:RW1C:0: */


/*
 * s8pdbb_pwm_top.boostcomp_out_lv changed. Check the INTR17_STATUS_1.PDBB_PWM_BOOST_COMP_STATUS
 */
#define PDSS_INTR17_PDBB_PWM_BOOST_COMP                     (1UL << 13) /* <13:13> RW1S:RW1C:0: */


/*
 * s8pdbb_pwm_top.bbcomp_out_lv changed. Check the INTR17_STATUS_1.PDBB_PWM_BB_COMP_STATUS
 */
#define PDSS_INTR17_PDBB_PWM_BB_COMP                        (1UL << 14) /* <14:14> RW1S:RW1C:0: */


/*
 * s8pdbb_gdrvo_top.vbst_comp_out changed. Check the INTR17_STATUS_1.PDBB_GDRVO_VBST_COMP_STATUS
 */
#define PDSS_INTR17_PDBB_GDRVO_VBST_COMP                    (1UL << 15) /* <15:15> RW1S:RW1C:0: */


/*
 * s8pdbb_gdrvo_top.hsrcp_out changed. Check the INTR17_STATUS_1.PDBB_GDRVO_HSRCP_STATUS
 */
#define PDSS_INTR17_PDBB_GDRVO_HSRCP                        (1UL << 16) /* <16:16> RW1S:RW1C:0: */


/*
 * s8pdbb_gdrvi_top.vbst_comp_out changed. Check the INTR17_STATUS_1.PDBB_GDRVI_VBST_COMP_STATUS
 */
#define PDSS_INTR17_PDBB_GDRVI_VBST_COMP                    (1UL << 17) /* <17:17> RW1S:RW1C:0: */


/*
 * s8pdbb_gdrvi_top.lszcd_out changed. Check the INTR17_STATUS_1.PDBB_GDRVI_LSZCD_STATUS
 */
#define PDSS_INTR17_PDBB_GDRVI_LSZCD                        (1UL << 18) /* <18:18> RW1S:RW1C:0: */


/*
 * s8pdbb_ea_top.cc_det changed. Check the INTR17_STATUS_1.PDBB_EA_CC_DET_STATUS
 */
#define PDSS_INTR17_PDBB_EA_CC_DET                          (1UL << 19) /* <19:19> RW1S:RW1C:0: */


/*
 * s8pdbb_ea_top.cv_det changed. Check the INTR17_STATUS_1.PDBB_EA_CV_DET_STATUS
 */
#define PDSS_INTR17_PDBB_EA_CV_DET                          (1UL << 20) /* <20:20> RW1S:RW1C:0: */


/*
 * changed. Check the INTR17_STATUS_1.PDBB_CC1_SCP_STATUS
 */
#define PDSS_INTR17_PDBB_CC1_SCP                            (1UL << 21) /* <21:21> RW1S:RW1C:0: */


/*
 * changed. Check the INTR17_STATUS_1.PDBB_CC2_SCP_STATUS
 */
#define PDSS_INTR17_PDBB_CC2_SCP                            (1UL << 22) /* <22:22> RW1S:RW1C:0: */


/*
 * changed. Check the INTR17_STATUS_1.PDBB_VREG_VDDD_BOD_STATUS
 */
#define PDSS_INTR17_PDBB_VREG_VDDD_BOD                      (1UL << 23) /* <23:23> RW1S:RW1C:0:CCG7D_EN_INST_ZERO */


/*
 * changed. Check the INTR17_STATUS_1.PDBB_VIN_REG_CTRL_OUT_STATUS
 */
#define PDSS_INTR17_PDBB_VIN_REG_CTRL_OUT                   (1UL << 24) /* <24:24> RW1S:RW1C:0:BB40VREGLD_EN */


/*
 * INTR17 Interrupt Set (NA in PMG1S3)
 */
#define PDSS_INTR17_SET_ADDRESS                             (0x400a22f0UL)
#define PDSS_INTR17_SET                                     (*(volatile uint32_t *)(0x400a22f0UL))
#define PDSS_INTR17_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_40VREG_VIN_DET                 (1UL << 0) /* <0:0> A:RW1S:0:CCG7D_EN_INST_ZERO */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_40VREG_IN_RUSH_DET             (1UL << 1) /* <1:1> A:RW1S:0:CCG7D_EN_INST_ZERO */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_20CSA_ITRAN_DET_L2H            (1UL << 2) /* <2:2> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_20CSA_ITRAN_DET_H2L            (1UL << 3) /* <3:3> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_40CSA_ILIM_DIG_OUT             (1UL << 4) /* <4:4> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_PWM_OUT_BLK                    (1UL << 5) /* <5:5> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_PWM_VIN_UV_DET                 (1UL << 10) /* <10:10> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_PWM_VIN_OV_DET                 (1UL << 11) /* <11:11> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_PWM_BUCK_COMP                  (1UL << 12) /* <12:12> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_PWM_BOOST_COMP                 (1UL << 13) /* <13:13> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_PWM_BB_COMP                    (1UL << 14) /* <14:14> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_GDRVO_VBST_COMP                (1UL << 15) /* <15:15> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_GDRVO_HSRCP                    (1UL << 16) /* <16:16> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_GDRVI_VBST_COMP                (1UL << 17) /* <17:17> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_GDRVI_LSZCD                    (1UL << 18) /* <18:18> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_EA_CC_DET                      (1UL << 19) /* <19:19> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_EA_CV_DET                      (1UL << 20) /* <20:20> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_CC1_SCP                        (1UL << 21) /* <21:21> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_CC2_SCP                        (1UL << 22) /* <22:22> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_VREG_VDDD_BOD                  (1UL << 23) /* <23:23> A:RW1S:0:CCG7D_EN_INST_ZERO */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_SET_PDBB_VIN_REG_CTRL_OUT               (1UL << 24) /* <24:24> A:RW1S:0:BB40VREGLD_EN */


/*
 * INTR17 interrupt Mask (NA in PMG1S3)
 */
#define PDSS_INTR17_MASK_ADDRESS                            (0x400a22f4UL)
#define PDSS_INTR17_MASK                                    (*(volatile uint32_t *)(0x400a22f4UL))
#define PDSS_INTR17_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_40VREG_VIN_DET_MASK           (1UL << 0) /* <0:0> R:RW:0:CCG7D_EN_INST_ZERO */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_40VREG_IN_RUSH_DET_MASK       (1UL << 1) /* <1:1> R:RW:0:CCG7D_EN_INST_ZERO */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_20CSA_ITRAN_DET_L2H_MASK      (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_20CSA_ITRAN_DET_H2L_MASK      (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_40CSA_ILIM_DIG_OUT_MASK       (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_PWM_OUT_BLK_MASK              (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_PWM_VIN_UV_DET_MASK           (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_PWM_VIN_OV_DET_MASK           (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_PWM_BUCK_COMP_MASK            (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_PWM_BOOST_COMP_MASK           (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_PWM_BB_COMP_MASK              (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_GDRVO_VBST_COMP_MASK          (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_GDRVO_HSRCP_MASK              (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_GDRVI_VBST_COMP_MASK          (1UL << 17) /* <17:17> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_GDRVI_LSZCD_MASK              (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_EA_CC_DET_MASK                (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_EA_CV_DET_MASK                (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_CC1_SCP_MASK                  (1UL << 21) /* <21:21> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_CC2_SCP_MASK                  (1UL << 22) /* <22:22> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_VREG_VDDD_BOD_MASK            (1UL << 23) /* <23:23> R:RW:0:CCG7D_EN_INST_ZERO */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR17_MASK_PDBB_VIN_REG_CTRL_OUT_MASK         (1UL << 24) /* <24:24> R:RW:0:BB40VREGLD_EN */


/*
 * INTR17 interrupt Masked (NA in PMG1S3)
 */
#define PDSS_INTR17_MASKED_ADDRESS                          (0x400a22f8UL)
#define PDSS_INTR17_MASKED                                  (*(volatile uint32_t *)(0x400a22f8UL))
#define PDSS_INTR17_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_40VREG_VIN_DET_MASKED       (1UL << 0) /* <0:0> RW:R:0:CCG7D_EN_INST_ZERO */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_40VREG_IN_RUSH_DET_MASKED    (1UL << 1) /* <1:1> RW:R:0:CCG7D_EN_INST_ZERO */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_20CSA_ITRAN_DET_L2H_MASKED    (1UL << 2) /* <2:2> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_20CSA_ITRAN_DET_H2L_MASKED    (1UL << 3) /* <3:3> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_40CSA_ILIM_DIG_OUT_MASKED    (1UL << 4) /* <4:4> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_PWM_OUT_BLK_MASKED          (1UL << 5) /* <5:5> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_PWM_VIN_UV_DET_MASKED       (1UL << 10) /* <10:10> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_PWM_VIN_OV_DET_MASKED       (1UL << 11) /* <11:11> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_PWM_BUCK_COMP_MASKED        (1UL << 12) /* <12:12> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_PWM_BOOST_COMP_MASKED       (1UL << 13) /* <13:13> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_PWM_BB_COMP_MASKED          (1UL << 14) /* <14:14> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_GDRVO_VBST_COMP_MASKED      (1UL << 15) /* <15:15> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_GDRVO_HSRCP_MASKED          (1UL << 16) /* <16:16> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_GDRVI_VBST_COMP_MASKED      (1UL << 17) /* <17:17> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_GDRVI_LSZCD_MASKED          (1UL << 18) /* <18:18> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_EA_CC_DET_MASKED            (1UL << 19) /* <19:19> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_EA_CV_DET_MASKED            (1UL << 20) /* <20:20> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_CC1_SCP_MASKED              (1UL << 21) /* <21:21> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_CC2_SCP_MASKED              (1UL << 22) /* <22:22> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_VREG_VDDD_BOD_MASKED        (1UL << 23) /* <23:23> RW:R:0:CCG7D_EN_INST_ZERO */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR17_MASKED_PDBB_VIN_REG_CTRL_OUT_MASKED     (1UL << 24) /* <24:24> RW:R:0:BB40VREGLD_EN */


/*
 * INTR10 Cause. These are the active interrupts get reflected on interrupt_usbpd
 * pin.
 */
#define PDSS_INTR10_ADDRESS                                 (0x400a2340UL)
#define PDSS_INTR10                                         (*(volatile uint32_t *)(0x400a2340UL))
#define PDSS_INTR10_DEFAULT                                 (0x00000000UL)

/*
 * This interrupt is asserted when the HS1 or LS2 is de-asserted at maximum
 * duty cycle, indicating no EA cut off condition
 */
#define PDSS_INTR10_BBCTRL_MAX_DUTY_DET                     (1UL << 0) /* <0:0> RW1S:RW1C:0:PDBBC_EN */


/*
 * This interrupt indicates that the EA cut off occurred before the minimum
 * duty cycle for HS1 or LS2
 */
#define PDSS_INTR10_BBCTRL_MIN_DUTY_DET                     (1UL << 1) /* <1:1> RW1S:RW1C:0:PDBBC_EN */


/*
 * This interrupt indicates Reverse Current Protection (RCP) or Zero Cross
 * Detection (ZCD) condition occurred during BOOST and BUCK modes respectively.
 */
#define PDSS_INTR10_BBCTRL_DCM_DET                          (1UL << 2) /* <2:2> RW1S:RW1C:0:PDBBC_EN */


/*
 * This interrupt indicates an invalid mode was indicated by the PWM block
 */
#define PDSS_INTR10_BBCTRL_ERR_COND                         (1UL << 4) /* <4:4> RW1S:RW1C:0:PDBBC_EN */


/*
 * This interrupt indicates an Audio minimum period timeout condition.
 */
#define PDSS_INTR10_BBCTRL_AUDIO_TMIN_TIMEOUT               (1UL << 5) /* <5:5> RW1S:RW1C:0:PDBBC_EN */


/*
 * This interrupt indicates an Audio maximum period timeout condition.
 */
#define PDSS_INTR10_BBCTRL_AUDIO_TMAX_TIMEOUT               (1UL << 6) /* <6:6> RW1S:RW1C:0:PDBBC_EN */


/*
 * INTR10 Set
 */
#define PDSS_INTR10_SET_ADDRESS                             (0x400a2344UL)
#define PDSS_INTR10_SET                                     (*(volatile uint32_t *)(0x400a2344UL))
#define PDSS_INTR10_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_SET_BBCTRL_MAX_DUTY_DET                 (1UL << 0) /* <0:0> A:RW1S:0:PDBBC_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_SET_BBCTRL_MIN_DUTY_DET                 (1UL << 1) /* <1:1> A:RW1S:0:PDBBC_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_SET_BBCTRL_DCM_DET                      (1UL << 2) /* <2:2> A:RW1S:0:PDBBC_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_SET_BBCTRL_ERR_COND                     (1UL << 4) /* <4:4> A:RW1S:0:PDBBC_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_SET_BBCTRL_AUDIO_TMIN_TIMEOUT           (1UL << 5) /* <5:5> A:RW1S:0:PDBBC_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_SET_BBCTRL_AUDIO_TMAX_TIMEOUT           (1UL << 6) /* <6:6> A:RW1S:0:PDBBC_EN */


/*
 * INTR10 Mask
 */
#define PDSS_INTR10_MASK_ADDRESS                            (0x400a2348UL)
#define PDSS_INTR10_MASK                                    (*(volatile uint32_t *)(0x400a2348UL))
#define PDSS_INTR10_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_MASK_BBCTRL_MAX_DUTY_DET_MASK           (1UL << 0) /* <0:0> R:RW:0:PDBBC_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_MASK_BBCTRL_MIN_DUTY_DET_MASK           (1UL << 1) /* <1:1> R:RW:0:PDBBC_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_MASK_BBCTRL_DCM_DET_MASK                (1UL << 2) /* <2:2> R:RW:0:PDBBC_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_MASK_BBCTRL_ERR_COND_MASK               (1UL << 4) /* <4:4> R:RW:0:PDBBC_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_MASK_BBCTRL_AUDIO_TMIN_TIMEOUT_MASK     (1UL << 5) /* <5:5> R:RW:0:PDBBC_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR10_MASK_BBCTRL_AUDIO_TMAX_TIMEOUT_MASK     (1UL << 6) /* <6:6> R:RW:0:PDBBC_EN */


/*
 * INTR10 Masked
 */
#define PDSS_INTR10_MASKED_ADDRESS                          (0x400a234cUL)
#define PDSS_INTR10_MASKED                                  (*(volatile uint32_t *)(0x400a234cUL))
#define PDSS_INTR10_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR10_MASKED_BBCTRL_MAX_DUTY_DET_MASKED       (1UL << 0) /* <0:0> RW:R:0:PDBBC_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR10_MASKED_BBCTRL_MIN_DUTY_DET_MASKED       (1UL << 1) /* <1:1> RW:R:0:PDBBC_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR10_MASKED_BBCTRL_DCM_DET_MASKED            (1UL << 2) /* <2:2> RW:R:0:PDBBC_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR10_MASKED_BBCTRL_ERR_COND_MASKED           (1UL << 4) /* <4:4> RW:R:0:PDBBC_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR10_MASKED_BBCTRL_AUDIO_TMIN_TIMEOUT_MASKED    (1UL << 5) /* <5:5> RW:R:0:PDBBC_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR10_MASKED_BBCTRL_AUDIO_TMAX_TIMEOUT_MASKED    (1UL << 6) /* <6:6> RW:R:0:PDBBC_EN */


/*
 * CCG7D GPIO DDFT & GPIO INTR DDFT Selections (NA in PMG1S3)
 */
#define PDSS_CCG7D_GPIO_DDFT_MUX_ADDRESS                    (0x400a2384UL)
#define PDSS_CCG7D_GPIO_DDFT_MUX                            (*(volatile uint32_t *)(0x400a2384UL))
#define PDSS_CCG7D_GPIO_DDFT_MUX_DEFAULT                    (0x00000000UL)

/*
 * 28: MXUSBPD_MMIO_INST.pdbb_vin_reg_ctrl_out_gpio
 * 27: MXUSBPD_MMIO_INST.pdbb_cc1_scp_gpio,
 * 26: MXUSBPD_MMIO_INST.pdbb_cc2_scp_gpio,
 * 25: MXUSBPD_MMIO_INST.pdbb_vreg_vddd_bod_gpio,
 * 24: MXUSBPD_MMIO_INST.pdbb_pwm_out_blk_gpio,
 * 23: MXUSBPD_MMIO_INST.pdbb_ea_cv_det_gpio,
 * 22: MXUSBPD_MMIO_INST.pdbb_ea_cc_det_gpio,
 * 21: MXUSBPD_MMIO_INST.pdbb_gdrvi_lszcd_gpio,
 * 20: MXUSBPD_MMIO_INST.pdbb_gdrvi_vbst_comp_gpio,
 * 19: MXUSBPD_MMIO_INST.pdbb_gdrvo_hsrcp_gpio,
 * 18: MXUSBPD_MMIO_INST.pdbb_gdrvo_vbst_comp_gpio,
 * 17: MXUSBPD_MMIO_INST.pdbb_pwm_bb_comp_gpio,
 * 16: MXUSBPD_MMIO_INST.pdbb_pwm_boost_comp_gpio,
 * 15: MXUSBPD_MMIO_INST.pdbb_pwm_buck_comp_gpio,
 * 14: MXUSBPD_MMIO_INST.pdbb_pwm_vin_ov_det_gpio,
 * 13: MXUSBPD_MMIO_INST.pdbb_pwm_vin_uv_det_gpio,
 * 12: 1'b0,
 * 11: 1'b0,
 * 10: 1'b0,
 * 09: 1'b0,
 * 08: MXUSBPD_MMIO_INST.pdbb_40csa_ilim_dig_gpio,
 * 07: MXUSBPD_MMIO_INST.pdbb_20csa_itran_det_h2l_gpio,
 * 06: MXUSBPD_MMIO_INST.pdbb_20csa_itran_det_l2h_gpio,
 * 05: MXUSBPD_MMIO_INST.pdbb_vreg_in_rush_gpio,
 * 04: MXUSBPD_MMIO_INST.bb_vreg_vin_gpio,
 * 03: MXUSBPD_MMIO_INST.pds_scp_filt_gpio,
 * 02: MXUSBPD_MMIO_INST.ea_cc_flag_gpio,
 * 01: MXUSBPD_MMIO_INST.skip_out_filt_gpio,
 * 00: MXUSBPD_MMIO_INST.pwm_out_filt_gpio
 */
#define PDSS_CCG7D_GPIO_DDFT_MUX_CCG7D_GPIO_DDFT0_SEL_MASK    (0x0000007fUL) /* <0:6> R:RW:0: */
#define PDSS_CCG7D_GPIO_DDFT_MUX_CCG7D_GPIO_DDFT0_SEL_POS    (0UL)


/*
 * 28: MXUSBPD_MMIO_INST.pdbb_vin_reg_ctrl_out_gpio
 * 27: MXUSBPD_MMIO_INST.pdbb_cc1_scp_gpio,
 * 26: MXUSBPD_MMIO_INST.pdbb_cc2_scp_gpio,
 * 25: MXUSBPD_MMIO_INST.pdbb_vreg_vddd_bod_gpio,
 * 24: MXUSBPD_MMIO_INST.pdbb_pwm_out_blk_gpio,
 * 23: MXUSBPD_MMIO_INST.pdbb_ea_cv_det_gpio,
 * 22: MXUSBPD_MMIO_INST.pdbb_ea_cc_det_gpio,
 * 21: MXUSBPD_MMIO_INST.pdbb_gdrvi_lszcd_gpio,
 * 20: MXUSBPD_MMIO_INST.pdbb_gdrvi_vbst_comp_gpio,
 * 19: MXUSBPD_MMIO_INST.pdbb_gdrvo_hsrcp_gpio,
 * 18: MXUSBPD_MMIO_INST.pdbb_gdrvo_vbst_comp_gpio,
 * 17: MXUSBPD_MMIO_INST.pdbb_pwm_bb_comp_gpio,
 * 16: MXUSBPD_MMIO_INST.pdbb_pwm_boost_comp_gpio,
 * 15: MXUSBPD_MMIO_INST.pdbb_pwm_buck_comp_gpio,
 * 14: MXUSBPD_MMIO_INST.pdbb_pwm_vin_ov_det_gpio,
 * 13: MXUSBPD_MMIO_INST.pdbb_pwm_vin_uv_det_gpio,
 * 12: 1'b0,
 * 11: 1'b0,
 * 10: 1'b0,
 * 09: 1'b0,
 * 08: MXUSBPD_MMIO_INST.pdbb_40csa_ilim_dig_gpio,
 * 07: MXUSBPD_MMIO_INST.pdbb_20csa_itran_det_h2l_gpio,
 * 06: MXUSBPD_MMIO_INST.pdbb_20csa_itran_det_l2h_gpio,
 * 05: MXUSBPD_MMIO_INST.pdbb_vreg_in_rush_gpio,
 * 04: MXUSBPD_MMIO_INST.bb_vreg_vin_gpio,
 * 03: MXUSBPD_MMIO_INST.pds_scp_filt_gpio,
 * 02: MXUSBPD_MMIO_INST.ea_cc_flag_gpio,
 * 01: MXUSBPD_MMIO_INST.skip_out_filt_gpio,
 * 00: MXUSBPD_MMIO_INST.pwm_out_filt_gpio
 */
#define PDSS_CCG7D_GPIO_DDFT_MUX_CCG7D_GPIO_DDFT1_SEL_MASK    (0x00007f00UL) /* <8:14> R:RW:0: */
#define PDSS_CCG7D_GPIO_DDFT_MUX_CCG7D_GPIO_DDFT1_SEL_POS    (8UL)


/*
 * CCG7D NCELL DDFT Selections (NA in PMG1S3)
 */
#define PDSS_CCG7D_NCELL_DDFT_MUX_ADDRESS                   (0x400a2388UL)
#define PDSS_CCG7D_NCELL_DDFT_MUX                           (*(volatile uint32_t *)(0x400a2388UL))
#define PDSS_CCG7D_NCELL_DDFT_MUX_DEFAULT                   (0x00000000UL)

/*
 * 112: MXUSBPD_MMIO_INST.bb_40vreg_vin_reg_ctrl_out_fx
 * 111: MXUSBPD_MMIO_INST.pdbb_vin_reg_ctrl_out_fx_scan
 * 110: MXUSBPD_MMIO_INST.bb_mode_fccm
 * 109: MXUSBPD_MMIO_INST.bb_keepoff_en
 * 108: MXUSBPD_MMIO_INST.bb_40csa_ilim_dig_out_fx,
 * 107: MXUSBPD_MMIO_INST.bb_20vconn_cc1_scp_fx,
 * 106: MXUSBPD_MMIO_INST.bb_20vconn_cc2_scp_fx,
 * 105: MXUSBPD_MMIO_INST.bb_40vreg_vddd_bod_fx,
 * 104: MXUSBPD_MMIO_INST.pdbb_vreg_vddd_bod_fx_scan,
 * 103: MXUSBPD_MMIO_INST.pdbb_cc2_scp_fx_scan,
 * 102: MXUSBPD_MMIO_INST.pdbb_cc1_scp_fx_scan,
 * 101: MXUSBPD_MMIO_INST.bb_vreg_vin_det_fx_scan,
 * 100: MXUSBPD_MMIO_INST.bb_vreg_in_rush_det_fx_scan,
 * 99 : MXUSBPD_MMIO_INST.pdbb_20csa_itran_det_l2h_fx_scan,
 * 98 : MXUSBPD_MMIO_INST.pdbb_20csa_itran_det_h2l_fx_scan,
 * 97 : MXUSBPD_MMIO_INST.pdbb_40csa_ilim_dig_fx_scan,
 * 96 : 1'b0,
 * 95 : 1'b0,
 * 94 : 1'b0,
 * 93 : 1'b0,
 * 92 : MXUSBPD_MMIO_INST.pdbb_pwm_vin_uv_det_fx_scan,
 * 91 : MXUSBPD_MMIO_INST.pdbb_pwm_vin_ov_det_fx_scan,
 * 90 : MXUSBPD_MMIO_INST.pdbb_pwm_buck_comp_fx_scan,
 * 89 : MXUSBPD_MMIO_INST.pdbb_pwm_boost_comp_fx_scan,
 * 88 : MXUSBPD_MMIO_INST.pdbb_pwm_bb_comp_fx_scan,
 * 87 : MXUSBPD_MMIO_INST.pdbb_gdrvo_vbst_comp_fx_scan,
 * 86 : MXUSBPD_MMIO_INST.pdbb_gdrvo_hsrcp_fx_scan,
 * 85 : MXUSBPD_MMIO_INST.pdbb_gdrvi_vbst_comp_fx_scan,
 * 84 : MXUSBPD_MMIO_INST.pdbb_gdrvi_lszcd_fx_scan,
 * 83 : MXUSBPD_MMIO_INST.pdbb_ea_cc_det_fx_scan,
 * 82 : MXUSBPD_MMIO_INST.pdbb_ea_cv_det_fx_scan,
 * 81 : MXUSBPD_MMIO_INST.pdbb_pwm_out_blk_fx_scan,
 * 80 : MXUSBPD_MMIO_INST.vconn20_ctrl_en_pump,
 * 79 : MXUSBPD_MMIO_INST.vconn20_ctrl_en_switch_cc2,
 * 78 : MXUSBPD_MMIO_INST.vconn20_ctrl_en_switch_cc1,
 * 77 : MXUSBPD_MMIO_INST.vconn_bb_en_pump_ddft_faults_masked,
 * 76 : MXUSBPD_MMIO_INST.vconn_bb_en_pump_ddft_async_fault_det,
 * 75 : MXUSBPD_MMIO_INST.vconn_bb_en_switch_cc2_ddft_faults_masked,
 * 74 : MXUSBPD_MMIO_INST.vconn_bb_en_switch_cc2_ddft_async_fault_det,
 * 73 : MXUSBPD_MMIO_INST.vconn_bb_en_switch_cc1_ddft_faults_masked,
 * 72 : MXUSBPD_MMIO_INST.vconn_bb_en_switch_cc1_ddft_async_fault_det,
 * 71 : MXUSBPD_MMIO_INST.ngdo_bb_gdrv_en_ddft_faults_masked,
 * 70 : MXUSBPD_MMIO_INST.ngdo_bb_gdrv_en_ddft_async_fault_det,
 * 69 : MXUSBPD_MMIO_INST.cc2_ocp_fx,
 * 68 : MXUSBPD_MMIO_INST.cc1_ocp_fx,
 * 67 : MXUSBPD_MMIO_INST.cc2_ovp_fx,
 * 66 : MXUSBPD_MMIO_INST.cc1_ovp_fx,
 * 65 : MXUSBPD_MMIO_INST.v5v_fx,
 * 64 : MXUSBPD_MMIO_INST.bb_gdrvi_func_lszcd_in,
 * 63 : MXUSBPD_MMIO_INST.bb_gdrvi_func_en_hsdr1_test,
 * 62 : MXUSBPD_MMIO_INST.bb_gdrvi_lszcd_out_fx,
 * 61 : MXUSBPD_MMIO_INST.bb_gdrvi_func_lsdr1_sen_dig_out,
 * 60 : MXUSBPD_MMIO_INST.bb_gdrvi_func_en_hsdr1_dig_out,
 * 59 : MXUSBPD_MMIO_INST.bb_gdrvi_func_en_lsdr1_test,
 * 58 : MXUSBPD_MMIO_INST.bb_gdrvi_func_hsdr1_sen_dig_out,
 * 57 : MXUSBPD_MMIO_INST.bb_gdrvi_vbst_comp_out_fx,
 * 56 : MXUSBPD_MMIO_INST.bb_gdrvo_func_en_lsdr2_dig_out,
 * 55 : MXUSBPD_MMIO_INST.bb_mode_buck,
 * 54 : MXUSBPD_MMIO_INST.bb_gdrvo_func_en_lsdr2_test,
 * 53 : MXUSBPD_MMIO_INST.bb_gdrvo_func_lsdr2_sen_dig_out,
 * 52 : MXUSBPD_MMIO_INST.bb_mode_boost,
 * 51 : MXUSBPD_MMIO_INST.bb_gdrvo_hsrcp_out_fx,
 * 50 : MXUSBPD_MMIO_INST.bb_gdrvo_vbst_comp_out_fx,
 * 49 : MXUSBPD_MMIO_INST.bb_gdrvo_func_hsdr2_sen_dig_out,
 * 48 : MXUSBPD_MMIO_INST.bb_gdrvo_func_en_hsdr2_test,
 * 47 : MXUSBPD_MMIO_INST.bb_gdrvo_func_en_hsdr2_dig_out,
 * 46 : MXUSBPD_MMIO_INST.bb_gdrvo_func_hsrcp_in,
 * 45 : MXUSBPD_MMIO_INST.bb_gdrvo_func_hsrcp_good_dig_out,
 * 44 : MXUSBPD_MMIO_INST.bb_pwm_func_pwmcomp_rawout_lv,
 * 43 : MXUSBPD_MMIO_INST.bb_pwm_out_blk_filt,
 * 42 : MXUSBPD_MMIO_INST.bb_pwm_ilimit_det_rtl,
 * 41 : MXUSBPD_MMIO_INST.bb_pwm_func_vout_uv_det_lv,
 * 40 : MXUSBPD_MMIO_INST.bb_pwm_bbcomp_out_fx,
 * 39 : MXUSBPD_MMIO_INST.bb_pwm_ls2_pwm_minduty_det_fx,
 * 38 : MXUSBPD_MMIO_INST.bb_pwm_func_reset_boost,
 * 37 : MXUSBPD_MMIO_INST.bb_pwm_boostcomp_out_fx,
 * 36 : MXUSBPD_MMIO_INST.bb_pwm_buckcomp_out_fx,
 * 35 : MXUSBPD_MMIO_INST.bb_pwm_func_set_boost,
 * 34 : MXUSBPD_MMIO_INST.bb_pwm_ls2_pwm_maxduty_det_fx,
 * 33 : MXUSBPD_MMIO_INST.bb_pwm_func_boostcomp_out_rtl,
 * 32 : MXUSBPD_MMIO_INST.bb_pwm_func_hs2_pwm_lv,
 * 31 : MXUSBPD_MMIO_INST.bb_pwm_vin_ov_det_fx,
 * 30 : MXUSBPD_MMIO_INST.bb_pwm_func_pwmcomp_nos_out_lv,
 * 29 : MXUSBPD_MMIO_INST.bb_pwm_func_ls1_pwm_lv,
 * 28 : MXUSBPD_MMIO_INST.bb_pwm_func_pwmcomp_out_lv,
 * 27 : MXUSBPD_MMIO_INST.bb_pwm_skipcomp_out_fx,
 * 26 : MXUSBPD_MMIO_INST.bb_pwm_func_hs1_pwm_lv,
 * 25 : MXUSBPD_MMIO_INST.bb_pwm_func_buckcomp_out_rtl,
 * 24 : MXUSBPD_MMIO_INST.bb_pwm_func_ls2_pwm_lv,
 * 23 : MXUSBPD_MMIO_INST.bb_pwm_hs1_pwm_minduty_det_fx,
 * 22 : MXUSBPD_MMIO_INST.bb_pwm_func_bbcomp_out_rtl,
 * 21 : MXUSBPD_MMIO_INST.bb_pwm_func_reset_buck,
 * 20 : MXUSBPD_MMIO_INST.bb_pwm_hs1_pwm_maxduty_det_fx,
 * 19 : MXUSBPD_MMIO_INST.bb_pwm_vin_uv_det_fx,
 * 18 : MXUSBPD_MMIO_INST.bb_40csa_pwm_out_blk_fx,
 * 17 : MXUSBPD_MMIO_INST.bb_scomp_sw_lv,
 * 16 : MXUSBPD_MMIO_INST.bb_40csa_func_scap_rst_lv,
 * 15 : MXUSBPD_MMIO_INST.final_ilim_dig_fx,
 * 14 : MXUSBPD_MMIO_INST.bb_40csa_func_reset_sw1_lv,
 * 13 : MXUSBPD_MMIO_INST.bb_40csa_func_rst_sw1_rtl_lv,
 * 12 : MXUSBPD_MMIO_INST.bb_40csa_func_set_boost_lv,
 * 11 : MXUSBPD_MMIO_INST.bb_40csa_func_scap_rst_rtl_lv,
 * 10 : MXUSBPD_MMIO_INST.pds_ea_cc_flag_fx,
 * 09 : MXUSBPD_MMIO_INST.pds_ea_cv_det_fx,
 * 08 : MXUSBPD_MMIO_INST.pds_ea_cc_det_fx,
 * 07 : MXUSBPD_MMIO_INST.bb_40vreg_in_rush_det_fx,
 * 06 : MXUSBPD_MMIO_INST.bb_40vreg_vin_det_fx,
 * 05 : MXUSBPD_MMIO_INST.bb_20csa_itran_det_h2l_fx,
 * 04 : MXUSBPD_MMIO_INST.bb_20csa_itran_det_l2h_fx,
 * 03 : MXUSBPD_MMIO_INST.bb_20csa_sh_itrandet,
 * 02 : MXUSBPD_MMIO_INST.csa_scp_fx,
 * 01 : MXUSBPD_MMIO_INST.csa_ocp_fx,
 * 00 : MXUSBPD_MMIO_INST.pds_scp_fx
 */
#define PDSS_CCG7D_NCELL_DDFT_MUX_CCG7D_NCELL_DDFT0_SEL_MASK    (0x0000007fUL) /* <0:6> R:RW:0: */
#define PDSS_CCG7D_NCELL_DDFT_MUX_CCG7D_NCELL_DDFT0_SEL_POS    (0UL)


/*
 * 112: MXUSBPD_MMIO_INST.bb_40vreg_vin_reg_ctrl_out_fx
 * 111: MXUSBPD_MMIO_INST.pdbb_vin_reg_ctrl_out_fx_scan
 * 110: MXUSBPD_MMIO_INST.bb_mode_fccm
 * 109: MXUSBPD_MMIO_INST.bb_keepoff_en
 * 108: MXUSBPD_MMIO_INST.bb_40csa_ilim_dig_out_fx,
 * 107: MXUSBPD_MMIO_INST.bb_20vconn_cc1_scp_fx,
 * 106: MXUSBPD_MMIO_INST.bb_20vconn_cc2_scp_fx,
 * 105: MXUSBPD_MMIO_INST.bb_40vreg_vddd_bod_fx,
 * 104: MXUSBPD_MMIO_INST.pdbb_vreg_vddd_bod_fx_scan,
 * 103: MXUSBPD_MMIO_INST.pdbb_cc2_scp_fx_scan,
 * 102: MXUSBPD_MMIO_INST.pdbb_cc1_scp_fx_scan,
 * 101: MXUSBPD_MMIO_INST.bb_vreg_vin_det_fx_scan,
 * 100: MXUSBPD_MMIO_INST.bb_vreg_in_rush_det_fx_scan,
 * 99 : MXUSBPD_MMIO_INST.pdbb_20csa_itran_det_l2h_fx_scan,
 * 98 : MXUSBPD_MMIO_INST.pdbb_20csa_itran_det_h2l_fx_scan,
 * 97 : MXUSBPD_MMIO_INST.pdbb_40csa_ilim_dig_fx_scan,
 * 96 : 1'b0,
 * 95 : 1'b0,
 * 94 : 1'b0,
 * 93 : 1'b0,
 * 92 : MXUSBPD_MMIO_INST.pdbb_pwm_vin_uv_det_fx_scan,
 * 91 : MXUSBPD_MMIO_INST.pdbb_pwm_vin_ov_det_fx_scan,
 * 90 : MXUSBPD_MMIO_INST.pdbb_pwm_buck_comp_fx_scan,
 * 89 : MXUSBPD_MMIO_INST.pdbb_pwm_boost_comp_fx_scan,
 * 88 : MXUSBPD_MMIO_INST.pdbb_pwm_bb_comp_fx_scan,
 * 87 : MXUSBPD_MMIO_INST.pdbb_gdrvo_vbst_comp_fx_scan,
 * 86 : MXUSBPD_MMIO_INST.pdbb_gdrvo_hsrcp_fx_scan,
 * 85 : MXUSBPD_MMIO_INST.pdbb_gdrvi_vbst_comp_fx_scan,
 * 84 : MXUSBPD_MMIO_INST.pdbb_gdrvi_lszcd_fx_scan,
 * 83 : MXUSBPD_MMIO_INST.pdbb_ea_cc_det_fx_scan,
 * 82 : MXUSBPD_MMIO_INST.pdbb_ea_cv_det_fx_scan,
 * 81 : MXUSBPD_MMIO_INST.pdbb_pwm_out_blk_fx_scan,
 * 80 : MXUSBPD_MMIO_INST.vconn20_ctrl_en_pump,
 * 79 : MXUSBPD_MMIO_INST.vconn20_ctrl_en_switch_cc2,
 * 78 : MXUSBPD_MMIO_INST.vconn20_ctrl_en_switch_cc1,
 * 77 : MXUSBPD_MMIO_INST.vconn_bb_en_pump_ddft_faults_masked,
 * 76 : MXUSBPD_MMIO_INST.vconn_bb_en_pump_ddft_async_fault_det,
 * 75 : MXUSBPD_MMIO_INST.vconn_bb_en_switch_cc2_ddft_faults_masked,
 * 74 : MXUSBPD_MMIO_INST.vconn_bb_en_switch_cc2_ddft_async_fault_det,
 * 73 : MXUSBPD_MMIO_INST.vconn_bb_en_switch_cc1_ddft_faults_masked,
 * 72 : MXUSBPD_MMIO_INST.vconn_bb_en_switch_cc1_ddft_async_fault_det,
 * 71 : MXUSBPD_MMIO_INST.ngdo_bb_gdrv_en_ddft_faults_masked,
 * 70 : MXUSBPD_MMIO_INST.ngdo_bb_gdrv_en_ddft_async_fault_det,
 * 69 : MXUSBPD_MMIO_INST.cc2_ocp_fx,
 * 68 : MXUSBPD_MMIO_INST.cc1_ocp_fx,
 * 67 : MXUSBPD_MMIO_INST.cc2_ovp_fx,
 * 66 : MXUSBPD_MMIO_INST.cc1_ovp_fx,
 * 65 : MXUSBPD_MMIO_INST.v5v_fx,
 * 64 : MXUSBPD_MMIO_INST.bb_gdrvi_func_lszcd_in,
 * 63 : MXUSBPD_MMIO_INST.bb_gdrvi_func_en_hsdr1_test,
 * 62 : MXUSBPD_MMIO_INST.bb_gdrvi_lszcd_out_fx,
 * 61 : MXUSBPD_MMIO_INST.bb_gdrvi_func_lsdr1_sen_dig_out,
 * 60 : MXUSBPD_MMIO_INST.bb_gdrvi_func_en_hsdr1_dig_out,
 * 59 : MXUSBPD_MMIO_INST.bb_gdrvi_func_en_lsdr1_test,
 * 58 : MXUSBPD_MMIO_INST.bb_gdrvi_func_hsdr1_sen_dig_out,
 * 57 : MXUSBPD_MMIO_INST.bb_gdrvi_vbst_comp_out_fx,
 * 56 : MXUSBPD_MMIO_INST.bb_gdrvo_func_en_lsdr2_dig_out,
 * 55 : MXUSBPD_MMIO_INST.bb_mode_buck,
 * 54 : MXUSBPD_MMIO_INST.bb_gdrvo_func_en_lsdr2_test,
 * 53 : MXUSBPD_MMIO_INST.bb_gdrvo_func_lsdr2_sen_dig_out,
 * 52 : MXUSBPD_MMIO_INST.bb_mode_boost,
 * 51 : MXUSBPD_MMIO_INST.bb_gdrvo_hsrcp_out_fx,
 * 50 : MXUSBPD_MMIO_INST.bb_gdrvo_vbst_comp_out_fx,
 * 49 : MXUSBPD_MMIO_INST.bb_gdrvo_func_hsdr2_sen_dig_out,
 * 48 : MXUSBPD_MMIO_INST.bb_gdrvo_func_en_hsdr2_test,
 * 47 : MXUSBPD_MMIO_INST.bb_gdrvo_func_en_hsdr2_dig_out,
 * 46 : MXUSBPD_MMIO_INST.bb_gdrvo_func_hsrcp_in,
 * 45 : MXUSBPD_MMIO_INST.bb_gdrvo_func_hsrcp_good_dig_out,
 * 44 : MXUSBPD_MMIO_INST.bb_pwm_func_pwmcomp_rawout_lv,
 * 43 : MXUSBPD_MMIO_INST.bb_pwm_out_blk_filt,
 * 42 : MXUSBPD_MMIO_INST.bb_pwm_ilimit_det_rtl,
 * 41 : MXUSBPD_MMIO_INST.bb_pwm_func_vout_uv_det_lv,
 * 40 : MXUSBPD_MMIO_INST.bb_pwm_bbcomp_out_fx,
 * 39 : MXUSBPD_MMIO_INST.bb_pwm_ls2_pwm_minduty_det_fx,
 * 38 : MXUSBPD_MMIO_INST.bb_pwm_func_reset_boost,
 * 37 : MXUSBPD_MMIO_INST.bb_pwm_boostcomp_out_fx,
 * 36 : MXUSBPD_MMIO_INST.bb_pwm_buckcomp_out_fx,
 * 35 : MXUSBPD_MMIO_INST.bb_pwm_func_set_boost,
 * 34 : MXUSBPD_MMIO_INST.bb_pwm_ls2_pwm_maxduty_det_fx,
 * 33 : MXUSBPD_MMIO_INST.bb_pwm_func_boostcomp_out_rtl,
 * 32 : MXUSBPD_MMIO_INST.bb_pwm_func_hs2_pwm_lv,
 * 31 : MXUSBPD_MMIO_INST.bb_pwm_vin_ov_det_fx,
 * 30 : MXUSBPD_MMIO_INST.bb_pwm_func_pwmcomp_nos_out_lv,
 * 29 : MXUSBPD_MMIO_INST.bb_pwm_func_ls1_pwm_lv,
 * 28 : MXUSBPD_MMIO_INST.bb_pwm_func_pwmcomp_out_lv,
 * 27 : MXUSBPD_MMIO_INST.bb_pwm_skipcomp_out_fx,
 * 26 : MXUSBPD_MMIO_INST.bb_pwm_func_hs1_pwm_lv,
 * 25 : MXUSBPD_MMIO_INST.bb_pwm_func_buckcomp_out_rtl,
 * 24 : MXUSBPD_MMIO_INST.bb_pwm_func_ls2_pwm_lv,
 * 23 : MXUSBPD_MMIO_INST.bb_pwm_hs1_pwm_minduty_det_fx,
 * 22 : MXUSBPD_MMIO_INST.bb_pwm_func_bbcomp_out_rtl,
 * 21 : MXUSBPD_MMIO_INST.bb_pwm_func_reset_buck,
 * 20 : MXUSBPD_MMIO_INST.bb_pwm_hs1_pwm_maxduty_det_fx,
 * 19 : MXUSBPD_MMIO_INST.bb_pwm_vin_uv_det_fx,
 * 18 : MXUSBPD_MMIO_INST.bb_40csa_pwm_out_blk_fx,
 * 17 : MXUSBPD_MMIO_INST.bb_scomp_sw_lv,
 * 16 : MXUSBPD_MMIO_INST.bb_40csa_func_scap_rst_lv,
 * 15 : MXUSBPD_MMIO_INST.final_ilim_dig_fx,
 * 14 : MXUSBPD_MMIO_INST.bb_40csa_func_reset_sw1_lv,
 * 13 : MXUSBPD_MMIO_INST.bb_40csa_func_rst_sw1_rtl_lv,
 * 12 : MXUSBPD_MMIO_INST.bb_40csa_func_set_boost_lv,
 * 11 : MXUSBPD_MMIO_INST.bb_40csa_func_scap_rst_rtl_lv,
 * 10 : MXUSBPD_MMIO_INST.pds_ea_cc_flag_fx,
 * 09 : MXUSBPD_MMIO_INST.pds_ea_cv_det_fx,
 * 08 : MXUSBPD_MMIO_INST.pds_ea_cc_det_fx,
 * 07 : MXUSBPD_MMIO_INST.bb_40vreg_in_rush_det_fx,
 * 06 : MXUSBPD_MMIO_INST.bb_40vreg_vin_det_fx,
 * 05 : MXUSBPD_MMIO_INST.bb_20csa_itran_det_h2l_fx,
 * 04 : MXUSBPD_MMIO_INST.bb_20csa_itran_det_l2h_fx,
 * 03 : MXUSBPD_MMIO_INST.bb_20csa_sh_itrandet,
 * 02 : MXUSBPD_MMIO_INST.csa_scp_fx,
 * 01 : MXUSBPD_MMIO_INST.csa_ocp_fx,
 * 00 : MXUSBPD_MMIO_INST.pds_scp_fx
 */
#define PDSS_CCG7D_NCELL_DDFT_MUX_CCG7D_NCELL_DDFT1_SEL_MASK    (0x00007f00UL) /* <8:14> R:RW:0: */
#define PDSS_CCG7D_NCELL_DDFT_MUX_CCG7D_NCELL_DDFT1_SEL_POS    (8UL)


/*
 * CCG7D INTR DDFT Selections (NA in PMG1S3)
 */
#define PDSS_CCG7D_INTR_DDFT_MUX_ADDRESS                    (0x400a238cUL)
#define PDSS_CCG7D_INTR_DDFT_MUX                            (*(volatile uint32_t *)(0x400a238cUL))
#define PDSS_CCG7D_INTR_DDFT_MUX_DEFAULT                    (0x00000000UL)

/*
 * 28 : MXUSBPD_MMIO_INST.intr17_pdbb_cc2_scp,
 * 27 : MXUSBPD_MMIO_INST.intr17_pdbb_cc1_scp,
 * 26 : MXUSBPD_MMIO_INST.intr10_bbctrl_audio_tmax_timeout,
 * 25 : MXUSBPD_MMIO_INST.intr10_bbctrl_audio_tmin_timeout,
 * 24 : MXUSBPD_MMIO_INST.intr10_bbctrl_err_cond,
 * 23 : MXUSBPD_MMIO_INST.intr10_bbctrl_dcm_det,
 * 22 : MXUSBPD_MMIO_INST.intr10_bbctrl_min_duty_det,
 * 21 : MXUSBPD_MMIO_INST.intr10_bbctrl_max_duty_det,
 * 20 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_out_blk,
 * 19 : MXUSBPD_MMIO_INST.intr17_pdbb_ea_cv_det,
 * 18 : MXUSBPD_MMIO_INST.intr17_pdbb_ea_cc_det,
 * 17 : MXUSBPD_MMIO_INST.intr17_pdbb_gdrvi_lszcd,
 * 16 : MXUSBPD_MMIO_INST.intr17_pdbb_gdrvi_vbst_comp,
 * 15 : MXUSBPD_MMIO_INST.intr17_pdbb_gdrvo_hsrcp,
 * 14 : MXUSBPD_MMIO_INST.intr17_pdbb_gdrvo_vbst_comp,
 * 13 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_bb_comp,
 * 12 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_boost_comp,
 * 11 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_buck_comp,
 * 10 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_vin_ov_det,
 * 09 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_vin_uv_det,
 * 08 : 1'b0,
 * 07 : 1'b0,
 * 06 : 1'b0,
 * 05 : 1'b0,
 * 04 : MXUSBPD_MMIO_INST.intr17_pdbb_40csa_ilim_dig_out,
 * 03 : MXUSBPD_MMIO_INST.intr17_pdbb_20csa_itran_det_h2l,
 * 02 : MXUSBPD_MMIO_INST.intr17_pdbb_20csa_itran_det_l2h,
 * 01 : MXUSBPD_MMIO_INST.intr17_pdbb_40vreg_in_rush_det,
 * 00 : MXUSBPD_MMIO_INST.intr17_pdbb_40vreg_vin_det
 */
#define PDSS_CCG7D_INTR_DDFT_MUX_CCG7D_INTR_DDFT0_SEL_MASK    (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_CCG7D_INTR_DDFT_MUX_CCG7D_INTR_DDFT0_SEL_POS    (0UL)


/*
 * 28 : MXUSBPD_MMIO_INST.intr17_pdbb_cc2_scp,
 * 27 : MXUSBPD_MMIO_INST.intr17_pdbb_cc1_scp,
 * 26 : MXUSBPD_MMIO_INST.intr10_bbctrl_audio_tmax_timeout,
 * 25 : MXUSBPD_MMIO_INST.intr10_bbctrl_audio_tmin_timeout,
 * 24 : MXUSBPD_MMIO_INST.intr10_bbctrl_err_cond,
 * 23 : MXUSBPD_MMIO_INST.intr10_bbctrl_dcm_det,
 * 22 : MXUSBPD_MMIO_INST.intr10_bbctrl_min_duty_det,
 * 21 : MXUSBPD_MMIO_INST.intr10_bbctrl_max_duty_det,
 * 20 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_out_blk,
 * 19 : MXUSBPD_MMIO_INST.intr17_pdbb_ea_cv_det,
 * 18 : MXUSBPD_MMIO_INST.intr17_pdbb_ea_cc_det,
 * 17 : MXUSBPD_MMIO_INST.intr17_pdbb_gdrvi_lszcd,
 * 16 : MXUSBPD_MMIO_INST.intr17_pdbb_gdrvi_vbst_comp,
 * 15 : MXUSBPD_MMIO_INST.intr17_pdbb_gdrvo_hsrcp,
 * 14 : MXUSBPD_MMIO_INST.intr17_pdbb_gdrvo_vbst_comp,
 * 13 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_bb_comp,
 * 12 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_boost_comp,
 * 11 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_buck_comp,
 * 10 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_vin_ov_det,
 * 09 : MXUSBPD_MMIO_INST.intr17_pdbb_pwm_vin_uv_det,
 * 08 : 1'b0,
 * 07 : 1'b0,
 * 06 : 1'b0,
 * 05 : 1'b0,
 * 04 : MXUSBPD_MMIO_INST.intr17_pdbb_40csa_ilim_dig_out,
 * 03 : MXUSBPD_MMIO_INST.intr17_pdbb_20csa_itran_det_h2l,
 * 02 : MXUSBPD_MMIO_INST.intr17_pdbb_20csa_itran_det_l2h,
 * 01 : MXUSBPD_MMIO_INST.intr17_pdbb_40vreg_in_rush_det,
 * 00 : MXUSBPD_MMIO_INST.intr17_pdbb_40vreg_vin_det
 */
#define PDSS_CCG7D_INTR_DDFT_MUX_CCG7D_INTR_DDFT1_SEL_MASK    (0x00003f00UL) /* <8:13> R:RW:0: */
#define PDSS_CCG7D_INTR_DDFT_MUX_CCG7D_INTR_DDFT1_SEL_POS    (8UL)


/*
 * S8PDBB Hard IP NGDO gate driver for gdrv_en Register 0 (Only for CCG7D)
 * (NA in PMG1S3)
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_ADDRESS                 (0x400a2500UL)
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL                         (*(volatile uint32_t *)(0x400a2500UL))
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_DEFAULT                 (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gdrv_en  pin
 * 1: HW controlls the  gdrv_en  pin
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_AUTO_MODE               (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control option.
 * Any write-one to this register will reset the edge detector in the controller.
 * FW should cleared this register after the fault conditions are removed
 * by writing a "1" to this register.
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_RST_EDGE_DET            (1UL << 1) /* <1:1> R:RW:0: */


/*
 * 0: OCP detection is not selected for turning off the gdrv_en
 * 1: OCP detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CSA_OCP             (1UL << 2) /* <2:2> R:RW:0: */


/*
 * 0: VREG in rush detection is not selected for turning off the gdrv_en
 * 1: VREG in rush detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VREG_IN_RUSH        (1UL << 4) /* <4:4> R:RW:0: */


/*
 * CPU can used this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected.
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_ON_OFF              (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Bit[6]:
 * 0: FILT20 detection is not selected for turning off the gdrv_en
 * 1: FILT20 detection is       selected for turning off the gdrv_en
 * Bit[7]:
 * 0: FILT21 detection is not selected for turning off the gdrv_en
 * 1: FILT21 detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_FILT2_MASK          (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_FILT2_POS           (6UL)


/*
 * 0: CC1_OCP detection is not selected for turning off the gdrv_en
 * 1: CC1_OCP detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC1_OCP_FOR_BB      (1UL << 8) /* <8:8> R:RW:0: */


/*
 * 0: CC2_OCP detection is not selected for turning off the gdrv_en
 * 1: CC2_OCP detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC2_OCP_FOR_BB      (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 0: CC1_OVP detection is not selected for turning off the gdrv_en
 * 1: CC1_OVP detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC1_OVP_FOR_BB      (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 0: CC2_OVP detection is not selected for turning off the gdrv_en
 * 1: CC2_OVP detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC2_OVP_FOR_BB      (1UL << 11) /* <11:11> R:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gdrv_en bit
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_GDRV_EN_OFF_VALUE       (1UL << 17) /* <17:17> R:RW:0: */


/*
 * The ON value used by Hardware to turn on the gdrv_en bit
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_GDRV_EN_ON_VALUE        (1UL << 18) /* <18:18> R:RW:0: */


/*
 * 0: ILIM DIG is not selected for turning off the gdrv_en
 * 1: ILIM DIG is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_ILIM_DIG            (1UL << 19) /* <19:19> R:RW:0: */


/*
 * 0: CC1_SCP detection is not selected for turning off the gdrv_en
 * 1: CC1_SCP detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC1_SCP_FOR_BB      (1UL << 22) /* <22:22> R:RW:0: */


/*
 * 0: CC2_SCP detection is not selected for turning off the gdrv_en
 * 1: CC2_SCP detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC2_SCP_FOR_BB      (1UL << 23) /* <23:23> R:RW:0: */


/*
 * 0: VREG VDDD_BOD detection is not selected for turning off the gdrv_en
 * 1: VREG VDDD_BOD detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VREG_VDDD_BOD       (1UL << 24) /* <24:24> R:RW:0: */


/*
 * 0: SCP detection is not selected for turning off the gdrv_en
 * 1: SCP detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CSA_SCP             (1UL << 28) /* <28:28> R:RW:0: */


/*
 * 0: PDS SCP detection is not selected for turning off the gdrv_en
 * 1: PDS SCP detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_PDS_SCP             (1UL << 29) /* <29:29> R:RW:0: */


/*
 * 0: VIN_OV detection is not selected for turning off the gdrv_en
 * 1: VIN_OV detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VIN_OV_DET          (1UL << 30) /* <30:30> R:RW:0: */


/*
 * 0: VIN_UV detection is not selected for turning off the gdrv_en
 * 1: VIN_UV detection is       selected for turning off the gdrv_en
 */
#define PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VIN_UV_DET          (1UL << 31) /* <31:31> R:RW:0: */


/*
 * S8PDBB Hard IP NGDO gate driver for gdrv_en Register 1 (Only for CCG7D)
 * (NA in PMG1S3)
 */
#define PDSS_BB_NGDO_1_GDRV_EN_CTRL_ADDRESS                 (0x400a2504UL)
#define PDSS_BB_NGDO_1_GDRV_EN_CTRL                         (*(volatile uint32_t *)(0x400a2504UL))
#define PDSS_BB_NGDO_1_GDRV_EN_CTRL_DEFAULT                 (0x00000000UL)

/*
 * There can be a maximum of 24 HS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function
 */
#define PDSS_BB_NGDO_1_GDRV_EN_CTRL_HS_SOURCE_SEL_MASK      (0x0000001fUL) /* <0:4> R:RW:0:CLK_FILTER_FILT_NUM */
#define PDSS_BB_NGDO_1_GDRV_EN_CTRL_HS_SOURCE_SEL_POS       (0UL)


/*
 * There can be a maximum of 8 LS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function.
 */
#define PDSS_BB_NGDO_1_GDRV_EN_CTRL_LS_SOURCE_SEL_MASK      (0x03000000UL) /* <24:25> R:RW:0:CLK_LF_FILT_NUM */
#define PDSS_BB_NGDO_1_GDRV_EN_CTRL_LS_SOURCE_SEL_POS       (24UL)


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
#define PDSS_TRIM_CC_3_DEFAULT                              (0x00000000UL)

/*
 * Trim bits for 0.5V comparator reference. Default is 0.53. Check BROS for
 * complete description of the steps.
 * This should be programmed to 0x2 for CCG2*A Silicon. Leave default for
 * ** silicon.
 * Notes: This filed should be 0x2 for all application (DFP,UFP,AMA ,cable)
 */
#define PDSS_TRIM_CC_3_V0P5_TRIM_MASK                       (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_CC_3_V0P5_TRIM_POS                        (0UL)


/*
 * Trim bits for 0.655V comparator reference. Default value is 0.6475V
 */
#define PDSS_TRIM_CC_3_V0P655_TRIM_MASK                     (0x00000038UL) /* <3:5> R:RW:0: */
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
#define PDSS_TRIM_CC_7_DEFAULT                              (0x00000000UL)

/*
 * Trim bits for 1.97V comparator reference. Default value being 2.09V. Check
 * BROS for complete description for the trim.
 */
#define PDSS_TRIM_CC_7_V1P97_TRIM_MASK                      (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_CC_7_V1P97_TRIM_POS                       (0UL)


/*
 * USBPD Hard IP Spare0 Trim Register
 */
#define PDSS_TRIM_SPARE0_ADDRESS                            (0x400aff20UL)
#define PDSS_TRIM_SPARE0                                    (*(volatile uint32_t *)(0x400aff20UL))
#define PDSS_TRIM_SPARE0_DEFAULT                            (0x00000000UL)

/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_TRIM_SPARE0_SPARE0_TRIM_MASK                   (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_TRIM_SPARE0_SPARE0_TRIM_POS                    (0UL)


/*
 * USBPD Hard IP Spare1 Trim Register
 */
#define PDSS_TRIM_SPARE1_ADDRESS                            (0x400aff24UL)
#define PDSS_TRIM_SPARE1                                    (*(volatile uint32_t *)(0x400aff24UL))
#define PDSS_TRIM_SPARE1_DEFAULT                            (0x00000000UL)

/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_TRIM_SPARE1_SPARE1_TRIM_MASK                   (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_TRIM_SPARE1_SPARE1_TRIM_POS                    (0UL)


/*
 * USBPD Hard IP 5V PUMP#1 trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_5VPUMP1_0_ADDRESS                         (0x400aff28UL)
#define PDSS_TRIM_5VPUMP1_0                                 (*(volatile uint32_t *)(0x400aff28UL))
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
#define PDSS_TRIM_5VPUMP1_1_ADDRESS                         (0x400aff2cUL)
#define PDSS_TRIM_5VPUMP1_1                                 (*(volatile uint32_t *)(0x400aff2cUL))
#define PDSS_TRIM_5VPUMP1_1_DEFAULT                         (0x00000005UL)

/*
 * Trim to change the charge pump output voltage by modifying the resistance
 * in the feed back divider
 */
#define PDSS_TRIM_5VPUMP1_1_V5PUMP_PUMP_TRIM3_0_MASK        (0x0000000fUL) /* <0:3> R:RW:5: */
#define PDSS_TRIM_5VPUMP1_1_V5PUMP_PUMP_TRIM3_0_POS         (0UL)


/*
 * USBPD Hard IP Deep Sleep   Trim Register0. Production trims stored in
 * flash
 */
#define PDSS_TRIM_DPSLP_0_ADDRESS                           (0x400aff30UL)
#define PDSS_TRIM_DPSLP_0                                   (*(volatile uint32_t *)(0x400aff30UL))
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
#define PDSS_TRIM_DPSLP_1_ADDRESS                           (0x400aff34UL)
#define PDSS_TRIM_DPSLP_1                                   (*(volatile uint32_t *)(0x400aff34UL))
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
 * USBPD Hard IP NGDO Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_NGDO_0_ADDRESS                            (0x400aff40UL)
#define PDSS_TRIM_NGDO_0                                    (*(volatile uint32_t *)(0x400aff40UL))
#define PDSS_TRIM_NGDO_0_DEFAULT                            (0x00000002UL)

/*
 * Trim the charge pump oscillator frequency,pump regulator bias current
 *
 * Trim charge pump Oscillator current (TRIM_OSC<2:0>)
 * 000 --> 1.8uA
 * 001 --> 2.4uA
 * 010 --> 3.0uA (Default)
 * 011 --> 3.6uA
 * 100 --> 4.2uA
 * 101 --> 4.8uA
 * 110 --> 5.4uA
 * 111 --> 6.0uA
 *
 * Trim charge pump Regulator iload (TRIM_OSC<3>)
 * 0 --> 5uA (Default)
 * 1 --> 0
 *
 * Trim charge pump Regulator bias current (TRIM_OSC<5:4>)
 * 00 --> 4.8uA (Default)
 * 01 --> 2.4uA
 * 10 --> 9.6uA
 * 11 --> 7.2uA
 *
 * Trim charge pump opamp bias current(TRIM_OSC<7:6>)
 * 00  --> 1.2uA(Default)
 * 01 -->  0.6uA
 * 10 -->  2.4uA
 * 11 --> 1.8uA
 */
#define PDSS_TRIM_NGDO_0_TRIM_OSC_MASK                      (0x000000ffUL) /* <0:7> R:RW:2: */
#define PDSS_TRIM_NGDO_0_TRIM_OSC_POS                       (0UL)


/*
 * USBPD Hard IP NGDO Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_NGDO_1_ADDRESS                            (0x400aff44UL)
#define PDSS_TRIM_NGDO_1                                    (*(volatile uint32_t *)(0x400aff44UL))
#define PDSS_TRIM_NGDO_1_DEFAULT                            (0x00000000UL)

/*
 * Trim the charge pump output voltage
 *
 * TRIM_PUMP [3:0] --> vboost=(vpump-v5v)
 * 0000--> 5.89(Default)
 * 0001--> 5.72
 * 0010--> 5.53
 * 0011--> 5.37
 * 0100--> 5.17
 * 0101--> 5.02
 * 0110--> 4.86
 * 0111--> 4.74
 * 1000--> 7.82
 * 1001--> 7.57
 * 1010--> 7.29
 * 1011--> 7.05
 * 1100--> 6.77
 * 1101--> 6.56
 * 1110--> 6.33
 * 1111--> 6.14
 */
#define PDSS_TRIM_NGDO_1_TRIM_PUMP_MASK                     (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_NGDO_1_TRIM_PUMP_POS                      (0UL)


/*
 * USBPD Hard IP battery charger Detect#1 Trim Register 0. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET1_0_ADDRESS                        (0x400aff48UL)
#define PDSS_TRIM_BCH_DET1_0                                (*(volatile uint32_t *)(0x400aff48UL))
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
#define PDSS_TRIM_BCH_DET1_1_ADDRESS                        (0x400aff4cUL)
#define PDSS_TRIM_BCH_DET1_1                                (*(volatile uint32_t *)(0x400aff4cUL))
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
#define PDSS_TRIM_BCH_DET1_2_ADDRESS                        (0x400aff50UL)
#define PDSS_TRIM_BCH_DET1_2                                (*(volatile uint32_t *)(0x400aff50UL))
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
#define PDSS_TRIM_BCH_DET1_3_ADDRESS                        (0x400aff54UL)
#define PDSS_TRIM_BCH_DET1_3                                (*(volatile uint32_t *)(0x400aff54UL))
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
 * USBPD Hard IP PDS SCP Trim Register1. Production trims stored in flash
 */
#define PDSS_TRIM_SCP_ADDRESS                               (0x400aff58UL)
#define PDSS_TRIM_SCP                                       (*(volatile uint32_t *)(0x400aff58UL))
#define PDSS_TRIM_SCP_DEFAULT                               (0x0000001fUL)

/*
 * Trim bits for SCP offset to for 6A SCP (30mV with external 5mohm Rsense)
 */
#define PDSS_TRIM_SCP_SCP_TRIM_MASK                         (0x0000003fUL) /* <0:5> R:RW:31: */
#define PDSS_TRIM_SCP_SCP_TRIM_POS                          (0UL)


/*
 * USBPD Hard IP 20V VCONN trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_BB_20VCONN_0_ADDRESS                      (0x400aff5cUL)
#define PDSS_TRIM_BB_20VCONN_0                              (*(volatile uint32_t *)(0x400aff5cUL))
#define PDSS_TRIM_BB_20VCONN_0_DEFAULT                      (0x00000000UL)

/*
 * Trim the charge pump output voltage
 *
 * BB_20VCONN_PUMP_TRIM [3:0] --> vboost=(vpump-v5v)
 * 0000--> 5.20(Default)
 * 0001--> 5.00
 * 0010--> 4.81
 * 0011--> 4.64
 * 0100--> 4.47
 * 0101--> 4.33
 * 0110--> 4.18
 * 0111--> 4.05
 * 1000--> 7.65
 * 1001--> 7.24
 * 1010--> 6.85
 * 1011--> 6.52
 * 1100--> 6.20
 * 1101--> 5.92
 * 1110--> 5.66
 * 1111--> 5.43
 */
#define PDSS_TRIM_BB_20VCONN_0_BB_20VCONN_PUMP_TRIM_MASK    (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_BB_20VCONN_0_BB_20VCONN_PUMP_TRIM_POS     (0UL)


/*
 * Trim  over voltage detection trip  voltage
 * BB_20VCONN_OVP_TRIM [7:4 ]= the accurate OVP detection scheme is disabled,
 * these trim bits are no longer used
 */
#define PDSS_TRIM_BB_20VCONN_0_BB_20VCONN_OVP_TRIM_MASK     (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_TRIM_BB_20VCONN_0_BB_20VCONN_OVP_TRIM_POS      (4UL)


/*
 * USBPD Hard IP 20V VCONN trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_BB_20VCONN_1_ADDRESS                      (0x400aff60UL)
#define PDSS_TRIM_BB_20VCONN_1                              (*(volatile uint32_t *)(0x400aff60UL))
#define PDSS_TRIM_BB_20VCONN_1_DEFAULT                      (0x00000000UL)

/*
 * Trim the charge pump oscillator frequency,pump regulator bias current
 *
 * Trim charge pump Oscillator current (BB_20VCONN_OSC_TRIM<2:0>)
 * 000 --> 2.4uA (Default)
 * 001 --> 1.8uA
 * 010 --> 1.2uA
 * 011 --> 0.6uA
 * 100 --> 4.8uA
 * 101 --> 4.2uA
 * 110 --> 3.6uA
 * 111 --> 3.0uA
 *
 * Trim charge pump Regulator iload (BB_20VCONN_OSC_TRIM<3>)
 * 0 --> 5uA (Default)
 * 1 --> 0
 *
 * Trim charge pump Regulator bias current (BB_20VCONN_OSC_TRIM<5:4>)
 * 00 --> 4.8uA (Default)
 * 01 --> 2.4uA
 * 10 --> 9.6uA
 * 11 --> 7.2uA
 *
 * Trim charge pump opamp bias current(BB_20VCONN_OSC_TRIM<7:6>)
 * 00  --> 1.2uA(Default)
 * 01 -->  0.6uA
 * 10 -->  2.4uA
 * 11 -->  1.8uA
 */
#define PDSS_TRIM_BB_20VCONN_1_BB_20VCONN_OSC_TRIM_MASK     (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_TRIM_BB_20VCONN_1_BB_20VCONN_OSC_TRIM_POS      (0UL)


/*
 * USBPD Hard IP 20V VCONN trim Register 2. Production trims stored in flash
 */
#define PDSS_TRIM_BB_20VCONN_2_ADDRESS                      (0x400aff64UL)
#define PDSS_TRIM_BB_20VCONN_2                              (*(volatile uint32_t *)(0x400aff64UL))
#define PDSS_TRIM_BB_20VCONN_2_DEFAULT                      (0x00000088UL)

/*
 * Trim bits to change the OCP trip point
 * 0000 - unused
 * 0001 - 1.2u (4.8mA)
 * 0010 - 2.4u (9.6mA)
 * 0100 - 4.8u (19.2 mA)
 * 1000 -  7.2u (28.8 mA)
 * 1111 - 15.6u (62.4 mA)
 */
#define PDSS_TRIM_BB_20VCONN_2_BB_20VCONN_OCP_TRIM_MASK     (0x0000000fUL) /* <0:3> R:RW:8: */
#define PDSS_TRIM_BB_20VCONN_2_BB_20VCONN_OCP_TRIM_POS      (0UL)


/*
 * BB_20VCONN_SCP_TRIM[3] :
 * bit gates the scp_out, when set to 0 it gates the scp_out
 * BB_20VCONN_SCP_TRIM[2:0]:
 *  Trim bits to change the SCP trip point
 * 000 - unused
 * 001 - 4.8u (19.2mA)
 * 010 - 9.6u (38.4 mA)
 * 100 - 14.4u (57.6 mA)
 * 111 - 28.8u (115.20 mA)
 */
#define PDSS_TRIM_BB_20VCONN_2_BB_20VCONN_SCP_TRIM_MASK     (0x000000f0UL) /* <4:7> R:RW:8: */
#define PDSS_TRIM_BB_20VCONN_2_BB_20VCONN_SCP_TRIM_POS      (4UL)


/*
 * USBPD Hard IP 20V VCONN trim Register 3. Production trims stored in flash
 */
#define PDSS_TRIM_BB_20VCONN_3_ADDRESS                      (0x400aff68UL)
#define PDSS_TRIM_BB_20VCONN_3                              (*(volatile uint32_t *)(0x400aff68UL))
#define PDSS_TRIM_BB_20VCONN_3_DEFAULT                      (0x00000002UL)

/*
 * Control the ramp rate of inrush control by controlling the charging current
 * 0000 - 0nA
 * 0001 - 50nA
 * 0010 - 100nA
 * 0100 - 200nA
 * 1000 - 400nA
 * 1111 - 750nA
 */
#define PDSS_TRIM_BB_20VCONN_3_BB_20VCONN_INRUSH_MASK       (0x0000000fUL) /* <0:3> R:RW:2: */
#define PDSS_TRIM_BB_20VCONN_3_BB_20VCONN_INRUSH_POS        (0UL)


/*
 * BB_20VCONN_RESV[1]  is unused
 * BB_20VCONN_RESV[0] bit used to toggle the OCP tap point
 * 0 : middle node is used as OCP ref point
 * 1 : end node is used as OCP ref pint
 */
#define PDSS_TRIM_BB_20VCONN_3_BB_20VCONN_RESV_MASK         (0x00000030UL) /* <4:5> R:RW:0: */
#define PDSS_TRIM_BB_20VCONN_3_BB_20VCONN_RESV_POS          (4UL)


/*
 * USBPD Hard IP BB 20CSA Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_BB_20CSA_0_ADDRESS                        (0x400aff6cUL)
#define PDSS_TRIM_BB_20CSA_0                                (*(volatile uint32_t *)(0x400aff6cUL))
#define PDSS_TRIM_BB_20CSA_0_DEFAULT                        (0x00000000UL)

/*
 * trims bits to alter hysteresis of itrandet_h2l comparator
 * <5> <4:0>
 * 0       0      default
 * 0       N    -N*Trim_Step
 * 1       0      default
 * 1       N     +N*Trim_Step
 * Trim_step=2mv
 */
#define PDSS_TRIM_BB_20CSA_0_TR_ITRANCOMP_H2L_VIOS_MASK     (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_TRIM_BB_20CSA_0_TR_ITRANCOMP_H2L_VIOS_POS      (0UL)


/*
 * USBPD Hard IP BB 20CSA Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_BB_20CSA_1_ADDRESS                        (0x400aff70UL)
#define PDSS_TRIM_BB_20CSA_1                                (*(volatile uint32_t *)(0x400aff70UL))
#define PDSS_TRIM_BB_20CSA_1_DEFAULT                        (0x00000000UL)

/*
 * trims bits to alter hysteresis of itrandet_l2h comparator
 * <4> <3:0>
 * 0       0        default
 * 0       N       -N*Trim_Step
 * 1       0        default
 * 1       N       +N*Trim_Step
 * Trim_step=2mv
 */
#define PDSS_TRIM_BB_20CSA_1_TR_ITRANCOMP_L2H_VIOS_MASK     (0x0000001fUL) /* <0:4> R:RW:0: */
#define PDSS_TRIM_BB_20CSA_1_TR_ITRANCOMP_L2H_VIOS_POS      (0UL)


/*
 * USBPD Hard IP BB 20CSA Trim Register 2. Production trims stored in flash
 */
#define PDSS_TRIM_BB_20CSA_2_ADDRESS                        (0x400aff74UL)
#define PDSS_TRIM_BB_20CSA_2                                (*(volatile uint32_t *)(0x400aff74UL))
#define PDSS_TRIM_BB_20CSA_2_DEFAULT                        (0x00000000UL)

/*
 * Trim bits to trim for stage1 input referred offset
 * [4]   [3:0]
 * 0     0       default
 * 0     N      -N*Vios1_Trim_Step
 * 1     0        default
 * 1     N      +N*Vios1_Trim_Step
 * Trim_step=0.43mV
 */
#define PDSS_TRIM_BB_20CSA_2_OS_EL_MASK                     (0x0000001fUL) /* <0:4> R:RW:0: */
#define PDSS_TRIM_BB_20CSA_2_OS_EL_POS                      (0UL)


/*
 * USBPD Hard IP BB 20CSA Trim Register 3. Production trims stored in flash
 */
#define PDSS_TRIM_BB_20CSA_3_ADDRESS                        (0x400aff78UL)
#define PDSS_TRIM_BB_20CSA_3                                (*(volatile uint32_t *)(0x400aff78UL))
#define PDSS_TRIM_BB_20CSA_3_DEFAULT                        (0x00000000UL)

/*
 * Trim for INP divide 10% tap point
 * [3]    [2:0]
 * 0      0         default
 * 0      N        -N*Inp_Div_Trim_Step
 * 1      0         default
 * 1      N        +N*Inp_Div_Trim_Step
 * Trim_step=0.7%
 */
#define PDSS_TRIM_BB_20CSA_3_INP_DIV_TR_MASK                (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_BB_20CSA_3_INP_DIV_TR_POS                 (0UL)


/*
 * USBPD Hard IP BB 40VREG Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_BB_40VREG_0_ADDRESS                       (0x400aff7cUL)
#define PDSS_TRIM_BB_40VREG_0                               (*(volatile uint32_t *)(0x400aff7cUL))
#define PDSS_TRIM_BB_40VREG_0_DEFAULT                       (0x00000005UL)

/*
 * Main trim for vreg_out (vddd) with the resolution of 100mV. Vreg_out increases
 * linearly from 4.5v (VREG_MAIN_TRIM = 0x0) to 5.5v (VREG_MAIN_TRIM = 0xA)
 */
#define PDSS_TRIM_BB_40VREG_0_VREG_MAIN_TRIM_MASK           (0x0000000fUL) /* <0:3> R:RW:5: */
#define PDSS_TRIM_BB_40VREG_0_VREG_MAIN_TRIM_POS            (0UL)


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
#define PDSS_TRIM_BB_40VREG_0_VREG_FINE_TRIM_MASK           (0x00000070UL) /* <4:6> R:RW:0: */
#define PDSS_TRIM_BB_40VREG_0_VREG_FINE_TRIM_POS            (4UL)


/*
 * USBPD Hard IP BB 40VREG Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_BB_40VREG_1_ADDRESS                       (0x400aff80UL)
#define PDSS_TRIM_BB_40VREG_1                               (*(volatile uint32_t *)(0x400aff80UL))
#define PDSS_TRIM_BB_40VREG_1_DEFAULT                       (0x0000000bUL)

/*
 * 40Vreg Inrush trimming register with trim step = 10*(1+inrush_det_sel<1:0>)mA;
 * Inrush linearly increases with trim setting.
 */
#define PDSS_TRIM_BB_40VREG_1_VREG_TRIM_INRUSH_MASK         (0x0000000fUL) /* <0:3> R:RW:11: */
#define PDSS_TRIM_BB_40VREG_1_VREG_TRIM_INRUSH_POS          (0UL)


/*
 * USBPD Hard IP BB EA Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_BB_EA_0_ADDRESS                           (0x400aff84UL)
#define PDSS_TRIM_BB_EA_0                                   (*(volatile uint32_t *)(0x400aff84UL))
#define PDSS_TRIM_BB_EA_0_DEFAULT                           (0x00000020UL)

/*
 * Trim bits to alter IDAC current resolution which would change VBUS resolution.
 * 000000 - 0
 * 000001 - 3.75n
 * 000010 - 7.5n
 * 000100 - 15n
 * 001000 - 30n
 * 010000 - 60n
 * 100000 - 120n
 * 111111 - 236.25n
 */
#define PDSS_TRIM_BB_EA_0_TRIM_IREF_CV_MASK                 (0x000000ffUL) /* <0:7> R:RW:32: */
#define PDSS_TRIM_BB_EA_0_TRIM_IREF_CV_POS                  (0UL)


/*
 * USBPD Hard IP BB EA Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_BB_EA_1_ADDRESS                           (0x400aff88UL)
#define PDSS_TRIM_BB_EA_1                                   (*(volatile uint32_t *)(0x400aff88UL))
#define PDSS_TRIM_BB_EA_1_DEFAULT                           (0x0000000aUL)

/*
 * Trims to change the Gm of CV amplifier. Enables the parallel sinks connected
 * to pad_ea_out.
 * 00000 - 100us;
 * 00001 - 150us;
 * 00010 - 200us;
 * 00100 - 300us;
 * 01000 - 500us;
 * 10000 - 900us;
 * 11111 - 1650us
 */
#define PDSS_TRIM_BB_EA_1_TRIM_GM_CV_MASK                   (0x0000001fUL) /* <0:4> R:RW:10: */
#define PDSS_TRIM_BB_EA_1_TRIM_GM_CV_POS                    (0UL)


/*
 * USBPD Hard IP BB EA Trim Register 2. Production trims stored in flash
 */
#define PDSS_TRIM_BB_EA_2_ADDRESS                           (0x400aff8cUL)
#define PDSS_TRIM_BB_EA_2                                   (*(volatile uint32_t *)(0x400aff8cUL))
#define PDSS_TRIM_BB_EA_2_DEFAULT                           (0x0000000aUL)

/*
 * Trims to change the Gm of CV amplifier. Enables the parallel sinks connected
 * to pad_ea_out.
 * 00000 - 100us;
 * 00001 - 150us;
 * 00010 - 200us;
 * 00100 - 300us;
 * 01000 - 500us;
 * 10000 - 900us;
 * 11111 - 1650us
 */
#define PDSS_TRIM_BB_EA_2_TRIM_GM_CC_MASK                   (0x0000001fUL) /* <0:4> R:RW:10: */
#define PDSS_TRIM_BB_EA_2_TRIM_GM_CC_POS                    (0UL)


/*
 * USBPD Hard IP BB EA Trim Register 3. Production trims stored in flash
 */
#define PDSS_TRIM_BB_EA_3_ADDRESS                           (0x400aff90UL)
#define PDSS_TRIM_BB_EA_3                                   (*(volatile uint32_t *)(0x400aff90UL))
#define PDSS_TRIM_BB_EA_3_DEFAULT                           (0x00000007UL)

/*
 * Trim to change the betamultiplier current by trimming resistor of betamultiplier
 * (more the resistance lesser the current)
 * 0000 - 0.957uA
 * 0001 - 1.067uA
 * 0010 - 1.2uA
 * 0100 - 1.536uA
 * 1000 - 2.856uA
 * 1111 - 7.6 uA
 */
#define PDSS_TRIM_BB_EA_3_TRIM_BMULT_RES_MASK               (0x0000000fUL) /* <0:3> R:RW:7: */
#define PDSS_TRIM_BB_EA_3_TRIM_BMULT_RES_POS                (0UL)


/*
 * USBPD Hard IP BB 40CSA Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_BB_40CSA_0_ADDRESS                        (0x400aff94UL)
#define PDSS_TRIM_BB_40CSA_0                                (*(volatile uint32_t *)(0x400aff94UL))
#define PDSS_TRIM_BB_40CSA_0_DEFAULT                        (0x00000000UL)

/*
 * trim_csa_off<3> : Steers the offset current b/w cspin and csnin
 * trim_csa_off<2:0>
 * 000= 0uA
 * 001=2.5uA
 * 010=5uA
 * 011=7.5uA
 * 100=10uA
 * 101=12.5uA
 * 110=15uA
 * 111=17.5uA
 */
#define PDSS_TRIM_BB_40CSA_0_TRIM_CSA_OFF_MASK              (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_BB_40CSA_0_TRIM_CSA_OFF_POS               (0UL)


/*
 * USBPD Hard IP BB 40CSA Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_BB_40CSA_1_ADDRESS                        (0x400aff98UL)
#define PDSS_TRIM_BB_40CSA_1                                (*(volatile uint32_t *)(0x400aff98UL))
#define PDSS_TRIM_BB_40CSA_1_DEFAULT                        (0x00000010UL)

/*
 * Slope correction bits which changes the NMOS DAC current to compensate
 * the slope cap process variation. Trim stee ~ 2.5%
 * 00000 - S0-40%
 * 01110 - S0-5%
 * 01111 - S0-2.5%
 * 10000 - S0
 * 10001 - S0+2.5%
 * 10010 - S0+5%
 * 11111 - S0+37.5%
 */
#define PDSS_TRIM_BB_40CSA_1_TRIM_BIAS_MASK                 (0x0000001fUL) /* <0:4> R:RW:16: */
#define PDSS_TRIM_BB_40CSA_1_TRIM_BIAS_POS                  (0UL)


/*
 * USBPD Hard IP BB 40CSA Trim Register 2. Production trims stored in flash
 */
#define PDSS_TRIM_BB_40CSA_2_ADDRESS                        (0x400aff9cUL)
#define PDSS_TRIM_BB_40CSA_2                                (*(volatile uint32_t *)(0x400aff9cUL))
#define PDSS_TRIM_BB_40CSA_2_DEFAULT                        (0x0000000bUL)

/*
 * Resistor trim bits to correct the voutbyr resistance process variation
 * Trim step - 0.795k
 * Trimbits - Iadft current
 * 0d - 42.18k-(11*0.795k)
 * 1d - 42.18k-(10*0.795k)
 * 2d - 42.18k-(9*0.795k)
 * 9d - 42.18k-(2*0.795k)
 * 10d - 42.18k-0.795k
 * 11d - 42.18k
 * 12d - 42.18k+0.795k
 * 13d - 42.18k+(2*0.795k)
 * 29d- 42.18k+(18*0.795k)
 * 30d -42.18k+(19*0.795k)
 * 31d -42.18k+(20*0.795k)
 */
#define PDSS_TRIM_BB_40CSA_2_TRIM_VOUTBYR_MASK              (0x0000001fUL) /* <0:4> R:RW:11: */
#define PDSS_TRIM_BB_40CSA_2_TRIM_VOUTBYR_POS               (0UL)


/*
 * USBPD Hard IP BB PWM Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_BB_PWM_0_ADDRESS                          (0x400affa0UL)
#define PDSS_TRIM_BB_PWM_0                                  (*(volatile uint32_t *)(0x400affa0UL))
#define PDSS_TRIM_BB_PWM_0_DEFAULT                          (0x00000008UL)

/*
 * trim bits to trim bb comparator detection threshold for accuracy. 4''b1000=
 * default:
 * <3> <2:0>
 * 0      N        Default +N*Inp_Div_Trim_Step
 * 1      0         Default
 * 1      N        Default -N*Inp_Div_Trim_Step
 * Trim_step=0.5%
 */
#define PDSS_TRIM_BB_PWM_0_TR_VIN_RESDIV_SEL_BB_MASK        (0x0000000fUL) /* <0:3> R:RW:8: */
#define PDSS_TRIM_BB_PWM_0_TR_VIN_RESDIV_SEL_BB_POS         (0UL)


/*
 * USBPD Hard IP BB PWM Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_BB_PWM_1_ADDRESS                          (0x400affa4UL)
#define PDSS_TRIM_BB_PWM_1                                  (*(volatile uint32_t *)(0x400affa4UL))
#define PDSS_TRIM_BB_PWM_1_DEFAULT                          (0x00000000UL)

/*
 * trim bits to trim offset of spare PWM comparator.
 * 5''b00000= default
 * <4> <3:0>
 * 0      N        -N*Trim_Step
 * 1      N        +(16-N)*Trim_Step
 * Trim_step=0.45mv
 */
#define PDSS_TRIM_BB_PWM_1_TR_PWMCOMP_NOS_OS_MASK           (0x0000001fUL) /* <0:4> R:RW:0: */
#define PDSS_TRIM_BB_PWM_1_TR_PWMCOMP_NOS_OS_POS            (0UL)


/*
 * USBPD Hard IP BB PWM Trim Register 2. Production trims stored in flash
 */
#define PDSS_TRIM_BB_PWM_2_ADDRESS                          (0x400affa8UL)
#define PDSS_TRIM_BB_PWM_2                                  (*(volatile uint32_t *)(0x400affa8UL))
#define PDSS_TRIM_BB_PWM_2_DEFAULT                          (0x00000000UL)

/*
 * trim bits to trim offset of PWM comparator.
 * 5''b00000= default
 * <4> <3:0>
 * 0      N        -N*Trim_Step
 * 1      N        +(16-N)*Trim_Step
 * Trim_step=0.45mv
 */
#define PDSS_TRIM_BB_PWM_2_TR_PWMCOMP_OS_MASK               (0x0000001fUL) /* <0:4> R:RW:0: */
#define PDSS_TRIM_BB_PWM_2_TR_PWMCOMP_OS_POS                (0UL)


/*
 * USBPD Hard IP BB PWM Trim Register 3. Production trims stored in flash
 */
#define PDSS_TRIM_BB_PWM_3_ADDRESS                          (0x400affacUL)
#define PDSS_TRIM_BB_PWM_3                                  (*(volatile uint32_t *)(0x400affacUL))
#define PDSS_TRIM_BB_PWM_3_DEFAULT                          (0x00000088UL)

/*
 * trim bits to trim boost comparator detection threshold for accuracy. 
 * 4''b1000= default
 * <3> <2:0>
 * 0      N        Default +N*Inp_Div_Trim_Step
 * 1      0         Default
 * 1      N        Default -N*Inp_Div_Trim_Step
 * Trim_step=0.5%
 */
#define PDSS_TRIM_BB_PWM_3_TR_VIN_RESDIV_SEL_BOOST_MASK     (0x0000000fUL) /* <0:3> R:RW:8: */
#define PDSS_TRIM_BB_PWM_3_TR_VIN_RESDIV_SEL_BOOST_POS      (0UL)


/*
 * trim bits to trim buck comparator detection threshold for accuracy. 4''b1000=
 * default
 * <3> <2:0>
 * 0      N        Default +N*Inp_Div_Trim_Step
 * 1      0         Default
 * 1      N        Default -N*Inp_Div_Trim_Step
 * Trim_step=0.5%
 */
#define PDSS_TRIM_BB_PWM_3_TR_VIN_RESDIV_SEL_BUCK_MASK      (0x000000f0UL) /* <4:7> R:RW:8: */
#define PDSS_TRIM_BB_PWM_3_TR_VIN_RESDIV_SEL_BUCK_POS       (4UL)


/*
 * USBPD Hard IP BB GDRVO Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_BB_GDRVO_0_ADDRESS                        (0x400affb0UL)
#define PDSS_TRIM_BB_GDRVO_0                                (*(volatile uint32_t *)(0x400affb0UL))
#define PDSS_TRIM_BB_GDRVO_0_DEFAULT                        (0x00000019UL)

/*
 * VBST under-voltage detection comparator trim bits:
 * <7:6> : Spare
 * <5:0> : trim bits with resolution of 40mV
 * 6'b000000 = 40mV
 * 6'b000001 = 80mV
 * ...
 * 6'b011001 = 1040mV (Default)
 * ....
 * 6'b011111 = 1280mV
 * 6'b100000 = 680mV
 * 6'b100001 = 720mV
 * ...
 * 6'b111111 = 1920mV
 */
#define PDSS_TRIM_BB_GDRVO_0_TRIM_VBST_COMP_MASK            (0x000000ffUL) /* <0:7> R:RW:25: */
#define PDSS_TRIM_BB_GDRVO_0_TRIM_VBST_COMP_POS             (0UL)


/*
 * USBPD Hard IP BB GDRVO Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_BB_GDRVO_1_ADDRESS                        (0x400affb4UL)
#define PDSS_TRIM_BB_GDRVO_1                                (*(volatile uint32_t *)(0x400affb4UL))
#define PDSS_TRIM_BB_GDRVO_1_DEFAULT                        (0x0000001bUL)

/*
 * HSRCP comparator trim bits:
 * <7:6> : Spare
 * <5:0> : trim bits with resolution of 0.6mV
 * 6'b000000 = 18.6mV
 * 6'b000001 = 18.0mV
 * ...
 * 6'b011011 = 2.4mV (default)
 * 6'b011100 = 1.8mV
 * 6'b011101 = 1.2mV
 * 6'b011110 = 0.6mV
 * 6'b011111 = 0.0mV
 * 6'b100000 = 0.0mV
 * 6'b100001 = -0.6mV
 * 6'b100010 = -1.2mV
 * 6'b100011 = -1.8mV
 * 6'b100100 = -2.4mV
 * ...
 * 6'b111110 = -18.0mV
 * 6'b111111 = -18.6mV
 */
#define PDSS_TRIM_BB_GDRVO_1_TRIM_HSRCP_MASK                (0x000000ffUL) /* <0:7> R:RW:27: */
#define PDSS_TRIM_BB_GDRVO_1_TRIM_HSRCP_POS                 (0UL)


/*
 * USBPD Hard IP BB GDRVI Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_BB_GDRVI_0_ADDRESS                        (0x400affb8UL)
#define PDSS_TRIM_BB_GDRVI_0                                (*(volatile uint32_t *)(0x400affb8UL))
#define PDSS_TRIM_BB_GDRVI_0_DEFAULT                        (0x00000019UL)

/*
 * VBST under-voltage detection comparator trim bits:
 * <7:6> : Spare
 * <5:0> : trim bits with resolution of 40mV
 * 6'b000000 = 40mV
 * 6'b000001 = 80mV
 * ...
 * 6'b011001 = 1040mV (Default)
 * ....
 * 6'b011111 = 1280mV
 * 6'b100000 = 680mV
 * 6'b100001 = 720mV
 * ...
 * 6'b111111 = 1920mV
 */
#define PDSS_TRIM_BB_GDRVI_0_TRIM_VBST_COMP_MASK            (0x000000ffUL) /* <0:7> R:RW:25: */
#define PDSS_TRIM_BB_GDRVI_0_TRIM_VBST_COMP_POS             (0UL)


/*
 * USBPD Hard IP BB GDRVI Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_BB_GDRVI_1_ADDRESS                        (0x400affbcUL)
#define PDSS_TRIM_BB_GDRVI_1                                (*(volatile uint32_t *)(0x400affbcUL))
#define PDSS_TRIM_BB_GDRVI_1_DEFAULT                        (0x00000024UL)

/*
 * LSZCD comparator trim bits:
 * <7:6> : Spare
 * <5:0> : trim bits with resolution of 0.6mV
 * 6'b000000 = 18.6mV
 * 6'b000001 = 18.0mV
 * ...
 * 6'b011011 = 2.4mV
 * 6'b011100 = 1.8mV
 * 6'b011101 = 1.2mV
 * 6'b011110 = 0.6mV
 * 6'b011111 = 0.0mV
 * 6'b100000 = 0.0mV
 * 6'b100001 = -0.6mV
 * 6'b100010 = -1.2mV
 * 6'b100011 = -1.8mV
 * 6'b100100 = -2.4mV(Default)
 * ...
 * 6'b111110 = -18.0mV
 * 6'b111111 = -18.6mV
 */
#define PDSS_TRIM_BB_GDRVI_1_TRIM_LSZCD_MASK                (0x000000ffUL) /* <0:7> R:RW:36: */
#define PDSS_TRIM_BB_GDRVI_1_TRIM_LSZCD_POS                 (0UL)


/*
 * USBPD Hard IP C-connector Trim Register8. Production trims stored in flash
 */
#define PDSS_TRIM_CC_8_ADDRESS                              (0x400affc0UL)
#define PDSS_TRIM_CC_8                                      (*(volatile uint32_t *)(0x400affc0UL))
#define PDSS_TRIM_CC_8_DEFAULT                              (0x00000000UL)

/*
 * Mapped to t_cc_shvt<2:0> in s8pdbb_cc_shvt.
 * Trim bits for vref_1p1_buff in wrapper block,
 * For code 0: default
 * For codes 1 to 4: default+N*20mV
 * For codes 5 to 7: default+(4-N)*20mV
 */
#define PDSS_TRIM_CC_8_V1P1_BUFF_WRAP_MASK                  (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_CC_8_V1P1_BUFF_WRAP_POS                   (0UL)


/*
 * Mapped to t_cc_shvt<5:3> in s8pdbb_cc_shvt.
 * Trim bits for vref_0p74_buff in wrapper block,
 * For code 0: default
 * For codes 1 to 4: default+N*20mV
 * For codes 5 to 7: default+(4-N)*20mV
 */
#define PDSS_TRIM_CC_8_V0P74_BUFF_WRAP_MASK                 (0x00000038UL) /* <3:5> R:RW:0: */
#define PDSS_TRIM_CC_8_V0P74_BUFF_WRAP_POS                  (3UL)


/*
 * Mapped to t_cc_shvt<7:6> in s8pdbb_cc_shvt.
 * Trim bits for biasgen output current in wrapper block.
 */
#define PDSS_TRIM_CC_8_BIASGEN_WRAP_MASK                    (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_TRIM_CC_8_BIASGEN_WRAP_POS                     (6UL)


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
 * the original component design as a result of componenet IP reuse.
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

#endif /* _CY_USBPD_CCG7S_REGS_H_ */

