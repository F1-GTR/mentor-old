//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest37.h"
#include "MAngle.h"
#include "drobi.h"
#include "qvarnt.h"
#include "MLog.h"

#include "UtilsNG.h"

#pragma hdrstop
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
#pragma package(smart_init)   

//class init
quest37::quest37(FILE* f)
{
  Log->Add("Q37 Init..");
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
quest37::Save(FILE* f)
{
  Log->Add("Q37 Saving..");
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);

  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  //fprintf(f,"%s\n",strpar1);
  fprintf(f,"%d %d %d %d\n",min.top,max.top,min.bot,max.bot);
  fprintf(f,"%s\n",strpar2);

  return 0;
}


//edit settings dialog
quest37::Edit()
{
  Log->Add("Q37 Edit settings..");

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
quest37::Print(TList* plist)
{
        Log->Add("Q37");
        mqinit;

        bool bZero       = true;
        //coefficients struct
        struct
        {
                //point
                int x0, y0, z0;
                //line
                int x3, y3, z3;
                //int a,b,c,d;
                //line
                int l,m,n;
        } cc;

        cc.x0 = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.y0 = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.z0 = -1*sign()*rgen(keygen,1,min.top,max.top);


        bZero = true;
        cc.x3 = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.y3 = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.z3 = -1*sign()*rgen(keygen,1,min.top,max.top);

        bZero = true;
        cc.l = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.m = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.n = -1*sign()*rgen(keygen,1,min.top,max.top);

        double t = (double)(cc.l*(cc.x0-cc.x3)+cc.m*(cc.y0-cc.y3)+cc.n*(cc.x0-cc.x3))/(double)(cc.l*cc.l+cc.m*cc.m+cc.n*cc.n);

        //Сборка уравненения
        mqtask;

        sprintf( buf, "String(Найти точку, симметричную данной относительно прямой.)" );mwl;
        sprintf( buf, "String(Объекты заданы уравнениями:)" );mwl;
        sprintf( buf, "String(Прямая:)" );mwl;
        sprintf( buf, "(x-(%d))/(%d)=(y-(%d))/(%d)=(z-(%d))/(%d)", cc.x3,cc.l,cc.y3,cc.m,cc.z3,cc.n);mwl;
        sprintf( buf, "String(Точка:)" );mwl;
        sprintf( buf, "m(%d,%d,%d)", cc.x0,cc.y0,cc.z0);mwl;
        msl;

        //расчёт ответа
        mqteacher;

         sprintf( buf, "(%d)*(x-(%d))+(%d)*(y-(%d))+(%d)*(z-(%d))=0",
          cc.l,cc.x3,cc.m,cc.y3,cc.n,cc.x3);mwl;

         //иницилизация дополнительных 8 буферов
        mbuffsinit;
        //очистка буферов
        mbuffsclear;

        sprintf(buf1,"System(");

        sprintf(buf2,"x=(%d)*t+(%d),",cc.l,cc.x3);
        sprintf(buf3,"y=(%d)*t+(%d),",cc.m,cc.y3);
        sprintf(buf4,"z=(%d)*t+(%d),",cc.n,cc.z3);
        sprintf(buf5,"(%d)*x+(%d)*y+(%d)*z=(%d)*(%d)+(%d)*(%d)+(%d)*(%d)",cc.l,cc.m,cc.n,cc.l,cc.x0,cc.m,cc.y0,cc.n,cc.z0);

        sprintf(buf6,")");

        //склеивание буферов в buf
        mbuffscat;mwl;

        sprintf(buf,"t_1=((%d)*((%d)-(%d))+(%d)*((%d)-(%d))+(%d)*((%d)-(%d)))/((%d)^2+(%d)^2+(%d)^2)",
                cc.l,cc.x0,cc.x3,cc.m,cc.y0,cc.y3, cc.n,cc.z0,cc.z3,
                cc.l,cc.m,cc.n);mwl;
        msl;

        sprintf(buf,"t_1=%f",t); mwl;
        msl;

        mbuffsclear;
        sprintf(buf1,"System(");

        sprintf(buf2,"x_1=(%d)*(%f)+(%d),",cc.l,t,cc.x3);
        sprintf(buf3,"y_1=(%d)*(%f)+(%d),",cc.m,t,cc.y3);
        sprintf(buf4,"z_1=(%d)*(%f)+(%d)",cc.n,t,cc.z3);

        double x1=cc.l*t+cc.x3;
        double y1=cc.m*t+cc.y3;
        double z1=cc.n*t+cc.z3;

        sprintf(buf5,")");

        mbuffscat;mwl;
        msl;

        sprintf(buf,"q(%f,%f,%f)",
                x1,
                y1,
                z1);mwl;msl;

        sprintf(buf,"p(%f,%f,%f)",
                2*(x1)-cc.x0,
                2*(y1)-cc.y0,
                2*(z1)-cc.z0);mwl;

        mqend;
}
//------------------------------------------------------------------------------
//output to test
quest37::Print(TList* plist, class test &t)
{
        Log->Add("Q37");

        tqinit;

         bool bZero       = true;
        //coefficients struct
        struct
        {
                //point
                int x0, y0, z0;
                //line
                int x3, y3, z3;
                //int a,b,c,d;
                //line
                int l,m,n;
        } cc;

        cc.x0 = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.y0 = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.z0 = -1*sign()*rgen(keygen,1,min.top,max.top);


        bZero = true;
        cc.x3 = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.y3 = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.z3 = -1*sign()*rgen(keygen,1,min.top,max.top);

        bZero = true;
        cc.l = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.m = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.n = -1*sign()*rgen(keygen,1,min.top,max.top);

        float t0 = (float)(cc.l*(cc.x0-cc.x3)+cc.m*(cc.y0-cc.y3)+cc.n*(cc.x0-cc.x3))/(float)(cc.l*cc.l+cc.m*cc.m+cc.n*cc.n);
        sprintf(buf,"%f",t0);  Log->Add(buf);
        float x1=cc.l*t0+cc.x3;
        sprintf(buf,"%f",x1); Log->Add(buf);
        float y1=cc.m*t0+cc.y3;
        sprintf(buf,"%f",y1); Log->Add(buf);
        float z1=cc.n*t0+cc.z3;
        sprintf(buf,"%f",z1); Log->Add(buf);
        //Сборка уравненения

        tqtask;

        sprintf( buf, "String(Найти точку, симметричную данной относительно прямой.)" );mwl;
        sprintf( buf, "String(Объекты заданы уравнениями:)" );mwl;
        sprintf( buf, "String(Прямая:)" );mwl;
        sprintf( buf, "(x-(%d))/(%d)=(y-(%d))/(%d)=(z-(%d))/(%d)", cc.x3,cc.l,cc.y3,cc.m,cc.z3,cc.n);mwl;
        sprintf( buf, "String(Точка:)" );mwl;
        sprintf( buf, "m(%d,%d,%d)", cc.x0,cc.y0,cc.z0);mwl;
        msl;


        msl;

        //generating variants

        //right variant
        pAns[0].legit = true;
        sprintf( pAns[0].str, "p(%f,%f,%f)",
                2*(x1)-cc.x0,
                2*(y1)-cc.y0,
                2*(z1)-cc.z0);


        //wrong variant 1
        pAns[1].legit = false;
        sprintf( pAns[1].str, "p(%f,%f,%f)",
                2*(x1)-cc.x0+sign()*(random(5)+15),
                2*(y1)-cc.y0+sign()*(random(5)+5),
                2*(z1)-cc.z0+sign()*(random(5)+25));


         //wrong variant 2
        pAns[2].legit = false;
        sprintf( pAns[2].str, "p(%f,%f,%f)",
                2*(x1)-cc.x0+sign()*(random(5)+25),
                2*(y1)-cc.y0+sign()*(random(5)+5),
                2*(z1)-cc.z0+sign()*(random(5)+15));


         //wrong variant 3
        pAns[3].legit = false;
        sprintf( pAns[3].str, "p(%f,%f,%f)",
                2*(x1)-cc.x0+sign()*(random(5)+5),
                2*(y1)-cc.y0+sign()*(random(5)+15),
                2*(z1)-cc.z0+sign()*(random(5)+25));

        tqend;
}
//-----------------------------------------------------------


