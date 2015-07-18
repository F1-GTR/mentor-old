#ifndef quest33H
#define quest33H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest33: public tquest{
  public:
  char* strpar1;
  char* strpar2;

  struct
  {
        int top, bot;
  } min,max;

  quest33(FILE* f);
  quest33(){};
  Save(FILE* f);
  copy(quest33* q){
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