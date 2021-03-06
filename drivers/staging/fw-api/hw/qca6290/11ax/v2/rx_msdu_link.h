/*
 * Copyright (c) 2016-2018 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _RX_MSDU_LINK_H_
#define _RX_MSDU_LINK_H_
#if !defined(__ASSEMBLER__)
#endif

#include "uniform_descriptor_header.h"
#include "buffer_addr_info.h"
#include "rx_msdu_details.h"

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	struct uniform_descriptor_header descriptor_header;
//	1-2	struct buffer_addr_info next_msdu_link_desc_addr_info;
//	3	receive_queue_number[15:0], first_rx_msdu_link_struct[16], reserved_3a[31:17]
//	4	pn_31_0[31:0]
//	5	pn_63_32[31:0]
//	6	pn_95_64[31:0]
//	7	pn_127_96[31:0]
//	8-11	struct rx_msdu_details msdu_0;
//	12-15	struct rx_msdu_details msdu_1;
//	16-19	struct rx_msdu_details msdu_2;
//	20-23	struct rx_msdu_details msdu_3;
//	24-27	struct rx_msdu_details msdu_4;
//	28-31	struct rx_msdu_details msdu_5;
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_RX_MSDU_LINK 32

struct rx_msdu_link {
    struct            uniform_descriptor_header                       descriptor_header;
    struct            buffer_addr_info                       next_msdu_link_desc_addr_info;
             uint32_t receive_queue_number            : 16, //[15:0]
                      first_rx_msdu_link_struct       :  1, //[16]
                      reserved_3a                     : 15; //[31:17]
             uint32_t pn_31_0                         : 32; //[31:0]
             uint32_t pn_63_32                        : 32; //[31:0]
             uint32_t pn_95_64                        : 32; //[31:0]
             uint32_t pn_127_96                       : 32; //[31:0]
    struct            rx_msdu_details                       msdu_0;
    struct            rx_msdu_details                       msdu_1;
    struct            rx_msdu_details                       msdu_2;
    struct            rx_msdu_details                       msdu_3;
    struct            rx_msdu_details                       msdu_4;
    struct            rx_msdu_details                       msdu_5;
};

/*

struct uniform_descriptor_header descriptor_header
			
			Details about which module owns this struct.
			
			Note that sub field Buffer_type shall be set to
			Receive_MSDU_Link_descriptor

struct buffer_addr_info next_msdu_link_desc_addr_info
			
			Details of the physical address of the next MSDU link
			descriptor that contains info about additional MSDUs that
			are part of this MPDU.

receive_queue_number
			
			Indicates the Receive queue to which this MPDU
			descriptor belongs
			
			Used for tracking, finding bugs and debugging.
			
			<legal all>

first_rx_msdu_link_struct
			
			When set, this RX_MSDU_link descriptor is the first one
			in the MSDU link list. Field MSDU_0 points to the very first
			MSDU buffer descriptor in the MPDU
			
			<legal all>

reserved_3a
			
			<legal 0>

pn_31_0
			
			
			
			
			31-0 bits of the 256-bit packet number bitmap.  
			
			<legal all>

pn_63_32
			
			
			
			
			63-32 bits of the 256-bit packet number bitmap.  
			
			<legal all>

pn_95_64
			
			
			
			
			95-64 bits of the 256-bit packet number bitmap. 
			
			<legal all>

pn_127_96
			
			
			
			
			127-96 bits of the 256-bit packet number bitmap. 
			
			<legal all>

struct rx_msdu_details msdu_0
			
			When First_RX_MSDU_link_struct  is set, this MSDU is the
			first in the MPDU
			
			
			
			When First_RX_MSDU_link_struct  is NOT set, this MSDU
			follows the last MSDU in the previous RX_MSDU_link data
			structure

struct rx_msdu_details msdu_1
			
			Details of next MSDU in this (MSDU flow) linked list

struct rx_msdu_details msdu_2
			
			Details of next MSDU in this (MSDU flow) linked list

struct rx_msdu_details msdu_3
			
			Details of next MSDU in this (MSDU flow) linked list

struct rx_msdu_details msdu_4
			
			Details of next MSDU in this (MSDU flow) linked list

struct rx_msdu_details msdu_5
			
			Details of next MSDU in this (MSDU flow) linked list
*/

#define RX_MSDU_LINK_0_UNIFORM_DESCRIPTOR_HEADER_DESCRIPTOR_HEADER_OFFSET 0x00000000
#define RX_MSDU_LINK_0_UNIFORM_DESCRIPTOR_HEADER_DESCRIPTOR_HEADER_LSB 0
#define RX_MSDU_LINK_0_UNIFORM_DESCRIPTOR_HEADER_DESCRIPTOR_HEADER_MASK 0xffffffff
#define RX_MSDU_LINK_1_BUFFER_ADDR_INFO_NEXT_MSDU_LINK_DESC_ADDR_INFO_OFFSET 0x00000004
#define RX_MSDU_LINK_1_BUFFER_ADDR_INFO_NEXT_MSDU_LINK_DESC_ADDR_INFO_LSB 0
#define RX_MSDU_LINK_1_BUFFER_ADDR_INFO_NEXT_MSDU_LINK_DESC_ADDR_INFO_MASK 0xffffffff
#define RX_MSDU_LINK_2_BUFFER_ADDR_INFO_NEXT_MSDU_LINK_DESC_ADDR_INFO_OFFSET 0x00000008
#define RX_MSDU_LINK_2_BUFFER_ADDR_INFO_NEXT_MSDU_LINK_DESC_ADDR_INFO_LSB 0
#define RX_MSDU_LINK_2_BUFFER_ADDR_INFO_NEXT_MSDU_LINK_DESC_ADDR_INFO_MASK 0xffffffff

/* Description		RX_MSDU_LINK_3_RECEIVE_QUEUE_NUMBER
			
			Indicates the Receive queue to which this MPDU
			descriptor belongs
			
			Used for tracking, finding bugs and debugging.
			
			<legal all>
*/
#define RX_MSDU_LINK_3_RECEIVE_QUEUE_NUMBER_OFFSET                   0x0000000c
#define RX_MSDU_LINK_3_RECEIVE_QUEUE_NUMBER_LSB                      0
#define RX_MSDU_LINK_3_RECEIVE_QUEUE_NUMBER_MASK                     0x0000ffff

/* Description		RX_MSDU_LINK_3_FIRST_RX_MSDU_LINK_STRUCT
			
			When set, this RX_MSDU_link descriptor is the first one
			in the MSDU link list. Field MSDU_0 points to the very first
			MSDU buffer descriptor in the MPDU
			
			<legal all>
*/
#define RX_MSDU_LINK_3_FIRST_RX_MSDU_LINK_STRUCT_OFFSET              0x0000000c
#define RX_MSDU_LINK_3_FIRST_RX_MSDU_LINK_STRUCT_LSB                 16
#define RX_MSDU_LINK_3_FIRST_RX_MSDU_LINK_STRUCT_MASK                0x00010000

/* Description		RX_MSDU_LINK_3_RESERVED_3A
			
			<legal 0>
*/
#define RX_MSDU_LINK_3_RESERVED_3A_OFFSET                            0x0000000c
#define RX_MSDU_LINK_3_RESERVED_3A_LSB                               17
#define RX_MSDU_LINK_3_RESERVED_3A_MASK                              0xfffe0000

/* Description		RX_MSDU_LINK_4_PN_31_0
			
			
			
			
			31-0 bits of the 256-bit packet number bitmap.  
			
			<legal all>
*/
#define RX_MSDU_LINK_4_PN_31_0_OFFSET                                0x00000010
#define RX_MSDU_LINK_4_PN_31_0_LSB                                   0
#define RX_MSDU_LINK_4_PN_31_0_MASK                                  0xffffffff

/* Description		RX_MSDU_LINK_5_PN_63_32
			
			
			
			
			63-32 bits of the 256-bit packet number bitmap.  
			
			<legal all>
*/
#define RX_MSDU_LINK_5_PN_63_32_OFFSET                               0x00000014
#define RX_MSDU_LINK_5_PN_63_32_LSB                                  0
#define RX_MSDU_LINK_5_PN_63_32_MASK                                 0xffffffff

/* Description		RX_MSDU_LINK_6_PN_95_64
			
			
			
			
			95-64 bits of the 256-bit packet number bitmap. 
			
			<legal all>
*/
#define RX_MSDU_LINK_6_PN_95_64_OFFSET                               0x00000018
#define RX_MSDU_LINK_6_PN_95_64_LSB                                  0
#define RX_MSDU_LINK_6_PN_95_64_MASK                                 0xffffffff

/* Description		RX_MSDU_LINK_7_PN_127_96
			
			
			
			
			127-96 bits of the 256-bit packet number bitmap. 
			
			<legal all>
*/
#define RX_MSDU_LINK_7_PN_127_96_OFFSET                              0x0000001c
#define RX_MSDU_LINK_7_PN_127_96_LSB                                 0
#define RX_MSDU_LINK_7_PN_127_96_MASK                                0xffffffff
#define RX_MSDU_LINK_8_RX_MSDU_DETAILS_MSDU_0_OFFSET                 0x00000020
#define RX_MSDU_LINK_8_RX_MSDU_DETAILS_MSDU_0_LSB                    0
#define RX_MSDU_LINK_8_RX_MSDU_DETAILS_MSDU_0_MASK                   0xffffffff
#define RX_MSDU_LINK_9_RX_MSDU_DETAILS_MSDU_0_OFFSET                 0x00000024
#define RX_MSDU_LINK_9_RX_MSDU_DETAILS_MSDU_0_LSB                    0
#define RX_MSDU_LINK_9_RX_MSDU_DETAILS_MSDU_0_MASK                   0xffffffff
#define RX_MSDU_LINK_10_RX_MSDU_DETAILS_MSDU_0_OFFSET                0x00000028
#define RX_MSDU_LINK_10_RX_MSDU_DETAILS_MSDU_0_LSB                   0
#define RX_MSDU_LINK_10_RX_MSDU_DETAILS_MSDU_0_MASK                  0xffffffff
#define RX_MSDU_LINK_11_RX_MSDU_DETAILS_MSDU_0_OFFSET                0x0000002c
#define RX_MSDU_LINK_11_RX_MSDU_DETAILS_MSDU_0_LSB                   0
#define RX_MSDU_LINK_11_RX_MSDU_DETAILS_MSDU_0_MASK                  0xffffffff
#define RX_MSDU_LINK_12_RX_MSDU_DETAILS_MSDU_1_OFFSET                0x00000030
#define RX_MSDU_LINK_12_RX_MSDU_DETAILS_MSDU_1_LSB                   0
#define RX_MSDU_LINK_12_RX_MSDU_DETAILS_MSDU_1_MASK                  0xffffffff
#define RX_MSDU_LINK_13_RX_MSDU_DETAILS_MSDU_1_OFFSET                0x00000034
#define RX_MSDU_LINK_13_RX_MSDU_DETAILS_MSDU_1_LSB                   0
#define RX_MSDU_LINK_13_RX_MSDU_DETAILS_MSDU_1_MASK                  0xffffffff
#define RX_MSDU_LINK_14_RX_MSDU_DETAILS_MSDU_1_OFFSET                0x00000038
#define RX_MSDU_LINK_14_RX_MSDU_DETAILS_MSDU_1_LSB                   0
#define RX_MSDU_LINK_14_RX_MSDU_DETAILS_MSDU_1_MASK                  0xffffffff
#define RX_MSDU_LINK_15_RX_MSDU_DETAILS_MSDU_1_OFFSET                0x0000003c
#define RX_MSDU_LINK_15_RX_MSDU_DETAILS_MSDU_1_LSB                   0
#define RX_MSDU_LINK_15_RX_MSDU_DETAILS_MSDU_1_MASK                  0xffffffff
#define RX_MSDU_LINK_16_RX_MSDU_DETAILS_MSDU_2_OFFSET                0x00000040
#define RX_MSDU_LINK_16_RX_MSDU_DETAILS_MSDU_2_LSB                   0
#define RX_MSDU_LINK_16_RX_MSDU_DETAILS_MSDU_2_MASK                  0xffffffff
#define RX_MSDU_LINK_17_RX_MSDU_DETAILS_MSDU_2_OFFSET                0x00000044
#define RX_MSDU_LINK_17_RX_MSDU_DETAILS_MSDU_2_LSB                   0
#define RX_MSDU_LINK_17_RX_MSDU_DETAILS_MSDU_2_MASK                  0xffffffff
#define RX_MSDU_LINK_18_RX_MSDU_DETAILS_MSDU_2_OFFSET                0x00000048
#define RX_MSDU_LINK_18_RX_MSDU_DETAILS_MSDU_2_LSB                   0
#define RX_MSDU_LINK_18_RX_MSDU_DETAILS_MSDU_2_MASK                  0xffffffff
#define RX_MSDU_LINK_19_RX_MSDU_DETAILS_MSDU_2_OFFSET                0x0000004c
#define RX_MSDU_LINK_19_RX_MSDU_DETAILS_MSDU_2_LSB                   0
#define RX_MSDU_LINK_19_RX_MSDU_DETAILS_MSDU_2_MASK                  0xffffffff
#define RX_MSDU_LINK_20_RX_MSDU_DETAILS_MSDU_3_OFFSET                0x00000050
#define RX_MSDU_LINK_20_RX_MSDU_DETAILS_MSDU_3_LSB                   0
#define RX_MSDU_LINK_20_RX_MSDU_DETAILS_MSDU_3_MASK                  0xffffffff
#define RX_MSDU_LINK_21_RX_MSDU_DETAILS_MSDU_3_OFFSET                0x00000054
#define RX_MSDU_LINK_21_RX_MSDU_DETAILS_MSDU_3_LSB                   0
#define RX_MSDU_LINK_21_RX_MSDU_DETAILS_MSDU_3_MASK                  0xffffffff
#define RX_MSDU_LINK_22_RX_MSDU_DETAILS_MSDU_3_OFFSET                0x00000058
#define RX_MSDU_LINK_22_RX_MSDU_DETAILS_MSDU_3_LSB                   0
#define RX_MSDU_LINK_22_RX_MSDU_DETAILS_MSDU_3_MASK                  0xffffffff
#define RX_MSDU_LINK_23_RX_MSDU_DETAILS_MSDU_3_OFFSET                0x0000005c
#define RX_MSDU_LINK_23_RX_MSDU_DETAILS_MSDU_3_LSB                   0
#define RX_MSDU_LINK_23_RX_MSDU_DETAILS_MSDU_3_MASK                  0xffffffff
#define RX_MSDU_LINK_24_RX_MSDU_DETAILS_MSDU_4_OFFSET                0x00000060
#define RX_MSDU_LINK_24_RX_MSDU_DETAILS_MSDU_4_LSB                   0
#define RX_MSDU_LINK_24_RX_MSDU_DETAILS_MSDU_4_MASK                  0xffffffff
#define RX_MSDU_LINK_25_RX_MSDU_DETAILS_MSDU_4_OFFSET                0x00000064
#define RX_MSDU_LINK_25_RX_MSDU_DETAILS_MSDU_4_LSB                   0
#define RX_MSDU_LINK_25_RX_MSDU_DETAILS_MSDU_4_MASK                  0xffffffff
#define RX_MSDU_LINK_26_RX_MSDU_DETAILS_MSDU_4_OFFSET                0x00000068
#define RX_MSDU_LINK_26_RX_MSDU_DETAILS_MSDU_4_LSB                   0
#define RX_MSDU_LINK_26_RX_MSDU_DETAILS_MSDU_4_MASK                  0xffffffff
#define RX_MSDU_LINK_27_RX_MSDU_DETAILS_MSDU_4_OFFSET                0x0000006c
#define RX_MSDU_LINK_27_RX_MSDU_DETAILS_MSDU_4_LSB                   0
#define RX_MSDU_LINK_27_RX_MSDU_DETAILS_MSDU_4_MASK                  0xffffffff
#define RX_MSDU_LINK_28_RX_MSDU_DETAILS_MSDU_5_OFFSET                0x00000070
#define RX_MSDU_LINK_28_RX_MSDU_DETAILS_MSDU_5_LSB                   0
#define RX_MSDU_LINK_28_RX_MSDU_DETAILS_MSDU_5_MASK                  0xffffffff
#define RX_MSDU_LINK_29_RX_MSDU_DETAILS_MSDU_5_OFFSET                0x00000074
#define RX_MSDU_LINK_29_RX_MSDU_DETAILS_MSDU_5_LSB                   0
#define RX_MSDU_LINK_29_RX_MSDU_DETAILS_MSDU_5_MASK                  0xffffffff
#define RX_MSDU_LINK_30_RX_MSDU_DETAILS_MSDU_5_OFFSET                0x00000078
#define RX_MSDU_LINK_30_RX_MSDU_DETAILS_MSDU_5_LSB                   0
#define RX_MSDU_LINK_30_RX_MSDU_DETAILS_MSDU_5_MASK                  0xffffffff
#define RX_MSDU_LINK_31_RX_MSDU_DETAILS_MSDU_5_OFFSET                0x0000007c
#define RX_MSDU_LINK_31_RX_MSDU_DETAILS_MSDU_5_LSB                   0
#define RX_MSDU_LINK_31_RX_MSDU_DETAILS_MSDU_5_MASK                  0xffffffff


#endif // _RX_MSDU_LINK_H_
