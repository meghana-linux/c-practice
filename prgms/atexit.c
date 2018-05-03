#include <stdio.h>
#include <stdlib.h>


void exit_cleanup(void)
{
	printf("\n in main cleanup \n");
}

int main(int argc, char *argv[], char *envp[])
{

	printf("\n main start \n");
	
	if(atexit(exit_cleanup))
		{
			printf("\n cleanup register error \n");
			exit(0);
			abort();
		}

	int i=0;
	for(i=0; argv[i]!=NULL;i++)
		printf("\n argv - %s \n",argv[i]);

        for(i=0; envp[i]!=NULL;i++)
                printf("\n envp - %s \n",envp[i]);
	

	return 0;
}



