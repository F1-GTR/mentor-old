#include <stdio.h>
#include "m_expressions.h"
#include "m_mflab.h"

char *mflab01 (const range& r, char *text)
{
    char buf[10][BUFSZ]; chprintf(text, "");
    int a,b;
    do{
        a=rnd(r.f,r.t);
        b=rnd(r.f,r.t);
    }while (a==0 || b==0);
    catprintf(text,"String(\"Укажите уравнение свободных колебаний струны без сопротивления:\")");
    catprintf(text, "%s%s", SEP,SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 2, 1,"pdiffn(u,2)/pdiff(t,2)",-a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 2, 1,"pdiffn(u,2)/pdiff(t,2)", a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)", b,"(pdiff(u)/pdiff(t))", a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=Q(t,x)", polynomial(buf[0], 2, 1,"pdiffn(u,2)/pdiff(t,2)",-a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)", b,"(pdiff(u)/pdiff(t))", -a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    return text;
}

char *mflab02 (const range& r, char *text)
{
    char buf[10][BUFSZ]; chprintf(text, "");
    int a,b;
    do{
        a=rnd(r.f,r.t);
        b=rnd(r.f,r.t);
    }while (a==0 || b==0);
    catprintf(text,"String(\"Уравнение свободных колебаний струны с вязким сопротивлением:\")");
    catprintf(text, "%s", SEP);
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)", b,"(pdiff(u)/pdiff(t))", -a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)",-b,"(pdiff(u)/pdiff(t))", -a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)",-b,"(pdiff(u)/pdiff(x))", -a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)", b,"(pdiff(u)/pdiff(x))",  a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)",-b,"(pdiff(u)/pdiff(x))",  a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    return text;
}

char *mflab03 (const range& r, char *text)
{
    char buf[10][BUFSZ]; chprintf(text, "");
    int l,c,h;
    bool done;
    char an[10][BUFSZ];
    do{
        do{
            l=rndr(r);
            c=rndr(r);
            h=rndr(r);
        }while(!(c>0 && l>c && l-h!=0 && h!=0 && h!=c));

        chprintf(an[1], "at(u,t=0)=f(x)=system(%s&String(\",\")&%d<=x<=%d,%s&String(\",\")&%d<=x<=%d)\n",
            memb(buf[0], h,c,1,1,"x",false),
            0,c,
            poly2ns(buf[1],2, h*l,l-c,1,1,"", -h,l-c,1,1,"x"),
            c,l
        );
        catprintf(an[1], "at(diff(u)/diff(t),t=0)=0\n");
        catprintf(an[1], "at(u,x=0)=at(u,x=l)=0");


        chprintf(an[2], "at(u,t=0)=f(x)=system(%s&String(\",\")&%d<=x<=%d,%s&String(\",\")&%d<=x<=%d)\n",
            memb(buf[0], h*c,1,1,1,"x",false),
            0,c,
            poly2ns(buf[1],2, h,c,1,1,"x", -l*h,c,1,1,""),
            c,l
        );
        catprintf(an[2], "at(diff(u)/diff(t),t=0)=0\n");
        catprintf(an[2], "at(u,x=0)=at(u,x=l)=0");


        chprintf(an[3], "at(u,t=0)=f(x)=system(%s&String(\",\")&%d<=x<=%d,%s&String(\",\")&%d<=x<=%d)\n",
            memb(buf[0], c,h,1,1,"x",false),
            0,c,
            poly2ns(buf[1],2, c*l,l-h,1,1,"", -c,l-h,1,1,"x"),
            c,l
        );
        catprintf(an[3], "at(diff(u)/diff(t),t=0)=0\n");
        catprintf(an[3], "at(u,x=0)=at(u,x=l)=0");


        chprintf(an[4], "at(u,t=0)=f(x)=system(%s&String(\",\")&%d<=x<=%d,%s&String(\",\")&%d<=x<=%d)\n",
            poly2ns(buf[0],2, h,c,1,1,"x", -h*l,c,1,1,""),
            0,c,
            poly2ns(buf[1],1, h,l-c,1,1,"x"),
            c,l
        );
        catprintf(an[4], "at(diff(u)/diff(t),t=0)=0\n");
        catprintf(an[4], "at(u,x=0)=at(u,x=l)=0");


        chprintf(an[5], "at(u,t=0)=f(x)=system(%s&String(\",\")&%d<=x<=%d,%s&String(\",\")&%d<=x<=%d)\n",
            poly2ns(buf[0],1, c,l-c,1,1,"x"),
            0,c,
            poly2ns(buf[1],2, h*l,c,1,1,"", -h,c,1,1,"x"),
            0,c
        );
        catprintf(an[5], "at(diff(u)/diff(t),t=0)=0\n");
        catprintf(an[5], "at(u,x=0)=at(u,x=l)=0");

        done=true;
        for(int i=1; i<=5; ++i)
            for(int j=i+1; j<=5; ++j)
                if (!strcmp(an[i],an[j]))
                    done=false;

    }while(!done);
    catprintf(text, "String(\"Написать начальные и граничные условия в задаче о колебаниях\")\n");
    catprintf(text, "String(\"струны с закрепленными концами (\")&0<=x<=%d&String(\"), которая в начальный\")\n", l);
    catprintf(text, "String(\"момент времени t=0 оттянута в точке \")&x=%d&String(\" на заданную\")\n", c);
    catprintf(text, "String(\"величину %d и отпущена без начальной скорости.\")", h);
    catprintf(text, "%s", SEP);
    for(int i=1; i<=5; ++i)
        catprintf(text, "%s%s", SEP, an[i]);
    return text;
}

char *mflab04 (const range& r, char *text)
{
    char buf[10][BUFSZ];
    int l,c,n,h,tau,rho;
    char nstr[100];
    char an[10][BUFSZ];
    bool done;
    do{
        do{
            l=rndr(r);
            c=rndr(r);
            n=rndr(r);
            h=rndr(r);
            tau=rndr(r);
            rho=rndr(r);
        }while(!(n>0 && abs(tau)!=abs(rho) && h*l!=0 && tau>0 && rho>0 && c*(l-c)*n*n!=0 && l!=0));
        if (n>10 && n<20)
            strcpy(nstr, "ый");
        else
            switch(n%10)
            {
                case 2: strcpy(nstr, "ой"); break;
                case 3: strcpy(nstr, "ий"); break;
                case 6: strcpy(nstr, "ой"); break;
                case 7: strcpy(nstr, "ой"); break;
                case 8: strcpy(nstr, "ой"); break;
                default: strcpy(nstr, "ый"); break;
            }
        chprintf(an[1], "(%s*(1/pi^2))*sin(%s)*cos(%s)",
            memb(buf[0], 2*h*l*l,c*(l-c)*n*n,1,1,chprintf(buf[8],"sin(%s)",memb(buf[1],n*c,l,1,1,"pi",false)), false),
            memb(buf[2], n,l,1,1,"pi*x",false),
            memb(buf[3], n,l,1,1,chprintf(buf[4], "pi*sqrt(%s)*t", fraction(buf[5],tau,1,rho)), false)
        );
        chprintf(an[2], "(%s*(1/pi^2))*sin(%s)*cos(%s)",
            memb(buf[0], h*l*l,c*n,1,1,chprintf(buf[8],"sin(%s)",memb(buf[1],n*c,l,1,1,"pi",false)), false),
            memb(buf[2], n,l,1,1,"pi*x",false),
            memb(buf[3], n*tau,l*rho,1,1,"pi*t", false)
        );
        chprintf(an[3], "(%s*(1/pi^2))*sin(%s)*cos(%s)",
            memb(buf[0], h*l,c*n,1,1,chprintf(buf[8],"sin(%s)",memb(buf[1],n*c,l,1,1,"pi",false)), false),
            memb(buf[2], n,l,1,1,"pi*x",false),
            memb(buf[3], n,l,1,1,chprintf(buf[4], "sqrt(%s)*t", fraction(buf[5],tau,1,rho)), false)
        );
        chprintf(an[4], "(%s*(1/pi^2))*sin(%s)*cos(%s)",
            memb(buf[0], 2*h*l,c*(l-c)*n,1,1,chprintf(buf[8],"sin(%s)",memb(buf[1],n*c,l,1,1,"pi",false)), false),
            memb(buf[2], n,l,1,1,"pi*x",false),
            memb(buf[3], n*tau,l*rho,1,1,"t", false)
        );
        chprintf(an[5], "(%s*(1/pi^2))*sin(%s)*cos(%s)",
            memb(buf[0], h*l*l,(l-c)*n,1,1,chprintf(buf[8],"sin(%s)",memb(buf[1],n*c,l,1,1,"pi",false)), false),
            memb(buf[2], n,l,1,1,"pi*x",false),
            memb(buf[3], n,l,1,1,chprintf(buf[4], "pi*sqrt(%s)*t", fraction(buf[5],tau,1,rho)), false)
        );

        done=true;
        for(int i=1; i<=5; ++i)
            for(int j=i+1; j<=5; ++j)
                if (!strcmp(an[i],an[j]))
                    done=false;

    }while(!done);
    chprintf(text, "String(\"Струна, концы которой закреплены в точках x=0 и x=%d, оттянута в начальный момент времени\")\n", l);
    catprintf(text, "String(\"в точке x=%d и отпущена без начальной скорости.\")\n", c);
    catprintf(text, "String(\"Определить %d-%s член разложения в ряд смещения u(x,t) любой точки струны,\")\n", n, nstr);
    catprintf(text, "String(\"если u(%d,0)=%d.\")\na=sqrt(tau/rho)\ntau=%d&String(\" - натяжение струны,\")\nrho=%d&String(\" - линейная плотность струны.\")", c, h, tau, rho);
    catprintf(text, "%s", SEP);
    for(int i=1; i<=5; ++i)
        catprintf(text, "%s%s", SEP, an[i]);
    return text;
}

char *mflab05 (const range& r, char *text)
{
    char buf[10][BUFSZ]; chprintf(text, "");
    int a,b;
    do{
        a=rnd(r.f,r.t);
        b=rnd(r.f,r.t);
    }while (!(a!=0 && b!=0));
    catprintf(text,"String(\"Укажите уравнение свободных продольных колебаний стержня без сопротивления:\")");
    catprintf(text, "%s%s", SEP,SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 2, 1,"pdiffn(u,2)/pdiff(t,2)",-a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 2, 1,"pdiffn(u,2)/pdiff(t,2)", a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)", b,"(pdiff(u)/pdiff(t))", a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=Q(t,x)", polynomial(buf[0], 2, 1,"pdiffn(u,2)/pdiff(t,2)",-a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)", b,"(pdiff(u)/pdiff(t))", -a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    return text;
}

char *mflab06 (const range& r, char *text)
{
    char buf[10][BUFSZ]; chprintf(text, "");
    int a,b;
    do{
        a=rnd(r.f,r.t);
        b=rnd(r.f,r.t);
    }while (a==0 || b==0);
    catprintf(text,"String(\"Найти дифференциальное уравнение свободных продольных колебаний стержня с вязким сопротивлением:\")");
    catprintf(text, "%s", SEP);
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)", b,"(pdiff(u)/pdiff(t))", -a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)",-b,"(pdiff(u)/pdiff(t))", -a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)",-b,"(pdiff(u)/pdiff(x))", -a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)", b,"(pdiff(u)/pdiff(x))",  a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0], 3, 1,"pdiffn(u,2)/pdiff(t,2)",-b,"(pdiff(u)/pdiff(x))",  a*a,"(pdiffn(u,2)/pdiff(x,2))"));
    return text;
}

char *mflab07 (const range& r, char *text)
{
    int l,c,v0; chprintf(text, "");
    char buf[10][BUFSZ];
    do{
        l=rndr(r);
        c=rndr(r);
        v0=rndr(r);
    }while(!(v0!=0 && l>0 && c>0 && c<l));
    catprintf(text, "String(\"Написать начальные и граничные условия в задаче о колебаниях стержня с закрепленным\")\n");
    catprintf(text, "String(\"правым концом (\")&0<=x<=%d&String(\"), который в начальный момент времени имеет нулевые\")\n",l);
    catprintf(text, "String(\"смещения, а в точке x=%d имеет скорость %d\")", c, v0);
    catprintf(text, SEP);
    catprintf(text, SEP);
    catprintf(text, "f(x)=0&String(\",\")&at(diff(u)/diff(t),t=0)=%s\nat(diff(u)/diff(x),x=0)=0\nu(%d,t)=0", polynomial(buf[0],1, v0,chprintf(buf[1],"sigma*(%d-x0)",c)),l);
    for(int i=0; i<3; ++i)
    {
        int i_v0, i_c;
        do{
            i_v0 = rndr(r);
            i_c = rndr(r);
        }while(!((i_v0!=v0 || i_c!=c) && i_v0!=0 && i_c>0 && i_c<l));
        catprintf(text, SEP);
        catprintf(text, "f(x)=0&String(\",\")&at(diff(u)/diff(t),t=0)=%s\nat(diff(u)/diff(x),x=0)=0\nu(%d,t)=0", polynomial(buf[0],1, i_v0,chprintf(buf[1],"sigma*(%d-x0)",i_c)),l);
    }
    return text;
}

char *mflab08 (const range& r, char *text)
{
    int a,b,c,d,n; chprintf(text, "");
    char buf[10][BUFSZ];
    do{
        a=rnd(r.f*100,r.t*100);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
        n=rnd(1,10);
    }while(!(a>0 && b>0 && c>0 && d>0 && (n>=1 && n<=10)));
    catprintf(text, "String(\"Модуль упругости стержня E=%d.\")\n",a);
    catprintf(text, "String(\"Площадь поперечного сечения S=%d.\")\n",b);
    catprintf(text, "String(\"Погонная плотность \")&rho=%d\n",c);
    catprintf(text, "String(\"Длина стержня l=%d\").\nString(\"Найти частоту %d-й гармоники.\")",d,n);
    catprintf(text, "%s", SEP);
    catprintf(text, "%s", SEP);
    fraction(buf[0],(2*n-1),a*b,c*c*2*d);
    if (!strcmp(buf[0],"1")) strcpy(buf[1],"");
    else if (!strcmp(buf[0],"-1")) strcpy(buf[1],"-");
    else chprintf(buf[1], "(%s)*", buf[0]);
    catprintf(text, "omega=%spi", buf[1]);
    for(int i=0; i<3; ++i)
    {
        int i_a, i_b, i_c, i_d, i_n;
        do{
            i_a=rnd(r.f*100,r.t*100);
            i_b=rndr(r);
            i_c=rndr(r);
            i_d=rndr(r);
            i_n=rnd(1,10);
        }while(!(a!=i_a && b!=i_b && c!=i_c && d!=i_d && n!=i_n && (i_a>0 && i_b>0 && i_c>0 && i_d>0 && (i_n>=1 && i_n<=10))));
        fraction(buf[0],(2*i_n-1),i_a*i_b,i_c*i_c*2*i_d);
        if (!strcmp(buf[0],"1")) strcpy(buf[1],"");
        else if (!strcmp(buf[0],"-1")) strcpy(buf[1],"-");
        else chprintf(buf[1], "(%s)*", buf[0]);
        catprintf(text, "%s", SEP);
        catprintf(text, "omega=%spi", buf[1]);
    }
    return text;
}

char *mflab09 (const range& r, char *text)
{
    char buf[10][BUFSZ]; strcpy(text,"");
    int a;
    do{
        a=rndr(r);
    }while(!(a!=0));
    catprintf(text, "Укажите уравнение свободных колебаний балки без сопротивления:");
    catprintf(text, "%s", SEP);
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0],2, 1,"(pdiffn(u,2)/pdiff(t,2))", a*a,"pdiffn(u,4)/pdiff(x,4)"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0],2, 1,"(pdiffn(u,2)/pdiff(t,2))", -a*a,"pdiffn(u,4)/pdiff(x,4)"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0],2, 1,"(pdiffn(u,2)/pdiff(t,2))", a*a,"pdiffn(u,2)/pdiff(x,2)"));
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0", polynomial(buf[0],2, 1,"(pdiffn(u,4)/pdiff(t,4))", a*a,"pdiffn(u,4)/pdiff(x,4)"));
    return text;
}

char *mflab10 (const range& r, char *text)
{
    char buf[10][BUFSZ]; strcpy(text, "");
    int mu,a,h,p,delta,x0;
    do{
        mu=rndr(r);
        a=rndr(r);
        h=rndr(r);
        p=rndr(r);
        delta=rndr(r);
        x0=rndr(r);
    }while(!(mu>0 && a>0 && h>0 && delta>0));
    catprintf(text, "String(\"Укажите уравнение вынужденных колебаний балки с сопротивлением:\")");
    catprintf(text, "%s", SEP);
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=%s",
        polynomial(buf[0],3, 1,"pdiffn(u,2)/pdiff(t,2)", 2*mu, "(pdiff(u)/pdiff(t))", a*a,"(pdiffn(u,4)/pdiff(x,4))"),
        polynomial(buf[1],2, h,chprintf(buf[2],"sin(%d)",p), delta, polynomial(buf[3],2,1,"x",-x0,""))
    );
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=%s",
        polynomial(buf[0],3, 1,"pdiffn(u,2)/pdiff(t,2)", 0, "(pdiff(u)/pdiff(t))", a*a,"(pdiffn(u,4)/pdiff(x,4))"),
        polynomial(buf[1],2, h,chprintf(buf[2],"sin(%d)",p), delta, polynomial(buf[3],2,1,"x",-x0,""))
    );
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=0",
        polynomial(buf[0],3, 1,"pdiffn(u,2)/pdiff(t,2)", 2*mu, "(pdiff(u)/pdiff(t))", a*a,"(pdiffn(u,4)/pdiff(x,4))")
    );
    catprintf(text, "%s", SEP);
    catprintf(text, "%s=%s",
        polynomial(buf[0],3, 1,"pdiffn(u,2)/pdiff(t,2)", 2*mu, "(pdiff(u)/pdiff(t))", 0,"(pdiffn(u,4)/pdiff(x,4))"),
        polynomial(buf[1],2, h,chprintf(buf[2],"sin(%d)",p), delta, polynomial(buf[3],2,1,"x",-x0,""))
    );
    return text;
}

char *mflab11 (const range& r, char *text)
{
    char buf[10][BUFSZ]; strcpy(text,"");
    int rhort, E, Iy, l, n, i_rhort, i_E, i_Iy, i_l, i_n;
    do{
        rhort=rndr(r);
        E=rndr(r);
        Iy=rndr(r);
        l=rndr(r);
        n=rndr(r);
    }while(!(rhort>0 && E>0 && l>0 && Iy>0 && n>0));
    catprintf(text, "String(\"Определите %d собственную частоту шарнирно-опертой балки по данным \")&%d&String(\", \")&%d&String(\", \")&%d&String(\", \")&%d", n, rhort*rhort, E, Iy, l);
    catprintf(text, "%s", SEP);
    catprintf(text, "%s", SEP);

    fraction(buf[1], n*n, E*Iy, rhort*l*l*2);
    if (strcmp(buf[1],"1")==0) chprintf(buf[2], "");
    else if (strcmp(buf[1],"-1")==0) chprintf(buf[2], "-");
    else chprintf(buf[2], "(%s)*",buf[1]);
    catprintf(text, "f=%spi&String(\" Гц\")", buf[2]);

    for(int i=0; i<3; ++i)
    {
        catprintf(text, "%s", SEP);
        do{
            i_rhort=rndr(r);
            i_E=rndr(r);
            i_Iy=rndr(r);
            i_l=rndr(r);
            i_n=rndr(r);
        }while(!(i_rhort>0 && i_E>0 && i_l>0 && i_Iy>0 && i_n>0)&&!(rhort==i_rhort && E==i_E && i_l==l && i_Iy==Iy && i_n==n));
        fraction(buf[1], i_n*i_n, i_E*i_Iy, i_rhort*i_l*i_l*2);
        if (strcmp(buf[1],"1")==0) chprintf(buf[2], "");
        else if (strcmp(buf[1],"-1")==0) chprintf(buf[2], "-");
        else chprintf(buf[2], "(%s)*",buf[1]);
        catprintf(text, "f=%spi&String(\" Гц\")", buf[2]);
    }
    return text;
}
