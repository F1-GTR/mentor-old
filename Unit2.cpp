//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPLAngle *PLAngle;
//---------------------------------------------------------------------------


__fastcall TPLAngle::TPLAngle(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

//если значения в треках поменялись - пересчёт всех значений
//несколько нерационально, но при таких мелких размерах можно пересчитать и все 6 треков

void TPLAngle::isChangeMin()
{
     if (MaxPoint->Position < MinPoint->Position)
     {
          MaxPoint->Position = MinPoint->Position;
     }
     if (MaxVector->Position < MinVector->Position)
     {
          MaxVector->Position = MinVector->Position;
     }
     if (MaxPlate->Position < MinPlate->Position)
     {
          MaxPlate->Position = MinPlate->Position;
     }
      drawText();

}

void TPLAngle::isChangeMax()
{
     if (MaxPoint->Position < MinPoint->Position)
     {
           MinPoint->Position = MaxPoint->Position;
     }
     if (MaxVector->Position < MinVector->Position)
     {
           MinVector->Position = MaxVector->Position;
     }
     if (MaxPlate->Position < MinPlate->Position)
     {
           MinPlate->Position = MaxPlate->Position;
     }

     drawText();
}

void TPLAngle::drawText()
{
        char buf[5];
        char tmp[255];
        //point
        strcpy(tmp,itoa(MinPoint->Position,buf,10));
        strcat(tmp," < x0,y0,z0 < ");
        strcat(tmp,itoa(MaxPoint->Position,buf,10));
        Point->Caption=strdup(tmp);
         //vector
        strcpy(tmp,itoa(MinVector->Position,buf,10));
        strcat(tmp," < l,m,n < ");
        strcat(tmp,itoa(MaxVector->Position,buf,10));
        Vector->Caption=strdup(tmp);
         //plate
        strcpy(tmp,itoa(MinPlate->Position,buf,10));
        strcat(tmp," < A,B,C,D < ");
        strcat(tmp,itoa(MaxPlate->Position,buf,10));
        Plate->Caption=strdup(tmp);
}


void __fastcall TPLAngle::MinPointChange(TObject *Sender)
{
        isChangeMin();
}
//---------------------------------------------------------------------------

void __fastcall TPLAngle::MinVectorChange(TObject *Sender)
{
        isChangeMin();        
}
//---------------------------------------------------------------------------

void __fastcall TPLAngle::MinPlateChange(TObject *Sender)
{
        isChangeMin();        
}
//---------------------------------------------------------------------------

void __fastcall TPLAngle::MaxPointChange(TObject *Sender)
{
        isChangeMax();        
}
//---------------------------------------------------------------------------

void __fastcall TPLAngle::MaxVectorChange(TObject *Sender)
{
         isChangeMax();        
}
//---------------------------------------------------------------------------

void __fastcall TPLAngle::MaxPlateChange(TObject *Sender)
{
         isChangeMax();
}
//---------------------------------------------------------------------------


void __fastcall TPLAngle::SaveClick(TObject *Sender)
{
  quest->min.point = MinPoint->Position;
  quest->min.vector= MinVector->Position;
  quest->min.plate = MinPlate->Position;
  quest->max.point = MaxPoint->Position;
  quest->max.vector= MaxVector->Position;
  quest->max.plate = MaxPlate->Position;
  //
  sprintf(quest->strpar1,"%d %d %d %d %d %d",quest->min.point,quest->max.point,quest->min.vector,quest->max.vector,quest->min.plate,quest->max.plate);
  sprintf(quest->strpar2,"%d %d %d %d %d %d",quest->min.point,quest->max.point,quest->min.vector,quest->max.vector,quest->min.plate,quest->max.plate);
  //
  this->Close(); 
}
//---------------------------------------------------------------------------

void __fastcall TPLAngle::CancelClick(TObject *Sender)
{
        this->Close();        
}
//---------------------------------------------------------------------------

