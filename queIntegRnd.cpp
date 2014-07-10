#include <vcl.h>
#include <stdlib.h>
#include "queinteg.h"
#include "queintegrnd.h"
#include "mintegrnd.h"
#include "qvarnt.h"
#include "m_expressions.h"
#pragma hdrstop
#pragma package(smart_init)

range groups[] =
{
    range (1,    10  ),
    range (11,   15  ),
    range (16,   17  ),
    range (18,   20  ),
    range (21,   28  ),
    range (32,   35  ),
    range (111,  119 ),
    range (120,  131 ),
    range (132,  143 ),
    range (144,  154 ),
    range (155,  166 ),
    range (179,  190 ),
    range (191,  202 ),
    range (203,  214 ),
    range (17,   24  ),
    range (25,   30  ),
    range (217,  224 ),
    range (33,   40  ),
    range (215,  216 )
};

queIntegRnd::queIntegRnd (FILE* f)
{
    // генерация ключа
    keygen=random(1000)+1;
    // чтение параметров
    char buf[256];
    reads(f, buf); strpar1 = strdup(buf);
    reads(f, buf); strpar2 = strdup(buf);
    // разбор параметров
    sscanf(strpar1, "%d %i %i\n", &group, &rmin, &rmax);
    // инициализация типа вопроса
    qtype = type;
}

queIntegRnd::Save(FILE* f)
{ // не знаю, для чего
    fprintf(f,"head %i\n",type);
    fprintf(f,"%s\n",name);
    fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
    fprintf(f,"%s\n",strpar1);
    fprintf(f,"%s\n",strpar2);
    return 0;
}

// вызвать окно генератора?
queIntegRnd::Edit()
{
    sscanf(strpar2, "%d%d%d", &group, &rmin, &rmax);
    // инициализация ключа и номера варианта
    keygen=0; nvar=1;
    // установка параметров в окне и показ окна
    IntegRnd->quest=this;
    IntegRnd->etype->Text = IntToStr(group);
    IntegRnd->rmin->Text = IntToStr(rmin); IntegRnd->rmax->Text = IntToStr(rmax);
    IntegRnd->ShowModal();
    return 0;
}

void queIntegRnd::TruePrint (TList* plist, bool make_answers=false, class test* t=NULL)
{
    int id = rndr(groups[group-1]);
    queInteg *gen = new queInteg;
    gen->keygen = keygen;
    gen->bmentor::copy(this);
    gen->nzad = nzad;
    gen->Integid = id;
    gen->rmin = rmin;
    gen->rmax = rmax;
    gen->TruePrint(plist, make_answers, t);
    keygen = gen->keygen;
    delete gen;
}

queIntegRnd::Print(TList* plist)
{ // функция вывода задания (без ответов)
    TruePrint(plist);
    return 0;
}

queIntegRnd::Print(TList* plist, class test &t)
{ // вывод с вариантами ответа?
    TruePrint(plist, true, &t);
    return 0;
}

