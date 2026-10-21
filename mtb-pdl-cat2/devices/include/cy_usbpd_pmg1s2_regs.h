/***************************************************************************//**
* \file cy_usbpd_pmg1s2_regs.h
* \version 1.0
*
* Cypress product header file.
* This file is auto generated from the register map spreadsheet.
* DO NOT MODIFY THIS FILE.
*
********************************************************************************
* \copyright
* Copyright 2016-2021 Cypress Semiconductor Corporation
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
#ifndef _CY_USBPD_PMG1S2_REGS_H_
#define _CY_USBPD_PMG1S2_REGS_H_

#include <stdint.h>
#include <stdbool.h>

/** \cond DOXYGEN_HIDE */

#define PDSS_BASE_ADDR                                   (0x400a0000UL)

typedef struct {
    volatile uint32_t ctrl;                               /* 0x400a0000 */
    volatile uint32_t header_info;                        /* 0x400a0004 */
    volatile uint32_t rsrvd0;
    volatile uint32_t tx_header;                          /* 0x400a000c */
    volatile uint32_t tx_mem_data[16];                    /* 0x400a0010 */
    volatile uint32_t rsrvd1[3];
    volatile uint32_t rx_header;                          /* 0x400a005c */
    volatile uint32_t rx_mem_data[16];                    /* 0x400a0060 */
    volatile uint32_t sram_ptr;                           /* 0x400a00a0 */
    volatile uint32_t status;                             /* 0x400a00a4 */
    volatile uint32_t rx_sop_good_crc_en_ctrl;            /* 0x400a00a8 */
    volatile uint32_t rx_default_sop_goodcrc_ctrl_0;      /* 0x400a00ac */
    volatile uint32_t rx_default_sop_goodcrc_ctrl_1;      /* 0x400a00b0 */
    volatile uint32_t rx_default_sop_goodcrc_ctrl_2;      /* 0x400a00b4 */
    volatile uint32_t rx_prime_sop_goodcrc_ctrl_0;        /* 0x400a00b8 */
    volatile uint32_t rx_prime_sop_goodcrc_ctrl_1;        /* 0x400a00bc */
    volatile uint32_t rx_prime_sop_goodcrc_ctrl_2;        /* 0x400a00c0 */
    volatile uint32_t rx_dbl_prime_sop_goodcrc_ctrl_0;    /* 0x400a00c4 */
    volatile uint32_t rx_dbl_prime_sop_goodcrc_ctrl_1;    /* 0x400a00c8 */
    volatile uint32_t rx_dbl_prime_sop_goodcrc_ctrl_2;    /* 0x400a00cc */
    volatile uint32_t rx_expect_goodcrc_msg;              /* 0x400a00d0 */
    volatile uint32_t rx_goodcrc_msg;                     /* 0x400a00d4 */
    volatile uint32_t rx_cc;                              /* 0x400a00d8 */
    volatile uint32_t rsrvd2;
    volatile uint32_t rx_cc2;                             /* 0x400a00e0 */
    volatile uint32_t rx_order_set_ctrl;                  /* 0x400a00e4 */
    volatile uint32_t rx_reserved1_order_set;             /* 0x400a00e8 */
    volatile uint32_t rx_reserved2_order_set;             /* 0x400a00ec */
    volatile uint32_t tx_goodcrc_msg_order_set;           /* 0x400a00f0 */
    volatile uint32_t tx_ctrl;                            /* 0x400a00f4 */
    volatile uint32_t tx_sop_order_set;                   /* 0x400a00f8 */
    volatile uint32_t tx_hard_cable_order_set;            /* 0x400a00fc */
    volatile uint32_t crc_counter;                        /* 0x400a0100 */
    volatile uint32_t inter_packet_counter;               /* 0x400a0104 */
    volatile uint32_t timer_trigger;                      /* 0x400a0108 */
    volatile uint32_t intr_ddft_mux;                      /* 0x400a010c */
    volatile uint32_t ddft_mux;                           /* 0x400a0110 */
    volatile uint32_t intr_1_cfg;                         /* 0x400a0114 */
    volatile uint32_t intr0;                              /* 0x400a0118 */
    volatile uint32_t intr1;                              /* 0x400a011c */
    volatile uint32_t intr0_set;                          /* 0x400a0120 */
    volatile uint32_t intr1_set;                          /* 0x400a0124 */
    volatile uint32_t intr0_mask;                         /* 0x400a0128 */
    volatile uint32_t intr1_mask;                         /* 0x400a012c */
    volatile uint32_t intr0_masked;                       /* 0x400a0130 */
    volatile uint32_t intr1_masked;                       /* 0x400a0134 */
    volatile uint32_t debug_ctrl;                         /* 0x400a0138 */
    volatile uint32_t debug_cc_0;                         /* 0x400a013c */
    volatile uint32_t debug_cc_1;                         /* 0x400a0140 */
    volatile uint32_t debug_cc_2;                         /* 0x400a0144 */
    volatile uint32_t debug_spare_intr_cfg;               /* 0x400a0148 */
    volatile uint32_t intr2;                              /* 0x400a014c */
    volatile uint32_t intr2_set;                          /* 0x400a0150 */
    volatile uint32_t intr2_mask;                         /* 0x400a0154 */
    volatile uint32_t intr2_masked;                       /* 0x400a0158 */
    volatile uint32_t hpd_ctrl1;                          /* 0x400a015c */
    volatile uint32_t hpd_ctrl2;                          /* 0x400a0160 */
    volatile uint32_t hpd_ctrl3;                          /* 0x400a0164 */
    volatile uint32_t hpd_ctrl4;                          /* 0x400a0168 */
    volatile uint32_t hpd_ctrl5;                          /* 0x400a016c */
    volatile uint32_t hpd_queue;                          /* 0x400a0170 */
    volatile uint32_t hpdt_ctrl1;                         /* 0x400a0174 */
    volatile uint32_t hpdt_ctrl2;                         /* 0x400a0178 */
    volatile uint32_t swap_ctrl0;                         /* 0x400a017c */
    volatile uint32_t swap_ctrl1;                         /* 0x400a0180 */
    volatile uint32_t swap_ctrl2;                         /* 0x400a0184 */
    volatile uint32_t swap_ctrl3;                         /* 0x400a0188 */
    volatile uint32_t swap_ctrl4;                         /* 0x400a018c */
    volatile uint32_t swap_ctrl5;                         /* 0x400a0190 */
    volatile uint32_t swap_queue;                         /* 0x400a0194 */
    volatile uint32_t swapt_ctrl1;                        /* 0x400a0198 */
    volatile uint32_t swapt_ctrl2;                        /* 0x400a019c */
    volatile uint32_t adc1_sar_ctrl;                      /* 0x400a01a0 */
    volatile uint32_t adc1_ctrl;                          /* 0x400a01a4 */
    volatile uint32_t adc2_sar_ctrl;                      /* 0x400a01a8 */
    volatile uint32_t adc2_ctrl;                          /* 0x400a01ac */
    volatile uint32_t cc_ctrl_0;                          /* 0x400a01b0 */
    volatile uint32_t cc_ctrl_1;                          /* 0x400a01b4 */
    volatile uint32_t dpslp_ref_ctrl;                     /* 0x400a01b8 */
    volatile uint32_t vconn_ctrl;                         /* 0x400a01bc */
    volatile uint32_t pump_ctrl;                          /* 0x400a01c0 */
    volatile uint32_t pfet300_ctrl;                       /* 0x400a01c4 */
    volatile uint32_t uvov_ctrl;                          /* 0x400a01c8 */
    volatile uint32_t csa_ctrl;                           /* 0x400a01cc */
    volatile uint32_t vreg_ctrl;                          /* 0x400a01d0 */
    volatile uint32_t sbu_ctrl;                           /* 0x400a01d4 */
    volatile uint32_t vsys_ctrl;                          /* 0x400a01d8 */
    volatile uint32_t vreg_vsys_ctrl;                     /* 0x400a01dc */
    volatile uint32_t ngdo_ctrl_0;                        /* 0x400a01e0 */
    volatile uint32_t ngdo_ctrl_c;                        /* 0x400a01e4 */
    volatile uint32_t ngdo_ctrl_p;                        /* 0x400a01e8 */
    volatile uint32_t vbus_ctrl;                          /* 0x400a01ec */
    volatile uint32_t chgdet_ctrl_0;                      /* 0x400a01f0 */
    volatile uint32_t chgdet_ctrl_1;                      /* 0x400a01f4 */
    volatile uint32_t intr3_cfg_0;                        /* 0x400a01f8 */
    volatile uint32_t intr3_cfg_1;                        /* 0x400a01fc */
    volatile uint32_t ncell_status;                       /* 0x400a0200 */
    volatile uint32_t intr3;                              /* 0x400a0204 */
    volatile uint32_t intr3_set;                          /* 0x400a0208 */
    volatile uint32_t intr3_mask;                         /* 0x400a020c */
    volatile uint32_t intr3_masked;                       /* 0x400a0210 */
    volatile uint32_t ncell_ddft_mux;                     /* 0x400a0214 */
    volatile uint32_t gpio_ddft_mux;                      /* 0x400a0218 */
    volatile uint32_t gpio_intr_ddft_mux;                 /* 0x400a021c */
    volatile uint32_t gpio_ncell_ddft_mux;                /* 0x400a0220 */
    volatile uint32_t swap_cntrl_0;                       /* 0x400a0224 */
    volatile uint32_t swap_cntrl_1;                       /* 0x400a0228 */
    volatile uint32_t rsrvd3[16181];
    volatile uint32_t s8usbpd_trim_0;                     /* 0x400aff00 */
    volatile uint32_t s8usbpd_trim_1;                     /* 0x400aff04 */
    volatile uint32_t s8usbpd_trim_2;                     /* 0x400aff08 */
    volatile uint32_t s8usbpd_trim_3;                     /* 0x400aff0c */
    volatile uint32_t s8usbpd_trim_4;                     /* 0x400aff10 */
    volatile uint32_t s8usbpd_trim_5;                     /* 0x400aff14 */
    volatile uint32_t s8usbpd_trim_6;                     /* 0x400aff18 */
    volatile uint32_t s8usbpd_trim_7;                     /* 0x400aff1c */
    volatile uint32_t s8usbpd_trim_spare1;                /* 0x400aff20 */
    volatile uint32_t s8usbpd_trim_spare2;                /* 0x400aff24 */
    volatile uint32_t s8usbpd_trim_csa_0;                 /* 0x400aff28 */
    volatile uint32_t s8usbpd_trim_csa_1;                 /* 0x400aff2c */
    volatile uint32_t s8usbpd_trim_csa_2;                 /* 0x400aff30 */
    volatile uint32_t s8usbpd_trim_chgdet_0;              /* 0x400aff34 */
    volatile uint32_t s8usbpd_trim_chgdet_1;              /* 0x400aff38 */
    volatile uint32_t s8usbpd_trim_chgdet_2;              /* 0x400aff3c */
    volatile uint32_t s8usbpd_trim_sbu_0;                 /* 0x400aff40 */
    volatile uint32_t s8usbpd_trim_sbu_1;                 /* 0x400aff44 */
    volatile uint32_t s8usbpd_trim_sbu_2;                 /* 0x400aff48 */
    volatile uint32_t s8usbpd_trim_spare3;                /* 0x400aff4c */
    volatile uint32_t s8usbpd_trim_spare4;                /* 0x400aff50 */
} PDSS_REGS_T, *PPDSS_REGS_T;

#define PDSS        ((PPDSS_REGS_T) PDSS_BASE_ADDR)
#define PDSS0       ((PPDSS_REGS_T) PDSS_BASE_ADDR)


#define ROMTABLE_BASE_ADDR                               (0xf0000000UL)

typedef struct {
    volatile uint32_t addr;                               /* 0xf0000000 */
    volatile uint32_t rsrvd0[1010];
    volatile uint32_t did;                                /* 0xf0000fcc */
    volatile uint32_t pid4;                               /* 0xf0000fd0 */
    volatile uint32_t pid5;                               /* 0xf0000fd4 */
    volatile uint32_t pid6;                               /* 0xf0000fd8 */
    volatile uint32_t pid7;                               /* 0xf0000fdc */
    volatile uint32_t pid0;                               /* 0xf0000fe0 */
    volatile uint32_t pid1;                               /* 0xf0000fe4 */
    volatile uint32_t pid2;                               /* 0xf0000fe8 */
    volatile uint32_t pid3;                               /* 0xf0000fec */
    volatile uint32_t cid0;                               /* 0xf0000ff0 */
    volatile uint32_t cid1;                               /* 0xf0000ff4 */
    volatile uint32_t cid2;                               /* 0xf0000ff8 */
    volatile uint32_t cid3;                               /* 0xf0000ffc */
} ROMTABLE_REGS_T, *PROMTABLE_REGS_T;

#define ROMTABLE        ((PROMTABLE_REGS_T) ROMTABLE_BASE_ADDR)


/*******************************************************************************
 ************************** REGISTER FIELD DEFINITIONS *************************
 ******************************************************************************/

/*
 * Generic control register.
 */
#define PDSS_CTRL_ADDRESS                                   (0x400a0000UL)
#define PDSS_CTRL                                           (*(volatile uint32_t *)(0x400a0000UL))
#define PDSS_CTRL_DEFAULT                                   (0x00000000UL)

/*
 * Setting this register will bypass 5b/4b, CRC.
 */
#define PDSS_CTRL_TX_BYPASS_EN                              (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Setting this register will bypass 5b/4b, CRC.
 */
#define PDSS_CTRL_RX_BYPASS_EN_MASK                         (0x00000006UL) /* <1:2> R:RW:0: */
#define PDSS_CTRL_RX_BYPASS_EN_POS                          (1UL)


/*
 * Defines the direction of GPIO used for HPD operation.
 * 0: GPIO is input. Receive operation.
 * 1: GPIO is output. Transmit operation
 * This bit must be set for correct mode of HPD operation (Receive / Transmit).
 */
#define PDSS_CTRL_HPD_DIRECTION                             (1UL << 3) /* <3:3> R:RW:0: */


/*
 * 0: Clocks is turn off for HPD block
 * 1: Clock is runing in the HPD block
 * This bit must be set when HPD Receive functionality is needed. This will
 * turn clock on for the RX module. resetting to zero will turn clock off.
 * Clock used for HPD is same clock that is used for CC transmit module (600
 * Khz).
 */
#define PDSS_CTRL_HPD_ENABLED                               (1UL << 29) /* <29:29> R:RW:0: */


/*
 * 0: Clocks is turn off for HPDT block
 * 1: Clock is runing in the HPDT block.
 * This bit must be set when HPDT transmit functionality is needed. This
 * will turn clock on for the TX module. resetting to zero will turn clock
 * off.
 * Clock used for HPD is same clock that is used for CC transmit module (600
 * Khz).
 */
#define PDSS_CTRL_HPDT_ENABLED                              (1UL << 30) /* <30:30> R:RW:0: */


/*
 * IP enabled ('1') or not ('0').
 * "0" Resets the IP. The reset is an async reset.
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
 * 0: Disable RX/TX extended data messaging
 * 1: Enable  RX/TX extended data messaging
 */
#define PDSS_HEADER_INFO_EN_RX_EXTENDED_DATA                (1UL << 0) /* <0:0> R:RW:0: */


/*
 * This bit will enable/disable extended data messaging.
 * 0: Disable RX/TX extended data messaging
 * 1: Enable  RX/TX extended data messaging
 */
#define PDSS_HEADER_INFO_EN_TX_EXTENDED_DATA                (1UL << 1) /* <1:1> R:RW:0: */


/*
 * The location of the extended data field in the Header[15:0].
 * 0: First Bit of the header
 * 1: Second Bit of the header
 * ...
 * 15: 15th bit of theheader
 */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BIT_LOCATION_MASK    (0x00000f00UL) /* <8:11> R:RW:15: */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BIT_LOCATION_POS     (8UL)


/*
 * The first bit location of the extended data size field in the header.
 * 0: First Bit of the header
 * 1: Second Bit of the header
 * ...
 * 31: Thirt first bit of the header
 */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BYTE_FIRST_BIT_LOCATION_MASK    (0x0001f000UL) /* <12:16> R:RW:16: */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BYTE_FIRST_BIT_LOCATION_POS    (12UL)


/*
 * The first bit location of the extended data size field in the header.
 * 0: First Bit of the header
 * 1: Second Bit of the header
 * ...
 * 31: Thirt first bit of the header
 */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BYTE_LAST_BIT_LOCATION_MASK    (0x003e0000UL) /* <17:21> R:RW:24: */
#define PDSS_HEADER_INFO_EXTENDED_DATA_BYTE_LAST_BIT_LOCATION_POS    (17UL)


/*
 * The location of the chunk field in the Header[31:16].
 * 16: 16th Bit of the header
 * 17: 17th Bit of the header
 * ...
 * 31: 31th bit of theheader
 */
#define PDSS_HEADER_INFO_CHUNK_BIT_LOCATION_MASK            (0x03c00000UL) /* <22:25> R:RW:15: */
#define PDSS_HEADER_INFO_CHUNK_BIT_LOCATION_POS             (22UL)


/*
 * Transmit Header
 */
#define PDSS_TX_HEADER_ADDRESS                              (0x400a000cUL)
#define PDSS_TX_HEADER                                      (*(volatile uint32_t *)(0x400a000cUL))
#define PDSS_TX_HEADER_DEFAULT                              (0x00000000UL)

/*
 * The transmit Header. This register contains the 16-bit(Regular Packet)
 * or 32-bit(Extended) header. Hardware uses this register along with HEADER_INFO
 * register to send either 16-bit (Regular Packet) or 32-bit (Extended Packet)
 * header.
 */
#define PDSS_TX_HEADER_TX_HEADER_MASK                       (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_TX_HEADER_TX_HEADER_POS                        (0UL)


/*
 * TX SRAM Data
 * The memory for the TX USB power controller is a 64 byte SRAM. This SRAM
 * containts only Data part of a packet in non-bypass mode.
 * Any access to address space 0x0010 - 0x004C will map to SRAM address x0-x31
 */
#define PDSS_TX_MEM_DATA_ADDRESS(n)                         (0x400a0010u + ((n) * (0x0004UL)))
#define PDSS_TX_MEM_DATA(n)                                 (*(volatile uint32_t *)(0x400a0010u + ((n) * 0x0004UL)))
#define PDSS_TX_MEM_DATA_DEFAULT                            (0x00000000UL)

/*
 * Data information in the transmitter SRAM. SOP/CRC/EOP will be appened
 * by HW.
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
 * The receive Header. This register contains the 16-bit(Regular Packet)
 * or 32-bit(Extended) header. The INTR2.EXTENDED_MSG_DET and INTR2.CHUNK_DET
 * interrupts indicates of the Packet type.  Hardware uses the HEADER_INFO
 * register for decoding the incoming packets.
 */
#define PDSS_RX_HEADER_RX_HEADER_MASK                       (0xffffffffUL) /* <0:31> RW:R:0: */
#define PDSS_RX_HEADER_RX_HEADER_POS                        (0UL)


/*
 * RX SRAM Data
 * The memory for the RX USB power controller is a 64 byte SRAM. This SRAM
 * containts only the Data part of a packet in non-bypass mode.
 * Any access to address space 0x0060 - 0x009C will map to SRAM address x0-x31
 */
#define PDSS_RX_MEM_DATA_ADDRESS(n)                         (0x400a0060u + ((n) * (0x0004UL)))
#define PDSS_RX_MEM_DATA(n)                                 (*(volatile uint32_t *)(0x400a0060u + ((n) * 0x0004UL)))
#define PDSS_RX_MEM_DATA_DEFAULT                            (0x00000000UL)

/*
 * The Data information in the receive SRAM. SOP type is stored in STATUS.SOP_TYPE_DETECTED
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
 * FW can use these pointers to Read/Write more data after the RX_SRAM_HALF_END/TX_SRAM_HALF_END
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
 * The recevie SRAM write pointer.
 */
#define PDSS_SRAM_PTR_RX_FUNC_WR_PTR_MASK                   (0x00001f00UL) /* <8:12> RW:R:0: */
#define PDSS_SRAM_PTR_RX_FUNC_WR_PTR_POS                    (8UL)


/*
 * Generic status register.
 */
#define PDSS_STATUS_ADDRESS                                 (0x400a00a4UL)
#define PDSS_STATUS                                         (*(volatile uint32_t *)(0x400a00a4UL))
#define PDSS_STATUS_DEFAULT                                 (0x00000000UL)

/*
 * Receiver is currently receiving a packet.
 * This signal gives information that Controlller has locked on to SOP and
 * is in process of receiving a packet. This will assert only after locking
 * on to Sop* symbols
 */
#define PDSS_STATUS_RX_BUSY                                 (1UL << 0) /* <0:0> RW:R:0: */


/*
 * Transmitter is currently transmitting a packet or the crc timmer is running
 */
#define PDSS_STATUS_TX_BUSY                                 (1UL << 1) /* <1:1> RW:R:0: */


/*
 * This status bit shows the CC_RX_VALID signal.
 * 0: No Valid data on the CC line'
 * 1: Valid Data detectd on the CC line
 */
#define PDSS_STATUS_CC_DATA_VALID                           (1UL << 2) /* <2:2> RW:R:0: */


/*
 * Type of SOP detected for the packet stored in the RX SRAM:
 * At the start of every packet, INTR.RCV_PACKET_COMPLETE and INTR.RCV_RST
 * status is evaluated.
 * If both are "0", then this register will be updated with the new packet
 * SOP value.
 * There is no clearing option.
 */
#define PDSS_STATUS_SOP_TYPE_DETECTED_MASK                  (0x00000038UL) /* <3:5> RW:R:0: */
#define PDSS_STATUS_SOP_TYPE_DETECTED_POS                   (3UL)


/*
 * GoodCrc Message SOP type detected:
 * At the start of every packet, INTR.RCV_GOODCRC_MSG_COMPLETE status is
 * evaluated, if its reset, then this register will be updated with the new
 * packet SOP value.
 */
#define PDSS_STATUS_GOODCRC_MSG_SOP_TYPE_DETECTED_MASK      (0x000001c0UL) /* <6:8> RW:R:0: */
#define PDSS_STATUS_GOODCRC_MSG_SOP_TYPE_DETECTED_POS       (6UL)


/*
 * RST Type detected:
 */
#define PDSS_STATUS_RST_TYPE_DET_MASK                       (0x00000e00UL) /* <9:11> RW:R:0: */
#define PDSS_STATUS_RST_TYPE_DET_POS                        (9UL)


/*
 * VCONN1 status (wakeup interrupt from deepsleep)
 * 1: VCONN1 > 2.7V
 * 0: VCONN1 < 2.7V
 */
#define PDSS_STATUS_VCONN1_STATUS                           (1UL << 12) /* <12:12> RW:R:0:VCONN_EN */


/*
 * CC1 status (wakeup interrupt from deepsleep using Resistor-based Rp, see
 * CC_CTRL_1.DS_ATTACH_DET_EN)
 * 1: CC1 attached
 * 0: CC1 detached
 */
#define PDSS_STATUS_CC1_STATUS                              (1UL << 14) /* <14:14> RW:R:0: */


/*
 * CC2 status (wakeup interrupt from deepsleep using Resistor-based Rp, see
 * CC_CTRL_1.DS_ATTACH_DET_EN)
 * 1: CC2 attached
 * 0: CC2 detached
 */
#define PDSS_STATUS_CC2_STATUS                              (1UL << 15) /* <15:15> RW:R:0: */


/*
 * This register provides the status of Receiver activity (wakeup interrupt
 * from deepsleep).
 */
#define PDSS_STATUS_VCMP_LA_STATUS                          (1UL << 16) /* <16:16> RW:R:0: */


/*
 * This register provides the status of VCMP_UP (wakeup interrupt from deepsleep).
 * Not enabled unless CC_CTRL_0.CMP_EN bit is set.
 * The following give two examples:
 * (Source) Edge: Ra/Rd value changed
 * {VCMP_UP, VCMP_DN}:
 * 00: Ra connected
 * 01: Rd connected
 * 11: Nothing connected (float)
 *                OR
 * (Sink) Edge: Rp value changed
 * {VCMP_UP, VCMP_DN}:
 * 00: Default Rp broadcast
 * 01: 1.5A Rp broadcast
 * 11: 3.0A Rp broadcast
 */
#define PDSS_STATUS_VCMP_UP_STATUS                          (1UL << 17) /* <17:17> RW:R:0: */


/*
 * This register provides the status of VCMP_DN (wakeup interrupt from deepsleep).
 * Not enabled unless CMP_EN bit is set.
 * Edge: Ra/Rd value changed
 *                OR
 * Edge: Rp value changed
 */
#define PDSS_STATUS_VCMP_DN_STATUS                          (1UL << 18) /* <18:18> RW:R:0: */


/*
 * This status bit shows the VCMP_FS comparator output from s8usbpd_cc_top.
 */
#define PDSS_STATUS_VCMP_FS                                 (1UL << 19) /* <19:19> RW:R:0: */


/*
 * This status bit shows that the transmit is in the process of sending googcrc
 * msg
 */
#define PDSS_STATUS_SENDING_GOODCRC_MSG                     (1UL << 20) /* <20:20> RW:R:0: */


/*
 * This status bit shows the v5v from s8usbpd_300ma_sw_top
 */
#define PDSS_STATUS_V5V_STATUS                              (1UL << 21) /* <21:21> RW:R:0:FET_300_EN */


/*
 * The status of cmp_out from the first ADC
 */
#define PDSS_STATUS_ADC1_CMP_OUT_STATUS                     (1UL << 22) /* <22:22> RW:R:0: */


/*
 * The status of cmp_out from the second ADC
 */
#define PDSS_STATUS_ADC2_CMP_OUT_STATUS                     (1UL << 23) /* <23:23> RW:R:0: */


/*
 * This reads the level of HPD input from GPIO.
 */
#define PDSS_STATUS_HPD_STATUS                              (1UL << 24) /* <24:24> RW:R:0: */


/*
 * Spare6 status. There is mainly kept as a spare
 */
#define PDSS_STATUS_SPARE6_STATUS                           (1UL << 25) /* <25:25> RW:R:0: */


/*
 * Spare7 status. There is mainly kept as a spare
 */
#define PDSS_STATUS_SPARE7_STATUS                           (1UL << 26) /* <26:26> RW:R:0: */


/*
 * RX SOP Control for sending GoodCRC Message
 * Hardware will wait for programmable IDLE_COUNTER and then send Good Crc
 * Message.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_ADDRESS                (0x400a00a8UL)
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL                        (*(volatile uint32_t *)(0x400a00a8UL))
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_DEFAULT                (0x000000c0UL)

/*
 * Setting this bit will enable the TX block to automatically issue a GoodCRC
 * Message when the received
 * packet with Dafault SOP which has no CRC issue and the packet has been
 * written into SRAM successfully.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_TX_SEND_DEFAULT_SOP_GOOD_CRC_EN    (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Setting this bit will enable the TX block to automatically issue a GoodCRC
 * Message when the received
 * packet with prime SOP which has no CRC issue and the packet has been written
 * into SRAM successfully.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_TX_SEND_PRIME_SOP_GOOD_CRC_EN    (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Setting this bit will enable the TX block to automatically issue a GoodCRC
 * Message when the received
 * packet with dbl prime SOP which has no CRC issue and the packet has been
 * written into SRAM successfully.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_TX_SEND_DBL_PRIME_SOP_GOOD_CRC_EN    (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Setting this bit will enable the TX block to automatically issue a GoodCRC
 * Message when the extended received
 * packet with Dafault SOP which has no CRC issue and the packet has been
 * written into SRAM successfully.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_EXT_TX_SEND_DEFAULT_SOP_GOOD_CRC_EN    (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Setting this bit will enable the TX block to automatically issue a GoodCRC
 * Message when the  extended received
 * packet with prime SOP which has no CRC issue and the packet has been written
 * into SRAM successfully.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_EXT_TX_SEND_PRIME_SOP_GOOD_CRC_EN    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Setting this bit will enable the TX block to automatically issue a GoodCRC
 * Message when the  extended received
 * packet with dbl prime SOP which has no CRC issue and the packet has been
 * written into SRAM successfully.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_EXT_TX_SEND_DBL_PRIME_SOP_GOOD_CRC_EN    (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Setting this bit will enable sending GoodCrcMsg for packet with Bad EOP.
 * This should be left to default for normal operation.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_SEND_GOOD_CRC_BAD_EOP    (1UL << 6) /* <6:6> R:RW:1: */


/*
 * Setting this bit will enable sending GoodCrcMsg for packet with KCHAR
 * Error. This should be left to default for normal operation.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_SEND_GOOD_CRC_BAD_KCHAR    (1UL << 7) /* <7:7> R:RW:1: */


/*
 * Setting this bit will enable sending GoodCrcMsg for packet even when there
 * is RX Sram Over Flow is detected. This should be left to default for normal
 * operation.
 */
#define PDSS_RX_SOP_GOOD_CRC_EN_CTRL_SEND_GOOD_CRC_SRAM_OVERFLOW    (1UL << 8) /* <8:8> R:RW:0: */


/*
 * RX Default SOP GoodCRC Control 0
 * There are two purposes for this register:
 * 1. Transmit Path:
 *     When hardware is done transmitting a packet, it will start the RX_CRC_TIMER.
 *     The CRC timer should stop on following conditions:
 *     1. Good CRC Received: With Matching Message ID, Matching Header Sop
 * type.
 *     2. Hard Reset on Receive side
 *     3. Soft Reset on Receive Side:
 *     4. Any other message legal in the current firmware state:
 *     Condition 1, condition 2: These two conditions are automatically taken
 * care by hardware and CRC timer is stopped.
 *     Condition 3, condition 4: Firmware needs to take care of. Firmware
 * can program what legal messages it is expecting in a particular state
 * and hardware will stop its counter.
 *                                         E.G: If firmware wants the transmit
 * logic to stop its CRC counter and not retry the packet on reception of
 * these following messages:
 *                                         - Soft Reset Control Message:
 *  Message Type 1101
 *                                         - Get Source Cap Control Message:
 * Message Type 0111
 *                                         - Vendor Defined Data Message:
 *  Message Type 1111
 *                                         Then in that case firmware will
 * program RX_DEFAULT_SOP_GOODCRC_CTRL to: 8000_2080 (Bit 7th, bit 13th and
 * bit 31st)
 *                                         Hardware will stop the timers
 * on reception of these packets and will also automatically send GoodCRC
 * message to these messages
 *                                         if the proper auto bit is set
 * in RX_SOP_GOOD_CRC_EN_CTRL. Other messages received will be logged in
 * RX_Memory but Good CRC will not be returned or
 *                                         timer will not be stopped.
 * 2. Receive  Path:
 *     Based on one hot encoding of RX_DEFAULT_SOP_GOODCRC_CTRL mapped to
 * message type field in the incoming header,
 *     Good CRC will be returned automatically if the correct RX_SOP_GOOD_CRC_EN_CTRL
 * bit is set.
 */
#define PDSS_RX_DEFAULT_SOP_GOODCRC_CTRL_0_ADDRESS          (0x400a00acUL)
#define PDSS_RX_DEFAULT_SOP_GOODCRC_CTRL_0                  (*(volatile uint32_t *)(0x400a00acUL))
#define PDSS_RX_DEFAULT_SOP_GOODCRC_CTRL_0_DEFAULT          (0x00000000UL)

/*
 * The Message type of a control message is a 5-bit field. Every bit of this
 * register mapps to the control message types. CPU can used this register
 * to select for which one of the the message types of a control message
 * should hardware send a GOODCRC message.
 */
#define PDSS_RX_DEF_SOP_GOODCRC_CTRL_0_SEND_GOOD_CRC_PER_CTRL_MSG_TYP_MASK    (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_RX_DEF_SOP_GOODCRC_CTRL_0_SEND_GOOD_CRC_PER_CTRL_MSG_TYP_POS    (0UL)


/*
 * RX Default SOP GoodCRC Control 1
 * There are two purposes for this register:
 * 1. Transmit Path:
 *     When hardware is done transmitting a packet, it will start the RX_CRC_TIMER.
 *     The CRC timer should stop on following conditions:
 *     1. Good CRC Received: With Matching Message ID, Matching Header Sop
 * type.
 *     2. Hard Reset on Receive side
 *     3. Soft Reset on Receive Side:
 *     4. Any other message legal in the current firmware state:
 *     Condition 1, condition 2: These two conditions are automatically taken
 * care by hardware and CRC timer is stopped.
 *     Condition 3, condition 4: Firmware needs to take care of. Firmware
 * can program what legal messages it is expecting in a particular state
 * and hardware will stop its counter.
 *                                         E.G: If firmware wants the transmit
 * logic to stop its CRC counter and not retry the packet on reception of
 * these following messages:
 *                                         - Soft Reset Control Message:
 *  Message Type 1101
 *                                         - Get Source Cap Control Message:
 * Message Type 0111
 *                                         - Vendor Defined Data Message:
 *  Message Type 1111
 *                                         Then in that case firmware will
 * program RX_DEFAULT_SOP_GOODCRC_CTRL to: 8000_2080 (Bit 7th, bit 13th and
 * bit 31st)
 *                                         Hardware will stop the timers
 * on reception of these packets and will also automatically send GoodCRC
 * message to these messages
 *                                         if the proper auto bit is set
 * in RX_SOP_GOOD_CRC_EN_CTRL. Other messages received will be logged in
 * RX_Memory but Good CRC will not be returned or
 *                                         timer will not be stopped.
 * 2. Receive  Path:
 *     Based on one hot encoding of RX_DEFAULT_SOP_GOODCRC_CTRL mapped to
 * message type field in the incoming header,
 *     Good CRC will be returned automatically if the correct RX_SOP_GOOD_CRC_EN_CTRL
 * bit is set.
 */
#define PDSS_RX_DEFAULT_SOP_GOODCRC_CTRL_1_ADDRESS          (0x400a00b0UL)
#define PDSS_RX_DEFAULT_SOP_GOODCRC_CTRL_1                  (*(volatile uint32_t *)(0x400a00b0UL))
#define PDSS_RX_DEFAULT_SOP_GOODCRC_CTRL_1_DEFAULT          (0x00000000UL)

/*
 * The Message type of a data message is a 5-bit field. Every bit of this
 * register mapps to the data message types. CPU can used this register to
 * select for which one of the the message types of a data message should
 * hardware send a GOODCRC message.
 */
#define PDSS_RX_DEF_SOP_GOODCRC_CTRL_1_SEND_GOODCRC_PER_DATA_MSG_TYP_MASK    (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_RX_DEF_SOP_GOODCRC_CTRL_1_SEND_GOODCRC_PER_DATA_MSG_TYP_POS    (0UL)


/*
 * RX Default SOP GoodCRC Control 2
 * There are two purposes for this register:
 * 1. Transmit Path:
 *     When hardware is done transmitting a packet, it will start the RX_CRC_TIMER.
 *     The CRC timer should stop on following conditions:
 *     1. Good CRC Received: With Matching Message ID, Matching Header Sop
 * type.
 *     2. Hard Reset on Receive side
 *     3. Soft Reset on Receive Side:
 *     4. Any other message legal in the current firmware state:
 *     Condition 1, condition 2: These two conditions are automatically taken
 * care by hardware and CRC timer is stopped.
 *     Condition 3, condition 4: Firmware needs to take care of. Firmware
 * can program what legal messages it is expecting in a particular state
 * and hardware will stop its counter.
 *                                         E.G: If firmware wants the transmit
 * logic to stop its CRC counter and not retry the packet on reception of
 * these following messages:
 *                                         - Soft Reset Control Message:
 *  Message Type 1101
 *                                         - Get Source Cap Control Message:
 * Message Type 0111
 *                                         - Vendor Defined Data Message:
 *  Message Type 1111
 *                                         Then in that case firmware will
 * program RX_DEFAULT_SOP_GOODCRC_CTRL to: 8000_2080 (Bit 7th, bit 13th and
 * bit 31st)
 *                                         Hardware will stop the timers
 * on reception of these packets and will also automatically send GoodCRC
 * message to these messages
 *                                         if the proper auto bit is set
 * in RX_SOP_GOOD_CRC_EN_CTRL. Other messages received will be logged in
 * RX_Memory but Good CRC will not be returned or
 *                                         timer will not be stopped.
 * 2. Receive  Path:
 *     Based on one hot encoding of RX_DEFAULT_SOP_GOODCRC_CTRL mapped to
 * message type field in the incoming header,
 *     Good CRC will be returned automatically if the correct RX_SOP_GOOD_CRC_EN_CTRL
 * bit is set.
 */
#define PDSS_RX_DEFAULT_SOP_GOODCRC_CTRL_2_ADDRESS          (0x400a00b4UL)
#define PDSS_RX_DEFAULT_SOP_GOODCRC_CTRL_2                  (*(volatile uint32_t *)(0x400a00b4UL))
#define PDSS_RX_DEFAULT_SOP_GOODCRC_CTRL_2_DEFAULT          (0x00000000UL)

/*
 * Only for extended data.
 * The Message type of a data message is a 5-bit field. Every bit of this
 * register mapps to the data message types. CPU can used this register to
 * select for which one of the the message types of a data message should
 * hardware send a GOODCRC message.
 */
#define PDSS_RX_DEF_SOP_GOODCRC_CTRL_2_SEND_GOODCRC_PER_DATAMSG_TYP_MASK    (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_RX_DEF_SOP_GOODCRC_CTRL_2_SEND_GOODCRC_PER_DATAMSG_TYP_POS    (0UL)


/*
 * RX Prime SOP GoodCRC Control 0
 */
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_0_ADDRESS            (0x400a00b8UL)
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_0                    (*(volatile uint32_t *)(0x400a00b8UL))
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_0_DEFAULT            (0x00000000UL)

/*
 * The Message type of a control message is a 5-bit field. Every bit of this
 * register mapps to the control
 * message types. CPU can used this register to select for which one of the
 * the message types of a control message should hardware send a GOODCRC
 * message.
 */
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_0_SEND_GOODCRC_PER_CTRLMSG_TYP_MASK    (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_0_SEND_GOODCRC_PER_CTRLMSG_TYP_POS    (0UL)


/*
 * RX Prime SOP GoodCRC Control 1
 */
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_1_ADDRESS            (0x400a00bcUL)
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_1                    (*(volatile uint32_t *)(0x400a00bcUL))
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_1_DEFAULT            (0x00000000UL)

/*
 * The Message type of a data message is a 5-bit field. Every bit of this
 * register mapps to the data
 * message types. CPU can used this register to select for which one of the
 * the message types of a data message should hardware send a GOODCRC message.
 */
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_1_SEND_GOODCRC_PER_DATAMSG_TYP_MASK    (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_1_SEND_GOODCRC_PER_DATAMSG_TYP_POS    (0UL)


/*
 * RX Prime SOP GoodCRC Control 2
 */
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_2_ADDRESS            (0x400a00c0UL)
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_2                    (*(volatile uint32_t *)(0x400a00c0UL))
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_2_DEFAULT            (0x00000000UL)

/*
 * Only for extended data.
 * The Message type of a data message is a 5-bit field. Every bit of this
 * register mapps to the data
 * message types. CPU can used this register to select for which one of the
 * the message types of a data message should hardware send a GOODCRC message.
 */
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_2_SEND_GOODCRC_PER_DATAMSG_TYP_MASK    (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_RX_PRIME_SOP_GOODCRC_CTRL_2_SEND_GOODCRC_PER_DATAMSG_TYP_POS    (0UL)


/*
 * RX DBL Prime SOP GoodCRC Control 0
 */
#define PDSS_RX_DBL_PRIME_SOP_GOODCRC_CTRL_0_ADDRESS        (0x400a00c4UL)
#define PDSS_RX_DBL_PRIME_SOP_GOODCRC_CTRL_0                (*(volatile uint32_t *)(0x400a00c4UL))
#define PDSS_RX_DBL_PRIME_SOP_GOODCRC_CTRL_0_DEFAULT        (0x00000000UL)

/*
 * The Message type of a control message is a 5-bit field. Every bit of this
 * register mapps to the control
 * message types. CPU can used this register to select for which one of the
 * the message types of a control message should hardware send a GOODCRC
 * message.
 */
#define PDSS_RX_DBLPRIME_SOP_GOODCRC_CTRL_0_SEND_GOODCRC_CTRLMSG_TYP_MASK    (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_RX_DBLPRIME_SOP_GOODCRC_CTRL_0_SEND_GOODCRC_CTRLMSG_TYP_POS    (0UL)


/*
 * RX DBL Prime SOP GoodCRC Control 1
 */
#define PDSS_RX_DBL_PRIME_SOP_GOODCRC_CTRL_1_ADDRESS        (0x400a00c8UL)
#define PDSS_RX_DBL_PRIME_SOP_GOODCRC_CTRL_1                (*(volatile uint32_t *)(0x400a00c8UL))
#define PDSS_RX_DBL_PRIME_SOP_GOODCRC_CTRL_1_DEFAULT        (0x00000000UL)

/*
 * The Message type of a data message is a 5-bit field. Every bit of this
 * register mapps to the data
 * message types. CPU can used this register to select for which one of the
 * the message types of a data message should hardware send a GOODCRC message.
 */
#define PDSS_RX_DBLPRIME_SOP_GOODCRC_CTRL_1_SEND_GOODCRC_DATAMSG_TYP_MASK    (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_RX_DBLPRIME_SOP_GOODCRC_CTRL_1_SEND_GOODCRC_DATAMSG_TYP_POS    (0UL)


/*
 * RX DBL Prime SOP GoodCRC Control 2
 */
#define PDSS_RX_DBL_PRIME_SOP_GOODCRC_CTRL_2_ADDRESS        (0x400a00ccUL)
#define PDSS_RX_DBL_PRIME_SOP_GOODCRC_CTRL_2                (*(volatile uint32_t *)(0x400a00ccUL))
#define PDSS_RX_DBL_PRIME_SOP_GOODCRC_CTRL_2_DEFAULT        (0x00000000UL)

/*
 * Only for extended data.
 * The Message type of a data message is a 5-bit field. Every bit of this
 * register mapps to the data
 * message types. CPU can used this register to select for which one of the
 * the message types of a data message should hardware send a GOODCRC message.
 */
#define PDSS_RX_DBLPRIME_SOP_GOODCRC_CTRL_2_SEND_GOODCRC_DATAMSG_TYP_MASK    (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_RX_DBLPRIME_SOP_GOODCRC_CTRL_2_SEND_GOODCRC_DATAMSG_TYP_POS    (0UL)


/*
 * RX Excepted good CRC message to stop the CRC timers
 */
#define PDSS_RX_EXPECT_GOODCRC_MSG_ADDRESS                  (0x400a00d0UL)
#define PDSS_RX_EXPECT_GOODCRC_MSG                          (*(volatile uint32_t *)(0x400a00d0UL))
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
#define PDSS_RX_EXPECT_GOODCRC_MSG_EXPECTED_HEADER_MASK     (0x0000ffffUL) /* <0:15> R:RW:1: */
#define PDSS_RX_EXPECT_GOODCRC_MSG_EXPECTED_HEADER_POS      (0UL)


/*
 * The expected SOP of GoodCRC Messgae on the RX side.
 */
#define PDSS_RX_EXPECT_GOODCRC_MSG_EXPECTED_SOP_MASK        (0x00070000UL) /* <16:18> R:RW:0: */
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
#define PDSS_RX_GOODCRC_MSG_ADDRESS                         (0x400a00d4UL)
#define PDSS_RX_GOODCRC_MSG                                 (*(volatile uint32_t *)(0x400a00d4UL))
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
 * The Receive C-Connect registers
 */
#define PDSS_RX_CC_ADDRESS                                  (0x400a00d8UL)
#define PDSS_RX_CC                                          (*(volatile uint32_t *)(0x400a00d8UL))
#define PDSS_RX_CC_DEFAULT                                  (0x00000580UL)

/*
 * This value is internally multiplied by 16.
 * The 16X value when multiplied by the period of CLK_RX defines the maximum
 * clock period.
 * This value is used to cause the RX state machine to return to idle state
 * if no transitions are detected.
 * For 12 Mhz, the count should be 20 Decimal ( becomes approx. 26usec)
 * For 24 Mhz, the count should be 40 Decimal
 */
#define PDSS_RX_CC_RX_CNT_MAX_MASK                          (0x000000ffUL) /* <0:7> R:RW:128: */
#define PDSS_RX_CC_RX_CNT_MAX_POS                           (0UL)


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
#define PDSS_RX_CC_RX_UI_BOUNDARY_DELTA_MASK                (0x00003f00UL) /* <8:13> R:RW:5: */
#define PDSS_RX_CC_RX_UI_BOUNDARY_DELTA_POS                 (8UL)


/*
 * Spare
 */
#define PDSS_RX_CC_DELAY_HALF                               (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Spare
 */
#define PDSS_RX_CC_DELAY_VALUE_MASK                         (0x00078000UL) /* <15:18> R:RW:0: */
#define PDSS_RX_CC_DELAY_VALUE_POS                          (15UL)


/*
 * Spare
 */
#define PDSS_RX_CC_DELAY_WIDEN_HIGH                         (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Spare
 */
#define PDSS_RX_CC_DELAY_AUTO                               (1UL << 20) /* <20:20> R:RW:0: */


/*
 * The Receive C-Connect registers
 */
#define PDSS_RX_CC2_ADDRESS                                 (0x400a00e0UL)
#define PDSS_RX_CC2                                         (*(volatile uint32_t *)(0x400a00e0UL))
#define PDSS_RX_CC2_DEFAULT                                 (0x00043008UL)

/*
 * This is a debug feature.
 * It defines minimum pulse value. If a pulse for current packet is calculated
 * to be smaller than this value, an interrupt will be issued.  MIN_PULSE_VIOLATED
 * will be set.  This check will be made after number of transitions specified
 * by NUM_TRANS_AVG are complete.
 */
#define PDSS_RX_CC2_MIN_PULSE_VALUE_MASK                    (0x000000ffUL) /* <0:7> R:RW:8: */
#define PDSS_RX_CC2_MIN_PULSE_VALUE_POS                     (0UL)


/*
 * This is a debug feature. It defines maximum pulse value. If a pulse for
 * current packet is calculated to be larger than this value, an interrupt
 * will be issued.  MAX_PULSE_VIOLATED will be set.  This check will be made
 * after number of transitions specified by NUM_TRANS_AVG are complete.
 */
#define PDSS_RX_CC2_MAX_PULSE_VALUE_MASK                    (0x0000ff00UL) /* <8:15> R:RW:48: */
#define PDSS_RX_CC2_MAX_PULSE_VALUE_POS                     (8UL)


/*
 * Number of RX_CC transitions before RX_VALID output is raised.
 */
#define PDSS_RX_CC2_DELAY_VALID_COUNT_MASK                  (0x000f0000UL) /* <16:19> R:RW:4: */
#define PDSS_RX_CC2_DELAY_VALID_COUNT_POS                   (16UL)


/*
 * Receive SOPs and RSTs order set control
 */
#define PDSS_RX_ORDER_SET_CTRL_ADDRESS                      (0x400a00e4UL)
#define PDSS_RX_ORDER_SET_CTRL                              (*(volatile uint32_t *)(0x400a00e4UL))
#define PDSS_RX_ORDER_SET_CTRL_DEFAULT                      (0x00006103UL)

/*
 * This register is used for SOP, SOP',SOP'", DEBUG SOP', DEBUG SOP" and
 * RX_RESERVED1/2_ORDER_SET(if configured for SOP) oder set detection. It
 * is recommended that CPU program this register to 1 ( 4 out of 4 option).
 * 0: Compare 3 out of 4 order sets
 * 1: Compare 4 out of 4 order sets
 */
#define PDSS_RX_ORDER_SET_CTRL_SOP_CMP_OPT                  (1UL << 0) /* <0:0> R:RW:1: */


/*
 * This register is used for Cable RST, Hard RST and RX_RESERVED1/2_ORDER_SET(if
 * configure for RST) order set detection.
 * It is recommended that CPU program this register to 1 ( 4 out of 4 option).
 * 0: Compare 3 out of 4 order sets
 * 1: Compare 4 out of 4 order sets
 */
#define PDSS_RX_ORDER_SET_CTRL_RST_CMP_OPT                  (1UL << 1) /* <1:1> R:RW:1: */


/*
 * This register is used to enable/disdable 4-bit preamble detection for
 * SOP detection.
 * 0: SOP Detection:                              SOP logic detection
 * 1: SOP detection: Preamble(4-bit)+ SOP logic detection
 */
#define PDSS_RX_ORDER_SET_CTRL_PREAMBLE_SOP_EN              (1UL << 2) /* <2:2> R:RW:0: */


/*
 * This register is used to enable/disdable 4-bit preamble detection for
 * RST detection.
 * 0: RST Detection:                              RST logic detection
 * 1: RST detection: Preamble(4-bit)+ RST logic detection
 */
#define PDSS_RX_ORDER_SET_CTRL_PREAMBLE_RST_EN              (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Host Mode: F/W can enable SOP, SOP', SOP" and Hard Reset Detection.
 * Device Mode: F/W should enable only SOP and Hard Reset Detection.
 * Cable Mode: Either SOP' or SOP" based on VCONN, Hard Reset and Cable Reset
 * should be enabled.
 */
#define PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_MASK              (0x0007ff00UL) /* <8:18> R:RW:97: */
#define PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_POS               (8UL)


/*
 * Receive Reserved1 order set
 */
#define PDSS_RX_RESERVED1_ORDER_SET_ADDRESS                 (0x400a00e8UL)
#define PDSS_RX_RESERVED1_ORDER_SET                         (*(volatile uint32_t *)(0x400a00e8UL))
#define PDSS_RX_RESERVED1_ORDER_SET_DEFAULT                 (0x00000000UL)

/*
 * Receive Reserved1 order set
 */
#define PDSS_RX_RESERVED1_ORDER_SET_RX_RESERVED1_OS_MASK    (0xffffffffUL) /* <0:31> R:RW:0: */
#define PDSS_RX_RESERVED1_ORDER_SET_RX_RESERVED1_OS_POS     (0UL)


/*
 * Receive Reserved2 order set
 */
#define PDSS_RX_RESERVED2_ORDER_SET_ADDRESS                 (0x400a00ecUL)
#define PDSS_RX_RESERVED2_ORDER_SET                         (*(volatile uint32_t *)(0x400a00ecUL))
#define PDSS_RX_RESERVED2_ORDER_SET_DEFAULT                 (0x00000000UL)

/*
 * Receive Reserved2  order set
 */
#define PDSS_RX_RESERVED2_ORDER_SET_RX_RESERVED2_OS_MASK    (0x000fffffUL) /* <0:19> R:RW:0: */
#define PDSS_RX_RESERVED2_ORDER_SET_RX_RESERVED2_OS_POS     (0UL)


/*
 * Transmit GoodCrc Message order set
 */
#define PDSS_TX_GOODCRC_MSG_ORDER_SET_ADDRESS               (0x400a00f0UL)
#define PDSS_TX_GOODCRC_MSG_ORDER_SET                       (*(volatile uint32_t *)(0x400a00f0UL))
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
#define PDSS_TX_CTRL_ADDRESS                                (0x400a00f4UL)
#define PDSS_TX_CTRL                                        (*(volatile uint32_t *)(0x400a00f4UL))
#define PDSS_TX_CTRL_DEFAULT                                (0x8f200041UL)

/*
 * For SOP Only.
 * This register constains the Transmit GoodCRC Message Header except the
 * MessageID which Is handled by Hardware.
 * [11:9] Message ID (This is handled by HardWare)
 */
#define PDSS_TX_CTRL_GOODCRC_MSG_BITS_MASK                  (0x0000ffffU) /* <0:15> R:RW:65: */
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
#define PDSS_TX_CTRL_TX_RETRY_ENABLE                        (1UL << 19) /* <19:19> RW1C:RW:0: */


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
#define PDSS_TX_CTRL_TX_REG_TIMER_MASK                      (0x3f000000UL) /* <24:29> R:RW:15: */
#define PDSS_TX_CTRL_TX_REG_TIMER_POS                       (24UL)


/*
 * Setting this bit will enable corrupting the TX CRC when there is TX Sram
 * Under Flow is detected. This should be left to default for normal operation.
 */
#define PDSS_TX_CTRL_TX_CORRUPT_CRC_ON_UNDER_FLOW           (1UL << 31) /* <31:31> R:RW:1: */


/*
 * Transmit SOP order set
 */
#define PDSS_TX_SOP_ORDER_SET_ADDRESS                       (0x400a00f8UL)
#define PDSS_TX_SOP_ORDER_SET                               (*(volatile uint32_t *)(0x400a00f8UL))
#define PDSS_TX_SOP_ORDER_SET_DEFAULT                       (0x0008e318UL)

/*
 * Transmit SOP order Set use in transmit except GoodCrcMsg
 */
#define PDSS_TX_SOP_ORDER_SET_TX_SOP_OS_MASK                (0x000fffffUL) /* <0:19> R:RW:582424: */
#define PDSS_TX_SOP_ORDER_SET_TX_SOP_OS_POS                 (0UL)


/*
 * Transmit Hard/Cable reset order set
 */
#define PDSS_TX_HARD_CABLE_ORDER_SET_ADDRESS                (0x400a00fcUL)
#define PDSS_TX_HARD_CABLE_ORDER_SET                        (*(volatile uint32_t *)(0x400a00fcUL))
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
#define PDSS_CRC_COUNTER_ADDRESS                            (0x400a0100UL)
#define PDSS_CRC_COUNTER                                    (*(volatile uint32_t *)(0x400a0100UL))
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
#define PDSS_INTER_PACKET_COUNTER_ADDRESS                   (0x400a0104UL)
#define PDSS_INTER_PACKET_COUNTER                           (*(volatile uint32_t *)(0x400a0104UL))
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
 * m0s8tcpwm_ver2 IP at the full chip. The mapping of the these signals is
 * SoC depended and it is defined
 * in SAS.
 */
#define PDSS_TIMER_TRIGGER_ADDRESS                          (0x400a0108UL)
#define PDSS_TIMER_TRIGGER                                  (*(volatile uint32_t *)(0x400a0108UL))
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
 * Interrupt DDFT Selections
 */
#define PDSS_INTR_DDFT_MUX_ADDRESS                          (0x400a010cUL)
#define PDSS_INTR_DDFT_MUX                                  (*(volatile uint32_t *)(0x400a010cUL))
#define PDSS_INTR_DDFT_MUX_DEFAULT                          (0x00000000UL)

/*
 * 70      intr_cause_vswap_vbus_less_5_done
 * 69      intr_cause_swapt_command_done_done
 * 68      intr_cause_swap_queue_done
 * 67      intr_cause_swap_unstable_done
 * 66      intr_cause_swap_unpluged_done
 * 65      intr_cause_swap_pluged_done
 * 64      intr_cause_swap_irq_done
 * 63      intr_cause_ngdo_c_spacing_done_done
 * 62      intr_cause_ngdo_p_spacing_done_done
 * 61      intr_cause_vreg20v_switch_done
 * 60      intr_cause_vddd_sw_switch_done
 * 59      intr_cause_chunk_det_done
 * 58      intr_cause_tx_sram_under_flow_done
 * 57      intr_cause_rx_sram_over_flow_done
 * 56      intr_cause_spare5_done
 * 55      intr_cause_spare4_done
 * 54      intr_cause_spare3_done
 * 53      intr_cause_extended_msg_det_done
 * 52      intr_cause_hpdt_command_done_done
 * 51      intr_cause_hpd_queue_done
 * 50      intr_cause_hpd_unstable_done
 * 49      intr_cause_hpd_unpluged_done
 * 48      intr_cause_hpd_pluged_done
 * 47      intr_cause_hpd_irq_done
 * 46      intr_cause_ui_cal_done_done
 * 45      intr_cause_pulse_min_violated_done
 * 44      intr_cause_pulse_max_violated_done
 * 43      intr1_cause_spare7_done
 * 42      intr1_cause_spare6_done
 * 41      intr1_cause_hpdin_changed_done
 * 40      intr1_cause_cmp_out_done[1]
 * 39      intr1_cause_cmp_out_done[0]
 * 38      intr1_cause_v5v_done
 * 37      intr1_cause_vcmp_dn_done
 * 36      intr1_cause_vcmp_up_done
 * 35      intr1_cause_vcmp_la_done
 * 34      intr1_cause_cc2_changed_done
 * 33      intr1_cause_cc1_changed_done
 * 32      intr1_cause_vconn2_changed_done
 * 31      intr1_cause_vconn1_changed_done
 * 30      intr_cause_cmp_out_det_done[1]
 * 29      intr_cause_sar_done[1]
 * 28      intr_cause_rx_state_idle_done
 * 27      intr_cause_tx_state_idle_done
 * 26      intr_cause_tx_regulator_enabled_done
 * 25      intr_cause_tx_cc_data_oen_deassert_done
 * 24      intr_cause_tx_cc_data_oen_assert_done
 * 23      intr_cause_kchar_error_done
 * 22      intr_cause_tx_retry_enable_clrd_done
 * 21      intr_cause_rx_sram_half_end_done
 * 20      intr_cause_tx_sram_half_end_done
 * 19      intr_cause_cmp_out_det_done[0]
 * 18      intr_cause_collision_type4_done
 * 17      intr_cause_collision_type3_done
 * 16      intr_cause_collision_type2_done
 * 15      intr_cause_collision_type1_done
 * 14      intr_cause_crc_rx_timer_exp_done
 * 13      intr_cause_cc_no_valid_data_detected_done
 * 12      intr_cause_cc_valid_data_detected_done
 * 11      intr_cause_tx_goodcrc_msg_done
 * 10      intr_cause_sar_done[0]
 * 9       intr_cause_rcv_rst_done
 * 8       intr_cause_tx_hard_rst_done
 * 7       intr_cause_tx_packet_done
 * 6       intr_cause_rx_over_run_done
 * 5       intr_cause_eop_error_done
 * 4       intr_cause_rcv_expt_goodcrc_msg_complete_done
 * 3       intr_cause_rcv_goodcrc_msg_complete_done
 * 2       intr_cause_rx_sop_done
 * 1       intr_cause_rcv_bad_packet_complete_done
 * 0       intr_cause_rcv_good_packet_complete_done
 */
#define PDSS_INTR_DDFT_MUX_INTR_DDFT0_SEL_MASK              (0x0000007fUL) /* <0:6> R:RW:0: */
#define PDSS_INTR_DDFT_MUX_INTR_DDFT0_SEL_POS               (0UL)


/*
 * 70      intr_cause_vswap_vbus_less_5_done
 * 69      intr_cause_swapt_command_done_done
 * 68      intr_cause_swap_queue_done
 * 67      intr_cause_swap_unstable_done
 * 66      intr_cause_swap_unpluged_done
 * 65      intr_cause_swap_pluged_done
 * 64      intr_cause_swap_irq_done
 * 63      intr_cause_ngdo_c_spacing_done_done
 * 62      intr_cause_ngdo_p_spacing_done_done
 * 61      intr_cause_vreg20v_switch_done
 * 60      intr_cause_vddd_sw_switch_done
 * 59      intr_cause_chunk_det_done
 * 58      intr_cause_tx_sram_under_flow_done
 * 57      intr_cause_rx_sram_over_flow_done
 * 56      intr_cause_spare5_done
 * 55      intr_cause_spare4_done
 * 54      intr_cause_spare3_done
 * 53      intr_cause_extended_msg_det_done
 * 52      intr_cause_hpdt_command_done_done
 * 51      intr_cause_hpd_queue_done
 * 50      intr_cause_hpd_unstable_done
 * 49      intr_cause_hpd_unpluged_done
 * 48      intr_cause_hpd_pluged_done
 * 47      intr_cause_hpd_irq_done
 * 46      intr_cause_ui_cal_done_done
 * 45      intr_cause_pulse_min_violated_done
 * 44      intr_cause_pulse_max_violated_done
 * 43      intr1_cause_spare7_done
 * 42      intr1_cause_spare6_done
 * 41      intr1_cause_hpdin_changed_done
 * 40      intr1_cause_cmp_out_done[1]
 * 39      intr1_cause_cmp_out_done[0]
 * 38      intr1_cause_v5v_done
 * 37      intr1_cause_vcmp_dn_done
 * 36      intr1_cause_vcmp_up_done
 * 35      intr1_cause_vcmp_la_done
 * 34      intr1_cause_cc2_changed_done
 * 33      intr1_cause_cc1_changed_done
 * 32      intr1_cause_vconn2_changed_done
 * 31      intr1_cause_vconn1_changed_done
 * 30      intr_cause_cmp_out_det_done[1]
 * 29      intr_cause_sar_done[1]
 * 28      intr_cause_rx_state_idle_done
 * 27      intr_cause_tx_state_idle_done
 * 26      intr_cause_tx_regulator_enabled_done
 * 25      intr_cause_tx_cc_data_oen_deassert_done
 * 24      intr_cause_tx_cc_data_oen_assert_done
 * 23      intr_cause_kchar_error_done
 * 22      intr_cause_tx_retry_enable_clrd_done
 * 21      intr_cause_rx_sram_half_end_done
 * 20      intr_cause_tx_sram_half_end_done
 * 19      intr_cause_cmp_out_det_done[0]
 * 18      intr_cause_collision_type4_done
 * 17      intr_cause_collision_type3_done
 * 16      intr_cause_collision_type2_done
 * 15      intr_cause_collision_type1_done
 * 14      intr_cause_crc_rx_timer_exp_done
 * 13      intr_cause_cc_no_valid_data_detected_done
 * 12      intr_cause_cc_valid_data_detected_done
 * 11      intr_cause_tx_goodcrc_msg_done
 * 10      intr_cause_sar_done[0]
 * 9       intr_cause_rcv_rst_done
 * 8       intr_cause_tx_hard_rst_done
 * 7       intr_cause_tx_packet_done
 * 6       intr_cause_rx_over_run_done
 * 5       intr_cause_eop_error_done
 * 4       intr_cause_rcv_expt_goodcrc_msg_complete_done
 * 3       intr_cause_rcv_goodcrc_msg_complete_done
 * 2       intr_cause_rx_sop_done
 * 1       intr_cause_rcv_bad_packet_complete_done
 * 0       intr_cause_rcv_good_packet_complete_done
 */
#define PDSS_INTR_DDFT_MUX_INTR_DDFT1_SEL_MASK              (0x00003f80UL) /* <7:13> R:RW:0: */
#define PDSS_INTR_DDFT_MUX_INTR_DDFT1_SEL_POS               (7UL)


/*
 * IP DDFT Selections
 */
#define PDSS_DDFT_MUX_ADDRESS                               (0x400a0110UL)
#define PDSS_DDFT_MUX                                       (*(volatile uint32_t *)(0x400a0110UL))
#define PDSS_DDFT_MUX_DEFAULT                               (0x00000000UL)

/*
 * 47      intr_swap_queue_set
 * 46      intr_swap_unstable_set
 * 45      intr_swap_unpluged_set
 * 44      intr_swap_pluged_set
 * 43      intr_swap_irq_set
 * 42      intr_swapt_command_done_set
 * 41      intr_ddft1
 * 40      intr_ddft0
 * 39      ncell_ddft1
 * 38      ncell_ddft0
 * 37      spare7_fx_scan
 * 36      spare6_fx_scan
 * 35      intr_hpd_queue_set
 * 34      intr_hpd_unstable_set
 * 33      intr_hpd_unpluged_set
 * 32      intr_hpd_pluged_set
 * 31      intr_hpd_irq_set
 * 30      intr_hpdt_command_done_set
 * 29      hpdin_fx_scan
 * 28      ddft_collision_src[4]
 * 27      ddft_collision_src[3]
 * 26      ddft_collision_src[2]
 * 25      ddft_collision_src[1]
 * 24      ddft_collision_src[0]
 * 23      cmp_out_fx_scan[1]
 * 22      cmp_out_fx_scan[0]
 * 21      v5v_fx_scan
 * 20      ddft_cc_core_rx_data
 * 19      vcmp_fs
 * 18      ddft_cc_ctrl_tx_en
 * 17      ddft_cc_tx_data_eop
 * 16      ddft_cc_tx_data_valid
 * 15      clk_tx
 * 14      vconn2_fx_scan
 * 13      vconn1_fx_scan
 * 12      vcmp_dn_fx_scan
 * 11      vcmp_la_fx_scan
 * 10      vcmp_up_fx_scan
 * 9       ddft_sop_valid
 * 8       ddft_rx_eop
 * 7       ddft_raw_cc_rx_valid
 * 6       ddft_cc_rx_bit_en
 * 5       ddft_cc_core_tx_data
 * 4       cc_tx_data
 * 3       clk_rx
 * 2       cc1_fx_scan
 * 1       cc2_fx_scan
 * 0: DDFT0 from previous m0s8usbpd instantiation if any
 */
#define PDSS_DDFT_MUX_DDFT0_SEL_MASK                        (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_DDFT_MUX_DDFT0_SEL_POS                         (0UL)


/*
 * 47      intr_swap_queue_set
 * 46      intr_swap_unstable_set
 * 45      intr_swap_unpluged_set
 * 44      intr_swap_pluged_set
 * 43      intr_swap_irq_set
 * 42      intr_swapt_command_done_set
 * 41      intr_ddft1
 * 40      intr_ddft0
 * 39      ncell_ddft1
 * 38      ncell_ddft0
 * 37      spare7_fx_scan
 * 36      spare6_fx_scan
 * 35      intr_hpd_queue_set
 * 34      intr_hpd_unstable_set
 * 33      intr_hpd_unpluged_set
 * 32      intr_hpd_pluged_set
 * 31      intr_hpd_irq_set
 * 30      intr_hpdt_command_done_set
 * 29      hpdin_fx_scan
 * 28      ddft_collision_src[4]
 * 27      ddft_collision_src[3]
 * 26      ddft_collision_src[2]
 * 25      ddft_collision_src[1]
 * 24      ddft_collision_src[0]
 * 23      cmp_out_fx_scan[1]
 * 22      cmp_out_fx_scan[0]
 * 21      v5v_fx_scan
 * 20      ddft_cc_core_rx_data
 * 19      vcmp_fs
 * 18      ddft_cc_ctrl_tx_en
 * 17      ddft_cc_tx_data_eop
 * 16      ddft_cc_tx_data_valid
 * 15      clk_tx
 * 14      vconn2_fx_scan
 * 13      vconn1_fx_scan
 * 12      vcmp_dn_fx_scan
 * 11      vcmp_la_fx_scan
 * 10      vcmp_up_fx_scan
 * 9       ddft_sop_valid
 * 8       ddft_rx_eop
 * 7       ddft_raw_cc_rx_valid
 * 6       ddft_cc_rx_bit_en
 * 5       ddft_cc_core_tx_data
 * 4       cc_tx_data
 * 3       clk_rx
 * 2       cc1_fx_scan
 * 1       cc2_fx_scan
 * 0: DDFT1 from previous m0s8usbpd instantiation if any
 */
#define PDSS_DDFT_MUX_DDFT1_SEL_MASK                        (0x00000fc0UL) /* <6:11> R:RW:0: */
#define PDSS_DDFT_MUX_DDFT1_SEL_POS                         (6UL)


/*
 * Wakeup Interrupts edge and filter configuration
 */
#define PDSS_INTR_1_CFG_ADDRESS                             (0x400a0114UL)
#define PDSS_INTR_1_CFG                                     (*(volatile uint32_t *)(0x400a0114UL))
#define PDSS_INTR_1_CFG_DEFAULT                             (0xd6df6aa2UL)

/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR_1_CFG_VCONN1_CFG_MASK                     (0x00000003UL) /* <0:1> R:RW:2:VCONN_EN */
#define PDSS_INTR_1_CFG_VCONN1_CFG_POS                      (0UL)


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR_1_CFG_CC1_CFG_MASK                        (0x00000030UL) /* <4:5> R:RW:2: */
#define PDSS_INTR_1_CFG_CC1_CFG_POS                         (4UL)


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR_1_CFG_CC2_CFG_MASK                        (0x000000c0UL) /* <6:7> R:RW:2: */
#define PDSS_INTR_1_CFG_CC2_CFG_POS                         (6UL)


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR_1_CFG_VCMP_UP_CFG_MASK                    (0x00000300UL) /* <8:9> R:RW:2: */
#define PDSS_INTR_1_CFG_VCMP_UP_CFG_POS                     (8UL)


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR_1_CFG_VCMP_DN_CFG_MASK                    (0x00000c00UL) /* <10:11> R:RW:2: */
#define PDSS_INTR_1_CFG_VCMP_DN_CFG_POS                     (10UL)


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR_1_CFG_VCMP_LA_CFG_MASK                    (0x00003000UL) /* <12:13> R:RW:2: */
#define PDSS_INTR_1_CFG_VCMP_LA_CFG_POS                     (12UL)


/*
 * Filtering the VCONN1_DET from s8usbpd.:
 * 0: No Filtering
 * 1: Enable 2 cycles of clk_lf filtering
 */
#define PDSS_INTR_1_CFG_VCONN1_FILT_EN                      (1UL << 14) /* <14:14> R:RW:1:VCONN_EN */


/*
 * Filtering the CC1_ATTACH from s8usbpd.:
 * 0: No Filtering
 * 1: Enable 2 cycles of clk_lf filtering
 */
#define PDSS_INTR_1_CFG_CC1_CFG_FILT_EN                     (1UL << 16) /* <16:16> R:RW:1: */


/*
 * Filtering the CC2_ATTACH from s8usbpd.:
 * 0: No Filtering
 * 1: Enable 2 cycles of clk_lf filtering
 */
#define PDSS_INTR_1_CFG_CC2_FILT_EN                         (1UL << 17) /* <17:17> R:RW:1: */


/*
 * Filtering the VCMP_UP from s8usbpd.:
 * 0: No Filtering
 * 1: Enable 2 cycles of clk_lf filtering
 */
#define PDSS_INTR_1_CFG_VCMP_UP_FILT_EN                     (1UL << 18) /* <18:18> R:RW:1: */


/*
 * Filtering the VCMP_DNfrom s8usbpd.:
 * 0: No Filtering
 * 1: Enable 2 cycles of clk_lf filtering
 */
#define PDSS_INTR_1_CFG_VCMP_DN_FILT_EN                     (1UL << 19) /* <19:19> R:RW:1: */


/*
 * Filtering the v5v_det from s8usbpd so FW can enable the VCONN FET to route
 * the V5V to appropriate VCONN line (CC1/CC2)
 * 0: No Filtering
 * 1: Enable 2 cycles of clk_lf filtering
 */
#define PDSS_INTR_1_CFG_V5V_FILT_EN                         (1UL << 20) /* <20:20> R:RW:1:FET_300_EN */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR_1_CFG_V5V_CFG_MASK                        (0x00600000UL) /* <21:22> R:RW:2:FET_300_EN */
#define PDSS_INTR_1_CFG_V5V_CFG_POS                         (21UL)


/*
 * Filtering the cmp_out from first s8usbpd_adc_top.:
 * 0: No Filtering
 * 1: Refer to ADC1_SAR_CTRL.CMP_OUT_TO_GPIO_FILT_SEL
 */
#define PDSS_INTR_1_CFG_CMP_OUT1_FILT_EN                    (1UL << 23) /* <23:23> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR_1_CFG_ADC1_CFG_MASK                       (0x03000000UL) /* <24:25> R:RW:2: */
#define PDSS_INTR_1_CFG_ADC1_CFG_POS                        (24UL)


/*
 * Filtering the cmp_out from first s8usbpd_adc_top.:
 * 0: No Filtering
 * 1: Refer to ADC2_SAR_CTRL.CMP_OUT_TO_GPIO_FILT_SEL
 */
#define PDSS_INTR_1_CFG_CMP_OUT2_FILT_EN                    (1UL << 26) /* <26:26> R:RW:1: */


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR_1_CFG_ADC2_CFG_MASK                       (0x18000000UL) /* <27:28> R:RW:2: */
#define PDSS_INTR_1_CFG_ADC2_CFG_POS                        (27UL)


/*
 * Edge detect positive/negative enable/disable. For HPD_IN input
 */
#define PDSS_INTR_1_CFG_HPDIN_CFG_MASK                      (0x60000000UL) /* <29:30> R:RW:2: */
#define PDSS_INTR_1_CFG_HPDIN_CFG_POS                       (29UL)


/*
 * Filtering the HPDIN_ATTACH .
 * 0: No Filtering
 * 1: Enable 2 cycles of clk_lf filtering
 */
#define PDSS_INTR_1_CFG_HPDIN_FILT_EN                       (1UL << 31) /* <31:31> R:RW:1: */


/*
 * INTR0 Cause. These are the active interrupts get reflected on interrupt_usbpd
 * pin.
 */
#define PDSS_INTR0_ADDRESS                                  (0x400a0118UL)
#define PDSS_INTR0                                          (*(volatile uint32_t *)(0x400a0118UL))
#define PDSS_INTR0_DEFAULT                                  (0x00000000UL)

/*
 * Receive a Good non-GoodCRC-message Data Packet Complete. Indicates that
 * the Receive Packet has been received in its entirety.  The received packet
 * had no CRC and no KCHAR error.
 * If this interrupt is not cleared, then RX_OVER_RUN will be set on the
 * next new data and the new data won't be written into RX SRAM.
 */
#define PDSS_INTR0_RCV_GOOD_PACKET_COMPLETE                 (1UL << 0) /* <0:0> RW1S:RW1C:0: */


/*
 * Receive a Bad non-GoodCRC-message Data Packet Complete. Indicates that
 * the Receive Packet has been received in its entirety.  The received packet
 * had CRC or KCHAR error.
 */
#define PDSS_INTR0_RCV_BAD_PACKET_COMPLETE                  (1UL << 1) /* <1:1> RW1S:RW1C:0: */


/*
 * Receive a SOP. FW should read SOP_TYPE_DETECTED for the SOP type
 */
#define PDSS_INTR0_RX_SOP                                   (1UL << 2) /* <2:2> RW1S:RW1C:0: */


/*
 * Receive GoodCRC-message Complete. Indicates that the GoodCRC-message is
 * stored in RX_GOODCRC_MSG register.
 * The received GoodCRC-message had no CRC error and no KCHAR error
 */
#define PDSS_INTR0_RCV_GOODCRC_MSG_COMPLETE                 (1UL << 3) /* <3:3> RW1S:RW1C:0: */


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
#define PDSS_INTR0_RCV_EXPT_GOODCRC_MSG_COMPLETE            (1UL << 4) /* <4:4> RW1S:RW1C:0: */


/*
 * Received Symbol wasn't a valid EOP K-Code.  It should be evaludated after
 * RCV_PACKET_COMPLETE.
 */
#define PDSS_INTR0_EOP_ERROR                                (1UL << 5) /* <5:5> RW1S:RW1C:0: */


/*
 * New data was received when the RCV_PACKET_COMPLETE is not cleared by CPU.
 */
#define PDSS_INTR0_RX_OVER_RUN                              (1UL << 6) /* <6:6> RW1S:RW1C:0: */


/*
 * Transmitter done sending data packet.
 */
#define PDSS_INTR0_TX_PACKET_DONE                           (1UL << 7) /* <7:7> RW1S:RW1C:0: */


/*
 * Transmitter done sending Hard Reset
 */
#define PDSS_INTR0_TX_HARD_RST_DONE                         (1UL << 8) /* <8:8> RW1S:RW1C:0: */


/*
 * Received a REST. FW should read RST_TYPE for the type of RST.
 * Firmware should process this interrupt according to the USB-PD spec.
 * Hardware does not process the Reset packets other than providing this
 * interrupt.
 * Hardware will stop processing any pending transmit packet until this interrupt
 * is cleared.
 */
#define PDSS_INTR0_RCV_RST                                  (1UL << 9) /* <9:9> RW1S:RW1C:0: */


/*
 * Marks Completion of First ADC SAR conversion at the end of 8 cycles of
 * clk_sar when SAR_EN is "1"
 */
#define PDSS_INTR0_SAR1_DONE                                (1UL << 10) /* <10:10> RW1S:RW1C:0: */


/*
 * A GoodCRC message was transmitted.
 */
#define PDSS_INTR0_TX_GOODCRC_MSG_DONE                      (1UL << 11) /* <11:11> RW1S:RW1C:0: */


/*
 * Valid Data detected on the CC line
 */
#define PDSS_INTR0_CC_VALID_DATA_DETECTED                   (1UL << 12) /* <12:12> RW1S:RW1C:0: */


/*
 * Valid Data got de-asserted on the CC line
 */
#define PDSS_INTR0_CC_NO_VALID_DATA_DETECTED                (1UL << 13) /* <13:13> RW1S:RW1C:0: */


/*
 * CRCReceiveTimer has expired
 */
#define PDSS_INTR0_CRC_RX_TIMER_EXP                         (1UL << 14) /* <14:14> RW1S:RW1C:0: */


/*
 * Transmit Collision Type1:
 * Collsion is detected Due to TX_GO(TX Data)/RX has occurred
 */
#define PDSS_INTR0_COLLISION_TYPE1                          (1UL << 15) /* <15:15> RW1S:RW1C:0: */


/*
 * Transmit Collision Type2:
 * Collsion is detected  due to TX-RETRY/RX has occurred
 */
#define PDSS_INTR0_COLLISION_TYPE2                          (1UL << 16) /* <16:16> RW1S:RW1C:0: */


/*
 * Transmit Collision Type3:
 * Collsion is detected due to TX-GoodCrc_MSG/RX has occurred
 */
#define PDSS_INTR0_COLLISION_TYPE3                          (1UL << 17) /* <17:17> RW1S:RW1C:0: */


/*
 * Transmit Collision Type4:
 * Collsion is detected due to TX_SEND_RST/RX has occurred
 */
#define PDSS_INTR0_COLLISION_TYPE4                          (1UL << 18) /* <18:18> RW1S:RW1C:0: */


/*
 * cmp_out pin of first ADC s8usbpd_adc_top changed based on the ADC_SAR_CTRL.INTR_CMP_SEL
 * INTR1.CMP_OUT1_CHANGED has the same function except INTR1 is for wakeup
 */
#define PDSS_INTR0_CMP_OUT1_DET                             (1UL << 19) /* <19:19> RW1S:RW1C:0: */


/*
 * Hardware has passed reading the data from Half or End of the TX SRAM Memory
 * Location
 */
#define PDSS_INTR0_TX_SRAM_HALF_END                         (1UL << 20) /* <20:20> RW1S:RW1C:0: */


/*
 * Hardware has passed writing the data to Half or End of the RX SRAM Memory
 * Location
 */
#define PDSS_INTR0_RX_SRAM_HALF_END                         (1UL << 21) /* <21:21> RW1S:RW1C:0: */


/*
 * TX_RETRY_ENABLE is cleared
 */
#define PDSS_INTR0_TX_RETRY_ENABLE_CLRD                     (1UL << 22) /* <22:22> RW1S:RW1C:0: */


/*
 * Received Symbol wasn't a valid K-Code.
 */
#define PDSS_INTR0_KCHAR_ERROR                              (1UL << 23) /* <23:23> RW1S:RW1C:0: */


/*
 * TX Data Output Enable of TX-CC is asserted
 */
#define PDSS_INTR0_TX_CC_DATA_OEN_ASSERT                    (1UL << 24) /* <24:24> RW1S:RW1C:0: */


/*
 * TX Data Output Enable of TX-CC is de-asserted
 */
#define PDSS_INTR0_TX_CC_DATA_OEN_DEASSERT                  (1UL << 25) /* <25:25> RW1S:RW1C:0: */


/*
 * The TX CC regulator is enabled
 */
#define PDSS_INTR0_TX_REGULATOR_ENABLED                     (1UL << 26) /* <26:26> RW1S:RW1C:0: */


/*
 * The TX State Machine entered Idle state
 */
#define PDSS_INTR0_TX_STATE_IDLE                            (1UL << 27) /* <27:27> RW1S:RW1C:0: */


/*
 * The RX State Machine entered Idle state
 */
#define PDSS_INTR0_RX_STATE_IDLE                            (1UL << 28) /* <28:28> RW1S:RW1C:0: */


/*
 * Marks Completion of Second ADC SAR conversion at the end of 8 cycles of
 * clk_sar when SAR_EN is "1"
 */
#define PDSS_INTR0_SAR2_DONE                                (1UL << 29) /* <29:29> RW1S:RW1C:0: */


/*
 * cmp_out pin of second ADC s8usbpd_adc_top changed based on the ADC_SAR_CTRL.INTR_CMP_SEL
 * INTR1.CMP_OUT2_CHANGED has the same function except INTR1 is for wakeup
 */
#define PDSS_INTR0_CMP_OUT2_DET                             (1UL << 30) /* <30:30> RW1S:RW1C:0: */


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
#define PDSS_INTR1_ADDRESS                                  (0x400a011cUL)
#define PDSS_INTR1                                          (*(volatile uint32_t *)(0x400a011cUL))
#define PDSS_INTR1_DEFAULT                                  (0x00000000UL)

/*
 * VCONN1 changed (wakeup interrupt from deepsleep)
 * Check the STATUS.VCONN1_STATUS value
 */
#define PDSS_INTR1_VCONN1_CHANGED                           (1UL << 0) /* <0:0> RW1S:RW1C:0:VCONN_EN */


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
#define PDSS_INTR1_V5V_CHANGED                              (1UL << 7) /* <7:7> RW1S:RW1C:0:FET_300_EN */


/*
 * CMP_OUT1 changed (wakeup interrupt from deepsleep)
 * Check the STATUS.ADC1_COMP_OUT_STATUS value
 */
#define PDSS_INTR1_CMP_OUT1_CHANGED                         (1UL << 8) /* <8:8> RW1S:RW1C:0: */


/*
 * CMP_OUT2 changed (wakeup interrupt from deepsleep)
 * Check the STATUS.ADC2_COMP_OUT_STATUS value
 */
#define PDSS_INTR1_CMP_OUT2_CHANGED                         (1UL << 9) /* <9:9> RW1S:RW1C:0: */


/*
 * HPD_IN changed (wakeup interrupt from deepsleep). For HPD input
 * Check the STATUS.HPDIN_STATUS value. Any change in HPD input will trigger
 * a wakeup interrupt.
 */
#define PDSS_INTR1_HPDIN_CHANGED                            (1UL << 10) /* <10:10> RW1S:RW1C:0: */


/*
 * SPARE6. Check the STATUS.SPARE6_STATUS value
 */
#define PDSS_INTR1_SPARE6                                   (1UL << 11) /* <11:11> RW1S:RW1C:0: */


/*
 * SPARE7. Check the STATUS.SPARE7_STATUS value
 */
#define PDSS_INTR1_SPARE7                                   (1UL << 12) /* <12:12> RW1S:RW1C:0: */


/*
 * INTR0 Set
 */
#define PDSS_INTR0_SET_ADDRESS                              (0x400a0120UL)
#define PDSS_INTR0_SET                                      (*(volatile uint32_t *)(0x400a0120UL))
#define PDSS_INTR0_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RCV_GOOD_PACKET_COMPLETE             (1UL << 0) /* <0:0> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RCV_BAD_PACKET_COMPLETE              (1UL << 1) /* <1:1> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RX_SOP                               (1UL << 2) /* <2:2> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RCV_GOODCRC_MSG_COMPLETE             (1UL << 3) /* <3:3> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RCV_EXPT_GOODCRC_MSG_COMPLETE        (1UL << 4) /* <4:4> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_EOP_ERROR                            (1UL << 5) /* <5:5> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RX_OVER_RUN                          (1UL << 6) /* <6:6> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_PACKET_DONE                       (1UL << 7) /* <7:7> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_HARD_RST_DONE                     (1UL << 8) /* <8:8> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RCV_RST                              (1UL << 9) /* <9:9> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_SAR1_DONE                            (1UL << 10) /* <10:10> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_GOODCRC_MSG_DONE                  (1UL << 11) /* <11:11> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_CC_VALID_DATA_DETECTED               (1UL << 12) /* <12:12> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_CC_NO_VALID_DATA_DETECTED            (1UL << 13) /* <13:13> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_CRC_RX_TIMER_EXP                     (1UL << 14) /* <14:14> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_COLLISION_TYPE1                      (1UL << 15) /* <15:15> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_COLLISION_TYPE2                      (1UL << 16) /* <16:16> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_COLLISION_TYPE3                      (1UL << 17) /* <17:17> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_COLLISION_TYPE4                      (1UL << 18) /* <18:18> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_CMP_OUT1_DET                         (1UL << 19) /* <19:19> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_SRAM_HALF_END                     (1UL << 20) /* <20:20> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RX_SRAM_HALF_END                     (1UL << 21) /* <21:21> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_RETRY_ENABLE_CLRD                 (1UL << 22) /* <22:22> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_KCHAR_ERROR                          (1UL << 23) /* <23:23> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_CC_DATA_OEN_ASSERT                (1UL << 24) /* <24:24> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_CC_DATA_OEN_DEASSERT              (1UL << 25) /* <25:25> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_REGULATOR_ENABLED                 (1UL << 26) /* <26:26> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_TX_STATE_IDLE                        (1UL << 27) /* <27:27> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_RX_STATE_IDLE                        (1UL << 28) /* <28:28> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_SAR2_DONE                            (1UL << 29) /* <29:29> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_SET_CMP_OUT2_DET                         (1UL << 30) /* <30:30> A:RW1S:0: */


/*
 * INTR1 Set
 */
#define PDSS_INTR1_SET_ADDRESS                              (0x400a0124UL)
#define PDSS_INTR1_SET                                      (*(volatile uint32_t *)(0x400a0124UL))
#define PDSS_INTR1_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_VCONN1_CHANGED                       (1UL << 0) /* <0:0> A:RW1S:0:VCONN_EN */


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
#define PDSS_INTR1_SET_V5V_CHANGED                          (1UL << 7) /* <7:7> A:RW1S:0:FET_300_EN */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CMP_OUT1_CHANGED                     (1UL << 8) /* <8:8> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_CMP_OUT2_CHANGED                     (1UL << 9) /* <9:9> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_HPDIN_CHANGED                        (1UL << 10) /* <10:10> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_SPARE6                               (1UL << 11) /* <11:11> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_SET_SPARE7                               (1UL << 12) /* <12:12> A:RW1S:0: */


/*
 * INTR0 Mask
 */
#define PDSS_INTR0_MASK_ADDRESS                             (0x400a0128UL)
#define PDSS_INTR0_MASK                                     (*(volatile uint32_t *)(0x400a0128UL))
#define PDSS_INTR0_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RCV_GOOD_PACKET_COMPLETE_MASK       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RCV_BAD_PACKET_COMPLETE_MASK        (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RX_SOP_MASK                         (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RCV_GOODCRC_MSG_COMPLETE_MASK       (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RCV_EXPT_GOODCRC_MSG_COMPLETE_MASK    (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_EOP_ERROR_MASK                      (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RX_OVER_RUN_MASK                    (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_PACKET_DONE_MASK                 (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_HARD_RST_DONE_MASK               (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RCV_RST_MASK                        (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_SAR1_DONE_MASK                      (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_GOODCRC_MSG_DONE_MASK            (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_CC_VALID_DATA_DETECTED_MASK         (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_CC_NO_VALID_DATA_DETECTED_MASK      (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_CRC_RX_TIMER_EXP_MASK               (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_COLLISION_TYPE1_MASK                (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_COLLISION_TYPE2_MASK                (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_COLLISION_TYPE3_MASK                (1UL << 17) /* <17:17> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_COLLISION_TYPE4_MASK                (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_CMP_OUT1_DET_MASK                   (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_SRAM_HALF_END_MASK               (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RX_SRAM_HALF_END_MASK               (1UL << 21) /* <21:21> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_RETRY_ENABLE_CLRD_MASK           (1UL << 22) /* <22:22> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_KCHAR_ERROR_MASK                    (1UL << 23) /* <23:23> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_CC_DATA_OEN_ASSERT_MASK          (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_CC_DATA_OEN_DEASSERT_MASK        (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_REGULATOR_ENABLED_MASK           (1UL << 26) /* <26:26> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_TX_STATE_IDLE_MASK                  (1UL << 27) /* <27:27> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_RX_STATE_IDLE_MASK                  (1UL << 28) /* <28:28> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_SAR2_DONE_MASK                      (1UL << 29) /* <29:29> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR0_MASK_CMP_OUT2_DET_MASK                   (1UL << 30) /* <30:30> R:RW:0: */


/*
 * INTR1 Mask
 */
#define PDSS_INTR1_MASK_ADDRESS                             (0x400a012cUL)
#define PDSS_INTR1_MASK                                     (*(volatile uint32_t *)(0x400a012cUL))
#define PDSS_INTR1_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_VCONN1_CHANGED_MASK                 (1UL << 0) /* <0:0> R:RW:0:VCONN_EN */


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
#define PDSS_INTR1_MASK_V5V_CHANGED_MASK                    (1UL << 7) /* <7:7> R:RW:0:FET_300_EN */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CMP_OUT1_CHANGED_MASK               (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_CMP_OUT2_CHANGED_MASK               (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_HPDIN_CHANGED_MASK                  (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_SPARE6_MASK                         (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR1_MASK_SPARE7_MASK                         (1UL << 12) /* <12:12> R:RW:0: */


/*
 * INTR0 Masked
 */
#define PDSS_INTR0_MASKED_ADDRESS                           (0x400a0130UL)
#define PDSS_INTR0_MASKED                                   (*(volatile uint32_t *)(0x400a0130UL))
#define PDSS_INTR0_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RCV_GOOD_PACKET_COMPLETE_MASKED    (1UL << 0) /* <0:0> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RCV_BAD_PACKET_COMPLETE_MASKED    (1UL << 1) /* <1:1> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RX_SOP_MASKED                     (1UL << 2) /* <2:2> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RCV_GOODCRC_MSG_COMPLETE_MASKED    (1UL << 3) /* <3:3> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RCV_EXPT_GOODCRC_MSG_COMPLETE_MASKED    (1UL << 4) /* <4:4> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_EOP_ERROR_MASKED                  (1UL << 5) /* <5:5> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RX_OVER_RUN_MASKED                (1UL << 6) /* <6:6> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_PACKET_DONE_MASKED             (1UL << 7) /* <7:7> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_HARD_RST_DONE_MASKED           (1UL << 8) /* <8:8> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RCV_RST_MASKED                    (1UL << 9) /* <9:9> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_SAR1_DONE_MASKED                  (1UL << 10) /* <10:10> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_GOODCRC_MSG_DONE_MASKED        (1UL << 11) /* <11:11> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_CC_VALID_DATA_DETECTED_MASKED     (1UL << 12) /* <12:12> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_CC_NO_VALID_DATA_DETECTED_MASKED    (1UL << 13) /* <13:13> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_CRC_RX_TIMER_EXP_MASKED           (1UL << 14) /* <14:14> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_COLLISION_TYPE1_MASKED            (1UL << 15) /* <15:15> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_COLLISION_TYPE2_MASKED            (1UL << 16) /* <16:16> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_COLLISION_TYPE3_MASKED            (1UL << 17) /* <17:17> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_COLLISION_TYPE4_MASKED            (1UL << 18) /* <18:18> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_CMP_OUT1_DET_MASKED               (1UL << 19) /* <19:19> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_SRAM_HALF_END_MASKED           (1UL << 20) /* <20:20> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RX_SRAM_HALF_END_MASKED           (1UL << 21) /* <21:21> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_RETRY_ENABLE_CLRD_MASKED       (1UL << 22) /* <22:22> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_KCHAR_ERROR_MASKED                (1UL << 23) /* <23:23> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_CC_DATA_OEN_ASSERT_MASKED      (1UL << 24) /* <24:24> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_CC_DATA_OEN_DEASSERT_MASKED    (1UL << 25) /* <25:25> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_REGULATOR_ENABLED_MASKED       (1UL << 26) /* <26:26> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_TX_STATE_IDLE_MASKED              (1UL << 27) /* <27:27> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_RX_STATE_IDLE_MASKED              (1UL << 28) /* <28:28> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_SAR2_DONE_MASKED                  (1UL << 29) /* <29:29> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR0_MASKED_CMP_OUT2_DET_MASKED               (1UL << 30) /* <30:30> RW:R:0: */


/*
 * INTR1 Masked
 */
#define PDSS_INTR1_MASKED_ADDRESS                           (0x400a0134UL)
#define PDSS_INTR1_MASKED                                   (*(volatile uint32_t *)(0x400a0134UL))
#define PDSS_INTR1_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_VCONN1_CHANGED_MASKED             (1UL << 0) /* <0:0> RW:R:0:VCONN_EN */


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
#define PDSS_INTR1_MASKED_V5V_CHANGED_MASKED                (1UL << 7) /* <7:7> RW:R:0:FET_300_EN */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CMP_OUT1_CHANGED_MASKED           (1UL << 8) /* <8:8> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_CMP_OUT2_CHANGED_MASKED           (1UL << 9) /* <9:9> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_HPDIN_CHANGED_MASKED              (1UL << 10) /* <10:10> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_SPARE6_MASKED                     (1UL << 11) /* <11:11> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR1_MASKED_SPARE7_MASKED                     (1UL << 12) /* <12:12> RW:R:0: */


/*
 * Debug Control Register
 */
#define PDSS_DEBUG_CTRL_ADDRESS                             (0x400a0138UL)
#define PDSS_DEBUG_CTRL                                     (*(volatile uint32_t *)(0x400a0138UL))
#define PDSS_DEBUG_CTRL_DEFAULT                             (0x037f0000UL)

/*
 * This register are for debugging purposes.
 * 0: Receive path is not at reset.
 * 1: Reset the logic on the receive path except the Hard-IP.
 *     FW should check STATUS.RX_BUSY to make sure it is zero before setting
 * this bit.
 */
#define PDSS_DEBUG_CTRL_RESET_RX                            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Message Cal State
 */
#define PDSS_DEBUG_CTRL_RX_MSG_CAL_STATE_MASK               (0x0000000eUL) /* <1:3> RW:R:0: */
#define PDSS_DEBUG_CTRL_RX_MSG_CAL_STATE_POS                (1UL)


/*
 * This register are for debugging purposes
 * 0: Transmit path is not at reset.
 * 1: Reset the logic on the transmit path except the Hard-IP.
 *     FW should check STATUS.TX_BUSY to make sure it is zero before setting
 * this bit.
 */
#define PDSS_DEBUG_CTRL_RESET_TX                            (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Transmit state machine
 */
#define PDSS_DEBUG_CTRL_TX_MSG_STATE_MASK                   (0x00000e00UL) /* <9:11> RW:R:0: */
#define PDSS_DEBUG_CTRL_TX_MSG_STATE_POS                    (9UL)


/*
 * TX SRC Select state machine
 */
#define PDSS_DEBUG_CTRL_TX_SRC_SEL_STATE_MASK               (0x0000e000UL) /* <13:15> RW:R:0: */
#define PDSS_DEBUG_CTRL_TX_SRC_SEL_STATE_POS                (13UL)


/*
 * Number of TX preambles+1 (bit transitions)
 */
#define PDSS_DEBUG_CTRL_TX_PREAMBLE_CNT_MASK                (0x003f0000UL) /* <16:21> R:RW:63: */
#define PDSS_DEBUG_CTRL_TX_PREAMBLE_CNT_POS                 (16UL)


/*
 * EOP value for Both RX and TX
 */
#define PDSS_DEBUG_CTRL_EOP_VALUE_MASK                      (0x07c00000UL) /* <22:26> R:RW:13: */
#define PDSS_DEBUG_CTRL_EOP_VALUE_POS                       (22UL)


/*
 * This bit enables the Receive state machine to exit from RX DATA and CRC
 * states when an EOP is detected.
 * 0: Ignore EOP during the Data and CRC state
 * 1: Exit from Data and CRC state when an EOP is detected and move to STATUS
 * state.
 */
#define PDSS_DEBUG_CTRL_ENABLE_EXIT_ON_EOP                  (1UL << 27) /* <27:27> R:RW:0: */


/*
 * C-Connector Debug control register 0
 */
#define PDSS_DEBUG_CC_0_ADDRESS                             (0x400a013cUL)
#define PDSS_DEBUG_CC_0                                     (*(volatile uint32_t *)(0x400a013cUL))
#define PDSS_DEBUG_CC_0_DEFAULT                             (0x00000000UL)

/*
 * FW can only use this bit when the DEBUG_CC_0.TX_CC_DRIVE_SRC is set to
 * "1".
 * 0: Disables the Transceiver to transmit data
 * 1: Enables the Transceiver to transmit data
 */
#define PDSS_DEBUG_CC_0_TX_FIRST_BIT_LEVEL                  (1UL << 0) /* <0:0> R:RW:0: */


/*
 * When set enables TX to RX loopback before CC encoding/Decoding data.
 */
#define PDSS_DEBUG_CC_0_LOOP_BACK_NO_BMC                    (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Loobback after data encdoing. When set, the BMC encoded tx output will
 * loop back into cc_rx module.
 */
#define PDSS_DEBUG_CC_0_LOOP_BACK_WITH_BMC                  (1UL << 2) /* <2:2> R:RW:0: */


/*
 * When set, enables rx module to decode cc_rx line all the time. (Including
 * during transmission).
 */
#define PDSS_DEBUG_CC_0_EXT_LOOP_BACK                       (1UL << 3) /* <3:3> R:RW:0: */


/*
 * When set to one, clears the BMC decoder RX state machines and counters.
 * It has to be set back to zero for normal operations.
 * RX_RESET is not required to be set
 */
#define PDSS_DEBUG_CC_0_RX_CLEAR                            (1UL << 4) /* <4:4> R:RW:0: */


/*
 * When set to one, clears the TX state machines and counters. It has to
 * be set back to zero for normal operations.
 */
#define PDSS_DEBUG_CC_0_TX_CLEAR                            (1UL << 5) /* <5:5> R:RW:0: */


/*
 * This will selects either the m0s8usbpd_cc_tx or FW to control the TX_EN/TX_DATA
 * ports of the s8usbpd_cc_top Hard IP.
 * 0: Hardware (m0s8usbpd_cc_tx) controls the TX_EN/TX_DATA ports of the
 * s8usbpd_cc_top Hard IP.
 * 1: This option is for Testing/Char. FW controls the TX_EN/TX_DATA ports
 * of the s8usbpd_cc_top Hard IP.
 */
#define PDSS_DEBUG_CC_0_TX_CC_DRIVE_SRC                     (1UL << 6) /* <6:6> R:RW:0: */


/*
 * FW can use this bit to dirve the CC data line when the TX_CC_DRIVE_SRC=1
 * and CC_DPSLP_REF_CTRL.TX_EN=1
 * When TX_CC_DRIVE_SRC is set to one:
 * - TX_EN port of the s8usbpd_cc_top is controlled by CC_DPSLP_REF_CTRL.TX_EN
 * - TX_DATA port of s8usbpd_cc_top Hard IP is controlled by TX_CC_DATA
 */
#define PDSS_DEBUG_CC_0_TX_CC_DATA                          (1UL << 7) /* <7:7> R:RW:0: */


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
#define PDSS_DEBUG_CC_0_DEBUG_SEL_MASK                      (0x00001f00UL) /* <8:12> R:RW:0: */
#define PDSS_DEBUG_CC_0_DEBUG_SEL_POS                       (8UL)


/*
 * 0: RX_CC_DATA_VALID signal is not disabled.
 * 1: RX_CC_DATA_VALID signal is disabled.
 */
#define PDSS_DEBUG_CC_0_RX_CC_DATA_VALID_DIS                (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Delays CC_TX output by number of clocks specified by TX_DELAY_VALUE. CLK_HF
 * is used for this purpose.
 * 0: delay falling edge of CC TX output
 * 1: delay rising edge of CC TX output
 */
#define PDSS_DEBUG_CC_0_TX_DELAY_FALLN_RISE                 (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Specifies number of HF clocks to delay CC_TX output.
 * 0 - Do not delay output.
 * 1 - Delay by 1 HF clock
 * 2 - Delay by 2 HF clock.
 *
 * 15 - Delay by 15 HF clock.
 */
#define PDSS_DEBUG_CC_0_TX_DELAY_VALUE_MASK                 (0x00078000UL) /* <15:18> R:RW:0: */
#define PDSS_DEBUG_CC_0_TX_DELAY_VALUE_POS                  (15UL)


/*
 * Debug output register. Its inputs are selected by CC_DEBUG_SEL
 */
#define PDSS_DEBUG_CC_0_DEBUG_OUT_MASK                      (0x0ff00000UL) /* <20:27> RW:R:0: */
#define PDSS_DEBUG_CC_0_DEBUG_OUT_POS                       (20UL)


/*
 * Selection bit for deepsleep vs. active current reference for Rp pull-up
 * termination
 * 0 - Select deepsleep current reference
 * 1 - Select active current reference
 */
#define PDSS_DEBUG_CC_0_IREF_SEL                            (1UL << 28) /* <28:28> R:RW:0: */


/*
 * 0: Create EOP in the case of TX BIST
 * 1: Don't create EOP in the case of TX BIST
 */
#define PDSS_DEBUG_CC_0_DISABLE_BIST_EOP                    (1UL << 29) /* <29:29> R:RW:0: */


/*
 * 0: Source for turing off the VBUS_C Gate driver is SWAPR IRQ
 * 1: Source for turing off the VBUS_C Gate driver is SWAPR IRQ and VBUS_C
 * less than 5 volt
 */
#define PDSS_DEBUG_CC_0_VBUS_C_SWAP_SOURCE_SEL              (1UL << 30) /* <30:30> R:RW:0: */


/*
 * BW[1] bit of CSA_CTRL.BW[0]
 */
#define PDSS_DEBUG_CC_0_CSA_BW_1                            (1UL << 31) /* <31:31> R:RW:0: */


/*
 * C-Connector Debug control register 1
 */
#define PDSS_DEBUG_CC_1_ADDRESS                             (0x400a0140UL)
#define PDSS_DEBUG_CC_1                                     (*(volatile uint32_t *)(0x400a0140UL))
#define PDSS_DEBUG_CC_1_DEFAULT                             (0x000140ccUL)

/*
 * Number of preamble bits to be used in the RX for averaging CDR frequency.
 * Any time the value of these bits are changed, the values of NUM_TRANS_AVG
 * will need to be updated.
 */
#define PDSS_DEBUG_CC_1_NUM_PREAMBLE_AVG_MASK               (0x00000007UL) /* <0:2> R:RW:4: */
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
#define PDSS_DEBUG_CC_1_NUM_TRANS_AVG_MASK                  (0x000001f8UL) /* <3:8> R:RW:25: */
#define PDSS_DEBUG_CC_1_NUM_TRANS_AVG_POS                   (3UL)


/*
 * 0: Automatic bit rate calculation by HW
 * 1: Disables the RX-CC automatic bit rate detection and the RX_UI_PRERIOD
 * register is used for RX UI period.
 */
#define PDSS_DEBUG_CC_1_RX_DISABLE_AUTO_ADJ                 (1UL << 9) /* <9:9> R:RW:0: */


/*
 * When RX_DISABLE_AUTO_ADJ is set, this register value will define RX UI
 * period.
 */
#define PDSS_DEBUG_CC_1_RX_UI_PERIOD_MASK                   (0x0003fc00UL) /* <10:17> R:RW:80: */
#define PDSS_DEBUG_CC_1_RX_UI_PERIOD_POS                    (10UL)


/*
 * 0: The TX statemachine does not reset to Idle on the assertion of "send_good_crc"
 * 1: The TX statemachine does       reset to Idle on the assertion of "send_good_crc"
 */
#define PDSS_DEBUG_CC_1_TX_STATE_RST                        (1UL << 18) /* <18:18> R:RW:0: */


/*
 * 300ma switch CC1 Pull down value
 */
#define PDSS_DEBUG_CC_1_PFET300_PULLDN_EN_CC1               (1UL << 19) /* <19:19> R:RW:0: */


/*
 * 300ma switch CC2 Pull down value
 */
#define PDSS_DEBUG_CC_1_PFET300_PULLDN_EN_CC2               (1UL << 20) /* <20:20> R:RW:0: */


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
#define PDSS_DEBUG_CC_1_CC1_PULLDN_CFG                      (1UL << 21) /* <21:21> R:RW:0: */


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
#define PDSS_DEBUG_CC_1_CC2_PULLDN_CFG                      (1UL << 22) /* <22:22> R:RW:0: */


/*
 * 0: Connect PFET300_PULLDN_EN_CC1 to 300ma_switch (pulldn_en_cc1 pins)
 * 1: Connect SWAPT to 300ma_switch (pulldn_en_cc1 pins)
 */
#define PDSS_DEBUG_CC_1_SWAPT_TO_CC1_EN                     (1UL << 23) /* <23:23> R:RW:0: */


/*
 * 0: Connect PFET300_PULLDN_EN_CC2 to 300ma_switch (pulldn_en_cc2 pins)
 * 1: Connect SWAPT to 300ma_switch (pulldn_en_cc2 pins)
 */
#define PDSS_DEBUG_CC_1_SWAPT_TO_CC2_EN                     (1UL << 24) /* <24:24> R:RW:0: */


/*
 * This bit is used only for Receive Extended Messages with the Chunk bit
 * set.
 * 0: Include the 2-byte extended data message header count
 * 1: Don't include the 2-byte extended data message header count
 */
#define PDSS_DEBUG_CC_1_INC_EXT_CHUNK_HDR_COUNT             (1UL << 25) /* <25:25> R:RW:0: */


/*
 * This bit is used only for Receive Extended Messages with the Chunk bit
 * set.
 * 0: No gating
 * 1: Turn off the transmiter (set the following pins of s8usbpd_cc_top to
 * zero: tx_reg_en, tx_en, tx_data)
 */
#define PDSS_DEBUG_CC_1_STOP_TX_ON_SWAP                     (1UL << 26) /* <26:26> R:RW:0: */


/*
 * Spare2
 */
#define PDSS_DEBUG_CC_1_SPARE2_MASK                         (0x18000000UL) /* <27:28> R:RW:0: */
#define PDSS_DEBUG_CC_1_SPARE2_POS                          (27UL)


/*
 * C-Connector Debug control register 2
 */
#define PDSS_DEBUG_CC_2_ADDRESS                             (0x400a0144UL)
#define PDSS_DEBUG_CC_2                                     (*(volatile uint32_t *)(0x400a0144UL))
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
 * SPARE6,7 Interrupt config
 */
#define PDSS_DEBUG_SPARE_INTR_CFG_ADDRESS                   (0x400a0148UL)
#define PDSS_DEBUG_SPARE_INTR_CFG                           (*(volatile uint32_t *)(0x400a0148UL))
#define PDSS_DEBUG_SPARE_INTR_CFG_DEFAULT                   (0x0000038eUL)

/*
 * Edge detect positive/negative enable/disable.
 */
#define PDSS_DEBUG_SPARE_INTR_CFG_SPARE6_CFG_MASK           (0x00000003UL) /* <0:1> R:RW:2: */
#define PDSS_DEBUG_SPARE_INTR_CFG_SPARE6_CFG_POS            (0UL)


/*
 * Filtering the positive edge of ocp_det from s8usbpd.:
 * 0: No Filtering
 * 1: Refer to SPARE6_FILT_SEL
 */
#define PDSS_DEBUG_SPARE_INTR_CFG_SPARE6_FILT_EN            (1UL << 2) /* <2:2> R:RW:1: */


/*
 * The positive edge of spare6 detection signal goes through a digital filter
 * which runs at CLK_LF.
 * If filtering is required, then SPARE6_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_DEBUG_SPARE_INTR_CFG_SPARE6_FILT_SEL_MASK      (0x00000038UL) /* <3:5> R:RW:1: */
#define PDSS_DEBUG_SPARE_INTR_CFG_SPARE6_FILT_SEL_POS       (3UL)


/*
 * Edge detect positive/negative enable/disable.
 */
#define PDSS_DEBUG_SPARE_INTR_CFG_SPARE7_CFG_MASK           (0x000000c0UL) /* <6:7> R:RW:2: */
#define PDSS_DEBUG_SPARE_INTR_CFG_SPARE7_CFG_POS            (6UL)


/*
 * Filtering the positive edge of ocp_det from s8usbpd.:
 * 0: No Filtering
 * 1: Refer to SPARE6_FILT_SEL
 */
#define PDSS_DEBUG_SPARE_INTR_CFG_SPARE7_FILT_EN            (1UL << 8) /* <8:8> R:RW:1: */


/*
 * The positive edge of spare7 detection signal goes through a digital filter
 * which runs at CLK_LF.
 * If filtering is required, then SPARE7_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_DEBUG_SPARE_INTR_CFG_SPARE7_FILT_SEL_MASK      (0x00000e00UL) /* <9:11> R:RW:1: */
#define PDSS_DEBUG_SPARE_INTR_CFG_SPARE7_FILT_SEL_POS       (9UL)


/*
 * INTR2 Cause.  These are the active interrupts get reflected on interrupt_usbpd
 * pin.
 */
#define PDSS_INTR2_ADDRESS                                  (0x400a014cUL)
#define PDSS_INTR2                                          (*(volatile uint32_t *)(0x400a014cUL))
#define PDSS_INTR2_DEFAULT                                  (0x00000000UL)

/*
 * The interrupt is raised at the end of UI calculation during preamble.
 */
#define PDSS_INTR2_UI_CAL_DONE                              (1UL << 0) /* <0:0> RW1S:RW1C:0: */


/*
 * The interrupt is raised when small pulse as defined by MIN_PULSE_VALUE
 * is detected
 */
#define PDSS_INTR2_PULSE_MIN_VIOLATED                       (1UL << 1) /* <1:1> RW1S:RW1C:0: */


/*
 * The interrupt is raised when large pulse as defined by MAX_PULSE_VALUE
 * is detected
 */
#define PDSS_INTR2_PULSE_MAX_VIOLATED                       (1UL << 2) /* <2:2> RW1S:RW1C:0: */


/*
 * The interrupt is raised when HPD detects IRQ signaling on HPD line
 */
#define PDSS_INTR2_HPD_IRQ                                  (1UL << 3) /* <3:3> RW1S:RW1C:0: */


/*
 * The interrupt is raised when HPD detects pluged condition
 */
#define PDSS_INTR2_HPD_PLUGED                               (1UL << 4) /* <4:4> RW1S:RW1C:0: */


/*
 * The interrupt is raised when HPD detects unpluged condition
 */
#define PDSS_INTR2_HPD_UNPLUGED                             (1UL << 5) /* <5:5> RW1S:RW1C:0: */


/*
 * The interrupt is raised when HPD detects undefined activity
 */
#define PDSS_INTR2_HPD_UNSTABLE                             (1UL << 6) /* <6:6> RW1S:RW1C:0: */


/*
 * The interrupt is raised when an entry to HPD queue is made.
 */
#define PDSS_INTR2_HPD_QUEUE                                (1UL << 7) /* <7:7> RW1S:RW1C:0: */


/*
 * The interrupt is raised when HPDT completes the command
 */
#define PDSS_INTR2_HPDT_COMMAND_DONE                        (1UL << 8) /* <8:8> RW1S:RW1C:0: */


/*
 * The extended receive message detected
 */
#define PDSS_INTR2_EXTENDED_MSG_DET                         (1UL << 9) /* <9:9> RW1S:RW1C:0: */


/*
 * The chunked-extended receive message detected
 */
#define PDSS_INTR2_CHUNK_DET                                (1UL << 10) /* <10:10> RW1S:RW1C:0: */


/*
 * Hardware has passed writing the data to Half or End of the RX SRAM Memory
 * Location but CPU has not read the Data (RX_SRAM_HALF_EN not cleared bt
 * FW). This interrupt should be cleared only after the end of the RX packet.
 */
#define PDSS_INTR2_RX_SRAM_OVER_FLOW                        (1UL << 11) /* <11:11> RW1S:RW1C:0: */


/*
 * Hardware has passed reading the data to Half or End of the TX SRAM Memory
 * Location but CPU has not wrote the Data (TX_SRAM_HALF_EN not cleared bt
 * FW). This interrupt should be cleared only after the end of the TX packet.
 */
#define PDSS_INTR2_TX_SRAM_UNDER_FLOW                       (1UL << 12) /* <12:12> RW1S:RW1C:0: */


/*
 * SPARE3 RX (KCHAR_ERROR)
 */
#define PDSS_INTR2_SPARE3                                   (1UL << 13) /* <13:13> RW1S:RW1C:0: */


/*
 * SPARE4 RX (SOP)
 */
#define PDSS_INTR2_SPARE4                                   (1UL << 14) /* <14:14> RW1S:RW1C:0: */


/*
 * SPARE5 TX (SRAM_HALF)
 */
#define PDSS_INTR2_SPARE5                                   (1UL << 15) /* <15:15> RW1S:RW1C:0: */


/*
 * NGDO C Spacing is complete
 */
#define PDSS_INTR2_NGDO_C_SPACING_DONE                      (1UL << 16) /* <16:16> RW1S:RW1C:0: */


/*
 * NGDO P Spacing is complete
 */
#define PDSS_INTR2_NGDO_P_SPACING_DONE                      (1UL << 17) /* <17:17> RW1S:RW1C:0: */


/*
 * VREG20V Switching is complete
 */
#define PDSS_INTR2_VREG20V_SWITCH_DONE                      (1UL << 18) /* <18:18> RW1S:RW1C:0: */


/*
 * VDDD_SW Switching is complete
 */
#define PDSS_INTR2_VDDD_SW_SWITCH_DONE                      (1UL << 19) /* <19:19> RW1S:RW1C:0: */


/*
 * VSWAP and VBUS_C less that 5V is detected
 */
#define PDSS_INTR2_VSWAP_VBUS_LESS_5_DONE                   (1UL << 20) /* <20:20> RW1S:RW1C:0: */


/*
 * The interrupt is raised when SWAP detects an interrupt
 */
#define PDSS_INTR2_SWAP_IRQ                                 (1UL << 21) /* <21:21> RW1S:RW1C:0: */


/*
 * The interrupt is raised when SWAP detects pluged condition
 */
#define PDSS_INTR2_SWAP_PLUGED                              (1UL << 22) /* <22:22> RW1S:RW1C:0: */


/*
 * The interrupt is raised when SWAP detects unpluged condition
 */
#define PDSS_INTR2_SWAP_UNPLUGED                            (1UL << 23) /* <23:23> RW1S:RW1C:0: */


/*
 * The interrupt is raised when SWAP detects undefined activity
 */
#define PDSS_INTR2_SWAP_UNSTABLE                            (1UL << 24) /* <24:24> RW1S:RW1C:0: */


/*
 * The interrupt is raised when an entry to SWAP queue is made.
 */
#define PDSS_INTR2_SWAP_QUEUE                               (1UL << 25) /* <25:25> RW1S:RW1C:0: */


/*
 * The interrupt is raised when SWAP completes the command
 */
#define PDSS_INTR2_SWAP_COMMAND_DONE                        (1UL << 26) /* <26:26> RW1S:RW1C:0: */


/*
 * INTR2 Set
 */
#define PDSS_INTR2_SET_ADDRESS                              (0x400a0150UL)
#define PDSS_INTR2_SET                                      (*(volatile uint32_t *)(0x400a0150UL))
#define PDSS_INTR2_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_UI_CAL_DONE                          (1UL << 0) /* <0:0> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_PULSE_MIN_VIOLATED                   (1UL << 1) /* <1:1> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_PULSE_MAX_VIOLATED                   (1UL << 2) /* <2:2> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_HPD_IRQ                              (1UL << 3) /* <3:3> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_HPD_PLUGED                           (1UL << 4) /* <4:4> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_HPD_UNPLUGED                         (1UL << 5) /* <5:5> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_HPD_UNSTABLE                         (1UL << 6) /* <6:6> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_HPD_QUEUE                            (1UL << 7) /* <7:7> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_HPDT_COMMAND_DONE                    (1UL << 8) /* <8:8> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_EXTENDED_MSG_DET                     (1UL << 9) /* <9:9> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_CHUNK_DET                            (1UL << 10) /* <10:10> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_RX_SRAM_OVER_FLOW                    (1UL << 11) /* <11:11> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_TX_SRAM_UNDER_FLOW                   (1UL << 12) /* <12:12> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SPARE3                               (1UL << 13) /* <13:13> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SPARE4                               (1UL << 14) /* <14:14> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SPARE5                               (1UL << 15) /* <15:15> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_NGDO_C_SPACING_DONE                  (1UL << 16) /* <16:16> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_NGDO_P_SPACING_DONE                  (1UL << 17) /* <17:17> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_VREG20V_SWITCH_DONE                  (1UL << 18) /* <18:18> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_VDDD_SW_SWITCH_DONE                  (1UL << 19) /* <19:19> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_VSWAP_VBUS_LESS_5_DONE               (1UL << 20) /* <20:20> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SWAP_IRQ                             (1UL << 21) /* <21:21> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SWAP_PLUGED                          (1UL << 22) /* <22:22> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SWAP_UNPLUGED                        (1UL << 23) /* <23:23> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SWAP_UNSTABLE                        (1UL << 24) /* <24:24> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SWAP_QUEUE                           (1UL << 25) /* <25:25> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_SET_SWAP_COMMAND_DONE                    (1UL << 26) /* <26:26> A:RW1S:0: */


/*
 * INTR2 Mask
 */
#define PDSS_INTR2_MASK_ADDRESS                             (0x400a0154UL)
#define PDSS_INTR2_MASK                                     (*(volatile uint32_t *)(0x400a0154UL))
#define PDSS_INTR2_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_UI_CAL_DONE_MASK                    (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_PULSE_MIN_VIOLATED_MASK             (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_PULSE_MAX_VIOLATED_MASK             (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_HPD_IRQ_MASK                        (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_HPD_PLUGED_MASK                     (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_HPD_UNPLUGED_MASK                   (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_HPD_UNSTABLE_MASK                   (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_HPD_QUEUE_MASK                      (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_HPDT_COMMAND_DONE_MASK              (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_EXTENDED_MSG_DET_MASK               (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_CHUNK_DET_MASK                      (1UL << 10) /* <10:10> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_RX_SRAM_OVER_FLOW_MASK              (1UL << 11) /* <11:11> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_TX_SRAM_UNDER_FLOW_MASK             (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SPARE3_MASK                         (1UL << 13) /* <13:13> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SPARE4_MASK                         (1UL << 14) /* <14:14> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SPARE5_MASK                         (1UL << 15) /* <15:15> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_NGDO_C_SPACING_DONE_MASK            (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_NGDO_P_SPACING_DONE_MASK            (1UL << 17) /* <17:17> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_VREG20V_SWITCH_DONE_MASK            (1UL << 18) /* <18:18> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_VDDD_SW_SWITCH_DONE_MASK            (1UL << 19) /* <19:19> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_VSWAP_VBUS_LESS_5_DONE_MASK         (1UL << 20) /* <20:20> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SWAP_IRQ_MASK                       (1UL << 21) /* <21:21> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SWAP_PLUGED_MASK                    (1UL << 22) /* <22:22> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SWAP_UNPLUGED_MASK                  (1UL << 23) /* <23:23> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SWAP_UNSTABLE_MASK                  (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SWAP_QUEUE_MASK                     (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR2_MASK_SWAP_COMMAND_DONE_MASK              (1UL << 26) /* <26:26> R:RW:0: */


/*
 * INTR2 Masked
 */
#define PDSS_INTR2_MASKED_ADDRESS                           (0x400a0158UL)
#define PDSS_INTR2_MASKED                                   (*(volatile uint32_t *)(0x400a0158UL))
#define PDSS_INTR2_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_UI_CAL_DONE_MASKED                (1UL << 0) /* <0:0> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_PULSE_MIN_VIOLATED_MASKED         (1UL << 1) /* <1:1> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_PULSE_MAX_VIOLATED_MASKED         (1UL << 2) /* <2:2> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_HPD_IRQ_MASKED                    (1UL << 3) /* <3:3> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_HPD_PLUGED_MASKED                 (1UL << 4) /* <4:4> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_HPD_UNPLUGED_MASKED               (1UL << 5) /* <5:5> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_HPD_UNSTABLE_MASKED               (1UL << 6) /* <6:6> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_HPD_QUEUE_MASKED                  (1UL << 7) /* <7:7> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_HPDT_COMMAND_DONE_MASKED          (1UL << 8) /* <8:8> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_EXTENDED_MSG_DET_MASKED           (1UL << 9) /* <9:9> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_CHUNK_DET_MASKED                  (1UL << 10) /* <10:10> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_RX_SRAM_OVER_FLOW_MASKED          (1UL << 11) /* <11:11> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_TX_SRAM_UNDER_FLOW_MASKED         (1UL << 12) /* <12:12> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SPARE3_MASKED                     (1UL << 13) /* <13:13> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SPARE4_MASKED                     (1UL << 14) /* <14:14> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SPARE5_MASKED                     (1UL << 15) /* <15:15> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_NGDO_C_SPACING_DONE_MASKED        (1UL << 16) /* <16:16> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_NGDO_P_SPACING_DONE_MASKED        (1UL << 17) /* <17:17> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_VREG20V_SWITCH_DONE_MASKED        (1UL << 18) /* <18:18> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_VDDD_SW_SWITCH_DONE_MASKED        (1UL << 19) /* <19:19> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_VSWAP_VBUS_LESS_5_DONE_MASKED     (1UL << 20) /* <20:20> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SWAP_IRQ_MASKED                   (1UL << 21) /* <21:21> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SWAP_PLUGED_MASKED                (1UL << 22) /* <22:22> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SWAP_UNPLUGED_MASKED              (1UL << 23) /* <23:23> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SWAP_UNSTABLE_MASKED              (1UL << 24) /* <24:24> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SWAP_QUEUE_MASKED                 (1UL << 25) /* <25:25> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR2_MASKED_SWAP_COMMAND_DONE_MASKED          (1UL << 26) /* <26:26> RW:R:0: */


/*
 * Configures HPD module, IRQ_MIN, IRQ_MAX and ENABLE
 */
#define PDSS_HPD_CTRL1_ADDRESS                              (0x400a015cUL)
#define PDSS_HPD_CTRL1                                      (*(volatile uint32_t *)(0x400a015cUL))
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
#define PDSS_HPD_CTRL2_ADDRESS                              (0x400a0160UL)
#define PDSS_HPD_CTRL2                                      (*(volatile uint32_t *)(0x400a0160UL))
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
 * Configures HPD module, stable high and stable low values
 */
#define PDSS_HPD_CTRL3_ADDRESS                              (0x400a0164UL)
#define PDSS_HPD_CTRL3                                      (*(volatile uint32_t *)(0x400a0164UL))
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
#define PDSS_HPD_CTRL4_ADDRESS                              (0x400a0168UL)
#define PDSS_HPD_CTRL4                                      (*(volatile uint32_t *)(0x400a0168UL))
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
#define PDSS_HPD_CTRL5_ADDRESS                              (0x400a016cUL)
#define PDSS_HPD_CTRL5                                      (*(volatile uint32_t *)(0x400a016cUL))
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
#define PDSS_HPD_QUEUE_ADDRESS                              (0x400a0170UL)
#define PDSS_HPD_QUEUE                                      (*(volatile uint32_t *)(0x400a0170UL))
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
#define PDSS_HPDT_CTRL1_ADDRESS                             (0x400a0174UL)
#define PDSS_HPDT_CTRL1                                     (*(volatile uint32_t *)(0x400a0174UL))
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
#define PDSS_HPDT_CTRL2_ADDRESS                             (0x400a0178UL)
#define PDSS_HPDT_CTRL2                                     (*(volatile uint32_t *)(0x400a0178UL))
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
#define PDSS_SWAP_CTRL0_ADDRESS                             (0x400a017cUL)
#define PDSS_SWAP_CTRL0                                     (*(volatile uint32_t *)(0x400a017cUL))
#define PDSS_SWAP_CTRL0_DEFAULT                             (0x00000000UL)

/*
 * Input source selection for SWAPT
 */
#define PDSS_SWAP_CTRL0_SWAPT_SOURCE_SEL_MASK               (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_SWAP_CTRL0_SWAPT_SOURCE_SEL_POS                (0UL)


/*
 * Input source selection for SWAPR
 * 0: Source is cmp_out of ADC1
 * 1: Source is cmp_out of ADC2
 */
#define PDSS_SWAP_CTRL0_SWAPR_SOURCE_SEL                    (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Polatiry of the SWAPT output
 * 0: No  Inverting the output of the swapt
 * 1: Inverting the output of the swapt
 */
#define PDSS_SWAP_CTRL0_SWAPT_POLARITY                      (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Pull down value for SWAPT_OUT_GPIO1
 */
#define PDSS_SWAP_CTRL0_SWAPT_EN_CC1_PULLDN                 (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Pull down value for SWAPT_OUT_GPIO2
 */
#define PDSS_SWAP_CTRL0_SWAPT_EN_CC2_PULLDN                 (1UL << 5) /* <5:5> R:RW:0: */


/*
 * 0: Connect SWAPT_EN_CC1_PULLDN to SWAPT_OUT_GPIO1
 * 1: Connect SWAPT to SWAPT_OUT_GPIO1
 */
#define PDSS_SWAP_CTRL0_SWAPT_TO_GPIO1_EN                   (1UL << 6) /* <6:6> R:RW:0: */


/*
 * 0: Connect SWAPT_EN_CC2_PULLDN to SWAPT_OUT_GPIO2
 * 1: Connect SWAPT to SWAPT_OUT_GPIO2
 */
#define PDSS_SWAP_CTRL0_SWAPT_TO_GPIO2_EN                   (1UL << 7) /* <7:7> R:RW:0: */


/*
 * 0: Clocks is turn off for SWAP block
 * 1: Clock is runing in the SWAP block
 */
#define PDSS_SWAP_CTRL0_SWAP_ENABLED                        (1UL << 31) /* <31:31> R:RW:0: */


/*
 * Configures SWAP module, IRQ_MIN, IRQ_MAX and ENABLE
 */
#define PDSS_SWAP_CTRL1_ADDRESS                             (0x400a0180UL)
#define PDSS_SWAP_CTRL1                                     (*(volatile uint32_t *)(0x400a0180UL))
#define PDSS_SWAP_CTRL1_DEFAULT                             (0x8025812cUL)

/*
 * Defines the min width of IRQ pulse. Spec = 0.5 ms. Assumes 600 Khz clock.
 */
#define PDSS_SWAP_CTRL1_IRQ_MIN_MASK                        (0x00000fffUL) /* <0:11> R:RW:300: */
#define PDSS_SWAP_CTRL1_IRQ_MIN_POS                         (0UL)


/*
 * Defines the max width of IRQ pulse. Spec = 1.0 ms. Assumes 600 Khz clock.
 */
#define PDSS_SWAP_CTRL1_IRQ_MAX_MASK                        (0x00fff000UL) /* <12:23> R:RW:600: */
#define PDSS_SWAP_CTRL1_IRQ_MAX_POS                         (12UL)


/*
 * When set it flushes the queue.
 */
#define PDSS_SWAP_CTRL1_FLUSH_QUEUE                         (1UL << 24) /* <24:24> R:RW:0: */


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
#define PDSS_SWAP_CTRL2_ADDRESS                             (0x400a0184UL)
#define PDSS_SWAP_CTRL2                                     (*(volatile uint32_t *)(0x400a0184UL))
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
#define PDSS_SWAP_CTRL3_ADDRESS                             (0x400a0188UL)
#define PDSS_SWAP_CTRL3                                     (*(volatile uint32_t *)(0x400a0188UL))
#define PDSS_SWAP_CTRL3_DEFAULT                             (0x0004b04bUL)

/*
 * Defines the minimum time before plugged condition is detected for subsequent
 * connect.  Spec = 2 ms. Assumes 600 Khz clock. This value is internally
 * multiplied by 16.
 */
#define PDSS_SWAP_CTRL3_STABLE_HIGH_MASK                    (0x00000fffUL) /* <0:11> R:RW:75: */
#define PDSS_SWAP_CTRL3_STABLE_HIGH_POS                     (0UL)


/*
 * Defines the minimum time before unplugged condition is detected for subsequent
 * connect.  Spec = 2 ms. Assumes 600 Khz clock. This value is internally
 * multiplied by 16.
 */
#define PDSS_SWAP_CTRL3_STABLE_LOW_MASK                     (0x00fff000UL) /* <12:23> R:RW:75: */
#define PDSS_SWAP_CTRL3_STABLE_LOW_POS                      (12UL)


/*
 * Configures SWAP module, irq spacing and unplug event
 */
#define PDSS_SWAP_CTRL4_ADDRESS                             (0x400a018cUL)
#define PDSS_SWAP_CTRL4                                     (*(volatile uint32_t *)(0x400a018cUL))
#define PDSS_SWAP_CTRL4_DEFAULT                             (0x000004b0UL)

/*
 * Defines the minimum spacing between interrupts  Spec = 2 ms. Assumes 600
 * Khz clock.
 */
#define PDSS_SWAP_CTRL4_IRQ_SPACING_MASK                    (0x00000fffUL) /* <0:11> R:RW:1200: */
#define PDSS_SWAP_CTRL4_IRQ_SPACING_POS                     (0UL)


/*
 * Configures SWAP module, Initial LOW and HIGH times
 */
#define PDSS_SWAP_CTRL5_ADDRESS                             (0x400a0190UL)
#define PDSS_SWAP_CTRL5                                     (*(volatile uint32_t *)(0x400a0190UL))
#define PDSS_SWAP_CTRL5_DEFAULT                             (0x0ea50ea5UL)

/*
 * Defines the minimum time before plugged condion is detected for initial
 * connect.  Spec = 100 ms. Assumes 600 Khz clock. This value is internally
 * multiplied by 16.
 */
#define PDSS_SWAP_CTRL5_LONG_HIGH_MASK                      (0x0000ffffUL) /* <0:15> R:RW:3749: */
#define PDSS_SWAP_CTRL5_LONG_HIGH_POS                       (0UL)


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
 * SWAP queue register
 */
#define PDSS_SWAP_QUEUE_ADDRESS                             (0x400a0194UL)
#define PDSS_SWAP_QUEUE                                     (*(volatile uint32_t *)(0x400a0194UL))
#define PDSS_SWAP_QUEUE_DEFAULT                             (0x00000000UL)

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
 * This queue will hold SWAP input events. These events are PLUGGED, UNPLUGGED
 * and IRQ.  Only 2 back to back IRQ will be written into the queue and additional
 * ones will be dropped. When UNPLUGGED is detected, the event will always
 * be written to location 0 of the queue and locations 1 to 3 will be cleared.
 *  The following codes are used to encode events in the queue.
 * 00  : Empty location.
 * 01  : UNPLUGGED.
 * 10  : PLUGGED.
 * 11  : IRQ.
 */
#define PDSS_SWAP_QUEUE_DATA_OUT_MASK                       (0x000000ffUL) /* <0:7> RW:R:0: */
#define PDSS_SWAP_QUEUE_DATA_OUT_POS                        (0UL)


/*
 * SWAPT module configure and IRQ width and delay parameters
 */
#define PDSS_SWAPT_CTRL1_ADDRESS                            (0x400a0198UL)
#define PDSS_SWAPT_CTRL1                                    (*(volatile uint32_t *)(0x400a0198UL))
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
#define PDSS_SWAPT_CTRL2_ADDRESS                            (0x400a019cUL)
#define PDSS_SWAPT_CTRL2                                    (*(volatile uint32_t *)(0x400a019cUL))
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
 * ADC1 SAR Control Register
 * General Purpose voltgae measurement, Temperature Sceining
 */
#define PDSS_ADC1_SAR_CTRL_ADDRESS                          (0x400a01a0UL)
#define PDSS_ADC1_SAR_CTRL                                  (*(volatile uint32_t *)(0x400a01a0UL))
#define PDSS_ADC1_SAR_CTRL_DEFAULT                          (0x00008000UL)

/*
 * Setting this bit will enable the HW SAR logic.
 * Once the SAR_EN is one, Hardware will update the  SAR_OUT register after
 * 8 cycles of clk_sar and clear this register.
 */
#define PDSS_ADC1_SAR_CTRL_SAR_EN                           (1UL << 0) /* <0:0> RW1C:RW1S:0: */


/*
 * ADC starting mid value
 */
#define PDSS_ADC1_SAR_CTRL_MID_VAL_MASK                     (0x0000ff00UL) /* <8:15> R:RW:128: */
#define PDSS_ADC1_SAR_CTRL_MID_VAL_POS                      (8UL)


/*
 * ADC output resistance value
 * Stored 8-bit ADC value after the ID Pin voltage is sampled.
 */
#define PDSS_ADC1_SAR_CTRL_SAR_OUT_MASK                     (0x00ff0000UL) /* <16:23> RW:R:0: */
#define PDSS_ADC1_SAR_CTRL_SAR_OUT_POS                      (16UL)


/*
 * This register selects which edge of cmp_out pin of the s8usbpd_adc_top
 * should be used to generate INT0.CMP_OUT_DET
 */
#define PDSS_ADC1_SAR_CTRL_INTR_CMP_SEL_MASK                (0x03000000UL) /* <24:25> R:RW:0: */
#define PDSS_ADC1_SAR_CTRL_INTR_CMP_SEL_POS                 (24UL)


/*
 * The CMP_OUT to SOC GPIO can be selected to go through a digital filter
 * which runs at CLK_LF.
 * If direct connection to GPIO is needed then INTR_1_CFG.CMP_OUT1_FILT_EN
 * needs to be set to "0".
 * If filtering is required, then INTR_1_CFG.CMP_OUT1_FILT_EN needs to beset
 * to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_ADC1_SAR_CTRL_CMP_OUT_TO_GPIO_FILT_SEL_MASK    (0x1c000000UL) /* <26:28> R:RW:0: */
#define PDSS_ADC1_SAR_CTRL_CMP_OUT_TO_GPIO_FILT_SEL_POS     (26UL)


/*
 * S8USBPD DAC1 Control Register
 */
#define PDSS_ADC1_CTRL_ADDRESS                              (0x400a01a4UL)
#define PDSS_ADC1_CTRL                                      (*(volatile uint32_t *)(0x400a01a4UL))
#define PDSS_ADC1_CTRL_DEFAULT                              (0x80000200UL)

/*
 * Control bits for 8-bit DAC.
 * DAC_CNTRL register is used only if CPU wants to implement the SAR algorithm
 * in FW.
 */
#define PDSS_ADC1_CTRL_DAC_CNTRL_MASK                       (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_ADC1_CTRL_DAC_CNTRL_POS                        (0UL)


/*
 * ADC DFT Control:
 * 0: Normal operation
 * 1: DAC output voltage
 */
#define PDSS_ADC1_CTRL_DFT_MUXSEL                           (1UL << 8) /* <8:8> R:RW:0: */


/*
 * This is for when high voltage supply for a port is not present. This bit
 * should be set when the high voltage is present,
 * in order to ensure that the outputs are set to know values.
 * 0: All outputs are isolated to a known value
 * 1: Normal operation
 */
#define PDSS_ADC1_CTRL_ADC_ISO_N                            (1UL << 9) /* <9:9> R:RW:1: */


/*
 * Comparator Output.  If voltage on ID pin is less than DAC voltage, then
 * cmp_out is HIGH.
 */
#define PDSS_ADC1_CTRL_CMP_OUT                              (1UL << 15) /* <15:15> RW:R:0: */


/*
 * Input Voltage select
 */
#define PDSS_ADC1_CTRL_VSEL_MASK                            (0x00060000UL) /* <17:18> R:RW:0: */
#define PDSS_ADC1_CTRL_VSEL_POS                             (17UL)


/*
 * ADC Power down control, active high.
 * DPSLP_REF_CTRL.PD_DPSLP must be Low when this block is enabled
 */
#define PDSS_ADC1_CTRL_PD_LV                                (1UL << 31) /* <31:31> R:RW:1: */


/*
 * ADC12SAR Control Register
 * General Purpose voltgae measurement, Temperature Sceining
 */
#define PDSS_ADC2_SAR_CTRL_ADDRESS                          (0x400a01a8UL)
#define PDSS_ADC2_SAR_CTRL                                  (*(volatile uint32_t *)(0x400a01a8UL))
#define PDSS_ADC2_SAR_CTRL_DEFAULT                          (0x00008000UL)

/*
 * Setting this bit will enable the HW SAR logic.
 * Once the SAR_EN is one, Hardware will update the  SAR_OUT register after
 * 8 cycles of clk_sar and clear this register.
 */
#define PDSS_ADC2_SAR_CTRL_SAR_EN                           (1UL << 0) /* <0:0> RW1C:RW1S:0: */


/*
 * ADC starting mid value
 */
#define PDSS_ADC2_SAR_CTRL_MID_VAL_MASK                     (0x0000ff00UL) /* <8:15> R:RW:128: */
#define PDSS_ADC2_SAR_CTRL_MID_VAL_POS                      (8UL)


/*
 * ADC output resistance value
 * Stored 8-bit ADC value after the ID Pin voltage is sampled.
 */
#define PDSS_ADC2_SAR_CTRL_SAR_OUT_MASK                     (0x00ff0000UL) /* <16:23> RW:R:0: */
#define PDSS_ADC2_SAR_CTRL_SAR_OUT_POS                      (16UL)


/*
 * This register selects which edge of cmp_out pin of the s8usbpd_adc_top
 * should be used to generate INT0.CMP_OUT_DET
 */
#define PDSS_ADC2_SAR_CTRL_INTR_CMP_SEL_MASK                (0x03000000UL) /* <24:25> R:RW:0: */
#define PDSS_ADC2_SAR_CTRL_INTR_CMP_SEL_POS                 (24UL)


/*
 * The CMP_OUT to SOC GPIO can be selected to go through a digital filter
 * which runs at CLK_LF.
 * If direct connection to GPIO is needed then INTR_1_CFG.CMP_OUT2_FILT_EN
 * needs to be set to "0".
 * If filtering is required, then INTR_1_CFG.CMP_OUT2_FILT_EN needs to beset
 * to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_ADC2_SAR_CTRL_CMP_OUT_TO_GPIO_FILT_SEL_MASK    (0x1c000000UL) /* <26:28> R:RW:0: */
#define PDSS_ADC2_SAR_CTRL_CMP_OUT_TO_GPIO_FILT_SEL_POS     (26UL)


/*
 * S8USBPD DAC2 Control Register
 */
#define PDSS_ADC2_CTRL_ADDRESS                              (0x400a01acUL)
#define PDSS_ADC2_CTRL                                      (*(volatile uint32_t *)(0x400a01acUL))
#define PDSS_ADC2_CTRL_DEFAULT                              (0x80000200UL)

/*
 * Control bits for 8-bit DAC.
 * DAC_CNTRL register is used only if CPU wants to implement the SAR algorithm
 * in FW.
 */
#define PDSS_ADC2_CTRL_DAC_CNTRL_MASK                       (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_ADC2_CTRL_DAC_CNTRL_POS                        (0UL)


/*
 * ADC DFT Control:
 * 0: Normal operation
 * 1: DAC output voltage
 */
#define PDSS_ADC2_CTRL_DFT_MUXSEL                           (1UL << 8) /* <8:8> R:RW:0: */


/*
 * This is for when high voltage supply for a port is not present. This bit
 * should be set when the high voltage is present,
 * in order to ensure that the outputs are set to know values.
 * 0: All outputs are isolated to a known value
 * 1: Normal operation
 */
#define PDSS_ADC2_CTRL_ADC_ISO_N                            (1UL << 9) /* <9:9> R:RW:1: */


/*
 * Comparator Output.  If voltage on ID pin is less than DAC voltage, then
 * cmp_out is HIGH.
 */
#define PDSS_ADC2_CTRL_CMP_OUT                              (1UL << 15) /* <15:15> RW:R:0: */


/*
 * Input Voltage select
 */
#define PDSS_ADC2_CTRL_VSEL_MASK                            (0x00060000UL) /* <17:18> R:RW:0: */
#define PDSS_ADC2_CTRL_VSEL_POS                             (17UL)


/*
 * ADC Power down control, active high.
 * DPSLP_REF_CTRL.PD_DPSLP must be Low when this block is enabled
 */
#define PDSS_ADC2_CTRL_PD_LV                                (1UL << 31) /* <31:31> R:RW:1: */


/*
 * S8USBPD C-connector Control Register 0
 */
#define PDSS_CC_CTRL_0_ADDRESS                              (0x400a01b0UL)
#define PDSS_CC_CTRL_0                                      (*(volatile uint32_t *)(0x400a01b0UL))
#define PDSS_CC_CTRL_0_DEFAULT                              (0xb0000000UL)

/*
 * FW can only use this bit when the DEBUG_CC_0.TX_CC_DRIVE_SRC is set to
 * "1".
 * 0: Disables the Transceiver to transmit data
 * 1: Enables the Transceiver to transmit data
 * Notes: This bit is not needed for normal data transmit . This is required
 * only for manual data tranmit .
 */
#define PDSS_CC_CTRL_0_TX_EN                                (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Enables the Transceiver to receive data, Active High
 * This bit should be set after CC Line active interrupt (wakeup) in DeepSleep.
 * FW should set this bit at init and not change after across deep sleep
 * and wake.
 * RX_EN and CMP_EN must be written to the same value.
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
 */
#define PDSS_CC_CTRL_0_CC_1V2                               (1UL << 2) /* <2:2> R:RW:0: */


/*
 * CC line voltage Comparator enable
 * CMP_EN and RX_EN must be written to the same value.
 */
#define PDSS_CC_CTRL_0_CMP_EN                               (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Connects cmp_dn comparator to CC1/CC2
 * 0 - CC1
 * 1 - CC2
 */
#define PDSS_CC_CTRL_0_CMP_DN_CC1V2                         (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Selects the voltage threshold for cmp_dn comparator
 * Notes: Pair of DN and UP comparators should be used to determine remote
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
 * Selects the cmp_up comparator offset:
 */
#define PDSS_CC_CTRL_0_CMP_UP_OFFSET_MASK                   (0x00007000UL) /* <12:14> R:RW:0: */
#define PDSS_CC_CTRL_0_CMP_UP_OFFSET_POS                    (12UL)


/*
 * Enables the offset generator for the cmp_up comparator
 * 0 - no offset
 * 1 - offset enabled, see CMP_UP_OFFSET register for value
 */
#define PDSS_CC_CTRL_0_CMP_UP_OFFSET_EN                     (1UL << 15) /* <15:15> R:RW:0: */


/*
 * No effect
 */
#define PDSS_CC_CTRL_0_CMP_LA_CC1V2                         (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Selects the voltage threshold for cmp_la comparator -> Needs to be set
 * to 1.77V for normal operation
 * CMP_LA_VSEL should  be set to 7 for all application (DFP,UPF,AMA, Cable)
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
 * 0: Disable CC1 Pull-up Termination (Rp)
 * 1: Enable CC1 Pull-up Termination
 * Notes:
 * DFP_UA  = 0  (Recommended to disable when using deepsleep resistor Rp,
 * see CC_CTRL_1.DS_ATTACH_DET_EN)
 * DFP_A : 1  (This bit must be set to 1'b0 if CC1 is not used for communication)
 * UFP_DEAD: 0
 * UFP_A: 0
 * Cable: 0
 */
#define PDSS_CC_CTRL_0_RP_CC1_EN                            (1UL << 24) /* <24:24> R:RW:0: */


/*
 * 0: Disable CC2 Pull-up Termination (Rp)
 * 1: Enable CC2 Pull-up Termination
 * Notes:
 * DFP_UA  = 0  (Recommended to disable when using deepsleep resistor Rp,
 * see CC_CTRL_1.DS_ATTACH_DET_EN)
 * DFP_A : 1  (This bit must be set to 1'b0 if CC2 is not used for communication)
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
 * Enables the hysteresis mode for the line activity comparator
 * This is a legacy control signal and must be driven low
 * (Common for all applications): 1'b0
 */
#define PDSS_CC_CTRL_0_EN_HYST                              (1UL << 28) /* <28:28> R:RW:1: */


/*
 * Selects the amount of line activity comparator hysteresis -> Also legacy
 * control, MUST be driven low
 * 0: 50mV hystersis
 * 1: 100mV hysteresis
 * Notes: This filed matter only when EN_HYST is set.
 */
#define PDSS_CC_CTRL_0_HYST_MODE                            (1UL << 29) /* <29:29> R:RW:1: */


/*
 * Controls the reference voltage generator for DFP vs. UFP/Cable operation
 * 0: UFP/Cable - voltage reference is 2.4V
 * 1: DFP - voltage reference is 2.6V
 * This register is a user configuration that must be set.
 * Notes: This bit must be enabled for DFP
 */
#define PDSS_CC_CTRL_0_DFP_EN                               (1UL << 30) /* <30:30> R:RW:0: */


/*
 * Disables all active circuitry and DC paths
 * DS_ATTACH_DET_EN is still active
 * Notes: Firmware can disable the PHY for DFP waiting for attach. This will
 * save power while waiting for attach. Firmware sets DS_ATTACH_DET_EN bit
 * to enable resistor based pullup on both CC lines. This pullup can be enabled
 * independent of PHY state.
 * DFP_UA: 1
 * DFP_A: 0
 * UFP: 0
 * Cable: 0
 * DPSLP_REF_CTRL.PD_DPSLP must be Low when this block is enabled
 */
#define PDSS_CC_CTRL_0_PWR_DISABLE                          (1UL << 31) /* <31:31> R:RW:1: */


/*
 * S8USBPD C-connector Control Register 1
 */
#define PDSS_CC_CTRL_1_ADDRESS                              (0x400a01b4UL)
#define PDSS_CC_CTRL_1                                      (*(volatile uint32_t *)(0x400a01b4UL))
#define PDSS_CC_CTRL_1_DEFAULT                              (0x00005000UL)

/*
 * Enables ADFT Mode
 */
#define PDSS_CC_CTRL_1_CC_ADFT_EN                           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Selects ADFT connection
 * See s8usbpd BROS for decoding details
 */
#define PDSS_CC_CTRL_1_CC_ADFT_CTRL_MASK                    (0x0000001eUL) /* <1:4> R:RW:0: */
#define PDSS_CC_CTRL_1_CC_ADFT_CTRL_POS                     (1UL)


/*
 * Enables the offset generator for the RX comparator
 * 0 - no offset
 * 1 - offset enabled, see RX_OFFSET register for value
 * This is a legacy control signal and MUST be driven low
 */
#define PDSS_CC_CTRL_1_RX_OFFSET_EN                         (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Selects the RX comparator offset:
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
 * S8USBPD DeepSleep-Reference Control Register
 */
#define PDSS_DPSLP_REF_CTRL_ADDRESS                         (0x400a01b8UL)
#define PDSS_DPSLP_REF_CTRL                                 (*(volatile uint32_t *)(0x400a01b8UL))
#define PDSS_DPSLP_REF_CTRL_DEFAULT                         (0x00000030UL)

/*
 * Setting this bit will enable the deepsleep current reference outputs.
 */
#define PDSS_DPSLP_REF_CTRL_IGEN_EN                         (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Setting this bit will enable the deepsleep reference generator ADFT mode.
 */
#define PDSS_DPSLP_REF_CTRL_DPSLP_ADFT_EN                   (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Controls the Deep Sleep reference ADFT mode
 * 0: ganged 7 iref current sources
 * 1: vrefdpslp voltage reference
 */
#define PDSS_DPSLP_REF_CTRL_ADFT_CTRL                       (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Block enable input
 * 1 - All analog and DC paths cut off, outputs forced to known value
 *      This completely disables the CC Transceiver/Detect block.
 * 0 - Normal functionality
 * Notes: Firmware can disable the PHY for and the deepsleep reference generator
 * when DFP waiting for attach. This will save power while waiting for attach.
 * Firmware sets DS_ATTACH_DET_EN bit to enable resistor based pullup on
 * both CC lines. This pullup can be enabled independent of PHY state.
 * DFP_UA: 1
 * DFP_A: 0
 * UFP: 0
 * Cable: 0
 */
#define PDSS_DPSLP_REF_CTRL_PD_DPSLP                        (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Control to "zero-out" PTAT/CTAT currents
 * 00 : PTAT-CTAT Zeroed-out (ibias=0)
 * 01 : CTAT zeroed-out, IBIAS = IPTAT
 * 10 : PTAT zeroed-out, IBIAS-ICTAT
 * 11 : Both enabled
 */
#define PDSS_DPSLP_REF_CTRL_PCTAT_CTRL_MASK                 (0x00000030UL) /* <4:5> R:RW:3: */
#define PDSS_DPSLP_REF_CTRL_PCTAT_CTRL_POS                  (4UL)


/*
 * S8USBPD VCONN control Register
 */
#define PDSS_VCONN_CTRL_ADDRESS                             (0x400a01bcUL)
#define PDSS_VCONN_CTRL                                     (*(volatile uint32_t *)(0x400a01bcUL))
#define PDSS_VCONN_CTRL_DEFAULT                             (0x00000000UL)

/*
 * Negative Charge Pump enable signal
 * 0 - Pump disabled:
 *      Ra termination is present on both VCONN1 and VCONN2
 * 1 - Pump enabled:
 *      Ra termination is cutoff on VCONN1 only if the EN_COMP1 is set
 *      Ra termination is cutoff on VCONN2 only if the EN_COMP2 is set
 * Notes: This PUMP should be enabled only for Vconn powered applicaiton
 * like Cable or AMA. Setting this bit to 1'b1 disconects Ra from VCONN line
 * to save power .
 * DFP_UA , DFP_A: 0
 * UFP: 0
 * AMA ,Cable : 1 (After powering up)
 * DPSLP_REF_CTRL.PD_DPSLP must be Low when this block is enabled
 */
#define PDSS_VCONN_CTRL_PUMP_EN                             (1UL << 0) /* <0:0> R:RW:0:VCONN_EN */


/*
 * Enable VCONN1 comparator
 */
#define PDSS_VCONN_CTRL_EN_COMP1                            (1UL << 1) /* <1:1> R:RW:0:VCONN_EN */


/*
 * VCONN1 leaker control
 */
#define PDSS_VCONN_CTRL_LEAKER_CONFIG1_MASK                 (0x00000038UL) /* <3:5> R:RW:0:VCONN_EN */
#define PDSS_VCONN_CTRL_LEAKER_CONFIG1_POS                  (3UL)


/*
 * S8USBPD PUMP control Register
 */
#define PDSS_PUMP_CTRL_ADDRESS                              (0x400a01c0UL)
#define PDSS_PUMP_CTRL                                      (*(volatile uint32_t *)(0x400a01c0UL))
#define PDSS_PUMP_CTRL_DEFAULT                              (0x00000014UL)

/*
 * ADFT control
 */
#define PDSS_PUMP_CTRL_ADFT_MASK                            (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_PUMP_CTRL_ADFT_POS                             (0UL)


/*
 * Bypasses the pumped output.  Pump output is connected to VDDD.
 * 0: Charge pump output
 * 1: Pump output shorted to VDDD
 */
#define PDSS_PUMP_CTRL_BYPASS_LV                            (1UL << 2) /* <2:2> R:RW:1: */


/*
 * External clock select
 * 0: Internal oscillator used for charge pump
 * 1: External clock used for charge pump
 */
#define PDSS_PUMP_CTRL_CLK_SEL                              (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Pump powerdown signal
 * 0: Pump enabled (CC_CTRL_0.PWR_DISABLE must be low)
 * 1: Pump disabled, all current paths cutoff
 * The pump must be disabled when the CC block is disabled (see CC_CTRL_0.PWR_DISABLE
 * bit).
 * The pump must be disabled when the deepsleep attach detect pull-up resistor
 * is enabled (see CC_CTRL_1.DS_ATTACH_DET_EN bit).
 * The pump must be enabled when in DFP/source mode with any Rp enabled.
 * The pump must be disabled for all other modes.  This includes UFP/sink
 * and Cable modes.
 *
 * DPSLP_REF_CTRL.PD_DPSLP must be Low when this block is enabled
 */
#define PDSS_PUMP_CTRL_PD_PUMP                              (1UL << 4) /* <4:4> R:RW:1: */


/*
 * S8USBPD 300ma V5V Power FET Register
 */
#define PDSS_PFET300_CTRL_ADDRESS                           (0x400a01c4UL)
#define PDSS_PFET300_CTRL                                   (*(volatile uint32_t *)(0x400a01c4UL))
#define PDSS_PFET300_CTRL_DEFAULT                           (0x00000000UL)

/*
 * V5V Comparator Enable, Active High.
 * Detects if V5V supply is present.
 */
#define PDSS_PFET300_CTRL_EN_COMP                           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * CC1 switch enable signal, Active High.
 */
#define PDSS_PFET300_CTRL_EN_SWITCH_CC1                     (1UL << 1) /* <1:1> R:RW:0: */


/*
 * CC1 switch enable signal, Active High.
 */
#define PDSS_PFET300_CTRL_EN_SWITCH_CC2                     (1UL << 2) /* <2:2> R:RW:0: */


/*
 * S8USBPD_VER2 UVOV Register
 */
#define PDSS_UVOV_CTRL_ADDRESS                              (0x400a01c8UL)
#define PDSS_UVOV_CTRL                                      (*(volatile uint32_t *)(0x400a01c8UL))
#define PDSS_UVOV_CTRL_DEFAULT                              (0x40000000UL)

/*
 * 6-bit input bus to set the UV threshold level. Refer to s8usbpd_ver2 BROS
 * for threshold unit.
 */
#define PDSS_UVOV_CTRL_UV_IN_MASK                           (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_UVOV_CTRL_UV_IN_POS                            (0UL)


/*
 * 6-bit input bus to set the OV threshold level. Refer to s8usbpd_ver2 BROS
 * for threshold unit.
 */
#define PDSS_UVOV_CTRL_OV_IN_MASK                           (0x00000fc0UL) /* <6:11> R:RW:0: */
#define PDSS_UVOV_CTRL_OV_IN_POS                            (6UL)


/*
 * isolation signal. Isolates when the LV supply is not present:
 * iso_n = 0 isolates
 * iso_n = 1 do not isolate
 */
#define PDSS_UVOV_CTRL_UVOV_ISO_N                           (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Adft enable pin
 * 0- adft1, adft0 in HiZ state
 * 1-adft outputs enabled
 */
#define PDSS_UVOV_CTRL_UVOV_ADFT_EN                         (1UL << 13) /* <13:13> R:RW:0: */


/*
 * adft control inputs used to select different analog signal to be brought
 * out on adft1 and adft2
 * 00 - HiZ
 * 01 - UV resistor divider output on adft0 and vref0p74 on adft1
 * 10 - OV resistor divider output on adft0 and vref0p74 on adft1
 * 11 - HiZ
 */
#define PDSS_UVOV_CTRL_UVOV_ADFT_CTRL_MASK                  (0x0000c000UL) /* <14:15> R:RW:0: */
#define PDSS_UVOV_CTRL_UVOV_ADFT_CTRL_POS                   (14UL)


/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_UVOV_CTRL_UVOV_SPARE_MASK                      (0x00ff0000UL) /* <16:23> R:RW:0: */
#define PDSS_UVOV_CTRL_UVOV_SPARE_POS                       (16UL)


/*
 * power down the comparators:
 * PD=1 disabled
 * PD=0 enabled
 */
#define PDSS_UVOV_CTRL_PD_UVOV                              (1UL << 30) /* <30:30> R:RW:1: */


/*
 * S8USBPD_VER2 CSA Register
 */
#define PDSS_CSA_CTRL_ADDRESS                               (0x400a01ccUL)
#define PDSS_CSA_CTRL                                       (*(volatile uint32_t *)(0x400a01ccUL))
#define PDSS_CSA_CTRL_DEFAULT                               (0x80000040UL)

/*
 * Selects nominal voltage gain - 10 (default), 15, 20, 30, 40, 50, 70, 100
 */
#define PDSS_CSA_CTRL_AV1_MASK                              (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_CSA_CTRL_AV1_POS                               (0UL)


/*
 * out_d Configuration:
 * 1 - out_d used
 * 0 - out_d = LOW
 */
#define PDSS_CSA_CTRL_SEL_OUT_D                             (1UL << 6) /* <6:6> R:RW:1: */


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced to known value
 */
#define PDSS_CSA_CTRL_CSA_ISO_N                             (1UL << 7) /* <7:7> R:RW:0: */


/*
 * ADFT control inputs used to connect various analog internal signals to
 * ADFT buses.
 */
#define PDSS_CSA_CTRL_CSA_ADFT_CTRL_MASK                    (0x00000f00UL) /* <8:11> R:RW:0: */
#define PDSS_CSA_CTRL_CSA_ADFT_CTRL_POS                     (8UL)


/*
 * Vref target voltage selection: 0=1.3V, 63=1.93V, Vstep=10mV
 */
#define PDSS_CSA_CTRL_CSA_VREF_SEL_MASK                     (0x0003f000UL) /* <12:17> R:RW:0: */
#define PDSS_CSA_CTRL_CSA_VREF_SEL_POS                      (12UL)


/*
 * CSA Spare
 */
#define PDSS_CSA_CTRL_CSA_SPARE_MASK                        (0x003c0000UL) /* <18:21> R:RW:0: */
#define PDSS_CSA_CTRL_CSA_SPARE_POS                         (18UL)


/*
 * Reference input signal selection
 * 0 - Use 0.74V from Beta-Multiplier in the Deep Sleep reference block
 * 1 - Use 1.2V from band-gap
 */
#define PDSS_CSA_CTRL_VREFIN_SEL                            (1UL << 28) /* <28:28> R:RW:0: */


/*
 * Hysteresis enable for CSA Stage 2
 */
#define PDSS_CSA_CTRL_HYST_EN                               (1UL << 29) /* <29:29> R:RW:0: */


/*
 * BW[0] of bandwidth control
 * The BW[1] is at DEBUG_CC_0.CSA_BW_1
 * BW=0 provides most capacitance on the output of stage1.  BW=7 provides
 * the least capacitance.
 */
#define PDSS_CSA_CTRL_BW                                    (1UL << 30) /* <30:30> R:RW:0: */


/*
 * Block power down input
 * 1 - All analog and DC paths cut off, outputs forced to known value
 * 0 - Normal functionality
 * DPSLP_REF_CTRL.PD_DPSLP must be Low when this block is enabled
 */
#define PDSS_CSA_CTRL_PD_CSA                                (1UL << 31) /* <31:31> R:RW:1: */


/*
 * S8USBPD_VER2 20V Regulator Register
 */
#define PDSS_VREG_CTRL_ADDRESS                              (0x400a01d0UL)
#define PDSS_VREG_CTRL                                      (*(volatile uint32_t *)(0x400a01d0UL))
#define PDSS_VREG_CTRL_DEFAULT                              (0x00000000UL)

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
 * Uses SRSSLT Bandgap as the reference voltage for more accurate Regulated
 * Output Voltage
 */
#define PDSS_VREG_CTRL_VBG_EN                               (1UL << 8) /* <8:8> R:RW:0: */


/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_VREG_CTRL_VREG_SPARE_MASK                      (0x0000fe00UL) /* <9:15> R:RW:0: */
#define PDSS_VREG_CTRL_VREG_SPARE_POS                       (9UL)


/*
 * S8USBPD_VER2 SBU Switch Register
 */
#define PDSS_SBU_CTRL_ADDRESS                               (0x400a01d4UL)
#define PDSS_SBU_CTRL                                       (*(volatile uint32_t *)(0x400a01d4UL))
#define PDSS_SBU_CTRL_DEFAULT                               (0x00000000UL)

/*
 * adft enable, active high
 */
#define PDSS_SBU_CTRL_SBU_ADFT_EN                           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * SBU Switch ADFT Select.  Refer to the s8usbpd_ver2 BROS for more details.
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
 * AUXP 1MOhm Pullup Resistor control, active high
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
 * RESERVED FOR FUTURE USE
 */
#define PDSS_SBU_CTRL_SBU_SPARE_MASK                        (0x00ff0000UL) /* <16:23> R:RW:0: */
#define PDSS_SBU_CTRL_SBU_SPARE_POS                         (16UL)


/*
 * S8USBPD_VER2 VSYS Supply Switch Register
 */
#define PDSS_VSYS_CTRL_ADDRESS                              (0x400a01d8UL)
#define PDSS_VSYS_CTRL                                      (*(volatile uint32_t *)(0x400a01d8UL))
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
 * RESERVED FOR FUTURE USE
 */
#define PDSS_VSYS_CTRL_VSYS_SPARE_MASK                      (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_VSYS_CTRL_VSYS_SPARE_POS                       (8UL)


/*
 * S8USBPD_VER2 20V Regulator and VSYS Supply Switch Register
 */
#define PDSS_VREG_VSYS_CTRL_ADDRESS                         (0x400a01dcUL)
#define PDSS_VREG_VSYS_CTRL                                 (*(volatile uint32_t *)(0x400a01dcUL))
#define PDSS_VREG_VSYS_CTRL_DEFAULT                         (0x00010000UL)

/*
 * 20V regulator enable signal
 * "1" : Enable regulator to output supply onto VDDD
 * "0" : Disable regulator
 */
#define PDSS_VREG_VSYS_CTRL_VREG20_EN                       (1UL << 0) /* <0:0> R:RW:0: */


/*
 * When VREG20_EN is set/de-assert, the 20v regulator will turn off/on after
 * VREG20_ONOFF_CNTR cycle of clk_tx.
 * There won't be any delay when this register is set to zero.
 */
#define PDSS_VREG_VSYS_CTRL_VREG20_ONOFF_CNTR_MASK          (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_VREG_VSYS_CTRL_VREG20_ONOFF_CNTR_POS           (8UL)


/*
 * Control signal to enable/disable switch
 * "1" : Enable switch : VOUT = VDDD = VSYS
 * "0" : Disable switch
 * VSYS_CTRL.VSYS_ISO_N and CSA_CTRL.CSA_ISO_N must be set High for this
 * bit to have effect.
 */
#define PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH              (1UL << 16) /* <16:16> R:RW:1: */


/*
 * When ENABLE_VDDD_SWITCH is set/de-assert, the s8usbpd_vdd_sw_top will
 * turn off/on after VDDD_SW_ONOFF_CNTR cycle of clk_tx.
 * There won't be any delay when this register is set to zero.
 */
#define PDSS_VREG_VSYS_CTRL_VDDD_SW_ONOFF_CNTR_MASK         (0x01fe0000UL) /* <17:24> R:RW:0: */
#define PDSS_VREG_VSYS_CTRL_VDDD_SW_ONOFF_CNTR_POS          (17UL)


/*
 * S8USBPD_VER2 VBUS_C/P NGDO Register
 */
#define PDSS_NGDO_CTRL_0_ADDRESS                            (0x400a01e0UL)
#define PDSS_NGDO_CTRL_0                                    (*(volatile uint32_t *)(0x400a01e0UL))
#define PDSS_NGDO_CTRL_0_DEFAULT                            (0x00000402UL)

/*
 * Selects clock (internal oscillator or external clock) to be used for the
 * charge-pump:
 * 0 : Internal Oscillator
 * 1 : External clock
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_C_CLKIN_SEL_LV           (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Selects "divide" option for the selected clock (internal oscillator or
 * external clock) to drive the charge-pump:
 * 00 : DIV by 1 - This setting must be used for normal operation, as this
 * is the setting used for production and characterization.
 * 01 : DIV by 2
 * 10 : DIV by 3
 * 11 : DIV by 4
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_C_CLKSEL_LV_MASK         (0x00000006UL) /* <1:2> R:RW:1: */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_C_CLKSEL_LV_POS          (1UL)


/*
 * NFET Gate Driver Control Signal, Active High
 * 0 - Gate Driver pump is OFF
 * 1 - Gate Driver pump is ON, will pump to CTRL pin to VBUS_C + >5V
 * Bit 3 - VBUS_C_CTRL0 pin Control
 * Bit 4 - VBUS_C_CTRL1 pin Control
 * DPSLP_REF_CTRL.PD_DPSLP must be Low when this block is enabled
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_C_NGDO_EN_LV_MASK        (0x00000018UL) /* <3:4> R:RW:0: */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_C_NGDO_EN_LV_POS         (3UL)


/*
 * PFET Gate Driver Control Signal, Active High
 * 0 - Pulldown resistor is OFF
 * 1 - Pulldown resistor is ON, ~3kOhms
 * Bit 5 - VBUS_C_CTRL0 pin Control
 * Bit 6 - VBUS_C_CTRL1 pin Control
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_C_PULLDN_EN_LV_MASK      (0x00000060UL) /* <5:6> R:RW:0: */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_C_PULLDN_EN_LV_POS       (5UL)


/*
 * DFT Model Enable Signal, Active High
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_C_DFT_EN_LV              (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Bring out the charge-pump clock onot ddft_lv & ddft_hv pins, Active High
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_C_DFT_CLKOUT_SEL_LV      (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Selects clock (internal oscillator or external clock) to be used for the
 * charge-pump:
 * 0 : Internal Oscillator
 * 1 : External clock
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_P_CLKIN_SEL_LV           (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Selects "divide" option for the selected clock (internal oscillator or
 * external clock) to drive the charge-pump:
 * 00 : DIV by 1 - This setting must be used for normal operation, as this
 * is the setting used for production and characterization.
 * 01 : DIV by 2
 * 10 : DIV by 3
 * 11 : DIV by 4
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_P_CLKSEL_LV_MASK         (0x00000c00UL) /* <10:11> R:RW:1: */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_P_CLKSEL_LV_POS          (10UL)


/*
 * NFET Gate Driver Control Signal, Active High
 * Bit 12 - VBUS_P_CTRL0 pin Control
 * Bit 13 - VBUS_P_CTRL1 pin Control
 * NOTE: In CCG3
 * Bit 12 - VBUS_P_CTRL1 pin Control
 * Bit 13 - VBUS_P_CTRL0 pin Control
 * DPSLP_REF_CTRL.PD_DPSLP must be Low when this block is enabled
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_P_NGDO_EN_LV_MASK        (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_P_NGDO_EN_LV_POS         (12UL)


/*
 * PFET Gate Driver Control Signal, Active High
 * Bit 14 - VBUS_P_CTRL0 pin Control
 * Bit 15 - VBUS_P_CTRL1 pin Control
 * NOTE: In CCG3
 * Bit 14 - VBUS_P_CTRL1 pin Control
 * Bit 15 - VBUS_P_CTRL0 pin Control
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_P_PULLDN_EN_LV_MASK      (0x0000c000UL) /* <14:15> R:RW:0: */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_P_PULLDN_EN_LV_POS       (14UL)


/*
 * DFT Model Enable Signal, Active High
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_P_DFT_EN_LV              (1UL << 16) /* <16:16> R:RW:0: */


/*
 * Bring out the charge-pump clock onot ddft_lv & ddft_hv pins, Active High
 */
#define PDSS_NGDO_CTRL_0_NGDO_VBUS_P_DFT_CLKOUT_SEL_LV      (1UL << 17) /* <17:17> R:RW:0: */


/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_NGDO_CTRL_0_NGDO_SPARE_MASK                    (0xff000000UL) /* <24:31> R:RW:0: */
#define PDSS_NGDO_CTRL_0_NGDO_SPARE_POS                     (24UL)


/*
 * Gate driver control for VBUS C
 */
#define PDSS_NGDO_CTRL_C_ADDRESS                            (0x400a01e4UL)
#define PDSS_NGDO_CTRL_C                                    (*(volatile uint32_t *)(0x400a01e4UL))
#define PDSS_NGDO_CTRL_C_DEFAULT                            (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the EN_LV and PULLDN_EN_PLV pins.
 * 1: HW controlls the EN_LV and PULLDN_EN_PLV pins
 */
#define PDSS_NGDO_CTRL_C_AUTO_MODE                          (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control option.
 * Any write-one to this register will reset the edge detector in the NGDO
 * controller.
 * FW should cleared this register after the fault conditions(OV, UV, OC,
 * VBUS_LESS_5) are removed by writing a "1" to this register.
 */
#define PDSS_NGDO_CTRL_C_RST_EDGE_DET                       (1UL << 1) /* <1:1> R:RW:0: */


/*
 * This bit selects which bit of EN_LV/PULLDN_EN_LV turns of first when the
 * TURN_OFF_SPACING is >0.
 * 0: pad_vbus_c_ctrl_0 turns off first
 * 1: pad_vbus_c_ctrl_1 turns off first
 */
#define PDSS_NGDO_CTRL_C_TURN_OFF_SEL                       (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Bypassing the synchronizer for fault detection in CLK_LF domain.
 * 0: No Bypass. The spacing take effect 2 CLK_LF after the fault detection.
 * 1: Bpass: The spacing takes effect right after fault detection
 */
#define PDSS_NGDO_CTRL_C_BYPASS_2DFF                        (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The EN_LV/PULLDN_EN_LV bit0 and bit 1 CLK_LF spacing.
 * 0:No Spacing. Both bit0 and bit1 turns off at the same time.
 * 1: One CLK_LF spacing between bit0 and bit1
 * 2: Two CLK_LF spacing between bit0 and bit1
 * .
 * .
 * .
 * 15: 15 CLK_LF spacing between bit0 and bit1
 */
#define PDSS_NGDO_CTRL_C_TURN_OFF_SPACING_MASK              (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_NGDO_CTRL_C_TURN_OFF_SPACING_POS               (4UL)


/*
 * 0: OV detection is not selected for turning off the NGDO
 * 1: OV detection is       selected for turning off the NGDO
 */
#define PDSS_NGDO_CTRL_C_SEL_OV                             (1UL << 8) /* <8:8> R:RW:0: */


/*
 * 0: UV detection is not selected for turning off the NGDO
 * 1: UV detection is       selected for turning off the NGDO
 */
#define PDSS_NGDO_CTRL_C_SEL_UV                             (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 0: OC detection is not selected for turning off the NGDO
 * 1: OC detection is       selected for turning off the NGDO
 */
#define PDSS_NGDO_CTRL_C_SEL_OC                             (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 0: SWAP detection & VBUS_LESS_5 is not selected for turning off the NGDO
 * 1: SWAP detection & VBUS_LESS_5 is       selected for turning off the
 * NGDO
 */
#define PDSS_NGDO_CTRL_C_SEL_SWAP_VBUS_LESS_5               (1UL << 11) /* <11:11> R:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the NGDO
 */
#define PDSS_NGDO_CTRL_C_EN_LV_OFF_VALUE_MASK               (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_NGDO_CTRL_C_EN_LV_OFF_VALUE_POS                (12UL)


/*
 * The Off value used by Hardware in Automode to turn off the NGDO
 */
#define PDSS_NGDO_CTRL_C_PULLDN_EN_LV_OFF_VALUE_MASK        (0x0000c000UL) /* <14:15> R:RW:0: */
#define PDSS_NGDO_CTRL_C_PULLDN_EN_LV_OFF_VALUE_POS         (14UL)


/*
 * Reserved
 */
#define PDSS_NGDO_CTRL_C_EN_LV_ON_VALUE_MASK                (0x00030000UL) /* <16:17> R:RW:0: */
#define PDSS_NGDO_CTRL_C_EN_LV_ON_VALUE_POS                 (16UL)


/*
 * Reserved
 */
#define PDSS_NGDO_CTRL_C_PULLDN_EN_LV_ON_VALUE_MASK         (0x000c0000UL) /* <18:19> R:RW:0: */
#define PDSS_NGDO_CTRL_C_PULLDN_EN_LV_ON_VALUE_POS          (18UL)


/*
 * Gate driver control for VBUS P
 */
#define PDSS_NGDO_CTRL_P_ADDRESS                            (0x400a01e8UL)
#define PDSS_NGDO_CTRL_P                                    (*(volatile uint32_t *)(0x400a01e8UL))
#define PDSS_NGDO_CTRL_P_DEFAULT                            (0x00000000UL)

/*
 * The gate driver control option.
 * 0: FW controlls the EN_LV and PULLDN_EN_PLV pins.
 * 1: HW controlls the EN_LV and PULLDN_EN_PLV pins
 */
#define PDSS_NGDO_CTRL_P_AUTO_MODE                          (1UL << 0) /* <0:0> R:RW:0: */


/*
 * The gate driver control option.
 * Any write-one to this register will reset the edge detector in the NGDO
 * controller.
 * FW should cleared this register after the fault conditions(OV, UV, OC,
 * VBUS_LESS_5) are removed by writing a "1" to this register.
 */
#define PDSS_NGDO_CTRL_P_RST_EDGE_DET                       (1UL << 1) /* <1:1> R:RW:0: */


/*
 * This bit selects which bit of EN_LV/PULLDN_EN_LV turns of first when the
 * TURN_OFF_SPACING is >0.
 * 0: Bit0 turns off first
 * 1: Bit1 turns off first
 * Note: IN CCG3:
 * 0: pad_vbus_p_ctrl_1 turns off first
 * 1: pad_vbus_p_ctrl_0 turns off first
 */
#define PDSS_NGDO_CTRL_P_TURN_OFF_SEL                       (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Bypassing the synchronizer for fault detection in CLK_LF domain.
 * 0: No Bypass. The spacing take effect 2 CLK_LF after the fault detection.
 * 1: Bpass: The spacing takes effect right after fault detection
 */
#define PDSS_NGDO_CTRL_P_BYPASS_2DFF                        (1UL << 3) /* <3:3> R:RW:0: */


/*
 * The EN_LV/PULLDN_EN_LV bit0 and bit 1 CLK_LF spacing.
 * 0:No Spacing. Both bit0 and bit1 turns off at the same time.
 * 1: One CLK_LF spacing between bit0 and bit1
 * 2: Two CLK_LF spacing between bit0 and bit1
 * .
 * .
 * .
 * 15: 15 CLK_LF spacing between bit0 and bit1
 */
#define PDSS_NGDO_CTRL_P_TURN_OFF_SPACING_MASK              (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_NGDO_CTRL_P_TURN_OFF_SPACING_POS               (4UL)


/*
 * 0: OV detection is not selected for turning off the NGDO
 * 1: OV detection is       selected for turning off the NGDO
 */
#define PDSS_NGDO_CTRL_P_SEL_OV                             (1UL << 8) /* <8:8> R:RW:0: */


/*
 * 0: UV detection is not selected for turning off the NGDO
 * 1: UV detection is       selected for turning off the NGDO
 */
#define PDSS_NGDO_CTRL_P_SEL_UV                             (1UL << 9) /* <9:9> R:RW:0: */


/*
 * 0: OC detection is not selected for turning off the NGDO
 * 1: OC detection is       selected for turning off the NGDO
 */
#define PDSS_NGDO_CTRL_P_SEL_OC                             (1UL << 10) /* <10:10> R:RW:0: */


/*
 * 0: SWAP detection & VBUS_LESS_5 is not selected for turning off the NGDO
 * 1: SWAP detection & VBUS_LESS_5 is       selected for turning off the
 * NGDO
 */
#define PDSS_NGDO_CTRL_P_SEL_SWAP_VBUS_LESS_5               (1UL << 11) /* <11:11> R:RW:0: */


/*
 * The Off value used by Hardware in Automode to turn off the NGDO bit[1:0]
 * Note in CCG3:
 * EN_LV Off values for [0:1]
 */
#define PDSS_NGDO_CTRL_P_EN_LV_OFF_VALUE_MASK               (0x00003000UL) /* <12:13> R:RW:0: */
#define PDSS_NGDO_CTRL_P_EN_LV_OFF_VALUE_POS                (12UL)


/*
 * The Off value used by Hardware in Automode to turn off the NGDO bit[1:0]
 * Note in CCG3:
 * PULLDN_EN_LV Off values for [0:1]
 */
#define PDSS_NGDO_CTRL_P_PULLDN_EN_LV_OFF_VALUE_MASK        (0x0000c000UL) /* <14:15> R:RW:0: */
#define PDSS_NGDO_CTRL_P_PULLDN_EN_LV_OFF_VALUE_POS         (14UL)


/*
 * The ON value used by Hardware to turn on the NGDO in swap condition bit[1:0]
 * Note in CCG3:
 * EN_LV ON values for [0:1]
 */
#define PDSS_NGDO_CTRL_P_EN_LV_ON_VALUE_MASK                (0x00030000UL) /* <16:17> R:RW:0: */
#define PDSS_NGDO_CTRL_P_EN_LV_ON_VALUE_POS                 (16UL)


/*
 * The ON value used by Hardware to turn on the NGDO in swap condition bit[1:0]
 * Note in CCG3:
 * PULLDN_EN_LV ON values for [0:1]
 */
#define PDSS_NGDO_CTRL_P_PULLDN_EN_LV_ON_VALUE_MASK         (0x000c0000UL) /* <18:19> R:RW:0: */
#define PDSS_NGDO_CTRL_P_PULLDN_EN_LV_ON_VALUE_POS          (18UL)


/*
 * S8USBPD_VER2 VBUS Discharge Register
 */
#define PDSS_VBUS_CTRL_ADDRESS                              (0x400a01ecUL)
#define PDSS_VBUS_CTRL                                      (*(volatile uint32_t *)(0x400a01ecUL))
#define PDSS_VBUS_CTRL_DEFAULT                              (0x00000000UL)

/*
 * VBUS Discharge control signal, Active High
 */
#define PDSS_VBUS_CTRL_DISCHG_EN                            (1UL << 0) /* <0:0> R:RW:0: */


/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_VBUS_CTRL_VBUS_SPARE_MASK                      (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_VBUS_CTRL_VBUS_SPARE_POS                       (8UL)


/*
 * S8USBPD_VER2 Charger Detect Register0
 */
#define PDSS_CHGDET_CTRL_0_ADDRESS                          (0x400a01f0UL)
#define PDSS_CHGDET_CTRL_0                                  (*(volatile uint32_t *)(0x400a01f0UL))
#define PDSS_CHGDET_CTRL_0_DEFAULT                          (0x80000000UL)

/*
 * Enables BC1.2 Circuitry, Active High
 */
#define PDSS_CHGDET_CTRL_0_EN_CHGDET                        (1UL << 0) /* <0:0> R:RW:0: */


/*
 * IDP_SINK enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_IDP_SNK_EN                       (1UL << 1) /* <1:1> R:RW:0: */


/*
 * IDM_SINK enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_IDM_SNK_EN                       (1UL << 2) /* <2:2> R:RW:0: */


/*
 * VDP_SRC enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_VDP_SRC_EN                       (1UL << 3) /* <3:3> R:RW:0: */


/*
 * VDM_SRC enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_VDM_SRC_EN                       (1UL << 4) /* <4:4> R:RW:0: */


/*
 * IDP_SRC enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_IDP_SRC_EN                       (1UL << 5) /* <5:5> R:RW:0: */


/*
 * DCP Short enable, Active High
 * Shorts D+ to D- with low resistance path
 */
#define PDSS_CHGDET_CTRL_0_DCP_EN                           (1UL << 6) /* <6:6> R:RW:0: */


/*
 * RDM_DWN enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_RDM_PD_EN                        (1UL << 7) /* <7:7> R:RW:0: */


/*
 * RDM_UP enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_RDM_PU_EN                        (1UL << 8) /* <8:8> R:RW:0: */


/*
 * RDP_DWN enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_RDP_PD_EN                        (1UL << 9) /* <9:9> R:RW:0: */


/*
 * RDP_UP enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_RDP_PU_EN                        (1UL << 10) /* <10:10> R:RW:0: */


/*
 * RDAT_LKG_DP enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_RDAT_LKG_DP_EN                   (1UL << 11) /* <11:11> R:RW:0: */


/*
 * RDAT_LKG_DM enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_RDAT_LKG_DM_EN                   (1UL << 12) /* <12:12> R:RW:0: */


/*
 * Output Comparator Negative input select bits:
 * 00 - DM pin
 * 01 - Vref
 * 10 - DP pin
 * 11 - GND
 */
#define PDSS_CHGDET_CTRL_0_CMP_INN_SEL_MASK                 (0x00006000UL) /* <13:14> R:RW:0: */
#define PDSS_CHGDET_CTRL_0_CMP_INN_SEL_POS                  (13UL)


/*
 * Output Comparator Positive input select bits:
 * 00 - DM pin
 * 01 - Vref
 * 10 - DP pin
 * 11 - GND
 */
#define PDSS_CHGDET_CTRL_0_CMP_INP_SEL_MASK                 (0x00018000UL) /* <15:16> R:RW:0: */
#define PDSS_CHGDET_CTRL_0_CMP_INP_SEL_POS                  (15UL)


/*
 * Reference voltage select bits
 * 0 - 0.325V
 * 1 - 0.6V
 * 2 - 0.85V
 * 3 - 1.4V
 * 4 - GND
 * 5 - 2.0V
 * 6 - 2.2V
 * 7 - 2.9V
 */
#define PDSS_CHGDET_CTRL_0_VREF_SEL_MASK                    (0x000e0000UL) /* <17:19> R:RW:0: */
#define PDSS_CHGDET_CTRL_0_VREF_SEL_POS                     (17UL)


/*
 * Enable Output Comparator, Active High
 */
#define PDSS_CHGDET_CTRL_0_EN_COMP_CHGDET                   (1UL << 20) /* <20:20> R:RW:0: */


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
#define PDSS_CHGDET_CTRL_0_CMP_OFFSET_SEL_MASK              (0x00e00000UL) /* <21:23> R:RW:0: */
#define PDSS_CHGDET_CTRL_0_CMP_OFFSET_SEL_POS               (21UL)


/*
 * Output Comparator Offset Enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_CMPP_OFFSET_EN                   (1UL << 24) /* <24:24> R:RW:0: */


/*
 * Output Comparator Unity Gain Mode Enable, Active High
 */
#define PDSS_CHGDET_CTRL_0_CMP_UGM_EN                       (1UL << 25) /* <25:25> R:RW:0: */


/*
 * Charger Detect Block Power Down
 * DPSLP_REF_CTRL.PD_DPSLP must be Low when this block is enabled
 */
#define PDSS_CHGDET_CTRL_0_PD                               (1UL << 31) /* <31:31> R:RW:1: */


/*
 * S8USBPD_VER2 Charger Detect Register1
 */
#define PDSS_CHGDET_CTRL_1_ADDRESS                          (0x400a01f4UL)
#define PDSS_CHGDET_CTRL_1                                  (*(volatile uint32_t *)(0x400a01f4UL))
#define PDSS_CHGDET_CTRL_1_DEFAULT                          (0x00000000UL)

/*
 * Enable Charger Detect ADFT Mode
 */
#define PDSS_CHGDET_CTRL_1_CHGDET_ADFT_EN                   (1UL << 0) /* <0:0> R:RW:0: */


/*
 * ADFT Select Control.  See the s8usbpd_ver2 BROS for more details
 */
#define PDSS_CHGDET_CTRL_1_CHGDET_ADFT_CTRL_MASK            (0x0000001eUL) /* <1:4> R:RW:0: */
#define PDSS_CHGDET_CTRL_1_CHGDET_ADFT_CTRL_POS             (1UL)


/*
 * Output isolation control.  Active Low
 * 0: All digital outputs are forced low
 */
#define PDSS_CHGDET_CTRL_1_CHGDET_ISO_N                     (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Apple detection enable to detect the 2.9V termination voltage on DP/DM
 */
#define PDSS_CHGDET_CTRL_1_CHGDET_APP_DET                   (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Apple DM termination enable control
 * 00 - Termination disabled
 * 01 - 1.5V
 * 10 - 2.5V: This mode uses the BC1.2 Driver, so CHGDET_CTRL_0.EN_CHGDET
 * and CHGDET_CTRL_0.VDM_SRC_EN must be set high
 * 11 - DO NOT USE: For 3.3V termination, use the RPU pullup. Set CHGDET_CTRL_0.RDM_PU_EN
 * high
 */
#define PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DM_MASK        (0x00000180UL) /* <7:8> R:RW:0: */
#define PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DM_POS         (7UL)


/*
 * Apple DP termination enable control
 * 00 - Termination disabled
 * 01 - 1.5V
 * 10 - 2.5V: This mode uses the BC1.2 Driver, so CHGDET_CTRL_0.EN_CHGDET
 * and CHGDET_CTRL_0.VDP_SRC_EN must be set high
 * 11 - DO NOT USE: For 3.3V termination, use the RPU pullup. Set CHGDET_CTRL_0.RDP_PU_EN
 * high
 */
#define PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DP_MASK        (0x00000600UL) /* <9:10> R:RW:0: */
#define PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DP_POS         (9UL)


/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_CHGDET_CTRL_1_CHGDET_SPARE_MASK                (0x00ff0000UL) /* <16:23> R:RW:0: */
#define PDSS_CHGDET_CTRL_1_CHGDET_SPARE_POS                 (16UL)


/*
 * Ncells Wakeup Interrupts edge and filter configuration 0
 */
#define PDSS_INTR3_CFG_0_ADDRESS                            (0x400a01f8UL)
#define PDSS_INTR3_CFG_0                                    (*(volatile uint32_t *)(0x400a01f8UL))
#define PDSS_INTR3_CFG_0_DEFAULT                            (0x06333333UL)

/*
 * Filtering the positive edge of ocp_det from s8usbpd.:
 * 0: No Filtering
 * 1: Refer to CSA_FILT_SEL
 */
#define PDSS_INTR3_CFG_0_CSA_POS_FILT_EN                    (1UL << 0) /* <0:0> R:RW:1: */


/*
 * The positive edge of over current detection signal goes through a digital
 * filter which runs at CLK_LF.
 * The output of this filter is used for wakeup interrupt as well as turing
 * off the gate driver.
 * If filtering is required, then CSA_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_INTR3_CFG_0_CSA_POS_FILT_SEL_MASK              (0x0000000eUL) /* <1:3> R:RW:1: */
#define PDSS_INTR3_CFG_0_CSA_POS_FILT_SEL_POS               (1UL)


/*
 * Filtering the negative edge of ocp_det from s8usbpd.:
 * 0: No Filtering
 * 1: Refer to CSA_FILT_SEL
 */
#define PDSS_INTR3_CFG_0_CSA_NEG_FILT_EN                    (1UL << 4) /* <4:4> R:RW:1: */


/*
 * The negative edge of over current detection signal goes through a digital
 * filter which runs at CLK_LF.
 * The output of this filter is used for wakeup interrupt as well as turing
 * off the gate driver.
 * If filtering is required, then CSA_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_INTR3_CFG_0_CSA_NEG_FILT_SEL_MASK              (0x000000e0UL) /* <5:7> R:RW:1: */
#define PDSS_INTR3_CFG_0_CSA_NEG_FILT_SEL_POS               (5UL)


/*
 * Filtering the positive edge of ov_det from s8usbpd.:
 * 0: No Filtering
 * 1: Refer to OV_FILT_SEL
 */
#define PDSS_INTR3_CFG_0_OV_POS_FILT_EN                     (1UL << 8) /* <8:8> R:RW:1: */


/*
 * The positive edge if over voltage detection signal goes through a digital
 * filter which runs at CLK_LF.
 * The output of this filter is used for wakeup interrupt as well as turing
 * off the gate driver.
 * If filtering is required, then OV_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_INTR3_CFG_0_OV_POS_FILT_SEL_MASK               (0x00000e00UL) /* <9:11> R:RW:1: */
#define PDSS_INTR3_CFG_0_OV_POS_FILT_SEL_POS                (9UL)


/*
 * Filtering the negative edge of ov_det from s8usbpd.:
 * 0: No Filtering
 * 1: Refer to OV_FILT_SEL
 */
#define PDSS_INTR3_CFG_0_OV_NEG_FILT_EN                     (1UL << 12) /* <12:12> R:RW:1: */


/*
 * The negative edge if over voltage detection signal goes through a digital
 * filter which runs at CLK_LF.
 * The output of this filter is used for wakeup interrupt as well as turing
 * off the gate driver.
 * If filtering is required, then OV_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_INTR3_CFG_0_OV_NEG_FILT_SEL_MASK               (0x0000e000UL) /* <13:15> R:RW:1: */
#define PDSS_INTR3_CFG_0_OV_NEG_FILT_SEL_POS                (13UL)


/*
 * Filtering the possitive edge of uv_det from s8usbpd.:
 * 0: No Filtering
 * 1: Refer to UV_FILT_SEL
 */
#define PDSS_INTR3_CFG_0_UV_POS_FILT_EN                     (1UL << 16) /* <16:16> R:RW:1: */


/*
 * The positive edge of under voltage detection signal goes through a digital
 * filter which runs at CLK_LF.
 * The output of this filter is used for wakeup interrupt as well as turing
 * off the gate driver.
 * If filtering is required, then UV_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_INTR3_CFG_0_UV_POS_FILT_SEL_MASK               (0x000e0000UL) /* <17:19> R:RW:1: */
#define PDSS_INTR3_CFG_0_UV_POS_FILT_SEL_POS                (17UL)


/*
 * Filtering the negative edge of uv_det from s8usbpd.:
 * 0: No Filtering
 * 1: Refer to UV_FILT_SEL
 */
#define PDSS_INTR3_CFG_0_UV_NEG_FILT_EN                     (1UL << 20) /* <20:20> R:RW:1: */


/*
 * The negative edge of under voltage detection signal goes through a digital
 * filter which runs at CLK_LF.
 * The output of this filter is used for wakeup interrupt as well as turing
 * off the gate driver.
 * If filtering is required, then UV_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LFF
 * 0, 4:7: Reserved
 */
#define PDSS_INTR3_CFG_0_UV_NEG_FILT_SEL_MASK               (0x00e00000UL) /* <21:23> R:RW:1: */
#define PDSS_INTR3_CFG_0_UV_NEG_FILT_SEL_POS                (21UL)


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR3_CFG_0_CHGDET_CFG_MASK                    (0x03000000UL) /* <24:25> R:RW:2: */
#define PDSS_INTR3_CFG_0_CHGDET_CFG_POS                     (24UL)


/*
 * Filtering the chgdet from s8usbpd_ver2_vconn_term_top:
 * 0: No Filtering
 * 1: Refer to CHGDET_FILT_SEL
 */
#define PDSS_INTR3_CFG_0_CHGDET_FILT_EN                     (1UL << 26) /* <26:26> R:RW:1: */


/*
 * The charger detection signal goes through a digital filter which runs
 * at CLK_LF.
 * The output of this filter is used for wakeup interrupt
 * If filtering is required, then CHGDET_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_INTR3_CFG_0_CHGDET_FILT_SEL_MASK               (0x38000000UL) /* <27:29> R:RW:0: */
#define PDSS_INTR3_CFG_0_CHGDET_FILT_SEL_POS                (27UL)


/*
 * Ncells Wakeup Interrupts edge and filter configuration 1
 */
#define PDSS_INTR3_CFG_1_ADDRESS                            (0x400a01fcUL)
#define PDSS_INTR3_CFG_1                                    (*(volatile uint32_t *)(0x400a01fcUL))
#define PDSS_INTR3_CFG_1_DEFAULT                            (0x00006186UL)

/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR3_CFG_1_VSYS_CFG_MASK                      (0x00000003UL) /* <0:1> R:RW:2: */
#define PDSS_INTR3_CFG_1_VSYS_CFG_POS                       (0UL)


/*
 * Filtering the vsys_det from s8usbpd.:
 * 0: No Filtering
 * 1: Refer to VSYS_FILT_SEL
 */
#define PDSS_INTR3_CFG_1_VSYS_FILT_EN                       (1UL << 2) /* <2:2> R:RW:1: */


/*
 * The VSYS detection signal goes through a digital filter which runs at
 * CLK_LF.
 * The output of this filter is used for wakeup interrupt.
 * If filtering is required, then VSYS_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_INTR3_CFG_1_VSYS_FILT_SEL_MASK                 (0x00000038UL) /* <3:5> R:RW:0: */
#define PDSS_INTR3_CFG_1_VSYS_FILT_SEL_POS                  (3UL)


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR3_CFG_1_VBUS_C_CFG_MASK                    (0x000000c0UL) /* <6:7> R:RW:2: */
#define PDSS_INTR3_CFG_1_VBUS_C_CFG_POS                     (6UL)


/*
 * Filtering the vbus_c_det from s8usbpd.:
 * 0: No Filtering
 * 1: Refer to VBUS_C_FILT_SEL
 */
#define PDSS_INTR3_CFG_1_VBUS_C_FILT_EN                     (1UL << 8) /* <8:8> R:RW:1: */


/*
 * The VBUS_C detection signal goes through a digital filter which runs at
 * CLK_LF.
 * The output of this filter is used for wakeup interrupt.
 * If filtering is required, then VBUS_C_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_INTR3_CFG_1_VBUS_C_FILT_SEL_MASK               (0x00000e00UL) /* <9:11> R:RW:0: */
#define PDSS_INTR3_CFG_1_VBUS_C_FILT_SEL_POS                (9UL)


/*
 * Edge detect positive/negative enable/disable
 */
#define PDSS_INTR3_CFG_1_VBUS_P_CFG_MASK                    (0x00003000UL) /* <12:13> R:RW:2: */
#define PDSS_INTR3_CFG_1_VBUS_P_CFG_POS                     (12UL)


/*
 * Filtering the vbus_p_det from s8usbpd.:
 * 0: No Filtering
 * 1: Refer to VBUS_P_FILT_SEL
 */
#define PDSS_INTR3_CFG_1_VBUS_P_FILT_EN                     (1UL << 14) /* <14:14> R:RW:1: */


/*
 * The VBUS_P detection signal goes through a digital filter which runs at
 * CLK_LF.
 * The output of this filter is used for wakeup interrupt.
 * If filtering is required, then VBUS_P_FILT_EN needs to beset to "1".
 * 1: Filter for one CLK_LF
 * 2: Filter for two CLK_LF
 * 3: Filter for three CLK_LF
 * 0, 4:7: Reserved
 */
#define PDSS_INTR3_CFG_1_VBUS_P_FILT_SEL_MASK               (0x00038000UL) /* <15:17> R:RW:0: */
#define PDSS_INTR3_CFG_1_VBUS_P_FILT_SEL_POS                (15UL)


/*
 * Ncells Status
 */
#define PDSS_NCELL_STATUS_ADDRESS                           (0x400a0200UL)
#define PDSS_NCELL_STATUS                                   (*(volatile uint32_t *)(0x400a0200UL))
#define PDSS_NCELL_STATUS_DEFAULT                           (0x00000000UL)

/*
 * The status of vsys_det from the s8usbpd_ver2_vddd_sw_top
 */
#define PDSS_NCELL_STATUS_VSYS_STATUS                       (1UL << 0) /* <0:0> RW:R:0: */


/*
 * The status of ocp_det from the s8usbpd_ver2_csa
 */
#define PDSS_NCELL_STATUS_CSA_STATUS                        (1UL << 1) /* <1:1> RW:R:0: */


/*
 * The status of uv_det from the s8usbpd_ver2_uvov_top
 */
#define PDSS_NCELL_STATUS_UV_STATUS                         (1UL << 2) /* <2:2> RW:R:0: */


/*
 * The status of ov_det from the s8usbpd_ver2_uvov_top
 */
#define PDSS_NCELL_STATUS_OV_STATUS                         (1UL << 3) /* <3:3> RW:R:0: */


/*
 * The status of chgdet_out from the s8usbpd_ver2_chgdet_top
 */
#define PDSS_NCELL_STATUS_CHGDET_STATUS                     (1UL << 4) /* <4:4> RW:R:0: */


/*
 * The status of vbus_c_det from the s8usbpd_ver2_20vreg_top
 */
#define PDSS_NCELL_STATUS_VBUS_C_STATUS                     (1UL << 5) /* <5:5> RW:R:0: */


/*
 * The status of vbus_p_det from the s8usbpd_ver2_20vreg_top
 */
#define PDSS_NCELL_STATUS_VBUS_P_STATUS                     (1UL << 6) /* <6:6> RW:R:0: */


/*
 * Ncells interrupt Cause.  These are the wakeup interrupts get reflected
 * on interrupt_wakeup pin.
 */
#define PDSS_INTR3_ADDRESS                                  (0x400a0204UL)
#define PDSS_INTR3                                          (*(volatile uint32_t *)(0x400a0204UL))
#define PDSS_INTR3_DEFAULT                                  (0x00000000UL)

/*
 * vsys_det changed (wakeup interrupt from deepsleep)
 * Check the  NCELL.STATUS.VSYS_STATUS value
 */
#define PDSS_INTR3_VSYS_CHANGED                             (1UL << 0) /* <0:0> RW1S:RW1C:0: */


/*
 * Positive edge of ocp_det detected (wakeup interrupt from deepsleep)
 * Check the  NCELL.STATUS_5.CSA_STATUS value
 */
#define PDSS_INTR3_POS_CSA_CHANGED                          (1UL << 1) /* <1:1> RW1S:RW1C:0: */


/*
 * Positive edge of ov_det changed (wakeup interrupt from deepsleep)
 * Check the  NCELL.STATU.OV_STATUS value
 */
#define PDSS_INTR3_POS_OV_CHANGED                           (1UL << 2) /* <2:2> RW1S:RW1C:0: */


/*
 * Positive edge of uv_det changed (wakeup interrupt from deepsleep)
 * Check the  NCELL.STATUS.UV_STATUS value
 */
#define PDSS_INTR3_POS_UV_CHANGED                           (1UL << 3) /* <3:3> RW1S:RW1C:0: */


/*
 * Negedge edge of ocp_det detected (wakeup interrupt from deepsleep)
 * Check the  NCELL.STATUS_5.CSA_STATUS value
 */
#define PDSS_INTR3_NEG_CSA_CHANGED                          (1UL << 4) /* <4:4> RW1S:RW1C:0: */


/*
 * Negedge edge of ov_det changed (wakeup interrupt from deepsleep)
 * Check the  NCELL.STATU.OV_STATUS value
 */
#define PDSS_INTR3_NEG_OV_CHANGED                           (1UL << 5) /* <5:5> RW1S:RW1C:0: */


/*
 * Negedge edge of uv_det changed (wakeup interrupt from deepsleep)
 * Check the  NCELL.STATUS.UV_STATUS value
 */
#define PDSS_INTR3_NEG_UV_CHANGED                           (1UL << 6) /* <6:6> RW1S:RW1C:0: */


/*
 * chgdet changed (wakeup interrupt from deepsleep)
 * Check the  NCELL.STATUS.CHGDET_STATUS value
 */
#define PDSS_INTR3_CHGDET_CHANGED                           (1UL << 7) /* <7:7> RW1S:RW1C:0: */


/*
 * vbus_c_det changed (wakeup interrupt from deepsleep)
 * Check the  NCELL.STATUS.VBUS_C_STATUS value
 */
#define PDSS_INTR3_VBUS_C_CHANGED                           (1UL << 8) /* <8:8> RW1S:RW1C:0: */


/*
 * vbus_p_det changed (wakeup interrupt from deepsleep)
 * Check the  NCELL.STATUS.VBUS_P_STATUS value
 */
#define PDSS_INTR3_VBUS_P_CHANGED                           (1UL << 9) /* <9:9> RW1S:RW1C:0: */


/*
 * Ncells Interrupt Set
 */
#define PDSS_INTR3_SET_ADDRESS                              (0x400a0208UL)
#define PDSS_INTR3_SET                                      (*(volatile uint32_t *)(0x400a0208UL))
#define PDSS_INTR3_SET_DEFAULT                              (0x00000000UL)

/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_VSYS_CHANGED                         (1UL << 0) /* <0:0> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_POS_CSA_CHANGED                      (1UL << 1) /* <1:1> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_POS_OV_CHANGED                       (1UL << 2) /* <2:2> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_POS_UV_CHANGED                       (1UL << 3) /* <3:3> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_NEG_CSA_CHANGED                      (1UL << 4) /* <4:4> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_NEG_OV_CHANGED                       (1UL << 5) /* <5:5> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_NEG_UV_CHANGED                       (1UL << 6) /* <6:6> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_CHGDET_CHANGED                       (1UL << 7) /* <7:7> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_VBUS_C_CHANGED                       (1UL << 8) /* <8:8> A:RW1S:0: */


/*
 * Write with '1' to set corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_SET_VBUS_P_CHANGED                       (1UL << 9) /* <9:9> A:RW1S:0: */


/*
 * Ncells interrupt Mask
 */
#define PDSS_INTR3_MASK_ADDRESS                             (0x400a020cUL)
#define PDSS_INTR3_MASK                                     (*(volatile uint32_t *)(0x400a020cUL))
#define PDSS_INTR3_MASK_DEFAULT                             (0x00000000UL)

/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_VSYS_CHANGED_MASK                   (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_POS_CSA_CHANGED_MASK                (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_POS_OV_CHANGED_MASK                 (1UL << 2) /* <2:2> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_POS_UV_CHANGED_MASK                 (1UL << 3) /* <3:3> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_NEG_CSA_CHANGED_MASK                (1UL << 4) /* <4:4> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_NEG_OV_CHANGED_MASK                 (1UL << 5) /* <5:5> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_NEG_UV_CHANGED_MASK                 (1UL << 6) /* <6:6> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_CHGDET_CHANGED_MASK                 (1UL << 7) /* <7:7> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_VBUS_C_CHANGED_MASK                 (1UL << 8) /* <8:8> R:RW:0: */


/*
 * Mask bit for corresponding bit in interrupt request register.
 */
#define PDSS_INTR3_MASK_VBUS_P_CHANGED_MASK                 (1UL << 9) /* <9:9> R:RW:0: */


/*
 * Ncells interrupt Masked
 */
#define PDSS_INTR3_MASKED_ADDRESS                           (0x400a0210UL)
#define PDSS_INTR3_MASKED                                   (*(volatile uint32_t *)(0x400a0210UL))
#define PDSS_INTR3_MASKED_DEFAULT                           (0x00000000UL)

/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_VSYS_CHANGED_MASKED               (1UL << 0) /* <0:0> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_POS_CSA_CHANGED_MASKED            (1UL << 1) /* <1:1> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_POS_OV_CHANGED_MASKED             (1UL << 2) /* <2:2> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_POS_UV_CHANGED_MASKED             (1UL << 3) /* <3:3> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_NEG_CSA_CHANGED_MASKED            (1UL << 4) /* <4:4> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_NEG_OV_CHANGED_MASKED             (1UL << 5) /* <5:5> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_NEG_UV_CHANGED_MASKED             (1UL << 6) /* <6:6> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_CHGDET_CHANGED_MASKED             (1UL << 7) /* <7:7> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_VBUS_C_CHANGED_MASKED             (1UL << 8) /* <8:8> RW:R:0: */


/*
 * Logical and of corresponding request and mask bits.
 */
#define PDSS_INTR3_MASKED_VBUS_P_CHANGED_MASKED             (1UL << 9) /* <9:9> RW:R:0: */


/*
 * NCELL DDFT Selections
 */
#define PDSS_NCELL_DDFT_MUX_ADDRESS                         (0x400a0214UL)
#define PDSS_NCELL_DDFT_MUX                                 (*(volatile uint32_t *)(0x400a0214UL))
#define PDSS_NCELL_DDFT_MUX_DEFAULT                         (0x00000000UL)

/*
 * In CCG3:
 * 30      vbus_p_en_lv[0]
 * 29      vbus_p_en_lv[1]
 * 28      vbus_p_pulldn_en_lv[0]
 * 27      vbus_p_pulldn_en_lv[1]
 * else
 * 30      vbus_p_en_lv[1]
 * 29      vbus_p_en_lv[0]
 * 28      vbus_p_pulldn_en_lv[1]
 * 27      vbus_p_pulldn_en_lv[0]
 *
 * 26      vbus_c_en_lv[1]
 * 25      vbus_c_en_lv[0]
 * 24      vbus_c_pulldn_en_lv[1]
 * 23      vbus_c_pulldn_en_lv[0]
 * 22      intr_cause_vbus_c_done
 * 21      intr_cause_vbus_p_done
 * 20      vbus_c_fx_scan
 * 19      vbus_p_fx_scan
 * 18      ngdo_vbus_p_ddft
 * 17      ngdo_vbus_c_ddft
 * 16      vbus_p_ddft_faults_masked
 * 15      vbus_p_ddft_async_fault_det
 * 14      intr_cause_chgdet_done
 * 13      intr_cause_vsys_done
 * 12      intr_cause_neg_ocp_done
 * 11      intr_cause_neg_uv_done
 * 10      intr_cause_neg_ov_done
 * 9       intr_cause_pos_ocp_done
 * 8       intr_cause_pos_uv_done
 * 7       intr_cause_pos_ov_done
 * 6       vbus_c_ddft_faults_masked
 * 5       vbus_c_ddft_async_fault_det
 * 4       chgdet_fx_scan
 * 3       vsys_fx_scan
 * 2       ocp_fx_scan
 * 1       uv_fx_scan
 * 0       ov_fx_scan
 */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT0_SEL_MASK            (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT0_SEL_POS             (0UL)


/*
 * In CCG3:
 * 30      vbus_p_en_lv[0]
 * 29      vbus_p_en_lv[1]
 * 28      vbus_p_pulldn_en_lv[0]
 * 27      vbus_p_pulldn_en_lv[1]
 * else
 * 30      vbus_p_en_lv[1]
 * 29      vbus_p_en_lv[0]
 * 28      vbus_p_pulldn_en_lv[1]
 * 27      vbus_p_pulldn_en_lv[0]
 *
 * 26      vbus_c_en_lv[1]
 * 25      vbus_c_en_lv[0]
 * 24      vbus_c_pulldn_en_lv[1]
 * 23      vbus_c_pulldn_en_lv[0]
 * 22      intr_cause_vbus_c_done
 * 21      intr_cause_vbus_p_done
 * 20      vbus_c_fx_scan
 * 19      vbus_p_fx_scan
 * 18      ngdo_vbus_p_ddft
 * 17      ngdo_vbus_c_ddft
 * 16      vbus_p_ddft_faults_masked
 * 15      vbus_p_ddft_async_fault_det
 * 14      intr_cause_chgdet_done
 * 13      intr_cause_vsys_done
 * 12      intr_cause_neg_ocp_done
 * 11      intr_cause_neg_uv_done
 * 10      intr_cause_neg_ov_done
 * 9       intr_cause_pos_ocp_done
 * 8       intr_cause_pos_uv_done
 * 7       intr_cause_pos_ov_done
 * 6       vbus_c_ddft_faults_masked
 * 5       vbus_c_ddft_async_fault_det
 * 4       chgdet_fx_scan
 * 3       vsys_fx_scan
 * 2       ocp_fx_scan
 * 1       uv_fx_scan
 * 0       ov_fx_scan
 */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT1_SEL_MASK            (0x00000fc0UL) /* <6:11> R:RW:0: */
#define PDSS_NCELL_DDFT_MUX_NCELL_DDFT1_SEL_POS             (6UL)


/*
 * IP GPIO DDFT Selections
 */
#define PDSS_GPIO_DDFT_MUX_ADDRESS                          (0x400a0218UL)
#define PDSS_GPIO_DDFT_MUX                                  (*(volatile uint32_t *)(0x400a0218UL))
#define PDSS_GPIO_DDFT_MUX_DEFAULT                          (0x00000000UL)

/*
 * 47      intr_swap_queue_set
 * 46      intr_swap_unstable_set
 * 45      intr_swap_unpluged_set
 * 44      intr_swap_pluged_set
 * 43      intr_swap_irq_set
 * 42      intr_swapt_command_done_set
 * 41      gpio_intr_ddft1
 * 40      gpio_intr_ddft0
 * 39      gpio_ncell_ddft1
 * 38      gpio_ncell_ddft0
 * 37      spare7_gpio
 * 36      spare6_gpio
 * 35      intr_hpd_queue_set
 * 34      intr_hpd_unstable_set
 * 33      intr_hpd_unpluged_set
 * 32      intr_hpd_pluged_set
 * 31      intr_hpd_irq_set
 * 30      intr_hpdt_command_done_set
 * 29      hpdin_gpio
 * 28      ddft_collision_src[4]
 * 27      ddft_collision_src[3]
 * 26      ddft_collision_src[2]
 * 25      ddft_collision_src[1]
 * 24      ddft_collision_src[0]
 * 23      cmp_out_fx_scan[1]
 * 22      cmp_out_fx_scan[0]
 * 21      v5v_gpio
 * 20      ddft_cc_core_rx_data
 * 19      vcmp_fs
 * 18      ddft_cc_ctrl_tx_en
 * 17      ddft_cc_tx_data_eop
 * 16      ddft_cc_tx_data_valid
 * 15      1'b0
 * 14      vconn2_gpio
 * 13      vconn1_gpio
 * 12      vcmp_dn_gpio
 * 11      vcmp_la_gpio
 * 10      vcmp_up_gpio
 * 9       ddft_sop_valid
 * 8       ddft_rx_eop
 * 7       ddft_raw_cc_rx_valid
 * 6       ddft_cc_rx_bit_en
 * 5       ddft_cc_core_tx_data
 * 4       cc_tx_data
 * 3       1'b0
 * 2       cc1_gpio
 * 1       cc2_gpio
 * 0      Reserved
 */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT0_SEL_MASK              (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT0_SEL_POS               (0UL)


/*
 * 47      intr_swap_queue_set
 * 46      intr_swap_unstable_set
 * 45      intr_swap_unpluged_set
 * 44      intr_swap_pluged_set
 * 43      intr_swap_irq_set
 * 42      intr_swapt_command_done_set
 * 41      gpio_intr_ddft1
 * 40      gpio_intr_ddft0
 * 39      gpio_ncell_ddft1
 * 38      gpio_ncell_ddft0
 * 37      spare7_gpio
 * 36      spare6_gpio
 * 35      intr_hpd_queue_set
 * 34      intr_hpd_unstable_set
 * 33      intr_hpd_unpluged_set
 * 32      intr_hpd_pluged_set
 * 31      intr_hpd_irq_set
 * 30      intr_hpdt_command_done_set
 * 29      hpdin_gpio
 * 28      ddft_collision_src[4]
 * 27      ddft_collision_src[3]
 * 26      ddft_collision_src[2]
 * 25      ddft_collision_src[1]
 * 24      ddft_collision_src[0]
 * 23      cmp_out_fx_scan[1]
 * 22      cmp_out_fx_scan[0]
 * 21      v5v_gpio
 * 20      ddft_cc_core_rx_data
 * 19      vcmp_fs
 * 18      ddft_cc_ctrl_tx_en
 * 17      ddft_cc_tx_data_eop
 * 16      ddft_cc_tx_data_valid
 * 15      1'b0
 * 14      vconn2_gpio
 * 13      vconn1_gpio
 * 12      vcmp_dn_gpio
 * 11      vcmp_la_gpio
 * 10      vcmp_up_gpio
 * 9       ddft_sop_valid
 * 8       ddft_rx_eop
 * 7       ddft_raw_cc_rx_valid
 * 6       ddft_cc_rx_bit_en
 * 5       ddft_cc_core_tx_data
 * 4       cc_tx_data
 * 3       1'b0
 * 2       cc1_gpio
 * 1       cc2_gpio
 * 0      Reserved
 */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT1_SEL_MASK              (0x00000fc0UL) /* <6:11> R:RW:0: */
#define PDSS_GPIO_DDFT_MUX_GPIO_DDFT1_SEL_POS               (6UL)


/*
 * Interrupt GPIO DDFT Selections
 */
#define PDSS_GPIO_INTR_DDFT_MUX_ADDRESS                     (0x400a021cUL)
#define PDSS_GPIO_INTR_DDFT_MUX                             (*(volatile uint32_t *)(0x400a021cUL))
#define PDSS_GPIO_INTR_DDFT_MUX_DEFAULT                     (0x00000000UL)

/*
 * 70      intr_cause_vswap_vbus_less_5_done
 * 69      intr_cause_swapt_command_done_done
 * 68      intr_cause_swap_queue_done
 * 67      intr_cause_swap_unstable_done
 * 66      intr_cause_swap_unpluged_done
 * 65      intr_cause_swap_pluged_done
 * 64      intr_cause_swap_irq_done
 * 63      intr_cause_ngdo_c_spacing_done_done
 * 62      intr_cause_ngdo_p_spacing_done_done
 * 61      intr_cause_vreg20v_switch_done
 * 60      intr_cause_vddd_sw_switch_done
 * 59      intr_cause_chunk_det_done
 * 58      intr_cause_tx_sram_under_flow_done
 * 57      intr_cause_rx_sram_over_flow_done
 * 56      intr_cause_spare5_done
 * 55      intr_cause_spare4_done
 * 54      intr_cause_spare3_done
 * 53      intr_cause_extended_msg_det_done
 * 52      intr_cause_hpdt_command_done_done
 * 51      intr_cause_hpd_queue_done
 * 50      intr_cause_hpd_unstable_done
 * 49      intr_cause_hpd_unpluged_done
 * 48      intr_cause_hpd_pluged_done
 * 47      intr_cause_hpd_irq_done
 * 46      intr_cause_ui_cal_done_done
 * 45      intr_cause_pulse_min_violated_done
 * 44      intr_cause_pulse_max_violated_done
 * 43      intr1_cause_spare7_done
 * 42      intr1_cause_spare6_done
 * 41      intr1_cause_hpdin_changed_done
 * 40      intr1_cause_cmp_out_done[1]
 * 39      intr1_cause_cmp_out_done[0]
 * 38      intr1_cause_v5v_done
 * 37      intr1_cause_vcmp_dn_done
 * 36      intr1_cause_vcmp_up_done
 * 35      intr1_cause_vcmp_la_done
 * 34      intr1_cause_cc2_changed_done
 * 33      intr1_cause_cc1_changed_done
 * 32      intr1_cause_vconn2_changed_done
 * 31      intr1_cause_vconn1_changed_done
 * 30      intr_cause_cmp_out_det_done[1]
 * 29      intr_cause_sar_done[1]
 * 28      intr_cause_rx_state_idle_done
 * 27      intr_cause_tx_state_idle_done
 * 26      intr_cause_tx_regulator_enabled_done
 * 25      intr_cause_tx_cc_data_oen_deassert_done
 * 24      intr_cause_tx_cc_data_oen_assert_done
 * 23      intr_cause_kchar_error_done
 * 22      intr_cause_tx_retry_enable_clrd_done
 * 21      intr_cause_rx_sram_half_end_done
 * 20      intr_cause_tx_sram_half_end_done
 * 19      intr_cause_cmp_out_det_done[0]
 * 18      intr_cause_collision_type4_done
 * 17      intr_cause_collision_type3_done
 * 16      intr_cause_collision_type2_done
 * 15      intr_cause_collision_type1_done
 * 14      intr_cause_crc_rx_timer_exp_done
 * 13      intr_cause_cc_no_valid_data_detected_done
 * 12      intr_cause_cc_valid_data_detected_done
 * 11      intr_cause_tx_goodcrc_msg_done
 * 10      intr_cause_sar_done[0]
 * 9       intr_cause_rcv_rst_done
 * 8       intr_cause_tx_hard_rst_done
 * 7       intr_cause_tx_packet_done
 * 6       intr_cause_rx_over_run_done
 * 5       intr_cause_eop_error_done
 * 4       intr_cause_rcv_expt_goodcrc_msg_complete_done
 * 3       intr_cause_rcv_goodcrc_msg_complete_done
 * 2       intr_cause_rx_sop_done
 * 1       intr_cause_rcv_bad_packet_complete_done
 * 0       intr_cause_rcv_good_packet_complete_done
 */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT0_SEL_MASK    (0x0000007fUL) /* <0:6> R:RW:0: */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT0_SEL_POS     (0UL)


/*
 * 70      intr_cause_vswap_vbus_less_5_done
 * 69      intr_cause_swapt_command_done_done
 * 68      intr_cause_swap_queue_done
 * 67      intr_cause_swap_unstable_done
 * 66      intr_cause_swap_unpluged_done
 * 65      intr_cause_swap_pluged_done
 * 64      intr_cause_swap_irq_done
 * 63      intr_cause_ngdo_c_spacing_done_done
 * 62      intr_cause_ngdo_p_spacing_done_done
 * 61      intr_cause_vreg20v_switch_done
 * 60      intr_cause_vddd_sw_switch_done
 * 59      intr_cause_chunk_det_done
 * 58      intr_cause_tx_sram_under_flow_done
 * 57      intr_cause_rx_sram_over_flow_done
 * 56      intr_cause_spare5_done
 * 55      intr_cause_spare4_done
 * 54      intr_cause_spare3_done
 * 53      intr_cause_extended_msg_det_done
 * 52      intr_cause_hpdt_command_done_done
 * 51      intr_cause_hpd_queue_done
 * 50      intr_cause_hpd_unstable_done
 * 49      intr_cause_hpd_unpluged_done
 * 48      intr_cause_hpd_pluged_done
 * 47      intr_cause_hpd_irq_done
 * 46      intr_cause_ui_cal_done_done
 * 45      intr_cause_pulse_min_violated_done
 * 44      intr_cause_pulse_max_violated_done
 * 43      intr1_cause_spare7_done
 * 42      intr1_cause_spare6_done
 * 41      intr1_cause_hpdin_changed_done
 * 40      intr1_cause_cmp_out_done[1]
 * 39      intr1_cause_cmp_out_done[0]
 * 38      intr1_cause_v5v_done
 * 37      intr1_cause_vcmp_dn_done
 * 36      intr1_cause_vcmp_up_done
 * 35      intr1_cause_vcmp_la_done
 * 34      intr1_cause_cc2_changed_done
 * 33      intr1_cause_cc1_changed_done
 * 32      intr1_cause_vconn2_changed_done
 * 31      intr1_cause_vconn1_changed_done
 * 30      intr_cause_cmp_out_det_done[1]
 * 29      intr_cause_sar_done[1]
 * 28      intr_cause_rx_state_idle_done
 * 27      intr_cause_tx_state_idle_done
 * 26      intr_cause_tx_regulator_enabled_done
 * 25      intr_cause_tx_cc_data_oen_deassert_done
 * 24      intr_cause_tx_cc_data_oen_assert_done
 * 23      intr_cause_kchar_error_done
 * 22      intr_cause_tx_retry_enable_clrd_done
 * 21      intr_cause_rx_sram_half_end_done
 * 20      intr_cause_tx_sram_half_end_done
 * 19      intr_cause_cmp_out_det_done[0]
 * 18      intr_cause_collision_type4_done
 * 17      intr_cause_collision_type3_done
 * 16      intr_cause_collision_type2_done
 * 15      intr_cause_collision_type1_done
 * 14      intr_cause_crc_rx_timer_exp_done
 * 13      intr_cause_cc_no_valid_data_detected_done
 * 12      intr_cause_cc_valid_data_detected_done
 * 11      intr_cause_tx_goodcrc_msg_done
 * 10      intr_cause_sar_done[0]
 * 9       intr_cause_rcv_rst_done
 * 8       intr_cause_tx_hard_rst_done
 * 7       intr_cause_tx_packet_done
 * 6       intr_cause_rx_over_run_done
 * 5       intr_cause_eop_error_done
 * 4       intr_cause_rcv_expt_goodcrc_msg_complete_done
 * 3       intr_cause_rcv_goodcrc_msg_complete_done
 * 2       intr_cause_rx_sop_done
 * 1       intr_cause_rcv_bad_packet_complete_done
 * 0       intr_cause_rcv_good_packet_complete_done
 */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT1_SEL_MASK    (0x00003f80UL) /* <7:13> R:RW:0: */
#define PDSS_GPIO_INTR_DDFT_MUX_GPIO_INTR_DDFT1_SEL_POS     (7UL)


/*
 * NCELL GPIO DDFT Selections
 */
#define PDSS_GPIO_NCELL_DDFT_MUX_ADDRESS                    (0x400a0220UL)
#define PDSS_GPIO_NCELL_DDFT_MUX                            (*(volatile uint32_t *)(0x400a0220UL))
#define PDSS_GPIO_NCELL_DDFT_MUX_DEFAULT                    (0x00000000UL)

/*
 * In CCG3:
 * 35      vbus_p_en_lv[0]
 * 34      vbus_p_en_lv[1]
 * 33      vbus_p_pulldn_en_lv[0]
 * 32      vbus_p_pulldn_en_lv[1]
 * Else
 * 35      vbus_p_en_lv[1]
 * 34      vbus_p_en_lv[0]
 * 33      vbus_p_pulldn_en_lv[1]
 * 32      vbus_p_pulldn_en_lv[0]
 *
 * 31      vbus_c_en_lv[1]
 * 30      vbus_c_en_lv[0]
 * 29      vbus_c_pulldn_en_lv[1]
 * 28      vbus_c_pulldn_en_lv[0]
 * 27      intr_cause_vbus_c_done
 * 26      intr_cause_vbus_p_done
 * 25      vbus_c_fx_scan
 * 24      vbus_p_fx_scan
 * 23      ngdo_vbus_p_ddft
 * 22      ngdo_vbus_c_ddft
 * 21      vbus_p_ddft_faults_masked
 * 20      vbus_p_ddft_async_fault_det
 * 19      intr_cause_chgdet_done
 * 18      intr_cause_vsys_done
 * 17      intr_cause_neg_ocp_done
 * 16      intr_cause_neg_uv_done
 * 15      intr_cause_neg_ov_done
 * 14      intr_cause_pos_ocp_done
 * 13      intr_cause_pos_uv_done
 * 12      intr_cause_pos_ov_done
 * 11      vbus_c_ddft_faults_masked
 * 10      vbus_c_ddft_async_fault_det
 * 9       vbus_c_gpio,
 * 8       vbus_p_gpio
 * 7       chgdet_gpio
 * 6       vsys_gpio
 * 5       pos_ocp_gpio
 * 4       neg_ocp_gpio
 * 3       pos_uv_gpio
 * 2       neg_uv_gpio
 * 1       pos_ov_gpio
 * 0       neg_ov_gpio
 */
#define PDSS_GPIO_NCELL_DDFT_MUX_GPIO_NCELL_DDFT0_SEL_MASK    (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_GPIO_NCELL_DDFT_MUX_GPIO_NCELL_DDFT0_SEL_POS    (0UL)


/*
 * In CCG3:
 * 35      vbus_p_en_lv[0]
 * 34      vbus_p_en_lv[1]
 * 33      vbus_p_pulldn_en_lv[0]
 * 32      vbus_p_pulldn_en_lv[1]
 * Else
 * 35      vbus_p_en_lv[1]
 * 34      vbus_p_en_lv[0]
 * 33      vbus_p_pulldn_en_lv[1]
 * 32      vbus_p_pulldn_en_lv[0]
 *
 * 31      vbus_c_en_lv[1]
 * 30      vbus_c_en_lv[0]
 * 29      vbus_c_pulldn_en_lv[1]
 * 28      vbus_c_pulldn_en_lv[0]
 * 27      intr_cause_vbus_c_done
 * 26      intr_cause_vbus_p_done
 * 25      vbus_c_fx_scan
 * 24      vbus_p_fx_scan
 * 23      ngdo_vbus_p_ddft
 * 22      ngdo_vbus_c_ddft
 * 21      vbus_p_ddft_faults_masked
 * 20      vbus_p_ddft_async_fault_det
 * 19      intr_cause_chgdet_done
 * 18      intr_cause_vsys_done
 * 17      intr_cause_neg_ocp_done
 * 16      intr_cause_neg_uv_done
 * 15      intr_cause_neg_ov_done
 * 14      intr_cause_pos_ocp_done
 * 13      intr_cause_pos_uv_done
 * 12      intr_cause_pos_ov_done
 * 11      vbus_c_ddft_faults_masked
 * 10      vbus_c_ddft_async_fault_det
 * 9       vbus_c_gpio,
 * 8       vbus_p_gpio
 * 7       chgdet_gpio
 * 6       vsys_gpio
 * 5       pos_ocp_gpio
 * 4       neg_ocp_gpio
 * 3       pos_uv_gpio
 * 2       neg_uv_gpio
 * 1       pos_ov_gpio
 * 0       neg_ov_gpio
 */
#define PDSS_GPIO_NCELL_DDFT_MUX_GPIO_NCELL_DDFT1_SEL_MASK    (0x00000fc0UL) /* <6:11> R:RW:0: */
#define PDSS_GPIO_NCELL_DDFT_MUX_GPIO_NCELL_DDFT1_SEL_POS    (6UL)


/*
 * Swap Spare coinfiguration 0
 */
#define PDSS_SWAP_CNTRL_0_ADDRESS                           (0x400a0224UL)
#define PDSS_SWAP_CNTRL_0                                   (*(volatile uint32_t *)(0x400a0224UL))
#define PDSS_SWAP_CNTRL_0_DEFAULT                           (0x00000000UL)

/*
 * Controls the CC Charge Pump voltage references
 * 0 - Charge pump voltage is lower
 * 1 - Charge pump voltage is higher
 */
#define PDSS_SWAP_CNTRL_0_CP_REF_SEL                        (1UL << 0) /* <0:0> R:RW:0: */


/*
 * Connects cmp_dn comparator to CC1/CC2
 * 0 - CC1
 * 1 - CC2
 */
#define PDSS_SWAP_CNTRL_0_CMP_FS_CC1V2                      (1UL << 1) /* <1:1> R:RW:0: */


/*
 * Selects the voltage threshold for cmp_fs comparator
 * Notes: 0.52V reference should be used for Fast Swap Detection
 */
#define PDSS_SWAP_CNTRL_0_CMP_FS_VSEL_MASK                  (0x0000001cUL) /* <2:4> R:RW:0: */
#define PDSS_SWAP_CNTRL_0_CMP_FS_VSEL_POS                   (2UL)


/*
 * PDSS SWAP Control registers
 */
#define PDSS_SWAP_CNTRL_0_SWAP_1_MASK                       (0x000000e0UL) /* <5:7> R:RW:0: */
#define PDSS_SWAP_CNTRL_0_SWAP_1_POS                        (5UL)


/*
 * PDSS SWAP Control registers
 */
#define PDSS_SWAP_CNTRL_0_SWAP_2_MASK                       (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_SWAP_CNTRL_0_SWAP_2_POS                        (8UL)


/*
 * PDSS SWAP Control registers
 */
#define PDSS_SWAP_CNTRL_0_SWAP_3_MASK                       (0x00ff0000UL) /* <16:23> R:RW:0: */
#define PDSS_SWAP_CNTRL_0_SWAP_3_POS                        (16UL)


/*
 * PDSS SWAP Control registers
 */
#define PDSS_SWAP_CNTRL_0_SWAP_4_MASK                       (0xff000000UL) /* <24:31> R:RW:0: */
#define PDSS_SWAP_CNTRL_0_SWAP_4_POS                        (24UL)


/*
 * Swap Spare coinfiguration 1
 */
#define PDSS_SWAP_CNTRL_1_ADDRESS                           (0x400a0228UL)
#define PDSS_SWAP_CNTRL_1                                   (*(volatile uint32_t *)(0x400a0228UL))
#define PDSS_SWAP_CNTRL_1_DEFAULT                           (0x00000000UL)

/*
 * PDSS SWAP Control registers
 */
#define PDSS_SWAP_CNTRL_1_SWAP_5_MASK                       (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_SWAP_CNTRL_1_SWAP_5_POS                        (0UL)


/*
 * PDSS SWAP Control registers
 */
#define PDSS_SWAP_CNTRL_1_SWAP_6_MASK                       (0x0000ff00UL) /* <8:15> R:RW:0: */
#define PDSS_SWAP_CNTRL_1_SWAP_6_POS                        (8UL)


/*
 * PDSS SWAP Control registers
 */
#define PDSS_SWAP_CNTRL_1_SWAP_7_MASK                       (0x00ff0000UL) /* <16:23> R:RW:0: */
#define PDSS_SWAP_CNTRL_1_SWAP_7_POS                        (16UL)


/*
 * PDSS SWAP Control registers
 */
#define PDSS_SWAP_CNTRL_1_SWAP_8_MASK                       (0xff000000UL) /* <24:31> R:RW:0: */
#define PDSS_SWAP_CNTRL_1_SWAP_8_POS                        (24UL)


/*
 * S8USBPD C-connector Trim Register0. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_0_ADDRESS                         (0x400aff00UL)
#define PDSS_S8USBPD_TRIM_0                                 (*(volatile uint32_t *)(0x400aff00UL))
#define PDSS_S8USBPD_TRIM_0_DEFAULT                         (0x00000040UL)

/*
 * Trim bits for Driver termination impedance
 */
#define PDSS_S8USBPD_TRIM_0_ZDRV_TRIM_MASK                  (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_S8USBPD_TRIM_0_ZDRV_TRIM_POS                   (0UL)


/*
 * Trim bits for TX Driver rise/fall slew rate
 * For all three usage scenarios (Cable, UFP, DFP), must implement the following
 * S8USBPD_TRIM_0.TX_TRIM settings:
 * For Rp = 3A termination, use TX_TRIM=2
 * For Rp = 1.5A or Default termination, use TX_TRIM=0
 */
#define PDSS_S8USBPD_TRIM_0_TX_TRIM_MASK                    (0x0000000cUL) /* <2:3> R:RW:0: */
#define PDSS_S8USBPD_TRIM_0_TX_TRIM_POS                     (2UL)


/*
 * Trim bits for Rd pull-down resistor
 */
#define PDSS_S8USBPD_TRIM_0_RD_TRIM_MASK                    (0x000000f0UL) /* <4:7> R:RW:4: */
#define PDSS_S8USBPD_TRIM_0_RD_TRIM_POS                     (4UL)


/*
 * S8USBPD C-connector Trim Register1. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_1_ADDRESS                         (0x400aff04UL)
#define PDSS_S8USBPD_TRIM_1                                 (*(volatile uint32_t *)(0x400aff04UL))
#define PDSS_S8USBPD_TRIM_1_DEFAULT                         (0x00000000UL)

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
#define PDSS_S8USBPD_TRIM_1_RP_CC1_TRIM_MASK                (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_S8USBPD_TRIM_1_RP_CC1_TRIM_POS                 (0UL)


/*
 * DeepSleep 2.4uA current reference temperature coefficient trim bits <1:0>
 */
#define PDSS_S8USBPD_TRIM_1_TC_I_TRIM_9P_MASK               (0x000000c0UL) /* <6:7> R:RW:0:DPSLP_REF_EN */
#define PDSS_S8USBPD_TRIM_1_TC_I_TRIM_9P_POS                (6UL)


/*
 * S8USBPD C-connector Trim Register2. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_2_ADDRESS                         (0x400aff08UL)
#define PDSS_S8USBPD_TRIM_2                                 (*(volatile uint32_t *)(0x400aff08UL))
#define PDSS_S8USBPD_TRIM_2_DEFAULT                         (0x00000000UL)

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
#define PDSS_S8USBPD_TRIM_2_RP_CC2_TRIM_MASK                (0x0000003fUL) /* <0:5> R:RW:0: */
#define PDSS_S8USBPD_TRIM_2_RP_CC2_TRIM_POS                 (0UL)


/*
 * Deepsleep 2.4uA current reference temperature coefficient trim bits <3:2>
 */
#define PDSS_S8USBPD_TRIM_2_TC_I_TRIM_4P_MASK               (0x000000c0UL) /* <6:7> R:RW:0:DPSLP_REF_EN */
#define PDSS_S8USBPD_TRIM_2_TC_I_TRIM_4P_POS                (6UL)


/*
 * S8USBPD C-connector Trim Register3. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_3_ADDRESS                         (0x400aff0cUL)
#define PDSS_S8USBPD_TRIM_3                                 (*(volatile uint32_t *)(0x400aff0cUL))
#define PDSS_S8USBPD_TRIM_3_DEFAULT                         (0x00000000UL)

/*
 * Trim bits for 1.63V comparator reference
 * This must be programmed to 0x2. This will set the voltage to 1.71V
 * Notes: This field must be 0x2 for all application (DFP,UFP,AMA ,cable)
 */
#define PDSS_S8USBPD_TRIM_3_V0P55_TRIM_MASK                 (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_S8USBPD_TRIM_3_V0P55_TRIM_POS                  (0UL)


/*
 * Trim bits for 0.655V comparator reference
 */
#define PDSS_S8USBPD_TRIM_3_V0P655_TRIM_MASK                (0x00000038UL) /* <3:5> R:RW:0: */
#define PDSS_S8USBPD_TRIM_3_V0P655_TRIM_POS                 (3UL)


/*
 * S8USBPD C-connector Trim Register4. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_4_ADDRESS                         (0x400aff10UL)
#define PDSS_S8USBPD_TRIM_4                                 (*(volatile uint32_t *)(0x400aff10UL))
#define PDSS_S8USBPD_TRIM_4_DEFAULT                         (0x00000000UL)

/*
 * Trim bits for 0.74V comparator reference
 */
#define PDSS_S8USBPD_TRIM_4_V0P74_TRIM_MASK                 (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_S8USBPD_TRIM_4_V0P74_TRIM_POS                  (0UL)


/*
 * Trim bits for 0.8V comparator reference
 */
#define PDSS_S8USBPD_TRIM_4_V0P8_TRIM_MASK                  (0x00000070UL) /* <4:6> R:RW:0: */
#define PDSS_S8USBPD_TRIM_4_V0P8_TRIM_POS                   (4UL)


/*
 * S8USBPD C-connector Trim Register5. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_5_ADDRESS                         (0x400aff14UL)
#define PDSS_S8USBPD_TRIM_5                                 (*(volatile uint32_t *)(0x400aff14UL))
#define PDSS_S8USBPD_TRIM_5_DEFAULT                         (0x00000004UL)

/*
 * Trim bits for 1.125V comparator reference
 */
#define PDSS_S8USBPD_TRIM_5_V1P125_TRIM_MASK                (0x00000007UL) /* <0:2> R:RW:4: */
#define PDSS_S8USBPD_TRIM_5_V1P125_TRIM_POS                 (0UL)


/*
 * Trim bits for 1.235V comparator reference
 */
#define PDSS_S8USBPD_TRIM_5_V1P235_TRIM_MASK                (0x00000038UL) /* <3:5> R:RW:0: */
#define PDSS_S8USBPD_TRIM_5_V1P235_TRIM_POS                 (3UL)


/*
 * S8USBPD C-connector Trim and Deep Sleep Refgen. Register6. Production
 * trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_6_ADDRESS                         (0x400aff18UL)
#define PDSS_S8USBPD_TRIM_6                                 (*(volatile uint32_t *)(0x400aff18UL))
#define PDSS_S8USBPD_TRIM_6_DEFAULT                         (0x00000000UL)

/*
 * Trim bits for 1.97V comparator reference
 * This must be programmed to 0x3. This will set the voltage to 2.09V.
 * Notes: This field must be 0x3 for all application (DFP,UFP,AMA ,cable)
 */
#define PDSS_S8USBPD_TRIM_6_V1P575_TRIM_MASK                (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_S8USBPD_TRIM_6_V1P575_TRIM_POS                 (0UL)


/*
 * Beta multiplier reference trim bits.
 * Refer to GPM-541 for trim settings.
 */
#define PDSS_S8USBPD_TRIM_6_REF_TRIM_MASK                   (0x00000078UL) /* <3:6> R:RW:0:DPSLP_REF_EN */
#define PDSS_S8USBPD_TRIM_6_REF_TRIM_POS                    (3UL)


/*
 * S8USBPD Deep Sleep Refgen Trim Register7. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_7_ADDRESS                         (0x400aff1cUL)
#define PDSS_S8USBPD_TRIM_7                                 (*(volatile uint32_t *)(0x400aff1cUL))
#define PDSS_S8USBPD_TRIM_7_DEFAULT                         (0x000000f1UL)

/*
 * DeepSleep 2.4uA current reference trim bit.
 * Refer to s8usbpd_ver2 BROS for bit settings.
 */
#define PDSS_S8USBPD_TRIM_7_I_TRIM_MASK                     (0x000000ffUL) /* <0:7> R:RW:241: */
#define PDSS_S8USBPD_TRIM_7_I_TRIM_POS                      (0UL)


/*
 * S8USBPD Spare1 Trim Register
 */
#define PDSS_S8USBPD_TRIM_SPARE1_ADDRESS                    (0x400aff20UL)
#define PDSS_S8USBPD_TRIM_SPARE1                            (*(volatile uint32_t *)(0x400aff20UL))
#define PDSS_S8USBPD_TRIM_SPARE1_DEFAULT                    (0x00000000UL)

/*
 * 20V regulator output voltage trim.  Refer to s8usbpd_ver2 BROS for settings.
 */
#define PDSS_S8USBPD_TRIM_SPARE1_VREG_TRIM_MASK             (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_S8USBPD_TRIM_SPARE1_VREG_TRIM_POS              (0UL)


/*
 * Spare1 Trim
 */
#define PDSS_S8USBPD_TRIM_SPARE1_SPARE1_TRIM_MASK           (0x000000f8UL) /* <3:7> R:RW:0: */
#define PDSS_S8USBPD_TRIM_SPARE1_SPARE1_TRIM_POS            (3UL)


/*
 * S8USBPD Spare2 Trim Register
 */
#define PDSS_S8USBPD_TRIM_SPARE2_ADDRESS                    (0x400aff24UL)
#define PDSS_S8USBPD_TRIM_SPARE2                            (*(volatile uint32_t *)(0x400aff24UL))
#define PDSS_S8USBPD_TRIM_SPARE2_DEFAULT                    (0x00000000UL)

/*
 * Spare2 Trim
 */
#define PDSS_S8USBPD_TRIM_SPARE2_SPARE2_TRIM_MASK           (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_S8USBPD_TRIM_SPARE2_SPARE2_TRIM_POS            (0UL)


/*
 * S8USBPD CSA Trim Register 0. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_CSA_0_ADDRESS                     (0x400aff28UL)
#define PDSS_S8USBPD_TRIM_CSA_0                             (*(volatile uint32_t *)(0x400aff28UL))
#define PDSS_S8USBPD_TRIM_CSA_0_DEFAULT                     (0x00000000UL)

/*
 * Trim control for stage1 input referred offset
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CSA_0_OS_EL_MASK                  (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CSA_0_OS_EL_POS                   (0UL)


/*
 * Trim control for VBUSP detect threshold
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CSA_0_INP_DIV_TR_MASK             (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CSA_0_INP_DIV_TR_POS              (4UL)


/*
 * S8USBPD CSA Trim Register 1. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_CSA_1_ADDRESS                     (0x400aff2cUL)
#define PDSS_S8USBPD_TRIM_CSA_1                             (*(volatile uint32_t *)(0x400aff2cUL))
#define PDSS_S8USBPD_TRIM_CSA_1_DEFAULT                     (0x00000000UL)

/*
 * Trim control for Gain Accuracy
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CSA_1_AV1_TR_MASK                 (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CSA_1_AV1_TR_POS                  (0UL)


/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_S8USBPD_TRIM_CSA_1_SPARE_MASK                  (0x000000f0UL) /* <4:7> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CSA_1_SPARE_POS                   (4UL)


/*
 * S8USBPD CSA Trim Register 2. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_CSA_2_ADDRESS                     (0x400aff30UL)
#define PDSS_S8USBPD_TRIM_CSA_2                             (*(volatile uint32_t *)(0x400aff30UL))
#define PDSS_S8USBPD_TRIM_CSA_2_DEFAULT                     (0x00000000UL)

/*
 * Trim control for the reference votlage generator
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CSA_2_VREF_TR_MASK                (0x0000000fUL) /* <0:3> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CSA_2_VREF_TR_POS                 (0UL)


/*
 * S8USBPD Charger Detect Trim Register 0. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_CHGDET_0_ADDRESS                  (0x400aff34UL)
#define PDSS_S8USBPD_TRIM_CHGDET_0                          (*(volatile uint32_t *)(0x400aff34UL))
#define PDSS_S8USBPD_TRIM_CHGDET_0_DEFAULT                  (0x00000000UL)

/*
 * 0.6V Reference Voltage Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CHGDET_0_V600M_TRIM_MASK          (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CHGDET_0_V600M_TRIM_POS           (0UL)


/*
 * 1.2V Top Side Voltage Reference Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CHGDET_0_V0P74_CHGDET_TRIM_MASK    (0x00000078UL) /* <3:6> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CHGDET_0_V0P74_CHGDET_TRIM_POS    (3UL)


/*
 * S8USBPD Charger Detect Trim Register 1. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_CHGDET_1_ADDRESS                  (0x400aff38UL)
#define PDSS_S8USBPD_TRIM_CHGDET_1                          (*(volatile uint32_t *)(0x400aff38UL))
#define PDSS_S8USBPD_TRIM_CHGDET_1_DEFAULT                  (0x00000000UL)

/*
 * 0.325V Reference Voltage Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CHGDET_1_V325M_TRIM_MASK          (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CHGDET_1_V325M_TRIM_POS           (0UL)


/*
 * 2.0V Reference Voltage Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CHGDET_1_V2V_TRIM_MASK            (0x0000000cUL) /* <2:3> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CHGDET_1_V2V_TRIM_POS             (2UL)


/*
 * 1.4V Reference Voltage Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CHGDET_1_VAPP_TRIM_MASK           (0x00000070UL) /* <4:6> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CHGDET_1_VAPP_TRIM_POS            (4UL)


/*
 * S8USBPD Charger Detect Trim Register 2. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_CHGDET_2_ADDRESS                  (0x400aff3cUL)
#define PDSS_S8USBPD_TRIM_CHGDET_2                          (*(volatile uint32_t *)(0x400aff3cUL))
#define PDSS_S8USBPD_TRIM_CHGDET_2_DEFAULT                  (0x00000000UL)

/*
 * 0.325V Reference Voltage Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CHGDET_2_V850M_TRIM_MASK          (0x00000003UL) /* <0:1> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CHGDET_2_V850M_TRIM_POS           (0UL)


/*
 * 2.2V Reference Voltage Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CHGDET_2_V2P2V_TRIM_MASK          (0x0000000cUL) /* <2:3> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CHGDET_2_V2P2V_TRIM_POS           (2UL)


/*
 * 2.9V Reference Voltage Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CHGDET_2_V2P9V_TRIM_MASK          (0x00000030UL) /* <4:5> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CHGDET_2_V2P9V_TRIM_POS           (4UL)


/*
 * 2.5V Reference Voltage Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 */
#define PDSS_S8USBPD_TRIM_CHGDET_2_V2P5V_TRIM_MASK          (0x000000c0UL) /* <6:7> R:RW:0: */
#define PDSS_S8USBPD_TRIM_CHGDET_2_V2P5V_TRIM_POS           (6UL)


/*
 * S8USBPD SBU 0 Trim Register. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_SBU_0_ADDRESS                     (0x400aff40UL)
#define PDSS_S8USBPD_TRIM_SBU_0                             (*(volatile uint32_t *)(0x400aff40UL))
#define PDSS_S8USBPD_TRIM_SBU_0_DEFAULT                     (0x00000000UL)

/*
 * 1 MOhm Resistor Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 * This should be trimmed at sort, or set to 2 for default
 */
#define PDSS_S8USBPD_TRIM_SBU_0_SBU_1MEG_TRIM_MASK          (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_S8USBPD_TRIM_SBU_0_SBU_1MEG_TRIM_POS           (0UL)


/*
 * 100 kOhm Resistor Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 * This should be trimmed at sort, or set to 2 for default
 */
#define PDSS_S8USBPD_TRIM_SBU_0_SBU_100K_TRIM_MASK          (0x00000038UL) /* <3:5> R:RW:0: */
#define PDSS_S8USBPD_TRIM_SBU_0_SBU_100K_TRIM_POS           (3UL)


/*
 * S8USBPD SBU 1 Trim Register. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_SBU_1_ADDRESS                     (0x400aff44UL)
#define PDSS_S8USBPD_TRIM_SBU_1                             (*(volatile uint32_t *)(0x400aff44UL))
#define PDSS_S8USBPD_TRIM_SBU_1_DEFAULT                     (0x00000000UL)

/*
 * 470 kOhm Resistor Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 * This should be trimmed at sort, or set to 2 for default
 */
#define PDSS_S8USBPD_TRIM_SBU_1_SBU_470K_PD_TRIM_MASK       (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_S8USBPD_TRIM_SBU_1_SBU_470K_PD_TRIM_POS        (0UL)


/*
 * S8USBPD SBU 2 Trim Register. Production trims stored in flash
 */
#define PDSS_S8USBPD_TRIM_SBU_2_ADDRESS                     (0x400aff48UL)
#define PDSS_S8USBPD_TRIM_SBU_2                             (*(volatile uint32_t *)(0x400aff48UL))
#define PDSS_S8USBPD_TRIM_SBU_2_DEFAULT                     (0x00000000UL)

/*
 * 4.7 MOhm Resistor Trim
 * Refer to the s8usbpd_ver2 BROS for more details
 * This should be trimmed at sort, or set to 2 for default
 */
#define PDSS_S8USBPD_TRIM_SBU_2_SBU_4P7MEG_PD_TRIM_MASK     (0x00000007UL) /* <0:2> R:RW:0: */
#define PDSS_S8USBPD_TRIM_SBU_2_SBU_4P7MEG_PD_TRIM_POS      (0UL)


/*
 * S8USBPD Spare3
 */
#define PDSS_S8USBPD_TRIM_SPARE3_ADDRESS                    (0x400aff4cUL)
#define PDSS_S8USBPD_TRIM_SPARE3                            (*(volatile uint32_t *)(0x400aff4cUL))
#define PDSS_S8USBPD_TRIM_SPARE3_DEFAULT                    (0x00000000UL)

/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_S8USBPD_TRIM_SPARE3_SPARE3_TRIM_MASK           (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_S8USBPD_TRIM_SPARE3_SPARE3_TRIM_POS            (0UL)


/*
 * S8USBPD Spare4
 */
#define PDSS_S8USBPD_TRIM_SPARE4_ADDRESS                    (0x400aff50UL)
#define PDSS_S8USBPD_TRIM_SPARE4                            (*(volatile uint32_t *)(0x400aff50UL))
#define PDSS_S8USBPD_TRIM_SPARE4_DEFAULT                    (0x00000000UL)

/*
 * RESERVED FOR FUTURE USE
 */
#define PDSS_S8USBPD_TRIM_SPARE4_SPARE4_TRIM_MASK           (0x000000ffUL) /* <0:7> R:RW:0: */
#define PDSS_S8USBPD_TRIM_SPARE4_SPARE4_TRIM_POS            (0UL)


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
#define ROMTABLE_DID_VALUE_POS                              (0)


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

#endif /* _CY_USBPD_PMG1S2_REGS_H_ */

