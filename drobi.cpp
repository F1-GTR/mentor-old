#include <vcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "drobi.h"
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)

drobi::drobi()
{
        a = 0;
        b = 1;
        c = 0;
        znak = 1;
}
//-----------------------------------------------------------

drobi::drobi( int ch )
{
        a = ch;
        b = 1;
        c = ch;

        if ( ch >= 0 )
                znak = 1;
        else
        {
                znak = -1;
                a *= -1;
        }
}
//--------------------------------------------------------------

char * DrobiToStr( drobi a )
{
        char * temp = new char[36];

        if ( a.a )
        {
                if ( a.b != 1 )
                {
                        if ( a.znak <= 0 )
                                sprintf( temp, "-(%d/%d)", a.a, a.b );
                        else
                                //sprintf( temp, "(%d/%d)", a.a, a.b );
                                sprintf( temp, "%d/%d", a.a, a.b );
                }
                else
                {
                        //if ( a.a != 1 )
                        //sprintf( temp, "%d", a.a );
                        if ( a.znak <= 0 )
                                sprintf( temp, "-(%d)", a.a );
                        else
                                //sprintf( temp, "(%d)", a.a );
                                sprintf( temp, "%d", a.a );
                        /*else
                                sprintf( temp, "" );*/
                }
        }
        else
                strcpy( temp, "0" );

        return temp;
}
//-----------------------------------------------------------

drobi drobi::operator+( drobi y )
{
        drobi temp;

        temp.a = znak * a * y.b + y.znak * y.a * b;
        temp.b = b * y.b;
        temp.c = ( double )temp.a / temp.b;

        if ( temp.a >=0 )
                temp.znak = 1;
        else
        {
                temp.znak = -1;
                temp.a *= -1;
        }

        temp.sokrat();

        return temp;
}
//------------------------------------------------------------------

drobi drobi::operator-( drobi y )
{
        drobi temp;

        temp.a = znak * a * y.b - y.znak * y.a * b;
        temp.b = b * y.b;
        temp.c = ( double )temp.a / temp.b;

        if ( temp.a >=0 )
                temp.znak = 1;
        else
        {
                temp.znak = -1;
                temp.a *= -1;
        }

        temp.sokrat();

        return temp;
}
//-----------------------------------------------------------------

drobi drobi::operator*( drobi y )
{
        drobi temp;

        temp.a = a * y.a;
        temp.b = b * y.b;
        temp.c = ( double ) znak * y.znak * temp.a / temp.b;

        temp.znak = znak * y.znak;

        temp.sokrat();

        return temp;
}
//---------------------------------------------------------------------

drobi drobi::operator/( drobi y )
{
        drobi temp;

        temp.a = a * y.b;
        temp.b = b * y.a;
        temp.c = ( double ) znak * y.znak * temp.a / temp.b;

        temp.znak = znak * y.znak;

        temp.sokrat();

        return temp;
}
//---------------------------------------------------------------

drobi::operator==( drobi y )
{
        sokrat();
        y.sokrat();

        if ( a == y.a && b == y.b )
                return 1;
        else
                return 0;
}
//---------------------------------------------------------------

drobi::min(int a, int b)
{
        if ( a < b )
                return a;
        else
                return b;
}
//---------------------------------------------------------------

drobi::sokrat()
{
        int i,temp,a1,b1;

        temp = min(a,b);

        for (i = 2; i <= temp; i ++)
        {
                temp = min(a,b);
                a1 = a%i;
                b1 = b%i;

                if( !a1 && !b1 )
                {
                        a /= i;
                        b /= i;

                        i = 1;
                }
        }

        return 0;
}
//------------------------------------------------------------

drobi::drobi(int x, int y)
{
        a = x;
        b = y;

        if (  y != 0 )
                c = (double)x/y;
        else
                c = 0;

        if (b < 0 && a != 0 )
        {
                a *= -1;
                b *= -1;
        }

        if (a < 0)
        {
                znak = -1;
                a *= -1;
        }
        else
                znak = 1;

        sokrat();
}
//----------------------------------------------------------------

double drobi::chislo()
{
        c = (double) a/b;
        return c;
}
//------------------------------------------------------------------------------
