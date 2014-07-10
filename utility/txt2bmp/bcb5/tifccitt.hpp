// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'tifccitt.pas' rev: 5.00

#ifndef tifccittHPP
#define tifccittHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyiedefs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Tifccitt
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int __fastcall _CCITTHuffmanGetLine(Windows::PByte dstbuf, Windows::PByte srcbuf, int 
	srcbufLen, int Width, int posb, int FillOrder);
extern PACKAGE int __fastcall CCITTHuffmanGetLine(Windows::PByte dstbuf, Windows::PByte srcbuf, int 
	srcbufLen, int Width, int FillOrder);
extern PACKAGE int __fastcall CCITT3_2D_GetLine(Windows::PByte dstbuf, Windows::PByte srcbuf, int srcbuflen
	, int Width, Windows::PByte predbuf, int posb, int FillOrder, bool AlignEOL);
extern PACKAGE void __fastcall CCITTHuffmanPutLine(Windows::PByte rdata, int wb, Classes::TStream* fs
	, bool &Aborting, int FillOrder);
extern PACKAGE void __fastcall CCITTHuffmanPutLineG3(Windows::PByte rdata, int wb, Classes::TStream* 
	fs, Byte &bwr, int &bwrl, bool &Aborting, int FillOrder);
extern PACKAGE void __fastcall _CCITTHuffmanPutLine(Windows::PByte rdata, int wb, Windows::PByte wbuf
	, int &wpos, int FillOrder);
extern PACKAGE void __fastcall CCITTHuffmanPutLineG32D(Windows::PByte rdata, int wb, Classes::TStream* 
	fs, Byte &bwr, int &bwrl, Windows::PByte &predline, bool &Aborting, int FillOrder);
extern PACKAGE void __fastcall CCITTHuffmanPutLineG4(Windows::PByte rdata, int wb, Classes::TStream* 
	fs, Byte &bwr, int &bwrl, Windows::PByte &predline, bool &Aborting, int FillOrder);

}	/* namespace Tifccitt */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Tifccitt;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// tifccitt
