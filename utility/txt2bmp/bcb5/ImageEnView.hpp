// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'imageenview.pas' rev: 5.00

#ifndef imageenviewHPP
#define imageenviewHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Imageenview
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIEGrip { ieNone, ieTopLeft, ieTopRight, ieBottomRight, ieBottomLeft, ieLeftSide, ieRightSide, 
	ieTopSide, ieBottomSide };
#pragma option pop

#pragma option push -b-
enum TIEAlignment { iejLeft, iejRight, iejCenter, iejJustify };
#pragma option pop

typedef void __fastcall (__closure *TViewChangeEvent)(System::TObject* Sender, int Change);

typedef void __fastcall (__closure *TIEMouseInResizingGripEvent)(System::TObject* Sender, TIEGrip Grip
	);

typedef void __fastcall (__closure *TIEZoomEvent)(System::TObject* Sender, double &NewZoom);

typedef void __fastcall (__closure *TIESpecialKeyEvent)(System::TObject* Sender, Word CharCode, bool 
	&Handled);

#pragma option push -b-
enum TIEScrollCommand { iescPosition, iescBottom, iescTop, iescLineDown, iescLineUp, iescPageDown, iescPageUp 
	};
#pragma option pop

typedef void __fastcall (__closure *TIEOnDrawCanvas)(System::TObject* Sender, Graphics::TCanvas* ACanvas
	, const Windows::TRect &ARect);

typedef void __fastcall (__closure *TIEOnDrawBackground)(System::TObject* Sender, Graphics::TCanvas* 
	ACanvas, const Windows::TRect &ARect, bool &Handled);

#pragma option push -b-
enum TIEWallPaperStyle { iewoNormal, iewoStretch, iewoTile };
#pragma option pop

#pragma option push -b-
enum TIEMouseInteractItems { miZoom, miScroll, miSelect, miSelectPolygon, miSelectCircle, miSelectZoom, 
	miSelectMagicWand, miSelectLasso, miMoveLayers, miResizeLayers };
#pragma option pop

typedef Set<TIEMouseInteractItems, miZoom, miResizeLayers>  TIEMouseInteract;

#pragma option push -b-
enum TIESelectionBase { iesbClientArea, iesbBitmap };
#pragma option pop

#pragma option push -b-
enum TIEBackgroundStyle { iebsSolid, iebsHorizontal, iebsVertical, iebsFDiagonal, iebsBDiagonal, iebsCross, 
	iebsDiagCross, iebsChessboard, iebsDiagonals, iebsCropped, iebsCropShadow, iebsGradient };
#pragma option pop

#pragma option push -b-
enum imageenview__1 { iesoAnimated, iesoSizeable, iesoMoveable, iesoFilled, iesoCutBorders, iesoMarkOuter, 
	iesoCanScroll, iesoSelectTranspLayers };
#pragma option pop

typedef Set<imageenview__1, iesoAnimated, iesoSelectTranspLayers>  TIESelectionOptions;

#pragma option push -b-
enum TIESelOp { iespReplace, iespAdd };
#pragma option pop

#pragma option push -b-
enum TIEMagicWandMode { iewInclusive, iewExclusive, iewGlobal };
#pragma option pop

class DELPHICLASS TIEVSoftShadow;
class PASCALIMPLEMENTATION TIEVSoftShadow : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	bool Enabled;
	double Radius;
	int OffsetX;
	int OffsetY;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIEVSoftShadow(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIEVSoftShadow(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TIEMagnifyStyle { iemRectangle, iemEllipse };
#pragma option pop

#pragma option push -b-
enum TIEMagnifySource { iemBackgroundLayer, iemCanvas };
#pragma option pop

struct TIELayerMagnification
{
	bool Enabled;
	double Rate;
	TIEMagnifyStyle Style;
	TIEMagnifySource Source;
} ;

struct TIEDrawingInfo
{
	int XDst;
	int YDst;
	int WidthDst;
	int HeightDst;
	int XSrc;
	int YSrc;
	int WidthSrc;
	int HeightSrc;
} ;

class DELPHICLASS TIELayer;
class PASCALIMPLEMENTATION TIELayer : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int ResizedWidth;
	int ResizedHeight;
	int __fastcall GetWidth(void);
	int __fastcall GetHeight(void);
	
public:
	System::TObject* fOwner;
	Hyieutils::TIEBitmap* Bitmap;
	bool Visible;
	bool VisibleBox;
	int Transparency;
	int PosX;
	int PosY;
	Windows::TRect ClientAreaBox;
	bool Cropped;
	bool Locked;
	TIELayerMagnification Magnify;
	Hyieutils::TIERenderOperation Operation;
	void *UserData;
	int UserDataLen;
	bool FreeBitmapOnDestroy;
	Hyiedefs::TResampleFilter ResampleFilter;
	bool UseResampleFilter;
	AnsiString Name;
	bool IsMask;
	TIEDrawingInfo DrawingInfo;
	__property int Width = {read=GetWidth, write=ResizedWidth, nodefault};
	__property int Height = {read=GetHeight, write=ResizedHeight, nodefault};
	__fastcall TIELayer(System::TObject* Owner, Hyieutils::TIEBitmap* TemplateBitmap, bool JustAssign);
		
	__fastcall virtual ~TIELayer(void);
	int __fastcall ConvXScr2Bmp(int x);
	int __fastcall ConvYScr2Bmp(int y);
	int __fastcall ConvXBmp2Scr(int x);
	int __fastcall ConvYBmp2Scr(int y);
	void __fastcall Assign(TIELayer* Source);
};


#pragma option push -b-
enum TIELayerEvent { ielSelected, ielMoved, ielResized, ielMoving, ielResizing };
#pragma option pop

typedef void __fastcall (__closure *TIELayerNotify)(System::TObject* Sender, int layer, TIELayerEvent 
	event);

class DELPHICLASS TImageEnView;
class PASCALIMPLEMENTATION TImageEnView : public Ieview::TIEView 
{
	typedef Ieview::TIEView inherited;
	
private:
	bool fLegacyBitmap;
	bool fUseDrawDibDraw;
	Controls::TCursor fLCursor;
	Controls::TCursor fCursor;
	Classes::TNotifyEvent fOnImageChange;
	TViewChangeEvent fOnViewChange;
	bool fCenter;
	Hyiedefs::TResampleFilter fZoomFilter;
	Hyiedefs::TResampleFilter fSaveZoomFilter;
	bool fDelayZoomFilter;
	TIEBackgroundStyle fBackgroundStyle;
	bool fMagicWandMaxFilter;
	int fMagicWandTolerance;
	TIEMagicWandMode fMagicWandMode;
	double fRXScroll;
	double fRYScroll;
	bool fDisplayGrid;
	bool fVScrollBarVisible;
	bool fHScrollBarVisible;
	int fAniCounter;
	Classes::TNotifyEvent fOnPaint;
	TIEMouseInResizingGripEvent fOnMouseInResizingGrip;
	TIEZoomEvent fOnZoomIn;
	TIEZoomEvent fOnZoomOut;
	bool fDelayDisplaySelection;
	Hyiedefs::TIEProgressEvent fOnProgress;
	Classes::TNotifyEvent fOnFinishWork;
	bool fFullUpdateRequest;
	bool fBlockPaint;
	bool fRectMoving;
	bool fDrawVersion;
	Classes::TNotifyEvent fOnDrawBackBuffer;
	TIELayerNotify fOnLayerNotify;
	double fSelectionAspectRatio;
	int fSelectionAbsWidth;
	int fSelectionAbsHeight;
	TIESpecialKeyEvent fOnSpecialKey;
	TImageEnView* fNavigator;
	bool fNavigatorInside;
	bool fUpdateInsideUpdate;
	bool fInsideUpdate;
	int fDelayTimer;
	Windows::TRect fLyrResizingClientAreaBox;
	bool fZoomSelectionAspectRatio;
	double fMouseScrollRate;
	double fLutLastZoomX;
	double fLutLastZoomY;
	int fLutLastFRX;
	int fLutLastFRY;
	int fLutLastMaxLayerWidth;
	int fLutLastMaxLayerHeight;
	int fHSVX1;
	int fHSVY1;
	int fo1x;
	int fo1y;
	int fo2x;
	int fo2y;
	int frx;
	int fry;
	int fBitmapWidth;
	int fBitmapHeight;
	Imageenproc::TIETransitionEffects* fTransition;
	Imageenproc::TIETransitionType fTransitionEffect;
	int fTransitionDuration;
	int fMinBitmapSize;
	bool fTransitionRectMaintainAspectRatio;
	Classes::TNotifyEvent fOnDShowNewFrame;
	Classes::TNotifyEvent fOnDShowEvent;
	bool fFlatScrollBars;
	TIEOnDrawBackground fOnDrawBackground;
	TIEOnDrawCanvas fOnDrawCanvas;
	unsigned fOldHandle;
	Graphics::TPicture* fWallPaper;
	TIEWallPaperStyle fWallPaperStyle;
	void __fastcall AniPolyFunc(System::TObject* Sender, bool UseLockPaint);
	void __fastcall TimerEvent(System::TObject* Sender);
	void __fastcall SetViewX(int v);
	void __fastcall SetViewY(int v);
	void __fastcall SetZoom(double v);
	void __fastcall SetZoomX(double v);
	void __fastcall SetZoomY(double v);
	int __fastcall GetSelX1(void);
	int __fastcall GetSelY1(void);
	int __fastcall GetSelX2(void);
	int __fastcall GetSelY2(void);
	void __fastcall SetCenter(bool v);
	TIEMouseInteract __fastcall GetMouseInteract(void);
	void __fastcall SetBackgroundStyle(TIEBackgroundStyle v);
	void __fastcall DoSelectionChange(void);
	void __fastcall DoSelectionChanging(void);
	void __fastcall DoBeforeSelectionChange(void);
	void __fastcall DoMouseInResizingGrip(TIEGrip Grip);
	void __fastcall DoMouseInSel(void);
	void __fastcall DoZoomIn(double &NewZoom);
	void __fastcall DoZoomOut(double &NewZoom);
	void __fastcall SetSelectionOptions(TIESelectionOptions v);
	TIEGrip __fastcall GetResizingGrip(int x, int y, Classes::TShiftState Shift);
	int __fastcall GetMovingGrip(int x, int y, Classes::TShiftState Shift);
	TIEGrip __fastcall SelectResizeEx(TIEGrip grip, int newx, int newy, bool aspectratio);
	int __fastcall SelectMoveEx(int fMoving, int ox, int oy);
	bool __fastcall GetScrollBarsAlwaysVisible(void);
	void __fastcall SetScrollBarsAlwaysVisible(bool v);
	void __fastcall SetDisplayGrid(bool v);
	bool __fastcall GetTransitionRunning(void);
	int __fastcall GetLayersCount(void);
	TIELayer* __fastcall GetLayer(int idx);
	void __fastcall PaintSelection(Graphics::TBitmap* OutBitmap);
	void __fastcall PaintGrid(Graphics::TBitmap* OutBitmap);
	HIDESBASE void __fastcall SetCursor(Controls::TCursor Value);
	void __fastcall SetDelayTimer(int Value);
	int __fastcall GetDelayTimer(void);
	void __fastcall SetGradientEndColor(Graphics::TColor Value);
	void __fastcall DoDrawVersion(void);
	void __fastcall SetDrawVersion(bool v);
	void __fastcall SetSelectionMaskDepth(int value);
	void __fastcall DrawLayerBox(Graphics::TBitmap* ABitmap, int idx);
	void __fastcall DrawLayerGrips(Graphics::TBitmap* ABitmap, int idx);
	void __fastcall CalcLayerGripCoords(int layeridx, Windows::TRect * coords, const int coords_Size);
	TIEGrip __fastcall FindLayerGrip(int x, int y);
	void __fastcall MouseResizeLayer(int clientlx, int cliently, bool aspectratio);
	MESSAGE void __fastcall DShowNewFrame(Messages::TMessage &Message);
	MESSAGE void __fastcall DShowEvent(Messages::TMessage &Message);
	void __fastcall MouseSelectCircle(int x, int y, Classes::TShiftState Shift);
	void __fastcall MouseSelectRectangle(int x, int y, Classes::TShiftState Shift);
	void __fastcall SetSelectionAspectRatio(double value);
	int __fastcall GetSavedSelectionsCount(void);
	void __fastcall SetFlatScrollBars(bool Value);
	void __fastcall SwapSelectionBase(void);
	void __fastcall NavigatorSelectionChanging(System::TObject* Sender);
	void __fastcall SetNavigatorRect(void);
	AnsiString __fastcall GetImageEnVersion(void);
	void __fastcall SetImageEnVersion(AnsiString Value);
	void __fastcall SetTransitionStartRect(const Windows::TRect &value);
	Windows::TRect __fastcall GetTransitionStartRect(void);
	void __fastcall SetTransitionEndRect(const Windows::TRect &value);
	Windows::TRect __fastcall GetTransitionEndRect(void);
	void __fastcall SetOnTransitionStop(Classes::TNotifyEvent value);
	Classes::TNotifyEvent __fastcall GetOnTransitionStop(void);
	void __fastcall SetTransitionTiming(Imageenproc::TIETransitionTiming value);
	Imageenproc::TIETransitionTiming __fastcall GetTransitionTiming(void);
	void __fastcall SetWallPaper(Graphics::TPicture* Value);
	void __fastcall SetWallPaperStyle(TIEWallPaperStyle Value);
	void __fastcall SetTransitionRectMaintainAspectRatio(bool value);
	Windows::TRect __fastcall AdjustRectToAspectRatio(const Windows::TRect &ARect);
	
protected:
	int fStableReset;
	int fStable2Reset;
	int fStable;
	int fStable2;
	bool fDBToDraw;
	Graphics::TBitmap* fTBitmap;
	void * *fTBitmapScanline;
	int fViewX;
	int fViewY;
	double fZoomX;
	double fZoomY;
	double fZoomD100X;
	double f100DZoomX;
	double fZoomD100Y;
	double f100DZoomY;
	unsigned fHDrawDib;
	Stdctrls::TScrollStyle fScrollBars;
	int fLockPaint;
	int fOffX;
	int fOffY;
	int fExtX;
	int fExtY;
	int fZZWW;
	int fZZHH;
	Graphics::TBitmap* fBitmap;
	#pragma pack(push, 1)
	Hyiedefs::TBitmapInfoHeader256 fBitmapInfoHeader256;
	#pragma pack(pop)
	
	bool fDoubleBuffer;
	bool fAutoFit;
	bool fUpdateInvalidate;
	bool fAutoStretch;
	bool fAutoShrink;
	bool fSel;
	bool fPolySelecting;
	bool fLassoSelecting;
	bool fRectSelecting;
	bool fCircSelecting;
	TIEGrip fRectResizing;
	int fSelectMoving;
	int fMMoveX;
	int fMMoveY;
	int fHSX1;
	int fHSY1;
	int fPredX;
	int fPredY;
	int fPredLX;
	int fPredLY;
	void *fHPolySel;
	TIESelectionBase fSelectionBase;
	TIESelectionBase fSavedSelectionBase;
	Classes::TNotifyEvent fOnSelectionChanging;
	Classes::TNotifyEvent fOnSelectionChange;
	Classes::TNotifyEvent fOnBeforeSelectionChange;
	Classes::TNotifyEvent fOnMouseInSel;
	TIESelectionOptions fSelectionOptions;
	int fStartingPolyCount;
	Hyieutils::TIEMask* fSelectionMask;
	int fSelectionMaskDepth;
	int fSelectionIntensity;
	Graphics::TColor fSelColor1;
	Graphics::TColor fSelColor2;
	Graphics::TColor fGripColor1;
	Graphics::TColor fGripColor2;
	Graphics::TBrushStyle fGripBrushStyle;
	int fGripSize;
	bool fExtendedGrips;
	int fChessboardSize;
	Graphics::TBrushStyle fChessboardBrushStyle;
	bool fForceALTkey;
	bool fMouseMoveScrolling;
	Classes::TList* fSavedSelection;
	bool fEnableShiftKey;
	Graphics::TColor fGradientEndColor;
	int fUpdateLocked;
	Classes::TList* fAnimPoly;
	Extctrls::TTimer* fAnimPolyTimer;
	TIEMouseInteract fMouseInteract;
	bool fScrollBarsAlwaysVisible;
	Hyieutils::TIEScrollBarParams* fVScrollBarParams;
	Hyieutils::TIEScrollBarParams* fHScrollBarParams;
	Hyieutils::TIEMouseWheelParams* fMouseWheelParams;
	int flx1;
	int fly1;
	int flx2;
	int fly2;
	bool fEnableAlphaChannel;
	Hyieutils::TIEBitmap* fIEBitmap;
	Imageenio::TImageEnIO* fImageEnIO;
	Imageenproc::TImageEnProc* fImageEnProc;
	Classes::TList* fLayers;
	int fLayersCurrent;
	int fMaxLayerWidth;
	int fMaxLayerHeight;
	bool fLayersSync;
	bool fLayersDrawBox;
	int fMovingLayer;
	TIEGrip fLayerResizing;
	int *fGXScr2Bmp;
	int *fGYScr2Bmp;
	int *fXScr2Bmp;
	int *fYScr2Bmp;
	int fXScr2BmpSize;
	int fYScr2BmpSize;
	int *fXBmp2Scr;
	int *fYBmp2Scr;
	int *fGXBmp2Scr;
	int *fGYBmp2Scr;
	int fXBmp2ScrSize;
	int fYBmp2ScrSize;
	bool fAutoCursors;
	void __fastcall CalcEdges(int &EdgeX, int &EdgeY, bool NoVertSB, bool NoHorizSB);
	virtual void __fastcall SetBackGround(Graphics::TColor cl);
	void __fastcall PolyDraw1(void);
	virtual void __fastcall SetScrollBars(Stdctrls::TScrollStyle v);
	void __fastcall GetMaxViewXY(int &mx, int &my);
	double __fastcall GetOptimalZoom(int ibitmapwidth, int ibitmapheight, int iwidth, int iheight, bool 
		bolStretch, bool bolShrink);
	void __fastcall DoSize(void);
	void __fastcall DoVertScroll(TIEScrollCommand command, int Position);
	void __fastcall DoHorizScroll(TIEScrollCommand command, int Position);
	void __fastcall DoMouseWheelScroll(int Delta, int mouseX, int mouseY, bool CtrlPressed);
	void __fastcall DoDoubleClickEx(bool Shift);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMHScroll(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseWheel(Messages::TMessage &Message);
	HPALETTE __fastcall _CreatePalette(void);
	DYNAMIC bool __fastcall PaletteChanged(bool Foreground);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Msg);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Msg);
	MESSAGE void __fastcall CMWantSpecialKey(Messages::TWMKey &Msg);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Messages::TMessage &Message);
	MESSAGE void __fastcall IEMUpdate(Messages::TMessage &Message);
	MESSAGE void __fastcall IEMProgress(Messages::TMessage &Message);
	MESSAGE void __fastcall IEMFinishWork(Messages::TMessage &Message);
	void __fastcall RestoreCursor(void);
	void __fastcall ShowSelectionEx(bool d);
	void __fastcall HideSelectionEx(bool dd);
	int __fastcall GetIdealComponentWidth(void);
	int __fastcall GetIdealComponentHeight(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	Windows::TPoint __fastcall GetPolySel(int idx);
	int __fastcall GetPolySelCount(void);
	virtual void __fastcall SetMouseInteract(TIEMouseInteract v);
	void __fastcall AnimPolygonAddPtEx(int ap, int x, int y);
	void __fastcall AnimPolygonAddBreak(int ap);
	void __fastcall AnimPolygonRemoveLast(int ap);
	void __fastcall AnimPolygonRemoveLastPoint(int ap);
	void __fastcall AnimPolygonMove(int ap, int ox, int oy, int max_x, int max_y, bool CutSel);
	virtual void __fastcall ViewChange(int c);
	void __fastcall SetZoomFilter(Hyiedefs::TResampleFilter v);
	virtual void __fastcall SubMouseMoveScroll(int scx, int scy);
	bool __fastcall MouseMoveScroll(void);
	virtual Graphics::TBitmap* __fastcall GetFBitmap(void);
	virtual Hyieutils::TIEBitmap* __fastcall GetIEBitmap(void);
	void __fastcall SetVisibleSelection(bool vv);
	bool __fastcall GetVisibleSelection(void);
	Hyiedefs::PPointArray __fastcall GetPolySelArray(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	void __fastcall AddSelPointEx(int x, int y);
	void __fastcall AddSelBreakEx(void);
	void __fastcall SelectEx(int x1, int y1, int x2, int y2, TIESelOp Op, bool aspectratio, bool adjRect
		);
	HIDESBASE virtual int __fastcall GetClientWidth(void);
	HIDESBASE virtual int __fastcall GetClientHeight(void);
	virtual bool __fastcall HasParentWindow(void);
	void __fastcall SetSelColor1(Graphics::TColor v);
	void __fastcall SetSelColor2(Graphics::TColor v);
	Imageenio::TImageEnIO* __fastcall GetImageEnIO(void);
	Imageenproc::TImageEnProc* __fastcall GetImageEnProc(void);
	void __fastcall SetEnableAlphaChannel(bool v);
	virtual void __fastcall SetOnProgress(Hyiedefs::TIEProgressEvent v);
	virtual void __fastcall SetOnFinishWork(Classes::TNotifyEvent v);
	virtual Hyiedefs::TIEProgressEvent __fastcall GetOnProgress(void);
	virtual Classes::TNotifyEvent __fastcall GetOnFinishWork(void);
	virtual bool __fastcall GetHasAlphaChannel(void);
	virtual Hyieutils::TIEBitmap* __fastcall GetAlphaChannel(void);
	virtual bool __fastcall GetIsEmpty(void);
	bool __fastcall RequiresScrollBars(void);
	virtual void __fastcall SetLayersCurrent(int Value);
	void __fastcall DoLayersSync(void);
	virtual void __fastcall SetLegacyBitmap(bool Value);
	virtual void __fastcall CreateCoordConvLUT(void);
	virtual void __fastcall CalcPaintCoords(void);
	void __fastcall CalcPaintCoordsEx(int &XSrc, int &YSrc, int &SrcWidth, int &SrcHeight, int &DstWidth
		, int &DstHeight, int tViewX, int tViewY);
	virtual void __fastcall UpdateLimits(void);
	int __fastcall QuantizeViewX(int vx);
	int __fastcall QuantizeViewY(int vy);
	void __fastcall HideHorizScrollBar(void);
	void __fastcall HideVertScrollBar(void);
	void __fastcall SetSelectionIntensity(int value);
	void __fastcall SetLayersSync(bool value);
	void __fastcall SetLayersDrawBox(bool value);
	virtual void __fastcall DoLayerNotify(int layer, TIELayerEvent event);
	void __fastcall SetTempCursor(Controls::TCursor Value);
	TIELayer* __fastcall GetCurrentLayer(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall GetFitValueXY(double &x, double &y);
	
public:
	__fastcall virtual TImageEnView(Classes::TComponent* Owner);
	__fastcall virtual ~TImageEnView(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PaintToEx(Graphics::TBitmap* ABitmap, Hyiedefs::PPointerArray ABitmapScanline
		, Windows::PRect UpdRect);
	void __fastcall GetRenderRectangles(int &xDst, int &yDst, int &dxDst, int &dyDst, int &xSrc, int &ySrc
		, int &dxSrc, int &dySrc);
	virtual void __fastcall SetZoomNoUpdate(double v);
	virtual void __fastcall SetZoomXNoUpdate(double v);
	virtual void __fastcall SetZoomYNoUpdate(double v);
	double __fastcall GetFitValue(void);
	void __fastcall DrawBackgroundToCanvas(Graphics::TCanvas* ACanvas);
	virtual void __fastcall Select(int x1, int y1, int x2, int y2, TIESelOp Op);
	void __fastcall SelectMagicWand(int x, int y, TIESelOp Op);
	void __fastcall SelectEllipse(int CenterX, int CenterY, int Width, int Height, TIESelOp Op);
	void __fastcall SelectRoundRect(int Left, int Top, int Right, int Bottom, int RoundWidth, int RoundHeight
		, TIESelOp Op);
	void __fastcall SelectCustom(void);
	void __fastcall MoveSelection(int OffsetX, int OffsetY);
	__property double SelectionAspectRatio = {read=fSelectionAspectRatio, write=SetSelectionAspectRatio
		};
	__property int SelectionAbsWidth = {read=fSelectionAbsWidth, write=fSelectionAbsWidth, nodefault};
	__property int SelectionAbsHeight = {read=fSelectionAbsHeight, write=fSelectionAbsHeight, nodefault
		};
	void __fastcall DeSelect(void);
	__property int SelX1 = {read=GetSelX1, nodefault};
	__property int SelY1 = {read=GetSelY1, nodefault};
	__property int SelX2 = {read=GetSelX2, nodefault};
	__property int SelY2 = {read=GetSelY2, nodefault};
	virtual void __fastcall AddSelPoint(int x, int y);
	void __fastcall AddSelBreak(void);
	__property Windows::TPoint PolySel[int idx] = {read=GetPolySel};
	__property int PolySelCount = {read=GetPolySelCount, nodefault};
	__property Hyiedefs::PPointArray PolySelPoints = {read=GetPolySelArray};
	__property bool Selected = {read=fSel, nodefault};
	__property bool VisibleSelection = {read=GetVisibleSelection, write=SetVisibleSelection, nodefault}
		;
	__property bool MagicWandMaxFilter = {read=fMagicWandMaxFilter, write=fMagicWandMaxFilter, nodefault
		};
	__property int MagicWandTolerance = {read=fMagicWandTolerance, write=fMagicWandTolerance, nodefault
		};
	__property TIEMagicWandMode MagicWandMode = {read=fMagicWandMode, write=fMagicWandMode, nodefault};
		
	bool __fastcall IsPointInsideSelection(int x, int y);
	__property Hyieutils::TIEMask* SelectionMask = {read=fSelectionMask};
	void __fastcall InvertSelection(void);
	void __fastcall SetSelectedAreaAlpha(int Alpha);
	void __fastcall SetSelectionGripStyle(Graphics::TColor GripColor1, Graphics::TColor GripColor2, Graphics::TBrushStyle 
		GripBrushStyle, int GripSize, bool ExtendedGrips);
	void __fastcall CopySelectionToBitmap(Graphics::TBitmap* DestBitmap);
	void __fastcall CopySelectionToIEBitmap(Hyieutils::TIEBitmap* DestBitmap);
	virtual void __fastcall EndSelect(void);
	void __fastcall SetSelectedPixelsColor(Hyiedefs::TRGB color);
	void __fastcall SetAlphaRangePixelsColor(int alphaMin, int alphaMax, Hyiedefs::TRGB color);
	void __fastcall SaveSelectionToStream(Classes::TStream* Stream);
	bool __fastcall LoadSelectionFromStream(Classes::TStream* Stream);
	bool __fastcall MergeSelectionFromStream(Classes::TStream* Stream);
	void __fastcall SaveSelection(void);
	bool __fastcall RestoreSelection(void);
	bool __fastcall DiscardSavedSelection(void);
	__property int SavedSelectionsCount = {read=GetSavedSelectionsCount, nodefault};
	__property bool EnableShiftKey = {read=fEnableShiftKey, write=fEnableShiftKey, nodefault};
	__property int SelectionMaskDepth = {read=fSelectionMaskDepth, write=SetSelectionMaskDepth, nodefault
		};
	__property int SelectionIntensity = {read=fSelectionIntensity, write=SetSelectionIntensity, nodefault
		};
	void __fastcall MakeSelectionFeather(double radius);
	int __fastcall AnimPolygonNew(Graphics::TColor VColor1, Graphics::TColor VColor2, bool VAnimated, bool 
		VSizeable);
	void __fastcall AnimPolygonDel(int ap);
	void __fastcall AnimPolygonAddPt(int ap, int x, int y);
	void __fastcall AnimPolygonClear(int ap);
	void __fastcall AnimPolygonEnabled(int ap, bool Value);
	void __fastcall CopyFromPolygon(Graphics::TBitmap* Source, const Windows::TPoint * Polygon, const int 
		Polygon_Size, int PolygonLen, const Windows::TPoint &Position);
	void __fastcall CopyToPolygon(Graphics::TBitmap* Dest, const Windows::TPoint * Polygon, const int Polygon_Size
		, int PolygonLen, const Windows::TPoint &Position);
	virtual void __fastcall Update(void);
	void __fastcall UpdateNoPaint(void);
	void __fastcall Fit(void);
	void __fastcall FitToWidth(void);
	void __fastcall FitToHeight(void);
	void __fastcall Stretch(void);
	double __fastcall GetIdealZoom(void);
	__property int ViewX = {read=fViewX, write=SetViewX, nodefault};
	__property int ViewY = {read=fViewY, write=SetViewY, nodefault};
	void __fastcall CenterImage(void);
	void __fastcall SetViewXY(int x, int y);
	__property double Zoom = {read=fZoomX, write=SetZoom};
	__property double ZoomX = {read=fZoomX, write=SetZoomX};
	__property double ZoomY = {read=fZoomY, write=SetZoomY};
	void __fastcall ZoomSelection(bool AspectRatio);
	void __fastcall DisplayImageRect(const Windows::TRect &ARect);
	void __fastcall ZoomAt(int x, int y, double ZoomVal, bool Center);
	__property ClientWidth  = {read=GetClientWidth};
	__property ClientHeight  = {read=GetClientHeight};
	__property int IdealComponentWidth = {read=GetIdealComponentWidth, nodefault};
	__property int IdealComponentHeight = {read=GetIdealComponentHeight, nodefault};
	virtual void __fastcall LockPaint(void);
	virtual int __fastcall UnLockPaint(void);
	virtual int __fastcall NPUnLockPaint(void);
	__property int LockPaintCount = {read=fLockPaint, nodefault};
	void __fastcall DrawTo(Graphics::TCanvas* Canvas);
	__property int OffsetX = {read=fOffX, nodefault};
	__property int OffsetY = {read=fOffY, nodefault};
	__property int ExtentX = {read=fExtX, nodefault};
	__property int ExtentY = {read=fExtY, nodefault};
	__property bool ScrollBarsAlwaysVisible = {read=GetScrollBarsAlwaysVisible, write=SetScrollBarsAlwaysVisible
		, default=0};
	__property Hyieutils::TIEScrollBarParams* VScrollBarParams = {read=fVScrollBarParams};
	__property Hyieutils::TIEScrollBarParams* HScrollBarParams = {read=fHScrollBarParams};
	void __fastcall UpdateRect(const Windows::TRect &rclip);
	void __fastcall PaintRect(const Windows::TRect &rc);
	void __fastcall LockUpdate(void);
	void __fastcall UnLockUpdate(void);
	__property Graphics::TBitmap* BackBuffer = {read=fTBitmap};
	void __fastcall SetNavigator(TImageEnView* nav);
	__property int MinBitmapSize = {read=fMinBitmapSize, write=fMinBitmapSize, nodefault};
	void __fastcall ChangeResolution(int NewDPI, Hyiedefs::TResampleFilter ResampleFilter);
	__property int LayersCount = {read=GetLayersCount, nodefault};
	__property int LayersCurrent = {read=fLayersCurrent, write=SetLayersCurrent, nodefault};
	int __fastcall LayersAdd(void);
	void __fastcall LayersInsert(int Position);
	void __fastcall LayersRemove(int idx);
	void __fastcall LayersClear(void);
	void __fastcall LayersMove(int CurIndex, int NewIndex);
	void __fastcall LayersMerge(int Layer0, int Layer1, bool RemoveUpperLayer);
	void __fastcall LayersMergeTo(int Layer0, int Layer1, Hyieutils::TIEBitmap* Destination);
	__property TIELayer* Layers[int idx] = {read=GetLayer};
	__property int MaxLayerWidth = {read=fMaxLayerWidth, nodefault};
	__property int MaxLayerHeight = {read=fMaxLayerHeight, nodefault};
	__property bool LayersSync = {read=fLayersSync, write=SetLayersSync, nodefault};
	__property bool LayersDrawBox = {read=fLayersDrawBox, write=SetLayersDrawBox, nodefault};
	int __fastcall FindLayerAt(int x, int y);
	__property TIELayer* CurrentLayer = {read=GetCurrentLayer};
	void __fastcall LayersSaveToStream(Classes::TStream* Stream, int CompressionFormat);
	void __fastcall LayersSaveToFile(const AnsiString FileName, int CompressionFormat);
	bool __fastcall LayersLoadFromStream(Classes::TStream* Stream);
	bool __fastcall LayersLoadFromFile(const AnsiString FileName);
	int __fastcall LayersCreateFromSelection(void);
	void __fastcall SetExternalBitmap(Hyieutils::TIEBitmap* bmp);
	__property Graphics::TColor GradientEndColor = {read=fGradientEndColor, write=SetGradientEndColor, 
		nodefault};
	__property MouseCapture ;
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall AssignSelTo(Classes::TPersistent* Dest);
	virtual void __fastcall ImageChange(void);
	int __fastcall YScr2Bmp(int y);
	int __fastcall XScr2Bmp(int x);
	int __fastcall YBmp2Scr(int y);
	int __fastcall XBmp2Scr(int x);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property Graphics::TColor SelColor1 = {read=fSelColor1, write=SetSelColor1, default=0};
	__property Graphics::TColor SelColor2 = {read=fSelColor2, write=SetSelColor2, default=16777215};
	void __fastcall Clear(void);
	void __fastcall Blank(void);
	__property bool DisplayGrid = {read=fDisplayGrid, write=SetDisplayGrid, nodefault};
	__property Hyieutils::TIEMouseWheelParams* MouseWheelParams = {read=fMouseWheelParams};
	void __fastcall SetChessboardStyle(int Size, Graphics::TBrushStyle BrushStyle);
	__property bool ForceALTkey = {read=fForceALTkey, write=fForceALTkey, nodefault};
	__property bool DelayDisplaySelection = {read=fDelayDisplaySelection, write=fDelayDisplaySelection, 
		nodefault};
	__property int DelayZoomTime = {read=fStableReset, write=fStableReset, nodefault};
	__property int DelayTimer = {read=GetDelayTimer, write=SetDelayTimer, nodefault};
	void __fastcall CopyToBitmapWithAlpha(Graphics::TBitmap* Dest, int DestX, int DestY);
	__property bool UseDrawDibDraw = {read=fUseDrawDibDraw, write=fUseDrawDibDraw, nodefault};
	TIEGrip __fastcall GetGripAt(int x, int y);
	virtual void __fastcall RemoveAlphaChannel(bool Merge);
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
	__property bool AutoCursors = {read=fAutoCursors, write=fAutoCursors, nodefault};
	__property bool ZoomSelectionAspectRatio = {read=fZoomSelectionAspectRatio, write=fZoomSelectionAspectRatio
		, nodefault};
	__property double MouseScrollRate = {read=fMouseScrollRate, write=fMouseScrollRate};
	__property Imageenio::TImageEnIO* IO = {read=GetImageEnIO};
	__property Imageenproc::TImageEnProc* Proc = {read=GetImageEnProc};
	__property bool TransitionRunning = {read=GetTransitionRunning, nodefault};
	void __fastcall PrepareTransition(void);
	void __fastcall RunTransition(Imageenproc::TIETransitionType Effect, int duration);
	void __fastcall AbortTransition(void);
	void __fastcall PrepareTransitionBitmap(Graphics::TBitmap* OriginalBitmap, Graphics::TBitmap* TargetBitmap
		, Imageenproc::TIETransitionType Effect);
	void __fastcall CreateTransitionBitmapFrame(int iStep, Graphics::TBitmap* ToBitmap);
	__property Windows::TRect TransitionStartRect = {read=GetTransitionStartRect, write=SetTransitionStartRect
		};
	__property Windows::TRect TransitionEndRect = {read=GetTransitionEndRect, write=SetTransitionEndRect
		};
	__property bool TransitionRectMaintainAspectRatio = {read=fTransitionRectMaintainAspectRatio, write=
		SetTransitionRectMaintainAspectRatio, nodefault};
	__property Imageenproc::TIETransitionTiming TransitionTiming = {read=GetTransitionTiming, write=SetTransitionTiming
		, nodefault};
	
__published:
	__property bool LegacyBitmap = {read=fLegacyBitmap, write=SetLegacyBitmap, default=1};
	__property bool DoubleBuffer = {read=fDoubleBuffer, write=fDoubleBuffer, default=1};
	__property Hyiedefs::TResampleFilter ZoomFilter = {read=fZoomFilter, write=SetZoomFilter, default=0
		};
	__property Stdctrls::TScrollStyle ScrollBars = {read=fScrollBars, write=SetScrollBars, default=3};
	__property TViewChangeEvent OnViewChange = {read=fOnViewChange, write=fOnViewChange};
	__property Classes::TNotifyEvent OnImageChange = {read=fOnImageChange, write=fOnImageChange};
	__property TIESelectionOptions SelectionOptions = {read=fSelectionOptions, write=SetSelectionOptions
		, default=71};
	__property bool Center = {read=fCenter, write=SetCenter, default=1};
	__property TIEMouseInteract MouseInteract = {read=GetMouseInteract, write=SetMouseInteract, default=0
		};
	__property bool AutoFit = {read=fAutoFit, write=fAutoFit, default=0};
	__property TIESelectionBase SelectionBase = {read=fSelectionBase, write=fSelectionBase, default=0};
		
	__property TIEBackgroundStyle BackgroundStyle = {read=fBackgroundStyle, write=SetBackgroundStyle, default=0
		};
	__property Classes::TNotifyEvent OnSelectionChange = {read=fOnSelectionChange, write=fOnSelectionChange
		};
	__property Classes::TNotifyEvent OnSelectionChanging = {read=fOnSelectionChanging, write=fOnSelectionChanging
		};
	__property Classes::TNotifyEvent OnMouseInSel = {read=fOnMouseInSel, write=fOnMouseInSel};
	__property bool DelayZoomFilter = {read=fDelayZoomFilter, write=fDelayZoomFilter, default=0};
	__property Classes::TNotifyEvent OnPaint = {read=fOnPaint, write=fOnPaint};
	__property bool EnableAlphaChannel = {read=fEnableAlphaChannel, write=SetEnableAlphaChannel, default=0
		};
	__property TIEMouseInResizingGripEvent OnMouseInResizingGrip = {read=fOnMouseInResizingGrip, write=
		fOnMouseInResizingGrip};
	__property TIEZoomEvent OnZoomIn = {read=fOnZoomIn, write=fOnZoomIn};
	__property TIEZoomEvent OnZoomOut = {read=fOnZoomOut, write=fOnZoomOut};
	__property Hyiedefs::TIEProgressEvent OnProgress = {read=GetOnProgress, write=SetOnProgress};
	__property Classes::TNotifyEvent OnFinishWork = {read=GetOnFinishWork, write=SetOnFinishWork};
	__property bool AutoStretch = {read=fAutoStretch, write=fAutoStretch, default=0};
	__property bool AutoShrink = {read=fAutoShrink, write=fAutoShrink, default=0};
	__property Classes::TNotifyEvent OnBeforeSelectionChange = {read=fOnBeforeSelectionChange, write=fOnBeforeSelectionChange
		};
	__property bool DrawVersion = {read=fDrawVersion, write=SetDrawVersion, default=0};
	__property Classes::TNotifyEvent OnDrawBackBuffer = {read=fOnDrawBackBuffer, write=fOnDrawBackBuffer
		};
	__property TIELayerNotify OnLayerNotify = {read=fOnLayerNotify, write=fOnLayerNotify};
	__property TIESpecialKeyEvent OnSpecialKey = {read=fOnSpecialKey, write=fOnSpecialKey};
	__property AnsiString ImageEnVersion = {read=GetImageEnVersion, write=SetImageEnVersion};
	__property TIEOnDrawBackground OnDrawBackground = {read=fOnDrawBackground, write=fOnDrawBackground}
		;
	__property TIEOnDrawCanvas OnDrawCanvas = {read=fOnDrawCanvas, write=fOnDrawCanvas};
	__property Graphics::TPicture* WallPaper = {read=fWallPaper, write=SetWallPaper};
	__property TIEWallPaperStyle WallPaperStyle = {read=fWallPaperStyle, write=SetWallPaperStyle, default=0
		};
	__property Classes::TNotifyEvent OnTransitionStop = {read=GetOnTransitionStop, write=SetOnTransitionStop
		};
	__property Anchors ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property DragCursor ;
	__property Classes::TNotifyEvent OnDShowNewFrame = {read=fOnDShowNewFrame, write=fOnDShowNewFrame};
		
	__property Classes::TNotifyEvent OnDShowEvent = {read=fOnDShowEvent, write=fOnDShowEvent};
	__property Controls::TCursor Cursor = {read=fCursor, write=SetCursor, default=1785};
	__property bool FlatScrollBars = {read=fFlatScrollBars, write=SetFlatScrollBars, default=0};
	__property Align ;
	__property DragMode ;
	__property Enabled ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property Visible ;
	__property TabOrder ;
	__property TabStop ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TImageEnView(HWND ParentWindow) : Ieview::TIEView(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall IEDrawGradient(const Windows::TRect &R, HDC DC, Graphics::TColor ColorStart
	, Graphics::TColor ColorStop, bool bVertical);
extern PACKAGE void __fastcall IEDrawBackground(Classes::TComponentState ComponentState, Graphics::TCanvas* 
	Canvas, Graphics::TBitmap* Bitmap, TIEBackgroundStyle fBackgroundStyle, Graphics::TColor fBackGround
	, int DestX, int DestY, int Width, int Height, int x1, int y1, int x2, int y2, int fChessboardSize, 
	Graphics::TBrushStyle fChessboardBrushStyle, Graphics::TColor fGradientEndColor, Graphics::TPicture* 
	WallPaper, TIEWallPaperStyle WallPaperStyle);
extern PACKAGE bool __fastcall _IsRectangle(Hyiedefs::PPointArray p, int n);
extern PACKAGE void __fastcall IELayersMerge(TIELayer* Layer0, TIELayer* Layer1, TIELayer* LayerMask
	, Hyieutils::TIEBitmap* Destination, Hyiedefs::TResampleFilter ZoomFilter, Graphics::TColor Background
	, bool RelativePositions);

}	/* namespace Imageenview */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Imageenview;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// imageenview
