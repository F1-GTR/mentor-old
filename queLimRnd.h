//---------------------------------------------------------------------------
#ifndef quelimrndH
#define quelimrndH
//---------------------------------------------------------------------------
#include "tquest.h"
#include <stdio.h>

class quelimrnd: public tquest
{
public:
    char* strpar1;
    char* strpar2;
    int rmin, rmax;
    int groupoflims;
    quelimrnd(FILE* f);
    quelimrnd(){};
    Save (FILE* f);
    copy (quelimrnd* q)
    {
        strpar1 = strdup(q->strpar1);
        strpar2 = strdup(q->strpar2);
        groupoflims=q->groupoflims;
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

 