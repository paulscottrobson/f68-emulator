rem @echo off
set VBCC=..\..\..\vbcc_win
set OLDPATH=%PATH%
set PATH=%PATH%;%VBCC%\bin_win
pushd FoenixMCP-a2560k\src
echo %VBCC%
set
make clean
make UNIT=a2560k MEMORY=flash 
popd
set PATH=%OLDPATH%

rem
rem ... I give up. I've already wasted too much time with Microsoft's rubbish.
rem