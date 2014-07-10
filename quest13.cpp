//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest13.h"
#include "MPlane.h"
#include "quest5.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest13::quest13(FILE* f)
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

quest13::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest13::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  Plane->quest = this;

  Plane->Edit1->Text = IntToStr(amin);
  Plane->Edit2->Text = IntToStr(amax);
  Plane->Edit3->Text = IntToStr(keygen);
  Plane->Edit4->Text = IntToStr(nvar);

  Plane->ShowModal();

  return 0;
}

quest13::Print(TList* plist)
{
        int i, j, k;
        int a[3], b[3], c[3];
        int plane[4], vert[4][10], vert_t[4][10];

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for( i = 0; i < 3; i ++ )
        {
                a[i] = rgen( keygen, 1, amin, amax );

                b[i] = rgen( keygen, 1, amin, amax );
                while ( b[i] == a[i] )
                        b[i] = rgen( keygen, 1, amin, amax );

                c[i] = rgen( keygen, 1, amin, amax );
                while ( c[i] == b[i] || c[i] == a[i] )
                        c[i] = rgen( keygen, 1, amin, amax );

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
                sprintf( buf, "String(Найти общее уравнение плоскости зная 3 точки.)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "A!(%d", a[0] );

        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", a[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "B!(%d", b[0] );

        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", b[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "C!(%d", c[0] );

        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", c[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        for ( i = 0; i < 3; i ++ )
        {
                vert[0][i] = b[i];
                vert[1][i] = a[i] - b[i];
                vert[2][i] = c[i] - b[i];
        }

        for ( i = 0; i < 3; i ++ )
        {
                k = 0;

                for ( j = 0; j < 3; j ++ )
                {
                        if ( j != i )
                        {
                                vert_t[0][k] = vert[1][j];
                                vert_t[1][k] = vert[2][j];
                                k ++;
                        }
                }

                plane[i] = pow(-1,i) * determ( 2, vert_t );
        }

        plane[3] = - determ ( 3, vert );

        sprintf( buf, "String(Искомая плоскость: )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "|Matrix(3,3" );

        for ( i = 0; i < 3; i ++ )
        for ( j = 0; j < 3; j ++ )
        {
                switch ( i )
                {
                        case 0:

                        sprintf( buf1, ",%d", a[j] - b[j] );

                        break;

                        case 1:

                        sprintf( buf1, ",%d", c[j] - b[j] );

                        break;

                        case 2:

                        if ( j == 0 )
                        if ( b[j] )
                                sprintf( buf1, ",x%+d", - b[j] );
                        else
                                sprintf( buf1, ",x" );
                        else
                        if ( j == 1 )
                        if ( b[j] )
                                sprintf( buf1, ",y%+d", - b[j] );
                        else
                                sprintf( buf1, ",y" );
                        else
                        if ( b[j] )
                                sprintf( buf1, ",z%+d", - b[j] );
                        else
                                sprintf( buf1, ",z" );
                }

                strcat( buf, buf1 );
        }

        strcat( buf, ")|=0" );
        plist->Add( strdup(buf) );

        strcpy ( buf, "" );

        if ( plane[0] )
        {
                if ( plane[0] == 1 )
                        sprintf( buf1, "x" );
                else
                if ( plane[0] == -1 )
                        sprintf( buf1, "-x" );
                else
                        sprintf( buf1, "%d*x", plane[0] );

                strcat ( buf, buf1 );
        }

        if ( plane[1] )
        {
                if ( plane[1] == 1 )
                        sprintf( buf1, "+y" );
                else
                if ( plane[1] == -1 )
                        sprintf( buf1, "-y" );
                else
                        sprintf( buf1, "%+d*y", plane[1] );

                strcat ( buf, buf1 );
        }

        if ( plane[2] )
        {
                if ( plane[2] == 1 )
                        sprintf( buf1, "+z" );
                else
                if ( plane[2] == -1 )
                        sprintf( buf1, "-z" );
                else
                        sprintf( buf1, "%+d*z", plane[2] );

                strcat ( buf, buf1 );
        }

        if ( plane[3] )
        {
                sprintf( buf1, "%+d", plane[3] );
                strcat( buf, buf1 );
        }

        if ( plane [0] || plane[1] || plane[2] || plane[3] )
        {
                strcat( buf, "=0" );
                plist->Add( strdup(buf) );
        }

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//------------------------------------------------------------------------------

quest13::Print(TList* plist, class test &t)
{
        int i, j, k;
        int a[3], b[3], c[3];
        int plane[4], vert[4][10], vert_t[4][10];
        int n, Right_Numb;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        Right_Numb = random( 5 ) + 1;

        srand( keygen );

        for( i = 0; i < 3; i ++ )
        {
                a[i] = rgen( keygen, 1, amin, amax );

                b[i] = rgen( keygen, 1, amin, amax );
                while ( b[i] == a[i] )
                        b[i] = rgen( keygen, 1, amin, amax );

                c[i] = rgen( keygen, 1, amin, amax );
                while ( c[i] == b[i] || c[i] == a[i] )
                        c[i] = rgen( keygen, 1, amin, amax );

        }

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Найти общее уравнение плоскости зная 3 точки.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "A!(%d", a[0] );

        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", a[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "B!(%d", b[0] );

        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", b[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "C!(%d", c[0] );

        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", c[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        for ( i = 0; i < 3; i ++ )
        {
                vert[0][i] = b[i];
                vert[1][i] = a[i] - b[i];
                vert[2][i] = c[i] - b[i];
        }

        for ( i = 0; i < 3; i ++ )
        {
                k = 0;

                for ( j = 0; j < 3; j ++ )
                {
                        if ( j != i )
                        {
                                vert_t[0][k] = vert[1][j];
                                vert_t[1][k] = vert[2][j];
                                k ++;
                        }
                }

                plane[i] = pow(-1,i) * determ( 2, vert_t );
        }

        plane[3] = - determ ( 3, vert );

        for( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                strcpy ( buf, "" );

                if ( plane[0] - ( Right_Numb - 1 ) + n )
                {
                        if ( plane[0] - ( Right_Numb - 1 ) + n == 1 )
                                sprintf( buf1, "x" );
                        else
                        if ( plane[0] - ( Right_Numb - 1 ) + n == -1 )
                                sprintf( buf1, "-x" );
                        else
                                sprintf( buf1, "%d*x", plane[0] - ( Right_Numb - 1 ) + n );

                        strcat ( buf, buf1 );
                }

                if ( plane[1] - ( Right_Numb - 1 ) + n )
                {
                        if ( plane[1] - ( Right_Numb - 1 ) + n == 1 )
                                sprintf( buf1, "+y" );
                        else
                        if ( plane[1] - ( Right_Numb - 1 ) + n == -1 )
                                sprintf( buf1, "-y" );
                        else
                                sprintf( buf1, "%+d*y", plane[1] - ( Right_Numb - 1 ) + n );

                        strcat ( buf, buf1 );
                }

                if ( plane[2] - ( Right_Numb - 1 ) + n )
                {
                        if ( plane[2] - ( Right_Numb - 1 ) + n == 1 )
                                sprintf( buf1, "+z" );
                        else
                        if ( plane[2] - ( Right_Numb - 1 ) + n == -1 )
                                sprintf( buf1, "-z" );
                        else
                                sprintf( buf1, "%+d*z", plane[2] - ( Right_Numb - 1 ) + n );

                        strcat ( buf, buf1 );
                }

                if ( plane[3] - ( Right_Numb - 1 ) + n )
                {
                        sprintf( buf1, "%+d", plane[3] - ( Right_Numb - 1 ) + n );
                        strcat( buf, buf1 );
                }

                if ( plane[0] || plane[1] || plane[2] || plane[3] )
                {
                        strcat( buf, "=0" );
                        plist->Add( strdup(buf) );
                }
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


