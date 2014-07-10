
/* * * * * * * * * * * * * * * * * * * * *
 *                                       *
 *   Txt2Bmp converter utility           *
 *  - - - - - - - - - - - - - -          *
 *                                       *
 *   used by Mentor v2.0 for Windows     *
 *                                       *
 * * * * * * * * * * * * * * * * * * * * */

#include <vcl.h>
#include <string.h>
#include <stdio.h>
#include "ExprDraw.hpp"
#include "ExprMake.hpp"
#pragma hdrstop
//#define DEBUG
USEUNIT("ExprDraw.pas");
USEUNIT("ExprMake.pas");


TList *loadText (const AnsiString &filename, TList *list)
{
    FILE *f = fopen(filename.c_str(), "rt");
    list->Clear();
    while(1)
    {
        char *buf = new char[10000];
        if (!fgets(buf, 10000, f)) { delete buf; break; }
        strcpy(buf, Trim(AnsiString(buf)).c_str());
        if (!strcmp(buf,"")) strcpy(buf, "String(\" \")");
        list->Add(buf);
    }
    fclose(f);
    return list;
}

/** basically, it converts =)
    it's just a converter, basically */
void convert (AnsiString textfile, AnsiString bmpfile)
{
    int i,j,left=5,top=5,x=left,y=top;
    Graphics::TBitmap *Bitmap = new Graphics::TBitmap;
    TExprClass *Expr;
    char Str[10000];

    Bitmap->Width = 1000;
    Bitmap->Height = 4000;

    TList *Text = loadText(textfile, new TList);
#ifdef DEBUG
    for(int i=0; i<Text->Count; ++i)
        printf("\"%s\"\n", (char *)Text->Items[i]);
#endif

    /*
    Text->Add("String(\"# Тема - JOB \")");
    Text->Add("String(\"Вариант   1, задача 1.\")");
    Text->Add("String(\"Вычислить предел:\")");
    Text->Add("lim(x->4, (-3*x^2+15*x)/(3*x^2+15*x))=...");
    Text->Add("String(@Часть преподавателя )");
    Text->Add("String(\"Тема - JOB \")");
    Text->Add("String(ВАРИАНТ 1, решение задачи 1, ключ 865)");
    Text->Add("lim(x->4, (-3*x^2+15*x)/(3*x^2+15*x))=(1/9)");
    */

    TFont *font = new TFont;
    font->PixelsPerInch = 1000;
    font->Name = "Trebuchet MS";
    font->Size=10;
    for(i=0; i<Text->Count; i++)
    {
        strcpy(Str, (char*)Text->Items[i]);
        Expr = BuildExpr(Str);
        Expr->Canvas = Bitmap->Canvas;
        Expr->Font = font;
        Expr->Draw(left, y, 1000, 4000);
        y = y + Expr->Height;
        if (x<Expr->Width)
            x = Expr->Width;
        delete Expr;
    }
    Bitmap->Width = x+left + 5;
    Bitmap->Height = y + 5;
    Bitmap->SaveToFile(bmpfile);
    delete Bitmap;
    delete font;
}



int main (int argc, char *argv[])
{
#ifndef DEBUG
    if (argc!=3)
        printf("txt2bmp converter\nusage: txt2bmp textfile bmpfile\n"), exit(1);
    AnsiString textfile(argv[1]);
    AnsiString bmpfile(argv[2]);
#else
    AnsiString textfile("1.txt");
    AnsiString bmpfile("1.bmp");
#endif
    convert(textfile, bmpfile);
    return 0;
}

