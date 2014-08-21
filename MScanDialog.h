//---------------------------------------------------------------------------

#ifndef MScanDialogH
#define MScanDialogH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TMScan : public TForm
{
__published:	// IDE-managed Components
        TButton *Folder;
        TLabel *Label1;
        TEdit *Edit1;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label2;
        void __fastcall FolderClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMScan(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMScan *MScan;
//---------------------------------------------------------------------------
#endif
