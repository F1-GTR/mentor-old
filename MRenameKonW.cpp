//---------------------------------------------------------------------
#include <vcl.h>
#include "MRenameKonW.h"
#include "tkurs.h"
#pragma hdrstop
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TRenameKonW *RenameKonW;
//---------------------------------------------------------------------
__fastcall TRenameKonW::TRenameKonW(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TRenameKonW::OKBtnClick(TObject *Sender)
{
        int i, Flag = 0;
        extern tkurs * kurs;

        for ( i = 0; i < kurs->qlist->Count; i ++ )
        {
                bmentor* b = (bmentor*)kurs->qlist->Items[i];

                if ( b->type == JOB && !strcmp( b->name, Edit1->Text.c_str() ) )
                {
                        Flag = 1;
                        break;
                }
        }

        if ( Flag )
                ShowMessage("Измените название КР. (Такое уже есть!)");
        else
        {
                //ModalResult = mrOk;
                fl = 1;
                RenameKonW->Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TRenameKonW::CancelBtnClick(TObject *Sender)
{
        //ModalResult = mrCancel;
        fl = 0;
        RenameKonW->Close();
}
//---------------------------------------------------------------------------

void __fastcall TRenameKonW::FormActivate(TObject *Sender)
{
        fl = 0;        
}
//---------------------------------------------------------------------------

