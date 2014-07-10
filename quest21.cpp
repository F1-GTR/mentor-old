//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include "quest21.h"
#include "MRang.h"
#include "qvarnt.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#include "det.cpp"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest21::quest21(FILE* f)
{
  char* buf = new char[256];

  randomize();
  keygen = random (1000) + 1;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);

  sscanf(strpar1,"%d %d %d",&amin,&amax,&rang);
  sscanf(strpar2,"%d %d %d",&amin,&amax,&dim);

  qtype = type;
  nvar = 1;

  delete buf;
}

quest21::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest21::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  Rang->quest = this;
  Rang->Edit1->Text = IntToStr(amin);
  Rang->Edit2->Text = IntToStr(amax);
  Rang->Edit3->Text = IntToStr(keygen);
  Rang->Edit4->Text = IntToStr(nvar);
  Rang->Edit5->Text = IntToStr(rang);
  Rang->Edit6->Text = IntToStr(dim);

  Rang->ShowModal();

  return 0;
}

quest21::Print(TList* plist)
{
        int i, j, k, r;
        int ma[10][10], mas[10];
        int tmp1, tmp2, TmpMtr[10][10];

        char * buf = new char[256];
        char * buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        if ( rang > dim )
        {
                ShowMessage("Ранг должен быть меньше размера матрицы!");
                return 0;
        }

        if ( rang < 1 )
        {
                ShowMessage("Ранг не может быть меньше 1!");
                return 0;
        }

        if ( dim < 2 )
        {
                ShowMessage("Размерность должна быть больше либо равна 2!");
                return 0;
        }

        r = random( rang ) + 1;
        if( r ==1 )
                r ++;

//  prev = 1;

        for( i = 0; i < dim; i ++ )
        for( j = 0; j < dim; j ++ )
        {
                ma[i][j] = 0;
        }

        for( i = 0; i < r; i ++ )
        for( j = 0; j < dim; j ++ )
        {
                ma[i][j] = rgen( keygen, 1, amin, amax );
        }

        while( !determ( r, ma ) )
        for( i = 0; i < r; i ++ )
        for( j = 0; j < dim; j ++ )
        {
                ma[i][j] = rgen( keygen, 1, amin, amax );
        }

        for( i = r; i < dim; i ++ )
        {
                for( k = 0; k < i; k ++ )
                        mas[k] = pow( -1, random( 2 ) ) * ( random( 2 ) + 2 );

               for( j = 0; j < dim; j ++ )
               {
                        ma[i][j] = 0;
                        for( k = 0; k < r; k ++ )
                                ma[i][j] += mas[k] * ma[k][j];
                }
        }

  /*for ( i = 0; i < r; i ++ )
        for ( j = 0; j < dim; j ++ )
        {
                matr[i][j] = rgen(keygen, 1, amin, amax);

                while ( prev == matr[i][j] )
                        matr[i][j] = rgen(keygen, 1, amin, amax);

                prev = matr[i][j];
        }

  for ( i = r; i < dim; i ++ )
  {
        ch = rgen(keygen, 1, amin, amax);
        num = random( r );

        for ( j = 0; j < dim; j ++ )
        {
                matr[i][j] = ch * matr[num][j];
        }
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
                sprintf( buf, "String(Найти ранг матрицы %dх%d.)", dim, dim );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "A=!(Matrix(%d,%d", dim, dim );

        for ( i = 0; i < dim; i ++ )
        for ( j = 0; j < dim; j ++ )
        {
                sprintf( buf1, ",%d", ma[i][j] );
                strcat( buf, buf1 );
        }

        sprintf( buf1, "))" );
        strcat( buf, buf1 );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        sprintf( buf, "rang=%d", r );
        plist->Add( strdup(buf) );

        sprintf( buf, "A=!(Matrix(%d,%d", dim, dim );
        for ( i = 0; i < dim; i ++ )
                for ( j = 0; j < dim; j++ )
                {
                        TmpMtr[i][j] = ma[i][j];
                        sprintf( buf1, ",%d", ma[i][j] );
                        strcat( buf, buf1 );
                }

        sprintf( buf1, "))" );
        strcat( buf, buf1 );
        plist->Add( strdup(buf) );

        for ( i = 0; i < dim; i ++ )
                for ( j = i + 1; j < dim; j++ )
                {
                        /*if ( TmpMtr[i][i] == 0 )
                                continue;
                        /*{
                                ch = j;
                        while ( ch < dim )
                        {
                                if ( TmpMtr[ch][i] )
                                {
                                        for ( k = i; k <= dim; k ++)
                                        {
                                                temp = TmpMtr[ch][k];
                                                TmpMtr[ch][k] = TmpMtr[i][k];
                                                TmpMtr[i][k] = temp;
                                        }
                                        break;
                                }
                                else
                                        j ++;
                        }
                        } */
//                        continue;

                        tmp1 = TmpMtr[i][i];
                        tmp2 = TmpMtr[j][i];

                        for ( k = i; k < dim; k ++)
                                TmpMtr[j][k] = TmpMtr[j][k]*tmp1 - TmpMtr[i][k]*tmp2;
                }

        sprintf( buf, "A^Asterix=!(Matrix(%d,%d", dim, dim );
        for ( i = 0; i < dim; i ++ )
        for ( j = 0; j < dim; j++ )
        {
                sprintf( buf1, ",%d", TmpMtr[i][j] );
                strcat( buf, buf1 );
        }

        sprintf( buf1, "))" );
        strcat( buf, buf1 );
        plist->Add( strdup(buf) );

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//------------------------------------------------------------------------------

quest21::Print(TList* plist, class test &t)
{
        int i, j, k, r;
        int ma[10][10], mas[10];
        int n, Right_Numb, tmp1;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        Right_Numb = random( dim ) + 1;

        if ( rang > dim )
        {
                ShowMessage( "Ранг должен быть меньше размера матрицы!" );
                return 0;
        }

        if ( rang < 1 )
        {
                ShowMessage( "Ранг не может быть меньше 1!" );
                return 0;
        }

        r = random( rang ) + 1;
        if( r ==1 )
                r ++;

        for( i = 0; i < dim; i ++ )
        for( j = 0; j < dim; j ++ )
        {
                ma[i][j] = 0;
        }

        for( i = 0; i < r; i ++ )
        for( j = 0; j < dim; j ++ )
        {
                ma[i][j] = rgen( keygen, 1, amin, amax );
        }

        while( !determ( r, ma ) )
        for( i = 0; i < r; i ++ )
        for( j = 0; j < dim; j ++ )
        {
                ma[i][j] = rgen( keygen, 1, amin, amax );
        }

        for( i = r; i < dim; i ++ )
        {
                for( k = 0; k < i; k ++ )
                        mas[k] = pow( -1, random( 2 ) ) * ( random( 2 ) + 2 );

                for( j = 0; j < dim; j ++ )
                {
                        ma[i][j] = 0;
                        for( k = 0; k < r; k ++ )
                                ma[i][j] += mas[k] * ma[k][j];
                }
        }

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add(strdup(buf));

        sprintf( buf, "String(Найти ранг матрицы %dх%d.)", dim, dim );
        plist->Add( strdup(buf) );

        sprintf( buf, "A=!(Matrix(%d,%d", dim, dim );

        for ( i = 0; i < dim; i ++ )
                for ( j = 0; j < dim; j ++ )
                {
                        sprintf( buf1, ",%d", ma[i][j] );
                        strcat( buf, buf1 );
                }

        sprintf( buf1, "))" );
        strcat( buf, buf1 );
        plist->Add( strdup(buf) );

        tmp1 = r;

        for ( n = 0; n < dim; n ++ )
        {
                sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
                plist->Add(strdup(buf));

                if ( n != Right_Numb - 1 )
                {
                        sprintf(buf,"rang=%d", ( tmp1++ ) % dim + 1 );
                        plist->Add(strdup(buf));
                }
                else
                {
                        sprintf(buf,"rang=%d", r );
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
        t.ch_ask = dim;
        t.right_ask = Right_Numb;
        t.msg = "Тест успешно сгенерирован.";

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//-----------------------------------------------------------


