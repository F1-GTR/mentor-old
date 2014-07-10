//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest20.h"
#include "integral2.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

int mass[16];

quest20::quest20(FILE* f)
{
  char* buf = new char[256];
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

quest20::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest20::Edit()
{
  sscanf(strpar2,"%i%i",&a,&b);

  nvar = 1;
  keygen = 0;

  NeoInt->quest = this;
  NeoInt->Caption = "Нахождение неопределённых интегралов.";
  NeoInt->Edit1->Text = IntToStr(a);
  NeoInt->Edit2->Text = IntToStr(b);
  NeoInt->Edit3->Text = IntToStr(keygen);
  NeoInt->Edit4->Text = IntToStr(nvar);
  NeoInt->Edit5->Text = IntToStr(n);
  NeoInt->Edit6->Text = IntToStr(number);

  NeoInt->ShowModal();

  return 0;
}

quest20::Print(TList* plist)
{
  int a1,b1,n1;
  double t,t1;

  char* buf = new char[256];

  if( keygen == 0 )
  {
    while (keygen == 0)
     keygen = random(1000) + 1;
  }

  srand(keygen);

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
        sprintf(buf,"String(Найти неопределённый интеграл.)");
        plist->Add(strdup(buf));
  }

  a1 = random(a) + 2;
  b1 = random(b) + 2;
  n1 = random(n) + 2;

  switch(number)
  {
        case 0:
                n1 += 4;
                sprintf(buf,"Int((x*(%d*x^2+%d)^%d)*Diff(x))=...",a1,b1,n1);
                plist->Add(strdup(buf));
        break;
        case 1:
                sprintf(buf,"Int((x/((%d*x^2+%d)^2))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 2:
                sprintf(buf,"Int((x/((%d*x^2+%d)^%d))*Diff(x))=...",a1,b1,n1);
                plist->Add(strdup(buf));
        break;
        case 3:
                sprintf(buf,"Int((x/(%d*x^2+%d))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 4:
                sprintf(buf,"Int((x*.e^(%d*x^2+%d))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 5:
                sprintf(buf,"Int(x*.(sin!(%d*x^2+%d))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 6:
                sprintf(buf,"Int(x*.(cos!(%d*x^2+%d))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 7:
                sprintf(buf,"Int((x/cos!(%d*x^2+%d)^2)*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 8:
                sprintf(buf,"Int((x/sin!(%d*x^2+%d)^2)*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 9:
                sprintf(buf,"Int((x/(%d+%d*x^4))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 10:
                sprintf(buf,"Int((x/(%d-%d*x^4))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 11:
                sprintf(buf,"Int((x/(-%d+%d*x^4))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 12:
                sprintf(buf,"Int((x/(-%d-%d*x^4))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 13:
                sprintf(buf,"Int((x/sqrt(%d+%d*x^4))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 14:
                sprintf(buf,"Int((x/sqrt(-%d+%d*x^4))*Diff(x))=...",a1,b1);
                plist->Add(strdup(buf));
        break;
        case 15:
                sprintf(buf,"Int((x/sqrt(%d-%d*x^4))*Diff(x))=...",a1,b1);
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
                sprintf(buf,"Int((x*(%d*x^2+%d)^%d)*Diff(x))=((%d*x^2+%d)^(%d))/(2*%d)+C",a1,b1,n1,a1,b1,n1+1,a1*(n1+1));
                plist->Add(strdup(buf));
        break;
        case 1:
                sprintf(buf,"Int((x/((%d*x^2+%d)^2))*Diff(x))=-(1/(2*(%d*x^2+%d)))+C",a1,b1,a1*a1,b1*a1);
                plist->Add(strdup(buf));
        break;
        case 2:
                sprintf(buf,"Int((x/((%d*x^2+%d)^%d))*Diff(x))=-(1/(2*%d*(%d*x^2+%d)^%d))+C=(((%d*x^2+%d)^%d-%d*x^2-%d)*(pow(%d*x^2+%d,%d)))/(2*%d)+C",a1,b1,n1,a1*(n1-1),a1,b1,n1-1,a1,b1,n1,a1,b1,a1,b1,-n1,a1*(n1-1));
                plist->Add(strdup(buf));
        break;
        case 3:
                sprintf(buf,"Int((x/(%d*x^2+%d))*Diff(x))=ln(%d*x^2+%d)/(2*%d)+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 4:
                sprintf(buf,"Int((x*.e^(%d*x^2+%d))*Diff(x))=(e^(%d*x^2+%d)/(2*%d))+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 5:
                sprintf(buf,"Int(x*.(sin!(%d*x^2+%d))*Diff(x))=-(cos(%d*x^2+%d)/(2*%d))+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 6:
                sprintf(buf,"Int(x*.(cos!(%d*x^2+%d))*Diff(x))=sin(%d*x^2+%d)/(2*%d)+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 7:
                sprintf(buf,"Int((x/cos(%d*x^2+%d)^2)*Diff(x))=tg(%d*x^2+%d)/(2*%d)+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 8:
                sprintf(buf,"Int((x/sin(%d*x^2+%d)^2)*Diff(x))=-(ctg(%d*x^2+%d)/(2*%d))+C",a1,b1,a1,b1,a1);
                plist->Add(strdup(buf));
        break;
        case 9:
                t = ceil(sqrt(a1));
                t1 = ceil(sqrt(b1));

                if ( t == sqrt(a1) && t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/(%d+%d*x^4))*Diff(x))=(arctg(%f*x^2/%f)/(2*%f*%f)))+C",a1,b1,sqrt(b1),sqrt(a1),sqrt(a1),sqrt(b1));
                else
                if ( t == sqrt(a1) )
                        sprintf(buf,"Int((x/(%d+%d*x^4))*Diff(x))=(arctg(sqrt(%d)*x^2/%f)/(2*%f*sqrt(%d))))+C",a1,b1,b1,sqrt(a1),sqrt(a1),b1);
                else
                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/(%d+%d*x^4))*Diff(x))=(arctg(%f*x^2/sqrt(%d))/(2*sqrt(%d)*%f))+C",a1,b1,sqrt(b1),a1,a1,sqrt(b1));
                else
                        sprintf(buf,"Int((x/(%d+%d*x^4))*Diff(x))=(arctg(sqrt(%d)*x^2/sqrt(%d))/(2*sqrt(%d)*sqrt(%d)))+C",a1,b1,b1,a1,a1,b1);
                plist->Add(strdup(buf));
        break;
        case 10:
                t = ceil(sqrt(a1));
                t1 = ceil(sqrt(b1));

                if ( t == sqrt(a1) && t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/(%d-%d*x^4))*Diff(x))=-((ln((%f*x^2-%f)/(%f*x^2+%f)))/(2*2*%f*%f))+C",a1,b1,sqrt(b1),sqrt(a1),sqrt(b1),sqrt(a1),sqrt(a1),sqrt(b1));
                else
                if ( t == sqrt(a1) )
                        sprintf(buf,"Int((x/(%d-%d*x^4))*Diff(x))=-((ln((sqrt(%d)*x^2-%f)/(sqrt(%d)*x^2+%f)))/(2*2*%f*sqrt(%d)))+C",a1,b1,b1,sqrt(a1),b1,sqrt(a1),sqrt(a1),b1);
                else
                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/(%d-%d*x^4))*Diff(x))=-((ln((%f*x^2-sqrt(%d))/(%f*x^2+sqrt(%d))))/(2*2*sqrt(%d)*%f))+C",a1,b1,sqrt(b1),a1,sqrt(b1),a1,a1,sqrt(b1));
                else
                        sprintf(buf,"Int((x/(%d-%d*x^4))*Diff(x))=-((ln((sqrt(%d)*x^2-sqrt(%d))/(sqrt(%d)*x^2+sqrt(%d))))/(2*2*sqrt(%d)*sqrt(%d)))+C",a1,b1,b1,a1,b1,a1,a1,b1);
                plist->Add(strdup(buf));
        break;
        case 11:
                t = ceil(sqrt(a1));
                t1 = ceil(sqrt(b1));

                if ( t == sqrt(a1) && t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/(-%d+%d*x^4))*Diff(x))=((ln((%f*x^2-%f)/(%f*x^2+%f)))/(2*2*%f*%f))+C",a1,b1,sqrt(b1),sqrt(a1),sqrt(b1),sqrt(a1),sqrt(a1),sqrt(b1));
                else
                if ( t == sqrt(a1) )
                        sprintf(buf,"Int((x/(-%d+%d*x^4))*Diff(x))=((ln((sqrt(%d)*x^2-%f)/(sqrt(%d)*x^2+%f)))/(2*2*%f*sqrt(%d)))+C",a1,b1,b1,sqrt(a1),b1,sqrt(a1),sqrt(a1),b1);
                else
                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/(-%d+%d*x^4))*Diff(x))=((ln((%f*x^2-sqrt(%d))/(%f*x^2+sqrt(%d))))/(2*2*sqrt(%d)*%f))+C",a1,b1,sqrt(b1),a1,sqrt(b1),a1,a1,sqrt(b1));
                else
                        sprintf(buf,"Int((x/(-%d+%d*x^4))*Diff(x))=((ln((sqrt(%d)*x^2-sqrt(%d))/(sqrt(%d)*x^2+sqrt(%d))))/(2*2*sqrt(%d)*sqrt(%d)))+C",a1,b1,b1,a1,b1,a1,a1,b1);
                plist->Add(strdup(buf));
        break;
        case 12:
                t = ceil(sqrt(a1));
                t1 = ceil(sqrt(b1));

                if ( t == sqrt(a1) && t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/(-%d-%d*x^4))*Diff(x))=-((arctg(%f*x^2/%f)/(2*%f*%f))))+C",a1,b1,sqrt(b1),sqrt(a1),sqrt(a1),sqrt(b1));
                else
                if ( t == sqrt(a1) )
                        sprintf(buf,"Int((x/(-%d-%d*x^4))*Diff(x))=-((arctg(sqrt(%d)*x^2/%f)/(2*%f*sqrt(%d)))))+C",a1,b1,b1,sqrt(a1),sqrt(a1),b1);
                else
                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/(-%d-%d*x^4))*Diff(x))=-((arctg(%f*x^2/sqrt(%d))/(2*sqrt(%d)*%f)))+C",a1,b1,sqrt(b1),a1,a1,sqrt(b1));
                else
                        sprintf(buf,"Int((x/(-%d-%d*x^4))*Diff(x))=-((arctg(sqrt(%d)*x^2/sqrt(%d))/(2*sqrt(%d)*sqrt(%d))))+C",a1,b1,b1,a1,a1,b1);
                plist->Add(strdup(buf));
        break;
        case 13:
                t1 = ceil(sqrt(b1));

                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/sqrt(%d+%d*x^4))*Diff(x))=(ln(sqrt(%d*x^4+%d)+%f*x^2))/(2*%f)+C",a1,b1,b1,a1,sqrt(b1),sqrt(b1));
                else
                        sprintf(buf,"Int((x/sqrt(%d+%d*x^4))*Diff(x))=(ln(sqrt(%d*x^4+%d)+sqrt(%d)*x^2))/(2*sqrt(%d))+C",a1,b1,b1,a1,b1,b1);
                plist->Add(strdup(buf));
        break;
        case 14:
                t1 = ceil(sqrt(b1));

                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/sqrt(-%d+%d*x^4))*Diff(x))=(ln(sqrt(%d*x^4-%d)+%f*x^2))/(2*%f)+C",a1,b1,b1,a1,sqrt(b1),sqrt(b1));
                else
                        sprintf(buf,"Int((x/sqrt(-%d+%d*x^4))*Diff(x))=(ln(sqrt(%d*x^4-%d)+sqrt(%d)*x^2))/(2*sqrt(%d))+C",a1,b1,b1,a1,b1,b1);
                plist->Add(strdup(buf));
        break;
        case 15:
                t = ceil(sqrt(a1));
                t1 = ceil(sqrt(b1));

                if ( t == sqrt(a1) && t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/sqrt(%d-%d*x^4))*Diff(x))=(1/(2*%f))*arcsin((%f/%f)*x^2)+C",a1,b1,sqrt(b1),sqrt(b1),sqrt(a1));
                else
                if ( t == sqrt(a1) )
                        sprintf(buf,"Int((x/sqrt(%d-%d*x^4))*Diff(x))=(1/(2*sqrt(%d)))*arcsin((sqrt(%d)/%f)*x^2)+C",a1,b1,b1,b1,sqrt(a1));
                else
                if ( t1 == sqrt(b1) )
                        sprintf(buf,"Int((x/sqrt(%d-%d*x^4))*Diff(x))=(1/(2*%f))*arcsin((%f/sqrt(%d))*x^2)+C",a1,b1,sqrt(b1),sqrt(b1),a1);
                else
                        sprintf(buf,"Int((x/sqrt(%d-%d*x^4))*Diff(x))=(1/(2*sqrt(%d)))*arcsin((sqrt(%d)/sqrt(%d))*x^2)+C",a1,b1,b1,b1,a1);
                plist->Add(strdup(buf));
        break;
  }

  keygen = 0;

  delete buf;

  return 0;
}
//------------------------------------------------------------------------------

quest20::Print(TList* plist, class test &t)
{
}
//-----------------------------------------------------------


