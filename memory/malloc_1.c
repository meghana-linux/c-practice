/* 
 allocating 0bytes using malloc 
 reading sbrk beofre and after malloc

*/

#include<unistd.h>
#include<stdio.h>
#include<malloc.h>

int main()
{

	void* ptr;
        printf("\n ptr is %x(b4 allocation) \n", ptr);

	printf("\n before allocation 0x%x  \n", sbrk(0) );

	ptr = (char*)malloc(0);

	printf("\n ptr is %x(after allocation) \n", ptr);

        printf("\n after allocation 0x%x  \n", sbrk(0) );

	return 0;
}




