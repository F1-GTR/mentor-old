#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "queMFlabs.h"
#include "TMFlabs.h"
#include "qvarnt.h"
#include "m_MFlab.h"
#include "m_expressions.h"
#pragma hdrstop
#pragma package(smart_init)

queMFlabs::queMFlabs (FILE* f)
{
    // генерация ключа
    keygen=random(1000)+1;
    // чтение параметров
    char buf[256];
    reads(f, buf); strpar1 = strdup(buf);
    reads(f, buf); strpar2 = strdup(buf);
    // разбор параметров
    sscanf(strpar1, "%d %i %i\n", &labid, &rmin, &rmax);
    debug=false;
    // инициализация типа вопроса
    qtype = type;
}

queMFlabs::Save(FILE* f)
{ // не знаю, для чего
    fprintf(f,"head %i\n",type);
    fprintf(f,"%s\n",name);
    fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
    fprintf(f,"%s\n",strpar1);
    fprintf(f,"%s\n",strpar2);
    return 0;
}

// вызвать окно генератора?
queMFlabs::Edit()
{
    sscanf(strpar2, "%d%d%d", &labid, &rmin, &rmax);
    // инициализация ключа и номера варианта
    keygen=0; nvar=1;
    // установка параметров в окне и показ окна
    FMFlabs->quest=this;
    FMFlabs->etype->Text = IntToStr(labid);
    FMFlabs->rmin->Text = IntToStr(rmin); FMFlabs->rmax->Text = IntToStr(rmax);
    FMFlabs->ShowModal();
    return 0;
}

void addstringtolist (char *str, TList *plist)
{
    char lines[10][BUFSZ];
    int n=split_str(str, lines);
    for(int i=0; i<n; ++i)
        plist->Add(strdup(lines[i]));
}

void queMFlabs::TruePrint (TList* plist, bool make_answers=false, class test* t=NULL)
{
    char str[500];
    if (keygen==0) keygen=random(1000)+1;
    srand(keygen);

    if (!qvar->MZad||(qvar->MZad&&nvar==1))
    {
        sprintf(str, "String(\"# Тема - %s \")", selecttask->name);
        plist->Add(strdup(str));
    }
    else
    {
        sprintf(str, "String(#)");
        plist->Add(strdup(str));
    }
    sprintf(str, "String(\"Вариант   %i, задача %i.\")", nvar, nzad); plist->Add(strdup(str));

    /*
    if (!qvar->MZad||(qvar->MZad&&nvar==1))
    {
        sprintf(str, "String(\"Найти дифференциальное уравнение:\")");
        plist->Add(strdup(str));
    }
    */

    bool done;
    range r(rmin, rmax);
    char labt[BUFSZ*4];
    switch(labid)
    {
        case  1: mflab01(r, labt); break;
        case  2: mflab02(r, labt); break;
        case  3: mflab03(r, labt); break;
        case  4: mflab04(r, labt); break;
        case  5: mflab05(r, labt); break;
        case  6: mflab06(r, labt); break;
        case  7: mflab07(r, labt); break;
        case  8: mflab08(r, labt); break;
        case  9: mflab09(r, labt); break;
        case  10: mflab10(r, labt); break;
        case  11: mflab11(r, labt); break;
        default: ShowMessage("Error\nUnknown MFlab ID"); break;
    }

    char text[BUFSZ], text1[10][BUFSZ];
    char answ[10][BUFSZ], answ1[10][10][BUFSZ];
    int nansw=split_text(labt, text, answ);
    addstringtolist(text,plist);
    int right=0;

    if (make_answers)
    {
        shuffle_answers(nansw, answ, right);
        for(int i=0; i<nansw; ++i)
        {
            char buf[BUFSZ];
            sprintf(buf, "String(\"Вариант %c):\")\n", i+'a');
            strcat(buf, answ[i]);
            strcpy(answ[i],buf);
            addstringtolist(answ[i],plist);
        }
        if (t!=NULL)
        {
            t->pr_tst = 1;
            t->ch_ask = nansw;
            t->right_ask = right;
            t->msg = "Тест успешно сгенерирован";
        }
    }

    sprintf(str, "String(@Часть преподавателя )"); plist->Add(strdup(str));
    sprintf(str, "String(\"Тема - %s\")", selecttask->name); plist->Add(strdup(str));
    sprintf(str, "String(\"ВАРИАНТ %i, решение задачи %i, ключ %i\")", nvar, nzad, keygen); plist->Add(strdup(str));
    addstringtolist(text, plist);
    addstringtolist(answ[right], plist);
    keygen=0;
}

queMFlabs::Print(TList* plist)
{ // функция вывода задания (без ответов)
    TruePrint(plist);
    return 0;
}

queMFlabs::Print(TList* plist, class test &t)
{ // вывод с вариантами ответа?
    TruePrint(plist, true, &t);
    return 0;
}


