//---------------------------------------------------------------------------
#ifndef queintegrndH
#define queintegrndH
//---------------------------------------------------------------------------
#include "tquest.h"
#include <stdio.h>

class queIntegRnd: public tquest
{
public:
    char* strpar1;
    char* strpar2;
    int rmin, rmax;
    int group;
    queIntegRnd(FILE* f);
    queIntegRnd(){};
    Save (FILE* f);
    copy (queIntegRnd* q)
    {
        strpar1 = strdup(q->strpar1);
        strpar2 = strdup(q->strpar2);
        group=q->group;
        rmin = q->rmin; rmax=q->rmax;
        tquest::copy(q);
        return 0;
    }
    void TruePrint(TList*, bool, class test*);
    Edit();
    Print(TList* plist);
    Print(TList* plist, class test &t);
};

#endif



 