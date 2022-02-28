
MEMORY
{
ram : org = 0x1800040, l = 0xffffff
}


SECTIONS
{
	.debug_abbrev 0 : { *(.debug_abbrev) } 
	.debug_info 0 : { *(.debug_info) *(.debug_loc) }
	.debug_line 0 : { *(.debug_line) }
	.debug_pubnames 0 : { *(.debug_pubnames) }
	.debug_aranges 0 : { *(.debug_aranges) }
 	.text : { *(.text) } > ram
	.sdata2 : { *(.sdata2) } > ram
	.rodata : { *(.rodata) } > ram
	.dtors : { *(.dtors) } > ram
	.ctors : { *(.ctors) } > ram
	.sdata : { *(.sdata) } > ram
	.data : { *(.data) } > ram
	.got : { *(.got) } > ram
	.bss : { *(.bss) } > ram
	.sbss : { *(.sbss) } > ram
	__HEAPSTART = .;
}

