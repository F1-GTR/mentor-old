//---------------------------------------------------------------------------
#ifndef quest8H
#define quest8H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest8: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int amin;
  int amax;
  int dim;
  int number;

  quest8(FILE* f);
  quest8(){};
  Save(FILE* f);
  copy(quest8* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
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
