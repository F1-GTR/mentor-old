//---------------------------------------------------------------------------
#ifndef matlinH
#define matlinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "quest1.h"

//---------------------------------------------------------------------------
class Tpmatlin : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TStaticText *StaticText3;
        TStaticText *StaticText4;
        TStaticText *StaticText5;
        TStaticText *StaticText6;
        TEdit *Edit5;
        TButton *Button3;
        TRadioGroup *RadioGroup1;
        TEdit *Edit6;
        TMemo *Memo1;
        TStaticText *StaticText7;
        TButton *Button4;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tpmatlin(TComponent* Owner);
        quest1* quest;
};
//---------------------------------------------------------------------------
extern PACKAGE Tpmatlin *pmatlin;
//---------------------------------------------------------------------------
#endif
