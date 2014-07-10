//---------------------------------------------------------------------------
#ifndef tkursH
#define tkursH
//---------------------------------------------------------------------------
#include "global.h"
#include "bmentor.h"
class tkurs: public bmentor{
  public:
  TList* qlist;

  tkurs(char* fname);
  Save(char* fname);

//  void Save(char* fname);
};
#endif
