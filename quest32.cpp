//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest32.h"
#include "MAngle.h"
#include "drobi.h"
#include "qvarnt.h"
#include "Unit1.h"
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


//Получение знака, если was = True - знак рандомный, если нет - вернёт +
//При минусе Was обращается в False
int sign(bool &was)
{
        if (was)
        {
                int RD = random(2);
                if (RD)
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

//Обращение в ноль, если was = True - возврат рандомный, если нет - вернёт 1
//При нуле Was обращается в False
int zero(bool &was)
{
        if (was)
        {
                int RD = random(2);
                if (RD)
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

  sscanf(strpar1,"%d %d",&amin,&amax);
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
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}


//edit settings dialog
quest32::Edit()
{
  Log->Add("Q32 Edit settings..");
  
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  Angle->quest2 = this;

  Angle->Edit1->Text = IntToStr(amin);
  Angle->Edit2->Text = IntToStr(amax);
  Angle->Edit3->Text = IntToStr(keygen);
  Angle->Edit4->Text = IntToStr(nvar);

  Angle->ShowModal();

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

        cc.X0 = -1*sign(true)*rgen(keygen,1,firstKf,lastKf);
        cc.Y0 = -1*sign(true)*rgen(keygen,1,firstKf,lastKf);
        cc.Z0 = -1*sign(true)*rgen(keygen,1,firstKf,lastKf);

        cc.A = sign(true)*rgen(keygen,1,firstKf,lastKf);
        cc.B = sign(true)*rgen(keygen,1,firstKf,lastKf);
        cc.C = sign(true)*rgen(keygen,1,firstKf,lastKf);
        cc.D = sign(true)*rgen(keygen,1,firstKf,lastKf);

        cc.l = sign(true)*zero(bZero)*rgen(keygen,1,firstKf,lastKf);
        cc.m = sign(true)*zero(bZero)*rgen(keygen,1,firstKf,lastKf);
        cc.n = sign(true)*zero(bZero)*rgen(keygen,1,firstKf,lastKf);

        //Сборка уравненения

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

        Right_Numb = random( 5 ) + 1;

        srand( keygen );

        for( i = 0; i < 4; i ++ )
        {
                /*plane[i] = pow(-1,random(amin)) * (random(amax) + 2);
                plane2[i] = pow(-1,random(amin)) * (random(amax) + 2);*/
                plane[i] = rgen( keygen, 1, amin, amax);
                plane2[i] = rgen( keygen, 1, amin, amax);
        }

        while( !plane[0] )
                plane[0] = rgen( keygen, 1, amin, amax );

        while( !plane2[0] )
                plane2[0] = rgen( keygen, 1, amin, amax );

        sprintf( buf, "String(\"# Тема - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Вариант   %i, задача %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Принт с двумя аргументами; Найти косинус угла между плоскостями.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(Плоскости заданы уравнениями:)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "alpha" );
        plist->Add( strdup(buf) );

        if( abs( plane[0] ) > 1 )
                sprintf( buf, "%d*x", plane[0] );
        else
        if( plane[0] < 0 )
                sprintf( buf, "-x" );
        else
                sprintf( buf, "x" );

        if ( abs( plane[1] ) > 1 )
                sprintf( buf1, "%+d*y", plane[1] );
        else
        if( plane[1] < 0 )
                sprintf( buf1, "-y" );
        else
        if ( plane[1] > 0 )
                sprintf( buf1, "+y" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( abs( plane[2] ) > 1 )
                sprintf( buf1, "%+d*z", plane[2] );
        else
        if ( plane[2] < 0 )
                sprintf( buf1, "-z" );
        else
        if ( plane[2] > 0 )
                sprintf( buf1, "+z", plane[2] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( plane[3] )
                sprintf( buf1, "%+d", plane[3] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        strcat( buf, "=0" );
        plist->Add( strdup(buf) );

        sprintf( buf, "beta" );
        plist->Add( strdup(buf) );

        if( abs( plane2[0] ) > 1 )
                sprintf( buf, "%d*x", plane2[0] );
        else
        if( plane2[0] < 0 )
                sprintf( buf, "-x" );
        else
                sprintf( buf, "x" );

        if ( abs( plane2[1] ) > 1 )
                sprintf( buf1, "%+d*y", plane2[1] );
        else
        if( plane2[1] < 0 )
                sprintf( buf1, "-y" );
        else
        if ( plane2[1] > 0 )
                sprintf( buf1, "+y" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( abs( plane2[2] ) > 1 )
                sprintf( buf1, "%+d*z", plane2[2] );
        else
        if ( plane2[2] < 0 )
                sprintf( buf1, "-z" );
        else
        if ( plane2[2] > 0 )
                sprintf( buf1, "+z", plane2[2] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( plane2[3] )
                sprintf( buf1, "%+d", plane2[3] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        strcat( buf, "=0" );
        plist->Add( strdup(buf) );


        sprintf( buf, "cos(!(alpha&beta))=...");
        plist->Add( strdup(buf) );

        scal = 0;
        absa = 0;
        absb = 0;

        for ( i = 0; i < 3; i ++ )
        {
                scal += plane[i] * plane2[i];
                absa += plane[i] * plane[i];
                absb += plane2[i] * plane2[i];
        }

        for( n = 0; n < 5; n ++ )
        {
                sprintf( buf, "String(\"Вариант %c):\")", 'a' + n );
                plist->Add( strdup(buf) );

                sprintf( buf, "cos(!(alpha&beta))=(" );

                if ( ( ceil( sqrt( absa ) ) == sqrt( absa ) ) && ( ceil( sqrt( absb ) ) == sqrt( absb ) ) )
                {
                        dr = drobi( scal - ( Right_Numb - 1 ) + n, sqrt( absa ) * sqrt( absb ) );

                        sprintf( buf1, "%s", DrobiToStr ( dr ) );
                        strcat( buf, buf1 );
                }
                else
                if ( ( ceil( sqrt( absa ) ) == sqrt( absa ) ) )
                {
                        dr = drobi( scal - ( Right_Numb - 1 ) + n, sqrt( absa ) );

                        sprintf( buf1, "%s/sqrt(%d)", DrobiToStr( dr ), absb );
                        strcat( buf, buf1 );
                }
                else
                if ( ( ceil( sqrt( absb ) ) == sqrt( absb ) ) )
                {
                        dr = drobi( scal - ( Right_Numb - 1 ) + n, sqrt( absb ) );

                        sprintf( buf1, "%s/sqrt(%d)", DrobiToStr ( dr ), absa );
                        strcat( buf, buf1 );
                }
                else
                {
                        if ( ceil ( sqrt ( absa * absb ) ) == sqrt ( absa * absb ) )
                        {
                                dr = drobi( scal - ( Right_Numb - 1 ) + n, sqrt (absa * absb ) );
                                sprintf( buf1, "%s", DrobiToStr( dr ) );
                        }
                        else
                        {
                                if( scal - ( Right_Numb - 1 ) + n )
                                        sprintf( buf1, "%d/(sqrt(%d)*sqrt(%d))=%d/(sqrt(%d*%d))", scal - ( Right_Numb - 1 ) + n, absa, absb, scal - ( Right_Numb - 1 ) + n, absa, absb );
                                else
                                        sprintf( buf1, "0" );
                        }
                        strcat( buf, buf1 );
                }

                strcat( buf, ")" );
                plist->Add( strdup(buf) );
        }

        /*sprintf(buf,"String(@Часть преподавателя )");
        plist->Add(strdup(buf));

        sprintf(buf,"String(\"Тема - %s \")",selecttask->name);
        plist->Add(strdup(buf));

        sprintf(buf,"String(ВАРИАНТ   %i, решение задачи %i, ключ %i)", nvar, nzad, keygen );
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


