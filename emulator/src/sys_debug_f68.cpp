// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		sys_debug_f68.c
//		Purpose:	Debugger Code (System Dependent)
//		Created:	22nd February 2022
//		Author:		Paul Robson (paul@robsons->org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <includes.h>

#define DBGC_ADDRESS 	(0x0F0)														// Colour scheme.
#define DBGC_DATA 		(0x0FF)														// (Background is in main.c)
#define DBGC_HIGHLIGHT 	(0xFF0)

static int renderCount = 0;

// *******************************************************************************************************************************
//											This renders the debug screen
// *******************************************************************************************************************************

static const char *labels[] = { "PC","SR","","BK",NULL };
static const char *labels2[] = { "SP","USP","ISP","CY",NULL };

#define IR (DW_WIDTH-8)
#define IL (IR-4-1-8)

void DBGXRender(int *address,int showDisplay, int scale) {

	int n = 0,xc,yc;
	char buffer[64];
	const char *sr = "XNZVC";
	CPUSTATUS *s = CPUGetStatus();

	MEMSetAddressLog(0);																// Address log off.

	if (showDisplay == 0) {
		GFXSetCharacterSize(DW_WIDTH,DW_HEIGHT);

		for (n = 0;n < 8;n++) {
			sprintf(buffer,"D%d",n);
			GFXString(GRID(IL-4,n),buffer,GRIDSIZE,DBGC_ADDRESS,-1);
			sprintf(buffer,"A%d",n);
			GFXString(GRID(IR-4,n),buffer,GRIDSIZE,DBGC_ADDRESS,-1);
			GFXNumber(GRID(IL,n),s->d[n],16,8,GRIDSIZE,DBGC_DATA,-1);
			GFXNumber(GRID(IR,n),s->a[n],16,8,GRIDSIZE,DBGC_DATA,-1);
		}

		DBGVerticalLabel(IL-4,8,labels,DBGC_ADDRESS,-1);								// Draw the labels for the register
		DBGVerticalLabel(IR-4,8,labels2,DBGC_ADDRESS,-1);	

		#define DN(n,w) { GFXNumber(GRID(xc,yc),n,16,w,GRIDSIZE,DBGC_DATA,-1);yc++; }

		xc = IL;yc = 8;
		DN(s->pc,8);DN(s->sr,4);
		for (n = 0;n < 5;n++) {
			int on = (s->sr & (0x10 >> n));
			GFXCharacter(GRID(xc+n,yc),on ? sr[n] : '.',GRIDSIZE,on ? DBGC_HIGHLIGHT : DBGC_ADDRESS,-1);
		}
		yc++;DN(address[3],8);
		xc = IR;yc = 8;
		DN(s->sp,8);DN(s->usp,8);DN(s->isp,8);DN(s->cycles,8);

		n = 0;
		int a = address[1];																// Dump Memory.
		for (int row = 16;row < DW_HEIGHT;row++) {
			GFXNumber(GRID(4,row),a,16,8,GRIDSIZE,DBGC_ADDRESS,-1);
			for (int col = 0;col < 16;col++) {
				if (GFXIsKeyPressed(GFXKEY_CONTROL)) {
					int c = CPUReadMemory(a);
					if (c < 0x20 || c > 0x7F) c = '.';
					GFXCharacter(GRID(13+col*3,row),c,GRIDSIZE,DBGC_DATA,-1);
				} else {
				GFXNumber(GRID(13+col*3,row),CPUReadMemory(a),16,2,GRIDSIZE,DBGC_DATA,-1);
				}	
				a = (a + 1) & ADDRESS_MASK;
			}		
		}

		int p = address[0];																// Dump program code. 

		for (int row = 0;row < 15;row++) {
			int isPC = (p == DEBUG_HOMEPC());											// Tests.
			int isBrk = (p == address[3]);
			GFXNumber(GRID(0,row),p,16,8,GRIDSIZE,isPC ? DBGC_HIGHLIGHT:DBGC_ADDRESS,	// Display address / highlight / breakpoint
																		isBrk ? 0xF00 : -1);
			int c = m68k_disassemble(buffer, p, PROCESSOR_TYPE);
			char *ps = strchr(buffer,';');
			if (ps != NULL) *ps = '\0';
			GFXString(GRID(9,row),buffer,GRIDSIZE,isPC ? DBGC_HIGHLIGHT:DBGC_DATA,-1);	// Print the mnemonic
			p += c;
		}
	} else {
		MEMRenderDisplay(scale);
	}
	MEMSetAddressLog(1);																// Address log on.
}	

// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Changes made
//	
//		Date 			Changes
//		---- 			-------
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************
