//---------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include "MGenKey.h"
#pragma hdrstop
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TGenKey *GenKey;
//---------------------------------------------------------------------
__fastcall TGenKey::TGenKey(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TGenKey::FormCreate(TObject *Sender)
{
        randomize();

        GeneralKey = random( 1000 ) + 1;        
}
//---------------------------------------------------------------------------

void __fastcall TGenKey::OKBtnClick(TObject *Sender)
{
        int temp;

        temp = StrToInt( Edit1->Text );

        if ( temp >=1 && temp <= 1000 )
        {
                GeneralKey = temp;
                Close();
        }
        else
        {
                ShowMessage( " люч должен быть от 1 до 1000." );
        }
}
//---------------------------------------------------------------------------

void __fastcall TGenKey::CancelBtnClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TGenKey::FormActivate(TObject *Sender)
{
        Edit1->Text = IntToStr( GeneralKey );        
}
//---------------------------------------------------------------------------

