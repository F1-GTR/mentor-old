#include "m_expressions.h"

void integ201a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b, k;
    do {
        a = rndr(r);
        b = rndr(r);
        k = rndr(r);
    } while (!(a!=0 && k>1));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s*sin(%s))*diff(x)",
        memb(buf[0], 1,1,k-1,1,"x", false),
        poly2ns(buf[1],2, a,1,k,1,"x", b,1,1,1,"")
    );

    chprintf(answ[0], "...=-cos(%s)/(%d)+C", poly2ns(buf[0],2, a,1,k,1,"x", b,1,1,1,""), a*k);
    chprintf(answ[1], "...=cos(%s)/(%d)+C", poly2ns(buf[0],2, a,1,k,1,"x", b,1,1,1,""), a);
    chprintf(answ[2], "...=(%s)*cos(%s)+C", memb(buf[1], 1,a*k,k,1,"x", false), poly2ns(buf[0],2, a,1,k,1,"x", b,1,1,1,""));
    chprintf(answ[3], "...=(%s)*sin(%s)+C", memb(buf[1], a,k,k,1,"x", false), poly2ns(buf[0],2, a,1,k,1,"x", b,1,1,1,""));

    chprintf(src, "Int(x^(k-1)*sin(a*x^k+b))*Diff(x)=-(cos(a*x^k+b)/a*k)+C)");
}



void integ202a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b, k;
    do {
        a = rndr(r);
        b = rndr(r);
        k = rndr(r);
    } while (!(a!=0 && k>1));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s*cos(%s))*diff(x)",
        memb(buf[0], 1,1,k-1,1,"x", false),
        poly2ns(buf[1],2, a,1,k,1,"x", b,1,1,1,"")
    );

    chprintf(answ[0], "...=sin(%s)/(%d)+C", poly2ns(buf[0],2, a,1,k,1,"x", b,1,1,1,""), a*k);
    chprintf(answ[1], "...=-sin(%s)/(%d)+C", poly2ns(buf[0],2, a,1,k,1,"x", b,1,1,1,""), a);
    chprintf(answ[2], "...=(%s)*sin(%s)+C", memb(buf[1],-a,k,k,1,"x", false), poly2ns(buf[0],2, a,1,k,1,"x", b,1,1,1,""));
    chprintf(answ[3], "...=(%s)*cos(%s)+C", memb(buf[1], 1,a,k,1,"x", false), poly2ns(buf[0],2, a,1,k,1,"x", b,1,1,1,""));

    chprintf(src, "Int(x^(k-1)*cos(a*x^k+b))*Diff(x)=-(cos(a*x^k+b)/a*k)+C)");
}



void integ203a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b, k;
    do {
        a = rndr(r);
        b = rndr(r);
        k = rndr(r);
    } while (!(a!=0 && k>1 && b>1));

    char eax[100];
    chprintf(eax, "e^(%s)", polynomial(buf[0],1, a,"x"));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((e^(%s))*cos(%s))*diff(x)",
        polynomial(buf[0],1, a,"x"),
        polynomial(buf[1],2, 1,eax, b,"")
    );

    chprintf(answ[0], "...=-cos(%s)/(%d)+C", polynomial(buf[1],2, 1,eax, b,""), a);
    chprintf(answ[1], "...=cos(%s)/(%d)+C",  polynomial(buf[1],2, 1,eax, b,""), a);
    chprintf(answ[2], "...=-((%s)/(%d))*cos(%s)+C", eax, a, polynomial(buf[1],2, 1,eax, b,""));
    chprintf(answ[3], "...=sin(%s)/(%d)+C", polynomial(buf[1],2, 1,eax, b,""), a);

    chprintf(src, "Int(x^(k-1)*cos(a*x^k+b))*Diff(x)=-(cos(a*x^k+b)/a*k)+C)");
}



void integ204a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b, k;
    do {
        a = rndr(r);
        b = rndr(r);
        k = rndr(r);
    } while (!(a!=0 && k>1 && abs(b)>1));

    char eax[100];
    chprintf(eax, "3^(%s)", polynomial(buf[0],1, a,"x"));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)*cos(%s))*diff(x)", eax, polynomial(buf[1],2, 1,eax, b,""));

    chprintf(answ[0], "...=(1/(%s))*sin(%s)+C",
        polynomial(buf[0],1, a,"ln(3)"),
        polynomial(buf[1],2, 1,eax, b,"")
    );
    chprintf(answ[1], "...=(-(%d/ln(3)))*sin(%s)+C",
        a,
        polynomial(buf[1],2, 1,eax, b,"")
    );
    chprintf(answ[2], "...=(%s)*cos(%s)+sin(%s)/ln(3)+C",
        memb(buf[0], 1,a,1,1,eax, false),
        polynomial(buf[1],2, 1,eax, b,""),
        polynomial(buf[2],2, 1,eax, b,"")
    );
    chprintf(answ[3], "...=(-ln(3)/(%d))*cos(%s)+C",
        a,
        polynomial(buf[1],2, 1,eax, b,"")
    );

    chprintf(src, "Int(x^(k-1)*cos(a*x^k+b))*Diff(x)=-(cos(a*x^k+b)/a*k)+C)");
}



void integ205a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b, p;
    do {
        a = rndr(r);
        b = rndr(r);
        p = rndr(r);
    } while (!(a>1 && abs(b)>1));

    char abx[100], lna[100];
    chprintf(abx, "(%d)^(%s)", a, polynomial(buf[0],1, b,"x"));
    chprintf(lna, "ln(%d)", a);

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)*cos(%s))*diff(x)", abx, polynomial(buf[1],2, 1,abx, p,""));

    chprintf(answ[0], "...=(1/(%s))*sin(%s)+C",
        polynomial(buf[0],1, b,lna),
        polynomial(buf[1],2, 1,abx, p,"")
    );
    chprintf(answ[1], "...=(-%s/(%d))*sin(%s)+C",
        lna, b,
        polynomial(buf[1],2, 1,abx, p,"")
    );
    chprintf(answ[2], "...=(1/%d)*sin(%s)+C",
        -b,
        polynomial(buf[1],2, 1,abx, p,"")
    );
    chprintf(answ[3], "...=(1/(%s))*(%s)*cos(%s)+sin(%s)/(%s)+C",
        polynomial(buf[0],1, b,lna),
        abx,
        polynomial(buf[1],2, 1,abx, p,""),
        polynomial(buf[2],2, 1,abx, p,""),
        lna
    );

    chprintf(src, "Int(x^(k-1)*cos(a*x^k+b))*Diff(x)=-(cos(a*x^k+b)/a*k)+C)");
}



void integ206a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b, k;
    do {
        a = rndr(r);
        b = rndr(r);
        k = rndr(r);
    } while (!(a>1 && b!=0 && k>1));

    char abx[100], lna[100], axkb[1000];
    chprintf(abx, "(%d)^(%s)", a, polynomial(buf[0],1, b,"x"));
    chprintf(lna, "ln(%d)", a);
    chprintf(axkb, "%s", poly2ns(buf[1],2, a,1,k,1,"x", b,1,1,1,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/cos(%s)^2)*diff(x)",
        memb(buf[0], 1,1,k-1,1,"x", false),
        axkb
    );

    chprintf(answ[0], "...=(1/(%d))*tg(%s)+C",
        a*k,
        axkb
    );
    chprintf(answ[1], "...=(1/(%d))*tg(%s)+C",
        k,
        axkb
    );
    chprintf(answ[2], "...=(%s)*ctg(%s)+C",
        fraction(buf[0],a,1,k),
        axkb
    );
    chprintf(answ[3], "...=(-1/(%d))*(1/cos(%s))+C",
        a*k,
        axkb
    );

    chprintf(src, "Int(x^(k-1)*cos(a*x^k+b))*Diff(x)=-(cos(a*x^k+b)/a*k)+C)");
}


void integ207a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b, p;
    do {
        a = rndr(r);
        b = rndr(r);
        p = rndr(r);
    } while (!(a>1 && abs(b)>1));

    char abxp[1000];
    polynomial(abxp,2,
        1,chprintf(buf[0],"(%d)^(%s)", a, polynomial(buf[1],1,b,"x")),
        p,""
    );

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(((%d)^(%s))/cos(%s)^2)*diff(x)=...",
        a,
        polynomial(buf[0],1,b,"x"),
        abxp
    );

    chprintf(answ[0], "...=(1/(%d*ln(%d)))*tg(%s)+C", b,a,abxp);
    chprintf(answ[1], "...=(1/(%d))*tg(%s)+C", b,abxp);
    chprintf(answ[2], "...=(ln(%d)/(%d))*tg((%d)^(%s))+C", a,b, a,polynomial(buf[0],1,b,"x"));
    chprintf(answ[3], "...=(-1/(%d*ln(%d)))*(1/cos(%s))+C", b,a,abxp);

    chprintf(src, "Int(a^(b*x)/cos(a^b*x+p)^2)*diff(x)");
}

void integ208a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b, p;
    do {
        a = rndr(r);
        b = rndr(r);
        p = rndr(r);
    } while (!(a>1 && abs(b)>1));

    char lnbxp[1000];
    polynomial(lnbxp,2,
        1,chprintf(buf[0], "ln(%s)", polynomial(buf[1],1,b,"x")),
        p,""
    );

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(diff(x)/(x*cos(%s)^2))=...", lnbxp);

    chprintf(answ[0], "...=tg(%s)+C", lnbxp);
    chprintf(answ[1], "...=(1/%d)*tg(%s)+C", b,lnbxp);
    chprintf(answ[2], "...=(-1/(%d*cos(%s)))+C", b,lnbxp);
    chprintf(answ[3], "...=%d*tg(%s)+C", -b,lnbxp);

    chprintf(src, "Int(diff(x)/(x*cos(ln(bx)+p)^2))");
}

void integ209a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b, k;
    do {
        a = rndr(r);
        b = rndr(r);
        k = rndr(r);
    } while (!(a!=0 && abs(b)>1 && k>0 && k>1));

    char axkb[1000];
    poly2ns(axkb,2, a,1,k,1,"x", b,1,1,1,"");

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/sin(%s)^2)*diff(x)=...", memb(buf[0], 1,1,k-1,1,"x", false), axkb);

    chprintf(answ[0], "...=%s",
        poly2ns(buf[0],2,
            -1,a*k,1,1, chprintf(buf[1], "ctg(%s)", axkb),
            1,1,1,1, "C"
        )
    );
    chprintf(answ[1], "...=-(x^%d/%d)*ctg(%s)+C", k,k, axkb);
    chprintf(answ[2], "...=%s",
        poly2ns(buf[0],2,
            a,k,1,1, chprintf(buf[1], "ctg(%s)", axkb),
            1,1,1,1, "C"
        )
    );
    chprintf(answ[3], "...=%s",
        poly2ns(buf[0],2,
            -1,a*k,1,1, chprintf(buf[1], "1/sin(%s)", axkb),
            1,1,1,1, "C"
        )
    );

    chprintf(src, "Int(x^(k-1)/sin(a*x^k+b)^2)*diff(x)");
}


void integ210a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int b, p;
    do {
        b = rndr(r);
        p = rndr(r);
    } while (!(abs(b)>1));

    char ebx[1000];
    sprintf(ebx, "e^(%s)", polynomial(buf[0],1,b,"x"));
    char ebxp[1000];
    polynomial(ebxp,2,
        1,chprintf(buf[0],"e^(%s)", polynomial(buf[1],1,b,"x")),
        p,""
    );

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/sin(%s)^2)*diff(x)=...", ebx, ebxp);

    chprintf(answ[0], "...=(-1/%d)*ctg(%s)+C", b,ebxp);
    chprintf(answ[1], "...=(1/%d)*ctg(%s)+C", b,ebxp);
    chprintf(answ[2], "...=(1/%d)*(1/sin(%s))+C", b,ebxp);
    chprintf(answ[3], "...=(-1/%d)*((%s)/sin(%s))+C", b,ebx,ebxp);

    chprintf(src, "Int((e^(b*x))/sin(e^(b*x)+p)^2)*diff(x)");
}

void integ211a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int b, p;
    do {
        b = rndr(r);
        p = rndr(r);
    } while (!(b>1));

    char lnbxp[1000];
    polynomial(lnbxp,2,
        1,chprintf(buf[0], "ln(!(%s))", polynomial(buf[1],1,b,"x")),
        p,""
    );

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(diff(x)/(x*sin(%s)^2))=...", lnbxp);

    chprintf(answ[0], "...=-ctg(%s)+C", lnbxp);
    chprintf(answ[1], "...=(-1/%d)*tg(%s)+C", b,lnbxp);
    chprintf(answ[2], "...=(1/%d)*(ln(%d*x)/sin(%s))+C", b,b,lnbxp);
    chprintf(answ[3], "...=(1/%d)*tg(%s)+C", b,lnbxp);

    chprintf(src, "Int(diff(x)/(x*sin(ln(bx)+p)^2))");
}

void integ212a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b;
    do {
        a = rndr(r);
        b = rndr(r);
    } while (!(a>1 && abs(b)>1 && b!=a));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(diff(x)/((%s)*x))=...", polynomial(buf[0],2, a*a,"", 1,chprintf(buf[1],"ln(%s)^2",polynomial(buf[2],1,b,"x"))));

    chprintf(answ[0], "...=(1/%d)*arctg(ln(%d*x)/%d)+C", a, b,a);
    chprintf(answ[1], "...=(1/%d)*(%s)+C", b, polynomial(buf[0],2, a*a,"", 1,chprintf(buf[1],"ln(%s)^2",polynomial(buf[2],1,b,"x"))));
    chprintf(answ[2], "...=(1/%d)*ln(%s)+C", b, polynomial(buf[0],1,b,"x"));
    chprintf(answ[3], "...=ln(%s)/(%s)+C", polynomial(buf[0],1,b,"x"), polynomial(buf[1],2, a,"", 1,chprintf(buf[2],"ln(%s)", polynomial(buf[3],1,b,"x"))));

    chprintf(src, "Int(diff(x)/(x*(a^2+ln(b*x)^2)))");
}

void integ213a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b;
    do {
        a = rndr(r);
        b = rndr(r);
    } while (!(a!=0 && abs(a)!=1 && abs(b)>1 && b!=a));

    char ebx[1000];
    chprintf(ebx, "e^(%s)", polynomial(buf[0],1, b,"x"));
    char a2e2bx[1000];
    polynomial(a2e2bx,2, a*a,"", 1,chprintf(buf[1],"e^(%s)",polynomial(buf[2],1,2*b,"x")));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(((%s)*diff(x))/(%s))=...", ebx, a2e2bx);

    chprintf(answ[0], "...=(1/%d)*arctg((%s)/%d)+C", b*a, ebx, a);
    chprintf(answ[1], "...=(1/%d)*arctg((%s)/%d)+C", b, ebx, a);
    chprintf(answ[2], "...=(1/%d)*ln(%s)+C", b, a2e2bx);
    chprintf(answ[3], "...=(%s)/(%s)+C", ebx, polynomial(buf[0],2, b*a*a,"", b,chprintf(buf[1],"e^(%s)",polynomial(buf[2],1,2*b,"x"))));

    chprintf(src, "Int((e^(b*x)*diff(x))/(a^2+e^(2*b*x)))");
}

void integ214a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b;
    do {
        a = rndr(r);
        b = rndr(r);
    } while (!(abs(a)!=1 && a!=0 && abs(b)>1));

    char bx[1000];
    polynomial(bx,1, b,"x");
    char a2cos2bx[1000];
    polynomial(a2cos2bx,2, a*a,"", 1,chprintf(buf[1],"cos(%s)^2",polynomial(buf[2],1,b,"x")));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((sin(%s)*diff(x))/(%s))=...", bx, a2cos2bx);

    chprintf(answ[0], "...=(-1/%d)*arctg(cos(%s)/%d)+C", b*a, bx, a);
    chprintf(answ[1], "...=(-1/%d)*arctg(cos(%s)/%d)+C", b, bx, a);
    chprintf(answ[2], "...=(1/%d)*arctg(cos(%s))+C", a, bx);
    chprintf(answ[3], "...=(1/%d)*ln(%s)+C", b, a2cos2bx);

    chprintf(src, "Int((e^(b*x)*diff(x))/(a^2+e^(2*b*x)))");
}

void integ215a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b, k;
    do {
        a = rndr(r);
        b = rndr(r);
        k = rndr(r);
    } while (!(abs(a)!=1 && a!=0 && k>1));

    char xk1[1000];
    memb(xk1, 1,1,k-1,1,"x", false);
    char a2x2k[1000];
    poly2ns(a2x2k,2, a*a,1,1,1,"", 1,1,2*k,1,"x");

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/(%s))*diff(x)=...", xk1, a2x2k);

    chprintf(answ[0], "...=(1/%d)*arctg((x^(%d))/%d)+C", a, k,a);
    chprintf(answ[1], "...=(1/%d)*arctg(x^(%d))+C", a, k);
    chprintf(answ[2], "...=ln(%s)+C", a2x2k);
    chprintf(answ[3], "...=arctg(x^(%d)/%d)+C", 2*k, a);

    chprintf(src, "Int((e^(b*x)*diff(x))/(a^2+e^(2*b*x)))");
}

void integ216a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b;
    do {
        a = rndr(r);
        b = rndr(r);
    } while (!(abs(a)>1 && abs(b)>1));

    char a2mln2bx[1000];
    polynomial(a2mln2bx,2, a*a,"", -1,chprintf(buf[0],"ln(%s)^2",polynomial(buf[1],1,b,"x")));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(diff(x)/(x*sqrt(%s)))=...", a2mln2bx);

    chprintf(answ[0], "...=arcsin(ln(%d*x)/%d)+C", b,a);
    chprintf(answ[1], "...=(1/%d)*arcsin(ln(%d*x)/%d)+C", a, b, a);
    chprintf(answ[2], "...=(1/%d)*arccos(ln(%d*x)/%d)+C", a*b,b,a);
    chprintf(answ[3], "...=(1/%d)*arcsin(ln(%d*x)/%d)+C", -a*b, b,a);

    chprintf(src, "Int((e^(b*x)*diff(x))/(a^2+e^(2*b*x)))");
}

void integ217a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b;
    do {
        a = rndr(r);
        b = rndr(r);
    } while (!(abs(a)>1 && abs(b)>1));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(cos(%d*x)/sqrt(%d-sin(%d*x)^2))*diff(x)=...", b, a*a, b);

    chprintf(answ[0], "...=(1/%d)*arcsin(sin(%d*x)/%d)+C", b,b,a);
    chprintf(answ[1], "...=(1/%d)*arcsin(sin(%d*x)/%d)+C", a*b, b, a);
    chprintf(answ[2], "...=(1/%d)*arccos(sin(%d*x)/%d)+C", b,b,a);
    chprintf(answ[3], "...=(1/%d)*arccos(sin(%s))+C", a*b, memb(buf[0], b,a,1,1,"x", false));

    chprintf(src, "Int((e^(b*x)*diff(x))/(a^2+e^(2*b*x)))");
}

void integ218a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b;
    do {
        a = rndr(r);
        b = rndr(r);
    } while (!(abs(a)>1 && abs(b)>1));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(diff(x)/(cos(%d*x)^2*sqrt(%d-tg(%d*x)^2)))=...", b, a*a, b);

    chprintf(answ[0], "...=(1/%d)*arcsin(tg(%d*x)/%d)+C", b,b,a);
    chprintf(answ[1], "...=(1/%d)*arcsin(tg(%d*x)/%d)+C", a*b, b, a);
    chprintf(answ[2], "...=(1/%d)*arccos(tg(%d*x)/%d)+C", a,b,a);
    chprintf(answ[3], "...=(1/%d)*arcsin(tg(%s))+C", b, memb(buf[0], b,a,1,1,"x", false));

    chprintf(src, "Int((e^(b*x)*diff(x))/(a^2+e^(2*b*x)))");
}


