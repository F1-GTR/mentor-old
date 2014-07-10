//---------------------------------------------------------------------
#include <vcl.h>
#include "MMentorConfig.h"
#pragma hdrstop
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TMentorConfig *MentorConfig;
//---------------------------------------------------------------------
__fastcall TMentorConfig::TMentorConfig(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TMentorConfig::FormCreate(TObject *Sender)
{
        TStringList * List = new TStringList;

        if ( FileExists( "Mentor.cfg" ) )
        {
                List->LoadFromFile( "Mentor.cfg" );
                ComboBox1->ItemIndex = StrToInt ( List->Strings[0] );
                Edit4->Text = List->Strings[1];
        }
        else
        {
                ComboBox1->ItemIndex = 0;
        }

        delete List;
}
//---------------------------------------------------------------------------

void __fastcall TMentorConfig::OKBtnClick(TObject *Sender)
{
        TStringList * List = new TStringList;

        List->Add( IntToStr( ComboBox1->ItemIndex ) );
        List->Add( Edit4->Text );
        List->SaveToFile( "Mentor.cfg" );

        MentorConfig->Close();
        
        delete List;
}
//---------------------------------------------------------------------------

void __fastcall TMentorConfig::CancelBtnClick(TObject *Sender)
{
        MentorConfig->Close();        
}
//---------------------------------------------------------------------------


