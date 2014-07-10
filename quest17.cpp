//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest17.h"
#include "MSmMul.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest17::quest17(FILE* f)
{
  char* buf = new char[256];

  keygen = 0;
  nvar = 1;

  reads( f, buf );
  strpar1 = strdup( buf );
  reads( f, buf );
  strpar2 = strdup( buf );

  sscanf( strpar1, "%d %d %d", &amin, &amax, &number );
  qtype = type;

  delete buf;
}

quest17::Save(FILE* f)
{
  fprintf( f, "head %i\n", type );
  fprintf( f, "%s\n", name );
  fprintf( f, "%i %i %i\n", itemnumber, subitemnumber, qtype );
  fprintf( f, "%s\n", strpar1 );
  fprintf( f, "%s\n", strpar2 );

  return 0;
}

quest17::Edit()
{
  sscanf( strpar2, "%i%i", &amin, &amax );

  keygen = 0;
  nvar = 1;

  SmMul->quest = this;

  SmMul->Edit1->Text = IntToStr(amin);
  SmMul->Edit2->Text = IntToStr(amax);
  SmMul->Edit3->Text = IntToStr(keygen);
  SmMul->Edit4->Text = IntToStr(nvar);
  SmMul->ComboBox1->ItemIndex = number;

  SmMul->ShowModal();

  return 0;
}

quest17::Print(TList* plist)
{
        int i, ma[3], mb[3], mc[3], matr[3][3];
        int a = 1, b = 1, zn1, zn2;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        while ( a == 1 )
                a = random ( 2 ) + 1;

        while ( b == 1 )
                b = random ( 2 ) + 1;

        zn1 = pow ( -1, random (2) );
        zn2 = pow ( -1, random (2) );

        for( i = 0; i < 3; i ++ )
        {
                ma[i] = rgen( keygen, 1, amin, amax );

                if ( number != 2)
                {
                        mb[i] = rgen( keygen, 1, amin, amax );
                        mc[i] = rgen( keygen, 1, amin, amax );

                        while ( mb[i] == ma[i] )
                                mb[i] = rgen( keygen, 1, amin, amax );

                        while ( mc[i] == ma[i] || mc[i] == mb[i] )
                                mc[i] = rgen( keygen, 1, amin, amax );
                }
                else
                {
                        mb[i] = rgen( keygen, 1, amin, amax );

                        while ( mb[i] == ma[i] )
                                mb[i] = rgen( keygen, 1, amin, amax );
                                
                        //mb[i] = zn1 * a * ma[i];
                        //mc[i] = zn2 * b * ma[i];
                        mc[i] = zn1 * a * ma[i] + zn2 * b * mb[i];
                }

                matr[0][i] = ma[i];
                matr[1][i] = mb[i];
                matr[2][i] = mc[i];
        }

        switch ( number )
        {

                case 0:

                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти смешанное произведение векторов.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_с=!(%d", mc[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mc[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                //sprintf( buf, "!(_a,_b,_c)=_a*.!(_b*+_c)=..." );
                sprintf( buf, "!(_a,_b,_c)=..." );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(@Часть преподавателя )" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_с=!(%d", mc[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mc[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                //sprintf( buf, "!(_a,_b,_c)=_a*.!(_b*+_c)=%d", determ(matr) );
                sprintf( buf, "!(_a,_b,_c)=%d", determ(matr) );                
                plist->Add( strdup(buf) );

                break;

                case 1:

                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти объём параллепипеда построенного на векторах.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_с=!(%d", mc[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mc[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "V=..." );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(@Часть преподавателя )" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_с=!(%d", mc[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mc[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "V=%d", abs ( determ( matr ) ) );
                plist->Add( strdup(buf) );

                break;

                case 2:

                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Используя смешанное произведение проверить компланарность.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_с=!(%d", mc[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mc[i] );
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

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_с=!(%d", mc[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mc[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вектора компланарны.)" );
                plist->Add( strdup(buf) );

                //sprintf( buf, "!(_a,_b,_c)=_a*.!(_b*+_c)=%d", determ( matr ) );
                sprintf( buf, "!(_a,_b,_c)=%d", determ( matr ) );
                plist->Add( strdup(buf) );

                break;
        }

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//-----------------------------------------------------------------

int determ( int ma[][3])
{
        int det;

        det = ma[0][0]*ma[1][1]*ma[2][2] + ma[0][1]*ma[1][2]*ma[2][0] + ma[1][0]*ma[2][1]*ma[0][2];
        det -= (ma[0][2]*ma[1][1]*ma[2][0] + ma[1][0]*ma[0][1]*ma[2][2] + ma[2][1]*ma[1][2]*ma[0][0]);

        return det;
}
//-----------------------------------------------------------------

quest17::Print(TList* plist, class test &t)
{
        int i, ma[3], mb[3], mc[3], matr[3][3];
        int a = 1, b = 1, zn1, zn2;
        int  n, Right_Numb;

        char* buf = new char[256];
        char* buf1 = new char[256];

        Right_Numb = random( 5 ) + 1;

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        while ( a == 1 )
                a = random ( 2 ) + 1;

        while ( b == 1 )
                b = random ( 2 ) + 1;

        zn1 = pow ( -1, random (2) );
        zn2 = pow ( -1, random (2) );

        for( i = 0; i < 3; i ++ )
        {
                ma[i] = rgen( keygen, 1, amin, amax );

                if ( number != 2 )
                {
                        mb[i] = rgen( keygen, 1, amin, amax );
                        mc[i] = rgen( keygen, 1, amin, amax );

                        while ( mb[i] == ma[i] )
                                mb[i] = rgen( keygen, 1, amin, amax );

                        while ( mc[i] == ma[i] || mc[i] == mb[i] )
                                mc[i] = rgen( keygen, 1, amin, amax );
                }
                else
                {
                        mb[i] = rgen( keygen, 1, amin, amax );

                        while ( mb[i] == ma[i] )
                                mb[i] = rgen( keygen, 1, amin, amax );

                        //mb[i] = zn1 * a * ma[i];
                        //mc[i] = zn2 * b * ma[i];
                        mc[i] = zn1 * a * ma[i] + zn2 * b * mb[i];
                }

                matr[0][i] = ma[i];
                matr[1][i] = mb[i];
                matr[2][i] = mc[i];
        }

        switch ( number )
        {

                case 0:

                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти смешанное произведение векторов.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_с=!(%d", mc[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mc[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                //sprintf( buf, "!(_a,_b,_c)=_a*.!(_b*+_c)=..." );
                sprintf( buf, "!(_a,_b,_c)=..." );
                plist->Add( strdup(buf) );

                for( i = 0; i < 5; i ++ )
                {
                        sprintf( buf, "String(\"Вариант %c):\")", 'a' + i );
                        plist->Add( strdup(buf) );

                        sprintf( buf, "!(_a,_b,_c)=%d", determ( matr ) - ( Right_Numb - 1 ) + i );
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

                break;

                case 1:

                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти объём параллепипеда построенного на векторах.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_с=!(%d", mc[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mc[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "V=..." );
                plist->Add( strdup(buf) );

                for( i = 0; i < 5; i ++ )
                {
                        sprintf( buf, "String(\"Вариант %c):\")", 'a' + i );
                        plist->Add( strdup(buf) );

                        sprintf( buf, "V=%d", abs( determ( matr ) ) - ( Right_Numb - 1 ) + i );
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

                break;

                case 2:

                sprintf( buf, "String(#Для данного типа задач тесты не генерируются.)" );
                plist->Add( strdup(buf) );

                /*sprintf( buf, "String(@Часть преподавателя )" );
                plist->Add( strdup(buf) );*/

                break;
        }

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


