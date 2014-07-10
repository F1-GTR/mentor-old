//---------------------------------------------------------------------------
#ifndef ParabH
#define ParabH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "quest16.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TParab : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TRadioGroup *RadioGroup1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TLabel *Label3;
        TEdit *Edit3;
        TLabel *Label4;
        TEdit *Edit4;
        TLabel *Label5;
        TComboBox *ComboBox1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
         quest16* quest;
        __fastcall TParab(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TParab *Parab;
//---------------------------------------------------------------------------
#endif
