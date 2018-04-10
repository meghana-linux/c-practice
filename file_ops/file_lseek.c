#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int fd;
	int offset;

	if (fd = open("/tmp/blah.txt", O_RDWR) < 0)
	 {
		printf("\n error opening the file");
		exit(-1);
	  }

	
	offset = lseek(fd, 0, SEEK_HOLE);
        printf("n SEEK_HOLE offset %d \n", offset);

        offset = lseek(fd, 0, SEEK_DATA);
        printf("n SEEK_DATA offset %d \n", offset);

	return 0;

}



