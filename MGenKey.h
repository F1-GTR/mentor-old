//----------------------------------------------------------------------------
#ifndef MGenKeyH
#define MGenKeyH
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
class TGenKey : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TLabel *Label1;
        TEdit *Edit1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall CancelBtnClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:
public:
	virtual __fastcall TGenKey(TComponent* AOwner);

        int GeneralKey;
};
//----------------------------------------------------------------------------
extern PACKAGE TGenKey *GenKey;
//----------------------------------------------------------------------------
#endif
