#ifndef _jaglib_h
#define _jaglib_h 1

#include <stdint.h>
#include <stdlib.h>

/* Blitter specific functions */ 
void jag_wait_blitter_ready();
void jag_memset8(void *dest,uint16_t repcount,uint16_t count,uint8_t value);
void jag_memset32(void *dest,uint16_t repcount,uint16_t count,uint32_t value);
void jag_memcpy16p(void *dest,const void *src,uint16_t repcount,uint16_t wordcount);
void jag_memcpy32p(void *dest,const void *src,uint16_t repcount,uint16_t longcount);

/* Object list specific functions */
void jag_set_olp(__reg("d0") const void *ol);
void jag_attach_olp(const void* olp);
void jag_append_olp(const void* olp);
void jag_restore_ol();

/* Console specific functions */
void jag_console_clear();
void jag_console_save_bmp(const char *fname);
void jag_console_show();
void jag_console_hide();
void jag_console_set_cursor(uint16_t x,uint8_t y);
void jag_init_message();
void jag_welcome_message();

/* Small small debugger */
void jag_debug();

/* Video specific functions */
#define CONSOLE_BMP_WIDTH	320
#define CONSOLE_BMP_HEIGHT	200
extern uint16_t jag_hdb;
extern uint16_t jag_hde;
extern uint16_t jag_vdb;
extern uint16_t jag_vde;
extern uint16_t jag_width;
extern uint16_t jag_height;

void jag_wait_vbl();

uint16_t jag_custom_interrupt_handler();
void jag_set_cpu_int_mask(uint16_t mask);

#define toRgb16(r,g,b) ((((r)&0xf8) << 8) | (((b)&0xf8) << 3) | (((g)&0xfc)>>2))
void jag_set_indexed_color(uint16_t index,uint16_t color);
extern uint8_t *jag_vidmem;
extern uint64_t *jag_listbuf;

/* Declaration for custom io function */
int jag_io_open(const char *name,const char *mode);
int jag_io_close(int handle);
long jag_io_seek(int handle,long offset,int origin);
size_t jag_io_read(int handle,char *buffer,size_t length);
size_t jag_io_write(int handle,const char *buffer, size_t length);

/* joystick functions */
#define STICK_READ_DIRECTIONS_A_ONLY 1
#define STICK_READ_ALL 0

#define STICK_OPTION	(1<<0)
#define STICK_HASH		(1<<1)
#define STICK_9			(1<<2)
#define STICK_6			(1<<3)
#define STICK_3			(1<<4)
#define STICK_C			(1<<5)
#define STICK_0			(1<<6)
#define STICK_8			(1<<7)
#define STICK_5			(1<<8)
#define STICK_2			(1<<9)
#define STICK_B			(1<<10)
#define STICK_STAR		(1<<11)
#define STICK_7			(1<<12)
#define STICK_4			(1<<13)
#define STICK_1			(1<<14)
#define STICK_PAUSE		(1<<15)
#define STICK_A			(1<<16)
#define STICK_UP		(1<<17)
#define STICK_DOWN		(1<<18)
#define STICK_LEFT		(1<<19)
#define STICK_RIGHT		(1<<20)
uint32_t jag_read_stick0(uint16_t readdirectionsonly);
uint32_t jag_read_stick1(uint16_t readdirectionsonly);
void jag_audio_mute(uint16_t mute);

/* dsp functions */
void jag_dsp_load(void *loadadr,const void *codestartadr, uint16_t count);
uint8_t jag_dsp_is_running();
uint8_t jag_dsp_go(const void *dspstartadr, uint16_t addFlags);
void jag_dsp_wait();

/* gpu functions */
void jag_gpu_load(void *loadadr,const void *codestartadr, uint16_t count);
uint8_t jag_gpu_is_running();
uint8_t jag_gpu_go(const void *gpustartadr, uint16_t addFlags);
void jag_gpu_wait();

/* SkunkBoard specific functions*/
void skunkRESET();
void skunkCONSOLEWRITE(__reg("a0") char *txt);
void skunkCONSOLECLOSE();
__reg("a0") char *skunkCONSOLEREAD(__reg("a0") char *buffer,__reg("d0") uint16_t maxbytes); // maxbytes max 4064
void skunkNOP();
void skunkFILEOPEN(__reg("a0") const char *filename,__reg("d0") uint8_t mode); // mode=0 (write), move=1 (read)
void skunkFILEWRITE(__reg("a0") const uint8_t *data,__reg("d0")  uint16_t count); // count max. 4060, even
__reg("d0") size_t skunkFILEREAD(__reg("a0") char *buffer,__reg("d0") uint16_t maxbytes); // maxbytes max 4064
void skunkFILECLOSE();
extern uint32_t skunkConsoleUp;
extern uint16_t jag_console_hide_startup;

#define JAG_CONSOLE_BACKGROUND_COLORINDEX	253
#define JAG_CONSOLE_BACKGROUND_COLORINDEX32	0xfdfdfdfd
#define JAG_CONSOLE_STDOUT_COLORINDEX		254
#define JAG_CONSOLE_STDERR_COLORINDEX		255

uint16_t jag_get_sr() =	"\tmove\tsr,d0";
void jag_set_sr(__reg("d0") uint16_t sr) = "\tmove\td0,sr";

#pragma dontwarn 51
typedef struct
{
	uint64_t reserved0 : 21; 
	uint64_t link : 19; 
	uint64_t reserved1 : 7; 
	uint64_t cc : 3; 
	uint64_t ypos : 11; 
	uint64_t type : 3; 
} op_branch_object;

typedef struct
{
	 
	struct {
		uint64_t data : 21; 
		uint64_t link : 19; 
		uint64_t height : 10; 
		uint64_t ypos : 11; 
		uint64_t type : 3; 
	} p0;
	 
	struct {
		uint64_t reserved : 9; 
		uint64_t firstpix : 6; 
		uint64_t release : 1; 
		uint64_t trans : 1; 
		uint64_t rmw : 1; 
		uint64_t reflect : 1; 
		uint64_t index : 7; 
		uint64_t iwidth : 10; 
		uint64_t dwidth : 10; 
		uint64_t pitch : 3; 
		uint64_t depth : 3; 
		uint64_t xpos : 12; 
	} p1;
} op_bmp_object;

typedef struct {
	uint64_t data1 : 32; 
	uint64_t data2 : 28; 
	uint64_t int_flag : 1; 
	uint64_t type : 3; 
} op_stop_object;

typedef struct
{
	 
	struct {
		uint64_t data : 21; 
		uint64_t link : 19; 
		uint64_t height : 10; 
		uint64_t ypos : 11; 
		uint64_t type : 3; 
	} p0;
	 
	struct {
		uint64_t reserved : 9; 
		uint64_t firstpix : 6; 
		uint64_t release : 1; 
		uint64_t trans : 1; 
		uint64_t rmw : 1; 
		uint64_t reflect : 1; 
		uint64_t index : 7; 
		uint64_t iwidth : 10; 
		uint64_t dwidth : 10; 
		uint64_t pitch : 3; 
		uint64_t depth : 3; 
		uint64_t xpos : 12; 
	} p1;
	
	struct {
		uint64_t reserved2 : 40; 
		uint64_t remainder : 8; 
		uint64_t vscale : 8;
		uint64_t hscale : 8;
	} p2;
	
	struct {
		uint64_t unused : 64; 
	} p3;
} op_bmp_object_scaled;
#pragma popwarn

extern op_bmp_object *jag_console_bmp;
extern op_branch_object *jag_logical_root;

#endif
