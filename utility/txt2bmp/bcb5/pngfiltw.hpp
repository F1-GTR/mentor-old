// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'pngfiltw.pas' rev: 5.00

#ifndef pngfiltwHPP
#define pngfiltwHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <iezlib.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Pngfiltw
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall WritePNGStream(Classes::TStream* Stream, Hyieutils::TIEBitmap* bitmap
	, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &xProgress, Hyieutils::TIEMask* AlphaChannel
	);

}	/* namespace Pngfiltw */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Pngfiltw;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// pngfiltw
