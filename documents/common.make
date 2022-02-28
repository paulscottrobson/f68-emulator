# ***********************************************************************************
#
#										Common Build 
#
# ***********************************************************************************
#
#	NB: Windows SDL2 is hard coded.
#
.ONESHELL:
ifeq ($(OS),Windows_NT)
CCOPY = copy
CMAKE = make
CDEL = del /Q
CDELQ = >NUL
APPSTEM = .exe
S = \\
SDLDIR = C:\\sdl2
CXXFLAGS = -I$(SDLDIR)$(S)include$(S)SDL2 -I . 
LDFLAGS = -lmingw32 -static-libgcc -static-libstdc++
SDL_LDFLAGS = -L$(SDLDIR)$(S)lib  -lSDL2main  -lSDL2 
ASMEND = 
else
CCOPY = cp
CDEL = rm -f
CDELQ = 
CMAKE = make
APPSTEM =
S = /
SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LDFLAGS = $(shell sdl2-config --libs)
CXXFLAGS = $(SDL_CFLAGS) -O2 -DLINUX  -fmax-errors=5 -I.  
LDFLAGS =
ASMEND = 
endif
#
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
#
#		Root directory
#
ROOTDIR = $(mkfile_dir)..$(S)
#
# 		Set up to compile VBCC
#
ifeq ($(OS),Windows_NT)
# God alone knows.
else
export VBCC=$(ROOTDIR)$(S)vbcc
export PATH+=:$(VBCC)$(S)bin
endif
