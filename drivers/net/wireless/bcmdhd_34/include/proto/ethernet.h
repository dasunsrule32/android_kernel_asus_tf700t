/*
 * From FreeBSD 2.2.7: Fundamental constants relating to ethernet.
 *
 * $Copyright Open Broadcom Corporation$
 *
 * $Id: ethernet.h 309193 2012-01-19 00:03:57Z $
 */

#ifndef _NET_ETHERNET_H_	      
#define _NET_ETHERNET_H_

#ifndef _TYPEDEFS_H_
#include "typedefs.h"
#endif


#include <packed_section_start.h>



#define	ETHER_ADDR_LEN		6


#define	ETHER_TYPE_LEN		2


#define	ETHER_CRC_LEN		4


#define	ETHER_HDR_LEN		(ETHER_ADDR_LEN * 2 + ETHER_TYPE_LEN)


#define	ETHER_MIN_LEN		64


#define	ETHER_MIN_DATA		46


#define	ETHER_MAX_LEN		1518


#define	ETHER_MAX_DATA		1500


#define ETHER_TYPE_MIN		0x0600		
#define	ETHER_TYPE_IP		0x0800		
#define ETHER_TYPE_ARP		0x0806		
#define ETHER_TYPE_8021Q	0x8100		
#define	ETHER_TYPE_IPV6		0x86dd		
#define	ETHER_TYPE_BRCM		0x886c		
#define	ETHER_TYPE_802_1X	0x888e		
#define	ETHER_TYPE_802_1X_PREAUTH 0x88c7	
#define ETHER_TYPE_WAI		0x88b4		
#define ETHER_TYPE_89_0D	0x890d		

#define ETHER_TYPE_IPV6		0x86dd		


#define	ETHER_BRCM_SUBTYPE_LEN	4	


#define ETHER_DEST_OFFSET	(0 * ETHER_ADDR_LEN)	
#define ETHER_SRC_OFFSET	(1 * ETHER_ADDR_LEN)	
#define ETHER_TYPE_OFFSET	(2 * ETHER_ADDR_LEN)	


#define	ETHER_IS_VALID_LEN(foo)	\
	((foo) >= ETHER_MIN_LEN && (foo) <= ETHER_MAX_LEN)

#define ETHER_FILL_MCAST_ADDR_FROM_IP(ea, mgrp_ip) {		\
		((uint8 *)ea)[0] = 0x01;			\
		((uint8 *)ea)[1] = 0x00;			\
		((uint8 *)ea)[2] = 0x5e;			\
		((uint8 *)ea)[3] = ((mgrp_ip) >> 16) & 0x7f;	\
		((uint8 *)ea)[4] = ((mgrp_ip) >>  8) & 0xff;	\
		((uint8 *)ea)[5] = ((mgrp_ip) >>  0) & 0xff;	\
}

#ifndef __INCif_etherh       

BWL_PRE_PACKED_STRUCT struct ether_header {
	uint8	ether_dhost[ETHER_ADDR_LEN];
	uint8	ether_shost[ETHER_ADDR_LEN];
	uint16	ether_type;
} BWL_POST_PACKED_STRUCT;


BWL_PRE_PACKED_STRUCT struct	ether_addr {
	uint8 octet[ETHER_ADDR_LEN];
} BWL_POST_PACKED_STRUCT;
#endif	


#define ETHER_SET_LOCALADDR(ea)	(((uint8 *)(ea))[0] = (((uint8 *)(ea))[0] | 2))
#define ETHER_IS_LOCALADDR(ea) 	(((uint8 *)(ea))[0] & 2)
#define ETHER_CLR_LOCALADDR(ea)	(((uint8 *)(ea))[0] = (((uint8 *)(ea))[0] & 0xfd))
#define ETHER_TOGGLE_LOCALADDR(ea)	(((uint8 *)(ea))[0] = (((uint8 *)(ea))[0] ^ 2))


#define ETHER_SET_UNICAST(ea)	(((uint8 *)(ea))[0] = (((uint8 *)(ea))[0] & ~1))


#define ETHER_ISMULTI(ea) (((const uint8 *)(ea))[0] & 1)



#define	ether_cmp(a, b)	(!(((short*)(a))[0] == ((short*)(b))[0]) | \
			 !(((short*)(a))[1] == ((short*)(b))[1]) | \
			 !(((short*)(a))[2] == ((short*)(b))[2]))


#define	ether_copy(s, d) { \
		((short*)(d))[0] = ((const short*)(s))[0]; \
		((short*)(d))[1] = ((const short*)(s))[1]; \
		((short*)(d))[2] = ((const short*)(s))[2]; }


static const struct ether_addr ether_bcast = {{255, 255, 255, 255, 255, 255}};
static const struct ether_addr ether_null = {{0, 0, 0, 0, 0, 0}};

#define ETHER_ISBCAST(ea)	((((uint8 *)(ea))[0] &		\
	                          ((uint8 *)(ea))[1] &		\
				  ((uint8 *)(ea))[2] &		\
				  ((uint8 *)(ea))[3] &		\
				  ((uint8 *)(ea))[4] &		\
				  ((uint8 *)(ea))[5]) == 0xff)
#define ETHER_ISNULLADDR(ea)	((((uint8 *)(ea))[0] |		\
				  ((uint8 *)(ea))[1] |		\
				  ((uint8 *)(ea))[2] |		\
				  ((uint8 *)(ea))[3] |		\
				  ((uint8 *)(ea))[4] |		\
				  ((uint8 *)(ea))[5]) == 0)

#define ETHER_MOVE_HDR(d, s) \
do { \
	struct ether_header t; \
	t = *(struct ether_header *)(s); \
	*(struct ether_header *)(d) = t; \
} while (0)


#include <packed_section_end.h>

#endif 
