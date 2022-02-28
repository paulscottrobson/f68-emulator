MEMORY
{
  out:     org=0x7FF0, len=0xffffff
  zero:    org=0, len=0x0100
  b0:      org=0x8000, len=0x8000
  b1:      org=0x8000, len=0x8000
  chr:     org=0x0000, len=0x2000
  ram:     org=0x0300, len=0x0500
}

NESMAPPER    = 0 ; /* mapper number */
NESPRG_BANKS = 2 ; /* number of 16K PRG banks, change to 2 for NROM256 */
NESCHR_BANKS = 1 ; /* number of 8K CHR banks */
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

  text:   {*(text)} >b0 AT>out
  .dtors: { *(.dtors) } >b0 AT>out
  .ctors: { *(.ctors) } >b0 AT>out
  rodata: {*(rodata)}  >b0 AT>out
  init:   {*(init)}  >b0 AT>out
  data:   {*(data)} >ram AT>out
  /* fill program bank */
  fill: { .=.+0x10000-6-ADDR(init)-SIZEOF(init)-SIZEOF(data);} >b0 AT>out
  vectors:{ *(vectors)} >b0 AT>out

  chars:  {
     *(chars);
     RESERVE(8192-.-ADDR(chars));
  } >chr AT>out

  zpage (NOLOAD) : {*(zpage) *(zp1) *(zp2)} >zero
  bss (NOLOAD): {*(bss)} >ram

  __DS = ADDR(data);
  __DE = ADDR(data) + SIZEOF(data);
  __DC = LOADADDR(data);

  __STACK = 0x800;

  ___heap = ADDR(bss) + SIZEOF(bss);
  ___heapend = __STACK;
}
