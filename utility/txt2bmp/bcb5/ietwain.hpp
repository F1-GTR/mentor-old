// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ietwain.pas' rev: 5.00

#ifndef ietwainHPP
#define ietwainHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ietwain
{
//-- type declarations -------------------------------------------------------
typedef unsigned TW_HANDLE;

typedef unsigned TTWHandle;

typedef void *TW_MEMREF;

typedef void *TTWMemRef;

typedef char TW_STR32[34];

typedef char *pTW_STR32;

typedef char TTWStr32[34];

typedef char *PTWStr32;

typedef char TW_STR64[66];

typedef char *pTW_STR64;

typedef char TTWStr64[66];

typedef char *PTWStr64;

typedef char TW_STR128[130];

typedef char *pTW_STR128;

typedef char TTWStr128[130];

typedef char *PTWStr128;

typedef char TW_STR255[256];

typedef char *pTW_STR255;

typedef char TTWStr255[256];

typedef char *PTWStr255;

typedef char TW_STR1024[1026];

typedef char *pTW_STR1024;

typedef char TTWStr1024[1026];

typedef char *PTWStr1024;

typedef wchar_t TW_UNI512[512];

typedef wchar_t *pTW_UNI512;

typedef wchar_t TTWUni512[512];

typedef wchar_t *PTWUni512;

typedef Shortint TW_INT8;

typedef Shortint *pTW_INT8;

typedef Shortint TTWInt8;

typedef Shortint *PTWInt8;

typedef short TW_INT16;

typedef short *pTW_INT16;

typedef short TTWInt16;

typedef short *PTWInt16;

typedef int TW_INT32;

typedef int *pTW_INT32;

typedef int TTWInt32;

typedef int *PTWInt32;

typedef Byte TW_UINT8;

typedef Byte *pTW_UINT8;

typedef Byte TTWUInt8;

typedef Byte *PTWUInt8;

typedef Word TW_UINT16;

typedef Word *pTW_UINT16;

typedef Word TTWUInt16;

typedef Word *PTWUInt16;

typedef unsigned TW_UINT32;

typedef unsigned *pTW_UINT32;

typedef unsigned TTWUInt32;

typedef unsigned *PTWUInt32;

typedef Word TW_BOOL;

typedef Word *pTW_BOOL;

typedef Word TTWBool;

typedef Word *PTWBool;

#pragma pack(push, 1)
struct TW_FIX32
{
	short Whole;
	Word Frac;
} ;
#pragma pack(pop)

typedef TW_FIX32 *pTW_FIX32;

typedef TW_FIX32  TTWFix32;

typedef TW_FIX32 *PTWFix32;

#pragma pack(push, 1)
struct TW_CIEPOINT
{
	TW_FIX32 X;
	TW_FIX32 Y;
	TW_FIX32 Z;
} ;
#pragma pack(pop)

typedef TW_CIEPOINT *pTW_CIEPOINT;

typedef TW_CIEPOINT  TTWCiePoint;

typedef TW_CIEPOINT *PTWCiePoint;

#pragma pack(push, 1)
struct TW_DECODEFUNCTION
{
	TW_FIX32 StartIn;
	TW_FIX32 BreakIn;
	TW_FIX32 EndIn;
	TW_FIX32 StartOut;
	TW_FIX32 BreakOut;
	TW_FIX32 EndOut;
	TW_FIX32 Gamma;
	TW_FIX32 SampleCount;
} ;
#pragma pack(pop)

typedef TW_DECODEFUNCTION *pTW_DECODEFUNCTION;

typedef TW_DECODEFUNCTION  TTWDecodeFunction;

typedef TW_DECODEFUNCTION *PTWDecodeFunction;

#pragma pack(push, 1)
struct TW_ELEMENT8
{
	Byte Index;
	Byte Channel1;
	Byte Channel2;
	Byte Channel3;
} ;
#pragma pack(pop)

typedef TW_ELEMENT8 *pTW_ELEMENT8;

typedef TW_ELEMENT8  TTWElement8;

typedef TW_ELEMENT8 *PTWElement8;

#pragma pack(push, 1)
struct TW_FRAME
{
	TW_FIX32 Left;
	TW_FIX32 Top;
	TW_FIX32 Right;
	TW_FIX32 Bottom;
} ;
#pragma pack(pop)

typedef TW_FRAME *pTW_FRAME;

typedef TW_FRAME *PTWFrame;

typedef TW_FRAME  TTWFrame;

#pragma pack(push, 1)
struct TW_MEMORY
{
	unsigned Flags;
	unsigned Length;
	void *TheMem;
} ;
#pragma pack(pop)

typedef TW_MEMORY *pTW_MEMORY;

typedef TW_MEMORY  TTWMemory;

typedef TW_MEMORY *PTWMemory;

#pragma pack(push, 1)
struct TW_TRANSFORMSTAGE
{
	TW_DECODEFUNCTION Decode[3];
	TW_FIX32 Mix[3][3];
} ;
#pragma pack(pop)

typedef TW_TRANSFORMSTAGE *pTW_TRANSFORMSTAGE;

typedef TW_TRANSFORMSTAGE  TTWTransformStage;

typedef TW_TRANSFORMSTAGE *PTWTransformStage;

#pragma pack(push, 1)
struct TW_VERSION
{
	Word MajorNum;
	Word MinorNum;
	Word Language;
	Word Country;
	char Info[34];
} ;
#pragma pack(pop)

typedef TW_VERSION *pTW_VERSION;

typedef TW_VERSION *PTWVersion;

typedef TW_VERSION  TTWVersion;

#pragma pack(push, 1)
struct TW_ARRAY
{
	Word ItemType;
	unsigned NumItems;
	Byte ItemList[2];
} ;
#pragma pack(pop)

typedef TW_ARRAY *pTW_ARRAY;

typedef TW_ARRAY  TTWArray;

typedef TW_ARRAY *PTWArray;

#pragma pack(push, 1)
struct TW_ENUMERATION
{
	Word ItemType;
	unsigned NumItems;
	unsigned CurrentIndex;
	unsigned DefaultIndex;
	Byte ItemList[2];
} ;
#pragma pack(pop)

typedef TW_ENUMERATION *pTW_ENUMERATION;

typedef TW_ENUMERATION  TTWEnumeration;

typedef TW_ENUMERATION *PTWEnumeration;

#pragma pack(push, 1)
struct TW_ONEVALUE
{
	Word ItemType;
	unsigned Item;
} ;
#pragma pack(pop)

typedef TW_ONEVALUE *pTW_ONEVALUE;

typedef TW_ONEVALUE  TTWOneValue;

typedef TW_ONEVALUE *PTWOneValue;

#pragma pack(push, 1)
struct TW_RANGE
{
	Word ItemType;
	unsigned MinValue;
	unsigned MaxValue;
	unsigned StepSize;
	unsigned DefaultValue;
	unsigned CurrentValue;
} ;
#pragma pack(pop)

typedef TW_RANGE *pTW_RANGE;

typedef TW_RANGE  TTWRange;

typedef TW_RANGE *PTWRange;

#pragma pack(push, 1)
struct TW_CAPABILITY
{
	Word Cap;
	Word ConType;
	unsigned hContainer;
} ;
#pragma pack(pop)

typedef TW_CAPABILITY *pTW_CAPABILITY;

typedef TW_CAPABILITY  TTWCapability;

typedef TW_CAPABILITY *PTWCapability;

#pragma pack(push, 1)
struct TW_CIECOLOR
{
	Word ColorSpace;
	short LowEndian;
	short DeviceDependent;
	int VersionNumber;
	TW_TRANSFORMSTAGE StageABC;
	TW_TRANSFORMSTAGE StageLMN;
	TW_CIEPOINT WhitePoint;
	TW_CIEPOINT BlackPoint;
	TW_CIEPOINT WhitePaper;
	TW_CIEPOINT BlackInk;
	TW_FIX32 Samples[1];
} ;
#pragma pack(pop)

typedef TW_CIECOLOR *pTW_CIECOLOR;

typedef TW_CIECOLOR  TTWCieColor;

typedef TW_CIECOLOR *PTWCieColor;

#pragma pack(push, 1)
struct TW_EVENT
{
	void *pEvent;
	Word TWMessage;
} ;
#pragma pack(pop)

typedef TW_EVENT *pTW_EVENT;

typedef TW_EVENT  TTWEvent;

typedef TW_EVENT *PTWEvent;

#pragma pack(push, 1)
struct TW_GRAYRESPONSE
{
	TW_ELEMENT8 Response[1];
} ;
#pragma pack(pop)

typedef TW_GRAYRESPONSE *pTW_GRAYRESPONSE;

typedef TW_GRAYRESPONSE  TTWGrayResponse;

typedef TW_GRAYRESPONSE *PTWGrayResponse;

#pragma pack(push, 1)
struct TW_IDENTITY
{
	unsigned Id;
	TW_VERSION Version;
	Word ProtocolMajor;
	Word ProtocolMinor;
	unsigned SupportedGroups;
	char Manufacturer[34];
	char ProductFamily[34];
	char ProductName[34];
} ;
#pragma pack(pop)

typedef TW_IDENTITY *pTW_IDENTITY;

typedef TW_IDENTITY  TTWIdentity;

typedef TW_IDENTITY *PTWIdentity;

#pragma pack(push, 1)
struct TW_IMAGEINFO
{
	TW_FIX32 XResolution;
	TW_FIX32 YResolution;
	int ImageWidth;
	int ImageLength;
	short SamplesPerPixel;
	short BitsPerSample[8];
	short BitsPerPixel;
	Word Planar;
	short PixelType;
	Word Compression;
} ;
#pragma pack(pop)

typedef TW_IMAGEINFO *pTW_IMAGEINFO;

typedef TW_IMAGEINFO  TTWImageInfo;

typedef TW_IMAGEINFO *PTWImageInfo;

#pragma pack(push, 1)
struct TW_IMAGELAYOUT
{
	TW_FRAME Frame;
	unsigned DocumentNumber;
	unsigned PageNumber;
	unsigned FrameNumber;
} ;
#pragma pack(pop)

typedef TW_IMAGELAYOUT *pTW_IMAGELAYOUT;

typedef TW_IMAGELAYOUT  TTWImageLayout;

typedef TW_IMAGELAYOUT *PTWImageLayout;

#pragma pack(push, 1)
struct TW_IMAGEMEMXFER
{
	Word Compression;
	unsigned BytesPerRow;
	unsigned Columns;
	unsigned Rows;
	unsigned XOffset;
	unsigned YOffset;
	unsigned BytesWritten;
	TW_MEMORY Memory;
} ;
#pragma pack(pop)

typedef TW_IMAGEMEMXFER *pTW_IMAGEMEMXFER;

typedef TW_IMAGEMEMXFER  TTWImageMemXFER;

typedef TW_IMAGEMEMXFER *PTWImageMemXFER;

#pragma pack(push, 1)
struct TW_JPEGCOMPRESSION
{
	Word ColorSpace;
	unsigned SubSampling;
	Word NumComponents;
	Word RestartFrequency;
	Word QuantMap[4];
	TW_MEMORY QuantTable[4];
	Word HuffmanMap[4];
	TW_MEMORY HuffmanDC[2];
	TW_MEMORY HuffmanAC[2];
} ;
#pragma pack(pop)

typedef TW_JPEGCOMPRESSION *pTW_JPEGCOMPRESSION;

typedef TW_JPEGCOMPRESSION  TTWJPEGCompression;

typedef TW_JPEGCOMPRESSION *PTWJPEGCompression;

#pragma pack(push, 1)
struct TW_PALETTE8
{
	Word NumColors;
	Word PaletteType;
	TW_ELEMENT8 Colors[256];
} ;
#pragma pack(pop)

typedef TW_PALETTE8 *pTW_PALETTE8;

typedef TW_PALETTE8  TTWPalette8;

typedef TW_PALETTE8 *PTWPalette8;

#pragma pack(push, 1)
struct TW_PENDINGXFERS
{
	Word Count;
	union
	{
		struct 
		{
			unsigned Reserved;
			
		};
		struct 
		{
			unsigned EOJ;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef TW_PENDINGXFERS *pTW_PENDINGXFERS;

typedef TW_PENDINGXFERS  TTWPendingXFERS;

typedef TW_PENDINGXFERS *PTWPendingXFERS;

#pragma pack(push, 1)
struct TW_RGBRESPONSE
{
	TW_ELEMENT8 Response[1];
} ;
#pragma pack(pop)

typedef TW_RGBRESPONSE *pTW_RGBRESPONSE;

typedef TW_RGBRESPONSE  TTWRGBResponse;

typedef TW_RGBRESPONSE *PTWRGBResponse;

#pragma pack(push, 1)
struct TW_SETUPFILEXFER
{
	char FileName[256];
	Word Format;
	short VRefNum;
} ;
#pragma pack(pop)

typedef TW_SETUPFILEXFER *pTW_SETUPFILEXFER;

typedef TW_SETUPFILEXFER  TTWSetupFileXFER;

typedef TW_SETUPFILEXFER *PTWSetupFileXFER;

#pragma pack(push, 1)
struct TW_SETUPFILEXFER2
{
	void *FileName;
	Word FileNameType;
	Word Format;
	short VRefNum;
	unsigned parID;
} ;
#pragma pack(pop)

typedef TW_SETUPFILEXFER2 *pTW_SETUPFILEXFER2;

typedef TW_SETUPFILEXFER2  TTWSetupFileXFER2;

typedef TW_SETUPFILEXFER2 *PTWSetupFileXFER2;

#pragma pack(push, 1)
struct TW_SETUPMEMXFER
{
	unsigned MinBufSize;
	unsigned MaxBufSize;
	unsigned Preferred;
} ;
#pragma pack(pop)

typedef TW_SETUPMEMXFER *pTW_SETUPMEMXFER;

typedef TW_SETUPMEMXFER  TTWSetupMemXFER;

typedef TW_SETUPMEMXFER *PTWSetupMemXFER;

#pragma pack(push, 1)
struct TW_STATUS
{
	Word ConditionCode;
	Word Reserved;
} ;
#pragma pack(pop)

typedef TW_STATUS *pTW_STATUS;

typedef TW_STATUS  TTWStatus;

typedef TW_STATUS *PTWStatus;

#pragma pack(push, 1)
struct TW_USERINTERFACE
{
	Word ShowUI;
	Word ModalUI;
	unsigned hParent;
} ;
#pragma pack(pop)

typedef TW_USERINTERFACE *pTW_USERINTERFACE;

typedef TW_USERINTERFACE  TTWUserInterface;

typedef TW_USERINTERFACE *PTWUserInterface;

#pragma pack(push, 1)
struct TW_TWUNKIDENTITY
{
	TW_IDENTITY identity;
	char dsPath[256];
} ;
#pragma pack(pop)

typedef TW_TWUNKIDENTITY *pTW_TWUNKIDENTITY;

typedef TW_TWUNKIDENTITY  TTWTwunkIdentity;

typedef TW_TWUNKIDENTITY *PTWTwunkIdentity;

#pragma pack(push, 1)
struct TW_TWUNKDSENTRYPARAMS
{
	Shortint destFlag;
	Shortint alignment;
	TW_IDENTITY dest;
	int dataGroup;
	short dataArgType;
	short message;
	int pDataSize;
} ;
#pragma pack(pop)

typedef TW_TWUNKDSENTRYPARAMS *pTW_TWUNKDSENTRYPARAMS;

typedef TW_TWUNKDSENTRYPARAMS  TTWTwunkDSEntryParams;

typedef TW_TWUNKDSENTRYPARAMS *PTWTwunkDSEntryParams;

#pragma pack(push, 1)
struct TW_TWUNKDSENTRYRETURN
{
	Word returnCode;
	Word conditionCode;
	int pDataSize;
} ;
#pragma pack(pop)

typedef TW_TWUNKDSENTRYRETURN *pTW_TWUNKDSENTRYRETURN;

typedef TW_TWUNKDSENTRYRETURN  TTWTwunkDSEntryReturn;

typedef TW_TWUNKDSENTRYRETURN *PTWTwunkDSEntryReturn;

#pragma pack(push, 1)
struct TW_CAPEXT
{
	Word Cap;
	Word Properties;
} ;
#pragma pack(pop)

typedef TW_CAPEXT *pTW_CAPEXT;

typedef TW_CAPEXT  TTWCapExt;

typedef TW_CAPEXT *PTWCapExt;

#pragma pack(push, 1)
struct TW_CUSTOMDSDATA
{
	unsigned InfoLength;
	unsigned hData;
} ;
#pragma pack(pop)

typedef TW_CUSTOMDSDATA *pTW_CUSTOMDSDATA;

typedef TW_CUSTOMDSDATA  TTWCustomDSData;

typedef TW_CUSTOMDSDATA *PTWCustomDSData;

#pragma pack(push, 1)
struct TW_INFO
{
	Word InfoID;
	Word ItemType;
	Word NumItems;
	Word CondCode;
	unsigned Item;
} ;
#pragma pack(pop)

typedef TW_INFO *pTW_INFO;

typedef TW_INFO  TTWInfo;

typedef TW_INFO *PTWInfo;

#pragma pack(push, 1)
struct TW_EXTIMAGEINFO
{
	unsigned NumInfos;
	TW_INFO Info[1];
} ;
#pragma pack(pop)

typedef TW_EXTIMAGEINFO *pTW_EXTIMAGEINFO;

typedef TW_EXTIMAGEINFO  TTWExtImageInfo;

typedef TW_EXTIMAGEINFO *PTWExtImageInfo;

#pragma pack(push, 1)
struct TW_AUDIOINFO
{
	char Name[256];
	unsigned Reserved;
} ;
#pragma pack(pop)

typedef TW_AUDIOINFO *pTW_AUDIOINFO;

typedef TW_AUDIOINFO  TTWAudioInfo;

typedef TW_AUDIOINFO *PTWAudioInfo;

#pragma pack(push, 1)
struct TW_DEVICEEVENT
{
	unsigned Event;
	char DeviceName[256];
	unsigned BatteryMinutes;
	short BatteryPercentage;
	int PowerSupply;
	TW_FIX32 XResolution;
	TW_FIX32 YResolution;
	unsigned FlashUsed2;
	unsigned AutomaticCapture;
	unsigned TimeBeforeFirstCapture;
	unsigned TimeBetweenCaptures;
} ;
#pragma pack(pop)

typedef TW_DEVICEEVENT *pTW_DEVICEEVENT;

typedef TW_DEVICEEVENT  TTWDeviceEvent;

typedef TW_DEVICEEVENT *PTWDeviceEvent;

#pragma pack(push, 1)
struct TW_FILESYSTEM
{
	char InputName[256];
	char OutputName[256];
	void *Context;
	int Recursive;
	int FileType;
	unsigned Size;
	char CreateTimeDate[34];
	char ModifiedTimeDate[34];
	unsigned FreeSpace;
	int NewImageSize;
	unsigned NumberOfFiles;
	unsigned NumberOfSnippets;
	unsigned DeviceGroupMask;
	char Reserved[508];
} ;
#pragma pack(pop)

typedef TW_FILESYSTEM *pTW_FILESYSTEM;

typedef TW_FILESYSTEM  TTWFileSystem;

typedef TW_FILESYSTEM *PTWFileSystem;

#pragma pack(push, 1)
struct TW_PASSTHRU
{
	void *pCommand;
	unsigned CommandBytes;
	int Direction;
	void *pData;
	unsigned DataBytes;
	unsigned DataBytesXfered;
} ;
#pragma pack(pop)

typedef TW_PASSTHRU *pTW_PASSTHRU;

typedef TW_PASSTHRU  TTWPassThru;

typedef TW_PASSTHRU *PTWPassThru;

#pragma pack(push, 1)
struct TW_SETUPAUDIOFILEXFER
{
	char FileName[256];
	Word Format;
	short VRefNum;
} ;
#pragma pack(pop)

typedef TW_SETUPAUDIOFILEXFER *pTW_SETUPAUDIOFILEXFER;

typedef TW_SETUPAUDIOFILEXFER  TTWSetupAudioFileXFER;

typedef TW_SETUPAUDIOFILEXFER *PTWSetupAudioFileXFER;

typedef Word __stdcall (*DSMENTRYPROC)(pTW_IDENTITY pOrigin, pTW_IDENTITY pDest, unsigned DG, Word DAT
	, Word MSG, void * pData);

typedef Word __stdcall (*TDSMEntryProc)(pTW_IDENTITY pOrigin, pTW_IDENTITY pDest, unsigned DG, Word 
	DAT, Word MSG, void * pData);

typedef Word __stdcall (*DSENTRYPROC)(pTW_IDENTITY pOrigin, unsigned DG, Word DAT, Word MSG, void * 
	pData);

typedef Word __stdcall (*TDSEntryProc)(pTW_IDENTITY pOrigin, unsigned DG, Word DAT, Word MSG, void * 
	pData);

//-- var, const, procedure ---------------------------------------------------
static const Shortint TWON_PROTOCOLMINOR = 0x9;
static const Shortint TWON_PROTOCOLMAJOR = 0x1;
static const Shortint TWON_ARRAY = 0x3;
static const Shortint TWON_ENUMERATION = 0x4;
static const Shortint TWON_ONEVALUE = 0x5;
static const Shortint TWON_RANGE = 0x6;
static const Word TWON_ICONID = 0x3c2;
static const Word TWON_DSMID = 0x1cd;
static const Shortint TWON_DSMCODEID = 0x3f;
static const Byte TWON_DONTCARE8 = 0xff;
static const Word TWON_DONTCARE16 = 0xffff;
static const unsigned TWON_DONTCARE32 = 0xffffffff;
static const Shortint TWMF_APPOWNS = 0x1;
static const Shortint TWMF_DSMOWNS = 0x2;
static const Shortint TWMF_DSOWNS = 0x4;
static const Shortint TWMF_POINTER = 0x8;
static const Shortint TWMF_HANDLE = 0x10;
static const Shortint TWPA_RGB = 0x0;
static const Shortint TWPA_GRAY = 0x1;
static const Shortint TWPA_CMY = 0x2;
static const Shortint TWTY_INT8 = 0x0;
static const Shortint TWTY_INT16 = 0x1;
static const Shortint TWTY_INT32 = 0x2;
static const Shortint TWTY_UINT8 = 0x3;
static const Shortint TWTY_UINT16 = 0x4;
static const Shortint TWTY_UINT32 = 0x5;
static const Shortint TWTY_BOOL = 0x6;
static const Shortint TWTY_FIX32 = 0x7;
static const Shortint TWTY_FRAME = 0x8;
static const Shortint TWTY_STR32 = 0x9;
static const Shortint TWTY_STR64 = 0xa;
static const Shortint TWTY_STR128 = 0xb;
static const Shortint TWTY_STR255 = 0xc;
static const Shortint TWTY_STR1024 = 0xd;
static const Shortint TWTY_UNI512 = 0xe;
static const Shortint TWBO_LSBFIRST = 0x0;
static const Shortint TWBO_MSBFIRST = 0x1;
static const Shortint TWCP_NONE = 0x0;
static const Shortint TWCP_PACKBITS = 0x1;
static const Shortint TWCP_GROUP31D = 0x2;
static const Shortint TWCP_GROUP31DEOL = 0x3;
static const Shortint TWCP_GROUP32D = 0x4;
static const Shortint TWCP_GROUP4 = 0x5;
static const Shortint TWCP_JPEG = 0x6;
static const Shortint TWCP_LZW = 0x7;
static const Shortint TWCP_JBIG = 0x8;
static const Shortint TWCP_PNG = 0x9;
static const Shortint TWCP_RLE4 = 0xa;
static const Shortint TWCP_RLE8 = 0xb;
static const Shortint TWCP_BITFIELDS = 0xc;
static const Shortint TWFF_TIFF = 0x0;
static const Shortint TWFF_PICT = 0x1;
static const Shortint TWFF_BMP = 0x2;
static const Shortint TWFF_XBM = 0x3;
static const Shortint TWFF_JFIF = 0x4;
static const Shortint TWFF_FPX = 0x5;
static const Shortint TWFF_TIFFMULTI = 0x6;
static const Shortint TWFF_PNG = 0x7;
static const Shortint TWFF_SPIFF = 0x8;
static const Shortint TWFF_EXIF = 0x9;
static const Shortint TWFT_RED = 0x0;
static const Shortint TWFT_GREEN = 0x1;
static const Shortint TWFT_BLUE = 0x2;
static const Shortint TWFT_NONE = 0x3;
static const Shortint TWFT_WHITE = 0x4;
static const Shortint TWFT_CYAN = 0x5;
static const Shortint TWFT_MAGENTA = 0x6;
static const Shortint TWFT_YELLOW = 0x7;
static const Shortint TWFT_BLACK = 0x8;
static const Shortint TWLP_REFLECTIVE = 0x0;
static const Shortint TWLP_TRANSMISSIVE = 0x1;
static const Shortint TWLS_RED = 0x0;
static const Shortint TWLS_GREEN = 0x1;
static const Shortint TWLS_BLUE = 0x2;
static const Shortint TWLS_NONE = 0x3;
static const Shortint TWLS_WHITE = 0x4;
static const Shortint TWLS_UV = 0x5;
static const Shortint TWLS_IR = 0x6;
static const Shortint TWOR_ROT0 = 0x0;
static const Shortint TWOR_ROT90 = 0x1;
static const Shortint TWOR_ROT180 = 0x2;
static const Shortint TWOR_ROT270 = 0x3;
static const Shortint TWOR_PORTRAIT = 0x0;
static const Shortint TWOR_LANDSCAPE = 0x3;
static const Shortint TWPC_CHUNKY = 0x0;
static const Shortint TWPC_PLANAR = 0x1;
static const Shortint TWPF_CHOCOLATE = 0x0;
static const Shortint TWPF_VANILLA = 0x1;
static const Shortint TWPT_BW = 0x0;
static const Shortint TWPT_GRAY = 0x1;
static const Shortint TWPT_RGB = 0x2;
static const Shortint TWPT_PALETTE = 0x3;
static const Shortint TWPT_CMY = 0x4;
static const Shortint TWPT_CMYK = 0x5;
static const Shortint TWPT_YUV = 0x6;
static const Shortint TWPT_YUVK = 0x7;
static const Shortint TWPT_CIEXYZ = 0x8;
static const Shortint TWSS_NONE = 0x0;
static const Shortint TWSS_A4LETTER = 0x1;
static const Shortint TWSS_B5LETTER = 0x2;
static const Shortint TWSS_USLETTER = 0x3;
static const Shortint TWSS_USLEGAL = 0x4;
static const Shortint TWSS_A5 = 0x5;
static const Shortint TWSS_B4 = 0x6;
static const Shortint TWSS_B6 = 0x7;
static const Shortint TWSS_USLEDGER = 0x9;
static const Shortint TWSS_USEXECUTIVE = 0xa;
static const Shortint TWSS_A3 = 0xb;
static const Shortint TWSS_B3 = 0xc;
static const Shortint TWSS_A6 = 0xd;
static const Shortint TWSS_C4 = 0xe;
static const Shortint TWSS_C5 = 0xf;
static const Shortint TWSS_C6 = 0x10;
static const Shortint TWSS_4A0 = 0x11;
static const Shortint TWSS_2A0 = 0x12;
static const Shortint TWSS_A0 = 0x13;
static const Shortint TWSS_A1 = 0x14;
static const Shortint TWSS_A2 = 0x15;
static const Shortint TWSS_A4 = 0x1;
static const Shortint TWSS_A7 = 0x16;
static const Shortint TWSS_A8 = 0x17;
static const Shortint TWSS_A9 = 0x18;
static const Shortint TWSS_A10 = 0x19;
static const Shortint TWSS_ISOB0 = 0x1a;
static const Shortint TWSS_ISOB1 = 0x1b;
static const Shortint TWSS_ISOB2 = 0x1c;
static const Shortint TWSS_ISOB3 = 0xc;
static const Shortint TWSS_ISOB4 = 0x6;
static const Shortint TWSS_ISOB5 = 0x1d;
static const Shortint TWSS_ISOB6 = 0x7;
static const Shortint TWSS_ISOB7 = 0x1e;
static const Shortint TWSS_ISOB8 = 0x1f;
static const Shortint TWSS_ISOB9 = 0x20;
static const Shortint TWSS_ISOB10 = 0x21;
static const Shortint TWSS_JISB0 = 0x22;
static const Shortint TWSS_JISB1 = 0x23;
static const Shortint TWSS_JISB2 = 0x24;
static const Shortint TWSS_JISB3 = 0x25;
static const Shortint TWSS_JISB4 = 0x26;
static const Shortint TWSS_JISB5 = 0x2;
static const Shortint TWSS_JISB6 = 0x27;
static const Shortint TWSS_JISB7 = 0x28;
static const Shortint TWSS_JISB8 = 0x29;
static const Shortint TWSS_JISB9 = 0x2a;
static const Shortint TWSS_JISB10 = 0x2b;
static const Shortint TWSS_C0 = 0x2c;
static const Shortint TWSS_C1 = 0x2d;
static const Shortint TWSS_C2 = 0x2e;
static const Shortint TWSS_C3 = 0x2f;
static const Shortint TWSS_C7 = 0x30;
static const Shortint TWSS_C8 = 0x31;
static const Shortint TWSS_C9 = 0x32;
static const Shortint TWSS_C10 = 0x33;
static const Shortint TWSS_USSTATEMENT = 0x34;
static const Shortint TWSS_BUSINESSCARD = 0x35;
static const Shortint TWSX_NATIVE = 0x0;
static const Shortint TWSX_FILE = 0x1;
static const Shortint TWSX_MEMORY = 0x2;
static const Shortint TWSX_FILE2 = 0x3;
static const Shortint TWUN_INCHES = 0x0;
static const Shortint TWUN_CENTIMETERS = 0x1;
static const Shortint TWUN_PICAS = 0x2;
static const Shortint TWUN_POINTS = 0x3;
static const Shortint TWUN_TWIPS = 0x4;
static const Shortint TWUN_PIXELS = 0x5;
static const Shortint TWBR_THRESHOLD = 0x0;
static const Shortint TWBR_HALFTONE = 0x1;
static const Shortint TWBR_CUSTHALFTONE = 0x2;
static const Shortint TWBR_DIFFUSION = 0x3;
static const Shortint TWDX_NONE = 0x0;
static const Shortint TWDX_1PASSDUPLEX = 0x1;
static const Shortint TWDX_2PASSDUPLEX = 0x2;
static const Shortint TWBT_3OF9 = 0x0;
static const Shortint TWBT_2OF5INTERLEAVED = 0x1;
static const Shortint TWBT_2OF5NONINTERLEAVED = 0x2;
static const Shortint TWBT_CODE93 = 0x3;
static const Shortint TWBT_CODE128 = 0x4;
static const Shortint TWBT_UCC128 = 0x5;
static const Shortint TWBT_CODABAR = 0x6;
static const Shortint TWBT_UPCA = 0x7;
static const Shortint TWBT_UPCE = 0x8;
static const Shortint TWBT_EAN8 = 0x9;
static const Shortint TWBT_EAN13 = 0xa;
static const Shortint TWBT_POSTNET = 0xb;
static const Shortint TWBT_PDF417 = 0xc;
static const Shortint TWBT_2OF5INDUSTRIAL = 0xd;
static const Shortint TWBT_2OF5MATRIX = 0xe;
static const Shortint TWBT_2OF5DATALOGIC = 0xf;
static const Shortint TWBT_2OF5IATA = 0x10;
static const Shortint TWBT_3OF9FULLASCII = 0x11;
static const Shortint TWBT_CODABARWITHSTARTSTOP = 0x12;
static const Shortint TWBT_MAXICODE = 0x13;
static const Shortint TWDSK_SUCCESS = 0x0;
static const Shortint TWDSK_REPORTONLY = 0x1;
static const Shortint TWDSK_FAIL = 0x2;
static const Shortint TWDSK_DISABLED = 0x3;
static const Shortint TWPCH_PATCH1 = 0x0;
static const Shortint TWPCH_PATCH2 = 0x1;
static const Shortint TWPCH_PATCH3 = 0x2;
static const Shortint TWPCH_PATCH4 = 0x3;
static const Shortint TWPCH_PATCH6 = 0x4;
static const Shortint TWPCH_PATCHT = 0x5;
static const Shortint TWJC_NONE = 0x0;
static const Shortint TWJC_JSIC = 0x1;
static const Shortint TWJC_JSIS = 0x2;
static const Shortint TWJC_JSXC = 0x3;
static const Shortint TWJC_JSXS = 0x4;
static const Shortint TWBCOR_ROT0 = 0x0;
static const Shortint TWBCOR_ROT90 = 0x1;
static const Shortint TWBCOR_ROT180 = 0x2;
static const Shortint TWBCOR_ROT270 = 0x3;
static const Shortint TWBCOR_ROTX = 0x4;
static const Shortint TWAF_WAV = 0x0;
static const Shortint TWAF_AIFF = 0x1;
static const Shortint TWAF_AU = 0x3;
static const Shortint TWAF_SND = 0x4;
static const Shortint TWAL_ALARM = 0x0;
static const Shortint TWAL_FEEDERERROR = 0x1;
static const Shortint TWAL_FEEDERWARNING = 0x2;
static const Shortint TWAL_BARCODE = 0x3;
static const Shortint TWAL_DOUBLEFEED = 0x4;
static const Shortint TWAL_JAM = 0x5;
static const Shortint TWAL_PATCHCODE = 0x6;
static const Shortint TWAL_POWER = 0x7;
static const Shortint TWAL_SKEW = 0x8;
static const Shortint TWCB_AUTO = 0x0;
static const Shortint TWCB_CLEAR = 0x1;
static const Shortint TWCB_NOCLEAR = 0x2;
static const Word TWDE_CUSTOMEVENTS = 0x8000;
static const Shortint TWDE_CHECKAUTOMATICCAPTURE = 0x0;
static const Shortint TWDE_CHECKBATTERY = 0x1;
static const Shortint TWDE_CHECKDEVICEONLINE = 0x2;
static const Shortint TWDE_CHECKFLASH = 0x3;
static const Shortint TWDE_CHECKPOWERSUPPLY = 0x4;
static const Shortint TWDE_CHECKRESOLUTION = 0x5;
static const Shortint TWDE_DEVICEADDED = 0x6;
static const Shortint TWDE_DEVICEOFFLINE = 0x7;
static const Shortint TWDE_DEVICEREADY = 0x8;
static const Shortint TWDE_DEVICEREMOVED = 0x9;
static const Shortint TWDE_IMAGECAPTURED = 0xa;
static const Shortint TWDE_IMAGEDELETED = 0xb;
static const Shortint TWDE_PAPERDOUBLEFEED = 0xc;
static const Shortint TWDE_PAPERJAM = 0xd;
static const Shortint TWDE_LAMPFAILURE = 0xe;
static const Shortint TWDE_POWERSAVE = 0xf;
static const Shortint TWDE_POWERSAVENOTIFY = 0x10;
static const Shortint TWFA_NONE = 0x0;
static const Shortint TWFA_LEFT = 0x1;
static const Shortint TWFA_CENTER = 0x2;
static const Shortint TWFA_RIGHT = 0x3;
static const Shortint TWFO_FIRSTPAGEFIRST = 0x0;
static const Shortint TWFO_LASTPAGEFIRST = 0x1;
static const Shortint TWFS_FILESYSTEM = 0x0;
static const Shortint TWFS_RECURSIVEDELETE = 0x1;
static const Shortint TWPS_EXTERNAL = 0x0;
static const Shortint TWPS_BATTERY = 0x1;
static const Shortint TWPR_IMPRINTERTOPBEFORE = 0x0;
static const Shortint TWPR_IMPRINTERTOPAFTER = 0x1;
static const Shortint TWPR_IMPRINTERBOTTOMBEFORE = 0x2;
static const Shortint TWPR_IMPRINTERBOTTOMAFTER = 0x3;
static const Shortint TWPR_ENDORSERTOPBEFORE = 0x4;
static const Shortint TWPR_ENDORSERTOPAFTER = 0x5;
static const Shortint TWPR_ENDORSERBOTTOMBEFORE = 0x6;
static const Shortint TWPR_ENDORSERBOTTOMAFTER = 0x7;
static const Shortint TWPM_SINGLESTRING = 0x0;
static const Shortint TWPM_MULTISTRING = 0x1;
static const Shortint TWPM_COMPOUNDSTRING = 0x2;
static const Shortint TWBD_HORZ = 0x0;
static const Shortint TWBD_VERT = 0x1;
static const Shortint TWBD_HORZVERT = 0x2;
static const Shortint TWBD_VERTHORZ = 0x3;
static const Shortint TWFL_NONE = 0x0;
static const Shortint TWFL_OFF = 0x1;
static const Shortint TWFL_ON = 0x2;
static const Shortint TWFL_AUTO = 0x3;
static const Shortint TWFL_REDEYE = 0x4;
static const Shortint TWFR_BOOK = 0x0;
static const Shortint TWFR_FANFOLD = 0x1;
static const Shortint TWIF_NONE = 0x0;
static const Shortint TWIF_AUTO = 0x1;
static const Shortint TWIF_LOWPASS = 0x2;
static const Shortint TWIF_BANDPASS = 0x3;
static const Shortint TWIF_HIGHPASS = 0x4;
static const Shortint TWIF_TEXT = 0x3;
static const Shortint TWIF_FINELINE = 0x4;
static const Shortint TWNF_NONE = 0x0;
static const Shortint TWNF_AUTO = 0x1;
static const Shortint TWNF_LONEPIXEL = 0x2;
static const Shortint TWNF_MAJORITYRULE = 0x3;
static const Shortint TWOV_NONE = 0x0;
static const Shortint TWOV_AUTO = 0x1;
static const Shortint TWOV_TOPBOTTOM = 0x2;
static const Shortint TWOV_LEFTRIGHT = 0x3;
static const Shortint TWOV_ALL = 0x4;
static const Shortint TWFY_CAMERA = 0x0;
static const Shortint TWFY_CAMERATOP = 0x1;
static const Shortint TWFY_CAMERABOTTOM = 0x2;
static const Shortint TWFY_CAMERAPREVIEW = 0x3;
static const Shortint TWFY_DOMAIN = 0x4;
static const Shortint TWFY_HOST = 0x5;
static const Shortint TWFY_DIRECTORY = 0x6;
static const Shortint TWFY_IMAGE = 0x7;
static const Shortint TWFY_UNKNOWN = 0x8;
static const Shortint TWJQ_UNKNOWN = 0xfffffffc;
static const Shortint TWJQ_LOW = 0xfffffffd;
static const Shortint TWJQ_MEDIUM = 0xfffffffe;
static const Shortint TWJQ_HIGH = 0xffffffff;
static const Word TWCY_AFGHANISTAN = 0x3e9;
static const Byte TWCY_ALGERIA = 0xd5;
static const Word TWCY_AMERICANSAMOA = 0x2ac;
static const Shortint TWCY_ANDORRA = 0x21;
static const Word TWCY_ANGOLA = 0x3ea;
static const Word TWCY_ANGUILLA = 0x1f9a;
static const Word TWCY_ANTIGUA = 0x1f9b;
static const Shortint TWCY_ARGENTINA = 0x36;
static const Word TWCY_ARUBA = 0x129;
static const Byte TWCY_ASCENSIONI = 0xf7;
static const Shortint TWCY_AUSTRALIA = 0x3d;
static const Shortint TWCY_AUSTRIA = 0x2b;
static const Word TWCY_BAHAMAS = 0x1f9c;
static const Word TWCY_BAHRAIN = 0x3cd;
static const Word TWCY_BANGLADESH = 0x370;
static const Word TWCY_BARBADOS = 0x1f9d;
static const Shortint TWCY_BELGIUM = 0x20;
static const Word TWCY_BELIZE = 0x1f5;
static const Byte TWCY_BENIN = 0xe5;
static const Word TWCY_BERMUDA = 0x1f9e;
static const Word TWCY_BHUTAN = 0x3eb;
static const Word TWCY_BOLIVIA = 0x24f;
static const Word TWCY_BOTSWANA = 0x10b;
static const Shortint TWCY_BRITAIN = 0x6;
static const Word TWCY_BRITVIRGINIS = 0x1f9f;
static const Shortint TWCY_BRAZIL = 0x37;
static const Word TWCY_BRUNEI = 0x2a1;
static const Word TWCY_BULGARIA = 0x167;
static const Word TWCY_BURKINAFASO = 0x3ec;
static const Word TWCY_BURMA = 0x3ed;
static const Word TWCY_BURUNDI = 0x3ee;
static const Byte TWCY_CAMAROON = 0xed;
static const Shortint TWCY_CANADA = 0x2;
static const Byte TWCY_CAPEVERDEIS = 0xee;
static const Word TWCY_CAYMANIS = 0x1fa0;
static const Word TWCY_CENTRALAFREP = 0x3ef;
static const Word TWCY_CHAD = 0x3f0;
static const Shortint TWCY_CHILE = 0x38;
static const Shortint TWCY_CHINA = 0x56;
static const Word TWCY_CHRISTMASIS = 0x3f1;
static const Word TWCY_COCOSIS = 0x3f1;
static const Shortint TWCY_COLOMBIA = 0x39;
static const Word TWCY_COMOROS = 0x3f2;
static const Word TWCY_CONGO = 0x3f3;
static const Word TWCY_COOKIS = 0x3f4;
static const Word TWCY_COSTARICA = 0x1fa;
static const Shortint TWCY_CUBA = 0x5;
static const Word TWCY_CYPRUS = 0x165;
static const Shortint TWCY_CZECHOSLOVAKIA = 0x2a;
static const Shortint TWCY_DENMARK = 0x2d;
static const Word TWCY_DJIBOUTI = 0x3f5;
static const Word TWCY_DOMINICA = 0x1fa1;
static const Word TWCY_DOMINCANREP = 0x1fa2;
static const Word TWCY_EASTERIS = 0x3f6;
static const Word TWCY_ECUADOR = 0x251;
static const Shortint TWCY_EGYPT = 0x14;
static const Word TWCY_ELSALVADOR = 0x1f7;
static const Word TWCY_EQGUINEA = 0x3f7;
static const Byte TWCY_ETHIOPIA = 0xfb;
static const Word TWCY_FALKLANDIS = 0x3f8;
static const Word TWCY_FAEROEIS = 0x12a;
static const Word TWCY_FIJIISLANDS = 0x2a7;
static const Word TWCY_FINLAND = 0x166;
static const Shortint TWCY_FRANCE = 0x21;
static const Word TWCY_FRANTILLES = 0x254;
static const Word TWCY_FRGUIANA = 0x252;
static const Word TWCY_FRPOLYNEISA = 0x2b1;
static const Word TWCY_FUTANAIS = 0x413;
static const Byte TWCY_GABON = 0xf1;
static const Byte TWCY_GAMBIA = 0xdc;
static const Shortint TWCY_GERMANY = 0x31;
static const Byte TWCY_GHANA = 0xe9;
static const Word TWCY_GIBRALTER = 0x15e;
static const Shortint TWCY_GREECE = 0x1e;
static const Word TWCY_GREENLAND = 0x12b;
static const Word TWCY_GRENADA = 0x1fa3;
static const Word TWCY_GRENEDINES = 0x1f4f;
static const Word TWCY_GUADELOUPE = 0x24e;
static const Word TWCY_GUAM = 0x29f;
static const Word TWCY_GUANTANAMOBAY = 0x1517;
static const Word TWCY_GUATEMALA = 0x1f6;
static const Byte TWCY_GUINEA = 0xe0;
static const Word TWCY_GUINEABISSAU = 0x3f9;
static const Word TWCY_GUYANA = 0x250;
static const Word TWCY_HAITI = 0x1fd;
static const Word TWCY_HONDURAS = 0x1f8;
static const Word TWCY_HONGKONG = 0x354;
static const Shortint TWCY_HUNGARY = 0x24;
static const Word TWCY_ICELAND = 0x162;
static const Shortint TWCY_INDIA = 0x5b;
static const Shortint TWCY_INDONESIA = 0x3e;
static const Shortint TWCY_IRAN = 0x62;
static const Word TWCY_IRAQ = 0x3c4;
static const Word TWCY_IRELAND = 0x161;
static const Word TWCY_ISRAEL = 0x3cc;
static const Shortint TWCY_ITALY = 0x27;
static const Byte TWCY_IVORYCOAST = 0xe1;
static const Word TWCY_JAMAICA = 0x1f4a;
static const Shortint TWCY_JAPAN = 0x51;
static const Word TWCY_JORDAN = 0x3c2;
static const Byte TWCY_KENYA = 0xfe;
static const Word TWCY_KIRIBATI = 0x3fa;
static const Shortint TWCY_KOREA = 0x52;
static const Word TWCY_KUWAIT = 0x3c5;
static const Word TWCY_LAOS = 0x3fb;
static const Word TWCY_LEBANON = 0x3fc;
static const Byte TWCY_LIBERIA = 0xe7;
static const Byte TWCY_LIBYA = 0xda;
static const Shortint TWCY_LIECHTENSTEIN = 0x29;
static const Word TWCY_LUXENBOURG = 0x160;
static const Word TWCY_MACAO = 0x355;
static const Word TWCY_MADAGASCAR = 0x3fd;
static const Word TWCY_MALAWI = 0x109;
static const Shortint TWCY_MALAYSIA = 0x3c;
static const Word TWCY_MALDIVES = 0x3c0;
static const Word TWCY_MALI = 0x3fe;
static const Word TWCY_MALTA = 0x164;
static const Word TWCY_MARSHALLIS = 0x2b4;
static const Word TWCY_MAURITANIA = 0x3ff;
static const Byte TWCY_MAURITIUS = 0xe6;
static const Shortint TWCY_MEXICO = 0x3;
static const Word TWCY_MICRONESIA = 0x2b3;
static const Word TWCY_MIQUELON = 0x1fc;
static const Shortint TWCY_MONACO = 0x21;
static const Word TWCY_MONGOLIA = 0x400;
static const Word TWCY_MONTSERRAT = 0x1f4b;
static const Byte TWCY_MOROCCO = 0xd4;
static const Word TWCY_MOZAMBIQUE = 0x401;
static const Word TWCY_NAMIBIA = 0x108;
static const Word TWCY_NAURU = 0x402;
static const Word TWCY_NEPAL = 0x3d1;
static const Shortint TWCY_NETHERLANDS = 0x1f;
static const Word TWCY_NETHANTILLES = 0x257;
static const Word TWCY_NEVIS = 0x1f4c;
static const Word TWCY_NEWCALEDONIA = 0x2af;
static const Shortint TWCY_NEWZEALAND = 0x40;
static const Word TWCY_NICARAGUA = 0x1f9;
static const Byte TWCY_NIGER = 0xe3;
static const Byte TWCY_NIGERIA = 0xea;
static const Word TWCY_NIUE = 0x403;
static const Word TWCY_NORFOLKI = 0x404;
static const Shortint TWCY_NORWAY = 0x2f;
static const Word TWCY_OMAN = 0x3c8;
static const Shortint TWCY_PAKISTAN = 0x5c;
static const Word TWCY_PALAU = 0x405;
static const Word TWCY_PANAMA = 0x1fb;
static const Word TWCY_PARAGUAY = 0x253;
static const Shortint TWCY_PERU = 0x33;
static const Shortint TWCY_PHILLIPPINES = 0x3f;
static const Word TWCY_PITCAIRNIS = 0x406;
static const Word TWCY_PNEWGUINEA = 0x2a3;
static const Shortint TWCY_POLAND = 0x30;
static const Word TWCY_PORTUGAL = 0x15f;
static const Word TWCY_QATAR = 0x3ce;
static const Word TWCY_REUNIONI = 0x407;
static const Shortint TWCY_ROMANIA = 0x28;
static const Byte TWCY_RWANDA = 0xfa;
static const Word TWCY_SAIPAN = 0x29e;
static const Shortint TWCY_SANMARINO = 0x27;
static const Word TWCY_SAOTOME = 0x409;
static const Word TWCY_SAUDIARABIA = 0x3c6;
static const Byte TWCY_SENEGAL = 0xdd;
static const Word TWCY_SEYCHELLESIS = 0x40a;
static const Word TWCY_SIERRALEONE = 0x40b;
static const Shortint TWCY_SINGAPORE = 0x41;
static const Word TWCY_SOLOMONIS = 0x40c;
static const Word TWCY_SOMALI = 0x40d;
static const Shortint TWCY_SOUTHAFRICA = 0x1b;
static const Shortint TWCY_SPAIN = 0x22;
static const Shortint TWCY_SRILANKA = 0x5e;
static const Word TWCY_STHELENA = 0x408;
static const Word TWCY_STKITTS = 0x1f4d;
static const Word TWCY_STLUCIA = 0x1f4e;
static const Word TWCY_STPIERRE = 0x1fc;
static const Word TWCY_STVINCENT = 0x1f4f;
static const Word TWCY_SUDAN = 0x40e;
static const Word TWCY_SURINAME = 0x255;
static const Word TWCY_SWAZILAND = 0x10c;
static const Shortint TWCY_SWEDEN = 0x2e;
static const Shortint TWCY_SWITZERLAND = 0x29;
static const Word TWCY_SYRIA = 0x40f;
static const Word TWCY_TAIWAN = 0x376;
static const Byte TWCY_TANZANIA = 0xff;
static const Shortint TWCY_THAILAND = 0x42;
static const Word TWCY_TOBAGO = 0x1f50;
static const Byte TWCY_TOGO = 0xe4;
static const Word TWCY_TONGAIS = 0x2a4;
static const Word TWCY_TRINIDAD = 0x1f50;
static const Byte TWCY_TUNISIA = 0xd8;
static const Shortint TWCY_TURKEY = 0x5a;
static const Word TWCY_TURKSCAICOS = 0x1f51;
static const Word TWCY_TUVALU = 0x410;
static const Word TWCY_UGANDA = 0x100;
static const Shortint TWCY_USSR = 0x7;
static const Word TWCY_UAEMIRATES = 0x3cb;
static const Shortint TWCY_UNITEDKINGDOM = 0x2c;
static const Shortint TWCY_USA = 0x1;
static const Word TWCY_URUGUAY = 0x256;
static const Word TWCY_VANUATU = 0x411;
static const Shortint TWCY_VATICANCITY = 0x27;
static const Shortint TWCY_VENEZUELA = 0x3a;
static const Word TWCY_WAKE = 0x412;
static const Word TWCY_WALLISIS = 0x413;
static const Word TWCY_WESTERNSAHARA = 0x414;
static const Word TWCY_WESTERNSAMOA = 0x415;
static const Word TWCY_YEMEN = 0x416;
static const Shortint TWCY_YUGOSLAVIA = 0x26;
static const Byte TWCY_ZAIRE = 0xf3;
static const Word TWCY_ZAMBIA = 0x104;
static const Word TWCY_ZIMBABWE = 0x107;
static const Word TWCY_ALBANIA = 0x163;
static const Word TWCY_ARMENIA = 0x176;
static const Word TWCY_AZERBAIJAN = 0x3e2;
static const Word TWCY_BELARUS = 0x177;
static const Word TWCY_BOSNIAHERZGO = 0x183;
static const Word TWCY_CAMBODIA = 0x357;
static const Word TWCY_CROATIA = 0x181;
static const Word TWCY_CZECHREPUBLIC = 0x1a4;
static const Byte TWCY_DIEGOGARCIA = 0xf6;
static const Word TWCY_ERITREA = 0x123;
static const Word TWCY_ESTONIA = 0x174;
static const Word TWCY_GEORGIA = 0x3e3;
static const Word TWCY_LATVIA = 0x173;
static const Word TWCY_LESOTHO = 0x10a;
static const Word TWCY_LITHUANIA = 0x172;
static const Word TWCY_MACEDONIA = 0x185;
static const Word TWCY_MAYOTTEIS = 0x10d;
static const Word TWCY_MOLDOVA = 0x175;
static const Shortint TWCY_MYANMAR = 0x5f;
static const Word TWCY_NORTHKOREA = 0x352;
static const Word TWCY_PUERTORICO = 0x313;
static const Shortint TWCY_RUSSIA = 0x7;
static const Word TWCY_SERBIA = 0x17d;
static const Word TWCY_SLOVAKIA = 0x1a5;
static const Word TWCY_SLOVENIA = 0x182;
static const Shortint TWCY_SOUTHKOREA = 0x52;
static const Word TWCY_UKRAINE = 0x17c;
static const Word TWCY_USVIRGINIS = 0x154;
static const Shortint TWCY_VIETNAM = 0x54;
static const Shortint TWLG_DAN = 0x0;
static const Shortint TWLG_DUT = 0x1;
static const Shortint TWLG_ENG = 0x2;
static const Shortint TWLG_FCF = 0x3;
static const Shortint TWLG_FIN = 0x4;
static const Shortint TWLG_FRN = 0x5;
static const Shortint TWLG_GER = 0x6;
static const Shortint TWLG_ICE = 0x7;
static const Shortint TWLG_ITN = 0x8;
static const Shortint TWLG_NOR = 0x9;
static const Shortint TWLG_POR = 0xa;
static const Shortint TWLG_SPA = 0xb;
static const Shortint TWLG_SWE = 0xc;
static const Shortint TWLG_USA = 0xd;
static const Shortint TWLG_USERLOCALE = 0xffffffff;
static const Shortint TWLG_AFRIKAANS = 0xe;
static const Shortint TWLG_ALBANIA = 0xf;
static const Shortint TWLG_ARABIC = 0x10;
static const Shortint TWLG_ARABIC_ALGERIA = 0x11;
static const Shortint TWLG_ARABIC_BAHRAIN = 0x12;
static const Shortint TWLG_ARABIC_EGYPT = 0x13;
static const Shortint TWLG_ARABIC_IRAQ = 0x14;
static const Shortint TWLG_ARABIC_JORDAN = 0x15;
static const Shortint TWLG_ARABIC_KUWAIT = 0x16;
static const Shortint TWLG_ARABIC_LEBANON = 0x17;
static const Shortint TWLG_ARABIC_LIBYA = 0x18;
static const Shortint TWLG_ARABIC_MOROCCO = 0x19;
static const Shortint TWLG_ARABIC_OMAN = 0x1a;
static const Shortint TWLG_ARABIC_QATAR = 0x1b;
static const Shortint TWLG_ARABIC_SAUDIARABIA = 0x1c;
static const Shortint TWLG_ARABIC_SYRIA = 0x1d;
static const Shortint TWLG_ARABIC_TUNISIA = 0x1e;
static const Shortint TWLG_ARABIC_UAE = 0x1f;
static const Shortint TWLG_ARABIC_YEMEN = 0x20;
static const Shortint TWLG_BASQUE = 0x21;
static const Shortint TWLG_BYELORUSSIAN = 0x22;
static const Shortint TWLG_BULGARIAN = 0x23;
static const Shortint TWLG_CATALAN = 0x24;
static const Shortint TWLG_CHINESE = 0x25;
static const Shortint TWLG_CHINESE_HONGKONG = 0x26;
static const Shortint TWLG_CHINESE_PRC = 0x27;
static const Shortint TWLG_CHINESE_SINGAPORE = 0x28;
static const Shortint TWLG_CHINESE_SIMPLIFIED = 0x29;
static const Shortint TWLG_CHINESE_TAIWAN = 0x2a;
static const Shortint TWLG_CHINESE_TRADITIONAL = 0x2b;
static const Shortint TWLG_CROATIA = 0x2c;
static const Shortint TWLG_CZECH = 0x2d;
static const Shortint TWLG_DANISH = 0x0;
static const Shortint TWLG_DUTCH = 0x1;
static const Shortint TWLG_DUTCH_BELGIAN = 0x2e;
static const Shortint TWLG_ENGLISH = 0x2;
static const Shortint TWLG_ENGLISH_AUSTRALIAN = 0x2f;
static const Shortint TWLG_ENGLISH_CANADIAN = 0x30;
static const Shortint TWLG_ENGLISH_IRELAND = 0x31;
static const Shortint TWLG_ENGLISH_NEWZEALAND = 0x32;
static const Shortint TWLG_ENGLISH_SOUTHAFRICA = 0x33;
static const Shortint TWLG_ENGLISH_UK = 0x34;
static const Shortint TWLG_ENGLISH_USA = 0xd;
static const Shortint TWLG_ESTONIAN = 0x35;
static const Shortint TWLG_FAEROESE = 0x36;
static const Shortint TWLG_FARSI = 0x37;
static const Shortint TWLG_FINNISH = 0x4;
static const Shortint TWLG_FRENCH = 0x5;
static const Shortint TWLG_FRENCH_BELGIAN = 0x38;
static const Shortint TWLG_FRENCH_CANADIAN = 0x3;
static const Shortint TWLG_FRENCH_LUXEMBOURG = 0x39;
static const Shortint TWLG_FRENCH_SWISS = 0x3a;
static const Shortint TWLG_GERMAN = 0x6;
static const Shortint TWLG_GERMAN_AUSTRIAN = 0x3b;
static const Shortint TWLG_GERMAN_LUXEMBOURG = 0x3c;
static const Shortint TWLG_GERMAN_LIECHTENSTEIN = 0x3d;
static const Shortint TWLG_GERMAN_SWISS = 0x3e;
static const Shortint TWLG_GREEK = 0x3f;
static const Shortint TWLG_HEBREW = 0x40;
static const Shortint TWLG_HUNGARIAN = 0x41;
static const Shortint TWLG_ICELANDIC = 0x7;
static const Shortint TWLG_INDONESIAN = 0x42;
static const Shortint TWLG_ITALIAN = 0x8;
static const Shortint TWLG_ITALIAN_SWISS = 0x43;
static const Shortint TWLG_JAPANESE = 0x44;
static const Shortint TWLG_KOREAN = 0x45;
static const Shortint TWLG_KOREAN_JOHAB = 0x46;
static const Shortint TWLG_LATVIAN = 0x47;
static const Shortint TWLG_LITHUANIAN = 0x48;
static const Shortint TWLG_NORWEGIAN = 0x9;
static const Shortint TWLG_NORWEGIAN_BOKMAL = 0x49;
static const Shortint TWLG_NORWEGIAN_NYNORSK = 0x4a;
static const Shortint TWLG_POLISH = 0x4b;
static const Shortint TWLG_PORTUGUESE = 0xa;
static const Shortint TWLG_PORTUGUESE_BRAZIL = 0x4c;
static const Shortint TWLG_ROMANIAN = 0x4d;
static const Shortint TWLG_RUSSIAN = 0x4e;
static const Shortint TWLG_SERBIAN_LATIN = 0x4f;
static const Shortint TWLG_SLOVAK = 0x50;
static const Shortint TWLG_SLOVENIAN = 0x51;
static const Shortint TWLG_SPANISH = 0xb;
static const Shortint TWLG_SPANISH_MEXICAN = 0x52;
static const Shortint TWLG_SPANISH_MODERN = 0x53;
static const Shortint TWLG_SWEDISH = 0xc;
static const Shortint TWLG_THAI = 0x54;
static const Shortint TWLG_TURKISH = 0x55;
static const Shortint TWLG_UKRANIAN = 0x56;
static const Shortint TWLG_ASSAMESE = 0x57;
static const Shortint TWLG_BENGALI = 0x58;
static const Shortint TWLG_BIHARI = 0x59;
static const Shortint TWLG_BODO = 0x5a;
static const Shortint TWLG_DOGRI = 0x5b;
static const Shortint TWLG_GUJARATI = 0x5c;
static const Shortint TWLG_HARYANVI = 0x5d;
static const Shortint TWLG_HINDI = 0x5e;
static const Shortint TWLG_KANNADA = 0x5f;
static const Shortint TWLG_KASHMIRI = 0x60;
static const Shortint TWLG_MALAYALAM = 0x61;
static const Shortint TWLG_MARATHI = 0x62;
static const Shortint TWLG_MARWARI = 0x63;
static const Shortint TWLG_MEGHALAYAN = 0x64;
static const Shortint TWLG_MIZO = 0x65;
static const Shortint TWLG_NAGA = 0x66;
static const Shortint TWLG_ORISSI = 0x67;
static const Shortint TWLG_PUNJABI = 0x68;
static const Shortint TWLG_PUSHTU = 0x69;
static const Shortint TWLG_SERBIAN_CYRILLIC = 0x6a;
static const Shortint TWLG_SIKKIMI = 0x6b;
static const Shortint TWLG_SWEDISH_FINLAND = 0x6c;
static const Shortint TWLG_TAMIL = 0x6d;
static const Shortint TWLG_TELUGU = 0x6e;
static const Shortint TWLG_TRIPURI = 0x6f;
static const Shortint TWLG_URDU = 0x70;
static const Shortint TWLG_VIETNAMESE = 0x71;
static const Shortint DG_CONTROL = 0x1;
static const Shortint DG_IMAGE = 0x2;
static const Shortint DG_AUDIO = 0x4;
static const Shortint DAT_NULL = 0x0;
static const Word DAT_CUSTOMBASE = 0x8000;
static const Shortint DAT_CAPABILITY = 0x1;
static const Shortint DAT_EVENT = 0x2;
static const Shortint DAT_IDENTITY = 0x3;
static const Shortint DAT_PARENT = 0x4;
static const Shortint DAT_PENDINGXFERS = 0x5;
static const Shortint DAT_SETUPMEMXFER = 0x6;
static const Shortint DAT_SETUPFILEXFER = 0x7;
static const Shortint DAT_STATUS = 0x8;
static const Shortint DAT_USERINTERFACE = 0x9;
static const Shortint DAT_XFERGROUP = 0xa;
static const Shortint DAT_TWUNKIDENTITY = 0xb;
static const Shortint DAT_CUSTOMDSDATA = 0xc;
static const Shortint DAT_DEVICEEVENT = 0xd;
static const Shortint DAT_FILESYSTEM = 0xe;
static const Shortint DAT_PASSTHRU = 0xf;
static const Word DAT_IMAGEINFO = 0x101;
static const Word DAT_IMAGELAYOUT = 0x102;
static const Word DAT_IMAGEMEMXFER = 0x103;
static const Word DAT_IMAGENATIVEXFER = 0x104;
static const Word DAT_IMAGEFILEXFER = 0x105;
static const Word DAT_CIECOLOR = 0x106;
static const Word DAT_GRAYRESPONSE = 0x107;
static const Word DAT_RGBRESPONSE = 0x108;
static const Word DAT_JPEGCOMPRESSION = 0x109;
static const Word DAT_PALETTE8 = 0x10a;
static const Word DAT_EXTIMAGEINFO = 0x10b;
static const Word DAT_AUDIOFILEXFER = 0x201;
static const Word DAT_AUDIOINFO = 0x202;
static const Word DAT_AUDIONATIVEXFER = 0x203;
static const Word DAT_SETUPFILEXFER2 = 0x301;
static const Shortint MSG_NULL = 0x0;
static const Word MSG_CUSTOMBASE = 0x8000;
static const Shortint MSG_GET = 0x1;
static const Shortint MSG_GETCURRENT = 0x2;
static const Shortint MSG_GETDEFAULT = 0x3;
static const Shortint MSG_GETFIRST = 0x4;
static const Shortint MSG_GETNEXT = 0x5;
static const Shortint MSG_SET = 0x6;
static const Shortint MSG_RESET = 0x7;
static const Shortint MSG_QUERYSUPPORT = 0x8;
static const Word MSG_XFERREADY = 0x101;
static const Word MSG_CLOSEDSREQ = 0x102;
static const Word MSG_CLOSEDSOK = 0x103;
static const Word MSG_DEVICEEVENT = 0x104;
static const Word MSG_CHECKSTATUS = 0x201;
static const Word MSG_OPENDSM = 0x301;
static const Word MSG_CLOSEDSM = 0x302;
static const Word MSG_OPENDS = 0x401;
static const Word MSG_CLOSEDS = 0x402;
static const Word MSG_USERSELECT = 0x403;
static const Word MSG_DISABLEDS = 0x501;
static const Word MSG_ENABLEDS = 0x502;
static const Word MSG_ENABLEDSUIONLY = 0x503;
static const Word MSG_PROCESSEVENT = 0x601;
static const Word MSG_ENDXFER = 0x701;
static const Word MSG_STOPFEEDER = 0x702;
static const Word MSG_CHANGEDIRECTORY = 0x801;
static const Word MSG_CREATEDIRECTORY = 0x802;
static const Word MSG_DELETE = 0x803;
static const Word MSG_FORMATMEDIA = 0x804;
static const Word MSG_GETCLOSE = 0x805;
static const Word MSG_GETFIRSTFILE = 0x806;
static const Word MSG_GETINFO = 0x807;
static const Word MSG_GETNEXTFILE = 0x808;
static const Word MSG_RENAME = 0x809;
static const Word MSG_COPY = 0x80a;
static const Word MSG_AUTOMATICCAPTUREDIRECTORY = 0x80b;
static const Word MSG_PASSTHRU = 0x901;
static const Word CAP_CUSTOMBASE = 0x8000;
static const Shortint CAP_XFERCOUNT = 0x1;
static const Word ICAP_COMPRESSION = 0x100;
static const Word ICAP_PIXELTYPE = 0x101;
static const Word ICAP_UNITS = 0x102;
static const Word ICAP_XFERMECH = 0x103;
static const Word CAP_AUTHOR = 0x1000;
static const Word CAP_CAPTION = 0x1001;
static const Word CAP_FEEDERENABLED = 0x1002;
static const Word CAP_FEEDERLOADED = 0x1003;
static const Word CAP_TIMEDATE = 0x1004;
static const Word CAP_SUPPORTEDCAPS = 0x1005;
static const Word CAP_EXTENDEDCAPS = 0x1006;
static const Word CAP_AUTOFEED = 0x1007;
static const Word CAP_CLEARPAGE = 0x1008;
static const Word CAP_FEEDPAGE = 0x1009;
static const Word CAP_REWINDPAGE = 0x100a;
static const Word CAP_INDICATORS = 0x100b;
static const Word CAP_SUPPORTEDCAPSEXT = 0x100c;
static const Word CAP_PAPERDETECTABLE = 0x100d;
static const Word CAP_UICONTROLLABLE = 0x100e;
static const Word CAP_DEVICEONLINE = 0x100f;
static const Word CAP_AUTOSCAN = 0x1010;
static const Word CAP_THUMBNAILSENABLED = 0x1011;
static const Word CAP_DUPLEX = 0x1012;
static const Word CAP_DUPLEXENABLED = 0x1013;
static const Word CAP_ENABLEDSUIONLY = 0x1014;
static const Word CAP_CUSTOMDSDATA = 0x1015;
static const Word CAP_ENDORSER = 0x1016;
static const Word CAP_JOBCONTROL = 0x1017;
static const Word CAP_ALARMS = 0x1018;
static const Word CAP_ALARMVOLUME = 0x1019;
static const Word CAP_AUTOMATICCAPTURE = 0x101a;
static const Word CAP_TIMEBEFOREFIRSTCAPTURE = 0x101b;
static const Word CAP_TIMEBETWEENCAPTURES = 0x101c;
static const Word CAP_CLEARBUFFERS = 0x101d;
static const Word CAP_MAXBATCHBUFFERS = 0x101e;
static const Word CAP_DEVICETIMEDATE = 0x101f;
static const Word CAP_POWERSUPPLY = 0x1020;
static const Word CAP_CAMERAPREVIEWUI = 0x1021;
static const Word CAP_DEVICEEVENT = 0x1022;
static const Word CAP_SERIALNUMBER = 0x1024;
static const Word CAP_PRINTER = 0x1026;
static const Word CAP_PRINTERENABLED = 0x1027;
static const Word CAP_PRINTERINDEX = 0x1028;
static const Word CAP_PRINTERMODE = 0x1029;
static const Word CAP_PRINTERSTRING = 0x102a;
static const Word CAP_PRINTERSUFFIX = 0x102b;
static const Word CAP_LANGUAGE = 0x102c;
static const Word CAP_FEEDERALIGNMENT = 0x102d;
static const Word CAP_FEEDERORDER = 0x102e;
static const Word CAP_REACQUIREALLOWED = 0x1030;
static const Word CAP_BATTERYMINUTES = 0x1032;
static const Word CAP_BATTERYPERCENTAGE = 0x1033;
static const Word ICAP_AUTOBRIGHT = 0x1100;
static const Word ICAP_BRIGHTNESS = 0x1101;
static const Word ICAP_CONTRAST = 0x1103;
static const Word ICAP_CUSTHALFTONE = 0x1104;
static const Word ICAP_EXPOSURETIME = 0x1105;
static const Word ICAP_FILTER = 0x1106;
static const Word ICAP_FLASHUSED = 0x1107;
static const Word ICAP_GAMMA = 0x1108;
static const Word ICAP_HALFTONES = 0x1109;
static const Word ICAP_HIGHLIGHT = 0x110a;
static const Word ICAP_IMAGEFILEFORMAT = 0x110c;
static const Word ICAP_LAMPSTATE = 0x110d;
static const Word ICAP_LIGHTSOURCE = 0x110e;
static const Word ICAP_ORIENTATION = 0x1110;
static const Word ICAP_PHYSICALWIDTH = 0x1111;
static const Word ICAP_PHYSICALHEIGHT = 0x1112;
static const Word ICAP_SHADOW = 0x1113;
static const Word ICAP_FRAMES = 0x1114;
static const Word ICAP_XNATIVERESOLUTION = 0x1116;
static const Word ICAP_YNATIVERESOLUTION = 0x1117;
static const Word ICAP_XRESOLUTION = 0x1118;
static const Word ICAP_YRESOLUTION = 0x1119;
static const Word ICAP_MAXFRAMES = 0x111a;
static const Word ICAP_TILES = 0x111b;
static const Word ICAP_BITORDER = 0x111c;
static const Word ICAP_CCITTKFACTOR = 0x111d;
static const Word ICAP_LIGHTPATH = 0x111e;
static const Word ICAP_PIXELFLAVOR = 0x111f;
static const Word ICAP_PLANARCHUNKY = 0x1120;
static const Word ICAP_ROTATION = 0x1121;
static const Word ICAP_SUPPORTEDSIZES = 0x1122;
static const Word ICAP_THRESHOLD = 0x1123;
static const Word ICAP_XSCALING = 0x1124;
static const Word ICAP_YSCALING = 0x1125;
static const Word ICAP_BITORDERCODES = 0x1126;
static const Word ICAP_PIXELFLAVORCODES = 0x1127;
static const Word ICAP_JPEGPIXELTYPE = 0x1128;
static const Word ICAP_TIMEFILL = 0x112a;
static const Word ICAP_BITDEPTH = 0x112b;
static const Word ICAP_BITDEPTHREDUCTION = 0x112c;
static const Word ICAP_UNDEFINEDIMAGESIZE = 0x112d;
static const Word ICAP_IMAGEDATASET = 0x112e;
static const Word ICAP_EXTIMAGEINFO = 0x112f;
static const Word ICAP_MINIMUMHEIGHT = 0x1130;
static const Word ICAP_MINIMUMWIDTH = 0x1131;
static const Word ICAP_FLIPROTATION = 0x1136;
static const Word ICAP_BARCODEDETECTIONENABLED = 0x1137;
static const Word ICAP_SUPPORTEDBARCODETYPES = 0x1138;
static const Word ICAP_BARCODEMAXSEARCHPRIORITIES = 0x1139;
static const Word ICAP_BARCODESEARCHPRIORITIES = 0x113a;
static const Word ICAP_BARCODESEARCHMODE = 0x113b;
static const Word ICAP_BARCODEMAXRETRIES = 0x113c;
static const Word ICAP_BARCODETIMEOUT = 0x113d;
static const Word ICAP_ZOOMFACTOR = 0x113e;
static const Word ICAP_PATCHCODEDETECTIONENABLED = 0x113f;
static const Word ICAP_SUPPORTEDPATCHCODETYPES = 0x1140;
static const Word ICAP_PATCHCODEMAXSEARCHPRIORITIES = 0x1141;
static const Word ICAP_PATCHCODESEARCHPRIORITIES = 0x1142;
static const Word ICAP_PATCHCODESEARCHMODE = 0x1143;
static const Word ICAP_PATCHCODEMAXRETRIES = 0x1144;
static const Word ICAP_PATCHCODETIMEOUT = 0x1145;
static const Word ICAP_FLASHUSED2 = 0x1146;
static const Word ICAP_IMAGEFILTER = 0x1147;
static const Word ICAP_NOISEFILTER = 0x1148;
static const Word ICAP_OVERSCAN = 0x1149;
static const Word ICAP_AUTOMATICBORDERDETECTION = 0x1150;
static const Word ICAP_AUTOMATICDESKEW = 0x1151;
static const Word ICAP_AUTOMATICROTATE = 0x1152;
static const Word ICAP_JPEGQUALITY = 0x1153;
static const Word ACAP_AUDIOFILEFORMAT = 0x1201;
static const Word ACAP_XFERMECH = 0x1202;
static const Word TWEI_BARCODEX = 0x1200;
static const Word TWEI_BARCODEY = 0x1201;
static const Word TWEI_BARCODETEXT = 0x1202;
static const Word TWEI_BARCODETYPE = 0x1203;
static const Word TWEI_DESHADETOP = 0x1204;
static const Word TWEI_DESHADELEFT = 0x1205;
static const Word TWEI_DESHADEHEIGHT = 0x1206;
static const Word TWEI_DESHADEWIDTH = 0x1207;
static const Word TWEI_DESHADESIZE = 0x1208;
static const Word TWEI_SPECKLESREMOVED = 0x1209;
static const Word TWEI_HORZLINEXCOORD = 0x120a;
static const Word TWEI_HORZLINEYCOORD = 0x120b;
static const Word TWEI_HORZLINELENGTH = 0x120c;
static const Word TWEI_HORZLINETHICKNESS = 0x120d;
static const Word TWEI_VERTLINEXCOORD = 0x120e;
static const Word TWEI_VERTLINEYCOORD = 0x120f;
static const Word TWEI_VERTLINELENGTH = 0x1210;
static const Word TWEI_VERTLINETHICKNESS = 0x1211;
static const Word TWEI_PATCHCODE = 0x1212;
static const Word TWEI_ENDORSEDTEXT = 0x1213;
static const Word TWEI_FORMCONFIDENCE = 0x1214;
static const Word TWEI_FORMTEMPLATEMATCH = 0x1215;
static const Word TWEI_FORMTEMPLATEPAGEMATCH = 0x1216;
static const Word TWEI_FORMHORZDOCOFFSET = 0x1217;
static const Word TWEI_FORMVERTDOCOFFSET = 0x1218;
static const Word TWEI_BARCODECOUNT = 0x1219;
static const Word TWEI_BARCODECONFIDENCE = 0x121a;
static const Word TWEI_BARCODEROTATION = 0x121b;
static const Word TWEI_BARCODETEXTLENGTH = 0x121c;
static const Word TWEI_DESHADECOUNT = 0x121d;
static const Word TWEI_DESHADEBLACKCOUNTOLD = 0x121e;
static const Word TWEI_DESHADEBLACKCOUNTNEW = 0x121f;
static const Word TWEI_DESHADEBLACKRLMIN = 0x1220;
static const Word TWEI_DESHADEBLACKRLMAX = 0x1221;
static const Word TWEI_DESHADEWHITECOUNTOLD = 0x1222;
static const Word TWEI_DESHADEWHITECOUNTNEW = 0x1223;
static const Word TWEI_DESHADEWHITERLMIN = 0x1224;
static const Word TWEI_DESHADEWHITERLAVE = 0x1225;
static const Word TWEI_DESHADEWHITERLMAX = 0x1226;
static const Word TWEI_BLACKSPECKLESREMOVED = 0x1227;
static const Word TWEI_WHITESPECKLESREMOVED = 0x1228;
static const Word TWEI_HORZLINECOUNT = 0x1229;
static const Word TWEI_VERTLINECOUNT = 0x122a;
static const Word TWEI_DESKEWSTATUS = 0x122b;
static const Word TWEI_SKEWORIGINALANGLE = 0x122c;
static const Word TWEI_SKEWFINALANGLE = 0x122d;
static const Word TWEI_SKEWCONFIDENCE = 0x122e;
static const Word TWEI_SKEWWINDOWX1 = 0x122f;
static const Word TWEI_SKEWWINDOWY1 = 0x1230;
static const Word TWEI_SKEWWINDOWX2 = 0x1231;
static const Word TWEI_SKEWWINDOWY2 = 0x1232;
static const Word TWEI_SKEWWINDOWX3 = 0x1233;
static const Word TWEI_SKEWWINDOWY3 = 0x1234;
static const Word TWEI_SKEWWINDOWX4 = 0x1235;
static const Word TWEI_SKEWWINDOWY4 = 0x1236;
static const Word TWEI_BOOKNAME = 0x1238;
static const Word TWEI_CHAPTERNUMBER = 0x1239;
static const Word TWEI_DOCUMENTNUMBER = 0x123a;
static const Word TWEI_PAGENUMBER = 0x123b;
static const Word TWEI_CAMERA = 0x123c;
static const Word TWEI_FRAMENUMBER = 0x123d;
static const Word TWEI_FRAME = 0x123e;
static const Word TWEI_PIXELFLAVOR = 0x123f;
static const Shortint TWEJ_NONE = 0x0;
static const Shortint TWEJ_MIDSEPARATOR = 0x1;
static const Shortint TWEJ_PATCH1 = 0x2;
static const Shortint TWEJ_PATCH2 = 0x3;
static const Shortint TWEJ_PATCH3 = 0x4;
static const Shortint TWEJ_PATCH4 = 0x5;
static const Shortint TWEJ_PATCH6 = 0x6;
static const Shortint TWEJ_PATCHT = 0x7;
static const Shortint TWDR_GET = 0x1;
static const Shortint TWDR_SET = 0x2;
static const Word TWRC_CUSTOMBASE = 0x8000;
static const Shortint TWRC_SUCCESS = 0x0;
static const Shortint TWRC_FAILURE = 0x1;
static const Shortint TWRC_CHECKSTATUS = 0x2;
static const Shortint TWRC_CANCEL = 0x3;
static const Shortint TWRC_DSEVENT = 0x4;
static const Shortint TWRC_NOTDSEVENT = 0x5;
static const Shortint TWRC_XFERDONE = 0x6;
static const Shortint TWRC_ENDOFLIST = 0x7;
static const Shortint TWRC_INFONOTSUPPORTED = 0x8;
static const Shortint TWRC_DATANOTAVAILABLE = 0x9;
static const Word TWCC_CUSTOMBASE = 0x8000;
static const Shortint TWCC_SUCCESS = 0x0;
static const Shortint TWCC_BUMMER = 0x1;
static const Shortint TWCC_LOWMEMORY = 0x2;
static const Shortint TWCC_NODS = 0x3;
static const Shortint TWCC_MAXCONNECTIONS = 0x4;
static const Shortint TWCC_OPERATIONERROR = 0x5;
static const Shortint TWCC_BADCAP = 0x6;
static const Shortint TWCC_BADPROTOCOL = 0x9;
static const Shortint TWCC_BADVALUE = 0xa;
static const Shortint TWCC_SEQERROR = 0xb;
static const Shortint TWCC_BADDEST = 0xc;
static const Shortint TWCC_CAPUNSUPPORTED = 0xd;
static const Shortint TWCC_CAPBADOPERATION = 0xe;
static const Shortint TWCC_CAPSEQERROR = 0xf;
static const Shortint TWCC_DENIED = 0x10;
static const Shortint TWCC_FILEEXISTS = 0x11;
static const Shortint TWCC_FILENOTFOUND = 0x12;
static const Shortint TWCC_NOTEMPTY = 0x13;
static const Shortint TWCC_PAPERJAM = 0x14;
static const Shortint TWCC_PAPERDOUBLEFEED = 0x15;
static const Shortint TWCC_FILEWRITEERROR = 0x16;
static const Shortint TWCC_CHECKDEVICEONLINE = 0x17;
static const Shortint TWQC_GET = 0x1;
static const Shortint TWQC_SET = 0x2;
static const Shortint TWQC_GETDEFAULT = 0x4;
static const Shortint TWQC_GETCURRENT = 0x8;
static const Shortint TWQC_RESET = 0x10;
extern PACKAGE DSMENTRYPROC DSM_Entry;
extern PACKAGE DSENTRYPROC DS_Entry;

}	/* namespace Ietwain */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ietwain;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ietwain
