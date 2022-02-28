STACKSTART = 0xC800;
STACKLEN   = 0x800;

PAGESIZE = 0x4000;
PAGEADDR = 0x8000;

MEMORY
{
 zero : org = 2 , len = 0x8d
 ram : org = 0x801, len=0x78ff
 stack : org = STACKSTART, len=STACKLEN
 reufile : org = 0x20000, len=0x1000000
 b0 : org = PAGEADDR, len = PAGESIZE
 b1 : org = PAGEADDR, len = PAGESIZE
 b2 : org = PAGEADDR, len = PAGESIZE
 b3 : org = PAGEADDR, len = PAGESIZE
 b4 : org = PAGEADDR, len = PAGESIZE
 b5 : org = PAGEADDR, len = PAGESIZE
 b6 : org = PAGEADDR, len = PAGESIZE
 b7 : org = PAGEADDR, len = PAGESIZE

}

SECTIONS
{
  text : {*(text)} >ram
  .dtors : { *(.dtors) } > ram
  .ctors : { *(.ctors) } > ram
  rodata : {*(rodata)} >ram
  data: {*(data)} >ram
  init : {*(init)} >ram
  zpage (NOLOAD) : {*(zpage) *(zp1) *(zp2)} >zero
  bss (NOLOAD): {*(bss)} >ram

  b0: {.=PAGEADDR; *(text0) *(rodata0) *(data0) *(bss0) 
       RESERVE(PAGEADDR+PAGESIZE-.);
      } >b0 AT>reufile

  b1: {.=PAGEADDR; *(text1) *(rodata1) *(data1) *(bss1)
       RESERVE(PAGEADDR+PAGESIZE-.);
      } >b1 AT>reufile

  b2: {.=PAGEADDR; *(text2) *(rodata2) *(data2) *(bss2)
       RESERVE(PAGEADDR+PAGESIZE-.);
      } >b2 AT>reufile

  b3: {.=PAGEADDR; *(text3) *(rodata3) *(data3) *(bss3)
       RESERVE(PAGEADDR+PAGESIZE-.);
      } >b3 AT>reufile

  b4: {.=PAGEADDR; *(text4) *(rodata4) *(data4) *(bss4)
       RESERVE(PAGEADDR+PAGESIZE-.);
      } >b4 AT>reufile

  b5: {.=PAGEADDR; *(text5) *(rodata5) *(data5) *(bss5)
       RESERVE(PAGEADDR+PAGESIZE-.);
      } >b5 AT>reufile

  b6: {.=PAGEADDR; *(text6) *(rodata6) *(data6) *(bss6)
       RESERVE(PAGEADDR+PAGESIZE-.);
      } >b6 AT>reufile

  b7: {.=PAGEADDR; *(text7) *(rodata7) *(data7) *(bss7)
       RESERVE(PAGEADDR+PAGESIZE-.);
      } >b7 AT>reufile




  __BB = ADDR(bss);
  __BE = ADDR(bss)+SIZEOF(bss);
  __SE = STACKSTART+STACKLEN;
  ___heap = ADDR(bss)+SIZEOF(bss);
  ___heapend = STACKSTART-1;
}
