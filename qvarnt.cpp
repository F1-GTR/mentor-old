//---------------------------------------------------------------------------
#include <vcl.h>
#include "qvarnt.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "imageenio"
#pragma link "imageenproc"
#pragma resource "*.dfm"
Tqvar *qvar;
//---------------------------------------------------------------------------
__fastcall Tqvar::Tqvar(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tqvar::Button1Click(TObject *Sender)
{
        ModalResult = 1;
}
//---------------------------------------------------------------------------
void __fastcall Tqvar::Button2Click(TObject *Sender)
{
        ModalResult = mrCancel;
}
//---------------------------------------------------------------------------


void __fastcall Tqvar::CheckBox1Click(TObject *Sender)
{
        if ( CheckBox1->Checked == true )
        {
                RadioButton1->Enabled = false;
                RadioButton2->Enabled = false;

                Label4->Enabled = false;

                CheckBox2->Visible = false;
        }
        else
        {
                RadioButton1->Enabled = true;
                RadioButton2->Enabled = true;

                Label4->Enabled = true;

                CheckBox2->Visible = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall Tqvar::CheckBox2Click(TObject *Sender)
{
        if ( CheckBox2->Checked == true )
        {
                RadioButton1->Enabled = false;
                RadioButton2->Enabled = false;

                Label4->Enabled = false;

                CheckBox1->Visible = false;
        }
        else
        {
                RadioButton1->Enabled = true;
                RadioButton2->Enabled = true;

                Label4->Enabled = true;

                CheckBox1->Visible = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall Tqvar::Button3Click(TObject *Sender)
{
        FontDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall Tqvar::FormCreate(TObject *Sender)
{
        FontDialog1->Font->Name = "Arial";
        FontDialog1->Font->Size = 10;

        MZad = 0;
}
//---------------------------------------------------------------------------

void __fastcall Tqvar::CheckBox3Click(TObject *Sender)
{
        if ( CheckBox3->Checked == true )
        {
                MZad = 1;
        }
        else
        {
                MZad = 0;
        }
}
//---------------------------------------------------------------------------

void __fastcall Tqvar::Button4Click(TObject *Sender)
{
        PrintDialog1->Execute();        
}
//---------------------------------------------------------------------------

void __fastcall Tqvar::FormActivate(TObject *Sender)
{
        Edit1->Focused();        
}
//---------------------------------------------------------------------------

