MEMSTART = 0x200;
STACKLEN = 0x400;

MEMORY
{
 zero : org = 0 , len = 256
 ram : org = 0x200, len=0xFFFF-STACKLEN
}

SECTIONS
{
  text : {*(text)} >ram
  .dtors : { *(.dtors) } > ram
  .ctors : { *(.ctors) } > ram
  rodata : {*(rodata)} >ram
  data: {*(data)} >ram
  bss: {*(bss)} >ram
  zpage (NOLOAD) : {*(zpage) *(zp1) *(zp2)} >zero

  ___heap = ADDR(bss) + SIZEOF(bss);
  ___heapend = 0xFFFF-STACKLEN;
}

