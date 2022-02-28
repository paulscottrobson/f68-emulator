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
#ifndef ST10R172L_H
#define ST10R172L_H
/*
 v0.1 02/12/04

 Hardware register access for the ST st10r172l device. 
 These declarations are to be used with the vbcc(c16x) compiler.
*/

#define SSPCON0 (*((volatile unsigned int*)0xEF00))
#define SSPCON1 (*((volatile unsigned int*)0xEF02))
#define SSPRTB (*((volatile unsigned int*)0xEF04))
#define SSPTBH (*((volatile unsigned int*)0xEF06))
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

__esfr(0x1F) volatile unsigned int PP3;
__esfr(0x3C) volatile unsigned int IDPROG;
__esfr(0x3D) volatile unsigned int IDMEM;
__esfr(0x3E) volatile unsigned int IDCHIP;
__esfr(0x3F) volatile unsigned int IDMANUF;
__esfr(0x80) volatile unsigned int DP0L;
__esfr(0x81) volatile unsigned int DP0H;
__esfr(0x82) volatile unsigned int DP1L;
__esfr(0x83) volatile unsigned int DP1H;
__esfr(0x84) volatile unsigned int RP0H;
__esfr(0x87) volatile unsigned int EBUSCON;
__esfr(0xBF) volatile unsigned int PWMIC;
__esfrbit(0xBF,0x06) volatile __bit PWMIE;
__esfrbit(0xBF,0x07) volatile __bit PWMIR;
__esfr(0xC7) volatile unsigned int XP1IC;
__esfrbit(0xC7,0x06) volatile __bit XP1IE;
__esfrbit(0xC7,0x07) volatile __bit XP1IR;
__esfr(0xCE) volatile unsigned int S0TBIC;
__esfrbit(0xCE,0x06) volatile __bit S0TBIE;
__esfrbit(0xCE,0x07) volatile __bit S0TBIR;
__esfr(0xCF) volatile unsigned int XP3IC;
__esfrbit(0xCF,0x06) volatile __bit XP3IE;
__esfrbit(0xCF,0x07) volatile __bit XP3IR;
__esfr(0xE0) volatile unsigned int EXICON;
__esfr(0xE1) volatile unsigned int ODP2;
__esfr(0xE3) volatile unsigned int ODP3;
__esfr(0xE7) volatile unsigned int ODP6;
__esfr(0xE9) volatile unsigned int ODP7;

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
__sfr(0x1B) volatile unsigned int PW3;
__sfr(0x20) volatile unsigned int T2;
__sfr(0x21) volatile unsigned int T3;
__sfr(0x22) volatile unsigned int T4;
__sfr(0x23) volatile unsigned int T5;
__sfr(0x24) volatile unsigned int T6;
__sfr(0x25) volatile unsigned int CAPREL;
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
__sfrbit(0x88,0x0A) volatile __bit HLDEN;
__sfrbit(0x88,0x0B) volatile __bit IEN;
__sfr(0x89) volatile unsigned int SYSCON;
__sfrbit(0x89,0x00) volatile __bit XPERSHARE;
__sfrbit(0x89,0x01) volatile __bit VISIBLE;
__sfrbit(0x89,0x02) volatile __bit XPEN;
__sfrbit(0x89,0x03) volatile __bit BDRSTEN;
__sfrbit(0x89,0x04) volatile __bit OWDDIS;
__sfrbit(0x89,0x05) volatile __bit PWDCFG;
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
__sfr(0x98) volatile unsigned int PWMCON0;
__sfrbit(0x98,0x03) volatile __bit PTR3;
__sfrbit(0x98,0x07) volatile __bit PTI3;
__sfrbit(0x98,0x0B) volatile __bit PIE3;
__sfrbit(0x98,0x0F) volatile __bit PIR3;
__sfr(0x99) volatile unsigned int PWMCON1;
__sfrbit(0x99,0x03) volatile __bit PEN3;
__sfrbit(0x99,0x07) volatile __bit PM3;
__sfrbit(0x99,0x0F) volatile __bit PS3;
__sfr(0xA0) volatile unsigned int T2CON;
__sfrbit(0xA0,0x06) volatile __bit T2R;
__sfrbit(0xA0,0x07) volatile __bit T2UD;
__sfrbit(0xA0,0x08) volatile __bit T2UDE; 
__sfr(0xA1) volatile unsigned int T3CON;
__sfrbit(0xA1,0x06) volatile __bit T3R;
__sfrbit(0xA1,0x07) volatile __bit T3UD;
__sfrbit(0xA1,0x08) volatile __bit T3UDE;
__sfrbit(0xA1,0x09) volatile __bit T3OE;
__sfrbit(0xA1,0x0A) volatile __bit T3OTL;
__sfr(0xA2) volatile unsigned int T4CON;
__sfrbit(0xA2,0x06) volatile __bit T4R;
__sfrbit(0xA2,0x07) volatile __bit T4UD;
__sfrbit(0xA2,0x08) volatile __bit T4UDE;
__sfr(0xA3) volatile unsigned int T5CON;
__sfrbit(0xA3,0x06) volatile __bit T5R;
__sfrbit(0xA3,0x07) volatile __bit T5UD;
__sfrbit(0xA3,0x08) volatile __bit T5UDE;
__sfrbit(0xA3,0x0E) volatile __bit T5CLR;
__sfrbit(0xA3,0x0F) volatile __bit T5SC;
__sfr(0xA4) volatile unsigned int T6CON;
__sfrbit(0xA4,0x06) volatile __bit T6R;
__sfrbit(0xA4,0x07) volatile __bit T6UD;
__sfrbit(0xA4,0x08) volatile __bit T6UDE;
__sfrbit(0xA4,0x09) volatile __bit T6OE;
__sfrbit(0xA4,0x0A) volatile __bit T6OTL;
__sfrbit(0xA4,0x0F) volatile __bit T6SR;
__sfr(0xB0) volatile unsigned int T2IC;
__sfrbit(0xB0,0x06) volatile __bit T2IE;
__sfrbit(0xB0,0x07) volatile __bit T2IR;
__sfr(0xB1) volatile unsigned int T3IC;
__sfrbit(0xB1,0x06) volatile __bit T3IE;
__sfrbit(0xB1,0x07) volatile __bit T3IR;
__sfr(0xB2) volatile unsigned int T4IC;
__sfrbit(0xB2,0x06) volatile __bit T4IE;
__sfrbit(0xB2,0x07) volatile __bit T5IR;
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
__sfr(0xD1) volatile unsigned int P5;
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
__sfr(0xE0) volatile unsigned int P2;
__sfr(0xE1) volatile unsigned int DP2;
__sfr(0xE2) volatile unsigned int P3;
__sfr(0xE3) volatile unsigned int DP3;
__sfr(0xE4) volatile unsigned int P4;
__sfr(0xE5) volatile unsigned int DP4;
__sfr(0xE6) volatile unsigned int P6;
__sfr(0xE7) volatile unsigned int DP6;
__sfr(0xE8) volatile unsigned int P7;
__sfr(0xE9) volatile unsigned int DP7;
#endif
