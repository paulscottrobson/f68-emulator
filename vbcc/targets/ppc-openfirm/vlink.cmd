ENTRY(_start)

PHDRS {
  main PT_LOAD FILEHDR PHDRS;
}

SECTIONS
{
  . = 0x400000;
  /* put all sections into a single main segment: */
  .init           : { *(.init) } :main
  .text           : { *(.text) }
  .fini           : { *(.fini) }
  .rodata         : { *(.rodata .rodata.*) }
  .sdata2         : { *(.sdata2 .sdata2.*) }
  .sbss2          : { *(.sbss2 .sbss2.*) }

  .data           : {
    *(.data .data.*)
    VBCC_CONSTRUCTORS_ELF
  }
  .got            : { *(.got.plt) *(.got) }
  _SDA_BASE_ = . + 0x8000;
  .sdata          : {
    *(.sdata .sdata.* .tocd)
  }

  __bss_start = .;
  .sbss           : {
    *(.sbss .sbss.*)
    *(.scommon)
  }
  .plt            : { *(.plt) }
  .bss            : {
    *(.bss .bss.*)
    *(COMMON)
   . = ALIGN(32 / 8);
  }
  . = ALIGN(32 / 8);
  __end = .;

  .comment       0 : { *(.comment) }

  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
}
