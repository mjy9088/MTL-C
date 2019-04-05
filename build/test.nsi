!include "MUI2.nsh"
!include "x64.nsh"

Unicode true

Name "test"
OutFile "output\test.exe"
Caption "test"
LicenseData "../LICENSE.txt"
InstallDir "$PROGRAMFILES\MTL\test"

!include "welcome.nsdinc"
!include "license.nsdinc"

RequestExecutionLevel admin

Page custom Fnc_welcome_Show
Page custom Fnc_license_Show
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

Section ""
SectionEnd
