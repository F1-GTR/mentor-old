//---------------------------------------------------------------------------
#ifndef quest4H
#define quest4H
//---------------------------------------------------------------------------
#include "tquest.h"
class quest4: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int kstrok;
  int kstolb;
  int amin;
  int amax;
  int dim;

  quest4(FILE* f);
  quest4(){};
  Save(FILE* f);
  copy(quest4* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    kstrok = q->kstrok;
    kstolb = q->kstolb;
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

int determ( int dim, int ma[][10] );
#endif
