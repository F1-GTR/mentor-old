//---------------------------------------------------------------------------
#ifndef mateigvH
#define mateigvH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "quest3.h"
//---------------------------------------------------------------------------
class Tpmateigv : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TStaticText *StaticText3;
        TEdit *Edit4;
        TStaticText *StaticText4;
        TMemo *Memo1;
        TStaticText *StaticText5;
        TRadioGroup *RadioGroup1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TEdit *Edit5;
        TEdit *Edit6;
        TStaticText *StaticText6;
        TStaticText *StaticText7;
        TButton *Button4;
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tpmateigv(TComponent* Owner);
        quest3* quest;
};
//---------------------------------------------------------------------------
extern PACKAGE Tpmateigv *pmateigv;
//---------------------------------------------------------------------------
#endif
