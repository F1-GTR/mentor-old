// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'tiflzw.pas' rev: 5.00

#ifndef tiflzwHPP
#define tiflzwHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyieutils.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Tiflzw
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Windows::PByte __fastcall TIFFLZWDecompress(Windows::PByte CompBuf, int LineSize, int 
	&Id);
extern PACKAGE void __fastcall TIFFLZWCompress(Windows::PByte indata, int inputlen, Classes::TStream* 
	outstream, int &id);

}	/* namespace Tiflzw */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Tiflzw;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// tiflzw
