// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ieraw.pas' rev: 5.00

#ifndef ierawHPP
#define ierawHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ieview.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <jpegfilt.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ieraw
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall IEReadCameraRAWStream(Classes::TStream* InputStream, Hyieutils::TIEBitmap* 
	Bitmap, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress, bool Preview);
extern PACKAGE bool __fastcall IERAWTryStream(Classes::TStream* Stream);
extern PACKAGE bool __fastcall IECRWGetCIFFAsExif(Classes::TStream* Stream, Imageenio::TIOParamsVals* 
	&IOParams);
extern PACKAGE bool __fastcall IECRWGetJpeg(Hyieutils::TIEBitmap* Bitmap, Classes::TStream* Stream);
	

}	/* namespace Ieraw */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ieraw;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ieraw
