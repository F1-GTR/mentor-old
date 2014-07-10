//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "__develop_frm.h"
#include "mc_deriv.cpp"
#include "m_mflab.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    char deriv[BUFSZ*10];
    range r(-5,5);
    //deriv050201(r,deriv); Memo1->Lines->Add(strdup(deriv));
    //deriv050202(r,deriv); Memo1->Lines->Add(strdup(deriv));
//    deriv050801(r,deriv); Memo1->Lines->Add(strdup(deriv));
    Memo1->Clear();
    char tx[100] = "a=(sin((!(cos(pi)))))";
    Memo1->Lines->Add(rmvpar(tx,tx));
    return;
    do {

//        mflab03(r, deriv);
        int rt=rand();
        srand(2583);
        mflab04(r,deriv); Memo1->Lines->Add(deriv);
        char text[BUFSZ*5], text1[10][BUFSZ];
        char answ[10][BUFSZ], answ1[10][10][BUFSZ];
        int nansw=split_text(deriv, text, answ);
            char strs[20][BUFSZ];
            int nstrs=split_str(text,strs);
            for(int j=0; j<nstrs; ++j)
            {
//                Memo1->Lines->Add(strs[j]);
            }
        for(int i=0; i<nansw; ++i)
        {
            char strs[20][BUFSZ];
            int nstrs=split_str(answ[i],strs);
            for(int j=0; j<nstrs; ++j)
            {
                if (strstr(strs[j],"sinpi"))
                    ShowMessage("sadsadasd");
                ;//Memo1->Lines->Add(strs[j]);
            }
        }
    } while (0);
}
//---------------------------------------------------------------------------

