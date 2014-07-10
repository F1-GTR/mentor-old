//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "MTRconvene.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFMTRconv *FMTRconv;
int shiftIndex;

//---------------------------------------------------------------------------
__fastcall TFMTRconv::TFMTRconv(TComponent* Owner)
    : TForm(Owner)
{
    shiftIndex=-1;
}
//---------------------------------------------------------------------------
void __fastcall TFMTRconv::BitBtn2Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TFMTRconv::DriveComboBox1Change(TObject *Sender)
{
    DirectoryListBox1->Directory = AnsiString(DriveComboBox1->Drive)+":\\";
}
//---------------------------------------------------------------------------
void __fastcall TFMTRconv::DirectoryListBox1Change(TObject *Sender)
{
    FileListBox1->Directory=DirectoryListBox1->Directory;
}
//---------------------------------------------------------------------------

void splitfilename (AnsiString filename, AnsiString& file, AnsiString& path)
{
    for(int i=filename.Length(); i>=1; --i)
        if (filename[i]=='\\')
        {
            file = filename.SubString(i+1,filename.Length()-i);
            path=filename.SubString(1,i-1);
            return;
        }
    path = "";
    file = filename;
}

void TFMTRconv::addfile (AnsiString filename)
{
    AnsiString file,path;
    splitfilename(filename, file, path);
    int q=files->Items->Count;
    for(int i=0; i<q; ++i)
        if (files->Items->Item[i]->Caption==file && files->Items->Item[i]->SubItems->Strings[0]==path)
            return;
    TListItem *item = files->Items->Add();
    item->Caption = file;
    item->SubItems->Add(path);
}

void __fastcall TFMTRconv::FileListBox1DblClick(TObject *Sender)
{
    addfile(FileListBox1->FileName);
}

//---------------------------------------------------------------------------
void mergeFiles (const AnsiString filelist[], const int nfiles, const AnsiString outFile)
{
    int i, row=0, num=0;
    char a[10000];
    int col=0, cols=0, column=0;

    FILE *fmain = fopen(outFile.c_str(),"wt");
    for(i=0; i<nfiles; ++i)
    {
        FILE *f = fopen(filelist[i].c_str(),"rt");
        col=0;
        do{
            fgets(a,1000,f);
            if (!strncmp(a,"head 3",6))
            {
                col++;
                fputs(a,fmain);
                fgets(a,1000,f); fputs(a,fmain);
            }
            else if (!strncmp(a,"head 4",6))
            {
                fputs(a,fmain);
                fgets(a,1000,f); fputs(a,fmain);
            }
            else if (!strncmp(a,"head 2",6))
            {
                fputs(a,fmain);
                fgets(a,1000,f); fputs(a,fmain);
                fscanf(f,"%d %d %d\n", &column, &row, &num);
                fprintf(fmain,"%d %d %d\n", column+cols, row, num);
                fgets(a,1000,f); fputs(a,fmain);
                fgets(a,1000,f); fputs(a,fmain);
            }
            else break;
        }while(!feof(f));
        fclose(f);
        cols+=col;
    }
    fclose(fmain);
    MessageBox(NULL,"Выполнено","Mentor",MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TFMTRconv::BitBtn1Click(TObject *Sender)
{
    if (files->Items->Count<2)
    {
        MessageBox(NULL, "Необходимо задать по крайней мере 2 файла для объединения.", "Mentor", MB_ICONERROR);
        return;
    }
    /** ------ */
    savedlg->Filter="MTR-файлы (*.mtr)|*.mtr";
    if (savedlg->Execute())
    {
        AnsiString filelist[100];
        for(int i=0; i<files->Items->Count; ++i)
        {
            filelist[i]=files->Items->Item[i]->SubItems->Strings[0]+"\\"+
                files->Items->Item[i]->Caption;
        }
        mergeFiles(filelist, files->Items->Count, savedlg->FileName);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFMTRconv::Panel8ConstrainedResize(TObject *Sender,
      int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight)
{
    Panel8->Refresh();
    DriveComboBox1->Width=Panel8->Width;
}
//---------------------------------------------------------------------------
int getFirstSelected (TListView *lst)
{
    for(int i=0; i<lst->Items->Count; ++i)
        if (lst->Items->Item[i]->Selected)
            return i;
    return -1;
}

int getLastSelected (TListView *lst)
{
    for(int i=lst->Items->Count-1; i>=0; --i)
        if (lst->Items->Item[i]->Selected)
            return i;
    return -1;
}
void __fastcall TFMTRconv::filesMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    int fs, ls, i, d;
    if (shiftIndex==-1) return;
    if (Shift.Contains(ssLeft))
    {
        if (files->GetItemAt(X,Y)==NULL) fs = files->Items->Count;
        else fs=files->GetItemAt(X, Y)->Index;
        ls = getLastSelected(files);
        if (fs!=shiftIndex)
            if (fs<shiftIndex)
            {
                if (getFirstSelected(files)>0)
                    for(int i=0; i<=ls; ++i)
                        if (files->Items->Item[i]->Selected)
                        {
                            AnsiString s;
                            TListItem *i1=files->Items->Item[i];
                            TListItem *i2=files->Items->Item[i-1];
                            bool sel;
                            s=i1->Caption; i1->Caption=i2->Caption; i2->Caption=s;
                            s=i1->SubItems->Strings[0]; i1->SubItems->Strings[0]=i2->SubItems->Strings[0]; i2->SubItems->Strings[0]=s;
                            sel=i1->Selected; i1->Selected=i2->Selected; i2->Selected=sel;
                        }
            }
            else
            {
                if (ls<files->Items->Count-1)
                    for(int i=ls; i>=0; --i)
                        if (files->Items->Item[i]->Selected)
                        {
                            AnsiString s;
                            TListItem *i1=files->Items->Item[i];
                            TListItem *i2=files->Items->Item[i+1];
                            bool sel;
                            s=i1->Caption; i1->Caption=i2->Caption; i2->Caption=s;
                            s=i1->SubItems->Strings[0]; i1->SubItems->Strings[0]=i2->SubItems->Strings[0]; i2->SubItems->Strings[0]=s;
                            sel=i1->Selected; i1->Selected=i2->Selected; i2->Selected=sel;
                        }
            }
            shiftIndex=fs;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFMTRconv::filesMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (files->GetItemAt(X, Y)) shiftIndex=files->GetItemAt(X, Y)->Index;
    else shiftIndex=-1;
}
//---------------------------------------------------------------------------
void __fastcall TFMTRconv::FormShow(TObject *Sender)
{
    DriveComboBox1->Drive=ExtractFilePath(Application->ExeName)[1];
    DriveComboBox1->Refresh();
    DirectoryListBox1->Directory=ExtractFilePath(Application->ExeName);
}
//---------------------------------------------------------------------------

void __fastcall TFMTRconv::filesDblClick(TObject *Sender)
{
    if (files->Selected) files->Items->Delete(files->Selected->Index);
}
//---------------------------------------------------------------------------

