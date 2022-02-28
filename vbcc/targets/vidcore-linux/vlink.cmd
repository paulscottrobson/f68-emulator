PHDRS {
  text PT_LOAD;
  data PT_LOAD;
}

SECTIONS
{
        .text : { *(.text) *(.barrier) *(.dtors) *(.ctors) *(.data) *(.bss)} :text
;        .data : {  } :data
;        .bss : {  }
}

