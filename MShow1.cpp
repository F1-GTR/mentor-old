//---------------------------------------------------------------------------
#include <vcl.h>
#include "MShow1.h"
#include "bmentor.h"
#include "tkurs.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMShow *MShow;
//---------------------------------------------------------------------------
__fastcall TMShow::TMShow(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMShow::ListBox1Click(TObject *Sender)
{
        bmentor * b = new bmentor;
        b = (bmentor *)lst->Items[ ListBox1->ItemIndex ];
        b->Edit();
        save_quest = true;
        //delete b;
}
//---------------------------------------------------------------------------

void __fastcall TMShow::FormCreate(TObject *Sender)
{
        lst = new TList();
}
//---------------------------------------------------------------------------


void __fastcall TMShow::N1Click(TObject *Sender)
{
        int i;
        extern tkurs * kurs;

        int chislo = 0;

        bmentor * b;

        for(int j = i + 1; j < kurs->qlist->Count; j ++)
        {
                b = (bmentor*)kurs->qlist->Items[j];

                if ( b->numbertask == kurs->selecttask->number )
                {
                        chislo ++;

                        if ( chislo == ListBox1->ItemIndex - 1)
                                kurs->qlist->Items[i] = NULL;

                }

                                //MShow->Height = (chislo + 1)* 20 + 35;
        }

/*        for( i = 0; i < kurs->qlist->Count; i ++ )
        {
                bmentor* b = (bmentor*)kurs->qlist->Items[i];

                AnsiString tmp = ListBox1->Items->Strings[ListBox1->ItemIndex];

                if( b->type == QUEST && !tmp.AnsiCompare( b->name ) )
                {
                        if( b->numbertask == kurs->selecttask->number )
                        {
                                int n = b->number;

                                kurs->qlist->Items[i] = NULL;

                                for( int j = i + 1; j < kurs->qlist->Count; j ++ )
                                {
                                        b = (bmentor*)kurs->qlist->Items[j];

                                        if( b->numbertask == n )
                                                kurs->qlist->Items[j] = NULL;
                                }

                                break;
                        }
                }
        }
*/
        kurs->qlist->Pack();

        //int chislo = 0;

/*        ListBox1->Clear();

                                for(int j = i + 1; j < kurs->qlist->Count; j ++)
                                {
                                        b = (bmentor*)kurs->qlist->Items[j];

                                if ( b->numbertask == kurs->selecttask->number )
                                {
                                        chislo ++;
                                        MShow->ListBox1->Items->Add( IntToStr(chislo) + "." + b->name );
                                        MShow->lst->Add( b );
                                }

                                //MShow->Height = (chislo + 1)* 20 + 35;
                                }
        //save->Enabled = true;
        //FormActivate(NULL);*/
}
//---------------------------------------------------------------------------

