//----------------------------------------------------------------------------
#ifndef MPrintH
#define MPrintH
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
extern tkurs* kurs;
//----------------------------------------------------------------------------
class TPrintKW : public TForm
{
__published:
	TBevel *Bevel1;
        TProgressBar *ProgressBar1;
        void __fastcall FormActivate(TObject *Sender);
private:
public:
	virtual __fastcall TPrintKW(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TPrintKW *PrintKW;
//----------------------------------------------------------------------------
#endif    
