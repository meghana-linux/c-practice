#if 0
#include<stdio.h>

typedef char* PCHAR;
#define pchar char*

int main()
{

	PCHAR a,b,c;
	pchar x,y,z;

	printf("\n size of a %lu \n", sizeof(a));
        printf("\n size of b %lu\n", sizeof(b));
        printf("\n size of c %lu\n", sizeof(c));
        printf("\n size of x %lu\n", sizeof(x));
        printf("\n size of y %lu\n", sizeof(y));
        printf("\n size of z %lu\n", sizeof(z));

	return 0;
}

#endif

#include<stdio.h>

typedef char* PCHAR;
#define PCHAR char*
//typedef char* PCHAR;

int main()
{

        PCHAR a,b,c;

        printf("\n size of a %lu \n", sizeof(a));
        printf("\n size of b %lu\n", sizeof(b));
        printf("\n size of c %lu\n", sizeof(c));

        return 0;
}

