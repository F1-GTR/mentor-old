//---------------------------------------------------------------------
#include <vcl.h>
#include "bmentor.h"
#include "tkurs.h"
#include "MPrint.h"
#include "qvarnt.h"
#include "MGenKey.h"
#include "MConvert.h"
#pragma hdrstop
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TPrintKW *PrintKW;
//---------------------------------------------------------------------

__fastcall TPrintKW::TPrintKW(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TPrintKW::FormActivate(TObject *Sender)
{
        Caption = "Подготовка к печати КР";

        TList* list = new TList();

        int left, top, numb, kvar, x, y;
        int ncvar, i, j, k;
        int nz = 0;
        int ns = 1;

        TFont * Font;

        numb = StrToInt( qvar->Edit4->Text );
        kvar = StrToInt( qvar->Edit1->Text );

        Printer()->BeginDoc();

        ProgressBar1->Max = kvar;

        //------
        for( ncvar = numb; ncvar < kvar + numb; ncvar++ )
        {
                list->Clear();

                Printer()->NewPage();

                for( i = 0; i < kurs->qlist->Count; i ++ )
                {
                        bmentor* b = (bmentor*)kurs->qlist->Items[i];

                        if( b->type == JOB )
                        {
                                if( kurs->selecttask == b )
                                {
                                        nz = 0;

                                        for( j = i + 1; j < kurs->qlist->Count; j ++ )
                                        {
                                                b = (bmentor*)kurs->qlist->Items[j];

                                                if( b->numbertask == kurs->selecttask->number )
                                                {
                                                        b->nvar = ncvar;
                                                        nz ++;
                                                        b->nzad = nz;

                                                        b->keygen = ( ncvar * GenKey->GeneralKey + nz ) % 1000 + 1;

                                                        b->Print(list);
                                                }
                                        }

                                        break;
                                }
                       }
                }

                TList* list1 = new TList();
                TList* list2 = new TList();

                ns = 1;

                for( i = 0; i < list->Count; i++ )
                {
                        char* t = (char*)list->Items[i];

                        if( strchr(t,'#') )
                                ns = 1;
                        if( strchr(t,'@') )
                                ns = 2;
                        if( ns == 1 )
                                list1->Add(t);
                        if( ns == 2 )
                                list2->Add(t);
                }

                list->Clear();

                for( i = 0; i < list1->Count; i ++ )
                        list->Add(list1->Items[i]);

                list->Add("String(___________________________________________)");

                for( i = 0; i < list2->Count; i ++ )
                        list->Add(list2->Items[i]);

                if ( qvar->CheckBox1->Checked == true )
                {
                        if( list1->Count )
                        {
                                left = StrToInt( qvar->Edit2->Text );
                                top = StrToInt( qvar->Edit3->Text );

                                Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                TxtToBmp ( list1, bmv, qvar->FontDialog1->Font, left, top );

                                bmv->SaveToFile( "out.bmp" );

                                delete bmv;

                                FilePrint( "out.bmp" );

                                /*if( ncvar < kvar + numb - 1 )
                                        Printer()->NewPage();*/
                        }
                }
                else
                if ( qvar->CheckBox2->Checked == true )
                {
                        if( list2->Count )
                        {
                                left = StrToInt( qvar->Edit2->Text );
                                top = StrToInt( qvar->Edit3->Text );

                                Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                TxtToBmp ( list2, bmv, qvar->FontDialog1->Font, left, top );

                                bmv->SaveToFile( "out.bmp" );

                                delete bmv;

                                FilePrint( "out.bmp" );

                                /*if( ncvar < kvar + numb - 1 )
                                        Printer()->NewPage();*/
                        }
                }
                else
                if ( qvar->RadioButton1->Checked == true )
                {
                        if( list->Count )
                        {
                                left = StrToInt( qvar->Edit2->Text );
                                top = StrToInt( qvar->Edit3->Text );

                                Font = qvar->FontDialog1->Font;

                                Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                TxtToBmp ( list, bmv, Font, left, top );

                                bmv->SaveToFile("out.bmp");

                                delete bmv;

                                FilePrint( "out.bmp" );

                                /*if( ncvar < kvar + numb - 1 )
                                        Printer()->NewPage();*/
                        }
                }
                else
                if( qvar->RadioButton2->Checked == true )
                {
                        if( list1->Count )
                        {
                                left = StrToInt( qvar->Edit2->Text );
                                top = StrToInt( qvar->Edit3->Text );

                                Font = qvar->FontDialog1->Font;

                                Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                TxtToBmp ( list1, bmv, Font, left, top );

                                bmv->SaveToFile("out.bmp");

                                delete bmv;

                                FilePrint( "out.bmp" );

                                /*if( ncvar < kvar + numb - 1 )
                                        Printer()->NewPage();*/
                        }

                        if( list2->Count )
                        {
                                left = StrToInt( qvar->Edit2->Text );
                                top = StrToInt( qvar->Edit3->Text );

                                Font = qvar->FontDialog1->Font;

                                Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                TxtToBmp ( list2, bmv, Font, left, top );

                                bmv->SaveToFile("out.bmp");

                                delete bmv;

                                FilePrint( "out.bmp" );

                                /*if( ncvar < kvar + numb - 1 )
                                        Printer()->NewPage();*/
                        }
                }

                ProgressBar1->Position ++;

                //Printer()->NewPage();

                /*if( list->Count )
                {
                        Graphics::TBitmap* bmv = new Graphics::TBitmap();

                        TxtToBmp ( list, bmv, qvar->FontDialog1->Font, left, top );

                        bmv->SaveToFile( "out.bmp" );

                        delete bmv;

                        FilePrint( "out.bmp" );
                }*/

                delete list1;
                delete list2;
        }

        delete list;
        //----
        /*
        for( ncvar = numb; ncvar < kvar + numb; ncvar++ )
        {
                list->Clear();
                list1->Clear();
                list2->Clear();

                nz = 0;
                //randomize();

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

                                                if( b->numbertask == kurs->selecttask->number)
                                                {
                                                        b->nvar = ncvar;
                                                        nz++;
                                                        b->nzad = nz;
                                                        //b->keygen = 0;
                                                        b->keygen = ( ncvar * GenKey->GeneralKey + nz ) % 1000 + 1;
                                                        b->Print(list);
                                                }
                                        }

                                        break;
                                }
                        }
                }

                ns = 1;

                for( i = 0; i < list->Count; i ++ )
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

                for( i = 0; i < list1->Count; i ++)
                        list->Add(list1->Items[i]);

                list->Add("String(___________________________________________)");

                for( i = 0; i < list2->Count; i ++)
                        list->Add(list2->Items[i]);

                list->Add("String(___________________________________________)");

                if ( qvar->CheckBox1->Checked == true )
                {
                        if( list1->Count )
                        {
                                left = StrToInt( qvar->Edit2->Text );
                                top = StrToInt( qvar->Edit3->Text );

                                Font = qvar->FontDialog1->Font;

                                Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                TxtToBmp ( list1, bmv, Font, left, top );

                                bmv->SaveToFile("out.bmp");

                                delete bmv;

                                FilePrint( "out.bmp" );
                        }
                }
                else
                if ( qvar->CheckBox2->Checked == true )
                {
                        if( list2->Count )
                        {
                                left = StrToInt(qvar->Edit2->Text);
                                top = StrToInt(qvar->Edit3->Text);

                                Font = qvar->FontDialog1->Font;

                                Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                TxtToBmp ( list2, bmv, Font, left, top );

                                bmv->SaveToFile("out.bmp");

                                delete bmv;

                                FilePrint( "out.bmp" );
                        }
                }
                else
                if ( qvar->RadioButton1->Checked == true )
                {
                        if( list->Count )
                        {
                                left = StrToInt(qvar->Edit2->Text);
                                top = StrToInt(qvar->Edit3->Text);

                                Font = qvar->FontDialog1->Font;

                                Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                TxtToBmp ( list, bmv, Font, left, top );

                                bmv->SaveToFile("out.bmp");

                                delete bmv;

                                FilePrint( "out.bmp" );
                        }
                }
                else
                if( qvar->RadioButton2->Checked == true )
                {
                        if( list1->Count )
                        {
                                left = StrToInt(qvar->Edit2->Text);
                                top = StrToInt(qvar->Edit3->Text);

                                Font = qvar->FontDialog1->Font;

                                Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                TxtToBmp ( list1, bmv, Font, left, top );

                                bmv->SaveToFile("out.bmp");

                                delete bmv;

                                FilePrint( "out.bmp" );
                        }

                        if( list2->Count )
                        {
                                left = StrToInt(qvar->Edit2->Text);
                                top = StrToInt(qvar->Edit3->Text);

                                Font = qvar->FontDialog1->Font;

                                Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                TxtToBmp ( list2, bmv, Font, left, top );

                                bmv->SaveToFile("out.bmp");

                                delete bmv;

                                FilePrint( "out.bmp" );
                        }
                }

                ProgressBar1->Position ++;

                Printer()->NewPage();
        }*/

        Printer()->EndDoc();

        //PrintKW->Close();
}
//---------------------------------------------------------------------------

