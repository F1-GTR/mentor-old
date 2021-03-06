//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "quest19.h"
#include "drobi.h"
#include "MPdl.h"
#include "qvarnt.h"
#pragma hdrstop
#include "MLog.h"

#include "UtilsNG.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//      ���������� �� ����� �� ���������
//
//      dot: (x0,y0,z0)
//
//      plane:  A*x + B*y + C*z + D = 0
//
//      Generating kfc.:        (x0,x0,z0),(A,B,C,D)
//
//      answer:    d =abs( A*x0 + B*y0 + C*z0 + D) / ( sqrt( A^2 + B^2 +C^2 ) )
//
//---------------------------------------------------------------------------



#pragma package(smart_init)

quest19::quest19(FILE* f)
{
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

quest19::Save(FILE* f)
{
  fprintf(f,"head %i\n",type);
  fprintf(f,"%s\n",name);
  fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
  fprintf(f,"%s\n",strpar1);
  fprintf(f,"%s\n",strpar2);

  return 0;
}

quest19::Edit()
{
  sscanf(strpar2,"%i%i",&amin,&amax);

  keygen = 0;
  nvar = 1;

  PlaneLine->quest = this;

  PlaneLine->Edit1->Text = IntToStr(amin);
  PlaneLine->Edit2->Text = IntToStr(amax);
  PlaneLine->Edit3->Text = IntToStr(keygen);
  PlaneLine->Edit4->Text = IntToStr(nvar);

  PlaneLine->ShowModal();

  return 0;
}

quest19::Print(TList* plist)
{
        /* OLD CODE

        int i, p[4], n[4];

        double absb, absa;

        drobi d;

        char * buf = new char[256];
        char * buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        srand( keygen );

        for( i = 0; i < 4; i ++ )
        {
                n[i] = rgen( keygen, 1, amin, amax );
                p[i] = rgen( keygen, 1, amin, amax );
        }


        if( !n[0] )
                n[0] ++;

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
                sprintf( buf, "String(����� ���������� �� ����� �� ���������.)" );
                plist->Add( strdup(buf) );

                sprintf( buf, "String(��������� ������ ����������:)" );
                plist->Add( strdup(buf) );
        }

        if( abs( n[0] ) > 1 )
                sprintf( buf, "%d*x", n[0] );
        else
        if( n[0] < 0 )
                sprintf( buf, "-x" );
        else
        if( n[0] > 0 )
                sprintf( buf, "x" );

        if ( abs( n[1] ) > 1 )
                sprintf( buf1, "%+d*y", n[1] );
        else
        if( n[1] < 0 )
                sprintf( buf1, "-y" );
        else
        if( n[1] > 0 )
                sprintf( buf1, "+y" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( abs( n[2] ) > 1 )
                sprintf( buf1, "%+d*z", n[2] );
        else
        if( n[2] < 0 )
                sprintf( buf1, "-z" );
        else
        if( n[2] > 0 )
                sprintf( buf1, "+z" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( n[3] )
                sprintf( buf1, "%+d", n[3] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        strcat( buf, "=0" );
        plist->Add( strdup(buf) );


        if ( !qvar->MZad || ( qvar->MZad && nvar == 1 ) )
        {
                sprintf( buf, "String(���������� �����:)" );
                plist->Add( strdup(buf) );
        }

        sprintf( buf, "A!(%d", p[0] );
        for( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", p[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "d=..." );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(@����� ������������� )" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(\"���� - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(�������   %i, ������� ������ %i, ���� %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );

        absa = 0;
        for ( i = 0; i < 3; i ++ )
                absa += n[i] * p[i];

        absa -= n[3];

        absa = fabs( absa );

        absb = 0;

        for ( i = 0; i < 3; i ++ )
                absb += n[i] * n[i];

        if ( !absa )
                sprintf( buf, "d=0" );
        else
        if ( ( ceil( sqrt( absb ) ) ) == ( sqrt( absb ) ) )
        {
                d = drobi( absa, absb );
                //sprintf( buf, "d=%d/%d", d.a, d.b );
                sprintf( buf, "d=%s", DrobiToStr( d ) );
        }
        else
                sprintf( buf, "d=%f/sqrt(%f)", absa, absb );
        plist->Add( strdup(buf) );

        keygen = 0;

        delete buf;
        delete buf1;

        */
        /* --------------------- Kulikov 2015 ---------------------- */

        char* buf = new char[256];

        Log->Add("Q19 Printing to test..");

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
        } cc;

        cc.X0 = -1*sign()*rgen(keygen,1,amin,amax);
        cc.Y0 = -1*sign()*rgen(keygen,1,amin,amax);
        cc.Z0 = -1*sign()*rgen(keygen,1,amin,amax);

        cc.A = sign()*rgen(keygen,1,amin,amax);
        cc.B = sign()*rgen(keygen,1,amin,amax);
        cc.C = sign()*rgen(keygen,1,amin,amax);
        cc.D = sign()*rgen(keygen,1,amin,amax);

        //������ �����������

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


        sprintf( buf, "String(��������� ���������� ����� ������ � ����������. ������� ������ �����������:)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "M!(%d, %d, %d)", cc.X0,cc.Y0,cc.Z0);
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "alpha" );
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "(%d)*x+(%d)*y+(%d)*z+(%d)=0", cc.A,cc.B,cc.C,cc.D);
        plist->Add( strdup(buf) );
        Log->Add(buf);

          //������ ������

        //      answer:    d =abs( A*x0 + B*y0 + C*z0 + D) / ( sqrt( A^2 + B^2 +C^2 ) )

        sprintf( buf, "String(@����� ������������� )" );
        plist->Add( strdup(buf) );
        Log->Add(buf);


        sprintf( buf, "String(\"���� - %s \")", selecttask->name );
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "String(�������   %i, ������� ������ %i, ���� %i)", nvar, nzad, keygen );
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "d=abs(A*x0+B*y0+C*z0+D)/(sqrt(A^2+B^2+C^2))" );
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "d=abs((%d)*(%d)+(%d)*(%d)+(%d)*(%d)+(%d))/(sqrt((%d)^2+(%d)^2+(%d)^2))",cc.A,cc.X0,cc.B,cc.Y0,cc.C,cc.Z0,cc.D,cc.A,cc.B,cc.C);
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf,
                "d=%d/(sqrt(%d))",
                abs(cc.A*cc.X0+cc.B*cc.Y0+cc.C*cc.Z0+cc.D),
                cc.A*cc.A+cc.B*cc.B+cc.C*cc.C);
        plist->Add( strdup(buf) );
        Log->Add(buf);

        delete buf;

        Log->Add("Q19 Generating Complete");
        return 0;
}
//------------------------------------------------------------------------------

quest19::Print(TList* plist, class test &t)
{
        /* OLD CODE
        int i, p[4], n[4];
        int m, Right_Numb;
        int absb, absa;

        drobi d;

        char * buf = new char[256];
        char * buf1 = new char[256];

        if( keygen == 0 )
        {
                keygen = random( 1000 ) + 1;
        }

        Right_Numb = random( 5 ) + 1;

        srand( keygen );

        for( i = 0; i < 4; i ++ )
        {
                n[i] = rgen( keygen, 1, amin, amax );
                p[i] = rgen( keygen, 1, amin, amax );
        }

        //while( !n[0] )
        //      n[0] = rgen( keygen, 1, amin, amax );
        if( !n[0] )
                n[0] ++;

        sprintf( buf, "String(\"# ���� - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(�������   %i, ������ %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(����� ���������� �� ����� �� ���������.)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(��������� ������ ����������:)" );
        plist->Add( strdup(buf) );

        if( abs( n[0] ) > 1 )
                sprintf( buf, "%d*x", n[0] );
        else
        if( n[0] < 0 )
                sprintf( buf, "-x" );
        else
        if( n[0] > 0 )
                sprintf( buf, "x" );

        if ( abs( n[1] ) > 1 )
                sprintf( buf1, "%+d*y", n[1] );
        else
        if( n[1] < 0 )
                sprintf( buf1, "-y" );
        else
        if( n[1] > 0 )
                sprintf( buf1, "+y" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( abs( n[2] ) > 1 )
                sprintf( buf1, "%+d*z", n[2] );
        else
        if( n[2] < 0 )
                sprintf( buf1, "-z" );
        else
        if( n[2] > 0 )
                sprintf( buf1, "+z" );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        if ( n[3] )
                sprintf( buf1, "%+d", n[3] );
        else
                sprintf( buf1, "" );
        strcat( buf, buf1 );

        strcat( buf, "=0" );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(���������� �����:)" );
        plist->Add( strdup(buf) );

        sprintf( buf, "A!(%d", p[0] );
        for( i = 1; i < 3; i ++ )
        {
                sprintf( buf1, ",%d", p[i] );
                strcat( buf, buf1 );
        }

        strcat( buf, ")" );
        plist->Add( strdup(buf) );

        sprintf( buf, "d=..." );
        plist->Add( strdup(buf) );

        absa = 0;

        for ( i = 0; i < 3; i ++ )
                absa += n[i] * p[i];

        absa -= n[3];

        absa = abs( absa );

        absb = 0;

        for ( i = 0; i < 3; i ++ )
                absb += n[i] * n[i];

        if( absa < 5 )
                Right_Numb = 1;

        for( m = 0; m < 5; m ++ )
        {
                sprintf( buf, "String(\"������� %c):\")", 'a' + m );
                plist->Add( strdup(buf) );

                if ( !( absa - ( Right_Numb - 1 ) + m ) )
                        sprintf( buf, "d=0" );
                else
                if ( ( ceil( sqrt( absb ) ) ) == ( sqrt( absb ) ) )
                {
                        d = drobi( absa - ( Right_Numb - 1 ) + m, absb );
                        sprintf( buf, "d=%s", DrobiToStr( d ) );
                }
                else
                        sprintf( buf, "d=%d/sqrt(%d)", absa - ( Right_Numb - 1 ) + m, absb );
                plist->Add( strdup(buf) );
        }

        //sprintf(buf,"String(@����� ������������� )");
        //plist->Add(strdup(buf));

        //sprintf(buf,"String(\"���� - %s \")",selecttask->name);
        //plist->Add(strdup(buf));

        //sprintf(buf,"String(�������   %i, ������� ������ %i, ���� %i)", nvar, nzad, keygen );
        //plist->Add(strdup(buf));

        //sprintf(buf,"String( ���������� ����� - %c)", 'a' + Right_Numb - 1 );
        //plist->Add(strdup(buf));

        t.pr_tst = 1;
        t.ch_ask = 5;
        t.right_ask = Right_Numb;
        t.msg = "���� ������� ������������.";

        keygen = 0;


        delete buf;
        delete buf1;

           */

        /* ------------------ KULIKOV 2015 -------------------- */

         int Right_Numb = -1;

        char* buf = new char[256];

         Log->Add("Q19 Printing to Joomla test..");  

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
        } cc;

        cc.X0 = -1*sign()*rgen(keygen,1,amin,amax);
        cc.Y0 = -1*sign()*rgen(keygen,1,amin,amax);
        cc.Z0 = -1*sign()*rgen(keygen,1,amin,amax);

        cc.A = sign()*rgen(keygen,1,amin,amax);
        cc.B = sign()*rgen(keygen,1,amin,amax);
        cc.C = sign()*rgen(keygen,1,amin,amax);
        cc.D = sign()*rgen(keygen,1,amin,amax);

        //������ �����������

        sprintf( buf, "String(\"# ���� - %s \")", selecttask->name );
        plist->Add( strdup(buf) );

        sprintf( buf, "String(�������   %i, ������ %i.)", nvar, nzad );
        plist->Add( strdup(buf) );

         sprintf( buf, "String(��������� ���������� ����� ������ � ����������. ������� ������ �����������:)" );


        sprintf( buf, "M!(%d, %d, %d)", cc.X0,cc.Y0,cc.Z0);
        plist->Add( strdup(buf) );
        Log->Add(buf);

         sprintf( buf, "alpha" );
        plist->Add( strdup(buf) );
        Log->Add(buf);

        sprintf( buf, "(%d)*x+(%d)*y+(%d)*z+(%d)=0", cc.A,cc.B,cc.C,cc.D); 
        plist->Add( strdup(buf) );
        Log->Add(buf);

          //������ ������

        //      answer:    d =abs( A*x0 + B*y0 + C*z0 + D) / ( sqrt( A^2 + B^2 +C^2 ) )
        // ------------------------

         //generating variants
        Log->Add("Generating..");
        pAnswer pAns[4];

        //right variant
        pAns[0].legit = true;
         sprintf( pAns[0].str,
                "d=%d/(sqrt(%d))",
                abs(cc.A*cc.X0+cc.B*cc.Y0+cc.C*cc.Z0+cc.D),
                cc.A*cc.A+cc.B*cc.B+
                cc.C*cc.C);
        //wrong variant 1
        pAns[1].legit = false;
         sprintf( pAns[1].str,
                "d=%d/(sqrt(%d))",
                -abs(cc.A*cc.X0+cc.B*cc.Y0+cc.C*cc.Z0+cc.D),
                cc.A*cc.A+cc.B*cc.B+
                cc.C*cc.C);
         //wrong variant 2
        pAns[2].legit = false;
         sprintf( pAns[2].str,
                "d=%d/(sqrt(%d))",
                abs(cc.A*cc.X0+cc.B*cc.Y0+cc.C*cc.Z0+cc.D+random(5)),
                cc.A*cc.A+cc.B*cc.B+cc.C*cc.C);
         //wrong variant 3
        pAns[3].legit = false;
        sprintf( pAns[3].str,
                "d=%d/(sqrt(%d))",
                abs(cc.A*cc.B+cc.B*cc.C+cc.C*cc.A+cc.X0*cc.Y0*cc.Z0-20),
                cc.A*cc.A+cc.B*cc.B+cc.C*cc.C-1);


        //shuffle ;)   ---------------------------------------------------
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

        plist->Add(strdup("String(������� a: )"));
        plist->Add( strdup(pAns[0].str) );
        Log->Add(pAns[0].str);
                      sprintf( buf, "String( )" );
                  plist->Add( strdup(buf) );

        plist->Add(strdup("String(������� b: )"));
        plist->Add( strdup(pAns[1].str) );
        Log->Add(pAns[1].str);
                sprintf( buf, "String( )" );
                 plist->Add( strdup(buf) );

        plist->Add(strdup("String(������� c: )"));
        plist->Add( strdup(pAns[2].str) );
        Log->Add(pAns[2].str);
                sprintf( buf, "String( )" );
                  plist->Add( strdup(buf) );

        plist->Add(strdup("String(������� d: )"));
        plist->Add( strdup(pAns[3].str) );
        Log->Add(pAns[3].str);
                 sprintf( buf, "String( )" );
                  plist->Add( strdup(buf) );

        t.pr_tst = 1;
        t.ch_ask = 4;
        t.right_ask = Right_Numb;
        t.msg = "���� ������� ������������.";

        keygen = 0;

        delete buf;

        // ------------------------

        return 0;
}
//-----------------------------------------------------------


