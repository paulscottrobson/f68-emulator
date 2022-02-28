# f68-emulator
A2560K Emulator

Note this is *still* in alpha, though it's not far off going into Beta.

Building it
===========
Standard make requires SDL2 only. 

Python 3 is technically required to build, but you can comment make -C setup from the makefile and it will work, albeit with the 
wrong timestamp. Python is only used to process the configuration file.

Builds on Windows with mingw32, SDL2 64 bit installed in c:\sdl2 and needs SDL2.dll and libwinpthread-1.dll - I will try to keep this
up to date - ish as I can build it on Virtual box. Seems to run okay. For the makefiles you need the Chocolatey Make, which is version
4.3. 

When building a pull do a make clean first so old .o files from another OS don't get in the way, then build with MAKE -B

I'm working on the bitmap at present so the delay is longer at the start, pressing a key after a couple of seconds clears the bitmap 
(which you can't see yet !)

Running it
==========

In the emulator directory either: 

./f68 <files>					(debug)
or
./f68 <files> go 				(run)

Where <files> are either Motorola SREC or Intel Hex format. See note below about -exec on vasm.

When an executable SRecord is loaded it sets the run address, so the F1 key now runs that program instead of resetting the CPU. If there are
more than one executables it's the last execute address. See testasm directory for an example file.

Debug keys
==========

0-9A-F 			Change code position (doesn't change PC)
With Shift 		Change data position
Ctrl key 		Display text not hex bytes
ESC 			Quit

F1 				Reset/Run program.
F2 				Set viewed code to PC.
F5 				Start emulation.
F6 				Stop
F7 				Single Step
F8 				Step over JSR/BSR/Trap
F9 				Set Breakpoint

*** NOTE ***

When building s68 or hex files using VASM, the option -exec=<start label> (or just -exec if the file runs from start) must be on the command line.

If it isn't, there is no way of telling where the program starts. 

Samples
=======

asample is an assembler sample based on the original by P.Weingar. It shows copying to the screen and using the O/S

make asample should run it, when it boots press F1 to start.

make csample should run a similar C program.

Logging
=======
The emulator has its own seperate logger, which operates by writing an ASCII string to address 0xFFFFFFFFC (normally Flash ROM)

e.g. the following code will print Hello, world and the current PC value. 

    *((long *)-4) = (long)"Hello, world";
