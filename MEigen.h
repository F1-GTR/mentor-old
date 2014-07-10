//---------------------------------------------------------------------------

#ifndef MEigenH
#define MEigenH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "queeigens.h"
//---------------------------------------------------------------------------
class TEigen : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TBevel *Bevel1;
    TMemo *Memo1;
    TEdit *Edit1;
    TEdit *Edit2;
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
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall RadioButton1Click(TObject *Sender);
    void __fastcall RadioButton2Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    queeigens* quest;
    __fastcall TEigen(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEigen *Eigen;
//---------------------------------------------------------------------------
#endif
