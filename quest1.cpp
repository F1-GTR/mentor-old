//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include "quest1.h"
#include "matlin.h"
#include "qvarnt.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest1::quest1(FILE* f)
{
  char* buf = new char[256];

  keygen = 0;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);
  qtype = MATLINOP;

  delete buf;
}

quest1::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest1::Edit()
{
  sscanf( strpar1, "%i%i%i", &kstrok, &kstolb, &amin );
  sscanf( strpar2, "%i%i", &amax, &keygen );

  keygen = 0;
  nvar = 1;

  pmatlin->quest = this;
  pmatlin->Edit1->Text = IntToStr(kstrok);
  pmatlin->Edit2->Text = IntToStr(kstolb);
  pmatlin->Edit3->Text = IntToStr(amin);
  pmatlin->Edit4->Text = IntToStr(amax);
  pmatlin->Edit5->Text = IntToStr(keygen);
  pmatlin->Edit6->Text = IntToStr(nvar);
  pmatlin->ShowModal();

  return 0;
}

quest1::Print(TList* plist)
{
  int ma[15][15];
  int mb[15][15];
  int mc[15][15];
  int a, b;
  int i, j;

  if( keygen == 0 )
  {
        keygen = random( 1000 ) + 1;
  }

  srand( keygen );

  sscanf( strpar1, "%i%i%i", &kstrok, &kstolb, &amin );
  sscanf( strpar2, "%i", &amax);

  a = rgen( keygen, 1, amin, amax );
  b = rgen( keygen, 1, amin, amax );

  while( !a )
        a = rgen( keygen, 1, amin, amax );

  while( !b )
        b = rgen( keygen, 1, amin, amax );

  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstolb; j ++ )
        {
                ma[i][j] = rgen( keygen, 1, amin, amax );
                mb[i][j] = rgen( keygen, 1, amin, amax );
        }
  }

  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstolb; j ++ )
        {
                mc[i][j] = a * ma[i][j] + b * mb[i][j];
        }
  }

  char* buf = new char[256];
  char* buf1 = new char[256];

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
        plist->Add( strdup("String( Найти сумму матриц.)") );

  if( abs( a ) != 1 )
        sprintf( buf, "%i*.!(Matrix(%i,%i", a , kstolb, kstrok );
  else
  if( a > 0 )
        sprintf( buf, "!(Matrix(%i,%i", kstolb, kstrok );
  else
        sprintf( buf, "-!(Matrix(%i,%i", kstolb, kstrok );


  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstolb; j ++ )
        {
                sprintf( buf1, ",%i", ma[i][j] );
                strcat( buf, buf1 );
        }
  }

  strcat( buf, "))" );

  if( abs( b ) != 1 )
        sprintf( buf1, "%+i*.!(Matrix(%i,%i", b, kstolb, kstrok );
  else
  if( b > 0 )
        sprintf( buf1, "+!(Matrix(%i,%i", kstolb, kstrok );
  else
        sprintf( buf1, "-!(Matrix(%i,%i", kstolb, kstrok );

  strcat( buf, buf1 );

  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstolb; j ++ )
        {
                sprintf( buf1, ",%i", mb[i][j] );
                strcat( buf, buf1 );
        }
  }

  strcat( buf, "))=..." );
  plist->Add( strdup(buf) );

/*  sprintf(buf,"String(___________________________________________)");
  plist->Add(strdup(buf));*/

  sprintf( buf, "String(@Часть преподавателя )" );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
  plist->Add( strdup(buf) );

  sprintf( buf, "!(Matrix(%i,%i", kstolb, kstrok );

  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstolb; j ++ )
        {
                sprintf( buf1, ",%i", mc[i][j] );
                strcat( buf, buf1 );
        }
  }
  strcat( buf, "))" );
  plist->Add( strdup(buf) );

  keygen = 0;

  delete buf;
  delete buf1;

  return 0;
}
//--------------------------------------------------------

quest1::Print(TList* plist, class test &t)
{
        int ma[15][15];
        int mb[15][15];
        int mc[15][15];
        int Right_Numb;
        int a, b;
        int i, j, n;

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        Right_Numb = random( 5 ) + 1;

        sscanf( strpar1, "%i%i%i", &kstrok, &kstolb, &amin );
        sscanf( strpar2, "%i", &amax);

        a = rgen( keygen, 1, amin, amax );
        b = rgen( keygen, 1, amin, amax );

        while( !a )
                a = rgen( keygen, 1, amin, amax );

        while( !b )
                b = rgen( keygen, 1, amin, amax );

        for( i = 0; i < kstrok; i ++ )
        {
                for( j = 0; j < kstolb; j ++ )
                {
                        ma[i][j] = rgen( keygen, 1, amin, amax );
                        mb[i][j] = rgen( keygen, 1, amin, amax );
                }
        }

        for( i = 0; i < kstrok; i ++ )
        {
                for( j = 0; j < kstolb; j ++ )
                {
                        mc[i][j] = a * ma[i][j] + b * mb[i][j];
                }
        }

        char* buf = new char[256];
        char* buf1 = new char[256];

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        plist->Add( strdup("String( Найти сумму матриц.)") );

        if( abs( a ) != 1 )
                sprintf( buf, "%i*.!(Matrix(%i,%i", a , kstolb, kstrok );
        else
        if( a > 0 )
                sprintf( buf, "!(Matrix(%i,%i", kstolb, kstrok );
        else
                sprintf( buf, "-!(Matrix(%i,%i", kstolb, kstrok );

        for( i = 0; i < kstrok; i ++ )
        {
                for( j = 0; j < kstolb; j ++ )
                {
                        sprintf( buf1, ",%i", ma[i][j] );
                        strcat( buf, buf1 );
                }
        }

        strcat( buf, "))" );

        if( abs( b ) != 1 )
                sprintf( buf1, "%+i*.!(Matrix(%i,%i", b, kstolb, kstrok );
        else
        if( b > 0 )
                sprintf( buf1, "+!(Matrix(%i,%i", kstolb, kstrok );
        else
                sprintf( buf1, "-!(Matrix(%i,%i", kstolb, kstrok );

        strcat( buf, buf1 );

        for( i = 0; i < kstrok; i ++ )
        {
                for( j = 0; j < kstolb; j ++ )
                {
                        sprintf( buf1, ",%i", mb[i][j] );
                        strcat( buf, buf1 );
                }
        }

        strcat( buf, "))=..." );
        plist->Add( strdup(buf) );

        for ( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                sprintf( buf, "!(Matrix(%i,%i", kstolb, kstrok );
                for( i = 0; i < kstrok; i ++ )
                {
                        for( j = 0; j < kstolb; j ++ )
                        {
                                if ( n != Right_Numb - 1 )
                                        sprintf( buf1, ",%i", mc[i][j] + ( random ( 20 ) - 10 ) );
                                else
                                        sprintf( buf1, ",%i", mc[i][j] );
                                strcat( buf, buf1 );
                        }
                }

                strcat( buf, "))" );
                plist->Add( strdup(buf) );

        }

        /*sprintf(buf,"String(@Часть преподавателя )");
        plist->Add(strdup(buf));

        sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
        plist->Add(strdup(buf));

        sprintf(buf,"String( Правильный ответ - %c)", 'a' + Right_Numb - 1 );
        plist->Add(strdup(buf));*/

        t.pr_tst = 1;
        t.ch_ask = 5;
        t.right_ask = Right_Numb;
        t.msg = "Тест успешно сгенерирован.";
        
        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//-----------------------------------------------------------


