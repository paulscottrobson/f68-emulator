@echo off
set VBCC=..\..\vbcc_win
set OLDPATH=%PATH%
set PATH=%PATH%;%VBCC%\bin_win
vc +%VBCC%\config\a2560-s28-win32 -o hello.s28 hello.c
set PATH=%OLDPATH%