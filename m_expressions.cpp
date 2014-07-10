#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <vcl.h>
#include "m_expressions.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   –азбивает текст на строки, раздел€ющиес€ \n
 *
 * * * * * * * * * * * * * * * * * * * * */
int split_str (char *str, char lines[20][BUFSZ])
{
    int line=0;
    char *ch;
    if (str[strlen(str)-1]!='\n')
        strcat(str,"\n");
    while(ch=strstr(str, "\n"))
    {
        strncpy(lines[line], str, ch-str);
        lines[line][ch-str]='\0';
        str=ch+1;
        line++;
    }
    return line;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   –азбивает текст на условие и ответы (разделитель -- SEP).
 *   —начала условие;
 *   ѕотом два сепаратора;
 *   ƒалее строки ответов, разделенные одним сепаратором.
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
int split_text (const char *wholetext, char text[BUFSZ], char answer[10][BUFSZ])
{
    char *ch, buf[BUFSZ];
    bool answers=false;
    int answeridx=0;
    char wtbuf[BUFSZ], *thewholetext=wtbuf;

    strcpy(thewholetext, wholetext);
    strcat(thewholetext, SEP);
    strcpy(text,"");
    while(ch=strstr(thewholetext, SEP))
    {
        strncpy(buf, thewholetext, ch-thewholetext);
        buf[ch-thewholetext]='\0';
        if (strcmp(buf,"")!=0)
        {
            if (!answers)
            {
                if (strncmp(buf, "String", 6)!=0)
                    rmvpar(buf,buf);
                catprintf(text, "%s", buf);
                catprintf(text, "\nString(\" \")\nString(\" \")\n");
            }
            else
            {
                chprintf(answer[answeridx], "%s", buf);
                catprintf(answer[answeridx], "\nString(\" \")\nString(\" \")\n");
                answeridx++;
            }
        }
        else
        {
            answers=true;
            answeridx=0;
        }
        thewholetext=ch+strlen(SEP);
    }
    rmvpar(text, text);
    for(int i=0; i<answeridx; ++i)
        rmvpar(answer[i], answer[i]);
    return answeridx;
}

void shuffle_answers (int n, char answ[10][BUFSZ], int& rightansw)
{
    char answ1[10][BUFSZ];
    bool used[10];
    int i,v;
    for(i=0; i<n; ++i)
        used[i]=false;
    for(i=0; i<n; ++i)
    {
        do v=rand()%n; while(used[v]); used[v]=true;
        strcpy(answ1[i], answ[v]);
        if (v==0) rightansw=i;
    }
    for(i=0; i<n; ++i)
        strcpy(answ[i],answ1[i]);
}

int rnd (int from, int to)
{
    return rand()%(to-from+1)+from;
}

bool fsq (int a)
{
    return ((int)pow((int)sqrt(a),2)==a*a);
}

int rndr (const range& r)
{
    return rnd(r.f,r.t);
}

int sgn (float a)
{
    return a>0? 1 : (a<0?-1:0);
}

char *polynomial (char *buf, int n, ...)
{
    int count;
   	int v[BUFSZ];
	char t[100][BUFSZ];
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
	char tm[BUFSZ];

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

char *divisor (char *res, int div, char *arg)
{
    if (div==1) return chprintf(res, "%s", arg);
    else if (div==-1) return chprintf(res, "-%s", arg);
    else return chprintf(res, "%s%s/%d", div<0?"-":"", arg, abs(div));
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

char *draw_coeff (char *buf, int coeff, bool sign)
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
        char b[BUFSZ];
        if (r==0) sprintf(buf,"0");
        else sprintf(buf,"%ssqrt(%d)",draw_coeff(b,r),i1);
    }
    else
    {
        char b[10][BUFSZ];
        char r[10][BUFSZ];
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
    return buf;
}

char *draw_e (char *buf, int coeff, int div)
{
    char buf1[BUFSZ];
    simplifyfrac(coeff, 1, div);
    if (coeff==0) strcpy(buf,"1");
    else if (coeff==div) strcpy(buf,"e");
    else sprintf(buf,"e^(%s)",fraction(buf1, coeff,1,div));
    return buf;
}

char *rmvpar (char *buf, char *pars)
{
    bool usechar[BUFSZ];
    for(int i=0; i<strlen(pars); ++i)
        usechar[i]=true;

    bool quoted=false;
    for(int i=1; i<strlen(pars); ++i)
        if (pars[i]=='\"')
            quoted=!quoted;
        else if (!quoted && pars[i]=='(')
        {
            int pc=1;
            int right=0;
            for(int j=i+1; j<strlen(pars); ++j)
            {
                if (pars[i]=='\"') quoted=!quoted;
                else if (!quoted)
                    switch(pars[j])
                    {
                        case '(': pc++; break;
                        case ')': pc--; if (pc==0) right=j; break;
                    }
                if (right) break;
            }
            if (pars[i-1]=='(' && pars[right+1]==')')
            {
                usechar[i]=false;
                usechar[right]=false;
            }
        }
    for(int i=0; i<strlen(pars); ++i)
        switch(pars[i])
        {
            case '\"':
                quoted=!quoted;
                break;
            case '(':
            {
                if (quoted) break;
                int pcnt=1;
                int leftpar=i;
                int rightpar=0;
                bool quoted=false;
                for(int j=i+1; j<strlen(pars); ++j)
                {
                    switch(pars[j])
                    {
                        case '\"': quoted=!quoted; break;
                        default:
                            if (quoted) break;
                            switch(pars[j])
                            {
                                case '(':
                                    pcnt++; break;
                                case ')':
                                    pcnt--;
                                    if (pcnt==0) rightpar=j;
                                    break;
                            }
                    }
                    if (rightpar) break;
                }
                bool rmv=true;
                if (leftpar==0 || !(isalnum(pars[leftpar-1]) || pars[leftpar-1]=='!'))
                {
                    for(int j=leftpar+1; j<rightpar-1; ++j)
                        if (!isalnum(pars[j]))
                        {
                            rmv=false;
                            break;
                        }
                }
                else
                    rmv=false;
                if (rmv)
                {
                    usechar[leftpar]=false;
                    usechar[rightpar]=false;
                }
            }
            break;
        }

    char pars1[BUFSZ];
    strcpy(pars1,pars);

    sprintf(buf,"");
    for(int i=0; i<strlen(pars1); ++i)
        if (usechar[i])
        {
            char st[2]={pars1[i],'\0'};
            strcat(buf,st);
        }
    if (*buf=='`')
        return buf;
    return buf;
}

char *depar (char *buf)
{
    if (buf[0]=='(' && buf[strlen(buf)-1]==')')
    {
        char buf1[BUFSZ];
        strcpy(buf1,buf+1);
        buf1[strlen(buf1)-1]='\0';
        strcpy(buf,buf1);
    }
    return buf;
}

char *product (char *buf, bool usedot, bool addsign, int n, ...)
{
    char dot[10]; strcpy(dot, usedot?"*.":"*");
    int count;
	char t[100][BUFSZ];

	count=n;
	va_list ap;
	va_start(ap, n);
	for(int i=0; i<n; ++i)
		strcpy(t[i],va_arg(ap, char*));
	va_end(ap);

    int sign=1; strcpy(buf,"");
    for(int i=0; i<count; ++i)
    {
        if (!strcmp(t[i],"0"))
        {
            strcpy(buf, "0");
            return buf;
        }
        else if (strcmp(t[i],"1"))
        {
            if (!strcmp(t[i],"-1"))
                sign=-sign;
            else
            {
                strcat(buf,"("), strcat(buf,t[i]), strcat(buf,")");
                strcat(buf,dot);
            }
        }
    }
    buf[strlen(buf)-2]='\0';

    char buf1[BUFSZ];
    strcpy(buf1,buf);
    if (sign==-1)
        sprintf(buf1,"-%s",buf);
    else if (addsign)
        sprintf(buf1,"+%s",buf);

    return rmvpar(buf,buf1);
}

void fracparts (char *bufc, char *bufd, int ratp, int irrp, char *expr)
{
    if (ratp%irrp==0)
        ratp=ratp/irrp, irrp=1;

    char excl[2]="";
    int par=0, pars[BUFSZ]={false};
    for(int i=0; i<strlen(expr); ++i)
    {
        if (expr[i]=='(')
        {
            ++par;
            pars[par] = (i!=0 && isalnum(expr[i-1])) || pars[par-1];
        }
        if (expr[i]==')') --par;
        if (expr[i]=='/' && !pars[par])
        {
            strcpy(excl,"!");
            break;
        }
    }

    if (ratp*irrp<0)
    {
        ratp=-abs(ratp), irrp=abs(irrp);
        strcpy(bufc,"");
        if (irrp==1)
            if (ratp==-1) sprintf(bufd,"%s", expr);
            else sprintf(bufd,"(%s(%s))^%d", excl, expr, -ratp);
        else if (irrp==2)
            if (ratp==-1) sprintf(bufd, "sqrt(%s)", expr);
            else sprintf(bufd, "sqrt((%s(%s))^%d)", excl, expr, -ratp);
        else
            if (ratp==-1) sprintf(bufd, "root(%d, %s)", irrp, expr);
            else sprintf(bufd, "root(%d,(%s(%s))^%d)", irrp, excl, expr, -ratp);
    }
    else if (ratp*irrp==0)
    {
        strcpy(bufc, "");
        strcpy(bufd, "");
    }
    else if (ratp*irrp>0)
    {
        ratp=abs(ratp), irrp=abs(irrp);
        strcpy(bufd,"");
        if (irrp==1)
            if (ratp==1) sprintf(bufc,"%s", expr);
            else sprintf(bufc,"(%s(%s))^%d", excl, expr, ratp);
        else if (irrp==2)
            if (ratp==1) sprintf(bufc, "sqrt(%s)", expr);
            else sprintf(bufc, "sqrt((%s(%s))^%d)", excl, expr, ratp);
        else
            if (ratp==1) sprintf(bufc, "root(%d, %s)", irrp, expr);
            else sprintf(bufc, "root(%d,(%s(%s))^%d)", irrp, excl, expr, ratp);
    }
}

char *print_fracparts (char *buf, int n, char c[][BUFSZ], char d[][BUFSZ])
{
    char t[BUFSZ], coeff[BUFSZ]="", div[BUFSZ]="";
    for(int i=0; i<n; ++i)
    {
        if (strcmp(c[i],"")!=0)
        {
            sprintf(t, "%s(%s)", (strcmp(coeff,"")==0?"":AnsiString(AnsiString(coeff)+"*").c_str()), c[i]);
            strcpy(coeff,t);
        }
    }
    for(int i=0; i<n; ++i)
    {
        if (strcmp(d[i],"")!=0)
        {
            sprintf(t, "%s(%s)", (strcmp(div,"")==0?"":AnsiString(AnsiString(div)+"*").c_str()), d[i]);
            strcpy(div, t);
        }
    }
    if (strcmp(div,"")==0)
        if (strcmp(coeff,"")==0) sprintf(buf,"1");
        else sprintf(buf, "%s", coeff);
    else
        if (strcmp(coeff,"")==0) sprintf(buf, "(1/(%s))", div);
        else sprintf(buf, "((%s)/(%s))", coeff, div);
    return buf;
}

char *memb (char *buf, int c,int d,int pr,int pi,char *var, bool sign)
{
    char cf[10][BUFSZ], dv[10][BUFSZ];
    char buf1[BUFSZ];

    if (c==0)
    {
        strcpy(buf,"0");
        return buf;
    }
    
    simplifyfrac(c,1,d);

    fracparts(cf[1],dv[1], pr,pi,var);

    if (abs(c)!=1) sprintf(cf[0],"%d", abs(c));
    else sprintf(cf[0],"");

    if (abs(d)!=1) sprintf(dv[0],"%d", abs(d));
    else sprintf(dv[0],"");

    print_fracparts(buf1,2,cf,dv);
    if (c<0) sprintf(buf, "-(%s)", buf1);
    else sprintf(buf,"%s(%s)", (sign?"+":""), buf1);
    return buf;
}

char *elfunc (char *func, char *deriv, int id, char *arg, int a, int j)
{
    switch(id)
    {
        case 0:
        {
            memb(func, 1,1,a,1,arg,false);
            char c[BUFSZ]; sprintf(c,"!(%s)",func);
            strcpy(func,c);
            memb(deriv, a,1, a-1, 1, arg,false);
        } break;
        case 1:
            sprintf(func, "!((%d)^(%s))", a, arg);
            sprintf(deriv, "(%s)*.ln(%d)", func, a);
            break;
        case 2:
            sprintf(func, "log(%d,%s)", j, arg);
            sprintf(deriv, "1/((%s)*ln(%d))",arg, j);
            break;
        case 3:
            sprintf(func, "sin(%s)", arg);
            sprintf(deriv, "cos(%s)", arg);
            break;
        case 4:
            sprintf(func, "cos(%s)", arg);
            sprintf(deriv, "-sin(%s)", arg);
            break;
        case 5:
            sprintf(func, "tg(%s)", arg);
            sprintf(deriv, "1/(cos(%s)^2)", arg);
            break;
        case 6:
            sprintf(func, "ctg(%s)", arg);
            sprintf(deriv, "-(1/(sin(%s)^2))", arg);
            break;
        case 7:
            sprintf(func, "arcsin(%s)", arg);
            sprintf(deriv, "1/sqrt(1-(%s)^2)", arg);
            break;
        case 8:
            sprintf(func, "arccos(%s)", arg);
            sprintf(deriv, "-1/sqrt(1-(%s)^2)", arg);
            break;
        case 9:
            sprintf(func, "arctg(%s)", arg);
            sprintf(deriv, "1/(1+(%s)^2)", arg);
            break;
        case 10:
            sprintf(func, "arcctg(%s)", arg);
            sprintf(deriv, "-1/(1+(%s)^2)", arg);
            break;
        case 11:
            sprintf(func, "ln(%s)", arg);
            sprintf(deriv, "1/(%s)",arg);
            break;
    }
    return func;
}

char *poly2 (char *buf, bool sign, int n, ...)
{
	va_list ap;
	va_start(ap, n);
    bool s=false;
    strcpy(buf,"");
	for(int i=0; i<n; ++i)
	{
		int coeff=va_arg(ap, int);
        int div=va_arg(ap, int);
        int powcoeff=va_arg(ap, int);
        int powdiv=va_arg(ap, int);
        char x[100];
        strcpy(x,va_arg(ap, char*));
        char m[BUFSZ];
        if (strcmp(memb(m,coeff,div,powcoeff,powdiv,x,s),"0"))
        {
            strcat(buf,m);
            s=true;
        }
	}
	va_end(ap);
    if (!s) strcpy(buf,"0");
    return buf;
}

char *poly2ns (char *buf, int n, ...)
{
    bool sign=false;
	va_list ap;
	va_start(ap, n);
    bool s=false;
    strcpy(buf,"");
	for(int i=0; i<n; ++i)
	{
		int coeff=va_arg(ap, int);
        int div=va_arg(ap, int);
        int powcoeff=va_arg(ap, int);
        int powdiv=va_arg(ap, int);
        char x[100];
        strcpy(x,va_arg(ap, char*));
        char m[BUFSZ];
        if (strcmp(memb(m,coeff,div,powcoeff,powdiv,x,s),"0"))
        {
            strcat(buf,m);
            s=true;
        }
	}
	va_end(ap);
    if (!s) strcpy(buf,"0");
    return buf;
}

char *poly2s (char *buf, int n, ...)
{
    bool sign=true;
	va_list ap;
	va_start(ap, n);
    bool s=false;
    strcpy(buf,"");
	for(int i=0; i<n; ++i)
	{
		int coeff=va_arg(ap, int);
        int div=va_arg(ap, int);
        int powcoeff=va_arg(ap, int);
        int powdiv=va_arg(ap, int);
        char x[100];
        strcpy(x,va_arg(ap, char*));
        char m[BUFSZ];
        if (strcmp(memb(m,coeff,div,powcoeff,powdiv,x,s),"0"))
        {
            strcat(buf,m);
            s=true;
        }
	}
	va_end(ap);
    if (!s) strcpy(buf,"0");
    return buf;
}

char *par (char *src, bool excl)
{
    char buf[BUFSZ];
    strcpy(buf,src);
    sprintf(src, (excl?"(!(%s))":"(%s)"), buf);
    return src;
}

char *chprintf (char *buf, char *fmt, ...)
{
   va_list argptr;
   int cnt;

   va_start(argptr, fmt);
   vsprintf(buf, fmt, argptr);
   va_end(argptr);

   return buf;
}

char *catprintf (char *buf, char *fmt, ...)
{
   va_list argptr;
   int cnt;
   char buf1[BUFSZ];

   va_start(argptr, fmt);
   vsprintf(buf1, fmt, argptr);
   va_end(argptr);
   strcat(buf, buf1);

   return buf;
}


