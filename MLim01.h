//---------------------------------------------------------------------------

#ifndef MLim01H
#define MLim01H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "quelim01.h"
//---------------------------------------------------------------------------
class TLim01 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TBevel *Bevel1;
    TMemo *Memo1;
        TEdit *rmin;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
    TGroupBox *GroupBox1;
    TLabel *Label3;
    TLabel *Label4;
    TRadioButton *RadioButton1;
    TRadioButton *RadioButton2;
    TEdit *Edit3;
    TEdit *Edit4;
    TLabel *Label5;
    TLabel *Label6;
        TEdit *rmax;
    TLabel *Label24;
    TEdit *etype;
    TCheckBox *CheckBox1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall RadioButton1Click(TObject *Sender);
    void __fastcall RadioButton2Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TLim01(TComponent* Owner);
    quelim01* quest;
};

//---------------------------------------------------------------------------
extern PACKAGE TLim01 *Lim01;
//---------------------------------------------------------------------------
#endif
