// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ietextc.pas' rev: 5.00

#ifndef ietextcHPP
#define ietextcHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyiedefs.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <imageenview.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ietextc
{
//-- type declarations -------------------------------------------------------
struct TIECharInfo
{
	int refcount;
	System::SmallString<255>  name;
	int height;
	Graphics::TFontStyles style;
	Graphics::TColor color;
	Graphics::TColor brushColor;
	Graphics::TBrushStyle brushStyle;
	Imageenview::TIEAlignment align;
} ;

typedef TIECharInfo *PIECharInfo;

class DELPHICLASS TIETextControl;
class PASCALIMPLEMENTATION TIETextControl : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
protected:
	char *fText;
	int fTextLength;
	int fInsertPos;
	Graphics::TBitmap* fBackbuf;
	int fCaretX;
	int fCaretY;
	int fCaretH;
	Graphics::TFont* fDefaultFont;
	Graphics::TBrush* fDefaultFontBrush;
	Graphics::TPen* fBorderPen;
	Graphics::TBrush* fBrush;
	bool fInsMode;
	Imageenview::TIEAlignment fDefaultAlign;
	double fZoom;
	int fSelStart;
	int fSelStop;
	int fMouseDownX;
	int fMouseDownY;
	TIECharInfo *fInsertingCharInfo;
	bool fForceDefaultColors;
	bool fFontLocked;
	bool fAutoSize;
	int fLineSpace;
	int fFixedHeight;
	Byte *fcache_h;
	Byte *fcache_w;
	Byte *fcache_InternalLeading;
	int *fposxarray;
	int *fposyarray;
	Classes::TList* fCharInfo;
	int *fCharRef;
	bool fWriteFormattedString;
	AnsiString fFormattedString;
	Classes::TNotifyEvent fOnCursorMoved;
	Graphics::TBitmap* fUnderBuffer;
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	MESSAGE void __fastcall CMWantSpecialKey(Messages::TWMKey &Msg);
	MESSAGE void __fastcall WMCut(Messages::TMessage &Message);
	MESSAGE void __fastcall WMCopy(Messages::TMessage &Message);
	MESSAGE void __fastcall WMPaste(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Msg);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Msg);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	HIDESBASE MESSAGE void __fastcall CNChar(Messages::TWMKey &Message);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	void __fastcall GoBack(char * &CurPos);
	bool __fastcall GoBackIdx(int &CurPos);
	void __fastcall GoForwardIdx(int &CurPos);
	void __fastcall SaveCharInfo(int idx, PIECharInfo charinf);
	int __fastcall FindCharInfo(PIECharInfo info);
	void __fastcall RestoreCharInfo(int idx, Graphics::TCanvas* XCanvas);
	void __fastcall CopyCharInfoTo(int source, PIECharInfo charinf);
	int __fastcall DelChar(int idx);
	void __fastcall IncFontSize(void);
	void __fastcall DecFontSize(void);
	void __fastcall MoveUp(void);
	void __fastcall MoveDown(void);
	void __fastcall MoveHome(void);
	void __fastcall MoveEnd(void);
	void __fastcall MoveTo(int x, int y);
	void __fastcall ClearBitmap(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	void __fastcall ResetSelection(void);
	void __fastcall SStop(int PrevPos, Classes::TShiftState Shift);
	void __fastcall RemoveSelected(void);
	void __fastcall CopyToClipboard(void);
	void __fastcall PasteFromClipboard(void);
	void __fastcall ResetCache(int from, int len);
	void __fastcall SwitchFontStyle(Graphics::TFontStyle sty);
	void __fastcall GoWordBackIdx(int &CurPos);
	void __fastcall GoWordForwardIdx(int &CurPos);
	void __fastcall SetFontLocked(bool value);
	void __fastcall DoCursorMoved(void);
	
public:
	__fastcall virtual TIETextControl(Classes::TComponent* Owner);
	__fastcall virtual ~TIETextControl(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Update(void);
	__property char * Text = {read=fText, write=fText};
	__property Hyiedefs::pIntegerArray TextFormatRef = {read=fCharRef, write=fCharRef};
	__property Classes::TList* TextFormat = {read=fCharInfo, write=fCharInfo};
	DYNAMIC void __fastcall KeyPress(char &Key);
	HIDESBASE void __fastcall PaintTo(Graphics::TCanvas* DestCanvas, int DestX, int DestY, int NonZoomDestWidth
		, int NonZoomDestHeight);
	void __fastcall AddChar(char key);
	void __fastcall InsertAlign(Imageenview::TIEAlignment Align);
	void __fastcall Init(void);
	void __fastcall RemoveUnreferenced(void);
	__property Graphics::TFont* DefaultFont = {read=fDefaultFont};
	__property Graphics::TBrush* DefaultFontBrush = {read=fDefaultFontBrush};
	__property Imageenview::TIEAlignment DefaultAlign = {read=fDefaultAlign, write=fDefaultAlign, nodefault
		};
	__property Graphics::TPen* BorderPen = {read=fBorderPen};
	__property Graphics::TBrush* Brush = {read=fBrush};
	__property double Zoom = {read=fZoom, write=fZoom};
	__property OnKeyDown ;
	__property bool ForceDefaultColors = {read=fForceDefaultColors, write=fForceDefaultColors, nodefault
		};
	__property bool IsFontLocked = {read=fFontLocked, write=SetFontLocked, nodefault};
	__property bool AutoSize = {read=fAutoSize, write=fAutoSize, nodefault};
	__property int GlobalLineSpace = {read=fLineSpace, write=fLineSpace, nodefault};
	__property int GlobalFixedHeight = {read=fFixedHeight, write=fFixedHeight, nodefault};
	__property bool WriteFormattedString = {read=fWriteFormattedString, write=fWriteFormattedString, nodefault
		};
	__property AnsiString FormattedString = {read=fFormattedString};
	__property PIECharInfo InsertingCharInfo = {read=fInsertingCharInfo};
	void __fastcall SetXFont(Graphics::TFont* fnt);
	void __fastcall SetXBackColor(Graphics::TColor bk);
	__property Classes::TNotifyEvent OnCursorMoved = {read=fOnCursorMoved, write=fOnCursorMoved};
	__property Graphics::TBitmap* UnderBuffer = {read=fUnderBuffer, write=fUnderBuffer};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TIETextControl(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TIEEdit;
class PASCALIMPLEMENTATION TIEEdit : public Stdctrls::TEdit 
{
	typedef Stdctrls::TEdit inherited;
	
private:
	MESSAGE void __fastcall CMWantSpecialKey(Messages::TWMKey &Msg);
	
protected:
	DYNAMIC void __fastcall KeyPress(char &Key);
public:
	#pragma option push -w-inl
	/* TCustomEdit.Create */ inline __fastcall virtual TIEEdit(Classes::TComponent* AOwner) : Stdctrls::TEdit(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TIEEdit(HWND ParentWindow) : Stdctrls::TEdit(ParentWindow
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TIEEdit(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ietextc */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ietextc;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ietextc
