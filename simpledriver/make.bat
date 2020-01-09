@echo off
rem CONFIGURATION VARIABLES
set ddkdir=c:\WinDDK\7600.16385.1
rem set architect=x64
set architect=
set winver=wnet

rem PROJECT VARIABLES
set artifactname=simpledrv
set cfiles=driver.c

rem PREPARE OUTPUT DIRECTORY
rd /s /q bin 2> nul
mkdir bin 2> nul
pushd .
call %ddkdir%\bin\setenv.bat %ddkdir% chk %architect% %winver%
if [%architect%]==[] set architect=x86
popd

rem CREATE MAKEFILES INSTRUCT DDK HOW TO BUILD
cd src
echo !INCLUDE $(NTMAKEENV)\makefile.def > makefile
echo TARGETNAME=%artifactname% > sources
echo TARGETTYPE=DRIVER >> sources
echo TARGETPATH=obj >> sources
rem echo TARGETLIBS=$(DDK_LIB_PATH)\\ndis.lib $(DDK_LIB_PATH)\\iointex.lib >> sources
echo SOURCES=%cfiles% >> sources

rem INVOKE BUILD COMMANDS
build
pushd .
cd ..\bin
xcopy /s /e /k /f /h ..\src\objchk_%winver%_%architect%\* . 1>nul 2>nul
popd

rem CLEAN UP
rd /s /q objchk_%winver%_%architect%
del buildchk_%winver%_%architect%.log 2> nul
del buildchk_%winver%_%architect%.wrn 2> nul
del makefile 2> nul
del sources 2> nul
cd ..

