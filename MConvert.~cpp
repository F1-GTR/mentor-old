//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#include <Printers.hpp>
#include <string.h>
#include "MConvert.h"
#include "qvarnt.h"
#include "ExprDraw.hpp"
#include "ExprMake.hpp"
#include "tkurs.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
extern tkurs* kurs;

#pragma package(smart_init)
//---------------------------------------------------------------------------

//#define OLDTXTTOBMP
#ifndef OLDTXTTOBMP


/** This version of TxtToBmp uses txt2bmp utility located in /utility dir */
void TxtToBmp (TList *List, Graphics::TBitmap *Bitmap, TFont *Font, int left, int top)
{
    AnsiString /** Define locations of some file needed for conversion */
         workdir = ExtractFilePath(Application->ExeName)+"utility\\",
         utility = workdir + "txt2bmp.exe", /** utility itself,      */
        textfile = workdir + "__temp.txt",  /** input file,          */
         picfile = workdir + "__temp.bmp",  /** resulting file,      */
        conffile = workdir + "custom.cfg";  /** config to write font *
                                              * and indent settings. */

    /** Save text to temporary text file */
    FILE *f = fopen(textfile.c_str(), "wt");
    for(int i=0,j; i<List->Count; i++)
    {
        char str[10000];
        strcpy(str, (const char *)List->Items[i]);
        if ((j=strcspn(str,"#"))<strlen(str)) str[j]=' ';
        fprintf(f, "%s\n", str);
    }
    fclose(f);

    /** * * * * * * * * * * * * * * * **** * * * * * * * * * * * * * * **
      *                                                                 *
      * Set custom config. File must have the following text format:    *
      *                                                                 *
      *  - left\n, top\n : integer values, indents                      *
      *  - fontface\n    : string, name of the font to draw image with  *
      *  - fontsize\n    : integer, size of the font                    *
      *  - stylestring   : string, determines font style. it must not   *
      *                    contain any delimiters.                      *
      *     For stylestring, if it contains 'b' character, font will    *
      * be set to bold, 'i' and 'u' is for italic and underline rspct.  *
      *                                                                 *
      * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    FILE *fconfig = fopen(conffile.c_str(), "wt");
    fprintf(fconfig, "%d\n%d\n%s\n%d\n%c%c%c",
        left, top,
        Font->Name.c_str(),
        Font->Size,
        Font->Style.Contains(fsBold)?'b':'x',
        Font->Style.Contains(fsItalic)?'i':'x',
        Font->Style.Contains(fsUnderline)?'u':'x'
    );
    fclose(f);

    /** Call the utility */
    SHELLEXECUTEINFO sei;
    sei.cbSize = sizeof(sei);
    sei.fMask = SEE_MASK_NOCLOSEPROCESS;
    sei.lpVerb = NULL;
    sei.lpFile = utility.c_str();
    sei.lpParameters = (textfile + " " + picfile).c_str();
    sei.lpDirectory = workdir.c_str();
    sei.nShow = SW_HIDE;
    ShellExecuteEx(&sei);
    /** ... wait while it works */
    WaitForSingleObject(sei.hProcess, INFINITE);

    /** Load the result */
    Bitmap->LoadFromFile(picfile);
}


void TxtToBmp (TStrings *List, Graphics::TBitmap *Bitmap, TFont *Font, int left, int top)
{
    TList *newlist = new TList;
    for(int i=0; i<List->Count; ++i)
    {
        char str[10000];
        strcpy(str, List->Strings[i].c_str());
        newlist->Add(strdup(str));
    }
    TxtToBmp(newlist, Bitmap, Font, left, top);
}
#else
void TxtToBmp ( TList * List, Graphics::TBitmap * Bitmap, TFont * Font, int left, int top )
{
    FILE *f = fopen("f:\\1.txt", "wt");
    for(int i=0,j; i<List->Count; i++)
    {
        char str[10000];
        strcpy(str, (const char *)List->Items[i]);
        if ((j=strcspn(str,"#"))<strlen(str)) str[j]=' ';
        fprintf(f, "%s\n", str);
    }
    fclose(f);
    return;
        int i, j, x, y;
        TExprClass *Expr;// = new TExprClass();
        char Str[10000];

        x = left;
        y = top;
        Bitmap->Width = 1500;
        Bitmap->Height = 9000;

        for(i=0; i<List->Count; i++)
        {
                strcpy(Str, (char*)List->Items[i]);

                if ((j=strcspn(Str,"#")) < strlen(Str))
                {
                    Str[j] = ' ';
                    strcpy((char *)List->Items[i], Str);
                }

                if (strcmp(Str, (char*)List->Items[i]))
                    ShowMessage("memory corruption! before");
#ifdef LOG_TXTTOBMP
                FILE *fil = fopen("c:\\mentor.log", "at");
                fprintf(fil, "%s\n", Str);
                fclose(fil);
#endif

                Expr = BuildExpr(Str);
                if (strcmp(Str, (char*)List->Items[i]))
                    ShowMessage("memory corruption! after");

                Expr->Canvas = Bitmap->Canvas;
                Expr->Font = Font;
                //Expr->Font->Size = Font->Size;
                //Expr->Color = Font->Color;
                Expr->Draw( left, y, 1500, 9000 );

                y = y + Expr->Height;
                if (x<Expr->Width)
                    x = Expr->Width;

                delete Expr;
        }
        Bitmap->Width = x + left;
        Bitmap->Height = y;
        Bitmap->SaveToFile("c:\\1.bmp");
}
//------------------------------------------------------------------------------
void TxtToBmp ( TStrings * List, Graphics::TBitmap * Bitmap, TFont * Font, int left, int top )
{
        int i, j, x, y;
        TExprClass * Expr = new TExprClass();
        char Str[10000];

        x = left;
        y = top;

        Bitmap->Width = 1500;
        Bitmap->Height = 9000;

        for ( i = 0; i < List->Count; i ++ )
        {
                strcpy(Str, List->Strings[i].c_str());
                j = strcspn(Str, "#" );

                if( j < strlen( Str ) )
                {
                        Str[j] = ' ';
                        List->Strings[i] = (AnsiString)Str;
                }

                Expr = BuildExpr(Str);

                Expr->Canvas = Bitmap->Canvas;

                Expr->Font = Font;
                Expr->Font->Size = Font->Size;
                Expr->Color = Font->Color;

                Expr->Draw( left, y, 1500, 9000 );

                y = y + Expr->Height;

                if ( x < Expr->Width )
                        x = Expr->Width;

                delete Expr;
        }

        Bitmap->Width = x + left;
        Bitmap->Height = y;
}
#endif

//------------------------------------------------------------------------------

void FilePrint ( AnsiString FileName )
{
        int TempHeight, w, h, str_n = 1;

        Graphics::TBitmap * Bitmap = new Graphics::TBitmap();

        qvar->ImageEnProc1->AttachedBitmap = Bitmap;
        qvar->ImageEnIO1->AttachedBitmap = Bitmap;

        //Bitmap->LoadFromFile( FileName );
        qvar->ImageEnIO1->LoadFromFile( FileName );
        qvar->ImageEnIO1->Params->JPEG_Quality = 100;

        //w = Bitmap->Width * 6;
        w = -1;
        //h = Bitmap->Height * Printer()->PageHeight / 1100;
        h = Bitmap->Height * 6;
        /*ShowMessage( Printer()->PageHeight );
        ShowMessage( h );*/

        //qvar->ImageEnProc1->Resample( w, h, rfBilinear );
        //qvar->ImageEnProc1->Resample( w, h, rfBSpline );
        qvar->ImageEnProc1->Resample( w, h, rfFastLinear );
        //qvar->ImageEnIO1->DoPrintPreviewDialog( iedtDialog, "Просмотр печати", true, "Печать" );

        /*Printer()->BeginDoc();
        qvar->ImageEnIO1->PrintImage( Printer()->Canvas,0,0,0,0,ievpTOP,iehpLEFT,iesNORMAL,0,0,1);
        Printer()->EndDoc();*/

        if ( h <= Printer()->PageHeight )
        {
                Printer()->BeginDoc();
                Printer()->Canvas->Draw( 0, 0, qvar->ImageEnIO1->AttachedBitmap );
                //qvar->ImageEnIO1->PrintImage( Printer()->Canvas,0,0,0,0,ievpTOP,iehpLEFT,iesNORMAL,0,0,1);
                //qvar->ImageEnIO1->PrintImagePos( Printer()->Canvas, 0, 0, w, h, 1 );
                Printer()->EndDoc();
        }
        else
        {
                TempHeight = 0;

                Printer()->BeginDoc();

                while ( h - TempHeight > 0 )
                {
                        Printer()->Canvas->CopyRect( Rect( 0, 0, Printer()->PageWidth, Printer()->PageHeight ), qvar->ImageEnIO1->AttachedBitmap->Canvas, Rect( 0, TempHeight, Printer()->PageWidth, TempHeight + Printer()->PageHeight ) );
                        //qvar->ImageEnIO1->PrintImagePos( Printer()->Canvas, 0, TempHeight, Printer()->PageWidth, TempHeight + Printer()->PageHeight, 1 );
                        //qvar->ImageEnIO1->PrintImagePos( Printer()->Canvas, TempHeight, 0, qvar->ImageEnIO1->AttachedBitmap->Width, TempHeight + Printer()->PageHeight, 1 );

                        Printer()->Canvas->TextOut( Printer()->PageWidth / 2, 10, "Страница №" + IntToStr( Printer()->PageNumber ));
                        //Printer()->Canvas->TextOut( Printer()->PageWidth / 2, 10, "Страница №" + IntToStr( str_n ++ ));

                        TempHeight += Printer()->PageHeight;

                        if ( h - TempHeight > 0 )
                                Printer()->NewPage();
                }

                Printer()->EndDoc();
        }

        delete Bitmap;
        unlink( FileName.c_str() );

        /*int TempHeight;

        Graphics::TBitmap * Bitmap = new Graphics::TBitmap();

        Bitmap->LoadFromFile( FileName );

        if ( Bitmap->Height <= Printer()->PageHeight )
        {
                Printer()->BeginDoc();
                Printer()->Canvas->Draw( 0, 0, Bitmap );
                Printer()->EndDoc();
        }
        else
        {
                TempHeight = 0;

                Printer()->BeginDoc();

                while ( Bitmap->Height - TempHeight > 0 )
                {
                        Printer()->Canvas->CopyRect( Rect( 0, 0, Printer()->PageWidth, Printer()->PageHeight ), Bitmap->Canvas, Rect( 0, TempHeight, Printer()->PageWidth, TempHeight + Printer()->PageHeight ) );
                        Printer()->Canvas->TextOut( Printer()->PageWidth / 2, 10, "Страница №" + IntToStr( Printer()->PageNumber ));

                        TempHeight += Printer()->PageHeight;

                        if ( Bitmap->Height - TempHeight > 0 )
                                Printer()->NewPage();
                }

                Printer()->EndDoc();
        }

        delete Bitmap;*/
}
//------------------------------------------------------------------------------

