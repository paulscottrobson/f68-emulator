ifeq ($(OS),Windows_NT)
include ..\..\documents\common.make
else
include ../../documents/common.make
endif

all:
	vasmm68k_mot sample.asm -align -Fsrec -o sample.s68 -L sample.lst -exec=start
