// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'iej2000.pas' rev: 5.00

#ifndef iej2000HPP
#define iej2000HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
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

namespace Iej2000
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE BOOL __turboFloat;
extern PACKAGE bool __fastcall J2KTryStreamJP2(Classes::TStream* Stream);
extern PACKAGE bool __fastcall J2KTryStreamJ2K(Classes::TStream* Stream);
extern PACKAGE void __fastcall J2KReadStream(Classes::TStream* Stream, Hyieutils::TIEBitmap* Bitmap, 
	Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &xProgress, bool Preview);
extern PACKAGE void __fastcall J2KWriteStream(Classes::TStream* Stream, Hyieutils::TIEBitmap* Bitmap
	, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &xProgress, int format);

}	/* namespace Iej2000 */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Iej2000;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// iej2000
