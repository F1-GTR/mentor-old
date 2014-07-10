//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest5.h"
#include "gauss.h"
#include "tkurs.h"
#include "qvarnt.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#include "drobi.h"
#include "determ.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest5::quest5(FILE* f,int type)
{
  char* buf = new char[256];

  randomize();
  keygen = random (1000) + 1;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);

  sscanf(strpar1,"%d %d %d",&amin,&amax,&dim);
  qtype = type;

  delete buf;
}

quest5::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest5::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  LinSistem->quest = this;

  if ( qtype == LEGAUSS)
        LinSistem->Caption = "Решение систем " + IntToStr(dim) + "x" + IntToStr(dim) + " методом Гаусса.";
  else
        LinSistem->Caption = "Решение систем " + IntToStr(dim) + "x" + IntToStr(dim) + " методом Крамера.";

  LinSistem->Edit1->Text = IntToStr(amin);
  LinSistem->Edit2->Text = IntToStr(amax);
  LinSistem->Edit3->Text = IntToStr(keygen);
  LinSistem->Edit4->Text = IntToStr(nvar);
  LinSistem->Edit5->Text = IntToStr(dim);

  LinSistem->ShowModal();

  return 0;
}

quest5::Print(TList* plist)
{
        int i, j, k;
        int ma[10][10], x[10], vect[10], mt[10][10];

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for( i = 0; i < dim; i ++ )
                x[i] = rgen( keygen, 1, amin, amax );

        for( i = 0; i < dim; i++ )
        {
                for( j = 0; j < dim; j++ )
                {
                        ma[i][j] = 0;
                }
        }

        while( !determ( dim, ma ) )
        for( i = 0; i < dim; i ++ )
        {
                for( j = 0; j < dim; j ++ )
                {
                        ma[i][j] = rgen( keygen, 1, amin, amax );
                }
        }

        for( i = 0; i < dim; i ++ )
        {
                /*for( j = 0; j < dim; j++)
                {
                        ma[i][j] = rgen( keygen, 1, amin, amax );
                }*/

                vect[i] = 0;

                for( j = 0; j < dim; j ++ )
                        vect[i] += x[j] * ma[i][j];
        }

  /*for( i = 0; i < dim; i++ )
  {
        for( j = 0; j < dim; j++ )
        {
                ma[i][j] = 0;
                vect[i] = 0;
        }
  }

  while( !determ( dim, ma ) )
  for( i = 0; i < dim; i ++ )
  {
        for( j = 0; j < dim; j ++ )
        {
                ma[i][j] = rgen( keygen, 1, amin, amax );
        }

        vect[i] = rgen( keygen, 1, amin, amax );
  }*/

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
                if ( qtype == LEGAUSS )
                        sprintf( buf, "String( Решить систему %dх%d методом Гаусса.)", dim, dim );
                else
                        sprintf( buf, "String( Решить систему %dх%d методом Крамера.)", dim, dim );
                plist->Add( strdup(buf) );
        }

        if ( abs( ma[0][0]) != 1 )
                sprintf( buf, "System(%d*x_1", ma[0][0] );
        else
        if ( ma[0][0] > 0 )
                sprintf( buf, "System(x_1" );
        else
                sprintf( buf, "System(-x_1" );

        for ( i = 1; i < dim; i ++ )
        {
                if ( abs( ma[0][i] ) != 1 )
                        sprintf( buf1, "%+d*x_%d", ma[0][i], i + 1 );
                else
                if ( ma[0][i] > 0 )
                        sprintf( buf1, "+x_%d", i + 1 );
                else
                        sprintf( buf1, "-x_%d", i + 1 );

                strcat( buf, buf1 );
        }

        sprintf( buf1, "=%d", vect[0] );
        strcat( buf, buf1 );

        for( i = 1; i < dim; i++ )
        {
                if ( abs( ma[i][0] ) != 1 )
                        sprintf( buf1, ",%d*x_1", ma[i][0] );
                else
                if ( ma[i][0] > 0 )
                        sprintf( buf1, ",x_1" );
                else
                        sprintf( buf1, ",-x_1" );
                strcat( buf, buf1 );

                for( j = 1; j < dim; j++ )
                {
                        if ( abs( ma[i][j] ) != 1 )
                                sprintf( buf1, "%+d*x_%d", ma[i][j], j + 1 );
                        else
                        if ( ma[i][j] > 0 )
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

        if ( qtype == LEKRAMER )
        {
                sprintf( buf, "Delta=%d", determ( dim, ma ) );
                plist->Add( strdup(buf) );

                for ( i = 0; i < dim; i ++ )
                {
                        for( j = 0; j < dim; j ++ )
                        for( k = 0; k < dim; k ++)
                        {
                                if( k != i )
                                        mt[j][k] = ma[j][k];
                                else
                                        mt[j][k] = vect[j];
                        }

                        sprintf( buf, "Delta_%d=%d", i + 1, determ( dim, mt ) );
                        plist->Add( strdup(buf) );
                }
        }

        sprintf( buf, "!(Matrix(1,%d", dim );

        for ( i = 0; i < dim; i ++ )
        {
                sprintf( buf1, ",x_%d", i + 1 );
                strcat( buf, buf1 );
        }

        strcat( buf, "))=" );

        sprintf( buf1, "!(Matrix(1,%d", dim );
        strcat( buf, buf1 );

        for( j = 0; j < dim; j ++ )
        {
                sprintf( buf1, ",%d", x[j] );
                strcat( buf, buf1 );
        }

        strcat( buf, "))" );
        plist->Add( strdup(buf) );

  /*sprintf( buf1, "!(Matrix(1,%d", dim );
  strcat( buf, buf1 );

  for (i = 0; i < dim; i ++ )
  {
        for(j = 0; j < dim; j ++ )
                for( k = 0; k < dim; k ++ )
                {
                        if (k == i)
                        {
                                mb[j][k] = vect[j];
                        }
                        else
                        {
                                mb[j][k] = ma[j][k];
                        }
                }

        drob = &drobi( determ( dim, mb ), determ( dim, ma ) );

        drob->sokrat();

        tc = ceil( drob->c );

        if ( tc == drob->c)
                sprintf( buf1, ",%f", drob->c );
        else
        {
                if ( drob->znak < 0)
                        sprintf( buf1, ",-(%d/%d)", drob->a, drob->b );
                else
                        sprintf( buf1, ",%d/%d", drob->a, drob->b );
        }
        strcat( buf, buf1 );
  }

  strcat( buf, "))" );
  plist->Add( strdup(buf) );*/

  if( qtype == LEGAUSS )
  {
        /*sprintf(buf,"String(Исходная матрица:)");
        plist->Add(strdup(buf));

        for ( i = 0; i < dim; i ++ )
                ma[i][dim] = vect[i];

        sprintf(buf,"!(Matrix(%d,%d",dim + 1,dim);
        for ( i = 0; i < dim; i ++ )
        for ( j = 0; j <= dim; j++ )
        {
                TmpMtr[i][j] = ma[i][j];
                sprintf(buf1,",%d",ma[i][j]);
                strcat(buf,buf1);
        }

  sprintf(buf1,"))");
  strcat(buf,buf1);
  plist->Add(strdup(buf));

        for ( i = 0; i < dim; i ++ )
        for ( j = i + 1; j < dim; j++ )
        {

                tmp1 = TmpMtr[i][i];
                tmp2 = TmpMtr[j][i];

                for ( k = i; k <= dim; k ++)
                        TmpMtr[j][k] = TmpMtr[j][k]*tmp1 - TmpMtr[i][k]*tmp2;
        }

  sprintf(buf,"String(Преобразованная матрица:)",nvar,nzad,keygen);
  plist->Add(strdup(buf));

  sprintf(buf,"!(Matrix(%d,%d",dim + 1,dim);
  for ( i = 0; i < dim; i ++ )
        for ( j = 0; j <= dim; j++ )
        {
                sprintf(buf1,",%d",TmpMtr[i][j]);
                strcat(buf,buf1);
        }
  sprintf(buf1,"))");
  strcat(buf,buf1);
  plist->Add(strdup(buf));*/

  }

/*  sprintf(buf,"String(___________________________________________)");
  plist->Add(strdup(buf));*/

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//--------------------------------------------------------

quest5::Print(TList* plist, class test &t)
{
        int i, j, k, ma[10][10], vect[10], x[10];
        int n, Right_Numb;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        Right_Numb = random( 5 ) + 1;

        for( i = 0; i < dim; i ++ )
                x[i] = rgen( keygen, 1, amin, amax );

        for( i = 0; i < dim; i++ )
        {
                for( j = 0; j < dim; j++ )
                {
                        ma[i][j] = 0;
                }
        }

        while( !determ( dim, ma ) )
        for( i = 0; i < dim; i ++ )
        {
                for( j = 0; j < dim; j ++ )
                {
                        ma[i][j] = rgen( keygen, 1, amin, amax );
                }
        }

        for( i = 0; i < dim; i ++ )
        {
                vect[i] = 0;
                
                for( j = 0; j < dim; j ++ )
                        vect[i] += x[j] * ma[i][j];
        }

        /*for( i = 0; i < dim; i++)
        {
                for( j = 0; j < dim; j++)
                {
                        ma[i][j] = rgen( keygen, 1, amin, amax );
                }

                vect[i] = 0;

                for( j = 0; j < dim; j ++ )
                        vect[i] += x[j] * ma[i][j];
        }*/

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        if ( qtype == LEGAUSS )
                sprintf( buf, "String( Решить систему %dх%d методом Гаусса.)", dim, dim );
        else
                sprintf( buf, "String( Решить систему %dх%d по формулам Крамера.)", dim, dim );
        plist->Add( strdup(buf) );

        if ( abs( ma[0][0]) != 1 )
                sprintf( buf, "System(%d*x_1", ma[0][0] );
        else
        if ( ma[0][0] > 0 )
                sprintf( buf, "System(x_1" );
        else
                sprintf( buf, "System(-x_1" );

        for ( i = 1; i < dim; i ++ )
        {
                if ( abs( ma[0][i] ) != 1 )
                        sprintf( buf1, "%+d*x_%d", ma[0][i], i + 1 );
                else
                if ( ma[0][i] > 0 )
                        sprintf( buf1, "+x_%d", i + 1 );
                else
                        sprintf( buf1, "-x_%d", i + 1 );

                strcat( buf, buf1 );
        }

        sprintf( buf1, "=%d", vect[0] );
        strcat( buf, buf1 );

        for( i = 1; i < dim; i++ )
        {
                if ( abs( ma[i][0] ) != 1 )
                        sprintf( buf1, ",%d*x_1", ma[i][0] );
                else
                if ( ma[i][0] > 0 )
                        sprintf( buf1, ",x_1" );
                else
                        sprintf( buf1, ",-x_1" );
                strcat( buf, buf1 );

                for( j = 1; j < dim; j++ )
                {
                        if ( abs( ma[i][j] ) != 1 )
                                sprintf( buf1, "%+d*x_%d", ma[i][j], j + 1 );
                        else
                        if ( ma[i][j] > 0 )
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

        sprintf( buf, "String(\"Варианты решения:\")" );
        plist->Add( strdup(buf) );

        for ( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                if ( n != Right_Numb - 1 )
                {
                        sprintf( buf, "!(Matrix(1,%d", dim );

                        for ( i = 0; i < dim; i ++)
                        {
                                sprintf( buf1, ",x_%d", i + 1 );
                                strcat( buf, buf1 );
                        }

                        strcat( buf, "))=" );

                        sprintf( buf1, "!(Matrix(1,%d", dim );
                        strcat( buf, buf1 );

                        for( j = 0; j < dim; j ++ )
                        {
                                sprintf( buf1, ",%d", ( x[j] + random( 10 ) - 5 ) );
                                strcat( buf, buf1 );
                        }

                        strcat( buf, "))" );
                        plist->Add( strdup(buf) );
                }
                else
                {
                        sprintf( buf, "!(Matrix(1,%d", dim );

                        for ( i = 0; i < dim; i ++ )
                        {
                                sprintf( buf1, ",x_%d", i + 1 );
                                strcat( buf, buf1 );
                        }

                        strcat( buf, "))=" );

                        sprintf( buf1, "!(Matrix(1,%d", dim );
                        strcat( buf, buf1 );

                        for( j = 0; j < dim; j ++ )
                        {
                                sprintf( buf1, ",%d", x[j] );
                                strcat( buf, buf1 );
                        }

                        strcat( buf, "))" );
                        plist->Add( strdup(buf) );
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
//-----------------------------------------------------------


