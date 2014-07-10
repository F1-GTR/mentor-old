//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest29.h"
#include "MLineCmp.h"
#include "drobi.h"
#include "determ.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest29::quest29(FILE* f)
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

quest29::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest29::Edit()
{
  sscanf(strpar2,"%i%i%i", &amin, &amax, &TypeQ );

  keygen = 0;
  nvar = 1;

  LineCmp->quest = this;

  LineCmp->Edit1->Text = IntToStr(amin);
  LineCmp->Edit2->Text = IntToStr(amax);
  LineCmp->Edit3->Text = IntToStr(keygen);
  LineCmp->Edit4->Text = IntToStr(nvar);
  LineCmp->ComboBox1->ItemIndex = TypeQ;

  LineCmp->ShowModal();

  return 0;
}

quest29::Print(TList* plist)
{
        int i, j, k, mn;
        int p[3], p2[3], m[3], m2[3], b[3], c[3];
        int scal, absp, absp2, absc;
        int plane[4], matr[2][10];

        char * buf = new char[256];
        char * buf1 = new char[256];

        drobi d;

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for( i = 0; i < 3; i ++ )
        {
                p[i] = rgen( keygen, 1, amin, amax );
                p2[i] = rgen( keygen, 1, amin, amax );
                m[i] = rgen( keygen, 1, amin, amax );
                m2[i] = rgen( keygen, 1, amin, amax );

                if( !p[i] )
                        p[i] ++;
        }

        switch ( TypeQ )
        {
                case 0:
                        //mn = rgen( keygen, 1, amin, amax );
                        mn = random( 3 ) + 2;

                        for ( i = 0; i < 3; i++ )
                                p2[i] = p[i] * mn;
                break;
                case 1:
                        for ( i = 0; i < 3; i ++ )
                                m2[i] = 2 * p[i] + m[i];
                break;
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

        sprintf( buf, "String( Прямая a:)" );
        plist->Add( strdup(buf) );

        if( -m[0] )
                sprintf( buf, "(x%+d)/%d=", -m[0], p[0] );
        else
                sprintf( buf, "x/%d=", p[0] );

        if( -m[1] )
                sprintf( buf1, "(y%+d)/%d=", -m[1], p[1] );
        else
                sprintf( buf1,"y/%d=", p[1] );
        strcat( buf, buf1);

        if( -m[2] )
                sprintf( buf1, "(z%+d)/%d", -m[2], p[2] );
        else
                sprintf( buf1, "z/%d", p[2] );
        strcat( buf, buf1);
        plist->Add( strdup(buf) );

        /*sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", -m[0], p[0], -m[1], p[1], -m[2], p[2] );
        plist->Add( strdup(buf) );*/

        sprintf( buf, "String( Прямая b:)" );
        plist->Add( strdup(buf) );

        if( -m2[0] )
                sprintf( buf, "(x%+d)/%d=", -m2[0], p2[0] );
        else
                sprintf( buf, "x/%d=", p2[0] );

        if( -m2[1] )
                sprintf( buf1, "(y%+d)/%d=", -m2[1], p2[1] );
        else
                sprintf( buf1,"y/%d=", p2[1] );
        strcat( buf, buf1);

        if( -m2[2] )
                sprintf( buf1, "(z%+d)/%d", -m2[2], p2[2] );
        else
                sprintf( buf1, "z/%d", p2[2] );
        strcat( buf, buf1);
        plist->Add( strdup(buf) );

        /*sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", -m2[0], p2[0], -m2[1], p2[1], -m2[2], p2[2] );
        plist->Add( strdup(buf) );*/

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(Исследовать взаимное расположение прямых а и b.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Если прямые пересекаются, то найти угол между ними,)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(составить уравнение плоскости проходящей через них.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Если прямые параллельны, то найти расстояние между ними,)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(составить уравнение плоскости проходящей через них.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Если прямые скрещивающиеся, то найти расстояние между ними.)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        switch ( TypeQ )
        {
                case 0:
                        sprintf( buf, "String(Прямые параллельны.)" );
                        plist->Add( strdup(buf) );

                        for ( i = 0; i < 3; i++ )
                                b[i] = m2[i] - m[i];

                        for (i = 0; i < 3; i ++)
                        {
                                k = 0;

                                for (j = 0; j < 3; j ++)
                                {
                                        if ( j != i)
                                        {
                                                matr[0][k] = p[j];
                                                matr[1][k] = b[j];
                                                k ++;
                                        }
                                }

                                c[i] = pow ( -1, i ) * determ( 2, matr );
                        }

                        absc = 0;

                        for ( i = 0; i < 3; i ++)
                                absc += c[i] * c[i];

                        absp = 0;

                        for ( i = 0; i < 3; i ++)
                                absp += p[i] * p[i];

                        if ( !absc )
                                sprintf( buf, "d=0" );
                        else
                        if ( ( ceil( sqrt( absc ) ) ) == ( sqrt( absc ) ) && ( ceil( sqrt( absp ) ) ) == ( sqrt( absp ) ) )
                        {
                                d = drobi( sqrt(absc), sqrt(absp) );
                                //sprintf( buf, "d=%d/%d", d.a, d.b );
                                sprintf( buf, "d=%s", DrobiToStr( d ) );
                        }
                        else
                        if ( ( ceil( sqrt( absc ) ) ) == ( sqrt( absc ) ) )
                                sprintf( buf, "d=%f/sqrt(%d)", sqrt( absc ), absp );
                        else
                        if ( ( ceil( sqrt( absp ) ) ) == ( sqrt( absp ) ) )
                                sprintf( buf, "d=sqrt(%d)/%f", absc, sqrt( absp ) );
                        else
                                sprintf( buf, "d=sqrt(%d)/sqrt(%d)", absc, absp );

                        plist->Add( strdup(buf) );

                        for( i = 0; i < 3; i++ )
                                b[i] = m2[i] - m[i];

                        for (i = 0; i < 3; i ++ )
                        {
                                k = 0;

                                for (j = 0; j < 3; j ++)
                                {
                                        if ( j != i)
                                        {
                                                matr[0][k] = p[j];
                                                matr[1][k] = b[j];
                                                k ++;
                                        }
                                }

                                c[i] = pow ( -1, i ) * determ(2,matr);
                        }

                        for ( i = 0; i < 3; i ++ )
                                plane[i] = c[i];

                        plane[3] = 0;

                        for ( i = 0; i < 3; i ++ )
                                plane[3] -= plane[i] * m[i];

                        if( abs( plane[0] ) > 1 )
                                sprintf( buf, "%d*x", plane[0] );
                        else
                        if( plane[0] > 0 )
                                sprintf( buf, "x" );
                        else
                        if( plane[0] < 0 )
                                sprintf( buf, "-x" );
                        else
                                sprintf( buf, "" );

                        if ( abs( plane[1] ) > 1 )
                                sprintf( buf1, "%+d*y", plane[1] );
                        else
                        if( plane[1] > 0 )
                                sprintf( buf1, "+y" );
                        else
                        if( plane[1] < 0 )
                                sprintf( buf1, "-y" );
                        else
                                sprintf( buf1, "" );
                        strcat( buf, buf1 );

                        if ( abs( plane[2] ) > 1 )
                                sprintf( buf1, "%+d*z", plane[2] );
                        else
                        if( plane[2] > 0 )
                                sprintf( buf1, "+z" );
                        else
                        if( plane[2] < 0 )
                                sprintf( buf1, "-z" );
                        else
                                sprintf( buf1, "" );
                        strcat( buf, buf1 );

                        if ( plane[3] )
                                sprintf( buf1, "%+d", plane[3] );
                        else
                                sprintf( buf1, "" );
                        strcat( buf, buf1 );

                        if( plane[0] || plane[1] || plane[2] || plane[3] )
                                strcat( buf, "=0" );
                        plist->Add( strdup(buf) );
                break;
                case 1:
                        sprintf( buf, "String(Прямые пересекаются.)" );
                        plist->Add( strdup(buf) );

                        for ( i = 0; i < 3; i ++ )
                        {
                                k = 0;

                                for ( j = 0; j < 3; j ++ )
                                {
                                        if ( j != i)
                                        {
                                                matr[0][k] = p[j];
                                                matr[1][k] = p2[j];
                                                k ++;
                                        }
                                }

                                c[i] = pow ( -1, i ) * determ( 2,matr );
                        }

                        for ( i = 0; i < 3; i ++ )
                                plane[i] = c[i];

                        plane[3] = 0;

                        for ( i = 0; i < 3; i ++ )
                                plane[3] -= plane[i] * m[i];

                        if( abs( plane[0] ) > 1 )
                                sprintf( buf, "%d*x", plane[0] );
                        else
                        if( plane[0] > 0 )
                                sprintf( buf, "x" );
                        else
                        if( plane[0] < 0 )
                                sprintf( buf, "-x" );
                        else
                                sprintf( buf, "" );

                        if ( abs( plane[1] ) > 1 )
                                sprintf( buf1, "%+d*y", plane[1] );
                        else
                        if( plane[1] > 0 )
                                sprintf( buf1, "+y" );
                        else
                        if( plane[1] < 0 )
                                sprintf( buf1, "-y" );
                        else
                                sprintf( buf1, "" );
                        strcat( buf, buf1 );

                        if ( abs( plane[2] ) > 1 )
                                sprintf( buf1, "%+d*z", plane[2] );
                        else
                        if( plane[2] > 0 )
                                sprintf( buf1, "+z" );
                        else
                        if( plane[2] < 0 )
                                sprintf( buf1, "-z" );
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

                        scal = 0;
                        absp = 0;
                        absp2 = 0;

                        for ( i = 0; i < 3; i ++ )
                        {
                                scal += p[i] * p2[i];
                                absp += p[i] * p[i];
                                absp2 += p2[i] * p2[i];
                        }

                        sprintf( buf, "cos(phi)=" );

                        if( !scal )
                                strcat( buf, "0" );
                        else
                        if ( ( ceil( sqrt( absp ) ) == sqrt( absp ) ) && ( ceil( sqrt( absp2 ) ) == sqrt( absp2 ) ) )
                        {
                                d = drobi ( scal, sqrt( absp ) * sqrt( absp2 ) );

                                sprintf( buf1, "%s", DrobiToStr ( d ) );
                                strcat( buf, buf1 );
                        }
                        else
                        if ( ( ceil( sqrt( absp ) ) == sqrt( absp ) ) )
                        {
                                d = drobi ( scal, sqrt(absp) );

                                sprintf( buf1, "%s/sqrt(%d)", DrobiToStr ( d ), absp2 );
                                strcat( buf, buf1 );
                        }
                        else
                        if ( ( ceil( sqrt( absp2 ) ) == sqrt( absp2 ) ) )
                        {
                                d = drobi ( scal, sqrt(absp) );

                                sprintf( buf1, "%s/sqrt(%d)", DrobiToStr ( d ), absp );
                                strcat( buf, buf1 );
                        }
                        else
                        {
                                if ( ceil ( sqrt ( absp * absp2 ) ) == sqrt ( absp * absp2 ) )
                                {
                                        d = drobi (scal, sqrt (absp * absp2 ) );
                                        sprintf( buf1, "%s", DrobiToStr( d ) );
                                }
                                else
                                        sprintf( buf1, "%d/(sqrt(%d)*sqrt(%d))=%d/(sqrt(%d*%d))", scal, absp, absp2, scal, absp, absp2 );

                                strcat( buf, buf1 );
                        }

                        plist->Add( strdup(buf) );
                break;
                case 2:
                        sprintf( buf, "String(Прямые скрещиваются.)" );
                        plist->Add( strdup(buf) );

                        for ( i = 0; i < 3; i ++ )
                        {
                                k = 0;

                                for ( j = 0; j < 3; j ++ )
                                {
                                        if ( j != i)
                                        {
                                                matr[0][k] = p[j];
                                                matr[1][k] = p2[j];
                                                k ++;
                                        }
                                }

                                c[i] = pow ( -1, i ) * determ(2,matr);
                        }

                        for ( i = 0; i < 3; i ++ )
                                plane[i] = c[i];

                        plane[3] = 0;

                        for ( i = 0; i < 3; i ++ )
                                plane[3] -= plane[i] * m[i];

                        absp = 0;

                        for ( i = 0; i < 3; i ++)
                                absp += plane[i] * m2[i];

                        absp -= plane[3];

                        absp = fabs( absp );

                        absp2 = 0;

                        for ( i = 0; i < 3; i ++)
                                absp2 += plane[i] * plane[i];

                        if ( !absp )
                                sprintf( buf, "d=0" );
                        else
                        if ( ( ceil( sqrt( absp ) ) ) == ( sqrt( absp ) ) )
                        {
                                d = drobi ( absp, absp2 );
                                //sprintf( buf, "d=%d/%d", d.a, d.b );
                                sprintf( buf, "d=%s", DrobiToStr( d ) );
                        }
                        else
                                sprintf( buf, "d=%d/sqrt(%d)", absp, absp2 );

                        plist->Add( strdup(buf) );
                        /*for ( i = 0; i < 3; i++ )
                                b[i] = m2[i] - m[i];

                        for (i = 0; i < 3; i ++)
                        {
                                k = 0;

                                for (j = 0; j < 3; j ++)
                                {
                                        if ( j != i)
                                        {
                                                matr[0][k] = p[j];
                                                matr[1][k] = b[j];
                                                k ++;
                                        }
                                }

                                c[i] = pow ( -1, i ) * determ(2,matr);
                        }

                        absc = 0;

                        for ( i = 0; i < 3; i ++)
                                absc += c[i] * c[i];

                        absp = 0;

                        for ( i = 0; i < 3; i ++)
                                absp += p[i] * p[i];

                        if ( !absc )
                                sprintf(buf,"d=0");
                        else
                        if ( (ceil(sqrt(absc))) == (sqrt(absc)) && (ceil(sqrt(absp))) == (sqrt(absp)))
                        {
                                d = drobi( sqrt(absc), sqrt(absp) );
                                sprintf(buf,"d=%d/%d", d.a, d.b );
                        }
                        else
                        if ( (ceil(sqrt(absc))) == (sqrt(absc)))
                                sprintf(buf,"d=%f/sqrt(%d)", sqrt(absc), absp );
                        else
                        if ( (ceil(sqrt(absp))) == (sqrt(absp)))
                                sprintf(buf,"d=sqrt(%d)/%f", absc, sqrt(absp) );
                        else
                                sprintf(buf,"d=sqrt(%d)/sqrt(%d)", absc, absp );

                        plist->Add(strdup(buf));*/
                break;
          }

          keygen = 0;

          delete buf;
          delete buf1;

          return 0;
}
//------------------------------------------------------------------------------

quest29::Print(TList* plist, class test &t)
{
        int i, j, k, mn;
        int p[3], p2[3];
        int m[3], m2[3];
        int b[3], c[3];
        int plane[4], matr[2][10];
        int Right_Numb;

        char * buf = new char[256];
        char * buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        Right_Numb = random( 3 ) + 1;

        srand( keygen );

        for( i = 0; i < 3; i ++ )
        {
                p[i] = rgen( keygen, 1, amin, amax );
                p2[i] = rgen( keygen, 1, amin, amax );
                m[i] = rgen( keygen, 1, amin, amax );
                m2[i] = rgen( keygen, 1, amin, amax );

                if( !p[i] )
                        p[i] ++;
        }

        switch ( Right_Numb - 1 )
        {
                case 0:
                        //mn = rgen( keygen, 1, amin, amax );
                        mn = random( 3 ) + 2;

                        for ( i = 0; i < 3; i++ )
                                p2[i] = p[i] * mn;
                break;
                case 1:
                        for ( i = 0; i < 3; i ++ )
                                m2[i] = 2 * p[i] + m[i];
                break;
        }

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Прямая a:)" );
        plist->Add( strdup(buf) );

        if( -m[0] )
                sprintf( buf, "(x%+d)/%d=", -m[0], p[0] );
        else
                sprintf( buf, "x/%d=", p[0] );

        if( -m[1] )
                sprintf( buf1, "(y%+d)/%d=", -m[1], p[1] );
        else
                sprintf( buf1,"y/%d=", p[1] );
        strcat( buf, buf1);

        if( -m[2] )
                sprintf( buf1, "(z%+d)/%d", -m[2], p[2] );
        else
                sprintf( buf1, "z/%d", p[2] );
        strcat( buf, buf1);
        plist->Add( strdup(buf) );

        /*sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", -m[0], p[0], -m[1], p[1], -m[2], p[2] );
        plist->Add( strdup(buf) );*/

        sprintf( buf, "String( Прямая b:)" );
        plist->Add( strdup(buf) );

        if( -m2[0] )
                sprintf( buf, "(x%+d)/%d=", -m2[0], p2[0] );
        else
                sprintf( buf, "x/%d=", p2[0] );

        if( -m2[1] )
                sprintf( buf1, "(y%+d)/%d=", -m2[1], p2[1] );
        else
                sprintf( buf1,"y/%d=", p2[1] );
        strcat( buf, buf1);

        if( -m2[2] )
                sprintf( buf1, "(z%+d)/%d", -m2[2], p2[2] );
        else
                sprintf( buf1, "z/%d", p2[2] );
        strcat( buf, buf1);
        plist->Add( strdup(buf) );

        /*sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", -m2[0], p2[0], -m2[1], p2[1], -m2[2], p2[2] );
        plist->Add( strdup(buf) );*/

        sprintf( buf, "String(Исследовать взаимное расположение прямых а и b.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Вариант a):\")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Прямые параллельны.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Вариант b):\")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Прямые пересекаются.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Вариант с):\")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Прямые скрещиваются.)" );
        plist->Add( strdup(buf) );

        /*sprintf(buf,"String(@Часть преподавателя )");
        plist->Add(strdup(buf));

        sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add(strdup(buf));

        sprintf(buf,"String( Правильный ответ - %c)", 'a' + Right_Numb - 1 );
        plist->Add(strdup(buf));*/

        t.pr_tst = 1;
        t.ch_ask = 3;
        t.right_ask = Right_Numb;
        t.msg = "Тест успешно сгенерирован.";

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//-----------------------------------------------------------


