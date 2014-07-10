//---------------------------------------------------------------------------
#ifndef quest21H
#define quest21H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest21: public tquest{
  public:
  char* strpar1;
  char* strpar2;
/*  int kstrok;
  int kstolb;*/
  int amin;
  int amax;
  int rang;
  int dim;

  quest21(FILE* f);
  quest21(){};
  Save(FILE* f);
  copy(quest21* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    amin = q->amin;
    amax = q->amax;
    rang = q->rang;
    dim = q->dim;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

#endif
