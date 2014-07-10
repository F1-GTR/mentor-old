#include <vcl.h>
#include "m_limits.h"

bool sq3 (int a)
{
    for(int i=-a/2; i<=a/2; ++i)
        if (i*i*i==a) return true;
    return false;
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                                                            //
//     ¹1.1.1 - 1.2.6                                                         //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


void lim111t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,x1,x2,x3;

    do{
        a=rndr(r), b=rndr(r), c=rndr(r);
        x1=rndr(r), x2=rndr(r), x3=rndr(r);
    }while (!(a!=0 && b!=0 && c!=x1 && c!=x2 && c!=x3 && x1!=x3 && b*c*c-b*(x2+x3)*c+b*x1*x2!=0));

    sprintf(src, "lim(x->c,(a*x^2-a*(x1+x2)*x+a*x1*x2)/(b*x^2-b*(x2+x3)*x+b*x1*x2))=(a*c^2-a*(x1+x2)*c+a*x1*x2)/(b*c^2-b*(x2+x3)*c+b*x1*x2)");
    sprintf(text, "lim(x->%d, (%s)/(%s))=(%s)",
        c,
        polynomial(buf[0], 3,a,"x^2", -a*(x1+x2),"x", a*x1*x2,""),
        polynomial(buf[1], 3,b,"x^2", -b*(x2+x3),"x", b*x1*x2,""),
        fraction(buf[2],
            a*c*c-a*(x1+x2)*c+a*x1*x2,  1,
            b*c*c-b*(x2+x3)*c+b*x1*x2
        )
    );

    rmvpar(text,text);
}


void lim112t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,x1,x2,x3;
    do{
        a=rndr(r), b=rndr(r);
        x1=rndr(r), x2=rndr(r), x3=rndr(r);
    }while (!(a!=0 && b!=0 && x1!=x3 && x2!=x3));
    sprintf(src, "lim(x->x2,(a*x^2-a*(x1+x2)*x+a*x1*x2)/(b*x^2-b*(x2+x3)*x+b*x2*x3))=(a*(x2-x1))/(b*(x2-x3))");
    sprintf(text, "lim(x->%d,(%s)/(%s))=%s",
        x2,
        polynomial(buf[0], 3,a,"x^2",-a*(x1+x2),"x",a*x1*x2,""),
        polynomial(buf[1], 3,b,"x^2",-b*(x2+x3),"x",b*x2*x3,""),
        fraction(buf[2], a*(x2-x1), 1, b*(x2-x3))
    );
    rmvpar(text,text);
}


void lim113t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,x1,x2,x3;
    do{
        a=rndr(r), b=rndr(r);
        x1=rndr(r), x2=rndr(r), x3=rndr(r);
    }while (!(a!=0 && x1!=x3 && (b!=0 || -b*(x2+x3)!=0 || abs(b*x2*x3)>=2)));
    sprintf(src, "lim(x->x3,(a*x^2-a*(x1+x2)*x+a*x1*x2)/(b*x^2-b*(x2+x3)*x+b*x2*x3))=inf");
    sprintf(text, "lim(x->%d,(%s)/(%s))=inf",
        x3,
        polynomial(buf[0], 3,a,"x^2",-a*(x1+x2),"x",a*x1*x2,""),
        polynomial(buf[1], 3,b,"x^2",-b*(x2+x3),"x",b*x2*x3,"")
    );
    rmvpar(text,text);
}


void lim114t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,x1,x2,x3;
    do{
        a=rndr(r), b=rndr(r);
        x1=rndr(r), x2=rndr(r), x3=rndr(r);
    }while (!(b!=0 && x1!=x3));
    sprintf(src, "lim(x->x1,(a*x^2-a*(x1+x2)*x+a*x1*x2)/(b*x^2-b*(x2+x3)*x+b*x2*x3))=0");
    sprintf(text, "lim(x->%d,(%s)/(%s))=0",
        x1,
        polynomial(buf[0], 3,a,"x^2",-a*(x1+x2),"x",a*x1*x2,""),
        polynomial(buf[1], 3,b,"x^2",-b*(x2+x3),"x",b*x2*x3,"")
    );
    rmvpar(text,text);
}


void lim115t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,x1,x2,x3;
    do{
        a=rndr(r), b=rndr(r);
        x1=rndr(r), x2=rndr(r), x3=rndr(r);
    }while (!(b!=0));
    sprintf(src, "lim(x->inf,(a*x^2-a*(x1+x2)*x+a*x1*x2)/(b*x^2-b*(x2+x3)*x+b*x2*x3))=a/b");
    sprintf(text, "lim(x->inf,(%s)/(%s))=%s",
        polynomial(buf[0], 3,a,"x^2",-a*(x1+x2),"x",a*x1*x2,""),
        polynomial(buf[1], 3,b,"x^2",-b*(x2+x3),"x",b*x2*x3,""),
        fraction(buf[2], a,1,b)
    );
    rmvpar(text,text);
}




void lim121t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a1,a2,a3,b1,b2,b3,p1,p2,p3,q1,q2,q3;
    do{
        a1=rndr(r), a2=rndr(r), a3=rndr(r);
        b1=rndr(r), b2=rndr(r), b3=rndr(r);
        p1=rndr(r), p2=rndr(r), p3=rndr(r);
        q1=rndr(r), q2=rndr(r), q3=rndr(r);
    }while (!(p1>p2 && p2>p3 && p3>=0  &&  q1>q2 && q2>q3 && q3>=0  &&  p1==q1  &&  a1*a2*a3!=0 && b1*b2*b3!=0));
    sprintf(src, "lim(x->inf,(a1*x^p1+a2*x^p2+a3*x^p3)/(b1*x^q1+b2*x^q2+b3*x^q3))=a1/b1,p1=q1");
    sprintf(text,"lim(x->inf,(%s)/(%s))=%s",
        poly2(buf[0], false,  3,  a1,1,p1,1,"x",  a2,1,p2,1,"x",  a3,1,p3,1,"x"),
        poly2(buf[2], false,  3,  b1,1,q1,1,"x",  b2,1,q2,1,"x",  b3,1,q3,1,"x"),
        fraction(buf[1], a1,1,b1)
    );
    rmvpar(text,text);
}



void lim122t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a1,a2,a3,b1,b2,b3,p1,p2,p3,q1,q2,q3;
    do{
        a1=rndr(r), a2=rndr(r), a3=rndr(r);
        b1=rndr(r), b2=rndr(r), b3=rndr(r);
        p1=rndr(r), p2=rndr(r), p3=rndr(r);
        q1=rndr(r), q2=rndr(r), q3=rndr(r);
    }while (!(p1>p2 && p2>p3 && p3>=0  &&  q1>q2 && q2>q3 && q3>=0  &&  p1<q1  &&  a1*a2*a3!=0 && b1*b2*b3!=0));
    sprintf(src, "lim(x->inf,(a1*x^p1+a2*x^p2+a3*x^p3)/(b1*x^q1+b2*x^q2+b3*x^q3))=0,p1<q1,p1>p2>p3,q1>q2>q3");
    sprintf(text,"lim(x->inf,(%s)/(%s))=0",
        poly2(buf[0], false,  3,  a1,1,p1,1,"x",  a2,1,p2,1,"x",  a3,1,p3,1,"x"),
        poly2(buf[2], false,  3,  b1,1,q1,1,"x",  b2,1,q2,1,"x",  b3,1,q3,1,"x")
    );
    rmvpar(text,text);
}



void lim123t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a1,a2,a3,b1,b2,b3,p1,p2,p3,q1,q2,q3;
    do{
        a1=rndr(r), a2=rndr(r), a3=rndr(r);
        b1=rndr(r), b2=rndr(r), b3=rndr(r);
        p1=rndr(r), p2=rndr(r), p3=rndr(r);
        q1=rndr(r), q2=rndr(r), q3=rndr(r);
    }while (!(p1>p2 && p2>p3 && p3>=0  &&  q1>q2 && q2>q3 && q3>=0  &&  p1>q1  &&  a1*a2*a3!=0 && b1*b2*b3!=0));
    sprintf(src, "lim(x->inf,(a1*x^p1+a2*x^p2+a3*x^p3)/(b1*x^q1+b2*x^q2+b3*x^q3))=inf,p1>q1");
    sprintf(text,"lim(x->inf,(%s)/(%s))=inf",
        poly2(buf[0], false,  3,  a1,1,p1,1,"x",  a2,1,p2,1,"x",  a3,1,p3,1,"x"),
        poly2(buf[2], false,  3,  b1,1,q1,1,"x",  b2,1,q2,1,"x",  b3,1,q3,1,"x")
    );
    rmvpar(text,text);
}



//?
void lim124t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a1,a2,a3,b1,b2,b3,p1,p2,p3,q1,q2,q3;
    do{
        a1=rndr(r), a2=rndr(r), a3=rndr(r);
        b1=rndr(r), b2=rndr(r), b3=rndr(r);
        p1=rndr(r), p2=rndr(r), p3=rndr(r);
        q1=rndr(r), q2=rndr(r), q3=rndr(r);
    }while (!(p1>p2 && p2>p3 && p3>=0  &&  q1>q2 && q2>q3 && q3>=0  &&  p3==q3  &&  a1*a2*a3!=0 && b1*b2*b3!=0));
    sprintf(src, "lim(x->0,(a1*x^p1+a2*x^p2+a3*x^p3)/(b1*x^q1+b2*x^q2+b3*x^q3))=a3/b3,p3=q3");
    sprintf(text,"lim(x->0,(%s)/(%s))=%s",
        poly2(buf[0], false,  3,  a1,1,p1,1,"x",  a2,1,p2,1,"x",  a3,1,p3,1,"x"),
        poly2(buf[2], false,  3,  b1,1,q1,1,"x",  b2,1,q2,1,"x",  b3,1,q3,1,"x"),
        fraction(buf[1], a3,1,b3)
    );
    rmvpar(text,text);
}



void lim125t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a1,a2,a3,b1,b2,b3,p1,p2,p3,q1,q2,q3;
    do{
        a1=rndr(r), a2=rndr(r), a3=rndr(r);
        b1=rndr(r), b2=rndr(r), b3=rndr(r);
        p1=rndr(r), p2=rndr(r), p3=rndr(r);
        q1=rndr(r), q2=rndr(r), q3=rndr(r);
    }while (!(p1>p2 && p2>p3 && p3>=0  &&  q1>q2 && q2>q3 && q3>=0  &&  p3<q3  &&  a1*a2*a3!=0 && b1*b2*b3!=0));
    sprintf(src, "lim(x->0,(a1*x^p1+a2*x^p2+a3*x^p3)/(b1*x^q1+b2*x^q2+b3*x^q3))=inf,p3<q3");
    sprintf(text,"lim(x->0,(%s)/(%s))=inf",
        poly2(buf[0], false,  3,  a1,1,p1,1,"x",  a2,1,p2,1,"x",  a3,1,p3,1,"x"),
        poly2(buf[1], false,  3,  b1,1,q1,1,"x",  b2,1,q2,1,"x",  b3,1,q3,1,"x")
    );
    rmvpar(text,text);
}



void lim126t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int a1,a2,a3,b1,b2,b3,p1,p2,p3,q1,q2,q3;
    do{
        a1=rndr(r), a2=rndr(r), a3=rndr(r);
        b1=rndr(r), b2=rndr(r), b3=rndr(r);
        p1=rndr(r), p2=rndr(r), p3=rndr(r);
        q1=rndr(r), q2=rndr(r), q3=rndr(r);
    }while (!(p1>p2 && p2>p3 && p3>=0  &&  q1>q2 && q2>q3 && q3>=0  &&  p3>q3  &&  a1*a2*a3!=0 && b1*b2*b3!=0));
    sprintf(src, "lim(x->0,(a1*x^p1+a2*x^p2+a3*x^p3)/(b1*x^q1+b2*x^q2+b3*x^q3))=0,p3>q3");
    sprintf(text,"lim(x->0,(%s)/(%s))=0",
        poly2(buf[0], false,  3,  a1,1,p1,1,"x",  a2,1,p2,1,"x",  a3,1,p3,1,"x"),
        poly2(buf[1], false,  3,  b1,1,q1,1,"x",  b2,1,q2,1,"x",  b3,1,q3,1,"x")
    );
    rmvpar(text,text);
}


/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *           x^2 - (a+b)x + a*b   (a-e)(b-e)
 *     lim   ------------------ = ----------
 *     x->e  x^2 - (c+d)x + c*d   (c-e)(d-e)
 *
 *  - - - - - - - - - - - - - - - - - - - - -
 *
 *   c-e!=0; d-e!=0
 *
 * * * * * * * * * * * * * * * * * * * * * * */
void lim131t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][100];
    int a,b,c,d,e;
    do{
        a=rnd(r.f,r.t); b=rnd(r.f,r.t); c=rnd(r.f,r.t);
        d=rnd(r.f,r.t); e=rnd(r.f,r.t);
    }while(!(c-e!=0 && d-e!=0));
    sprintf(src, "lim(x->p,(x^2-(a+b)*x+a*b)/(x^2-(c+d)*x+c*d))=((a-p)*(b-p))/((c-p)*(d-p))");
    sprintf(text, "lim(x->%d,(%s)/(%s))=%s",
        e,
        polynomial(buf[0], 3,1,"x^2",-(a+b),"x",a*b,""),
        polynomial(buf[1], 3,1,"x^2",-(c+d),"x",c*d,""),
        fraction(buf[2], (a-e)*(b-e),1,(c-e)*(d-e))
    );
}

/* * * * * * * * * * * * * * * * * * * * * *
 *
 *           x^2 - (a+b)x + a*b   (a-b)
 *     lim   ------------------ = -----
 *     x->a  x^2 - (c+d)x + c*d   (a-c)
 *
 *  - - - - - - - - - - - - - - - - - - -
 *
 *   a-c!=0
 *
 * * * * * * * * * * * * * * * * * * * * */
void lim132t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][100];
    int a,b,c;
    do{
        a=rnd(r.f,r.t);
        b=rnd(r.f,r.t);
        c=rnd(r.f,r.t);
    }while (!(a-c!=0));
    sprintf(src, "lim(x->a,(x^2-(a+b)*x+a*b)/(x^2-(a+c)*x+a*c))=(a-b)/(a-c)");
    sprintf(text, "lim(x->%d, (%s)/(%s))=%s",
        a,
        polynomial(buf[0], 3,1,"x^2",-(a+b),"x",a*b,""),
        polynomial(buf[1], 3,1,"x^2",-(a+c),"x",a*c,""),
        fraction(buf[2], a-b,1,a-c)
    );
}

/* * * * * * * * * * * * * * * * * * * * *
 *
 *           a1*x^2 + b1*x + c1   a1
 *     lim   ------------------ = --
 *     x->a  a2*x^2 + b2*x + c2   a2
 *
 *  - - - - - - - - - - - - - - - - - - -
 *
 *   a1, a2 <> 0
 *
 * * * * * * * * * * * * * * * * * * * * */
void lim141t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][100];
    int a1,b1,c1,a2,b2,c2;
    do{
        a1=rnd(r.f,r.t);
        b1=rnd(r.f,r.t);
        c1=rnd(r.f,r.t);
        a2=rnd(r.f,r.t);
        b2=rnd(r.f,r.t);
        c2=rnd(r.f,r.t);
    }while(!(a2!=0 && a1!=0));
    sprintf(src, "lim(x->inf,(a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2))=a1/a2");
    sprintf(text, "lim(x->inf,(%s)/(%s))=%s",
        polynomial(buf[0], 3,a1,"x^2",b1,"x",c1,""),
        polynomial(buf[1], 3,a2,"x^2",b2,"x",c2,""),
        fraction(buf[2], a1,1,a2)
    );
}

/* * * * * * * * * * * * * * * * * * * * *
 *
 *             a1*x^2 + b1*x + c1
 *     lim     ------------------ = 0
 *     x->inf  a2*x^3 + b2*x + c2
 *
 *  - - - - - - - - - - - - - - - - - - -
 *
 *   a1, a2 <> 0
 *
 * * * * * * * * * * * * * * * * * * * * */
void lim151t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
	char buf[10][BUFSZ];
    int a1,b1,c1,a2,b2,c2;
	do{
        a1=rndr(r);
    	b1=rndr(r);
    	c1=rndr(r);
        a2=rndr(r);
        b2=rndr(r);
        c2=rndr(r);
    }while (!(a1!=0 && a2!=0));
    sprintf(src, "lim(x->inf,(a1*x^2+b1*x+c1)/(a2*x^3+b2*x+c2))=0");
	sprintf(text, "lim(x->inf, (%s)/(%s))=0",
        polynomial(buf[0], 3, a1,"x^2", b1,"x",c1,""),
        polynomial(buf[1], 3, a2,"x^3",b2,"x",c2,"")
    );
}

void lim161t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
	char buf[5][BUFSZ];
    int a1,b1,c1,a2,b2,c2;
	do{
        a1=rndr(r);
        b1=rndr(r);
        c1=rndr(r);
        a2=rndr(r);
    	b2=rndr(r);
    	c2=rndr(r);
    }while (!(a1!=0 && a2!=0));
    sprintf(src, "lim(x->inf,(a1*x^3+b1*x+c1)/(a2*x^2+b2*x+c2))=inf");
	sprintf(text, "lim(x->inf, (%s)/(%s))=inf",
        polynomial(buf[0], 3, a1,"x^3", b1,"x", c1,""),
        polynomial(buf[1], 3,a2,"x^2",b2,"x",c2,"")
    );
}











////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                                                            //
//     ¹1.1.1 - 1.2.6                                                         //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////










void lim211t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int k1,k2,a,b,c,d;
    do{
        k1=rndr(r), k2=rndr(r);
        a=rndr(r),b=rndr(r),c=rndr(r),d=rndr(r);
    }while (!(a>=0 && b>=0 && abs(d)>=2 && abs(a)+abs(b)!=0 && a!=b && k1*k2!=0 && k1!=k2));
    /*draw_sum1(buf[4],d,a,d,b); rmvpar(buf[4],buf[4]);
    sprintf(buf[5],"1/(%s)", buf[4]);*/
    sprintf(text, "lim(x->0, (sqrt(%s)-sqrt(%s))/((%s)*(%s)))=%s",
        polynomial(buf[0], 2, k1,"x",a*a,""),
        polynomial(buf[1], 2, k2,"x",b*b,""),
        polynomial(buf[2], 2, k1-k2,"x",a*a-b*b,""),
        polynomial(buf[3], 2, c,"x",d,""),
        fraction(buf[4],1,1,(a+b)*d)
    );
    sprintf(src, "lim(x->0,(sqrt(k1*x+a^2)-sqrt(k2*x+b^2))/(((k1-k2)*x+a^2-b^2)*(c*x+d)))=1/((a+b)*d)");
    rmvpar(text,text);
}



void lim212t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int k1,k2,a,b,c,d;
    do{
        k1=rndr(r), k2=rndr(r);
        a=rndr(r),b=rndr(r),c=rndr(r),d=rndr(r);
    }while (a<0 || b<0 || abs(d)<2 || abs(a)+abs(b)==0 || a!=b || k1*k2==0 || k1==k2);
    sprintf(text, "lim(x->0, (sqrt(%s)-sqrt(%s))/((%s)*(%s)))=%s",
        polynomial(buf[0], 2, k1,"x",a*a,""),
        polynomial(buf[1], 2, k2,"x",b*b,""),
        polynomial(buf[2], 2, k1-k2,"x",a*a-b*b,""),
        polynomial(buf[3], 2, c,"x",d,""),
        fraction(buf[4],1,1,2*a*d)
    );
    sprintf(src, "lim(x->0,(sqrt(k1*x+a^2)-sqrt(k2*x+b^2))/(((k1-k2)*x+a^2-b^2)*(c*x+d)))=1/(2*a*d)");
    rmvpar(text,text);
}




void lim221t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[20][BUFSZ];
    int k1,k2,a,b,c,d,x0;
    do{
        k1=rndr(r), k2=rndr(r);
        a=rndr(r),b=rndr(r),c=rndr(r),d=rndr(r);
        x0=rndr(r);
    }while (!(k1*x0+a>=0 && k2*x0+b>=0 && c*x0+d!=0 && k1-k2!=0 && c!=0 && k1!=0 && k2!=0 && k1>0 && k2>0));
    sprintf(text, "lim(x->%d, ((%s)*(%s))/(sqrt(%s)-sqrt(%s)))=%s",
        x0,
        polynomial(buf[0], 2, k1-k2,"x",a-b,""),
        polynomial(buf[1], 2, c,"x",d,""),
        polynomial(buf[2], 2, k1,"x",a,""),
        polynomial(buf[3], 2, k2,"x",b,""),
        draw_sum1(buf[4],c*x0+d,k1*x0+a,c*x0+d,k2*x0+b)
    );
    sprintf(src, "lim(x->x0,(((k1-k2)*x+a-b)*(c*x+d))/(sqrt(k1*x+a)-sqrt(k2*x+b)))=(c*x0+d)*(sqrt(k1*x0+a)+sqrt(k2*x0+b))");
    rmvpar(text,text);
}

//?
void lim231t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
	char buf[10][BUFSZ];
    int b,c,d;
	do{
    	b=rndr(r);
	    c=rndr(r);
        d=rndr(r);
    }while (!(d!=0));
	sprintf(text, "lim(x->%d, (%s)/(sqrt(%s)-sqrt(%s)))=%d",
        abs(d*d)+c,
        polynomial(buf[0], 3, 1,"x^2", -(abs(d*d)+b+c),"x", (b*abs(d*d)+b*c),""),
        polynomial(buf[1], 2, 1,"x", -c,""),
        polynomial(buf[2], 2, c+abs(2*d*d),"",-1,"x"),
        -(b-c-d*d)*abs(d)
    );
    sprintf(src, "lim(x->d^2+c,(x^2-(d^2+b+c)*x+(b*d^2+b*c))/(sqrt(x-c)-sqrt(c+(2*d^2)-x)))=-(b-c-d^2)*abs(d)");
}




void lim241t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1,a2,b2,c2;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
    }while(!(a1!=a2 && a1>0 && a2>0 && a1>a2 && b1>0 && b2>0));
    sprintf(text,"lim(x->inf, sqrt(%s)-sqrt(%s))=+inf",
        polynomial(buf[0], 3, a1*a1,"x^2",b1,"x",c1,""),
        polynomial(buf[1], 3, a2*a2,"x^2",b2,"x",c2,"")
    );
    sprintf(src, "lim(x->inf,sqrt(a1^2*x^2+b1*x+c1)-sqrt(a2^2*x^2+b2*x+c2))=+inf,a1>a2");
    rmvpar(text,text);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                                                          b1-b2
 *     lim   sqrt(a1*x^2+b1*x+c1) - sqrt(a2*x^2+b2*x+c2) = -------
 *   x->+inf                                                2*a1
 *
 *
 *  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 *   a1<a2; a1,a2>0; b1!=b2
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void lim242t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1,a2,b2,c2;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
    }while(!(b1!=b2 && a1>0 && a2>0 && a1<a2));
    sprintf(text,"lim(x->inf, sqrt(%s)-sqrt(%s))=-inf",
        polynomial(buf[0], 3, a1*a1,"x^2",b1,"x",c1,""),
        polynomial(buf[1], 3, a2*a2,"x^2",b2,"x",c2,"")
    );
    sprintf(src, "lim(x->inf,sqrt(a1^2*x^2+b1*x+c1)-sqrt(a2^2*x^2+b2*x+c2))=-inf,a1<a2");
    rmvpar(text,text);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                                                          b1-b2
 *     lim   sqrt(a1*x^2+b1*x+c1) - sqrt(a2*x^2+b2*x+c2) = -------
 *   x->+inf                                                2*a1
 *
 *
 *  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 *   a1=a2, a1>0, b1!=b2
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void lim243t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1,a2,b2,c2;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
    }while(!(a1==a2 && a1>0 && b1!=b2));
    sprintf(text,"lim(x->+inf, sqrt(%s)-sqrt(%s))=%s",
        polynomial(buf[0], 3, a1*a1,"x^2",b1,"x",c1,""),
        polynomial(buf[1], 3, a2*a2,"x^2",b2,"x",c2,""),
        fraction(buf[2], b1-b2,1,2*a1)
    );
    sprintf(src, "lim(x->+inf,sqrt(a1^2*x^2+b1*x+c1)-sqrt(a2^2*x^2+b2*x+c2))=(b1-b2)/(2*a1),a1=a2");
    rmvpar(text,text);
}

void lim244t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1,a2,b2,c2;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
    }while(!(a1==a2 && a1>0 && b1!=b2));
    sprintf(text,"lim(x->-inf, sqrt(%s)-sqrt(%s))=%s",
        polynomial(buf[0], 3, a1*a1,"x^2",b1,"x",c1,""),
        polynomial(buf[1], 3, a2*a2,"x^2",b2,"x",c2,""),
        fraction(buf[2], b2-b1,1,2*a1)
    );
    sprintf(src, "lim(x->-inf,sqrt(a1^2*x^2+b1*x+c1)-sqrt(a2^2*x^2+b2*x+c2))=(b2-b1)/(2*a1),a1=a2");
    rmvpar(text,text);
}

void lim245t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1,a2,b2,c2;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
    }while(!(a1==a2 && a1>0 && b1==b2 && abs(a1)+abs(a2)!=0));
    sprintf(text,"lim(x->inf, sqrt(%s)-sqrt(%s))=0",
        polynomial(buf[0], 3, a1*a1,"x^2",b1,"x",c1,""),
        polynomial(buf[1], 3, a2*a2,"x^2",b2,"x",c2,"")
    );
    sprintf(src, "lim(x->inf,sqrt(a1^2*x^2+b1*x+c1)-sqrt(a2^2*x^2+b2*x+c2))=0,a1=a2,b1=b2");
    rmvpar(text,text);
}


void lim251t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(true));
    sprintf(text, "lim(x->+inf, (x*(sqrt(%s)-sqrt(%s))))=%s",
        polynomial(buf[0], 2,a,"",1,"x^2"),
        polynomial(buf[1], 2,b,"",1,"x^2"),
        fraction(buf[2], a-b,1,2)
    );
    sprintf(src, "lim(x->inf,x*(sqrt(a+x^2)-sqrt(b+x^2)))=(a-b)/2");
}


void lim252t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rnd(r.f, r.t);
        b=rnd(r.f, r.t);
    }while(!(true));
    sprintf(text, "lim(x->-inf, (x*(sqrt(%s)-sqrt(%s))))=%s",
        polynomial(buf[0],2,a,"",1,"x^2"),
        polynomial(buf[1],2,b,"",1,"x^2"),
        fraction(buf[2], b-a,1,2)
    );
    sprintf(src, "lim(x->-inf,x*(sqrt(a+x^2)-sqrt(b+x^2)))=(b-a)/2");
}


void lim261t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while(!(a>0));
    polynomial(buf[1], 3, a*a,"x^2", b,"x", c,"");
    sprintf(buf[0],"sqrt(%s)",buf[1]);
    polynomial(buf[1], 2, 1,buf[0], -a,"x");
    sprintf(text, "lim(x->+inf, %s)=%s",
        buf[1],
        fraction(buf[2], b,1,2*a)
    );
    sprintf(src, "lim(x->+inf,sqrt(a^2*x^2+b*x+c)-a*x)=b/(2*a),a>0");
}


void lim262t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while(!(a>0));
    polynomial(buf[1], 3, a*a,"x^2", b,"x", c,"");
    sprintf(buf[0],"sqrt(%s)",buf[1]);
    polynomial(buf[1], 2, 1,buf[0], -a,"x");
    sprintf(text, "lim(x->-inf, %s)=+inf", buf[1]);
    sprintf(src, "lim(x->-inf,sqrt(a^2*x^2+b*x+c)-a*x)=+inf,a>0");
}


void lim271t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[3][BUFSZ];
    int a;
    do{
        a=rndr(r);
    }while(!(a>0));
    sprintf(text, "lim(h->0, (sqrt(%d+h)-%s)/h)=%s",
        a,
        fraction(buf[0],1,a,1),
        fraction(buf[1],1,a,2*a) //?
    );
    sprintf(src, "lim(h->0,(sqrt(a+h)-sqrt(a))/h)=1/(2*sqrt(a)),a>0");
}


void lim281t (const range& ar, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int n,a;
    do{
        n=rndr(range(2,4));
        a=rndr(ar);
    }while (!(a>0));
    sprintf(text, "lim(x->0, ((%s)^(1/%d)-1)/(x))=%s",
        polynomial(buf[0], 2,a,"x",1,""),
        n, // don't need to use a fraction - n!=1
        fraction(buf[1],a,1,n)
    );
    sprintf(src, "lim(x->0,((a*x+1)^(1/n)-1)/x)=a/n");
}


void lim291t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[5][100];
    int a,b,c;
    do{
        a=rnd(1,9);
        b=rnd(1,9);
        c=rnd(-9,9);
    }while(!(c!=0));
    int r1,i1,r2,i2;
    r1=1;i1=a;r2=-1;i2=b;
    sprintf(text, "lim(x->+inf, (sqrt(%s)-sqrt(%s))/(sqrt(x)))=%s",
        polynomial(buf[1],2, a,"x",c,""),
        polynomial(buf[2],1, b,"x"),
        draw_sum1(buf[0],r1,i1,r2,i2)
    );
    sprintf(src, "lim(x->+inf,(sqrt(a*x+c)-sqrt(b*x))/sqrt(x))=sqrt(a)-sqrt(b)");
}



////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                                                            //
//     ¹3.x.x                                                                 //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


void lim311t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && b!=0));
    sprintf(text, "lim(x->0, sin(%s)/(%s))=%s",
        polynomial(buf[0], 1, a,"x"),
        polynomial(buf[1], 1, b,"x"),
        fraction(buf[2], a,1,b)
    );
    sprintf(src, "lim(x->0,sin(a*x)/(b*x))=a/b");
    rmvpar(text,text);
}


void lim312t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text, "");
    int a;
    do{
        a=rndr(r);
    }while(!(a!=0 && a!=1));
    catprintf(text, "lim(x->0, tg(%s)/x)=%d", polynomial(buf[0],1,a,"x"), a);
    sprintf(src, "lim(x->0,tg(a*x)/x)=a");
}

void lim313t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && b!=0));
    sprintf(text, "lim(x->0, arcsin(%s)/(%s))=%s",
        polynomial(buf[0], 1, a,"x"),
        polynomial(buf[1], 1, b,"x"),
        fraction(buf[2], a,1,b)
    );
    sprintf(src, "lim(x->0,arcsin(a*x)/(b*x))=a/b");
    rmvpar(text,text);
}

void lim314t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && b!=0));
    sprintf(text, "lim(x->0, sin(%s)/tg(%s))=%s",
        polynomial(buf[0], 1, a,"x"),
        polynomial(buf[1], 1, b,"x"),
        fraction(buf[2], a,1,b)
    );
    sprintf(src, "lim(x->0,sin(a*x)/tg(b*x))=a/b");
    rmvpar(text,text);
}


void lim315t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0 && a!=1 && b!=a));
    chprintf(text, "lim(x->0, tg(%s)/arctg(%s))=%s",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],1,b,"x"),
        fraction(buf[2],a,1,b)
    );
    sprintf(src, "lim(x->0,tg(a*x)/arctg(b*x))=a/b");
}

void lim316t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0 && a!=1 && b!=a));
    chprintf(text, "lim(x->0, arctg(%s)/arcsin(%s))=%s",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],1,b,"x"),
        fraction(buf[2],a,1,b)
    );
    sprintf(src, "lim(x->0,arctg(a*x)/arcsin(b*x))=a/b");
}

void lim317t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    chprintf(text, "lim(x->0, sin(%s)/tg(%s))=0",
        polynomial(buf[0],1,a,"x^2"),
        polynomial(buf[1],1,b,"x")
    );
    sprintf(src, "lim(x->0,sin(a*x^2)/tg(b*x))=0");
}

void lim318t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    chprintf(text, "lim(x->0, arcsin(%s)/(%s))=inf",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],1,b,"x^2")
    );
    sprintf(src, "lim(x->0,arcsin(a*x)/(b*x^2))=inf");
}

void lim319t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    chprintf(text, "lim(x->0, (1-cos(%s))/(%s))=%s",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],1,b,"x^2"),
        fraction(buf[2], a*a,1,2*b)
    );
    sprintf(src, "lim(x->0,(1-cos(a*x))/(b*x^2))=a^2/(2*b)");
}

void lim3110t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    chprintf(text, "lim(x->0, (1-cos(%s))/(%s))=0",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],1,b,"x")
    );
    sprintf(src, "lim(x->0,(1-cos(a*x))/(b*x))=0");
}

void lim321t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && b!=0));
    sprintf(text, "lim(x->0, tg(%s)/sin(%s))=%s",
        polynomial(buf[0], 1, b,"x^2"),
        memb(buf[3], 1,1,2,1,polynomial(buf[1], 1, a,"x"),false),
        fraction(buf[2], b,1,a*a)
    );
    sprintf(src, "lim(x->0,tg(b*x^2)/sin(a^2*x^2))=b/a^2");
    rmvpar(text,text);
}

void lim322t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && b!=0));
    sprintf(text, "lim(x->0, (sin(%s)^2)/arcsin(%s))=%s",
        polynomial(buf[0], 1,a,"x"),
        polynomial(buf[1], 1,b,"x^2"),
        fraction(buf[2], a*a,1,b)
    );
    sprintf(src, "lim(x->0,(sin(a*x)^2)/arcsin(b*x^2))=a^2/b");
    rmvpar(text,text);
}

void lim323t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && b!=0 && !sq3(b)));
    sprintf(text, "lim(x->0, arcsin(%s)/sin(root(3,%s)))=%s(%d/root(3,%d))",
        polynomial(buf[0], 1, a,"root(3,x)"),
        polynomial(buf[1], 1, b,"x"),
        a*b>0?"":"-",abs(a),abs(b)
    );
    sprintf(src, "lim(x->0,arcsin(a*root(3,x))/sin(root(3,b*x)))=(a*b/abs(a*b))*((abs(a)/root(3,abs(b))))");
    rmvpar(text,text);
}

void lim324t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0 && b!=1 && a!=1));
    chprintf(text, "lim(x->0,(arctg(%s)^3)/sin(%s))=%d/root(3,%d)", //!
        polynomial(buf[0], 1,b,"x"),
        polynomial(buf[1], 1,a,"x^3"),
        a,b
    );
    sprintf(src, "lim(x->0,(arctg(b*x)^3)/sin(a*x^3))=a/root(3,b)");
}

void lim325t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    catprintf(text, "lim(x->0, (sin(%s)^2)/(%s))=0",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],1,b,"x")
    );
    sprintf(src, "lim(x->0,(sin(a*x)^2)/(b*x))=0");
}

void lim326t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    catprintf(text, "lim(x->0, (arctg(%s)^3)/(%s))=inf",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],1,b,"x^4")
    );
    sprintf(src, "lim(x->0,(arctg(a*x)^3)/(b*x^4))=inf");
}

void lim331t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,x0;
    do{
        a=rndr(r);
        b=rndr(r);
        x0=rndr(r);
    }while (!(a!=0 && b!=0 && x0!=0));
    sprintf(text, "lim(x->%d, sin(%s)/(%s))=%s",
        x0,
        polynomial(buf[0], 1, a, par(polynomial(buf[1], 2,1,"x",-x0,""))),
        polynomial(buf[2], 1, b, par(polynomial(buf[3], 2,1,"x",-x0,""))),
        fraction(buf[4], a,1,b)
    );
    sprintf(src, "lim(x->x0,sin(a*(x-x0))/(b*(x-x0)))=a/b");
    rmvpar(text,text);
}

void lim332t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b,x0;
    do{
        a=rndr(r);
        b=rndr(r);
        x0=rndr(r);
    }while(!(a!=0 && b!=0));
    catprintf(text, "lim(x->%d,(tg(%s)^2)/(%s))=0",
        x0,
        polynomial(buf[0],2,a,"x",-a*x0,""),
        polynomial(buf[1],2,b,"x",-b*x0,"")
    );
    sprintf(src, "lim(x->x0,(tg(a*x-a*x0)^2)/(b*x-b*x0))=0");
}

void lim333t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,x0,k;
    do{
        a=rndr(r);
        b=rndr(r);
        x0=rndr(r);
        k=rndr(range(-4,4));
    }while (!(a*b*x0!=0 && k>0 && (abs(a*k)<=25 && abs(b*k)<=25) && abs((int)pow(b,k))<=2000 && abs((int)pow(a,k))<=2000));
    sprintf(buf[1], "sin(%s)", polynomial(buf[2],1,a,par(polynomial(buf[3],2,1,"x",-x0,""))));
    sprintf(buf[2], "tg(%s)", polynomial(buf[3],1,b,par(polynomial(buf[4],2,1,"x",-x0,""))));
    sprintf(text,"lim(x->%d, (%s)/(%s))=%s",
        x0,
        memb(buf[9],1,1,k,1,buf[1],false),
        memb(buf[8],1,1,k,1,buf[2],false),
        fraction(buf[4],(int)pow(a,k),1,(int)pow(b,k))
    );
    sprintf(src, "lim(x->x0,(sin(x-x0)^k)/(tg(x-x0)^k))=a^k/b^k");
    rmvpar(text,text);
}

void lim334t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b,x0,n;
    do{
        a=rndr(r);
        b=rndr(r);
        x0=rndr(r);
        n=rndr(range(1,5));
    }while(!(a!=0 && b!=0));
    catprintf(text, "lim(x->%d,(%s)/(%s))=0",
        x0,
        memb(buf[0], 1,1,n+2,1,chprintf(buf[1],"sin(%s)", polynomial(buf[2],2,a,"x",-a*x0,"")),false),
        memb(buf[3], 1,1,n,1,chprintf(buf[1],"tg(%s)", polynomial(buf[2],2,b,"x",-b*x0,"")),false)
    );
    sprintf(src, "lim(x->x0,(sin(a*x-a*x0)^(n+2))/(tg(b*x-b*x0)^n))=0");
}

void lim335t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text, "");
    int a,b,x0;
    do{
        a=rndr(r);
        b=rndr(r);
        x0=rndr(r);
    }while(!(a!=0 && b!=0 && a!=1 && b!=1 && a!=b));
    catprintf(text, "lim(x->%d,(cos(%s)-1)/(sin(%s)^2))=%s",
        x0,
        polynomial(buf[2],2,a,"x",-a*x0,""),
        polynomial(buf[3],2,b,"x",-b*x0,""),
        fraction(buf[4], -a*a,1,2*b*b)
    );
    sprintf(src, "lim(x->x0,(cos(a*x-a*x0)-1)/(sin(b*x-b*x0)^2))=-a^2/(2*b^2)");
}

void lim336t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,x0,n;
    do{
        a=rndr(r);
        b=rndr(r);
        x0=rndr(r);
        n=rndr(r);
    }while (!(a*b*x0!=0 && a!=-1 && b!=-1 && n>0 && (abs(a*n)<=25 && abs(b*n)<=25) && abs((int)pow(a,n))<=2000 && abs((int)pow(b,n))<=2000));
    sprintf(buf[1], "sin(%s)", polynomial(buf[2],1,a,par(polynomial(buf[3],2,1,"x",-x0,""))));
    sprintf(buf[2], "arctg(%s)", polynomial(buf[3],1,b,par(polynomial(buf[4],2,1,"x",-x0,""))));
    sprintf(text,"lim(x->%d, (%s)/(%s))=%s",
        x0,
        memb(buf[9],1,1,n,1,buf[1],false),
        memb(buf[8],1,1,n,1,buf[2],false),
        fraction(buf[4],pow(a,n),1,pow(b,n))
    );
    sprintf(src, "lim(x->x0,(sin(x-x0)^n)/(tg(b*x-b*x0)^n))=0");
    rmvpar(text,text);
}

void lim337t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,x0,m;
    do{
        a=rndr(r);
        b=rndr(r);
        x0=rndr(r);
        m=rndr(r);
    }while (!(a*b*x0!=0 && a!=-1 && b!=-1 && m>1 && !(a*b<0 && m>0)));
    sprintf(buf[1], "arcsin(%s)", polynomial(buf[2],1,a,par(polynomial(buf[3],2,1,"x",-x0,""))));
    sprintf(buf[2], "sin(%s)", polynomial(buf[3],1,b,par(polynomial(buf[4],2,1,"x",-x0,""))));
    sprintf(text,"lim(x->%d, (%s)/(%s))=%s",
        x0,
        memb(buf[9],1,1,1,m,buf[1],false),
        memb(buf[8],1,1,1,m,buf[2],false),
        abs(a)!=abs(b)? memb(buf[3], 1,1,1,m,fraction(buf[4],a,1,b),false) : (a*b<0? "-1": "1")
    );
    sprintf(src, "lim(x->x0,(root(m,arcsin(x-x0)))/(root(m,tg(b*x-b*x0))))=root(m,a/b)");
    rmvpar(text,text);
}

void lim338t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b,x0,n;
    do{
        a=rndr(r);
        b=rndr(r);
        x0=rndr(r);
        n=rndr(range(1,5));
    }while(!(a!=0 && b!=0));
    catprintf(text, "lim(x->%d,(%s)/(%s))=inf",
        x0,
        memb(buf[0], 1,1,n,1,chprintf(buf[1],"arcsin(%s)", polynomial(buf[2],2,a,"x",-a*x0,"")),false),
        memb(buf[3], 1,1,n+1,1,chprintf(buf[1],"tg(%s)", polynomial(buf[2],2,b,"x",-b*x0,"")),false)
    );
    sprintf(src, "lim(x->x0,arcsin(a*(x-x0))/tg(b*(x-x0)))=inf");
}

void lim341t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0 && b!=a));
    catprintf(text, "lim(x->0,(1-cos(%s))/(1-cos(%s)))=%s",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],1,b,"x"),
        fraction(buf[2],a*a,1,b*b)
    );
    sprintf(src, "lim(x->0,(1-cos(a*x))/(1-cos(b*x)))=a^2/b^2");
}

void lim342t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0 && b!=a));
    catprintf(text, "lim(x->%d,(cos(x)-cos(%d))/(%s))=-sin(%d)",
        a,
        a,
        polynomial(buf[0],2,1,"x",-a,""),
        a
    );
    sprintf(src, "lim(x->a,(cos(x)-cos(a))/(x-a))=-sin(a)");
}

void lim343t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    catprintf(text, "lim(x->%d,(sin(x)-sin(%d))/(%s))=%s",
        a,
        a,
        polynomial(buf[0],2,b,"x",-b*a,""),
        memb(buf[2], 1,b,1,1,chprintf(buf[1],"cos(%d)",a), false)
    );
    sprintf(src, "lim(x->a,(sin(x)-sin(a))/(b*(x-a)))=b*cos(a)");
}

void lim344t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text, "");
    int a;
    do{
        a=rndr(r);
    }while(!(a!=0 && a!=1));
    catprintf(text, "lim(x->0,(tg(%s)-sin(%s))/(x^3))=%s",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[2],1,a,"x"),
        fraction(buf[1],a*a*a,1,2)
    );
    sprintf(src, "lim(x->0,(tg(a*x-x0)-sin(a*x))/(x^3))=a^3/2");
}

void lim345t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text, "");
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    catprintf(text, "lim(x->0,(tg(%s)-sin(%s))/(%s))=0",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[2],1,a,"x"),
        polynomial(buf[3],1,b,"x^2"),
        fraction(buf[1],a*a*a,1,2)
    );
    sprintf(src, "lim(x->0,(tg(a*x)-sin(a*x))/(b*x^2))=0");
}

void lim346t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    catprintf(text, "lim(x->%d, (sin(x)-sin(%d))/(%s))=inf",
        a,
        a,
        memb(buf[0],b,1,1,1,chprintf(buf[1],"(%s)^2",polynomial(buf[2],2,1,"x",-a,"")), false)
    );
    sprintf(src, "lim(x->a,(sin(x)-sin(a))/(b*(x-a)^2))=inf");
}

void lim347t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    catprintf(text, "lim(x->%s, arcsin(%s)/(%s))=%s",
        fraction(buf[0],1,1,a),
        polynomial(buf[1],2, 1,"",-a,"x"),
        polynomial(buf[2],2, b*a*a*a,"x^3",-b,""),
        fraction(buf[3],-1,1,3*b)
    );
    sprintf(src, "lim(x->(1/a),arcsin(1-a*x)/(b*a^3*x^3-b))=-1/(3*b)");
}

void lim348t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    catprintf(text, "lim(x->%s, (%s)/(%s))=%s",
        fraction(buf[0],1,1,a),
        memb(buf[1],b,1,1,1,chprintf(buf[2],"arctg(%s)",polynomial(buf[3],2,a,"x",-1,"")), false),
        polynomial(buf[4],2, a*a,"x^2",-1,""),
        fraction(buf[5],b,1,2)
    );
    sprintf(src, "lim(x->1/a,(b*arctg(a*x-1))/(a^2*x^2-1))=b/2");
}

void lim349t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(true));
    polynomial(buf[1], 1,a,"x"); sprintf(buf[0],"cos(%s)",buf[1]);
    polynomial(buf[2], 1,b,"x"); sprintf(buf[1],"cos(%s)",buf[2]);
    sprintf(text, "lim(x->0, (%s-%s)/(x^2))=%s",
        a==0?"1":buf[0],
        b==0?"1":buf[1],
        fraction(buf[2],b*b-a*a,1,2)
    );
    sprintf(src, "lim(x->0,(cos(a*x)-cos(b*x))/(x^2))=(b^2-a^2)/2");
}

void lim3410t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    int a;
    do{
        a=rnd(r.f,r.t);
    }while (!(a!=0 && a!=1 && a!=-1));
    sprintf(text, "lim(x->%d, tg((pi*x)/(%d))*sin((x%s)/2))=%d/pi", a,2*a,(-a>0?((AnsiString)"+"+(-a)).c_str():AnsiString(-a).c_str()),-a);
    sprintf(src, "lim(x->a,tg((pi*x)/(2*a))*sin((x+a)/2))=-a/pi");
}

void lim3411t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && b!=0));
    chprintf(text, "lim(x->0, (1+cos(%s))/(1-cos(%s)))=inf",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],1,b,"x")
    );
    sprintf(src, "lim(x->0,(1+cos(a*x))/(1-cos(b*x)))=inf");
    
}

void lim3412t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a;
    do{
        a=rndr(r);
    }while (!(a!=0));
    chprintf(text, "lim(x->%s, arcsin(%s)/(%s))=-(1/2)",
        fraction(buf[9],1,1,a),
        polynomial(buf[0],2, 1,"",-a,"x"),
        polynomial(buf[1],2, a*a,"x^2",-1,"")
    );
    sprintf(src, "lim(x->1/a,arcsin(1-a*x)/(a^2*x^2-1))=-(1/2)");
    
}

void lim3413t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text,"");
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && b!=0));
    chprintf(text, "lim(x->pi, (1+cos(%s))/(1-cos(%s)))=%s",
        polynomial(buf[0],1, 2*a+1,"x"),
        polynomial(buf[1],1, 2*b, "x"),
        fraction(buf[2], pow(2*a+1,2),1,4*b*b)
    );
    sprintf(src, "lim(x->pi,(1+cos((2*a+1)*x))/(1-cos(2*b*x)))=(2*a+1)^2/(4*b^2)");
    
}

/////////////////////


void lim411t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1, a2,b2,c2, d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a2!=0 && 0<(float)a1/a2 && (float)a1/a2<1.0 && 0<a1 && a1<a2 && d>0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->+inf, %s)=0", buf[4]);
    sprintf(src, "lim(x->+inf,(!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2)))^(d*x))=0");
    rmvpar(text,text);
}

void lim412t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1,a2,b2,c2,d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a2!=0 && 0<(float)a1/a2 && (float)a1/a2<1.0 && 0<a1 && a1<a2 && d<0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->+inf, %s)=+inf", buf[4]);
    sprintf(src, "lim(x->+inf,(!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2)))^(d*x))=+inf");
    rmvpar(text,text);
}

void lim413t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1, a2,b2,c2, d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a2!=0 && 0<(float)a1/a2 && (float)a1/a2<1 && 0<a1 && a1<a2 && d>0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->-inf, %s)=+inf", buf[4]);
    sprintf(src, "lim(x->-inf,(!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2)))^(d*x))=+inf");
    rmvpar(text,text);
}

void lim414t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1,a2,b2,c2,d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a2!=0 && 0<(float)a1/a2 && (float)a1/a2<1 && 0<a1 && a1<a2 && d<0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->-inf, %s)=0", buf[4]);
    sprintf(src, "lim(x->-inf,(!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2)))^(d*x))=0");
    rmvpar(text,text);
}

void lim421t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1, a2,b2,c2, d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a1<a2 && a2<0 && d>0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->+inf, %s)=+inf", buf[4]);
    sprintf(src, "lim(x->+inf,(!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2)))^(d*x))=+inf");
    rmvpar(text,text);
}

void lim422t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1, a2,b2,c2, d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a1<a2 && a2<0 && d<0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->+inf, %s)=0", buf[4]);
    sprintf(src, "lim(x->+inf,(!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2)))^(d*x))=0");
    rmvpar(text,text);
}

void lim423t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1, a2,b2,c2, d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a1<a2 && a2<0 && d>0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->-inf, %s)=0", buf[4]);
    sprintf(src, "lim(x->-inf,(!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2)))^(d*x))=0");
    rmvpar(text,text);
}

void lim424t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1, a2,b2,c2, d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a1<a2 && a2<0 && d<0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->-inf, %s)=+inf", buf[4]);
    sprintf(src, "lim(x->-inf,(!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2)))^(d*x))=+inf");
    rmvpar(text,text);
}

void lim431t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1, a2,b2,c2, d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a1>a2 && a2>0 && d>0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->+inf, %s)=+inf", buf[4]);
    sprintf(src, "lim(x->+inf,(!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2)))^(d*x))=+inf");
    rmvpar(text,text);
}

void lim432t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1, a2,b2,c2, d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a1>a2 && a2>0 && d<0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->+inf, %s)=0", buf[4]);
    sprintf(src, "lim(x->+inf,(!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2)))^(d*x))=0");
    rmvpar(text,text);
}

void lim433t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1, a2,b2,c2, d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a1>a2 && a2>0 && d>0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->-inf, %s)=0", buf[4]);
    sprintf(src, "lim(x->-inf,(!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2)))^(d*x))=0");
    rmvpar(text,text);
}

void lim441t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,d,p,q;
    do
    {
        a=rndr(r); b=rndr(r); c=rndr(r);
        d=rndr(r); p=rndr(r); q=rndr(r);
    }while(!(a*c*p!=0));
    sprintf(text, "lim(x->+inf, !((%s)/(%s))^(%s))=0",
        polynomial(buf[0], 2,abs(a),"x",b,""),
        polynomial(buf[1], 2,abs(a)+abs(c),"x",d,""),
        polynomial(buf[2], 2,abs(p),"x",q,"")
    );
    sprintf(src, "lim(x->+inf,!((abs(a)*x+b)/((abs(a)+abs(c))*x+d))^(abs(p)*x+q))=0");
    
}

void lim442t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,d,p,q;
    do{
        a=rndr(r); b=rndr(r); c=rndr(r);
        d=rndr(r); p=rndr(r); q=rndr(r);
    }while (!(a*p*c!=0));
    sprintf(text, "lim(x->+inf, !((%s)/(%s))^(%s))=inf",
        polynomial(buf[0], 2, abs(a)+abs(c),"x",b,""),
        polynomial(buf[1], 2, abs(a),"x",d,""),
        polynomial(buf[2], 2, abs(p),"x",q,"")
    );
    sprintf(src, "lim(x->+inf,!(((abs(a)+abs(c))*x+b)/(abs(a)*x+d))^(abs(p)*x+q))=inf");
    
}

void lim451t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1,a2,b2,c2,p,q;
    do{
        a1=rndr(r); b1=rndr(r); c1=rndr(r);
        a2=rndr(r); b2=rndr(r); c2=rndr(r);
        p=rndr(range(1,4)); q=rndr(r);
    }while (!(a1!=0 && a2!=0 && a1*a2!=0 && p!=0));
    sprintf(text, "lim(x->+inf, !((%s)/(%s))^((%s)/(x+1)))=%s",
        polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,""),
        polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,""),
        polynomial(buf[2], 2, p,"x",q,""),
        fraction(buf[3],pow(a1,p),1,pow(a2,p))
    );
    sprintf(src, "lim(x->+inf,!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2))^(p*x+q))=a1^p/a2^p");
    
}

void lim461t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1,a2,b2,c2,p,q;
    do{
        a1=rndr(r); b1=rndr(r); c1=rndr(r);
        a2=rndr(r); b2=rndr(r); c2=rndr(r);
        p=rndr(range(1,4)); q=rndr(r);
    }while (!(a1!=0 && a2!=0 && a1*a2!=0 && p!=0));
    sprintf(text, "lim(x->+inf, !((%s)/(%s))^(%s))=e^(%s)",
        polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,""),
        polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,""),
        polynomial(buf[2], 1, p,"x"),
        fraction(buf[3],(b1-b2)*p,1,a1)
    );
    sprintf(src, "lim(x->+inf,!((a1*x^2+b1*x+c1)/(a2*x^2+b2*x+c2))^(p*x))=(b1-b2)^p/a1");
    
}

void lim462t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,d,p,q;
    do{
        a=rndr(r);
        b=rndr(r);
        d=rndr(r);
        p=rndr(r);
        q=rndr(r);
    }while (!(a!=0 && b!=d && (p!=0 || abs(q)>=2)));
    sprintf(text, "lim(x->+inf, (!((%s)/(%s))^(%s)))=%s",
        polynomial(buf[0], 2,a,"x",b,""),
        polynomial(buf[1], 2,a,"x",d,""),
        polynomial(buf[2], 2,p,"x",q,""),
        draw_e(buf[3], b*p-d*p, a)
    );
    sprintf(src, "lim(x->+inf,(!((a*x+b)/(a*x+d)))^(p*x+q))=e^((b*p-d*p)/a)");
    
}

void lim471t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    sprintf(text, "lim(x->1, !((3*x-1)/(x+1))&String(\"^\")&!(1/(root(3,x)-1)))=e^3");
    sprintf(src, "lim(x->1, !((3*x-1)/(x+1))&String(\"^\")&!(1/(root(3,x)-1)))=e^3");
    
}

void lim481t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        p=rndr(r);
    }while (!(a!=0 && p!=0 && p!=1 && a!=c && a*p*p*p+b!=0));
    sprintf(text, "lim(x->%d, !((%s)/(%s))&String(\"^\")&!(1/(%s)))=%s",
        p*p*p,
        polynomial(buf[0],2, a,"x",b,""),
        polynomial(buf[1],2, c,"x",a*p*p*p+b-c*p*p*p,""),
        polynomial(buf[2],2, 1,"root(3,x)",-p,""),
        draw_e(buf[3], 3*p*p*(a-c), a*p*p*p+b)
    );
    sprintf(src, "lim(x->p^3, !((a*x+b)/(c*x+a*p^3+b-c*p^3))^(1/(root(3,x)-p)))=e^((3*p^2*(a-c))/(a*p^3+b))");
    
}

void lim482t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text, "");
    int a,b,c,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        p=rndr(r);
    }while (!(a!=0 && p!=0 && p!=1 && a!=c && a*p*p+b!=0));
    sprintf(text, "lim(x->%d, !((%s)/(%s))&String(\"^\")&!(1/(%s)))=%s",
        p*p,
        polynomial(buf[0],2, a,"x",b,""),
        polynomial(buf[1],2, c,"x",a*p*p+b-c*p*p,""),
        polynomial(buf[2],2, 1,"sqrt(x)",-p,""),
        draw_e(buf[3], 2*p*(a-c), a*p*p+b)
    );
    sprintf(src, "lim(x->p^3, !((a*x+b)/(c*x+a*p^2+b-c*p^2))^(1/(sqrt(x)-p)))=e^((2*p*(a-c))/(a*p^2+b))");
    
}

void lim483t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ]; chprintf(text, "");
    int a,b,c,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        p=rndr(r);
    }while (!(a!=0 && p!=0 && p!=1 && a!=c && a*p+b));
    sprintf(text, "lim(x->%d, !((%s)/(%s))&String(\"^\")&!(1/(%s)))=%s",
        p,
        polynomial(buf[0],2, a,"x",b,""),
        polynomial(buf[1],2, c,"x",a*p+b-c*p,""),
        polynomial(buf[2],2, 1,"x",-p,""),
        draw_e(buf[3], a-c, a*p+b)
    );
    sprintf(src, "lim(x->p, !((a*x+b)/(c*x+a*p+b-c*p))^(1/(x-p)))=e^((a-c)/(a*p+b))");
    
}

void lim491t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,pc,pd;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        pc=rndr(r);
        pd=rndr(r);
    }while (!(a!=0 && pc<pd && pc*pd>0));
    sprintf(text, "lim(x->%s+0, !((%s)/(%s))&String(\"^\")&!(1/(%s)))=0",
        fraction(buf[9], pc*pc*pc, 1, pd*pd*pd),
        polynomial(buf[0],2, a,"x^2",b,"x"),
        poly2ns(buf[1],2, c,1,1,1,"x", a*pc*pc*pc+b*pd*pd*pd-c*pc*pc*pc,pd*pd*pd,1,1,""),
        poly2ns(buf[2],2, 1,1,1,1,"(x^(1/3))", -pc,pd,1,1,"")
    );
    sprintf(src, "lim(x->(p^3*c^3)/(p^3*d^3)+0, !((a*x^2+b*x)/(c*x+a*p^3*c^3+(b*p^3*d^3-c*p^3*c^3)/(p^3*d^3)))^(1/(x^(1/3)-(p*c)/(p*d))))=0");
    
}

void lim492t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        p=rndr(r);
    }while (!(a!=0 && p>1 && p!=1 && a!=c));
    sprintf(text, "lim(x->%d+0, !((%s)/(%s))&String(\"^\")&!(1/(%s)))=+inf",
        p*p*p,
        polynomial(buf[0],2, a,"x^2",b,"x"),
        polynomial(buf[1],2, c,"x",a*p*p*p+b-c*p*p*p,""),
        polynomial(buf[2],2, 1,"(x^(1/3))",-p,"")
    );
    sprintf(src, "lim(x->p^3+0, !((a*x^2+b*x)/(c*x+a*p^3-c*p^3))^(1/(x^(1/3)-p)))=+inf");
    
}

///////////5

void lim511t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while (!(a!=0 && b!=0));
    sprintf(text, "lim(x->inf, sin(%s)/(%s))=0",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],2,b,"x",c,"")
    );
    sprintf(src, "lim(x->inf, sin(a*x)/(b*x+c))=0");
    rmvpar(text,text);
}

void lim512t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while (!(a!=0 && b!=0));
    sprintf(text, "lim(x->inf, (%s)/cos(%s))=inf",
        polynomial(buf[1],2,b,"x",c,""),
        polynomial(buf[0],1,a,"x")
    );
    sprintf(src, "lim(x->inf, (b*x+c)/cos(a*x))=inf");
    rmvpar(text,text);
}

void lim513t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while (!(a!=0 && b!=0 && c!=0));
    sprintf(text, "lim(x->inf, (sin(%s)^2)/(%s))=0",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],3,b,"x^2",c,"x",d,"")
    );
    sprintf(src, "lim(x->inf, (sin(a*x)^2)/(b*x^2+c*x+d))=0");
    rmvpar(text,text);
}

void lim514t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while (!(a!=0 && b!=0 && c!=0));
    sprintf(text, "lim(x->inf, (%s)/(cos(%s)^2))=inf",
        polynomial(buf[1],3,b,"x^2",c,"x",d,""),
        polynomial(buf[0],1,a,"x")
    );
    sprintf(src, "lim(x->inf, (b*x^2+c*x+d)/(cos(a*x)^2))=inf");
    rmvpar(text,text);
}

void lim515t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,n;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        n=rndr(r);
    }while (!(a!=0 && b!=0 && c!=0 && n>1));
    sprintf(buf[1],"(1+cos(%s)^2)", polynomial(buf[0],1,a,"x"));
    sprintf(text, "lim(x->inf, (%s)/(%s))=0",
        memb(buf[9],1,1,1,n,buf[1],false),
        polynomial(buf[2],2,b,"x",c,"")
    );
    sprintf(src, "lim(x->inf, root(n,1+cos(a*x)^2)/(b*x+c))=0");
    rmvpar(text,text);
}

void lim516t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while (!(a!=0 && b!=0 && c!=0));
    sprintf(text, "lim(x->inf, (%s)/ln(1+sin(%s)^2))=inf",
        polynomial(buf[1],2,b,"x",c,""),
        polynomial(buf[0],1,a,"x")
    );
    sprintf(src, "lim(x->inf, (b*x+c)/ln(1+sin(a*x)^2))=inf");
    rmvpar(text,text);
}

void lim521t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while (!(0<b && b<a && c>0));
    sprintf(text, "lim(x->0+0,!(sin(%s)/tg(%s))^(%d/x))=+inf",
        polynomial(buf[1],1,a,"x"),
        polynomial(buf[0],1,b,"x"),
        c
    );
    sprintf(src, "lim(x->0+0, !(sin(a*x)/tg(b*x))^(c/x))=+inf");
    rmvpar(text,text);
}

void lim522t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while (!(0<b && b<a && c<0));
    sprintf(text, "lim(x->0,!(arcsin(%s)/tg(%s))^(%d/(x^2)))=0",
        polynomial(buf[1],1,a,"x"),
        polynomial(buf[0],1,b,"x"),
        c
    );
    sprintf(src, "lim(x->0, !(arcsin(a*x)/tg(b*x))^(c/(x^2)))=0");
    rmvpar(text,text);
}

void lim523t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,c;
    do{
        a=rndr(r);
        c=rndr(r);
    }while (!(a!=0 && c!=0));
    sprintf(text, "lim(x->0,!(1+sin(%s))^(1/(%s)))=%s",
        polynomial(buf[1],1,a,"x"),
        polynomial(buf[0],1,c,"x"),
        draw_e(buf[2],a,c)
    );
    sprintf(src, "lim(x->0, !(1+sin(a*x))^(1/(c*x)))=e^(a/c)");
    rmvpar(text,text);
}

void lim524t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,c;
    do{
        a=rndr(r);
        c=rndr(r);
    }while (!(a!=0 && c!=0));
    sprintf(text, "lim(x->0,!(1+arctg(%s))^(%d/x))=%s",
        poly2ns(buf[1],1, 1,a,1,1,"x"),
        c,
        draw_e(buf[2],c,a)
    );
    sprintf(src, "lim(x->0,!(1+arctg(x/a))^(c/x))=e^(c/a)");
    rmvpar(text,text);
}

void lim525t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,c;
    do{
        a=rndr(r);
        c=rndr(r);
    }while (!(a!=0 && c!=0));
    sprintf(text, "lim(x->1,!(1+arcsin(%s))^(1/(%s)))=%s",
        polynomial(buf[0],2, a,"x",-a,""),
        polynomial(buf[1],2, c,"x^2",-c,""),
        draw_e(buf[2],a,2*c)
    );
    sprintf(src, "lim(x->1, !(1+arcsin(a*(x-1)))^(1/(c*(x^2-1))))=e^(a/(2*c))");
    rmvpar(text,text);
}

void lim531t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,d,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
        p=rndr(r);
    }while (!(a>0 && b!=c && p!=0));
    sprintf(text, "lim(x->+inf, (%s)*(ln(%s)-ln(%s)))=%s",
        polynomial(buf[0],2, p,"x",d,""),
        polynomial(buf[1],2, a,"x",b,""),
        polynomial(buf[2],2, a,"x",c,""),
        fraction(buf[3], (b-c)*p,1,a)
    );
    sprintf(src, "lim(x->+inf, (p*x+d)*(ln(a*x+b)-ln(a*x+c)))=((b-c)*p)/a");
    rmvpar(text,text);
}

void lim532t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,d,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
        p=rndr(r);
    }while (!(a>0 && b!=c && p!=0));
    sprintf(text, "lim(x->-inf, (%s)*(ln(%s)-ln(%s)))=%s",
        polynomial(buf[0],2, p,"x^2",d,""),
        polynomial(buf[1],2, a,"x^2",b,""),
        polynomial(buf[2],2, a,"x^2",c,""),
        fraction(buf[3], (b-c)*p,1,a)
    );
    sprintf(src, "lim(x->-inf, (p*x^2+d)*(ln(a*x^2+b)-ln(a*x^2+c)))=((b-c)*p)/a");
    rmvpar(text,text);
}

void lim533t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,d,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
        p=rndr(r);
    }while (!(a>0 && b!=c && p!=0));
    sprintf(text, "lim(x->+inf, (%s)*(ln(%s)-ln(%s)))=+inf",
        polynomial(buf[0],2, p,"x^2",d,""),
        polynomial(buf[1],2, a,"x",b,""),
        polynomial(buf[2],2, a,"x",c,"")
    );
    sprintf(src, "lim(x->+inf, (p*x^2+d)*(ln(a*x+b)-ln(a*x+c)))=+inf");
    rmvpar(text,text);
}

void lim541t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while (!(a!=0 && b!=0 && c!=0));
    sprintf(text, "lim(x->0, (e^(%s)-1)/(sin(%s)*ln(%s)))=%s",
        polynomial(buf[0],1, a,"x^2"),
        polynomial(buf[1],1, b,"x"),
        polynomial(buf[2],2, 1,"",c,"x"),
        fraction(buf[3], a,1,b*c)
    );
    sprintf(src, "lim(x->0, (e^(a*x^2)-1)/(sin(b*x)*ln(1+c*x)))=a/(b*c)");
    rmvpar(text,text);
}

void lim542t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        p=rndr(r);
    }while (!(a!=0 && b!=0 && c!=0 && p>0));
    sprintf(text, "lim(x->0, ((%d)^(%s)-1)/(arctg(%s)*ln(%s)))=(%s)*ln(%d)",
        p,
        polynomial(buf[0],1, a,"x^2"),
        polynomial(buf[1],1, b,"x"),
        polynomial(buf[2],2, 1,"",c,"x"),
        fraction(buf[3], a,1,b*c),
        p
    );
    sprintf(src, "lim(x->0, (p^(a*x^2)-1)/(arctg(b*x)*ln(1+c*x)))=a/(b-c)*ln(p)");
    rmvpar(text,text);
}

void lim543t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && b!=0 && b!=1));
    sprintf(text, "lim(x->0, ln(%s)*(tg(%s+pi/2)^2))=%s",
        polynomial(buf[0],2, a,"x^2",1,""),
        polynomial(buf[1],1, b,"x"),
        fraction(buf[3], a,1,b*b)
    );
    sprintf(src, "lim(x->0, ln(a*x^2+1)*(tg(b*x)^2))=a/(b^2)");
    rmvpar(text,text);
}

void lim544t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while (!(a!=0 && b!=0 && c!=0));
    sprintf(text, "lim(x->0, x*ln(%s)/(sin(%s)*arctg(%s)))=%s",
        polynomial(buf[0],2, 1,"",-a,"x"),
        polynomial(buf[1],1, b,"x"),
        polynomial(buf[2],1, c,"x"),
        fraction(buf[3], -a,1,b*c)
    );
    sprintf(src, "lim(x->0, x*ln(1-a*x)/(sin(b*x)*arctg(c*x)))=-a/(b*c)");
    rmvpar(text,text);
}

void lim545t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while (!(a!=0 && b!=0 && p>0 && p!=1));
    sprintf(text, "lim(x->0, log(%d,1-sin(%s))/(e^(%s)-1))=%s",
        p,
        polynomial(buf[0],1, a,"x"),
        polynomial(buf[1],1, b,"tg(x)"),
        memb(buf[2], -a,b,-1,1,chprintf(buf[5],"ln(%d)",p), false)
    );
    sprintf(src, "lim(x->0, log(p,1-sin(a*x))/(e^(b*tg(x))-1))=-a/(b*ln(p))");
    rmvpar(text,text);
}

void lim546t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while (!(a!=0 && b!=0 && p>0 && p!=1));
    sprintf(text, "lim(x->0, ln(1+sin(%s))/((%d)^(%s)-1))=%s",
        polynomial(buf[0],1, a,"x"),
        p,
        polynomial(buf[1],1, b,"tg(x)"),
        memb(buf[2], a,b,-1,1,chprintf(buf[5],"ln(%d)",p), false)
    );
    sprintf(src, "lim(x->0, ln(1+sin(a*x))/(p^(b*tg(x))-1))=a/(b*ln(p))");
    rmvpar(text,text);
}

void lim547t (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,p;
    do{
        a=rndr(r);
        p=rndr(r);
    }while (!(a!=0 && p>0 && p!=1));
    sprintf(text, "lim(x->inf, x^2*log(%d,2-cos(%s)))=(%s)*((pi^2)/ln(%d))",
        p,
        polynomial(buf[0],1, a,"pi/x"),
        fraction(buf[1], a*a,1,2),
        p
    );
    sprintf(src, "lim(x->inf, x^2*log(p,2-cos(a*pi/x)))=(a^2/2)*((pi^2)/ln(p))");
    rmvpar(text,text);
}









void split_lim (const char *all, char *lim, char *sol)
{
    for(int i=0; i<strlen(all); ++i)
        if (*(all+i)=='=')
        {
            strncpy(lim,all,i);
            lim[i]='\0';
            strcpy(sol,all+i+1);
            return;
        }
    ShowMessage("Warning!\nSolution not found!");
    strcpy(lim,all);
    strcpy(sol,"");
    return;
}
















/* * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *           a1*x^2 - a1*(b+c)x + a1*b*c   a1*(b-c)
 *     lim   --------------------------- = --------
 *     x->a  a2*x^2 - a2*(b+d)x + a2*b*d   a2*(b-d)
 *
 *  - - - - - - - - - - - - - - - - - - - - - - - -
 *
 *   a1, a2, b-d <> 0;
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/*
void lim03 (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][100];
    int a1,a2,b,c,d;
    do{
        a1=rnd(r.f,r.t);
        a2=rnd(r.f,r.t);
        b=rnd(r.f,r.t);
        c=rnd(r.f,r.t);
        d=rnd(r.f,r.t);
    }while (!(a1!=0 && a2!=0 && b-d!=0));
    sprintf(text, "lim(x->%d, (%s)/(%s))=%s",
        b,
        polynomial(buf[0], 3,a1,"x^2",-a1*(b+c),"x",a1*b*c,""),
        polynomial(buf[1], 3,a2,"x^2",-a2*(b+d),"x",a2*b*d,""),
        fraction(buf[2], a1*(b-c),1,a2*(b-d))
    );
    
}
*/



























void lim20 (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && b!=0));
    sprintf(text, "lim(x->0, sin(%s)/atan(%s))=%s",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],1,b,"x"),
        fraction(buf[2], a,1,b)
    );
    
}


void lim21 (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        b=rndr(r);
        a=rndr(r);
    }while (!(b!=0));
    sprintf(text, "lim(x->pi, (1+cos(%s))/(1-cos(%s)))=%s",
        polynomial(buf[1], 1, 2*a+1,"x"),
        polynomial(buf[2], 1, 2*b,"x"),
        fraction(buf[0], pow(2*a+1,2),1,4*b*b)
    );
    
}


void lim22 (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a;
    do{
        a=rndr(r);
    }while (!(a!=0));
    sprintf(text, "lim(x->0,(1-cos(%s)/(x^2)))=%d",
        polynomial(buf[0], 1,2*a,"x"),
        2*a*a
    );
    
}


void lim23 (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,p;
    do{
        a=rnd(r.f,r.t);
        b=rnd(r.f,r.t);
        c=rnd(r.f,r.t);
        p=rnd(r.f,r.t);
    }while (!(a*p*p*p+b!=0 && a!=0 && c!=0));
    sprintf(text, "lim(x->%d,!((%s)/(%s))^(1/(%s)))=%s",
        p*p*p,
        polynomial(buf[0], 2, a,"x",b,""),
        polynomial(buf[1], 2, c,"x",(a*p*p*p+b-c*p*p*p),""),
        polynomial(buf[2], 2, 1,"x^(1/3)",-p,""),
        draw_e(buf[3], 3*p*p*(a-c), a*p*p*p+b)
    );
    
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                           1                                 1
 *                                      -----------                   ------------------
 *          /        a*x^2 + b        \ x^(1/3) - p     / a*p^6 + b \ p*(sign(p^(4/3))-1)
 *   lim   |   ----------------------  |             = |  ---------  |
 *  x->p^3  \  cx + a*p^3 + b - c*p^3 /                 \ a*p^3 + b /
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 /*
void lim24 (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a,b,c,p;
    do{
        a=rnd(r.f,r.t);
        b=rnd(r.f,r.t);
        c=rnd(r.f,r.t);
        p=rnd(r.f,r.t);
    }while (!(p>0 && a*p*p*p+b!=0 && p*(sgn(pow(p,4.0/3.0))-1)!=0));
    sprintf(text, "lim(x->%d, ((%s)/(%s))^(1/(%s)))=(%s)^(%s)",
        p*p*p,
        polynomial(buf[0], 2,a,"x^2",b,""),
        polynomial(buf[4], 2,c,"x",a*p*p*p+b-c*p*p*p,""),
        polynomial(buf[1], 2,1,"x^(1/3)",-p,""),
        fraction(buf[2], a*pow(p,6)+b, 1, a*p*p*p+b),
        fraction(buf[3], 1,1,p*(sgn(pow(p,4.0/3.0))-1))
    );
    
}
*/












































void limddd (const range& r, char *text, char answ[][BUFSZ], char *src)
{
    char buf[10][BUFSZ];
    int a1,b1,c1, a2,b2,c2, d;
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a1>a2 && a2>0 && d<0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(!(%s))^(%s)", buf[2],buf[3]);
    sprintf(text, "lim(x->-inf, %s)=+inf", buf[4]);
}


/*
void lim901 (int&a1,int&b1,int&c1,int&a2,int&b2,int&c2,int&d, const range& r, char *text)
{
    char buf[10][BUFSZ];
    do{
        a1=rndr(r), b1=rndr(r), c1=rndr(r);
        a2=rndr(r), b2=rndr(r), c2=rndr(r);
        d=rndr(r);
    }while (!(a1>a2 && a2>0 && d<0));
    polynomial(buf[0], 3, a1,"x^2",b1,"x",c1,"");
    polynomial(buf[1], 3, a2,"x^2",b2,"x",c2,"");
    sprintf(buf[2], "(%s)/(%s)", buf[0], buf[1]);
    polynomial(buf[3], 1, d, "x");
    sprintf(buf[4], "(%s)^(%s)", buf[2],buf[3]);

    sprintf(text, "lim(x->+inf, %s)=+inf", buf[4]);
    rmvpar(text,text);
}
*/




