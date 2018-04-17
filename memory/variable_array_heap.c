
/*
  this is program is to understand whetehr variable sized arrays are stored
  in heap or stack?
*/

#include<stdio.h>
#include<unistd.h>

#define N 100

int main()

{
//	int arr[N];	
	int arr[100];
	int i=0;
	for(i=0;i<N;i++)
		arr[i]= i;

	return 0;
}
