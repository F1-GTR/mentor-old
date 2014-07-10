// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ieds.pas' rev: 5.00

#ifndef iedsHPP
#define iedsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <imageenproc.hpp>	// Pascal unit
#include <iewia.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ieds
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct IEREFERENCE_TIME
{
	unsigned lo32;
	unsigned hi32;
} ;
#pragma pack(pop)

typedef IEREFERENCE_TIME *PIEREFERENCE_TIME;

__interface IIESequentialStream;
typedef System::DelphiInterface<IIESequentialStream> _di_IIESequentialStream;
__interface INTERFACE_UUID("{0C733A30-2A1C-11CE-ADE5-00AA0044773D}") IIESequentialStream  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall Read(void) = 0 ;
	virtual HRESULT __stdcall Write(void) = 0 ;
};

__interface IIEStream;
typedef System::DelphiInterface<IIEStream> _di_IIEStream;
__interface INTERFACE_UUID("{0000000C-0000-0000-C000-000000000046}") IIEStream  : public IIESequentialStream 
	
{
	
public:
	virtual HRESULT __stdcall Seek(void) = 0 ;
	virtual HRESULT __stdcall SetSize(void) = 0 ;
	virtual HRESULT __stdcall CopyTo(void) = 0 ;
	virtual HRESULT __stdcall Commit(void) = 0 ;
	virtual HRESULT __stdcall Revert(void) = 0 ;
	virtual HRESULT __stdcall LockRegion(void) = 0 ;
	virtual HRESULT __stdcall UnlockRegion(void) = 0 ;
	virtual HRESULT __stdcall Stat(void) = 0 ;
	virtual HRESULT __stdcall Clone(void) = 0 ;
};

__interface IIEStorage;
typedef System::DelphiInterface<IIEStorage> _di_IIEStorage;
__interface INTERFACE_UUID("{0000000B-0000-0000-C000-000000000046}") IIEStorage  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall CreateStream(wchar_t * pwcsName, int grfMode, int reserved1, int reserved2
		, /* out */ _di_IIEStream &stm) = 0 ;
	virtual HRESULT __stdcall OpenStream(void) = 0 ;
	virtual HRESULT __stdcall CreateStorage(void) = 0 ;
	virtual HRESULT __stdcall OpenStorage(void) = 0 ;
	virtual HRESULT __stdcall CopyTo(void) = 0 ;
	virtual HRESULT __stdcall MoveElementTo(void) = 0 ;
	virtual HRESULT __stdcall Commit(int grfCommitFlags) = 0 ;
	virtual HRESULT __stdcall Revert(void) = 0 ;
	virtual HRESULT __stdcall EnumElements(void) = 0 ;
	virtual HRESULT __stdcall DestroyElement(void) = 0 ;
	virtual HRESULT __stdcall RenameElement(void) = 0 ;
	virtual HRESULT __stdcall SetElementTimes(void) = 0 ;
	virtual HRESULT __stdcall SetClass(void) = 0 ;
	virtual HRESULT __stdcall SetStateBits(void) = 0 ;
	virtual HRESULT __stdcall Stat(void) = 0 ;
};

__interface IIEPersist;
typedef System::DelphiInterface<IIEPersist> _di_IIEPersist;
__interface INTERFACE_UUID("{0000010C-0000-0000-C000-000000000046}") IIEPersist  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall GetClassID(void) = 0 ;
};

__interface IIEPersistStream;
typedef System::DelphiInterface<IIEPersistStream> _di_IIEPersistStream;
__interface INTERFACE_UUID("{00000109-0000-0000-C000-000000000046}") IIEPersistStream  : public IIEPersist 
	
{
	
public:
	virtual HRESULT __stdcall IsDirty(void) = 0 ;
	virtual HRESULT __stdcall Load(const _di_IIEStream stm) = 0 ;
	virtual HRESULT __stdcall Save(const _di_IIEStream stm, BOOL fClearDirty) = 0 ;
	virtual HRESULT __stdcall GetSizeMax(void) = 0 ;
};

typedef IIEPersistStream IID_IIEPersistStream;
;

__interface IIEEnumMoniker;
typedef System::DelphiInterface<IIEEnumMoniker> _di_IIEEnumMoniker;
__interface INTERFACE_UUID("{00000102-0000-0000-C000-000000000046}") IIEEnumMoniker  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall Next(int celt, /* out */ void *elt, void * pceltFetched) = 0 ;
	virtual HRESULT __stdcall Skip(void) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Clone(void) = 0 ;
};

__interface IIEBindCtx;
typedef System::DelphiInterface<IIEBindCtx> _di_IIEBindCtx;
__interface INTERFACE_UUID("{0000000E-0000-0000-C000-000000000046}") IIEBindCtx  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall RegisterObjectBound(void) = 0 ;
	virtual HRESULT __stdcall RevokeObjectBound(void) = 0 ;
	virtual HRESULT __stdcall ReleaseBoundObjects(void) = 0 ;
	virtual HRESULT __stdcall SetBindOptions(void) = 0 ;
	virtual HRESULT __stdcall GetBindOptions(void) = 0 ;
	virtual HRESULT __stdcall GetRunningObjectTable(void) = 0 ;
	virtual HRESULT __stdcall RegisterObjectParam(void) = 0 ;
	virtual HRESULT __stdcall GetObjectParam(void) = 0 ;
	virtual HRESULT __stdcall EnumObjectParam(void) = 0 ;
	virtual HRESULT __stdcall RevokeObjectParam(void) = 0 ;
};

__interface IIEMoniker;
typedef System::DelphiInterface<IIEMoniker> _di_IIEMoniker;
__interface INTERFACE_UUID("{0000000F-0000-0000-C000-000000000046}") IIEMoniker  : public IIEPersistStream 
	
{
	
public:
	virtual HRESULT __stdcall BindToObject(const _di_IIEBindCtx bc, const _di_IIEMoniker mkToLeft, const 
		GUID &iidResult, /* out */ void *vResult) = 0 ;
	virtual HRESULT __stdcall BindToStorage(const _di_IIEBindCtx bc, const _di_IIEMoniker mkToLeft, const 
		GUID &iid, /* out */ void *vObj) = 0 ;
	virtual HRESULT __stdcall Reduce(void) = 0 ;
	virtual HRESULT __stdcall ComposeWith(void) = 0 ;
	virtual HRESULT __stdcall Enum(void) = 0 ;
	virtual HRESULT __stdcall IsEqual(void) = 0 ;
	virtual HRESULT __stdcall Hash(void) = 0 ;
	virtual HRESULT __stdcall IsRunning(void) = 0 ;
	virtual HRESULT __stdcall GetTimeOfLastChange(void) = 0 ;
	virtual HRESULT __stdcall Inverse(void) = 0 ;
	virtual HRESULT __stdcall CommonPrefixWith(void) = 0 ;
	virtual HRESULT __stdcall RelativePathTo(void) = 0 ;
	virtual HRESULT __stdcall GetDisplayName(void) = 0 ;
	virtual HRESULT __stdcall ParseDisplayName(void) = 0 ;
	virtual HRESULT __stdcall IsSystemMoniker(void) = 0 ;
};

__interface IIECreateDevEnum;
typedef System::DelphiInterface<IIECreateDevEnum> _di_IIECreateDevEnum;
__interface INTERFACE_UUID("{29840822-5B84-11D0-BD3B-00A0C911CE86}") IIECreateDevEnum  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall CreateClassEnumerator(const GUID &clsidDeviceClass, _di_IIEEnumMoniker &ppEnumMoniker
		, unsigned dwFlags) = 0 ;
};

typedef IIECreateDevEnum IID_IIECreateDevEnum;
;

__interface IIEErrorLog;
typedef System::DelphiInterface<IIEErrorLog> _di_IIEErrorLog;
__interface INTERFACE_UUID("{3127CA40-446E-11CE-8135-00AA004BB851}") IIEErrorLog  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall AddError(void) = 0 ;
};

struct TIECAGUID
{
	int cElems;
	void *pElems;
} ;

__interface IIESpecifyPropertyPages;
typedef System::DelphiInterface<IIESpecifyPropertyPages> _di_IIESpecifyPropertyPages;
__interface INTERFACE_UUID("{B196B28B-BAB4-101A-B69C-00AA00341D07}") IIESpecifyPropertyPages  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetPages(/* out */ TIECAGUID &pages) = 0 ;
};

typedef IIESpecifyPropertyPages IID_IIESpecifyPropertyPages;
;

__interface IAMVideoCompression;
typedef System::DelphiInterface<IAMVideoCompression> _di_IAMVideoCompression;
__interface INTERFACE_UUID("{C6E13343-30AC-11D0-A18C-00A0C9118956}") IAMVideoCompression  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall put_KeyFrameRate(int KeyFrameRate) = 0 ;
	virtual HRESULT __stdcall get_KeyFrameRate(int &pKeyFrameRate) = 0 ;
	virtual HRESULT __stdcall put_PFramesPerKeyFrame(void) = 0 ;
	virtual HRESULT __stdcall get_PFramesPerKeyFrame(void) = 0 ;
	virtual HRESULT __stdcall put_Quality(double Quality) = 0 ;
	virtual HRESULT __stdcall get_Quality(double &pQuality) = 0 ;
	virtual HRESULT __stdcall put_WindowSize(void) = 0 ;
	virtual HRESULT __stdcall get_WindowSize(void) = 0 ;
	virtual HRESULT __stdcall GetInfo(void) = 0 ;
	virtual HRESULT __stdcall OverrideKeyFrame(void) = 0 ;
	virtual HRESULT __stdcall OverrideFrameSize(void) = 0 ;
};

typedef IAMVideoCompression IID_IAMVideoCompression;
;

__interface IIEPropertyBag;
typedef System::DelphiInterface<IIEPropertyBag> _di_IIEPropertyBag;
__interface INTERFACE_UUID("{55272A00-42CB-11CE-8135-00AA004BB851}") IIEPropertyBag  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall Read(wchar_t * pszPropName, OleVariant &pvar, const _di_IIEErrorLog pErrorLog
		) = 0 ;
	virtual HRESULT __stdcall Write(void) = 0 ;
};

typedef IIEPropertyBag IID_IIEPropertyBag;
;

__interface IMediaFilter;
typedef System::DelphiInterface<IMediaFilter> _di_IMediaFilter;
__interface INTERFACE_UUID("{56A86899-0AD4-11CE-B03A-0020AF0BA770}") IMediaFilter  : public IIEPersist 
	
{
	
public:
	virtual HRESULT __stdcall Stop(void) = 0 ;
	virtual HRESULT __stdcall Pause(void) = 0 ;
	virtual HRESULT __stdcall Run(void) = 0 ;
	virtual HRESULT __stdcall GetState(void) = 0 ;
	virtual HRESULT __stdcall SetSyncSource(void * pClock) = 0 ;
	virtual HRESULT __stdcall GetSyncSource(void) = 0 ;
};

__interface IPin;
typedef System::DelphiInterface<IPin> _di_IPin;
__interface INTERFACE_UUID("{56A86891-0AD4-11CE-B03A-0020AF0BA770}") IPin  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall Connect(void) = 0 ;
	virtual HRESULT __stdcall ReceiveConnection(void) = 0 ;
	virtual HRESULT __stdcall Disconnect(void) = 0 ;
	virtual HRESULT __stdcall ConnectedTo(void) = 0 ;
	virtual HRESULT __stdcall ConnectionMediaType(void) = 0 ;
	virtual HRESULT __stdcall QueryPinInfo(void * pInfo) = 0 ;
	virtual HRESULT __stdcall QueryDirection(void) = 0 ;
	virtual HRESULT __stdcall QueryId(void) = 0 ;
	virtual HRESULT __stdcall QueryAccept(void) = 0 ;
	virtual HRESULT __stdcall EnumMediaTypes(void) = 0 ;
	virtual HRESULT __stdcall QueryInternalConnections(void) = 0 ;
	virtual HRESULT __stdcall EndOfStream(void) = 0 ;
	virtual HRESULT __stdcall BeginFlush(void) = 0 ;
	virtual HRESULT __stdcall EndFlush(void) = 0 ;
	virtual HRESULT __stdcall NewSegment(void) = 0 ;
};

__interface IEnumPins;
typedef System::DelphiInterface<IEnumPins> _di_IEnumPins;
__interface INTERFACE_UUID("{56A86892-0AD4-11CE-B03A-0020AF0BA770}") IEnumPins  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall Next(int cPins, _di_IPin &ppPins, int &pcFetched) = 0 ;
	virtual HRESULT __stdcall Skip(void) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Clone(void) = 0 ;
};

__interface IBaseFilter;
typedef System::DelphiInterface<IBaseFilter> _di_IBaseFilter;
__interface INTERFACE_UUID("{56A86895-0AD4-11CE-B03A-0020AF0BA770}") IBaseFilter  : public IMediaFilter 
	
{
	
public:
	virtual HRESULT __stdcall EnumPins(_di_IEnumPins &ppEnum) = 0 ;
	virtual HRESULT __stdcall FindPin(void) = 0 ;
	virtual HRESULT __stdcall QueryFilterInfo(void * pInfo) = 0 ;
	virtual HRESULT __stdcall JoinFilterGraph(void) = 0 ;
	virtual HRESULT __stdcall QueryVendorInfo(void) = 0 ;
};

typedef IBaseFilter IID_BaseFilter;
;

__interface IFilterGraph;
typedef System::DelphiInterface<IFilterGraph> _di_IFilterGraph;
__interface INTERFACE_UUID("{56A8689F-0AD4-11CE-B03A-0020AF0BA770}") IFilterGraph  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall AddFilter(_di_IBaseFilter pFilter, wchar_t * pName) = 0 ;
	virtual HRESULT __stdcall RemoveFilter(void) = 0 ;
	virtual HRESULT __stdcall EnumFilters(void) = 0 ;
	virtual HRESULT __stdcall FindFilterByName(void) = 0 ;
	virtual HRESULT __stdcall ConnectDirect(void) = 0 ;
	virtual HRESULT __stdcall Reconnect(void) = 0 ;
	virtual HRESULT __stdcall Disconnect(void) = 0 ;
	virtual HRESULT __stdcall SetDefaultSyncSource(void) = 0 ;
};

typedef IFilterGraph IID_IFilterGraph;
;

struct FILTER_INFO
{
	wchar_t achName[128];
	_di_IFilterGraph pGraph;
} ;

struct PIN_INFO
{
	_di_IBaseFilter pFilter;
	int dir;
	wchar_t achName[128];
} ;

__interface IGraphBuilder;
typedef System::DelphiInterface<IGraphBuilder> _di_IGraphBuilder;
__interface INTERFACE_UUID("{56A868A9-0AD4-11CE-B03A-0020AF0BA770}") IGraphBuilder  : public IFilterGraph 
	
{
	
public:
	virtual HRESULT __stdcall Connect(void) = 0 ;
	virtual HRESULT __stdcall Render(void) = 0 ;
	virtual HRESULT __stdcall RenderFile(void) = 0 ;
	virtual HRESULT __stdcall AddSourceFilter(wchar_t * lpwstrFileName, wchar_t * lpwstrFilterName, _di_IBaseFilter 
		&ppFilter) = 0 ;
	virtual HRESULT __stdcall SetLogFile(void) = 0 ;
	virtual HRESULT __stdcall Abort(void) = 0 ;
	virtual HRESULT __stdcall ShouldOperationContinue(void) = 0 ;
};

typedef IGraphBuilder IID_IGraphBuilder;
;

__interface IFileSinkFilter;
typedef System::DelphiInterface<IFileSinkFilter> _di_IFileSinkFilter;
__interface INTERFACE_UUID("{A2104830-7C70-11CF-8BCE-00AA00A3F1A6}") IFileSinkFilter  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall SetFileName(void) = 0 ;
	virtual HRESULT __stdcall GetCurFile(void) = 0 ;
};

__interface ICaptureGraphBuilder2;
typedef System::DelphiInterface<ICaptureGraphBuilder2> _di_ICaptureGraphBuilder2;
__interface INTERFACE_UUID("{93E5A4E0-2D50-11D2-ABFA-00A0C9C6E38D}") ICaptureGraphBuilder2  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall SetFiltergraph(_di_IGraphBuilder pfg) = 0 ;
	virtual HRESULT __stdcall GetFiltergraph(void) = 0 ;
	virtual HRESULT __stdcall SetOutputFileName(const GUID &pType, wchar_t * lpwstrFile, _di_IBaseFilter 
		&ppf, _di_IFileSinkFilter &pSink) = 0 ;
	virtual HRESULT __stdcall FindInterface(System::PGUID pCategory, System::PGUID pType, _di_IBaseFilter 
		pf, const GUID &riid, _di_IUnknown &ppint) = 0 ;
	virtual HRESULT __stdcall RenderStream(System::PGUID pCategory, System::PGUID pType, _di_IUnknown pSource
		, _di_IBaseFilter pIntermediate, _di_IBaseFilter pSink) = 0 ;
	virtual HRESULT __stdcall ControlStream(System::PGUID pCategory, System::PGUID pType, _di_IBaseFilter 
		pFilter, PIEREFERENCE_TIME pstart, PIEREFERENCE_TIME pstop, Word wStartCookie, Word wStopCookie) = 0 
		;
	virtual HRESULT __stdcall AllocCapFile(void) = 0 ;
	virtual HRESULT __stdcall CopyCaptureFile(void) = 0 ;
	virtual HRESULT __stdcall FindPin(_di_IUnknown pSource, int pindir, System::PGUID pCategory, System::PGUID 
		pType, BOOL fUnconnected, int num, _di_IPin &ppPin) = 0 ;
};

typedef ICaptureGraphBuilder2 IID_ICaptureGraphBuilder2;
;

#pragma option push -b-
enum TIEDirectShowState { gsStopped, gsPaused, gsRunning };
#pragma option pop

__interface IMediaControl;
typedef System::DelphiInterface<IMediaControl> _di_IMediaControl;
__interface INTERFACE_UUID("{56A868B1-0AD4-11CE-B03A-0020AF0BA770}") IMediaControl  : public IDispatch 
	
{
	
public:
	virtual HRESULT __stdcall Run(void) = 0 ;
	virtual HRESULT __stdcall Pause(void) = 0 ;
	virtual HRESULT __stdcall Stop(void) = 0 ;
	virtual HRESULT __stdcall GetState(unsigned msTimeout, TIEDirectShowState &pfs) = 0 ;
	virtual HRESULT __stdcall RenderFile(void) = 0 ;
	virtual HRESULT __stdcall AddSourceFilter(void) = 0 ;
	virtual HRESULT __stdcall get_FilterCollection(void) = 0 ;
	virtual HRESULT __stdcall get_RegFilterCollection(void) = 0 ;
	virtual HRESULT __stdcall StopWhenReady(void) = 0 ;
};

typedef IMediaControl IID_IMediaControl;
;

__interface IMediaSeeking;
typedef System::DelphiInterface<IMediaSeeking> _di_IMediaSeeking;
__interface INTERFACE_UUID("{36B73880-C2C8-11CF-8B46-00805F6CEF60}") IMediaSeeking  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetCapabilities(void) = 0 ;
	virtual HRESULT __stdcall CheckCapabilities(void) = 0 ;
	virtual HRESULT __stdcall IsFormatSupported(void) = 0 ;
	virtual HRESULT __stdcall QueryPreferredFormat(void) = 0 ;
	virtual HRESULT __stdcall GetTimeFormat(System::PGUID pFormat) = 0 ;
	virtual HRESULT __stdcall IsUsingTimeFormat(void) = 0 ;
	virtual HRESULT __stdcall SetTimeFormat(System::PGUID pFormat) = 0 ;
	virtual HRESULT __stdcall GetDuration(PIEREFERENCE_TIME pDuration) = 0 ;
	virtual HRESULT __stdcall GetStopPosition(void) = 0 ;
	virtual HRESULT __stdcall GetCurrentPosition(PIEREFERENCE_TIME pCurrent) = 0 ;
	virtual HRESULT __stdcall ConvertTimeFormat(PIEREFERENCE_TIME pTarget, System::PGUID pTargetFormat, 
		PIEREFERENCE_TIME Source, System::PGUID pSourceFormat) = 0 ;
	virtual HRESULT __stdcall SetPositions(PIEREFERENCE_TIME pCurrent, unsigned dwCurrentFlags, PIEREFERENCE_TIME 
		pStop, unsigned dwStopFlags) = 0 ;
	virtual HRESULT __stdcall GetPositions(PIEREFERENCE_TIME pCurrent, PIEREFERENCE_TIME pStop) = 0 ;
	virtual HRESULT __stdcall GetAvailable(void) = 0 ;
	virtual HRESULT __stdcall SetRate(double dRate) = 0 ;
	virtual HRESULT __stdcall GetRate(Windows::PDouble dRate) = 0 ;
	virtual HRESULT __stdcall GetPreroll(void) = 0 ;
};

typedef IMediaSeeking IID_IMediaSeeking;
;

__interface IMediaEvent;
typedef System::DelphiInterface<IMediaEvent> _di_IMediaEvent;
__interface INTERFACE_UUID("{56A868B6-0AD4-11CE-B03A-0020AF0BA770}") IMediaEvent  : public IDispatch 
	
{
	
public:
	virtual HRESULT __stdcall GetEventHandle(void) = 0 ;
	virtual HRESULT __stdcall GetEvent(int &lEventCode, int &lParam1, int &lParam2, int msTimeout) = 0 
		;
	virtual HRESULT __stdcall WaitForCompletion(int msTimeout, int &pEvCode) = 0 ;
	virtual HRESULT __stdcall CancelDefaultHandling(void) = 0 ;
	virtual HRESULT __stdcall RestoreDefaultHandling(void) = 0 ;
	virtual HRESULT __stdcall FreeEventParams(int lEventCode, int lParam1, int lParam2) = 0 ;
};

typedef IMediaEvent IID_IMediaEvent;
;

__interface IMediaEventEx;
typedef System::DelphiInterface<IMediaEventEx> _di_IMediaEventEx;
__interface INTERFACE_UUID("{56A868C0-0AD4-11CE-B03A-0020AF0BA770}") IMediaEventEx  : public IMediaEvent 
	
{
	
public:
	virtual HRESULT __stdcall SetNotifyWindow(unsigned hwnd, int lMsg, int lInstanceData) = 0 ;
	virtual HRESULT __stdcall SetNotifyFlags(void) = 0 ;
	virtual HRESULT __stdcall GetNotifyFlags(void) = 0 ;
};

typedef IMediaEventEx IID_IMediaEventEx;
;

struct IEAM_MEDIA_TYPE
{
	GUID majortype;
	GUID subtype;
	BOOL bFixedSizeSamples;
	BOOL bTemporalCompression;
	unsigned lSampleSize;
	GUID formattype;
	_di_IUnknown pUnk;
	unsigned cbFormat;
	Byte *pbFormat;
} ;

typedef IEAM_MEDIA_TYPE *PIEAM_MEDIA_TYPE;

struct IEVIDEOINFOHEADER
{
	Windows::TRect rcSource;
	Windows::TRect rcTarget;
	unsigned dwBitRate;
	unsigned dwBitErrorRate;
	IEREFERENCE_TIME AvgTimePerFrame;
	tagBITMAPINFOHEADER bmiHeader;
} ;

typedef IEVIDEOINFOHEADER *PIEVIDEOINFOHEADER;

__interface IMediaSample;
typedef System::DelphiInterface<IMediaSample> _di_IMediaSample;
__interface INTERFACE_UUID("{56A8689A-0AD4-11CE-B03A-0020AF0BA770}") IMediaSample  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetPointer(void) = 0 ;
	virtual int __stdcall GetSize(void) = 0 ;
	virtual HRESULT __stdcall GetTime(void) = 0 ;
	virtual HRESULT __stdcall SetTime(void) = 0 ;
	virtual HRESULT __stdcall IsSyncPoint(void) = 0 ;
	virtual HRESULT __stdcall SetSyncPoint(void) = 0 ;
	virtual HRESULT __stdcall IsPreroll(void) = 0 ;
	virtual HRESULT __stdcall SetPreroll(void) = 0 ;
	virtual int __stdcall GetActualDataLength(void) = 0 ;
	virtual HRESULT __stdcall SetActualDataLength(void) = 0 ;
	virtual HRESULT __stdcall GetMediaType(void) = 0 ;
	virtual HRESULT __stdcall SetMediaType(void) = 0 ;
	virtual HRESULT __stdcall IsDiscontinuity(void) = 0 ;
	virtual HRESULT __stdcall SetDiscontinuity(void) = 0 ;
	virtual HRESULT __stdcall GetMediaTime(void) = 0 ;
	virtual HRESULT __stdcall SetMediaTime(void) = 0 ;
};

__interface ISampleGrabberCB;
typedef System::DelphiInterface<ISampleGrabberCB> _di_ISampleGrabberCB;
__interface INTERFACE_UUID("{0579154A-2B53-4994-B0D0-E773148EFF85}") ISampleGrabberCB  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall SampleCB(double SampleTime, _di_IMediaSample pSample) = 0 ;
	virtual HRESULT __stdcall BufferCB(double SampleTime, Windows::PByte pBuffer, int BufferLen) = 0 ;
};

__interface ISampleGrabber;
typedef System::DelphiInterface<ISampleGrabber> _di_ISampleGrabber;
__interface INTERFACE_UUID("{6B652FFF-11FE-4FCE-92AD-0266B5D7C78F}") ISampleGrabber  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall SetOneShot(void) = 0 ;
	virtual HRESULT __stdcall SetMediaType(PIEAM_MEDIA_TYPE pType) = 0 ;
	virtual HRESULT __stdcall GetConnectedMediaType(PIEAM_MEDIA_TYPE pType) = 0 ;
	virtual HRESULT __stdcall SetBufferSamples(BOOL BufferThem) = 0 ;
	virtual HRESULT __stdcall GetCurrentBuffer(Windows::PInteger pBufferSize, void * pBuffer) = 0 ;
	virtual HRESULT __stdcall GetCurrentSample(void) = 0 ;
	virtual HRESULT __stdcall SetCallback(_di_ISampleGrabberCB pCallback, int WhichMethodToCallback) = 0 
		;
};

typedef ISampleGrabber IID_ISampleGrabber;
;

#pragma option push -b-
enum TIETimeFormat { tfNone, tfFrame, tfSample, tfField, tfByte, tfTime };
#pragma option pop

class DELPHICLASS TIESampleGrabberCB;
class PASCALIMPLEMENTATION TIESampleGrabberCB : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	System::TObject* fOwner;
	
public:
	__fastcall TIESampleGrabberCB(System::TObject* Owner);
	__fastcall virtual ~TIESampleGrabberCB(void);
	HRESULT __stdcall SampleCB(double SampleTime, _di_IMediaSample pSample);
	HRESULT __stdcall BufferCB(double SampleTime, Windows::PByte pBuffer, int BufferLen);
private:
	void *__ISampleGrabberCB;	/* Ieds::ISampleGrabberCB */
	
public:
	operator ISampleGrabberCB*(void) { return (ISampleGrabberCB*)&__ISampleGrabberCB; }
	
};


__interface IAMStreamConfig;
typedef System::DelphiInterface<IAMStreamConfig> _di_IAMStreamConfig;
__interface INTERFACE_UUID("{C6E13340-30AC-11D0-A18C-00A0C9118956}") IAMStreamConfig  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall SetFormat(PIEAM_MEDIA_TYPE pmt) = 0 ;
	virtual HRESULT __stdcall GetFormat(PIEAM_MEDIA_TYPE &ppmt) = 0 ;
	virtual HRESULT __stdcall GetNumberOfCapabilities(int &piCount, int &piSize) = 0 ;
	virtual HRESULT __stdcall GetStreamCaps(int iIndex, PIEAM_MEDIA_TYPE &ppmt, void * pSCC) = 0 ;
};

typedef IAMStreamConfig IID_IAMStreamConfig;
;

__interface IAMCrossbar;
typedef System::DelphiInterface<IAMCrossbar> _di_IAMCrossbar;
__interface INTERFACE_UUID("{C6E13380-30AC-11D0-A18C-00A0C9118956}") IAMCrossbar  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall get_PinCounts(int &OutputPinCount, int &InputPinCount) = 0 ;
	virtual HRESULT __stdcall CanRoute(int OutputPinIndex, int InputPinIndex) = 0 ;
	virtual HRESULT __stdcall Route(int OutputPinIndex, int InputPinIndex) = 0 ;
	virtual HRESULT __stdcall get_IsRoutedTo(int OutputPinIndex, int &InputPinIndex) = 0 ;
	virtual HRESULT __stdcall get_CrossbarPinInfo(BOOL IsInputPin, int PinIndex, int &PinIndexRelated, 
		int &PhysicalType) = 0 ;
};

typedef IAMCrossbar IID_IAMCrossBar;
;

__interface IAMTuner;
typedef System::DelphiInterface<IAMTuner> _di_IAMTuner;
__interface INTERFACE_UUID("{211A8761-03AC-11D1-8D13-00AA00BD8339}") IAMTuner  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall put_Channel(int lChannel, int lVideoSubChannel, int lAudioSubChannel) = 0 
		;
	virtual HRESULT __stdcall get_Channel(int &plChannel, int &plVideoSubChannel, int &plAudioSubChannel
		) = 0 ;
	virtual HRESULT __stdcall ChannelMinMax(void) = 0 ;
	virtual HRESULT __stdcall put_CountryCode(void) = 0 ;
	virtual HRESULT __stdcall get_CountryCode(void) = 0 ;
	virtual HRESULT __stdcall put_TuningSpace(int lTuningSpace) = 0 ;
	virtual HRESULT __stdcall get_TuningSpace(void) = 0 ;
	virtual HRESULT __stdcall Logon(void) = 0 ;
	virtual HRESULT __stdcall Logout(void) = 0 ;
	virtual HRESULT __stdcall SignalPresent(int &plSignalStrength) = 0 ;
	virtual HRESULT __stdcall put_Mode(void) = 0 ;
	virtual HRESULT __stdcall get_Mode(void) = 0 ;
	virtual HRESULT __stdcall GetAvailableModes(void) = 0 ;
	virtual HRESULT __stdcall RegisterNotificationCallBack(void) = 0 ;
	virtual HRESULT __stdcall UnRegisterNotificationCallBack(void) = 0 ;
};

typedef IAMTuner IID_IAMTuner;
;

__interface IAMTVTuner;
typedef System::DelphiInterface<IAMTVTuner> _di_IAMTVTuner;
__interface INTERFACE_UUID("{211A8766-03AC-11D1-8D13-00AA00BD8339}") IAMTVTuner  : public IAMTuner 
{
	
public:
	virtual HRESULT __stdcall get_AvailableTVFormats(void) = 0 ;
	virtual HRESULT __stdcall get_TVFormat(void) = 0 ;
	virtual HRESULT __stdcall AutoTune(int lChannel, int &plFoundSignal) = 0 ;
	virtual HRESULT __stdcall StoreAutoTune(void) = 0 ;
	virtual HRESULT __stdcall get_NumInputConnections(void) = 0 ;
	virtual HRESULT __stdcall put_InputType(void) = 0 ;
	virtual HRESULT __stdcall get_InputType(void) = 0 ;
	virtual HRESULT __stdcall put_ConnectInput(void) = 0 ;
	virtual HRESULT __stdcall get_ConnectInput(void) = 0 ;
	virtual HRESULT __stdcall get_VideoFrequency(void) = 0 ;
	virtual HRESULT __stdcall get_AudioFrequency(void) = 0 ;
};

typedef IAMTVTuner IID_IAMTVTuner;
;

__interface IVideoFrameStep;
typedef System::DelphiInterface<IVideoFrameStep> _di_IVideoFrameStep;
__interface INTERFACE_UUID("{E46A9787-2B71-444D-A4B5-1FAB7B708D6A}") IVideoFrameStep  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall Step(unsigned dwFrames, _di_IUnknown pStepObject) = 0 ;
	virtual HRESULT __stdcall CanStep(int bMultiple, _di_IUnknown pStepObject) = 0 ;
	virtual HRESULT __stdcall CancelStep(void) = 0 ;
};

typedef IVideoFrameStep IID_IVideoFrameStep;
;

#pragma option push -b-
enum TIEPropertyPages { iepVideoInput, iepAudioInput, iepVideoCodec, iepAudioCodec, iepVideoInputSource, 
	iepTuner };
#pragma option pop

#pragma option push -b-
enum TIEPropertyPagesType { ietFilter, ietInput, ietOutput };
#pragma option pop

class DELPHICLASS TIEVideoFormat;
class PASCALIMPLEMENTATION TIEVideoFormat : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString Format;
	int BitRate;
	AnsiString VideoStandard;
	int MinWidth;
	int MinHeight;
	int MaxWidth;
	int MaxHeight;
	int GranularityX;
	int GranularityY;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIEVideoFormat(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIEVideoFormat(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIEDirectShow;
class PASCALIMPLEMENTATION TIEDirectShow : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStringList* fAudioInputs;
	Classes::TStringList* fVideoInputs;
	Classes::TStringList* fVideoCodecs;
	Classes::TStringList* fAudioCodecs;
	Classes::TList* fVideoFormats;
	Classes::TStringList* fVideoInputSources;
	_di_IBaseFilter fCurColor;
	_di_IBaseFilter fCurAudioInput;
	_di_IBaseFilter fCurVideoInput;
	_di_IBaseFilter fCurFileInput;
	AnsiString fFileInput;
	_di_IBaseFilter fCurVideoCodec;
	_di_IBaseFilter fCurAudioCodec;
	_di_IAMVideoCompression fIAMVideoCompression;
	AnsiString fFileOutput;
	_di_IGraphBuilder fGraph;
	_di_ICaptureGraphBuilder2 fBuilder;
	_di_IMediaControl fControl;
	_di_IMediaSeeking fMediaSeeking;
	_di_IMediaEventEx fMediaEvent;
	_di_IAMStreamConfig fStreamConfig;
	_di_IBaseFilter fCrossBarFilter;
	_di_IAMCrossbar fCrossBar;
	_di_IAMTVTuner fTuner;
	_di_IBaseFilter fTunerFilter;
	_di_IVideoFrameStep fVideoFrameStep;
	_di_IBaseFilter fSampleGrabber;
	_di_ISampleGrabber fSampleGrabberFilter;
	bool fEnableSampleGrabber;
	TIESampleGrabberCB* fSampleGrabberCB;
	_di_IBaseFilter fNullRenderer;
	unsigned fNotifyWindow;
	int fNewFrameMessage;
	int fEventMessage;
	bool fRenderaudio;
	Classes::TStringList* __fastcall GetAudioInputs(void);
	Classes::TStringList* __fastcall GetVideoInputs(void);
	Classes::TStringList* __fastcall GetVideoCodecs(void);
	Classes::TStringList* __fastcall GetAudioCodecs(void);
	void __fastcall SetPosition(__int64 v);
	__int64 __fastcall GetPosition(void);
	__int64 __fastcall GetDuration(void);
	bool __fastcall GetEndOfStream(void);
	bool __fastcall GetGraphCreated(void);
	void __fastcall SetRate(double value);
	double __fastcall GetRate(void);
	void __fastcall SetXTimeFormat(TIETimeFormat value);
	TIETimeFormat __fastcall GetXTimeFormat(void);
	void __fastcall SetVideoCodecQuality(double value);
	double __fastcall GetVideoCodecQuality(void);
	bool __fastcall ShowFilterPropertyPages(_di_IBaseFilter filter, bool checkOnly);
	bool __fastcall ShowPinPropertyPages(_di_IPin pin, bool checkOnly);
	void __fastcall FillVideoFormats(void);
	void __fastcall ClearVideoFormats(void);
	TIEVideoFormat* __fastcall GetVideoFormats(int i);
	int __fastcall GetVideoFormatsCount(void);
	void __fastcall FillVideoInputSources(void);
	int __fastcall GetInputSource(void);
	void __fastcall SetInputSource(int value);
	void __fastcall SetVideoTunerChannel(int value);
	int __fastcall GetVideoTunerChannel(void);
	
public:
	__fastcall TIEDirectShow(void);
	__fastcall virtual ~TIEDirectShow(void);
	__property Classes::TStringList* AudioInputs = {read=GetAudioInputs};
	__property Classes::TStringList* VideoInputs = {read=GetVideoInputs};
	__property Classes::TStringList* VideoCodecs = {read=GetVideoCodecs};
	__property Classes::TStringList* AudioCodecs = {read=GetAudioCodecs};
	void __fastcall SetVideoInput(int idx, int instanceIndex);
	void __fastcall SetAudioInput(int idx, int instanceIndex);
	void __fastcall SetVideoCodec(int idx);
	void __fastcall SetAudioCodec(int idx);
	__property AnsiString FileInput = {read=fFileInput, write=fFileInput};
	__property AnsiString FileOutput = {read=fFileOutput, write=fFileOutput};
	void __fastcall SaveGraph(AnsiString filename);
	void __fastcall Connect(void);
	void __fastcall Disconnect(void);
	__property bool Connected = {read=GetGraphCreated, nodefault};
	void __fastcall Run(void);
	void __fastcall Stop(void);
	void __fastcall Pause(void);
	__property double Rate = {read=GetRate, write=SetRate};
	TIEDirectShowState __fastcall State(void);
	__property __int64 Position = {read=GetPosition, write=SetPosition};
	__property __int64 Duration = {read=GetDuration};
	__property bool EndOfStream = {read=GetEndOfStream, nodefault};
	__property bool EnableSampleGrabber = {read=fEnableSampleGrabber, write=fEnableSampleGrabber, nodefault
		};
	void __fastcall GetSample(Hyieutils::TIEBitmap* DestBitmap);
	__property TIETimeFormat TimeFormat = {read=GetXTimeFormat, write=SetXTimeFormat, nodefault};
	void __fastcall BufferToTIEBitmap(Windows::PByte buffer, int len, Hyieutils::TIEBitmap* DestBitmap)
		;
	void __fastcall SetNotifyWindow(unsigned WindowHandle, int NewFrameMessage, int EventMessage);
	bool __fastcall GetEventCode(int &Event);
	__property double VideoCodecQuality = {read=GetVideoCodecQuality, write=SetVideoCodecQuality};
	bool __fastcall ShowPropertyPages(TIEPropertyPages proppages, TIEPropertyPagesType proptype, bool checkOnly
		);
	void __fastcall SetCurrentVideoFormat(int width, int height, AnsiString format);
	void __fastcall GetCurrentVideoFormat(int &width, int &height, AnsiString &format);
	__property TIEVideoFormat* VideoFormats[int i] = {read=GetVideoFormats};
	__property int VideoFormatsCount = {read=GetVideoFormatsCount, nodefault};
	__property Classes::TStringList* VideoInputSources = {read=fVideoInputSources};
	__property int VideoInputSource = {read=GetInputSource, write=SetInputSource, nodefault};
	__property int TunerChannel = {read=GetVideoTunerChannel, write=SetVideoTunerChannel, nodefault};
	bool __fastcall TunerFindSignal(void);
	__property bool RenderAudio = {read=fRenderaudio, write=fRenderaudio, nodefault};
	bool __fastcall Step(int frames);
	__int64 __fastcall ConvertTimeFormat(__int64 source, TIETimeFormat sourceFormat, TIETimeFormat targetFormat
		);
	__int64 __fastcall GetAverageTimePerFrame(void);
	__property unsigned NotifyWindow = {read=fNotifyWindow, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint IEEC_COMPLETE = 0x1;
static const Shortint IEEC_USERABORT = 0x2;
static const Shortint IEEC_ERRORABORT = 0x3;
static const Shortint IEEC_TIME = 0x4;
static const Shortint IEEC_REPAINT = 0x5;
static const Shortint IEEC_STREAM_ERROR_STOPPED = 0x6;
static const Shortint IEEC_STREAM_ERROR_STILLPLAYING = 0x7;
static const Shortint IEEC_ERROR_STILLPLAYING = 0x8;
static const Shortint IEEC_PALETTE_CHANGED = 0x9;
static const Shortint IEEC_VIDEO_SIZE_CHANGED = 0xa;
static const Shortint IEEC_QUALITY_CHANGE = 0xb;
static const Shortint IEEC_SHUTTING_DOWN = 0xc;
static const Shortint IEEC_CLOCK_CHANGED = 0xd;
static const Shortint IEEC_PAUSED = 0xe;
static const Shortint IEEC_OPENING_FILE = 0x10;
static const Shortint IEEC_BUFFERING_DATA = 0x11;
static const Shortint IEEC_FULLSCREEN_LOST = 0x12;
static const Shortint IEEC_ACTIVATE = 0x13;
static const Shortint IEEC_NEED_RESTART = 0x14;
static const Shortint IEEC_WINDOW_DESTROYED = 0x15;
static const Shortint IEEC_DISPLAY_CHANGED = 0x16;
static const Shortint IEEC_STARVATION = 0x17;
static const Shortint IEEC_OLE_EVENT = 0x18;
static const Shortint IEEC_NOTIFY_WINDOW = 0x19;
static const Shortint IEEC_STREAM_CONTROL_STOPPED = 0x1a;
static const Shortint IEEC_STREAM_CONTROL_STARTED = 0x1b;
static const Shortint IEEC_END_OF_SEGMENT = 0x1c;
static const Shortint IEEC_SEGMENT_STARTED = 0x1d;
static const Shortint IEEC_LENGTH_CHANGED = 0x1e;
static const Shortint IEEC_DEVICE_LOST = 0x1f;
static const Shortint IEEC_STEP_COMPLETE = 0x24;
static const Shortint IEEC_SKIP_FRAMES = 0x25;
static const Shortint IEEC_TIMECODE_AVAILABLE = 0x30;
static const Shortint IEEC_EXTDEVICE_MODE_CHANGE = 0x31;
static const Shortint IEEC_GRAPH_CHANGED = 0x50;
static const Shortint IEEC_CLOCK_UNSET = 0x51;
static const Byte IEMAX_FILTER_NAME = 0x80;

}	/* namespace Ieds */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ieds;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ieds
