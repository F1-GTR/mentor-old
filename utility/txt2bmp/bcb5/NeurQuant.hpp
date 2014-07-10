// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'neurquant.pas' rev: 5.00

#ifndef neurquantHPP
#define neurquantHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyieutils.hpp>	// Pascal unit
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

namespace Neurquant
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIEQuantizer;
class PASCALIMPLEMENTATION TIEQuantizer : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int fMethod;
	void *fQT;
	bool fGrayScale;
	Hyiedefs::TRGB *fSQ;
	int fNCol;
	Hyieutils::TIEBitmap* fSrcBmp;
	int __fastcall GetRGBIndex(const Hyiedefs::TRGB cl);
	
public:
	__fastcall TIEQuantizer(Hyieutils::TIEBitmap* SrcBitmap, Hyiedefs::TRGB * ColorMap, const int ColorMap_Size
		, int NCol, int Quality, int qmethod);
	__fastcall virtual ~TIEQuantizer(void);
	__property int RGBIndex[Hyiedefs::TRGB cl] = {read=GetRGBIndex};
	__property bool GrayScale = {read=fGrayScale, nodefault};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Neurquant */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Neurquant;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// neurquant
