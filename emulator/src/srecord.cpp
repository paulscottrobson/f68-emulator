// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		srecord.c
//		Purpose:	SRecord processors
//		Created:	24th February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <includes.h>

// *******************************************************************************************************************************
//
// 											Extract Hex from SREC
//
// *******************************************************************************************************************************

static int _SRecGetHex(char *s,int c) {
	int n = 0;
	while (c-- > 0) {
		int ch = toupper(*s);
		s++;
		if (ch >= 'A' && ch <= 'F') ch = ch - 7;
		n = n * 16 + (ch & 0x0F);
	}
	return n;
}

// *******************************************************************************************************************************
//
// 											Process one line of intel code
//
// *******************************************************************************************************************************

static int upper16bits = 0; 

static void _SRECProcessIntel(char *line) {
	int a,count;

	switch(line[8]) {
		case '4':												// 04 sets upper 16 bits
			a = _SRecGetHex(line+9,4);
			upper16bits = (a << 16);
			break;

		case '0':												// 00 is a data line.
			count = _SRecGetHex(line+1,2);						// byte count
			a = _SRecGetHex(line+3,4)|upper16bits;	 			// Load address
			for (int i = 0;i < count;i++) {
				int b = _SRecGetHex(line+9+i*2,2);
				m68k_write_memory_8(a+i,b); 	// Copy into memory.
			}
			break;

		case '5':												// 05 is start address
			a = _SRecGetHex(line+9,8);
			CPUOverrideReset(a);
			break;
	}
}

// *******************************************************************************************************************************
//
// 											Process one line of motorola code
//
// *******************************************************************************************************************************

static void _SRECProcessMotorola(char *line) {
	int a,count;
	switch(line[1]) {

		case '2':								// S2 is a data line (24 bit)
			count = _SRecGetHex(line+2,2)-3-1;	// 3 for address, 1 for checksum which I ignore
			a = _SRecGetHex(line+4,6); 			// Load address
			for (int i = 0;i < count;i++) {
				int b = _SRecGetHex(line+10+i*2,2);
				m68k_write_memory_8(a+i,b); 	// Copy into memory.
			}
			break;

		case '3':								// S3 is a data line (32 bit)
			count = _SRecGetHex(line+2,2)-4-1;	// 4 for address, 1 for checksum which I ignore
			a = _SRecGetHex(line+4,8); 			// Load address
			for (int i = 0;i < count;i++) {
				int b = _SRecGetHex(line+12+i*2,2);
				m68k_write_memory_8(a+i,b); 	// Copy into memory.
			}
			break;

		case '7':								// S7 sets the start address (32 bit)
			a = _SRecGetHex(line+4,8);
			CPUOverrideReset(a);
			break;

		case '8':								// S8 sets the start address (24 bit)
			a = _SRecGetHex(line+4,6);
			CPUOverrideReset(a);
			break;
	}
}

// *******************************************************************************************************************************
//
// 										Process Command Line. Return -1 to autorun
//
// *******************************************************************************************************************************

int SRECHandler(int argc,char *argv[]) {
	int autoRun = 0;
	char buffer[128];
	for (int i = 1;i < argc;i++) {
		if (strcmp(argv[i],"go") == 0) {
			autoRun = -1;
		} else {		
			upper16bits = 0;
			FILE *f = fopen(argv[i],"r");
			if (f == NULL)
				exit(fprintf(stderr,"Cannot find file %s\n",argv[i]));
			while (!feof(f)) {
				fgets(buffer,sizeof(buffer),f);
				//printf("[%s]\n",buffer);
				if (buffer[0] == 'S') _SRECProcessMotorola(buffer);
				if (buffer[0] == ':') _SRECProcessIntel(buffer);
			}
			fclose(f);
		}
	}
	return autoRun;
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
