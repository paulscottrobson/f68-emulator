STACKLEN = 0x100;
MEMSTART = 0x2000;
MEMEND   = 0xB000;

MEMORY
{
 zero : org = 0x82 , len = 0x7e
 vec : org = 0x2e0, len = 2
 ram : org = MEMSTART+STACKLEN, len=MEMEND-MEMSTART-STACKLEN
 out : org = MEMSTART, len = 0xffff
}

SECTIONS
{
  vec : {SHORT(MEMSTART+STACKLEN); } > vec
  text : {*(text)} >ram
  .dtors : { *(.dtors) } > ram
  .ctors : { *(.ctors) } > ram
  rodata : {*(rodata)} >ram
  data: {*(data)} >ram
  init : {*(init)} >ram
  zpage (NOLOAD) : {*(zpage) *(zp1) *(zp2)} >zero
  bss (NOLOAD): {*(bss)} >ram

  __SP = MEMSTART+STACKLEN;
  __BB = ADDR(bss);
  __BE = ADDR(bss)+SIZEOF(bss);
  ___heap = ADDR(bss) + SIZEOF(bss);
}
