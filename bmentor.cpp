//---------------------------------------------------------------------------
#include <vcl.h>
#include "bmentor.h"
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)

bmentor::bmentor(){
  number = 0;
  itemnumber = 0;
  subitemnumber = 0;
  type = ITEM;
  name = strdup("��� ����");
  numbertask = 0;
};

bmentor::Save(FILE* f){
  if(type==ITEM||type==SUBITEM||type==JOB){
    fprintf(f,"head %i\n",type);
    fprintf(f,"%s\n",name);
  }
  else{
    FError("������� Save ��� ������� ������ �� ���������",0);
  }
  return 0;
};
