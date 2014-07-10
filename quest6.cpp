//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest6.h"
#include "integral.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

int mass[16];

quest6::quest6(FILE* f)
{
  char * buf = new char[256];
  int count = 0;

  randomize();
  keygen = random (1000) + 1;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);

  sscanf(strpar1,"%d %d %d",&a,&b,&n);
  qtype = INTEGRAL;

  number = random(16);

  while ( mass[number] == 1 )
  {
        if ( count > 30 )
        {
                for ( int i = 0; i < 16; i++)
                        mass[i] = 0;
                count == 0;
                break;
        }

        number = random(16);

        count ++;
  }

  mass[number] = 1;
}

quest6::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest6::Edit()
{
  sscanf(strpar2,"%i%i",&a,&b);

  keygen = 0;
  nvar = 1;

  OprInt->quest = this;
  OprInt->Caption = "Нахождение неопределённых интегралов.";
  OprInt->Edit1->Text = IntToStr(a);
  OprInt->Edit2->Text = IntToStr(b);
  OprInt->Edit3->Text = IntToStr(keygen);
  OprInt->Edit4->Text = IntToStr(nvar);
  OprInt->Edit5->Text = IntToStr(n);
  OprInt->Edit6->Text = IntToStr(number);

  OprInt->ShowModal();

  return 0;
}

quest6::Print(TList* plist)
{
  int a1, b1, n1;
  double t, t1;

  char* buf = new char[256];

  if( keygen == 0 )
  {
        keygen = random( 1000 ) + 1;
  }

/*  number = random(16);

  while ( mass[number] == 1)
  {
        if ( count > 30 )
        {
                count = 0;

                break;
        }

        number = random(16);

        count ++;
  }

  mass[number] = 1;

  keygen = StrToInt( OprInt->Edit3->Text );*/
  srand( keygen );

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

  sprintf( buf, "String(Вариант   %i, задача %i. )", nvar, nzad );
  plist->Add( strdup(buf) );

  if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
  {
        sprintf( buf, "String(Найти неопределённый интеграл.)" );
        plist->Add( strdup(buf) );
  }

  a1 = random( a ) + 2;
  b1 = random( b ) + 2;
  n1 = random( n ) + 2;

  switch( number )
  {
        case 0:
                n1 += 4;
                sprintf(buf,"Int(((%d*x+%d)^%d)*Diff(x))=...",a1,b1,n1);
                plist->Add(strdup(buf));
        break;
        case 1:
                sprintf(buf,"Int((1/((%d*x+%d)^2))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 2:
                sprintf(buf,"Int((1/((%d*x+%d)^%d))*Diff(x))=...",a1,b1,n1);
                plist->Add(strdup(buf));
        break;
        case 3:
                sprintf(buf,"Int((1/(%d*x+%d))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 4:
                sprintf(buf,"Int((e^(%d*x+%d))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 5:
                sprintf(buf,"Int((sin(%d*x+%d))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 6:
                sprintf(buf,"Int((cos(%d*x+%d))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 7:
                sprintf(buf,"Int((1/cos(%d*x+%d)^2)*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 8:
                sprintf(buf,"Int((1/sin(%d*x+%d)^2)*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 9:
                sprintf(buf,"Int((1/(%d+%d*x^2))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 10:
                sprintf(buf,"Int((1/(%d-%d*x^2))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 11:
                sprintf(buf,"Int((1/(-%d+%d*x^2))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 12:
                sprintf(buf,"Int((1/(-%d-%d*x^2))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 13:
                sprintf(buf,"Int((1/sqrt(%d+%d*x^2))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 14:
                sprintf(buf,"Int((1/sqrt(-%d+%d*x^2))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 15:
                sprintf(buf,"Int((1/sqrt(%d-%d*x^2))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
  }

  sprintf(buf,"String(@Часть преподавателя )");
  plist->Add(strdup(buf));

  sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
  plist->Add(strdup(buf));

  sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
  plist->Add(strdup(buf));

  switch(number)
  {
        case 0:
                sprintf(buf,"Int(((%d*x+%d)^%d)*Diff(x))=((%d*x+%d)^(%d))/(%d)+C",a1,b1,n1,a1,b1,n1+1,a1*(n1+1));
                plist->Add(strdup(buf));
        break;
        case 1:
                sprintf(buf,"Int((1/((%d*x+%d)^2))*Diff(x))=-(1/(%d*x+%d))+C",a1,b1,a1*a1,b1*a1);
                plist->Add(strdup(buf));
        break;
        case 2:
                sprintf(buf,"Int((1/((%d*x+%d)^%d))*Diff(x))=-(1/(%d*(%d*x+%d)^%d))+C=(((%d*x+%d)^%d-%d*x-%d)*(pow(%d*x+%d,%d)))/%d+C",a1,b1,n1,a1*(n1-1),a1,b1,n1-1,a1,b1,n1,a1,b1,a1,b1,-n1,a1*(n1-1));
                plist->Add(strdup(buf));
        break;
        case 3:
                sprintf(buf,"Int((1/(%d*x+%d))*Diff(x))=ln(%d*x+%d)/%d+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 4:
                sprintf(buf,"Int((e^(%d*x+%d))*Diff(x))=(e^(%d*x+%d)/%d)+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 5:
                sprintf(buf,"Int((sin(%d*x+%d))*Diff(x))=-(cos(%d*x+%d)/%d)+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 6:
                sprintf(buf,"Int((cos(%d*x+%d))*Diff(x))=sin(%d*x+%d)/%d+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 7:
                sprintf(buf,"Int((1/cos(%d*x+%d)^2)*Diff(x))=tg(%d*x+%d)/%d+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 8:
                sprintf(buf,"Int((1/sin(%d*x+%d)^2)*Diff(x))=-(ctg(%d*x+%d)/%d)+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 9:
                t = ceil(sqrt(a1));
                t1 = ceil(sqrt(b1));

                if ( t == sqrt(a1) && t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/(%d+%d*x^2))*Diff(x))=(arctg(%f*x/%f)/(%f*%f)))+C",a1,b1,sqrt(b1),sqrt(a1),sqrt(a1),sqrt(b1));
                else
                if ( t == sqrt(a1) )
                        sprintf(buf,"Int((1/(%d+%d*x^2))*Diff(x))=(arctg(sqrt(%d)*x/%f)/(%f*sqrt(%d))))+C",a1,b1,b1,sqrt(a1),sqrt(a1),b1);
                else
                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/(%d+%d*x^2))*Diff(x))=(arctg(%f*x/sqrt(%d))/(sqrt(%d)*%f))+C",a1,b1,sqrt(b1),a1,a1,sqrt(b1));
                else
                        sprintf(buf,"Int((1/(%d+%d*x^2))*Diff(x))=(arctg(sqrt(%d)*x/sqrt(%d))/(sqrt(%d)*sqrt(%d)))+C",a1,b1,b1,a1,a1,b1);
                plist->Add(strdup(buf));
        break;
        case 10:
                t = ceil(sqrt(a1));
                t1 = ceil(sqrt(b1));

                if ( t == sqrt(a1) && t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/(%d-%d*x^2))*Diff(x))=-((ln((%f*x-%f)/(%f*x+%f)))/(2*%f*%f))+C",a1,b1,sqrt(b1),sqrt(a1),sqrt(b1),sqrt(a1),sqrt(a1),sqrt(b1));
                else
                if ( t == sqrt(a1) )
                        sprintf(buf,"Int((1/(%d-%d*x^2))*Diff(x))=-((ln((sqrt(%d)*x-%f)/(sqrt(%d)*x+%f)))/(2*%f*sqrt(%d)))+C",a1,b1,b1,sqrt(a1),b1,sqrt(a1),sqrt(a1),b1);
                else
                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/(%d-%d*x^2))*Diff(x))=-((ln((%f*x-sqrt(%d))/(%f*x+sqrt(%d))))/(2*sqrt(%d)*%f))+C",a1,b1,sqrt(b1),a1,sqrt(b1),a1,a1,sqrt(b1));
                else
                        sprintf(buf,"Int((1/(%d-%d*x^2))*Diff(x))=-((ln((sqrt(%d)*x-sqrt(%d))/(sqrt(%d)*x+sqrt(%d))))/(2*sqrt(%d)*sqrt(%d)))+C",a1,b1,b1,a1,b1,a1,a1,b1);
                plist->Add(strdup(buf));
        break;
        case 11:
                t = ceil(sqrt(a1));
                t1 = ceil(sqrt(b1));

                if ( t == sqrt(a1) && t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/(-%d+%d*x^2))*Diff(x))=((ln((%f*x-%f)/(%f*x+%f)))/(2*%f*%f))+C",a1,b1,sqrt(b1),sqrt(a1),sqrt(b1),sqrt(a1),sqrt(a1),sqrt(b1));
                else
                if ( t == sqrt(a1) )
                        sprintf(buf,"Int((1/(-%d+%d*x^2))*Diff(x))=((ln((sqrt(%d)*x-%f)/(sqrt(%d)*x+%f)))/(2*%f*sqrt(%d)))+C",a1,b1,b1,sqrt(a1),b1,sqrt(a1),sqrt(a1),b1);
                else
                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/(-%d+%d*x^2))*Diff(x))=((ln((%f*x-sqrt(%d))/(%f*x+sqrt(%d))))/(2*sqrt(%d)*%f))+C",a1,b1,sqrt(b1),a1,sqrt(b1),a1,a1,sqrt(b1));
                else
                        sprintf(buf,"Int((1/(-%d+%d*x^2))*Diff(x))=((ln((sqrt(%d)*x-sqrt(%d))/(sqrt(%d)*x+sqrt(%d))))/(2*sqrt(%d)*sqrt(%d)))+C",a1,b1,b1,a1,b1,a1,a1,b1);
                plist->Add(strdup(buf));
        break;
        case 12:
                t = ceil(sqrt(a1));
                t1 = ceil(sqrt(b1));

                if ( t == sqrt(a1) && t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/(-%d-%d*x^2))*Diff(x))=-((arctg(%f*x/%f)/(%f*%f))))+C",a1,b1,sqrt(b1),sqrt(a1),sqrt(a1),sqrt(b1));
                else
                if ( t == sqrt(a1) )
                        sprintf(buf,"Int((1/(-%d-%d*x^2))*Diff(x))=-((arctg(sqrt(%d)*x/%f)/(%f*sqrt(%d)))))+C",a1,b1,b1,sqrt(a1),sqrt(a1),b1);
                else
                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/(-%d-%d*x^2))*Diff(x))=-((arctg(%f*x/sqrt(%d))/(sqrt(%d)*%f)))+C",a1,b1,sqrt(b1),a1,a1,sqrt(b1));
                else
                        sprintf(buf,"Int((1/(-%d-%d*x^2))*Diff(x))=-((arctg(sqrt(%d)*x/sqrt(%d))/(sqrt(%d)*sqrt(%d))))+C",a1,b1,b1,a1,a1,b1);
                plist->Add(strdup(buf));
        break;
        case 13:
                t1 = ceil(sqrt(b1));

                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/sqrt(%d+%d*x^2))*Diff(x))=(ln(sqrt(%d*x^2+%d)+%f*x))/(%f)+C",a1,b1,b1,a1,sqrt(b1),sqrt(b1));
                else
                        sprintf(buf,"Int((1/sqrt(%d+%d*x^2))*Diff(x))=(ln(sqrt(%d*x^2+%d)+sqrt(%d)*x))/(sqrt(%d))+C",a1,b1,b1,a1,b1,b1);
                plist->Add(strdup(buf));
        break;
        case 14:
                t1 = ceil(sqrt(b1));

                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/sqrt(-%d+%d*x^2))*Diff(x))=(ln(sqrt(%d*x^2-%d)+%f*x))/(%f)+C",a1,b1,b1,a1,sqrt(b1),sqrt(b1));
                else
                        sprintf(buf,"Int((1/sqrt(-%d+%d*x^2))*Diff(x))=(ln(sqrt(%d*x^2-%d)+sqrt(%d)*x))/(sqrt(%d))+C",a1,b1,b1,a1,b1,b1);
                plist->Add(strdup(buf));
        break;
        case 15:
                t = ceil(sqrt(a1));
                t1 = ceil(sqrt(b1));

                if ( t == sqrt(a1) && t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/sqrt(%d-%d*x^2))*Diff(x))=(1/%f)*arcsin((%f/%f)*x)+C",a1,b1,sqrt(b1),sqrt(b1),sqrt(a1));
                else
                if ( t == sqrt(a1) )
                        sprintf(buf,"Int((1/sqrt(%d-%d*x^2))*Diff(x))=(1/sqrt(%d))*arcsin((sqrt(%d)/%f)*x)+C",a1,b1,b1,b1,sqrt(a1));
                else
                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((1/sqrt(%d-%d*x^2))*Diff(x))=(1/%f)*arcsin((%f/sqrt(%d))*x)+C",a1,b1,sqrt(b1),sqrt(b1),a1);
                else
                        sprintf(buf,"Int((1/sqrt(%d-%d*x^2))*Diff(x))=(1/sqrt(%d))*arcsin((sqrt(%d)/sqrt(%d))*x)+C",a1,b1,b1,b1,a1);
                plist->Add(strdup(buf));
        break;
  }

  keygen = 0;

  delete buf;

  return 0;
}
//-----------------------------------------------------------

quest6::Print(TList* plist, class test &t)
{
}
//-----------------------------------------------------------


