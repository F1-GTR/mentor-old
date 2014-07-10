//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest23.h"
#include "drobi.h"
#include "determ.h"
#include "MKramer.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest23::quest23(FILE* f)
{
  char* buf = new char[256];

  randomize();
  keygen = random (1000) + 1;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);

  sscanf(strpar1,"%d %d %d",&amin,&amax,&dim);
  sscanf(strpar2,"%d %d %d",&amin,&amax,&number);
  qtype = KRAMER;
  delete buf;
}

quest23::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest23::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  Kramer->quest = this;
  Kramer->Edit1->Text = IntToStr(amin);
  Kramer->Edit2->Text = IntToStr(amax);
  Kramer->Edit3->Text = IntToStr(keygen);
  Kramer->Edit4->Text = IntToStr(nvar);
  Kramer->Edit5->Text = IntToStr(dim);
  Kramer->ComboBox1->ItemIndex = number;
  Kramer->ShowModal();

  return 0;
}

quest23::Print(TList* plist)
{
  int i, j, k, ma[5][10], vect[5], a, b, tm, TmpMtr[5][5], tmp1, tmp2, mt[5][10];

  char* buf = new char[256];
  char* buf1 = new char[256];

  if( keygen == 0 )
  {
        keygen = random( 1000 ) + 1;
  }

  srand( keygen );

  for( i = 0; i < dim; i ++ )
  {
        for( j = 0; j < dim; j ++ )
        {
                ma[i][j] = rgen( keygen, 1, amin, amax );
                vect[i] = rgen( keygen, 1, amin, amax );
        }
  }

  a = random( dim );
  b = random( dim );

  while ( b == a)
        b = random( dim );

  if ( a > b )
  {
        i = a;
        a = b;
        b = i;
  }

  tm = random( 4 ) + 2;

  if ( number != 2 )
  for( i = 0; i < dim; i ++ )
  {
        ma[b][i] = ma[a][i] * tm;
  }
  else
  for( i = 1; i < dim; i ++ )
  {
        tm = random( 3 ) + 2;

        for( j = 0; j < dim; j ++ )
        {
                ma[i][j] = ma[0][j] * tm;
        }
  }

  if ( number == 1 )
        vect[b] = vect[a] * tm;
  else
  if ( number == 0 )
        vect[b] = vect[a] * tm + 1;
  else
  {
        for( i = 0; i < dim; i ++ )
        {
                tm = random( dim );

                while ( tm == i )
                        tm = random( dim );

        //for( i = 0; i < dim; i ++ )
                vect[i] = ma[tm][0];
        }
  }

  if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
  {
        sprintf(buf,"String(\"# Тема - %s.\")",selecttask->name);
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
        sprintf( buf, "String( Решить систему %dх%d методом Крамера.)", dim, dim );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Найти особенность этой системы.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Решить эту же систему методом Гаусса.)" );
        plist->Add( strdup(buf) );
  }

/*  sprintf(buf,"System(%d*x_1",ma[0][0]);

  for ( i = 1; i < dim; i ++)
  {
        sprintf(buf1,"%+d*x_%d",ma[0][i],i+1);
        strcat(buf,buf1);
  }

  sprintf(buf1,"=%d",vect[0]);
  strcat(buf,buf1);

  for( i = 1; i < dim; i ++)
  {
    sprintf(buf1,",%d*x_1",ma[i][0]);
    strcat(buf,buf1);

    for( j = 1; j < dim; j ++)
    {
        sprintf(buf1,"%+d*x_%d",ma[i][j],j+1);
        strcat(buf,buf1);
    }

    sprintf(buf1,"=%d",vect[i]);
    strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));
*/

  if ( ma[0][0] != 1 )
        sprintf( buf, "System(%d*x_1", ma[0][0] );
  else
        sprintf( buf, "System(x_1" );

  for ( i = 1; i < dim; i ++ )
  {
        if ( ma[0][i] != 1 )
                sprintf( buf1, "%+d*x_%d", ma[0][i], i + 1 );
        else
                sprintf( buf1, "+x_%d", i + 1 );
        strcat( buf, buf1 );
  }

  sprintf( buf1, "=%d", vect[0] );
  strcat( buf, buf1 );

  for( i = 1; i < dim; i++ )
  {
    if ( ma[i][0] != 1 )
        sprintf( buf1, ",%d*x_1", ma[i][0] );
    else
        sprintf( buf1, ",x_1" );
    strcat( buf, buf1 );

    for( j = 1; j < dim; j++ )
    {
        if ( ma[i][j] != 1 )
                sprintf( buf1, "%+d*x_%d", ma[i][j], j + 1 );
        else
                sprintf( buf1, "+x_%d", j + 1 );
        strcat( buf, buf1 );
    }

    sprintf( buf1, "=%d", vect[i] );
    strcat( buf, buf1 );
  }

  strcat( buf, ")" );
  plist->Add( strdup(buf) );

/*  sprintf(buf,"String(___________________________________________)");
  plist->Add(strdup(buf));*/

  sprintf( buf, "String(@Часть преподавателя )" );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
  plist->Add( strdup(buf) );

  if ( number == 0 )
  {
        sprintf( buf, "String( Решений нет.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Главный определитель равен нулю.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Дополнительные определители не нулевые: )" );
        plist->Add( strdup(buf) );

        for (i = 0; i < dim; i ++ )
        {
                for(j = 0; j < dim; j ++ )
                        for( k = 0; k < dim; k ++ )
                        {
                        if (k == i)
                        {
                                mt[j][k] = vect[j];
                        }
                        else
                        {
                                mt[j][k] = ma[j][k];
                        }
                        }

                if (  determ( dim, mt ) )
                {
                        sprintf( buf, "Delta_%d<>0", i + 1 );
                        plist->Add( strdup(buf) );
                }
        }
  }
  else
  if( number == 1 )
  {
        sprintf( buf, "String( Решений бесконечно много.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Все определители равны нулю.)" );
        plist->Add( strdup(buf) );
  }
  else
  {
        sprintf( buf, "String( Решений нет.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Все определители равны нулю.)" );
        plist->Add( strdup(buf) );
  }

//  if( qtype == LEGAUSS )
  {
        sprintf( buf, "String(Исходная матрица:)" );
        plist->Add( strdup(buf) );

        for ( i = 0; i < dim; i ++ )
                ma[i][dim] = vect[i];

        sprintf( buf, "!(Matrix(%d,%d", dim + 1, dim );
        for ( i = 0; i < dim; i ++ )
        for ( j = 0; j <= dim; j++ )
        {
                TmpMtr[i][j] = ma[i][j];
                sprintf( buf1, ",%d", ma[i][j] );
                strcat( buf, buf1 );
        }

        sprintf( buf1, "))" );
        strcat( buf, buf1 );
        plist->Add( strdup(buf) );

        for ( i = 0; i < dim; i ++ )
        for ( j = i + 1; j < dim; j++ )
        {

                tmp1 = TmpMtr[i][i];
                tmp2 = TmpMtr[j][i];

                for ( k = 0; k <= dim; k ++)
                        TmpMtr[j][k] = TmpMtr[j][k]*tmp1 - TmpMtr[i][k]*tmp2;
        }

  sprintf( buf, "String(Преобразованная матрица:)", nvar, nzad, keygen );
  plist->Add( strdup(buf) );

  sprintf( buf, "!(Matrix(%d,%d", dim + 1, dim );

  for ( i = 0; i < dim; i ++ )
        for ( j = 0; j <= dim; j++ )
        {
                sprintf( buf1, ",%d", TmpMtr[i][j] );
                strcat( buf, buf1 );
        }

  sprintf( buf1, "))" );

  strcat( buf, buf1 );
  plist->Add( strdup(buf) );

  if ( number == 1 )
  {
        drobi a, b;

        sprintf( buf, "!(Matrix(1,%d", dim );

        for ( i = 0; i < dim; i ++ )
        {
                sprintf( buf1, ",x_%d", i + 1 );
                strcat( buf, buf1 );
        }


        sprintf( buf1, "))=!(Matrix(1,%d", dim );
        strcat( buf, buf1 );

        for( i = 0; i < dim; i ++ )
        {
                if ( TmpMtr[i][i] )
                {
                        a = drobi( vect[i], TmpMtr[i][i] );

                        if ( a.c == ceil(a.c) )
                                sprintf( buf1, ",%f", a.c );
                        else
                                sprintf( buf1, ",%d*%d/%d", a.znak, a.a, a.b );
                        strcat( buf, buf1 );

                        for( j = i + 1; j < dim; j ++ )
                        {
                                b = drobi( -TmpMtr[i][j], TmpMtr[i][i] );

                                if ( b.c == ceil(b.c) )
                                        sprintf( buf1, "%+f*x_%d", b.c, j + 1 );
                                else
                                        sprintf( buf1, "%+d*%d/%d*x_%d", b.znak, b.a, b.b, j + 1 );
                                strcat( buf, buf1 );
                        }
                }
                else
                {
                        sprintf( buf1,",x_%d", i+1 );
                        strcat( buf, buf1 );
                }
        }

        strcat( buf, "))" );
        plist->Add( strdup(buf) );
  }
  }

/*  sprintf(buf,"String(___________________________________________)");
  plist->Add(strdup(buf));*/

  keygen = 0;

  delete buf;
  delete buf1;

  return 0;
}
//----------------------------------------------------------------

quest23::Print(TList* plist, class test &t)
{
        int i, j, k, ma[5][10], vect[5], a, b, tm;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        number = random( 3 );

        for( i = 0; i < dim; i ++ )
        {
                for( j = 0; j < dim; j ++ )
                {
                        ma[i][j] = rgen( keygen, 1, amin, amax );
                        vect[i] = rgen( keygen, 1, amin, amax );
                }
        }

        a = random( dim );
        b = random( dim );

        while ( b == a)
                b = random( dim );

        if ( a > b )
        {
                i = a;
                a = b;
                b = i;
        }

        tm = random( 4 ) + 2;

        if ( number != 2 )
        for( i = 0; i < dim; i ++ )
        {
                ma[b][i] = ma[a][i] * tm;
        }
        else
        for( i = 1; i < dim; i ++ )
        {
                tm = random( 3 ) + 2;

                for( j = 0; j < dim; j ++ )
                {
                        ma[i][j] = ma[0][j] * tm;
                }
        }

        if ( number == 1 )
                vect[b] = vect[a] * tm;
        else
        if ( number == 0 )
                vect[b] = vect[a] * tm + 1;
        else
        {
                for( i = 0; i < dim; i ++ )
                {
                        tm = random( dim );

                        while ( tm == i )
                                tm = random( dim );

                        vect[i] = ma[tm][0];
                }
        }

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(\"# Тема - %s.\")", selecttask->name );
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
                sprintf( buf, "String( Решить систему %dх%d методом Крамера.)", dim, dim );
                plist->Add( strdup(buf) );

                sprintf( buf, "String( Найти особенность этой системы.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String( Решить эту же систему методом Гаусса.)" );
                plist->Add( strdup(buf) );
        }

        if ( ma[0][0] != 1 )
                sprintf( buf, "System(%d*x_1", ma[0][0] );
        else
                sprintf( buf, "System(x_1" );

        for ( i = 1; i < dim; i ++ )
        {
                if ( ma[0][i] != 1 )
                        sprintf( buf1, "%+d*x_%d", ma[0][i], i + 1 );
                else
                        sprintf( buf1, "+x_%d", i + 1 );
                strcat( buf, buf1 );
        }

        sprintf( buf1, "=%d", vect[0] );
        strcat( buf, buf1 );

        for( i = 1; i < dim; i++ )
        {
                if ( ma[i][0] != 1 )
                        sprintf( buf1, ",%d*x_1", ma[i][0] );
                else
                        sprintf( buf1, ",x_1" );
                strcat( buf, buf1 );

                for( j = 1; j < dim; j++ )
                {
                        if ( ma[i][j] != 1 )
                                sprintf( buf1, "%+d*x_%d", ma[i][j], j + 1 );
                        else
                        sprintf( buf1, "+x_%d", j + 1 );
                        strcat( buf, buf1 );
                }

                sprintf( buf1, "=%d", vect[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Вариант %c):\")", 'a' );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Решений нет.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Главный определитель равен нулю.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Дополнительные определители не нулевые: )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Вариант %c):\")", 'b' );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Решений бесконечно много.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Все определители равны нулю.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"Вариант %c):\")", 'c' );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Решений нет.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String( Все определители равны нулю.)" );
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
        t.right_ask = number + 1;
        t.msg = "Тест успешно сгенерирован.";

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//-----------------------------------------------------------


