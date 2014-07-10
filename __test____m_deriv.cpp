#include <vcl.h>
#pragma hdrstop
#include "mc_deriv.h"
#include "m_integ.h"
#include "m_limits.h"
#include "__test____logs.h"
#include "__test____m_deriv.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

// глубина тестирования: количество итераций
#define TESTDEPTH 20000
// вести протоколы? (медленнее)
#define NOTEXT false


const int tLimits=0, tDerivs=1, tInteg=2;
TForm1 *Form1;
int num=0;
bool badAnsw[1000][3];
bool badExpr[1000][3];
bool stoptesting;
int type;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}





bool exprtest (const char *src)
{
    const char subs[][100] = {
        "*0)",
        "(0*",
        "+0)",
        //"(0)",
        "^0)",
        "-0)",
        "/0)",
        "*1)",
        "(1*",
        //"(1)",
        "^1)",
        "/1)",
        "*1+",
        "*(-1)",
        "+(-1)",
        "-(-1)",
        "/(-1)",
        "/-1",
        "^-1",
        "*1-",
        "*1*",
        "*1/",
        "*1^",
        "*1=",
        "=1*",
        "=-1*",
        "+1*",
        "-1*",
        "/1*",
        "*1^",
        "^1+",
        "^1-",
        "^1*",
        "^1/",
        "/1/",
        "()",

        "*(0))",
        "((0)*",
        "+(0))",
        //"(0)",
        "^(0))",
        "-(0))",
        "/(0))",
        "*(1))",
        "((1)*",
        //"(1)",
        "^(1))",
        "/(1))",
        "*(1)+",
        "*(-(1))",
        "+(-(1))",
        "-(-(1))",
        "/(-(1))",
        "/-(1)",
        "^-(1)",
        "*(1)-",
        "*(1)*",
        "*(1)/",
        "*(1)^",
        "*(1)=",
        "=(1)*",
        "+(1)*",
        "-(1)*",
        "/(1)*",
        "*(1)^",
        "^(1)+",
        "^(1)-",
        "^(1)*",
        "^(1)/",
        ""
    };
    unsigned int j;
    int lpar=0, rpar=0;
    for(j=0; j<strlen(src); ++j)
        switch(src[j])
        {
            case '\"':
                {
                    int prevj=j;
                    for(int i=j+1; i<strlen(src); ++i)
                        if (src[i]=='\"') j=i;
                    if (j==prevj) ShowMessage("unterminated string.");
                } break;
            case '(': lpar++; break;
            case ')': rpar++; break;
        }
    if (lpar!=rpar)
    {
        return true;
    }
    for(j=0; j<strlen(src); ++j)
        if (!strchr(">\"`_|abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ1234567890(),. :!=+-*/^&",
                src[j]))
            return true;
    for(j=0; *subs[j]; ++j)
        if (strstr(src, subs[j]))
            return true;
    return false;
}




void addline(char *str)
{
    TMemo *merr = (NOTEXT?NULL:Form2->Memo2);
    TMemo *mtext = (NOTEXT?NULL:Form2->Memo1);
    char text[BUFSZ], text1[10][BUFSZ];
    char answ[10][BUFSZ], answ1[10][10][BUFSZ];
    int nansw=split_text(str, text, answ);
    int i,j;
    bool same=false, exprincorr=false;

    num++;

    {
        /* * * * * * * * * * * * *
         *
         *  Проверка одинаковых ответов
         *
         * * * * * * * * * * * * */
        for(i=0; i<nansw; ++i)
            for(j=0; j<nansw; ++j)
                if (i!=j && strcmp(answ[i],answ[j])==0)
                    same=true;
    }


    {
        /* * * * * * * * * * * * *
         *
         *  Проверка некорректных выражений
         *
         * * * * * * * * * * * * */
        char strs[10][BUFSZ];
        int n=split_str(text,strs);
        for(int z=0; z<n; ++z)
            exprincorr = exprtest(rmvpar(strs[z],strs[z])) || exprincorr;
        for(int q=0; q<nansw; ++q)
        {
            n=split_str(answ[q],strs);
            for(int z=0; z<n; ++z)
                exprincorr = exprincorr || exprtest(rmvpar(strs[z],strs[z]));
        }
    }


    /* * * * * * * * * * * * * * * * *
     *
     *   Регистрация ошибок
     *
     * * * * * * * * * * * * * * * * */
    if (same || exprincorr)
    {
        char buf[BUFSZ];
        if (same)
        {
            badAnsw[num][type]=true;
            if (merr) merr->Lines->Add(chprintf(buf,"№%d: Найдены совпадающие ответы: ",num));
        }
        if (exprincorr)
        {
            badExpr[num][type]=true;
            if (merr) merr->Lines->Add(chprintf(buf,"№%d: Найдены некорректные выражения: ",num));
        }
        char strs[10][BUFSZ];
        int n;
        n=split_str(text,strs);
        if (merr)
        {
            for(int z=0; z<n; ++z)
                merr->Lines->Add(strs[z]);
            for(int q=0; q<nansw; ++q)
            {
                n=split_str(answ[q],strs);
                for(int z=0; z<n; ++z)
                    merr->Lines->Add(rmvpar(strs[z],strs[z]));
            }
            merr->Lines->Add("============================================");
            merr->Lines->Add("");
        }
    }
    
    if (mtext)
        mtext->Lines->Add(str);
}




void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
    srand(100);
    char deriv[10000];
    char integ[10000];
    char text[10000];
    int a,b,c,d,e,a1,b1,c1,a2,b2,c2,a3,b3,c3,p,q,x1,x2,x3,x0,p1,p2,p3,q1,q2,q3,n,k1,k2,k,m,sign;
    int i = 0;
    range r(-5, 5);

    ProgressBar1->Max = TESTDEPTH; ProgressBar1->Min = 0;
    Form2->Memo1->Clear();
    Form2->Memo2->Clear();
    BitBtn1->Enabled = false;
    BitBtn2->Enabled = true;

    for(int i=0; i<3; ++i)
        for(int j=0; j<1000; ++j)
            badAnsw[j][i] = false, badExpr[j][i] = false;

    stoptesting = false;
    do{

        /* * * * * * * * *
         *
         *   Тестируем пределы
         *
         * * * * * * * * */
        num=0, type=tLimits;
        /*
        addline(lim111t (r, text));
        addline(lim112t (r, text));
        addline(lim113t (r, text));
        addline(lim114t (r, text));
        addline(lim115t (r, text));
        addline(lim121t (r, text));
        addline(lim122t (r, text));
        addline(lim123t (r, text));
        addline(lim124t (r, text));
        addline(lim125t (r, text));
        addline(lim126t (r, text));
        addline(lim131t (r, text));
        addline(lim132t (r, text));
        addline(lim141t (r, text));
        addline(lim151t (r, text));
        addline(lim161t (r, text));
        addline(lim211t (r, text));
        addline(lim212t (r, text));
        addline(lim221t (r, text));
        addline(lim231t (r, text));
        addline(lim241t (r, text));
        addline(lim242t (r, text));
        addline(lim243t (r, text));
        addline(lim244t (r, text));
        addline(lim245t (r, text));
        addline(lim251t (r, text));
        addline(lim252t (r, text));
        addline(lim261t (r, text));
        addline(lim262t (r, text));
        addline(lim271t (r, text));
        addline(lim281t (r, text));
        addline(lim291t (r, text));
        addline(lim311t (r, text));
        addline(lim312t (r, text));
        addline(lim313t (r, text));
        addline(lim314t (r, text));
        addline(lim315t (r, text));
        addline(lim316t (r, text));
        addline(lim317t (r, text));
        addline(lim318t (r, text));
        addline(lim319t (r, text));
        addline(lim3110t (r, text));
        addline(lim321t (r, text));
        addline(lim322t (r, text));
        addline(lim323t (r, text));
        addline(lim324t (r, text));
        addline(lim325t (r, text));
        addline(lim326t (r, text));
        addline(lim331t (r, text));
        addline(lim332t (r, text));
        addline(lim333t (r, text));
        addline(lim334t (r, text));
        addline(lim335t (r, text));
        addline(lim336t (r, text));
        addline(lim337t (r, text));
        addline(lim338t (r, text));
        addline(lim341t (r, text));
        addline(lim342t (r, text));
        addline(lim343t (r, text));
        addline(lim344t (r, text));
        addline(lim345t (r, text));
        addline(lim346t (r, text));
        addline(lim347t (r, text));
        addline(lim348t (r, text));
        addline(lim349t (r, text));
        addline(lim3410t (r, text));
        addline(lim411t (r, text));
        addline(lim412t (r, text));
        addline(lim413t (r, text));
        addline(lim414t (r, text));
        addline(lim421t (r, text));
        addline(lim422t (r, text));
        addline(lim423t (r, text));
        addline(lim424t (r, text));
        addline(lim431t (r, text));
        addline(lim432t (r, text));
        addline(lim433t (r, text));
        addline(lim441t (r, text));
        addline(lim442t (r, text));
        addline(lim451t (r, text));
        addline(lim461t (r, text));
        addline(lim462t (r, text));
        addline(lim511t (r, text));
        addline(lim512t (r, text));
        addline(lim513t (r, text));
        addline(lim514t (r, text));
        addline(lim515t (r, text));
        addline(lim516t (r, text));
        addline(lim521t (r, text));
        addline(lim522t (r, text));
        addline(lim523t (r, text));
        addline(lim524t (r, text));
        addline(lim525t (r, text));
        /**/

        /* * * * * * * * *
         *
         *   Тестируем производные
         *
         * * * * * * * * */
        type=tDerivs, num=0;
        addline(deriv101(r,deriv));
        addline(deriv102(r,deriv));
        addline(deriv103(r,deriv));
        addline(deriv104(r,deriv));
        addline(deriv105(r,deriv));
        addline(deriv106(r,deriv));
        addline(deriv107(r,deriv));
        addline(deriv108(r,deriv));
        addline(deriv201(r,deriv));
        addline(deriv202(r,deriv));
        addline(deriv203(r,deriv));
        addline(deriv204(r,deriv));
        addline(deriv205(r,deriv));
        addline(deriv206(r,deriv));
        addline(deriv207(r,deriv));
        addline(deriv208(r,deriv));
        addline(deriv209(r,deriv));
        addline(deriv301(r,deriv));
        addline(deriv302(r,deriv));
        addline(deriv303(r,deriv));
        addline(deriv304(r,deriv));
        addline(deriv305(r,deriv));
        addline(deriv306(r,deriv));
        addline(deriv307(r,deriv));
        addline(deriv308(r,deriv));
        addline(deriv401(r,deriv));
        addline(deriv402(r,deriv));
        addline(deriv403(r,deriv));
        addline(deriv404(r,deriv));
        addline(deriv405(r,deriv));
        addline(deriv406(r,deriv));
        addline(deriv407(r,deriv));
        addline(deriv408(r,deriv));
        addline(deriv501(r,deriv));
        addline(deriv502(r,deriv));
        addline(deriv503(r,deriv));
        addline(deriv504(r,deriv));
        addline(deriv505(r,deriv));
        addline(deriv506(r,deriv));
        addline(deriv507(r,deriv));
        addline(deriv508(r,deriv));
        addline(deriv50101v(r,deriv));
        addline(deriv50102v(r,deriv));
        addline(deriv50103v(r,deriv));
        addline(deriv50104v(r,deriv));
        addline(deriv50105v(r,deriv));
        addline(deriv50201v(r,deriv));
        addline("---");
        /**/
        /*
        //addline(deriv50202v (r,deriv));

        /* * * * * * * * *
         *
         *   Тестируем интегралы
         *
         * * * * * * * * */
        type=tInteg, num=0;
        /*
        addline(integral_ambp01(r,integ));
        addline(integral_ambp02(r,integ));
        addline(integral_ambp03(r,integ));
        addline(integral_ambp04(r,integ));
        //addline(integral_ambp05(r,integ));
        addline(integral_ambp06(r,integ));
        addline(integral_ambp07(r,integ));
        addline(integral_ambp08(r,integ));
        addline(integral_ambp09(r,integ));
        addline(integral_ambp10(r,integ));
        addline(integral_ambp11(r,integ));
        addline(integral_ambp12(r,integ));
        addline(integral_ambp13(r,integ));
        addline(integral_ambp14(r,integ));
        addline(integral_ambp15(r,integ));
        addline(integral_ambp18(r,integ));
        addline(integral_ambp19(r,integ));
        addline(integral_ambp20(r,integ));
        addline(integral_ambp21(r,integ));
        addline(integral_ambp22(r,integ));
        addline(integral_ambp23(r,integ));
        addline(integral_ambp24(r,integ));
        addline(integral_ambp25(r,integ));
        addline(integral_ambp26(r,integ));
        addline(integral_ambp27(r,integ));
        addline(integral_ambp28(r,integ));
        addline(integral_ambp29(r,integ));
        addline(integral_ambp30(r,integ));
        addline(integral_ambp31(r,integ));
        addline(integral_ambp32(r,integ));
        addline(integral_ambp33(r,integ));
        addline(integral_ambp34(r,integ));
        addline(integral_ambp35(r,integ));
        /**/

        i++;


        /* * * * * * * * * * * * * * * * * * *
         *
         *   Вывод промежуточных результатов
         *
         * * * * * * * * * * * * * * * * * * */
        ProgressBar1->Position=i;
        lblIter->Caption=AnsiString("выполнено итераций: ")+i;
        lblIter->Refresh();
        if (i%10==0 || stoptesting)
        {
            ListA1->Clear(); ListA2->Clear(); ListA3->Clear();
            ListE1->Clear(); ListE2->Clear(); ListE3->Clear();
            for(int i=1; i<1000; ++i)
            {
                if (badAnsw[i][0]) ListA1->Items->Add(i);
                if (badAnsw[i][1]) ListA2->Items->Add(i);
                if (badAnsw[i][2]) ListA3->Items->Add(i);
            }
            for(int i=1; i<1000; ++i)
            {
                if (badExpr[i][0]) ListE1->Items->Add(i);
                if (badExpr[i][1]) ListE2->Items->Add(i);
                if (badExpr[i][2]) ListE3->Items->Add(i);
            }
            Form1->Refresh();
            Application->ProcessMessages();
        }

    }while (i<TESTDEPTH && !stoptesting);
    FILE *f = fopen("c:\\menttest.log", "wt");
    for(int i=0; i<Form2->Memo1->Lines->Count; ++i)
        fprintf(f, "%s\n", Form2->Memo1->Lines->Strings[i].c_str());
    fclose(f);
    
    ProgressBar1->Position=0;
    BitBtn1->Enabled=true;
    BitBtn2->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
    Form2->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
    stoptesting=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
    BitBtn2Click(BitBtn2);
    Close();    
}
//---------------------------------------------------------------------------

