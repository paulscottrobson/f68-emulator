STACKSTART = 0xC800;
STACKLEN   = 0x800;

MEMORY
{
 zero : org = 2 , len = 0x8d
 ram : org = 0x801, len=0xbfff
 stack : org = STACKSTART, len=STACKLEN
}

SECTIONS
{
  text : {*(text)} >ram
  .dtors : { *(.dtors) } > ram
  .ctors : { *(.ctors) } > ram
  rodata : {*(rodata)} >ram
  data: {*(data)} >ram
  init : {*(init)} >ram
  bss (NOLOAD): {*(bss)} >ram
  /* data copy section + zpage save */

  zpage (NOLOAD) : {*(zpage) *(zp1) *(zp2)} >zero

  __BB = ADDR(bss);
  __BE = ADDR(bss)+SIZEOF(bss);
  __ZB = ADDR(zpage);
  __ZS = SIZEOF(zpage);
  __ZC = ADDR(bss)+SIZEOF(bss)+SIZEOF(data);
  __DB = ADDR(data);
  __DE = ADDR(data)+SIZEOF(data);
  __DC = ADDR(bss)+SIZEOF(bss);
  __SE = STACKSTART+STACKLEN;
  ___heap = ADDR(bss)+SIZEOF(bss)+SIZEOF(data)+SIZEOF(zpage);
  ___heapend = STACKSTART-1;
}
