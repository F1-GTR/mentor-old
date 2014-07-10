#include <vcl.h>
#include <stdlib.h>
#include "quederiv.h"
#include "quederivrnd.h"
#include "mderivrnd.h"
#include "qvarnt.h"
#include "m_expressions.h"
#pragma hdrstop
#pragma package(smart_init)

range groups[] = {
    range(  1,    8 ),   /*  01  */
    range(  9,   16 ),   /*  02  */
    range( 67,   77 ),   /*  03  */
    range( 78,   88 ),   /*  04  */
    range( 89,   99 ),   /*  05  */
    range(100,  110 ),   /*  06  */
    range(111,  119 ),   /*  07  */
    range(120,  131 ),   /*  08  */
    range(132,  143 ),   /*  09  */
    range(144,  154 ),   /*  10  */
    range(155,  166 ),   /*  11  */
    range(179,  190 ),   /*  12  */
    range(191,  202 ),   /*  13  */
    range(203,  214 ),   /*  14  */
    range( 17,   24 ),   /*  15  */
    range( 25,   30 ),   /*  16  */
    range(219,  226 ),   /*  17  */
    range(227,  241 ),   /*  18  */
    range( 33,   40 ),   /*  19  */
    range(215,  218 )    /*  20  */
};



quederivrnd::quederivrnd (FILE* f)
{
    // генерация ключа
    keygen=random(1000)+1;
    // чтение параметров
    char buf[256];
    reads(f, buf); strpar1 = strdup(buf);
    reads(f, buf); strpar2 = strdup(buf);
    // разбор параметров
    sscanf(strpar1, "%d %i %i\n", &groupofderivs, &rmin, &rmax);
    // инициализация типа вопроса
    qtype = type;
}

quederivrnd::Save(FILE* f)
{ // не знаю, для чего
    fprintf(f,"head %i\n",type);
    fprintf(f,"%s\n",name);
    fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
    fprintf(f,"%s\n",strpar1);
    fprintf(f,"%s\n",strpar2);
    return 0;
}

// вызвать окно генератора?
quederivrnd::Edit()
{
    sscanf(strpar2, "%d%d%d", &groupofderivs, &rmin, &rmax);
    // инициализация ключа и номера варианта
    keygen=0; nvar=1;
    // установка параметров в окне и показ окна
    DerivRnd->quest=this;
    DerivRnd->etype->Text = IntToStr(groupofderivs);
    DerivRnd->rmin->Text = IntToStr(rmin); DerivRnd->rmax->Text = IntToStr(rmax);
    DerivRnd->ShowModal();
    return 0;
}

void quederivrnd::TruePrint (TList* plist, bool make_answers=false, class test* t=NULL)
{
    int derivid = rndr(groups[groupofderivs-1]);
    queDeriv *derivgen = new queDeriv;
    derivgen->keygen = keygen;
    derivgen->bmentor::copy(this);
    derivgen->nzad = nzad;
    derivgen->derivid = derivid;
    derivgen->rmin = rmin;
    derivgen->rmax = rmax;
    derivgen->TruePrint(plist, make_answers, t);
    keygen = derivgen->keygen;
    delete derivgen;
}

quederivrnd::Print(TList* plist)
{ // функция вывода задания (без ответов)
    TruePrint(plist);
    return 0;
}

quederivrnd::Print(TList* plist, class test &t)
{ // вывод с вариантами ответа?
    TruePrint(plist, true, &t);
    return 0;
}

