//---------------------------------------------------------------------------
#include <vcl.h>
#include "MLinDet.h"
#include "quest22.h"
#include "MPreview.h"
#include "MConvert.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLinDet *LinDet;
//---------------------------------------------------------------------------
__fastcall TLinDet::TLinDet(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLinDet::Button1Click(TObject *Sender)
{
        if (RadioButton2->Checked == true)
        {
                quest->keygen = StrToInt(Edit3->Text);
        }

  quest->amin= StrToInt(Edit1->Text);
  quest->amax= StrToInt(Edit2->Text);
  quest->dim = StrToInt(Edit5->Text);
  quest->numstr = StrToInt(Edit6->Text);

  quest->nquest=1;
  quest->nzad=1;

  String p = String("  ");
  String s = Edit1->Text + p + Edit2->Text + p + Edit5->Text;
  quest->strpar1=strdup(s.c_str());

  s = Edit1->Text + p + Edit2->Text + p + Edit6->Text;
  quest->strpar2 = strdup(s.c_str());

  TList* plist = new TList();
  quest->Print(plist);

  Memo1->Clear();

  for(int i=0;i<plist->Count;i++){
    Memo1->Lines->Append(String((char*)plist->Items[i]));
  }

}
//---------------------------------------------------------------------------

void __fastcall TLinDet::Button3Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------



void __fastcall TLinDet::Button4Click(TObject *Sender)
{
        Graphics::TBitmap * bmv = new Graphics::TBitmap();

        if ( !Memo1->Lines->Count )
                Button1->Click();

        /*Memo1->Lines->SaveToFile("txtout.txt");
        WinExec("txt2bmp.exe",SW_SHOWDEFAULT);
        Preview->Image1->Picture->LoadFromFile("out.bmp");*/

        TxtToBmp( Memo1->Lines, bmv, qvar->FontDialog1->Font, 0, 0 );
        bmv->SaveToFile( "out.bmp" );

        Preview->ImageEnIO1->LoadFromFile( "out.bmp" );
        //Preview->ImageEnProc1->Resample( -1, Screen->Height - 40, rfBSpline );

        unlink( "out.bmp" );
        delete bmv;

        Preview->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TLinDet::FormCreate(TObject *Sender)
{
        Memo1->Clear();        
}
//---------------------------------------------------------------------------

void __fastcall TLinDet::RadioButton1Click(TObject *Sender)
{
        if (RadioButton1->Checked == True)
        {
                Edit3->Enabled = False;
                Edit4->Enabled = False;
        }
}
//---------------------------------------------------------------------------

void __fastcall TLinDet::RadioButton2Click(TObject *Sender)
{
        if (RadioButton2->Checked == True)
        {
                Edit3->Enabled = True;
                Edit4->Enabled = True;
        }
}
//---------------------------------------------------------------------------

void __fastcall TLinDet::Button2Click(TObject *Sender)
{
        Button1->Click();
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TLinDet::FormActivate(TObject *Sender)
{
        Memo1->Clear();        
}
//---------------------------------------------------------------------------

