//---------------------------------------------------------------------------
#ifndef queIntegH
#define queIntegH
//---------------------------------------------------------------------------
#include "tquest.h"
#include <stdio.h>

class queInteg: public tquest
{
public:
    char* strpar1;
    char* strpar2;
    bool debug;
    int rmin, rmax;
    int Integid;
    queInteg(FILE* f);
    queInteg(){};
    Save (FILE* f);
    copy (queInteg* q)
    {
        strpar1 = strdup(q->strpar1);
        strpar2 = strdup(q->strpar2);
        Integid=q->Integid;
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

 