/* two different process trying to write to the same file */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
/*	if( (fd = open("/tmp/a.txt", O_CREAT))< 0)
	{
		printf("\n error in c reating a new file ");
		exit(-1);
	}

	close(fd);
*/
        if( (fd = open("/tmp/a.txt", O_RDWR|O_APPEND))< 0)
        {
                printf("\n error in opening a new file ");
                exit(-1);
        }
	
	while(1)
	{
		write(fd, "WRITING DATA INTO FILE FROM P2#",30);
		sleep(0);
	}

	close(fd);
	return 0;
}

