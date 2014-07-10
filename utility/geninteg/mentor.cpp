//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mentor.h"
#include <stdio.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    FILE *f = fopen("f:\\mentor\\_TABLE_DERIV.mtr", "wt");

    char title[10][100] = { "1", "Подведение под зн. дифф.", "По частям", "Дробно-рациональные выражения" };
    int range[][2] = {
        {  1,    8 },
        {  9,   16 },
        {  67,  77 },
        {  78,  88 },
        {  89,  99 },
        { 100, 110 },
        { 111, 119 },
        { 120, 131 },
        { 132, 143 },
        { 144, 154 },
        { 155, 166 },
        { 179, 190 },
        { 191, 202 },
        { 203, 214 },
        {  17,  24 },
        {  25,  30 },
        { 217, 224 },
        { 225, 239 },
        {  33,  40 },
        { 215, 216 },
        { -1, -1 }
    };

    for(int i=0; range[i][0]!=-1; ++i)
    {
        fprintf(f,"head 3\n%d\n", i+1);//title[i]);
        if (range[i][0]==0)
        {
            int a[] = { 25,26,27,28,29,30,31,32,  225,226,227,228,229,230,231, 0 };
            for(int j=0; a[j]; ++j)
            {
                fprintf(f,"head 4\n%d\n", a[j]);
                fprintf(f,"head 2\nabc\n%d %d %d\n", i+1, j+1, 49);
                fprintf(f,"%d %d %d\n", a[j], -5,5);
                fprintf(f,"%d %d %d\n", a[j], -5,5);
            }
        }
        else
        {
            for(int j=0; j<range[i][1]-range[i][0]+1; ++j)
            {
                fprintf(f,"head 4\n%d\n", j+range[i][0]);
                fprintf(f,"head 2\nabc\n%d %d %d\n", i+1, j+1, 47);
                fprintf(f,"%d %d %d\n", j+range[i][0], -5,5);
                fprintf(f,"%d %d %d\n", j+range[i][0], -5,5);
            }
        }
    }


    fprintf(f,"head 6\njob\n");
    for(int i=0; range[i][0]!=-1; ++i)
    {
        if (range[i][0]==0)
        {
            int a[] = { 25,26,27,28,29,30,31,32,  225,226,227,228,229,230,231,0 };
            for(int j=0; a[j]; ++j)
            {
                fprintf(f,"head 2\nabc\n%d %d %d\n", i+1, j+1, 47);
                fprintf(f,"%d %d %d\n", a[j], -5,5);
                fprintf(f,"%d %d %d\n", a[j], -5,5);
            }
        }
        else
        {
            for(int j=0; j<range[i][1]-range[i][0]+1; ++j)
            {
                fprintf(f,"head 2\nabc\n%d %d %d\n", i+1, j+1, 47);
                fprintf(f,"%d %d %d\n", j+range[i][0], -5,5);
                fprintf(f,"%d %d %d\n", j+range[i][0], -5,5);
            }
        }
    }

    fclose(f);
    exit(EXIT_SUCCESS);
}
//---------------------------------------------------------------------------
