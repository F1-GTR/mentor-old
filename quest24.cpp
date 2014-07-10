//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest24.h"
#include "drobi.h"
#include "determ.h"
#include "MObrMatr.h"
#include "tkurs.h"
#include "qvarnt.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest24::quest24( FILE* f )
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

quest24::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest24::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  ObrMatr->quest = this;
  ObrMatr->Edit1->Text = IntToStr(amin);
  ObrMatr->Edit2->Text = IntToStr(amax);
  ObrMatr->Edit3->Text = IntToStr(keygen);
  ObrMatr->Edit4->Text = IntToStr(nvar);
  ObrMatr->Edit5->Text = IntToStr(dim);

  ObrMatr->ShowModal();

  return 0;
}

quest24::Print(TList* plist)
{
        drobi mtr[10][10];

        int i, j, k, l, n;
        int ma[10][10], A[10][10];
        int det_A, det_B;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for( i = 0; i < dim; i++ )
        {
                for( j = 0; j < dim; j++ )
                {
                        ma[i][j] = 0;
                }
        }

        while( !determ( dim, ma ) )
        for( i = 0; i < dim; i++ )
        {
                for( j = 0; j < dim; j++ )
                {
                        ma[i][j] = rgen( keygen, 1, amin, amax );
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
                sprintf( buf, "String(Найти обратную матрицу к матрице:)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "A=!(Matrix(%d,%d", dim, dim );

        for ( i = 0; i < dim; i ++ )
        for ( j = 0; j < dim; j ++ )
        {
                sprintf( buf1, ",%d", ma[i][j] );
                strcat( buf, buf1 );
        }

        strcat( buf, "))" );
        plist->Add( strdup(buf) );

        sprintf( buf, "pow(A,-1)=..." );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        det_A = determ ( dim, ma );

        for ( i = 0; i < dim; i ++ )
        for ( j = 0; j < dim; j ++ )
        {
                int ai, aj;

                ai = 0;
                aj = 0;

                for ( k = 0; k < dim; k ++ )
                {
                        if ( k == j )
                                continue;
                        else
                        {
                        for ( l = 0; l < dim; l ++ )
                        {
                                if ( l != i )
                                {
                                        A[ai][aj] = ma[k][l];
                                        aj ++;
                                }
                                else
                                        continue;
                        }
                                ai ++;
                                aj = 0;
                        }
                }

                mtr[i][j] = drobi ( pow( -1, i + j ) * determ( dim - 1, A ), det_A );
                mtr[i][j].sokrat();
        }

        sprintf( buf, "pow(A,-1)=!(Matrix(%d,%d", dim, dim );

        for ( i = 0; i < dim; i ++ )
        for ( j = 0; j < dim; j ++ )
        {
                sprintf( buf1, ",%s", DrobiToStr( mtr[i][j] ) );
                strcat( buf, buf1 );
        }

        strcat( buf, "))" );
        plist->Add( strdup(buf) );

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//--------------------------------------------------------

quest24::Print(TList* plist, class test &t)
{
        drobi mtr[10][10];

        int i, j, k, l, n;
        int ma[10][10], A[10][10];
        int det_A, det_B;
        int Right_Numb;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        Right_Numb = random( 5 ) + 1;

        for( i = 0; i < dim; i++ )
        {
                for( j = 0; j < dim; j++ )
                {
                        ma[i][j] = 0;
                }
        }

        while( !determ( dim, ma ) )
        for( i = 0; i < dim; i++ )
        {
                for( j = 0; j < dim; j++ )
                {
                        ma[i][j] = rgen( keygen, 1, amin, amax);
                }
        }

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Найти обратную матрцу к матрице:)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "A=!(Matrix(%d,%d", dim, dim );

        for ( i = 0; i < dim; i ++ )
        for ( j = 0; j < dim; j ++ )
        {
                sprintf( buf1, ",%d", ma[i][j] );
                strcat( buf, buf1 );
        }

        strcat( buf, "))" );
        plist->Add( strdup(buf) );

        sprintf( buf, "pow(A,-1)=..." );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Варианты ответов: )" );
        plist->Add( strdup(buf) );

        for ( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                det_A = determ ( dim, ma );

                if ( n != Right_Numb - 1 )
                        det_A = det_A + ( random ( 20 ) - 10 );

                for ( i = 0; i < dim; i ++ )
                for ( j = 0; j < dim; j ++ )
                {
                        int ai, aj;

                        ai = 0;
                        aj = 0;

                        for ( k = 0; k < dim; k ++ )
                        {
                                if ( k == j )
                                        continue;
                                else
                                {
                                for ( l = 0; l < dim; l ++ )
                                {
                                        if ( l != i )
                                        {
                                                A[ai][aj] = ma[k][l];
                                                aj ++;
                                        }
                                        else
                                                continue;
                                }

                                ai ++;
                                aj = 0;
                        }
                }

                det_B = determ( dim - 1, A );
                if ( n != Right_Numb - 1 )
                        det_B = det_B + ( random ( 20 ) - 10 );

                mtr[i][j] = drobi ( pow( -1, i + j ) * det_B, det_A );
                mtr[i][j].sokrat();
                }

                sprintf( buf, "pow(A,-1)=!(Matrix(%d,%d", dim, dim );

                for ( i = 0; i < dim; i ++ )
                for ( j = 0; j < dim; j ++ )
                {
                        sprintf( buf1, ",%s", DrobiToStr( mtr[i][j] ) );
                        strcat( buf, buf1 );
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
        plist->Add(strdup(buf));
        GenHtml->Right_Number = Right_Numb;*/

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


