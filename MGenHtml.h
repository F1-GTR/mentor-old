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
        TEdit *Edit2;
        TProgressBar *ProgressBar1;
        TLabel *Label4;
        TSaveDialog *SaveDialog1;
        TButton *Button2;
        TCheckBox *CheckBox1;
    TImageEnIO *ImageEnIO1;
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:
public:
	virtual __fastcall TGenHtml(TComponent* AOwner);
        void __fastcall gen_test( int NVar );
        void __fastcall gen_for_redclass( int NVar );
};
//----------------------------------------------------------------------------
extern PACKAGE TGenHtml *GenHtml;
//----------------------------------------------------------------------------
#endif    
