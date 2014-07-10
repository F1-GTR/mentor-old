//---------------------------------------------------------------------------
#ifndef quest9H
#define quest9H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest9: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int amin;
  int amax;
  int QuestType;

  quest9(FILE* f);
  quest9(){};
  Save(FILE* f);
  copy(quest9* q){
    strpar1 = strdup(q->strpar1);
    strpar2 = strdup(q->strpar2);
    amin = q->amin;
    amax = q->amax;
    QuestType = q->QuestType;
    tquest::copy(q);
    return 0;
  }
  Edit();
  Print(TList* plist);
  Print(TList* plist, class test &t);
};

int determ(int, int [][2]);

#endif
