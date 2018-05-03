#include <stdio.h>

int main()
{

	void * ptr;
	size_t x;
	x = sizeof(void*);
//	printf("\n size of void* %d \n",sizeof(void*));
        printf("\n size of void* %d \n", x);
	x = sizeof(int*);
        printf("\n size of int* %d \n",x);

        printf("\n size of int %d \n",sizeof(int));

	printf("\n size of void %d \n",sizeof(void));


	printf("\n testing void pointer arthimetic \n");
	printf("\n So %x   -  %x \n", ptr, ptr++);
	
	return 0;
}
