//---------------------------------------------------------------------------

#ifndef MIntegRndH
#define MIntegRndH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "queintegrnd.h"

//---------------------------------------------------------------------------
class TIntegRnd : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TBevel *Bevel1;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label24;
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
    TEdit *rmax;
    TEdit *etype;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall RadioButton1Click(TObject *Sender);
    void __fastcall RadioButton2Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TIntegRnd(TComponent* Owner);
    queIntegRnd *quest;
};
//---------------------------------------------------------------------------
extern PACKAGE TIntegRnd *IntegRnd;
//---------------------------------------------------------------------------
#endif
