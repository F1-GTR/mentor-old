// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'hsvbox.pas' rev: 5.00

#ifndef hsvboxHPP
#define hsvboxHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Hsvbox
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THSVBox;
class PASCALIMPLEMENTATION THSVBox : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	int fHue;
	int fSat;
	int fVal;
	Byte fRed;
	Byte fGreen;
	Byte fBlue;
	Graphics::TBitmap* bitmap;
	Graphics::TColor fBackground;
	Classes::TNotifyEvent fOnChange;
	int fMouseSel;
	Graphics::TColor fColor;
	int fHueBarWidth;
	int fBarsDistance;
	
protected:
	void __fastcall SetHue(int h);
	void __fastcall SetSat(int s);
	void __fastcall SetVal(int v);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TMessage &Message);
	void __fastcall SetBackground(Graphics::TColor bk);
	void __fastcall DrawValSat(void);
	void __fastcall DrawHue(void);
	void __fastcall DrawGrips(void);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	void __fastcall XMouseMove(int X, int Y);
	void __fastcall SetHueBarWidth(int v);
	void __fastcall SetBarsDistance(int v);
	
public:
	virtual void __fastcall Paint(void);
	__fastcall virtual THSVBox(Classes::TComponent* Owner);
	__fastcall virtual ~THSVBox(void);
	void __fastcall SetRGB(Byte r, Byte g, Byte b);
	HIDESBASE void __fastcall SetColor(Graphics::TColor cl);
	Graphics::TColor __fastcall GetColorAt(int x, int y);
	
__published:
	__property int Hue = {read=fHue, write=SetHue, default=0};
	__property int Sat = {read=fSat, write=SetSat, default=0};
	__property int Val = {read=fVal, write=SetVal, default=0};
	__property Byte Red = {read=fRed, nodefault};
	__property Byte Green = {read=fGreen, nodefault};
	__property Byte Blue = {read=fBlue, nodefault};
	__property Graphics::TColor Color = {read=fColor, nodefault};
	__property Graphics::TColor Background = {read=fBackground, write=SetBackground, default=-2147483633
		};
	__property Classes::TNotifyEvent OnChange = {read=fOnChange, write=fOnChange};
	__property int HueBarWidth = {read=fHueBarWidth, write=SetHueBarWidth, default=20};
	__property int BarsDistance = {read=fBarsDistance, write=SetBarsDistance, default=5};
	__property Align ;
	__property Anchors ;
	__property DragCursor ;
	__property DragMode ;
	__property Enabled ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property Visible ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall THSVBox(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Hsvbox */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Hsvbox;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// hsvbox
