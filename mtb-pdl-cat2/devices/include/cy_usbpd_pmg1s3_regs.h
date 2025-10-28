/***************************************************************************//**
* \file cy_usbpd_pmg1s3_regs.h
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
#ifndef _CY_USBPD_PMG1S3_REGS_H_
#define _CY_USBPD_PMG1S3_REGS_H_

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
    volatile uint32_t rsrvd2;
    volatile uint32_t afc_1_ctrl;                         /* 0x400a0140UL */
    volatile uint32_t rsrvd3[3];
    volatile uint32_t afc_2_ctrl;                         /* 0x400a0150UL */
    volatile uint32_t rsrvd4[3];
    volatile uint32_t afc_opcode_ctrl;                    /* 0x400a0160UL */
    volatile uint32_t rsrvd5[3];
    volatile uint32_t afc_ping_pong;                      /* 0x400a0170UL */
    volatile uint32_t rsrvd6[3];
    volatile uint32_t qc3_chrger_ctrl;                    /* 0x400a0180UL */
    volatile uint32_t rsrvd7[3];
    volatile uint32_t qc3_device_ctrl;                    /* 0x400a0190UL */
    volatile uint32_t rsrvd8[3];
    volatile uint32_t afc_sm_status;                      /* 0x400a01a0UL */
    volatile uint32_t rsrvd9[3];
    volatile uint32_t afc_hs_filter_cfg;                  /* 0x400a01b0UL */
    volatile uint32_t rsrvd10[3];
    volatile uint32_t adc_sar_ctrl;                       /* 0x400a01c0UL */
    volatile uint32_t rsrvd11[7];
    volatile uint32_t refgen_sel6_sel8_ctrl;              /* 0x400a01e0UL */
    volatile uint32_t rsrvd12[19];
    volatile uint32_t vconn20_cc1_switch_1_ctrl;          /* 0x400a0230UL */
    volatile uint32_t vconn20_cc1_switch_2_ctrl;          /* 0x400a0234UL */
    volatile uint32_t vconn20_cc2_switch_1_ctrl;          /* 0x400a0238UL */
    volatile uint32_t vconn20_cc2_switch_2_ctrl;          /* 0x400a023cUL */
    volatile uint32_t vconn20_pump_en_1_ctrl;             /* 0x400a0240UL */
    volatile uint32_t vconn20_pump_en_2_ctrl;             /* 0x400a0244UL */
    volatile uint32_t rsrvd13[22];
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
    volatile uint32_t rsrvd14[14];
    volatile uint32_t intr3_cfg_vsys;                     /* 0x400a0300UL */
    volatile uint32_t intr3_cfg_adc_hs;                   /* 0x400a0304UL */
    volatile uint32_t rsrvd15[12];
    volatile uint32_t intr3_cfg_vreg20_vbus;              /* 0x400a0338UL */
    volatile uint32_t rsrvd16;
    volatile uint32_t intr3_status_0;                     /* 0x400a0340UL */
    volatile uint32_t intr3_status_1;                     /* 0x400a0344UL */
    volatile uint32_t intr3;                              /* 0x400a0348UL */
    volatile uint32_t intr3_set;                          /* 0x400a034cUL */
    volatile uint32_t intr3_mask;                         /* 0x400a0350UL */
    volatile uint32_t intr3_masked;                       /* 0x400a0354UL */
    volatile uint32_t rsrvd17[10];
    volatile uint32_t intr5_filter_cfg[2];                /* 0x400a0380UL */
    volatile uint32_t rsrvd18[22];
    volatile uint32_t intr5_status_0;                     /* 0x400a03e0UL */
    volatile uint32_t rsrvd19;
    volatile uint32_t intr5;                              /* 0x400a03e8UL */
    volatile uint32_t intr5_set;                          /* 0x400a03ecUL */
    volatile uint32_t intr5_mask;                         /* 0x400a03f0UL */
    volatile uint32_t intr5_masked;                       /* 0x400a03f4UL */
    volatile uint32_t rsrvd20[10];
    volatile uint32_t intr7_filter_cfg[3];                /* 0x400a0420UL */
    volatile uint32_t rsrvd21[5];
    volatile uint32_t intr7_status;                       /* 0x400a0440UL */
    volatile uint32_t intr7;                              /* 0x400a0444UL */
    volatile uint32_t intr7_set;                          /* 0x400a0448UL */
    volatile uint32_t intr7_mask;                         /* 0x400a044cUL */
    volatile uint32_t intr7_masked;                       /* 0x400a0450UL */
    volatile uint32_t rsrvd22[7];
    volatile uint32_t intr9_cfg_bch_det[1];               /* 0x400a0470UL */
    volatile uint32_t rsrvd23[6];
    volatile uint32_t intr9_status_0;                     /* 0x400a048cUL */
    volatile uint32_t intr9_status_1;                     /* 0x400a0490UL */
    volatile uint32_t intr9;                              /* 0x400a0494UL */
    volatile uint32_t intr9_set;                          /* 0x400a0498UL */
    volatile uint32_t intr9_mask;                         /* 0x400a049cUL */
    volatile uint32_t intr9_masked;                       /* 0x400a04a0UL */
    volatile uint32_t rsrvd24[7];
    volatile uint32_t intr11_filter_cfg;                  /* 0x400a04c0UL */
    volatile uint32_t intr11_status_0;                    /* 0x400a04c4UL */
    volatile uint32_t intr11;                             /* 0x400a04c8UL */
    volatile uint32_t intr11_set;                         /* 0x400a04ccUL */
    volatile uint32_t intr11_mask;                        /* 0x400a04d0UL */
    volatile uint32_t intr11_masked;                      /* 0x400a04d4UL */
    volatile uint32_t rsrvd25;
    volatile uint32_t intr13_status;                      /* 0x400a04dcUL */
    volatile uint32_t intr13;                             /* 0x400a04e0UL */
    volatile uint32_t intr13_set;                         /* 0x400a04e4UL */
    volatile uint32_t intr13_mask;                        /* 0x400a04e8UL */
    volatile uint32_t intr13_masked;                      /* 0x400a04ecUL */
    volatile uint32_t intr13_cfg_csa_scp_hs;              /* 0x400a04f0UL */
    volatile uint32_t intr13_cfg_csa_rcp_hs;              /* 0x400a04f4UL */
    volatile uint32_t intr13_cfg_csa_rcp_ovp_hs;          /* 0x400a04f8UL */
    volatile uint32_t rsrvd26;
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
    volatile uint32_t rsrvd27[16];
    volatile uint32_t ddft_mux;                           /* 0x400a0580UL */
    volatile uint32_t intr_ddft_mux;                      /* 0x400a0584UL */
    volatile uint32_t ncell_ddft_mux;                     /* 0x400a0588UL */
    volatile uint32_t gpio_ddft_mux;                      /* 0x400a058cUL */
    volatile uint32_t gpio_intr_ddft_mux;                 /* 0x400a0590UL */
    volatile uint32_t rsrvd28;
    volatile uint32_t fault_gpio_ctrl_extr;               /* 0x400a0598UL */
    volatile uint32_t rsrvd29[25];
    volatile uint32_t cc_ctrl_0;                          /* 0x400a0600UL */
    volatile uint32_t cc_ctrl_1;                          /* 0x400a0604UL */
    volatile uint32_t dpslp_ref_ctrl;                     /* 0x400a0608UL */
    volatile uint32_t rsrvd30[3];
    volatile uint32_t vsys_ctrl;                          /* 0x400a0618UL */
    volatile uint32_t vreg_vsys_ctrl;                     /* 0x400a061cUL */
    volatile uint32_t rsrvd31[3];
    volatile uint32_t amux_nhv_ctrl;                      /* 0x400a062cUL */
    volatile uint32_t amux_denfet_ctrl;                   /* 0x400a0630UL */
    volatile uint32_t rsrvd32[11];
    volatile uint32_t vreg_ctrl;                          /* 0x400a0660UL */
    volatile uint32_t rsrvd33[3];
    volatile uint32_t sbu_ctrl;                           /* 0x400a0670UL */
    volatile uint32_t rsrvd34[3];
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
    volatile uint32_t dischg_shv_ctrl;                    /* 0x400a0790UL */
    volatile uint32_t rsrvd43[15];
    volatile uint32_t comp_ctrl[5];                       /* 0x400a07d0UL */
    volatile uint32_t rsrvd44[32];
    volatile uint32_t reg_control;                        /* 0x400a0864UL */
    volatile uint32_t vconn20_ctrl;                       /* 0x400a0868UL */
    volatile uint32_t pump5v_ctrl[2];                     /* 0x400a086cUL */
    volatile uint32_t rsrvd45[18];
    volatile uint32_t csa_scp_0_ctrl;                     /* 0x400a08bcUL */
    volatile uint32_t csa_scp_1_ctrl;                     /* 0x400a08c0UL */
    volatile uint32_t csa_rcp_0_ctrl;                     /* 0x400a08c4UL */
    volatile uint32_t csa_rcp_1_ctrl;                     /* 0x400a08c8UL */
    volatile uint32_t rsrvd46[1535];
    volatile uint32_t v2_ngdo_0_ctrl;                     /* 0x400a20c8UL */
    volatile uint32_t v2_ngdo_1_ctrl;                     /* 0x400a20ccUL */
    volatile uint32_t rsrvd47[270];
    volatile uint32_t scp_rcp_0_ctrl;                     /* 0x400a2508UL */
    volatile uint32_t scp_rcp_1_ctrl;                     /* 0x400a250cUL */
    volatile uint32_t fmx_ctrl;                           /* 0x400a2510UL */
    volatile uint32_t rsrvd48[2];
    volatile uint32_t rambist_mux_ctrl;                   /* 0x400a251cUL */
    volatile uint32_t sbu_new_ctrl[2];                    /* 0x400a2520UL */
    volatile uint32_t rsrvd49[2];
    volatile uint32_t refgen_cal;                         /* 0x400a2530UL */
    volatile uint32_t vconn_cal;                          /* 0x400a2534UL */
    volatile uint32_t ngdo_cal;                           /* 0x400a2538UL */
    volatile uint32_t rsrvd50;
    volatile uint32_t scp_rcp_cal;                        /* 0x400a2540UL */
    volatile uint32_t pmg1_ncell_ddft_mux;                /* 0x400a2544UL */
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
    volatile uint32_t trim_5vpump0_0;                     /* 0x400aff20UL */
    volatile uint32_t trim_5vpump0_1;                     /* 0x400aff24UL */
    volatile uint32_t trim_5vpump1_0;                     /* 0x400aff28UL */
    volatile uint32_t trim_5vpump1_1;                     /* 0x400aff2cUL */
    volatile uint32_t trim_dpslp_0;                       /* 0x400aff30UL */
    volatile uint32_t trim_dpslp_1;                       /* 0x400aff34UL */
    volatile uint32_t trim_refgen;                        /* 0x400aff38UL */
    volatile uint32_t trim_ngdo;                          /* 0x400aff3cUL */
    volatile uint32_t trim_vconn;                         /* 0x400aff40UL */
    volatile uint32_t trim_scp_rcp_0;                     /* 0x400aff44UL */
    volatile uint32_t trim_scp_rcp_1;                     /* 0x400aff48UL */
    volatile uint32_t trim_scp_rcp_2;                     /* 0x400aff4cUL */
    volatile uint32_t trim_sbu_sw_0;                      /* 0x400aff50UL */
    volatile uint32_t trim_sbu_sw_1;                      /* 0x400aff54UL */
    volatile uint32_t trim_vreg28_0;                      /* 0x400aff58UL */
    volatile uint32_t trim_vreg28_1;                      /* 0x400aff5cUL */
    volatile uint32_t trim_bch_det_0;                     /* 0x400aff60UL */
    volatile uint32_t trim_bch_det_1;                     /* 0x400aff64UL */
    volatile uint32_t trim_bch_det_2;                     /* 0x400aff68UL */
    volatile uint32_t trim_bch_det_3;                     /* 0x400aff6cUL */
    volatile uint32_t trim_bch_det_4;                     /* 0x400aff70UL */
} PDSS_TRIMS_REGS_T, *PPDSS_TRIMS_REGS_T;

#define PDSS_TRIMS0       ((PPDSS_TRIMS_REGS_T) PDSS_TRIMS0_BASE_ADDR)
#define PDSS_TRIMS1       ((PPDSS_TRIMS_REGS_T) PDSS_TRIMS1_BASE_ADDR)

/*
 * NOTE:
 * There are multiple instances of the above register section.
 * The following structure pointer array needs to be defined in
 * a source file before using it.
 * const PPDSS_TRIMS_REGS_T PDSS_TRIMS[2] = {PDSS_TRIMS0, PDSS_TRIMS1};
 */
extern const PPDSS_TRIMS_REGS_T PDSS_TRIMS[];

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
 * CCG3PA:
 * 0: Source is cmp_out of ADC1
 * 1: Source is cmp_out of ADC2
 * 2: VBUS_MON
 * 3: VSRC_NEW_P
 * 4: VSRC_NEW_M
 * 5: UV
 * 6: OV
 * 7: DISCHG
 * 8: SCP
 * 9: OCP
 * 10: SCP
 * 11: SR
 *
 * CCG5, Port0:
 * 0: Source is cmp_out of ADC1
 * 1: Source is cmp_out of ADC2
 * 2: VBUS_MON
 * 3: VSYS_DET
 * 4: 1'b0
 * 5: UV
 * 6: OV
 * 7: 1'b0
 * 8: 1'b0
 * 9:  CSA-OCP
 * 10: 1'b0
 * 11: 1'b0
 *
 * CCG5, Port1:
 * 0: Source is cmp_out of ADC1
 * 1: Source is cmp_out of ADC2
 * 2: VBUS_MON
 * 3: 1'b0
 * 4: 1'b0
 * 5: UV
 * 6: OV
 * 7: 1'b0
 * 8: 1'b0
 * 9:  CSA-OCP
 * 10: 1'b0
 * 11: 1'b0
 *
 * CCG6:
 * 0: Source is cmp_out of ADC1
 * 1: 0
 * 2: VBUS_MON
 * 3: VSYS_DET
 * 4: 1'b0
 * 5: UV
 * 6: OV
 * 7: 1'b0
 * 8: 1'b0
 * 9:  CSA-OCP
 * 10: CSA-SCP
 * 11: CSA_OUT
 * 12: CSA_COMP_OUT
 * 13: CSA_VBUS_OVP
 *
 * CCG6DF Port0:
 * 0: Source is cmp_out of ADC1
 * 1: 0
 * 2: 0
 * 3: VSYS_DET
 * 4: 0
 * 5: UV
 * 6: OV
 * 7: 0
 * 8: 0
 * 9:  CSA_OCP
 * 10: CSA_SCP
 * 11: CSA_OUT
 * 12: CSA_COMP_OUT
 * 13: CSA_VBUS_OVP
 * 14: 0
 * 15: 0
 *
 * CCG6DF Port1:
 * 0: Source is cmp_out of ADC1
 * 1: 0
 * 2: 0
 * 3: 0
 * 4: 0
 * 5: UV
 * 6: OV
 * 7: 0
 * 8: 0
 * 9:  CSA_OCP
 * 10: CSA_SCP
 * 11: CSA_OUT
 * 12: CSA_COMP_OUT
 * 13: CSA_VBUS_OVP
 * 14: 0
 * 15: 0
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
 * AFC Charger Detect control 1 for logic
 */
#define PDSS_AFC_1_CTRL_ADDRESS(m)                          (0x400a0140UL + ((m) * (0x10000UL)))
#define PDSS_AFC_1_CTRL(m)                                  (*(volatile uint32_t *)(0x400a0140UL + ((m) * 0x10000UL)))
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
#define PDSS_AFC_2_CTRL_ADDRESS(m)                          (0x400a0150UL + ((m) * (0x10000UL)))
#define PDSS_AFC_2_CTRL(m)                                  (*(volatile uint32_t *)(0x400a0150UL + ((m) * 0x10000UL)))
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
#define PDSS_AFC_OPCODE_CTRL_ADDRESS(m)                     (0x400a0160UL + ((m) * (0x10000UL)))
#define PDSS_AFC_OPCODE_CTRL(m)                             (*(volatile uint32_t *)(0x400a0160UL + ((m) * 0x10000UL)))
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
#define PDSS_AFC_PING_PONG_ADDRESS(m)                       (0x400a0170UL + ((m) * (0x10000UL)))
#define PDSS_AFC_PING_PONG(m)                               (*(volatile uint32_t *)(0x400a0170UL + ((m) * 0x10000UL)))
#define PDSS_AFC_PING_PONG_DEFAULT                          (0x00000000UL)

/*
 * AFC TX/RX Data
 */
#define PDSS_AFC_PING_PONG_AFC_DATA_MASK                    (0x0000ffffUL) /* <0:15> RW:RW:0: */
#define PDSS_AFC_PING_PONG_AFC_DATA_POS                     (0UL)


/*
 * Slave ( Dedicated Charger) Control Registers for QC3.0
 */
#define PDSS_QC3_CHRGER_CTRL_ADDRESS(m)                     (0x400a0180UL + ((m) * (0x10000UL)))
#define PDSS_QC3_CHRGER_CTRL(m)                             (*(volatile uint32_t *)(0x400a0180UL + ((m) * 0x10000UL)))
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
#define PDSS_QC3_DEVICE_CTRL_ADDRESS(m)                     (0x400a0190UL + ((m) * (0x10000UL)))
#define PDSS_QC3_DEVICE_CTRL(m)                             (*(volatile uint32_t *)(0x400a0190UL + ((m) * 0x10000UL)))
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
#define PDSS_AFC_SM_STATUS_ADDRESS(m)                       (0x400a01a0UL + ((m) * (0x10000UL)))
#define PDSS_AFC_SM_STATUS(m)                               (*(volatile uint32_t *)(0x400a01a0UL + ((m) * 0x10000UL)))
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
#define PDSS_AFC_HS_FILTER_CFG_ADDRESS(m)                   (0x400a01b0UL + ((m) * (0x10000UL)))
#define PDSS_AFC_HS_FILTER_CFG(m)                           (*(volatile uint32_t *)(0x400a01b0UL + ((m) * 0x10000UL)))
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
#define PDSS_ADC_SAR_CTRL_ADDRESS(m)                        (0x400a01c0UL + ((m) * (0x10000UL)))
#define PDSS_ADC_SAR_CTRL(m)                                (*(volatile uint32_t *)(0x400a01c0UL + ((m) * 0x10000UL)))
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
#define PDSS_REFGEN_SEL6_SEL8_CTRL_ADDRESS(m)               (0x400a01e0UL + ((m) * (0x10000UL)))
#define PDSS_REFGEN_SEL6_SEL8_CTRL(m)                       (*(volatile uint32_t *)(0x400a01e0UL + ((m) * 0x10000UL)))
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
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL_ADDRESS(m)           (0x400a0230UL + ((m) * (0x10000UL)))
#define PDSS_VCONN20_CC1_SWITCH_1_CTRL(m)                   (*(volatile uint32_t *)(0x400a0230UL + ((m) * 0x10000UL)))
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
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL_ADDRESS(m)           (0x400a0234UL + ((m) * (0x10000UL)))
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL(m)                   (*(volatile uint32_t *)(0x400a0234UL + ((m) * 0x10000UL)))
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL_DEFAULT              (0x00000000UL)

/*
 * There can be a maximum of 24 HS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function
 */
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL_HS_SOURCE_SEL_MASK    (0x00000003UL) /* <0:1> R:RW:0:CLK_FILTER_FILT_NUM */
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL_HS_SOURCE_SEL_POS    (0UL)


/*
 * There can be a maximum of 8 LS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function.
 */
#define PDSS_VCONN20_CC1_SWITCH_2_CTRL_LS_SOURCE_SEL_MASK    (0x07000000UL) /* <24:26> R:RW:0:CLK_LF_FILT_NUM */
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
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL_ADDRESS(m)           (0x400a0238UL + ((m) * (0x10000UL)))
#define PDSS_VCONN20_CC2_SWITCH_1_CTRL(m)                   (*(volatile uint32_t *)(0x400a0238UL + ((m) * 0x10000UL)))
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
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_ADDRESS(m)           (0x400a023cUL + ((m) * (0x10000UL)))
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL(m)                   (*(volatile uint32_t *)(0x400a023cUL + ((m) * 0x10000UL)))
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_DEFAULT              (0x00000000UL)

/*
 * There can be a maximum of 24 HS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function
 */
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_HS_SOURCE_SEL_MASK    (0x00000003UL) /* <0:1> R:RW:0:CLK_FILTER_FILT_NUM */
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_HS_SOURCE_SEL_POS    (0UL)


/*
 * There can be a maximum of 8 LS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function.
 */
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_LS_SOURCE_SEL_MASK    (0x07000000UL) /* <24:26> R:RW:0:CLK_LF_FILT_NUM */
#define PDSS_VCONN20_CC2_SWITCH_2_CTRL_LS_SOURCE_SEL_POS    (24UL)


/*
 * VCONN20 pump_en control 1
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 */
#define PDSS_VCONN20_PUMP_EN_1_CTRL_ADDRESS(m)              (0x400a0240UL + ((m) * (0x10000UL)))
#define PDSS_VCONN20_PUMP_EN_1_CTRL(m)                      (*(volatile uint32_t *)(0x400a0240UL + ((m) * 0x10000UL)))
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
#define PDSS_VCONN20_PUMP_EN_2_CTRL_ADDRESS(m)              (0x400a0244UL + ((m) * (0x10000UL)))
#define PDSS_VCONN20_PUMP_EN_2_CTRL(m)                      (*(volatile uint32_t *)(0x400a0244UL + ((m) * 0x10000UL)))
#define PDSS_VCONN20_PUMP_EN_2_CTRL_DEFAULT                 (0x00000000UL)

/*
 * There can be a maximum of 24 HS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function
 */
#define PDSS_VCONN20_PUMP_EN_2_CTRL_HS_SOURCE_SEL_MASK      (0x00000003UL) /* <0:1> R:RW:0:CLK_FILTER_FILT_NUM */
#define PDSS_VCONN20_PUMP_EN_2_CTRL_HS_SOURCE_SEL_POS       (0UL)


/*
 * There can be a maximum of 8 LS filter.
 * This register can be use to select any of the comparators output for turning
 * on/off the function.
 */
#define PDSS_VCONN20_PUMP_EN_2_CTRL_LS_SOURCE_SEL_MASK      (0x07000000UL) /* <24:26> R:RW:0:CLK_LF_FILT_NUM */
#define PDSS_VCONN20_PUMP_EN_2_CTRL_LS_SOURCE_SEL_POS       (24UL)


/*
 * Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR1_CFG_ADDRESS(m)                           (0x400a02a0UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_CFG(m)                                   (*(volatile uint32_t *)(0x400a02a0UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_CFG_CC1_CC2_LS_ADDRESS(m)                (0x400a02a4UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_CFG_CC1_CC2_LS(m)                        (*(volatile uint32_t *)(0x400a02a4UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_ADDRESS(m)           (0x400a02a8UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_CFG_VCMP_UP_DOWN_LS(m)                   (*(volatile uint32_t *)(0x400a02a8UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_CFG_CC12_OCP_HS_ADDRESS(m)               (0x400a02acUL + ((m) * (0x10000UL)))
#define PDSS_INTR1_CFG_CC12_OCP_HS(m)                       (*(volatile uint32_t *)(0x400a02acUL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_CFG_CC12_OVP_HS_ADDRESS(m)               (0x400a02b0UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_CFG_CC12_OVP_HS(m)                       (*(volatile uint32_t *)(0x400a02b0UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_STATUS_ADDRESS(m)                        (0x400a02b4UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_STATUS(m)                                (*(volatile uint32_t *)(0x400a02b4UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_ADDRESS(m)                               (0x400a02b8UL + ((m) * (0x10000UL)))
#define PDSS_INTR1(m)                                       (*(volatile uint32_t *)(0x400a02b8UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_VSWAP_VBUS_LESS_5_DONE                   (1UL << 17) /* <17:17> RW1S:RW1C:0:SWAP_EN */


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
#define PDSS_INTR1_SET_ADDRESS(m)                           (0x400a02bcUL + ((m) * (0x10000UL)))
#define PDSS_INTR1_SET(m)                                   (*(volatile uint32_t *)(0x400a02bcUL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_SET_VSWAP_VBUS_LESS_5_DONE               (1UL << 17) /* <17:17> A:RW1S:0:SWAP_EN */


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
#define PDSS_INTR1_MASK_ADDRESS(m)                          (0x400a02c0UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_MASK(m)                                  (*(volatile uint32_t *)(0x400a02c0UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_MASK_VSWAP_VBUS_LESS_5_DONE_MASK         (1UL << 17) /* <17:17> R:RW:0:SWAP_EN */


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
#define PDSS_INTR1_MASKED_ADDRESS(m)                        (0x400a02c4UL + ((m) * (0x10000UL)))
#define PDSS_INTR1_MASKED(m)                                (*(volatile uint32_t *)(0x400a02c4UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR1_MASKED_VSWAP_VBUS_LESS_5_DONE_MASKED     (1UL << 17) /* <17:17> RW:R:0:SWAP_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_DRP_ATTACHED_DETECTED_MASKED      (1UL << 18) /* <18:18> RW:R:0:RPRD_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_LF_CNTR_MASKED                    (1UL << 19) /* <19:19> RW:R:0:LF_CNTR_EN */


/*
 * VSYS Wakeup Interrupts edge and filter configuration 1
 */
#define PDSS_INTR3_CFG_VSYS_ADDRESS(m)                      (0x400a0300UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_CFG_VSYS(m)                              (*(volatile uint32_t *)(0x400a0300UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR3_CFG_ADC_HS_ADDRESS(m)                    (0x400a0304UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_CFG_ADC_HS(m)                            (*(volatile uint32_t *)(0x400a0304UL + ((m) * 0x10000UL)))
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
 * 20V Regulator#1-4 VBUS Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR3_CFG_VREG20_VBUS_ADDRESS(m)               (0x400a0338UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_CFG_VREG20_VBUS(m)                       (*(volatile uint32_t *)(0x400a0338UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_CFG_VREG20_VBUS_DEFAULT                  (0x00000000UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_FILT_EN        (1UL << 0) /* <0:0> R:RW:0:VREG20_NUM_LOG1 */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_CFG_MASK       (0x00000030UL) /* <4:5> R:RW:0:VREG20_NUM_LOG2 */
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
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_FILT_RESET     (1UL << 12) /* <12:12> R:RW:0:VREG20_NUM_LOG1 */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_FILT_BYPASS    (1UL << 16) /* <16:16> R:RW:0:VREG20_NUM_LOG1 */


/*
 * #of clock CLK_LF filtering. Should be programmed before FILTER is enabled.
 */
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_FILT_SEL_MASK    (0x00700000UL) /* <20:22> R:RW:0:VREG20_NUM_LOG3 */
#define PDSS_INTR3_CFG_VREG20_VBUS_VREG_VBUS_FILT_SEL_POS    (20UL)


/*
 * INTR3 Status 0
 */
#define PDSS_INTR3_STATUS_0_ADDRESS(m)                      (0x400a0340UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_STATUS_0(m)                              (*(volatile uint32_t *)(0x400a0340UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_STATUS_0_DEFAULT                         (0x00000000UL)

/*
 * The status of vsys_det from the s8usbpd_ver3_vddd_sw_top
 */
#define PDSS_INTR3_STATUS_0_VSYS_STATUS                     (1UL << 0) /* <0:0> RW:R:0:VSYS_EN */


/*
 * CC1 Filtered output
 */
#define PDSS_INTR3_STATUS_0_VSYS_FILT                       (1UL << 1) /* <1:1> RW:R:0:VSYS_EN */


/*
 * The status of cmp_out from the ADC#1-4
 */
#define PDSS_INTR3_STATUS_0_CMP_OUT_STATUS                  (1UL << 2) /* <2:2> RW:R:0:ADC_NUM */


/*
 * ADC1-4 COMP_OUT Filtered output
 */
#define PDSS_INTR3_STATUS_0_CMP_OUT_FILT                    (1UL << 6) /* <6:6> RW:R:0:ADC_NUM */


/*
 * INTR3 Status 1
 */
#define PDSS_INTR3_STATUS_1_ADDRESS(m)                      (0x400a0344UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_STATUS_1(m)                              (*(volatile uint32_t *)(0x400a0344UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_STATUS_1_DEFAULT                         (0x00000000UL)

/*
 * The status of vbus_det from the s8usbpd_ver3 Regulator#1-4
 */
#define PDSS_INTR3_STATUS_1_VREG20_VBUS_STATUS              (1UL << 0) /* <0:0> RW:R:0:VREG20_NUM_LOG1 */


/*
 * CC1 Filtered output
 */
#define PDSS_INTR3_STATUS_1_VREG20_VBUS_FILT                (1UL << 4) /* <4:4> RW:R:0:VREG20_NUM_LOG1 */


/*
 * INTR3 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin.
 */
#define PDSS_INTR3_ADDRESS(m)                               (0x400a0348UL + ((m) * (0x10000UL)))
#define PDSS_INTR3(m)                                       (*(volatile uint32_t *)(0x400a0348UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_DEFAULT                                  (0x00000000UL)

/*
 * vsys_det changed (wakeup interrupt from deepsleep)
 * Check the  INTR3_STATUS.VSYS_STATUS value
 */
#define PDSS_INTR3_VSYS_CHANGED                             (1UL << 0) /* <0:0> RW1S:RW1C:0:VSYS_EN */


/*
 * CMP_OUT1-4 changed (wakeup interrupt from deepsleep)
 * Check the INTR3_STATUS.ADC_CMP_OUT_STATUS value
 */
#define PDSS_INTR3_CMP_OUT_CHANGED                          (1UL << 1) /* <1:1> RW1S:RW1C:0:ADC_NUM */


/*
 * vbus_c_det changed (wakeup interrupt from deepsleep)
 * Check the  INTR3_STATUS.VREG20_VBUS_STATUS value
 */
#define PDSS_INTR3_VREG20_VBUS_CHANGED                      (1UL << 13) /* <13:13> RW1S:RW1C:0:VREG20_NUM_LOG1 */


/*
 * INTR3 Interrupt Set
 */
#define PDSS_INTR3_SET_ADDRESS(m)                           (0x400a034cUL + ((m) * (0x10000UL)))
#define PDSS_INTR3_SET(m)                                   (*(volatile uint32_t *)(0x400a034cUL + ((m) * 0x10000UL)))
#define PDSS_INTR3_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_VSYS_CHANGED                         (1UL << 0) /* <0:0> A:RW1S:0:VSYS_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_CMP_OUT_CHANGED                      (1UL << 1) /* <1:1> A:RW1S:0:ADC_NUM */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_VREG20_VBUS_CHANGED                  (1UL << 13) /* <13:13> A:RW1S:0:VREG20_NUM_LOG1 */


/*
 * INTR3 interrupt Mask
 */
#define PDSS_INTR3_MASK_ADDRESS(m)                          (0x400a0350UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_MASK(m)                                  (*(volatile uint32_t *)(0x400a0350UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_VSYS_CHANGED_MASK                   (1UL << 0) /* <0:0> R:RW:0:VSYS_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_CMP_OUT_CHANGED_MASK                (1UL << 1) /* <1:1> R:RW:0:ADC_NUM */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_VREG20_VBUS_CHANGED_MASK            (1UL << 13) /* <13:13> R:RW:0:VREG20_NUM_LOG1 */


/*
 * INTR3 interrupt Masked
 */
#define PDSS_INTR3_MASKED_ADDRESS(m)                        (0x400a0354UL + ((m) * (0x10000UL)))
#define PDSS_INTR3_MASKED(m)                                (*(volatile uint32_t *)(0x400a0354UL + ((m) * 0x10000UL)))
#define PDSS_INTR3_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_VSYS_CHANGED_MASKED               (1UL << 0) /* <0:0> RW:R:0:VSYS_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_CMP_OUT_CHANGED_MASKED            (1UL << 1) /* <1:1> RW:R:0:ADC_NUM */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_VREG20_VBUS_CHANGED_MASKED        (1UL << 13) /* <13:13> RW:R:0:VREG20_NUM_LOG1 */


/*
 * CLK_FILTER (Refer to CTRL.SEL_CLK_FILTER) Filter configuration
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 */
#define PDSS_INTR5_FILTER_CFG_ADDRESS(m,n)                  (0x400a0380UL + ((m) * (0x10000UL)) + ((n) * (0x0004UL)))
#define PDSS_INTR5_FILTER_CFG(m,n)                          (*(volatile uint32_t *)(0x400a0380UL + ((m) * (0x10000UL)) + ((n) * 0x0004)))
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
#define PDSS_INTR5_STATUS_0_ADDRESS(m)                      (0x400a03e0UL + ((m) * (0x10000UL)))
#define PDSS_INTR5_STATUS_0(m)                              (*(volatile uint32_t *)(0x400a03e0UL + ((m) * 0x10000UL)))
#define PDSS_INTR5_STATUS_0_DEFAULT                         (0x00000000UL)

/*
 * The status of HS/LS filter edge detectors 1-12
 */
#define PDSS_INTR5_STATUS_0_STATUS_12_MASK                  (0x00000003UL) /* <0:1> RW:R:0:CLK_FILTER_FILT_NUM_LOG1_12 */
#define PDSS_INTR5_STATUS_0_STATUS_12_POS                   (0UL)


/*
 * 1-12 HS/LS Filtered output
 */
#define PDSS_INTR5_STATUS_0_FILT_12_MASK                    (0x00003000UL) /* <12:13> RW:R:0:CLK_FILTER_FILT_NUM_LOG1_12 */
#define PDSS_INTR5_STATUS_0_FILT_12_POS                     (12UL)


/*
 * INTR5 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin from HS filters
 */
#define PDSS_INTR5_ADDRESS(m)                               (0x400a03e8UL + ((m) * (0x10000UL)))
#define PDSS_INTR5(m)                                       (*(volatile uint32_t *)(0x400a03e8UL + ((m) * 0x10000UL)))
#define PDSS_INTR5_DEFAULT                                  (0x00000000UL)

/*
 * Change in edge of HS filter edge detectors (wakeup interrupt from deepsleep)
 * Check the  INTR5_STATUS_0/1.STATUS_12/24 value
 */
#define PDSS_INTR5_EDGE_CHANGED_MASK                        (0x00000003UL) /* <0:1> RW1S:RW1C:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_EDGE_CHANGED_POS                         (0UL)


/*
 * INTR5 Interrupt Set
 */
#define PDSS_INTR5_SET_ADDRESS(m)                           (0x400a03ecUL + ((m) * (0x10000UL)))
#define PDSS_INTR5_SET(m)                                   (*(volatile uint32_t *)(0x400a03ecUL + ((m) * 0x10000UL)))
#define PDSS_INTR5_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR5_SET_EDGE_CHANGED_MASK                    (0x00000003UL) /* <0:1> A:RW1S:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_SET_EDGE_CHANGED_POS                     (0UL)


/*
 * INTR5 interrupt Mask
 */
#define PDSS_INTR5_MASK_ADDRESS(m)                          (0x400a03f0UL + ((m) * (0x10000UL)))
#define PDSS_INTR5_MASK(m)                                  (*(volatile uint32_t *)(0x400a03f0UL + ((m) * 0x10000UL)))
#define PDSS_INTR5_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR5_MASK_EDGE_CHANGED_MASK_MASK              (0x00000003UL) /* <0:1> R:RW:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_MASK_EDGE_CHANGED_MASK_POS               (0UL)


/*
 * INTR5 interrupt Masked
 */
#define PDSS_INTR5_MASKED_ADDRESS(m)                        (0x400a03f4UL + ((m) * (0x10000UL)))
#define PDSS_INTR5_MASKED(m)                                (*(volatile uint32_t *)(0x400a03f4UL + ((m) * 0x10000UL)))
#define PDSS_INTR5_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR5_MASKED_EDGE_CHANGED_MASKED_MASK          (0x00000003UL) /* <0:1> RW:R:0:CLK_FILTER_LOG1 */
#define PDSS_INTR5_MASKED_EDGE_CHANGED_MASKED_POS           (0UL)


/*
 * CLK_LF ONLY Filter configuration
 * Refer to COMP_CTRL, COMP_TR_CTRL comments for the mapping
 */
#define PDSS_INTR7_FILTER_CFG_ADDRESS(m,n)                  (0x400a0420UL + ((m) * (0x10000UL)) + ((n) * (0x0004UL)))
#define PDSS_INTR7_FILTER_CFG(m,n)                          (*(volatile uint32_t *)(0x400a0420UL + ((m) * (0x10000UL)) + ((n) * 0x0004)))
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
 * MSB 4 bits for 9bit filtering, To be read as {CLK_LF_FILT_SEL_EXT, CLK_LF_FILT_SEL}
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_SEL_EXT_MASK      (0x00003f00UL) /* <8:13> R:RW:0:PMG1S3_EN */
#define PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_SEL_EXT_POS       (8UL)


/*
 * INTR7 Status
 */
#define PDSS_INTR7_STATUS_ADDRESS(m)                        (0x400a0440UL + ((m) * (0x10000UL)))
#define PDSS_INTR7_STATUS(m)                                (*(volatile uint32_t *)(0x400a0440UL + ((m) * 0x10000UL)))
#define PDSS_INTR7_STATUS_DEFAULT                           (0x00000000UL)

/*
 * The status of LS filter edge detectors
 */
#define PDSS_INTR7_STATUS_STATUS_8_MASK                     (0x00000007UL) /* <0:2> RW:R:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_STATUS_STATUS_8_POS                      (0UL)


/*
 * 1-8 LS Filtered output
 */
#define PDSS_INTR7_STATUS_FILT_8_MASK                       (0x00000700UL) /* <8:10> RW:R:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_STATUS_FILT_8_POS                        (8UL)


/*
 * INTR7 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin from LS filters
 */
#define PDSS_INTR7_ADDRESS(m)                               (0x400a0444UL + ((m) * (0x10000UL)))
#define PDSS_INTR7(m)                                       (*(volatile uint32_t *)(0x400a0444UL + ((m) * 0x10000UL)))
#define PDSS_INTR7_DEFAULT                                  (0x00000000UL)

/*
 * Change in edge of HS filter edge detectors (wakeup interrupt from deepsleep)
 * Check the  INTR7_STATUS.STATUS_8 value
 */
#define PDSS_INTR7_CLK_LF_EDGE_CHANGED_MASK                 (0x00000007UL) /* <0:2> RW1S:RW1C:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_CLK_LF_EDGE_CHANGED_POS                  (0UL)


/*
 * INTR7 Interrupt Set
 */
#define PDSS_INTR7_SET_ADDRESS(m)                           (0x400a0448UL + ((m) * (0x10000UL)))
#define PDSS_INTR7_SET(m)                                   (*(volatile uint32_t *)(0x400a0448UL + ((m) * 0x10000UL)))
#define PDSS_INTR7_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR7_SET_CLK_LF_EDGE_CHANGED_MASK             (0x00000007UL) /* <0:2> A:RW1S:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_SET_CLK_LF_EDGE_CHANGED_POS              (0UL)


/*
 * INTR7 interrupt Mask
 */
#define PDSS_INTR7_MASK_ADDRESS(m)                          (0x400a044cUL + ((m) * (0x10000UL)))
#define PDSS_INTR7_MASK(m)                                  (*(volatile uint32_t *)(0x400a044cUL + ((m) * 0x10000UL)))
#define PDSS_INTR7_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR7_MASK_CLK_LF_EDGE_CHANGED_MASK_MASK       (0x00000007UL) /* <0:2> R:RW:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_MASK_CLK_LF_EDGE_CHANGED_MASK_POS        (0UL)


/*
 * INTR7 interrupt Masked
 */
#define PDSS_INTR7_MASKED_ADDRESS(m)                        (0x400a0450UL + ((m) * (0x10000UL)))
#define PDSS_INTR7_MASKED(m)                                (*(volatile uint32_t *)(0x400a0450UL + ((m) * 0x10000UL)))
#define PDSS_INTR7_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR7_MASKED_CLK_LF_EDGE_CHANGED_MASKED_MASK    (0x00000007UL) /* <0:2> RW:R:0:CLK_LF_FILT_NUM */
#define PDSS_INTR7_MASKED_CLK_LF_EDGE_CHANGED_MASKED_POS    (0UL)


/*
 * Battery Charger 1-4 Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR9_CFG_BCH_DET_ADDRESS(m)                   (0x400a0470UL + ((m) * (0x10000UL)))
#define PDSS_INTR9_CFG_BCH_DET(m)                           (*(volatile uint32_t *)(0x400a0470UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR9_STATUS_0_ADDRESS(m)                      (0x400a048cUL + ((m) * (0x10000UL)))
#define PDSS_INTR9_STATUS_0(m)                              (*(volatile uint32_t *)(0x400a048cUL + ((m) * 0x10000UL)))
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
#define PDSS_INTR9_STATUS_1_ADDRESS(m)                      (0x400a0490UL + ((m) * (0x10000UL)))
#define PDSS_INTR9_STATUS_1(m)                              (*(volatile uint32_t *)(0x400a0490UL + ((m) * 0x10000UL)))
#define PDSS_INTR9_STATUS_1_DEFAULT                         (0x00000000UL)

/*
 * The status of qcom receiver dm
 */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DM_STATUS             (1UL << 8) /* <8:8> RW:R:0:BCH_DET_NUM */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DM_STATUS_POS         (8UL)      /* <8:8> RW:R:0:BCH_DET_NUM */


/*
 * QCOM RCVR DM  Filtered output
 */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DM_FILT               (1UL << 12) /* <12:12> RW:R:0:BCH_DET_NUM */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DM_FILT_POS           (12UL)      /* <12:12> RW:R:0:BCH_DET_NUM */


/*
 * The status of qcom receiver dp
 */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DP_STATUS             (1UL << 16) /* <16:16> RW:R:0:BCH_DET_NUM */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DP_STATUS_POS         (16UL)      /* <16:16> RW:R:0:BCH_DET_NUM */


/*
 * QCOM RCVR DP  Filtered output
 */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DP_FILT               (1UL << 20) /* <20:20> RW:R:0:BCH_DET_NUM */
#define PDSS_INTR9_STATUS_1_QCOM_RCVR_DP_FILT_POS           (20UL)      /* <20:20> RW:R:0:BCH_DET_NUM */


/*
 * DM  Filtered output
 */
#define PDSS_INTR9_STATUS_1_DM_FILT                         (1UL << 24) /* <24:24> RW:R:0:BCH_DET_NUM */
#define PDSS_INTR9_STATUS_1_DM_FILT_POS                     (24UL)      /* <24:24> RW:R:0:BCH_DET_NUM */


/*
 * DP  Filtered output
 */
#define PDSS_INTR9_STATUS_1_DP_FILT                         (1UL << 28) /* <28:28> RW:R:0:BCH_DET_NUM */
#define PDSS_INTR9_STATUS_1_DP_FILT_POS                     (28UL)      /* <28:28> RW:R:0:BCH_DET_NUM */


/*
 * INTR9 interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin.
 */
#define PDSS_INTR9_ADDRESS(m)                               (0x400a0494UL + ((m) * (0x10000UL)))
#define PDSS_INTR9(m)                                       (*(volatile uint32_t *)(0x400a0494UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR9_SET_ADDRESS(m)                           (0x400a0498UL + ((m) * (0x10000UL)))
#define PDSS_INTR9_SET(m)                                   (*(volatile uint32_t *)(0x400a0498UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR9_MASK_ADDRESS(m)                          (0x400a049cUL + ((m) * (0x10000UL)))
#define PDSS_INTR9_MASK(m)                                  (*(volatile uint32_t *)(0x400a049cUL + ((m) * 0x10000UL)))
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
#define PDSS_INTR9_MASKED_ADDRESS(m)                        (0x400a04a0UL + ((m) * (0x10000UL)))
#define PDSS_INTR9_MASKED(m)                                (*(volatile uint32_t *)(0x400a04a0UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR11_FILTER_CFG_ADDRESS(m)                   (0x400a04c0UL + ((m) * (0x10000UL)))
#define PDSS_INTR11_FILTER_CFG(m)                           (*(volatile uint32_t *)(0x400a04c0UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR11_STATUS_0_ADDRESS(m)                     (0x400a04c4UL + ((m) * (0x10000UL)))
#define PDSS_INTR11_STATUS_0(m)                             (*(volatile uint32_t *)(0x400a04c4UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR11_ADDRESS(m)                              (0x400a04c8UL + ((m) * (0x10000UL)))
#define PDSS_INTR11(m)                                      (*(volatile uint32_t *)(0x400a04c8UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR11_SET_ADDRESS(m)                          (0x400a04ccUL + ((m) * (0x10000UL)))
#define PDSS_INTR11_SET(m)                                  (*(volatile uint32_t *)(0x400a04ccUL + ((m) * 0x10000UL)))
#define PDSS_INTR11_SET_DEFAULT                             (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR11_SET_FILT2_EDGE_CHANGED_MASK             (0x00000003UL) /* <0:1> A:RW1S:0: */
#define PDSS_INTR11_SET_FILT2_EDGE_CHANGED_POS              (0UL)


/*
 * INTR11 interrupt Mask
 */
#define PDSS_INTR11_MASK_ADDRESS(m)                         (0x400a04d0UL + ((m) * (0x10000UL)))
#define PDSS_INTR11_MASK(m)                                 (*(volatile uint32_t *)(0x400a04d0UL + ((m) * 0x10000UL)))
#define PDSS_INTR11_MASK_DEFAULT                            (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR11_MASK_FILT2_EDGE_CHANGED_MASK_MASK       (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_INTR11_MASK_FILT2_EDGE_CHANGED_MASK_POS        (0UL)


/*
 * INTR11 interrupt Masked
 */
#define PDSS_INTR11_MASKED_ADDRESS(m)                       (0x400a04d4UL + ((m) * (0x10000UL)))
#define PDSS_INTR11_MASKED(m)                               (*(volatile uint32_t *)(0x400a04d4UL + ((m) * 0x10000UL)))
#define PDSS_INTR11_MASKED_DEFAULT                          (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR11_MASKED_FILT2_EDGE_CHANGED_MASKED_MASK    (0x00000003UL) /* <0:1> RW:R:0: */
#define PDSS_INTR11_MASKED_FILT2_EDGE_CHANGED_MASKED_POS    (0UL)


/*
 * INTR13 Status
 */
#define PDSS_INTR13_STATUS_ADDRESS(m)                       (0x400a04dcUL + ((m) * (0x10000UL)))
#define PDSS_INTR13_STATUS(m)                               (*(volatile uint32_t *)(0x400a04dcUL + ((m) * 0x10000UL)))
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
 * The status of csa_out_d from the s8usbpdv2_csa_rcp_top
 */
#define PDSS_INTR13_STATUS_CSA_OUT_STATUS                   (1UL << 12) /* <12:12> RW:R:0:CSA_RCP_EN */


/*
 * csa_out_d Filtered output
 */
#define PDSS_INTR13_STATUS_CSA_OUT_FILT                     (1UL << 13) /* <13:13> RW:R:0:CSA_RCP_EN */


/*
 * The status of rcp_comp_out_lv from the s8usbpdv2_csa_rcp_top
 */
#define PDSS_INTR13_STATUS_CSA_COMP_OUT_STATUS              (1UL << 14) /* <14:14> RW:R:0:CSA_RCP_EN */


/*
 * rcp_comp_out_lv Filtered output
 */
#define PDSS_INTR13_STATUS_CSA_COMP_OUT_FILT                (1UL << 15) /* <15:15> RW:R:0:CSA_RCP_EN */


/*
 * The status of vbus_ovp_comp_out_lv from the s8usbpdv2_csa_rcp_top
 */
#define PDSS_INTR13_STATUS_CSA_VBUS_OVP_STATUS              (1UL << 16) /* <16:16> RW:R:0:CSA_RCP_EN */


/*
 * vbus_ovp_comp_out_lv Filtered output
 */
#define PDSS_INTR13_STATUS_CSA_VBUS_OVP_FILT                (1UL << 17) /* <17:17> RW:R:0:CSA_RCP_EN */


/*
 * INTR13 interrupt Cause.
 */
#define PDSS_INTR13_ADDRESS(m)                              (0x400a04e0UL + ((m) * (0x10000UL)))
#define PDSS_INTR13(m)                                      (*(volatile uint32_t *)(0x400a04e0UL + ((m) * 0x10000UL)))
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
 * csa_out_d changed (wakeup interrupt from deepsleep)
 * Check the  INTR13_STATUS_5.CSA_OC_STATUS value
 */
#define PDSS_INTR13_CSA_OUT_CHANGED                         (1UL << 6) /* <6:6> RW1S:RW1C:0:CSA_RCP_EN */


/*
 * rcp_comp_out_lv changed (wakeup interrupt from deepsleep)
 * Check the  INTR13_STATUS.CSA_OUT_STATUS value
 */
#define PDSS_INTR13_CSA_COMP_OUT_CHANGED                    (1UL << 7) /* <7:7> RW1S:RW1C:0:CSA_RCP_EN */


/*
 * vbus_ovp_comp_out_lv changed (wakeup interrupt from deepsleep)
 * Check the  INTR13_STATUS.CSA_COMP_OUT_STATUS value
 */
#define PDSS_INTR13_CSA_VBUS_OVP_CHANGED                    (1UL << 8) /* <8:8> RW1S:RW1C:0:CSA_RCP_EN */


/*
 * INTR13 Interrupt Set
 */
#define PDSS_INTR13_SET_ADDRESS(m)                          (0x400a04e4UL + ((m) * (0x10000UL)))
#define PDSS_INTR13_SET(m)                                  (*(volatile uint32_t *)(0x400a04e4UL + ((m) * 0x10000UL)))
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
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_CSA_OUT_CHANGED                     (1UL << 6) /* <6:6> A:RW1S:0:CSA_RCP_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_CSA_COMP_OUT_CHANGED                (1UL << 7) /* <7:7> A:RW1S:0:CSA_RCP_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_SET_CSA_VBUS_OVP_CHANGED                (1UL << 8) /* <8:8> A:RW1S:0:CSA_RCP_EN */


/*
 * INTR13 interrupt Mask
 */
#define PDSS_INTR13_MASK_ADDRESS(m)                         (0x400a04e8UL + ((m) * (0x10000UL)))
#define PDSS_INTR13_MASK(m)                                 (*(volatile uint32_t *)(0x400a04e8UL + ((m) * 0x10000UL)))
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
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_CSA_OUT_CHANGED_MASK               (1UL << 6) /* <6:6> R:RW:0:CSA_RCP_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_CSA_COMP_OUT_CHANGED_MASK          (1UL << 7) /* <7:7> R:RW:0:CSA_RCP_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR13_MASK_CSA_VBUS_OVP_CHANGED_MASK          (1UL << 8) /* <8:8> R:RW:0:CSA_RCP_EN */


/*
 * INTR13 interrupt Masked
 */
#define PDSS_INTR13_MASKED_ADDRESS(m)                       (0x400a04ecUL + ((m) * (0x10000UL)))
#define PDSS_INTR13_MASKED(m)                               (*(volatile uint32_t *)(0x400a04ecUL + ((m) * 0x10000UL)))
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
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_CSA_OUT_CHANGED_MASKED           (1UL << 6) /* <6:6> RW:R:0:CSA_RCP_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_CSA_COMP_OUT_CHANGED_MASKED      (1UL << 7) /* <7:7> RW:R:0:CSA_RCP_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR13_MASKED_CSA_VBUS_OVP_CHANGED_MASKED      (1UL << 8) /* <8:8> RW:R:0:CSA_RCP_EN */


/*
 * CSA SCP HardIP High/Low Speed Filter and Edge detector configuration for
 * OCP and SCP detection
 */
#define PDSS_INTR13_CFG_CSA_SCP_HS_ADDRESS(m)               (0x400a04f0UL + ((m) * (0x10000UL)))
#define PDSS_INTR13_CFG_CSA_SCP_HS(m)                       (*(volatile uint32_t *)(0x400a04f0UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR13_CFG_CSA_RCP_HS_ADDRESS(m)               (0x400a04f4UL + ((m) * (0x10000UL)))
#define PDSS_INTR13_CFG_CSA_RCP_HS(m)                       (*(volatile uint32_t *)(0x400a04f4UL + ((m) * 0x10000UL)))
#define PDSS_INTR13_CFG_CSA_RCP_HS_DEFAULT                  (0x00200400UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_EN          (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_CFG_POS     (1UL)


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
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_RESET       (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_BYPASS      (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_SEL_POS     (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_DPSLP_MODE       (1UL << 10) /* <10:10> R:RW:1: */


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
 * CSA RCP HardIP High/Low Speed Filter and Edge detector configuration for
 * VBUS_OVP detection
 */
#define PDSS_INTR13_CFG_CSA_RCP_OVP_HS_ADDRESS(m)           (0x400a04f8UL + ((m) * (0x10000UL)))
#define PDSS_INTR13_CFG_CSA_RCP_OVP_HS(m)                   (*(volatile uint32_t *)(0x400a04f8UL + ((m) * 0x10000UL)))
#define PDSS_INTR13_CFG_CSA_RCP_OVP_HS_DEFAULT              (0x00000400UL)

/*
 * 0: Filter is disabled
 * 1: Filter is enabled
 */
#define PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_EN    (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_CFG_MASK    (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_CFG_POS    (1UL)


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
#define PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_RESET    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit bypasses the Filter. It is recommended to set FILTER_EN
 * to 1'b0 with this to save power.
 */
#define PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_BYPASS    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * #of clock CLK_FILTER filtering. Should be programmed before FILTER is
 * enabled.
 */
#define PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_SEL_MASK    (0x000003e0UL) /* <5:9> R:RW:0: */
#define PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_SEL_POS    (5UL)


/*
 * This bit enables CPU to bypass the Filter when the part is in deep-sleep
 * state.  This over-rides the FILTER_EN settings during DEEP SLEEP state
 * ONLY.
 * The bit should be set by CPU only when its using the filter with high
 * frequency active clock and wants to wakeup from deep sleep on the transition
 * of the incoming signal.
 * This bit if set also disables the AUTO shutoff logic in DEEP SLEEP state.
 */
#define PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_DPSLP_MODE    (1UL << 10) /* <10:10> R:RW:1: */


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
 * Marks Completion of the ADC SAR1-4 conversion at the end of 8 cycles of
 * clk_sar when SAR_EN is "1"
 */
#define PDSS_INTR0_SAR_DONE                                 (1UL << 27) /* <27:27> RW1S:RW1C:0:ADC_NUM */


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
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_SAR_DONE                             (1UL << 27) /* <27:27> A:RW1S:0:ADC_NUM */


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
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_SAR_DONE_MASK                       (1UL << 27) /* <27:27> R:RW:0:ADC_NUM */


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
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_SAR_DONE_MASKED                   (1UL << 27) /* <27:27> RW:R:0:ADC_NUM */


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
 * INTR4 Cause for AFC. These are the active interrupts get reflected on
 * interrupt_usbpd pin.
 */
#define PDSS_INTR4_ADDRESS(m)                               (0x400a0520UL + ((m) * (0x10000UL)))
#define PDSS_INTR4(m)                                       (*(volatile uint32_t *)(0x400a0520UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR4_SET_ADDRESS(m)                           (0x400a0524UL + ((m) * (0x10000UL)))
#define PDSS_INTR4_SET(m)                                   (*(volatile uint32_t *)(0x400a0524UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR4_MASK_ADDRESS(m)                          (0x400a0528UL + ((m) * (0x10000UL)))
#define PDSS_INTR4_MASK(m)                                  (*(volatile uint32_t *)(0x400a0528UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR4_MASKED_ADDRESS(m)                        (0x400a052cUL + ((m) * (0x10000UL)))
#define PDSS_INTR4_MASKED(m)                                (*(volatile uint32_t *)(0x400a052cUL + ((m) * 0x10000UL)))
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
#define PDSS_INTR6_ADDRESS(m)                               (0x400a0530UL + ((m) * (0x10000UL)))
#define PDSS_INTR6(m)                                       (*(volatile uint32_t *)(0x400a0530UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR6_SET_ADDRESS(m)                           (0x400a0534UL + ((m) * (0x10000UL)))
#define PDSS_INTR6_SET(m)                                   (*(volatile uint32_t *)(0x400a0534UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR6_MASK_ADDRESS(m)                          (0x400a0538UL + ((m) * (0x10000UL)))
#define PDSS_INTR6_MASK(m)                                  (*(volatile uint32_t *)(0x400a0538UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR6_MASKED_ADDRESS(m)                        (0x400a053cUL + ((m) * (0x10000UL)))
#define PDSS_INTR6_MASKED(m)                                (*(volatile uint32_t *)(0x400a053cUL + ((m) * 0x10000UL)))
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
 * IP DDFT0/1 and TR_OUT0/1 Selections
 */
#define PDSS_DDFT_MUX_ADDRESS(m)                            (0x400a0580UL + ((m) * (0x10000UL)))
#define PDSS_DDFT_MUX(m)                                    (*(volatile uint32_t *)(0x400a0580UL + ((m) * 0x10000UL)))
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
#define PDSS_INTR_DDFT_MUX_ADDRESS(m)                       (0x400a0584UL + ((m) * (0x10000UL)))
#define PDSS_INTR_DDFT_MUX(m)                               (*(volatile uint32_t *)(0x400a0584UL + ((m) * 0x10000UL)))
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
#define PDSS_NCELL_DDFT_MUX_ADDRESS(m)                      (0x400a0588UL + ((m) * (0x10000UL)))
#define PDSS_NCELL_DDFT_MUX(m)                              (*(volatile uint32_t *)(0x400a0588UL + ((m) * 0x10000UL)))
#define PDSS_NCELL_DDFT_MUX_DEFAULT                         (0x00000000UL)

/*
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
#define PDSS_GPIO_DDFT_MUX_ADDRESS(m)                       (0x400a058cUL + ((m) * (0x10000UL)))
#define PDSS_GPIO_DDFT_MUX(m)                               (*(volatile uint32_t *)(0x400a058cUL + ((m) * 0x10000UL)))
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
#define PDSS_GPIO_INTR_DDFT_MUX_ADDRESS(m)                  (0x400a0590UL + ((m) * (0x10000UL)))
#define PDSS_GPIO_INTR_DDFT_MUX(m)                          (*(volatile uint32_t *)(0x400a0590UL + ((m) * 0x10000UL)))
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
#define PDSS_FAULT_GPIO_CTRL_EXTR_ADDRESS(m)                (0x400a0598UL + ((m) * (0x10000UL)))
#define PDSS_FAULT_GPIO_CTRL_EXTR(m)                        (*(volatile uint32_t *)(0x400a0598UL + ((m) * 0x10000UL)))
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
#define PDSS_CC_CTRL_0_ADDRESS(m)                           (0x400a0600UL + ((m) * (0x10000UL)))
#define PDSS_CC_CTRL_0(m)                                   (*(volatile uint32_t *)(0x400a0600UL + ((m) * 0x10000UL)))
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
#define PDSS_CC_CTRL_1_ADDRESS(m)                           (0x400a0604UL + ((m) * (0x10000UL)))
#define PDSS_CC_CTRL_1(m)                                   (*(volatile uint32_t *)(0x400a0604UL + ((m) * 0x10000UL)))
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
#define PDSS_DPSLP_REF_CTRL_ADDRESS(m)                      (0x400a0608UL + ((m) * (0x10000UL)))
#define PDSS_DPSLP_REF_CTRL(m)                              (*(volatile uint32_t *)(0x400a0608UL + ((m) * 0x10000UL)))
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
 * USBPD Hard IP VSYS1  Supply Switch Register
 */
#define PDSS_VSYS_CTRL_ADDRESS(m)                           (0x400a0618UL + ((m) * (0x10000UL)))
#define PDSS_VSYS_CTRL(m)                                   (*(volatile uint32_t *)(0x400a0618UL + ((m) * 0x10000UL)))
#define PDSS_VSYS_CTRL_DEFAULT                              (0x00000000UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
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
#define PDSS_VSYS_CTRL_ADFT_SEL_MASK                        (0x0000000cUL) /* <2:3> R:RW:0: */
#define PDSS_VSYS_CTRL_ADFT_SEL_POS                         (2UL)


/*
 * USBPD Hard IP Regulator #1-4 and VSYS Supply Switch 1 Register
 */
#define PDSS_VREG_VSYS_CTRL_ADDRESS(m)                      (0x400a061cUL + ((m) * (0x10000UL)))
#define PDSS_VREG_VSYS_CTRL(m)                              (*(volatile uint32_t *)(0x400a061cUL + ((m) * 0x10000UL)))
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
 */
#define PDSS_VREG_VSYS_CTRL_VREG20_1_EN                     (1UL << 4) /* <4:4> R:RW:0:REGULATOR20_1_EN */


/*
 * When VREG20_EN is set/de-assert, the regulator will turn off/on after
 * VREG20_ONOFF_CNTR cycle of clk_tx.
 * There won't be any delay is this register is set to zero.
 */
#define PDSS_VREG_VSYS_CTRL_VREG20_ONOFF_CNTR_MASK          (0x0000ff00UL) /* <8:15> R:RW:0:KEEP_REG_BIT */
#define PDSS_VREG_VSYS_CTRL_VREG20_ONOFF_CNTR_POS           (8UL)


/*
 * Control signal to enable/disable switch
 * "1" : Enable switch : VOUT = VDDD = VSYS
 * "0" : Disable switch
 */
#define PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH              (1UL << 16) /* <16:16> R:RW:1:VSYS_EN */


/*
 * When ENABLE_VDDD_SWITCH is set/de-assert, the s8usbpd_vdd_sw_top will
 * turn off/on after VDDD_SW_ONOFF_CNTR cycle of clk_tx.
 * There won't be any delay is this register is set to zero.
 */
#define PDSS_VREG_VSYS_CTRL_VDDD_SW_ONOFF_CNTR_MASK         (0x01fe0000UL) /* <17:24> R:RW:0:VSYS_EN */
#define PDSS_VREG_VSYS_CTRL_VDDD_SW_ONOFF_CNTR_POS          (17UL)


/*
 * USBPD Hard IP AMUX_NHV #1-32 Register
 * Function                            SWITCH#          SEL[0]    SEL[1]
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 * ACG1F:
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *           UV                                          #0             
 *       10%        20%
 *           OV                                          #1             
 *       08%        10%
 *           VBUS_2_ADC_0                 #2                    10%     
 *   08%
 *           VBUS_2_ADC_1                 #3                AMUXB     "VBUS_2_ADC_0"
 *
 * CCG6DF-Port0 / CCG6SF:
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *           UV                                          #0             
 *       10%        20%
 *           OV                                          #1             
 *       08%        10%
 *           VBUS_2_ADC_0                 #2                    10%     
 *   08%
 *           VBUS_2_ADC_1                 #3                AMUXB     "VBUS_2_ADC_0"
 *           VSYS_DET                           #4                    40%
 *        50%
 * CCG6DF-Port1:
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *           UV                                          #0             
 *       10%        20%
 *           OV                                          #1             
 *       08%        10%
 *           VBUS_2_ADC_0                 #2                    10%     
 *   08%
 *           VBUS_2_ADC_1                 #3                AMUXB     "VBUS_2_ADC_0"
 * ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 * ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *  Function                               SWITCH#                   SEL[0]
 *                               SEL[1]
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 * PMG1S3-Port0:
 *          UV                                      #0                  
 *         8%(VBUSC)                      15%(VBUSC)
 *          OV                                      #1                  
 *         6%(VBUSC)                      8%(VBUSC)
 *          AMUX_NHV[5]                                      #2         
 *                  8%(VBUSC)                      15%(VBUSC)
 *          UV                                      #3                  
 *         8%(VBUSC)                      15%(VBUSC)
 *          UV                                      #4                  
 *         8%(VBUSC)                      15%(VBUSC)
 *          UV                                      #5                  
 *         8%(VBUSC)                      15%(VBUSC)
 */
#define PDSS_AMUX_NHV_CTRL_ADDRESS(m)                       (0x400a062cUL + ((m) * (0x10000UL)))
#define PDSS_AMUX_NHV_CTRL(m)                               (*(volatile uint32_t *)(0x400a062cUL + ((m) * 0x10000UL)))
#define PDSS_AMUX_NHV_CTRL_DEFAULT                          (0x00000000UL)

/*
 * AMUX select control
 */
#define PDSS_AMUX_NHV_CTRL_SEL_MASK                         (0x0000003fUL) /* <0:5> R:RW:0:USB_AMUX_NHV_NUM */
#define PDSS_AMUX_NHV_CTRL_SEL_POS                          (0UL)


/*
 * USBPD Hard IP AMUX_DENFET #1-32 Register
 * Function                            SWITCH#          SEL[0]    SEL[1]
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 * ACG1F:
 * ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *           VBUS_MON                          #0                  100% 
 *     10%
 */
#define PDSS_AMUX_DENFET_CTRL_ADDRESS(m)                    (0x400a0630UL + ((m) * (0x10000UL)))
#define PDSS_AMUX_DENFET_CTRL(m)                            (*(volatile uint32_t *)(0x400a0630UL + ((m) * 0x10000UL)))
#define PDSS_AMUX_DENFET_CTRL_DEFAULT                       (0x00000000UL)

/*
 * AMUX select control
 */
#define PDSS_AMUX_DENFET_CTRL_SEL                           (1UL << 0) /* <0:0> R:RW:0:USB_AMUX_DENFET_NUM */


/*
 * USBPD Hard IP 20V Regulator #1-4 Register
 */
#define PDSS_VREG_CTRL_ADDRESS(m)                           (0x400a0660UL + ((m) * (0x10000UL)))
#define PDSS_VREG_CTRL(m)                                   (*(volatile uint32_t *)(0x400a0660UL + ((m) * 0x10000UL)))
#define PDSS_VREG_CTRL_DEFAULT                              (0x00080800UL)

/*
 * adft control inputs used to select different analog signal to be brought
 * out on adft1 and adft2
 * 00 - Normal Operation
 * 01 - vreg_en (VDDD domain) on adft1 and vbus_good_vcrude on adft2
 * 10 - vfb on adft1 and vreg_cr on adft2
 * 11 - vref on adft1, vreg_en (vcrude domain) on adft2
 */
#define PDSS_VREG_CTRL_VREG20_ADFT_CTRL_MASK                (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_VREG_CTRL_VREG20_ADFT_CTRL_POS                 (0UL)


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_VREG_CTRL_VREG_ISO_N                           (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Control signal to choose Bandgap voltage as the reference instead of the
 * dpslp reference, Active High
 */
#define PDSS_VREG_CTRL_VBG_EN                               (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Test Mode Control for s8usbpdv2_28vreg_top.
 * TM_28VREG<0> - 0: inrush clamp in normal function
 *                             1: forcefully turning on inrush clamp
 * TM_28VREG<1> - 0: inrush clamp in normal function
 *                             1: forcefully disabling inrush clamp
 * TM_28VREG<2> -  0: disable inrush detection
 *                             1: enable inrush detection
 * TM_28VREG<3> - Not used
 * TM_28VREG<4> -  0: clk_out on ddft low
 *                             1: clk_out on ddft toggling
 * TM_28VREG<4> -  0: comp_out on ddft low
 *                             1: comp_out on ddft toggling
 */
#define PDSS_VREG_CTRL_TM_28VREG_MASK                       (0x0001fe00UL) /* <9:16> R:RW:4:PMG1S3_EN */
#define PDSS_VREG_CTRL_TM_28VREG_POS                        (9UL)


/*
 * adft control inputs used to select different analog signal to be brought
 * out on adft1 and adft2
 * bit[17],bit[1],bit[0]
 * 000 - Normal Operation
 * 001 - vref_0p74 on adft1 and vreg_en_vcr on adft2
 * 010 - vfb on adft1 and vreg_cr on adft2
 * 011 - isrc_2p4u on adft1, vreg_cr_rep on adft2
 * 100 - vbus_detect on adft1, vreg_cr_cp on adft2
 * 101 - 20% of vmid_supply on adft1, 20% of charge pump output on adft2
 * 110 - vreg_out on adft1, vreg_out_rdiv on adft2
 * 111 - HiZ
 */
#define PDSS_VREG_CTRL_VREG20_ADFT_CTRL_EXT                 (1UL << 17) /* <17:17> R:RW:0:PMG1S3_EN */


/*
 * trim bits for inrush current detection
 * 00 - 60mA
 * 01 - 148mA
 * 10 - 282mA
 * 11 - 354mA
 */
#define PDSS_VREG_CTRL_VREG28_DET_SEL_LV_MASK               (0x000c0000UL) /* <18:19> R:RW:2:PMG1S3_EN */
#define PDSS_VREG_CTRL_VREG28_DET_SEL_LV_POS                (18UL)


/*
 * USBPD Hard IP SBU #1-4 Switch Register
 */
#define PDSS_SBU_CTRL_ADDRESS(m)                            (0x400a0670UL + ((m) * (0x10000UL)))
#define PDSS_SBU_CTRL(m)                                    (*(volatile uint32_t *)(0x400a0670UL + ((m) * 0x10000UL)))
#define PDSS_SBU_CTRL_DEFAULT                               (0x00000000UL)

/*
 * adft enable, active high
 */
#define PDSS_SBU_CTRL_SBU_ADFT_EN                           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * SBU Switch ADFT Select.  Refer to the s8usbpd_ver3 BROS for more details.
 */
#define PDSS_SBU_CTRL_SBU_ADFT_SEL_MASK                     (0x0000001eUL) /* <1:4> R:RW:0: */
#define PDSS_SBU_CTRL_SBU_ADFT_SEL_POS                      (1UL)


/*
 * SBU1 to AUXP switch enable control, active high
 */
#define PDSS_SBU_CTRL_IN1_OUT1_EN                           (1UL << 5) /* <5:5> R:RW:0: */


/*
 * SBU2 to AUXP switch enable control, active high
 */
#define PDSS_SBU_CTRL_IN2_OUT1_EN                           (1UL << 6) /* <6:6> R:RW:0: */


/*
 * SBU1 to AUXN switch enable control, active high
 */
#define PDSS_SBU_CTRL_IN1_OUT2_EN                           (1UL << 7) /* <7:7> R:RW:0: */


/*
 * SBU2 to AUXN switch enable control, active high
 */
#define PDSS_SBU_CTRL_IN2_OUT2_EN                           (1UL << 8) /* <8:8> R:RW:0: */


/*
 * AUXP 1MOhm Pullup Resistor control, active
 */
#define PDSS_SBU_CTRL_OUT1_1MEG_EN_PU                       (1UL << 9) /* <9:9> R:RW:0: */


/*
 * AUXP 100KOhm Pulldown Resistor control, active high
 */
#define PDSS_SBU_CTRL_OUT1_100K_EN_PD                       (1UL << 10) /* <10:10> R:RW:0: */


/*
 * AUXP 470KOhm Pulldown Resistor control, active high
 */
#define PDSS_SBU_CTRL_OUT1_470K_EN_PD                       (1UL << 11) /* <11:11> R:RW:0: */


/*
 * AUXN 100KOhm Pullup Resistor control, active high
 */
#define PDSS_SBU_CTRL_OUT2_100K_EN_PU                       (1UL << 12) /* <12:12> R:RW:0: */


/*
 * AUXN 4.7MOhm Pulldown Resistor control, active high
 */
#define PDSS_SBU_CTRL_OUT2_4P7MEG_EN_PD                     (1UL << 13) /* <13:13> R:RW:0: */


/*
 * AUXN 1MOhm Pulldown Resistor control, active high
 */
#define PDSS_SBU_CTRL_OUT2_1MEG_EN_PD                       (1UL << 14) /* <14:14> R:RW:0: */


/*
 * USBPD Hard IP DAC #1-4 Register
 */
#define PDSS_ADC_CTRL_ADDRESS(m)                            (0x400a0680UL + ((m) * (0x10000UL)))
#define PDSS_ADC_CTRL(m)                                    (*(volatile uint32_t *)(0x400a0680UL + ((m) * 0x10000UL)))
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
#define PDSS_REFGEN_0_CTRL_ADDRESS(m)                       (0x400a0690UL + ((m) * (0x10000UL)))
#define PDSS_REFGEN_0_CTRL(m)                               (*(volatile uint32_t *)(0x400a0690UL + ((m) * 0x10000UL)))
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
#define PDSS_REFGEN_1_CTRL_ADDRESS(m)                       (0x400a06a0UL + ((m) * (0x10000UL)))
#define PDSS_REFGEN_1_CTRL(m)                               (*(volatile uint32_t *)(0x400a06a0UL + ((m) * 0x10000UL)))
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
#define PDSS_REFGEN_2_CTRL_ADDRESS(m)                       (0x400a06b0UL + ((m) * (0x10000UL)))
#define PDSS_REFGEN_2_CTRL(m)                               (*(volatile uint32_t *)(0x400a06b0UL + ((m) * 0x10000UL)))
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
#define PDSS_REFGEN_3_CTRL_ADDRESS(m)                       (0x400a06c0UL + ((m) * (0x10000UL)))
#define PDSS_REFGEN_3_CTRL(m)                               (*(volatile uint32_t *)(0x400a06c0UL + ((m) * 0x10000UL)))
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
#define PDSS_REFGEN_4_CTRL_ADDRESS(m)                       (0x400a06d0UL + ((m) * (0x10000UL)))
#define PDSS_REFGEN_4_CTRL(m)                               (*(volatile uint32_t *)(0x400a06d0UL + ((m) * 0x10000UL)))
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
#define PDSS_BCH_DET_0_CTRL_ADDRESS(m)                      (0x400a0700UL + ((m) * (0x10000UL)))
#define PDSS_BCH_DET_0_CTRL(m)                              (*(volatile uint32_t *)(0x400a0700UL + ((m) * 0x10000UL)))
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
#define PDSS_BCH_DET_1_CTRL_ADDRESS(m)                      (0x400a0710UL + ((m) * (0x10000UL)))
#define PDSS_BCH_DET_1_CTRL(m)                              (*(volatile uint32_t *)(0x400a0710UL + ((m) * 0x10000UL)))
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


#define PDSS_BCH_DET_1_CTRL_ISINK_CAL_DP_EN                 (1UL << 30) /* <30:30> R:RW:0:PMG1S3_EN */


#define PDSS_BCH_DET_1_CTRL_ISINK_CAL_DM_EN                 (1UL << 31) /* <31:31> R:RW:0:PMG1S3_EN */


/*
 * USBPD Hard IP VBUS Discharge SHV #1-8 Register0
 */
#define PDSS_DISCHG_SHV_CTRL_ADDRESS(m)                     (0x400a0790UL + ((m) * (0x10000UL)))
#define PDSS_DISCHG_SHV_CTRL(m)                             (*(volatile uint32_t *)(0x400a0790UL + ((m) * 0x10000UL)))
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
#define PDSS_COMP_CTRL_ADDRESS(m,n)                         (0x400a07d0UL + ((m) * (0x10000UL)) + ((n) * (0x0004UL)))
#define PDSS_COMP_CTRL(m,n)                                 (*(volatile uint32_t *)(0x400a07d0UL + ((m) * (0x10000UL)) + ((n) * 0x0004)))
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
 * USBPD Hard IP Regulator control Register
 */
#define PDSS_REG_CONTROL_ADDRESS(m)                         (0x400a0864UL + ((m) * (0x10000UL)))
#define PDSS_REG_CONTROL(m)                                 (*(volatile uint32_t *)(0x400a0864UL + ((m) * 0x10000UL)))
#define PDSS_REG_CONTROL_DEFAULT                            (0x00000000UL)

/*
 * Priority signal to turn on either the regulator on VBUS1 or VBUS2
 * when VBUS_PRIORITY = 0 VBUS1 Regulator is selected by default when both
 * VBUS1 and VBUS2 is present
 * when VBUS_PRIORITY = 1 VBUS2 Regulator is selected by default when both
 * VBUS1 and VBUS2 is present
 */
#define PDSS_REG_CONTROL_VBUS_PRIORITY                      (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Output Isolation control. Active Low
 * 0 : All digital outputs are forced to known value
 */
#define PDSS_REG_CONTROL_REG_CNTRL_ISO_N                    (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Test modes to change the sink current
 * T_REG_CONTROL[0] = 1 : isink<9:0> doubled
 * T_REG_CONTROL[1] = 1 : isink<14:10> doubled
 * T_REG_CONTROL[2] = 1 : isink<9:0> current halved
 * T_REG_CONTROL[3] = 1 : isink<14:10> current halved
 */
#define PDSS_REG_CONTROL_T_REG_CONTROL_MASK                 (0x0000003cUL) /* <2:5> R:RW:0: */
#define PDSS_REG_CONTROL_T_REG_CONTROL_POS                  (2UL)


/*
 * Bypasses the vsys_good_acc_hv signal when set to 1
 * CCG6 *A:
 * BYPASS_VSYS_GOOD_ACC : 1  output depenedent on vsys_good_acc_hv
 * BYPASS_VSYS_GOOD_ACC : 0 outputs independent of vsys_good_acc_hv
 * CCG5, CCG6*:
 * BYPASS_VSYS_GOOD_ACC : 0  output depenedent on vsys_good_acc_hv
 * BYPASS_VSYS_GOOD_ACC : 1 outputs independent of vsys_good_acc_hv
 */
#define PDSS_REG_CONTROL_BYPASS_VSYS_GOOD_ACC               (1UL << 6) /* <6:6> R:RW:0: */


/*
 * USBPD Hard IP VCONN20 V5V Power FET Register
 */
#define PDSS_VCONN20_CTRL_ADDRESS(m)                        (0x400a0868UL + ((m) * (0x10000UL)))
#define PDSS_VCONN20_CTRL(m)                                (*(volatile uint32_t *)(0x400a0868UL + ((m) * 0x10000UL)))
#define PDSS_VCONN20_CTRL_DEFAULT                           (0x00000000UL)

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
 */
#define PDSS_VCONN20_CTRL_VCONN20_ADFT_CTRL_MASK            (0x01f00000UL) /* <20:24> R:RW:0: */
#define PDSS_VCONN20_CTRL_VCONN20_ADFT_CTRL_POS             (20UL)


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
#define PDSS_PUMP5V_CTRL_ADDRESS(m,n)                       (0x400a086cUL + ((m) * (0x10000UL)) + ((n) * (0x0004UL)))
#define PDSS_PUMP5V_CTRL(m,n)                               (*(volatile uint32_t *)(0x400a086cUL + ((m) * (0x10000UL)) + ((n) * 0x0004)))
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
 * USBPD Hard IP CSA SCP Register0
 */
#define PDSS_CSA_SCP_0_CTRL_ADDRESS(m)                      (0x400a08bcUL + ((m) * (0x10000UL)))
#define PDSS_CSA_SCP_0_CTRL(m)                              (*(volatile uint32_t *)(0x400a08bcUL + ((m) * 0x10000UL)))
#define PDSS_CSA_SCP_0_CTRL_DEFAULT                         (0xc0000045UL)

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
#define PDSS_CSA_SCP_1_CTRL_ADDRESS(m)                      (0x400a08c0UL + ((m) * (0x10000UL)))
#define PDSS_CSA_SCP_1_CTRL(m)                              (*(volatile uint32_t *)(0x400a08c0UL + ((m) * 0x10000UL)))
#define PDSS_CSA_SCP_1_CTRL_DEFAULT                         (0x00000000UL)

/*
 * t_csa_scp<1:0>=0 --> Reserved
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
 * t_csa_scp<6> -  0 , output latch on scp hv/lv outputs
 *                          1,  output latch on scp hv/lv output in bypass
 * mode (i.e. no latch funciton on SCP output)
 * t_csa_scp<7> -  0 , offset dac current LSB increased from 36nA to about
 * 90nA
 *                          1 , offset dac current LSB same as CCG6 SCP 36nA
 * t_csa_scp<8> -  0 = OCP comparator filter cap disabled
 *                          1 = OCP comparator filter cap enabled
 * t_csa_scp<9> -  0 = SCP comparator filter cap disabled
 *                          1 = SCP comparator filter cap enabled
 * t_csa_scp<10>     1 Short OCP 200k filter resistor
 * t_csa_scp<11>     --> Reserved
 */
#define PDSS_CSA_SCP_1_CTRL_ACG1F_T_CSA_SCP_MASK            (0x000fff00UL) /* <8:19> R:RW:0:ACG1F_CCG6DF_EN */
#define PDSS_CSA_SCP_1_CTRL_ACG1F_T_CSA_SCP_POS             (8UL)


/*
 * USBPD Hard IP CSA RCP Register0
 */
#define PDSS_CSA_RCP_0_CTRL_ADDRESS(m)                      (0x400a08c4UL + ((m) * (0x10000UL)))
#define PDSS_CSA_RCP_0_CTRL(m)                              (*(volatile uint32_t *)(0x400a08c4UL + ((m) * 0x10000UL)))
#define PDSS_CSA_RCP_0_CTRL_DEFAULT                         (0xe0000047UL)

/*
 * Selects the nominal voltage gain of 100
 */
#define PDSS_CSA_RCP_0_CTRL_AV1_MASK                        (0x00000007UL) /* <0:2> R:RW:7: */
#define PDSS_CSA_RCP_0_CTRL_AV1_POS                         (0UL)


/*
 * Configuration: 1 - Out_d used, 0 - Out_d=LOW
 */
#define PDSS_CSA_RCP_0_CTRL_SEL_OUT_D                       (1UL << 6) /* <6:6> R:RW:1: */


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_CSA_RCP_0_CTRL_CSA_ISO_N                       (1UL << 7) /* <7:7> R:RW:0: */


/*
 * dft control inputs used to connect various analog internal signals to
 * atstio.
 * See BROS doc for more info.
 * When
 * 1. csa_adft_en_lv = 1, then CSA block ADFT
 * 2. rcp_adft_en_lv = 1, then RCP comparator and VBUS detect block ADFT
 */
#define PDSS_CSA_RCP_0_CTRL_CSA_ADFT_CTRL_MASK              (0x00000f00UL) /* <8:11> R:RW:0: */
#define PDSS_CSA_RCP_0_CTRL_CSA_ADFT_CTRL_POS               (8UL)


/*
 * Hysteresis enable for Stage 2
 */
#define PDSS_CSA_RCP_0_CTRL_HYST_EN                         (1UL << 28) /* <28:28> R:RW:0: */


/*
 * Trim control for analog bandwidth- default is maximum bandwith
 * 11 - default (16 *7/8 of HV native cap)
 * 10 - 12* 7/8 of HV native cap + default caps
 * 01 - 24* 7/8 of HV native cap + default caps
 * 00 - 36* 7/8 of HV native cap + default caps
 */
#define PDSS_CSA_RCP_0_CTRL_BW_MASK                         (0x60000000UL) /* <29:30> R:RW:3: */
#define PDSS_CSA_RCP_0_CTRL_BW_POS                          (29UL)


/*
 * Block power down input (CSA, RCP & VBUS detect)
 * 1 - All analog and DC paths cut off, outputs forced to known value
 * 0 - Normal functionality
 */
#define PDSS_CSA_RCP_0_CTRL_PD_CSA                          (1UL << 31) /* <31:31> R:RW:1: */


/*
 * USBPD Hard IP CSA RCP Register1
 */
#define PDSS_CSA_RCP_1_CTRL_ADDRESS(m)                      (0x400a08c8UL + ((m) * (0x10000UL)))
#define PDSS_CSA_RCP_1_CTRL(m)                              (*(volatile uint32_t *)(0x400a08c8UL + ((m) * 0x10000UL)))
#define PDSS_CSA_RCP_1_CTRL_DEFAULT                         (0x00180081UL)

/*
 * Enables the RCP comparator and the related bias circuitry. Timing requirements
 * are follows:
 * After making RCP_EN_LV=0->1 , assert Reg:TRIM_CSA_RCP1_4 : RCP_TRIM_LV_1[5]=
 * 0->1 after minimum delay of 20us ( this is RCP comparator output latch
 * reset)
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_EN_LV                       (1UL << 0) /* <0:0> R:RW:1: */


/*
 * RCP CSA Block power down input
 * 0 - All analog and DC paths cut off, outputs forced to known value
 * 1 - Normal functionality
 * Timing requirements are follows:
 * CSA_EN_LV=0->1
 * Reg: TRIM_CSA_RCP1_4 : RCP_TRIM_LV_1[7] =0->1 after minimum delay of 100us
 * from CSA_EN_LV=0->1 while enabling the block (this is basically RCP CSA
 * output latch reset)
 */
#define PDSS_CSA_RCP_1_CTRL_CSA_EN_LV                       (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Enables the ADFT for the RCP comparator & VBUS OVP detect comparators
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_ADFT_EN_LV                  (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Enables the Ring oscillator for autozero mode of RCP comparator. Trimming
 * requirements are follows:
 * RCP_EN_LV=0>1
 * RCP_AUTOZERO_EN_LV=0 -->1 after minimum delay of 10us from  RCP_EN_LV=0-->1
 * ( to avoid false gitch)
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_AUTOZERO_EN_LV              (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Enable bit for the ADFT of the CSA section of the block
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_CSA_ADFT_EN_LV              (1UL << 4) /* <4:4> R:RW:0: */


/*
 * MSB trim bit  to vary glitch filter delay on RCP output  (for delay see
 * the next line)
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_CSA_HYST_R_EN_LV            (1UL << 5) /* <5:5> R:RW:0: */


/*
 * LSB trim bit  to vary glitch filter delay on RCP output . See the delay
 * as below
 * 00 - 135nS glitch filter
 * 01 - 353nS glitch filter
 * 10 - 585nS glitch filter
 * 11 - 775nS glitch filter
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_HYST_F_EN_LV                (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Enables the 5.75V comparator on CSN side (this comparator added for HP
 * so that provide sides doesn't go above 5.75+/-200mV)
 * Timing requirements are follows:
 * RCP_VBUS_OVP_EN_LV=0->1
 * Reg: TRIM_CSA_RCP1_4 : RCP_TRIM_LV_1[6] =0->1 after minimum delay min
 * 20us from RCP_VBUS_OVP_EN_LV=0->1 to observe output
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_VBUS_OVP_EN_LV              (1UL << 7) /* <7:7> R:RW:1: */


/*
 * MSB trim bit  to vary glitch filter delay on 5.75V comp output  (for delay
 * see the next line)
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_VBUS_OVP_HYST_R_EN_LV       (1UL << 8) /* <8:8> R:RW:0: */


/*
 * LSB trim bit  to vary glitch filter delay on 5.75V comp output . See the
 * delay as below
 * 00 - 135nS glitch filter
 * 01 - 353nS glitch filter
 * 10 - 585nS glitch filter
 * 11 - 775nS glitch filter
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_VBUS_OVP_HYST_F_EN_LV       (1UL << 9) /* <9:9> R:RW:0: */


/*
 * T_CSA_RCP_LV[0]=1, Double the RCP Comparator bias current
 * T_CSA_RCP_LV[1]=1, Double the vbus 5.75V Comparator bias current
 * T_CSA_RCP_LV[2]=1, Select the 10 % of  vbus resistor divider in 5.75V
 * comparator stack
 * T_CSA_RCP_LV[3]=1, it will allow putting offset bits on both CSP and CSN
 * sides as in CCG3 HSCSA
 * T_CSA_RCP_LV[4]=1, all RCP hv/lv output (RCP CSA, RCP comp and RCP 5.75V
 * comp) latch in bypass mode
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_T_CSA_RCP_LV_MASK           (0x0003fc00UL) /* <10:17> R:RW:0: */
#define PDSS_CSA_RCP_1_CTRL_RCP_T_CSA_RCP_LV_POS            (10UL)


/*
 * To bring out the various clock outputs of the ring oscillator
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_RINGOSC_DFT_EN_LV           (1UL << 18) /* <18:18> R:RW:0: */


/*
 * To select the output clock from the ring oscillator to be used for Auto-Zeroing
 */
#define PDSS_CSA_RCP_1_CTRL_RCP_RINGOSC_CLKSEL_LV_MASK      (0x00180000UL) /* <19:20> R:RW:3: */
#define PDSS_CSA_RCP_1_CTRL_RCP_RINGOSC_CLKSEL_LV_POS       (19UL)


/*
 * S8USBPDV2 Hard IP ACG1F NGDO Register 0 (Only for ACG1F or CCG6DF or PMG1S3)
 */
#define PDSS_V2_NGDO_0_CTRL_ADDRESS(m)                      (0x400a20c8UL + ((m) * (0x10000UL)))
#define PDSS_V2_NGDO_0_CTRL(m)                              (*(volatile uint32_t *)(0x400a20c8UL + ((m) * 0x10000UL)))
#define PDSS_V2_NGDO_0_CTRL_DEFAULT                         (0x381c0400UL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value.
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_ISO_N                      (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Enable signal for the bias circuitry and slew rate block
 * ngdo_en = 0 ; disabled
 * ngdo_en = 1 ; enabled
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_EN_LV                      (1UL << 1) /* <1:1> R:RW:0:ACG1F_PMG1S3_EN */


/*
 * Only for ACG1F. For CCG6DF, see V2_NGDO_0_CP_EN_CTRL and V2_NGDO_1_CP_EN_CTRL
 * Charge-pump ouptut control;
 * cp_en = 0 ; cp output = vbus
 * cp_en = 1 ; cp output = driven by cp action
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_CP_EN                      (1UL << 3) /* <3:3> R:RW:0:ACG1F_PMG1S3_EN */


/*
 * Enable signal for adft.
 * adft_en = 0 ; ADFT disabled, normal functionality
 * adft_en = 1 ; ADFT network enabled
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_ADFT_EN                    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Forced RCP fault to pulldown gatedriver output
 * 1= Force RCP fault. Fast pulldown enabled on G0.
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_FORCE_RCP            (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Forced SCP fault to pulldown gatedriver output
 * 1= Force SCP fault. Fast pulldown enabled on G1.
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_FORCE_SCP            (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Keep off Control
 * 0= Keep off control circuit enabled
 * 1= Keep off control circuit disabled
 */
#define PDSS_V2_NGDO_0_CTRL_KEEP_OFF_DISABLE                (1UL << 7) /* <7:7> R:RW:0:ACG1F_PMG1S3_EN */


/*
 * PMG1S3:
 * 000 --> 0
 * 001 --> 5u
 * 010 --> 8.5u
 * 011 --> 11.5u
 * 100 --> 15.3u
 * 101 --> 18u
 * 110 --> 21.5u
 * 111 --> 24u
 *
 * CCG6DF/CCG6SF/ACG1F: Programmable delay control for pulldown during Normal
 * Turn OFF
 * 000 --> 0
 * 001 --> 3.57u
 * 010 --> 6.1u
 * 011 --> 8.27u
 * 100 --> 11.14u
 * 101 --> 13.23u
 * 110 --> 15.57u
 * 111 --> 17.6u
 */
#define PDSS_V2_NGDO_0_CTRL_T_SW_OFF_DELAY_MASK             (0x00000700UL) /* <8:10> R:RW:4: */
#define PDSS_V2_NGDO_0_CTRL_T_SW_OFF_DELAY_POS              (8UL)


/*
 * Programmability for external NFET gate charging current (default 0xE=
 * 2.1u)
 * LSB current(step size) = 150nA
 * Max setting allowed = 0x1C
 */
#define PDSS_V2_NGDO_0_CTRL_V2_NGDO_SLEW_CTRL_MASK          (0x007e0000UL) /* <17:22> R:RW:14: */
#define PDSS_V2_NGDO_0_CTRL_V2_NGDO_SLEW_CTRL_POS           (17UL)


/*
 * ADFT selection pins.
 * [PMG1S3]
 * CTRL - adft0,adft1
 * 000 - Hi-z,Hi-z
 * 001 - vpump_vfb,Hi-z
 * 010 - vpump_5p,Hi-z
 * 011 - ugbop, ubgip
 * 100 - Reserved,Reserved
 * 101 - Reserved,Reserved
 * 110 - Reserved,Reserved
 * 111- Reserved,Reserved
 * ------------------------------------
 * CCG6DF/CCG6SF/ACG1F:
 * ADFT selection pins.
 * CTRL - adft0,adft1
 * 000 - Hi-z,Hi-z
 * 001 - vpump_reg_adft,Hi-z
 * 010 - vpump_10p,Hi-z
 * 011 - ugbop, ubgip
 * 100 - Reserved,Reserved
 * 101 - Reserved,Reserved
 * 110 - Reserved,Reserved
 * 111- Reserved,Reserved
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_ADFT_CTRL_MASK             (0x07800000UL) /* <23:26> R:RW:0: */
#define PDSS_V2_NGDO_0_CTRL_NGDO_ADFT_CTRL_POS              (23UL)


/*
 * 0: Disable rcp fault to pulldown gate driver output
 * 1: Allow rcp fault to pulldown gate driver output
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_RCP_EN               (1UL << 27) /* <27:27> R:RW:1: */


/*
 * 0: Disable scp fault to pulldown gate driver output
 * 1: Allow scp fault to pulldown gate driver output
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_SCP_EN               (1UL << 28) /* <28:28> R:RW:1: */


/*
 * [PMG1S3] UNUSED
 * -----------------------------------
 * [ACG1F/CCG6DF/CCG6SF]
 * 0: Disable  vbus_ov fault to pulldown gate driver output
 * 1: To allow vbus_ov fault to pulldown gate driver output
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_VBUS_OV_EN           (1UL << 29) /* <29:29> R:RW:1: */


/*
 * Only for ACG1F. For CCG6DF, see V2_NGDO_0_GDRV_EN_CTRL and V2_NGDO_1_GDRV_EN_CTRL
 * Gatedriver Enable.
 * gdrv_en = 0 The gate control output is pulled low
 * gdrv_en = 1 The gate control output is  controlled by slew rate block
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_GRV_EN                     (1UL << 30) /* <30:30> R:RW:0:ACG1F_PMG1S3_EN */


/*
 * External clock selection
 * t_ext_clk_sel = 0 Internal clock used
 * t_ext_clk_sel = 1 External clock used
 */
#define PDSS_V2_NGDO_0_CTRL_NGDO_T_EXT_CLK_SEL              (1UL << 31) /* <31:31> R:RW:0: */


/*
 * S8USBPDV2 Hard IP ACG1F NGDO Register 1 (Only for ACG1F or CCG6DF or PMG1S3)
 */
#define PDSS_V2_NGDO_1_CTRL_ADDRESS(m)                      (0x400a20ccUL + ((m) * (0x10000UL)))
#define PDSS_V2_NGDO_1_CTRL(m)                              (*(volatile uint32_t *)(0x400a20ccUL + ((m) * 0x10000UL)))
#define PDSS_V2_NGDO_1_CTRL_DEFAULT                         (0x00000600UL)

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
 * 11:9 Configuration bits for pulse width of 1us pulse based SCP pull-down
 * 12 1: increases rcp fault pd strength by 2X
 * 13 1: decreases rcp fault pd strength by 6X
 * 14 1: Enables RCP fast pulldown on G0 during normal OFF
 * 15 1: ibias in the idac will be gated by ngdo_en
 * - - - - - - - - - - - - - - - - - - - -
 * PMG1S3
 * <1:0> --> Trim bits for SCP G1 PD strength (Default = 2'b10) [00 : 3x,
 * 01 : x, 10 : 6x, 11 : 4x]
 * <2> --> 1: doubles the backup oscillator frequency Default=0
 * <3> --> 1: prioritizes SCP over RCP    Default=0
 *               0: prioritizes RCP over SCP"
 * <4> --> 1: disables the G1 gdrv pulse pull down during normal OFF Default=0
 * <5> --> 1: disables fault SCP G1 pull-down Default=0
 * <6> --> 1: enables static(instead of pulse) fault SCP G1 pull-down Default=0
 * <7> --> 1: Use back-up FB scheme for CP (comparator based clock gating)
 * <8> --> 1: Use CP in openloop
 * <11:9> --> trim bits for pulse width of pulse based SCP pull-down (use
 * count of 3 for 1.6us width)
 * <13:12> --> Trim bits for RCP G0 PD strength (Default = 2'b01) [00 : 4x,
 * 01 : 6x, 10 : x, 11 : 3x]
 * <14> --> 1: enables RCP fast pull down on G0 during normal OFF
 * <15> --> 1: ibias in the idac will be gated by ngdo_en  Default=0
 *
 */
#define PDSS_V2_NGDO_1_CTRL_V2_NGDO_TM_NGDO_MASK            (0x0000ffffUL) /* <0:15> R:RW:1536: */
#define PDSS_V2_NGDO_1_CTRL_V2_NGDO_TM_NGDO_POS             (0UL)


/*
 * <18:16> --> trim bits for pulse width of pulse based RCP pull-down (use
 * count of 3 for 1us width)
 * <19> --> 1 : Reduce CP boost voltage to 3.5V (Default =0)
 * <20> --> 1 : Double G0 normal-off PD current (Default =0)
 * <22:21> -->  Trim bits for CP comparator hysteresis (Default = 2'b10)
 * <23> --> UNUSED
 */
#define PDSS_V2_NGDO_1_CTRL_V2_NGDO_TM_NGDO_EXT_MASK        (0x00ff0000UL) /* <16:23> R:RW:0:PMG1S3_EN */
#define PDSS_V2_NGDO_1_CTRL_V2_NGDO_TM_NGDO_EXT_POS         (16UL)


/*
 * Enable the charging of G1 (VBUS_C side) gate
 * 1: G1 is allowed to charge up
 * 0 : G1 is pulled low to gnd
 */
#define PDSS_V2_NGDO_1_CTRL_V2_NGDO_EN_G1_CHRG              (1UL << 24) /* <24:24> R:RW:0:PMG1S3_EN */


/*
 * S8USBPDV2_PMG1S3 SCP RCP Control Register 0
 */
#define PDSS_SCP_RCP_0_CTRL_ADDRESS(m)                      (0x400a2508UL + ((m) * (0x10000UL)))
#define PDSS_SCP_RCP_0_CTRL(m)                              (*(volatile uint32_t *)(0x400a2508UL + ((m) * 0x10000UL)))
#define PDSS_SCP_RCP_0_CTRL_DEFAULT                         (0x0000100eUL)

/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_ISO_N                   (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Power-down for Short Circuit protection. PD=0 enables scp  , PD=1 disables
 * scp
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD_SCP                  (1UL << 1) /* <1:1> R:RW:1: */


/*
 * Power-down for Over current protection. PD=0 enables ocp  , PD=1 disables
 * ocp
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD_OCP                  (1UL << 2) /* <2:2> R:RW:1: */


/*
 * Power-down for reverse current protection. PD=0 enables rcp  , PD=1 disables
 * rcp
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD_RCP                  (1UL << 3) /* <3:3> R:RW:1: */


/*
 * RCP trip point selection .  0 -->  800mA , 1 --> 400mA
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_SEL_RCP_400MA         (1UL << 4) /* <4:4> R:RW:0: */


/*
 * SCP trip point selection .  0= 6A , 1=10A
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_SEL_SCP_10A           (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Enables the 5.75V comparator on CSP side (this comparator added for HP
 * so that provide sides doesn't go above 5.75+/-200mV)
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_VBUS_OVP_EN             (1UL << 6) /* <6:6> R:RW:0: */


/*
 * MSB trim bit  to vary glitch filter delay on 5.75V comp output  (for delay
 * see the next line)
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_VBUS_OVP_HYST_R_EN      (1UL << 7) /* <7:7> R:RW:0: */


/*
 * LSB trim bit  to vary glitch filter delay on 5.75V comp output . See the
 * delay as below
 * 00 - 135nS glitch filter
 * 01 - 353nS glitch filter
 * 10 - 585nS glitch filter
 * 11 - 775nS glitch filter
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_VBUS_OVP_HYST_F_EN      (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Hysteresis enable for scp , rcp and ocp comparators
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_HYST_EN                 (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 0 --> SCP  output latch in reset mode.
 * 1 --> SCP output latch in sample mode.
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_SCP_RST_LATCH_N       (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 0 --> RCP  output latch in reset mode.
 * 1 --> RCP output latch in sample mode.
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_RCP_RST_LATCH_N       (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Master power-down signal
 */
#define PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD                      (1UL << 12) /* <12:12> R:RW:1: */


/*
 * S8USBPDV2_PMG1S3 SCP RCP Control Register 1
 */
#define PDSS_SCP_RCP_1_CTRL_ADDRESS(m)                      (0x400a250cUL + ((m) * (0x10000UL)))
#define PDSS_SCP_RCP_1_CTRL(m)                              (*(volatile uint32_t *)(0x400a250cUL + ((m) * 0x10000UL)))
#define PDSS_SCP_RCP_1_CTRL_DEFAULT                         (0x00000000UL)

/*
 * ADFT master enable signal
 */
#define PDSS_SCP_RCP_1_CTRL_SCP_RCP_ADFT_EN                 (1UL << 0) /* <0:0> R:RW:0: */


/*
 * ADFT control inputs used to connect various analog internal signals to
 * ADFT buses
 */
#define PDSS_SCP_RCP_1_CTRL_SCP_RCP_ADFT_CTRL_MASK          (0x000000fcUL) /* <2:7> R:RW:0: */
#define PDSS_SCP_RCP_1_CTRL_SCP_RCP_ADFT_CTRL_POS           (2UL)


/*
 * Trim bits for SCP_RCP                                                
 *                              t_scp_rcp<2:0> --> SCP filter delay trim
 * t_scp_rcp<3>   --> VBUS OVP comp bias trim
 * t_scp_rcp<4>   --> RCP comp bias trim
 * t_scp_rcp<5>   --> SCP out latch bypass
 * t_scp_rcp<6>   --> VBUS OVP comp latch bypass
 * t_scp_rcp<7>   --> RCP comp latch bypass
 * t_scp_rcp<8>   --> RCP hysteresis width trim
 * t_scp_rcp<9>   --> OCP hysteresis width trim
 *                        0 => default width
 *                        1 => 2x width
 * t_scp_rcp<10>  --> RCP filter delay trim
 * t_scp_rcp<11>  --> SCP hysteresis width trim
 *                        0 => default width
 *                        1 => 2x width
 * t_scp_rcp<13:12> --> VBUS OVP comp resistive divider tap point selt_scp_rcp<2:0>
 * --> SCP filter delay trim
 *
 *
 */
#define PDSS_SCP_RCP_1_CTRL_SCP_RCP_T_SCP_RCP_MASK          (0xffff0000UL) /* <16:31> R:RW:0: */
#define PDSS_SCP_RCP_1_CTRL_SCP_RCP_T_SCP_RCP_POS           (16UL)


/*
 * DIGITAL FLIP MUX Control Register
 */
#define PDSS_FMX_CTRL_ADDRESS(m)                            (0x400a2510UL + ((m) * (0x10000UL)))
#define PDSS_FMX_CTRL(m)                                    (*(volatile uint32_t *)(0x400a2510UL + ((m) * 0x10000UL)))
#define PDSS_FMX_CTRL_DEFAULT                               (0x000000aaUL)

/*
 * UpStream Port Mux Select.
 *
 * MUX1 - UPS_OUT[1] (in PMG1S3 this is connected to SBU[1])
 * UPS_MUX_SEL[3:2]
 * 00 - dns_in[0]
 * 01 - dns_in[1]
 * 10 - dns_in[2]
 * 11 - dns_in[3]
 *
 * MUX0 - UPS_OUT[0] (in PMG1S3 this is connected to SBU[0])
 * UPS_MUX_SEL[1:0]
 * 00 - dns_in[0]
 * 01 - dns_in[1]
 * 10 - dns_in[2]
 * 11 - dns_in[3]
 */
#define PDSS_FMX_CTRL_UPS_MUX_SEL_MASK                      (0x0000000fUL) /* <0:3> R:RW:10: */
#define PDSS_FMX_CTRL_UPS_MUX_SEL_POS                       (0UL)


/*
 * DownStream Port Mux Select.
 *
 * MUX1 - DNS_OUT[3] (in PMG1S3 this is connected to LSTX)
 * DNS_MUX_SEL[7:6]
 * 00 - ups_in[0]
 * 01 - ups_in[1]
 * 10 - dns_in[0]
 * 11 - dns_in[1]
 *
 * MUX0 - DNS_OUT[2] (in PMG1S3 this is connected to LSRX)
 * DNS_MUX_SEL[5:4]
 * 00 - ups_in[0]
 * 01 - ups_in[1]
 * 10 - dns_in[0]
 * 11 - dns_in[1]
 *
 * MUX1 - DNS_OUT[1] (in PMG1S3 this is connected to DBG2)
 * DNS_MUX_SEL[3:2]
 * 00 - ups_in[0]
 * 01 - ups_in[1]
 * 10 - dns_in[2]
 * 11 - dns_in[3]
 *
 * MUX0 - DNS_OUT[0] (in PMG1S3 this is connected to DBG1)
 * DNS_MUX_SEL[1:0]
 * 00 - ups_in[0]
 * 01 - ups_in[1]
 * 10 - dns_in[2]
 * 11 - dns_in[3]
 *
 */
#define PDSS_FMX_CTRL_DNS_MUX_SEL_MASK                      (0x00000ff0UL) /* <4:11> R:RW:10: */
#define PDSS_FMX_CTRL_DNS_MUX_SEL_POS                       (4UL)


/*
 * UpStream Port Output Enable.
 *
 * Bit[1] - MUX1 (in PMG1S3 this is connected to SBU[1])
 * 0 - Ouptut Enabled
 * 1 - Output Disabled
 *
 * Bit[0] - MUX0 (in PMG1S3 this is connected to SBU[0])
 * 0 - Ouptut Enabled
 * 1 - Output Disabled
 */
#define PDSS_FMX_CTRL_UPS_OUT_EN_MASK                       (0x0c000000UL) /* <26:27> R:RW:0: */
#define PDSS_FMX_CTRL_UPS_OUT_EN_POS                        (26UL)


/*
 * DownStream Port Output Enable.
 * Bit[3] - MUX3 (in PMG1S3 this is connected to LSTX)
 * 0 - Ouptut Enabled
 * 1 - Output Disabled
 *
 * Bit[2] - MUX2 (in PMG1S3 this is connected to LSRX)
 * 0 - Ouptut Enabled
 * 1 - Output Disabled
 *
 * Bit[1] - MUX1 (in PMG1S3 this is connected to DBG2)
 * 0 - Ouptut Enabled
 * 1 - Output Disabled
 *
 * Bit[0] - MUX0 (in PMG1S3 this is connected to DBG1)
 * 0 - Ouptut Enabled
 * 1 - Output Disabled
 */
#define PDSS_FMX_CTRL_DNS_OUT_EN_MASK                       (0xf0000000UL) /* <28:31> R:RW:0: */
#define PDSS_FMX_CTRL_DNS_OUT_EN_POS                        (28UL)


/*
 * RAMBIST Interface Mux Control Register
 */
#define PDSS_RAMBIST_MUX_CTRL_ADDRESS(m)                    (0x400a251cUL + ((m) * (0x10000UL)))
#define PDSS_RAMBIST_MUX_CTRL(m)                            (*(volatile uint32_t *)(0x400a251cUL + ((m) * 0x10000UL)))
#define PDSS_RAMBIST_MUX_CTRL_DEFAULT                       (0x00000000UL)

/*
 * RAMBIST Mux Select
 * 000 - None
 * 001 - TX_SRAM0
 * 010 - TX_SRAM1
 * 011 - RX_SRAM0
 * 100 - RX_SRAM1
 * 101 - PEAK_SRAM
 */
#define PDSS_RAMBIST_MUX_CTRL_RB_MUX_SEL_MASK               (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_RAMBIST_MUX_CTRL_RB_MUX_SEL_POS                (0UL)


/*
 * S8USBPDV2_PMG1S3 SBU SW #1-4 Control Register
 */
#define PDSS_SBU_NEW_CTRL_ADDRESS(m,n)                      (0x400a2520UL + ((m) * (0x10000UL)) + ((n) * (0x0004UL)))
#define PDSS_SBU_NEW_CTRL(m,n)                              (*(volatile uint32_t *)(0x400a2520UL + ((m) * (0x10000UL)) + ((n) * 0x0004)))
#define PDSS_SBU_NEW_CTRL_DEFAULT                           (0x00000000UL)

/*
 * ADFT enable, active high
 */
#define PDSS_SBU_NEW_CTRL_SBU_NEW_ADFT_EN                   (1UL << 0) /* <0:0> R:RW:0: */


/*
 * SBU Switch ADFT Select.  Refer to the s8usbpd_ver3 BROS for more details.
 */
#define PDSS_SBU_NEW_CTRL_SBU_NEW_ADFT_SEL_MASK             (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_SBU_NEW_CTRL_SBU_NEW_ADFT_SEL_POS              (1UL)


/*
 * IN1 to OUT1 switch enable control, active high
 */
#define PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT1_EN               (1UL << 3) /* <3:3> R:RW:0: */


/*
 * IN2 to OUT1 switch enable control, active high
 */
#define PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT1_EN               (1UL << 4) /* <4:4> R:RW:0: */


/*
 * IN1 to OUT2 switch enable control, active high
 */
#define PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT2_EN               (1UL << 5) /* <5:5> R:RW:0: */


/*
 * IN2 to OUT2 switch enable control, active high
 */
#define PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT2_EN               (1UL << 6) /* <6:6> R:RW:0: */


/*
 * PMG1S3 REFGEN Calibrate Register
 */
#define PDSS_REFGEN_CAL_ADDRESS(m)                          (0x400a2530UL + ((m) * (0x10000UL)))
#define PDSS_REFGEN_CAL(m)                                  (*(volatile uint32_t *)(0x400a2530UL + ((m) * 0x10000UL)))
#define PDSS_REFGEN_CAL_DEFAULT                             (0x00000000UL)

/*
 * There are four bits declared for maximum of REFGEN_NUM. Every Bit is indepently
 * connected every refgen instance.
 * Calibrate bit for internal clock generator
 * 0: No calibration
 * 1: Higher Frequency
 */
#define PDSS_REFGEN_CAL_REFGEN_ICLK_CAL_MASK                (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_REFGEN_CAL_REFGEN_ICLK_CAL_POS                 (0UL)


/*
 * PMG1S3 VCONN Calibrate Register
 */
#define PDSS_VCONN_CAL_ADDRESS(m)                           (0x400a2534UL + ((m) * (0x10000UL)))
#define PDSS_VCONN_CAL(m)                                   (*(volatile uint32_t *)(0x400a2534UL + ((m) * 0x10000UL)))
#define PDSS_VCONN_CAL_DEFAULT                              (0x00000000UL)

/*
 * Calibrate the charge pump output voltage
 * VCONN_PUMP_CAL [3:0] --> vboost=(vpump-v5v)
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
#define PDSS_VCONN_CAL_VCONN_PUMP_CAL_MASK                  (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_VCONN_CAL_VCONN_PUMP_CAL_POS                   (0UL)


/*
 * Calibrate the charge pump oscillator frequency,pump regulator bias current
 *
 * Calibrate charge pump Oscillator current (VCONN20_OSC_CAL<2:0>)
 * 000 --> 2.4uA (Default)
 * 001 --> 1.8uA
 * 010 --> 1.2uA
 * 011 --> 0.6uA
 * 100 --> 4.8uA
 * 101 --> 4.2uA
 * 110 --> 3.6uA
 * 111 --> 3.0uA
 *
 * Calibrate charge pump Regulator iload (VCONN20_OSC_CAL<3>)
 * 0 --> 5uA (Default)
 * 1 --> 0
 *
 * Calibrate charge pump Regulator bias current (VCONN20_OSC_CAL<5:4>)
 * 00 --> 4.8uA (Default)
 * 01 --> 2.4uA
 * 10 --> 9.6uA
 * 11 --> 7.2uA
 *
 * Calibrate charge pump opamp bias current(VCONN20_OSC_CAL<7:6>)
 * 00  --> 1.2uA(Default)
 * 01 -->  0.6uA
 * 10 -->  2.4uA
 * 11 -->  1.8uA
 */
#define PDSS_VCONN_CAL_VCONN_OSC_CAL_MASK                   (0x00000ff0UL) /* <4:11> R:RW:0: */
#define PDSS_VCONN_CAL_VCONN_OSC_CAL_POS                    (4UL)


/*
 * PMG1S3 NGDO Calibrate Register
 */
#define PDSS_NGDO_CAL_ADDRESS(m)                            (0x400a2538UL + ((m) * (0x10000UL)))
#define PDSS_NGDO_CAL(m)                                    (*(volatile uint32_t *)(0x400a2538UL + ((m) * 0x10000UL)))
#define PDSS_NGDO_CAL_DEFAULT                               (0x00000002UL)

/*
 * Calibrate the charge pump oscillator frequency,pump regulator bias current
 *
 * Calibrate charge pump Oscillator current (NGDO_OSC_CAL<2:0>)
 * 000 --> 2.4uA
 * 001 --> 3.6uA
 * 010 --> 4.8uA (Default)
 * 011 --> 6.0uA
 * 100 --> 7.2uA
 * 101 --> 8.4uA
 * 110 --> 9.6uA
 * 111 --> 10.8uA
 *
 * UNUSED (NGDO_OSC_CAL<3>)
 * 0 --> UNUSED (default)
 *
 * Calibrate charge pump Regulator bias current (NGDO_OSC_CAL<5:4>)
 * 00 --> 3.6uA (Default)
 * 01 --> 1.2uA
 * 10 --> 8.4uA
 * 11 --> 6.0uA
 *
 * Calibrate charge pump opamp bias current(NGDO_OSC_CAL<7:6>)
 * 00  --> 1.2uA(Default)
 * 01 -->  0.6uA
 * 10 -->  2.4uA
 * 11 --> 1.8uA
 */
#define PDSS_NGDO_CAL_NGDO_OSC_CAL_MASK                     (0x000000ffUL) /* <0:7> R:RW:2: */
#define PDSS_NGDO_CAL_NGDO_OSC_CAL_POS                      (0UL)


/*
 * PMG1S3 SCP RCP Calibrate Register
 */
#define PDSS_SCP_RCP_CAL_ADDRESS(m)                         (0x400a2540UL + ((m) * (0x10000UL)))
#define PDSS_SCP_RCP_CAL(m)                                 (*(volatile uint32_t *)(0x400a2540UL + ((m) * 0x10000UL)))
#define PDSS_SCP_RCP_CAL_DEFAULT                            (0x00000000UL)

/*
 * Calibrate bits for VbgbyR .
 * Bits[3:2] are not used
 * Bit[1] - increase vbgbyr current 2x
 * Bit[0] - reduce vbgbyr curent 0.5x
 */
#define PDSS_SCP_RCP_CAL_SCP_RCP_VBGBYR_CAL_MASK            (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_SCP_RCP_CAL_SCP_RCP_VBGBYR_CAL_POS             (0UL)


/*
 * PMG1S3 NCELL DDFT Selections
 */
#define PDSS_PMG1_NCELL_DDFT_MUX_ADDRESS(m)                 (0x400a2544UL + ((m) * (0x10000UL)))
#define PDSS_PMG1_NCELL_DDFT_MUX(m)                         (*(volatile uint32_t *)(0x400a2544UL + ((m) * 0x10000UL)))
#define PDSS_PMG1_NCELL_DDFT_MUX_DEFAULT                    (0x00000000UL)

/*
 * 03 : MXUSBPD_HIP_TOP_INST.y_pmg1s3_y_20vreg_pmg1s3_0_u_s8usbpd_vreg_top.clk_out
 * 02 : MXUSBPD_HIP_TOP_INST.y_pmg1s3_y_20vreg_pmg1s3_0_u_s8usbpd_vreg_top.cp_comp_out
 * 01 : MXUSBPD_HIP_TOP_INST.y_pmg1s3_y_20vreg_pmg1s3_0_u_s8usbpd_vreg_top.in_rush_det_lv
 * 00 : MXUSBPD_HIP_TOP_INST.y_pmg1s3_y_20vreg_pmg1s3_0_u_s8usbpd_vreg_top.ddft_out
 */
#define PDSS_PMG1_NCELL_DDFT_MUX_PMG1_NCELL_DDFT0_SEL_MASK    (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_PMG1_NCELL_DDFT_MUX_PMG1_NCELL_DDFT0_SEL_POS    (0UL)


/*
 * 03 : MXUSBPD_HIP_TOP_INST.y_pmg1s3_y_20vreg_pmg1s3_0_u_s8usbpd_vreg_top.clk_out
 * 02 : MXUSBPD_HIP_TOP_INST.y_pmg1s3_y_20vreg_pmg1s3_0_u_s8usbpd_vreg_top.cp_comp_out
 * 01 : MXUSBPD_HIP_TOP_INST.y_pmg1s3_y_20vreg_pmg1s3_0_u_s8usbpd_vreg_top.in_rush_det_lv
 * 00 : MXUSBPD_HIP_TOP_INST.y_pmg1s3_y_20vreg_pmg1s3_0_u_s8usbpd_vreg_top.ddft_out
 */
#define PDSS_PMG1_NCELL_DDFT_MUX_PMG1_NCELL_DDFT1_SEL_MASK    (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_PMG1_NCELL_DDFT_MUX_PMG1_NCELL_DDFT1_SEL_POS    (4UL)


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
 * USBPD Hard IP 5V PUMP#0 trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_5VPUMP0_0_ADDRESS(m)                      (0x400aff20UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_5VPUMP0_0(m)                              (*(volatile uint32_t *)(0x400aff20UL + ((m) * 0x10000UL)))
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
 * USBPD Hard IP 5V PUMP#0 trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_5VPUMP0_1_ADDRESS(m)                      (0x400aff24UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_5VPUMP0_1(m)                              (*(volatile uint32_t *)(0x400aff24UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_5VPUMP0_1_DEFAULT                         (0x00000005UL)

/*
 * Trim to change the charge pump output voltage by modifying the resistance
 * in the feed back divider
 */
#define PDSS_TRIM_5VPUMP0_1_V5PUMP_PUMP_TRIM3_0_MASK        (0x0000000fUL) /* <0:3> R:RW:5: */
#define PDSS_TRIM_5VPUMP0_1_V5PUMP_PUMP_TRIM3_0_POS         (0UL)


/*
 * USBPD Hard IP 5V PUMP#1 trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_5VPUMP1_0_ADDRESS(m)                      (0x400aff28UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_5VPUMP1_0(m)                              (*(volatile uint32_t *)(0x400aff28UL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_5VPUMP1_1_ADDRESS(m)                      (0x400aff2cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_5VPUMP1_1(m)                              (*(volatile uint32_t *)(0x400aff2cUL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_DPSLP_0_ADDRESS(m)                        (0x400aff30UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_DPSLP_0(m)                                (*(volatile uint32_t *)(0x400aff30UL + ((m) * 0x10000UL)))
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
#define PDSS_TRIM_DPSLP_1_ADDRESS(m)                        (0x400aff34UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_DPSLP_1(m)                                (*(volatile uint32_t *)(0x400aff34UL + ((m) * 0x10000UL)))
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
 * USBPD Hard IP REFGEN Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_REFGEN_ADDRESS(m)                         (0x400aff38UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_REFGEN(m)                                 (*(volatile uint32_t *)(0x400aff38UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_REFGEN_DEFAULT                            (0x00000000UL)

/*
 * Trim for input reference voltage/ Offset of regulation amplifier. This
 * provides the reference for the regulation blocks in the CSA,EA, and other
 * blocks such as CC_SHVT reference and VBUS_dischg. Default value is 0 with
 * bits bit 1-7 trimming down and 9-15 trimming up. BROS shows complete description
 * for the trim.
 */
#define PDSS_TRIM_REFGEN_REFGEN_VREF_TRIM_MASK              (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_REFGEN_REFGEN_VREF_TRIM_POS               (0UL)


/*
 * Trim for input reference voltage/ Offset of regulation amplifier. This
 * provides the reference for the regulation blocks in the CSA,EA, and other
 * blocks such as CC_SHVT reference and VBUS_dischg. Default value is 0 with
 * bits bit 1-7 trimming down and 9-15 trimming up. BROS shows complete description
 * for the trim.
 */
#define PDSS_TRIM_REFGEN_REFGEN_VREF_MON_TRIM_MASK          (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_TRIM_REFGEN_REFGEN_VREF_MON_TRIM_POS           (4UL)


/*
 * USBPD Hard IP NGDO Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_NGDO_ADDRESS(m)                           (0x400aff3cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_NGDO(m)                                   (*(volatile uint32_t *)(0x400aff3cUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_NGDO_DEFAULT                              (0x00000008UL)

/*
 * Trim the charge pump output voltage
 *
 * TRIM_PUMP [3:0] --> vboost=(vcp - vbus_in)
 * 0000 -> 8.05
 * 0001 -> 8.25
 * 0010 -> 8.45
 * 0011 -> 8.65
 * 0100 -> 8.85
 * 0101 -> 9.05
 * 0110 -> 9.25
 * 0111 -> 9.45
 * 1000 -> 9.65(Default)
 * 1001 -> 9.85
 * 1010 -> 10.05
 * 1011 -> 10.25
 * 1100 -> 10.45
 * 1101 -> 10.65
 * 1110 -> 10.85
 * 1111 -> 11.05
 */
#define PDSS_TRIM_NGDO_TRIM_PUMP_MASK                       (0x0000000fUL) /* <0:3> R:RW:8: */
#define PDSS_TRIM_NGDO_TRIM_PUMP_POS                        (0UL)


/*
 * USBPD Hard IP VCONN trim Register. Production trims stored in flash
 */
#define PDSS_TRIM_VCONN_ADDRESS(m)                          (0x400aff40UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_VCONN(m)                                  (*(volatile uint32_t *)(0x400aff40UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_VCONN_DEFAULT                             (0x00000086UL)

/*
 * TRIM--Typical OCP Trip
 * 0000--> 451mA
 * 0001--> 477mA
 * 0010--> 503mA
 * 0011--> 529mA
 * 0100--> 555mA
 * 0101--> 581mA
 * 0110--> 608mA (Default)
 * 0111--> 643mA
 * 1000--> 660mA
 * 1001--> 685mA
 * 1010--> 711mA
 * 1011--> 737mA
 * 1100--> 763mA
 * 1101--> 788mA
 * 1110--> 814mA
 * 1111--> 840mA
 */
#define PDSS_TRIM_VCONN_VCONN_OCP_TRIM_MASK                 (0x0000000fUL) /* <0:3> R:RW:6: */
#define PDSS_TRIM_VCONN_VCONN_OCP_TRIM_POS                  (0UL)


/*
 * TRIM--Inrush Current--Charging Current
 * 0000--> 83.22mA  --> 11.79nA
 * 0001--> 349.6mA  --> 63.01nA
 * 0010--> 522.47mA  --> 114.24nA
 * 0011--> 653.03mA -->165.35nA
 * 0100--> 757.05mA --> 216.66nA
 * 0101--> 842.4mA --> 267.57nA
 * 0110--> 919.36mA --> 318.99nA
 * 0111--> 984.33mA --> 369.88nA
 * 1000-->  168.69mA  --> 25.39nA (Default)
 * 1001--> 400.63mA  --> 76.61nA
 * 1010--> 559.43mA  --> 127.66nA
 * 1011--> 682.11mA --> 178.84nA
 * 1100--> 772.76mA --> 230.03nA
 * 1101--> 864.05mA --> 281.16nA
 * 1110--> 941.41mA --> 332.58nA
 * 1111--> 1004.49mA --> 383.51nA
 */
#define PDSS_TRIM_VCONN_VCONN_INRUSH_TRIM_MASK              (0x000000f0UL) /* <4:7> R:RW:8: */
#define PDSS_TRIM_VCONN_VCONN_INRUSH_TRIM_POS               (4UL)


/*
 * USBPD Hard IP SCP_RCP Trim Register 0. Production trims stored in flash
 */
#define PDSS_TRIM_SCP_RCP_0_ADDRESS(m)                      (0x400aff44UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SCP_RCP_0(m)                              (*(volatile uint32_t *)(0x400aff44UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SCP_RCP_0_DEFAULT                         (0x00000020UL)

/*
 * Offset trim for SCP . Corrects offset in steps of 80mA
 *
 * 000000 = -2.48A Offset
 * 000001 = -2.40A Offset
 * ...
 * 011111 =  0.00A Offset
 * 100000 =  0.00A Offset
 * ...
 * 111110 =  2.40A Offset
 * 111111 =  2.48A Offset
 */
#define PDSS_TRIM_SCP_RCP_0_TRIM_SCP_MASK                   (0x0000003fUL) /* <0:5> R:RW:32: */
#define PDSS_TRIM_SCP_RCP_0_TRIM_SCP_POS                    (0UL)


/*
 * USBPD Hard IP SCP_RCP Trim Register 1. Production trims stored in flash
 */
#define PDSS_TRIM_SCP_RCP_1_ADDRESS(m)                      (0x400aff48UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SCP_RCP_1(m)                              (*(volatile uint32_t *)(0x400aff48UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SCP_RCP_1_DEFAULT                         (0x00000040UL)

/*
 * Offset trim for RCP . Corrects offset in steps of 40mA
 *
 * 0000000 = -2.52A Offset
 * 0000001 = -2.48A Offset
 * ...
 * 0111111 =  0.00A Offset
 * 1000000 =  0.00A Offset
 * ...
 * 1111110 =  2.48A Offset
 * 1111111 =  2.52A Offset
 */
#define PDSS_TRIM_SCP_RCP_1_TRIM_RCP_MASK                   (0x0000007fUL) /* <0:6> R:RW:64: */
#define PDSS_TRIM_SCP_RCP_1_TRIM_RCP_POS                    (0UL)


/*
 * USBPD Hard IP SCP_RCP Trim Register 2. Production trims stored in flash
 */
#define PDSS_TRIM_SCP_RCP_2_ADDRESS(m)                      (0x400aff4cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SCP_RCP_2(m)                              (*(volatile uint32_t *)(0x400aff4cUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SCP_RCP_2_DEFAULT                         (0x0000003eUL)

/*
 * Offset trim for OCP . Corrects offset in steps of 40mA
 *
 * 00000000 = -1.28A Offset
 * 00000001 = -1.24A Offset
 * ...
 * 00011111 = -0.04A Offset
 * 00100000 =  0.00A Offset
 * ...
 * 11111110 =  8.88A Offset
 * 11111111 =  8.92A Offset
 */
#define PDSS_TRIM_SCP_RCP_2_TRIM_OCP_MASK                   (0x000000ffUL) /* <0:7> R:RW:62: */
#define PDSS_TRIM_SCP_RCP_2_TRIM_OCP_POS                    (0UL)


/*
 * USBPD Hard IP SBU_SW Termination Resistor Trim Register 0. Production
 * trims stored in flash
 */
#define PDSS_TRIM_SBU_SW_0_ADDRESS(m)                       (0x400aff50UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SBU_SW_0(m)                               (*(volatile uint32_t *)(0x400aff50UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SBU_SW_0_DEFAULT                          (0x00000000UL)

/*
 * 1 MOhm Resistor Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 * This should be trimmed at sort, or set to 2 for default
 */
#define PDSS_TRIM_SBU_SW_0_TRIM_1MEG_MASK                   (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_SBU_SW_0_TRIM_1MEG_POS                    (0UL)


/*
 * 100 kOhm Resistor Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 * This should be trimmed at sort, or set to 2 for default
 */
#define PDSS_TRIM_SBU_SW_0_TRIM_100K_MASK                   (0x00000038UL) /* <3:5> R:RW:0: */
#define PDSS_TRIM_SBU_SW_0_TRIM_100K_POS                    (3UL)


/*
 * USBPD Hard IP SBU_SW Termination Resistor Trim Register 1. Production
 * trims stored in flash
 */
#define PDSS_TRIM_SBU_SW_1_ADDRESS(m)                       (0x400aff54UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_SBU_SW_1(m)                               (*(volatile uint32_t *)(0x400aff54UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_SBU_SW_1_DEFAULT                          (0x00000000UL)

/*
 * 470 kOhm Resistor Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 * This should be trimmed at sort, or set to 2 for default
 */
#define PDSS_TRIM_SBU_SW_1_TRIM_470K_PD_MASK                (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_SBU_SW_1_TRIM_470K_PD_POS                 (0UL)


/*
 * 4.7 MOhm Resistor Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 * This should be trimmed at sort, or set to 2 for default
 */
#define PDSS_TRIM_SBU_SW_1_TRIM_4P7MEG_PD_MASK              (0x00000038UL) /* <3:5> R:RW:0: */
#define PDSS_TRIM_SBU_SW_1_TRIM_4P7MEG_PD_POS               (3UL)


/*
 * USBPD Hard IP 28V regulator Trim Register 0. Production trims stored in
 * flash
 */
#define PDSS_TRIM_VREG28_0_ADDRESS(m)                       (0x400aff58UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_VREG28_0(m)                               (*(volatile uint32_t *)(0x400aff58UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_VREG28_0_DEFAULT                          (0x00000043UL)

/*
 * 28V regulator output voltage trim
 *
 * Default "3" = 3.3
 * Step-Size = 50mV
 */
#define PDSS_TRIM_VREG28_0_VREG_TRIM_MASK                   (0x00000007UL) /* <0:2> R:RW:3: */
#define PDSS_TRIM_VREG28_0_VREG_TRIM_POS                    (0UL)


/*
 * 28V regulator output in-rush current detection trim
 *
 * Default "8" = 250mA
 * Step-Size = 25mA
 */
#define PDSS_TRIM_VREG28_0_INRUSH_TRIM_MASK                 (0x00000078UL) /* <3:6> R:RW:8: */
#define PDSS_TRIM_VREG28_0_INRUSH_TRIM_POS                  (3UL)


/*
 * USBPD Hard IP 28V regulator Trim Register 1. Production trims stored in
 * flash
 */
#define PDSS_TRIM_VREG28_1_ADDRESS(m)                       (0x400aff5cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_VREG28_1(m)                               (*(volatile uint32_t *)(0x400aff5cUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_VREG28_1_DEFAULT                          (0x00000070UL)

/*
 * 28V regulator internal charge-pump reference trim.  Unused currently
 */
#define PDSS_TRIM_VREG28_1_VCP_REF_TRIM_MASK                (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_TRIM_VREG28_1_VCP_REF_TRIM_POS                 (0UL)


/*
 * 28V regulator internal charge-pump trim
 *
 * Default "7" = 7.03V
 * Step-Size = 0.3V
 */
#define PDSS_TRIM_VREG28_1_VCP_TRIM_MASK                    (0x000000f0UL) /* <4:7> R:RW:7: */
#define PDSS_TRIM_VREG28_1_VCP_TRIM_POS                     (4UL)


/*
 * USBPD Hard IP battery charger Detect Trim Register 0. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET_0_ADDRESS(m)                      (0x400aff60UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BCH_DET_0(m)                              (*(volatile uint32_t *)(0x400aff60UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BCH_DET_0_DEFAULT                         (0x00000000UL)

/*
 * 0.6V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_0_V600M_TRIM_MASK                 (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_BCH_DET_0_V600M_TRIM_POS                  (0UL)


/*
 * Reference Generator trim control
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_0_V740M_CHGDET_TRIM_MASK          (0x00000078UL) /* <3:6> R:RW:0: */
#define PDSS_TRIM_BCH_DET_0_V740M_CHGDET_TRIM_POS           (3UL)


/*
 * USBPD Hard IP battery charger Detect Trim Register 1. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET_1_ADDRESS(m)                      (0x400aff64UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BCH_DET_1(m)                              (*(volatile uint32_t *)(0x400aff64UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BCH_DET_1_DEFAULT                         (0x00000000UL)

/*
 * 0.325V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_1_V325M_TRIM_MASK                 (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_TRIM_BCH_DET_1_V325M_TRIM_POS                  (0UL)


/*
 * 2.0V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_1_V2P0V_TRIM_MASK                 (0x0000000cUL) /* <2:3> R:RW:0: */
#define PDSS_TRIM_BCH_DET_1_V2P0V_TRIM_POS                  (2UL)


/*
 * 1.2V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_1_V1P2V_TRIM_MASK                 (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_TRIM_BCH_DET_1_V1P2V_TRIM_POS                  (4UL)


/*
 * USBPD Hard IP battery charger Detect Trim Register 2. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET_2_ADDRESS(m)                      (0x400aff68UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BCH_DET_2(m)                              (*(volatile uint32_t *)(0x400aff68UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BCH_DET_2_DEFAULT                         (0x00000000UL)

/*
 * 0.325V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_2_V850M_TRIM_MASK                 (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_TRIM_BCH_DET_2_V850M_TRIM_POS                  (0UL)


/*
 * 2.2V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_2_V2P2V_TRIM_MASK                 (0x0000000cUL) /* <2:3> R:RW:0: */
#define PDSS_TRIM_BCH_DET_2_V2P2V_TRIM_POS                  (2UL)


/*
 * 2.9V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_2_V2P9V_TRIM_MASK                 (0x00000030UL) /* <4:5> R:RW:0: */
#define PDSS_TRIM_BCH_DET_2_V2P9V_TRIM_POS                  (4UL)


/*
 * 2.5V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_2_V2P5V_TRIM_MASK                 (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_TRIM_BCH_DET_2_V2P5V_TRIM_POS                  (6UL)


/*
 * USBPD Hard IP battery charger Detect Trim Register 3. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET_3_ADDRESS(m)                      (0x400aff6cUL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BCH_DET_3(m)                              (*(volatile uint32_t *)(0x400aff6cUL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BCH_DET_3_DEFAULT                         (0x00000000UL)

/*
 * 0.700V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_3_V700M_TRIM_MASK                 (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_TRIM_BCH_DET_3_V700M_TRIM_POS                  (0UL)


/*
 * 1.4V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_3_V1P4V_TRIM_MASK                 (0x00000038UL) /* <3:5> R:RW:0: */
#define PDSS_TRIM_BCH_DET_3_V1P4V_TRIM_POS                  (3UL)


/*
 * 1.7V Reference Voltage Trim
 * Refer to the s8pds BROS for more details
 */
#define PDSS_TRIM_BCH_DET_3_V1P7V_TRIM_MASK                 (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_TRIM_BCH_DET_3_V1P7V_TRIM_POS                  (6UL)


/*
 * USBPD Hard IP battery charger Detect Trim Register 4. Production trims
 * stored in flash
 */
#define PDSS_TRIM_BCH_DET_4_ADDRESS(m)                      (0x400aff70UL + ((m) * (0x10000UL)))
#define PDSS_TRIM_BCH_DET_4(m)                              (*(volatile uint32_t *)(0x400aff70UL + ((m) * 0x10000UL)))
#define PDSS_TRIM_BCH_DET_4_DEFAULT                         (0x00000003UL)

/*
 * Trimming the idp_sink & idm_sink parameters.  To be effective, needs have
 * isink_trim_dp_en &  isink_trim_dp_en set as "1"
 * 0000 = 21.6 uA
 * 0001 = 24.0 uA
 * 0011 = 28.8 uA
 * 0111 = 38.4 uA
 * 1111 = 57.6 uA
 */
#define PDSS_TRIM_BCH_DET_4_ISINK_TRIM_MASK                 (0x0000000fUL) /* <0:3> R:RW:3: */
#define PDSS_TRIM_BCH_DET_4_ISINK_TRIM_POS                  (0UL)


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

#endif /* _CY_USBPD_PMG1S3_REGS_H_ */

