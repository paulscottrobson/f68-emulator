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
#ifndef ST10F269_H
#define ST10F269_H
/*
 v0.2 23/09/04

 Hardware register access for the ST st10f269 device. 
 These declarations are to be used with the vbcc(c16x) compiler. 

 There may be an error in the user manual (v1.2).
 T8IC and PWMIC were located at the same 8 bit esfr address (0xBF). 
 Moved T7IC and T8IC to 0xBD and 0xBE.

 The MACTRP flag (page  67) in the TFR and IDX0 and IDX1 were
 missing in the expected places (silently adding these bits).  

 @todo reviewing and testing
*/

#define RTCCON (*((volatile unsigned int*)0x0EC00))
#define RTCPL (*((volatile unsigned int*)0xEC06))
#define RTCPH (*((volatile unsigned int*)0xEC08))
#define RTCDL (*((volatile unsigned int*)0xEC0A))
#define RTCDH (*((volatile unsigned int*)0xEC0C))
#define RTCL (*((volatile unsigned int*)0xEC0E))
#define RTCH (*((volatile unsigned int*)0xEC10))
#define RTCAL (*((volatile unsigned int*)0xEC12))
#define RTCAH (*((volatile unsigned int*)0xEC14))
#define CAN2CSR (*((volatile unsigned int*)0xEE00))
#define CAN2IR (*((volatile unsigned int*)0xEE02))
#define CAN2BTR (*((volatile unsigned int*)0xEE04))
#define CAN2GMS (*((volatile unsigned int*)0xEE06))
#define CAN2UGML (*((volatile unsigned int*)0xEE08))
#define CAN2LGML (*((volatile unsigned int*)0xEE0A))
#define CAN2UMLM (*((volatile unsigned int*)0xEE0C))
#define CAN2LMLM (*((volatile unsigned int*)0xEE0E))
#define CAN2MCR1 (*((volatile unsigned int*)0xEE10))
#define CAN2MO1 (*((volatile unsigned int*)0xEE10))
#define CAN2UAR1 (*((volatile unsigned int*)0xEE12))
#define CAN2LAR1 (*((volatile unsigned int*)0xEE14))
#define CAN2MCR2 (*((volatile unsigned int*)0xEE20))
#define CAN2MO2 (*((volatile unsigned int*)0xEE20))
#define CAN2UAR2 (*((volatile unsigned int*)0xEE22))
#define CAN2LAR2 (*((volatile unsigned int*)0xEE24))
#define CAN2MCR3 (*((volatile unsigned int*)0xEE30))
#define CAN2MO3 (*((volatile unsigned int*)0xEE30))
#define CAN2UAR3 (*((volatile unsigned int*)0xEE32))
#define CAN2LAR3 (*((volatile unsigned int*)0xEE34))
#define CAN2MCR4 (*((volatile unsigned int*)0xEE40))
#define CAN2MO4 (*((volatile unsigned int*)0xEE40))
#define CAN2UAR4 (*((volatile unsigned int*)0xEE42))
#define CAN2LAR4 (*((volatile unsigned int*)0xEE44))
#define CAN2MCR5 (*((volatile unsigned int*)0xEE50))
#define CAN2MO5 (*((volatile unsigned int*)0xEE50))
#define CAN2UAR5 (*((volatile unsigned int*)0xEE52))
#define CAN2LAR5 (*((volatile unsigned int*)0xEE54))
#define CAN2MCR6 (*((volatile unsigned int*)0xEE60))
#define CAN2MO6 (*((volatile unsigned int*)0xEE60))
#define CAN2UAR6 (*((volatile unsigned int*)0xEE62))
#define CAN2LAR6 (*((volatile unsigned int*)0xEE64))
#define CAN2MCR7 (*((volatile unsigned int*)0xEE70))
#define CAN2MO7 (*((volatile unsigned int*)0xEE70))
#define CAN2UAR7 (*((volatile unsigned int*)0xEE72))
#define CAN2LAR7 (*((volatile unsigned int*)0xEE74))
#define CAN2MCR8 (*((volatile unsigned int*)0xEE80))
#define CAN2MO8 (*((volatile unsigned int*)0xEE80))
#define CAN2UAR8 (*((volatile unsigned int*)0xEE82))
#define CAN2LAR8 (*((volatile unsigned int*)0xEE84))
#define CAN2MCR9 (*((volatile unsigned int*)0xEE90))
#define CAN2MO9 (*((volatile unsigned int*)0xEE90))
#define CAN2UAR9 (*((volatile unsigned int*)0xEE92))
#define CAN2LAR9 (*((volatile unsigned int*)0xEE94))
#define CAN2MCR10 (*((volatile unsigned int*)0xEEA0))
#define CAN2MO10 (*((volatile unsigned int*)0xEEA0))
#define CAN2UAR10 (*((volatile unsigned int*)0xEEA2))
#define CAN2LAR10 (*((volatile unsigned int*)0xEEA4))
#define CAN2MCR11 (*((volatile unsigned int*)0xEEB0))
#define CAN2MO11 (*((volatile unsigned int*)0xEEB0))
#define CAN2UAR11 (*((volatile unsigned int*)0xEEB2))
#define CAN2LAR11 (*((volatile unsigned int*)0xEEB4))
#define CAN2MCR12 (*((volatile unsigned int*)0xEEC0))
#define CAN2MO12 (*((volatile unsigned int*)0xEEC0))
#define CAN2UAR12 (*((volatile unsigned int*)0xEEC2))
#define CAN2LAR12 (*((volatile unsigned int*)0xEEC4))
#define CAN2MCR13 (*((volatile unsigned int*)0xEED0))
#define CAN2MO13 (*((volatile unsigned int*)0xEED0))
#define CAN2UAR13 (*((volatile unsigned int*)0xEED2))
#define CAN2LAR13 (*((volatile unsigned int*)0xEED4))
#define CAN2MCR14 (*((volatile unsigned int*)0xEEE0))
#define CAN2MO14 (*((volatile unsigned int*)0xEEE0))
#define CAN2UAR14 (*((volatile unsigned int*)0xEEE2))
#define CAN2LAR14 (*((volatile unsigned int*)0xEEE4))
#define CAN2MCR15 (*((volatile unsigned int*)0xEEF0))
#define CAN2MO15 (*((volatile unsigned int*)0xEEF0))
#define CAN2UAR15 (*((volatile unsigned int*)0xEEF2))
#define CAN2LAR15 (*((volatile unsigned int*)0xEEF4))
#define CAN1CSR (*((volatile unsigned int*)0xEF00))
#define CAN1IR (*((volatile unsigned int*)0xEF02))
#define CAN1BTR (*((volatile unsigned int*)0xEF04))
#define CAN1GMS (*((volatile unsigned int*)0xEF06))
#define CAN1UGML (*((volatile unsigned int*)0xEF08))
#define CAN1LGML (*((volatile unsigned int*)0xEF0A))
#define CAN1UMLM (*((volatile unsigned int*)0xEF0C))
#define CAN1LMLM (*((volatile unsigned int*)0xEF0E))
#define CAN1MCR1 (*((volatile unsigned int*)0xEF10))
#define CAN1MO1 (*((volatile unsigned int*)0xEF10))
#define CAN1UAR1 (*((volatile unsigned int*)0xEF12))
#define CAN1LAR1 (*((volatile unsigned int*)0xEF14))
#define CAN1MCR2 (*((volatile unsigned int*)0xEF20))
#define CAN1MO2 (*((volatile unsigned int*)0xEF20))
#define CAN1UAR2 (*((volatile unsigned int*)0xEF22))
#define CAN1LAR2 (*((volatile unsigned int*)0xEF24))
#define CAN1MCR3 (*((volatile unsigned int*)0xEF30))
#define CAN1MO3 (*((volatile unsigned int*)0xEF30))
#define CAN1UAR3 (*((volatile unsigned int*)0xEF32))
#define CAN1LAR3 (*((volatile unsigned int*)0xEF34))
#define CAN1MCR4 (*((volatile unsigned int*)0xEF40))
#define CAN1MO4 (*((volatile unsigned int*)0xEF40))
#define CAN1UAR4 (*((volatile unsigned int*)0xEF42))
#define CAN1LAR4 (*((volatile unsigned int*)0xEF44))
#define CAN1MCR5 (*((volatile unsigned int*)0xEF50))
#define CAN1MO5 (*((volatile unsigned int*)0xEF50))
#define CAN1UAR5 (*((volatile unsigned int*)0xEF52))
#define CAN1LAR5 (*((volatile unsigned int*)0xEF54))
#define CAN1MCR6 (*((volatile unsigned int*)0xEF60))
#define CAN1MO6 (*((volatile unsigned int*)0xEF60))
#define CAN1UAR6 (*((volatile unsigned int*)0xEF62))
#define CAN1LAR6 (*((volatile unsigned int*)0xEF64))
#define CAN1MCR7 (*((volatile unsigned int*)0xEF70))
#define CAN1MO7 (*((volatile unsigned int*)0xEF70))
#define CAN1UAR7 (*((volatile unsigned int*)0xEF72))
#define CAN1LAR7 (*((volatile unsigned int*)0xEF74))
#define CAN1MCR8 (*((volatile unsigned int*)0xEF80))
#define CAN1MO8 (*((volatile unsigned int*)0xEF80))
#define CAN1UAR8 (*((volatile unsigned int*)0xEF82))
#define CAN1LAR8 (*((volatile unsigned int*)0xEF84))
#define CAN1MCR9 (*((volatile unsigned int*)0xEF90))
#define CAN1MO9 (*((volatile unsigned int*)0xEF90))
#define CAN1UAR9 (*((volatile unsigned int*)0xEF92))
#define CAN1LAR9 (*((volatile unsigned int*)0xEF94))
#define CAN1MCR10 (*((volatile unsigned int*)0xEFA0))
#define CAN1MO10 (*((volatile unsigned int*)0xEFA0))
#define CAN1UAR10 (*((volatile unsigned int*)0xEFA2))
#define CAN1LAR10 (*((volatile unsigned int*)0xEFA4))
#define CAN1MCR11 (*((volatile unsigned int*)0xEFB0))
#define CAN1MO11 (*((volatile unsigned int*)0xEFB0))
#define CAN1UAR11 (*((volatile unsigned int*)0xEFB2))
#define CAN1LAR11 (*((volatile unsigned int*)0xEFB4))
#define CAN1MCR12 (*((volatile unsigned int*)0xEFC0))
#define CAN1MO12 (*((volatile unsigned int*)0xEFC0))
#define CAN1UAR12 (*((volatile unsigned int*)0xEFC2))
#define CAN1LAR12 (*((volatile unsigned int*)0xEFC4))
#define CAN1MCR13 (*((volatile unsigned int*)0xEFD0))
#define CAN1MO13 (*((volatile unsigned int*)0xEFD0))
#define CAN1UAR13 (*((volatile unsigned int*)0xEFD2))
#define CAN1LAR13 (*((volatile unsigned int*)0xEFD4))
#define CAN1MCR14 (*((volatile unsigned int*)0xEFE0))
#define CAN1MO14 (*((volatile unsigned int*)0xEFE0))
#define CAN1UAR14 (*((volatile unsigned int*)0xEFE2))
#define CAN1LAR14 (*((volatile unsigned int*)0xEFE4))
#define CAN1MCR15 (*((volatile unsigned int*)0xEFF0))
#define CAN1MO15 (*((volatile unsigned int*)0xEFF0))
#define CAN1UAR15 (*((volatile unsigned int*)0xEFF2))
#define CAN1LAR15 (*((volatile unsigned int*)0xEFF4))
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

__esfr(0x00) volatile unsigned int QX0;
__esfr(0x01) volatile unsigned int QX1;
__esfr(0x02) volatile unsigned int QR0;
__esfr(0x03) volatile unsigned int QR1;
__esfr(0x12) volatile unsigned int XPERCON;
__esfrbit(0x12,0x00) volatile __bit CAN1EN;
__esfrbit(0x12,0x01) volatile __bit CAN2EN;
__esfrbit(0x12,0x02) volatile __bit XRAM1EN;
__esfrbit(0x12,0x03) volatile __bit XRAM2EN;
__esfrbit(0x12,0x04) volatile __bit RTCEN;
__esfr(0x18) volatile unsigned int PT0;
__esfr(0x19) volatile unsigned int PT1;
__esfr(0x1A) volatile unsigned int PT2;
__esfr(0x1B) volatile unsigned int PT3;
__esfr(0x1C) volatile unsigned int PP0;
__esfr(0x1D) volatile unsigned int PP1;
__esfr(0x1E) volatile unsigned int PP2;
__esfr(0x1F) volatile unsigned int PP3;
__esfr(0x28) volatile unsigned int T7;
__esfr(0x29) volatile unsigned int T8;
__esfr(0x2A) volatile unsigned int T7REL;
__esfr(0x2B) volatile unsigned int T8REL;
__esfr(0x3C) volatile unsigned int IDPROG;
__esfr(0x3D) volatile unsigned int IDMEM;
__esfr(0x3E) volatile unsigned int IDCHIP;
__esfr(0x3F) volatile unsigned int IDMANUF;
__esfr(0x40) volatile unsigned int POCON0L;
__esfr(0x41) volatile unsigned int POCON0H;
__esfr(0x42) volatile unsigned int POCON1L;
__esfr(0x43) volatile unsigned int POCON1H;
__esfr(0x44) volatile unsigned int POCON2;
__esfr(0x45) volatile unsigned int POCON3;
__esfr(0x46) volatile unsigned int POCON4;
__esfr(0x47) volatile unsigned int POCON6;
__esfr(0x48) volatile unsigned int POCON7;
__esfr(0x49) volatile unsigned int POCON8;
__esfr(0x50) volatile unsigned int ADDAT2;
__esfr(0x55) volatile unsigned int POCON20;
__esfr(0x58) volatile unsigned int SSCTB;
__esfr(0x59) volatile unsigned int SSCRB;
__esfr(0x5A) volatile unsigned int SSCBR;
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
__esfr(0xB4) volatile unsigned int CC20IC;
__esfrbit(0xB4,0x06) volatile __bit CC20IE;
__esfrbit(0xB4,0x07) volatile __bit CC20IR;
__esfr(0xB5) volatile unsigned int CC21IC;
__esfrbit(0xB5,0x06) volatile __bit CC21IE;
__esfrbit(0xB5,0x07) volatile __bit CC21IR;
__esfr(0xB6) volatile unsigned int CC22IC;
__esfrbit(0xB6,0x06) volatile __bit CC22IE;
__esfrbit(0xB6,0x07) volatile __bit CC22IR;
__esfr(0xB7) volatile unsigned int CC23IC;
__esfrbit(0xB7,0x06) volatile __bit CC23IE;
__esfrbit(0xB7,0x07) volatile __bit CC23IR;
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
__esfr(0xBC) volatile unsigned int CC28IC;
__esfrbit(0xBC,0x06) volatile __bit CC28IE;
__esfrbit(0xBC,0x07) volatile __bit CC28IR;
__esfr(0xBD) volatile unsigned int T7IC;
__esfrbit(0xBD,0x06) volatile __bit T7IE;
__esfrbit(0xBD,0x07) volatile __bit T7IR;
__esfr(0xBE) volatile unsigned int T8IC;
__esfrbit(0xBE,0x06) volatile __bit T8IE;
__esfrbit(0xBE,0x07) volatile __bit T8IR;
__esfr(0xBF) volatile unsigned int PWMIC;
__esfrbit(0xBF,0x06) volatile __bit PWMIE;
__esfrbit(0xBF,0x07) volatile __bit PWMIR;
__esfr(0xC2) volatile unsigned int CC29IC;
__esfrbit(0xC2,0x06) volatile __bit CC29IE;
__esfrbit(0xC2,0x07) volatile __bit CC29IR;
__esfr(0xC3) volatile unsigned int XP0IC;
__esfrbit(0xC3,0x06) volatile __bit XP0IE;
__esfrbit(0xC3,0x07) volatile __bit XP0IR;
__esfr(0xC6) volatile unsigned int CC30IC;
__esfrbit(0xC6,0x06) volatile __bit CC30IE;
__esfrbit(0xC6,0x07) volatile __bit CC30IR;
__esfr(0xC7) volatile unsigned int XP1IC;
__esfrbit(0xC7,0x06) volatile __bit XP1IE;
__esfrbit(0xC7,0x07) volatile __bit XP1IR;
__esfr(0xCA) volatile unsigned int CC31IC;
__esfrbit(0xCA,0x06) volatile __bit CC31IE;
__esfrbit(0xCA,0x07) volatile __bit CC31IR;
__esfr(0xCB) volatile unsigned int XP2IC;
__esfrbit(0xCB,0x06) volatile __bit XP2IE;
__esfrbit(0xCB,0x07) volatile __bit XP2IR;
__esfr(0xCE) volatile unsigned int S0TBIC;
__esfrbit(0xCE,0x06) volatile __bit S0TBIE;
__esfrbit(0xCE,0x07) volatile __bit S0TBIR;
__esfr(0xCF) volatile unsigned int XP3IC;
__esfrbit(0xCF,0x06) volatile __bit XP3IE;
__esfrbit(0xCF,0x07) volatile __bit XP3IR;
__esfr(0xE0) volatile unsigned int EXICON;
__esfr(0xE1) volatile unsigned int ODP2;
__esfr(0xE2) volatile unsigned int PICON;
__esfrbit(0xE2,0x00) volatile __bit P2LIN;
__esfrbit(0xE2,0x01) volatile __bit P2HIN;
__esfrbit(0xE2,0x02) volatile __bit P3LIN;
__esfrbit(0xE2,0x03) volatile __bit P3HIN;
__esfrbit(0xE2,0x04) volatile __bit P4LIN;
__esfrbit(0xE2,0x06) volatile __bit P7LIN;
__esfrbit(0xE2,0x07) volatile __bit P8LIN;
__esfr(0xE3) volatile unsigned int ODP3;
__esfr(0xE5) volatile unsigned int ODP4;
__esfr(0xE7) volatile unsigned int ODP6;
__esfr(0xE9) volatile unsigned int ODP7;
__esfr(0xEB) volatile unsigned int ODP8;
__esfr(0xED) volatile unsigned int EXISEL;

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
__sfr(0x18) volatile unsigned int PW0;
__sfr(0x19) volatile unsigned int PW1;
__sfr(0x1A) volatile unsigned int PW2;
__sfr(0x1B) volatile unsigned int PW3;
__sfr(0x20) volatile unsigned int T2;
__sfr(0x21) volatile unsigned int T3;
__sfr(0x22) volatile unsigned int T4;
__sfr(0x23) volatile unsigned int T5;
__sfr(0x24) volatile unsigned int T6;
__sfr(0x25) volatile unsigned int CAPREL;
__sfr(0x28) volatile unsigned int T0;
__sfr(0x29) volatile unsigned int T1;
__sfr(0x2A) volatile unsigned int T0REL;
__sfr(0x2B) volatile unsigned int T1REL;
__sfr(0x2E) volatile unsigned int MAL;
__sfr(0x2F) volatile unsigned int MAH;
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
__sfr(0x40) volatile unsigned int CC0;
__sfr(0x41) volatile unsigned int CC1;
__sfr(0x42) volatile unsigned int CC2;
__sfr(0x43) volatile unsigned int CC3;
__sfr(0x44) volatile unsigned int CC4;
__sfr(0x45) volatile unsigned int CC5;
__sfr(0x46) volatile unsigned int CC6;
__sfr(0x47) volatile unsigned int CC7;
__sfr(0x48) volatile unsigned int CC8;
__sfr(0x49) volatile unsigned int CC9;
__sfr(0x4A) volatile unsigned int CC10;
__sfr(0x4B) volatile unsigned int CC11;
__sfr(0x4C) volatile unsigned int CC12;
__sfr(0x4D) volatile unsigned int CC13;
__sfr(0x4E) volatile unsigned int CC14;
__sfr(0x4F) volatile unsigned int CC15;
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
__sfr(0x84) volatile unsigned int IDX0;
__sfr(0x85) volatile unsigned int IDX1;
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
__sfr(0x90) volatile unsigned int T78CON;
__sfrbit(0x90,0x03) volatile __bit T7M;
__sfrbit(0x90,0x06) volatile __bit T7R;
__sfrbit(0x90,0x0B) volatile __bit T8M;
__sfrbit(0x90,0x0E) volatile __bit T8R;
__sfr(0x91) volatile unsigned int CCM4;
__sfrbit(0x91,0x03) volatile __bit ACC16;
__sfrbit(0x91,0x07) volatile __bit ACC17;
__sfrbit(0x91,0x0B) volatile __bit ACC18;
__sfrbit(0x91,0x0F) volatile __bit ACC19;
__sfr(0x92) volatile unsigned int CCM5;
__sfrbit(0x92,0x03) volatile __bit ACC20;
__sfrbit(0x92,0x07) volatile __bit ACC21;
__sfrbit(0x92,0x0B) volatile __bit ACC22;
__sfrbit(0x92,0x0F) volatile __bit ACC23;
__sfr(0x93) volatile unsigned int CCM6;
__sfrbit(0x93,0x03) volatile __bit ACC24;
__sfrbit(0x93,0x07) volatile __bit ACC25;
__sfrbit(0x93,0x0B) volatile __bit ACC26;
__sfrbit(0x93,0x0F) volatile __bit ACC27;
__sfr(0x94) volatile unsigned int CCM7;
__sfrbit(0x94,0x03) volatile __bit ACC28;
__sfrbit(0x94,0x07) volatile __bit ACC29;
__sfrbit(0x94,0x0B) volatile __bit ACC30;
__sfrbit(0x94,0x0F) volatile __bit ACC31;
__sfr(0x98) volatile unsigned int PWMCON0;
__sfrbit(0x98,0x00) volatile __bit PTR0;
__sfrbit(0x98,0x01) volatile __bit PTR1;
__sfrbit(0x98,0x02) volatile __bit PTR2;
__sfrbit(0x98,0x03) volatile __bit PTR3;
__sfrbit(0x98,0x04) volatile __bit PTI0;
__sfrbit(0x98,0x05) volatile __bit PTI1;
__sfrbit(0x98,0x06) volatile __bit PTI2;
__sfrbit(0x98,0x07) volatile __bit PTI3;
__sfrbit(0x98,0x08) volatile __bit PIE0;
__sfrbit(0x98,0x09) volatile __bit PIE1;
__sfrbit(0x98,0x0A) volatile __bit PIE2;
__sfrbit(0x98,0x0B) volatile __bit PIE3;
__sfrbit(0x98,0x0C) volatile __bit PIR0;
__sfrbit(0x98,0x0D) volatile __bit PIR1;
__sfrbit(0x98,0x0E) volatile __bit PIR2;
__sfrbit(0x98,0x0F) volatile __bit PIR3;
__sfr(0x99) volatile unsigned int PWMCON1;
__sfrbit(0x99,0x00) volatile __bit PEN0;
__sfrbit(0x99,0x01) volatile __bit PEN1;
__sfrbit(0x99,0x02) volatile __bit PEN2;
__sfrbit(0x99,0x03) volatile __bit PEN3;
__sfrbit(0x99,0x04) volatile __bit PM0;
__sfrbit(0x99,0x05) volatile __bit PM1;
__sfrbit(0x99,0x06) volatile __bit PM2;
__sfrbit(0x99,0x07) volatile __bit PM3;
__sfrbit(0x99,0x0C) volatile __bit PB01;
__sfrbit(0x99,0x0E) volatile __bit PS2;
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
__sfrbit(0xA3,0x09) volatile __bit CT3;
__sfrbit(0xA3,0x0E) volatile __bit T5CLR;
__sfrbit(0xA3,0x0F) volatile __bit T5SC;
__sfr(0xA4) volatile unsigned int T6CON;
__sfrbit(0xA4,0x06) volatile __bit T6R;
__sfrbit(0xA4,0x07) volatile __bit T6UD;
__sfrbit(0xA4,0x08) volatile __bit T6UDE;
__sfrbit(0xA4,0x09) volatile __bit T6OE;
__sfrbit(0xA4,0x0A) volatile __bit T6OTL;
__sfrbit(0xA4,0x0F) volatile __bit T6SR;
__sfr(0xA8) volatile unsigned int T01CON;
__sfrbit(0xA8,0x03) volatile __bit T0M;
__sfrbit(0xA8,0x06) volatile __bit T0R;
__sfrbit(0xA8,0x0B) volatile __bit T1M;
__sfrbit(0xA8,0x0E) volatile __bit T1R;
__sfr(0xA9) volatile unsigned int CCM0;
__sfrbit(0xA9,0x03) volatile __bit ACC0;
__sfrbit(0xA9,0x07) volatile __bit ACC1;
__sfrbit(0xA9,0x0B) volatile __bit ACC2;
__sfrbit(0xA9,0x0F) volatile __bit ACC3;
__sfr(0xAA) volatile unsigned int CCM1;
__sfrbit(0xAA,0x03) volatile __bit ACC4;
__sfrbit(0xAA,0x07) volatile __bit ACC5;
__sfrbit(0xAA,0x0B) volatile __bit ACC6;
__sfrbit(0xAA,0x0F) volatile __bit ACC7;
__sfr(0xAB) volatile unsigned int CCM2;
__sfrbit(0xAB,0x03) volatile __bit ACC8;
__sfrbit(0xAB,0x07) volatile __bit ACC9;
__sfrbit(0xAB,0x0B) volatile __bit ACC10;
__sfrbit(0xAB,0x0F) volatile __bit ACC11;
__sfr(0xAC) volatile unsigned int CCM3;
__sfrbit(0xAC,0x03) volatile __bit ACC12;
__sfrbit(0xAC,0x07) volatile __bit ACC13;
__sfrbit(0xAC,0x0B) volatile __bit ACC14;
__sfrbit(0xAC,0x0F) volatile __bit ACC15;
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
__sfr(0xB9) volatile unsigned int SSCTIC;
__sfrbit(0xB9,0x06) volatile __bit SSCTIE;
__sfrbit(0xB9,0x07) volatile __bit SSCTIR;
__sfr(0xBA) volatile unsigned int SSCRIC;
__sfrbit(0xBA,0x06) volatile __bit SSCRIE;
__sfrbit(0xBA,0x07) volatile __bit SSCRIR;
__sfr(0xBB) volatile unsigned int SSCEIC;
__sfrbit(0xBB,0x06) volatile __bit SSCEIE;
__sfrbit(0xBB,0x07) volatile __bit SSCEIR;
__sfr(0xBC) volatile unsigned int CC0IC;
__sfrbit(0xBC,0x06) volatile __bit CC0IE;
__sfrbit(0xBC,0x07) volatile __bit CC0IR;
__sfr(0xBD) volatile unsigned int CC1IC;
__sfrbit(0xBD,0x06) volatile __bit CC1IE;
__sfrbit(0xBD,0x07) volatile __bit CC1IR;
__sfr(0xBE) volatile unsigned int CC2IC;
__sfrbit(0xBE,0x06) volatile __bit CC2IE;
__sfrbit(0xBE,0x07) volatile __bit CC2IR;
__sfr(0xBF) volatile unsigned int CC3IC;
__sfrbit(0xBF,0x06) volatile __bit CC3IE;
__sfrbit(0xBF,0x07) volatile __bit CC3IR;
__sfr(0xC0) volatile unsigned int CC4IC;
__sfrbit(0xC0,0x06) volatile __bit CC4IE;
__sfrbit(0xC0,0x07) volatile __bit CC4IR;
__sfr(0xC1) volatile unsigned int CC5IC;
__sfrbit(0xC1,0x06) volatile __bit CC5IE;
__sfrbit(0xC1,0x07) volatile __bit CC5IR;
__sfr(0xC2) volatile unsigned int CC6IC;
__sfrbit(0xC2,0x06) volatile __bit CC6IE;
__sfrbit(0xC2,0x07) volatile __bit CC6IR;
__sfr(0xC3) volatile unsigned int CC7IC;
__sfrbit(0xC3,0x06) volatile __bit CC7IE;
__sfrbit(0xC3,0x07) volatile __bit CC7IR;
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
__sfr(0xC8) volatile unsigned int CC12IC;
__sfrbit(0xC8,0x06) volatile __bit CC12IE;
__sfrbit(0xC8,0x07) volatile __bit CC12IR;
__sfr(0xC9) volatile unsigned int CC13IC;
__sfrbit(0xC9,0x06) volatile __bit CC13IE;
__sfrbit(0xC9,0x07) volatile __bit CC13IR;
__sfr(0xCA) volatile unsigned int CC14IC;
__sfrbit(0xCA,0x06) volatile __bit CC14IE;
__sfrbit(0xCA,0x07) volatile __bit CC14IR;
__sfr(0xCB) volatile unsigned int CC15IC;
__sfrbit(0xCB,0x06) volatile __bit CC15IE;
__sfrbit(0xCB,0x07) volatile __bit CC15IR;
__sfr(0xCC) volatile unsigned int ADCIC;
__sfrbit(0xCC,0x06) volatile __bit ADCIE;
__sfrbit(0xCC,0x07) volatile __bit ADCIR;
__sfr(0xCD) volatile unsigned int ADEIC;
__sfrbit(0xCD,0x06) volatile __bit ADEIE;
__sfrbit(0xCD,0x07) volatile __bit ADEIR;
__sfr(0xCE) volatile unsigned int T0IC;
__sfrbit(0xCE,0x06) volatile __bit T0IE;
__sfrbit(0xCE,0x07) volatile __bit T0IR;
__sfr(0xCF) volatile unsigned int T1IC;
__sfrbit(0xCF,0x06) volatile __bit T1IE;
__sfrbit(0xCF,0x07) volatile __bit T1IR;
__sfr(0xD0) volatile unsigned int ADCON;
__sfrbit(0xD0,0x07) volatile __bit ADST;
__sfrbit(0xD0,0x08) volatile __bit ADBSY;
__sfrbit(0xD0,0x09) volatile __bit ADWR;
__sfrbit(0xD0,0x0A) volatile __bit ADCIN;
__sfrbit(0xD0,0x0B) volatile __bit ADCRQ;
__sfr(0xD1) volatile unsigned int P5;
__sfr(0xD2) volatile unsigned int P5DIDIS;
__sfr(0xD6) volatile unsigned int TFR;
__sfrbit(0xD6,0x00) volatile __bit ILLBUS;
__sfrbit(0xD6,0x01) volatile __bit ILLINA;
__sfrbit(0xD6,0x02) volatile __bit ILLOPA;
__sfrbit(0xD6,0x03) volatile __bit PRTFLT;
__sfrbit(0xD6,0x06) volatile __bit MACTRP;
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
__sfrbit(0xD7,0x05) volatile __bit PONR;
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
__sfr(0xEA) volatile unsigned int P8;
__sfr(0xEB) volatile unsigned int DP8;
__sfr(0xED) volatile unsigned int MRW;
__sfr(0xEE) volatile unsigned int MCW;
__sfrbit(0xEE,0x09) volatile __bit MCWMS;
__sfrbit(0xEE,0x0A) volatile __bit MCWMP;
__sfrbit(0xEE,0x0B) volatile __bit MCWCM;
__sfrbit(0xEE,0x0C) volatile __bit MCWVM;
__sfrbit(0xEE,0x0D) volatile __bit MCWEM;
__sfrbit(0xEE,0x0E) volatile __bit MCWLM;
__sfrbit(0xEE,0x0F) volatile __bit MIE;
__sfr(0xEF) volatile unsigned int MSW;
__sfrbit(0xEF,0x08) volatile __bit MSWN;
__sfrbit(0xEF,0x09) volatile __bit MSWZ;
__sfrbit(0xEF,0x0A) volatile __bit MSWC;
__sfrbit(0xEF,0x0B) volatile __bit MSWSV;
__sfrbit(0xEF,0x0C) volatile __bit MSWE;
__sfrbit(0xEF,0x0D) volatile __bit MSWSL;
__sfrbit(0xEF,0x0F) volatile __bit MIR;
#endif
