#include "m_expressions.h"

void integ201b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*e^x)*Diff(x)=...");

    sprintf(src, "Int(x*e^x)*Diff(x)");

    sprintf(answ[0], "...=x*e^x-e^x+C");
    sprintf(answ[1], "...=x*e^x+e^x+C");
    sprintf(answ[2], "...=e^x-x*e^x+C");
    sprintf(answ[3], "...=-x*e^x-e^x+C");
}

void integ202b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*ln(x))*Diff(x)=...");

    sprintf(src, "Int(x*ln(x))*Diff(x)");

    sprintf(answ[0], "...=(1/2)*x^2*ln(x)-(x^2)/4+C");
    sprintf(answ[1], "...=(1/2)*x^2*ln(x)+(x^2)/4+C");
    sprintf(answ[2], "...=-(1/2)*x^2*ln(x)-(x^2)/4+C");
    sprintf(answ[3], "...=-(1/2)*x^2*ln(x)+(x^2)/4+C");
}

void integ203b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*sin(x))*Diff(x)=...");

    sprintf(src, "Int(x*sin(x))*Diff(x)");

    sprintf(answ[0], "...=-x*cos(x)+sin(x)+C");
    sprintf(answ[1], "...=-x*cos(x)-sin(x)+C");
    sprintf(answ[2], "...=x*cos(x)+sin(x)+C");
    sprintf(answ[3], "...=x*cos(x)-sin(x)+C");
}

void integ204b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*cos(x))*Diff(x)=...");

    sprintf(src, "Int(x*cos(x))*Diff(x)");

    sprintf(answ[0], "...=x*sin(x)+cos(x)+C");
    sprintf(answ[1], "...=x*sin(x)-cos(x)+C");
    sprintf(answ[2], "...=-x*sin(x)-cos(x)+C");
    sprintf(answ[3], "...=-x*sin(x)+cos(x)+C");
}

void integ205b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*arcsin(x))*Diff(x)=...");

    sprintf(src, "Int(x*arcsin(x))*Diff(x)");

    sprintf(answ[0], "...=x*arcsin(x)+sqrt(1-x^2)+C");
    sprintf(answ[1], "...=x*arcsin(x)-sqrt(1-x^2)+C");
    sprintf(answ[2], "...=-x*arcsin(x)+sqrt(1-x^2)+C");
    sprintf(answ[3], "...=-x*arcsin(x)-sqrt(1-x^2)+C");
}

void integ206b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*arccos(x))*Diff(x)=...");

    sprintf(src, "Int(x*arccos(x))*Diff(x)");

    sprintf(answ[0], "...=x*arccos(x)-sqrt(1-x^2)+C");
    sprintf(answ[1], "...=x*arccos(x)+sqrt(1-x^2)+C");
    sprintf(answ[2], "...=-x*arccos(x)-sqrt(1-x^2)+C");
    sprintf(answ[3], "...=-x*arccos(x)+sqrt(1-x^2)+C");
}

void integ207b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*arctg(x))*Diff(x)=...");

    sprintf(src, "Int(x*arctg(x))*Diff(x)");

    sprintf(answ[0], "...=x*arctg(x)-(1/2)*ln(1+x^2)+C");
    sprintf(answ[1], "...=x*arctg(x)+(1/2)*ln(1+x^2)+C");
    sprintf(answ[2], "...=-x*arctg(x)-(1/2)*ln(1+x^2)+C");
    sprintf(answ[3], "...=-x*arctg(x)+(1/2)*ln(1+x^2)+C");
}

void integ208b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*arcctg(x))*Diff(x)=...");

    sprintf(src, "Int(x*arcctg(x))*Diff(x)");

    sprintf(answ[0], "...=x*arcctg(x)+(1/2)*ln(1+x^2)+C");
    sprintf(answ[1], "...=x*arcctg(x)-(1/2)*ln(1+x^2)+C");
    sprintf(answ[2], "...=-x*arcctg(x)+(1/2)*ln(1+x^2)+C");
    sprintf(answ[3], "...=-x*arcctg(x)-(1/2)*ln(1+x^2)+C");
}


/* * * * * * * * * * * *
 *                     *
 *   Простые задачи    *
 *                     *
 * * * * * * * * * * * */

void integ301b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x^2*e^x)*Diff(x)=...");

    sprintf(src, "Int(x^2*e^x)*Diff(x)");

    sprintf(answ[0], "...=x^2*e^x-2*x*e^x+2*e^x+C");
    sprintf(answ[1], "...=x^2*e^x-2*x*e^x-2*e^x+C");
    sprintf(answ[2], "...=x^2*e^x+2*x*e^x+2*e^x+C");
    sprintf(answ[3], "...=x^2*e^x+2*x*e^x-2*e^x+C");
}


void integ302b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*e^(2*x))*Diff(x)=...");

    sprintf(src, "Int(x*e^(2*x))*Diff(x)");

    sprintf(answ[0], "...=(1/2)*x*e^(2*x)-(1/4)*e^(2*x)+C");
    sprintf(answ[1], "...=(1/2)*x*e^(2*x)+(1/4)*e^(2*x)+C");
    sprintf(answ[2], "...=-(1/2)*x*e^(2*x)-(1/4)*e^(2*x)+C");
    sprintf(answ[3], "...=-(1/2)*x*e^(2*x)+(1/4)*e^(2*x)+C");
}

void integ303b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x^2*e^(2*x))*Diff(x)=...");

    sprintf(src, "Int(x^2*e^(2*x))*Diff(x)");

    sprintf(answ[0], "...=(1/2)*(x^2)*(e^(2*x))-(1/2)*x*e^(2*x)+(1/4)*e^(2*x)+C");
    sprintf(answ[1], "...=(1/2)*(x^2)*(e^(2*x))-(1/2)*x*e^(2*x)-(1/4)*e^(2*x)+C");
    sprintf(answ[2], "...=(1/2)*(x^2)*(e^(2*x))+(1/2)*x*e^(2*x)-(1/4)*e^(2*x)+C");
    sprintf(answ[3], "...=(1/2)*(x^2)*(e^(2*x))+(1/2)*x*e^(2*x)+(1/4)*e^(2*x)+C");
}

void integ304b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(ln(x))*Diff(x)=...");

    sprintf(src, "Int(ln(x))*Diff(x)");

    sprintf(answ[0], "...=x*ln(x)-x+C");
    sprintf(answ[1], "...=x*ln(x)+x+C");
    sprintf(answ[2], "...=-x*ln(x)-x+C");
    sprintf(answ[3], "...=-x*ln(x)+x+C");
}

void integ305b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x^2*ln(x))*Diff(x)=...");

    sprintf(src, "Int(x^2*ln(x))*Diff(x)");

    sprintf(answ[0], "...=(x^3/3)*ln(x)-(x^3/9)+C");
    sprintf(answ[1], "...=(x^3/3)*ln(x)+(x^3/9)+C");
    sprintf(answ[2], "...=-(x^3/3)*ln(x)-(x^3/9)+C");
    sprintf(answ[3], "...=-(x^3/3)*ln(x)+(x^3/9)+C");
}

void integ306b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*ln(x)^2)*Diff(x)=...");

    sprintf(src, "Int(x*ln(x)^2)*Diff(x)");

    sprintf(answ[0], "...=(1/2)*(x^2)*(ln(x)^2)-(1/2)*(x^2)*ln(x)+(1/4)*(x^2)+C");
    sprintf(answ[1], "...=(1/2)*(x^2)*(ln(x)^2)-(1/2)*(x^2)*ln(x)-(1/4)*(x^2)+C");
    sprintf(answ[2], "...=(1/2)*(x^2)*(ln(x)^2)+(1/2)*(x^2)*ln(x)+(1/4)*(x^2)+C");
    sprintf(answ[3], "...=(1/2)*(x^2)*(ln(x)^2)+(1/2)*(x^2)*ln(x)-(1/4)*(x^2)+C");
}

void integ307b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt((x^2)*(ln(x)^2))*Diff(x)=...");

    sprintf(src, "Int((x^2)*(ln(x)^2))*Diff(x)");

    sprintf(answ[0], "...=(1/3)*(x^3)*(ln(x)^2)-(2/9)*(x^3)*ln(x)+(2/27)*(x^3)+C");
    sprintf(answ[1], "...=(1/3)*(x^3)*(ln(x)^2)-(2/9)*(x^3)*ln(x)-(2/27)*(x^3)+C");
    sprintf(answ[2], "...=(1/3)*(x^3)*(ln(x)^2)+(2/9)*(x^3)*ln(x)+(2/27)*(x^3)+C");
    sprintf(answ[3], "...=(1/3)*(x^3)*(ln(x)^2)+(2/9)*(x^3)*ln(x)-(2/27)*(x^3)+C");
}

void integ308b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt((x^2)*(ln(x)^2))*Diff(x)=...");

    sprintf(src, "Int((x^2)*(ln(x)^2))*Diff(x)");

    sprintf(answ[0], "...=-ln(x)/x-1/x+C");
    sprintf(answ[1], "...=-ln(x)/x+1/x+C");
    sprintf(answ[2], "...=ln(x)/x+1/x+C");
    sprintf(answ[3], "...=ln(x)/x-1/x+C");
}

void integ309b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x^2*sin(x))*Diff(x)=...");

    sprintf(src, "Int(x^2*sin(x))*Diff(x)");

    sprintf(answ[0], "...=-x^2*cos(x)+2*x*sin(x)+2*cos(x)+C");
    sprintf(answ[1], "...=-x^2*cos(x)+2*x*sin(x)-2*cos(x)+C");
    sprintf(answ[2], "...=-x^2*cos(x)-2*x*sin(x)+2*cos(x)+C");
    sprintf(answ[3], "...=-x^2*cos(x)-2*x*sin(x)-2*cos(x)+C");
}

void integ310b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*sin(x)^2)*Diff(x)=...");

    sprintf(src, "Int(x*sin(x)^2)*Diff(x)");

    sprintf(answ[0], "...=(1/4)*(x^2)-(1/4)*x*sin(2*x)-(1/8)*cos(2*x)+C");
    sprintf(answ[1], "...=(1/4)*(x^2)-(1/4)*x*sin(2*x)+(1/8)*cos(2*x)+C");
    sprintf(answ[2], "...=(1/4)*(x^2)+(1/4)*x*sin(2*x)-(1/8)*cos(2*x)+C");
    sprintf(answ[3], "...=(1/4)*(x^2)+(1/4)*x*sin(2*x)+(1/8)*cos(2*x)+C");
}

void integ311b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x^2*cos(x)^2)*Diff(x)=...");

    sprintf(src, "Int(x^2*cos(x)^2)*Diff(x)");

    sprintf(answ[0], "...=(1/6)*(x^3)+(1/4)*(x^2)*sin(2*x)+(1/4)*x*cos(2*x)-(1/8)*sin(2*x)+C");
    sprintf(answ[1], "...=(1/6)*(x^3)+(1/4)*(x^2)*sin(2*x)+(1/4)*x*cos(2*x)+(1/8)*sin(2*x)+C");
    sprintf(answ[2], "...=(1/6)*(x^3)+(1/4)*(x^2)*sin(2*x)-(1/4)*x*cos(2*x)-(1/8)*sin(2*x)+C");
    sprintf(answ[3], "...=(1/6)*(x^3)+(1/4)*(x^2)*sin(2*x)-(1/4)*x*cos(2*x)+(1/8)*sin(2*x)+C");
}

void integ312b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x^2*cos(x))*Diff(x)=...");

    sprintf(src, "Int(x^2*cos(x))*Diff(x)");

    sprintf(answ[0], "...=(x^2)*sin(x)+2*x*cos(x)-2*sin(x)+C");
    sprintf(answ[1], "...=(x^2)*sin(x)+2*x*cos(x)+2*sin(x)+C");
    sprintf(answ[2], "...=(x^2)*sin(x)-2*x*cos(x)-2*sin(x)+C");
    sprintf(answ[3], "...=(x^2)*sin(x)-2*x*cos(x)+2*sin(x)+C");
}

void integ313b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(x*cos(x)^2)*Diff(x)=...");

    sprintf(src, "Int(x*cos(x)^2)*Diff(x)");

    sprintf(answ[0], "...=x^2/4+(1/4)*x*sin(2*x)+(1/8)*cos(2*x)+C");
    sprintf(answ[1], "...=x^2/4+(1/4)*x*sin(2*x)-(1/8)*cos(2*x)+C");
    sprintf(answ[2], "...=x^2/4-(1/4)*x*sin(2*x)+(1/8)*cos(2*x)+C");
    sprintf(answ[3], "...=x^2/4-(1/4)*x*sin(2*x)-(1/8)*cos(2*x)+C");
}

void integ314b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(e^sqrt(x))*Diff(x)=...");

    sprintf(src, "Int(e^sqrt(x))*Diff(x)");

    sprintf(answ[0], "...=2*sqrt(x)*e^sqrt(x)-2*e^sqrt(x)+C");
    sprintf(answ[1], "...=2*sqrt(x)*e^sqrt(x)+2*e^sqrt(x)+C");
    sprintf(answ[2], "...=2*sqrt(x)*e^sqrt(x)-e^sqrt(x)+C");
    sprintf(answ[3], "...=2*sqrt(x)*e^sqrt(x)+e^sqrt(x)+C");
}

void integ315b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(arccos(sqrt(x)))*Diff(x)=...");

    sprintf(src, "Int(arccos(sqrt(x)))*Diff(x)");

    sprintf(answ[0], "...=((pi*x)/2)-x*arcsin(sqrt(x))+(1/2)*arcsin(sqrt(x))-(sqrt(x)*.sqrt(1-x))/2+C");
    sprintf(answ[1], "...=((pi*x)/2)-x*arcsin(sqrt(x))+(1/2)*arcsin(sqrt(x))+(sqrt(x)*.sqrt(1-x))/2+C");
    sprintf(answ[2], "...=((pi*x)/2)-x*arcsin(sqrt(x))-(1/2)*arcsin(sqrt(x))-(sqrt(x)*.sqrt(1-x))/2+C");
    sprintf(answ[3], "...=((pi*x)/2)-x*arcsin(sqrt(x))-(1/2)*arcsin(sqrt(x))+(sqrt(x)*.sqrt(1-x))/2+C");
}

void integ316b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(sin(sqrt(x)))*Diff(x)=...");

    sprintf(src, "Int(sin(sqrt(x)))*Diff(x)");

    sprintf(answ[0], "...=-2*sqrt(x)*cos(sqrt(x))+2*sin(sqrt(x))+C");
    sprintf(answ[1], "...=-2*sqrt(x)*cos(sqrt(x))-2*sin(sqrt(x))+C");
    sprintf(answ[2], "...=2*sqrt(x)*cos(sqrt(x))+2*sin(sqrt(x))+C");
    sprintf(answ[3], "...=2*sqrt(x)*cos(sqrt(x))-2*sin(sqrt(x))+C");
}

void integ317b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(arctg(sqrt(x)))*Diff(x)=...");

    sprintf(src, "Int(arctg(sqrt(x)))*Diff(x)");

    sprintf(answ[0], "...=x*arctg(sqrt(x))-sqrt(x)+arctg(sqrt(x))+C");
    sprintf(answ[1], "...=x*arctg(sqrt(x))-sqrt(x)-arctg(sqrt(x))+C");
    sprintf(answ[2], "...=x*arctg(sqrt(x))+sqrt(x)+arctg(sqrt(x))+C");
    sprintf(answ[3], "...=x*arctg(sqrt(x))+sqrt(x)-arctg(sqrt(x))+C");
}

void integ318b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(cos(sqrt(x)))*Diff(x)=...");

    sprintf(src, "Int(cos(sqrt(x)))*Diff(x)");

    sprintf(answ[0], "...=2*sqrt(x)*sin(sqrt(x))+2*cos(sqrt(x))+C");
    sprintf(answ[1], "...=2*sqrt(x)*sin(sqrt(x))-2*cos(sqrt(x))+C");
    sprintf(answ[2], "...=-2*sqrt(x)*sin(sqrt(x))+2*cos(sqrt(x))+C");
    sprintf(answ[3], "...=-2*sqrt(x)*sin(sqrt(x))-2*cos(sqrt(x))+C");
}

void integ319b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(arcctg(sqrt(x)))*Diff(x)=...");

    sprintf(src, "Int(arcctg(sqrt(x)))*Diff(x)");

    sprintf(answ[0], "...=(pi*x)/2-x*arctg(sqrt(x))+sqrt(x)-arctg(sqrt(x))+C");
    sprintf(answ[1], "...=(pi*x)/2-x*arctg(sqrt(x))+sqrt(x)+arctg(sqrt(x))+C");
    sprintf(answ[2], "...=(pi*x)/2-x*arctg(sqrt(x))-sqrt(x)-arctg(sqrt(x))+C");
    sprintf(answ[3], "...=(pi*x)/2-x*arctg(sqrt(x))-sqrt(x)+arctg(sqrt(x))+C");
}

void integ320b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(arcsin(sqrt(x)))*Diff(x)=...");

    sprintf(src, "Int(arcsin(sqrt(x)))*Diff(x)");

    sprintf(answ[0], "...=x*arcsin(sqrt(x))-(1/2)*arctg(sqrt(x/(1-x)))+(1/2)*(sqrt(x)*.sqrt(1-x))/1+C");
    sprintf(answ[1], "...=x*arcsin(sqrt(x))-(1/2)*arctg(sqrt(x/(1-x)))-(1/2)*(sqrt(x)*.sqrt(1-x))/1+C");
    sprintf(answ[2], "...=x*arcsin(sqrt(x))+(1/2)*arctg(sqrt(x/(1-x)))+(1/2)*(sqrt(x)*.sqrt(1-x))/1+C");
    sprintf(answ[3], "...=x*arcsin(sqrt(x))+(1/2)*arctg(sqrt(x/(1-x)))-(1/2)*(sqrt(x)*.sqrt(1-x))/1+C");
}

void integ321b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(e^arcsin(x))*Diff(x)=...");

    sprintf(src, "Int(e^arcsin(x))*Diff(x)");

    sprintf(answ[0], "...=0.5*e^arcsin(x)*(sqrt(1-x^2)+x)+C");
    sprintf(answ[1], "...=0.5*e^arcsin(x)*(sqrt(1-x^2)-x)+C");
    sprintf(answ[2], "...=0.5*e^arcsin(x)*(-sqrt(1-x^2)+x)+C");
    sprintf(answ[3], "...=0.5*e^arcsin(x)*(-sqrt(1-x^2)-x)+C");
}

void integ322b (const range &r, char *task, char answ[][BUFSZ], char *src)
{
    strcpy(task, "");
    catprintf(task, "String(\"Найти интеграл:\")");
    catprintf(task, "\nInt(e^arccos(x))*Diff(x)=...");

    sprintf(src, "Int(e^arccos(x))*Diff(x)");

    sprintf(answ[0], "...=0.5*e^arccos(x)*(x-sqrt(1-x^2))+C");
    sprintf(answ[1], "...=0.5*e^arccos(x)*(x+sqrt(1-x^2))+C");
    sprintf(answ[2], "...=0.5*e^arccos(x)*(-x-sqrt(1-x^2))+C");
    sprintf(answ[3], "...=0.5*e^arccos(x)*(-x+sqrt(1-x^2))+C");
}

