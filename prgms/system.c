#include <stdio.h>
#include <stdlib.h>	//to use system()
#include <string.h> //to use strcpy()

int main()
{
	char *command = malloc(100);
	
	//executing ls command
	strcpy(command, "ls");
	printf("ls command...\n");
	system(command);
	
	//executing date command 
	strcpy(command, "date");
	printf("date command...\n");
	system(command);


        //executing date command 
        strcpy(command, "cat sleep.c");
        printf("cat command...\n");
        system(command);

	
	return 0;
}

