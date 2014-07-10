//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest18.h"
#include "drobi.h"
#include "MDl.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest18::quest18(FILE* f)
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

quest18::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest18::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  PRLine->quest = this;

  PRLine->Edit1->Text = IntToStr(amin);
  PRLine->Edit2->Text = IntToStr(amax);
  PRLine->Edit3->Text = IntToStr(keygen);
  PRLine->Edit4->Text = IntToStr(nvar);

  PRLine->ShowModal();

  return 0;
}

quest18::Print(TList* plist)
{
        int i, j, k;
        int p[4], a[3], b[3], c[3];
        int M[3], matr[2][2];

        double absc, absa;

        drobi d;

        char * buf = new char[256];
        char * buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for( i = 0; i < 4; i ++ )
        {
                a[i] = rgen( keygen, 1, amin, amax );
                M[i] = rgen( keygen, 1, amin, amax );
                p[i] = rgen( keygen, 1, amin, amax );

                while ( p[i] == M[i] )
                        p[i] = rgen( keygen, 1, amin, amax );
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
                sprintf( buf, "String(Найти расстояние от точки до прямой.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Прямая задана уравнением:)" );
                plist->Add( strdup(buf) );
        }

        if( M[0] )
                sprintf( buf, "(x%+d)/%d=", -M[0], a[0] );
        else
                sprintf( buf, "x/%d=", a[0] );

        if( M[1] )
                sprintf( buf1, "(y%+d)/%d=", -M[1], a[1] );
        else
                sprintf( buf1, "y/%d=", a[1] );
        strcat( buf, buf1 );

        if( M[2] )
                sprintf( buf1, "(z%+d)/%d", -M[2], a[2] );
        else
                sprintf( buf1, "z/%d", a[2] );

        strcat( buf, buf1 );
        plist->Add( strdup(buf) );

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(Координаты точки:)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "A!(%d", p[0] );
        for( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", p[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "d=..." );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        for ( i = 0; i < 3; i++ )
                b[i] = M[i] - p[i];

        for (i = 0; i < 3; i ++)
        {
                k = 0;

                for ( j = 0; j < 3; j ++ )
                {
                        if ( j != i )
                        {
                                matr[0][k] = a[j];
                                matr[1][k] = b[j];
                                k ++;
                        }
                }

                c[i] = pow ( -1, i ) * determ( 2, matr );
        }

        absc = 0;

        for ( i = 0; i < 3; i ++ )
                absc += c[i] * c[i];

        absa = 0;

        for ( i = 0; i < 3; i ++ )
                absa += a[i] * a[i];

        if ( !absc )
                sprintf( buf, "d=0" );
        else
        if ( ( ceil( sqrt( absc ) ) ) == ( sqrt( absc ) ) && ( ceil( sqrt( absa ) ) ) == ( sqrt( absa ) ) )
        {
                d = drobi( sqrt( absc ), sqrt( absa ) );
                //sprintf( buf, "d=%d/%d", d.a, d.b );
                sprintf( buf, "d=%s", DrobiToStr( d ) );
        }
        else
        if ( ( ceil( sqrt( absc ) ) ) == ( sqrt( absc ) ) )
                sprintf( buf, "d=%f/sqrt(%f)", sqrt( absc ), absa );
        else
        if ( ( ceil( sqrt( absa ) ) ) == ( sqrt( absa ) ) )
                sprintf( buf, "d=sqrt(%f)/%f", absc, sqrt( absa ) );
        else
                sprintf( buf, "d=sqrt(%f)/sqrt(%f)", absc, absa );

        plist->Add( strdup(buf) );

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//------------------------------------------------------------------------------

int determ( int dim, int ma[][2])
{
        int det;

        det = ma[0][0]*ma[1][1] - ma[0][1]*ma[1][0];

        return det;
}
//------------------------------------------------------------------------------

quest18::Print(TList* plist, class test &t)
{
        int i, j, k;
        int p[4], a[3], b[3], c[3];
        int M[3], matr[2][2];
        int n, Right_Numb;

        double absc, absa;

        drobi d;

        char * buf = new char[256];
        char * buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        Right_Numb = random( 5 ) + 1;

        srand( keygen );

        for( i = 0; i < 4; i ++ )
        {
                a[i] = rgen( keygen, 1, amin, amax );
                M[i] = rgen( keygen, 1, amin, amax );
                p[i] = rgen( keygen, 1, amin, amax );

                while ( p[i] == M[i] )
                        p[i] = rgen( keygen, 1, amin, amax );
        }

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Найти расстояние от точки до прямой.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Прямая задана уравнением:)" );
        plist->Add( strdup(buf) );

        if( M[0] )
                sprintf( buf, "(x%+d)/%d=", -M[0], a[0] );
        else
                sprintf( buf, "x/%d=", a[0] );

        if( M[1] )
                sprintf( buf1, "(y%+d)/%d=", -M[1], a[1] );
        else
                sprintf( buf1, "y/%d=", a[1] );
        strcat( buf, buf1 );

        if( M[2] )
                sprintf( buf1, "(z%+d)/%d", -M[2], a[2] );
        else
                sprintf( buf1, "z/%d", a[2] );

        strcat( buf, buf1 );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Координаты точки:)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "A!(%d", p[0] );

        for( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", p[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "d=..." );
        plist->Add( strdup(buf) );

        for ( i = 0; i < 3; i++ )
                b[i] = M[i] - p[i];

        for (i = 0; i < 3; i ++)
        {
                k = 0;

                for ( j = 0; j < 3; j ++ )
                {
                        if ( j != i )
                        {
                                matr[0][k] = a[j];
                                matr[1][k] = b[j];
                                k ++;
                        }
                }

                c[i] = pow ( -1, i ) * determ( 2, matr );
        }

        absc = 0;

        for ( i = 0; i < 3; i ++ )
                absc += c[i] * c[i];

        absa = 0;

        for ( i = 0; i < 3; i ++ )
                absa += a[i] * a[i];

        if( absc < 5 )
                Right_Numb = 1;

        for( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                if ( !( absc - ( Right_Numb - 1 ) + n ) )
                        sprintf( buf, "d=0" );
                else
                if ( ( ceil( sqrt( absc - ( Right_Numb - 1 ) + n ) ) ) == ( sqrt( absc - ( Right_Numb - 1 ) + n ) ) && ( ceil( sqrt( absa ) ) ) == ( sqrt( absa ) ) )
                {
                        d = drobi( sqrt( absc - ( Right_Numb - 1 ) + n ), sqrt( absa ) );
                        //sprintf( buf, "d=%d/%d", d.a, d.b );
                        sprintf( buf, "d=%s", DrobiToStr( d ) );
                }
                else
                if ( ( ceil( sqrt( absc - ( Right_Numb - 1 ) + n ) ) ) == ( sqrt( absc - ( Right_Numb - 1 ) + n ) ) )
                        sprintf( buf, "d=%f/sqrt(%f)", sqrt( absc - ( Right_Numb - 1 ) + n ), absa );
                else
                if ( ( ceil( sqrt( absa ) ) ) == ( sqrt( absa ) ) )
                        sprintf( buf, "d=sqrt(%f)/%f", absc - ( Right_Numb - 1 ) + n, sqrt( absa ) );
                else
                        sprintf( buf, "d=sqrt(%f)/sqrt(%f)", absc - ( Right_Numb - 1 ) + n, absa );

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
//-----------------------------------------------------------


