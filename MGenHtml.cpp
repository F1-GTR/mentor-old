//---------------------------------------------------------------------
#include <vcl.h>
#include "MGenHtml.h"
#include "MMentorConfig.h"
#include "MConvert.h"
#include "test_class.h"
#include "tkurs.h"
#include "MGenKey.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------
#pragma link "imageenio"
#pragma resource "*.dfm"
TGenHtml *GenHtml;
//---------------------------------------------------------------------
__fastcall TGenHtml::TGenHtml(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TGenHtml::OKBtnClick(TObject *Sender)
{
    this->Enabled = false;
    OKBtn->Enabled = false; CancelBtn->Enabled = false;
        if( !CheckBox1->Checked )
                gen_test( StrToInt( Edit1->Text ) );
        else
                gen_for_redclass( StrToInt( Edit1->Text ) );
    OKBtn->Enabled = true; CancelBtn->Enabled = true;
    this->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::FormActivate(TObject *Sender)
{
        ProgressBar1->Position = 0;
}
//---------------------------------------------------------------------------


void __fastcall TGenHtml::Button2Click(TObject *Sender)
{
        if( SaveDialog1->Execute() )
                Edit2->Text = SaveDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::FormCreate(TObject *Sender)
{
        Edit2->Text = GetCurrentDir() + "\\kurs.zip";
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::gen_test( int NVar )
{

        int variant, i, j, k, Numb_Zad = 0;
        int max, sch, num_var;

        AnsiString kurs_name;

        class test tst;

        char str[256];

        TList * list = new TList;
        TStringList * VarHtml = new TStringList;
        TStringList * Right = new TStringList;
        TStringList * NumZ = new TStringList;

        variant = NVar;

        for( i = 0; i < kurs->qlist->Count; i ++ )
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
                                                Numb_Zad ++ ;

                                        }
                                }

                                break;
                        }
                }
        }

        max = variant * Numb_Zad;
        ProgressBar1->Max = max;

        for( num_var = 1; num_var <= variant; num_var ++ )
        {
                list->Clear();

                for( i = 0; i < kurs->qlist->Count; i ++)
                {
                        bmentor* b = (bmentor*)kurs->qlist->Items[i];

                        if( b->type == JOB )
                        {
                                if( kurs->selecttask == b )
                                {
                                        int nz = 0;

                                        for( j = i + 1; j < kurs->qlist->Count; j ++)
                                        {
                                                b = (bmentor*)kurs->qlist->Items[j];

                                                if( b->numbertask == kurs->selecttask->number )
                                                {
                                                        b->nvar = num_var;
                                                        nz++;
                                                        b->nzad = nz;

                                                        b->keygen = ( num_var * GenKey->GeneralKey + nz ) % 1000 + 1;

                                                        list->Clear();
                                                        b->Print(list, tst );

                                                        TList* list1 = new TList();
                                                        TList* list2 = new TList();
                                                        list1->Clear();
                                                        list2->Clear();
                                                        Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                                        int ns = 2;

                                                        for ( int pp = 0; pp < list->Count; pp ++ )
                                                        {
                                                                char* t = (char*)list->Items[pp];

                                                                if(strchr(t,'#'))
                                                                        ns = 1;
                                                                if(strchr(t,'@'))
                                                                        ns = 2;

                                                                if( ns == 1 )
                                                                        list1->Add(t);
                                                                if( ns == 2 )
                                                                        list2->Add(t);
                                                        }

                                                        Right->Add( IntToStr( tst.right_ask ) );



                                                        TxtToBmp ( list1, bmv, qvar->FontDialog1->Font, 0, 0 );
                                                        bmv->SaveToFile( "temp.bmp" );
                                                        ImageEnIO1->LoadFromFile( "temp.bmp" );
                                                        ImageEnIO1->Params->JPEG_Quality = 100;

                                                        ProgressBar1->Position ++;

                                                        kurs_name = "tmp_kurs";
                                                        CreateDir( kurs_name );

                                                        sprintf( str, "Image_%d_zad_%d.jpg", num_var, nz );
                                                        ImageEnIO1->SaveToFile( GetCurrentDir() + "\\" + kurs_name + "\\" + str);

                                                        //FOR REDLAB Картинка вопрос и ответы. У каждого вопроса своё уникальное имя файла - Image_№варианта_zad_№задания.jpg.
                                                        //FOR REDLAB В переменной tst хранятся параметры теста.
                                                        //FOR REDLAB Ниже должен располагаться код для ввода в REDLAB.

                                                        unlink( "temp.bmp" );
                                                        delete bmv;

                                                        VarHtml->Clear();
                                                        VarHtml->Add("<html><head>");
                                                        VarHtml->Add("    <meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1251\">" );
                                                        VarHtml->Add("<title>Вариант для тренировки. </title>");

                                                        VarHtml->Add( "<script type=\"text/javascript\">" );
                                                        VarHtml->Add( "function dataSelect(f) { " );
                                                        VarHtml->Add( "n = f.ask.selectedIndex" );
                                                        VarHtml->Add( AnsiString( "location.href = \"../mod_prov.php?id_user=\" + f.id_user.value + \"&id_kurs=\" + f.id_kurs.value + \"&ask_numb=\" + f.ask.options[n].value + \"&level=") + IntToStr( nz ) + "\"" );

                                                        VarHtml->Add( "}" );
                                                        VarHtml->Add( "</script>" );

                                                        VarHtml->Add("</head>");
                                                        VarHtml->Add("<body>");
                                                        VarHtml->Add("<form>");
                                                        VarHtml->Add("<?php");
                                                        VarHtml->Add("$id_kurs = $_GET[id_kurs];");
                                                        VarHtml->Add("$id_user = $_GET[id_user];");
                                                        VarHtml->Add("echo \"<input type=\\\"hidden\\\" name=\\\"id_kurs\\\"  value=\\\"$id_kurs\\\" >\\n\";");
                                                        VarHtml->Add("echo \"<input type=\\\"hidden\\\" name=\\\"id_user\\\"  value=\\\"$id_user\\\" >\\n\";");
                                                        VarHtml->Add("?>");

                                                        sprintf( str, "Вариант №%d:", num_var );
                                                        VarHtml->Add( str );
                                                        VarHtml->Add("<p>");
                                                        sprintf( str, "Image_%d_zad_%d.jpg", num_var, nz );
                                                        VarHtml->Add( AnsiString( "<Img src= \'" ) + str + "\' >");

                                                        VarHtml->Add( "<p>" );
                                                        VarHtml->Add( "Ваш ответ:" );
                                                        VarHtml->Add( "<p>" );
                                                        VarHtml->Add( "<select name=\"ask\" onchange=\"\"> " );

                                                        for( sch = 0; sch < tst.ch_ask; sch ++ )
                                                        {
                                                                sprintf( str, "<option value=\"%d\"> Вариант %c) </option>", sch + 1, 'a' + sch );
                                                                VarHtml->Add( str );
                                                        }

                                                        VarHtml->Add( "</select>" );

                                                        VarHtml->Add( "<p>" );
                                                        VarHtml->Add( "<input type=\"button\" value=\"Ответить\" onClick=\"dataSelect(this.form)\"> ");

                                                        VarHtml->Add("</form>");
                                                        VarHtml->Add("</body>");
                                                        VarHtml->Add("</html>");

                                                        sprintf( str, "\\var_%d_zad_%d.php", num_var, nz );
                                                        VarHtml->SaveToFile( GetCurrentDir() + "\\" + kurs_name + "\\" + str );

                                                        delete list1;
                                                        delete list2;
                                                        //this->Refresh();
                                                        Application->ProcessMessages();
                                                }
                                        }

                                        Numb_Zad = nz;
                                        break;
                                }
                        }
                }


        }

        Right->SaveToFile(  GetCurrentDir() + "\\" + kurs_name + "\\right.txt" );

        NumZ->Clear();
        NumZ->Add( kurs_name );
        NumZ->Add( kurs->selecttask->name );
        NumZ->Add( IntToStr( variant ) );
        NumZ->Add( IntToStr( Numb_Zad ) );
        NumZ->SaveToFile( GetCurrentDir() + "\\" + kurs_name + "\\Number.txt" );

        delete list;
        delete VarHtml;
        delete Right;
        delete NumZ;
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::gen_for_redclass( int NVar )
{
}
//---------------------------------------------------------------------------



