/*
FIrst time when fun1 is invoked memory from stack is used for function push/pull etc.
So the variable from fun1 is pushed to Stack and initialized as 10,
now when fun1 exits and fun2 is invoked the stack memory used by fun1 is deassigned and given to fun2,
hence  variable "y" in fun1 prints = 10
*/



#include <stdio.h>

void fun1()
{
	int x;
        printf("\n X in func is %d \n", x);
	x= 10;
        printf("\n X in func is %d \n", x);
	return ;
}

void fun2()
{
        int y;
        printf("\n Y in second func is %d \n", y);
        return ;
}

int main()
{

	fun1();
	fun2();

	return 0;
}
