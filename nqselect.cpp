//---------------------------------------------------------------------------
#include <vcl.h>
#include "nqselect.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tpnqselect *pnqselect;
//---------------------------------------------------------------------------
__fastcall Tpnqselect::Tpnqselect(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tpnqselect::Button1Click(TObject *Sender)
{
  ModalResult = 1;
}
//---------------------------------------------------------------------------

