//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <stdlib.h>
#include "quest30.h"
#include "matlin.h"
#include "qvarnt.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

quest30::quest30(FILE* f)
{
  char* buf = new char[256];

  randomize();
  keygen = random (1000) + 1;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);
  qtype = LIM;

  delete buf;
}

quest30::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest30::Edit()
{
  sscanf(strpar1,"%i%i%i",&amin,&amax,&amin);
  sscanf(strpar2,"%i%i",&amax,&keygen);

  keygen = 0;
  nvar = 1;

  return 0;
}

quest30::Print(TList* plist)
{
        int Right_Numb;
        int a, b;
        int i, j, n,temp1,temp2,vtype;
        int chis[10],znam[10],variants[10],Nvarint;
        float sd;
        AnsiString zadanie,otvet;
        Randomize;
        if( keygen == 0 )
        {
                keygen = random(1000) + 1;
        }

        Right_Numb = random( 5 ) + 1;

        srand( keygen );
        Nvarint=6;
        variants[0]=20;
        variants[1]=20;
        variants[2]=20;
        variants[3]=20;
        variants[4]=10;
        variants[5]=10;


        char* buf = new char[256];
        char* buf1 = new char[256];

        sprintf(buf,"String(\"# Тема - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add(strdup(buf));

        plist->Add(strdup("String( Вычислить предел.)"));
//s1 - type
        temp1=random(100)+1;
        temp2=0;
        for (n=0;n<Nvarint;n++)
                {
                temp2+=variants[n];
                if (temp2>temp1) {vtype=n;break;}
                }
vtype=1;
//s2 reshenie
if (vtype==1)
        {
        chis[2]=0;rgen( keygen, 0, amin, amax );
        chis[1]=random(12)-6;
        chis[0]=random(20)-10;
        znam[0]=random(20)-10;
        znam[1]=random(20)-10;
        znam[2]=random(20)-10;
        zadanie="Lim(x->0,(";
        zadanie=zadanie+IntToStr(chis[1])+"*x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"*Pow(x,2)+"+IntToStr(znam[1])+"*x+"+IntToStr(znam[0])+"))";
        plist->Add(strdup(zadanie.c_str()));
        for ( n = 0; n < 5; n ++ )
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "%d", chis[0]/znam[0]);}
               else
                        {
                         temp1=random(5);
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", random(10)/(random(18)-9) );
                        }
                plist->Add(strdup(buf));
        }}
if (vtype==2)
        {
        chis[2]=0;
        chis[1]=random(12)-6;
        chis[0]=random(20)-10;
        znam[0]=random(20)-10;
        znam[1]=random(20)-10;
        znam[2]=random(20)-10;
        zadanie="Lim(x->Inf,(";
        zadanie=zadanie+IntToStr(chis[1])+"x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"Pow(x,2)+"+IntToStr(znam[1])+"x+"+IntToStr(znam[0])+")";
         plist->Add(strdup(zadanie.c_str()));
                for ( n = 0; n < 5; n ++ )
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "0");}
               else
                        {
                         temp1=random(20)-10;
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", temp1);
                        }
                plist->Add(strdup(buf));

        }}
if (vtype==3)
        {
        chis[2]=0;
        chis[1]=random(20)-10;
        chis[0]=(random(10)-5)*chis[1];
        temp1=random(20)-10;
        temp2=random(20)-10;
        znam[0]=chis[0]*temp2;
        znam[1]=temp2*chis[1]+chis[0]*temp1;
        znam[2]=temp1*chis[1];
        zadanie="Lim(x->"+IntToStr(-(chis[0]/chis[1]))+",(";
        zadanie=zadanie+IntToStr(chis[1])+"x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"Pow(x,2)+"+IntToStr(znam[1])+"x+"+IntToStr(znam[0])+")";
         plist->Add(strdup(zadanie.c_str()));
        sd=1./float(-temp1*chis[0]/chis[b]+temp2);
        for ( n = 0; n < 5; n ++ )
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "%d", sd);}
               else
                        {
                         temp1=random(10)-5;
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", 1/float(temp1+random(8)-5));
                        }
                plist->Add(strdup(buf));

        }
        }
if (vtype==4)
        {
        chis[2]=0;
        chis[1]=random(12)-6;
        chis[0]=random(20)-10;
        znam[0]=random(20)-10;
        znam[1]=random(20)-10;
        znam[2]=random(20)-10;
        temp1=random(20)-10;
        zadanie="Lim(x->"+IntToStr(temp1)+",(";
        zadanie=zadanie+IntToStr(chis[1])+"x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"Pow(x,2)+"+IntToStr(znam[1])+"x+"+IntToStr(znam[0])+")";
         plist->Add(strdup(zadanie.c_str()));
        sd=float(chis[1]*temp1+chis[0])/float(znam[2]*temp1*temp1+znam[1]*temp1+znam[0]);
        for ( n = 0; n < 5; n ++ )
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "%d",sd);}
               else
                        {
                         temp1=random(20)-10;
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", float(temp1)/float(random(25)-12));
                        }
                plist->Add(strdup(buf));

        }
        }
if (vtype==5)
        {
        chis[2]=random(12)-6;
        chis[1]=random(12)-6;
        chis[0]=random(20)-10;
        znam[0]=random(20)-10;
        znam[1]=random(20)-10;
        znam[2]=random(20)-10;
        temp1=random(20)-10;
        zadanie="Lim(x->"+IntToStr(temp1)+",(";
        zadanie=zadanie+IntToStr(chis[2])+"Pow(x,2)+"+IntToStr(chis[1])+"x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"Pow(x,2)+"+IntToStr(znam[1])+"x+"+IntToStr(znam[0])+")";
         plist->Add(strdup(zadanie.c_str()));
        sd=float(chis[2]*temp1*temp1+chis[1]*temp1+chis[0])/float(znam[2]*temp1*temp1+znam[1]*temp1+znam[0]);
        for ( n = 0; n < 5; n++)
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "%d",sd);}
               else
                        {
                         temp1=random(10)-10;
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", float(temp1)/float(random(18)-10));
                        }
                plist->Add(strdup(buf));

        }
        }
if (vtype==6)
        {
        chis[2]=random(12)-6;
        chis[1]=random(12)-6;
        chis[0]=random(20)-10;
        znam[0]=random(20)-10;
        znam[1]=random(20)-10;
        znam[2]=random(20)-10;
        zadanie="Lim(x->Inf,(";
        zadanie=zadanie+IntToStr(chis[2])+"Pow(x,2)+"+IntToStr(chis[1])+"x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"Pow(x,2)+"+IntToStr(znam[1])+"x+"+IntToStr(znam[0])+")";
         plist->Add(strdup(zadanie.c_str()));
        sd=float(chis[2])/float(znam[2]);
        for ( n = 0; n < 5; n++)
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "%d",sd);}
               else
                        {
                         temp1=random(10)-10;
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", float(temp1)/float(random(18)-10));
                        }
                plist->Add(strdup(buf));

        }
        }

        FILE * out = fopen( "text.txt", "wt" );
        fprintf( out, "%d\n", vtype );
        for( i = 0; i < plist->Count; i ++ )
                fprintf( out, "%s\n", (char *)plist->Items[i] );

        fclose( out );

        /*sprintf(buf,"String(@Часть преподавателя )");
        plist->Add(strdup(buf));

        sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)",nvar,nzad,keygen);
        plist->Add(strdup(buf));

        sprintf(buf,"String( Правильный ответ - %c)", 'a' + Right_Numb - 1 );
        plist->Add(strdup(buf));*/

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//--------------------------------------------------------

quest30::Print(TList* plist, class test &t)
{
        int Right_Numb;
        int a, b;
        int i, j, n,temp1,temp2,vtype;
        int chis[10],znam[10],variants[10],Nvarint;
        float sd;
        AnsiString zadanie,otvet;
        Randomize;
        if( keygen == 0 )
        {
                keygen = random(1000) + 1;
        }

        Right_Numb = random( 5 ) + 1;

        srand( keygen );
        Nvarint=6;
        variants[0]=20;
        variants[1]=20;
        variants[2]=20;
        variants[3]=20;
        variants[4]=10;
        variants[5]=10;


        char* buf = new char[256];
        char* buf1 = new char[256];

        sprintf(buf,"String(\"# Тема - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add(strdup(buf));

        plist->Add(strdup("String( Вычислить предел.)"));
//s1 - type
        temp1=random(100)+1;
        temp2=0;
        for (n=0;n<Nvarint;n++)
                {
                temp2+=variants[n];
                if (temp2>temp1) {vtype=n;break;}
                }
//s2 reshenie
if (vtype==1)
        {
        chis[2]=0;
        chis[1]=random(12)-6;
        chis[0]=random(20)-10;
        znam[0]=random(20)-10;
        znam[1]=random(20)-10;
        znam[2]=random(20)-10;
        zadanie="Lim(x->0,(";
        zadanie=zadanie+IntToStr(chis[1])+"x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"*Pow(x,2)+"+IntToStr(znam[1])+"x+"+IntToStr(znam[0])+")";
         plist->Add(strdup(zadanie.c_str()));
        for ( n = 0; n < 5; n ++ )
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "%d", chis[0]/znam[0]);}
               else
                        {
                         temp1=random(5);
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", random(10)/(random(18)-9) );
                        }
                plist->Add(strdup(buf));
        }}
if (vtype==2)
        {
        chis[2]=0;
        chis[1]=random(12)-6;
        chis[0]=random(20)-10;
        znam[0]=random(20)-10;
        znam[1]=random(20)-10;
        znam[2]=random(20)-10;
        zadanie="Lim(x->Inf,(";
        zadanie=zadanie+IntToStr(chis[1])+"x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"Pow(x,2)+"+IntToStr(znam[1])+"x+"+IntToStr(znam[0])+")";
         plist->Add(strdup(zadanie.c_str()));
                for ( n = 0; n < 5; n ++ )
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "0");}
               else
                        {
                         temp1=random(20)-10;
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", temp1);
                        }
                plist->Add(strdup(buf));

        }}
if (vtype==3)
        {
        chis[2]=0;
        chis[1]=random(20)-10;
        chis[0]=(random(10)-5)*chis[1];
        temp1=random(20)-10;
        temp2=random(20)-10;
        znam[0]=chis[0]*temp2;
        znam[1]=temp2*chis[1]+chis[0]*temp1;
        znam[2]=temp1*chis[1];
        zadanie="Lim(x->"+IntToStr(-(chis[0]/chis[1]))+",(";
        zadanie=zadanie+IntToStr(chis[1])+"x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"Pow(x,2)+"+IntToStr(znam[1])+"x+"+IntToStr(znam[0])+")";
         plist->Add(strdup(zadanie.c_str()));
        sd=1./float(-temp1*chis[0]/chis[b]+temp2);
        for ( n = 0; n < 5; n ++ )
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "%d", sd);}
               else
                        {
                         temp1=random(10)-5;
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", 1/float(temp1+random(8)-5));
                        }
                plist->Add(strdup(buf));

        }
        }
if (vtype==4)
        {
        chis[2]=0;
        chis[1]=random(12)-6;
        chis[0]=random(20)-10;
        znam[0]=random(20)-10;
        znam[1]=random(20)-10;
        znam[2]=random(20)-10;
        temp1=random(20)-10;
        zadanie="Lim(x->"+IntToStr(temp1)+",(";
        zadanie=zadanie+IntToStr(chis[1])+"x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"Pow(x,2)+"+IntToStr(znam[1])+"x+"+IntToStr(znam[0])+")";
         plist->Add(strdup(zadanie.c_str()));
        sd=float(chis[1]*temp1+chis[0])/float(znam[2]*temp1*temp1+znam[1]*temp1+znam[0]);
        for ( n = 0; n < 5; n ++ )
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "%d",sd);}
               else
                        {
                         temp1=random(20)-10;
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", float(temp1)/float(random(25)-12));
                        }
                plist->Add(strdup(buf));

        }
        }
if (vtype==5)
        {
        chis[2]=random(12)-6;
        chis[1]=random(12)-6;
        chis[0]=random(20)-10;
        znam[0]=random(20)-10;
        znam[1]=random(20)-10;
        znam[2]=random(20)-10;
        temp1=random(20)-10;
        zadanie="Lim(x->"+IntToStr(temp1)+",(";
        zadanie=zadanie+IntToStr(chis[2])+"Pow(x,2)+"+IntToStr(chis[1])+"x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"Pow(x,2)+"+IntToStr(znam[1])+"x+"+IntToStr(znam[0])+")";
         plist->Add(strdup(zadanie.c_str()));
        sd=float(chis[2]*temp1*temp1+chis[1]*temp1+chis[0])/float(znam[2]*temp1*temp1+znam[1]*temp1+znam[0]);
        for ( n = 0; n < 5; n++)
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "%d",sd);}
               else
                        {
                         temp1=random(10)-10;
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", float(temp1)/float(random(18)-10));
                        }
                plist->Add(strdup(buf));

        }
        }
if (vtype==6)
        {
        chis[2]=random(12)-6;
        chis[1]=random(12)-6;
        chis[0]=random(20)-10;
        znam[0]=random(20)-10;
        znam[1]=random(20)-10;
        znam[2]=random(20)-10;
        zadanie="Lim(x->Inf,(";
        zadanie=zadanie+IntToStr(chis[2])+"Pow(x,2)+"+IntToStr(chis[1])+"x+"+IntToStr(chis[0])+")/(";
        zadanie=zadanie+IntToStr(znam[2])+"Pow(x,2)+"+IntToStr(znam[1])+"x+"+IntToStr(znam[0])+")";
         plist->Add(strdup(zadanie.c_str()));
        sd=float(chis[2])/float(znam[2]);
        for ( n = 0; n < 5; n++)
        {
               sprintf(buf,"String(\"Вариант %c):\")", 'a' + n );
               plist->Add(strdup(buf));
               if ( n != Right_Numb - 1 ) {sprintf(buf, "%d",sd);}
               else
                        {
                         temp1=random(10)-10;
                         if (temp1=0)  sprintf(buf, "Inf"); else
                                sprintf(buf, "%d", float(temp1)/float(random(18)-10));
                        }
                plist->Add(strdup(buf));

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
        t.ch_ask = 5;
        t.right_ask = Right_Numb;
        t.msg = "Тест успешно сгенерирован.";

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//-----------------------------------------------------------



