//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#include <printers.hpp>
#include <stdlib.h>
#include <dir.h>
#include "bmentor.h"
#include "global.h"
#include "tkurs.h"
#include "tquest.h"
#include "headwin.h"
#include "dtask.h"
#include "qvarnt.h"
#include "nqselect.h"
#include "MPreview2.h"
#include "MAbout.h"
#include "MShow1.h"
#include "MKRVar.h"
#include "MGenKey.h"
#include "utilm.cpp"
#include "MEditWork.h"
#include "MConvert.h"
#include "MRenameKonW.h"
#include "MMentorConfig.h"
#include "MGenHtml.h"
#include "MVarCmp.h"
#include "MPrint.h"
#include "MTRconvene.h"
#include "Unit1.h"
#include "Unit2.h"
#include "MScanDialog.h"
#include <windows.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thwin *hwin;
TFMTRconv *FMTRconv;
int flagaddtask = 0;
//---------------------------------------------------------------------------
__fastcall Thwin::Thwin(TComponent* Owner)
        : TForm(Owner)
{
        kurs = NULL;
        
}
//---------------------------------------------------------------------------
//dialog otkritiya faila
void __fastcall Thwin::fopenkrClick(TObject *Sender)
{
        AnsiString InDir;

        InDir = GetCurrentDir();

        OpenDialog1->InitialDir = InDir;

        filename = strdup("system.mtr");

        if(OpenDialog1->Execute())
        {
                filename = OpenDialog1->FileName.c_str();
                Caption = OpenDialog1->FileName;

                fopenkr->Enabled = false;
                //    save->Enabled=true;
                saveas->Enabled = true;
                close->Enabled = true;
                exit->Enabled = true;
                ComboBox1->Enabled = true;
                insert->Enabled = true;
                delet->Enabled = true;
                EditKR->Enabled = true;

                AddQuest->Enabled = true;
                DeleteQuest->Enabled = true;
                SwapQuest->Enabled = true;

                KRV->Enabled = true;
                RenameKW->Enabled = true;
                html1->Enabled = true;
                VarCompare->Enabled = true;
        //}

        kurs = new tkurs(filename);
        FormActivate(NULL);

        if(ComboBox1->Items->Count == 0 )
                ComboBox1->Enabled = false;
        }
}
//---------------------------------------------------------------------------
//sohranenie MTR faila
void __fastcall Thwin::saveClick(TObject *Sender)
{
  kurs->Save(filename);
  save->Enabled = false;
  MShow->save_quest = false;
}
//---------------------------------------------------------------------------
//sohranenie MTR faila
void __fastcall Thwin::saveasClick(TObject *Sender)
{
/*  OpenDialog1->FileName=String(filename);
  if(OpenDialog1->Execute()){
    filename=OpenDialog1->FileName.c_str();
    Caption=OpenDialog1->FileName;
  }
  kurs->Save(filename);*/
  
  SaveDialog1->FileName = String(filename);
  
  if(SaveDialog1->Execute()){
    filename=SaveDialog1->FileName.c_str();
    Caption = SaveDialog1->FileName;
  }
  
  kurs->Save(filename);
}
//---------------------------------------------------------------------------
//PROB izmenenie MTR faila
void __fastcall Thwin::qeditClick(TObject *Sender)
{
  if( kurs->selectquest )
  {
    kurs->selectquest->Edit();
    save->Enabled = true;
  }
}
//---------------------------------------------------------------------------

//deystviya pri inicilizacii formi
void __fastcall Thwin::FormActivate(TObject *Sender)
{
 Log->Add("Main form activate..");
  int kx = 0;
  int ky = 0;
  int mky[100];
  int i,j;

  if( kurs )
  {
  Table->Visible = true;

  for(int i = 0; i < kurs->qlist->Count; i ++)
  {
    bmentor* b = (bmentor*)kurs->qlist->Items[i];

    if( b->type == ITEM )
    {
        kx++;
        mky[kx-1] = 0;
    }

    if( b->type == SUBITEM )
        mky[kx-1]++;
  }

  for(int i = 0; i < kx; i++)
  {
        if( mky[i] > ky )
                ky = mky[i];
  }

  int lenx = 200;
  int leny = 20; //40;

  Table->DefaultRowHeight=leny;
  Table->DefaultColWidth=lenx;
  Table->ColCount = kx + 0;
  Table->RowCount = ky + 1;
  //!tTable->Width = (Table->DefaultColWidth+Table->GridLineWidth) * (kx + 0);
  //!tTable->Height = (Table->DefaultRowHeight+Table->GridLineWidth) * (ky + 1);
  Table->FixedColor = TColor(RGB(0,255,0));

  for ( i = 0; i < kx; i ++ )
        for ( j = 0; j < ky; j ++ )
                Table->Cells[i][j] = "";

  kx = 0;
  ky = 0;

  for(int i = 0; i < kurs->qlist->Count; i++)
  {
    bmentor* b = (bmentor*)kurs->qlist->Items[i];

    if( b->type == ITEM )
    {
      Table->Cells[kx][0] = String(b->name);
//      Table->RowHeights[0] = leny;
//      Table->ColWidths[kx] = lenx;
      kx++;
      ky = 0;
    }

    if( b->type == SUBITEM )
    {
      Table->Cells[kx-1][ky+1] = String(b->name);
      Table->RowHeights[ky+1] = leny;
      ky++;
    }
  }
  ComboBox1->Clear();
  kurs->selecttask = NULL;

  int nt = 0;

  for(int i = 0; i < kurs->qlist->Count; i++)
  {
    bmentor* b = (bmentor*)kurs->qlist->Items[i];

    if( b->type == JOB )
    {
      ComboBox1->Items->Add(String(b->name));
      ComboBox1->ItemIndex = nt;
      nt++;
      kurs->selecttask = b;
    }

    /*if (b->type == QUEST)
    {
        ComboBox2->Items->Add(String(b->name));
    }*/
  }

  /*AnsiString temp;

  for( int i = 0; i < ComboBox1->Items->Count; i++)
        for(int j = 0; j < ComboBox1->Items->Count; j++ )
        {
                if( ComboBox1->Items->Strings[i] > ComboBox1->Items->Strings[j] )
                {
                        temp = ComboBox1->Items->Strings[i];
                        ComboBox1->Items->Strings[i] = ComboBox1->Items->Strings[j];
                        ComboBox1->Items->Strings[j] = temp;
                }
        }
  ComboBox1->ItemIndex = 0;*/

  ComboBox1Click(NULL);
  
  tasklist = new TList();
  }

}
//---------------------------------------------------------------------------

void __fastcall Thwin::TableClick(TObject *Sender)
{
        if (EditWork->Edit==ADDQUEST)
        {
                int nx = Table->Col+1;
                int ny = Table->Row;
                int i, j;
                int Ind;

                TList* lq = new TList();
                for(int i = 0; i < kurs->qlist->Count; i ++)
                {
                    bmentor* b = (bmentor*)kurs->qlist->Items[i];
                    if(b->type == QUEST)
                        if (b->itemnumber==nx && b->subitemnumber==ny)
                            lq->Add(b);
                }

                for (i = 0; i<kurs->qlist->Count; i++)
                {   bmentor* t = (bmentor*)kurs->qlist->Items[i];
                    if (t->type==JOB && !ComboBox1->Text.AnsiCompare(t->name)) {
                        j=i;
                        bmentor* d = (bmentor*)kurs->qlist->Items[j];
                        do {
                            j++;
                            if (j!=kurs->qlist->Count)
                                d=(bmentor*)kurs->qlist->Items[j];
                            else
                                break;
                        } while (d->numbertask==t->number);
                        tquest* b = (tquest*)lq->Items[0];
                        tquest* q = qcreate(b);
                        q->number = kurs->selecttask->number;
                        q->numbertask = t->number;
                        kurs->qlist->Insert(j,q);
                    }
                }

                Ind = ComboBox1->ItemIndex;
                FormActivate(NULL);
                ComboBox1->ItemIndex = Ind;
                ComboBox1->OnClick(NULL);
                EditWork->Edit = NOQUEST;
                save->Enabled = true;
                CanselAddQuest->Visible = false;
                DeleteQuest->Visible = true;
                SwapQuest->Visible = true;
                save->OnClick( NULL );
                delete lq;
        }
        else
        {
                int nx = Table->Col+1;
                int ny = Table->Row;

                qedit->Enabled = false;
                TList* lq = new TList();

                if(!flagaddtask)
                {
                    for(int i=0; i<kurs->qlist->Count; i++)
                    {
                        bmentor* b = (bmentor*)kurs->qlist->Items[i];
                        if (b->type==QUEST)
                            if (b->itemnumber==nx && b->subitemnumber==ny)
                                if (kurs->selecttask->number==b->numbertask)
                                {
                                    kurs->selectquest = (tquest*)b;
                                    qedit->Enabled = true;
                                    lq->Add(b);
                                }
                    }
                    int nss = lq->Count;
                    if (nss>1) MShow->ShowModal();

                    if(lq->Count)
                        kurs->selectquest = (tquest*)lq->Items[nss-1];
                }
                else
                {
                        for (int i=0; i<kurs->qlist->Count; i++)
                        {
                            bmentor* b = (bmentor*)kurs->qlist->Items[i];
                            if (b->type==QUEST)
                                if (b->itemnumber==nx && b->subitemnumber==ny)
                                {
                                    kurs->selectquest = (tquest*)b;
                                    lq->Add(b);
                                    break;
                                }
                        }

                        if(lq->Count == 0)
                                FError("Не выбран вопрос, повторите указание ",0);
                        else
                        {
                                tasklist->Add(kurs->selectquest);
                                insertClick(NULL);
                        }
                }
      }
// Удаляем переменную lq
//  delete lq;
}
//---------------------------------------------------------------------------

void __fastcall Thwin::closeClick(TObject *Sender)
{
  int i = IDNO;

  if( save->Enabled )
  {
    i = Application->MessageBox("Вы хотите сохранить измения?","",MB_YESNOCANCEL);
  }

  if( i == IDYES )
        saveClick(Sender);

  if( i == IDYES || i == IDNO )
  {
      //delete kurs;
      /*if ( kurs )
      {
        for ( j = 0; j < kurs->qlist->Count; j ++ )
                kurs->qlist->Items[j] = NULL;

        kurs->qlist->Pack();
      } */

      kurs = NULL;

      ComboBox1->Clear();

      Table->Visible = false;
      fopenkr->Enabled = true;
      save->Enabled = false;
      saveas->Enabled = false;
      close->Enabled = false;
      print->Enabled = false;
      Preview->Enabled = false;
      ComboBox1->Enabled = false;
      hwin->Caption = "Mentor";
      insert->Enabled = false;
      delet->Enabled = false;
      EditKR->Enabled = false;

      AddQuest->Enabled = false;
      DeleteQuest->Enabled = false;
      SwapQuest->Enabled = false;

      KRV->Enabled = false;
      RenameKW->Enabled = false;
      html1->Enabled = false;
      VarCompare->Enabled = false;
  }
}
//---------------------------------------------------------------------------

void __fastcall Thwin::exitClick(TObject *Sender)
{
  if( save->Enabled )
        closeClick(Sender);
  Close();
}
//---------------------------------------------------------------------------

void __fastcall Thwin::insertClick(TObject *Sender)
{
  flagaddtask = 0;
  //ptask->Edit1->Text = String("Имя контрольной работы");

  int k = ptask->ShowModal();

  if( k == 1 )
  {
        tasklist->Clear();
  }

  if( k == 2 )
  {
    if(tasklist->Count)
    {

      bmentor* t = new bmentor();
      t->number = t->inumber++;
      t->type = JOB;
      t->name = strdup(ptask->Edit1->Text.c_str());
      kurs->qlist->Add(t);

      for(int i = 0; i < tasklist->Count; i++)
      {
        tquest* b = (tquest*)tasklist->Items[i];
        tquest* q = qcreate(b);
        q->number = q->inumber++;
        q->numbertask = t->number;
        kurs->qlist->Add(q);
      }
// Удаляем переменную t
      //delete t;
    }

    tasklist->Clear();

    FormActivate(NULL);

    qedit->Enabled = false;
    save->Enabled = true;
  }

  if( k == 3 )
  {
        flagaddtask = 1;
  }
}
//---------------------------------------------------------------------------

void __fastcall Thwin::FormKeyPress(TObject *Sender, char &Key)
{
  if( flagaddtask && Key == '1x1B' )
  {
    flagaddtask = 0;
    insertClick(NULL);
  }
}
//---------------------------------------------------------------------------

void __fastcall Thwin::ComboBox1Click(TObject *Sender)
{
        int k = ComboBox1->ItemIndex;

        char* name = ComboBox1->Items->Strings[k].c_str();

        for(int i = 0; i < kurs->qlist->Count; i ++)
        {
                bmentor* b = (bmentor*)kurs->qlist->Items[i];

                if( b->type == JOB )
                {
                        if(!strcmp(b->name,name))
                        {
                                kurs->selecttask = b;
                                break;
                        }
                }
        }

        print->Enabled = true;
        Preview->Enabled = true;
        qedit->Enabled = false;

        for(int i = 0; i < kurs->qlist->Count; i ++)
        {
                bmentor* b = (bmentor*)kurs->qlist->Items[i];

                if( b->type == JOB )
                {
                        if( kurs->selecttask == b )
                        {
                                MShow->ListBox1->Clear();

                                MShow->lst->Clear();

                                int chislo = 0;

                                for(int j = i + 1; j < kurs->qlist->Count; j ++)
                                {
                                        b = (bmentor*)kurs->qlist->Items[j];

                                        if ( b->numbertask == kurs->selecttask->number )
                                        {
                                                chislo ++;
                                                MShow->ListBox1->Items->Add( IntToStr(chislo) + "." + Table->Cells[b->itemnumber - 1][b->subitemnumber] );
                                                MShow->lst->Add( b );
                                        }

                                //MShow->Height = (chislo + 1)* 20 + 35;
                                }
                        }
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall Thwin::deletClick(TObject *Sender)
{
  AnsiString st = "Вы действительно хотите удалить контрольную работу: '" + ComboBox1->Text + "'?";

  if ( MessageBox(Handle,st.c_str(),"Внимание!",MB_YESNO) == ID_YES )
  {
  for(int i = 0; i < kurs->qlist->Count; i ++)
  {
    bmentor* b = (bmentor*)kurs->qlist->Items[i];

    if( b->type == JOB )
    {
      if( kurs->selecttask == b )
      {
        int n = b->number;
        kurs->qlist->Items[i] = NULL;

        for( int j = i + 1; j < kurs->qlist->Count; j ++ )
        {
          b = (bmentor*)kurs->qlist->Items[j];

          if( b->numbertask == n )
                kurs->qlist->Items[j] = NULL;
        }
        break;
      }
    }
  }

  kurs->qlist->Pack();
  save->Enabled = true;
  FormActivate(NULL);
  }
}
//---------------------------------------------------------------------------

void __fastcall Thwin::PreviewClick(TObject *Sender)
{
  TList* list = new TList();

  int numb, kvar, left, top;

  qvar->Edit1->Text = String("1");
  qvar->Edit4->Text = String("1");

  qvar->ShowModal();

  StrToInt(qvar->Edit1->Text);

  if ( qvar->ModalResult != mrCancel )
  {
        //Preview2->ImageEnIO1->AttachedBitmap = Preview2->Image1->Picture->Bitmap;
        //hwin->Visible = false;

        kvar = StrToInt(qvar->Edit1->Text);

        if( kvar<1 || kvar > 50 )
        {
                FError("Недопустимое количество вариантов",1);
                kvar = 1;
        }

        numb = StrToInt( qvar->Edit4->Text );

        left = StrToInt( qvar->Edit2->Text );
        top = StrToInt( qvar->Edit3->Text );

        for(int ncvar = numb; ncvar < kvar + numb; ncvar++ )
        {
            list->Clear();
            for(int i = 0; i < kurs->qlist->Count; i ++)
            {
                bmentor* b = (bmentor*)kurs->qlist->Items[i];

                if(b->type == JOB)
                {
                    if( kurs->selecttask == b )
                    {
                        int nz = 0;
                        for(int j = i + 1; j < kurs->qlist->Count; j ++)
                        {
                            b = (bmentor*)kurs->qlist->Items[j];
                            if (b->numbertask == kurs->selecttask->number)
                            {
                                b->nvar = ncvar;
                                nz++;
                                b->nzad = nz;
                                b->keygen = ( ncvar * GenKey->GeneralKey + nz ) % 1000 + 1;
                                b->Print(list);
                            }
                        }
                        break;
                    }
                }
            }

            TList* list1 = new TList();
            TList* list2 = new TList();

            int ns = 1;

            for(int i = 0; i < list->Count; i++)
            {
                char* t = (char*)list->Items[i];
                if(strchr(t,'#')) ns = 1;
                if(strchr(t,'@')) ns = 2;
                if( ns == 1 ) list1->Add(t);
                if( ns == 2 ) list2->Add(t);
            }
            list->Clear();

            for(int i = 0; i < list1->Count; i ++)
                list->Add(list1->Items[i]);

            list->Add("String(___________________________________________)");

            for(int i = 0; i < list2->Count; i ++)
                list->Add(list2->Items[i]);

            if ( qvar->CheckBox1->Checked == true )
            {
                if( list1->Count )
                {
                    Graphics::TBitmap* bmv = new Graphics::TBitmap();
                    TxtToBmp (list1, bmv, qvar->FontDialog1->Font, left, top);
                    Preview2->Left = 0; Preview2->Top = 0;
                    if (bmv->Width+25<Screen->Width) Preview2->Width = bmv->Width + 25;
                    else Preview2->Width = Screen->Width;
                    if (bmv->Height + 30 < Screen->Height) Preview2->Height = bmv->Height;
                    else Preview2->Height = Screen->Height - 30;
                    Preview2->Image1->Width = bmv->Width;
                    Preview2->Image1->Height = bmv->Height;
                    //Preview2->ImageEnIO1->AttachedBitmap = Preview2->Image1->Picture->Bitmap;
                    Preview2->Image1->Picture->Bitmap = bmv;
                    Preview2->Caption = "Предварительный просмотр печати - ВАРИАНТ " + IntToStr(ncvar);
                    Preview2->ShowModal();
                    delete bmv;
                }
            }
            else
            if ( qvar->CheckBox2->Checked == true )
            {
                if( list2->Count )
                {
                        Graphics::TBitmap* bmv = new Graphics::TBitmap();
                        TxtToBmp (list2, bmv, qvar->FontDialog1->Font, left, top);
                        Preview2->Left = 0; Preview2->Top = 0;
                        if (bmv->Width+25<Screen->Width) Preview2->Width = bmv->Width + 25;
                        else Preview2->Width = Screen->Width;
                        if (bmv->Height+30<Screen->Height) Preview2->Height = bmv->Height;
                        else Preview2->Height = Screen->Height - 30;
                        Preview2->Image1->Width = bmv->Width;
                        Preview2->Image1->Height = bmv->Height;
                        //Preview2->ImageEnIO1->AttachedBitmap = Preview2->Image1->Picture->Bitmap;
                        Preview2->Image1->Picture->Bitmap = bmv;
                        Preview2->Caption = "Предварительный просмотр печати - ВАРИАНТ " + IntToStr(ncvar);
                        Preview2->ShowModal();
                        delete bmv;
                }
            }
            else
            if (list->Count)
            {
                Graphics::TBitmap* bmv = new Graphics::TBitmap();
                TxtToBmp(list, bmv, qvar->FontDialog1->Font, left, top);
                Preview2->Left = 0; Preview2->Top = 0;
                if (bmv->Width + 25 < Screen->Width) Preview2->Width = bmv->Width + 25;
                else Preview2->Width = Screen->Width;
                if (bmv->Height + 30 < Screen->Height) Preview2->Height = bmv->Height;
                else Preview2->Height = Screen->Height - 30;
                Preview2->Image1->Width = bmv->Width;
                Preview2->Image1->Height = bmv->Height;

                //Preview2->ImageEnIO1->AttachedBitmap = Preview2->Image1->Picture->Bitmap;
                Preview2->Image1->Picture->Bitmap = bmv;
                Preview2->Caption = "Предварительный просмотр печати - ВАРИАНТ " + IntToStr(ncvar);
                Preview2->ShowModal();
                delete bmv;
            }

            delete list1;
            delete list2;
        }
    }
    delete list;
//        hwin->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall Thwin::N7Click(TObject *Sender)
{
        Application->HelpCommand(HELP_CONTENTS, 0);
        //WinExec("notepad mentor.txt",SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

void __fastcall Thwin::N8Click(TObject *Sender)
{
        About->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Thwin::N14Click(TObject *Sender)
{
        closeClick(NULL);
        //delete kurs;

        //filename = strdup("system.mtr");
        filename = strdup("syslin.mtr");
        fopenkr->Enabled = false;
        saveas->Enabled = true;
        close->Enabled = true;
        exit->Enabled = true;
        ComboBox1->Enabled = true;
        insert->Enabled = true;
        delet->Enabled = true;
        EditKR->Enabled = true;

        AddQuest->Enabled = true;
        DeleteQuest->Enabled = true;
        SwapQuest->Enabled = true;

        KRV->Enabled = true;
        RenameKW->Enabled = true;
        html1->Enabled = true;
        VarCompare->Enabled = true;

        kurs = new tkurs(filename);

        FormActivate(NULL);

        if(ComboBox1->Items->Count == 0)
                ComboBox1->Enabled = false;

        ComboBox1->OnClick(NULL);
}
//---------------------------------------------------------------------------

void __fastcall Thwin::N15Click(TObject *Sender)
{
        closeClick(NULL);
//        delete kurs;

        //filename = strdup("geometri.mtr");
        filename = strdup("sysgeo.mtr");
        fopenkr->Enabled = false;
        saveas->Enabled = true;
        close->Enabled = true;
        exit->Enabled = true;
        ComboBox1->Enabled = true;
        insert->Enabled = true;
        delet->Enabled = true;
        EditKR->Enabled = true;

        AddQuest->Enabled = true;
        DeleteQuest->Enabled = true;
        SwapQuest->Enabled = true;

        KRV->Enabled = true;
        RenameKW->Enabled = true;
        html1->Enabled = true;
        VarCompare->Enabled = true;
        
        kurs = new tkurs(filename);

        FormActivate(NULL);

        if( ComboBox1->Items->Count == 0 )
                ComboBox1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall Thwin::N17Click(TObject *Sender)
{
        closeClick(NULL);

        //filename = strdup("integral.mtr");
        filename = strdup("sysint.mtr");
        fopenkr->Enabled = false;
        saveas->Enabled = true;
        close->Enabled = true;
        exit->Enabled = true;
        ComboBox1->Enabled = true;
        insert->Enabled = true;
        delet->Enabled = true;
        EditKR->Enabled = true;
        AddQuest->Enabled = true;
        DeleteQuest->Enabled = true;
        SwapQuest->Enabled = true;
        KRV->Enabled = true;
        RenameKW->Enabled = true;
        html1->Enabled = true;
        VarCompare->Enabled = true;

        kurs = new tkurs(filename);

        FormActivate(NULL);

        if( ComboBox1->Items->Count == 0 )
                ComboBox1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall Thwin::TableDblClick(TObject *Sender)
{
        if( kurs->selectquest )
        {
                kurs->selectquest->Edit();
                save->Enabled = true;
        }
}
//---------------------------------------------------------------------------


void __fastcall Thwin::EditKRClick(TObject *Sender)
{
        MShow->ShowModal();

        if ( MShow->save_quest == true )
        {
                save->Enabled = true;

                save->OnClick ( NULL );
        }
}
//---------------------------------------------------------------------------

void __fastcall Thwin::KRVClick(TObject *Sender)
{
        KRVar->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Thwin::EditGenKeyClick(TObject *Sender)
{
        GenKey->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Thwin::DeleteQuestClick(TObject *Sender)
{
        extern TList * EL;

        int Ind;

        EditWork->Edit = DELETEQUEST;

        for(int i = 0; i < kurs->qlist->Count; i ++)
        {
                bmentor* b = (bmentor*)kurs->qlist->Items[i];

                if( b->type == JOB )
                {
                        if( kurs->selecttask == b )
                        {
                                EditWork->ListBox1->Clear();

                                EditWork->EL->Clear();

                                EditWork->FirstNumber = i + 1;

                                int chislo = 0;

                                for(int j = i + 1; j < kurs->qlist->Count; j ++)
                                {
                                        b = (bmentor*)kurs->qlist->Items[j];

                                        if ( b->numbertask == kurs->selecttask->number )
                                        {
                                                chislo ++;
                                                EditWork->ListBox1->Items->Add( IntToStr(chislo) + "." + Table->Cells[b->itemnumber - 1][b->subitemnumber] );
                                                EditWork->EL->Add( b );
                                        }
                                }
                        }
                }
        }

        EditWork->ShowModal();

        Ind = ComboBox1->ItemIndex;

        FormActivate(NULL);

        ComboBox1->ItemIndex = Ind;
        ComboBox1->OnClick ( NULL);

        EditWork->Edit = NOQUEST;

        save->Enabled = true;
        save->OnClick ( NULL );
}
//---------------------------------------------------------------------------

void __fastcall Thwin::AddQuestClick(TObject *Sender)
{
        EditWork->Edit = ADDQUEST;

        CanselAddQuest->Visible = true;
        DeleteQuest->Visible = false;
        SwapQuest->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall Thwin::SwapQuestClick(TObject *Sender)
{
        extern TList * EL;

        int Ind;

        EditWork->Edit = SWAPQUEST_A;

        for(int i = 0; i < kurs->qlist->Count; i ++)
        {
                bmentor* b = (bmentor*)kurs->qlist->Items[i];

                if( b->type == JOB )
                {
                        if( kurs->selecttask == b )
                        {
                                EditWork->ListBox1->Clear();

                                EditWork->EL->Clear();

                                EditWork->FirstNumber = i + 1;

                                int chislo = 0;

                                for(int j = i + 1; j < kurs->qlist->Count; j ++)
                                {
                                        b = (bmentor*)kurs->qlist->Items[j];

                                        if ( b->numbertask == kurs->selecttask->number )
                                        {
                                                chislo ++;
                                                EditWork->ListBox1->Items->Add( IntToStr(chislo) + "." + Table->Cells[b->itemnumber - 1][b->subitemnumber] );
                                                EditWork->EL->Add( b );
                                        }
                                }
                        }
                }
        }

        EditWork->ShowModal();

        Ind = ComboBox1->ItemIndex;

        FormActivate(NULL);

        ComboBox1->ItemIndex = Ind;
        ComboBox1->OnClick ( NULL);

        EditWork->Edit = NOQUEST;

        save->Enabled = true;
        save->OnClick ( NULL );
}
//---------------------------------------------------------------------------

void __fastcall Thwin::CanselAddQuestClick(TObject *Sender)
{
        EditWork->Edit = NOQUEST;

        CanselAddQuest->Visible = false;

        DeleteQuest->Visible = true;
        SwapQuest->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall Thwin::RenameKWClick(TObject *Sender)
{
        int i;
        AnsiString WName;

        RenameKonW->Edit1->Text = ComboBox1->Text;
        WName = ComboBox1->Text;

        RenameKonW->ShowModal();

        if ( RenameKonW->fl )
        {
                for( i = 0; i < kurs->qlist->Count; i++ )
                {
                        bmentor* b = (bmentor*)kurs->qlist->Items[i];

                        if( b->type == JOB && kurs->selecttask == b )
                        {
                                strcpy( kurs->selecttask->name, RenameKonW->Edit1->Text.c_str() );
                                strcpy( b->name, RenameKonW->Edit1->Text.c_str() );

                                break;
                        }
                }

                FormActivate( NULL );
                
                for ( i = 0; i < ComboBox1->Items->Count; i ++ )
                        if ( ComboBox1->Items->Strings[i] == RenameKonW->Edit1->Text )
                        {
                                ComboBox1->ItemIndex = i;
                                break;
                        }

                save->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall Thwin::PrintSetupClick(TObject *Sender)
{
        qvar->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall Thwin::CfgClick(TObject *Sender)
{
        MentorConfig->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Thwin::html1Click(TObject *Sender)
{
        GenHtml->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Thwin::VarCompareClick(TObject *Sender)
{
        CompareVar->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Thwin::printClick(TObject *Sender)
{
        TList* list = new TList();

        int numb, kvar, ncvar;
        int left, top;
        int i, j;
        int nz, ns;

        TFont * Font;

        qvar->Edit1->Text = String( "1" );
        qvar->Edit4->Text = String( "1" );

        qvar->ShowModal();

        if ( qvar->ModalResult != mrCancel )
        {
                kvar = StrToInt(qvar->Edit1->Text);

                if( kvar < 1 || kvar > 50 )
                {
                        FError( "Недопустимое количество вариантов", 1 );
                        kvar = 1;
                }

                numb = StrToInt( qvar->Edit4->Text );

                left = StrToInt( qvar->Edit2->Text );
                top = StrToInt( qvar->Edit3->Text );

                for(ncvar=numb; ncvar<kvar+numb; ncvar++)
                {
                        list->Clear();

                        for(i=0; i<kurs->qlist->Count; i++)
                        {
                                bmentor* b = (bmentor*)kurs->qlist->Items[i];

                                if(b->type==JOB)
                                {
                                        if(kurs->selecttask==b)
                                        {
                                                nz = 0;

                                                for(j=i+1; j<kurs->qlist->Count; j++)
                                                {
                                                        b = (bmentor*)kurs->qlist->Items[j];

                                                        if (b->numbertask == kurs->selecttask->number)
                                                        {
                                                                b->nvar = ncvar;
                                                                nz++;
                                                                b->nzad = nz;

                                                                b->keygen = ( ncvar * GenKey->GeneralKey + nz ) % 1000 + 1;

                                                                b->Print(list);
                                                        }
                                                }

                                                break;
                                        }
                                }
                        }

                        TList* list1 = new TList();
                        TList* list2 = new TList();

                        ns = 1;

                        for( i = 0; i < list->Count; i++ )
                        {
                                char* t = (char*)list->Items[i];

                                if(strchr(t,'#'))
                                        ns = 1;
                                if(strchr(t,'@'))
                                        ns = 2;
                                if( ns == 1 )
                                        list1->Add(t);
                                if( ns == 2 )
                                        list2->Add(t);
                        }

                        list->Clear();

                        for( i = 0; i < list1->Count; i ++ )
                                list->Add( list1->Items[i] );

                        list->Add("String(___________________________________________)");

                        for( i = 0; i < list2->Count; i ++ )
                                list->Add(list2->Items[i]);

                        if ( qvar->CheckBox1->Checked == true )
                        {
                                if( list1->Count )
                                {
                                        Font = qvar->FontDialog1->Font;

                                        Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                        TxtToBmp( list1, bmv, qvar->FontDialog1->Font, left, top );

                                        bmv->SaveToFile( "out.bmp" );

                                        delete bmv;

                                        FilePrint( "out.bmp" );

                                }
                        }
                        else
                        if ( qvar->CheckBox2->Checked == true )
                        {
                                if( list2->Count )
                                {
                                        Font = qvar->FontDialog1->Font;

                                        Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                        TxtToBmp ( list2, bmv, qvar->FontDialog1->Font, left, top );

                                        bmv->SaveToFile( "out.bmp" );

                                        delete bmv;

                                        FilePrint( "out.bmp" );

                                }
                        }
                        else
                        if ( qvar->RadioButton1->Checked == true )
                        {
                                if( list->Count )
                                {
                                        Font = qvar->FontDialog1->Font;

                                        Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                        TxtToBmp ( list, bmv, Font, left, top );

                                        bmv->SaveToFile("out.bmp");

                                        delete bmv;

                                        FilePrint( "out.bmp" );

                                }
                        }
                        else
                        if( qvar->RadioButton2->Checked == true )
                        {
                                if( list1->Count )
                                {
                                        Font = qvar->FontDialog1->Font;

                                        Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                        TxtToBmp ( list1, bmv, Font, left, top );

                                        bmv->SaveToFile("out.bmp");

                                        delete bmv;

                                        FilePrint( "out.bmp" );

                                }

                                if( list2->Count )
                                {
                                        Font = qvar->FontDialog1->Font;

                                        Graphics::TBitmap* bmv = new Graphics::TBitmap();

                                        TxtToBmp ( list2, bmv, Font, left, top );

                                        bmv->SaveToFile("out.bmp");

                                        delete bmv;

                                        FilePrint( "out.bmp" );
                                }
                        }

                        delete list1;
                        delete list2;
                }
        }

        delete list;

        /*qvar->Edit1->Text = String("1");
        qvar->Edit4->Text = String("1");

        qvar->ShowModal();

        if ( qvar->ModalResult != mrCancel )
        {
                if ( kvar < 1 || kvar > 50 )
                {
                        FError( "Недопустимое количество вариантов", 1 );
                        kvar = 1;
                }

                PrintKW->ShowModal();
        }*/
}
//---------------------------------------------------------------------------






void __fastcall Thwin::MTRconv1Click(TObject *Sender)
{
    FMTRconv->ShowModal();
}
//---------------------------------------------------------------------------


//resize formi
void __fastcall Thwin::FormResize(TObject *Sender)
{
    const int
        topIndent = 84,
        rightIndent = 4,
        bottomIndent = 4,
        leftIndent = 4;
    Table->Left = leftIndent;
    Table->Top = topIndent;
    Table->Height = this->ClientHeight - topIndent - bottomIndent;
    Table->Width = this->ClientWidth - leftIndent - rightIndent;
}
//---------------------------------------------------------------------------

void __fastcall Thwin::N21Click(TObject *Sender)
{
        Log->Show();
}
//---------------------------------------------------------------------------






void __fastcall Thwin::MTRScanner1Click(TObject *Sender)
{
     MScan->ShowModal();
}
//---------------------------------------------------------------------------

