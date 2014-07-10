//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest8.h"
#include "scale.h"
# include "drobi.h"
#include "qvarnt.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest8::quest8(FILE* f)
{
  char* buf = new char[256];

  randomize();
  keygen = random (1000) + 1;

  reads( f, buf );
  strpar1 = strdup(buf);
  reads( f, buf );
  strpar2 = strdup(buf);

  sscanf( strpar1, "%d %d %d", &amin, &amax, &dim );
  sscanf( strpar2, "%d %d %d", &amin, &amax, &number );
  qtype = type;

  delete buf;
}

quest8::Save( FILE * f )
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest8::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  ScalMul->quest = this;
  ScalMul->Edit1->Text = IntToStr(amin);
  ScalMul->Edit2->Text = IntToStr(amax);
  ScalMul->Edit3->Text = IntToStr(keygen);
  ScalMul->Edit4->Text = IntToStr(nvar);
  ScalMul->Edit5->Text = IntToStr(dim);
  ScalMul->ComboBox1->ItemIndex = number;

  ScalMul->ShowModal();

  return 0;
}

quest8::Print(TList* plist)
{
  int i, ma[20], mb[20], mc[20], md[20], mult, a, b;
  int TypeQuest;

  char* buf = new char[256];
  char* buf1 = new char[256];

  int fabsa, fabsb;

  drobi dr;

  TypeQuest = number;

  if( keygen == 0 )
  {
        keygen = random( 1000 ) + 1;
  }

  srand( keygen );

  mult = 0;

  a = 1;
  b = 1;

  for( i = 0; i < dim; i ++ )
  {
        /*ma[i] = pow(-1,random(amin)) * (random(amax) + 1);
        mb[i] = pow(-1,random(amin)) * (random(amax) + 1);*/
        ma[i] = rgen(keygen, 1, amin,amax);
        mb[i] = rgen(keygen, 1, amin,amax);
        mc[i] = rgen(keygen, 1, amin,amax);

        while ( abs( a ) <= 1 )
                a = rgen(keygen, 1, amin,amax);

        while ( abs( b ) <= 1 )
                b = rgen(keygen, 1, amin,amax);
  }

  switch ( TypeQuest )
  {
        case 1:
                for (i = 0; i < dim - 1; i ++)
                        mult += ma[i] * mb[i];

                ma[dim - 1] = 1;
                mb[dim - 1] = -mult;
                mult = 0;
        break;
        case 2:
                int kol, zn;

                kol = random ( 3 ) + 1;
                zn = pow ( -1, ( double )random (2) );

                for (i = 0; i < dim; i ++)
                        mb[i] = zn * kol * ma[i];
        break;

        case 3:
                for ( i = 0; i < dim; i ++ )
                {
                        md[i] = a * ma[i] + b * mb[i];
                }
        break;
  }

  switch ( TypeQuest )
  {
        case 0:
        case 1:

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf(buf,"String(\"# Тема - %s \")",selecttask->name);
                plist->Add(strdup(buf));
        }
        else
        {
                sprintf( buf, "String(#)" );
                plist->Add(strdup(buf));
        }

        sprintf(buf,"String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add(strdup(buf));

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf(buf,"String(Найти скалярное произведение векторов.)");
                plist->Add(strdup(buf));

                sprintf(buf,"String(Найти косинус угла между векторами.)");
                plist->Add(strdup(buf));
        }

        sprintf(buf,"_a=!(%d",ma[0]);

        for( i = 1; i < dim; i ++ )
        {
                sprintf(buf1,",%d",ma[i]);
                strcat(buf,buf1);
        }

        strcat(buf,")");
        plist->Add(strdup(buf));

        sprintf(buf,"_b=!(%d",mb[0]);

        for( i = 1; i < dim; i ++ )
        {
                sprintf(buf1,",%d",mb[i]);
                strcat(buf,buf1);
        }

        strcat(buf,")");
        plist->Add(strdup(buf));

        sprintf(buf,"!(_a,_b)=...");
        plist->Add(strdup(buf));

        sprintf(buf,"cos(Angle(ab))=...");
        plist->Add(strdup(buf));

        sprintf(buf,"String(@Часть преподавателя )");
        plist->Add(strdup(buf));

        sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
        plist->Add(strdup(buf));

        sprintf(buf,"!(_a,_b)=!(!(%d",ma[0]);

        for (i = 1; i < dim; i ++)
        {
                sprintf(buf1,",%d",ma[i]);
                strcat(buf,buf1);
        }

        strcat(buf,"),");

        sprintf(buf1,"!(%d",mb[0]);
        strcat(buf,buf1);

        for (i = 1; i < dim; i ++)
        {
                sprintf(buf1,",%d",mb[i]);
                strcat(buf,buf1);
        }

        strcat(buf,"))=");

        for (i = 0; i < dim; i ++)
                mult += ma[i] * mb[i];

        sprintf(buf1,"%d",mult);
        strcat(buf,buf1);
        plist->Add(strdup(buf));

        fabsa = 0;
        fabsb = 0;

        for ( i = 0; i < dim; i ++ )
        {
                fabsa += ( ma[i] * ma[i] );
                fabsb += ( mb[i] * mb[i] );
        }

        if ( !mult )
                sprintf (buf , "cos(Angle(ab))=0" );
        else
        if ( ceil (sqrt ( fabsa )) == sqrt ( fabsa ) &&  ceil (sqrt ( fabsb )) == sqrt ( fabsb ) )
        {
                dr = drobi( mult, (int ) sqrt ( fabsa * fabsb ) );

                sprintf (buf , "cos(Angle(ab))=%s", DrobiToStr( dr ) );
        }
        else
        if ( ceil (sqrt ( fabsa )) == sqrt ( fabsa ) )
        {
                sprintf (buf , "cos(Angle(ab))=%d/(%f*sqrt(%d))", mult, sqrt(fabsa), fabsb );
        }
        else
        if ( ceil (sqrt ( fabsb )) == sqrt ( fabsb ) )
        {
                sprintf (buf , "cos(Angle(ab))=%d/(sqrt(%d)*%f)", mult, fabsa, sqrt(fabsb));
        }
        else
        if ( ceil ( sqrt ( fabsa * fabsb ) ) == sqrt ( fabsa * fabsb )  )
        {
                dr = drobi( mult, (int ) sqrt ( fabsa * fabsb ) );

                sprintf (buf , "cos(Angle(ab))=%s", DrobiToStr( dr ) );
        }
        else
                sprintf (buf , "cos(Angle(ab))=%d/(sqrt(%d)*sqrt(%d))=%d/(sqrt(%d))", mult, fabsa, fabsb, mult, fabsa * fabsb);

        plist->Add(strdup(buf));

        break;

        case 2:

        double angle;

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf(buf,"String(\"# Тема - %s \")",selecttask->name);
                plist->Add(strdup(buf));
        }

        sprintf(buf,"String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add(strdup(buf));

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf(buf,"String(Используя скалярное произведение доказать колинеарность векторов.)");
                plist->Add(strdup(buf));
        }

        sprintf(buf,"_a=!(%d",ma[0]);

        for( i = 1; i < dim; i ++ )
        {
                sprintf(buf1,",%d",ma[i]);
                strcat(buf,buf1);
        }

        strcat(buf,")");
        plist->Add(strdup(buf));

        sprintf(buf,"_b=!(%d",mb[0]);

        for( i = 1; i < dim; i ++ )
        {
                sprintf(buf1,",%d",mb[i]);
                strcat(buf,buf1);
        }

        strcat(buf,")");
        plist->Add(strdup(buf));

        sprintf(buf,"String(@Часть преподавателя )");
        plist->Add(strdup(buf));

        sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
        plist->Add(strdup(buf));

        sprintf(buf,"!(_a,_b)=!(!(%d",ma[0]);

        for (i = 1; i < dim; i ++)
        {
                sprintf(buf1,",%d",ma[i]);
                strcat(buf,buf1);
        }

        strcat(buf,"),");

        sprintf(buf1,"!(%d",mb[0]);
        strcat(buf,buf1);

        for (i = 1; i < dim; i ++)
        {
                sprintf(buf1,",%d",mb[i]);
                strcat(buf,buf1);
        }

        strcat(buf,"))=");

        for (i = 0; i < dim; i ++)
                mult += ma[i] * mb[i];

        sprintf(buf1,"%d",mult);
        strcat(buf,buf1);
        plist->Add(strdup(buf));

        fabsa = 0;
        fabsb = 0;

        for ( i = 0; i < dim; i ++ )
        {
                fabsa += ( ma[i] * ma[i] );
                fabsb += ( mb[i] * mb[i] );
        }

        angle = ( mult * mult )/ ( fabsa * fabsb);

        angle = ( mult / abs( mult )) * sqrt ( angle );

        sprintf (buf , "String(Вектора коллинеарны.)");
        plist->Add(strdup(buf));

        sprintf (buf , "cos(Angle(ab))=%f",angle);
        plist->Add(strdup(buf));

        break;

        case 3:
                if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
                {
                        sprintf(buf,"String(\"# Тема - %s \")",selecttask->name);
                        plist->Add(strdup(buf));
                }

                sprintf(buf,"String(Вариант   %i, задача %i. )", nvar, nzad );
                plist->Add(strdup(buf));

                if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
                {
                        sprintf(buf,"String(Найти значение выражения.)");
                        plist->Add(strdup(buf));
                }

                sprintf(buf,"_a=!(%d",ma[0]);

                for( i = 1; i < dim; i ++ )
                {
                        sprintf(buf1,",%d",ma[i]);
                        strcat(buf,buf1);
                }

                strcat(buf,")");
                plist->Add(strdup(buf));

                sprintf(buf,"_b=!(%d",mb[0]);

                for( i = 1; i < dim; i ++ )
                {
                        sprintf(buf1,",%d",mb[i]);
                        strcat(buf,buf1);
                }

                strcat(buf,")");
                plist->Add(strdup(buf));

                sprintf(buf,"_с=!(%d",mc[0]);

                for( i = 1; i < dim; i ++ )
                {
                        sprintf(buf1,",%d", mc[i]);
                        strcat(buf,buf1);
                }

                strcat(buf,")");
                plist->Add(strdup(buf));

                sprintf(buf,"!(%d*_a%+d*_b)*._c=...", a, b );
                plist->Add(strdup(buf));

                sprintf(buf,"String(@Часть преподавателя )");
                plist->Add(strdup(buf));

                sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
                plist->Add(strdup(buf));

                sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
                plist->Add(strdup(buf));

                sprintf(buf,"_a=!(%d",ma[0]);

                for (i = 1; i < dim; i ++)
                {
                        sprintf(buf1,",%d",ma[i]);
                        strcat(buf,buf1);
                }

                strcat(buf,")");
                plist->Add(strdup(buf));

                sprintf(buf,"_b=!(%d",mb[0]);

                for (i = 1; i < dim; i ++)
                {
                        sprintf(buf1,",%d",mb[i]);
                        strcat(buf,buf1);
                }

                strcat(buf,")");
                plist->Add(strdup(buf));

                sprintf(buf,"_c=!(%d",mc[0]);

                for (i = 1; i < dim; i ++)
                {
                        sprintf(buf1,",%d",mc[i]);
                        strcat(buf,buf1);
                }

                strcat(buf,")");
                plist->Add(strdup(buf));

                mult = 0;

                for (i = 0; i < dim; i ++)
                        mult += mc[i] * md[i];

                sprintf(buf,"!(%d*_a%+d*_b)*._c=%d", a, b, mult);
                plist->Add(strdup(buf));

        break;
  }

  keygen = 0;

  delete buf;
  delete buf1;

  return 0;
}
//---------------------------------------------------------

quest8::Print(TList* plist, class test &t)
{
        int ma[20], mb[20], mc[20], md[20], mult;
        int n, Right_Numb;
        int kol, zn, i, a, b;

        char* buf = new char[256];
        char* buf1 = new char[256];

        int fabsa, fabsb;

        drobi dr;

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        Right_Numb = random( 5 ) + 1;

        mult = 0;

        a = 1;
        b = 1;

        for( i = 0; i < dim; i ++ )
        {
                ma[i] = rgen( keygen, 1, amin, amax );
                mb[i] = rgen( keygen, 1, amin, amax );
                mc[i] = rgen( keygen, 1, amin, amax );

                while ( abs( a ) <= 1 )
                        a = rgen( keygen, 1, amin, amax );

                while ( abs( b) <= 1 )
                        b = rgen( keygen, 1, amin, amax );
        }

        switch ( number )
        {
                case 1:

                for (i = 0; i < dim - 1; i ++)
                        mult += ma[i] * mb[i];

                ma[dim - 1] = 1;
                mb[dim - 1] = -mult;
                mult = 0;

                break;
                case 2:

                kol = random ( 3 ) + 1;
                zn = pow ( -1, ( double )random (2) );

                for( i = 0; i < dim; i ++ )
                        mb[i] = zn * kol * ma[i];
        break;

        case 3:
                for ( i = 0; i < dim; i ++ )
                {
                        md[i] = a * ma[i] + b * mb[i];
                }
        break;
  }

  switch ( number )
  {
        case 0:
        case 1:
                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add(strdup(buf));

                sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти скалярное произведение векторов.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d",ma[0] );

                for( i = 1; i < dim; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < dim; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "!(_a,_b)=..." );
                plist->Add( strdup(buf) );

                mult = 0;

                for (i = 0; i < dim; i ++)
                        mult +=  ma[i] * mb[i];

                for ( n = 0; n < 5; n ++ )
                {
                        sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                        plist->Add( strdup(buf) );

                        sprintf( buf, "!(_a,_b)=" );

                        sprintf( buf1, "%d", mult - ( Right_Numb - 1 ) + n );
                        strcat( buf, buf1 );
                        plist->Add( strdup(buf) );

                }

                /*sprintf(buf,"String(@Часть преподавателя )");
                plist->Add(strdup(buf));

                sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
                plist->Add(strdup(buf));

                sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
                plist->Add(strdup(buf));

                sprintf(buf,"String( Правильный ответ - %c)", 'a' + Right_Numb - 1 );
                plist->Add(strdup(buf));*/

        break;

        case 2:
                sprintf( buf, "String(#Для данного типа задач тесты не генерируются.)" );
                plist->Add( strdup(buf) );
        break;

        case 3:
                sprintf(buf,"String(\"# Тема - %s \")",selecttask->name);
                plist->Add(strdup(buf));

                sprintf(buf,"String(Вариант   %i, задача %i. )", nvar, nzad );
                plist->Add(strdup(buf));

                sprintf(buf,"String(Найти значение выражения.)");
                plist->Add(strdup(buf));

                sprintf(buf,"_a=!(%d",ma[0]);

                for( i = 1; i < dim; i ++ )
                {
                        sprintf(buf1,",%d",ma[i]);
                        strcat(buf,buf1);
                }

                strcat(buf,")");
                plist->Add(strdup(buf));

                sprintf(buf,"_b=!(%d",mb[0]);

                for( i = 1; i < dim; i ++ )
                {
                        sprintf(buf1,",%d",mb[i]);
                        strcat(buf,buf1);
                }

                strcat(buf,")");
                plist->Add(strdup(buf));

                sprintf(buf,"_с=!(%d",mc[0]);

                for( i = 1; i < dim; i ++ )
                {
                        sprintf(buf1,",%d", mc[i]);
                        strcat(buf,buf1);
                }

                strcat(buf,")");
                plist->Add(strdup(buf));

                sprintf(buf,"!(%d*_a%+d*_b)*._c=...", a, b );
                plist->Add(strdup(buf));

                mult = 0;

                for (i = 0; i < dim; i ++)
                        mult += mc[i] * md[i];

                for ( n = 0; n < 5; n ++ )
                {
                        sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
                        plist->Add(strdup(buf));

                        sprintf( buf, "!(%d*_a%+d*_b)*._c=%d", a, b, mult - ( Right_Numb - 1 ) + n );
                        plist->Add(strdup(buf));
                }

                /*sprintf(buf,"String(@Часть преподавателя )");
                plist->Add(strdup(buf));

                sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
                plist->Add(strdup(buf));

                sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
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

