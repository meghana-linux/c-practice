#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{

  int *i1, *i2;

  printf("\n  page size= %d bytes\n", getpagesize());


  int sbrk_int =sbrk(0);
  printf("sbrk(0) before malloc(4): 0x%x\n", sbrk_int);

  i1 = (int *) malloc(4);

  printf("sbrk(0) after `i1 = (int *) malloc(4)': 0x%x\n", sbrk(0));

  i2 = (int *) malloc(4);

  printf("sbrk(0) after `i2 = (int *) malloc(4)': 0x%x\n", sbrk(0));

  printf("i1 = 0x%x, i2 = 0x%x\n", i1, i2);

  int sbrk_end =sbrk(0);  
  printf("sbrk(0) before malloc(4): 0x%x\n", sbrk_end);

  printf("\n difference = %d \n",   sbrk_int - sbrk_end );

}
