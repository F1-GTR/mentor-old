//----------------------------------------------------------------------------
#ifndef MGenHtmlH
#define MGenHtmlH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
#include <NMFtp.hpp>
#include <Psock.hpp>
#include "tkurs.h"
#include "imageenio.hpp"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>

extern tkurs* kurs;
//----------------------------------------------------------------------------
class TGenHtml : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TProgressBar *ProgressBar1;
        TLabel *Label4;
        TSaveDialog *SaveDialog1;
        TImageEnIO *ImageEnIO1;
        TButton *VPlus;
        TButton *VMinus;
        TButton *V1;
        TButton *V4;
        TButton *V10;
        TButton *V30;
        TEdit *KName;
        TMemo *SOut;
        TButton *OpenFolder;
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall OpenFolderClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall V1Click(TObject *Sender);
        void __fastcall V4Click(TObject *Sender);
        void __fastcall V10Click(TObject *Sender);
        void __fastcall V30Click(TObject *Sender);
        void __fastcall VPlusClick(TObject *Sender);
        void __fastcall VMinusClick(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall KNameKeyPress(TObject *Sender, char &Key);
private:
public:
	virtual __fastcall TGenHtml(TComponent* AOwner);
        void __fastcall gen_test( int NVar );
        AnsiString KursName;
};
//----------------------------------------------------------------------------
extern PACKAGE TGenHtml *GenHtml;
//----------------------------------------------------------------------------
#endif    
