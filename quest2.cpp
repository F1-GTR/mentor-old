//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include "quest2.h"
#include "matumn.h"
#include "qvarnt.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#include "test_class.h"
#include "unit1.h"
#pragma hdrstop
//---------------------------------------------------------------------------
//������������ ������
#pragma package(smart_init)

//��������� �����, ���� was = True - ���� ���������, ���� ��� - ����� +
//��� ������ Was ���������� � False
int sign(bool &was)
{
        if (was)
        {
                int RD = random(10);
                if (RD >= 3)
                {
                        return 1;
                }
                else
                {
                        was = false;
                        return -1;
                }
        }
        else
        {
                return -1;
        }

}
int sign()
{
       int RD = random(10);
       char buff[10];
       if (RD >= 3)
       {
              return 1;
       }
       else
       {
                return -1;
       }

}

//��������� � ����, ���� was = True - ������� ���������, ���� ��� - ����� 1
//��� ���� Was ���������� � False
int zero(bool &was)
{
        if (was)
        {
               int RD = random(10);

                if (RD%2 == 0)
                {
                        return 1;
                }
                else
                {
                        was = false;
                        return 0;
                }
        }
        else
        {
                return 1;
        }

}

int zero()
{
   int RD = random(10);
   if (RD%2 == 0)
   {
           return 1;
   }
   else
   {
         return 0;
   }

}

quest2::quest2(FILE* f)
{
  char* buf = new char[256];

  //randomize();
  keygen = 0;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);
  qtype = MATMULT;

  delete buf;
}

quest2::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest2::Edit()
{
  sscanf(strpar1,"%i%i%i",&kstrok,&kstolb,&amin);
  sscanf(strpar2,"%i%i",&amax,&keygen);

  nvar = 1;
  keygen = 0;

  pmatumn->quest = (quest2*)this;
  pmatumn->Edit1->Text = IntToStr(kstrok);
  pmatumn->Edit2->Text = IntToStr(kstolb);
  pmatumn->Edit3->Text = IntToStr(amin);
  pmatumn->Edit4->Text = IntToStr(amax);
  pmatumn->Edit5->Text = IntToStr(keygen);
  pmatumn->Edit6->Text = IntToStr(nvar);
  pmatumn->ShowModal();

  return 0;
}

quest2::Print(TList* plist)
{
  int ma[15][15];
  int mb[15][15];
  int mc[15][15];
  int i, j, k;

  bool wZero = true;

  sscanf( strpar1, "%i%i%i", &kstrok, &kstolb, &amin );
  sscanf( strpar2, "%i", &amax );

  if( keygen == 0 )
  {
        keygen = random( 1000 ) + 1;
  }

  srand( keygen );

  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstolb; j ++ )
        {
                //������ ���� ���� � �������
                ma[i][j] = sign()*zero(wZero)*(1+abs(amin + random( amax - amin + 1 )));
                mb[j][i] = sign()*zero(wZero)*(1+abs(amin + random( amax - amin + 1 )));
        }
  }

  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstrok; j ++ )
        {
                mc[i][j]=0;

        for( k = 0; k < kstolb; k ++ )
        {
                mc[i][j] = mc[i][j] + ma[i][k] * mb[j][k];
        }
        }
  }

  char* buf = new char[256];
  char* buf1 = new char[256];

  if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
  {
        sprintf( buf, "String(\"# ���� - %s \")", selecttask->name );
        plist->Add( strdup(buf) );
  }
  else
  {
        sprintf( buf, "String(#)" );
        plist->Add( strdup(buf) );
  }

  sprintf( buf, "String(�������   %i, ������ %i.)", nvar, nzad );
  plist->Add( strdup(buf) );

  if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
  {
        plist->Add( strdup("String( ����� ������������ ������. )") );
  }

  sprintf( buf, "!(Matrix(%i,%i", kstolb, kstrok );

  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstolb; j ++ )
        {
                sprintf( buf1, ",%i", ma[i][j] );
                strcat( buf, buf1 );
        }
  }

  strcat( buf, "))*." );
  sprintf( buf1, "!(Matrix(%i,%i", kstrok, kstolb );
  strcat( buf, buf1 );

  if ( kstrok == kstolb )
  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstolb; j ++ )
        {
                sprintf( buf1, ",%i", mb[j][i] );
                strcat( buf, buf1 );
        }
  }
  else
  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstolb; j ++ )
        {
                sprintf( buf1, ",%i", mb[i][j] );
                strcat( buf, buf1 );
        }
  }

  strcat( buf, "))=..." );
  plist->Add( strdup(buf) );

/*  sprintf(buf,"String(___________________________________________)");
  plist->Add(strdup(buf));*/

  sprintf( buf, "String(@����� ������������� )" );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(\"���� - %s \")", selecttask->name );
  plist->Add( strdup(buf) );

  sprintf( buf, "String(�������   %i, ������� ������ %i, ���� %i)", nvar, nzad, keygen );
  plist->Add( strdup(buf) );

  sprintf( buf, "!(Matrix(%i,%i", kstrok, kstrok );
  for( i = 0; i < kstrok; i ++ )
  {
        for( j = 0; j < kstrok; j ++ )
        {
                sprintf( buf1, ",%i", mc[i][j] );
                strcat( buf, buf1 );
        }
  }

  strcat( buf, "))" );
  plist->Add( strdup(buf) );

  keygen = 0;

  delete buf;
  delete buf1;

  return 0;
}
//---------------------------------------------------------------------------

quest2::Print(TList* plist, class test &t)
{
        int ma[15][15];
        int mb[15][15];
        int mc[15][15];
        int i, j, k;
        int n, Right_Numb;
        bool wZero = true;

        sscanf( strpar1, "%i%i%i", &kstrok, &kstolb, &amin );
        sscanf( strpar2, "%i", &amax );

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        Right_Numb = random( 5 ) + 1;

        for( i = 0; i < kstrok; i ++ )
        {
                for( j = 0; j < kstolb; j ++ )
                {
                        ma[i][j] = sign()*zero(wZero)*(1+abs(amin + random( amax - amin + 1 )));
                        mb[j][i] = sign()*zero(wZero)*(1+abs(amin + random( amax - amin + 1 )));
                }
        }

        for( i = 0; i < kstrok; i ++ )
        {
                for( j = 0; j < kstrok; j ++ )
                {
                        mc[i][j]=0;

                        for( k = 0; k < kstolb; k ++ )
                        {
                                mc[i][j] = mc[i][j] + ma[i][k] * mb[j][k];
                        }
                }
        }

        char* buf = new char[256];
        char* buf1 = new char[256];

        sprintf( buf, "String(\"# ���� - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(�������   %i, ������ %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        plist->Add( strdup( "String( ����� ������������ ������. )" ) );

        sprintf( buf, "!(Matrix(%i,%i", kstolb, kstrok );
        for( i = 0; i < kstrok; i ++ )
        {
                for( j = 0; j < kstolb; j ++ )
                {
                        sprintf( buf1, ",%i", ma[i][j] );
                        strcat( buf, buf1 );
                }
        }

        strcat( buf, "))*." );
        sprintf( buf1,"!(Matrix(%i,%i", kstrok, kstolb );
        strcat( buf, buf1 );

        if ( kstrok == kstolb )
        for( i = 0; i < kstrok; i ++ )
        {
                for( j = 0; j < kstolb; j ++ )
                {
                        sprintf( buf1, ",%i", mb[j][i] );
                        strcat( buf, buf1 );
                }
        }
        else
        for( i = 0; i < kstrok; i ++ )
        {
                for( j = 0; j < kstolb; j ++ )
                {
                        sprintf( buf1, ",%i", mb[i][j] );
                        strcat( buf, buf1 );
                }
        }

        strcat( buf, "))=..." );
        plist->Add( strdup(buf) );

        for ( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"������� %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                sprintf( buf, "!(Matrix(%i,%i", kstrok, kstrok );
                for( i = 0; i < kstrok; i ++ )
                {
                        for( j = 0; j < kstrok; j ++ )
                        {
                                if ( n != Right_Numb - 1 )
                                        sprintf( buf1, ",%i", mc[i][j] + ( random ( 20 ) - 10 ) );
                                else
                                        sprintf( buf1,",%i", mc[i][j] );
                                strcat( buf, buf1 );
                        }
                }

                strcat( buf, "))" );
                plist->Add( strdup(buf) );
        }

        /*sprintf(buf,"String(@����� ������������� )");
        plist->Add(strdup(buf));

        sprintf(buf,"String(\"���� - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(�������   %i, ������� ������ %i, ���� %i)",nvar,nzad,keygen);
        plist->Add(strdup(buf));

        sprintf(buf,"String( ���������� ����� - %c)", 'a' + Right_Numb - 1 );
        plist->Add(strdup(buf));*/

        t.pr_tst = 1;
        t.ch_ask = 5;
        t.right_ask = Right_Numb;
        t.msg = "���� ������� ������������.";

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//---------------------------------------------------------------------------


