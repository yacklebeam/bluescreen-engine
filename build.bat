@echo off
IF NOT EXIST build mkdir build
pushd build

IF "%1"=="-d" (
	echo Building DEBUG Version
	set COMPILERFLAGS=-nologo /Fe../release/DebugGame.exe /EHsc /FC /I"C:\Users\Jacob\SFML-2.3\include"
	set LINKERFLAGS=/link /SUBSYSTEM:CONSOLE /INCREMENTAL:NO /LIBPATH:C:\Users\Jacob\SFML-2.3\lib /MACHINE:X86
	set LIBS=opengl32.lib user32.lib kernel32.lib gdi32.lib winmm.lib "sfml-graphics.lib" "sfml-window.lib" "sfml-system.lib"
) ELSE (
	echo Building RELEASE Version
	set COMPILERFLAGS=-nologo /DRELEASE /Fe../release/RunGame.exe /EHsc /FC /I"C:\Users\Jacob\SFML-2.3\include"
	set LINKERFLAGS=/link /SUBSYSTEM:WINDOWS /INCREMENTAL:NO /LIBPATH:C:\Users\Jacob\SFML-2.3\lib /MACHINE:X86
	set LIBS=opengl32.lib user32.lib kernel32.lib gdi32.lib winmm.lib "sfml-graphics.lib" "sfml-window.lib" "sfml-system.lib"
)

cl %COMPILERFLAGS% ../src/main.cpp %LIBS% %LINKERFLAGS%

popd