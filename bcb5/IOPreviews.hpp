// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'iopreviews.pas' rev: 5.00

#ifndef iopreviewsHPP
#define iopreviewsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Dialogs.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <imageen.hpp>	// Pascal unit
#include <imageenview.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
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

namespace Iopreviews
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfIOPreviews;
class PASCALIMPLEMENTATION TfIOPreviews : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button2;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheetJPEG1;
	Stdctrls::TLabel* Label23;
	Stdctrls::TLabel* Label24;
	Stdctrls::TLabel* Label25;
	Stdctrls::TEdit* Edit22;
	Comctrls::TTrackBar* TrackBar13;
	Stdctrls::TGroupBox* GroupBox5;
	Stdctrls::TLabel* Label26;
	Stdctrls::TLabel* Label27;
	Stdctrls::TCheckBox* CheckBox2;
	Stdctrls::TComboBox* ComboBox1;
	Stdctrls::TEdit* Edit23;
	Comctrls::TUpDown* UpDown11;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label4;
	Stdctrls::TCheckBox* CheckBox3;
	Stdctrls::TButton* Button3;
	Comctrls::TTabSheet* TabSheetTIFF1;
	Stdctrls::TLabel* Label5;
	Stdctrls::TComboBox* ComboBox2;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UpDown1;
	Stdctrls::TLabel* Label7;
	Stdctrls::TComboBox* ComboBox3;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label8;
	Stdctrls::TLabel* Label10;
	Stdctrls::TEdit* Edit2;
	Stdctrls::TEdit* Edit3;
	Stdctrls::TLabel* Label12;
	Stdctrls::TEdit* Edit4;
	Stdctrls::TLabel* Label13;
	Stdctrls::TEdit* Edit5;
	Stdctrls::TLabel* Label14;
	Stdctrls::TEdit* Edit6;
	Stdctrls::TLabel* Label15;
	Stdctrls::TEdit* Edit7;
	Stdctrls::TLabel* Label16;
	Stdctrls::TEdit* Edit8;
	Stdctrls::TLabel* Label19;
	Stdctrls::TComboBox* ComboBox4;
	Comctrls::TTabSheet* TabSheetGIF1;
	Stdctrls::TLabel* Label20;
	Stdctrls::TEdit* Edit9;
	Comctrls::TUpDown* UpDown2;
	Stdctrls::TLabel* Label21;
	Stdctrls::TComboBox* ComboBox5;
	Stdctrls::TLabel* Label34;
	Extctrls::TPanel* Panel3;
	Stdctrls::TCheckBox* CheckBox4;
	Stdctrls::TCheckBox* CheckBox5;
	Stdctrls::TLabel* Label35;
	Extctrls::TPanel* Panel4;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TEdit* Edit12;
	Stdctrls::TLabel* Label33;
	Stdctrls::TLabel* Label31;
	Stdctrls::TEdit* Edit10;
	Stdctrls::TLabel* Label32;
	Stdctrls::TEdit* Edit11;
	Stdctrls::TLabel* Label36;
	Comctrls::TTabSheet* TabSheetBMP1;
	Stdctrls::TLabel* Label37;
	Stdctrls::TComboBox* ComboBox6;
	Stdctrls::TLabel* Label38;
	Stdctrls::TComboBox* ComboBox7;
	Comctrls::TTabSheet* TabSheetPCX1;
	Stdctrls::TLabel* Label43;
	Stdctrls::TComboBox* ComboBox8;
	Stdctrls::TLabel* Label44;
	Stdctrls::TComboBox* ComboBox9;
	Comctrls::TTabSheet* TabSheetPNG1;
	Stdctrls::TLabel* Label49;
	Stdctrls::TComboBox* ComboBox10;
	Stdctrls::TLabel* Label54;
	Extctrls::TPanel* Panel1;
	Dialogs::TColorDialog* ColorDialog1;
	Stdctrls::TGroupBox* GroupBox3;
	Stdctrls::TLabel* Label55;
	Stdctrls::TComboBox* ComboBox11;
	Stdctrls::TCheckBox* CheckBox6;
	Stdctrls::TLabel* Label56;
	Stdctrls::TComboBox* ComboBox12;
	Extctrls::TPanel* Panel2;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Imageenview::TImageEnView* ImageEn1;
	Imageenview::TImageEnView* ImageEn2;
	Comctrls::TProgressBar* ProgressBar1;
	Stdctrls::TLabel* Label57;
	Stdctrls::TComboBox* ComboBox13;
	Comctrls::TTabSheet* TabSheetTGA1;
	Stdctrls::TLabel* Label62;
	Stdctrls::TComboBox* ComboBox14;
	Stdctrls::TLabel* Label63;
	Extctrls::TPanel* Panel5;
	Stdctrls::TCheckBox* CheckBox1;
	Stdctrls::TLabel* Label64;
	Stdctrls::TEdit* Edit13;
	Stdctrls::TLabel* Label65;
	Stdctrls::TEdit* Edit14;
	Stdctrls::TLabel* Label9;
	Stdctrls::TLabel* Label11;
	Stdctrls::TLabel* Label17;
	Stdctrls::TLabel* Label18;
	Stdctrls::TLabel* Label22;
	Stdctrls::TLabel* Label28;
	Stdctrls::TLabel* Label29;
	Stdctrls::TLabel* Label30;
	Stdctrls::TLabel* Label39;
	Stdctrls::TLabel* Label40;
	Stdctrls::TLabel* Label41;
	Stdctrls::TLabel* Label42;
	Stdctrls::TLabel* Label45;
	Stdctrls::TLabel* Label46;
	Stdctrls::TLabel* Label47;
	Stdctrls::TLabel* Label48;
	Stdctrls::TLabel* Label50;
	Stdctrls::TLabel* Label51;
	Stdctrls::TLabel* Label52;
	Stdctrls::TLabel* Label53;
	Stdctrls::TLabel* Label58;
	Stdctrls::TLabel* Label59;
	Stdctrls::TLabel* Label60;
	Stdctrls::TLabel* Label61;
	Stdctrls::TButton* Button4;
	Comctrls::TTabSheet* TabSheetJ20001;
	Stdctrls::TLabel* Label66;
	Stdctrls::TEdit* Edit15;
	Comctrls::TTrackBar* TrackBar1;
	Stdctrls::TLabel* Label67;
	Stdctrls::TLabel* Label68;
	Stdctrls::TLabel* Label69;
	Stdctrls::TLabel* Label70;
	Stdctrls::TLabel* Label71;
	Stdctrls::TComboBox* ComboBox15;
	Comctrls::TTabSheet* TabSheetJPEG2;
	Stdctrls::TLabel* Label72;
	Stdctrls::TEdit* Edit16;
	Comctrls::TTrackBar* TrackBar2;
	Stdctrls::TLabel* Label73;
	Stdctrls::TLabel* Label74;
	Stdctrls::TLabel* Label75;
	Stdctrls::TLabel* Label76;
	Comctrls::TTabSheet* TabSheetTIFF2;
	Stdctrls::TLabel* Label77;
	Stdctrls::TLabel* Label78;
	Stdctrls::TLabel* Label79;
	Stdctrls::TLabel* Label80;
	Stdctrls::TLabel* Label81;
	Stdctrls::TComboBox* ComboBox16;
	Stdctrls::TLabel* Label82;
	Stdctrls::TComboBox* ComboBox17;
	Comctrls::TTabSheet* TabSheetGIF2;
	Stdctrls::TLabel* Label83;
	Stdctrls::TLabel* Label84;
	Stdctrls::TLabel* Label85;
	Stdctrls::TLabel* Label86;
	Stdctrls::TLabel* Label87;
	Stdctrls::TComboBox* ComboBox18;
	Stdctrls::TCheckBox* chkLockPreview;
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall Edit22Change(System::TObject* Sender);
	void __fastcall TrackBar13Change(System::TObject* Sender);
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall ImageEn1ViewChange(System::TObject* Sender, int Change);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall ComboBox2Click(System::TObject* Sender);
	void __fastcall Panel3Click(System::TObject* Sender);
	void __fastcall Panel4Click(System::TObject* Sender);
	void __fastcall ComboBox5Click(System::TObject* Sender);
	void __fastcall ComboBox6Change(System::TObject* Sender);
	void __fastcall ComboBox8Change(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall ComboBox10Change(System::TObject* Sender);
	void __fastcall Panel1Click(System::TObject* Sender);
	void __fastcall PageControl1Changing(System::TObject* Sender, bool &AllowChange);
	void __fastcall ComboBox14Click(System::TObject* Sender);
	void __fastcall Panel5Click(System::TObject* Sender);
	void __fastcall Button4Click(System::TObject* Sender);
	void __fastcall Edit15Change(System::TObject* Sender);
	void __fastcall TrackBar1Change(System::TObject* Sender);
	void __fastcall Edit16Change(System::TObject* Sender);
	void __fastcall TrackBar2Change(System::TObject* Sender);
	void __fastcall ComboBox16Change(System::TObject* Sender);
	void __fastcall ComboBox18Change(System::TObject* Sender);
	void __fastcall ImageEn1Progress(System::TObject* Sender, int per);
	
private:
	Imageenio::TPreviewParams pp;
	AnsiString msgCancel;
	bool dochange;
	void __fastcall applyAct(void);
	bool __fastcall HasTIFFLZW(void);
	int __fastcall CompToCombo(Imageenio::TIOTIFFCompression v);
	Imageenio::TIOTIFFCompression __fastcall ComboToComp(int i);
	
public:
	bool fSimplified;
	Imageenio::TIOParamsVals* fParams;
	int JPEG_Quality;
	int JPEG_Photometric;
	int JPEG_DCTMethod;
	bool JPEG_OptimalHuffman;
	int JPEG_Smooth;
	bool JPEG_Progressive;
	double J2000_Rate;
	int J2000_ColorSpace;
	Imageenio::TIOTIFFCompression TIFF_Compression;
	int TIFF_ImageIndex;
	Imageenio::TIOTIFFPhotometInterpret TIFF_PhotometInterpret;
	int TIFF_XPos;
	int TIFF_YPos;
	AnsiString TIFF_DocumentName;
	AnsiString TIFF_ImageDescription;
	AnsiString TIFF_PageName;
	int TIFF_PageNumber;
	int TIFF_PageCount;
	int TIFF_BitsPerSample;
	int TIFF_SamplesPerPixel;
	Imageenio::TTIFFLZWDecompFunc TIFF_LZWDecompFunc;
	Imageenio::TTIFFLZWCompFunc TIFF_LZWCompFunc;
	int GIF_ImageIndex;
	int GIF_XPos;
	int GIF_YPos;
	int GIF_DelayTime;
	bool GIF_FlagTranspColor;
	#pragma pack(push, 1)
	Hyiedefs::TRGB GIF_TranspColor;
	#pragma pack(pop)
	
	bool GIF_Interlaced;
	#pragma pack(push, 1)
	Hyiedefs::TRGB GIF_Background;
	#pragma pack(pop)
	
	int GIF_BitsPerSample;
	Imageenio::TGIFLZWDecompFunc GIF_LZWDecompFunc;
	Imageenio::TGIFLZWCompFunc GIF_LZWCompFunc;
	Imageenio::TIOBMPCompression BMP_Compression;
	int BMP_BitsPerPixel;
	Imageenio::TIOPCXCompression PCX_Compression;
	int PCX_BitsPerPixel;
	int PNG_Colors;
	bool PNG_Interlaced;
	#pragma pack(push, 1)
	Hyiedefs::TRGB PNG_Background;
	#pragma pack(pop)
	
	int PNG_Filter;
	int PNG_Compression;
	int TGA_Colors;
	#pragma pack(push, 1)
	Hyiedefs::TRGB TGA_Background;
	#pragma pack(pop)
	
	bool TGA_Compressed;
	AnsiString TGA_Name;
	AnsiString TGA_Description;
	bool DefaultLockPreview;
	bool ars[8];
	int xper;
	int xdiv;
	Hyieutils::TIEDitherMethod fDefaultDitherMethod;
	bool fInitialized;
	void __fastcall SetLanguage(Hyiedefs::TMsgLanguage l);
	void __fastcall ApplyParameters(void);
	void __fastcall ResetParameters(void);
	bool __fastcall SetPreviewParams(Imageenio::TPreviewParams xpp);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TfIOPreviews(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfIOPreviews(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfIOPreviews(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TfIOPreviews(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iopreviews */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Iopreviews;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// iopreviews
