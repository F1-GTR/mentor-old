//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest4.h"
#include "matopr.h"
#include "qvarnt.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#include "test_class.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest4::quest4(FILE* f)
{
  char* buf = new char[256];

  randomize();
  keygen = random( 1000 ) + 1;

  reads( f, buf );
  strpar1 = strdup(buf);
  reads( f, buf );
  strpar2 = strdup(buf);

  sscanf( strpar1, "%d %d %d", &amin, &amax, &dim );

  switch( dim )
  {
        case 2:
        qtype = DETER22;
        break;

        case 3:
        qtype = DETER33;
        break;

        //case 4:
        default:
        qtype = DETER;
        break;

        /*default:
        ShowMessage("Для таких определителей программа не рассчитана!");*/

  }

  delete buf;
}

quest4::Save( FILE* f )
{
  fprintf( f, "head %i\n", type );
  fprintf( f, "%s\n", name );
  fprintf( f, "%i %i %i\n", itemnumber, subitemnumber, qtype );
  fprintf( f, "%s\n", strpar1 );
  fprintf( f, "%s\n", strpar2 );

  return 0;
}

quest4::Edit()
{
  sscanf( strpar2, "%i%i", &amin, &amax );

  keygen = 0;
  nvar = 1;

  Matdet->quest = this;

  /*switch(dim)
  {
        case 2:
                Matdet->Caption = "Вычислить определитель матрицы 2х2.";
        break;
        case 3:
                Matdet->Caption = "Вычислить определитель матрицы 3х3.";
        break;
        case 4:
                Matdet->Caption = "Вычислить определитель матрицы 4х4.";
        break;
        default:
        ShowMessage("Для таких определителей программа не рассчитана!");
  }*/

  Matdet->Caption.sprintf( "Вычислить определитель матрицы %dх%d.", dim, dim );

  Matdet->Edit1->Text = IntToStr(amin);
  Matdet->Edit2->Text = IntToStr(amax);
  Matdet->Edit3->Text = IntToStr(keygen);
  Matdet->Edit4->Text = IntToStr(nvar);
  Matdet->Edit5->Text = IntToStr(dim);

  Matdet->ShowModal();

  return 0;
}

quest4::Print( TList* plist )
{
  int ma[10][10];
  int det;
  int i, j;

  if( keygen == 0 )
  {
        keygen = random( 1000 ) + 1;
  }

  srand( keygen );

  for( i = 0; i < dim; i++)
  {
        for( j = 0; j < dim; j++)
        {
                ma[i][j] = rgen( keygen, 1, amin, amax );
        }
  }

  det = determ( dim, ma );

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
        sprintf( buf, "String( Найти определитель матрицы %dх%d )",dim,dim);
        plist->Add( strdup(buf) );
  }

  sprintf( buf, "|Matrix(%i,%i", dim, dim );

  for( i = 0; i < dim; i ++ )
  {
        for( j = 0; j < dim; j ++ )
        {
                sprintf( buf1, ",%i", ma[i][j] );
                strcat( buf, buf1 );
        }
  }

  strcat( buf, ")|=..." );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(@Часть преподавателя )" );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
  plist->Add( strdup(buf) );

  sprintf( buf, "|Matrix(%d,%d", dim, dim );

  for( i = 0; i < dim; i ++ )
  {
        for( j = 0; j < dim; j ++ )
        {
                sprintf( buf1, ",%i", ma[i][j] );
                strcat( buf, buf1 );
        }
  }

  strcat( buf, ")|=" );
  sprintf( buf1, "%d", det );
  strcat( buf, buf1 );

  plist->Add( strdup(buf) );

  keygen = 0;

  delete buf;
  delete buf1;

  return 0;
}
//------------------------------------------------------------------------------

/*int det33(int ma[4][4])
{
        int det;

        det = ma[0][0]*ma[1][1]*ma[2][2] + ma[0][1]*ma[1][2]*ma[2][0] + ma[1][0]*ma[2][1]*ma[0][2];
        det -= (ma[0][2]*ma[1][1]*ma[2][0] + ma[1][0]*ma[0][1]*ma[2][2] + ma[2][1]*ma[1][2]*ma[0][0]);

        return det;
}
//------------------------------------------------------------------------------*/

int determ( int dim, int ma[][10] )
{
        int i, j, k, l, det, mb[10][10];

        if( dim == 1 )
                return ma[0][0];

        if( dim > 1 )
        {
                det = 0;

                for( i = 0; i < dim; i ++ )
                {
                        l = 0;

                        for( j = 1; j < dim; j ++ )
                        {
                                for( k = 0; k < dim; k ++ )
                                {
                                        if ( k != i )
                                                mb[j - 1][ l ++ ] = ma[j][k];
                                        else
                                                continue;
                                }

                                l = 0;
                        }

                        det += pow( -1, i ) * ma[0][i] * determ( dim - 1, mb );
                }
                return det;
        }
}
//------------------------------------------------------------------------------

quest4::Print( TList* plist, class test &t )
{
        int ma[10][10];
        int det;
        int i, j;
        int mas[5], a = -4, b = 4;
        double p;
        int  n, Right_Numb;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for ( i = 0; i < 5; i ++ )
        {
                p = random( 8 ) / 8;

                if ( p >= 0.5 )
                        mas[i] = a;
                else
                        mas[i] = b;

                a ++;
                b --;

                if ( !a )
                        a ++;

                if ( !b )
                        b --;
        }

        Right_Numb = random( 5 ) + 1;

        for( i = 0; i < dim; i++ )
        {
                for( j = 0; j < dim; j++ )
                {
                        ma[i][j] = rgen( keygen, 1, amin, amax );
                }
        }

        det = determ( dim, ma );

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Найти определитель матрицы %dх%d )", dim, dim );
        plist->Add( strdup(buf) );

        sprintf( buf, "|Matrix(%i,%i", dim, dim );

        for( i = 0; i < dim; i ++ )
        {
                for( j = 0; j < dim; j ++ )
                {
                        sprintf( buf1, ",%i", ma[i][j] );
                        strcat( buf, buf1 );
                }
        }

        strcat( buf, ")|=..." );
        plist->Add( strdup(buf) );

        for ( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                if ( n != Right_Numb - 1 )
                        sprintf( buf, "%d", det + mas[n] );
                else
                        sprintf( buf, "%d", det );
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
        delete buf1;

        return 0;
}
//------------------------------------------------------------------------------


