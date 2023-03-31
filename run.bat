@echo off
set CONFIG=Debug

if not "%1" == "" (
  REM If argument is "debug", set build configuration to debug
  if /i "%1" == "release" set CONFIG=Release
)
@echo on
.\build\%CONFIG%\pool.exe
@echo off
echo error level %errorlevel%
