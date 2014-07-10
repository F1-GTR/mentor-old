//---------------------------------------------------------------------------
#include <vcl.h>
#include "MProgressForm.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProgressForm *ProgressForm;
//---------------------------------------------------------------------------
__fastcall TProgressForm::TProgressForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
