// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'tiffilt.pas' rev: 5.00

#ifndef tiffiltHPP
#define tiffiltHPP

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

namespace Tiffilt
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int __fastcall TIFFFindTAG(Word IdTag, Hyieutils::TTIFFEnv &TIFFEnv);
extern PACKAGE int __fastcall TIFFGetDataLength(Hyieutils::TTIFFEnv &TIFFEnv, int nTag);
extern PACKAGE int __fastcall TIFFReadSingleValDef(Hyieutils::TTIFFEnv &TIFFEnv, int ntag, int def);
	
extern PACKAGE double __fastcall TIFFReadSingleRational(Hyieutils::TTIFFEnv &TIFFEnv, int nTag);
extern PACKAGE double __fastcall TIFFReadRationalIndex(Hyieutils::TTIFFEnv &TIFFEnv, int nTag, int idx
	);
extern PACKAGE int __fastcall TIFFReadIndexValN(Hyieutils::TTIFFEnv &TIFFEnv, int nTag, int idx);
extern PACKAGE int __fastcall TIFFReadArrayIntegers(Hyieutils::TTIFFEnv &TIFFEnv, Hyiedefs::pIntegerArray 
	&ar, int NTag);
extern PACKAGE void * __fastcall TIFFReadRawData(Hyieutils::TTIFFEnv &TIFFEnv, int NTag, int &Size);
	
extern PACKAGE AnsiString __fastcall TIFFReadString(Hyieutils::TTIFFEnv &TIFFEnv, int NTag);
extern PACKAGE AnsiString __fastcall TIFFReadMiniString(Hyieutils::TTIFFEnv &TIFFEnv, int NTag);
extern PACKAGE bool __fastcall TIFFReadIFD(int imageindex, int Offset, Hyieutils::TTIFFEnv &TIFFEnv, 
	int &numi);
extern PACKAGE void __fastcall TIFFReadStream(Hyieutils::TIEBitmap* Bitmap, Classes::TStream* Stream
	, int &numi, Imageenio::TIOParamsVals* IOParams, Hyiedefs::TProgressRec &Progress, bool Preview, Hyieutils::TIEMask* 
	&AlphaChannel, bool TranslateBase, bool IgnoreAlpha, bool IsExifThumb);
extern PACKAGE int __fastcall _EnumTIFFImStream(Classes::TStream* Stream);
extern PACKAGE int __fastcall TIFFWriteStream(Classes::TStream* Stream, bool Ins, Hyieutils::TIEBitmap* 
	Bitmap, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress);
extern PACKAGE int __fastcall _DeleteTIFFImStream(Classes::TStream* Stream, int idx);
extern PACKAGE int __fastcall _DeleteTIFFImStreamGroup(Classes::TStream* Stream, Hyiedefs::pIntegerArray 
	idxlist, int idxcount);
extern PACKAGE bool __fastcall TIFFLoadTags(Classes::TStream* Stream, int &numi, int ImageIndex, Hyieutils::TTIFFEnv 
	&TIFFEnv);
extern PACKAGE void __fastcall TIFFFreeTags(Hyieutils::TTIFFEnv &TIFFEnv);
extern PACKAGE void __fastcall _ExtractTIFFImStream(Classes::TStream* Stream, int idx, Classes::TStream* 
	OutStream);
extern PACKAGE void __fastcall _InsertTIFFImStream(Classes::TStream* Stream, Classes::TStream* ToInsert
	, int idx, Classes::TStream* OutStream);
extern PACKAGE bool __fastcall IsDNGStream(Classes::TStream* fs);
extern PACKAGE bool __fastcall IsTIFFStream(Classes::TStream* fs);

}	/* namespace Tiffilt */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Tiffilt;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// tiffilt
