//---------------------------------------------------------------------------
#ifndef quest5H
#define quest5H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest5: public tquest{
  public:
  char* strpar1;
  char* strpar2;
/*  int kstrok;
  int kstolb;*/
  int amin;
  int amax;
  int dim;

  quest5(FILE* f,int);
  quest5(){};
  Save(FILE* f);
  copy(quest5* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
/*    kstrok=q->kstrok;
    kstolb=q->kstolb;*/
    amin = q->amin;
    amax = q->amax;
    dim = q->dim;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

int determ(int, int [][10]);

#endif
