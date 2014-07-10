//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include "quest3.h"
#include "drobi.h"
#include "mateigv.h"
#include "qvarnt.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#include "test_class.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest3::quest3(FILE* f)
{
  char* buf = new char[256];

  //randomize();
  keygen = 0;

  reads( f, buf );
  strpar1 = strdup( buf );
  reads( f, buf );
  strpar2 = strdup( buf );
  qtype = MATEIGEN;

  delete buf;
}

quest3::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest3::Edit()
{
  sscanf( strpar1, "%i%i%i", &kstrok, &amin, &amax );
  sscanf( strpar2, "%i%i", &knull, &keygen );

  keygen = 0;
  nvar = 1;

  pmateigv->quest = (quest3*)this;
  pmateigv->Edit1->Text = IntToStr(kstrok);
  pmateigv->Edit4->Text = IntToStr(knull);
  pmateigv->Edit2->Text = IntToStr(amin);
  pmateigv->Edit3->Text = IntToStr(amax);
  pmateigv->Edit5->Text = IntToStr(keygen);
  pmateigv->Edit6->Text = IntToStr(nvar);
  pmateigv->ShowModal();

  return 0;
}

quest3::Print(TList* plist)
{
  int ma[5][5];
  int b1 = 0, b2 = 0;
  int i, j;

  drobi matr[5][5];

  sscanf( strpar1, "%i%i%i", &kstrok, &amin, &amax );
  sscanf( strpar2, "%i", &knull );

  if( keygen == 0 )
  {
        keygen = random( 1000 ) + 1;
  }

  srand( keygen );

  if( kstrok != 2 )
  {
    FError("Примеры с размерностью > 2 не генерируются",0);
    kstrok = 2;
  }

  kstolb = kstrok;

  while ( !b1 )
        b1 = amin + random( amax - amin + 1);

  while ( !b2 )
        b2 = amin + random( amax - amin + 1);

  ma[0][0] = rgen( keygen, 0, amin, amax );
  ma[0][1] = rgen( keygen, 0, amin, amax );
  while( !ma[0][1] )
        ma[0][1] = rgen( keygen, 0, amin, amax );
  ma[1][1] = b1 + b2 - ma[0][0];

  matr[0][0] = ma[0][0];
  matr[0][1] = ma[0][1];
  matr[1][0] = drobi ( ma[0][0] * ma[1][1] - b1 * b2, ma[0][1] );
  matr[1][1] = ma[1][1];

 /* while( 1 )
  {
    ki ++;

    if( ki > 100000 )
    {
      FError("мал диапазон собственных значений ",0);

      ml[0] = 3;
      ml[1] = 5;

      break;
    }

    a1 = amin + random( amax - amin + 1);

    if( a1 - ( a1 / 2 ) * 2 == 0 )
        continue;

    if( k == 0 && a1 + 2 <= amax )
    {
        ml[k] = a1;
        k++;

        continue;
    }

    if( k > 0 )
    {
        if( a1 - ( a1 / 2 ) * 2 == 0 )
                continue;
        if( a1 <= ml[0] )
                continue;
        ml[k] = a1;
        break;
    }
  }

  ma[0][0] = ( ml[0] + ml[1] ) / 2;
  ma[0][1] = ( ml[0] - ml[1] ) / 2;
  ma[1][0] = ( ml[0] - ml[1] ) / 2;
  ma[1][1] = ( ml[0] + ml[1] ) / 2;
                                   */
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
  {
        plist->Add( strdup("String( Найти собственные значения и векторы матрицы. )") );
  }

  sprintf( buf, "!(Matrix(%i,%i", kstolb, kstrok );

  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstolb; j ++ )
        {
                sprintf( buf1, ",%s", DrobiToStr( matr[i][j] ) );
                strcat( buf, buf1 );
        }
  }

  strcat( buf, "))" );
  plist->Add( strdup(buf) );

/*  sprintf(buf,"String(___________________________________________)");
  plist->Add(strdup(buf));*/

  sprintf( buf, "String(@Часть преподавателя )" );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
  plist->Add( strdup(buf) );

  sprintf( buf, "String( Собственные числа матрицы:)" );
  plist->Add( strdup(buf) );

  sprintf( buf, "lambda_1=%d", b1 );
  plist->Add( strdup(buf) );

  sprintf( buf, "lambda_2=%d", b2 );
  plist->Add( strdup(buf) );

  keygen = 0;

  return 0;
}
//---------------------------------------------------------------------------

quest3::Print(TList* plist, class test &t)
{
        int ma[5][5];
        int b1 = 0, b2 = 0;
        int i, j;
        int n, Right_Numb;

        drobi matr[5][5];

        sscanf( strpar1, "%i%i%i", &kstrok, &amin, &amax );
        sscanf( strpar2, "%i", &knull );

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        Right_Numb = random( 5 ) + 1;

        if( kstrok != 2 )
        {
                FError("Примеры с размерностью > 2 не генерируются",0);
                kstrok = 2;
        }

        kstolb = kstrok;

        while ( !b1 )
                b1 = amin + random( amax - amin + 1);

        while ( !b2 )
                b2 = amin + random( amax - amin + 1);

        ma[0][0] = amin + random( amax - amin + 1);
        ma[0][1] = rgen( keygen, 0, amin, amax );
        while( !ma[0][1] )
                ma[0][1] = rgen( keygen, 0, amin, amax );
        ma[1][1] = b1 + b2 - ma[0][0];

        matr[0][0] = ma[0][0];
        matr[0][1] = ma[0][1];
        matr[1][0] = drobi ( ma[0][0] * ma[1][1] - b1 * b2, ma[0][1] );
        matr[1][1] = ma[1][1];

        char* buf = new char[128];
        char* buf1 = new char[128];

        sprintf(buf,"String(\"# Тема - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add(strdup(buf));

        plist->Add( strdup( "String( Найти собственные значения и векторы матрицы. )" ) );

        sprintf(buf,"!(Matrix(%i,%i",kstolb,kstrok);

        for( i = 0; i < kstrok; i ++ )
        {
                for( j = 0; j < kstolb; j ++ )
                {
                        sprintf(buf1,",%s", DrobiToStr( matr[i][j] ) );
                        strcat(buf,buf1);
                }
        }

        strcat(buf,"))");
        plist->Add(strdup(buf));

        sprintf(buf,"String( Собственные числа матрицы:)");
        plist->Add(strdup(buf));

        for ( n = 0; n < 5; n ++ )
        {
                sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
                plist->Add(strdup(buf));

                if ( n != Right_Numb - 1 )
                {
                        sprintf(buf,"lambda_1=%d", b1 + ( random( 10 ) -  5 ) );
                        plist->Add(strdup(buf));

                        sprintf(buf,"lambda_2=%d", b2 + ( random( 10 ) -  5 ) );
                        plist->Add(strdup(buf));
                }
                else
                {
                        sprintf(buf,"lambda_1=%d", b1);
                        plist->Add(strdup(buf));

                        sprintf(buf,"lambda_2=%d", b2);
                        plist->Add(strdup(buf));
                }

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
//------------------------------------------------------------------------------


