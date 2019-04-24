@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by MEMBRANEPRINTER.HPJ. >"hlp\MembranePrinter.hm"
echo. >>"hlp\MembranePrinter.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\MembranePrinter.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\MembranePrinter.hm"
echo. >>"hlp\MembranePrinter.hm"
echo // Prompts (IDP_*) >>"hlp\MembranePrinter.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\MembranePrinter.hm"
echo. >>"hlp\MembranePrinter.hm"
echo // Resources (IDR_*) >>"hlp\MembranePrinter.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\MembranePrinter.hm"
echo. >>"hlp\MembranePrinter.hm"
echo // Dialogs (IDD_*) >>"hlp\MembranePrinter.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\MembranePrinter.hm"
echo. >>"hlp\MembranePrinter.hm"
echo // Frame Controls (IDW_*) >>"hlp\MembranePrinter.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\MembranePrinter.hm"
REM -- Make help for Project MEMBRANEPRINTER


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\MembranePrinter.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\MembranePrinter.hlp" goto :Error
if not exist "hlp\MembranePrinter.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\MembranePrinter.hlp" Debug
if exist Debug\nul copy "hlp\MembranePrinter.cnt" Debug
if exist Release\nul copy "hlp\MembranePrinter.hlp" Release
if exist Release\nul copy "hlp\MembranePrinter.cnt" Release
echo.
goto :done

:Error
echo hlp\MembranePrinter.hpj(1) : error: Problem encountered creating help file

:done
echo.
