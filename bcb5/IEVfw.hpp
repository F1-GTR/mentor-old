// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ievfw.pas' rev: 5.00

#ifndef ievfwHPP
#define ievfwHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ievfw
{
//-- type declarations -------------------------------------------------------
typedef GUID *PCLSID;

typedef GUID  TIID;

class DELPHICLASS IUnknown;
class PASCALIMPLEMENTATION IUnknown : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual HRESULT __stdcall QueryInterface(const GUID &iid, void *obj) = 0 ;
	virtual int __stdcall AddRef(void) = 0 ;
	virtual int __stdcall Release(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IUnknown(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IUnknown(void) { }
	#pragma option pop
	
};


typedef int LONG;

typedef void *PVOID;

struct TAviStreamInfoA;
typedef TAviStreamInfoA *PAviStreamInfoA;

struct TAviStreamInfoA
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

typedef TAviStreamInfoA  TAviStreamInfo;

struct TAviStreamInfoW;
typedef TAviStreamInfoW *PAviStreamInfoW;

struct TAviStreamInfoW
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
	wchar_t szName[64];
} ;

struct TAviFileInfoA;
typedef TAviFileInfoA *PAviFileInfoA;

struct TAviFileInfoA
{
	unsigned dwMaxBytesPerSec;
	unsigned dwFlags;
	unsigned dwCaps;
	unsigned dwStreams;
	unsigned dwSuggestedBufferSize;
	unsigned dwWidth;
	unsigned dwHeight;
	unsigned dwScale;
	unsigned dwRate;
	unsigned dwLength;
	unsigned dwEditCount;
	char szFileType[64];
} ;

typedef TAviFileInfoA  TAviFileInfo;

struct TAviFileInfoW;
typedef TAviFileInfoW *PAviFileInfoW;

struct TAviFileInfoW
{
	unsigned dwMaxBytesPerSec;
	unsigned dwFlags;
	unsigned dwCaps;
	unsigned dwStreams;
	unsigned dwSuggestedBufferSize;
	unsigned dwWidth;
	unsigned dwHeight;
	unsigned dwScale;
	unsigned dwRate;
	unsigned dwLength;
	unsigned dwEditCount;
	wchar_t szFileType[64];
} ;

typedef bool __stdcall (*TAVISaveCallBack)(int Percentage);

typedef TAVISaveCallBack *AVISaveCallBack;

struct TAviCompressOptions;
typedef TAviCompressOptions *PAviCompressOptions;

struct TAviCompressOptions
{
	unsigned fccType;
	unsigned fccHandler;
	unsigned dwKeyFrameEvery;
	unsigned dwQuality;
	unsigned dwBytesPerSecond;
	unsigned dwFlags;
	void *lpFormat;
	unsigned cbFormat;
	void *lpParms;
	unsigned cbParms;
	unsigned dwInterleaveEvery;
} ;

class DELPHICLASS IAVIStream;
class PASCALIMPLEMENTATION IAVIStream : public IUnknown 
{
	typedef IUnknown inherited;
	
public:
	HIDESBASE virtual HRESULT __stdcall Create(int lParam1, int lParam2) = 0 ;
	virtual HRESULT __stdcall Info(TAviStreamInfoW &psi, int lSize) = 0 ;
	virtual int __stdcall FindSample(int lPos, int lFlags) = 0 ;
	virtual HRESULT __stdcall ReadFormat(int lPos, void * lpFormat, int &lpcbFormat) = 0 ;
	virtual HRESULT __stdcall SetFormat(int lPos, void * lpFormat, int lpcbFormat) = 0 ;
	virtual HRESULT __stdcall Read(int lStart, int lSamples, void * lpBuffer, int cbBuffer, int &plBytes
		, int &plSamples) = 0 ;
	virtual HRESULT __stdcall Write(int lStart, int lSamples, void * lpBuffer, int cbBuffer, unsigned dwFlags
		, int &plSampWritten, int &plBytesWritten) = 0 ;
	virtual HRESULT __stdcall Delete(int lStart, int lSamples) = 0 ;
	virtual HRESULT __stdcall ReadData(unsigned fcc, void * lp, int &lpcb) = 0 ;
	virtual HRESULT __stdcall WriteData(unsigned fcc, void * lp, int cb) = 0 ;
	virtual HRESULT __stdcall SetInfo(TAviStreamInfoW &lpInfo, int cbInfo) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IAVIStream(void) : IUnknown() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IAVIStream(void) { }
	#pragma option pop
	
};


typedef IAVIStream* *PAVIStream;

class DELPHICLASS IAVIEditStream;
class PASCALIMPLEMENTATION IAVIEditStream : public IUnknown 
{
	typedef IUnknown inherited;
	
public:
	virtual HRESULT __stdcall Info(TAviFileInfoW &pfi, int lSize) = 0 ;
	virtual HRESULT __stdcall Cut(int &plStart, int &plLength, PAVIStream &ppResult) = 0 ;
	virtual HRESULT __stdcall Copy(int &plLength, PAVIStream &ppResult) = 0 ;
	virtual HRESULT __stdcall Paste(int &plLength, PAVIStream pstream, int lStart, int lEnd) = 0 ;
	virtual HRESULT __stdcall Clone(PAVIStream &ppResult) = 0 ;
	virtual HRESULT __stdcall SetInfo(TAviStreamInfoW &lpInfo, int cbInfo) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IAVIEditStream(void) : IUnknown() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IAVIEditStream(void) { }
	#pragma option pop
	
};


typedef IAVIEditStream* *PAVIEditStream;

class DELPHICLASS IAVIFile;
class PASCALIMPLEMENTATION IAVIFile : public IUnknown 
{
	typedef IUnknown inherited;
	
public:
	virtual HRESULT __stdcall Open(char * szFile, unsigned mode) = 0 ;
	virtual HRESULT __stdcall Info(TAviFileInfoA &pfi, int lSize) = 0 ;
	virtual HRESULT __stdcall GetStream(PAVIStream &ppStream, unsigned fccType, int lParam) = 0 ;
	virtual HRESULT __stdcall CreateStream(PAVIStream &ppStream, const TAviStreamInfoA psi) = 0 ;
	virtual HRESULT __stdcall Save(char * szFile, TAviCompressOptions &lpOptions, AVISaveCallBack lpfnCallback
		) = 0 ;
	virtual HRESULT __stdcall WriteData(unsigned ckid, void * lpData, int cbData) = 0 ;
	virtual HRESULT __stdcall ReadData(unsigned ckid, void * lpData, int &lpcbData) = 0 ;
	virtual HRESULT __stdcall EndRecord(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IAVIFile(void) : IUnknown() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IAVIFile(void) { }
	#pragma option pop
	
};


typedef IAVIFile* *PAVIFile;

class DELPHICLASS IGetFrame;
class PASCALIMPLEMENTATION IGetFrame : public IUnknown 
{
	typedef IUnknown inherited;
	
public:
	virtual void * __stdcall GetFrame(int lPos) = 0 ;
	virtual HRESULT __stdcall SetFormat(Windows::PBitmapInfoHeader lpbi, void * lpBits, int x, int y, int 
		dx, int dy) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IGetFrame(void) : IUnknown() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IGetFrame(void) { }
	#pragma option pop
	
};


typedef IGetFrame* *PGetFrame;

//-- var, const, procedure ---------------------------------------------------
static const int streamtypeVIDEO = 0x73646976;
static const int streamtypeAUDIO = 0x73647561;
static const int streamtypeMIDI = 0x7364696d;
static const int streamtypeTEXT = 0x73747874;
static const int comptypeDIB = 0x20424944;
static const Shortint AVIIF_KEYFRAME = 0x10;
static const Shortint AVISTREAMINFO_DISABLED = 0x1;
static const int AVISTREAMINFO_FORMATCHANGES = 0x10000;
static const Shortint AVIFILEINFO_HASINDEX = 0x10;
static const Shortint AVIFILEINFO_MUSTUSEINDEX = 0x20;
static const Word AVIFILEINFO_ISINTERLEAVED = 0x100;
static const int AVIFILEINFO_WASCAPTUREFILE = 0x10000;
static const int AVIFILEINFO_COPYRIGHTED = 0x20000;
static const Shortint AVIFILECAPS_CANREAD = 0x1;
static const Shortint AVIFILECAPS_CANWRITE = 0x2;
static const Shortint AVIFILECAPS_ALLKEYFRAMES = 0x10;
static const Shortint AVIFILECAPS_NOCOMPRESSION = 0x20;
static const Shortint ICMF_CHOOSE_KEYFRAME = 0x1;
static const Shortint ICMF_CHOOSE_DATARATE = 0x2;
static const Shortint ICMF_CHOOSE_PREVIEW = 0x4;
static const Shortint ICMF_CHOOSE_ALLCOMPRESSORS = 0x8;
static const Shortint AVICOMPRESSF_INTERLEAVE = 0x1;
static const Shortint AVICOMPRESSF_DATARATE = 0x2;
static const Shortint AVICOMPRESSF_KEYFRAMES = 0x4;
static const Shortint AVICOMPRESSF_VALID = 0x8;
extern PACKAGE GUID IID_IAVIFile;
extern PACKAGE GUID IID_IAVIStream;
extern PACKAGE GUID IID_IAVIStreaming;
extern PACKAGE GUID IID_IGetFrame;
extern PACKAGE GUID IID_IAVIEditStream;
extern PACKAGE GUID CLSID_AVISimpleUnMarshal;
extern PACKAGE GUID CLSID_AVIFile;
static const Shortint AVIFILEHANDLER_CANREAD = 0x1;
static const Shortint AVIFILEHANDLER_CANWRITE = 0x2;
static const Shortint AVIFILEHANDLER_CANACCEPTNONRGB = 0x4;
static const Shortint FIND_DIR = 0xf;
static const Shortint FIND_NEXT = 0x1;
static const Shortint FIND_PREV = 0x4;
static const Byte FIND_TYPE = 0xf0;
static const Shortint FIND_KEY = 0x10;
static const Shortint FIND_ANY = 0x20;
static const Shortint FIND_FORMAT = 0x40;
static const Word FIND_RET = 0xf000;
static const Shortint FIND_POS = 0x0;
static const Word FIND_LENGTH = 0x1000;
static const Word FIND_OFFSET = 0x2000;
static const Word FIND_SIZE = 0x3000;
static const Word FIND_INDEX = 0x4000;
static const Shortint AVIERR_OK = 0x0;
static const Shortint AVIIF_LIST = 0x1;
static const Shortint AVIIF_TWOCC = 0x2;
extern "C" void __stdcall AVIFileInit(void);
extern "C" void __stdcall AVIFileExit(void);
extern "C" unsigned __stdcall AVIFileAddRef(PAVIFile pfile);
extern "C" unsigned __stdcall AVIFileRelease(PAVIFile pfile);
extern "C" HRESULT __stdcall AVIFileOpen(PAVIFile &ppfile, char * szFile, unsigned uMode, System::PGUID 
	lpHandler);
extern "C" HRESULT __stdcall AVIFileInfo(PAVIFile pfile, TAviFileInfoA &pfi, int lSize);
extern "C" HRESULT __stdcall AVIFileGetStream(PAVIFile pfile, PAVIStream &ppavi, unsigned fccType, int 
	lParam);
extern "C" HRESULT __stdcall AVIFileCreateStream(PAVIFile pfile, PAVIStream &ppavi, TAviStreamInfoA 
	&psi);
extern "C" HRESULT __stdcall AVIFileWriteData(PAVIFile pfile, unsigned ckid, void * lpData, int cbData
	);
extern "C" HRESULT __stdcall AVIFileReadData(unsigned ckid, void * lpData, int &lpcbData);
extern "C" HRESULT __stdcall AVIFileEndRecord(PAVIFile pfile);
extern "C" unsigned __stdcall AVIStreamAddRef(PAVIStream pavi);
extern "C" unsigned __stdcall AVIStreamRelease(PAVIStream pavi);
extern "C" HRESULT __stdcall AVIStreamInfo(PAVIStream pavi, TAviStreamInfoA &psi, int lSize);
extern "C" int __stdcall AVIStreamFindSample(PAVIStream pavi, int lPos, int lFlags);
extern "C" HRESULT __stdcall AVIStreamReadFormat(PAVIStream pavi, int lPos, void * lpFormat, int &lpcbFormat
	);
extern "C" HRESULT __stdcall AVIStreamSetFormat(PAVIStream pavi, int lPos, void * lpFormat, int cbFormat
	);
extern "C" HRESULT __stdcall AVIStreamReadData(PAVIStream pavi, unsigned fcc, void * lp, int &lpcb);
	
extern "C" HRESULT __stdcall AVIStreamWriteData(PAVIStream pavi, unsigned fcc, void * lp, int cb);
extern "C" HRESULT __stdcall AVIStreamRead(PAVIStream pavi, int lStart, int lSamples, void * lpBuffer
	, int cbBuffer, int &plBytes, int &plSamples);
extern "C" HRESULT __stdcall AVIStreamWrite(PAVIStream pavi, int lStart, int lSamples, void * lpBuffer
	, int cbBuffer, unsigned dwFlags, void * plSampWritten, void * plBytesWritten);
extern "C" int __stdcall AVIStreamStart(PAVIStream pavi);
extern "C" int __stdcall AVIStreamLength(PAVIStream pavi);
extern "C" int __stdcall AVIStreamTimeToSample(PAVIStream pavi, int lTime);
extern "C" int __stdcall AVIStreamSampleToTime(PAVIStream pavi, int lSample);
extern "C" int __stdcall AVIStreamBeginStreaming(PAVIStream pavi, int lStart, int lEnd, int lRate);
extern "C" int __stdcall AVIStreamEndStreaming(PAVIStream pavi);
extern "C" PGetFrame __stdcall AVIStreamGetFrameOpen(PAVIStream pavi, Windows::PBitmapInfoHeader lpbiWanted
	);
extern "C" void * __stdcall AVIStreamGetFrame(PGetFrame pg, int lPos);
extern "C" HRESULT __stdcall AVIStreamGetFrameClose(PGetFrame pg);
extern "C" HRESULT __stdcall AVIStreamOpenFromFile(PAVIStream &ppavi, char * szFile, unsigned fccType
	, int lParam, unsigned mode, System::PGUID pclsidHandler);
extern "C" HRESULT __stdcall AVIStreamCreate(PAVIStream &ppavi, int lParam1, int lParam2, System::PGUID 
	pclsidHandler);
extern "C" HRESULT __stdcall AVISaveV(char * szFile, System::PGUID pclsidHandler, AVISaveCallBack lpfnCallback
	, int nStreams, PAVIStream &ppavi, PAviCompressOptions &plpOptions);
extern "C" bool __stdcall AVISaveOptions(HWND hwnd, unsigned uiFlags, int nStreams, void * pavi, void * 
	plpOptions);
extern "C" bool __stdcall AVISaveOptionsFree(int nStreams, PAviCompressOptions &plpOptions);
extern "C" HRESULT __stdcall CreateEditableStream(PAVIStream &ppsEditable, PAVIStream psSource);
extern "C" HRESULT __stdcall EditStreamSetInfo(PAVIStream pavi, PAviStreamInfoA lpinfo, int cbinfo);
	
extern "C" HRESULT __stdcall AVIMakeCompressedStream(PAVIStream &ppsCompressed, PAVIStream psSource, 
	PAviCompressOptions lpOptions, System::PGUID pclsid);
extern PACKAGE int __fastcall mmioFOURCC(AnsiString cc);
#pragma option push -w-inl
inline HRESULT __stdcall AVIFileOpen(PAVIFile &ppfile, char * szFile, unsigned uMode, System::PGUID 
	lpHandler)
{
	return AVIFileOpenA(ppfile, szFile, uMode, lpHandler);
}
#pragma option pop


#pragma option push -w-inl
inline HRESULT __stdcall AVIFileCreateStream(PAVIFile pfile, PAVIStream &ppavi, TAviStreamInfoA &psi
	)
{
	return AVIFileCreateStreamA(pfile, ppavi, psi);
}
#pragma option pop



}	/* namespace Ievfw */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ievfw;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ievfw
