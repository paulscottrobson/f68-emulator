@echo off
set VBCC=..\..\vbcc_win
set OLDPATH=%PATH%
set PATH=%PATH%;%VBCC%\bin_win
vasmm68k_mot sample.asm -align -Fsrec -o sample.s68 -L sample.lst -exec=start
set PATH=%OLDPATH%