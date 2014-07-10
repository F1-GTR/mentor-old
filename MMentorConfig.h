//----------------------------------------------------------------------------
#ifndef MMentorConfigH
#define MMentorConfigH
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
#include <ComCtrls.hpp>
//----------------------------------------------------------------------------
class TMentorConfig : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TLabel *Label1;
        TComboBox *ComboBox1;
        TLabel *Label2;
        TEdit *Edit1;
        TLabel *Label3;
        TEdit *Edit2;
        TLabel *Label4;
        TEdit *Edit3;
        TLabel *Label5;
        TEdit *Edit4;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall CancelBtnClick(TObject *Sender);
private:
public:
	virtual __fastcall TMentorConfig(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TMentorConfig *MentorConfig;
//----------------------------------------------------------------------------
#endif    
