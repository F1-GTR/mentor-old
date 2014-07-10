// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'bmpfilt.pas' rev: 5.00

#ifndef bmpfiltHPP
#define bmpfiltHPP

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

namespace Bmpfilt
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall BMPReadStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, int 
	BlockDim, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress, bool Preview, bool 
	MissingFileHead, Hyieutils::TIEMask* &AlphaChannel, bool IgnoreAlpha);
extern PACKAGE void __fastcall BMPWriteStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE bool __fastcall ICOTryStream(Classes::TStream* fs);
extern PACKAGE int __fastcall _EnumICOImStream(Classes::TStream* fs);
extern PACKAGE void __fastcall ICOReadStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, bool Preview, Hyiedefs::TProgressRec &Progress, Hyieutils::TIEMask* &AlphaChannel, bool 
	IgnoreAlpha);
extern PACKAGE void __fastcall ICOWriteStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress, const tagSIZE * sizes, const int sizes_Size, const int 
	* bitcounts, const int bitcounts_Size);
extern PACKAGE void __fastcall ICOWriteStream2(Classes::TStream* fs, System::TObject* const * ielist
	, const int ielist_Size, Hyiedefs::TProgressRec &Progress);
extern PACKAGE bool __fastcall CURTryStream(Classes::TStream* fs);
extern PACKAGE void __fastcall CURReadStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, bool Preview, Hyiedefs::TProgressRec &Progress, Hyieutils::TIEMask* &AlphaChannel, bool 
	IgnoreAlpha);
extern PACKAGE bool __fastcall TryPXM(Classes::TStream* fs);
extern PACKAGE void __fastcall PXMReadStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress, bool Preview);
extern PACKAGE void __fastcall PXMWriteStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall WBMPReadStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress, bool Preview);
extern PACKAGE void __fastcall WBMPWriteStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void * __fastcall IEPostScriptCreate(Classes::TStream* fs, Imageenio::TIOParamsVals* 
	&IOParams);
extern PACKAGE void __fastcall IEPostScriptClose(void * handle, Classes::TStream* fs);
extern PACKAGE void __fastcall IEPostScriptSave(void * handle, Classes::TStream* fs, Hyieutils::TIEBitmap* 
	Bitmap, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall IEPostScriptSaveOneStep(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap
	, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void * __fastcall IEPDFCreate(Imageenio::TIOParamsVals* &IOParams);
extern PACKAGE void __fastcall IEPDFSave(void * handle, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall IEPDFClose(void * handle, Classes::TStream* fs, Imageenio::TIOParamsVals* 
	&IOParams);
extern PACKAGE void __fastcall IEPDFSaveOneStep(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, 
	Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE bool __fastcall IEEMFTryStream(Classes::TStream* Stream);
extern PACKAGE bool __fastcall IEWMFTryStream(Classes::TStream* Stream);
extern PACKAGE void __fastcall IERealRAWReadStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap
	, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall IERealRAWWriteStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap
	, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress);

}	/* namespace Bmpfilt */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Bmpfilt;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// bmpfilt
