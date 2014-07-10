//---------------------------------------------------------------------------
#include <vcl.h>
#include "MPreview2.h"
#include "bmentor.h"
#include "global.h"
#include "tkurs.h"
#include "tquest.h"
#include "headwin.h"
#include "dtask.h"
#include "qvarnt.h"
#include "nqselect.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ieopensavedlg"
#pragma link "imageenio"
#pragma resource "*.dfm"
TPreview2 *Preview2;

//---------------------------------------------------------------------------
__fastcall TPreview2::TPreview2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPreview2::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{      
        if ( Key == 38 )
        {
                Preview2->VertScrollBar->Position -= 5;
        }

        if ( Key == 33 )
        {
                Preview2->VertScrollBar->Position -= 20;
        }

        if ( Key == 40 )
        {
                Preview2->VertScrollBar->Position += 5;
        }

        if ( Key == 34 )
        {
                Preview2->VertScrollBar->Position += 20;
        }

        if ( Key == 37 )
                Preview2->HorzScrollBar->Position -= 5;

        if ( Key == 39 )
                Preview2->HorzScrollBar->Position  += 5;
}
//---------------------------------------------------------------------------

void __fastcall TPreview2::SaveBClick(TObject *Sender)
{
        if ( SaveImageEnDialog1->Execute() )
        {
                Image1->Picture->Bitmap->SaveToFile( "temp.bmp" );
                ImageEnIO1->LoadFromFile( "temp.bmp" );
                ImageEnIO1->Params->JPEG_Quality = 100;
                ImageEnIO1->SaveToFile( SaveImageEnDialog1->FileName );
                unlink( "temp.bmp" );
        }
}
//---------------------------------------------------------------------------

void __fastcall TPreview2::ExitBClick(TObject *Sender)
{
        Preview2->Close();        
}
//---------------------------------------------------------------------------

