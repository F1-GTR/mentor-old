// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'hyieutils.pas' rev: 5.00

#ifndef hyieutilsHPP
#define hyieutilsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Dialogs.hpp>	// Pascal unit
#include <iewords.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Hyieutils
{
//-- type declarations -------------------------------------------------------
typedef int __fastcall (__closure *TIECompareFunction)(int Index1, int Index2);

typedef void __fastcall (__closure *TIESwapFunction)(int Index1, int Index2);

typedef void __fastcall (*TIEDialogCenter)(HWND Wnd);

#pragma pack(push, 1)
struct TTIFFHeader
{
	Word Id;
	Word Ver;
	int PosIFD;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TTIFFTAG
{
	Word IdTag;
	Word DataType;
	int DataNum;
	int DataPos;
} ;
#pragma pack(pop)

typedef TTIFFTAG *PTIFFTAG;

typedef TTIFFTAG TIFD[134217728];

typedef TTIFFTAG *PIFD;

struct TTIFFEnv
{
	bool Intel;
	Classes::TStream* Stream;
	TTIFFTAG *IFD;
	Word NumTags;
	__int64 StreamBase;
} ;

class DELPHICLASS THash1Item;
class PASCALIMPLEMENTATION THash1Item : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int key;
	THash1Item* nextitem;
	int value;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall THash1Item(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~THash1Item(void) { }
	#pragma option pop
	
};


class DELPHICLASS THash1;
class PASCALIMPLEMENTATION THash1 : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* fMainKeys;
	Classes::TList* fMainKeysUse;
	Classes::TList* fMainKeysValue;
	int fHbits;
	int fHdim;
	int fIteratePtr1;
	THash1Item* fIteratePtr2;
	int __fastcall HashFunc(int kk);
	
public:
	int nkeys;
	__fastcall THash1(int Hbits);
	__fastcall virtual ~THash1(void);
	bool __fastcall Insert(int kk);
	bool __fastcall KeyPresent(int kk);
	bool __fastcall Insert2(int kk, int &ptr1, THash1Item* &ptr2);
	void __fastcall SetValue(int ptr1, THash1Item* ptr2, int Value);
	int __fastcall GetValue(int ptr1, THash1Item* ptr2);
	bool __fastcall IterateBegin(void);
	bool __fastcall IterateNext(void);
	int __fastcall IterateGetValue(void);
};


class DELPHICLASS TImageEnPaletteDialog;
class PASCALIMPLEMENTATION TImageEnPaletteDialog : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
private:
	int MouseCol;
	Hyiedefs::TRGB *fPalette;
	int fNumCol;
	void __fastcall FormPaint(System::TObject* Sender);
	void __fastcall FormMouseMove(System::TObject* Sender, Classes::TShiftState Shift, int x, int y);
	void __fastcall FormClick(System::TObject* Sender);
	
public:
	Stdctrls::TButton* ButtonCancel;
	Graphics::TColor SelCol;
	__property int NumCol = {read=MouseCol, nodefault};
	__fastcall virtual TImageEnPaletteDialog(Classes::TComponent* AOwner);
	void __fastcall SetPalette(Hyiedefs::TRGB * Palette, const int Palette_Size, int NumCol);
	bool __fastcall Execute(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TImageEnPaletteDialog(Classes::TComponent* AOwner
		, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TImageEnPaletteDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TImageEnPaletteDialog(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TIEScrollBarParams;
class PASCALIMPLEMENTATION TIEScrollBarParams : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int fLineStep;
	int fPageStep;
	bool fTracking;
	
public:
	__fastcall TIEScrollBarParams(void);
	__fastcall virtual ~TIEScrollBarParams(void);
	__property int LineStep = {read=fLineStep, write=fLineStep, nodefault};
	__property int PageStep = {read=fPageStep, write=fPageStep, nodefault};
	__property bool Tracking = {read=fTracking, write=fTracking, nodefault};
};


#pragma option push -b-
enum TIEMouseWheelParamsAction { iemwNone, iemwVScroll, iemwZoom };
#pragma option pop

#pragma option push -b-
enum TIEMouseWheelParamsVariation { iemwAbsolute, iemwPercentage };
#pragma option pop

#pragma option push -b-
enum TIEMouseWheelParamsZoomPosition { iemwCenter, iemwMouse };
#pragma option pop

class DELPHICLASS TIEMouseWheelParams;
class PASCALIMPLEMENTATION TIEMouseWheelParams : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	bool InvertDirection;
	TIEMouseWheelParamsAction Action;
	TIEMouseWheelParamsVariation Variation;
	int Value;
	TIEMouseWheelParamsZoomPosition ZoomPosition;
	__fastcall TIEMouseWheelParams(void);
	__fastcall virtual ~TIEMouseWheelParams(void);
};


class DELPHICLASS TIEHint;
class PASCALIMPLEMENTATION TIEHint : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	AnsiString fText;
	Graphics::TFont* fFont;
	HIDESBASE void __fastcall SetText(AnsiString s);
	HIDESBASE void __fastcall SetFont(Graphics::TFont* f);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Messages::TMessage &Message);
	
public:
	__fastcall virtual TIEHint(Classes::TComponent* Owner);
	__fastcall virtual ~TIEHint(void);
	virtual void __fastcall Paint(void);
	__property AnsiString Text = {read=fText, write=SetText};
	__property Graphics::TFont* Font = {read=fFont, write=SetFont};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TIEHint(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TIEByteArray;
class PASCALIMPLEMENTATION TIEByteArray : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int fSize;
	int fRSize;
	int fBlockSize;
	void __fastcall SetSize(int v);
	
public:
	Byte *Data;
	__fastcall TIEByteArray(void);
	__fastcall virtual ~TIEByteArray(void);
	void __fastcall AddByte(Byte v);
	__property int Size = {read=fSize, write=SetSize, nodefault};
	__property int BlockSize = {read=fBlockSize, write=fBlockSize, nodefault};
	void __fastcall Clear(void);
	int __fastcall AppendFromStream(Classes::TStream* Stream, int Count);
};


class DELPHICLASS TNulStream;
class PASCALIMPLEMENTATION TNulStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	int fposition;
	int fsize;
	
public:
	__fastcall TNulStream(void);
	__fastcall virtual ~TNulStream(void);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin);
};


#pragma option push -b-
enum hyieutils__9 { ielItems, ielRange, ielCurrentValue };
#pragma option pop

typedef Set<hyieutils__9, ielItems, ielCurrentValue>  TIEListChanges;

class DELPHICLASS TIEList;
class PASCALIMPLEMENTATION TIEList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int fCount;
	
protected:
	int fItemSize;
	void *fData;
	TIEListChanges fChanged;
	virtual void __fastcall SetCount(int v);
	int __fastcall AddItem(void * v);
	void __fastcall InsertItem(int idx, void * v);
	int __fastcall IndexOfItem(void * v);
	void * __fastcall BaseGetItem(int idx);
	void __fastcall BaseSetItem(int idx, void * v);
	
public:
	__fastcall virtual TIEList(void);
	__fastcall virtual ~TIEList(void);
	virtual void __fastcall Delete(int idx);
	__property int Count = {read=fCount, write=SetCount, nodefault};
	virtual void __fastcall Clear(void);
	virtual void __fastcall Assign(TIEList* Source);
	__property TIEListChanges Changed = {read=fChanged, write=fChanged, nodefault};
};


class DELPHICLASS TIEDoubleList;
class PASCALIMPLEMENTATION TIEDoubleList : public TIEList 
{
	typedef TIEList inherited;
	
private:
	double fRangeMin;
	double fRangeMax;
	double fRangeStep;
	double fCurrentValue;
	double __fastcall GetItem(int idx);
	void __fastcall SetItem(int idx, double v);
	void __fastcall SetRangeMax(double v);
	void __fastcall SetRangeMin(double v);
	void __fastcall SetRangeStep(double v);
	void __fastcall SetCurrentValue(double v);
	
public:
	int __fastcall Add(double v);
	void __fastcall Insert(int idx, double v);
	virtual void __fastcall Clear(void);
	int __fastcall IndexOf(double v);
	__property double RangeMin = {read=fRangeMin, write=SetRangeMin};
	__property double RangeMax = {read=fRangeMax, write=SetRangeMax};
	__property double RangeStep = {read=fRangeStep, write=SetRangeStep};
	__property double Items[int idx] = {read=GetItem, write=SetItem/*, default*/};
	virtual void __fastcall Assign(TIEList* Source);
	__property double CurrentValue = {read=fCurrentValue, write=SetCurrentValue};
public:
	#pragma option push -w-inl
	/* TIEList.Create */ inline __fastcall virtual TIEDoubleList(void) : TIEList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEList.Destroy */ inline __fastcall virtual ~TIEDoubleList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEIntegerList;
class PASCALIMPLEMENTATION TIEIntegerList : public TIEList 
{
	typedef TIEList inherited;
	
private:
	int fRangeMin;
	int fRangeMax;
	int fRangeStep;
	int fCurrentValue;
	int __fastcall GetItem(int idx);
	void __fastcall SetItem(int idx, int v);
	void __fastcall SetRangeMax(int v);
	void __fastcall SetRangeMin(int v);
	void __fastcall SetRangeStep(int v);
	void __fastcall SetCurrentValue(int v);
	
public:
	int __fastcall Add(int v);
	void __fastcall Insert(int idx, int v);
	virtual void __fastcall Clear(void);
	int __fastcall IndexOf(int v);
	__property int RangeMin = {read=fRangeMin, write=SetRangeMin, nodefault};
	__property int RangeMax = {read=fRangeMax, write=SetRangeMax, nodefault};
	__property int RangeStep = {read=fRangeStep, write=SetRangeStep, nodefault};
	__property int Items[int idx] = {read=GetItem, write=SetItem/*, default*/};
	virtual void __fastcall Assign(TIEList* Source);
	__property int CurrentValue = {read=fCurrentValue, write=SetCurrentValue, nodefault};
public:
	#pragma option push -w-inl
	/* TIEList.Create */ inline __fastcall virtual TIEIntegerList(void) : TIEList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEList.Destroy */ inline __fastcall virtual ~TIEIntegerList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIERecordList;
class PASCALIMPLEMENTATION TIERecordList : public TIEList 
{
	typedef TIEList inherited;
	
private:
	void * __fastcall GetItem(int idx);
	void __fastcall SetItem(int idx, void * v);
	
public:
	int __fastcall Add(void * v);
	void __fastcall Insert(int idx, void * v);
	int __fastcall IndexOf(void * v);
	__property void * Items[int idx] = {read=GetItem, write=SetItem/*, default*/};
	__fastcall TIERecordList(int RecordSize);
public:
	#pragma option push -w-inl
	/* TIEList.Create */ inline __fastcall virtual TIERecordList(void) : TIEList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEList.Destroy */ inline __fastcall virtual ~TIERecordList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEMarkerList;
class PASCALIMPLEMENTATION TIEMarkerList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* fData;
	Classes::TList* fType;
	int __fastcall GetCount(void);
	char * __fastcall GetMarkerData(int idx);
	Classes::TStream* __fastcall GetMarkerStream(int idx);
	Byte __fastcall GetMarkerType(int idx);
	Word __fastcall GetMarkerLength(int idx);
	
public:
	__fastcall TIEMarkerList(void);
	__fastcall virtual ~TIEMarkerList(void);
	int __fastcall AddMarker(Byte marker, char * data, Word datalen);
	void __fastcall SetMarker(int idx, Byte marker, char * data, Word datalen);
	void __fastcall InsertMarker(int idx, char * data, Byte marker, Word datalen);
	void __fastcall Clear(void);
	__property char * MarkerData[int idx] = {read=GetMarkerData};
	__property Classes::TStream* MarkerStream[int idx] = {read=GetMarkerStream};
	__property Word MarkerLength[int idx] = {read=GetMarkerLength};
	__property Byte MarkerType[int idx] = {read=GetMarkerType};
	int __fastcall IndexOf(Byte marker);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall DeleteMarker(int idx);
	__property int Count = {read=GetCount, nodefault};
	void __fastcall Assign(TIEMarkerList* Source);
};


#pragma pack(push, 1)
struct TIPTCInfo
{
	int fRecord;
	int fDataSet;
	int fLength;
} ;
#pragma pack(pop)

typedef TIPTCInfo *PIPTCInfo;

class DELPHICLASS TIEIPTCInfoList;
class PASCALIMPLEMENTATION TIEIPTCInfoList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* fBuffer;
	Classes::TList* fInfo;
	bool fUserChanged;
	AnsiString __fastcall GetStrings(int idx);
	void __fastcall SetStrings(int idx, AnsiString Value);
	int __fastcall GetRecordNumber(int idx);
	void __fastcall SetRecordNumber(int idx, int Value);
	int __fastcall GetDataSet(int idx);
	void __fastcall SetDataSet(int idx, int Value);
	int __fastcall GetCount(void);
	
public:
	__fastcall TIEIPTCInfoList(void);
	__fastcall virtual ~TIEIPTCInfoList(void);
	__property AnsiString StringItem[int idx] = {read=GetStrings, write=SetStrings};
	__property int RecordNumber[int idx] = {read=GetRecordNumber, write=SetRecordNumber};
	__property int DataSet[int idx] = {read=GetDataSet, write=SetDataSet};
	int __fastcall AddStringItem(int RecordNumber, int DataSet, AnsiString Value);
	int __fastcall AddBufferItem(int RecordNumber, int DataSet, void * Buffer, int BufferLength);
	void __fastcall InsertStringItem(int idx, int RecordNumber, int DataSet, AnsiString Value);
	void __fastcall Clear(void);
	int __fastcall IndexOf(int RecordNumber, int DataSet);
	void __fastcall DeleteItem(int idx);
	__property int Count = {read=GetCount, nodefault};
	void __fastcall Assign(TIEIPTCInfoList* Source);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall LoadFromStandardBuffer(void * Buffer, int BufferLength);
	void __fastcall SaveToStandardBuffer(void * &Buffer, int &BufferLength, bool WriteHeader);
	__property bool UserChanged = {read=fUserChanged, write=fUserChanged, nodefault};
};


struct OIAN_MARK_ATTRIBUTES
{
	int uType;
	Windows::TRect lrBounds;
	tagRGBQUAD rgbColor1;
	tagRGBQUAD rgbColor2;
	BOOL bHighlighting;
	BOOL bTransparent;
	unsigned uLineSize;
	unsigned uReserved1;
	unsigned uReserved2;
	tagLOGFONTA lfFont;
	unsigned bReserved3;
	int Time;
	BOOL bVisible;
	unsigned dwReserved4;
	int lReserved[10];
} ;

class DELPHICLASS TIEImagingObject;
class DELPHICLASS TIEBitmap;
class DELPHICLASS TIEBaseBitmap;
#pragma option push -b-
enum hyieutils__91 { iedRead, iedWrite };
#pragma option pop

typedef Set<hyieutils__91, iedRead, iedWrite>  TIEDataAccess;

#pragma option push -b-
enum TIEPixelFormat { ienull, ie1g, ie8p, ie8g, ie16g, ie24RGB, ie32f, ieCMYK, ie48RGB, ieCIELab };
#pragma option pop

class PASCALIMPLEMENTATION TIEBaseBitmap : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	TIEDataAccess fAccess;
	virtual void * __fastcall GetScanLine(int Row) = 0 ;
	virtual int __fastcall GetBitCount(void) = 0 ;
	virtual int __fastcall GetHeight(void) = 0 ;
	virtual int __fastcall GetWidth(void) = 0 ;
	virtual TIEPixelFormat __fastcall GetPixelFormat(void) = 0 ;
	virtual int __fastcall GetRowLen(void) = 0 ;
	virtual Hyiedefs::TRGB __fastcall GetPalette(int index) = 0 ;
	virtual void __fastcall SetPalette(int index, Hyiedefs::TRGB Value) = 0 ;
	virtual int __fastcall GetPaletteLen(void) = 0 ;
	
public:
	__property void * Scanline[int row] = {read=GetScanLine};
	__property int BitCount = {read=GetBitCount, nodefault};
	__property int Width = {read=GetWidth, nodefault};
	__property int Height = {read=GetHeight, nodefault};
	__property TIEPixelFormat PixelFormat = {read=GetPixelFormat, nodefault};
	virtual void __fastcall Allocate(int ImageWidth, int ImageHeight, TIEPixelFormat ImagePixelFormat) = 0 
		;
	virtual void __fastcall Assign(System::TObject* Source) = 0 ;
	__property int RowLen = {read=GetRowLen, nodefault};
	__property TIEDataAccess Access = {read=fAccess, write=fAccess, nodefault};
	__property Hyiedefs::TRGB Palette[int index] = {read=GetPalette, write=SetPalette};
	__property int PaletteLength = {read=GetPaletteLen, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIEBaseBitmap(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIEBaseBitmap(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEFileBuffer;
class PASCALIMPLEMENTATION TIEFileBuffer : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TFileStream* fSimFile;
	AnsiString fFileName;
	Classes::TList* fMapped;
	int __fastcall IndexOf(void * ptr);
	
public:
	__fastcall TIEFileBuffer(void);
	__fastcall virtual ~TIEFileBuffer(void);
	bool __fastcall AllocateFile(__int64 InSize, const AnsiString Descriptor);
	void __fastcall ReAllocateFile(__int64 NewSize);
	void * __fastcall Map(__int64 InPos, __int64 InSize, TIEDataAccess DataAccess);
	void __fastcall UnMap(void * ptr);
	void __fastcall UnMapAll(void);
	bool __fastcall IsAllocated(void);
	void __fastcall DeAllocate(void);
	void __fastcall CopyTo(TIEFileBuffer* Dest, __int64 InPos, __int64 InSize);
};


#pragma option push -b-
enum TIELocation { ieMemory, ieFile, ieTBitmap };
#pragma option pop

#pragma option push -b-
enum TIEDitherMethod { ieOrdered, ieThreshold };
#pragma option pop

#pragma option push -b-
enum TIERenderOperation { ielNormal, ielAdd, ielSub, ielDiv, ielMul, ielOR, ielAND, ielXOR, ielMAX, 
	ielMIN, ielAverage, ielScreen, ielNegation, ielExclusion, ielOverlay, ielHardLight, ielSoftLight, ielXFader, 
	ielColorEdge, ielColorBurn, ielInverseColorDodge, ielInverseColorBurn, ielSoftDodge, ielSoftBurn, ielReflect, 
	ielGlow, ielFreeze, ielEat, ielSubtractive, ielInterpolation, ielStamp, ielRed, ielGreen, ielBlue, 
	ielHue, ielSaturation, ielColor, ielLuminosity };
#pragma option pop

class DELPHICLASS TIEMask;
#pragma option push -b-
enum TIEHAlign { iehLeft, iehCenter, iehRight };
#pragma option pop

#pragma option push -b-
enum TIEVAlign { ievTop, ievCenter, ievBottom };
#pragma option pop

class DELPHICLASS TIEDibbitmap;
class PASCALIMPLEMENTATION TIEBitmap : public TIEBaseBitmap 
{
	typedef TIEBaseBitmap inherited;
	
private:
	TIEFileBuffer* fmemmap;
	void *fWorkingMap;
	Hyiedefs::TRGB *fRGBPalette;
	int fRGBPaletteLen;
	TIEBitmap* fAlphaChannel;
	void *fMemory;
	void *fRealMemory;
	Graphics::TBitmap* fBitmap;
	void * *fBitmapScanlines;
	Classes::TList* fScanlinesToUnMap;
	int fWidth;
	int fHeight;
	int fBitCount;
	int fChannelCount;
	int fRowLen;
	TIEPixelFormat fPixelFormat;
	bool fIsAlpha;
	TIELocation fLocation;
	bool fFull;
	bool fEncapsulatedFromTBitmap;
	bool fEncapsulatedFromMemory;
	int fMinFileSize;
	TIEDitherMethod fDefaultDitherMethod;
	int fPaletteUsed;
	double fBlackValue;
	double fWhiteValue;
	int fChannelOffset[4];
	bool fEnableChannelOffset;
	int fContrast;
	int fBitAlignment;
	void __fastcall SetWidth(int Value);
	void __fastcall SetHeight(int Value);
	void __fastcall AllocateImage(void);
	void __fastcall SetPixelFormat(TIEPixelFormat Value);
	void __fastcall ConvertToPixelFormat(TIEPixelFormat DestPixelFormat);
	bool __fastcall GetPixels_ie1g(int x, int y);
	Byte __fastcall GetPixels_ie8(int x, int y);
	Word __fastcall GetPixels_ie16g(int x, int y);
	Hyiedefs::TRGB __fastcall GetPixels_ie24RGB(int x, int y);
	float __fastcall GetPixels_ie32f(int x, int y);
	Hyiedefs::TCMYK __fastcall GetPixels_ieCMYK(int x, int y);
	Hyiedefs::TCIELab __fastcall GetPixels_ieCIELab(int x, int y);
	Hyiedefs::TRGB48 __fastcall GetPixels_ie48RGB(int x, int y);
	Hyiedefs::PRGB __fastcall GetPPixels_ie24RGB(int x, int y);
	Hyiedefs::PRGB48 __fastcall GetPPixels_ie48RGB(int x, int y);
	Hyiedefs::TRGB __fastcall GetPixels(int x, int y);
	void __fastcall SetPixels_ie1g(int x, int y, bool Value);
	void __fastcall SetPixels_ie8(int x, int y, Byte Value);
	void __fastcall SetPixels_ie16g(int x, int y, Word Value);
	void __fastcall SetPixels_ie24RGB(int x, int y, Hyiedefs::TRGB Value);
	void __fastcall SetPixels_ie32f(int x, int y, float Value);
	void __fastcall SetPixels_ieCMYK(int x, int y, Hyiedefs::TCMYK Value);
	void __fastcall SetPixels_ieCIELab(int x, int y, Hyiedefs::TCIELab Value);
	void __fastcall SetPixels_ie48RGB(int x, int y, const Hyiedefs::TRGB48 &Value);
	Byte __fastcall GetAlpha(int x, int y);
	void __fastcall SetAlpha(int x, int y, Byte Value);
	void __fastcall SetLocation(TIELocation Value);
	void __fastcall UpdateTBitmapPalette(void);
	bool __fastcall GetHasAlphaChannel(void);
	void __fastcall FreeBitmapScanlines(void);
	void __fastcall BuildBitmapScanlines(void);
	Graphics::TBitmap* __fastcall GetVclBitmap(void);
	void __fastcall SetChannelOffset(int idx, int value);
	int __fastcall GetChannelOffset(int idx);
	void __fastcall SetBitAlignment(int value);
	int __fastcall GetChannelCount(void);
	
protected:
	__fastcall TIEBitmap(int ImageWidth, int ImageHeight, TIELocation ImageLocation);
	Graphics::TCanvas* __fastcall GetCanvas(void);
	TIEBitmap* __fastcall GetAlphaChannel(void);
	virtual int __fastcall GetBitCount(void);
	virtual int __fastcall GetWidth(void);
	virtual int __fastcall GetHeight(void);
	virtual int __fastcall GetRowLen(void);
	virtual void * __fastcall GetScanLine(int Row);
	virtual TIEPixelFormat __fastcall GetPixelFormat(void);
	virtual Hyiedefs::TRGB __fastcall GetPalette(int index);
	virtual void __fastcall SetPalette(int index, Hyiedefs::TRGB Value);
	virtual int __fastcall GetPaletteLen(void);
	void __fastcall FreeAllMaps(void);
	void __fastcall UpdateFromTBitmap(void);
	virtual void __fastcall Render_ie24RGB(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap
		, Windows::PInteger XLUT, Windows::PInteger YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, 
		int cy1, int cx2, int cy2, int rx, int ry, bool SolidBackground, TIERenderOperation RenderOperation
		);
	virtual void __fastcall Render_ie24RGB_alpha(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap
		, int Transparency, bool UseAlpha, Windows::PByte SimAlphaRow, Windows::PInteger XLUT, Windows::PInteger 
		YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int cy2, int rx, int ry, 
		bool SolidBackground, TIERenderOperation RenderOperation);
	virtual void __fastcall Render_ie1g(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap, Windows::PInteger 
		XLUT, Windows::PInteger YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int 
		cy2, int rx, int ry, bool SolidBackground);
	virtual void __fastcall Render_ie1g_alpha(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap
		, int Transparency, bool UseAlpha, Windows::PByte SimAlphaRow, Windows::PInteger XLUT, Windows::PInteger 
		YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int cy2, int rx, int ry, 
		bool SolidBackground);
	virtual void __fastcall Render_ie8g(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap, Windows::PInteger 
		XLUT, Windows::PInteger YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int 
		cy2, int rx, int ry, bool SolidBackground);
	virtual void __fastcall Render_ie8g_alpha(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap
		, int Transparency, bool UseAlpha, Windows::PByte SimAlphaRow, Windows::PInteger XLUT, Windows::PInteger 
		YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int cy2, int rx, int ry, 
		bool SolidBackground);
	virtual void __fastcall Render_ie8p(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap, Windows::PInteger 
		XLUT, Windows::PInteger YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int 
		cy2, int rx, int ry, bool SolidBackground);
	virtual void __fastcall Render_ie8p_alpha(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap
		, int Transparency, bool UseAlpha, Windows::PByte SimAlphaRow, Windows::PInteger XLUT, Windows::PInteger 
		YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int cy2, int rx, int ry, 
		bool SolidBackground);
	virtual void __fastcall Render_ie16g(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap, 
		Windows::PInteger XLUT, Windows::PInteger YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int 
		cy1, int cx2, int cy2, int rx, int ry, bool SolidBackground);
	virtual void __fastcall Render_ie16g_alpha(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap
		, int Transparency, bool UseAlpha, Windows::PByte SimAlphaRow, Windows::PInteger XLUT, Windows::PInteger 
		YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int cy2, int rx, int ry, 
		bool SolidBackground);
	virtual void __fastcall Render_ie32f(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap, 
		Windows::PInteger XLUT, Windows::PInteger YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int 
		cy1, int cx2, int cy2, int rx, int ry, bool SolidBackground);
	virtual void __fastcall Render_ie32f_alpha(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap
		, int Transparency, bool UseAlpha, Windows::PByte SimAlphaRow, Windows::PInteger XLUT, Windows::PInteger 
		YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int cy2, int rx, int ry, 
		bool SolidBackground);
	virtual void __fastcall Render_ieCMYK(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap, 
		Windows::PInteger XLUT, Windows::PInteger YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int 
		cy1, int cx2, int cy2, int rx, int ry, bool SolidBackground);
	virtual void __fastcall Render_ieCMYK_alpha(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap
		, int Transparency, bool UseAlpha, Windows::PByte SimAlphaRow, Windows::PInteger XLUT, Windows::PInteger 
		YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int cy2, int rx, int ry, 
		bool SolidBackground);
	virtual void __fastcall Render_ieCIELab(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap
		, Windows::PInteger XLUT, Windows::PInteger YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, 
		int cy1, int cx2, int cy2, int rx, int ry, bool SolidBackground);
	virtual void __fastcall Render_ieCIELab_alpha(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &
		ABitmap, int Transparency, bool UseAlpha, Windows::PByte SimAlphaRow, Windows::PInteger XLUT, Windows::PInteger 
		YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int cy2, int rx, int ry, 
		bool SolidBackground);
	virtual void __fastcall Render_ie48RGB(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap
		, Windows::PInteger XLUT, Windows::PInteger YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, 
		int cy1, int cx2, int cy2, int rx, int ry, bool SolidBackground, TIERenderOperation RenderOperation
		);
	virtual void __fastcall Render_ie48RGB_alpha(Hyiedefs::PPointerArray dbitmapscanline, TIEBitmap* &ABitmap
		, int Transparency, bool UseAlpha, Windows::PByte SimAlphaRow, Windows::PInteger XLUT, Windows::PInteger 
		YLUT, int xSrc, int ySrc, int xDst, int yDst, int cx1, int cy1, int cx2, int cy2, int rx, int ry, 
		bool SolidBackground, TIERenderOperation RenderOperation);
	
public:
	__fastcall TIEBitmap(void)/* overload */;
	__fastcall TIEBitmap(int ImageWidth, int ImageHeight, TIEPixelFormat ImagePixelFormat)/* overload */
		;
	__fastcall virtual ~TIEBitmap(void);
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property TIEPixelFormat PixelFormat = {read=GetPixelFormat, write=SetPixelFormat, nodefault};
	virtual void __fastcall Assign(System::TObject* Source);
	void __fastcall AssignImage(TIEBitmap* Source);
	__property void * ScanLine[int Row] = {read=GetScanLine};
	__property Graphics::TCanvas* Canvas = {read=GetCanvas};
	__property bool EncapsulatedFromTBitmap = {read=fEncapsulatedFromTBitmap, write=fEncapsulatedFromTBitmap
		, nodefault};
	__property bool EncapsulatedFromMemory = {read=fEncapsulatedFromMemory, write=fEncapsulatedFromMemory
		, nodefault};
	__property int Rowlen = {read=GetRowLen, nodefault};
	virtual void __fastcall Allocate(int ImageWidth, int ImageHeight, TIEPixelFormat ImagePixelFormat);
		
	void __fastcall EncapsulateTBitmap(Graphics::TBitmap* obj, bool DoFreeImage);
	void __fastcall EncapsulateMemory(void * mem, int bmpWidth, int bmpHeight, TIEPixelFormat bmpPixelFormat
		, bool DoFreeImage);
	void __fastcall FreeImage(bool freeAlpha);
	void __fastcall SwitchTo(TIEBitmap* Target);
	__property TIEBitmap* AlphaChannel = {read=GetAlphaChannel, write=fAlphaChannel};
	__property TIELocation Location = {read=fLocation, write=SetLocation, nodefault};
	void __fastcall CopyToTBitmap(Graphics::TBitmap* Dest);
	void __fastcall CopyFromTBitmap(Graphics::TBitmap* Source);
	void __fastcall CopyFromTIEMask(TIEMask* Source);
	void __fastcall CopyToTIEMask(TIEMask* Dest);
	void __fastcall CopyRectTo(TIEBitmap* Dest, int SrcX, int SrcY, int DstX, int DstY, int RectWidth, 
		int RectHeight);
	void __fastcall MergeAlphaRectTo(TIEBitmap* Dest, int SrcX, int SrcY, int DstX, int DstY, int RectWidth
		, int RectHeight);
	void * __fastcall GetRow(int Row);
	void __fastcall FreeRow(int Row);
	void __fastcall Resize(int NewWidth, int NewHeight, int BackgroundValue, int AlphaValue, TIEHAlign 
		HorizAlign, TIEVAlign VertAlign);
	__property Graphics::TBitmap* VclBitmap = {read=GetVclBitmap, write=fBitmap};
	void __fastcall MoveRegion(int x1, int y1, int x2, int y2, int DstX, int DstY, int BackgroundValue)
		;
	void __fastcall CopyFromTDibBitmap(TIEDibbitmap* Source);
	void __fastcall MergeFromTDibBitmap(TIEDibbitmap* Source, int x, int y);
	void __fastcall CopyToTDibBitmap(TIEDibbitmap* Dest, int source_x, int source_y, int sourceWidth, int 
		sourceHeight);
	__property bool Pixels_ie1g[int x][int y] = {read=GetPixels_ie1g, write=SetPixels_ie1g};
	__property Byte Pixels_ie8[int x][int y] = {read=GetPixels_ie8, write=SetPixels_ie8};
	__property Word Pixels_ie16g[int x][int y] = {read=GetPixels_ie16g, write=SetPixels_ie16g};
	__property Hyiedefs::TRGB Pixels_ie24RGB[int x][int y] = {read=GetPixels_ie24RGB, write=SetPixels_ie24RGB
		};
	__property float Pixels_ie32f[int x][int y] = {read=GetPixels_ie32f, write=SetPixels_ie32f};
	__property Hyiedefs::TCMYK Pixels_ieCMYK[int x][int y] = {read=GetPixels_ieCMYK, write=SetPixels_ieCMYK
		};
	__property Hyiedefs::TCIELab Pixels_ieCIELab[int x][int y] = {read=GetPixels_ieCIELab, write=SetPixels_ieCIELab
		};
	__property Hyiedefs::TRGB48 Pixels_ie48RGB[int x][int y] = {read=GetPixels_ie48RGB, write=SetPixels_ie48RGB
		};
	__property Hyiedefs::PRGB PPixels_ie24RGB[int x][int y] = {read=GetPPixels_ie24RGB};
	__property Hyiedefs::PRGB48 PPixels_ie48RGB[int x][int y] = {read=GetPPixels_ie48RGB};
	__property Hyiedefs::TRGB Pixels[int x][int y] = {read=GetPixels};
	__property Byte Alpha[int x][int y] = {read=GetAlpha, write=SetAlpha};
	void __fastcall RenderToTIEBitmap(TIEBitmap* ABitmap, Hyiedefs::PPointerArray &ABitmapScanline, Windows::PInteger 
		&XLUT, Windows::PInteger &YLUT, Windows::PRect UpdRect, int xDst, int yDst, int dxDst, int dyDst, 
		int xSrc, int ySrc, int dxSrc, int dySrc, bool EnableAlpha, bool SolidBackground, int Transparency
		, Hyiedefs::TResampleFilter Filter, bool FreeTables, TIERenderOperation RenderOperation);
	void __fastcall RenderToTBitmap(Graphics::TBitmap* ABitmap, Hyiedefs::PPointerArray &ABitmapScanline
		, Windows::PInteger &XLUT, Windows::PInteger &YLUT, Windows::PRect UpdRect, int xDst, int yDst, int 
		dxDst, int dyDst, int xSrc, int ySrc, int dxSrc, int dySrc, bool EnableAlpha, bool SolidBackground
		, int Transparency, Hyiedefs::TResampleFilter Filter, bool FreeTables, TIERenderOperation RenderOperation
		);
	void __fastcall RenderToTBitmapEx(Graphics::TBitmap* Dest, int xDst, int yDst, int dxDst, int dyDst
		, int xSrc, int ySrc, int dxSrc, int dySrc, int Transparency, Hyiedefs::TResampleFilter Filter, TIERenderOperation 
		RenderOperation);
	void __fastcall RenderToTIEBitmapEx(TIEBitmap* Dest, int xDst, int yDst, int dxDst, int dyDst, int 
		xSrc, int ySrc, int dxSrc, int dySrc, int Transparency, Hyiedefs::TResampleFilter Filter, TIERenderOperation 
		RenderOperation);
	void __fastcall StretchRectTo(TIEBitmap* Dest, int xDst, int yDst, int dxDst, int dyDst, int xSrc, 
		int ySrc, int dxSrc, int dySrc, Hyiedefs::TResampleFilter Filter, int Transparency);
	void __fastcall RenderToCanvas(Graphics::TCanvas* DestCanvas, int xDst, int yDst, int dxDst, int dyDst
		, Hyiedefs::TResampleFilter Filter, double Gamma);
	void __fastcall DrawToCanvas(Graphics::TCanvas* DestCanvas, int xDst, int yDst);
	__property bool Full = {read=fFull, write=fFull, nodefault};
	void __fastcall SyncFull(void);
	void __fastcall Fill(double Value);
	void __fastcall FillRect(int x1, int y1, int x2, int y2, double Value);
	__property bool HasAlphaChannel = {read=GetHasAlphaChannel, nodefault};
	__property int MinFileSize = {read=fMinFileSize, write=fMinFileSize, nodefault};
	void __fastcall RemoveAlphaChannel(void);
	__property TIEDitherMethod DefaultDitherMethod = {read=fDefaultDitherMethod, write=fDefaultDitherMethod
		, nodefault};
	__property double BlackValue = {read=fBlackValue, write=fBlackValue};
	__property double WhiteValue = {read=fWhiteValue, write=fWhiteValue};
	__property int ChannelOffset[int idx] = {read=GetChannelOffset, write=SetChannelOffset};
	__property int Contrast = {read=fContrast, write=fContrast, nodefault};
	bool __fastcall IsGrayScale(void);
	bool __fastcall IsAllBlack(void);
	__property int PaletteUsed = {read=fPaletteUsed, write=fPaletteUsed, nodefault};
	__property int BitAlignment = {read=fBitAlignment, write=SetBitAlignment, nodefault};
	bool __fastcall IsEmpty(void);
	void __fastcall CopyAndConvertFormat(TIEBitmap* Source);
	__property int ChannelCount = {read=GetChannelCount, nodefault};
	__property int BitCount = {read=GetBitCount, nodefault};
};


class PASCALIMPLEMENTATION TIEImagingObject : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	OIAN_MARK_ATTRIBUTES attrib;
	Hyiedefs::TIEPoint *points;
	int pointsLen;
	char *text;
	TIEBitmap* image;
	
public:
	__fastcall TIEImagingObject(void);
	__fastcall virtual ~TIEImagingObject(void);
};


class DELPHICLASS TIEImagingAnnot;
class PASCALIMPLEMENTATION TIEImagingAnnot : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool fUserChanged;
	Classes::TList* fObjects;
	TIEImagingObject* __fastcall GetObject(int idx);
	int __fastcall GetObjectsCount(void);
	
public:
	__fastcall TIEImagingAnnot(void);
	__fastcall virtual ~TIEImagingAnnot(void);
	void __fastcall LoadFromStandardBuffer(void * buffer, int buflen);
	void __fastcall SaveToStandardBuffer(void * &Buffer, int &BufferLength);
	__property bool UserChanged = {read=fUserChanged, write=fUserChanged, nodefault};
	void __fastcall Clear(void);
	void __fastcall Assign(TIEImagingAnnot* Source);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall CopyToTImageEnVect(System::TObject* Target);
	void __fastcall CopyFromTImageEnVect(System::TObject* Target);
	void __fastcall DrawToBitmap(TIEBitmap* target, bool Antialias);
	__property TIEImagingObject* Objects[int idx] = {read=GetObject};
	__property int ObjectsCount = {read=GetObjectsCount, nodefault};
};


class PASCALIMPLEMENTATION TIEMask : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int fWidth;
	int fHeight;
	int fBitsperpixel;
	int fRowlen;
	Byte *fBits;
	int fX1;
	int fY1;
	int fX2;
	int fY2;
	#pragma pack(push, 1)
	Hyiedefs::TBitmapInfoHeader256 fBitmapInfoHeader1;
	#pragma pack(pop)
	
	Byte *fTmpBmp;
	int fTmpBmpWidth;
	int fTmpBmpHeight;
	void * *fTmpBmpScanline;
	bool fFull;
	int __fastcall DrawHorizontalLine(int Alpha, int xleft, int xright, int y);
	void __fastcall DrawSinglePolygon(int Alpha, Hyiedefs::PPointArray SelPoly, int SelPolyCount);
	void * __fastcall GetScanLine(int Row);
	
public:
	__fastcall TIEMask(void);
	__fastcall virtual ~TIEMask(void);
	void __fastcall SetPixel(int x, int y, int Alpha);
	int __fastcall GetPixel(int x, int y);
	void __fastcall AllocateBits(int width, int height, int bitsperpixel);
	void __fastcall Resize(int NewWidth, int NewHeight);
	void __fastcall FreeBits(void);
	void __fastcall CopyBitmap(Graphics::TBitmap* Dest, Graphics::TBitmap* Source, bool dstonlymask, bool 
		srconlymask);
	void __fastcall CopyIEBitmap(TIEBitmap* Dest, TIEBitmap* Source, bool dstonlymask, bool srconlymask
		, bool UseAlphaChannel);
	void __fastcall CopyIEBitmapAlpha(TIEBitmap* Dest, TIEBitmap* Source, bool dstonlymask, bool srconlymask
		);
	void __fastcall DrawPolygon(int Alpha, Hyiedefs::PPointArray SelPoly, int SelPolyCount);
	void __fastcall Fill(int Alpha);
	void __fastcall Empty(void);
	bool __fastcall IsPointInside(int x, int y);
	void __fastcall TranslateBitmap(int &ox, int &oy, bool CutSel);
	void __fastcall InvertCanvas(Graphics::TCanvas* Dest, int xDst, int yDst, int dxDst, int dyDst, int 
		xMask, int yMask, int dxMask, int dyMask);
	void __fastcall DrawOuter(Graphics::TBitmap* Dest, int xDst, int yDst, int dxDst, int dyDst, int xMask
		, int yMask, int dxMask, int dyMask);
	void __fastcall DrawOutline(Graphics::TCanvas* Dest, int xDst, int yDst, int dxDst, int dyDst, int 
		xMask, int yMask, int dxMask, int dyMask, int AniCounter, Graphics::TColor Color1, Graphics::TColor 
		Color2);
	void __fastcall Negative(int MaxVal);
	void __fastcall SyncFull(void);
	void __fastcall SyncRect(void);
	__property int Width = {read=fWidth, nodefault};
	__property int Height = {read=fHeight, nodefault};
	__property int BitsPerPixel = {read=fBitsperpixel, nodefault};
	__property int X1 = {read=fX1, write=fX1, nodefault};
	__property int Y1 = {read=fY1, write=fY1, nodefault};
	__property int X2 = {read=fX2, write=fX2, nodefault};
	__property int Y2 = {read=fY2, write=fY2, nodefault};
	bool __fastcall IsEmpty(void);
	__property void * ScanLine[int row] = {read=GetScanLine};
	void __fastcall Assign(TIEMask* Source);
	__property int Rowlen = {read=fRowlen, nodefault};
	__property Windows::PByte Bits = {read=fBits};
	__property bool Full = {read=fFull, write=fFull, nodefault};
};


typedef Set<TIEPixelFormat, ienull, ieCIELab>  TIEPixelFormatSet;

struct TIEFileBufferItem
{
	__int64 Pos;
	__int64 Size;
	void *ptr;
	TIEDataAccess access;
} ;

typedef TIEFileBufferItem *PIEFileBufferItem;

struct TIEGotBitmap
{
	unsigned Left;
	unsigned Top;
	int Width;
	int Height;
	Graphics::TBitmap* Bitmap;
	Classes::TList* maps;
} ;

typedef TIEGotBitmap *PIEGotBitmap;

struct TIEVirtualImageInfo
{
	__int64 pos;
	__int64 size;
	__int64 vsize;
	void *ptr;
	bool bitmapped;
	int orig_width;
	int orig_height;
	bool HasAlphaChannel;
	TIEDataAccess currentaccess;
	int ImWidth;
	int ImHeight;
	int ImBitCount;
	TIEPixelFormat ImPixelFormat;
} ;

typedef TIEVirtualImageInfo *PIEVirtualImageInfo;

struct TIEVirtualToReleaseBmp
{
	TIEVirtualImageInfo *info;
	TIEBitmap* bmp;
	int refcount;
} ;

typedef TIEVirtualToReleaseBmp *PIEVirtualToReleaseBmp;

struct TIEVirtualFreeBlock
{
	__int64 pos;
	unsigned vsize;
} ;

typedef TIEVirtualFreeBlock *PIEVirtualFreeBlock;

class DELPHICLASS TIEVirtualImageList;
class PASCALIMPLEMENTATION TIEVirtualImageList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TIEFileBuffer* fmemmap;
	__int64 fSize;
	int fImageCount;
	Classes::TList* fImageInfo;
	Classes::TList* fToDiscardList;
	Classes::TList* fFreeBlocks;
	__int64 fInsPos;
	unsigned fAllocationBlock;
	int fMaxImagesInMemory;
	int fImagesInMemory;
	Classes::TList* fBmpToRelease;
	unsigned fLastVImageSize;
	AnsiString fDescriptor;
	int __fastcall GetImageCount(void);
	int __fastcall BmpToReleaseIndexOf(void * image);
	
protected:
	void __fastcall ReAllocateBits(void);
	void __fastcall FreeBits(void);
	void __fastcall RemoveImageInfo(int idx);
	void __fastcall DiscardImage(PIEVirtualImageInfo info);
	void __fastcall DiscardOne(void);
	void __fastcall DiscardAll(void);
	void __fastcall MapImage(void * image, TIEDataAccess access);
	bool __fastcall AllocImage(void * image, int Width, int Height, int Bitcount, TIEPixelFormat PixelFormat
		, bool HasAlpha);
	void __fastcall DirectCopyToBitmap(void * image, TIEBitmap* bitmap);
	
public:
	__fastcall TIEVirtualImageList(const AnsiString Descriptor);
	__fastcall virtual ~TIEVirtualImageList(void);
	void __fastcall PrepareSpaceFor(int Width, int Height, int Bitcount, int ImageCount);
	void * __fastcall AddBlankImage(int Width, int Height, int Bitcount, TIEPixelFormat PixelFormat, bool 
		HasAlpha);
	void * __fastcall AddBitmap(Graphics::TBitmap* bitmap);
	void * __fastcall AddIEBitmap(TIEBaseBitmap* bitmap);
	void * __fastcall AddBitmapRect(Graphics::TBitmap* bitmap, int xsrc, int ysrc, int dxsrc, int dysrc
		);
	void __fastcall CopyToIEBitmap(void * image, TIEBitmap* bitmap);
	void __fastcall CopyFromIEBitmap(void * image, TIEBitmap* bitmap);
	TIEBitmap* __fastcall GetBitmap(void * image);
	void __fastcall ReleaseBitmap(TIEBitmap* bitmap, bool changed);
	void __fastcall ReleaseBitmapByImage(void * image, bool changed);
	__property int MaxImagesInMemory = {read=fMaxImagesInMemory, write=fMaxImagesInMemory, nodefault};
	__property int ImageCount = {read=GetImageCount, nodefault};
	void __fastcall Delete(void * image);
	int __fastcall GetImageWidth(void * image);
	int __fastcall GetImageHeight(void * image);
	int __fastcall GetImageOriginalWidth(void * image);
	int __fastcall GetImageOriginalHeight(void * image);
	void __fastcall SetImageOriginalWidth(void * image, int Value);
	void __fastcall SetImageOriginalHeight(void * image, int Value);
	int __fastcall GetImageBitCount(void * image);
	void * __fastcall GetImageBits(void * image);
	TIEPixelFormat __fastcall GetImagePixelFormat(void * image);
	void * __fastcall GetAlphaBits(void * image);
};


class PASCALIMPLEMENTATION TIEDibbitmap : public TIEBaseBitmap 
{
	typedef TIEBaseBitmap inherited;
	
private:
	unsigned fWidth;
	unsigned fHeight;
	unsigned fBitCount;
	unsigned fRowLen;
	unsigned fHDC;
	unsigned fDIB;
	#pragma pack(push, 1)
	Hyiedefs::TBitmapInfoHeader256 fBitmapInfoHeader1;
	#pragma pack(pop)
	
	void *fBits;
	
protected:
	virtual int __fastcall GetBitCount(void);
	virtual int __fastcall GetWidth(void);
	virtual int __fastcall GetHeight(void);
	virtual TIEPixelFormat __fastcall GetPixelFormat(void);
	virtual int __fastcall GetRowLen(void);
	virtual void * __fastcall GetScanLine(int row);
	virtual Hyiedefs::TRGB __fastcall GetPalette(int index);
	virtual void __fastcall SetPalette(int index, Hyiedefs::TRGB Value);
	virtual int __fastcall GetPaletteLen(void);
	
public:
	__fastcall TIEDibbitmap(void);
	__fastcall virtual ~TIEDibbitmap(void);
	void __fastcall AllocateBits(unsigned BmpWidth, unsigned BmpHeight, unsigned BmpBitCount);
	virtual void __fastcall Allocate(int ImageWidth, int ImageHeight, TIEPixelFormat ImagePixelFormat);
		
	void __fastcall FreeBits(void);
	__property unsigned HDC = {read=fHDC, nodefault};
	__property unsigned DIB = {read=fDIB, nodefault};
	__property unsigned Width = {read=fWidth, nodefault};
	__property unsigned Height = {read=fHeight, nodefault};
	__property unsigned BitCount = {read=fBitCount, nodefault};
	__property void * Scanline[int row] = {read=GetScanLine};
	__property void * Bits = {read=fBits};
	__property int Rowlen = {read=GetRowLen, nodefault};
	void __fastcall CopyToTBitmap(Graphics::TBitmap* Dest);
	virtual void __fastcall Assign(System::TObject* Source);
};


class DELPHICLASS TIEWorkBitmap;
class PASCALIMPLEMENTATION TIEWorkBitmap : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int fWidth;
	int fHeight;
	int fBitCount;
	int fRowLen;
	void *fBits;
	void * __fastcall GetScanline(int row);
	
public:
	__fastcall TIEWorkBitmap(int BmpWidth, int BmpHeight, int BmpBitCount);
	__fastcall virtual ~TIEWorkBitmap(void);
	void __fastcall AllocateBits(int BmpWidth, int BmpHeight, int BmpBitCount);
	void __fastcall FreeBits(void);
	__property int Width = {read=fWidth, nodefault};
	__property int Height = {read=fHeight, nodefault};
	__property int BitCount = {read=fBitCount, nodefault};
	__property void * Scanline[int row] = {read=GetScanline};
	__property void * Bits = {read=fBits};
	__property int Rowlen = {read=fRowLen, nodefault};
	Windows::PByte __fastcall GetPByte(int row, int col);
	Hyiedefs::PRGB __fastcall GetPRGB(int row, int col);
	Windows::PDouble __fastcall GetPDouble(int row, int col);
	Windows::PSingle __fastcall GetPSingle(int row, int col);
	Windows::PInteger __fastcall GetPInteger(int row, int col);
	void __fastcall SetBit(int row, int col, int value);
};


class DELPHICLASS TIETIFTagsReader;
class PASCALIMPLEMENTATION TIETIFTagsReader : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStream* fFileStream;
	Classes::TStream* fStream;
	TTIFFEnv fTIFFEnv;
	int fNumi;
	
public:
	__fastcall TIETIFTagsReader(const AnsiString FileName, int ImageIndex);
	__fastcall TIETIFTagsReader(Classes::TStream* Stream, int ImageIndex);
	__fastcall TIETIFTagsReader(TIETIFTagsReader* tagReader, int IFDTag);
	__fastcall virtual ~TIETIFTagsReader(void);
	__property int ImageCount = {read=fNumi, nodefault};
	bool __fastcall TagExists(int Tag);
	int __fastcall TagLength(int Tag);
	int __fastcall GetInteger(int Tag);
	int __fastcall GetIntegerIndexed(int Tag, int index);
	double __fastcall GetRational(int Tag);
	double __fastcall GetRationalIndexed(int Tag, int index);
	int __fastcall GetIntegerArray(int Tag, Hyiedefs::pIntegerArray &ar);
	void * __fastcall GetRawData(int Tag);
	AnsiString __fastcall GetString(int Tag);
	AnsiString __fastcall GetMiniString(int Tag);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIETIFTagsReader(void) : System::TObject() { }
	#pragma option pop
	
};


class DELPHICLASS TIETagsHandler;
class PASCALIMPLEMENTATION TIETagsHandler : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TMemoryStream* fData;
	TTIFFEnv fTIFFEnv;
	
public:
	__fastcall TIETagsHandler(void);
	__fastcall virtual ~TIETagsHandler(void);
	__property Classes::TMemoryStream* Data = {read=fData};
	void __fastcall Update(void);
	bool __fastcall TagExists(int Tag);
	int __fastcall TagLength(int Tag);
	int __fastcall GetInteger(int Tag);
	int __fastcall GetIntegerIndexed(int Tag, int index);
	double __fastcall GetRational(int Tag);
	double __fastcall GetRationalIndexed(int Tag, int index);
	int __fastcall GetIntegerArray(int Tag, Hyiedefs::pIntegerArray &ar);
	void * __fastcall GetRawData(int Tag);
	AnsiString __fastcall GetString(int Tag);
	AnsiString __fastcall GetMiniString(int Tag);
};


#pragma option push -b-
enum TIETagType { ttUnknown, ttByte, ttAscii, ttShort, ttLong, ttRational, ttSByte, ttUndefined, ttSShort, 
	ttSLong, ttSRational, ttFloat, ttDouble };
#pragma option pop

class DELPHICLASS TIETIFFHandler;
class PASCALIMPLEMENTATION TIETIFFHandler : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool fIsMotorola;
	Classes::TList* fPages;
	bool __fastcall ReadHeader(Classes::TStream* Stream);
	bool __fastcall ReadIFD(Classes::TStream* Stream, int insertPos);
	Word __fastcall xword(Word value);
	unsigned __fastcall xdword(unsigned value);
	int __fastcall GetIntegerByCode(int page, int tagcode, int idx);
	void __fastcall SortTags(int pageIndex);
	void __fastcall SimpleDeleteTag(int pageIndex, int tagIndex);
	void * __fastcall GetValueRAWEx(int pageIndex, int tagIndex, int arrayIndex, int &tagType);
	
public:
	__fastcall TIETIFFHandler(void);
	__fastcall virtual ~TIETIFFHandler(void);
	bool __fastcall ReadFile(const AnsiString FileName);
	bool __fastcall ReadStream(Classes::TStream* Stream);
	bool __fastcall InsertTIFFStream(Classes::TStream* Stream, int pageIndex);
	bool __fastcall InsertTIFFFile(const AnsiString FileName, int pageIndex);
	bool __fastcall InsertPageAsFile(const AnsiString FileName, int pageIndex);
	bool __fastcall InsertPageAsStream(Classes::TStream* Stream, int pageIndex);
	bool __fastcall InsertPageAsImage(System::TObject* viewer, int pageIndex);
	void __fastcall WriteFile(const AnsiString FileName);
	void __fastcall WriteStream(Classes::TStream* Stream);
	void __fastcall FreeData(void);
	int __fastcall GetTagsCount(int pageIndex);
	int __fastcall GetPagesCount(void);
	int __fastcall GetTagCode(int pageIndex, int tagIndex);
	TIETagType __fastcall GetTagType(int pageIndex, int tagIndex);
	int __fastcall GetTagLength(int pageIndex, int tagIndex);
	int __fastcall GetTagLengthInBytes(int pageIndex, int tagIndex);
	int __fastcall FindTag(int pageIndex, int tagCode);
	void __fastcall DeleteTag(int pageIndex, int tagIndex);
	AnsiString __fastcall GetTagDescription(int pageIndex, int tagIndex);
	void __fastcall ChangeTagCode(int pageIndex, int tagIndex, int newCode);
	int __fastcall GetInteger(int pageIndex, int tagIndex, int arrayIndex);
	AnsiString __fastcall GetString(int pageIndex, int tagIndex);
	double __fastcall GetFloat(int pageIndex, int tagIndex, int arrayIndex);
	Variant __fastcall GetValue(int pageIndex, int tagIndex, int arrayIndex);
	void __fastcall SaveTagToFile(int pageIndex, int tagIndex, const AnsiString fileName);
	void * __fastcall GetValueRAW(int pageIndex, int tagIndex, int arrayIndex);
	void __fastcall SetValue(int pageIndex, int tagCode, TIETagType tagType, const Variant &value);
	void __fastcall SetValueRAW(int pageIndex, int tagCode, TIETagType tagType, int dataNum, void * buffer
		);
	void __fastcall DeletePage(int pageIndex);
};


class DELPHICLASS TIEGraphicBase;
class PASCALIMPLEMENTATION TIEGraphicBase : public Graphics::TGraphic 
{
	typedef Graphics::TGraphic inherited;
	
private:
	System::TObject* fio;
	TIEBitmap* bmp;
	int fFiletype;
	Hyiedefs::TResampleFilter fResampleFilter;
	
protected:
	virtual void __fastcall Draw(Graphics::TCanvas* ACanvas, const Windows::TRect &Rect);
	virtual bool __fastcall GetEmpty(void);
	virtual int __fastcall GetHeight(void);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetWidth(int Value);
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	virtual void __fastcall ReadData(Classes::TStream* Stream);
	
public:
	__fastcall virtual TIEGraphicBase(void);
	__fastcall virtual ~TIEGraphicBase(void);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromClipboardFormat(Word AFormat, unsigned AData, HPALETTE APalette);
	virtual void __fastcall SaveToClipboardFormat(Word &AFormat, unsigned &AData, HPALETTE &APalette);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::TObject* IO = {read=fio};
	__property Hyiedefs::TResampleFilter ResampleFilter = {read=fResampleFilter, write=fResampleFilter, 
		nodefault};
};


class DELPHICLASS TIEMemStream;
class PASCALIMPLEMENTATION TIEMemStream : public Classes::TCustomMemoryStream 
{
	typedef Classes::TCustomMemoryStream inherited;
	
public:
	__fastcall TIEMemStream(void * Ptr, int Size);
	virtual void __fastcall SetSize(int NewSize);
	virtual int __fastcall Write(const void *Buffer, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIEMemStream(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEICC;
class PASCALIMPLEMENTATION TIEICC : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Byte *fRaw;
	int fRawLen;
	void *fProfile;
	TIEMemStream* fProfileStream;
	unsigned fMSProfile;
	bool fApplied;
	void *fTransform;
	int fInputFormat;
	int fOutputFormat;
	TIEICC* fDestination;
	int fIntent;
	int fFlags;
	unsigned fMSTransform;
	void __fastcall OpenProfileFromRaw(void);
	void __fastcall CloseProfileFromRaw(void);
	
public:
	__fastcall TIEICC(void);
	__fastcall virtual ~TIEICC(void);
	void __fastcall LoadFromBuffer(void * buffer, int bufferlen);
	void __fastcall Clear(void);
	void __fastcall SaveToStream(Classes::TStream* Stream, bool StandardICC);
	void __fastcall LoadFromStream(Classes::TStream* Stream, bool StandardICC);
	void __fastcall Assign(TIEICC* source);
	bool __fastcall IsValid(void);
	__property bool IsApplied = {read=fApplied, nodefault};
	__property Windows::PByte Raw = {read=fRaw};
	__property int RawLength = {read=fRawLen, nodefault};
	void __fastcall Assign_sRGBProfile(void);
	void __fastcall Assign_LabProfile(double WhitePoint_x, double WhitePoint_y, double WhitePoint_Y_);
	void __fastcall Assign_LabProfileFromTemp(int TempK);
	void __fastcall Assign_LabProfileD50(void);
	void __fastcall Assign_XYZProfile(void);
	void __fastcall FreeTransform(void);
	bool __fastcall Transform(TIEICC* Destination, int InputFormat, int OutputFormat, int Intent, int Flags
		, void * InputBuffer, void * OutputBuffer, int ImageWidth);
	bool __fastcall Apply(TIEBitmap* SourceBitmap, int SourceFormat, TIEBitmap* DestinationBitmap, int 
		DestinationFormat, TIEICC* DestinationProfile, int Intent, int Flags);
	bool __fastcall Apply2(TIEBitmap* Bitmap, int SourceFormat, int DestinationFormat, TIEICC* DestinationProfile
		, int Intent, int Flags);
};


class DELPHICLASS TIEBufferedReadStream;
class PASCALIMPLEMENTATION TIEBufferedReadStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	Classes::TStream* fStream;
	int fBufferSize;
	Byte *fMemory;
	__int64 fPosition;
	int fPositionBuf;
	__int64 fSize;
	void __fastcall AllocBufferSize(int BufferSize);
	void __fastcall LoadData(void);
	
public:
	__fastcall TIEBufferedReadStream(Classes::TStream* InputStream, int BufferSize);
	__fastcall virtual ~TIEBufferedReadStream(void);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin);
};


class DELPHICLASS TIEBufferedWriteStream;
class PASCALIMPLEMENTATION TIEBufferedWriteStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	Classes::TStream* fStream;
	Byte *fMemory;
	int fBufferSize;
	int fBufferPos;
	void __fastcall FlushData(void);
	
public:
	__fastcall TIEBufferedWriteStream(Classes::TStream* InputStream, int BufferSize);
	__fastcall virtual ~TIEBufferedWriteStream(void);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin);
};


class DELPHICLASS TIETIFFImage;
class PASCALIMPLEMENTATION TIETIFFImage : public TIEGraphicBase 
{
	typedef TIEGraphicBase inherited;
	
public:
	#pragma option push -w-inl
	/* TIEGraphicBase.Create */ inline __fastcall virtual TIETIFFImage(void) : TIEGraphicBase() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEGraphicBase.Destroy */ inline __fastcall virtual ~TIETIFFImage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEGIFImage;
class PASCALIMPLEMENTATION TIEGIFImage : public TIEGraphicBase 
{
	typedef TIEGraphicBase inherited;
	
public:
	#pragma option push -w-inl
	/* TIEGraphicBase.Create */ inline __fastcall virtual TIEGIFImage(void) : TIEGraphicBase() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEGraphicBase.Destroy */ inline __fastcall virtual ~TIEGIFImage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEJpegImage;
class PASCALIMPLEMENTATION TIEJpegImage : public TIEGraphicBase 
{
	typedef TIEGraphicBase inherited;
	
public:
	#pragma option push -w-inl
	/* TIEGraphicBase.Create */ inline __fastcall virtual TIEJpegImage(void) : TIEGraphicBase() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEGraphicBase.Destroy */ inline __fastcall virtual ~TIEJpegImage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEPCXImage;
class PASCALIMPLEMENTATION TIEPCXImage : public TIEGraphicBase 
{
	typedef TIEGraphicBase inherited;
	
public:
	#pragma option push -w-inl
	/* TIEGraphicBase.Create */ inline __fastcall virtual TIEPCXImage(void) : TIEGraphicBase() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEGraphicBase.Destroy */ inline __fastcall virtual ~TIEPCXImage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEBMPImage;
class PASCALIMPLEMENTATION TIEBMPImage : public TIEGraphicBase 
{
	typedef TIEGraphicBase inherited;
	
public:
	#pragma option push -w-inl
	/* TIEGraphicBase.Create */ inline __fastcall virtual TIEBMPImage(void) : TIEGraphicBase() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEGraphicBase.Destroy */ inline __fastcall virtual ~TIEBMPImage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEICOImage;
class PASCALIMPLEMENTATION TIEICOImage : public TIEGraphicBase 
{
	typedef TIEGraphicBase inherited;
	
public:
	#pragma option push -w-inl
	/* TIEGraphicBase.Create */ inline __fastcall virtual TIEICOImage(void) : TIEGraphicBase() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEGraphicBase.Destroy */ inline __fastcall virtual ~TIEICOImage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEPNGImage;
class PASCALIMPLEMENTATION TIEPNGImage : public TIEGraphicBase 
{
	typedef TIEGraphicBase inherited;
	
public:
	#pragma option push -w-inl
	/* TIEGraphicBase.Create */ inline __fastcall virtual TIEPNGImage(void) : TIEGraphicBase() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEGraphicBase.Destroy */ inline __fastcall virtual ~TIEPNGImage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIETGAImage;
class PASCALIMPLEMENTATION TIETGAImage : public TIEGraphicBase 
{
	typedef TIEGraphicBase inherited;
	
public:
	#pragma option push -w-inl
	/* TIEGraphicBase.Create */ inline __fastcall virtual TIETGAImage(void) : TIEGraphicBase() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEGraphicBase.Destroy */ inline __fastcall virtual ~TIETGAImage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEPXMImage;
class PASCALIMPLEMENTATION TIEPXMImage : public TIEGraphicBase 
{
	typedef TIEGraphicBase inherited;
	
public:
	#pragma option push -w-inl
	/* TIEGraphicBase.Create */ inline __fastcall virtual TIEPXMImage(void) : TIEGraphicBase() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEGraphicBase.Destroy */ inline __fastcall virtual ~TIEPXMImage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEJP2Image;
class PASCALIMPLEMENTATION TIEJP2Image : public TIEGraphicBase 
{
	typedef TIEGraphicBase inherited;
	
public:
	#pragma option push -w-inl
	/* TIEGraphicBase.Create */ inline __fastcall virtual TIEJP2Image(void) : TIEGraphicBase() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEGraphicBase.Destroy */ inline __fastcall virtual ~TIEJP2Image(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEJ2KImage;
class PASCALIMPLEMENTATION TIEJ2KImage : public TIEGraphicBase 
{
	typedef TIEGraphicBase inherited;
	
public:
	#pragma option push -w-inl
	/* TIEGraphicBase.Create */ inline __fastcall virtual TIEJ2KImage(void) : TIEGraphicBase() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIEGraphicBase.Destroy */ inline __fastcall virtual ~TIEJ2KImage(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TIEShadowType { iestNone, iestSolid, iestSmooth1, iestSmooth2 };
#pragma option pop

typedef void __fastcall (__closure *TIEMultiCallBack)(TIEBitmap* Bitmap, System::TObject* &IOParams)
	;

class DELPHICLASS TIEPDFObject;
class PASCALIMPLEMENTATION TIEPDFObject : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Index;
	int Position;
	bool DontFree;
	__fastcall TIEPDFObject(void);
	__fastcall virtual ~TIEPDFObject(void);
	virtual void __fastcall Write(Classes::TStream* Stream) = 0 ;
};


class DELPHICLASS TIEPDFRefObject;
class PASCALIMPLEMENTATION TIEPDFRefObject : public TIEPDFObject 
{
	typedef TIEPDFObject inherited;
	
public:
	int ObjectNumber;
	int GenerationNumber;
	__fastcall TIEPDFRefObject(int ObjNumber, int GenNumber);
	virtual void __fastcall Write(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TIEPDFObject.Destroy */ inline __fastcall virtual ~TIEPDFRefObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEPDFBooleanObject;
class PASCALIMPLEMENTATION TIEPDFBooleanObject : public TIEPDFObject 
{
	typedef TIEPDFObject inherited;
	
public:
	bool Value;
	__fastcall TIEPDFBooleanObject(bool vv);
	virtual void __fastcall Write(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TIEPDFObject.Destroy */ inline __fastcall virtual ~TIEPDFBooleanObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEPDFNumericObject;
class PASCALIMPLEMENTATION TIEPDFNumericObject : public TIEPDFObject 
{
	typedef TIEPDFObject inherited;
	
public:
	double Value;
	__fastcall TIEPDFNumericObject(double vv);
	virtual void __fastcall Write(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TIEPDFObject.Destroy */ inline __fastcall virtual ~TIEPDFNumericObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEPDFStringObject;
class PASCALIMPLEMENTATION TIEPDFStringObject : public TIEPDFObject 
{
	typedef TIEPDFObject inherited;
	
public:
	AnsiString Value;
	__fastcall TIEPDFStringObject(AnsiString vv);
	virtual void __fastcall Write(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TIEPDFObject.Destroy */ inline __fastcall virtual ~TIEPDFStringObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEPDFNameObject;
class PASCALIMPLEMENTATION TIEPDFNameObject : public TIEPDFObject 
{
	typedef TIEPDFObject inherited;
	
public:
	AnsiString Value;
	__fastcall TIEPDFNameObject(AnsiString vv);
	virtual void __fastcall Write(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TIEPDFObject.Destroy */ inline __fastcall virtual ~TIEPDFNameObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEPDFArrayObject;
class PASCALIMPLEMENTATION TIEPDFArrayObject : public TIEPDFObject 
{
	typedef TIEPDFObject inherited;
	
public:
	Classes::TList* Items;
	__fastcall TIEPDFArrayObject(void);
	__fastcall virtual ~TIEPDFArrayObject(void);
	virtual void __fastcall Write(Classes::TStream* Stream);
};


class DELPHICLASS TIEPDFDictionaryObject;
class PASCALIMPLEMENTATION TIEPDFDictionaryObject : public TIEPDFObject 
{
	typedef TIEPDFObject inherited;
	
public:
	Classes::TStringList* items;
	__fastcall TIEPDFDictionaryObject(void);
	__fastcall virtual ~TIEPDFDictionaryObject(void);
	virtual void __fastcall Write(Classes::TStream* Stream);
};


class DELPHICLASS TIEPDFStreamObject;
class PASCALIMPLEMENTATION TIEPDFStreamObject : public TIEPDFObject 
{
	typedef TIEPDFObject inherited;
	
public:
	void *data;
	int length;
	TIEPDFDictionaryObject* dict;
	__fastcall TIEPDFStreamObject(void);
	__fastcall TIEPDFStreamObject(void * copydata, int copylength);
	__fastcall virtual ~TIEPDFStreamObject(void);
	virtual void __fastcall Write(Classes::TStream* Stream);
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint IEAnnotImageEmbedded = 0x1;
static const Shortint IEAnnotImageReference = 0x2;
static const Shortint IEAnnotStraightLine = 0x3;
static const Shortint IEAnnotFreehandLine = 0x4;
static const Shortint IEAnnotHollowRectangle = 0x5;
static const Shortint IEAnnotFilledRectangle = 0x6;
static const Shortint IEAnnotTypedText = 0x7;
static const Shortint IEAnnotTextFromFile = 0x8;
static const Shortint IEAnnotTextStamp = 0x9;
static const Shortint IEAnnotAttachANote = 0xa;
static const Shortint IEAnnotForm = 0xc;
static const Shortint IEAnnotOCRRegion = 0xd;
static const Shortint IEMAXCHANNELS = 0x4;
extern PACKAGE Byte iebitmask1[8];
extern PACKAGE TIEDialogCenter IEDefDialogCenter;
extern PACKAGE int IEDefMinFileSize;
extern PACKAGE bool __fastcall IEDirectoryExists(const AnsiString Name);
extern PACKAGE void __fastcall IEForceDirectories(AnsiString Dir);
extern PACKAGE int __fastcall _GetBitCount(int b);
extern PACKAGE int __fastcall _NColToBitsPixel(int NCol);
extern PACKAGE int __fastcall IEBitmapRowLen(int Width, int BitCount, int align);
extern PACKAGE int __fastcall _Pixelformat2BitCount(Graphics::TPixelFormat PixelFormat);
extern PACKAGE TIEPixelFormat __fastcall IEVCLPixelFormat2ImageEnPixelFormat(Graphics::TPixelFormat 
	PixelFormat);
extern PACKAGE int __fastcall _PixelFormat2RowLen(int Width, Graphics::TPixelFormat PixelFormat);
extern PACKAGE Graphics::TPixelFormat __fastcall _Bitcount2Pixelformat(int Bitcount);
extern PACKAGE void __fastcall ReverseBitsB(Byte &inp);
extern PACKAGE void __fastcall ReverseBits(unsigned &inp);
extern PACKAGE Extended __fastcall IEPower(Extended Base, Extended Exponent);
extern PACKAGE double __fastcall IEPower2(const double Base, const double Exponent);
extern PACKAGE void __fastcall DrawDibDrawEmu(unsigned hdd, unsigned hDC, int xDst, int yDst, int dxDst
	, int dyDst, tagBITMAPINFOHEADER &lpbi, void * Bits, int xSrc, int ySrc, int dxSrc, int dySrc, unsigned 
	wFlags);
extern PACKAGE void __fastcall DrawDib(unsigned hDC, int xDst, int yDst, int dxDst, int dyDst, tagBITMAPINFOHEADER 
	&lpbi, void * Bits, int xSrc, int ySrc, int dxSrc, int dySrc);
extern PACKAGE Word __fastcall IESwapWord(Word i);
extern PACKAGE int __fastcall IESwapDWord(int i);
extern PACKAGE void __fastcall _CastPolySelCC(const int x1, const int y1, int &x2, int &y2);
extern PACKAGE bool __fastcall _RectXRect(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int 
	bx2, int by2);
extern PACKAGE int __fastcall _RectPRect(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2
	, int by2);
extern PACKAGE bool __fastcall _InRect(int xx, int yy, int x1, int y1, int x2, int y2);
extern PACKAGE bool __fastcall _InRectO(int xx, int yy, int x1, int y1, int x2, int y2);
extern PACKAGE int __fastcall _getfilesize(const AnsiString nf);
extern PACKAGE int __fastcall IEFindHandle(Classes::TComponent* cmp);
extern PACKAGE void __fastcall IERightShadow(Graphics::TCanvas* Canvas, int x1, int y1, int x2, int 
	y2, TIEShadowType st, Graphics::TColor dstColor);
extern PACKAGE void __fastcall IEBottomShadow(Graphics::TCanvas* Canvas, int x1, int y1, int x2, int 
	y2, TIEShadowType st, Graphics::TColor dstColor);
extern PACKAGE void __fastcall SaveStringToStream(Classes::TStream* Stream, const AnsiString ss);
extern PACKAGE void __fastcall LoadStringFromStream(Classes::TStream* Stream, AnsiString &ss);
extern PACKAGE void __fastcall SaveStringListToStream(Classes::TStream* Stream, Classes::TStringList* 
	sl);
extern PACKAGE void __fastcall LoadStringListFromStream(Classes::TStream* Stream, Classes::TStringList* 
	sl);
extern PACKAGE int __fastcall _GetNumCol(int BitsPerSample, int SamplesPerPixel);
extern PACKAGE void __fastcall IESetTranslationWord(const Hyiedefs::TMsgLanguage lang, const Hyiedefs::TMsgLanguageWords 
	msg, const AnsiString trans);
extern PACKAGE AnsiString __fastcall iemsg(const Hyiedefs::TMsgLanguageWords msg, const Hyiedefs::TMsgLanguage 
	lang);
extern PACKAGE int __fastcall IEFloor(Extended X);
extern PACKAGE double __fastcall _DistPoint2Point(int x1, int y1, int x2, int y2);
extern PACKAGE double __fastcall _DistPoint2Line(int xp, int yp, int x1, int y1, int x2, int y2);
extern PACKAGE double __fastcall _DistPoint2Seg(int xp, int yp, int x1, int y1, int x2, int y2);
extern PACKAGE double __fastcall _DistPoint2Polyline(int x, int y, Hyiedefs::PPointArray PolyPoints, 
	int PolyPointsCount, int ToSubX, int ToSubY, int ToAddX, int ToAddY, double ToMulX, double ToMulY);
	
extern PACKAGE Byte __fastcall IEMMXSupported(void);
extern PACKAGE int __fastcall IEAdd64(unsigned op1_lo, unsigned op1_hi, unsigned op2_lo, unsigned op2_hi
	, PDWORD result_lo, PDWORD result_hi);
extern PACKAGE bool __fastcall IEGreater64(unsigned op1_lo, unsigned op1_hi, unsigned op2_lo, unsigned 
	op2_hi);
extern PACKAGE void __fastcall IEMul64(unsigned op1, unsigned op2, PDWORD resultlo, PDWORD resulthi)
	;
extern PACKAGE void __fastcall SafeStreamWrite(Classes::TStream* Stream, bool &Aborting, const void 
	*Buffer, int Count);
extern PACKAGE void __fastcall IEBitmapMapXCopy(Windows::PByte map, unsigned maprowlen, unsigned mapbitcount
	, Graphics::TBitmap* bitmap, unsigned mapx, unsigned mapy, unsigned bitmapx, unsigned bitmapy, unsigned 
	dx, unsigned dy, int dir);
extern PACKAGE void __fastcall SaveEXIFToStandardBuffer(System::TObject* params, void * &Buffer, int 
	&BufferLength);
extern PACKAGE bool __fastcall LoadEXIFFromStandardBuffer(void * Buffer, int BufferLength, System::TObject* 
	params);
extern PACKAGE __int64 __fastcall IESearchEXIFInfo(Classes::TStream* Stream);
extern PACKAGE bool __fastcall IELoadEXIFFromTIFF(Classes::TStream* Stream, System::TObject* params)
	;
extern PACKAGE bool __fastcall IEIs_Win2000_ME_XP(void);
extern PACKAGE bool __fastcall IEIs_XP(void);
extern PACKAGE bool __fastcall IEIs_98(void);
extern PACKAGE Extended __fastcall IEStrToFloatDef(AnsiString s, Extended Def);
extern PACKAGE Hyiedefs::TCIELab __fastcall IERGB2CIELAB(Hyiedefs::TRGB rgb);
extern PACKAGE Hyiedefs::TRGB __fastcall IECIELAB2RGB(const Hyiedefs::TCIELab lab);
extern PACKAGE void __fastcall IEDraw3DRect(Graphics::TCanvas* Canvas, int x1, int y1, int x2, int y2
	, Graphics::TColor cl1, Graphics::TColor cl2);
extern PACKAGE void __fastcall IEBlendRGBA(Hyiedefs::TRGBA &src, Hyiedefs::TRGBA &dst, TIERenderOperation 
	RenderOperation);
extern PACKAGE void __fastcall IEBlend(Hyiedefs::TRGB &src, Hyiedefs::TRGB &dst, TIERenderOperation 
	RenderOperation);
extern PACKAGE void __fastcall IEDrawHint(Graphics::TCanvas* Canvas, int &x, int &y, const AnsiString 
	ss, Graphics::TFont* Font, Graphics::TBrush* Brush, Graphics::TBitmap* &SaveBitmap, int MaxWidth, int 
	MaxHeight, Graphics::TColor Border1, Graphics::TColor Border2);
extern PACKAGE bool __fastcall IEDrawDibClose(unsigned hdd);
extern PACKAGE bool __fastcall IEDrawDibDraw(unsigned hdd, unsigned hDC, int xDst, int yDst, int dxDst
	, int dyDst, tagBITMAPINFOHEADER &lpbi, void * Bits, int xSrc, int ySrc, int dxSrc, int dySrc, unsigned 
	wFlags);
extern PACKAGE unsigned __fastcall IEDrawDibOpen(void);
extern PACKAGE unsigned __fastcall IEDrawDibRealize(unsigned hdd, unsigned hDC, BOOL fBackground);
extern PACKAGE void __fastcall IECenterWindow(HWND Wnd);
extern PACKAGE int __fastcall IEGetFreeMemory(void);
extern PACKAGE void __fastcall IESetplim(Windows::TRect &plim, int x, int y);
extern PACKAGE Extended __fastcall IEArcCos(Extended X);
extern PACKAGE double __fastcall IEAngle(int x1, int y1, int x2, int y2, int x3, int y3);
extern PACKAGE Graphics::TFontStyles __fastcall IEExtractStylesFromLogFont(Windows::PLogFontA logfont
	);
extern PACKAGE AnsiString __fastcall IEConvertGUIDToString(System::PGUID g);
extern PACKAGE void __fastcall IEConvertStringToGUID(AnsiString invar, System::PGUID gg);
extern PACKAGE void __fastcall IEResetPrinter(void);
extern PACKAGE void __fastcall IEFitResample(int owidth, int oheight, int fwidth, int fheight, int &
	rwidth, int &rheight);
extern PACKAGE int __fastcall IEASCII85EncodeBlock(Windows::PByte &inbytes, int buflen, char * &outstr
	, int &asciilen);
extern PACKAGE int __fastcall IEASCII85DecodeBlock(char * &instr, int buflen, Windows::PByte &outbytes
	);
extern PACKAGE int __fastcall IEPSRunLengthEncode(Sysutils::PByteArray inbytes, int inlen, Sysutils::PByteArray 
	outbytes);
extern PACKAGE void __fastcall IEWriteStrLn(Classes::TStream* s, AnsiString ss);
extern PACKAGE void __fastcall IERegisterFormats(void);
extern PACKAGE void __fastcall IEUnregisterFormats(void);
extern PACKAGE void __fastcall iepdf_WriteLn(Classes::TStream* Stream, AnsiString line);
extern PACKAGE void __fastcall iepdf_Write(Classes::TStream* Stream, AnsiString line);
extern PACKAGE void __fastcall iepdf_WriteHeader(Classes::TStream* Stream);
extern PACKAGE void __fastcall iepdf_WriteFooter(Classes::TStream* Stream, Classes::TList* IndirectObjects
	, TIEPDFObject* info);
extern PACKAGE void __fastcall iepdf_AddIndirectObject(Classes::TList* IndirectObjects, TIEPDFObject* 
	obj);
extern PACKAGE void __fastcall iepdf_WriteIndirectObjects(Classes::TStream* Stream, Classes::TList* 
	IndirectObjects);
extern PACKAGE TIEPDFDictionaryObject* __fastcall iepdf_AddCatalog(Classes::TList* IndirectObjects);
	
extern PACKAGE TIEPDFDictionaryObject* __fastcall iepdf_AddPageTree(Classes::TList* IndirectObjects, 
	Classes::TList* pages);
extern PACKAGE void __fastcall iepdf_AddPage(Classes::TList* IndirectObjects, Classes::TList* pages, 
	TIEPDFDictionaryObject* Resources, TIEPDFArrayObject* MediaBox, int Content);
extern PACKAGE bool __fastcall IEIsRemoteSession(void);
extern PACKAGE void __fastcall IEBezier2D4Controls(const Windows::TPoint &p0, const Windows::TPoint 
	&c0, const Windows::TPoint &c1, const Windows::TPoint &p1, Hyiedefs::PPointArray pResultArray, int 
	nSteps);
extern PACKAGE void __fastcall IEencode64(Classes::TStream* infile, TextFile &outfile, int linesize)
	;
extern PACKAGE BOOL __fastcall IESetScrollRange(HWND hWnd, int nBar, int nMinPos, int nMaxPos, BOOL 
	bRedraw, bool flat);
extern PACKAGE int __fastcall IESetScrollInfo(HWND hWnd, int BarFlag, const tagSCROLLINFO &ScrollInfo
	, BOOL Redraw, bool flat);
extern PACKAGE void __fastcall IESetSBPageSize(unsigned HScrollBar, int fnBar, int PageSize, bool Redraw
	, bool flat);
extern PACKAGE int __fastcall IESetScrollPos(HWND hWnd, int nBar, int nPos, BOOL bRedraw, bool flat)
	;
extern PACKAGE BOOL __fastcall IEEnableScrollBar(HWND hWnd, unsigned wSBflags, unsigned wArrows, bool 
	flat);
extern PACKAGE BOOL __fastcall IEShowScrollBar(HWND hWnd, int wBar, BOOL bShow, bool flat);
extern PACKAGE int __fastcall IEIFI(bool cond, int val1, int val2);
extern PACKAGE double __fastcall IEIFD(bool cond, double val1, double val2);
extern PACKAGE void __fastcall IEAdjustEXIFOrientation(TIEBitmap* Bitmap, int Orientation);
extern PACKAGE Word __fastcall IECSwapWord(Word i, bool sc);
extern PACKAGE int __fastcall IECSwapDWord(int i, bool sc);
extern PACKAGE void __fastcall IEQuickSort(int ItemsCount, TIECompareFunction CompareFunction, TIESwapFunction 
	SwapFunction);
extern PACKAGE AnsiString __fastcall IEGetTempFileName(const AnsiString Descriptor, const AnsiString 
	Directory);
extern PACKAGE AnsiString __fastcall IEGetTempFileName2(void);
extern PACKAGE void * __fastcall IEGetMem(unsigned ASize);
extern PACKAGE void __fastcall IEFreeMem(void *P);
extern PACKAGE AnsiString __fastcall IEFloatToStr(Extended Value);
extern PACKAGE AnsiString __fastcall IERemoveCtrlChars(const AnsiString text);
extern PACKAGE AnsiString __fastcall IErgb2str(Hyiedefs::TRGB c);
extern PACKAGE AnsiString __fastcall IEbool2str(bool v);
extern PACKAGE Hyiedefs::TRGB __fastcall IEstr2rgb(const AnsiString rgbstr);
extern PACKAGE bool __fastcall IEstr2bool(const AnsiString v);
extern PACKAGE void __fastcall IESetGrayPalette(Graphics::TBitmap* Bitmap);
extern PACKAGE bool __fastcall IEIsGrayPalette(Graphics::TBitmap* Bitmap);
extern PACKAGE void __fastcall IECopyTBitmapPaletteToTIEBitmap(Graphics::TBitmap* source, TIEBitmap* 
	dest);
extern PACKAGE void __fastcall IERGB2YCbCr(Hyiedefs::TRGB rgb, int &Y, int &Cb, int &Cr);
extern PACKAGE void __fastcall IEYCbCr2RGB(Hyiedefs::TRGB &rgb, int Y, int Cb, int Cr);

}	/* namespace Hyieutils */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Hyieutils;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// hyieutils
