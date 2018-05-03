#include <stdio.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	pid = fork();
	if (pid==0)
	{
		printf("\n inchild process \n");
		exit(0);
	}
	else
	{
		printf("\n parent process \n");

		return 0;
	}
}

