
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
        char buf[10000];
        if (!fgets(buf, 10000, f)) break;
        char *buf1 = new char[10000];
        strcpy(buf1, Trim(AnsiString(buf)).c_str());
        printf("'%s'\n", buf1);
        if (!strcmp(buf1,"")) strcpy(buf1, "String(\" \")");
        list->Add(buf1);
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

    TList *Text = loadText(textfile, new TList);
#ifdef DEBUG
    for(int i=0; i<Text->Count; ++i)
        printf("\"%s\"\n", (char *)Text->Items[i]);
#endif

/** Configuring... */
    TFont *font = new TFont;
    font->PixelsPerInch = 750;
    font->Name = "Arial";
    font->Size = 8;
    font->Style = TFontStyles();
    font->Charset = RUSSIAN_CHARSET;
    FILE *fconf;
#ifdef DEBUG
    if (fconf=fopen("e:\\source\\mentor\\mentorsrc\\utility\\custom.cfg", "rt"))
#else
    if (fconf=fopen("custom.cfg", "rt"))
#endif
    {
        char face[10000];
        char style[1000];
        int size;
        fscanf(fconf, "%d\n%d\n", &left, &top);
        fgets(face, 10000, fconf);
        face[strlen(face)-1]=0; // remove \n
        fscanf(fconf, "%d\n%s\n", &size, style);
        fclose(fconf);
        //font->Name = (AnsiString)face;
        //font->Size = size;
        //font->Style = TFontStyles();
        if (strchr(style, 'b')) font->Style = font->Style << fsBold;
        if (strchr(style, 'i')) font->Style = font->Style << fsItalic;
        if (strchr(style, 'u')) font->Style = font->Style << fsUnderline;
    }

    bool done;
    int w=700, h=Text->Count*100;
    Bitmap->Width = w;
    Bitmap->Height = h;
    y=top;
    for(i=0; i<Text->Count; i++)
    {
        strcpy(Str, (char*)Text->Items[i]);
        Expr = BuildExpr(Str);
        Expr->Canvas = Bitmap->Canvas;
        Expr->Font = font;
        if (abs(Expr->Width)<10000 && abs(Expr->Height)<10000)
        {
            if (y+Expr->Height+20>h)
                Bitmap->Height = (h=Bitmap->Height + Expr->Height+100);
            if (left+Expr->Width>w)
                Bitmap->Width = (w=Bitmap->Width + Expr->Width + 10);
            Expr->Draw(left, y, w, h);
            y = y + Expr->Height+2;
            if (x<Expr->Width)
                x = Expr->Width+5;
        }
        else
        {
            printf("ERROR in '%s' (%d)!\n", Str, i);
            printf("");
        }
        delete Expr;
        printf("%d\n", i);
    }
    printf("w=%d h=%d\n", w,h);
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
    AnsiString textfile("e:\\mentor\\utility\\text.txt");
    AnsiString  bmpfile("e:\\mentor\\utility\\text.bmp");
#endif
    convert(textfile, bmpfile);
    return 0;
}

