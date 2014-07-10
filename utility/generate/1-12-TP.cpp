#include <stdio.h>

void main()
{
	FILE *f = fopen("c:\\1-12-TP.mtr","wt");
    int index = 143;
    for(int i=7; i<=12; ++i)
    {
	    fprintf(f,"head 3\n%d\n", i);
        for(int j=1; j<=12; ++j)
        {
        	if (i==7 && j==12) continue;
        	++index;
        	fprintf(f,"head 4\n");
            fprintf(f,"%d\n", j);
            fprintf(f,"head 2\n");
            fprintf(f,"someid\n");
            fprintf(f,"%d %d 47\n", i-7+1, j);
            fprintf(f,"%d -5 5\n", index);
            fprintf(f,"%d -5 5\n", index);
        }
    }
    index = 143;
    fprintf(f,"head 6\nall tests\n");
    for(int i=7; i<=12; ++i)
    {
        for(int j=1; j<=12; ++j)
        {
        	if (i==7 && j==12) continue;
        	++index;
            fprintf(f,"head 2\n");
            fprintf(f,"someid\n");
            fprintf(f,"%d %d 47\n", i-7+1, j);
            fprintf(f,"%d -5 5\n", index);
            fprintf(f,"%d -5 5\n", index);
        }
    }
    fclose(f);
    
}