//---------------------------------------------------------------------------
#include <vcl.h>
#include "MPreview3.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPreview3 *Preview3;
//---------------------------------------------------------------------------
__fastcall TPreview3::TPreview3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPreview3::N1Click(TObject *Sender)
{
        Preview3->AutoScroll = false;
        Image1->Stretch = true;
        Image1->Picture->LoadFromFile( "out.bmp" );
}
//---------------------------------------------------------------------------

void __fastcall TPreview3::N111Click(TObject *Sender)
{
        Preview3->AutoScroll = true;
        Image1->Stretch = false;
        Image1->Picture->LoadFromFile( "out.bmp" );        
}
//---------------------------------------------------------------------------

void __fastcall TPreview3::N2Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

