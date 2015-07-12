//---------------------------------------------------------------------------

#include <vcl.h>
#include "global.h"
#include <stdio.h>
#pragma hdrstop

#include <time.h>

#include "MLog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLog *Log;
//---------------------------------------------------------------------------
__fastcall TLog::TLog(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//Add text to log
void TLog::Add(const char * line)
{
        //Get Time
        TDateTime DateTime = TDateTime::CurrentDateTime();

        //Strings
        char Dline[255];
        char Dtime[255];

        //Generating output line
        strcpy(Dtime,DateTime.DateString().c_str());
        strcat(Dtime," ");
        strcat(Dtime,DateTime.TimeString().c_str());
        //
        strcpy(Dline,"[INFO] ["); //message type
        strcat(Dline,Dtime);
        strcat(Dline,"] - ");
        strcat(Dline,line);
        strcat(Dline,"\n");
        //adding to memo
        this->Out->Lines->Append(Dline);

        //append to logfile
        if (LOG_WRITE)
        {
                this->Out->Lines->Append("Trying to save\n");
                char filename[255] = "";
                //strcpy(filename,wpath);
                strcat(filename,DateTime.DateString().c_str());
                strcat(filename,".log");
                FILE * logFile = fopen(filename,"a");
                if (logFile  != NULL)
                {
                        fprintf(logFile,"%s",Dline);
                        fclose(logFile);
                }
                else
                {

                }
        }
}
