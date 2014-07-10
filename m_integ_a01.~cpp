#include "m_expressions.h"

void integ101a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,x1,x2;
    do{
        a=rndr(r);
        x1=rndr(r);
        x2=rndr(r);
    }while(!(a!=0 && x1!=x2));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(Diff(x)/(%s))=...", polynomial(buf[0],3, a,"x^2", -a*(x1+x2),"x", a*x1*x2,""));

    sprintf(answ[0], "...=%s(%s)+C",
        chprintf(buf[9],
              a*(x1-x2)==1? ""
            : a*(x1-x2)==-1? "-"
            : "(%s)*", fraction(buf[0],1,1,a*(x1-x2))),
        chprintf(buf[1], "(ln(abs(%s))-ln(abs(%s)))", polynomial(buf[2],2,1,"x",-x1,""),polynomial(buf[3],2,1,"x",-x2,"")));
    sprintf(answ[1], "...=%s(%s)+C",
        chprintf(buf[9],
              a==1? ""
            : a==-1? "-"
            : "(%s)*", fraction(buf[0],1,1,a)),
        chprintf(buf[1], "(ln(abs(%s))-ln(abs(%s)))", polynomial(buf[2],2,1,"x",-x1,""),polynomial(buf[3],2,1,"x",-x2,"")));
    sprintf(answ[2], "...=%s(%s)+C",
        chprintf(buf[9],
              a*(x1-x2)==1? ""
            : a*(x1-x2)==-1? "-"
            : "(%s)*", fraction(buf[0],1,1,a*(x1-x2))),
        chprintf(buf[1], "(ln(abs(%s))-ln(abs(%s)))", polynomial(buf[2],2,1,"x",-x2,""),polynomial(buf[3],2,1,"x",-x1,"")));
    sprintf(answ[3], "...=%s(%s)+C",
        chprintf(buf[9],
              a==-1? ""
            : a==1? "-"
            : "(%s)*", fraction(buf[0],-1,1,a)),
        chprintf(buf[1], "(1/((%s)^2)+1/((%s)^2))", polynomial(buf[2],2,1,"x",-x2,""),polynomial(buf[3],2,1,"x",-x1,"")));

    sprintf(src, "1/(a*(x-x1)*(x-x2))");
}

void integ102a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,x0,y0,m,n;
    do{
        a=rndr(r);
        x0=rndr(r);
        y0=rndr(r);
        m=rndr(r);
        n=rndr(r);
    }while(!(y0!=0 && y0!=1 && m!=0));

    strcpy(task, "");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt(((%s)/(%s))*Diff(x))=...", polynomial(buf[0],2, m,"x", n,""), polynomial(buf[1],3, 1,"x^2", -2*x0,"x", x0*x0+y0*y0,""));

    sprintf(answ[0], "...=(%s)+(%s)*arctg(%s)+C",
        memb(buf[0], m,2,1,1,chprintf(buf[6],"ln(%s)", polynomial(buf[1],3, 1,"x^2", -2*x0,"x", x0*x0+y0*y0,"")), false),
        fraction(buf[2], m*x0+n,1,y0),
        memb(buf[3],1,y0,1,1,polynomial(buf[4],2,x0,"",1,"x"),false)
    );
    sprintf(answ[1], "...=(%s)+(%s)*arctg(%s)+C",
        memb(buf[0], m,1,1,1, chprintf(buf[6],"ln(%s)", polynomial(buf[1],2, 1, chprintf(buf[7],"(%s)^2", polynomial(buf[8],2,1,"x",x0,"")), y0*y0,"")),false),
        fraction(buf[2], m*x0+n,1,y0),
        memb(buf[3],1,y0,1,1,"x",false)
    );
    sprintf(answ[2], "...=(%s)+(%s)*arctg(%s)+C",
        memb(buf[0], m,1,2,1, chprintf(buf[6],"ln(%s)", polynomial(buf[1],2, 1, chprintf(buf[7],"(%s)^2", polynomial(buf[8],2,1,"x",x0,"")), y0*y0,"")),false),
        fraction(buf[2], n,1,y0),
        polynomial(buf[8],2,1,"x",-x0,"")
    );
    sprintf(answ[3], "...=(%d)/(%s)+(%s)*arctg((%s)/(%d))+C",
        m,
        polynomial(buf[0],3, 2,"x^2", -2*2*x0,"x", 2*x0*x0*y0*y0),
        fraction(buf[1],m*x0+n,1,y0),
        polynomial(buf[2],2, 1,"x", -x0,""),
        y0
    );

    sprintf(src, "(M*x+N)/((x-x0)^2+y0^2)");
}





void integ103a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,x1,x2;
    do{
        a=rndr(r);
        b=rndr(r);
        x1=rndr(r);
        x2=rndr(r);
    }while(!(a!=0 && b!=0 && x1!=x2 && x2!=0));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/(%s))*Diff(x))=...",
        polynomial(buf[0],2, a+b,"x", -(a*x2+b*x1),""),
        polynomial(buf[1],3, 1,"x^2", -(x1+x2),"x", x1*x2,"")
    );
    sprintf(src, "A/(x-x1)+B/(x-x2)");

    sprintf(answ[0], "...=%s",
        polynomial(buf[0],3,
            a,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2,1,"x",-x1,"")),
            b,chprintf(buf[3],"ln(abs(%s))",polynomial(buf[4],2,1,"x",-x2,"")),
            1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        polynomial(buf[0],3,
             b, chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2,1,"x",-x1,"")),
            -a, chprintf(buf[3],"ln(abs(%s))",polynomial(buf[4],2,1,"x",-x2,"")),
             1, "C"
        )
    );
    sprintf(answ[2], "...=%s",
        poly2ns(buf[0],2,
            a+b,2,1,1, chprintf(buf[1],"ln(%s)", polynomial(buf[2],3, 1,"x^2", -(x1+x2),"x", x1*x2,"")),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[3], "...=%s",
        polynomial(buf[0],3,
            a+b, chprintf(buf[1], "ln(%s)",polynomial(buf[2],3,1,"x^2",-(x1+x2),"x",x1*x2,"")),
            -(a*x2+b*x1), chprintf(buf[5], "arctg(x/sqrt(%d))", x1*x2),
            1,"C"
        )
    );
}




void integ104a1 (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,d,x1,x2;
    do{
        a=rndr(r);
        b=rndr(r);
        d=rndr(r);
        x1=rndr(r);
        x2=rndr(r);
    }while(!(a!=0 && b!=0 && d!=0 && x1!=x2 && x2!=0));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/(%s))*Diff(x))=...",
        polynomial(buf[0],3, a+b,"x^2", -(2*x2*a+b*(x1+x2)-d),"x", a*x2*x2+b*x1*x2-d*x1,""),
        polynomial(buf[1],3, 1,"x^3", -(2*x2+x1),"x^2", x2*x2+2*x1*x2,"x", -x1*x2*x2)
    );
    sprintf(src, "A/(x-x1)+B/(x-x2)+D/((x-x2)^2)");

    sprintf(answ[0], "...=%s",
        polynomial(buf[0],4,
            a,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x",-x1,"")),
            b,chprintf(buf[3],"ln(abs(%s))",polynomial(buf[4],2, 1,"x",-x2,"")),
            1,memb(buf[5],-d,1,-1,1,polynomial(buf[6],2,1,"x",-x2,""), true),
            1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        polynomial(buf[0],4,
             b,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x",-x1,"")),
            -a,chprintf(buf[3],"ln(abs(%s))",polynomial(buf[4],2, 1,"x",-x2,"")),
            1,memb(buf[5],d*x2,1,-1,1,polynomial(buf[6],2,1,"x",-x2,""), true),
            1,"C"
        )
    );
    sprintf(answ[2], "...=%s",
        polynomial(buf[0],3,
            a,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x",-x1,"")),
            1,memb(buf[5],-d,1,-1,1,polynomial(buf[6],2,1,"x",-x2,""), true),
            1,"C"
        )
    );
    sprintf(answ[3], "...=%s",
        polynomial(buf[0],3,
            a+b,chprintf(buf[1],"ln(%s)",polynomial(buf[2],3, 1,"x^2",-(x1+x2),"", x1*x2,"")),
            1,memb(buf[5],b,1,-1,1,polynomial(buf[6],2,1,"x",-x2,""), true),
            1,"C"
        )
    );

}




void integ104a2 (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,d,x1,x2;
    do{
        a=rndr(r);
        b=rndr(r);
        d=rndr(r);
        x1=rndr(r);
        x2=rndr(r);
    }while(!(a!=0 && b!=0 && d!=0 && x1!=x2 && x2!=0));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/((%s)*(%s)^2))*Diff(x))=...",
        polynomial(buf[0],3, a+b,"x^2", -(2*x2*a+b*(x1+x2)-d),"x", a*x2*x2+b*x1*x2-d*x1,""),
        polynomial(buf[1],2, 1,"x", -x1,""),
        polynomial(buf[2],2, 1,"x", -x2,"")
    );
    sprintf(src, "A/(x-x1)+B/(x-x2)+D/((x-x2)^2)");

    sprintf(answ[0], "...=%s",
        polynomial(buf[0],4,
            a,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x",-x1,"")),
            b,chprintf(buf[3],"ln(abs(%s))",polynomial(buf[4],2, 1,"x",-x2,"")),
            1,memb(buf[5],-d,1,-1,1,polynomial(buf[6],2,1,"x",-x2,""), true),
            1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        polynomial(buf[0],4,
             b,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x",-x1,"")),
            -a,chprintf(buf[3],"ln(abs(%s))",polynomial(buf[4],2, 1,"x",-x2,"")),
            1,memb(buf[5],d*x2,1,-1,1,polynomial(buf[6],2,1,"x",-x2,""), true),
            1,"C"
        )
    );
    sprintf(answ[2], "...=%s",
        polynomial(buf[0],3,
            a,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x",-x1,"")),
            1,memb(buf[5],-d,1,-1,1,polynomial(buf[6],2,1,"x",-x2,""), true),
            1,"C"
        )
    );
    sprintf(answ[3], "...=%s",
        polynomial(buf[0],3,
            a+b,chprintf(buf[1],"ln(%s)",polynomial(buf[2],3, 1,"x^2",-(x1+x2),"", x1*x2,"")),
            1,memb(buf[5],b,1,-1,1,polynomial(buf[6],2,1,"x",-x2,""), true),
            1,"C"
        )
    );

}




void integ105a1 (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,m,n,x1,x0,y0;
    do{
        a=rndr(r);
        m=rndr(r);
        n=rndr(r);
        x1=rndr(r);
        x0=rndr(r);
        y0=rndr(r);
    }while(!(a!=0 && m!=0 && y0!=0 && x1!=0 && x1!=x0));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/((%s)*(%s)))*Diff(x))=...",
        polynomial(buf[0],3, a,"x^2", -(m-2*a*x0),"x", a*x0*x0+a*y0*y0+n,""),
        polynomial(buf[1],2, 1,"x", -x1,""),
        poly2ns(buf[2],2, 1,1,2,1,polynomial(buf[3],2,1,"x",-x1,""), y0*y0,1,1,1,"")
    );
    sprintf(src, "A/(x-x1)+(M*x+N)/((x-x0)^2+y0^2)");

    sprintf(answ[0], "...=%s",
        poly2ns(buf[0],4,
            a,1,1,1,chprintf(buf[1],"ln(abs(%s))", polynomial(buf[2],2,1,"x",-x1,"")),
            m,2,1,1,chprintf(buf[3],"ln(%s)",poly2ns(buf[4],2, 1,1,2,1,polynomial(buf[5],2,1,"x",-x1,""), y0*y0,1,1,1,"")),
            m*x0+n,y0,1,1,chprintf(buf[6], "arctg(%s)", memb(buf[7], 1,y0,1,1,polynomial(buf[8],2,1,"x",-x0,""),false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        poly2ns(buf[0],3,
            a,1,-1,1,polynomial(buf[1],2, 1,"x",-x1,""),
            m-2*a*x0,2,1,1,chprintf(buf[2],"ln(%s)",poly2ns(buf[3],2, 1,1,2,1,polynomial(buf[4],2,1,"x",-x1,""), y0*y0,1,1,1,"")),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[2], "...=%s",
        poly2ns(buf[0],3,
            a,1,1,1,chprintf(buf[1],"ln(abs(%s))", polynomial(buf[2],2,1,"x",-x1,"")),
            n,y0,1,1,chprintf(buf[3],"arctg(%s)", memb(buf[4], 1,y0,1,1,"x", false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[3], "...=%s",
        poly2ns(buf[0],4,
            1,1,1,1,chprintf(buf[1],"ln(abs(%s))", polynomial(buf[2],2,1,"x",-x1,"")),
            m-2*a*x0,2,1,1,chprintf(buf[3],"ln(%s)",poly2ns(buf[4],2, 1,1,2,1,polynomial(buf[5],2,1,"x",-x1,""), y0*y0,1,1,1,"")),
            m*x0,y0,1,1,chprintf(buf[6], "arctg(%s)", memb(buf[7], 1,y0,1,1,polynomial(buf[8],2,1,"x",-x0,""),false)),
            1,1,1,1,"C"
        )
    );
}




void integ105a2 (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,m,n,x1,x0,y0;
    do{
        a=rndr(r);
        m=rndr(r);
        n=rndr(r);
        x1=rndr(r);
        x0=rndr(r);
        y0=rndr(r);
    }while(!(a!=0 && m!=0 && y0!=0 && x1!=0 && x1!=x0));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/((%s)*(%s)))*Diff(x))=...",
        polynomial(buf[0],3, a,"x^2", -(m-2*a*x0),"x", a*x0*x0+a*y0*y0+n,""),
        polynomial(buf[1],2, 1,"x", -x1,""),
        polynomial(buf[2],3, 1,"x^2", -2*x0,"x", x0*x0+y0*y0,"")
    );
    sprintf(src, "A/(x-x1)+(M*x+N)/((x-x0)^2+y0^2)");

    sprintf(answ[0], "...=%s",
        poly2ns(buf[0],4,
            a,1,1,1,chprintf(buf[1],"ln(abs(%s))", polynomial(buf[2],2,1,"x",-x1,"")),
            m,2,1,1,chprintf(buf[3],"ln(%s)",poly2ns(buf[4],2, 1,1,2,1,polynomial(buf[5],2,1,"x",-x1,""), y0*y0,1,1,1,"")),
            m*x0+n,y0,1,1,chprintf(buf[6], "arctg(%s)", memb(buf[7], 1,y0,1,1,polynomial(buf[8],2,1,"x",-x0,""),false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        poly2ns(buf[0],3,
            a,1,-1,1,polynomial(buf[1],2,1,"x",-x1,""),
            m-2*a*x0,2,1,1,chprintf(buf[2],"ln(%s)",poly2ns(buf[3],2, 1,1,2,1,polynomial(buf[4],2,1,"x",-x1,""), y0*y0,1,1,1,"")),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[2], "...=%s",
        poly2ns(buf[0],3,
            a,1,1,1,chprintf(buf[1],"ln(abs(%s))", polynomial(buf[2],2,1,"x",-x1,"")),
            n,y0,1,1,chprintf(buf[3],"arctg(%s)", memb(buf[4], 1,y0,1,1,"x", false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[3], "...=%s",
        poly2ns(buf[0],4,
            1,1,1,1,chprintf(buf[1],"ln(abs(%s))", polynomial(buf[2],2,1,"x",-x1,"")),
            m-2*a*x0,2,1,1,chprintf(buf[3],"ln(%s)",poly2ns(buf[4],2, 1,1,2,1,polynomial(buf[5],2,1,"x",-x1,""), y0*y0,1,1,1,"")),
            m*x0,y0,1,1,chprintf(buf[6], "arctg(%s)", memb(buf[7], 1,y0,1,1,polynomial(buf[8],2,1,"x",-x0,""),false)),
            1,1,1,1,"C"
        )
    );
}




void integ106a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a,b,d,x1,x2,x3;
    do{
        a=rndr(r);
        b=rndr(r);
        d=rndr(r);
        x1=rndr(r);
        x2=rndr(r);
        x3=rndr(r);
    }while(!(x1!=x2 && x1!=x3 && x2!=0 && x3!=0 && a!=0 && b!=0 && d!=0));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/((%s)*(%s)*(%s)))*Diff(x))=...",
        polynomial(buf[0],3, a+b+d,"x^2", -(a*(x2+x3)+b*(x1+x3)+d*(x1+x2)),"x", a*x2*x3+b*x1*x3+d*x1*x2,""),
        polynomial(buf[1],2, 1,"x", -x1,""),
        polynomial(buf[2],2, 1,"x", -x2,""),
        polynomial(buf[3],2, 1,"x", -x3,"")
    );
    sprintf(src, "A/(x-x1)+B/(x-x2)+D/(x-x3)");

    sprintf(buf[0], "ln(%s)", polynomial(buf[10],2, 1,"x",-x1,""));
    sprintf(buf[1], "ln(%s)", polynomial(buf[10],2, 1,"x",-x2,""));
    sprintf(buf[2], "ln(%s)", polynomial(buf[10],2, 1,"x",-x3,""));

    sprintf(answ[0], "...=%s",
        polynomial(buf[5],4,
            a,buf[0],
            b,buf[1],
            d,buf[2],
            1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        polynomial(buf[5],4,
            d,buf[0],
            -b,buf[1],
            a,buf[2],
            1,"C"
        )
    );
    sprintf(answ[2], "...=%s",
        polynomial(buf[5],4,
            a*(x2+x3),buf[0],
            b*(x1+x3),buf[1],
            d*(x1+x2),buf[2],
            1,"C"
        )
    );
    sprintf(answ[3], "...=%s",
        polynomial(buf[5],2,
            a+b+d,chprintf(buf[6],"%s+%s+%s", buf[0],buf[1],buf[2]),
            1,"C"
        )
    );
}




void integ107a1 (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a,b,x1,p;
    do{
        a=rndr(r);
        b=rndr(r);
        x1=rndr(r);
        p=rndr(r);
    }while(!(p!=0 && a!=0 && b!=0));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/(%s))*Diff(x))=...",
        polynomial(buf[0],3, a,"x^2", b,"x", a*p*p-x1*b,""),
        polynomial(buf[1],3, 1,"x^3", -x1,"x^2", p*p,"x", -x1*p*p,"")
    );
    sprintf(src, "A/(x-x1)+B/(x^2+p^2)");

    sprintf(answ[0], "...=%s",
        poly2ns(buf[0],3,
            a,1,1,1,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            b,p,1,1,chprintf(buf[3],"arctg(%s)", memb(buf[4], 1,p,1,1,"x",false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        poly2ns(buf[0],3,
            a,1,1,1,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            a*p*p-x1*b,p,1,1,chprintf(buf[3],"arctg(%s)", memb(buf[4], 1,p,1,1,"x",false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[2], "...=%s",
        poly2ns(buf[0],3,
            b,2,1,1,chprintf(buf[1],"ln(%s)",polynomial(buf[2],2, 1,"x^2", p*p,"")),
            a,1,-1,1,polynomial(buf[3],2,1,"x",-x1,""),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[3], "...=%s",
        poly2ns(buf[0],3,
            1,1,1,1,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            a,p,1,1,"arctg(x)",
            1,1,1,1,"C"
        )
    );
}



void integ107a2 (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a,b,x1,p;
    do{
        a=rndr(r);
        b=rndr(r);
        x1=rndr(r);
        p=rndr(r);
    }while(!(p!=0 && a!=0 && b!=0));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%d)/(%s)+(%d)/(%s))*Diff(x))=...",
        a,
        polynomial(buf[0],2, 1,"x", -x1,""),
        b,
        polynomial(buf[1],2, 1,"x^2", p*p,"")
    );
    sprintf(src, "A/(x-x1)+B/(x^2+p^2)");

    sprintf(answ[0], "...=%s",
        poly2ns(buf[0],3,
            a,1,1,1,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            b,p,1,1,chprintf(buf[3],"arctg(%s)", memb(buf[4], 1,p,1,1,"x",false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        poly2ns(buf[0],3,
            a,1,1,1,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            a*p*p-x1*b,p,1,1,chprintf(buf[3],"arctg(%s)", memb(buf[4], 1,p,1,1,"x",false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[2], "...=%s",
        poly2ns(buf[0],3,
            b,2,1,1,chprintf(buf[1],"ln(%s)",polynomial(buf[2],2, 1,"x^2", p*p,"")),
            a,1,-1,1,polynomial(buf[3],2,1,"x",-x1,""),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[3], "...=%s",
        poly2ns(buf[0],3,
            1,1,1,1,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            a,p,1,1,"arctg(x)",
            1,1,1,1,"C"
        )
    );
}



void integ108a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a,b,n,x1,p;
    do{
        a=rndr(r);
        b=rndr(r);
        n=rndr(r);
        x1=rndr(r);
        p=rndr(r);
    }while(!(b!=0 && n!=0 && x1!=0 && p!=0));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/((%s)^2*(%s)))*Diff(x))=...",
        polynomial(buf[0],4,
            a,"x^3",
            b+n-x1*a,"x^2",
            p*p-2*n*x1,"x",
            -a*x1*p*p+b*p*p+n*x1*x1,""
        ),
        polynomial(buf[1],2, 1,"x", -x1,""),
        polynomial(buf[2],2, 1,"x^2",p*p,"")
    );
    sprintf(src, "A/(x-x1)+B/((x-x1)^2)+N/(x^2+p^2)");

    sprintf(answ[0], "...=%s",
        poly2ns(buf[0],4,
            a,1,1,1,  chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            -b,1,-1,1,polynomial(buf[3],2, 1,"x", -x1,""),
            n,p,1,1,chprintf(buf[4],"arctg(%s)", memb(buf[5], 1,p,1,1,"x",false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        poly2ns(buf[0],4,
            a,1,1,1,  chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            b,1,-1,1, polynomial(buf[3],2, 1,"x", -x1,""),
            b*p*p+n*x1*x1,p,1,1,chprintf(buf[4],"arctg(%s)", memb(buf[5], 1,p,1,1,"x",false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[2], "...=%s",
        poly2ns(buf[0],3,
            b+n-x1*a,1,-1,1,  polynomial(buf[2],2, 1,"x", -x1,""),
            n,p,1,1,chprintf(buf[4],"arctg(%s)", memb(buf[5], 1,p,1,1,"x",false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[3], "...=%s",
        poly2ns(buf[0],4,
            b,1,1,1,  chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            a,1,-1,1, polynomial(buf[3],2, 1,"x", -x1,""),
            b*p*p+n,1,1,1,chprintf(buf[4],"ln(%s)", polynomial(buf[5],2, 1,"x^2",p*p,"")),
            1,1,1,1,"C"
        )
    );
}



void integ109a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a,m,b,x1,p;
    do{
        a=rndr(r);
        b=rndr(r);
        m=rndr(r);
        x1=rndr(r);
        p=rndr(r);
    }while(!(a!=0 && b!=0 && m!=0 && x1!=0 && p!=0));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/((%s)^2*(%s)))*Diff(x))=...",
        polynomial(buf[0],4,
            a+m,"x^3",
            -(a*x1+2*m*x1-b),"x^2",
            a*p*p+m*x1*x1,"x",
            b*p*p-a*x1*p*p,""
        ),
        polynomial(buf[1],2, 1,"x", -x1,""),
        polynomial(buf[2],2, 1,"x^2",p*p,"")
    );
    sprintf(src, "A/(x-x1)+B/((x-x1)^2)+(M*x)/(x^2+p^2)");

    sprintf(answ[0], "...=%s",
        poly2ns(buf[0],4,
            a,1,1,1,  chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            -b,1,-1,1,polynomial(buf[3],2, 1,"x", -x1,""),
            m,2,1,1,chprintf(buf[4],"ln(%s)", polynomial(buf[5],2, 1,"x^2",p*p,"")),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        poly2ns(buf[0],4,
            a,1,1,1,  chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            a+b,1,-1,1,polynomial(buf[3],2, 1,"x", -x1,""),
            -m,1,1,1,chprintf(buf[4],"ln(%s)", polynomial(buf[5],2, 1,"x^2",p*p,"")),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[2], "...=%s",
        poly2ns(buf[0],4,
            a,1,-1,1,  polynomial(buf[2],2, 1,"x", -x1,""),
            b,1,1,1,chprintf(buf[4],"arctg(%s)", memb(buf[5], 1,p,1,1,"x",false)),
            m,p,1,1,chprintf(buf[4],"arctg(%s)", memb(buf[5], 1,p,1,1,"x",false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[3], "...=%s",
        poly2ns(buf[0],4,
            b,1,-1,1,  polynomial(buf[2],2, 1,"x", -x1,""),
            a,1,1,1,chprintf(buf[4],"arctg(%s)", memb(buf[5], 1,p,1,1,"x",false)),
            m,p,1,1,chprintf(buf[4],"arctg(%s)", memb(buf[5], 1,p,1,1,"x",false)),
            1,1,1,1,"C"
        )
    );
}




void integ110a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a,n,m,b,x1,p;
    do{
        a=rndr(r);
        b=rndr(r);
        m=rndr(r);
        n=rndr(r);
        x1=rndr(r);
        p=rndr(r);
    }while(!(a!=0 && b!=0 && m!=0 && x1!=0 && p!=0));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/((%s)^2*(%s)))*Diff(x))=...",
        polynomial(buf[0],4,
            a+m,"x^3",
            -(a*x1+2*m*x1-b-n),"x^2",
            a*p*p+m*x1*x1-2*n*x1,"x",
            b*p*p-a*x1*p*p+n*x1*x1,""
        ),
        polynomial(buf[1],2, 1,"x", -x1,""),
        polynomial(buf[2],2, 1,"x^2",p*p,"")
    );
    sprintf(src, "A/(x-x1)+B/((x-x1)^2)+(M*x+N)/(x^2+p^2)");

    sprintf(answ[0], "...=%s",
        poly2ns(buf[0],5,
            a,1,1,1,  chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            -b,1,-1,1,polynomial(buf[3],2, 1,"x", -x1,""),
            m,2,1,1,chprintf(buf[4],"ln(%s)", polynomial(buf[5],2, 1,"x^2",p*p,"")),
            n,p,1,1,chprintf(buf[4],"arctg(%s)", memb(buf[5], 1,p,1,1,"x",false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        poly2ns(buf[0],4,
            a+m,1,1,1,  chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            -b,1,-1,1,polynomial(buf[3],2, 1,"x", -x1,""),
            b+m,2,1,1,chprintf(buf[4],"ln(%s)", polynomial(buf[5],2, 1,"x^2",p*p,"")),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[2], "...=%s",
        poly2ns(buf[0],4,
            b,1,1,1,  chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            a,1,-1,1,polynomial(buf[3],2, 1,"x", -x1,""),
            n,p,1,1,chprintf(buf[4],"arctg(%s)", memb(buf[5], 1,p,1,1,"x",false)),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[0], "...=%s",
        poly2ns(buf[0],4,
            b,1,1,1,   chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            n,2,1,1,   chprintf(buf[4],"ln(%s)", polynomial(buf[5],2, 1,"x^2",p*p,"")),
            m,1,1,1,   chprintf(buf[4],"arctg(%s)", memb(buf[5], 1,p,1,1,"x",false)),
            1,1,1,1,   "C"
        )
    );
}



void integ111a (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int p,q,a,x1,b,x2;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
        q=rndr(r);
        x1=rndr(r);
        x2=rndr(r);
    }while(!(a!=0 && b!=0 && p!=0 && q!=0 && x1!=0 && x2!=0 && x1!=x2 && a!=b && a!=p));

    strcpy(task,"");
    catprintf(task, "String(\"Найдите интеграл:\")");
    catprintf(task, "\nInt((%s)/(%s))*Diff(x))=...",
        polynomial(buf[0],4,
            p,"x^3",
            -(p*(x1+x2)-q),"x^2",
            p*x1*x2-q*(x1+x2)+a+b,"x",
            q*x1*x2-a*x2-b*x1,""
        ),
        polynomial(buf[1],3, 1,"x^2", -(x1+x2),"x", x1*x2,"")
    );
    sprintf(src, "P*x+Q+A/(x-x1)+B/(x-x2)");

    sprintf(answ[0], "...=%s",
        poly2ns(buf[0],5,
            p,2,1,1,"x^2",
            q,1,1,1,"x",
            a,1,1,1,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            b,1,1,1,chprintf(buf[3],"ln(abs(%s))",polynomial(buf[4],2, 1,"x", -x2,"")),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[1], "...=%s",
        poly2ns(buf[0],5,
            a,2,1,1,"x^2",
            q,1,1,1,"x",
            p,1,1,1,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            -b,1,1,1,chprintf(buf[3],"ln(abs(%s))",polynomial(buf[4],2, 1,"x", -x2,"")),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[2], "...=%s",
        poly2ns(buf[0],4,
            b,1,1,1,"x^2",
            b,1,1,1,chprintf(buf[1],"ln(abs(%s))",polynomial(buf[2],2, 1,"x", -x1,"")),
            a,1,1,1,chprintf(buf[3],"ln(abs(%s))",polynomial(buf[4],2, 1,"x", -x2,"")),
            1,1,1,1,"C"
        )
    );
    sprintf(answ[3], "...=%s",
        poly2ns(buf[0],4,
            p,2,1,1,"x^2",
            b,1,1,1,"x",
            a,1,1,1,chprintf(buf[1],"ln(%s)",polynomial(buf[2],3, 1,"x^2", -(x1+x2),"x", x1*x2,"")),
            1,1,1,1,"C"
        )
    );
}




