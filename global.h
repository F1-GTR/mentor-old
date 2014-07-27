#ifndef GLOBAL_H
#define GLOBAL_H
#include <vcl.h>
#pragma hdrstop
#include <stdio.h>

//Переменные для редактирования.
#define NOQUEST 100
#define ADDQUEST 101
#define DELETEQUEST 102
#define SWAPQUEST_A 103
#define SWAPQUEST_B 104

//Переменные для КР
#define NullSyst        20
#define ScalMult        21
#define VectMult        22
#define Norm            23
#define LINES           24
#define ANGLE           25
#define PLANE           26
#define ELIPS           27
#define GIPER           28
#define PARAB           29
#define SMMUL           30
#define PRLINE          31
#define PLANELINE       32
#define NEOINTEGRAL2    33
#define RANG            34
#define LINDET          35
#define KRAMER          36
#define OBRMATR         37
#define PRIZMA          38
#define LINE_OF_PLANE   39
#define COMP_LINE       40
#define LINE_PRIZM      41
#define LINE_CMP        42
#define NEW_INT         44
#define EIGEN3x3        45
#define LIM01           46
#define DERIV           47
#define MFLABS          48
#define MINTEG          49
#define MLIMRND         50
#define MDERIVRND       51
#define MINTEGRND       52
#define ANGLINEPLANE    53
//int flagaddtask = 0;
enum elem_code{
      KURS=1,
      QUEST=2,
      ITEM=3,
      SUBITEM=4,
      MATLINOP=5,
      JOB=6,
      MATMULT=7,
      MATINVERS=8,
      MATEQ=9,
      DETER22=10,
      DETER33=11,
      DETER=12,
      LEGAUSS=13,
      LEKRAMER=14,
      INTEGRAL=15,
      MATEIGEN=16
//      MATOPR=17
};
void FWarning(char *s);
void FInform(char *s);
void FError(char *, int);
void FError(char* s,int kod,int par);
void FError(char* s,char* s1,int par);
int reads(FILE *f, char *s);
int readsall(FILE *f, char *s);
int rgen(int key,int n,int min,int max);
//tquest* qcreate(tquest* q);
#endif

