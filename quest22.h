//---------------------------------------------------------------------------
#ifndef quest22H
#define quest22H
//---------------------------------------------------------------------------
#include "tquest.h"
class quest22: public tquest{
  public:
  char* strpar1;
  char* strpar2;
//  int kstrok;
  int numstr;
  int amin;
  int amax;
  int dim;
  int typeos;

  quest22(FILE* f);
  quest22(){};
  Save(FILE* f);
  copy(quest22* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    numstr = q->numstr;
    amin = q->amin;
    amax = q->amax;
    dim = q->dim;
    typeos = q->typeos;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

#endif
