//---------------------------------------------------------------------------
#ifndef quest26H
#define quest26H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest26: public tquest{
  public:
  char * strpar1;
  char * strpar2;
  int amin;
  int amax;

  quest26(FILE* f);
  quest26(){};
  Save(FILE* f);
  copy(quest26* q)
  {
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    amin = q->amin;
    amax = q->amax;
//    TypeQ = q->TypeQ;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

int determ(int, int [][2]);

#endif
