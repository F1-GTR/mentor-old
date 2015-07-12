//---------------------------------------------------------------------------

#ifndef MQ32SettingsH
#define MQ32SettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "quest32.h"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------

class TPLAngle : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TGroupBox *GroupBox5;
        TButton *Save;
        TButton *Cancel;
        TTrackBar *MinPoint;
        TTrackBar *MinVector;
        TTrackBar *MinPlate;
        TTrackBar *MaxPoint;
        TTrackBar *MaxVector;
        TTrackBar *MaxPlate;

        TLabel *Point;
        TLabel *Vector;
        TLabel *Plate;
        void __fastcall MinPointChange(TObject *Sender);
        void __fastcall MinVectorChange(TObject *Sender);
        void __fastcall MinPlateChange(TObject *Sender);
        void __fastcall MaxPointChange(TObject *Sender);
        void __fastcall MaxVectorChange(TObject *Sender);
        void __fastcall MaxPlateChange(TObject *Sender);
        void __fastcall SaveClick(TObject *Sender);
        void __fastcall CancelClick(TObject *Sender);
private:	// User declarations
        void drawText();
        void isChangeMax();
        void isChangeMin();
public:		// User declarations
        quest32 * quest;
        __fastcall TPLAngle(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TPLAngle *PLAngle;
//---------------------------------------------------------------------------
#endif
