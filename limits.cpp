#include <stdarg.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vcl.h>

int rnd (int from, int to) { return rand()%(to-from+1)+from; }
int sgn (int a) { return a>0? 1 : (a<0?-1:0); }

char *polynomial (char *buf, int n, ...)
{
    int count;
   	int v[100];
	char t[100][1000];
	count=n;
	va_list ap;
	va_start(ap, n);
	for(int i=0; i<n; ++i)
	{
		v[i]=va_arg(ap, int);
		strcpy(t[i],va_arg(ap, char*));
	}
	va_end(ap);

	bool sg=false;
	strcpy(buf, "");
	char tm[1000];

	for(int i=0; i<count; ++i)
	{
		if (!strcmp(t[i],""))
		{
  			if (sg)
				switch(v[i])
				{
					case 1: strcat(buf, "+1"); break;
					case -1: strcat(buf, "-1"); break;
					case 0: ; break;
					default:
						if (v[i]<0) { sprintf(tm, "%d", v[i]); strcat(buf, tm); }
                        else { sprintf(tm, "+%d", v[i]); strcat(buf, tm); }
                    break;
                }
            else
            {
                sg=true;
   				switch(v[i])
   				{
   					case 1: strcat(buf, "1"); break;
   					case -1: strcat(buf, "-1"); break;
   					case 0: sg=false; break;
   					default:
   						if (v[i]<0) { sprintf(tm, "%d", v[i]); strcat(buf, tm); }
   						else { sprintf(tm, "%d", v[i]); strcat(buf, tm); }
   					break;
   				}
            }
        }
   		else
   		{
   			if (sg)
   				switch(v[i])
   				{
   					case 1: { sprintf(tm, "+%s", t[i]); strcat(buf, tm); } break;
   					case -1: { sprintf(tm, "-%s", t[i]); strcat(buf, tm); } break;
   					case 0: ; break;
   					default:
   						if (v[i]<0) { sprintf(tm, "%d*%s", v[i], t[i]); strcat(buf,tm); }
   						else { sprintf(tm, "+%d*%s", v[i], t[i]); strcat(buf,tm); }
   					break;
   				}
   			else
   			{
   				sg=true;
   				switch(v[i])
   				{
   					case 1: { sprintf(tm, "%s", t[i]); strcat(buf, tm); } break;
   					case -1: { sprintf(tm, "-%s", t[i]); strcat(buf, tm); } break;
   					case 0: sg=false; break;
   					default:
   						if (v[i]<0) { sprintf(tm, "%d*%s", v[i], t[i]); strcat(buf,tm); }
   						else { sprintf(tm, "%d*%s", v[i], t[i]); strcat(buf,tm); }
   					break;
   				}
   			}
   		}
    }
    if (!sg) sprintf(buf,"0");
    return buf;
};

void simplify_product (int rat, int irr, int&rrat,int&rirr)
{
    for(int i=irr/2; i>=4; --i)
        do
            if (irr%i==0 && fabs(sqrt(i)-(int)sqrt(i))<0.0001)
                rat*=sqrt(i), irr/=i;
            else break;
        while(true);
    rrat=rat;
    rirr=irr;
}

void simplifyfrac (int &coeff, int &root, int &div)
{
    if (root%(div*div)==0)
    {
        root/=div*div;
        div=div<0? (-1) : (1);
    }
    if (div<0) div=-div, coeff=-coeff;
    if (fabs((int)sqrt(coeff*coeff*root)-sqrt(coeff*coeff*root))<0.00001)
    {
        if (coeff<0) div=-div;
        coeff=sqrt(coeff*coeff*root);
        if (div<0) coeff=-coeff, div=-div;
        root=1;
    }
    if (root>1)
        simplify_product(coeff,root, coeff,root);
        /*
        for(int i=root/2; i>=4; --i)
            do
                if (root%i==0 && fabs(sqrt(i)-(int)sqrt(i))<0.0001)
                    coeff*=sqrt(i), root/=i;
                else break;
            while(true);
        */
    for(int i=div; i>=2; --i)
        do
            if (coeff%i==0 && div%i==0)
                coeff/=i, div/=i;
            else break;
        while(true);
}

char *fraction (char *res, int coeff, int root, int div)
{
    simplifyfrac(coeff, root, div);
    if (coeff==0)
        sprintf(res,"0");
    else if (div==1)
    {
        if (root==1)
        {
            if (coeff==1) sprintf(res, "1");
            else if (coeff==-1) sprintf(res, "-1");
            else sprintf(res, "%d", coeff);
        }
        else
        {
            if (coeff==1) sprintf(res, "sqrt(%d)", root);
            else if (coeff==-1) sprintf(res, "-sqrt(%d)", root);
            else sprintf(res, "%d*sqrt(%d)", coeff, root);
        }
    }
    else
    {
        if (root==1)
            if (coeff>0) sprintf(res, "%d/%d", coeff, div);
            else sprintf(res, "-(%d/%d)", -coeff, div);
        else
        {
            if (coeff==1) sprintf(res, "sqrt(%d)/%d", root, div);
            else if (coeff==-1) sprintf(res, "-(sqrt(%d)/%d)", root, div);
            else if (coeff>0) sprintf(res, "%d*sqrt(%d)/%d", coeff, root, div);
            else if (coeff<0) sprintf(res, "-(%d*sqrt(%d)/%d)", abs(coeff), root, div);
        }
    }
    return res;
}

struct range
{
    range() {}
	range (const int from, const int to): f(from), t(to) {}
	int f,t;
};

char *draw_coeff (char *buf, int coeff, bool sign=false)
{
    if (coeff==1) sprintf(buf,"%s",(sign?"+":""));
    else if (coeff==-1) sprintf(buf,"-");
    else sprintf(buf,"%s%d*",(sign && coeff>0?"+":""),coeff);
    return buf;
}

char *draw_sum1 (char *buf, int r1, int i1, int r2, int i2)
{
    simplifyfrac(r1,i1,1);
    simplifyfrac(r2,i2,1);
    if ((r1==0 && r2==0) || (i1==0 && i2==0))
        strcpy(buf,"0");
    else if (i1==1 && i2==1)
        sprintf(buf,"%d",r1+r2);
    else if (i1==i2)
    {
        int r=r1+r2;
        char b[1000];
        if (r==0) sprintf(buf,"0");
        else sprintf(buf,"%ssqrt(%d)",draw_coeff(b,r),i1);
    }
    else
    {
        char b[10][1000];
        char r[10][1000];
        int sign=true;

        if (r1==0) { sprintf(r[0],""); sign=false; }
        else if (i1==1) sprintf(r[0],"%d", r1);
        else sprintf(r[0],"%ssqrt(%d)",draw_coeff(b[0],r1), i1);

        if (r2==0)
            if (sign) strcpy(r[1],"");
            else strcpy(r[1],"0");
        else if (i2==1)
            if (r2>0) sprintf(r[1],"%s%d", (sign?"+":""), r2);
            else sprintf(r[1],"%d",r2);
        else
            sprintf(r[1],"%ssqrt(%d)",draw_coeff(b[1],r2,sign), i2);
        sprintf(buf,"%s%s",r[0],r[1]);
    }
    /*
    else if (r1==1)
    {
        if (i2==1) sprintf(buf, "%d", r2);
        else
        {
            if (r2==1) sprintf(buf,"sqrt(%d)",i2);
            else if (r2==-1) sprintf(buf, "-sqrt(%d)", i2);
            else sprintf(buf,"%d*sqrt(%d)", r2,i2);
        }
    }
    else if (r2==1)
    {
        if (i1==1) sprintf(buf, "%d", r1);
        else
        {
            if (r1==1) sprintf(buf,"sqrt(%d)",i1);
            else if (r1==-1) sprintf(buf, "-sqrt(%d)", i1);
            else sprintf(buf,"%d*sqrt(%d)", r1,i1);
        }
    }
    else
    {
        char buf1[100],buf2[100];
        if (i1==1) sprintf(buf1, "%d", r1);
        else
        {
            if (r1==1) sprintf(buf1,"sqrt(%d)",i1);
            else if (r1==-1) sprintf(buf1, "-sqrt(%d)", i1);
            else sprintf(buf1,"%d*sqrt(%d)", r1,i1);
        }
        if (i2==1)
            if (r2<0) sprintf(buf2, "%d", r2);
            else sprintf(buf2, "+%d", r2);
        else
        {
            if (r2==1) sprintf(buf2,"+sqrt(%d)",i2);
            else if (r2==-1) sprintf(buf2, "-sqrt(%d)", i2);
            else
                if (r2>0) sprintf(buf2,"+%d*sqrt(%d)", r2,i2);
                else sprintf(buf2,"%d*sqrt(%d)", r2,i2);
        }
        strcpy(buf,strcat(buf1,buf2));
    }
    */
    return buf;
}

//////////////////////////////////////////////////////////////////////////////////////////////
/**   limit generators      */
//////////////////////////////////////////////////////////////////////////////////////////////

char *lim01 (int&a, int&b, int&c, int&d, int&e,  const range& r, char *text)
{
    char buf[10][100];
    do{
        a=rnd(r.f,r.t); b=rnd(r.f,r.t); c=rnd(r.f,r.t);
        d=rnd(r.f,r.t); e=rnd(r.f,r.t);
    }while(c-e==0 || d-e==0);
    sprintf(text, "lim(x->%d,(%s)/(%s))=%s",
        e,
        polynomial(buf[0], 3,1,"x^2",-(a+b),"x",a*b,""),
        polynomial(buf[1], 3,1,"x^2",-(c+d),"x",c*d,""),
        fraction(buf[2], (a-e)*(b-e),1,(c-e)*(d-e))
    );
    return text;
}


char *lim02 (int&a, int&b, int&c, const range& r, char *text)
{
    char buf[10][100];
    do{
        a=rnd(r.f,r.t);b=rnd(r.f,r.t);c=rnd(r.f,r.t);
    }while (a-c==0);
    sprintf(text, "lim(x->%d, (%s)/(%s))=%s",
        a,
        polynomial(buf[0], 3,1,"x^2",-(a+b),"x",a*b,""),
        polynomial(buf[1], 3,1,"x^2",-(a+c),"x",a*c,""),
        fraction(buf[2], a-b,1,a-c)
    );
    return text;
}


char *lim03 (int&a1,int&a2,int&b,int&c,int&d, const range& r, char *text)
{
    char buf[10][100];
    do{
        a1=rnd(r.f,r.t);a2=rnd(r.f,r.t);b=rnd(r.f,r.t);c=rnd(r.f,r.t);d=rnd(r.f,r.t);
    }while (a1==0 || a2==0 || b-d==0);
    sprintf(text, "lim(x->%d, (%s)/(%s))=%s",
        b,
        polynomial(buf[0], 3,a1,"x^2",-a1*(b+c),"x",a1*b*c,""),
        polynomial(buf[1], 3,a2,"x^2",-a2*(b+d),"x",a2*b*d,""),
        fraction(buf[2], a1*(b-c),1,a2*(b-d))
    );
    return text;
}


char *lim04 (int&a1,int&b1,int&c1,int&a2,int&b2,int&c2, const range& r, char *text)
{
    char buf[10][100];
    do{
        a1=rnd(r.f,r.t), b1=rnd(r.f,r.t), c1=rnd(r.f,r.t);
        a2=rnd(r.f,r.t), b2=rnd(r.f,r.t), c2=rnd(r.f,r.t);
    }while(a2==0 || a1==0);
    sprintf(text, "lim(x->inf,(%s)/(%s))=%s",
        polynomial(buf[0], 3,a1,"x^2",b1,"x",c1,""),
        polynomial(buf[1], 3,a2,"x^2",b2,"x",c2,""),
        fraction(buf[2], a1,1,a2)
    );
    return text;
}


char *lim05 (int &a1,int &b1,int &c1,  int &a2,int &b2,int &c2,  const range &r,  char *text)
{
	char buf[10][1000];
	do { a1=rnd(r.f, r.t); a2=rnd(r.f, r.t); } while (a1==0 || a2==0);
	b1=rnd(r.f, r.t);b2=rnd(r.f, r.t);
	c1=rnd(r.f, r.t);c2=rnd(r.f, r.t);
	sprintf(text, "lim(x->inf, (%s)/(%s))=0",
        polynomial(buf[0], 3, a1,"x^2", b1,"x", c1,""),
        polynomial(buf[1], 3, a2,"x^3",b2,"x",c2,"")
    );
	return text;
}


char *lim06 (int &a1,int &b1,int &c1,  int &a2,int &b2,int &c2,  const range &r,  char *text)
{
	char buf[5][1000];
	a1=rnd(r.f, r.t);
	do { a1=rnd(r.f, r.t); a2=rnd(r.f, r.t); } while (a1==0 || a2==0);
	b1=rnd(r.f, r.t);b2=rnd(r.f, r.t);
	c1=rnd(r.f, r.t);c2=rnd(r.f, r.t);
	sprintf(text, "lim(x->inf, (%s)/(%s))=%s", polynomial(buf[0], 3, a1,"x^3", b1,"x", c1,""), polynomial(buf[1], 3,a2,"x^2",b2,"x",c2,""), strcat(strcpy(buf[2],(sgn(a1*a2)==-1?"-":"+")),"inf") );
	return text;
}


char *lim07 (int &b,int &c,int &d,  const range &r,  char *text)
{
	char buf[10][1000];
	do { d=rnd(r.f, r.t); } while (d==0);
	b=rnd(r.f, r.t);
	c=rnd(r.f, r.t);
	sprintf(text, "lim(x->%d, (%s)/(sqrt(%s)-sqrt(%s)))=%d",
        abs(d*d)+c,
        polynomial(buf[0], 3, 1,"x^2", -(abs(d*d)+b+c),"x", (b*abs(d*d)+b*c),""),
        polynomial(buf[1], 2, 1,"x", -c,""),
        polynomial(buf[2], 2, c+abs(2*d*d),"",-1,"x"),
        -(b-c-d*d)*abs(d)
    );
	return text;
}


char *lim08 (int &a, int &b, const range& r, char *text)
{
    char buf[10][1000];
    a=rnd(r.f, r.t);
    b=rnd(r.f, r.t);
    sprintf(text, "lim(x->+inf, (x*(sqrt(%s)-sqrt(%s))))=%s",
        polynomial(buf[0], 2,a,"",1,"x^2"),
        polynomial(buf[1], 2,b,"",1,"x^2"),
        fraction(buf[2], a-b,1,2)
    );
    return text;
}


char *lim09 (int &a, int &b, const range& r, char *text)
{
    char buf[10][1000];
    a=rnd(r.f, r.t);
    b=rnd(r.f, r.t);
    sprintf(text, "lim(x->-inf, (x*(sqrt(%s)-sqrt(%s))))=%s",
        polynomial(buf[0],2,a,"",1,"x^2"),
        polynomial(buf[1],2,b,"",1,"x^2"),
        fraction(buf[2], b-a,1,2)
    );
    return text;
}


char *lim10 (int &a,int &b,int &c,  const range &r,  char *text)
{
    char buf[10][1000];
    do a=rnd(r.f, r.t); while(a<=0); b=rnd(r.f, r.t); c=rnd(r.f, r.t);
    polynomial(buf[1], 3, a*a,"x^2", b,"x", c,"");
    sprintf(buf[0],"sqrt(%s)",buf[1]);
    polynomial(buf[1], 2, 1,buf[0], -a,"x");
    sprintf(text, "lim(x->+inf, %s)=%s",
        buf[1],
        fraction(buf[2], b,1,2*a)
    );
    return text;
}


char *lim11 (int &a,int &b,int &c,  const range &r,  char *text)
{
    char buf[10][1000];
    do a=rnd(r.f, r.t); while (a<=0); b=rnd(r.f, r.t); c=rnd(r.f, r.t);
    polynomial(buf[1], 3, a*a,"x^2", b,"x", c,"");
    sprintf(buf[0],"sqrt(%s)",buf[1]);
    polynomial(buf[1], 2, 1,buf[0], -a,"x");
    sprintf(text, "lim(x->-inf, %s)=inf", buf[1]);
    return text;
}

/*
char *lim12 (int &a, int &b, int &d, int &p, int &q,  const range &r,  char *text)
{
    char buf[10][1000];
    do{
        a=rnd(r.f, r.t); b=rnd(r.f, r.t);
        d=rnd(r.f, r.t); p=rnd(r.f, r.t); q=rnd(r.f, r.t);
    }while (a==0 || b==d || b*p-d*p==a);
    do { p=rnd(r.f, r.t); q=rnd(r.f, r.t); } while (p==0 || q==0);
    sprintf(text, "lim(x->+inf, (!((%s)/(%s))^(%s)))=e^(%s)",
        polynomial(buf[0], 2,a,"x",b,""),
        polynomial(buf[1], 2,a,"x",d,""),
        polynomial(buf[2], 2,p,"x",q,""),
        fraction(buf[3], b*p-d*p,1,a)
    );
    return text;
}*/

char *lim12 (int &a, int &b, int &d, int &p, int &q,  const range &r,  char *text)
{
    char buf[10][1000];
    do{
        a=rnd(r.f, r.t);
        b=rnd(r.f, r.t);
        d=rnd(r.f, r.t);
        p=rnd(r.f, r.t);
        q=rnd(r.f, r.t);
    }while (a==0 || b==d);// || b*p-d*p==a);
    if (b*p-d*p==0)
        strcpy(buf[4],"1");
    else if (b*p-d*p==a)
        strcpy(buf[4],"e");
    else
        sprintf(buf[4],"e^(%s)",fraction(buf[3], b*p-d*p,1,a));
    sprintf(text, "lim(x->+inf, (!((%s)/(%s))^(%s)))=%s",
        polynomial(buf[0], 2,a,"x",b,""),
        polynomial(buf[1], 2,a,"x",d,""),
        polynomial(buf[2], 2,p,"x",q,""),
        buf[4]
    );
    return text;
}


char *lim13 (int& a,int& b,int& c,int& d,int& p,int& q,  const range& r,  char *text)
{
    char buf[10][1000];
    do
    {
        a=rnd(r.f, r.t); b=rnd(r.f, r.t); c=rnd(r.f, r.t);
        d=rnd(r.f, r.t); p=rnd(r.f, r.t); q=rnd(r.f, r.t);
    }while( a*c*p==0 );
    sprintf(text, "lim(x->+inf, !((%s)/(%s))^(%s))=0",
        polynomial(buf[0], 2,abs(a),"x",b,""),
        polynomial(buf[1], 2,abs(a)+abs(c),"x",d,""),
        polynomial(buf[2], 2,abs(p),"x",q,"")
    );
    return text;
}


char *lim14 (int&a,int&b,int&c,int&d,int&p,int&q, const range& r, char *text)
{
    char buf[10][1000];
    do{
        a=rnd(r.f, r.t); b=rnd(r.f, r.t); c=rnd(r.f, r.t);
        d=rnd(r.f, r.t); p=rnd(r.f, r.t); q=rnd(r.f, r.t);
    }while (a*p*c==0);
    sprintf(text, "lim(x->+inf, !((%s)/(%s))^(%s))=inf",
        polynomial(buf[0], 2, abs(a)+abs(c),"x",b,""),
        polynomial(buf[1], 2, abs(a),"x",d,""),
        polynomial(buf[2], 2, abs(p),"x",q,"")
    );
    return text;
}


char *lim15 (int&a,int&b, const range& r, char *text)
{
    char buf[10][1000];
    a=rnd(r.f, r.t); b=rnd(r.f, r.t);
    polynomial(buf[1], 1,a,"x"); sprintf(buf[0],"cos(%s)",buf[1]);
    polynomial(buf[2], 1,b,"x"); sprintf(buf[1],"cos(%s)",buf[2]);
    sprintf(text, "lim(x->0, (%s-%s)/(x^2))=%s",
        a==0?"1":buf[0],
        b==0?"1":buf[1],
        fraction(buf[2],b*b-a*a,1,2)
    );
    return text;
}


char *lim16 (int &a, const range& r, char *text)
{
    do a=rnd(r.f,r.t); while (a==0);
    sprintf(text, "lim(x->%d, tg((pi*x)/(%d))*sin((x%s)/2))=%d/pi", a,2*a,(-a>0?((AnsiString)"+"+(-a)).c_str():AnsiString(-a).c_str()),-a);
    return text;
}


char *lim17 (int &a, const range& r, char *text)
{
    char buf[3][1000];
    do a=rnd(r.f,r.t); while(a<=0);
    sprintf(text, "lim(h->0, (sqrt(%d+h)-%s)/h)=%s",
        a,
        fraction(buf[0],1,a,1),
        fraction(buf[1],1,a,2*a) //?
    );
    return text;
}


char *lim18 (int &a, int&n, const range& ar, char *text)
{
    char buf[10][1000];
    n=rnd(2,4); do a=rnd(ar.f,ar.t); while (a<=0);
    sprintf(text, "lim(x->0, ((%s)^(1/%d)-1)/(x))=%s",
        polynomial(buf[0], 2,a,"x",1,""),
        n, // don't need to use fraction - n!=1
        fraction(buf[1],a,1,n)
    );
    return text;
}


char *lim19 (int&a,int&b,int&c, char *text)
{
    char buf[5][100];
    a=rnd(1,9); b=rnd(1,9); do c=rnd(-9,9); while(c==0);
    int r1,i1,r2,i2;
//    simplify_sum1(1,a, -1,b,  r1,i1, r2,i2);
    r1=1;i1=a;r2=-1;i2=b;
    sprintf(text, "lim(x->+inf, (sqrt(%s)-sqrt(%s))/(sqrt(x)))=%s",
        polynomial(buf[1],2, a,"x",c,""),
        polynomial(buf[2],1, b,"x"),
        draw_sum1(buf[0],r1,i1,r2,i2)
    );
    return text;
}


char *lim20 (int&a,int&b, const range& r, char *text)
{
    char buf[10][1000];
    do a=rnd(r.f,r.t); while (a==0);
    do b=rnd(r.f,r.t); while (b==0);
    sprintf(text, "lim(x->0, sin(%s)/atan(%s))=%s",
        polynomial(buf[0],1,a,"x"),
        polynomial(buf[1],1,b,"x"),
        fraction(buf[2], a,1,b)
    );
    return text;
}


char *lim21a (int&a,int&b, const range&r, char *text)
{
    char buf[10][1000];
    a=rnd(r.f,r.t); do b=rnd(r.f,r.t); while (b==0);
    sprintf(text, "lim(x->pi, (1+cos(%d*x))/(1-cos(%d*x)))=%s",
        2*a+1,
        2*b,
        fraction(buf[0], pow(2*a+1,2),1,4*b*b)
    );
    return text;
}


char *lim21b1 (int&a, const range& r, char *text)
{
    char buf[10][100];
    do a=rnd(r.f,r.t); while (a==0);
    sprintf(text, "lim(x->0,(1-cos(%s)/(x^2)))=%d",
        polynomial(buf[0], 1,2*a,"x"),
        2*a*a
    );
    return text;
}

/*
char *lim21b3 (int&a,int&b,int&c,int&p, const range& r, char *text)
{
    char buf[10][100];
    do{
        a=rnd(r.f,r.t);b=rnd(r.f,r.t);c=rnd(r.f,r.t);p=rnd(r.f,r.t);
    }while (a*p*p*p+b==0);
    sprintf(text, "lim(x->%d,!((%s)/(%s))^(1/(%s)))=e^(%s)",
        p*p*p,
        polynomial(buf[0], 2,a,"x",b,""),
        polynomial(buf[1], 2,c,"x",(a*p*p*p+b-c*p*p*p),""),
        polynomial(buf[2], 2,1,"x^(1/3)",-p,""),
        fraction(buf[3],3*p*p*(a-c),1,a*p*p*p+b)
    );
    return text;
}
*/



void split_lim (char *all, char *lim, char *sol)
{
    for(i=0; i<strlen(all); ++i)
        if (*(all+i)=='=')
        {
            strncpy(lim,all,i);
            strcpy(sol,all+i+1);
            return;
        }
    ShowMessage("Warning!\nSolution not found!");
    strcpy(lim,all);
    strcpy(sol,"");
    return;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
char *addline (TMemo *m, char *num, char *line)
{
//    if(m) m->Lines->Add(AnsiString(num)+".\t"+line);
    if(m) m->Lines->Add(line);
    return line;
}

void generate (TMemo *m)
{
	char buf[1000];
    range r;
    do r=range(rnd(-20,0),rnd(4,20)); while (r.f==r.t);
	int a1,b1,c1, a2,b2,c2, a,b,c,d,e, p,q, n;
    for(int i=0; i<100000; ++i)
    {
    addline(m, "--",draw_sum1(buf,rnd(-10,10),rnd(0,10),rnd(-10,10),rnd(0,10)));
    addline(m, "*1",lim01(a,b,c,d,e, r, buf));
    addline(m, "*2",lim02(a,b,c, r, buf));
    addline(m, "*3",lim03(a1,a2,b,c,d, r, buf));
    addline(m, "*4",lim04(a1,b1,c1,a2,b2,c2, r, buf));
    addline(m, "*5",lim05(a1,b1,c1,a2,b2,c2, r, buf));
    addline(m, "*6",lim06(a1,b1,c1,a2,b2,c2, r, buf));
    addline(m, "*7",lim07(b,c,d, r, buf));
    addline(m, "*8",lim08(b,c, r, buf));
    addline(m, "*9",lim09(a,b, r, buf));
    addline(m, "*10",lim10(a,b,c, r, buf));
    addline(m, "*11",lim11(a,b,c, r, buf));
    addline(m, "*12",lim12(a,b,d,p,q, r, buf));
    addline(m, "*13",lim13(a,b,c,d,p,q, r,buf));
    addline(m, "*14",lim14(a,b,c,d,p,q, r,buf));
    addline(m, "*15",lim15(a,b, r,buf));
    addline(m, "*16",lim16(a, r,buf));
    addline(m, "*17",lim17(a, r,buf));
    addline(m, "*18",lim18(a,n, r, buf));
    addline(m, "*19",lim19(a,b,c, buf));
    addline(m, "*20",lim20(a,b, r, buf));
    addline(m, "*21a",lim21a(a,b, r,buf));
    addline(m, "*21b1", lim21b1(a, r, buf));
    return;
    }
    ShowMessage("done");
}
*/
