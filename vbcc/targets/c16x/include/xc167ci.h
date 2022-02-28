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
#ifndef XC167CI_H
#define XC167CI_H
/*
 v0.1 07/12/04

 Hardware register access for the Infineon xc167ci device. 
 These functions are to be used with the vbcc(c16x) compiler. 

 @todo bits, SDLC, CAN and reviewing this.
*/

#define IIC_CFG (*((volatile unsigned int*)0xE600))
#define IIC_CON (*((volatile unsigned int*)0xE602))
#define IIC_ST (*((volatile unsigned int*)0xE604))
#define IIC_ADR (*((volatile unsigned int*)0xE606))
#define IIC_RTBL (*((volatile unsigned int*)0xE608))
#define IIC_RTBH (*((volatile unsigned int*)0xE60A))
#define CCU6_T12 (*((volatile unsigned int*)0xE890))
#define CCU6_T12PR (*((volatile unsigned int*)0xE892))
#define CCU6_T12DTC (*((volatile unsigned int*)0xE894))
#define CCU6_CC60R (*((volatile unsigned int*)0xE898))
#define CCU6_CC61R (*((volatile unsigned int*)0xE89A))
#define CCU6_CC62R (*((volatile unsigned int*)0xE89C))
#define CCU6_CC60SR (*((volatile unsigned int*)0xE8A0))
#define CCU6_CC61SR (*((volatile unsigned int*)0xE8A2))
#define CCU6_CC62SR (*((volatile unsigned int*)0xE8A4))
#define CCU6_TCTR4 (*((volatile unsigned int*)0xE8A6))
#define CCU6_CMPSTAT (*((volatile unsigned int*)0xE8A8))
#define CCU6_CMPMODIF (*((volatile unsigned int*)0xE8AA))
#define CCU6_TCTR0 (*((volatile unsigned int*)0xE8AC))
#define CCU6_TCTR2 (*((volatile unsigned int*)0xE8AE))
#define CCU6_T13 (*((volatile unsigned int*)0xE8B0))
#define CCU6_T13PR (*((volatile unsigned int*)0xE8B2))
#define CCU6_CC63R (*((volatile unsigned int*)0xE8B4))
#define CCU6_CC63SR (*((volatile unsigned int*)0xE8B6))
#define CCU6_MODCTR (*((volatile unsigned int*)0xE8C0))
#define CCU6_TRPCTR (*((volatile unsigned int*)0xE8C2))
#define CCU6_PSLR (*((volatile unsigned int*)0xE8C4))
#define CCU6_T12MSEL (*((volatile unsigned int*)0xE8C6))
#define CCU6_MCMOUTS (*((volatile unsigned int*)0xE8CA))
#define CCU6_MCMOUT (*((volatile unsigned int*)0xE8CC))
#define CCU6_MCMCTR (*((volatile unsigned int*)0xE8CE))
#define CCU6_IS (*((volatile unsigned int*)0xE8D0))
#define CCU6_ISS (*((volatile unsigned int*)0xE8D2))
#define CCU6_ISR (*((volatile unsigned int*)0xE8D4))
#define CCU6_INP (*((volatile unsigned int*)0xE8D6)
#define CCU6_IEN (*((volatile unsigned int*)0xE8D8))
#define FINT0CSP (*((volatile unsigned int*)0xEC00))
#define FINT0ADDR (*((volatile unsigned int*)0xEC02))
#define FINT1CSP (*((volatile unsigned int*)0xEC04))
#define FINT1ADDR (*((volatile unsigned int*)0xEC06))
#define BNKSEL0 (*((volatile unsigned int*)0xEC20))
#define BNKSEL1 (*((volatile unsigned int*)0xEC22))
#define BNKSEL2 (*((volatile unsigned int*)0xEC24))
#define BNKSEL3 (*((volatile unsigned int*)0xEC26))
#define SRCP0 (*((volatile unsigned int*)0xEC40))
#define DSTP0 (*((volatile unsigned int*)0xEC42))
#define SRCP1 (*((volatile unsigned int*)0xEC44))
#define DSTP1 (*((volatile unsigned int*)0xEC46))
#define SRCP2 (*((volatile unsigned int*)0xEC48))
#define DSTP2 (*((volatile unsigned int*)0xEC4A))
#define SRCP3 (*((volatile unsigned int*)0xEC4C))
#define DSTP3 (*((volatile unsigned int*)0xEC4E))
#define SRCP4 (*((volatile unsigned int*)0xEC50))
#define DSTP4 (*((volatile unsigned int*)0xEC52))
#define SRCP5 (*((volatile unsigned int*)0xEC54))
#define DSTP5 (*((volatile unsigned int*)0xEC56))
#define SRCP6 (*((volatile unsigned int*)0xEC58))
#define DSTP6 (*((volatile unsigned int*)0xEC5A))
#define SRCP7 (*((volatile unsigned int*)0xEC5C))
#define DSTP7 (*((volatile unsigned int*)0xEC5E))
#define PECSEG0 (*((volatile unsigned int*)0xEC80))
#define PECSEG1 (*((volatile unsigned int*)0xEC82))
#define PECSEG2 (*((volatile unsigned int*)0xEC84))
#define PECSEG3 (*((volatile unsigned int*)0xEC86))
#define PECSEG4 (*((volatile unsigned int*)0xEC88))
#define PECSEG5 (*((volatile unsigned int*)0xEC8A))
#define PECSEG6 (*((volatile unsigned int*)0xEC8C))
#define PECSEG7 (*((volatile unsigned int*)0xEC8E))
#define EBCMOD0 (*((volatile unsigned int*)0xEE00))
#define EBCMOD1 (*((volatile unsigned int*)0xEE02))
#define TCONCSMM (*((volatile unsigned int*)0xEE0C))
#define TCONCSSM (*((volatile unsigned int*)0xEE0E))
#define TCONCS0 (*((volatile unsigned int*)0xEE10))
#define FCONCS0 (*((volatile unsigned int*)0xEE12))
#define TCONCS1 (*((volatile unsigned int*)0xEE18))
#define FCONCS1 (*((volatile unsigned int*)0xEE1A))
#define ADDRSEL1 (*((volatile unsigned int*)0xEE1E))
#define TCONCS2 (*((volatile unsigned int*)0xEE20))
#define FCONCS2 (*((volatile unsigned int*)0xEE22))
#define ADDRSEL2 (*((volatile unsigned int*)0xEE26))
#define TCONCS3 (*((volatile unsigned int*)0xEE28))
#define FCONCS3 (*((volatile unsigned int*)0xEE2A))
#define ADDRSEL3 (*((volatile unsigned int*)0xEE2E))
#define TCONCS4 (*((volatile unsigned int*)0xEE30))
#define FCONCS4 (*((volatile unsigned int*)0xEE32))
#define ADDRSEL4 (*((volatile unsigned int*)0xEE36))
#define TCONCS5 (*((volatile unsigned int*)0xEE38))
#define FCONCS5 (*((volatile unsigned int*)0xEE3A))
#define ADDRSEL5 (*((volatile unsigned int*)0xEE3E))
#define TCONCS6 (*((volatile unsigned int*)0xEE40))
#define FCONCS6 (*((volatile unsigned int*)0xEE42))
#define ADDRSEL6 (*((volatile unsigned int*)0xEE46))
#define TCONCS7 (*((volatile unsigned int*)0xEE48))
#define FCONCS7 (*((volatile unsigned int*)0xEE4A))
#define ADDRSEL7 (*((volatile unsigned int*)0xEE4E))

__esfr(0x00) volatile unsigned int QX0;
__esfr(0x01) volatile unsigned int QX1;
__esfr(0x02) volatile unsigned int QR0;
__esfr(0x03) volatile unsigned int QR1;
__esfr(0x28) volatile unsigned int CC2_T7;
__esfr(0x29) volatile unsigned int CC2_T8;
__esfr(0x2A) volatile unsigned int CC2_T7REL;
__esfr(0x2B) volatile unsigned int CC2_T8REL;
__esfr(0x2D) volatile unsigned int SSC1_TB;
__esfr(0x2E) volatile unsigned int SSC1_RB;
__esfr(0x2F) volatile unsigned int SSC1_BR;
__esfr(0x31) volatile unsigned int CC1_IOC;
__esfrbit(0x31,0x01) volatile __bit CC1_PL;
__esfrbit(0x31,0x02) volatile __bit CC1_STAG;
__esfr(0x33) volatile unsigned int CC2_IOC;
__esfrbit(0x33,0x01) volatile __bit CC2_PL;
__esfrbit(0x33,0x02) volatile __bit CC2_STAG;
__esfr(0x40) volatile unsigned int POCON0L;
__esfr(0x41) volatile unsigned int POCON0H;
__esfr(0x42) volatile unsigned int POCON1L;
__esfr(0x43) volatile unsigned int POCON1H;
__esfr(0x45) volatile unsigned int POCON3;
__esfr(0x46) volatile unsigned int POCON4;
__esfr(0x4A) volatile unsigned int POCON9;
__esfr(0x4E) volatile unsigned int ADC_CTR2;
__esfr(0x4F) volatile unsigned int ADC_CTR2IN;
__esfr(0x50) volatile unsigned int ADC_DAT2;
__esfr(0x52) volatile unsigned int ASC1_TXFCON;
__esfrbit(0x52,0x00) volatile __bit ASC1_TXFEN;
__esfrbit(0x52,0x01) volatile __bit ASC1_TXFFLU;
__esfrbit(0x52,0x02) volatile __bit ASC1_TXTMEN;
__esfr(0x53) volatile unsigned int ASC1_RXFCON;
__esfrbit(0x53,0x00) volatile __bit ASC1_RXFEN;
__esfrbit(0x53,0x01) volatile __bit ASC1_RXFFLU;
__esfrbit(0x53,0x02) volatile __bit ASC1_RXTMEN;
__esfr(0x55) volatile unsigned int POCON20;
__esfr(0x58) volatile unsigned int SSC0_TB;
__esfr(0x59) volatile unsigned int SSC0_RB;
__esfr(0x5A) volatile unsigned int SSC0_BR;
__esfr(0x5C) volatile unsigned int ASC0_ABSTAT;
__esfrbit(0x5C,0x00) volatile __bit ASC0_FCSDET;
__esfrbit(0x5C,0x01) volatile __bit ASC0_FCCDET;
__esfrbit(0x5C,0x02) volatile __bit ASC0_SCSDET;
__esfrbit(0x5C,0x03) volatile __bit ASC0_SCCDET;
__esfrbit(0x5C,0x04) volatile __bit ASC0_DETWAIT;
__esfr(0x5D) volatile unsigned int ASC0_FSTAT;
__esfr(0x5E) volatile unsigned int ASC1_ABSTAT;
__esfrbit(0x5E,0x00) volatile __bit ASC1_FCSDET;
__esfrbit(0x5E,0x01) volatile __bit ASC1_FCCDET;
__esfrbit(0x5E,0x02) volatile __bit ASC1_SCSDET;
__esfrbit(0x5E,0x03) volatile __bit ASC1_SCCDET;
__esfrbit(0x5E,0x04) volatile __bit ASC1_DETWAIT;
__esfr(0x5F) volatile unsigned int ASC1_FSTAT;
__esfr(0x62) volatile unsigned int ASC0_TXFCON;
__esfrbit(0x62,0x00) volatile __bit ASC0_TXFEN;
__esfrbit(0x62,0x01) volatile __bit ASC0_TXFFLU;
__esfrbit(0x62,0x02) volatile __bit ASC0_TXTMEN;
__esfr(0x63) volatile unsigned int ASC0_RXFCON;
__esfrbit(0x63,0x00) volatile __bit ASC0_RXFEN;
__esfrbit(0x63,0x01) volatile __bit ASC0_RXFFLU;
__esfrbit(0x63,0x02) volatile __bit ASC0_RXTMEN;
__esfr(0x66) volatile unsigned int RTC_RELL;
__esfr(0x67) volatile unsigned int RTC_RELH;
__esfr(0x68) volatile unsigned int RTC_T14REL;
__esfr(0x69) volatile unsigned int RTC_T14;
__esfr(0x6A) volatile unsigned int RTC_RTCL;
__esfr(0x6B) volatile unsigned int RTC_RTCH;
__esfr(0x80) volatile unsigned int DP0L;
__esfr(0x81) volatile unsigned int DP0H;
__esfr(0x82) volatile unsigned int DP1L;
__esfr(0x83) volatile unsigned int DP1H;
__esfr(0x86) volatile unsigned int RTC_ISNC;
__esfrbit(0x86,0x00) volatile __bit T14IE;
__esfrbit(0x86,0x01) volatile __bit T14IR;
__esfrbit(0x86,0x02) volatile __bit CNT0IE;
__esfrbit(0x86,0x03) volatile __bit CNT0IR;
__esfrbit(0x86,0x04) volatile __bit CNT1IE;
__esfrbit(0x86,0x05) volatile __bit CNT1IR;
__esfrbit(0x86,0x06) volatile __bit CNT2IE;
__esfrbit(0x86,0x07) volatile __bit CNT2IR;
__esfrbit(0x86,0x08) volatile __bit CNT3IE;
__esfrbit(0x86,0x09) volatile __bit CNT3IR;
__esfr(0x88) volatile unsigned int RTC_CON;
__esfrbit(0x88,0x00) volatile __bit RTC_RUN;
__esfrbit(0x88,0x01) volatile __bit RTC_PRE;
__esfrbit(0x88,0x02) volatile __bit T14DEC;
__esfrbit(0x88,0x03) volatile __bit T14INC;
__esfrbit(0x88,0x04) volatile __bit REFCLK;
__esfrbit(0x88,0x0F) volatile __bit ACCPOS;
__esfr(0x90) volatile unsigned int ALTSEL0P1H;
__esfr(0x93) volatile unsigned int ALTSEL0P3;
__esfr(0x94) volatile unsigned int ALTSEL1P3;
__esfr(0x95) volatile unsigned int ALTSEL0P4;
__esfr(0x98) volatile unsigned int ALTSEL0P1L;
__esfr(0x9B) volatile unsigned int ALTSEL1P4;
__esfr(0x9C) volatile unsigned int ALTSEL0P9;
__esfr(0x9D) volatile unsigned int ALTSEL1P9;
__esfr(0xA0) volatile unsigned int CCU6_IC;
__esfrbit(0xA0,0x06) volatile __bit CCU6_ICIE;
__esfrbit(0xA0,0x07) volatile __bit CCU6_ICIR;
__esfr(0xA1) volatile unsigned int CAN_1IC;
__esfr(0xA2) volatile unsigned int CAN_2IC;
__esfr(0xA3) volatile unsigned int CAN_3IC;
__esfr(0xA4) volatile unsigned int CAN_4IC;
__esfr(0xA5) volatile unsigned int CAN_5IC;
__esfr(0xA6) volatile unsigned int CAN_6IC;
__esfr(0xA7) volatile unsigned int CAN_7IC;
__esfr(0xA8) volatile unsigned int ASC1_TBIC;
__esfrbit(0xA8,0x06) volatile __bit ASC1_TBIE;
__esfrbit(0xA8,0x07) volatile __bit ASC1_TBIR;
__esfr(0xAE) volatile unsigned int ASC0_ABIC;
__esfrbit(0xAE,0x06) volatile __bit ASC0_ABIE;
__esfrbit(0xAE,0x07) volatile __bit ASC0_ABIR;
__esfr(0xB0) volatile unsigned int CC2_CC16IC;
__esfrbit(0xB0,0x06) volatile __bit CC2_CC16IE;
__esfrbit(0xB0,0x07) volatile __bit CC2_CC16IR;
__esfr(0xB1) volatile unsigned int CC2_CC17IC;
__esfrbit(0xB1,0x06) volatile __bit CC2_CC17IE;
__esfrbit(0xB1,0x07) volatile __bit CC2_CC17IR;
__esfr(0xB2) volatile unsigned int CC2_CC18IC;
__esfrbit(0xB2,0x06) volatile __bit CC2_CC18IE;
__esfrbit(0xB2,0x07) volatile __bit CC2_CC18IR;
__esfr(0xB3) volatile unsigned int CC2_CC19IC;
__esfrbit(0xB3,0x06) volatile __bit CC2_CC19IE;
__esfrbit(0xB3,0x07) volatile __bit CC2_CC19IR;
__esfr(0xB4) volatile unsigned int CC2_CC20IC;
__esfrbit(0xB4,0x06) volatile __bit CC2_CC20IE;
__esfrbit(0xB4,0x07) volatile __bit CC2_CC20IR;
__esfr(0xB5) volatile unsigned int CC2_CC21IC;
__esfrbit(0xB5,0x06) volatile __bit CC2_CC21IE;
__esfrbit(0xB5,0x07) volatile __bit CC2_CC21IR;
__esfr(0xB6) volatile unsigned int CC2_CC22IC;
__esfrbit(0xB6,0x06) volatile __bit CC2_CC22IE;
__esfrbit(0xB6,0x07) volatile __bit CC2_CC22IR;
__esfr(0xB7) volatile unsigned int CC2_CC23IC;
__esfrbit(0xB7,0x06) volatile __bit CC2_CC23IE;
__esfrbit(0xB7,0x07) volatile __bit CC2_CC23IR;
__esfr(0xB8) volatile unsigned int CC2_CC24IC;
__esfrbit(0xB8,0x06) volatile __bit CC2_CC24IE;
__esfrbit(0xB8,0x07) volatile __bit CC2_CC24IR;
__esfr(0xB9) volatile unsigned int CC2_CC25IC;
__esfrbit(0xB9,0x06) volatile __bit CC2_CC25IE;
__esfrbit(0xB9,0x07) volatile __bit CC2_CC25IR;
__esfr(0xBA) volatile unsigned int CC2_CC26IC;
__esfrbit(0xBA,0x06) volatile __bit CC2_CC26IE;
__esfrbit(0xBA,0x07) volatile __bit CC2_CC26IR;
__esfr(0xBB) volatile unsigned int CC2_CC27IC;
__esfrbit(0xBB,0x06) volatile __bit CC2_CC27IE;
__esfrbit(0xBB,0x07) volatile __bit CC2_CC27IR;
__esfr(0xBC) volatile unsigned int CC2_CC28IC;
__esfrbit(0xBC,0x06) volatile __bit CC2_CC28IE;
__esfrbit(0xBC,0x07) volatile __bit CC2_CC28IR;
__esfr(0xBD) volatile unsigned int CC2_T7IC;
__esfrbit(0xBD,0x06) volatile __bit CC2_T7IE;
__esfrbit(0xBD,0x07) volatile __bit CC2_T7IR;
__esfr(0xBE) volatile unsigned int CC2_T8IC;
__esfrbit(0xBE,0x06) volatile __bit CC2_T8IE;
__esfrbit(0xBE,0x07) volatile __bit CC2_T8IR;
__esfr(0xC0) volatile unsigned int EOPIC;
__esfrbit(0xC0,0x06) volatile __bit EOPIE;
__esfrbit(0xC0,0x07) volatile __bit EOPIR;
__esfr(0xC1) volatile unsigned int ASC1_TIC;
__esfrbit(0xC1,0x06) volatile __bit ASC1_TIE;
__esfrbit(0xC1,0x07) volatile __bit ASC1_TIR;
__esfr(0xC2) volatile unsigned int CC2_CC29IC;
__esfrbit(0xC2,0x06) volatile __bit CC2_CC29IE;
__esfrbit(0xC2,0x07) volatile __bit CC2_CC29IR;
__esfr(0xC4) volatile unsigned int CCU6_EIC;
__esfrbit(0xC4,0x06) volatile __bit CCU6_EICIE;
__esfrbit(0xC4,0x07) volatile __bit CCU6_EICIR;
__esfr(0xC5) volatile unsigned int ASC1_RIC;
__esfrbit(0xC5,0x06) volatile __bit ASC1_RIE;
__esfrbit(0xC5,0x07) volatile __bit ASC1_RIR;
__esfr(0xC6) volatile unsigned int CC2_CC30IC;
__esfrbit(0xC6,0x06) volatile __bit CC2_CC30IE;
__esfrbit(0xC6,0x07) volatile __bit CC2_CC30IR;
__esfr(0xC8) volatile unsigned int CCU6_T12IC;
__esfrbit(0xC8,0x06) volatile __bit CCU6_T12IE;
__esfrbit(0xC8,0x07) volatile __bit CCU6_T12IR;
__esfr(0xC9) volatile unsigned int ASC1_EIC;
__esfrbit(0xC9,0x06) volatile __bit ASC1_EIE;
__esfrbit(0xC9,0x07) volatile __bit ASC1_EIR;
__esfr(0xCA) volatile unsigned int CC2_CC31IC;
__esfrbit(0xCA,0x06) volatile __bit CC2_CC31IE;
__esfrbit(0xCA,0x07) volatile __bit CC2_CC31IR;
__esfr(0xCB) volatile unsigned int CAN_0IC;
__esfr(0xCC) volatile unsigned int CCU6_T13IC;
__esfrbit(0xCC,0x06) volatile __bit CCU6_T13IE;
__esfrbit(0xCC,0x07) volatile __bit CCU6_T13IR;
__esfr(0xCE) volatile unsigned int ASC0_TBIC;
__esfrbit(0xCE,0x06) volatile __bit ASC0_TBIE;
__esfrbit(0xCE,0x07) volatile __bit ASC0_TBIR;
__esfr(0xCF) volatile unsigned int PLL_IC;
__esfrbit(0xCF,0x06) volatile __bit PLL_IE;
__esfrbit(0xCF,0x07) volatile __bit PLL_IR;
__esfr(0xD0) volatile unsigned int RTC_IC;
__esfrbit(0xD0,0x06) volatile __bit RTC_IE;
__esfrbit(0xD0,0x07) volatile __bit RTC_IR;
__esfr(0xD5) volatile unsigned int SSC1_TIC;
__esfrbit(0xD5,0x06) volatile __bit SSC1_TIE;
__esfrbit(0xD5,0x07) volatile __bit SSC1_TIR;
__esfr(0xD6) volatile unsigned int SSC1_RIC;
__esfrbit(0xD6,0x06) volatile __bit SSC1_RIE;
__esfrbit(0xD6,0x07) volatile __bit SSC1_RIR;
__esfr(0xD7) volatile unsigned int SSC1_EIC;
__esfrbit(0xD7,0x06) volatile __bit SSC1_EIE;
__esfrbit(0xD7,0x07) volatile __bit SSC1_EIR;
__esfr(0xDC) volatile unsigned int ASC0_ABCON;
__esfrbit(0xDC,0x00) volatile __bit ASC0_ABEN;
__esfrbit(0xDC,0x01) volatile __bit ASC0_AUREN;
__esfrbit(0xDC,0x02) volatile __bit ASC0_ABSTEN;
__esfrbit(0xDC,0x03) volatile __bit ASC0_ABDETEN;
__esfrbit(0xDC,0x04) volatile __bit ASC0_FCDETEN;
__esfrbit(0xDC,0x0A) volatile __bit ASC0_TXINV;
__esfrbit(0xDC,0x0B) volatile __bit ASC0_RXINV;
__esfr(0xDD) volatile unsigned int ASC1_ABIC;
__esfrbit(0xDD,0x06) volatile __bit ASC1_ABIE;
__esfrbit(0xDD,0x07) volatile __bit ASC1_ABIR;
__esfr(0xDE) volatile unsigned int ASC1_ABCON;
__esfrbit(0xDE,0x00) volatile __bit ASC1_ABEN;
__esfrbit(0xDE,0x01) volatile __bit ASC1_AUREN;
__esfrbit(0xDE,0x02) volatile __bit ASC1_ABSTEN;
__esfrbit(0xDE,0x03) volatile __bit ASC1_ABDETEN;
__esfrbit(0xDE,0x04) volatile __bit ASC1_FCDETEN;
__esfrbit(0xDE,0x0A) volatile __bit ASC1_TXINV;
__esfrbit(0xDE,0x0B) volatile __bit ASC1_RXINV;
__esfr(0xE2) volatile unsigned int PICON;
__esfrbit(0xE2,0x01) volatile __bit P2HIN;
__esfrbit(0xE2,0x02) volatile __bit P3LIN;
__esfrbit(0xE2,0x03) volatile __bit P3HIN;
__esfrbit(0xE2,0x04) volatile __bit P4LIN;
__esfrbit(0xE2,0x05) volatile __bit P6LIN;
__esfrbit(0xE2,0x06) volatile __bit P7LIN;
__esfrbit(0xE2,0x07) volatile __bit P9LIN;
__esfrbit(0xE2,0x08) volatile __bit P20LIN;
__esfrbit(0xE2,0x09) volatile __bit P20HIN;
__esfr(0xE3) volatile unsigned int ODP3;
__esfr(0xE4) volatile unsigned int ODP4;

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
__sfr(0x0C) volatile unsigned int CPUCON1;
__sfrbit(0x0C,0x00) volatile __bit ZCJ;
__sfrbit(0x0C,0x01) volatile __bit BP;
__sfrbit(0x0C,0x02) volatile __bit INTSCXT;
__sfrbit(0x0C,0x03) volatile __bit SGTDIS;
__sfrbit(0x0C,0x04) volatile __bit WDTCTL;
__sfr(0x0D) volatile unsigned int CPUCON2;
__sfrbit(0x0D,0x00) volatile __bit SL;
__sfrbit(0x0D,0x01) volatile __bit DAID;
__sfrbit(0x0D,0x03) volatile __bit RETST;
__sfrbit(0x0D,0x04) volatile __bit OVRUN;
__sfrbit(0x0D,0x05) volatile __bit LFIC;
__sfrbit(0x0D,0x06) volatile __bit STEN;
__sfrbit(0x0D,0x07) volatile __bit EIOIAEN;
__sfrbit(0x0D,0x08) volatile __bit BYPF;
__sfrbit(0x0D,0x09) volatile __bit BYPPF;
__sfr(0x14) volatile unsigned int CC2_SEM;
__sfrbit(0x14,0x00) volatile __bit CC2_SEM0;
__sfrbit(0x14,0x01) volatile __bit CC2_SEM1;
__sfrbit(0x14,0x02) volatile __bit CC2_SEM2;
__sfrbit(0x14,0x03) volatile __bit CC2_SEM3;
__sfrbit(0x14,0x04) volatile __bit CC2_SEM4;
__sfrbit(0x14,0x05) volatile __bit CC2_SEM5;
__sfrbit(0x14,0x06) volatile __bit CC2_SEM6;
__sfrbit(0x14,0x07) volatile __bit CC2_SEM7;
__sfrbit(0x14,0x08) volatile __bit CC2_SEM8;
__sfrbit(0x14,0x09) volatile __bit CC2_SEM9;
__sfrbit(0x14,0x0A) volatile __bit CC2_SEM10;
__sfrbit(0x14,0x0B) volatile __bit CC2_SEM11;
__sfrbit(0x14,0x0C) volatile __bit CC2_SEM12;
__sfrbit(0x14,0x0D) volatile __bit CC2_SEM13;
__sfrbit(0x14,0x0E) volatile __bit CC2_SEM14;
__sfrbit(0x14,0x0F) volatile __bit CC2_SEM15;
__sfr(0x15) volatile unsigned int CC2_SEE;
__sfrbit(0x15,0x00) volatile __bit CC2_SEE0;
__sfrbit(0x15,0x01) volatile __bit CC2_SEE1;
__sfrbit(0x15,0x02) volatile __bit CC2_SEE2;
__sfrbit(0x15,0x03) volatile __bit CC2_SEE3;
__sfrbit(0x15,0x04) volatile __bit CC2_SEE4;
__sfrbit(0x15,0x05) volatile __bit CC2_SEE5;
__sfrbit(0x15,0x06) volatile __bit CC2_SEE6;
__sfrbit(0x15,0x07) volatile __bit CC2_SEE7;
__sfrbit(0x15,0x08) volatile __bit CC2_SEE8;
__sfrbit(0x15,0x09) volatile __bit CC2_SEE9;
__sfrbit(0x15,0x0A) volatile __bit CC2_SEE10;
__sfrbit(0x15,0x0B) volatile __bit CC2_SEE11;
__sfrbit(0x15,0x0C) volatile __bit CC2_SEE12;
__sfrbit(0x15,0x0D) volatile __bit CC2_SEE13;
__sfrbit(0x15,0x0E) volatile __bit CC2_SEE14;
__sfrbit(0x15,0x0F) volatile __bit CC2_SEE15;
__sfr(0x16) volatile unsigned int CC1_SEM;
__sfrbit(0x16,0x00) volatile __bit CC1_SEM0;
__sfrbit(0x16,0x01) volatile __bit CC1_SEM1;
__sfrbit(0x16,0x02) volatile __bit CC1_SEM2;
__sfrbit(0x16,0x03) volatile __bit CC1_SEM3;
__sfrbit(0x16,0x04) volatile __bit CC1_SEM4;
__sfrbit(0x16,0x05) volatile __bit CC1_SEM5;
__sfrbit(0x16,0x06) volatile __bit CC1_SEM6;
__sfrbit(0x16,0x07) volatile __bit CC1_SEM7;
__sfrbit(0x16,0x08) volatile __bit CC1_SEM8;
__sfrbit(0x16,0x09) volatile __bit CC1_SEM9;
__sfrbit(0x16,0x0A) volatile __bit CC1_SEM10;
__sfrbit(0x16,0x0B) volatile __bit CC1_SEM11;
__sfrbit(0x16,0x0C) volatile __bit CC1_SEM12;
__sfrbit(0x16,0x0D) volatile __bit CC1_SEM13;
__sfrbit(0x16,0x0E) volatile __bit CC1_SEM14;
__sfrbit(0x16,0x0F) volatile __bit CC1_SEM15;
__sfr(0x17) volatile unsigned int CC1_SEE;
__sfrbit(0x17,0x00) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x01) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x02) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x03) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x04) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x05) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x06) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x07) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x08) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x09) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x0A) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x0B) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x0C) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x0D) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x0E) volatile __bit CC1_SEE0;
__sfrbit(0x17,0x0F) volatile __bit CC1_SEE0;
__sfr(0x20) volatile unsigned int GPT12E_T2;
__sfr(0x21) volatile unsigned int GPT12E_T3;
__sfr(0x22) volatile unsigned int GPT12E_T4;
__sfr(0x23) volatile unsigned int GPT12E_T5;
__sfr(0x24) volatile unsigned int GPT12E_T6;
__sfr(0x25) volatile unsigned int GPT12E_CAPREL;
__sfr(0x28) volatile unsigned int CC1_T0;
__sfr(0x29) volatile unsigned int CC1_T1;
__sfr(0x2A) volatile unsigned int CC1_T0REL;
__sfr(0x2B) volatile unsigned int CC1_T1REL;
__sfr(0x2E) volatile unsigned int MAL;
__sfr(0x2F) volatile unsigned int MAH;
__sfr(0x30) volatile unsigned int CC2_CC16;
__sfr(0x31) volatile unsigned int CC2_CC17;
__sfr(0x32) volatile unsigned int CC2_CC18;
__sfr(0x33) volatile unsigned int CC2_CC19;
__sfr(0x34) volatile unsigned int CC2_CC20;
__sfr(0x35) volatile unsigned int CC2_CC21;
__sfr(0x36) volatile unsigned int CC2_CC22;
__sfr(0x37) volatile unsigned int CC2_CC23;
__sfr(0x38) volatile unsigned int CC2_CC24;
__sfr(0x39) volatile unsigned int CC2_CC25;
__sfr(0x3A) volatile unsigned int CC2_CC26;
__sfr(0x3B) volatile unsigned int CC2_CC27;
__sfr(0x3C) volatile unsigned int CC2_CC28;
__sfr(0x3D) volatile unsigned int CC2_CC29;
__sfr(0x3E) volatile unsigned int CC2_CC30;
__sfr(0x3F) volatile unsigned int CC2_CC31;
__sfr(0x40) volatile unsigned int CC1_CC0;
__sfr(0x41) volatile unsigned int CC1_CC1;
__sfr(0x42) volatile unsigned int CC1_CC2;
__sfr(0x43) volatile unsigned int CC1_CC3;
__sfr(0x44) volatile unsigned int CC1_CC4;
__sfr(0x45) volatile unsigned int CC1_CC5;
__sfr(0x46) volatile unsigned int CC1_CC6;
__sfr(0x47) volatile unsigned int CC1_CC7;
__sfr(0x48) volatile unsigned int CC1_CC8;
__sfr(0x49) volatile unsigned int CC1_CC9;
__sfr(0x4A) volatile unsigned int CC1_CC10;
__sfr(0x4B) volatile unsigned int CC1_CC11;
__sfr(0x4C) volatile unsigned int CC1_CC12;
__sfr(0x4D) volatile unsigned int CC1_CC13;
__sfr(0x4E) volatile unsigned int CC1_CC14;
__sfr(0x4F) volatile unsigned int CC1_CC15;
__sfr(0x50) volatile unsigned int ADC_DAT;
__sfr(0x55) volatile unsigned int ASC0_PMW;
__sfr(0x56) volatile unsigned int ASC1_PMW;
__sfr(0x58) volatile unsigned int ASC0_TBUF;
__sfr(0x59) volatile unsigned int ASC0_RBUF;
__sfr(0x5A) volatile unsigned int ASC0_BG;
__sfr(0x5B) volatile unsigned int ASC0_FDV;
__sfr(0x5C) volatile unsigned int ASC1_TBUF;
__sfr(0x5D) volatile unsigned int ASC1_RBUF;
__sfr(0x5E) volatile unsigned int ASC1_BG;
__sfr(0x5F) volatile unsigned int ASC1_FDV;
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
__sfr(0x86) volatile unsigned int SPSEG;
__sfr(0x87) volatile unsigned int MDC;
__sfrbit(0x87,0x04) volatile __bit MDRIU;
__sfr(0x88) volatile unsigned int PSW;
__sfrbit(0x88,0x05) volatile __bit MULIP;
__sfrbit(0x88,0x06) volatile __bit USR0;
__sfrbit(0x88,0x07) volatile __bit USR1;
__sfrbit(0x88,0x0A) volatile __bit HLDEN;
__sfrbit(0x88,0x0B) volatile __bit IEN;
__sfr(0x89) volatile unsigned int VECSEG;
__sfr(0x8B) volatile unsigned int P9;
__sfr(0x8C) volatile unsigned int DP9;
__sfr(0x8D) volatile unsigned int ODP9;
__sfr(0x8E) volatile unsigned int ZEROS;
__sfr(0x8F) volatile unsigned int ONES;
__sfr(0x90) volatile unsigned int CC2_T78CON;
__sfrbit(0x90,0x03) volatile __bit T7M;
__sfrbit(0x90,0x06) volatile __bit T7R;
__sfrbit(0x90,0x0B) volatile __bit T8M;
__sfrbit(0x90,0x0E) volatile __bit T8R;
__sfr(0x91) volatile unsigned int CC2_M4;
__sfrbit(0x91,0x03) volatile __bit ACC16;
__sfrbit(0x91,0x07) volatile __bit ACC17;
__sfrbit(0x91,0x0B) volatile __bit ACC18;
__sfrbit(0x91,0x0F) volatile __bit ACC19;
__sfr(0x92) volatile unsigned int CC2_M5;
__sfrbit(0x92,0x03) volatile __bit ACC20;
__sfrbit(0x92,0x07) volatile __bit ACC21;
__sfrbit(0x92,0x0B) volatile __bit ACC22;
__sfrbit(0x92,0x0F) volatile __bit ACC23;
__sfr(0x93) volatile unsigned int CC2_M6;
__sfrbit(0x93,0x03) volatile __bit ACC24;
__sfrbit(0x93,0x07) volatile __bit ACC25;
__sfrbit(0x93,0x0B) volatile __bit ACC26;
__sfrbit(0x93,0x0F) volatile __bit ACC27;
__sfr(0x94) volatile unsigned int CC2_M7;
__sfrbit(0x94,0x03) volatile __bit ACC28;
__sfrbit(0x94,0x07) volatile __bit ACC29;
__sfrbit(0x94,0x0B) volatile __bit ACC30;
__sfrbit(0x94,0x0F) volatile __bit ACC31;
__sfr(0x95) volatile unsigned int CC2_DRM;
__sfr(0x96) volatile unsigned int CC2_OUT;
__sfrbit(0x96,0x00) volatile __bit CC2_CC0IO;
__sfrbit(0x96,0x01) volatile __bit CC2_CC1IO;
__sfrbit(0x96,0x02) volatile __bit CC2_CC2IO;
__sfrbit(0x96,0x03) volatile __bit CC2_CC3IO;
__sfrbit(0x96,0x04) volatile __bit CC2_CC4IO;
__sfrbit(0x96,0x05) volatile __bit CC2_CC5IO;
__sfrbit(0x96,0x06) volatile __bit CC2_CC6IO;
__sfrbit(0x96,0x07) volatile __bit CC2_CC7IO;
__sfrbit(0x96,0x08) volatile __bit CC2_CC8IO;
__sfrbit(0x96,0x09) volatile __bit CC2_CC9IO;
__sfrbit(0x96,0x0A) volatile __bit CC2_CC10IO;
__sfrbit(0x96,0x0B) volatile __bit CC2_CC11IO;
__sfrbit(0x96,0x0C) volatile __bit CC2_CC12IO;
__sfrbit(0x96,0x0D) volatile __bit CC2_CC13IO;
__sfrbit(0x96,0x0E) volatile __bit CC2_CC14IO;
__sfrbit(0x96,0x0F) volatile __bit CC2_CC15IO;
__sfr(0xA0) volatile unsigned int GPT12E_T2CON;
__sfrbit(0xA0,0x06) volatile __bit T2R;
__sfrbit(0xA0,0x07) volatile __bit T2UD;
__sfrbit(0xA0,0x08) volatile __bit T2UDE;
__sfrbit(0xA0,0x09) volatile __bit T2RC;
__sfrbit(0xA0,0x0C) volatile __bit T2IRDIS;
__sfrbit(0xA0,0x0D) volatile __bit T2EDGE;
__sfrbit(0xA0,0x0E) volatile __bit T2CHDIR;
__sfrbit(0xA0,0x0F) volatile __bit T2RDIR;
__sfr(0xA1) volatile unsigned int GPT12E_T3CON;
__sfrbit(0xA1,0x06) volatile __bit T3R;
__sfrbit(0xA1,0x07) volatile __bit T3UD;
__sfrbit(0xA1,0x08) volatile __bit T3UDE;
__sfrbit(0xA1,0x09) volatile __bit T3OE;
__sfrbit(0xA1,0x0A) volatile __bit T3OTL;
__sfrbit(0xA1,0x0D) volatile __bit T3EDGE;
__sfrbit(0xA1,0x0E) volatile __bit T3CHDIR;
__sfrbit(0xA1,0x0F) volatile __bit T3RDIR;
__sfr(0xA2) volatile unsigned int GPT12E_T4CON;
__sfrbit(0xA2,0x06) volatile __bit T4R;
__sfrbit(0xA2,0x07) volatile __bit T4UD;
__sfrbit(0xA2,0x08) volatile __bit T4UDE;
__sfrbit(0xA2,0x09) volatile __bit T4RC;
__sfrbit(0xA2,0x0C) volatile __bit T4IRDIS;
__sfrbit(0xA2,0x0D) volatile __bit T4EDGE;
__sfrbit(0xA2,0x0E) volatile __bit T4CHDIR;
__sfrbit(0xA2,0x0F) volatile __bit T4RDIR;
__sfr(0xA3) volatile unsigned int GPT12E_T5CON;
__sfrbit(0xA3,0x06) volatile __bit T5R;
__sfrbit(0xA3,0x07) volatile __bit T5UD;
__sfrbit(0xA3,0x09) volatile __bit T5RC;
__sfrbit(0xA3,0x0A) volatile __bit CT3;
__sfrbit(0xA3,0x0B) volatile __bit T5CC;
__sfrbit(0xA3,0x0E) volatile __bit T5CLR;
__sfrbit(0xA3,0x0F) volatile __bit T5SC;
__sfr(0xA4) volatile unsigned int GPT12E_T6CON;
__sfrbit(0xA4,0x06) volatile __bit T6R;
__sfrbit(0xA4,0x07) volatile __bit T6UD;
__sfrbit(0xA4,0x09) volatile __bit T6OE;
__sfrbit(0xA4,0x0A) volatile __bit T6OTL;
__sfrbit(0xA4,0x0E) volatile __bit T6CLR;
__sfrbit(0xA4,0x0F) volatile __bit T6SR;
__sfr(0xA8) volatile unsigned int CC1_T01CON;
__sfrbit(0xA8,0x03) volatile __bit T0M;
__sfrbit(0xA8,0x06) volatile __bit T0R;
__sfrbit(0xA8,0x0B) volatile __bit T1M;
__sfrbit(0xA8,0x0E) volatile __bit T1R;
__sfr(0xA9) volatile unsigned int CC1_M0;
__sfrbit(0xA9,0x03) volatile __bit ACC0;
__sfrbit(0xA9,0x07) volatile __bit ACC1;
__sfrbit(0xA9,0x0B) volatile __bit ACC2;
__sfrbit(0xA9,0x0F) volatile __bit ACC3;
__sfr(0xAA) volatile unsigned int CC1_M1;
__sfrbit(0xAA,0x03) volatile __bit ACC4;
__sfrbit(0xAA,0x07) volatile __bit ACC5;
__sfrbit(0xAA,0x0B) volatile __bit ACC6;
__sfrbit(0xAA,0x0F) volatile __bit ACC7;
__sfr(0xAB) volatile unsigned int CC1_M2;
__sfrbit(0xAB,0x03) volatile __bit ACC8;
__sfrbit(0xAB,0x07) volatile __bit ACC9;
__sfrbit(0xAB,0x0B) volatile __bit ACC10;
__sfrbit(0xAB,0x0F) volatile __bit ACC11;
__sfr(0xAC) volatile unsigned int CC1_M3;
__sfrbit(0xAC,0x03) volatile __bit ACC12;
__sfrbit(0xAC,0x07) volatile __bit ACC13;
__sfrbit(0xAC,0x0B) volatile __bit ACC14;
__sfrbit(0xAC,0x0F) volatile __bit ACC15;
__sfr(0xAD) volatile unsigned int CC1_DRM;
__sfr(0xAE) volatile unsigned int CC1_OUT;
__sfrbit(0xAE,0x00) volatile __bit CC1_CC0IO;
__sfrbit(0xAE,0x01) volatile __bit CC1_CC1IO;
__sfrbit(0xAE,0x02) volatile __bit CC1_CC2IO;
__sfrbit(0xAE,0x03) volatile __bit CC1_CC3IO;
__sfrbit(0xAE,0x04) volatile __bit CC1_CC4IO;
__sfrbit(0xAE,0x05) volatile __bit CC1_CC5IO;
__sfrbit(0xAE,0x06) volatile __bit CC1_CC6IO;
__sfrbit(0xAE,0x07) volatile __bit CC1_CC7IO;
__sfrbit(0xAE,0x08) volatile __bit CC1_CC8IO;
__sfrbit(0xAE,0x09) volatile __bit CC1_CC9IO;
__sfrbit(0xAE,0x0A) volatile __bit CC1_CC10IO;
__sfrbit(0xAE,0x0B) volatile __bit CC1_CC11IO;
__sfrbit(0xAE,0x0C) volatile __bit CC1_CC12IO;
__sfrbit(0xAE,0x0D) volatile __bit CC1_CC13IO;
__sfrbit(0xAE,0x0E) volatile __bit CC1_CC14IO;
__sfrbit(0xAE,0x0F) volatile __bit CC1_CC15IO;
__sfr(0xAF) volatile unsigned int SSC1_CON;
__sfrbit(0xAF,0x04) volatile __bit SCC1_HB;
__sfrbit(0xAF,0x05) volatile __bit SCC1_PH;
__sfrbit(0xAF,0x06) volatile __bit SCC1_PO;
__sfrbit(0xAF,0x07) volatile __bit SCC1_LB;
__sfrbit(0xAF,0x08) volatile __bit SCC1_TEN;
__sfrbit(0xAF,0x08) volatile __bit SCC1_TE;
__sfrbit(0xAF,0x09) volatile __bit SCC1_REN;
__sfrbit(0xAF,0x09) volatile __bit SCC1_RE;
__sfrbit(0xAF,0x0A) volatile __bit SCC1_PEN;
__sfrbit(0xAF,0x0A) volatile __bit SCC1_PE;
__sfrbit(0xAF,0x0B) volatile __bit SCC1_BEN;
__sfrbit(0xAF,0x0B) volatile __bit SCC1_BE;
__sfrbit(0xAF,0x0C) volatile __bit SCC1_AREN;
__sfrbit(0xAF,0x0C) volatile __bit SCC1_BSY;
__sfrbit(0xAF,0x0E) volatile __bit SCC1_MS;
__sfrbit(0xAF,0x0F) volatile __bit SCC1_EN;
__sfr(0xB0) volatile unsigned int GPT12E_T2IC;
__sfrbit(0xB0,0x06) volatile __bit T2IE;
__sfrbit(0xB0,0x07) volatile __bit T2IR;
__sfr(0xB1) volatile unsigned int GPT12E_T3IC;
__sfrbit(0xB1,0x06) volatile __bit T3IE;
__sfrbit(0xB1,0x07) volatile __bit T3IR;
__sfr(0xB2) volatile unsigned int GPT12E_T4IC;
__sfrbit(0xB2,0x06) volatile __bit T4IE;
__sfrbit(0xB2,0x07) volatile __bit T4IR;
__sfr(0xB3) volatile unsigned int GPT12E_T5IC;
__sfrbit(0xB3,0x06) volatile __bit T5IE;
__sfrbit(0xB3,0x07) volatile __bit T5IR;
__sfr(0xB4) volatile unsigned int GPT12E_T6IC;
__sfrbit(0xB4,0x06) volatile __bit T6IE;
__sfrbit(0xB4,0x07) volatile __bit T6IR;
__sfr(0xB5) volatile unsigned int GPT12E_CRIC;
__sfrbit(0xB5,0x06) volatile __bit CRIE;
__sfrbit(0xB5,0x07) volatile __bit CRIR;
__sfr(0xB6) volatile unsigned int ASC0_TIC;
__sfrbit(0xB6,0x06) volatile __bit ASC0_TIE;
__sfrbit(0xB6,0x07) volatile __bit ASC0_TIR;
__sfr(0xB7) volatile unsigned int ASC0_RIC;
__sfrbit(0xB7,0x06) volatile __bit ASC0_RIE;
__sfrbit(0xB7,0x07) volatile __bit ASC0_RIR;
__sfr(0xB8) volatile unsigned int ASC0_EIC;
__sfrbit(0xB8,0x06) volatile __bit ASC0_EIE;
__sfrbit(0xB8,0x07) volatile __bit ASC0_EIR;
__sfr(0xB9) volatile unsigned int SSC0_TIC;
__sfrbit(0xB9,0x06) volatile __bit SSC0_TIE;
__sfrbit(0xB9,0x07) volatile __bit SSC0_TIR;
__sfr(0xBA) volatile unsigned int SSC0_RIC;
__sfrbit(0xBA,0x06) volatile __bit SSC0_RIE;
__sfrbit(0xBA,0x07) volatile __bit SSC0_RIR;
__sfr(0xBB) volatile unsigned int SSC0_EIC;
__sfrbit(0xBB,0x06) volatile __bit SSC0_EIE;
__sfrbit(0xBB,0x07) volatile __bit SSC0_EIR;
__sfr(0xBC) volatile unsigned int CC1_CC0IC;
__sfrbit(0xBC,0x06) volatile __bit CC1_CC0IE;
__sfrbit(0xBC,0x07) volatile __bit CC1_CC0IR;
__sfr(0xBD) volatile unsigned int CC1_CC1IC;
__sfrbit(0xBD,0x06) volatile __bit CC1_CC1IE;
__sfrbit(0xBD,0x07) volatile __bit CC1_CC1IR;
__sfr(0xBE) volatile unsigned int CC1_CC2IC;
__sfrbit(0xBE,0x06) volatile __bit CC1_CC2IE;
__sfrbit(0xBE,0x07) volatile __bit CC1_CC2IR;
__sfr(0xBF) volatile unsigned int CC1_CC3IC;
__sfrbit(0xBF,0x06) volatile __bit CC1_CC3IE;
__sfrbit(0xBF,0x07) volatile __bit CC1_CC3IR;
__sfr(0xC0) volatile unsigned int CC1_CC4IC;
__sfrbit(0xC0,0x06) volatile __bit CC1_CC4IE;
__sfrbit(0xC0,0x07) volatile __bit CC1_CC4IR;
__sfr(0xC1) volatile unsigned int CC1_CC5IC;
__sfrbit(0xC1,0x06) volatile __bit CC1_CC5IE;
__sfrbit(0xC1,0x07) volatile __bit CC1_CC5IR;
__sfr(0xC2) volatile unsigned int CC1_CC6IC;
__sfrbit(0xC2,0x06) volatile __bit CC1_CC6IE;
__sfrbit(0xC2,0x07) volatile __bit CC1_CC6IR;
__sfr(0xC3) volatile unsigned int CC1_CC7IC;
__sfrbit(0xC3,0x06) volatile __bit CC1_CC7IE;
__sfrbit(0xC3,0x07) volatile __bit CC1_CC7IR;
__sfr(0xC4) volatile unsigned int CC1_CC8IC;
__sfrbit(0xC4,0x06) volatile __bit CC1_CC8IE;
__sfrbit(0xC4,0x07) volatile __bit CC1_CC8IR;
__sfr(0xC5) volatile unsigned int CC1_CC9IC;
__sfrbit(0xC5,0x06) volatile __bit CC1_CC9IE;
__sfrbit(0xC5,0x07) volatile __bit CC1_CC9IR;
__sfr(0xC6) volatile unsigned int CC1_CC10IC;
__sfrbit(0xC6,0x06) volatile __bit CC1_CC10IE;
__sfrbit(0xC6,0x07) volatile __bit CC1_CC10IR;
__sfr(0xC7) volatile unsigned int CC1_CC11IC;
__sfrbit(0xC7,0x06) volatile __bit CC1_CC11IE;
__sfrbit(0xC7,0x07) volatile __bit CC1_CC11IR;
__sfr(0xC8) volatile unsigned int CC1_CC12IC;
__sfrbit(0xC8,0x06) volatile __bit CC1_CC12IE;
__sfrbit(0xC8,0x07) volatile __bit CC1_CC12IR;
__sfr(0xC9) volatile unsigned int CC1_CC13IC;
__sfrbit(0xC9,0x06) volatile __bit CC1_CC13IE;
__sfrbit(0xC9,0x07) volatile __bit CC1_CC13IR;
__sfr(0xCA) volatile unsigned int CC1_CC14IC;
__sfrbit(0xCA,0x06) volatile __bit CC1_CC14IE;
__sfrbit(0xCA,0x07) volatile __bit CC1_CC14IR;
__sfr(0xCB) volatile unsigned int CC1_CC15IC;
__sfrbit(0xCB,0x06) volatile __bit CC1_CC15IE;
__sfrbit(0xCB,0x07) volatile __bit CC1_CC15IR;
__sfr(0xCC) volatile unsigned int ADC_CIC;
__sfrbit(0xCC,0x06) volatile __bit ADCIE;
__sfrbit(0xCC,0x07) volatile __bit ADCIR;
__sfr(0xCD) volatile unsigned int ADC_EIC;
__sfrbit(0xCD,0x06) volatile __bit ADEIE;
__sfrbit(0xCD,0x07) volatile __bit ADEIR;
__sfr(0xCE) volatile unsigned int CC1_T0IC;
__sfrbit(0xCE,0x06) volatile __bit T0IE;
__sfrbit(0xCE,0x07) volatile __bit T0IR;
__sfr(0xCF) volatile unsigned int CC1_T1IC;
__sfrbit(0xCF,0x06) volatile __bit T1IE;
__sfrbit(0xCF,0x07) volatile __bit T1IR;
__sfr(0xD0) volatile unsigned int ADC_CON;
__sfrbit(0xD0,0x07) volatile __bit ADC_CON_ADST;
__sfrbit(0xD0,0x08) volatile __bit ADC_CON_ADBSY;
__sfrbit(0xD0,0x09) volatile __bit ADC_CON_ADWR;
__sfrbit(0xD0,0x0A) volatile __bit ADC_CON_ADCIN;
__sfrbit(0xD0,0x0B) volatile __bit ADC_CON_ADCRQ;
__sfr(0xD1) volatile unsigned int P5;
__sfr(0xD2) volatile unsigned int P5DIDIS;
__sfr(0xD3) volatile unsigned int ADC_CON1;
__sfrbit(0xD3,0x0C) volatile __bit RES;
__sfrbit(0xD3,0x0D) volatile __bit CAL;
__sfrbit(0xD3,0x0E) volatile __bit SAMPLE;
__sfrbit(0xD3,0x0F) volatile __bit ICST;
__sfr(0xD4) volatile unsigned int PECISNC;
__sfrbit(0xD4,0x00) volatile __bit C0IE;
__sfrbit(0xD4,0x01) volatile __bit C0IR;
__sfrbit(0xD4,0x02) volatile __bit C1IE;
__sfrbit(0xD4,0x03) volatile __bit C1IR;
__sfrbit(0xD4,0x04) volatile __bit C2IE;
__sfrbit(0xD4,0x05) volatile __bit C2IR;
__sfrbit(0xD4,0x06) volatile __bit C3IE;
__sfrbit(0xD4,0x07) volatile __bit C3IR;
__sfrbit(0xD4,0x08) volatile __bit C4IE;
__sfrbit(0xD4,0x09) volatile __bit C4IR;
__sfrbit(0xD4,0x0A) volatile __bit C5IE;
__sfrbit(0xD4,0x0B) volatile __bit C5IR;
__sfrbit(0xD4,0x0C) volatile __bit C6IE;
__sfrbit(0xD4,0x0D) volatile __bit C6IR;
__sfrbit(0xD4,0x0E) volatile __bit C7IE;
__sfrbit(0xD4,0x0F) volatile __bit C7IR;
__sfr(0xD6) volatile unsigned int TFR;
__sfrbit(0xD6,0x02) volatile __bit ILLOPA;
__sfrbit(0xD6,0x03) volatile __bit PRTFLT;
__sfrbit(0xD6,0x04) volatile __bit PARFLT;
__sfrbit(0xD6,0x07) volatile __bit UNDOPC;
__sfrbit(0xD6,0x0C) volatile __bit SOFTBRK;
__sfrbit(0xD6,0x0D) volatile __bit STKUF;
__sfrbit(0xD6,0x0E) volatile __bit STKOF;
__sfrbit(0xD6,0x0F) volatile __bit NMI;
__sfr(0xD8) volatile unsigned int ASC0_CON;
__sfrbit(0xD8,0x03) volatile __bit ASC0_STP;
__sfrbit(0xD8,0x04) volatile __bit ASC0_REN;
__sfrbit(0xD8,0x05) volatile __bit ASC0_PEN;
__sfrbit(0xD8,0x06) volatile __bit ASC0_FEN;
__sfrbit(0xD8,0x07) volatile __bit ASC0_OEN;
__sfrbit(0xD8,0x08) volatile __bit ASC0_PE;
__sfrbit(0xD8,0x09) volatile __bit ASC0_FE;
__sfrbit(0xD8,0x0A) volatile __bit ASC0_OE;
__sfrbit(0xD8,0x0B) volatile __bit ASC0_FDE;
__sfrbit(0xD8,0x0C) volatile __bit ASC0_ODD;
__sfrbit(0xD8,0x0D) volatile __bit ASC0_BRS;
__sfrbit(0xD8,0x0E) volatile __bit ASC0_LB;
__sfrbit(0xD8,0x0F) volatile __bit ASC0_R;
__sfr(0xD9) volatile unsigned int SSC0_CON;
__sfrbit(0xD9,0x04) volatile __bit SCC0_HB;
__sfrbit(0xD9,0x05) volatile __bit SCC0_PH;
__sfrbit(0xD9,0x06) volatile __bit SCC0_PO;
__sfrbit(0xD9,0x07) volatile __bit SCC0_LB;
__sfrbit(0xD9,0x08) volatile __bit SCC0_TEN;
__sfrbit(0xD9,0x08) volatile __bit SCC0_TE;
__sfrbit(0xD9,0x09) volatile __bit SCC0_REN;
__sfrbit(0xD9,0x09) volatile __bit SCC0_RE;
__sfrbit(0xD9,0x0A) volatile __bit SCC0_PEN;
__sfrbit(0xD9,0x0A) volatile __bit SCC0_PE;
__sfrbit(0xD9,0x0B) volatile __bit SCC0_BEN;
__sfrbit(0xD9,0x0B) volatile __bit SCC0_BE;
__sfrbit(0xD9,0x0C) volatile __bit SCC0_AREN;
__sfrbit(0xD9,0x0C) volatile __bit SCC0_BSY;
__sfrbit(0xD9,0x0E) volatile __bit SCC0_MS;
__sfrbit(0xD9,0x0F) volatile __bit SCC0_EN;
__sfr(0xDA) volatile unsigned int P20;
__sfr(0xDB) volatile unsigned int DP20;
__sfr(0xDC) volatile unsigned int ASC1_CON;
__sfrbit(0xDC,0x03) volatile __bit ASC1_STP;
__sfrbit(0xDC,0x04) volatile __bit ASC1_REN;
__sfrbit(0xDC,0x05) volatile __bit ASC1_PEN;
__sfrbit(0xDC,0x06) volatile __bit ASC1_FEN;
__sfrbit(0xDC,0x07) volatile __bit ASC1_OEN;
__sfrbit(0xDC,0x08) volatile __bit ASC1_PE;
__sfrbit(0xDC,0x09) volatile __bit ASC1_FE;
__sfrbit(0xDC,0x0A) volatile __bit ASC1_OE;
__sfrbit(0xDC,0x0B) volatile __bit ASC1_FDE;
__sfrbit(0xDC,0x0C) volatile __bit ASC1_ODD;
__sfrbit(0xDC,0x0D) volatile __bit ASC1_BRS;
__sfrbit(0xDC,0x0E) volatile __bit ASC1_LB;
__sfrbit(0xDC,0x0F) volatile __bit ASC1_R;
__sfr(0xDF) volatile unsigned int ADC_CTR0;
__sfrbit(0xDF,0x04) volatile __bit ADC_CTR0_CALOFF;
__sfrbit(0xDF,0x07) volatile __bit ADC_CTR0_ADST;
__sfrbit(0xDF,0x08) volatile __bit ADC_CTR0_ADBSY;
__sfrbit(0xDF,0x09) volatile __bit ADC_CTR0_ADWR;
__sfrbit(0xDF,0x0A) volatile __bit ADC_CTR0_ADCIN;
__sfrbit(0xDF,0x0B) volatile __bit ADC_CTR0_ADCRQ;
__sfrbit(0xDF,0x0E) volatile __bit ADC_CTR0_SAMPLE;
__sfrbit(0xDF,0x0F) volatile __bit ADC_CTR0_MD;
__sfr(0xE2) volatile unsigned int P3;
__sfr(0xE3) volatile unsigned int DP3;
__sfr(0xE4) volatile unsigned int P4;
__sfr(0xE5) volatile unsigned int DP4;
__sfr(0xED) volatile unsigned int MRW;
__sfr(0xEE) volatile unsigned int MCW;
__sfrbit(0xEE,0x09) volatile __bit MCW_MS;
__sfrbit(0xEE,0x0A) volatile __bit MCW_MP;
__sfr(0xEF) volatile unsigned int MSW;
__sfrbit(0xEF,0x08) volatile __bit MSW_MN;
__sfrbit(0xEF,0x09) volatile __bit MSW_MZ;
__sfrbit(0xEF,0x0A) volatile __bit MSW_MC;
__sfrbit(0xEF,0x0B) volatile __bit MSW_MSV;
__sfrbit(0xEF,0x0C) volatile __bit MSW_ME;
__sfrbit(0xEF,0x0D) volatile __bit MSW_MSL;
__sfrbit(0xEF,0x0E) volatile __bit MSW_MV;

#endif
