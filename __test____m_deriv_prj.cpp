//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("__test____m_deriv_prj.res");
USEFORM("__test____m_deriv.cpp", Form1);
USEUNIT("mc_deriv.cpp");
USEUNIT("m_expressions.cpp");
USEUNIT("m_limits.cpp");
USEUNIT("m_integ.cpp");
USEFORM("__test____logs.cpp", Form2);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->CreateForm(__classid(TForm2), &Form2);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
