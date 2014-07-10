//---------------------------------------------------------------------------
#ifndef tkursH
#define tkursH
//---------------------------------------------------------------------------
#include "global.h"
#include "bmentor.h"

//nekiy klass, predpolojitel'no ykazatel' na MTR fail
class tkurs: public bmentor{
  public:
  TList* qlist;

  tkurs(char* fname);
  Save(char* fname);

//  void Save(char* fname);
};
#endif
