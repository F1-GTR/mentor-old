// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'histogrambox.pas' rev: 5.00

#ifndef histogramboxHPP
#define histogramboxHPP

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

namespace Histogrambox
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum histogrambox__1 { hkRed, hkGreen, hkBlue, hkGray };
#pragma option pop

typedef Set<histogrambox__1, hkRed, hkGray>  THistogramKind;

#pragma option push -b-
enum histogrambox__2 { hlVertical, hlHorizontal };
#pragma option pop

typedef Set<histogrambox__2, hlVertical, hlHorizontal>  THistogramLabels;

#pragma option push -b-
enum THistogramStyle { hsBars, hsLines };
#pragma option pop

class DELPHICLASS THistogramBox;
class PASCALIMPLEMENTATION THistogramBox : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	Graphics::TBitmap* Bitmap;
	Graphics::TColor fBackground;
	Imageenproc::TImageEnProc* fAIEP;
	THistogramKind fHistKind;
	THistogramLabels fLabels;
	bool fCompBar;
	THistogramStyle fHistogramStyle;
	int fHistogramXPos;
	Graphics::TColor fGrayColor;
	void __fastcall SetBackground(Graphics::TColor bk);
	void __fastcall SetLabels(THistogramLabels v);
	void __fastcall SetCompBar(bool v);
	void __fastcall SetHistogramStyle(THistogramStyle v);
	void __fastcall SetHistogramKind(THistogramKind v);
	void __fastcall SetAIEP(Imageenproc::TImageEnProc* v);
	THistogramKind __fastcall GetHistogramKind(void);
	THistogramLabels __fastcall GetLabels(void);
	
protected:
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TMessage &Message);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	virtual void __fastcall Paint(void);
	__fastcall virtual THistogramBox(Classes::TComponent* Owner);
	__fastcall virtual ~THistogramBox(void);
	virtual void __fastcall Update(void);
	__property int HistogramXPos = {read=fHistogramXPos, nodefault};
	
__published:
	__property Imageenproc::TImageEnProc* AttachedImageEnProc = {read=fAIEP, write=SetAIEP};
	__property Graphics::TColor Background = {read=fBackground, write=SetBackground, default=16777215};
		
	__property THistogramKind HistogramKind = {read=GetHistogramKind, write=SetHistogramKind, default=8
		};
	__property THistogramLabels Labels = {read=GetLabels, write=SetLabels, default=3};
	__property bool CompBar = {read=fCompBar, write=SetCompBar, default=1};
	__property THistogramStyle HistogramStyle = {read=fHistogramStyle, write=SetHistogramStyle, default=0
		};
	__property Graphics::TColor GrayColor = {read=fGrayColor, write=fGrayColor, default=0};
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
	__property Font ;
	__property Width ;
	__property Height ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall THistogramBox(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Histogrambox */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Histogrambox;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// histogrambox
