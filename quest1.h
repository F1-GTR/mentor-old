//---------------------------------------------------------------------------
#ifndef quest1H
#define quest1H
//---------------------------------------------------------------------------
#include "tquest.h"
class quest1: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int kstrok;
  int kstolb;
  int amin;
  int amax;

  quest1(FILE* f);
  quest1(){};
  Save(FILE* f);
  copy(quest1* q){
    strpar1=strdup(q->strpar1);
    strpar2=strdup(q->strpar2);
    kstrok=q->kstrok;
    kstolb=q->kstolb;
    amin=q->amin;
    amax=q->amax;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};
#endif
