//---------------------------------------------------------------------------

#ifndef __test____m_derivH
#define __test____m_derivH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TBevel *Bevel1;
    TPanel *Panel2;
    TBevel *Bevel2;
    TPanel *Panel3;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn3;
    TGroupBox *GroupBox1;
    TListBox *ListA3;
    TListBox *ListA2;
    TListBox *ListA1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TGroupBox *GroupBox2;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TListBox *ListE2;
    TListBox *ListE3;
    TListBox *ListE1;
    TBitBtn *BitBtn2;
    TImage *Image1;
    TLabel *Label7;
    TLabel *Label8;
    TProgressBar *ProgressBar1;
    TBitBtn *BitBtn4;
    TLabel *lblIter;
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall BitBtn3Click(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
    void __fastcall BitBtn4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
