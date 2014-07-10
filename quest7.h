//---------------------------------------------------------------------------
#ifndef quest7H
#define quest7H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest7: public tquest{
  public:
  char* strpar1;
  char* strpar2;
/*  int kstrok;
  int kstolb;*/
  int amin;
  int amax;
  int rang;

  quest7(FILE* f);
  quest7(){};
  Save(FILE* f);
  copy(quest7* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    amin = q->amin;
    amax = q->amax;
    rang = q->rang;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

int determ(int, int [][10]);

#endif
