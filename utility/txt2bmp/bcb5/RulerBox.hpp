// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'rulerbox.pas' rev: 5.00

#ifndef rulerboxHPP
#define rulerboxHPP

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

namespace Rulerbox
{
//-- type declarations -------------------------------------------------------
typedef Windows::TPoint TPolyg[10];

#pragma option push -b-
enum TGripKind { gkTriangle, gkLeftTriangle, gkRightTriangle, gkArrow, gkArrow2 };
#pragma option pop

#pragma option push -b-
enum TGripsDir { gdUp, gdDown };
#pragma option pop

#pragma option push -b-
enum TRulerDir { rdHorizontal, rdVertical };
#pragma option pop

typedef void __fastcall (__closure *TRulerPosChangeEvent)(System::TObject* Sender, int Grip);

typedef void __fastcall (__closure *TRulerGripClickEvent)(System::TObject* Sender, int Grip);

typedef void __fastcall (__closure *TRulerGripDblClickEvent)(System::TObject* Sender, int Grip);

typedef void __fastcall (__closure *TRulerClickEvent)(System::TObject* Sender, double ps);

class DELPHICLASS TRulerBox;
class PASCALIMPLEMENTATION TRulerBox : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	Graphics::TBitmap* Bitmap;
	Graphics::TColor fBackground;
	Classes::TList* fGrips;
	int fGripBaseDim;
	int fSelGrip;
	int fSelGripSt;
	int fMX1;
	int fMY1;
	TGripsDir fGripsDir;
	bool fRuler;
	double fViewPos;
	double fDPU;
	double fFrequency;
	double fLabelFreq;
	Graphics::TColor fRulerColor;
	TRulerDir fRulerDir;
	double fViewMin;
	double fViewMax;
	TRulerPosChangeEvent fOnRulerPosChange;
	TRulerGripClickEvent fOnRulerGripClick;
	TRulerGripDblClickEvent fOnRulerGripDblClick;
	TRulerClickEvent fOnRulerClick;
	bool fFitInView;
	bool fHexLabels;
	void __fastcall SetBackground(Graphics::TColor bk);
	void __fastcall SetGripsCount(int v);
	int __fastcall GetGripsCount(void);
	void __fastcall SetGripsPos(int i, double p);
	double __fastcall GetGripsPos(int i);
	void __fastcall SetGripsCol(int i, int p);
	int __fastcall GetGripsCol(int i);
	void __fastcall SetGripBaseDim(int v);
	void __fastcall SetGripsKind(int i, TGripKind v);
	TGripKind __fastcall GetGripsKind(int i);
	void __fastcall SetGripsDir(TGripsDir v);
	void __fastcall SetRuler(bool v);
	void __fastcall SetViewPos(double v);
	void __fastcall SetDPU(double v);
	void __fastcall SetFrequency(double v);
	void __fastcall SetLabelFreq(double v);
	void __fastcall SetRulerColor(Graphics::TColor v);
	void __fastcall SetRulerDir(TRulerDir v);
	void __fastcall SetGripsMax(int i, double v);
	void __fastcall SetGripsMin(int i, double v);
	double __fastcall GetGripsMax(int i);
	double __fastcall GetGripsMin(int i);
	void __fastcall SetViewMin(double v);
	void __fastcall SetViewMax(double v);
	void __fastcall SetFitInView(bool v);
	double __fastcall GetWidthInUnit(void);
	void __fastcall SetHexLabels(bool v);
	
protected:
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TMessage &Message);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	int __fastcall GetClickedGrip(int x, int y);
	void __fastcall GetGripPoly(int gn, Windows::TPoint * poly);
	void __fastcall GetGripRect(int gn, Windows::TRect &rc);
	int __fastcall GetRulerHeight(void);
	void __fastcall RepaintGrips(void);
	void __fastcall RepaintRuler(void);
	int __fastcall GetXGripPos(int gn);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	void __fastcall AdjustGripLimits(int gn);
	void __fastcall AdjustViewLimits(void);
	
public:
	virtual void __fastcall Paint(void);
	__fastcall virtual TRulerBox(Classes::TComponent* Owner);
	__fastcall virtual ~TRulerBox(void);
	virtual void __fastcall Update(void);
	__property double GripsPos[int g] = {read=GetGripsPos, write=SetGripsPos/*, default*/};
	__property int GripsColor[int g] = {read=GetGripsCol, write=SetGripsCol};
	__property TGripKind GripsKind[int g] = {read=GetGripsKind, write=SetGripsKind};
	__property double GripsMin[int g] = {read=GetGripsMin, write=SetGripsMin};
	__property double GripsMax[int g] = {read=GetGripsMax, write=SetGripsMax};
	
__published:
	__property double ViewPos = {read=fViewPos, write=SetViewPos};
	__property Graphics::TColor Background = {read=fBackground, write=SetBackground, default=-2147483633
		};
	__property int GripBaseDim = {read=fGripBaseDim, write=SetGripBaseDim, default=12};
	__property TGripsDir GripsDir = {read=fGripsDir, write=SetGripsDir, default=0};
	__property bool Ruler = {read=fRuler, write=SetRuler, default=1};
	__property double DotPerUnit = {read=fDPU, write=SetDPU};
	__property double Frequency = {read=fFrequency, write=SetFrequency};
	__property double LabelFreq = {read=fLabelFreq, write=SetLabelFreq};
	__property Graphics::TColor RulerColor = {read=fRulerColor, write=SetRulerColor, default=-2147483633
		};
	__property TRulerDir RulerDir = {read=fRulerDir, write=SetRulerDir, default=0};
	__property double ViewMin = {read=fViewMin, write=SetViewMin};
	__property double ViewMax = {read=fViewMax, write=SetViewMax};
	__property TRulerPosChangeEvent OnRulerPosChange = {read=fOnRulerPosChange, write=fOnRulerPosChange
		};
	__property TRulerGripClickEvent OnRulerGripClick = {read=fOnRulerGripClick, write=fOnRulerGripClick
		};
	__property TRulerGripDblClickEvent OnRulerGripDblClick = {read=fOnRulerGripDblClick, write=fOnRulerGripDblClick
		};
	__property TRulerClickEvent OnRulerClick = {read=fOnRulerClick, write=fOnRulerClick};
	__property bool FitInView = {read=fFitInView, write=SetFitInView, default=0};
	__property int GripsCount = {read=GetGripsCount, write=SetGripsCount, default=1};
	__property bool HexLabels = {read=fHexLabels, write=SetHexLabels, default=0};
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
	__property Width ;
	__property Height ;
	__property Font ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TRulerBox(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MAXPOLYGLINES = 0xa;

}	/* namespace Rulerbox */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Rulerbox;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// rulerbox
