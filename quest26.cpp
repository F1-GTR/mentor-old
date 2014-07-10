//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest26.h"
#include "drobi.h"
#include "MLinePlane.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest26::quest26(FILE* f)
{
  char* buf = new char[256];

  randomize();
  keygen = random (1000) + 1;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);

  sscanf(strpar1,"%d %d", &amin, &amax );
  qtype = type;

  delete buf;
}

quest26::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest26::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  LinePlane->quest = this;

  LinePlane->Edit1->Text = IntToStr(amin);
  LinePlane->Edit2->Text = IntToStr(amax);
  LinePlane->Edit3->Text = IntToStr(keygen);
  LinePlane->Edit4->Text = IntToStr(nvar);

  LinePlane->ShowModal();

  return 0;
}

quest26::Print(TList* plist)
{
        int i, j, k;
        int plane[4], plane2[4], p[3], matr[2][2], b[2];
        int detA, detB1, detB2;

        drobi m0[3];

        char * buf = new char[256];
        char * buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for( i = 0; i < 4; i ++ )
        {
                plane[i] = rgen( keygen, 1, amin, amax );
                plane2[i] = rgen( keygen, 1, amin, amax );
        }

        if ( !(plane[0] * plane2[1] - plane[1] * plane2[0]) )
                plane[1] += 1;

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
                sprintf( buf, "String(Найти линию пересечения плоскостей.)" );
                plist->Add( strdup(buf) );

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

        for (i = 0; i < 3; i ++)
        {
                k = 0;

                for (j = 0; j < 3; j ++)
                {
                        if ( j != i)
                        {
                                matr[0][k] = plane[j];
                                matr[1][k] = plane2[j];
                                k ++;
                        }
                }

                p[i] = pow(-1,i) * determ(2,matr);
        }

        b[0] = -plane[3];
        b[1] = -plane2[3];

        matr[0][0] = plane[0];
        matr[0][1] = plane[1];
        matr[1][0] = plane2[0];
        matr[1][1] = plane2[1];

        detA = determ( 2, matr );

        matr[0][0] = b[0];
        matr[0][1] = plane[1];
        matr[1][0] = b[1];
        matr[1][1] = plane2[1];

        detB1 = determ( 2, matr );

        matr[0][0] = plane[0];
        matr[0][1] = b[0];
        matr[1][0] = plane2[0];
        matr[1][1] = b[1];

        detB2 = determ( 2, matr );

        m0[2] = 0;
        m0[1] = drobi ( detB2, detA );
        m0[0] = drobi ( detB1, detA );

        sprintf( buf, "String( Линия пересечения плоскостей есть прямая.)" );
        plist->Add( strdup(buf) );

        if ( m0[0].znak > 0 )
                sprintf( buf, "(x+%s)/%d", DrobiToStr(m0[0]), p[0] );
        else
                sprintf( buf, "(x%s)/%d", DrobiToStr(m0[0]), p[0] );

        if ( m0[1].znak > 0 )
                sprintf( buf1, "=(y+%s)/%d", DrobiToStr(m0[1]), p[1] );
        else
                sprintf( buf1, "=(y%s)/%d", DrobiToStr(m0[1]), p[1] );

        strcat ( buf, buf1 );

        sprintf( buf1, "=z/%d", p[2] );

        strcat ( buf, buf1 );
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

quest26::Print(TList* plist, class test &t)
{
        int i, j, k;
        int plane[4], plane2[4], p[3], matr[2][2], b[2];
        int detA, detB1, detB2;
        int n, Right_Numb;

        drobi m0[3];

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
                plane[i] = rgen( keygen, 1, amin, amax );
                plane2[i] = rgen( keygen, 1, amin, amax );
        }

        if ( !(plane[0] * plane2[1] - plane[1] * plane2[0]) )
                plane[1] += 1;

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Найти линию пересечения плоскостей.)" );
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

        for (i = 0; i < 3; i ++)
        {
                k = 0;

                for (j = 0; j < 3; j ++)
                {
                        if ( j != i)
                        {
                                matr[0][k] = plane[j];
                                matr[1][k] = plane2[j];
                                k ++;
                        }
                }

                p[i] = pow(-1,i) * determ(2,matr);
        }

        b[0] = -plane[3];
        b[1] = -plane2[3];

        matr[0][0] = plane[0];
        matr[0][1] = plane[1];
        matr[1][0] = plane2[0];
        matr[1][1] = plane2[1];

        detA = determ( 2, matr );

        matr[0][0] = b[0];
        matr[0][1] = plane[1];
        matr[1][0] = b[1];
        matr[1][1] = plane2[1];

        detB1 = determ( 2, matr );

        matr[0][0] = plane[0];
        matr[0][1] = b[0];
        matr[1][0] = plane2[0];
        matr[1][1] = b[1];

        detB2 = determ( 2, matr );

        m0[2] = 0;
        m0[1] = drobi ( detB2, detA );
        m0[0] = drobi ( detB1, detA );

        for( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                if ( m0[0].znak > 0 )
                        sprintf( buf, "(x+%s)/%d", DrobiToStr(m0[0]), p[0] - ( Right_Numb - 1 ) + n );
                else
                        sprintf( buf, "(x%s)/%d", DrobiToStr(m0[0]), p[0] - ( Right_Numb - 1 ) + n );

                if ( m0[1].znak > 0 )
                        sprintf( buf1, "=(y+%s)/%d", DrobiToStr(m0[1]), p[1] - ( Right_Numb - 1 ) + n );
                else
                        sprintf( buf1, "=(y%s)/%d", DrobiToStr(m0[1]), p[1] - ( Right_Numb - 1 ) + n );

                strcat ( buf, buf1 );

                sprintf( buf1, "=z/%d", p[2] - ( Right_Numb - 1 ) + n );

                strcat ( buf, buf1 );
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


