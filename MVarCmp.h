//----------------------------------------------------------------------------
#ifndef MVarCmpH
#define MVarCmpH
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
#include <Grids.hpp>
//----------------------------------------------------------------------------
class TCompareVar : public TForm
{
__published:
	TButton *CancelBtn;
	TBevel *Bevel1;
        TLabel *Label1;
        TComboBox *ComboBox1;
        TStringGrid *Table;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall TableClick(TObject *Sender);
private:
public:
	virtual __fastcall TCompareVar(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TCompareVar *CompareVar;
//----------------------------------------------------------------------------
#endif    
