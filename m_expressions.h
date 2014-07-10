#ifndef expression_h
#define expression_h
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define SEP "$$$"
#define BUFSZ 4000

struct range
{
    range() {}
	range (const int from, const int to): f(from), t(to) {}
	int f,t;
};

char *divisor (char *res, int div, char *arg);
int split_str (char *str, char lines[20][BUFSZ]);
int split_text (const char *wholetext, char text[BUFSZ], char answer[10][BUFSZ]);
char *depar (char *buf);
void shuffle_answers (int n, char answ[10][BUFSZ], int& rightansw);
char *par (char *src, bool excl=false);
int rnd (int from, int to);
int rndr(const range& r);
int sgn (float a);
bool fsq (int a);
char *polynomial (char *buf, int n, ...);
void simplify_product (int rat, int irr, int&rrat,int&rirr);
void simplifyfrac (int &coeff, int &root, int &div);
char *fraction (char *res, int coeff, int root, int div);
char *draw_coeff (char *buf, int coeff, bool sign=false);
char *draw_sum1 (char *buf, int r1, int i1, int r2, int i2);
char *draw_e (char *buf, int coeff, int div);
char *product (char *buf, bool usedot, bool addsign, int n, ...);
void fracparts (char *bufc, char *bufd, int ratp, int irrp, char *expr);
char *print_fracparts (char *buf, int n, char c[][BUFSZ], char d[][BUFSZ]);
char *memb (char *buf, int c,int d,int pr,int pi,char *var, bool sign=true);
char *elfunc (char *func, char *deriv, int id, char *arg, int a, int j=2);
char *poly2ns (char *buf, int n, ...);
char *poly2s (char *buf, int n, ...);
char *poly2 (char *buf, bool sign, int n, ...);
char *rmvpar (char *buf, char *pars);
char *chprintf (char *buf, char *fmt, ...);
char *catprintf (char *buf, char *fmt, ...);

#endif
