#include <vcl.h>
#include <stdlib.h>
#include <math.h>
//#define QEDBG
#include "queeigens.h"

#ifndef QEDBG
#include "MEigen.h"
#include "qvarnt.h"
#endif

#include "matrgen.h"
#pragma hdrstop
#pragma package(smart_init)

queeigens::queeigens (FILE* f)
{ // ��������� ���������� ����� ����?
    // ��������� �����
    randomize();
    keygen=random(1000)+1;
    // ������ ����������
    char buf[256];
#ifndef QEDBG
    reads(f, buf); strpar1 = strdup(buf);
    reads(f, buf); strpar2 = strdup(buf);
#endif
    // ������ ����������
    sscanf(strpar1, "%d %d", &size, &variouseigens);
    // ������������� ���� �������
    qtype = type;
}

queeigens::Save(FILE* f)
{ // �� ����, ��� ����
    fprintf(f,"head %i\n",type);
    fprintf(f,"%s\n",name);
    fprintf(f,"%i %i %i\n",itemnumber,subitemnumber,qtype);
    fprintf(f,"%s\n",strpar1);
    fprintf(f,"%s\n",strpar2);
    return 0;
}

// ������� ���� ����������?
queeigens::Edit()
{
    //ShowMessage("queeigensedit");
    // �� ����, ��� ����
    sscanf(strpar2, "%i%i", &size, &variouseigens);
    // ������������� ����� � ������ ��������
    keygen=0; nvar=1;
    // ��������� ���������� � ���� � ����� ����
#ifndef QEDBG
    Eigen->quest=this;
    Eigen->Edit1->Text = IntToStr(size);
    Eigen->Edit2->Text = IntToStr(variouseigens);
    Eigen->Edit3->Text = IntToStr(keygen);
    Eigen->Edit4->Text = IntToStr(nvar);
    Eigen->ShowModal();
#endif
    return 0;
}


void queeigens::TruePrint (TList* plist, bool make_answers=false, class test* t=NULL)
{
    if (variouseigens>size || variouseigens==0 || size>4 || (size==4 && variouseigens!=4))
    {
        ShowMessage("Incorrect params!");
        return;
    }

    char str[500], tempstr[500];
    if (keygen==0)
        keygen=random(1000)+1;

    srand(keygen);

#ifndef QEDBG
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
#endif
    sprintf(str, "String(�������   %i, ������ %i.)", nvar, nzad);
    plist->Add(strdup(str));

#ifndef QEDBG
    if (!qvar->MZad||(qvar->MZad&&nvar==1))
    {
         sprintf(str, "String(����� ��� ����������� ����� ������� %d�%d:)", size, size);
        plist->Add(strdup(str));
    }
#endif

    int i,j;
    matrix matr;
    if (!generate(matr, size, variouseigens))
        ShowMessage("can't generate matrix"); //?

    sprintf(str, "!(Matrix(%d,%d,", size, size);
    for(i=0; i<size; ++i)
        for(j=0; j<size; ++j)
        {
            sprintf(tempstr, "%d,", matr.e[i][j]);
            strcat(str, tempstr);
        }
    str[strlen(str)-1]='\0';
    strcpy(tempstr, "))");
    strcat(str, tempstr);
    plist->Add(strdup(str));

    if (make_answers)
    {
        const int answc = 3;
        int err[answc];
        bool newvalue;
        int rightansw = random(answc), n;
        int i,j;

        for(i=0; i<answc; ++i)
            do {
                err[i]=random(8)-4;
                if (err[i]==0)
                    newvalue=false;
                else
                    for(newvalue=true, j=0; j<i; ++j)
                        if (err[j]==err[i]) newvalue=false;
            } while (newvalue==false);

        for(i=0; i<answc; ++i)
        {
            sprintf(str, "String(\"������� %c):\")", 'a'+i);
            plist->Add(strdup(str));

            if (i==rightansw) n=0; else n=err[i];

            sprintf(str, "!(Matrix(%d,1,", size);
            for(j=0; j<size; ++j)
            {
                sprintf(tempstr, "%d,", matr.eigenv[j]+n);
                strcat(str, tempstr);
            }
            str[strlen(str)-1]='\0';
            strcat(str, "))");
            plist->Add(strdup(str));
        }
        if (t!=NULL)
        {
            /*t->pr_tst = 1;
            t->ch_ask = answc;
            t->right_ask = rightansw+1;
            t->msg = "���� ������� ������������";*/
        }
    }

    sprintf(str, "String(@����� ������������� )"); plist->Add(strdup(str));
    sprintf(str, "String(\"���� - %s \")", selecttask->name); plist->Add(strdup(str));
    sprintf(str, "String(������� %i, ������� ������ %i, ���� %i)", nvar, nzad, keygen); plist->Add(strdup(str));

    sprintf(str, "!(Matrix(%d,1,", size);
    for(j=0; j<size; ++j)
    {
        sprintf(tempstr, "%d,", matr.eigenv[j]);
        strcat(str, tempstr);
    }
    keygen=0;
    str[strlen(str)-1]='\0';
    strcat(str, "))");
    plist->Add(strdup(str));
}

queeigens::Print(TList* plist)
{ // ������� ������ ������� (��� �������)
    TruePrint(plist);
    return 0;
}

queeigens::Print(TList* plist, class test &t)
{ // ����� � ���������� ������?
    TruePrint(plist, true, &t);
    return 0;
}

