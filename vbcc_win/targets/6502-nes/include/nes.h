/* NES hardware access */

#define PPUCTRL   ((volatile unsigned char*)0x2000)
#define PPUMASK   ((volatile unsigned char*)0x2001)
#define PPUSTATUS ((volatile unsigned char*)0x2002)
#define OAMADDR   ((volatile unsigned char*)0x2003)
#define OAMDATA   ((volatile unsigned char*)0x2004)
#define PPUSCROLL ((volatile unsigned char*)0x2005)
#define PPUADDR   ((volatile unsigned char*)0x2006)
#define PPUDATA   ((volatile unsigned char*)0x2007)
#define DMCFREQ   ((volatile unsigned char*)0x4010)
#define OAMDMA    ((volatile unsigned char*)0x4014)
#define CTRLPORT1 ((volatile unsigned char*)0x4016)
#define CTRLPORT2 ((volatile unsigned char*)0x4017)
