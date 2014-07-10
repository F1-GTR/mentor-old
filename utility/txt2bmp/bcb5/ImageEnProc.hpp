// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'imageenproc.pas' rev: 5.00

#ifndef imageenprocHPP
#define imageenprocHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ieXtraTransitions.hpp>	// Pascal unit
#include <iefft.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Imageenproc
{
//-- type declarations -------------------------------------------------------
struct TGraphFilter
{
	int Values[3][3];
	int Divisor;
} ;

typedef TGraphFilter *PIEGraphFilter;

class DELPHICLASS EFilterInvalid;
class PASCALIMPLEMENTATION EFilterInvalid : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EFilterInvalid(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EFilterInvalid(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EFilterInvalid(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EFilterInvalid(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EFilterInvalid(const AnsiString Msg, int AHelpContext)
		 : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EFilterInvalid(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EFilterInvalid(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EFilterInvalid(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EFilterInvalid(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TFlipDir { fdHorizontal, fdVertical };
#pragma option pop

struct THistogramItem
{
	unsigned R;
	unsigned G;
	unsigned B;
	unsigned Gray;
} ;

typedef THistogramItem THistogram[256];

typedef THistogramItem *PHistogram;

#pragma option push -b-
enum imageenproc__2 { peAll, peContrast, peHSV, peHSL, peRGB, peUserFilt, peEqualize, peBumpMap, peLens, 
	peWave, peMorph, peRotate, peFFT, peGamma, peSharpen };
#pragma option pop

typedef Set<imageenproc__2, peAll, peSharpen>  TPreviewEffects;

#pragma option push -b-
enum TPRPreviewsParamsItems { prppDefaultLockPreview };
#pragma option pop

typedef Set<TPRPreviewsParamsItems, prppDefaultLockPreview, prppDefaultLockPreview>  TPRPreviewsParams
	;

class DELPHICLASS TIPDialogParams;
class PASCALIMPLEMENTATION TIPDialogParams : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int CONTRAST_Contrast;
	int CONTRAST_Brightness;
	int HSV_H;
	int HSV_S;
	int HSV_V;
	int HSL_H;
	int HSL_S;
	int HSL_L;
	int RGB_R;
	int RGB_G;
	int RGB_B;
	TGraphFilter USERFILTER_Values;
	#pragma pack(push, 1)
	Hyiedefs::TRGB EQUALIZATION_ThresholdDown;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Hyiedefs::TRGB EQUALIZATION_ThresholdUp;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Hyiedefs::TRGB EQUALIZATION_EqDown;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Hyiedefs::TRGB EQUALIZATION_EqUp;
	#pragma pack(pop)
	
	int BUMPMAP_Left;
	int BUMPMAP_Top;
	int BUMPMAP_Width;
	int BUMPMAP_Height;
	#pragma pack(push, 1)
	Hyiedefs::TRGB BUMPMAP_Col;
	#pragma pack(pop)
	
	int BUMPMAP_Src;
	bool BUMPMAP_Auto;
	int LENS_Left;
	int LENS_Top;
	int LENS_Width;
	int LENS_Height;
	double LENS_Ref;
	bool LENS_Auto;
	int WAVE_Amplitude;
	int WAVE_WaveLength;
	int WAVE_Phase;
	bool WAVE_Reflect;
	int MORPH_Filter;
	int MORPH_WinSize;
	double ROTATE_Angle;
	double GAMMACORRECTION_Value;
	int SHARPEN_Sharpen;
	int SHARPEN_Size;
	int FFT_Left;
	int FFT_Top;
	int FFT_Right;
	int FFT_Bottom;
	bool FFT_GrayScale;
	__fastcall TIPDialogParams(void);
	void __fastcall SaveToFile(const AnsiString FileName);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall SetProperty(AnsiString Prop, AnsiString Value);
	AnsiString __fastcall GetProperty(const AnsiString Prop);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIPDialogParams(void) { }
	#pragma option pop
	
};


typedef int TIEFilterPresets;

typedef void __fastcall (__closure *TIEPreviewEvent)(System::TObject* Sender, Forms::TForm* PreviewForm
	);

#pragma option push -b-
enum imageenproc__4 { iecRed, iecGreen, iecBlue };
#pragma option pop

typedef Set<imageenproc__4, iecRed, iecBlue>  TIEChannels;

#pragma option push -b-
enum TIEUndoSource { ieuUnknown, ieuImage, ieuSelection };
#pragma option pop

#pragma option push -b-
enum TIEAntialiasMode { ierFast, ierBilinear, ierBicubic };
#pragma option pop

#pragma option push -b-
enum TIEMedFilType { mfMedianFilter, mfSharpen, mfEdgeExtract };
#pragma option pop

class DELPHICLASS TImageEnProc;
class PASCALIMPLEMENTATION TImageEnProc : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool fAutoUndo;
	Ieview::TIEView* fImageEnView;
	int fImageEnViewIdx;
	Graphics::TColor fBackground;
	Hyiedefs::TMsgLanguage fMsgLanguage;
	TPRPreviewsParams fPreviewsParams;
	Graphics::TFont* fPreviewFont;
	TIEPreviewEvent fOnPreview;
	Extctrls::TImage* fTImage;
	AnsiString fFiltersInitialDir;
	Hyieutils::TIEBitmap* fIEBitmap;
	bool fIEBitmapCreated;
	TIPDialogParams* fIPDialogParams;
	void __fastcall SetAttachedBitmap(Graphics::TBitmap* atBitmap);
	void __fastcall SetAttachedImageEn(Ieview::TIEView* atImageEn);
	Graphics::TColor __fastcall GetReBackground(void);
	void __fastcall SetReBackground(Graphics::TColor v);
	void __fastcall SetPreviewFont(Graphics::TFont* f);
	void __fastcall SetTImage(Extctrls::TImage* v);
	void __fastcall SetPRPreviewParams(TPRPreviewsParams v);
	TPRPreviewsParams __fastcall GetPRPreviewParams(void);
	bool __fastcall GetCanUndo(void);
	bool __fastcall GetCanRedo(void);
	int __fastcall GetUndoCount(void);
	void __fastcall SetUndoCaptions(int index, const AnsiString Value);
	AnsiString __fastcall GetUndoCaptions(int index);
	int __fastcall GetRedoCount(void);
	AnsiString __fastcall GetRedoCaptions(int index);
	void __fastcall SetUndoLimit(int v);
	
protected:
	Classes::TList* fUndoList;
	Hyieutils::TIELocation fUndoLocation;
	int fUndoLimit;
	Classes::TStringList* fUndoCaptions;
	Classes::TList* fRedoList;
	Classes::TStringList* fRedoCaptions;
	Graphics::TBitmap* fBitmap;
	Hyiedefs::TIEProgressEvent fOnProgress;
	Classes::TNotifyEvent fOnFinishWork;
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall OnBitmapChange(System::TObject* Sender, bool destroying);
	void __fastcall SetIEBitmap(Hyieutils::TIEBitmap* bmp);
	void __fastcall SetAttachedIEBitmap(Hyieutils::TIEBitmap* bmp);
	bool __fastcall MakeConsistentBitmap(Hyieutils::TIEPixelFormatSet allowedFormats);
	virtual void __fastcall DoFinishWork(void);
	
public:
	__fastcall virtual TImageEnProc(Classes::TComponent* Owner);
	__fastcall virtual ~TImageEnProc(void);
	__property Graphics::TBitmap* AttachedBitmap = {read=fBitmap, write=SetAttachedBitmap};
	__property Hyieutils::TIEBitmap* AttachedIEBitmap = {read=fIEBitmap, write=SetAttachedIEBitmap};
	void __fastcall Update(void);
	__property AnsiString FiltersInitialDir = {read=fFiltersInitialDir, write=fFiltersInitialDir};
	bool __fastcall BeginImageProcessing(Hyieutils::TIEPixelFormatSet allowedFormats, int &x1, int &y1, 
		int &x2, int &y2, const AnsiString OpName, Hyieutils::TIEBitmap* &ProcBitmap, Hyieutils::TIEMask* 
		&mask);
	void __fastcall EndImageProcessing(Hyieutils::TIEBitmap* ProcBitmap, Hyieutils::TIEMask* mask);
	bool __fastcall BeginImageAnalysis(Hyieutils::TIEPixelFormatSet allowedFormats, int &x1, int &y1, int 
		&x2, int &y2, Hyieutils::TIEBitmap* &ProcBitmap, Hyieutils::TIEMask* &mask);
	void __fastcall EndImageAnalysis(Hyieutils::TIEBitmap* ProcBitmap);
	void __fastcall Negative(void);
	void __fastcall HSLvar(int oHue, int oSat, int oLum);
	void __fastcall HSVvar(int oHue, int oSat, int oVal);
	void __fastcall IntensityRGBall(int r, int g, int b);
	void __fastcall Contrast(int vv);
	void __fastcall ApplyFilter(const TGraphFilter &filter);
	void __fastcall ApplyFilterPreset(int filter);
	void __fastcall ConvertToGray(void);
	void __fastcall CastColorRange(Hyiedefs::TRGB BeginColor, Hyiedefs::TRGB EndColor, Hyiedefs::TRGB CastColor
		);
	void __fastcall CastColor(int x, int y, Hyiedefs::TRGB newColor, int tolerance);
	void __fastcall CastAlpha(int x, int y, int newAlpha, int tolerance);
	void __fastcall Flip(TFlipDir dir);
	void __fastcall RemoveRedEyes(void);
	void __fastcall ConvertToBW_FloydSteinberg(void);
	void __fastcall ImageResize(int newWidth, int newHeight, Hyieutils::TIEHAlign HorizAlign, Hyieutils::TIEVAlign 
		VertAlign);
	void __fastcall Resample(int NewWidth, int NewHeight, Hyiedefs::TResampleFilter FilterType);
	void __fastcall Rotate(double fangle, bool antialias, TIEAntialiasMode AntialiasMode, Graphics::TColor 
		BackgroundColor);
	void __fastcall ConvertToBWThreshold(int Threshold);
	void __fastcall EdgeDetect_ShenCastan(double Ratio, double Smooth, int WindowSize, int ThinFactor, 
		bool DoHysteresis);
	void __fastcall RemoveIsolatedPixels(int NoiseColor, int PixelsCount);
	void __fastcall RemoveNoise(int Iterations, bool InvertImage);
	void __fastcall PaintMark(int Frequency, Hyiedefs::TRGB Color);
	void __fastcall GammaCorrect(double Gamma, TIEChannels Channel);
	void __fastcall PaintPenMarker(int x, int y, int Width, Graphics::TColor Color, Graphics::TColor BackgroundColor
		, int Tolerance);
	void __fastcall ConvertToPalette(int NumColors, void * Palette, Hyieutils::TIEDitherMethod DitherMethod
		);
	void __fastcall ConvertTo(int NumColors, Hyieutils::TIEDitherMethod DitherMethod);
	bool __fastcall DoPreviews(TPreviewEffects pe);
	__property TIPDialogParams* IPDialogParams = {read=fIPDialogParams};
	void __fastcall AddSoftShadow(double radius, int OffSetX, int OffSetY, bool AdaptSize, Graphics::TColor 
		ShadowColor);
	void __fastcall AddInnerShadow(double radius, int OffSetX, int OffSetY, Graphics::TColor ShadowColor
		);
	void __fastcall MedianFilter(int WindowX, int WindowY, int Brightness, int Contrast, int Multiplier
		, int Threshold, TIEMedFilType MedianOp);
	void __fastcall WallisFilter(int WinWidth, int WinHeight, int Mean, int StDev, int InGain, int Edge
		, int Limit, bool Thresholding);
	void __fastcall Sharpen(int Intensity, int Neighbourhood);
	void __fastcall Clear(void);
	void __fastcall ClearSel(void);
	void __fastcall Merge(Graphics::TBitmap* DBitmap, int pcf);
	void __fastcall MergeIEBitmap(Hyieutils::TIEBitmap* DBitmap, int pcf);
	void __fastcall Threshold(Hyiedefs::TRGB DownLimit, Hyiedefs::TRGB UpLimit, Hyiedefs::TRGB DownVal, 
		Hyiedefs::TRGB UpVal);
	void __fastcall HistEqualize(Hyiedefs::TRGB LoThresh, Hyiedefs::TRGB HiThresh);
	void __fastcall HistAutoEqualize(void);
	void __fastcall CropSel(void);
	void __fastcall BumpMapping(int LightX, int LightY, int LampX, int LampY, int pcf, Hyiedefs::TRGB Color
		);
	void __fastcall Lens(int cx, int cy, int Width, int Height, double Refraction);
	void __fastcall Wave(int amplitude, int wavelength, int phase, bool reflective);
	void __fastcall ConvertToBWOrdered(void);
	void __fastcall ConvertTo24Bit(void);
	int __fastcall WriteHiddenText(AnsiString text);
	int __fastcall WriteHiddenData(char * data, int count);
	void __fastcall Maximum(int WindowSize);
	void __fastcall Minimum(int WindowSize);
	void __fastcall Opening(int WindowSize);
	void __fastcall Closing(int WindowSize);
	void __fastcall Fill(Hyiedefs::TRGB FillColor);
	void __fastcall Blur(double radius);
	void __fastcall SetTransparentColors(Hyiedefs::TRGB MinColor, Hyiedefs::TRGB MaxColor, int Alpha);
	void __fastcall ResampleTo(Hyieutils::TIEBitmap* Target, int TargetWidth, int TargetHeight, Hyiedefs::TResampleFilter 
		FilterType);
	void __fastcall RoundImage(int RoundWidth, int RoundHeight);
	void __fastcall RadialStretch(double ARed, double BRed, double CRed, double DRed, double AGreen, double 
		BGreen, double CGreen, double DGreen, double ABlue, double BBlue, double CBlue, double DBlue);
	void __fastcall Crop(int x1, int y1, int x2, int y2);
	void __fastcall AutoCrop(int Tolerance, Hyiedefs::TRGB Background);
	void __fastcall MakeTile(int columns, int rows);
	void __fastcall ShiftChannel(int offsetX, int offsetY, int channel, int fillValue);
	void __fastcall WhiteBalance_coef(double Red, double Green, double Blue);
	void __fastcall WhiteBalance_GrayWorld(void);
	void __fastcall WhiteBalance_WhiteAt(int WhiteX, int WhiteY);
	void __fastcall WhiteBalance_AutoWhite(void);
	void __fastcall AdjustGainOffset(void);
	void __fastcall AutoImageEnhance1(int SubsampledSize, int Slope, int Cut, int Neightbour);
	void __fastcall AutoImageEnhance2(int ScaleCount, int ScaleCurve, double Variance, int ScaleHigh, bool 
		Luminance);
	void __fastcall AutoSharp(int Intensity, double rate);
	void __fastcall Colorize(int hue, int saturation, double luminosity);
	void __fastcall AdjustBrightnessContrastSaturation(int Brightness, int Contrast, int Saturation);
	void __fastcall Contrast2(double Amount);
	void __fastcall AdjustSaturation(int Amount);
	void __fastcall AdjustTint(int Amount);
	void __fastcall AdjustLumSatHistogram(double Saturation, double Luminance);
	int __fastcall CalcOrientation(void);
	void __fastcall GetHistogram(void * Hist);
	void __fastcall CalcImagePalette(Hyiedefs::TRGB * Palette, const int Palette_Size, int MaxCol);
	int __fastcall CalcImageNumColors(void);
	Hyieutils::TIEBitmap* __fastcall GetHSVChannel(int ch);
	void __fastcall GetHSVChannelAll(Hyieutils::TIEBitmap* BitmapH, Hyieutils::TIEBitmap* BitmapS, Hyieutils::TIEBitmap* 
		BitmapV);
	Hyieutils::TIEBitmap* __fastcall GetRGBChannel(int ch);
	void __fastcall GetRGBChannelAll(Hyieutils::TIEBitmap* BitmapR, Hyieutils::TIEBitmap* BitmapG, Hyieutils::TIEBitmap* 
		BitmapB);
	AnsiString __fastcall ReadHiddenText(void);
	int __fastcall ReadHiddenData(char * data, int maxlen);
	int __fastcall GetHiddenDataSpace(void);
	void __fastcall ClearHiddenText(void);
	Iefft::TIEFtImage* __fastcall FTCreateImage(Iefft::TIEFtImageType ImageType, int NewWidth, int NewHeight
		);
	void __fastcall FTConvertFrom(Iefft::TIEFtImage* ft);
	void __fastcall FTDisplayFrom(Iefft::TIEFtImage* ft);
	double __fastcall SkewDetection(int ResampleWidth, int AngleRange, double Precision, bool EdgeDetect
		);
	double __fastcall SkewDetectionFine(double StartingAngle, double resolution, int range, bool maxQuality
		);
	void __fastcall CalcDensityHistogram(void * VertHist, void * HorizHist, int norm_vert, int norm_horiz
		);
	bool __fastcall ComputeImageEquality(Hyieutils::TIEBitmap* SecondImage, double &psnr_min, double &psnr_max
		, double &mse_min, double &mse_max, double &rmse_min, double &rmse_max, double &pae_min, double &pae_max
		, double &mae_min, double &mae_max);
	double __fastcall CompareWith(Hyieutils::TIEBitmap* SecondImage, Hyieutils::TIEBitmap* DiffBitmap);
		
	double __fastcall GetDominantColor(Hyiedefs::TRGB &Color);
	virtual void __fastcall SaveUndo(TIEUndoSource Source);
	void __fastcall SaveUndoCaptioned(const AnsiString Caption, TIEUndoSource Source);
	void __fastcall ClearUndo(void);
	void __fastcall ClearUndoAt(int Position);
	void __fastcall ClearAllUndo(void);
	virtual void __fastcall Undo(void);
	void __fastcall UndoRect(int x1, int y1, int x2, int y2);
	virtual void __fastcall UndoAt(int Position);
	__property bool CanUndo = {read=GetCanUndo, nodefault};
	__property bool CanRedo = {read=GetCanRedo, nodefault};
	__property Hyieutils::TIELocation UndoLocation = {read=fUndoLocation, write=fUndoLocation, nodefault
		};
	__property int UndoCount = {read=GetUndoCount, nodefault};
	__property AnsiString UndoCaptions[int index] = {read=GetUndoCaptions, write=SetUndoCaptions};
	TIEUndoSource __fastcall UndoPeekAt(int Position);
	virtual void __fastcall SaveRedo(TIEUndoSource Source);
	void __fastcall SaveRedoCaptioned(const AnsiString Caption, TIEUndoSource Source);
	__property AnsiString RedoCaptions[int index] = {read=GetRedoCaptions};
	__property int RedoCount = {read=GetRedoCount, nodefault};
	void __fastcall ClearAllRedo(void);
	virtual void __fastcall ClearRedo(void);
	virtual void __fastcall Redo(void);
	virtual void __fastcall RedoAt(int Position);
	TIEUndoSource __fastcall RedoPeekAt(int Position);
	void __fastcall SelCopyToClip(void);
	void __fastcall CopyToClipboard(void);
	void __fastcall SelPasteFromClipStretch(void);
	void __fastcall PasteFromClipboard(void);
	void __fastcall PointPasteFromClip(int x1, int y1);
	void __fastcall SelCutToClip(void);
	void __fastcall SelPasteFromClip(void);
	DYNAMIC bool __fastcall GetReSel(int &fsX1, int &fsY1, int &fsX2, int &fsY2, Hyiedefs::PPointArray 
		&PolySel, int &PolySelCount, Hyieutils::TIEMask* &mask);
	
__published:
	__property Ieview::TIEView* AttachedImageEn = {read=fImageEnView, write=SetAttachedImageEn};
	__property bool AutoUndo = {read=fAutoUndo, write=fAutoUndo, default=1};
	__property Graphics::TColor Background = {read=GetReBackground, write=SetReBackground, default=0};
	__property Hyiedefs::TIEProgressEvent OnProgress = {read=fOnProgress, write=fOnProgress};
	__property Hyiedefs::TMsgLanguage MsgLanguage = {read=fMsgLanguage, write=fMsgLanguage, default=0};
		
	__property TPRPreviewsParams PreviewsParams = {read=GetPRPreviewParams, write=SetPRPreviewParams, default=0
		};
	__property Graphics::TFont* PreviewFont = {read=fPreviewFont, write=SetPreviewFont};
	__property Extctrls::TImage* AttachedTImage = {read=fTImage, write=SetTImage};
	__property TIEPreviewEvent OnPreview = {read=fOnPreview, write=fOnPreview};
	__property int UndoLimit = {read=fUndoLimit, write=SetUndoLimit, default=1};
	__property Classes::TNotifyEvent OnFinishWork = {read=fOnFinishWork, write=fOnFinishWork};
};


#pragma option push -b-
enum TIETransitionType { iettNone, iettCrossDissolve, iettFadeOut, iettFadeIn, iettFadeOutIn, iettLeftRight1, 
	iettLeftRight2, iettRightLeft1, iettRightLeft2, iettUpDown1, iettUpDown2, iettDownUp1, iettDownUp2, 
	iettFromUpLeft, iettFromUpRight, iettFromBottomLeft, iettFromBottomRight, iettMoveLeftRight1, iettMoveLeftRight2, 
	iettMoveRightLeft1, iettMoveRightLeft2, iettMoveUpDown1, iettMoveUpDown2, iettMoveDownUp1, iettMoveDownUp2, 
	iettRandomPoints, iettRandomBoxes, iettCenter1, iettCenter2, iettCenterZoom1, iettCenterZoom2, iettExpandFromLeft, 
	iettExpandFromRight, iettExpandFromTop, iettExpandFromBottom, iettExpandFromTopLeft, iettExpandFromTopRight, 
	iettExpandFromBottomLeft, iettExpandFromBottomRight, iettExpandInFromLeft, iettExpandInFromRight, iettExpandInFromTop, 
	iettExpandInFromBottom, iettExpandInToVerticalCenter, iettExpandInToHorizon, iettExpandInFromSides, 
	iettExpandInFromTopAndBottom, iettExpandOutFromHorizon, iettExpandOutFromVerticalCenter, iettWipeFromTopLeft, 
	iettWipeFromTopRight, iettWipeFromBottomLeft, iettWipeFromBottomRight, iettWipeFromHorizon, iettWipeInFromSides, 
	iettWipeOutFromVerticalCenter, iettBuildUpFromLeft, iettBuildUpFromRight, iettBuildUpFromTop, iettBuildUpFromBottom, 
	iettUnrollFromLeft, iettUnrollFromRight, iettUnrollFromTop, iettUnrollFromBottom, iettSlideInFromLeft, 
	iettSlideInFromRight, iettSlideInFromTop, iettSlideInFromBottom, iettSlideInFromTopAndBottom, iettShrinkToTopLeft, 
	iettShrinkToTopRight, iettShrinkToBottomLeft, iettShrinkToBottomRight, iettShrinkToCenter, iettQuartersWipeInToCenter, 
	iettQuartersExpandToCenter, iettQuartersSlideInToCenter, iettCurvedWipeFromLeft, iettCurvedWipeFromRight, 
	iettCurvedWipeFromTop, iettCurvedWipeFromBottom, iettBarsInFromLeft, iettBarsInFromRight, iettBarsFromTop, 
	iettBarsFromBottom, iettBarsLeftThenRight, iettBarsRightThenLeft, iettBarsTopThenBottom, iettBarsBottomThenTop, 
	iettBarsFrombothSides, iettBarsFromTopAndBottom, iettShreddedFromLeft, iettShreddedFromRight, iettShreddedFromTop, 
	iettShreddedFromBottom, iettShreddedFromTopAndLeft, iettShreddedFromTopAndRight, iettShreddedFromBottomAndLeft, 
	iettShreddedFromBottomAndRight, iettShreddedFromHorizonAndLeft, iettShreddedFromHorizonAndRight, iettShreddedFromTopAndVerticalCenter, 
	iettShreddedFromBottomAndVerticalCenter, iettShreddedToCenter, iettShreddedFromCenter, iettShreddedInToHorizon, 
	iettShreddedInToVerticalCenter, iettShreddedOutFromHorizon, iettShreddedOutFromVerticalCenter, iettRectangularShred, 
	iettTriangularShredToTopLeft, iettCurvedWipeFromTopLeft, iettCurvedWipeFromTopRight, iettCurvedWipeFromBottomLeft, 
	iettCurvedWipeFromBottomRight, iettCircularWipeFromCenter, iettCircularWipeToCenter, iettCrisscrossWipeFromTopLeft, 
	iettCrisscrossWipeFromTopRight, iettCrisscrossWipeFromBottomLeft, iettCrisscrossWipeFromBottomRight, 
	iettCrisscrossWipeBounceFromTopLeft, iettCrisscrossWipeBounceFromTopRight, iettCrisscrossWipeBounceFromBottomLeft, 
	iettCrisscrossWipeBounceFromBottomRight, iettCrisscrossWipeFromLeftRightAndTop, iettCrisscrossWipeFromLeftRightAndBottom, 
	iettCrisscrossWipeFromLeftTopAndBottom, iettCrisscrossWipeFromTopLeftRightAndBottom, iettCrisscrossWipeFromRightTopAndBottom, 
	iettCrisscrossWipeFromBottomLeftTopRight, iettWipeDiagonalFromTopLeft, iettWipeDiagonalFromTopRight, 
	iettWipeDiagonalFromBottomLeft, iettWipeDiagonalFromBottomRight, iettDiagonalSweepClockwise, iettDiagonalSweepCounterClockwise, 
	iettSweepClockwise, iettSweepCounterClockwise, iettStarburstClockwiseFromCenter, iettRotationalRectangle, 
	iettRotationalStar, iettSpeckledWipeFromLeft, iettSpeckledWipeFromRight, iettSpeckledWipeFromTop, iettSpeckledWipeFromBottom, 
	iettPushLeftAndSlideOut, iettPushRightAndSlideOut, iettPushUpAndSlideOut, iettPushDownAndSlideOut, 
	iettPushAndSqueezeLeft, iettPushAndSqueezeRight, iettPushAndSqueezeUp, iettPushAndSqueezeDown, iettHorizontalBlinds, 
	iettVerticalBlinds, iettUnevenBlindsFromLeft, iettUnevenBlindsFromRight, iettUnevenBlindsFromTop, iettUnevenBlindsFromBottom, 
	iettRectanglesFromTheLeft, iettRectanglesFromTheRight, iettRectanglesFromTheTop, iettRectanglesFromTheBottom, 
	iettPanZoom };
#pragma option pop

#pragma option push -b-
enum TIETransitionTiming { iettLinear, iettExponential, iettLogarithmic };
#pragma option pop

class DELPHICLASS TIETransitionEffects;
class PASCALIMPLEMENTATION TIETransitionEffects : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Graphics::TBitmap* fSourceShot;
	Graphics::TBitmap* fTargetShot;
	Graphics::TBitmap* fCurrentView;
	Hyieutils::TIEBitmap* fFullImage;
	void * *fSourceShotLines;
	void * *fTargetShotLines;
	void * *fCurrentViewLines;
	int fWidth;
	int fHeight;
	bool fRunning;
	Ieview::TIEView* fOwner;
	Extctrls::TTimer* fTimer;
	int fStep;
	int fAccum1;
	TIETransitionType fTransition;
	int fDuration;
	unsigned fStartTick;
	bool fUpdateOnStop;
	Windows::TRect fStartRect;
	Windows::TRect fEndRect;
	Classes::TNotifyEvent fOnTransitionStop;
	TIETransitionTiming fTiming;
	
protected:
	int fFrames;
	void __fastcall TimerEvent(System::TObject* Sender);
	void __fastcall CrossDissolve(int Step);
	void __fastcall FadeOut(int Step);
	void __fastcall FadeIn(int Step);
	void __fastcall FadeOutIn(int Step);
	void __fastcall LeftRight1(int Step);
	void __fastcall LeftRight2(int Step);
	void __fastcall RightLeft1(int Step);
	void __fastcall RightLeft2(int Step);
	void __fastcall UpDown1(int Step);
	void __fastcall UpDown2(int Step);
	void __fastcall DownUp1(int Step);
	void __fastcall DownUp2(int Step);
	void __fastcall MoveLeftRight1(int Step);
	void __fastcall MoveLeftRight2(int Step);
	void __fastcall MoveRightLeft1(int Step);
	void __fastcall MoveRightLeft2(int Step);
	void __fastcall MoveUpDown1(int Step);
	void __fastcall MoveUpDown2(int Step);
	void __fastcall MoveDownUp1(int Step);
	void __fastcall MoveDownUp2(int Step);
	void __fastcall RandomPoints(int Step);
	void __fastcall FromUpLeft(int Step);
	void __fastcall FromUpRight(int Step);
	void __fastcall FromBottomLeft(int Step);
	void __fastcall FromBottomRight(int Step);
	void __fastcall RandomBoxes(int Step);
	void __fastcall Center1(int Step);
	void __fastcall Center2(int Step);
	void __fastcall CenterZoom1(int Step);
	void __fastcall CenterZoom2(int Step);
	void __fastcall PanZoom(int Step);
	
public:
	__fastcall TIETransitionEffects(Ieview::TIEView* Owner);
	__fastcall virtual ~TIETransitionEffects(void);
	__property Graphics::TBitmap* SourceShot = {read=fSourceShot};
	__property Graphics::TBitmap* TargetShot = {read=fTargetShot};
	__property bool Running = {read=fRunning, nodefault};
	void __fastcall Run(bool UpdateOnStop);
	void __fastcall Stop(void);
	__property TIETransitionType Transition = {read=fTransition, write=fTransition, nodefault};
	void __fastcall SetSizes(int Width, int Height);
	__property int Duration = {read=fDuration, write=fDuration, nodefault};
	void __fastcall PrepareBitmap(Graphics::TBitmap* OriginalBitmap, Graphics::TBitmap* TargetBitmap);
	void __fastcall CreateBitmapFrame(int iStep, Graphics::TBitmap* ToBitmap);
	__property Hyieutils::TIEBitmap* FullImage = {read=fFullImage, write=fFullImage};
	__property Windows::TRect StartRect = {read=fStartRect, write=fStartRect};
	__property Windows::TRect EndRect = {read=fEndRect, write=fEndRect};
	__property Classes::TNotifyEvent OnTransitionStop = {read=fOnTransitionStop, write=fOnTransitionStop
		};
	__property TIETransitionTiming Timing = {read=fTiming, write=fTiming, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
#define ppeColorAdjust (System::Set<imageenproc__2, peAll, peSharpen> () )
#define ppeEffects (System::Set<imageenproc__2, peAll, peSharpen> () )
static const Shortint fpNone = 0x0;
static const Shortint fpBlur = 0x1;
static const Shortint fpEdge = 0x2;
static const Shortint fpEmboss = 0x3;
static const Shortint fpHighPass1 = 0x4;
static const Shortint fpHighPass2 = 0x5;
static const Shortint fpHighPass3 = 0x6;
static const Shortint fpLowPass1 = 0x7;
static const Shortint fpLowPass2 = 0x8;
extern PACKAGE int BWORDERPATTERN[8][8];
extern PACKAGE Hyiedefs::TRGB C1TO24[256][8];
extern PACKAGE int __fastcall IECeil(Extended X);
extern PACKAGE void __fastcall iedswap(double &d1, double &d2);
extern PACKAGE Hyiedefs::TRGB __fastcall CreateRGB(Byte r, Byte g, Byte b);
extern PACKAGE int __fastcall _RGBToGray(const Hyiedefs::TRGB rgb);
extern PACKAGE Graphics::TColor __fastcall TRGB2TColor(Hyiedefs::TRGB rgb);
extern PACKAGE Graphics::TColor __fastcall RGB2TColor(int r, int g, int b);
extern PACKAGE Hyiedefs::TRGB __fastcall TColor2TRGB(Graphics::TColor cl);
extern PACKAGE double __fastcall dmin(double v1, double v2);
extern PACKAGE double __fastcall dmax(double v1, double v2);
extern PACKAGE int __fastcall imax(int v1, int v2);
extern PACKAGE int __fastcall imin(int v1, int v2);
extern PACKAGE int __fastcall ilimit(int vv, int min, int max);
extern PACKAGE int __fastcall blimit(int vv);
extern PACKAGE void __fastcall iswap(int &B1, int &B2);
extern PACKAGE void __fastcall dwswap(unsigned &B1, unsigned &B2);
extern PACKAGE bool __fastcall EqualRGB(Hyiedefs::TRGB rgb1, Hyiedefs::TRGB rgb2);
extern PACKAGE void __fastcall bswap(Byte &B1, Byte &B2);
extern PACKAGE void __fastcall OrdCor(int &x1, int &y1, int &x2, int &y2);
extern PACKAGE void __fastcall _ApplyFilter(Hyieutils::TIEBitmap* bitmap, const TGraphFilter &filter
	, int fSelx1, int fSely1, int fSelx2, int fSely2, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall _HSLvar(Hyieutils::TIEBitmap* bitmap, int oHue, int oSat, int oLum, int 
	fSelx1, int fSely1, int fSelx2, int fSely2, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE void __fastcall _HSVvar(Hyieutils::TIEBitmap* bitmap, int oHue, int oSat, int oVal, int 
	fSelx1, int fSely1, int fSelx2, int fSely2, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE void __fastcall _Rot90o(Graphics::TBitmap* bakbmp, Graphics::TBitmap* newbitmap);
extern PACKAGE void __fastcall _Rot90oEx(Hyieutils::TIEBitmap* bakbmp, Hyieutils::TIEBitmap* newbitmap
	);
extern PACKAGE void __fastcall _Rot90oEx8(Hyieutils::TIEBitmap* bakbmp, Hyieutils::TIEBitmap* newbitmap
	);
extern PACKAGE void __fastcall _Rot90(Graphics::TBitmap* bakbmp, Graphics::TBitmap* newbitmap);
extern PACKAGE void __fastcall _Rot90Ex(Hyieutils::TIEBitmap* bakbmp, Hyieutils::TIEBitmap* newbitmap
	);
extern PACKAGE void __fastcall _Rot90Ex8(Hyieutils::TIEBitmap* bakbmp, Hyieutils::TIEBitmap* newbitmap
	);
extern PACKAGE void __fastcall RGB2HSL(Hyiedefs::TRGB px, double &Hue, double &Sat, double &Lum);
extern PACKAGE void __fastcall HSL2RGB(Hyiedefs::TRGB &px, double iHue, double iSat, double iLum);
extern PACKAGE void __fastcall HSV2RGB(Hyiedefs::TRGB &px, int H, int S, int V);
extern PACKAGE void __fastcall RGB2HSV(Hyiedefs::TRGB RGB, int &h, int &s, int &v);
extern PACKAGE TGraphFilter __fastcall LoadFilterFromFile(const AnsiString nf);
extern PACKAGE void __fastcall SaveFilterToFile(const AnsiString nf, const TGraphFilter &filt);
extern PACKAGE void __fastcall _ContrastRGB(Hyieutils::TIEBitmap* bitmap, int vv, int mR, int mG, int 
	mB, int fSelx1, int fSely1, int fSelx2, int fSely2, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE void __fastcall _Merge(Hyieutils::TIEBitmap* bitmap, Hyieutils::TIEBitmap* DBitmap, int 
	pcf, int fSelx1, int fSely1, int fSelx2, int fSely2, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE void __fastcall _CastColorRange(Hyieutils::TIEBitmap* bitmap, Hyiedefs::TRGB BeginColor
	, Hyiedefs::TRGB EndColor, Hyiedefs::TRGB CastColor, int fSelx1, int fSely1, int fSelx2, int fSely2
	, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _Threshold(Hyieutils::TIEBitmap* bitmap, Hyiedefs::TRGB DownLimit, Hyiedefs::TRGB 
	UpLimit, Hyiedefs::TRGB DownVal, Hyiedefs::TRGB UpVal, int fSelx1, int fSely1, int fSelx2, int fSely2
	, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _HistAutoEqualize(Hyieutils::TIEBitmap* bitmap, int fSelx1, int fSely1
	, int fSelx2, int fSely2, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _HistEqualize(Hyieutils::TIEBitmap* bitmap, Hyiedefs::TRGB LoThresh, 
	Hyiedefs::TRGB HiThresh, int fSelx1, int fSely1, int fSelx2, int fSely2, Hyiedefs::TIEProgressEvent 
	fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _IESetAlpha0Color(Hyieutils::TIEBitmap* bitmap, Hyiedefs::TRGB cl);
extern PACKAGE void __fastcall _IEResampleIEBitmap(Hyieutils::TIEBitmap* source, Hyieutils::TIEBitmap* 
	dest, Hyiedefs::TResampleFilter FilterType, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE void __fastcall _IEResampleIEBitmap2(Hyieutils::TIEBitmap* sourceANDdest, Hyiedefs::TResampleFilter 
	FilterType, int NewWidth, int NewHeight, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender
	);
extern PACKAGE void __fastcall _GetMediaContrastRGB(Hyieutils::TIEBitmap* bitmap, int &mR, int &mG, 
	int &mB);
extern PACKAGE void __fastcall _GetHistogram(Hyieutils::TIEBitmap* Bitmap, PHistogram Hist, int fSelx1
	, int fSely1, int fSelx2, int fSely2, Hyieutils::TIEMask* mask);
extern PACKAGE int __fastcall _GetImageNumColors(Hyieutils::TIEBitmap* bitmap, int fSelx1, int fSely1
	, int fSelx2, int fSely2);
extern PACKAGE Hyieutils::TIEBitmap* __fastcall _ConvertTo1bitEx(Hyieutils::TIEBitmap* Bitmap, Hyiedefs::TRGB 
	&BackCol, Hyiedefs::TRGB &ForeCol);
extern PACKAGE void __fastcall _IntensityRGBall(Hyieutils::TIEBitmap* bitmap, int r, int g, int b, int 
	fSelx1, int fSely1, int fSelx2, int fSely2, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE Hyieutils::TIEBitmap* __fastcall _GetHSVChannel(Hyieutils::TIEBitmap* bitmap, int ch, 
	Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE Hyieutils::TIEBitmap* __fastcall _GetRGBChannel(Hyieutils::TIEBitmap* bitmap, int ch, 
	Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _GetHSVChannelAll(Hyieutils::TIEBitmap* bitmap, Hyieutils::TIEBitmap* 
	BitmapH, Hyieutils::TIEBitmap* BitmapS, Hyieutils::TIEBitmap* BitmapV, Hyiedefs::TIEProgressEvent fOnProgress
	, System::TObject* Sender);
extern PACKAGE void __fastcall _GetRGBChannelAll(Hyieutils::TIEBitmap* bitmap, Hyieutils::TIEBitmap* 
	BitmapR, Hyieutils::TIEBitmap* BitmapG, Hyieutils::TIEBitmap* BitmapB, Hyiedefs::TIEProgressEvent fOnProgress
	, System::TObject* Sender);
extern PACKAGE int __fastcall _GetSimilColor(const Hyiedefs::TRGB * ColorMap, const int ColorMap_Size
	, int nc, Hyiedefs::TRGB Col);
extern PACKAGE Graphics::TBitmap* __fastcall IECloneBitmap(Graphics::TBitmap* Source);
extern PACKAGE void __fastcall IECopyBitmap(Graphics::TBitmap* Source, Graphics::TBitmap* Dest);
extern PACKAGE unsigned __fastcall _CopyBitmaptoDIBEx(Hyieutils::TIEBaseBitmap* fBitmap, int x1, int 
	y1, int x2, int y2);
extern PACKAGE void __fastcall _CopyBits(Windows::PByte Dest, Windows::PByte Source, int DestStart, 
	int SourceStart, int Len, int SourceRowLen);
extern PACKAGE void __fastcall _CopyBitmapRect(Graphics::TBitmap* Source, Graphics::TBitmap* Dest, int 
	x1, int y1, int x2, int y2);
extern PACKAGE void __fastcall _NegativeBuffer(Windows::PByte buf, int WidthBytes);
extern PACKAGE void __fastcall _Negative1Bit(Graphics::TBitmap* Bitmap);
extern PACKAGE void __fastcall _Negative1BitEx(Hyieutils::TIEBitmap* Bitmap);
extern PACKAGE void __fastcall _Negative(Hyieutils::TIEBitmap* bitmap, int fSelx1, int fSely1, int fSelx2
	, int fSely2, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _FlipEx(Hyieutils::TIEBitmap* bmp, TFlipDir dir);
extern PACKAGE bool __fastcall _BitmapCompareX(Graphics::TBitmap* Bitmap1, Graphics::TBitmap* Bitmap2
	);
extern PACKAGE bool __fastcall _BitmapCompareXEx(Hyieutils::TIEBitmap* Bitmap1, Hyieutils::TIEBitmap* 
	Bitmap2);
extern PACKAGE void __fastcall _ClearSelMaskEx(Hyieutils::TIEBitmap* fIEBitmap, Hyieutils::TIEMask* 
	mask, Graphics::TColor Background);
extern PACKAGE int __fastcall _IECopyDIB2Bitmap2Ex(unsigned hbi, Hyieutils::TIEDibbitmap* fBitmap, Windows::PByte 
	xbits, bool unlck);
extern PACKAGE void __fastcall _ConvertToEx(Hyieutils::TIEBitmap* Bitmap, int NumColors, Hyiedefs::PRGBROW 
	OutPalette, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _ConvertToBWOrdered(Hyieutils::TIEBitmap* bitmap, Hyiedefs::TProgressRec 
	&Progress);
extern PACKAGE void __fastcall _ConvertToBWThreshold(Hyieutils::TIEBitmap* bitmap, int Threshold, Hyiedefs::TProgressRec 
	&Progress);
extern PACKAGE void __fastcall _ConvRow1To24(Windows::PByte spx, Windows::PByte dpx, int Width);
extern PACKAGE void __fastcall _Conv1to24(Graphics::TBitmap* &SrcBitmap, Graphics::TBitmap* &DstBitmap
	, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall _Conv1to24Ex(Hyieutils::TIEBitmap* &SrcBitmap, Hyieutils::TIEBitmap* 
	&DstBitmap, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall _ConvertToGray(Hyieutils::TIEBitmap* bitmap, int fSelx1, int fSely1, 
	int fSelx2, int fSely2, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _BumpMapping(Hyieutils::TIEBitmap* Bitmap, int LightX, int LightY, int 
	LAmpX, int LAmpY, int pcf, Hyiedefs::TRGB Color, int fselx1, int fsely1, int fselx2, int fsely2, Hyiedefs::TProgressRec 
	&Progress);
extern PACKAGE void __fastcall _RotateEx(Hyieutils::TIEBitmap* fBitmap, double fangle, bool antialias
	, Hyiedefs::TRGB Background, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _RotateEx8(Hyieutils::TIEBitmap* fBitmap, double fangle, bool antialias
	, int Background, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _lens(Hyieutils::TIEBitmap* Bitmap, int xx, int yy, int width, int height
	, double refraction, Hyiedefs::TProgressRec &Progress);
extern PACKAGE int __fastcall _GetPixelbw(Windows::PByte row, int pix);
extern PACKAGE void __fastcall _SetPixelbw(Windows::PByte row, int pix, int vv);
extern PACKAGE void __fastcall _rotate1bitEx(Hyieutils::TIEBitmap* fBitmap, double angle, int background
	, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall _rotate1bit(Graphics::TBitmap* fBitmap, double angle, int background, 
	Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall _rotate8bit(Hyieutils::TIEBitmap* fBitmap, double angle, int background
	);
extern PACKAGE void __fastcall _wave(Hyieutils::TIEBitmap* Bitmap, int amplitude, int wavelength, int 
	phase, bool reflective, Hyiedefs::TProgressRec &Progress);
extern PACKAGE HPALETTE __fastcall _CreateWinPalette(Hyiedefs::TRGB * ColorMap, const int ColorMap_Size
	, int NCol);
extern PACKAGE void __fastcall YUV2RGB(int y, int u, int v, Hyiedefs::TRGB &RGB);
extern PACKAGE void __fastcall _CopyIYU1ToBitmap(Windows::PByte xbits, Hyieutils::TIEBaseBitmap* fBitmap
	, bool dirc);
extern PACKAGE void __fastcall _CopyIYU2ToBitmap(Windows::PByte xbits, Hyieutils::TIEBaseBitmap* fBitmap
	, bool dirc);
extern PACKAGE void __fastcall _CopyUYVYToBitmap(Windows::PByte xbits, Hyieutils::TIEBaseBitmap* fBitmap
	, bool dirc);
extern PACKAGE void __fastcall _CopyYUY2ToBitmap(Windows::PByte xbits, Hyieutils::TIEBaseBitmap* fBitmap
	, bool dirc);
extern PACKAGE void __fastcall _CopyYVYUToBitmap(Windows::PByte xbits, Hyieutils::TIEBaseBitmap* fBitmap
	, bool dirc);
extern PACKAGE void __fastcall _CopyY41PToBitmap(Windows::PByte xbits, Hyieutils::TIEBaseBitmap* fBitmap
	, bool dirc);
extern PACKAGE void __fastcall _CopyY211ToBitmap(Windows::PByte xbits, Hyieutils::TIEBaseBitmap* fBitmap
	, bool dirc);
extern PACKAGE void __fastcall _CopyCLJRToBitmap(Windows::PByte xbits, Hyieutils::TIEBaseBitmap* fBitmap
	, bool dirc);
extern PACKAGE void __fastcall _CopyYVU9ToBitmap(Windows::PByte xbits, Hyieutils::TIEBaseBitmap* fBitmap
	, bool dirc);
extern PACKAGE void __fastcall _CopyYV12ToBitmap(Windows::PByte xbits, Hyieutils::TIEBaseBitmap* fBitmap
	, bool dirc);
extern PACKAGE void __fastcall _CopyI420ToBitmap(Windows::PByte xbits, Hyieutils::TIEBaseBitmap* fBitmap
	, bool dirc);
extern PACKAGE int __fastcall _CopyDIB2Bitmap(unsigned hbi, Graphics::TBitmap* fBitmap, Windows::PByte 
	xbits, bool unlck);
extern PACKAGE int __fastcall _CopyDIB2BitmapEx(unsigned hbi, Hyieutils::TIEBaseBitmap* fBitmap, Windows::PByte 
	xbits, bool unlck);
extern PACKAGE void __fastcall _CopyPolygonToPoint(Graphics::TBitmap* Source, Hyiedefs::PPointArray 
	Polygon, int PolygonLen, Graphics::TBitmap* Dest, const Windows::TPoint &Position);
extern PACKAGE void __fastcall _CopyPointToPolygon(Graphics::TBitmap* Source, Hyiedefs::PPointArray 
	Polygon, int PolygonLen, Graphics::TBitmap* Dest, const Windows::TPoint &Position);
extern PACKAGE void __fastcall _CopyBGR_RGB(Hyiedefs::PRGB dst, Hyiedefs::PRGB src, int width);
extern PACKAGE void __fastcall _CopyBGR_RGB48(Hyiedefs::PRGB48 dst, Hyiedefs::PRGB48 src, int width)
	;
extern PACKAGE void __fastcall _BGR2RGB(Hyiedefs::PRGB buff, int width);
extern PACKAGE void __fastcall _BGR2RGB48(Hyiedefs::PRGB48 buff, int width);
extern PACKAGE void __fastcall _RGB2BGR(Hyiedefs::TRGB * ColorMap, const int ColorMap_Size, int nc);
	
extern PACKAGE void __fastcall _MorphFilter(Hyieutils::TIEBitmap* bitmap, int WindowSize, int op, int 
	fSelx1, int fSely1, int fSelx2, int fSely2, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE void __fastcall IEmorph1bit(Hyieutils::TIEBitmap* Bitmap, int nIter, int opType, int 
	size, bool invertFlag, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE Hyiedefs::PPointArray __fastcall _MakeMagicWandPoints(Hyieutils::TIEBitmap* fBitmap, 
	int x, int y, bool maxfilter, int tolerance, int &pcount);
extern PACKAGE void __fastcall _MakeMagicWandPointsEx(Hyieutils::TIEBitmap* fBitmap, int x, int y, bool 
	maxfilter, int tolerance, Hyieutils::TIEMask* mask, int selintensity);
extern PACKAGE void __fastcall _MakeMagicWandPointsEx2(Hyieutils::TIEBitmap* fBitmap, int x, int y, 
	int tolerance, Hyieutils::TIEMask* mask, int selintensity);
extern PACKAGE void __fastcall _IEBmpStretch(Graphics::TBitmap* origBmp, Graphics::TBitmap* destBmp)
	;
extern PACKAGE void __fastcall _IEBmpStretchEx(Hyieutils::TIEBaseBitmap* origBmp, Hyieutils::TIEBaseBitmap* 
	destBmp, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE int __fastcall _ConvertXBitsToYBits(Byte * Input, Byte * Output, Word Xbits, Word Ybits
	, Word Width, const Hyiedefs::TRGB * Palette, const int Palette_Size, System::TObject* Quantizer);
extern PACKAGE void __fastcall _CopyPolygonBitmap(Graphics::TBitmap* Dest, Graphics::TBitmap* Source
	, int x1, int y1, Hyiedefs::PPointArray SelPoly, int SelPolyCount);
extern PACKAGE void __fastcall _ResampleAlphaEx(Hyieutils::TIEBitmap* Src, Hyieutils::TIEBitmap* Dst
	, Hyiedefs::TResampleFilter FilterType);
extern PACKAGE void __fastcall _Resample1bitEx(Hyieutils::TIEBitmap* Src, Hyieutils::TIEBitmap* Dst, 
	Hyiedefs::TResampleFilter FilterType);
extern PACKAGE void __fastcall _ResampleEx(Hyieutils::TIEBaseBitmap* Src, Hyieutils::TIEBaseBitmap* 
	Dst, Hyiedefs::TResampleFilter FilterType, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE void __fastcall _IEEdgeDetect_ShenCastan(Hyieutils::TIEBitmap* SrcBitmap, Hyieutils::TIEBitmap* 
	DstBitmap, double Ratio, double Smooth, int WindowSize, int ThinFactor, bool DoHysteresis, Hyiedefs::TProgressRec 
	&Progress);
extern PACKAGE double __fastcall _iehough(Hyieutils::TIEBitmap* image, Hyiedefs::TProgressRec &Progress
	, int anglerange, double Precision);
extern PACKAGE double __fastcall _IESkewDetection(Hyieutils::TIEBitmap* Bitmap, int ResampleWidth, int 
	AngleRange, double Precision, bool EdgeDetect, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE void __fastcall _Fill(Hyieutils::TIEBitmap* bitmap, int fSelx1, int fSely1, int fSelx2
	, int fSely2, Hyiedefs::TRGB FillColor, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender
	);
extern PACKAGE void __fastcall _ResampleLinearEx(Hyieutils::TIEBaseBitmap* Src, Hyieutils::TIEBaseBitmap* 
	Dst, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _ResampleProject1Bit(Hyieutils::TIEBaseBitmap* origBmp, Hyieutils::TIEBaseBitmap* 
	DestBmp, bool Negative, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _ResampleProject24Bit(Hyieutils::TIEBaseBitmap* origBmp, Hyieutils::TIEBaseBitmap* 
	DestBmp, bool Negative, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _ResampleLinear1BitEx(Hyieutils::TIEBitmap* Src, Hyieutils::TIEBitmap* 
	Dst, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _ResampleLinearAlpha(Hyieutils::TIEBitmap* Src, Hyieutils::TIEBitmap* 
	Dst, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _SubResample1bitFilteredEx(Hyieutils::TIEBaseBitmap* src, int sx1, int 
	sy1, int sx2, int sy2, Hyieutils::TIEBitmap* dst);
extern PACKAGE void __fastcall _CalcDensityHistogram(Hyieutils::TIEBitmap* bitmap, int fSelx1, int fSely1
	, int fSelx2, int fSely2, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender, Hyiedefs::pIntegerArray 
	VertHist, Hyiedefs::pIntegerArray HorizHist, int norm_vert, int norm_horiz);
extern PACKAGE void __fastcall _IERemoveIsolatedPixels1Bit(Hyieutils::TIEBitmap* bitmap, int fSelx1, 
	int fSely1, int fSelx2, int fSely2, int NoiseColor, int IsolationMax);
extern PACKAGE void __fastcall _kf_kfill(Hyieutils::TIEBitmap* bitmap, bool RetainConnectivity, bool 
	RetainEndpoints, int MaxIterations, int WindowSize, bool InvertImage);
extern PACKAGE void __fastcall _IEComputeDiff(Hyieutils::TIEBitmap* x, Hyieutils::TIEBitmap* y, double 
	&psnr_min, double &psnr_max, double &mse_min, double &mse_max, double &rmse_min, double &rmse_max, 
	double &pae_min, double &pae_max, double &mae_min, double &mae_max, bool &equal);
extern PACKAGE double __fastcall IECompareImages(Hyieutils::TIEBitmap* image1, Hyieutils::TIEBitmap* 
	image2, Hyieutils::TIEBitmap* diffmap);
extern PACKAGE void __fastcall _IEGammaCorrect(Hyieutils::TIEBitmap* ABitmap, double AGamma, TIEChannels 
	AChannel, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _ConvertToBWThresholdEx(Hyieutils::TIEBitmap* origbitmap, Hyieutils::TIEBitmap* 
	destbitmap, int Threshold, Hyiedefs::TProgressRec &Progress);
extern PACKAGE void __fastcall _IEGBlur(Hyieutils::TIEBitmap* Bitmap, double radius, Hyiedefs::TIEProgressEvent 
	fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _IEGBlurRect8(Hyieutils::TIEBitmap* Bitmap, int x1, int y1, int x2, int 
	y2, double radius);
extern PACKAGE void __fastcall _IEAddSoftShadow(Hyieutils::TIEBitmap* bitmap, double radius, int OffSetX
	, int OffSetY, bool AdaptBitmap, Hyiedefs::TRGB ShadowColor, Hyiedefs::TIEProgressEvent fOnProgress
	, System::TObject* Sender);
extern PACKAGE void __fastcall _IEAddInnerShadow(Hyieutils::TIEBitmap* bitmap, double radius, int OffSetX
	, int OffSetY, Hyiedefs::TRGB ShadowColor, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE int __fastcall _IEAddSoftShadowRect(Hyieutils::TIEBitmap* bitmap, double radius, int 
	OffSetX, int OffSetY, int x1, int y1, int x2, int y2);
extern PACKAGE void __fastcall _IEAddSoftShadowRect2(Hyieutils::TIEBitmap* bitmap, int size, double 
	Intensity, int OffsetX, int OffsetY, int rx1, int ry1, int rx2, int ry2);
extern PACKAGE void __fastcall _IEQRotate(Hyieutils::TIEBitmap* src, double angle, Graphics::TColor 
	Background, TIEAntialiasMode Filter, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender
	);
extern PACKAGE void __fastcall _IEQRotate8(Hyieutils::TIEBitmap* src, double angle, int Background, 
	TIEAntialiasMode Filter);
extern PACKAGE void __fastcall _IEQResample(Hyieutils::TIEBaseBitmap* SrcImg, Hyieutils::TIEBaseBitmap* 
	DstImg, int filter, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _SetTransparentColors(Hyieutils::TIEBitmap* bitmap, int fSelx1, int fSely1
	, int fSelx2, int fSely2, Hyiedefs::TRGB MinColor, Hyiedefs::TRGB MaxColor, int alpha, Hyiedefs::TIEProgressEvent 
	fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _IEMedianFilter(Hyieutils::TIEBitmap* image, int WindowX, int WindowY
	, int Brightness, int Contrast, int Multiplier, int Threshold, TIEMedFilType MedianOp, Hyiedefs::TIEProgressEvent 
	fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall _IEWallisFilter(Hyieutils::TIEBitmap* image, int WinWidth, int WinHeight
	, int Mean, int StDev, int InGain, int Edge, int Limit, bool Thresholding, Hyiedefs::TIEProgressEvent 
	fOnProgress, System::TObject* Sender);
extern PACKAGE int __fastcall _IECalcVertOrientationFitness(Hyieutils::TIEBitmap* bitmap);
extern PACKAGE double __fastcall _IESkewDetectionFine(Hyieutils::TIEBitmap* Bitmap, double StartingAngle
	, double resolution, int range, bool maxQuality);
extern PACKAGE void __fastcall _Sharpen(Hyieutils::TIEBitmap* bitmap, int fSelx1, int fSely1, int fSelx2
	, int fSely2, int Intensity, int Neighbourhood, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE void __fastcall _IERemoveRedEyes(Hyieutils::TIEBitmap* bitmap, int fSelx1, int fSely1
	, int fSelx2, int fSely2, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEFields_warp(Hyieutils::TIEBitmap* source, Hyiedefs::PIELineArray asource_lines
	, Hyiedefs::PIELineArray adest_lines, int num_lines, int num_frames, Classes::TList* outimages);
extern PACKAGE int __fastcall IEAddNewFilter(const TGraphFilter &filter, const AnsiString name);
extern PACKAGE PIEGraphFilter __fastcall IEGetFilter(int index);
extern PACKAGE AnsiString __fastcall IEGetFilterName(int index);
extern PACKAGE int __fastcall IEGetFiltersCount(void);
extern PACKAGE void __fastcall _IERoundImage(Hyieutils::TIEBitmap* ProcBitmap, int RoundWidth, int RoundHeight
	, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* self);
extern PACKAGE void __fastcall _IERadialStretch(Hyieutils::TIEBitmap* bitmap, double ARed, double BRed
	, double CRed, double DRed, double AGreen, double BGreen, double CGreen, double DGreen, double ABlue
	, double BBlue, double CBlue, double DBlue, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* 
	Sender);
extern PACKAGE void __fastcall _IEfsdither(Hyieutils::TIEBitmap* bitmap, Hyiedefs::TIEProgressEvent 
	fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEGetLuminosityDiff(Hyieutils::TIEBitmap* image1, Hyieutils::TIEBitmap* 
	image2, int &Red, int &Green, int &Blue);
extern PACKAGE void __fastcall IEAdjustColors(Hyieutils::TIEBitmap* templateimage, Hyieutils::TIEBitmap* 
	targetimage);
extern PACKAGE void __fastcall IEApplyCoefficients(Hyieutils::TIEBitmap* bitmap, double * coeff, const 
	int coeff_Size, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEGetAverageValues(Hyieutils::TIEBitmap* bitmap, double * avg, const 
	int avg_Size);
extern PACKAGE void __fastcall IEWhiteBalance_grayworld(Hyieutils::TIEBitmap* bitmap, Hyiedefs::TIEProgressEvent 
	fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEWhiteBalance_2(Hyieutils::TIEBitmap* bitmap, Hyiedefs::TIEProgressEvent 
	fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEWhiteBalance_3(Hyieutils::TIEBitmap* bitmap, int white_x, int white_y
	, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEAdjustGainOffset(Hyieutils::TIEBitmap* bitmap, Hyiedefs::TIEProgressEvent 
	fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IECastColor(Hyieutils::TIEBitmap* Bitmap, int x, int y, Hyiedefs::TRGB 
	newColor, int tolerance, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IECastAlpha(Hyieutils::TIEBitmap* Bitmap, int x, int y, int newAlpha, 
	int tolerance, Hyiedefs::TIEProgressEvent fOnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEPatternSearch(Hyieutils::TIEBitmap* InputBitmap, Hyieutils::TIEBitmap* 
	pattern, Windows::TRect &FoundRect, double precision, int scaleSteps);
extern PACKAGE void __fastcall IELLLUT(Hyieutils::TIEBitmap* SubOriginal, Hyieutils::TIEBitmap* SubFiltered
	, Hyieutils::TIEBitmap* Bitmap, int Neightbour, Hyiedefs::TIEProgressEvent OnProgress, System::TObject* 
	Sender, int ProgressOffset, double ProgressMultiplier);
extern PACKAGE void __fastcall IEACE(Hyieutils::TIEBitmap* OrigBitmap, int subwidth, int Slope, int 
	Cut, int Neightbour, Hyiedefs::TIEProgressEvent OnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEAutoSharp(Hyieutils::TIEBitmap* bitmap, int Intensity, double rate, 
	Hyiedefs::TIEProgressEvent OnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IERetinex(Hyieutils::TIEBitmap* bitmap, int ScaleCount, int ScaleCurve
	, float Variance, int ScaleHigh, bool Luma, Hyiedefs::TIEProgressEvent OnProgress, System::TObject* 
	Sender);
extern PACKAGE void __fastcall IEShift(Hyieutils::TIEBitmap* Bitmap, int offsetx, int offsety, int channel
	, int FillValue, Hyiedefs::TIEProgressEvent OnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEChangeYCbCrCoefficients(Hyieutils::TIEBitmap* Bitmap, double srcLumaRed
	, double srcLumaGreen, double srcLumaBlue, double dstLumaRed, double dstLumaGreen, double dstLumaBlue
	);
extern PACKAGE void __fastcall IERGBtoHSB(const Byte cRed, const Byte cGreen, const Byte cBlue, Word 
	&H, Word &S, Word &B);
extern PACKAGE void __fastcall IEHSBtoRGB(const Word H, const Word S, const Word B, Byte &cRed, Byte 
	&cGreen, Byte &cBlue);
extern PACKAGE void __fastcall IEAdjustBrightnessContrastSaturation(Hyieutils::TIEBitmap* Bitmap, int 
	b, int c, int s, Hyiedefs::TIEProgressEvent OnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEContrast2(Hyieutils::TIEBitmap* src, float z, Hyiedefs::TIEProgressEvent 
	OnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEAdjustSaturation(Hyieutils::TIEBitmap* Src, int Amount, Hyiedefs::TIEProgressEvent 
	OnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEAdjustTint(Hyieutils::TIEBitmap* Src, int Amount, Hyiedefs::TIEProgressEvent 
	OnProgress, System::TObject* Sender);
extern PACKAGE void __fastcall IEAutoSBHist(Hyieutils::TIEBitmap* src, float z1, float z2, Hyiedefs::TIEProgressEvent 
	OnProgress, System::TObject* Sender);

}	/* namespace Imageenproc */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Imageenproc;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// imageenproc
