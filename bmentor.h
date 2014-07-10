#ifndef BMENTOR_H
#define BMENTOR_H
#include "global.h"
#include "test_class.h"

class bmentor{
  public:
  static int inumber;
  static bmentor* selectquest;
  static bmentor* selecttask;

  int number;
  int itemnumber;
  int subitemnumber;
  int type;
  int nvar;
  int nquest;
  char* name;
  int numbertask;
  int nzad;
  int keygen;

  bmentor();
  virtual Save(FILE* f);
  copy(bmentor* q)
  {
    number = q->number;
    itemnumber = q->itemnumber;
    subitemnumber = q->subitemnumber;
    type = q->type;
    nvar = q->nvar;
    nquest = q->nquest;
    name = q->name;
    numbertask = q->numbertask;
    keygen = q->keygen;
    return 0;
  };
  virtual Edit()
  {
        FError("Для вопроса данного типа редактирование не реализовано",0);
        return 0;
  }
  virtual Print(TList* l)
  {
        FError("Для вопроса данного типа редактирование не реализовано",0);
        return 0;
  }
  virtual Print(TList* l, class test &t)
  {
        FError("Для вопроса данного типа редактирование не реализовано",0);
        return 0;
  }
};
#endif