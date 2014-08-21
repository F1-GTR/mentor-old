//---------------------------------------------------------------------
#include <vcl.h>
#include "MGenHtml.h"
#include "MMentorConfig.h"
#include "MConvert.h"
#include "test_class.h"
#include "tkurs.h"
#include "MGenKey.h"
#include "qvarnt.h"
#include "unit1.h"
#pragma hdrstop
//---------------------------------------------------------------------
#pragma link "imageenio"
#pragma resource "*.dfm"
TGenHtml *GenHtml;

bool TrueStr(AnsiString str)
{
        char* ch = "/\\#*:?\"<>| ";
        if (strlen(str.c_str()) < 1)
                return false;
        for (int i = 0; i < strlen(str.c_str()); i ++)
        {
                if (AnsiStrScan(ch,str.c_str()[i]))
                        return false;
        }
        return true;
}

void SlashReplace(char str[])
{
        while(strchr(str,'\\') != NULL)
        {
            strstr(str,"\\")[0] = '/';
        }

}


void ConvertToMoodle(char * kname)
{
        char dir[255];
        strcpy(dir, "-d \"");
        strcat(dir,GetCurrentDir().c_str());
        strcat(dir,"\\");
        strcat(dir,kname);
        strcat(dir,"\\\"");
        Log->Add(dir);
        SlashReplace(dir);
        //preparation strings

        AnsiString workdir = ExtractFilePath(Application->ExeName)+"utility\\mentor2moodle\\";
        AnsiString utility = workdir + "toMoodleXML.exe";


         /** Call the utility */
        Log->Add(dir);
        Log->Add(utility.c_str());
        Log->Add("Start converting..");
        /*
        SHELLEXECUTEINFO sei;
        sei.cbSize = sizeof(sei);
        sei.fMask = SEE_MASK_NOCLOSEPROCESS;
        sei.lpVerb = NULL;
        sei.lpFile = utility.c_str();
        sei.lpParameters = strdup(dir);
        sei.lpDirectory = workdir.c_str();
        sei.nShow = SW_HIDE;
        ShellExecuteEx(&sei);
        // ... wait while it works
        WaitForSingleObject(sei.hProcess, INFINITE);
        */
        ShellExecute(0,"open",utility.c_str(),dir,0,SW_SHOW); //запускаем

        /*(char tmp[255];
        strcpy(tmp,utility.c_str());
        strcat(tmp," ");
        strcat(tmp,dir);
        Log->Add(tmp);
        WinExec(tmp, SW_SHOW); */
        Log->Add("Converting completed.. Possibly..");

}

//---------------------------------------------------------------------
__fastcall TGenHtml::TGenHtml(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TGenHtml::OKBtnClick(TObject *Sender)
{
    char *str = "/\\#*:?\"<>| ";
    if (TrueStr(KName->Text))
    {
     KursName = KName->Text;
     SOut->Lines->Add("Generating start for '"+KursName+"' with "+StrToInt(Edit1->Text)+" variants");

     //this->Enabled = false;
     OKBtn->Enabled = false; CancelBtn->Enabled = false;



     gen_test( StrToInt( Edit1->Text ) );
     SOut->Lines->Add("Generating complete");
     SOut->Lines->Add("Now, you can open saved test using this button");
     SOut->Lines->Add("       |");
     SOut->Lines->Add("      \\/");
     OpenFolder->Enabled = true;
     //this->Enabled = true;
     CancelBtn->Enabled = true;
    }
    else
    {
       SOut->Lines->Add("<!> Wrong kurs name");
    }
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::FormActivate(TObject *Sender)
{
        ProgressBar1->Position = 0;
        SOut->Lines->Clear();
        SOut->Lines->Add("Activate form");
        OKBtn->Enabled = true;  CancelBtn->Enabled = true;
        OpenFolder->Enabled = false;
        KName->Text = "kurs_tmp";

}
//---------------------------------------------------------------------------

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

        SOut->Lines->Add("Create and converting images");

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
                                                        ImageEnIO1->Params->JPEG_Quality = 70;

                                                        ProgressBar1->Position ++;

                                                        kurs_name = KursName;
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
                                                        //VarHtml->SaveToFile( GetCurrentDir() + "\\" + kurs_name + "\\" + str );

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
        SOut->Lines->Add("Saving right.txt");
        Right->SaveToFile(  GetCurrentDir() + "\\" + kurs_name + "\\right.txt" );

        NumZ->Clear();
        NumZ->Add( kurs_name );
        NumZ->Add( kurs->selecttask->name );
        NumZ->Add( IntToStr( variant ) );
        NumZ->Add( IntToStr( Numb_Zad ) );
        SOut->Lines->Add("Saving Number.txt");
        NumZ->SaveToFile( GetCurrentDir() + "\\" + kurs_name + "\\Number.txt" );
        Log->Add(GetCurrentDir().c_str());
        SOut->Lines->Add("Converting to moodle");
        ConvertToMoodle(kurs_name.c_str());

        delete list;
        delete VarHtml;
        delete Right;
        delete NumZ;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------




void __fastcall TGenHtml::OpenFolderClick(TObject *Sender)
{
        ShellExecute(Handle, NULL, "explorer", (GetCurrentDir()+"\\"+KursName).c_str(), NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::FormClose(TObject *Sender, TCloseAction &Action)
{
        Log->Add("Gen. Form closing");        
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::V1Click(TObject *Sender)
{
        Edit1->Text = "1";        
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::V4Click(TObject *Sender)
{
        Edit1->Text = "4";        
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::V10Click(TObject *Sender)
{
        Edit1->Text="10";        
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::V30Click(TObject *Sender)
{
        Edit1->Text="30";        
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::VPlusClick(TObject *Sender)
{
        int Current = StrToInt(Edit1->Text);
        Current++;
        Edit1->Text  = StrToInt(Current);
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::VMinusClick(TObject *Sender)
{
        int Current = StrToInt(Edit1->Text);
        if (Current > 1)
                Current--;
        Edit1->Text  = StrToInt(Current);
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::Edit1KeyPress(TObject *Sender, char &Key)
{
      char *str = "0123456789";
      if (((int)Key==8) || ((int)Key==13))
        return;
      if (!( AnsiStrScan( str, Key)))
        Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TGenHtml::KNameKeyPress(TObject *Sender, char &Key)
{
      char *str = "/\\#*:?\"<>| ";
      if (((int)Key==8) || ((int)Key==13))
        return;
      if (( AnsiStrScan( str, Key)))
        Key = NULL;
}
//---------------------------------------------------------------------------


