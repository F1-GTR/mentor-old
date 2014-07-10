//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest16.h"
#include "MParab.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest16::quest16(FILE* f)
{
  char* buf = new char[256];

  randomize();
  keygen = random (1000) + 1;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);

  sscanf(strpar1,"%d %d",&amin,&amax);
  qtype = type;

  delete buf;
}

quest16::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest16::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  Parab->quest = this;

  Parab->Edit1->Text = IntToStr(amin);
  Parab->Edit2->Text = IntToStr(amax);
  Parab->Edit3->Text = IntToStr(keygen);
  Parab->Edit4->Text = IntToStr(nvar);

  Parab->ShowModal();

  return 0;
}

quest16::Print(TList* plist)
{
        int p, y, y0, i;

        char * buf = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        p = rgen( keygen, 1, amin, amax );
        p = abs ( p );

        if( !p )
                p ++;

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
                sprintf( buf, "String(Выписать каноническое уравнение параболы зная её фокус.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти директрису этой параболы.)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "p=%d", p );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Искомое уравнение: )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "y^2=2*%d*x", p );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Директриса параболы:)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "x=%d", -p );
        plist->Add( strdup(buf) );

/*  Graphics::TBitmap* bmv = new Graphics::TBitmap();

  y0 = funk( 100, p );

  bmv->Width = 280;
  bmv->Height = 2 * y0 + 20;

// Парабола.
  y = funk( 100, p );
  bmv->Canvas->MoveTo( p + 110, 0);

  for( i = 100; i >= 0; i -- )
  {
        y = funk( i, p );
        draw( p + 10, y0, i, y, bmv );
  }

  for( i = 0; i <= 100; i ++ )
  {
        y = -funk( i, p );
        draw( p + 10, y0, i, y, bmv );
  }

// Оси координат.
  bmv->Canvas->MoveTo( p + 10, 0 );
  bmv->Canvas->LineTo( p + 10, 2 * y0 );
  bmv->Canvas->MoveTo( 0, y0 );
  bmv->Canvas->LineTo( p + 110, y0 );

// Директриса параболы.
  bmv->Canvas->MoveTo( p, 0 );
  bmv->Canvas->LineTo( p, 2 * y0 );

// Пояснения.
  sprintf(buf,"Парабола ВАРИАНТА %i, решение задачи %i, ключ %i",nvar,nzad,keygen);
  bmv->Canvas->TextOutA( 0, 2 * y0, buf);

  bmv->Canvas->TextOutA( 110 + p, y0 - 6, "x" );
  bmv->Canvas->TextOutA( p + 12, 0, "y" );
//  bmv->Canvas->TextOutA( 12, 12, "Директриса" );

  bmv->SaveToFile("plane.bmp");
  delete bmv;*/

        keygen = 0;

        delete buf;

        return 0;
}
//---------------------------------------------------------------
/*
void draw(int x0, int y0, int x, int y, Graphics::TBitmap* map)
{
        map->Canvas->LineTo( x0 + x, y0 - y);
}
//---------------------------------------------------------------

double funk( int x, int p)
{
        double y, temp;

        temp = (double)(2 * p * x );

        y = sqrt( temp );

        return y;
}*/
//----------------------------------------------------------------

quest16::Print(TList* plist, class test &t)
{
        int p, y, y0, i;
        int n, Right_Numb;
        
        char * buf = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        Right_Numb = random( 5 ) + 1;
        
        srand( keygen );

        p = rgen( keygen, 1, amin, amax );
        p = abs ( p );

        if( !p )
                p ++;

        if( p < 5 )
                Right_Numb = p;

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Выписать каноническое уравнение параболы зная её фокус.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Найти директрису этой параболы.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "p=%d", p );
        plist->Add( strdup(buf) );

        for( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Искомое уравнение: )" );
                plist->Add( strdup(buf) );

                sprintf( buf, "y^2=2*%d*x", p - ( Right_Numb - 1 ) + n );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Директриса параболы:)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "x=%d", -p - ( Right_Numb - 1 ) + n );
                plist->Add( strdup(buf) );
        }

        /*sprintf(buf,"String(@Часть преподавателя )");
        plist->Add(strdup(buf));

        sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add(strdup(buf));

        sprintf(buf,"String( Правильный ответ - %c)", 'a' + Right_Numb - 1 );
        plist->Add(strdup(buf));*/

        t.pr_tst = 1;
        t.ch_ask = 5;
        t.right_ask = Right_Numb;
        t.msg = "Тест успешно сгенерирован.";

        keygen = 0;

        delete buf;

        return 0;
}
//-----------------------------------------------------------


