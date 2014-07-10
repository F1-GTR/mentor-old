// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'imageenio.pas' rev: 5.00

#ifndef imageenioHPP
#define imageenioHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Printers.hpp>	// Pascal unit
#include <ieds.hpp>	// Pascal unit
#include <iewia.hpp>	// Pascal unit
#include <ietwain.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
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

namespace Imageenio
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIETextFormat { ietfPascal, ietfHEX, ietfBase64, ietfASCIIArt };
#pragma option pop

#pragma option push -b-
enum TIEAcquireApi { ieaTWain, ieaWIA };
#pragma option pop

typedef void __fastcall (__closure *TIEAcquireBitmapEvent)(System::TObject* Sender, Hyieutils::TIEBitmap* 
	ABitmap, bool &Handled);

#pragma option push -b-
enum TIEJpegTransform { jtNone, jtCut, jtHorizFlip, jtVertFlip, jtTranspose, jtTransverse, jtRotate90, 
	jtRotate180, jtRotate270 };
#pragma option pop

#pragma option push -b-
enum TIEJpegCopyMarkers { jcCopyNone, jcCopyComments, jcCopyAll };
#pragma option pop

struct TStreamJpegHeader
{
	char ID[5];
	int dim;
} ;

struct PCXSHead
{
	char ID[5];
	int dim;
} ;

struct TIFFSHead
{
	char ID[5];
	int dim;
} ;

#pragma option push -b-
enum imageenio__1 { ppALL, ppAUTO, ppJPEG, ppTIFF, ppGIF, ppBMP, ppPCX, ppPNG, ppTGA, ppJ2000 };
#pragma option pop

typedef Set<imageenio__1, ppALL, ppJ2000>  TPreviewParams;

typedef void __fastcall (*TGIFLZWCompFunc)(Classes::TStream* Stream, int Height, int Width, bool Interlaced
	, char * FData, int BitsPerPixel);

typedef void __fastcall (*TGIFLZWDecompFunc)(Classes::TStream* Stream, int Height, int Width, bool Interlaced
	, char * FData);

typedef Windows::PByte __fastcall (*TTIFFLZWDecompFunc)(Windows::PByte CompBuf, int LineSize, int &Id
	);

typedef void __fastcall (*TTIFFLZWCompFunc)(Windows::PByte indata, int inputlen, Classes::TStream* outstream
	, int &id);

#pragma option push -b-
enum TIOPreviewsParamsItems { ioppDefaultLockPreview, ioppApplyButton };
#pragma option pop

typedef Set<TIOPreviewsParamsItems, ioppDefaultLockPreview, ioppApplyButton>  TIOPreviewsParams;

#pragma option push -b-
enum TIEVerticalPos { ievpTOP, ievpCENTER, ievpBOTTOM };
#pragma option pop

#pragma option push -b-
enum TIEHorizontalPos { iehpLEFT, iehpCENTER, iehpRIGHT };
#pragma option pop

#pragma option push -b-
enum TIESize { iesNORMAL, iesFITTOPAGE, iesFITTOPAGESTRETCH, iesSPECIFIEDSIZE };
#pragma option pop

#pragma option push -b-
enum TIOPSCompression { ioPS_RLE, ioPS_G4FAX, ioPS_G3FAX2D, ioPS_JPEG };
#pragma option pop

#pragma option push -b-
enum TIOPDFCompression { ioPDF_UNCOMPRESSED, ioPDF_RLE, ioPDF_G4FAX, ioPDF_G3FAX2D, ioPDF_JPEG, ioPDF_LZW 
	};
#pragma option pop

#pragma option push -b-
enum TIOTIFFCompression { ioTIFF_UNCOMPRESSED, ioTIFF_CCITT1D, ioTIFF_G3FAX1D, ioTIFF_G3FAX2D, ioTIFF_G4FAX, 
	ioTIFF_LZW, ioTIFF_OLDJPEG, ioTIFF_JPEG, ioTIFF_PACKBITS, ioTIFF_UNKNOWN };
#pragma option pop

#pragma option push -b-
enum TIOTIFFPhotometInterpret { ioTIFF_WHITEISZERO, ioTIFF_BLACKISZERO, ioTIFF_RGB, ioTIFF_RGBPALETTE, 
	ioTIFF_TRANSPMASK, ioTIFF_CMYK, ioTIFF_YCBCR, ioTIFF_CIELAB };
#pragma option pop

#pragma option push -b-
enum TIOJPEGColorspace { ioJPEG_RGB, ioJPEG_GRAYLEV, ioJPEG_YCbCr, ioJPEG_CMYK, ioJPEG_YCbCrK };
#pragma option pop

#pragma option push -b-
enum TIOJ2000ColorSpace { ioJ2000_GRAYLEV, ioJ2000_RGB, ioJ2000_YCbCr };
#pragma option pop

#pragma option push -b-
enum TIOJ2000ScalableBy { ioJ2000_Rate, ioJ2000_Resolution };
#pragma option pop

#pragma option push -b-
enum TIOJPEGDctMethod { ioJPEG_ISLOW, ioJPEG_IFAST, ioJPEG_FLOAT };
#pragma option pop

#pragma option push -b-
enum TIOJPEGScale { ioJPEG_AUTOCALC, ioJPEG_FULLSIZE, ioJPEG_HALF, ioJPEG_QUARTER, ioJPEG_EIGHTH };
#pragma option pop

#pragma option push -b-
enum TIOBMPVersion { ioBMP_BM, ioBMP_BM3, ioBMP_BMOS2V1, ioBMP_BMOS2V2 };
#pragma option pop

#pragma option push -b-
enum TIOBMPCompression { ioBMP_UNCOMPRESSED, ioBMP_RLE };
#pragma option pop

#pragma option push -b-
enum TIOPCXCompression { ioPCX_UNCOMPRESSED, ioPCX_RLE };
#pragma option pop

#pragma option push -b-
enum TIOPNGFilter { ioPNG_FILTER_NONE, ioPNG_FILTER_SUB, ioPNG_FILTER_PAETH };
#pragma option pop

#pragma option push -b-
enum TIEGIFAction { ioGIF_None, ioGIF_DontRemove, ioGIF_DrawBackground, ioGIF_RestorePrev };
#pragma option pop

typedef int TIOFileType;

typedef tagSIZE TIOICOSizes[16];

typedef int TIOICOBitCount[16];

#pragma option push -b-
enum TIOBMPRAWChannelOrder { coRGB, coBGR };
#pragma option pop

#pragma option push -b-
enum TIOBMPRAWPlanes { plInterleaved, plPlanar };
#pragma option pop

class DELPHICLASS TIOParamsVals;
class DELPHICLASS TImageEnIO;
typedef void __fastcall (__closure *TIEDoPreviewsEvent)(System::TObject* Sender, bool &Handled);

class DELPHICLASS TIETWainParams;
struct TIEDRect
{
	double Left;
	double Top;
	double Right;
	double Bottom;
} ;

struct TIETWSourceCaps
{
	Hyieutils::TIEDoubleList* fXResolution;
	Hyieutils::TIEDoubleList* fYResolution;
	Hyieutils::TIEDoubleList* fXScaling;
	Hyieutils::TIEDoubleList* fYScaling;
	Hyieutils::TIEIntegerList* fPixelType;
	Hyieutils::TIEIntegerList* fBitDepth;
	double fGamma;
	double fPhysicalHeight;
	double fPhysicalWidth;
	bool fFeederEnabled;
	Hyieutils::TIEIntegerList* fOrientation;
	bool fIndicators;
	TIEDRect fAcquireFrame;
	bool fBufferedTransfer;
	bool fFileTransfer;
	bool fDuplexEnabled;
	bool fAcquireFrameEnabled;
	bool fFeederLoaded;
	bool fDuplexSupported;
	bool fPaperDetectable;
	Hyieutils::TIEDoubleList* fContrast;
	Hyieutils::TIEDoubleList* fBrightness;
	Hyieutils::TIEDoubleList* fThreshold;
	Hyieutils::TIEDoubleList* fRotation;
	bool fUndefinedImageSize;
	Hyieutils::TIEIntegerList* fStandardSize;
	bool fAutoFeed;
} ;

struct TIETWainShared
{
	unsigned hDSMLib;
	Ietwain::DSMENTRYPROC DSM_Entry;
	HWND hproxy;
} ;

class PASCALIMPLEMENTATION TIETWainParams : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TComponent* fOwner;
	bool fVisibleDialog;
	Classes::TList* fSourceListData;
	int fSelectedSource;
	bool fSourceListDataValid;
	bool fCapabilitiesValid;
	TIETWSourceCaps fCapabilities;
	AnsiString fAppVersionInfo;
	AnsiString fAppManufacturer;
	AnsiString fAppProductFamily;
	AnsiString fAppProductName;
	bool fCompatibilityMode;
	void __fastcall FillSourceListData(void);
	void __fastcall FillCapabilities(void);
	AnsiString __fastcall GetSourceName(int idx);
	int __fastcall GetSourceCount(void);
	Hyieutils::TIEDoubleList* __fastcall GetXResolution(void);
	Hyieutils::TIEDoubleList* __fastcall GetYResolution(void);
	Hyieutils::TIEDoubleList* __fastcall GetXScaling(void);
	Hyieutils::TIEDoubleList* __fastcall GetYScaling(void);
	Hyieutils::TIEDoubleList* __fastcall GetContrast(void);
	Hyieutils::TIEDoubleList* __fastcall GetBrightness(void);
	Hyieutils::TIEDoubleList* __fastcall GetThreshold(void);
	Hyieutils::TIEDoubleList* __fastcall GetRotation(void);
	Hyieutils::TIEIntegerList* __fastcall GetPixelType(void);
	Hyieutils::TIEIntegerList* __fastcall GetBitDepth(void);
	double __fastcall GetGamma(void);
	double __fastcall GetPhysicalHeight(void);
	double __fastcall GetPhysicalWidth(void);
	bool __fastcall GetFeederEnabled(void);
	bool __fastcall GetAutoFeed(void);
	bool __fastcall GetUndefinedImageSize(void);
	Hyieutils::TIEIntegerList* __fastcall GetOrientation(void);
	Hyieutils::TIEIntegerList* __fastcall GetStandardSize(void);
	void __fastcall SetSelectedSource(int v);
	bool __fastcall GetIndicators(void);
	void __fastcall SetFeederEnabled(bool v);
	void __fastcall SetAutoFeed(bool v);
	void __fastcall SetUndefinedImageSize(bool v);
	void __fastcall SetIndicators(bool v);
	double __fastcall GetAcquireFrame(int idx);
	void __fastcall SetAcquireFrame(int idx, double v);
	bool __fastcall GetBufferedTransfer(void);
	void __fastcall SetBufferedTransfer(bool v);
	bool __fastcall GetFileTransfer(void);
	void __fastcall SetFileTransfer(bool v);
	void __fastcall SetAppVersionInfo(AnsiString v);
	void __fastcall SetAppManufacturer(AnsiString v);
	void __fastcall SetAppProductFamily(AnsiString v);
	void __fastcall SetAppProductName(AnsiString v);
	void __fastcall SetDuplexEnabled(bool v);
	bool __fastcall GetDuplexEnabled(void);
	void __fastcall SetAcquireFrameEnabled(bool v);
	bool __fastcall GetAcquireFrameEnabled(void);
	bool __fastcall GetFeederLoaded(void);
	bool __fastcall GetDuplexSupported(void);
	bool __fastcall GetPaperDetectable(void);
	void __fastcall SetLogFile(AnsiString v);
	AnsiString __fastcall GetLogFile(void);
	
public:
	TIETWainShared TWainShared;
	int LastError;
	AnsiString LastErrorStr;
	__property bool VisibleDialog = {read=fVisibleDialog, write=fVisibleDialog, nodefault};
	__property AnsiString SourceName[int idx] = {read=GetSourceName};
	__property int SourceCount = {read=GetSourceCount, nodefault};
	__property int SelectedSource = {read=fSelectedSource, write=SetSelectedSource, nodefault};
	__property AnsiString LogFile = {read=GetLogFile, write=SetLogFile};
	__property bool CompatibilityMode = {read=fCompatibilityMode, write=fCompatibilityMode, nodefault};
		
	__property Hyieutils::TIEDoubleList* XResolution = {read=GetXResolution};
	__property Hyieutils::TIEDoubleList* YResolution = {read=GetYResolution};
	__property Hyieutils::TIEDoubleList* XScaling = {read=GetXScaling};
	__property Hyieutils::TIEDoubleList* YScaling = {read=GetYScaling};
	__property Hyieutils::TIEIntegerList* PixelType = {read=GetPixelType};
	__property Hyieutils::TIEIntegerList* BitDepth = {read=GetBitDepth};
	__property double Gamma = {read=GetGamma};
	__property double PhysicalHeight = {read=GetPhysicalHeight};
	__property double PhysicalWidth = {read=GetPhysicalWidth};
	__property bool FeederEnabled = {read=GetFeederEnabled, write=SetFeederEnabled, nodefault};
	__property bool AutoFeed = {read=GetAutoFeed, write=SetAutoFeed, nodefault};
	__property bool FeederLoaded = {read=GetFeederLoaded, nodefault};
	__property bool PaperDetectable = {read=GetPaperDetectable, nodefault};
	__property Hyieutils::TIEIntegerList* Orientation = {read=GetOrientation};
	__property bool ProgressIndicators = {read=GetIndicators, write=SetIndicators, nodefault};
	__property double AcquireFrameLeft = {read=GetAcquireFrame, write=SetAcquireFrame, index=0};
	__property double AcquireFrameTop = {read=GetAcquireFrame, write=SetAcquireFrame, index=1};
	__property double AcquireFrameRight = {read=GetAcquireFrame, write=SetAcquireFrame, index=2};
	__property double AcquireFrameBottom = {read=GetAcquireFrame, write=SetAcquireFrame, index=3};
	__property bool BufferedTransfer = {read=GetBufferedTransfer, write=SetBufferedTransfer, nodefault}
		;
	__property bool FileTransfer = {read=GetFileTransfer, write=SetFileTransfer, nodefault};
	__property bool DuplexEnabled = {read=GetDuplexEnabled, write=SetDuplexEnabled, nodefault};
	__property bool DuplexSupported = {read=GetDuplexSupported, nodefault};
	__property bool AcquireFrameEnabled = {read=GetAcquireFrameEnabled, write=SetAcquireFrameEnabled, nodefault
		};
	__property Hyieutils::TIEDoubleList* Contrast = {read=GetContrast};
	__property Hyieutils::TIEDoubleList* Brightness = {read=GetBrightness};
	__property Hyieutils::TIEDoubleList* Threshold = {read=GetThreshold};
	__property Hyieutils::TIEDoubleList* Rotation = {read=GetRotation};
	__property bool UndefinedImageSize = {read=GetUndefinedImageSize, write=SetUndefinedImageSize, nodefault
		};
	__property Hyieutils::TIEIntegerList* StandardSize = {read=GetStandardSize};
	__property AnsiString AppVersionInfo = {read=fAppVersionInfo, write=SetAppVersionInfo};
	__property AnsiString AppManufacturer = {read=fAppManufacturer, write=SetAppManufacturer};
	__property AnsiString AppProductFamily = {read=fAppProductFamily, write=SetAppProductFamily};
	__property AnsiString AppProductName = {read=fAppProductName, write=SetAppProductName};
	__fastcall TIETWainParams(Classes::TComponent* Owner);
	__fastcall virtual ~TIETWainParams(void);
	void __fastcall SetDefaultParams(void);
	void __fastcall Assign(TIETWainParams* Source);
	bool __fastcall SelectSourceByName(const AnsiString sn);
	int __fastcall GetDefaultSource(void);
	void __fastcall Update(void);
	void __fastcall FreeResources(void);
	bool __fastcall GetFromScanner(void);
};


typedef void __fastcall (__closure *TIEIOPreviewEvent)(System::TObject* Sender, Forms::TForm* PreviewForm
	);

#pragma option push -b-
enum TIEDialogsMeasureUnit { ieduInches, ieduCm, ieduSelectableDefInches, ieduSelectableDefCm };
#pragma option pop

struct TAviStreamInfoA_Ex
{
	unsigned fccType;
	unsigned fccHandler;
	unsigned dwFlags;
	unsigned dwCaps;
	Word wPriority;
	Word wLanguage;
	unsigned dwScale;
	unsigned dwRate;
	unsigned dwStart;
	unsigned dwLength;
	unsigned dwInitialFrames;
	unsigned dwSuggestedBufferSize;
	unsigned dwQuality;
	unsigned dwSampleSize;
	Windows::TRect rcFrame;
	unsigned dwEditCount;
	unsigned dwFormatChangeCount;
	char szName[64];
} ;

class DELPHICLASS TIOPrintPreviewParams;
#pragma option push -b-
enum TIOPrintPreviewPosition { ppTopLeft, ppTop, ppTopRight, ppLeft, ppCenter, ppRight, ppBottomLeft, 
	ppBottom, ppBottomRight };
#pragma option pop

#pragma option push -b-
enum TIOPrintPreviewSize { psNormal, psFitToPage, psStretchToPage, psSpecifiedSize };
#pragma option pop

class PASCALIMPLEMENTATION TIOPrintPreviewParams : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	double fMarginTop;
	double fMarginLeft;
	double fMarginRight;
	double fMarginBottom;
	TIOPrintPreviewPosition fPosition;
	TIOPrintPreviewSize fSize;
	double fWidth;
	double fHeight;
	double fGamma;
	
public:
	__fastcall TIOPrintPreviewParams(void);
	__property double MarginTop = {read=fMarginTop, write=fMarginTop};
	__property double MarginLeft = {read=fMarginLeft, write=fMarginLeft};
	__property double MarginRight = {read=fMarginRight, write=fMarginRight};
	__property double MarginBottom = {read=fMarginBottom, write=fMarginBottom};
	__property TIOPrintPreviewPosition Position = {read=fPosition, write=fPosition, nodefault};
	__property TIOPrintPreviewSize Size = {read=fSize, write=fSize, nodefault};
	__property double Width = {read=fWidth, write=fWidth};
	__property double Height = {read=fHeight, write=fHeight};
	__property double Gamma = {read=fGamma, write=fGamma};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIOPrintPreviewParams(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TIECSSource { iecsScreen, iecsForegroundWindow, iecsForegroundWindowClient };
#pragma option pop

#pragma option push -b-
enum TIEDialogType { iedtDialog, iedtMaxi };
#pragma option pop

class PASCALIMPLEMENTATION TImageEnIO : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Graphics::TBitmap* fBitmap;
	Hyieutils::TIEBitmap* fIEBitmap;
	bool fIEBitmapCreated;
	Ieview::TIEView* fImageEnView;
	int fImageEnViewIdx;
	Extctrls::TImage* fTImage;
	Graphics::TColor fBackground;
	Hyiedefs::TMsgLanguage fMsgLanguage;
	TIOPreviewsParams fPreviewsParams;
	bool fSimplifiedParamsDialogs;
	TIEDoPreviewsEvent fOnDoPreviews;
	bool fChangeBackground;
	TIETWainParams* fTwainParams;
	bool fStreamHeaders;
	Graphics::TFont* fPreviewFont;
	TIEIOPreviewEvent fOnIOPreview;
	TIEDialogsMeasureUnit fDialogsMeasureUnit;
	bool fAutoAdjustDPI;
	bool fFilteredAdjustDPI;
	void *fAVI_avf;
	void *fAVI_avs;
	void *fAVI_avs1;
	void *fAVI_gf;
	TAviStreamInfoA_Ex fAVI_psi;
	void *fAVI_popts;
	int fAVI_idx;
	Ieds::TIEDirectShow* fOpenMediaFile;
	double fOpenMediaFileRate;
	int fOpenMediaFileMul;
	void *fPS_handle;
	Classes::TFileStream* fPS_stream;
	void *fPDF_handle;
	Classes::TFileStream* fPDF_stream;
	Classes::TList* fAsyncThreads;
	_RTL_CRITICAL_SECTION fAsyncThreadsCS;
	bool fAsyncMode;
	Hyiedefs::TResampleFilter fPrintingFilterOnSubsampling;
	void *fgrec;
	Iewia::TIEWia* fWIA;
	Ieds::TIEDirectShow* fDShow;
	AnsiString fProxyAddress;
	AnsiString fProxyUser;
	AnsiString fProxyPassword;
	Hyieutils::TIEDitherMethod fDefaultDitherMethod;
	bool fResetPrinter;
	TIOPrintPreviewParams* fPrintPreviewParams;
	bool __fastcall IsInsideAsyncThreads(void);
	void __fastcall SetAttachedBitmap(Graphics::TBitmap* atBitmap);
	void __fastcall SetAttachedImageEn(Ieview::TIEView* atImageEn);
	Graphics::TColor __fastcall GetReBackground(void);
	void __fastcall SetReBackground(Graphics::TColor v);
	void __fastcall SetPreviewFont(Graphics::TFont* f);
	void __fastcall SetTImage(Extctrls::TImage* v);
	void __fastcall SetIOPreviewParams(TIOPreviewsParams v);
	TIOPreviewsParams __fastcall GetIOPreviewParams(void);
	void __fastcall AdjustDPI(void);
	int __fastcall GetAsyncRunning(void);
	int __fastcall GetThreadsCount(void);
	void __fastcall SetDefaultDitherMethod(Hyieutils::TIEDitherMethod Value);
	bool __fastcall WiaOnProgress(int Percentage);
	
protected:
	TIOParamsVals* fParams;
	bool fAborting;
	Hyiedefs::TIEProgressEvent fOnIntProgress;
	Hyiedefs::TIEProgressEvent fOnProgress;
	Classes::TNotifyEvent fOnFinishWork;
	TIEAcquireBitmapEvent fOnAcquireBitmap;
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall OnBitmapChange(System::TObject* Sender, bool destroying);
	void __fastcall PrintImageEx(Graphics::TCanvas* PrtCanvas, int dpix, int dpiy, double pagewidth, double 
		pageheight, double MarginLeft, double MarginTop, double MarginRight, double MarginBottom, TIEVerticalPos 
		VerticalPos, TIEHorizontalPos HorizontalPos, TIESize Size, double SpecWidth, double SpecHeight, double 
		GammaCorrection);
	void __fastcall PrintImagePosEx(Graphics::TCanvas* PrtCanvas, int dpix, int dpiy, double x, double 
		y, double Width, double Height, double GammaCorrection);
	void __fastcall LoadFromStreamJ2000(Classes::TStream* Stream);
	void __fastcall SaveToStreamJ2000(Classes::TStream* Stream, int format);
	void __fastcall SetBitmap(Graphics::TBitmap* bmp);
	void __fastcall SetIEBitmap(Hyieutils::TIEBitmap* bmp);
	void __fastcall SetAttachedIEBitmap(Hyieutils::TIEBitmap* bmp);
	virtual void __fastcall TWMultiCallBack(Hyieutils::TIEBitmap* Bitmap, System::TObject* &IOParams);
	virtual void __fastcall TWCloseCallBack(void);
	DYNAMIC void __fastcall DoAcquireBitmap(Hyieutils::TIEBitmap* ABitmap, bool &Handled);
	virtual void __fastcall DoFinishWork(void);
	virtual Graphics::TBitmap* __fastcall GetBitmap(void);
	bool __fastcall MakeConsistentBitmap(Hyieutils::TIEPixelFormatSet allowedFormats);
	virtual Iewia::TIEWia* __fastcall GetWIAParams(void);
	virtual Ieds::TIEDirectShow* __fastcall GetDShowParams(void);
	int __fastcall SyncLoadFromStreamGIF(Classes::TStream* Stream);
	void __fastcall SyncLoadFromStreamPCX(Classes::TStream* Stream, bool streamhead);
	void __fastcall SyncLoadFromStreamDCX(Classes::TStream* Stream);
	int __fastcall SyncLoadFromStreamTIFF(Classes::TStream* Stream, bool streamhead);
	void __fastcall SyncLoadFromStreamBMP(Classes::TStream* Stream);
	void __fastcall SyncSaveToStreamPS(Classes::TStream* Stream);
	void __fastcall SyncSaveToStreamPDF(Classes::TStream* Stream);
	void __fastcall SyncSaveToStreamBMP(Classes::TStream* Stream);
	void __fastcall SyncSaveToStreamDCX(Classes::TStream* Stream);
	void __fastcall SyncLoadFromStreamRAW(Classes::TStream* Stream);
	void __fastcall SyncLoadFromStreamBMPRAW(Classes::TStream* Stream);
	void __fastcall SyncSaveToStreamBMPRAW(Classes::TStream* Stream);
	void __fastcall CheckDPI(void);
	void __fastcall SetNativePixelFormat(bool value);
	bool __fastcall GetNativePixelFormat(void);
	virtual void __fastcall DoIntProgress(System::TObject* Sender, int per);
	
public:
	__fastcall virtual TImageEnIO(Classes::TComponent* Owner);
	__fastcall virtual ~TImageEnIO(void);
	__property Graphics::TBitmap* AttachedBitmap = {read=fBitmap, write=SetAttachedBitmap};
	__property Hyieutils::TIEBitmap* AttachedIEBitmap = {read=fIEBitmap, write=SetAttachedIEBitmap};
	void __fastcall Update(void);
	__property bool ChangeBackground = {read=fChangeBackground, write=fChangeBackground, nodefault};
	__property int ThreadsCount = {read=GetThreadsCount, nodefault};
	__property Hyieutils::TIEDitherMethod DefaultDitherMethod = {read=fDefaultDitherMethod, write=SetDefaultDitherMethod
		, nodefault};
	virtual bool __fastcall DoPreviews(TPreviewParams pp);
	__property Graphics::TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap};
	__property Hyieutils::TIEBitmap* IEBitmap = {read=fIEBitmap, write=SetIEBitmap};
	__property TIOParamsVals* Params = {read=fParams};
	void __fastcall AssignParams(System::TObject* Source);
	void __fastcall RecreatedTImageEnViewHandle(void);
	void __fastcall SaveToFileJpeg(const AnsiString nf);
	void __fastcall LoadFromFileJpeg(const AnsiString nf);
	void __fastcall SaveToStreamJpeg(Classes::TStream* Stream);
	void __fastcall LoadFromStreamJpeg(Classes::TStream* Stream);
	bool __fastcall InjectJpegIPTC(const AnsiString nf);
	bool __fastcall InjectJpegIPTCStream(Classes::TStream* InputStream, Classes::TStream* OutputStream)
		;
	bool __fastcall InjectJpegEXIF(const AnsiString nf);
	bool __fastcall InjectJpegEXIFStream(Classes::TStream* InputStream, Classes::TStream* OutputStream)
		;
	void __fastcall LoadFromFileDCX(const AnsiString nf);
	void __fastcall LoadFromStreamDCX(Classes::TStream* Stream);
	void __fastcall SaveToStreamDCX(Classes::TStream* Stream);
	void __fastcall SaveToFileDCX(const AnsiString nf);
	void __fastcall InsertToFileDCX(const AnsiString nf);
	void __fastcall LoadFromFileJP2(const AnsiString nf);
	void __fastcall LoadFromFileJ2K(const AnsiString nf);
	void __fastcall LoadFromStreamJP2(Classes::TStream* Stream);
	void __fastcall LoadFromStreamJ2K(Classes::TStream* Stream);
	void __fastcall SaveToStreamJP2(Classes::TStream* Stream);
	void __fastcall SaveToStreamJ2K(Classes::TStream* stream);
	void __fastcall SaveToFileJP2(const AnsiString nf);
	void __fastcall SaveToFileJ2K(const AnsiString nf);
	int __fastcall LoadFromFileGIF(const AnsiString nf);
	void __fastcall SaveToFileGIF(const AnsiString nf);
	int __fastcall InsertToFileGIF(const AnsiString nf);
	int __fastcall LoadFromStreamGIF(Classes::TStream* Stream);
	void __fastcall SaveToStreamGIF(Classes::TStream* Stream);
	int __fastcall ReplaceFileGIF(const AnsiString nf);
	void __fastcall SaveToStreamPCX(Classes::TStream* Stream);
	void __fastcall LoadFromStreamPCX(Classes::TStream* Stream);
	void __fastcall SaveToFilePCX(const AnsiString nf);
	void __fastcall LoadFromFilePCX(const AnsiString nf);
	int __fastcall LoadFromStreamTIFF(Classes::TStream* Stream);
	void __fastcall SaveToStreamTIFF(Classes::TStream* Stream);
	int __fastcall LoadFromFileTIFF(const AnsiString nf);
	void __fastcall SaveToFileTIFF(const AnsiString nf);
	int __fastcall InsertToFileTIFF(const AnsiString nf);
	int __fastcall InsertToStreamTIFF(Classes::TStream* Stream);
	int __fastcall ReplaceFileTIFF(const AnsiString nf);
	void __fastcall SaveToStreamBMP(Classes::TStream* Stream);
	void __fastcall LoadFromStreamBMP(Classes::TStream* Stream);
	void __fastcall SaveToFileBMP(const AnsiString nf);
	void __fastcall LoadFromFileBMP(const AnsiString nf);
	void __fastcall LoadFromFileICO(const AnsiString nf);
	void __fastcall LoadFromStreamICO(Classes::TStream* Stream);
	void __fastcall SaveToStreamICO(Classes::TStream* Stream);
	void __fastcall SaveToFileICO(const AnsiString nf);
	void __fastcall LoadFromFileCUR(const AnsiString nf);
	void __fastcall LoadFromStreamCUR(Classes::TStream* Stream);
	void __fastcall LoadFromFilePNG(const AnsiString nf);
	void __fastcall LoadFromStreamPNG(Classes::TStream* Stream);
	void __fastcall SaveToFilePNG(const AnsiString nf);
	void __fastcall SaveToStreamPNG(Classes::TStream* Stream);
	void __fastcall LoadFromFileTGA(const AnsiString nf);
	void __fastcall LoadFromStreamTGA(Classes::TStream* Stream);
	void __fastcall SaveToFileTGA(const AnsiString nf);
	void __fastcall SaveToStreamTGA(Classes::TStream* Stream);
	void __fastcall ImportMetafile(const AnsiString nf, int Width, int Height, bool WithAlpha);
	void __fastcall MergeMetafile(const AnsiString FileName, int x, int y, int Width, int Height);
	void __fastcall LoadFromFilePXM(const AnsiString nf);
	void __fastcall LoadFromStreamPXM(Classes::TStream* Stream);
	void __fastcall SaveToFilePXM(const AnsiString nf);
	void __fastcall SaveToStreamPXM(Classes::TStream* Stream);
	int __fastcall OpenAVIFile(const AnsiString nf);
	void __fastcall CloseAVIFile(void);
	void __fastcall LoadFromAVI(int FrameIndex);
	void __fastcall CreateAVIFile(const AnsiString nf, int rate, AnsiString codec);
	void __fastcall SaveToAVI(void);
	bool __fastcall IsOpenAVI(void);
	int __fastcall OpenMediaFile(const AnsiString nf);
	void __fastcall CloseMediaFile(void);
	void __fastcall LoadFromMediaFile(int FrameIndex);
	bool __fastcall IsOpenMediaFile(void);
	void __fastcall LoadFromFileWBMP(const AnsiString nf);
	void __fastcall LoadFromStreamWBMP(Classes::TStream* Stream);
	void __fastcall SaveToFileWBMP(const AnsiString nf);
	void __fastcall SaveToStreamWBMP(Classes::TStream* Stream);
	void __fastcall CreatePSFile(const AnsiString nf);
	void __fastcall SaveToPS(void);
	void __fastcall ClosePSFile(void);
	void __fastcall SaveToStreamPS(Classes::TStream* Stream);
	void __fastcall SaveToFilePS(const AnsiString nf);
	void __fastcall CreatePDFFile(const AnsiString nf);
	void __fastcall SaveToPDF(void);
	void __fastcall ClosePDFFile(void);
	void __fastcall SaveToStreamPDF(Classes::TStream* Stream);
	void __fastcall SaveToFilePDF(const AnsiString nf);
	void __fastcall LoadFromStreamRAW(Classes::TStream* Stream);
	void __fastcall LoadFromFileRAW(const AnsiString nf);
	void __fastcall LoadJpegFromFileCRW(const AnsiString nf);
	void __fastcall LoadFromStreamBMPRAW(Classes::TStream* Stream);
	void __fastcall LoadFromFileBMPRAW(const AnsiString nf);
	void __fastcall SaveToStreamBMPRAW(Classes::TStream* Stream);
	void __fastcall SaveToFileBMPRAW(const AnsiString nf);
	DYNAMIC void __fastcall LoadFromFile(const AnsiString nf);
	DYNAMIC void __fastcall LoadFromFileAuto(const AnsiString nf);
	DYNAMIC void __fastcall SaveToFile(const AnsiString nf);
	DYNAMIC void __fastcall SaveToText(const AnsiString FileName, int ImageFormat, TIETextFormat TextFormat
		);
	DYNAMIC void __fastcall LoadFromFileFormat(const AnsiString nf, int FileFormat);
	DYNAMIC void __fastcall LoadFromBuffer(void * Buffer, int BufferSize, int Format);
	__property bool Aborting = {read=fAborting, write=fAborting, nodefault};
	DYNAMIC void __fastcall ParamsFromFile(const AnsiString nf);
	DYNAMIC void __fastcall ParamsFromFileFormat(const AnsiString nf, int format);
	DYNAMIC void __fastcall ParamsFromStream(Classes::TStream* Stream);
	DYNAMIC void __fastcall ParamsFromStreamFormat(Classes::TStream* Stream, int format);
	DYNAMIC void __fastcall LoadFromStream(Classes::TStream* Stream);
	DYNAMIC void __fastcall LoadFromStreamFormat(Classes::TStream* Stream, int FileFormat);
	DYNAMIC void __fastcall SaveToStream(Classes::TStream* Stream, int FileType);
	AnsiString __fastcall ExecuteOpenDialog(AnsiString InitialDir, AnsiString InitialFileName, bool AlwaysAnimate
		, int FilterIndex, AnsiString ExtendedFilters);
	AnsiString __fastcall ExecuteSaveDialog(AnsiString InitialDir, AnsiString InitialFileName, bool AlwaysAnimate
		, int FilterIndex, AnsiString ExtendedFilters);
	void __fastcall CaptureFromScreen(TIECSSource Source, Controls::TCursor MouseCursor);
	void __fastcall LoadFromURL(AnsiString URL);
	bool __fastcall Acquire(TIEAcquireApi api);
	bool __fastcall SelectAcquireSource(TIEAcquireApi api);
	bool __fastcall AcquireOpen(void);
	void __fastcall AcquireClose(void);
	__property int AsyncRunning = {read=GetAsyncRunning, nodefault};
	__property bool AsyncMode = {read=fAsyncMode, write=fAsyncMode, nodefault};
	void __fastcall WaitThreads(bool Aborts);
	__property TIETWainParams* TWainParams = {read=fTwainParams};
	__property Iewia::TIEWia* WIAParams = {read=GetWIAParams};
	__property Ieds::TIEDirectShow* DShowParams = {read=GetDShowParams};
	void __fastcall PrintImagePos(Graphics::TCanvas* PrtCanvas, double x, double y, double Width, double 
		Height, double GammaCorrection);
	void __fastcall PrintImage(Graphics::TCanvas* PrtCanvas, double MarginLeft, double MarginTop, double 
		MarginRight, double MarginBottom, TIEVerticalPos VerticalPos, TIEHorizontalPos HorizontalPos, TIESize 
		Size, double SpecWidth, double SpecHeight, double GammaCorrection);
	void __fastcall PreviewPrintImage(Graphics::TBitmap* DestBitmap, int MaxBitmapWidth, int MaxBitmapHeight
		, Printers::TPrinter* PrinterObj, double MarginLeft, double MarginTop, double MarginRight, double 
		MarginBottom, TIEVerticalPos VerticalPos, TIEHorizontalPos HorizontalPos, TIESize Size, double SpecWidth
		, double SpecHeight, double GammaCorrection);
	bool __fastcall DoPrintPreviewDialog(TIEDialogType DialogType, const AnsiString TaskName, bool PrintAnnotations
		, const AnsiString Caption);
	__property TIOPrintPreviewParams* PrintPreviewParams = {read=fPrintPreviewParams};
	__property Hyiedefs::TResampleFilter PrintingFilterOnSubsampling = {read=fPrintingFilterOnSubsampling
		, write=fPrintingFilterOnSubsampling, nodefault};
	__property AnsiString ProxyAddress = {read=fProxyAddress, write=fProxyAddress};
	__property AnsiString ProxyUser = {read=fProxyUser, write=fProxyUser};
	__property AnsiString ProxyPassword = {read=fProxyPassword, write=fProxyPassword};
	__property bool ResetPrinter = {read=fResetPrinter, write=fResetPrinter, nodefault};
	
__published:
	__property Ieview::TIEView* AttachedImageEn = {read=fImageEnView, write=SetAttachedImageEn};
	__property Graphics::TColor Background = {read=GetReBackground, write=SetReBackground, default=0};
	__property Hyiedefs::TIEProgressEvent OnProgress = {read=fOnProgress, write=fOnProgress};
	__property Hyiedefs::TMsgLanguage MsgLanguage = {read=fMsgLanguage, write=fMsgLanguage, default=0};
		
	__property TIOPreviewsParams PreviewsParams = {read=GetIOPreviewParams, write=SetIOPreviewParams, default=0
		};
	__property bool StreamHeaders = {read=fStreamHeaders, write=fStreamHeaders, default=0};
	__property Graphics::TFont* PreviewFont = {read=fPreviewFont, write=SetPreviewFont};
	__property Extctrls::TImage* AttachedTImage = {read=fTImage, write=SetTImage};
	__property TIEIOPreviewEvent OnIOPreview = {read=fOnIOPreview, write=fOnIOPreview};
	__property TIEDialogsMeasureUnit DialogsMeasureUnit = {read=fDialogsMeasureUnit, write=fDialogsMeasureUnit
		, default=0};
	__property bool AutoAdjustDPI = {read=fAutoAdjustDPI, write=fAutoAdjustDPI, default=0};
	__property bool FilteredAdjustDPI = {read=fFilteredAdjustDPI, write=fFilteredAdjustDPI, default=0};
		
	__property Classes::TNotifyEvent OnFinishWork = {read=fOnFinishWork, write=fOnFinishWork};
	__property TIEAcquireBitmapEvent OnAcquireBitmap = {read=fOnAcquireBitmap, write=fOnAcquireBitmap};
		
	__property bool SimplifiedParamsDialogs = {read=fSimplifiedParamsDialogs, write=fSimplifiedParamsDialogs
		, default=1};
	__property TIEDoPreviewsEvent OnDoPreviews = {read=fOnDoPreviews, write=fOnDoPreviews};
	__property bool NativePixelFormat = {read=GetNativePixelFormat, write=SetNativePixelFormat, default=0
		};
};


class PASCALIMPLEMENTATION TIOParamsVals : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TImageEnIO* fImageEnIO;
	int fBitsPerSample;
	AnsiString fFileName;
	int fSamplesPerPixel;
	int fWidth;
	int fHeight;
	int fDpiX;
	int fDpiY;
	int fFileType;
	int fImageIndex;
	int fImageCount;
	bool fGetThumbnail;
	TIOTIFFCompression fTIFF_Compression;
	int fTIFF_ImageIndex;
	TIOTIFFPhotometInterpret fTIFF_PhotometInterpret;
	int fTIFF_PlanarConf;
	int fTIFF_XPos;
	int fTIFF_YPos;
	AnsiString fTIFF_DocumentName;
	AnsiString fTIFF_ImageDescription;
	AnsiString fTIFF_PageName;
	int fTIFF_PageNumber;
	int fTIFF_PageCount;
	int fTIFF_Orientation;
	TTIFFLZWDecompFunc fTIFF_LZWDecompFunc;
	TTIFFLZWCompFunc fTIFF_LZWCompFunc;
	bool fTIFF_EnableAdjustOrientation;
	int fTIFF_JPEGQuality;
	TIOJPEGColorspace fTIFF_JPEGColorSpace;
	int fTIFF_ImageCount;
	int fTIFF_FillOrder;
	int fDCX_ImageIndex;
	AnsiString fGIF_Version;
	int fGIF_ImageIndex;
	int fGIF_XPos;
	int fGIF_YPos;
	int fGIF_DelayTime;
	bool fGIF_FlagTranspColor;
	#pragma pack(push, 1)
	Hyiedefs::TRGB fGIF_TranspColor;
	#pragma pack(pop)
	
	bool fGIF_Interlaced;
	int fGIF_WinWidth;
	int fGIF_WinHeight;
	#pragma pack(push, 1)
	Hyiedefs::TRGB fGIF_Background;
	#pragma pack(pop)
	
	int fGIF_Ratio;
	Classes::TStringList* fGIF_Comments;
	TIEGIFAction fGIF_Action;
	TGIFLZWDecompFunc fGIF_LZWDecompFunc;
	TGIFLZWCompFunc fGIF_LZWCompFunc;
	int fGIF_ImageCount;
	TIOJPEGColorspace fJPEG_ColorSpace;
	int fJPEG_Quality;
	TIOJPEGDctMethod fJPEG_DCTMethod;
	bool fJPEG_OptimalHuffman;
	int fJPEG_Smooth;
	bool fJPEG_Progressive;
	TIOJPEGScale fJPEG_Scale;
	Hyieutils::TIEMarkerList* fJPEG_MarkerList;
	int fJPEG_Scale_Used;
	int fJPEG_WarningTot;
	int fJPEG_WarningCode;
	int fJPEG_OriginalWidth;
	int fJPEG_OriginalHeight;
	bool fJPEG_EnableAdjustOrientation;
	bool fJPEG_GetExifThumbnail;
	TIOJ2000ColorSpace fJ2000_ColorSpace;
	double fJ2000_Rate;
	TIOJ2000ScalableBy fJ2000_ScalableBy;
	int fPCX_Version;
	TIOPCXCompression fPCX_Compression;
	TIOBMPVersion fBMP_Version;
	TIOBMPCompression fBMP_Compression;
	int fICO_ImageIndex;
	#pragma pack(push, 1)
	Hyiedefs::TRGB fICO_Background;
	#pragma pack(pop)
	
	int fCUR_ImageIndex;
	int fCUR_XHotSpot;
	int fCUR_YHotSpot;
	#pragma pack(push, 1)
	Hyiedefs::TRGB fCUR_Background;
	#pragma pack(pop)
	
	bool fPNG_Interlaced;
	#pragma pack(push, 1)
	Hyiedefs::TRGB fPNG_Background;
	#pragma pack(pop)
	
	TIOPNGFilter fPNG_Filter;
	int fPNG_Compression;
	Classes::TStringList* fPNG_TextKeys;
	Classes::TStringList* fPNG_TextValues;
	int fTGA_XPos;
	int fTGA_YPos;
	bool fTGA_Compressed;
	AnsiString fTGA_Descriptor;
	AnsiString fTGA_Author;
	System::TDateTime fTGA_Date;
	AnsiString fTGA_ImageName;
	#pragma pack(push, 1)
	Hyiedefs::TRGB fTGA_Background;
	#pragma pack(pop)
	
	double fTGA_AspectRatio;
	double fTGA_Gamma;
	bool fTGA_GrayLevel;
	Hyieutils::TIEIPTCInfoList* fIPTC_Info;
	Hyieutils::TIEImagingAnnot* fImagingAnnot;
	Classes::TStringList* fPXM_Comments;
	bool fEXIF_HasEXIFData;
	Hyieutils::TIEBitmap* fEXIF_Bitmap;
	AnsiString fEXIF_ImageDescription;
	AnsiString fEXIF_Make;
	AnsiString fEXIF_Model;
	int fEXIF_Orientation;
	double fEXIF_XResolution;
	double fEXIF_YResolution;
	int fEXIF_ResolutionUnit;
	AnsiString fEXIF_Software;
	AnsiString fEXIF_Artist;
	AnsiString fEXIF_DateTime;
	double fEXIF_WhitePoint[2];
	double fEXIF_PrimaryChromaticities[6];
	double fEXIF_YCbCrCoefficients[3];
	int fEXIF_YCbCrPositioning;
	double fEXIF_ReferenceBlackWhite[6];
	AnsiString fEXIF_Copyright;
	double fEXIF_ExposureTime;
	double fEXIF_FNumber;
	int fEXIF_ExposureProgram;
	int fEXIF_ISOSpeedRatings[2];
	AnsiString fEXIF_ExifVersion;
	AnsiString fEXIF_DateTimeOriginal;
	AnsiString fEXIF_DateTimeDigitized;
	double fEXIF_CompressedBitsPerPixel;
	double fEXIF_ShutterSpeedValue;
	double fEXIF_ApertureValue;
	double fEXIF_BrightnessValue;
	double fEXIF_ExposureBiasValue;
	double fEXIF_MaxApertureValue;
	double fEXIF_SubjectDistance;
	int fEXIF_MeteringMode;
	int fEXIF_LightSource;
	int fEXIF_Flash;
	double fEXIF_FocalLength;
	AnsiString fEXIF_SubsecTime;
	AnsiString fEXIF_SubsecTimeOriginal;
	AnsiString fEXIF_SubsecTimeDigitized;
	AnsiString fEXIF_FlashPixVersion;
	int fEXIF_ColorSpace;
	int fEXIF_ExifImageWidth;
	int fEXIF_ExifImageHeight;
	AnsiString fEXIF_RelatedSoundFile;
	double fEXIF_FocalPlaneXResolution;
	double fEXIF_FocalPlaneYResolution;
	int fEXIF_FocalPlaneResolutionUnit;
	double fEXIF_ExposureIndex;
	int fEXIF_SensingMethod;
	int fEXIF_FileSource;
	int fEXIF_SceneType;
	AnsiString fEXIF_UserComment;
	AnsiString fEXIF_UserCommentCode;
	Hyieutils::TIETagsHandler* fEXIF_MakerNote;
	WideString fEXIF_XPTitle;
	WideString fEXIF_XPComment;
	WideString fEXIF_XPAuthor;
	WideString fEXIF_XPKeywords;
	WideString fEXIF_XPSubject;
	int fAVI_FrameCount;
	int fAVI_FrameDelayTime;
	int fMEDIAFILE_FrameCount;
	int fMEDIAFILE_FrameDelayTime;
	int fPS_PaperWidth;
	int fPS_PaperHeight;
	TIOPSCompression fPS_Compression;
	AnsiString fPS_Title;
	int fPDF_PaperWidth;
	int fPDF_PaperHeight;
	TIOPDFCompression fPDF_Compression;
	AnsiString fPDF_Title;
	AnsiString fPDF_Author;
	AnsiString fPDF_Subject;
	AnsiString fPDF_Keywords;
	AnsiString fPDF_Creator;
	AnsiString fPDF_Producer;
	bool fRAW_HalfSize;
	double fRAW_Gamma;
	double fRAW_Bright;
	double fRAW_RedScale;
	double fRAW_BlueScale;
	bool fRAW_QuickInterpolate;
	bool fRAW_UseAutoWB;
	bool fRAW_UseCameraWB;
	bool fRAW_FourColorRGB;
	AnsiString fRAW_Camera;
	bool fRAW_GetExifThumbnail;
	bool fRAW_AutoAdjustColors;
	TIOBMPRAWChannelOrder fBMPRAW_ChannelOrder;
	TIOBMPRAWPlanes fBMPRAW_Planes;
	int fBMPRAW_RowAlign;
	int fBMPRAW_HeaderSize;
	AnsiString __fastcall GetFileTypeStr(void);
	void __fastcall SetEXIF_WhitePoint(int index, double v);
	double __fastcall GetEXIF_WhitePoint(int index);
	void __fastcall SetEXIF_PrimaryChromaticities(int index, double v);
	double __fastcall GetEXIF_PrimaryChromaticities(int index);
	void __fastcall SetEXIF_YCbCrCoefficients(int index, double v);
	double __fastcall GetEXIF_YCbCrCoefficients(int index);
	void __fastcall SetEXIF_ReferenceBlackWhite(int index, double v);
	double __fastcall GetEXIF_ReferenceBlackWhite(int index);
	void __fastcall SetEXIF_ISOSpeedRatings(int index, int v);
	int __fastcall GetEXIF_ISOSpeedRatings(int index);
	void __fastcall SetDpi(int Value);
	void __fastcall SetDpiX(int Value);
	void __fastcall SetDpiY(int Value);
	void __fastcall SetTIFF_Orientation(int Value);
	void __fastcall SetEXIF_Orientation(int Value);
	void __fastcall SetEXIF_XResolution(double Value);
	void __fastcall SetEXIF_YResolution(double Value);
	Hyieutils::TIEICC* __fastcall GetInputICC(void);
	Hyieutils::TIEICC* __fastcall GetOutputICC(void);
	Hyieutils::TIEImagingAnnot* __fastcall GetImagingAnnot(void);
	void __fastcall SetImageIndex(int value);
	void __fastcall SetImageCount(int value);
	void __fastcall SetGetThumbnail(bool value);
	void __fastcall SetJPEG_GetExifThumbnail(bool value);
	void __fastcall SetRAW_GetExifThumbnail(bool value);
	
public:
	bool IsNativePixelFormat;
	Hyiedefs::TRGB *fColorMap;
	int fColorMapCount;
	tagSIZE ICO_Sizes[16];
	int ICO_BitCount[16];
	Hyieutils::TIEICC* fInputICC;
	Hyieutils::TIEICC* fOutputICC;
	__property AnsiString FileName = {read=fFileName, write=fFileName};
	__property AnsiString FileTypeStr = {read=GetFileTypeStr};
	__property int FileType = {read=fFileType, write=fFileType, nodefault};
	__property int BitsPerSample = {read=fBitsPerSample, write=fBitsPerSample, nodefault};
	__property int SamplesPerPixel = {read=fSamplesPerPixel, write=fSamplesPerPixel, nodefault};
	__property int Width = {read=fWidth, write=fWidth, nodefault};
	__property int Height = {read=fHeight, write=fHeight, nodefault};
	__property int DpiX = {read=fDpiX, write=SetDpiX, nodefault};
	__property int DpiY = {read=fDpiY, write=SetDpiY, nodefault};
	__property int Dpi = {read=fDpiX, write=SetDpi, nodefault};
	__property Hyiedefs::PRGBROW ColorMap = {read=fColorMap};
	__property int ColorMapCount = {read=fColorMapCount, nodefault};
	__property int ImageIndex = {read=fImageIndex, write=SetImageIndex, nodefault};
	__property int ImageCount = {read=fImageCount, write=SetImageCount, nodefault};
	__property bool GetThumbnail = {read=fGetThumbnail, write=SetGetThumbnail, nodefault};
	__property Hyieutils::TIEICC* InputICCProfile = {read=GetInputICC};
	__property Hyieutils::TIEICC* OutputICCProfile = {read=GetOutputICC};
	__property Hyieutils::TIEIPTCInfoList* IPTC_Info = {read=fIPTC_Info};
	__property Hyieutils::TIEImagingAnnot* ImagingAnnot = {read=GetImagingAnnot};
	__property TIOTIFFCompression TIFF_Compression = {read=fTIFF_Compression, write=fTIFF_Compression, 
		nodefault};
	__property int TIFF_ImageIndex = {read=fTIFF_ImageIndex, write=SetImageIndex, nodefault};
	__property int TIFF_ImageCount = {read=fTIFF_ImageCount, write=SetImageCount, nodefault};
	__property TIOTIFFPhotometInterpret TIFF_PhotometInterpret = {read=fTIFF_PhotometInterpret, write=fTIFF_PhotometInterpret
		, nodefault};
	__property int TIFF_PlanarConf = {read=fTIFF_PlanarConf, write=fTIFF_PlanarConf, nodefault};
	__property int TIFF_XPos = {read=fTIFF_XPos, write=fTIFF_XPos, nodefault};
	__property int TIFF_YPos = {read=fTIFF_YPos, write=fTIFF_YPos, nodefault};
	__property AnsiString TIFF_DocumentName = {read=fTIFF_DocumentName, write=fTIFF_DocumentName};
	__property AnsiString TIFF_ImageDescription = {read=fTIFF_ImageDescription, write=fTIFF_ImageDescription
		};
	__property AnsiString TIFF_PageName = {read=fTIFF_PageName, write=fTIFF_PageName};
	__property int TIFF_PageNumber = {read=fTIFF_PageNumber, write=fTIFF_PageNumber, nodefault};
	__property int TIFF_PageCount = {read=fTIFF_PageCount, write=fTIFF_PageCount, nodefault};
	__property int TIFF_Orientation = {read=fTIFF_Orientation, write=SetTIFF_Orientation, nodefault};
	__property bool TIFF_EnableAdjustOrientation = {read=fTIFF_EnableAdjustOrientation, write=fTIFF_EnableAdjustOrientation
		, nodefault};
	__property TTIFFLZWDecompFunc TIFF_LZWDecompFunc = {read=fTIFF_LZWDecompFunc, write=fTIFF_LZWDecompFunc
		};
	__property TTIFFLZWCompFunc TIFF_LZWCompFunc = {read=fTIFF_LZWCompFunc, write=fTIFF_LZWCompFunc};
	__property int TIFF_JPEGQuality = {read=fTIFF_JPEGQuality, write=fTIFF_JPEGQuality, nodefault};
	__property TIOJPEGColorspace TIFF_JPEGColorSpace = {read=fTIFF_JPEGColorSpace, write=fTIFF_JPEGColorSpace
		, nodefault};
	__property int TIFF_FillOrder = {read=fTIFF_FillOrder, write=fTIFF_FillOrder, nodefault};
	__property AnsiString GIF_Version = {read=fGIF_Version, write=fGIF_Version};
	__property int GIF_ImageIndex = {read=fGIF_ImageIndex, write=SetImageIndex, nodefault};
	__property int GIF_ImageCount = {read=fGIF_ImageCount, write=SetImageCount, nodefault};
	__property int GIF_XPos = {read=fGIF_XPos, write=fGIF_XPos, nodefault};
	__property int GIF_YPos = {read=fGIF_YPos, write=fGIF_YPos, nodefault};
	__property int GIF_DelayTime = {read=fGIF_DelayTime, write=fGIF_DelayTime, nodefault};
	__property bool GIF_FlagTranspColor = {read=fGIF_FlagTranspColor, write=fGIF_FlagTranspColor, nodefault
		};
	__property Hyiedefs::TRGB GIF_TranspColor = {read=fGIF_TranspColor, write=fGIF_TranspColor};
	__property bool GIF_Interlaced = {read=fGIF_Interlaced, write=fGIF_Interlaced, nodefault};
	__property int GIF_WinWidth = {read=fGIF_WinWidth, write=fGIF_WinWidth, nodefault};
	__property int GIF_WinHeight = {read=fGIF_WinHeight, write=fGIF_WinHeight, nodefault};
	__property Hyiedefs::TRGB GIF_Background = {read=fGIF_Background, write=fGIF_Background};
	__property int GIF_Ratio = {read=fGIF_Ratio, write=fGIF_Ratio, nodefault};
	__property Classes::TStringList* GIF_Comments = {read=fGIF_Comments};
	__property TIEGIFAction GIF_Action = {read=fGIF_Action, write=fGIF_Action, nodefault};
	__property TGIFLZWDecompFunc GIF_LZWDecompFunc = {read=fGIF_LZWDecompFunc, write=fGIF_LZWDecompFunc
		};
	__property TGIFLZWCompFunc GIF_LZWCompFunc = {read=fGIF_LZWCompFunc, write=fGIF_LZWCompFunc};
	__property int DCX_ImageIndex = {read=fDCX_ImageIndex, write=SetImageIndex, nodefault};
	__property TIOJPEGColorspace JPEG_ColorSpace = {read=fJPEG_ColorSpace, write=fJPEG_ColorSpace, nodefault
		};
	__property int JPEG_Quality = {read=fJPEG_Quality, write=fJPEG_Quality, nodefault};
	__property TIOJPEGDctMethod JPEG_DCTMethod = {read=fJPEG_DCTMethod, write=fJPEG_DCTMethod, nodefault
		};
	__property bool JPEG_OptimalHuffman = {read=fJPEG_OptimalHuffman, write=fJPEG_OptimalHuffman, nodefault
		};
	__property int JPEG_Smooth = {read=fJPEG_Smooth, write=fJPEG_Smooth, nodefault};
	__property bool JPEG_Progressive = {read=fJPEG_Progressive, write=fJPEG_Progressive, nodefault};
	__property TIOJPEGScale JPEG_Scale = {read=fJPEG_Scale, write=fJPEG_Scale, nodefault};
	__property Hyieutils::TIEMarkerList* JPEG_MarkerList = {read=fJPEG_MarkerList};
	__property int JPEG_Scale_Used = {read=fJPEG_Scale_Used, write=fJPEG_Scale_Used, nodefault};
	__property int JPEG_WarningTot = {read=fJPEG_WarningTot, write=fJPEG_WarningTot, nodefault};
	__property int JPEG_WarningCode = {read=fJPEG_WarningCode, write=fJPEG_WarningCode, nodefault};
	__property int JPEG_OriginalWidth = {read=fJPEG_OriginalWidth, write=fJPEG_OriginalWidth, nodefault
		};
	__property int JPEG_OriginalHeight = {read=fJPEG_OriginalHeight, write=fJPEG_OriginalHeight, nodefault
		};
	__property bool JPEG_EnableAdjustOrientation = {read=fJPEG_EnableAdjustOrientation, write=fJPEG_EnableAdjustOrientation
		, nodefault};
	__property bool JPEG_GetExifThumbnail = {read=fJPEG_GetExifThumbnail, write=SetJPEG_GetExifThumbnail
		, nodefault};
	__property TIOJ2000ColorSpace J2000_ColorSpace = {read=fJ2000_ColorSpace, write=fJ2000_ColorSpace, 
		nodefault};
	__property double J2000_Rate = {read=fJ2000_Rate, write=fJ2000_Rate};
	__property TIOJ2000ScalableBy J2000_ScalableBy = {read=fJ2000_ScalableBy, write=fJ2000_ScalableBy, 
		nodefault};
	__property int PCX_Version = {read=fPCX_Version, write=fPCX_Version, nodefault};
	__property TIOPCXCompression PCX_Compression = {read=fPCX_Compression, write=fPCX_Compression, nodefault
		};
	__property TIOBMPVersion BMP_Version = {read=fBMP_Version, write=fBMP_Version, nodefault};
	__property TIOBMPCompression BMP_Compression = {read=fBMP_Compression, write=fBMP_Compression, nodefault
		};
	__property int ICO_ImageIndex = {read=fICO_ImageIndex, write=SetImageIndex, nodefault};
	__property Hyiedefs::TRGB ICO_Background = {read=fICO_Background, write=fICO_Background};
	__property int CUR_ImageIndex = {read=fCUR_ImageIndex, write=SetImageIndex, nodefault};
	__property int CUR_XHotSpot = {read=fCUR_XHotSpot, write=fCUR_XHotSpot, nodefault};
	__property int CUR_YHotSpot = {read=fCUR_YHotSpot, write=fCUR_YHotSpot, nodefault};
	__property Hyiedefs::TRGB CUR_Background = {read=fCUR_Background, write=fCUR_Background};
	__property bool PNG_Interlaced = {read=fPNG_Interlaced, write=fPNG_Interlaced, nodefault};
	__property Hyiedefs::TRGB PNG_Background = {read=fPNG_Background, write=fPNG_Background};
	__property TIOPNGFilter PNG_Filter = {read=fPNG_Filter, write=fPNG_Filter, nodefault};
	__property int PNG_Compression = {read=fPNG_Compression, write=fPNG_Compression, nodefault};
	__property Classes::TStringList* PNG_TextKeys = {read=fPNG_TextKeys};
	__property Classes::TStringList* PNG_TextValues = {read=fPNG_TextValues};
	__property int TGA_XPos = {read=fTGA_XPos, write=fTGA_XPos, nodefault};
	__property int TGA_YPos = {read=fTGA_YPos, write=fTGA_YPos, nodefault};
	__property bool TGA_Compressed = {read=fTGA_Compressed, write=fTGA_Compressed, nodefault};
	__property AnsiString TGA_Descriptor = {read=fTGA_Descriptor, write=fTGA_Descriptor};
	__property AnsiString TGA_Author = {read=fTGA_Author, write=fTGA_Author};
	__property System::TDateTime TGA_Date = {read=fTGA_Date, write=fTGA_Date};
	__property AnsiString TGA_ImageName = {read=fTGA_ImageName, write=fTGA_ImageName};
	__property Hyiedefs::TRGB TGA_Background = {read=fTGA_Background, write=fTGA_Background};
	__property double TGA_AspectRatio = {read=fTGA_AspectRatio, write=fTGA_AspectRatio};
	__property double TGA_Gamma = {read=fTGA_Gamma, write=fTGA_Gamma};
	__property bool TGA_GrayLevel = {read=fTGA_GrayLevel, write=fTGA_GrayLevel, nodefault};
	__property int AVI_FrameCount = {read=fAVI_FrameCount, write=fAVI_FrameCount, nodefault};
	__property int AVI_FrameDelayTime = {read=fAVI_FrameDelayTime, write=fAVI_FrameDelayTime, nodefault
		};
	__property int MEDIAFILE_FrameCount = {read=fMEDIAFILE_FrameCount, write=fMEDIAFILE_FrameCount, nodefault
		};
	__property int MEDIAFILE_FrameDelayTime = {read=fMEDIAFILE_FrameDelayTime, write=fMEDIAFILE_FrameDelayTime
		, nodefault};
	__property Classes::TStringList* PXM_Comments = {read=fPXM_Comments};
	__property int PS_PaperWidth = {read=fPS_PaperWidth, write=fPS_PaperWidth, nodefault};
	__property int PS_PaperHeight = {read=fPS_PaperHeight, write=fPS_PaperHeight, nodefault};
	__property TIOPSCompression PS_Compression = {read=fPS_Compression, write=fPS_Compression, nodefault
		};
	__property AnsiString PS_Title = {read=fPS_Title, write=fPS_Title};
	__property int PDF_PaperWidth = {read=fPDF_PaperWidth, write=fPDF_PaperWidth, nodefault};
	__property int PDF_PaperHeight = {read=fPDF_PaperHeight, write=fPDF_PaperHeight, nodefault};
	__property TIOPDFCompression PDF_Compression = {read=fPDF_Compression, write=fPDF_Compression, nodefault
		};
	__property AnsiString PDF_Title = {read=fPDF_Title, write=fPDF_Title};
	__property AnsiString PDF_Author = {read=fPDF_Author, write=fPDF_Author};
	__property AnsiString PDF_Subject = {read=fPDF_Subject, write=fPDF_Subject};
	__property AnsiString PDF_Keywords = {read=fPDF_Keywords, write=fPDF_Keywords};
	__property AnsiString PDF_Creator = {read=fPDF_Creator, write=fPDF_Creator};
	__property AnsiString PDF_Producer = {read=fPDF_Producer, write=fPDF_Producer};
	__property bool EXIF_HasEXIFData = {read=fEXIF_HasEXIFData, write=fEXIF_HasEXIFData, nodefault};
	__property Hyieutils::TIEBitmap* EXIF_Bitmap = {read=fEXIF_Bitmap, write=fEXIF_Bitmap};
	__property AnsiString EXIF_ImageDescription = {read=fEXIF_ImageDescription, write=fEXIF_ImageDescription
		};
	__property AnsiString EXIF_Make = {read=fEXIF_Make, write=fEXIF_Make};
	__property AnsiString EXIF_Model = {read=fEXIF_Model, write=fEXIF_Model};
	__property int EXIF_Orientation = {read=fEXIF_Orientation, write=SetEXIF_Orientation, nodefault};
	__property double EXIF_XResolution = {read=fEXIF_XResolution, write=SetEXIF_XResolution};
	__property double EXIF_YResolution = {read=fEXIF_YResolution, write=SetEXIF_YResolution};
	__property int EXIF_ResolutionUnit = {read=fEXIF_ResolutionUnit, write=fEXIF_ResolutionUnit, nodefault
		};
	__property AnsiString EXIF_Software = {read=fEXIF_Software, write=fEXIF_Software};
	__property AnsiString EXIF_Artist = {read=fEXIF_Artist, write=fEXIF_Artist};
	__property AnsiString EXIF_DateTime = {read=fEXIF_DateTime, write=fEXIF_DateTime};
	__property double EXIF_WhitePoint[int index] = {read=GetEXIF_WhitePoint, write=SetEXIF_WhitePoint};
		
	__property double EXIF_PrimaryChromaticities[int index] = {read=GetEXIF_PrimaryChromaticities, write=
		SetEXIF_PrimaryChromaticities};
	__property double EXIF_YCbCrCoefficients[int index] = {read=GetEXIF_YCbCrCoefficients, write=SetEXIF_YCbCrCoefficients
		};
	__property int EXIF_YCbCrPositioning = {read=fEXIF_YCbCrPositioning, write=fEXIF_YCbCrPositioning, 
		nodefault};
	__property double EXIF_ReferenceBlackWhite[int index] = {read=GetEXIF_ReferenceBlackWhite, write=SetEXIF_ReferenceBlackWhite
		};
	__property AnsiString EXIF_Copyright = {read=fEXIF_Copyright, write=fEXIF_Copyright};
	__property double EXIF_ExposureTime = {read=fEXIF_ExposureTime, write=fEXIF_ExposureTime};
	__property double EXIF_FNumber = {read=fEXIF_FNumber, write=fEXIF_FNumber};
	__property int EXIF_ExposureProgram = {read=fEXIF_ExposureProgram, write=fEXIF_ExposureProgram, nodefault
		};
	__property int EXIF_ISOSpeedRatings[int index] = {read=GetEXIF_ISOSpeedRatings, write=SetEXIF_ISOSpeedRatings
		};
	__property AnsiString EXIF_ExifVersion = {read=fEXIF_ExifVersion, write=fEXIF_ExifVersion};
	__property AnsiString EXIF_DateTimeOriginal = {read=fEXIF_DateTimeOriginal, write=fEXIF_DateTimeOriginal
		};
	__property AnsiString EXIF_DateTimeDigitized = {read=fEXIF_DateTimeDigitized, write=fEXIF_DateTimeDigitized
		};
	__property double EXIF_CompressedBitsPerPixel = {read=fEXIF_CompressedBitsPerPixel, write=fEXIF_CompressedBitsPerPixel
		};
	__property double EXIF_ShutterSpeedValue = {read=fEXIF_ShutterSpeedValue, write=fEXIF_ShutterSpeedValue
		};
	__property double EXIF_ApertureValue = {read=fEXIF_ApertureValue, write=fEXIF_ApertureValue};
	__property double EXIF_BrightnessValue = {read=fEXIF_BrightnessValue, write=fEXIF_BrightnessValue};
		
	__property double EXIF_ExposureBiasValue = {read=fEXIF_ExposureBiasValue, write=fEXIF_ExposureBiasValue
		};
	__property double EXIF_MaxApertureValue = {read=fEXIF_MaxApertureValue, write=fEXIF_MaxApertureValue
		};
	__property double EXIF_SubjectDistance = {read=fEXIF_SubjectDistance, write=fEXIF_SubjectDistance};
		
	__property int EXIF_MeteringMode = {read=fEXIF_MeteringMode, write=fEXIF_MeteringMode, nodefault};
	__property int EXIF_LightSource = {read=fEXIF_LightSource, write=fEXIF_LightSource, nodefault};
	__property int EXIF_Flash = {read=fEXIF_Flash, write=fEXIF_Flash, nodefault};
	__property double EXIF_FocalLength = {read=fEXIF_FocalLength, write=fEXIF_FocalLength};
	__property AnsiString EXIF_SubsecTime = {read=fEXIF_SubsecTime, write=fEXIF_SubsecTime};
	__property AnsiString EXIF_SubsecTimeOriginal = {read=fEXIF_SubsecTimeOriginal, write=fEXIF_SubsecTimeOriginal
		};
	__property AnsiString EXIF_SubsecTimeDigitized = {read=fEXIF_SubsecTimeDigitized, write=fEXIF_SubsecTimeDigitized
		};
	__property AnsiString EXIF_FlashPixVersion = {read=fEXIF_FlashPixVersion, write=fEXIF_FlashPixVersion
		};
	__property int EXIF_ColorSpace = {read=fEXIF_ColorSpace, write=fEXIF_ColorSpace, nodefault};
	__property int EXIF_ExifImageWidth = {read=fEXIF_ExifImageWidth, write=fEXIF_ExifImageWidth, nodefault
		};
	__property int EXIF_ExifImageHeight = {read=fEXIF_ExifImageHeight, write=fEXIF_ExifImageHeight, nodefault
		};
	__property AnsiString EXIF_RelatedSoundFile = {read=fEXIF_RelatedSoundFile, write=fEXIF_RelatedSoundFile
		};
	__property double EXIF_FocalPlaneXResolution = {read=fEXIF_FocalPlaneXResolution, write=fEXIF_FocalPlaneXResolution
		};
	__property double EXIF_FocalPlaneYResolution = {read=fEXIF_FocalPlaneYResolution, write=fEXIF_FocalPlaneYResolution
		};
	__property int EXIF_FocalPlaneResolutionUnit = {read=fEXIF_FocalPlaneResolutionUnit, write=fEXIF_FocalPlaneResolutionUnit
		, nodefault};
	__property double EXIF_ExposureIndex = {read=fEXIF_ExposureIndex, write=fEXIF_ExposureIndex};
	__property int EXIF_SensingMethod = {read=fEXIF_SensingMethod, write=fEXIF_SensingMethod, nodefault
		};
	__property int EXIF_FileSource = {read=fEXIF_FileSource, write=fEXIF_FileSource, nodefault};
	__property int EXIF_SceneType = {read=fEXIF_SceneType, write=fEXIF_SceneType, nodefault};
	__property AnsiString EXIF_UserComment = {read=fEXIF_UserComment, write=fEXIF_UserComment};
	__property AnsiString EXIF_UserCommentCode = {read=fEXIF_UserCommentCode, write=fEXIF_UserCommentCode
		};
	__property Hyieutils::TIETagsHandler* EXIF_MakerNote = {read=fEXIF_MakerNote};
	__property WideString EXIF_XPTitle = {read=fEXIF_XPTitle, write=fEXIF_XPTitle};
	__property WideString EXIF_XPComment = {read=fEXIF_XPComment, write=fEXIF_XPComment};
	__property WideString EXIF_XPAuthor = {read=fEXIF_XPAuthor, write=fEXIF_XPAuthor};
	__property WideString EXIF_XPKeywords = {read=fEXIF_XPKeywords, write=fEXIF_XPKeywords};
	__property WideString EXIF_XPSubject = {read=fEXIF_XPSubject, write=fEXIF_XPSubject};
	__property bool RAW_HalfSize = {read=fRAW_HalfSize, write=fRAW_HalfSize, nodefault};
	__property double RAW_Gamma = {read=fRAW_Gamma, write=fRAW_Gamma};
	__property double RAW_Bright = {read=fRAW_Bright, write=fRAW_Bright};
	__property double RAW_RedScale = {read=fRAW_RedScale, write=fRAW_RedScale};
	__property double RAW_BlueScale = {read=fRAW_BlueScale, write=fRAW_BlueScale};
	__property bool RAW_QuickInterpolate = {read=fRAW_QuickInterpolate, write=fRAW_QuickInterpolate, nodefault
		};
	__property bool RAW_UseAutoWB = {read=fRAW_UseAutoWB, write=fRAW_UseAutoWB, nodefault};
	__property bool RAW_UseCameraWB = {read=fRAW_UseCameraWB, write=fRAW_UseCameraWB, nodefault};
	__property bool RAW_FourColorRGB = {read=fRAW_FourColorRGB, write=fRAW_FourColorRGB, nodefault};
	__property AnsiString RAW_Camera = {read=fRAW_Camera, write=fRAW_Camera};
	__property bool RAW_GetExifThumbnail = {read=fRAW_GetExifThumbnail, write=SetRAW_GetExifThumbnail, 
		nodefault};
	__property bool RAW_AutoAdjustColors = {read=fRAW_AutoAdjustColors, write=fRAW_AutoAdjustColors, nodefault
		};
	__property TIOBMPRAWChannelOrder BMPRAW_ChannelOrder = {read=fBMPRAW_ChannelOrder, write=fBMPRAW_ChannelOrder
		, nodefault};
	__property TIOBMPRAWPlanes BMPRAW_Planes = {read=fBMPRAW_Planes, write=fBMPRAW_Planes, nodefault};
	__property int BMPRAW_RowAlign = {read=fBMPRAW_RowAlign, write=fBMPRAW_RowAlign, nodefault};
	__property int BMPRAW_HeaderSize = {read=fBMPRAW_HeaderSize, write=fBMPRAW_HeaderSize, nodefault};
	__fastcall TIOParamsVals(TImageEnIO* IEIO);
	__fastcall virtual ~TIOParamsVals(void);
	void __fastcall SetDefaultParams(void);
	void __fastcall Assign(TIOParamsVals* Source);
	void __fastcall AssignCompressionInfo(TIOParamsVals* Source);
	void __fastcall SaveToFile(const AnsiString FileName);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	__property TImageEnIO* ImageEnIO = {read=fImageEnIO};
	void __fastcall ResetInfo(void);
	void __fastcall ResetEXIF(void);
	AnsiString __fastcall GetProperty(const AnsiString Prop);
	void __fastcall SetProperty(AnsiString Prop, AnsiString Value);
};


typedef TIETWainShared *PIETWainShared;

typedef Sysutils::TMethod *PMethod;

#pragma option push -b-
enum TIEIOMethodTypes { ieLoadSaveFile, ieLoadSaveStream, ieLoadSaveFileRetInt, ieRetBool, ieLoadSaveStreamRetInt, 
	ieLoadSaveFileFormat, ieLoadSaveStreamFormat, ieCaptureFromScreen, ieLoadSaveIndex, ieImportMetaFile, 
	ieLoadFromURL, ieAcquire };
#pragma option pop

typedef void __fastcall (__closure *TIEIOMethodType_LoadSaveFile)(const AnsiString nf);

typedef void __fastcall (__closure *TIEIOMethodType_LoadSaveStream)(Classes::TStream* Stream);

typedef int __fastcall (__closure *TIEIOMethodType_LoadSaveFileRetInt)(const AnsiString nf);

typedef bool __fastcall (__closure *TIEIOMethodType_RetBool)(void);

typedef int __fastcall (__closure *TIEIOMethodType_LoadSaveStreamRetInt)(Classes::TStream* Stream);

typedef void __fastcall (__closure *TIEIOMethodType_LoadSaveFileFormat)(const AnsiString nf, int FileFormat
	);

typedef void __fastcall (__closure *TIEIOMethodType_LoadSaveStreamFormat)(Classes::TStream* Stream, 
	int FileFormat);

typedef void __fastcall (__closure *TIEIOMethodType_CaptureFromScreen)(TIECSSource Source, Controls::TCursor 
	MouseCursor);

typedef void __fastcall (__closure *TIEIOMethodType_LoadSaveIndex)(int Index);

typedef void __fastcall (__closure *TIEIOMethodType_ImportMetaFile)(const AnsiString nf, int Width, 
	int Height, bool WithAlpha);

typedef void __fastcall (__closure *TIEIOMethodType_LoadFromURL)(AnsiString URL);

typedef bool __fastcall (__closure *TIEIOMethodType_Acquire)(TIEAcquireApi api);

class DELPHICLASS TIEIOThread;
class PASCALIMPLEMENTATION TIEIOThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	Classes::TList* fThreadList;
	TIEIOMethodTypes fMethodType;
	TIEIOMethodType_LoadSaveFile fMethod_LoadSaveFile;
	TIEIOMethodType_LoadSaveStream fMethod_LoadSaveStream;
	TIEIOMethodType_LoadSaveFileRetInt fMethod_LoadSaveFileRetInt;
	TIEIOMethodType_RetBool fMethod_RetBool;
	TIEIOMethodType_LoadSaveStreamRetInt fMethod_LoadSaveStreamRetInt;
	TIEIOMethodType_LoadSaveFileFormat fMethod_LoadSaveFileFormat;
	TIEIOMethodType_LoadSaveStreamFormat fMethod_LoadSaveStreamFormat;
	TIEIOMethodType_CaptureFromScreen fMethod_CaptureFromScreen;
	TIEIOMethodType_LoadSaveIndex fMethod_LoadSaveIndex;
	TIEIOMethodType_ImportMetaFile fMethod_ImportMetaFile;
	TIEIOMethodType_LoadFromURL fMethod_LoadFromURL;
	TIEIOMethodType_Acquire fMethod_Acquire;
	AnsiString p_nf;
	Classes::TStream* p_stream;
	int p_fileformat;
	TIECSSource p_source;
	int p_index;
	int p_width;
	int p_height;
	bool p_withalpha;
	Controls::TCursor p_mouseCursor;
	AnsiString p_URL;
	TIEAcquireApi p_api;
	unsigned fThreadID;
	TImageEnIO* fOwner;
	
public:
	virtual void __fastcall Execute(void);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_LoadSaveFile 
		InMethod, const AnsiString in_nf);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_LoadSaveStream 
		InMethod, Classes::TStream* in_Stream);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_LoadSaveFileRetInt 
		InMethod, const AnsiString in_nf);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_RetBool InMethod
		);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_LoadSaveStreamRetInt 
		InMethod, Classes::TStream* in_Stream);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_LoadSaveFileFormat 
		InMethod, const AnsiString in_nf, int in_fileformat);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_LoadSaveStreamFormat 
		InMethod, Classes::TStream* in_Stream, int in_fileformat);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_CaptureFromScreen 
		InMethod, TIECSSource in_source, Controls::TCursor in_mouseCursor);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_LoadSaveIndex 
		InMethod, int in_index);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_ImportMetaFile 
		InMethod, const AnsiString in_nf, int in_width, int in_height, bool in_withalpha);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_Acquire InMethod
		, TIEAcquireApi in_api);
	__fastcall TIEIOThread(TImageEnIO* owner, Classes::TList* InThreadList, TIEIOMethodType_LoadFromURL 
		InMethod, const AnsiString in_URL, double dummy);
	__property unsigned ThreadID = {read=fThreadID, nodefault};
public:
	#pragma option push -w-inl
	/* TThread.Create */ inline __fastcall TIEIOThread(bool CreateSuspended) : Classes::TThread(CreateSuspended
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TThread.Destroy */ inline __fastcall virtual ~TIEIOThread(void) { }
	#pragma option pop
	
};


typedef void __fastcall (*TIEReadImageStream)(Classes::TStream* Stream, Hyieutils::TIEBitmap* Bitmap
	, TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress, bool Preview);

typedef void __fastcall (*TIEWriteImageStream)(Classes::TStream* Stream, Hyieutils::TIEBitmap* Bitmap
	, TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &Progress);

typedef bool __fastcall (*TIETryImageStream)(Classes::TStream* Stream, int TryingFormat);

struct TIEFileFormatInfo
{
	int FileType;
	System::SmallString<80>  FullName;
	System::SmallString<80>  Extensions;
	bool InternalFormat;
	TPreviewParams DialogPage;
	TIEReadImageStream ReadFunction;
	TIEWriteImageStream WriteFunction;
	TIETryImageStream TryFunction;
} ;

typedef TIEFileFormatInfo *PIEFileFormatInfo;

#pragma option push -b-
enum TIEColorSpace { iecmsRGB, iecmsBGR, iecmsCMYK, iecmsCMYK6, iecmsCIELab, iecmsGray8, iecmsRGB48, 
	iecmsRGB48_SE, iecmsYCBCR };
#pragma option pop

typedef void __fastcall (*TIEConvertColorFunction)(void * InputScanline, TIEColorSpace InputColorSpace
	, void * OutputScanline, TIEColorSpace OutputColorSpace, int ImageWidth, TIOParamsVals* IOParams);

//-- var, const, procedure ---------------------------------------------------
static const Shortint ioUnknown = 0x0;
static const Shortint ioTIFF = 0x1;
static const Shortint ioGIF = 0x2;
static const Shortint ioJPEG = 0x3;
static const Shortint ioPCX = 0x4;
static const Shortint ioBMP = 0x5;
static const Shortint ioICO = 0x6;
static const Shortint ioCUR = 0x7;
static const Shortint ioPNG = 0x8;
static const Shortint ioWMF = 0x9;
static const Shortint ioEMF = 0xa;
static const Shortint ioTGA = 0xb;
static const Shortint ioPXM = 0xc;
static const Shortint ioJP2 = 0xd;
static const Shortint ioJ2K = 0xe;
static const Shortint ioAVI = 0xf;
static const Shortint ioWBMP = 0x10;
static const Shortint ioPS = 0x11;
static const Shortint ioPDF = 0x12;
static const Shortint ioDCX = 0x13;
static const Shortint ioRAW = 0x14;
static const Shortint ioBMPRAW = 0x15;
static const Shortint ioWMV = 0x16;
static const Shortint ioMPEG = 0x17;
static const Word ioDLLPLUGINS = 0x1000;
static const Word ioUSER = 0x2710;
static const Shortint IEMAXICOIMAGES = 0x10;
static const Byte JPEG_APP0 = 0xe0;
static const Byte JPEG_APP1 = 0xe1;
static const Byte JPEG_APP2 = 0xe2;
static const Byte JPEG_APP3 = 0xe3;
static const Byte JPEG_APP4 = 0xe4;
static const Byte JPEG_APP5 = 0xe5;
static const Byte JPEG_APP6 = 0xe6;
static const Byte JPEG_APP7 = 0xe7;
static const Byte JPEG_APP8 = 0xe8;
static const Byte JPEG_APP9 = 0xe9;
static const Byte JPEG_APP10 = 0xea;
static const Byte JPEG_APP11 = 0xeb;
static const Byte JPEG_APP12 = 0xec;
static const Byte JPEG_APP13 = 0xed;
static const Byte JPEG_APP14 = 0xee;
static const Byte JPEG_APP15 = 0xef;
static const Byte JPEG_COM = 0xfe;
static const Shortint IETW_NONE = 0x0;
static const Shortint IETW_A4LETTER = 0x1;
static const Shortint IETW_B5LETTER = 0x2;
static const Shortint IETW_USLETTER = 0x3;
static const Shortint IETW_USLEGAL = 0x4;
static const Shortint IETW_A5 = 0x5;
static const Shortint IETW_B4 = 0x6;
static const Shortint IETW_B6 = 0x7;
static const Shortint IETW_USLEDGER = 0x9;
static const Shortint IETW_USEXECUTIVE = 0xa;
static const Shortint IETW_A3 = 0xb;
static const Shortint IETW_B3 = 0xc;
static const Shortint IETW_A6 = 0xd;
static const Shortint IETW_C4 = 0xe;
static const Shortint IETW_C5 = 0xf;
static const Shortint IETW_C6 = 0x10;
static const Shortint IETW_4A0 = 0x11;
static const Shortint IETW_2A0 = 0x12;
static const Shortint IETW_A0 = 0x13;
static const Shortint IETW_A1 = 0x14;
static const Shortint IETW_A2 = 0x15;
static const Shortint IETW_A4 = 0x1;
static const Shortint IETW_A7 = 0x16;
static const Shortint IETW_A8 = 0x17;
static const Shortint IETW_A9 = 0x18;
static const Shortint IETW_A10 = 0x19;
static const Shortint IETW_ISOB0 = 0x1a;
static const Shortint IETW_ISOB1 = 0x1b;
static const Shortint IETW_ISOB2 = 0x1c;
static const Shortint IETW_ISOB3 = 0xc;
static const Shortint IETW_ISOB4 = 0x6;
static const Shortint IETW_ISOB5 = 0x1d;
static const Shortint IETW_ISOB6 = 0x7;
static const Shortint IETW_ISOB7 = 0x1e;
static const Shortint IETW_ISOB8 = 0x1f;
static const Shortint IETW_ISOB9 = 0x20;
static const Shortint IETW_ISOB10 = 0x21;
static const Shortint IETW_JISB0 = 0x22;
static const Shortint IETW_JISB1 = 0x23;
static const Shortint IETW_JISB2 = 0x24;
static const Shortint IETW_JISB3 = 0x25;
static const Shortint IETW_JISB4 = 0x26;
static const Shortint IETW_JISB5 = 0x2;
static const Shortint IETW_JISB6 = 0x27;
static const Shortint IETW_JISB7 = 0x28;
static const Shortint IETW_JISB8 = 0x29;
static const Shortint IETW_JISB9 = 0x2a;
static const Shortint IETW_JISB10 = 0x2b;
static const Shortint IETW_C0 = 0x2c;
static const Shortint IETW_C1 = 0x2d;
static const Shortint IETW_C2 = 0x2e;
static const Shortint IETW_C3 = 0x2f;
static const Shortint IETW_C7 = 0x30;
static const Shortint IETW_C8 = 0x31;
static const Shortint IETW_C9 = 0x32;
static const Shortint IETW_C10 = 0x33;
static const Shortint IETW_USSTATEMENT = 0x34;
static const Shortint IETW_BUSINESSCARD = 0x35;
extern PACKAGE TGIFLZWDecompFunc DefGIF_LZWDECOMPFUNC;
extern PACKAGE TGIFLZWCompFunc DefGIF_LZWCOMPFUNC;
extern PACKAGE TTIFFLZWDecompFunc DefTIFF_LZWDECOMPFUNC;
extern PACKAGE TTIFFLZWCompFunc DefTIFF_LZWCOMPFUNC;
extern PACKAGE Classes::TList* iegFileFormats;
extern PACKAGE AnsiString DefTEMPPATH;
extern PACKAGE AnsiString iegTWainLogName;
extern PACKAGE TextFile iegTWainLogFile;
extern PACKAGE TIEConvertColorFunction IEConvertColorFunction;
extern PACKAGE bool iegEnableCMS;
extern PACKAGE int iegObjectsTIFFTag;
extern PACKAGE int __fastcall DeleteGIFIm(const AnsiString nf, int idx);
extern PACKAGE int __fastcall DeleteTIFFIm(const AnsiString nf, int idx);
extern PACKAGE void __fastcall DeleteDCXIm(const AnsiString nf, int idx);
extern PACKAGE int __fastcall DeleteTIFFImGroup(const AnsiString nf, const int * Indexes, const int 
	Indexes_Size);
extern PACKAGE int __fastcall EnumGIFIm(const AnsiString nf);
extern PACKAGE int __fastcall EnumTIFFIm(const AnsiString nf);
extern PACKAGE int __fastcall EnumDCXIm(const AnsiString nf);
extern PACKAGE int __fastcall EnumTIFFStream(Classes::TStream* Stream);
extern PACKAGE int __fastcall EnumICOIm(const AnsiString nf);
extern PACKAGE bool __fastcall CheckAniGIF(const AnsiString nf);
extern PACKAGE bool __fastcall IsKnownFormat(const AnsiString FileName);
extern PACKAGE int __fastcall FindFileFormat(const AnsiString nf, bool VerifyExtension);
extern PACKAGE int __fastcall FindStreamFormat(Classes::TStream* fs);
extern PACKAGE PIEFileFormatInfo __fastcall IEFileFormatGetInfo(int FileType);
extern PACKAGE int __fastcall IEFileFormatGetExtCount(int FileType);
extern PACKAGE AnsiString __fastcall IEFileFormatGetExt(int FileType, int idx);
extern PACKAGE PIEFileFormatInfo __fastcall IEFileFormatGetInfo2(AnsiString Extension);
extern PACKAGE void __fastcall IEFileFormatAdd(const TIEFileFormatInfo &FileFormatInfo);
extern PACKAGE void __fastcall IEFileFormatRemove(int FileType);
extern PACKAGE void __fastcall IEUpdateGIFStatus(void);
extern PACKAGE Hyieutils::TIEBitmap* __fastcall IEAdjustDPI(Hyieutils::TIEBitmap* bmp, TIOParamsVals* 
	Params, bool FilteredAdjustDPI);
extern PACKAGE bool __fastcall JpegLosslessTransformStream(Classes::TStream* SourceStream, Classes::TStream* 
	DestStream, TIEJpegTransform Transform, bool GrayScale, TIEJpegCopyMarkers CopyMarkers, const Windows::TRect 
	&CutRect);
extern PACKAGE bool __fastcall JpegLosslessTransform(const AnsiString SourceFile, const AnsiString DestFile
	, TIEJpegTransform Transform, bool GrayScale, TIEJpegCopyMarkers CopyMarkers, const Windows::TRect 
	&CutRect);
extern PACKAGE bool __fastcall JpegLosslessTransform2(const AnsiString FileName, TIEJpegTransform Transform
	, bool GrayScale, TIEJpegCopyMarkers CopyMarkers, const Windows::TRect &CutRect);
extern PACKAGE void __fastcall ExtractTIFFImageStream(Classes::TStream* SourceStream, Classes::TStream* 
	OutStream, int idx);
extern PACKAGE void __fastcall ExtractTIFFImageFile(const AnsiString SourceFileName, const AnsiString 
	OutFileName, int idx);
extern PACKAGE void __fastcall InsertTIFFImageStream(Classes::TStream* SourceStream, Classes::TStream* 
	InsertingStream, Classes::TStream* OutStream, int idx);
extern PACKAGE void __fastcall InsertTIFFImageFile(const AnsiString SourceFileName, const AnsiString 
	InsertingFileName, const AnsiString OutFileName, int idx);
extern PACKAGE void __fastcall IEWriteICOImages(const AnsiString fileName, System::TObject* const * 
	images, const int images_Size);
extern PACKAGE Hyiedefs::TRGB __fastcall IECMYK2RGB(Hyiedefs::TCMYK cmyk);
extern PACKAGE Hyiedefs::TCMYK __fastcall IERGB2CMYK(const Hyiedefs::TRGB rgb);
extern PACKAGE void __fastcall IEDefaultConvertColorFunction(void * InputScanline, TIEColorSpace InputColorSpace
	, void * OutputScanline, TIEColorSpace OutputColorSpace, int ImageWidth, TIOParamsVals* IOParams);
extern PACKAGE int __fastcall IECalcJpegFileQuality(const AnsiString FileName);
extern PACKAGE int __fastcall IECalcJpegStreamQuality(Classes::TStream* Stream);
extern PACKAGE int __fastcall IEGetFileFramesCount(const AnsiString FileName);
extern PACKAGE int __fastcall IEExtToFileFormat(AnsiString ex);
extern PACKAGE bool __fastcall IEIsInternalFormat(AnsiString ex);
extern PACKAGE AnsiString __fastcall IEAVISelectCodec(void);
extern PACKAGE bool __fastcall IEIsExtIOPluginLoaded(const AnsiString FileName);
extern PACKAGE int __fastcall IEAddExtIOPlugin(const AnsiString FileName);
extern PACKAGE void __fastcall IEOptimizeGIF(const AnsiString InputFile, const AnsiString OutputFile
	);

}	/* namespace Imageenio */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Imageenio;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// imageenio
