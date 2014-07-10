//---------------------------------------------------------------------------
#ifndef qvarntH
#define qvarntH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include "imageenio.hpp"
#include "imageenproc.hpp"
//---------------------------------------------------------------------------
class Tqvar : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TStaticText *StaticText1;
        TButton *Button1;
        TLabel *Label1;
        TEdit *Edit2;
        TLabel *Label2;
        TEdit *Edit3;
        TButton *Button2;
        TLabel *Label3;
        TEdit *Edit4;
        TLabel *Label4;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TLabel *Label5;
        TButton *Button3;
        TFontDialog *FontDialog1;
        TCheckBox *CheckBox3;
        TImageEnIO *ImageEnIO1;
        TImageEnProc *ImageEnProc1;
        TPrintDialog *PrintDialog1;
        TButton *Button4;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tqvar(TComponent* Owner);

        int MZad;
};
//---------------------------------------------------------------------------
extern PACKAGE Tqvar *qvar;
//---------------------------------------------------------------------------
#endif
