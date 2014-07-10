// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'giffilter.pas' rev: 5.00

#ifndef giffilterHPP
#define giffilterHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <imageen.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Giffilter
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct TGIFHeader
{
	char id[6];
	Word WinWidth;
	Word WinHeight;
	Byte Flags;
	Byte Background;
	Byte Ratio;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall _GIFMakeAnimate(const AnsiString nf, Word iters, int windx, int windy
	);
extern PACKAGE int __fastcall _DeleteGIFIm(AnsiString nf, int idx, bool wr);
extern PACKAGE bool __fastcall _CheckGIFAnimate(const AnsiString nf);
extern PACKAGE void __fastcall ReadGIF(AnsiString nf, Hyieutils::TIEBitmap* OutBitmap, int &numi, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress, Hyieutils::TIEMask* &AlphaChannel, bool IgnoreAlpha);
extern PACKAGE void __fastcall ReadGIFStream(Classes::TStream* fs, Hyieutils::TIEBitmap* OutBitmap, 
	int &numi, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress, bool Preview, Hyieutils::TIEMask* 
	&AlphaChannel, bool IgnoreAlpha);
extern PACKAGE void __fastcall WriteGIF(AnsiString nf, Hyieutils::TIEBitmap* bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall WriteGIFStream(Classes::TStream* fs, Hyieutils::TIEBitmap* bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE int __fastcall _InsertGIFIm(AnsiString nf, Hyieutils::TIEBitmap* bitmap, Imageenio::TIOParamsVals* 
	&IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE int __fastcall _InsertGIFImStream(Classes::TStream* fs, Hyieutils::TIEBitmap* bitmap, 
	Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress);

}	/* namespace Giffilter */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Giffilter;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// giffilter
