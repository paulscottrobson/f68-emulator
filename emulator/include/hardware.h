// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		hardware.h
//		Purpose:	Hardware Emulation Header
//		Created:	22nd February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifndef _HARDWARE_H
#define _HARDWARE_H

#define IRQ_VICKY_B 		(6) 			// Flags in Gavin:100	
#define IRQ_VICKY_A  		(5) 			// Flags in Gavin:101
#define IRQ_GAVIN_SUPERIO 	(4) 			// Flags in Gavin:103 		Group 0 (User vectors)
#define IRQ_GAVIN_TIMER 	(3) 			// Flags in Gavin:102 		Group 1
#define IRQ_BEATRIX_IDESDYAM (2) 			// Flags in Gavin:105 		Group 2
#define IRQ_BEATRIX_DAC  	(1)				// Flags in Gavin:104 		Group 3

void HWReset(void);
void HWSync(void);

int Gavin_Read(int offset,BYTE8 *memory,int size);
int Gavin_Write(int offset,BYTE8 *memory,int value,int size);

void GAVIN_FlagInterrupt(int offset,int bitMask);
void GAVIN_InsertMauFIFO(int mau);
void GAVIN_UpdateTimers(int cycles,int frames);
int GAVIN_IdentifyInterrupt(int irq);

void MEMRenderDisplay(void);
void HWRenderTextScreen(char vType,BYTE8 *vicky,BYTE8 *charMem,BYTE8 *colMem,BYTE8 *lutMem,BYTE8 *fontMem,SDL_Rect *rDraw);
void HWRenderBitmap(BYTE8 *vicky,BYTE8 *videoMem,SDL_Rect *rDraw);
int HWConvertVickyTextLUT(BYTE8 *lut);
int HWConvertVickyBitmapLUT(BYTE8 *lut);

void  HWScanCodeHandler(int scancode,int keydown);

#ifdef LINUX
#define FILESEP '/'
#else
#define FILESEP '\\'
#endif

#endif
