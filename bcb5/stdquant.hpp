// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'stdquant.pas' rev: 5.00

#ifndef stdquantHPP
#define stdquantHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyiedefs.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <imageen.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stdquant
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void * __fastcall CreateMedianCutQuantizer(System::TObject* SrcBitmap, Hyiedefs::TRGB 
	* ColorMap, const int ColorMap_Size, int NCol);
extern PACKAGE void __fastcall FreeMedianCutQuantizer(void * mq);
extern PACKAGE int __fastcall MedianCutFindIndex(void * mq, const Hyiedefs::TRGB rgb);

}	/* namespace Stdquant */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Stdquant;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// stdquant
