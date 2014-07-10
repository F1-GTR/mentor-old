//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest19.h"
#include "drobi.h"
#include "MPdl.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest19::quest19(FILE* f)
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

quest19::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest19::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  PlaneLine->quest = this;

  PlaneLine->Edit1->Text = IntToStr(amin);
  PlaneLine->Edit2->Text = IntToStr(amax);
  PlaneLine->Edit3->Text = IntToStr(keygen);
  PlaneLine->Edit4->Text = IntToStr(nvar);

  PlaneLine->ShowModal();

  return 0;
}

quest19::Print(TList* plist)
{
        int i, p[4], n[4];

        double absb, absa;

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
                n[i] = rgen( keygen, 1, amin, amax );
                p[i] = rgen( keygen, 1, amin, amax );
        }

        /*while( !n[0] )
                n[0] = rgen( keygen, 1, amin, amax );*/

        if( !n[0] )
                n[0] ++;

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
                sprintf( buf, "String(Найти расстояние от точки до плоскости.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Плоскость задана уравнением:)" );
                plist->Add( strdup(buf) );
        }

        if( abs( n[0] ) > 1 )
                sprintf( buf, "%d*x", n[0] );
        else
        if( n[0] < 0 )
                sprintf( buf, "-x" );
        else
        if( n[0] > 0 )
                sprintf( buf, "x" );

        if ( abs( n[1] ) > 1 )
                sprintf( buf1, "%+d*y", n[1] );
        else
        if( n[1] < 0 )
                sprintf( buf1, "-y" );
        else
        if( n[1] > 0 )
                sprintf( buf1, "+y" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( abs( n[2] ) > 1 )
                sprintf( buf1, "%+d*z", n[2] );
        else
        if( n[2] < 0 )
                sprintf( buf1, "-z" );
        else
        if( n[2] > 0 )
                sprintf( buf1, "+z" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( n[3] )
                sprintf( buf1, "%+d", n[3] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        strcat( buf, "=0" );
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

        absa = 0;
        for ( i = 0; i < 3; i ++ )
                absa += n[i] * p[i];

        absa -= n[3];

        absa = fabs( absa );

        absb = 0;

        for ( i = 0; i < 3; i ++ )
                absb += n[i] * n[i];

        if ( !absa )
                sprintf( buf, "d=0" );
        else
        if ( ( ceil( sqrt( absb ) ) ) == ( sqrt( absb ) ) )
        {
                d = drobi( absa, absb );
                //sprintf( buf, "d=%d/%d", d.a, d.b );
                sprintf( buf, "d=%s", DrobiToStr( d ) );
        }
        else
                sprintf( buf, "d=%f/sqrt(%f)", absa, absb );
        plist->Add( strdup(buf) );

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//------------------------------------------------------------------------------

quest19::Print(TList* plist, class test &t)
{
        int i, p[4], n[4];
        int m, Right_Numb;
        int absb, absa;

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
                n[i] = rgen( keygen, 1, amin, amax );
                p[i] = rgen( keygen, 1, amin, amax );
        }

        /*while( !n[0] )
                n[0] = rgen( keygen, 1, amin, amax );*/
        if( !n[0] )
                n[0] ++;

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Найти расстояние от точки до плоскости.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Плоскость задана уравнением:)" );
        plist->Add( strdup(buf) );

        if( abs( n[0] ) > 1 )
                sprintf( buf, "%d*x", n[0] );
        else
        if( n[0] < 0 )
                sprintf( buf, "-x" );
        else
        if( n[0] > 0 )
                sprintf( buf, "x" );

        if ( abs( n[1] ) > 1 )
                sprintf( buf1, "%+d*y", n[1] );
        else
        if( n[1] < 0 )
                sprintf( buf1, "-y" );
        else
        if( n[1] > 0 )
                sprintf( buf1, "+y" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( abs( n[2] ) > 1 )
                sprintf( buf1, "%+d*z", n[2] );
        else
        if( n[2] < 0 )
                sprintf( buf1, "-z" );
        else
        if( n[2] > 0 )
                sprintf( buf1, "+z" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( n[3] )
                sprintf( buf1, "%+d", n[3] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        strcat( buf, "=0" );
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

        absa = 0;

        for ( i = 0; i < 3; i ++ )
                absa += n[i] * p[i];

        absa -= n[3];

        absa = abs( absa );

        absb = 0;

        for ( i = 0; i < 3; i ++ )
                absb += n[i] * n[i];

        if( absa < 5 )
                Right_Numb = 1;

        for( m = 0; m < 5; m ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + m );
                plist->Add( strdup(buf) );

                if ( !( absa - ( Right_Numb - 1 ) + m ) )
                        sprintf( buf, "d=0" );
                else
                if ( ( ceil( sqrt( absb ) ) ) == ( sqrt( absb ) ) )
                {
                        d = drobi( absa - ( Right_Numb - 1 ) + m, absb );
                        sprintf( buf, "d=%s", DrobiToStr( d ) );
                }
                else
                        sprintf( buf, "d=%d/sqrt(%d)", absa - ( Right_Numb - 1 ) + m, absb );
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


