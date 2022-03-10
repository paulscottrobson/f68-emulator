// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		sys_processor.h
//		Purpose:	Processor Emulation (header)
//		Created:	22nd February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifndef _PROCESSOR_H
#define _PROCESSOR_H

typedef unsigned short WORD16;														// 8 and 16 bit types.
typedef unsigned char  BYTE8;
typedef unsigned int   LONG32;														// 32 bit type.

void CPUReset(void);
int CPUExecuteInstruction(void);
BYTE8 CPUReadMemory(LONG32 address);
void CPUWriteMemory(LONG32 address,BYTE8 data);
void CPUOverrideReset(int addr);

void MEMLoadFlashROM(void);
void MEMSetAddressLog(int logBad);

#define PC 			(CPUGetStatus()->pc)

#ifdef INCLUDE_DEBUGGING_SUPPORT													// Only required for debugging

BYTE8 CPUExecute(LONG32 breakPoint1,LONG32 breakPoint2);
LONG32 CPUGetStepOverBreakpoint(void);
void CPUExit(void);

int SRECHandler(int argc,char *argv[]);

void MEMEndRun(void);
void MEMLoadBinary(char *fileName);

typedef struct _CPUStatus {
	int a[8],d[8];
	int pc,sp,cycles;
	int sr,usp,isp;
} CPUSTATUS;

CPUSTATUS *CPUGetStatus(void);

#endif
#endif