//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest11.h"
#include "MLine.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest11::quest11(FILE* f)
{
  char* buf = new char[256];

  randomize();
  keygen = random (1000) + 1;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);

  sscanf(strpar1,"%d %d %d", &amin, &amax );
  qtype = type;

  delete buf;
}

quest11::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest11::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  Line->quest = this;

  Line->Edit1->Text = IntToStr(amin);
  Line->Edit2->Text = IntToStr(amax);
  Line->Edit3->Text = IntToStr(keygen);
  Line->Edit4->Text = IntToStr(nvar);

  Line->ShowModal();

  return 0;
}

quest11::Print(TList* plist)
{
        int i, j, k;
        int plane[4], plane2[4];
        int ma[3], matr[2][2];

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for( i = 0; i < 4; i ++ )
        {
                /*plane[i] = pow(-1,random(amin)) * (random(amax) + 2);
                plane2[i] = pow(-1,random(amin)) * (random(amax) + 2);*/
                plane[i] = rgen( keygen, 1, amin, amax );
                plane2[i] = rgen( keygen, 1, amin, amax);
        }

        while( !plane[0] )
                plane[0] = rgen( keygen, 1, amin, amax );

        while( !plane2[0] )
                plane2[0] = rgen( keygen, 1, amin, amax );

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

        sprintf( buf, "String(Вариант   %i, задача %i. )", nvar, nzad );
        plist->Add( strdup(buf) );

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(Найти направляющий вектор пересечения плоскостей.)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "_a=..." );
        plist->Add( strdup(buf) );

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(Плоскости заданы уравнениями:)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "alpha" );
        plist->Add( strdup(buf) );

        if( abs( plane[0] ) > 1 )
                sprintf( buf, "%d*x", plane[0] );
        else
        if( plane[0] < 0 )
                sprintf( buf, "-x" );
        else
                sprintf( buf, "x" );

        if ( abs( plane[1] ) > 1 )
                sprintf( buf1, "%+d*y", plane[1] );
        else
        if( plane[1] < 0 )
                sprintf( buf1, "-y" );
        else
        if ( plane[1] > 0 )
                sprintf( buf1, "+y" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( abs( plane[2] ) > 1 )
                sprintf( buf1, "%+d*z", plane[2] );
        else
        if ( plane[2] < 0 )
                sprintf( buf1, "-z" );
        else
        if ( plane[2] > 0 )
                sprintf( buf1, "+z", plane[2] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( plane[3] )
                sprintf( buf1, "%+d", plane[3] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        strcat( buf, "=0" );
        plist->Add( strdup(buf) );

        sprintf( buf, "beta" );
        plist->Add( strdup(buf) );

        if( abs( plane2[0] ) > 1 )
                sprintf( buf, "%d*x", plane2[0] );
        else
        if( plane2[0] < 0 )
                sprintf( buf, "-x" );
        else
                sprintf( buf, "x" );

        if ( abs( plane2[1] ) > 1 )
                sprintf( buf1, "%+d*y", plane2[1] );
        else
        if( plane2[1] < 0 )
                sprintf( buf1, "-y" );
        else
        if ( plane2[1] > 0 )
                sprintf( buf1, "+y" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( abs( plane2[2] ) > 1 )
                sprintf( buf1, "%+d*z", plane2[2] );
        else
        if ( plane2[2] < 0 )
                sprintf( buf1, "-z" );
        else
        if ( plane2[2] > 0 )
                sprintf( buf1, "+z", plane2[2] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( plane2[3] )
                sprintf( buf1, "%+d", plane2[3] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        strcat( buf, "=0" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        for ( i = 0; i < 3; i ++ )
        {
                k = 0;

                for ( j = 0; j < 3; j ++ )
                {
                        if ( j != i )
                        {
                                matr[0][k] = plane[j];
                                matr[1][k] = plane2[j];
                                k ++;
                        }
                }

                ma[i] = pow( -1, i ) * determ( 2, matr );
        }


        sprintf( buf, "_a=!(%d", ma[0] );

        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", ma[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
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

        det = ma[0][0] * ma[1][1] - ma[0][1] * ma[1][0];

        return det;
}
//------------------------------------------------------------------------------

quest11::Print(TList* plist, class test &t)
{
        int i, j, k;
        int plane[4], plane2[4];
        int ma[3], matr[2][2];
        int n, Right_Numb;

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
                /*plane[i] = pow(-1,random(amin)) * (random(amax) + 2);
                plane2[i] = pow(-1,random(amin)) * (random(amax) + 2);*/
                plane[i] = rgen( keygen, 1, amin, amax );
                plane2[i] = rgen( keygen, 1, amin, amax);
        }

        while( !plane[0] )
                plane[0] = rgen( keygen, 1, amin, amax );

        while( !plane2[0] )
                plane2[0] = rgen( keygen, 1, amin, amax );

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i. )", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Найти направляющий вектор пересечения плоскостей.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "_a=..." );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Плоскости заданы уравнениями:)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "alpha" );
        plist->Add( strdup(buf) );

        if( abs( plane[0] ) > 1 )
                sprintf( buf, "%d*x", plane[0] );
        else
        if( plane[0] < 0 )
                sprintf( buf, "-x" );
        else
                sprintf( buf, "x" );

        if ( abs( plane[1] ) > 1 )
                sprintf( buf1, "%+d*y", plane[1] );
        else
        if( plane[1] < 0 )
                sprintf( buf1, "-y" );
        else
        if ( plane[1] > 0 )
                sprintf( buf1, "+y" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( abs( plane[2] ) > 1 )
                sprintf( buf1, "%+d*z", plane[2] );
        else
        if ( plane[2] < 0 )
                sprintf( buf1, "-z" );
        else
        if ( plane[2] > 0 )
                sprintf( buf1, "+z", plane[2] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( plane[3] )
                sprintf( buf1, "%+d", plane[3] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        strcat( buf, "=0" );
        plist->Add( strdup(buf) );

        sprintf( buf, "beta" );
        plist->Add( strdup(buf) );

        if( abs( plane2[0] ) > 1 )
                sprintf( buf, "%d*x", plane2[0] );
        else
        if( plane2[0] < 0 )
                sprintf( buf, "-x" );
        else
                sprintf( buf, "x" );

        if ( abs( plane2[1] ) > 1 )
                sprintf( buf1, "%+d*y", plane2[1] );
        else
        if( plane2[1] < 0 )
                sprintf( buf1, "-y" );
        else
        if ( plane2[1] > 0 )
                sprintf( buf1, "+y" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( abs( plane2[2] ) > 1 )
                sprintf( buf1, "%+d*z", plane2[2] );
        else
        if ( plane2[2] < 0 )
                sprintf( buf1, "-z" );
        else
        if ( plane2[2] > 0 )
                sprintf( buf1, "+z", plane2[2] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( plane2[3] )
                sprintf( buf1, "%+d", plane2[3] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        strcat( buf, "=0" );
        plist->Add( strdup(buf) );

        for ( i = 0; i < 3; i ++ )
        {
                k = 0;

                for ( j = 0; j < 3; j ++ )
                {
                        if ( j != i )
                        {
                                matr[0][k] = plane[j];
                                matr[1][k] = plane2[j];
                                k ++;
                        }
                }

                ma[i] = pow( -1, i ) * determ( 2, matr );
        }

        for( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] - ( Right_Numb - 1 ) + n );

                for ( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] - ( Right_Numb - 1 ) + n );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
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


