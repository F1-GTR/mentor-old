//---------------------------------------------------------------------------
#include <vcl.h>
#include "MEditWork.h"
#include "tkurs.h"
#include "global.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditWork *EditWork;

extern tkurs * kurs;
//---------------------------------------------------------------------------
__fastcall TEditWork::TEditWork(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TEditWork::FormCreate(TObject *Sender)
{
        EL = new TList;
}
//---------------------------------------------------------------------------
void __fastcall TEditWork::N1Click(TObject *Sender)
{
        int i;
        int count;

        TStringList * List = new TStringList;

        kurs->qlist->Items[ ListBox1->ItemIndex + FirstNumber ] = NULL;

        EL->Remove ( EL->Items[ ListBox1->ItemIndex ] );

        for ( i = 0; i < ListBox1->Items->Count; i ++ )
        {
                if ( i != ListBox1->ItemIndex )
                {
                        count = ListBox1->Items->Strings[i].AnsiPos( "." );

                        ListBox1->Items->Strings[i].Delete( 1, count );

                        List->Add ( ListBox1->Items->Strings[i].Delete( 1, count ) );
                }
                else
                        continue;
        }

        ListBox1->Clear();

        for ( i = 0; i < EL->Count; i ++ )
        {
                ListBox1->Items->Add ( IntToStr( i + 1 ) + "." + List->Strings[i] );
        }

        kurs->qlist->Pack();
        delete List;
}
//---------------------------------------------------------------------------
void __fastcall TEditWork::N2Click(TObject *Sender)
{
        //Edit = 1;
        Index1 = ListBox1->ItemIndex;
        //ListBox1->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TEditWork::ListBox1Click(TObject *Sender)
{
/*        if ( Edit )
        {
                int i;
                int count;

                TStringList * List = new TStringList;

                AnsiString temp;

                Index2 = ListBox1->ItemIndex;

                kurs->qlist->Exchange( FirstNumber + Index1, FirstNumber + Index2 );

                EL->Exchange( Index1, Index2 );

                temp = ListBox1->Items->Strings[ Index1 ];
                ListBox1->Items->Strings[ Index1 ] = ListBox1->Items->Strings[ Index2 ];
                ListBox1->Items->Strings[ Index2 ] = temp;

                for ( i = 0; i < ListBox1->Items->Count; i ++ )
                {
                        count = ListBox1->Items->Strings[i].AnsiPos( "." );

                        List->Add ( ListBox1->Items->Strings[i].Delete( 1, count ) );
                }

                ListBox1->Clear();

                for ( i = 0; i < EL->Count; i ++ )
                {
                        ListBox1->Items->Add ( IntToStr( i + 1 ) + "." + List->Strings[i] );
                }

                delete List;

                Edit = 0;
        }
        */
        int i;
        int count;
        int Ind;

        TStringList * List = new TStringList;

        switch ( Edit )
        {
                case DELETEQUEST:
                        /*int i;
                        int count;*/

                        //TStringList * List = new TStringList;

                        kurs->qlist->Items[ ListBox1->ItemIndex + FirstNumber ] = NULL;

                        EL->Remove ( EL->Items[ ListBox1->ItemIndex ] );

                        for ( i = 0; i < ListBox1->Items->Count; i ++ )
                        {
                                if ( i != ListBox1->ItemIndex )
                                {
                                        count = ListBox1->Items->Strings[i].AnsiPos( "." );

                                        ListBox1->Items->Strings[i].Delete( 1, count );

                                        List->Add ( ListBox1->Items->Strings[i].Delete( 1, count ) );
                                }
                                else
                                        continue;
                        }

                        ListBox1->Clear();

                        for ( i = 0; i < EL->Count; i ++ )
                        {
                                ListBox1->Items->Add ( IntToStr( i + 1 ) + "." + List->Strings[i] );
                        }

                        kurs->qlist->Pack();
                        delete List;

                break;
                case SWAPQUEST_A:
                        Index1 = ListBox1->ItemIndex;
                        Edit = SWAPQUEST_B;
                break;
                case SWAPQUEST_B:
                        /*int i;
                        int count;
                        TStringList * List = new TStringList;*/

                        AnsiString temp;

                        Index2 = ListBox1->ItemIndex;
                        Ind = Index2;

                        kurs->qlist->Exchange( FirstNumber + Index1, FirstNumber + Index2 );

                        EL->Exchange( Index1, Index2 );

                        temp = ListBox1->Items->Strings[ Index1 ];
                        ListBox1->Items->Strings[ Index1 ] = ListBox1->Items->Strings[ Index2 ];
                        ListBox1->Items->Strings[ Index2 ] = temp;

                        for ( i = 0; i < ListBox1->Items->Count; i ++ )
                        {
                                count = ListBox1->Items->Strings[i].AnsiPos( "." );

                                List->Add ( ListBox1->Items->Strings[i].Delete( 1, count ) );
                        }

                        ListBox1->Clear();

                        for ( i = 0; i < EL->Count; i ++ )
                        {
                                ListBox1->Items->Add ( IntToStr( i + 1 ) + "." + List->Strings[i] );
                        }

                        delete List;

                        ListBox1->ItemIndex = Ind;

                        Edit = SWAPQUEST_A;
                break;
        }
}
//---------------------------------------------------------------------------
