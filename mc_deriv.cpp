#include "m_expressions.h"
#include <stdlib.h>
#define pi 3.14


/*
task deriv0505 (taskparm &tp)
{
    int A, B, C, D;
    do{
        A = rndr(r);
        B = rndr(r);
        C = rndr(r);
        D = rndr(r);
    }while(!(A>0 && D!=0 && abs(D)!=1));

    expr a=A, b=B, c=C, d=D, y=estring("y"), x=estring("x");
    task t;

    t.tasktext()
        << "Найти производную заданной функции среди представленных ниже вариантов ответа:"
        << y=((1/epi)*earctg(1/d*x))^(a*(x^2)+b*x+c)
        << ederiv(y)="...";
    t.answers().add() << ederiv(y)=((1/pi)*earctg(1/d*x))^eln(a*(x^2)+b*x+c)*((2*a*x+b)/(a*x^2+b*x+c)*eln((1/epi)*earctg(1/d*x)))+(d*ln(a*x^2+b*x+c))/((d^2)*(x^2)*earctg(1/d*x));
    t.answers().add() << ederiv(y)=eln(a*(x^2)+b*x+c)*((1/epi)*earctg(1/d*x))^(eln(a*x^2+b*x+c)-1)*(d/((x^2+d^2)*arctg(1/d*x)));
    t.answers().add() << ederiv(y)=eln(a*x^2+b*x+c)*((1/epi)*earctg(1/d*x))^(eln(a*x^2+b*x+c)-1)*(1/(d*arctg(1/d*x)));
    return t;
}
*/

/*
task deriv0101 (taskparm &tp)
{
    int A,B;
    do{
        A=rndr(r);
        B=rndr(r);
    }while (!(A!=0 && A!=1 && A!=-1 && B!=0));

    expr a = A, b = B, y = estring("y");
    task t;
    t.tasktext()
        << plaintext("Найти значение производной функции в заданной точке:")
        << y = esin(2*a+b)
        << x|0 = 1*epi/(3*a)-b/a
        << ederiv(y)(x|0) = estring("...");
    t.answers().add() << "..." = en(0.5*A);
    t.answers().add() << "..." = en(-0.5*A);
    t.answers().add() << "..." = en(0.5);
    t.answers().add() << "..." = a*esqrt(3)/2;
    t.source() << y = esin(2*es("a")+"b");

    return t;
}
*/

void deriv101 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && a!=1 && a!=-1 && b!=0));

    strcpy(task, "");
    catprintf(task, "String(\"Найти значение производной функции в заданной точке:\")");
    catprintf(task, "\ny=sin(%s)", polynomial(buf[0],2,a,"x",b,""));
    catprintf(task, "\nx_0=%s", poly2(buf[1],false,2,  1,3*a,1,1,"pi",  -b,a,1,1,""));
    catprintf(task, "\n%s", "String( )&y`&String(\"(\")&x_0&String(\")\")=...");

    sprintf(answ[0], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f",0.5*a);
    sprintf(answ[1], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f", -0.5*a);
    sprintf(answ[2], "String( )&y`&String(\"(\")&x_0&String(\")\")=0.5");
    sprintf(answ[3], "String( )&y`&String(\"(\")&x_0&String(\")\")=%s", fraction(buf[0],a,3,2));

    sprintf(src, "%s", "y=sin(a*x+b)");
}

void deriv102 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && a!=1 && a!=-1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти значение производной функции в заданной точке:\")");
    catprintf(task, "\ny=cos(%s)", polynomial(buf[0],2,a,"x",b,""));
    catprintf(task, "\nx_0=(%s)*(%s)", poly2(buf[1],false,2,  1,6,1,1,"pi",  -b,1,1,1,""), fraction(buf[2],1,1,a));
    catprintf(task, "\n%s", "String( )&y`&String(\"(\")&x_0&String(\")\")=...");

    sprintf(answ[0], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f",-0.5*a);
    sprintf(answ[1], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f", 0.5*a);
    sprintf(answ[2], "String( )&y`&String(\"(\")&x_0&String(\")\")=-0.5");
    sprintf(answ[3], "String( )&y`&String(\"(\")&x_0&String(\")\")=%s", fraction(buf[0],a,3,2));

    sprintf(src, "%s", "y=cos(a*x+b)");
}

void deriv103 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (a==0 || abs(a)==1);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти значение производной функции в заданной точке:\")");
    catprintf(task, "\ny=tg(%s)", polynomial(buf[0],2,a,"x",b,""));
    catprintf(task, "\nx_0=(%s)*(%s)", poly2(buf[1],false,2,  1,4,1,1,"pi",  -b,1,1,1,""), fraction(buf[3],1,1,a));
    catprintf(task, "\nString( )&y`&String(\"(\")&x_0&String(\")\")=...");

    sprintf(answ[0], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f",0.5*a);
    sprintf(answ[1], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f", (float)a);
    sprintf(answ[2], "String( )&y`&String(\"(\")&x_0&String(\")\")=1");
    sprintf(answ[3], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f", -2.0*a);

    sprintf(src, "y=tg(a*x+b)");
}

void deriv104 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && abs(a)!=1 && b!=0));// && a!=1 && a!=-1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти значение производной функции в заданной точке:\")");
    catprintf(task, "\ny=ctg(%s)", polynomial(buf[0],2,a,"x",b,""));
    catprintf(task, "\nx_0=(%s)*(%s)", poly2(buf[1],false,2,  1,-4,1,1,"pi",  -b,1,1,1,""), fraction(buf[3],1,1,a));
    catprintf(task, "\n%s", "String( )&y`&String(\"(\")&x_0&String(\")\")=...");

    sprintf(answ[0], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f",-0.5*a);
    sprintf(answ[1], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f", -(float)a);
    sprintf(answ[2], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f", (float)2*a);
    sprintf(answ[3], "String( )&y`&String(\"(\")&x_0&String(\")\")=sqrt(3)");

    sprintf(src, "y=ctg(a*x+b)");
}

void deriv105 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && abs(a)!=1));

    sprintf(task, "");
    catprintf(task, "%s", "String(\"Найти значение производной функции в заданной точке:\")");
    catprintf(task, "\ny=arcsin(%s)", polynomial(buf[0],2,a,"x",b,""));
    catprintf(task, "\nx_0=(%s)*(%s)", poly2(buf[1],false,2,  1,2,1,2,"3",  -b,1,1,1,""), fraction(buf[3],1,1,a));
    catprintf(task, "\n%s", "String( )&y`&String(\"(\")&x_0&String(\")\")=...");

    sprintf(answ[0], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f",2.0*a);
    sprintf(answ[1], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f", -(float)a);
    sprintf(answ[2], "String( )&y`&String(\"(\")&x_0&String(\")\")=0.5");
    sprintf(answ[3], "String( )&y`&String(\"(\")&x_0&String(\")\")=2");

    sprintf(src, "y=arcsin(a*x+b)");
}

void deriv106 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while (!(a!=0 && a!=1 && a!=-1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти значение производной функции в заданной точке:\")");
    catprintf(task, "\ny=arctg(%s)", polynomial(buf[0],2,a,"x",b,""));
    catprintf(task, "\nx_0=%s", fraction(buf[3],4-b,1,a));
    catprintf(task, "\n%s", "String( )&y`&String(\"(\")&x_0&String(\")\")=...");

    sprintf(answ[0], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f", 0.2*(float)a);
    sprintf(answ[1], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f", 2.0*a);
    sprintf(answ[2], "String( )&y`&String(\"(\")&x_0&String(\")\")=5");
    sprintf(answ[3], "String( )&y`&String(\"(\")&x_0&String(\")\")=-0.2");

    sprintf(src, "y=arctg(a*x+b)");
}

void deriv107 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while (a<=0 || b==0 || abs(a)==1 || abs(b)==1);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти значение производной функции в заданной точке:\")");
    catprintf(task, "\ny=log(%d,%s)", a, polynomial(buf[0],2,b,"x",c,""));
    catprintf(task, "\nx_0=(%s)*(%s)", poly2(buf[1],false,2,  1,1,-1,1,chprintf(buf[4],"ln(%d)",a),  -c,1,1,1,""), fraction(buf[3],1,1,b));
    catprintf(task, "\n%s", "String( )&y`&String(\"(\")&x_0&String(\")\")=...");

    sprintf(answ[0], "String( )&y`&String(\"(\")&x_0&String(\")\")=%1.1f",(float)b);
    sprintf(answ[1], "String( )&y`&String(\"(\")&x_0&String(\")\")=%s", memb(buf[3],b,1,1,1,buf[4],false));
    sprintf(answ[2], "String( )&y`&String(\"(\")&x_0&String(\")\")=1");
    sprintf(answ[3], "String( )&y`&String(\"(\")&x_0&String(\")\")=1/ln(%d)^2", a);

    sprintf(src, "y=log(a,b*x+c)");
}

void deriv108 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while (!(a>0 && b!=0 && a!=1 && b!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти значение производной функции в заданной точке:\")");
    catprintf(task, "\ny=(%d)^(%s)", a, polynomial(buf[0],2,b,"x",c,""));
    catprintf(task, "\nx_0=%s", fraction(buf[0],2-c,1,b));
    catprintf(task, "\n%s", "String( )&y`&String(\"(\")&x_0&String(\")\")=...");

    sprintf(answ[0], "String( )&y`&String(\"(\")&x_0&String(\")\")=%s", memb(buf[0],a*a*b,1,1,1,chprintf(buf[2],"ln(%d)",a),false));
    sprintf(answ[1], "String( )&y`&String(\"(\")&x_0&String(\")\")=%d", 2*a*b);
    sprintf(answ[2], "String( )&y`&String(\"(\")&x_0&String(\")\")=%s", memb(buf[0],a*a,1,1,1,buf[2],false));
    sprintf(answ[3], "String( )&y`&String(\"(\")&x_0&String(\")\")=%d", 2*a);

    sprintf(src, "y=a^(b*x+c)");
}

void deriv201 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while ((a==0 || c==0) || b==0 || d==0 || b==d || a*d-b*c==0 || abs(a)==abs(c));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=sin((%s)/(%s))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""));
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=cos((%s)/(%s))*(%d/((%s)^2))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""), a*d-b*c, polynomial(buf[4],2, c,"x",d,""));
    sprintf(answ[1], "y`=cos((%s)/(%s))*(%d/((%s)^2))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""), -a*d+b*c, polynomial(buf[4],2, c,"x",d,""));
    sprintf(answ[2], "y`=(%s)*cos((%s)/(%s))", fraction(buf[3],a,1,c), polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""));
    sprintf(answ[3], "y`=cos(%d/((%s)^2))", a*d-b*c, polynomial(buf[0],2,c,"x",d,""));

    sprintf(src, "y=sin((a*x+b)/(c*x+d))");
}

void deriv202 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while ((a==0 || c==0) || abs(a)==c*c || b==0 || d==0 || a==c || b==d || a*d-b*c==0);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=cos((%s)/(%s))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""));
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(-sin((%s)/(%s)))*(%d/((%s)^2))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""), a*d-b*c, polynomial(buf[4],2, c,"x",d,""));
    sprintf(answ[1], "y`=sin((%s)/(%s))*(%d/((%s)^2))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""), a*d-b*c, polynomial(buf[4],2, c,"x",d,""));
    sprintf(answ[2], "y`=(%s)*sin((%s)/(%s))", fraction(buf[3],a,1,c*c), polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""));
    sprintf(answ[3], "y`=-sin(%d/((%s)^2))", a*d-b*c, polynomial(buf[0],2,c,"x",d,""));

    sprintf(src, "y=cos((a*x+b)/(c*x+d))");
}

void deriv203 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while ((a==0 || c==0) || abs(a)==abs(c) || b==0 || d==0 || a==c || b==d || a*d-b*c==0 || abs(a*d-b*c)==c*c);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=tg((%s)/(%s))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""));
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(1/(cos((%s)/(%s))^2))*(%d/((%s)^2))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""), a*d-b*c, polynomial(buf[4],2, c,"x",d,""));
    sprintf(answ[1], "y`=(1/(sin((%s)/(%s))^2))*(%d/((%s)^2))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""), -a*d+b*c, polynomial(buf[4],2, c,"x",d,""));
    sprintf(answ[2], "y`=ctg((%s)/(%s))*(%s)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""), fraction(buf[6],a*d-b*c,1,c*c));
    sprintf(answ[3], "y`=(%s)*(1/(cos((%s)/(%s))^2))", fraction(buf[0],a,1,c), polynomial(buf[2],2,a,"x",b,""), polynomial(buf[3],2,c,"x",d,""));

    sprintf(src, "y=tg((a*x+b)/(c*x+d))");
}

void deriv204 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while ((a==0 || c==0) || b==0 || d==0 || a==c || b==d || a*d-b*c==0);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=ctg((%s)/(%s))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""));
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=-(1/(sin((%s)/(%s))^2))*(%d/((%s)^2))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""), a*d-b*c, polynomial(buf[4],2, c,"x",d,""));
    sprintf(answ[1], "y`=(1/(sin((%s)/(%s))^2))*(%d/((%s)^2))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""), -a*d+b*c, polynomial(buf[4],2, c,"x",d,""));
    sprintf(answ[2], "y`=(%s)*tg((%s)/(%s))", fraction(buf[1],a,1,c), polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""));
    sprintf(answ[3], "y`=(1/(cos((%s)/(%s))^2))*(%d/(%s))", polynomial(buf[2],2,a,"x",b,""), polynomial(buf[3],2,c,"x",d,""), b*c-a*d, polynomial(buf[5],2,c,"x",d,""));

    sprintf(src, "y=ctg((a*x+b)/(c*x+d))");
}

void deriv205 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while ((a==0 || c==0) || (c==0 && abs(d)==1) || b==0 || d==0 || a==c || b==d || a*d-b*c==0);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=arcsin((%s)/(%s))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""));
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(1/sqrt(1-((%s)/(%s))^2))*(%d/((%s)^2))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""), a*d-b*c, polynomial(buf[4],2, c,"x",d,""));
    sprintf(answ[1], "y`=(1/sqrt((%s)^2-(%s)^2))*(%d/((%s)^2))", polynomial(buf[2],2,c,"x",d,""), polynomial(buf[0],2,a,"x",b,""), a*d-b*c, polynomial(buf[4],2, c,"x",d,""));
    sprintf(answ[2], "y`=arccos((%s)/(%s))*(%d/((%s)^2))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""), b*c-a*d, polynomial(buf[5],2,c,"x",d,""));
    sprintf(answ[3], "y`=1/sqrt(1-((%s)^2)/((%s)^4))", polynomial(buf[2],2,a,"x",b,""), polynomial(buf[3],2,c,"x",d,""));

    sprintf(src, "y=arcsin((a*x+b)/(c*x+d))");
}

void deriv206 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while ((a==0 || c==0) || abs(a)==c*c || b==0 || d==0 || a==c || b==d || a*d-b*c==0 || abs(a*d-b*c)==1);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=arctg((%s)/(%s))", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""));
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=%d/((%s)^2+(%s)^2)", a*d-b*c, polynomial(buf[0],2,c,"x",d,""), polynomial(buf[2],2,a,"x",b,""));
    sprintf(answ[1], "y`=((%d)*(%s)^2)/((%s)^2+(%s)^2)", b*c-a*d, polynomial(buf[2],2,c,"x",d,""), polynomial(buf[0],2,c,"x",d,""), polynomial(buf[2],2,a,"x",b,""));
    sprintf(answ[2], "y`=(%s)*(1/(cos((%s)/(%s))^2))", fraction(buf[0],a,1,c*c), polynomial(buf[1],2,a,"x",b,""), polynomial(buf[2],2,c,"x",d,""));
    sprintf(answ[3], "y`=1/(1+(%d)/((%s)^4))", (int)pow(a*d+b*c,2), polynomial(buf[3],2,c,"x",d,""));

    sprintf(src, "y=arctg((a*x+b)/(c*x+d))");
}

void deriv207 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
        p=rndr(r);
    }while (!(p>0 && p!=1 && a!=c && b!=d && a*d!=b*c && abs(a)+abs(c)!=0 && !(c==0 && abs(d)==1) && !(a==0 && abs(b)==1) && b*c-a*d!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=log(%d,(%s)/(%s))", p, polynomial(buf[0], 2, a,"x",b,""), polynomial(buf[1], 2, c,"x",d,""));
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=%d/((%s)*(%s)*ln(%d))", a*d-b*c, buf[0], buf[1], p);
    sprintf(answ[1], "y`=(%s)/((%s)*ln(%d))", memb(buf[6], b*c-a*d, 1, 1,1, buf[1], false), buf[0], p);
    sprintf(answ[2], "y`=(%s)/((%s)*ln(%d))", buf[1], buf[0], p);
    sprintf(answ[3], "y`=%s", memb(buf[6], 1,a*d-b*c,2,1,buf[1],false));

    sprintf(src, "y=log(p,(a*x+b)/(c*x+d))");
}

void deriv208 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
        p=rndr(r);
    }while (!(p>0 && p!=1 && abs(a)!=abs(c) && b!=d && a*d!=b*c && a!=0 && c!=0 && abs(a*d-b*c)!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%d)^((%s)/(%s))", p, polynomial(buf[0], 2, a,"x",b,""), polynomial(buf[1], 2, c,"x",d,""));
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%d)^((%s)/(%s))*ln(%d)*(%d)/((%s)^2)", p, buf[0], buf[1], p, a*d-b*c, buf[1]);
    sprintf(answ[1], "y`=(%d)^((%s)/(%s))*(%s)*ln(%d)", p, buf[0], buf[1], fraction(buf[3], a,1, c), p);
    sprintf(answ[2], "y`=(%s)/((%s)^3)*(%d)^((%s)/(%s))",
        memb(buf[3], a*d-b*c,1,1,1, buf[0], false),
        buf[1],
        p,
        polynomial(buf[4], 2, a-c, "x", b-d, ""),
        buf[1]
    );
    sprintf(answ[3], "y`=(%d)^(%s)*ln(%d)", p, memb(buf[3], a*d-b*c,1,-2,1,buf[1],false), p);

    sprintf(src, "y=p^((a*x+b)/(c*x+d))");
}

void deriv209 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d,q;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
        q=rndr(r);
    }while (!(q>0 && q!=1 && a!=c && b!=d && a*d!=b*c && a!=0 && c!=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=!((%s)/(%s))^(%d)", polynomial(buf[0], 2, a,"x",b,""), polynomial(buf[1], 2, c,"x",d,""), q);
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%s)*((%d)/((%s)^2))",
        memb(buf[5], q,1,q-1,1, chprintf(buf[4],"((%s)/(%s))", buf[0], buf[1]), false),
        a*d-b*c,
        buf[1]
    );
    sprintf(answ[1], "y`=(!((%s)/(%s))^(%d))*((%d)/((%s)^2))*ln(%d)",
        buf[0], buf[1], q,
        b*c-a*d, buf[1],
        q
    );
    sprintf(answ[2], "y`=(!((%s)/(%s))^(%d))*((%d)/((%s)^2))*ln((%s)/(%s))",
        buf[0], buf[1], q,
        b*c-a*d, buf[1],
        buf[0], buf[1]
    );
    sprintf(answ[3], "y`=%s", memb(buf[5], q,1,q-1,1,chprintf(buf[4],"((%d)/((%s)^2))", a*d-b*c, buf[1]), false));

    sprintf(src, "y=!((a*x+b)/(c*x+d))^q");
}

void deriv301 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,p,b;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while (!(b!=0 && abs(p)!=abs(a) && p!=0 && p!=1 && a>0 && a!=1 && b!=1 && abs(b*p)!=abs(a)));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=ln(%d)*sin(%s)^(%d)", a, polynomial(buf[0],1,b,"x"), p);
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=ln(%d)*(%s)*cos(%s)",
        a,
        memb(buf[3],b*p,1,p-1,1,chprintf(buf[4],"sin(%s)",buf[0]), false),
        buf[0]
    );
    sprintf(answ[1], "y`=(%s)*(%s)*cos(%s)",
        fraction(buf[1],b*p,1,a),
        memb(buf[3],1,1,p-1,1,chprintf(buf[4],"sin(%s)",buf[0]), false),
        buf[0]
    );
    sprintf(answ[2], "y`=ln(%d)*(%s)*cos(%s)^(%d)",
        a,
        memb(buf[3],b*p,1,p-1,1,chprintf(buf[4],"sin(%s)",buf[0]), false),
        buf[0],
        p
    );
    sprintf(answ[3], "y`=(%s)*(%s)*cos(%s)",
        fraction(buf[1],p,1,a),
        memb(buf[3],1,1,p-1,1,chprintf(buf[4],"sin(%s)",buf[0]), false),
        buf[0]
    );

    sprintf(src, "y=ln(a)*sin(b*x)^p");
}

void deriv302 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,p,n,m;
    do{
        b=rndr(r);
        p=rndr(r);
        n=rndr(r);
        m=rndr(r);
    }while (!(b!=0 && abs(n)!=abs(m) && p!=0 && p!=1 && n<m && m!=0 && n!=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=arcsin((%s)*pi)*(cos(%s)^(%d))",
        fraction(buf[0],n,1,m),
        polynomial(buf[1],1,b,"x"),
        p
    );
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=arcsin((%s)*pi)*(%s)*sin(%s)",
        fraction(buf[0],n,1,m),
        memb(buf[2],-b*p,1,p-1,1,chprintf(buf[4],"cos(%s)",buf[1]),false),
        buf[1]
    );
    sprintf(answ[1], "y`=((%d)/sqrt(1-(%s)^2))*(%s)*sin(%s)",
        -b*p,
        fraction(buf[0],n,1,m),
        memb(buf[2],-b*p,1,p-1,1,chprintf(buf[4],"cos(%s)",buf[1]),false),
        buf[1]
    );
    sprintf(answ[2], "y`=((%d)/sqrt(1-(%s)^2))*(cos(%s)^(%d))%s*arcsin(%s)*sin(%s)",
        -b*p,
        fraction(buf[0],n,1,m),
        buf[1],p,
        memb(buf[2],-b*p,1,p-1,1, chprintf(buf[4],"cos(%s)",buf[1]),true),
        buf[0],
        buf[1]
    );
    sprintf(answ[3], "y`=arcsin(%s)*(%s)",
        fraction(buf[0],n,1,m),
        memb(buf[2],b*p,1,p-1,1, chprintf(buf[4],"(-sin(%s))",buf[1]),false)
    );

    sprintf(src, "y=arcsin((n/m)*pi)*(cos(b*x)^p)");
}

void deriv303 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,p;
    do{
        b=rndr(r);
        p=rndr(r);
        a=rndr(r);
    }while (!(b!=0 && p>0 && p!=1 && a>0 && a!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(1/ln(%d))*(tg(%s)^(%d))",
        a,
        polynomial(buf[0],1,b,"x"),
        p
    );
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%s)/(ln(%d)*(cos(%s)^2))",
        memb(buf[2], b*p,1,p-1,1, chprintf(buf[3],"tg(%s)",buf[0]),false),
        a,
        buf[0]
    );
    sprintf(answ[1], "y`=-(1/((%d)*ln(%d)))*tg(%s)^(%d)+((%s)/(ln(%d)*cos(%s)^(%d)))",
        a,a, buf[0], p,
        memb(buf[3], b*p, 1, p-1,1, chprintf(buf[5],"sin(%s)",buf[0]), false), a, buf[0], p+1
    );
    sprintf(answ[2], "y`=((%d)/ln(%d))*(1/(cos(%s)^(%d)))", p*b, a, buf[0], 2*p);
    sprintf(answ[3], "y`=((%d)/((%d)*ln(%d)))*((%s)/(cos(%s)^2))",
        -b*p, a,a,
        memb(buf[2],1,1,p-1,1,chprintf(buf[3],"tg(%s)",buf[0]),false),buf[0]
    );

    sprintf(src, "y=(1/ln(a))*(tg(b*x)^p)");
}

void deriv304 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,p;
    do{
        b=rndr(r);
        p=rndr(r);
        a=rndr(r);
    }while (!(b!=0 && p>0 && p!=1 && a>0 && a!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(1/(ln(%d)^2))*(ctg(%s)^(%d))",
        a,
        polynomial(buf[0],1,b,"x"),
        p
    );
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%s)/((ln(%d)^2)*(sin(%s)^2))",
        memb(buf[2], -b*p,1,p-1,1, chprintf(buf[3],"ctg(%s)",buf[0]),false),
        a,
        buf[0]
    );
    sprintf(answ[1], "y`=((%d)/(ln(%d)^2))*((%s)/(cos(%s)^2))",
        b*p, a,
        memb(buf[2],1,1,p-1,1,chprintf(buf[3],"ctg(%s)",buf[0]),false),buf[0]
    );
    sprintf(answ[2], "y`=-(2/((%d)*ln(%d)^3))*ctg(%s)^(%d)-((%s)/((ln(%d)^2)*(sin(%s)^2)))",
        a,a, buf[0], p,
        memb(buf[3], b*p,1,p-1,1, chprintf(buf[5],"ctg(%s)",buf[0]),false), a, buf[0]
    );
    sprintf(answ[3], "y`=((%d)/((%d)*ln(%d)))*(1/(sin(%s)^(%d)))", -p*b, a,a, buf[0], 2*p);

    sprintf(src, "y=(1/(ln(a)^2))*(ctg(b*x)^p)");
}

void deriv305 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,p;
    do{
        b=rndr(r);
        p=rndr(r);
        a=rndr(r);
    }while (!(a!=0 && b!=0 && p>0 && p!=1 && a>=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(1/cos(%d))*(arcsin(%s)^(%d))",
        a,
        polynomial(buf[0],1,b,"x"),
        p
    );
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%s)/(sqrt(%s)*cos(%d))",
        memb(buf[3], b*p,1,p-1,1,chprintf(buf[4],"arcsin(%s)",polynomial(buf[0],1,b,"x")),false),
        polynomial(buf[1],2, 1,"",-b*b,"x^2"),
        a
    );
    sprintf(answ[1], "y`=(sin(%d)/(cos(%d)^2))*(arcsin(%s)^(%d))+(%s)/(sqrt(%s)*cos(%d))",
        a,a,buf[0],p,
        memb(buf[4],b*p,1,p-1,1,chprintf(buf[5],"arcsin(%s)",buf[0]),false),
        buf[1],a
    );
    sprintf(answ[2], "y`=((%d)/(cos(%d)))*(1/(%s))",
        b*p, a,
        memb(buf[5],1,1,p-1,1, chprintf(buf[6],"sqrt(%s)",buf[1]), false)
    );
    sprintf(answ[3], "y`=(%s)/(%s*sqrt(%s))",
        memb(buf[4],p,1,p-1,1,chprintf(buf[8],"arcsin(%s)",buf[0]),false),
        memb(buf[5],b,1,1,1,chprintf(buf[6],"cos(%d)",a),false),
        buf[1]
    );

    sprintf(src, "y=(1/cos(a))*(arcsin(b*x)^p)");
}

void deriv306 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,p;
    do{
        b=rndr(r);
        p=rndr(r);
        a=rndr(r);
    }while (!(a!=0 && b!=0 && p>0 && p!=1 && a>=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(sin(%d)/2)*(arctg(%s)^(%d))",
        a,
        polynomial(buf[0],1,b,"x"),
        p
    );
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%s)*((%s)/(%s))",
        memb(buf[3], b*p,2,1,1,chprintf(buf[4],"sin(%s)",buf[0]),false),
        memb(buf[2], 1,1,p-1,1,chprintf(buf[5],"arctg(%s)",buf[0]), false),
        polynomial(buf[1],2, 1,"",b*b,"x^2")
    );
    sprintf(answ[1], "y`=(cos(%d)/2)*(arctg(%s)^(%d))+(%s)*(%s)/(%s)",
        a,buf[0],p,
        memb(buf[3],b*p,2,1,1,chprintf(buf[6],"sin(%d)",a),false),
        memb(buf[4],1,1,p-1,1,chprintf(buf[8],"arctg(%s)",buf[0]),false),
        buf[1]
    );
    sprintf(answ[2], "y`=(sin(%d)/2)*(%s)",
        a,
        memb(buf[2],p*b,1,-(p-1),1,chprintf(buf[8],"(%s)",buf[1]),false)
    );
    sprintf(answ[3], "y`=(sin(%d)/4)*((%s)/(%s))",
        a,
        memb(buf[2],1,1,p-1,1,chprintf(buf[9],"arctg(%s)",buf[0]),false),
        memb(buf[3],b,1,1,1,buf[1],false)
    );

    sprintf(src, "y=(sin(a)/2)*(arctg(b*x)^p)");
}

void deriv307 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        p=rndr(r);
    }while(!(c>0 && c!=1 && b!=0 && p!=0 && p!=1 && b!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=cos(%d)^2*(log(%d,%s)^(%d))", a, c, polynomial(buf[0],1,b,"x"),p);
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=((cos(%d)^2)*(%s))/(x*ln(%d))", a,memb(buf[1],p,1,p-1,1,chprintf(buf[2],"log(%d,%s)",c,buf[0]),false),c);
    sprintf(answ[1], "y`=((cos(%d)^2)*(%s))/(x*ln(%d))", a,memb(buf[1],p*b,1,p-1,1,chprintf(buf[2],"log(%d,%s)",c,buf[0]),false),c);
    sprintf(answ[2], "y`=sin(%d)*(log(%d,%s)^(%d))+((cos(%d)^2)*(%s))/(x*ln(%d))", 2*a,c,buf[0],p, a,memb(buf[1],p*b,1,p-1,1,chprintf(buf[2],"log(%d,%s)",c,buf[0]),false),c);
    sprintf(answ[3], "y`=sin(%d)*(%s)", 2*a, memb(buf[1],p,1,p-1,1,chprintf(buf[2],"1/(x*ln(%d))",c),false));

    sprintf(src, "y=cos(a)^2*(log(c,b*x)^p)");
}

void deriv308 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        p=rndr(r);
    }while(!(c>0 && c!=1 && b!=0 && a!=0 && p!=0 && p!=1 && !(abs(b)==1 && p<0)));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    if (p>0)
    {
        catprintf(task, "\ny=arctg(%d)*(%d)^((%s)^(%d))", a,c,polynomial(buf[0],1,b,"x"),p);
        catprintf(task, "\n%s", "y`=...");

        sprintf(answ[0], "y`=arctg(%d)*ln(%d)*(%s)*(%d)^((%s)^(%d))", a,c,memb(buf[1],pow(b,p)*p,1,p-1,1,"x",false), c,buf[0],p);
        sprintf(answ[1], "y`=arctg(%d)*(%s)*((%d)^((%s)^(%d)-1))", a,memb(buf[2],b,1,p,1,buf[0],false),c,buf[0],p);
        sprintf(answ[2], "y`=(%s)+arctg(%d)*ln(%d)*(%s)*(%d)^((%s)^(%d))",
            memb(buf[2],1,1+a*a,1,1,chprintf(buf[2],"(%d)^((%s)^(%d))", c, buf[0], p),false),
            a,c,memb(buf[1],pow(b,p)*p,1,p-1,1,"x",false), c,buf[0],p
        );
        sprintf(answ[3], "y`=(%s)", memb(buf[4],1,1+a*a,1,1, chprintf(buf[3],"ln(%d)*(%s)*(%d)^((%s)^(%d))",c,memb(buf[1],pow(b,p)*p,1,p-1,1,"x",false), c,buf[0],p),false));
    }
    else
    {
        catprintf(task, "\ny=arctg(%d)*(%d)^((%s)^(%d))", a,c,polynomial(buf[0],1,b,"x"),p);
        catprintf(task, "\n%s", "y`=...");

        sprintf(answ[0], "y`=arctg(%d)*ln(%d)*(%s)*(%d)^((%s)^(%d))", a,c,memb(buf[1],p,pow(b,-p),p-1,1,"x",false), c,buf[0],p);
        sprintf(answ[1], "y`=arctg(%d)*(%s)*((%d)^((%s)^(%d)-1))", a,memb(buf[2],b,1,p,1,buf[0],false),c,buf[0],p);
        sprintf(answ[2], "y`=(%s)+arctg(%d)*ln(%d)*(%s)*(%d)^((%s)^(%d))",
            memb(buf[2],1,1+a*a,1,1,chprintf(buf[2],"(%d)^((%s)^(%d))", c, buf[0], p),false),
            a,c,memb(buf[1],p,pow(b,-p),p-1,1,"x",false), c,buf[0],p
        );
        sprintf(answ[3], "y`=(%s)", memb(buf[4],1,1+a*a,1,1, chprintf(buf[3],"ln(%d)*(%s)*(%d)^((%s)^(%d))",c,memb(buf[1],p,pow(b,-p),p-1,1,"x",false), c,buf[0],p),false));
    }

    sprintf(src, "y=arctg(a)*(c^((b*x)^p))");
}

void deriv401 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while (!(a>0 && a!=1 && b!=0 && c!=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=log(%d,sin(%s))+1/arctg(%d)",a,polynomial(buf[0],1,b,"x"),c);
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%d/ln(%d))*ctg(%s)", b,a,buf[0]);
    sprintf(answ[1], "y`=(%d/ln(%d))*tg(%s)", b,a,buf[0]);
    sprintf(answ[2], "y`=(1/(ln(%d))*sin(%s))-1/arctg(%d)^2", a,buf[0],c);
    sprintf(answ[3], "y`=(%d/ln(%d))*ctg(%s)-1/((%d)*arctg(%d)^2)", b,a,buf[0],1+c*c,c);

    sprintf(src, "y=log(a,sin(b*x))+1/arctg(c)");
}

void deriv402 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while (!(b!=0 && a>0 && a!=1 && c!=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=log(%d,cos(%s))+arctg(%d)^2", a,polynomial(buf[0],1,b,"x"),c);
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%d/ln(%d))*tg(%s)", -b,a,buf[0]);
    sprintf(answ[1], "y`=(%d/ln(%d))*ctg(%s)", b,a,buf[0]);
    sprintf(answ[2], "y`=1/(ln(%d)*cos(%s))+2*arctg(%d)",a,buf[0],c);
    sprintf(answ[3], "y`=(%d/ln(%d))*tg(%s)+%s",-b,a,buf[0], memb(buf[3], 2,1+c*c,1,1,chprintf(buf[4], "arctg(%d)",c),false));
    sprintf(src, "y=log(a,cos(b*x))+arctg(c)^2");
}

void deriv403 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while (!(b!=0 && d>0 && a>0 && a!=1 && abs(b)!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=log(%d,%s)+cos(%d)^3", a,polynomial(buf[0],2,d,"",1,chprintf(buf[3],"tg(%s)", polynomial(buf[1],1,b,"x"))),c);
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%d/((%s)*ln(%d)))*(1/cos(%s)^2)", b,buf[0],a,buf[1]);
    sprintf(answ[1], "y`=(%d*cos(%s)^2)/(%s)", b,buf[1],buf[0]);
    sprintf(answ[2], "y`=(%d/((%s)*ln(%d)))*(1/cos(%s)^2)-3*cos(%d)^2*sin(%d)", b,buf[0],a,buf[1],c,c);
    sprintf(answ[3], "y`=-(1/((%s)*sin(%s)^2))", buf[0],buf[1]);
    sprintf(src, "y=log(a,d+tg(b*x))+cos(c)^3");
}

void deriv404 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while (!(b!=0 && d>0 && a>0 && a!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=log(%d,%s)+sin(%d)", a,polynomial(buf[0],2,d,"",1,chprintf(buf[2],"ctg(%s)", polynomial(buf[1],1,b,"x"))),c);
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%d/((%s)*ln(%d)))*(1/sin(%s)^2)", -b,buf[0],a,buf[1]);
    sprintf(answ[1], "y`=(%d/((%s)*ln(%d)))*(1/cos(%s)^2)", b,buf[0],a,buf[1]);
    sprintf(answ[2], "y`=-2/(sin(%s)*ln(%d))+sin(%d)", polynomial(buf[2],1,2*b,"x"),a,c);
    sprintf(answ[3], "y`=(%d/((%s)*ln(%d)))*(1/sin(%s)^2)+cos(%d)", -b,buf[0],a,buf[1],c);

    sprintf(src, "y=log(a,d+ctg(b*x))+sin(c)");
}

void deriv405 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while(!(b!=0 && a>0 && a!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=log(%d,%s)+cos(%d)^2", a, chprintf(buf[1],"arcsin(%s)", polynomial(buf[0],1,b,"x")), c);
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=%d/(%s*sqrt(%s)*ln(%d))",b,buf[1],polynomial(buf[2],2,1,"",-b*b,"x^2"),a);
    sprintf(answ[1], "y`=%d/(%s*sqrt(%s)*ln(%d))",b,buf[1],polynomial(buf[3],2,1,"",b*b,"x^2"),a);
    sprintf(answ[2], "y`=1/(sqrt(%s)*ln(%d))",buf[2],a);
    sprintf(answ[3], "y`=%d/(%s*sqrt(%s))+sin(%d)", b,buf[1],buf[2],2*c);

    sprintf(src, "y=log(a,arcsin(b*x))+cos(c)^2");
}

void deriv406 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while(!(b!=0 && a>0 && a!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=log(%d,%s)+arcctg(%d)", a, chprintf(buf[1],"arctg(%s)", polynomial(buf[0],1,b,"x")), c);
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=%d/(%s*(%s)*ln(%d))",b,buf[1],polynomial(buf[2],2,1,"",b*b,"x^2"),a);
    sprintf(answ[1], "y`=%d/((%s)*ln(%d))-1/(%d)",b,polynomial(buf[3],2,1,"",b*b,"x^2"),a,1+c*c);
    sprintf(answ[2], "y`=1/((%s)*sqrt(%s))+arcctg(%d)",buf[1], buf[2], c);
    sprintf(answ[3], "y`=(%s)/(arctg(%s)*ln(%d))", memb(buf[5],b,1,1,1,buf[2],false),buf[0],a);

    sprintf(src, "y=log(a,arctg(b*x))+arcctg(c)");
}

void deriv407 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while(!(b!=0 && a>0 && a!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%d)^(sin(%s))+(1/2)*tg(%d)", a, polynomial(buf[0],1,b,"x"), c);
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%d)^(sin(%s))*(%s)*ln(%d)",a,buf[0],memb(buf[1],b,1,1,1,chprintf(buf[2],"cos(%s)",buf[0]),false),a);
    sprintf(answ[1], "y`=(%d)^(sin(%s))*(%s)*ln(%d)-1/(2*cos(%d)^2)",a,buf[0],memb(buf[1],b,1,1,1,chprintf(buf[2],"cos(%s)",buf[0]),false),a,c);
    sprintf(answ[2], "y`=(%d)^(cos(%s))*(%s)",a,buf[0],memb(buf[1],b,1,1,1,chprintf(buf[2],"ln(%d)",a),false));
    sprintf(answ[3], "y`=(1/2)*sin(%s)*(%d)^(sin(%s)-1)", polynomial(buf[1],1,2*b,"x"),a,buf[0]);

    sprintf(src, "y=a^sin(b*x)+(1/2)*tg(c)");
}

void deriv408 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while(!(b!=0 && a>0 && a!=1 && c!=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%d)^(cos(%s))+ln(%d)^2", a, polynomial(buf[0],1,b,"x"), c);
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%d)^(cos(%s))*(%s)*ln(%d)",a,buf[0],memb(buf[1],-b,1,1,1,chprintf(buf[2],"sin(%s)",buf[0]),false),a);
    sprintf(answ[1], "y`=(%d)^(sin(%s))*(%s)+ln(%d)^2",a,buf[0],memb(buf[1],b,1,1,1,chprintf(buf[2],"ln(%d)",a),false),c);
    sprintf(answ[2], "y`=(%d)^(cos(%s)-1)*(%s)",a,buf[0],memb(buf[1],b,1,1,1,chprintf(buf[2],"cos(%s)",buf[0]),false));
    sprintf(answ[3], "y`=(%d)^(cos(%s))*(%s)*ln(%d)%s",a,buf[0],memb(buf[1],-b,1,1,1,chprintf(buf[2],"sin(%s)",buf[0]),false),a,memb(buf[6],2,c,1,1,chprintf(buf[7],"ln(%d)",c),true));

    sprintf(src, "y=a^cos(b*x)+ln(c)^2");
}

void deriv501 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[15][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while(!(a!=0 && b!=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(1+sin(%s))^sqrt(%s)", polynomial(buf[0],1,a,"pi*x"), polynomial(buf[1],2, b,"x",c,""));
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(1+sin(%s))^sqrt(%s)*(%s)",
        polynomial(buf[0],1,a,"pi*x"), polynomial(buf[1],2, b,"x",c,""),
        poly2ns(buf[2],2,
            1,1,1,1, chprintf(buf[3],chprintf(buf[12],"(%s)*ln(1+sin(%s))/sqrt(%s)", fraction(buf[11],b,1,2)), polynomial(buf[4],1,a,"pi*x"), polynomial(buf[5],2,b,"x",c,"")),
            a,1,1,1, chprintf(buf[6],"(sqrt(%s)/(1+sin(%s)))*pi*cos(%s)", polynomial(buf[7],2,b,"x",c,""), polynomial(buf[8],1,a,"pi*x"), polynomial(buf[9],1,a,"pi*x"))
        )
    );
    sprintf(answ[1], "y`=sqrt(%s)*(1+sin(%s))^(sqrt(%s)-1)*(%s)",
        polynomial(buf[0],2, b,"x",c,""),
        polynomial(buf[1],1, a,"pi*x"),
        polynomial(buf[2],2, b,"x",c,""),
        polynomial(buf[3],1, a,chprintf(buf[4], "pi*cos(%s)", polynomial(buf[1],1, a,"pi*x")))
    );
    sprintf(answ[2], "y`=(1+sin(%s))^sqrt(%s)*ln(1+sin(%s))*(%s)",
        polynomial(buf[0],1, a,"pi*x"),
        polynomial(buf[1],2, b,"x",c,""),
        polynomial(buf[2],1, a,"pi*x"),
        memb(buf[3], b,2,-1,1,chprintf(buf[4],"sqrt(%s)", polynomial(buf[5],2, b,"x",c,"")),false)
    );
    sprintf(answ[3], "y`=(%s)*ln(1+sin(%s))+(sqrt(%s)/(1+sin(%s)))*(%s)",
        memb(buf[0], b,2,-1,1,chprintf(buf[1],"sqrt(%s)", polynomial(buf[2],2, b,"x",c,"")),false),
        polynomial(buf[3],1, a,"pi*x"),
        polynomial(buf[4],2, b,"x",c,""),
        polynomial(buf[5],1, a,"pi*x"),
        polynomial(buf[6],1,a,chprintf(buf[7],"pi*cos(%s)", polynomial(buf[8],1, a,"pi*x")))
    );

    sprintf(src, "y=(1+sin(a*pi/x))^sqrt(b*x+c)");
}

void deriv502 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while(!(a!=0 && c!=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)^sin(%s)",
        polynomial(buf[0],2, a,"x^2",b,""),
        poly2ns(buf[1],1, c,24,1,1,"pi*x")
    );
    catprintf(task, "\n%s", "y`=...");

    sprintf(answ[0], "y`=(%s)^sin(%s)*(%s)",
        polynomial(buf[0],2, a,"x^2",b,""),
        poly2ns(buf[1],1, c,24,1,1,"pi*x"),
        poly2ns(buf[2],2,
            c,24,1,1, chprintf(buf[3],"pi*cos(%s)*ln(%s)", poly2ns(buf[4],1, c,24,1,1,"pi*x"), polynomial(buf[5],2, a,"x^2",b,"")),
            2*a,1,1,1, chprintf(buf[6],"sin(%s)*x/(%s)", poly2ns(buf[7],1, c,24,1,1,"pi*x"), polynomial(buf[8],2, a,"x^2",b,""))
        )
    );
    sprintf(answ[1], "y`=(%s)*(%s)^sin(%s)*ln(%s)*cos(%s)",
        poly2ns(buf[1],1, c,24,1,1,"pi*x"),
        polynomial(buf[2],2, a,"x^2",b,""),
        poly2ns(buf[3],1, c,24,1,1,"pi*x"),
        polynomial(buf[4],2, a,"x^2",b,""),
        poly2ns(buf[5],1, c,24,1,1,"pi*x")
    );
    sprintf(answ[2], "y`=(%s)*(%s)^cos(%s)*ln(%s)",
        poly2ns(buf[1],1, c,24,1,1,"pi*x"),
        polynomial(buf[2],2, a,"x^2",b,""),
        poly2ns(buf[3],1, c,24,1,1,"pi*x"),
        polynomial(buf[4],2, a,"x^2",b,"")
    );
    sprintf(answ[3], "y`=sin(%s)*(%s)^(sin(%s)-1)*(%s)",
        poly2ns(buf[1],1, c,24,1,1,"pi*x"),
        polynomial(buf[2],2, a,"x^2",b,""),
        poly2ns(buf[3],1, c,24,1,1,"pi*x"),
        polynomial(buf[4],1, 2*a,"x")
    );

    sprintf(src, "y=(a*x^2+b)^sin((pi/24)*c*x)");
}

void deriv503 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b,c,p;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        p=rndr(r);
    }while(!(a>0 && b!=0 && p!=0 && p-1!=0));

    strcpy(task, "");
    char *z;
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=((1/pi)*arcsin(%s))^(%s)",
        poly2ns(buf[0],1, 1,a,1,1,"x"),
        memb(buf[9], b,1,p,1,"x",false)
    );
    catprintf(task, "\n%s", "y`=...");
    sprintf(src, "y=((1/pi)*arcsin(a*x))^(b*x^p)");

    sprintf(answ[0], "y`=(%s)^(%s)*((%s)*ln(%s)+(%s)/((%s)*sqrt(%s)))",
        polynomial(buf[0],2, 1,chprintf(buf[1],"(1/pi)*arcsin(%s)", poly2ns(buf[2],1,1,a,1,1,"x")), c,""),
        memb(buf[3], b,1,p,1,"x",false),
        memb(buf[4], b*p,1,p-1,1,"x",false),
        polynomial(buf[5],2, 1,chprintf(buf[6],"(1/pi)*arcsin(%s)", poly2ns(buf[7],1,1,a,1,1,"x")), c,""),
        memb(buf[8],b,1,p,1,"x",false),
        polynomial(buf[9],2, 1,chprintf(buf[10],"(1/pi)*arcsin(%s)", poly2ns(buf[11],1,1,a,1,1,"x")), c,""),
        polynomial(buf[12],2, a*a,"", -1,"x^2")
    );
    sprintf(answ[1], "y`=(%s)^(%s)*((%s)*ln(%s))",
        polynomial(buf[0],2, 1,chprintf(buf[1],"(1/pi)*arcsin(%s)", poly2ns(buf[2],1,1,a,1,1,"x")), c,""),
        memb(buf[3], b,1,p,1,"x",false),
        memb(buf[4], b*p,1,p-1,1,"x",false),
        polynomial(buf[5],2, 1,chprintf(buf[6],"(1/pi)*arcsin(%s)", poly2ns(buf[7],1,1,a,1,1,"x")), c,"")
    );
    sprintf(answ[2], "y`=((1/pi))*(%s)*(%s)^(%s-1)*(1/sqrt(%s))",
        poly2ns(buf[9],2, b,1,p,1,"x", -1,1,1,1,""),
        polynomial(buf[0],2, 1,chprintf(buf[1],"(1/pi)*arcsin(%s)", poly2ns(buf[2],1,1,a,1,1,"x")), c,""),
        memb(buf[3], b,1,p,1,"x",false),
        polynomial(buf[4],2, a*a,"", -1,"x^2")
    );
    sprintf(answ[3], "y`=((1/pi)*(1/sqrt(%s))^(%s))",
        polynomial(buf[10],2, a*a,"", -1,"x^2"),
        memb(buf[4], b*p,1,p-1,1,"x",false)
    );
    
}


void deriv504 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while(!(a>0 && d!=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)^tg(%s)",
        polynomial(buf[0],3, a,"x^2", b,"x", c,""),
        memb(buf[1], d,12,1,1,"pi*x",false)
    );
    catprintf(task, "\n%s", "y`=...");
    sprintf(src, "y=(a*x^2+b*x+c)^tg((pi/12)*d*x)");

    sprintf(answ[0], "y`=(%s)^tg(%s)*((%s)*(1/cos(%s)^2)*ln(%s)+tg(%s)*(%s)/(%s))",
        polynomial(buf[0],3, a,"x^2", b,"x", c,""),
        memb(buf[1], d,12,1,1,"pi*x",false),
        memb(buf[2], d,12,1,1,"pi", false),
        memb(buf[3], d,12,1,1,"pi*x",false),
        polynomial(buf[4],3, a,"x^2", b,"x", c,""),
        memb(buf[5], d,12,1,1,"pi*x",false),
        polynomial(buf[6],2, 2*a,"x",b,""),
        polynomial(buf[7],3, a,"x^2", b,"x", c,"")
    );
    sprintf(answ[1], "y`=(%s)^tg(%s)*(%s*(1/cos(%s)^2)*ln(%s))",
        polynomial(buf[0],3, a,"x^2", b,"x", c,""),
        memb(buf[1], d,12,1,1,"pi*x",false),
        memb(buf[2], d,12,1,1,"pi", false),
        memb(buf[3], d,12,1,1,"pi*x",false),
        polynomial(buf[4],3, a,"x^2", b,"x", c,"")
    );
    sprintf(answ[2], "y`=tg(%s)*(%s)^(tg(%s)-1)*(%s)",
        memb(buf[9], d,12,1,1,"pi*x",false),
        polynomial(buf[0],3, a,"x^2", b,"x", c,""),
        memb(buf[1], d,12,1,1,"pi*x",false),
        polynomial(buf[2],2, 2*a,"x", b,"")
    );
    sprintf(answ[3], "y`=(%s)^(%s/(cos(%s)^2))",
        polynomial(buf[2],2, 2*a,"x", b,""),
        memb(buf[9], d,1,1,1,"pi",false),
        memb(buf[1], d,12,1,1,"pi*x",false)
    );

}

void deriv505 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b,c,d;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
    }while(!(a>0 && d!=0 && abs(d)!=1));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=((1/pi)*arctg(%s))^ln(%s)",
        poly2ns(buf[0],1, 1,d,1,1,"x"),
        polynomial(buf[1],3, a,"x^2", b,"x", c,"")
    );
    catprintf(task, "\n%s", "y`=...");
    sprintf(src, "y=((1/pi)*arctg(x/d))^ln(a*x^2+b*x+c)");

    sprintf(answ[0], "y`=((1/pi)*arctg(%s))^ln(%s)*((%s)/(%s)*ln((1/pi)*arctg(%s))+((%d)*ln(%s))/((%s)*arctg(%s)))",
        poly2ns(buf[0],1, 1,d,1,1,"x"),
        polynomial(buf[1],3, a,"x^2", b,"x", c,""),
        polynomial(buf[2],2, 2*a,"x", b,""),
        polynomial(buf[3],3, a,"x^2", b,"x", c,""),
        poly2ns(buf[4],1, 1,d,1,1,"x"),
        d,
        polynomial(buf[5],3, a,"x^2", b,"x", c,""),
        polynomial(buf[6],2, d*d,"", 1,"x^2"),
        poly2ns(buf[4],1, 1,d,1,1,"x")
    );
    sprintf(answ[1], "y`=((1/pi)*arctg(%s))^ln(%s)*((%s)/(%s)*ln((1/pi)*arctg(%s)))",
        poly2ns(buf[0],1, 1,d,1,1,"x"),
        polynomial(buf[1],3, a,"x^2", b,"x", c,""),
        polynomial(buf[2],2, 2*a,"x", b,""),
        polynomial(buf[3],3, a,"x^2", b,"x", c,""),
        poly2ns(buf[4],1, 1,d,1,1,"x")
    );
    sprintf(answ[2], "y`=ln(%s)*((1/pi)*arctg(%s))^(ln(%s)-1)*(%d)/((%s)*arctg(%s))",
        polynomial(buf[1],3, a,"x^2", b,"x", c,""),
        poly2ns(buf[2],1, 1,d,1,1,"x"),
        polynomial(buf[3],3, a,"x^2", b,"x", c,""),
        d,
        polynomial(buf[4],2, 1,"x^2", d*d,""),
        poly2ns(buf[5],1, 1,d,1,1,"x")
    );
    sprintf(answ[3], "y`=ln(%s)*((1/pi)*arctg(%s))^(ln(%s)-1)*(1/(%s))",
        polynomial(buf[1],3, a,"x^2", b,"x", c,""),
        poly2ns(buf[2],1, 1,d,1,1,"x"),
        polynomial(buf[3],3, a,"x^2", b,"x", c,""),
        polynomial(buf[4],1, d,chprintf(buf[5], "arctg(%s)", poly2ns(buf[7],1, 1,d,1,1,"x")))
    );
}

void deriv506 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b,c;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
    }while(!(a!=0 && b!=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=!(cos(%s))^(e^(%s))",
        polynomial(buf[0],1, a,"pi*x"),
        polynomial(buf[1],2, b,"x", c,"")
    );
    catprintf(task, "\n%s", "y`=...");
    sprintf(src, "y=cos(pi*a*x)^(e^(b*x+c))");

    sprintf(answ[0], "y`=e^(%s)*(!(cos(%s))^(e^(%s)))*(%s)",
        polynomial(buf[1],2, b,"x", c,""),
        polynomial(buf[2],1, a,"pi*x"),
        polynomial(buf[3],2, b,"x", c,""),
        polynomial(buf[4],2,
            b,  chprintf(buf[5],"ln(cos(%s))",polynomial(buf[6],1, a,"pi*x")),
            -a, chprintf(buf[7],"pi*tg(%s)",polynomial(buf[8],1, a,"pi*x"))
        )
    );
    sprintf(answ[1], "y`=(%s)*e^(%s)*(!(cos(%s))^(e^(%s)-1))*sin(%s)",
        polynomial(buf[0],1,-a,"pi"),
        polynomial(buf[1],2, b,"x", c,""),
        polynomial(buf[2],1, a,"pi*x"),
        polynomial(buf[3],2, b,"x", c,""),
        polynomial(buf[4],1, a,"pi*x")
    );
    sprintf(answ[2], "y`=(!(cos(%s))^(e^(%s)))*ln(cos(%s))*(%s)",
        polynomial(buf[2],1, a,"pi*x"),
        polynomial(buf[3],2, b,"x", c,""),
        polynomial(buf[4],1, a,"pi*x"),
        polynomial(buf[5],1, b,chprintf(buf[6],"e^(%s)",polynomial(buf[7],2, b,"x",c,"")))
    );
    sprintf(answ[3], "y`=(%s)*e^(%s)*(!(cos(%s))^(e^(%s)))*tg(%s)",
        polynomial(buf[0],1, a,"pi"),
        polynomial(buf[1],2, b,"x", c,""),
        polynomial(buf[2],1, a,"pi*x"),
        polynomial(buf[3],2, b,"x", c,""),
        polynomial(buf[4],1, a,"pi*x")
    );
}

void deriv507 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b,c,m;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        m=rndr(r);
    }while(!(a!=0 && b!=0 && m>0 && c!=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)^ctg(%s)",
        poly2ns(buf[0],2, a,1,m,1,"x", b,1,1,1,""),
        memb(buf[1], 1,c,1,1,"pi*x", false)
    );
    catprintf(task, "\n%s", "y`=...");
    sprintf(src, "y=(a*x^m+b)^ctg(pi/c*x)");

    sprintf(answ[0], "y`=(%s)^ctg(%s)*((pi/(%s))*ln(%s)+(ctg(%s)*((%s)/(%s))))",
        poly2ns(buf[0],2, a,1,m,1,"x", b,1,1,1,""),
        memb(buf[1], 1,c,1,1,"pi*x", false),
        memb(buf[2], -c,1,2,1,chprintf(buf[3],"sin(%s)",memb(buf[4],1,c,1,1,"pi*x",false)),false),
        poly2ns(buf[5],2, a,1,m,1,"x", b,1,1,1,""),
        memb(buf[6], 1,c,1,1,"pi*x", false),
        memb(buf[7], m*a,1,m-1,1,"x",false),
        poly2ns(buf[8],2, a,1,m,1,"x", b,1,1,1,"")
    );
    sprintf(answ[1], "y`=(%s)^ctg(%s)*((pi/(%s))*ln(%s)+(ctg(%s)*((%s)/(%s))))",
        poly2ns(buf[0],2, a,1,m,1,"x", b,1,1,1,""),
        memb(buf[1], 1,c,1,1,"pi*x", false),
        memb(buf[2], c,1,2,1,chprintf(buf[3],"cos(%s)",memb(buf[4],1,c,1,1,"pi*x",false)),false),
        poly2ns(buf[5],2, a,1,m,1,"x", b,1,1,1,""),
        memb(buf[6], 1,c,1,1,"pi*x", false),
        memb(buf[7], m*a,1,m-1,1,"x",false),
        poly2ns(buf[8],2, a,1,m,1,"x", b,1,1,1,"")
    );
    sprintf(answ[2], "y`=(%s)^ctg(%s)*ln(%s)*(pi/(%s))",
        poly2ns(buf[0],2, a,1,m,1,"x", b,1,1,1,""),
        memb(buf[1], 1,c,1,1,"pi*x", false),
        poly2ns(buf[2],2, a,1,m,1,"x", b,1,1,1,""),
        memb(buf[3], -c,1,2,1,chprintf(buf[4],"sin(%s)",memb(buf[5],1,c,1,1,"pi*x",false)),false)
    );
    sprintf(answ[3], "y`=(%s)^(pi/(%s))",
        memb(buf[0], m*a,1,m-1,1,"x", false),
        memb(buf[1], -c,1,2,1,chprintf(buf[2],"sin(%s)",memb(buf[3],1,c,1,1,"pi*x",false)),false)
    );
}

void deriv508 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0));

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)^(%s)",
        polynomial(buf[0],2, 1,"x^2", a*a,""),
        polynomial(buf[1],2, 1,chprintf(buf[2],"(1/pi)*arctg(%s)",poly2ns(buf[3],1, 1,a,1,1,"x")), b,"")
    );
    catprintf(task, "\n%s", "y`=...");
    sprintf(src, "y=(x^2+a^2)^((1/pi)*arctg(x/a)+b)");

    sprintf(answ[0], "y`=(%s)^(%s)*((%d/pi)*ln(%s)+2*x*(%s))",
        polynomial(buf[0],2, 1,"x^2", a*a,""),
        polynomial(buf[1],2, 1,chprintf(buf[2],"(1/pi)*arctg(%s)",poly2ns(buf[3],1, 1,a,1,1,"x")), b-1,""),
        a,
        polynomial(buf[4],2, 1,"x^2", a*a,""),
        polynomial(buf[5],2, 1,chprintf(buf[6],"(1/pi)*arctg(%s)",poly2ns(buf[7],1, 1,a,1,1,"x")), b,"")
    );
    sprintf(answ[1], "y`=(%s)^(%s)*ln(%s)*(%d/(pi*(%s)))",
        polynomial(buf[0],2, 1,"x^2", a*a,""),
        polynomial(buf[1],2, 1,chprintf(buf[2],"(1/pi)*arctg(%s)",poly2ns(buf[3],1, 1,a,1,1,"x")), b-1,""),
        polynomial(buf[4],2, 1,"x^2", a*a,""),
        a,
        polynomial(buf[5],2, 1,"x^2", a*a,"")
    );
    sprintf(answ[2], "y`=(%s)*(%s)^(%s)*2*x",
        polynomial(buf[1],2, 1,chprintf(buf[2],"(1/pi)*arctg(%s)",poly2ns(buf[3],1, 1,a,1,1,"x")), b,""),
        polynomial(buf[0],2, 1,"x^2", a*a,""),
        polynomial(buf[4],2, 1,chprintf(buf[5],"(1/pi)*arctg(%s)",poly2ns(buf[6],1, 1,a,1,1,"x")), b-1,"")
    );
    sprintf(answ[3], "y`=(%s+2*x*(%s))*(2*x)^(%s)",
        memb(buf[0],a,1,1,1,chprintf(buf[1],"ln(%s)",polynomial(buf[2],2,1,"x^2",a*a,"")),false),
        polynomial(buf[3],2, 1,chprintf(buf[4],"(1/pi)*arctg(%s)",poly2ns(buf[5],1, 1,a,1,1,"x")), b,""),
        polynomial(buf[6],2, 1,chprintf(buf[7],"(1/pi)*arctg(%s)",poly2ns(buf[8],1, 1,a,1,1,"x")), b,"")
    );
}

// -------------------------------------------------------------------------- //
void deriv50101v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,k;
    bool done;
    float answ[4];
    do{
        do{
            a=rndr(r);
            b=rndr(r);
            k=rndr(range(2,4));
        }while(!(a!=0 && k!=0 && b!=k*k));
        float delta;
        answ[0]=pow(3.0/2.0,k)*((float)b/(2.0*k)*log(3.0/2.0)+a*k*pi*sqrt(3)/3);
        answ[1]=k*a*pi*pow(3.0/2.0,k-1)*sqrt(3.0)/2.0;
        answ[2]=(float)b/(2.0*k)*log(3.0/2.0)+k*a*pi*sqrt(3)/3.0;
        answ[3]=pow(3.0/2.0,k)*log(3.0/2.0)*(float)b/(2.0*k);
        done=true;
        for(int i=0; i<4; ++i)
            for(int j=0; j<4; ++j)
                if (i!=j && fabs(answ[i]-answ[j])<0.1)
                {
                    done=false;
                    break;
                }
    }while(!done);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(1+sin(%s))^sqrt(%s)", polynomial(buf[0],1,a,"pi*x"), poly2ns(buf[1],2, b,1,1,1,"x", -b+6*a*k*k,6*a,1,1,""));
    catprintf(task, "\nx_0=%s", fraction(buf[0],1,1,6*a));
    sprintf(src, "y=(1+sin(pi*a*x))^sqrt(b*x+(-b*6*a*k^2)/(6*a))");

    for(int i=0; i<4; ++i)
        sprintf(ans[i], "y`&!(x_0)=%1.2f", answ[i]);
}

void deriv50102v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    float a,b,k;
    bool done;
    float answ[4];
    do{
        do{
            a=rndr(r);
            b=rndr(r);
            k=rndr(range(2,4));
        }while(!(fabs(a)>0.1 && fabs(k)>0.1 && fabs(b-k*k)>0.1 && fabs(b)!=0));
        float delta;
        answ[0]=pow(1.0+sqrt(3.0)/2.0,k)*(b/(2.0*k)*log(1.0+sqrt(3.0)/2.0)+k*a*pi/(2.0+sqrt(3.0)));
        answ[1]=pow(1.0+sqrt(3.0)/2.0,k)*((float)b/k*log(1.0+sqrt(3)/2.0)+(float)k*pi*sqrt(3.0)/(2.0+sqrt(3.0)));
        answ[2]=pow(3.0/2.0,k-1)*(b/(2.0*k)*log(1.5)+pi*k/(2+sqrt(3.0)));
        answ[3]=pow(1.0+sqrt(3.0)/2.0,k)*(1.0/(float)k*log(1.0+sqrt(3.0)/2.0)+pi/sqrt(3));
        done=true;
        for(int i=0; i<4; ++i)
            for(int j=0; j<4; ++j)
                if (i!=j && fabs(answ[i]-answ[j])<0.1)
                {
                    done=false;
                    break;
                }
    }while(!done);
    int ai=a, bi=b, ki=k;

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(1+sin(%s))^sqrt(%s)", polynomial(buf[0],1,ai,"pi*x"), poly2ns(buf[1],2, bi,1,1,1,"x", -bi+3*ai*ki*ki,3*ai,1,1,""));
    catprintf(task, "\nx_0=%s", fraction(buf[0],1,1,3*ai));

    for(int i=0; i<4; ++i)
        sprintf(ans[i], "y`&!(x_0)=%1.2f", answ[i]);

    sprintf(src, "y=(1+sin(a*pi*x))^sqrt(b*x+(-b+3*a*k^2)/(3*a))");
}

void deriv50103v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    float a,b,k;
    bool done;
    float answ[4];
    do{
        do{
            a=rndr(r);
            b=rndr(r);
            k=rndr(range(2,4));
        }while(!(fabs(a)>0.1 && fabs(k)>0.1 && fabs(b-k*k)>0.1));
        float delta;
        answ[0]=pow(2,k-1)*b*log(2.0)/k;
        answ[1]=pow(2,k-1)*b;
        answ[2]=pow(2,k)*log(2);
        answ[3]=pow(2,k)*(b/k*log(2)+k*a*pi/2);
        done=true;
        for(int i=0; i<4; ++i)
            for(int j=0; j<4; ++j)
                if (i!=j && fabs(answ[i]-answ[j])<0.1)
                {
                    done=false;
                    break;
                }
    }while(!done);
    int ai=a, bi=b, ki=k;

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(1+sin(%s))^sqrt(%s)", polynomial(buf[0],1,ai,"pi*x"), poly2ns(buf[1],2, bi,1,1,1,"x", -bi+2*ai*ki*ki,2*ai,1,1,""));
    catprintf(task, "\nx_0=%s", fraction(buf[0],1,1,2*ai));
    sprintf(src, "y=(1+sin(a*pi*x))^sqrt(b*x+(-b+2*a*k^2)/(2*a))");

    for(int i=0; i<4; ++i)
        sprintf(ans[i], "y`&!(x_0)=%1.2f", answ[i]);
}

void deriv50104v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    float a,b,k;
    bool done;
    float answ[4];
    do{
        do{
            a=rndr(r);
            b=rndr(r);
            k=rndr(range(2,4));
        }while(!(fabs(a)>0.1 && fabs(k)>0.1 && fabs(b-k*k)>0.1));
        float delta;
        answ[0]=pow(3.0/2.0,k)*(b/(2*k)*log(1.5)+k*a*pi*sqrt(3)/3.0);
        answ[1]=pow(3.0/2.0,k-1)*(b/k*log(1.5)+k*a*pi*sqrt(3));
        answ[2]=pow(1.0/2.0,k)*(1.0/k+2*k*a*pi/3);
        answ[3]=pow(1.5,k-1)*(b/(2*k)+k*a*pi/sqrt(3));
        done=true;
        for(int i=0; i<4; ++i)
            for(int j=0; j<4; ++j)
                if (i!=j && fabs(answ[i]-answ[j])<0.1)
                {
                    done=false;
                    break;
                }
    }while(!done);
    int ai=a, bi=b, ki=k;

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(1+sin(%s))^sqrt(%s)", polynomial(buf[0],1,ai,"pi*x"), poly2ns(buf[1],2, bi,1,1,1,"x", -bi+6*ai*ki*ki,6*ai,1,1,""));
    catprintf(task, "\nx_0=%s", fraction(buf[0],1,1,6*ai));
    sprintf(src, "y=(1+sin(a*pi*x))^sqrt(b*x+(-b+6*a*k^2)/(6*a))");

    for(int i=0; i<4; ++i)
        sprintf(ans[i], "y`&!(x_0)=%1.2f", answ[i]);
}

void deriv50105v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    float a,b,k;
    bool done;
    float answ[4];
    do{
        do{
            a=rndr(r);
            b=rndr(r);
            k=rndr(range(2,4));
        }while(!(fabs(a)>0.1 && fabs(k)>0.1 && fabs(b-k*k)>0.1));
        float delta;
        answ[0]=pow(2,k-1)*b*log(2)/k;
        answ[1]=0;
        answ[2]=pow(2,k)*log(2)*b/k;
        answ[3]=b/(2*k)*log(2);
        done=true;
        for(int i=0; i<4; ++i)
            for(int j=0; j<4; ++j)
                if (i!=j && fabs(answ[i]-answ[j])<0.1)
                {
                    done=false;
                    break;
                }
    }while(!done);
    int ai=a, bi=b, ki=k;

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(1+sin(%s))^sqrt(%s)", polynomial(buf[0],1,ai,"pi*x"), poly2ns(buf[1],2, bi,1,1,1,"x", -bi+2*ai*ki*ki,2*ai,1,1,""));
    catprintf(task, "\nx_0=%s", fraction(buf[0],1,1,2*ai));
    sprintf(src, "y=(1+sin(a*pi*x))^sqrt(b*x+(-b+2*a*k^2)/(2*a))");

    for(int i=0; i<4; ++i)
        sprintf(ans[i], "y`&!(x_0)=%1.2f", answ[i]);
}

void deriv50201v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int ai, ci, ip;
    float answ[4];
    {
    float a,c,p;
    bool done;
    do{
        do{
            a=rndr(r);
            c=rndr(r);
            p=rndr(range(2,4));
        }while(!(fabs(a)>0.1 && fabs(c)>0.1 && fabs(c)>0.1));
        float delta;
        answ[0]=exp(p/2.0)*(pi*c*p*sqrt(3.0)/48.0+4.0*a/(c*exp(p)));
        answ[1]=exp(-p/2)*4*a/c;
        answ[2]=exp(-p/2)*(pi*c*p*sqrt(3)/24+a/(c*exp(p)));
        answ[3]=exp(p/2)*pi*c*p*sqrt(3)/48;
        done=true;
        for(int i=0; i<4; ++i)
            for(int j=0; j<4; ++j)
                if (i!=j && fabs(answ[i]-answ[j])<0.1)
                {
                    done=false;
                    break;
                }
    }while(!done);
    ai=a, ci=c, ip=p;
    }

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)^sin(%s)",
        polynomial(buf[0],2, ai,"x^2", 1,chprintf(buf[8],"%s",poly2ns(buf[7],2, 1,1,ip,1,"e", -ai*16,ci*ci,1,1,""))),
        poly2ns(buf[1],1, ci,24,1,1,"pi*x")
    );
    catprintf(task, "\nx_0=%s", fraction(buf[0],4,1,ci));
    sprintf(src, "y=(a*x^2+e^p-(a*16)/(c^2))^sin(((c*pi)/24)*x)");

    for(int i=0; i<4; ++i)
        sprintf(ans[i], "y`&!(x_0)=%1.2f", answ[i]);
}

//?
/*
void deriv50202v (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int ai, ci, ip;
    float answ[4];
    {
    float a,c,p;
    bool done;
    do{
        do{
            a=rndr(r);
            c=rndr(r);
            p=rndr(range(2,4));
        }while(!(fabs(a)>0.1 && fabs(c)>0.1));
        float delta;
        answ[0]=6*a/c;
        answ[1]=6*a/c*exp(p);
        answ[2]=2*a/c*exp(p);
        answ[3]=p*pi*c/24;
        done=true;
        for(int i=0; i<4; ++i)
            for(int j=0; j<4; ++j)
                if (i!=j && fabs(answ[i]-answ[j])<0.1)
                {
                    done=false;
                    break;
                }
    }while(!done);
    ai=a, ci=c, ip=p;
    }
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "%s", SEP);
    catprintf(task, "\ny=(%s)^sin(%s)", polynomial(buf[0],2, ai,"x^2", 1,chprintf(buf[8],"%s",poly2ns(buf[7],2, ip,1,1,1,"", -ai*144,ci*ci,1,1,""))), poly2ns(buf[1],1, ci,24,1,1,"pi*x"));
    catprintf(, SEP);
    catprintf(task, "x_0=%s", fraction(buf[0],12,1,ci));
    catprintf(task, "%s%s", SEP,SEP);
    for(int i=0; i<4; ++i)
        sprintf(answ[i], "y`&!(x_0)=%1.2f%s", answ[i], (i!=3?SEP:""));
    sprintf(src, "y=!!!");
}
*/

void deriv050201v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,c,i,j,p;
    float answ[4];
    bool done;
    do{
        do{
            a=rndr(r);
            c=rndr(r);
            p=rndr(range(2,4));
        }while(!(c!=0 && a>0));
        answ[0]=exp(p/2.0)*(pi*c*p*sqrt(3)/48.0+4.0*a/(c*exp(p)));
        answ[1]=exp(-p/2.0)*4.0*a/c;
        answ[2]=exp(p/2.0)*(pi*c*p*sqrt(3)/24+a/(c*exp(p)));
        answ[3]=exp(p/2.0)*pi*c*p*sqrt(3)/48;
        for(done=true, i=0; i<4; ++i)
            for(j=i+1; j<4; ++j)
                if (fabs(answ[i]-answ[j])<0.3)
                    done=false;
    }while(!done);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)^sin(%s)",
        poly2ns(buf[0],3, a,1,1,1,"x^2", 1,1,p,1,"e", -a*4*4,c*c,1,1,""),
        memb(buf[1], c,24,1,1,"pi*x",false)
    );
    catprintf(task, "\nx_0=%s", fraction(buf[0],4,1,c));
    sprintf(src, "y=(a*x^2+e^p-(a*16)/(c^2))^sin(((c*pi)/24)*x)");

    for(i=0; i<4; ++i)
        sprintf(ans[i], "y`&!(x_0)=%1.4f", answ[i]);

}

void deriv050202v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,c,p,j,i;
    float answ[4];
    bool done;
    do{
        do{
            a=rndr(r);
            c=rndr(r);
            p=rndr(range(2,4));
        }while(!(c!=0 && a>0));
        answ[0]=24.0*a/c;
        answ[1]=6*a*exp(p)/c;
        answ[2]=2*a*exp(p)/c;
        answ[3]=p*pi*c/24.0;
        for(done=true, i=0; i<4; ++i)
            for(j=i+1; j<4; ++j)
                if (fabs(answ[i]-answ[j])<0.3)
                    done=false;
    }while(!done);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)^sin(%s)",
        poly2ns(buf[0],2, a,1,1,1,"x^2", -a*12*12 + p*c*c,c*c,1,1,""),
        memb(buf[1], c,24,1,1,"pi*x",false)
    );
    catprintf(task, "\nx_0=%s", fraction(buf[0],12,1,c));

    for(i=0; i<4; ++i)
        sprintf(ans[i], "y`&!(x_0)=%1.4f", answ[i]);
    sprintf(src, "y=(a*x^2-(a*144+p*c^2)/(c^2))^sin(((pi*c)/24)*x)");
}

/*
void deriv050301v (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b,p,q,j,i;
    float answ[4];
    bool done;
    do{
        do{
            a=rndr(r);
            b=rndr(r);
            p=rndr(range(2,4));
            q=rndr(range(2,4));
        }while(!(a>0 && b!=0 && q!=0));
        answ[0]=b*pow(q,b*pow(a/2.0,p))*pow(a/2.0,p-1)*(p*log(q)+b*sqrt(3)/(3.0*q));
        answ[1]=pow(q,b*pow(a/2.0,p))*b*p*pow(a/2.0,p-1)*log(q);
        answ[2]=1/pi*(b*pow(a/2.0,p)-1)*pow(q,b*pow(a/2.0,p)-1)*2/(a*sqrt(3));
        answ[3]=pow(1/pi*2/(a*sqrt(3)), b*p*pow(a/2.0,p-1));
        for(done=true, i=0; i<4; ++i)
            for(j=i+1; j<4; ++j)
                if (fabs(answ[i]-answ[j])<0.3)
                    done=false;
    }while(!done);
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "%s", SEP);
    catprintf(task, "\ny=((1/pi)*arcsin(%s)%s)^(%s)",
        poly2ns(buf[0], 1,a,1,1,"x"),
        poly2s(buf[1],1, q*b-1,b,1,1,""),
        poly2ns(buf[2],1, b,1,p,1,"x")
    );
    catprintf(task, "%s", SEP);
    catprintf(task, "x_0=%s", fraction(buf[0],a,1,2));
    catprintf(task, "%s%s", SEP, SEP);
    for(i=0; i<4; ++i)
        sprintf(answ[i], "y`&!(x_0)=%1.4f%s", answ[i], (i!=3?SEP:""));
    sprintf(src, "y=!!!");
}

void deriv050302v (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ]);
void deriv050303v (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ]);
//(it won't work!)

*/



// sometimes falls
void deriv050401v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b,d,p, j,i;
    float answ[4];
    bool done;
    do{
        do{
            a=rndr(r);
            b=rndr(r);
            p=rndr(range(2,4));
            d=rndr(r);
        }while(!(d!=0 && a>0));
        answ[0]=p*(pi*d*log(p)/6+(6*a+b*d)/(p*d));
        answ[1]=pi*p*d*log(p)/6;
        answ[2]=6*a/d+b;
        answ[3]=pow((6*a+b*d)/6, 2*pi*d);
        for(done=true, i=0; i<4; ++i)
            for(j=i+1; j<4; ++j)
                if (fabs(answ[i]-answ[j])<0.3)
                    done=false;
    }while(!done);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)^tg(%s)",
        poly2ns(buf[0],3, a,1,2,1,"x", b,1,1,1,"x", p*d*d-a*3*3-b*3*d,d*d,1,1,""),
        memb(buf[1], d,12,1,1,"pi*x",false)
    );
    catprintf(task, "\nx_0=%s", fraction(buf[0],3,1,d));

    for(i=0; i<4; ++i)
        sprintf(ans[i], "y`&!(x_0)=%1.4f", answ[i]);
    sprintf(src, "y=(a*x^2+b*x+(p*d^2-a*9-b*d*3)/(d^2))^tg(((pi*d)/12)*x)");
}

void deriv050501v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b,d,p, j,i;
    float answ[4];
    bool done;
    do{
        do{
            a=rndr(r);
            b=rndr(r);
            p=rndr(range(2,4));
            d=rndr(r);
        }while(!(d!=0 && a>0 && a*d*d+b*d+p-a*d*d-b*d!=0));
        answ[0]=pow(1.0/4.0, log(p))*(2*log(p)/(d*pi)-(2*a*d+b)*log(4)/(a*d*d+b*d+p-a*d*d-b*d));
        answ[1]=-pow(1.0/4.0, log(p))*((2*a*d+b)*log(4)/(a*d*d+b*d+p-a*d*d-b*d));
        answ[2]=pow(1.0/4.0, log(a*d*d+b*d+p-a*d*d-b*d)-1)*log(a*d*d+b*d+p-a*d*d-b*d)*2*log(p)/(d*pi);
        answ[3]=pow(1.0/4.0, log(p))*(4*log(p)/d-(2*a*d+b)*log(4)/(a*d*d+b*d+p-a*d*d-b*d));
        for(done=true, i=0; i<4; ++i)
            for(j=i+1; j<4; ++j)
                if (fabs(answ[i]-answ[j])<0.1)
                    done=false;
    }while(!done);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=((1/pi)*arctg(%s))^ln(%s)",
        memb(buf[0], 1,d,1,1,"x",false),
        poly2ns(buf[1],3, a,1,2,1,"x", b,1,1,1,"x", p-a*d*d-b*d,1,1,1,"")
    );
    catprintf(task, "\nx_0=%d", d);

    for(i=0; i<4; ++i)
        sprintf(ans[i], "y`&!(x_0)=%1.4f", answ[i]);
    sprintf(src, "y=((1/pi)*arctg(x/d))^ln(a*x^2+b*x+p-a*d^2-b*d)");
}

void deriv050601v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b,p,m, j,i;
    float answ[4];
    bool done;
    do{
        do{
            a=rndr(r);
            b=rndr(r);
            p=rndr(r);
        }while(!(a!=0 && p>0));
        answ[0]=-p*pow(1.0/2.0,p)*(b*log(2)+pi*a*sqrt(3));
        answ[1]=-p*b*pow(1.0/2.0,p)*log(2);
        answ[2]=-pi*a*p*pow(1.0/2.0,p)*sqrt(3);
        answ[3]=p*a*pow(1.0/2.0,p)*sqrt(3);
        for(done=true, i=0; i<4; ++i)
            for(j=i+1; j<4; ++j)
                if (fabs(answ[i]-answ[j])<0.1)
                    done=false;
    }while(!done);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=!(cos(%s))&String(\"^\")&!(e^(%s))",
        polynomial(buf[0],1, a,"pi*x"),
        poly2ns(buf[1],3, b,1,1,1,"x", 1,1,1,1,chprintf(buf[2],"ln(%d)",p), b,3*a,1,1,"")
    );
    catprintf(task, "\nx_0=%s", fraction(buf[0],1,1,3*a));

    for(i=0; i<4; ++i)
        sprintf(ans[i], "y`&!(x_0)=%1.4f", answ[i]);
    sprintf(src, "y=!(cos(pi*a*x))&String(\"^\")&!(e^(b*x+ln(p)+b/(3*a)))");
}

void deriv050701v (const range& r, char task[BUFSZ], char ans[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,c,p,m, j,i;
    float answ[4];
    bool done;
    do{
        do{
            a=rndr(r);
            c=rndr(r);
            p=rndr(r);
            m=rndr(r);
        }while(!(a>0 && c!=0 && m>0));
        answ[0]=m*a*pow(c,m-1)/pow(4,m-1)-2*pi*p*log(p)/c;
        answ[1]=m*a*pow(c,m-1)/pow(4,m)+2.0*pi*p*log(p)/3.0;
        answ[2]=-2*pi*p*log(p)/c;
        answ[3]=pow(m*a*pow(c/4.0,m-1),-2*pi/c);
        for(done=true, i=0; i<4; ++i)
            for(j=i+1; j<4; ++j)
                if (fabs(answ[i]-answ[j])<0.1)
                    done=false;
    }while(!done);

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)^ctg(%s)",
        poly2ns(buf[0],2, a,1,m,1,"x", p*pow(4,m)-a*pow(c,m),pow(4,m),1,1,""),
        memb(buf[1], 1,c,1,1,"pi*x", false)
    );
    catprintf(task, "\nx_0=%s", fraction(buf[0],c,1,4));

    for(i=0; i<4; ++i)
        catprintf(ans[i], "y`&!(x_0)=%1.4f", answ[i]);
    sprintf(src, "y=(a*x^m+p*4^m-a*c^m)^ctg((pi/c)*x)");
}

/*
void deriv050801v (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(false);

    strcpy(task, "");
    sprintf(, "%1.4f", pow(2*a*a,b+0.25)*(a/pi*log(2*a*a)+2*a*b+0.5*a));
    sprintf(src, "y=!!!");
}
*/


void deriv601 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    char axpb[BUFSZ], cxpd[BUFSZ], pxpq[BUFSZ];
    int a,b,c,d,n,m,p,q,k;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
        m=rndr(r);
        n=rndr(r);
        k=rndr(r);
        p=rndr(r);
        q=rndr(r);
    }while(!(a>0 && c>0 && p>0 && b*d*q!=0 && n>1 && m>1 && k>1));

    strcpy(task, "");
    polynomial(axpb,2, a,"x",b,"");
    polynomial(cxpd,2, c,"x",d,"");
    polynomial(pxpq,2, p,"x",q,"");

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)*(%s)",
        memb(buf[0], 1,1,m,n, axpb, false),
        memb(buf[1], 1,1,k,1, chprintf(buf[2], "(%s)/(%s)", cxpd, pxpq), false)
    );
    catprintf(task, "\n%s", "y`=...");
    sprintf(src, "y=root(n,(a*x+b)^m)*(((c*x+d)/(p*x+q))^k)");

    sprintf(answ[0], "y`=(%s)*(%s)*(%s)",
        memb(buf[0], 1,1,m,n, axpb, false),
        memb(buf[1], 1,1,k,1, chprintf(buf[2], "(%s)/(%s)", cxpd, pxpq), false),
        poly2ns(buf[3],3, m*a,n,-1,1,axpb, k*c,1,-1,1,cxpd, -k*p,1,-1,1,pxpq)
    );
    sprintf(answ[1], "y`=(%s)*(%s)+(%s)*(%s)",
        memb(buf[0], m,n,m-n,n,axpb, false),
        memb(buf[1], 1,1,k,1,chprintf(buf[2], "(%s)/(%s)", cxpd, pxpq), false),
        memb(buf[3], 1,1,m,n,axpb, false),
        memb(buf[4], k,1,k-1,1, chprintf(buf[5], "(%s)/(%s)", cxpd, pxpq), false)
    );
    sprintf(answ[2], "y`=(%s)",
        poly2ns(buf[3],3, m*a,n,-1,1,axpb, k*c,1,-1,1,cxpd, -k*p,1,-1,1,pxpq)
    );
    sprintf(answ[3], "y`=(%s)*(%s)+(%s)*(%s)*(%s)",
        memb(buf[0], m*k,n,m-1,1,axpb, false),
        memb(buf[1], 1,1,k,1,chprintf(buf[2], "(%s)/(%s)", cxpd, pxpq), false),
        memb(buf[3], 1,1,m,n,axpb, false),
        memb(buf[4], k,1,k-1,1, chprintf(buf[5], "(%s)/(%s)", cxpd, pxpq), false),
        memb(buf[6], c-d,1,2,1,pxpq, false)
    );
}

void deriv602 (const range &rr, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b,d,c,m,n,k,r;
    do{
        a=rndr(rr);
        b=rndr(rr);
        d=rndr(rr);
        c=rndr(rr);
        m=rndr(rr);
        n=rndr(rr);
        k=rndr(rr);
        r=rndr(rr);
    }while(!(a>0 && c>0 && b*d!=0 && m>0 && n>0 && k>0 && r>0));

    strcpy(task, "");
    char axpb[BUFSZ], xpd[BUFSZ], cxp3[BUFSZ];
    polynomial(axpb,2, a,"x",b,"");
    polynomial(xpd,2, 1,"x",d,"");
    polynomial(cxp3,2, c,"x",3,"");

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)*(%s)/(%s)",
        memb(buf[0], 1,1,m,n, axpb, false),
        memb(buf[1], 1,1,k,1, xpd,  false),
        memb(buf[2], 1,1,r,1, cxp3, false)
    );
    catprintf(task, "\n%s", "y`=...");
    sprintf(src, "y=((root(n,(a*x+b)^m)*(x+d)^k)/(c*x+3)^r))*(m*n*a/(a*x+b)+k/(x+d)-r*c/(c*x+3))");

    sprintf(answ[0], "y`=((%s)*(%s)/(%s))*(%s)",
        memb(buf[0], 1,1,m,n, axpb, false),
        memb(buf[1], 1,1,k,1, xpd,  false),
        memb(buf[2], 1,1,r,1, cxp3, false),
        poly2ns(buf[3],3, m*n*a,1,-1,1,axpb, k,1,-1,1,xpd, -r*c,1,-1,1,cxp3)
    );
    sprintf(answ[1], "y`=(%s)*((%s)/(%s))+(%s)*((%s)/(%s))",
        memb(buf[0], m,n,m-n,n,axpb, false),
        memb(buf[1], 1,1,k,1,xpd, false),
        memb(buf[2], 1,1,r,1,cxp3, false),
        memb(buf[3], 1,1,m,n, axpb, false),
        memb(buf[4], k,1,k-1,1,xpd, false),
        memb(buf[5], 1,1,2*r,1,cxp3, false)
    );
    sprintf(answ[2], "y`=(%s)",
        poly2ns(buf[3],3, m*n*a,1,-1,1,axpb, k,1,-1,1,xpd, -r*c,1,-1,1,cxp3)
    );
    sprintf(answ[3], "y`=((%s)*(%s))/(%s)+(%s)*(((%s)*(%s))/(%s))",
        memb(buf[0], m*k,n,m-1,1, axpb, false),
        memb(buf[1], 1,1,k,1, xpd,  false),
        memb(buf[2], 1,1,r,1, cxp3, false),
        memb(buf[3], 1,1,m,n, axpb, false),
        memb(buf[4], 1,1,k-1,1,xpd, false),
        polynomial(buf[5],2, k-r,"x",3*k-3*d,""),
        memb(buf[6], 1,1,r,1,cxp3, false)
    );
}

void deriv603 (const range &rr, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int a,b,m,q,r,p,s;
    do{
        a=rndr(rr);
        b=rndr(rr);
        m=rndr(rr);
        q=rndr(rr);
        r=rndr(rr);
        p=rndr(rr);
        s=rndr(rr);
    }while(!(a>0 && b>0 && q>0 && p>0 && m>2 && r>0 && s>0));

    strcpy(task, "");
    char asqxpb[BUFSZ], x3pq[BUFSZ], xpp[BUFSZ];
    polynomial(asqxpb,2, a,"sqrt(x)",b,"");
    polynomial(x3pq,2, 1,"x^3",q,"");
    polynomial(xpp,2, 1,"x",p,"");

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)/((%s)*(%s))",
        memb(buf[0], 1,1,m,1, asqxpb, false),
        memb(buf[1], 1,1,r,1, x3pq,  false),
        memb(buf[2], 1,1,s,1, xpp, false)
    );
    catprintf(task, "\n%s", "y`=...");
    sprintf(src, "y=(a*sqrt(x)+b)^m/(((x^3+p)^r)*((x+p)^s))");

    sprintf(answ[0], "y`=((%s)*(%s)/(%s))*(%d/(2*(a*sqrt(x)+b)*sqrt(x))-((%d*x^2)/(%s))-((%d)/(%s)))",
        memb(buf[0], 1,1,m,1, asqxpb, false),
        memb(buf[1], 1,1,r,1, x3pq,  false),
        memb(buf[2], 1,1,s,1, xpp, false),
        m*a, asqxpb,
        3*r, x3pq,
        s, xpp
    );
    sprintf(answ[1], "y`=(%s)/((%s)*(%s))-((%s)*(%d*(%s)+%d*(%s))/((%s)*(%s)))",
        memb(buf[0], m*a,1,m-1,1,asqxpb, false),
        memb(buf[1], 1,1,r,1,x3pq, false),
        memb(buf[2], 1,1,s,1,xpp, false),
        memb(buf[3], 1,1,m,1, asqxpb, false),
        r, xpp,
        p, x3pq,
        memb(buf[4], 1,1,r+1,1,x3pq, false),
        memb(buf[5], 1,1,s+1,1,xpp, false)
    );
    sprintf(answ[2], "y`=%d/(2*(a*sqrt(x)+b)*sqrt(x))-((%d*x^2)/(%s))-((%d)/(%s))",
        m*a, asqxpb,
        3*r, x3pq,
        s, xpp
    );
    sprintf(answ[0], "y`=((%s)*(%s)/(%s))*(%d/(%d*(a*sqrt(x)+b)*sqrt(x))-((%d*x^2)/(%s))+((%d)/(%s)))",
        memb(buf[0], 1,1,m,1, asqxpb, false),
        memb(buf[1], 1,1,r,1, x3pq,  false),
        memb(buf[2], 1,1,s,1, xpp, false),
        a, a, asqxpb,
        3*r, x3pq,
        s, xpp
    );
}

void deriv604 (const range &rr, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[20][BUFSZ];
    int n,a,b,c,r,p,s;
    do{
        n=rndr(rr);
        a=rndr(rr);
        b=rndr(rr);
        c=rndr(rr);
        r=rndr(rr);
        p=rndr(rr);
        s=rndr(rr);
    }while(!(n>0 && a>0 && b>0 && c>0 && r>0 && p>0 && s>0));

    strcpy(task, "");
    char axpb[BUFSZ], csq3xp2[BUFSZ], pxp1[BUFSZ];
    polynomial(axpb,2, a,"x",b,"");
    polynomial(csq3xp2,2, c,"root(3,x)",2,"");
    polynomial(pxp1,2, p,"x",1,"");

    strcpy(task, "");
    catprintf(task, "%s", "String(\"Найти производную заданной функции среди представленных ниже вариантов ответа:\")");
    catprintf(task, "\ny=(%s)/((%s)*(%s))",
        memb(buf[0], 1,1,1,n, axpb, false),
        memb(buf[1], 1,1,r,1, csq3xp2,  false),
        memb(buf[2], 1,1,s,1, pxp1, false)
    );
    catprintf(task, "\n%s", "y`=...");
    sprintf(src, "y=root(n,a*x+b)/((c*root(3,x)+2)*(p*x+1))");

    sprintf(answ[0], "y`=(%s)/((%s)*(%s))*((%s)-%d/(3*(%s)*root(3,x^2))-(%d*x)/(%s))",
        memb(buf[0], 1,1,1,n, axpb, false),
        memb(buf[1], 1,1,r,1, csq3xp2,  false),
        memb(buf[2], 1,1,s,1, pxp1, false),
        memb(buf[3], a,n,-1,1, axpb, false),
        r*c, csq3xp2,
        2*s*p, pxp1
    );
    sprintf(answ[1], "y`=%d/((%s)*(%s)*(%s))-((%s)*(%s))/((%s)*(%s)*root(3,x^2))",
        a,
        memb(buf[0], 1,1,n-1,n, axpb, false),
        memb(buf[1], 1,1,r,1, csq3xp2,  false),
        memb(buf[2], 1,1,s,1, pxp1, false),
        memb(buf[3], 1,1,n,1, axpb, false),
        polynomial(buf[4],2, c,"",2*p,"x"),
        memb(buf[5], 3,1,r+1,1,csq3xp2, false),
        memb(buf[6], 1,1,s+1,1,pxp1, false)
    );
    sprintf(answ[2], "y`=(%s)-%d/(3*(%s)*root(3,x^2))-(%d*x)/(%s)",
        memb(buf[3], a,n,-1,1, axpb, false),
        r*c, csq3xp2,
        2*s*p, pxp1
    );
    sprintf(answ[3], "y`=(%s)/((%s)*(%s))*((%s)-%d/(3*(%s)*root(3,x^2))+(%d*x)/(%s))",
        memb(buf[0], 1,1,1,n, axpb, false),
        memb(buf[1], 1,1,r+1,1, csq3xp2,  false),
        memb(buf[2], 1,1,s+1,1, pxp1, false),
        memb(buf[3], 1,n,-1,1, axpb, false),
        r*c, csq3xp2,
        2*s*p, pxp1
    );
}


void make_answers (float right, float other[])
{
    for(int i=0; i<3; ++i)
    {
        float newvalue;
        bool skip;
        do{
            newvalue = right;
            float delta = (rand()%10000-5000)/200.0;
            newvalue -= delta;
            skip=(fabs(newvalue-right)<1.0);
            for(int j=0; j<i && !skip; ++j)
                if (fabs(other[j]-newvalue)<1.0)
                    skip=true;
        }while(skip);
        other[i]=newvalue;
    }
}





void deriv71 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b,c,d,n,m,x0;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
        n=rndr(r);
        m=rndr(r);
        x0=rndr(r);
    }while(!(a!=0 && c>0 && b!=0 && d>0 && m*n!=1 && x0>0 && (m>=2 && m<=3) && (n>=2 && n<=3)));
    float result =
        pow(a*x0+b,m-1)*(a*c*(m*n-1)*x0+a*m*n*d-c*b) / (n*pow(c*x0+d,1.0/n)*(c*x0+d));
    float invalid[3];
    make_answers(result, invalid);

    char buf[20][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти значение производной в указанной точке:\")\n");
    catprintf(task,
        n==1?
            "y=(%s)/(%s)"
          : n==2?
            "y=(%s)/sqrt(%s)"
          : chprintf(buf[2],"y=(%%s)/root(%d,%%s)",n),
        polynomial(buf[0], 2, a,"x",b,""), polynomial(buf[1], 2, c,"x",d,"")
    );
    catprintf(task, ",x_0=%d", x0);
    sprintf(src, "y=(a*x+b)/root(n,c*x+d)");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2lf", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2lf", invalid[i]);

}

void deriv72 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b,c,k,x0;
    char buf[10][BUFSZ];
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        k=rndr(r);
        x0=rndr(r);
    }while(!((k!=2 && k>0) && a>0 && c>=1 && x0!=0));

    float result = tan(pi/k)*(2*a*x0*cos(a*x0*x0+b)*(pow(cos(x0),2)+c)+sin(2*x0)*sin(a*x0*x0+b))/pow((pow(cos(x0),2)+c),2);
    float answers[3];
    make_answers(result, answers);


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=(sin(%s)/(cos(x)^2+%d))*tg(%s),x_0=%d",
        polynomial(buf[0],2,a,"x^2",b,""),
        c,
        fraction(buf[2],1,1,k),
        x0
    );
    sprintf(src, "y=(sin(a*x^2+b)/(cos(x)^2+c))*tg(1/k)");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv73 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,c,x,b;
    do{
        a=rndr(r);
        c=rndr(r);
        x=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && c!=0 && -a<x && x<a && x!=0));

    float result = ((sqrt(a*a-x*x)+x*(asin((float)x/a)+c))/sqrt(pow(a*a-x*x,3)))*atan(b);
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=((%s)/sqrt(%d-x^2))*arctg(%d),x_0=%d",
        polynomial(buf[0],2, 1,chprintf(buf[1],"arcsin(%s)",divisor(buf[3],a,"x")), c,""),
        a*a,
        b,
        x
    );
    sprintf(src, "y=(arcsin(x/a)/sqrt(a^2-x^2))*arctg(b)");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv74 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,n,x;
    do{
        a=rndr(r);
        n=rndr(r);
        x=rndr(r);
    }while(!(a!=0 && x!=a && n>=1 && (-a<x && x<a) && n<=3));

    float result = pow(acos((float)x/a),n-1)*(x*acos((float)x/a)-n*sqrt(a*a-x*x))/sqrt(pow(a*a-x*x,3));
    float answers[3];
    make_answers(result, answers);


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=(%s)/sqrt(%d-x^2),x_0=%d",
        poly2ns(buf[0], 1, 1,1,n,1,chprintf(buf[1], "arccos(%s)", divisor(buf[3],a,"x"))),
        a*a,
        x
    );
    sprintf(src, "y=(arccos(x/a)^n)/sqrt(a^2-x^2)");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv75 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,c,b,x;
    do{
        a=rndr(r);
        c=rndr(r);
        b=rndr(r);
        x=rndr(r);
    }while(!(a!=0 && abs(a)!=1 && b!=0 && ((-1<=b && b<0) || (0<b && b<=1)) && x!=0));

    float result = (a-4*x*(atan((float)x/a)+c))/pow(a*a+x*x,3);
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=((%s)/((%d+x^2)^2))*arcsin(%d),x_0=%d",
        poly2ns(buf[0], 2, 1,1,1,1,chprintf(buf[1], "arctg(%s)", divisor(buf[3],a,"x")), c,1,1,1,""),
        a*a,
        b,
        x
    );
    sprintf(src, "y=(arctg(x/a)/((a^2+x^2)^2))*arcsin(b)");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv76 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,n,x;
    do{
        a=rndr(r);
        n=rndr(r);
        x=rndr(r);
    }while(!(a!=0 && abs(a)!=1 && x!=0 && (n==1 || n==2 || n==3)));

    float result = (a-2*n*x*atan((float)x/a))/pow(a*a+x*x,n+1);
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=((%s)/(%s)),x_0=%d",
        polynomial(buf[0], 1, 1,chprintf(buf[1], "arctg(%s)", divisor(buf[4], a, "x"))),
        poly2ns(buf[2], 1, 1,1,n,1,chprintf(buf[3], "%d+x^2",a*a)),
        x
    );
    sprintf(src, "y=arctg(x/a)/((a^2+x^2)^n)");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv77 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,x;
    do{
        a=rndr(r);
        c=rndr(r);
        b=rndr(r);
        x=rndr(r);
    }while(!(a!=0 && x!=0 && c!=0 && b>0));

    float result = (a-x*(atan((float)x/a)+c))/sqrt(pow(a*a+x*x,3))*log(b);
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=((%s)/sqrt(%d+x^2))*ln(%d),x_0=%d",
        polynomial(buf[0], 2,1,chprintf(buf[1], "arctg(%s)", divisor(buf[6],a,"x")), c,""),
        a*a,
        b,
        x
    );
    sprintf(src, "y=(arctg(x/a)/sqrt(a^2+x^2))*ln(b)");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv78 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,d,x;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        d=rndr(r);
        x=rndr(r);
    }while(!(a>0 && c!=0 && b>0 && x!=0));

    float result = a*x*(2-c-log(a*x*x+b))/sqrt(pow(a*x*x+b,3))*cos(d);
    float answers[3];
    make_answers(result, answers);


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=((%s)/sqrt(%s))*cos(%d),x_0=%d",
        polynomial(buf[0], 2,1,chprintf(buf[1], "ln(%s)", polynomial(buf[5],2,a,"x^2",b,"")),c,""),
        polynomial(buf[3], 2, a,"x^2",b,""),
        d,
        x
    );
    sprintf(src, "y=((ln(a*x^2+b)+c)/sqrt(a*x^2+b))*ln(d)");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv79 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,c,d,x0;
    float x;
    do{
        a=rndr(r);
        c=rndr(r);
        d=rndr(r);
        x0=rndr(range(1,3));
    }while(!(a!=0 && c>0));

    int arr[] = {6,4,3}; x0=arr[x0-1]; x=(float)a/x0;
    float result = pi*tan(d)*(log(cos(pi*x/a)) + c - pow(sin(pi*x/a),2))/(a*pow(cos(pi*x/a),2))*tan(d);
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=((%s)/ctg(%s))*tg(%d),x_0=%s",
        polynomial(buf[0], 2,1,chprintf(buf[1], "ln(cos(%s))", divisor(buf[5], a, "(pi*x)")),c,""),
        divisor(buf[6],a,"(pi*x)"),
        d,
        fraction(buf[9], a,1,x0)
    );
    sprintf(src, "y=((ln(cos((pi*x)/a))+c)/ctg((pi*x)/a))*tg(d),x0=a/x0");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv710 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,f,c,d,x0;
    float x;
    do{
        a=rndr(r);
        c=rndr(r);
        d=rndr(r);
        f=rndr(r);
        x0=rndr(range(1,3));
    }while(!(a>0 && a!=0 && c!=0 && d>0 && f>0 && f!=1));

    int arr[] = {6,4,3}; x0=arr[x0-1]; x=(float)a/x0;
    float result = pi*(pow(cos(pi*x/a),2)-log(sin(pi*x/a))+c)/(a*pow(sin(pi*x/a),2))*(log(a)/log(f));
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=((%s)/tg(%s))*log(%d,%d),x_0=%s",
        polynomial(buf[0], 2,1,chprintf(buf[1], "ln(sin(%s))", divisor(buf[4], a, "(pi*x)")),-c,""),
        divisor(buf[7],a,"(pi*x)"),
        f,
        d,
        fraction(buf[9], a,1,x0)
    );
    sprintf(src, "y=((ln(sin((pi*x)/a))-c)/tg((pi*x)/a))*log(f,d),x_0=a/x0");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv711 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,x0;
    float x;
    do{
        a=rndr(r);
        c=rndr(r);
        b=rndr(r);
        x0=rndr(range(1,3));
    }while(!(a!=0 && c!=0));

    int arr[] = {6,4,3}; x0=arr[x0-1]; x=(float)a/x0;
    float result = (pi*sin(pi*x/a)*(pow(4,cos(pi*x/a))*(1.0-cos(pi*x/a))*log(4)*log(cos(pi*x/a))+c))/(a*pow(log(cos(pi*x/a)),2))*tan(b);
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=((%s)/ln(cos(%s)))*tg(%d),x_0=%s",
        polynomial(buf[0], 2,1,chprintf(buf[1], "4^cos(%s)", divisor(buf[5],a,"(pi*x)")),c,""),
        divisor(buf[7],a,"(pi*x)"),
        b,
        fraction(buf[9], a,1,x0)
    );
    sprintf(src, "y=((4^cos((pi*x)/a)+c)/ln(cos((pi*x)/a)))*tg(b),x_0=a/x0");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv712 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,c,x0;
    float x;
    do{
        a=rndr(r);
        c=rndr(r);
        x0=rndr(range(1,3));
    }while(!(a!=0 && c!=0));

    int arr[] = {6,4,3}; x0=arr[x0-1]; x=(float)a/x0;
    float result = -pi*(pow(4,cos(pi*x/a))*(pow(sin(pi*x/a),2)*log(4)+2*cos(pi*x/a))+c*cos(pi*x/a))/(a*pow(sin(pi*x/a),3));
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=((%s)/(sin(%s)^2)),x_0=%s",
        polynomial(buf[0], 2,1,chprintf(buf[1], "4^cos(%s)", divisor(buf[6],a,"(pi*x)")),c,""),
        divisor(buf[7],a,"(pi*x)"),
        fraction(buf[9], a,1,x0)
    );
    sprintf(src, "y=((4^cos((pi*x)/a)+c)/(sin((pi*x)/a)^2)),x_0=a/x0");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv713 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,m,x0;
    float x;
    do{
        a=rndr(r);
        b=rndr(r);
        m=rndr(range(1,3));
        x0=rndr(range(1,3));
    }while(!(a>0 && b!=1 && b>0));

    int arr[] = {6,4,3}; x0=arr[x0-1]; x=(float)a/x0;
    float result = (-pi/a)*(pow(b,cos(pi*x/a))*pow(sin(pi*x/a),m-1)*(pow(sin(pi*x/a),2)*log(b)+m*cos(pi*x/a)))/(pow(sin(pi*x/a),2*m));
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=((%s)/(%s)),x_0=%s",
        polynomial(buf[0], 1,1,chprintf(buf[1], "(%d)^cos(%s)", b,divisor(buf[7],a,"(pi*x)"))),
        poly2ns(buf[2], 1, 1,1,m,1,chprintf(buf[4],"sin(%s)",divisor(buf[8],a,"(pi*x)"))),
        fraction(buf[9], a,1,x0)
    );
    sprintf(task, "y=(((b)^cos((pi*x)/a))/((sin((pi*x)/a))^m)),x_0=a/x0");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv714 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,m,x0;
    float x;
    do{
        a=rndr(r);
        b=rndr(r);
        m=rndr(range(1,3));
        x0=rndr(range(1,3));
    }while(!(a>0 && b!=1 && b>0));

    int arr[] = {6,4,3}; x0=arr[x0-1]; x=(float)a/x0;
    float result = pi*pow(b,tan(pi*x/a))*(log(b)+m/2.0*sin(2*pi*x/a))/(a*pow(cos(pi*x/a),2*m-2));
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=((%s)/(%s)),x_0=%s",
        polynomial(buf[0], 1,1,chprintf(buf[1], "(%d)^tg(%s)", b,divisor(buf[7],a,"(pi*x)"))),
        poly2ns(buf[2], 1, 1,1,m,1,chprintf(buf[4],"cos(%s)",divisor(buf[8],a,"(pi*x)"))),
        fraction(buf[9], a,1,x0)
    );
    sprintf(src, "y=(((b)^tg((pi*x)/a))/(cos((pi*x)/a)^m)),x_0=a/x0");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv715 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,n,x0;
    float x;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        n=rndr(range(2,4));
        x=rndr(r);
    }while(!(a>0 && x!=0 && c>0 && b!=1 && b>0));

    float result = (2*a*x*pow(b,a*x*x+c)*(n*(a*x*x+c)*log(b)-1))/(n*(a*x*x+c)*sqrt(a*x*x+c));
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")\n");
    catprintf(task,
        n==2?
            "y=((%d)^(%s))/sqrt(%s)"
          : "y=((%d)^(%s))/root(%s,%d)",
        b,
        polynomial(buf[0], 2, a,"x^2",c,""),
        polynomial(buf[1], 2, a,"x^2",c,""),
        n
    );
    catprintf(task, ",x_0=%d", x);
    sprintf(src, "y=(b^(a*x^2+c))/root(a*x^2+c,n)");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

void deriv716 (const range& r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    char buf[10][BUFSZ];
    int a,b,c,p,n,x;
    do{
        a=rndr(r);
        b=rndr(r);
        c=rndr(r);
        n=rndr(range(1,3));
        p=rndr(r);
        x=rndr(r);
    }while(!(p>1 && a>0 && b>0 && c>0 && x>0));

    float result = (2*a*x+b)*(1/log(p)-n*log(a*x*x+b*x+c)/log(p))/pow(a*x*x+b*x+c,n+1);
    float answers[3];
    make_answers(result, answers);

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции в заданной точке:\")");
    catprintf(task, "\ny=log(%d,%s)/(%s),x_0=%d",
        p,
        polynomial(buf[0], 3, a,"x^2",b,"x",c,""),
        poly2ns(buf[2], 1,1,1,n,1,polynomial(buf[1], 3, a,"x^2",b,"x",c,"")),
        x
    );
    sprintf(src, "y=log(p,a*x^2+b*x+c)/((a*x^2+b*x+c)^n)");

    sprintf(answ[0], "y&string(\"`\")&!(x_0)=%2.2f", result);
    for(int i=0; i<3; ++i)
        sprintf(answ[i+1], "y&string(\"`\")&!(x_0)=%2.2f", answers[i]);
}

/** ----------------------------------------------------------------------- **/

void derivb119 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(a!=0 && b!=0 && p!=0 && p>1));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=%s", poly2ns(buf[0], 1, 1,1,p,1, chprintf(buf[1], "1/(%s)", polynomial(buf[2], 2,a,"x",b,""))));
    sprintf(src, "y=(1/(a*x+b))^p");

    sprintf(answ[0], "y`=(%d)*.(%s)*.((-1)/((%s)^2))*.(%d)", p, poly2ns(buf[9], 1, 1,1,p-1,1,polynomial(buf[0],2,a,"x",b,"")), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[1], "y`=(%d)*.(%s)*.((-1)/((%s)^2))", p-1, poly2ns(buf[9], 1, 1,1,p-1,1,polynomial(buf[0],2,a,"x",b,"")), polynomial(buf[1],2,a,"x",b,""));
    sprintf(answ[2], "y`=(%d)*.(%s)*.(1/((%s)^2))", p+1, poly2ns(buf[9], 1, 1,1,p-1,1,polynomial(buf[0],2,a,"x",b,"")), polynomial(buf[1],2,a,"x",b,""));
    sprintf(answ[3], "y`=(%d)*.(%s)*.(%d)", p-1, poly2ns(buf[9], 1, 1,1,p+1,1,polynomial(buf[0],2,a,"x",b,"")), a);
}

void derivb120 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(a!=0 && b!=0 && p>1));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=(%d)^(1/(%s))", p, polynomial(buf[2], 2,a,"x",b,""));
    sprintf(src, "y=p^(1/(a*x+b))");

    sprintf(answ[0], "y`=(%d)^(1/(%s))*.ln(%d)*.((-1)/((%s)^2))*.(%d)", p, polynomial(buf[0],2,a,"x",b,""), p, polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[1], "y`=(%d)^(1/(%s))*.((-1)/((%s)^2))*.(%d)", p, polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[2], "y`=(%d)^(1/(%s))*.ln(%d)*.(%d)", p, polynomial(buf[0],2,a,"x",b,""), p, a);
    sprintf(answ[3], "y`=(%d)^(1/(%s))*.ln(%d)", p, polynomial(buf[0],2,a,"x",b,""), p);
}

void derivb121 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(a!=0 && b!=0 && p>1));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=log(%d,1/(%s))", p, polynomial(buf[2], 2,a,"x",b,""));
    sprintf(src, "y=log(p,1/(a*x+b))");

    sprintf(answ[0], "y`=-(%s)*.(%d)", polynomial(buf[0],2,a,"x",b,""), a);
    sprintf(answ[1], "y`=(%s)*.(%d)", polynomial(buf[0],2,a,"x",b,""), b);
    sprintf(answ[2], "y`=(%s)/(%d)", polynomial(buf[0],2,a,"x",b,""), a);
    sprintf(answ[3], "y`=(%s)/(%d)", polynomial(buf[0],2,a,"x",b,""), b);
}

void derivb122 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=sin(1/(%s))", polynomial(buf[2], 2,a,"x",b,""));
    sprintf(src, "y=sin(1/(a*x+b))");

    sprintf(answ[0], "y`=cos(1/(%s))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[1], "y`=-cos(1/(%s))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[2], "y`=-sin(1/(%s))*.(1/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[3], "y`=(1/cos(1/(%s))^2)*.(1/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
}

void derivb123 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=cos(1/(%s))", polynomial(buf[2], 2,a,"x",b,""));
    sprintf(src, "y=cos(1/(a*x+b))");

    sprintf(answ[0], "y`=-sin(1/(%s))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[1], "y`=sin(1/(%s))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[2], "y`=-cos(1/(%s))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[3], "y`=(1/sin(1/(%s))^2)*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
}

void derivb124 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=tg(1/(%s))", polynomial(buf[2], 2,a,"x",b,""));
    sprintf(src, "y=tg(1/(a*x+b))");

    sprintf(answ[0], "y`=(1/(cos(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[1], "y`=(1/(sin(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[2], "y`=(-1/(cos(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[3], "y`=(-1/(sin(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
}

void derivb125 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=ctg(1/(%s))", polynomial(buf[2], 2,a,"x",b,""));
    sprintf(src, "y=ctg(1/(a*x+b))");

    sprintf(answ[0], "y`=(-1/(sin(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[1], "y`=(1/(sin(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[2], "y`=(1/(cos(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[3], "y`=(-1/(cos(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
}

void derivb126 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=arcsin(1/(%s))", polynomial(buf[2], 2,a,"x",b,""));
    sprintf(src, "y=arcsin(1/(a*x+b))");

    sprintf(answ[0], "y`=(1/sqrt(1-(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[1], "y`=(-1/sqrt(1-(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[2], "y`=(1/sqrt(1-(1/(%s))^2))*.(1/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[3], "y`=(1/sqrt(1+(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
}

void derivb127 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=arccos(1/(%s))", polynomial(buf[2], 2,a,"x",b,""));
    sprintf(src, "y=arccos(1/(a*x+b))");

    sprintf(answ[0], "y`=(-1/sqrt(1-(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[1], "y`=(1/sqrt(1-(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[2], "y`=(1/sqrt(1-(1/(%s))^2))*.(1/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[3], "y`=(-1/sqrt(1+(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
}

void derivb128 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=arctg(1/(%s))", polynomial(buf[2], 2,a,"x",b,""));
    sprintf(src, "y=arctg(1/(a*x+b))");

    sprintf(answ[0], "y`=(1/(1+(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[1], "y`=(1/(1+(1/(%s))^2))*.(1/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[2], "y`=(1/(1-(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[3], "y`=(-1/(1+(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
}

void derivb129 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=arcctg(1/(%s))", polynomial(buf[2], 2,a,"x",b,""));
    sprintf(src, "y=arcctg(1/(a*x+b))");

    sprintf(answ[0], "y`=(-1/(1+!(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[1], "y`=(1/(1+!(1/(%s))^2))*.((-1)/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[2], "y`=(-1/(1+!(1/(%s))^2))*.(1/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
    sprintf(answ[3], "y`=(1/(1+!(1/(%s))^2))*.(1/((%s)^2))*.(%d)", polynomial(buf[0],2,a,"x",b,""), polynomial(buf[1],2,a,"x",b,""), a);
}





void derivb219 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(a!=0 && b!=0 && p!=0 && p>1));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=%s", poly2ns(buf[0], 1, 1,1,p,1, chprintf(buf[1], "1/(%s)", polynomial(buf[2], 2,a,"x^2",b,""))));
    sprintf(src, "y=(1/(a*x^2+b))^p");

    sprintf(answ[0], "y`=(%d)*.(%s)*.((-1)/((%s)^2))*.(%s)", p, poly2ns(buf[9], 1, 1,1,p-1,1,polynomial(buf[0],2,a,"x^2",b,"")), polynomial(buf[1],2,a,"x^2",b,""), polynomial(buf[3],1, 2*a,"x"));
    sprintf(answ[1], "under_construction");
    sprintf(answ[2], "under_construction");
    sprintf(answ[3], "under_construction");
}

void derivb220 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(a!=0 && b!=0 && p>1));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=(%d)^(1/(%s))", p, polynomial(buf[2], 2,a,"x^2",b,""));
    sprintf(src, "y=p^(1/(a*x^2+b))");

    sprintf(answ[0], "y`=(%d)^(1/(%s))*.ln(%d)*.((-1)/((%s)^2))*.(%s)", p, polynomial(buf[0],2,a,"x^2",b,""), p, polynomial(buf[1],2,a,"x^2",b,""), polynomial(buf[3],1, 2*a,"x"));
    sprintf(answ[1], "under_construction");
    sprintf(answ[2], "under_construction");
    sprintf(answ[3], "under_construction");
}

void derivb221 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(a!=0 && b!=0 && p>1));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=log(%d,1/(%s))", p, polynomial(buf[2], 2,a,"x^2",b,""));
    sprintf(src, "y=log(p,1/(a*x^2+b))");

    sprintf(answ[0], "y`=-(1/(%s))*.ln(%d)*.(%s)", polynomial(buf[0],2,a,"x^2",b,""), p, polynomial(buf[3],1, 2*a,"x"));
    sprintf(answ[1], "under_construction");
    sprintf(answ[2], "under_construction");
    sprintf(answ[3], "under_construction");
}

void derivb222 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=sin(1/(%s))", polynomial(buf[2], 2,a,"x^2",b,""));
    sprintf(src, "y=sin(1/(a*x^2+b))");

    sprintf(answ[0], "y`=cos(1/(%s))*.((-1)/(!(%s)^2))*.(%s)", polynomial(buf[0],2,a,"x^2",b,""), polynomial(buf[1],2,a,"x^2",b,""), polynomial(buf[3],1, 2*a,"x"));
    sprintf(answ[1], "under_construction");
    sprintf(answ[2], "under_construction");
    sprintf(answ[3], "under_construction");
}

void derivb223 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=cos(1/(%s))", polynomial(buf[2], 2,a,"x^2",b,""));
    sprintf(src, "y=cos(1/(a*x^2+b))");

    sprintf(answ[0], "y`=-sin(1/(%s))*.((-1)/(!(%s)^2))*.(%s)", polynomial(buf[0],2,a,"x^2",b,""), polynomial(buf[1],2,a,"x^2",b,""), polynomial(buf[3],1, 2*a,"x"));
    sprintf(answ[1], "under_construction");
    sprintf(answ[2], "under_construction");
    sprintf(answ[3], "under_construction");
}

void derivb224 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=tg(1/(%s))", polynomial(buf[2], 2,a,"x^2",b,""));
    sprintf(src, "y=tg(1/(a*x^2+b))");

    sprintf(answ[0], "y`=(1/(cos(1/(%s))^2))*.((-1)/(!(%s)^2))*.(%s)", polynomial(buf[0],2,a,"x^2",b,""), polynomial(buf[1],2,a,"x^2",b,""), polynomial(buf[3],1, 2*a,"x"));
    sprintf(answ[1], "under_construction");
    sprintf(answ[2], "under_construction");
    sprintf(answ[3], "under_construction");
}

void derivb225 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=ctg(1/(%s))", polynomial(buf[2], 2,a,"x^2",b,""));
    sprintf(src, "y=ctg(1/(a*x^2+b))");

    sprintf(answ[0], "y`=(-1/(sin(1/(%s))^2))*.((-1)/(!(%s)^2))*.(%s)", polynomial(buf[0],2,a,"x^2",b,""), polynomial(buf[1],2,a,"x^2",b,""), polynomial(buf[3],1, 2*a,"x"));
    sprintf(answ[1], "under_construction");
    sprintf(answ[2], "under_construction");
    sprintf(answ[3], "under_construction");
}

void derivb226 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=arcsin(1/(%s))", polynomial(buf[2], 2,a,"x^2",b,""));
    sprintf(src, "y=arcsin(1/(a*x^2+b))");

    sprintf(answ[0], "y`=(1/sqrt(1-!(1/(%s))^2))*.((-1)/(!(%s)^2))*.(%s)", polynomial(buf[0],2,a,"x^2",b,""), polynomial(buf[1],2,a,"x^2",b,""), polynomial(buf[3],1, 2*a,"x"));
    sprintf(answ[1], "under_construction");
    sprintf(answ[2], "under_construction");
    sprintf(answ[3], "under_construction");
}

void derivb227 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=arccos(1/(%s))", polynomial(buf[2], 2,a,"x^2",b,""));
    sprintf(src, "y=arccos(1/(a*x^2+b))");

    sprintf(answ[0], "y`=(-1/sqrt(1-!(1/(%s))^2))*.((-1)/(!(%s)^2))*.(%s)", polynomial(buf[0],2,a,"x^2",b,""), polynomial(buf[1],2,a,"x^2",b,""), polynomial(buf[3],1, 2*a,"x"));
    sprintf(answ[1], "under_construction");
    sprintf(answ[2], "under_construction");
    sprintf(answ[3], "under_construction");
}

void derivb228 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=arctg(1/(%s))", polynomial(buf[2], 2,a,"x^2",b,""));
    sprintf(src, "y=arctg(1/(a*x^2+b))");

    sprintf(answ[0], "y`=(1/(1+!(1/(%s))^2))*.((-1)/(!(%s)^2))*.(%s)", polynomial(buf[0],2,a,"x^2",b,""), polynomial(buf[1],2,a,"x^2",b,""), polynomial(buf[3],1, 2*a,"x"));
    sprintf(answ[1], "under_construction");
    sprintf(answ[2], "under_construction");
    sprintf(answ[3], "under_construction");
}

void derivb229 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(a!=0 && b!=0));
    char buf[10][BUFSZ];

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную функции:\")");
    catprintf(task, "\ny=arcctg(1/(%s))", polynomial(buf[2], 2,a,"x^2",b,""));
    sprintf(src, "y=arcctg(1/(a*x^2+b))");

    sprintf(answ[0], "y`=(-1/(1+!(1/(%s))^2))*.((-1)/(!(%s)^2))*.(%s)", polynomial(buf[0],2,a,"x^2",b,""), polynomial(buf[1],2,a,"x^2",b,""), polynomial(buf[3],1, 2*a,"x"));
    sprintf(answ[1], "under_construction");
    sprintf(answ[2], "under_construction");
    sprintf(answ[3], "under_construction");
}

/** ------------------------------------------------------------------------- */



void derivb301 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
   
    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(p>1 && abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "sqrt(%s)", polynomial(buf[0], 2, a,"x",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=(%s)^(%d)", poly, p);
    sprintf(src, "y=(sqrt(a*x+b))^p");

    sprintf(answ[0], "y`=%s*.(1/(2*%s))*.(%d)", poly2ns(buf[1], 1, p,1,p-1,1,poly), poly, a);
    sprintf(answ[1], "y`=%s*.(1/(%s))*.(%d)", poly2ns(buf[1], 1, p,1,p-1,1,poly), poly, a);
    sprintf(answ[2], "y`=%s*.(1/(2*%s))", poly2ns(buf[1], 1, p,1,p-1,1,poly), poly);
    sprintf(answ[3], "y`=%s*.(1/(%s))", poly2ns(buf[1], 1, p,1,-(p-1),1,poly), poly);
}



void derivb302 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
   
    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(p>1 && abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "sqrt(%s)", polynomial(buf[0], 2, a,"x",b,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=(%d)^(%s)", p, poly);
    sprintf(src, "y=p^(sqrt(a*x+b))");

    sprintf(answ[0], "y`=(%d)^(%s)*.ln(%d)*.(1/(2*(%s)))*.(%d)", p, poly, p, poly, a);
    sprintf(answ[1], "y`=(%s)*.(%d)^(%s-1)*.ln(%d)*.(%d)", poly, p, poly, p, a);
    sprintf(answ[2], "y`=(%d)^(%s)*.(1/ln(%d))*.(1/(2*(%s)))*.(%d)", p, poly, p, poly, a);
    sprintf(answ[3], "y`=(%s)*.(%d)^(%s-1)*.(1/ln(%d))*.(%d)", poly, p, poly, p, a);
}




void derivb303 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(p>1 && abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "sqrt(%s)", polynomial(buf[0], 2, a,"x",b,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=log(%d,%s)", p, poly);
    sprintf(src, "y=log(p,sqrt(a*x+b))");

    sprintf(answ[0], "y`=(1/(%s))*.(1/ln(%d))*.(1/(2*%s))*.(%d)", poly, p, poly, a);
    sprintf(answ[1], "y`=(1/(%s))*.(ln(%d))*.(1/(2*%s))*.(%d)", poly, p, poly, a);
    sprintf(answ[2], "y`=(1/(%s))*.(ln(%d))*.(1/(%s))*.(%d)", poly, p, poly, a);
    sprintf(answ[3], "y`=(1/(%s))*.(1/ln(%d))*.(1/(%s))*.(%d)", poly, p, poly, a);
}




void derivb304 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "sqrt(%s)", polynomial(buf[0], 2, a,"x",b,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=sin(%s)", poly);
    sprintf(src, "y=sin(sqrt(a*x+b))");

    sprintf(answ[0], "y`=cos(%s)*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=-cos(%s)*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=-cos(%s)*.(1/(%s))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=cos(%s)*.(1/(%s))*.(%d)", poly, poly, a);
}




void derivb305 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "sqrt(%s)", polynomial(buf[0], 2, a,"x",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=cos(%s)", poly);
    sprintf(src, "y=cos(sqrt(a*x+b))");

    sprintf(answ[0], "y`=-sin(%s)*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=sin(%s)*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=sin(%s)*.(1/(%s))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=-sin(%s)*.(1/(%s))*.(%d)", poly, poly, a);
}



void derivb306 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "sqrt(%s)", polynomial(buf[0], 2, a,"x",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=tg(%s)", poly);
    sprintf(src, "y=tg(sqrt(a*x+b))");

    sprintf(answ[0], "y`=(1/(cos(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=(-1/(cos(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=(-1/(cos(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=(1/(cos(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
}




void derivb307 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "sqrt(%s)", polynomial(buf[0], 2, a,"x",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=ctg(%s)", poly);
    sprintf(src, "y=ctg(sqrt(a*x+b))");

    sprintf(answ[0], "y`=(-1/(sin(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=(1/(sin(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=(1/(sin(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=(-1/(sin(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
}



void derivb308 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "sqrt(%s)", polynomial(buf[0], 2, a,"x",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arcsin(%s)", poly);
    sprintf(src, "y=arcsin(sqrt(a*x+b))");

    sprintf(answ[0], "y`=(1/sqrt(1-(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=(-1/sqrt(1-(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=(-1/sqrt(1-(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=(1/sqrt(1-(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
}




void derivb309 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "sqrt(%s)", polynomial(buf[0], 2, a,"x",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arccos(%s)", poly);
    sprintf(src, "y=arccos(sqrt(a*x+b))");

    sprintf(answ[0], "y`=(-1/sqrt(1-(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=(1/sqrt(1-(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=(1/sqrt(1-(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=(-1/sqrt(1-(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
}




void derivb310 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "sqrt(%s)", polynomial(buf[0], 2, a,"x",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arctg(%s)", poly);
    sprintf(src, "y=arctg(sqrt(a*x+b))");

    sprintf(answ[0], "y`=(1/(1+(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=(-1/(1+(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=(-1/(1+(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=(1/(1+(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
}




void derivb311 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "sqrt(%s)", polynomial(buf[0], 2, a,"x",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arcctg(%s)", poly);
    sprintf(src, "y=arcctg(sqrt(a*x+b))");

    sprintf(answ[0], "y`=(-1/(1+(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=(1/(1+(%s)^2))*.(1/(2*%s))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=(1/(1+(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=(-1/(1+(%s)^2))*.(1/(%s))*.(%d)", poly, poly, a);
}



void derivb401 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
   
    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x^2",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=(%s)^(%d)", poly, p);
    sprintf(src, "y=(a*x^2+b)^p");

    sprintf(answ[0], "y`=%d*.(%s)*.(%d)*x", p, poly2ns(buf[1], 1, 1,1,p-1,1,poly), 2*a);
    sprintf(answ[1], "y`=%d*.(%s)*.(%d)*x", p, poly2ns(buf[1], 1, 1,1,p-1,1,poly), a);
    sprintf(answ[2], "y`=%d*.(%s)*.(%d)*x", p, poly2ns(buf[1], 1, 1,1,1-p,1,poly), a);
    sprintf(answ[3], "y`=%d*.(%s)*.(%d)*x", p, poly2ns(buf[1], 1, 1,1,1-p,1,poly), 2*a);
}




void derivb402 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x^2",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=(%d)^(%s)", p, poly);
    sprintf(src, "y=p^(a*x^2+b)");

    sprintf(answ[0], "y`=%d^(%s)*.ln(%d)*.(%d)*x", p, poly, p, 2*a);
    sprintf(answ[1], "y`=%d^(%s)*.(1/ln(%d))*.(%d)*x", p, poly, p, 2*a);
    sprintf(answ[2], "y`=%d^(%s)*.(1/ln(%d))*.(%d)*x", p, poly, p, a);
    sprintf(answ[3], "y`=%d^(%s)*.ln(%d)*.(%d)*x", p, poly, p, 2);
}




void derivb403 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x^2",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=log(%d,%s)", p, poly);
    sprintf(src, "y=log(p,a*x^2+b)");

    sprintf(answ[0], "y`=(1/(%s))*.(1/ln(%d))*.(%d)*x", poly, p, 2*a);
    sprintf(answ[1], "y`=(1/(%s))*.(ln(%d))*.(%d)*x", poly, p, 2*a);
    sprintf(answ[2], "y`=(1/(%s))*.(ln(%d))*.(%d)*x", poly, p, a);
    sprintf(answ[3], "y`=(1/(%s))*.(1/ln(%d))*.(%d)*x", poly, p, a);
}




void derivb404 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x^2",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=sin(%s)", poly);
    sprintf(src, "y=sin(a*x^2+b)");

    sprintf(answ[0], "y`=cos(%s)*.(%d)*x", poly, 2*a);
    sprintf(answ[1], "y`=-cos(%s)*.(%d)*x", poly, 2*a);
    sprintf(answ[2], "y`=-cos(%s)*.(%d)*x", poly, a);
    sprintf(answ[3], "y`=cos(%s)*.(%d)*x", poly, a);
}




void derivb405 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x^2",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=cos(%s)", poly);
    sprintf(src, "y=cos(a*x^2+b)");

    sprintf(answ[0], "y`=-sin(%s)*.(%d)*x", poly, 2*a);
    sprintf(answ[1], "y`=sin(%s)*.(%d)*x", poly, 2*a);
    sprintf(answ[2], "y`=sin(%s)*.(%d)*x", poly, a);
    sprintf(answ[3], "y`=-sin(%s)*.(%d)*x", poly, a);
}



void derivb406 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x^2",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=tg(%s)", poly);
    sprintf(src, "y=tg(a*x^2+b)");

    sprintf(answ[0], "y`=(1/(cos(%s)^2))*.(%d)*x", poly, 2*a);
    sprintf(answ[1], "y`=-(1/(cos(%s)^2))*.(%d)*x", poly, 2*a);
    sprintf(answ[2], "y`=-(1/(cos(%s)^2))*.(%d)*x", poly, a);
    sprintf(answ[3], "y`=(1/(cos(%s)^2))*.(%d)*x", poly, a);
}




void derivb407 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x^2",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=ctg(%s)", poly);
    sprintf(src, "y=ctg(a*x^2+b)");

    sprintf(answ[0], "y`=-(1/(sin(%s)^2))*.(%d)*x", poly, 2*a);
    sprintf(answ[1], "y`=(1/(sin(%s)^2))*.(%d)*x", poly, 2*a);
    sprintf(answ[2], "y`=(1/(sin(%s)^2))*.(%d)*x", poly, a);
    sprintf(answ[3], "y`=-(1/(sin(%s)^2))*.(%d)*x", poly, a);
}




void derivb408 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x^2",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arcsin(%s)", poly);
    sprintf(src, "y=arcsin(a*x^2+b)");

    sprintf(answ[0], "y`=(1/(sqrt(1-(%s)^2)))*.(%d)*x", poly, 2*a);
    sprintf(answ[1], "y`=-(1/(sqrt(1-(%s)^2)))*.(%d)*x", poly, 2*a);
    sprintf(answ[2], "y`=-(1/(sqrt(1-(%s)^2)))*.(%d)*x", poly, a);
    sprintf(answ[3], "y`=(1/(sqrt(1-(%s)^2)))*.(%d)*x", poly, a);
}




void derivb409 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x^2",b,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arccos(%s)", poly);
    sprintf(src, "y=arccos(a*x^2+b)");

    sprintf(answ[0], "y`=-(1/(sqrt(1-(%s)^2)))*.(%d)*x", poly, 2*a);
    sprintf(answ[1], "y`=(1/(sqrt(1-(%s)^2)))*.(%d)*x", poly, 2*a);
    sprintf(answ[2], "y`=-(1/(sqrt(1-(%s)^2)))*.(%d)*x", poly, a);
    sprintf(answ[3], "y`=(1/(sqrt(1-(%s)^2)))*.(%d)*x", poly, a);
}




void derivb410 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x^2",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arctg(%s)", poly);
    sprintf(src, "y=arctg(a*x^2+b)");

    sprintf(answ[0], "y`=(1/(1+(%s)^2))*.(%d)*x", poly, 2*a);
    sprintf(answ[1], "y`=-(1/(1+(%s)^2))*.(%d)*x", poly, 2*a);
    sprintf(answ[2], "y`=-(1/(1+(%s)^2))*.(%d)*x", poly, a);
    sprintf(answ[3], "y`=(1/(1+(%s)^2))*.(%d)*x", poly, a);
}




void derivb411 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
   
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x^2",b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arcctg(%s)", poly);
    sprintf(src, "y=arcctg(a*x^2+b)");

    sprintf(answ[0], "y`=-(1/(1+(%s)^2))*.(%d)*x", poly, 2*a);
    sprintf(answ[1], "y`=(1/(1+(%s)^2))*.(%d)*x", poly, 2*a);
    sprintf(answ[2], "y`=(1/(1+(%s)^2))*.(%d)*x", poly, a);
    sprintf(answ[3], "y`=-(1/(1+(%s)^2))*.(%d)*x", poly, a);
}



/////////////////////////////////////////////////////
/* * * * * * * * * * * * * * * * * * * * * * * * * *
 * - - - - - - - - - - - - - - - - - - - - - - - - *
 * -                                             - *
 *                y=f^2(z=ax+b)                    *
 * -                                             - *
 * - - - - - - - - - - - - - - - - - - - - - - - - *
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/////////////////////////////////////////////////////

/** y=log^2(p,z) */
void derivb501 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=log(%d,%s)^2", p, poly);
    sprintf(src, "y=log(p,a*x+b)^2");

    sprintf(answ[0], "y`=2*log(%d,%s)*.1/((%s)*ln(%d))*.(%d)", p, poly, poly, p, a);
    sprintf(answ[1], "y`=2*log(%d,%s)*.(ln(%d)/(%s))*.(%d)", p, poly, p, poly, a);
    sprintf(answ[2], "y`=2*log(%d,%s)*.(ln(%d)/(%s))*.1/(%d)", p, poly, p, poly, a);
    sprintf(answ[3], "y`=2*log(%d,%s)*.1/((%s)*ln(%d))*.1/(%d)", p, poly, poly, p, a);
}

/** y=sin^2(z) */
void derivb502 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=sin(%s)^2", poly);
    sprintf(src, "y=sin(a*x+b)^2");

    sprintf(answ[0], "y`=2*sin(%s)*.cos(%s)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=2*sin(%s)*.(-cos(%s))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=2*sin(%s)*.(-cos(%s))*.(%d)", poly, poly, b);
    sprintf(answ[3], "y`=2*sin(%s)*.cos(%s)*.(%d)", poly, poly, b);
}

/** y=cos^2(z) */
void derivb503 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=cos(%s)^2", poly);
    sprintf(src, "y=cos(a*x+b)^2");

    sprintf(answ[0], "y`=2*cos(%s)*.(-sin(%s))*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=2*cos(%s)*.sin(%s)*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=2*cos(%s)*.sin(%s)*.(%d)", poly, poly, b);
    sprintf(answ[3], "y`=2*cos(%s)*.(-sin(%s))*.(%d)", poly, poly, b);
}

/** y=tg^2(z) */
void derivb504 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=tg(%s)^2", poly);
    sprintf(src, "y=tg(a*x+b)^2");

    sprintf(answ[0], "y`=(1/(cos(%s)^2))*.2*tg(%s)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=(2*tg(%s))*.(-1/(cos(%s)^2))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=(2*tg(%s))*.(-1/(cos(%s)^2))*.(%d)", poly, poly, b);
    sprintf(answ[3], "y`=(2*tg(%s))*.(1/(cos(%s)^2))*.(%d)", poly, poly, b);
}

/** y=ctg^2(z) */
void derivb505 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=ctg(%s)^2", poly);
    sprintf(src, "y=ctg(a*x+b)^2");

    sprintf(answ[0], "y`=2*ctg(%s)*.(-1/(sin(%s)^2))*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=2*ctg(%s)*.(1/(sin(%s)^2))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=2*ctg(%s)*.(1/(sin(%s)^2))*.(%d)", poly, poly, b);
    sprintf(answ[3], "y`=2*ctg(%s)*.(-1/(sin(%s)^2))*.(%d)", poly, poly, b);
}

/** y=arcsin^2(z) */
void derivb506 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arcsin(%s)^2", poly);
    sprintf(src, "y=arcsin(a*x+b)^2");

    sprintf(answ[0], "y`=2*arcsin(%s)*.1/sqrt(1-(%s)^2)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=2*arcsin(%s)*.(-1/sqrt(1-(%s)^2))*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=2*arcsin(%s)*.(-1/sqrt(1-(%s)^2))*.(%d)", poly, poly, b);
    sprintf(answ[3], "y`=2*arcsin(%s)*.(1/sqrt(1-(%s)^2))*.(%d)", poly, poly, b);
}

/** y=arccos^2(z) */
void derivb507 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arccos(%s)^2", poly);
    sprintf(src, "y=arccos(a*x+b)^2");

    sprintf(answ[0], "y`=2*arccos(%s)*.(-1)/sqrt(1-(%s)^2)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=2*arccos(%s)*.1/sqrt(1-(%s)^2)*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=2*arccos(%s)*.1/sqrt(1-(%s)^2)*.(%d)", poly, poly, b);
    sprintf(answ[3], "y`=2*arccos(%s)*.(-1)/sqrt(1-(%s)^2)*.(%d)", poly, poly, b);
}

/** y=arctg^2(z) */
void derivb508 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arctg(%s)^2", poly);
    sprintf(src, "y=arctg(a*x+b)^2");

    sprintf(answ[0], "y`=2*arctg(%s)*.1/(1+(%s)^2)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=2*arctg(%s)*.(-1)/(1+(%s)^2)*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=2*arctg(%s)*.(-1)/(1+(%s)^2)*.(%d)", poly, poly, b);
    sprintf(answ[3], "y`=2*arctg(%s)*.1/(1+(%s)^2)*.(%d)", poly, poly, b);
}

/** y=arcctg^2(z) */
void derivb509 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arcctg(%s)^2", poly);
    sprintf(src, "y=arcctg(a*x+b)^2");

    sprintf(answ[0], "y`=2*arcctg(%s)*.(-1)/(1+(%s)^2)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=2*arcctg(%s)*.1/(1+(%s)^2)*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=2*arcctg(%s)*.1/(1+(%s)^2)*.(%d)", poly, poly, b);
    sprintf(answ[3], "y`=2*arcctg(%s)*.(-1)/(1+(%s)^2)*.(%d)", poly, poly, b);
}




/////////////////////////////////////////////////////
/* * * * * * * * * * * * * * * * * * * * * * * * * *
 * - - - - - - - - - - - - - - - - - - - - - - - - *
 * -                                             - *
 *                   z=a/x+b                       *
 * -                                             - *
 * - - - - - - - - - - - - - - - - - - - - - - - - *
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/////////////////////////////////////////////////////

void derivb601 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=(%s)^%d", poly, p);
    sprintf(src, "y=(a/x+b)^p");

    sprintf(answ[0], "y`=-(%s)*.(%d)*(%s)^(%d)", poly2ns(buf[1], 1, a,1,-2,1,"x"), p, poly, p-1);
    sprintf(answ[1], "y`=(%d)*(%s)^(%d)*.(%s)", p, poly, p-1, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[2], "y`=(%d)*(%s)^(%d)*.(%s)", p, poly, p-1, poly2ns(buf[1], 1, a,1,2,1,"x"));
    sprintf(answ[3], "y`=(%d)*(%s)^(%d)*.(-(%s))", p, poly, p-1, poly2ns(buf[1], 1, a,1,2,1,"x"));
}

void derivb602 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=(%d)^(%s)", p, poly);
    sprintf(src, "y=p^(a/x+b)");

    sprintf(answ[0], "y`=(%d)^(%s)*.ln(%d)*.(-(%s))", p, poly, p, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[1], "y`=(%d)^(%s)*.ln(%d)*.(%s)", p, poly, p, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[2], "y`=(%d)^(%s)*.(1/ln(%d))*.(%s)", p, poly, p, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[3], "y`=(%d)^(%s)*.(1/ln(%d))*(-(%s))", p, poly, p, poly2ns(buf[1], 1, a,1,-2,1,"x"));
}

void derivb603 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=log(%d,%s)", p, poly);
    sprintf(src, "y=log(p,a/x+b)");

    sprintf(answ[0], "y`=(1/(%s))*.(1/ln(%d))*.(-(%s))", poly, p, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[1], "y`=(1/(%s))*.(1/ln(%d))*.(%s)", poly, p, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[2], "y`=(1/(%s))*.(ln(%d))*.(-(%s))", poly, p, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[3], "y`=(1/(%s))*.(ln(%d))*.(%s)", poly, p, poly2ns(buf[1], 1, a,1,-2,1,"x"));
}

void derivb604 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=root(%d,%s)", p, poly);
    sprintf(src, "y=root(p,a/x+b)");

    sprintf(answ[0], "y`=(1/((%d)*.root(%d,(%s)^(%d))))*.(-(%s))", p,p,poly,p-1, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[1], "y`=(1/((%d)*.root(%d,(%s)^(%d))))*.(%s)", p,p,poly,p-1, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[2], "y`=(%d)/(root(%d,(%s)^(%d)))*.(-(%s))", p,p,poly,p-1, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[3], "y`=(%d)/(root(%d,(%s)^(%d)))*.(%s)", p,p,poly,p-1, poly2ns(buf[1], 1, a,1,-2,1,"x"));
}

void derivb605 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=sin(%s)", poly);
    sprintf(src, "y=sin(a/x+b)");

    sprintf(answ[0], "y`=cos(%s)*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[1], "y`=cos(%s)*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[2], "y`=-cos(%s)*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[3], "y`=-cos(%s)*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
}

void derivb606 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=cos(%s)", poly);
    sprintf(src, "y=cos(a/x+b)");

    sprintf(answ[0], "y`=-sin(%s)*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[1], "y`=-sin(%s)*.(%s)", poly, poly2ns(buf[1], 1, a*a,1,-2,1,"x"));
    sprintf(answ[2], "y`=sin(%s)*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[3], "y`=sin(%s)*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
}

void derivb607 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
   
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=tg(%s)", poly);
    sprintf(src, "y=tg(a/x+b)");

    sprintf(answ[0], "y`=(1/(cos(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[1], "y`=(1/(cos(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[2], "y`=((-1)/(cos(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[3], "y`=((-1)/(cos(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
}

void derivb608 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=ctg(%s)", poly);
    sprintf(src, "y=ctg(a/x+b)");

    sprintf(answ[0], "y`=((-1)/(sin(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[1], "y`=((-1)/(sin(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[2], "y`=(1/(sin(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[3], "y`=(1/(sin(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
}

void derivb609 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
   
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arcsin(%s)", poly);
    sprintf(src, "y=arcsin(a/x+b)");

    sprintf(answ[0], "y`=(1/sqrt(1-(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[1], "y`=(1/sqrt(1-(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[2], "y`=((-1)/sqrt(1-(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[3], "y`=((-1)/sqrt(1-(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
}

void derivb610 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arccos(%s)", poly);
    sprintf(src, "y=arccos(a/x+b)");

    sprintf(answ[0], "y`=((-1)/sqrt(1-(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[1], "y`=((-1)/sqrt(1-(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[2], "y`=(1/sqrt(1-(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[3], "y`=(1/sqrt(1-(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
}

void derivb611 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arctg(%s)", poly);
    sprintf(src, "y=arctg(a/x+b)");

    sprintf(answ[0], "y`=(1/(1+(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[1], "y`=(1/(1+(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[2], "y`=((-1)/(1+(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[3], "y`=((-1)/(1+(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
}

void derivb612 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", poly2ns(buf[0], 2, a,1,-1,1,"x", b,1,1,1,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arcctg(%s)", poly);
    sprintf(src, "y=arcctg(a/x+b)");

    sprintf(answ[0], "y`=((-1)/(1+(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[1], "y`=((-1)/(1+(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[2], "y`=(1/(1+(%s)^2))*.(-(%s))", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
    sprintf(answ[3], "y`=(1/(1+(%s)^2))*.(%s)", poly, poly2ns(buf[1], 1, a,1,-2,1,"x"));
}



/////////////////////////////////////////////////////
/* * * * * * * * * * * * * * * * * * * * * * * * * *
 * - - - - - - - - - - - - - - - - - - - - - - - - *
 * -                                             - *
 *                  (ax+b)^2                       *
 * -                                             - *
 * - - - - - - - - - - - - - - - - - - - - - - - - *
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/////////////////////////////////////////////////////

/** z^p */
void derivb701 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    //chprintf(poly, "(%s)^2", polynomial(buf[0], 2, a,"x", b,""));
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=(%s)^(%d)", poly, 2*p);
    sprintf(src, "y=((a*x+b)^2)^p");

    sprintf(answ[0], "y`=%d*(%s)^(%d)*.(%d)", 2*p, poly, 2*p-1, a);
    sprintf(answ[1], "y`=%d*(%s)^(%d)*.(%d)", 2*p, poly, p-1, a);
    sprintf(answ[2], "y`=%d*(%s)^(%d)*.(%d)", 2*p, poly, 2*p-2, a);
    sprintf(answ[3], "y`=%d*(%s)^(%d)*.(%d)", 2*p, poly, p-2, a);
}

/** root(p,z) */
void derivb702 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>2));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=root(%d,(%s)^2)", p,poly);
    sprintf(src, "y=root(p,(a*x+b)^2)");

    sprintf(answ[0], "y`=(2/(%d*.root(%d,(%s)^(%d))))*.(%d)", p, p, poly, p-2, a);
    sprintf(answ[1], "y`=(2/(root(%d,(%s)^(%d))))*.(%d)", p, poly, p-2, a);
    sprintf(answ[2], "y`=(1/(root(%d,(%s)^(%d))))*.(%d)", p, poly, p-2, a);
    sprintf(answ[3], "y`=(1/(root(%d,(%s)^(%d))))*.(%d)", p, poly, p-1, a);
}

/** y=p^z */
void derivb703 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>2));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=(%d)^((%s)^2))", p,poly);
    sprintf(src, "y=p^((a*x+b)^2)");

    sprintf(answ[0], "y`=(%d)^((%s)^2)*.ln(%d)*.2*(%s)*.(%d)", p, poly, p, poly, a);
    sprintf(answ[1], "y`=(%d)^((%s)^2)*.(1/ln(%d))*.2*(%s)*.(%d)", p, poly, p, poly, a);
    sprintf(answ[2], "y`=(%d)^((%s)^2)*.2*(%s)*.(%d)", p, poly, poly, a);
    sprintf(answ[3], "y`=(%d)^((%s)^2)*.((%s)^2)*.(%d)", p, poly, poly, a);
}

/** y=log(p,z) */
void derivb704 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b,p;
    do{
        a=rndr(r);
        b=rndr(r);
        p=rndr(r);
    }while(!(abs(a)>1 && p>2));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=log(%d,(%s)^2)", p, poly);
    sprintf(src, "y=log(p,(a*x+b)^2)");

    sprintf(answ[0], "y`=(2/(%s))*.(1/ln(%d))*.(%d)", poly, p, a);
    sprintf(answ[1], "y`=(1/((%s)^2))*.(1/ln(%d))*.(%d)", poly, p, a);
    sprintf(answ[2], "y`=(1/((%s)^2))*.ln(%d)*.(%d)", poly, p, a);
    sprintf(answ[3], "y`=(2/(%s))*.ln(%d)*.(%d)", poly, p, a);
}

/** y=sin(z) */
void derivb705 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=sin((%s)^2)", poly);
    sprintf(src, "y=sin((a*x+b)^2)");

    sprintf(answ[0], "y`=cos((%s)^2)*.2*(%s)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=cos((%s)^2)*.(-2)*(%s)*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=cos((%s)^2)*.(-2)*(%s)", poly, poly);
    sprintf(answ[3], "y`=cos((%s)^2)*.2*(%s)", poly, poly);
}

/** y=cos(z) */
void derivb706 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
   
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));


    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=cos((%s)^2)", poly);
    sprintf(src, "y=cos((a*x+b)^2)");

    sprintf(answ[0], "y`=-sin((%s)^2)*.2*(%s)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=-sin((%s)^2)*.(-2)*(%s)*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=-sin((%s)^2)*.(-2)*(%s)", poly, poly);
    sprintf(answ[3], "y`=-sin((%s)^2)*.2*(%s)", poly, poly);
}

/** y=tg(z) */
void derivb707 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=tg((%s)^2)", poly);
    sprintf(src, "y=tg((a*x+b)^2)");

    sprintf(answ[0], "y`=(1/(cos(%s)^2))*.2*(%s)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=(1/(cos(%s)^2))*.(%s)^2*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=(1/(cos(%s)^2))*.(1/((%s)^2))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=(1/(cos(%s)^2))*.(1/(2*(%s)))*.(%d)", poly, poly, a);
}

/** y=ctg(z) */
void derivb708 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=ctg((%s)^2)", poly);
    sprintf(src, "y=ctg((a*x+b)^2)");

    sprintf(answ[0], "y`=-1/(sin(%s)^2)*.2*(%s)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=-1/(sin(%s)^2)*.(%s)^2*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=-1/(sin(%s)^2)*.(1/((%s)^2))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=-1/(sin(%s)^2)*.(1/(2*(%s)))*.(%d)", poly, poly, a);
}

/** y=arcsin(z) */
void derivb709 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arcsin((%s)^2)", poly);
    sprintf(src, "y=arcsin((a*x+b)^2)");

    sprintf(answ[0], "y`=(1/sqrt(1-(%s)^4))*.2*(%s)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=(1/sqrt(1-(%s)^4))*.(%s)^2*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=(1/sqrt(1-(%s)^4))*.2*(%s)", poly, poly);
    sprintf(answ[3], "y`=(1/sqrt(1-(%s)^4))*.(%s)^2", poly, poly);
}

/** y=arccos(z) */
void derivb710 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{

    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arccos((%s)^2)", poly);
    sprintf(src, "y=arccos((a*x+b)^2)");

    sprintf(answ[0], "y`=-1/sqrt(1+(%s)^4)*.2*(%s)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=-1/sqrt(1+(%s)^4)*.(%s)^2*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=-1/sqrt(1+(%s)^4)*.2*(%s)", poly, poly);
    sprintf(answ[3], "y`=-1/sqrt(1+(%s)^4)*.(%s)^2", poly, poly);
}

/** y=arctg(z) */
void derivb711 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arctg((%s)^2)", poly);
    sprintf(src, "y=arctg((a*x+b)^2)");

    sprintf(answ[0], "y`=(1/(1+(%s)^4))*.2*(%s)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=(1/(1+(%s)^4))*.(%s)^2*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=(1/(1+(%s)^4))*.(1/((%s)^2))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=(1/(1+(%s)^4))*.(1/(2*(%s)))*.(%d)", poly, poly, a);
}

/** y=arcctg(z) */
void derivb712 (const range &r, char task[BUFSZ], char answ[5][BUFSZ], char src[BUFSZ])
{
    int a,b;
    do{
        a=rndr(r);
        b=rndr(r);
    }while(!(abs(a)>1));

    char buf[10][BUFSZ];
    char poly[BUFSZ];
    chprintf(poly, "%s", polynomial(buf[0], 2, a,"x", b,""));

    strcpy(task, "");
    catprintf(task, "String(\"Найти производную указанной функции:\")");
    catprintf(task, "\ny=arcctg((%s)^2)", poly);
    sprintf(src, "y=arcctg((a*x+b)^2)");

    sprintf(answ[0], "y`=-1/(1+(%s)^4)*.2*(%s)*.(%d)", poly, poly, a);
    sprintf(answ[1], "y`=-1/(1+(%s)^4)*.(%s)^2*.(%d)", poly, poly, a);
    sprintf(answ[2], "y`=-1/(1+(%s)^4)*.(1/((%s)^2))*.(%d)", poly, poly, a);
    sprintf(answ[3], "y`=-1/(1+(%s)^4)*.(1/(2*(%s)))*.(%d)", poly, poly, a);
}

