//---------------------------------------------------------------------------
#ifndef queMFlabsH
#define queMFlabsH
//---------------------------------------------------------------------------
#include "tquest.h"
#include <stdio.h>

class queMFlabs: public tquest
{
public:
    char* strpar1;
    char* strpar2;
    bool debug;
    int rmin, rmax;
    int labid;
    queMFlabs(FILE* f);
    queMFlabs(){};
    Save (FILE* f);
    copy (queMFlabs* q)
    {
        strpar1 = strdup(q->strpar1);
        strpar2 = strdup(q->strpar2);
        labid=q->labid;
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

