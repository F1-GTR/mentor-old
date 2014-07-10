// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'pngfilt.pas' rev: 5.00

#ifndef pngfiltHPP
#define pngfiltHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <iezlib.hpp>	// Pascal unit
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

namespace Pngfilt
{
//-- type declarations -------------------------------------------------------
typedef unsigned png_uint_32;

typedef unsigned *png_uint_32p;

typedef int png_int_32;

typedef Word png_uint_16;

typedef short png_int_16;

typedef Byte png_byte;

typedef unsigned png_size_t;

typedef char * *png_charpp;

typedef char *png_charp;

typedef float float;

typedef int int;

typedef Byte *png_bytep;

typedef png_bytep *png_bytepp;

typedef Word *png_uint_16p;

typedef png_uint_16p *png_uint_16pp;

typedef void *png_voidp;

typedef int time_t;

typedef double *png_doublep;

typedef double png_double;

typedef void *user_error_ptr;

typedef void __fastcall (*png_error_ptr)(void * png_ptr, void * msg);

typedef png_error_ptr *png_error_ptrp;

typedef void __fastcall (*png_rw_ptr)(void * png_ptr, void * data, unsigned length);

typedef png_rw_ptr *png_rw_ptrp;

typedef void __fastcall (*png_flush_ptr)(void * png_ptr);

typedef png_flush_ptr *png_flush_ptrp;

typedef void __fastcall (*png_progressive_info_ptr)(void * png_ptr, void * info_ptr);

typedef png_progressive_info_ptr *png_progressive_info_ptrp;

typedef void __fastcall (*png_progressive_end_ptr)(void * png_ptr, void * info_ptr);

typedef png_progressive_end_ptr *png_progressive_end_ptrp;

typedef void __fastcall (*png_progressive_row_ptr)(void * png_ptr, void * data, unsigned length, int 
	count);

typedef png_progressive_row_ptr *png_progressive_row_ptrp;

typedef void __fastcall (*png_read_status_ptr)(void * png_ptr, unsigned row_number, int pass);

typedef void __fastcall (*png_write_status_ptr)(void * png_ptr, unsigned row_number, int pass);

typedef void __fastcall (*png_user_transform_ptr)(void * png_ptr, void * row_info, png_bytep data);

#pragma pack(push, 1)
struct png_color
{
	Byte red;
	Byte green;
	Byte blue;
} ;
#pragma pack(pop)

typedef png_color *png_colorp;

typedef png_colorp *png_colorpp;

#pragma pack(push, 1)
struct png_color_16
{
	Byte index;
	Word red;
	Word green;
	Word blue;
	Word gray;
} ;
#pragma pack(pop)

typedef png_color_16 *png_color_16p;

typedef png_color_16p *png_color_16pp;

#pragma pack(push, 1)
struct png_color_8
{
	Byte red;
	Byte green;
	Byte blue;
	Byte gray;
	Byte alpha;
} ;
#pragma pack(pop)

typedef png_color_8 *png_color_8p;

typedef png_color_8p *png_color_8pp;

#pragma pack(push, 1)
struct tpng_text
{
	int compression;
	char *key;
	char *text;
	unsigned text_length;
} ;
#pragma pack(pop)

typedef tpng_text *png_textp;

typedef png_textp *png_textpp;

#pragma pack(push, 1)
struct tpng_time
{
	Word year;
	Byte month;
	Byte day;
	Byte hour;
	Byte minute;
	Byte second;
} ;
#pragma pack(pop)

typedef tpng_time *png_timep;

typedef png_timep *png_timepp;

typedef void * *png_infopp;

typedef void *png_infop;

#pragma pack(push, 1)
struct png_row_info
{
	unsigned width;
	unsigned rowbytes;
	Byte color_type;
	Byte bit_depth;
	Byte channels;
	Byte pixel_depth;
} ;
#pragma pack(pop)

typedef png_row_info *png_row_infop;

typedef png_row_infop *png_row_infopp;

typedef void * *png_structpp;

typedef void *png_structp;

//-- var, const, procedure ---------------------------------------------------
static const Shortint PNG_TEXT_COMPRESSION_NONE_WR = 0xfffffffd;
static const Shortint PNG_TEXT_COMPRESSION_zTXt_WR = 0xfffffffe;
static const Shortint PNG_TEXT_COMPRESSION_NONE = 0xffffffff;
static const Shortint PNG_TEXT_COMPRESSION_zTXt = 0x0;
static const Shortint PNG_COLOR_MASK_PALETTE = 0x1;
static const Shortint PNG_COLOR_MASK_COLOR = 0x2;
static const Shortint PNG_COLOR_MASK_ALPHA = 0x4;
static const Shortint PNG_COLOR_TYPE_GRAY = 0x0;
static const Shortint PNG_COLOR_TYPE_PALETTE = 0x3;
static const Shortint PNG_COLOR_TYPE_RGB = 0x2;
static const Shortint PNG_COLOR_TYPE_RGB_ALPHA = 0x6;
static const Shortint PNG_COLOR_TYPE_GRAY_ALPHA = 0x4;
static const Shortint PNG_COMPRESSION_TYPE_BASE = 0x0;
static const Shortint PNG_COMPRESSION_TYPE_DEFAULT = 0x0;
static const Shortint PNG_FILTER_TYPE_BASE = 0x0;
static const Shortint PNG_FILTER_TYPE_DEFAULT = 0x0;
static const Shortint PNG_INTERLACE_NONE = 0x0;
static const Shortint PNG_INTERLACE_ADAM7 = 0x1;
static const Shortint PNG_OFFSET_PIXEL = 0x0;
static const Shortint PNG_OFFSET_MICROMETER = 0x1;
static const Shortint PNG_EQUATION_LINEAR = 0x0;
static const Shortint PNG_EQUATION_BASE_E = 0x1;
static const Shortint PNG_EQUATION_ARBITRARY = 0x2;
static const Shortint PNG_EQUATION_HYPERBOLIC = 0x3;
static const Shortint PNG_RESOLUTION_UNKNOWN = 0x0;
static const Shortint PNG_RESOLUTION_METER = 0x1;
static const Shortint PNG_sRGB_INTENT_SATURATION = 0x0;
static const Shortint PNG_sRGB_INTENT_PERCEPTUAL = 0x1;
static const Shortint PNG_sRGB_INTENT_ABSOLUTE = 0x2;
static const Shortint PNG_sRGB_INTENT_RELATIVE = 0x3;
static const Shortint PNG_BACKGROUND_GAMMA_UNKNOWN = 0x0;
static const Shortint PNG_BACKGROUND_GAMMA_SCREEN = 0x1;
static const Shortint PNG_BACKGROUND_GAMMA_FILE = 0x2;
static const Shortint PNG_BACKGROUND_GAMMA_UNIQUE = 0x3;
static const Shortint PNG_CRC_DEFAULT = 0x0;
static const Shortint PNG_CRC_ERROR_QUIT = 0x1;
static const Shortint PNG_CRC_WARN_DISCARD = 0x2;
static const Shortint PNG_CRC_WARN_USE = 0x3;
static const Shortint PNG_CRC_QUIET_USE = 0x4;
static const Shortint PNG_CRC_NO_CHANGE = 0x5;
static const Shortint PNG_NO_FILTERS = 0x0;
static const Shortint PNG_FILTER_NONE = 0x8;
static const Shortint PNG_FILTER_SUB = 0x10;
static const Shortint PNG_FILTER_UP = 0x20;
static const Shortint PNG_FILTER_AVG = 0x40;
static const Byte PNG_FILTER_PAETH = 0x80;
static const Byte PNG_ALL_FILTERS = 0xf8;
static const Shortint PNG_FILTER_VALUE_NONE = 0x0;
static const Shortint PNG_FILTER_VALUE_SUB = 0x1;
static const Shortint PNG_FILTER_VALUE_UP = 0x2;
static const Shortint PNG_FILTER_VALUE_AVG = 0x3;
static const Shortint PNG_FILTER_VALUE_PAETH = 0x4;
static const Shortint PNG_FILTER_HEURISTIC_DEFAULT = 0x0;
static const Shortint PNG_FILTER_HEURISTIC_UNWEIGHTED = 0x1;
static const Shortint PNG_FILTER_HEURISTIC_WEIGHTED = 0x2;
static const Shortint PNG_FILTER_HEURISTIC_LAST = 0x3;
extern PACKAGE void __fastcall ReadPNGStream(Classes::TStream* Stream, Hyieutils::TIEBitmap* Bitmap, 
	Imageenio::TIOParamsVals* &IOParams, Hyiedefs::TProgressRec &xProgress, bool Preview, Hyieutils::TIEMask* 
	&AlphaChannel, bool IgnoreAlpha);
extern PACKAGE bool __fastcall IsPNGStream(Classes::TStream* Stream);

}	/* namespace Pngfilt */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Pngfilt;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// pngfilt
