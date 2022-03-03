// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		sys_debug_system.h
//		Purpose:	Debugger Code (System Dependent) Header
//		Created:	22nd February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifndef _DEBUG_SYS_H
#define _DEBUG_SYS_H


#define DW_WIDTH  		(64)
#define DW_HEIGHT		(32)

#define WIN_TITLE 		"A2560K Emulator"											// Initial Window stuff
#define WIN_WIDTH		(DW_WIDTH*6*4+32)
#define WIN_HEIGHT		(DW_HEIGHT*8*4+160)
#define WIN_BACKCOLOUR	0x004

// *******************************************************************************************************************************
//							These functions need to be implemented by the dependent debugger.
// *******************************************************************************************************************************

#define DEBUG_ARGUMENTS(ac,av) SRECHandler(ac,av)

#define DEBUG_CPURENDER(x) 	DBGXRender(x,0)											// Render the debugging display
#define DEBUG_VDURENDER(x)	DBGXRender(x,1)											// Render the game display etc.

#define DEBUG_RESET() 		CPUReset()												// Reset the CPU / Hardware.
#define DEBUG_HOMEPC()		(CPUGetStatus()->pc) 									// Get PC Home Address (e.g. current PCTR value)

#define DEBUG_SINGLESTEP()	CPUExecuteInstruction()									// Execute a single instruction, return 0 or Frame rate on frame end.
#define DEBUG_RUN(b1,b2) 	CPUExecute(b1,b2) 										// Run a frame or to breakpoint, returns -1 if breakpoint
#define DEBUG_GETOVERBREAK() CPUGetStepOverBreakpoint()								// Where would we break to step over here. (0 == single step)

#define DEBUG_RAMSTART 		(0x10000)												// Initial RAM address for debugger.
#define DEBUG_SHIFT(d,v)	((((d) << 4) | v) & ADDRESS_MASK)						// Shifting into displayed address.

#define DEBUG_KEYMAP(k,r)	(k)

void DBGXRender(int *address,int isRunMode);										// Render the debugger screen.
BYTE8 DRVGFXHandler(BYTE8 key,BYTE8 isRunMode);

#endif