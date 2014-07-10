// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'pcxfilter.pas' rev: 5.00

#ifndef pcxfilterHPP
#define pcxfilterHPP

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

namespace Pcxfilter
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct TPcxHeader
{
	Byte Manufacturer;
	Byte Version;
	Byte Encoding;
	Byte Bits_Per_Pixel;
	Word Xmin;
	Word Ymin;
	Word Xmax;
	Word Ymax;
	Word Hres;
	Word Vres;
	Hyiedefs::TRGB Palette[16];
	Byte Reserved;
	Byte Colour_Planes;
	Word Bytes_Per_Line;
	Word Palette_Type;
	Byte Filler[58];
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ReadPcx(AnsiString nf, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall ReadPcxStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, int fsDim, Hyiedefs::TProgressRec &Progress, bool Preview);
extern PACKAGE void __fastcall WritePcx(AnsiString nf, Hyieutils::TIEBitmap* bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall WritePcxStream(Classes::TStream* fs, Hyieutils::TIEBitmap* bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE bool __fastcall IEDCXTryStream(Classes::TStream* fs);
extern PACKAGE int __fastcall IEDCXCountStream(Classes::TStream* fs);
extern PACKAGE void __fastcall IEDCXReadStream(Classes::TStream* fs, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress, bool Preview);
extern PACKAGE void __fastcall IEDCXInsertStream(Classes::TStream* fs, Hyieutils::TIEBitmap* bitmap, 
	Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall IEDCXDeleteStream(Classes::TStream* fs, int idx);

}	/* namespace Pcxfilter */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Pcxfilter;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// pcxfilter
