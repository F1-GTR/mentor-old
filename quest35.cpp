    //---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest35.h"
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
quest35::quest35(FILE* f)
{
  Log->Add("Q35 Init..");
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
quest35::Save(FILE* f)
{
  Log->Add("Q35 Saving..");
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);

  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  //fprintf(f,"%s\n",strpar1);
  fprintf(f,"%d %d %d %d\n",min.top,max.top,min.bot,max.bot);
  fprintf(f,"%s\n",strpar2);

  return 0;
}


//edit settings dialog
quest35::Edit()
{
  Log->Add("Q35 Edit settings..");
  keygen = 0;
  nvar = 1;
  return 0;
}

//output to plist
quest35::Print(TList* plist)
{
        Log->Add("Q35");
        //иницилизация
        mqinit;

        bool bZero       = true;
        //coefficients struct
        struct
        {
                int x, y, z;
                int l,m,n;
                int a,b,c,d;
        } cc;

        cc.x = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.y = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.z = -1*sign()*rgen(keygen,1,min.top,max.top);

        cc.l = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc.m = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc.n = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);

        bZero = true;
        cc.a = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.b = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.c = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.d = -1*sign()*rgen(keygen,1,min.top,max.top);

        double t = - (double)(cc.a*cc.x+cc.b*cc.y+cc.c*cc.z+cc.d)/(double)(cc.a*cc.l+cc.b*cc.m+cc.c*cc.n);

        //Сборка уравненения
        mqtask;

        sprintf( buf, "String(Найти точку пересечения прямой и плоскости.)" );mwl;
        sprintf( buf, "String(Объекты заданы уравнениями:)" );mwl;
        sprintf( buf, "String(Плоскость:)" );mwl;
        sprintf( buf, "(%d)*x+(%d)*y+(%d)*z+(%d)=0", cc.a,cc.b,cc.c,cc.d);mwl;
        sprintf( buf, "String(Прямая:)" );mwl;
        sprintf( buf, "((x-(%d))/%d)=((y-(%d))/%d)=((z-(%d))/%d)", cc.x,cc.l,cc.y,cc.m,cc.z,cc.n);mwl;
        msl;

        //расчёт ответа
        mqteacher;

        //иницилизация дополнительных 8 буферов
        mbuffsinit;
        //очистка буферов
        mbuffsclear;
        
        sprintf(buf1,"System(");

        sprintf(buf2,"x=(%d)*t+(%d),",cc.l,cc.x);
        sprintf(buf3,"y=(%d)*t+(%d),",cc.m,cc.y);
        sprintf(buf4,"z=(%d)*t+(%d),",cc.n,cc.z);
        sprintf(buf5,"(%d)*x+(%d)*y+(%d)*z+(%d)=0",cc.a,cc.b,cc.c,cc.d);

        sprintf(buf6,")");

        //склеивание буферов в buf
        mbuffscat;mwl;

        msl;
        sprintf(buf,"(%d)*((%d)*t+(%d))+(%d)*((%d)*t+(%d))+(%d)*((%d)*t+(%d))+(%d)=0",
                cc.a,cc.l,cc.x,cc.b,cc.m,cc.y,cc.c,cc.n,cc.z,cc.d); mwl;

        msl;
        sprintf(buf,"t*((%d)*(%d)+(%d)*(%d)+(%d)*(%d))=-((%d)+(%d)*(%d)+(%d)*(%d)+(%d)*(%d))",
                cc.a,cc.l,cc.b,cc.m,cc.c,cc.n,
                cc.d,cc.a,cc.x,cc.b,cc.y,cc.c,cc.z);mwl;
        msl;

        sprintf(buf,"-t=((%d)+(%d)*(%d)+(%d)*(%d)+(%d)*(%d))/((%d)*(%d)+(%d)*(%d)+(%d)*(%d))",
                cc.d,cc.a,cc.x,cc.b,cc.y,cc.c,cc.z,
               cc.a,cc.l,cc.b,cc.m,cc.c,cc.n);mwl;
        msl;

        sprintf(buf,"t=%f",t); mwl;
        msl;

        mbuffsclear;
        sprintf(buf1,"System(");

        sprintf(buf2,"x_1=(%d)*(%f)+(%d),",cc.l,t,cc.x);
        sprintf(buf3,"y_1=(%d)*(%f)+(%d),",cc.m,t,cc.y);
        sprintf(buf4,"z_1=(%d)*(%f)+(%d)",cc.n,t,cc.z);

        sprintf(buf5,")");

        mbuffscat;mwl;
        msl;


        sprintf(buf,"m(%f,%f,%f)",
                cc.l*t+cc.x,
                cc.m*t+cc.y,
                cc.n*t+cc.z);mwl;
        //конец
        mqend;
}
//------------------------------------------------------------------------------
//output to test
quest35::Print(TList* plist, class test &t)
{
        Log->Add("Q35");

        tqinit;

        bool bZero       = true;
        //coefficients struct
        struct
        {
                int x, y, z;
                int l,m,n;
                int a,b,c,d;
        } cc;

        cc.x = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.y = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.z = -1*sign()*rgen(keygen,1,min.top,max.top);

        cc.l = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc.m = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);
        cc.n = sign()*zero(bZero)*rgen(keygen,1,min.bot,max.bot);

        bZero = true;
        cc.a = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.b = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.c = -1*sign()*rgen(keygen,1,min.top,max.top);
        cc.d = -1*sign()*rgen(keygen,1,min.top,max.top);

        //Сборка уравненения

        tqtask;

        sprintf( buf, "String(Найти точку пересечения прямой и плоскости.)" );mwl;

        sprintf( buf, "String(Объекты заданы уравнениями:)" );mwl;

        sprintf( buf, "String(Плоскость:)" );mwl;
        sprintf( buf, "(%d)*x+(%d)*y+(%d)*z+(%d)=0", cc.a,cc.b,cc.c,cc.d);mwl;
        sprintf( buf, "String(Прямая:)" );mwl;
        sprintf( buf, "((x-(%d))/%d)=((y-(%d))/%d)=((z-(%d))/%d)", cc.x,cc.l,cc.y,cc.m,cc.z,cc.n);mwl;

        msl;
        double t0 = - (double)(cc.a*cc.x+cc.b*cc.y+cc.c*cc.z+cc.d)/(double)(cc.a*cc.l+cc.b*cc.m+cc.c*cc.n);

        //generating variants
       
        //right variant
        pAns[0].legit = true;
        sprintf( pAns[0].str, "m(%f,%f,%f)",
                cc.l*t0+cc.x,
                cc.m*t0+cc.y,
                cc.n*t0+cc.z);


        //wrong variant 1
        pAns[1].legit = false;
        sprintf( pAns[1].str, "m(%f,%f,%f)",
                cc.l*t0+cc.x+random(5)+1,
                cc.m*t0+cc.y-random(5)-5,
                cc.n*t0+cc.z+random(5)+10);


         //wrong variant 2
        pAns[2].legit = false;
        sprintf( pAns[2].str, "m(%f,%f,%f)",
                cc.l*t0+cc.x-random(5)-1,
                cc.m*t0+cc.y+random(5)+10,
                cc.n*t0+cc.z+random(5)+5);


         //wrong variant 3
        pAns[3].legit = false;
        sprintf( pAns[3].str, "m(%f,%f,%f)",
                cc.l*t0+cc.x+random(5)+1,
                cc.m*t0+cc.y+random(5)+25,
                cc.n*t0+cc.z+random(5)+10);

        tqend;
}
//-----------------------------------------------------------


