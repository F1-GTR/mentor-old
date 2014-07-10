//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest25.h"
#include "MPr.h"
#include "drobi.h"
#include "determ.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest25::quest25(FILE* f)
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

quest25::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest25::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  Pr->quest = this;

  Pr->Edit1->Text = IntToStr(amin);
  Pr->Edit2->Text = IntToStr(amax);
  Pr->Edit3->Text = IntToStr(keygen);
  Pr->Edit4->Text = IntToStr(nvar);

  Pr->ShowModal();

  return 0;
}

quest25::Print(TList* plist)
{
        int i, j, k;
        int a[3], b[3], c[3], d[3];
        int plane[4], plane1[4], vert[3][10], vert_t[2][10];
        int scal, absa, absb;

        char * buf = new char[256];
        char * buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for( i = 0; i < 3; i ++ )
        {
                a[i] = rgen(keygen, 1, amin, amax);

                b[i] = rgen(keygen, 1, amin, amax);
                while ( b[i] == a[i] )
                        b[i] = rgen(keygen, 1, amin, amax);

                c[i] = rgen(keygen, 1, amin, amax);
                while ( c[i] == b[i] || c[i] == a[i] )
                        c[i] = rgen(keygen, 1, amin, amax);

                d[i] = rgen(keygen, 1, amin, amax);
                while ( d[i] == c[i] || d[i] == b[i] || d[i] == a[i] )
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
                plist->Add( strdup(buf) );
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

        sprintf( buf, "C!(%d",c[0] );
        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d",c[i]);
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "D!(%d", d[0] );
        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d",d[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(Выписать уравнение граней ABC, BCD.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти косинус угла между этими гранями.)" );
                plist->Add( strdup(buf) );
        }

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
                        if ( j != i)
                        {
                                vert_t[0][k] = vert[1][j];
                                vert_t[1][k] = vert[2][j];
                                k ++;
                        }
                }

                plane[i] = pow(-1,i) * determ( 2, vert_t );
        }

        plane[3] = - determ ( 3, vert );

        for ( i = 0; i < 3; i ++ )
        {
                vert[0][i] = c[i];
                vert[1][i] = b[i] - c[i];
                vert[2][i] = d[i] - c[i];
        }

        for ( i = 0; i < 3; i ++ )
        {
                k = 0;

                for ( j = 0; j < 3; j ++ )
                {
                        if ( j != i)
                        {
                                vert_t[0][k] = vert[1][j];
                                vert_t[1][k] = vert[2][j];
                                k ++;
                        }
                }

                plane1[i] = pow(-1,i) * determ( 2, vert_t );
        }

        plane1[3] = - determ ( 3, vert );

        sprintf( buf, "String(Искомые грани: )" );
        plist->Add( strdup(buf) );

// Грань АВС.
        sprintf( buf, "String(Грань ABC: )" );
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
                        if ( b[j])
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

        strcpy( buf, "" );

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

// Грань BCD
        sprintf( buf, "String(Грань BCD: )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "|Matrix(3,3" );

        for ( i = 0; i < 3; i ++ )
        for ( j = 0; j < 3; j ++ )
        {
                switch ( i )
                {
                        case 0:

                        sprintf( buf1, ",%d", b[j] - c[j] );

                        break;

                        case 1:

                        sprintf( buf1, ",%d", d[j] - c[j] );

                        break;

                        case 2:

                        if ( j == 0 )
                        if ( c[j])
                                sprintf( buf1, ",x%+d", - c[j] );
                        else
                                sprintf( buf1, ",x" );
                        else
                        if ( j == 1 )
                        if ( c[j] )
                                sprintf( buf1, ",y%+d", - c[j] );
                        else
                                sprintf( buf1, ",y" );
                        else
                        if ( c[j] )
                                sprintf( buf1, ",z%+d", - c[j] );
                        else
                                sprintf( buf1, ",z" );
                }

                strcat( buf, buf1 );
        }

        strcat( buf, ")|=0" );
        plist->Add( strdup(buf) );

        strcpy ( buf, "" );

        if ( plane1[0] )
        {
                if ( plane1[0] == 1 )
                        sprintf( buf1, "x" );
                else
                if ( plane1[0] == -1 )
                        sprintf( buf1, "-x" );
                else
                        sprintf( buf1, "%d*x", plane1[0] );

                strcat ( buf, buf1 );
        }

        if ( plane1[1] )
        {
                if ( plane1[1] == 1 )
                        sprintf( buf1, "+y" );
                else
                if ( plane1[1] == -1 )
                        sprintf( buf1, "-y" );
                else
                        sprintf( buf1, "%+d*y", plane1[1] );

                strcat ( buf, buf1 );
        }

        if ( plane1[2] )
        {
                if ( plane1[2] == 1 )
                        sprintf( buf1, "+z" );
                else
                if ( plane1[2] == -1 )
                        sprintf( buf1, "-z" );
                else
                        sprintf( buf1, "%+d*z", plane1[2] );

                strcat ( buf, buf1 );
        }

        if ( plane1[3] )
        {
                sprintf( buf1, "%+d", plane1[3] );
                strcat( buf, buf1 );
        }

        if ( plane1 [0] || plane1[1] || plane1[2] || plane1[3] )
        {
                strcat(buf,"=0");
                plist->Add( strdup(buf) );
        }

//Косинус угла между гранями.

        sprintf( buf, "cos(alpha)=" );

        scal = 0;
        absa = 0;
        absb = 0;

        for ( i = 0; i < 3; i ++ )
        {
                scal += plane[i] * plane1[i];
                absa += plane[i] * plane[i];
                absb += plane1[i] * plane1[i];
        }

        drobi dr;

        if ( (ceil(sqrt(absa)) == sqrt(absa)) && (ceil(sqrt(absb)) == sqrt(absb)) )
        {
        //temp = scal / ( sqrt(absa) * sqrt( absb ) );
                dr = drobi ( scal, sqrt(absa) * sqrt( absb ) );

                sprintf(buf1,"%s", DrobiToStr ( dr ) );
                strcat(buf,buf1);
        }
        else
        if ( (ceil(sqrt(absa)) == sqrt(absa)) )
        {
        //temp = scal / ( sqrt(absa) );

                dr = drobi ( scal, sqrt(absa) );
                sprintf(buf1,"%s/sqrt(%d)", DrobiToStr ( dr ), absb);
                strcat(buf,buf1);
        }
        else
        if ( (ceil(sqrt(absb)) == sqrt(absb)) )
        {
        //temp = scal / ( sqrt(absb) );

                dr = drobi ( scal, sqrt(absa) );
                sprintf(buf1,"%s/sqrt(%d)", DrobiToStr ( dr ), absa);
                strcat(buf,buf1);
        }
        else
        {
                if ( ceil ( sqrt ( absa * absb ) ) == sqrt ( absa * absb ) )
                {
                        dr = drobi (scal, sqrt (absa * absb ) );
                        sprintf(buf1,"%s", DrobiToStr( dr ) );
                }
                else
                        sprintf(buf1,"%d/(sqrt(%d)*sqrt(%d))=%d/(sqrt(%d*%d))",scal,absa,absb,scal,absa,absb);
                strcat(buf,buf1);
        }

        strcat( buf, "" );
        plist->Add( strdup(buf) );

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//------------------------------------------------------------------------------

quest25::Print(TList* plist, class test &t)
{
        int i, j, k;
        int a[3], b[3], c[3], d[3];
        int plane[4], plane1[4], vert[3][10], vert_t[2][10];
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
                while ( b[i] == a[i] )
                        b[i] = rgen(keygen, 1, amin, amax);

                c[i] = rgen(keygen, 1, amin, amax);
                while ( c[i] == b[i] || c[i] == a[i] )
                        c[i] = rgen(keygen, 1, amin, amax);

                d[i] = rgen(keygen, 1, amin, amax);
                while ( d[i] == c[i] || d[i] == b[i] || d[i] == a[i] )
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

        sprintf( buf, "C!(%d",c[0] );
        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d",c[i]);
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "D!(%d", d[0] );
        for ( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d",d[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Выписать уравнение граней ABC, BCD.)" );
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
                        if ( j != i)
                        {
                                vert_t[0][k] = vert[1][j];
                                vert_t[1][k] = vert[2][j];
                                k ++;
                        }
                }

                plane[i] = pow(-1,i) * determ( 2, vert_t );
        }

        plane[3] = - determ ( 3, vert );

        for ( i = 0; i < 3; i ++ )
        {
                vert[0][i] = c[i];
                vert[1][i] = b[i] - c[i];
                vert[2][i] = d[i] - c[i];
        }

        for ( i = 0; i < 3; i ++ )
        {
                k = 0;

                for ( j = 0; j < 3; j ++ )
                {
                        if ( j != i)
                        {
                                vert_t[0][k] = vert[1][j];
                                vert_t[1][k] = vert[2][j];
                                k ++;
                        }
                }

                plane1[i] = pow(-1,i) * determ( 2, vert_t );
        }

        plane1[3] = - determ ( 3, vert );

        for( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Грань ABC: )" );
                plist->Add( strdup(buf) );

                strcpy( buf, "" );

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

                if ( plane [0] || plane[1] || plane[2] || plane[3] )
                {
                        strcat( buf, "=0" );
                        plist->Add( strdup(buf) );
                }

                sprintf( buf, "String(Грань BCD: )" );
                plist->Add( strdup(buf) );

                strcpy ( buf, "" );

                if ( plane1[0] - ( Right_Numb - 1 ) + n )
                {
                        if ( plane1[0] - ( Right_Numb - 1 ) + n == 1 )
                                sprintf( buf1, "x" );
                        else
                        if ( plane1[0] - ( Right_Numb - 1 ) + n == -1 )
                                sprintf( buf1, "-x" );
                        else
                                sprintf( buf1, "%d*x", plane1[0] - ( Right_Numb - 1 ) + n );

                        strcat ( buf, buf1 );
                }

                if ( plane1[1] - ( Right_Numb - 1 ) + n )
                {
                        if ( plane1[1] - ( Right_Numb - 1 ) + n == 1 )
                                sprintf( buf1, "+y" );
                        else
                        if ( plane1[1] - ( Right_Numb - 1 ) + n == -1 )
                                sprintf( buf1, "-y" );
                        else
                                sprintf( buf1, "%+d*y", plane1[1] - ( Right_Numb - 1 ) + n );

                        strcat ( buf, buf1 );
                }

                if ( plane1[2] - ( Right_Numb - 1 ) + n )
                {
                        if ( plane1[2] - ( Right_Numb - 1 ) + n == 1 )
                                sprintf( buf1, "+z" );
                        else
                        if ( plane1[2] - ( Right_Numb - 1 ) + n == -1 )
                                sprintf( buf1, "-z" );
                        else
                                sprintf( buf1, "%+d*z", plane1[2] - ( Right_Numb - 1 ) + n );

                        strcat ( buf, buf1 );
                }

                if ( plane1[3] - ( Right_Numb - 1 ) + n )
                {
                        sprintf( buf1, "%+d", plane1[3] - ( Right_Numb - 1 ) + n );
                        strcat( buf, buf1 );
                }

                if ( plane1 [0] || plane1[1] || plane1[2] || plane1[3] )
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


