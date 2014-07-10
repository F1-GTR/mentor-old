//---------------------------------------------------------------------------
#ifndef quest6H
#define quest6H
//---------------------------------------------------------------------------
#include "tquest.h"
#include <math.h>

class quest6: public tquest{
  public:
  char* strpar1;
  char* strpar2;
/*  int kstrok;
  int kstolb;*/
  int number;
  int a;
  int b;
  int n;

  quest6(FILE* f);
  quest6(){};
  Save(FILE* f);
  copy(quest6* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    a = q->a;
    b = q->b;
    n = q->n;
    number = q->number;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

#endif
