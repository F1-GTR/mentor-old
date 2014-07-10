//---------------------------------------------------------------------
#include <vcl.h>
#include "MVarCmp.h"
#include "MConvert.h"
#include "MPreview2.h"
#include "tkurs.h"
#include "MGenKey.h"
#include "qvarnt.h"
#include "headwin.h"
#pragma hdrstop
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TCompareVar *CompareVar;
extern tkurs* kurs;
//---------------------------------------------------------------------
__fastcall TCompareVar::TCompareVar(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TCompareVar::FormCreate(TObject *Sender)
{
        ComboBox1->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TCompareVar::FormActivate(TObject *Sender)
{
        int i, j, k = 1;

        hwin->Visible = false;
        
        //Table->FixedColor = TColor(RGB(0,255,0));
        for ( i = 0; i < 8; i ++ )
                for( j = 0; j < 6; j ++ )
                {
                        Table->Cells[j][i] = IntToStr( k ++ );
                }

}
//---------------------------------------------------------------------------

void __fastcall TCompareVar::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        hwin->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TCompareVar::TableClick(TObject *Sender)
{
  TList* list = new TList();
  TList* list1 = new TList();
  TList* list2 = new TList();

  int i, j, x, y;
  int ncvar, nz = 0, ns = 1;

  CompareVar->Visible = false;

  list->Clear();

  x = Table->Col;
  y = Table->Row;

  /*ShowMessage( IntToStr( x ) + "\n" + IntToStr ( y ) );
  ShowMessage( Table->Cells[ x ][ y ] );*/

  ncvar = StrToInt( Table->Cells[ x ][ y ] );

  for( i = 0; i < kurs->qlist->Count; i ++)
  {
        bmentor* b = (bmentor*)kurs->qlist->Items[i];

        if( b->type == JOB )
        {
                if( kurs->selecttask == b )
                {

                        for( j = i + 1; j < kurs->qlist->Count; j ++ )
                        {
                                b = (bmentor*)kurs->qlist->Items[j];

                                if( b->numbertask == kurs->selecttask->number )
                                {
                                        b->nvar = ncvar;
                                        nz++;
                                        b->nzad = nz;

                                        b->keygen = ( ncvar * GenKey->GeneralKey + nz ) % 1000 + 1;

                                        b->Print(list);
                                }
                        }

                        break;
                }
        }
  }

  for( i = 0; i < list->Count; i++)
  {
        char* t = (char*)list->Items[i];

        if(strchr(t,'#'))
                ns = 1;
        if(strchr(t,'@'))
                ns = 2;
        if( ns == 1 )
                list1->Add(t);
        if( ns == 2 )
                list2->Add(t);
  }

  list->Clear();

/*  for( i = 0; i < list1->Count; i ++)
        list->Add(list1->Items[i]);

  list->Add("String(___________________________________________)");
  */

  for( i = 0; i < list2->Count; i ++)
        list->Add(list2->Items[i]);

  if( list2->Count )
  {
        Graphics::TBitmap* bmv = new Graphics::TBitmap();

        TxtToBmp ( list2, bmv, qvar->FontDialog1->Font, 0, 0 );

        Preview2->Left = 0;
        Preview2->Top = 0;

        if ( bmv->Width + 25 < Screen->Width )
                Preview2->Width = bmv->Width + 25;
        else
                Preview2->Width = Screen->Width;

        if ( bmv->Height + 30 < Screen->Height )
                Preview2->Height = bmv->Height;
        else
                Preview2->Height = Screen->Height - 30;

        Preview2->Image1->Width = bmv->Width;
        Preview2->Image1->Height = bmv->Height;

        Preview2->Image1->Picture->Bitmap = bmv;

        Preview2->Caption = "Ïðîñìîòð ÂÀÐÈÀÍÒÀ ¹" + Table->Cells[ x ][ y ];

        Preview2->ShowModal();

        delete bmv;
  }

  CompareVar->Visible = true;
  
  delete list1;
  delete list2;
  delete list;
}
//---------------------------------------------------------------------------

