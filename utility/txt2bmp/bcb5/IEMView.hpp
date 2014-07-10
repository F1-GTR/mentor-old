// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'iemview.pas' rev: 5.00

#ifndef iemviewHPP
#define iemviewHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <ievect.hpp>	// Pascal unit
#include <iepresetim.hpp>	// Pascal unit
#include <iemio.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <imageenview.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Clipbrd.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Iemview
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIEImageSelectEvent)(System::TObject* Sender, int idx);

typedef void __fastcall (__closure *TIEImageIDRequestEvent)(System::TObject* Sender, int ID, Graphics::TBitmap* 
	&Bitmap);

typedef void __fastcall (__closure *TIEImageIDRequestExEvent)(System::TObject* Sender, int ID, Hyieutils::TIEBitmap* 
	&Bitmap);

typedef void __fastcall (__closure *TIEMProgressEvent)(System::TObject* Sender, int per, int idx);

typedef void __fastcall (__closure *TIEWrongImageEvent)(System::TObject* Sender, Hyieutils::TIEBitmap* 
	OutBitmap, int idx, bool &Handled);

typedef void __fastcall (__closure *TIEImageDrawEvent)(System::TObject* Sender, int idx, int Left, int 
	Top, Graphics::TCanvas* Canvas);

typedef void __fastcall (__closure *TIEImageDrawEventEx)(System::TObject* Sender, int idx, int Left, 
	int Top, Graphics::TBitmap* Dest, Windows::TRect &ThumbRect);

typedef int __fastcall (*TIEImageEnMViewSortCompare)(int Item1, int Item2);

#pragma option push -b-
enum TIEStoreType { ietNormal, ietThumb };
#pragma option pop

#pragma option push -b-
enum TIEMTextPos { iemtpTop, iemtpBottom, iemtpInfo };
#pragma option pop

#pragma option push -b-
enum TIEMTruncSide { iemtsLeft, iemtsRight };
#pragma option pop

class DELPHICLASS TIEMText;
class PASCALIMPLEMENTATION TIEMText : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	WideString fCaption;
	Graphics::TFont* fFont;
	Graphics::TColor fBackground;
	Graphics::TBrushStyle fBackgroundStyle;
	Classes::TComponent* fOwner;
	TIEMTextPos fPos;
	TIEMTruncSide fTruncSide;
	void __fastcall SetCaption(WideString value);
	
public:
	__fastcall TIEMText(Classes::TComponent* Owner, TIEMTextPos Position);
	__fastcall virtual ~TIEMText(void);
	__property WideString Caption = {read=fCaption, write=SetCaption};
	__property Graphics::TFont* Font = {read=fFont};
	__property Graphics::TColor Background = {read=fBackground, write=fBackground, nodefault};
	__property Graphics::TBrushStyle BackgroundStyle = {read=fBackgroundStyle, write=fBackgroundStyle, 
		nodefault};
	__property TIEMTruncSide TruncSide = {read=fTruncSide, write=fTruncSide, nodefault};
};


struct TIEImageInfo
{
	System::TObject* parent;
	void *image;
	void *cacheImage;
	int X;
	int Y;
	int row;
	int col;
	Graphics::TColor Background;
	char *name;
	int ID;
	int DTime;
	TIEMText* TopText;
	TIEMText* BottomText;
	TIEMText* InfoText;
	Windows::TRect internalrect;
} ;

typedef TIEImageInfo *PIEImageInfo;

#pragma option push -b-
enum TIEMMouseInteractItems { mmiScroll, mmiSelect };
#pragma option pop

typedef Set<TIEMMouseInteractItems, mmiScroll, mmiSelect>  TIEMMouseInteract;

#pragma option push -b-
enum TIEMKeyInteractItems { mkiMoveSelected };
#pragma option pop

typedef Set<TIEMKeyInteractItems, mkiMoveSelected, mkiMoveSelected>  TIEMKeyInteract;

#pragma option push -b-
enum TIEMDisplayMode { mdGrid, mdSingle };
#pragma option pop

#pragma option push -b-
enum TIESeek { iskLeft, iskRight, iskUp, iskDown, iskFirst, iskLast, iskPagDown, iskPagUp };
#pragma option pop

#pragma option push -b-
enum TIEMStyle { iemsFlat, iemsACD };
#pragma option pop

#pragma option push -b-
enum TIESStyle { iessAround, iessACD };
#pragma option pop

#pragma option push -b-
enum iemview__2 { iemoRegion, iemoSelectOnMouseUp };
#pragma option pop

typedef Set<iemview__2, iemoRegion, iemoSelectOnMouseUp>  TIEMultiSelectionOptions;

class DELPHICLASS TIEStarter;
class DELPHICLASS TImageEnMView;
class PASCALIMPLEMENTATION TImageEnMView : public Ieview::TIEView 
{
	typedef Ieview::TIEView inherited;
	
private:
	bool fMDown;
	Hyieutils::TIEBitmap* fBackBuffer;
	int fHSVX1;
	int fHSVY1;
	Stdctrls::TScrollStyle fScrollBars;
	double fRXScroll;
	double fRYScroll;
	int fViewX;
	int fViewY;
	Hyieutils::TIEVirtualImageList* fImageList;
	Hyieutils::TIEVirtualImageList* fCacheList;
	Classes::TList* fImageInfo;
	TIEStoreType fStoreType;
	int fThumbWidth;
	int fThumbHeight;
	int fHorizBorder;
	int fVertBorder;
	int fVWidth;
	int fVHeight;
	Imageenview::TViewChangeEvent fOnViewChange;
	TIEMProgressEvent fOnDrawProgress;
	TIEWrongImageEvent fOnWrongImage;
	unsigned fHDrawDib;
	TIEImageIDRequestEvent fOnImageIDRequest;
	TIEImageIDRequestExEvent fOnImageIDRequestEx;
	TIEImageDrawEvent fOnImageDraw;
	Hyiedefs::TIEProgressEvent fOnIOProgress;
	int fBottomGap;
	int fUpperGap;
	TIEMDisplayMode fDisplayMode;
	int fGridWidth;
	int fHSX1;
	int fHSY1;
	int fHSIDX;
	int fLHSIDX;
	int fHSIDX2;
	Imageenio::TImageEnIO* fImageEnIO;
	int fLockPaint;
	bool fRemoveCorrupted;
	bool fDrawImageBackground;
	bool fScrollBarsAlwaysVisible;
	Hyieutils::TIEScrollBarParams* fVScrollBarParams;
	Hyieutils::TIEScrollBarParams* fHScrollBarParams;
	Hyiedefs::TResampleFilter fThumbnailResampleFilter;
	Hyiedefs::TResampleFilter fThumbnailDisplayFilter;
	bool fDestroying;
	TIEMStyle fStyle;
	TIESStyle fSelectionStyle;
	bool fDoubleClicking;
	Graphics::TColor fThumbnailsBackground;
	int fThumbnailsBorderWidth;
	Graphics::TColor fThumbnailsBorderColor;
	bool fThumbnailsInternalBorder;
	Graphics::TColor fThumbnailsInternalBorderColor;
	bool fUpdating;
	bool fEnableResamplingOnMinor;
	int fThumbsRounded;
	bool fEnableAdjustOrientation;
	bool fEnableLoadEXIFThumbnails;
	bool fEnableAlphaChannel;
	Imageenview::TIEBackgroundStyle fBackgroundStyle;
	Imageenview::TIEBackgroundStyle fThumbnailsBackgroundStyle;
	bool fFillThumbnail;
	TIEImageEnMViewSortCompare fCurrentCompare;
	int fThreadPoolSize;
	Classes::TList* fThreadPoolIO;
	Classes::TList* fThreadRequests;
	TIEStarter* fThreadStarter;
	Classes::TList* fLookAheadList;
	Graphics::TPicture* fWallPaper;
	Imageenview::TIEWallPaperStyle fWallPaperStyle;
	int fSelectedItem;
	bool fVisibleSelection;
	int fSelectionWidth;
	int fSelectionWidthNoFocus;
	Graphics::TColor fSelectionColor;
	TIEImageSelectEvent fOnImageSelect;
	TIEImageSelectEvent fOnImageDeselect;
	TIEMMouseInteract fMouseInteract;
	TIEMKeyInteract fKeyInteract;
	Hyieutils::TIEBitmap* fSelectedBitmap;
	int fImageCacheSize;
	bool fMultiSelecting;
	bool fEnableMultiSelect;
	bool fHaveMultiselected;
	bool fSelectInclusive;
	TIEMultiSelectionOptions fMultiSelectionOptions;
	bool fSelectImages;
	bool fChangedSel;
	bool fPlaying;
	int fPlayTimer;
	bool fPlayLoop;
	bool fTimerInProgress;
	int fFrame;
	TIEMDisplayMode fSaveDM;
	int fSaveSel;
	int fLastImOp;
	int fLastImIdx;
	int fLastImP1;
	Imageenproc::TIETransitionEffects* fTransition;
	Imageenproc::TIETransitionType fTransitionEffect;
	int fTransitionDuration;
	Hyiedefs::TIEProgressEvent fOnProgress;
	TIEImageDrawEvent fOnBeforeImageDraw;
	TIEImageDrawEventEx fOnBeforeImageDrawEx;
	bool fEnableImageCaching;
	Imageenview::TIEVSoftShadow* fSoftShadow;
	int fChessboardSize;
	Graphics::TBrushStyle fChessboardBrushStyle;
	Graphics::TColor fGradientEndColor;
	bool fShowText;
	int fSetUpperGap;
	int fSetBottomGap;
	bool fFlatScrollBars;
	Hyieutils::TIEBitmap* fThumbnailFrame;
	Hyieutils::TIEBitmap* fThumbnailFrameSelected;
	Windows::TRect fThumbnailFrameRect;
	bool fDragging;
	Classes::TList* fMultiOnDemands;
	int fMaintainInvisibleImages;
	int fLookAhead;
	Classes::TNotifyEvent fOnAllDisplayed;
	bool fAllDisplayed;
	bool fUserAction;
	void __fastcall GetMaxViewXY(int &mx, int &my);
	void __fastcall SetViewX(int v);
	void __fastcall SetViewY(int v);
	int __fastcall GetImageX(int idx);
	int __fastcall GetImageY(int idx);
	int __fastcall GetImageCol(int idx);
	int __fastcall GetImageRow(int idx);
	void __fastcall SetThumbWidth(int v);
	void __fastcall SetThumbHeight(int v);
	int __fastcall GetImageCount(void);
	void __fastcall SetImageFileName(int idx, AnsiString v);
	AnsiString __fastcall GetImageFileName(int idx);
	void __fastcall SetImageID(int idx, int v);
	int __fastcall GetImageID(int idx);
	void __fastcall SetHorizBorder(int v);
	void __fastcall SetVertBorder(int v);
	bool __fastcall DeleteImageNU(int idx);
	void __fastcall SetVisibleSelection(bool v);
	void __fastcall SetSelectionWidth(int v);
	void __fastcall SetSelectionWidthNoFocus(int v);
	void __fastcall SetSelectionColor(Graphics::TColor v);
	void __fastcall SetSelectedItem(int v);
	void __fastcall SetBottomGap(int v);
	void __fastcall SetUpperGap(int v);
	void __fastcall SetImageBackground(int idx, Graphics::TColor v);
	Graphics::TColor __fastcall GetImageBackground(int idx);
	void __fastcall SetImageDelayTime(int idx, int v);
	int __fastcall GetImageDelayTime(int idx);
	bool __fastcall ObtainImageNow(int idx);
	bool __fastcall ObtainImageThreaded(int idx);
	void __fastcall SetDisplayMode(TIEMDisplayMode v);
	void __fastcall SetGridWidth(int v);
	void __fastcall SetPlaying(bool v);
	void __fastcall PlayFrame(void);
	void __fastcall SetSelectedItemNU(int v);
	void __fastcall DeselectNU(void);
	void __fastcall SetVisibleFrame(int v);
	TIEMMouseInteract __fastcall GetMouseInteract(void);
	TIEMKeyInteract __fastcall GetKeyInteract(void);
	void __fastcall SetRemoveCorrupted(bool v);
	void __fastcall SetDrawImageBackground(bool v);
	bool __fastcall GetScrollBarsAlwaysVisible(void);
	void __fastcall SetScrollBarsAlwaysVisible(bool v);
	void __fastcall SetImageCacheSize(int v);
	bool __fastcall GetTransitionRunning(void);
	TIEMText* __fastcall GetImageTopText(int idx);
	TIEMText* __fastcall GetImageBottomText(int idx);
	TIEMText* __fastcall GetImageInfoText(int idx);
	void __fastcall SetStyle(TIEMStyle value);
	void __fastcall SetSelectionStyle(TIESStyle value);
	void __fastcall SetEnableMultiSelect(bool Value);
	int __fastcall GetMultiSelectedImages(int index);
	int __fastcall GetMultiSelectedImagesCount(void);
	void __fastcall SetThumbnailsBorderWidth(int Value);
	void __fastcall SetThumbnailsBorderColor(Graphics::TColor Value);
	void __fastcall SetThumbnailsInternalBorder(bool Value);
	void __fastcall SetThumbnailsInternalBorderColor(Graphics::TColor Value);
	void __fastcall SetEnableResamplingOnMinor(bool Value);
	void __fastcall DrawImage(Graphics::TBitmap* DestBitmap, PIEImageInfo info, bool IsSelected, int Index
		);
	void __fastcall ThreadFinish(System::TObject* Sender);
	int __fastcall GetImageBitCount(int idx);
	int __fastcall GetMaximumViewX(void);
	int __fastcall GetMaximumViewY(void);
	void __fastcall SetEnableImageCaching(bool v);
	bool __fastcall SetImageFromStreamOrFile(int idx, Classes::TStream* Stream, const AnsiString FileName
		);
	void __fastcall SetEnableAlphaChannel(bool v);
	void __fastcall SetBackgroundStyle(Imageenview::TIEBackgroundStyle v);
	void __fastcall SetThumbnailsBackgroundStyle(Imageenview::TIEBackgroundStyle v);
	void __fastcall SetGradientEndColor(Graphics::TColor Value);
	void __fastcall SetFillThumbnail(bool Value);
	void __fastcall SetShowText(bool Value);
	void __fastcall SetFlatScrollBars(bool Value);
	int __fastcall GetJobsRunning(void);
	int __fastcall GetJobsWaiting(void);
	int __fastcall SortCompareFunction(int index1, int index2);
	Imageenio::TImageEnIO* __fastcall GetOnDemandIO(const AnsiString filename, int &FrameIndex);
	void __fastcall ClearOnDemandIOList(void);
	void __fastcall LoadMultiOnDemand(Imageenio::TImageEnIO* io, int frameindex, int &dt);
	bool __fastcall IsOnDemand(PIEImageInfo info);
	bool __fastcall IsLookAhead(int idx);
	
protected:
	Iemio::TImageEnMIO* fImageEnMIO;
	Imageenproc::TImageEnProc* fImageEnProc;
	Classes::TList* fMultiSelectedImages;
	virtual Iemio::TImageEnMIO* __fastcall GetImageEnMIO(void);
	virtual Imageenproc::TImageEnProc* __fastcall GetImageEnProc(void);
	virtual void __fastcall SetScrollBars(Stdctrls::TScrollStyle v);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMHScroll(Messages::TMessage &Message);
	MESSAGE void __fastcall WMTimer(Messages::TWMTimer &Message);
	MESSAGE void __fastcall CMWantSpecialKey(Messages::TWMKey &Msg);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Msg);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Msg);
	HIDESBASE MESSAGE void __fastcall WMMouseWheel(Messages::TMessage &Message);
	virtual void __fastcall ViewChange(int c);
	DYNAMIC bool __fastcall PaletteChanged(bool Foreground);
	virtual void __fastcall SetBackGround(Graphics::TColor cl);
	virtual Graphics::TBitmap* __fastcall GetFBitmap(void);
	virtual Hyieutils::TIEBitmap* __fastcall GetIEBitmap(void);
	virtual void __fastcall SetMouseInteract(TIEMMouseInteract v);
	virtual void __fastcall SetKeyInteract(TIEMKeyInteract v);
	int __fastcall GetImageWidth(int idx);
	int __fastcall GetImageHeight(int idx);
	int __fastcall GetImageOriginalWidth(int idx);
	int __fastcall GetImageOriginalHeight(int idx);
	void __fastcall SetImageOriginalWidth(int idx, int Value);
	void __fastcall SetImageOriginalHeight(int idx, int Value);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	void __fastcall SelectAtPos(int X, int Y, Classes::TShiftState Shift);
	void __fastcall SetWallPaper(Graphics::TPicture* Value);
	void __fastcall SetWallPaperStyle(Imageenview::TIEWallPaperStyle Value);
	virtual bool __fastcall GetHasAlphaChannel(void);
	virtual Hyieutils::TIEBitmap* __fastcall GetAlphaChannel(void);
	virtual void __fastcall SetOnProgress(Hyiedefs::TIEProgressEvent v);
	virtual Hyiedefs::TIEProgressEvent __fastcall GetOnProgress(void);
	virtual void __fastcall ClearThreadsAndRequests(void);
	void __fastcall ClearCache(void);
	virtual void __fastcall DoWrongImage(Hyieutils::TIEBitmap* OutBitmap, int idx);
	virtual void __fastcall DoImageSelect(int idx);
	virtual void __fastcall DoImageDeselect(int idx);
	void __fastcall SwapImages(int idx1, int idx2);
	
public:
	__fastcall virtual TImageEnMView(Classes::TComponent* Owner);
	__fastcall virtual ~TImageEnMView(void);
	virtual void __fastcall Update(void);
	void __fastcall UpdateEx(bool UpdateCache);
	HIDESBASE virtual void __fastcall PaintTo(Graphics::TBitmap* DestBitmap);
	virtual void __fastcall Paint(void);
	__property ClientWidth ;
	__property ClientHeight ;
	__property int ViewX = {read=fViewX, write=SetViewX, nodefault};
	__property int ViewY = {read=fViewY, write=SetViewY, nodefault};
	__property int MaximumViewX = {read=GetMaximumViewX, nodefault};
	__property int MaximumViewY = {read=GetMaximumViewY, nodefault};
	void __fastcall SetViewXY(int x, int y);
	void __fastcall CenterSelected(void);
	void __fastcall CenterFrame(void);
	virtual void __fastcall LockPaint(void);
	virtual int __fastcall UnLockPaint(void);
	virtual int __fastcall NPUnLockPaint(void);
	__property int LockPaintCount = {read=fLockPaint, nodefault};
	__property Imageenview::TIEVSoftShadow* SoftShadow = {read=fSoftShadow};
	void __fastcall SetChessboardStyle(int Size, Graphics::TBrushStyle BrushStyle);
	__property Graphics::TColor GradientEndColor = {read=fGradientEndColor, write=SetGradientEndColor, 
		nodefault};
	__property bool FillThumbnail = {read=fFillThumbnail, write=SetFillThumbnail, nodefault};
	__property int ThumbsRounded = {read=fThumbsRounded, write=fThumbsRounded, nodefault};
	void __fastcall SetPresetThumbnailFrame(int PresetIndex, Graphics::TColor UnSelectedColor, Graphics::TColor 
		SelectedColor);
	__property Hyieutils::TIEBitmap* ThumbnailFrame = {read=fThumbnailFrame, write=fThumbnailFrame};
	__property Hyieutils::TIEBitmap* ThumbnailFrameSelected = {read=fThumbnailFrameSelected, write=fThumbnailFrameSelected
		};
	__property Windows::TRect ThumbnailFrameRect = {read=fThumbnailFrameRect, write=fThumbnailFrameRect
		};
	__property MouseCapture ;
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	int __fastcall GetLastOp(void);
	int __fastcall GetLastOpIdx(void);
	int __fastcall GetLastOpP1(void);
	__property bool ScrollBarsAlwaysVisible = {read=GetScrollBarsAlwaysVisible, write=SetScrollBarsAlwaysVisible
		, default=0};
	__property Hyieutils::TIEScrollBarParams* VScrollBarParams = {read=fVScrollBarParams};
	__property Hyieutils::TIEScrollBarParams* HScrollBarParams = {read=fHScrollBarParams};
	virtual void __fastcall RemoveAlphaChannel(bool Merge);
	virtual void __fastcall CallBitmapChangeEvents(void);
	void __fastcall FillFromDirectory(const AnsiString Directory);
	__property bool EnableAdjustOrientation = {read=fEnableAdjustOrientation, write=fEnableAdjustOrientation
		, nodefault};
	__property int MaintainInvisibleImages = {read=fMaintainInvisibleImages, write=fMaintainInvisibleImages
		, nodefault};
	void __fastcall LoadFromFileOnDemand(const AnsiString FileName);
	__property bool EnableLoadEXIFThumbnails = {read=fEnableLoadEXIFThumbnails, write=fEnableLoadEXIFThumbnails
		, nodefault};
	void __fastcall CreateMorphingSequence(Ievect::TImageEnVect* Source, Ievect::TImageEnVect* Target, 
		int FramesCount);
	__property int JobsRunning = {read=GetJobsRunning, nodefault};
	__property int JobsWaiting = {read=GetJobsWaiting, nodefault};
	__property int LookAhead = {read=fLookAhead, write=fLookAhead, nodefault};
	void __fastcall ClearImageCache(int idx);
	__property bool EnableImageCaching = {read=fEnableImageCaching, write=SetEnableImageCaching, default=1
		};
	__property int ImageWidth[int idx] = {read=GetImageWidth};
	__property int ImageHeight[int idx] = {read=GetImageHeight};
	__property int ImageOriginalWidth[int idx] = {read=GetImageOriginalWidth, write=SetImageOriginalWidth
		};
	__property int ImageOriginalHeight[int idx] = {read=GetImageOriginalHeight, write=SetImageOriginalHeight
		};
	__property int ImageBitCount[int idx] = {read=GetImageBitCount};
	__property int ImageX[int idx] = {read=GetImageX};
	__property int ImageY[int idx] = {read=GetImageY};
	__property int ImageRow[int idx] = {read=GetImageRow};
	__property int ImageCol[int idx] = {read=GetImageCol};
	__property AnsiString ImageFileName[int idx] = {read=GetImageFileName, write=SetImageFileName};
	__property int ImageID[int idx] = {read=GetImageID, write=SetImageID};
	__property Graphics::TColor ImageBackground[int idx] = {read=GetImageBackground, write=SetImageBackground
		};
	__property int ImageDelayTime[int idx] = {read=GetImageDelayTime, write=SetImageDelayTime};
	__property TIEMText* ImageTopText[int idx] = {read=GetImageTopText};
	__property TIEMText* ImageBottomText[int idx] = {read=GetImageBottomText};
	__property TIEMText* ImageInfoText[int idx] = {read=GetImageInfoText};
	__property bool ShowText = {read=fShowText, write=SetShowText, nodefault};
	void __fastcall UpdateImage(int idx);
	void __fastcall InsertImage(int idx);
	void __fastcall InsertImageEx(int idx);
	void __fastcall MoveImage(int idx, int destination);
	void __fastcall Sort(TIEImageEnMViewSortCompare Compare);
	int __fastcall AppendImage(void);
	int __fastcall AppendImage2(int Width, int Height, Hyieutils::TIEPixelFormat PixelFormat);
	void __fastcall DeleteImage(int idx);
	void __fastcall DeleteSelectedImages(void);
	__property int ImageCount = {read=GetImageCount, nodefault};
	void __fastcall UpdateCoords(void);
	void __fastcall SetImage(int idx, Graphics::TBitmap* v);
	void __fastcall SetImageEx(int idx, Graphics::TBitmap* v);
	void __fastcall SetIEBitmapEx(int idx, Hyieutils::TIEBaseBitmap* v);
	void __fastcall SetIEBitmap(int idx, Hyieutils::TIEBaseBitmap* v);
	bool __fastcall SetImageFromFile(int idx, const AnsiString FileName);
	bool __fastcall SetImageFromStream(int idx, Classes::TStream* Stream);
	void __fastcall SetImageRect(int idx, Graphics::TBitmap* v, int x1, int y1, int x2, int y2);
	void __fastcall Clear(void);
	Graphics::TBitmap* __fastcall GetBitmap(int idx);
	void __fastcall ReleaseBitmap(int idx);
	Hyieutils::TIEBitmap* __fastcall GetTIEBitmap(int idx);
	int __fastcall GetImageVisibility(int idx);
	int __fastcall ImageAtPos(int x, int y);
	int __fastcall ImageAtGridPos(int row, int col);
	int __fastcall InsertingPoint(int x, int y);
	__property Hyiedefs::TResampleFilter ThumbnailResampleFilter = {read=fThumbnailResampleFilter, write=
		fThumbnailResampleFilter, nodefault};
	__property Hyiedefs::TResampleFilter ThumbnailDisplayFilter = {read=fThumbnailDisplayFilter, write=
		fThumbnailDisplayFilter, nodefault};
	__property bool EnableResamplingOnMinor = {read=fEnableResamplingOnMinor, write=SetEnableResamplingOnMinor
		, nodefault};
	void __fastcall CopyToIEBitmap(int idx, Hyieutils::TIEBitmap* bmp);
	bool __fastcall IsVisible(int idx);
	void __fastcall ReloadImage(int imageIndex);
	void __fastcall PrepareSpaceFor(int Width, int Height, int Bitcount, int ImageCount);
	__property int SelectedImage = {read=fSelectedItem, write=SetSelectedItem, nodefault};
	void __fastcall Deselect(void);
	void __fastcall SelectSeek(TIESeek pos);
	__property bool MultiSelecting = {read=fMultiSelecting, write=fMultiSelecting, nodefault};
	__property int MultiSelectedImages[int index] = {read=GetMultiSelectedImages};
	__property int MultiSelectedImagesCount = {read=GetMultiSelectedImagesCount, nodefault};
	void __fastcall MultiSelectSortList(void);
	void __fastcall UnSelectImage(int idx);
	void __fastcall SelectAll(void);
	void __fastcall BeginSelectImages(void);
	void __fastcall EndSelectImages(void);
	bool __fastcall IsSelected(int idx);
	__property bool Playing = {read=fPlaying, write=SetPlaying, nodefault};
	__property bool PlayLoop = {read=fPlayLoop, write=fPlayLoop, nodefault};
	__property int VisibleFrame = {read=fFrame, write=SetVisibleFrame, nodefault};
	__property bool TransitionRunning = {read=GetTransitionRunning, nodefault};
	__property Iemio::TImageEnMIO* MIO = {read=GetImageEnMIO};
	__property Imageenproc::TImageEnProc* Proc = {read=GetImageEnProc};
	void __fastcall IEBeginDrag(bool Immediate, int Threshold);
	void __fastcall IEEndDrag(void);
	__property int SelectionWidthNoFocus = {read=fSelectionWidthNoFocus, write=SetSelectionWidthNoFocus
		, nodefault};
	
__published:
	__property Stdctrls::TScrollStyle ScrollBars = {read=fScrollBars, write=SetScrollBars, default=3};
	__property TIEStoreType StoreType = {read=fStoreType, write=fStoreType, default=0};
	__property int ThumbWidth = {read=fThumbWidth, write=SetThumbWidth, default=100};
	__property int ThumbHeight = {read=fThumbHeight, write=SetThumbHeight, default=100};
	__property int HorizBorder = {read=fHorizBorder, write=SetHorizBorder, default=4};
	__property int VertBorder = {read=fVertBorder, write=SetVertBorder, default=4};
	__property int BottomGap = {read=fBottomGap, write=SetBottomGap, default=0};
	__property int UpperGap = {read=fUpperGap, write=SetUpperGap, default=0};
	__property Imageenview::TViewChangeEvent OnViewChange = {read=fOnViewChange, write=fOnViewChange};
	__property TIEImageIDRequestEvent OnImageIDRequest = {read=fOnImageIDRequest, write=fOnImageIDRequest
		};
	__property TIEImageIDRequestExEvent OnImageIDRequestEx = {read=fOnImageIDRequestEx, write=fOnImageIDRequestEx
		};
	__property TIEImageDrawEvent OnBeforeImageDraw = {read=fOnBeforeImageDraw, write=fOnBeforeImageDraw
		};
	__property TIEImageDrawEventEx OnBeforeImageDrawEx = {read=fOnBeforeImageDrawEx, write=fOnBeforeImageDrawEx
		};
	__property TIEImageDrawEvent OnImageDraw = {read=fOnImageDraw, write=fOnImageDraw};
	__property TIEImageSelectEvent OnImageSelect = {read=fOnImageSelect, write=fOnImageSelect};
	__property TIEImageSelectEvent OnImageDeselect = {read=fOnImageDeselect, write=fOnImageDeselect};
	__property Hyiedefs::TIEProgressEvent OnIOProgress = {read=fOnIOProgress, write=fOnIOProgress};
	__property TIEMProgressEvent OnDrawProgress = {read=fOnDrawProgress, write=fOnDrawProgress};
	__property TIEWrongImageEvent OnWrongImage = {read=fOnWrongImage, write=fOnWrongImage};
	__property bool VisibleSelection = {read=fVisibleSelection, write=SetVisibleSelection, default=1};
	__property TIEMMouseInteract MouseInteract = {read=GetMouseInteract, write=SetMouseInteract, default=2
		};
	__property TIEMKeyInteract KeyInteract = {read=GetKeyInteract, write=SetKeyInteract, default=1};
	__property TIEMDisplayMode DisplayMode = {read=fDisplayMode, write=SetDisplayMode, default=0};
	__property int GridWidth = {read=fGridWidth, write=SetGridWidth, default=0};
	__property int SelectionWidth = {read=fSelectionWidth, write=SetSelectionWidth, nodefault};
	__property Graphics::TColor SelectionColor = {read=fSelectionColor, write=SetSelectionColor, nodefault
		};
	__property bool RemoveCorrupted = {read=fRemoveCorrupted, write=SetRemoveCorrupted, default=0};
	__property bool DrawImageBackground = {read=fDrawImageBackground, write=SetDrawImageBackground, default=0
		};
	__property int ImageCacheSize = {read=fImageCacheSize, write=SetImageCacheSize, default=10};
	__property Imageenproc::TIETransitionType TransitionEffect = {read=fTransitionEffect, write=fTransitionEffect
		, default=0};
	__property int TransitionDuration = {read=fTransitionDuration, write=fTransitionDuration, default=1000
		};
	__property TIEMStyle Style = {read=fStyle, write=SetStyle, default=1};
	__property TIESStyle SelectionStyle = {read=fSelectionStyle, write=SetSelectionStyle, default=0};
	__property Graphics::TColor ThumbnailsBackground = {read=fThumbnailsBackground, write=fThumbnailsBackground
		, default=-2147483633};
	__property bool EnableMultiSelect = {read=fEnableMultiSelect, write=SetEnableMultiSelect, default=0
		};
	__property TIEMultiSelectionOptions MultiSelectionOptions = {read=fMultiSelectionOptions, write=fMultiSelectionOptions
		, default=0};
	__property int ThumbnailsBorderWidth = {read=fThumbnailsBorderWidth, write=SetThumbnailsBorderWidth
		, default=0};
	__property Graphics::TColor ThumbnailsBorderColor = {read=fThumbnailsBorderColor, write=SetThumbnailsBorderColor
		, default=-2147483633};
	__property bool ThumbnailsInternalBorder = {read=fThumbnailsInternalBorder, write=SetThumbnailsInternalBorder
		, default=0};
	__property Graphics::TColor ThumbnailsInternalBorderColor = {read=fThumbnailsInternalBorderColor, write=
		SetThumbnailsInternalBorderColor, default=0};
	__property Graphics::TPicture* WallPaper = {read=fWallPaper, write=SetWallPaper};
	__property Imageenview::TIEWallPaperStyle WallPaperStyle = {read=fWallPaperStyle, write=SetWallPaperStyle
		, default=0};
	__property Hyiedefs::TIEProgressEvent OnProgress = {read=GetOnProgress, write=SetOnProgress};
	__property int ThreadPoolSize = {read=fThreadPoolSize, write=fThreadPoolSize, default=5};
	__property bool EnableAlphaChannel = {read=fEnableAlphaChannel, write=SetEnableAlphaChannel, default=1
		};
	__property Imageenview::TIEBackgroundStyle BackgroundStyle = {read=fBackgroundStyle, write=SetBackgroundStyle
		, default=0};
	__property Imageenview::TIEBackgroundStyle ThumbnailsBackgroundStyle = {read=fThumbnailsBackgroundStyle
		, write=SetThumbnailsBackgroundStyle, default=0};
	__property Classes::TNotifyEvent OnAllDisplayed = {read=fOnAllDisplayed, write=fOnAllDisplayed};
	__property bool FlatScrollBars = {read=fFlatScrollBars, write=SetFlatScrollBars, default=0};
	__property Anchors ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property Align ;
	__property DragCursor ;
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
	/* TWinControl.CreateParented */ inline __fastcall TImageEnMView(HWND ParentWindow) : Ieview::TIEView(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TIEStarter : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
public:
	TImageEnMView* mview;
	virtual void __fastcall Execute(void);
public:
	#pragma option push -w-inl
	/* TThread.Create */ inline __fastcall TIEStarter(bool CreateSuspended) : Classes::TThread(CreateSuspended
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TThread.Destroy */ inline __fastcall virtual ~TIEStarter(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iemview */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Iemview;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// iemview
