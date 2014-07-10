// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ExprMake.pas' rev: 4.00

#ifndef ExprMakeHPP
#define ExprMakeHPP

#pragma delphiheader begin
#pragma option push -w-
#include <SysUtils.hpp>	// Pascal unit
#include <ExprDraw.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Exprmake
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TExprBuilder;
#pragma pack(push, 4)
class PASCALIMPLEMENTATION TExprBuilder : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	bool Build;
	int P;
	AnsiString S;
	AnsiString __fastcall Preprocess(AnsiString S);
	void __fastcall AddMult(Exprdraw::TExprClass* &Existing, Exprdraw::TExprClass* Multiplier);
	Exprdraw::TExprClass* __fastcall MakePower(Exprdraw::TExprClass* Base, Exprdraw::TExprClass* Exponent
		);
	Exprdraw::TExprClass* __fastcall MakeIndex(Exprdraw::TExprClass* Base, Exprdraw::TExprClass* Index)
		;
	Exprdraw::TExprClass* __fastcall MakeCap(Exprdraw::TExprClass* Base, Exprdraw::TExprCapStyle Style, 
		int N);
	void __fastcall Decorate(Exprdraw::TExprClass* &Base);
	Exprdraw::TExprClass* __fastcall ExprString(int Need, bool AllowComma);
	Exprdraw::TExprClass* __fastcall BoolExpr(int &Flags);
	Exprdraw::TExprClass* __fastcall Expr(int &Flags);
	Exprdraw::TExprClass* __fastcall Factor(int &Flags);
	Exprdraw::TExprClass* __fastcall Trans(int &Flags);
	Exprdraw::TExprClass* __fastcall Func(int &Flags);
	Exprdraw::TExprClass* __fastcall FuncName(AnsiString N, int &Flags, bool Brackets);
	Exprdraw::TExprClass* __fastcall Token(AnsiString N, int &Flags);
	int __fastcall GreekLetter(AnsiString N);
	bool __fastcall Comma(void);
	void __fastcall LookForComma(void);
	
public:
	bool FuncAutoIndex;
	bool VarAutoIndex;
	bool PostSymbols;
	__fastcall TExprBuilder(void);
	Exprdraw::TExprClass* __fastcall BuildExpr(AnsiString Expr);
	Exprdraw::TExprClass* __fastcall SafeBuildExpr(AnsiString Expr);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TExprBuilder(void) { }
	#pragma option pop
	
};

#pragma pack(pop)

class DELPHICLASS EIncorrectExpr;
#pragma pack(push, 4)
class PASCALIMPLEMENTATION EIncorrectExpr : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIncorrectExpr(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIncorrectExpr(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIncorrectExpr(int Ident, Extended Dummy) : Sysutils::Exception(
		Ident, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIncorrectExpr(int Ident, const System::TVarRec * Args
		, const int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIncorrectExpr(const AnsiString Msg, int AHelpContext)
		 : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIncorrectExpr(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIncorrectExpr(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIncorrectExpr(int Ident, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIncorrectExpr(void) { }
	#pragma option pop
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Exprdraw::TExprClass* __fastcall SafeBuildExpr(AnsiString Expr);
extern PACKAGE Exprdraw::TExprClass* __fastcall BuildExpr(AnsiString Expr);

}	/* namespace Exprmake */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Exprmake;
#endif
#pragma option pop	// -w-

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ExprMake
