// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ExprDraw.pas' rev: 5.00

#ifndef ExprDrawHPP
#define ExprDrawHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Math.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Exprdraw
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TExprOrigin { eoTop, eoBottom };
#pragma option pop

#pragma option push -b-
enum TExprHorAlign { ehLeft, ehCenter, ehRight };
#pragma option pop

#pragma option push -b-
enum TExprVertAlign { evTop, evCenter, evBottom };
#pragma option pop

#pragma option push -b-
enum TExprBracket { ebNone, ebRound, ebSquare, ebFigure, ebModule };
#pragma option pop

#pragma option push -b-
enum TExprCapStyle { ecPoints, ecVector, ecCap, ecTilde, ecLine };
#pragma option pop

class DELPHICLASS TExprClass;
class PASCALIMPLEMENTATION TExprClass : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TExprClass* FParent;
	TExprClass* FNext;
	Graphics::TColor FColor;
	Graphics::TFont* FFont;
	int FWidth;
	int FHeight;
	int FMidLineUp;
	int FMidLineDn;
	int FPowerXPos;
	int FPowerYPos;
	int FIndexXPos;
	int FIndexYPos;
	int FCapDY;
	int FCapDXLeft;
	int FCapDXRight;
	Graphics::TCanvas* FCanvas;
	unsigned ToChange;
	void __fastcall SetNext(TExprClass* Value);
	Graphics::TColor __fastcall GetColor(void);
	void __fastcall SetLineWidth(void);
	void __fastcall SetFont(Graphics::TFont* NewFont);
	void __fastcall SetCanvas(Graphics::TCanvas* Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall FontNotify(System::TObject* Sender);
	int __fastcall GetWidth(void);
	int __fastcall GetHeight(void);
	int __fastcall GetMidLineUp(void);
	int __fastcall GetMidLineDn(void);
	int __fastcall GetPowerXPos(void);
	int __fastcall GetPowerYPos(void);
	int __fastcall GetIndexXPos(void);
	int __fastcall GetIndexYPos(void);
	int __fastcall GetCapDXLeft(void);
	int __fastcall GetCapDXRight(void);
	int __fastcall GetCapDY(void);
	void __fastcall SetParent(TExprClass* Value);
	
protected:
	int WX;
	int WY;
	Extended RWX;
	Extended RWY;
	__property TExprClass* Parent = {read=FParent, write=SetParent};
	DYNAMIC void __fastcall DynaSetFont(void);
	DYNAMIC void __fastcall DynaSetCanvas(void);
	DYNAMIC void __fastcall SetCanvasFont(void);
	void __fastcall SetPenAndBrush(void);
	void __fastcall ConvertCoords(int &X, int &Y, TExprHorAlign HorAlign, TExprVertAlign VertAlign);
	void __fastcall AssignCanvas(Graphics::TCanvas* Value, int EWX, int EWY, Extended ERWX, Extended ERWY
		);
	void __fastcall AssignFont(Graphics::TFont* NewFont, int EWX, int EWY, Extended ERWX, Extended ERWY
		);
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC bool __fastcall NeedBrackets(void);
	DYNAMIC bool __fastcall ArgNeedBrackets(void);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
	DYNAMIC int __fastcall CalcPowerXPos(void);
	DYNAMIC int __fastcall CalcIndexXPos(void);
	DYNAMIC int __fastcall CalcPowerYPos(void);
	DYNAMIC int __fastcall CalcIndexYPos(void);
	DYNAMIC int __fastcall CalcCapDY(void);
	DYNAMIC void __fastcall CalcCapDX(int &DLeft, int &DRight);
	
public:
	__property TExprClass* Next = {read=FNext, write=SetNext};
	__property Graphics::TColor Color = {read=GetColor, write=SetColor, nodefault};
	__property Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property Graphics::TCanvas* Canvas = {read=FCanvas, write=SetCanvas};
	__property int Width = {read=GetWidth, nodefault};
	__property int Height = {read=GetHeight, nodefault};
	__property int MidLineUp = {read=GetMidLineUp, nodefault};
	__property int MidLineDn = {read=GetMidLineDn, nodefault};
	__property int PowerXPos = {read=GetPowerXPos, nodefault};
	__property int PowerYPos = {read=GetPowerYPos, nodefault};
	__property int IndexXPos = {read=GetIndexXPos, nodefault};
	__property int IndexYPos = {read=GetIndexYPos, nodefault};
	__property int CapDXLeft = {read=GetCapDXLeft, nodefault};
	__property int CapDXRight = {read=GetCapDXRight, nodefault};
	__property int CapDY = {read=GetCapDY, nodefault};
	DYNAMIC int __fastcall FTType(void);
	__fastcall TExprClass(void);
	__fastcall virtual ~TExprClass(void);
	void __fastcall AddNext(TExprClass* Value);
	TExprClass* __fastcall CutOff(void);
	void __fastcall Draw(int X, int Y, TExprHorAlign HorAlign, TExprVertAlign VertAlign);
};


class DELPHICLASS TExprParent;
class PASCALIMPLEMENTATION TExprParent : public TExprClass 
{
	typedef TExprClass inherited;
	
private:
	TExprClass* FSon;
	void __fastcall SetSon(TExprClass* Value);
	DYNAMIC void __fastcall SetSonFont(void);
	DYNAMIC void __fastcall SetSonCanvas(void);
	
protected:
	DYNAMIC void __fastcall DynaSetFont(void);
	DYNAMIC void __fastcall DynaSetCanvas(void);
	
public:
	__property TExprClass* Son = {read=FSon, write=SetSon};
	__fastcall TExprParent(TExprClass* ASon);
	__fastcall virtual ~TExprParent(void);
	TExprClass* __fastcall CutOffSon(void);
};


class DELPHICLASS TExprBigParent;
class PASCALIMPLEMENTATION TExprBigParent : public TExprParent 
{
	typedef TExprParent inherited;
	
private:
	TExprClass* FDaughter;
	void __fastcall SetDaughter(TExprClass* Value);
	DYNAMIC void __fastcall SetDaughterFont(void);
	DYNAMIC void __fastcall SetDaughterCanvas(void);
	
protected:
	DYNAMIC void __fastcall DynaSetCanvas(void);
	DYNAMIC void __fastcall DynaSetFont(void);
	
public:
	__property TExprClass* Daughter = {read=FDaughter, write=SetDaughter};
	__fastcall TExprBigParent(TExprClass* ASon, TExprClass* ADaughter);
	__fastcall virtual ~TExprBigParent(void);
	TExprClass* __fastcall CutOffDaughter(void);
};


class DELPHICLASS TExprChain;
class PASCALIMPLEMENTATION TExprChain : public TExprParent 
{
	typedef TExprParent inherited;
	
private:
	void __fastcall CalcOverAbove(int &Over, int &Above);
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcCapDY(void);
	DYNAMIC void __fastcall CalcCapDX(int &DLeft, int &DRight);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	
public:
	void __fastcall BuildUpChain(TExprClass* Value);
	DYNAMIC int __fastcall FTType(void);
public:
	#pragma option push -w-inl
	/* TExprParent.Create */ inline __fastcall TExprChain(TExprClass* ASon) : TExprParent(ASon) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TExprParent.Destroy */ inline __fastcall virtual ~TExprChain(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprSimple;
class PASCALIMPLEMENTATION TExprSimple : public TExprClass 
{
	typedef TExprClass inherited;
	
protected:
	AnsiString S;
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcCapDY(void);
	
public:
	__fastcall TExprSimple(AnsiString Expr);
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprSimple(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprVar;
class PASCALIMPLEMENTATION TExprVar : public TExprSimple 
{
	typedef TExprSimple inherited;
	
protected:
	DYNAMIC void __fastcall SetCanvasFont(void);
	DYNAMIC void __fastcall CalcCapDX(int &DLeft, int &DRight);
	DYNAMIC int __fastcall CalcPowerXPos(void);
	DYNAMIC int __fastcall CalcIndexXPos(void);
public:
	#pragma option push -w-inl
	/* TExprSimple.Create */ inline __fastcall TExprVar(AnsiString Expr) : TExprSimple(Expr) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprVar(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprCustomText;
class PASCALIMPLEMENTATION TExprCustomText : public TExprSimple 
{
	typedef TExprSimple inherited;
	
protected:
	Graphics::TFontStyles FFontStyle;
	AnsiString FFontName;
	DYNAMIC void __fastcall SetCanvasFont(void);
	
public:
	__fastcall TExprCustomText(AnsiString Expr, Graphics::TFontStyles FontStyle, AnsiString FontName);
public:
		
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprCustomText(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprNumber;
class PASCALIMPLEMENTATION TExprNumber : public TExprClass 
{
	typedef TExprClass inherited;
	
private:
	Extended FNumber;
	AnsiString SM;
	AnsiString SE;
	bool ExpVal;
	void __fastcall SetNumber(Extended Value);
	
protected:
	DYNAMIC AnsiString __fastcall NumToStr();
	DYNAMIC int __fastcall CalcCapDY(void);
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
	
public:
	__property Extended Number = {read=FNumber, write=SetNumber};
	__fastcall TExprNumber(Extended A, bool ExpForm);
	DYNAMIC int __fastcall FTType(void);
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprNumber(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprExpNumber;
class PASCALIMPLEMENTATION TExprExpNumber : public TExprNumber 
{
	typedef TExprNumber inherited;
	
private:
	int FPrecision;
	int FDigits;
	int FMaxDeg;
	
protected:
	DYNAMIC AnsiString __fastcall NumToStr();
	
public:
	__fastcall TExprExpNumber(Extended A, int Precision, int Digits, int MaxDeg);
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprExpNumber(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprRatio;
class PASCALIMPLEMENTATION TExprRatio : public TExprBigParent 
{
	typedef TExprBigParent inherited;
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
public:
	#pragma option push -w-inl
	/* TExprBigParent.Create */ inline __fastcall TExprRatio(TExprClass* ASon, TExprClass* ADaughter) : 
		TExprBigParent(ASon, ADaughter) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TExprBigParent.Destroy */ inline __fastcall virtual ~TExprRatio(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprRoot;
class PASCALIMPLEMENTATION TExprRoot : public TExprBigParent 
{
	typedef TExprBigParent inherited;
	
private:
	DYNAMIC void __fastcall SetDaughterFont(void);
	DYNAMIC void __fastcall SetDaughterCanvas(void);
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
public:
	#pragma option push -w-inl
	/* TExprBigParent.Create */ inline __fastcall TExprRoot(TExprClass* ASon, TExprClass* ADaughter) : 
		TExprBigParent(ASon, ADaughter) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TExprBigParent.Destroy */ inline __fastcall virtual ~TExprRoot(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprBracketed;
class PASCALIMPLEMENTATION TExprBracketed : public TExprChain 
{
	typedef TExprChain inherited;
	
protected:
	TExprBracket Left;
	TExprBracket Right;
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC bool __fastcall IsBracketed(void);
	DYNAMIC int __fastcall CalcCapDY(void);
	DYNAMIC void __fastcall CalcCapDX(int &DLeft, int &DRight);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
	
public:
	__fastcall TExprBracketed(TExprClass* ASon, TExprBracket LeftBracket, TExprBracket RightBracket);
	DYNAMIC int __fastcall FTType(void);
	void __fastcall RemoveBrackets(void);
public:
	#pragma option push -w-inl
	/* TExprParent.Destroy */ inline __fastcall virtual ~TExprBracketed(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprRound;
class PASCALIMPLEMENTATION TExprRound : public TExprBracketed 
{
	typedef TExprBracketed inherited;
	
public:
	__fastcall TExprRound(TExprClass* ASon);
	DYNAMIC int __fastcall FTType(void);
public:
	#pragma option push -w-inl
	/* TExprParent.Destroy */ inline __fastcall virtual ~TExprRound(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprExtSymbol;
class PASCALIMPLEMENTATION TExprExtSymbol : public TExprClass 
{
	typedef TExprClass inherited;
	
public:
	wchar_t Symbol;
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcCapDY(void);
	DYNAMIC void __fastcall CalcCapDX(int &DLeft, int &DRight);
	DYNAMIC int __fastcall CalcPowerXPos(void);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	
public:
	__fastcall TExprExtSymbol(int SymbolCode);
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprExtSymbol(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprPlank;
class PASCALIMPLEMENTATION TExprPlank : public TExprExtSymbol 
{
	typedef TExprExtSymbol inherited;
	
protected:
	DYNAMIC void __fastcall SetCanvasFont(void);
	DYNAMIC int __fastcall CalcCapDY(void);
	DYNAMIC void __fastcall CalcCapDX(int &DLeft, int &DRight);
	
public:
	__fastcall TExprPlank(void);
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprPlank(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprSign;
class PASCALIMPLEMENTATION TExprSign : public TExprExtSymbol 
{
	typedef TExprExtSymbol inherited;
	
protected:
	DYNAMIC bool __fastcall NeedBrackets(void);
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcCapDY(void);
	DYNAMIC int __fastcall CalcWidth(void);
	
public:
	DYNAMIC int __fastcall FTType(void);
public:
	#pragma option push -w-inl
	/* TExprExtSymbol.Create */ inline __fastcall TExprSign(int SymbolCode) : TExprExtSymbol(SymbolCode
		) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprSign(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprTwinParent;
class PASCALIMPLEMENTATION TExprTwinParent : public TExprParent 
{
	typedef TExprParent inherited;
	
private:
	TExprClass* Twins[2];
	void __fastcall SetTwins(int Index, TExprClass* Value);
	
protected:
	DYNAMIC void __fastcall DynaSetFont(void);
	DYNAMIC void __fastcall DynaSetCanvas(void);
	
public:
	__property TExprClass* Twin1 = {read=Twins[28], write=SetTwins, index=1};
	__property TExprClass* Twin2 = {read=Twins[29], write=SetTwins, index=2};
	__fastcall TExprTwinParent(TExprClass* ASon, TExprClass* FirstTwin, TExprClass* SecondTwin);
	__fastcall virtual ~TExprTwinParent(void);
};


class DELPHICLASS TExprIndex;
class PASCALIMPLEMENTATION TExprIndex : public TExprTwinParent 
{
	typedef TExprTwinParent inherited;
	
protected:
	DYNAMIC int __fastcall CalcCapDY(void);
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
	
public:
	DYNAMIC bool __fastcall ArgNeedBrackets(void);
	DYNAMIC int __fastcall FTType(void);
public:
	#pragma option push -w-inl
	/* TExprTwinParent.Create */ inline __fastcall TExprIndex(TExprClass* ASon, TExprClass* FirstTwin, 
		TExprClass* SecondTwin) : TExprTwinParent(ASon, FirstTwin, SecondTwin) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TExprTwinParent.Destroy */ inline __fastcall virtual ~TExprIndex(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprArgument;
class PASCALIMPLEMENTATION TExprArgument : public TExprBracketed 
{
	typedef TExprBracketed inherited;
	
protected:
	bool ForcedBrackets;
	DYNAMIC bool __fastcall IsBracketed(void);
	
public:
	__fastcall TExprArgument(TExprClass* ASon);
	void __fastcall SetBrackets(void);
public:
	#pragma option push -w-inl
	/* TExprParent.Destroy */ inline __fastcall virtual ~TExprArgument(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprCommonFunc;
class PASCALIMPLEMENTATION TExprCommonFunc : public TExprBigParent 
{
	typedef TExprBigParent inherited;
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
	
public:
	bool __fastcall ArgumentNeedBrackets(void);
	DYNAMIC int __fastcall FTType(void);
public:
	#pragma option push -w-inl
	/* TExprBigParent.Create */ inline __fastcall TExprCommonFunc(TExprClass* ASon, TExprClass* ADaughter
		) : TExprBigParent(ASon, ADaughter) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TExprBigParent.Destroy */ inline __fastcall virtual ~TExprCommonFunc(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprFuncName;
class PASCALIMPLEMENTATION TExprFuncName : public TExprSimple 
{
	typedef TExprSimple inherited;
	
protected:
	DYNAMIC bool __fastcall ArgNeedBrackets(void);
public:
	#pragma option push -w-inl
	/* TExprSimple.Create */ inline __fastcall TExprFuncName(AnsiString Expr) : TExprSimple(Expr) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprFuncName(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprFunc;
class PASCALIMPLEMENTATION TExprFunc : public TExprCommonFunc 
{
	typedef TExprCommonFunc inherited;
	
public:
	__fastcall TExprFunc(AnsiString FuncName, TExprClass* ADaughter);
public:
	#pragma option push -w-inl
	/* TExprBigParent.Destroy */ inline __fastcall virtual ~TExprFunc(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprBase;
class PASCALIMPLEMENTATION TExprBase : public TExprBracketed 
{
	typedef TExprBracketed inherited;
	
protected:
	DYNAMIC bool __fastcall IsBracketed(void);
	
public:
	__fastcall TExprBase(TExprClass* ASon);
public:
	#pragma option push -w-inl
	/* TExprParent.Destroy */ inline __fastcall virtual ~TExprBase(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprComma;
class PASCALIMPLEMENTATION TExprComma : public TExprExtSymbol 
{
	typedef TExprExtSymbol inherited;
	
protected:
	DYNAMIC bool __fastcall NeedBrackets(void);
	DYNAMIC int __fastcall CalcCapDY(void);
	
public:
	__fastcall TExprComma(void);
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprComma(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprLim;
class PASCALIMPLEMENTATION TExprLim : public TExprParent 
{
	typedef TExprParent inherited;
	
protected:
	DYNAMIC void __fastcall SetSonFont(void);
	DYNAMIC void __fastcall SetSonCanvas(void);
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC bool __fastcall ArgNeedBrackets(void);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
public:
	#pragma option push -w-inl
	/* TExprParent.Create */ inline __fastcall TExprLim(TExprClass* ASon) : TExprParent(ASon) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TExprParent.Destroy */ inline __fastcall virtual ~TExprLim(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprSpace;
class PASCALIMPLEMENTATION TExprSpace : public TExprClass 
{
	typedef TExprClass inherited;
	
private:
	int N;
	
protected:
	DYNAMIC int __fastcall CalcWidth(void);
	
public:
	__fastcall TExprSpace(int Space);
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprSpace(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprStrokes;
class PASCALIMPLEMENTATION TExprStrokes : public TExprClass 
{
	typedef TExprClass inherited;
	
private:
	int N;
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	
public:
	__fastcall TExprStrokes(int Strokes);
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprStrokes(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprAtValue;
class PASCALIMPLEMENTATION TExprAtValue : public TExprBigParent 
{
	typedef TExprBigParent inherited;
	
private:
	DYNAMIC void __fastcall SetDaughterFont(void);
	DYNAMIC void __fastcall SetDaughterCanvas(void);
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
	
public:
	DYNAMIC int __fastcall FTType(void);
public:
	#pragma option push -w-inl
	/* TExprBigParent.Create */ inline __fastcall TExprAtValue(TExprClass* ASon, TExprClass* ADaughter)
		 : TExprBigParent(ASon, ADaughter) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TExprBigParent.Destroy */ inline __fastcall virtual ~TExprAtValue(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprCap;
class PASCALIMPLEMENTATION TExprCap : public TExprParent 
{
	typedef TExprParent inherited;
	
private:
	TExprCapStyle Style;
	int N;
	
protected:
	int __fastcall CapWidth(void);
	int __fastcall CapHeight(void);
	int __fastcall SelfHeight(void);
	DYNAMIC int __fastcall CalcPowerXPos(void);
	DYNAMIC int __fastcall CalcPowerYPos(void);
	DYNAMIC int __fastcall CalcIndexXPos(void);
	DYNAMIC int __fastcall CalcCapDY(void);
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
	
public:
	__fastcall TExprCap(TExprClass* ASon, TExprCapStyle CapStyle, int Count);
	DYNAMIC int __fastcall FTType(void);
public:
	#pragma option push -w-inl
	/* TExprParent.Destroy */ inline __fastcall virtual ~TExprCap(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprStand;
class PASCALIMPLEMENTATION TExprStand : public TExprParent 
{
	typedef TExprParent inherited;
	
private:
	TExprHorAlign Alg;
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	
public:
	__fastcall TExprStand(TExprClass* ASon, TExprHorAlign Align);
public:
	#pragma option push -w-inl
	/* TExprParent.Destroy */ inline __fastcall virtual ~TExprStand(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprMatrix;
class PASCALIMPLEMENTATION TExprMatrix : public TExprParent 
{
	typedef TExprParent inherited;
	
private:
	int HS;
	int VS;
	int FCX;
	int FCY;
	
protected:
	void __fastcall GetCellSize(int &CX, int &CY);
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	int __fastcall GetCellWidth(void);
	int __fastcall GetCellHeight(void);
	
public:
	__fastcall TExprMatrix(TExprClass* ASon, int HorSize, int VertSize);
public:
	#pragma option push -w-inl
	/* TExprParent.Destroy */ inline __fastcall virtual ~TExprMatrix(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprGroupOp;
class PASCALIMPLEMENTATION TExprGroupOp : public TExprTwinParent 
{
	typedef TExprTwinParent inherited;
	
private:
	int FSymbolHeight;
	int FSymbolWidth;
	
protected:
	int __fastcall CalcSymbolHeight(void);
	DYNAMIC int __fastcall CalcSymbolWidth(void) = 0 ;
	DYNAMIC void __fastcall DrawSymbol(int X, int Y) = 0 ;
	DYNAMIC void __fastcall LRDrawSymbol(int X, int Y) = 0 ;
	DYNAMIC void __fastcall Paint(int X, int Y);
	int __fastcall GetSymbolWidth(void);
	int __fastcall GetSymbolHeight(void);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
	DYNAMIC int __fastcall CalcMidLine(TExprOrigin Origin);
	
public:
	__fastcall TExprGroupOp(TExprClass* ASon, TExprClass* FirstTwin, TExprClass* SecondTwin);
public:
	#pragma option push -w-inl
	/* TExprTwinParent.Destroy */ inline __fastcall virtual ~TExprGroupOp(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprSumma;
class PASCALIMPLEMENTATION TExprSumma : public TExprGroupOp 
{
	typedef TExprGroupOp inherited;
	
protected:
	DYNAMIC int __fastcall CalcSymbolWidth(void);
	DYNAMIC void __fastcall DrawSymbol(int X, int Y);
	DYNAMIC void __fastcall LRDrawSymbol(int X, int Y);
public:
	#pragma option push -w-inl
	/* TExprGroupOp.Create */ inline __fastcall TExprSumma(TExprClass* ASon, TExprClass* FirstTwin, TExprClass* 
		SecondTwin) : TExprGroupOp(ASon, FirstTwin, SecondTwin) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TExprTwinParent.Destroy */ inline __fastcall virtual ~TExprSumma(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprProd;
class PASCALIMPLEMENTATION TExprProd : public TExprGroupOp 
{
	typedef TExprGroupOp inherited;
	
protected:
	DYNAMIC int __fastcall CalcSymbolWidth(void);
	DYNAMIC void __fastcall DrawSymbol(int X, int Y);
	DYNAMIC void __fastcall LRDrawSymbol(int X, int Y);
public:
	#pragma option push -w-inl
	/* TExprGroupOp.Create */ inline __fastcall TExprProd(TExprClass* ASon, TExprClass* FirstTwin, TExprClass* 
		SecondTwin) : TExprGroupOp(ASon, FirstTwin, SecondTwin) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TExprTwinParent.Destroy */ inline __fastcall virtual ~TExprProd(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprCirc;
class PASCALIMPLEMENTATION TExprCirc : public TExprGroupOp 
{
	typedef TExprGroupOp inherited;
	
protected:
	DYNAMIC int __fastcall CalcSymbolWidth(void);
	DYNAMIC void __fastcall DrawSymbol(int X, int Y);
	DYNAMIC void __fastcall LRDrawSymbol(int X, int Y);
public:
	#pragma option push -w-inl
	/* TExprGroupOp.Create */ inline __fastcall TExprCirc(TExprClass* ASon, TExprClass* FirstTwin, TExprClass* 
		SecondTwin) : TExprGroupOp(ASon, FirstTwin, SecondTwin) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TExprTwinParent.Destroy */ inline __fastcall virtual ~TExprCirc(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprIntegral;
class PASCALIMPLEMENTATION TExprIntegral : public TExprGroupOp 
{
	typedef TExprGroupOp inherited;
	
private:
	int K;
	
protected:
	DYNAMIC int __fastcall CalcSymbolWidth(void);
	DYNAMIC void __fastcall DrawSymbol(int X, int Y);
	DYNAMIC void __fastcall LRDrawSymbol(int X, int Y);
	void __fastcall DrawHook(int H, int X, int Y);
	void __fastcall LRDrawHook(int H, int X, int Y);
	
public:
	__fastcall TExprIntegral(TExprClass* ASon, TExprClass* FirstTwin, TExprClass* SecondTwin, int Mult)
		;
public:
	#pragma option push -w-inl
	/* TExprTwinParent.Destroy */ inline __fastcall virtual ~TExprIntegral(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprLambda;
class PASCALIMPLEMENTATION TExprLambda : public TExprExtSymbol 
{
	typedef TExprExtSymbol inherited;
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	
public:
	__fastcall TExprLambda(void);
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprLambda(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprNabla;
class PASCALIMPLEMENTATION TExprNabla : public TExprExtSymbol 
{
	typedef TExprExtSymbol inherited;
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	
public:
	__fastcall TExprNabla(void);
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprNabla(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprAsterix;
class PASCALIMPLEMENTATION TExprAsterix : public TExprSimple 
{
	typedef TExprSimple inherited;
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	
public:
	__fastcall TExprAsterix(void);
public:
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprAsterix(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprCase;
class PASCALIMPLEMENTATION TExprCase : public TExprParent 
{
	typedef TExprParent inherited;
	
protected:
	DYNAMIC void __fastcall Paint(int X, int Y);
	DYNAMIC int __fastcall CalcWidth(void);
	DYNAMIC int __fastcall CalcHeight(void);
public:
	#pragma option push -w-inl
	/* TExprParent.Create */ inline __fastcall TExprCase(TExprClass* ASon) : TExprParent(ASon) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TExprParent.Destroy */ inline __fastcall virtual ~TExprCase(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExprEmpty;
class PASCALIMPLEMENTATION TExprEmpty : public TExprClass 
{
	typedef TExprClass inherited;
	
protected:
	DYNAMIC int __fastcall CalcHeight(void);
public:
	#pragma option push -w-inl
	/* TExprClass.Create */ inline __fastcall TExprEmpty(void) : TExprClass() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TExprClass.Destroy */ inline __fastcall virtual ~TExprEmpty(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint efLeft = 0x1;
static const Shortint efRight = 0x2;
static const Shortint efNegative = 0x4;
static const Shortint efRoundBrackets = 0x18;
static const Shortint efBrackets = 0x10;
static const Shortint efNumber = 0x20;
static const Shortint esMuchLess = 0x1;
static const Shortint esMuchGreater = 0x2;
static const Shortint esApproxLess = 0x3;
static const Shortint esApproxGreater = 0x4;
static const Shortint esPlusMinus = 0x5;
static const Shortint esMinusPlus = 0x6;
static const Shortint esAlmostEqual = 0x7;
static const Shortint esParallel = 0xa;
static const Shortint esPerpendicular = 0xb;
static const Shortint esAngle = 0xc;
static const Shortint esPlus = 0x2b;
static const Word esMinus = 0x2212;
static const Shortint esLess = 0x3c;
static const Shortint esEqual = 0x3d;
static const Shortint esGreater = 0x3e;
static const Word esNotEqual = 0x2260;
static const Byte esMultiply = 0xb7;
static const Word esLessOrEqual = 0x2264;
static const Word esGreaterOrEqual = 0x2265;
static const Word esApproxEqual = 0x2248;
static const Byte esCrossMultiply = 0xd7;
static const Byte esDivide = 0xf7;
static const Shortint esTilde = 0x7e;
static const Word esEquivalent = 0x2261;
static const Word esArrow = 0x2192;
static const Shortint esSlash = 0x2f;
static const Word esEllipsis = 0x2026;
static const Word esInfinum = 0x221e;
static const Word esPartDiff = 0x2202;
static const Shortint tcWidth = 0x1;
static const Shortint tcHeight = 0x2;
static const Shortint tcPowerXPos = 0x4;
static const Shortint tcPowerYPos = 0x8;
static const Shortint tcIndexXPos = 0x10;
static const Shortint tcIndexYPos = 0x20;
static const Shortint tcCapDX = 0x40;
static const Byte tcCapDY = 0x80;
static const Word tcMidLineUp = 0x100;
static const Word tcMidlineDn = 0x200;
static const Word tcCellSize = 0x400;
static const Word tcSymbolWidth = 0x400;
static const Word tcSymbolHeight = 0x800;

}	/* namespace Exprdraw */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Exprdraw;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ExprDraw
