// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'previews.pas' rev: 5.00

#ifndef previewsHPP
#define previewsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Dialogs.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
#include <iefft.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <rulerbox.hpp>	// Pascal unit
#include <histogrambox.hpp>	// Pascal unit
#include <CheckLst.hpp>	// Pascal unit
#include <imageenview.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <hsvbox.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <imageen.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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

namespace Previews
{
//-- type declarations -------------------------------------------------------
typedef AnsiString previews__2[14];

class DELPHICLASS TfPreviews;
class PASCALIMPLEMENTATION TfPreviews : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button2;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Comctrls::TTabSheet* TabSheet3;
	Comctrls::TTabSheet* TabSheet4;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* Edit1;
	Comctrls::TTrackBar* TrackBar1;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* Edit3;
	Stdctrls::TEdit* Edit2;
	Stdctrls::TEdit* Edit4;
	Comctrls::TTrackBar* TrackBar2;
	Comctrls::TTrackBar* TrackBar3;
	Comctrls::TTrackBar* TrackBar5;
	Stdctrls::TLabel* Label7;
	Stdctrls::TLabel* Label8;
	Stdctrls::TLabel* Label9;
	Stdctrls::TEdit* Edit5;
	Stdctrls::TEdit* Edit6;
	Stdctrls::TEdit* Edit7;
	Comctrls::TTrackBar* TrackBar6;
	Comctrls::TTrackBar* TrackBar7;
	Comctrls::TTrackBar* TrackBar8;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TEdit* Edit8;
	Stdctrls::TEdit* Edit9;
	Stdctrls::TEdit* Edit10;
	Stdctrls::TEdit* Edit11;
	Stdctrls::TEdit* Edit12;
	Stdctrls::TEdit* Edit13;
	Stdctrls::TEdit* Edit14;
	Stdctrls::TEdit* Edit15;
	Stdctrls::TEdit* Edit16;
	Comctrls::TUpDown* UpDown1;
	Comctrls::TUpDown* UpDown2;
	Comctrls::TUpDown* UpDown3;
	Comctrls::TUpDown* UpDown4;
	Comctrls::TUpDown* UpDown5;
	Comctrls::TUpDown* UpDown6;
	Comctrls::TUpDown* UpDown7;
	Comctrls::TUpDown* UpDown8;
	Comctrls::TUpDown* UpDown9;
	Stdctrls::TGroupBox* GroupBox3;
	Stdctrls::TListBox* ListBox1;
	Stdctrls::TButton* Button6;
	Comctrls::TTabSheet* TabSheet5;
	Stdctrls::TLabel* Label10;
	Stdctrls::TLabel* Label11;
	Stdctrls::TLabel* Label12;
	Stdctrls::TEdit* Edit17;
	Stdctrls::TEdit* Edit18;
	Stdctrls::TEdit* Edit19;
	Comctrls::TTrackBar* TrackBar9;
	Comctrls::TTrackBar* TrackBar10;
	Comctrls::TTrackBar* TrackBar11;
	Stdctrls::TLabel* Label13;
	Stdctrls::TLabel* Label14;
	Extctrls::TPanel* Panel3;
	Extctrls::TPanel* Panel4;
	Stdctrls::TButton* Button4;
	Stdctrls::TButton* Button5;
	Dialogs::TOpenDialog* OpenDialog1;
	Dialogs::TSaveDialog* SaveDialog1;
	Stdctrls::TEdit* Edit20;
	Comctrls::TUpDown* UpDown10;
	Stdctrls::TLabel* Label15;
	Comctrls::TTabSheet* TabSheet6;
	Extctrls::TPanel* Panel5;
	Stdctrls::TGroupBox* GroupBox4;
	Checklst::TCheckListBox* CheckListBox1;
	Stdctrls::TLabel* Label16;
	Stdctrls::TLabel* Label17;
	Stdctrls::TLabel* Label18;
	Stdctrls::TLabel* Label19;
	Stdctrls::TLabel* Label20;
	Stdctrls::TLabel* Label21;
	Buttons::TSpeedButton* SpeedButton3;
	Stdctrls::TLabel* Label22;
	Stdctrls::TEdit* Edit21;
	Comctrls::TTrackBar* TrackBar12;
	Hsvbox::THSVBox* HSVBox3;
	Hsvbox::THSVBox* HSVBox1;
	Rulerbox::TRulerBox* RulerBox2;
	Rulerbox::TRulerBox* RulerBox1;
	Histogrambox::THistogramBox* HistogramBox1;
	Stdctrls::TButton* Button3;
	Imageenview::TImageEnView* ImageEn1;
	Imageenview::TImageEnView* ImageEn2;
	Comctrls::TTabSheet* TabSheet7;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TLabel* Label23;
	Stdctrls::TLabel* Label24;
	Stdctrls::TLabel* Label26;
	Extctrls::TPanel* Panel1;
	Hsvbox::THSVBox* HSVBox2;
	Stdctrls::TLabel* Label27;
	Stdctrls::TLabel* Label28;
	Stdctrls::TLabel* Label25;
	Stdctrls::TEdit* Edit22;
	Comctrls::TUpDown* UpDown11;
	Comctrls::TUpDown* UpDown12;
	Stdctrls::TEdit* Edit23;
	Stdctrls::TEdit* Edit24;
	Comctrls::TUpDown* UpDown13;
	Stdctrls::TEdit* Edit25;
	Comctrls::TUpDown* UpDown14;
	Stdctrls::TEdit* Edit26;
	Comctrls::TUpDown* UpDown15;
	Comctrls::TTabSheet* TabSheet8;
	Stdctrls::TGroupBox* GroupBox5;
	Stdctrls::TLabel* Label29;
	Stdctrls::TLabel* Label30;
	Stdctrls::TLabel* Label32;
	Stdctrls::TLabel* Label33;
	Stdctrls::TEdit* Edit27;
	Comctrls::TUpDown* UpDown16;
	Comctrls::TUpDown* UpDown17;
	Stdctrls::TEdit* Edit28;
	Stdctrls::TEdit* Edit29;
	Comctrls::TUpDown* UpDown18;
	Stdctrls::TEdit* Edit30;
	Comctrls::TUpDown* UpDown19;
	Stdctrls::TLabel* Label31;
	Comctrls::TUpDown* UpDown20;
	Stdctrls::TEdit* Edit31;
	Comctrls::TTabSheet* TabSheet9;
	Comctrls::TTabSheet* TabSheet10;
	Stdctrls::TGroupBox* GroupBox6;
	Stdctrls::TLabel* Label34;
	Stdctrls::TEdit* Edit32;
	Comctrls::TUpDown* UpDown21;
	Comctrls::TUpDown* UpDown22;
	Stdctrls::TEdit* Edit33;
	Stdctrls::TLabel* Label35;
	Stdctrls::TLabel* Label36;
	Stdctrls::TEdit* Edit34;
	Comctrls::TUpDown* UpDown23;
	Stdctrls::TCheckBox* CheckBox2;
	Stdctrls::TGroupBox* GroupBox7;
	Stdctrls::TLabel* Label37;
	Stdctrls::TListBox* ListBox2;
	Stdctrls::TLabel* Label38;
	Stdctrls::TEdit* Edit35;
	Comctrls::TUpDown* UpDown24;
	Comctrls::TTabSheet* TabSheet11;
	Comctrls::TTrackBar* TrackBarRotate;
	Stdctrls::TEdit* EditRotate;
	Stdctrls::TLabel* LabelRotate;
	Comctrls::TTabSheet* TabSheet12;
	Stdctrls::TGroupBox* GroupBox8;
	Imageenview::TImageEnView* ImageEnView1;
	Imageenproc::TImageEnProc* ImageEnProc2;
	Stdctrls::TButton* Clear;
	Stdctrls::TButton* Button7;
	Comctrls::TProgressBar* ProgressBar1;
	Stdctrls::TCheckBox* CheckBox1;
	Comctrls::TTabSheet* tabGamma;
	Stdctrls::TGroupBox* GroupBox9;
	Checklst::TCheckListBox* cbxGamma;
	Stdctrls::TLabel* Label39;
	Stdctrls::TEdit* edtGamma;
	Comctrls::TTrackBar* trkGamma;
	Imageenview::TImageEnView* ImageEnView2;
	Stdctrls::TLabel* Label41;
	Stdctrls::TLabel* Label42;
	Stdctrls::TLabel* Label40;
	Stdctrls::TLabel* Label43;
	Comctrls::TTabSheet* TabSheet14;
	Stdctrls::TLabel* Label44;
	Stdctrls::TEdit* Edit36;
	Comctrls::TTrackBar* TrackBar4;
	Stdctrls::TLabel* Label45;
	Stdctrls::TEdit* Edit37;
	Comctrls::TUpDown* UpDown25;
	Stdctrls::TCheckBox* chkLockPreview;
	Stdctrls::TCheckBox* CheckBox3;
	Stdctrls::TCheckBox* CheckBox4;
	Stdctrls::TLabel* Label46;
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall TrackBar1Change(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall TrackBar2Change(System::TObject* Sender);
	void __fastcall Edit4Change(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall Button4Click(System::TObject* Sender);
	void __fastcall Button6Click(System::TObject* Sender);
	void __fastcall ImageEn1ViewChange(System::TObject* Sender, int Change);
	void __fastcall TrackBar6Change(System::TObject* Sender);
	void __fastcall Edit7Change(System::TObject* Sender);
	void __fastcall Edit8Change(System::TObject* Sender);
	void __fastcall ListBox1Click(System::TObject* Sender);
	void __fastcall Button5Click(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall TrackBar9Change(System::TObject* Sender);
	void __fastcall Edit19Change(System::TObject* Sender);
	void __fastcall HSVBox3Change(System::TObject* Sender);
	void __fastcall ImageEn2MouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState 
		Shift, int X, int Y);
	void __fastcall CheckListBox1Click(System::TObject* Sender);
	void __fastcall RulerBox2RulerPosChange(System::TObject* Sender, int Grip);
	void __fastcall RulerBox1RulerPosChange(System::TObject* Sender, int Grip);
	void __fastcall SpeedButton3Click(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	void __fastcall Edit22Change(System::TObject* Sender);
	void __fastcall HSVBox2Change(System::TObject* Sender);
	void __fastcall Edit27Change(System::TObject* Sender);
	void __fastcall Edit32Change(System::TObject* Sender);
	void __fastcall Edit35Change(System::TObject* Sender);
	void __fastcall TrackBarRotateChange(System::TObject* Sender);
	void __fastcall EditRotateChange(System::TObject* Sender);
	void __fastcall SpeedButtonFlipHorClick(System::TObject* Sender);
	void __fastcall ClearClick(System::TObject* Sender);
	void __fastcall Button7Click(System::TObject* Sender);
	void __fastcall ImageEnProc2Progress(System::TObject* Sender, int per);
	void __fastcall CheckBox1Click(System::TObject* Sender);
	void __fastcall trkGammaChange(System::TObject* Sender);
	void __fastcall cbxGammaClick(System::TObject* Sender);
	void __fastcall TrackBar4Change(System::TObject* Sender);
	void __fastcall Edit36Change(System::TObject* Sender);
	
private:
	int mr;
	int mg;
	int mb;
	bool domod;
	bool dochange;
	bool doProgress;
	bool NeedToFlip;
	void __fastcall applyAct(Imageenview::TImageEnView* im);
	void __fastcall CopyOrg(void);
	void __fastcall CopyModToOrg(void);
	void __fastcall LoadFilt(void);
	void __fastcall ResetParameters(bool rs);
	void __fastcall UpdatePreviewZoom(void);
	void __fastcall UpdatePreview(void);
	void __fastcall DrawGammaGraph(double g);
	void __fastcall GetIPParams(void);
	
public:
	int Contrast;
	int Brightness;
	int Hue;
	int Sat;
	int Lum;
	int bHue;
	int bSat;
	int bVal;
	int Red;
	int Green;
	int Blue;
	Imageenproc::TGraphFilter Filter;
	#pragma pack(push, 1)
	Hyiedefs::TRGB DownLimit;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Hyiedefs::TRGB UpLimit;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Hyiedefs::TRGB EDownLimit;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Hyiedefs::TRGB EUpLimit;
	#pragma pack(pop)
	
	bool AutoEqualize;
	int BumpLeft;
	int BumpTop;
	int BumpWidth;
	int BumpHeight;
	#pragma pack(push, 1)
	Hyiedefs::TRGB BumpCol;
	#pragma pack(pop)
	
	int BumpSrc;
	int LensLeft;
	int LensTop;
	int LensWidth;
	int LensHeight;
	double LensRef;
	int WaveAmplitude;
	int WaveWaveLength;
	int WavePhase;
	bool WaveReflect;
	int MorphFilter;
	int MorphWinSize;
	double RotationAngle;
	int Sharpen;
	int SharpenSize;
	int FFTProgressPos;
	Iefft::TIEFtImage* FTImage;
	Imageenproc::TPreviewEffects pe;
	Hyiedefs::TProgressRec Progress;
	bool DefaultLockPreview;
	bool ars[14];
	AnsiString undos[14];
	Comctrls::TTabSheet* InitialPage;
	AnsiString UndoCaption;
	Imageenproc::TIPDialogParams* fIPDialogParams;
	void __fastcall SetLanguage(Hyiedefs::TMsgLanguage l);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TfPreviews(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfPreviews(Classes::TComponent* AOwner, int Dummy
		) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfPreviews(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TfPreviews(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint PREVIEWSTABCOUNT = 0xe;

}	/* namespace Previews */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Previews;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// previews
