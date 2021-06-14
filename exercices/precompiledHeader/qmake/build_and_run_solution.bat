@echo off

set QTDIR=C:\dev\libs\Qt\5.14.0\msvc2017_64\bin
set VCDIR=C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional
set WIN_SDK=10.0.17763.0

REM NE PLUS RIEN MODIFIER

REM Converti les noms longs en noms courts

echo %~s1 "%QTDIR%" > DIRtempName.txt
set /p QTDIR=<DIRtempName.txt

echo %~s1 "%VCDIR%" > DIRtempName.txt
set /p VCDIR=<DIRtempName.txt

del DIRtempName.txt

set PATH=%QTDIR%\bin;
echo %PATH%

REM Mise en place du path pour Visual
pushd %VCDIR%\VC\Auxiliary\Build
	call vcvarsall.bat x64
popd

start /WAIT /B %QTDIR% qmake.exe -tp vc -r visual.pro

start /WAIT "Visual" devenv visual.vcxproj

@echo off
echo.
set /p id="press ENTER to quit"

goto:eof

REM Functions here...

:convertToShortPath 
echo %~s1
EXIT /B 0

goto:eof