// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ieprnform3.pas' rev: 5.00

#ifndef ieprnform3HPP
#define ieprnform3HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ievect.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <imageenproc.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <iemview.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
#include <imageenview.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <iemio.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
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

namespace Ieprnform3
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfiePrnForm3;
class PASCALIMPLEMENTATION TfiePrnForm3 : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TSplitter* Splitter1;
	Extctrls::TPanel* Panel2;
	Buttons::TSpeedButton* SpeedButton1;
	Buttons::TSpeedButton* SpeedButton2;
	Buttons::TSpeedButton* SpeedButton3;
	Buttons::TSpeedButton* SpeedButton4;
	Buttons::TSpeedButton* SpeedButton5;
	Buttons::TSpeedButton* SpeedButton6;
	Buttons::TSpeedButton* SpeedButton7;
	Buttons::TSpeedButton* SpeedButton8;
	Buttons::TSpeedButton* SpeedButton9;
	Buttons::TSpeedButton* SpeedButton10;
	Buttons::TSpeedButton* SpeedButton11;
	Buttons::TSpeedButton* SpeedButton12;
	Stdctrls::TEdit* Edit1;
	Stdctrls::TEdit* Edit2;
	Stdctrls::TEdit* Edit3;
	Stdctrls::TEdit* Edit4;
	Stdctrls::TComboBox* ComboBox1;
	Stdctrls::TEdit* Edit5;
	Stdctrls::TEdit* Edit6;
	Stdctrls::TEdit* Edit7;
	Comctrls::TUpDown* UpDown1;
	Comctrls::TUpDown* UpDown2;
	Comctrls::TUpDown* UpDown3;
	Comctrls::TUpDown* UpDown4;
	Comctrls::TUpDown* UpDown5;
	Comctrls::TUpDown* UpDown6;
	Comctrls::TUpDown* UpDown7;
	Dialogs::TPrinterSetupDialog* PrinterSetupDialog1;
	Imageenview::TImageEnView* ImageEnView1;
	Extctrls::TPanel* Panel3;
	Iemview::TImageEnMView* ImageEnMView1;
	Menus::TPopupMenu* PopupMenu1;
	Stdctrls::TComboBox* ComboBox2;
	Menus::TMenuItem* Add1;
	Menus::TMenuItem* Delete1;
	Extctrls::TBevel* Bevel1;
	Extctrls::TBevel* Bevel3;
	Extctrls::TBevel* Bevel2;
	Extctrls::TBevel* Bevel4;
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall ComboBox1Change(System::TObject* Sender);
	void __fastcall SpeedButton12Click(System::TObject* Sender);
	void __fastcall SpeedButton10Click(System::TObject* Sender);
	void __fastcall SpeedButton11Click(System::TObject* Sender);
	void __fastcall UpDown1Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown2Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown3Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown4Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown5Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown6Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall UpDown7Click(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall PrintPreview(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ImageEnMView1MouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState 
		Shift, int X, int Y);
	void __fastcall Delete1Click(System::TObject* Sender);
	void __fastcall Add1Click(System::TObject* Sender);
	
private:
	Iemview::TImageEnMView* srcview;
	Ievect::TImageEnVect* ie;
	void __fastcall incdecmargins(Stdctrls::TEdit* text, Comctrls::TUDBtnType Button);
	void __fastcall ImageSelect(void);
	void __fastcall GetPage(int idx);
	
public:
	Iemio::TImageEnMIO* mio;
	AnsiString fTaskName;
	Hyiedefs::TMsgLanguage fLanguage;
	Imageenio::TIEDialogsMeasureUnit fDialogsMeasureUnit;
	bool PrintAnnotations;
	void __fastcall SetLanguage(Hyiedefs::TMsgLanguage l);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TfiePrnForm3(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfiePrnForm3(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfiePrnForm3(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TfiePrnForm3(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ieprnform3 */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ieprnform3;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ieprnform3
