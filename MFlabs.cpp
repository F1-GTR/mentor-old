#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "queMFlabs.h"
#include "MMFlabs.h"
#include "qvarnt.h"
#include "m_MFlabs.h"
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
queDeriv::Edit()
{
    sscanf(strpar2, "%d%d%d", &derivid, &rmin, &rmax);
    // инициализация ключа и номера варианта
    keygen=0; nvar=1;
    // установка параметров в окне и показ окна
    FMFlabs->quest=this;
    FMFlabs->etype->Text = IntToStr(labid);
    FMFlabs->rmin->Text = IntToStr(rmin); FMFlabs->rmax->Text = IntToStr(rmax);
    FMFlabs->ShowModal();
    return 0;
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

    if (!qvar->MZad||(qvar->MZad&&nvar==1))
    {
        if (
        sprintf(str, "String(\"Найти дифференциальное уравнение:\")");
        plist->Add(strdup(str));
    }

    bool done;
    range r(rmin, rmax);
    char text[1000], answ[10][1000];
    switch(derivid)
    {
        case  1: mflab01(r, text, answ); break;
        case  2: mflab01(r, text, answ); break;
        default: ShowMessage("Error\nUnknown MFlab ID"); break;
    }
    plist->Add(strdup(text));

    if (make_answers)
    {
        bool used[5]={false,false,false,false,false};
        int right=-1;
        for(i=0; i<5; ++i)
        {
            while (!used[idx[i]=rand()%5]);
            used[idx[i]]=true;
            if (idx[i]==0) right=i;
            sprintf(str, "String(\"Вариант %c):\")", 'a'+i); plist->Add(strdup(str));
            sprintf(str, "%s", answ[idx[i]]); plist->Add(strdup(str));
        }
        if (t!=NULL)
        {
            t->pr_tst = 1;
            t->ch_ask = 5;
            t->right_ask = right;
            t->msg = "Тест успешно сгенерирован";
        }
    }

    sprintf(str, "String(@Часть преподавателя )"); plist->Add(strdup(str));
    sprintf(str, "String(\"Тема - %s \")", selecttask->name); plist->Add(strdup(str));
    sprintf(str, "String(ВАРИАНТ %i, решение задачи %i, ключ %i)", nvar, nzad, keygen); plist->Add(strdup(str));
    sprintf(str, "%s", text); plist->Add(strdup(str));
    sprintf(str, "%s", answ[0]); plist->Add(strdup(str));
    keygen=0;
}

queDeriv::Print(TList* plist)
{ // функция вывода задания (без ответов)
    TruePrint(plist);
    return 0;
}

queDeriv::Print(TList* plist, class test &t)
{ // вывод с вариантами ответа?
    TruePrint(plist, true, &t);
    return 0;
}


 