/* allocating 0bytes using malloc */
#include<stdio.h>
#include<malloc.h>

int main()
{

	void* ptr;
        printf("\n ptr is %x \n", ptr);

	ptr = (char*)malloc(0);

	printf("\n ptr is %x \n", ptr);

	return 0;
}
