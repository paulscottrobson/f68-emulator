MEMORY
{
  ram : org = 0x0000, len = 0x8000
  rom : org = 0x8000, len = 0x7FFD
  res : org = 0xFFFE, len = 2
}

SECTIONS {
	.text: { *(.text) } > rom
	.dtors : { *(.dtors) } > rom
	.ctors : { *(.ctors) } > rom
	.rodata: { *(.rodata) } > rom
	.dpage: { *(.dpage) } > ram
	.data: { *(.data) } > ram AT> rom
	.bss (NOLOAD) : { *(.bss) } > ram
	.res: { BYTE(0x80);BYTE(0); } > res

	__BS = ADDR(.bss);
	__BL = SIZEOF(.bss);
	__DS = ADDR(.data);
	__DC = LOADADDR(.data);
	__DL = SIZEOF(.data);

	__STACK = 0x8000;

}
