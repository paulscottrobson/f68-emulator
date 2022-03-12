ifeq ($(OS),Windows_NT)
include ..\documents\common.make
else
include ../documents/common.make
endif

APPNAME = f68$(APPSTEM)

SOURCES = 	framework$(S)main.o framework$(S)gfx.o framework$(S)debugger.o \
			src$(S)sys_debug_f68.o src$(S)sys_processor.o src$(S)memory.o src$(S)srecord.o \
			src$(S)hardware.o src$(S)gavin.o src$(S)rendertext.o src$(S)renderbitmap.o src$(S)fileformats.o \
			cpu$(S)m68kcpu.o cpu$(S)m68kdasm.o cpu$(S)m68kops.o cpu$(S)softfloat.o
  			
CC = g++

.PHONY: all clean emulator test prebuild 

all: emulator
#	.$(S)$(APPNAME) 

run: emulator 
	.$(S)$(APPNAME) go

debug: emulator 
	.$(S)$(APPNAME) 

asample: emulator
	make -C assembly
	.$(S)$(APPNAME) assembly$(S)sample.s68 go

csample: emulator
	make -C c
	.$(S)$(APPNAME) c$(S)hello.s28 go

text:emulator
	make -C text
	.$(S)$(APPNAME) text$(S)text.s28 go

emulator: prebuild $(APPNAME)

rom:
	make -C ..$(S)rom

prebuild:
	make -C ..$(S)Musashi
	make -C setup
	$(CCOPY) ..$(S)Musashi$(S)*.h cpu
	$(CCOPY) ..$(S)Musashi$(S)*.o cpu
	$(CCOPY) ..$(S)Musashi$(S)softfloat$(S)*.o cpu

%.o:%.cpp
	$(CC) $(CXXFLAGS) -g -D INCLUDE_DEBUGGING_SUPPORT -I cpu -I framework -I include -I roms -c -o $@ $<

clean:
	$(CDEL) $(APPNAME) 
	$(CDEL) src$(S)*.o 
	$(CDEL) framework$(S)*.o cpu$(S)*.o cpu$(S)*.h
	make -C ..$(S)rom clean

$(APPNAME): $(SOURCES) 
	$(CC) $(SOURCES) $(LDFLAGS) $(SDL_LDFLAGS) -o $@
	
