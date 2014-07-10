//----------------------------------------------------------------------------
#ifndef MRenameKonWH
#define MRenameKonWH
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
//----------------------------------------------------------------------------
class TRenameKonW : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TEdit *Edit1;
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall CancelBtnClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:
public:
	virtual __fastcall TRenameKonW(TComponent* AOwner);
        int fl;
};
//----------------------------------------------------------------------------
extern PACKAGE TRenameKonW *RenameKonW;
//----------------------------------------------------------------------------
#endif    
