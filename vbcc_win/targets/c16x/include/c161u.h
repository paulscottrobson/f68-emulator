/*
 * Copyright (c) 2004 Christiaan Simons <cc_simons@yahoo.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifndef C161U_H
#define C161U_H
/*
 v0.3 23/09/04 

 Hardware register acces for the Infineon c161u (USB) microcontroller. 
 These declarations are to be used with the vbcc(c16x) compiler.
*/

#define EPECCLC (*((volatile unsigned int*)0xED00))
#define EPECID (*((volatile unsigned int*)0xED08))
#define EPEC_SPTR_IN_R00 (*((volatile unsigned int*)0xED10))
#define EPEC_SPTR_IN_R01 (*((volatile unsigned int*)0xED12))
#define EPEC_SPTR_OUT_R00 (*((volatile unsigned int*)0xED14))
#define EPEC_SPTR_OUT_R01 (*((volatile unsigned int*)0xED16))
#define EPEC_SPTR_REG10 (*((volatile unsigned int*)0xED18))
#define EPEC_SPTR_REG11 (*((volatile unsigned int*)0xED1A))
#define EPEC_SPTR_REG20 (*((volatile unsigned int*)0xED1C))
#define EPEC_SPTR_REG21 (*((volatile unsigned int*)0xED1E))
#define EPEC_SPTR_REG30 (*((volatile unsigned int*)0xED20))
#define EPEC_SPTR_REG31 (*((volatile unsigned int*)0xED22))
#define EPEC_SPTR_REG40 (*((volatile unsigned int*)0xED24))
#define EPEC_SPTR_REG41 (*((volatile unsigned int*)0xED26))
#define EPEC_SPTR_REG50 (*((volatile unsigned int*)0xED28))
#define EPEC_SPTR_REG51 (*((volatile unsigned int*)0xED2A))
#define EPEC_SPTR_REG60 (*((volatile unsigned int*)0xED2C))
#define EPEC_SPTR_REG61 (*((volatile unsigned int*)0xED2E))
#define EPEC_SPTR_REG70 (*((volatile unsigned int*)0xED30))
#define EPEC_SPTR_REG71 (*((volatile unsigned int*)0xED32))
#define EPEC_DPTR_IN_R00 (*((volatile unsigned int*)0xED34))
#define EPEC_DPTR_IN_R01 (*((volatile unsigned int*)0xED36))
#define EPEC_DPTR_OUT_R00 (*((volatile unsigned int*)0xED38))
#define EPEC_DPTR_OUT_R01 (*((volatile unsigned int*)0xED3A))
#define EPEC_DPTR_REG10 (*((volatile unsigned int*)0xED3C))
#define EPEC_DPTR_REG11 (*((volatile unsigned int*)0xED3E))
#define EPEC_DPTR_REG20 (*((volatile unsigned int*)0xED40))
#define EPEC_DPTR_REG21 (*((volatile unsigned int*)0xED42))
#define EPEC_DPTR_REG30 (*((volatile unsigned int*)0xED44))
#define EPEC_DPTR_REG31 (*((volatile unsigned int*)0xED46))
#define EPEC_DPTR_REG40 (*((volatile unsigned int*)0xED48))
#define EPEC_DPTR_REG41 (*((volatile unsigned int*)0xED4A))
#define EPEC_DPTR_REG50 (*((volatile unsigned int*)0xED4C))
#define EPEC_DPTR_REG51 (*((volatile unsigned int*)0xED4E))
#define EPEC_DPTR_REG60 (*((volatile unsigned int*)0xED50))
#define EPEC_DPTR_REG61 (*((volatile unsigned int*)0xED52))
#define EPEC_DPTR_REG70 (*((volatile unsigned int*)0xED54))
#define EPEC_DPTR_REG71 (*((volatile unsigned int*)0xED56))
#define EPEC_CTRL_IN_R0 (*((volatile unsigned int*)0xED58))
#define EPEC_CTRL_OUT_R0 (*((volatile unsigned int*)0xED5A))
#define EPEC_CTRL_REG1 (*((volatile unsigned int*)0xED5C))
#define EPEC_CTRL_REG2 (*((volatile unsigned int*)0xED5E))
#define EPEC_CTRL_REG3 (*((volatile unsigned int*)0xED60))
#define EPEC_CTRL_REG4 (*((volatile unsigned int*)0xED62))
#define EPEC_CTRL_REG5 (*((volatile unsigned int*)0xED64))
#define EPEC_CTRL_REG6 (*((volatile unsigned int*)0xED66))
#define EPEC_CTRL_REG7 (*((volatile unsigned int*)0xED68))
#define EPEC_INT_REG (*((volatile unsigned int*)0xED6A))
#define EPEC_INTMSK_REG (*((volatile unsigned int*)0xED6C))
#define USBCLC (*((volatile unsigned int*)0xEE00))
#define USBD_ID (*((volatile unsigned int*)0xEE08))
#define USBD_CMD_REG (*((volatile unsigned int*)0xEE10))
#define USBD_STATUS_REG0 (*((volatile unsigned int*)0xEE12))
#define USBD_STATUS_REG1 (*((volatile unsigned int*)0xEE14))
#define USBD_STATUS_REG2 (*((volatile unsigned int*)0xEE16))
#define USBD_TIME_REG (*((volatile unsigned int*)0xEE24))
#define USBD_SETUP_REG01 (*((volatile unsigned int*)0xEE26))
#define USBD_SETUP_REG23 (*((volatile unsigned int*)0xEE28))
#define USBD_SETUP_REG45 (*((volatile unsigned int*)0xEE2A))
#define USBD_SETUP_REG67 (*((volatile unsigned int*)0xEE2C))
#define USBD_TXWR0 (*((volatile unsigned int*)0xEE2E))
#define USBD_TXEOD0 (*((volatile unsigned int*)0xEE30))
#define USBD_RXRR0 (*((volatile unsigned int*)0xEE32))
#define USBD_RX_BYTECNT0 (*((volatile unsigned int*)0xEE34))
#define USBD_TXWR1 (*((volatile unsigned int*)0xEE36))
#define USBD_TXEOD1 (*((volatile unsigned int*)0xEE38))
#define USBD_RXRR1 (*((volatile unsigned int*)0xEE3A))
#define USBD_RX_BYTECNT1 (*((volatile unsigned int*)0xEE3C))
#define USBD_TXWR2 (*((volatile unsigned int*)0xEE3E))
#define USBD_TXEOD2 (*((volatile unsigned int*)0xEE40))
#define USBD_RXRR2 (*((volatile unsigned int*)0xEE42))
#define USBD_RX_BYTECNT2 (*((volatile unsigned int*)0xEE44))
#define USBD_TXWR3 (*((volatile unsigned int*)0xEE46))
#define USBD_TXEOD3 (*((volatile unsigned int*)0xEE48))
#define USBD_RXRR3 (*((volatile unsigned int*)0xEE4A))
#define USBD_RX_BYTECNT3 (*((volatile unsigned int*)0xEE4C))
#define USBD_TXWR4 (*((volatile unsigned int*)0xEE4E))
#define USBD_TXEOD4 (*((volatile unsigned int*)0xEE50))
#define USBD_RXRR4 (*((volatile unsigned int*)0xEE52))
#define USBD_RX_BYTECNT4 (*((volatile unsigned int*)0xEE54))
#define USBD_TXWR5 (*((volatile unsigned int*)0xEE56))
#define USBD_TXEOD5 (*((volatile unsigned int*)0xEE58))
#define USBD_RXRR5 (*((volatile unsigned int*)0xEE5A))
#define USBD_RX_BYTECNT5 (*((volatile unsigned int*)0xEE5C))
#define USBD_TXWR6 (*((volatile unsigned int*)0xEE5E))
#define USBD_TXEOD6 (*((volatile unsigned int*)0xEE60))
#define USBD_RXRR6 (*((volatile unsigned int*)0xEE62))
#define USBD_RX_BYTECNT6 (*((volatile unsigned int*)0xEE64))
#define USBD_TXWR7 (*((volatile unsigned int*)0xEE66))
#define USBD_TXEOD7 (*((volatile unsigned int*)0xEE68))
#define USBD_RXRR7 (*((volatile unsigned int*)0xEE6A))
#define USBD_RX_BYTECNT7 (*((volatile unsigned int*)0xEE6C))
#define USBD_CFGVAL (*((volatile unsigned int*)0xEE6E))
#define USBC_CMD_RESET (*((volatile unsigned int*)0xEE70))
#define SRCP0 (*((volatile unsigned int*)0xFCE0))
#define DSTP0 (*((volatile unsigned int*)0xFCE2))
#define SRCP1 (*((volatile unsigned int*)0xFCE4))
#define DSTP1 (*((volatile unsigned int*)0xFCE6))
#define SRCP2 (*((volatile unsigned int*)0xFCE8))
#define DSTP2 (*((volatile unsigned int*)0xFCEA))
#define SRCP3 (*((volatile unsigned int*)0xFCEC))
#define DSTP3 (*((volatile unsigned int*)0xFCEE))
#define SRCP4 (*((volatile unsigned int*)0xFCF0))
#define DSTP4 (*((volatile unsigned int*)0xFCF2))
#define SRCP5 (*((volatile unsigned int*)0xFCF4))
#define DSTP5 (*((volatile unsigned int*)0xFCF6))
#define SRCP6 (*((volatile unsigned int*)0xFCF8))
#define DSTP6 (*((volatile unsigned int*)0xFCFA))
#define SRCP7 (*((volatile unsigned int*)0xFCFC))
#define DSTP7 (*((volatile unsigned int*)0xFCFE))

__esfr(0x0A) volatile unsigned int XADRS1;
__esfr(0x0B) volatile unsigned int XADRS2;
__esfr(0x0C) volatile unsigned int XADRS3;
__esfr(0x0D) volatile unsigned int XADRS4;
__esfr(0x0E) volatile unsigned int XADRS5;
__esfr(0x0F) volatile unsigned int XADRS6;
__esfr(0x12) volatile unsigned int XPERCON;
__esfrbit(0x12,0x05) volatile __bit XPER5;
__esfrbit(0x12,0x06) volatile __bit XPER6;
__esfrbit(0x12,0x07) volatile __bit XPER7;
__esfr(0x3B) volatile unsigned int IDMEM2;
__esfr(0x3C) volatile unsigned int IDPROG;
__esfr(0x3D) volatile unsigned int IDMEM;
__esfr(0x3E) volatile unsigned int IDCHIP;
__esfr(0x3F) volatile unsigned int IDMANUF;
__esfr(0x58) volatile unsigned int SSCTB;
__esfr(0x59) volatile unsigned int SSCRB;
__esfr(0x5A) volatile unsigned int SSCBR;
__esfr(0x5B) volatile unsigned int SSCCLC;
__esfrbit(0x5B,0x00) volatile __bit SSCDISR;
__esfrbit(0x5B,0x01) volatile __bit SSCDISS;
__esfrbit(0x5B,0x02) volatile __bit SSCSUSPEN;
__esfrbit(0x5B,0x03) volatile __bit SSCEXDISR;
__esfr(0x60) volatile unsigned int SCUSLC;
__esfr(0x61) volatile unsigned int SCUSLS;
__esfr(0x66) volatile unsigned int RTCRELL;
__esfr(0x67) volatile unsigned int RTCRELH;
__esfr(0x68) volatile unsigned int T14REL;
__esfr(0x69) volatile unsigned int T14;
__esfr(0x6A) volatile unsigned int RTCL;
__esfr(0x6B) volatile unsigned int RTCH;
__esfr(0x6C) volatile unsigned int DTIDR;
__esfr(0x80) volatile unsigned int DP0L;
__esfr(0x81) volatile unsigned int DP0H;
__esfr(0x82) volatile unsigned int DP1L;
__esfr(0x83) volatile unsigned int DP1H;
__esfr(0x84) volatile unsigned int RP0H;
__esfr(0x8A) volatile unsigned int XBCON1;
__esfr(0x8B) volatile unsigned int XBCON2;
__esfr(0x8C) volatile unsigned int XBCON3;
__esfr(0x8D) volatile unsigned int XBCON4;
__esfr(0x8E) volatile unsigned int XBCON5;
__esfr(0x8F) volatile unsigned int XBCON6;
__esfr(0xB0) volatile unsigned int UTD3IC;
__esfrbit(0xB0,0x06) volatile __bit UTD3IE;
__esfrbit(0xB0,0x07) volatile __bit UTD3IR;
__esfr(0xB1) volatile unsigned int UTD4IC;
__esfrbit(0xB1,0x06) volatile __bit UTD4IE;
__esfrbit(0xB1,0x07) volatile __bit UTD4IR;
__esfr(0xB2) volatile unsigned int UTD5IC;
__esfrbit(0xB2,0x06) volatile __bit UTD5IE;
__esfrbit(0xB2,0x07) volatile __bit UTD5IR;
__esfr(0xB3) volatile unsigned int UTD6IC;
__esfrbit(0xB3,0x06) volatile __bit UTD6IE;
__esfrbit(0xB3,0x07) volatile __bit UTD6IR;
__esfr(0xB4) volatile unsigned int UTD7IC;
__esfrbit(0xB4,0x06) volatile __bit UTD7IE;
__esfrbit(0xB4,0x07) volatile __bit UTD7IR;
__esfr(0xB5) volatile unsigned int URXRIC;
__esfrbit(0xB5,0x06) volatile __bit URXRIE;
__esfrbit(0xB5,0x07) volatile __bit URXRIR;
__esfr(0xB6) volatile unsigned int UTXRIC;
__esfrbit(0xB6,0x06) volatile __bit UTXRIE;
__esfrbit(0xB6,0x07) volatile __bit UTXRIR;
__esfr(0xB7) volatile unsigned int UCFGVIC;
__esfrbit(0xB7,0x06) volatile __bit UCFGVIE;
__esfrbit(0xB7,0x07) volatile __bit UCFGVIR;
__esfr(0xB8) volatile unsigned int USOFIC;
__esfrbit(0xB8,0x06) volatile __bit USOFIE;
__esfrbit(0xB8,0x07) volatile __bit USOFIR;
__esfr(0xB9) volatile unsigned int USSOIC;
__esfrbit(0xB9,0x06) volatile __bit USSOIE;
__esfrbit(0xB9,0x07) volatile __bit USSOIR;
__esfr(0xBA) volatile unsigned int USSIC;
__esfrbit(0xBA,0x06) volatile __bit USSIE;
__esfrbit(0xBA,0x07) volatile __bit USSIR;
__esfr(0xBB) volatile unsigned int ULCDIC;
__esfrbit(0xBB,0x06) volatile __bit ULCDIE;
__esfrbit(0xBB,0x07) volatile __bit ULCDIR;
__esfr(0xBC) volatile unsigned int USETIC;
__esfrbit(0xBC,0x06) volatile __bit USETIE;
__esfrbit(0xBC,0x07) volatile __bit USETIR;
__esfr(0xBD) volatile unsigned int URD0IC;
__esfrbit(0xBD,0x06) volatile __bit URD0IE;
__esfrbit(0xBD,0x07) volatile __bit URD0IR;
__esfr(0xBE) volatile unsigned int EPECIC;
__esfrbit(0xBE,0x06) volatile __bit EPECIE;
__esfrbit(0xBE,0x07) volatile __bit EPECIR;
__esfr(0xC0) volatile unsigned int PECCLIC;
__esfr(0xC2) volatile unsigned int RTC_INTIC;
__esfr(0xC3) volatile unsigned int XP0IC;
__esfrbit(0xC3,0x06) volatile __bit XP0IE;
__esfrbit(0xC3,0x07) volatile __bit XP0IR;
__esfr(0xC6) volatile unsigned int ABENDIC;
__esfrbit(0xC6,0x06) volatile __bit ABENDIE;
__esfrbit(0xC6,0x07) volatile __bit ABENDIR;
__esfr(0xC7) volatile unsigned int XP1IC;
__esfrbit(0xC7,0x06) volatile __bit XP1IE;
__esfrbit(0xC7,0x07) volatile __bit XP1IR;
__esfr(0xCA) volatile unsigned int ABSTIC;
__esfrbit(0xCA,0x06) volatile __bit ABSTIE;
__esfrbit(0xCA,0x07) volatile __bit ABSTIR;
__esfr(0xCD) volatile unsigned int RES6IC;
__esfr(0xCE) volatile unsigned int S0TBIC;
__esfrbit(0xCE,0x06) volatile __bit S0TBIE;
__esfrbit(0xCE,0x07) volatile __bit S0TBIR;
__esfr(0xCF) volatile unsigned int XP3IC;
__esfrbit(0xCF,0x06) volatile __bit XP3IE;
__esfrbit(0xCF,0x07) volatile __bit XP3IR;
__esfr(0xE0) volatile unsigned int EXICON;
__esfr(0xE1) volatile unsigned int ODP2;
__esfr(0xE3) volatile unsigned int ODP3;
__esfr(0xE4) volatile unsigned int RTCISNC;
__esfrbit(0xE4,0x00) volatile __bit T14IE;
__esfrbit(0xE4,0x01) volatile __bit T14IR;
__esfrbit(0xE4,0x02) volatile __bit RTC0IE;
__esfrbit(0xE4,0x03) volatile __bit RTC0IR;
__esfrbit(0xE4,0x04) volatile __bit RTC1IE;
__esfrbit(0xE4,0x05) volatile __bit RTC1IR;
__esfrbit(0xE4,0x06) volatile __bit RTC2IE;
__esfrbit(0xE4,0x07) volatile __bit RTC2IR;
__esfrbit(0xE4,0x08) volatile __bit RTC3IE;
__esfrbit(0xE4,0x09) volatile __bit RTC3IR;
__esfr(0xE5) volatile unsigned int ODP4;
__esfr(0xE6) volatile unsigned int RTCCON;
__esfrbit(0xE6,0x00) volatile __bit RTCR;
__esfrbit(0xE6,0x01) volatile __bit RTCPRE;
__esfrbit(0xE6,0x02) volatile __bit T14DEC;
__esfrbit(0xE6,0x03) volatile __bit T14INC;
__esfr(0xE7) volatile unsigned int ODP6;
__esfr(0xE8) volatile unsigned int SYSCON2;
__esfrbit(0xE8,0x06) volatile __bit RCS;
__esfrbit(0xE8,0x07) volatile __bit SCS;
__esfrbit(0xE8,0x0F) volatile __bit CLKLOCK;
__esfr(0xEA) volatile unsigned int SYSCON3;
__esfrbit(0xEA,0x00) volatile __bit PERDIS0;
__esfrbit(0xEA,0x01) volatile __bit PERDIS1;
__esfrbit(0xEA,0x02) volatile __bit PERDIS2;
__esfrbit(0xEA,0x03) volatile __bit PERDIS3;
__esfrbit(0xEA,0x06) volatile __bit PERDIS6;
__esfrbit(0xEA,0x07) volatile __bit PERDIS7;
__esfrbit(0xEA,0x08) volatile __bit PERDIS8;
__esfrbit(0xEA,0x0D) volatile __bit PLLDIS;
__esfrbit(0xEA,0x0F) volatile __bit GRPDIS;
__esfr(0xED) volatile unsigned int EXISEL;
__esfr(0xEE) volatile unsigned int SYSCON1;
__esfr(0xEF) volatile unsigned int ISNC;
__esfrbit(0xEF,0x00) volatile __bit RTCT14IR;
__esfrbit(0xEF,0x01) volatile __bit RTCT14IE;
__esfrbit(0xEF,0x02) volatile __bit PLLIR;
__esfrbit(0xEF,0x03) volatile __bit PLLIE;

__sfr(0x00) volatile unsigned int DPP0;
__sfr(0x01) volatile unsigned int DPP1;
__sfr(0x02) volatile unsigned int DPP2;
__sfr(0x03) volatile unsigned int DPP3;
__sfr(0x04) volatile unsigned int CSP;
__sfr(0x05) volatile unsigned int EMUCON;
__sfr(0x06) volatile unsigned int MDH;
__sfr(0x07) volatile unsigned int MDL;
__sfr(0x08) volatile unsigned int CP;
__sfr(0x09) volatile unsigned int SP;
__sfr(0x0A) volatile unsigned int STKOV;
__sfr(0x0B) volatile unsigned int STKUN;
__sfr(0x0C) volatile unsigned int ADDRSEL1;
__sfr(0x0D) volatile unsigned int ADDRSEL2;
__sfr(0x0E) volatile unsigned int ADDRSEL3;
__sfr(0x0F) volatile unsigned int ADDRSEL4;
__sfr(0x11) volatile unsigned int ODP0H;
__sfr(0x12) volatile unsigned int ODP1L;
__sfr(0x13) volatile unsigned int ODP1H;
__sfr(0x20) volatile unsigned int T2;
__sfr(0x21) volatile unsigned int T3;
__sfr(0x22) volatile unsigned int T4;
__sfr(0x23) volatile unsigned int T5;
__sfr(0x24) volatile unsigned int T6;
__sfr(0x25) volatile unsigned int CAPREL;
__sfr(0x26) volatile unsigned int GPTCLC;
__sfrbit(0x26,0x00) volatile __bit GPTDISR;
__sfrbit(0x26,0x01) volatile __bit GPTDISS;
__sfrbit(0x26,0x02) volatile __bit GPTSUSPEN;
__sfrbit(0x26,0x03) volatile __bit GPTEXDISR;
__sfr(0x30) volatile unsigned int P0LPUDSEL;
__sfr(0x31) volatile unsigned int P0HPUDSEL;
__sfr(0x32) volatile unsigned int P0LPUDEN;
__sfr(0x33) volatile unsigned int P0HPUDEN;
__sfr(0x34) volatile unsigned int P0LPHEN;
__sfr(0x35) volatile unsigned int P0HPHEN;
__sfr(0x36) volatile unsigned int P1LPUDSEL;
__sfr(0x37) volatile unsigned int P1HPUDSEL;
__sfr(0x38) volatile unsigned int P1LPUDEN;
__sfr(0x39) volatile unsigned int P1HPUDEN;
__sfr(0x3A) volatile unsigned int P1LPHEN;
__sfr(0x3B) volatile unsigned int P1HPHEN;
__sfr(0x3C) volatile unsigned int P2PUDSEL;
__sfr(0x3D) volatile unsigned int P2PUDEN;
__sfr(0x3E) volatile unsigned int P2PHEN;
__sfr(0x3F) volatile unsigned int P3PUDSEL;
__sfr(0x40) volatile unsigned int P3PUDEN;
__sfr(0x41) volatile unsigned int P3PHEN;
__sfr(0x42) volatile unsigned int P4PUDSEL;
__sfr(0x43) volatile unsigned int P4PUDEN;
__sfr(0x44) volatile unsigned int P4PHEN;
__sfr(0x48) volatile unsigned int P6PUDSEL;
__sfr(0x49) volatile unsigned int P6PUDEN;
__sfr(0x4A) volatile unsigned int P6PHEN;
__sfr(0x55) volatile unsigned int S0PWM;
__sfr(0x57) volatile unsigned int WDT;
__sfr(0x58) volatile unsigned int S0TBUF;
__sfr(0x59) volatile unsigned int S0RBUF;
__sfr(0x5A) volatile unsigned int S0BG;
__sfr(0x5B) volatile unsigned int S0FDV;
__sfr(0x60) volatile unsigned int PECC0;
__sfr(0x61) volatile unsigned int PECC1;
__sfr(0x62) volatile unsigned int PECC2;
__sfr(0x63) volatile unsigned int PECC3;
__sfr(0x64) volatile unsigned int PECC4;
__sfr(0x65) volatile unsigned int PECC5;
__sfr(0x66) volatile unsigned int PECC6;
__sfr(0x67) volatile unsigned int PECC7;
__sfr(0x68) volatile unsigned int PECSN0;
__sfr(0x69) volatile unsigned int PECSN1;
__sfr(0x6A) volatile unsigned int PECSN2;
__sfr(0x6B) volatile unsigned int PECSN3;
__sfr(0x6C) volatile unsigned int PECSN4;
__sfr(0x6D) volatile unsigned int PECSN5;
__sfr(0x6E) volatile unsigned int PECSN6;
__sfr(0x6F) volatile unsigned int PECSN7;
__sfr(0x78) volatile unsigned int PECXC0;
__sfr(0x79) volatile unsigned int PECXC2;
__sfr(0x7C) volatile unsigned int ABS0CON;
__sfrbit(0x7C,0x00) volatile __bit ABEN;
__sfrbit(0x7C,0x01) volatile __bit AUREN;
__sfrbit(0x7C,0x02) volatile __bit ABSTEN;
__sfrbit(0x7C,0x03) volatile __bit ABDETEN;
__sfrbit(0x7C,0x04) volatile __bit FCDETEN;
__sfrbit(0x7C,0x0A) volatile __bit TXINV;
__sfrbit(0x7C,0x0B) volatile __bit RXINV;
__sfr(0x7F) volatile unsigned int ABSTAT;
__sfrbit(0x7F,0x00) volatile __bit FCSDET;
__sfrbit(0x7F,0x01) volatile __bit FCCDET;
__sfrbit(0x7F,0x02) volatile __bit SCSDET;
__sfrbit(0x7F,0x03) volatile __bit SCCDET;
__sfrbit(0x7F,0x04) volatile __bit DETWAIT;
__sfr(0x80) volatile unsigned int P0L;
__sfr(0x81) volatile unsigned int P0H;
__sfr(0x82) volatile unsigned int P1L;
__sfr(0x83) volatile unsigned int P1H;
__sfr(0x86) volatile unsigned int BUSCON0;
__sfr(0x87) volatile unsigned int MDC;
__sfrbit(0x87,0x04) volatile __bit MDRIU;
__sfr(0x88) volatile unsigned int PSW;
__sfrbit(0x88,0x05) volatile __bit MULIP;
__sfrbit(0x88,0x06) volatile __bit USR0;
__sfrbit(0x88,0x0B) volatile __bit IEN;
__sfr(0x89) volatile unsigned int SYSCON;
__sfrbit(0x89,0x00) volatile __bit XPERSHARE;
__sfrbit(0x89,0x01) volatile __bit VISIBLE;
__sfrbit(0x89,0x02) volatile __bit XPEN;
__sfrbit(0x89,0x04) volatile __bit OSCENBL;
__sfrbit(0x89,0x06) volatile __bit CSCFG;
__sfrbit(0x89,0x07) volatile __bit WRCFG;
__sfrbit(0x89,0x08) volatile __bit CLKEN;
__sfrbit(0x89,0x09) volatile __bit BYTDIS;
__sfrbit(0x89,0x0A) volatile __bit ROMEN;
__sfrbit(0x89,0x0B) volatile __bit SGTDIS;
__sfrbit(0x89,0x0C) volatile __bit ROMS1;
__sfr(0x8A) volatile unsigned int BUSCON1;
__sfr(0x8B) volatile unsigned int BUSCON2;
__sfr(0x8C) volatile unsigned int BUSCON3;
__sfr(0x8D) volatile unsigned int BUSCON4;
__sfr(0x8E) volatile unsigned int ZEROS;
__sfr(0x8F) volatile unsigned int ONES;
__sfr(0xA0) volatile unsigned int T2CON;
__sfrbit(0xA0,0x06) volatile __bit T2R;
__sfrbit(0xA0,0x07) volatile __bit T2UD;
__sfrbit(0xA0,0x08) volatile __bit T2UDE;
__sfrbit(0xA0,0x09) volatile __bit T2RC;
__sfrbit(0xA0,0x0C) volatile __bit T2EDGE;
__sfrbit(0xA0,0x0D) volatile __bit T2CHDIR;
__sfrbit(0xA0,0x0E) volatile __bit T2RDIR;
__sfrbit(0xA0,0x0F) volatile __bit T2IREN;
__sfr(0xA1) volatile unsigned int T3CON;
__sfrbit(0xA1,0x06) volatile __bit T3R;
__sfrbit(0xA1,0x07) volatile __bit T3UD;
__sfrbit(0xA1,0x08) volatile __bit T3UDE;
__sfrbit(0xA1,0x09) volatile __bit T3OE;
__sfrbit(0xA1,0x0A) volatile __bit T3OTL;
__sfrbit(0xA1,0x0B) volatile __bit FM1;
__sfrbit(0xA1,0x0C) volatile __bit T3EDGE;
__sfrbit(0xA1,0x0D) volatile __bit T3CHDIR;
__sfrbit(0xA1,0x0E) volatile __bit T3RDIR;
__sfrbit(0xA1,0x0F) volatile __bit T3IREN;
__sfr(0xA2) volatile unsigned int T4CON;
__sfrbit(0xA2,0x06) volatile __bit T4R;
__sfrbit(0xA2,0x07) volatile __bit T4UD;
__sfrbit(0xA2,0x08) volatile __bit T4UDE;
__sfrbit(0xA2,0x09) volatile __bit T4RC;
__sfrbit(0xA2,0x0C) volatile __bit T4EDGE;
__sfrbit(0xA2,0x0D) volatile __bit T4CHDIR;
__sfrbit(0xA2,0x0E) volatile __bit T4RDIR;
__sfrbit(0xA2,0x0F) volatile __bit T4IREN;
__sfr(0xA3) volatile unsigned int T5CON;
__sfrbit(0xA3,0x06) volatile __bit T5R;
__sfrbit(0xA3,0x07) volatile __bit T5UD;
__sfrbit(0xA3,0x09) volatile __bit T5RC;
__sfrbit(0xA3,0x0A) volatile __bit CT3;
__sfrbit(0xA3,0x0B) volatile __bit T5CC;
__sfrbit(0xA3,0x0E) volatile __bit T5CLR;
__sfrbit(0xA3,0x0F) volatile __bit T5SC;
__sfr(0xA4) volatile unsigned int T6CON;
__sfrbit(0xA4,0x06) volatile __bit T6R;
__sfrbit(0xA4,0x07) volatile __bit T6UD;
__sfrbit(0xA4,0x0A) volatile __bit T6OTL;
__sfrbit(0xA4,0x0B) volatile __bit FM2;
__sfrbit(0xA4,0x0E) volatile __bit T6CLR;
__sfrbit(0xA4,0x0F) volatile __bit T6SR;
__sfr(0xB0) volatile unsigned int T2IC;
__sfrbit(0xB0,0x06) volatile __bit T2IE;
__sfrbit(0xB0,0x07) volatile __bit T2IR;
__sfr(0xB1) volatile unsigned int T3IC;
__sfrbit(0xB1,0x06) volatile __bit T3IE;
__sfrbit(0xB1,0x07) volatile __bit T3IR;
__sfr(0xB2) volatile unsigned int T4IC;
__sfrbit(0xB2,0x06) volatile __bit T4IE;
__sfrbit(0xB2,0x07) volatile __bit T4IR;
__sfr(0xB3) volatile unsigned int T5IC;
__sfrbit(0xB3,0x06) volatile __bit T5IE;
__sfrbit(0xB3,0x07) volatile __bit T5IR;
__sfr(0xB4) volatile unsigned int T6IC;
__sfrbit(0xB4,0x06) volatile __bit T6IE;
__sfrbit(0xB4,0x07) volatile __bit T6IR;
__sfr(0xB5) volatile unsigned int CRIC;
__sfrbit(0xB5,0x06) volatile __bit CRIE;
__sfrbit(0xB5,0x07) volatile __bit CRIR;
__sfr(0xB6) volatile unsigned int S0TIC;
__sfrbit(0xB6,0x06) volatile __bit S0TIE;
__sfrbit(0xB6,0x07) volatile __bit S0TIR;
__sfr(0xB7) volatile unsigned int S0RIC;
__sfrbit(0xB7,0x06) volatile __bit S0RIE;
__sfrbit(0xB7,0x07) volatile __bit S0RIR;
__sfr(0xB8) volatile unsigned int S0EIC;
__sfrbit(0xB8,0x06) volatile __bit S0EIE;
__sfrbit(0xB8,0x07) volatile __bit S0EIR;
__sfr(0xB9) volatile unsigned int SSCTIC;
__sfrbit(0xB9,0x06) volatile __bit SSCTIE;
__sfrbit(0xB9,0x07) volatile __bit SSCTIR;
__sfr(0xBA) volatile unsigned int SSCRIC;
__sfrbit(0xBA,0x06) volatile __bit SSCRIE;
__sfrbit(0xBA,0x07) volatile __bit SSCRIR;
__sfr(0xBB) volatile unsigned int SSCEIC;
__sfrbit(0xBB,0x06) volatile __bit SSCEIE;
__sfrbit(0xBB,0x07) volatile __bit SSCEIR;
__sfr(0xBC) volatile unsigned int URD3IC;
__sfrbit(0xBC,0x06) volatile __bit URD3IE;
__sfrbit(0xBC,0x07) volatile __bit URD3IR;
__sfr(0xBD) volatile unsigned int URD4IC;
__sfrbit(0xBD,0x06) volatile __bit URD4IE;
__sfrbit(0xBD,0x07) volatile __bit URD4IR;
__sfr(0xBE) volatile unsigned int URD5IC;
__sfrbit(0xBE,0x06) volatile __bit URD5IE;
__sfrbit(0xBE,0x07) volatile __bit URD5IR;
__sfr(0xBF) volatile unsigned int URD6IC;
__sfrbit(0xBF,0x06) volatile __bit URD6IE;
__sfrbit(0xBF,0x07) volatile __bit URD6IR;
__sfr(0xC0) volatile unsigned int URD7IC;
__sfrbit(0xC0,0x06) volatile __bit URD7IE;
__sfrbit(0xC0,0x07) volatile __bit URD7IR;
__sfr(0xC1) volatile unsigned int UTD0IC;
__sfrbit(0xC1,0x06) volatile __bit UTD0IE;
__sfrbit(0xC1,0x07) volatile __bit UTD0IR;
__sfr(0xC2) volatile unsigned int UTD1IC;
__sfrbit(0xC2,0x06) volatile __bit UTD1IE;
__sfrbit(0xC2,0x07) volatile __bit UTD1IR;
__sfr(0xC3) volatile unsigned int UTD2IC;
__sfrbit(0xC3,0x06) volatile __bit UTD2IE;
__sfrbit(0xC3,0x07) volatile __bit UTD2IR;
__sfr(0xC4) volatile unsigned int FEI0IC;
__sfrbit(0xC4,0x06) volatile __bit FEI0IE;
__sfrbit(0xC4,0x07) volatile __bit FEI0IR;
__sfr(0xC5) volatile unsigned int FEI1IC;
__sfrbit(0xC5,0x06) volatile __bit FEI1IE;
__sfrbit(0xC5,0x07) volatile __bit FEI1IR;
__sfr(0xCB) volatile unsigned int RES4IC;
__sfr(0xCE) volatile unsigned int URD2IC;
__sfrbit(0xCE,0x06) volatile __bit URD2IE;
__sfrbit(0xCE,0x07) volatile __bit URD2IR;
__sfr(0xCF) volatile unsigned int URD1IC;
__sfrbit(0xCF,0x06) volatile __bit URD1IE;
__sfrbit(0xCF,0x07) volatile __bit URD1IR;
__sfr(0xD4) volatile unsigned int CLISNC;
__sfrbit(0xD4,0x00) volatile __bit C0IE;
__sfrbit(0xD4,0x01) volatile __bit C0IR;
__sfrbit(0xD4,0x04) volatile __bit C2IE;
__sfrbit(0xD4,0x05) volatile __bit C2IR;
__sfrbit(0xD4,0x08) volatile __bit C4IE;
__sfrbit(0xD4,0x09) volatile __bit C4IR;
__sfrbit(0xD4,0x0C) volatile __bit C6IR;
__sfrbit(0xD4,0x0D) volatile __bit C6IE;
__sfr(0xD5) volatile unsigned int FOCON;
__sfr(0xD6) volatile unsigned int TFR;
__sfrbit(0xD6,0x00) volatile __bit ILLBUS;
__sfrbit(0xD6,0x01) volatile __bit ILLINA;
__sfrbit(0xD6,0x02) volatile __bit ILLOPA;
__sfrbit(0xD6,0x03) volatile __bit PRTFLT;
__sfrbit(0xD6,0x07) volatile __bit UNDOPC;
__sfrbit(0xD6,0x0D) volatile __bit STKUF;
__sfrbit(0xD6,0x0E) volatile __bit STKOF;
__sfrbit(0xD6,0x0F) volatile __bit NMI;
__sfr(0xD7) volatile unsigned int WDTCON;
__sfrbit(0xD7,0x00) volatile __bit WDTIN;
__sfrbit(0xD7,0x01) volatile __bit WDTR;
__sfrbit(0xD7,0x02) volatile __bit SWR;
__sfrbit(0xD7,0x03) volatile __bit SHWR;
__sfrbit(0xD7,0x04) volatile __bit LHWR;
__sfr(0xD8) volatile unsigned int S0CON;
__sfrbit(0xD8,0x03) volatile __bit S0STP;
__sfrbit(0xD8,0x04) volatile __bit S0REN;
__sfrbit(0xD8,0x05) volatile __bit S0PEN;
__sfrbit(0xD8,0x06) volatile __bit S0FEN;
__sfrbit(0xD8,0x07) volatile __bit S0OEN;
__sfrbit(0xD8,0x08) volatile __bit S0PE;
__sfrbit(0xD8,0x09) volatile __bit S0FE;
__sfrbit(0xD8,0x0A) volatile __bit S0OE;
__sfrbit(0xD8,0x0B) volatile __bit S0FDE;
__sfrbit(0xD8,0x0C) volatile __bit S0ODD;
__sfrbit(0xD8,0x0D) volatile __bit S0BRS;
__sfrbit(0xD8,0x0E) volatile __bit S0LB;
__sfrbit(0xD8,0x0F) volatile __bit S0R;
__sfr(0xD9) volatile unsigned int SSCCON;
__sfrbit(0xD9,0x04) volatile __bit SSCHB;
__sfrbit(0xD9,0x05) volatile __bit SSCPH;
__sfrbit(0xD9,0x06) volatile __bit SSCPO;
__sfrbit(0xD9,0x08) volatile __bit SSCTEN;
__sfrbit(0xD9,0x08) volatile __bit SSCTE;
__sfrbit(0xD9,0x09) volatile __bit SSCREN;
__sfrbit(0xD9,0x09) volatile __bit SSCRE;
__sfrbit(0xD9,0x0A) volatile __bit SSCPEN;
__sfrbit(0xD9,0x0A) volatile __bit SSCPE;
__sfrbit(0xD9,0x0B) volatile __bit SSCBEN;
__sfrbit(0xD9,0x0B) volatile __bit SSCBE;
__sfrbit(0xD9,0x0C) volatile __bit SSCAREN;
__sfrbit(0xD9,0x0C) volatile __bit SSCBSY;
__sfrbit(0xD9,0x0E) volatile __bit SSCMS;
__sfrbit(0xD9,0x0F) volatile __bit SSCEN;
__sfr(0xDD) volatile unsigned int S0CLC;
__sfrbit(0xDD,0x00) volatile __bit S0DISR;
__sfrbit(0xDD,0x01) volatile __bit S0DISS;
__sfrbit(0xDD,0x02) volatile __bit S0SUSPEN;
__sfrbit(0xDD,0x03) volatile __bit S0EXDISR;
__sfr(0xE0) volatile unsigned int P2;
__sfr(0xE1) volatile unsigned int DP2;
__sfr(0xE2) volatile unsigned int P3;
__sfr(0xE3) volatile unsigned int DP3;
__sfr(0xE4) volatile unsigned int P4;
__sfr(0xE5) volatile unsigned int DP4;
__sfr(0xE6) volatile unsigned int P6;
__sfr(0xE7) volatile unsigned int DP6;

#endif
