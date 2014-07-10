#include <stdio.h>
#include <string.h>

int input (const char *prompt)
{
	int res;
	printf("%s", prompt);
    scanf("%d", &res);
    return res;
}

char *inputstr (const char *prompt, char *buffer)
{
	printf("%s", prompt);
    fflush(stdin);
    gets(buffer);
    return buffer;
}

main()
{
	char title[1000], filename[1000];
    int i, qid, start, count;
    FILE *fmtr;

    printf("make_mtr version 1.0.\n\n");

    inputstr("filename? ", filename);
	qid = input("what questID? ");
    count = input("how many? ");
    start = input("start from? ");
    inputstr("title? ", title);

    if (!strstr(filename, ".mtr")) strcat(filename, ".mtr");
	fmtr = fopen(filename, "wt");
    fprintf(fmtr, "head 3\n%s\n", title);
    for(i=1; i<=count; ++i)
    {
    	fprintf(fmtr, "head 4\n#%d\n", i);
        fprintf(fmtr, "head 2\nsomeid\n");
        fprintf(fmtr, "1 %d %d\n%d -5 5\n%d -5 5\n", i, qid, i+start-1, i+start-1);
    }
    fprintf(fmtr, "head 6\n%s*\n", title);
    for(i=1; i<=count; ++i)
    {
        fprintf(fmtr, "head 2\nsomeid\n");
        fprintf(fmtr, "1 %d %d\n%d -5 5\n%d -5 5\n", i, qid, i+start-1, i+start-1);
    }
    fclose(fmtr);

    printf("done.\n");
}
