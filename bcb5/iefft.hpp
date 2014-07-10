// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'iefft.pas' rev: 5.00

#ifndef iefftHPP
#define iefftHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iefft
{
//-- type declarations -------------------------------------------------------
typedef float TIEsinglearray[16385];

typedef float *PIEsinglearray;

typedef float *TIECOMPLEX_IMAGE[16385];

typedef PIEsinglearray *PIECOMPLEX_IMAGE;

typedef double *PIEdouble;

typedef int *PIEinteger;

typedef float *PIEsingle;

typedef int *PIElongint;

#pragma pack(push, 1)
struct TIEComplexColor
{
	float *real_Red;
	float *imag_Red;
	float *real_Blue;
	float *imag_Blue;
	float *real_Green;
	float *imag_Green;
	float *imag_gray;
	float *real_gray;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TIEComplex
{
	float real;
	float imag;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TIEFtImageType { ieitUnknown, ieitRGB, ieitGrayscale };
#pragma option pop

typedef unsigned tdwordarray[134217728];

typedef unsigned *pdwordarray;

typedef int tlongintarray[134217728];

typedef int *plongintarray;

class DELPHICLASS TIEFtImage;
class PASCALIMPLEMENTATION TIEFtImage : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	double *sintabpt;
	int *bittabpt;
	int *powers;
	int numpts;
	int nn;
	float direction;
	double scalef;
	int FFTN;
	bool NORMALIZE;
	PIEsinglearray *fftr;
	PIEsinglearray *fftg;
	PIEsinglearray *fftb;
	PIEsinglearray *fftgray;
	int fOX;
	int fOY;
	int fOrigBitmapWidth;
	int fOrigBitmapHeight;
	Hyiedefs::TIEProgressEvent fOnProgress;
	TIEFtImageType fImageType;
	void __fastcall image_fftoc(Hyieutils::TIEBitmap* image, PIECOMPLEX_IMAGE &output, int ch, Hyiedefs::TProgressRec 
		&Progress);
	void __fastcall fftx(Hyieutils::TIEBitmap* image, int oc, PIECOMPLEX_IMAGE &output, int ch, Hyiedefs::TProgressRec 
		&Progress);
	void __fastcall image_fftinv(PIECOMPLEX_IMAGE image, PIECOMPLEX_IMAGE &output, Hyiedefs::TProgressRec 
		&Progress);
	void __fastcall pairsort(PIEsinglearray arr, pdwordarray iarr, int n);
	void __fastcall fqsort(PIEsinglearray arr, pdwordarray iarr, int l, int r);
	void __fastcall fftinvx(PIECOMPLEX_IMAGE image, int oc, PIECOMPLEX_IMAGE &output, Hyiedefs::TProgressRec 
		&Progress);
	void __fastcall fft2d(PIECOMPLEX_IMAGE image, float direction, Hyiedefs::TProgressRec &Progress);
	void __fastcall filt_orig(PIECOMPLEX_IMAGE xarray);
	void __fastcall realtoint(PIECOMPLEX_IMAGE fim, plongintarray H);
	void __fastcall fft(PIEsinglearray data, float dir);
	void __fastcall _fft(PIEsinglearray tseries, int level, int chunk);
	void __fastcall fftinit(int nopts);
	int __fastcall bitrev(int bits);
	PIECOMPLEX_IMAGE __fastcall newcomplex(Hyieutils::TIEBitmap* im, int ch);
	PIECOMPLEX_IMAGE __fastcall dupcomplex(PIECOMPLEX_IMAGE im);
	void __fastcall filt_toint(PIECOMPLEX_IMAGE oimage, Hyieutils::TIEBitmap* output, int ch);
	TIEComplexColor __fastcall GetComplexImage(int x, int y);
	
protected:
	void __fastcall FreeAll(void);
	
public:
	__fastcall TIEFtImage(void);
	__fastcall virtual ~TIEFtImage(void);
	void __fastcall BuildFT(Hyieutils::TIEBitmap* fOrigBitmap, TIEFtImageType ImageType);
	void __fastcall BuildBitmap(Hyieutils::TIEBitmap* Bitmap);
	void __fastcall GetFTImage(Hyieutils::TIEBitmap* Bitmap);
	void __fastcall HiPass(int radius);
	void __fastcall LoPass(int radius);
	void __fastcall ClearZone(int x1, int y1, int x2, int y2);
	__property TIEComplexColor ComplexPixel[int x][int y] = {read=GetComplexImage};
	__property TIEFtImageType Imagetype = {read=fImageType, nodefault};
	__property int ComplexWidth = {read=FFTN, nodefault};
	__property int ComplexHeight = {read=FFTN, nodefault};
	void __fastcall Assign(TIEFtImage* Source);
	__property Hyiedefs::TIEProgressEvent OnProgress = {read=fOnProgress, write=fOnProgress};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iefft */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Iefft;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// iefft
