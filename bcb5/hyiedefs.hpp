// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'hyiedefs.pas' rev: 5.00

#ifndef hyiedefsHPP
#define hyiedefsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Hyiedefs
{
//-- type declarations -------------------------------------------------------
struct TBitmapInfoHeader256;
typedef TBitmapInfoHeader256 *PBitmapInfoHeader256;

typedef Windows::TPoint TPointArray[134217728];

typedef Windows::TPoint *PPointArray;

struct TIEPoint
{
	int X;
	int Y;
} ;

typedef TIEPoint TIEPointArray[134217728];

typedef TIEPoint *PIEPointArray;

typedef void *TPointerArray[134217728];

typedef void * *PPointerArray;

typedef double TDoubleArray[134217728];

typedef double *PDoubleArray;

typedef unsigned TDWordArray[134217728];

typedef unsigned *PDWordArray;

typedef float tsinglearray[134217728];

typedef float *psinglearray;

struct TRGBA;
typedef TRGBA *PRGBA;

#pragma pack(push, 1)
struct TRGBA
{
	Byte b;
	Byte g;
	Byte r;
	Byte a;
} ;
#pragma pack(pop)

typedef TRGBA TIERGBAPalette[134217728];

typedef TRGBA *PIERGBAPalette;

struct TRGB;
typedef TRGB *PRGB;

#pragma pack(push, 1)
struct TRGB
{
	Byte b;
	Byte g;
	Byte r;
} ;
#pragma pack(pop)

typedef TRGB TIERGBPalette[134217728];

typedef TRGB *PIERGBPalette;

struct TCMYK;
typedef TCMYK *PCMYK;

struct TCIELab;
typedef TCIELab *PCIELAB;

#pragma pack(push, 1)
struct TCIELab
{
	Byte l;
	Shortint a;
	Shortint b;
} ;
#pragma pack(pop)

typedef TCIELab TCIELABROW[134217728];

typedef TCIELab *PCIELABROW;

#pragma pack(push, 1)
struct TCMYK
{
	Byte c;
	Byte m;
	Byte y;
	Byte k;
} ;
#pragma pack(pop)

typedef TCMYK TCMYKROW[134217728];

typedef TCMYK *PCMYKROW;

typedef TRGB RGBROW[134217728];

typedef TRGB *PRGBROW;

#pragma pack(push, 1)
struct TRGB48
{
	Word r;
	Word g;
	Word b;
} ;
#pragma pack(pop)

typedef TRGB48 TRGB48ROW[134217728];

typedef TRGB48 *PRGB48ROW;

typedef Byte TBYTEROW[134217728];

typedef Byte *PBYTEROW;

typedef Byte *TBYTEROWS[134217728];

typedef PBYTEROW *PBYTEROWS;

typedef int IntegerArray[134217728];

typedef int *pIntegerArray;

typedef TRGB *PRGBArray[134217728];

typedef PRGB *PPRGBArray;

typedef bool *pboolean;

struct TProgressRec;
typedef TProgressRec *PProgressRec;

typedef unsigned hDrawDib;

struct TDrawDibTime
{
	int timeCount;
	int timeDraw;
	int timeDecompress;
	int timeDither;
	int timeStretch;
	int timeBlt;
	int timeSetDIBits;
} ;

#pragma pack(push, 1)
struct TBitmapInfoHeader256
{
	unsigned biSize;
	int biWidth;
	int biHeight;
	Word biPlanes;
	Word biBitCount;
	unsigned biCompression;
	unsigned biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	unsigned biClrUsed;
	unsigned biClrImportant;
	tagRGBQUAD Palette[2];
} ;
#pragma pack(pop)

typedef TRGB48 *PRGB48;

struct TIELine
{
	Windows::TPoint P;
	Windows::TPoint Q;
} ;

typedef TIELine TIELineArray[8193];

typedef TIELine *PIELineArray;

struct T3dPoint
{
	double x;
	double y;
	double z;
} ;

typedef void __fastcall (__closure *TIEProgressEvent)(System::TObject* Sender, int per);

#pragma option push -b-
enum TIEJob { iejNOTHING, iejGENERALPROCESSING, iejVIDEOCAP_CONNECTING };
#pragma option pop

typedef void __fastcall (__closure *TIEJobEvent)(System::TObject* Sender, TIEJob job, int per);

struct TProgressRec
{
	TIEProgressEvent fOnProgress;
	System::TObject* Sender;
	int val;
	int tot;
	double per1;
	double per2;
	bool *Aborting;
} ;

#pragma option push -b-
enum TResampleFilter { rfNone, rfTriangle, rfHermite, rfBell, rfBSpline, rfLanczos3, rfMitchell, rfNearest, 
	rfLinear, rfFastLinear, rfBilinear, rfBicubic, rfProjectBW, rfProjectWB };
#pragma option pop

struct THYIEGraphicHeader
{
	Word Count;
	Word HType;
	int Size;
} ;

#pragma option push -b-
enum TMsgLanguage { msSystem, msEnglish, msItalian, msGerman, msSpanish, msFrench, msPortuguese, msGreek, 
	msRussian, msDutch, msSwedish, msPolish, msJapanese, msCzech, msUser };
#pragma option pop

#pragma option push -b-
enum TMsgLanguageWords { IEMSG_PREVIEW, IEMSG_SOURCE, IEMSG_RESULT, IEMSG_OK, IEMSG_CANCEL, IEMSG_LOCKPREVIEW, 
	IEMSG_COPYRESULTTOSOURCE, IEMSG_CONTRAST, IEMSG_BRIGHTNESS, IEMSG_HUE, IEMSG_SATURATION, IEMSG_VALUE, 
	IEMSG_BASECOLOR, IEMSG_NEWCOLOR, IEMSG_LUMINOSITY, IEMSG_RED, IEMSG_GREEN, IEMSG_BLUE, IEMSG_FILTERVALUES, 
	IEMSG_PRESETS, IEMSG_DIVISOR, IEMSG_LOAD, IEMSG_SAVE, IEMSG_EQUALIZATION, IEMSG_THRESHOLD, IEMSG_EQUALIZE, 
	IEMSG_HISTOGRAM, IEMSG_GRAY, IEMSG_LIGHT, IEMSG_LEFT, IEMSG_TOP, IEMSG_WIDTH, IEMSG_HEIGHT, IEMSG_COLOR, 
	IEMSG_SOURCEIMAGEQUANTITY, IEMSG_LENS, IEMSG_REFRACTION, IEMSG_PARAMETERSPREVIEW, IEMSG_QUALITY, IEMSG_DCTMETHOD, 
	IEMSG_SMOOTHINGFACTOR, IEMSG_GRAYSCALE, IEMSG_OPTIMALHUFFMAN, IEMSG_ORIGINALSIZE, IEMSG_COMPRESSEDSIZE, 
	IEMSG_ADVANCED, IEMSG_PROGRESSIVE, IEMSG_COMPRESSION, IEMSG_IMAGEINDEX, IEMSG_PHOTOMETRIC, IEMSG_SCANNDEDDOCUMENTINFO, 
	IEMSG_NAME, IEMSG_DESCRIPTION, IEMSG_PAGENAME, IEMSG_PAGENUMBER, IEMSG_OF, IEMSG_HORIZPOSITIONINCH, 
	IEMSG_VERTPOSITIONINCH, IEMSG_COLORS, IEMSG_TRANSPARENT, IEMSG_TRANSPARENTCOLOR, IEMSG_INTERLACED, 
	IEMSG_BACKGROUND, IEMSG_HORIZPOSITION, IEMSG_VERTPOSITION, IEMSG_DELAYTIME, IEMSG_FILTER, IEMSG_WAVE, 
	IEMSG_AMPLITUDE, IEMSG_WAVELENGTH, IEMSG_PHASE, IEMSG_REFLECTIVE, IEMSG_USERFILTER, IEMSG_MORPHFILTER, 
	IEMSG_WINDOWSIZE, IEMSG_MAXIMUM, IEMSG_MINIMUM, IEMSG_OPEN, IEMSG_CLOSE, IEMSG_ROTATE, IEMSG_FLIP, 
	IEMSG_FLIPHOR, IEMSG_FLIPVER, IEMSG_FREQUENCYDOMAINIMAGE, IEMSG_SELECTTHEREGIONTOCLEAR, IEMSG_CLEAR, 
	IEMSG_RESET, IEMSG_ANIMATE, IEMSG_LOADFILTER, IEMSG_SAVEFILTER, IEMSG_BUMPMAP, IEMSG_PRINT, IEMSG_MARGINS, 
	IEMSG_INCHES, IEMSG_RIGHT, IEMSG_BOTTOM, IEMSG_POSITION, IEMSG_SIZE, IEMSG_NORMAL, IEMSG_FITTOPAGE, 
	IEMSG_STRETCHTOPAGE, IEMSG_SPECIFIEDSIZE, IEMSG_GAMMACORRECTION, IEMSG_VALUE2, IEMSG_PRINTSETUP, IEMSG_LEFTMARGIN, 
	IEMSG_TOPMARGIN, IEMSG_RIGHTMARGIN, IEMSG_BOTTOMMARGIN, IEMSG_LOCATIONSIZE, IEMSG_TOPLEFT, IEMSG_TOPCENTER, 
	IEMSG_TOPRIGHT, IEMSG_CENTERLEFT, IEMSG_CENTER, IEMSG_CENTERRIGHT, IEMSG_BOTTOMLEFT, IEMSG_BOTTOMCENTER, 
	IEMSG_BOTTOMRIGHT, IEMSG_CLOSE2, IEMSG_APPLY, IEMSG_MEASUREUNITS, IEMSG_UNITS, IEMSG_RATE, IEMSG_ALLGRAPHICS, 
	IEMSG_VIDEOFORWINDOWS, IEMSG_FILE, IEMSG_MEM, IEMSG_LOCKPREVIEWHINT, IEMSG_PRINTALL, IEMSG_PRINTSELECTED, 
	IEMSG_COMMONGRAPHICFILES, IEMSG_ALLFILES };
#pragma option pop

typedef AnsiString hyiedefs__1[133];

typedef AnsiString hyiedefs__2[15][133];

//-- var, const, procedure ---------------------------------------------------
#define IEMAINVERSION "2.2.1"
static const Shortint IEMAINDATEDD = 0x8;
static const Shortint IEMAINDATEMM = 0xc;
static const Word IEMAINDATEYY = 0x7d5;
static const Word IEM_UPDATE = 0x1f58;
static const Word IEM_NEWFRAME = 0x1f59;
static const Word IEM_EVENT = 0x1f5a;
static const Word IEM_PROGRESS = 0x1f5b;
static const Word IEM_FINISHWORK = 0x1f5c;
static const int IESELBREAK = 0xfffff;
extern PACKAGE Word IETAGSIZE[12];
static const int IEBI_IYU1 = 0x31555949;
static const int IEBI_IYU2 = 0x32555949;
static const int IEBI_UYVY = 0x59565955;
static const int IEBI_UYNV = 0x564e5955;
static const int IEBI_cyuv = 0x76757963;
static const int IEBI_YUY2 = 0x32595559;
static const int IEBI_YUNV = 0x564e5559;
static const int IEBI_YVYU = 0x55595659;
static const int IEBI_Y41P = 0x50313459;
static const int IEBI_Y211 = 0x31313259;
static const int IEBI_Y41T = 0x54313459;
static const int IEBI_Y42T = 0x54323459;
static const int IEBI_CLJR = 0x524a4c43;
static const int IEBI_YVU9 = 0x39555659;
static const int IEBI_IF09 = 0x39304649;
static const int IEBI_YV12 = 0x32315659;
static const int IEBI_I420 = 0x30323449;
static const int IEBI_IYUV = 0x56555949;
static const int IEBI_CLPL = 0x4c504c43;
extern PACKAGE AnsiString ieMessages[15][133];
extern PACKAGE bool gAVIFILEinit;
extern PACKAGE _RTL_CRITICAL_SECTION gThreadCS;
extern PACKAGE int gRedToGrayCoef;
extern PACKAGE int gGreenToGrayCoef;
extern PACKAGE int gBlueToGrayCoef;
extern PACKAGE void __fastcall _ctrlview(Graphics::TCanvas* canvas);
extern PACKAGE void __fastcall _ctrlbmp(System::TObject* bmp);

}	/* namespace Hyiedefs */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Hyiedefs;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// hyiedefs
