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
#ifndef SDA600X_H
#define SDA600X_H
/*
 v0.4 23/09/04 

 Hardware register acces for the Micronas sda6000, sda6001 (aka M2) devices. 
 These declarations are to be used with the vbcc(c16x) compiler. 

 @todo reviewing. maybe typos in here... 
*/

#define IICPISEL (*((volatile unsigned int*)0xE804))
#define ICCFG (*((volatile unsigned int*)0xE810))
#define ICCON (*((volatile unsigned int*)0xE812))
#define ICST (*((volatile unsigned int*)0xE814))
#define ICADR (*((volatile unsigned int*)0xE816))
#define ICRTBL (*((volatile unsigned int*)0xE818))
#define ICRTBH (*((volatile unsigned int*)0xE81A))
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

__esfr(0x06) volatile unsigned int CPUID;
__esfr(0x0A) volatile unsigned int XADRS1;
__esfr(0x0B) volatile unsigned int XADRS2;
__esfr(0x0C) volatile unsigned int XADRS3;
__esfr(0x0D) volatile unsigned int XADRS4;
__esfr(0x0E) volatile unsigned int XADRS5;
__esfr(0x0F) volatile unsigned int XADRS6;
__esfr(0x12) volatile unsigned int XPERCON;
__esfr(0x34) volatile unsigned int COMDATA;
__esfr(0x35) volatile unsigned int RWDATA;
__esfr(0x36) volatile unsigned int IOSR;
__esfr(0x39) volatile unsigned int IDSCU; 
__esfr(0x3B) volatile unsigned int IDMEM2;
__esfr(0x3C) volatile unsigned int IDPROG;
__esfr(0x3D) volatile unsigned int IDMEM;
__esfr(0x3E) volatile unsigned int IDCHIP;
__esfr(0x3F) volatile unsigned int IDMANUF;
__esfr(0x50) volatile unsigned int RGBINTFC_EN;
__esfr(0x51) volatile unsigned int CLKINTFC_EN;
__esfr(0x58) volatile unsigned int SSCTB;
__esfr(0x59) volatile unsigned int SSCRB;
__esfr(0x5A) volatile unsigned int SSCBR;
__esfr(0x5C) volatile unsigned int S0ABSTAT;
__esfr(0x60) volatile unsigned int SCUSLC;
__esfr(0x61) volatile unsigned int SCUSLS;
__esfr(0x66) volatile unsigned int RTCRELL;
__esfr(0x67) volatile unsigned int RTCRELH;
__esfr(0x68) volatile unsigned int T14REL;
__esfr(0x69) volatile unsigned int T14;
__esfr(0x6A) volatile unsigned int RTCL;
__esfr(0x6B) volatile unsigned int RTCH;
__esfr(0x6E) volatile unsigned int DCMPLL;
__esfr(0x6F) volatile unsigned int DCMPLH;
__esfr(0x70) volatile unsigned int DCMPGL;
__esfr(0x71) volatile unsigned int DCMPGH;
__esfr(0x72) volatile unsigned int DCMP0L;
__esfr(0x73) volatile unsigned int DCMP0H;
__esfr(0x74) volatile unsigned int DCMP1L;
__esfr(0x75) volatile unsigned int DCMP1H;
__esfr(0x76) volatile unsigned int DCMP2L;
__esfr(0x77) volatile unsigned int DCMP2H;
__esfr(0x78) volatile unsigned int DTREVT;
__esfr(0x7A) volatile unsigned int DSWEVT;
__esfr(0x7C) volatile unsigned int DEXEVT;
__esfr(0x7E) volatile unsigned int DBGSR;
__esfr(0x80) volatile unsigned int EBIREF;
__esfr(0x84) volatile unsigned int RP0H;
__esfr(0x8A) volatile unsigned int XBCON1;
__esfr(0x8B) volatile unsigned int XBCON2;
__esfr(0x8C) volatile unsigned int XBCON3;
__esfr(0x8D) volatile unsigned int XBCON4;
__esfr(0x8E) volatile unsigned int XBCON5;
__esfr(0x8F) volatile unsigned int XBCON6;
__esfr(0x96) volatile unsigned int ALTSELOP6;
__esfr(0xA4) volatile unsigned int SCR2;
__esfrbit(0xA4,0x06) volatile __bit FPORT;
__esfrbit(0xA4,0x07) volatile __bit FDETE;
__esfr(0xB9) volatile unsigned int HSDISIC;
__esfr(0xBA) volatile unsigned int VSDISIC;
__esfr(0xBB) volatile unsigned int ACQIC;
__esfr(0xBC) volatile unsigned int ADWIC;
__esfr(0xBD) volatile unsigned int ABSTOIC;
__esfr(0xC0) volatile unsigned int PECCLIC;
__esfr(0xC2) volatile unsigned int I2CTEIC;
__esfrbit(0xC2,0x06) volatile __bit I2CTEICIE;
__esfrbit(0xC2,0x07) volatile __bit I2CTEICIR;
__esfr(0xC6) volatile unsigned int I2CPIC;
__esfrbit(0xC6,0x06) volatile __bit I2CPICIE;
__esfrbit(0xC6,0x07) volatile __bit I2CPICIR;
__esfr(0xCA) volatile unsigned int I2CTIC;
__esfrbit(0xCA,0x06) volatile __bit I2CTICIE;
__esfrbit(0xCA,0x07) volatile __bit I2CTICIR;
__esfr(0xCC) volatile unsigned int PXDEL;
__esfr(0xCE) volatile unsigned int S0TBIC;
__esfrbit(0xCE,0x06) volatile __bit S0TBIE;
__esfrbit(0xCE,0x07) volatile __bit S0TBIR;
__esfr(0xCF) volatile unsigned int RTCIC;
__esfr(0xD0) volatile unsigned int STRVBI;
__esfrbit(0xD0,0x0F) volatile __bit ACQON;
__esfr(0xD1) volatile unsigned int ACQISN;
__esfrbit(0xD1,0x00) volatile __bit VS1_IR;
__esfrbit(0xD1,0x01) volatile __bit VS1_IE;
__esfrbit(0xD1,0x02) volatile __bit HS1_IR;
__esfrbit(0xD1,0x03) volatile __bit HS1_IE;
__esfrbit(0xD1,0x04) volatile __bit VS2_IR;
__esfrbit(0xD1,0x05) volatile __bit VS2_IE;
__esfrbit(0xD1,0x06) volatile __bit HS2_IR;
__esfrbit(0xD1,0x07) volatile __bit HS2_IE;
__esfrbit(0xD1,0x08) volatile __bit L23_IR;
__esfrbit(0xD1,0x09) volatile __bit L23_IE;
__esfrbit(0xD1,0x0A) volatile __bit CC_IR;
__esfrbit(0xD1,0x0B) volatile __bit CC_IE;
__esfr(0xD2) volatile unsigned int GPRGCRL;
__esfr(0xD3) volatile unsigned int GPRGCRH;
__esfr(0xD4) volatile unsigned int SCR;
__esfrbit(0xD4,0x00) volatile __bit MAST;
__esfrbit(0xD4,0x01) volatile __bit VCS;
__esfrbit(0xD4,0x02) volatile __bit INT;
__esfrbit(0xD4,0x03) volatile __bit VP;
__esfrbit(0xD4,0x04) volatile __bit HP;
__esfrbit(0xD4,0x05) volatile __bit CORP;
__esfrbit(0xD4,0x06) volatile __bit BLANKP;
__esfrbit(0xD4,0x0B) volatile __bit CORBL;
__esfrbit(0xD4,0x0E) volatile __bit DINT;
__esfrbit(0xD4,0x0F) volatile __bit FINV;
__esfr(0xD5) volatile unsigned int VLR;
__esfr(0xD6) volatile unsigned int HPR;
__esfr(0xD7) volatile unsigned int SDV;
__esfr(0xD8) volatile unsigned int SDH;
__esfr(0xD9) volatile unsigned int HCR;
__esfr(0xDA) volatile unsigned int DACCON;
__esfr(0xDB) volatile unsigned int PFR;
__esfr(0xDC) volatile unsigned int S0ABCON;
__esfr(0xDD) volatile unsigned int REDIR;
__esfr(0xDE) volatile unsigned int EBICON;
__esfrbit(0xDE,0x00) volatile __bit EDMR;
__esfrbit(0xDE,0x01) volatile __bit EDMA;
__esfrbit(0xDE,0x02) volatile __bit SDRSZE;
__esfrbit(0xDE,0x03) volatile __bit REFEN; 
__esfr(0xDF) volatile unsigned int EBIDIR;
__esfrbit(0xDF,0x00) volatile __bit ADr_10;
__esfrbit(0xDF,0x01) volatile __bit WR_N;
__esfrbit(0xDF,0x02) volatile __bit CAS_N;
__esfrbit(0xDF,0x03) volatile __bit RAS_N;
__esfrbit(0xDF,0x04) volatile __bit CS_N;
__esfrbit(0xDF,0x05) volatile __bit CLKEN;
__esfr(0xE0) volatile unsigned int EXICON;
__esfr(0xE1) volatile unsigned int P5BEN;
__esfr(0xE2) volatile unsigned int OSCCON;
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
__esfr(0xE5) volatile unsigned int REDIR1;
__esfr(0xE6) volatile unsigned int RTCCON;
__esfrbit(0xE6,0x00) volatile __bit RTCR;
__esfrbit(0xE6,0x02) volatile __bit T14DEC;
__esfrbit(0xE6,0x03) volatile __bit T14INC;
__esfr(0xE7) volatile unsigned int ODP6;
__esfr(0xE8) volatile unsigned int SYSCON2;
__esfrbit(0xE8,0x08) volatile __bit CLKCON;
__esfr(0xEA) volatile unsigned int SYSCON3;
__esfr(0xED) volatile unsigned int EXISEL;
__esfr(0xEE) volatile unsigned int SYSCON1;
__esfr(0xEF) volatile unsigned int ISNC;
__esfrbit(0xEF,0x00) volatile __bit RTCINTIR;
__esfrbit(0xEF,0x01) volatile __bit RTCINTIE;
__esfrbit(0xEF,0x02) volatile __bit INT2IR;
__esfrbit(0xEF,0x03) volatile __bit INT2IE;

__sfr(0x00) volatile unsigned int DPP0;
__sfr(0x01) volatile unsigned int DPP1;
__sfr(0x02) volatile unsigned int DPP2;
__sfr(0x03) volatile unsigned int DPP3;
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
__sfr(0x20) volatile unsigned int T2;
__sfr(0x21) volatile unsigned int T3;
__sfr(0x22) volatile unsigned int T4;
__sfr(0x23) volatile unsigned int T5;
__sfr(0x24) volatile unsigned int T6;
__sfr(0x25) volatile unsigned int CAPREL;
__sfr(0x50) volatile unsigned int ADDAT1;
__sfr(0x51) volatile unsigned int ADDAT2;
__sfr(0x52) volatile unsigned int ADCCON;
__sfrbit(0x52,0x04) volatile __bit ADWULE;
__sfrbit(0x52,0x05) volatile __bit FSADCDIFF;
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
__sfr(0x7B) volatile unsigned int BVCR;
__sfr(0x7C) volatile unsigned int EVCR;
__sfr(0x7D) volatile unsigned int DGCON;
__sfrbit(0x7D,0x00) volatile __bit EADG;
__sfrbit(0x7D,0x01) volatile __bit EODG;
__sfrbit(0x7D,0x02) volatile __bit STGA;
__sfrbit(0x7D,0x03) volatile __bit BSYGA;
__sfr(0x7E) volatile unsigned int TM_LO;
__sfr(0x7F) volatile unsigned int TM_HI;
__sfr(0x86) volatile unsigned int BUSCON0;
__sfr(0x87) volatile unsigned int MDC;
__sfrbit(0x87,0x04) volatile __bit MDRIU;
__sfr(0x88) volatile unsigned int PSW;
__sfrbit(0x88,0x05) volatile __bit MULIP;
__sfrbit(0x88,0x06) volatile __bit USR0;
__sfrbit(0x88,0x0B) volatile __bit IEN;
__sfr(0x89) volatile unsigned int SYSCON;
__sfrbit(0x89,0x02) volatile __bit XPEN;
__sfrbit(0x89,0x03) volatile __bit RSOEN;
__sfrbit(0x89,0x06) volatile __bit CSCFG;
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
__sfrbit(0xA0,0x0C) volatile __bit T2IRDIS;
__sfrbit(0xA0,0x0D) volatile __bit T2EDGE;
__sfrbit(0xA0,0x0E) volatile __bit T2CHDIR;
__sfrbit(0xA0,0x0F) volatile __bit T2RDIR;
__sfr(0xA1) volatile unsigned int T3CON;
__sfrbit(0xA1,0x06) volatile __bit T3R;
__sfrbit(0xA1,0x07) volatile __bit T3UD;
__sfrbit(0xA1,0x08) volatile __bit T3UDE;
__sfrbit(0xA1,0x09) volatile __bit T3OE;
__sfrbit(0xA1,0x0A) volatile __bit T3OTL;
__sfrbit(0xA1,0x0D) volatile __bit T3EDGE;
__sfrbit(0xA1,0x0E) volatile __bit T3CHDIR;
__sfrbit(0xA1,0x0F) volatile __bit T3RDIR;
__sfr(0xA2) volatile unsigned int T4CON;
__sfrbit(0xA2,0x06) volatile __bit T4R;
__sfrbit(0xA2,0x07) volatile __bit T4UD;
__sfrbit(0xA2,0x08) volatile __bit T4UDE;
__sfrbit(0xA2,0x09) volatile __bit T4RC;
__sfrbit(0xA2,0x0C) volatile __bit T4IRDIS;
__sfrbit(0xA2,0x0D) volatile __bit T4EDGE;
__sfrbit(0xA2,0x0E) volatile __bit T4CHDIR;
__sfrbit(0xA2,0x0F) volatile __bit T4RDIR;
__sfr(0xA3) volatile unsigned int T5CON;
__sfrbit(0xA3,0x06) volatile __bit T5R;
__sfrbit(0xA3,0x07) volatile __bit T5UD;
__sfrbit(0xA3,0x09) volatile __bit T5RC;
__sfrbit(0xA3,0x0A) volatile __bit CT3;
__sfrbit(0xA3,0x0B) volatile __bit T5CC;
__sfrbit(0xA3,0x0E) volatile __bit T5CLR;
__sfrbit(0xA3,0x0F) volatile __bit T5SR;
__sfr(0xA4) volatile unsigned int T6CON;
__sfrbit(0xA4,0x06) volatile __bit T6R;
__sfrbit(0xA4,0x07) volatile __bit T6UD;
__sfrbit(0xA4,0x0A) volatile __bit T6OTL;
__sfrbit(0xA4,0x0E) volatile __bit T6CLR;
__sfrbit(0xA4,0x0F) volatile __bit T6SR;
__sfr(0xA5) volatile unsigned int EN_ACQ_PARAM;
__sfrbit(0xA5,0x00) volatile __bit EN_GD_COMP;
__sfrbit(0xA5,0x01) volatile __bit EN_GD_MEAS;
__sfrbit(0xA5,0x02) volatile __bit EN_DATA_STL;
__sfrbit(0xA5,0x03) volatile __bit EN_HSGL_WIN;
__sfr(0xA6) volatile unsigned int HSGL_WIN;
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
__sfr(0xC4) volatile unsigned int EX0IC;
__sfr(0xC5) volatile unsigned int EX1IC;
__sfr(0xC6) volatile unsigned int EX2IC;
__sfr(0xC7) volatile unsigned int EX3IC;
__sfr(0xC8) volatile unsigned int EX4IC;
__sfr(0xC9) volatile unsigned int EX5IC;
__sfr(0xCA) volatile unsigned int EX6IC;
__sfr(0xCB) volatile unsigned int EX7IC;
__sfr(0xCC) volatile unsigned int ADC1IC;
__sfr(0xCD) volatile unsigned int ADC2IC;
__sfr(0xCE) volatile unsigned int GAFIC;
__sfr(0xCF) volatile unsigned int ABSTAIC;
__sfr(0xD1) volatile unsigned int P5;
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
__sfrbit(0xD6,0x0C) volatile __bit DEBUG;
__sfrbit(0xD6,0x0D) volatile __bit STKUF;
__sfrbit(0xD6,0x0E) volatile __bit STKOF;
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
__sfr(0xE6) volatile unsigned int P6;
__sfr(0xE7) volatile unsigned int DP6;


#endif
