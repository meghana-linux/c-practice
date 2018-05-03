#include <stdio.h>
#include <stdlib.h>

char arr[100];

int main(int argc, char *argv[])
{
	char *str;

	int i=0;
	for(i=0;i<argc+1;i++)
		printf("\n So %s \n", argv[i]);



	str = getenv("TMPDIR");
 	printf("\n so %s \n",str);	
	return 0;
}
