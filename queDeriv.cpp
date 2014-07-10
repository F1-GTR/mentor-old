#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#include "queDeriv.h"
#include "MDeriv.h"
#include "qvarnt.h"
#include "mc_deriv.h"
#include "m_deriv_01.h"
#include "m_deriv_02.h"
#pragma hdrstop
#pragma package(smart_init)


queDeriv::queDeriv (FILE* f)
{
    // генерация ключа
    keygen=random(1000)+1;
    // чтение параметров
    char buf[256];
    reads(f, buf); strpar1 = strdup(buf);
    reads(f, buf); strpar2 = strdup(buf);
    // разбор параметров
    sscanf(strpar1, "%d %i %i\n", &derivid, &rmin, &rmax);
    debug=false;
    // инициализация типа вопроса
    qtype = type;
}

queDeriv::Save(FILE* f)
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
    FDeriv->quest=this;
    FDeriv->etype->Text = IntToStr(derivid);
    FDeriv->rmin->Text = IntToStr(rmin); FDeriv->rmax->Text = IntToStr(rmax);
    FDeriv->ShowModal();
    return 0;
}

void addstringtolist (char *str1, TList *plist)
{
    char str[BUFSZ]; strcpy(str, str1);
    char lines[40][BUFSZ];
    int n=split_str(str, lines);
    for(int i=0; i<n; ++i)
        plist->Add(strdup(lines[i]));
}

void queDeriv::TruePrint (TList* plist, bool make_answers=false, class test* t=NULL)
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
    char task[BUFSZ], answers[5][BUFSZ], src[BUFSZ];

    switch(derivid)
    {
        case  1: deriv101(r, task, answers, src); break;
        case  2: deriv102(r, task, answers, src); break;
        case  3: deriv103(r, task, answers, src); break;
        case  4: deriv104(r, task, answers, src); break;
        case  5: deriv105(r, task, answers, src); break;
        case  6: deriv106(r, task, answers, src); break;
        case  7: deriv107(r, task, answers, src); break;
        case  8: deriv108(r, task, answers, src); break;
        case  9: deriv201(r, task, answers, src); break;
        case 10: deriv202(r, task, answers, src); break;
        case 11: deriv203(r, task, answers, src); break;
        case 12: deriv204(r, task, answers, src); break;
        case 13: deriv205(r, task, answers, src); break;
        case 14: deriv206(r, task, answers, src); break;
        case 15: deriv207(r, task, answers, src); break;
        case 16: deriv208(r, task, answers, src); break;
        case 17: deriv301(r, task, answers, src); break;
        case 18: deriv302(r, task, answers, src); break;
        case 19: deriv303(r, task, answers, src); break;
        case 20: deriv304(r, task, answers, src); break;
        case 21: deriv305(r, task, answers, src); break;
        case 22: deriv306(r, task, answers, src); break;
        case 23: deriv307(r, task, answers, src); break;
        case 24: deriv308(r, task, answers, src); break;
        case 25: deriv401(r, task, answers, src); break;
        case 26: deriv402(r, task, answers, src); break;
        case 27: deriv403(r, task, answers, src); break;
        case 28: deriv404(r, task, answers, src); break;
        case 29: deriv405(r, task, answers, src); break;
        case 30: deriv406(r, task, answers, src); break;
        case 31: deriv407(r, task, answers, src); break;
        case 32: deriv408(r, task, answers, src); break;
        case 33: deriv501(r, task, answers, src); break;
        case 34: deriv502(r, task, answers, src); break;
        case 35: deriv503(r, task, answers, src); break;
        case 36: deriv504(r, task, answers, src); break;
        case 37: deriv505(r, task, answers, src); break;
        case 38: deriv506(r, task, answers, src); break;
        case 39: deriv507(r, task, answers, src); break;
        case 40: deriv508(r, task, answers, src); break;
        case 41: deriv50101v(r, task, answers, src); break;
        case 42: deriv50102v(r, task, answers, src); break;
        case 43: deriv50103v(r, task, answers, src); break;
        case 44: deriv50104v(r, task, answers, src); break;
        case 45: deriv50105v(r, task, answers, src); break;
        //case 46: deriv50201v(r, task, answers, src); break;
        //new
        case 46: deriv050201v(r, task, answers, src); break;
        case 47: deriv050202v(r, task, answers, src); break;
        //case 49: deriv050301v(r,deriv); break;
//char *deriv050302v (const range& r, char *deriv);
//char *deriv050303v (const range& r, char *deriv);
// sometimes falls
        case 48: deriv050401v(r, task, answers, src); break;
        case 49: deriv050501v(r, task, answers, src); break;
        case 50: deriv050601v(r, task, answers, src); break;

        case 51: deriv71(r, task, answers, src); break;
        case 52: deriv72(r, task, answers, src); break;
        case 53: deriv73(r, task, answers, src); break;
        case 54: deriv74(r, task, answers, src); break;
        case 55: deriv75(r, task, answers, src); break;
        case 56: deriv76(r, task, answers, src); break;
        case 57: deriv77(r, task, answers, src); break;
        case 58: deriv78(r, task, answers, src); break;
        case 59: deriv79(r, task, answers, src); break;
        case 60: deriv710(r, task, answers, src); break;
        case 61: deriv711(r, task, answers, src); break;
        case 62: deriv712(r, task, answers, src); break;
        case 63: deriv713(r, task, answers, src); break;
        case 64: deriv714(r, task, answers, src); break;
        case 65: deriv715(r, task, answers, src); break;
        case 66: deriv716(r, task, answers, src); break;

        case 67: derivb119(r, task, answers, src); break;
        case 68: derivb120(r, task, answers, src); break;
        case 69: derivb121(r, task, answers, src); break;
        case 70: derivb122(r, task, answers, src); break;
        case 71: derivb123(r, task, answers, src); break;
        case 72: derivb124(r, task, answers, src); break;
        case 73: derivb125(r, task, answers, src); break;
        case 74: derivb126(r, task, answers, src); break;
        case 75: derivb127(r, task, answers, src); break;
        case 76: derivb128(r, task, answers, src); break;
        case 77: derivb129(r, task, answers, src); break;

        case 78: derivb219(r, task, answers, src); break;
        case 79: derivb220(r, task, answers, src); break;
        case 80: derivb221(r, task, answers, src); break;
        case 81: derivb222(r, task, answers, src); break;
        case 82: derivb223(r, task, answers, src); break;
        case 83: derivb224(r, task, answers, src); break;
        case 84: derivb225(r, task, answers, src); break;
        case 85: derivb226(r, task, answers, src); break;
        case 86: derivb227(r, task, answers, src); break;
        case 87: derivb228(r, task, answers, src); break;
        case 88: derivb229(r, task, answers, src); break;

        case 89: derivb301(r, task, answers, src); break;
        case 90: derivb302(r, task, answers, src); break;
        case 91: derivb303(r, task, answers, src); break;
        case 92: derivb304(r, task, answers, src); break;
        case 93: derivb305(r, task, answers, src); break;
        case 94: derivb306(r, task, answers, src); break;
        case 95: derivb307(r, task, answers, src); break;
        case 96: derivb308(r, task, answers, src); break;
        case 97: derivb309(r, task, answers, src); break;
        case 98: derivb310(r, task, answers, src); break;
        case 99: derivb311(r, task, answers, src); break;

        case 100: derivb401(r, task, answers, src); break;
        case 101: derivb402(r, task, answers, src); break;
        case 102: derivb403(r, task, answers, src); break;
        case 103: derivb404(r, task, answers, src); break;
        case 104: derivb405(r, task, answers, src); break;
        case 105: derivb406(r, task, answers, src); break;
        case 106: derivb407(r, task, answers, src); break;
        case 107: derivb408(r, task, answers, src); break;
        case 108: derivb409(r, task, answers, src); break;
        case 109: derivb410(r, task, answers, src); break;
        case 110: derivb411(r, task, answers, src); break;

        // 501-509
        case 111: derivb501(r, task, answers, src); break;
        case 112: derivb502(r, task, answers, src); break;
        case 113: derivb503(r, task, answers, src); break;
        case 114: derivb504(r, task, answers, src); break;
        case 115: derivb505(r, task, answers, src); break;
        case 116: derivb506(r, task, answers, src); break;
        case 117: derivb507(r, task, answers, src); break;
        case 118: derivb508(r, task, answers, src); break;
        case 119: derivb509(r, task, answers, src); break;

        // 601-612
        case 120: derivb601(r, task, answers, src); break;
        case 121: derivb602(r, task, answers, src); break;
        case 122: derivb603(r, task, answers, src); break;
        case 123: derivb604(r, task, answers, src); break;
        case 124: derivb605(r, task, answers, src); break;
        case 125: derivb606(r, task, answers, src); break;
        case 126: derivb607(r, task, answers, src); break;
        case 127: derivb608(r, task, answers, src); break;
        case 128: derivb609(r, task, answers, src); break;
        case 129: derivb610(r, task, answers, src); break;
        case 130: derivb611(r, task, answers, src); break;
        case 131: derivb612(r, task, answers, src); break;

        // 701-712
        case 132: derivb701(r, task, answers, src); break;
        case 133: derivb702(r, task, answers, src); break;
        case 134: derivb703(r, task, answers, src); break;
        case 135: derivb704(r, task, answers, src); break;
        case 136: derivb705(r, task, answers, src); break;
        case 137: derivb706(r, task, answers, src); break;
        case 138: derivb707(r, task, answers, src); break;
        case 139: derivb708(r, task, answers, src); break;
        case 140: derivb709(r, task, answers, src); break;
        case 141: derivb710(r, task, answers, src); break;
        case 142: derivb711(r, task, answers, src); break;
        case 143: derivb712(r, task, answers, src); break;

        // new derivs
        case 144: deriv2b701(r, task, answers, src); break;
        case 145: deriv2b702(r, task, answers, src); break;
        case 146: deriv2b703(r, task, answers, src); break;
        case 147: deriv2b704(r, task, answers, src); break;
        case 148: deriv2b705(r, task, answers, src); break;
        case 149: deriv2b706(r, task, answers, src); break;
        case 150: deriv2b707(r, task, answers, src); break;
        case 151: deriv2b708(r, task, answers, src); break;
        case 152: deriv2b709(r, task, answers, src); break;
        case 153: deriv2b710(r, task, answers, src); break;
        case 154: deriv2b711(r, task, answers, src); break;

        case 155: deriv2b801(r, task, answers, src); break;
        case 156: deriv2b802(r, task, answers, src); break;
        case 157: deriv2b803(r, task, answers, src); break;
        case 158: deriv2b804(r, task, answers, src); break;
        case 159: deriv2b805(r, task, answers, src); break;
        case 160: deriv2b806(r, task, answers, src); break;
        case 161: deriv2b807(r, task, answers, src); break;
        case 162: deriv2b808(r, task, answers, src); break;
        case 163: deriv2b809(r, task, answers, src); break;
        case 164: deriv2b810(r, task, answers, src); break;
        case 165: deriv2b811(r, task, answers, src); break;
        case 166: deriv2b812(r, task, answers, src); break;

        case 167: deriv2b901(r, task, answers, src); break;
        case 168: deriv2b902(r, task, answers, src); break;
        case 169: deriv2b903(r, task, answers, src); break;
        case 170: deriv2b904(r, task, answers, src); break;
        case 171: deriv2b905(r, task, answers, src); break;
        case 172: deriv2b906(r, task, answers, src); break;
        case 173: deriv2b907(r, task, answers, src); break;
        case 174: deriv2b908(r, task, answers, src); break;
        case 175: deriv2b909(r, task, answers, src); break;
        case 176: deriv2b910(r, task, answers, src); break;
        case 177: deriv2b911(r, task, answers, src); break;
        case 178: deriv2b912(r, task, answers, src); break;

        case 179: deriv2b1001(r, task, answers, src); break;
        case 180: deriv2b1002(r, task, answers, src); break;
        case 181: deriv2b1003(r, task, answers, src); break;
        case 182: deriv2b1004(r, task, answers, src); break;
        case 183: deriv2b1005(r, task, answers, src); break;
        case 184: deriv2b1006(r, task, answers, src); break;
        case 185: deriv2b1007(r, task, answers, src); break;
        case 186: deriv2b1008(r, task, answers, src); break;
        case 187: deriv2b1009(r, task, answers, src); break;
        case 188: deriv2b1010(r, task, answers, src); break;
        case 189: deriv2b1011(r, task, answers, src); break;
        case 190: deriv2b1012(r, task, answers, src); break;

        case 191: deriv2b1101(r, task, answers, src); break;
        case 192: deriv2b1102(r, task, answers, src); break;
        case 193: deriv2b1103(r, task, answers, src); break;
        case 194: deriv2b1104(r, task, answers, src); break;
        case 195: deriv2b1105(r, task, answers, src); break;
        case 196: deriv2b1106(r, task, answers, src); break;
        case 197: deriv2b1107(r, task, answers, src); break;
        case 198: deriv2b1108(r, task, answers, src); break;
        case 199: deriv2b1109(r, task, answers, src); break;
        case 200: deriv2b1110(r, task, answers, src); break;
        case 201: deriv2b1111(r, task, answers, src); break;
        case 202: deriv2b1112(r, task, answers, src); break;

        case 203: deriv2b1201(r, task, answers, src); break;
        case 204: deriv2b1202(r, task, answers, src); break;
        case 205: deriv2b1203(r, task, answers, src); break;
        case 206: deriv2b1204(r, task, answers, src); break;
        case 207: deriv2b1205(r, task, answers, src); break;
        case 208: deriv2b1206(r, task, answers, src); break;
        case 209: deriv2b1207(r, task, answers, src); break;
        case 210: deriv2b1208(r, task, answers, src); break;
        case 211: deriv2b1209(r, task, answers, src); break;
        case 212: deriv2b1210(r, task, answers, src); break;
        case 213: deriv2b1211(r, task, answers, src); break;
        case 214: deriv2b1212(r, task, answers, src); break;

        case 215: deriv601(r, task, answers, src); break;
        case 216: deriv602(r, task, answers, src); break;
        case 217: deriv603(r, task, answers, src); break;
        case 218: deriv604(r, task, answers, src); break;

        case 219: deriv701a(r, task, answers, src); break;
        case 220: deriv702a(r, task, answers, src); break;
        case 221: deriv703a(r, task, answers, src); break;
        case 222: deriv704a(r, task, answers, src); break;
        case 223: deriv705a(r, task, answers, src); break;
        case 224: deriv706a(r, task, answers, src); break;
        case 225: deriv707a(r, task, answers, src); break;
        case 226: deriv708a(r, task, answers, src); break;

        case 227: deriv401(r, task, answers, src); break;
        case 228: deriv402(r, task, answers, src); break;
        case 229: deriv403(r, task, answers, src); break;
        case 230: deriv404(r, task, answers, src); break;
        case 231: deriv405(r, task, answers, src); break;
        case 232: deriv406(r, task, answers, src); break;
        case 233: deriv407(r, task, answers, src); break;
        case 234: deriv408(r, task, answers, src); break;
        case 235: deriv409a(r, task, answers, src); break;
        case 236: deriv410a(r, task, answers, src); break;
        case 237: deriv411a(r, task, answers, src); break;
        case 238: deriv412a(r, task, answers, src); break;
        case 239: deriv413a(r, task, answers, src); break;
        case 240: deriv414a(r, task, answers, src); break;
        case 241: deriv415a(r, task, answers, src); break;

        default: ShowMessage("Error\nUnknown derivative ID"); break;
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
            t->right_ask = right+1;
            t->msg = "Тест успешно сгенерирован";
        }
    }


    char buf[1000];
    FILE *f = fopen(chprintf(buf, "c:\\47\\%d.txt", derivid), "wt");
    if (f) fprintf(f, "String(\"%d.  \")&%s", derivid, src), fclose(f);

    sprintf(str, "String(@Часть преподавателя )"); plist->Add(strdup(str));
    sprintf(str, "String(\"Тема - %s\")", selecttask->name); plist->Add(strdup(str));
    sprintf(str, "String(\"ВАРИАНТ %i, решение задачи %i, ключ %i\")", nvar, nzad, keygen); plist->Add(strdup(str));
    addstringtolist(task, plist);
    addstringtolist(src, plist);
    addstringtolist(answers[right], plist);
    addstringtolist("String( )", plist);
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

 