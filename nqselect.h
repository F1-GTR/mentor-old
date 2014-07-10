//---------------------------------------------------------------------------
#ifndef nqselectH
#define nqselectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tpnqselect : public TForm
{
__published:	// IDE-managed Components
        TStaticText *StaticText1;
        TEdit *Edit1;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tpnqselect(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tpnqselect *pnqselect;
//---------------------------------------------------------------------------
#endif
