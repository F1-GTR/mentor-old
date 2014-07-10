#include <vcl.h>
#include <stdlib.h>
#include "quelim01.h"
#include "quelimrnd.h"
#include "limrnd.h"
#include "qvarnt.h"
#include "m_expressions.h"
#pragma hdrstop
#pragma package(smart_init)
range groups[] = {
    range(1,16),
    range(17,32),
    range(31,69),
    range(70,91),
    range(92,112)
};

quelimrnd::quelimrnd (FILE* f)
{
    // генерация ключа
    keygen=random(1000)+1;
    // чтение параметров
    char buf[256];
    reads(f, buf); strpar1 = strdup(buf);
    reads(f, buf); strpar2 = strdup(buf);
    // разбор параметров
    sscanf(strpar1, "%d %i %i\n", &groupoflims, &rmin, &rmax);
    // инициализация типа вопроса
    qtype = type;
}

quelimrnd::Save(FILE* f)
{ // не знаю, для чего
    fprintf(f,"head %i\n",type);
    fprintf(f,"%s\n",name);
    fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
    fprintf(f,"%s\n",strpar1);
    fprintf(f,"%s\n",strpar2);
    return 0;
}

// вызвать окно генератора?
quelimrnd::Edit()
{
    sscanf(strpar2, "%d%d%d", &groupoflims, &rmin, &rmax);
    // инициализация ключа и номера варианта
    keygen=0; nvar=1;
    // установка параметров в окне и показ окна
    FLimRnd->quest=this;
    FLimRnd->etype->Text = IntToStr(groupoflims);
    FLimRnd->rmin->Text = IntToStr(rmin); FLimRnd->rmax->Text = IntToStr(rmax);
    FLimRnd->ShowModal();
    return 0;
}

void quelimrnd::TruePrint (TList* plist, bool make_answers=false, class test* t=NULL)
{
    int limid = rndr(groups[groupoflims-1]);
    quelim01 *limgen = new quelim01;
    limgen->bmentor::copy(this);
    limgen->nzad = nzad;
    limgen->typeoflim = limid;
    limgen->rmin = rmin;
    limgen->rmax = rmax;
    limgen->TruePrint(plist, make_answers, t);
    keygen = limgen->keygen;
    delete limgen;
}

quelimrnd::Print(TList* plist)
{ // функция вывода задания (без ответов)
    TruePrint(plist);
    return 0;
}

quelimrnd::Print(TList* plist, class test &t)
{ // вывод с вариантами ответа?
    TruePrint(plist, true, &t);
    return 0;
}

