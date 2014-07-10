//---------------------------------------------------------------------------
#ifndef marumnH
#define marumnH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tpmatumn : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TStaticText *StaticText3;
        TStaticText *StaticText4;
        TRadioGroup *RadioGroup1;
        TEdit *Edit5;
        TEdit *Edit6;
        TStaticText *StaticText5;
        TStaticText *StaticText6;
        TStaticText *StaticText7;
        TMemo *Memo1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        quest2* quest;
        __fastcall Tpmatumn(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpmatumn *pmatumn;
//---------------------------------------------------------------------------
#endif
