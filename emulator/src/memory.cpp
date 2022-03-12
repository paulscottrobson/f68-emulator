// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		memory.cpp
//		Purpose:	Memory functions
//		Created:	22nd February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <includes.h>

static BYTE8 ramMemory[SRAM_END];													// SRAM Memory at $000000
static BYTE8 flashMemory[FLASH_SIZE];												// Flash memory at end of memory
static BYTE8 videoMemory[VRAM_END-VRAM_START+1];									// Video RAM
static BYTE8 hwMemory[HARDWARE_RAM]; 												// RAM space & Registers in hardware area
static int   logBadAddress = 0; 													// Log address errors.

#ifdef SDRAM_ENABLED
static BYTE8 sdMemory[64*1024*1024];												// 64 Mb SDRAM.
#endif

// *******************************************************************************************************************************
//													  Print logged text
// *******************************************************************************************************************************

static void logPrint(unsigned int textAddr) {
	char buffer[129];
	int n = 0;
	while (m68k_read_memory_8(textAddr) != 0 && n < 128) {
		buffer[n++] = m68k_read_memory_8(textAddr++);
	}
	buffer[n] = '\0';
	fprintf(stderr,"F68 LOG: %s PC:$%08x\n",buffer,CPUGetStatus()->pc);
}

// *******************************************************************************************************************************
//													  Set bad address log
// *******************************************************************************************************************************

void MEMSetAddressLog(int logBad) {
	logBadAddress = logBad;
}

// *******************************************************************************************************************************
//														Load Flash ROM
// *******************************************************************************************************************************

void MEMLoadFlashROM(void) {
	FILE *f = fopen(FLASH_ROM,"rb"); 												// Read Flash ROM
	if (f == NULL)
		exit(fprintf(stderr,"Flash rom %s missing",FLASH_ROM));
	fread(flashMemory,1,sizeof(flashMemory),f);
	fclose(f);	
	for (int i = 0;i < 64*1024;i++) { 												// Copy first 64k to SRAM
		ramMemory[i] = flashMemory[i];
	}
}

// *******************************************************************************************************************************
//														Dump Memory on exit
// *******************************************************************************************************************************

void MEMEndRun(void) {
	FILE *f = fopen("memory.dump","wb");
	fwrite(ramMemory,1,sizeof(ramMemory),f);
	fclose(f);
}

// *******************************************************************************************************************************
//														Render the display
// *******************************************************************************************************************************

void MEMRenderDisplay(void) {
	SDL_Rect rc; 
	DISPLAYINFO di;
	rc.w = WIN_WIDTH;rc.h = WIN_HEIGHT;
	rc.x = WIN_WIDTH/2 - rc.w/2;rc.y = WIN_HEIGHT/2-rc.h/2;
	 													
	if (GFXGetDisplayToggle() & 1) {
		HWGetDisplayInfo(&di,'A',hwMemory+0x40000,&rc);
		HWRenderTextScreen(&di,hwMemory+0x40000,hwMemory+0x60000,hwMemory+0x68000,
															hwMemory+0x6C400,hwMemory+0x48000);	
	} else {
		HWGetDisplayInfo(&di,'B',hwMemory+0x80000,&rc);
		HWRenderBitmap(&di,hwMemory+0x80000,videoMemory,0);
		HWRenderTextScreen(&di,hwMemory+0x80000,hwMemory+0xA0000,hwMemory+0xA8000,
															hwMemory+0xAC400,hwMemory+0x88000);
	}
}

// *******************************************************************************************************************************
//													  Generic read routines
// *******************************************************************************************************************************

unsigned int  m68k_read_memory_8(unsigned int address){

	address &= ADDRESS_MASK;

	if (address < SRAM_END) {
		return ramMemory[address];
	}

	if (address >= FLASH_ADDRESS) {
		return flashMemory[address & (FLASH_SIZE-1)];
	}

	if (address >= VRAM_START && address <= VRAM_END) {
		return videoMemory[address-VRAM_START];
	}

	#ifdef SDRAM_ENABLED
	if (address >= SDRAM_ADDRESS && address < SDRAM_ADDRESS+0x4000000) {
		return sdMemory[address-SDRAM_ADDRESS];
	}
	#endif

	if (ISHWADDR(address)) {
		#include "generated/hardware/hw_gavin_read_byte.h"
		#include "generated/hardware/hw_beatrix_read_byte.h"
		#include "generated/hardware/hw_vicky3a_read_byte.h"
		#include "generated/hardware/hw_vicky3b_read_byte.h"
		return hwMemory[address-HARDWARE_START];
	}
	if (logBadAddress) printf("Warning: Reading address $%08x PC:$%08x\n",address,PC);
	return 0x00;
}

unsigned int  m68k_read_memory_16(unsigned int address){

	address &= ADDRESS_MASK;

	if (ISHWADDR(address)) {
		#include "generated/hardware/hw_gavin_read_word.h"
		#include "generated/hardware/hw_beatrix_read_word.h"
		#include "generated/hardware/hw_vicky3a_read_word.h"
		#include "generated/hardware/hw_vicky3b_read_word.h"
	}
	return m68k_read_memory_8(address+1) + (m68k_read_memory_8(address) << 8);
}

unsigned int  m68k_read_memory_32(unsigned int address){

	address &= ADDRESS_MASK;

	if (ISHWADDR(address)) {
		#include "generated/hardware/hw_gavin_read_long.h"
		#include "generated/hardware/hw_beatrix_read_long.h"
		#include "generated/hardware/hw_vicky3a_read_long.h"
		#include "generated/hardware/hw_vicky3b_read_long.h"
	}
	unsigned int r = m68k_read_memory_16(address+2) + (m68k_read_memory_16(address) << 16);
	return r;
}

// *******************************************************************************************************************************
//													 Generic write routines
// *******************************************************************************************************************************

void m68k_write_memory_8(unsigned int address, unsigned int value){

	address &= ADDRESS_MASK;

	if (address < SRAM_END) {
		ramMemory[address] = value & 0xFF;
		return;
	}

	if (address >= VRAM_START && address <= VRAM_END) {
		videoMemory[address-VRAM_START] = value;
		return;
	}

	if (address >= FLASH_ADDRESS) {
		return;
	}

	#ifdef SDRAM_ENABLED
	if (address >= SDRAM_ADDRESS && address < SDRAM_ADDRESS+0x4000000) {
		sdMemory[address-SDRAM_ADDRESS] = value;
		return;
	}
	#endif

	if (ISHWADDR(address)) {
		#include "generated/hardware/hw_gavin_write_byte.h"
		#include "generated/hardware/hw_beatrix_write_byte.h"
		#include "generated/hardware/hw_vicky3a_write_byte.h"
		#include "generated/hardware/hw_vicky3b_write_byte.h"
		hwMemory[address-HARDWARE_START] = value;
		return;
	}
	if (logBadAddress) printf("Warning: Writing address $%08x PC:$%08x\n",address,PC);
}

void m68k_write_memory_16(unsigned int address, unsigned int value){

	address &= ADDRESS_MASK;

	if (ISHWADDR(address)) {
		#include "generated/hardware/hw_gavin_write_word.h"
		#include "generated/hardware/hw_beatrix_write_word.h"
		#include "generated/hardware/hw_vicky3a_write_word.h"
		#include "generated/hardware/hw_vicky3b_write_word.h"
	}
	m68k_write_memory_8(address+1,value & 0xFF);
	m68k_write_memory_8(address,value >> 8);
}

void m68k_write_memory_32(unsigned int address, unsigned int value){

	address &= ADDRESS_MASK;

	if (address == 0xFFFFFFFC) {
		logPrint(value);
		return;
	}

	if (ISHWADDR(address)) {
		#include "generated/hardware/hw_gavin_write_long.h"
		#include "generated/hardware/hw_beatrix_write_long.h"
		#include "generated/hardware/hw_vicky3a_write_long.h"
		#include "generated/hardware/hw_vicky3b_write_long.h"
	}
	m68k_write_memory_16(address+2,value & 0xFFFF);
	m68k_write_memory_16(address,value >> 16);
}

// *******************************************************************************************************************************
//							Duplicate R/W routines required by the CPU core for some reason
// *******************************************************************************************************************************

unsigned int inline m68k_read_immediate_16(unsigned int address){
	return m68k_read_memory_16(address);
}

unsigned int inline m68k_read_immediate_32(unsigned int address){
	return m68k_read_memory_32(address);
}

unsigned int m68k_read_disassembler_8  (unsigned int address){
	return m68k_read_memory_8(address);
}

unsigned int m68k_read_disassembler_16 (unsigned int address){
	return m68k_read_memory_16(address);
}

unsigned int m68k_read_disassembler_32 (unsigned int address){
	return m68k_read_memory_32(address);
}

// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Changes made
//	
//		Date 			Changes
//		---- 			-------
// 		10-03-2022  	Printing by write logging to $FFFFFFFFC (-4) does not trigger warnings.
//		11-03-2022 		Can write to flash, which does nothing, but doesn't warn.
//						Added 64Mb of SDRAM support.
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************
