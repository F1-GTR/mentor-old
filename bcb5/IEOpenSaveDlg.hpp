// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ieopensavedlg.pas' rev: 5.00

#ifndef ieopensavedlgHPP
#define ieopensavedlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <iemio.hpp>	// Pascal unit
#include <iemview.hpp>	// Pascal unit
#include <imageenview.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <hyieutils.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Clipbrd.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <CommDlg.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ieopensavedlg
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIEDBorderStyle { iepsDefault, iepsCropped, iepsCropShadow };
#pragma option pop

class DELPHICLASS TIECommonDialog;
class PASCALIMPLEMENTATION TIECommonDialog : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Hyiedefs::TMsgLanguage fMsgLanguage;
	bool FCtl3D;
	void *FDefWndProc;
	Classes::THelpContext FHelpContext;
	HWND FHandle;
	void *FObjectInstance;
	char *FTemplate;
	Classes::TNotifyEvent FOnClose;
	Classes::TNotifyEvent FOnShow;
	bool fShowPlacesBar;
	Extctrls::TTimer* fWatchTimer;
	MESSAGE void __fastcall WMDestroy(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMInitDialog(Messages::TWMInitDialog &Message);
	MESSAGE void __fastcall WMNCDestroy(Messages::TWMNoParams &Message);
	void __fastcall MainWndProc(Messages::TMessage &Message);
	
protected:
	bool fExtendedDialog;
	DYNAMIC void __fastcall DoClose(void);
	DYNAMIC void __fastcall DoShow(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	virtual bool __fastcall MessageHook(Messages::TMessage &Msg);
	virtual BOOL __fastcall TaskModalDialog(void * DialogFunc, void *DialogData);
	virtual bool __fastcall Execute(void) = 0 ;
	__property char * Template = {read=FTemplate, write=FTemplate};
	
public:
	__fastcall virtual TIECommonDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TIECommonDialog(void);
	virtual void __fastcall DefaultHandler(void *Message);
	__property HWND Handle = {read=FHandle, nodefault};
	
__published:
	__property bool Ctl3D = {read=FCtl3D, write=FCtl3D, default=1};
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=FHelpContext, default=0};
	__property Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
	__property Hyiedefs::TMsgLanguage MsgLanguage = {read=fMsgLanguage, write=fMsgLanguage, default=0};
		
	__property bool ShowPlacesBar = {read=fShowPlacesBar, write=fShowPlacesBar, default=1};
	__property bool ExtendedDialog = {read=fExtendedDialog, write=fExtendedDialog, default=1};
};


class DELPHICLASS TOpenImageEnDialog;
class PASCALIMPLEMENTATION TOpenImageEnDialog : public TIECommonDialog 
{
	typedef TIECommonDialog inherited;
	
private:
	bool m_blnInSelectionChange;
	Imageenview::TImageEnView* FImageEnView;
	Iemview::TImageEnMView* fImageEnMView;
	Extctrls::TPanel* FPicturePanel;
	Stdctrls::TLabel* fPicLabel1;
	Stdctrls::TLabel* fPicLabel2;
	Stdctrls::TLabel* fPicLabel3;
	Extctrls::TPanel* fInfoPanel;
	Stdctrls::TLabel* fInfoLabel1;
	Stdctrls::TLabel* fInfoLabel2;
	Buttons::TSpeedButton* FPreviewButton;
	Stdctrls::TComboBox* FZoomComboBox;
	Comctrls::TProgressBar* fProgressBar;
	Buttons::TSpeedButton* fPlayButton;
	Stdctrls::TButton* fAdvancedButton;
	Stdctrls::TCheckBox* fPreviewCheck;
	int fFileSize;
	int fFrames;
	AnsiString fSelType;
	bool fAutoSetFilter;
	bool fAlwaysAnimate;
	bool fAutoAdjustDPI;
	bool fFilteredAdjustDPI;
	Classes::TStrings* FHistoryList;
	Dialogs::TOpenOptions FOptions;
	AnsiString FFilter;
	int FFilterIndex;
	int FCurrentFilterIndex;
	AnsiString FInitialDir;
	AnsiString FTitle;
	AnsiString FDefaultExt;
	AnsiString FFileName;
	Classes::TStrings* FFiles;
	Dialogs::TFileEditStyle FFileEditStyle;
	Classes::TNotifyEvent FOnSelectionChange;
	Classes::TNotifyEvent FOnFolderChange;
	Classes::TNotifyEvent FOnTypeChange;
	Forms::TCloseQueryEvent FOnCanClose;
	TIEDBorderStyle fPreviewBorderStyle;
	bool fShowAVI;
	AnsiString fExtendedFilters;
	bool fShowAllFrames;
	int fSelectedFrame;
	AnsiString __fastcall GetFileName(void);
	AnsiString __fastcall GetFileName2(void);
	int __fastcall GetFilterIndex(void);
	void __fastcall ReadFileEditStyle(Classes::TReader* Reader);
	void __fastcall SetHistoryList(Classes::TStrings* Value);
	void __fastcall SetInitialDir(const AnsiString Value);
	void __fastcall PreviewClick(System::TObject* Sender);
	void __fastcall PreviewKeyPress(System::TObject* Sender, char &Key);
	void __fastcall ZoomComboChange(System::TObject* Sender);
	void __fastcall ImageEnIOProgress(System::TObject* Sender, int per);
	void __fastcall ShowIOParams(Imageenio::TIOParamsVals* params);
	void __fastcall DoCheckPreview(System::TObject* Sender);
	void __fastcall SetPreviewBorderStyle(TIEDBorderStyle v);
	void __fastcall SetZoomFilter(Hyiedefs::TResampleFilter v);
	Hyiedefs::TResampleFilter __fastcall GetZoomFilter(void);
	int __fastcall FileName2FilterIndex(AnsiString e);
	void __fastcall SetAlwaysAnimate(bool value);
	
protected:
	bool fShowPreview;
	void __fastcall PlayClick(System::TObject* Sender);
	bool __fastcall CanClose(tagOFNA &OpenFileName);
	DYNAMIC bool __fastcall DoCanClose(void);
	BOOL __fastcall DoExecute(void * Func);
	DYNAMIC void __fastcall DoSelectionChange(void);
	DYNAMIC void __fastcall DoFolderChange(void);
	DYNAMIC void __fastcall DoTypeChange(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall GetFileNames(tagOFNA &OpenFileName);
	virtual Windows::TRect __fastcall GetStaticRect(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	AnsiString __fastcall BuildStrFilter(void);
	virtual void __fastcall SetZoom(void);
	DYNAMIC void __fastcall DoClose(void);
	DYNAMIC void __fastcall DoShow(void);
	void __fastcall SetLang(void);
	void __fastcall OnMViewSelect(System::TObject* Sender, int idx);
	void __fastcall DoAllDisplayed(System::TObject* Sender);
	
public:
	__fastcall virtual TOpenImageEnDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TOpenImageEnDialog(void);
	virtual bool __fastcall Execute(void);
	__property Dialogs::TFileEditStyle FileEditStyle = {read=FFileEditStyle, write=FFileEditStyle, nodefault
		};
	__property Classes::TStrings* Files = {read=FFiles};
	__property Classes::TStrings* HistoryList = {read=FHistoryList, write=SetHistoryList};
	__property bool ShowAVI = {read=fShowAVI, write=fShowAVI, nodefault};
	__property Stdctrls::TCheckBox* PreviewCheckBox = {read=fPreviewCheck};
	__property AnsiString ExtendedFilters = {read=fExtendedFilters, write=fExtendedFilters};
	__property int SelectedFrame = {read=fSelectedFrame, write=fSelectedFrame, nodefault};
	
__published:
	__property AnsiString DefaultExt = {read=FDefaultExt, write=FDefaultExt};
	__property AnsiString FileName = {read=GetFileName, write=FFileName};
	__property AnsiString Filter = {read=FFilter, write=FFilter};
	__property int FilterIndex = {read=GetFilterIndex, write=FFilterIndex, default=1};
	__property AnsiString InitialDir = {read=FInitialDir, write=SetInitialDir};
	__property Dialogs::TOpenOptions Options = {read=FOptions, write=FOptions, default=4};
	__property AnsiString Title = {read=FTitle, write=FTitle};
	__property Forms::TCloseQueryEvent OnCanClose = {read=FOnCanClose, write=FOnCanClose};
	__property Classes::TNotifyEvent OnFolderChange = {read=FOnFolderChange, write=FOnFolderChange};
	__property Classes::TNotifyEvent OnSelectionChange = {read=FOnSelectionChange, write=FOnSelectionChange
		};
	__property Classes::TNotifyEvent OnTypeChange = {read=FOnTypeChange, write=FOnTypeChange};
	__property bool AutoSetFilter = {read=fAutoSetFilter, write=fAutoSetFilter, default=1};
	__property bool AlwaysAnimate = {read=fAlwaysAnimate, write=SetAlwaysAnimate, default=0};
	__property TIEDBorderStyle PreviewBorderStyle = {read=fPreviewBorderStyle, write=SetPreviewBorderStyle
		, default=0};
	__property bool AutoAdjustDPI = {read=fAutoAdjustDPI, write=fAutoAdjustDPI, default=0};
	__property bool FilteredAdjustDPI = {read=fFilteredAdjustDPI, write=fFilteredAdjustDPI, default=0};
		
	__property Hyiedefs::TResampleFilter ZoomFilter = {read=GetZoomFilter, write=SetZoomFilter, default=9
		};
	__property bool ShowAllFrames = {read=fShowAllFrames, write=fShowAllFrames, default=1};
};


#pragma option push -b-
enum ieopensavedlg__3 { sdShowPreview, sdShowAdvanced };
#pragma option pop

typedef Set<ieopensavedlg__3, sdShowPreview, sdShowAdvanced>  TIESaveDlgOpt;

class DELPHICLASS TSaveImageEnDialog;
class PASCALIMPLEMENTATION TSaveImageEnDialog : public TOpenImageEnDialog 
{
	typedef TOpenImageEnDialog inherited;
	
private:
	TIESaveDlgOpt fExOptions;
	Classes::TComponent* fAttachedImageEnIO;
	Imageenio::TIOParamsVals* fBackParams;
	void __fastcall OnWatchTimer(System::TObject* Sender);
	void __fastcall DoAdvanced(System::TObject* Sender);
	void __fastcall SetAttachedImageEnIO(Classes::TComponent* v);
	
protected:
	DYNAMIC void __fastcall DoTypeChange(void);
	virtual void __fastcall SetFileNameExt(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall GetAdvancedType(Imageenio::TPreviewParams &pp, int &ft);
	void __fastcall EnableDisableAdvanced(void);
	
public:
	__fastcall virtual TSaveImageEnDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TSaveImageEnDialog(void);
	virtual bool __fastcall Execute(void);
	
__published:
	__property TIESaveDlgOpt ExOptions = {read=fExOptions, write=fExOptions, nodefault};
	__property Classes::TComponent* AttachedImageEnIO = {read=fAttachedImageEnIO, write=SetAttachedImageEnIO
		};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Imageenview::TIEBackgroundStyle iegPreviewImageBackgroundStyle;
extern PACKAGE Graphics::TColor iegPreviewImageBackgroundColor;

}	/* namespace Ieopensavedlg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ieopensavedlg;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ieopensavedlg
