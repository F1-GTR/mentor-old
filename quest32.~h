#ifndef quest32H
#define quest32H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest32: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int amin;
  int amax;
  struct
  {
                int point;
                int vector;
                int plate;
  } min,max;
//  int dim;

  quest32(FILE* f);
  quest32(){};
  Save(FILE* f);
  copy(quest32* q){
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

#endif