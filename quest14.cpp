//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest14.h"
#include "drobi.h"
#include "MElips.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest14::quest14(FILE* f)
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

quest14::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest14::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  Elips->quest = this;

  Elips->Edit1->Text = IntToStr(amin);
  Elips->Edit2->Text = IntToStr(amax);
  Elips->Edit3->Text = IntToStr(keygen);
  Elips->Edit4->Text = IntToStr(nvar);

  Elips->ShowModal();

  return 0;
}

quest14::Print(TList* plist)
{
        int a, b;
        double c;

        char * buf = new char[256];

        drobi d;

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        a = rgen( keygen, 1, amin, amax );
        b = rgen( keygen, 1, amin, amax );

        if( !a )
                a ++;
        if( !b )
                b ++;

        a = abs (a);
        b = abs (b);

        if ( b > a )
        {
                c = a;
                a = b;
                b = c;
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
                sprintf( buf, "String(Выписать каноническое уравнение эллипса зная его полуоси.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти расстояние между фокусами этого эллипса.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вычислить эксцентриситет этого эллипса.)" );
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

        c = sqrt( a*a - b*b );
        //e = c / a;

        sprintf( buf, "String(Искомое уравнение: )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "(x^2)/%d+(y^2)/%d=1", a*a, b*b );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Расстояние между фокусами:)" );
        plist->Add( strdup(buf) );

        if ( (ceil(c)) == c )
                sprintf( buf, "c=%f", c );
        else
                sprintf( buf, "c=sqrt(%d)", a*a - b*b );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Эксцентриситет эллипса:)" );
        plist->Add( strdup(buf) );

        if ( ( ceil( c ) ) == c )
        {
                d = drobi( (int)c, a );
                sprintf( buf, "e=%s", DrobiToStr( d ) );
                //sprintf( buf, "e=%f", e );
        }
        else
                sprintf( buf, "e=sqrt(%d)/%d", a * a - b * b, a );
        plist->Add( strdup(buf) );

        /*Graphics::TBitmap* bmv = new Graphics::TBitmap();
        bmv->Width = 20 * a + 100;
        bmv->Height = 20 * b + 30;
        bmv->Canvas->Rectangle( 0, 0, 20 * a, 20 * b);
        bmv->Canvas->MoveTo( 10 * a, 10 * b );
        bmv->Canvas->Ellipse( 0, 0, 20*a, 20*b);
        bmv->Canvas->MoveTo( 20 * a , 10 * b );
        bmv->Canvas->LineTo( 0, 10 * b );
        bmv->Canvas->MoveTo( 10 * a , 20 * b );
        bmv->Canvas->LineTo( 10 * a, 0 );
        bmv->Canvas->TextOutA(20 * a + 1, 10 * b, "a");
        bmv->Canvas->TextOutA(10 * a + 1, 1, "b");
        sprintf(buf,"(-%d,%d)",a,b);
        bmv->Canvas->TextOutA(1, 1, buf);
        sprintf(buf,"(%d,-%d)",a,b);
        bmv->Canvas->TextOutA(20 * a, 20 * b - 12, buf);
        sprintf(buf,"Элипс ВАРИАНТА %i, решение задачи %i, ключ %i",nvar,nzad,keygen);
        bmv->Canvas->TextOutA(0, 20 * b + 1, buf);
        bmv->SaveToFile("plane.bmp");
        delete bmv;*/

        keygen = 0;

        delete buf;

        return 0;
}
//------------------------------------------------------------------------------

quest14::Print(TList* plist, class test &t)
{
        int a, b;
        double c;
        int n, Right_Numb;

        char * buf = new char[256];

        drobi d;

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

        if ( b > a )
        {
                c = a;
                a = b;
                b = c;
        }

        if( b * b < 5 )
                Right_Numb = b * b;

        if( a * a - b * b < 5 )
                n = a * a - b * b;

        if( n < Right_Numb )
                Right_Numb = n;

        if( !Right_Numb )
                Right_Numb ++;

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Выписать каноническое уравнение эллипса зная его полуоси.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Найти расстояние между фокусами этого эллипса.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вычислить эксцентриситет этого эллипса.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "a=%d", a );
        plist->Add( strdup(buf) );

        sprintf( buf, "b=%d", b );
        plist->Add( strdup(buf) );

        for( n = 0; n < 5; n ++ )
        {
                c = sqrt( a * a - b * b - ( Right_Numb - 1 ) + n );
                //e = c / a;

                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Искомое уравнение: )" );
                plist->Add( strdup(buf) );

                /*sprintf( buf, "(x^2)/%d+(y^2)/%d=1", a * a - ( Right_Numb - 1 ) + n, b * b - ( Right_Numb - 1 ) + n );
                plist->Add( strdup(buf) );*/
                if( b * b - ( Right_Numb - 1 ) + n > 1 )
                        sprintf( buf, "(x^2)/%d+(y^2)/%d=1", a * a - ( Right_Numb - 1 ) + n, b * b - ( Right_Numb - 1 ) + n );
                else
                        sprintf( buf, "(x^2)/%d+y^2=1", a * a - ( Right_Numb - 1 ) + n );

                plist->Add( strdup(buf) );

                sprintf( buf, "String(Расстояние между фокусами:)" );
                plist->Add( strdup(buf) );

                if ( ( ceil( c ) ) == c )
                        sprintf( buf, "c=%f", c );
                else
                        sprintf( buf, "c=sqrt(%d)", a * a - b * b - ( Right_Numb - 1 ) + n  );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Эксцентриситет эллипса:)" );
                plist->Add( strdup(buf) );

                if ( ( ceil( c ) ) == c )
                {
                        d = drobi( (int)c, a );
                        sprintf( buf, "e=%s", DrobiToStr( d ) );
                }
                else
                        sprintf( buf, "e=sqrt(%d)/%d", a * a - b * b - ( Right_Numb - 1 ) + n, a );
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

        return 0;
}
//-----------------------------------------------------------




