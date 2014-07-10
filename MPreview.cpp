//---------------------------------------------------------------------------
#include <vcl.h>
#include <printers.hpp>
#include "MPreview.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ieview"
#pragma link "imageenview"
#pragma link "imageenio"
#pragma link "imageenproc"
#pragma link "ieopensavedlg"
#pragma resource "*.dfm"
TPreview *Preview;
//---------------------------------------------------------------------------
__fastcall TPreview::TPreview(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPreview::N2Click(TObject *Sender)
{
        /*Graphics::TBitmap* bmv = new Graphics::TBitmap();

        if (PrintDialog1->Execute() == True)
        {
                //bmv = Image1->Picture->Bitmap;
                bmv->LoadFromFile("out.bmp");

                Printer()->BeginDoc();
                Printer()->Canvas->Draw(10,10,bmv);
                Printer()->EndDoc();
        }

        delete bmv;*/
}
//---------------------------------------------------------------------------

void __fastcall TPreview::N4Click(TObject *Sender)
{
        //N2Click(Sender);
        ImageEnIO1->DoPrintPreviewDialog( iedtDialog, "Просмотр печати", true, "Печать" );
}
//---------------------------------------------------------------------------

void __fastcall TPreview::N5Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TPreview::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        /*if ( Key == 38 )
        {
                Preview->VertScrollBar->Position -= 5;
        }

        if ( Key == 33 )
        {
                Preview->VertScrollBar->Position -= 20;
        }

        if ( Key == 40 )
        {
                Preview->VertScrollBar->Position += 5;
        }

        if ( Key == 34 )
        {
                Preview->VertScrollBar->Position += 20;
        }

        if ( Key == 37 )
                Preview->HorzScrollBar->Position -= 5;

        if ( Key == 39 )
                Preview->HorzScrollBar->Position  += 5;
                */
}
//---------------------------------------------------------------------------

void __fastcall TPreview::FormActivate(TObject *Sender)
{
        //ImageEnProc1->Resample( -1, Screen->Height - 40, rfFastLinear );
        ImageEnView1->ZoomFilter = rfFastLinear;
        ImageEnView1->Zoom = 200;//ImageEnView1->GetIdealZoom();

        //ImageEnIO1->SaveToFileBMP( "temp.bmp" );
}
//---------------------------------------------------------------------------

