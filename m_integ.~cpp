#include "m_integ.h"

void integ101b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b;
    do{
        a = rndr(r);
        b = rndr(r);
    } while (!(a>0 && b>0 && a!=-1 && a!=1));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s)*Diff(x)=...", memb(buf[1],1,1,-2,1,polynomial(buf[0],2,a,"x",b,""),false));
    sprintf(src, "Int(1/(a*x+b)^2)*Diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[2],-1,a,-1,1,polynomial(buf[0],2,a,"x",b,""),false));
    sprintf(answ[1], "...=%s", memb(buf[2],1,a,-1,1,polynomial(buf[0],2,a,"x",b,""),false));
    sprintf(answ[2], "...=%s", memb(buf[2],-1,1,-1,1,polynomial(buf[0],2,a,"x",b,""),false));
    sprintf(answ[3], "...=%s", memb(buf[2],a,1,-1,1,polynomial(buf[0],2,a,"x",b,""),false));
}

void integ102b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b;
    do {
        a = rndr(r);
        b = rndr(r);
    } while (!(a>0 && b>0 && a!=1 && a!=-1));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s)*Diff(x)=...", memb(buf[1],1,1,-1,1,polynomial(buf[0],2,a,"x",b,""),false));
    sprintf(src, "Int(1/(a*x+b))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[2],1,a,1,1,chprintf(buf[3],"ln(%s)", polynomial(buf[0],2,a,"x",b,"")),false));
    sprintf(answ[1], "...=%s", memb(buf[2],a,1,1,1,chprintf(buf[3],"ln(%s)", polynomial(buf[0],2,a,"x",b,"")),false));
    sprintf(answ[2], "...=%s", memb(buf[2],a,1,-1,1,chprintf(buf[3],"ln(%s)", polynomial(buf[0],2,a,"x",b,"")),false));
    sprintf(answ[3], "...=%s", memb(buf[2],1,a,-1,1,chprintf(buf[3],"ln(%s)", polynomial(buf[0],2,a,"x",b,"")),false));
}

void integ103b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b;
    do {
        a = rndr(r);
        b = rndr(r);
    } while (!(a>0 && b>0 && a!=1 && a!=-1));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s)*Diff(x)=...", memb(buf[1],1,1,-1,2,polynomial(buf[0],2,a,"x",b,""),false));

    sprintf(src, "Int(1/sqrt(a*x+b))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[2],2,a,1,2,polynomial(buf[0],2,a,"x",b,""),false));
    sprintf(answ[1], "...=%s", memb(buf[2],1,2*a,1,2,polynomial(buf[0],2,a,"x",b,""),false));
    sprintf(answ[2], "...=%s", memb(buf[2],2*a,1,1,2,polynomial(buf[0],2,a,"x",b,""),false));
    sprintf(answ[3], "...=%s", memb(buf[2],2,a,-1,2,polynomial(buf[0],2,a,"x",b,""),false));
}

void integ104b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b, n;
    do {
        a = rndr(r);
        b = rndr(r);
        n = rndr(r);
    } while (!(a>0 && b>0 && n!=0 && n!=1 && n!=-1 && a!=1 && a!=-1 && abs(n+1)!=abs(a) && abs(n+1)!=1));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s)*Diff(x)=...", memb(buf[1],1,1,n,1,polynomial(buf[0],2,a,"x",b,""),false));

    sprintf(src, "int((a*x+b)^n)*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[2],1,a*(n+1),n+1,1,chprintf(buf[4],"(%s)", polynomial(buf[0],2,a,"x",b,"")),false));
    sprintf(answ[1], "...=%s", memb(buf[2],a,(n+1),n+1,1,chprintf(buf[4],"(%s)", polynomial(buf[0],2,a,"x",b,"")),false));
    sprintf(answ[2], "...=%s", memb(buf[2],(n+1),a,n+1,1,chprintf(buf[4],"(%s)", polynomial(buf[0],2,a,"x",b,"")),false));
    sprintf(answ[3], "...=%s", memb(buf[2],a*(n+1),1,n+1,1,chprintf(buf[4],"(%s)", polynomial(buf[0],2,a,"x",b,"")),false));
}

/*
char *integral_ambp05 (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(integ,"");
    int a,b,p,q;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
        q=rndr(r);
    }while(!(a>0 && b>0 && q!=0 && p%q!=0));
    catprintf(task, "\nInt(%s)*Diff(x)=(%s)/(%s)",
        memb(buf[0], 1,1,p,q, polynomial(buf[9],2,a,"x",b,""),false),
        polynomial(buf[1], 3, 1,memb(buf[6],1,1,p,q,polynomial(buf[7],2,a,"x",b,""),false), -a,"x", -b,""),
        memb(buf[2], a*(n-1),1,p,q, polynomial(buf[3],2,a,"x",b,""), false)
    );
    return integ;
}
*/

void integ106b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b;
    do {
        a = rndr(r);
        b = rndr(r);
    } while (!(a>0 && b>0 && b!=1 && a!=1));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(e^(%s))*Diff(x)=...", polynomial(buf[0],2,a,"x",b,""));

    sprintf(src, "int(e^(a*x+b))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[1], 1,a,1,1, chprintf(buf[7],"e^(%s)", polynomial(buf[1],2,a,"x",b,"")),false));
    sprintf(answ[1], "...=%s", memb(buf[1], a,1,1,1, chprintf(buf[7],"e^(%s)", polynomial(buf[1],2,a,"x",b,"")),false));
    sprintf(answ[2], "...=%s", memb(buf[1], a,1,-1,1, chprintf(buf[7],"e^(%s)", polynomial(buf[1],2,a,"x",b,"")),false));
    sprintf(answ[3], "...=%s", memb(buf[1], a*b,1,1,1, chprintf(buf[7],"e^(%s)", polynomial(buf[1],2,a,"x",b,"")),false));
}

void integ107b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a>0 && b>0 && abs(a)!=1));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(sin(%s))*Diff(x)=...", polynomial(buf[0],2,a,"x",b,""));

    sprintf(src, "int(sin(a*x+b))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[1],-1,a,1,1,chprintf(buf[3],"cos(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[1], "...=%s", memb(buf[1],a,1,1,1,chprintf(buf[3],"cos(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[2], "...=%s", memb(buf[1],-a,1,1,1,chprintf(buf[3],"cos(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[3], "...=%s", memb(buf[1],1,a,1,1,chprintf(buf[3],"cos(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
}

void integ108b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a>0 && b>0 && abs(a)!=1));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(cos(%s))*Diff(x)=...", polynomial(buf[0],2,a,"x",b,""));

    sprintf(src, "int(cos(a*x+b))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[1],1,a,1,1,chprintf(buf[3],"sin(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[1], "...=%s", memb(buf[1],a,1,1,1,chprintf(buf[3],"sin(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[2], "...=%s", memb(buf[1],-a,1,1,1,chprintf(buf[3],"sin(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[3], "...=%s", memb(buf[1],1,-a,1,1,chprintf(buf[3],"sin(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
}

void integ109b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a>0 && b>0 && abs(a)!=1));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(1/(cos(%s)^2))*Diff(x)=...", polynomial(buf[0],2,a,"x",b,""));

    sprintf(src, "int(cos(a*x+b)^2)*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[1],1,a,1,1,chprintf(buf[3],"tg(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[1], "...=%s", memb(buf[1],-1,a,1,1,chprintf(buf[3],"tg(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[2], "...=%s", memb(buf[1],a,1,1,1,chprintf(buf[3],"tg(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[3], "...=%s", memb(buf[1],-a,1,1,1,chprintf(buf[3],"tg(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
}

void integ110b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a>0 && b>0 && a!=b && abs(a)!=1));
    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(1/(sin(%s)^2))*Diff(x)=...", polynomial(buf[0],2,a,"x",b,""));

    sprintf(src, "int(1/sin(a*x+b)^2)*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[1],-1,a,1,1,chprintf(buf[3],"ctg(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[1], "...=%s", memb(buf[1],1,a,1,1,chprintf(buf[3],"ctg(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[2], "...=%s", memb(buf[1],a,1,1,1,chprintf(buf[3],"ctg(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
    sprintf(answ[3], "...=%s", memb(buf[1],-a,1,1,1,chprintf(buf[3],"ctg(%s)",polynomial(buf[7],2,a,"x",b,"")),false));
}

void integ111b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a>0 && b>0 && a!=b && b!=1 && abs(a)!=1));
    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(1/(%s))*Diff(x)=...", poly2ns(buf[0],2, a,1,1,1,"", b,1,2,1,"x"));

    sprintf(src, "int(1/(a+b*x^2))*diff(x)");

    sprintf(answ[0], "...=arctg((%s)*x)/(%s)",
        fraction(buf[1],1,a*b,a),
        fraction(buf[2],1,a*b,1)
    );
    sprintf(answ[1], "...=(%s)*arctg((%s)*x)/(%s)",
        fraction(buf[3],1,a,1),
        fraction(buf[1],1,a*b,a),
        fraction(buf[2],1,b,1)
    );
    sprintf(answ[2], "...=(%s)*arctg((%s)*x)/(%s)",
        fraction(buf[3],1,b,1),
        fraction(buf[1],1,a*b,a),
        fraction(buf[2],1,a,1)
    );
    sprintf(answ[3], "...=(%s)*arctg((%s)*x)",
        fraction(buf[3],1,a*b,1),
        fraction(buf[1],1,a*b,a)
    );
}

void integ112b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a>0 && b>0 && abs(b)!=1 && a!=b && abs(a)!=1));
    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(1/(%s))*Diff(x)=...", poly2ns(buf[0],2, a,1,1,1,"", -b,1,2,1,"x"));

    sprintf(src, "int(1/(a-b*x^2))*diff(x)");

    sprintf(answ[0], "...=-ln(((%s)*x-(%s))/((%s)*x+(%s)))/(%s)",
        fraction(buf[1],1,b,1), fraction(buf[2],1,a,1),
        fraction(buf[3],1,b,1), fraction(buf[4],1,a,1),
        fraction(buf[9],2,a*b,1)
    );
    sprintf(answ[1], "...=ln(((%s)*x-(%s))/((%s)*x+(%s)))/(%s)",
        fraction(buf[1],1,b,1), fraction(buf[2],1,a,1),
        fraction(buf[3],1,b,1), fraction(buf[4],1,a,1),
        fraction(buf[9],2,a*b,1)
    );
    sprintf(answ[2], "...=ln(((%s)*x-(%s))/((%s)*x+(%s)))*(%s)",
        fraction(buf[1],1,b,1), fraction(buf[2],1,a,1),
        fraction(buf[3],1,b,1), fraction(buf[4],1,a,1),
        fraction(buf[9],2,a*b,1)
    );
    sprintf(answ[3], "...=ln(((%s)*x-(%s))/((%s)*x+(%s)))*(%s)",
        fraction(buf[1],1,b,1), fraction(buf[2],1,a,1),
        fraction(buf[3],1,b,1), fraction(buf[4],1,a,1),
        fraction(buf[9],2,a*b,b)
    );
}

void integ113b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; 
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a>0 && b>0 && a!=b && abs(a)!=1 && abs(b)!=1));
    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(1/(%s))*Diff(x)=...", poly2ns(buf[0],2, -a,1,1,1,"", b,1,2,1,"x"));

    sprintf(src, "int(1/(-a+b*x^2))*diff(x)");

    sprintf(answ[0], "...=ln(((%s)*x-(%s))/((%s)*x+(%s)))/(%s)",
        fraction(buf[1],1,b,1), fraction(buf[2],1,a,1),
        fraction(buf[3],1,b,1), fraction(buf[4],1,a,1),
        fraction(buf[9],2,a*b,1)
    );
    sprintf(answ[1], "...=-ln(((%s)*x-(%s))/((%s)*x+(%s)))/(%s)",
        fraction(buf[1],1,b,1), fraction(buf[2],1,a,1),
        fraction(buf[3],1,b,1), fraction(buf[4],1,a,1),
        fraction(buf[9],2,a*b,1)
    );
    sprintf(answ[2], "...=-ln(((%s)*x-(%s))/((%s)*x+(%s)))*(%s)",
        fraction(buf[1],1,b,1), fraction(buf[2],1,a,1),
        fraction(buf[3],1,b,1), fraction(buf[4],1,a,1),
        fraction(buf[9],2,a*b,1)
    );
    sprintf(answ[3], "...=-ln(((%s)*x-(%s))/((%s)*x+(%s)))*(%s)",
        fraction(buf[1],1,b,1), fraction(buf[2],1,a,1),
        fraction(buf[3],1,b,1), fraction(buf[4],1,a,1),
        fraction(buf[9],2,a*b,b)
    );
}

void integ114b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a>0 && b>0 && a!=b && abs(a)!=1 && abs(b)!=1));
    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(1/(%s))*Diff(x)=...", poly2ns(buf[0],2, -a,1,1,1,"", -b,1,2,1,"x"));

    sprintf(src, "int(1/(-a-b*x^2))*diff(x)");

    sprintf(answ[0], "...=-arctg((%s)*x)/(%s)",
        fraction(buf[1],1,a*b,a),
        fraction(buf[2],1,a*b,1)
    );
    sprintf(answ[1], "...=arctg((%s)*x)/(%s)",
        fraction(buf[1],1,a*b,a),
        fraction(buf[2],1,a*b,1)
    );
    sprintf(answ[2], "...=arctg((%s)*x)*(%s)",
        fraction(buf[1],1,a*b,a),
        fraction(buf[2],1,a*b,1)
    );
    sprintf(answ[3], "...=arctg((%s)*x)/(%s)",
        fraction(buf[1],1,a*b,a),
        fraction(buf[2],1,a*b,b)
    );
}

void integ115b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a>0 && b>1 && a!=b && abs(a)!=1 && abs(b)!=1));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(1/sqrt(%s))*Diff(x)=...", poly2ns(buf[0],2, a,1,1,1,"", b,1,2,1,"x"));

    sprintf(src, "int(1/sqrt(a+b*x^2))*diff(x)");

    sprintf(answ[0], "...=ln(sqrt(%s)+(%s)*x)/(%s)",
        poly2ns(buf[1],2, b,1,2,1,"x", a,1,1,1,""),
        fraction(buf[2],1,b,1),
        fraction(buf[9],1,b,1)
    );
    sprintf(answ[1], "...=ln(sqrt(%s)+(%s)*x)*(%s)",
        poly2ns(buf[1],2, b,1,2,1,"x", a,1,1,1,""),
        fraction(buf[2],1,b,1),
        fraction(buf[9],1,b,1)
    );
    sprintf(answ[2], "...=ln(sqrt(%s)+(%s)*x)*(%s)",
        poly2ns(buf[1],2, b,1,2,1,"x", a,1,1,1,""),
        fraction(buf[2],1,b,1),
        fraction(buf[9],2,a*b,a*b)
    );
    sprintf(answ[3], "...=ln(sqrt(%s)+(%s)*x)/(%s)",
        poly2ns(buf[1],2, b,1,2,1,"x", a,1,1,1,""),
        fraction(buf[2],1,b,1),
        fraction(buf[9],2,a*b,1)
    );
}

/*
void integ116b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a>0 && b>1));
    catprintf(task, "\nInt(1/sqrt(%s))*Diff(x)=ln(sqrt(%s)+(%s)*x)/(%s)",
        poly2ns(buf[0],2, -a,1,1,1,"", b,1,2,1,"x"),
        poly2ns(buf[1],2, b,1,2,1,"x", -a,1,1,1,""),
        fraction(buf[2],1,b,1),
        fraction(buf[9],1,b,1)
    );
    return integ;
}

void integ117b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a>0 && b>1));
    catprintf(task, "\nInt(1/sqrt(%s))*Diff(x)=arctg((%s)*x/sqrt(%s))/(%s)",
        poly2ns(buf[0],2, -a,1,1,1,"", -b,1,2,1,"x"),
        fraction(buf[2],1,b,1),
        poly2ns(buf[1],2, -b,1,2,1,"x", -a,1,1,1,""),
        fraction(buf[9],1,b,1)
    );
    return integ;
}
*/

void integ118b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,l,p,q;
    do{
        a=rndr(r);
        b=rndr(r);
        l=rndr(r);
        p=rndr(r);
        q=rndr(r);
    }while (!(a!=0 && b!=0 && q!=-p && q!=0 && p!=0 && p+q!=0 && l+1!=0
        && abs(l+1)!=1
        && abs(a*(p+q))!=abs(a*q)
        && abs(q)!=abs(p+q)
        && abs(q)!=1
    ));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s)*Diff(x)=...", poly2ns(buf[1],2, a,1,p,q,"x", b,1,l,1,"x"));

    sprintf(src, "int(a*x^(p/q)+b*x)*diff(x)");

    sprintf(answ[0], "...=%s", poly2ns(buf[3],2, a*q,p+q,p+q,q,"x", b,l+1,l+1,1,"x"));
    sprintf(answ[1], "...=%s", poly2ns(buf[3],2, a*(p+q),q,p+q,q,"x", b,l+1,l+1,1,"x"));
    sprintf(answ[2], "...=%s", poly2ns(buf[3],2, a*q,p+q,p+q,q,"x", b*(l+1),1,l+1,1,"x"));
    sprintf(answ[3], "...=%s", poly2ns(buf[3],2, a,q*(p+q),p+q,q,"x", b*(l+1),1,l+1,1,"x"));
}

void integ119b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,k,l;
    do{
        a=rndr(r);
        b=rndr(r);
        k=rndr(r);
        l=rndr(r);
    }while (!(a!=0 && l>0 && k!=0 && k+l!=0
        && abs(a)!=abs(l*(k+l))
        && abs(a)!=abs(a*(k+l))
        && abs(l)!=abs(a)
        && abs(k+l)!=1
        && abs(l)!=abs(a*(k+l))
    ));

    strcpy(task,"");
    sprintf(src, "int(1/(ln(a*x+b)^(-k)*(a*x+b)))*diff(x)");
    catprintf(task, "String(\"Найдите интеграл:\")");
    if (k*l<0)
    {
        catprintf(task, "\nInt(1/((%s)*(%s)))*Diff(x)=...",
            memb(buf[1], 1,1,-k,l, chprintf(buf[3], "ln(%s)", polynomial(buf[0],2,a,"x",b,"")), false),
            polynomial(buf[9],2, a,"x",b,"")
        );

        sprintf(answ[0], "...=%s", memb(buf[2], l,a*(k+l),k+l,l, chprintf(buf[4],"ln(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
        sprintf(answ[1], "...=%s", memb(buf[2], a,l*(k+l),k+l,l, chprintf(buf[4],"ln(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
        sprintf(answ[2], "...=%s", memb(buf[2], l*(k+l),a,k+l,l, chprintf(buf[4],"ln(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
        sprintf(answ[3], "...=%s", memb(buf[2], a*(k+l),l,k+l,l, chprintf(buf[4],"ln(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    }
    else
    {
        catprintf(task, "\nInt((%s)/(%s))*Diff(x)=...",
            memb(buf[1], 1,1,k,l, chprintf(buf[3], "ln(%s)", polynomial(buf[0],2,a,"x",b,"")), false),
            polynomial(buf[9],2, a,"x",b,"")
        );

        sprintf(answ[0], "...=%s", memb(buf[2], l,a*(k+l),k+l,l, chprintf(buf[4],"ln(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
        sprintf(answ[1], "...=%s", memb(buf[2], a,l*(k+l),k+l,l, chprintf(buf[4],"ln(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
        sprintf(answ[2], "...=%s", memb(buf[2], l*(k+l),a,k+l,l, chprintf(buf[4],"ln(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
        sprintf(answ[3], "...=%s", memb(buf[2], a*(k+l),l,k+l,l, chprintf(buf[4],"ln(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    }
}

void integ120b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a, b;
    do {
        a = rndr(r);
        b = rndr(r);
    } while (!(a!=0 && abs(a)!=1 && abs(a)!=2));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(x*e^(%s))*Diff(x)=...", poly2ns(buf[1],2, a,1,2,1,"x", b,1,1,1,""));

    sprintf(src, "int(x*e^(a*x^2+b))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[2], 1,2*a,1,1, chprintf(buf[3],"e^(%s)", poly2ns(buf[1],2, a,1,2,1,"x", b,1,1,1,"")), false));
    sprintf(answ[1], "...=%s", memb(buf[2], 2*a,1,1,1, chprintf(buf[3],"e^(%s)", poly2ns(buf[1],2, a,1,2,1,"x", b,1,1,1,"")), false));
    sprintf(answ[2], "...=%s", memb(buf[2], 2,a,1,1, chprintf(buf[3],"e^(%s)", poly2ns(buf[1],2, a,1,2,1,"x", b,1,1,1,"")), false));
    sprintf(answ[3], "...=%s", memb(buf[2], a,2,1,1, chprintf(buf[3],"e^(%s)", poly2ns(buf[1],2, a,1,2,1,"x", b,1,1,1,"")), false));
}

void integ121b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[12][BUFSZ];
    int a,b,p,q;
    do{
        a=rndr(r);
        b=rndr(r);
        q=rndr(r);
        p=rndr(r);
    }while(!(a!=0 && q!=-p && q!=0 && p!=0
        && strcmp(fraction(buf[0],q,1,a*(p+q)), fraction(buf[1],p+q,1,a*q))
        && strcmp(fraction(buf[2],q,1,a*(p+q)), fraction(buf[3],a*q,1,p+q))
        && strcmp(fraction(buf[4],q,1,a*(p+q)), fraction(buf[5],a*(p+q),1,q))

        && strcmp(fraction(buf[6],a*q,1,p+q), fraction(buf[7],p+q,1,a*q))
        && strcmp(fraction(buf[8],a*q,1,p+q), fraction(buf[9],a*(p+q),1,q))

        && strcmp(fraction(buf[10],p+q,1,a*q), fraction(buf[11],a*(p+q),1,q))
    ));

    strcpy(task, "");
    catprintf(task, "Найдите интеграл:");
    catprintf(task, "\nInt((%s)*sin(%s))*Diff(x)=...",
        memb(buf[1], 1,1,p,q, chprintf(buf[2],"cos(%s)",polynomial(buf[0],2,a,"x",b,"")), false),
        polynomial(buf[0],2,a,"x",b,"")
    );

    sprintf(src, "int(cos(a*x+b)^(p/q)*sin(a*x+b))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[3], -q,a*(p+q),p+q,q, chprintf(buf[5], "cos(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[1], "...=%s", memb(buf[3], -a*q,(p+q),p+q,q, chprintf(buf[5], "cos(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[2], "...=%s", memb(buf[3], -(p+q),a*q,p+q,q, chprintf(buf[5], "cos(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[3], "...=%s", memb(buf[3], -a*(p+q),q,p+q,q, chprintf(buf[5], "cos(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
}

void integ122b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a,b,p,q;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
        q=rndr(r);
    }while(!(a!=0 && q!=-p && q!=0 && p!=0
        && strcmp(fraction(buf[0],q,1,a*(p+q)), fraction(buf[1],p+q,1,a*q))
        && strcmp(fraction(buf[2],q,1,a*(p+q)), fraction(buf[3],a*q,1,p+q))
        && strcmp(fraction(buf[4],q,1,a*(p+q)), fraction(buf[5],a*(p+q),1,q))

        && strcmp(fraction(buf[6],a*q,1,p+q), fraction(buf[7],p+q,1,a*q))
        && strcmp(fraction(buf[8],a*q,1,p+q), fraction(buf[9],a*(p+q),1,q))

        && strcmp(fraction(buf[10],p+q,1,a*q), fraction(buf[11],a*(p+q),1,q))
    ));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)*cos(%s))*Diff(x)=...",
        memb(buf[1], 1,1,p,q, chprintf(buf[2],"sin(%s)",polynomial(buf[0],2,a,"x",b,"")), false),
        polynomial(buf[0],2,a,"x",b,"")
    );

    sprintf(src, "int(sin(a*x+b)^(p/q)*cos(a*x+b))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[3], q,a*(p+q),p+q,q, chprintf(buf[5], "sin(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[1], "...=%s", memb(buf[3], a*q,(p+q),p+q,q, chprintf(buf[5], "sin(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[2], "...=%s", memb(buf[3], (p+q),a*q,p+q,q, chprintf(buf[5], "sin(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[3], "...=%s", memb(buf[3], a*(p+q),q,p+q,q, chprintf(buf[5], "sin(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
}

void integ123b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ]; 
    int a,b,p,q;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
        q=rndr(r);
    }while(!(a!=0 && q!=-p && q!=0 && p!=0
        && strcmp(fraction(buf[0],q,1,a*(p+q)), fraction(buf[1],p+q,1,a*q))
        && strcmp(fraction(buf[2],q,1,a*(p+q)), fraction(buf[3],a*q,1,p+q))
        && strcmp(fraction(buf[4],q,1,a*(p+q)), fraction(buf[5],a*(p+q),1,q))

        && strcmp(fraction(buf[6],a*q,1,p+q), fraction(buf[7],p+q,1,a*q))
        && strcmp(fraction(buf[8],a*q,1,p+q), fraction(buf[9],a*(p+q),1,q))

        && strcmp(fraction(buf[10],p+q,1,a*q), fraction(buf[11],a*(p+q),1,q))
    ));
    
    strcpy(task,"");
    catprintf(task, "Найдите интеграл:");
    catprintf(task, "\nInt(%s/cos(%s)^2)*Diff(x)=...",
        depar(rmvpar(memb(buf[1], 1,1,p,q, chprintf(buf[2],"tg(%s)",polynomial(buf[0],2,a,"x",b,"")), false),buf[1])),
        polynomial(buf[0],2,a,"x",b,"")
    );

    sprintf(src, "int(tg(a*x+b)^(p/q)/cos(a*x+b))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[3], q,a*(p+q),p+q,q, chprintf(buf[5], "tg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[1], "...=%s", memb(buf[3], a*q,(p+q),p+q,q, chprintf(buf[5], "tg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[2], "...=%s", memb(buf[3], p+q,a*q,p+q,q, chprintf(buf[5], "tg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[3], "...=%s", memb(buf[3], a*(p+q),q,p+q,q, chprintf(buf[5], "tg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
}

void integ124b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a,b,p,q;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
        q=rndr(r);
    }while(!(a!=0 && q!=-p && q!=0 && p!=0
        && strcmp(fraction(buf[0],q,1,a*(p+q)), fraction(buf[1],p+q,1,a*q))
        && strcmp(fraction(buf[2],q,1,a*(p+q)), fraction(buf[3],a*q,1,p+q))
        && strcmp(fraction(buf[4],q,1,a*(p+q)), fraction(buf[5],a*(p+q),1,q))

        && strcmp(fraction(buf[6],a*q,1,p+q), fraction(buf[7],p+q,1,a*q))
        && strcmp(fraction(buf[8],a*q,1,p+q), fraction(buf[9],a*(p+q),1,q))

        && strcmp(fraction(buf[10],p+q,1,a*q), fraction(buf[11],a*(p+q),1,q))
    ));
    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s/sin(%s)^2)*Diff(x)=...",
        depar(rmvpar(buf[1],memb(buf[1], 1,1,p,q, chprintf(buf[2],"ctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false))),
        polynomial(buf[0],2,a,"x",b,"")
    );

    sprintf(src, "int(ctg(a*x+b)^(p/q)/sin(a*x+b))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[3], -q,a*(p+q),p+q,q, chprintf(buf[5], "ctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[1], "...=%s", memb(buf[3], -a*q,(p+q),p+q,q, chprintf(buf[5], "ctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[2], "...=%s", memb(buf[3], -(p+q),a*q,p+q,q, chprintf(buf[5], "ctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[3], "...=%s", memb(buf[3], -a*(p+q),q,p+q,q, chprintf(buf[5], "ctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
}

void integ125b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ]; 
    int a,b,p,q;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
        q=rndr(r);
    }while(!(a!=0 && q!=-p && q!=0 && p!=0
        && strcmp(fraction(buf[0],q,1,a*(p+q)), fraction(buf[1],p+q,1,a*q))
        && strcmp(fraction(buf[2],q,1,a*(p+q)), fraction(buf[3],a*q,1,p+q))
        && strcmp(fraction(buf[4],q,1,a*(p+q)), fraction(buf[5],a*(p+q),1,q))

        && strcmp(fraction(buf[6],a*q,1,p+q), fraction(buf[7],p+q,1,a*q))
        && strcmp(fraction(buf[8],a*q,1,p+q), fraction(buf[9],a*(p+q),1,q))

        && strcmp(fraction(buf[10],p+q,1,a*q), fraction(buf[11],a*(p+q),1,q))
    ));
    
    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s/sqrt(1-(%s)^2))*Diff(x)=...",
        depar(rmvpar(buf[1],memb(buf[1], 1,1,p,q, chprintf(buf[2],"arcsin(%s)",polynomial(buf[0],2,a,"x",b,"")), false))),
        polynomial(buf[0],2,a,"x",b,"")
    );

    sprintf(src, "int(arcsin(a*x+b)^(p/q)/sqrt(1-(a*x+b)^2))*diff(x)");

    sprintf(answ[0], "...=%s",  memb(buf[3], q,a*(p+q),p+q,q, chprintf(buf[5], "arcsin(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[1], "...=%s", memb(buf[3], a*q,(p+q),p+q,q, chprintf(buf[5], "arcsin(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[2], "...=%s", memb(buf[3], p+q,a*q,p+q,q, chprintf(buf[5], "arcsin(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[3], "...=%s", memb(buf[3], a*(p+q),q,p+q,q, chprintf(buf[5], "arcsin(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
}

void integ126b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ]; 
    int a,b,p,q;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
        q=rndr(r);
    }while(!(a!=0 && q!=-p && q!=0 && p!=0
        && strcmp(fraction(buf[0],q,1,a*(p+q)), fraction(buf[1],p+q,1,a*q))
        && strcmp(fraction(buf[2],q,1,a*(p+q)), fraction(buf[3],a*q,1,p+q))
        && strcmp(fraction(buf[4],q,1,a*(p+q)), fraction(buf[5],a*(p+q),1,q))

        && strcmp(fraction(buf[6],a*q,1,p+q), fraction(buf[7],p+q,1,a*q))
        && strcmp(fraction(buf[8],a*q,1,p+q), fraction(buf[9],a*(p+q),1,q))

        && strcmp(fraction(buf[10],p+q,1,a*q), fraction(buf[11],a*(p+q),1,q))
    ));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s/sqrt(1-(%s)^2))*Diff(x)=...",
        depar(rmvpar(buf[1],memb(buf[1], 1,1,p,q, chprintf(buf[2],"arccos(%s)",polynomial(buf[0],2,a,"x",b,"")), false))),
        polynomial(buf[0],2,a,"x",b,"")
    );

    sprintf(src, "int(arccos(a*x+b)^(p/q)/sqrt(1-(a*x+b)^2))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[3], -q,a*(p+q),p+q,q, chprintf(buf[5], "arccos(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[1], "...=%s", memb(buf[3], -a*q,(p+q),p+q,q, chprintf(buf[5], "arccos(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[2], "...=%s", memb(buf[3], -(p+q),a*q,p+q,q, chprintf(buf[5], "arccos(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[3], "...=%s", memb(buf[3], -a*(p+q),q,p+q,q, chprintf(buf[5], "arccos(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
}

void integ127b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ]; 
    int a,b,p,q;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
        q=rndr(r);
    }while(!(a!=0 && q!=-p && q!=0 && p!=0
        && strcmp(fraction(buf[0],q,1,a*(p+q)), fraction(buf[1],p+q,1,a*q))
        && strcmp(fraction(buf[2],q,1,a*(p+q)), fraction(buf[3],a*q,1,p+q))
        && strcmp(fraction(buf[4],q,1,a*(p+q)), fraction(buf[5],a*(p+q),1,q))

        && strcmp(fraction(buf[6],a*q,1,p+q), fraction(buf[7],p+q,1,a*q))
        && strcmp(fraction(buf[8],a*q,1,p+q), fraction(buf[9],a*(p+q),1,q))

        && strcmp(fraction(buf[10],p+q,1,a*q), fraction(buf[11],a*(p+q),1,q))
    ));
    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s/(1+(%s)^2))*Diff(x)=...",
        depar(rmvpar(buf[1],memb(buf[1], 1,1,p,q, chprintf(buf[2],"arctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false))),
        polynomial(buf[0],2,a,"x",b,"")
    );

    sprintf(src, "int(arctg(a*x+b)^(p/q)/(1+(a*x+b)^2))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[3], q,a*(p+q),p+q,q, chprintf(buf[5], "arctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[1], "...=%s", memb(buf[3], a*q,(p+q),p+q,q, chprintf(buf[5], "arctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[2], "...=%s", memb(buf[3], p+q,a*q,p+q,q, chprintf(buf[5], "arctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[3], "...=%s", memb(buf[3], a*(p+q),q,p+q,q, chprintf(buf[5], "arctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
}

void integ128b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a,b,p,q;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
        q=rndr(r);
    }while(!(a!=0 && q!=-p && q!=0 && p!=0
        && strcmp(fraction(buf[0],q,1,a*(p+q)), fraction(buf[1],p+q,1,a*q))
        && strcmp(fraction(buf[2],q,1,a*(p+q)), fraction(buf[3],a*q,1,p+q))
        && strcmp(fraction(buf[4],q,1,a*(p+q)), fraction(buf[5],a*(p+q),1,q))

        && strcmp(fraction(buf[6],a*q,1,p+q), fraction(buf[7],p+q,1,a*q))
        && strcmp(fraction(buf[8],a*q,1,p+q), fraction(buf[9],a*(p+q),1,q))

        && strcmp(fraction(buf[10],p+q,1,a*q), fraction(buf[11],a*(p+q),1,q))
    ));
    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(%s/(1+(%s)^2))*Diff(x)=...",
        depar(rmvpar(buf[1],memb(buf[1], 1,1,p,q, chprintf(buf[2],"arcctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false))),
        polynomial(buf[0],2,a,"x",b,"")
    );

    sprintf(src, "int(arcctg(a*x+b)^(p/q)/(1+(a*x+b)^2))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[3], -q,a*(p+q),p+q,q, chprintf(buf[5], "arcctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[1], "...=%s", memb(buf[3], -a*q,(p+q),p+q,q, chprintf(buf[5], "arcctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[2], "...=%s", memb(buf[3], -(p+q),a*q,p+q,q, chprintf(buf[5], "arcctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
    sprintf(answ[3], "...=%s", memb(buf[3], -a*(p+q),q,p+q,q, chprintf(buf[5], "arcctg(%s)",polynomial(buf[0],2,a,"x",b,"")), false));
}


void integ129b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while(!(a*b!=0 && d>0 && c>0 && abs(a)!=1 && abs(c)!=1));
    polynomial(buf[0],2, a,"x",b,"");
    polynomial(buf[1],2, c*c,"x^2",d*d,"");
    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/(%s))*Diff(x)=...",
        buf[0],
        buf[1]
    );

    sprintf(src, "int((a*x+b)/(c^2*x^2+d^2))*diff(x)");

    sprintf(answ[0], "...=%s%s",
        memb(buf[3],a,2*c*c,1,1,chprintf(buf[4],"ln(%s)",buf[1]),false),
        memb(buf[5],b,c*d,1,1,chprintf(buf[6],"arctg(%s)", memb(buf[7],c,d,1,1,"x",false)),true)
    );
    sprintf(answ[1], "...=%s%s",
        memb(buf[3],2*a,c*c,1,1,chprintf(buf[4],"ln(%s)",buf[1]),false),
        memb(buf[5],b,c*d,1,1,chprintf(buf[6],"arctg(%s)", memb(buf[7],c,d,1,1,"x",false)),true)
    );
    sprintf(answ[2], "...=%s%s",
        memb(buf[3],2*a*c*c,1,1,1,chprintf(buf[4],"ln(%s)",buf[1]),false),
        memb(buf[5],b,c*d,1,1,chprintf(buf[6],"arctg(%s)", memb(buf[7],c,d,1,1,"x",false)),true)
    );
    sprintf(answ[3], "...=%s%s",
        memb(buf[3],2*a*c*c,1,1,1,chprintf(buf[4],"ln(%s)",buf[1]),false),
        memb(buf[5],b*c,d,1,1,chprintf(buf[6],"arctg(%s)", memb(buf[7],c,d,1,1,"x",false)),true)
    );
}

void integ130b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while(!(c>0 && c!=1 && a!=0 && b!=0 && abs(c)!=1 && abs(c)!=1));
    poly2ns(buf[1],2, c*c,1,2,1,"x", d*d,1,1,1,"");

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/sqrt(%s))*Diff(x)=...",
        polynomial(buf[0],2,a,"x",b,""),
        buf[1]
    );

    sprintf(src, "int((a*x+b)/sqrt(c^2*x^2+d^2))*diff(x)");

    sprintf(answ[0], "...=%s%s",
        memb(buf[2],a,c*c,1,2,buf[1],false),
        memb(buf[3],b,c,1,1,chprintf(buf[5],"ln(|%s|)",polynomial(buf[6],2,c,"x",1,chprintf(buf[9],"sqrt(%s)", buf[1]))),true)
    );
    sprintf(answ[1], "...=%s%s",
        memb(buf[2],a*c*c,1,1,2,buf[1],false),
        memb(buf[3],b,c,1,1,chprintf(buf[5],"ln(|%s|)",polynomial(buf[6],2,c,"x",1,chprintf(buf[9],"sqrt(%s)", buf[1]))),true)
    );
    sprintf(answ[2], "...=%s%s",
        memb(buf[2],a*c*c,1,1,2,buf[1],false),
        memb(buf[3],b*c,1,1,1,chprintf(buf[5],"ln(|%s|)",polynomial(buf[6],2,c,"x",1,chprintf(buf[9],"sqrt(%s)", buf[1]))),true)
    );
    sprintf(answ[3], "...=%s%s",
        memb(buf[2],a,c*c,1,2,buf[1],false),
        memb(buf[3],b*c,1,1,1,chprintf(buf[5],"ln(|%s|)",polynomial(buf[6],2,c,"x",1,chprintf(buf[9],"sqrt(%s)", buf[1]))),true)
    );
}

void integ131b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; 
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while(!(c!=0 && a!=0 && b!=0 && c>0 && d>0 && abs(c)!=1 && c!=d));
    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/sqrt(%s))*Diff(x)=...",
        polynomial(buf[0],2,a,"x",b,""),
        poly2ns(buf[1],2, d,1,1,1,"", -c*c,1,2,1,"x")
    );

    sprintf(src, "int((a*x+b)/sqrt(d-c^2*x^2))*diff(x)");

    sprintf(answ[0], "...=%s",
        poly2ns(buf[2],2,
            -a,c*c,1,2,polynomial(buf[6],2,d,"",-c*c,"x^2"),
            b,c,1,1,chprintf(buf[7], "arcsin((%s)*x)", fraction(buf[8],1,c*d,d))
        )
    );
    sprintf(answ[1], "...=%s",
        poly2ns(buf[2],2,
            -a*c*c,1,1,2,polynomial(buf[6],2,d,"",-c*c,"x^2"),
            b,c,1,1,chprintf(buf[7], "arcsin((%s)*x)", fraction(buf[8],1,c*d,d))
        )
    );
    sprintf(answ[2], "...=%s",
        poly2ns(buf[2],2,
            a*c*c,1,1,2,polynomial(buf[6],2,d,"",-c*c,"x^2"),
            b*c,1,1,1,chprintf(buf[7], "arcsin((%s)*x)", fraction(buf[8],1,c*d,d))
        )
    );
    sprintf(answ[3], "...=%s",
        poly2ns(buf[2],2,
            -a*c*c,1,1,2,polynomial(buf[6],2,d,"",-c*c,"x^2"),
            -b*c,1,1,1,chprintf(buf[7], "arcsin((%s)*x)", fraction(buf[8],1,c*d,d))
        )
    );
}

void integ132b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; 
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while(!(a!=0 && d!=0 && abs(d)!=1));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(sin(%s)/(%s))*Diff(x)=...",
        polynomial(buf[0],2,a,"x",b,""),
        polynomial(buf[1],2,c,"",d,chprintf(buf[7],"cos(%s)",polynomial(buf[0],2,a,"x",b,"")))
    );

    sprintf(src, "int(sin(a*x+b)/(c+d*cos(a*x+b)))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[8], -1,a*d,1,1, chprintf(buf[9],"ln(%s)", polynomial(buf[1],2,c,"",d,chprintf(buf[7],"cos(%s)",polynomial(buf[0],2,a,"x",b,"")))),false));
    sprintf(answ[1], "...=%s", memb(buf[8], a,d,1,1, chprintf(buf[9],"ln(%s)", polynomial(buf[1],2,c,"",d,chprintf(buf[7],"cos(%s)",polynomial(buf[0],2,a,"x",b,"")))),false));
    sprintf(answ[2], "...=%s", memb(buf[8], a*d,1,1,1, chprintf(buf[9],"ln(%s)", polynomial(buf[1],2,c,"",d,chprintf(buf[7],"cos(%s)",polynomial(buf[0],2,a,"x",b,"")))),false));
    sprintf(answ[3], "...=%s", memb(buf[8], -a*d,1,1,1, chprintf(buf[9],"ln(%s)", polynomial(buf[1],2,c,"",d,chprintf(buf[7],"cos(%s)",polynomial(buf[0],2,a,"x",b,"")))),false));
}

void integ133b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,k;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        k=rndr(r);
    }while(!(k>0 && a!=0 && b!=0 && c!=0 && abs(b)!=1));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/(%s))*Diff(x)=...",
        memb(buf[1],a,1,k,1,"x",false),
        poly2ns(buf[2],2, b,1,k+1,1,"x", c,1,1,1,"")
    );

    sprintf(src, "int((a*x^k)/(b*x^(k+1)+c))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[3], a,b,1,1,chprintf(buf[4],"ln(%s)",poly2ns(buf[2],2, b,1,k+1,1,"x", c,1,1,1,"")),false));
    sprintf(answ[1], "...=%s", memb(buf[3], a*b,1,1,1,chprintf(buf[4],"ln(%s)",poly2ns(buf[2],2, b,1,k+1,1,"x", c,1,1,1,"")),false));
    sprintf(answ[2], "...=%s", poly2ns(buf[3],2, a,b,1,1,"ln(x)", a,c*(k+1),k+1,1,"x"));
    sprintf(answ[3], "...=%s", poly2ns(buf[3],2, a,b,1,1,chprintf(buf[9],"ln(%s)",poly2ns(buf[8],1, b,1,k+1,1,"x")), a,c*(k+1),k+1,1,"x"));
}

void integ134b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while(!(a!=0 && b!=0 && c!=0 && abs(b)!=1));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/(%s))*Diff(x)=...",
        polynomial(buf[0],1, a,"e^x"),
        polynomial(buf[1],2, b,"e^x",c,"")
    );

    sprintf(src, "int((a*e^x)/(b*e^x+c))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[2], a,b,1,1,chprintf(buf[3],"ln(%s)", polynomial(buf[4],2,b,"e^x",c,"")),false));
    sprintf(answ[1], "...=%s", memb(buf[2], a*b,1,1,1,chprintf(buf[3],"ln(%s)", polynomial(buf[4],2,b,"e^x",c,"")),false));
    sprintf(answ[2], "...=%s", poly2ns(buf[2],2, a,b,1,1,"x", a,c,1,1,"e^x"));
    sprintf(answ[3], "...=%s", poly2ns(buf[2],1,a,b,1,1,chprintf(buf[4],"%s",polynomial(buf[7],2, 1,"e^(-x)",c,""))));
}

void integ135b (const range& r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while(!(a!=0 && b!=0 && c!=0 && abs(b)!=1 && abs(a)!=1 && abs(a)!=abs(b)));
    chprintf(buf[1],"e^(%s)", polynomial(buf[0],1,a,"x"));
    polynomial(buf[3],2, b,buf[1], c,""),

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/(%s))*Diff(x)=...",
        buf[1],
        buf[3]
    );

    sprintf(src, "int(e^(a*x)/(b*e^(a*x)+c))*diff(x)");

    sprintf(answ[0], "...=%s", memb(buf[2], 1,a*b,1,1,chprintf(buf[4],"ln(%s)",buf[3]),false));
    sprintf(answ[1], "...=%s", memb(buf[2], a,b,1,1,chprintf(buf[4],"ln(%s)",buf[3]),false));
    sprintf(answ[2], "...=%s", memb(buf[2], a*b,1,1,1,chprintf(buf[4],"ln(%s)",buf[3]),false));
    sprintf(answ[3], "...=%s", memb(buf[2], b,a,1,1,chprintf(buf[4],"ln(%s)",buf[3]),false));
}

