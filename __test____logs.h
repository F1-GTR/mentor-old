//---------------------------------------------------------------------------

#ifndef __test____logsH
#define __test____logsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
    TMemo *Memo1;
    TMemo *Memo2;
    TPanel *Panel1;
    TBevel *Bevel1;
    TPanel *Panel2;
    TBevel *Bevel2;
    TBitBtn *BitBtn1;
    TImage *Image1;
    TLabel *Label1;
    TLabel *Label2;
    void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
