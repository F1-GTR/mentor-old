//---------------------------------------------------------------------------
#ifndef quest30H
#define quest30H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest30: public tquest{
  public:
  char * strpar1;
  char * strpar2;
  int amin;
  int amax;
  int TypeQ;

  quest30( FILE* f );
  quest30(){};
  Save( FILE* f );
  copy( quest30* q)
  {
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    amin = q->amin;
    amax = q->amax;
    TypeQ = q->TypeQ;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

#endif
