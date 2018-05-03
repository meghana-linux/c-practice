#include <string.h>
#include <stdio.h>
struct student{
	char name[10];
	int roll_no;
};

int main()
{
	struct student abc;
	abc.roll_no = 123;
	strcpy(abc.name,"asm");

	printf("\n %d  %s\n",abc.roll_no, abc.name);

	return 0;
}
