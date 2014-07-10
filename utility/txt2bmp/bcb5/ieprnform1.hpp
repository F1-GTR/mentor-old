// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ieprnform1.pas' rev: 5.00

#ifndef ieprnform1HPP
#define ieprnform1HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ievect.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Ieprnform1
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfiePrnForm1;
class PASCALIMPLEMENTATION TfiePrnForm1 : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Dialogs::TPrinterSetupDialog* PrinterSetupDialog1;
	Imageenview::TImageEnView* ImageEnView1;
	Menus::TMainMenu* MainMenu1;
	Extctrls::TPanel* Panel1;
	Buttons::TSpeedButton* SpeedButton1;
	Buttons::TSpeedButton* SpeedButton2;
	Buttons::TSpeedButton* SpeedButton3;
	Buttons::TSpeedButton* SpeedButton4;
	Buttons::TSpeedButton* SpeedButton5;
	Buttons::TSpeedButton* SpeedButton6;
	Buttons::TSpeedButton* SpeedButton7;
	Buttons::TSpeedButton* SpeedButton8;
	Buttons::TSpeedButton* SpeedButton9;
	Stdctrls::TEdit* Edit1;
	Stdctrls::TEdit* Edit2;
	Stdctrls::TEdit* Edit3;
	Stdctrls::TEdit* Edit4;
	Stdctrls::TComboBox* ComboBox1;
	Stdctrls::TEdit* Edit5;
	Stdctrls::TEdit* Edit6;
	Stdctrls::TEdit* Edit7;
	Buttons::TSpeedButton* SpeedButton10;
	Buttons::TSpeedButton* SpeedButton11;
	Comctrls::TUpDown* UpDown1;
	Comctrls::TUpDown* UpDown2;
	Comctrls::TUpDown* UpDown3;
	Comctrls::TUpDown* UpDown4;
	Comctrls::TUpDown* UpDown5;
	Comctrls::TUpDown* UpDown6;
	Comctrls::TUpDown* UpDown7;
	Menus::TMenuItem* File1;
	Menus::TMenuItem* Exit1;
	Menus::TMenuItem* N1;
	Menus::TMenuItem* PrintSetup1;
	Menus::TMenuItem* Print1;
	Buttons::TSpeedButton* SpeedButton12;
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall PrintPreview(System::TObject* Sender);
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall ComboBox1Change(System::TObject* Sender);
	void __fastcall Exit1Click(System::TObject* Sender);
	void __fastcall SpeedButton12Click(System::TObject* Sender);
	void __fastcall SpeedButton10Click(System::TObject* Sender);
	void __fastcall Print1Click(System::TObject* Sender);
	void __fastcall UpDown1Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown2Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown3Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown4Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown7Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown5Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown6Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall FormResize(System::TObject* Sender);
	
private:
	void __fastcall incdecmargins(Stdctrls::TEdit* text, Comctrls::TUDBtnType Button);
	double __fastcall XMult(void);
	
public:
	Imageenio::TIEDialogsMeasureUnit fDialogsMeasureUnit;
	Imageenio::TImageEnIO* io;
	AnsiString fTaskName;
	Imageenio::TIOPrintPreviewParams* fPrintPreviewParams;
	bool PrintAnnotations;
	void __fastcall SetLanguage(Hyiedefs::TMsgLanguage l);
	void __fastcall LoadParameters(void);
	void __fastcall SaveParameters(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TfiePrnForm1(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfiePrnForm1(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfiePrnForm1(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TfiePrnForm1(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ieprnform1 */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ieprnform1;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ieprnform1
