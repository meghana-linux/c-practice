#include <stdio.h>
//#include "extern_hdr.h"

//extern int arr_size;
#define sss 5
extern int arr[sss];
//extern int arr_size;

int main()
{

	printf("\n hello\n");
	printf("\n no of element in arr : %d \n", sizeof(arr)/sizeof(arr[0]) );

	return 0;
}
