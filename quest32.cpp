//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest32.h"
#include "MAngle.h"
#include "drobi.h"
#include "qvarnt.h"
#include "MLog.h"
#include "MQ32Settings.h"

#include "UtilsNG.h"

#pragma hdrstop
//---------------------------------------------------------------------------
//
//      line:   (x-x0)/l = (y-y0)/m = (z-z0)/n
//
//      plane:  A*x + B*y + C*z + D = 0
//
//      Generating kfc.:        (x0,x0,z0),(l,m,n),(A,B,C,D)
//
//      ask:    sin(alpha) = abs( A*l + B*m + C*n ) / ( sqrt( l^2 + m^2 +n^2 )*sqrt( A^2 + B^2 + C^2 ) )
//
//---------------------------------------------------------------------------
#pragma package(smart_init)   

//class init
quest32::quest32(FILE* f)
{
  Log->Add("Q32 Init..");
  char* buf = new char[256];

  randomize();
  keygen = random (1000) + 1;

  reads(f,buf);
  strpar1 = strdup(buf);
  reads(f,buf);
  strpar2 = strdup(buf);

  sscanf(strpar1,"%d %d %d %d %d %d",&min.point,&max.point,&min.vector,&max.vector,&min.plate,&max.plate);
  qtype = type;

  delete buf;
}

//save to file??
quest32::Save(FILE* f)
{
  Log->Add("Q32 Saving..");
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  //fprintf(f,"%s\n",strpar1);
  fprintf(f,"%d %d %d %d %d %d\n",min.point,max.point,min.vector,max.vector,min.plate,max.plate );
  fprintf(f,"%s\n",strpar2);

  return 0;
}


//edit settings dialog
quest32::Edit()
{
  Log->Add("Q32 Edit settings..");

  //sscanf(strpar2,"%d %d %d %d %d %d",&min.point,&max.point,&min.vector,&max.vector,&min.plate,&max.plate);

  keygen = 0;
  nvar = 1;

  /*Angle->quest2 = this;

  Angle->Edit1->Text = IntToStr(amin);
  Angle->Edit2->Text = IntToStr(amax);
  Angle->Edit3->Text = IntToStr(keygen);
  Angle->Edit4->Text = IntToStr(nvar);

  Angle->ShowModal();   */
  PLAngle->quest = this;
  PLAngle->MinPoint->Position = min.point;
  PLAngle->MinVector->Position = min.vector;
  PLAngle->MinPlate->Position = min.plate;
  PLAngle->MaxPoint->Position = max.point;
  PLAngle->MaxVector->Position = max.vector;
  PLAngle->MaxPlate->Position = max.plate;
  PLAngle->ShowModal();

  return 0;
}

//output to plist
quest32::Print(TList* plist)
{
        drobi dr;

        char* buf = new char[256];
        char* buf1 = new char[256];

        Log->Add("Q32 Printing to test..");

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );


        //get limits
        int firstKf     = 1;
        int lastKf      = 10;
        bool bZero       = true;
        //coefficients struct
        struct
        {
                int X0, Y0, Z0;
                int A,B,C,D;
                int l,m,n;
        } cc;

       


        cc.X0 = -1*sign()*rgen(keygen,1,min.point,max.point);
        cc.Y0 = -1*sign()*rgen(keygen,1,min.point,max.point);
        cc.Z0 = -1*sign()*rgen(keygen,1,min.point,max.point);

        cc.A = sign()*rgen(keygen,1,min.plate,max.plate);
        cc.B = sign()*rgen(keygen,1,min.plate,max.plate);
        cc.C = sign()*rgen(keygen,1,min.plate,max.plate);
        cc.D = sign()*rgen(keygen,1,min.plate,max.plate);

        cc.l = sign()*zero(bZero)*rgen(keygen,1,min.vector,max.vector);
        cc.m = sign()*zero(bZero)*rgen(keygen,1,min.vector,max.vector);
        cc.n = sign()*zero(bZero)*rgen(keygen,1,min.vector,max.vector);

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


         sprintf( buf, "String(Посчитать угол между прямой и плоскостью.)" );
         plist->Add( strdup(buf) );

         sprintf( buf, "String(Объекты заданы уравнениями:)" );
         plist->Add( strdup(buf) );

        sprintf( buf, "a" );
        plist->Add( strdup(buf) );
        Log->Add(buf);
        sprintf( buf, "((x-(%d))/%d)=((y-(%d))/%d)=((z-(%d))/%d)", cc.X0,cc.l,cc.Y0,cc.m,cc.Z0,cc.n);
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "alpha" );
        plist->Add( strdup(buf) );
        Log->Add(buf);
        sprintf( buf, "(%d)*x+(%d)*y+(%d)*z+(%d)=0", cc.A,cc.B,cc.C,cc.D);
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

        sprintf( buf, "sin(!(alpha))" );
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "(abs((%d)*(%d)+(%d)*(%d)+(%d)*(%d)))/(sqrt((%d)^2+(%d)^2+(%d)^2)*sqrt((%d)^2+(%d)^2+(%d)^2))",cc.A,cc.l,cc.B,cc.m,cc.C,cc.n,cc.l,cc.m,cc.n,cc.A,cc.B,cc.C);
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "(abs(%d))/(sqrt(%d)*sqrt(%d))",cc.A*cc.l+cc.B*cc.m+cc.C*cc.n,   cc.l*cc.l+cc.m*cc.m+cc.n*cc.n,   cc.A*cc.A+cc.B*cc.B+cc.C*cc.C);
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "(abs(%d))/(sqrt(%d))",cc.A*cc.l+cc.B*cc.m+cc.C*cc.n,   (cc.l*cc.l+cc.m*cc.m+cc.n*cc.n)*(cc.A*cc.A+cc.B*cc.B+cc.C*cc.C));
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "(%d*sqrt(%d))/%d",abs(cc.A*cc.l+cc.B*cc.m+cc.C*cc.n),   (cc.l*cc.l+cc.m*cc.m+cc.n*cc.n)*(cc.A*cc.A+cc.B*cc.B+cc.C*cc.C),(cc.l*cc.l+cc.m*cc.m+cc.n*cc.n)*(cc.A*cc.A+cc.B*cc.B+cc.C*cc.C));
        plist->Add( strdup(buf) );
        Log->Add(buf);

        keygen = 0;

        delete buf;
        delete buf1;

        return 0;
}
//------------------------------------------------------------------------------
//output to test
quest32::Print(TList* plist, class test &t)
{
        Log->Add("Q32 Printing to Joomla test..");
        int i;
        int plane[4], plane2[4];
        int scal, absa, absb;
        int n, Right_Numb;

        drobi dr;

        char* buf = new char[256];
        char* buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        Right_Numb = -1;

        srand( keygen );

        //get limits
        int firstKf     = 1;
        int lastKf      = 10;
        bool bZero       = true;
        //coefficients struct
        struct
        {
                int X0, Y0, Z0;
                int A,B,C,D;
                int l,m,n;
        } cc;

        cc.X0 = -1*sign()*rgen(keygen,1,firstKf,lastKf);
        cc.Y0 = -1*sign()*rgen(keygen,1,firstKf,lastKf);
        cc.Z0 = -1*sign()*rgen(keygen,1,firstKf,lastKf);

        cc.A = sign()*rgen(keygen,1,firstKf,lastKf);
        cc.B = sign()*rgen(keygen,1,firstKf,lastKf);
        cc.C = sign()*rgen(keygen,1,firstKf,lastKf);
        cc.D = sign()*rgen(keygen,1,firstKf,lastKf);

        cc.l = sign()*zero(bZero)*rgen(keygen,1,firstKf,lastKf);
        cc.m = sign()*zero(bZero)*rgen(keygen,1,firstKf,lastKf);
        cc.n = sign()*zero(bZero)*rgen(keygen,1,firstKf,lastKf);

        //Сборка уравненения

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

         sprintf( buf, "String(Посчитать угол между прямой и плоскостью.)" );
         plist->Add( strdup(buf) );

         sprintf( buf, "String(Объекты заданы уравнениями:)" );
         plist->Add( strdup(buf) );
                sprintf( buf, "String( )" );
                 plist->Add( strdup(buf) );

        sprintf( buf, "a" );
        plist->Add( strdup(buf) );
        Log->Add(buf);
        sprintf( buf, "((x-(%d))/%d)=((y-(%d))/%d)=((z-(%d))/%d)", cc.X0,cc.l,cc.Y0,cc.m,cc.Z0,cc.n);
        plist->Add( strdup(buf) );
        Log->Add(buf);
                sprintf( buf, "String( )" );
                 plist->Add( strdup(buf) );

        sprintf( buf, "alpha" );
        plist->Add( strdup(buf) );
        Log->Add(buf);
        sprintf( buf, "(%d)*x+(%d)*y+(%d)*z+(%d)=0", cc.A,cc.B,cc.C,cc.D);
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "sin(!(alpha))=...");
        plist->Add( strdup(buf) );
        Log->Add(buf);

                sprintf( buf, "String( )" );
                 plist->Add( strdup(buf) );

        //generating variants
        Log->Add("Generating..");
        pAnswer pAns[4];

        //right variant
        pAns[0].legit = true;
        sprintf( pAns[0].str, "(%d*sqrt(%d))/%d",abs(cc.A*cc.l+cc.B*cc.m+cc.C*cc.n),   (cc.l*cc.l+cc.m*cc.m+cc.n*cc.n)*(cc.A*cc.A+cc.B*cc.B+cc.C*cc.C),(cc.l*cc.l+cc.m*cc.m+cc.n*cc.n)*(cc.A*cc.A+cc.B*cc.B+cc.C*cc.C));

        //wrong variant 1
        pAns[1].legit = false;
        sprintf( pAns[1].str, "(%d*sqrt(%d))/%d",-abs(cc.A*cc.l+cc.B*cc.m+cc.C*cc.n),   (cc.l*cc.l+cc.m*cc.m+cc.n*cc.n)*(cc.A*cc.A+cc.B*cc.B+cc.C*cc.C),(cc.l*cc.l+cc.m*cc.m+cc.n*cc.n)*(cc.A*cc.A+cc.B*cc.B+cc.C*cc.C));

         //wrong variant 2
        pAns[2].legit = false;
        sprintf( pAns[2].str, "(%d*sqrt(%d))/%d",abs(cc.A*cc.l+cc.B*cc.m+cc.C*cc.n)+random(5)+1,   (cc.l*cc.l+cc.m*cc.m+cc.n*cc.n)*(cc.A*cc.A+cc.B*cc.B+cc.C*cc.C),(cc.l*cc.l+cc.m*cc.m+cc.n*cc.n)*(cc.A*cc.A+cc.B*cc.B+cc.C*cc.C));

         //wrong variant 3
        pAns[3].legit = false;
        sprintf( pAns[3].str, "(%d*%d)/sqrt(%d)",abs(cc.A*cc.l+cc.B*cc.m+cc.C*cc.n),   (cc.l*cc.l+cc.m*cc.m+cc.n*cc.n)*(cc.A*cc.A+cc.B*cc.B+cc.C*cc.C),(cc.l*cc.l+cc.m*cc.m+cc.n*cc.n)*(cc.A*cc.A+cc.B*cc.B+cc.C*cc.C));

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

                                    
