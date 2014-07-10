//---------------------------------------------------------------------------
#ifndef quederivrndH
#define quederivrndH
//---------------------------------------------------------------------------
#include "tquest.h"
#include <stdio.h>

class quederivrnd: public tquest
{
public:
    char* strpar1;
    char* strpar2;
    int rmin, rmax;
    int groupofderivs;
    quederivrnd(FILE* f);
    quederivrnd(){};
    Save (FILE* f);
    copy (quederivrnd* q)
    {
        strpar1 = strdup(q->strpar1);
        strpar2 = strdup(q->strpar2);
        groupofderivs=q->groupofderivs;
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


 