@echo off
pushd release

IF "%1"=="-d" (
	echo Running DEBUG Version
	DebugGame.exe
) ELSE (
	RunGame.exe
)

popd