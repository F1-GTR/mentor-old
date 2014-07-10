// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ietgafil.pas' rev: 5.00

#ifndef ietgafilHPP
#define ietgafilHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ietgafil
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall TryTGA(Classes::TStream* Stream);
extern PACKAGE void __fastcall ReadTGAStream(Classes::TStream* Stream, Hyieutils::TIEBitmap* Bitmap, 
	Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress, bool Preview, Hyieutils::TIEMask* 
	&AlphaChannel, bool IgnoreAlpha);
extern PACKAGE void __fastcall WriteTGAStream(Classes::TStream* Stream, Hyieutils::TIEBitmap* Bitmap
	, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress, Hyieutils::TIEMask* AlphaChannel
	);

}	/* namespace Ietgafil */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ietgafil;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ietgafil
