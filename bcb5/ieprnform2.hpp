// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ieprnform2.pas' rev: 5.00

#ifndef ieprnform2HPP
#define ieprnform2HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ievect.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <imageenview.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
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

namespace Ieprnform2
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfiePrnForm2;
class PASCALIMPLEMENTATION TfiePrnForm2 : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TEdit* Edit1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* Edit2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* Edit3;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* Edit4;
	Stdctrls::TGroupBox* GroupBox2;
	Buttons::TSpeedButton* SpeedButton2;
	Buttons::TSpeedButton* SpeedButton3;
	Buttons::TSpeedButton* SpeedButton4;
	Buttons::TSpeedButton* SpeedButton5;
	Buttons::TSpeedButton* SpeedButton6;
	Buttons::TSpeedButton* SpeedButton7;
	Buttons::TSpeedButton* SpeedButton8;
	Buttons::TSpeedButton* SpeedButton9;
	Buttons::TSpeedButton* SpeedButton1;
	Stdctrls::TGroupBox* GroupBox3;
	Stdctrls::TComboBox* ComboBox1;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* Edit5;
	Stdctrls::TLabel* Label7;
	Stdctrls::TEdit* Edit6;
	Stdctrls::TLabel* Label8;
	Stdctrls::TGroupBox* GroupBox4;
	Stdctrls::TEdit* Edit7;
	Stdctrls::TLabel* Label9;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button2;
	Stdctrls::TGroupBox* GroupBox5;
	Imageenview::TImageEnView* ImageEnView1;
	Comctrls::TUpDown* UpDown1;
	Comctrls::TUpDown* UpDown2;
	Comctrls::TUpDown* UpDown3;
	Comctrls::TUpDown* UpDown4;
	Comctrls::TUpDown* UpDown5;
	Comctrls::TUpDown* UpDown6;
	Comctrls::TUpDown* UpDown7;
	Stdctrls::TButton* Button4;
	Dialogs::TPrinterSetupDialog* PrinterSetupDialog1;
	Stdctrls::TGroupBox* GroupBox6;
	Stdctrls::TLabel* Label10;
	Stdctrls::TComboBox* ComboBox2;
	void __fastcall ComboBox1Change(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall printpreview(System::TObject* Sender);
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall UpDown1Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown2Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown3Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown4Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown7Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown5Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown6Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall Button4Click(System::TObject* Sender);
	void __fastcall ComboBox2Change(System::TObject* Sender);
	
private:
	void __fastcall incdecmargins(Stdctrls::TEdit* text, Comctrls::TUDBtnType Button);
	void __fastcall SetLanguage_units(void);
	double __fastcall XMult(void);
	
public:
	Imageenio::TImageEnIO* io;
	Imageenio::TIEDialogsMeasureUnit fDialogsMeasureUnit;
	Hyiedefs::TMsgLanguage fLanguage;
	AnsiString fTaskName;
	Imageenio::TIOPrintPreviewParams* fPrintPreviewParams;
	bool PrintAnnotations;
	void __fastcall SetLanguage(Hyiedefs::TMsgLanguage l);
	void __fastcall LoadParameters(void);
	void __fastcall SaveParameters(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TfiePrnForm2(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfiePrnForm2(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfiePrnForm2(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TfiePrnForm2(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ieprnform2 */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ieprnform2;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ieprnform2
