//---------------------------------------------------------------------------
#ifndef qrepH
#define qrepH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tqvar : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TStaticText *StaticText1;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tqvar(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tqvar *qvar;
//---------------------------------------------------------------------------
#endif
