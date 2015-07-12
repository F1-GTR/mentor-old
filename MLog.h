//---------------------------------------------------------------------------

#ifndef MLogH
#define MLogH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TLog : public TForm
{
__published:	// IDE-managed Components
        TMemo *Out;
private:	// User declarations
public:		// User declarations
        __fastcall TLog(TComponent* Owner);
        void Add(const char * line);
        void Add(const int type, char * line);
};
//---------------------------------------------------------------------------
extern PACKAGE TLog *Log;
//---------------------------------------------------------------------------
#endif
