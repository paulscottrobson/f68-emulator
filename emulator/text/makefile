ifeq ($(OS),Windows_NT)
include ..\..\documents\common.make
else
include ../../documents/common.make
endif


all:
	vc +$(VBCC)/config/a2560-s28 -o text.s28 main.c lib_general.c lib_general_a2560.c lib_text.c lib_text_test.c

clean:
	$(CDEL) text.s28
	$(CDEL) mapfile

#
# 		Sorry, this, like most other things, doesn't work on Windoze because it's rubbish Microsoft bodge #39173428
#
#		You'll have to use a batch file or something.
#