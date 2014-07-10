//---------------------------------------------------------------------------
#include <vcl.h>
#include "GetFunc.h"
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)

int rgen(int key,int n, int min,int max)
{
        int a = min;

//     a=min+(max-min+0.8)*0.5*(sin(6.2832/150.*n*key)+1.);

        a = min + random( max - min + 1 );

        if ( a = 0)
                a = 1;

        return a;
}
