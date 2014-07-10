//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include "quest22.h"
#include "MLinDet.h"
#include "qvarnt.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#include "math.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest22::quest22(FILE* f)
{
  char* buf = new char[256];

  keygen = 0;

  reads( f, buf );
  strpar1 = strdup( buf );
  reads( f, buf );
  strpar2 = strdup( buf );

  sscanf( strpar1, "%d %d %d", &amin, &amax, &dim );
  sscanf( strpar2, "%d %d %d", &amin, &amax, &numstr );

  qtype = LINDET;

  delete buf;
}

quest22::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest22::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  LinDet->quest = this;
  LinDet->Edit1->Text = IntToStr(amin);
  LinDet->Edit2->Text = IntToStr(amax);
  LinDet->Edit3->Text = IntToStr(keygen);
  LinDet->Edit4->Text = IntToStr(nvar);
  LinDet->Edit5->Text = IntToStr(dim);
  LinDet->Edit6->Text = IntToStr(numstr);
  LinDet->ShowModal();

  return 0;
}

quest22::Print(TList* plist)
{
  int i, j, a, b, temp, ma[10][10];
  int det = 0;
  int tmpi, tmpj;

  char* buf = new char[256];
  char* buf1 = new char[256];

  if( keygen == 0 )
  {
        keygen = random( 1000 ) + 1;
  }

  srand( keygen );

  //Right_Numb = random( dim ) + 1;

  for( i = 0; i < dim; i ++ )
  {
        for( j = 0; j < dim; j ++ )
        {
                ma[i][j] = rgen( keygen, 1, amin, amax );
        }
  }

  a = random( dim );
  b = random( dim );

  typeos = random( 2 );

  while ( a == b )
        b = random( dim );

  if ( a > b )
  {
        temp = a;
        a = b;
        b = temp;
  }

  temp = pow( -1, random( 2 ) ) * ( random( 3 ) + 2 );

  if( !typeos )
  for ( i = 0; i < dim; i++ )
        ma[b][i] = ma[a][i] * temp;
  else
  for ( i = 0; i < dim; i++ )
        ma[i][b] = ma[i][a] * temp;

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
        sprintf( buf, "String(Проверить являются ли строки или столбцы линейно зависимыми.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Если это так то:)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\" а) Найти их номера и определитель данной матрицы %dх%d.\")", dim, dim );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\" б) Найти их линейную комбинацию. \")", dim, dim );
        plist->Add( strdup(buf) );
  }

  sprintf( buf, "|Matrix(%i,%i", dim, dim );

  for( i = 0; i < dim; i ++ )
  {
        for( j = 0; j < dim; j ++ )
        {
                sprintf( buf1, ",%i", ma[i][j] );
                strcat( buf, buf1 );
        }
  }

  strcat( buf, ")|=..." );
  plist->Add( strdup(buf) );

  sprintf( buf, "i=..." );
  plist->Add(strdup(buf));

  sprintf( buf, "j=..." );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(@Часть преподавателя )" );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
  plist->Add( strdup(buf) );

  if ( !typeos )
  {
        sprintf( buf, "String(Линейно зависимыми являются строки.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Линая комбинация этих строк:)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "a(%d)=%d*a(%d)", b + 1, temp, a + 1 );
        plist->Add( strdup(buf) );
  }
  else
  {
        sprintf( buf, "String(Линейно зависимыми являются столбцы.)");
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Линая комбинация этих столбцов:)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "b(%d)=%d*b(%d)", b + 1, temp, a + 1);
        plist->Add( strdup(buf) );
  }

  sprintf( buf, "|Matrix(%d,%d", dim, dim );
  for( i = 0; i < dim; i ++ )
  {
        for( j = 0; j < dim; j ++ )
        {
                sprintf( buf1, ",%i", ma[i][j] );
                strcat( buf, buf1 );
        }
  }

  strcat( buf, ")|=" );
  sprintf( buf1, "%d", det );
  strcat( buf, buf1 );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(i=%d)", a + 1 );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(j=%d)", b + 1 );
  plist->Add( strdup(buf) );

  keygen = 0;

  delete buf;
  delete buf1;

  return 0;
}
//------------------------------------------------------------------------------

quest22::Print(TList* plist, class test &t)
{
        int i, j, a, b, temp, ma[10][10];
        int n, Right_Numb;
        int tmpi, tmpj;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        Right_Numb = random( 2 ) + 1;

        for( i = 0; i < dim; i ++ )
        {
                for( j = 0; j < dim; j ++ )
                {
                        ma[i][j] = rgen( keygen, 1, amin, amax );
                }
        }

        a = random( dim );
        b = random( dim );

        typeos = random( 2 );

        while ( a == b )
                b = random( dim );

        if ( a > b )
        {
                temp = a;
                a = b;
                b = temp;
        }

        temp = pow( -1, random( 2 ) ) * ( random( 3 ) + 2 );

        if( !typeos )
        for ( i = 0; i < dim; i++ )
                ma[b][i] = ma[a][i] * temp;
        else
        for ( i = 0; i < dim; i++ )
                ma[i][b] = ma[i][a] * temp;

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"а)Найти определитель данной матрицы %dх%d.\")", dim, dim );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"б)Найти линейную комбинацию линейнозависимых строк или столбцов. \")", dim, dim );
        plist->Add( strdup(buf) );

        sprintf( buf, "|Matrix(%i,%i", dim, dim );

        for( i = 0; i < dim; i ++ )
        {
                for( j = 0; j < dim; j ++ )
                {
                        sprintf( buf1, ",%i", ma[i][j] );
                        strcat( buf, buf1 );
                }
        }

        strcat( buf, ")|=..." );
        plist->Add( strdup(buf) );

        sprintf( buf, "i=..." );
        plist->Add( strdup(buf) );

        sprintf( buf, "j=..." );
        plist->Add( strdup(buf) );

        tmpi = a;
        tmpj = b;

        for ( n = 0; n < 2; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                if ( n != Right_Numb - 1 )
                {
                        tmpi = ( ( ++tmpi ) % dim + 1 );
                        tmpj = ( ( ++tmpj ) % dim + 1 );

                        if ( !typeos )
                        {
                                sprintf( buf, "String(Линейно зависимыми являются столбцы.)" );
                                plist->Add( strdup(buf) );

                                sprintf( buf, "String(Линая комбинация этих столбцов:)" );
                                plist->Add( strdup(buf) );

                                sprintf( buf, "b(%d)=%d*b(%d)", tmpj, temp, tmpi );
                                plist->Add(strdup(buf));
                        }
                        else
                        {
                                sprintf( buf, "String(Линейно зависимыми являются строки.)" );
                                plist->Add( strdup(buf) );

                                sprintf( buf, "String(Линая комбинация этих строк:)" );
                                plist->Add( strdup(buf) );

                                sprintf( buf, "a(%d)=%d*a(%d)", tmpj, temp, tmpi );
                                plist->Add( strdup(buf) );
                        }

                        sprintf( buf, "|A|=0" );
                        plist->Add( strdup(buf) );

                        sprintf( buf, "String(i=%d)", tmpi );
                        plist->Add( strdup(buf) );

                        sprintf( buf, "String(j=%d)", tmpj );
                        plist->Add( strdup(buf) );
                }
                else
                {
                        if ( !typeos )
                        {
                                sprintf( buf, "String(Линейно зависимыми являются строки.)" );
                                plist->Add( strdup(buf) );

                                sprintf( buf, "String(Линая комбинация этих строк:)" );
                                plist->Add( strdup(buf) );

                                sprintf( buf, "a(%d)=%d*a(%d)", b + 1, temp, a + 1 );
                                plist->Add( strdup(buf) );
                        }
                        else
                        {
                                sprintf( buf, "String(Линейно зависимыми являются столбцы.)" );
                                plist->Add( strdup(buf) );

                                sprintf( buf, "String(Линая комбинация этих столбцов:)" );
                                plist->Add( strdup(buf) );

                                sprintf( buf, "b(%d)=%d*b(%d)", b + 1, temp, a + 1 );
                                plist->Add( strdup(buf) );
                        }

                        sprintf( buf, "|A|=0" );
                        plist->Add( strdup(buf) );

                        sprintf( buf, "String(i=%d)", a + 1 );
                        plist->Add( strdup(buf) );

                        sprintf( buf, "String(j=%d)", b + 1 );
                        plist->Add( strdup(buf) );
                }
        }

        /*sprintf(buf,"String(@Часть преподавателя )");
        plist->Add(strdup(buf));

        sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
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


