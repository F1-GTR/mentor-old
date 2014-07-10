// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'iezlib.pas' rev: 5.00

#ifndef iezlibHPP
#define iezlibHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iezlib
{
//-- type declarations -------------------------------------------------------
typedef void * __fastcall (*TZAlloc)(void * opaque, int items, int size);

typedef void __fastcall (*TZFree)(void * opaque, void * block);

#pragma option push -b-
enum TZCompressionLevel { zcNone, zcFastest, zcDefault, zcMax };
#pragma option pop

#pragma pack(push, 1)
struct TZStreamRec
{
	char *next_in;
	int avail_in;
	int total_in;
	char *next_out;
	int avail_out;
	int total_out;
	char *msg;
	void *state;
	TZAlloc zalloc;
	TZFree zfree;
	void *opaque;
	int data_type;
	int adler;
	int reserved;
} ;
#pragma pack(pop)

class DELPHICLASS TCustomZStream;
class PASCALIMPLEMENTATION TCustomZStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	Classes::TStream* FStream;
	__int64 FStreamPos;
	Classes::TNotifyEvent FOnProgress;
	#pragma pack(push, 1)
	TZStreamRec FZStream;
	#pragma pack(pop)
	
	char FBuffer[65536];
	
protected:
	__fastcall TCustomZStream(Classes::TStream* stream);
	DYNAMIC void __fastcall DoProgress(void);
	__property Classes::TNotifyEvent OnProgress = {read=FOnProgress, write=FOnProgress};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCustomZStream(void) { }
	#pragma option pop
	
};


class DELPHICLASS TZCompressionStream;
class PASCALIMPLEMENTATION TZCompressionStream : public TCustomZStream 
{
	typedef TCustomZStream inherited;
	
private:
	float __fastcall GetCompressionRate(void);
	
public:
	__fastcall TZCompressionStream(Classes::TStream* dest, TZCompressionLevel compressionLevel);
	__fastcall virtual ~TZCompressionStream(void);
	virtual int __fastcall Read(void *buffer, int count);
	virtual int __fastcall Write(const void *buffer, int count);
	virtual int __fastcall Seek(int offset, Word origin);
	__property float CompressionRate = {read=GetCompressionRate};
	__property OnProgress ;
};


class DELPHICLASS TZDecompressionStream;
class PASCALIMPLEMENTATION TZDecompressionStream : public TCustomZStream 
{
	typedef TCustomZStream inherited;
	
public:
	__fastcall TZDecompressionStream(Classes::TStream* source);
	__fastcall virtual ~TZDecompressionStream(void);
	virtual int __fastcall Read(void *buffer, int count);
	virtual int __fastcall Write(const void *buffer, int count);
	virtual int __fastcall Seek(int offset, Word origin);
	__property OnProgress ;
};


class DELPHICLASS EZLibError;
class PASCALIMPLEMENTATION EZLibError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EZLibError(const AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EZLibError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EZLibError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EZLibError(int Ident, const System::TVarRec * Args, 
		const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EZLibError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(
		Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EZLibError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EZLibError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EZLibError(System::PResStringRec ResStringRec, const 
		System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EZLibError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EZCompressionError;
class PASCALIMPLEMENTATION EZCompressionError : public EZLibError 
{
	typedef EZLibError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EZCompressionError(const AnsiString Msg) : EZLibError(Msg)
		 { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EZCompressionError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : EZLibError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EZCompressionError(int Ident)/* overload */ : EZLibError(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EZCompressionError(int Ident, const System::TVarRec 
		* Args, const int Args_Size)/* overload */ : EZLibError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EZCompressionError(const AnsiString Msg, int AHelpContext
		) : EZLibError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EZCompressionError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : EZLibError(Msg, Args, Args_Size, AHelpContext) { }
		
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EZCompressionError(int Ident, int AHelpContext)/* overload */
		 : EZLibError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EZCompressionError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EZLibError(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EZCompressionError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EZDecompressionError;
class PASCALIMPLEMENTATION EZDecompressionError : public EZLibError 
{
	typedef EZLibError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EZDecompressionError(const AnsiString Msg) : EZLibError(Msg
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EZDecompressionError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : EZLibError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EZDecompressionError(int Ident)/* overload */ : EZLibError(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EZDecompressionError(int Ident, const System::TVarRec 
		* Args, const int Args_Size)/* overload */ : EZLibError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EZDecompressionError(const AnsiString Msg, int AHelpContext
		) : EZLibError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EZDecompressionError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : EZLibError(Msg, Args, Args_Size, AHelpContext) { }
		
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EZDecompressionError(int Ident, int AHelpContext)/* overload */
		 : EZLibError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EZDecompressionError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EZLibError(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EZDecompressionError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define ZLIB_VERSION "1.1.4"
extern PACKAGE void __cdecl _memset(void * P, Byte B, int count);
extern PACKAGE int __cdecl _memcmp(Windows::PByte buf1, Windows::PByte buf2, int count);
extern PACKAGE double __cdecl _strtod(char * s, char * &vp);
extern PACKAGE void __cdecl _abort(void);
extern PACKAGE void __cdecl _memcpy(void * dest, void * source, int count);
extern PACKAGE void * __cdecl _malloc(int size);
extern PACKAGE void __cdecl _free(void * P);
extern PACKAGE double __cdecl _fabs(double v);
extern PACKAGE double __cdecl _pow(double Base, double Exponent);
extern PACKAGE int __cdecl __ftol(void);
extern PACKAGE unsigned __cdecl _strlen(char * s);
extern PACKAGE void __fastcall ZCompress(const void * inBuffer, int inSize, /* out */ void * &outBuffer
	, /* out */ int &outSize, TZCompressionLevel level);
extern PACKAGE void __fastcall ZDecompress(const void * inBuffer, int inSize, /* out */ void * &outBuffer
	, /* out */ int &outSize, int outEstimate);
extern PACKAGE AnsiString __fastcall ZCompressStr(const AnsiString s, TZCompressionLevel level);
extern PACKAGE AnsiString __fastcall ZDecompressStr(const AnsiString s);
extern PACKAGE void __fastcall ZCompressStream(Classes::TStream* inStream, Classes::TStream* outStream
	, TZCompressionLevel level);
extern PACKAGE void __fastcall ZDecompressStream(Classes::TStream* inStream, Classes::TStream* outStream
	);
extern PACKAGE int __fastcall deflateInit_(TZStreamRec &strm, int level, char * version, int recsize
	);
extern PACKAGE void __fastcall deflateInit2_(void);
extern PACKAGE void __fastcall deflateReset(void);
extern PACKAGE int __fastcall deflate(TZStreamRec &strm, int flush);
extern PACKAGE int __fastcall deflateEnd(TZStreamRec &strm);
extern PACKAGE int __fastcall inflateReset(TZStreamRec &strm);
extern PACKAGE int __fastcall inflateEnd(TZStreamRec &strm);
extern PACKAGE int __fastcall inflateInit_(TZStreamRec &strm, char * version, int recsize);
extern PACKAGE int __fastcall inflate(TZStreamRec &strm, int flush);
extern PACKAGE void __fastcall crc32(void);

}	/* namespace Iezlib */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Iezlib;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// iezlib
