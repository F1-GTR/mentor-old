//---------------------------------------------------------------------------
#ifndef MPreview3H
#define MPreview3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TPreview3 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TPopupMenu *PopupMenu1;
        TMenuItem *N1;
        TMenuItem *N111;
        TMenuItem *N2;
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N111Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPreview3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPreview3 *Preview3;
//---------------------------------------------------------------------------
#endif
