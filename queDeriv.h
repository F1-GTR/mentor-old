//---------------------------------------------------------------------------
#ifndef queDerivH
#define queDerivH
//---------------------------------------------------------------------------
#include "tquest.h"
#include <stdio.h>

class queDeriv: public tquest
{
public:
    char* strpar1;
    char* strpar2;
    bool debug;
    int rmin, rmax;
    int derivid;
    queDeriv(FILE* f);
    queDeriv(){};
    Save (FILE* f);
    copy (queDeriv* q)
    {
        strpar1 = strdup(q->strpar1);
        strpar2 = strdup(q->strpar2);
        derivid=q->derivid;
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
 