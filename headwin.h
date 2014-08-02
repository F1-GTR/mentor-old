//---------------------------------------------------------------------------
#ifndef headwinH
#define headwinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Qrctrls.hpp>
#include <QuickRpt.hpp>
#include <Graphics.hpp>
extern tkurs* kurs;
//---------------------------------------------------------------------------
class Thwin : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *Mainmnu;
        TMenuItem *file;
        TMenuItem *fopenkr;
        TMenuItem *N1;
        TMenuItem *saveas;
        TMenuItem *save;
        TMenuItem *close;
        TMenuItem *edit;
        TMenuItem *copy;
        TMenuItem *N2;
        TMenuItem *qedit;
        TStringGrid *Table;
        TOpenDialog *OpenDialog1;
        TMenuItem *N3;
        TMenuItem *exit;
        TStaticText *StaticText1;
        TComboBox *ComboBox1;
        TStaticText *StaticText2;
        TMenuItem *insert;
        TMenuItem *N4;
        TMenuItem *delet;
        TMenuItem *print;
        TPrintDialog *PrintDialog1;
        TImage *Image1;
        TSaveDialog *SaveDialog1;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *Preview;
        TMenuItem *N13;
        TMenuItem *N14;
        TMenuItem *N15;
        TMenuItem *N16;
        TMenuItem *N17;
        TMenuItem *N9;
        TMenuItem *N10;
        TMenuItem *EditKR;
        TMenuItem *N5;
        TMenuItem *DeleteQuest;
        TMenuItem *N12;
        TMenuItem *KRV;
        TMenuItem *N18;
        TMenuItem *N11;
        TMenuItem *EditGenKey;
        TMenuItem *SwapQuest;
        TMenuItem *AddQuest;
        TMenuItem *CanselAddQuest;
        TMenuItem *RenameKW;
        TMenuItem *PrintSetup;
        TMenuItem *Cfg;
        TMenuItem *html1;
        TMenuItem *N19;
        TMenuItem *VarCompare;
    TMenuItem *N20;
    TMenuItem *MTRconv1;
    TBevel *Bevel1;
        TMenuItem *N21;
        void __fastcall fopenkrClick(TObject *Sender);
        void __fastcall saveClick(TObject *Sender);
        void __fastcall saveasClick(TObject *Sender);
        void __fastcall qeditClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall TableClick(TObject *Sender);
        void __fastcall closeClick(TObject *Sender);
        void __fastcall exitClick(TObject *Sender);
        void __fastcall insertClick(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall ComboBox1Click(TObject *Sender);
        void __fastcall deletClick(TObject *Sender);
        void __fastcall PreviewClick(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N14Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall N17Click(TObject *Sender);
        void __fastcall TableDblClick(TObject *Sender);
        void __fastcall EditKRClick(TObject *Sender);
        void __fastcall KRVClick(TObject *Sender);
        void __fastcall EditGenKeyClick(TObject *Sender);
        void __fastcall DeleteQuestClick(TObject *Sender);
        void __fastcall AddQuestClick(TObject *Sender);
        void __fastcall SwapQuestClick(TObject *Sender);
        void __fastcall CanselAddQuestClick(TObject *Sender);
        void __fastcall RenameKWClick(TObject *Sender);
        void __fastcall PrintSetupClick(TObject *Sender);
        void __fastcall CfgClick(TObject *Sender);
        void __fastcall html1Click(TObject *Sender);
        void __fastcall VarCompareClick(TObject *Sender);
        void __fastcall printClick(TObject *Sender);
    void __fastcall MTRconv1Click(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
        void __fastcall N21Click(TObject *Sender);
//        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall Thwin(TComponent* Owner);
        char* filename;
        TList* tasklist;
};
//---------------------------------------------------------------------------
extern PACKAGE Thwin *hwin;
//---------------------------------------------------------------------------
#endif
