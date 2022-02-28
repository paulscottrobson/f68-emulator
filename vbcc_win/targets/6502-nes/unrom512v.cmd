MEMORY
{
  out:     org=0x7FF0, len=0xffffff
  zero:    org=0, len=0x0100
  b0:      org=0x8000, len=0x4000
  b1:      org=0x8000, len=0x4000
  b2:      org=0x8000, len=0x4000
  b7:      org=0xC000, len=0x4000
  ram:     org=0x0300, len=0x0500
}

NESMAPPER    = 2 ; /* mapper number */
NESPRG_BANKS = 4 ; /* number of 16K PRG banks */
NESCHR_BANKS = 0 ; /* number of 8K CHR banks */
NESMIRRORING = 1 ; /* 0 horizontal, 1 vertical, 8 four screen */

SECTIONS
{
  header: {BYTE(0x4e);BYTE(0x45);BYTE(0x53);BYTE(0x1a);
           BYTE(NESPRG_BANKS);
           BYTE(NESCHR_BANKS);
           BYTE(NESMIRRORING|(NESMAPPER<<4));
           BYTE(NESMAPPER&0xf0);
           LONG(0);LONG(0);
          } >out

	/* banks 0..2 */
	text0: { .=0x8000; *(text0) } >b0 AT>out
	rodata0: { *(rodata0) } >b0 AT>out
	chars: { *(chars) } >b0 AT>out
        bank0: { *(bank0) } >b0 AT>out
	fill0: { .=0xC000; } >b0 AT>out

	text1: { .=0x8000; *(text1) } >b1 AT>out
	rodata1: { *(rodata1) } >b1 AT>out
        bank1: { *(bank1) } >b1 AT>out
	fill1: { .=0xC000; } >b1 AT>out

	text2: { .=0x8000; *(text2) } >b2 AT>out
	rodata2: { *(rodata2) } >b2 AT>out
        bank2: { *(bank2) } >b2 AT>out
	fill2: { .=0xC000; } >b2 AT>out

	/* common bank */
  text:   { *(text) } >b7 AT>out
  .dtors: { *(.dtors) } >b7 AT>out
  .ctors: { *(.ctors) } >b7 AT>out
  rodata: { *(rodata) }  >b7 AT>out
  init:   { *(init) }  >b7 AT>out
  data:   { *(data) } >ram AT>out
  /* fill common bank */
  fill:   { .=.+0x10000-6-ADDR(init)-SIZEOF(init)-SIZEOF(data); } >b7 AT>out
  vectors:{ *(vectors) } >b7 AT>out

  zpage (NOLOAD) : {*(zpage)} >zero
  bss (NOLOAD): {*(bss)} >ram

  __DS = ADDR(data);
  __DE = ADDR(data) + SIZEOF(data);
  __DC = LOADADDR(data)-0x8000; /* it's a patch */
  __STACK = 0x800;

  ___heap = ADDR(bss) + SIZEOF(bss);
  ___heapend = __STACK;
}
