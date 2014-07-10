//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include "quest7.h"
#include "drobi.h"
#include "odsistem.h"
#include "qvarnt.h"
#include "math.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest7::quest7(FILE* f)
{
  char* buf = new char[256];

  //randomize();
  keygen = 0;

  reads( f, buf );
  strpar1 = strdup( buf );
  reads( f, buf );
  strpar2 = strdup( buf );

  sscanf( strpar1, "%d %d %d", &amin, &amax, &rang );
  qtype = type;
}

quest7::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest7::Edit()
{
  sscanf( strpar2, "%i%i", &amin, &amax );

  keygen = 0;
  nvar = 1;

  NullSystem->quest = this;
  NullSystem->Edit1->Text = IntToStr(amin);
  NullSystem->Edit2->Text = IntToStr(amax);
  NullSystem->Edit3->Text = IntToStr(keygen);
  NullSystem->Edit4->Text = IntToStr(nvar);
  NullSystem->Edit5->Text = IntToStr(rang);

  NullSystem->ShowModal();

  return 0;
}
//------------------------------------------------------------------------------

int determ( int dim, int ma[][10])
{
        int i, j, k, l, det, mb[10][10];

        if ( dim == 1 )
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
                                                mb[j][ l ++ ] = ma[j][k];
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

quest7::Print(TList* plist)
{
  drobi matr[4][4], tc, x[4];
  int i, j, k, m, vect[4];

  char* buf = new char[256];
  char* buf1 = new char[256];

  if( keygen == 0 )
  {
  	keygen = random( 1000 ) + 1;
  }

  srand( keygen );

  for( i = 0; i < 3; i++ )
  {
        for( j = 0; j < 3; j++ )
        {
                matr[i][j] = drobi(0);
                vect[i] = 0;
        }
  }

  for( i = 0; i < 3; i++ )
  {
        if ( i < rang )
        for( j = 0; j < 3; j++ )
        {
                matr[i][j] = rgen(keygen, 1, amin,amax);
                //matr[i][j] = drobi( random(amax) + amin );
        }
        else
        {
                if ( rang == 2)
                {
                        if ( matr[0][0] * matr[1][1] - matr[0][1]*matr[1][0] == (drobi ) 0 )
                        {
                                //i = 0;
                                //keygen = keygen + 5;
                                //continue;
                                matr[1][1] = matr[1][1] + 1;
                        }

                        k = random( 2 );
                }
                else
                        k = 0;

                m = rgen( keygen, 1, amin, amax );

        for( j = 0; j < 3; j++ )
        {
                //ma[i][j]=rgen(keygen,30,amin,amax);
                int temp;
                temp = m * matr[k][j].a  * matr[k][j].znak;
                matr[i][j] = drobi( temp );
        }
        }

  }

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
        sprintf( buf, "String( Найти общее решение системы %dх%d.)", 3, 3 );
        plist->Add( strdup(buf) );
  }

  if ( matr[0][0].a != 1 )
        sprintf( buf, "System(%d*x_1", matr[0][0].a * matr[0][0].znak );
  else
  if ( matr[0][0].znak > 0 )
        sprintf( buf, "System(x_1" );
  else
        sprintf( buf, "System(-x_1" );

  for ( i = 1; i < 3; i ++ )
  {
        if ( matr[0][i].a != 1 )
                sprintf( buf1, "%+d*x_%d", matr[0][i].znak * matr[0][i].a, i + 1 );
        else
        if ( matr[0][i].znak > 0 )
                sprintf( buf1, "+x_%d", i + 1 );
        else
                sprintf( buf1, "-x_%d", i + 1 );

        strcat( buf, buf1 );
  }

  sprintf( buf1, "=%d", vect[0] );
  strcat( buf, buf1 );

  for( i = 1; i < 3; i ++ )
  {
    if ( matr[i][0].a != 1 )
        sprintf( buf1, ",%d*x_1", matr[i][0].znak * matr[i][0].a );
    else
    if ( matr[i][0].znak > 0 )
        sprintf( buf1, ",x_1" );
    else
        sprintf( buf1, ",-x_1" );
    strcat( buf, buf1 );

    for( j = 1; j < 3; j++ )
    {
        if ( matr[i][j].a != 1 )
                sprintf( buf1, "%+d*x_%d", matr[i][j].znak * matr[i][j].a, j + 1 );
        else
        if ( matr[i][j].znak > 0 )
                sprintf( buf1, "+x_%d", j + 1 );
        else
                sprintf( buf1, "-x_%d", j + 1 );

        strcat( buf, buf1 );
    }

    sprintf( buf1, "=%d", vect[i] );
    strcat( buf, buf1 );
  }

  strcat( buf, ")" );
  plist->Add( strdup(buf) );

/*  sprintf(buf,"String(___________________________________________)");
  plist->Add(strdup(buf));*/

  sprintf( buf, "String(@Часть преподавателя )" );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
  plist->Add( strdup(buf) );

  /*sprintf(buf,"!(Matrix(1,%d",3);

  for (i = 0; i < 3; i ++)
  {
        sprintf(buf1,",x_%d",i+1);
        strcat(buf,buf1);
  }

  strcat(buf,"))=");

  sprintf(buf1,"!(Matrix(1,%d",3);
  strcat(buf,buf1);*/

  if ( rang != 3 )
  {
  for ( i = 0; i < rang; i ++ )
  {
        for( j = i + 1; j < 3; j ++ )
        {
                tc = matr[j][i]/matr[i][i];

                for( k = i; k < 3; k ++ )
                {
                        matr[j][k] = matr[j][k] - matr[i][k] * tc;
                }
         }
  }

  switch ( rang )
  {
        case 1:
                x[1] = (drobi(-1) * matr[0][2]) / matr[0][0];
                x[0] = (drobi(-1) * matr[0][1]) / matr[0][0];

                sprintf( buf, "!(Matrix(1,3,x_1,x_2,x_3))=!(Matrix(1,3") ;

                sprintf( buf1,",%s*x_2", DrobiToStr( x[0] ));
                strcat( buf, buf1 );

                if ( x[1].znak >= 0 )
                        sprintf( buf1, "+%s*x_3,x_2,x_3))", DrobiToStr( x[1] ) );
                else
                        sprintf( buf1, "%s*x_3,x_2,x_3))", DrobiToStr( x[1] ) );

                strcat( buf, buf1 );
                plist->Add( strdup(buf) );

                x[1] = (drobi(-1) * matr[0][2]) / matr[0][1];
                x[0] = (drobi(-1) * matr[0][0]) / matr[0][1];

                sprintf( buf, "!(Matrix(1,3,x_1,x_2,x_3))=!(Matrix(1,3" );

                sprintf( buf1, ",x_1,%s*x_1", DrobiToStr( x[0] ));
                strcat( buf, buf1 );

                //sprintf( buf1,"%+d*%d/%d*x_3,x_3))",x[1].znak,x[1].a,x[1].b);
                if ( x[1].znak >= 0 )
                        sprintf( buf1, "+%s*x_3,x_3))", DrobiToStr( x[1] ) );
                else
                        sprintf( buf1, "%s*x_3,x_3))", DrobiToStr( x[1] ) );
                strcat( buf, buf1 );

                plist->Add( strdup(buf) );

                x[1] = (drobi(-1) * matr[0][1]) / matr[0][2];
                x[0] = (drobi(-1) * matr[0][0]) / matr[0][2];

                sprintf( buf, "!(Matrix(1,3,x_1,x_2,x_3))=!(Matrix(1,3" );

                //sprintf( buf1,",x_1,x_2,%d*%d/%d*x_1",x[0].znak,x[0].a,x[0].b);
                sprintf( buf1, ",x_1,x_2,%s*x_1", DrobiToStr( x[0] ));
                strcat( buf, buf1 );

                //sprintf( buf1,"%+d*%d/%d*x_2))",x[1].znak,x[1].a,x[1].b);
                if ( x[1].znak >= 0 )
                        sprintf( buf1, "+%s*x_2))", DrobiToStr( x[1] ) );
                else
                        sprintf( buf1, "%s*x_2))", DrobiToStr( x[1] ) );
                strcat( buf, buf1 );

        break;
        case 2:
                sprintf( buf, "!(Matrix(1,3,x_1,x_2,x_3))=!(Matrix(1,3" );

                x[1] = (drobi )-1 * matr[1][2]/matr[1][1];
                x[0] = (drobi )-1 * ( matr[0][2] + matr[0][1] * x[1]) / matr[0][0];

                if ( x[0].a != 0 )
                {
                        sprintf( buf1, ",%s*x_3", DrobiToStr( x[0] ) );
                        strcat( buf, buf1 );
                }
                else
                {
                        sprintf( buf1, ",0" );
                        strcat( buf, buf1 );
                }

                if ( x[1].a != 0 )
                {
                        sprintf( buf1, ",%s*x_3,x_3", DrobiToStr( x[1] ) );
                        strcat( buf, buf1 );
                }
                else
                {
                        sprintf( buf1, ",0,x_3", DrobiToStr( x[1] ) );
                        strcat( buf, buf1 );
                }

                strcat ( buf, "))" );
        break;
        case 3:
                sprintf( buf, "!(Matrix(1,3,0,0,0))");
        break;
  }
  }
  else
        sprintf( buf, "!(Matrix(1,3,0,0,0))" );

  plist->Add( strdup(buf) );

  sprintf( buf, "rang=%d", rang );
  plist->Add( strdup(buf) );

  keygen = 0;

  delete buf;
  delete buf1;

  return 0;
}
//------------------------------------------------------------

quest7::Print(TList* plist, class test &t)
{
  int matr[4][4], vect[4];
  int i, j, k, m;
  int n, Right_Numb;

  char* buf = new char[256];
  char* buf1 = new char[256];

  if( keygen == 0 )
  {
  	keygen = random( 1000 ) + 1;
  }

  srand( keygen );

  rang = random( 3 ) + 1;
  Right_Numb = random( 2 ) + 1;

  for( i = 0; i < 3; i++ )
  {
        for( j = 0; j < 3; j++ )
        {
                matr[i][j] = 0;
                vect[i] = 0;
        }
  }

  for( i = 0; i < 3; i++ )
  {
        if ( i < rang )
        for( j = 0; j < 3; j++ )
        {
                matr[i][j] = rgen( keygen, 1, amin, amax );
        }
        else
        {
                if ( rang == 2)
                {
                        if ( matr[0][0] * matr[1][1] - matr[0][1]*matr[1][0] == 0 )
                        {
                                matr[1][1] = matr[1][1] + 1;
                        }

                        k = random( 2 );
                }
                else
                        k = 0;

                m = rgen( keygen, 1, amin, amax );

        for( j = 0; j < 3; j++ )
        {
                matr[i][j] = m * matr[k][j];
        }
        }

  }

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
        sprintf( buf, "String(Найти общее решение системы %dх%d.)", 3, 3 );
        plist->Add( strdup(buf) );
  }

  if ( abs( matr[0][0] ) != 1 )
        sprintf( buf, "System(%d*x_1", matr[0][0] );
  else
  if ( matr[0][0] > 0 )
        sprintf( buf, "System(x_1" );
  else
        sprintf( buf, "System(-x_1" );

  for ( i = 1; i < 3; i ++ )
  {
        if ( abs( matr[0][i] ) != 1 )
                sprintf( buf1, "%+d*x_%d", matr[0][i], i + 1 );
        else
        if ( matr[0][i] > 0 )
                sprintf( buf1, "+x_%d", i + 1 );
        else
                sprintf( buf1, "-x_%d", i + 1 );

        strcat( buf, buf1 );
  }

  sprintf( buf1, "=%d", vect[0] );
  strcat( buf, buf1 );

  for( i = 1; i < 3; i ++ )
  {
    if ( abs( matr[i][0] ) != 1 )
        sprintf( buf1, ",%d*x_1", matr[i][0] );
    else
    if ( matr[i][0] > 0 )
        sprintf( buf1, ",x_1" );
    else
        sprintf( buf1, ",-x_1" );
    strcat( buf, buf1 );

    for( j = 1; j < 3; j++ )
    {
        if ( abs( matr[i][j] ) != 1 )
                sprintf( buf1, "%+d*x_%d", matr[i][j], j + 1 );
        else
        if ( matr[i][j] > 0 )
                sprintf( buf1, "+x_%d", j + 1 );
        else
                sprintf( buf1, "-x_%d", j + 1 );

        strcat( buf, buf1 );
    }

    sprintf( buf1, "=%d", vect[i] );
    strcat( buf, buf1 );
  }

  strcat( buf, ")" );
  plist->Add( strdup(buf) );

        for ( n = 0; n < 2; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                if ( n != Right_Numb - 1 )
                {
                        if( rang != 3 )
                                sprintf( buf, "!(Matrix(1,3,x_1,x_2,x_3))=!(Matrix(1,3,0,0,0))" );
                        else
                                sprintf(buf,"String(Решений бесконечно много.)");
                }
                else
                {
                        if( rang != 3 )
                                sprintf(buf,"String(Решений бесконечно много.)");
                        else
                                sprintf( buf, "!(Matrix(1,3,x_1,x_2,x_3))=!(Matrix(1,3,0,0,0))" );
                }

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
        t.ch_ask = 2;
        t.right_ask = Right_Numb;
        t.msg = "Тест успешно сгенерирован.";

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//-----------------------------------------------------------


