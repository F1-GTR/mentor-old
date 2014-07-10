//---------------------------------------------------------------------------
#ifndef MPreviewH
#define MPreviewH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include "ieview.hpp"
#include "imageenview.hpp"
#include "imageenio.hpp"
#include "imageenproc.hpp"
#include "ieopensavedlg.hpp"
//---------------------------------------------------------------------------
class TPreview : public TForm
{
__published:	// IDE-managed Components
        TPrintDialog *PrintDialog1;
        TPopupMenu *PopupMenu1;
        TMenuItem *N4;
        TMenuItem *N5;
        TImageEnIO *ImageEnIO1;
        TImageEnProc *ImageEnProc1;
        TImageEnView *ImageEnView1;
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPreview(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPreview *Preview;
//---------------------------------------------------------------------------
#endif
