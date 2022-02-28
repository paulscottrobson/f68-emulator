MEMORY
{
  out:     org=0x7FF0, len=0xffffff
  zero:    org=0, len=0x0100
  b0:     org=0x8000, len=0x4000
  b1:     org=0x8000, len=0x4000
  b2:     org=0x8000, len=0x4000
  b255:   org=0xC000, len=0x4000
  chr:     org=0x0000, len=0x4000
  ram:     org=0x0300, len=0x0500
}

NESMAPPER    = 4 ; /* mapper number */
NESPRG_BANKS = 4 ; /* number of 16K PRG banks */
NESCHR_BANKS = 2 ; /* number of 8K CHR banks */

SECTIONS
{
  header: {BYTE(0x4e);BYTE(0x45);BYTE(0x53);BYTE(0x1a);
           BYTE(NESPRG_BANKS);
           BYTE(NESCHR_BANKS);
           BYTE(NESMAPPER<<4);
           BYTE(NESMAPPER&0xf0);
           LONG(0);LONG(0);
          } >out

  text0:   { .=0x8000; *(text0) } >b0 AT>out
  rodata0: { *(rodata0) } >b0 AT>out
  bank0:   { *(bank0) } >b0 AT>out
  fill0:   { .=0xC000; } >b0 AT>out

  text1:   { .=0x8000; *(text1) } >b1 AT>out
  rodata1: { *(rodata1) } >b1 AT>out
  bank1:   { *(bank1) } >b1 AT>out
  fill1:   { .=0xC000; } >b1 AT>out

  text2:   { .=0x8000; *(text2) } >b2 AT>out
  rodata2: { *(rodata2) } >b2 AT>out
  bank2:   { *(bank2) } >b2 AT>out
  fill2:   { .=0xC000; } >b2 AT>out

  /* common bank */
  text:   { *(text) } >b255 AT>out
  .dtors: { *(.dtors) } >b255 AT>out
  .ctors: { *(.ctors) } >b255 AT>out
  rodata: { *(rodata) }  >b255 AT>out
  init:   { *(init) }  >b255 AT>out
  data:   { *(data) } >ram AT>out
  /* fill common bank */
  fill:   { .=.+0x10000-6-ADDR(init)-SIZEOF(init)-SIZEOF(data); } >b255 AT>out
  vectors:{ *(vectors) } >b255 AT>out

  chars:  {
     *(chars);
     RESERVE((NESCHR_BANKS*8192)-.-ADDR(chars));
  } >chr AT>out

  zpage (NOLOAD) : {*(zpage) *(zp1) *(zp2)} >zero
  bss (NOLOAD): {*(bss)} >ram

  __DS = ADDR(data);
  __DE = ADDR(data) + SIZEOF(data);
  __DC = LOADADDR(data)-0x8000;

  __STACK = 0x800;

  ___heap = ADDR(bss) + SIZEOF(bss);
  ___heapend = __STACK;
}
