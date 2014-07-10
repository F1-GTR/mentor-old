// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ievect.pas' rev: 5.00

#ifndef ievectHPP
#define ievectHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ieview.hpp>	// Pascal unit
#include <ietextc.hpp>	// Pascal unit
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

namespace Ievect
{
//-- type declarations -------------------------------------------------------
typedef AnsiString ievect__1[8];

class DELPHICLASS TIEMemoEditCharInfo;
class PASCALIMPLEMENTATION TIEMemoEditCharInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Graphics::TFont* Font;
	Imageenview::TIEAlignment Align;
	__fastcall TIEMemoEditCharInfo(void);
	__fastcall virtual ~TIEMemoEditCharInfo(void);
};


#pragma option push -b-
enum TIERotateCenter { ierObject, ierImage };
#pragma option pop

#pragma option push -b-
enum TIECurve { iecNone, iecEllipse, iecCosine, iecVertical, iecHorizontal, iecArc };
#pragma option pop

struct TDPoint
{
	double X;
	double y;
} ;

typedef TDPoint TDPointArray[67108864];

typedef TDPoint *PDPointArray;

#pragma option push -b-
enum TIEVObjectKind { iekNONE, iekLINE, iekBOX, iekELLIPSE, iekARC, iekBITMAP, iekTEXT, iekRULER, iekPOLYLINE, 
	iekANGLE, iekMEMO, iekLINELABEL };
#pragma option pop

#pragma option push -b-
enum TIEShape { iesNONE, iesINARROW, iesOUTARROW };
#pragma option pop

#pragma option push -b-
enum TIEVRulerType { iertRULER, iertQUOTEBEGIN, iertQUOTECENTER, iertQUOTEEND };
#pragma option pop

struct TIEVBitmap
{
	Hyieutils::TIEBitmap* fBitmap;
	int fRefCount;
} ;

typedef TIEVBitmap *PIEVBitmap;

typedef TIEVBitmap TIEVBitmapArray[16777216];

typedef TIEVBitmap *PIEVBitmapArray;

#pragma option push -b-
enum ievect__3 { ievsSelectable, ievsMoveable, ievsSizeable, ievsVisible };
#pragma option pop

typedef Set<ievect__3, ievsSelectable, ievsVisible>  TIEVStyle;

struct TIEVObject;
typedef TIEVObject *PIEVObject;

#pragma option push -b-
enum TIEUnits { ieuPIXELS, ieuINCHES, ieuKM, ieuMETERS, ieuCENTIMETERS, ieuMILLIMETERS, ieuMICRONS, 
	ieuNANOMETERS };
#pragma option pop

#pragma option push -b-
enum TIELabelPos { ielBegin, ielEnd };
#pragma option pop

struct TIEVObject
{
	int x1;
	int y1;
	int x2;
	int y2;
	TIEVObjectKind Kind;
	int Transparency;
	TIEShape BeginShape;
	TIEShape EndShape;
	int ShapeWidth;
	int ShapeHeight;
	Graphics::TColor LabelBrushColor;
	Graphics::TBrushStyle LabelBrushStyle;
	TIELabelPos LabelPosition;
	Graphics::TColor PenColor;
	Graphics::TPenStyle PenStyle;
	int PenWidth;
	Graphics::TColor BrushColor;
	Graphics::TBrushStyle BrushStyle;
	bool BoxHighlight;
	double a1;
	double a2;
	int BitmapIdx;
	bool BitmapBorder;
	char *Text;
	tagLOGFONTA *LogFont;
	Imageenview::TIEAlignment TextAlign;
	bool TextAutoSize;
	bool FontLocked;
	TDPoint *CurvedPos;
	int CurvedLen;
	int CurvedCharRot;
	int *TextFormatRef;
	Classes::TList* TextFormat;
	int LineSpace;
	Graphics::TColor MemoBorderColor;
	Graphics::TPenStyle MemoBorderStyle;
	int MemoFixedHeight;
	char *Name;
	int ID;
	TIEVStyle Style;
	TIEUnits RulerUnit;
	TIEVRulerType RulerType;
	void *PolyPoints;
	int PolyPointsCount;
	int PolyBaseX1;
	int PolyBaseY1;
	int PolyBaseX2;
	int PolyBaseY2;
	bool PolyClosed;
	void *DrawnPoints;
	int DrawnPointsCount;
	Windows::TPoint AnglePoints[3];
	int lx1;
	int ly1;
	int lx2;
	int ly2;
	Windows::TRect plim;
	int pwidth;
	Imageenview::TIEVSoftShadow* softShadow;
} ;

typedef TIEVObject TIEVObjectArray[8388608];

typedef TIEVObject *PIEVObjectArray;

#pragma option push -b-
enum TIEMouseInteractVtItems { miArea, miLineLen, miPutLine, miPutBox, miPutEllipse, miPutBitmap, miPutText, 
	miObjectSelect, miDragLen, miPutRuler, miPutPolyLine, miPutAngle, miPutMemo, miPutLineLabel, miEditPolyline, 
	miUnStampMode };
#pragma option pop

typedef Set<TIEMouseInteractVtItems, miArea, miUnStampMode>  TIEMouseInteractVt;

typedef void __fastcall (__closure *TIEVMeasureHintEvent)(System::TObject* Sender, AnsiString &Text, 
	double Value);

typedef void __fastcall (__closure *TIEVDragLenEndEvent)(System::TObject* Sender, double Value);

typedef void __fastcall (__closure *TIEVNewObject)(System::TObject* Sender, int hobj);

typedef void __fastcall (__closure *TIEVObjectMoveResizeEvent)(System::TObject* Sender, int hobj, int 
	Grip, int &OffsetX, int &OffsetY);

typedef void __fastcall (__closure *TIEVObjectClickEvent)(System::TObject* Sender, int hobj);

typedef void __fastcall (__closure *TIESelectObjectEvent)(System::TObject* Sender, int hobj);

class DELPHICLASS TImageEnVect;
class PASCALIMPLEMENTATION TImageEnVect : public Imageenview::TImageEnView 
{
	typedef Imageenview::TImageEnView inherited;
	
private:
	Hyieutils::TIEBitmap* fCacheBitmap;
	TIEMouseInteractVt fMouseInteractVt;
	double fScale;
	TIEUnits fMUnit;
	double fCoefX;
	double fCoefY;
	int fFloatPrecision;
	int fFloatDigits;
	bool fMeasureTrack;
	int fVMoveX;
	int fVMoveY;
	Classes::TNotifyEvent fOnSelectObject;
	TIEVMeasureHintEvent fOnMeasureHint;
	TIEVDragLenEndEvent fOnDragLenEnd;
	bool fZoomObjectsWidth;
	Classes::TNotifyEvent fOnVectorialChanged;
	Classes::TNotifyEvent fOnBeforeVectorialChanged;
	double fLastHintValue;
	int fMaxSelectionDistance;
	int flx;
	int fly;
	Graphics::TBitmap* fHintSaveBitmap;
	bool fShowHint;
	int fHintX;
	int fHintY;
	int fMovX;
	int fMovY;
	Graphics::TFont* fMeasureHintFont;
	Graphics::TBrush* fMeasureHintBrush;
	Graphics::TColor fMeasureHintBorder1;
	Graphics::TColor fMeasureHintBorder2;
	int fGripSize;
	Graphics::TPen* fGripPen;
	Graphics::TBrush* fGripBrush;
	TIEVObject *fMemoWriteFormattedString;
	AnsiString fMemoFormattedString;
	bool fUseCentralGrip;
	int fCurPolylineGrip;
	int fCurPolylineIntraGrip;
	bool fSelectOnMouseDown;
	bool fSelectOnMouseDown_WasSelected;
	bool fDoubleClicking;
	bool fVectorialChanged;
	int fObjCount;
	int *fObj;
	bool fVectorialChanging;
	TIEVObjectKind fInserting;
	int fInsertingPolylineObject;
	int fInsertingPolylineLastX;
	int fInsertingPolylineLastY;
	int fInsertingAngleObject;
	TIEVObject fNewObj;
	int *fSelObj;
	int fSelObjCount;
	int fGripping;
	int fTextEditing;
	Ietextc::TIEEdit* fTextEdit;
	Ietextc::TIETextControl* fMemoEdit;
	bool fObjAntialias;
	TIEVObject *fObjHeap;
	int fObjHeapCount;
	TIEVBitmap *fBitmaps;
	int fBitmapsCount;
	bool fShareBitmaps;
	bool fAllObjectsHidden;
	TIEVNewObject fOnNewObject;
	Hyiedefs::TResampleFilter fBitmapResampleFilter;
	TIEVObjectMoveResizeEvent fOnObjectMoveResize;
	TIEVObjectClickEvent fOnObjectClick;
	TIEVObjectClickEvent fOnObjectDblClick;
	TIEVObjectClickEvent fOnObjectOver;
	Controls::TKeyEvent fOnTextKeyDown;
	int fObjDrawed;
	bool fObjGraphicRender;
	bool fCenterNewObjects;
	Classes::TNotifyEvent fOnActivateTextEdit;
	Classes::TNotifyEvent fOnDeactivateTextEdit;
	bool fAllowOutOfBitmapMoving;
	bool fEnableRangeObjectsSelection;
	bool fObjEditOnNewText;
	Classes::TList* fObjUndoList;
	int fObjUndoLimit;
	bool fObjAutoUndo;
	void __fastcall HintRestore(void);
	void __fastcall HintShow(int x, int y);
	void __fastcall SetAllObjectsHidden(bool Value);
	void __fastcall TextEditKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall TextEditOnChange(System::TObject* Sender);
	void __fastcall MemoEditKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall CalcCoef(double &cx, double &cy, TIEUnits mu);
	void __fastcall DrawLineInserting(void);
	void __fastcall DrawBoxInserting(void);
	void __fastcall DrawEllipseInserting(void);
	void __fastcall DrawRulerInserting(void);
	void __fastcall DrawAngleInserting(void);
	void __fastcall DrawRuler(Graphics::TCanvas* wcanvas, int x1, int y1, int x2, int y2, TIEUnits um, 
		Graphics::TColor Color, int PW, TIEVRulerType RulerType, double zx, double zy, Windows::TRect &plim
		, Windows::PLogFontA logfont);
	void __fastcall DrawAngle(Graphics::TCanvas* wcanvas, const Windows::TPoint * AnglePoints, const int 
		AnglePoints_Size, Graphics::TColor Color, int PW, Windows::TRect &plim, bool usezoom, int mul, double 
		zx, double zy);
	void __fastcall RemoveVObjData(TIEVObject &obj);
	void __fastcall RemoveMemoTextData(TIEVObject &obj);
	void __fastcall RemoveVObjDataAll(void);
	int __fastcall AddVObject(const TIEVObject &aObj);
	void __fastcall RemoveVObject(int hobj);
	PIEVObject __fastcall GetObj(int hobj);
	bool __fastcall DrawObject(TIEVObject &aobj, int hobj, Graphics::TBitmap* BBitmap, bool CheckLimits
		, bool UseZoom, Hyieutils::TIEBitmap* DrawOnTIEBitmap, int mul, bool drawingalpha);
	void __fastcall DrawObjectAll(Hyieutils::TIEBitmap* BackGroundBitmap, bool re, Graphics::TBitmap* BBitmap
		, bool antialias, int OnlyThis);
	void __fastcall DrawObjectText(Graphics::TCanvas* wcanvas, int x1, int y1, int x2, int y2, TIEVObject 
		&aobj, int hobj, double zx, double zy, bool drawingalpha, Windows::TRect &plim);
	void __fastcall DrawObjectLineLabel(Graphics::TCanvas* wcanvas, int lx1, int ly1, int lx2, int ly2, 
		const TIEVObject &aobj, double zx, double zy, Windows::TRect &plim);
	void __fastcall DrawObjectGrips(Graphics::TCanvas* Canvas, const TIEVObject &aobj);
	int __fastcall FindNearObj(int x, int y, double &ds, bool mustbeselectable);
	int __fastcall FindPolylineIntraPoint(int x, int y);
	double __fastcall CalcDistPtObj(PIEVObject Obj, int x, int y);
	void __fastcall DrawSelGrips(Graphics::TCanvas* Canvas);
	int __fastcall FindSelGrip(int x, int y, int &gr);
	void __fastcall TraslateObject(int o, int ox, int oy);
	void __fastcall ChangeObjectCoor(int o, int ox1, int oy1, int ox2, int oy2, bool AspectRatio, int grip
		);
	void __fastcall SelInRect(int aobj, int xx1, int yy1, int xx2, int yy2);
	void __fastcall DrawLineShape(const TIEVObject &aobj, Graphics::TCanvas* Canvas, int x1, int y1, int 
		x2, int y2, TIEShape Shape, int w, int h, Windows::TRect &plim);
	void __fastcall AddSelObjectNS(int hobj);
	void __fastcall ActivateTextEdit(void);
	void __fastcall RemoveTextEdit(void);
	void __fastcall SaveObj(Classes::TStream* Stream, int hobj);
	int __fastcall ReadObj(Classes::TStream* Stream, Byte ver, bool LoadBitmapIdx);
	void __fastcall CalcZxZyPolyline(PIEVObject Obj, double &zx, double &zy);
	TIEVObjectKind __fastcall GetObjKind(int hobj);
	void __fastcall SetObjKind(int hobj, TIEVObjectKind v);
	Graphics::TColor __fastcall GetObjPenColor(int hobj);
	void __fastcall SetObjPenColor(int hobj, Graphics::TColor v);
	Graphics::TPenStyle __fastcall GetObjPenStyle(int hobj);
	void __fastcall SetObjPenStyle(int hobj, Graphics::TPenStyle v);
	int __fastcall GetObjPenWidth(int hobj);
	void __fastcall SetObjPenWidth(int hobj, int v);
	Graphics::TColor __fastcall GetObjBrushColor(int hobj);
	void __fastcall SetObjBrushColor(int hobj, Graphics::TColor v);
	Graphics::TBrushStyle __fastcall GetObjBrushStyle(int hobj);
	void __fastcall SetObjBrushStyle(int hobj, Graphics::TBrushStyle v);
	bool __fastcall GetObjBoxHighLight(int hobj);
	void __fastcall SetObjBoxHighLight(int hobj, bool v);
	Hyieutils::TIEBitmap* __fastcall GetObjBitmap(int hobj);
	void __fastcall SetObjBitmap(int hobj, Hyieutils::TIEBitmap* v);
	Hyieutils::TIEBitmap* __fastcall GetObjBitmapAlpha(int hobj);
	void __fastcall SetObjBitmapAlpha(int hobj, Hyieutils::TIEBitmap* v);
	int __fastcall GetSelObjects(int idx);
	void __fastcall SetObjBeginShape(int hobj, TIEShape v);
	TIEShape __fastcall GetObjBeginShape(int hobj);
	void __fastcall SetObjEndShape(int hobj, TIEShape v);
	TIEShape __fastcall GetObjEndShape(int hobj);
	void __fastcall SetObjLabelPos(int hobj, TIELabelPos v);
	TIELabelPos __fastcall GetObjLabelPos(int hobj);
	void __fastcall SetObjShapeWidth(int hobj, int v);
	int __fastcall GetObjShapeWidth(int hobj);
	void __fastcall SetObjShapeHeight(int hobj, int v);
	int __fastcall GetObjShapeHeight(int hobj);
	void __fastcall SetObjText(int hobj, AnsiString v);
	AnsiString __fastcall GetObjText(int hobj);
	void __fastcall SetObjName(int hobj, AnsiString v);
	AnsiString __fastcall GetObjName(int hobj);
	void __fastcall SetObjFontAngle(int hobj, double v);
	double __fastcall GetObjFontAngle(int hobj);
	int __fastcall GetObjFontHeight(int hobj);
	void __fastcall SetObjFontHeight(int hobj, int v);
	AnsiString __fastcall GetObjFontName(int hobj);
	void __fastcall SetObjFontName(int hobj, AnsiString v);
	Graphics::TFontStyles __fastcall GetObjFontStyles(int hobj);
	void __fastcall SetObjFontStyles(int hobj, Graphics::TFontStyles v);
	void __fastcall SetObjTextAlign(int hobj, Imageenview::TIEAlignment v);
	Imageenview::TIEAlignment __fastcall GetObjTextAlign(int hobj);
	void __fastcall SetObjTextAutoSize(int hobj, bool v);
	bool __fastcall GetObjTextAutoSize(int hobj);
	void __fastcall SetObjTextCurveCharRot(int hobj, double v);
	double __fastcall GetObjTextCurveCharRot(int hobj);
	void __fastcall SetObjMemoLineSpace(int hobj, int v);
	int __fastcall GetObjMemoLineSpace(int hobj);
	void __fastcall SetObjLeft(int hobj, int v);
	int __fastcall GetObjLeft(int hobj);
	void __fastcall SetObjTop(int hobj, int v);
	int __fastcall GetObjTop(int hobj);
	void __fastcall SetObjWidth(int hobj, int v);
	int __fastcall GetObjWidth(int hobj);
	void __fastcall SetObjHeight(int hobj, int v);
	int __fastcall GetObjHeight(int hobj);
	void __fastcall SetObjRulerUnit(int hobj, TIEUnits v);
	TIEUnits __fastcall GetObjRulerUnit(int hobj);
	void __fastcall SetObjRulerType(int hobj, TIEVRulerType v);
	TIEVRulerType __fastcall GetObjRulerType(int hobj);
	void __fastcall SetObjTransparency(int hobj, int v);
	int __fastcall GetObjTransparency(int hobj);
	void __fastcall SetObjID(int hobj, int v);
	int __fastcall GetObjID(int hobj);
	void __fastcall SetObjStyle(int hobj, TIEVStyle v);
	TIEVStyle __fastcall GetObjStyle(int hobj);
	void __fastcall SetZoomObjectsWidth(bool Value);
	Windows::TRect __fastcall GetObjectsExtents(void);
	Windows::TPoint __fastcall GetObjPolylinePoints(int hobj, int index);
	int __fastcall GetObjPolylinePointsCount(int hobj);
	bool __fastcall GetObjPolylineClosed(int hobj);
	void __fastcall SetObjPolylineClosed(int hobj, bool Value);
	Imageenview::TIEVSoftShadow* __fastcall GetObjSoftShadow(int hobj);
	void __fastcall DrawGrip(Graphics::TCanvas* destcanvas, int x, int y, int ty);
	bool __fastcall InGrip(int xg, int yg, int xp, int yp);
	Graphics::TColor __fastcall GetObjLabelBrushColor(int hobj);
	void __fastcall SetObjLabelBrushColor(int hobj, Graphics::TColor v);
	Graphics::TBrushStyle __fastcall GetObjLabelBrushStyle(int hobj);
	void __fastcall SetObjLabelBrushStyle(int hobj, Graphics::TBrushStyle v);
	bool __fastcall GetObjFontLocked(int hobj);
	void __fastcall SetObjFontLocked(int hobj, bool value);
	Graphics::TColor __fastcall GetObjMemoBorderColor(int hobj);
	void __fastcall SetObjMemoBorderColor(int hobj, Graphics::TColor value);
	Graphics::TPenStyle __fastcall GetObjMemoBorderStyle(int hobj);
	void __fastcall SetObjMemoBorderStyle(int hobj, Graphics::TPenStyle value);
	void __fastcall SetObjMemoFixedHeight(int hobj, int value);
	int __fastcall GetObjMemoFixedHeight(int hobj);
	bool __fastcall GetObjBitmapBorder(int hobj);
	void __fastcall SetObjBitmapBorder(int hobj, bool value);
	double __fastcall GetObjArcStartingAngle(int hobj);
	void __fastcall SetObjArcStartingAngle(int hobj, double v);
	double __fastcall GetObjArcEndingAngle(int hobj);
	void __fastcall SetObjArcEndingAngle(int hobj, double v);
	Hyieutils::TIEBitmap* __fastcall GetBitmap(int idx);
	Hyieutils::TIEBitmap* __fastcall GetBitmapAlpha(int idx);
	void __fastcall FreeBitmap(int idx);
	int __fastcall AllocBitmap(void);
	void __fastcall PackBMP(void);
	int __fastcall FindBitmap(Hyieutils::TIEBitmap* SBitmap);
	void __fastcall SetObjBitmapNU(int hobj, Hyieutils::TIEBitmap* v);
	void __fastcall SetObjBitmapIdxNU(int hobj, int idx);
	void __fastcall SetBitmapResampleFilter(Hyiedefs::TResampleFilter v);
	bool __fastcall GetObjCanUndo(void);
	int __fastcall GetObjUndoCount(void);
	void __fastcall SetObjAntialias(bool value);
	void __fastcall MouseSelect(Classes::TShiftState Shift, int x, int y, bool MouseDown);
	void __fastcall SetObjTextEditMode(int hobj);
	int __fastcall GetObjTextEditMode(void);
	void __fastcall SetOnTextEditCursorMoved(Classes::TNotifyEvent value);
	Classes::TNotifyEvent __fastcall GetOnTextEditCursorMoved(void);
	Windows::TRect __fastcall GetSelectedObjectsRect(void);
	void __fastcall DrawObjectsToBitmapEx(Hyieutils::TIEBitmap* target, bool Antialias, int OnlyThis);
	
protected:
	int fVStable;
	int fObjLockPaint;
	void __fastcall VPaintTo(Graphics::TBitmap* BBitmap);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	virtual void __fastcall SetMouseInteract(Imageenview::TIEMouseInteract v);
	void __fastcall SetMouseInteractVt(TIEMouseInteractVt v);
	HIDESBASE TIEMouseInteractVt __fastcall GetMouseInteract(void);
	void __fastcall SetMUnit(TIEUnits v);
	void __fastcall SetScale(double v);
	void __fastcall SetFloatDigits(int v);
	void __fastcall SetFloatPrecision(int v);
	void __fastcall UpdateHint(int x, int y);
	virtual void __fastcall ViewChange(int c);
	virtual void __fastcall SubMouseMoveScroll(int scx, int scy);
	int __fastcall GetObjPos(int hobj);
	void __fastcall ReInsertVObject(int hobj, int pos);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Msg);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Msg);
	virtual void __fastcall DoVectorialChanged(void);
	virtual void __fastcall UpdateTextEdit(void);
	void __fastcall DrawBitmapObject(Graphics::TBitmap* BBitmap, const TIEVObject &aobj, int x1, int y1
		, int x2, int y2, Hyieutils::TIEBitmap* DrawOnTIEBitmap, int realPenWidth);
	void __fastcall DoObjectMoveResize(int hobj, int Grip, int &OffsetX, int &OffsetY);
	void __fastcall DoObjectClick(int hobj);
	void __fastcall DoObjectDblClick(int hobj);
	void __fastcall DoObjectOver(int hobj);
	void __fastcall AddPolyLinePoint(int hobj, int X, int Y);
	int __fastcall CountAnglePoints(const Windows::TPoint * AnglePoints, const int AnglePoints_Size);
	int __fastcall AdjustCoords(const TIEVObject &aobj, int &x1, int &y1, int &x2, int &y2, int &x3, int 
		&y3, double zx, double zy);
	virtual void __fastcall SetObjGraphicRender(bool Value);
	int __fastcall VXBmp2Scr(int x, bool UseZoom, int mul);
	int __fastcall VYBmp2Scr(int y, bool UseZoom, int mul);
	virtual void __fastcall DoBeforeVectorialChange(void);
	void __fastcall DrawPolylinePoints(Graphics::TCanvas* Canvas);
	int __fastcall FindPolylinePoint(int x, int y);
	void __fastcall RecalcPolylineBox(PIEVObject Obj);
	void __fastcall RotateObjectEx(PIEVObject obj, double angle, double vsin, double vcos, int basex, int 
		basey);
	void __fastcall CalcRotateValues(PIEVObject obj, double angle, TIERotateCenter center, int &basex, 
		int &basey, double &vsin, double &vcos);
	void __fastcall UnSelAllObjectsNU(void);
	void __fastcall AddSelObjectEx(int hobj);
	
public:
	__fastcall virtual TImageEnVect(Classes::TComponent* Owner);
	__fastcall virtual ~TImageEnVect(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PaintToEx(Graphics::TBitmap* ABitmap, Hyiedefs::PPointerArray ABitmapScanline
		, Windows::PRect UpdRect);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Update(void);
	__property TIEMouseInteractVt MouseInteractVt = {read=GetMouseInteract, write=SetMouseInteractVt, default=0
		};
	virtual void __fastcall SetDPIX(int dpiX);
	virtual void __fastcall SetDPIY(int dpiY);
	__property bool ObjGraphicRender = {read=fObjGraphicRender, write=SetObjGraphicRender, nodefault};
	__property bool UseCentralGrip = {read=fUseCentralGrip, write=fUseCentralGrip, nodefault};
	__property int GripSize = {read=fGripSize, write=fGripSize, nodefault};
	__property Graphics::TPen* GripPen = {read=fGripPen};
	__property Graphics::TBrush* GripBrush = {read=fGripBrush};
	__property bool CenterNewObjects = {read=fCenterNewObjects, write=fCenterNewObjects, nodefault};
	double __fastcall GetSelectionArea(void);
	double __fastcall GetSelectionLen(void);
	Windows::TPoint __fastcall GetSelectionCentroid(void);
	double __fastcall GetPolylineLen(int hobj);
	double __fastcall GetPolylineArea(int hobj);
	Windows::TPoint __fastcall GetPolylineCentroid(int hobj);
	__property bool MeasureTrack = {read=fMeasureTrack, write=fMeasureTrack, default=1};
	void __fastcall SetScaleFromPixels(int px, double mm);
	__property double ScaleFactor = {read=fScale, write=SetScale};
	void __fastcall SetScaleFromSelectionLen(double mm);
	__property double MeasureCoefX = {read=fCoefX};
	__property double MeasureCoefY = {read=fCoefY};
	double __fastcall GetObjDiagLen(int hobj);
	virtual void __fastcall AddSelPoint(int x, int y);
	virtual void __fastcall Select(int x1, int y1, int x2, int y2, Imageenview::TIESelOp Op);
	void __fastcall CancelInteracts(void);
	__property int ObjectsCount = {read=fObjCount, nodefault};
	__property Windows::TRect ObjectsExtents = {read=GetObjectsExtents};
	__property TIEVObjectKind ObjKind[int hobj] = {read=GetObjKind, write=SetObjKind};
	__property Graphics::TColor ObjPenColor[int hobj] = {read=GetObjPenColor, write=SetObjPenColor};
	__property Graphics::TPenStyle ObjPenStyle[int hobj] = {read=GetObjPenStyle, write=SetObjPenStyle};
		
	__property int ObjPenWidth[int hobj] = {read=GetObjPenWidth, write=SetObjPenWidth};
	__property Graphics::TColor ObjBrushColor[int hobj] = {read=GetObjBrushColor, write=SetObjBrushColor
		};
	__property Graphics::TBrushStyle ObjBrushStyle[int hobj] = {read=GetObjBrushStyle, write=SetObjBrushStyle
		};
	__property bool ObjBoxHighlight[int hobj] = {read=GetObjBoxHighLight, write=SetObjBoxHighLight};
	__property Graphics::TColor ObjLabelBrushColor[int hobj] = {read=GetObjLabelBrushColor, write=SetObjLabelBrushColor
		};
	__property Graphics::TBrushStyle ObjLabelBrushStyle[int hobj] = {read=GetObjLabelBrushStyle, write=
		SetObjLabelBrushStyle};
	__property Hyieutils::TIEBitmap* ObjBitmap[int hobj] = {read=GetObjBitmap, write=SetObjBitmap};
	__property Hyieutils::TIEBitmap* ObjBitmapAlpha[int hobj] = {read=GetObjBitmapAlpha, write=SetObjBitmapAlpha
		};
	__property TIEShape ObjBeginShape[int hobj] = {read=GetObjBeginShape, write=SetObjBeginShape};
	__property TIEShape ObjEndShape[int hobj] = {read=GetObjEndShape, write=SetObjEndShape};
	__property int ObjShapeWidth[int hobj] = {read=GetObjShapeWidth, write=SetObjShapeWidth};
	__property int ObjShapeHeight[int hobj] = {read=GetObjShapeHeight, write=SetObjShapeHeight};
	__property TIELabelPos ObjLabelPosition[int hobj] = {read=GetObjLabelPos, write=SetObjLabelPos};
	__property AnsiString ObjText[int hobj] = {read=GetObjText, write=SetObjText};
	__property bool ObjTextAutoSize[int hobj] = {read=GetObjTextAutoSize, write=SetObjTextAutoSize};
	__property double ObjTextCurveCharRot[int hobj] = {read=GetObjTextCurveCharRot, write=SetObjTextCurveCharRot
		};
	__property int ObjMemoLineSpace[int hobj] = {read=GetObjMemoLineSpace, write=SetObjMemoLineSpace};
	__property double ObjFontAngle[int hobj] = {read=GetObjFontAngle, write=SetObjFontAngle};
	__property int ObjFontHeight[int hobj] = {read=GetObjFontHeight, write=SetObjFontHeight};
	__property AnsiString ObjFontName[int hobj] = {read=GetObjFontName, write=SetObjFontName};
	__property Graphics::TFontStyles ObjFontStyles[int hobj] = {read=GetObjFontStyles, write=SetObjFontStyles
		};
	__property Imageenview::TIEAlignment ObjTextAlign[int hobj] = {read=GetObjTextAlign, write=SetObjTextAlign
		};
	__property int ObjLeft[int hobj] = {read=GetObjLeft, write=SetObjLeft};
	__property int ObjTop[int hobj] = {read=GetObjTop, write=SetObjTop};
	__property int ObjWidth[int hobj] = {read=GetObjWidth, write=SetObjWidth};
	__property int ObjHeight[int hobj] = {read=GetObjHeight, write=SetObjHeight};
	__property AnsiString ObjName[int hobj] = {read=GetObjName, write=SetObjName};
	__property int ObjID[int hobj] = {read=GetObjID, write=SetObjID};
	__property TIEVStyle ObjStyle[int hobj] = {read=GetObjStyle, write=SetObjStyle};
	__property TIEUnits ObjRulerUnit[int hobj] = {read=GetObjRulerUnit, write=SetObjRulerUnit};
	__property TIEVRulerType ObjRulerType[int hobj] = {read=GetObjRulerType, write=SetObjRulerType};
	__property int ObjTransparency[int hobj] = {read=GetObjTransparency, write=SetObjTransparency};
	__property Windows::TPoint ObjPolylinePoints[int hobj][int index] = {read=GetObjPolylinePoints};
	__property int ObjPolylinePointsCount[int hobj] = {read=GetObjPolylinePointsCount};
	__property bool ObjPolylineClosed[int hobj] = {read=GetObjPolylineClosed, write=SetObjPolylineClosed
		};
	__property Imageenview::TIEVSoftShadow* ObjSoftShadow[int hobj] = {read=GetObjSoftShadow};
	__property bool ObjFontLocked[int hobj] = {read=GetObjFontLocked, write=SetObjFontLocked};
	__property Graphics::TColor ObjMemoBorderColor[int hobj] = {read=GetObjMemoBorderColor, write=SetObjMemoBorderColor
		};
	__property Graphics::TPenStyle ObjMemoBorderStyle[int hobj] = {read=GetObjMemoBorderStyle, write=SetObjMemoBorderStyle
		};
	__property int ObjMemoFixedHeight[int hobj] = {read=GetObjMemoFixedHeight, write=SetObjMemoFixedHeight
		};
	__property int ObjTextEditMode = {read=GetObjTextEditMode, write=SetObjTextEditMode, nodefault};
	__property bool ObjBitmapBorder[int hobj] = {read=GetObjBitmapBorder, write=SetObjBitmapBorder};
	__property double ObjArcStartingAngle[int hobj] = {read=GetObjArcStartingAngle, write=SetObjArcStartingAngle
		};
	__property double ObjArcEndingAngle[int hobj] = {read=GetObjArcEndingAngle, write=SetObjArcEndingAngle
		};
	void __fastcall ObjSetTBitmap(int hobj, Graphics::TBitmap* bmp);
	double __fastcall GetAngleValue(int hobj);
	void __fastcall SetObjPolylinePoints(int hobj, const Windows::TPoint * Points, const int Points_Size
		);
	void __fastcall GetObjRect(int hobj, Windows::TRect &Rect);
	void __fastcall SetObjRect(int hobj, const Windows::TRect &Rect);
	__property bool AllObjectsHidden = {read=fAllObjectsHidden, write=SetAllObjectsHidden, nodefault};
	void __fastcall SetObjFont(int hobj, Graphics::TFont* v);
	void __fastcall SetObjBitmapICO(int hobj, int ico, int iwidth, int iheight);
	bool __fastcall SetObjBitmapFromFile(int hobj, const AnsiString FileName);
	void __fastcall SetObjFrontOf(int hobj, int refobj);
	void __fastcall SetObjBackTo(int hobj, int refobj);
	__property bool ObjEditOnNewText = {read=fObjEditOnNewText, write=fObjEditOnNewText, nodefault};
	TIEMemoEditCharInfo* __fastcall MemoEditingGetCharInfo(void);
	void __fastcall MemoEditingSetCharInfo(TIEMemoEditCharInfo* info);
	bool __fastcall IsSelObject(int hobj);
	void __fastcall UnSelObject(int hobj);
	void __fastcall AddSelObject(int hobj);
	void __fastcall UnSelAllObjects(void);
	void __fastcall SelAllObjects(void);
	__property int MaxSelectionDistance = {read=fMaxSelectionDistance, write=fMaxSelectionDistance, nodefault
		};
	__property int SelObjects[int idx] = {read=GetSelObjects};
	__property int SelObjectsCount = {read=fSelObjCount, nodefault};
	__property bool EnableRangeObjectsSelection = {read=fEnableRangeObjectsSelection, write=fEnableRangeObjectsSelection
		, nodefault};
	void __fastcall RemoveAllObjects(void);
	void __fastcall RemoveObject(int hobj);
	int __fastcall AddNewObject(void);
	int __fastcall GetObjFromName(const AnsiString oName);
	int __fastcall GetObjFromID(int oID);
	int __fastcall GetObjFromIndex(int idx);
	int __fastcall CopyObjectTo(int hobj, TImageEnVect* Dest);
	void __fastcall CopyAllObjectsTo(TImageEnVect* Dest);
	void __fastcall CopySelectedObjectsTo(TImageEnVect* Dest);
	int __fastcall FindObjectAt(int x, int y, double &Distance);
	int __fastcall CreatePolygonFromEdge(int x, int y, bool maxfilter, int tolerance);
	void __fastcall SetObjTextCurve(int hobj, double x, double y);
	void __fastcall SetObjTextCurveShape(int hobj, TIECurve shape, int phase, bool dforward);
	void __fastcall SetObjTextCurveFromPolyline(int hobj, int source);
	int __fastcall CreateImageFromSelectedArea(int feather, bool smooth);
	void __fastcall CopyObjectsToBack(bool Antialias);
	void __fastcall CopyObjectToBack(int hobj, bool Antialias);
	void __fastcall DrawObjectsToBitmap(Hyieutils::TIEBitmap* target, bool Antialias);
	bool __fastcall RemovePolygonJaggedEdges(int hobj);
	void __fastcall SimplifyPolygon(int hobj, int MaxPoints);
	AnsiString __fastcall GetMemoFormattedString(int hobj);
	__property int ObjDrawed = {read=fObjDrawed, nodefault};
	bool __fastcall IsEditMode(void);
	void __fastcall RotateAllObjects(double angle, TIERotateCenter center);
	void __fastcall RotateObject(int hobj, double angle, TIERotateCenter center);
	__property bool AllowOutOfBitmapMoving = {read=fAllowOutOfBitmapMoving, write=fAllowOutOfBitmapMoving
		, nodefault};
	__property Graphics::TFont* MeasureHintFont = {read=fMeasureHintFont};
	__property Graphics::TBrush* MeasureHintBrush = {read=fMeasureHintBrush};
	__property Graphics::TColor MeasureHintBorder1 = {read=fMeasureHintBorder1, write=fMeasureHintBorder1
		, nodefault};
	__property Graphics::TColor MeasureHintBorder2 = {read=fMeasureHintBorder2, write=fMeasureHintBorder2
		, nodefault};
	void __fastcall SaveToFileIEV(const AnsiString nf);
	void __fastcall SaveToStreamIEV(Classes::TStream* Stream);
	bool __fastcall LoadFromFileIEV(const AnsiString nf);
	bool __fastcall LoadFromStreamIEV(Classes::TStream* Stream);
	bool __fastcall ImportDXF(const AnsiString nf);
	void __fastcall SaveObjectsToTIFF(const AnsiString fileName, int pageIndex);
	void __fastcall LoadObjectsFromTIFF(const AnsiString fileName, int pageIndex);
	void __fastcall SaveToFileAll(const AnsiString fileName, int imageCompression);
	void __fastcall SaveToStreamAll(Classes::TStream* Stream, int imageCompression);
	bool __fastcall LoadFromFileAll(const AnsiString fileName);
	bool __fastcall LoadFromStreamAll(Classes::TStream* Stream);
	void __fastcall ObjCopyToClipboard(void);
	void __fastcall ObjCutToClipboard(void);
	void __fastcall ObjPasteFromClipboard(int OffsetX, int OffsetY);
	void __fastcall ObjSaveUndo(void);
	void __fastcall ObjClearUndo(void);
	void __fastcall ObjClearAllUndo(void);
	__property bool ObjCanUndo = {read=GetObjCanUndo, nodefault};
	__property int ObjUndoCount = {read=GetObjUndoCount, nodefault};
	void __fastcall ObjUndoAt(int Position);
	void __fastcall ObjUndo(void);
	void __fastcall ObjLockPaint(void);
	void __fastcall ObjUnLockPaint(void);
	
__published:
	__property TIEUnits MUnit = {read=fMUnit, write=SetMUnit, default=0};
	__property int FloatDigits = {read=fFloatDigits, write=SetFloatDigits, default=2};
	__property int FloatPrecision = {read=fFloatPrecision, write=SetFloatPrecision, default=15};
	__property bool ShareBitmaps = {read=fShareBitmaps, write=fShareBitmaps, default=1};
	__property Classes::TNotifyEvent OnSelectObject = {read=fOnSelectObject, write=fOnSelectObject};
	__property TIEVMeasureHintEvent OnMeasureHint = {read=fOnMeasureHint, write=fOnMeasureHint};
	__property bool ZoomObjectsWidth = {read=fZoomObjectsWidth, write=SetZoomObjectsWidth, default=1};
	__property Classes::TNotifyEvent OnVectorialChanged = {read=fOnVectorialChanged, write=fOnVectorialChanged
		};
	__property Classes::TNotifyEvent OnBeforeVectorialChanged = {read=fOnBeforeVectorialChanged, write=
		fOnBeforeVectorialChanged};
	__property TIEVDragLenEndEvent OnDragLenEnd = {read=fOnDragLenEnd, write=fOnDragLenEnd};
	__property TIEVNewObject OnNewObject = {read=fOnNewObject, write=fOnNewObject};
	__property Hyiedefs::TResampleFilter BitmapResampleFilter = {read=fBitmapResampleFilter, write=SetBitmapResampleFilter
		, default=0};
	__property TIEVObjectMoveResizeEvent OnObjectMoveResize = {read=fOnObjectMoveResize, write=fOnObjectMoveResize
		};
	__property TIEVObjectClickEvent OnObjectClick = {read=fOnObjectClick, write=fOnObjectClick};
	__property TIEVObjectClickEvent OnObjectDblClick = {read=fOnObjectDblClick, write=fOnObjectDblClick
		};
	__property TIEVObjectClickEvent OnObjectOver = {read=fOnObjectOver, write=fOnObjectOver};
	__property int ObjUndoLimit = {read=fObjUndoLimit, write=fObjUndoLimit, default=1};
	__property bool ObjAutoUndo = {read=fObjAutoUndo, write=fObjAutoUndo, default=0};
	__property bool ObjAntialias = {read=fObjAntialias, write=SetObjAntialias, default=0};
	__property bool SelectOnMouseDown = {read=fSelectOnMouseDown, write=fSelectOnMouseDown, default=1};
		
	__property Controls::TKeyEvent OnTextKeyDown = {read=fOnTextKeyDown, write=fOnTextKeyDown};
	__property Classes::TNotifyEvent OnActivateTextEdit = {read=fOnActivateTextEdit, write=fOnActivateTextEdit
		};
	__property Classes::TNotifyEvent OnDeactivateTextEdit = {read=fOnDeactivateTextEdit, write=fOnDeactivateTextEdit
		};
	__property Classes::TNotifyEvent OnTextEditCursorMoved = {read=GetOnTextEditCursorMoved, write=SetOnTextEditCursorMoved
		};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TImageEnVect(HWND ParentWindow) : Imageenview::TImageEnView(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString strunits[8];
static const Shortint NULLOBJ = 0xfffffffc;
static const Shortint DEFWIDTH = 0x40;
static const Shortint DEFHEIGHT = 0x40;
extern PACKAGE AnsiString IEVECTCLIPFORMAT_NAME;
#define IEVMAGIC "IEV"
extern PACKAGE Byte IEVVER;
extern PACKAGE int IEVECTCLIPFORMAT;

}	/* namespace Ievect */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ievect;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ievect
