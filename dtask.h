//---------------------------------------------------------------------------
#ifndef dtaskH
#define dtaskH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tptask : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TStaticText *StaticText1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label1;
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tptask(TComponent* Owner);
        int count;
};
//---------------------------------------------------------------------------
extern PACKAGE Tptask *ptask;
//---------------------------------------------------------------------------
#endif
