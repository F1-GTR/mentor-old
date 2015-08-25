
              //---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest36.h"
#include "MAngle.h"
#include "drobi.h"
#include "qvarnt.h"
#include "MLog.h"

#include "UtilsNG.h"

#pragma hdrstop
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma package(smart_init)   

//class init
quest36::quest36(FILE* f)
{
  Log->Add("Q36 Init..");
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
quest36::Save(FILE* f)
{
  Log->Add("Q36 Saving..");
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);

  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  //fprintf(f,"%s\n",strpar1);
  fprintf(f,"%d %d %d %d\n",min.top,max.top,min.bot,max.bot);
  fprintf(f,"%s\n",strpar2);

  return 0;
}


//edit settings dialog
quest36::Edit()
{
   Log->Add("Q36 Edit settings..");
  keygen = 0;
  nvar = 1;
  return 0;
}

//output to plist
quest36::Print(TList* plist)
{       Log->Add("Q36");
        mqinit;

        bool bZero       = true;
        //coefficients struct
        struct
        {
                int x, y, z;
                int a,b,c,d;
        } cc;

        cc.x = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.y = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.z = -1*sign()*rgen(keygen,1,min.top,max.top);


        bZero = true;
        cc.a = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.b = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.c = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.d = -1*sign()*rgen(keygen,1,min.top,max.top);

        double t = - (double)(cc.a*cc.x+cc.b*cc.y+cc.c*cc.z+cc.d)/(double)(cc.a*cc.a+cc.b*cc.b+cc.c*cc.c);

        //Сборка уравненения
        mqtask;

        sprintf( buf, "String(Найти точку, симметричную данной относительно плоскости.)" );mwl;
        sprintf( buf, "String(Объекты заданы уравнениями:)" );mwl;
        sprintf( buf, "String(Плоскость:)" );mwl;
        sprintf( buf, "(%d)*x+(%d)*y+(%d)*z+(%d)=0", cc.a,cc.b,cc.c,cc.d);mwl;
        sprintf( buf, "String(Точка:)" );mwl;
        sprintf( buf, "m(%d,%d,%d)", cc.x,cc.y,cc.z);mwl;
        msl;

        //расчёт ответа
        mqteacher;

         sprintf( buf, "((x-(%d))/%d)=((y-(%d))/%d)=((z-(%d))/%d)", cc.x,cc.a,cc.y,cc.b,cc.z,cc.c);mwl;

         //иницилизация дополнительных 8 буферов
        mbuffsinit;
        //очистка буферов
        mbuffsclear;

        sprintf(buf1,"System(");

        sprintf(buf2,"x=(%d)*t+(%d),",cc.a,cc.x);
        sprintf(buf3,"y=(%d)*t+(%d),",cc.b,cc.y);
        sprintf(buf4,"z=(%d)*t+(%d),",cc.c,cc.z);
        sprintf(buf5,"(%d)*x+(%d)*y+(%d)*z+(%d)=0",cc.a,cc.b,cc.c,cc.d);

        sprintf(buf6,")");

        //склеивание буферов в buf
        mbuffscat;mwl;

        msl;
        sprintf(buf,"(%d)*((%d)*t+(%d))+(%d)*((%d)*t+(%d))+(%d)*((%d)*t+(%d))+(%d)=0",
                cc.a,cc.a,cc.x,cc.b,cc.b,cc.y,cc.c,cc.c,cc.z,cc.d); mwl;

        msl;
        sprintf(buf,"(%d)^2*t+(%d)^2*t+(%d)^2*t=-((%d)+(%d)*(%d)+(%d)*(%d)+(%d)*(%d))",
                cc.a,cc.b,cc.c,
                cc.d,cc.a,cc.x,cc.b,cc.y,cc.c,cc.z);mwl;
        msl;

        sprintf(buf,"-t=((%d)*(%d)+(%d)*(%d)+(%d)*(%d))/((%d)^2+(%d)^2+(%d)^2)",
                cc.a,cc.x,cc.b,cc.y,cc.c,cc.z,
                cc.a,cc.b,cc.c);mwl;
        msl;

        sprintf(buf,"t=%f",t); mwl;
        msl;

        mbuffsclear;
        sprintf(buf1,"System(");

        sprintf(buf2,"x_1=(%d)*(%f)+(%d),",cc.a,t,cc.x);
        sprintf(buf3,"y_1=(%d)*(%f)+(%d),",cc.b,t,cc.y);
        sprintf(buf4,"z_1=(%d)*(%f)+(%d)",cc.c,t,cc.z);

        sprintf(buf5,")");

        mbuffscat;mwl;
        msl;

        sprintf(buf,"q(%f,%f,%f)",
                cc.a*t+cc.x,
                cc.b*t+cc.y,
                cc.c*t+cc.z);mwl;msl;

        sprintf(buf,"p(%f,%f,%f)",
                2*(cc.a*t+cc.x)-cc.x,
                2*(cc.b*t+cc.y)-cc.y,
                2*(cc.c*t+cc.z)-cc.z);mwl;

        mqend;
}
//------------------------------------------------------------------------------
//output to test
quest36::Print(TList* plist, class test &t)
{
       Log->Add("Q36");

        tqinit;

        bool bZero       = true;
        //coefficients struct
        struct
        {
                int x, y, z;
                int a,b,c,d;
        } cc;

        cc.x = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.y = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.z = -1*sign()*rgen(keygen,1,min.top,max.top);



        bZero = true;
        cc.a = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.b = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.c = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.d = -1*sign()*rgen(keygen,1,min.top,max.top);

        //Сборка уравненения

        tqtask;

        sprintf( buf, "String(Найти точку, симметричную данной относительно плоскости.)" );mwl;
        sprintf( buf, "String(Объекты заданы уравнениями:)" );mwl;
        sprintf( buf, "String(Плоскость:)" );mwl;
        sprintf( buf, "(%d)*x+(%d)*y+(%d)*z+(%d)=0", cc.a,cc.b,cc.c,cc.d);mwl;
        sprintf( buf, "String(Точка:)" );mwl;
        sprintf( buf, "m(%d,%d,%d)", cc.x,cc.y,cc.z);mwl;

        msl;
        double t0 = - (double)(cc.a*cc.x+cc.b*cc.y+cc.c*cc.z+cc.d)/(double)(cc.a*cc.a+cc.b*cc.b+cc.c*cc.c);

        //generating variants

        //right variant
        pAns[0].legit = true;
        sprintf( pAns[0].str, "p(%f,%f,%f)",
                2*(cc.a*t0+cc.x)-cc.x,
                2*(cc.b*t0+cc.y)-cc.y,
                2*(cc.c*t0+cc.z)-cc.z);


        //wrong variant 1
        pAns[1].legit = false;
        sprintf( pAns[1].str, "p(%f,%f,%f)",
                2*(cc.a*t0+cc.x+random(5)+1)-cc.x,
                2*(cc.b*t0+cc.y-random(5)-5)-cc.y,
                2*(cc.c*t0+cc.z+random(5)+10)-cc.z);


         //wrong variant 2
        pAns[2].legit = false;
        sprintf( pAns[2].str, "p(%f,%f,%f)",
                2*(cc.a*t0+cc.x-random(5)-1)-cc.x,
                2*(cc.b*t0+cc.y+random(5)+10)-cc.y,
                2*(cc.c*t0+cc.z+random(5)+5)-cc.z);


         //wrong variant 3
        pAns[3].legit = false;
        sprintf( pAns[3].str, "p(%f,%f,%f)",
                2*(cc.a*t0+cc.x+random(5)+1)-cc.x,
                2*(cc.b*t0+cc.y+random(5)+25)-cc.y,
                2*(cc.c*t0+cc.z+random(5)+10)-cc.z);

        tqend;
}
//-----------------------------------------------------------

