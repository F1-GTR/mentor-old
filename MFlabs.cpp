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
    // ��������� �����
    keygen=random(1000)+1;
    // ������ ����������
    char buf[256];
    reads(f, buf); strpar1 = strdup(buf);
    reads(f, buf); strpar2 = strdup(buf);
    // ������ ����������
    sscanf(strpar1, "%d %i %i\n", &labid, &rmin, &rmax);
    debug=false;
    // ������������� ���� �������
    qtype = type;
}

queMFlabs::Save(FILE* f)
{ // �� ����, ��� ����
    fprintf(f,"head %i\n",type);
    fprintf(f,"%s\n",name);
    fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
    fprintf(f,"%s\n",strpar1);
    fprintf(f,"%s\n",strpar2);
    return 0;
}

// ������� ���� ����������?
queDeriv::Edit()
{
    sscanf(strpar2, "%d%d%d", &derivid, &rmin, &rmax);
    // ������������� ����� � ������ ��������
    keygen=0; nvar=1;
    // ��������� ���������� � ���� � ����� ����
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
        sprintf(str, "String(\"# ���� - %s \")", selecttask->name);
        plist->Add(strdup(str));
    }
    else
    {
        sprintf(str, "String(#)");
        plist->Add(strdup(str));
    }
    sprintf(str, "String(\"�������   %i, ������ %i.\")", nvar, nzad); plist->Add(strdup(str));

    if (!qvar->MZad||(qvar->MZad&&nvar==1))
    {
        if (
        sprintf(str, "String(\"����� ���������������� ���������:\")");
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
            sprintf(str, "String(\"������� %c):\")", 'a'+i); plist->Add(strdup(str));
            sprintf(str, "%s", answ[idx[i]]); plist->Add(strdup(str));
        }
        if (t!=NULL)
        {
            t->pr_tst = 1;
            t->ch_ask = 5;
            t->right_ask = right;
            t->msg = "���� ������� ������������";
        }
    }

    sprintf(str, "String(@����� ������������� )"); plist->Add(strdup(str));
    sprintf(str, "String(\"���� - %s \")", selecttask->name); plist->Add(strdup(str));
    sprintf(str, "String(������� %i, ������� ������ %i, ���� %i)", nvar, nzad, keygen); plist->Add(strdup(str));
    sprintf(str, "%s", text); plist->Add(strdup(str));
    sprintf(str, "%s", answ[0]); plist->Add(strdup(str));
    keygen=0;
}

queDeriv::Print(TList* plist)
{ // ������� ������ ������� (��� �������)
    TruePrint(plist);
    return 0;
}

queDeriv::Print(TList* plist, class test &t)
{ // ����� � ���������� ������?
    TruePrint(plist, true, &t);
    return 0;
}


 