// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'iepresetim.pas' rev: 5.00

#ifndef iepresetimHPP
#define iepresetimHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <imageenio.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iepresetim
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIEPresetImage;
class PASCALIMPLEMENTATION TIEPresetImage : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	void *Data;
	int FileFormat;
	Windows::TRect ThumbRect;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIEPresetImage(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIEPresetImage(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Classes::TList* iegPresetImages;
static const Word iePRESETTHUMB1Size = 0x24a0;
extern PACKAGE Byte iePRESETTHUMB1[9376];
static const Word iePRESETTHUMB2Size = 0x41f;
extern PACKAGE Byte iePRESETTHUMB2[1055];
static const Word iePRESETTHUMB3Size = 0x4e4;
extern PACKAGE Byte iePRESETTHUMB3[1252];
static const Word iePRESETTHUMB4Size = 0xd01;
extern PACKAGE Byte iePRESETTHUMB4[3329];

}	/* namespace Iepresetim */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Iepresetim;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// iepresetim
