// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		sys_processor.cpp
//		Purpose:	Processor Emulation.
//		Created:	22nd February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <includes.h>

// *******************************************************************************************************************************
//														   Timing
// *******************************************************************************************************************************

#define CPU_CLOCK 		(25)														// Clock speed (effective)
#define FRAME_RATE		(60)														// Frames per second (60Hz)

#define CYCLE_RATE 		(CPU_CLOCK*1000*1000)										// Cycles per second 
#define CYCLES_PER_FRAME (CYCLE_RATE / FRAME_RATE) 									// Cycles per frame.

// *******************************************************************************************************************************
//														CPU / Memory
// *******************************************************************************************************************************

static int cycles;																	// Cycle Count.
static int resetJumpAddress = 0; 													// Override reset address.

// *******************************************************************************************************************************
//														Reset the CPU
// *******************************************************************************************************************************

void CPUReset(void) {
	if (resetJumpAddress != 0) {
		m68k_set_reg(M68K_REG_PC,resetJumpAddress);
	} else {
		MEMLoadFlashROM();																// Load Flash ROM and copy down.
		m68k_init();
		m68k_set_cpu_type(PROCESSOR_TYPE);		 										// Select CPU type.
		m68k_pulse_reset();																// Reset
		HWReset();																		// Reset Hardware
		cycles = CYCLES_PER_FRAME;
	}
}

// *******************************************************************************************************************************
//													CPU Interrupt Manager
// *******************************************************************************************************************************

int CPUInterruptHandler(int n) {
	m68k_set_irq(0);
	if (n >= 1 && n <= 4) { 															// So, it's the user interrupt.
		int v = GAVIN_IdentifyInterrupt(n);												// Figure out which interrupt
		//printf("INT %d UINTV $%x\n",n,v);
		return v;
	}
	return M68K_INT_ACK_AUTOVECTOR; 													// Otherwise a Vicky 3 interrupt.
}

// *******************************************************************************************************************************
//													Override reset address
// *******************************************************************************************************************************

void CPUOverrideReset(int addr) {
	resetJumpAddress = addr;
}

// *******************************************************************************************************************************
//					Called on exit, does nothing on ESP32 but required for compilation
// *******************************************************************************************************************************

#ifdef INCLUDE_DEBUGGING_SUPPORT
#include "gfx.h"
void CPUExit(void) {	
	printf("Exited via $FFFFFFFF");
	GFXExit();
}
#else
void CPUExit(void) {}
#endif

// *******************************************************************************************************************************
//												Execute a single instruction
// *******************************************************************************************************************************

int CPUExecuteInstruction(void) {
	#ifdef INCLUDE_DEBUGGING_SUPPORT
	if (PC == 0xFFFFFFFF) CPUExit();
	#endif
	cycles -= m68k_execute(0);
	if (cycles >= 0 ) return 0;														// Not completed a frame.
	cycles = cycles + CYCLES_PER_FRAME;												// Adjust this frame rate, up to x16 on HS
	HWSync();																		// Update any hardware
	GAVIN_FlagInterrupt(1,1); 								 						// Bit 0 of ICR 1 (Vicky A)
	m68k_set_irq(IRQ_VICKY_A); 															// Interrupt level 5 (Vicky A)
	GAVIN_UpdateTimers(CYCLES_PER_FRAME,1); 										// Update the timers.
	return FRAME_RATE;																// Return frame rate.	
}

// *******************************************************************************************************************************
//												Read/Write Memory
// *******************************************************************************************************************************

BYTE8 CPUReadMemory(LONG32 address) {
	return m68k_read_memory_8(address);
}

void CPUWriteMemory(LONG32 address,BYTE8 data) {
	m68k_write_memory_8(address,data);
}

#ifdef INCLUDE_DEBUGGING_SUPPORT

// *******************************************************************************************************************************
//		Execute chunk of code, to either of two break points or frame-out, return non-zero frame rate on frame, breakpoint 0
// *******************************************************************************************************************************

BYTE8 CPUExecute(LONG32 breakPoint1,LONG32 breakPoint2) { 
	BYTE8 next,hitBreak;
	hitBreak = 0;
	do {
		BYTE8 r = CPUExecuteInstruction();											// Execute an instruction
		if (r != 0) return r; 														// Frame out.
		if (m68k_read_memory_8(PC) == 0x10) { 										// $1000 is MOVE.B D0,D0
			if (m68k_read_memory_8(PC+1) == 0x00) hitBreak = 1;
		}
	} while (PC != breakPoint1 && PC != breakPoint2 && hitBreak == 0);				// Stop on breakpoint or MOVE.B D0,D0
	return 0; 
}

// *******************************************************************************************************************************
//									Return address of breakpoint for step-over, or 0 if N/A
// *******************************************************************************************************************************

LONG32 CPUGetStepOverBreakpoint(void) {
	char buffer[64];
	int pc = CPUGetStatus()->pc; 
	int c = m68k_disassemble(buffer, pc, PROCESSOR_TYPE);
	buffer[3] = '\0';
	if (strcmp(buffer,"bsr") == 0 || strcmp(buffer,"jsr") == 0 || strcmp(buffer,"tra") == 0) {
		return pc+c;
	}
	return 0;																		// Do a normal single step
}

// *******************************************************************************************************************************
//														Get CPU Status
// *******************************************************************************************************************************

static CPUSTATUS st;

CPUSTATUS *CPUGetStatus(void) {
	st.cycles = cycles;
	st.pc = m68k_get_reg(NULL, M68K_REG_PC);
	st.sp = m68k_get_reg(NULL, M68K_REG_SP);
	st.sr = m68k_get_reg(NULL, M68K_REG_SR);
	st.usp = m68k_get_reg(NULL, M68K_REG_USP);
	st.isp = m68k_get_reg(NULL, M68K_REG_ISP);
	st.a[0] = m68k_get_reg(NULL,M68K_REG_A0);
	st.a[1] = m68k_get_reg(NULL,M68K_REG_A1);
	st.a[2] = m68k_get_reg(NULL,M68K_REG_A2);
	st.a[3] = m68k_get_reg(NULL,M68K_REG_A3);
	st.a[4] = m68k_get_reg(NULL,M68K_REG_A4);
	st.a[5] = m68k_get_reg(NULL,M68K_REG_A5);
	st.a[6] = m68k_get_reg(NULL,M68K_REG_A6);
	st.a[7] = m68k_get_reg(NULL,M68K_REG_A7);
	st.d[0] = m68k_get_reg(NULL,M68K_REG_D0);
	st.d[1] = m68k_get_reg(NULL,M68K_REG_D1);
	st.d[2] = m68k_get_reg(NULL,M68K_REG_D2);
	st.d[3] = m68k_get_reg(NULL,M68K_REG_D3);
	st.d[4] = m68k_get_reg(NULL,M68K_REG_D4);
	st.d[5] = m68k_get_reg(NULL,M68K_REG_D5);
	st.d[6] = m68k_get_reg(NULL,M68K_REG_D6);
	st.d[7] = m68k_get_reg(NULL,M68K_REG_D7);
	return &st;
}

#endif