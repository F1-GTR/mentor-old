// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'giflzw.pas' rev: 5.00

#ifndef giflzwHPP
#define giflzwHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyiedefs.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Giflzw
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall GIFLZWDecompress(Classes::TStream* Stream, int Height, int Width, bool 
	Interlaced, char * FData);
extern PACKAGE void __fastcall GIFNONLZWCompress(Classes::TStream* Stream, int Height, int Width, bool 
	Interlaced, char * FData, int BitsPerPixel);
extern PACKAGE void __fastcall GIFLZWCompress(Classes::TStream* Stream, int Height, int Width, bool 
	Interlaced, char * FData, int BitsPerPixel);

}	/* namespace Giflzw */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Giflzw;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// giflzw
