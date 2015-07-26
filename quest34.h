#ifndef quest34H
#define quest34H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest34: public tquest{
  public:
  char* strpar1;
  char* strpar2;

  struct
  {
        int top, bot;
  } min,max;

  quest34(FILE* f);
  quest34(){};
  Save(FILE* f);
  copy(quest34* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    min = q->min;
    max = q->max;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

#endif
 