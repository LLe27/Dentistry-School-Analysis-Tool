@echo off

REM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
REM ~~~~~~~~~~~~~~~~~~~~~~~~~~PARAMETERS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
REM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
REM Set the path to the Qt install folder (not the 5.5 subfolder).
SET PATH_TO_QT=C:\Qt

REM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
REM ~~~~~~~~~~~~~~~~~~~~~~~~~AUTO-COMPILE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
REM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
echo Setting paths...
SET PATH=%PATH_TO_QT%\5.5\mingw492_32\bin;%PATH_TO_QT%\Tools\mingw492_32\bin;%PATH_TO_QT%\Tools\QtCreator\bin;%PATH%
SET PATH_PROJECT=%cd%\..\project\project.pro
SET PATH_COMPILE=%cd%\compile
SET PATH_COMPILE_EXE=%cd%\compile\release\project.exe
SET PATH_COMPILE_DLL="%cd%\compiled exe with dll"

echo -----------------------------------------------------------------
echo Moving to compile subfolder
if not exist %PATH_COMPILE% mkdir %PATH_COMPILE%
cd %PATH_COMPILE%

echo -----------------------------------------------------------------
echo Creating Makefile with qmake...
qmake -makefile %PATH_PROJECT%

echo -----------------------------------------------------------------
echo Compiling from Makefile (using mingw32)...
jom

echo -----------------------------------------------------------------
echo Moving executable to folder with dlls...
xcopy /y/q %PATH_COMPILE_EXE% %PATH_COMPILE_DLL%

REM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
echo -----------------------------------------------------------------
echo Complete!
pause