// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'imscan.pas' rev: 5.00

#ifndef imscanHPP
#define imscanHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <ietwain.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Imscan
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIETWCloseCallBack)(void);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall IETW_SelectImageSource(AnsiString &SelectedSourceName, Imageenio::PIETWainShared 
	TWainShared, HWND callwnd);
extern PACKAGE void __fastcall IETW_GetSourceList(Classes::TList* SList, Imageenio::PIETWainShared TWainShared
	, HWND callwnd);
extern PACKAGE bool __fastcall IETW_Acquire(Hyieutils::TIEBitmap* Bitmap, bool multi, Hyieutils::TIEMultiCallBack 
	MultiCallBack, Imageenio::TIETWainParams* Params, Imageenio::TIOParamsVals* IOParams, Hyiedefs::TProgressRec 
	&Progress, Imageenio::PIETWainShared TWainShared, HWND callwnd, bool DoNativePixelFormat);
extern PACKAGE bool __fastcall IETW_GetCapabilities(Imageenio::TIETWainParams* Params, Imageenio::TIETWSourceCaps 
	&Capabilities, bool setcap, Imageenio::PIETWainShared TWainShared, HWND callwnd);
extern PACKAGE AnsiString __fastcall IETW_GetDefaultSource(Imageenio::PIETWainShared TWainShared, HWND 
	callwnd);
extern PACKAGE void __fastcall IETW_FreeResources(Imageenio::PIETWainShared TWainShared, HWND callwnd
	);
extern PACKAGE void * __fastcall IETWAINAcquireOpen(TIETWCloseCallBack CloseCallBack, Hyieutils::TIEMultiCallBack 
	MultiCallBack, Imageenio::TIETWainParams* Params, Imageenio::PIETWainShared TWainShared, Imageenio::TIOParamsVals* 
	IOParams, Controls::TWinControl* parent, bool DoNativePixelFormat);
extern PACKAGE void __fastcall IETWAINAcquireClose(void * &grec);

}	/* namespace Imscan */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Imscan;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// imscan
