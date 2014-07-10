#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "queInteg.h"
#include "MInteg.h"
#include "qvarnt.h"
#include "m_integ.h"
#include "m_integ2.h"
#include "m_integ_a01.h"
#include "m_integ_a02.h"
#pragma hdrstop
#pragma package(smart_init)

queInteg::queInteg (FILE* f)
{
    // генерация ключа
    keygen=random(1000)+1;
    // чтение параметров
    char buf[256];
    reads(f, buf); strpar1 = strdup(buf);
    reads(f, buf); strpar2 = strdup(buf);
    // разбор параметров
    sscanf(strpar1, "%d %i %i\n", &Integid, &rmin, &rmax);
    debug=false;
    // инициализация типа вопроса
    qtype = type;
}

queInteg::Save(FILE* f)
{ // не знаю, для чего
    fprintf(f,"head %i\n",type);
    fprintf(f,"%s\n",name);
    fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
    fprintf(f,"%s\n",strpar1);
    fprintf(f,"%s\n",strpar2);
    return 0;
}

// вызвать окно генератора?
queInteg::Edit()
{
    sscanf(strpar2, "%d%d%d", &Integid, &rmin, &rmax);
    // инициализация ключа и номера варианта
    keygen=0; nvar=1;
    // установка параметров в окне и показ окна
    FInteg->quest=this;
    FInteg->etype->Text = IntToStr(Integid);
    FInteg->rmin->Text = IntToStr(rmin); FInteg->rmax->Text = IntToStr(rmax);
    FInteg->ShowModal();
    return 0;
}

void addstringtolist (char *str, TList *plist)
{
    char lines[40][BUFSZ];
    int n=split_str(str, lines);
    for(int i=0; i<n; ++i)
        plist->Add(strdup(lines[i]));
}

void queInteg::TruePrint (TList* plist, bool make_answers=false, class test* t=NULL)
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
    }

    bool done;
    range r(rmin, rmax);
    char task[BUFSZ], answers[10][BUFSZ], src[BUFSZ];

    switch(Integid)
    {
        case 1: integ101b (r, task, answers, src); break;
        case 2: integ102b (r, task, answers, src); break;
        case 3: integ103b (r, task, answers, src); break;
        case 4: integ104b (r, task, answers, src); break;
        case 5: //integ105b (r, task, answers, src); break;
        case 6: integ106b (r, task, answers, src); break;
        case 7: integ107b (r, task, answers, src); break;
        case 8: integ108b (r, task, answers, src); break;
        case 9: integ109b (r, task, answers, src); break;
        case 10: integ110b (r, task, answers, src); break;
        case 11: integ111b (r, task, answers, src); break;
        case 12: integ112b (r, task, answers, src); break;
        case 13: integ113b (r, task, answers, src); break;
        case 14: integ114b (r, task, answers, src); break;
        case 15: integ115b (r, task, answers, src); break;
        case 16: //integ116b (r, task, answers, src); break;
        case 17: //integ117b (r, task, answers, src); break;
        case 18: integ118b (r, task, answers, src); break;
        case 19: integ119b (r, task, answers, src); break;
        case 20: integ120b (r, task, answers, src); break;
        case 21: integ121b (r, task, answers, src); break;
        case 22: integ122b (r, task, answers, src); break;
        case 23: integ123b (r, task, answers, src); break;
        case 24: integ124b (r, task, answers, src); break;
        case 25: integ125b (r, task, answers, src); break;
        case 26: integ126b (r, task, answers, src); break;
        case 27: integ127b (r, task, answers, src); break;
        case 28: integ128b (r, task, answers, src); break;
        case 29: integ129b (r, task, answers, src); break;
        case 30: integ130b (r, task, answers, src); break;
        case 31: integ131b (r, task, answers, src); break;
        case 32: integ132b (r, task, answers, src); break;
        case 33: integ133b (r, task, answers, src); break;
        case 34: integ134b (r, task, answers, src); break;
        case 35: integ135b (r, task, answers, src); break;
        case 36: integ201b (r, task, answers, src); break;
        case 37: integ202b (r, task, answers, src); break;
        case 38: integ203b (r, task, answers, src); break;
        case 39: integ204b (r, task, answers, src); break;
        case 40: integ205b (r, task, answers, src); break;
        case 41: integ206b (r, task, answers, src); break;
        case 42: integ207b (r, task, answers, src); break;
        case 43: integ208b (r, task, answers, src); break;
        case 44: integ301b (r, task, answers, src); break;
        case 45: integ302b (r, task, answers, src); break;
        case 46: integ303b (r, task, answers, src); break;
        case 47: integ304b (r, task, answers, src); break;
        case 48: integ305b (r, task, answers, src); break;
        case 49: integ306b (r, task, answers, src); break;
        case 50: integ307b (r, task, answers, src); break;
        case 51: integ308b (r, task, answers, src); break;
        case 52: integ309b (r, task, answers, src); break;
        case 53: integ310b (r, task, answers, src); break;
        case 54: integ311b (r, task, answers, src); break;
        case 55: integ312b (r, task, answers, src); break;
        case 56: integ313b (r, task, answers, src); break;
        case 57: integ314b (r, task, answers, src); break;
        case 58: integ315b (r, task, answers, src); break;
        case 59: integ316b (r, task, answers, src); break;
        case 60: integ317b (r, task, answers, src); break;
        case 61: integ318b (r, task, answers, src); break;
        case 62: integ319b (r, task, answers, src); break;
        case 63: integ320b (r, task, answers, src); break;
        case 64: integ321b (r, task, answers, src); break;
        case 65: integ322b (r, task, answers, src); break;

        case 66: integ101a (r, task, answers, src); break;
        case 67: integ102a (r, task, answers, src); break;
        case 68: integ103a (r, task, answers, src); break;
        case 69: integ104a1 (r, task, answers, src); break;
        case 70: integ104a2 (r, task, answers, src); break;
        case 71: integ105a1 (r, task, answers, src); break;
        case 72: integ105a2 (r, task, answers, src); break;
        case 73: integ106a (r, task, answers, src); break;
        case 74: integ107a1 (r, task, answers, src); break;
        case 75: integ107a2 (r, task, answers, src); break;
        case 76: integ108a (r, task, answers, src); break;
        case 77: integ109a (r, task, answers, src); break;
        case 78: integ110a (r, task, answers, src); break;
        case 79: integ111a (r, task, answers, src); break;

        case 80: integ201a (r, task, answers, src); break;
        case 81: integ202a (r, task, answers, src); break;
        case 82: integ203a (r, task, answers, src); break;
        case 83: integ204a (r, task, answers, src); break;
        case 84: integ205a (r, task, answers, src); break;
        case 85: integ206a (r, task, answers, src); break;
        case 86: integ207a (r, task, answers, src); break;
        case 87: integ208a (r, task, answers, src); break;
        case 88: integ209a (r, task, answers, src); break;
        case 89: integ210a (r, task, answers, src); break;
        case 90: integ211a (r, task, answers, src); break;
        case 91: integ212a (r, task, answers, src); break;
        case 92: integ213a (r, task, answers, src); break;
        case 93: integ214a (r, task, answers, src); break;
        case 94: integ215a (r, task, answers, src); break;
        case 95: integ216a (r, task, answers, src); break;
        case 96: integ217a (r, task, answers, src); break;
        case 97: integ218a (r, task, answers, src); break;

        default:
            ShowMessage("Error\nUnknown Integral ID");
            break;
    }

    addstringtolist(task,plist);
    addstringtolist("String( )", plist);
    int right = 0;
    const int nansw = 4;

    if (make_answers)
    {
        shuffle_answers(nansw, answers, right);
        for(int i=0; i<nansw; ++i)
        {
            char buf[BUFSZ];
            sprintf(buf, "String(\"Вариант %c):\")\n", i+'a');
            strcat(buf, answers[i]);
            strcpy(answers[i],buf);
            addstringtolist(answers[i],plist);
            addstringtolist("String( )", plist);
        }
        if (t!=NULL)
        {
            t->pr_tst = 1;
            t->ch_ask = nansw;
            t->right_ask = right;
            t->msg = "Тест успешно сгенерирован";
        }
    }


    char buf[1000];
    FILE *f = fopen(chprintf(buf, "c:\\49\\%d.txt", Integid), "wt");
    if (f) fprintf(f, "String(\"%d.  \")&%s", Integid, src), fclose(f);

    sprintf(str, "String(@Часть преподавателя )"); plist->Add(strdup(str));
    sprintf(str, "String(\"Тема - %s\")", selecttask->name); plist->Add(strdup(str));
    sprintf(str, "String(\"ВАРИАНТ %i, решение задачи %i, ключ %i\")", nvar, nzad, keygen); plist->Add(strdup(str));
    addstringtolist(task, plist);
    addstringtolist(src, plist);
    addstringtolist(answers[right], plist);
    addstringtolist("String( )", plist);
    keygen=0;
}

queInteg::Print(TList* plist)
{ // функция вывода задания (без ответов)
    TruePrint(plist);
    return 0;
}

queInteg::Print(TList* plist, class test &t)
{ // вывод с вариантами ответа?
    TruePrint(plist, true, &t);
    return 0;
}


