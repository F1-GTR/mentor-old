//---------------------------------------------------------------------------

#ifndef FEigenH
#define FEigenH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMEigen : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TBevel *Bevel1;
    TMemo *Memo1;
    TEdit *Edit1;
    TEdit *Edit2;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
    TGroupBox *GroupBox1;
    TLabel *Label3;
    TLabel *Label4;
    TRadioButton *RadioButton1;
    TRadioButton *RadioButton2;
    TEdit *Edit3;
    TEdit *Edit4;
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMEigen(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMEigen *MEigen;
//---------------------------------------------------------------------------
#endif
