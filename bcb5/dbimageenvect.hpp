// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dbimageenvect.pas' rev: 5.00

#ifndef dbimageenvectHPP
#define dbimageenvectHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <ieview.hpp>	// Pascal unit
#include <hyiedefs.hpp>	// Pascal unit
#include <ievect.hpp>	// Pascal unit
#include <dbimageen.hpp>	// Pascal unit
#include <imageenio.hpp>	// Pascal unit
#include <imageenview.hpp>	// Pascal unit
#include <DBCtrls.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbimageenvect
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TImageEnDBVect;
class PASCALIMPLEMENTATION TImageEnDBVect : public Ievect::TImageEnVect 
{
	typedef Ievect::TImageEnVect inherited;
	
private:
	bool FAutoDisplay;
	Dbctrls::TFieldDataLink* FDataLink;
	bool FPictureLoaded;
	Dbimageen::TDataFieldImageFormat fDataFieldImageFormat;
	bool fDoImageChange;
	AnsiString fAbsolutePath;
	bool fIsInsideDbCtrl;
	void __fastcall SetAutoDisplay(bool Value);
	AnsiString __fastcall GetDataField(void);
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetReadOnly(bool Value);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	void __fastcall SetJPegQuality(int q);
	int __fastcall GetJPegQuality(void);
	Imageenio::TIOParamsVals* __fastcall GetIOParams(void);
	Imageenio::TIOPreviewsParams __fastcall GetIOPreviewsParams(void);
	void __fastcall SetIOPreviewsParams(Imageenio::TIOPreviewsParams v);
	void __fastcall SetPreviewFont(Graphics::TFont* f);
	Graphics::TFont* __fastcall GetPreviewFont(void);
	void __fastcall SetAbsolutePath(const AnsiString v);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	virtual void __fastcall DataChange(System::TObject* Sender);
	virtual void __fastcall UpdateData(System::TObject* Sender);
	virtual Dbimageen::TDataFieldImageFormat __fastcall GetDataFieldImageFormat(void);
	virtual void __fastcall SetDataFieldImageFormat(Dbimageen::TDataFieldImageFormat v);
	void __fastcall LoadPictureEx(Imageenio::TImageEnIO* ffImageEnIO);
	virtual void __fastcall DoVectorialChanged(void);
	virtual bool __fastcall InsideDBCtrl(void);
	
public:
	__fastcall virtual TImageEnDBVect(Classes::TComponent* AOwner);
	__fastcall virtual ~TImageEnDBVect(void);
	virtual void __fastcall PaintToEx(Graphics::TBitmap* ABitmap, Hyiedefs::PPointerArray ABitmapScanline
		, Windows::PRect UpdRect);
	virtual void __fastcall Paint(void);
	virtual void __fastcall ImageChange(void);
	__property Db::TField* Field = {read=GetField};
	virtual void __fastcall LoadPicture(void);
	virtual Dbimageen::TDataFieldImageFormat __fastcall LoadedFieldImageFormat(void);
	__property Imageenio::TIOParamsVals* IOParams = {read=GetIOParams};
	bool __fastcall DoIOPreview(void);
	__property bool PictureLoaded = {read=FPictureLoaded, nodefault};
	__property AnsiString AbsolutePath = {read=fAbsolutePath, write=SetAbsolutePath};
	
__published:
	__property bool AutoDisplay = {read=FAutoDisplay, write=SetAutoDisplay, default=1};
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property Dbimageen::TDataFieldImageFormat DataFieldImageFormat = {read=GetDataFieldImageFormat, write=
		SetDataFieldImageFormat, default=0};
	__property int JpegQuality = {read=GetJPegQuality, write=SetJPegQuality, default=25};
	__property Imageenio::TIOPreviewsParams IOPreviewsParams = {read=GetIOPreviewsParams, write=SetIOPreviewsParams
		, default=0};
	__property Graphics::TFont* PreviewFont = {read=GetPreviewFont, write=SetPreviewFont};
	__property bool IsInsideDbCtrl = {read=fIsInsideDbCtrl, write=fIsInsideDbCtrl, default=0};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TImageEnDBVect(HWND ParentWindow) : Ievect::TImageEnVect(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dbimageenvect */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dbimageenvect;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// dbimageenvect
