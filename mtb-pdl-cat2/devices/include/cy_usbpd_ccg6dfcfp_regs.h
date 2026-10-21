/***************************************************************************//**
* \file 13525_reg_top.h
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
#ifndef _13525_REG_TOP_H_
#define _13525_REG_TOP_H_

#include <stdint.h>
#include <stdbool.h>

/** \cond DOXYGEN_HIDE */

#define PDSS_BASE_ADDR                                   (0x400a0000UL)
#define PDSS0_BASE_ADDR                                  (0x400a0000UL)
#define PDSS1_BASE_ADDR                                  (0x400b0000UL)

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
    volatile uint32_t swap_ctrl0;                         /* 0x400a010cUL */
    volatile uint32_t swap_ctrl1;                         /* 0x400a0110UL */
    volatile uint32_t swap_ctrl2;                         /* 0x400a0114UL */
    volatile uint32_t swap_ctrl3;                         /* 0x400a0118UL */
    volatile uint32_t swap_ctrl5;                         /* 0x400a011cUL */
    volatile uint32_t swapt_ctrl1;                        /* 0x400a0120UL */
    volatile uint32_t swapt_ctrl2;                        /* 0x400a0124UL */
    volatile uint32_t bit_en_cntr_ctrl;                   /* 0x400a0128UL */
    volatile uint32_t rp_rd_cfg1;                         /* 0x400a012cUL */
    volatile uint32_t rp_rd_cfg2;                         /* 0x400a0130UL */
    volatile uint32_t lf_cntr;                            /* 0x400a0134UL */
    volatile uint32_t lf_cntr_match;                      /* 0x400a0138UL */
    volatile uint32_t rsrvd2[241];
    volatile uint32_t intr0;                              /* 0x400a0500UL */
    volatile uint32_t intr0_set;                          /* 0x400a0504UL */
    volatile uint32_t intr0_mask;                         /* 0x400a0508UL */
    volatile uint32_t intr0_masked;                       /* 0x400a050cUL */
    volatile uint32_t intr2;                              /* 0x400a0510UL */
    volatile uint32_t intr2_set;                          /* 0x400a0514UL */
    volatile uint32_t intr2_mask;                         /* 0x400a0518UL */
    volatile uint32_t intr2_masked;                       /* 0x400a051cUL */
    volatile uint32_t intr20;                             /* 0x400a0520UL */
    volatile uint32_t intr20_set;                         /* 0x400a0524UL */
    volatile uint32_t intr20_mask;                        /* 0x400a0528UL */
    volatile uint32_t intr20_masked;                      /* 0x400a052cUL */
    volatile uint32_t rsrvd3[20];
    volatile uint32_t ddft_dig_mux;                       /* 0x400a0580UL */
    volatile uint32_t intr_ddft_dig_mux;                  /* 0x400a0584UL */
    volatile uint32_t rsrvd4[7950];
    volatile uint32_t adc_sar_ctrl;                       /* 0x400a81c0UL */
    volatile uint32_t rsrvd5[15];
    volatile uint32_t switch_ctrl_00;                     /* 0x400a8200UL */
    volatile uint32_t switch_ctrl_01;                     /* 0x400a8204UL */
    volatile uint32_t switch_ctrl_02;                     /* 0x400a8208UL */
    volatile uint32_t switch_ctrl_03;                     /* 0x400a820cUL */
    volatile uint32_t switch_ctrl_04;                     /* 0x400a8210UL */
    volatile uint32_t switch_ctrl_05;                     /* 0x400a8214UL */
    volatile uint32_t switch_ctrl_06;                     /* 0x400a8218UL */
    volatile uint32_t switch_ctrl_07;                     /* 0x400a821cUL */
    volatile uint32_t switch_ctrl_08;                     /* 0x400a8220UL */
    volatile uint32_t switch_ctrl_09;                     /* 0x400a8224UL */
    volatile uint32_t switch_ctrl_10;                     /* 0x400a8228UL */
    volatile uint32_t switch_ctrl_11;                     /* 0x400a822cUL */
    volatile uint32_t rsrvd6[28];
    volatile uint32_t intr1_cfg;                          /* 0x400a82a0UL */
    volatile uint32_t intr1_cfg_cc1_cc2_ls;               /* 0x400a82a4UL */
    volatile uint32_t intr1_cfg_vcmp_up_down_ls;          /* 0x400a82a8UL */
    volatile uint32_t intr1_cfg_cc12_ocp_hs;              /* 0x400a82acUL */
    volatile uint32_t intr1_cfg_cc12_ovp_hs;              /* 0x400a82b0UL */
    volatile uint32_t intr1_status;                       /* 0x400a82b4UL */
    volatile uint32_t intr1;                              /* 0x400a82b8UL */
    volatile uint32_t intr1_set;                          /* 0x400a82bcUL */
    volatile uint32_t intr1_mask;                         /* 0x400a82c0UL */
    volatile uint32_t intr1_masked;                       /* 0x400a82c4UL */
    volatile uint32_t rsrvd7[14];
    volatile uint32_t intr3_cfg_vsys;                     /* 0x400a8300UL */
    volatile uint32_t intr3_cfg_adc_hs;                   /* 0x400a8304UL */
    volatile uint32_t rsrvd8[7];
    volatile uint32_t intr3_cfg_sbu20_ovp_hs;             /* 0x400a8324UL */
    volatile uint32_t rsrvd9[4];
    volatile uint32_t intr3_cfg_vreg20_vbus;              /* 0x400a8338UL */
    volatile uint32_t rsrvd10;
    volatile uint32_t intr3_status_0;                     /* 0x400a8340UL */
    volatile uint32_t intr3_status_1;                     /* 0x400a8344UL */
    volatile uint32_t intr3;                              /* 0x400a8348UL */
    volatile uint32_t intr3_set;                          /* 0x400a834cUL */
    volatile uint32_t intr3_mask;                         /* 0x400a8350UL */
    volatile uint32_t intr3_masked;                       /* 0x400a8354UL */
    volatile uint32_t rsrvd11[10];
    volatile uint32_t intr5_filter_cfg[4];                /* 0x400a8380UL */
    volatile uint32_t rsrvd12[20];
    volatile uint32_t intr5_status_0;                     /* 0x400a83e0UL */
    volatile uint32_t rsrvd13;
    volatile uint32_t intr5;                              /* 0x400a83e8UL */
    volatile uint32_t intr5_set;                          /* 0x400a83ecUL */
    volatile uint32_t intr5_mask;                         /* 0x400a83f0UL */
    volatile uint32_t intr5_masked;                       /* 0x400a83f4UL */
    volatile uint32_t rsrvd14[10];
    volatile uint32_t intr7_filter_cfg;                   /* 0x400a8420UL */
    volatile uint32_t rsrvd15[7];
    volatile uint32_t intr7_status;                       /* 0x400a8440UL */
    volatile uint32_t intr7;                              /* 0x400a8444UL */
    volatile uint32_t intr7_set;                          /* 0x400a8448UL */
    volatile uint32_t intr7_mask;                         /* 0x400a844cUL */
    volatile uint32_t intr7_masked;                       /* 0x400a8450UL */
    volatile uint32_t rsrvd16[27];
    volatile uint32_t intr11_filter_cfg;                  /* 0x400a84c0UL */
    volatile uint32_t intr11_status_0;                    /* 0x400a84c4UL */
    volatile uint32_t intr11;                             /* 0x400a84c8UL */
    volatile uint32_t intr11_set;                         /* 0x400a84ccUL */
    volatile uint32_t intr11_mask;                        /* 0x400a84d0UL */
    volatile uint32_t intr11_masked;                      /* 0x400a84d4UL */
    volatile uint32_t rsrvd17;
    volatile uint32_t intr13_status;                      /* 0x400a84dcUL */
    volatile uint32_t intr13;                             /* 0x400a84e0UL */
    volatile uint32_t intr13_set;                         /* 0x400a84e4UL */
    volatile uint32_t intr13_mask;                        /* 0x400a84e8UL */
    volatile uint32_t intr13_masked;                      /* 0x400a84ecUL */
    volatile uint32_t intr13_cfg_csa_scp_hs;              /* 0x400a84f0UL */
    volatile uint32_t intr13_cfg_csa_rcp_hs;              /* 0x400a84f4UL */
    volatile uint32_t rsrvd18[35];
    volatile uint32_t hip_intr_ddft_mux;                  /* 0x400a8584UL */
    volatile uint32_t ncell_ddft_mux;                     /* 0x400a8588UL */
    volatile uint32_t gpio_ddft_mux;                      /* 0x400a858cUL */
    volatile uint32_t gpio_intr_ddft_mux;                 /* 0x400a8590UL */
    volatile uint32_t rsrvd19;
    volatile uint32_t fault_gpio_ctrl_extr;               /* 0x400a8598UL */
    volatile uint32_t rsrvd20[25];
    volatile uint32_t cc_ctrl_0;                          /* 0x400a8600UL */
    volatile uint32_t cc_ctrl_1;                          /* 0x400a8604UL */
    volatile uint32_t rsrvd21[4];
    volatile uint32_t vsys_ctrl;                          /* 0x400a8618UL */
    volatile uint32_t vreg_vsys_ctrl;                     /* 0x400a861cUL */
    volatile uint32_t rsrvd22[3];
    volatile uint32_t amux_nhv_ctrl;                      /* 0x400a862cUL */
    volatile uint32_t amux_denfet_ctrl;                   /* 0x400a8630UL */
    volatile uint32_t rsrvd23[19];
    volatile uint32_t adc_ctrl;                           /* 0x400a8680UL */
    volatile uint32_t rsrvd24[67];
    volatile uint32_t dischg_shv_ctrl;                    /* 0x400a8790UL */
    volatile uint32_t rsrvd25[15];
    volatile uint32_t comp_ctrl[3];                       /* 0x400a87d0UL */
    volatile uint32_t rsrvd26[36];
    volatile uint32_t pump5v_ctrl[2];                     /* 0x400a886cUL */
    volatile uint32_t rsrvd27[1567];
    volatile uint32_t frs_ctrl;                           /* 0x400aa0f0UL */
    volatile uint32_t rsrvd28[2];
    volatile uint32_t frs_seq_cntr;                       /* 0x400aa0fcUL */
    volatile uint32_t rsrvd29[256];
    volatile uint32_t pd_bg_ctrl;                         /* 0x400aa500UL */
    volatile uint32_t pd_bg_iref8_ctrl;                   /* 0x400aa504UL */
    volatile uint32_t pd_ref_gen_ctrl;                    /* 0x400aa508UL */
    volatile uint32_t pd_ref_mux_ctrl_0;                  /* 0x400aa50cUL */
    volatile uint32_t pd_ref_mux_ctrl_1;                  /* 0x400aa510UL */
    volatile uint32_t pd_reg_ctrl;                        /* 0x400aa514UL */
    volatile uint32_t rsrvd30[6];
    volatile uint32_t pd_reg_40nlsw_ctrl;                 /* 0x400aa530UL */
    volatile uint32_t pd_30vconn_ctrl;                    /* 0x400aa534UL */
    volatile uint32_t rsrvd31[2];
    volatile uint32_t ngdo_p5c40_ctrl_0;                  /* 0x400aa540UL */
    volatile uint32_t ngdo_p5c40_ctrl_1;                  /* 0x400aa544UL */
    volatile uint32_t rsrvd32[2];
    volatile uint32_t pd_30sbu_clipper_ctrl;              /* 0x400aa550UL */
    volatile uint32_t pd_sbu_term_ctrl;                   /* 0x400aa554UL */
    volatile uint32_t pd_sbu_lres_ctrl;                   /* 0x400aa558UL */
    volatile uint32_t pd_sbu_hres_ctrl;                   /* 0x400aa55cUL */
    volatile uint32_t rsrvd33[4];
    volatile uint32_t pd_sbu_ls_ctrl_0;                   /* 0x400aa570UL */
    volatile uint32_t pd_sbu_ls_ctrl_1;                   /* 0x400aa574UL */
    volatile uint32_t rsrvd34[2];
    volatile uint32_t pd_40rcp_ctrl;                      /* 0x400aa580UL */
    volatile uint32_t pd_40scp_ctrl;                      /* 0x400aa584UL */
    volatile uint32_t rsrvd35[2];
    volatile uint32_t pd_vsense_ctrl_0;                   /* 0x400aa590UL */
    volatile uint32_t pd_vsense_ctrl_1;                   /* 0x400aa594UL */
    volatile uint32_t pd_ilimt_ctrl;                      /* 0x400aa598UL */
    volatile uint32_t pd_tempsns_ctrl;                    /* 0x400aa59cUL */
    volatile uint32_t spare_0;                            /* 0x400aa5a0UL */
    volatile uint32_t spare_1;                            /* 0x400aa5a4UL */
    volatile uint32_t rsrvd36[2];
    volatile uint32_t hw_sbu_ctrl_1;                      /* 0x400aa5b0UL */
    volatile uint32_t hw_sbu_ctrl_2;                      /* 0x400aa5b4UL */
    volatile uint32_t hw_sbu_status;                      /* 0x400aa5b8UL */
    volatile uint32_t intr21_status;                      /* 0x400aa5bcUL */
    volatile uint32_t intr21;                             /* 0x400aa5c0UL */
    volatile uint32_t intr21_set;                         /* 0x400aa5c4UL */
    volatile uint32_t intr21_mask;                        /* 0x400aa5c8UL */
    volatile uint32_t intr21_masked;                      /* 0x400aa5ccUL */
    volatile uint32_t rsrvd37[5708];
} PDSS_REGS_T, *PPDSS_REGS_T;

#define PDSS0       ((PPDSS_REGS_T) PDSS0_BASE_ADDR)
#define PDSS1       ((PPDSS_REGS_T) PDSS1_BASE_ADDR)

/*
 * NOTE:
 * There are multiple instances of the above register section.
 * The following structure pointer array needs to be defined in
 * a source file before using it.
 * const PPDSS_REGS_T PDSS[2] = {PDSS0, PDSS1};
 */
extern const PPDSS_REGS_T PDSS[];

#define PDSS_TRIMS_BASE_ADDR                             (0x400aff00UL)
#define PDSS_TRIMS0_BASE_ADDR                            (0x400aff00UL)
#define PDSS_TRIMS1_BASE_ADDR                            (0x400bff00UL)

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
    volatile uint32_t trim_5vpump0_0;                     /* 0x400aff24UL */
    volatile uint32_t trim_5vpump0_1;                     /* 0x400aff28UL */
    volatile uint32_t trim_5vpump1_0;                     /* 0x400aff2cUL */
    volatile uint32_t trim_5vpump1_1;                     /* 0x400aff30UL */
    volatile uint32_t trim_ngdo_0;                        /* 0x400aff34UL */
    volatile uint32_t trim_ngdo_1;                        /* 0x400aff38UL */
    volatile uint32_t trim_30vconn_0;                     /* 0x400aff3cUL */
    volatile uint32_t trim_30vconn_1;                     /* 0x400aff40UL */
    volatile uint32_t trim_30vconn_2;                     /* 0x400aff44UL */
    volatile uint32_t trim_sbu_term_0;                    /* 0x400aff48UL */
    volatile uint32_t trim_sbu_term_1;                    /* 0x400aff4cUL */
    volatile uint32_t trim_40rcp;                         /* 0x400aff50UL */
    volatile uint32_t trim_40scp_0;                       /* 0x400aff54UL */
    volatile uint32_t trim_40scp_1;                       /* 0x400aff58UL */
    volatile uint32_t trim_vsense_0;                      /* 0x400aff5cUL */
    volatile uint32_t trim_vsense_1;                      /* 0x400aff60UL */
    volatile uint32_t trim_vsense_2;                      /* 0x400aff64UL */
    volatile uint32_t trim_vsense_3;                      /* 0x400aff68UL */
    volatile uint32_t trim_vsense_4;                      /* 0x400aff6cUL */
    volatile uint32_t trim_ilimt;                         /* 0x400aff70UL */
    volatile uint32_t trim_ref_gen;                       /* 0x400aff74UL */
    volatile uint32_t trim_sbu_ls_0;                      /* 0x400aff78UL */
    volatile uint32_t trim_sbu_ls_1;                      /* 0x400aff7cUL */
    volatile uint32_t trim_sbu_ls_2;                      /* 0x400aff80UL */
    volatile uint32_t trim_sbu_ls_3;                      /* 0x400aff84UL */
    volatile uint32_t trim_sbu_ls_4;                      /* 0x400aff88UL */
    volatile uint32_t trim_tempsns;                       /* 0x400aff8cUL */
    volatile uint32_t rsrvd38;
    volatile uint32_t trim_bg_0;                          /* 0x400aff94UL */
    volatile uint32_t trim_bg_1;                          /* 0x400aff98UL */
    volatile uint32_t trim_bg_2;                          /* 0x400aff9cUL */
    volatile uint32_t trim_bg_3;                          /* 0x400affa0UL */
    volatile uint32_t trim_bg_4;                          /* 0x400affa4UL */
    volatile uint32_t trim_bg_5;                          /* 0x400affa8UL */
    volatile uint32_t trim_bg_6;                          /* 0x400affacUL */
    volatile uint32_t trim_reg_0;                         /* 0x400affb0UL */
    volatile uint32_t trim_reg_1;                         /* 0x400affb4UL */
    volatile uint32_t trim_reg_2;                         /* 0x400affb8UL */
} PDSS_TRIMS_REGS_T, *PPDSS_TRIMS_REGS_T;

#define PDSS_TRIMS0       ((PPDSS_TRIMS_REGS_T) PDSS_TRIMS0_BASE_ADDR)
#define PDSS_TRIMS1       ((PPDSS_TRIMS_REGS_T) PDSS_TRIMS1_BASE_ADDR)

/*
 * NOTE:
 * There are multiple instances of the above register section.
 * The following structure pointer array needs to be defined in
 * a source file before using it.
 * const PPDSS_REGS_T PDSS[2] = {PDSS0, PDSS1};
 */
extern const PPDSS_REGS_T PDSS[];


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
#define PDSS_CTRL_ADDRESS(m)                                (0x400a0000UL + ((m) * (0x10000UL)))
#define PDSS_CTRL(m)                                        (*(volatile uint32_t *)(0x400a0000UL + ((m) * 0x10000UL)))
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
 * This bit is used to selects which of the clk_filter or clk_lf drivers
 * the High-Speed filters 1
 * 0: clk_lf drives the High Speed filters 1
 * 1: clk_filter drives the High Speed filters 1
 */
#define PDSS_CTRL_SEL_CLK_FILTER1                           (1UL << 5) /* <5:5> R:RW:0: */


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
#define PDSS_HEADER_INFO_ADDRESS(m)                         (0x400a0004UL + ((m) * (0x10000UL)))
#define PDSS_HEADER_INFO(m)                                 (*(volatile uint32_t *)(0x400a0004UL + ((m) * 0x10000UL)))
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
#define PDSS_TX_HEADER_ADDRESS(m)                           (0x400a000cUL + ((m) * (0x10000UL)))
#define PDSS_TX_HEADER(m)                                   (*(volatile uint32_t *)(0x400a000cUL + ((m) * 0x10000UL)))
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
#define PDSS_TX_MEM_DATA_ADDRESS(m,n)                       (0x400a0010UL + ((m) * (0x10000UL)) + ((n) * (0x0004UL)))
#define PDSS_TX_MEM_DATA(m,n)                               (*(volatile uint32_t *)(0x400a0010UL + ((m) * (0x10000UL)) + ((n) * 0x0004)))
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
#define PDSS_RX_HEADER_ADDRESS(m)                           (0x400a005cUL + ((m) * (0x10000UL)))
#define PDSS_RX_HEADER(m)                                   (*(volatile uint32_t *)(0x400a005cUL + ((m) * 0x10000UL)))
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
#define PDSS_RX_MEM_DATA_ADDRESS(m,n)                       (0x400a0060UL + ((m) * (0x10000UL)) + ((n) * (0x0004UL)))
#define PDSS_RX_MEM_DATA(m,n)                               (*(volatile uint32_t *)(0x400a0060UL + ((m) * (0x10000UL)) + ((n) * 0x0004)))
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
#define PDSS_SRAM_PTR_ADDRESS(m)                            (0x400a00a0UL + ((m) * (0x10000UL)))
#define PDSS_SRAM_PTR(m)                                    (*(volatile uint32_t *)(0x400a00a0UL + ((m) * 0x10000UL)))
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
#define PDSS_STATUS_ADDRESS(m)                              (0x400a00a4UL + ((m) * (0x10000UL)))
#define PDSS_STATUS(m)                                      (*(volatile uint32_t *)(0x400a00a4UL + ((m) * 0x10000UL)))
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
 * This status bit shows the VCM_FS comparator output from s8usbpd_cc_shvt_top.
 */
#define PDSS_STATUS_VCMP_FS                                 (1UL << 12) /* <12:12> RW:R:0:SWAP_EN */


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
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_ADDRESS(m)             (0x400a00a8UL + ((m) * (0x10000UL)))
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL(m)                     (*(volatile uint32_t *)(0x400a00a8UL + ((m) * 0x10000UL)))
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
 * Setting this bit will clear the SENDING_GOODCRC_MSG stauts bit, when a
 * collision happens between CRC timer and a new message is received from
 * the partner.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_CLR_SENDING_GOODCRC_MSG_ON_COLL    (1UL << 31) /* <31:31> R:RW:0: */


/*
 * RX Expected GoodCRC message to stop the CRC timers
 */
#define PDSS_RX_EXPECT_GOODCRC_MSG_ADDRESS(m)               (0x400a00acUL + ((m) * (0x10000UL)))
#define PDSS_RX_EXPECT_GOODCRC_MSG(m)                       (*(volatile uint32_t *)(0x400a00acUL + ((m) * 0x10000UL)))
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
#define PDSS_RX_GOODCRC_MSG_ADDRESS(m)                      (0x400a00b0UL + ((m) * (0x10000UL)))
#define PDSS_RX_GOODCRC_MSG(m)                              (*(volatile uint32_t *)(0x400a00b0UL + ((m) * 0x10000UL)))
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
#define PDSS_RX_CC_0_CFG_ADDRESS(m)                         (0x400a00b4UL + ((m) * (0x10000UL)))
#define PDSS_RX_CC_0_CFG(m)                                 (*(volatile uint32_t *)(0x400a00b4UL + ((m) * 0x10000UL)))
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
#define PDSS_RX_CC_1_CFG_ADDRESS(m)                         (0x400a00b8UL + ((m) * (0x10000UL)))
#define PDSS_RX_CC_1_CFG(m)                                 (*(volatile uint32_t *)(0x400a00b8UL + ((m) * 0x10000UL)))
#define PDSS_RX_CC_1_CFG_DEFAULT                            (0x00040000UL)

/*
 * Number of RX_CC transitions before RX_VALID output is raised.
 */
#define PDSS_RX_CC_1_CFG_DELAY_VALID_COUNT_MASK             (0x000f0000UL) /* <16:19> R:RW:4: */
#define PDSS_RX_CC_1_CFG_DELAY_VALID_COUNT_POS              (16UL)


/*
 * Receive SOPs and RSTs order set control
 */
#define PDSS_RX_ORDER_SET_CTRL_ADDRESS(m)                   (0x400a00bcUL + ((m) * (0x10000UL)))
#define PDSS_RX_ORDER_SET_CTRL(m)                           (*(volatile uint32_t *)(0x400a00bcUL + ((m) * 0x10000UL)))
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
#define PDSS_TX_GOODCRC_MSG_ORDER_SET_ADDRESS(m)            (0x400a00c0UL + ((m) * (0x10000UL)))
#define PDSS_TX_GOODCRC_MSG_ORDER_SET(m)                    (*(volatile uint32_t *)(0x400a00c0UL + ((m) * 0x10000UL)))
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
#define PDSS_TX_CTRL_ADDRESS(m)                             (0x400a00c4UL + ((m) * (0x10000UL)))
#define PDSS_TX_CTRL(m)                                     (*(volatile uint32_t *)(0x400a00c4UL + ((m) * 0x10000UL)))
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
#define PDSS_TX_SOP_ORDER_SET_ADDRESS(m)                    (0x400a00c8UL + ((m) * (0x10000UL)))
#define PDSS_TX_SOP_ORDER_SET(m)                            (*(volatile uint32_t *)(0x400a00c8UL + ((m) * 0x10000UL)))
#define PDSS_TX_SOP_ORDER_SET_DEFAULT                       (0x0008e318UL)

/*
 * Transmit SOP order Set use in transmit except GoodCrcMsg
 */
#define PDSS_TX_SOP_ORDER_SET_TX_SOP_OS_MASK                (0x000fffffUL) /* <0:19> R:RW:582424: */
#define PDSS_TX_SOP_ORDER_SET_TX_SOP_OS_POS                 (0UL)


/*
 * Transmit Hard/Cable reset order set
 */
#define PDSS_TX_HARD_CABLE_ORDER_SET_ADDRESS(m)             (0x400a00ccUL + ((m) * (0x10000UL)))
#define PDSS_TX_HARD_CABLE_ORDER_SET(m)                     (*(volatile uint32_t *)(0x400a00ccUL + ((m) * 0x10000UL)))
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
#define PDSS_CRC_COUNTER_ADDRESS(m)                         (0x400a00d0UL + ((m) * (0x10000UL)))
#define PDSS_CRC_COUNTER(m)                                 (*(volatile uint32_t *)(0x400a00d0UL + ((m) * 0x10000UL)))
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
#define PDSS_INTER_PACKET_COUNTER_ADDRESS(m)                (0x400a00d4UL + ((m) * (0x10000UL)))
#define PDSS_INTER_PACKET_COUNTER(m)                        (*(volatile uint32_t *)(0x400a00d4UL + ((m) * 0x10000UL)))
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
#define PDSS_TIMER_TRIGGER_ADDRESS(m)                       (0x400a00d8UL + ((m) * (0x10000UL)))
#define PDSS_TIMER_TRIGGER(m)                               (*(volatile uint32_t *)(0x400a00d8UL + ((m) * 0x10000UL)))
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
#define PDSS_DEBUG_CTRL_ADDRESS(m)                          (0x400a00dcUL + ((m) * (0x10000UL)))
#define PDSS_DEBUG_CTRL(m)                                  (*(volatile uint32_t *)(0x400a00dcUL + ((m) * 0x10000UL)))
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
 * C-Connector Debug control register 0
 */
#define PDSS_DEBUG_CC_0_ADDRESS(m)                          (0x400a00e0UL + ((m) * (0x10000UL)))
#define PDSS_DEBUG_CC_0(m)                                  (*(volatile uint32_t *)(0x400a00e0UL + ((m) * 0x10000UL)))
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
 * 0: Source for turing off the VBUS_C Gate driver is SWAPR IRQ
 * 1: Source for turing off the VBUS_C Gate driver is SWAPR IRQ and VBUS_C
 * less than 5 volt
 */
#define PDSS_DEBUG_CC_0_VBUS_C_SWAP_SOURCE_SEL              (1UL << 30) /* <30:30> R:RW:0:SWAP_EN */


/*
 * 0: Source for turing off the VBUS_P Gate driver is SWAPR IRQ
 * 1: Source for turing off the VBUS_P Gate driver is SWAPR IRQ and VBUS_C
 * less than 5 volt
 */
#define PDSS_DEBUG_CC_0_VBUS_P_SWAP_SOURCE_SEL              (1UL << 31) /* <31:31> R:RW:0:SWAP_EN */


/*
 * C-Connector Debug control register 1
 */
#define PDSS_DEBUG_CC_1_ADDRESS(m)                          (0x400a00e4UL + ((m) * (0x10000UL)))
#define PDSS_DEBUG_CC_1(m)                                  (*(volatile uint32_t *)(0x400a00e4UL + ((m) * 0x10000UL)))
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
 * 0: If PFET300_CTRL.EN_SWITCH_CC1 is "1" then
 *                        300ma_switch pulldn_en_cc1 and SWAPT_OUT_GPIO1
 * will be driven "0"
 *     else
 *                        300ma_switch pulldn_en_cc1 and SWAPT_OUT_GPIO1
 *  will be driven based on
 *                        SWAP_CTRL0.SWAPT_TO_GPIO1_EN register
 * 1: 300ma_switch pulldn_en_cc1 and SWAPT_OUT_GPIO1  will be driven based
 * on
 *                        SWAP_CTRL0.SWAPT_TO_GPIO1_EN register
 */
#define PDSS_DEBUG_CC_1_CC1_PULLDN_CFG                      (1UL << 21) /* <21:21> R:RW:0:SWAP_EN */


/*
 * 0: If PFET300_CTRL.EN_SWITCH_CC2 is "1" then
 *                        300ma_switch pulldn_en_cc2 and SWAPT_OUT_GPIO2
 * will be driven "0"
 *     else
 *                        300ma_switch pulldn_en_cc2 and SWAPT_OUT_GPIO2
 *  will be driven based on
 *                        SWAP_CTRL0.SWAPT_TO_GPIO2_EN register
 * 1: 300ma_switch pulldn_en_cc2 and SWAPT_OUT_GPIO2  will be driven based
 * on
 *                        SWAP_CTRL0.SWAPT_TO_GPIO2_EN register
 */
#define PDSS_DEBUG_CC_1_CC2_PULLDN_CFG                      (1UL << 22) /* <22:22> R:RW:0:SWAP_EN */


/*
 * 0: Connect PFET300_PULLDN_EN_CC1 to 300ma_switch (pulldn_en_cc1 pins)
 * 1: Connect SWAPT to 300ma_switch (pulldn_en_cc1 pins)
 */
#define PDSS_DEBUG_CC_1_SWAPT_TO_CC1_EN                     (1UL << 23) /* <23:23> R:RW:0:SWAP_EN */


/*
 * 0: Connect PFET300_PULLDN_EN_CC2 to 300ma_switch (pulldn_en_cc2 pins)
 * 1: Connect SWAPT to 300ma_switch (pulldn_en_cc2 pins)
 */
#define PDSS_DEBUG_CC_1_SWAPT_TO_CC2_EN                     (1UL << 24) /* <24:24> R:RW:0:SWAP_EN */


/*
 * This bit is used only for Receive Extended Messages with the Chunk bit
 * set.
 * 0: Include the 2-byte extended data message header count
 * 1: Don't include the 2-byte extended data message header count
 */
#define PDSS_DEBUG_CC_1_INC_EXT_CHUNK_HDR_COUNT             (1UL << 25) /* <25:25> R:RW:0:PD_EN */


/*
 * This bit is used only for Receive Extended Messages with the Chunk bit
 * set.
 * 0: No gating
 * 1: Turn off the transmiter (set the following pins of s8usbpd_cc_top to
 * zero: tx_reg_en, tx_en, tx_data)
 */
#define PDSS_DEBUG_CC_1_STOP_TX_ON_SWAP                     (1UL << 26) /* <26:26> R:RW:0:SWAP_EN */


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
#define PDSS_DEBUG_CC_2_ADDRESS(m)                          (0x400a00e8UL + ((m) * (0x10000UL)))
#define PDSS_DEBUG_CC_2(m)                                  (*(volatile uint32_t *)(0x400a00e8UL + ((m) * 0x10000UL)))
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
#define PDSS_HPD_CTRL1_ADDRESS(m)                           (0x400a00ecUL + ((m) * (0x10000UL)))
#define PDSS_HPD_CTRL1(m)                                   (*(volatile uint32_t *)(0x400a00ecUL + ((m) * 0x10000UL)))
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
#define PDSS_HPD_CTRL2_ADDRESS(m)                           (0x400a00f0UL + ((m) * (0x10000UL)))
#define PDSS_HPD_CTRL2(m)                                   (*(volatile uint32_t *)(0x400a00f0UL + ((m) * 0x10000UL)))
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
#define PDSS_HPD_CTRL3_ADDRESS(m)                           (0x400a00f4UL + ((m) * (0x10000UL)))
#define PDSS_HPD_CTRL3(m)                                   (*(volatile uint32_t *)(0x400a00f4UL + ((m) * 0x10000UL)))
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
#define PDSS_HPD_CTRL4_ADDRESS(m)                           (0x400a00f8UL + ((m) * (0x10000UL)))
#define PDSS_HPD_CTRL4(m)                                   (*(volatile uint32_t *)(0x400a00f8UL + ((m) * 0x10000UL)))
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
#define PDSS_HPD_CTRL5_ADDRESS(m)                           (0x400a00fcUL + ((m) * (0x10000UL)))
#define PDSS_HPD_CTRL5(m)                                   (*(volatile uint32_t *)(0x400a00fcUL + ((m) * 0x10000UL)))
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
#define PDSS_HPD_QUEUE_ADDRESS(m)                           (0x400a0100UL + ((m) * (0x10000UL)))
#define PDSS_HPD_QUEUE(m)                                   (*(volatile uint32_t *)(0x400a0100UL + ((m) * 0x10000UL)))
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
#define PDSS_HPDT_CTRL1_ADDRESS(m)                          (0x400a0104UL + ((m) * (0x10000UL)))
#define PDSS_HPDT_CTRL1(m)                                  (*(volatile uint32_t *)(0x400a0104UL + ((m) * 0x10000UL)))
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
#define PDSS_HPDT_CTRL2_ADDRESS(m)                          (0x400a0108UL + ((m) * (0x10000UL)))
#define PDSS_HPDT_CTRL2(m)                                  (*(volatile uint32_t *)(0x400a0108UL + ((m) * 0x10000UL)))
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
 * Configures SWAP control0
 */
#define PDSS_SWAP_CTRL0_ADDRESS(m)                          (0x400a010cUL + ((m) * (0x10000UL)))
#define PDSS_SWAP_CTRL0(m)                                  (*(volatile uint32_t *)(0x400a010cUL + ((m) * 0x10000UL)))
#define PDSS_SWAP_CTRL0_DEFAULT                             (0x00000000UL)

/*
 * Input source selection for SWAPT
 */
#define PDSS_SWAP_CTRL0_SWAPT_SOURCE_SEL_MASK               (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_SWAP_CTRL0_SWAPT_SOURCE_SEL_POS                (0UL)


/*
 * Input source selection for SWAPR
 *
 * CCG6DF_CFP : Port 0
 * 0: ADC_COMP_OUT
 * 1:0
 * 2:0
 * 3:VSYS_DET
 * 4:0
 * 5:UV
 * 6:OV
 * 7:0
 * 8:0
 * 9:  CSA_OCP
 * 10: CSA_SCP
 * 11:CSA_COMP_OUT
 * 12:0
 * 13:0
 * 14:0
 * 15: 0
 *
 *
 * CCG6DF_CFP : Port 1
 * 0:ADC_COMP_OUT
 * 1:0
 * 2:0
 * 3:0
 * 4:0
 * 5:UV
 * 6:OV
 * 7:0
 * 8:0
 * 9:  CSA_OCP
 * 10: CSA_SCP
 * 11:CSA_COMP_OUT
 * 12:0
 * 13:0
 * 14:0
 * 15: 0
 *
 *
 */
#define PDSS_SWAP_CTRL0_SWAPR_SOURCE_SEL_MASK               (0x0000003cUL) /* <2:5> R:RW:0: */
#define PDSS_SWAP_CTRL0_SWAPR_SOURCE_SEL_POS                (2UL)


/*
 * Polatiry of the SWAPT output
 * 0: No  Inverting the output of the swapt
 * 1: Inverting the output of the swapt
 */
#define PDSS_SWAP_CTRL0_SWAPT_POLARITY                      (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Pull down value for SWAPT_OUT_GPIO1
 */
#define PDSS_SWAP_CTRL0_SWAPT_EN_CC1_PULLDN                 (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Pull down value for SWAPT_OUT_GPIO2
 */
#define PDSS_SWAP_CTRL0_SWAPT_EN_CC2_PULLDN                 (1UL << 8) /* <8:8> R:RW:0: */


/*
 * 0: Connect SWAPT_EN_CC1_PULLDN to SWAPT_OUT_GPIO1
 * 1: Connect SWAPT to SWAPT_OUT_GPIO1
 */
#define PDSS_SWAP_CTRL0_SWAPT_TO_GPIO1_EN                   (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 0: Connect SWAPT_EN_CC2_PULLDN to SWAPT_OUT_GPIO2
 * 1: Connect SWAPT to SWAPT_OUT_GPIO2
 */
#define PDSS_SWAP_CTRL0_SWAPT_TO_GPIO2_EN                   (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 0: Swap Pulse
 * 1: Swap rcvd
 * 2: Gpio
 */
#define PDSS_SWAP_CTRL0_RX_SWAP_SOURCE_MASK                 (0x00001800UL) /* <11:12> R:RW:0: */
#define PDSS_SWAP_CTRL0_RX_SWAP_SOURCE_POS                  (11UL)


/*
 * 0: Swap_done is not cleared
 * 1: Swap_done is cleared
 */
#define PDSS_SWAP_CTRL0_CLR_RX_SWAP_DONE                    (1UL << 13) /* <13:13> R:RW:0: */


/*
 * 0: Clocks is turn off for SWAP block
 * 1: Clock is runing in the SWAP block
 */
#define PDSS_SWAP_CTRL0_SWAP_ENABLED                        (1UL << 31) /* <31:31> R:RW:0: */


/*
 * Configures SWAP module, IRQ_MIN, IRQ_MAX and ENABLE
 */
#define PDSS_SWAP_CTRL1_ADDRESS(m)                          (0x400a0110UL + ((m) * (0x10000UL)))
#define PDSS_SWAP_CTRL1(m)                                  (*(volatile uint32_t *)(0x400a0110UL + ((m) * 0x10000UL)))
#define PDSS_SWAP_CTRL1_DEFAULT                             (0x8025812cUL)

/*
 * Defines the min width of pulse. Spec = 0.5 ms. Assumes 600 Khz clock.
 */
#define PDSS_SWAP_CTRL1_PULSE_MIN_MASK                      (0x00000fffUL) /* <0:11> R:RW:300: */
#define PDSS_SWAP_CTRL1_PULSE_MIN_POS                       (0UL)


/*
 * Defines the max width of Ipulse. Spec = 1.0 ms. Assumes 600 Khz clock.
 */
#define PDSS_SWAP_CTRL1_PULSE_MAX_MASK                      (0x00fff000UL) /* <12:23> R:RW:600: */
#define PDSS_SWAP_CTRL1_PULSE_MAX_POS                       (12UL)


/*
 * When set, input to SWAP module will come from output of SWAPt module.
 */
#define PDSS_SWAP_CTRL1_LOOPBACK_EN                         (1UL << 30) /* <30:30> R:RW:0: */


/*
 * When set, SWAP state machine is at Idle
 */
#define PDSS_SWAP_CTRL1_RESET_SWAP_STATE                    (1UL << 31) /* <31:31> R:RW:1: */


/*
 * Configures SWAP module, Glitch width.
 */
#define PDSS_SWAP_CTRL2_ADDRESS(m)                          (0x400a0114UL + ((m) * (0x10000UL)))
#define PDSS_SWAP_CTRL2(m)                                  (*(volatile uint32_t *)(0x400a0114UL + ((m) * 0x10000UL)))
#define PDSS_SWAP_CTRL2_DEFAULT                             (0x00096096UL)

/*
 * Defines the width of glitch. Spec = 0.25 ms. Assumes clk of 600 Khz on
 * the rising edge of SWAP_in input
 */
#define PDSS_SWAP_CTRL2_GLITCH_WIDTH_HIGH_MASK              (0x00000fffUL) /* <0:11> R:RW:150: */
#define PDSS_SWAP_CTRL2_GLITCH_WIDTH_HIGH_POS               (0UL)


/*
 * Defines the width of glitch. Spec = 0.25 ms. Assumes clk of 600 Khz on
 * the falling edge of SWAP_in input
 */
#define PDSS_SWAP_CTRL2_GLITCH_WIDTH_LOW_MASK               (0x00fff000UL) /* <12:23> R:RW:150: */
#define PDSS_SWAP_CTRL2_GLITCH_WIDTH_LOW_POS                (12UL)


/*
 * Configures SWAP module, stable high and stable low values
 */
#define PDSS_SWAP_CTRL3_ADDRESS(m)                          (0x400a0118UL + ((m) * (0x10000UL)))
#define PDSS_SWAP_CTRL3(m)                                  (*(volatile uint32_t *)(0x400a0118UL + ((m) * 0x10000UL)))
#define PDSS_SWAP_CTRL3_DEFAULT                             (0x0004b000UL)

/*
 * Defines the minimum time before unplugged condition is detected for subsequent
 * connect.  Spec = 2 ms. Assumes 600 Khz clock. This value is internally
 * multiplied by 16.
 */
#define PDSS_SWAP_CTRL3_STABLE_LOW_MASK                     (0x00fff000UL) /* <12:23> R:RW:75: */
#define PDSS_SWAP_CTRL3_STABLE_LOW_POS                      (12UL)


/*
 * Configures SWAP module, Initial LOW and HIGH times
 */
#define PDSS_SWAP_CTRL5_ADDRESS(m)                          (0x400a011cUL + ((m) * (0x10000UL)))
#define PDSS_SWAP_CTRL5(m)                                  (*(volatile uint32_t *)(0x400a011cUL + ((m) * 0x10000UL)))
#define PDSS_SWAP_CTRL5_DEFAULT                             (0x0ea50000UL)

/*
 * Defines the minimum width before unplugged condition is detected.  Spec
 * = 100 ms. Assumes 600 Khz clock. This value is internally multiplied by
 * 16..  After LONG_LOW condition is detected, SWAP input is expected to
 * stay high equal to LONG_HIGH before plugged condition is reached. This
 * is the optional 100 ms debounce time
 */
#define PDSS_SWAP_CTRL5_LONG_LOW_MASK                       (0xffff0000UL) /* <16:31> R:RW:3749: */
#define PDSS_SWAP_CTRL5_LONG_LOW_POS                        (16UL)


/*
 * SWAPT module configure and IRQ width and delay parameters
 */
#define PDSS_SWAPT_CTRL1_ADDRESS(m)                         (0x400a0120UL + ((m) * (0x10000UL)))
#define PDSS_SWAPT_CTRL1(m)                                 (*(volatile uint32_t *)(0x400a0120UL + ((m) * 0x10000UL)))
#define PDSS_SWAPT_CTRL1_DEFAULT                            (0x404af1c2UL)

/*
 * Defines the width of IRQ pulse in muliples of 600KHZ clock period. This
 * value sets the width at 0.75 ms.
 */
#define PDSS_SWAPT_CTRL1_IRQ_WIDTH_MASK                     (0x00000fffUL) /* <0:11> R:RW:450: */
#define PDSS_SWAPT_CTRL1_IRQ_WIDTH_POS                      (0UL)


/*
 * Defines the delay to execute IRQ command in multiples of 600KHZ clock
 * period. The default value is 2 ms.
 */
#define PDSS_SWAPT_CTRL1_SET_IRQ_DELAY_MASK                 (0x00fff000UL) /* <12:23> R:RW:1199: */
#define PDSS_SWAPT_CTRL1_SET_IRQ_DELAY_POS                  (12UL)


/*
 * Defines the initial level of the SWAPt output.
 */
#define PDSS_SWAPT_CTRL1_DEFAULT_LEVEL                      (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Source of data to SWAPt_out signal. 0: comes from SWAPt module.  1: comes
 * from DATA_SOURCE bit of this register
 */
#define PDSS_SWAPT_CTRL1_DATA_SOURCE_SELECT                 (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Data source of SWAPt_out output when DATA_SOURCE_SELECT is set high
 */
#define PDSS_SWAPT_CTRL1_DATA_SOURCE                        (1UL << 26) /* <26:26> R:RW:0: */


/*
 * Defines the commands to be executed by SWAPt module.
 * 0: set SWAPt_out to low.
 * 1: set SWAPt_out to high.
 * 2: send an IRQ.
 * 3: unused.
 */
#define PDSS_SWAPT_CTRL1_COMMAND_MASK                       (0x18000000UL) /* <27:28> R:RW:0: */
#define PDSS_SWAPT_CTRL1_COMMAND_POS                        (27UL)


/*
 * When set, the commands specified by COMMAND bits will be executed. Execution
 * happens on the rising edge of this bit.
 * FW should not clear this bit until INTR2.SWAPT_COMMAND_DONE interrupt
 * is set.
 * Hardware clears this bit when command_done is set.
 */
#define PDSS_SWAPT_CTRL1_COMMAND_START                      (1UL << 29) /* <29:29> RW1C:RW:0: */


/*
 * When set, SWAPT state machine is at Idle
 */
#define PDSS_SWAPT_CTRL1_RESET_SWAPT_STATE                  (1UL << 30) /* <30:30> R:RW:1: */


/*
 * SWAPT HIGH & LOW transition delays.
 */
#define PDSS_SWAPT_CTRL2_ADDRESS(m)                         (0x400a0124UL + ((m) * (0x10000UL)))
#define PDSS_SWAPT_CTRL2(m)                                 (*(volatile uint32_t *)(0x400a0124UL + ((m) * 0x10000UL)))
#define PDSS_SWAPT_CTRL2_DEFAULT                            (0x014af4afUL)

/*
 * Defines the delay from HIGH -> LOW transition.  In multiples of 600KHZ
 * clock period. The defaul value is 2 ms.
 */
#define PDSS_SWAPT_CTRL2_SET_LOW_DELAY_MASK                 (0x00000fffUL) /* <0:11> R:RW:1199: */
#define PDSS_SWAPT_CTRL2_SET_LOW_DELAY_POS                  (0UL)


/*
 * Defines the delay from LOW --> HIGH transition.  In multiples of 600KHZ
 * clock period. The defaul value is 2 ms.
 */
#define PDSS_SWAPT_CTRL2_SET_HIGH_DELAY_MASK                (0x00fff000UL) /* <12:23> R:RW:1199: */
#define PDSS_SWAPT_CTRL2_SET_HIGH_DELAY_POS                 (12UL)


/*
 * Defines the default level of SWAPT transmit OE.
 * 0: SWAP output goes IDLE (OE=0) when module is not selected or module
 * is IDLE state
 * 1: SWAP output stays active.
 */
#define PDSS_SWAPT_CTRL2_DEFAULT_OE                         (1UL << 24) /* <24:24> R:RW:1: */


/*
 * Defines the source of SWAP pin OE.
 * 0: Driven by HW
 * 1: Driven by bit CTRL.SWAP_DIRECTION
 */
#define PDSS_SWAPT_CTRL2_OE_SOURCE_SELECT                   (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Selects which pins to appear on SWAPT debug bus
 *      2'h1     : debug_out   <= count_12_bits_q[3:0]
 *     2'h2     : debug_out   <= count_12_bits_q[7:4]
 *     2'h3     : debug_out   <= count_12_bits_q[11:8]
 *     default  : debug_out   <= {1'h0, state_q}
 */
#define PDSS_SWAPT_CTRL2_SWAPT_DEBUG_SEL_MASK               (0x0c000000UL) /* <26:27> R:RW:0: */
#define PDSS_SWAPT_CTRL2_SWAPT_DEBUG_SEL_POS                (26UL)


/*
 * The output of debug bus.
 */
#define PDSS_SWAPT_CTRL2_SWAPT_DEBUG_OUT_MASK               (0xf0000000UL) /* <28:31> RW:R:0: */
#define PDSS_SWAPT_CTRL2_SWAPT_DEBUG_OUT_POS                (28UL)


/*
 * Counter for IDLE detection
 */
#define PDSS_BIT_EN_CNTR_CTRL_ADDRESS(m)                    (0x400a0128UL + ((m) * (0x10000UL)))
#define PDSS_BIT_EN_CNTR_CTRL(m)                            (*(volatile uint32_t *)(0x400a0128UL + ((m) * 0x10000UL)))
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
#define PDSS_RP_RD_CFG1_ADDRESS(m)                          (0x400a012cUL + ((m) * (0x10000UL)))
#define PDSS_RP_RD_CFG1(m)                                  (*(volatile uint32_t *)(0x400a012cUL + ((m) * 0x10000UL)))
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
#define PDSS_RP_RD_CFG2_ADDRESS(m)                          (0x400a0130UL + ((m) * (0x10000UL)))
#define PDSS_RP_RD_CFG2(m)                                  (*(volatile uint32_t *)(0x400a0130UL + ((m) * 0x10000UL)))
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
#define PDSS_LF_CNTR_ADDRESS(m)                             (0x400a0134UL + ((m) * (0x10000UL)))
#define PDSS_LF_CNTR(m)                                     (*(volatile uint32_t *)(0x400a0134UL + ((m) * 0x10000UL)))
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
#define PDSS_LF_CNTR_MATCH_ADDRESS(m)                       (0x400a0138UL + ((m) * (0x10000UL)))
#define PDSS_LF_CNTR_MATCH(m)                               (*(volatile uint32_t *)(0x400a0138UL + ((m) * 0x10000UL)))
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
 * INTR0 Cause. These are the active interrupts get reflected on interrupt_usbpd
 * pin.
 */
#define PDSS_INTR0_ADDRESS(m)                               (0x400a0500UL + ((m) * (0x10000UL)))
#define PDSS_INTR0(m)                                       (*(volatile uint32_t *)(0x400a0500UL + ((m) * 0x10000UL)))
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
 * INTR0 Set
 */
#define PDSS_INTR0_SET_ADDRESS(m)                           (0x400a0504UL + ((m) * (0x10000UL)))
#define PDSS_INTR0_SET(m)                                   (*(volatile uint32_t *)(0x400a0504UL + ((m) * 0x10000UL)))
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
 * INTR0 Mask
 */
#define PDSS_INTR0_MASK_ADDRESS(m)                          (0x400a0508UL + ((m) * (0x10000UL)))
#define PDSS_INTR0_MASK(m)                                  (*(volatile uint32_t *)(0x400a0508UL + ((m) * 0x10000UL)))
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
 * INTR0 Masked
 */
#define PDSS_INTR0_MASKED_ADDRESS(m)                        (0x400a050cUL + ((m) * (0x10000UL)))
#define PDSS_INTR0_MASKED(m)                                (*(volatile uint32_t *)(0x400a050cUL + ((m) * 0x10000UL)))
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
 * INTR2 Cause.  These are the active interrupts get reflected on interrupt_usbpd
 * pin.
 */
#define PDSS_INTR2_ADDRESS(m)                               (0x400a0510UL + ((m) * (0x10000UL)))
#define PDSS_INTR2(m)                                       (*(volatile uint32_t *)(0x400a0510UL + ((m) * 0x10000UL)))
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
 * VDDD_SW Switching is complete
 */
#define PDSS_INTR2_VDDD_SW_SWITCH_DONE                      (1UL << 16) /* <16:16> RW1S:RW1C:0:VSYS_EN */


/*
 * The interrupt is raised when SWAP detects an interrupt
 */
#define PDSS_INTR2_SWAP_PULSE                               (1UL << 18) /* <18:18> RW1S:RW1C:0:SWAP_EN */


/*
 * The interrupt is raised when SWAP detects pluged condition
 */
#define PDSS_INTR2_SWAP_RCVD                                (1UL << 19) /* <19:19> RW1S:RW1C:0:SWAP_EN */


/*
 * The interrupt is raised when SWAP detects unpluged condition
 */
#define PDSS_INTR2_SWAP_DISCONNECT                          (1UL << 20) /* <20:20> RW1S:RW1C:0:SWAP_EN */


/*
 * The interrupt is raised when SWAP completes the command
 */
#define PDSS_INTR2_SWAP_COMMAND_DONE                        (1UL << 21) /* <21:21> RW1S:RW1C:0:SWAP_EN */


/*
 * INTR2 Set
 */
#define PDSS_INTR2_SET_ADDRESS(m)                           (0x400a0514UL + ((m) * (0x10000UL)))
#define PDSS_INTR2_SET(m)                                   (*(volatile uint32_t *)(0x400a0514UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR2_SET_VDDD_SW_SWITCH_DONE                  (1UL << 16) /* <16:16> A:RW1S:0:VSYS_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SWAP_PULSE                           (1UL << 18) /* <18:18> A:RW1S:0:SWAP_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SWAP_RCVD                            (1UL << 19) /* <19:19> A:RW1S:0:SWAP_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SWAP_DISCONNECT                      (1UL << 20) /* <20:20> A:RW1S:0:SWAP_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SWAP_COMMAND_DONE                    (1UL << 21) /* <21:21> A:RW1S:0:SWAP_EN */


/*
 * INTR2 Mask
 */
#define PDSS_INTR2_MASK_ADDRESS(m)                          (0x400a0518UL + ((m) * (0x10000UL)))
#define PDSS_INTR2_MASK(m)                                  (*(volatile uint32_t *)(0x400a0518UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR2_MASK_VDDD_SW_SWITCH_DONE_MASK            (1UL << 16) /* <16:16> R:RW:0:VSYS_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SWAP_PULSE_MASK                     (1UL << 18) /* <18:18> R:RW:0:SWAP_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SWAP_RCVD_MASK                      (1UL << 19) /* <19:19> R:RW:0:SWAP_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SWAP_DISCONNECT_MASK                (1UL << 20) /* <20:20> R:RW:0:SWAP_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SWAP_COMMAND_DONE_MASK              (1UL << 21) /* <21:21> R:RW:0:SWAP_EN */


/*
 * INTR2 Masked
 */
#define PDSS_INTR2_MASKED_ADDRESS(m)                        (0x400a051cUL + ((m) * (0x10000UL)))
#define PDSS_INTR2_MASKED(m)                                (*(volatile uint32_t *)(0x400a051cUL + ((m) * 0x10000UL)))
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
#define PDSS_INTR2_MASKED_VDDD_SW_SWITCH_DONE_MASKED        (1UL << 16) /* <16:16> RW:R:0:VSYS_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SWAP_PULSE_MASKED                 (1UL << 18) /* <18:18> RW:R:0:SWAP_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SWAP_RCVD_MASKED                  (1UL << 19) /* <19:19> RW:R:0:SWAP_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SWAP_DISCONNECT_MASKED            (1UL << 20) /* <20:20> RW:R:0:SWAP_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SWAP_COMMAND_DONE_MASKED          (1UL << 21) /* <21:21> RW:R:0:SWAP_EN */


/*
 * INTR20 Cause.  These are the wakeup interrupts get reflected on interrupt_wakeup
 */
#define PDSS_INTR20_ADDRESS(m)                              (0x400a0520UL + ((m) * (0x10000UL)))
#define PDSS_INTR20(m)                                      (*(volatile uint32_t *)(0x400a0520UL + ((m) * 0x10000UL)))
#define PDSS_INTR20_DEFAULT                                 (0x00000000UL)

/*
 * LF_CNTR Interrupt Request. This bit is set by the HW each time LF_CNTR.COUNTER==LF_MATCH.
 * This is cleared by the FW by writing 1 and due to internal synchronization,
 * it takes 2 SYSCLK cycles to update after a W1C.
 */
#define PDSS_INTR20_LF_CNTR_MATCH                           (1UL << 30) /* <30:30> RW1S:RW1C:0:LF_CNTR_EN */


/*
 * VSWAP and VBUS_C less that 5V is detected
 */
#define PDSS_INTR20_VSWAP_VBUS_LESS_5_DONE                  (1UL << 31) /* <31:31> RW1S:RW1C:0:SWAP_EN */


/*
 * INTR20_SET
 */
#define PDSS_INTR20_SET_ADDRESS(m)                          (0x400a0524UL + ((m) * (0x10000UL)))
#define PDSS_INTR20_SET(m)                                  (*(volatile uint32_t *)(0x400a0524UL + ((m) * 0x10000UL)))
#define PDSS_INTR20_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR20_SET_LF_CNTR_MATCH                       (1UL << 30) /* <30:30> A:RW1S:0:LF_CNTR_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR20_SET_VSWAP_VBUS_LESS_5_DONE              (1UL << 31) /* <31:31> A:RW1S:0:SWAP_EN */


/*
 * INTR20_MASK
 */
#define PDSS_INTR20_MASK_ADDRESS(m)                         (0x400a0528UL + ((m) * (0x10000UL)))
#define PDSS_INTR20_MASK(m)                                 (*(volatile uint32_t *)(0x400a0528UL + ((m) * 0x10000UL)))
#define PDSS_INTR20_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR20_MASK_LF_CNTR_MASK                       (1UL << 30) /* <30:30> R:RW:0:LF_CNTR_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR20_MASK_VSWAP_VBUS_LESS_5_DONE_MASK        (1UL << 31) /* <31:31> R:RW:0:SWAP_EN */


/*
 * INTR20_MASKED
 */
#define PDSS_INTR20_MASKED_ADDRESS(m)                       (0x400a052cUL + ((m) * (0x10000UL)))
#define PDSS_INTR20_MASKED(m)                               (*(volatile uint32_t *)(0x400a052cUL + ((m) * 0x10000UL)))
#define PDSS_INTR20_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR20_MASKED_LF_CNTR_MASKED                   (1UL << 30) /* <30:30> RW:R:0:LF_CNTR_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR20_MASKED_VSWAP_VBUS_LESS_5_DONE_MASKED    (1UL << 31) /* <31:31> RW:R:0:SWAP_EN */


/*
 * IP DDFT0/1 and TR_OUT0/1 Selections
 */
#define PDSS_DDFT_DIG_MUX_ADDRESS(m)                        (0x400a0580UL + ((m) * (0x10000UL)))
#define PDSS_DDFT_DIG_MUX(m)                                (*(volatile uint32_t *)(0x400a0580UL + ((m) * 0x10000UL)))
#define PDSS_DDFT_DIG_MUX_DEFAULT                           (0x00000000UL)

/*
 * 255:60  : 1'b0
 * 59  :    PD_TOP/u_mxusbpd_cc/clk_tx
 * 58  :    PD_TOP/u_mxusbpd_clock_gates/clk_tx_half
 * 57  :    PD_TOP/u_mxusbpd_clock_gates/clk_filt[1]
 * 56  :    PD_TOP/u_mxusbpd_clock_gates/clk_filt[0]
 * 55  :    HIP_CFG_TOP/intr_tx_clk_en_hip
 * 54  :    DIG_MMIO/intr_tx_clk_en
 * 53  :    PD_TOP/u_mxusbpd_clock_gates/clk_isnk
 * 52  :    PD_TOP/u_mxusbpd_clock_gates/clk_refgen
 * 43  :    HIP_CFG_TOP/u_mxusbpd_hip_intr_ddft1_mux/ddft_out
 * 42  :    HIP_CFG_TOP/u_mxusbpd_hip_intr_ddft0_mux/ddft_out
 * 41  :    DIG_MMIO/u_mxusbpd_intr_ddft1_mux/ddft_out
 * 40  :    DIG_MMIO/u_mxusbpd_intr_ddft0_mux/ddft_out
 * 39  :    HIP_CFG_TOP/u_mxusbpd_ncell_ddft1_mux/ddft_out
 * 38  :    HIP_CFG_TOP/u_mxusbpd_ncell_ddft0_mux/ddft_out
 * 35  :    PD_TOP/y_hpdt/u_mxusbpd_hpd/intr_hpd_queue_event_set
 * 34  :    PD_TOP/y_hpdt/u_mxusbpd_hpd/intr_hpd_unstable_set
 * 33  :    PD_TOP/y_hpdt/u_mxusbpd_hpd/intr_hpd_unpluged_set
 * 32  :    PD_TOP/y_hpdt/u_mxusbpd_hpd/intr_hpd_plugged_set
 * 31  :    PD_TOP/y_hpdt/u_mxusbpd_hpd/intr_hpd_irq_set
 * 30  :    PD_TOP/y_hpdt/u_mxusbpd_hpdt/intr_hpdt_command_done_set
 * 29  :    HIP_FILT/u_hpd_change/intr_fx_scan
 * 28  :    PD_TOP/u_mxusbpd_tx/ddft_collision_src[4]
 * 27  :    PD_TOP/u_mxusbpd_tx/ddft_collision_src[3]
 * 26  :    PD_TOP/u_mxusbpd_tx/ddft_collision_src[2]
 * 25  :    PD_TOP/u_mxusbpd_tx/ddft_collision_src[1]
 * 24  :    PD_TOP/u_mxusbpd_tx/ddft_collision_src[0]
 * 20  :    PD_TOP/u_mxusbpd_cc/cc_rx_data
 * 19  :    DIG_TOP/y_swap/u_mxusbpd_swap/swapr_in_fx_scan
 * 18  :    PD_TOP/cc_ctrl_0_tx_en
 * 17  :    PD_TOP/u_mxusbpd_tx/cc_tx_data_eop
 * 16  :    PD_TOP/u_mxusbpd_tx/cc_tx_data_valid
 * 15  :    PD_TOP/u_mxusbpd_cc/clk_tx
 * 9   :   PD_TOP/u_mxusbpd_rx/sop_valid
 * 8   :   PD_TOP/u_mxusbpd_rx/eop
 * 7   :   PD_TOP/u_mxusbpd_cc/cc_rx_valid
 * 6   :   PD_TOP/u_mxusbpd_cc/cc_rx_bit
 * 5   :   PD_TOP/u_mxusbpd_tx/cc_tx_data
 * 4   :   PD_TOP/sip_cc_tx_data
 * 0   :   top/DUT/u_dut_mxusbpd_top/ext_ddft0_i
 */
#define PDSS_DDFT_DIG_MUX_DDFT0_SEL_MASK                    (0x0000007fUL) /* <0:6> R:RW:0: */
#define PDSS_DDFT_DIG_MUX_DDFT0_SEL_POS                     (0UL)


/*
 * 255:60  : 1'b0
 * 59  :    PD_TOP/u_mxusbpd_cc/clk_tx
 * 58  :    PD_TOP/u_mxusbpd_clock_gates/clk_tx_half
 * 57  :    PD_TOP/u_mxusbpd_clock_gates/clk_filt[1]
 * 56  :    PD_TOP/u_mxusbpd_clock_gates/clk_filt[0]
 * 55  :    HIP_CFG_TOP/intr_tx_clk_en_hip
 * 54  :    DIG_MMIO/intr_tx_clk_en
 * 53  :    PD_TOP/u_mxusbpd_clock_gates/clk_isnk
 * 52  :    PD_TOP/u_mxusbpd_clock_gates/clk_refgen
 * 43  :    HIP_CFG_TOP/u_mxusbpd_hip_intr_ddft1_mux/ddft_out
 * 42  :    HIP_CFG_TOP/u_mxusbpd_hip_intr_ddft0_mux/ddft_out
 * 41  :    DIG_MMIO/u_mxusbpd_intr_ddft1_mux/ddft_out
 * 40  :    DIG_MMIO/u_mxusbpd_intr_ddft0_mux/ddft_out
 * 39  :    HIP_CFG_TOP/u_mxusbpd_ncell_ddft1_mux/ddft_out
 * 38  :    HIP_CFG_TOP/u_mxusbpd_ncell_ddft0_mux/ddft_out
 * 35  :    PD_TOP/y_hpdt/u_mxusbpd_hpd/intr_hpd_queue_event_set
 * 34  :    PD_TOP/y_hpdt/u_mxusbpd_hpd/intr_hpd_unstable_set
 * 33  :    PD_TOP/y_hpdt/u_mxusbpd_hpd/intr_hpd_unpluged_set
 * 32  :    PD_TOP/y_hpdt/u_mxusbpd_hpd/intr_hpd_plugged_set
 * 31  :    PD_TOP/y_hpdt/u_mxusbpd_hpd/intr_hpd_irq_set
 * 30  :    PD_TOP/y_hpdt/u_mxusbpd_hpdt/intr_hpdt_command_done_set
 * 29  :    HIP_FILT/u_hpd_change/intr_fx_scan
 * 28  :    PD_TOP/u_mxusbpd_tx/ddft_collision_src[4]
 * 27  :    PD_TOP/u_mxusbpd_tx/ddft_collision_src[3]
 * 26  :    PD_TOP/u_mxusbpd_tx/ddft_collision_src[2]
 * 25  :    PD_TOP/u_mxusbpd_tx/ddft_collision_src[1]
 * 24  :    PD_TOP/u_mxusbpd_tx/ddft_collision_src[0]
 * 20  :    PD_TOP/u_mxusbpd_cc/cc_rx_data
 * 19  :    DIG_TOP/y_swap/u_mxusbpd_swap/swapr_in_fx_scan
 * 18  :    PD_TOP/cc_ctrl_0_tx_en
 * 17  :    PD_TOP/u_mxusbpd_tx/cc_tx_data_eop
 * 16  :    PD_TOP/u_mxusbpd_tx/cc_tx_data_valid
 * 15  :    PD_TOP/u_mxusbpd_cc/clk_tx
 * 9   :   PD_TOP/u_mxusbpd_rx/sop_valid
 * 8   :   PD_TOP/u_mxusbpd_rx/eop
 * 7   :   PD_TOP/u_mxusbpd_cc/cc_rx_valid
 * 6   :   PD_TOP/u_mxusbpd_cc/cc_rx_bit
 * 5   :   PD_TOP/u_mxusbpd_tx/cc_tx_data
 * 4   :   PD_TOP/sip_cc_tx_data
 * 0   :   top/DUT/u_dut_mxusbpd_top/ext_ddft0_i
 */
#define PDSS_DDFT_DIG_MUX_DDFT1_SEL_MASK                    (0x00003f80UL) /* <7:13> R:RW:0: */
#define PDSS_DDFT_DIG_MUX_DDFT1_SEL_POS                     (7UL)


/*
 * Interrupt DDFT Selections
 */
#define PDSS_INTR_DDFT_DIG_MUX_ADDRESS(m)                   (0x400a0584UL + ((m) * (0x10000UL)))
#define PDSS_INTR_DDFT_DIG_MUX(m)                           (*(volatile uint32_t *)(0x400a0584UL + ((m) * 0x10000UL)))
#define PDSS_INTR_DDFT_DIG_MUX_DEFAULT                      (0x00000000UL)

/*
 * 255:47 : 1'b0
 * 46  :    AGNOSTIC_REGS/intr2_vswap_vbus_less_5_done
 * 45  :    AGNOSTIC_REGS/intr2_hpd_irq
 * 44  :    AGNOSTIC_REGS/intr2_hpd_pluged
 * 43  :    AGNOSTIC_REGS/intr2_hpd_unpluged
 * 42  :    AGNOSTIC_REGS/intr2_hpd_unstable
 * 41  :    AGNOSTIC_REGS/intr2_hpdt_command_done
 * 40  :    AGNOSTIC_REGS/intr2_hpd_queue
 * 39  :    AGNOSTIC_REGS/intr2_lf_cntr_match
 * 38  :    AGNOSTIC_REGS/intr2_vreg20v_switch_done
 * 37  :    AGNOSTIC_REGS/intr2_vddd_sw_switch_done
 * 36  :    AGNOSTIC_REGS/intr2_swap_disconnect
 * 35  :    AGNOSTIC_REGS/intr2_swap_command_done
 * 34  :    AGNOSTIC_REGS/intr2_swap_pulse
 * 33  :    AGNOSTIC_REGS/intr2_swap_rcvd
 * 32  :    HIP_REG/intr1_drp_attached_detected
 * 31  :    AGNOSTIC_REGS/intr2_chunk_det
 * 30  :    AGNOSTIC_REGS/intr2_tx_sram_under_flow
 * 29  :    AGNOSTIC_REGS/intr2_rx_sram_over_flow
 * 28  :    AGNOSTIC_REGS/intr2_extended_msg_det
 * 27  :    AGNOSTIC_REGS/intr2_ui_cal_done
 * 26  :    AGNOSTIC_REGS/intr0_rx_state_idle
 * 25  :    AGNOSTIC_REGS/intr0_tx_state_idle
 * 24  :    AGNOSTIC_REGS/intr0_tx_regulator_enabled
 * 23  :    AGNOSTIC_REGS/intr0_tx_cc_data_oen_deassert
 * 22  :    AGNOSTIC_REGS/intr0_tx_cc_data_oen_assert
 * 21  :    AGNOSTIC_REGS/intr0_kchar_error
 * 20  :    AGNOSTIC_REGS/intr0_tx_retry_enable_clrd
 * 19  :    AGNOSTIC_REGS/intr0_rx_sram_half_end
 * 18  :    AGNOSTIC_REGS/intr0_tx_sram_half_end
 * 17  :    AGNOSTIC_REGS/intr0_collision_type4
 * 16  :    AGNOSTIC_REGS/intr0_collision_type3
 * 15  :    AGNOSTIC_REGS/intr0_collision_type2
 * 14  :    AGNOSTIC_REGS/intr0_collision_type1
 * 13  :    AGNOSTIC_REGS/intr0_crc_rx_timer_exp
 * 12  :    AGNOSTIC_REGS/intr0_cc_no_valid_data_detected
 * 11  :    AGNOSTIC_REGS/intr0_cc_valid_data_detected
 * 10  :    AGNOSTIC_REGS/intr0_tx_goodcrc_msg_done
 * 9   :   AGNOSTIC_REGS/intr0_rcv_rst
 * 8   :   AGNOSTIC_REGS/intr0_tx_hard_rst_done
 * 7   :   AGNOSTIC_REGS/intr0_tx_packet_done
 * 6   :   AGNOSTIC_REGS/intr0_rx_over_run
 * 5   :   AGNOSTIC_REGS/intr0_eop_error
 * 4   :   AGNOSTIC_REGS/intr0_rcv_expt_goodcrc_msg_complete
 * 3   :   AGNOSTIC_REGS/intr0_rcv_goodcrc_msg_complete
 * 2   :   AGNOSTIC_REGS/intr0_rx_sop
 * 1   :   AGNOSTIC_REGS/intr0_rcv_bad_packet_complete
 * 0   :   AGNOSTIC_REGS/intr0_rcv_good_packet_complete
 */
#define PDSS_INTR_DDFT_DIG_MUX_INTR_DDFT0_SEL_MASK          (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_INTR_DDFT_DIG_MUX_INTR_DDFT0_SEL_POS           (0UL)


/*
 * 255:47 : 1'b0
 * 46  :    AGNOSTIC_REGS/intr2_vswap_vbus_less_5_done
 * 45  :    AGNOSTIC_REGS/intr2_hpd_irq
 * 44  :    AGNOSTIC_REGS/intr2_hpd_pluged
 * 43  :    AGNOSTIC_REGS/intr2_hpd_unpluged
 * 42  :    AGNOSTIC_REGS/intr2_hpd_unstable
 * 41  :    AGNOSTIC_REGS/intr2_hpdt_command_done
 * 40  :    AGNOSTIC_REGS/intr2_hpd_queue
 * 39  :    AGNOSTIC_REGS/intr2_lf_cntr_match
 * 38  :    AGNOSTIC_REGS/intr2_vreg20v_switch_done
 * 37  :    AGNOSTIC_REGS/intr2_vddd_sw_switch_done
 * 36  :    AGNOSTIC_REGS/intr2_swap_disconnect
 * 35  :    AGNOSTIC_REGS/intr2_swap_command_done
 * 34  :    AGNOSTIC_REGS/intr2_swap_pulse
 * 33  :    AGNOSTIC_REGS/intr2_swap_rcvd
 * 32  :    HIP_REG/intr1_drp_attached_detected
 * 31  :    AGNOSTIC_REGS/intr2_chunk_det
 * 30  :    AGNOSTIC_REGS/intr2_tx_sram_under_flow
 * 29  :    AGNOSTIC_REGS/intr2_rx_sram_over_flow
 * 28  :    AGNOSTIC_REGS/intr2_extended_msg_det
 * 27  :    AGNOSTIC_REGS/intr2_ui_cal_done
 * 26  :    AGNOSTIC_REGS/intr0_rx_state_idle
 * 25  :    AGNOSTIC_REGS/intr0_tx_state_idle
 * 24  :    AGNOSTIC_REGS/intr0_tx_regulator_enabled
 * 23  :    AGNOSTIC_REGS/intr0_tx_cc_data_oen_deassert
 * 22  :    AGNOSTIC_REGS/intr0_tx_cc_data_oen_assert
 * 21  :    AGNOSTIC_REGS/intr0_kchar_error
 * 20  :    AGNOSTIC_REGS/intr0_tx_retry_enable_clrd
 * 19  :    AGNOSTIC_REGS/intr0_rx_sram_half_end
 * 18  :    AGNOSTIC_REGS/intr0_tx_sram_half_end
 * 17  :    AGNOSTIC_REGS/intr0_collision_type4
 * 16  :    AGNOSTIC_REGS/intr0_collision_type3
 * 15  :    AGNOSTIC_REGS/intr0_collision_type2
 * 14  :    AGNOSTIC_REGS/intr0_collision_type1
 * 13  :    AGNOSTIC_REGS/intr0_crc_rx_timer_exp
 * 12  :    AGNOSTIC_REGS/intr0_cc_no_valid_data_detected
 * 11  :    AGNOSTIC_REGS/intr0_cc_valid_data_detected
 * 10  :    AGNOSTIC_REGS/intr0_tx_goodcrc_msg_done
 * 9   :   AGNOSTIC_REGS/intr0_rcv_rst
 * 8   :   AGNOSTIC_REGS/intr0_tx_hard_rst_done
 * 7   :   AGNOSTIC_REGS/intr0_tx_packet_done
 * 6   :   AGNOSTIC_REGS/intr0_rx_over_run
 * 5   :   AGNOSTIC_REGS/intr0_eop_error
 * 4   :   AGNOSTIC_REGS/intr0_rcv_expt_goodcrc_msg_complete
 * 3   :   AGNOSTIC_REGS/intr0_rcv_goodcrc_msg_complete
 * 2   :   AGNOSTIC_REGS/intr0_rx_sop
 * 1   :   AGNOSTIC_REGS/intr0_rcv_bad_packet_complete
 * 0   :   AGNOSTIC_REGS/intr0_rcv_good_packet_complete
 */
#define PDSS_INTR_DDFT_DIG_MUX_INTR_DDFT1_SEL_MASK          (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_INTR_DDFT_DIG_MUX_INTR_DDFT1_SEL_POS           (8UL)


/*
 * ADC#1-4 SAR Control Register
 * General Purpose voltgae measurement, Temperature Sceining
 */
#define PDSS_ADC_SAR_CTRL_ADDRESS(m)                        (0x400a81c0UL + ((m) * (0x10000UL)))
#define PDSS_ADC_SAR_CTRL(m)                                (*(volatile uint32_t *)(0x400a81c0UL + ((m) * 0x10000UL)))
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
 * SWITCH control register for SBU_LRES. This register must be configured
 * after configuring the PD_30SBU_CLIPPER_CTRL  & PD_SBU_LRES_CTRL registers
 * and the filters contributing to the faults listed in this register's SEL_FAULT_EN
 * field. This controls the below inputs of SBU LRES signals. in1_out1_en,
 * in2_out1_en, in1_out2_en, in2_out2_en,
 */
#define PDSS_SWITCH_CTRL_00_ADDRESS(m)                      (0x400a8200UL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_00(m)                              (*(volatile uint32_t *)(0x400a8200UL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_00_DEFAULT                         (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_00_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_00_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_00_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_00_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_00_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 0: SBU1_OVP fault
 * 1: SBU2_OVP fault
 * 31-2: NA
 */
#define PDSS_SWITCH_CTRL_00_SEL_FAULT_EN_MASK               (0x00000300UL) /* <8:9> R:RW:0:SWITCH_00_FAULT_CNT */
#define PDSS_SWITCH_CTRL_00_SEL_FAULT_EN_POS                (8UL)


/*
 * SWITCH control register for SBU_HRES. This register must be configured
 * after configuring the PD_30SBU_CLIPPER_CTRL  & PD_SBU_HRES_CTRL registers
 * and the filters contributing to the faults listed in this register's SEL_FAULT_EN
 * field. This controls the below inputs of SBU_HRES signals. in1_out1_en,
 * in2_out1_en, in1_out2_en, in2_out2_en,
 */
#define PDSS_SWITCH_CTRL_01_ADDRESS(m)                      (0x400a8204UL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_01(m)                              (*(volatile uint32_t *)(0x400a8204UL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_01_DEFAULT                         (0x00000030UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_01_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_01_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_01_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_01_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:1: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_01_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:1: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 0: SBU1_OVP fault
 * 1: SBU2_OVP fault
 * 31-2: NA
 */
#define PDSS_SWITCH_CTRL_01_SEL_FAULT_EN_MASK               (0x00000300UL) /* <8:9> R:RW:0:SWITCH_01_FAULT_CNT */
#define PDSS_SWITCH_CTRL_01_SEL_FAULT_EN_POS                (8UL)


/*
 * SWITCH control register for SBU_LS. This register must be configured after
 * configuring the PD_30SBU_CLIPPER_CTRL  & PD_SBU_LS_CTRL registers and
 * the filters contributing to the faults listed in this register's SEL_FAULT_EN
 * field. This controls the below inputs of SBU_LS signals. in1_out1_en,
 * in2_out1_en, in1_out2_en, in2_out2_en,
 */
#define PDSS_SWITCH_CTRL_02_ADDRESS(m)                      (0x400a8208UL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_02(m)                              (*(volatile uint32_t *)(0x400a8208UL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_02_DEFAULT                         (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_02_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_02_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_02_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_02_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_02_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 0: SBU1_OVP fault
 * 1: SBU2_OVP fault
 * 31-2: NA
 */
#define PDSS_SWITCH_CTRL_02_SEL_FAULT_EN_MASK               (0x00000300UL) /* <8:9> R:RW:0:SWITCH_02_FAULT_CNT */
#define PDSS_SWITCH_CTRL_02_SEL_FAULT_EN_POS                (8UL)


/*
 * SWITCH control register for 30VCONN. This register must be configured
 * after configuring the PD_30VCONN_CTRL registers and the filters contributing
 * to the faults listed in this register's SEL_FAULT_EN field.This controls
 * the en_cc1_sw_lv input of 30VCONN.
 */
#define PDSS_SWITCH_CTRL_03_ADDRESS(m)                      (0x400a820cUL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_03(m)                              (*(volatile uint32_t *)(0x400a820cUL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_03_DEFAULT                         (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_03_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_03_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_03_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_03_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_03_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 8: CC1 OCP fault
 * 9: CC2 OCP fault
 * 10: CC1 OVP fault
 * 11: CC2 OVP fault
 * 12: VBUS UV fault
 * 13: VBUS OV fault
 * 31-14: NA
 */
#define PDSS_SWITCH_CTRL_03_SEL_FAULT_EN_MASK               (0x00003f00UL) /* <8:13> R:RW:0:SWITCH_03_FAULT_CNT */
#define PDSS_SWITCH_CTRL_03_SEL_FAULT_EN_POS                (8UL)


/*
 * SWITCH control register for 30VCONN. This register must be configured
 * after configuring the PD_30VCONN_CTRL registers and the filters contributing
 * to the faults listed in this register's SEL_FAULT_EN field.This controls
 * the en_cc2_sw_lv input of 30VCONN.
 */
#define PDSS_SWITCH_CTRL_04_ADDRESS(m)                      (0x400a8210UL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_04(m)                              (*(volatile uint32_t *)(0x400a8210UL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_04_DEFAULT                         (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_04_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_04_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_04_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_04_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_04_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 8: CC1 OCP fault
 * 9: CC2 OCP fault
 * 10: CC1 OVP fault
 * 11: CC2 OVP fault
 * 12: VBUS UV fault
 * 13: VBUS OV fault
 * 31-14: NA
 */
#define PDSS_SWITCH_CTRL_04_SEL_FAULT_EN_MASK               (0x00003f00UL) /* <8:13> R:RW:0:SWITCH_04_FAULT_CNT */
#define PDSS_SWITCH_CTRL_04_SEL_FAULT_EN_POS                (8UL)


/*
 * SWITCH control register for 30VCONN. This register must be configured
 * after configuring the PD_30VCONN_CTRL registers and the filters contributing
 * to the faults listed in this register's SEL_FAULT_EN field.This controls
 * the en_pump_lv input of 30VCONN.
 */
#define PDSS_SWITCH_CTRL_05_ADDRESS(m)                      (0x400a8214UL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_05(m)                              (*(volatile uint32_t *)(0x400a8214UL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_05_DEFAULT                         (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_05_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_05_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_05_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_05_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_05_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 8: CC1 OCP fault
 * 9: CC2 OCP fault
 * 10: CC1 OVP fault
 * 11: CC2 OVP fault
 * 31-12: NA
 */
#define PDSS_SWITCH_CTRL_05_SEL_FAULT_EN_MASK               (0x00000f00UL) /* <8:11> R:RW:0:SWITCH_05_FAULT_CNT */
#define PDSS_SWITCH_CTRL_05_SEL_FAULT_EN_POS                (8UL)


/*
 * SWITCH control register for NGDO_P5C40. This register must be configured
 * after configuring the SWAP related registers, COMP_CTRL, PD_TEMPNS_CTRL
 * & NGDO_P5C40_CTRL registers and the filters contributing to the faults
 * listed in this register's SEL_FAULT_EN field. This controls the gdrv_en
 * input of the NGDO_P5C40.
 */
#define PDSS_SWITCH_CTRL_06_ADDRESS(m)                      (0x400a8218UL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_06(m)                              (*(volatile uint32_t *)(0x400a8218UL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_06_DEFAULT                         (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_06_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_06_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_06_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_06_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_06_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 8: VBUS-C < 5V fault
 * 9:VBUS-P <5V  fault
 * 10: VBUS UV fault
 * 11: VBUS OV fault
 * 12: SCP fault
 * 13: RCP fault
 * 31-14: NA
 */
#define PDSS_SWITCH_CTRL_06_SEL_FAULT_EN_MASK               (0x00003f00UL) /* <8:13> R:RW:0:SWITCH_06_FAULT_CNT */
#define PDSS_SWITCH_CTRL_06_SEL_FAULT_EN_POS                (8UL)


/*
 * SWITCH control register for NGDO_P5C40. This register must be configured
 * after configuring the SWAP related registers, COMP_CTRL, PD_TEMPNS_CTRL
 * & NGDO_P5C40_CTRL registers and the filters contributing to the faults
 * listed in this register's SEL_FAULT_EN field. This controls the ngdo_en
 * input of the NGDO_P5C40.
 */
#define PDSS_SWITCH_CTRL_07_ADDRESS(m)                      (0x400a821cUL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_07(m)                              (*(volatile uint32_t *)(0x400a821cUL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_07_DEFAULT                         (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_07_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_07_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_07_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_07_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_07_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 8: VBUS-C < 5V fault
 * 9:VBUS-P <5V  fault
 * 10: VBUS UV fault
 * 11: VBUS OV fault
 * 12: SCP fault
 * 13: RCP fault
 * 31-14: NA
 */
#define PDSS_SWITCH_CTRL_07_SEL_FAULT_EN_MASK               (0x00003f00UL) /* <8:13> R:RW:0:SWITCH_07_FAULT_CNT */
#define PDSS_SWITCH_CTRL_07_SEL_FAULT_EN_POS                (8UL)


/*
 * SWITCH control register for NGDO_P5C40. This register must be configured
 * after configuring the SWAP related registers, COMP_CTRL, PD_TEMPNS_CTRL
 * & NGDO_P5C40_CTRL registers and the filters contributing to the faults
 * listed in this register's SEL_FAULT_EN field. This controls the cp_en
 * input of the NGDO_P5C40.
 */
#define PDSS_SWITCH_CTRL_08_ADDRESS(m)                      (0x400a8220UL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_08(m)                              (*(volatile uint32_t *)(0x400a8220UL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_08_DEFAULT                         (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_08_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_08_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_08_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_08_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_08_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 8: VBUS-C < 5V fault
 * 9:VBUS-P <5V  fault
 * 10: VBUS UV fault
 * 11: VBUS OV fault
 * 12: SCP fault
 * 13: RCP fault
 * 31-14: NA
 */
#define PDSS_SWITCH_CTRL_08_SEL_FAULT_EN_MASK               (0x00003f00UL) /* <8:13> R:RW:0:SWITCH_08_FAULT_CNT */
#define PDSS_SWITCH_CTRL_08_SEL_FAULT_EN_POS                (8UL)


/*
 * SWITCH control register for NGDO_P5C40. This register must be configured
 * after configuring the SWAP related registers, COMP_CTRL, PD_TEMPNS_CTRL
 * & NGDO_P5C40_CTRL registers and the filters contributing to the faults
 * listed in this register's SEL_FAULT_EN field. This controls the keep_off_disable
 * input of the NGDO_P5C40.
 */
#define PDSS_SWITCH_CTRL_09_ADDRESS(m)                      (0x400a8224UL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_09(m)                              (*(volatile uint32_t *)(0x400a8224UL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_09_DEFAULT                         (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_09_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_09_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_09_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_09_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_09_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 8: VBUS-C < 5V fault
 * 9:VBUS-P <5V  fault
 * 10: VBUS UV fault
 * 11: VBUS OV fault
 * 12: SCP fault
 * 13: RCP fault
 * 31-14: NA
 */
#define PDSS_SWITCH_CTRL_09_SEL_FAULT_EN_MASK               (0x00003f00UL) /* <8:13> R:RW:0:SWITCH_09_FAULT_CNT */
#define PDSS_SWITCH_CTRL_09_SEL_FAULT_EN_POS                (8UL)


/*
 * SWITCH control register for FRS. This register must be configured after
 * configuring the FRS_CTRL registers and the filters contributing to the
 * faults listed in this register's SEL_FAULT_EN field. This controls the
 * frs_cp_en input of the FRS.
 */
#define PDSS_SWITCH_CTRL_10_ADDRESS(m)                      (0x400a8228UL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_10(m)                              (*(volatile uint32_t *)(0x400a8228UL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_10_DEFAULT                         (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_10_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_10_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_10_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_10_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_10_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 8: VBUS-C < 5V fault
 * 9:VBUS-P <5V  fault
 * 31-10: NA
 */
#define PDSS_SWITCH_CTRL_10_SEL_FAULT_EN_MASK               (0x00000300UL) /* <8:9> R:RW:0:SWITCH_10_FAULT_CNT */
#define PDSS_SWITCH_CTRL_10_SEL_FAULT_EN_POS                (8UL)


/*
 * SWITCH control register for FRS. This register must be configured after
 * configuring the FRS_CTRLregisters and the filters contributing to the
 * faults listed in this register's SEL_FAULT_EN field. This controls the
 * frs_sw_en input of the FRS.
 */
#define PDSS_SWITCH_CTRL_11_ADDRESS(m)                      (0x400a822cUL + ((m) * (0x10000UL)))
#define PDSS_SWITCH_CTRL_11(m)                              (*(volatile uint32_t *)(0x400a822cUL + ((m) * 0x10000UL)))
#define PDSS_SWITCH_CTRL_11_DEFAULT                         (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the gate Driver Enable
 * 1: HW controlls the gate Driver Enable
 */
#define PDSS_SWITCH_CTRL_11_AUTO_MODE                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control bit.
 * Writing 1 to this bit will reset the edge detector in the switch controller,
 * following which this bit is auto cleared by the HW.
 */
#define PDSS_SWITCH_CTRL_11_RST_EDGE_DET                    (1UL << 1) /* <1:1> RW1C:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the gate driver
 * enable in order to open the gate
 */
#define PDSS_SWITCH_CTRL_11_EN_SWITCH_OFF_VALUE             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The On value used by Hardware in Automode to turn on the gate driver enable
 * in order to close the gate
 */
#define PDSS_SWITCH_CTRL_11_EN_SWITCH_ON_VALUE              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * FW can use this register to inform the hardware to drive the ON value
 * or OFF value when a fault is detected. This is for Debug only
 * 0: Select OFF
 * 1: Select ON
 */
#define PDSS_SWITCH_CTRL_11_SEL_ON_OFF                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Each bit enables the respective fault as a source to control the gate
 * driver enable. Any fault asserted, will set a SET flop
 * The list of faults and the corresponding enable bit for this product is
 * listed below.
 * 8: VBUS-C < 5V fault
 * 9:VBUS-P <5V  fault
 * 31-10: NA
 */
#define PDSS_SWITCH_CTRL_11_SEL_FAULT_EN_MASK               (0x00000300UL) /* <8:9> R:RW:0:SWITCH_11_FAULT_CNT */
#define PDSS_SWITCH_CTRL_11_SEL_FAULT_EN_POS                (8UL)


/*
 * Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR1_CFG_ADDRESS(m)                           (0x400a82a0UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_CFG(m)                                   (*(volatile uint32_t *)(0x400a82a0UL + ((m) * 0x10000UL)))
#define PDSS_INTR1_CFG_DEFAULT                              (0x00000000UL)

/*
 * Filtering the v5v_det from s8usbpd so FW can enable the VCONN FET to route
 * the V5V to appropriate VCONN line (CC1/CC2)
 * 0: No Filtering
 * 1: Enable 2 cycles of clk_lf filtering
 */
#define PDSS_INTR1_CFG_V5V_FILT_EN                          (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_V5V_CFG_MASK                         (0x00001800UL) /* <11:12> R:RW:0: */
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
#define PDSS_INTR1_CFG_V5V_FILT_RESET                       (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_V5V_FILT_BYPASS                      (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Filtering the HPDIN_ATTACH .
 * 0: No Filtering
 * 1: Enable 2 cycles of clk_lf filtering
 */
#define PDSS_INTR1_CFG_HPDIN_FILT_EN                        (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable. For HPD_IN input
 */
#define PDSS_INTR1_CFG_HPDIN_CFG_MASK                       (0x00030000UL) /* <16:17> R:RW:0: */
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
#define PDSS_INTR1_CFG_HPDIN_FILT_RESET                     (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_HPDIN_FILT_BYPASS                    (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_VCMP_LA_CFG_MASK                     (0x00300000UL) /* <20:21> R:RW:0: */
#define PDSS_INTR1_CFG_VCMP_LA_CFG_POS                      (20UL)


/*
 * CC1/CC2 Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_ADDRESS(m)                (0x400a82a4UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_CFG_CC1_CC2_LS(m)                        (*(volatile uint32_t *)(0x400a82a4UL + ((m) * 0x10000UL)))
#define PDSS_INTR1_CFG_CC1_CC2_LS_DEFAULT                   (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_EN               (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_CFG_MASK              (0x00000006UL) /* <1:2> R:RW:0: */
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
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_RESET            (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_BYPASS           (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_SEL_MASK         (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_SEL_POS          (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_EN               (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_CFG_MASK              (0x00001800UL) /* <11:12> R:RW:0: */
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
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_RESET            (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_BYPASS           (1UL << 14) /* <14:14> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_SEL_MASK         (0x000f8000UL) /* <15:19> R:RW:0: */
#define PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_SEL_POS          (15UL)


/*
 * VCMP_UP/DOWN/FS Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_ADDRESS(m)           (0x400a82a8UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS(m)                   (*(volatile uint32_t *)(0x400a82a8UL + ((m) * 0x10000UL)))
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_DEFAULT              (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_EN      (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_CFG_MASK     (0x00000006UL) /* <1:2> R:RW:0: */
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
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_RESET    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_BYPASS    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_SEL_POS    (5UL)


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_EN      (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_CFG_MASK     (0x00001800UL) /* <11:12> R:RW:0: */
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
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_RESET    (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_BYPASS    (1UL << 14) /* <14:14> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_SEL_MASK    (0x000f8000UL) /* <15:19> R:RW:0: */
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_SEL_POS    (15UL)


/*
 * CC1/CC2 OCP Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR1_CFG_CC12_OCP_HS_ADDRESS(m)               (0x400a82acUL + ((m) * (0x10000UL)))
#define PDSS_INTR1_CFG_CC12_OCP_HS(m)                       (*(volatile uint32_t *)(0x400a82acUL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_CFG_CC12_OVP_HS_ADDRESS(m)               (0x400a82b0UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_CFG_CC12_OVP_HS(m)                       (*(volatile uint32_t *)(0x400a82b0UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_STATUS_ADDRESS(m)                        (0x400a82b4UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_STATUS(m)                                (*(volatile uint32_t *)(0x400a82b4UL + ((m) * 0x10000UL)))
#define PDSS_INTR1_STATUS_DEFAULT                           (0x00000000UL)

/*
 * CC1 status (wakeup interrupt from deepsleep)
 * 1: CC1 attached
 * 0: CC1 detached
 */
#define PDSS_INTR1_STATUS_CC1_STATUS                        (1UL << 4) /* <4:4> RW:R:0: */


/*
 * CC1 Filtered output
 */
#define PDSS_INTR1_STATUS_CC1_FILT                          (1UL << 5) /* <5:5> RW:R:0: */


/*
 * CC2 status (wakeup interrupt from deepsleep)
 * 1: CC2 attached
 * 0: CC2 detached
 */
#define PDSS_INTR1_STATUS_CC2_STATUS                        (1UL << 6) /* <6:6> RW:R:0: */


/*
 * CC2 Filtered output
 */
#define PDSS_INTR1_STATUS_CC2_FILT                          (1UL << 7) /* <7:7> RW:R:0: */


/*
 * This register provides the status CC_LINE_ACTIVITY (wakeup interrupt from
 * deepsleep).
 */
#define PDSS_INTR1_STATUS_VCMP_LA_STATUS                    (1UL << 8) /* <8:8> RW:R:0: */


/*
 * VCMP_LA Filtered output
 */
#define PDSS_INTR1_STATUS_VCMP_LA_FILT                      (1UL << 9) /* <9:9> RW:R:0: */


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
#define PDSS_INTR1_STATUS_VCMP_UP_STATUS                    (1UL << 10) /* <10:10> RW:R:0: */


/*
 * VCMP_UP Filtered output
 */
#define PDSS_INTR1_STATUS_VCMP_UP_FILT                      (1UL << 11) /* <11:11> RW:R:0: */


/*
 * This register provides the status of VCMP_DN (wakeup interrupt from deepsleep).
 * Not enabled unless CMP_EN bit is set.
 * Edge: Ra/Rd value changed
 *                OR
 * Edge: Rp value changed
 */
#define PDSS_INTR1_STATUS_VCMP_DN_STATUS                    (1UL << 12) /* <12:12> RW:R:0: */


/*
 * VCMP_DN Filtered output
 */
#define PDSS_INTR1_STATUS_VCMP_DN_FILT                      (1UL << 13) /* <13:13> RW:R:0: */


/*
 * This status bit shows the v5v from 300ma or Vconn20
 */
#define PDSS_INTR1_STATUS_V5V_STATUS                        (1UL << 14) /* <14:14> RW:R:0: */


/*
 * V5V Filtered output
 */
#define PDSS_INTR1_STATUS_V5V_FILT                          (1UL << 15) /* <15:15> RW:R:0: */


/*
 * This reads the level of HPD input from GPIO.
 */
#define PDSS_INTR1_STATUS_HPD_STATUS                        (1UL << 16) /* <16:16> RW:R:0: */


/*
 * HDPIN OUT Filtered output
 */
#define PDSS_INTR1_STATUS_HPD_FILT                          (1UL << 17) /* <17:17> RW:R:0: */


/*
 * This reads the CC1 over-current signal from s8usbpd2_20Vconn_sw_top
 */
#define PDSS_INTR1_STATUS_CC1_OCP_STATUS                    (1UL << 18) /* <18:18> RW:R:0: */


/*
 * CC1_OCP Detect Filtered output
 */
#define PDSS_INTR1_STATUS_CC1_OCP_FILT                      (1UL << 19) /* <19:19> RW:R:0: */


/*
 * This reads the CC2 over-current signal from s8usbpd2_20Vconn_sw_top
 */
#define PDSS_INTR1_STATUS_CC2_OCP_STATUS                    (1UL << 20) /* <20:20> RW:R:0: */


/*
 * CC2_OCP Detect Filtered output
 */
#define PDSS_INTR1_STATUS_CC2_OCP_FILT                      (1UL << 21) /* <21:21> RW:R:0: */


/*
 * This reads the CC1 over-voltage signal from s8usbpd2_20Vconn_sw_top
 */
#define PDSS_INTR1_STATUS_CC1_OVP_STATUS                    (1UL << 22) /* <22:22> RW:R:0: */


/*
 * CC1_OVP Detect Filtered output
 */
#define PDSS_INTR1_STATUS_CC1_OVP_FILT                      (1UL << 23) /* <23:23> RW:R:0: */


/*
 * This reads the CC2 over-voltage signal from s8usbpd2_20Vconn_sw_top
 */
#define PDSS_INTR1_STATUS_CC2_OVP_STATUS                    (1UL << 24) /* <24:24> RW:R:0: */


/*
 * CC2_OVP Detect Filtered output
 */
#define PDSS_INTR1_STATUS_CC2_OVP_FILT                      (1UL << 25) /* <25:25> RW:R:0: */


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
#define PDSS_INTR1_ADDRESS(m)                               (0x400a82b8UL + ((m) * (0x10000UL)))
#define PDSS_INTR1(m)                                       (*(volatile uint32_t *)(0x400a82b8UL + ((m) * 0x10000UL)))
#define PDSS_INTR1_DEFAULT                                  (0x00000000UL)

/*
 * CC1 changed (wakeup interrupt from deepsleep)
 * Check the STATUS.CC1_STATUS value
 */
#define PDSS_INTR1_CC1_CHANGED                              (1UL << 2) /* <2:2> RW1S:RW1C:0: */


/*
 * CC2 changed (wakeup interrupt from deepsleep)
 * Check the STATUS.CC2_STATUS value
 */
#define PDSS_INTR1_CC2_CHANGED                              (1UL << 3) /* <3:3> RW1S:RW1C:0: */


/*
 * VCMP_LA changed (wakeup interrupt from deepsleep)
 * Check the STATUS.VCMP_LA_STATUS value
 */
#define PDSS_INTR1_VCMP_LA_CHANGED                          (1UL << 4) /* <4:4> RW1S:RW1C:0: */


/*
 * VCMP_UP changed (wakeup interrupt from deepsleep)
 * Check the STATUS.VCMP_UP_STATUS value
 */
#define PDSS_INTR1_VCMP_UP_CHANGED                          (1UL << 5) /* <5:5> RW1S:RW1C:0: */


/*
 * VCMP_DN changed (wakeup interrupt from deepsleep)
 * Check the STATUS.VCMP_DN_STATUS value
 */
#define PDSS_INTR1_VCMP_DN_CHANGED                          (1UL << 6) /* <6:6> RW1S:RW1C:0: */


/*
 * V5V changed (wakeup interrupt from deepsleep)
 * Check the STATUS.V5V_STATUS value
 */
#define PDSS_INTR1_V5V_CHANGED                              (1UL << 7) /* <7:7> RW1S:RW1C:0: */


/*
 * HPD_IN changed (wakeup interrupt from deepsleep). For HPD input
 * Check the STATUS.HPDIN_STATUS value. Any change in HPD input will trigger
 * a wakeup interrupt.
 */
#define PDSS_INTR1_HPDIN_CHANGED                            (1UL << 8) /* <8:8> RW1S:RW1C:0: */


/*
 * Over-Current is detected on CC1 line
 */
#define PDSS_INTR1_CC1_OCP_CHANGED                          (1UL << 9) /* <9:9> RW1S:RW1C:0: */


/*
 * Over-Current is detected on CC2 line
 */
#define PDSS_INTR1_CC2_OCP_CHANGED                          (1UL << 10) /* <10:10> RW1S:RW1C:0: */


/*
 * Over-Voltage is detected on CC1 line
 */
#define PDSS_INTR1_CC1_OVP_CHANGED                          (1UL << 11) /* <11:11> RW1S:RW1C:0: */


/*
 * Over-Voltage is detected on CC2 line
 */
#define PDSS_INTR1_CC2_OVP_CHANGED                          (1UL << 12) /* <12:12> RW1S:RW1C:0: */


/*
 * VSWAP and VBUS_C less that 5V is detected
 */
#define PDSS_INTR1_DRP_ATTACHED_DETECTED                    (1UL << 18) /* <18:18> RW1S:RW1C:0:RPRD_EN */


/*
 * INTR1 Set
 */
#define PDSS_INTR1_SET_ADDRESS(m)                           (0x400a82bcUL + ((m) * (0x10000UL)))
#define PDSS_INTR1_SET(m)                                   (*(volatile uint32_t *)(0x400a82bcUL + ((m) * 0x10000UL)))
#define PDSS_INTR1_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC1_CHANGED                          (1UL << 2) /* <2:2> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC2_CHANGED                          (1UL << 3) /* <3:3> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_VCMP_LA_CHANGED                      (1UL << 4) /* <4:4> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_VCMP_UP_CHANGED                      (1UL << 5) /* <5:5> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_VCMP_DN_CHANGED                      (1UL << 6) /* <6:6> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_V5V_CHANGED                          (1UL << 7) /* <7:7> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_HPDIN_CHANGED                        (1UL << 8) /* <8:8> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC1_OCP_CHANGED                      (1UL << 9) /* <9:9> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC2_OCP_CHANGED                      (1UL << 10) /* <10:10> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC1_OVP_CHANGED                      (1UL << 11) /* <11:11> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CC2_OVP_CHANGED                      (1UL << 12) /* <12:12> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_DRP_ATTACHED_DETECTED                (1UL << 18) /* <18:18> A:RW1S:0:RPRD_EN */


/*
 * INTR1 Mask
 */
#define PDSS_INTR1_MASK_ADDRESS(m)                          (0x400a82c0UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_MASK(m)                                  (*(volatile uint32_t *)(0x400a82c0UL + ((m) * 0x10000UL)))
#define PDSS_INTR1_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC1_CHANGED_MASK                    (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC2_CHANGED_MASK                    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_VCMP_LA_CHANGED_MASK                (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_VCMP_UP_CHANGED_MASK                (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_VCMP_DN_CHANGED_MASK                (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_V5V_CHANGED_MASK                    (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_HPDIN_CHANGED_MASK                  (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC1_OCP_CHANGED_MASK                (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC2_OCP_CHANGED_MASK                (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC1_OVP_CHANGED_MASK                (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CC2_OVP_CHANGED_MASK                (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_DRP_ATTACHED_DETECTED_MASK          (1UL << 18) /* <18:18> R:RW:0:RPRD_EN */


/*
 * INTR1 Masked
 */
#define PDSS_INTR1_MASKED_ADDRESS(m)                        (0x400a82c4UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_MASKED(m)                                (*(volatile uint32_t *)(0x400a82c4UL + ((m) * 0x10000UL)))
#define PDSS_INTR1_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC1_CHANGED_MASKED                (1UL << 2) /* <2:2> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC2_CHANGED_MASKED                (1UL << 3) /* <3:3> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_VCMP_LA_CHANGED_MASKED            (1UL << 4) /* <4:4> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_VCMP_UP_CHANGED_MASKED            (1UL << 5) /* <5:5> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_VCMP_DN_CHANGED_MASKED            (1UL << 6) /* <6:6> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_V5V_CHANGED_MASKED                (1UL << 7) /* <7:7> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_HPDIN_CHANGED_MASKED              (1UL << 8) /* <8:8> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC1_OCP_CHANGED_MASKED            (1UL << 9) /* <9:9> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC2_OCP_CHANGED_MASKED            (1UL << 10) /* <10:10> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC1_OVP_CHANGED_MASKED            (1UL << 11) /* <11:11> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CC2_OVP_CHANGED_MASKED            (1UL << 12) /* <12:12> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_DRP_ATTACHED_DETECTED_MASKED      (1UL << 18) /* <18:18> RW:R:0:RPRD_EN */


/*
 * VSYS Wakeup Interrupts edge and filter configuration 1
 */
#define PDSS_INTR3_CFG_VSYS_ADDRESS(m)                      (0x400a8300UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_CFG_VSYS(m)                              (*(volatile uint32_t *)(0x400a8300UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_CFG_VSYS_DEFAULT                         (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR3_CFG_VSYS_VSYS_FILT_EN                    (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR3_CFG_VSYS_VSYS_CFG_MASK                   (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR3_CFG_VSYS_VSYS_CFG_POS                    (1UL)


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
#define PDSS_INTR3_CFG_VSYS_VSYS_FILT_RESET                 (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR3_CFG_VSYS_VSYS_FILT_BYPASS                (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR3_CFG_VSYS_VSYS_FILT_SEL_MASK              (0x000000e0UL) /* <5:7> R:RW:0: */
#define PDSS_INTR3_CFG_VSYS_VSYS_FILT_SEL_POS               (5UL)


/*
 * ADC1-4 High/Low Speed Filter and Edge detector configuration
 */
#define PDSS_INTR3_CFG_ADC_HS_ADDRESS(m)                    (0x400a8304UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_CFG_ADC_HS(m)                            (*(volatile uint32_t *)(0x400a8304UL + ((m) * 0x10000UL)))
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
 * SBU201-4 SBU1/2  Over-Voltage High/Low Speed Filter and Edge detector
 * configuration
 */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_ADDRESS(m)              (0x400a8324UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_CFG_SBU20_OVP_HS(m)                      (*(volatile uint32_t *)(0x400a8324UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_CFG_SBU20_OVP_HS_DEFAULT                 (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_EN            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_CFG_MASK      (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_CFG_POS       (1UL)


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
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_RESET         (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_BYPASS        (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_SEL_MASK      (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_SEL_POS       (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_DPSLP_MODE         (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_EN            (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_CFG_MASK      (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_CFG_POS       (12UL)


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
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_RESET         (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_BYPASS        (1UL << 15) /* <15:15> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_SEL_MASK      (0x001f0000UL) /* <16:20> R:RW:0: */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_SEL_POS       (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_DPSLP_MODE         (1UL << 21) /* <21:21> R:RW:0: */


/*
 * 20V Regulator#1-4 VBUS Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR3_CFG_VREG20_VBUS_ADDRESS(m)               (0x400a8338UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_CFG_VREG20_VBUS(m)                       (*(volatile uint32_t *)(0x400a8338UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_CFG_VREG20_VBUS_DEFAULT                  (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_FILT_EN        (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_CFG_MASK       (0x00000030UL) /* <4:5> R:RW:0: */
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_CFG_POS        (4UL)


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
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_FILT_RESET     (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_FILT_BYPASS    (1UL << 16) /* <16:16> R:RW:0: */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_FILT_SEL_MASK    (0x00700000UL) /* <20:22> R:RW:0: */
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_FILT_SEL_POS    (20UL)


/*
 * INTR3 Status 0
 */
#define PDSS_INTR3_STATUS_0_ADDRESS(m)                      (0x400a8340UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_STATUS_0(m)                              (*(volatile uint32_t *)(0x400a8340UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_STATUS_0_DEFAULT                         (0x00000000UL)

/*
 * The status of vsys_det from the s8usbpd_ver3_vddd_sw_top
 */
#define PDSS_INTR3_STATUS_0_VSYS_STATUS                     (1UL << 0) /* <0:0> RW:R:0: */


/*
 * CC1 Filtered output
 */
#define PDSS_INTR3_STATUS_0_VSYS_FILT                       (1UL << 1) /* <1:1> RW:R:0: */


/*
 * The status of cmp_out from the ADC#1-4
 */
#define PDSS_INTR3_STATUS_0_CMP_OUT_STATUS                  (1UL << 2) /* <2:2> RW:R:0: */


/*
 * ADC1-4 COMP_OUT Filtered output
 */
#define PDSS_INTR3_STATUS_0_CMP_OUT_FILT                    (1UL << 3) /* <3:3> RW:R:0: */


/*
 * INTR3 Status 1
 */
#define PDSS_INTR3_STATUS_1_ADDRESS(m)                      (0x400a8344UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_STATUS_1(m)                              (*(volatile uint32_t *)(0x400a8344UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_STATUS_1_DEFAULT                         (0x00000000UL)

/*
 * The status of vbus_det from the s8usbpd_ver3 Regulator#1-4
 */
#define PDSS_INTR3_STATUS_1_VREG20_VBUS_STATUS              (1UL << 0) /* <0:0> RW:R:0: */


/*
 * CC1 Filtered output
 */
#define PDSS_INTR3_STATUS_1_VREG20_VBUS_FILT                (1UL << 4) /* <4:4> RW:R:0: */


/*
 * The status of sbu1_ovp/sbu2_ovp from the s8usbpdv2_sbu20_top#1-4
 */
#define PDSS_INTR3_STATUS_1_SBU1_SBU2_OVP_STATUS_MASK       (0x00030000UL) /* <16:17> RW:R:0: */
#define PDSS_INTR3_STATUS_1_SBU1_SBU2_OVP_STATUS_POS        (16UL)


/*
 * sbu1_ovp/sbu2_ovp Filtered output
 */
#define PDSS_INTR3_STATUS_1_SBU1_SBU2_OVP_FILT_MASK         (0x03000000UL) /* <24:25> RW:R:0: */
#define PDSS_INTR3_STATUS_1_SBU1_SBU2_OVP_FILT_POS          (24UL)


/*
 * INTR3 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin.
 */
#define PDSS_INTR3_ADDRESS(m)                               (0x400a8348UL + ((m) * (0x10000UL)))
#define PDSS_INTR3(m)                                       (*(volatile uint32_t *)(0x400a8348UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_DEFAULT                                  (0x00000000UL)

/*
 * vsys_det changed (wakeup interrupt from deepsleep)
 * Check the  INTR3_STATUS.VSYS_STATUS value
 */
#define PDSS_INTR3_VSYS_CHANGED                             (1UL << 0) /* <0:0> RW1S:RW1C:0: */


/*
 * CMP_OUT1-4 changed (wakeup interrupt from deepsleep)
 * Check the INTR3_STATUS.ADC_CMP_OUT_STATUS value
 */
#define PDSS_INTR3_CMP_OUT_CHANGED                          (1UL << 1) /* <1:1> RW1S:RW1C:0: */


/*
 * vbus_c_det changed (wakeup interrupt from deepsleep)
 * Check the  INTR3_STATUS.VREG20_VBUS_STATUS value
 */
#define PDSS_INTR3_VREG20_VBUS_CHANGED                      (1UL << 13) /* <13:13> RW1S:RW1C:0: */


/*
 * sbu1_ovp/sbu2_ovp changed (wakeup interrupt from deepsleep)
 * Check the  INTR3_STATUS.SBU1_SBU2_OVP_STATUS value
 */
#define PDSS_INTR3_SBU1_SBU2_OVP_CHANGED_MASK               (0x00600000UL) /* <21:22> RW1S:RW1C:0: */
#define PDSS_INTR3_SBU1_SBU2_OVP_CHANGED_POS                (21UL)


/*
 * INTR3 Interrupt Set
 */
#define PDSS_INTR3_SET_ADDRESS(m)                           (0x400a834cUL + ((m) * (0x10000UL)))
#define PDSS_INTR3_SET(m)                                   (*(volatile uint32_t *)(0x400a834cUL + ((m) * 0x10000UL)))
#define PDSS_INTR3_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_VSYS_CHANGED                         (1UL << 0) /* <0:0> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_CMP_OUT_CHANGED                      (1UL << 1) /* <1:1> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_VREG20_VBUS_CHANGED                  (1UL << 13) /* <13:13> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_SBU1_SBU2_OVP_CHANGED_MASK           (0x00600000UL) /* <21:22> A:RW1S:0: */
#define PDSS_INTR3_SET_SBU1_SBU2_OVP_CHANGED_POS            (21UL)


/*
 * INTR3 interrupt Mask
 */
#define PDSS_INTR3_MASK_ADDRESS(m)                          (0x400a8350UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_MASK(m)                                  (*(volatile uint32_t *)(0x400a8350UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_VSYS_CHANGED_MASK                   (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_CMP_OUT_CHANGED_MASK                (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_VREG20_VBUS_CHANGED_MASK            (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_SBU1_SBU2_OVP_CHANGED_MASK_MASK     (0x00600000UL) /* <21:22> R:RW:0: */
#define PDSS_INTR3_MASK_SBU1_SBU2_OVP_CHANGED_MASK_POS      (21UL)


/*
 * INTR3 interrupt Masked
 */
#define PDSS_INTR3_MASKED_ADDRESS(m)                        (0x400a8354UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_MASKED(m)                                (*(volatile uint32_t *)(0x400a8354UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_VSYS_CHANGED_MASKED               (1UL << 0) /* <0:0> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_CMP_OUT_CHANGED_MASKED            (1UL << 1) /* <1:1> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_VREG20_VBUS_CHANGED_MASKED        (1UL << 13) /* <13:13> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_SBU1_SBU2_OVP_CHANGED_MASKED_MASK    (0x00600000UL) /* <21:22> RW:R:0: */
#define PDSS_INTR3_MASKED_SBU1_SBU2_OVP_CHANGED_MASKED_POS    (21UL)


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
#define PDSS_INTR5_FILTER_CFG_ADDRESS(m,n)                  (0x400a8380UL + ((m) * (0x10000UL)) + ((n) * (0x0004UL)))
#define PDSS_INTR5_FILTER_CFG(m,n)                          (*(volatile uint32_t *)(0x400a8380UL + ((m) * (0x10000UL)) + ((n) * 0x0004)))
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
#define PDSS_INTR5_STATUS_0_ADDRESS(m)                      (0x400a83e0UL + ((m) * (0x10000UL)))
#define PDSS_INTR5_STATUS_0(m)                              (*(volatile uint32_t *)(0x400a83e0UL + ((m) * 0x10000UL)))
#define PDSS_INTR5_STATUS_0_DEFAULT                         (0x00000000UL)

/*
 * The status of HS/LS filter edge detectors 1-12
 */
#define PDSS_INTR5_STATUS_0_STATUS_12_MASK                  (0x0000000fUL) /* <0:3> RW:R:0:CLK_FILTER_FILT_NUM_LOG1_12 */
#define PDSS_INTR5_STATUS_0_STATUS_12_POS                   (0UL)


/*
 * 1-12 HS/LS Filtered output
 */
#define PDSS_INTR5_STATUS_0_FILT_12_MASK                    (0x0000f000UL) /* <12:15> RW:R:0:CLK_FILTER_FILT_NUM_LOG1_12 */
#define PDSS_INTR5_STATUS_0_FILT_12_POS                     (12UL)


/*
 * INTR5 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin from HS filters
 */
#define PDSS_INTR5_ADDRESS(m)                               (0x400a83e8UL + ((m) * (0x10000UL)))
#define PDSS_INTR5(m)                                       (*(volatile uint32_t *)(0x400a83e8UL + ((m) * 0x10000UL)))
#define PDSS_INTR5_DEFAULT                                  (0x00000000UL)

/*
 * Change in edge of HS filter edge detectors (wakeup interrupt from deepsleep)
 * Check the  INTR5_STATUS_0/1.STATUS_12/24 value
 */
#define PDSS_INTR5_EDGE_CHANGED_MASK                        (0x0000000fUL) /* <0:3> RW1S:RW1C:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_EDGE_CHANGED_POS                         (0UL)


/*
 * INTR5 Interrupt Set
 */
#define PDSS_INTR5_SET_ADDRESS(m)                           (0x400a83ecUL + ((m) * (0x10000UL)))
#define PDSS_INTR5_SET(m)                                   (*(volatile uint32_t *)(0x400a83ecUL + ((m) * 0x10000UL)))
#define PDSS_INTR5_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR5_SET_EDGE_CHANGED_MASK                    (0x0000000fUL) /* <0:3> A:RW1S:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_SET_EDGE_CHANGED_POS                     (0UL)


/*
 * INTR5 interrupt Mask
 */
#define PDSS_INTR5_MASK_ADDRESS(m)                          (0x400a83f0UL + ((m) * (0x10000UL)))
#define PDSS_INTR5_MASK(m)                                  (*(volatile uint32_t *)(0x400a83f0UL + ((m) * 0x10000UL)))
#define PDSS_INTR5_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR5_MASK_EDGE_CHANGED_MASK_MASK              (0x0000000fUL) /* <0:3> R:RW:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_MASK_EDGE_CHANGED_MASK_POS               (0UL)


/*
 * INTR5 interrupt Masked
 */
#define PDSS_INTR5_MASKED_ADDRESS(m)                        (0x400a83f4UL + ((m) * (0x10000UL)))
#define PDSS_INTR5_MASKED(m)                                (*(volatile uint32_t *)(0x400a83f4UL + ((m) * 0x10000UL)))
#define PDSS_INTR5_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR5_MASKED_EDGE_CHANGED_MASKED_MASK          (0x0000000fUL) /* <0:3> RW:R:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_MASKED_EDGE_CHANGED_MASKED_POS           (0UL)


/*
 * CLK_LF ONLY Filter configuration
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 */
#define PDSS_INTR7_FILTER_CFG_ADDRESS(m)                    (0x400a8420UL + ((m) * (0x10000UL)))
#define PDSS_INTR7_FILTER_CFG(m)                            (*(volatile uint32_t *)(0x400a8420UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR7_STATUS_ADDRESS(m)                        (0x400a8440UL + ((m) * (0x10000UL)))
#define PDSS_INTR7_STATUS(m)                                (*(volatile uint32_t *)(0x400a8440UL + ((m) * 0x10000UL)))
#define PDSS_INTR7_STATUS_DEFAULT                           (0x00000000UL)

/*
 * The status of LS filter edge detectors
 */
#define PDSS_INTR7_STATUS_STATUS_8                          (1UL << 0) /* <0:0> RW:R:0: */


/*
 * 1-8 LS Filtered output
 */
#define PDSS_INTR7_STATUS_FILT_8                            (1UL << 8) /* <8:8> RW:R:0: */


/*
 * INTR7 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin from LS filters
 */
#define PDSS_INTR7_ADDRESS(m)                               (0x400a8444UL + ((m) * (0x10000UL)))
#define PDSS_INTR7(m)                                       (*(volatile uint32_t *)(0x400a8444UL + ((m) * 0x10000UL)))
#define PDSS_INTR7_DEFAULT                                  (0x00000000UL)

/*
 * Change in edge of HS filter edge detectors (wakeup interrupt from deepsleep)
 * Check the  INTR7_STATUS.STATUS_8 value
 */
#define PDSS_INTR7_CLK_LF_EDGE_CHANGED                      (1UL << 0) /* <0:0> RW1S:RW1C:0: */


/*
 * INTR7 Interrupt Set
 */
#define PDSS_INTR7_SET_ADDRESS(m)                           (0x400a8448UL + ((m) * (0x10000UL)))
#define PDSS_INTR7_SET(m)                                   (*(volatile uint32_t *)(0x400a8448UL + ((m) * 0x10000UL)))
#define PDSS_INTR7_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR7_SET_CLK_LF_EDGE_CHANGED                  (1UL << 0) /* <0:0> A:RW1S:0: */


/*
 * INTR7 interrupt Mask
 */
#define PDSS_INTR7_MASK_ADDRESS(m)                          (0x400a844cUL + ((m) * (0x10000UL)))
#define PDSS_INTR7_MASK(m)                                  (*(volatile uint32_t *)(0x400a844cUL + ((m) * 0x10000UL)))
#define PDSS_INTR7_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR7_MASK_CLK_LF_EDGE_CHANGED_MASK            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * INTR7 interrupt Masked
 */
#define PDSS_INTR7_MASKED_ADDRESS(m)                        (0x400a8450UL + ((m) * (0x10000UL)))
#define PDSS_INTR7_MASKED(m)                                (*(volatile uint32_t *)(0x400a8450UL + ((m) * 0x10000UL)))
#define PDSS_INTR7_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR7_MASKED_CLK_LF_EDGE_CHANGED_MASKED        (1UL << 0) /* <0:0> RW:R:0: */


/*
 * CLK_FILTER2 (Divided version of CLK_HF) Filter configuration
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 */
#define PDSS_INTR11_FILTER_CFG_ADDRESS(m)                   (0x400a84c0UL + ((m) * (0x10000UL)))
#define PDSS_INTR11_FILTER_CFG(m)                           (*(volatile uint32_t *)(0x400a84c0UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR11_STATUS_0_ADDRESS(m)                     (0x400a84c4UL + ((m) * (0x10000UL)))
#define PDSS_INTR11_STATUS_0(m)                             (*(volatile uint32_t *)(0x400a84c4UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR11_ADDRESS(m)                              (0x400a84c8UL + ((m) * (0x10000UL)))
#define PDSS_INTR11(m)                                      (*(volatile uint32_t *)(0x400a84c8UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR11_SET_ADDRESS(m)                          (0x400a84ccUL + ((m) * (0x10000UL)))
#define PDSS_INTR11_SET(m)                                  (*(volatile uint32_t *)(0x400a84ccUL + ((m) * 0x10000UL)))
#define PDSS_INTR11_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR11_SET_FILT2_EDGE_CHANGED_MASK             (0x00000003UL) /* <0:1> A:RW1S:0: */
#define PDSS_INTR11_SET_FILT2_EDGE_CHANGED_POS              (0UL)


/*
 * INTR11 interrupt Mask
 */
#define PDSS_INTR11_MASK_ADDRESS(m)                         (0x400a84d0UL + ((m) * (0x10000UL)))
#define PDSS_INTR11_MASK(m)                                 (*(volatile uint32_t *)(0x400a84d0UL + ((m) * 0x10000UL)))
#define PDSS_INTR11_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR11_MASK_FILT2_EDGE_CHANGED_MASK_MASK       (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_INTR11_MASK_FILT2_EDGE_CHANGED_MASK_POS        (0UL)


/*
 * INTR11 interrupt Masked
 */
#define PDSS_INTR11_MASKED_ADDRESS(m)                       (0x400a84d4UL + ((m) * (0x10000UL)))
#define PDSS_INTR11_MASKED(m)                               (*(volatile uint32_t *)(0x400a84d4UL + ((m) * 0x10000UL)))
#define PDSS_INTR11_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR11_MASKED_FILT2_EDGE_CHANGED_MASKED_MASK    (0x00000003UL) /* <0:1> RW:R:0: */
#define PDSS_INTR11_MASKED_FILT2_EDGE_CHANGED_MASKED_POS    (0UL)


/*
 * INTR13 Status
 */
#define PDSS_INTR13_STATUS_ADDRESS(m)                       (0x400a84dcUL + ((m) * (0x10000UL)))
#define PDSS_INTR13_STATUS(m)                               (*(volatile uint32_t *)(0x400a84dcUL + ((m) * 0x10000UL)))
#define PDSS_INTR13_STATUS_DEFAULT                          (0x00000000UL)

/*
 * The status of out_d_ocp from the s8usbpdv2_csa_scp_top
 */
#define PDSS_INTR13_STATUS_CSA_OCP_STATUS                   (1UL << 8) /* <8:8> RW:R:0: */


/*
 * out_d_ocp Filtered output
 */
#define PDSS_INTR13_STATUS_CSA_OCP_FILT                     (1UL << 9) /* <9:9> RW:R:0: */


/*
 * The status of s8usbpdv2_csa_scp_top.out_d_scp
 */
#define PDSS_INTR13_STATUS_CSA_SCP_STATUS                   (1UL << 10) /* <10:10> RW:R:0: */


/*
 * s8usbpdv2_csa_scp_top.out_d_scp Filtered output
 */
#define PDSS_INTR13_STATUS_CSA_SCP_FILT                     (1UL << 11) /* <11:11> RW:R:0: */


/*
 * The status of rcp_comp_out_lv from the s8usbpdv2_csa_rcp_top
 */
#define PDSS_INTR13_STATUS_CSA_COMP_OUT_STATUS              (1UL << 14) /* <14:14> RW:R:0: */


/*
 * rcp_comp_out_lv Filtered output
 */
#define PDSS_INTR13_STATUS_CSA_COMP_OUT_FILT                (1UL << 15) /* <15:15> RW:R:0: */


/*
 * INTR13 interrupt Cause.
 */
#define PDSS_INTR13_ADDRESS(m)                              (0x400a84e0UL + ((m) * (0x10000UL)))
#define PDSS_INTR13(m)                                      (*(volatile uint32_t *)(0x400a84e0UL + ((m) * 0x10000UL)))
#define PDSS_INTR13_DEFAULT                                 (0x00000000UL)

/*
 * out_d_ocp changed (wakeup interrupt from deepsleep)
 * Check the  INTR13_STATUS.CSA_OCP_STATUS value
 */
#define PDSS_INTR13_CSA_OCP_CHANGED                         (1UL << 4) /* <4:4> RW1S:RW1C:0: */


/*
 * s8usbpdv2_csa_scp_top.out_d_scp changed (wakeup interrupt from deepsleep)
 * Check the INTR13_STATUS.CSA_SCP_STATUS value
 */
#define PDSS_INTR13_CSA_SCP_CHANGED                         (1UL << 5) /* <5:5> RW1S:RW1C:0: */


/*
 * rcp_comp_out_lv changed (wakeup interrupt from deepsleep)
 * Check the  INTR13_STATUS.CSA_OUT_STATUS value
 */
#define PDSS_INTR13_CSA_COMP_OUT_CHANGED                    (1UL << 7) /* <7:7> RW1S:RW1C:0: */


/*
 * INTR13 Interrupt Set
 */
#define PDSS_INTR13_SET_ADDRESS(m)                          (0x400a84e4UL + ((m) * (0x10000UL)))
#define PDSS_INTR13_SET(m)                                  (*(volatile uint32_t *)(0x400a84e4UL + ((m) * 0x10000UL)))
#define PDSS_INTR13_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_CSA_OCP_CHANGED                     (1UL << 4) /* <4:4> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_CSA_SCP_CHANGED                     (1UL << 5) /* <5:5> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_CSA_COMP_OUT_CHANGED                (1UL << 7) /* <7:7> A:RW1S:0: */


/*
 * INTR13 interrupt Mask
 */
#define PDSS_INTR13_MASK_ADDRESS(m)                         (0x400a84e8UL + ((m) * (0x10000UL)))
#define PDSS_INTR13_MASK(m)                                 (*(volatile uint32_t *)(0x400a84e8UL + ((m) * 0x10000UL)))
#define PDSS_INTR13_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_CSA_OCP_CHANGED_MASK               (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_CSA_SCP_CHANGED_MASK               (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_CSA_COMP_OUT_CHANGED_MASK          (1UL << 7) /* <7:7> R:RW:0: */


/*
 * INTR13 interrupt Masked
 */
#define PDSS_INTR13_MASKED_ADDRESS(m)                       (0x400a84ecUL + ((m) * (0x10000UL)))
#define PDSS_INTR13_MASKED(m)                               (*(volatile uint32_t *)(0x400a84ecUL + ((m) * 0x10000UL)))
#define PDSS_INTR13_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_CSA_OCP_CHANGED_MASKED           (1UL << 4) /* <4:4> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_CSA_SCP_CHANGED_MASKED           (1UL << 5) /* <5:5> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_CSA_COMP_OUT_CHANGED_MASKED      (1UL << 7) /* <7:7> RW:R:0: */


/*
 * CSA SCP HardIP High/Low Speed Filter and Edge detector configuration for
 * OCP and SCP detection
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_ADDRESS(m)               (0x400a84f0UL + ((m) * (0x10000UL)))
#define PDSS_INTR13_CFG_CSA_SCP_HS(m)                       (*(volatile uint32_t *)(0x400a84f0UL + ((m) * 0x10000UL)))
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
 * CSA RCP HardIP High/Low Speed Filter and Edge detector configuration for
 * CSA_OUT and COMP_OUT detection
 */
#define PDSS_INTR13_CFG_CSA_RCP_HS_ADDRESS(m)               (0x400a84f4UL + ((m) * (0x10000UL)))
#define PDSS_INTR13_CFG_CSA_RCP_HS(m)                       (*(volatile uint32_t *)(0x400a84f4UL + ((m) * 0x10000UL)))
#define PDSS_INTR13_CFG_CSA_RCP_HS_DEFAULT                  (0x00200000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_EN     (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_CFG_MASK    (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_CFG_POS    (12UL)


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
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_RESET    (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_BYPASS    (1UL << 15) /* <15:15> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_SEL_MASK    (0x001f0000UL) /* <16:20> R:RW:0: */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_SEL_POS    (16UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_DPSLP_MODE    (1UL << 21) /* <21:21> R:RW:1: */


/*
 * Interrupt DDFT Selections
 */
#define PDSS_HIP_INTR_DDFT_MUX_ADDRESS(m)                   (0x400a8584UL + ((m) * (0x10000UL)))
#define PDSS_HIP_INTR_DDFT_MUX(m)                           (*(volatile uint32_t *)(0x400a8584UL + ((m) * 0x10000UL)))
#define PDSS_HIP_INTR_DDFT_MUX_DEFAULT                      (0x00000000UL)

/*
 * 31:27 : 1'b0
 * 26:            HIP_CFG_TOP/u_ext_trig_det/u_ext_trig_det
 * 25  :    HIP_REG/intr1_v5v_changed
 * 24  :    HIP_REG/intr1_cc1_ocp_changed
 * 23  :    HIP_REG/intr1_cc2_ocp_changed
 * 22  :    HIP_REG/intr1_cc1_ovp_changed
 * 21  :    HIP_REG/intr1_cc2_ovp_changed
 * 20  :    HIP_REG/intr1_cc1_changed
 * 19  :    HIP_REG/intr1_cc2_changed
 * 18  :    HIP_REG/intr1_vcmp_up_changed
 * 17  :    HIP_REG/intr1_vcmp_dn_changed
 * 16  :    HIP_REG/intr1_vcmp_la_changed
 * 15  :    HIP_REG/intr3_cmp_out_changed
 * 14  :    HIP_REG/intr1_hpdin_changed
 * 13  :    HIP_REG/intr13_csa_comp_out_changed
 * 12  :    HIP_REG/intr13_csa_ocp_changed
 * 11  :    HIP_REG/intr13_csa_scp_changed
 * 10  :    HIP_REG/intr3_sbu1_sbu2_ovp_changed[0]
 * 9   :   HIP_REG/intr3_sbu1_sbu2_ovp_changed[1]
 * 8   :   HIP_REG/intr3_vreg20_vbus_changed
 * 7   :   HIP_REG/intr3_vsys_changed
 * 6   :   HIP_REG/intr5_edge_changed[0]
 * 5   :   HIP_REG/intr5_edge_changed[1]
 * 4   :   HIP_REG/intr5_edge_changed[2]
 * 3   :   HIP_REG/intr5_edge_changed[3]
 * 2   :   HIP_REG/intr7_clk_lf_edge_changed[0]
 * 1   :   HIP_REG/intr11_filt2_edge_changed[0]
 * 0   :   HIP_REG/intr11_filt2_edge_changed[1]
 */
#define PDSS_HIP_INTR_DDFT_MUX_HIP_INTR_DDFT0_SEL_MASK      (0x0000001fUL) /* <0:4> R:RW:0: */
#define PDSS_HIP_INTR_DDFT_MUX_HIP_INTR_DDFT0_SEL_POS       (0UL)


/*
 * 31:27 : 1'b0
 * 26:            HIP_CFG_TOP/u_ext_trig_det/u_ext_trig_det
 * 25  :    HIP_REG/intr1_v5v_changed
 * 24  :    HIP_REG/intr1_cc1_ocp_changed
 * 23  :    HIP_REG/intr1_cc2_ocp_changed
 * 22  :    HIP_REG/intr1_cc1_ovp_changed
 * 21  :    HIP_REG/intr1_cc2_ovp_changed
 * 20  :    HIP_REG/intr1_cc1_changed
 * 19  :    HIP_REG/intr1_cc2_changed
 * 18  :    HIP_REG/intr1_vcmp_up_changed
 * 17  :    HIP_REG/intr1_vcmp_dn_changed
 * 16  :    HIP_REG/intr1_vcmp_la_changed
 * 15  :    HIP_REG/intr3_cmp_out_changed
 * 14  :    HIP_REG/intr1_hpdin_changed
 * 13  :    HIP_REG/intr13_csa_comp_out_changed
 * 12  :    HIP_REG/intr13_csa_ocp_changed
 * 11  :    HIP_REG/intr13_csa_scp_changed
 * 10  :    HIP_REG/intr3_sbu1_sbu2_ovp_changed[0]
 * 9   :   HIP_REG/intr3_sbu1_sbu2_ovp_changed[1]
 * 8   :   HIP_REG/intr3_vreg20_vbus_changed
 * 7   :   HIP_REG/intr3_vsys_changed
 * 6   :   HIP_REG/intr5_edge_changed[0]
 * 5   :   HIP_REG/intr5_edge_changed[1]
 * 4   :   HIP_REG/intr5_edge_changed[2]
 * 3   :   HIP_REG/intr5_edge_changed[3]
 * 2   :   HIP_REG/intr7_clk_lf_edge_changed[0]
 * 1   :   HIP_REG/intr11_filt2_edge_changed[0]
 * 0   :   HIP_REG/intr11_filt2_edge_changed[1]
 */
#define PDSS_HIP_INTR_DDFT_MUX_HIP_INTR_DDFT1_SEL_MASK      (0x00001f00UL) /* <8:12> R:RW:0: */
#define PDSS_HIP_INTR_DDFT_MUX_HIP_INTR_DDFT1_SEL_POS       (8UL)


/*
 * NCELL DDFT Selections
 */
#define PDSS_NCELL_DDFT_MUX_ADDRESS(m)                      (0x400a8588UL + ((m) * (0x10000UL)))
#define PDSS_NCELL_DDFT_MUX(m)                              (*(volatile uint32_t *)(0x400a8588UL + ((m) * 0x10000UL)))
#define PDSS_NCELL_DDFT_MUX_DEFAULT                         (0x00000000UL)

/*
 * 63:60 :          1'b0
 * 59  :    HIP_TOP/inst_u_s8pd_sbu_ls_top/sbu2_rx_out
 * 58  :    HIP_TOP/inst_u_s8pd_sbu_ls_top/sbu1_rx_out
 * 57  :    HIP_TOP/inst_u_s8pd_sbu_ls_top/lstx_rx_out
 * 56  :    HIP_FILT/u_v5v_change/intr_fx_scan
 * 55  :    HIP_FILT/u_cc1_ocp_change/intr_fx_scan
 * 54  :    HIP_FILT/u_cc2_ocp_change/intr_fx_scan
 * 53  :    HIP_FILT/u_cc1_ovp_change/intr_fx_scan
 * 52  :    HIP_FILT/u_cc2_ovp_change/intr_fx_scan
 * 51  :    HIP_FILT/u_cc1_change/intr_fx_scan
 * 50  :    HIP_FILT/u_cc2_change/intr_fx_scan
 * 49  :    HIP_FILT/u_vcmp_up_change/intr_fx_scan
 * 48  :    HIP_FILT/u_vcmp_dn_change/intr_fx_scan
 * 47  :    HIP_FILT/u_vcmp_la_change/intr_fx_scan
 * 46  :    HIP_FILT/u_cmp_out_change/intr_fx_scan
 * 45  :    HIP_FILT/u_hpd_change/intr_fx_scan
 * 44  :    HIP_FILT/u_csa_comp_out_change/intr_fx_scan
 * 43  :    HIP_FILT/u_csa_ocp_change/intr_fx_scan
 * 42  :    HIP_FILT/u_csa_scp_change/intr_fx_scan
 * 41  :    HIP_FILT/u_sbu1_ovp_change/intr_fx_scan
 * 40  :    HIP_FILT/u_sbu2_ovp_change/intr_fx_scan
 * 39  :    HIP_FILT/u_vreg_vbus_change/intr_fx_scan
 * 38  :    HIP_FILT/y_vsys_chg/u_vsys_change/intr_fx_scan
 * 37  :    HIP_FILT/u_hs_change_uv/intr_fx_scan
 * 36  :    HIP_FILT/u_hs_change_ov/intr_fx_scan
 * 35  :    HIP_FILT/u_hs_change_ilim/intr_fx_scan
 * 34  :    HIP_FILT/y_inrush_det/u_hs_change_inrush_det/intr_fx_scan
 * 33  :    HIP_FILT/y_vsys_det/u_ls_change/intr_fx_scan
 * 32  :    HIP_FILT/u_hs_filt21_change/intr_fx_scan
 * 31  :    HIP_FILT/u_hs_filt22_change/intr_fx_scan
 * 30  :    HIP_TOP/inst_u_s8pd_reg_top/vcr_enable
 * 29  :    HIP_TOP/inst_u_s8pd_ngdo_p5c40_top/clk_out
 * 28  :    HIP_TOP/inst_u_s8pd_30vconn_top/clk_out
 * 27  :    HIP_TOP/inst_u_s8pd_reg_top/cp_compout_ddft
 * 26  :    HIP_TOP/inst_u_s8pd_reg_top/cp_clkout_ddft
 * 25  :    HIP_TOP/inst_u_s8usbpd_5vpump_top_0/clkout
 * 24  :    HIP_TOP/inst_u_s8usbpd_5vpump_top_1/clkout
 * 23  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_auxp_auxn_ctrl/ddft_faults_masked
 * 22  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_auxp_auxn_ctrl/ddft_async_fault_det
 * 21  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_dbg12_ctrl/ddft_faults_masked
 * 20  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_dbg12_ctrl/ddft_async_fault_det
 * 19  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_lstx_lsrx_ctrl/ddft_faults_masked
 * 18  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_lstx_lsrx_ctrl/ddft_async_fault_det
 * 17  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_cc1_ctrl/ddft_faults_masked
 * 16  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_cc1_ctrl/ddft_async_fault_det
 * 15  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_cc2_ctrl/ddft_faults_masked
 * 14  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_cc2_ctrl/ddft_async_fault_det
 * 13  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_pump_ctrl/ddft_faults_masked
 * 12  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_pump_ctrl/ddft_async_fault_det
 * 11  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_gdrv_ctrl/ddft_faults_masked
 * 10  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_gdrv_ctrl/ddft_async_fault_det
 * 9   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_ngdo_gdrv_ctrl/ddft_faults_masked
 * 8   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_ngdo_gdrv_ctrl/ddft_async_fault_det
 * 7   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_cp_gdrv_ctrl/ddft_faults_masked
 * 6   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_cp_gdrv_ctrl/ddft_async_fault_det
 * 5   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_keepoff_disable_gdrv_ctrl/ddft_faults_masked
 * 4   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_keepoff_disable_gdrv_ctrl/ddft_async_fault_det
 * 3   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_frs_cp_en_gdrv_ctrl/ddft_faults_masked
 * 2   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_frs_cp_en_gdrv_ctrl/ddft_async_fault_det
 * 1   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_frs_sw_en_gdrv_ctrl/ddft_faults_masked
 * 0   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_frs_sw_en_gdrv_ctrl/ddft_async_fault_det
 */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT0_SEL_MASK            (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT0_SEL_POS             (0UL)


/*
 * 63:60 :          1'b0
 * 59  :    HIP_TOP/inst_u_s8pd_sbu_ls_top/sbu2_rx_out
 * 58  :    HIP_TOP/inst_u_s8pd_sbu_ls_top/sbu1_rx_out
 * 57  :    HIP_TOP/inst_u_s8pd_sbu_ls_top/lstx_rx_out
 * 56  :    HIP_FILT/u_v5v_change/intr_fx_scan
 * 55  :    HIP_FILT/u_cc1_ocp_change/intr_fx_scan
 * 54  :    HIP_FILT/u_cc2_ocp_change/intr_fx_scan
 * 53  :    HIP_FILT/u_cc1_ovp_change/intr_fx_scan
 * 52  :    HIP_FILT/u_cc2_ovp_change/intr_fx_scan
 * 51  :    HIP_FILT/u_cc1_change/intr_fx_scan
 * 50  :    HIP_FILT/u_cc2_change/intr_fx_scan
 * 49  :    HIP_FILT/u_vcmp_up_change/intr_fx_scan
 * 48  :    HIP_FILT/u_vcmp_dn_change/intr_fx_scan
 * 47  :    HIP_FILT/u_vcmp_la_change/intr_fx_scan
 * 46  :    HIP_FILT/u_cmp_out_change/intr_fx_scan
 * 45  :    HIP_FILT/u_hpd_change/intr_fx_scan
 * 44  :    HIP_FILT/u_csa_comp_out_change/intr_fx_scan
 * 43  :    HIP_FILT/u_csa_ocp_change/intr_fx_scan
 * 42  :    HIP_FILT/u_csa_scp_change/intr_fx_scan
 * 41  :    HIP_FILT/u_sbu1_ovp_change/intr_fx_scan
 * 40  :    HIP_FILT/u_sbu2_ovp_change/intr_fx_scan
 * 39  :    HIP_FILT/u_vreg_vbus_change/intr_fx_scan
 * 38  :    HIP_FILT/y_vsys_chg/u_vsys_change/intr_fx_scan
 * 37  :    HIP_FILT/u_hs_change_uv/intr_fx_scan
 * 36  :    HIP_FILT/u_hs_change_ov/intr_fx_scan
 * 35  :    HIP_FILT/u_hs_change_ilim/intr_fx_scan
 * 34  :    HIP_FILT/y_inrush_det/u_hs_change_inrush_det/intr_fx_scan
 * 33  :    HIP_FILT/y_vsys_det/u_ls_change/intr_fx_scan
 * 32  :    HIP_FILT/u_hs_filt21_change/intr_fx_scan
 * 31  :    HIP_FILT/u_hs_filt22_change/intr_fx_scan
 * 30  :    HIP_TOP/inst_u_s8pd_reg_top/vcr_enable
 * 29  :    HIP_TOP/inst_u_s8pd_ngdo_p5c40_top/clk_out
 * 28  :    HIP_TOP/inst_u_s8pd_30vconn_top/clk_out
 * 27  :    HIP_TOP/inst_u_s8pd_reg_top/cp_compout_ddft
 * 26  :    HIP_TOP/inst_u_s8pd_reg_top/cp_clkout_ddft
 * 25  :    HIP_TOP/inst_u_s8usbpd_5vpump_top_0/clkout
 * 24  :    HIP_TOP/inst_u_s8usbpd_5vpump_top_1/clkout
 * 23  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_auxp_auxn_ctrl/ddft_faults_masked
 * 22  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_auxp_auxn_ctrl/ddft_async_fault_det
 * 21  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_dbg12_ctrl/ddft_faults_masked
 * 20  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_dbg12_ctrl/ddft_async_fault_det
 * 19  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_lstx_lsrx_ctrl/ddft_faults_masked
 * 18  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_sbu12_lstx_lsrx_ctrl/ddft_async_fault_det
 * 17  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_cc1_ctrl/ddft_faults_masked
 * 16  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_cc1_ctrl/ddft_async_fault_det
 * 15  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_cc2_ctrl/ddft_faults_masked
 * 14  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_cc2_ctrl/ddft_async_fault_det
 * 13  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_pump_ctrl/ddft_faults_masked
 * 12  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_vconn30_en_pump_ctrl/ddft_async_fault_det
 * 11  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_gdrv_ctrl/ddft_faults_masked
 * 10  :    HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_gdrv_ctrl/ddft_async_fault_det
 * 9   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_ngdo_gdrv_ctrl/ddft_faults_masked
 * 8   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_ngdo_gdrv_ctrl/ddft_async_fault_det
 * 7   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_cp_gdrv_ctrl/ddft_faults_masked
 * 6   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_en_cp_gdrv_ctrl/ddft_async_fault_det
 * 5   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_keepoff_disable_gdrv_ctrl/ddft_faults_masked
 * 4   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_ngdo_p5c40_keepoff_disable_gdrv_ctrl/ddft_async_fault_det
 * 3   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_frs_cp_en_gdrv_ctrl/ddft_faults_masked
 * 2   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_frs_cp_en_gdrv_ctrl/ddft_async_fault_det
 * 1   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_frs_sw_en_gdrv_ctrl/ddft_faults_masked
 * 0   :   HIP_CFG_TOP/u_mxusbpd_gate_driver_frs_sw_en_gdrv_ctrl/ddft_async_fault_det
 */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT1_SEL_MASK            (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT1_SEL_POS             (8UL)


/*
 * IP GPIO DDFT Selections
 */
#define PDSS_GPIO_DDFT_MUX_ADDRESS(m)                       (0x400a858cUL + ((m) * (0x10000UL)))
#define PDSS_GPIO_DDFT_MUX(m)                               (*(volatile uint32_t *)(0x400a858cUL + ((m) * 0x10000UL)))
#define PDSS_GPIO_DDFT_MUX_DEFAULT                          (0x00000000UL)

/*
 * 31:28 : 1'b0
 * 27 :HIP_FILT/u_v5v_change/filt_out_gpio
 * 26 :HIP_FILT/u_cc1_ocp_change/filt_out_gpio
 * 25 :HIP_FILT/u_cc2_ocp_change/filt_out_gpio
 * 24 :HIP_FILT/u_cc1_ovp_change/filt_out_gpio
 * 23 :HIP_FILT/u_cc2_ovp_change/filt_out_gpio
 * 22 :HIP_FILT/u_cc1_change/filt_out_gpio
 * 21 :HIP_FILT/u_cc2_change/filt_out_gpio
 * 20 :HIP_FILT/u_vcmp_up_change/filt_out_gpio
 * 19 :HIP_FILT/u_vcmp_dn_change/filt_out_gpio
 * 18 :HIP_FILT/u_vcmp_la_change/filt_out_gpio
 * 17 :HIP_FILT/u_cmp_out_change/filt_out_gpio
 * 16 :HIP_FILT/u_hpd_change/filt_out_gpio
 * 15 :HIP_FILT/u_csa_comp_out_change/filt_out_gpio
 * 14 :HIP_FILT/u_csa_ocp_change/filt_out_gpio
 * 13 :HIP_FILT/u_csa_scp_change/filt_out_gpio
 * 12 :HIP_FILT/u_sbu1_ovp_change/filt_out_gpio
 * 11 :HIP_FILT/u_sbu2_ovp_change/filt_out_gpio
 * 10 :HIP_FILT/u_vreg_vbus_change/filt_out_gpio
 * 9  :HIP_FILT/y_vsys_chg/u_vsy_change/filt_out_gpio
 * 8  :HIP_FILT/u_hs_change_uv/filt_out_gpio
 * 7  :HIP_FILT/u_hs_change_ov/filt_out_gpio
 * 6  :HIP_FILT/u_hs_change_ilim/filt_out_gpio
 * 5  :HIP_FILT/y_inrush_det/u_hs_change_inrush_det/filt_out_gpio
 * 4  :HIP_FILT/y_vsys_det/u_ls_change/filt_out_gpio
 * 3  :HIP_FILT/u_hs_filt21_change/filt_out_gpio
 * 2  :HIP_FILT/u_hs_filt22_change/filt_out_gpio
 * 1  :DIG_MMIO/u_mxusbpd_gpio_intr_ddft0_mux/ddft_out
 */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT0_SEL_MASK              (0x0000007fUL) /* <0:6> R:RW:0: */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT0_SEL_POS               (0UL)


/*
 * 0: The selected output is not inverted
 * 1: The selected out is inverted
 */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT0_POLARITY              (1UL << 7) /* <7:7> R:RW:0: */


/*
 * 31:28 : 1'b0
 * 27 :HIP_FILT/u_v5v_change/filt_out_gpio
 * 26 :HIP_FILT/u_cc1_ocp_change/filt_out_gpio
 * 25 :HIP_FILT/u_cc2_ocp_change/filt_out_gpio
 * 24 :HIP_FILT/u_cc1_ovp_change/filt_out_gpio
 * 23 :HIP_FILT/u_cc2_ovp_change/filt_out_gpio
 * 22 :HIP_FILT/u_cc1_change/filt_out_gpio
 * 21 :HIP_FILT/u_cc2_change/filt_out_gpio
 * 20 :HIP_FILT/u_vcmp_up_change/filt_out_gpio
 * 19 :HIP_FILT/u_vcmp_dn_change/filt_out_gpio
 * 18 :HIP_FILT/u_vcmp_la_change/filt_out_gpio
 * 17 :HIP_FILT/u_cmp_out_change/filt_out_gpio
 * 16 :HIP_FILT/u_hpd_change/filt_out_gpio
 * 15 :HIP_FILT/u_csa_comp_out_change/filt_out_gpio
 * 14 :HIP_FILT/u_csa_ocp_change/filt_out_gpio
 * 13 :HIP_FILT/u_csa_scp_change/filt_out_gpio
 * 12 :HIP_FILT/u_sbu1_ovp_change/filt_out_gpio
 * 11 :HIP_FILT/u_sbu2_ovp_change/filt_out_gpio
 * 10 :HIP_FILT/u_vreg_vbus_change/filt_out_gpio
 * 9  :HIP_FILT/y_vsys_chg/u_vsys_change/filt_out_gpio
 * 8  :HIP_FILT/u_hs_change_uv/filt_out_gpio
 * 7  :HIP_FILT/u_hs_change_ov/filt_out_gpio
 * 6  :HIP_FILT/u_hs_change_ilim/filt_out_gpio
 * 5  :HIP_FILT/y_inrush_det/u_hs_change_inrush_det/filt_out_gpio
 * 4  :HIP_FILT/y_vsys_det/u_ls_change/filt_out_gpio
 * 3  :HIP_FILT/u_hs_filt21_change/filt_out_gpio
 * 2  :HIP_FILT/u_hs_filt22_change/filt_out_gpio
 * 1  :DIG_MMIO/u_mxusbpd_gpio_intr_ddft0_mux/ddft_out
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
#define PDSS_GPIO_INTR_DDFT_MUX_ADDRESS(m)                  (0x400a8590UL + ((m) * (0x10000UL)))
#define PDSS_GPIO_INTR_DDFT_MUX(m)                          (*(volatile uint32_t *)(0x400a8590UL + ((m) * 0x10000UL)))
#define PDSS_GPIO_INTR_DDFT_MUX_DEFAULT                     (0x00000000UL)

/*
 * 255:47 : 1'b0
 * 46  :    AGNOSTIC_REGS/intr2_vswap_vbus_less_5_done
 * 45  :    AGNOSTIC_REGS/intr2_hpd_irq
 * 44  :    AGNOSTIC_REGS/intr2_hpd_pluged
 * 43  :    AGNOSTIC_REGS/intr2_hpd_unpluged
 * 42  :    AGNOSTIC_REGS/intr2_hpd_unstable
 * 41  :    AGNOSTIC_REGS/intr2_hpdt_command_done
 * 40  :    AGNOSTIC_REGS/intr2_hpd_queue
 * 39  :    AGNOSTIC_REGS/intr2_lf_cntr_match
 * 38  :    AGNOSTIC_REGS/intr2_vreg20v_switch_done
 * 37  :    AGNOSTIC_REGS/intr2_vddd_sw_switch_done
 * 36  :    AGNOSTIC_REGS/intr2_swap_disconnect
 * 35  :    AGNOSTIC_REGS/intr2_swap_command_done
 * 34  :    AGNOSTIC_REGS/intr2_swap_pulse
 * 33  :    AGNOSTIC_REGS/intr2_swap_rcvd
 * 32  :    HIP_REG/intr1_drp_attached_detected
 * 31  :    AGNOSTIC_REGS/intr2_chunk_det
 * 30  :    AGNOSTIC_REGS/intr2_tx_sram_under_flow
 * 29  :    AGNOSTIC_REGS/intr2_rx_sram_over_flow
 * 28  :    AGNOSTIC_REGS/intr2_extended_msg_det
 * 27  :    AGNOSTIC_REGS/intr2_ui_cal_done
 * 26  :    AGNOSTIC_REGS/intr0_rx_state_idle
 * 25  :    AGNOSTIC_REGS/intr0_tx_state_idle
 * 24  :    AGNOSTIC_REGS/intr0_tx_regulator_enabled
 * 23  :    AGNOSTIC_REGS/intr0_tx_cc_data_oen_deassert
 * 22  :    AGNOSTIC_REGS/intr0_tx_cc_data_oen_assert
 * 21  :    AGNOSTIC_REGS/intr0_kchar_error
 * 20  :    AGNOSTIC_REGS/intr0_tx_retry_enable_clrd
 * 19  :    AGNOSTIC_REGS/intr0_rx_sram_half_end
 * 18  :    AGNOSTIC_REGS/intr0_tx_sram_half_end
 * 17  :    AGNOSTIC_REGS/intr0_collision_type4
 * 16  :    AGNOSTIC_REGS/intr0_collision_type3
 * 15  :    AGNOSTIC_REGS/intr0_collision_type2
 * 14  :    AGNOSTIC_REGS/intr0_collision_type1
 * 13  :    AGNOSTIC_REGS/intr0_crc_rx_timer_exp
 * 12  :    AGNOSTIC_REGS/intr0_cc_no_valid_data_detected
 * 11  :    AGNOSTIC_REGS/intr0_cc_valid_data_detected
 * 10  :    AGNOSTIC_REGS/intr0_tx_goodcrc_msg_done
 * 9   :   AGNOSTIC_REGS/intr0_rcv_rst
 * 8   :   AGNOSTIC_REGS/intr0_tx_hard_rst_done
 * 7   :   AGNOSTIC_REGS/intr0_tx_packet_done
 * 6   :   AGNOSTIC_REGS/intr0_rx_over_run
 * 5   :   AGNOSTIC_REGS/intr0_eop_error
 * 4   :   AGNOSTIC_REGS/intr0_rcv_expt_goodcrc_msg_complete
 * 3   :   AGNOSTIC_REGS/intr0_rcv_goodcrc_msg_complete
 * 2   :   AGNOSTIC_REGS/intr0_rx_sop
 * 1   :   AGNOSTIC_REGS/intr0_rcv_bad_packet_complete
 * 0   :   AGNOSTIC_REGS/intr0_rcv_good_packet_complete
 */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT0_SEL_MASK    (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT0_SEL_POS     (0UL)


/*
 * 255:47 : 1'b0
 * 46  :    AGNOSTIC_REGS/intr2_vswap_vbus_less_5_done
 * 45  :    AGNOSTIC_REGS/intr2_hpd_irq
 * 44  :    AGNOSTIC_REGS/intr2_hpd_pluged
 * 43  :    AGNOSTIC_REGS/intr2_hpd_unpluged
 * 42  :    AGNOSTIC_REGS/intr2_hpd_unstable
 * 41  :    AGNOSTIC_REGS/intr2_hpdt_command_done
 * 40  :    AGNOSTIC_REGS/intr2_hpd_queue
 * 39  :    AGNOSTIC_REGS/intr2_lf_cntr_match
 * 38  :    AGNOSTIC_REGS/intr2_vreg20v_switch_done
 * 37  :    AGNOSTIC_REGS/intr2_vddd_sw_switch_done
 * 36  :    AGNOSTIC_REGS/intr2_swap_disconnect
 * 35  :    AGNOSTIC_REGS/intr2_swap_command_done
 * 34  :    AGNOSTIC_REGS/intr2_swap_pulse
 * 33  :    AGNOSTIC_REGS/intr2_swap_rcvd
 * 32  :    HIP_REG/intr1_drp_attached_detected
 * 31  :    AGNOSTIC_REGS/intr2_chunk_det
 * 30  :    AGNOSTIC_REGS/intr2_tx_sram_under_flow
 * 29  :    AGNOSTIC_REGS/intr2_rx_sram_over_flow
 * 28  :    AGNOSTIC_REGS/intr2_extended_msg_det
 * 27  :    AGNOSTIC_REGS/intr2_ui_cal_done
 * 26  :    AGNOSTIC_REGS/intr0_rx_state_idle
 * 25  :    AGNOSTIC_REGS/intr0_tx_state_idle
 * 24  :    AGNOSTIC_REGS/intr0_tx_regulator_enabled
 * 23  :    AGNOSTIC_REGS/intr0_tx_cc_data_oen_deassert
 * 22  :    AGNOSTIC_REGS/intr0_tx_cc_data_oen_assert
 * 21  :    AGNOSTIC_REGS/intr0_kchar_error
 * 20  :    AGNOSTIC_REGS/intr0_tx_retry_enable_clrd
 * 19  :    AGNOSTIC_REGS/intr0_rx_sram_half_end
 * 18  :    AGNOSTIC_REGS/intr0_tx_sram_half_end
 * 17  :    AGNOSTIC_REGS/intr0_collision_type4
 * 16  :    AGNOSTIC_REGS/intr0_collision_type3
 * 15  :    AGNOSTIC_REGS/intr0_collision_type2
 * 14  :    AGNOSTIC_REGS/intr0_collision_type1
 * 13  :    AGNOSTIC_REGS/intr0_crc_rx_timer_exp
 * 12  :    AGNOSTIC_REGS/intr0_cc_no_valid_data_detected
 * 11  :    AGNOSTIC_REGS/intr0_cc_valid_data_detected
 * 10  :    AGNOSTIC_REGS/intr0_tx_goodcrc_msg_done
 * 9   :   AGNOSTIC_REGS/intr0_rcv_rst
 * 8   :   AGNOSTIC_REGS/intr0_tx_hard_rst_done
 * 7   :   AGNOSTIC_REGS/intr0_tx_packet_done
 * 6   :   AGNOSTIC_REGS/intr0_rx_over_run
 * 5   :   AGNOSTIC_REGS/intr0_eop_error
 * 4   :   AGNOSTIC_REGS/intr0_rcv_expt_goodcrc_msg_complete
 * 3   :   AGNOSTIC_REGS/intr0_rcv_goodcrc_msg_complete
 * 2   :   AGNOSTIC_REGS/intr0_rx_sop
 * 1   :   AGNOSTIC_REGS/intr0_rcv_bad_packet_complete
 * 0   :   AGNOSTIC_REGS/intr0_rcv_good_packet_complete
 */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT1_SEL_MASK    (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT1_SEL_POS     (8UL)


/*
 * The CCG6 & CCG7D Fault GPIO control
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_ADDRESS(m)                (0x400a8598UL + ((m) * (0x10000UL)))
#define PDSS_FAULT_GPIO_CTRL_EXTR(m)                        (*(volatile uint32_t *)(0x400a8598UL + ((m) * 0x10000UL)))
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
 * 15:10 : 1'b0
 * 9 : HIP_FILT/u_csa_comp_out_change/filt_out_gpio
 * 8 : HIP_FILT/u_csa_scp_change/filt_out_gpio
 * 7 : HIP_FILT/u_cc2_ocp_change/filt_out_gpio
 * 6 : HIP_FILT/u_cc1_ocp_change/filt_out_gpio
 * 5 : HIP_FILT/u_cc2_ovp_change/filt_out_gpio
 * 4 : HIP_FILT/u_cc1_ovp_change/filt_out_gpio
 * 3 : HIP_FILT/u_csa_ocp_change/filt_out_gpio
 * 2 : HIP_FILT/u_hs_change_ov/filt_out_gpio
 * 1 : HIP_FILT/u_hs_change_uv/filt_out_gpio
 * 0 : HIP_CFG_TOP/y_fault_gpio_extr/u_mxusbpd_fault_gpio/fault_gpio_out
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_0_SEL_MASK    (0x0000003cUL) /* <2:5> R:RW:0: */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_0_SEL_POS    (2UL)


/*
 * 0: The selected output is not inverted
 * 1: The selected out is inverted
 */
#define PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_0_POLARITY    (1UL << 6) /* <6:6> R:RW:0: */


/*
 * 15:10 : 1'b0
 * 9 : HIP_FILT/u_csa_comp_out_change/filt_out_gpio
 * 8 : HIP_FILT/u_csa_scp_change/filt_out_gpio
 * 7 : HIP_FILT/u_cc2_ocp_change/filt_out_gpio
 * 6 : HIP_FILT/u_cc1_ocp_change/filt_out_gpio
 * 5 : HIP_FILT/u_cc2_ovp_change/filt_out_gpio
 * 4 : HIP_FILT/u_cc1_ovp_change/filt_out_gpio
 * 3 : HIP_FILT/u_csa_ocp_change/filt_out_gpio
 * 2 : HIP_FILT/u_hs_change_ov/filt_out_gpio
 * 1 : HIP_FILT/u_hs_change_uv/filt_out_gpio
 * 0 : HIP_CFG_TOP/y_fault_gpio_extr/u_mxusbpd_fault_gpio/fault_gpio_out
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
#define PDSS_CC_CTRL_0_ADDRESS(m)                           (0x400a8600UL + ((m) * (0x10000UL)))
#define PDSS_CC_CTRL_0(m)                                   (*(volatile uint32_t *)(0x400a8600UL + ((m) * 0x10000UL)))
#define PDSS_CC_CTRL_0_DEFAULT                              (0x80000000UL)

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
#define PDSS_CC_CTRL_1_ADDRESS(m)                           (0x400a8604UL + ((m) * (0x10000UL)))
#define PDSS_CC_CTRL_1(m)                                   (*(volatile uint32_t *)(0x400a8604UL + ((m) * 0x10000UL)))
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
 * 0: All outputs are isolated to a known value "0"
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
 * rx_alt_dis = 0 -> Newly added receiver is enabled.
 * rx_alt_dis = 1 -> Newly added receiver is disabled.
 */
#define PDSS_CC_CTRL_1_RX_ALT_DIS                           (1UL << 21) /* <21:21> R:RW:0: */


/*
 * Test Mode bits.
 */
#define PDSS_CC_CTRL_1_T_CC_40SHVT_MASK                     (0x1fc00000UL) /* <22:28> R:RW:0: */
#define PDSS_CC_CTRL_1_T_CC_40SHVT_POS                      (22UL)


/*
 * USBPD Hard IP VSYS1  Supply Switch Register
 */
#define PDSS_VSYS_CTRL_ADDRESS(m)                           (0x400a8618UL + ((m) * (0x10000UL)))
#define PDSS_VSYS_CTRL(m)                                   (*(volatile uint32_t *)(0x400a8618UL + ((m) * 0x10000UL)))
#define PDSS_VSYS_CTRL_DEFAULT                              (0x00000000UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value "0"
 */
#define PDSS_VSYS_CTRL_VSYS_ISO_N                           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Control signal to enable ADFT Switches, Active High
 */
#define PDSS_VSYS_CTRL_ADFT_EN                              (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Control signal to select DFT OUT
 * adft_sel<0> : 1 : Select VSYS/2 onto ADFT_OUT pin
 * adft_sel<1> : Reserved
 */
#define PDSS_VSYS_CTRL_ADFT_SEL_MASK                        (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_VSYS_CTRL_ADFT_SEL_POS                         (6UL)


/*
 * USBPD Hard IP Regulator #1-4 and VSYS Supply Switch 1 Register
 */
#define PDSS_VREG_VSYS_CTRL_ADDRESS(m)                      (0x400a861cUL + ((m) * (0x10000UL)))
#define PDSS_VREG_VSYS_CTRL(m)                              (*(volatile uint32_t *)(0x400a861cUL + ((m) * 0x10000UL)))
#define PDSS_VREG_VSYS_CTRL_DEFAULT                         (0x00010000UL)

/*
 * Timing requirement of ENABLE_VDDD_SWITCH and VREG20_1_EN :
 *   i. During dead-battery powerup (with VSYS=0 and VBUS available), based
 * on the comp_out_lv signal (post digital filter) of VSYS accurate
 *      comparator, ENABLE_VDDD_SWITCH should be disabled (0) and should
 * be enabled only when comp_out_lv signal (post digital filter) of VSYS
 *      accurate comparator gets asserted.  This would mean that VSYS got
 * charged fully and ready to supply to VDDD.
 *   ii. VREG20_1_EN should be disabled only after 50uS (programmable from
 * 10uS to 200us) of enabling ENABLE_VDDD_SWITCH.
 *
 * Enable signal for Port-0 regulator
 */
#define PDSS_VREG_VSYS_CTRL_VREG20_EN                       (1UL << 4) /* <4:4> R:RW:0: */


/*
 * When VREG20_EN is set/de-assert, the regulator will turn off/on after
 * VREG20_ONOFF_CNTR cycle of clk_tx.
 * There won't be any delay is this register is set to zero.
 */
#define PDSS_VREG_VSYS_CTRL_VREG20_ONOFF_CNTR_MASK          (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_VREG_VSYS_CTRL_VREG20_ONOFF_CNTR_POS           (8UL)


/*
 * Control signal to enable/disable switch
 * "1" : Enable switch : VOUT = VDDD = VSYS
 * "0" : Disable switch
 */
#define PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH              (1UL << 16) /* <16:16> R:RW:1:INSTANCE_NUM_ZERO */


/*
 * When ENABLE_VDDD_SWITCH is set/de-assert, the s8usbpd_vdd_sw_top will
 * turn off/on after VDDD_SW_ONOFF_CNTR cycle of clk_tx.
 * There won't be any delay is this register is set to zero.
 */
#define PDSS_VREG_VSYS_CTRL_VDDD_SW_ONOFF_CNTR_MASK         (0x01fe0000UL) /* <17:24> R:RW:0:INSTANCE_NUM_ZERO */
#define PDSS_VREG_VSYS_CTRL_VDDD_SW_ONOFF_CNTR_POS          (17UL)


/*
 * USBPD Hard IP AMUX_NHV #1-32 Register
 * Function                               SWITCH#                   SEL[0]
 *                               SEL[1]
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * CCG6DF_CFP-Port0:
 *          UV                                      #0                  
 *         8%(VBUSC)                      15%(VBUSC)
 *          OV                                      #1                  
 *         6%(VBUSC)                      8%(VBUSC)
 *          VBUS_C                              #2                      
 *     6%(VBUSC)                      8%(VBUSC)
 *          ADC_AMUXB_NHV5            #3                           AMUXBUSB
 *                      AMUX_NHV[5]
 *          VSYS_DET                         #4                         
 *  40%(VSYS)                      50%(VSYS)
 *          ADC_NHV2_NHV6               #5                          AMUX_
 * NHV[2]                   AMUX_NHV[6]
 *          ADC_VSENSE_TMPSNS     #6                          VSENSE    
 *                        TEMPERATURE SENSOR
 *          UV_COMP                           #7                        
 *  AMUX_ NHV[0]                   31%(VBUS_P)
 *          OV_COMP                           #8                        
 *  AMUX_ NHV[1]                    31%(VBUS_P)
 *
 * CCG6DF_CFP-Port1:
 *          UV                                      #0                  
 *         8%(VBUSC)                      15%(VBUSC)
 *          OV                                      #1                  
 *         6%(VBUSC)                      8%(VBUSC)
 *          VBUS_C                              #2                      
 *     6%(VBUSC)                      8%(VBUSC)
 *          ADC_AMUXB_NHV4            #3                           AMUXBUSB
 *                      AMUX_NHV[4]
 *          ADC_NHV2_NHV5               #4                          AMUX_
 * NHV[2]                   AMUX_NHV[5]
 *          ADC_VSENSE_TMPSNS     #5                          VSENSE    
 *                        TEMPERATURE SENSOR
 *          UV_COMP                           #6                        
 *  AMUX_ NHV[0]                   31%(VBUS_P)
 *          OV_COMP                           #7                        
 *  AMUX_ NHV[1]                    31%(VBUS_P)
 */
#define PDSS_AMUX_NHV_CTRL_ADDRESS(m)                       (0x400a862cUL + ((m) * (0x10000UL)))
#define PDSS_AMUX_NHV_CTRL(m)                               (*(volatile uint32_t *)(0x400a862cUL + ((m) * 0x10000UL)))
#define PDSS_AMUX_NHV_CTRL_DEFAULT                          (0x00000000UL)

/*
 * AMUX select control
 */
#define PDSS_AMUX_NHV_CTRL_SEL_MASK                         (0x000001ffUL) /* <0:8> R:RW:0:USB_AMUX_NHV_NUM */
#define PDSS_AMUX_NHV_CTRL_SEL_POS                          (0UL)


/*
 * USBPD Hard IP AMUX_DENFET #1-32 Register
 * Function                            SWITCH#          SEL[0]    SEL[1]
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * ACG1F:
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *           VBUS_MON                          #0                  100% 
 *     10%
 */
#define PDSS_AMUX_DENFET_CTRL_ADDRESS(m)                    (0x400a8630UL + ((m) * (0x10000UL)))
#define PDSS_AMUX_DENFET_CTRL(m)                            (*(volatile uint32_t *)(0x400a8630UL + ((m) * 0x10000UL)))
#define PDSS_AMUX_DENFET_CTRL_DEFAULT                       (0x00000000UL)

/*
 * AMUX select control
 */
#define PDSS_AMUX_DENFET_CTRL_SEL                           (1UL << 0) /* <0:0> R:RW:0:USB_AMUX_DENFET_NUM */


/*
 * USBPD Hard IP DAC #1-4 Register
 */
#define PDSS_ADC_CTRL_ADDRESS(m)                            (0x400a8680UL + ((m) * (0x10000UL)))
#define PDSS_ADC_CTRL(m)                                    (*(volatile uint32_t *)(0x400a8680UL + ((m) * 0x10000UL)))
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
 * 0: All outputs are isolated to a known value "0"
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
 * USBPD Hard IP VBUS Discharge SHV #1-8 Register0
 */
#define PDSS_DISCHG_SHV_CTRL_ADDRESS(m)                     (0x400a8790UL + ((m) * (0x10000UL)))
#define PDSS_DISCHG_SHV_CTRL(m)                             (*(volatile uint32_t *)(0x400a8790UL + ((m) * 0x10000UL)))
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
 */
#define PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK                 (0x0000007cUL) /* <2:6> R:RW:0: */
#define PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS                  (2UL)


/*
 * USBPD Hard IP Comparators #1-24 Register
 * Function                            Comparator#       CLK_FILTER#    
 *   CLK_LF#    FILTER21  FILTER22
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------/
 * CCG6DF_CFP-Port0:
 *           UV                                    #0                   
 *             #0                   NA           #0          #0
 *           OV                                    #1                   
 *             #1                   NA           #1          #1
 *           Vsys_det                        #2                         
 *       NA                  #3            NA         NA
 *
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------/
 * CCG6DF_CFP-Port1:
 *           UV                                    #0                   
 *             #0                   NA           #0          #0
 *           OV                                    #1                   
 *             #1                   NA           #1          #1
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------/
 */
#define PDSS_COMP_CTRL_ADDRESS(m,n)                         (0x400a87d0UL + ((m) * (0x10000UL)) + ((n) * (0x0004UL)))
#define PDSS_COMP_CTRL(m,n)                                 (*(volatile uint32_t *)(0x400a87d0UL + ((m) * (0x10000UL)) + ((n) * 0x0004)))
#define PDSS_COMP_CTRL_DEFAULT                              (0x80000001UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value "0"
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
 * CCG6DF_CFP:
 *   First Instance:
 *   USBPD0.5VPUMP[0] ==> cc_shvt_top + AMUX Network
 *   USBPD0.5VPUMP[1] ==> SBU switch
 *  Second Instance
 *   USBPD1.5VPUMP[0] ==> cc_shvt_top + AMUX Network
 *   USBPD1.5VPUMP[1] ==> SBU switch
 */
#define PDSS_PUMP5V_CTRL_ADDRESS(m,n)                       (0x400a886cUL + ((m) * (0x10000UL)) + ((n) * (0x0004UL)))
#define PDSS_PUMP5V_CTRL(m,n)                               (*(volatile uint32_t *)(0x400a886cUL + ((m) * (0x10000UL)) + ((n) * 0x0004)))
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
 * S8USBPDV2 Hard IP FRS Register
 */
#define PDSS_FRS_CTRL_ADDRESS(m)                            (0x400aa0f0UL + ((m) * (0x10000UL)))
#define PDSS_FRS_CTRL(m)                                    (*(volatile uint32_t *)(0x400aa0f0UL + ((m) * 0x10000UL)))
#define PDSS_FRS_CTRL_DEFAULT                               (0x00070000UL)

/*
 * Enable the current bias generation circuit
 */
#define PDSS_FRS_CTRL_FRS_BIAS_EN                           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Enables ADFT mode for this block
 */
#define PDSS_FRS_CTRL_ADFT_EN                               (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value.
 */
#define PDSS_FRS_CTRL_FRS_ISO_N                             (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Selects required ADFT mode for this block
 *
 * adft_ctrl_hv<3:0> : adft_out_hv<0> : adft_out_hv<1>
 * 0000 : Hi-Z : Hi-Z
 * 0001 : v10p_vcp1 : vgnd
 * 0010: v10p_vcp2 : vgnd
 * 0100 : vgnd : vgnd
 * 1000 : vgnd : vgnd
 */
#define PDSS_FRS_CTRL_FRS_ADFT_CTRL_MASK                    (0x00000078UL) /* <3:6> R:RW:0: */
#define PDSS_FRS_CTRL_FRS_ADFT_CTRL_POS                     (3UL)


/*
 * Test-Mode for debug and engineering purposes
 *
 * tm_ngdo<0> 1: disable the switch
 * tm_ngdo<1> 1: disable the pulldown path in switch
 * tm_ngdo<2> 1:disbale the pulldown on cp for switch 2
 * tm_ngdo<3> spare
 */
#define PDSS_FRS_CTRL_TM_FRS_MASK                           (0x00000f00UL) /* <8:11> R:RW:0: */
#define PDSS_FRS_CTRL_TM_FRS_POS                            (8UL)


/*
 * 0: Disable scp fault(HV signal from SCP hHard-IP)  to tri-state the FRS
 * gate-driver output
 * 1: Allow scp fault to tri-state the FRS gate-driver output
 */
#define PDSS_FRS_CTRL_FAULT_SCP_EN                          (1UL << 16) /* <16:16> R:RW:1: */


/*
 * 0: Disable rcp fault(HV signal from RCP hHard-IP)  to tri-state the FRS
 * gate-driver output
 * 1: Allow rcp fault to tri-state the FRS gate-driver output
 */
#define PDSS_FRS_CTRL_FAULT_RCP_EN                          (1UL << 17) /* <17:17> R:RW:1: */


/*
 * 0: Disable vbus_ov fault(HV signal from RCP hHard-IP)  to tri-state the
 * FRS gate-driver output
 * 1: Allow vbus_ov fault to tri-state the FRS gate-driver output
 */
#define PDSS_FRS_CTRL_FAULT_VBUS_OV_EN                      (1UL << 18) /* <18:18> R:RW:1: */


/*
 * Forced SCP fault to pulldown gatedriver output
 *
 * 0 : Normal operation
 * 1= Force SCP fault
 */
#define PDSS_FRS_CTRL_FAULT_FORCE_SCP                       (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Forced RCP/VBUS_OV fault to pulldown gatedriver output
 *
 * 0 : Normal operation
 * 1= Force RCP/VBUS_OV fault
 */
#define PDSS_FRS_CTRL_FAULT_FORCE_RCP                       (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Source of the clk_in port of s8usbpdv2_ccg6df_frs_top:
 * 0: Disabled. Clock is truned off.
 * 1: clk_hf divide by 2
 * 2: clk_hf divide by 4
 * 3: clk_hf
 */
#define PDSS_FRS_CTRL_FRS_CLOCK_SOURCE_MASK                 (0xc0000000UL) /* <30:31> R:RW:0: */
#define PDSS_FRS_CTRL_FRS_CLOCK_SOURCE_POS                  (30UL)


/*
 * FRS Sequence counter
 */
#define PDSS_FRS_SEQ_CNTR_ADDRESS(m)                        (0x400aa0fcUL + ((m) * (0x10000UL)))
#define PDSS_FRS_SEQ_CNTR(m)                                (*(volatile uint32_t *)(0x400aa0fcUL + ((m) * 0x10000UL)))
#define PDSS_FRS_SEQ_CNTR_DEFAULT                           (0xa2850a14UL)

/*
 * The Hard IP NGDO cp_en pin get the value from V2_NGDO_0_CP_EN_CTRL register
 * (NGDO_CP_EN_ON_VALUE+1) of clk_frs_en_seq cycles after NGDO ngdo_en pin
 * assertion based on FRS detection.
 */
#define PDSS_FRS_SEQ_CNTR_NGDO_CP_EN_ON_VALUE_MASK          (0x0000001fUL) /* <0:4> R:RW:20: */
#define PDSS_FRS_SEQ_CNTR_NGDO_CP_EN_ON_VALUE_POS           (0UL)


/*
 * The Hard IP NGDO keep_off_disable pin gets the value from V2_NGDO_KEEP_OFF_DISABLE_CTRL
 * register (NGDO_KEEP_OFF_DISABLE_ON_VALUE+1) of clk_frs_en_seq cycles after
 * internal FRS sequence counter reaches NGDO_CP_EN_ON_VALUE
 */
#define PDSS_FRS_SEQ_CNTR_NGDO_KEEP_OFF_DISABLE_ON_VALUE_MASK    (0x00000f80UL) /* <7:11> R:RW:20: */
#define PDSS_FRS_SEQ_CNTR_NGDO_KEEP_OFF_DISABLE_ON_VALUE_POS    (7UL)


/*
 * The Hard IP NGDO gdrv_en pin gets the value from V2_NGDO_0_GDRV_EN_CTRL
 * register  (NGDO_GDRV_EN_ON_VALUE+1) of clk_frs_en_seq cycles after internal
 * FRS sequence counter reaches NGDO_KEEP_OFF_DISABLE_ON_VALUE
 */
#define PDSS_FRS_SEQ_CNTR_NGDO_GDRV_EN_ON_VALUE_MASK        (0x0007c000UL) /* <14:18> R:RW:20: */
#define PDSS_FRS_SEQ_CNTR_NGDO_GDRV_EN_ON_VALUE_POS         (14UL)


/*
 * The Hard IP FRS frs_sw_en pin gets the value from FRS_SW_EN_CTRL register
 * (FRS_SW_EN_ON_VALUE+1) of clk_frs_en_seq cycles after internal FRS sequence
 * counter reaches NGDO_GDRV_EN_ON_VALUE
 */
#define PDSS_FRS_SEQ_CNTR_FRS_SW_EN_ON_VALUE_MASK           (0x03e00000UL) /* <21:25> R:RW:20: */
#define PDSS_FRS_SEQ_CNTR_FRS_SW_EN_ON_VALUE_POS            (21UL)


/*
 * The Hard IP FRS frs_cp_en pin gets the value from FRS_CP_EN_CTRL register
 * (FRS_CP_EN_ON_VALUE+1) of clk_frs_en_seq cycles after internal FRS sequence
 * counter reaches FRS_SW_EN_ON_VALUE
 */
#define PDSS_FRS_SEQ_CNTR_FRS_CP_EN_ON_VALUE_MASK           (0x78000000UL) /* <27:30> R:RW:4: */
#define PDSS_FRS_SEQ_CNTR_FRS_CP_EN_ON_VALUE_POS            (27UL)


/*
 * 0: FRS sequencing based on FRS detection is disabled
 * 1: FRS sequencing based on FRS detection is enabled.
 */
#define PDSS_FRS_SEQ_CNTR_EN_FRS_SEQ                        (1UL << 31) /* <31:31> R:RW:1: */


/*
 * Band gap primary Voltage and Current reference generator control register
 */
#define PDSS_PD_BG_CTRL_ADDRESS(m)                          (0x400aa500UL + ((m) * (0x10000UL)))
#define PDSS_PD_BG_CTRL(m)                                  (*(volatile uint32_t *)(0x400aa500UL + ((m) * 0x10000UL)))
#define PDSS_PD_BG_CTRL_DEFAULT                             (0x0000000cUL)

/*
 * ADFT enable
 */
#define PDSS_PD_BG_CTRL_ADFT_EN                             (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable signal for CTAT current generator leakage compensation
 */
#define PDSS_PD_BG_CTRL_ICTAT_LEAKCOMP_EN                   (1UL << 2) /* <2:2> R:RW:1: */


/*
 * Enable signal for bandgap core and voltge buffer.
 * Must be enabled before enabling ANY analog busing references lock to work
 * in USBPB
 */
#define PDSS_PD_BG_CTRL_BG_EN                               (1UL << 3) /* <3:3> R:RW:1: */


/*
 * To select different signals for ADFT output
 */
#define PDSS_PD_BG_CTRL_PD_BG_ADFT_CTRL_MASK                (0x00000070UL) /* <4:6> R:RW:0: */
#define PDSS_PD_BG_CTRL_PD_BG_ADFT_CTRL_POS                 (4UL)


/*
 * Power down signal for current generator.
 * Must be enabled before enabling ANY analog busing references lock to work
 * in USBPB
 */
#define PDSS_PD_BG_CTRL_IGEN_PD                             (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Current Mirror Current reference generator control register
 */
#define PDSS_PD_BG_IREF8_CTRL_ADDRESS(m)                    (0x400aa504UL + ((m) * (0x10000UL)))
#define PDSS_PD_BG_IREF8_CTRL(m)                            (*(volatile uint32_t *)(0x400aa504UL + ((m) * 0x10000UL)))
#define PDSS_PD_BG_IREF8_CTRL_DEFAULT                       (0x00000003UL)

/*
 * Enable signal for currents
 * FIRST INSTANCE :
 * CC_PHY, VSENSE, FRS, ADC, NGDO, VCONN, 5V-Pump(CC & AMUX)
 *
 * SECOND INSTANCE :
 * ILIMIT, TEMPERATURE SENSOR, SCP, RCP, SBU-CLIPPER, 5V-Pump(SBU)
 */
#define PDSS_PD_BG_IREF8_CTRL_BG_IREF_EN_MASK               (0x00000003UL) /* <0:1> R:RW:3: */
#define PDSS_PD_BG_IREF8_CTRL_BG_IREF_EN_POS                (0UL)


/*
 * Voltage reference generator control register
 */
#define PDSS_PD_REF_GEN_CTRL_ADDRESS(m)                     (0x400aa508UL + ((m) * (0x10000UL)))
#define PDSS_PD_REF_GEN_CTRL(m)                             (*(volatile uint32_t *)(0x400aa508UL + ((m) * 0x10000UL)))
#define PDSS_PD_REF_GEN_CTRL_DEFAULT                        (0x00000001UL)

/*
 * Block power down input
 * 1 - All analog and DC paths cut off, outputs forced to known value
 *
 * 0 - Normal functionality
 * Must be enabled when using ADC, UV, OV Comparators, VSYS Detect Comparator
 */
#define PDSS_PD_REF_GEN_CTRL_PD                             (1UL << 0) /* <0:0> R:RW:1: */


/*
 * ADFT enable
 */
#define PDSS_PD_REF_GEN_CTRL_ADFT_EN                        (1UL << 1) /* <1:1> R:RW:0: */


/*
 * To select different signals for ADFT output
 */
#define PDSS_PD_REF_GEN_CTRL_REF_ADFT_CTRL_MASK             (0x0000000cUL) /* <2:3> R:RW:0: */
#define PDSS_PD_REF_GEN_CTRL_REF_ADFT_CTRL_POS              (2UL)


/*
 * Voltage reference analog multiplexer control register 0
 */
#define PDSS_PD_REF_MUX_CTRL_0_ADDRESS(m)                   (0x400aa50cUL + ((m) * (0x10000UL)))
#define PDSS_PD_REF_MUX_CTRL_0(m)                           (*(volatile uint32_t *)(0x400aa50cUL + ((m) * 0x10000UL)))
#define PDSS_PD_REF_MUX_CTRL_0_DEFAULT                      (0x00000000UL)

/*
 * Selection bits for VREF_OUT0
 *
 * 00000000 = 10mV
 * .
 * .
 * .
 * 11000111 = 2200mV (Step = 10mV)
 */
#define PDSS_PD_REF_MUX_CTRL_0_VREF_SEL0_MASK               (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_PD_REF_MUX_CTRL_0_VREF_SEL0_POS                (0UL)


/*
 * Selection bits for VREF_OUT1 (Min = 10mV, Max = 2200mV, Step = 10mV)
 */
#define PDSS_PD_REF_MUX_CTRL_0_VREF_SEL1_MASK               (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_PD_REF_MUX_CTRL_0_VREF_SEL1_POS                (8UL)


/*
 * Selection bits for VREF_OUT2 (Min = 10mV, Max = 2200mV, Step = 10mV) -
 * UV Compaator
 */
#define PDSS_PD_REF_MUX_CTRL_0_VREF_SEL2_MASK               (0x00ff0000UL) /* <16:23> R:RW:0: */
#define PDSS_PD_REF_MUX_CTRL_0_VREF_SEL2_POS                (16UL)


/*
 * Selection bits for VREF_OUT3 (Min = 10mV, Max = 2200mV, Step = 10mV) -
 * OV Compaator
 */
#define PDSS_PD_REF_MUX_CTRL_0_VREF_SEL3_MASK               (0xff000000UL) /* <24:31> R:RW:0: */
#define PDSS_PD_REF_MUX_CTRL_0_VREF_SEL3_POS                (24UL)


/*
 * Voltage reference analog multiplexer control register 1
 */
#define PDSS_PD_REF_MUX_CTRL_1_ADDRESS(m)                   (0x400aa510UL + ((m) * (0x10000UL)))
#define PDSS_PD_REF_MUX_CTRL_1(m)                           (*(volatile uint32_t *)(0x400aa510UL + ((m) * 0x10000UL)))
#define PDSS_PD_REF_MUX_CTRL_1_DEFAULT                      (0x00000000UL)

/*
 * ADFT enable
 */
#define PDSS_PD_REF_MUX_CTRL_1_ADFT_EN                      (1UL << 1) /* <1:1> R:RW:0: */


/*
 * To select different signals for ADFT output
 */
#define PDSS_PD_REF_MUX_CTRL_1_MUX_ADFT_CTRL_MASK           (0x0000001cUL) /* <2:4> R:RW:0: */
#define PDSS_PD_REF_MUX_CTRL_1_MUX_ADFT_CTRL_POS            (2UL)


/*
 * Selection bits for VREF_OUT4 (Min = 10mV, Max = 2200mV, Step = 10mV) -
 * VSYS Detect
 */
#define PDSS_PD_REF_MUX_CTRL_1_VREF_SEL4_MASK               (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_PD_REF_MUX_CTRL_1_VREF_SEL4_POS                (8UL)


/*
 * VBUS Regulator control register
 */
#define PDSS_PD_REG_CTRL_ADDRESS(m)                         (0x400aa514UL + ((m) * (0x10000UL)))
#define PDSS_PD_REG_CTRL(m)                                 (*(volatile uint32_t *)(0x400aa514UL + ((m) * 0x10000UL)))
#define PDSS_PD_REG_CTRL_DEFAULT                            (0x00040400UL)

/*
 * Output isolation control, Active Low
 * 0 - All digital outputs are forced to known value ("0")
 */
#define PDSS_PD_REG_CTRL_ISO_N                              (1UL << 0) /* <0:0> R:RW:0: */


/*
 * ADFT enable
 */
#define PDSS_PD_REG_CTRL_ADFT_EN                            (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Chooses priority between Port-0 & Port-1 regulator when both supplies
 * are present
 * 0 : Port-0 Regulator
 * 1 : Port-1 Regulator
 */
#define PDSS_PD_REG_CTRL_VBUS_PRIORITY                      (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Bypass accurate VSYS detect
 * 1 : Will check for VSYS_DETECT_ACCURATE
 * 0 (Default) : Uses crude VSYS DETECT
 */
#define PDSS_PD_REG_CTRL_BYPASS_VSYS_GOOD_ACCB              (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Reference voltage select signal
 * 0 - Use crude reference
 * 1 - Use bandgap reference
 */
#define PDSS_PD_REG_CTRL_VBG_EN                             (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Inrush current detection level selection
 * 2b'00 : 55 mA
 * 2b'01 : 130 mA
 * 2b'10 : 255 mA (Default)
 * 2b'11 : 325 mA
 */
#define PDSS_PD_REG_CTRL_INRUSH_DET_SEL_MASK                (0x00000600UL) /* <9:10> R:RW:2: */
#define PDSS_PD_REG_CTRL_INRUSH_DET_SEL_POS                 (9UL)


/*
 * To select different signals for ADFT output
 */
#define PDSS_PD_REG_CTRL_REG_ADFT_CTRL_MASK                 (0x00007000UL) /* <12:14> R:RW:0: */
#define PDSS_PD_REG_CTRL_REG_ADFT_CTRL_POS                  (12UL)


/*
 * Bypass charge-pump/iref/reg_ea disabling during VSYS good
 * 0 : Don't bypass
 * 1 : Bypass
 */
#define PDSS_PD_REG_CTRL_BYPASS_REG_DIS                     (1UL << 15) /* <15:15> R:RW:0: */


/*
 * tm_vreg<0>
 * 0: inrush clamp in normal function (default)
 * 1: forcefully disabling inrush clamp
 *
 * tm_vreg<1>
 * 0: inrush clamp in normal function (default)
 * 1: forcefully turning on inrush clamp
 *
 * tm_vreg<2>
 * 0: disable inrush detection
 * 1: enable inrush detection (default)
 *
 * tm_vreg<3>
 * 0:disable high inrush detection threshold (default)
 * 1: enable high inrush detection threshold
 *
 * tm_vreg<4>
 * 0: clk_out on ddft low (default)
 * 1: clk_out on ddft toggling
 *
 * tm_vreg<5>
 * 0: comp_out on ddft low (default)
 * 1: comp_out on ddft toggling
 *
 * tm_vreg<7:6> : Charge pump frequency adjustment
 * 00: no change
 * 01:1.3times
 * 10:1.85times
 * 11: 3.25times
 */
#define PDSS_PD_REG_CTRL_TM_VREG_REG2_MASK                  (0x00ff0000UL) /* <16:23> R:RW:4: */
#define PDSS_PD_REG_CTRL_TM_VREG_REG2_POS                   (16UL)


/*
 * Regulator Load Switch control register
 */
#define PDSS_PD_REG_40NLSW_CTRL_ADDRESS(m)                  (0x400aa530UL + ((m) * (0x10000UL)))
#define PDSS_PD_REG_40NLSW_CTRL(m)                          (*(volatile uint32_t *)(0x400aa530UL + ((m) * 0x10000UL)))
#define PDSS_PD_REG_40NLSW_CTRL_DEFAULT                     (0x00000000UL)

/*
 * Output isolation control, Active Low
 * 0 - All digital outputs are forced to known value ("0")
 */
#define PDSS_PD_REG_40NLSW_CTRL_ISO_N                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * 30VCONN control register
 */
#define PDSS_PD_30VCONN_CTRL_ADDRESS(m)                     (0x400aa534UL + ((m) * (0x10000UL)))
#define PDSS_PD_30VCONN_CTRL(m)                             (*(volatile uint32_t *)(0x400aa534UL + ((m) * 0x10000UL)))
#define PDSS_PD_30VCONN_CTRL_DEFAULT                        (0x00000000UL)

/*
 * Output isolation control, Active Low
 * 0 - All digital outputs are forced to known value ("0")
 */
#define PDSS_PD_30VCONN_CTRL_ISO_N                          (1UL << 0) /* <0:0> R:RW:0: */


/*
 * ADFT enable
 */
#define PDSS_PD_30VCONN_CTRL_ADFT_EN                        (1UL << 1) /* <1:1> R:RW:0: */


/*
 * 0 : When switch(CC1/CC2) enabled, CC OVP checked with v5v only. When switch
 * is disabled, checked with max of v5v and vddd.
 * 1 : CC OVP always checked with max of v5v & vddd
 */
#define PDSS_PD_30VCONN_CTRL_DIS_PGATE_CC_VTP_OVP           (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Ungate the output of the accurate OVP comparator which compares V5V with
 * CC1/CC2
 */
#define PDSS_PD_30VCONN_CTRL_EN_CC_V5V_OVP_COMP             (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Increases the current used to charge the CC switch gate terminals.  Improves
 * turn-on time of the CC1/CC2 switch
 */
#define PDSS_PD_30VCONN_CTRL_EN_HIGHI_INRUSH                (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Increases offset of the accurate OVP comparator which compares V5V with
 * CC1/CC2
 */
#define PDSS_PD_30VCONN_CTRL_EN_HIGH_VTP_OVP                (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Connects the input of the OCP comparator to CC1/CC2 and V5V pins.  Else
 * leaves the pins floating
 */
#define PDSS_PD_30VCONN_CTRL_EN_OCP_TAP                     (1UL << 8) /* <8:8> R:RW:0: */


/*
 * To be enabled during VCONN OCP Test at sort & backend
 * 0(default) : Will enable full switch (CC1/CC2) based on EN_SW_CC1 or EN_SW_CC2
 * 1 : Will enable only a portion of the original switch as we cannot flow
 * 500mA at sort to compare OCP
 */
#define PDSS_PD_30VCONN_CTRL_EN_REPLICA_SW_4_TST            (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 0 (Default) : Disable's comparator that checks if V5V voltage is > 6V
 * 1 : Enable's comparator that checks if V5V voltage is > 6V
 */
#define PDSS_PD_30VCONN_CTRL_EN_V5V_OVP6V_COMP              (1UL << 10) /* <10:10> R:RW:0: */


/*
 * To be enabled during VCONN V5V OVP Test at sort & backend
 * 0(default) : Default Tap Point
 * 1 : Selects a higher tap-point during test as we cannot raise V5V to 6V
 * during test
 */
#define PDSS_PD_30VCONN_CTRL_EN_V5V_OVP6V_COMP_TEST         (1UL << 11) /* <11:11> R:RW:0: */


/*
 * To select a higher tap-point (engineering option)
 */
#define PDSS_PD_30VCONN_CTRL_EN_V5V_OVP6V_TRIP_INC          (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Selects "external clock" for the charge-pump when set to "1" (Debug Option)
 */
#define PDSS_PD_30VCONN_CTRL_T_EXT_CLK                      (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Enable signal for internal 10V pump
 */
#define PDSS_PD_30VCONN_CTRL_EN_PUMP                        (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Enable signal for v5v detector, active high
 */
#define PDSS_PD_30VCONN_CTRL_EN_V5V_DET_COMP                (1UL << 15) /* <15:15> R:RW:0: */


/*
 * To enable the OCP output.  Need to enable after OCP enable and CC switch
 * enable
 * If set to "1" from beginning, there could be glitch in the OCP circuit
 * (due to glitch or inrush) when CC switch is enabled
 */
#define PDSS_PD_30VCONN_CTRL_DIS_OCP_BLANKING               (1UL << 16) /* <16:16> R:RW:0: */


/*
 * 0(default) : CC1 Switch between CC1 & V5V is disabled
 * 1 : CC1 Switch between CC1 & V5V is enabled
 */
#define PDSS_PD_30VCONN_CTRL_EN_CC1_SW                      (1UL << 17) /* <17:17> R:RW:0: */


/*
 * 0(default) : CC2 Switch between CC1 & V5V is disabled
 * 1 : CC2 Switch between CC1 & V5V is enabled
 */
#define PDSS_PD_30VCONN_CTRL_EN_CC2_SW                      (1UL << 18) /* <18:18> R:RW:0: */


/*
 * 0(default) : Over-Current detection disabled for CC1
 * 1 : Over-Current detection enabled for CC1
 */
#define PDSS_PD_30VCONN_CTRL_VCONN30_EN_OCP_CC1             (1UL << 19) /* <19:19> R:RW:0: */


/*
 * 0(default) : Over-Current detection disabled for CC2
 * 1 : Over-Current detection enabled for CC2
 */
#define PDSS_PD_30VCONN_CTRL_VCONN30_EN_OCP_CC2             (1UL << 20) /* <20:20> R:RW:0: */


/*
 * 0(default) : Enables autoshutdown of CC switches when OVP occurs
 * 1 : Disables autoshutdown of CC switches when OVP occurs
 */
#define PDSS_PD_30VCONN_CTRL_DIS_OVP_AUTOSHUTDN             (1UL << 21) /* <21:21> R:RW:0: */


/*
 * To select different signals for ADFT output
 */
#define PDSS_PD_30VCONN_CTRL_VCONN30_ADFT_CTRL_MASK         (0x03c00000UL) /* <22:25> R:RW:0: */
#define PDSS_PD_30VCONN_CTRL_VCONN30_ADFT_CTRL_POS          (22UL)


/*
 * 0(default) : Over-Voltage detection disabled for CC1
 * 1 : Over-Voltage detection enabled for CC1
 */
#define PDSS_PD_30VCONN_CTRL_EN_OVP_CC1                     (1UL << 26) /* <26:26> R:RW:0: */


/*
 * 0(default) : Over-Voltage detection disabled for CC2
 * 1 : Over-Voltage detection enabled for CC2
 */
#define PDSS_PD_30VCONN_CTRL_EN_OVP_CC2                     (1UL << 27) /* <27:27> R:RW:0: */


/*
 * Dual NFET Gate Driver block control register 0
 */
#define PDSS_NGDO_P5C40_CTRL_0_ADDRESS(m)                   (0x400aa540UL + ((m) * (0x10000UL)))
#define PDSS_NGDO_P5C40_CTRL_0(m)                           (*(volatile uint32_t *)(0x400aa540UL + ((m) * 0x10000UL)))
#define PDSS_NGDO_P5C40_CTRL_0_DEFAULT                      (0x1007046cUL)

/*
 * Output isolation control, Active Low
 * 0 - All digital outputs are forced to known value ("0")
 */
#define PDSS_NGDO_P5C40_CTRL_0_ISO_N                        (1UL << 0) /* <0:0> R:RW:0: */


/*
 * ADFT enable
 */
#define PDSS_NGDO_P5C40_CTRL_0_ADFT_EN                      (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Keep off Control
 * 0= Keep off control circuit enabled
 * 1= Keep off control circuit disabled
 */
#define PDSS_NGDO_P5C40_CTRL_0_KEEP_OFF_DISABLE             (1UL << 2) /* <2:2> R:RW:1: */


/*
 * Gatedriver Enable.
 * gdrv_en = 0 The gate control output is pulled low
 * gdrv_en = 1 The gate control output is  controlled by slew rate block
 */
#define PDSS_NGDO_P5C40_CTRL_0_GDRV_EN                      (1UL << 3) /* <3:3> R:RW:1: */


/*
 * Charge-pump ouptut control;
 * cp_en = 0 ; cp output = vbus
 * cp_en = 1 ; cp output = driven by cp action
 */
#define PDSS_NGDO_P5C40_CTRL_0_CP_EN                        (1UL << 5) /* <5:5> R:RW:1: */


/*
 * Enable signal for the bias circuitry and slew rate block
 * ngdo_en = 0 ; disabled
 * ngdo_en = 1 ; enabled
 */
#define PDSS_NGDO_P5C40_CTRL_0_NGDO_EN                      (1UL << 6) /* <6:6> R:RW:1: */


/*
 * Programmability for external NFET gate charging current (default 0x4=
 * 2.1u)
 * LSB current(step size) = 150nA
 * Max setting allowed = 0x1C
 */
#define PDSS_NGDO_P5C40_CTRL_0_SLEW_CTRL_MASK               (0x00003f00UL) /* <8:13> R:RW:4: */
#define PDSS_NGDO_P5C40_CTRL_0_SLEW_CTRL_POS                (8UL)


/*
 * 0: Disable scp fault to pulldown gate driver output
 * 1: Allow scp fault to pulldown gate driver output
 */
#define PDSS_NGDO_P5C40_CTRL_0_FAULT_SCP_EN                 (1UL << 16) /* <16:16> R:RW:1: */


/*
 * 0: Disable rcp fault to pulldown gate driver output
 * 1: Allow rcp fault to pulldown gate driver output
 */
#define PDSS_NGDO_P5C40_CTRL_0_FAULT_RCP_EN                 (1UL << 17) /* <17:17> R:RW:1: */


/*
 * 0: Disable  vbus_ov fault to pulldown gate driver output
 * 1: To allow vbus_ov fault to pulldown gate driver output
 */
#define PDSS_NGDO_P5C40_CTRL_0_FAULT_VBUS_OV_EN             (1UL << 18) /* <18:18> R:RW:1: */


/*
 * Forced SCP fault to pulldown gatedriver output
 * 1= Force SCP fault. Fast pulldown enabled on G1.
 */
#define PDSS_NGDO_P5C40_CTRL_0_FAULT_FORCE_SCP              (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Forced RCP fault to pulldown gatedriver output
 * 1= Force RCP fault. Fast pulldown enabled on G0.
 */
#define PDSS_NGDO_P5C40_CTRL_0_FAULT_FORCE_RCP              (1UL << 20) /* <20:20> R:RW:0: */


/*
 * To select different signals for ADFT output
 */
#define PDSS_NGDO_P5C40_CTRL_0_P5C40_ADFT_CTRL_MASK         (0x01e00000UL) /* <21:24> R:RW:0: */
#define PDSS_NGDO_P5C40_CTRL_0_P5C40_ADFT_CTRL_POS          (21UL)


/*
 * External clock selection
 * t_ext_clk_sel = 0 Internal clock used
 * t_ext_clk_sel = 1 External clock used
 */
#define PDSS_NGDO_P5C40_CTRL_0_T_EXT_CLK_SEL                (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Programmable delay control for pulldown during Normal Turn OFF
 * 000 --> 0
 * 001 --> 3.57u
 * 010 --> 6.1u
 * 011 --> 8.27u
 * 100 --> 11.14u
 * 101 --> 13.23u
 * 110 --> 15.57u
 * 111 --> 17.6u
 */
#define PDSS_NGDO_P5C40_CTRL_0_T_SW_OFF_DELAY_MASK          (0x1c000000UL) /* <26:28> R:RW:4: */
#define PDSS_NGDO_P5C40_CTRL_0_T_SW_OFF_DELAY_POS           (26UL)


/*
 * Dual NFET Gate Driver block control register 1
 */
#define PDSS_NGDO_P5C40_CTRL_1_ADDRESS(m)                   (0x400aa544UL + ((m) * (0x10000UL)))
#define PDSS_NGDO_P5C40_CTRL_1(m)                           (*(volatile uint32_t *)(0x400aa544UL + ((m) * 0x10000UL)))
#define PDSS_NGDO_P5C40_CTRL_1_DEFAULT                      (0x00200401UL)

/*
 * Test mode purpose.
 * 0 1: decreases scp fault pd strength by 2X
 * 1 1: increases scp fault pd strength by 6X
 * 2 1: doubles the oscillator frequency
 * 3 0: prioritizes RCP over SCP
 *    1: prioritizes SCP over RCP
 * 4 1: disables the gdrv pulse pull down during normal OFF
 * 5 1: disables fault SCP pulse based pull-down
 * 6 1: enables static fault SCP pull-down
 * 7 1: enables the VGS equalization switch turn ON during normal OFF condition
 * 8 1: disables the VGS equalization switch turn ON during SCP event
 * 9 1: disables ibias output from vpump domain
 * 11:10 Configuration bits for pulse width of 1us pulse based SCP pull-down
 * 12 1: increases rcp fault pd strength by 2X
 * 13 1: decreases rcp fault pd strength by 6X
 * 14 1: Enables RCP fast pulldown on G0 during normal OFF
 * 15 1: ibias in the idac will be gated by ngdo_en
 */
#define PDSS_NGDO_P5C40_CTRL_1_TM_NGDO_MASK                 (0x0000ffffUL) /* <0:15> R:RW:1025: */
#define PDSS_NGDO_P5C40_CTRL_1_TM_NGDO_POS                  (0UL)


/*
 * 0 1: reverts the GDRV pulse PD strength
 * 1 0: sets VBUS_C SCP Toff-fault time to max 500ns
 *    1: sets VBUS_C SCP Toff-fault time to max 900ns
 *    This setting is valid only when TM_NGDO<1:0>=1
 */
#define PDSS_NGDO_P5C40_CTRL_1_CONFIG_NGDO_MASK             (0x00180000UL) /* <19:20> R:RW:0: */
#define PDSS_NGDO_P5C40_CTRL_1_CONFIG_NGDO_POS              (19UL)


/*
 * Gate 2 charging control, for plateau fix
 * 0: enables gate 2 charging when GDRV_EN=1
 * 1: disables gate 2 charging (default)
 */
#define PDSS_NGDO_P5C40_CTRL_1_G2_DISABLE                   (1UL << 21) /* <21:21> R:RW:1: */


/*
 * 30V SBU clipper control register
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_ADDRESS(m)               (0x400aa550UL + ((m) * (0x10000UL)))
#define PDSS_PD_30SBU_CLIPPER_CTRL(m)                       (*(volatile uint32_t *)(0x400aa550UL + ((m) * 0x10000UL)))
#define PDSS_PD_30SBU_CLIPPER_CTRL_DEFAULT                  (0x005d0000UL)

/*
 * ADFT enable
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_CLIPPER_ADFT_EN          (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable switch between IN1 and OUT1 pins
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_SBU1_EN                  (1UL << 2) /* <2:2> R:RW:0: */


/*
 * To select different signals for ADFT output
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_CLIPPER_ADFT_CTRL_MASK    (0x00000018UL) /* <3:4> R:RW:0: */
#define PDSS_PD_30SBU_CLIPPER_CTRL_CLIPPER_ADFT_CTRL_POS    (3UL)


/*
 * Enable switch between IN2 and OUT2 pins
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_SBU2_EN                  (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Testmode for sbu
 * tm_sbu<0>, 0 : Don't bypass pump_good_hv, 1 : Bypass pump_good_hv
 * tm_sbu<1>, 0 : On iref_cm, 1: Off iref_cm
 * tm_sbu<2>, Parking
 * tm_sbu<3>, Parking
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_TM_SBU_MASK              (0x00000f00UL) /* <8:11> R:RW:0: */
#define PDSS_PD_30SBU_CLIPPER_CTRL_TM_SBU_POS               (8UL)


/*
 * Output isolation control, Active Low
 * 0 - All digital outputs are forced to known value ("0")
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_CLIPPER_ISO_N            (1UL << 16) /* <16:16> R:RW:1: */


/*
 * OVP detection threshold selection
 * 0 : 1.8V IO
 * 1 : 3..3V IO
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_DET_LEVEL_CTRL           (1UL << 17) /* <17:17> R:RW:0: */


/*
 * Enable signal for crude OVP detect
 * 0 : Disable
 * 1: Enable
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_VTP               (1UL << 18) /* <18:18> R:RW:1: */


/*
 * Enable signal for accurate OVP detect
 * 0 : Disable
 * 1: Enable
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_COMP              (1UL << 19) /* <19:19> R:RW:1: */


/*
 * Enable signal for accurate OVP detect output
 * 0 : Disable
 * 1: Enable
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_COMP_OUT          (1UL << 20) /* <20:20> R:RW:1: */


/*
 * Disable SBU switch-off by OVP
 * 0 : SBU switch-off by OVP
 * 1: Disable SBU switch-off by OVP
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_DIS_OVP_AUTOSHUTDN       (1UL << 21) /* <21:21> R:RW:0: */


/*
 * OVP detection threshold selection
 * 00 : 2.14V / 3.65V
 * 01 : 2.18V / 3.70V
 * 10 : 2.22V / 3.75V
 * 11 : 2.26V / 3.80V
 */
#define PDSS_PD_30SBU_CLIPPER_CTRL_OVP_COMP_OFFSET_MASK     (0x00c00000UL) /* <22:23> R:RW:1: */
#define PDSS_PD_30SBU_CLIPPER_CTRL_OVP_COMP_OFFSET_POS      (22UL)


/*
 * SBU AUX Termination resistors control register
 */
#define PDSS_PD_SBU_TERM_CTRL_ADDRESS(m)                    (0x400aa554UL + ((m) * (0x10000UL)))
#define PDSS_PD_SBU_TERM_CTRL(m)                            (*(volatile uint32_t *)(0x400aa554UL + ((m) * 0x10000UL)))
#define PDSS_PD_SBU_TERM_CTRL_DEFAULT                       (0x00000000UL)

/*
 * Enables 1MOhm Pull-up to VDDD on AUXP
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_TERM_CTRL_OUT1_1MEG_EN_PU               (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Enables 100KOhm Pull-down to VDDD on AUXP
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_TERM_CTRL_OUT1_100K_EN_PD               (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enables 470KOhm Pull-down to VDDD on AUXP
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_TERM_CTRL_OUT1_470K_EN_PD               (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Enables 100KOhm Pull-up to VDDD on AUXN
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_TERM_CTRL_OUT2_100K_EN_PU               (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Enables 1MOhm Pull-down to VDDD on AUXN
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_TERM_CTRL_OUT2_1MEG_EN_PD               (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Enables 4.7MOhm Pull-down to VDDD on AUXN
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_TERM_CTRL_OUT2_4P7MEG_EN_PD             (1UL << 5) /* <5:5> R:RW:0: */


/*
 * SBU bi-directional low resistance cross switch control register
 */
#define PDSS_PD_SBU_LRES_CTRL_ADDRESS(m)                    (0x400aa558UL + ((m) * (0x10000UL)))
#define PDSS_PD_SBU_LRES_CTRL(m)                            (*(volatile uint32_t *)(0x400aa558UL + ((m) * 0x10000UL)))
#define PDSS_PD_SBU_LRES_CTRL_DEFAULT                       (0x00000000UL)

/*
 * ADFT enable
 */
#define PDSS_PD_SBU_LRES_CTRL_ADFT_EN                       (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable switch between IN1 and OUT1 pins (Cannot be enabled when IN1_OUT2
 * OR IN2_OUT1 are enabled)
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_LRES_CTRL_IN1_OUT1_EN                   (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Enable switch between IN2 and OUT1 pins (Cannot be enabled when IN1_OUT1
 * OR IN2_OUT2 are enabled)
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_LRES_CTRL_IN2_OUT1_EN                   (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Enable switch between IN1 and OUT2 pins (Cannot be enabled when IN1_OUT1
 * OR IN2_OUT2 are enabled)
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_LRES_CTRL_IN1_OUT2_EN                   (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Enable switch between IN2 and OUT2 pins (Cannot be enabled when IN1_OUT2
 * OR IN2_OUT1 are enabled)
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_LRES_CTRL_IN2_OUT2_EN                   (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Output isolation control, Active Low
 * 0 - All digital outputs are forced to known value ("0")
 */
#define PDSS_PD_SBU_LRES_CTRL_ADFT_SEL_MASK                 (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_PD_SBU_LRES_CTRL_ADFT_SEL_POS                  (6UL)


/*
 * SBU bi-directional High resistance cross switch control register
 */
#define PDSS_PD_SBU_HRES_CTRL_ADDRESS(m)                    (0x400aa55cUL + ((m) * (0x10000UL)))
#define PDSS_PD_SBU_HRES_CTRL(m)                            (*(volatile uint32_t *)(0x400aa55cUL + ((m) * 0x10000UL)))
#define PDSS_PD_SBU_HRES_CTRL_DEFAULT                       (0x00000024UL)

/*
 * ADFT enable
 */
#define PDSS_PD_SBU_HRES_CTRL_ADFT_EN                       (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable switch between IN1 and OUT1 pins (Cannot be enabled when IN1_OUT2
 * OR IN2_OUT1 are enabled)
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_HRES_CTRL_IN1_OUT1_EN                   (1UL << 2) /* <2:2> R:RW:1: */


/*
 * Enable switch between IN2 and OUT1 pins (Cannot be enabled when IN1_OUT1
 * OR IN2_OUT2 are enabled)
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_HRES_CTRL_IN2_OUT1_EN                   (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Enable switch between IN1 and OUT2 pins (Cannot be enabled when IN1_OUT1
 * OR IN2_OUT2 are enabled)
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_HRES_CTRL_IN1_OUT2_EN                   (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Enable switch between IN2 and OUT2 pins (Cannot be enabled when IN1_OUT2
 * OR IN2_OUT1 are enabled)
 * 1 : Enable
 * 0(Default) : Disable
 */
#define PDSS_PD_SBU_HRES_CTRL_IN2_OUT2_EN                   (1UL << 5) /* <5:5> R:RW:1: */


/*
 * Output isolation control, Active Low
 * 0 - All digital outputs are forced to known value ("0")
 */
#define PDSS_PD_SBU_HRES_CTRL_ADFT_SEL_MASK                 (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_PD_SBU_HRES_CTRL_ADFT_SEL_POS                  (6UL)


/*
 * SBU Level Shifter translation block control register
 */
#define PDSS_PD_SBU_LS_CTRL_0_ADDRESS(m)                    (0x400aa570UL + ((m) * (0x10000UL)))
#define PDSS_PD_SBU_LS_CTRL_0(m)                            (*(volatile uint32_t *)(0x400aa570UL + ((m) * 0x10000UL)))
#define PDSS_PD_SBU_LS_CTRL_0_DEFAULT                       (0x00000008UL)

/*
 * enable the 1meg resistor on lsrx pull down path
 */
#define PDSS_PD_SBU_LS_CTRL_0_EN_LSRX_PDRES_1MEG            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * enable the 10K resistor on lsTx pull UP path
 */
#define PDSS_PD_SBU_LS_CTRL_0_EN_LSTX_PURES_10K             (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Input buffer trip point select for the LV receiver in LSTX
 * 0(default) : CMOS
 * 1 : LVTTL
 */
#define PDSS_PD_SBU_LS_CTRL_0_LSTX_VTRIP_SEL                (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Enabling the hysteresis for lv receiver in LSTX
 */
#define PDSS_PD_SBU_LS_CTRL_0_LSTX_HYS_EN                   (1UL << 3) /* <3:3> R:RW:1: */


/*
 * LV Transmitter slow mode enable signal in LSTX
 */
#define PDSS_PD_SBU_LS_CTRL_0_LSTX_SLOW                     (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Transmitter mode in LSTX
 */
#define PDSS_PD_SBU_LS_CTRL_0_LSTX_MODE_MASK                (0x00000060UL) /* <5:6> R:RW:0: */
#define PDSS_PD_SBU_LS_CTRL_0_LSTX_MODE_POS                 (5UL)


/*
 * Enabling the hysteresis for lv receiver in LSTX
 */
#define PDSS_PD_SBU_LS_CTRL_0_LSRX_SLOW                     (1UL << 7) /* <7:7> R:RW:0: */


/*
 * LV Receiver slow mode enable signal in LSRX
 */
#define PDSS_PD_SBU_LS_CTRL_0_LSRX_MODE_MASK                (0x00000300UL) /* <8:9> R:RW:0: */
#define PDSS_PD_SBU_LS_CTRL_0_LSRX_MODE_POS                 (8UL)


/*
 * HV Transmitter slow mode enable signal in SBU1
 */
#define PDSS_PD_SBU_LS_CTRL_0_SBU1_SLOW                     (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Transmitter mode in SBU1
 */
#define PDSS_PD_SBU_LS_CTRL_0_SBU1_MODE_MASK                (0x00001800UL) /* <11:12> R:RW:0: */
#define PDSS_PD_SBU_LS_CTRL_0_SBU1_MODE_POS                 (11UL)


/*
 * Input buffer trip point select for the HV receiver on SBU2
 * 0(default) : CMOS
 * 1 : LVTTL
 */
#define PDSS_PD_SBU_LS_CTRL_0_SBU1_VTRIP_SEL                (1UL << 13) /* <13:13> R:RW:0: */


/*
 * "Input buffer trip point select for the HV receiver in SBU2
 * (0=CMOS, 1=LVTTL)"
 */
#define PDSS_PD_SBU_LS_CTRL_0_SBU2_SLOW                     (1UL << 14) /* <14:14> R:RW:0: */


/*
 * HV Transmitter slow mode enable signal in SBU2
 */
#define PDSS_PD_SBU_LS_CTRL_0_SBU2_MODE_MASK                (0x00018000UL) /* <15:16> R:RW:0: */
#define PDSS_PD_SBU_LS_CTRL_0_SBU2_MODE_POS                 (15UL)


/*
 * to select different signals for adft output
 */
#define PDSS_PD_SBU_LS_CTRL_0_SBU_LS_ADFT_CTRL_MASK         (0x000e0000UL) /* <17:19> R:RW:0: */
#define PDSS_PD_SBU_LS_CTRL_0_SBU_LS_ADFT_CTRL_POS          (17UL)


/*
 * sets the direction of LSTX
 * 0 : receiver mode (Data from LSTX to SBU1/2)
 * 1: Transmitter mode  (Data from SBU1/2 to LXTX)
 */
#define PDSS_PD_SBU_LS_CTRL_0_DIR_LSTX                      (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Enables the data path between SBU1 & LSTX (cannot be enabled when EN_SBU1_LSRX
 * & EN_SBU2_LSTX are enabled)
 */
#define PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSTX                  (1UL << 21) /* <21:21> R:RW:0: */


/*
 * Enables the data path between SBU1 & LSRX (cannot be enabled when EN_SBU1_LSTX
 * & EN_SBU2_LSRX are enabled)
 */
#define PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSRX                  (1UL << 22) /* <22:22> R:RW:0: */


/*
 * Enables the data path between SBU2 & LSTX (cannot be enabled when EN_SBU2_LSRX
 * & EN_SBU1_LSTX are enabled)
 */
#define PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSTX                  (1UL << 23) /* <23:23> R:RW:0: */


/*
 * Input buffer trip point select for the HV receiver on SBU1
 * 0(default) : CMOS
 * 1 : LVTTL
 */
#define PDSS_PD_SBU_LS_CTRL_0_SBU2_VTRIP_SEL                (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Enables the data path between SBU2 & LSRX (cannot be enabled when EN_SBU2_LSTX
 * & EN_SBU1_LSRX are enabled)
 */
#define PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSRX                  (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Output isolation control, Active Low
 * 0 - All digital outputs are forced to known value ("0")
 */
#define PDSS_PD_SBU_LS_CTRL_0_SBU_LS_ISO_N                  (1UL << 26) /* <26:26> R:RW:0: */


/*
 * SBU Level Shifter translation block control register
 */
#define PDSS_PD_SBU_LS_CTRL_1_ADDRESS(m)                    (0x400aa574UL + ((m) * (0x10000UL)))
#define PDSS_PD_SBU_LS_CTRL_1(m)                            (*(volatile uint32_t *)(0x400aa574UL + ((m) * 0x10000UL)))
#define PDSS_PD_SBU_LS_CTRL_1_DEFAULT                       (0x00000000UL)

/*
 * Configuring the weak resistance for auto detect on the lv side (lstx)
 */
#define PDSS_PD_SBU_LS_CTRL_1_CONF_AUTO_DET_LV_WEAK_RES_MASK    (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_PD_SBU_LS_CTRL_1_CONF_AUTO_DET_LV_WEAK_RES_POS    (0UL)


/*
 * Configuring the weak resistance for auto detect on the hv side (sbu1 and
 * sbu2)
 */
#define PDSS_PD_SBU_LS_CTRL_1_CONF_AUTO_DET_HV_WEAK_RES_MASK    (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_PD_SBU_LS_CTRL_1_CONF_AUTO_DET_HV_WEAK_RES_POS    (4UL)


/*
 * To disable the strong drive in auto detection mode
 * 0 : strong drive is enabled
 * 1 : strong drive is disabled
 */
#define PDSS_PD_SBU_LS_CTRL_1_DIS_STRONG_DRV                (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Reverse Current Protection block control register
 */
#define PDSS_PD_40RCP_CTRL_ADDRESS(m)                       (0x400aa580UL + ((m) * (0x10000UL)))
#define PDSS_PD_40RCP_CTRL(m)                               (*(volatile uint32_t *)(0x400aa580UL + ((m) * 0x10000UL)))
#define PDSS_PD_40RCP_CTRL_DEFAULT                          (0x00080204UL)

/*
 * Output isolation control, Active Low
 * 0 - All digital outputs are forced to known value ("0")
 */
#define PDSS_PD_40RCP_CTRL_ISO_N                            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * ADFT enable
 */
#define PDSS_PD_40RCP_CTRL_ADFT_EN                          (1UL << 1) /* <1:1> R:RW:0: */


/*
 * RCP comparator enable
 * 1 : Enable
 * 0(default) : Power down
 */
#define PDSS_PD_40RCP_CTRL_RCP_PD                           (1UL << 2) /* <2:2> R:RW:1: */


/*
 * RCP comparator Hysteresis enable
 * 1 : Enabled
 * 0(default) : Disabled
 */
#define PDSS_PD_40RCP_CTRL_RCP_COMP_HYST_EN                 (1UL << 3) /* <3:3> R:RW:0: */


/*
 * To select different signals for ADFT output
 */
#define PDSS_PD_40RCP_CTRL_RCP_ADFT_CTRL_MASK               (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_PD_40RCP_CTRL_RCP_ADFT_CTRL_POS                (4UL)


/*
 * 40RCP configmode to double the trim range
 */
#define PDSS_PD_40RCP_CTRL_CONFIG_DOUBLE_TRIM               (1UL << 8) /* <8:8> R:RW:0: */


/*
 * 40RCP configmode to take the RCP comparator to fast mode
 */
#define PDSS_PD_40RCP_CTRL_CONFIG_FAST_MODE                 (1UL << 9) /* <9:9> R:RW:1: */


/*
 * 40RCP configmode to take the RCP comparator to slow mode
 */
#define PDSS_PD_40RCP_CTRL_CONFIG_SLOW_MODE                 (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 40RCP configmode to disable the output rcp_good_dig_hv
 */
#define PDSS_PD_40RCP_CTRL_CONFIG_RCP_GOOD_DISABLE          (1UL << 11) /* <11:11> R:RW:0: */


/*
 * 40RCP configmode to choose the comparator hysteresis between 5m and 10m
 */
#define PDSS_PD_40RCP_CTRL_CONFIG_HYST                      (1UL << 12) /* <12:12> R:RW:0: */


/*
 * 40RCP configmode to disable the trim arrangement
 */
#define PDSS_PD_40RCP_CTRL_CONFIG_TRIM_DISABLE              (1UL << 13) /* <13:13> R:RW:0: */


/*
 * 40RCP config spare
 */
#define PDSS_PD_40RCP_CTRL_CONFIG_SPARE_MASK                (0x0003c000UL) /* <14:17> R:RW:0: */
#define PDSS_PD_40RCP_CTRL_CONFIG_SPARE_POS                 (14UL)


/*
 * Reset pin to internal latch
 */
#define PDSS_PD_40RCP_CTRL_RCP_COMP_OUT_EN                  (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Control signal to use internal latch
 */
#define PDSS_PD_40RCP_CTRL_SEL_RCP_LATCH_PATH               (1UL << 19) /* <19:19> R:RW:1: */


/*
 * control pins to choose delay
 */
#define PDSS_PD_40RCP_CTRL_SEL_RCP_COMP_FILTER_MASK         (0x00f00000UL) /* <20:23> R:RW:0: */
#define PDSS_PD_40RCP_CTRL_SEL_RCP_COMP_FILTER_POS          (20UL)


/*
 * Control Signal to override the g1_slow_pd_en_hv signal from NGDO, which
 * would otherwise disable the internal comparator.
 * 0: Fault_Override Disabled
 * 1: Fault_Override Enabled
 */
#define PDSS_PD_40RCP_CTRL_FAULT_OVERRIDE                   (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Spare Bits Unused
 */
#define PDSS_PD_40RCP_CTRL_CONFIG_ESDPROT_MASK              (0x1e000000UL) /* <25:28> R:RW:0: */
#define PDSS_PD_40RCP_CTRL_CONFIG_ESDPROT_POS               (25UL)


/*
 * Short Circuit Protection block control register
 */
#define PDSS_PD_40SCP_CTRL_ADDRESS(m)                       (0x400aa584UL + ((m) * (0x10000UL)))
#define PDSS_PD_40SCP_CTRL(m)                               (*(volatile uint32_t *)(0x400aa584UL + ((m) * 0x10000UL)))
#define PDSS_PD_40SCP_CTRL_DEFAULT                          (0x00080004UL)

/*
 * Output isolation control, Active Low
 * 0 - All digital outputs are forced to known value ("0")
 */
#define PDSS_PD_40SCP_CTRL_ISO_N                            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * ADFT enable
 */
#define PDSS_PD_40SCP_CTRL_ADFT_EN                          (1UL << 1) /* <1:1> R:RW:0: */


/*
 * SCP comparator enable
 * 1 : Enable
 * 0(default) : Power down
 */
#define PDSS_PD_40SCP_CTRL_SCP_PD                           (1UL << 2) /* <2:2> R:RW:1: */


/*
 * SCP comparator Hysteresis enable
 * 1 : Enabled
 * 0(default) : Disabled
 */
#define PDSS_PD_40SCP_CTRL_SCP_COMP_HYST_EN                 (1UL << 3) /* <3:3> R:RW:0: */


/*
 * To select different signals for ADFT output
 */
#define PDSS_PD_40SCP_CTRL_SCP_ADFT_CTRL_MASK               (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_PD_40SCP_CTRL_SCP_ADFT_CTRL_POS                (4UL)


/*
 * 40SCP configmode to double the trim range
 */
#define PDSS_PD_40SCP_CTRL_CONFIG_DOUBLE_TRIM               (1UL << 8) /* <8:8> R:RW:0: */


/*
 * 40SCP configmode to take the SCP comparator to fast mode
 */
#define PDSS_PD_40SCP_CTRL_CONFIG_FAST_MODE                 (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 40SCP configmode to take the SCP comparator to slow mode
 */
#define PDSS_PD_40SCP_CTRL_CONFIG_SLOW_MODE                 (1UL << 10) /* <10:10> R:RW:0: */


/*
 * SCP trip point configuration bits
 */
#define PDSS_PD_40SCP_CTRL_CONFIG_SCP_VTRIP_MASK            (0x00003800UL) /* <11:13> R:RW:0: */
#define PDSS_PD_40SCP_CTRL_CONFIG_SCP_VTRIP_POS             (11UL)


/*
 * 40SCP config spares
 */
#define PDSS_PD_40SCP_CTRL_CONFIG_SPARE_MASK                (0x0003c000UL) /* <14:17> R:RW:0: */
#define PDSS_PD_40SCP_CTRL_CONFIG_SPARE_POS                 (14UL)


/*
 * reset pin to internal latch
 */
#define PDSS_PD_40SCP_CTRL_SCP_COMP_OUT_EN                  (1UL << 18) /* <18:18> R:RW:0: */


/*
 * control signal to use internal latch
 */
#define PDSS_PD_40SCP_CTRL_SEL_SCP_LATCH_PATH               (1UL << 19) /* <19:19> R:RW:1: */


/*
 * control pins to choose delay
 */
#define PDSS_PD_40SCP_CTRL_SEL_SCP_COMP_FILTER_MASK         (0x00f00000UL) /* <20:23> R:RW:0: */
#define PDSS_PD_40SCP_CTRL_SEL_SCP_COMP_FILTER_POS          (20UL)


/*
 * unused bits
 */
#define PDSS_PD_40SCP_CTRL_FAULT_OVERRIDE                   (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Voltage sense Over Current Protection block control register 0
 */
#define PDSS_PD_VSENSE_CTRL_0_ADDRESS(m)                    (0x400aa590UL + ((m) * (0x10000UL)))
#define PDSS_PD_VSENSE_CTRL_0(m)                            (*(volatile uint32_t *)(0x400aa590UL + ((m) * 0x10000UL)))
#define PDSS_PD_VSENSE_CTRL_0_DEFAULT                       (0x00000000UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_PD_VSENSE_CTRL_0_ISO_N                         (1UL << 0) /* <0:0> R:RW:0: */


/*
 * adft enable
 */
#define PDSS_PD_VSENSE_CTRL_0_ADFT_EN                       (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable bit for OCP
 */
#define PDSS_PD_VSENSE_CTRL_0_EN_OCP                        (1UL << 2) /* <2:2> R:RW:0: */


/*
 * To enable hysteresis for OCP
 */
#define PDSS_PD_VSENSE_CTRL_0_EN_OCP_HYST                   (1UL << 3) /* <3:3> R:RW:0: */


/*
 * adfta control inputs used to select different analog signal to be brought
 * out on adft<0> output
 */
#define PDSS_PD_VSENSE_CTRL_0_ADFTA_CTRL_MASK               (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_PD_VSENSE_CTRL_0_ADFTA_CTRL_POS                (4UL)


/*
 * adftb control inputs used to select different analog signal to be brought
 * out on adft<1> output
 */
#define PDSS_PD_VSENSE_CTRL_0_ADFTB_CTRL_MASK               (0x00000f00UL) /* <8:11> R:RW:0: */
#define PDSS_PD_VSENSE_CTRL_0_ADFTB_CTRL_POS                (8UL)


/*
 * Enable bit for OCP Output
 */
#define PDSS_PD_VSENSE_CTRL_0_EN_OCP_OUT_D                  (1UL << 12) /* <12:12> R:RW:0: */


/*
 * BW selection bits for OCP
 */
#define PDSS_PD_VSENSE_CTRL_0_SEL_BW_OCP_MASK               (0x00006000UL) /* <13:14> R:RW:0: */
#define PDSS_PD_VSENSE_CTRL_0_SEL_BW_OCP_POS                (13UL)


/*
 * Enable bit for ILIMIT sense current output
 */
#define PDSS_PD_VSENSE_CTRL_0_EN_ILIMT_ISENSEOUT            (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Enable bit for SCP sense current output
 */
#define PDSS_PD_VSENSE_CTRL_0_EN_SCP_ISENSEOUT              (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Latch path selection bit for OCP
 */
#define PDSS_PD_VSENSE_CTRL_0_SEL_OCP_LATCH_PATH            (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Selection bits for OCP
 */
#define PDSS_PD_VSENSE_CTRL_0_SEL_OCP_MASK                  (0x0ff00000UL) /* <20:27> R:RW:0: */
#define PDSS_PD_VSENSE_CTRL_0_SEL_OCP_POS                   (20UL)


/*
 * OCP configuration bits
 */
#define PDSS_PD_VSENSE_CTRL_0_CONFIG_OCP_MASK               (0xf0000000UL) /* <28:31> R:RW:0: */
#define PDSS_PD_VSENSE_CTRL_0_CONFIG_OCP_POS                (28UL)


/*
 * Voltage sense Over Current Protection block control register 1
 */
#define PDSS_PD_VSENSE_CTRL_1_ADDRESS(m)                    (0x400aa594UL + ((m) * (0x10000UL)))
#define PDSS_PD_VSENSE_CTRL_1(m)                            (*(volatile uint32_t *)(0x400aa594UL + ((m) * 0x10000UL)))
#define PDSS_PD_VSENSE_CTRL_1_DEFAULT                       (0x80000000UL)

/*
 * Enable bit for voltage sense reference
 */
#define PDSS_PD_VSENSE_CTRL_1_EN_REF_VSENSE                 (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Bit to increase bias current of Vsense Amplifier
 */
#define PDSS_PD_VSENSE_CTRL_1_INC_AMP_BIAS_2XI              (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Fault override bit from FW to mask fault application
 */
#define PDSS_PD_VSENSE_CTRL_1_VSENSE_FAULT_OVERRIDE         (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Enable signal for Vsense block
 */
#define PDSS_PD_VSENSE_CTRL_1_EN_VSENSE                     (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Gain selection bits for OCP
 * 2'b00: AV=0  (Powerup default)
 * 2'b01: AV=5% (Supports 1.3 to 6.5 A)
 * 2'b10: AV=10% (recommended, supports 1.3 - 3.9 A)
 * 2'b11: AV=15% (Supports 1.3A)
 */
#define PDSS_PD_VSENSE_CTRL_1_SEL_AV_OCP_MASK               (0x00000030UL) /* <4:5> R:RW:0: */
#define PDSS_PD_VSENSE_CTRL_1_SEL_AV_OCP_POS                (4UL)


/*
 * Gain selection bits for voltage sense output
 * 3'b000: AV=0 (Powerup default)
 * 3'b001: AV=5%  ( supports 1 A - 6 A)
 * 3'b010: AV=10% (recommened, supports 1A -3A)
 * 3'b011: AV=15% (Supports 1A-2A)
 * 3'b100: AV=20% (Supports 1A)
 * 3'b101: AV=25% (Supports 1A)
 * 3'b110: AV=30% (Supports 1A)
 * 3'b111: AV=35% (Supports 1A)
 */
#define PDSS_PD_VSENSE_CTRL_1_SEL_AV_VSENSE_OUT_MASK        (0x000001c0UL) /* <6:8> R:RW:0: */
#define PDSS_PD_VSENSE_CTRL_1_SEL_AV_VSENSE_OUT_POS         (6UL)


/*
 * Reference selection bit for voltage sense
 */
#define PDSS_PD_VSENSE_CTRL_1_SEL_REF_VSENSE                (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Bits to increase gain of SCP externally
 */
#define PDSS_PD_VSENSE_CTRL_1_SEL_SCP_AV_EXT                (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Bits to increase gain of OCP externally
 */
#define PDSS_PD_VSENSE_CTRL_1_SEL_OCP_AV_EXT                (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Bits to increase gain of ILIMIT externally
 */
#define PDSS_PD_VSENSE_CTRL_1_SEL_ILIMIT_AV_EXT             (1UL << 12) /* <12:12> R:RW:0: */


/*
 * BW selection bits for voltage sense output
 */
#define PDSS_PD_VSENSE_CTRL_1_SEL_BW_VSENSE_OUT_MASK        (0x000e0000UL) /* <17:19> R:RW:0: */
#define PDSS_PD_VSENSE_CTRL_1_SEL_BW_VSENSE_OUT_POS         (17UL)


/*
 * Vsense configuration bits
 */
#define PDSS_PD_VSENSE_CTRL_1_CONFIG_VSENSE_MASK            (0x1fe00000UL) /* <21:28> R:RW:0: */
#define PDSS_PD_VSENSE_CTRL_1_CONFIG_VSENSE_POS             (21UL)


/*
 * Master/global vsense block power-down signal
 */
#define PDSS_PD_VSENSE_CTRL_1_VSENSE_PD                     (1UL << 31) /* <31:31> R:RW:1: */


/*
 * Current limitor block control register
 */
#define PDSS_PD_ILIMT_CTRL_ADDRESS(m)                       (0x400aa598UL + ((m) * (0x10000UL)))
#define PDSS_PD_ILIMT_CTRL(m)                               (*(volatile uint32_t *)(0x400aa598UL + ((m) * 0x10000UL)))
#define PDSS_PD_ILIMT_CTRL_DEFAULT                          (0x00201000UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_PD_ILIMT_CTRL_ISO_N                            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * adft enable
 */
#define PDSS_PD_ILIMT_CTRL_ADFT_EN                          (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enable signal for Ilimit block
 */
#define PDSS_PD_ILIMT_CTRL_ILIMIT_EN                        (1UL << 2) /* <2:2> R:RW:0: */


/*
 * adft control inputs used to select different analog signal to be brought
 * out on adft out hv
 */
#define PDSS_PD_ILIMT_CTRL_ILIM_ADFT_CTRL_MASK              (0x00000078UL) /* <3:6> R:RW:0: */
#define PDSS_PD_ILIMT_CTRL_ILIM_ADFT_CTRL_POS               (3UL)


/*
 * Ilimit testmode input bits
 * config_ilimit<7> --> Comparator select during sort
 * config_ilimit<6:0> --> Load current configuration with a step size of
 *  65mA/32mA for config_2x_step_ctrl=0/1
 */
#define PDSS_PD_ILIMT_CTRL_CONFIG_ILIMIT_MASK               (0x0000ff00UL) /* <8:15> R:RW:16: */
#define PDSS_PD_ILIMT_CTRL_CONFIG_ILIMIT_POS                (8UL)


/*
 * Configure filter delay
 */
#define PDSS_PD_ILIMT_CTRL_CONFIG_FLT_DELAY_MASK            (0x000f0000UL) /* <16:19> R:RW:0: */
#define PDSS_PD_ILIMT_CTRL_CONFIG_FLT_DELAY_POS             (16UL)


/*
 * Config signal to double the load limit step size from 120mA (default)
 * to 240mA
 */
#define PDSS_PD_ILIMT_CTRL_CONFIG_2X_STEP_CTRL              (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Configure comparator trip point
 */
#define PDSS_PD_ILIMT_CTRL_CONFIG_COMP_TRIP_MASK            (0x00600000UL) /* <21:22> R:RW:1: */
#define PDSS_PD_ILIMT_CTRL_CONFIG_COMP_TRIP_POS             (21UL)


/*
 * Comp out hysteresis enable
 */
#define PDSS_PD_ILIMT_CTRL_HYST_EN                          (1UL << 23) /* <23:23> R:RW:0: */


/*
 * Fault override bit to mask fault application:
 * 0: Fault override Disabled
 * 1: Fault override Enabled
 */
#define PDSS_PD_ILIMT_CTRL_FAULT_OVERRIDE                   (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Temperature sensor control register
 */
#define PDSS_PD_TEMPSNS_CTRL_ADDRESS(m)                     (0x400aa59cUL + ((m) * (0x10000UL)))
#define PDSS_PD_TEMPSNS_CTRL(m)                             (*(volatile uint32_t *)(0x400aa59cUL + ((m) * 0x10000UL)))
#define PDSS_PD_TEMPSNS_CTRL_DEFAULT                        (0x00000080UL)

/*
 * adft control inputs used to select different analog signal to be brought
 * out on adft out
 */
#define PDSS_PD_TEMPSNS_CTRL_ADFT_CTRL_MASK                 (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_PD_TEMPSNS_CTRL_ADFT_CTRL_POS                  (0UL)


/*
 * programmable/configuration bits
 * 00 - gain =2
 * 01 - gain = 2.5
 * 10 - gain =3
 * 11 - gain =3.5
 */
#define PDSS_PD_TEMPSNS_CTRL_CONFIG_TEMPSNS_MASK            (0x00000078UL) /* <3:6> R:RW:0: */
#define PDSS_PD_TEMPSNS_CTRL_CONFIG_TEMPSNS_POS             (3UL)


/*
 * 1:disable option for tempsns block
 * 0: enable tempsns block
 */
#define PDSS_PD_TEMPSNS_CTRL_PD_TEMPSNS                     (1UL << 7) /* <7:7> R:RW:1: */


/*
 * config signal to turn off VBUS_C side switch in averaging resistor path
 * 1: disable VBUS_C side switch
 * 0: enable VBUS_C side switch
 */
#define PDSS_PD_TEMPSNS_CTRL_TURNOFF_CSWITCH_TEMPSNS        (1UL << 8) /* <8:8> R:RW:0: */


/*
 * input to switch reference in ILIM mode
 * 1: in ILIM mode
 * 0: in normal mode
 */
#define PDSS_PD_TEMPSNS_CTRL_EN_REPLICA_TEMPSNS             (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 1: mask fault events coming from NGDO
 * 0: allow fault signals to affect tempsns
 */
#define PDSS_PD_TEMPSNS_CTRL_FAULT_OVERRIDE                 (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Spare register 0
 */
#define PDSS_SPARE_0_ADDRESS(m)                             (0x400aa5a0UL + ((m) * (0x10000UL)))
#define PDSS_SPARE_0(m)                                     (*(volatile uint32_t *)(0x400aa5a0UL + ((m) * 0x10000UL)))
#define PDSS_SPARE_0_DEFAULT                                (0x00000000UL)

/*
 *
 *
 * Bit0: Polarity control for adc_cmp_out_gpio that is routed to GPIO
 * 0- Inverted
 * 1- Non- inverted
 *
 * Bit 7:1 - Spare
 */
#define PDSS_SPARE_0_CTRL_MASK                              (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_SPARE_0_CTRL_POS                               (0UL)


/*
 * Spare register 1
 */
#define PDSS_SPARE_1_ADDRESS(m)                             (0x400aa5a4UL + ((m) * (0x10000UL)))
#define PDSS_SPARE_1(m)                                     (*(volatile uint32_t *)(0x400aa5a4UL + ((m) * 0x10000UL)))
#define PDSS_SPARE_1_DEFAULT                                (0x00000000UL)

/*
 * Spare register
 */
#define PDSS_SPARE_1_CTRL_MASK                              (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_SPARE_1_CTRL_POS                               (0UL)


/*
 * HW SBU-DBG sequencer trigger controls-1
 */
#define PDSS_HW_SBU_CTRL_1_ADDRESS(m)                       (0x400aa5b0UL + ((m) * (0x10000UL)))
#define PDSS_HW_SBU_CTRL_1(m)                               (*(volatile uint32_t *)(0x400aa5b0UL + ((m) * 0x10000UL)))
#define PDSS_HW_SBU_CTRL_1_DEFAULT                          (0xb0041818UL)

/*
 * SBU sequencer : clipper toggle to HRES toggle delay
 */
#define PDSS_HW_SBU_CTRL_1_CLIPER_HRES_TGL_DLY_MASK         (0x0000003fUL) /* <0:5> R:RW:24: */
#define PDSS_HW_SBU_CTRL_1_CLIPER_HRES_TGL_DLY_POS          (0UL)


/*
 * SBU sequencer : HRES toggle to PUMP toggle delay
 */
#define PDSS_HW_SBU_CTRL_1_HRES_PUMP_TGL_DLY_MASK           (0x00003f00UL) /* <8:13> R:RW:24: */
#define PDSS_HW_SBU_CTRL_1_HRES_PUMP_TGL_DLY_POS            (8UL)


/*
 * SBU sequencer : PUMP_BYPASS toggle to CLIPPER toggle delay
 */
#define PDSS_HW_SBU_CTRL_1_BYPASS_EN_CLIPPER_TGL_DLY_MASK    (0x001f0000UL) /* <16:20> R:RW:4: */
#define PDSS_HW_SBU_CTRL_1_BYPASS_EN_CLIPPER_TGL_DLY_POS    (16UL)


/*
 * SBU sequencer : PUMP_BYPASS toggle to PUMP_DELAY toggle delay
 */
#define PDSS_HW_SBU_CTRL_1_BYPASS_EN_PUMP_DIS_DLY_MASK      (0x7f000000UL) /* <24:30> R:RW:48: */
#define PDSS_HW_SBU_CTRL_1_BYPASS_EN_PUMP_DIS_DLY_POS       (24UL)


/*
 * HW SBU sequencer enable
 */
#define PDSS_HW_SBU_CTRL_1_SBU_DBG_EN                       (1UL << 31) /* <31:31> R:RW:1: */


/*
 * HW SBU-DBG sequencer trigger controls-2
 */
#define PDSS_HW_SBU_CTRL_2_ADDRESS(m)                       (0x400aa5b4UL + ((m) * (0x10000UL)))
#define PDSS_HW_SBU_CTRL_2(m)                               (*(volatile uint32_t *)(0x400aa5b4UL + ((m) * 0x10000UL)))
#define PDSS_HW_SBU_CTRL_2_DEFAULT                          (0x25800960UL)

/*
 * SBU sequencer : PUMP_ENABLE toggle to PUMP_DELAY toggle delay
 */
#define PDSS_HW_SBU_CTRL_2_PUMP_EN_DEL_EN_DLY_MASK          (0x00000fffUL) /* <0:11> R:RW:2400: */
#define PDSS_HW_SBU_CTRL_2_PUMP_EN_DEL_EN_DLY_POS           (0UL)


/*
 * Duration for which the pump should be enabled before the SBU  DBG  connection
 * is stable
 */
#define PDSS_HW_SBU_CTRL_2_PUMP_STABLE_DLY_MASK             (0x3fff0000UL) /* <16:29> R:RW:9600: */
#define PDSS_HW_SBU_CTRL_2_PUMP_STABLE_DLY_POS              (16UL)


/*
 * HW SBU-DBG sequencer status signals
 */
#define PDSS_HW_SBU_STATUS_ADDRESS(m)                       (0x400aa5b8UL + ((m) * (0x10000UL)))
#define PDSS_HW_SBU_STATUS(m)                               (*(volatile uint32_t *)(0x400aa5b8UL + ((m) * 0x10000UL)))
#define PDSS_HW_SBU_STATUS_DEFAULT                          (0x0fffe100UL)

/*
 * Sbu sequencer's current FSM state
 */
#define PDSS_HW_SBU_STATUS_FSM_CURR_STATE_MASK              (0x0000000fUL) /* <0:3> RW:R:0: */
#define PDSS_HW_SBU_STATUS_FSM_CURR_STATE_POS               (0UL)


/*
 * Sequencer  PUMP BYPASS_LV state
 */
#define PDSS_HW_SBU_STATUS_PUMP_BYPASS_LV_FSM               (1UL << 8) /* <8:8> RW:R:1: */


/*
 * Sequencer CLIPPER state
 */
#define PDSS_HW_SBU_STATUS_CLIPPER_EN_FSM                   (1UL << 9) /* <9:9> RW:R:0: */


/*
 * Sequencer HRES state
 */
#define PDSS_HW_SBU_STATUS_HRES_EN_FSM                      (1UL << 10) /* <10:10> RW:R:0: */


/*
 * Sequencer PUMP ENABLE state
 */
#define PDSS_HW_SBU_STATUS_PUMP_EN_FSM                      (1UL << 11) /* <11:11> RW:R:0: */


/*
 * Sequencer PUMP DELAY state
 */
#define PDSS_HW_SBU_STATUS_PUMP_DLY_EN_FSM                  (1UL << 12) /* <12:12> RW:R:0: */


/*
 * MUX SEL between sequencer control or Firmware control for SBU debug path
 *  1 : Sequencer path
 * 0: Firmware path
 */
#define PDSS_HW_SBU_STATUS_HRES_CTRL_MUX_SEL                (1UL << 13) /* <13:13> RW:R:1: */


/*
 * Status signal - SBU Sequencer's  counter value
 */
#define PDSS_HW_SBU_STATUS_CNTR_VALUE_MASK                  (0x0fffc000UL) /* <14:27> RW:R:16383: */
#define PDSS_HW_SBU_STATUS_CNTR_VALUE_POS                   (14UL)


/*
 * INTR21 Status - Hidden register and only for debug purpose
 */
#define PDSS_INTR21_STATUS_ADDRESS(m)                       (0x400aa5bcUL + ((m) * (0x10000UL)))
#define PDSS_INTR21_STATUS(m)                               (*(volatile uint32_t *)(0x400aa5bcUL + ((m) * 0x10000UL)))
#define PDSS_INTR21_STATUS_DEFAULT                          (0x00000000UL)

/*
 * SBU debug connection established
 */
#define PDSS_INTR21_STATUS_SBU_DBG_CONNECTION               (1UL << 0) /* <0:0> RW:R:0: */


/*
 * SBU debug disconnection established
 */
#define PDSS_INTR21_STATUS_SBU_DBG_DISCONNECTION            (1UL << 1) /* <1:1> RW:R:0: */


/*
 * Marks Completion of the ADC SAR1-4 conversion at the end of 8 cycles of
 * clk_sar when SAR_EN is "1"
 */
#define PDSS_INTR21_STATUS_SAR_DONE                         (1UL << 31) /* <31:31> RW:R:0: */


/*
 * INTR21 Cause.  These are the active interrupts get reflected on interrupt_usbpd
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
#define PDSS_INTR21_ADDRESS(m)                              (0x400aa5c0UL + ((m) * (0x10000UL)))
#define PDSS_INTR21(m)                                      (*(volatile uint32_t *)(0x400aa5c0UL + ((m) * 0x10000UL)))
#define PDSS_INTR21_DEFAULT                                 (0x00000000UL)

/*
 * SBU debug connection established
 */
#define PDSS_INTR21_SBU_DBG_CONNECTION                      (1UL << 0) /* <0:0> RW1S:RW1C:0: */


/*
 * SBU debug disconnection established
 */
#define PDSS_INTR21_SBU_DBG_DISCONNECTION                   (1UL << 1) /* <1:1> RW1S:RW1C:0: */


/*
 * Marks Completion of the ADC SAR1-4 conversion at the end of 8 cycles of
 * clk_sar when SAR_EN is "1"
 */
#define PDSS_INTR21_SAR_DONE                                (1UL << 31) /* <31:31> RW1S:RW1C:0: */


/*
 * INTR21 Set
 */
#define PDSS_INTR21_SET_ADDRESS(m)                          (0x400aa5c4UL + ((m) * (0x10000UL)))
#define PDSS_INTR21_SET(m)                                  (*(volatile uint32_t *)(0x400aa5c4UL + ((m) * 0x10000UL)))
#define PDSS_INTR21_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR21_SET_SBU_DBG_CONNECTION                  (1UL << 0) /* <0:0> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR21_SET_SBU_DBG_DISCONNECTION               (1UL << 1) /* <1:1> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR21_SET_SAR_DONE                            (1UL << 31) /* <31:31> A:RW1S:0: */


/*
 * INTR21 Mask
 */
#define PDSS_INTR21_MASK_ADDRESS(m)                         (0x400aa5c8UL + ((m) * (0x10000UL)))
#define PDSS_INTR21_MASK(m)                                 (*(volatile uint32_t *)(0x400aa5c8UL + ((m) * 0x10000UL)))
#define PDSS_INTR21_MASK_DEFAULT                            (0x00000003UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR21_MASK_SBU_DBG_CONNECTION_MASK            (1UL << 0) /* <0:0> R:RW:1: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR21_MASK_SBU_DBG_DISCONNECTION_MASK         (1UL << 1) /* <1:1> R:RW:1: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR21_MASK_SAR_DONE_MASK                      (1UL << 31) /* <31:31> R:RW:0: */


/*
 * INTR21 Masked
 */
#define PDSS_INTR21_MASKED_ADDRESS(m)                       (0x400aa5ccUL + ((m) * (0x10000UL)))
#define PDSS_INTR21_MASKED(m)                               (*(volatile uint32_t *)(0x400aa5ccUL + ((m) * 0x10000UL)))
#define PDSS_INTR21_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR21_MASKED_SBU_DBG_CONNECTION_MASKED        (1UL << 0) /* <0:0> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR21_MASKED_SBU_DBG_DISCONNECTION_MASKED     (1UL << 1) /* <1:1> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR21_MASKED_SAR_DONE_MASKED                  (1UL << 31) /* <31:31> RW:R:0: */


/*
 * USBPD Hard IP C-connector Trim Register0. Production trims stored in flash
 */
#define PDSS_TRIM_CC_0_ADDRESS(m)                           (0x400aff00UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_CC_0(m)                                   (*(volatile uint32_t *)(0x400aff00UL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_CC_1_ADDRESS(m)                           (0x400aff04UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_CC_1(m)                                   (*(volatile uint32_t *)(0x400aff04UL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_CC_2_ADDRESS(m)                           (0x400aff08UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_CC_2(m)                                   (*(volatile uint32_t *)(0x400aff08UL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_CC_3_ADDRESS(m)                           (0x400aff0cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_CC_3(m)                                   (*(volatile uint32_t *)(0x400aff0cUL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_CC_4_ADDRESS(m)                           (0x400aff10UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_CC_4(m)                                   (*(volatile uint32_t *)(0x400aff10UL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_CC_5_ADDRESS(m)                           (0x400aff14UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_CC_5(m)                                   (*(volatile uint32_t *)(0x400aff14UL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_CC_6_ADDRESS(m)                           (0x400aff18UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_CC_6(m)                                   (*(volatile uint32_t *)(0x400aff18UL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_CC_7_ADDRESS(m)                           (0x400aff1cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_CC_7(m)                                   (*(volatile uint32_t *)(0x400aff1cUL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_SPARE0_ADDRESS(m)                         (0x400aff20UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SPARE0(m)                                 (*(volatile uint32_t *)(0x400aff20UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SPARE0_DEFAULT                            (0x00000000UL)

/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_TRIM_SPARE0_SPARE0_TRIM_MASK                   (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_TRIM_SPARE0_SPARE0_TRIM_POS                    (0UL)


/*
 * USBPD Hard IP 5V PUMP#1 trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_5VPUMP0_0_ADDRESS(m)                      (0x400aff24UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_5VPUMP0_0(m)                              (*(volatile uint32_t *)(0x400aff24UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_5VPUMP0_0_DEFAULT                         (0x00000041UL)

/*
 * Trim to change the comparator (used for SOA protection) hysteresis value.
 */
#define PDSS_TRIM_5VPUMP0_0_V5PUMP_PUMP_TRIM8_7_MASK        (0x00000003UL) /* <0:1> R:RW:1: */
#define PDSS_TRIM_5VPUMP0_0_V5PUMP_PUMP_TRIM8_7_POS         (0UL)


/*
 * Trim to change the oscillator frequency which is inside the charge pump.
 * Trim increases the current in oscillator cell which increases the frequency
 */
#define PDSS_TRIM_5VPUMP0_0_V5PUMP_PUMP_TRIM6_4_MASK        (0x0000001cUL) /* <2:4> R:RW:0: */
#define PDSS_TRIM_5VPUMP0_0_V5PUMP_PUMP_TRIM6_4_POS         (2UL)


/*
 * Trim to change the tail current in opamp
 */
#define PDSS_TRIM_5VPUMP0_0_V5PUMP_OPA_TRIM_MASK            (0x00000060UL) /* <5:6> R:RW:2: */
#define PDSS_TRIM_5VPUMP0_0_V5PUMP_OPA_TRIM_POS             (5UL)


/*
 * USBPD Hard IP 5V PUMP#1 trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_5VPUMP0_1_ADDRESS(m)                      (0x400aff28UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_5VPUMP0_1(m)                              (*(volatile uint32_t *)(0x400aff28UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_5VPUMP0_1_DEFAULT                         (0x00000005UL)

/*
 * Trim to change the charge pump output voltage by modifying the resistance
 * in the feed back divider
 */
#define PDSS_TRIM_5VPUMP0_1_V5PUMP_PUMP_TRIM3_0_MASK        (0x0000000fUL) /* <0:3> R:RW:5: */
#define PDSS_TRIM_5VPUMP0_1_V5PUMP_PUMP_TRIM3_0_POS         (0UL)


/*
 * USBPD Hard IP 5V PUMP#2 trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_5VPUMP1_0_ADDRESS(m)                      (0x400aff2cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_5VPUMP1_0(m)                              (*(volatile uint32_t *)(0x400aff2cUL + ((m) * 0x10000UL)))
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
 * USBPD Hard IP 5V PUMP#2 trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_5VPUMP1_1_ADDRESS(m)                      (0x400aff30UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_5VPUMP1_1(m)                              (*(volatile uint32_t *)(0x400aff30UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_5VPUMP1_1_DEFAULT                         (0x00000005UL)

/*
 * Trim to change the charge pump output voltage by modifying the resistance
 * in the feed back divider
 */
#define PDSS_TRIM_5VPUMP1_1_V5PUMP_PUMP_TRIM3_0_MASK        (0x0000000fUL) /* <0:3> R:RW:5: */
#define PDSS_TRIM_5VPUMP1_1_V5PUMP_PUMP_TRIM3_0_POS         (0UL)


/*
 * USBPD Hard IP NGDO Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_NGDO_0_ADDRESS(m)                         (0x400aff34UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_NGDO_0(m)                                 (*(volatile uint32_t *)(0x400aff34UL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_NGDO_1_ADDRESS(m)                         (0x400aff38UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_NGDO_1(m)                                 (*(volatile uint32_t *)(0x400aff38UL + ((m) * 0x10000UL)))
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
 * 30VCONN Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_30VCONN_0_ADDRESS(m)                      (0x400aff3cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_30VCONN_0(m)                              (*(volatile uint32_t *)(0x400aff3cUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_30VCONN_0_DEFAULT                         (0x000000a0UL)

/*
 * Charge pump voltage trim (engineering trim only)
 */
#define PDSS_TRIM_30VCONN_0_TRIM_PUMP_MASK                  (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_30VCONN_0_TRIM_PUMP_POS                   (0UL)


/*
 * Inrush current trim (engineering trim only)
 */
#define PDSS_TRIM_30VCONN_0_TRIM_INRUSH_MASK                (0x000000f0UL) /* <4:7> R:RW:10: */
#define PDSS_TRIM_30VCONN_0_TRIM_INRUSH_POS                 (4UL)


/*
 * 30VCONN Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_30VCONN_1_ADDRESS(m)                      (0x400aff40UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_30VCONN_1(m)                              (*(volatile uint32_t *)(0x400aff40UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_30VCONN_1_DEFAULT                         (0x00000000UL)

/*
 * Charge pump oscillator trim (engineering trim only)
 */
#define PDSS_TRIM_30VCONN_1_TRIM_OSC_MASK                   (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_TRIM_30VCONN_1_TRIM_OSC_POS                    (0UL)


/*
 * 30VCONN Trim Register 2. Production trims stored in flash
 */
#define PDSS_TRIM_30VCONN_2_ADDRESS(m)                      (0x400aff44UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_30VCONN_2(m)                              (*(volatile uint32_t *)(0x400aff44UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_30VCONN_2_DEFAULT                         (0x00000076UL)

/*
 * Over current protection trim
 */
#define PDSS_TRIM_30VCONN_2_TRIM_OCP_30VCONN_MASK           (0x000000ffUL) /* <0:7> R:RW:118: */
#define PDSS_TRIM_30VCONN_2_TRIM_OCP_30VCONN_POS            (0UL)


/*
 * SBU termination Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_SBU_TERM_0_ADDRESS(m)                     (0x400aff48UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SBU_TERM_0(m)                             (*(volatile uint32_t *)(0x400aff48UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SBU_TERM_0_DEFAULT                        (0x00000012UL)

/*
 * trims for 1Meg resistor
 */
#define PDSS_TRIM_SBU_TERM_0_TRIM_1MEG_MASK                 (0x00000007UL) /* <0:2> R:RW:2: */
#define PDSS_TRIM_SBU_TERM_0_TRIM_1MEG_POS                  (0UL)


/*
 * trims for 100K resistor
 */
#define PDSS_TRIM_SBU_TERM_0_TRIM_100K_MASK                 (0x00000038UL) /* <3:5> R:RW:2: */
#define PDSS_TRIM_SBU_TERM_0_TRIM_100K_POS                  (3UL)


/*
 * SBU termination Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_SBU_TERM_1_ADDRESS(m)                     (0x400aff4cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SBU_TERM_1(m)                             (*(volatile uint32_t *)(0x400aff4cUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SBU_TERM_1_DEFAULT                        (0x00000012UL)

/*
 * trims for 4.7M resistor
 */
#define PDSS_TRIM_SBU_TERM_1_TRIM_4P7MEG_PD_MASK            (0x00000007UL) /* <0:2> R:RW:2: */
#define PDSS_TRIM_SBU_TERM_1_TRIM_4P7MEG_PD_POS             (0UL)


/*
 * trims for 470K resistor
 */
#define PDSS_TRIM_SBU_TERM_1_TRIM_470K_PD_MASK              (0x00000038UL) /* <3:5> R:RW:2: */
#define PDSS_TRIM_SBU_TERM_1_TRIM_470K_PD_POS               (3UL)


/*
 * Reverse Current Protection Trim Register. Production trims stored in flash
 */
#define PDSS_TRIM_40RCP_ADDRESS(m)                          (0x400aff50UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_40RCP(m)                                  (*(volatile uint32_t *)(0x400aff50UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_40RCP_DEFAULT                             (0x00000025UL)

/*
 * 40RCP comparator trim bits
 */
#define PDSS_TRIM_40RCP_TRIM_RCP_COMP_MASK                  (0x000000ffUL) /* <0:7> R:RW:37: */
#define PDSS_TRIM_40RCP_TRIM_RCP_COMP_POS                   (0UL)


/*
 * Short Circuit Protection Trim Register. Production trims stored in flash
 */
#define PDSS_TRIM_40SCP_0_ADDRESS(m)                        (0x400aff54UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_40SCP_0(m)                                (*(volatile uint32_t *)(0x400aff54UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_40SCP_0_DEFAULT                           (0x00000020UL)

/*
 * SCP comparator offset trim bits
 */
#define PDSS_TRIM_40SCP_0_TRIM_SCP_COMP_MASK                (0x0000003fUL) /* <0:5> R:RW:32: */
#define PDSS_TRIM_40SCP_0_TRIM_SCP_COMP_POS                 (0UL)


/*
 * Short Circuit Protection Trim Register. Production trims stored in flash
 */
#define PDSS_TRIM_40SCP_1_ADDRESS(m)                        (0x400aff58UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_40SCP_1(m)                                (*(volatile uint32_t *)(0x400aff58UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_40SCP_1_DEFAULT                           (0x00000020UL)

/*
 * SCP trip point trim bits
 */
#define PDSS_TRIM_40SCP_1_TRIM_SCP_VTRIP_MASK               (0x0000003fUL) /* <0:5> R:RW:32: */
#define PDSS_TRIM_40SCP_1_TRIM_SCP_VTRIP_POS                (0UL)


/*
 * SCP PTAT input reference current trim
 */
#define PDSS_TRIM_40SCP_1_TRIM_IREF_0P6U_MASK               (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_TRIM_40SCP_1_TRIM_IREF_0P6U_POS                (6UL)


/*
 * Voltage Sense block Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_VSENSE_0_ADDRESS(m)                       (0x400aff5cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_VSENSE_0(m)                               (*(volatile uint32_t *)(0x400aff5cUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_VSENSE_0_DEFAULT                          (0x00000004UL)

/*
 * Trim bits for OCP
 */
#define PDSS_TRIM_VSENSE_0_TRIM_OCP_MASK                    (0x0000000fUL) /* <0:3> R:RW:4: */
#define PDSS_TRIM_VSENSE_0_TRIM_OCP_POS                     (0UL)


/*
 * Voltage Sense block Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_VSENSE_1_ADDRESS(m)                       (0x400aff60UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_VSENSE_1(m)                               (*(volatile uint32_t *)(0x400aff60UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_VSENSE_1_DEFAULT                          (0x00000010UL)

/*
 * Trim bits for voltage sense reference
 */
#define PDSS_TRIM_VSENSE_1_TRIM_REF_VSENSE_IREF_MASK        (0x0000003fUL) /* <0:5> R:RW:16: */
#define PDSS_TRIM_VSENSE_1_TRIM_REF_VSENSE_IREF_POS         (0UL)


/*
 * Voltage Sense block Trim Register 2. Production trims stored in flash
 */
#define PDSS_TRIM_VSENSE_2_ADDRESS(m)                       (0x400aff64UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_VSENSE_2(m)                               (*(volatile uint32_t *)(0x400aff64UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_VSENSE_2_DEFAULT                          (0x00000007UL)

/*
 * Trim bits for voltage sense reference resistance
 */
#define PDSS_TRIM_VSENSE_2_TRIM_REF_VSENSE_RES_MASK         (0x0000003fUL) /* <0:5> R:RW:7: */
#define PDSS_TRIM_VSENSE_2_TRIM_REF_VSENSE_RES_POS          (0UL)


/*
 * Voltage Sense block Trim Register 3. Production trims stored in flash
 */
#define PDSS_TRIM_VSENSE_3_ADDRESS(m)                       (0x400aff68UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_VSENSE_3(m)                               (*(volatile uint32_t *)(0x400aff68UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_VSENSE_3_DEFAULT                          (0x00000010UL)

/*
 * Rladder top gain adjustment bits vs FET KILIS process variation
 */
#define PDSS_TRIM_VSENSE_3_TRIM_RLADDER_MASK                (0x000000ffUL) /* <0:7> R:RW:16: */
#define PDSS_TRIM_VSENSE_3_TRIM_RLADDER_POS                 (0UL)


/*
 * Voltage Sense block Trim Register 4. Production trims stored in flash
 */
#define PDSS_TRIM_VSENSE_4_ADDRESS(m)                       (0x400aff6cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_VSENSE_4(m)                               (*(volatile uint32_t *)(0x400aff6cUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_VSENSE_4_DEFAULT                          (0x00000040UL)

/*
 * Amplifier input offset cancellation bits
 */
#define PDSS_TRIM_VSENSE_4_TRIM_VIOS_MASK                   (0x000000ffUL) /* <0:7> R:RW:64: */
#define PDSS_TRIM_VSENSE_4_TRIM_VIOS_POS                    (0UL)


/*
 * Current Limitor Trim Register. Production trims stored in flash
 */
#define PDSS_TRIM_ILIMT_ADDRESS(m)                          (0x400aff70UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_ILIMT(m)                                  (*(volatile uint32_t *)(0x400aff70UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_ILIMT_DEFAULT                             (0x00000060UL)

/*
 * Ilimit trim bits
 *  trim_ilimit<7>  --> 1/0: Enable/disable low gm path for stability
 * trim_ilimit<6>  --> 1/0: Enable/disable gate1 parallel comp out path for
 * better noise performance
 * trim_ilimit<5:0> -->  6b'100000 :Load current trimming with a step size
 * of 6mA/18mA for 1A/3A load limit
 */
#define PDSS_TRIM_ILIMT_TRIM_ILIMIT_MASK                    (0x000000ffUL) /* <0:7> R:RW:96: */
#define PDSS_TRIM_ILIMT_TRIM_ILIMIT_POS                     (0UL)


/*
 * Reference Generator Trim Register. Production trims stored in flash
 */
#define PDSS_TRIM_REF_GEN_ADDRESS(m)                        (0x400aff74UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_REF_GEN(m)                                (*(volatile uint32_t *)(0x400aff74UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_REF_GEN_DEFAULT                           (0x00000007UL)

/*
 * Trimming for Vref2p2
 * 0000 - 0110 : -6mV / step
 * 1000 - 1111 : +6mV / step
 */
#define PDSS_TRIM_REF_GEN_TRIM_VREF_MASK                    (0x0000000fUL) /* <0:3> R:RW:7: */
#define PDSS_TRIM_REF_GEN_TRIM_VREF_POS                     (0UL)


/*
 * SBU Lever Shifter Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_SBU_LS_0_ADDRESS(m)                       (0x400aff78UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SBU_LS_0(m)                               (*(volatile uint32_t *)(0x400aff78UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SBU_LS_0_DEFAULT                          (0x00000024UL)

/*
 * trim bits to maintain the accuracy of 1meg resistor on lsrx pull down
 * path
 */
#define PDSS_TRIM_SBU_LS_0_TRIM_LSRX_PDRES_1MEG_MASK        (0x00000007UL) /* <0:2> R:RW:4: */
#define PDSS_TRIM_SBU_LS_0_TRIM_LSRX_PDRES_1MEG_POS         (0UL)


/*
 * trim bits to maintain the 10K resistor on lsTx pull UP path
 */
#define PDSS_TRIM_SBU_LS_0_TRIM_LSTX_PURES_10K_MASK         (0x00000038UL) /* <3:5> R:RW:4: */
#define PDSS_TRIM_SBU_LS_0_TRIM_LSTX_PURES_10K_POS          (3UL)


/*
 * SBU Lever Shifter Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_SBU_LS_1_ADDRESS(m)                       (0x400aff7cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SBU_LS_1(m)                               (*(volatile uint32_t *)(0x400aff7cUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SBU_LS_1_DEFAULT                          (0x00000004UL)

/*
 * Trims for trimming the 50 ohm impedance for LV TX in LSTX
 */
#define PDSS_TRIM_SBU_LS_1_TRIM_LSTX_RES_MASK               (0x00000007UL) /* <0:2> R:RW:4: */
#define PDSS_TRIM_SBU_LS_1_TRIM_LSTX_RES_POS                (0UL)


/*
 * SBU Lever Shifter Trim Register 2. Production trims stored in flash
 */
#define PDSS_TRIM_SBU_LS_2_ADDRESS(m)                       (0x400aff80UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SBU_LS_2(m)                               (*(volatile uint32_t *)(0x400aff80UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SBU_LS_2_DEFAULT                          (0x00000004UL)

/*
 * Trims for trimming the 50 ohm impedance for LV TX in LSRX
 */
#define PDSS_TRIM_SBU_LS_2_TRIM_LSRX_RES_MASK               (0x00000007UL) /* <0:2> R:RW:4: */
#define PDSS_TRIM_SBU_LS_2_TRIM_LSRX_RES_POS                (0UL)


/*
 * SBU Lever Shifter Trim Register 3. Production trims stored in flash
 */
#define PDSS_TRIM_SBU_LS_3_ADDRESS(m)                       (0x400aff84UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SBU_LS_3(m)                               (*(volatile uint32_t *)(0x400aff84UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SBU_LS_3_DEFAULT                          (0x00000004UL)

/*
 * Trims for trimming the 50 ohm impedance for HV TX in SBU1
 */
#define PDSS_TRIM_SBU_LS_3_TRIM_SBU1_RES_MASK               (0x00000007UL) /* <0:2> R:RW:4: */
#define PDSS_TRIM_SBU_LS_3_TRIM_SBU1_RES_POS                (0UL)


/*
 * SBU Lever Shifter Trim Register 4. Production trims stored in flash
 */
#define PDSS_TRIM_SBU_LS_4_ADDRESS(m)                       (0x400aff88UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SBU_LS_4(m)                               (*(volatile uint32_t *)(0x400aff88UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SBU_LS_4_DEFAULT                          (0x00000004UL)

/*
 * Trims for trimming the 50 ohm impedance  for HV TX in SBU2
 */
#define PDSS_TRIM_SBU_LS_4_TRIM_SBU2_RES_MASK               (0x00000007UL) /* <0:2> R:RW:4: */
#define PDSS_TRIM_SBU_LS_4_TRIM_SBU2_RES_POS                (0UL)


/*
 * Temperature Sensor Trim Register. Production trims stored in flash
 */
#define PDSS_TRIM_TEMPSNS_ADDRESS(m)                        (0x400aff8cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_TEMPSNS(m)                                (*(volatile uint32_t *)(0x400aff8cUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_TEMPSNS_DEFAULT                           (0x00000000UL)

/*
 * trim bits for tempsns block
 */
#define PDSS_TRIM_TEMPSNS_TRIM_TEMPSNS_MASK                 (0x0000001fUL) /* <0:4> R:RW:0: */
#define PDSS_TRIM_TEMPSNS_TRIM_TEMPSNS_POS                  (0UL)


/*
 * Bangap Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_BG_0_ADDRESS(m)                           (0x400aff94UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BG_0(m)                                   (*(volatile uint32_t *)(0x400aff94UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BG_0_DEFAULT                              (0x0000003fUL)

/*
 * Output reference current Tempco trimming
 */
#define PDSS_TRIM_BG_0_TRIM_ICTAT_MASK                      (0x0000007fUL) /* <0:6> R:RW:63: */
#define PDSS_TRIM_BG_0_TRIM_ICTAT_POS                       (0UL)


/*
 * Bangap Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_BG_1_ADDRESS(m)                           (0x400aff98UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BG_1(m)                                   (*(volatile uint32_t *)(0x400aff98UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BG_1_DEFAULT                              (0x0000003bUL)

/*
 * Output reference current Tempco trimming
 */
#define PDSS_TRIM_BG_1_TRIM_ICTAT2_MASK                     (0x00000007UL) /* <0:2> R:RW:3: */
#define PDSS_TRIM_BG_1_TRIM_ICTAT2_POS                      (0UL)


/*
 * Output reference current offset trimming
 */
#define PDSS_TRIM_BG_1_TRIM_IREF2_MASK                      (0x00000078UL) /* <3:6> R:RW:7: */
#define PDSS_TRIM_BG_1_TRIM_IREF2_POS                       (3UL)


/*
 * Bangap Trim Register 2. Production trims stored in flash
 */
#define PDSS_TRIM_BG_2_ADDRESS(m)                           (0x400aff9cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BG_2(m)                                   (*(volatile uint32_t *)(0x400aff9cUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BG_2_DEFAULT                              (0x0000001fUL)

/*
 * Output reference current Tempco trimming
 */
#define PDSS_TRIM_BG_2_TRIM_IPTAT_MASK                      (0x0000003fUL) /* <0:5> R:RW:31: */
#define PDSS_TRIM_BG_2_TRIM_IPTAT_POS                       (0UL)


/*
 * Bangap Trim Register 3. Production trims stored in flash
 */
#define PDSS_TRIM_BG_3_ADDRESS(m)                           (0x400affa0UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BG_3(m)                                   (*(volatile uint32_t *)(0x400affa0UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BG_3_DEFAULT                              (0x0000001fUL)

/*
 * Output reference current offset trimming
 */
#define PDSS_TRIM_BG_3_BG_TRIM_IREF_MASK                    (0x0000003fUL) /* <0:5> R:RW:31: */
#define PDSS_TRIM_BG_3_BG_TRIM_IREF_POS                     (0UL)


/*
 * Bangap Trim Register 4. Production trims stored in flash
 */
#define PDSS_TRIM_BG_4_ADDRESS(m)                           (0x400affa4UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BG_4(m)                                   (*(volatile uint32_t *)(0x400affa4UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BG_4_DEFAULT                              (0x0000000fUL)

/*
 * Output reference voltage Tempco trimming
 */
#define PDSS_TRIM_BG_4_TRIM_BG_TC_MASK                      (0x0000001fUL) /* <0:4> R:RW:15: */
#define PDSS_TRIM_BG_4_TRIM_BG_TC_POS                       (0UL)


/*
 * Bangap Trim Register 5. Production trims stored in flash
 */
#define PDSS_TRIM_BG_5_ADDRESS(m)                           (0x400affa8UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BG_5(m)                                   (*(volatile uint32_t *)(0x400affa8UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BG_5_DEFAULT                              (0x0000000fUL)

/*
 * Output reference voltage offset trimming
 */
#define PDSS_TRIM_BG_5_TRIM_BG_OS_MASK                      (0x0000001fUL) /* <0:4> R:RW:15: */
#define PDSS_TRIM_BG_5_TRIM_BG_OS_POS                       (0UL)


/*
 * Bangap Trim Register 6. Production trims stored in flash
 */
#define PDSS_TRIM_BG_6_ADDRESS(m)                           (0x400affacUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BG_6(m)                                   (*(volatile uint32_t *)(0x400affacUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BG_6_DEFAULT                              (0x0000000fUL)

/*
 * Output reference voltage offset trimming
 */
#define PDSS_TRIM_BG_6_TRIM_BG_OS2_MASK                     (0x0000001fUL) /* <0:4> R:RW:15: */
#define PDSS_TRIM_BG_6_TRIM_BG_OS2_POS                      (0UL)


/*
 * Regulator Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_REG_0_ADDRESS(m)                          (0x400affb0UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_REG_0(m)                                  (*(volatile uint32_t *)(0x400affb0UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_REG_0_DEFAULT                             (0x00000083UL)

/*
 * 3.3V output trimming
 * 000 - 111 : 50mV / step, Range: 3150 to 3500mV
 */
#define PDSS_TRIM_REG_0_TRIM_VREG_REG0_MASK                 (0x00000007UL) /* <0:2> R:RW:3: */
#define PDSS_TRIM_REG_0_TRIM_VREG_REG0_POS                  (0UL)


/*
 * Vddd to vgnd short current trimming (66Ohm to vgnd)
 * inrush_det_sel<1:0>=00, (mA) 0001: 7, 0010: 14, 0011: 20, 0100: 27, 0101:
 * 33, 0110: 39, 0111: 43, 1000: 47, 1001: 50
 *
 * inrush_det_sel<1:0>=10, (mA) 0001: 33, 0010: 64, 0011: 94, 0100: 125,
 * 0101: 155, 0110: 184, 0111: 211, 1000: 237, 1001: 264, 1010: 289, 1011:
 * 311, 1100: 331, 1101: 424
 */
#define PDSS_TRIM_REG_0_TRIM_INRSH_MASK                     (0x000000f0UL) /* <4:7> R:RW:8: */
#define PDSS_TRIM_REG_0_TRIM_INRSH_POS                      (4UL)


/*
 * Regulator Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_REG_1_ADDRESS(m)                          (0x400affb4UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_REG_1(m)                                  (*(volatile uint32_t *)(0x400affb4UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_REG_1_DEFAULT                             (0x00000008UL)

/*
 * Chargepump output trimming
 * 0000 - 1100 : 300mV / step, Range: 4.08 to 8.10V
 */
#define PDSS_TRIM_REG_1_TRIM_VCP_MASK                       (0x0000000fUL) /* <0:3> R:RW:8: */
#define PDSS_TRIM_REG_1_TRIM_VCP_POS                        (0UL)


/*
 * Crude current reference trimming (%)
 * 000: +0
 * 001: +12.5
 * 010: +25
 * 011: +37.5
 *
 * 100: -12.5
 * 101: -25
 * 110: -37.5
 * 111: -50
 */
#define PDSS_TRIM_REG_1_TRIM_IREF_MASK                      (0x00000070UL) /* <4:6> R:RW:0: */
#define PDSS_TRIM_REG_1_TRIM_IREF_POS                       (4UL)


/*
 * Regulator Trim Register 2. Production trims stored in flash
 */
#define PDSS_TRIM_REG_2_ADDRESS(m)                          (0x400affb8UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_REG_2(m)                                  (*(volatile uint32_t *)(0x400affb8UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_REG_2_DEFAULT                             (0x00000000UL)

/*
 * Crude voltage reference trimming
 * (mV) 0001: -6, 0010: +10, 0011: +5, 0100: -38, 0101: -62, 0110: -14, 0111:
 * -24, 1000: +41,
 * 1001: +27, 1010: +82, 1011: +57, 1100: +18, 1101: +14, 1110: +24, 1111:
 * +21
 */
#define PDSS_TRIM_REG_2_TRIM_VREF_REG4_MASK                 (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_REG_2_TRIM_VREF_REG4_POS                  (0UL)


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
#define ROMTABLE_PID2_JEPID_MAJ_MASK                        (0x0000000fUL) /* <0:3> R:R:Undefined: */
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

#endif /* _13525_REG_TOP_H_ */

