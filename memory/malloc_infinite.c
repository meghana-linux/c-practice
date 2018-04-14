#include<stdio.h>
#include<malloc.h>
#include<unistd.h>

int main()
{
	void *ptr;
	int count=0;

        ptr = (int*)malloc(1024*1024*1024);
       printf("\n addr 0x%x (count - %d) ", (unsigned int)ptr, count++);

	while(ptr)
	{
		ptr = (int*)malloc(1024*1024*1024);
		printf("\n addr 0x%x (count - %d) ", (unsigned int)ptr, count++);
	}


	int ret = sbrk(0);
	printf("\n sbrk 0x%x ",ret);
	return 0;
}
