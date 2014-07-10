//---------------------------------------------------------------------------
#ifndef MPreview2H
#define MPreview2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Graphics.hpp>
#include "ieopensavedlg.hpp"
#include "imageenio.hpp"
//---------------------------------------------------------------------------
class TPreview2 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TMainMenu *MainMenu1;
        TImageEnIO *ImageEnIO1;
        TSaveImageEnDialog *SaveImageEnDialog1;
        TMenuItem *N1;
        TMenuItem *SaveB;
        TMenuItem *ExitB;
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall SaveBClick(TObject *Sender);
        void __fastcall ExitBClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPreview2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPreview2 *Preview2;
//---------------------------------------------------------------------------
#endif
