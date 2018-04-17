/*
	allocate 10bytes of memory get the ptr address, sbrk value,
	then free the above memory and then get the value of sbrk, and 
	try to access the above free'ed ptr location => segmentation fault
	Reason for segmentation fault => after doing free(ptr) and ptr=NULL TOGETHER, sbrk value doesnt change
		but we get SEG fault bcoz after free'ing the page-table entry 
		for the process is updated saying that the page is not-VALID, so 
		since process is trying to access INVALID page, we get SEG error.

	NOTE : if ptr=NULL is not done after free(ptr), we dont get segmentation
		fault, since that page is still a part of process page table entry, but the 
		result value is unexpected.
*/


#include<stdio.h>
#include<malloc.h>
#include<unistd.h>

int main()
{
	int val=0;
	char *ptr = 0;
	printf("\n before malloc sbrk = 0x%x \n", sbrk(0) );

	ptr = (char*)malloc(10);
	ptr[0]= 'z';
	printf("\n ptr = 0x%x \n", ptr);
        printf("\n after malloc- ptr[0]=%c ",ptr[0]);
        printf("\n after malloc sbrk = 0x%x \n", sbrk(0) );

	printf("***************************************************\n");

	free(ptr);
        printf("\n after free ptr = 0x%x \n", ptr);
	printf("\n after free- ptr[0]=%c \n ",ptr[0]);


        printf("***************************************************\n");

	ptr = NULL;
        printf("\n after free-NULL ptr[0]=%c ",ptr[0]);

        printf("\n after free-NULL ptr = 0x%x \n", ptr);
        printf("\n after free sbrk = 0x%x \n", sbrk(0) );

	
	return 0;	
}
