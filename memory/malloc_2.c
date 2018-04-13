/* allocating bytes using malloc */
#include<stdio.h>
#include<malloc.h>

int main()
{

	int* ptr;
        printf("\n ptr is %x \n", ptr);

	ptr = (int*)malloc(50);

	printf("\n ptr is %x \n", ptr);

        ptr = (int*)malloc(250);
        printf("\n ptr is %x \n", ptr);


	free(ptr);
	return 0;
}
