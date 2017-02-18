# Microsoft Developer Studio Project File - Name="ImageToWords" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ImageToWords - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ImageToWords.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ImageToWords.mak" CFG="ImageToWords - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ImageToWords - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ImageToWords - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ImageToWords - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release1"
# PROP Intermediate_Dir "Release1"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "ImageToWords - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "ImageToWords - Win32 Release"
# Name "ImageToWords - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BalanceInput.cpp
# End Source File
# Begin Source File

SOURCE=.\BlurInput.cpp
# End Source File
# Begin Source File

SOURCE=.\CharacterSetInput.cpp
# End Source File
# Begin Source File

SOURCE=.\ChuzaInput.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogCommon.cpp
# End Source File
# Begin Source File

SOURCE=.\DiffuseInput.cpp
# End Source File
# Begin Source File

SOURCE=.\EdgeInput.cpp
# End Source File
# Begin Source File

SOURCE=.\FontComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\GrayenInput.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageToWords.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageToWords.idl
# ADD MTL /h "ImageToWords_i.h" /iid "ImageToWords_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\ImageToWords.rc
# End Source File
# Begin Source File

SOURCE=.\ImageToWordsDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageToWordsView.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MaximumInput.cpp
# End Source File
# Begin Source File

SOURCE=.\MinimumInput.cpp
# End Source File
# Begin Source File

SOURCE=.\MotionBlurInput.cpp
# End Source File
# Begin Source File

SOURCE=.\PerspectiveInput.cpp
# End Source File
# Begin Source File

SOURCE=.\RotateInput.cpp
# End Source File
# Begin Source File

SOURCE=.\RuihuaInput.cpp
# End Source File
# Begin Source File

SOURCE=.\ScaleInput.cpp
# End Source File
# Begin Source File

SOURCE=.\SejieInput.cpp
# End Source File
# Begin Source File

SOURCE=.\StablelizeInput.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Texture1Input.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolProperties.cpp
# End Source File
# Begin Source File

SOURCE=.\TrimInput.cpp
# End Source File
# Begin Source File

SOURCE=.\WizFontsEnumerator.cpp
# End Source File
# Begin Source File

SOURCE=.\WordsTransformInput.cpp
# End Source File
# Begin Source File

SOURCE=.\WtEditOutput.cpp
# End Source File
# Begin Source File

SOURCE=.\YuzhiInput.cpp
# End Source File
# Begin Source File

SOURCE=.\ZhongZhiLvBo.cpp
# End Source File
# Begin Source File

SOURCE=.\Zidingyilvjing.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\atlimage.h
# End Source File
# Begin Source File

SOURCE=.\BalanceInput.h
# End Source File
# Begin Source File

SOURCE=.\BlurInput.h
# End Source File
# Begin Source File

SOURCE=.\CharacterSetInput.h
# End Source File
# Begin Source File

SOURCE=.\ChuzaInput.h
# End Source File
# Begin Source File

SOURCE=.\DialogCommon.h
# End Source File
# Begin Source File

SOURCE=.\DiffuseInput.h
# End Source File
# Begin Source File

SOURCE=.\EdgeInput.h
# End Source File
# Begin Source File

SOURCE=.\FontComboBox.h
# End Source File
# Begin Source File

SOURCE=.\GrayenInput.h
# End Source File
# Begin Source File

SOURCE=.\ImageToWords.h
# End Source File
# Begin Source File

SOURCE=.\ImageToWordsDoc.h
# End Source File
# Begin Source File

SOURCE=.\ImageToWordsView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MaximumInput.h
# End Source File
# Begin Source File

SOURCE=.\MinimumInput.h
# End Source File
# Begin Source File

SOURCE=.\MotionBlurInput.h
# End Source File
# Begin Source File

SOURCE=.\PerspectiveInput.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RotateInput.h
# End Source File
# Begin Source File

SOURCE=.\RuihuaInput.h
# End Source File
# Begin Source File

SOURCE=.\ScaleInput.h
# End Source File
# Begin Source File

SOURCE=.\SejieInput.h
# End Source File
# Begin Source File

SOURCE=.\StablelizeInput.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Texture1Input.h
# End Source File
# Begin Source File

SOURCE=.\ToolProperties.h
# End Source File
# Begin Source File

SOURCE=.\TrimInput.h
# End Source File
# Begin Source File

SOURCE=.\WizFontsEnumerator.h
# End Source File
# Begin Source File

SOURCE=.\WordsTransformInput.h
# End Source File
# Begin Source File

SOURCE=.\WtEditOutput.h
# End Source File
# Begin Source File

SOURCE=.\YuzhiInput.h
# End Source File
# Begin Source File

SOURCE=.\ZhongZhiLvBo.h
# End Source File
# Begin Source File

SOURCE=.\Zidingyilvjing.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hk2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hk3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ImageToWords.ico
# End Source File
# Begin Source File

SOURCE=.\res\ImageToWords.rc2
# End Source File
# Begin Source File

SOURCE=.\ImageToWords.rgs
# End Source File
# Begin Source File

SOURCE=.\res\ImageToWordsDoc.ico
# End Source File
# Begin Source File

SOURCE=.\jianbian1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\xp.manifest
# End Source File
# End Target
# End Project
# Section ImageToWords : {00000000-0000-0000-0000-000000000000}
# 	1:16:IDR_IMAGETOWORDS:102
# End Section
