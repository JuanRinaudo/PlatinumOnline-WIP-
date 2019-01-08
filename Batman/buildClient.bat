@echo off

pushd ..
mkdir Build
pushd Build
mkdir Client
pushd Client
mkdir Windows
pushd Windows
REM robocopy ..\..\Assets\Windows Assets /MIR /NFL /NDL /NJH /NJS
REM robocopy ..\..\Libraries\bin\x64 ..\windows /NFL /NDL /NJH /NJS
REM cl -Zi -FC ..\..\Client\Source\Main.cpp /D __WINDOWS__ /I ..\..\Libraries\include /link user32.lib Gdi32.lib Kernel32.lib lib\x64\freeglut.lib lib\x64\glew32.lib lib\x64\OpenAL32.lib /LIBPATH:"..\..\Libraries"
cl -Zi -FC ..\..\..\Client\Source\Client.cpp /D __WINDOWS__ /link user32.lib Gdi32.lib Kernel32.lib
popd
popd
popd
popd