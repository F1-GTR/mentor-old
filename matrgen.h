#pragma once
const int range = 9;
const int maxsize = 5;
const int reslimit = 3000;
const int eqk = 2;
const int manytries = 1000000000;

typedef int elements[maxsize][maxsize];
typedef int eigenvalues[maxsize];
typedef struct
{
	elements e;
    eigenvalues eigenv;
    int eigenc;
} matrix;

bool generate (matrix& cur, int size, int wantedcount);

