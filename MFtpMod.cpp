//---------------------------------------------------------------------------
#include <vcl.h>
#include "MFtpMod.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFtpMod *FtpMod;
//---------------------------------------------------------------------------
__fastcall TFtpMod::TFtpMod(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFtpMod::Button1Click(TObject *Sender)
{
        int i;

        NMFTP1->Vendor = NMOS_AUTO;
        NMFTP1->Host = "hosting.vstu.ru";
        NMFTP1->UserID = "frund";
        NMFTP1->Password = "frund15";
        NMFTP1->Connect();

        if ( NMFTP1->Connected == false )
                FtpMod->Close();

        NMFTP1->ParseList = true;
        NMFTP1->List();

        ListBox2->Clear();
        ListBox2->Items->Add("..");
        ListBox2->Items->AddStrings( NMFTP1->FTPDirectoryList->name );
        Label2->Caption = "\\";

//        NMFTP1->FTPDirectoryList->ParseLine;
}
//---------------------------------------------------------------------------
void __fastcall TFtpMod::ListBox2DblClick(TObject *Sender)
{
        int i;

        NMFTP1->ChangeDir( ListBox2->Items->Strings[ ListBox2->ItemIndex ] );

        if ( ListBox2->Items->Strings[ ListBox2->ItemIndex ].AnsiCompare("..") )
                Label2->Caption = Label2->Caption + "\\" + ListBox2->Items->Strings[ ListBox2->ItemIndex ];
        else
        {
                i = Label2->Caption.LastDelimiter( "\\" );
                Label2->Caption = Label2->Caption.SubString( 1, i );
        }

        NMFTP1->ParseList = true;
        NMFTP1->List();

        ListBox2->Clear();
        ListBox2->Items->Add("..");
        ListBox2->Items->AddStrings( NMFTP1->FTPDirectoryList->name );
}
//---------------------------------------------------------------------------
void __fastcall TFtpMod::Button2Click(TObject *Sender)
{
        NMFTP1->Disconnect();
        ListBox2->Clear();
        Label2->Caption = "";        
}
//---------------------------------------------------------------------------
