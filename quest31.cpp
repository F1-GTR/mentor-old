//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest31.h"
#include "integral2.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest31::quest31(FILE* f)
{
  char * buf = new char[256];

  randomize();
  keygen = random( 1000 ) + 1;

  reads( f, buf );
  strpar1 = strdup( buf );
  reads( f, buf );
  strpar2 = strdup( buf );

  sscanf( strpar1, "%d %d %d", &a, &b, &n );

  qtype = NEW_INT;
}

quest31::Save(FILE* f)
{
  fprintf( f, "head %i\n", type );
  fprintf( f, "%s\n", name );
  fprintf( f, "%i %i %i\n", itemnumber, subitemnumber, qtype );
  fprintf( f, "%s\n", strpar1 );
  fprintf( f, "%s\n", strpar2 );

  return 0;
}

quest31::Edit()
{
        TForm  * fm = new TForm( Application );

        TButton * Button1 = new TButton( Application );
        TButton * Button2 = new TButton( Application );
        TButton * Button3 = new TButton( Application );
        TButton * Button4 = new TButton( Application );

        TMemo * Memo1 = new TMemo( Application );

        TEdit * Edit1 = new TEdit( Application );
        TEdit * Edit2 = new TEdit( Application );
        TEdit * Edit3 = new TEdit( Application );
        TEdit * Edit4 = new TEdit( Application );
        TEdit * Edit5 = new TEdit( Application );
        TEdit * Edit6 = new TEdit( Application );

        TLabel * Label1 = new TLabel( Application );
        TLabel * Label2 = new TLabel( Application );
        TLabel * Label3 = new TLabel( Application );
        TLabel * Label4 = new TLabel( Application );
        TLabel * Label5 = new TLabel( Application );
        TLabel * Label6 = new TLabel( Application );

        TRadioGroup * RadioGroup1 = new TRadioGroup( Application );

        TRadioButton * RadioButton1 = new TRadioButton( Application );
        TRadioButton * RadioButton2 = new TRadioButton( Application );

        sscanf( strpar2, "%i%i", &a, &b );

        nvar = 1;
        keygen = 0;

        fm->Position = poScreenCenter;
        fm->Caption = "Нахождение неопределённых интегралов";
        fm->Width = 640;
        fm->Height = 480;
        fm->BorderStyle = bsDialog;

        Button1->Visible = true;
        Button1->Caption = "Генерация";
        Button1->Left = 16;
        Button1->Top = 412;
        Button1->Parent = fm;

        Button2->Visible = true;
        Button2->Caption = "Просмотр результатов";
        Button2->Left = 184;
        Button2->Top = 412;
        Button2->Width = 130;
        Button2->Parent = fm;

        RadioGroup1->Visible = true;
        RadioGroup1->Caption = "Режим генерации ключа";
        RadioGroup1->Left = 0;
        RadioGroup1->Top = 300;
        RadioGroup1->Width = 209;
        RadioGroup1->Height = 57;
        RadioGroup1->Parent = fm;

        RadioButton1->Visible = true;
        RadioButton1->Caption = "Автоматическая генерация ключа";
        RadioButton1->Left = 8;
        RadioButton1->Top = 315;
        RadioButton1->Width = 195;
        RadioButton1->Parent = fm;
        RadioButton1->Checked = true;

        RadioButton2->Visible = true;
        RadioButton2->Caption = "Ручная генерация ключа";
        RadioButton2->Left = 8;
        RadioButton2->Top = 330;
        RadioButton2->Width = 195;
        RadioButton2->Parent = fm;
        RadioButton2->Checked = false;

        Label1->Visible = true;
        Label1->Caption = "Коэффициент А:";
        Label1->Left = 0;
        Label1->Top = 16;
        Label1->Parent = fm;

        Label2->Visible = true;
        Label2->Caption = "Коэффициент В:";
        Label2->Left = 0;
        Label2->Top = 64;
        Label2->Parent = fm;

        Label3->Visible = true;
        Label3->Caption = "Степень n:";
        Label3->Left = 0;
        Label3->Top = 112;
        Label3->Parent = fm;

        Label4->Visible = true;
        Label4->Caption = "Тип интеграла:";
        Label4->Left = 0;
        Label4->Top = 160;
        Label4->Parent = fm;

        Label5->Visible = true;
        Label5->Caption = "Ключ";
        Label5->Left = 40;
        Label5->Top = 364;
        Label5->Parent = fm;

        Label6->Visible = true;
        Label6->Caption = "Вариант";
        Label6->Left = 136;
        Label6->Top = 364;
        Label6->Parent = fm;

        Memo1->Visible = true;
        Memo1->ScrollBars = ssBoth;
        Memo1->Left = 128;
        Memo1->Top = 8;
        Memo1->Width = 500;
        Memo1->Height = 285;
        Memo1->Parent = fm;

        Edit1->Visible = true;
        Edit1->Text = IntToStr( a );
        Edit1->Left = 0;
        Edit1->Top = 32;
        Edit1->Width = 121;
        Edit1->Parent = fm;

        Edit2->Visible = true;
        Edit2->Text = IntToStr( b );
        Edit2->Left = 0;
        Edit2->Top = 80;
        Edit2->Width = 121;
        Edit2->Parent = fm;

        Edit3->Visible = true;
        Edit3->Text = IntToStr( n );
        Edit3->Left = 0;
        Edit3->Top = 128;
        Edit3->Width = 121;
        Edit3->Parent = fm;

        Edit4->Visible = true;
        Edit4->Text = IntToStr( number );
        Edit4->Left = 0;
        Edit4->Top = 176;
        Edit4->Width = 121;
        Edit4->Parent = fm;

        Edit5->Visible = true;
        Edit5->Text = IntToStr( keygen );
        Edit5->Left = 0;
        Edit5->Top = 380;
        Edit5->Width = 121;
        Edit5->Parent = fm;

        Edit6->Visible = true;
        Edit6->Text = IntToStr( nvar );
        Edit6->Left = 125;
        Edit6->Top = 380;
        Edit6->Width = 121;
        Edit6->Parent = fm;

        fm->ShowModal();

        delete Button1;
        delete Button2;
        delete Button3;
        delete Button4;

        delete Memo1;

        delete Edit1;
        delete Edit2;
        delete Edit3;
        delete Edit4;
        delete Edit5;
        delete Edit6;

        delete Label1;
        delete Label2;
        delete Label3;
        delete Label4;
        delete Label5;
        delete Label6;

        delete RadioButton1;
        delete RadioButton2;
        
        delete RadioGroup1;

        delete fm;

  /*NeoInt->quest = this;
  NeoInt->Caption = "Нахождение неопределённых интегралов.";
  NeoInt->Edit1->Text = IntToStr(a);
  NeoInt->Edit2->Text = IntToStr(b);
  NeoInt->Edit3->Text = IntToStr(keygen);
  NeoInt->Edit4->Text = IntToStr(nvar);
  NeoInt->Edit5->Text = IntToStr(n);
  NeoInt->Edit6->Text = IntToStr(number);

  NeoInt->ShowModal();*/

  return 0;
}

quest31::Print(TList* plist)
{
        int a1, b1, n1;
        double t, t1;

        char * buf = new char[256];

        if( keygen == 0 )
        {
                keygen = random(1000) + 1;
        }

        srand( keygen );

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );
        }
        else
        {
                sprintf( buf, "String(#)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(Найти неопределённый интеграл.)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        keygen = 0;

        delete buf;

        return 0;
}
//------------------------------------------------------------------------------

quest31::Print(TList* plist, class test &t)
{
}
//-----------------------------------------------------------


