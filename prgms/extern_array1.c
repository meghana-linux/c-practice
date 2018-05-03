#include <stdio.h>
//#include "extern_hdr.h"

int arr[]={1,2,3,4};

int arr_size = sizeof(arr)/sizeof(arr[0]);

int func()
{
	printf(" %s \n",__func__);

}
