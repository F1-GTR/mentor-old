//----------------------------------------------------------------------------
#ifndef MKRVarH
#define MKRVarH
//----------------------------------------------------------------------------
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include "tkurs.h"
//----------------------------------------------------------------------------
class TKRVar : public TForm
{
__published:
	TLabel *Label1;
	TEdit *Password;
	TButton *OKBtn;
	TButton *CancelBtn;
        TEdit *Edit1;
        TLabel *Label2;
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:
public:
	virtual __fastcall TKRVar(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TKRVar *KRVar;
extern tkurs * kurs;
//----------------------------------------------------------------------------
#endif    
