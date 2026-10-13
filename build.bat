@echo off
setlocal enabledelayedexpansion
REM ===================================================================
REM  Route Bank System - Windows build script (MSVC / C++17)
REM
REM    build.bat        build only
REM    build.bat run    build, then launch the program
REM
REM  Output: build\RouteBank.exe
REM ===================================================================

set "ROOT=%~dp0"
cd /d "%ROOT%"

REM --- locate the MSVC toolchain ------------------------------------
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
set "VSPATH="
if exist "%VSWHERE%" for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSPATH=%%i"
if defined VSPATH call "%VSPATH%\Common7\Tools\VsDevCmd.bat" -arch=amd64 -no_logo >nul 2>&1
if not defined VSPATH call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1

where cl >nul 2>&1
if errorlevel 1 (
  echo ERROR: cl.exe was not found.
  echo Install "Desktop development with C++" from the Visual Studio Installer.
  exit /b 1
)

if not exist build mkdir build

set "SOURCES="
for /r "src" %%F in (*.cpp) do set "SOURCES=!SOURCES! "%%F""

echo Compiling Route Bank System...
cl /nologo /std:c++17 /EHsc /W3 /I"src" /I"src\model" /I"src\managers" /I"src\io" /I"src\ui" /Fo:build\ /Fe:build\RouteBank.exe !SOURCES!

if errorlevel 1 (
  echo.
  echo BUILD FAILED
  exit /b 1
)

echo.
echo Built build\RouteBank.exe

if /i "%~1"=="run" (
  echo Running from "%ROOT%" ...
  echo.
  build\RouteBank.exe
)

endlocal
