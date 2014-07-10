//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest15.h"
#include "drobi.h"
#include "MGiper.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest15::quest15(FILE* f)
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

quest15::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest15::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  nvar = 1;
  keygen = 0;

  Giper->quest = this;

  Giper->Edit1->Text = IntToStr(amin);
  Giper->Edit2->Text = IntToStr(amax);
  Giper->Edit3->Text = IntToStr(keygen);
  Giper->Edit4->Text = IntToStr(nvar);

  Giper->ShowModal();

  return 0;
}

quest15::Print(TList* plist)
{
        int a, b, i;
        double c;

        drobi d;

        char * buf = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        a = rgen(keygen, 1, amin, amax );
        b = rgen(keygen, 1, amin, amax );

        if( !a )
                a ++;
        if( !b )
                b ++;

        a = abs (a);
        b = abs (b);

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
                sprintf( buf, "String(Выписать каноническое уравнение гиперболы зная её полуоси.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти расстояние между фокусами этой гиперболы.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вычислить эксцентриситет этой гипербоы.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти acимптоты этой гиперболы.)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "a=%d", a );
        plist->Add( strdup(buf) );

        sprintf( buf, "b=%d", b );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        c = sqrt( a*a + b*b );
        //e = c / a;

        sprintf( buf, "String(Искомое уравнение: )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "(x^2)/%d-(y^2)/%d=1", a*a, b*b );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Расстояние между фокусами:)" );
        plist->Add( strdup(buf) );

        if ( (ceil(c)) == c )
                sprintf( buf, "c=%f", c );
        else
                sprintf( buf, "c=sqrt(%d)", a*a + b*b );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Эксцентриситет гиперболы:)" );
        plist->Add( strdup(buf) );

        if ( (ceil(c)) == c )
        {
                d = drobi( (int)c, a );
                sprintf( buf, "e=%s", DrobiToStr( d ) );
                //sprintf( buf, "e=%f", e );
        }
        else
                sprintf( buf, "e=sqrt(%d)/%d", a*a + b*b,a );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Асимптоты гиперболы:)" );
        plist->Add( strdup(buf) );

        d = drobi( b, a );

        /*if ( d.b == 1 )
                sprintf( buf, "y=+-%f*x", d.c );
        else
                sprintf( buf, "y=+-(%d/%d)*x", b, a );*/
        if( d.znak > 0 )
                if( d.c != 1)
                        sprintf( buf, "y=+-(%s)*x", DrobiToStr( d ) );
                else
                        sprintf( buf, "y=+-x" );
        else
                sprintf( buf, "y=+%s*x", DrobiToStr( d ) );
        plist->Add( strdup(buf) );

/*  Graphics::TBitmap* bmv = new Graphics::TBitmap();

  y0 = funk( -100, a, b );

  bmv->Width = 300;
  bmv->Height = 2 * y0 + 20;

  y = funk( -100, a, b);
  bmv->Canvas->MoveTo(0, 100 - y);

  for( i = -100; i <= -a; i ++ )
  {
        y = funk( i, a, b);
        draw(100,y0,i,y,bmv);
  }

  for( i = -a; i >= -100; i -- )
  {
        y = -funk( i, a, b);
        draw(100,y0,i,y,bmv);
  }

  y = funk( 100, a, b);
  bmv->Canvas->MoveTo(200, 100 - y);

  for( i = 100; i >= a; i -- )
  {
        y = funk( i, a, b);
        draw(100,y0,i,y,bmv);
  }

  for( i = a; i <= 100; i ++ )
  {
        y = -funk( i, a, b);
        draw(100,y0,i,y,bmv);
  }

  y = gline( -100, a, b);
  bmv->Canvas->MoveTo(0, y0 - y);
  y = gline(100,a,b);
  draw(100,y0,100,y,bmv);

  y = -gline( -100, a, b);
  bmv->Canvas->MoveTo(0, y0 - y);
  y = -gline(100,a,b);
  draw(100,y0,100,y,bmv);

  bmv->Canvas->MoveTo(100,0);
  bmv->Canvas->LineTo(100,2 * y0);
  bmv->Canvas->MoveTo(0,y0);
  bmv->Canvas->LineTo(200,y0);

  sprintf(buf,"Гипербола ВАРИАНТА %i, решение задачи %i, ключ %i",nvar,nzad,keygen);
  bmv->Canvas->TextOutA(0, 2 * y0, buf);
  bmv->SaveToFile("plane.bmp");
  delete bmv;*/

        keygen = 0;

        delete buf;

        return 0;
}
//---------------------------------------------------------------
/*
void draw(int x0, int y0, int x, int y, Graphics::TBitmap* map)
{
        map->Canvas->LineTo( x0 + x, y0 - y);
}
//---------------------------------------------------------------

double funk( int x, int a, int b)
{
        double y, temp;

        temp = (double)(x * x ) / ( a * a ) - 1;

        y = b * sqrt( temp );

        return y;
}
//----------------------------------------------------------------

double gline(int x, int a, int b)
{
        double y;

        y = (double )x * ((double)b / a);

        return y;
}*/
//----------------------------------------------------------------

quest15::Print(TList* plist, class test &t)
{
        int a, b, i, y;
        int n, Right_Numb;

        double c;

        drobi d;

        char * buf = new char[256];
        char * buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        Right_Numb = random( 5 ) + 1;
        
        srand( keygen );

        a = rgen( keygen, 1, amin, amax );
        b = rgen( keygen, 1, amin, amax );

        if( !a )
                a ++;
        if( !b )
                b ++;

        a = abs( a );
        b = abs( b );

        if( a <= b )
        {
                if( a * a < 5 )
                        Right_Numb = a * a;
        }
        else
        {
                if( b * b < 5 )
                       Right_Numb = b * b;
        }

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Выписать каноническое уравнение гиперболы зная её полуоси.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Найти расстояние между фокусами этой гиперболы.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вычислить эксцентриситет этой гипербоы.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Найти acимптоты этой гиперболы.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "a=%d", a );
        plist->Add( strdup(buf) );

        sprintf( buf, "b=%d", b );
        plist->Add( strdup(buf) );

        for( n = 0; n < 5; n ++ )
        {
                c = sqrt( a * a + b * b - ( Right_Numb - 1 ) + n );

                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Искомое уравнение: )" );
                plist->Add( strdup(buf) );

                /*sprintf( buf, "(x^2)/%d-(y^2)/%d=1", a * a - ( Right_Numb - 1 ) + n, b * b - ( Right_Numb - 1 ) + n );
                plist->Add( strdup(buf) );*/

                if( a * a - ( Right_Numb - 1 ) + n > 1 )
                        sprintf( buf, "(x^2)/%d", a * a - ( Right_Numb - 1 ) + n );
                else
                        sprintf( buf, "x^2" );

                if( b * b - ( Right_Numb - 1 ) + n > 1 )
                        sprintf( buf1, "-(y^2)/%d=1", b * b - ( Right_Numb - 1 ) + n );
                else
                        sprintf( buf1, "-y^2=1" );

                strcat( buf, buf1 );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Расстояние между фокусами:)" );
                plist->Add( strdup(buf) );

                if ( (ceil(c)) == c )
                        sprintf( buf, "c=%f", c );
                else
                        sprintf( buf, "c=sqrt(%d)", a * a + b * b - ( Right_Numb - 1 ) + n );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Эксцентриситет гиперболы:)" );
                plist->Add( strdup(buf) );

                if ( (ceil(c)) == c )
                {
                        d = drobi( (int)c, a );
                        sprintf( buf, "e=%s", DrobiToStr( d ) );
                }
                else
                        sprintf( buf, "e=sqrt(%d)/%d", a * a + b * b - ( Right_Numb - 1 ) + n, a );
                        plist->Add( strdup(buf) );

                sprintf( buf, "String(Асимптоты гиперболы:)" );
                plist->Add( strdup(buf) );

                d = drobi( b - ( Right_Numb - 1 ) + n, a );

                if( d.znak > 0 )
                {
                        if( !d.c )
                                sprintf( buf, "y=0" );
                        else
                        if( d.c != 1)
                                sprintf( buf, "y=+-(%s)*x", DrobiToStr( d ) );
                        else
                                sprintf( buf, "y=+-x" );
                }
                else
                        sprintf( buf, "y=+%s*x", DrobiToStr( d ) );
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


