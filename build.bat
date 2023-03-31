@echo off
cmake -S . -B build
cd build

set CONFIG=debug
if not "%1" == "" (
  REM If argument is "debug", set build configuration to debug
  if /i "%1" == "release" set CONFIG=release
)
msbuild pool.sln -m /p:configuration=%CONFIG%

cd ..

