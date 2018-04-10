#include <sys/stat.h>

#include <fcntl.h>

#include <stdio.h>

#include <errno.h>

#include <string.h>

#include <sys/types.h>

#include <unistd.h>

#include <stdlib.h>



#define FILENAME "/tmp/partly.sparse"

#define FILE_SIZE (1<<30)

#define START_STRING "start of file\n"

#define START_LEN strlen(START_STRING)

#define END_STRING "\nend of file\n"

#define END_LEN strlen(END_STRING)



#define debug(M, ...) fprintf(stderr, "%i: DEBUG %10.10s:%3.0d: " M "\n", getpid(), __FILE__, __LINE__, ##__VA_ARGS__); fflush(stderr);

#define log_err(M, ...) fprintf(stderr, "%i: ERROR errno:%i %10.10s:%3.0d: " M "\n", getpid(), errno, __FILE__, __LINE__, ##__VA_ARGS__); fflush(stderr);



#define quit_if(COND, ...)  do {         \
	if(COND) { \

                log_err(__VA_ARGS__); \

                perror(NULL); \

                exit(errno); \

        } \

} while(0);



int make_partly_sparse(const char *filename, off_t size) {

        int r, fd;

        fd = open(filename, O_RDWR|O_CREAT, 0755);

        quit_if(fd < 1, "unable to create %s", filename);

        r = write(fd, START_STRING, START_LEN);

        quit_if(r < START_LEN, "unable to write %s", filename);

        r = lseek(fd, FILE_SIZE - END_LEN, SEEK_SET);

        quit_if(r < 0, "unable to seek %s", filename);

        r = write(fd, END_STRING, END_LEN);

        quit_if(r < END_LEN, "unable to write %s", filename);

        r = close(fd);

        quit_if(r < 0, "unable to close %s", filename);

        return 0;

}



int test_seek(const char *filename) {

        int r, fd;

        fd = open(filename, O_RDWR|O_CREAT, 0755);

        quit_if(fd < 1, "unable to open %s", filename);

        debug("seeking hole at %li", START_LEN);

        r = lseek(fd, 0, SEEK_HOLE);

        quit_if(r < 0, "unable to seek %s", filename);

        quit_if(r != START_LEN, "SEEK_HOLE unsupported %i", r);

        r = lseek(fd, 0, SEEK_DATA);

        quit_if(r < 0, "unable to seek %s", filename);

        quit_if(r != (FILE_SIZE - END_LEN), "SEEK_DATA unsupported %i", r);

        r = close(fd);

        quit_if(r < 0, "unable to close %s", filename);

        return 0;

}



int main(int argc, char *argv[]) {

        debug("making sparse file: %s", FILENAME);

        make_partly_sparse(FILENAME, FILE_SIZE);

        test_seek(FILENAME);

        return 0;

}
