#include<unistd.h>
#include<stdio.h>
#include<malloc.h>

int main()
{

	void* ptr;
        printf("\n ptr is %x \n", ptr);

        printf("\n ptr is %x page size", getpagesize());

	return 0;
}
