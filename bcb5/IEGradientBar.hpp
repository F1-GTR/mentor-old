// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'iegradientbar.pas' rev: 5.00

#ifndef iegradientbarHPP
#define iegradientbarHPP

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

namespace Iegradientbar
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIEGradientDir { gdHorizontal, gdVertical };
#pragma option pop

#pragma option push -b-
enum TIEMouseInteractItemsGr { migDragGrip };
#pragma option pop

typedef Set<TIEMouseInteractItemsGr, migDragGrip, migDragGrip>  TIEMouseInteractGr;

class DELPHICLASS TIEGradientBar;
class PASCALIMPLEMENTATION TIEGradientBar : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	int fColorIndex;
	Graphics::TColor fBeginColor;
	Graphics::TColor fEndColor;
	Graphics::TColor fGradient[256];
	TIEGradientDir fDirection;
	Classes::TNotifyEvent fOnChange;
	TIEMouseInteractGr fMouseInteract;
	void __fastcall SetColorIndex(int v);
	void __fastcall SetBeginColor(Graphics::TColor v);
	void __fastcall SetEndColor(Graphics::TColor v);
	Graphics::TColor __fastcall GetColor(void);
	Hyiedefs::TRGB __fastcall GetRGB(void);
	void __fastcall SetDirection(TIEGradientDir v);
	void __fastcall SetMouseInteractGr(TIEMouseInteractGr v);
	TIEMouseInteractGr __fastcall GetMouseInteractGr(void);
	
protected:
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TMessage &Message);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	void __fastcall CalcGradient(void);
	void __fastcall DrawGrip(void);
	
public:
	virtual void __fastcall Paint(void);
	__fastcall virtual TIEGradientBar(Classes::TComponent* Owner);
	__fastcall virtual ~TIEGradientBar(void);
	__property int ColorIndex = {read=fColorIndex, write=SetColorIndex, nodefault};
	__property Graphics::TColor Color = {read=GetColor, nodefault};
	__property Hyiedefs::TRGB RGB = {read=GetRGB};
	
__published:
	__property Graphics::TColor BeginColor = {read=fBeginColor, write=SetBeginColor, default=0};
	__property Graphics::TColor EndColor = {read=fEndColor, write=SetEndColor, default=16777215};
	__property TIEGradientDir Direction = {read=fDirection, write=SetDirection, default=1};
	__property Classes::TNotifyEvent OnChange = {read=fOnChange, write=fOnChange};
	__property TIEMouseInteractGr MouseInteract = {read=GetMouseInteractGr, write=SetMouseInteractGr, default=1
		};
	__property Width ;
	__property Height ;
	__property Align ;
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
	/* TWinControl.CreateParented */ inline __fastcall TIEGradientBar(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iegradientbar */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Iegradientbar;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// iegradientbar
