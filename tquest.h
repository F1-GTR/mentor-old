#ifndef TQUEST_H
#define TQUEST_H
#include "global.h"
#include "bmentor.h"
class tquest: public bmentor{
  public:
  int qtype;
//  int numbertask;

  tqwest(FILE* f){qtype=0; return 0;};
  copy(tquest* q){
    qtype=q->qtype;
    numbertask=q->numbertask;
    bmentor::copy(q);
    return 0;
  }

//  void Save(char* fname);
};
tquest* qcreate(tquest* q);
#endif


