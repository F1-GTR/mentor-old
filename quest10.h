//---------------------------------------------------------------------------
#ifndef quest10H
#define quest10H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest10: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int amin;
  int amax;
  int TypeQ;

  quest10(FILE* f);
  quest10(){};
  Save(FILE* f);
  copy(quest10* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    amin = q->amin;
    amax = q->amax;
    TypeQ = q->TypeQ;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

#endif
