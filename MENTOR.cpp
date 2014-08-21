//---------------------------------------------------------------------------
#include <vcl.h>
//#pragma hdrstop
//USERES("mentor.res");
USEFORM("headwin.cpp", hwin);
USEUNIT("utilm.cpp");
USEUNIT("fglobal.cpp");
USEUNIT("tkurs.cpp");
USEUNIT("tquest.cpp");
USEUNIT("BMENTOR.CPP");
USEUNIT("quest1.cpp");
USEFORM("matlin.cpp", pmatlin);
USEFORM("dtask.cpp", ptask);
USEFORM("qvarnt.cpp", qvar);
USEFORM("nqselect.cpp", pnqselect);
USEUNIT("quest2.cpp");
USEFORM("matumn.cpp", pmatumn);
USEUNIT("quest3.cpp");
USEFORM("mateigv.cpp", pmateigv);
USEUNIT("quest4.cpp");
USEFORM("matopr.cpp", Matdet);
USEUNIT("quest5.cpp");
USEFORM("gauss.cpp", LinSistem);
USEFORM("integral.cpp", OprInt);
USEUNIT("quest6.cpp");
USEFORM("odsistem.cpp", NullSystem);
USEUNIT("quest7.cpp");
USEFORM("scale.cpp", ScalMul);
USEUNIT("quest8.cpp");
USEFORM("MPreview.cpp", Preview);
USEUNIT("ExprDraw.pas");
USEUNIT("ExprMake.pas");
USEUNIT("quest9.cpp");
USEFORM("MVectorMul.cpp", VectorMul);
USEFORM("MNormal.cpp", Normal);
USEUNIT("quest10.cpp");
USEFORM("MLine.cpp", Line);
USEUNIT("quest11.cpp");
USEFORM("MAngle.cpp", Angle);
USEUNIT("quest12.cpp");
USEFORM("MPlane.cpp", Plane);
USEUNIT("quest13.cpp");
USEFORM("MElips.cpp", Elips);
USEUNIT("quest14.cpp");
USEFORM("MGiper.cpp", Giper);
USEUNIT("quest15.cpp");
USEFORM("MParab.cpp", Parab);
USEUNIT("quest16.cpp");
USEFORM("MSmMul.cpp", SmMul);
USEUNIT("quest17.cpp");
USEFORM("MDl.cpp", PRLine);
USEUNIT("quest18.cpp");
USEFORM("MPdl.cpp", PlaneLine);
USEUNIT("quest19.cpp");
USEFORM("MPreview2.cpp", Preview2);
USEFORM("integral2.cpp", NeoInt);
USEUNIT("quest20.cpp");
USEFORM("MRang.cpp", Rang);
USEUNIT("quest21.cpp");
USEFORM("MAbout.cpp", About);
USEFORM("MLinDet.cpp", LinDet);
USEUNIT("quest22.cpp");
USEUNIT("quest23.cpp");
USEFORM("MKramer.cpp", Kramer);
USEFORM("MShow1.cpp", MShow);
USEFORM("MKRVar.cpp", KRVar);
USEFORM("MPreview3.cpp", Preview3);
USEFORM("MGenKey.cpp", GenKey);
USEFORM("MObrMatr.cpp", ObrMatr);
USEUNIT("quest24.cpp");
USEFORM("MEditWork.cpp", EditWork);
USEFORM("MPr.cpp", Pr);
USEUNIT("quest25.cpp");
USEFORM("MLinePlane.cpp", LinePlane);
USEUNIT("quest26.cpp");
USEFORM("MComp.cpp", CompLine);
USEUNIT("quest27.cpp");
USEFORM("MLinePrizm.cpp", LinePrizm);
USEUNIT("quest28.cpp");
USEFORM("MLineCmp.cpp", LineCmp);
USEUNIT("quest29.cpp");
USEUNIT("MConvert.cpp");
USEFORM("MRenameKonW.cpp", RenameKonW);
USEFORM("MMentorConfig.cpp", MentorConfig);
USEFORM("MGenHtml.cpp", GenHtml);
USEFORM("MFtpMod.cpp", FtpMod);
USEFORM("MVarCmp.cpp", CompareVar);
USEUNIT("det.cpp");
USEFORM("MPrint.cpp", PrintKW);
USEUNIT("drobi.cpp");
USEUNIT("determ.cpp");
USEUNIT("quest31.cpp");
USEUNIT("quest32.cpp");
USEUNIT("queEigens.cpp");
USEUNIT("MATRGEN.CPP");
USEFORM("MEigen.cpp", Eigen);
USEUNIT("quelim01.cpp");
USEFORM("MLim01.cpp", Lim01);
USEFORM("MTRconvene.cpp", FMTRconv);
USEUNIT("m_limits.cpp");
USE("m_limits.h", File);
USEUNIT("queDeriv.cpp");
USEUNIT("mc_deriv.cpp");
USEFORM("MDeriv.cpp", FDeriv);
USEUNIT("queMFlabs.cpp");
USEUNIT("m_mflab.cpp");
USEUNIT("m_expressions.cpp");
USEFORM("TMFlabs.cpp", FMFlabs);
USEUNIT("queInteg.cpp");
USEFORM("MInteg.cpp", FInteg);
USEUNIT("m_integ.cpp");
USEUNIT("queLimRnd.cpp");
USEFORM("LimRnd.cpp", FLimRnd);
USEUNIT("m_deriv_01.cpp");
USEUNIT("m_integ2.cpp");
USEUNIT("quederivrnd.cpp");
USEFORM("MDerivRnd.cpp", DerivRnd);
USEUNIT("m_integ_a01.cpp");
USEUNIT("m_deriv_02.cpp");
USEUNIT("queIntegRnd.cpp");
USEFORM("MIntegRnd.cpp", IntegRnd);
USEUNIT("m_integ_a02.cpp");
USEFORM("Unit1.cpp", Log);
USEFORM("Unit2.cpp", PLAngle);
USEFORM("MScanDialog.cpp", MScan);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR lpCmdLine, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "������ - ��������� ������� � ���������� �������";
                 Application->HelpFile = "C:\\Igor\\Program\\MENTOR\\MENTOR.HLP";
                 Application->CreateForm(__classid(Thwin), &hwin);
                 Application->CreateForm(__classid(Tpmatlin), &pmatlin);
                 Application->CreateForm(__classid(Tptask), &ptask);
                 Application->CreateForm(__classid(Tqvar), &qvar);
                 Application->CreateForm(__classid(Tpnqselect), &pnqselect);
                 Application->CreateForm(__classid(Tpmatumn), &pmatumn);
                 Application->CreateForm(__classid(Tpmateigv), &pmateigv);
                 Application->CreateForm(__classid(TMatdet), &Matdet);
                 Application->CreateForm(__classid(TLinSistem), &LinSistem);
                 Application->CreateForm(__classid(TOprInt), &OprInt);
                 Application->CreateForm(__classid(TNullSystem), &NullSystem);
                 Application->CreateForm(__classid(TScalMul), &ScalMul);
                 Application->CreateForm(__classid(TPreview), &Preview);
                 Application->CreateForm(__classid(TVectorMul), &VectorMul);
                 Application->CreateForm(__classid(TNormal), &Normal);
                 Application->CreateForm(__classid(TLine), &Line);
                 Application->CreateForm(__classid(TAngle), &Angle);
                 Application->CreateForm(__classid(TPlane), &Plane);
                 Application->CreateForm(__classid(TElips), &Elips);
                 Application->CreateForm(__classid(TGiper), &Giper);
                 Application->CreateForm(__classid(TParab), &Parab);
                 Application->CreateForm(__classid(TSmMul), &SmMul);
                 Application->CreateForm(__classid(TPRLine), &PRLine);
                 Application->CreateForm(__classid(TPlaneLine), &PlaneLine);
                 Application->CreateForm(__classid(TPreview2), &Preview2);
                 Application->CreateForm(__classid(TNeoInt), &NeoInt);
                 Application->CreateForm(__classid(TRang), &Rang);
                 Application->CreateForm(__classid(TAbout), &About);
                 Application->CreateForm(__classid(TLinDet), &LinDet);
                 Application->CreateForm(__classid(TKramer), &Kramer);
                 Application->CreateForm(__classid(TMShow), &MShow);
                 Application->CreateForm(__classid(TKRVar), &KRVar);
                 Application->CreateForm(__classid(TPreview3), &Preview3);
                 Application->CreateForm(__classid(TGenKey), &GenKey);
                 Application->CreateForm(__classid(TObrMatr), &ObrMatr);
                 Application->CreateForm(__classid(TEditWork), &EditWork);
                 Application->CreateForm(__classid(TPr), &Pr);
                 Application->CreateForm(__classid(TLinePlane), &LinePlane);
                 Application->CreateForm(__classid(TCompLine), &CompLine);
                 Application->CreateForm(__classid(TLinePrizm), &LinePrizm);
                 Application->CreateForm(__classid(TLineCmp), &LineCmp);
                 Application->CreateForm(__classid(TRenameKonW), &RenameKonW);
                 Application->CreateForm(__classid(TMentorConfig), &MentorConfig);
                 Application->CreateForm(__classid(TGenHtml), &GenHtml);
                 Application->CreateForm(__classid(TFtpMod), &FtpMod);
                 Application->CreateForm(__classid(TCompareVar), &CompareVar);
                 Application->CreateForm(__classid(TPrintKW), &PrintKW);
                 Application->CreateForm(__classid(TEigen), &Eigen);
                 Application->CreateForm(__classid(TLim01), &Lim01);
                 Application->CreateForm(__classid(TFMTRconv), &FMTRconv);
                 Application->CreateForm(__classid(TFDeriv), &FDeriv);
                 Application->CreateForm(__classid(TFMFlabs), &FMFlabs);
                 Application->CreateForm(__classid(TFInteg), &FInteg);
                 Application->CreateForm(__classid(TFLimRnd), &FLimRnd);
                 Application->CreateForm(__classid(TDerivRnd), &DerivRnd);
                 Application->CreateForm(__classid(TIntegRnd), &IntegRnd);
                 Application->CreateForm(__classid(TLog), &Log);
                 Application->CreateForm(__classid(TPLAngle), &PLAngle);
                 Application->CreateForm(__classid(TMScan), &MScan);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
