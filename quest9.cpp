//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "drobi.h"
#include "quest9.h"
#include "MVectorMul.h"
#include "qvarnt.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest9::quest9(FILE* f)
{
  char* buf = new char[256];

  randomize();
  keygen = random (1000) + 1;

  reads(f,buf);
  strpar1 = strdup(buf);

  reads(f,buf);
  strpar2 = strdup(buf);

  sscanf(strpar1,"%d %d %d", &amin, &amax, &QuestType);
  qtype = type;

  delete buf;
}

quest9::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest9::Edit()
{
  sscanf( strpar1, "%i%i%i", &amin, &amax, &QuestType);

  keygen = 0;
  nvar = 1;

  VectorMul->quest = this;

  VectorMul->Edit1->Text = IntToStr(amin);
  VectorMul->Edit2->Text = IntToStr(amax);
  VectorMul->Edit3->Text = IntToStr(keygen);
  VectorMul->Edit4->Text = IntToStr(nvar);
  VectorMul->ComboBox1->ItemIndex = QuestType;

  VectorMul->ShowModal();

  return 0;
}

quest9::Print(TList* plist)
{
  int i, j, k;
  int ma[3], mb[3], mc[3], md[3], mvect[3], matr[2][2];
  int a = 0, b = 0, c = 0, d = 0, TypeQuest;
  int mult;

  char* buf = new char[256];
  char* buf1 = new char[256];

  if( keygen == 0 )
  {
        keygen = random( 1000 ) + 1;
  }

  srand( keygen );

  TypeQuest = QuestType;

  for( i = 0; i < 3; i ++ )
  {
        ma[i] = rgen( keygen, 1, amin, amax );
        mb[i] = rgen( keygen, 1, amin, amax );

        while( mb[i] == ma[i] )
                        mb[i] = rgen( keygen, 1, amin, amax );
  }

  if ( TypeQuest == 2 )
  {
        a = pow( -1, random ( 2 ) );
        b = random ( 4 ) + 1;

        for ( i = 0; i < 3; i ++)
                mb[i] = a * b * ma[i];
  }

  a = 0;
  b = 0;

  while ( a <= 1 )
        a = rgen( keygen, 1, amin, amax );

  while ( b == 0 || b == a )
        b = rgen( keygen, 1, amin, amax );

  while ( c <= 1 )
        c = rgen( keygen, 1, amin, amax );

  while ( d == 0 || d == c || d == b )
        d = rgen( keygen, 1, amin, amax );

  if ( TypeQuest == 4 )
  {
        for ( i = 0; i < 3; i ++ )
        {
                mc[i] = a * ma[i] + b * mb[i];
                md[i] = c * ma[i] + d * mb[i];
        }
  }

  switch ( TypeQuest )
  {
        case 0:

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
                sprintf(buf,"String(Найти векторное произведение векторов.)");
                plist->Add(strdup(buf));
        }

  sprintf(buf,"_a=!(%d",ma[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",ma[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"_b=!(%d",mb[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",mb[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"_a*+_b=...");
  plist->Add(strdup(buf));

  sprintf(buf,"String(@Часть преподавателя )");
  plist->Add(strdup(buf));

  sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
  plist->Add(strdup(buf));

  sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
  plist->Add(strdup(buf));

  sprintf(buf,"_a*+_b=!(%d",ma[0]);

  for (i = 1; i < 3; i ++)
  {
        sprintf(buf1,",%d",ma[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")*+");

  sprintf(buf1,"!(%d",mb[0]);
  strcat(buf,buf1);

  for (i = 1; i < 3; i ++)
  {
        sprintf(buf1,",%d",mb[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")=!(");

  for (i = 0; i < 3; i ++)
  {
        k = 0;

        for (j = 0; j < 3; j ++)
        {
                if ( j != i)
                {
                        matr[0][k] = ma[j];
                        matr[1][k] = mb[j];
                        k ++;
                }
        }

        mvect[i] = pow(-1,i) * determ(2,matr);
  }

  sprintf(buf1,"%d",mvect[0]);
  strcat(buf,buf1);

  for (i = 1; i < 3; i ++)
  {
        sprintf(buf1,",%d",mvect[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  break;
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

        sprintf(buf,"String(Вариант   %i, задача %i)", nvar, nzad );
        plist->Add(strdup(buf));

        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf(buf,"String(Найти площадь параллелограмма построенного на векторах.)");
                plist->Add(strdup(buf));
        }

  sprintf(buf,"_a=!(%d",ma[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",ma[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"_b=!(%d",mb[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",mb[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"S=...");
  plist->Add(strdup(buf));

  sprintf(buf,"String(@Часть преподавателя )");
  plist->Add(strdup(buf));

  sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
  plist->Add(strdup(buf));

  sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
  plist->Add(strdup(buf));

  sprintf(buf,"_a=!(%d",ma[0]);

  for (i = 1; i < 3; i ++)
  {
        sprintf(buf1,",%d",ma[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"_b=!(%d",mb[0]);

  for (i = 1; i < 3; i ++)
  {
        sprintf(buf1,",%d",mb[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  for (i = 0; i < 3; i ++)
  {
        k = 0;

        for (j = 0; j < 3; j ++)
        {
                if ( j != i)
                {
                        matr[0][k] = ma[j];
                        matr[1][k] = mb[j];
                        k ++;
                }
        }

        mvect[i] = pow(-1,i)*determ(2,matr);
  }

  mult = 0;

  for ( i = 0; i < 3; i ++ )
        mult += mvect[i] * mvect [i];

  if ( ceil ( sqrt (mult ) ) == sqrt(mult) )
        sprintf ( buf, "S=%f", sqrt(mult) );
  else
        sprintf ( buf, "S=sqrt(%d)", mult );

  plist->Add(strdup(buf));

  break;

  case 2:

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

  sprintf(buf,"String(Вариант   %i, задача %i. )", nvar, nzad );
  plist->Add(strdup(buf));

  if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
  {
        sprintf(buf,"String(Доказать коллинеарность векторов через векторное произведение.)");
        plist->Add(strdup(buf));
  }

  sprintf(buf,"_a=!(%d",ma[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",ma[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"_b=!(%d",mb[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",mb[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"_a*+_b=...");
  plist->Add(strdup(buf));

  sprintf(buf,"String(@Часть преподавателя )");
  plist->Add(strdup(buf));

  sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
  plist->Add(strdup(buf));

  sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
  plist->Add(strdup(buf));

  sprintf(buf,"_a=!(%d",ma[0]);

  for (i = 1; i < 3; i ++)
  {
        sprintf(buf1,",%d",ma[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"_b=!(%d",mb[0]);

  for (i = 1; i < 3; i ++)
  {
        sprintf(buf1,",%d",mb[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  for (i = 0; i < 3; i ++)
  {
        k = 0;

        for (j = 0; j < 3; j ++)
        {
                if ( j != i)
                {
                        matr[0][k] = ma[j];
                        matr[1][k] = mb[j];
                        k ++;
                }
        }

        mvect[i] = pow(-1,i)*determ(2,matr);
  }

  sprintf(buf,"String(Вектора коллинеарны.)");
  plist->Add(strdup(buf));

  sprintf(buf,"_a*+_b=!(%d",mvect[0]);

  for (i = 1; i < 3; i ++)
  {
        sprintf(buf1,",%d",mvect[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  break;

  case 3:

  drobi dr;

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
        sprintf(buf,"String(Найти орт ортогональный векторам.)");
        plist->Add(strdup(buf));
  }

  sprintf(buf,"_a=!(%d",ma[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",ma[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"_b=!(%d",mb[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",mb[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"орт=...");
  plist->Add(strdup(buf));

  sprintf(buf,"String(@Часть преподавателя )");
  plist->Add(strdup(buf));

  sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
  plist->Add(strdup(buf));

  sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
  plist->Add(strdup(buf));

  sprintf(buf,"_a=!(%d",ma[0]);

  for (i = 1; i < 3; i ++)
  {
        sprintf(buf1,",%d",ma[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf, "_b=!(%d",mb[0]);

  for (i = 1; i < 3; i ++)
  {
        sprintf(buf1,",%d",mb[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  for (i = 0; i < 3; i ++)
  {
        k = 0;

        for (j = 0; j < 3; j ++)
        {
                if ( j != i)
                {
                        matr[0][k] = ma[j];
                        matr[1][k] = mb[j];
                        k ++;
                }
        }

        mvect[i] = pow(-1,i)*determ(2,matr);
  }


  mult = 0;

  for ( i = 0; i < 3; i ++ )
        mult += mvect[i] * mvect [i];

  if ( ceil ( sqrt ( mult) ) == sqrt ( mult ) )
  {
        dr = drobi( mvect[0], sqrt ( mult ) );
        sprintf(buf,"орт=!(%s", DrobiToStr( dr ) );

        for (i = 1; i < 3; i ++)
        {
                dr = drobi( mvect[i], sqrt ( mult ) );
                sprintf(buf1,",%s", DrobiToStr( dr ) );
                strcat(buf,buf1);
        }

        strcat(buf,")");
        plist->Add(strdup(buf));
  }
  else
  {
        if ( mvect[0] )
                sprintf(buf,"орт=!(%d/sqrt(%d)", mvect[0], mult );
        else
                sprintf(buf,"орт=!(0");

        for (i = 1; i < 3; i ++)
        {
                if ( mvect [i] )
                        sprintf(buf1,",%d/sqrt(%d)", mvect [i], mult );
                else
                        sprintf(buf1,",0" );
                strcat(buf,buf1);
        }

        strcat(buf,")");
        plist->Add(strdup(buf));
  }

  break;

  }

  if ( TypeQuest == 4 )
  {
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
                sprintf(buf,"String(Найти значение выражения.)");
                plist->Add(strdup(buf));
        }

  sprintf(buf,"_a=!(%d",ma[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",ma[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"_b=!(%d",mb[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",mb[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  //sprintf(buf,"!(%d*_a%+d*_b)*+!(%d*_a%+d*_b)=...", a, b, c, d);
  if ( abs( b ) != 1 )
        sprintf(buf,"!(%d*_a%+d*_b)*+", a, b );
  else
  {
        if ( b == -1 )
                sprintf(buf,"!(%d*_a-_b)*+", a );
        else
                sprintf(buf,"!(%d*_a+_b)*+", a );
  }

  if ( abs( d) != 1 )
  {
        sprintf(buf1,"!(%d*_a%+d*_b)=...", c, d );
        strcat ( buf, buf1 );
  }
  else
  {
        if ( d == -1 )
                sprintf(buf1,"!(%d*_a-_b)=...", c );
        else
                sprintf(buf1,"!(%d*_a+_b)=...", c);

        strcat ( buf, buf1 );
  }

  plist->Add(strdup(buf));

  sprintf(buf,"String(@Часть преподавателя )");
  plist->Add(strdup(buf));

  sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
  plist->Add(strdup(buf));

  sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
  plist->Add(strdup(buf));

  sprintf(buf,"_a=!(%d",ma[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",ma[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  sprintf(buf,"_b=!(%d",mb[0]);

  for( i = 1; i < 3; i ++ )
  {
        sprintf(buf1,",%d",mb[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

  //sprintf(buf,"!(%d*_a%+d*_b)*+!(%d*_a%+d*_b)=", a, b, c, d );
  if ( abs( b ) != 1 )
        sprintf(buf,"!(%d*_a%+d*_b)*+", a, b );
  else
  {
        if ( b == -1 )
                sprintf(buf,"!(%d*_a-_b)*+", a );
        else
                sprintf(buf,"!(%d*_a+_b)*+", a );
  }

  if ( abs( d) != 1 )
  {
        sprintf(buf1,"!(%d*_a%+d*_b)=", c, d );
        strcat ( buf, buf1 );
  }
  else
  {
        if ( d == -1 )
                sprintf(buf1,"!(%d*_a-_b)=", c );
        else
                sprintf(buf1,"!(%d*_a+_b)=", c);

        strcat ( buf, buf1 );
  }

  for (i = 0; i < 3; i ++)
  {
        k = 0;

        for (j = 0; j < 3; j ++)
        {
                if ( j != i)
                {
                        matr[0][k] = mc[j];
                        matr[1][k] = md[j];
                        k ++;
                }
        }

        mvect[i] = pow( -1, i ) * determ( 2, matr );
  }

  sprintf( buf1, "!(%d", mvect[0] );
  strcat(buf,buf1);

  for (i = 1; i < 3; i ++)
  {
        sprintf(buf1, ",%d", mvect[i]);
        strcat(buf,buf1);
  }

  strcat(buf,")");
  plist->Add(strdup(buf));

 }

  keygen = 0;

  delete buf;
  delete buf1;

  return 0;
}
//-----------------------------------------------------------

int determ( int dim, int ma[][2])
{
        int det;

        det = ma[0][0]*ma[1][1] - ma[0][1]*ma[1][0];

        return det;
}
//-----------------------------------------------------------

quest9::Print(TList* plist, class test &t)
{
        int i, j, k, ma[3], mb[3], mc[3], md[3], mvect[3], matr[2][2];
        int a = 0, b = 0, c = 0, d = 0;
        int mult;
        int n, Right_Numb;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        Right_Numb = random( 5 ) + 1;

        for( i = 0; i < 3; i ++ )
        {
                ma[i] = rgen( keygen, 1, amin, amax );
                mb[i] = rgen( keygen, 1, amin, amax );

                while( mb[i] == ma[i] )
                        mb[i] = rgen( keygen, 1, amin, amax );
        }

        if ( QuestType == 2 )
        {
                a = pow( -1, random ( 2 ) );
                b = random ( 4 ) + 1;

                for ( i = 0; i < 3; i ++)
                        mb[i] = a * b * ma[i];
        }

        a = 0;
        b = 0;

        while ( a <= 1 )
                a = rgen( keygen, 1, amin, amax );

        while ( b == 0 || b == a )
                b = rgen( keygen, 1, amin, amax );

        while ( c <= 1 )
                c = rgen( keygen, 1, amin, amax );

        while ( d == 0 || d == c || d == b )
                d = rgen( keygen, 1, amin, amax );

        if ( QuestType == 4 )
        {
                for ( i = 0; i < 3; i ++ )
                {
                        mc[i] = a * ma[i] + b * mb[i];
                        md[i] = c * ma[i] + d * mb[i];
                }
        }

        switch ( QuestType )
        {
                case 0:

                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти векторное произведение векторов.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                      sprintf( buf1, ",%d", ma[i] );
                      strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                      sprintf( buf1, ",%d", mb[i] );
                      strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a*+_b=..." );
                plist->Add( strdup(buf) );

                for (i = 0; i < 3; i ++)
                {
                        k = 0;

                        for (j = 0; j < 3; j ++)
                        {
                                if ( j != i)
                                {
                                        matr[0][k] = ma[j];
                                        matr[1][k] = mb[j];
                                        k ++;
                                }
                        }

                        mvect[i] = pow( -1, i ) * determ( 2, matr );
                }

                for ( n = 0; n < 5; n ++ )
                {
                      sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                      plist->Add( strdup(buf) );

                      sprintf( buf, "_a*+_b=!(" );

                      sprintf( buf1, "%d", mvect[0]  - ( Right_Numb - 1 ) + n );
                      strcat( buf, buf1 );

                      for (i = 1; i < 3; i ++)
                      {
                                sprintf( buf1, ",%d", mvect[i] - ( Right_Numb - 1 ) + n );
                                strcat( buf, buf1 );
                      }

                      strcat( buf, ")" );
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

        case 1:

                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вариант   %i, задача %i)", nvar, nzad );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти площадь параллелограмма построенного на векторах.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                      sprintf( buf1, ",%d", ma[i] );
                      strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "S=..." );
                plist->Add( strdup(buf) );

                for (i = 0; i < 3; i ++)
                {
                        k = 0;

                        for (j = 0; j < 3; j ++)
                        {
                                if ( j != i)
                                {
                                        matr[0][k] = ma[j];
                                        matr[1][k] = mb[j];
                                        k ++;
                                }
                        }

                        mvect[i] = pow( -1, i ) * determ( 2, matr );
                }

                mult = 0;

                for ( i = 0; i < 3; i ++ )
                        mult += mvect[i] * mvect [i];

                if( mult < 5 )
                        Right_Numb = 1;

                for ( n = 0; n < 5; n ++ )
                {
                        sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                        plist->Add( strdup(buf) );

                        /*if( Right_Numb != n - 1 )
                        {
                                k = random( 15 ) + 1;
                                if ( ceil ( sqrt ( mult + k )) == sqrt( mult + k ) )
                                        sprintf ( buf, "S=%f", sqrt( mult + k ) );
                                else
                                        sprintf ( buf, "S=sqrt(%d)", mult + k );
                        }
                        else
                        {
                                if ( ceil ( sqrt ( mult )) == sqrt( mult ) )
                                        sprintf ( buf, "S=%f", sqrt( mult ) );
                                else
                                        sprintf ( buf, "S=sqrt(%d)", mult );
                        }*/

                        if ( ceil ( sqrt ( mult - ( Right_Numb - 1 ) + n )) == sqrt( mult - ( Right_Numb - 1 ) + n ) )
                                sprintf ( buf, "S=%f", sqrt( mult - ( Right_Numb - 1 ) + n ) );
                        else
                                sprintf ( buf, "S=sqrt(%d)", mult - ( Right_Numb - 1 ) + n );

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

                drobi dr;

                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти орт для векторов.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "орт=..." );
                plist->Add( strdup(buf) );

                for (i = 0; i < 3; i ++)
                {
                        k = 0;

                        for (j = 0; j < 3; j ++)
                        {
                                if ( j != i)
                                {
                                        matr[0][k] = ma[j];
                                        matr[1][k] = mb[j];
                                        k ++;
                                }
                        }

                        mvect[i] = pow( -1, i ) * determ( 2, matr );
                }

                mult = 0;

                for ( i = 0; i < 3; i ++ )
                        mult += mvect[i] * mvect [i];

                for ( n = 0; n < 5; n ++ )
                {
                        sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                        plist->Add( strdup(buf) );

                        if ( ceil ( sqrt ( mult ) ) == sqrt ( mult ) )
                        {
                                dr = drobi( mvect[0] - ( Right_Numb - 1 ) + n, sqrt ( mult ) );
                                sprintf( buf, "орт=!(%s", DrobiToStr( dr ) );

                                for (i = 1; i < 3; i ++)
                                {
                                        dr = drobi( mvect[i] - ( Right_Numb - 1 ) + n, sqrt ( mult ) );
                                        sprintf( buf1, ",%s", DrobiToStr( dr ) );
                                        strcat( buf, buf1 );
                                }

                                strcat( buf, ")" );
                                plist->Add( strdup(buf) );
                        }
                        else
                        {
                                if ( mvect[0] - ( Right_Numb - 1 ) + n )
                                        sprintf( buf, "орт=!(%d/sqrt(%d)", mvect[0] - ( Right_Numb - 1 ) + n, mult );
                                else
                                        sprintf( buf, "орт=!(0" );

                                for (i = 1; i < 3; i ++)
                                {
                                        if ( mvect [i] - ( Right_Numb - 1 ) + n )
                                                sprintf( buf1, ",%d/sqrt(%d)", mvect [i] - ( Right_Numb - 1 ) + n, mult );
                                        else
                                                sprintf( buf1, ",0" );
                                        strcat( buf, buf1 );
                                }

                                strcat( buf, ")" );
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

                break;

        }

        if ( QuestType == 4 )
        {

                sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(Найти значение выражения.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_a=!(%d", ma[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", ma[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                sprintf( buf, "_b=!(%d", mb[0] );

                for( i = 1; i < 3; i ++ )
                {
                        sprintf( buf1, ",%d", mb[i] );
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );

                if ( abs( b ) != 1 )
                        sprintf( buf, "!(%d*_a%+d*_b)*+", a, b );
                else
                {
                        if ( b == -1 )
                                sprintf( buf, "!(%d*_a-_b)*+", a );
                        else
                                sprintf( buf, "!(%d*_a+_b)*+", a );
                }

                if ( abs( d) != 1 )
                {
                        sprintf( buf1, "!(%d*_a%+d*_b)=...", c, d );
                                strcat ( buf, buf1 );
                }
                else
                {
                        if ( d == -1 )
                                sprintf( buf1, "!(%d*_a-_b)=...", c );
                        else
                                sprintf( buf1, "!(%d*_a+_b)=...", c );

                        strcat ( buf, buf1 );
                }

                plist->Add( strdup(buf) );

                for (i = 0; i < 3; i ++)
                {
                        k = 0;

                        for (j = 0; j < 3; j ++)
                        {
                                if ( j != i )
                                {
                                        matr[0][k] = mc[j];
                                        matr[1][k] = md[j];
                                        k ++;
                                }
                        }

                        mvect[i] = pow( -1, i ) * determ( 2, matr );
                }

                for ( n = 0; n < 5; n ++ )
                {
                        sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                        plist->Add( strdup(buf) );

                        if ( abs( b ) != 1 )
                                sprintf( buf, "!(%d*_a%+d*_b)*+", a, b );
                        else
                        {
                                if ( b == -1 )
                                        sprintf( buf, "!(%d*_a-_b)*+", a );
                                else
                                        sprintf( buf, "!(%d*_a+_b)*+", a );
                        }

                        if ( abs( d) != 1 )
                        {
                                sprintf( buf1, "!(%d*_a%+d*_b)=", c, d );
                                strcat ( buf, buf1 );
                        }
                        else
                        {
                                if ( d == -1 )
                                        sprintf( buf1, "!(%d*_a-_b)=", c );
                                else
                                        sprintf( buf1, "!(%d*_a+_b)=", c );

                                strcat ( buf, buf1 );
                        }

                        sprintf( buf1, "!(%d", mvect[0]  - ( Right_Numb - 1 ) + n );
                        strcat( buf, buf1 );

                        for (i = 1; i < 3; i ++)
                        {
                                sprintf( buf1, ",%d", mvect[i]  - ( Right_Numb - 1 ) + n );
                                strcat( buf, buf1 );
                        }

                        strcat( buf, ")" );
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

