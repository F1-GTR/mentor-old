//---------------------------------------------------------------------------
#ifndef quelim01H
#define quelim01H
//---------------------------------------------------------------------------
#include "tquest.h"
#include <stdio.h>

class quelim01: public tquest
{
public:
    char* strpar1;
    char* strpar2;
    bool debug;
    int rmin, rmax;
    int typeoflim;
    quelim01(FILE* f);
    quelim01(){};
    Save (FILE* f);
    copy (quelim01* q)
    {
        strpar1 = strdup(q->strpar1);
        strpar2 = strdup(q->strpar2);
        typeoflim=q->typeoflim;
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

