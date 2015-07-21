//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest33.h"
#include "MAngle.h"
#include "drobi.h"
#include "qvarnt.h"
#include "MLog.h"

#include "UtilsNG.h"

#pragma hdrstop
//---------------------------------------------------------------------------
//      Angle within lines
//
//      line1:   (x-x1)/l1 = (y-y1)/m1 = (z-z1)/n1
//
//      line2:   (x-x2)/l2 = (y-y2)/m2 = (z-z2)/n2
//
//      plane:  A*x + B*y + C*z + D = 0
//
//      Generating kfc.:        (x1,y1,z1),(l1,m1,n1)
//                              (x2,y2,z2),(l2,m2,n2)
//
//      One kfc != 0
//
//---------------------------------------------------------------------------
#pragma package(smart_init)   

//class init
quest33::quest33(FILE* f)
{
  Log->Add("Q33 Init..");
  char* buf = new char[256];

  randomize();
  keygen = random (1000) + 1;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);

  sscanf(strpar1,"%d %d %d %d %d %d",&min.top,&max.top,&min.bot,&max.bot);
  qtype = type;

  delete buf;
}

//save to file??
quest33::Save(FILE* f)
{
  Log->Add("Q33 Saving..");
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);

  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  //fprintf(f,"%s\n",strpar1);
  fprintf(f,"%d %d %d %d\n",min.top,max.top,min.bot,max.bot);
  fprintf(f,"%s\n",strpar2);

  return 0;
}


//edit settings dialog
quest33::Edit()
{
  Log->Add("Q33 Edit settings..");

  //sscanf(strpar1,"%d %d %d %d %d %d",&min.top,&max.top,&min.bot,&max.bot);

  keygen = 0;
  nvar = 1;
  /*
  LAngle->quest = this;
  PLAngle->MinPoint->Position = min.point;
  PLAngle->MinVector->Position = min.vector;
  PLAngle->MinPlate->Position = min.plate;
  PLAngle->MaxPoint->Position = max.point;
  PLAngle->MaxVector->Position = max.vector;
  PLAngle->MaxPlate->Position = max.plate;
  PLAngle->ShowModal();
   */
  return 0;
}

//output to plist
quest33::Print(TList* plist)
{
        char* buf = new char[256];
        char* buf1 = new char[256];

        Log->Add("Q33 Printing to test..");

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );
        bool bZero       = true;
        //coefficients struct
        struct
        {
                int X, Y, Z;
                int l,m,n;
        } cc[2];

        cc[0].X = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc[0].Y = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc[0].Z = -1*sign()*rgen(keygen,1,min.top,max.top);

        cc[0].l = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc[0].m = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc[0].n = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);

        bZero = true;
        cc[1].X = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc[1].Y = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc[1].Z = -1*sign()*rgen(keygen,1,min.top,max.top);

        cc[1].l = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc[1].m = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc[1].n = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);

        //Сборка уравненения

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


         sprintf( buf, "String(Посчитать угол между прямыми.)" );
         plist->Add( strdup(buf) );

         sprintf( buf, "String(Объекты заданы уравнениями:)" );
         plist->Add( strdup(buf) );

        sprintf( buf, "a" );
        plist->Add( strdup(buf) );
        Log->Add(buf);
        sprintf( buf, "((x-(%d))/%d)=((y-(%d))/%d)=((z-(%d))/%d)", cc[0].X,cc[0].l,cc[0].Y,cc[0].m,cc[0].Z,cc[0].n);
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "b" );
        plist->Add( strdup(buf) );
        Log->Add(buf);
        sprintf( buf, "((x-(%d))/%d)=((y-(%d))/%d)=((z-(%d))/%d)", cc[1].X,cc[1].l,cc[1].Y,cc[1].m,cc[1].Z,cc[1].n);
        plist->Add( strdup(buf) );
        Log->Add(buf);


        //расчёт ответа
        sprintf( buf, "String(@Часть преподавателя )" );
        plist->Add( strdup(buf) );
        Log->Add(buf);



        sprintf( buf, "String(\"Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf(buf,
                "((%d)*(%d)+(%d)*(%d)+(%d)*(%d))/(sqrt((%d)^2+(%d)^2+(%d)^2)*sqrt((%d)^2+(%d)^2+(%d)^2))",
                cc[0].l,cc[1].l,
                cc[0].m,cc[1].m,
                cc[0].n,cc[1].n,
                cc[0].l,cc[0].m,cc[0].n,
                cc[1].l,cc[1].m,cc[1].n);

        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf(buf,
                "((%d)+(%d)+(%d))/(sqrt((%d)+(%d)+(%d))*sqrt((%d)+(%d)+(%d)))",
                cc[0].l*cc[1].l,
                cc[0].m*cc[1].m,
                cc[0].n*cc[1].n,
                cc[0].l*cc[0].l,cc[0].m*cc[0].m,cc[0].n*cc[0].n,
                cc[1].l*cc[1].l,cc[1].m*cc[1].m,cc[1].n*cc[1].n);

        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf(buf,
                "(%d)/(sqrt(%d))",
                cc[0].l*cc[1].l+
                cc[0].m*cc[1].m+
                cc[0].n*cc[1].n,
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n);


        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf(buf,
                "(%d*(sqrt(%d))/%d)",
                cc[0].l*cc[1].l+
                cc[0].m*cc[1].m+
                cc[0].n*cc[1].n,
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n,
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n);


        plist->Add( strdup(buf) );
        Log->Add(buf);

         sprintf(buf,
                "arccos(abs(cos(%d*sqrt(%d)/%d)))",
                (cc[0].l*cc[1].l+
                cc[0].m*cc[1].m+
                cc[0].n*cc[1].n),
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n,
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n);


        plist->Add( strdup(buf) );

        Log->Add(buf);

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//------------------------------------------------------------------------------
//output to test
quest33::Print(TList* plist, class test &t)
{
        char* buf = new char[256];
        char* buf1 = new char[256];

        Log->Add("Q33 Printing to Joomla test..");

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );
        bool bZero       = true;
        int Right_Numb = -1;
        //coefficients struct
        struct
        {
                int X, Y, Z;
                int l,m,n;
        } cc[2];

        cc[0].X = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc[0].Y = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc[0].Z = -1*sign()*rgen(keygen,1,min.top,max.top);

        cc[0].l = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc[0].m = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc[0].n = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);

        cc[1].X = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc[1].Y = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc[1].Z = -1*sign()*rgen(keygen,1,min.top,max.top);

        cc[1].l = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc[1].m = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc[1].n = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);

        //Сборка уравненения


        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

         sprintf( buf, "String(Посчитать угол между прямыми.)" );
         plist->Add( strdup(buf) );

         sprintf( buf, "String(Объекты заданы уравнениями:)" );
         plist->Add( strdup(buf) );

        sprintf( buf, "a" );
        plist->Add( strdup(buf) );
        Log->Add(buf);
        sprintf( buf, "((x-(%d))/%d)=((y-(%d))/%d)=((z-(%d))/%d)", cc[0].X,cc[0].l,cc[0].Y,cc[0].m,cc[0].Z,cc[0].n);
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "b" );
        plist->Add( strdup(buf) );
        Log->Add(buf);
        sprintf( buf, "((x-(%d))/%d)=((y-(%d))/%d)=((z-(%d))/%d)", cc[1].X,cc[1].l,cc[1].Y,cc[1].m,cc[1].Z,cc[1].n);
        plist->Add( strdup(buf) );
        Log->Add(buf);


                sprintf( buf, "String( )" );
                 plist->Add( strdup(buf) );

        //generating variants
        Log->Add("Generating..");
        pAnswer pAns[4];

        //right variant
        pAns[0].legit = true;
        sprintf( pAns[0].str, "arccos(abs(cos(%d*sqrt(%d)/%d)))",
                (cc[0].l*cc[1].l+
                cc[0].m*cc[1].m+
                cc[0].n*cc[1].n),
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n,
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n);


        //wrong variant 1
        pAns[1].legit = false;
        sprintf( pAns[1].str, "arccos(abs(cos(%d*sqrt(%d)/%d)))",
                cc[0].l*cc[1].l+
                cc[0].m*cc[1].m+
                cc[0].n*cc[1].n+sign()*(random(10)+1),
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n,
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n);


         //wrong variant 2
        pAns[2].legit = false;
        sprintf( pAns[2].str, "arccos(abs(cos(%d*sqrt(%d)/%d)))",
                (cc[0].l*cc[1].l+
                cc[0].m*cc[1].m+
                cc[0].n*cc[1].n+sign()*(random(20)+1)),
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n,
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n);


         //wrong variant 3
        pAns[3].legit = false;
        sprintf( pAns[3].str, "arccos(abs(cos(%d*sqrt(%d)/%d)))",
                (cc[0].l*cc[1].l+
                cc[0].m*cc[1].m+
                cc[0].n*cc[1].n+sign()*(random(30)+1)),
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n,
                cc[0].l*cc[0].l+cc[0].m*cc[0].m+cc[0].n*cc[0].n+
                cc[1].l*cc[1].l+cc[1].m*cc[1].m+cc[1].n*cc[1].n);


        //shuffle ;)
        Log->Add("Shuffle..");
        shuffleAnswers(pAns);

        Log->Add("Find right..");
        //get right variant
        for (int i = 0; i < 4 && Right_Numb == -1; i++)
        {
                if (pAns[i].legit)
                {
                        Right_Numb = i+1;
                         Log->Add("Right");
                }
                else
                {
                        Log->Add("Wrong");
                }
        }

        //output

        plist->Add(strdup("String(Вариант a: )"));
        plist->Add( strdup(pAns[0].str) );
        Log->Add(pAns[0].str);
                      sprintf( buf, "String( )" );
                  plist->Add( strdup(buf) );

        plist->Add(strdup("String(Вариант b: )"));
        plist->Add( strdup(pAns[1].str) );
        Log->Add(pAns[1].str);
                sprintf( buf, "String( )" );
                 plist->Add( strdup(buf) );

        plist->Add(strdup("String(Вариант c: )"));
        plist->Add( strdup(pAns[2].str) );
        Log->Add(pAns[2].str);
                sprintf( buf, "String( )" );
                  plist->Add( strdup(buf) );

        plist->Add(strdup("String(Вариант d: )"));
        plist->Add( strdup(pAns[3].str) );
        Log->Add(pAns[3].str);
                 sprintf( buf, "String( )" );
                  plist->Add( strdup(buf) );

        t.pr_tst = 1;
        t.ch_ask = 4;
        t.right_ask = Right_Numb;
        t.msg = "Тест успешно сгенерирован.";

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//-----------------------------------------------------------


