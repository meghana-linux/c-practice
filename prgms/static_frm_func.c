#include <stdio.h>


int* func1()
{
	int z=10;
	return &z;
}

void func2(int x, int y)
{
	int a=99;
}

int main()
{
	int x=10;
	int *y=NULL;
	y = func1();
	printf("\n so %d %d\n",x,*y);
	func2(1,2);
        printf("\n so %d %d\n",x,*y);

	return 0;
}
