//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest27.h"
#include "MComp.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest27::quest27(FILE* f)
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

quest27::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest27::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  CompLine->quest = this;

  CompLine->Edit1->Text = IntToStr(amin);
  CompLine->Edit2->Text = IntToStr(amax);
  CompLine->Edit3->Text = IntToStr(keygen);
  CompLine->Edit4->Text = IntToStr(nvar);

  CompLine->ShowModal();

  return 0;
}

quest27::Print(TList* plist)
{
        int i;
        int p[3], p2[3], m[3], m2[3];
        int TypeQ;

        char * buf = new char[256];
        char * buf1 = new char[256];

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
        }

        TypeQ = random ( 2 );

        if ( TypeQ )
        for ( i = 0; i < 3; i ++ )
                m2[i] = 2 * p[i] + m[i];

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
                sprintf( buf, "String(Установить лежат ли данные прямые в одной плоскости.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Прямые заданы уравнениями:)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "a:" );
        plist->Add( strdup(buf) );

        sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", -m[0], p[0], -m[1], p[1], -m[2], p[2] );
        plist->Add( strdup(buf) );

        sprintf( buf, "b:" );
        plist->Add( strdup(buf) );

        sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", -m2[0], p2[0], -m2[1], p2[1], -m2[2], p2[2] );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        if ( TypeQ )
                sprintf( buf, "String( Прямые принадлежат одной плоскости.)" );
        else
                sprintf( buf, "String( Прямые не принадлежат одной плоскости.)" );
        plist->Add( strdup(buf) );

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//-----------------------------------------------------------------------------

quest27::Print(TList* plist, class test &t)
{
        int i;
        int p[3], p2[3], m[3], m2[3];
        int TypeQ;
        int n, Right_Numb;

        char * buf = new char[256];
        char * buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        Right_Numb = random( 2 ) + 1;

        srand( keygen );

        for( i = 0; i < 3; i ++ )
        {
                p[i] = rgen( keygen, 1, amin, amax );
                p2[i] = rgen( keygen, 1, amin, amax );
                m[i] = rgen( keygen, 1, amin, amax );
                m2[i] = rgen( keygen, 1, amin, amax );

                if( !m[i] )
                        m[i] ++;

                if( !m2[i] )
                        m2[i] ++;
        }

        TypeQ = random ( 2 );

        if ( TypeQ )
        for ( i = 0; i < 3; i ++ )
                m2[i] = 2 * p[i] + m[i];

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Установить лежат ли данные прямые в одной плоскости.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Прямые заданы уравнениями:)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "a:" );
        plist->Add( strdup(buf) );

        sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", -m[0], p[0], -m[1], p[1], -m[2], p[2] );
        plist->Add( strdup(buf) );

        sprintf( buf, "b:" );
        plist->Add( strdup(buf) );

        sprintf( buf, "(x%+d)/%d=(y%+d)/%d=(z%+d)/%d", -m2[0], p2[0], -m2[1], p2[1], -m2[2], p2[2] );
        plist->Add( strdup(buf) );


        for( n = 0; n < 2; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );
                
                if( n == Right_Numb - 1 )
                        if ( TypeQ )
                                sprintf( buf, "String( Прямые принадлежат одной плоскости.)" );
                        else
                                sprintf( buf, "String( Прямые не принадлежат одной плоскости.)" );
                else
                        if ( TypeQ )
                                sprintf( buf, "String( Прямые не принадлежат одной плоскости.)" );
                        else
                                sprintf( buf, "String( Прямые принадлежат одной плоскости.)" );

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
        t.ch_ask = 2;
        t.right_ask = Right_Numb;
        t.msg = "Тест успешно сгенерирован.";

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//-----------------------------------------------------------


