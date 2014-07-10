// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'iemio.pas' rev: 5.00

#ifndef iemioHPP
#define iemioHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <pcxfilter.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <iewia.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <imageenview.hpp>	// Pascal unit
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

namespace Iemio
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TImageEnMIO;
class PASCALIMPLEMENTATION TImageEnMIO : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Ieview::TIEView* fImageEnMView;
	int fImageEnMViewIdx;
	Classes::TList* fParams;
	bool fSimplifiedParamsDialogs;
	Imageenio::TIETWainParams* fTwainParams;
	Iewia::TIEWia* fWIA;
	Hyiedefs::TMsgLanguage fMsgLanguage;
	Imageenio::TIOPreviewsParams fPreviewsParams;
	Graphics::TFont* fPreviewFont;
	int fTWainNextToInsert;
	bool fAutoAdjustDPI;
	bool fFilteredAdjustDPI;
	Hyieutils::TIEDitherMethod fDefaultDitherMethod;
	bool fResetPrinter;
	Imageenio::TIEDialogsMeasureUnit fDialogsMeasureUnit;
	bool fNativePixelFormat;
	Hyiedefs::TResampleFilter fPrintingFilterOnSubsampling;
	Imageenio::TIEDoPreviewsEvent fOnDoPreviews;
	void *fgrec;
	AnsiString fProxyAddress;
	AnsiString fProxyUser;
	AnsiString fProxyPassword;
	void __fastcall SetAttachedMView(Ieview::TIEView* v);
	void __fastcall RemoveIOParam(int idx);
	void __fastcall InsertIOParam(int idx);
	void __fastcall MoveIOParams(int idx, int destination);
	void __fastcall SwapIOParams(int idx1, int idx2);
	Imageenio::TIOParamsVals* __fastcall GetParams(int idx);
	void __fastcall SetPreviewFont(Graphics::TFont* f);
	int __fastcall GetParamsCount(void);
	void __fastcall SetIOPreviewParams(Imageenio::TIOPreviewsParams v);
	Imageenio::TIOPreviewsParams __fastcall GetIOPreviewParams(void);
	
protected:
	bool fAborting;
	Hyiedefs::TIEProgressEvent fOnProgress;
	Imageenio::TIEAcquireBitmapEvent fOnAcquireBitmap;
	Classes::TNotifyEvent fOnFinishWork;
	virtual void __fastcall TWMultiCallBack(Hyieutils::TIEBitmap* Bitmap, System::TObject* &IOParams);
	virtual void __fastcall TWCloseCallBack(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall OnBitmapChange(System::TObject* Sender, bool destroying);
	virtual void __fastcall DoFinishWork(void);
	virtual Iewia::TIEWia* __fastcall GetWIAParams(void);
	void __fastcall CheckDPI(Imageenio::TIOParamsVals* p);
	
public:
	__fastcall virtual TImageEnMIO(Classes::TComponent* Owner);
	__fastcall virtual ~TImageEnMIO(void);
	void __fastcall Update(void);
	__property Hyieutils::TIEDitherMethod DefaultDitherMethod = {read=fDefaultDitherMethod, write=fDefaultDitherMethod
		, nodefault};
	__property Imageenio::TIOParamsVals* Params[int idx] = {read=GetParams};
	__property int ParamsCount = {read=GetParamsCount, nodefault};
	void __fastcall DuplicateCompressionInfo(void);
	bool __fastcall DoPreviews(int idx, Imageenio::TPreviewParams pp);
	__property Imageenio::TIETWainParams* TWainParams = {read=fTwainParams};
	__property Iewia::TIEWia* WIAParams = {read=GetWIAParams};
	__property bool Aborting = {read=fAborting, write=fAborting, nodefault};
	void __fastcall LoadFromFileGIF(const AnsiString nf);
	void __fastcall LoadFromStreamGIF(Classes::TStream* Stream);
	void __fastcall SaveToFileGIF(const AnsiString nf);
	void __fastcall SaveToStreamGIF(Classes::TStream* Stream);
	void __fastcall LoadFromFileDCX(const AnsiString nf);
	void __fastcall LoadFromStreamDCX(Classes::TStream* Stream);
	void __fastcall SaveToFileDCX(const AnsiString nf);
	void __fastcall SaveToStreamDCX(Classes::TStream* Stream);
	void __fastcall LoadFromFileTIFF(const AnsiString nf);
	void __fastcall LoadFromStreamTIFF(Classes::TStream* Stream);
	void __fastcall SaveToFileTIFF(const AnsiString nf);
	void __fastcall SaveToStreamTIFF(Classes::TStream* Stream);
	void __fastcall LoadFromFileAVI(const AnsiString nf);
	void __fastcall SaveToFileAVI(const AnsiString nf, const AnsiString codec);
	void __fastcall SaveToFilePS(const AnsiString nf);
	void __fastcall SaveToStreamPS(Classes::TStream* Stream);
	void __fastcall SaveToFilePDF(const AnsiString nf);
	void __fastcall SaveToStreamPDF(Classes::TStream* Stream);
	void __fastcall LoadFromFileICO(const AnsiString nf);
	void __fastcall LoadFromStreamICO(Classes::TStream* Stream);
	void __fastcall LoadFromURL(AnsiString URL);
	void __fastcall LoadFromMediaFile(const AnsiString nf);
	bool __fastcall Acquire(Imageenio::TIEAcquireApi api);
	bool __fastcall SelectAcquireSource(Imageenio::TIEAcquireApi api);
	bool __fastcall AcquireOpen(void);
	void __fastcall AcquireClose(void);
	void __fastcall LoadFromFile(const AnsiString nf);
	void __fastcall SaveToFile(const AnsiString nf);
	void __fastcall LoadFromFileFormat(const AnsiString FileName, int FileFormat);
	void __fastcall LoadFromFileAuto(const AnsiString FileName);
	AnsiString __fastcall ExecuteOpenDialog(AnsiString InitialDir, AnsiString InitialFileName, bool AlwaysAnimate
		, int FilterIndex, AnsiString ExtendedFilters);
	AnsiString __fastcall ExecuteSaveDialog(AnsiString InitialDir, AnsiString InitialFileName, bool AlwaysAnimate
		, int FilterIndex, AnsiString ExtendedFilters);
	bool __fastcall DoPrintPreviewDialog(const AnsiString TaskName, bool PrintAnnotations, const AnsiString 
		Caption);
	__property bool ResetPrinter = {read=fResetPrinter, write=fResetPrinter, nodefault};
	__property bool NativePixelFormat = {read=fNativePixelFormat, write=fNativePixelFormat, nodefault};
		
	__property Hyiedefs::TResampleFilter PrintingFilterOnSubsampling = {read=fPrintingFilterOnSubsampling
		, write=fPrintingFilterOnSubsampling, nodefault};
	__property AnsiString ProxyAddress = {read=fProxyAddress, write=fProxyAddress};
	__property AnsiString ProxyUser = {read=fProxyUser, write=fProxyUser};
	__property AnsiString ProxyPassword = {read=fProxyPassword, write=fProxyPassword};
	
__published:
	__property Ieview::TIEView* AttachedMView = {read=fImageEnMView, write=SetAttachedMView};
	__property Hyiedefs::TIEProgressEvent OnProgress = {read=fOnProgress, write=fOnProgress};
	__property Imageenio::TIEAcquireBitmapEvent OnAcquireBitmap = {read=fOnAcquireBitmap, write=fOnAcquireBitmap
		};
	__property Hyiedefs::TMsgLanguage MsgLanguage = {read=fMsgLanguage, write=fMsgLanguage, default=0};
		
	__property Imageenio::TIOPreviewsParams PreviewsParams = {read=GetIOPreviewParams, write=SetIOPreviewParams
		, default=0};
	__property Graphics::TFont* PreviewFont = {read=fPreviewFont, write=SetPreviewFont};
	__property bool AutoAdjustDPI = {read=fAutoAdjustDPI, write=fAutoAdjustDPI, default=0};
	__property bool FilteredAdjustDPI = {read=fFilteredAdjustDPI, write=fFilteredAdjustDPI, default=0};
		
	__property bool SimplifiedParamsDialogs = {read=fSimplifiedParamsDialogs, write=fSimplifiedParamsDialogs
		, default=1};
	__property Classes::TNotifyEvent OnFinishWork = {read=fOnFinishWork, write=fOnFinishWork};
	__property Imageenio::TIEDialogsMeasureUnit DialogsMeasureUnit = {read=fDialogsMeasureUnit, write=fDialogsMeasureUnit
		, default=0};
	__property Imageenio::TIEDoPreviewsEvent OnDoPreviews = {read=fOnDoPreviews, write=fOnDoPreviews};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iemio */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Iemio;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// iemio
