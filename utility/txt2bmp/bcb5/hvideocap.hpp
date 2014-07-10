// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'hvideocap.pas' rev: 5.00

#ifndef hvideocapHPP
#define hvideocapHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyieutils.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
#include <videocap.hpp>	// Pascal unit
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

namespace Hvideocap
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TImageEnVideoCap;
class PASCALIMPLEMENTATION TImageEnVideoCap : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool fCapture;
	HWND fWndC;
	Classes::TStringList* fDrivers;
	int fVideoSource;
	bool fCallBackFrame;
	Videocap::TVideoFrameEvent fOnVideoFrame;
	Videocap::TVideoFrameRawEvent fOnVideoFrameRaw;
	unsigned fhBitmapInfo;
	bool fBitmapInfoUp;
	bool fConnected;
	Hyiedefs::TIEJobEvent fOnJob;
	unsigned fHDrawDib;
	Hyieutils::TIEDibbitmap* fBitmap;
	void *fPix;
	bool fDone;
	bool fDriverBusy;
	bool fEnding;
	bool fUseWindowsCodec;
	AnsiString fRecFileName;
	int fRecFrameRate;
	bool fRecAudio;
	bool fRecMultitask;
	bool fRecording;
	HWND fWinHandle;
	
protected:
	void __fastcall SetCapture(bool v);
	void __fastcall DriverConnect(void);
	bool __fastcall DriverConnectNE(void);
	void __fastcall DriverDisconnect(void);
	void __fastcall FillDrivers(void);
	void __fastcall SetVideoSource(int v);
	bool __fastcall GetHasDlgVideoSource(void);
	bool __fastcall GetHasDlgVideoFormat(void);
	bool __fastcall GetHasDlgVideoDisplay(void);
	bool __fastcall GetHasOverlay(void);
	void __fastcall GetCaps(Videocap::TCAPDRIVERCAPS &fDriverCaps);
	void __fastcall SetCallBackFrame(bool v);
	void __fastcall SetOnVideoFrame(Videocap::TVideoFrameEvent v);
	void __fastcall SetOnVideoFrameRaw(Videocap::TVideoFrameRawEvent v);
	bool __fastcall FillBitmapInfo(void);
	void __fastcall CreateCaptureWindow(void);
	void __fastcall DestroyCaptureWindow(void);
	void __fastcall DoJob(Hyiedefs::TIEJob job, int per);
	void __fastcall AllocateWindow(void);
	Word __fastcall GetAudioFormat(void);
	void __fastcall SetAudioFormat(Word v);
	Word __fastcall GetAudioChannels(void);
	void __fastcall SetAudioChannels(Word v);
	unsigned __fastcall GetAudioSamplesPerSec(void);
	void __fastcall SetAudioSamplesPerSec(unsigned v);
	Word __fastcall GetAudioBitsPerSample(void);
	void __fastcall SetAudioBitsPerSample(Word v);
	void __fastcall GetWaveFormat(Videocap::TWAVEFORMATEX &wf);
	void __fastcall SetWaveFormat(Videocap::TWAVEFORMATEX &wf);
	
public:
	__fastcall virtual TImageEnVideoCap(Classes::TComponent* Owner);
	__fastcall virtual ~TImageEnVideoCap(void);
	__property bool Capture = {read=fCapture, write=SetCapture, default=0};
	bool __fastcall DoConfigureSource(void);
	bool __fastcall DoConfigureFormat(void);
	bool __fastcall DoConfigureDisplay(void);
	bool __fastcall DoConfigureCompression(void);
	__property Classes::TStringList* VideoSourceList = {read=fDrivers};
	__property bool HasOverlay = {read=GetHasOverlay, nodefault};
	__property bool HasDlgVideoSource = {read=GetHasDlgVideoSource, nodefault};
	__property bool HasDlgVideoFormat = {read=GetHasDlgVideoFormat, nodefault};
	__property bool HasDlgVideoDisplay = {read=GetHasDlgVideoDisplay, nodefault};
	void __fastcall StartRecord(void);
	void __fastcall StopRecord(void);
	__property AnsiString RecFileName = {read=fRecFileName, write=fRecFileName};
	__property int RecFrameRate = {read=fRecFrameRate, write=fRecFrameRate, nodefault};
	__property bool RecAudio = {read=fRecAudio, write=fRecAudio, nodefault};
	__property bool RecMultitask = {read=fRecMultitask, write=fRecMultitask, nodefault};
	__property HWND WndCaptureHandle = {read=fWndC, nodefault};
	__property Word AudioFormat = {read=GetAudioFormat, write=SetAudioFormat, nodefault};
	__property Word AudioChannels = {read=GetAudioChannels, write=SetAudioChannels, nodefault};
	__property unsigned AudioSamplesPerSec = {read=GetAudioSamplesPerSec, write=SetAudioSamplesPerSec, 
		nodefault};
	__property Word AudioBitsPerSample = {read=GetAudioBitsPerSample, write=SetAudioBitsPerSample, nodefault
		};
	Windows::TRect __fastcall GetVideoSize(void);
	__property bool UseWindowsCodec = {read=fUseWindowsCodec, write=fUseWindowsCodec, nodefault};
	
__published:
	__property int VideoSource = {read=fVideoSource, write=SetVideoSource, default=0};
	__property Videocap::TVideoFrameEvent OnVideoFrame = {read=fOnVideoFrame, write=SetOnVideoFrame};
	__property Videocap::TVideoFrameRawEvent OnVideoFrameRaw = {read=fOnVideoFrameRaw, write=SetOnVideoFrameRaw
		};
	__property Hyiedefs::TIEJobEvent OnJob = {read=fOnJob, write=fOnJob};
};


//-- var, const, procedure ---------------------------------------------------
static const Word VH_FRAMEMESSAGE = 0x1788;
static const Word VH_DESTROYWINDOW = 0x1789;

}	/* namespace Hvideocap */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Hvideocap;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// hvideocap
