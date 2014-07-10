// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ieXtraTransitions.pas' rev: 5.00

#ifndef ieXtraTransitionsHPP
#define ieXtraTransitionsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iextratransitions
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (*TEffectProc)(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);

struct TEffect
{
	AnsiString Name;
	TEffectProc Proc;
} ;

typedef TEffect ieXtraTransitions__1[163];

//-- var, const, procedure ---------------------------------------------------
static const Byte MAX_TRANSITIONS = 0xa3;
extern PACKAGE TEffect IETransitionList[163];
extern PACKAGE void __fastcall MirrorCopyRect(Graphics::TCanvas* Canvas, const Windows::TRect &dstRect
	, Graphics::TBitmap* Bitmap, const Windows::TRect &srcRect, bool Horz, bool Vert);
extern PACKAGE void __fastcall RotatePoints(Windows::TPoint * Points, const int Points_Size, int xOrg
	, int yOrg, Extended Angle);
extern PACKAGE void __fastcall Effect001(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect002(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect003(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect004(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect007(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect008(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect009(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect010(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect011(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect012(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect013(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect014(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect015(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect016(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect017(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect018(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect019(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect020(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect021(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect024(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect025(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect026(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect027(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect028(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect029(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect030(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect031(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect032(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect033(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect034(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect035(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect036(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect037(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect038(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect043(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect044(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect045(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect046(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect047(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect048(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect049(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect050(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect051(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect055(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect056(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect057(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect058(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect059(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect060(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect061(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect062(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect063(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect064(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect065(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect066(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect067(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect068(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect069(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect070(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect071(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect072(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect073(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect074(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect075(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect076(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect077(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect078(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect079(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect080(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect081(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect082(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect083(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect084(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect085(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect086(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect087(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect088(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect089(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect090(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect091(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect092(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect093(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect094(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect095(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect096(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect097(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect098(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect099(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect100(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect101(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect102(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect103(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect104(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect105(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect106(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect107(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect108(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect109(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect110(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect111(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect112(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect113(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect114(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect115(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect116(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect117(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect123(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect124(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect125(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect126(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect128(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect129(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect130(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect131(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect132(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect133(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect134(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect135(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect136(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect137(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect138(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect139(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect140(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect141(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect142(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect143(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect144(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect145(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect146(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect147(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect148(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect149(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);
extern PACKAGE void __fastcall Effect150(Graphics::TCanvas* DestCanvas, Graphics::TBitmap* Screen, Graphics::TBitmap* 
	Image, const Windows::TRect &Rect, int Step, int Progress);

}	/* namespace Iextratransitions */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Iextratransitions;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ieXtraTransitions
