//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest28.h"
#include "MLinePrizm.h"
#include "drobi.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest28::quest28(FILE* f)
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

quest28::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest28::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  LinePrizm->quest = this;

  LinePrizm->Edit1->Text = IntToStr(amin);
  LinePrizm->Edit2->Text = IntToStr(amax);
  LinePrizm->Edit3->Text = IntToStr(keygen);
  LinePrizm->Edit4->Text = IntToStr(nvar);

  LinePrizm->ShowModal();

  return 0;
}

quest28::Print(TList* plist)
{
        int i;
        int a[3], b[3], c[3], d[3];
        int scal, absa, absb;
        int p[3], q[3];

        char * buf = new char[256];
        char * buf1 = new char[256];

        drobi dr;

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for( i = 0; i < 3; i ++ )
        {
                a[i] = rgen(keygen, 1, amin, amax);
                b[i] = rgen(keygen, 1, amin, amax);
                c[i] = rgen(keygen, 1, amin, amax);
                d[i] = rgen(keygen, 1, amin, amax);

                while( !a[i] )
                        a[i] = rgen(keygen, 1, amin, amax);

                while ( b[i] == a[i] || !b[i])
                        b[i] = rgen(keygen, 1, amin, amax);

                while ( c[i] == b[i] )
                        c[i] = rgen(keygen, 1, amin, amax);

                while ( d[i] == c[i] )
                        d[i] = rgen(keygen, 1, amin, amax);
        }

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );
        }
        else
        {
                sprintf( buf, "String(#)" );
                plist->Add(strdup(buf));
        }

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(Точки A,B,C,D задают треугольную пирамиду.)" );
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

        sprintf( buf, "D!(%d", d[0] );
        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", d[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(Выписать уравнение ребра AB.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Выписать уравнение ребра BC.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти косинус угла между ребрами AB и BC.)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

//Сторона АВ.
        sprintf( buf, "String(Сторона AB: )" );
        plist->Add( strdup(buf) );

        if( -a[0] )
                sprintf( buf, "(x%+d)/%d=", -a[0], b[0] - a[0] );
        else
                sprintf( buf, "x/%d=", b[0] - a[0] );

        if( -a[1] )
                sprintf( buf1, "(y%+d)/%d=", -a[1], b[1] - a[1] );
        else
                sprintf( buf1,"y/%d=", b[1] - a[1] );
        strcat( buf, buf1);

        if( -a[2] )
                sprintf( buf1, "(z%+d)/%d", -a[2], b[2] - a[2] );
        else
                sprintf( buf1, "z/%d", b[2] - a[2] );
        strcat( buf, buf1);
        plist->Add( strdup(buf) );

        /*sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", - a[0] - ( Right_Numb - 1 ) + n, b[0] - a[0] - ( Right_Numb - 1 ) + n, - a[1], b[1] - a[1], - a[2], b[2] - a[2] );
        plist->Add( strdup(buf) );*/

//Сторона ВС.
        sprintf( buf, "String(Сторона BС: )" );
        plist->Add( strdup(buf) );

        if( -b[0] )
                sprintf( buf, "(x%+d)/%d=", -b[0], c[0] - b[0] );
        else
        sprintf( buf, "x/%d=", c[0] - b[0] );

        if( -b[1] )
                sprintf( buf1, "(y%+d)/%d=", -b[1], c[1] - b[1] );
        else
                sprintf( buf1, "y/%d=", c[1] - b[1] );
        strcat( buf, buf1);

        if( -b[2] )
                sprintf( buf1, "(z%+d)/%d", -b[2], c[2] - b[2] );
        else
                sprintf( buf1, "z/%d", c[2] - b[2] );
        strcat( buf, buf1);
        plist->Add( strdup(buf) );

        /*sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", - b[0], c[0] - b[0], - b[1], c[1] - b[1], - b[2], c[2] - b[2] );
        plist->Add( strdup(buf) );*/

//Косинус угла между сторонами.
        for ( i = 0; i < 3; i ++ )
        {
                p[i] = b[i] - a[i];
                q[i] = c[i] - b[i];
        }

        scal = 0;
        absa = 0;
        absb = 0;

        for ( i = 0; i < 3; i ++ )
        {
                scal += p[i] * q[i];
                absa += p[i] * p[i];
                absb += q[i] * q[i];
        }

        sprintf( buf, "cos(phi)=" );

        if ( !scal )
                strcat( buf, "0" );
        else
        if ( ( ceil( sqrt( absa ) ) == sqrt( absa ) ) && ( ceil( sqrt( absb ) ) == sqrt( absb ) ) )
        {
                dr = drobi ( scal, sqrt( absa ) * sqrt( absb ) );

                sprintf( buf1, "%s", DrobiToStr ( dr ) );
                strcat( buf, buf1 );
        }
        else
        if ( ( ceil( sqrt( absa ) ) == sqrt( absa ) ) )
        {
                dr = drobi ( scal, sqrt( absa ) );

                sprintf( buf1, "%s/sqrt(%d)", DrobiToStr ( dr ), absb );
                strcat( buf, buf1 );
        }
        else
        if ( ( ceil( sqrt( absb ) ) == sqrt( absb ) ) )
        {
                dr = drobi ( scal, sqrt( absb ) );

                sprintf( buf1, "%s/sqrt(%d)", DrobiToStr ( dr ), absa );
                strcat( buf, buf1 );
        }
        else
        {
                if ( ceil ( sqrt ( absa * absb ) ) == sqrt ( absa * absb ) )
                {
                        dr = drobi( scal, sqrt (absa * absb ) );
                        sprintf( buf1, "%s", DrobiToStr( dr ) );
                }
                else
                        sprintf( buf1, "%d/(sqrt(%d)*sqrt(%d))=%d/(sqrt(%d*%d))", scal, absa, absb, scal, absa, absb );

                strcat( buf, buf1 );
        }

        //strcat(buf,"");
        plist->Add( strdup(buf) );

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//------------------------------------------------------------------------------

quest28::Print(TList* plist, class test &t)
{
        int i;
        int a[3], b[3], c[3], d[3];
        int n, Right_Numb;

        char * buf = new char[256];
        char * buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        Right_Numb = random( 5 ) + 1;

        srand( keygen );

        for( i = 0; i < 3; i ++ )
        {
                a[i] = rgen(keygen, 1, amin, amax);
                b[i] = rgen(keygen, 1, amin, amax);
                c[i] = rgen(keygen, 1, amin, amax);
                d[i] = rgen(keygen, 1, amin, amax);

                while( !a[i] )
                        a[i] = rgen(keygen, 1, amin, amax);

                while ( b[i] == a[i] || !b[i])
                        b[i] = rgen(keygen, 1, amin, amax);

                while ( c[i] == b[i] )
                        c[i] = rgen(keygen, 1, amin, amax);

                while ( d[i] == c[i] )
                        d[i] = rgen(keygen, 1, amin, amax);
        }

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Точки A,B,C,D задают треугольную пирамиду.)" );
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

        sprintf( buf, "D!(%d", d[0] );
        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", d[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Выписать уравнение ребра AB.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Выписать уравнение ребра BC.)" );
        plist->Add( strdup(buf) );

        for( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                //Сторона АВ.
                sprintf( buf, "String(Сторона AB: )" );
                plist->Add( strdup(buf) );

                if( -a[0] - ( Right_Numb - 1 ) + n )
                        sprintf( buf, "(x%+d)/%d=", -a[0] - ( Right_Numb - 1 ) + n, b[0] - a[0] );
                else
                        sprintf( buf, "x/%d=", b[0] - a[0] );

                if( -a[1] - ( Right_Numb - 1 ) + n )
                        sprintf( buf1, "(y%+d)/%d=", -a[1] - ( Right_Numb - 1 ) + n, b[1] - a[1] );
                else
                        sprintf( buf1, "y/%d=", b[1] - a[1] );
                strcat( buf, buf1);

                if( -a[2] - ( Right_Numb - 1 ) + n )
                        sprintf( buf1, "(z%+d)/%d", -a[2] - ( Right_Numb - 1 ) + n, b[2] - a[2] );
                else
                        sprintf( buf1, "z/%d", b[2] - a[2] );
                strcat( buf, buf1);
                plist->Add( strdup(buf) );

                /*sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", - a[0] - ( Right_Numb - 1 ) + n, b[0] - a[0] - ( Right_Numb - 1 ) + n, - a[1], b[1] - a[1], - a[2], b[2] - a[2] );
                plist->Add( strdup(buf) );*/

                //Сторона ВС.
                sprintf( buf, "String(Сторона BС: )" );
                plist->Add( strdup(buf) );

                if( -b[0] - ( Right_Numb - 1 ) + n )
                        sprintf( buf, "(x%+d)/%d=", -b[0] - ( Right_Numb - 1 ) + n, c[0] - b[0] );
                else
                        sprintf( buf, "x/%d=", c[0] - b[0] );

                if( -b[1] - ( Right_Numb - 1 ) + n )
                        sprintf( buf1, "(y%+d)/%d=", -b[1] - ( Right_Numb - 1 ) + n, c[1] - b[1] );
                else
                        sprintf( buf1, "y/%d=", c[1] - b[1] );
                strcat( buf, buf1);

                if( -b[2] - ( Right_Numb - 1 ) + n )
                        sprintf( buf1, "(z%+d)/%d", -b[2] - ( Right_Numb - 1 ) + n, c[2] - b[2] );
                else
                        sprintf( buf1, "z/%d", c[2] - b[2] );
                strcat( buf, buf1);
                plist->Add( strdup(buf) );

                /*sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", - b[0], c[0] - b[0], - b[1], c[1] - b[1], - b[2], c[2] - b[2] );
                plist->Add( strdup(buf) );*/
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


