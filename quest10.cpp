//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest10.h"
#include "MNormal.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest10::quest10(FILE* f)
{
  char* buf = new char[256];

  //randomize();
  keygen = random (1000) + 1;

  reads( f, buf );
  strpar1 = strdup( buf );
  reads( f, buf );
  strpar2 = strdup( buf );

  sscanf( strpar1, "%d %d %d", &amin, &amax, &TypeQ );
  qtype = type;

  delete buf;
}

quest10::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest10::Edit()
{
  sscanf(strpar2,"%i%i%i", &amin, &amax, &TypeQ);

  keygen = 0;
  nvar = 1;

  Normal->quest = this;

  Normal->Edit1->Text = IntToStr(amin);
  Normal->Edit2->Text = IntToStr(amax);
  Normal->Edit3->Text = IntToStr(keygen);
  Normal->Edit4->Text = IntToStr(nvar);
  Normal->ComboBox1->ItemIndex = TypeQ;

  Normal->ShowModal();

  return 0;
}

quest10::Print(TList* plist)
{
        int i, plane[4], A[4];

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for( i = 0; i < 4; i ++ )
        {
                plane[i] = rgen( keygen, 1, amin, amax );
                A[i] = rgen( keygen, 1, amin, amax );
        }

        while( !plane[0] )
                plane[0] = rgen( keygen, 1, amin, amax );

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

        sprintf( buf, "String(Вариант   %i, задача %i. )", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        switch ( TypeQ )
        {
                case 0:

                if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
                {
                        sprintf( buf, "String(Найти нормальный вектор к плоскости.)" );
                        plist->Add( strdup(buf) );

                        sprintf( buf, "String(Плоскость задана уравнением:)" );
                        plist->Add( strdup(buf) );
                }

                if( abs( plane[0] ) > 1 )
                        sprintf( buf, "%d*x", plane[0] );
                else
                if( plane[0] < 0 )
                        sprintf( buf, "-x" );
                else
                if( plane[0] > 0 )
                        sprintf( buf, "x" );

                if ( abs( plane[1] ) > 1 )
                        sprintf( buf1, "%+d*y", plane[1] );
                else
                if( plane[1] < 0 )
                        sprintf( buf1, "-y" );
                else
                if( plane[1] > 0 )
                        sprintf( buf1, "+y" );
                else
                        sprintf( buf1, "" );
                strcat( buf, buf1 );

                if ( abs( plane[2] ) > 1 )
                        sprintf( buf1, "%+d*z", plane[2] );
                else
                if( plane[2] < 0 )
                        sprintf( buf1, "-z" );
                else
                if( plane[2] > 0 )
                        sprintf( buf1, "+z" );
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

                sprintf( buf, "_n=..." );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(@Часть преподавателя )" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
                plist->Add( strdup(buf) );

                sprintf(buf,"_n=!(%d", plane[0] );

                for ( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", plane[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                break;

                case 1:

                if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
                {
                        sprintf( buf, "String(Зная нормальный вектор и точку плоскости выписать её уравнение.)" );
                        plist->Add( strdup(buf) );

                        sprintf( buf, "String(Нормальный вектор:)" );
                        plist->Add( strdup(buf) );
                }

                sprintf( buf, "_n=!(%d", plane[0] );

                for ( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", plane[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
                {
                        sprintf( buf, "String(Точка:)" );
                        plist->Add( strdup(buf) );
                }

                sprintf( buf, "M_0=!(%d", A[0] );

                for ( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", A[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "alpha=..." );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(@Часть преподавателя )" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
                plist->Add( strdup(buf) );

                sprintf( buf, "alpha" );
                plist->Add( strdup(buf) );

                plane[3] = 0;

                for ( i = 0; i < 3; i ++ )
                        plane[3] -= plane[i] * A[i];

                if( abs( plane[0] ) > 1 )
                        sprintf( buf, "%d*x", plane[0] );
                else
                if( plane[0] < 0 )
                        sprintf( buf, "-x" );
                else
                if( plane[0] > 0 )
                        sprintf( buf, "x" );

                if ( abs( plane[1] ) > 1 )
                        sprintf( buf1, "%+d*y", plane[1] );
                else
                if( plane[1] < 0 )
                        sprintf( buf1, "-y" );
                else
                if( plane[1] > 0 )
                        sprintf( buf1, "+y" );
                else
                        sprintf( buf1, "" );
                strcat( buf, buf1 );

                if ( abs( plane[2] ) > 1 )
                        sprintf( buf1, "%+d*z", plane[2] );
                else
                if( plane[2] < 0 )
                        sprintf( buf1, "-z" );
                else
                if( plane[2] > 0 )
                        sprintf( buf1, "+z" );
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

                break;
        }

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//------------------------------------------------------------------------------

quest10::Print(TList* plist, class test &t)
{
        int plane[4], A[4];
        int i, n, Right_Numb;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        Right_Numb = random( 5 ) + 1;

        srand( keygen );

        for( i = 0; i < 4; i ++ )
        {
                plane[i] = rgen( keygen, 1, amin, amax );
                A[i] = rgen( keygen, 1, amin, amax );
        }

        while( !plane[0] )
                plane[0] = rgen( keygen, 1, amin, amax );

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i. )", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        switch ( TypeQ )
        {
                case 0:
                
                sprintf( buf, "String(Найти нормальный вектор к плоскости.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Плоскость задана уравнением:)" );
                plist->Add( strdup(buf) );

                if( abs( plane[0] ) > 1 )
                        sprintf( buf, "%d*x", plane[0] );
                else
                if( plane[0] < 0 )
                        sprintf( buf, "-x" );
                else
                if( plane[0] > 0 )
                        sprintf( buf, "x" );

                if ( abs( plane[1] ) > 1 )
                        sprintf( buf1, "%+d*y", plane[1] );
                else
                if( plane[1] < 0 )
                        sprintf( buf1, "-y" );
                else
                if( plane[1] > 0 )
                        sprintf( buf1, "+y" );
                else
                        sprintf( buf1, "" );
                strcat( buf, buf1 );

                if ( abs( plane[2] ) > 1 )
                        sprintf( buf1, "%+d*z", plane[2] );
                else
                if( plane[2] < 0 )
                        sprintf( buf1, "-z" );
                else
                if( plane[2] > 0 )
                        sprintf( buf1, "+z" );
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

                sprintf( buf, "_n=..." );
                plist->Add( strdup(buf) );

                for( n = 0; n < 5; n ++ )
                {
                        sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                        plist->Add( strdup(buf) );

                        sprintf( buf, "_n=!(%d", plane[0]  - ( Right_Numb - 1 ) + n );

                        for (i = 1; i < 3; i ++)
                        {
                                sprintf( buf1, ",%d", plane[i] - ( Right_Numb - 1 ) + n );
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

                break;

                case 1:

                sprintf( buf, "String(Зная нормальный вектор и точку плоскости выписать её уравнение.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Нормальный вектор:)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_n=!(%d", plane[0] );

                for ( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", plane[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Точка:)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "M_0=!(%d", A[0] );

                for ( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", A[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "alpha=..." );
                plist->Add( strdup(buf) );

                plane[3] = 0;

                for ( i = 0; i < 3; i ++ )
                        plane[3] -= plane[i] * A[i];

                for( n = 0; n < 5; n ++ )
                {
                        sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                        plist->Add( strdup(buf) );

                        if( abs( plane[0] - ( Right_Numb - 1 ) + n ) > 1 )
                                sprintf( buf, "%d*x", plane[0] - ( Right_Numb - 1 ) + n );
                        else
                        if( plane[0] - ( Right_Numb - 1 ) + n < 0 )
                                sprintf( buf, "-x" );
                        else
                        if( plane[0] - ( Right_Numb - 1 ) + n > 0 )
                                sprintf( buf, "x" );

                        if ( abs( plane[1] - ( Right_Numb - 1 ) + n ) > 1 )
                                sprintf( buf1, "%+d*y", plane[1] - ( Right_Numb - 1 ) + n );
                        else
                        if( plane[1] - ( Right_Numb - 1 ) + n < 0 )
                                sprintf( buf1, "-y" );
                        else
                        if( plane[1] - ( Right_Numb - 1 ) + n > 0 )
                                sprintf( buf1, "+y" );
                        else
                                sprintf( buf1, "" );
                        strcat( buf, buf1 );

                        if ( abs( plane[2] - ( Right_Numb - 1 ) + n ) > 1 )
                                sprintf( buf1, "%+d*z", plane[2] - ( Right_Numb - 1 ) + n );
                        else
                        if( plane[2] - ( Right_Numb - 1 ) + n < 0 )
                                sprintf( buf1, "-z" );
                        else
                        if( plane[2] - ( Right_Numb - 1 ) + n > 0 )
                                sprintf( buf1, "+z" );
                        else
                                sprintf( buf1, "" );
                        strcat( buf, buf1 );

                        if ( plane[3] - ( Right_Numb - 1 ) + n )
                                sprintf( buf1, "%+d", plane[3] - ( Right_Numb - 1 ) + n );
                        else
                                sprintf( buf1, "" );
                        strcat( buf, buf1 );

                        strcat( buf, "=0" );
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


