#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	int offset;

	if (fd = open("/tmp/blah.txt", O_CREAT) < 0)
	 {
		printf("\n error opening the file");
		exit(-1);
	  }

	close(fd);

	fd = open("/tmp/blah.txt", O_RDWR);		
       
	write(fd, "creating a new file", 25);

	offset = lseek(fd, 0 , SEEK_CUR);
	printf("n current offset %d \n", offset);
	
	offset = lseek(fd, 100, SEEK_END);
        printf("n new offset %d \n", offset);

	write(fd, "adding text after a hole", 30);

        offset = lseek(fd, 300, SEEK_END);
        printf("n new offset %d \n", offset);

        write(fd, "adding text after first hole", 40);

	return 0;

}



