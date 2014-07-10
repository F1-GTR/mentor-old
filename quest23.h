//---------------------------------------------------------------------------
#ifndef quest23H
#define quest23H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest23: public tquest{
  public:
  char* strpar1;
  char* strpar2;
/*  int kstrok;
  int kstolb;*/
  int amin;
  int amax;
  int dim;
  int number;

  quest23(FILE* f);
  quest23(){};
  Save(FILE* f);
  copy(quest23* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
/*    kstrok=q->kstrok;
    kstolb=q->kstolb;*/
    amin = q->amin;
    amax = q->amax;
    dim = q->dim;
    number = q->number;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

#endif
