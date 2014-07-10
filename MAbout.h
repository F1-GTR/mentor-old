//----------------------------------------------------------------------------
#ifndef MAboutH
#define MAboutH
//----------------------------------------------------------------------------
#include <vcl.h>
//----------------------------------------------------------------------------
class TAbout : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TMemo *Memo1;
private:
public:
	virtual __fastcall TAbout(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TAbout *About;
//----------------------------------------------------------------------------
#endif    
