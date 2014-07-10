//---------------------------------------------------------------------
#include <vcl.h>
#include "MKRVar.h"
#include "MPreview2.h"
#include "MGenKey.h"
#include "MConvert.h"
#include "qvarnt.h"
#pragma hdrstop
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TKRVar *KRVar;
//---------------------------------------------------------------------
__fastcall TKRVar::TKRVar(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TKRVar::OKBtnClick(TObject *Sender)
{
        TList* list = new TList();
        int nz = 0;
        int kg = StrToInt( Password->Text );
        int ncvar = StrToInt( Edit1->Text );

        for(int i = 0; i < kurs->qlist->Count; i ++)
        {
                bmentor* b = (bmentor*)kurs->qlist->Items[i];

                if( b->type == JOB )
                {
                        if( kurs->selecttask == b )
                        {
                                for(int j = i + 1; j < kurs->qlist->Count; j ++)
                                {
                                        b = (bmentor*)kurs->qlist->Items[j];

                                        if( b->numbertask == kurs->selecttask->number)
                                        {
                                                b->nvar = ncvar;
                                                nz++;
                                                b->nzad = nz;
                                                b->keygen = ( ncvar * kg + nz ) % 1000 + 1;

                                                b->Print(list);
                                        }
                                }
                        }
                }
        }

        TList* list1 = new TList();
        TList* list2 = new TList();

        int ns = 1;

        for(int i = 0; i < list->Count; i ++)
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

        for(int i = 0; i < list1->Count; i ++)
                list->Add(list1->Items[i]);

        list->Add("String(___________________________________________)");

        for(int i = 0; i < list2->Count; i ++)
                list->Add(list2->Items[i]);

        if( list->Count )
        {
                /*FILE* f = fopen("txtout.txt","wt");

                for(int i = 0; i < list->Count; i ++)
                {
                        fprintf(f,"%s\n",(char*)list->Items[i]);
                }

                fclose(f);

                WinExec("txt2bmp.exe",SW_SHOWDEFAULT);

                Preview3->Image1->Picture->LoadFromFile( "out.bmp" );
                Preview3->ShowModal();*/

                Graphics::TBitmap* bmv = new Graphics::TBitmap();

                TxtToBmp ( list, bmv, qvar->FontDialog1->Font, 10, 10 );

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

                //Preview2->ImageEnIO1->AttachedBitmap = Preview2->Image1->Picture->Bitmap;
                Preview2->Image1->Picture->Bitmap = bmv;

                Preview2->Caption = "ÂÀÐÈÀÍÒ ¹" + IntToStr(ncvar);

                Preview2->ShowModal();

                delete bmv;
        }
}
//---------------------------------------------------------------------------

void __fastcall TKRVar::FormActivate(TObject *Sender)
{
        Password->Text = IntToStr( GenKey->GeneralKey );
}
//---------------------------------------------------------------------------

