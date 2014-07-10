#include <vcl.h>
#pragma hdrstop
#include "MInteg.h"
#include "MPreview.h"
#include "MConvert.h"
#include "qvarnt.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TFInteg *FInteg;



__fastcall TFInteg::TFInteg(TComponent* Owner)
    : TForm(Owner)
{
}



void __fastcall TFInteg::Button1Click (TObject *Sender)
{
    if (RadioButton2->Checked == true)
        quest->keygen = StrToInt(Edit3->Text);
    quest->Integid=StrToInt(etype->Text);
    quest->rmin=StrToInt(rmin->Text); quest->rmax=StrToInt(rmax->Text);
    quest->nquest=1;
    quest->nzad=1;
    String p = String(" ");
    String s = etype->Text + p + rmin->Text + p + rmax->Text;
    quest->strpar1=strdup(s.c_str());
    quest->strpar2=strdup(s.c_str());
    TList* plist = new TList();
    quest->Print(plist);
    Memo1->Clear();
    for(int i=0;i<plist->Count;i++)
        Memo1->Lines->Append(String((char*)plist->Items[i]));
}



void __fastcall TFInteg::Button3Click(TObject *Sender)
{
    Close();
}



void __fastcall TFInteg::Button4Click(TObject *Sender)
{
    Graphics::TBitmap * bmv = new Graphics::TBitmap();
    if (!Memo1->Lines->Count) Button1->Click();
    TxtToBmp( Memo1->Lines, bmv, qvar->FontDialog1->Font, 0, 0 );
    bmv->SaveToFile( "out.bmp" );
    Preview->ImageEnIO1->LoadFromFile( "out.bmp" );
    unlink( "out.bmp" );
    delete bmv;
    Preview->ShowModal();
}



void __fastcall TFInteg::RadioButton1Click(TObject *Sender)
{
    if (RadioButton1->Checked == True)
    {
        Edit3->Enabled = False;
        Edit4->Enabled = False;
    }
}



void __fastcall TFInteg::RadioButton2Click(TObject *Sender)
{
    if (RadioButton2->Checked == True)
    {
        Edit3->Enabled = True;
        Edit4->Enabled = True;
    }
}



void __fastcall TFInteg::Button2Click(TObject *Sender)
{
    Button1->Click();
    Close();
}



void __fastcall TFInteg::FormShow(TObject *Sender)
{
    Memo1->Clear();
}



