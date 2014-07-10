//---------------------------------------------------------------------------
#ifndef MShow1H
#define MShow1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMShow : public TForm
{
__published:	// IDE-managed Components
        TListBox *ListBox1;
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMShow(TComponent* Owner);
        TList * lst;

        bool save_quest;

        char * NameJob;
        int number;
};
//---------------------------------------------------------------------------
extern PACKAGE TMShow *MShow;
//---------------------------------------------------------------------------
#endif
