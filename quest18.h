//---------------------------------------------------------------------------
#ifndef quest18H
#define quest18H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest18: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int amin;
  int amax;
//  int dim;

  quest18(FILE* f);
  quest18(){};
  Save(FILE* f);
  copy(quest18* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    amin = q->amin;
    amax = q->amax;
//    dim = q->dim;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

int determ(int, int [][2]);

#endif
