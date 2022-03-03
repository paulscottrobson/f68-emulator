// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		hardware.c
//		Purpose:	Hardware Emulation
//		Created:	22nd February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <includes.h>

static BYTE8 icr[6];
static BYTE8 mauQueue = 0;
static LONG32 timers[4];

// *******************************************************************************************************************************
//
//													Read Gavin Memory
//
// *******************************************************************************************************************************

int Gavin_Read(int offset,BYTE8 *memory,int size) {
//	printf("GAVIN:Reading memory %04x %d\n",offset,size);
//	printf("Gavin Address %x\n",memory);

	//
	//		We manage the ICR ourselves
	//
	if (HW_IS_GAVIN_INTERRUPTCTRL(offset)) {
		return icr[offset-0x100];
	}
	//
	// 		Reading the PS/2 port always returns zero, it's dead.
	//
	if (HW_IS_GAVIN_READPS2(offset)) {
		return 0;
	}
	//
	//		Read the head of the MAU FIFO Queue
	//
	if (HW_IS_GAVIN_READMAU(offset)) {
		int qHead = mauQueue;
		mauQueue = 0;
		return qHead;
	}
	//
	// 		Reading from timers
	//
	if (HW_IS_GAVIN_TIMERS(offset)) {
		if ((offset & 7) == 0) {
			return timers[(offset - 0x208) >> 3];
		}
	}
	//
	// 		Reading from RTC, update it with actual values before the read.
	//		Writing will not work :)
	//
	if (HW_IS_GAVIN_RTC(offset)) {
	    struct tm* ptr;
	    time_t t;
	    t = time(NULL);
	    ptr = localtime(&t);
		memory[0x80] = ptr->tm_sec; 					// seconds
		memory[0x82] = ptr->tm_min; 					// minuts
		memory[0x84] = ptr->tm_hour; 					// hours
		memory[0x86] = ptr->tm_mday; 					// day
		memory[0x88] = ptr->tm_wday; 					// day of week
		memory[0x89] = ptr->tm_mon; 					// month
		memory[0x8A] = ptr->tm_year % 100; 				// year
	}
	//
	//		Default
	//
	return memory[offset];
}


// *******************************************************************************************************************************
//
//										Write Gavin Memory - return true if write done.
//
// *******************************************************************************************************************************

int Gavin_Write(int offset,BYTE8 *memory,int value,int size) {
//	printf("GAVIN:Writing memory %04x value %02x %d\n",offset,value,size);
//	printf("Gaving Address %x\n",memory);
	//
	//		Writing to ICR ands the bits with the value. 
	//
	if (HW_IS_GAVIN_INTERRUPTCTRL(offset)) {
		icr[offset - 0x100] &= value;
		return 1;
	}
	//
	// 		Writing to timers
	//
	if (HW_IS_GAVIN_TIMERS(offset)) {
		if ((offset & 7) == 0) {
			timers[(offset - 0x208) >> 3] = value;
			return 1;
		}
	}
	return 0;
}

// *******************************************************************************************************************************
//
//													Gavin - Flag Interrupt
//
// *******************************************************************************************************************************

void GAVIN_FlagInterrupt(int offset,int bitMask) {
	icr[offset] |= bitMask;
}

// *******************************************************************************************************************************
//
//											  Gavin - insert into MAU Fifo Queue
//
// *******************************************************************************************************************************

void GAVIN_InsertMauFIFO(int mau) {
	mauQueue = mau;
}

// *******************************************************************************************************************************
//
//								Empty Keyboard Queue, used before run to block spurious INTs
//
// *******************************************************************************************************************************

void GAVINClearKeyboardQueue(void) {
	mauQueue = 0;
}

// *******************************************************************************************************************************
//
//											Update timers, currently free running
//
// *******************************************************************************************************************************

void GAVIN_UpdateTimers(int cycles,int frames) {
	timers[0] += cycles;
	timers[1] += cycles;
	timers[2] += frames;
	timers[3] += frames;
}

// *******************************************************************************************************************************
//
//											Use Gavin Registers to Identify Interrupt.
//
// *******************************************************************************************************************************

int GAVIN_IdentifyInterrupt(int irq) {
	int n = 3-((irq-1) ^ 1)+2; 										// Register to check.
	if (n == 0) { 													// A bit should be set.
		fprintf(stderr,"Warning : IRQ %d register %d not set\n",irq,n);
		return M68K_INT_ACK_AUTOVECTOR;								// effectively ignore it.
	}
	//printf("ICR %d = %x\n",n,icr[n]);
	int base = (4-irq) * 8; 										// User IRQ vector.
	int bCheck = icr[n];
	while ((bCheck & 1) == 0) {
		bCheck >>=1; 												// FInd first set bit.
		base++;
	}
	int v = base + 64;
	//printf("User Interrupt %d at vector %d\n",base+64,v);
	return v;
}