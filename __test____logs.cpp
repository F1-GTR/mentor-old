//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "__test____logs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
    FILE *f = fopen("C:\\text.txt", "wt");
    fwrite(Memo1->Text.c_str(),Memo1->Text.Length(),1,f);
    fclose(f);
    Close();
}
//---------------------------------------------------------------------------
