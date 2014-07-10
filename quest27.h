//---------------------------------------------------------------------------
#ifndef quest27H
#define quest27H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest27: public tquest{
  public:
  char * strpar1;
  char * strpar2;
  int amin;
  int amax;

  quest27(FILE* f);
  quest27(){};
  Save(FILE* f);
  copy(quest27* q)
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

#endif
