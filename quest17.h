//---------------------------------------------------------------------------
#ifndef quest17H
#define quest17H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest17: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int amin;
  int amax;
  int number;

  quest17(FILE* f);
  quest17(){};
  Save(FILE* f);
  copy(quest17* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    amin = q->amin;
    amax = q->amax;
    number = q->number;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

int determ( int [][3]);

#endif
