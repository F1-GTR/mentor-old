//---------------------------------------------------------------------------
#ifndef quest25H
#define quest25H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest25: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int amin;
  int amax;
//  int dim;

  quest25( FILE* f );
  quest25(){};
  Save( FILE* f );
  copy( quest25* q)
  {
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
