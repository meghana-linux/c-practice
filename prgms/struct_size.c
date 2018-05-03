#include <stdio.h>

struct abc
{
	int var :1;
	int var1 :7;
	char ch;
	int var3 : 7;
};

int main()
{

        printf("\n size of empty struct %d \n",sizeof(struct abc));

}

