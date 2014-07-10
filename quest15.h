//---------------------------------------------------------------------------
#ifndef quest15H
#define quest15H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest15: public tquest{
  public:
  char* strpar1;
  char* strpar2;
  int amin;
  int amax;
//  int dim;

  quest15(FILE* f);
  quest15(){};
  Save(FILE* f);
  copy(quest15* q){
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


/*void draw(int x0, int y0, int x, int y, Graphics::TBitmap*);
double funk( int x, int a, int b);
double gline(int x, int a, int b);*/
#endif
