//---------------------------------------------------------------------------

#include <vcl.h>
#include "MLog.h"
#pragma hdrstop

#include "MScanDialog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMScan *MScan;
//---------------------------------------------------------------------------
__fastcall TMScan::TMScan(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMScan::FolderClick(TObject *Sender)
{
    AnsiString Path;
    if (SelectDirectory("Выберите каталог", "",Path))   //Path - папка
    {
        Path = Path + "\\";
        Edit1->Text = Path;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMScan::Button2Click(TObject *Sender)
{
        ShellExecute(Handle,"open", ("file://"+ExtractFilePath(Application->ExeName)+"utility\\mtrscan\\mtrlist.html").c_str(),NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------
void __fastcall TMScan::FormActivate(TObject *Sender)
{
        Edit1->Text = GetCurrentDir()+"\\";        
}
//---------------------------------------------------------------------------
void __fastcall TMScan::Button1Click(TObject *Sender)
{
        ShellExecute(0,"open",(ExtractFilePath(Application->ExeName)+"utility\\mtrscan\\MtrScanner.exe").c_str(),("-p \""+Edit1->Text+"\\\"").c_str(),0,SW_SHOW);
}
//---------------------------------------------------------------------------
