//---------------------------------------------------------------------------
#ifndef MEditWorkH
#define MEditWorkH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TEditWork : public TForm
{
__published:	// IDE-managed Components
        TListBox *ListBox1;
        TPopupMenu *PopupMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TEditWork(TComponent* Owner);
        TList * EL;
        int FirstNumber;
        int Index1;
        int Index2;
        int Edit;
};
//---------------------------------------------------------------------------
extern PACKAGE TEditWork *EditWork;
//---------------------------------------------------------------------------
#endif
