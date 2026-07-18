@echo off


if not exist make.bat (
    echo all.bat must be run from Compilor\src 1>&2
    exit /b 1
)
call .\make.bat --no-banner || exit /b 1
call .\run.bat --no-rebuild || exit /b 1

