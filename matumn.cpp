//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include "matumn.h"
#include "MPreview.h"
#include "MConvert.h"
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tpmatumn *pmatumn;
//---------------------------------------------------------------------------
__fastcall Tpmatumn::Tpmatumn(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tpmatumn::Button1Click(TObject *Sender)
{
  ModalResult=1;        
}
//---------------------------------------------------------------------------
void __fastcall Tpmatumn::Button2Click(TObject *Sender)
{
  String p=String("  ");
  String s=Edit1->Text+p+Edit2->Text+p+Edit3->Text;
  quest->strpar1=strdup(s.c_str());
  s=Edit4->Text+p+Edit5->Text;
  quest->strpar2=strdup(s.c_str());
  ModalResult=2;        
}
//---------------------------------------------------------------------------
void __fastcall Tpmatumn::Button3Click(TObject *Sender)
{
        if (RadioGroup1->ItemIndex == 0)
        {
                quest->keygen = StrToInt(Edit5->Text);
        }
        else
                quest->keygen = 0;

  quest->kstrok=StrToInt(Edit1->Text);
  quest->kstolb=StrToInt(Edit2->Text);
  quest->amin=StrToInt(Edit3->Text);
  quest->amax=StrToInt(Edit4->Text);
//  quest->keygen=StrToInt(Edit5->Text);
  quest->nvar=StrToInt(Edit6->Text);
  quest->nquest=1;
  quest->nzad=1;
  String p = String("  ");
  String s = Edit1->Text+p+Edit2->Text+p+Edit3->Text;
  quest->strpar1=strdup(s.c_str());
  s=Edit4->Text+p+Edit6->Text;
  quest->strpar2=strdup(s.c_str());
  TList* plist=new TList();
  quest->Print(plist);
  Memo1->Clear();
  for(int i=0;i<plist->Count;i++){
    Memo1->Lines->Append(String((char*)plist->Items[i]));
  }
}
//---------------------------------------------------------------------------
void __fastcall Tpmatumn::RadioGroup1Click(TObject *Sender)
{
  if(RadioGroup1->ItemIndex==0){
    Edit5->Enabled=true;
    Edit6->Enabled=true;
    Edit5->Text=IntToStr(quest->keygen);
    Edit6->Text=String("1");
  }
  else{
    Edit5->Enabled=false;
    Edit6->Enabled=false;
    Edit5->Text=String("1");
    Edit6->Text=String("1");
  }        
}
//---------------------------------------------------------------------------
void __fastcall Tpmatumn::FormActivate(TObject *Sender)
{
  Edit1->Text=IntToStr(quest->kstrok);
  Edit2->Text=IntToStr(quest->kstolb);
  Edit3->Text=IntToStr(quest->amin);
  Edit4->Text=IntToStr(quest->amax);
  Memo1->Clear();
  RadioGroup1->ItemIndex=1;
  RadioGroup1Click(NULL);        
}
//---------------------------------------------------------------------------
void __fastcall Tpmatumn::Button4Click(TObject *Sender)
{
        Graphics::TBitmap * bmv = new Graphics::TBitmap();
        
        if ( !Memo1->Lines->Count )
                Button3->Click();

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

