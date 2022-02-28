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
#ifndef C164SM_H
#define C164SM_H
/*
 v0.1 30/11/04

 Hardware register access for the Infineon c164sm device. 
 These declarations are to be used with the vbcc(c16x) compiler.
*/

#define OPCTRL (*((volatile unsigned int*)0xEDC0))
#define OPAD (*((volatile unsigned int*)0xEDC2))
#define OPDAT (*((volatile unsigned int*)0xEDC4))
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

__esfr(0x18) volatile unsigned int T12P;
__esfr(0x19) volatile unsigned int T13P;
__esfr(0x1A) volatile unsigned int T12OF;
__esfr(0x1B) volatile unsigned int CC6MSEL;
__esfr(0x28) volatile unsigned int T7;
__esfr(0x29) volatile unsigned int T8;
__esfr(0x2A) volatile unsigned int T7REL;
__esfr(0x2B) volatile unsigned int T8REL;
__esfr(0x3B) volatile unsigned int IDMEM2;
__esfr(0x3C) volatile unsigned int IDPROG;
__esfr(0x3D) volatile unsigned int IDMEM;
__esfr(0x3E) volatile unsigned int IDCHIP;
__esfr(0x3F) volatile unsigned int IDMANUF;
__esfr(0x40) volatile unsigned int POCON0L;
__esfr(0x41) volatile unsigned int POCON0H;
__esfr(0x42) volatile unsigned int POCON1L;
__esfr(0x43) volatile unsigned int POCON1H;
__esfr(0x49) volatile unsigned int POCON8;
__esfr(0x50) volatile unsigned int ADDAT2;
__esfr(0x55) volatile unsigned int POCON20;
__esfr(0x57) volatile unsigned int PTCR;
__esfr(0x58) volatile unsigned int SSCTB;
__esfr(0x59) volatile unsigned int SSCRB;
__esfr(0x5A) volatile unsigned int SSCBR;
__esfr(0x68) volatile unsigned int T14REL;
__esfr(0x69) volatile unsigned int T14;
__esfr(0x6A) volatile unsigned int RTCL;
__esfr(0x6B) volatile unsigned int RTCH;
__esfr(0x80) volatile unsigned int DP0L;
__esfr(0x81) volatile unsigned int DP0H;
__esfr(0x82) volatile unsigned int DP1L;
__esfr(0x83) volatile unsigned int DP1H;
__esfr(0x84) volatile unsigned int RP0H;
__esfr(0xB0) volatile unsigned int CC16IC;
__esfrbit(0xB0,0x06) volatile __bit CC16IE;
__esfrbit(0xB0,0x07) volatile __bit CC16IR; 
__esfr(0xB1) volatile unsigned int CC17IC;
__esfrbit(0xB1,0x06) volatile __bit CC17IE;
__esfrbit(0xB1,0x07) volatile __bit CC17IR;
__esfr(0xB2) volatile unsigned int CC18IC;
__esfrbit(0xB2,0x06) volatile __bit CC18IE;
__esfrbit(0xB2,0x07) volatile __bit CC18IR;
__esfr(0xB3) volatile unsigned int CC19IC;
__esfrbit(0xB3,0x06) volatile __bit CC19IE;
__esfrbit(0xB3,0x07) volatile __bit CC19IR;
__esfr(0xB8) volatile unsigned int CC24IC;
__esfrbit(0xB8,0x06) volatile __bit CC24IE;
__esfrbit(0xB8,0x07) volatile __bit CC24IR;
__esfr(0xB9) volatile unsigned int CC25IC;
__esfrbit(0xB9,0x06) volatile __bit CC25IE;
__esfrbit(0xB9,0x07) volatile __bit CC25IR;
__esfr(0xBA) volatile unsigned int CC26IC;
__esfrbit(0xBA,0x06) volatile __bit CC26IE;
__esfrbit(0xBA,0x07) volatile __bit CC26IR;
__esfr(0xBB) volatile unsigned int CC27IC;
__esfrbit(0xBB,0x06) volatile __bit CC27IE;
__esfrbit(0xBB,0x07) volatile __bit CC27IR;
__esfr(0xBD) volatile unsigned int T7IC;
__esfrbit(0xBD,0x06) volatile __bit T7IE;
__esfrbit(0xBD,0x07) volatile __bit T7IR;
__esfr(0xBE) volatile unsigned int T8IC;
__esfrbit(0xBE,0x06) volatile __bit T8IE;
__esfrbit(0xBE,0x07) volatile __bit T8IR;
__esfr(0xBF) volatile unsigned int CC6IC;
__esfrbit(0xBF,0x06) volatile __bit CC6IE;
__esfrbit(0xBF,0x07) volatile __bit CC6IR;
__esfr(0xC3) volatile unsigned int XP0IC;
__esfrbit(0xC3,0x06) volatile __bit XP0IE;
__esfrbit(0xC3,0x07) volatile __bit XP0IR;
__esfr(0xC4) volatile unsigned int CC6EIC;
__esfrbit(0xC4,0x06) volatile __bit CC6EIE;
__esfrbit(0xC4,0x07) volatile __bit CC6EIR;
__esfr(0xC8) volatile unsigned int T12IC;
__esfrbit(0xC8,0x06) volatile __bit T12IE;
__esfrbit(0xC8,0x07) volatile __bit T12IR;
__esfr(0xCC) volatile unsigned int T13IC;
__esfrbit(0xCC,0x06) volatile __bit T13IE;
__esfrbit(0xCC,0x07) volatile __bit T13IR;
__esfr(0xCE) volatile unsigned int S0TBIC;
__esfrbit(0xCE,0x06) volatile __bit S0TBIE;
__esfrbit(0xCE,0x07) volatile __bit S0TBIR;
__esfr(0xCF) volatile unsigned int XP3IC;
__esfrbit(0xCF,0x06) volatile __bit XP3IE;
__esfrbit(0xCF,0x07) volatile __bit XP3IR;
__esfr(0xE0) volatile unsigned int EXICON;
__esfr(0xE8) volatile unsigned int SYSCON2;
__esfrbit(0xE8,0x0F) volatile __bit CLKLOCK;
__esfr(0xEA) volatile unsigned int SYSCON3;
__esfrbit(0xEA,0x00) volatile __bit ADCDIS;
__esfrbit(0xEA,0x01) volatile __bit ASC0DIS;
__esfrbit(0xEA,0x02) volatile __bit SSCDIS;
__esfrbit(0xEA,0x03) volatile __bit GPTDIS;
__esfrbit(0xEA,0x07) volatile __bit CC2DIS;
__esfrbit(0xEA,0x08) volatile __bit CC6DIS;
__esfrbit(0xEA,0x0D) volatile __bit CAN1DIS;
__esfrbit(0xEA,0x0F) volatile __bit PCDDIS;
__esfr(0xEB) volatile unsigned int ODP8;
__esfr(0xED) volatile unsigned int EXISEL;
__esfr(0xEE) volatile unsigned int SYSCON1;
__esfr(0xEF) volatile unsigned int ISNC;
__esfrbit(0xEF,0x00) volatile __bit RTCIR;
__esfrbit(0xEF,0x01) volatile __bit RTCIE;
__esfrbit(0xEF,0x02) volatile __bit PLLIR;
__esfrbit(0xEF,0x03) volatile __bit PLLIE;

__sfr(0x00) volatile unsigned int DPP0;
__sfr(0x01) volatile unsigned int DPP1;
__sfr(0x02) volatile unsigned int DPP2;
__sfr(0x03) volatile unsigned int DPP3;
__sfr(0x04) volatile unsigned int CSP;
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
__sfr(0x18) volatile unsigned int CC60;
__sfr(0x19) volatile unsigned int CC61;
__sfr(0x1A) volatile unsigned int CC62;
__sfr(0x1B) volatile unsigned int CMP13;
__sfr(0x20) volatile unsigned int T2;
__sfr(0x21) volatile unsigned int T3;
__sfr(0x22) volatile unsigned int T4;
__sfr(0x30) volatile unsigned int CC16;
__sfr(0x31) volatile unsigned int CC17;
__sfr(0x32) volatile unsigned int CC18;
__sfr(0x33) volatile unsigned int CC19;
__sfr(0x34) volatile unsigned int CC20;
__sfr(0x35) volatile unsigned int CC21;
__sfr(0x36) volatile unsigned int CC22;
__sfr(0x37) volatile unsigned int CC23;
__sfr(0x38) volatile unsigned int CC24;
__sfr(0x39) volatile unsigned int CC25;
__sfr(0x3A) volatile unsigned int CC26;
__sfr(0x3B) volatile unsigned int CC27;
__sfr(0x3C) volatile unsigned int CC28;
__sfr(0x3D) volatile unsigned int CC29;
__sfr(0x3E) volatile unsigned int CC30;
__sfr(0x3F) volatile unsigned int CC31;
__sfr(0x50) volatile unsigned int ADDAT;
__sfr(0x57) volatile unsigned int WDT;
__sfr(0x58) volatile unsigned int S0TBUF;
__sfr(0x59) volatile unsigned int S0RBUF;
__sfr(0x5A) volatile unsigned int S0BG;
__sfr(0x60) volatile unsigned int PECC0;
__sfr(0x61) volatile unsigned int PECC1;
__sfr(0x62) volatile unsigned int PECC2;
__sfr(0x63) volatile unsigned int PECC3;
__sfr(0x64) volatile unsigned int PECC4;
__sfr(0x65) volatile unsigned int PECC5;
__sfr(0x66) volatile unsigned int PECC6;
__sfr(0x67) volatile unsigned int PECC7;
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
__sfrbit(0x89,0x01) volatile __bit VISIBLE;
__sfrbit(0x89,0x02) volatile __bit XPEN;
__sfrbit(0x89,0x03) volatile __bit BDRSTEN;
__sfrbit(0x89,0x04) volatile __bit OWDDIS;
__sfrbit(0x89,0x08) volatile __bit CLKEN;
__sfrbit(0x89,0x0A) volatile __bit ROMEN;
__sfrbit(0x89,0x0B) volatile __bit SGTDIS;
__sfrbit(0x89,0x0C) volatile __bit ROMS1;
__sfr(0x8A) volatile unsigned int BUSCON1;
__sfr(0x8B) volatile unsigned int BUSCON2;
__sfr(0x8C) volatile unsigned int BUSCON3;
__sfr(0x8D) volatile unsigned int BUSCON4;
__sfr(0x8E) volatile unsigned int ZEROS;
__sfr(0x8F) volatile unsigned int ONES;
__sfr(0x90) volatile unsigned int T78CON;
__sfr(0x91) volatile unsigned int CCM4;
__sfr(0x92) volatile unsigned int CCM5;
__sfr(0x93) volatile unsigned int CCM6;
__sfr(0x94) volatile unsigned int CCM7;
__sfr(0x98) volatile unsigned int CTCON;
__sfr(0x99) volatile unsigned int CC6MCON;
__sfr(0x9A) volatile unsigned int TRCON;
__sfr(0x9B) volatile unsigned int CC6MIC;
__sfr(0xA0) volatile unsigned int T2CON;
__sfrbit(0xA0,0x06) volatile __bit T2R;
__sfrbit(0xA0,0x07) volatile __bit T2UD;
__sfrbit(0xA0,0x08) volatile __bit T2UDE; 
__sfr(0xA1) volatile unsigned int T3CON;
__sfrbit(0xA1,0x06) volatile __bit T3R;
__sfrbit(0xA1,0x07) volatile __bit T3UD;
__sfrbit(0xA1,0x08) volatile __bit T3UDE;
__sfrbit(0xA1,0x0A) volatile __bit T3OTL;
__sfr(0xA2) volatile unsigned int T4CON;
__sfrbit(0xA2,0x06) volatile __bit T4R;
__sfrbit(0xA2,0x07) volatile __bit T4UD;
__sfrbit(0xA2,0x08) volatile __bit T4UDE;
__sfr(0xB0) volatile unsigned int T2IC;
__sfrbit(0xB0,0x06) volatile __bit T2IE;
__sfrbit(0xB0,0x07) volatile __bit T2IR;
__sfr(0xB1) volatile unsigned int T3IC;
__sfrbit(0xB1,0x06) volatile __bit T3IE;
__sfrbit(0xB1,0x07) volatile __bit T3IR;
__sfr(0xB2) volatile unsigned int T4IC;
__sfrbit(0xB2,0x06) volatile __bit T4IE;
__sfrbit(0xB2,0x07) volatile __bit T5IR;
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
__sfr(0xC4) volatile unsigned int CC8IC;
__sfrbit(0xC4,0x06) volatile __bit CC8IE;
__sfrbit(0xC4,0x07) volatile __bit CC8IR;
__sfr(0xC5) volatile unsigned int CC9IC;
__sfrbit(0xC5,0x06) volatile __bit CC9IE;
__sfrbit(0xC5,0x07) volatile __bit CC9IR;
__sfr(0xC6) volatile unsigned int CC10IC;
__sfrbit(0xC6,0x06) volatile __bit CC10IE;
__sfrbit(0xC6,0x07) volatile __bit CC10IR;
__sfr(0xC7) volatile unsigned int CC11IC;
__sfrbit(0xC7,0x06) volatile __bit CC11IE;
__sfrbit(0xC7,0x07) volatile __bit CC11IR;
__sfr(0xCC) volatile unsigned int ADCIC;
__sfrbit(0xCC,0x06) volatile __bit ADCIE;
__sfrbit(0xCC,0x07) volatile __bit ADCIR;
__sfr(0xCD) volatile unsigned int ADEIC;
__sfrbit(0xCD,0x06) volatile __bit ADEIE;
__sfrbit(0xCD,0x07) volatile __bit ADEIR;
__sfr(0xD0) volatile unsigned int ADCON;
__sfrbit(0xD0,0x07) volatile __bit ADST;
__sfrbit(0xD0,0x08) volatile __bit ADBSY;
__sfrbit(0xD0,0x09) volatile __bit ADWR;
__sfrbit(0xD0,0x0A) volatile __bit ADCIN;
__sfrbit(0xD0,0x0B) volatile __bit ADCRQ;
__sfr(0xD1) volatile unsigned int P5;
__sfr(0xD2) volatile unsigned int P5DIDIS;
__sfr(0xD5) volatile unsigned int FOCON;
__sfrbit(0xD5,0x06) volatile __bit FOTL;
__sfrbit(0xD5,0x0E) volatile __bit FOSS;
__sfrbit(0xD5,0x0F) volatile __bit FOEN;
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
__sfrbit(0xD7,0x07) volatile __bit WDTPRE;
__sfr(0xD8) volatile unsigned int S0CON;
__sfrbit(0xD8,0x03) volatile __bit S0STP;
__sfrbit(0xD8,0x04) volatile __bit S0REN;
__sfrbit(0xD8,0x05) volatile __bit S0PEN;
__sfrbit(0xD8,0x06) volatile __bit S0FEN;
__sfrbit(0xD8,0x07) volatile __bit S0OEN;
__sfrbit(0xD8,0x08) volatile __bit S0PE;
__sfrbit(0xD8,0x09) volatile __bit S0FE;
__sfrbit(0xD8,0x0A) volatile __bit S0OE;
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
__sfr(0xDA) volatile unsigned int P20;
__sfr(0xDB) volatile unsigned int DP20;
__sfr(0xEA) volatile unsigned int P8;
__sfr(0xEB) volatile unsigned int DP8;

#endif
