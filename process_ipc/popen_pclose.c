#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char command[100];
	strcpy(command, "echo abc  > a.txt");
	FILE *fp = popen(command,"w");
	pclose(fp);


		return 0;
}
