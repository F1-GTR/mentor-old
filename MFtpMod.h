//---------------------------------------------------------------------------

#ifndef MFtpModH
#define MFtpModH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <NMFtp.hpp>
#include <Psock.hpp>
//---------------------------------------------------------------------------
class TFtpMod : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TNMFTP *NMFTP1;
        TListBox *ListBox1;
        TListBox *ListBox2;
        TLabel *Label1;
        TLabel *Label2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ListBox2DblClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFtpMod(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFtpMod *FtpMod;
//---------------------------------------------------------------------------
#endif
