#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[])
{
	int pipefd[2];
	if(pipe(pipefd)==-1)
		{
			printf("\n ppe cretionf ailed \n");
			exit(0);
		}

	char msg[]="hello testing";
	char rmsg[100];
//	if(write(pipefd[1], msg,sizeof(msg)) == -1)
        if(write(pipefd[1], argv[1],sizeof(argv[1])) == -1)
		{
			printf("\n write fialed\n");
		}

	if(read(pipefd[0],rmsg, strlen(argv[1]))<0)	//sizeof(argv[1])) <0)
		{
			printf("\n read failed\n");
		}

	printf("\n so %s (%d)(%d) \n", rmsg, (size_t)strlen(argv[1]),sizeof(argv[1]) );

	return 0;
}

	

