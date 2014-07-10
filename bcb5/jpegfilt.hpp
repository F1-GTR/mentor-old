// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'jpegfilt.pas' rev: 5.00

#ifndef jpegfiltHPP
#define jpegfiltHPP

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

namespace Jpegfilt
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE BOOL __turboFloat;
static const Byte M_SOF0 = 0xc0;
static const Byte M_SOF1 = 0xc1;
static const Byte M_SOF2 = 0xc2;
static const Byte M_SOF3 = 0xc3;
static const Byte M_SOF5 = 0xc5;
static const Byte M_SOF6 = 0xc6;
static const Byte M_SOF7 = 0xc7;
static const Byte M_JPG = 0xc8;
static const Byte M_SOF9 = 0xc9;
static const Byte M_SOF10 = 0xca;
static const Byte M_SOF11 = 0xcb;
static const Byte M_SOF13 = 0xcd;
static const Byte M_SOF14 = 0xce;
static const Byte M_SOF15 = 0xcf;
static const Byte M_DHT = 0xc4;
static const Byte M_DAC = 0xcc;
static const Byte M_RST0 = 0xd0;
static const Byte M_RST1 = 0xd1;
static const Byte M_RST2 = 0xd2;
static const Byte M_RST3 = 0xd3;
static const Byte M_RST4 = 0xd4;
static const Byte M_RST5 = 0xd5;
static const Byte M_RST6 = 0xd6;
static const Byte M_RST7 = 0xd7;
static const Byte M_SOI = 0xd8;
static const Byte M_EOI = 0xd9;
static const Byte M_SOS = 0xda;
static const Byte M_DQT = 0xdb;
static const Byte M_DNL = 0xdc;
static const Byte M_DRI = 0xdd;
static const Byte M_DHP = 0xde;
static const Byte M_EXP = 0xdf;
static const Byte M_APP0 = 0xe0;
static const Byte M_APP1 = 0xe1;
static const Byte M_APP2 = 0xe2;
static const Byte M_APP3 = 0xe3;
static const Byte M_APP4 = 0xe4;
static const Byte M_APP5 = 0xe5;
static const Byte M_APP6 = 0xe6;
static const Byte M_APP7 = 0xe7;
static const Byte M_APP8 = 0xe8;
static const Byte M_APP9 = 0xe9;
static const Byte M_APP10 = 0xea;
static const Byte M_APP11 = 0xeb;
static const Byte M_APP12 = 0xec;
static const Byte M_APP13 = 0xed;
static const Byte M_APP14 = 0xee;
static const Byte M_APP15 = 0xef;
static const Byte M_JPG0 = 0xf0;
static const Byte M_JPG1 = 0xf1;
static const Byte M_JPG2 = 0xf2;
static const Byte M_JPG3 = 0xf3;
static const Byte M_JPG4 = 0xf4;
static const Byte M_JPG5 = 0xf5;
static const Byte M_JPG6 = 0xf6;
static const Byte M_JPG7 = 0xf7;
static const Byte M_JPG8 = 0xf8;
static const Byte M_JPG9 = 0xf9;
static const Byte M_JPG10 = 0xfa;
static const Byte M_JPG11 = 0xfb;
static const Byte M_JPG12 = 0xfc;
static const Byte M_JPG13 = 0xfd;
static const Byte M_COM = 0xfe;
static const Shortint M_TEM = 0x1;
static const Shortint M_BYPASS = 0x0;
extern PACKAGE void __fastcall ReadJPegStream(Classes::TStream* Stream, Classes::TStream* TableStream
	, Hyieutils::TIEBitmap* Bitmap, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &xProgress
	, bool Preview, bool Raw, bool LoadIPTCEXIF, bool invertCMYK, bool freeICC);
extern PACKAGE void __fastcall WriteJPegStream(Classes::TStream* Stream, Hyieutils::TIEBitmap* bitmap
	, Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &xProgress);
extern PACKAGE __int64 __fastcall JpegTryStream(Classes::TStream* Stream);
extern PACKAGE bool __fastcall IEJpegInjectIPTC(Classes::TStream* InputStream, Classes::TStream* OutputStream
	, Hyieutils::TIEIPTCInfoList* iptc, Hyiedefs::TProgressRec &xProgress);
extern PACKAGE bool __fastcall IEJpegInjectEXIF(Classes::TStream* InputStream, Classes::TStream* OutputStream
	, Imageenio::TIOParamsVals* exif, Hyiedefs::TProgressRec &xProgress);
extern PACKAGE void __fastcall IEJpegLosslessTransform(Classes::TStream* InStream, Classes::TStream* 
	OutStream, Hyiedefs::TProgressRec &xProgress, int Transform, bool GrayScale, int CopyMarkers, const 
	Windows::TRect &CutRect);
extern PACKAGE int __fastcall IEGetJpegQuality(Classes::TStream* InputStream, void * &QTables);
extern PACKAGE int __fastcall IEGetJpegLength(Classes::TStream* InputStream);
extern PACKAGE void __fastcall IEJPEG_SetNextInput(void * cinfo, void * next_input_byte, int bytes_in_buffer
	);
extern PACKAGE void * __fastcall IEJPEG_CreateDecompStruct(void);
extern PACKAGE void __fastcall IEJPEG_FreeDecompStruct(void * cinfo);
extern PACKAGE void * __fastcall IEJPEG_CreateErrMgr(void * cinfo);
extern PACKAGE void __fastcall IEJPEG_FreeErrMgr(void * err);
extern PACKAGE void __fastcall IEJPEG_CreateDecompress(void * cinfo);
extern PACKAGE void __fastcall IEJPEG_DestroyDecompress(void * cinfo);
extern PACKAGE void __fastcall IEJPEG_SetReadStream(void * cinfo, Classes::TStream* stream);
extern PACKAGE void __fastcall IEJPEG_SetFillInputBuffer(void * cinfo, void * func);
extern PACKAGE void __fastcall IEJPEG_ReadHeader(void * cinfo, bool reqimage);
extern PACKAGE void __fastcall IEJPEG_StartDecompress(void * cinfo);
extern PACKAGE int __fastcall IEJPEG_GetOutputWidth(void * cinfo);
extern PACKAGE int __fastcall IEJPEG_GetOutputHeight(void * cinfo);
extern PACKAGE int __fastcall IEJPEG_GetOutputComponents(void * cinfo);
extern PACKAGE void * __fastcall IEJPEG_AllocSArray(void * cinfo, int pool_id, unsigned samplesperrow
	, unsigned numrows);
extern PACKAGE int __fastcall IEJPEG_GetOutputScanline(void * cinfo);
extern PACKAGE unsigned __fastcall IEJPEG_ReadScanlines(void * cinfo, void * scanlines, unsigned max_lines
	);
extern PACKAGE void __fastcall IEJPEG_FinishDecompress(void * cinfo);
extern PACKAGE void __fastcall IEGetJpegICC(Classes::TStream* InputStream, Imageenio::TIOParamsVals* 
	Params);

}	/* namespace Jpegfilt */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Jpegfilt;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// jpegfilt
