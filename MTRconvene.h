//---------------------------------------------------------------------------

#ifndef MTRconveneH
#define MTRconveneH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <FileCtrl.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFMTRconv : public TForm
{
__published:	// IDE-managed Components
    TListView *files;
    TPanel *Panel1;
    TPanel *Panel2;
    TPanel *Panel3;
    TPanel *Panel4;
    TPanel *Panel5;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TPanel *Panel7;
    TPanel *Panel8;
    TDriveComboBox *DriveComboBox1;
    TPanel *Panel9;
    TDirectoryListBox *DirectoryListBox1;
    TFileListBox *FileListBox1;
    TSplitter *Splitter1;
    TSplitter *Splitter2;
    TLabel *Label1;
    TPanel *Panel6;
    TBevel *Bevel1;
    TBevel *Bevel2;
    TPanel *Panel10;
    TImage *Image1;
    TLabel *Label2;
    TLabel *Label3;
    TPanel *Panel11;
    TSaveDialog *savedlg;
    TBitBtn *BitBtn3;
    void __fastcall BitBtn2Click(TObject *Sender);
    void __fastcall DriveComboBox1Change(TObject *Sender);
    void __fastcall DirectoryListBox1Change(TObject *Sender);
    void __fastcall FileListBox1DblClick(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall Panel8ConstrainedResize(TObject *Sender, int &MinWidth,
          int &MinHeight, int &MaxWidth, int &MaxHeight);
    void __fastcall filesMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall filesMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall filesDblClick(TObject *Sender);
private:	// User declarations
    void addfile (AnsiString filename);
public:		// User declarations
    __fastcall TFMTRconv(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFMTRconv *FMTRconv;
//---------------------------------------------------------------------------
#endif
