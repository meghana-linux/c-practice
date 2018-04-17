/*

      Read sbrk(0), then allocate 10bytes of memory using 

      malloc assign some value to the 10bytes, read sbrk(0) 

      and free the ptr, again malloc(20) bytes and print the

      data in these new 20bytes

*/



#include<stdio.h>

#include<malloc.h>



int main()

{

    int *ptr, i=0;

    printf("\n before malloc( 5*4) sbrk = 0x%x \n",sbrk(0) );

    ptr = (int *)malloc( 5 *sizeof(int) );
	printf("\n ptr addr = 0x%x ",ptr);

    for(i=0; i<5; i++)

        ptr[i] = i+10;



    printf("\n after malloc( 5*4)  sbrk = 0x%x \n",sbrk(0) );

    for(i=0; i<5; i++)

        printf("\n allocated malloc data %d \n",ptr[i]);



    free(ptr);

    printf("\n after free sbrk =  0x%x \n",sbrk(0) );  



  

    ptr = (int *)malloc( 5 *sizeof(int) );
        printf("\n ptr addr = 0x%x ",ptr);

    printf("\n after second malloc( 10*4)  sbrk = 0x%x \n",sbrk(0) );

    for(i=0; i<10; i++)

        printf("\n SECOND allocated malloc data %d \n",ptr[i]);



    free(ptr);

    printf("\n after SECOND free sbrk =  0x%x \n",sbrk(0) ); 



    ptr=NULL;

    printf("\n after free sbrk =  0x%x \n",sbrk(0) ); 



	return 0;

}


