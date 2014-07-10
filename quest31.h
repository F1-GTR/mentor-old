//---------------------------------------------------------------------------
#ifndef quest31H
#define quest31H
//---------------------------------------------------------------------------
#include "tquest.h"

class quest31: public tquest{
  public:
  char * strpar1;
  char * strpar2;
  int number;
  int a;
  int b;
  int n;

  quest31( FILE * f );
  quest31(){};
  Save( FILE * f );
  copy( quest31 * q ){
    strpar1 = strdup( q->strpar1 );
    strpar2 = strdup( q->strpar2 );
    a = q->a;
    b = q->b;
    n = q->n;
    number = q->number;
    tquest::copy( q );
    return 0;
  }
  Edit();
  Print( TList * plist );
  Print( TList * plist, class test &t );
};

#endif
