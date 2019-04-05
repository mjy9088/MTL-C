!include "MUI2.nsh"
!include "x64.nsh"

Unicode true

Name "test"
OutFile "output\test.exe"
Caption "test"
LicenseData "../LICENSE.txt"
InstallDir "$PROGRAMFILES\MTL\test"

ShowInstDetails show
AutoCloseWindow false
SilentInstall normal
CRCCheck on
SetCompressor /SOLID /FINAL lzma
SetDatablockOptimize on
SetOverwrite try
XPStyle on

!include "welcome.nsdinc"

RequestExecutionLevel admin

Page custom Fnc_welcome_Show

Section ""
SectionEnd
