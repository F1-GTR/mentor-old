//---------------------------------------------------------------------------
#ifndef quest2H
#define quest2H
//---------------------------------------------------------------------------
#include "tquest.h"
#include "test_class.h"
class quest2: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int kstrok;
  int kstolb;
  int amin;
  int amax;

  quest2(FILE* f);
  quest2(){};
  Save(FILE* f);
  copy(quest2* q){
    strpar1=strdup(q->strpar1);
    strpar2=strdup(q->strpar2);
    kstrok=q->kstrok;
    kstolb=q->kstolb;
    amin=q->amin;
    amax=q->amax;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};
#endif
//---------------------------------------------------------------------------


