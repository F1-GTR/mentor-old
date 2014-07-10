// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'videocap.pas' rev: 5.00

#ifndef videocapHPP
#define videocapHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyieutils.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
#include <ievect.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <imageenview.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Videocap
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TVideoCapException;
class PASCALIMPLEMENTATION TVideoCapException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall TVideoCapException(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall TVideoCapException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall TVideoCapException(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall TVideoCapException(int Ident, const System::TVarRec 
		* Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall TVideoCapException(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall TVideoCapException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall TVideoCapException(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall TVideoCapException(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TVideoCapException(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TVCDisplayMode { dmPreview, dmOverlay };
#pragma option pop

typedef void __fastcall (__closure *TVideoFrameEvent)(System::TObject* Sender, Hyieutils::TIEDibbitmap* 
	Bitmap);

typedef void __fastcall (__closure *TVideoFrameRawEvent)(System::TObject* Sender, unsigned hDib, void * 
	pData);

struct TCAPDRIVERCAPS
{
	int wDeviceIndex;
	BOOL fHasOverlay;
	BOOL fHasDlgVideoSource;
	BOOL fHasDlgVideoFormat;
	BOOL fHasDlgVideoDisplay;
	BOOL fCaptureInitialized;
	BOOL fDriverSuppliesPalettes;
	unsigned hVideoIn;
	unsigned hVideoOut;
	unsigned hVideoExtIn;
	unsigned hVideoExtout;
} ;

typedef TCAPDRIVERCAPS *PCAPDRIVERCAPS;

struct TVIDEOHDR
{
	Byte *lpData;
	unsigned dwBufferLength;
	unsigned dwBytesUsed;
	unsigned dwTimeCaptured;
	unsigned dwUser;
	unsigned dwFlags;
	unsigned dwReserved[4];
} ;

typedef TVIDEOHDR *PVIDEOHDR;

struct TCAPSTATUS
{
	unsigned uiImageWidth;
	unsigned uiImageHeight;
	BOOL fLiveWindow;
	BOOL fOverlayWindow;
	BOOL fScale;
	Windows::TPoint ptScroll;
	BOOL fUsingDefaultPalette;
	BOOL fAudioHardware;
	BOOL fCapFileExists;
	unsigned dwCurrentVideoFrame;
	unsigned dwCurrentVideoFramesDropped;
	unsigned dwCurrentWaveSamples;
	unsigned dwCurrentTimeElapsedMS;
	unsigned hPalCurrent;
	BOOL fCapturingNow;
	unsigned dwReturn;
	unsigned wNumVideoAllocated;
	unsigned wNumAudioAllocated;
} ;

typedef TCAPSTATUS *PCAPSTATUS;

struct TCAPTUREPARMS;
typedef TCAPTUREPARMS *PCAPTUREPARMS;

struct TCAPTUREPARMS
{
	unsigned dwRequestMicroSecPerFrame;
	BOOL fMakeUserHitOKToCapture;
	unsigned wPercentDropForError;
	BOOL fYield;
	unsigned dwIndexSize;
	unsigned wChunkGranularity;
	BOOL fUsingDOSMemory;
	unsigned wNumVideoRequested;
	BOOL fCaptureAudio;
	unsigned wNumAudioRequested;
	unsigned vKeyAbort;
	BOOL fAbortLeftMouse;
	BOOL fAbortRightMouse;
	BOOL fLimitEnabled;
	unsigned wTimeLimit;
	BOOL fMCIControl;
	BOOL fStepMCIDevice;
	unsigned dwMCIStartTime;
	unsigned dwMCIStopTime;
	BOOL fStepCaptureAt2x;
	unsigned wStepCaptureAverageFrames;
	unsigned dwAudioBufferSize;
	BOOL fDisableWriteCache;
	unsigned AVStreamMaster;
} ;

struct TWAVEFORMATEX;
typedef TWAVEFORMATEX *PWAVEFORMATEX;

struct TWAVEFORMATEX
{
	Word wFormatTag;
	Word nChannels;
	unsigned nSamplesPerSec;
	unsigned nAvgBytesPerSec;
	Word nBlockAlign;
	Word wBitsPerSample;
	Word cbSize;
} ;

class DELPHICLASS TImageEnVideoView;
class PASCALIMPLEMENTATION TImageEnVideoView : public Ievect::TImageEnVect 
{
	typedef Ievect::TImageEnVect inherited;
	
private:
	bool fShowVideo;
	bool fFreeze;
	TVCDisplayMode fDisplayMode;
	HWND fWndC;
	Classes::TStringList* fDrivers;
	int fVideoSource;
	Stdctrls::TScrollStyle fSScrollBars;
	int fPreviewRate;
	bool fCallBackFrame;
	TVideoFrameEvent fOnVideoFrame;
	TVideoFrameRawEvent fOnVideoFrameRaw;
	unsigned fhBitmapInfo;
	bool fBitmapInfoUp;
	bool fConnected;
	bool fFitFreeze;
	Hyiedefs::TIEJobEvent fOnJob;
	unsigned fHDrawDib;
	bool fGrabFrame;
	AnsiString fRecFileName;
	int fRecFrameRate;
	bool fRecAudio;
	bool fRecMultitask;
	bool fRecording;
	bool fCreatingCaptureWindow;
	
protected:
	void __fastcall SetShowVideo(bool v);
	void __fastcall SetFreeze(bool v);
	void __fastcall SetDisplayMode(TVCDisplayMode v);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	bool __fastcall DriverConnect(void);
	bool __fastcall DriverConnectNE(void);
	void __fastcall DriverDisconnect(void);
	void __fastcall SetVideoSource(int v);
	virtual void __fastcall SetScrollBars(Stdctrls::TScrollStyle v);
	bool __fastcall GetHasDlgVideoSource(void);
	bool __fastcall GetHasDlgVideoFormat(void);
	bool __fastcall GetHasDlgVideoDisplay(void);
	bool __fastcall GetHasOverlay(void);
	void __fastcall GetCaps(TCAPDRIVERCAPS &fDriverCaps);
	void __fastcall SetPreviewRate(int v);
	void __fastcall SetCallBackFrame(bool v);
	void __fastcall SetOnVideoFrame(TVideoFrameEvent v);
	void __fastcall SetOnVideoFrameRaw(TVideoFrameRawEvent v);
	bool __fastcall FillBitmapInfo(void);
	void __fastcall CreateCaptureWindow(void);
	void __fastcall DestroyCaptureWindow(void);
	void __fastcall DoJob(Hyiedefs::TIEJob job, int per);
	void __fastcall DecompRawFrame(Hyieutils::TIEDibbitmap* OutBitmap, void * pix);
	Word __fastcall GetAudioFormat(void);
	void __fastcall SetAudioFormat(Word v);
	Word __fastcall GetAudioChannels(void);
	void __fastcall SetAudioChannels(Word v);
	unsigned __fastcall GetAudioSamplesPerSec(void);
	void __fastcall SetAudioSamplesPerSec(unsigned v);
	Word __fastcall GetAudioBitsPerSample(void);
	void __fastcall SetAudioBitsPerSample(Word v);
	void __fastcall GetWaveFormat(TWAVEFORMATEX &wf);
	void __fastcall SetWaveFormat(TWAVEFORMATEX &wf);
	
public:
	__fastcall virtual TImageEnVideoView(Classes::TComponent* Owner);
	__fastcall virtual ~TImageEnVideoView(void);
	void __fastcall FillDrivers(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Select(int x1, int y1, int x2, int y2, Imageenview::TIESelOp Op);
	bool __fastcall DoConfigureSource(void);
	bool __fastcall DoConfigureFormat(void);
	bool __fastcall DoConfigureDisplay(void);
	bool __fastcall DoConfigureCompression(void);
	void __fastcall Freeze(void);
	void __fastcall UnFreeze(void);
	__property bool Frozen = {read=fFreeze, write=SetFreeze, default=0};
	void __fastcall SaveFrame(void);
	__property Classes::TStringList* VideoSourceList = {read=fDrivers};
	__property bool HasOverlay = {read=GetHasOverlay, nodefault};
	__property bool HasDlgVideoSource = {read=GetHasDlgVideoSource, nodefault};
	__property bool HasDlgVideoFormat = {read=GetHasDlgVideoFormat, nodefault};
	__property bool HasDlgVideoDisplay = {read=GetHasDlgVideoDisplay, nodefault};
	bool __fastcall StartRecord(void);
	void __fastcall StopRecord(void);
	__property AnsiString RecFileName = {read=fRecFileName, write=fRecFileName};
	__property int RecFrameRate = {read=fRecFrameRate, write=fRecFrameRate, nodefault};
	__property bool RecAudio = {read=fRecAudio, write=fRecAudio, nodefault};
	__property bool RecMultitask = {read=fRecMultitask, write=fRecMultitask, nodefault};
	__property HWND WndCaptureHandle = {read=fWndC, nodefault};
	Windows::TRect __fastcall GetVideoSize(void);
	__property Word AudioFormat = {read=GetAudioFormat, write=SetAudioFormat, nodefault};
	__property Word AudioChannels = {read=GetAudioChannels, write=SetAudioChannels, nodefault};
	__property unsigned AudioSamplesPerSec = {read=GetAudioSamplesPerSec, write=SetAudioSamplesPerSec, 
		nodefault};
	__property Word AudioBitsPerSample = {read=GetAudioBitsPerSample, write=SetAudioBitsPerSample, nodefault
		};
	
__published:
	__property bool FitFreeze = {read=fFitFreeze, write=fFitFreeze, default=1};
	__property TVCDisplayMode DisplayMode = {read=fDisplayMode, write=SetDisplayMode, default=0};
	__property bool ShowVideo = {read=fShowVideo, write=SetShowVideo, default=0};
	__property int VideoSource = {read=fVideoSource, write=SetVideoSource, default=0};
	__property int PreviewRate = {read=fPreviewRate, write=SetPreviewRate, default=60};
	__property TVideoFrameEvent OnVideoFrame = {read=fOnVideoFrame, write=SetOnVideoFrame};
	__property TVideoFrameRawEvent OnVideoFrameRaw = {read=fOnVideoFrameRaw, write=SetOnVideoFrameRaw};
		
	__property Hyiedefs::TIEJobEvent OnJob = {read=fOnJob, write=fOnJob};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TImageEnVideoView(HWND ParentWindow) : Ievect::TImageEnVect(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Videocap */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Videocap;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// videocap
