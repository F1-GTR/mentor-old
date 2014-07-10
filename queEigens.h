//---------------------------------------------------------------------------
#ifndef queeigensH
#define queeigensH
//---------------------------------------------------------------------------
#include "tquest.h"
#include <stdio.h>

class queeigens: public tquest
{
public:
    char* strpar1;
    char* strpar2;
    int size;
    int variouseigens;
    queeigens(FILE* f);
    queeigens(){};
    Save (FILE* f);
    copy (queeigens* q)
    {
        strpar1 = strdup(q->strpar1);
        strpar2 = strdup(q->strpar2);
        size = q->size;
        variouseigens = q->variouseigens;
        tquest::copy(q);
        return 0;
    }
    void TruePrint(TList*, bool, class test*);
    Edit();
    Print(TList* plist);
    Print(TList* plist, class test &t);
};

#endif
