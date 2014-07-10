//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("__develop_prj.res");
USEFORM("__develop_frm.cpp", Form1);
USEUNIT("mc_deriv.cpp");
USEUNIT("m_expressions.cpp");
USEUNIT("m_mflab.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
