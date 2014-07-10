//---------------------------------------------------------------------------
#include <vcl.h>
#include <string.h>
#include "dtask.h"
#include "tkurs.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tptask *ptask;
//---------------------------------------------------------------------------
__fastcall Tptask::Tptask(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tptask::Button3Click(TObject *Sender)
{
        int i, exit = 0;
        extern tkurs * kurs;

        for ( i = 0; i < kurs->qlist->Count; i ++ )
        {
                bmentor* b = (bmentor*)kurs->qlist->Items[i];

                if ( b->type == JOB && !strcmp( b->name, Edit1->Text.c_str() ) )
                {
                        exit = 1;
                        break;
                }
        }

        if ( !exit )
        {
                count ++;
                ModalResult = 3;
        }
        else
                ShowMessage("Измените название КР. (Такое уже есть!)");
}
//---------------------------------------------------------------------------
void __fastcall Tptask::Button1Click(TObject *Sender)
{
  count = 0;
  ModalResult = 1;
}
//---------------------------------------------------------------------------
void __fastcall Tptask::Button2Click(TObject *Sender)
{
  if ( !count )
  {
        if ( Application->MessageBox("Вы действительно хотите выйти? (В КР не добавленно вопросов)","Внимание!",MB_YESNO) == ID_YES )
        {
                count = 0;
                ModalResult = 2;
        }
  }
  else
  {
        count  = 0;
        ModalResult = 2;
  }
}
//---------------------------------------------------------------------------
void __fastcall Tptask::FormActivate(TObject *Sender)
{
        if (Edit1->Text == "")
                Edit1->Text = "Имя контрольной работы ";
        Label1->Caption = "Общее число вопросов контрольной работы  - " + IntToStr(count);
}
//---------------------------------------------------------------------------



