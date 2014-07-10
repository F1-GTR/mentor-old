//---------------------------------------------------------------------------
#ifndef quest3H
#define quest3H
//---------------------------------------------------------------------------
#include "tquest.h"
class quest3: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int kstrok;
  int kstolb;
  int knull;
  int amin;
  int amax;

  quest3(FILE* f);
  quest3(){};
  Save(FILE* f);
  copy(quest3* q){
    strpar1=strdup(q->strpar1);
    strpar2=strdup(q->strpar2);
    kstrok=q->kstrok;
    kstolb=q->kstolb;
    amin=q->amin;
    amax=q->amax;
    knull=q->knull;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};
#endif//---------------------------------------------------------------------------

