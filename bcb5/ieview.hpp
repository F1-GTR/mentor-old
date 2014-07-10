// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ieview.pas' rev: 5.00

#ifndef ieviewHPP
#define ieviewHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyieutils.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ieview
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIEBitmapChangeEvent)(System::TObject* Sender, bool destroying);
	

typedef TIEBitmapChangeEvent *PIEBitmapChangeEvent;

class DELPHICLASS TIEView;
class PASCALIMPLEMENTATION TIEView : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	Forms::TFormBorderStyle FBorderStyle;
	Classes::TList* fBmpChange;
	Classes::TNotifyEvent fOnMouseEnter;
	Classes::TNotifyEvent fOnMouseLeave;
	void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	bool __fastcall GetCtl3D(void);
	HIDESBASE void __fastcall SetCtl3D(bool v);
	
protected:
	Graphics::TColor fBackGround;
	int fDPIX;
	int fDPIY;
	virtual void __fastcall SetBackGround(Graphics::TColor cl);
	virtual Graphics::TBitmap* __fastcall GetFBitmap(void);
	virtual Hyieutils::TIEBitmap* __fastcall GetIEBitmap(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	virtual Hyieutils::TIEBitmap* __fastcall GetAlphaChannel(void) = 0 ;
	virtual bool __fastcall GetHasAlphaChannel(void) = 0 ;
	
public:
	virtual void __fastcall RemoveAlphaChannel(bool Merge) = 0 ;
	virtual void __fastcall LockPaint(void) = 0 ;
	virtual int __fastcall UnLockPaint(void) = 0 ;
	virtual int __fastcall NPUnLockPaint(void) = 0 ;
	virtual void __fastcall SetDPIX(int dpiX);
	virtual void __fastcall SetDPIY(int dpiY);
	virtual void __fastcall SetDPI(int dpiX, int dpiY);
	virtual void __fastcall ImageChange(void);
	__fastcall virtual TIEView(Classes::TComponent* Owner);
	__fastcall virtual ~TIEView(void);
	__property int DpiX = {read=fDPIX, write=SetDPIX, nodefault};
	__property int DpiY = {read=fDPIY, write=SetDPIY, nodefault};
	__property Graphics::TBitmap* Bitmap = {read=GetFBitmap};
	__property Hyieutils::TIEBitmap* IEBitmap = {read=GetIEBitmap};
	virtual void __fastcall CallBitmapChangeEvents(void);
	int __fastcall RegisterBitmapChangeEvent(TIEBitmapChangeEvent v);
	void __fastcall RemoveBitmapChangeEvent(int idx);
	Graphics::TCanvas* __fastcall GetCanvas(void);
	__property Hyieutils::TIEBitmap* AlphaChannel = {read=GetAlphaChannel};
	__property bool HasAlphaChannel = {read=GetHasAlphaChannel, nodefault};
	
__published:
	__property Graphics::TColor Background = {read=fBackGround, write=SetBackGround, default=-2147483633
		};
	__property Ctl3D  = {read=GetCtl3D, write=SetCtl3D, default=1};
	__property ParentCtl3D ;
	__property Classes::TNotifyEvent OnMouseEnter = {read=fOnMouseEnter, write=fOnMouseEnter};
	__property Classes::TNotifyEvent OnMouseLeave = {read=fOnMouseLeave, write=fOnMouseLeave};
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
public:
		
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TIEView(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int gSystemColors;
extern PACKAGE bool gIsRemoteSession;
extern PACKAGE int gSystemDPIX;
extern PACKAGE int gSystemDPIY;
extern PACKAGE int gDefaultDPIX;
extern PACKAGE int gDefaultDPIY;
extern PACKAGE bool gMMX;
extern PACKAGE int gEdgeX;
extern PACKAGE int gEdgeY;
extern PACKAGE int gBorderX;
extern PACKAGE int gBorderY;
extern PACKAGE int gVScrollWidth;
extern PACKAGE int gHScrollHeight;

}	/* namespace Ieview */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ieview;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ieview
